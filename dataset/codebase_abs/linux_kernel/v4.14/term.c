void F_1 ( struct V_1 * V_2 )
{
char * V_3 = getenv ( L_1 ) ;
if ( V_3 != NULL ) {
V_2 -> V_4 = atoi ( V_3 ) ;
V_3 = getenv ( L_2 ) ;
if ( V_3 != NULL ) {
V_2 -> V_5 = atoi ( V_3 ) ;
if ( V_2 -> V_4 && V_2 -> V_5 )
return;
}
}
#ifdef F_2
if ( F_3 ( 1 , F_2 , V_2 ) == 0 &&
V_2 -> V_4 && V_2 -> V_5 )
return;
#endif
V_2 -> V_4 = 25 ;
V_2 -> V_5 = 80 ;
}
void F_4 ( struct V_6 * V_7 )
{
struct V_6 V_8 ;
F_5 ( 0 , V_7 ) ;
V_8 = * V_7 ;
V_8 . V_9 &= ~ ( V_10 | V_11 ) ;
V_8 . V_12 [ V_13 ] = 0 ;
V_8 . V_12 [ V_14 ] = 0 ;
F_6 ( 0 , V_15 , & V_8 ) ;
}
