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
if ( F_11 ( & V_2 -> V_33 ) == V_34 )
F_8 ( V_2 ) ;
F_12 ( V_2 ) ;
F_7 ( V_2 -> V_6 ) ;
}
static int F_13 ( struct V_35 * V_36 , T_1 V_33 )
{
int V_37 = 0 ;
bool V_38 = false ;
long V_27 ;
unsigned long V_39 ;
void T_2 * V_4 = NULL ;
T_3 V_15 ;
struct V_1 * V_2 = F_14 ( V_36 -> V_40 . V_41 ) ;
if ( F_15 ( V_33 != V_34 ) )
return - V_42 ;
F_16 ( & V_2 -> V_43 , V_39 ) ;
if ( ! V_2 -> V_4 ) {
F_17 ( & V_2 -> V_43 , V_39 ) ;
V_4 = F_18 ( V_2 -> V_40 , V_2 -> V_5 ,
& V_15 , V_44 ) ;
if ( ! V_4 )
return - V_45 ;
F_16 ( & V_2 -> V_43 , V_39 ) ;
}
if ( V_2 -> V_46 ) {
V_37 = - V_47 ;
goto V_48;
}
V_27 = F_19 ( & V_2 -> V_33 , V_33 ) ;
if ( V_27 == V_34 )
goto V_48;
if ( V_2 -> V_31 == NULL ) {
V_38 = true ;
V_2 -> V_4 = V_4 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_31 = V_2 -> V_4 ;
}
memset ( V_2 -> V_4 , 0 , V_2 -> V_5 ) ;
F_1 ( V_2 ) ;
V_48:
F_17 ( & V_2 -> V_43 , V_39 ) ;
if ( ! V_38 && V_4 )
F_20 ( V_2 -> V_40 , V_2 -> V_5 , V_4 , V_15 ) ;
if ( ! V_37 )
F_21 ( V_2 -> V_40 , L_1 ) ;
return V_37 ;
}
static int F_22 ( struct V_35 * V_36 , T_1 V_33 )
{
int V_37 = 0 ;
long V_27 ;
unsigned long V_39 ;
struct V_1 * V_2 = F_14 ( V_36 -> V_40 . V_41 ) ;
if ( F_15 ( V_33 != V_49 ) )
return - V_42 ;
F_16 ( & V_2 -> V_43 , V_39 ) ;
if ( V_2 -> V_46 ) {
V_37 = - V_42 ;
goto V_48;
}
V_27 = F_19 ( & V_2 -> V_33 , V_33 ) ;
if ( V_27 != V_50 ) {
V_37 = - V_42 ;
goto V_48;
}
F_1 ( V_2 ) ;
V_48:
F_17 ( & V_2 -> V_43 , V_39 ) ;
return V_37 ;
}
static int F_23 ( struct V_35 * V_36 , T_1 V_33 )
{
switch ( V_33 ) {
case V_34 :
return F_13 ( V_36 , V_33 ) ;
case V_49 :
return F_22 ( V_36 , V_33 ) ;
}
return - V_42 ;
}
static void F_24 ( struct V_35 * V_36 )
{
long V_27 ;
unsigned long V_39 ;
struct V_1 * V_2 = F_14 ( V_36 -> V_40 . V_41 ) ;
F_16 ( & V_2 -> V_43 , V_39 ) ;
if ( V_2 -> V_46 ) {
F_17 ( & V_2 -> V_43 , V_39 ) ;
return;
}
V_27 = F_19 ( & V_2 -> V_33 , V_50 ) ;
if ( V_27 != V_50 )
F_9 ( V_2 ) ;
F_17 ( & V_2 -> V_43 , V_39 ) ;
F_21 ( V_2 -> V_40 , L_2 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
long V_27 ;
unsigned long V_39 ;
if ( F_26 ( V_2 -> V_51 != V_52 ) )
return - V_42 ;
F_16 ( & V_2 -> V_43 , V_39 ) ;
if ( V_2 -> V_46 ) {
V_37 = - V_47 ;
goto V_48;
}
V_27 = F_11 ( & V_2 -> V_33 ) ;
if ( V_27 == V_49 ) {
V_37 = - V_42 ;
goto V_48;
}
if ( V_2 -> V_31 == NULL ) {
V_37 = - V_42 ;
goto V_48;
}
if ( V_27 == V_34 )
F_9 ( V_2 ) ;
V_2 -> V_46 = true ;
V_48:
F_17 ( & V_2 -> V_43 , V_39 ) ;
return V_37 ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
T_3 V_15 ;
void T_2 * V_4 = NULL ;
if ( F_26 ( V_2 -> V_51 != V_52 ) )
return - V_42 ;
F_16 ( & V_2 -> V_43 , V_39 ) ;
if ( F_11 ( & V_2 -> V_33 ) == V_34 ) {
F_1 ( V_2 ) ;
} else {
V_4 = V_2 -> V_4 ;
V_15 = V_2 -> V_15 ;
V_2 -> V_31 = V_2 -> V_4 = NULL ;
}
V_2 -> V_46 = false ;
F_17 ( & V_2 -> V_43 , V_39 ) ;
if ( V_4 )
F_20 ( V_2 -> V_40 , V_2 -> V_5 , V_4 , V_15 ) ;
return 0 ;
}
