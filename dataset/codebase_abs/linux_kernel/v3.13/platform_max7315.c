static void T_1 * F_1 ( void * V_1 )
{
static struct V_2 V_3 [ V_4 ] ;
static int V_5 ;
struct V_2 * V_6 = & V_3 [ V_5 ] ;
struct V_7 * V_8 = V_1 ;
int V_9 , V_10 ;
char V_11 [ V_12 + 1 ] ;
char V_13 [ V_12 + 1 ] ;
if ( V_5 == V_4 ) {
F_2 ( L_1 ,
V_4 ) ;
return NULL ;
}
strcpy ( V_8 -> type , L_2 ) ;
if ( V_5 ++ ) {
sprintf ( V_11 , L_3 , V_5 ) ;
sprintf ( V_13 , L_4 , V_5 ) ;
} else {
strcpy ( V_11 , L_5 ) ;
strcpy ( V_13 , L_6 ) ;
}
V_9 = F_3 ( V_11 ) ;
V_10 = F_3 ( V_13 ) ;
if ( V_9 == - 1 )
return NULL ;
V_6 -> V_9 = V_9 ;
if ( V_10 != - 1 ) {
V_8 -> V_14 = V_10 + V_15 ;
V_6 -> V_16 = V_9 + V_15 ;
} else {
V_8 -> V_14 = - 1 ;
V_6 -> V_16 = - 1 ;
}
return V_6 ;
}
