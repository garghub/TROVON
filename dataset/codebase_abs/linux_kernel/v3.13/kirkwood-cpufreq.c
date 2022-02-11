static unsigned int F_1 ( unsigned int V_1 )
{
if ( F_2 ( V_2 . V_3 ) )
return V_4 [ 1 ] . V_5 ;
return V_4 [ 0 ] . V_5 ;
}
static int F_3 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned int V_9 = V_4 [ V_8 ] . V_10 ;
unsigned long V_11 ;
F_4 () ;
V_11 = F_5 ( V_2 . V_12 ) ;
V_11 |= V_13 ;
F_6 ( V_11 , V_2 . V_12 ) ;
switch ( V_9 ) {
case V_14 :
F_7 ( V_2 . V_3 ) ;
break;
case V_15 :
F_8 ( V_2 . V_3 ) ;
break;
}
F_9 () ;
V_11 = F_5 ( V_2 . V_12 ) ;
V_11 &= ~ V_13 ;
F_6 ( V_11 , V_2 . V_12 ) ;
F_10 () ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 )
{
return F_12 ( V_7 , V_4 , 5000 ) ;
}
static int F_13 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_22 ;
V_2 . V_23 = & V_17 -> V_23 ;
V_21 = F_14 ( V_17 , V_24 , 0 ) ;
V_2 . V_12 = F_15 ( & V_17 -> V_23 , V_21 ) ;
if ( F_16 ( V_2 . V_12 ) )
return F_17 ( V_2 . V_12 ) ;
V_19 = F_18 ( 0 ) ;
if ( ! V_19 ) {
F_19 ( & V_17 -> V_23 , L_1 ) ;
return - V_25 ;
}
V_2 . V_26 = F_20 ( V_19 , L_2 ) ;
if ( F_16 ( V_2 . V_26 ) ) {
F_19 ( V_2 . V_23 , L_3 ) ;
return F_17 ( V_2 . V_26 ) ;
}
F_21 ( V_2 . V_26 ) ;
V_4 [ 0 ] . V_5 = F_22 ( V_2 . V_26 ) / 1000 ;
V_2 . V_27 = F_20 ( V_19 , L_4 ) ;
if ( F_16 ( V_2 . V_27 ) ) {
F_19 ( V_2 . V_23 , L_5 ) ;
V_22 = F_17 ( V_2 . V_27 ) ;
goto V_28;
}
F_21 ( V_2 . V_27 ) ;
V_4 [ 1 ] . V_5 = F_22 ( V_2 . V_27 ) / 1000 ;
V_2 . V_3 = F_20 ( V_19 , L_6 ) ;
if ( F_16 ( V_2 . V_3 ) ) {
F_19 ( V_2 . V_23 , L_7 ) ;
V_22 = F_17 ( V_2 . V_3 ) ;
goto V_29;
}
F_23 ( V_2 . V_3 ) ;
F_24 ( V_19 ) ;
V_19 = NULL ;
V_22 = F_25 ( & V_30 ) ;
if ( ! V_22 )
return 0 ;
F_19 ( V_2 . V_23 , L_8 ) ;
F_26 ( V_2 . V_3 ) ;
V_29:
F_26 ( V_2 . V_27 ) ;
V_28:
F_26 ( V_2 . V_26 ) ;
F_24 ( V_19 ) ;
return V_22 ;
}
static int F_27 ( struct V_16 * V_17 )
{
F_28 ( & V_30 ) ;
F_26 ( V_2 . V_3 ) ;
F_26 ( V_2 . V_27 ) ;
F_26 ( V_2 . V_26 ) ;
return 0 ;
}
