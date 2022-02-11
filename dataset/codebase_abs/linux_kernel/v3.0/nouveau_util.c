void
F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
while ( V_2 -> V_4 ) {
if ( V_3 & V_2 -> V_5 ) {
F_2 ( L_1 , V_2 -> V_4 ) ;
V_3 &= ~ V_2 -> V_5 ;
}
V_2 ++ ;
}
if ( V_3 )
F_2 ( L_2 , V_3 ) ;
}
const struct V_6 *
F_3 ( const struct V_6 * V_7 , T_1 V_3 )
{
while ( V_7 -> V_4 ) {
if ( V_7 -> V_3 == V_3 )
return V_7 ;
V_7 ++ ;
}
return NULL ;
}
void
F_4 ( const struct V_6 * V_7 , T_1 V_3 )
{
V_7 = F_3 ( V_7 , V_3 ) ;
if ( V_7 ) {
F_2 ( L_3 , V_7 -> V_4 ) ;
return;
}
F_2 ( L_4 , V_3 ) ;
}
int
F_5 ( void )
{
return F_6 ( & V_8 ) ;
}
