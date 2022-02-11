void F_1 ( T_1 V_1 )
{
struct V_2 * V_2 ;
V_2 = F_2 () ;
if ( V_2 ) {
F_3 ( V_2 -> V_3 , V_1 ) ;
F_4 ( V_2 ) ;
}
}
void F_5 ( T_1 V_1 )
{
struct V_2 * V_2 ;
V_2 = F_2 () ;
if ( V_2 ) {
F_6 ( V_2 -> V_3 , V_1 ) ;
F_4 ( V_2 ) ;
}
}
int F_7 ( T_1 V_1 )
{
return F_8 ( F_9 () , V_1 ) ;
}
static void F_10 ( T_2 V_4 , T_1 * V_1 )
{
* V_1 = V_4 . V_1 [ 0 ] ;
}
T_1 F_11 ( void )
{
T_1 V_1 ;
F_10 ( F_9 () , & V_1 ) ;
return V_1 ;
}
