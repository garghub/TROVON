static unsigned int F_1 ( unsigned int V_1 )
{
if ( F_2 ( V_2 . V_3 ) )
return V_4 [ 1 ] . V_5 ;
return V_4 [ 0 ] . V_5 ;
}
static void F_3 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
struct V_9 V_10 ;
unsigned int V_11 = V_4 [ V_8 ] . V_8 ;
unsigned long V_12 ;
V_10 . V_13 = F_1 ( 0 ) ;
V_10 . V_14 = V_4 [ V_8 ] . V_5 ;
F_4 ( V_7 , & V_10 , V_15 ) ;
F_5 ( V_2 . V_16 , L_1 ,
V_4 [ V_8 ] . V_5 ) ;
F_5 ( V_2 . V_16 , L_2 ,
F_1 ( 0 ) ) ;
if ( V_10 . V_13 != V_10 . V_14 ) {
F_6 () ;
V_12 = F_7 ( V_2 . V_17 ) ;
V_12 |= V_18 ;
F_8 ( V_12 , V_2 . V_17 ) ;
switch ( V_11 ) {
case V_19 :
F_9 ( V_2 . V_3 ) ;
break;
case V_20 :
F_10 ( V_2 . V_3 ) ;
break;
}
F_11 () ;
V_12 = F_7 ( V_2 . V_17 ) ;
V_12 &= ~ V_18 ;
F_8 ( V_12 , V_2 . V_17 ) ;
F_12 () ;
}
F_4 ( V_7 , & V_10 , V_21 ) ;
}
static int F_13 ( struct V_6 * V_7 )
{
return F_14 ( V_7 , V_4 ) ;
}
static int F_15 ( struct V_6 * V_7 ,
unsigned int V_22 ,
unsigned int V_23 )
{
unsigned int V_8 = 0 ;
if ( F_16 ( V_7 , V_4 ,
V_22 , V_23 , & V_8 ) )
return - V_24 ;
F_3 ( V_7 , V_8 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 )
{
int V_25 ;
V_7 -> V_26 . V_27 = 5000 ;
V_7 -> V_28 = F_1 ( 0 ) ;
V_25 = F_18 ( V_7 , V_4 ) ;
if ( V_25 )
return V_25 ;
F_19 ( V_4 , V_7 -> V_1 ) ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 )
{
F_21 ( V_7 -> V_1 ) ;
return 0 ;
}
static int F_22 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
int V_35 ;
V_2 . V_16 = & V_30 -> V_16 ;
V_34 = F_23 ( V_30 , V_36 , 0 ) ;
V_2 . V_17 = F_24 ( & V_30 -> V_16 , V_34 ) ;
if ( F_25 ( V_2 . V_17 ) )
return F_26 ( V_2 . V_17 ) ;
V_32 = F_27 ( L_3 ) ;
if ( ! V_32 )
return - V_37 ;
V_2 . V_38 = F_28 ( V_32 , L_4 ) ;
if ( F_25 ( V_2 . V_38 ) ) {
F_29 ( V_2 . V_16 , L_5 ) ;
return F_26 ( V_2 . V_38 ) ;
}
F_30 ( V_2 . V_38 ) ;
V_4 [ 0 ] . V_5 = F_31 ( V_2 . V_38 ) / 1000 ;
V_2 . V_39 = F_28 ( V_32 , L_6 ) ;
if ( F_25 ( V_2 . V_39 ) ) {
F_29 ( V_2 . V_16 , L_7 ) ;
V_35 = F_26 ( V_2 . V_39 ) ;
goto V_40;
}
F_30 ( V_2 . V_39 ) ;
V_4 [ 1 ] . V_5 = F_31 ( V_2 . V_39 ) / 1000 ;
V_2 . V_3 = F_28 ( V_32 , L_8 ) ;
if ( F_25 ( V_2 . V_3 ) ) {
F_29 ( V_2 . V_16 , L_9 ) ;
V_35 = F_26 ( V_2 . V_3 ) ;
goto V_41;
}
F_32 ( V_2 . V_3 ) ;
F_33 ( V_32 ) ;
V_32 = NULL ;
V_35 = F_34 ( & V_42 ) ;
if ( ! V_35 )
return 0 ;
F_29 ( V_2 . V_16 , L_10 ) ;
F_35 ( V_2 . V_3 ) ;
V_41:
F_35 ( V_2 . V_39 ) ;
V_40:
F_35 ( V_2 . V_38 ) ;
F_33 ( V_32 ) ;
return V_35 ;
}
static int F_36 ( struct V_29 * V_30 )
{
F_37 ( & V_42 ) ;
F_35 ( V_2 . V_3 ) ;
F_35 ( V_2 . V_39 ) ;
F_35 ( V_2 . V_38 ) ;
return 0 ;
}
