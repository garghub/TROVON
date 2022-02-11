static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 T_2 * V_8 = V_5 -> V_9 . V_8 ;
F_2 ( L_1 , V_3 ) ;
if ( ! ( V_3 & V_10 ) )
return V_11 ;
V_3 &= V_12 ;
if ( V_3 > 255 )
return V_11 ;
F_3 ( V_2 , V_3 , 255 ) ;
F_4 ( F_5 ( V_3 * 100 , 255 ) | V_13 , & V_8 -> V_14 ) ;
return 0 ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_15 )
{
F_2 ( L_2 ) ;
return V_16 ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_17 )
{
F_2 ( L_3 ) ;
return V_18 ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_1 V_19 )
{
F_2 ( L_4 ) ;
return V_20 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 T_2 * V_8 = V_5 -> V_9 . V_8 ;
T_1 V_21 = 0 ;
T_1 V_22 ;
if ( ! V_8 )
return;
V_22 = F_10 ( & V_8 -> V_23 ) & V_24 ;
if ( ! V_22 ) {
F_2 ( L_5 ) ;
return;
}
if ( V_22 & V_25 )
V_21 |= F_6 ( V_2 , F_10 ( & V_8 -> V_15 ) ) ;
if ( V_22 & V_26 )
V_21 |= F_1 ( V_2 , F_10 ( & V_8 -> V_3 ) ) ;
if ( V_22 & V_27 )
V_21 |= F_8 ( V_2 , F_10 ( & V_8 -> V_19 ) ) ;
if ( V_22 & V_28 )
V_21 |= F_7 ( V_2 , F_10 ( & V_8 -> V_17 ) ) ;
F_4 ( V_21 , & V_8 -> V_23 ) ;
}
static int F_11 ( struct V_29 * V_30 ,
unsigned long V_31 , void * V_32 )
{
struct V_33 T_2 * V_34 ;
struct V_35 * V_36 = V_32 ;
int V_37 = V_38 ;
if ( strcmp ( V_36 -> V_39 , V_40 ) != 0 )
return V_41 ;
if ( ! V_42 )
return V_41 ;
V_34 = V_42 -> V_34 ;
if ( V_36 -> type == 0x80 &&
( F_10 ( & V_34 -> V_43 ) & 1 ) == 0 )
V_37 = V_44 ;
F_4 ( 0 , & V_34 -> V_45 ) ;
return V_37 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_46 * V_9 = & V_5 -> V_9 ;
struct V_47 * V_48 ;
T_3 V_49 ;
struct V_50 * V_51 , * V_52 , * V_53 = NULL ;
unsigned long long V_54 ;
T_4 V_55 ;
T_1 V_56 ;
int V_57 = 0 ;
V_49 = F_13 ( & V_2 -> V_58 -> V_2 ) ;
if ( ! V_49 || F_14 ( V_49 , & V_51 ) )
return;
if ( F_15 ( V_49 ) )
V_53 = V_51 ;
else {
F_16 (acpi_cdev, &acpi_dev->children, node) {
if ( F_15 ( V_52 -> V_49 ) ) {
V_53 = V_52 ;
break;
}
}
}
if ( ! V_53 ) {
F_17 ( L_6 ) ;
return;
}
F_16 (acpi_cdev, &acpi_video_bus->children, node) {
if ( V_57 >= 8 ) {
F_18 ( & V_2 -> V_58 -> V_2 ,
L_7 ) ;
return;
}
V_55 =
F_19 ( V_52 -> V_49 , L_8 ,
NULL , & V_54 ) ;
if ( F_20 ( V_55 ) ) {
if ( ! V_54 )
goto V_59;
F_4 ( ( T_1 ) ( V_54 & 0x0f0f ) ,
& V_9 -> V_34 -> V_60 [ V_57 ] ) ;
V_57 ++ ;
}
}
V_61:
if ( V_57 < 8 )
F_4 ( 0 , & V_9 -> V_34 -> V_60 [ V_57 ] ) ;
return;
V_59:
V_57 = 0 ;
F_16 (connector, &dev->mode_config.connector_list, head) {
int V_62 = V_63 ;
if ( V_57 >= 8 ) {
F_18 ( & V_2 -> V_58 -> V_2 ,
L_9 ) ;
return;
}
switch ( V_48 -> V_64 ) {
case V_65 :
case V_66 :
V_62 = V_67 ;
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_62 = V_72 ;
break;
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
V_62 = V_78 ;
break;
case V_79 :
V_62 = V_80 ;
break;
}
V_56 = F_10 ( & V_9 -> V_34 -> V_60 [ V_57 ] ) ;
F_4 ( V_56 | ( 1 << 31 ) | V_62 | V_57 ,
& V_9 -> V_34 -> V_60 [ V_57 ] ) ;
V_57 ++ ;
}
goto V_61;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_46 * V_9 = & V_5 -> V_9 ;
int V_57 = 0 ;
T_1 V_81 ;
do {
V_81 = F_10 ( & V_9 -> V_34 -> V_60 [ V_57 ] ) ;
F_4 ( V_81 , & V_9 -> V_34 -> V_82 [ V_57 ] ) ;
} while ( ++ V_57 < 8 && V_81 != 0 );
}
void F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_46 * V_9 = & V_5 -> V_9 ;
if ( ! V_9 -> V_83 )
return;
if ( V_9 -> V_34 ) {
if ( F_23 ( V_2 , V_84 ) ) {
F_12 ( V_2 ) ;
F_21 ( V_2 ) ;
}
F_4 ( 0 , & V_9 -> V_34 -> V_45 ) ;
F_4 ( 1 , & V_9 -> V_34 -> V_85 ) ;
V_42 = V_9 ;
F_24 ( & V_86 ) ;
}
if ( V_9 -> V_8 ) {
F_4 ( V_87 , & V_9 -> V_8 -> V_88 ) ;
F_4 ( V_89 , & V_9 -> V_8 -> V_90 ) ;
}
}
void F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_46 * V_9 = & V_5 -> V_9 ;
if ( ! V_9 -> V_83 )
return;
if ( V_9 -> V_8 )
F_4 ( V_91 , & V_9 -> V_8 -> V_90 ) ;
if ( V_9 -> V_34 ) {
F_4 ( 0 , & V_9 -> V_34 -> V_85 ) ;
V_42 = NULL ;
F_26 ( & V_86 ) ;
}
F_27 ( V_9 -> V_83 ) ;
V_9 -> V_83 = NULL ;
V_9 -> V_34 = NULL ;
V_9 -> V_92 = NULL ;
V_9 -> V_8 = NULL ;
V_9 -> V_93 = NULL ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_46 * V_9 = & V_5 -> V_9 ;
void T_2 * V_94 ;
T_1 V_95 , V_96 ;
char V_97 [ sizeof( V_98 ) ] ;
int V_99 = 0 ;
F_29 ( V_2 -> V_58 , V_100 , & V_95 ) ;
F_2 ( L_10 , V_95 ) ;
if ( V_95 == 0 ) {
F_2 ( L_11 ) ;
return - V_101 ;
}
V_94 = F_30 ( V_95 , V_102 ) ;
if ( ! V_94 )
return - V_103 ;
F_31 ( V_97 , V_94 , sizeof( V_97 ) ) ;
if ( memcmp ( V_97 , V_98 , 16 ) ) {
F_2 ( L_12 ) ;
V_99 = - V_104 ;
goto V_105;
}
V_9 -> V_83 = V_94 ;
V_9 -> V_93 = V_94 + V_106 ;
V_9 -> V_107 = V_94 + V_108 ;
V_96 = F_10 ( & V_9 -> V_83 -> V_96 ) ;
if ( V_96 & V_109 ) {
F_2 ( L_13 ) ;
V_9 -> V_34 = V_94 + V_110 ;
}
if ( V_96 & V_111 ) {
F_2 ( L_14 ) ;
V_9 -> V_92 = V_94 + V_112 ;
}
if ( V_96 & V_113 ) {
F_2 ( L_15 ) ;
V_9 -> V_8 = V_94 + V_114 ;
F_4 ( V_91 , & V_9 -> V_8 -> V_90 ) ;
}
return 0 ;
V_105:
F_27 ( V_94 ) ;
return V_99 ;
}
