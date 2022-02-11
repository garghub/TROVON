int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 () ;
if ( F_3 () &&
! F_4 ( F_5 () , V_4 ) ) {
F_6 () ;
return V_4 ;
}
F_6 () ;
V_3 = F_7 ( V_5 , V_4 ,
V_6 ) ;
if ( V_3 )
return 0 ;
return V_4 ;
}
static inline bool F_8 ( struct V_7 * V_8 )
{
if ( ( V_8 -> V_9 & ( V_10 | V_11 | V_12 ) ) != V_12 )
return false ;
if ( F_9 ( V_8 ) != V_4 )
return false ;
return true ;
}
int F_10 ( struct V_7 * V_8 , int V_13 , int V_14 )
{
if ( V_14 != - 1 )
return V_14 ;
if ( F_8 ( V_8 ) &&
( V_13 & ( V_15 | V_16 ) ) ) {
return 0 ;
}
if ( V_13 == V_17 ) {
V_14 = F_11 ( V_8 -> V_18 ) ;
if ( V_14 > 0 )
return V_14 ;
}
return F_9 ( V_8 ) ;
}
