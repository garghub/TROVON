static T_1 F_1 ( void * V_1 , T_2 V_2 ,
T_3 V_3 , void * V_4 ,
T_2 V_5 , T_3 V_6 )
{
T_2 V_7 = V_3 - V_6 ;
T_2 V_8 = V_5 ;
T_2 V_9 = V_3 + V_2 - V_5 ;
T_2 V_10 = F_2 ( V_8 , V_9 ) ;
T_2 V_11 = V_10 - V_7 ;
if ( V_3 < 0 || V_6 < 0 )
return - V_12 ;
if ( V_8 <= V_7 )
return 0 ;
memcpy ( V_1 , V_4 + V_7 , V_11 ) ;
return V_11 ;
}
static unsigned long F_3 ( unsigned long V_13 ,
unsigned long V_14 ,
unsigned long V_15 )
{
F_4 ( L_1 ,
V_13 ,
V_14 ,
V_15 ) ;
F_5 ( ! F_6 ( V_13 , 4096 ) ) ;
return F_7 ( V_16 ,
V_13 ,
V_14 ,
V_15 ) ;
}
static unsigned long F_8 ( char V_17 [] ,
T_4 V_14 , T_5 V_15 )
{
return F_3 ( F_9 ( V_17 ) ,
V_14 , V_15 ) ;
}
static T_1 F_10 ( struct V_18 * V_19 , struct V_20 * V_21 ,
struct V_22 * V_23 , char * V_24 ,
T_3 V_25 , T_2 V_26 )
{
unsigned long V_27 ;
T_1 V_28 = 0 ;
T_2 V_29 = 0 , V_30 = 0 , V_31 = 0 ;
T_3 V_32 = 0 ;
T_6 V_33 = 0 ;
void * V_17 = F_11 ( V_34 , V_35 ) ;
struct V_36 * V_37 = V_17 ;
if ( ! V_17 )
return - V_38 ;
V_27 = F_8 ( V_17 , 0 , 0 ) ;
if ( V_27 ) {
V_28 = - V_39 ;
goto V_40;
}
V_33 = F_12 ( V_37 -> V_14 ) ;
V_30 = F_13 ( V_37 -> V_41 ) ;
V_29 = V_30 * 4096 ;
V_32 = V_25 / 4096 ;
V_31 = V_26 / 4096 ;
if ( V_32 >= V_30 )
goto V_40;
if ( V_32 != 0 ) {
V_27 = F_8 ( V_17 , V_33 ,
V_32 ) ;
if ( V_27 ) {
V_28 = - V_39 ;
goto V_40;
}
}
V_28 = F_1 ( V_24 , V_26 , V_25 ,
V_17 , 4096 , V_32 * 4096 ) ;
V_40:
if ( V_27 )
F_14 ( L_2
L_3 ,
V_33 , V_32 , V_27 ) ;
F_15 ( V_34 , V_17 ) ;
F_4 ( L_4 ,
V_25 , V_32 , V_26 , V_31 , V_29 ,
V_30 , V_28 ) ;
return V_28 ;
}
static bool F_16 ( int V_42 )
{
return V_42 == V_43 ||
V_42 == V_44 ;
}
static unsigned long F_17 ( T_7 V_42 , T_5 V_25 , T_8 V_45 ,
T_8 V_46 , T_4 * V_47 ,
bool V_48 )
{
unsigned long V_28 ;
struct V_49 {
struct V_50 V_24 ;
struct V_51 V_52 ;
} V_53 V_54 ( 4096 ) V_55 = {
. V_24 = {
. V_56 = V_57 ,
. V_58 = 1 ,
} ,
. V_52 = {
. V_59 = V_42 ,
. V_60 = F_18 ( 8 ) ,
. V_61 = F_19 ( V_25 ) ,
. V_62 = F_18 ( V_46 ) ,
. V_63 = F_18 ( 1 ) ,
. V_64 = F_18 ( V_45 ) ,
. V_65 = F_18 ( 1 ) ,
}
} ;
struct V_66 {
struct V_67 V_24 ;
struct V_68 V_47 ;
struct V_69 V_70 ;
T_9 V_71 ;
} V_53 V_54 ( 4096 ) V_72 = {} ;
V_28 = F_7 ( V_73 ,
F_9 ( & V_55 ) , sizeof( V_55 ) ,
F_9 ( & V_72 ) , sizeof( V_72 ) ) ;
if ( V_28 ) {
if ( V_48 )
F_20 ( L_5 ,
V_42 , V_25 , V_45 , V_46 ,
V_28 , V_28 ,
V_72 . V_24 . V_74 ,
V_72 . V_24 . V_75 ) ;
return V_28 ;
}
* V_47 = F_12 ( V_72 . V_71 ) ;
return V_28 ;
}
static unsigned long F_21 ( struct V_76 * V_77 , T_4 * V_47 ,
bool V_48 )
{
return F_17 ( F_22 ( V_77 ) ,
F_23 ( V_77 ) ,
F_24 ( V_77 ) ,
F_25 ( V_77 ) ,
V_47 ,
V_48 ) ;
}
static int F_26 ( struct V_76 * V_77 )
{
struct V_78 V_79 ;
unsigned V_42 ;
unsigned long V_27 ;
T_4 V_80 ;
if ( V_77 -> V_81 . type != V_77 -> V_82 -> type )
return - V_83 ;
if ( F_27 ( V_77 ) ||
F_28 ( V_77 ) ||
F_29 ( V_77 ) ) {
F_4 ( L_6 ,
V_77 -> V_81 . V_84 ,
F_27 ( V_77 ) ,
V_77 -> V_81 . V_85 ,
F_28 ( V_77 ) ,
V_77 -> V_81 . V_86 ,
F_29 ( V_77 ) ) ;
return - V_12 ;
}
if ( V_77 -> V_81 . V_87 ||
V_77 -> V_81 . V_88 ||
V_77 -> V_81 . V_89 ||
V_77 -> V_81 . V_90 ||
V_77 -> V_81 . V_91 ||
V_77 -> V_81 . V_92 )
return - V_12 ;
if ( F_30 ( V_77 ) )
return - V_93 ;
if ( F_23 ( V_77 ) % 8 ) {
F_4 ( L_7 ) ;
return - V_12 ;
}
V_42 = F_22 ( V_77 ) ;
if ( V_42 > 6 ) {
F_4 ( L_8 , V_42 ) ;
return - V_12 ;
}
V_27 = F_31 ( & V_79 ) ;
if ( V_27 ) {
F_4 ( L_9 , V_27 ) ;
return - V_39 ;
}
if ( ! V_79 . V_94 && ( F_16 ( V_42 ) ||
( F_25 ( V_77 ) != F_32 () ) ) ) {
F_4 ( L_10 ,
F_16 ( V_42 ) ,
F_25 ( V_77 ) ) ;
return - V_95 ;
}
if ( F_21 ( V_77 , & V_80 , false ) ) {
F_4 ( L_11 ) ;
return - V_39 ;
}
return 0 ;
}
static T_4 F_33 ( struct V_76 * V_77 )
{
unsigned long V_28 ;
T_4 V_80 ;
V_28 = F_21 ( V_77 , & V_80 , true ) ;
if ( V_28 )
return 0 ;
return V_80 ;
}
static void F_34 ( struct V_76 * V_77 )
{
T_10 V_96 ;
T_4 V_97 ;
V_97 = F_33 ( V_77 ) ;
V_96 = F_35 ( & V_77 -> V_98 . V_99 , V_97 ) ;
F_36 ( V_97 - V_96 , & V_77 -> V_26 ) ;
}
static void F_37 ( struct V_76 * V_77 , int V_100 )
{
if ( V_100 & V_101 )
F_38 ( & V_77 -> V_98 . V_99 , F_33 ( V_77 ) ) ;
}
static void F_39 ( struct V_76 * V_77 , int V_100 )
{
F_34 ( V_77 ) ;
}
static int F_40 ( struct V_76 * V_77 , int V_100 )
{
if ( V_100 & V_102 )
F_37 ( V_77 , V_100 ) ;
return 0 ;
}
static int F_41 ( struct V_76 * V_77 )
{
return 0 ;
}
static int F_42 ( void )
{
int V_103 ;
unsigned long V_27 ;
struct V_78 V_79 ;
if ( ! F_43 ( V_104 ) ) {
F_44 ( L_12 ) ;
return - V_105 ;
}
V_27 = F_31 ( & V_79 ) ;
if ( V_27 ) {
F_44 ( L_13 ,
V_27 ) ;
return - V_105 ;
}
V_34 = F_45 ( L_14 , 4096 , 4096 , 0 , NULL ) ;
if ( ! V_34 )
return - V_38 ;
V_106 . V_107 |= V_108 ;
V_103 = F_46 ( & V_106 , V_106 . V_109 , - 1 ) ;
if ( V_103 )
return V_103 ;
return 0 ;
}
