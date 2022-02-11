static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 , struct V_2 , V_1 ) ;
F_3 ( & V_2 -> V_3 ) ;
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_2 * V_2 )
{
F_6 ( & V_2 -> V_1 , F_1 ) ;
}
static struct V_2 * F_7 ( struct V_4 * V_4 )
{
struct V_2 * V_2 ;
F_8 ( & V_5 ) ;
F_9 (fw_mgmt, &fw_mgmt_list, node) {
if ( & V_2 -> V_4 == V_4 ) {
F_10 ( & V_2 -> V_1 ) ;
goto V_6;
}
}
V_2 = NULL ;
V_6:
F_11 ( & V_5 ) ;
return V_2 ;
}
static int F_12 ( struct V_2 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_11 V_12 ;
int V_13 ;
V_13 = F_13 ( V_10 ,
V_14 , NULL , 0 ,
& V_12 , sizeof( V_12 ) ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_15 ,
L_1 , V_13 ) ;
return V_13 ;
}
V_8 -> V_16 = F_15 ( V_12 . V_16 ) ;
V_8 -> V_17 = F_15 ( V_12 . V_17 ) ;
strncpy ( V_8 -> V_18 , V_12 . V_18 ,
V_19 ) ;
if ( V_8 -> V_18 [ V_19 - 1 ] != '\0' ) {
F_14 ( V_2 -> V_15 ,
L_2 ) ;
V_8 -> V_18 [ V_19 - 1 ] = '\0' ;
}
return 0 ;
}
static int F_16 ( struct V_2 * V_2 ,
T_1 V_20 , const char * V_21 )
{
struct V_22 V_23 ;
int V_13 ;
if ( V_20 != V_24 &&
V_20 != V_25 ) {
F_14 ( V_2 -> V_15 ,
L_3 , V_20 ) ;
return - V_26 ;
}
V_23 . V_20 = V_20 ;
strncpy ( V_23 . V_18 , V_21 , V_19 ) ;
if ( V_23 . V_18 [ V_19 - 1 ] != '\0' ) {
F_14 ( V_2 -> V_15 , L_4 ) ;
return - V_26 ;
}
V_13 = F_17 ( & V_2 -> V_3 , 1 , 256 , V_27 ) ;
if ( V_13 < 0 ) {
F_14 ( V_2 -> V_15 , L_5 ,
V_13 ) ;
return V_13 ;
}
V_2 -> V_28 = V_13 ;
V_2 -> V_29 = false ;
V_23 . V_30 = V_13 ;
V_13 = F_13 ( V_2 -> V_10 ,
V_31 , & V_23 ,
sizeof( V_23 ) , NULL , 0 ) ;
if ( V_13 ) {
F_18 ( & V_2 -> V_3 ,
V_2 -> V_28 ) ;
V_2 -> V_28 = 0 ;
F_14 ( V_2 -> V_15 ,
L_6 ,
V_13 ) ;
return V_13 ;
}
return 0 ;
}
static int F_19 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = V_33 -> V_10 ;
struct V_2 * V_2 = F_20 ( V_10 ) ;
struct V_34 * V_23 ;
if ( ! V_2 -> V_28 ) {
F_14 ( V_2 -> V_15 ,
L_7 ) ;
return - V_35 ;
}
if ( V_33 -> V_23 -> V_36 != sizeof( * V_23 ) ) {
F_14 ( V_2 -> V_15 , L_8 ,
V_33 -> V_23 -> V_36 , sizeof( * V_23 ) ) ;
return - V_26 ;
}
V_23 = V_33 -> V_23 -> V_37 ;
if ( V_23 -> V_30 != V_2 -> V_28 ) {
F_14 ( V_2 -> V_15 , L_9 ,
V_2 -> V_28 , V_23 -> V_30 ) ;
return - V_35 ;
}
F_18 ( & V_2 -> V_3 , V_2 -> V_28 ) ;
V_2 -> V_28 = 0 ;
V_2 -> V_38 = V_23 -> V_39 ;
V_2 -> V_40 = F_15 ( V_23 -> V_16 ) ;
V_2 -> V_41 = F_15 ( V_23 -> V_17 ) ;
if ( V_2 -> V_38 == V_42 )
F_14 ( V_2 -> V_15 ,
L_10 ,
V_2 -> V_38 ) ;
else if ( V_2 -> V_38 == V_43 )
F_14 ( V_2 -> V_15 ,
L_11 ,
V_2 -> V_38 ) ;
else
V_2 -> V_29 = true ;
F_21 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_2 ,
struct V_45 * V_8 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_46 V_23 ;
struct V_47 V_12 ;
int V_13 ;
strncpy ( V_23 . V_18 , V_8 -> V_18 ,
V_19 ) ;
if ( V_23 . V_18 [ V_19 - 1 ] != '\0' ) {
F_14 ( V_2 -> V_15 , L_12 ) ;
return - V_26 ;
}
V_13 = F_13 ( V_10 ,
V_48 , & V_23 ,
sizeof( V_23 ) , & V_12 , sizeof( V_12 ) ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_15 , L_13 ,
V_8 -> V_18 , V_13 ) ;
return V_13 ;
}
V_8 -> V_39 = V_12 . V_39 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
switch ( V_8 -> V_39 ) {
case V_49 :
V_8 -> V_16 = F_15 ( V_12 . V_16 ) ;
V_8 -> V_17 = F_15 ( V_12 . V_17 ) ;
break;
case V_50 :
case V_51 :
break;
case V_52 :
F_14 ( V_2 -> V_15 ,
L_14 ,
V_8 -> V_18 ) ;
break;
default:
F_14 ( V_2 -> V_15 , L_15 ,
V_8 -> V_39 ) ;
}
return 0 ;
}
static int F_23 ( struct V_2 * V_2 ,
char * V_21 )
{
struct V_53 V_23 ;
int V_13 ;
strncpy ( V_23 . V_18 , V_21 , V_19 ) ;
if ( V_23 . V_18 [ V_19 - 1 ] != '\0' ) {
F_14 ( V_2 -> V_15 , L_16 ) ;
return - V_26 ;
}
V_13 = F_17 ( & V_2 -> V_3 , 1 , 256 , V_27 ) ;
if ( V_13 < 0 ) {
F_14 ( V_2 -> V_15 , L_5 ,
V_13 ) ;
return V_13 ;
}
V_2 -> V_54 = V_13 ;
V_23 . V_30 = V_13 ;
V_13 = F_13 ( V_2 -> V_10 ,
V_55 , & V_23 ,
sizeof( V_23 ) , NULL , 0 ) ;
if ( V_13 ) {
F_18 ( & V_2 -> V_3 ,
V_2 -> V_54 ) ;
V_2 -> V_54 = 0 ;
F_14 ( V_2 -> V_15 ,
L_17 , V_21 ,
V_13 ) ;
return V_13 ;
}
return 0 ;
}
static int F_24 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = V_33 -> V_10 ;
struct V_2 * V_2 = F_20 ( V_10 ) ;
struct V_56 * V_23 ;
if ( ! V_2 -> V_54 ) {
F_14 ( V_2 -> V_15 , L_18 ) ;
return - V_35 ;
}
if ( V_33 -> V_23 -> V_36 != sizeof( * V_23 ) ) {
F_14 ( V_2 -> V_15 , L_19 ,
V_33 -> V_23 -> V_36 , sizeof( * V_23 ) ) ;
return - V_26 ;
}
V_23 = V_33 -> V_23 -> V_37 ;
if ( V_23 -> V_30 != V_2 -> V_54 ) {
F_14 ( V_2 -> V_15 , L_20 ,
V_2 -> V_54 , V_23 -> V_30 ) ;
return - V_35 ;
}
F_18 ( & V_2 -> V_3 , V_2 -> V_54 ) ;
V_2 -> V_54 = 0 ;
V_2 -> V_57 = V_23 -> V_39 ;
if ( ( V_2 -> V_57 != V_58 ) &&
( V_2 -> V_57 != V_59 ) )
F_14 ( V_2 -> V_15 ,
L_21 ,
V_2 -> V_57 ) ;
F_21 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int F_25 ( struct V_60 * V_60 , struct V_61 * V_61 )
{
struct V_2 * V_2 = F_7 ( V_60 -> V_62 ) ;
if ( V_2 ) {
V_61 -> V_63 = V_2 ;
return 0 ;
}
return - V_35 ;
}
static int F_26 ( struct V_60 * V_60 , struct V_61 * V_61 )
{
struct V_2 * V_2 = V_61 -> V_63 ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_2 , unsigned int V_64 ,
void T_2 * V_65 )
{
struct V_7 V_66 ;
struct V_45 V_67 ;
struct V_68 V_69 ;
struct V_70 V_71 ;
unsigned int V_72 ;
int V_13 ;
if ( V_2 -> V_73 )
return - V_74 ;
switch ( V_64 ) {
case V_75 :
V_13 = F_12 ( V_2 ,
& V_66 ) ;
if ( V_13 )
return V_13 ;
if ( F_28 ( V_65 , & V_66 , sizeof( V_66 ) ) )
return - V_76 ;
return 0 ;
case V_77 :
if ( F_29 ( & V_67 , V_65 ,
sizeof( V_67 ) ) )
return - V_76 ;
V_13 = F_22 ( V_2 ,
& V_67 ) ;
if ( V_13 )
return V_13 ;
if ( F_28 ( V_65 , & V_67 ,
sizeof( V_67 ) ) )
return - V_76 ;
return 0 ;
case V_78 :
if ( F_29 ( & V_69 , V_65 , sizeof( V_69 ) ) )
return - V_76 ;
V_13 = F_16 ( V_2 ,
V_69 . V_20 , V_69 . V_18 ) ;
if ( V_13 )
return V_13 ;
if ( ! F_30 ( & V_2 -> V_44 ,
V_2 -> V_79 ) ) {
F_14 ( V_2 -> V_15 , L_22 ) ;
return - V_80 ;
}
V_69 . V_39 = V_2 -> V_38 ;
V_69 . V_16 = V_2 -> V_40 ;
V_69 . V_17 = V_2 -> V_41 ;
if ( F_28 ( V_65 , & V_69 , sizeof( V_69 ) ) )
return - V_76 ;
return 0 ;
case V_81 :
if ( F_29 ( & V_71 , V_65 ,
sizeof( V_71 ) ) )
return - V_76 ;
V_13 = F_23 ( V_2 ,
V_71 . V_18 ) ;
if ( V_13 )
return V_13 ;
if ( ! F_30 ( & V_2 -> V_44 ,
V_2 -> V_79 ) ) {
F_14 ( V_2 -> V_15 , L_23 ) ;
return - V_80 ;
}
V_71 . V_39 = V_2 -> V_57 ;
if ( F_28 ( V_65 , & V_71 , sizeof( V_71 ) ) )
return - V_76 ;
return 0 ;
case V_82 :
if ( F_31 ( V_72 , ( unsigned int T_2 * ) V_65 ) )
return - V_76 ;
if ( ! V_72 ) {
F_14 ( V_2 -> V_15 , L_24 ) ;
return - V_26 ;
}
V_2 -> V_79 = F_32 ( V_72 ) ;
return 0 ;
case V_83 :
if ( ! V_2 -> V_29 ) {
F_14 ( V_2 -> V_15 ,
L_25 ) ;
return - V_84 ;
}
V_2 -> V_73 = true ;
V_13 = F_33 ( V_2 -> V_10 -> V_85 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_15 , L_26 ,
V_13 ) ;
V_2 -> V_73 = false ;
return V_13 ;
}
return 0 ;
default:
return - V_86 ;
}
}
static long F_34 ( struct V_61 * V_61 , unsigned int V_64 ,
unsigned long V_87 )
{
struct V_2 * V_2 = V_61 -> V_63 ;
struct V_88 * V_89 = V_2 -> V_10 -> V_89 ;
int V_13 = - V_35 ;
F_8 ( & V_2 -> V_90 ) ;
if ( ! V_2 -> V_91 ) {
V_13 = F_35 ( V_89 ) ;
if ( ! V_13 ) {
V_13 = F_27 ( V_2 , V_64 , ( void T_2 * ) V_87 ) ;
F_36 ( V_89 ) ;
}
}
F_11 ( & V_2 -> V_90 ) ;
return V_13 ;
}
int F_37 ( struct V_32 * V_33 )
{
T_1 type = V_33 -> type ;
switch ( type ) {
case V_92 :
return F_19 ( V_33 ) ;
case V_93 :
return F_24 ( V_33 ) ;
default:
F_14 ( & V_33 -> V_10 -> V_89 -> V_94 ,
L_27 , type ) ;
return - V_26 ;
}
}
int F_38 ( struct V_9 * V_10 )
{
struct V_2 * V_2 ;
int V_13 , V_17 ;
if ( ! V_10 )
return 0 ;
V_2 = F_39 ( sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return - V_95 ;
V_2 -> V_15 = & V_10 -> V_89 -> V_94 ;
V_2 -> V_79 = F_32 ( V_96 ) ;
V_2 -> V_10 = V_10 ;
F_40 ( V_10 , V_2 ) ;
F_41 ( & V_2 -> V_44 ) ;
F_42 ( & V_2 -> V_3 ) ;
F_43 ( & V_2 -> V_90 ) ;
F_44 ( & V_2 -> V_1 ) ;
F_8 ( & V_5 ) ;
F_45 ( & V_2 -> V_97 , & V_98 ) ;
F_11 ( & V_5 ) ;
V_13 = F_46 ( V_10 ) ;
if ( V_13 )
goto V_99;
V_17 = F_17 ( & V_100 , 0 , V_101 , V_27 ) ;
if ( V_17 < 0 ) {
V_13 = V_17 ;
goto V_102;
}
V_2 -> V_103 = F_47 ( F_48 ( V_104 ) , V_17 ) ;
F_49 ( & V_2 -> V_4 , & V_105 ) ;
V_13 = F_50 ( & V_2 -> V_4 , V_2 -> V_103 , 1 ) ;
if ( V_13 )
goto V_106;
V_2 -> V_107 = F_51 ( V_108 , V_2 -> V_15 ,
V_2 -> V_103 , NULL ,
L_28 , V_17 ) ;
if ( F_52 ( V_2 -> V_107 ) ) {
V_13 = F_53 ( V_2 -> V_107 ) ;
goto V_109;
}
return 0 ;
V_109:
F_54 ( & V_2 -> V_4 ) ;
V_106:
F_18 ( & V_100 , V_17 ) ;
V_102:
F_55 ( V_10 ) ;
V_99:
F_8 ( & V_5 ) ;
F_56 ( & V_2 -> V_97 ) ;
F_11 ( & V_5 ) ;
F_5 ( V_2 ) ;
return V_13 ;
}
void F_57 ( struct V_9 * V_10 )
{
struct V_2 * V_2 ;
if ( ! V_10 )
return;
V_2 = F_20 ( V_10 ) ;
F_58 ( V_108 , V_2 -> V_103 ) ;
F_54 ( & V_2 -> V_4 ) ;
F_18 ( & V_100 , F_59 ( V_2 -> V_103 ) ) ;
F_8 ( & V_2 -> V_90 ) ;
V_2 -> V_91 = true ;
F_11 ( & V_2 -> V_90 ) ;
F_55 ( V_2 -> V_10 ) ;
F_8 ( & V_5 ) ;
F_56 ( & V_2 -> V_97 ) ;
F_11 ( & V_5 ) ;
F_5 ( V_2 ) ;
}
int F_60 ( void )
{
int V_13 ;
V_108 = F_61 ( V_110 , L_29 ) ;
if ( F_52 ( V_108 ) )
return F_53 ( V_108 ) ;
V_13 = F_62 ( & V_104 , 0 , V_101 ,
L_29 ) ;
if ( V_13 )
goto V_111;
return 0 ;
V_111:
F_63 ( V_108 ) ;
return V_13 ;
}
void F_64 ( void )
{
F_65 ( V_104 , V_101 ) ;
F_63 ( V_108 ) ;
F_3 ( & V_100 ) ;
}
