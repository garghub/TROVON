static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 . V_8 ;
T_1 V_10 ;
if ( ! ( V_3 & V_11 ) )
return V_12 ;
V_3 &= V_13 ;
if ( V_3 > 255 )
return V_12 ;
V_10 = F_2 ( V_2 ) ;
F_3 ( V_2 , V_3 * V_10 / 255 ) ;
V_8 -> V_14 = ( V_3 * 0x64 ) / 0xff | V_15 ;
return 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_1 V_16 )
{
return 0 ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_17 & V_18 ) {
T_1 V_19 = F_6 ( V_20 ) ;
T_1 V_21 = V_17 & V_22 ;
V_19 &= V_23 ;
V_21 = V_21 >> 9 ;
}
return 0 ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_24 )
{
if ( ! ( V_24 & V_25 ) )
return V_26 ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 . V_8 ;
T_1 V_27 = 0 ;
T_1 V_28 ;
if ( ! V_8 )
return;
V_28 = V_8 -> V_29 & V_30 ;
if ( ! V_28 ) {
F_9 ( L_1 ) ;
return;
}
if ( V_28 & V_31 )
V_27 |= F_4 ( V_2 , V_8 -> V_16 ) ;
if ( V_28 & V_32 )
V_27 |= F_1 ( V_2 , V_8 -> V_3 ) ;
if ( V_28 & V_33 )
V_27 |= F_7 ( V_2 , V_8 -> V_24 ) ;
if ( V_28 & V_34 )
V_27 |= F_5 ( V_2 , V_8 -> V_17 ) ;
V_8 -> V_29 = V_27 ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 . V_8 ;
T_1 V_27 = 0 ;
T_1 V_28 ;
if ( ! V_8 )
return;
V_28 = V_8 -> V_29 & V_30 ;
if ( ! V_28 ) {
F_9 ( L_1 ) ;
return;
}
if ( V_28 & V_31 ) {
F_9 ( L_2 ) ;
V_27 |= V_35 ;
}
if ( V_28 & V_32 )
V_27 |= F_1 ( V_2 , V_8 -> V_3 ) ;
if ( V_28 & V_33 ) {
F_9 ( L_3 ) ;
V_27 |= V_26 ;
}
if ( V_28 & V_34 ) {
F_9 ( L_4 ) ;
V_27 |= V_36 ;
}
V_8 -> V_29 = V_27 ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 . V_8 ;
if ( V_8 ) {
if ( F_12 ( V_2 ) )
F_13 ( V_2 ) ;
V_8 -> V_37 = V_38 | V_39 | V_40 |
V_41 ;
V_8 -> V_42 = 1 ;
}
}
static int F_14 ( struct V_43 * V_44 ,
unsigned long V_45 , void * V_46 )
{
struct V_47 * V_48 ;
if ( ! V_49 )
return V_50 ;
V_48 = V_49 -> V_48 ;
V_48 -> V_51 = 0 ;
return V_52 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_53 * V_9 = & V_5 -> V_9 ;
struct V_54 * V_55 ;
T_2 V_56 ;
struct V_57 * V_58 , * V_59 , * V_60 = NULL ;
unsigned long long V_61 ;
T_3 V_62 ;
int V_63 = 0 ;
V_56 = F_16 ( & V_2 -> V_64 -> V_2 ) ;
if ( ! V_56 || F_17 ( F_18 ( V_56 , & V_58 ) ) )
return;
if ( F_19 ( V_58 ) )
V_60 = V_58 ;
else {
F_20 (acpi_cdev, &acpi_dev->children, node) {
if ( F_19 ( V_59 ) ) {
V_60 = V_59 ;
break;
}
}
}
if ( ! V_60 ) {
F_21 ( V_65 L_5 ) ;
return;
}
F_20 (acpi_cdev, &acpi_video_bus->children, node) {
if ( V_63 >= 8 ) {
F_22 ( V_66 , & V_2 -> V_64 -> V_2 ,
L_6 ) ;
return;
}
V_62 =
F_23 ( V_59 -> V_56 , L_7 ,
NULL , & V_61 ) ;
if ( F_24 ( V_62 ) ) {
if ( ! V_61 )
goto V_67;
V_9 -> V_48 -> V_68 [ V_63 ] = ( T_1 ) ( V_61 & 0x0f0f ) ;
V_63 ++ ;
}
}
V_69:
if ( V_63 < 8 )
V_9 -> V_48 -> V_68 [ V_63 ] = 0 ;
return;
V_67:
V_63 = 0 ;
F_20 (connector, &dev->mode_config.connector_list, head) {
int V_70 = V_71 ;
if ( V_63 >= 8 ) {
F_22 ( V_66 , & V_2 -> V_64 -> V_2 ,
L_6 ) ;
return;
}
switch ( V_55 -> V_72 ) {
case V_73 :
case V_74 :
V_70 = V_75 ;
break;
case V_76 :
case V_77 :
case V_78 :
case V_79 :
V_70 = V_80 ;
break;
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
V_70 = V_86 ;
break;
case V_87 :
V_70 = V_88 ;
break;
}
V_9 -> V_48 -> V_68 [ V_63 ] |= ( 1 << 31 ) | V_70 | V_63 ;
V_63 ++ ;
}
goto V_69;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_53 * V_9 = & V_5 -> V_9 ;
if ( ! V_9 -> V_89 )
return;
if ( V_9 -> V_48 ) {
if ( F_26 ( V_2 , V_90 ) )
F_15 ( V_2 ) ;
V_9 -> V_48 -> V_51 = 0 ;
V_9 -> V_48 -> V_91 = 1 ;
V_49 = V_9 ;
F_27 ( & V_92 ) ;
}
if ( V_9 -> V_8 )
F_11 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_53 * V_9 = & V_5 -> V_9 ;
if ( ! V_9 -> V_89 )
return;
if ( V_9 -> V_48 ) {
V_9 -> V_48 -> V_91 = 0 ;
V_49 = NULL ;
F_29 ( & V_92 ) ;
}
F_30 ( V_9 -> V_89 ) ;
V_9 -> V_89 = NULL ;
V_9 -> V_48 = NULL ;
V_9 -> V_93 = NULL ;
V_9 -> V_8 = NULL ;
V_9 -> V_94 = NULL ;
}
int F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_53 * V_9 = & V_5 -> V_9 ;
void * V_95 ;
T_1 V_96 , V_97 ;
int V_98 = 0 ;
F_32 ( V_2 -> V_64 , V_99 , & V_96 ) ;
F_9 ( L_8 , V_96 ) ;
if ( V_96 == 0 ) {
F_9 ( L_9 ) ;
return - V_100 ;
}
V_95 = F_33 ( V_96 , V_101 ) ;
if ( ! V_95 )
return - V_102 ;
if ( memcmp ( V_95 , V_103 , 16 ) ) {
F_9 ( L_10 ) ;
V_98 = - V_104 ;
goto V_105;
}
V_9 -> V_89 = V_95 ;
V_9 -> V_94 = V_95 + V_106 ;
V_9 -> V_107 = V_95 + V_108 ;
V_97 = V_9 -> V_89 -> V_97 ;
if ( V_97 & V_109 ) {
F_9 ( L_11 ) ;
V_9 -> V_48 = V_95 + V_110 ;
}
if ( V_97 & V_111 ) {
F_9 ( L_12 ) ;
V_9 -> V_93 = V_95 + V_112 ;
}
if ( V_97 & V_113 ) {
F_9 ( L_13 ) ;
V_9 -> V_8 = V_95 + V_114 ;
}
return 0 ;
V_105:
F_30 ( V_95 ) ;
return V_98 ;
}
