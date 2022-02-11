int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
struct V_5 * V_6 ;
const struct V_7 * V_7 = F_2 () , * V_8 ;
F_3 () ;
V_8 = F_4 ( V_2 ) ;
if ( ! F_5 ( V_8 -> V_9 , V_7 -> V_10 ) &&
! F_5 ( V_8 -> V_9 , V_7 -> V_9 ) && ! F_6 ( V_11 ) ) {
F_7 () ;
return - V_12 ;
}
F_7 () ;
V_4 = F_8 ( V_2 , V_3 ) ;
if ( V_4 )
return V_4 ;
V_6 = F_9 ( V_2 , V_13 , V_14 ) ;
if ( V_6 ) {
V_6 -> V_3 = V_3 ;
F_10 ( V_6 ) ;
}
return V_4 ;
}
static int F_11 ( struct V_1 * V_15 )
{
int V_16 ;
V_16 = F_12 ( V_15 ) ;
if ( V_16 )
goto V_17;
V_16 = F_13 ( V_18 , V_19 ) ;
if ( V_15 -> V_5 )
V_16 = V_15 -> V_5 -> V_3 ;
V_17:
return V_16 ;
}
int F_14 ( unsigned short V_20 , unsigned short V_21 )
{
unsigned short V_22 = F_15 ( V_20 ) ;
unsigned short V_23 = F_15 ( V_21 ) ;
if ( V_22 == V_18 )
V_22 = V_24 ;
if ( V_23 == V_18 )
V_23 = V_24 ;
if ( V_22 == V_23 )
return F_16 ( V_20 , V_21 ) ;
if ( V_22 > V_23 )
return V_21 ;
else
return V_20 ;
}
