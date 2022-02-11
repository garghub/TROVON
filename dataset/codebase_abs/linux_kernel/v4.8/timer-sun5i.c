static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 . V_5 + F_3 ( 1 ) ) ;
while ( ( V_3 - F_2 ( V_2 -> V_4 . V_5 + F_3 ( 1 ) ) ) < V_6 )
F_4 () ;
}
static void F_5 ( struct V_1 * V_2 , T_2 V_4 )
{
T_1 V_7 = F_2 ( V_2 -> V_4 . V_5 + F_6 ( V_4 ) ) ;
F_7 ( V_7 & ~ V_8 , V_2 -> V_4 . V_5 + F_6 ( V_4 ) ) ;
F_1 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_4 , T_1 V_9 )
{
F_7 ( V_9 , V_2 -> V_4 . V_5 + F_9 ( V_4 ) ) ;
}
static void F_10 ( struct V_1 * V_2 , T_2 V_4 , bool V_10 )
{
T_1 V_7 = F_2 ( V_2 -> V_4 . V_5 + F_6 ( V_4 ) ) ;
if ( V_10 )
V_7 &= ~ V_11 ;
else
V_7 |= V_11 ;
F_7 ( V_7 | V_8 | V_12 ,
V_2 -> V_4 . V_5 + F_6 ( V_4 ) ) ;
}
static int F_11 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_12 ( V_14 ) ;
F_5 ( V_2 , 0 ) ;
return 0 ;
}
static int F_13 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_12 ( V_14 ) ;
F_5 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 , false ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_12 ( V_14 ) ;
F_5 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 , V_2 -> V_4 . V_15 ) ;
F_10 ( V_2 , 0 , true ) ;
return 0 ;
}
static int F_15 ( unsigned long V_16 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_12 ( V_14 ) ;
F_5 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 , V_16 - V_6 ) ;
F_10 ( V_2 , 0 , false ) ;
return 0 ;
}
static T_3 F_16 ( int V_17 , void * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
F_7 ( 0x1 , V_2 -> V_4 . V_5 + V_19 ) ;
V_2 -> V_14 . V_20 ( & V_2 -> V_14 ) ;
return V_21 ;
}
static int F_17 ( struct V_22 * V_23 ,
unsigned long V_24 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_28 * V_4 = F_18 ( V_23 ) ;
struct V_29 * V_30 = F_19 ( V_4 , struct V_29 , V_4 ) ;
switch ( V_24 ) {
case V_31 :
F_20 ( & V_30 -> V_32 ) ;
break;
case V_33 :
F_21 ( & V_30 -> V_32 , V_27 -> V_34 ) ;
break;
default:
break;
}
return V_35 ;
}
static int T_4 F_22 ( struct V_36 * V_37 ,
void T_5 * V_5 ,
struct V_38 * V_38 , int V_17 )
{
struct V_29 * V_30 ;
unsigned long V_39 ;
int V_40 ;
V_30 = F_23 ( sizeof( * V_30 ) , V_41 ) ;
if ( ! V_30 )
return - V_42 ;
V_40 = F_24 ( V_38 ) ;
if ( V_40 ) {
F_25 ( L_1 ) ;
goto V_43;
}
V_39 = F_26 ( V_38 ) ;
V_30 -> V_4 . V_5 = V_5 ;
V_30 -> V_4 . V_38 = V_38 ;
V_30 -> V_4 . V_44 . V_45 = F_17 ;
V_30 -> V_4 . V_44 . V_46 = NULL ;
V_40 = F_27 ( V_38 , & V_30 -> V_4 . V_44 ) ;
if ( V_40 ) {
F_25 ( L_2 ) ;
goto V_47;
}
F_7 ( ~ 0 , V_5 + F_9 ( 1 ) ) ;
F_7 ( V_8 | V_12 ,
V_5 + F_6 ( 1 ) ) ;
V_40 = F_28 ( V_5 + F_3 ( 1 ) , V_37 -> V_48 ,
V_39 , 340 , 32 , V_49 ) ;
if ( V_40 ) {
F_25 ( L_3 ) ;
goto V_50;
}
return 0 ;
V_50:
F_29 ( V_38 , & V_30 -> V_4 . V_44 ) ;
V_47:
F_30 ( V_38 ) ;
V_43:
F_31 ( V_30 ) ;
return V_40 ;
}
static int F_32 ( struct V_22 * V_23 ,
unsigned long V_24 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_28 * V_4 = F_18 ( V_23 ) ;
struct V_1 * V_2 = F_19 ( V_4 , struct V_1 , V_4 ) ;
if ( V_24 == V_33 ) {
F_33 ( & V_2 -> V_14 , V_27 -> V_34 ) ;
V_2 -> V_4 . V_15 = F_34 ( V_27 -> V_34 , V_51 ) ;
}
return V_35 ;
}
static int T_4 F_35 ( struct V_36 * V_37 , void T_5 * V_5 ,
struct V_38 * V_38 , int V_17 )
{
struct V_1 * V_2 ;
unsigned long V_39 ;
int V_40 ;
T_1 V_7 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
V_40 = F_24 ( V_38 ) ;
if ( V_40 ) {
F_25 ( L_1 ) ;
goto V_43;
}
V_39 = F_26 ( V_38 ) ;
V_2 -> V_4 . V_5 = V_5 ;
V_2 -> V_4 . V_15 = F_34 ( V_39 , V_51 ) ;
V_2 -> V_4 . V_38 = V_38 ;
V_2 -> V_4 . V_44 . V_45 = F_32 ;
V_2 -> V_4 . V_44 . V_46 = NULL ;
V_40 = F_27 ( V_38 , & V_2 -> V_4 . V_44 ) ;
if ( V_40 ) {
F_25 ( L_2 ) ;
goto V_47;
}
V_2 -> V_14 . V_48 = V_37 -> V_48 ;
V_2 -> V_14 . V_52 = V_53 | V_54 ;
V_2 -> V_14 . V_55 = F_15 ;
V_2 -> V_14 . V_56 = F_11 ;
V_2 -> V_14 . V_57 = F_14 ;
V_2 -> V_14 . V_58 = F_13 ;
V_2 -> V_14 . V_59 = F_11 ;
V_2 -> V_14 . V_60 = 340 ;
V_2 -> V_14 . V_17 = V_17 ;
V_2 -> V_14 . V_61 = V_62 ;
V_7 = F_2 ( V_5 + V_63 ) ;
F_7 ( V_7 | F_36 ( 0 ) , V_5 + V_63 ) ;
F_37 ( & V_2 -> V_14 , V_39 ,
V_6 , 0xffffffff ) ;
V_40 = F_38 ( V_17 , F_16 , V_64 | V_65 ,
L_4 , V_2 ) ;
if ( V_40 ) {
F_25 ( L_5 ) ;
goto V_50;
}
return 0 ;
V_50:
F_29 ( V_38 , & V_2 -> V_4 . V_44 ) ;
V_47:
F_30 ( V_38 ) ;
V_43:
F_31 ( V_2 ) ;
return V_40 ;
}
static int T_4 F_39 ( struct V_36 * V_37 )
{
struct V_66 * V_67 ;
void T_5 * V_68 ;
struct V_38 * V_38 ;
int V_17 , V_40 ;
V_68 = F_40 ( V_37 , 0 , F_41 ( V_37 ) ) ;
if ( F_42 ( V_68 ) ) {
F_25 ( L_6 ) ;
return F_43 ( V_68 ) ; ;
}
V_17 = F_44 ( V_37 , 0 ) ;
if ( V_17 <= 0 ) {
F_25 ( L_7 ) ;
return - V_69 ;
}
V_38 = F_45 ( V_37 , 0 ) ;
if ( F_42 ( V_38 ) ) {
F_25 ( L_8 ) ;
return F_43 ( V_38 ) ;
}
V_67 = F_46 ( V_37 , NULL ) ;
if ( ! F_42 ( V_67 ) )
F_47 ( V_67 ) ;
V_40 = F_22 ( V_37 , V_68 , V_38 , V_17 ) ;
if ( V_40 )
return V_40 ;
return F_35 ( V_37 , V_68 , V_38 , V_17 ) ;
}
