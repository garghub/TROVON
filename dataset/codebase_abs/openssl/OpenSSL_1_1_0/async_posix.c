int F_1 ( void )
{
T_1 V_1 ;
return F_2 ( & V_1 ) == 0 ;
}
void F_3 ( void )
{
}
int F_4 ( T_2 * V_2 )
{
V_2 -> V_3 = 0 ;
if ( F_2 ( & V_2 -> V_2 ) == 0 ) {
V_2 -> V_2 . V_4 . V_5 = F_5 ( V_6 ) ;
if ( V_2 -> V_2 . V_4 . V_5 != NULL ) {
V_2 -> V_2 . V_4 . V_7 = V_6 ;
V_2 -> V_2 . V_8 = NULL ;
F_6 ( & V_2 -> V_2 , V_9 , 0 ) ;
return 1 ;
}
} else {
V_2 -> V_2 . V_4 . V_5 = NULL ;
}
return 0 ;
}
void F_7 ( T_2 * V_2 )
{
F_8 ( V_2 -> V_2 . V_4 . V_5 ) ;
V_2 -> V_2 . V_4 . V_5 = NULL ;
}
