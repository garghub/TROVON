static T_1
F_1 ( char * V_1 , T_2 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_1 , V_4 | V_5 | V_6 | V_7 , 0666 ) ;
if ( V_3 == - 1 ) {
F_3 ( V_1 , V_8 , TRUE ) ;
return FALSE ;
}
if ( F_4 ( V_3 , V_2 , ( unsigned int ) strlen ( V_2 ) ) < 0 ) {
F_5 ( V_1 , V_8 ) ;
F_6 ( V_3 ) ;
return FALSE ;
}
if ( F_6 ( V_3 ) < 0 ) {
F_5 ( V_1 , V_8 ) ;
return FALSE ;
}
F_7 ( V_2 ) ;
return TRUE ;
}
void
F_8 ( T_3 * T_4 V_9 , T_5 T_6 V_9 )
{
F_9 ( F_10 ( F_11 ( V_10 ) ) ) ;
return;
}
static char *
F_12 ( T_7 V_11 )
{
T_3 * V_12 ;
T_2 * V_13 ;
T_3 * V_14 ;
char * V_15 ;
V_12 = F_13 ( L_1 ,
F_14 ( V_10 ) ,
V_16 ) ;
V_13 = F_15 ( L_2 ,
V_11 , F_16 ( V_11 , L_3 , L_4 ) ) ;
V_14 = F_17 ( V_13 ) ;
F_7 ( V_13 ) ;
F_18 ( V_12 , V_14 ) ;
F_19 ( V_14 ) ;
V_15 = F_20 ( V_12 ) ;
if ( V_15 == NULL ) {
return NULL ;
}
F_21 ( V_12 ) ;
return V_15 ;
}
void
F_8 ( T_3 * T_4 V_9 , T_5 T_6 V_9 )
{
char * V_15 ;
T_7 V_11 ;
T_2 * V_2 ;
V_11 = F_22 () ;
if ( V_11 == 0 ) {
F_23 ( V_17 , V_18 , L_5 ) ;
return;
}
V_2 = F_24 () ;
for (; ; ) {
V_15 = F_12 ( V_11 ) ;
if ( V_15 == NULL ) {
break;
}
if ( F_1 ( V_15 , V_2 ) ) {
F_7 ( V_15 ) ;
break;
}
F_7 ( V_15 ) ;
}
}
