static void T_1 F_1 ( unsigned long V_1 , struct V_2 * V_3 )
{
struct V_2 * V_4 = & V_5 ;
struct V_2 V_6 ;
V_4 = F_2 ( V_4 ) ;
V_6 = * V_4 ;
* V_4 = * V_3 ;
if ( V_6 . V_7 && ! V_3 -> V_7 ) {
V_4 -> V_7 = V_6 . V_7 ;
V_4 -> V_8 = V_6 . V_8 ;
V_4 -> V_9 = V_6 . V_9 ;
V_4 -> V_10 = V_6 . V_10 ;
V_4 -> V_11 = V_6 . V_11 ;
V_4 -> V_12 = V_6 . V_12 ;
if ( V_6 . V_13 != NULL ) {
V_4 -> V_13 = V_6 . V_13 ;
V_4 -> V_9 = V_6 . V_9 ;
}
}
* F_2 ( & V_14 ) = & V_5 ;
if ( * F_2 ( & V_15 ) == NULL )
* F_2 ( & V_15 ) = V_4 -> V_16 ;
#if F_3 ( V_17 ) || F_3 ( V_18 )
if ( V_4 -> V_19 ) {
V_4 -> V_19 ( V_1 , V_4 ) ;
}
#endif
}
struct V_2 * T_1 F_4 ( unsigned long V_1 , unsigned int V_20 )
{
struct V_2 * V_3 = V_21 ;
int V_22 ;
V_3 = F_2 ( V_3 ) ;
for ( V_22 = 0 ; V_22 < F_5 ( V_21 ) ; V_22 ++ , V_3 ++ ) {
if ( ( V_20 & V_3 -> V_23 ) == V_3 -> V_24 ) {
F_1 ( V_1 , V_3 ) ;
return V_3 ;
}
}
F_6 () ;
return NULL ;
}
