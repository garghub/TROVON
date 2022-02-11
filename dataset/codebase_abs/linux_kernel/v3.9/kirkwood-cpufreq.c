static unsigned int F_1 ( unsigned int V_1 )
{
if ( F_2 ( V_2 . V_3 ) )
return V_4 [ 1 ] . V_5 ;
return V_4 [ 0 ] . V_5 ;
}
static void F_3 ( unsigned int V_6 )
{
struct V_7 V_8 ;
unsigned int V_9 = V_4 [ V_6 ] . V_6 ;
unsigned long V_10 ;
V_8 . V_11 = F_1 ( 0 ) ;
V_8 . V_12 = V_4 [ V_6 ] . V_5 ;
V_8 . V_1 = 0 ;
F_4 ( & V_8 , V_13 ) ;
F_5 ( V_2 . V_14 , L_1 ,
V_4 [ V_6 ] . V_5 ) ;
F_5 ( V_2 . V_14 , L_2 ,
F_1 ( 0 ) ) ;
if ( V_8 . V_11 != V_8 . V_12 ) {
F_6 () ;
V_10 = F_7 ( V_2 . V_15 ) ;
V_10 |= V_16 ;
F_8 ( V_10 , V_2 . V_15 ) ;
switch ( V_9 ) {
case V_17 :
F_9 ( V_2 . V_3 ) ;
break;
case V_18 :
F_10 ( V_2 . V_3 ) ;
break;
}
F_11 () ;
V_10 = F_7 ( V_2 . V_15 ) ;
V_10 &= ~ V_16 ;
F_8 ( V_10 , V_2 . V_15 ) ;
F_12 () ;
}
F_4 ( & V_8 , V_19 ) ;
}
static int F_13 ( struct V_20 * V_21 )
{
return F_14 ( V_21 , V_4 ) ;
}
static int F_15 ( struct V_20 * V_21 ,
unsigned int V_22 ,
unsigned int V_23 )
{
unsigned int V_6 = 0 ;
if ( F_16 ( V_21 , V_4 ,
V_22 , V_23 , & V_6 ) )
return - V_24 ;
F_3 ( V_6 ) ;
return 0 ;
}
static int F_17 ( struct V_20 * V_21 )
{
int V_25 ;
V_21 -> V_26 . V_27 = 5000 ;
V_21 -> V_28 = F_1 ( 0 ) ;
V_25 = F_18 ( V_21 , V_4 ) ;
if ( V_25 )
return V_25 ;
F_19 ( V_4 , V_21 -> V_1 ) ;
return 0 ;
}
static int F_20 ( struct V_20 * V_21 )
{
F_21 ( V_21 -> V_1 ) ;
return 0 ;
}
static int F_22 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
int V_35 ;
V_2 . V_14 = & V_30 -> V_14 ;
V_34 = F_23 ( V_30 , V_36 , 0 ) ;
if ( ! V_34 ) {
F_24 ( & V_30 -> V_14 , L_3 ) ;
return - V_37 ;
}
V_2 . V_15 = F_25 ( & V_30 -> V_14 , V_34 ) ;
if ( ! V_2 . V_15 ) {
F_24 ( & V_30 -> V_14 , L_4 ) ;
return - V_38 ;
}
V_32 = F_26 ( L_5 ) ;
if ( ! V_32 )
return - V_37 ;
V_2 . V_39 = F_27 ( V_32 , L_6 ) ;
if ( F_28 ( V_2 . V_39 ) ) {
F_24 ( V_2 . V_14 , L_7 ) ;
return F_29 ( V_2 . V_39 ) ;
}
F_30 ( V_2 . V_39 ) ;
V_4 [ 0 ] . V_5 = F_31 ( V_2 . V_39 ) / 1000 ;
V_2 . V_40 = F_27 ( V_32 , L_8 ) ;
if ( F_28 ( V_2 . V_40 ) ) {
F_24 ( V_2 . V_14 , L_9 ) ;
V_35 = F_29 ( V_2 . V_40 ) ;
goto V_41;
}
F_30 ( V_2 . V_40 ) ;
V_4 [ 1 ] . V_5 = F_31 ( V_2 . V_40 ) / 1000 ;
V_2 . V_3 = F_27 ( V_32 , L_10 ) ;
if ( F_28 ( V_2 . V_3 ) ) {
F_24 ( V_2 . V_14 , L_11 ) ;
V_35 = F_29 ( V_2 . V_3 ) ;
goto V_42;
}
F_32 ( V_2 . V_3 ) ;
F_33 ( V_32 ) ;
V_32 = NULL ;
V_35 = F_34 ( & V_43 ) ;
if ( ! V_35 )
return 0 ;
F_24 ( V_2 . V_14 , L_12 ) ;
F_35 ( V_2 . V_3 ) ;
V_42:
F_35 ( V_2 . V_40 ) ;
V_41:
F_35 ( V_2 . V_39 ) ;
F_33 ( V_32 ) ;
return V_35 ;
}
static int F_36 ( struct V_29 * V_30 )
{
F_37 ( & V_43 ) ;
F_35 ( V_2 . V_3 ) ;
F_35 ( V_2 . V_40 ) ;
F_35 ( V_2 . V_39 ) ;
return 0 ;
}
