bool F_1 ( struct V_1 * V_1 )
{
if ( 1 == V_1 -> V_2 . V_3 )
return true ;
if ( ( 2 == V_1 -> V_2 . V_3 ) && ( ! F_2 ( V_1 ) -> V_4 ) )
return true ;
return false ;
}
