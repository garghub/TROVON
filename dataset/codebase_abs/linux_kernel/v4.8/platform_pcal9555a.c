static void T_1 * F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
char * type = V_3 -> type ;
struct V_4 * V_5 ;
char V_6 [ V_7 + 1 ] ;
char V_8 [ V_7 + 1 ] ;
int V_9 , V_10 ;
snprintf ( V_6 , sizeof( V_6 ) , L_1 , type ) ;
snprintf ( V_8 , sizeof( V_8 ) , L_2 , type ) ;
V_9 = F_2 ( V_6 ) ;
V_10 = F_2 ( V_8 ) ;
if ( V_9 == - 1 )
return NULL ;
if ( V_11 >= V_12 ) {
F_3 ( L_3 , V_13 ,
V_12 ) ;
return NULL ;
}
V_5 = & V_14 [ V_11 ++ ] ;
V_5 -> V_9 = V_9 ;
if ( V_10 >= 0 ) {
V_3 -> V_15 = V_10 + V_16 ;
V_5 -> V_17 = V_9 + V_16 ;
} else {
V_3 -> V_15 = - 1 ;
V_5 -> V_17 = - 1 ;
}
strcpy ( type , L_4 ) ;
return V_5 ;
}
