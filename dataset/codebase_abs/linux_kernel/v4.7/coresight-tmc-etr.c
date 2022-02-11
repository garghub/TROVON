void F_1 ( struct V_1 * V_2 )
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
if ( V_27 & F_9 ( 0 ) )
V_2 -> V_30 = V_2 -> V_4 + V_26 - V_2 -> V_15 ;
else
V_2 -> V_30 = V_2 -> V_4 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_6 ) ;
F_11 ( V_2 ) ;
if ( F_12 ( & V_2 -> V_31 ) == V_32 )
F_8 ( V_2 ) ;
F_13 ( V_2 ) ;
F_7 ( V_2 -> V_6 ) ;
}
static int F_14 ( struct V_33 * V_34 , T_1 V_31 )
{
int V_35 = 0 ;
bool V_36 = false ;
long V_27 ;
unsigned long V_37 ;
void T_2 * V_4 = NULL ;
T_3 V_15 ;
struct V_1 * V_2 = F_15 ( V_34 -> V_38 . V_39 ) ;
if ( F_16 ( V_31 != V_32 ) )
return - V_40 ;
F_17 ( & V_2 -> V_41 , V_37 ) ;
if ( ! V_2 -> V_4 ) {
F_18 ( & V_2 -> V_41 , V_37 ) ;
V_4 = F_19 ( V_2 -> V_38 , V_2 -> V_5 ,
& V_15 , V_42 ) ;
if ( ! V_4 )
return - V_43 ;
F_17 ( & V_2 -> V_41 , V_37 ) ;
}
if ( V_2 -> V_44 ) {
V_35 = - V_45 ;
goto V_46;
}
V_27 = F_20 ( & V_2 -> V_31 , V_31 ) ;
if ( V_27 == V_32 )
goto V_46;
if ( V_2 -> V_30 == NULL ) {
V_36 = true ;
V_2 -> V_4 = V_4 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_30 = V_2 -> V_4 ;
}
memset ( V_2 -> V_4 , 0 , V_2 -> V_5 ) ;
F_1 ( V_2 ) ;
V_46:
F_18 ( & V_2 -> V_41 , V_37 ) ;
if ( ! V_36 && V_4 )
F_21 ( V_2 -> V_38 , V_2 -> V_5 , V_4 , V_15 ) ;
if ( ! V_35 )
F_22 ( V_2 -> V_38 , L_1 ) ;
return V_35 ;
}
static int F_23 ( struct V_33 * V_34 , T_1 V_31 )
{
int V_35 = 0 ;
long V_27 ;
unsigned long V_37 ;
struct V_1 * V_2 = F_15 ( V_34 -> V_38 . V_39 ) ;
if ( F_16 ( V_31 != V_47 ) )
return - V_40 ;
F_17 ( & V_2 -> V_41 , V_37 ) ;
if ( V_2 -> V_44 ) {
V_35 = - V_40 ;
goto V_46;
}
V_27 = F_20 ( & V_2 -> V_31 , V_31 ) ;
if ( V_27 != V_48 ) {
V_35 = - V_40 ;
goto V_46;
}
F_1 ( V_2 ) ;
V_46:
F_18 ( & V_2 -> V_41 , V_37 ) ;
return V_35 ;
}
static int F_24 ( struct V_33 * V_34 , T_1 V_31 )
{
switch ( V_31 ) {
case V_32 :
return F_14 ( V_34 , V_31 ) ;
case V_47 :
return F_23 ( V_34 , V_31 ) ;
}
return - V_40 ;
}
static void F_25 ( struct V_33 * V_34 )
{
long V_27 ;
unsigned long V_37 ;
struct V_1 * V_2 = F_15 ( V_34 -> V_38 . V_39 ) ;
F_17 ( & V_2 -> V_41 , V_37 ) ;
if ( V_2 -> V_44 ) {
F_18 ( & V_2 -> V_41 , V_37 ) ;
return;
}
V_27 = F_20 ( & V_2 -> V_31 , V_48 ) ;
if ( V_27 != V_48 )
F_10 ( V_2 ) ;
F_18 ( & V_2 -> V_41 , V_37 ) ;
F_22 ( V_2 -> V_38 , L_2 ) ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
long V_27 ;
unsigned long V_37 ;
if ( F_27 ( V_2 -> V_49 != V_50 ) )
return - V_40 ;
F_17 ( & V_2 -> V_41 , V_37 ) ;
if ( V_2 -> V_44 ) {
V_35 = - V_45 ;
goto V_46;
}
V_27 = F_12 ( & V_2 -> V_31 ) ;
if ( V_27 == V_47 ) {
V_35 = - V_40 ;
goto V_46;
}
if ( V_2 -> V_30 == NULL ) {
V_35 = - V_40 ;
goto V_46;
}
if ( V_27 == V_32 )
F_10 ( V_2 ) ;
V_2 -> V_44 = true ;
V_46:
F_18 ( & V_2 -> V_41 , V_37 ) ;
return V_35 ;
}
int F_28 ( struct V_1 * V_2 )
{
unsigned long V_37 ;
T_3 V_15 ;
void T_2 * V_4 = NULL ;
if ( F_27 ( V_2 -> V_49 != V_50 ) )
return - V_40 ;
F_17 ( & V_2 -> V_41 , V_37 ) ;
if ( F_12 ( & V_2 -> V_31 ) == V_32 ) {
F_1 ( V_2 ) ;
} else {
V_4 = V_2 -> V_4 ;
V_15 = V_2 -> V_15 ;
V_2 -> V_30 = V_2 -> V_4 = NULL ;
}
V_2 -> V_44 = false ;
F_18 ( & V_2 -> V_41 , V_37 ) ;
if ( V_4 )
F_21 ( V_2 -> V_38 , V_2 -> V_5 , V_4 , V_15 ) ;
return 0 ;
}
