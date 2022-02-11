static unsigned int F_1 ( unsigned int V_1 )
{
return F_2 ( V_2 . V_3 ) / 1000 ;
}
static int F_3 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
unsigned int V_7 = V_8 [ V_6 ] . V_9 ;
unsigned long V_10 ;
F_4 () ;
V_10 = F_5 ( V_2 . V_11 ) ;
V_10 |= V_12 ;
F_6 ( V_10 , V_2 . V_11 ) ;
switch ( V_7 ) {
case V_13 :
F_7 ( V_2 . V_3 , V_2 . V_14 ) ;
break;
case V_15 :
F_7 ( V_2 . V_3 , V_2 . V_16 ) ;
break;
}
F_8 () ;
V_10 = F_5 ( V_2 . V_11 ) ;
V_10 &= ~ V_12 ;
F_6 ( V_10 , V_2 . V_11 ) ;
F_9 () ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 )
{
return F_11 ( V_5 , V_8 , 5000 ) ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 ;
V_2 . V_24 = & V_18 -> V_24 ;
V_22 = F_13 ( V_18 , V_25 , 0 ) ;
V_2 . V_11 = F_14 ( & V_18 -> V_24 , V_22 ) ;
if ( F_15 ( V_2 . V_11 ) )
return F_16 ( V_2 . V_11 ) ;
V_20 = F_17 ( 0 ) ;
if ( ! V_20 ) {
F_18 ( & V_18 -> V_24 , L_1 ) ;
return - V_26 ;
}
V_2 . V_14 = F_19 ( V_20 , L_2 ) ;
if ( F_15 ( V_2 . V_14 ) ) {
F_18 ( V_2 . V_24 , L_3 ) ;
return F_16 ( V_2 . V_14 ) ;
}
V_23 = F_20 ( V_2 . V_14 ) ;
if ( V_23 ) {
F_18 ( V_2 . V_24 , L_4 ) ;
return V_23 ;
}
V_8 [ 0 ] . V_27 = F_2 ( V_2 . V_14 ) / 1000 ;
V_2 . V_16 = F_19 ( V_20 , L_5 ) ;
if ( F_15 ( V_2 . V_16 ) ) {
F_18 ( V_2 . V_24 , L_6 ) ;
V_23 = F_16 ( V_2 . V_16 ) ;
goto V_28;
}
V_23 = F_20 ( V_2 . V_16 ) ;
if ( V_23 ) {
F_18 ( V_2 . V_24 , L_7 ) ;
goto V_28;
}
V_8 [ 1 ] . V_27 = F_2 ( V_2 . V_16 ) / 1000 ;
V_2 . V_3 = F_19 ( V_20 , L_8 ) ;
if ( F_15 ( V_2 . V_3 ) ) {
F_18 ( V_2 . V_24 , L_9 ) ;
V_23 = F_16 ( V_2 . V_3 ) ;
goto V_29;
}
V_23 = F_20 ( V_2 . V_3 ) ;
if ( V_23 ) {
F_18 ( V_2 . V_24 , L_10 ) ;
goto V_29;
}
F_21 ( V_20 ) ;
V_20 = NULL ;
V_23 = F_22 ( & V_30 ) ;
if ( ! V_23 )
return 0 ;
F_18 ( V_2 . V_24 , L_11 ) ;
F_23 ( V_2 . V_3 ) ;
V_29:
F_23 ( V_2 . V_16 ) ;
V_28:
F_23 ( V_2 . V_14 ) ;
F_21 ( V_20 ) ;
return V_23 ;
}
static int F_24 ( struct V_17 * V_18 )
{
F_25 ( & V_30 ) ;
F_23 ( V_2 . V_3 ) ;
F_23 ( V_2 . V_16 ) ;
F_23 ( V_2 . V_14 ) ;
return 0 ;
}
