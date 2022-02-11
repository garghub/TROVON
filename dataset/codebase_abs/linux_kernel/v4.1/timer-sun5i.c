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
static void F_11 ( enum V_13 V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_12 ( V_16 ) ;
switch ( V_14 ) {
case V_17 :
F_5 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 , V_2 -> V_4 . V_18 ) ;
F_10 ( V_2 , 0 , true ) ;
break;
case V_19 :
F_5 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 , false ) ;
break;
case V_20 :
case V_21 :
default:
F_5 ( V_2 , 0 ) ;
break;
}
}
static int F_13 ( unsigned long V_22 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_12 ( V_16 ) ;
F_5 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 , V_22 - V_6 ) ;
F_10 ( V_2 , 0 , false ) ;
return 0 ;
}
static T_3 F_14 ( int V_23 , void * V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
F_7 ( 0x1 , V_2 -> V_4 . V_5 + V_25 ) ;
V_2 -> V_16 . V_26 ( & V_2 -> V_16 ) ;
return V_27 ;
}
static T_4 F_15 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_16 ( V_29 ) ;
return ~ F_2 ( V_31 -> V_4 . V_5 + F_3 ( 1 ) ) ;
}
static int F_17 ( struct V_32 * V_33 ,
unsigned long V_34 , void * V_35 )
{
struct V_36 * V_37 = V_35 ;
struct V_38 * V_4 = F_18 ( V_33 ) ;
struct V_30 * V_31 = F_19 ( V_4 , struct V_30 , V_4 ) ;
switch ( V_34 ) {
case V_39 :
F_20 ( & V_31 -> V_29 ) ;
break;
case V_40 :
F_21 ( & V_31 -> V_29 , V_37 -> V_41 ) ;
break;
default:
break;
}
return V_42 ;
}
static int T_5 F_22 ( struct V_43 * V_44 ,
void T_6 * V_5 ,
struct V_45 * V_45 , int V_23 )
{
struct V_30 * V_31 ;
unsigned long V_46 ;
int V_47 ;
V_31 = F_23 ( sizeof( * V_31 ) , V_48 ) ;
if ( ! V_31 )
return - V_49 ;
V_47 = F_24 ( V_45 ) ;
if ( V_47 ) {
F_25 ( L_1 ) ;
goto V_50;
}
V_46 = F_26 ( V_45 ) ;
V_31 -> V_4 . V_5 = V_5 ;
V_31 -> V_4 . V_45 = V_45 ;
V_31 -> V_4 . V_51 . V_52 = F_17 ;
V_31 -> V_4 . V_51 . V_53 = NULL ;
V_47 = F_27 ( V_45 , & V_31 -> V_4 . V_51 ) ;
if ( V_47 ) {
F_25 ( L_2 ) ;
goto V_54;
}
F_7 ( ~ 0 , V_5 + F_9 ( 1 ) ) ;
F_7 ( V_8 | V_12 ,
V_5 + F_6 ( 1 ) ) ;
V_31 -> V_29 . V_55 = V_44 -> V_55 ;
V_31 -> V_29 . V_56 = 340 ;
V_31 -> V_29 . V_57 = F_15 ;
V_31 -> V_29 . V_58 = F_28 ( 32 ) ;
V_31 -> V_29 . V_59 = V_60 ;
V_47 = F_21 ( & V_31 -> V_29 , V_46 ) ;
if ( V_47 ) {
F_25 ( L_3 ) ;
goto V_61;
}
return 0 ;
V_61:
F_29 ( V_45 , & V_31 -> V_4 . V_51 ) ;
V_54:
F_30 ( V_45 ) ;
V_50:
F_31 ( V_31 ) ;
return V_47 ;
}
static int F_32 ( struct V_32 * V_33 ,
unsigned long V_34 , void * V_35 )
{
struct V_36 * V_37 = V_35 ;
struct V_38 * V_4 = F_18 ( V_33 ) ;
struct V_1 * V_2 = F_19 ( V_4 , struct V_1 , V_4 ) ;
if ( V_34 == V_40 ) {
F_33 ( & V_2 -> V_16 , V_37 -> V_41 ) ;
V_2 -> V_4 . V_18 = F_34 ( V_37 -> V_41 , V_62 ) ;
}
return V_42 ;
}
static int T_5 F_35 ( struct V_43 * V_44 , void T_6 * V_5 ,
struct V_45 * V_45 , int V_23 )
{
struct V_1 * V_2 ;
unsigned long V_46 ;
int V_47 ;
T_1 V_7 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 )
return - V_49 ;
V_47 = F_24 ( V_45 ) ;
if ( V_47 ) {
F_25 ( L_1 ) ;
goto V_50;
}
V_46 = F_26 ( V_45 ) ;
V_2 -> V_4 . V_5 = V_5 ;
V_2 -> V_4 . V_18 = F_34 ( V_46 , V_62 ) ;
V_2 -> V_4 . V_45 = V_45 ;
V_2 -> V_4 . V_51 . V_52 = F_32 ;
V_2 -> V_4 . V_51 . V_53 = NULL ;
V_47 = F_27 ( V_45 , & V_2 -> V_4 . V_51 ) ;
if ( V_47 ) {
F_25 ( L_2 ) ;
goto V_54;
}
V_2 -> V_16 . V_55 = V_44 -> V_55 ;
V_2 -> V_16 . V_63 = V_64 | V_65 ;
V_2 -> V_16 . V_66 = F_13 ;
V_2 -> V_16 . V_67 = F_11 ;
V_2 -> V_16 . V_56 = 340 ;
V_2 -> V_16 . V_23 = V_23 ;
V_2 -> V_16 . V_68 = V_69 ;
V_7 = F_2 ( V_5 + V_70 ) ;
F_7 ( V_7 | F_36 ( 0 ) , V_5 + V_70 ) ;
F_37 ( & V_2 -> V_16 , V_46 ,
V_6 , 0xffffffff ) ;
V_47 = F_38 ( V_23 , F_14 , V_71 | V_72 ,
L_4 , V_2 ) ;
if ( V_47 ) {
F_25 ( L_5 ) ;
goto V_61;
}
return 0 ;
V_61:
F_29 ( V_45 , & V_2 -> V_4 . V_51 ) ;
V_54:
F_30 ( V_45 ) ;
V_50:
F_31 ( V_2 ) ;
return V_47 ;
}
static void T_5 F_39 ( struct V_43 * V_44 )
{
struct V_73 * V_74 ;
void T_6 * V_75 ;
struct V_45 * V_45 ;
int V_23 ;
V_75 = F_40 ( V_44 , 0 , F_41 ( V_44 ) ) ;
if ( ! V_75 )
F_42 ( L_6 ) ;
V_23 = F_43 ( V_44 , 0 ) ;
if ( V_23 <= 0 )
F_42 ( L_7 ) ;
V_45 = F_44 ( V_44 , 0 ) ;
if ( F_45 ( V_45 ) )
F_42 ( L_8 ) ;
V_74 = F_46 ( V_44 , NULL ) ;
if ( ! F_45 ( V_74 ) )
F_47 ( V_74 ) ;
F_22 ( V_44 , V_75 , V_45 , V_23 ) ;
F_35 ( V_44 , V_75 , V_45 , V_23 ) ;
}
