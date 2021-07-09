#include <stdio.h>
#include <math.h>
// usamos esse side de referência: http://arcaz.dainf.ct.utfpr.edu.br/rea/files/original/b638596b01aae0a52c36e987c09ac053.pdf//

float anoBissexto(int ano){
    if(ano % 100 == 0 && ano % 400 != 0)
        return 0;
    else if(ano % 100 == 0 && ano % 400 != 0)
        return 0;
    else if(ano % 100 == 0 && ano % 400 == 0)
        return 1;
    else if (ano % 4 == 0 || ano % 400 == 0)
        return 1;
}
float diaMes (int mes, int ano){
    int teste;  
    if(mes>12)
        return 0;  
    if(mes == 2  && anoBissexto(ano) == 0){
        teste = 28;
    }
    if(mes == 2 && anoBissexto(ano) == 1)
        teste = 29;
    if(mes <=7 && mes != 2){
        teste =  mes % 2;
        if(teste == 1){
            teste = 31;
        }
        else{
            teste = 30;
        }
    }
    else if(mes !=2){
        teste = mes % 2;
        if(teste == 0){
            teste = 31;
        }
        else{
            teste = 30;
        }
    }
    return teste;

}
int diaSemana (int ano, int i){
    int ds, k, j, dia = 1;

    if (i<=2){
        i =  i +12;
        ano =  ano -1;
    }
    else
        i =  i-2;
    k =  ano %100;
    j = ano /100;

    ds = ((700+((26 * i - 2) /10) + dia + k + (k /4) + ((j /4)+ 5 * j)) %7);

    return ds;
}
char *months[]={
    "---JANEIRO---",
    "---FEVEREIRO---",
    "---MARÇO---",
    "---ABRIL---",
    "---MAIO---",
    "---JUNHO---",
    "---JULHO---",
    "---AGOSTO---",
    "---SETEMBRO---",
    "---OUTUBRO---",
    "---NOVEMBRO---",
    "---DEZEMBRO---"
};
int main(void){
    int ano, mes = 0, i, cont, dia, aux = 0, k=0, j, x;
    printf("Insira o ano desejado: ");
    scanf("%d", &ano);
    dia=1;
    for(i = 1; i <=12; i++){
        mes ++;
        dia = 1;
        printf("\n\n\t\t%s\n\n", months[mes - 1]);
        printf("  D    S    T    Q    Q    S    S \n");
        k = 0;
        if(mes <=2){
          printf(" --   --  ");
          k =  k+2;
        }
        for(j = 0; j<diaSemana(ano, i); j++){
                printf(" --  ");
                k++;
              }
            for(cont = 1; cont <=diaMes(mes, ano); cont++){
                  printf("|%02d| ", dia);
                  dia++;
                  k = k;
                  k++;
                  if(k %7== 0){
                  printf("\n"); 
                  }
                  else if(dia > diaMes(mes, ano))
                      break;
            }
        printf("\n");
    }
    return 0;
}
/*##################################################################
####################################################################
##################    Code by: Lucas Orlikoski    ##################
#                              &                                   #
#                         Kelwin Oliveira                          #
#                              &                                   #
########################  Saulo Centenaro  #########################  
## # # # # # # # # # # # # # # #  # # # # # # # # # # # # # # # # ##
#                 Alunos de Sistemas de Informação.                #
#                Matéria: Prolegômenos ao Computar.                #
#                  Professores Rita & Pelisson.                    #
##################################################################*/
