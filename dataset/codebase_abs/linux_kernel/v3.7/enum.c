const struct V_1 *
F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
while ( V_2 -> V_4 ) {
if ( V_2 -> V_3 == V_3 )
return V_2 ;
V_2 ++ ;
}
return NULL ;
}
void
F_2 ( const struct V_1 * V_2 , T_1 V_3 )
{
V_2 = F_1 ( V_2 , V_3 ) ;
if ( V_2 )
F_3 ( L_1 , V_2 -> V_4 ) ;
else
F_3 ( L_2 , V_3 ) ;
}
void
F_4 ( const struct V_5 * V_6 , T_1 V_3 )
{
while ( V_6 -> V_4 ) {
if ( V_3 & V_6 -> V_7 ) {
F_3 ( L_3 , V_6 -> V_4 ) ;
V_3 &= ~ V_6 -> V_7 ;
}
V_6 ++ ;
}
if ( V_3 )
F_3 ( L_4 , V_3 ) ;
}
