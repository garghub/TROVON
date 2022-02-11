static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 T_2 * V_8 = V_5 -> V_9 . V_8 ;
T_1 V_10 ;
if ( ! ( V_3 & V_11 ) )
return V_12 ;
V_3 &= V_13 ;
if ( V_3 > 255 )
return V_12 ;
V_10 = F_2 ( V_2 ) ;
F_3 ( V_2 , V_3 * V_10 / 255 ) ;
F_4 ( ( V_3 * 0x64 ) / 0xff | V_14 , & V_8 -> V_15 ) ;
return 0 ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_16 )
{
return 0 ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_17 & V_18 ) {
T_1 V_19 = F_7 ( V_20 ) ;
T_1 V_21 = V_17 & V_22 ;
V_19 &= V_23 ;
V_21 = V_21 >> 9 ;
}
return 0 ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_1 V_24 )
{
if ( ! ( V_24 & V_25 ) )
return V_26 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 T_2 * V_8 = V_5 -> V_9 . V_8 ;
T_1 V_27 = 0 ;
T_1 V_28 ;
if ( ! V_8 )
return;
V_28 = F_10 ( & V_8 -> V_29 ) & V_30 ;
if ( ! V_28 ) {
F_11 ( L_1 ) ;
return;
}
if ( V_28 & V_31 )
V_27 |= F_5 ( V_2 , F_10 ( & V_8 -> V_16 ) ) ;
if ( V_28 & V_32 )
V_27 |= F_1 ( V_2 , F_10 ( & V_8 -> V_3 ) ) ;
if ( V_28 & V_33 )
V_27 |= F_8 ( V_2 , F_10 ( & V_8 -> V_24 ) ) ;
if ( V_28 & V_34 )
V_27 |= F_6 ( V_2 , F_10 ( & V_8 -> V_17 ) ) ;
F_4 ( V_27 , & V_8 -> V_29 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 T_2 * V_8 = V_5 -> V_9 . V_8 ;
T_1 V_27 = 0 ;
T_1 V_28 ;
if ( ! V_8 )
return;
V_28 = F_10 ( & V_8 -> V_29 ) & V_30 ;
if ( ! V_28 ) {
F_11 ( L_1 ) ;
return;
}
if ( V_28 & V_31 ) {
F_11 ( L_2 ) ;
V_27 |= V_35 ;
}
if ( V_28 & V_32 )
V_27 |= F_1 ( V_2 , F_10 ( & V_8 -> V_3 ) ) ;
if ( V_28 & V_33 ) {
F_11 ( L_3 ) ;
V_27 |= V_26 ;
}
if ( V_28 & V_34 ) {
F_11 ( L_4 ) ;
V_27 |= V_36 ;
}
F_4 ( V_27 , & V_8 -> V_29 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 T_2 * V_8 = V_5 -> V_9 . V_8 ;
if ( V_8 ) {
if ( F_14 ( V_2 ) )
F_15 ( V_2 ) ;
F_4 ( V_37 | V_38 | V_39 |
V_40 ,
& V_8 -> V_41 ) ;
F_4 ( 1 , & V_8 -> V_42 ) ;
}
}
static int F_16 ( struct V_43 * V_44 ,
unsigned long V_45 , void * V_46 )
{
struct V_47 T_2 * V_48 ;
struct V_49 * V_50 = V_46 ;
int V_51 = V_52 ;
if ( strcmp ( V_50 -> V_53 , V_54 ) != 0 )
return V_55 ;
if ( ! V_56 )
return V_55 ;
V_48 = V_56 -> V_48 ;
if ( V_50 -> type == 0x80 &&
( F_10 ( & V_48 -> V_57 ) & 1 ) == 0 )
V_51 = V_58 ;
F_4 ( 0 , & V_48 -> V_59 ) ;
return V_51 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_60 * V_9 = & V_5 -> V_9 ;
struct V_61 * V_62 ;
T_3 V_63 ;
struct V_64 * V_65 , * V_66 , * V_67 = NULL ;
unsigned long long V_68 ;
T_4 V_69 ;
T_1 V_70 ;
int V_71 = 0 ;
V_63 = F_18 ( & V_2 -> V_72 -> V_2 ) ;
if ( ! V_63 || F_19 ( F_20 ( V_63 , & V_65 ) ) )
return;
if ( F_21 ( V_65 ) )
V_67 = V_65 ;
else {
F_22 (acpi_cdev, &acpi_dev->children, node) {
if ( F_21 ( V_66 ) ) {
V_67 = V_66 ;
break;
}
}
}
if ( ! V_67 ) {
F_23 ( L_5 ) ;
return;
}
F_22 (acpi_cdev, &acpi_video_bus->children, node) {
if ( V_71 >= 8 ) {
F_24 ( V_73 , & V_2 -> V_72 -> V_2 ,
L_6 ) ;
return;
}
V_69 =
F_25 ( V_66 -> V_63 , L_7 ,
NULL , & V_68 ) ;
if ( F_26 ( V_69 ) ) {
if ( ! V_68 )
goto V_74;
F_4 ( ( T_1 ) ( V_68 & 0x0f0f ) ,
& V_9 -> V_48 -> V_75 [ V_71 ] ) ;
V_71 ++ ;
}
}
V_76:
if ( V_71 < 8 )
F_4 ( 0 , & V_9 -> V_48 -> V_75 [ V_71 ] ) ;
return;
V_74:
V_71 = 0 ;
F_22 (connector, &dev->mode_config.connector_list, head) {
int V_77 = V_78 ;
if ( V_71 >= 8 ) {
F_24 ( V_73 , & V_2 -> V_72 -> V_2 ,
L_6 ) ;
return;
}
switch ( V_62 -> V_79 ) {
case V_80 :
case V_81 :
V_77 = V_82 ;
break;
case V_83 :
case V_84 :
case V_85 :
case V_86 :
V_77 = V_87 ;
break;
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
V_77 = V_93 ;
break;
case V_94 :
V_77 = V_95 ;
break;
}
V_70 = F_10 ( & V_9 -> V_48 -> V_75 [ V_71 ] ) ;
F_4 ( V_70 | ( 1 << 31 ) | V_77 | V_71 ,
& V_9 -> V_48 -> V_75 [ V_71 ] ) ;
V_71 ++ ;
}
goto V_76;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_60 * V_9 = & V_5 -> V_9 ;
if ( ! V_9 -> V_96 )
return;
if ( V_9 -> V_48 ) {
if ( F_28 ( V_2 , V_97 ) )
F_17 ( V_2 ) ;
F_4 ( 0 , & V_9 -> V_48 -> V_59 ) ;
F_4 ( 1 , & V_9 -> V_48 -> V_98 ) ;
V_56 = V_9 ;
F_29 ( & V_99 ) ;
}
if ( V_9 -> V_8 )
F_13 ( V_2 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_60 * V_9 = & V_5 -> V_9 ;
if ( ! V_9 -> V_96 )
return;
if ( V_9 -> V_48 ) {
F_4 ( 0 , & V_9 -> V_48 -> V_98 ) ;
V_56 = NULL ;
F_31 ( & V_99 ) ;
}
F_32 ( V_9 -> V_96 ) ;
V_9 -> V_96 = NULL ;
V_9 -> V_48 = NULL ;
V_9 -> V_100 = NULL ;
V_9 -> V_8 = NULL ;
V_9 -> V_101 = NULL ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_60 * V_9 = & V_5 -> V_9 ;
void T_2 * V_102 ;
T_1 V_103 , V_104 ;
char V_105 [ sizeof( V_106 ) ] ;
int V_107 = 0 ;
F_34 ( V_2 -> V_72 , V_108 , & V_103 ) ;
F_11 ( L_8 , V_103 ) ;
if ( V_103 == 0 ) {
F_11 ( L_9 ) ;
return - V_109 ;
}
V_102 = F_35 ( V_103 , V_110 ) ;
if ( ! V_102 )
return - V_111 ;
F_36 ( V_105 , V_102 , sizeof( V_105 ) ) ;
if ( memcmp ( V_105 , V_106 , 16 ) ) {
F_11 ( L_10 ) ;
V_107 = - V_112 ;
goto V_113;
}
V_9 -> V_96 = V_102 ;
V_9 -> V_101 = V_102 + V_114 ;
V_9 -> V_115 = V_102 + V_116 ;
V_104 = F_10 ( & V_9 -> V_96 -> V_104 ) ;
if ( V_104 & V_117 ) {
F_11 ( L_11 ) ;
V_9 -> V_48 = V_102 + V_118 ;
}
if ( V_104 & V_119 ) {
F_11 ( L_12 ) ;
V_9 -> V_100 = V_102 + V_120 ;
}
if ( V_104 & V_121 ) {
F_11 ( L_13 ) ;
V_9 -> V_8 = V_102 + V_122 ;
}
return 0 ;
V_113:
F_32 ( V_102 ) ;
return V_107 ;
}
