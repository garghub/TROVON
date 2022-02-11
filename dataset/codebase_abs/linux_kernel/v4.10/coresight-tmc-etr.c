static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
memset ( V_2 -> V_4 , 0 , V_2 -> V_5 ) ;
F_2 ( V_2 -> V_6 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_5 / 4 , V_2 -> V_6 + V_7 ) ;
F_4 ( V_8 , V_2 -> V_6 + V_9 ) ;
V_3 = F_5 ( V_2 -> V_6 + V_10 ) ;
V_3 |= V_11 ;
F_4 ( V_3 , V_2 -> V_6 + V_10 ) ;
V_3 &= ~ V_12 ;
F_4 ( V_3 , V_2 -> V_6 + V_10 ) ;
V_3 = ( V_3 &
~ ( V_13 | V_14 ) ) |
V_14 ;
F_4 ( V_3 , V_2 -> V_6 + V_10 ) ;
F_4 ( V_2 -> V_15 , V_2 -> V_6 + V_16 ) ;
F_4 ( 0x0 , V_2 -> V_6 + V_17 ) ;
F_4 ( V_18 | V_19 |
V_20 | V_21 |
V_22 ,
V_2 -> V_6 + V_23 ) ;
F_4 ( V_2 -> V_24 , V_2 -> V_6 + V_25 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 -> V_6 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 V_26 , V_27 ;
V_26 = F_5 ( V_2 -> V_6 + V_28 ) ;
V_27 = F_5 ( V_2 -> V_6 + V_29 ) ;
if ( V_27 & V_30 ) {
V_2 -> V_31 = V_2 -> V_4 + V_26 - V_2 -> V_15 ;
V_2 -> V_32 = V_2 -> V_5 ;
} else {
V_2 -> V_31 = V_2 -> V_4 ;
V_2 -> V_32 = V_26 - V_2 -> V_15 ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_6 ) ;
F_10 ( V_2 ) ;
if ( V_2 -> V_33 == V_34 )
F_8 ( V_2 ) ;
F_11 ( V_2 ) ;
F_7 ( V_2 -> V_6 ) ;
}
static int F_12 ( struct V_35 * V_36 )
{
int V_37 = 0 ;
bool V_38 = false ;
unsigned long V_39 ;
void T_2 * V_4 = NULL ;
T_3 V_15 ;
struct V_1 * V_2 = F_13 ( V_36 -> V_40 . V_41 ) ;
F_14 ( & V_2 -> V_42 , V_39 ) ;
if ( ! V_2 -> V_4 ) {
F_15 ( & V_2 -> V_42 , V_39 ) ;
V_4 = F_16 ( V_2 -> V_40 , V_2 -> V_5 ,
& V_15 , V_43 ) ;
if ( ! V_4 )
return - V_44 ;
F_14 ( & V_2 -> V_42 , V_39 ) ;
}
if ( V_2 -> V_45 ) {
V_37 = - V_46 ;
goto V_47;
}
if ( V_2 -> V_33 == V_34 )
goto V_47;
if ( V_2 -> V_31 == NULL ) {
V_38 = true ;
V_2 -> V_4 = V_4 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_31 = V_2 -> V_4 ;
}
V_2 -> V_33 = V_34 ;
F_1 ( V_2 ) ;
V_47:
F_15 ( & V_2 -> V_42 , V_39 ) ;
if ( ! V_38 && V_4 )
F_17 ( V_2 -> V_40 , V_2 -> V_5 , V_4 , V_15 ) ;
if ( ! V_37 )
F_18 ( V_2 -> V_40 , L_1 ) ;
return V_37 ;
}
static int F_19 ( struct V_35 * V_36 )
{
int V_37 = 0 ;
unsigned long V_39 ;
struct V_1 * V_2 = F_13 ( V_36 -> V_40 . V_41 ) ;
F_14 ( & V_2 -> V_42 , V_39 ) ;
if ( V_2 -> V_45 ) {
V_37 = - V_48 ;
goto V_47;
}
if ( V_2 -> V_33 != V_49 ) {
V_37 = - V_48 ;
goto V_47;
}
V_2 -> V_33 = V_50 ;
F_1 ( V_2 ) ;
V_47:
F_15 ( & V_2 -> V_42 , V_39 ) ;
return V_37 ;
}
static int F_20 ( struct V_35 * V_36 , T_1 V_33 )
{
switch ( V_33 ) {
case V_34 :
return F_12 ( V_36 ) ;
case V_50 :
return F_19 ( V_36 ) ;
}
return - V_48 ;
}
static void F_21 ( struct V_35 * V_36 )
{
unsigned long V_39 ;
struct V_1 * V_2 = F_13 ( V_36 -> V_40 . V_41 ) ;
F_14 ( & V_2 -> V_42 , V_39 ) ;
if ( V_2 -> V_45 ) {
F_15 ( & V_2 -> V_42 , V_39 ) ;
return;
}
if ( V_2 -> V_33 != V_49 ) {
F_9 ( V_2 ) ;
V_2 -> V_33 = V_49 ;
}
F_15 ( & V_2 -> V_42 , V_39 ) ;
F_18 ( V_2 -> V_40 , L_2 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
unsigned long V_39 ;
if ( F_23 ( V_2 -> V_51 != V_52 ) )
return - V_48 ;
F_14 ( & V_2 -> V_42 , V_39 ) ;
if ( V_2 -> V_45 ) {
V_37 = - V_46 ;
goto V_47;
}
if ( V_2 -> V_33 == V_50 ) {
V_37 = - V_48 ;
goto V_47;
}
if ( V_2 -> V_31 == NULL ) {
V_37 = - V_48 ;
goto V_47;
}
if ( V_2 -> V_33 == V_34 )
F_9 ( V_2 ) ;
V_2 -> V_45 = true ;
V_47:
F_15 ( & V_2 -> V_42 , V_39 ) ;
return V_37 ;
}
int F_24 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
T_3 V_15 ;
void T_2 * V_4 = NULL ;
if ( F_23 ( V_2 -> V_51 != V_52 ) )
return - V_48 ;
F_14 ( & V_2 -> V_42 , V_39 ) ;
if ( V_2 -> V_33 == V_34 ) {
F_1 ( V_2 ) ;
} else {
V_4 = V_2 -> V_4 ;
V_15 = V_2 -> V_15 ;
V_2 -> V_31 = V_2 -> V_4 = NULL ;
}
V_2 -> V_45 = false ;
F_15 ( & V_2 -> V_42 , V_39 ) ;
if ( V_4 )
F_17 ( V_2 -> V_40 , V_2 -> V_5 , V_4 , V_15 ) ;
return 0 ;
}
