static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , struct V_2 , V_1 ) ;
F_3 ( V_3 ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
F_5 ( & V_3 -> V_1 , F_1 ) ;
}
static struct V_2 * F_6 ( struct V_4 * V_4 )
{
struct V_2 * V_3 ;
F_7 ( & V_5 ) ;
F_8 (cap, &cap_list, node) {
if ( & V_3 -> V_4 == V_4 ) {
F_9 ( & V_3 -> V_1 ) ;
goto V_6;
}
}
V_3 = NULL ;
V_6:
F_10 ( & V_5 ) ;
return V_3 ;
}
static int F_11 ( struct V_2 * V_3 , T_1 * V_7 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 V_11 ;
int V_12 ;
V_12 = F_12 ( V_9 , V_13 , NULL ,
0 , & V_11 , sizeof( V_11 ) ) ;
if ( V_12 ) {
F_13 ( V_3 -> V_14 , L_1 , V_12 ) ;
return V_12 ;
}
memcpy ( V_7 , V_11 . V_15 , sizeof( V_11 . V_15 ) ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , T_2 V_16 , T_2 V_17 ,
T_1 * V_18 , T_2 * V_19 , T_1 * V_20 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_21 * V_22 ;
struct V_23 * V_11 ;
T_3 V_24 = F_15 ( V_9 ) ;
struct V_25 * V_26 ;
int V_12 ;
V_26 = F_16 ( V_9 ,
V_27 ,
sizeof( * V_22 ) , V_24 ,
V_28 ,
V_29 ) ;
if ( ! V_26 )
return - V_30 ;
V_22 = V_26 -> V_22 -> V_31 ;
V_22 -> V_32 = F_17 ( V_16 ) ;
V_22 -> V_33 = F_17 ( V_17 ) ;
V_12 = F_18 ( V_26 ) ;
if ( V_12 ) {
F_13 ( V_3 -> V_14 , L_2 , V_12 ) ;
goto V_34;
}
V_11 = V_26 -> V_11 -> V_31 ;
* V_20 = V_11 -> V_35 ;
* V_19 = V_26 -> V_11 -> V_36 - sizeof( * V_11 ) ;
memcpy ( V_18 , V_11 -> V_18 , * V_19 ) ;
V_34:
F_19 ( V_26 ) ;
return V_12 ;
}
static int F_20 ( struct V_2 * V_3 , T_2 V_37 , T_1 * V_15 ,
T_1 * V_38 , T_1 * V_20 , T_1 * V_39 ,
T_2 * V_40 , T_1 * V_41 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_42 * V_22 ;
struct V_43 * V_11 ;
T_3 V_24 = F_15 ( V_9 ) ;
struct V_25 * V_26 ;
int V_12 ;
V_26 = F_16 ( V_9 , V_44 ,
sizeof( * V_22 ) , V_24 ,
V_28 ,
V_29 ) ;
if ( ! V_26 )
return - V_30 ;
V_22 = V_26 -> V_22 -> V_31 ;
V_22 -> V_37 = F_17 ( V_37 ) ;
memcpy ( V_22 -> V_15 , V_15 , sizeof( V_22 -> V_15 ) ) ;
memcpy ( V_22 -> V_38 , V_38 , sizeof( V_22 -> V_38 ) ) ;
V_12 = F_18 ( V_26 ) ;
if ( V_12 ) {
F_13 ( V_3 -> V_14 , L_3 , V_12 ) ;
goto V_34;
}
V_11 = V_26 -> V_11 -> V_31 ;
* V_20 = V_11 -> V_35 ;
* V_40 = V_26 -> V_11 -> V_36 - sizeof( * V_11 ) ;
memcpy ( V_39 , V_11 -> V_11 , sizeof( V_11 -> V_11 ) ) ;
memcpy ( V_41 , V_11 -> V_41 , * V_40 ) ;
V_34:
F_19 ( V_26 ) ;
return V_12 ;
}
static int F_21 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
struct V_2 * V_3 = F_6 ( V_45 -> V_47 ) ;
if ( V_3 ) {
V_46 -> V_48 = V_3 ;
return 0 ;
}
return - V_49 ;
}
static int F_22 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
struct V_2 * V_3 = V_46 -> V_48 ;
F_4 ( V_3 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , unsigned int V_50 ,
void T_4 * V_51 )
{
struct V_52 V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_3 V_19 ;
int V_12 ;
switch ( V_50 ) {
case V_58 :
V_12 = F_11 ( V_3 , V_53 . V_15 ) ;
if ( V_12 )
return V_12 ;
if ( F_24 ( V_51 , & V_53 , sizeof( V_53 ) ) )
return - V_59 ;
return 0 ;
case V_60 :
V_19 = sizeof( * V_55 ) ;
V_55 = F_25 ( V_51 , V_19 ) ;
if ( F_26 ( V_55 ) )
return F_27 ( V_55 ) ;
V_12 = F_14 ( V_3 , V_55 -> V_32 ,
V_55 -> V_33 ,
V_55 -> V_18 ,
& V_55 -> V_61 ,
& V_55 -> V_35 ) ;
if ( ! V_12 && F_24 ( V_51 , V_55 , V_19 ) )
V_12 = - V_59 ;
F_3 ( V_55 ) ;
return V_12 ;
case V_62 :
V_19 = sizeof( * V_57 ) ;
V_57 = F_25 ( V_51 , V_19 ) ;
if ( F_26 ( V_57 ) )
return F_27 ( V_57 ) ;
V_12 = F_20 ( V_3 , V_57 -> V_37 ,
V_57 -> V_15 ,
V_57 -> V_38 ,
& V_57 -> V_35 ,
V_57 -> V_11 ,
& V_57 -> V_40 ,
V_57 -> V_41 ) ;
if ( ! V_12 && F_24 ( V_51 , V_57 , V_19 ) )
V_12 = - V_59 ;
F_3 ( V_57 ) ;
return V_12 ;
default:
return - V_63 ;
}
}
static long F_28 ( struct V_46 * V_46 , unsigned int V_50 ,
unsigned long V_64 )
{
struct V_2 * V_3 = V_46 -> V_48 ;
struct V_65 * V_66 = V_3 -> V_9 -> V_66 ;
int V_12 = - V_49 ;
F_7 ( & V_3 -> V_67 ) ;
if ( ! V_3 -> V_68 ) {
V_12 = F_29 ( V_66 ) ;
if ( ! V_12 ) {
V_12 = F_23 ( V_3 , V_50 , ( void T_4 * ) V_64 ) ;
F_30 ( V_66 ) ;
}
}
F_10 ( & V_3 -> V_67 ) ;
return V_12 ;
}
int F_31 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
int V_12 , V_69 ;
if ( ! V_9 )
return 0 ;
V_3 = F_32 ( sizeof( * V_3 ) , V_29 ) ;
if ( ! V_3 )
return - V_30 ;
V_3 -> V_14 = & V_9 -> V_66 -> V_70 ;
V_3 -> V_9 = V_9 ;
F_33 ( & V_3 -> V_67 ) ;
F_34 ( V_9 , V_3 ) ;
F_35 ( & V_3 -> V_1 ) ;
F_7 ( & V_5 ) ;
F_36 ( & V_3 -> V_71 , & V_72 ) ;
F_10 ( & V_5 ) ;
V_12 = F_37 ( V_9 ) ;
if ( V_12 )
goto V_73;
V_69 = F_38 ( & V_74 , 0 , V_75 , V_29 ) ;
if ( V_69 < 0 ) {
V_12 = V_69 ;
goto V_76;
}
V_3 -> V_77 = F_39 ( F_40 ( V_78 ) , V_69 ) ;
F_41 ( & V_3 -> V_4 , & V_79 ) ;
V_12 = F_42 ( & V_3 -> V_4 , V_3 -> V_77 , 1 ) ;
if ( V_12 )
goto V_80;
V_3 -> V_81 = F_43 ( V_82 , V_3 -> V_14 , V_3 -> V_77 ,
NULL , L_4 , V_69 ) ;
if ( F_26 ( V_3 -> V_81 ) ) {
V_12 = F_27 ( V_3 -> V_81 ) ;
goto V_83;
}
return 0 ;
V_83:
F_44 ( & V_3 -> V_4 ) ;
V_80:
F_45 ( & V_74 , V_69 ) ;
V_76:
F_46 ( V_9 ) ;
V_73:
F_7 ( & V_5 ) ;
F_47 ( & V_3 -> V_71 ) ;
F_10 ( & V_5 ) ;
F_4 ( V_3 ) ;
return V_12 ;
}
void F_48 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
if ( ! V_9 )
return;
V_3 = F_49 ( V_9 ) ;
F_50 ( V_82 , V_3 -> V_77 ) ;
F_44 ( & V_3 -> V_4 ) ;
F_45 ( & V_74 , F_51 ( V_3 -> V_77 ) ) ;
F_7 ( & V_3 -> V_67 ) ;
V_3 -> V_68 = true ;
F_10 ( & V_3 -> V_67 ) ;
F_46 ( V_3 -> V_9 ) ;
F_7 ( & V_5 ) ;
F_47 ( & V_3 -> V_71 ) ;
F_10 ( & V_5 ) ;
F_4 ( V_3 ) ;
}
int F_52 ( void )
{
int V_12 ;
V_82 = F_53 ( V_84 , L_5 ) ;
if ( F_26 ( V_82 ) )
return F_27 ( V_82 ) ;
V_12 = F_54 ( & V_78 , 0 , V_75 ,
L_5 ) ;
if ( V_12 )
goto V_85;
return 0 ;
V_85:
F_55 ( V_82 ) ;
return V_12 ;
}
void F_56 ( void )
{
F_57 ( V_78 , V_75 ) ;
F_55 ( V_82 ) ;
F_58 ( & V_74 ) ;
}
