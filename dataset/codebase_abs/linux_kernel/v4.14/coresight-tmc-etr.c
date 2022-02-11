static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
memset ( V_2 -> V_5 , 0 , V_2 -> V_6 ) ;
F_2 ( V_2 -> V_7 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_6 / 4 , V_2 -> V_7 + V_8 ) ;
F_4 ( V_9 , V_2 -> V_7 + V_10 ) ;
V_3 = F_5 ( V_2 -> V_7 + V_11 ) ;
V_3 &= ~ V_12 ;
V_3 |= ( V_13 | V_14 ) ;
V_3 |= V_15 ;
if ( F_6 ( V_2 , V_16 ) ) {
V_3 &= ~ V_17 ;
V_3 |= V_18 ;
}
F_4 ( V_3 , V_2 -> V_7 + V_11 ) ;
F_7 ( V_2 , V_2 -> V_19 ) ;
if ( F_6 ( V_2 , V_20 ) ) {
F_8 ( V_2 , V_2 -> V_19 ) ;
F_9 ( V_2 , V_2 -> V_19 ) ;
V_4 = F_5 ( V_2 -> V_7 + V_21 ) & ~ V_22 ;
F_4 ( V_4 , V_2 -> V_7 + V_21 ) ;
}
F_4 ( V_23 | V_24 |
V_25 | V_26 |
V_27 ,
V_2 -> V_7 + V_28 ) ;
F_4 ( V_2 -> V_29 , V_2 -> V_7 + V_30 ) ;
F_10 ( V_2 ) ;
F_11 ( V_2 -> V_7 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
const T_1 * V_31 ;
T_1 V_32 ;
T_1 * V_33 ;
T_2 V_34 ;
V_34 = F_13 ( V_2 ) ;
V_32 = F_5 ( V_2 -> V_7 + V_21 ) ;
if ( V_32 & V_22 ) {
V_2 -> V_35 = V_2 -> V_5 + V_34 - V_2 -> V_19 ;
V_2 -> V_36 = V_2 -> V_6 ;
V_31 = V_37 ;
V_33 = ( T_1 * ) V_2 -> V_35 ;
while ( * V_31 ) {
* V_33 = * V_31 ;
V_33 ++ ;
V_31 ++ ;
}
} else {
V_2 -> V_35 = V_2 -> V_5 ;
V_2 -> V_36 = V_34 - V_2 -> V_19 ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_7 ) ;
F_15 ( V_2 ) ;
if ( V_2 -> V_38 == V_39 )
F_12 ( V_2 ) ;
F_16 ( V_2 ) ;
F_11 ( V_2 -> V_7 ) ;
}
static int F_17 ( struct V_40 * V_41 )
{
int V_42 = 0 ;
bool V_43 = false ;
unsigned long V_44 ;
void T_3 * V_5 = NULL ;
T_4 V_19 ;
struct V_1 * V_2 = F_18 ( V_41 -> V_45 . V_46 ) ;
F_19 ( & V_2 -> V_47 , V_44 ) ;
if ( ! V_2 -> V_5 ) {
F_20 ( & V_2 -> V_47 , V_44 ) ;
V_5 = F_21 ( V_2 -> V_45 , V_2 -> V_6 ,
& V_19 , V_48 ) ;
if ( ! V_5 )
return - V_49 ;
F_19 ( & V_2 -> V_47 , V_44 ) ;
}
if ( V_2 -> V_50 ) {
V_42 = - V_51 ;
goto V_52;
}
if ( V_2 -> V_38 == V_39 )
goto V_52;
if ( V_2 -> V_35 == NULL ) {
V_43 = true ;
V_2 -> V_5 = V_5 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_35 = V_2 -> V_5 ;
}
V_2 -> V_38 = V_39 ;
F_1 ( V_2 ) ;
V_52:
F_20 ( & V_2 -> V_47 , V_44 ) ;
if ( ! V_43 && V_5 )
F_22 ( V_2 -> V_45 , V_2 -> V_6 , V_5 , V_19 ) ;
if ( ! V_42 )
F_23 ( V_2 -> V_45 , L_1 ) ;
return V_42 ;
}
static int F_24 ( struct V_40 * V_41 )
{
int V_42 = 0 ;
unsigned long V_44 ;
struct V_1 * V_2 = F_18 ( V_41 -> V_45 . V_46 ) ;
F_19 ( & V_2 -> V_47 , V_44 ) ;
if ( V_2 -> V_50 ) {
V_42 = - V_53 ;
goto V_52;
}
if ( V_2 -> V_38 != V_54 ) {
V_42 = - V_53 ;
goto V_52;
}
V_2 -> V_38 = V_55 ;
F_1 ( V_2 ) ;
V_52:
F_20 ( & V_2 -> V_47 , V_44 ) ;
return V_42 ;
}
static int F_25 ( struct V_40 * V_41 , T_1 V_38 )
{
switch ( V_38 ) {
case V_39 :
return F_17 ( V_41 ) ;
case V_55 :
return F_24 ( V_41 ) ;
}
return - V_53 ;
}
static void F_26 ( struct V_40 * V_41 )
{
unsigned long V_44 ;
struct V_1 * V_2 = F_18 ( V_41 -> V_45 . V_46 ) ;
F_19 ( & V_2 -> V_47 , V_44 ) ;
if ( V_2 -> V_50 ) {
F_20 ( & V_2 -> V_47 , V_44 ) ;
return;
}
if ( V_2 -> V_38 != V_54 ) {
F_14 ( V_2 ) ;
V_2 -> V_38 = V_54 ;
}
F_20 ( & V_2 -> V_47 , V_44 ) ;
F_23 ( V_2 -> V_45 , L_2 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
int V_42 = 0 ;
unsigned long V_44 ;
if ( F_28 ( V_2 -> V_56 != V_57 ) )
return - V_53 ;
F_19 ( & V_2 -> V_47 , V_44 ) ;
if ( V_2 -> V_50 ) {
V_42 = - V_51 ;
goto V_52;
}
if ( V_2 -> V_38 == V_55 ) {
V_42 = - V_53 ;
goto V_52;
}
if ( V_2 -> V_35 == NULL ) {
V_42 = - V_53 ;
goto V_52;
}
if ( V_2 -> V_38 == V_39 )
F_14 ( V_2 ) ;
V_2 -> V_50 = true ;
V_52:
F_20 ( & V_2 -> V_47 , V_44 ) ;
return V_42 ;
}
int F_29 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
T_4 V_19 ;
void T_3 * V_5 = NULL ;
if ( F_28 ( V_2 -> V_56 != V_57 ) )
return - V_53 ;
F_19 ( & V_2 -> V_47 , V_44 ) ;
if ( V_2 -> V_38 == V_39 ) {
F_1 ( V_2 ) ;
} else {
V_5 = V_2 -> V_5 ;
V_19 = V_2 -> V_19 ;
V_2 -> V_35 = V_2 -> V_5 = NULL ;
}
V_2 -> V_50 = false ;
F_20 ( & V_2 -> V_47 , V_44 ) ;
if ( V_5 )
F_22 ( V_2 -> V_45 , V_2 -> V_6 , V_5 , V_19 ) ;
return 0 ;
}
