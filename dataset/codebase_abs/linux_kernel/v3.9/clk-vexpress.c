static void T_1 F_1 ( void T_2 * V_1 )
{
int V_2 ;
if ( F_2 ( ! V_1 ) )
return;
for ( V_2 = 0 ; V_2 < F_3 ( V_3 ) ; V_2 ++ ) {
char V_4 [ 12 ] ;
const char * V_5 [] = {
L_1 ,
L_2
} ;
snprintf ( V_4 , F_3 ( V_4 ) , L_3 , V_2 ) ;
V_3 [ V_2 ] = F_4 ( NULL , V_4 ,
V_5 , 2 , 0 , V_1 + V_6 ,
F_5 ( V_2 ) , 1 ,
0 , & V_7 ) ;
if ( F_2 ( F_6 ( V_3 [ V_2 ] ) ) )
break;
}
}
void T_1 F_7 ( void T_2 * V_8 )
{
struct V_9 * V_9 ;
int V_2 ;
V_9 = F_8 ( NULL , L_4 , NULL ,
V_10 , 0 ) ;
F_2 ( F_9 ( V_9 , L_5 , NULL ) ) ;
V_9 = F_8 ( NULL , L_6 , NULL ,
V_10 , 24000000 ) ;
for ( V_2 = 0 ; V_2 < F_3 ( V_11 ) ; V_2 ++ )
F_2 ( F_9 ( V_9 , NULL ,
V_11 [ V_2 ] ) ) ;
V_9 = F_8 ( NULL , L_1 , NULL ,
V_10 , 32768 ) ;
F_2 ( F_9 ( V_9 , NULL , L_7 ) ) ;
V_9 = F_8 ( NULL , L_2 , NULL ,
V_10 , 1000000 ) ;
F_1 ( V_8 ) ;
for ( V_2 = 0 ; V_2 < F_3 ( V_3 ) ; V_2 ++ )
F_2 ( F_10 ( V_3 [ V_2 ] , V_9 ) ) ;
F_2 ( F_9 ( V_3 [ 0 ] ,
L_8 , L_9 ) ) ;
F_2 ( F_9 ( V_3 [ 1 ] ,
L_10 , L_9 ) ) ;
}
struct V_9 * F_11 ( struct V_12 * V_13 , void * V_14 )
{
if ( F_2 ( V_13 -> V_15 != 1 || V_13 -> args [ 0 ] >
F_3 ( V_3 ) ) )
return NULL ;
return V_3 [ V_13 -> args [ 0 ] ] ;
}
void T_1 F_12 ( void )
{
struct V_16 * V_17 ;
struct V_9 * V_9 ;
struct V_9 * V_18 , * V_19 ;
F_13 ( NULL ) ;
V_17 = F_14 ( NULL , NULL , L_11 ) ;
F_1 ( F_15 ( V_17 , 0 ) ) ;
F_16 ( V_17 , F_11 , NULL ) ;
V_18 = F_17 ( V_17 , L_12 ) ;
V_19 = F_17 ( V_17 , L_13 ) ;
if ( ! F_2 ( F_6 ( V_18 ) || F_6 ( V_19 ) ) ) {
int V_2 = 0 ;
if ( F_18 ( V_18 ) > F_18 ( V_19 ) )
V_9 = V_18 ;
else
V_9 = V_19 ;
for ( V_2 = 0 ; V_2 < F_3 ( V_3 ) ; V_2 ++ )
F_2 ( F_10 ( V_3 [ V_2 ] ,
V_9 ) ) ;
}
F_2 ( F_9 ( V_3 [ 0 ] ,
L_8 , L_9 ) ) ;
F_2 ( F_9 ( V_3 [ 1 ] ,
L_10 , L_9 ) ) ;
}
