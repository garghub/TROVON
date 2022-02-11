static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
}
void F_4 ( struct V_3 * V_6 )
{
F_5 ( & V_6 -> V_2 , F_1 ) ;
F_6 ( & V_6 -> V_2 ) ;
}
unsigned int
F_7 ( const unsigned char * V_7 , int V_8 , struct V_9 * V_10 )
{
if ( ( V_8 < 2 ) || ( V_8 > 3 ) )
return V_11 ;
if ( ( V_7 [ 0 ] != '^' ) && ( V_7 [ 0 ] != '\252' ) )
return V_11 ;
#ifdef F_8
if ( V_8 == 3 && V_7 [ 1 ] == '-' ) {
V_12 . V_5 = V_7 [ 2 ] ;
F_4 ( & V_12 ) ;
return V_13 ;
}
#endif
if ( V_8 != 2 )
return V_11 ;
switch ( tolower ( V_7 [ 1 ] ) ) {
case 'c' :
return F_9 ( V_10 ) | V_14 ;
case 'd' :
return F_10 ( V_10 ) | V_14 ;
case 'z' :
return F_11 ( V_10 ) | V_14 ;
}
return V_11 ;
}
