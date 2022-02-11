int F_1 ( int V_1 , int V_2 , char * string )
{
char * V_3 ;
if ( F_2 ( V_1 < 0 || V_1 >= V_4 ) )
return - V_5 ;
if ( F_2 ( V_2 < 0 || V_2 >= V_6 ) )
return - V_5 ;
F_3 ( & V_7 ) ;
if ( string == NULL ) {
if ( ( V_3 = V_8 [ V_2 ] [ V_1 ] ) != NULL ) {
F_4 ( V_3 ) ;
V_3 = NULL ;
}
} else {
V_3 = F_5 ( string , V_9 ) ;
if ( V_3 == NULL ) {
F_6 ( & V_7 ) ;
return - V_10 ;
}
}
V_8 [ V_2 ] [ V_1 ] = V_3 ;
F_6 ( & V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_11 * V_12 , char * V_13 , int V_1 )
{
int V_14 , V_15 = - 1 ;
char * V_16 ;
F_8 ( V_12 , L_1 , V_13 ) ;
F_3 ( & V_7 ) ;
for ( V_14 = 0 ; V_14 < V_6 ; V_14 ++ ) {
V_16 = V_8 [ V_14 ] [ V_1 ] ;
if ( V_16 ) {
if ( V_15 < 0 ) {
F_8 ( V_12 , L_2 ) ;
V_15 ++ ;
}
F_8 ( V_12 , L_3 , V_14 , V_16 ) ;
}
}
F_6 ( & V_7 ) ;
if ( V_15 < 0 )
F_8 ( V_12 , L_4 ) ;
return V_15 ;
}
static void F_9 ( struct V_17 * V_18 ,
struct V_11 * V_19 )
{
F_8 ( V_19 , L_5 ) ;
F_8 ( V_19 , L_6 ,
F_10 () -> V_20 ,
F_10 () -> V_21 ,
F_10 () -> V_22 ,
F_10 () -> V_23 ,
F_10 () -> V_24 ) ;
F_8 ( V_19 , L_7 ) ;
F_8 ( V_19 , L_8 ) ;
F_8 ( V_19 , L_9 ) ;
F_8 ( V_19 , L_10 ) ;
F_11 ( V_19 ) ;
F_7 ( V_19 , L_11 , V_25 ) ;
F_7 ( V_19 , L_12 , V_26 ) ;
F_7 ( V_19 , L_13 , V_27 ) ;
F_7 ( V_19 , L_14 , V_28 ) ;
F_7 ( V_19 , L_15 , V_29 ) ;
}
int T_1 F_12 ( void )
{
struct V_17 * V_18 ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_18 = F_13 ( V_30 , L_16 ,
V_31 ) ;
if ( ! V_18 )
return - V_10 ;
V_18 -> V_32 . V_33 . V_34 = F_9 ;
return F_14 ( V_18 ) ;
}
