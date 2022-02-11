int F_1 ( void )
{
char V_1 [ V_2 + 1 ] ;
F_2 ( V_1 , L_1 ) ;
if ( F_3 ( V_3 ) ) {
F_4 ( L_2 ) ;
return 1 ;
}
if ( F_5 ( L_3 , L_4 , NULL , V_4 | V_5 , NULL ) ) {
F_4 ( L_5 ) ;
return 1 ;
}
if ( F_5 ( L_3 , V_6 , L_6 , 0 , NULL ) ) {
F_4 ( L_7 ) ;
return 1 ;
}
F_6 () ;
if ( F_7 ( V_1 , 0777 ) && V_7 != V_8 ) {
F_4 ( L_8 ) ;
return 1 ;
}
return 0 ;
}
static int F_8 ( const char * V_9 , const struct V_10 * V_11 ,
int V_12 , struct V_13 * V_14 )
{
if ( ( V_12 & V_15 ) && F_9 ( V_9 ) )
F_4 ( L_9 , V_9 ) ;
return 0 ;
}
static int F_10 ( char * V_16 )
{
char V_17 [ V_2 + 1 ] ;
T_1 V_18 = F_11 () ;
int V_19 , V_20 = 0 ;
snprintf ( V_17 , sizeof( V_17 ) ,
L_10 , V_16 ) ;
V_19 = F_12 ( V_17 , V_21 ) ;
if ( V_19 < 0 ) {
F_4 ( L_11 , V_17 ) ;
return 1 ;
}
if ( F_13 ( V_19 , L_12 , V_18 ) < 0 ) {
F_4 ( L_13 ) ;
V_20 = 1 ;
}
F_14 ( V_19 ) ;
return V_20 ;
}
int F_15 ( char * V_22 )
{
char V_16 [ V_2 + 1 ] ;
F_2 ( V_16 , V_22 ) ;
return F_10 ( V_16 ) ;
}
void F_6 ( void )
{
char V_1 [ V_2 + 1 ] ;
F_2 ( V_1 , L_1 ) ;
F_10 ( V_6 ) ;
F_16 ( V_1 , F_8 , V_23 , V_24 | V_25 ) ;
}
int F_17 ( char * V_22 )
{
char V_16 [ V_2 + 1 ] ;
int V_19 ;
F_2 ( V_16 , V_22 ) ;
if ( F_7 ( V_16 , 0777 ) && V_7 != V_8 ) {
F_4 ( L_14 ) ;
return 0 ;
}
V_19 = F_12 ( V_16 , V_26 ) ;
if ( V_19 < 0 ) {
F_4 ( L_15 ) ;
return 0 ;
}
return V_19 ;
}
