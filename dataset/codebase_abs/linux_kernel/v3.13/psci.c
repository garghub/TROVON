static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = true ;
}
static unsigned long F_2 ( struct V_1 * V_5 )
{
struct V_6 * V_6 = V_5 -> V_6 ;
struct V_1 * V_2 = NULL , * V_7 ;
T_1 * V_8 ;
unsigned long V_9 ;
unsigned long V_10 ;
T_2 V_11 ;
int V_12 ;
V_9 = * F_3 ( V_5 , 1 ) ;
if ( F_4 ( V_5 ) )
V_9 &= ~ ( ( V_13 ) 0 ) ;
F_5 (i, tmp, kvm) {
V_10 = F_6 ( V_7 ) ;
if ( ( V_10 & V_14 ) == ( V_9 & V_14 ) ) {
V_2 = V_7 ;
break;
}
}
if ( ! V_2 )
return V_15 ;
V_11 = * F_3 ( V_5 , 2 ) ;
V_8 = F_7 ( V_2 ) ;
if ( ! F_8 ( V_8 ) )
return V_15 ;
F_9 ( V_2 ) ;
if ( F_4 ( V_2 ) && ( V_11 & 1 ) ) {
V_11 &= ~ ( ( T_2 ) 1 ) ;
F_10 ( V_2 ) ;
}
if ( F_11 ( V_5 ) )
F_12 ( V_2 ) ;
* F_13 ( V_2 ) = V_11 ;
V_2 -> V_3 . V_4 = false ;
F_14 () ;
F_15 ( V_8 ) ;
return V_16 ;
}
bool F_16 ( struct V_1 * V_2 )
{
unsigned long V_17 = * F_3 ( V_2 , 0 ) & ~ ( ( V_13 ) 0 ) ;
unsigned long V_18 ;
switch ( V_17 ) {
case V_19 :
F_1 ( V_2 ) ;
V_18 = V_16 ;
break;
case V_20 :
V_18 = F_2 ( V_2 ) ;
break;
case V_21 :
case V_22 :
V_18 = V_23 ;
break;
default:
return false ;
}
* F_3 ( V_2 , 0 ) = V_18 ;
return true ;
}
