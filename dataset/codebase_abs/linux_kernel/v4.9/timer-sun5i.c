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
static T_4 F_17 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_18 ( V_23 ) ;
return ~ F_2 ( V_25 -> V_4 . V_5 + F_3 ( 1 ) ) ;
}
static int F_19 ( struct V_26 * V_27 ,
unsigned long V_28 , void * V_29 )
{
struct V_30 * V_31 = V_29 ;
struct V_32 * V_4 = F_20 ( V_27 ) ;
struct V_24 * V_25 = F_21 ( V_4 , struct V_24 , V_4 ) ;
switch ( V_28 ) {
case V_33 :
F_22 ( & V_25 -> V_23 ) ;
break;
case V_34 :
F_23 ( & V_25 -> V_23 , V_31 -> V_35 ) ;
break;
default:
break;
}
return V_36 ;
}
static int T_5 F_24 ( struct V_37 * V_38 ,
void T_6 * V_5 ,
struct V_39 * V_39 , int V_17 )
{
struct V_24 * V_25 ;
unsigned long V_40 ;
int V_41 ;
V_25 = F_25 ( sizeof( * V_25 ) , V_42 ) ;
if ( ! V_25 )
return - V_43 ;
V_41 = F_26 ( V_39 ) ;
if ( V_41 ) {
F_27 ( L_1 ) ;
goto V_44;
}
V_40 = F_28 ( V_39 ) ;
V_25 -> V_4 . V_5 = V_5 ;
V_25 -> V_4 . V_39 = V_39 ;
V_25 -> V_4 . V_45 . V_46 = F_19 ;
V_25 -> V_4 . V_45 . V_47 = NULL ;
V_41 = F_29 ( V_39 , & V_25 -> V_4 . V_45 ) ;
if ( V_41 ) {
F_27 ( L_2 ) ;
goto V_48;
}
F_7 ( ~ 0 , V_5 + F_9 ( 1 ) ) ;
F_7 ( V_8 | V_12 ,
V_5 + F_6 ( 1 ) ) ;
V_25 -> V_23 . V_49 = V_38 -> V_49 ;
V_25 -> V_23 . V_50 = 340 ;
V_25 -> V_23 . V_51 = F_17 ;
V_25 -> V_23 . V_52 = F_30 ( 32 ) ;
V_25 -> V_23 . V_53 = V_54 ;
V_41 = F_23 ( & V_25 -> V_23 , V_40 ) ;
if ( V_41 ) {
F_27 ( L_3 ) ;
goto V_55;
}
return 0 ;
V_55:
F_31 ( V_39 , & V_25 -> V_4 . V_45 ) ;
V_48:
F_32 ( V_39 ) ;
V_44:
F_33 ( V_25 ) ;
return V_41 ;
}
static int F_34 ( struct V_26 * V_27 ,
unsigned long V_28 , void * V_29 )
{
struct V_30 * V_31 = V_29 ;
struct V_32 * V_4 = F_20 ( V_27 ) ;
struct V_1 * V_2 = F_21 ( V_4 , struct V_1 , V_4 ) ;
if ( V_28 == V_34 ) {
F_35 ( & V_2 -> V_14 , V_31 -> V_35 ) ;
V_2 -> V_4 . V_15 = F_36 ( V_31 -> V_35 , V_56 ) ;
}
return V_36 ;
}
static int T_5 F_37 ( struct V_37 * V_38 , void T_6 * V_5 ,
struct V_39 * V_39 , int V_17 )
{
struct V_1 * V_2 ;
unsigned long V_40 ;
int V_41 ;
T_1 V_7 ;
V_2 = F_25 ( sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
V_41 = F_26 ( V_39 ) ;
if ( V_41 ) {
F_27 ( L_1 ) ;
goto V_44;
}
V_40 = F_28 ( V_39 ) ;
V_2 -> V_4 . V_5 = V_5 ;
V_2 -> V_4 . V_15 = F_36 ( V_40 , V_56 ) ;
V_2 -> V_4 . V_39 = V_39 ;
V_2 -> V_4 . V_45 . V_46 = F_34 ;
V_2 -> V_4 . V_45 . V_47 = NULL ;
V_41 = F_29 ( V_39 , & V_2 -> V_4 . V_45 ) ;
if ( V_41 ) {
F_27 ( L_2 ) ;
goto V_48;
}
V_2 -> V_14 . V_49 = V_38 -> V_49 ;
V_2 -> V_14 . V_57 = V_58 | V_59 ;
V_2 -> V_14 . V_60 = F_15 ;
V_2 -> V_14 . V_61 = F_11 ;
V_2 -> V_14 . V_62 = F_14 ;
V_2 -> V_14 . V_63 = F_13 ;
V_2 -> V_14 . V_64 = F_11 ;
V_2 -> V_14 . V_50 = 340 ;
V_2 -> V_14 . V_17 = V_17 ;
V_2 -> V_14 . V_65 = V_66 ;
V_7 = F_2 ( V_5 + V_67 ) ;
F_7 ( V_7 | F_38 ( 0 ) , V_5 + V_67 ) ;
F_39 ( & V_2 -> V_14 , V_40 ,
V_6 , 0xffffffff ) ;
V_41 = F_40 ( V_17 , F_16 , V_68 | V_69 ,
L_4 , V_2 ) ;
if ( V_41 ) {
F_27 ( L_5 ) ;
goto V_55;
}
return 0 ;
V_55:
F_31 ( V_39 , & V_2 -> V_4 . V_45 ) ;
V_48:
F_32 ( V_39 ) ;
V_44:
F_33 ( V_2 ) ;
return V_41 ;
}
static int T_5 F_41 ( struct V_37 * V_38 )
{
struct V_70 * V_71 ;
void T_6 * V_72 ;
struct V_39 * V_39 ;
int V_17 , V_41 ;
V_72 = F_42 ( V_38 , 0 , F_43 ( V_38 ) ) ;
if ( F_44 ( V_72 ) ) {
F_27 ( L_6 ) ;
return F_45 ( V_72 ) ; ;
}
V_17 = F_46 ( V_38 , 0 ) ;
if ( V_17 <= 0 ) {
F_27 ( L_7 ) ;
return - V_73 ;
}
V_39 = F_47 ( V_38 , 0 ) ;
if ( F_44 ( V_39 ) ) {
F_27 ( L_8 ) ;
return F_45 ( V_39 ) ;
}
V_71 = F_48 ( V_38 , NULL ) ;
if ( ! F_44 ( V_71 ) )
F_49 ( V_71 ) ;
V_41 = F_24 ( V_38 , V_72 , V_39 , V_17 ) ;
if ( V_41 )
return V_41 ;
return F_37 ( V_38 , V_72 , V_39 , V_17 ) ;
}
