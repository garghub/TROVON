static int F_1 ( unsigned int V_1 )
{
int V_2 ;
if ( V_1 > 3 )
return - V_3 ;
switch ( V_1 ) {
case 2 :
V_2 = F_2 ( V_4 ,
V_5 ,
V_6 , true ) ;
if ( V_2 )
return V_2 ;
break;
case 3 :
V_2 = F_2 ( V_4 ,
V_7 ,
V_8 , true ) ;
if ( V_2 )
return V_2 ;
break;
}
F_3 ( 200 ) ;
F_4 ( F_5 ( V_9 ) ,
V_10 + V_11 + ( V_1 - 1 ) * 4 ) ;
F_4 ( V_12 ,
V_10 + V_13 + ( V_1 - 1 ) * 4 ) ;
F_6 () ;
F_7 () ;
return 0 ;
}
static int F_8 ( unsigned int V_1 , struct V_14 * V_15 )
{
unsigned long V_16 ;
int V_2 ;
V_2 = F_1 ( V_1 ) ;
if ( V_2 )
return V_2 ;
F_3 ( 10 ) ;
F_9 ( & V_17 ) ;
F_10 ( V_1 ) ;
V_16 = V_18 + ( 1 * V_19 ) ;
while ( F_11 ( V_18 , V_16 ) ) {
if ( V_20 == - 1 )
break;
}
F_4 ( 0 , V_10 + V_11 + ( V_1 - 1 ) * 4 ) ;
F_4 ( 0 , V_10 + V_13 + ( V_1 - 1 ) * 4 ) ;
F_12 ( & V_17 ) ;
return 0 ;
}
static void T_1 F_13 ( unsigned int V_21 )
{
struct V_22 * V_23 ;
V_23 = F_14 ( NULL , NULL , L_1 ) ;
if ( ! V_23 ) {
F_15 ( L_2 , V_24 ) ;
return;
}
V_10 = F_16 ( V_23 , 0 ) ;
if ( ! V_10 ) {
F_15 ( L_3 , V_24 ) ;
return;
}
V_23 = F_14 ( NULL , NULL , L_4 ) ;
if ( ! V_23 ) {
F_15 ( L_5 , V_24 ) ;
return;
}
V_4 = F_16 ( V_23 , 0 ) ;
if ( ! V_4 ) {
F_15 ( L_6 , V_24 ) ;
return;
}
if ( F_17 () == V_25 ) {
V_23 = F_14 ( NULL , NULL , L_7 ) ;
if ( ! V_23 ) {
F_15 ( L_8 , V_24 ) ;
return;
}
V_26 = F_16 ( V_23 , 0 ) ;
if ( ! V_26 ) {
F_15 ( L_9 , V_24 ) ;
return;
}
V_27 = F_18 ( V_26 ) ;
F_19 ( L_10 , V_24 , V_27 ) ;
F_20 ( V_26 ) ;
}
}
