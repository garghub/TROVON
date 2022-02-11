static void * F_1 ( void * V_1 )
{
static struct V_2 V_3 ;
struct V_4 * V_5 = V_1 ;
int V_6 , V_7 ;
char V_8 [ V_9 + 1 ] ;
char V_10 [ V_9 + 1 ] ;
strcpy ( V_5 -> type , V_11 ) ;
strcpy ( V_8 , V_12 ) ;
strcpy ( V_10 , V_13 ) ;
V_6 = F_2 ( V_8 ) ;
V_7 = F_2 ( V_10 ) ;
if ( V_6 == - 1 )
return NULL ;
V_3 . V_6 = V_6 ;
if ( V_7 != - 1 ) {
V_5 -> V_14 = V_7 + V_15 ;
V_3 . V_16 = V_6 + V_15 ;
} else {
V_5 -> V_14 = - 1 ;
V_3 . V_16 = - 1 ;
}
return & V_3 ;
}
