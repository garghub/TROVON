bool F_1 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 . V_3 == 1 )
return true ;
if ( ( V_1 -> V_2 . V_3 == 2 ) &&
( ! F_2 ( V_1 ) -> V_4 ) )
return true ;
return false ;
}
