void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
T_1 * V_8 , * V_9 = NULL , * V_10 = NULL ;
void * V_11 , * V_12 ;
const char * V_13 ;
char V_14 [ V_15 ] ;
char V_16 [ V_17 ] ;
V_7 = V_2 -> V_18 -> V_19 ;
V_13 = V_4 -> V_20 ? V_4 -> V_20 : L_1 ;
F_2 ( V_15 < 56 || V_17 != 128 ) ;
for ( V_8 = V_7 -> V_21 ; V_8 < V_7 -> V_21 + V_7 -> V_22 . V_23 ; V_8 ++ ) {
V_5 = sscanf ( V_7 -> V_24 + V_8 -> V_25 ,
L_2 ,
V_14 , V_16 ) ;
if ( V_5 != 2 )
continue;
if ( strcmp ( V_14 , V_13 ) )
continue;
if ( ! strcmp ( L_3 , V_16 ) )
V_9 = V_8 ;
if ( ! strcmp ( L_4 , V_16 ) )
V_10 = V_8 ;
}
if ( V_9 ) {
V_11 = ( void * ) V_9 -> V_26 ;
F_3 ( V_11 , V_11 + V_9 -> V_27 ) ;
}
if ( V_10 ) {
V_12 = ( void * ) V_10 -> V_26 ;
F_4 ( V_12 , V_12 + V_10 -> V_27 ) ;
}
}
