static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = true ;
}
static unsigned long F_2 ( struct V_1 * V_5 )
{
struct V_6 * V_6 = V_5 -> V_6 ;
struct V_1 * V_2 ;
T_1 * V_7 ;
unsigned long V_8 ;
T_2 V_9 ;
V_8 = * F_3 ( V_5 , 1 ) ;
if ( F_4 ( V_5 ) )
V_8 &= ~ ( ( V_10 ) 0 ) ;
if ( V_8 >= F_5 ( & V_6 -> V_11 ) )
return V_12 ;
V_9 = * F_3 ( V_5 , 2 ) ;
V_2 = F_6 ( V_6 , V_8 ) ;
V_7 = F_7 ( V_2 ) ;
if ( ! F_8 ( V_7 ) )
return V_12 ;
F_9 ( V_2 ) ;
if ( F_4 ( V_2 ) && ( V_9 & 1 ) ) {
V_9 &= ~ ( ( T_2 ) 1 ) ;
F_10 ( V_2 ) ;
}
* F_11 ( V_2 ) = V_9 ;
V_2 -> V_3 . V_4 = false ;
F_12 () ;
F_13 ( V_7 ) ;
return V_13 ;
}
bool F_14 ( struct V_1 * V_2 )
{
unsigned long V_14 = * F_3 ( V_2 , 0 ) & ~ ( ( V_10 ) 0 ) ;
unsigned long V_15 ;
switch ( V_14 ) {
case V_16 :
F_1 ( V_2 ) ;
V_15 = V_13 ;
break;
case V_17 :
V_15 = F_2 ( V_2 ) ;
break;
case V_18 :
case V_19 :
V_15 = V_20 ;
break;
default:
return false ;
}
* F_3 ( V_2 , 0 ) = V_15 ;
return true ;
}
