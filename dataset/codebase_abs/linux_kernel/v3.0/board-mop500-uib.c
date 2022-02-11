static int T_1 F_1 ( char * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ ) {
struct V_4 * V_4 = & V_3 [ V_2 ] ;
if ( ! strcmp ( V_1 , V_4 -> V_5 ) ) {
V_6 = V_4 ;
break;
}
}
if ( V_2 == F_2 ( V_3 ) )
F_3 ( L_1 , V_1 ) ;
return 1 ;
}
void F_4 ( int V_7 , struct V_8 * V_9 ,
unsigned V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_2 ;
V_12 = F_5 ( V_7 ) ;
if ( ! V_12 ) {
F_3 ( L_2 , V_7 ) ;
return;
}
for ( V_2 = 0 ; V_2 < V_10 ; V_2 ++ ) {
V_14 = F_6 ( V_12 , & V_9 [ V_2 ] ) ;
if ( ! V_14 )
F_3 ( L_3 ,
V_9 [ V_2 ] . type , V_7 ) ;
}
F_7 ( V_12 ) ;
}
static void T_1 F_8 ( struct V_4 * V_4 , const char * V_15 )
{
F_9 ( L_4 , V_4 -> V_16 , V_15 ) ;
V_4 -> V_17 () ;
}
static int T_1 F_10 ( void )
{
struct V_4 * V_4 = V_6 ;
struct V_11 * V_18 ;
int V_19 ;
if ( ! F_11 () )
return - V_20 ;
if ( V_4 ) {
F_8 ( V_4 , L_5 ) ;
return 0 ;
}
V_18 = F_5 ( 0 ) ;
if ( ! V_18 ) {
F_8 ( & V_3 [ V_21 ] ,
L_6 ) ;
return - V_20 ;
}
V_19 = F_12 ( V_18 , 0x44 , 0 , V_22 , 0 ,
V_23 , NULL ) ;
F_7 ( V_18 ) ;
if ( V_19 == 0 )
V_4 = & V_3 [ V_24 ] ;
else
V_4 = & V_3 [ V_21 ] ;
F_8 ( V_4 , L_7 ) ;
return 0 ;
}
