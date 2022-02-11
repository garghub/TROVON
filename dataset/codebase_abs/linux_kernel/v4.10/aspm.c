static int F_1 ( struct V_1 * V_2 )
{
switch ( V_3 ) {
case V_4 :
return 0 ;
case V_5 :
return V_6 ;
case V_7 :
return V_2 -> V_8 ;
}
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
switch ( V_3 ) {
case V_4 :
return 0 ;
case V_5 :
return 1 ;
case V_7 :
return V_2 -> V_9 ;
}
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , int V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 = V_2 -> V_15 -> V_16 ;
T_1 V_17 = V_10 ? V_18 : 0 ;
F_4 (child, &linkbus->devices, bus_list)
F_5 ( V_12 , V_19 ,
V_18 ,
V_17 ) ;
V_2 -> V_20 = ! ! V_10 ;
}
static void F_6 ( struct V_1 * V_2 , int V_10 )
{
if ( ! V_2 -> V_21 )
V_10 = 0 ;
if ( V_2 -> V_20 == V_10 )
return;
F_3 ( V_2 , V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_22 )
{
int V_23 = 1 , V_24 = 1 ;
T_1 V_25 ;
T_2 V_26 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = V_2 -> V_15 -> V_16 ;
F_4 (child, &linkbus->devices, bus_list) {
F_8 ( V_12 , V_27 , & V_25 ) ;
if ( ! ( V_25 & V_28 ) ) {
V_23 = 0 ;
V_24 = 0 ;
break;
}
F_9 ( V_12 , V_19 , & V_26 ) ;
if ( ! ( V_26 & V_18 ) )
V_24 = 0 ;
}
V_2 -> V_20 = V_24 ;
V_2 -> V_9 = V_24 ;
V_2 -> V_21 = ( V_22 ) ? 0 : V_23 ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_29 = 1 ;
T_2 V_26 , V_30 , V_31 [ 8 ] ;
unsigned long V_32 ;
struct V_11 * V_12 , * V_33 = V_2 -> V_15 ;
struct V_13 * V_14 = V_33 -> V_16 ;
V_12 = F_11 ( V_14 -> V_34 . V_35 , struct V_11 , V_36 ) ;
F_12 ( ! F_13 ( V_12 ) ) ;
F_9 ( V_12 , V_37 , & V_26 ) ;
if ( ! ( V_26 & V_38 ) )
V_29 = 0 ;
F_9 ( V_33 , V_37 , & V_26 ) ;
if ( ! ( V_26 & V_38 ) )
V_29 = 0 ;
F_4 (child, &linkbus->devices, bus_list) {
F_9 ( V_12 , V_19 , & V_26 ) ;
V_31 [ F_14 ( V_12 -> V_39 ) ] = V_26 ;
if ( V_29 )
V_26 |= V_40 ;
else
V_26 &= ~ V_40 ;
F_15 ( V_12 , V_19 , V_26 ) ;
}
F_9 ( V_33 , V_19 , & V_26 ) ;
V_30 = V_26 ;
if ( V_29 )
V_26 |= V_40 ;
else
V_26 &= ~ V_40 ;
F_15 ( V_33 , V_19 , V_26 ) ;
V_26 |= V_41 ;
F_15 ( V_33 , V_19 , V_26 ) ;
V_32 = V_42 ;
for (; ; ) {
F_9 ( V_33 , V_37 , & V_26 ) ;
if ( ! ( V_26 & V_43 ) )
break;
if ( F_16 ( V_42 , V_32 + V_44 ) )
break;
F_17 ( 1 ) ;
}
if ( ! ( V_26 & V_43 ) )
return;
F_18 ( & V_33 -> V_45 , L_1 ) ;
F_4 (child, &linkbus->devices, bus_list)
F_15 ( V_12 , V_19 ,
V_31 [ F_14 ( V_12 -> V_39 ) ] ) ;
F_15 ( V_33 , V_19 , V_30 ) ;
}
static T_1 F_19 ( T_1 V_46 )
{
if ( V_46 == 0x7 )
return ( 5 * 1000 ) ;
return ( 64 << V_46 ) ;
}
static T_1 F_20 ( T_1 V_46 )
{
if ( V_46 == 0x7 )
return - 1U ;
return ( 64 << V_46 ) ;
}
static T_1 F_21 ( T_1 V_46 )
{
if ( V_46 == 0x7 )
return ( 65 * 1000 ) ;
return ( 1000 << V_46 ) ;
}
static T_1 F_22 ( T_1 V_46 )
{
if ( V_46 == 0x7 )
return - 1U ;
return ( 1000 << V_46 ) ;
}
static void F_23 ( struct V_11 * V_15 ,
struct V_47 * V_48 )
{
T_2 V_26 ;
T_1 V_25 ;
F_8 ( V_15 , V_27 , & V_25 ) ;
V_48 -> V_49 = ( V_25 & V_50 ) >> 10 ;
V_48 -> V_51 = ( V_25 & V_52 ) >> 12 ;
V_48 -> V_53 = ( V_25 & V_54 ) >> 15 ;
F_9 ( V_15 , V_19 , & V_26 ) ;
V_48 -> V_24 = V_26 & V_55 ;
}
static void F_24 ( struct V_11 * V_56 )
{
T_1 V_57 , V_58 = 0 ;
struct V_59 * V_60 ;
struct V_1 * V_2 ;
if ( ( V_56 -> V_61 != V_62 ) &&
( V_56 -> V_61 != V_63 ) )
return;
V_2 = V_56 -> V_64 -> V_65 -> V_66 ;
V_60 = & V_2 -> V_60 [ F_14 ( V_56 -> V_39 ) ] ;
while ( V_2 ) {
if ( ( V_2 -> V_67 & V_68 ) &&
( V_2 -> V_69 . V_70 > V_60 -> V_70 ) )
V_2 -> V_67 &= ~ V_68 ;
if ( ( V_2 -> V_67 & V_71 ) &&
( V_2 -> V_72 . V_70 > V_60 -> V_70 ) )
V_2 -> V_67 &= ~ V_71 ;
V_57 = F_25 ( T_1 , V_2 -> V_69 . V_73 , V_2 -> V_72 . V_73 ) ;
if ( ( V_2 -> V_67 & V_74 ) &&
( V_57 + V_58 > V_60 -> V_73 ) )
V_2 -> V_67 &= ~ V_74 ;
V_58 += 1000 ;
V_2 = V_2 -> V_33 ;
}
}
static void F_26 ( struct V_1 * V_2 , int V_22 )
{
struct V_11 * V_12 , * V_33 = V_2 -> V_15 ;
struct V_13 * V_14 = V_33 -> V_16 ;
struct V_47 V_75 , V_76 ;
if ( V_22 ) {
V_2 -> V_77 = V_6 ;
V_2 -> V_78 = V_6 ;
return;
}
F_23 ( V_33 , & V_75 ) ;
V_12 = F_11 ( V_14 -> V_34 . V_35 , struct V_11 , V_36 ) ;
F_23 ( V_12 , & V_76 ) ;
if ( ! ( V_75 . V_49 & V_76 . V_49 ) )
return;
F_10 ( V_2 ) ;
F_23 ( V_33 , & V_75 ) ;
F_23 ( V_12 , & V_76 ) ;
if ( V_76 . V_49 & V_75 . V_49 & V_79 )
V_2 -> V_80 |= V_81 ;
if ( V_76 . V_24 & V_79 )
V_2 -> V_77 |= V_68 ;
if ( V_75 . V_24 & V_79 )
V_2 -> V_77 |= V_71 ;
V_2 -> V_69 . V_70 = F_19 ( V_75 . V_51 ) ;
V_2 -> V_72 . V_70 = F_19 ( V_76 . V_51 ) ;
if ( V_75 . V_49 & V_76 . V_49 & V_82 )
V_2 -> V_80 |= V_74 ;
if ( V_75 . V_24 & V_76 . V_24 & V_82 )
V_2 -> V_77 |= V_74 ;
V_2 -> V_69 . V_73 = F_21 ( V_75 . V_53 ) ;
V_2 -> V_72 . V_73 = F_21 ( V_76 . V_53 ) ;
V_2 -> V_8 = V_2 -> V_77 ;
V_2 -> V_67 = V_2 -> V_80 ;
F_4 (child, &linkbus->devices, bus_list) {
if ( F_27 ( V_12 ) == V_83 ) {
V_2 -> V_78 = V_6 ;
break;
}
}
F_4 (child, &linkbus->devices, bus_list) {
T_1 V_25 , V_46 ;
struct V_59 * V_60 =
& V_2 -> V_60 [ F_14 ( V_12 -> V_39 ) ] ;
if ( F_27 ( V_12 ) != V_84 &&
F_27 ( V_12 ) != V_85 )
continue;
F_8 ( V_12 , V_86 , & V_25 ) ;
V_46 = ( V_25 & V_87 ) >> 6 ;
V_60 -> V_70 = F_20 ( V_46 ) ;
V_46 = ( V_25 & V_88 ) >> 9 ;
V_60 -> V_73 = F_22 ( V_46 ) ;
F_24 ( V_12 ) ;
}
}
static void F_28 ( struct V_11 * V_15 , T_1 V_17 )
{
F_5 ( V_15 , V_19 ,
V_55 , V_17 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_89 )
{
T_1 V_90 = 0 , V_91 = 0 ;
struct V_11 * V_12 , * V_33 = V_2 -> V_15 ;
struct V_13 * V_14 = V_33 -> V_16 ;
V_89 &= ( V_2 -> V_67 & ~ V_2 -> V_78 ) ;
if ( V_2 -> V_77 == V_89 )
return;
if ( V_89 & V_68 )
V_91 |= V_92 ;
if ( V_89 & V_71 )
V_90 |= V_92 ;
if ( V_89 & V_74 ) {
V_90 |= V_93 ;
V_91 |= V_93 ;
}
if ( V_89 & V_74 )
F_28 ( V_33 , V_90 ) ;
F_4 (child, &linkbus->devices, bus_list)
F_28 ( V_12 , V_91 ) ;
if ( ! ( V_89 & V_74 ) )
F_28 ( V_33 , V_90 ) ;
V_2 -> V_77 = V_89 ;
}
static void F_30 ( struct V_1 * V_2 )
{
while ( V_2 ) {
F_29 ( V_2 , F_1 ( V_2 ) ) ;
V_2 = V_2 -> V_33 ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
V_2 -> V_15 -> V_66 = NULL ;
F_32 ( V_2 ) ;
}
static int F_33 ( struct V_11 * V_15 )
{
struct V_11 * V_12 ;
T_1 V_25 ;
F_4 (child, &pdev->subordinate->devices, bus_list) {
if ( ! F_13 ( V_12 ) )
return - V_94 ;
if ( V_95 )
continue;
F_8 ( V_12 , V_86 , & V_25 ) ;
if ( ! ( V_25 & V_96 ) && ! V_97 ) {
F_34 ( & V_12 -> V_45 , L_2 ) ;
return - V_94 ;
}
}
return 0 ;
}
static struct V_1 * F_35 ( struct V_11 * V_15 )
{
struct V_1 * V_2 ;
V_2 = F_36 ( sizeof( * V_2 ) , V_98 ) ;
if ( ! V_2 )
return NULL ;
F_37 ( & V_2 -> V_99 ) ;
F_37 ( & V_2 -> V_100 ) ;
F_37 ( & V_2 -> V_2 ) ;
V_2 -> V_15 = V_15 ;
if ( F_27 ( V_15 ) == V_101 ||
F_27 ( V_15 ) == V_102 ) {
V_2 -> V_103 = V_2 ;
} else {
struct V_1 * V_33 ;
V_33 = V_15 -> V_64 -> V_33 -> V_65 -> V_66 ;
if ( ! V_33 ) {
F_32 ( V_2 ) ;
return NULL ;
}
V_2 -> V_33 = V_33 ;
V_2 -> V_103 = V_2 -> V_33 -> V_103 ;
F_38 ( & V_2 -> V_2 , & V_33 -> V_100 ) ;
}
F_38 ( & V_2 -> V_99 , & V_104 ) ;
V_15 -> V_66 = V_2 ;
return V_2 ;
}
void F_39 ( struct V_11 * V_15 )
{
struct V_1 * V_2 ;
int V_22 = ! ! F_33 ( V_15 ) ;
if ( ! V_105 )
return;
if ( V_15 -> V_66 )
return;
if ( ! V_15 -> V_106 )
return;
if ( F_27 ( V_15 ) == V_101 &&
V_15 -> V_64 -> V_65 )
return;
F_40 ( & V_107 ) ;
if ( F_41 ( & V_15 -> V_16 -> V_34 ) )
goto V_108;
F_42 ( & V_109 ) ;
V_2 = F_35 ( V_15 ) ;
if ( ! V_2 )
goto V_110;
F_26 ( V_2 , V_22 ) ;
F_7 ( V_2 , V_22 ) ;
if ( V_3 != V_5 ) {
F_30 ( V_2 ) ;
F_6 ( V_2 , F_2 ( V_2 ) ) ;
}
V_110:
F_43 ( & V_109 ) ;
V_108:
F_44 ( & V_107 ) ;
}
static void F_45 ( struct V_1 * V_103 )
{
struct V_1 * V_2 ;
F_12 ( V_103 -> V_33 ) ;
F_4 (link, &link_list, sibling) {
if ( V_2 -> V_103 != V_103 )
continue;
V_2 -> V_67 = V_2 -> V_80 ;
}
F_4 (link, &link_list, sibling) {
struct V_11 * V_12 ;
struct V_13 * V_14 = V_2 -> V_15 -> V_16 ;
if ( V_2 -> V_103 != V_103 )
continue;
F_4 (child, &linkbus->devices, bus_list) {
if ( ( F_27 ( V_12 ) != V_84 ) &&
( F_27 ( V_12 ) != V_85 ) )
continue;
F_24 ( V_12 ) ;
}
}
}
void F_46 ( struct V_11 * V_15 )
{
struct V_11 * V_33 = V_15 -> V_64 -> V_65 ;
struct V_1 * V_2 , * V_103 , * V_111 ;
if ( ! V_33 || ! V_33 -> V_66 )
return;
F_40 ( & V_107 ) ;
F_42 ( & V_109 ) ;
if ( ! F_47 ( & V_15 -> V_36 , & V_33 -> V_16 -> V_34 ) )
goto V_108;
V_2 = V_33 -> V_66 ;
V_103 = V_2 -> V_103 ;
V_111 = V_2 -> V_33 ;
F_29 ( V_2 , 0 ) ;
F_48 ( & V_2 -> V_99 ) ;
F_48 ( & V_2 -> V_2 ) ;
F_31 ( V_2 ) ;
if ( V_111 ) {
F_45 ( V_103 ) ;
F_30 ( V_111 ) ;
}
V_108:
F_43 ( & V_109 ) ;
F_44 ( & V_107 ) ;
}
void F_49 ( struct V_11 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_66 ;
if ( V_95 || ! V_2 )
return;
F_40 ( & V_107 ) ;
F_42 ( & V_109 ) ;
F_45 ( V_2 -> V_103 ) ;
F_30 ( V_2 ) ;
F_43 ( & V_109 ) ;
F_44 ( & V_107 ) ;
}
void F_50 ( struct V_11 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_66 ;
if ( V_95 || ! V_2 )
return;
if ( V_3 != V_5 )
return;
F_40 ( & V_107 ) ;
F_42 ( & V_109 ) ;
F_30 ( V_2 ) ;
F_6 ( V_2 , F_2 ( V_2 ) ) ;
F_43 ( & V_109 ) ;
F_44 ( & V_107 ) ;
}
static void F_51 ( struct V_11 * V_15 , int V_89 , bool V_112 )
{
struct V_11 * V_33 = V_15 -> V_64 -> V_65 ;
struct V_1 * V_2 ;
if ( ! F_13 ( V_15 ) )
return;
if ( V_15 -> V_106 )
V_33 = V_15 ;
if ( ! V_33 || ! V_33 -> V_66 )
return;
if ( V_95 ) {
F_52 ( & V_15 -> V_45 , L_3 ) ;
return;
}
if ( V_112 )
F_40 ( & V_107 ) ;
F_42 ( & V_109 ) ;
V_2 = V_33 -> V_66 ;
if ( V_89 & V_79 )
V_2 -> V_78 |= V_81 ;
if ( V_89 & V_82 )
V_2 -> V_78 |= V_74 ;
F_29 ( V_2 , F_1 ( V_2 ) ) ;
if ( V_89 & V_113 ) {
V_2 -> V_21 = 0 ;
F_6 ( V_2 , 0 ) ;
}
F_43 ( & V_109 ) ;
if ( V_112 )
F_44 ( & V_107 ) ;
}
void F_53 ( struct V_11 * V_15 , int V_89 )
{
F_51 ( V_15 , V_89 , false ) ;
}
void F_54 ( struct V_11 * V_15 , int V_89 )
{
F_51 ( V_15 , V_89 , true ) ;
}
static int F_55 ( const char * V_17 , struct V_114 * V_115 )
{
int V_116 ;
struct V_1 * V_2 ;
if ( V_95 )
return - V_117 ;
for ( V_116 = 0 ; V_116 < F_56 ( V_118 ) ; V_116 ++ )
if ( ! strncmp ( V_17 , V_118 [ V_116 ] , strlen ( V_118 [ V_116 ] ) ) )
break;
if ( V_116 >= F_56 ( V_118 ) )
return - V_94 ;
if ( V_116 == V_3 )
return 0 ;
F_40 ( & V_107 ) ;
F_42 ( & V_109 ) ;
V_3 = V_116 ;
F_4 (link, &link_list, sibling) {
F_29 ( V_2 , F_1 ( V_2 ) ) ;
F_6 ( V_2 , F_2 ( V_2 ) ) ;
}
F_43 ( & V_109 ) ;
F_44 ( & V_107 ) ;
return 0 ;
}
static int F_57 ( char * V_119 , struct V_114 * V_115 )
{
int V_116 , V_120 = 0 ;
for ( V_116 = 0 ; V_116 < F_56 ( V_118 ) ; V_116 ++ )
if ( V_116 == V_3 )
V_120 += sprintf ( V_119 + V_120 , L_4 , V_118 [ V_116 ] ) ;
else
V_120 += sprintf ( V_119 + V_120 , L_5 , V_118 [ V_116 ] ) ;
return V_120 ;
}
static T_3 F_58 ( struct V_121 * V_45 ,
struct V_122 * V_123 ,
char * V_124 )
{
struct V_11 * V_125 = F_59 ( V_45 ) ;
struct V_1 * V_66 = V_125 -> V_66 ;
return sprintf ( V_124 , L_6 , V_66 -> V_77 ) ;
}
static T_3 F_60 ( struct V_121 * V_45 ,
struct V_122 * V_123 ,
const char * V_124 ,
T_4 V_126 )
{
struct V_11 * V_15 = F_59 ( V_45 ) ;
struct V_1 * V_2 , * V_103 = V_15 -> V_66 -> V_103 ;
T_1 V_89 ;
if ( V_95 )
return - V_117 ;
if ( F_61 ( V_124 , 10 , & V_89 ) )
return - V_94 ;
if ( ( V_89 & ~ V_6 ) != 0 )
return - V_94 ;
F_40 ( & V_107 ) ;
F_42 ( & V_109 ) ;
F_4 (link, &link_list, sibling) {
if ( V_2 -> V_103 != V_103 )
continue;
F_29 ( V_2 , V_89 ) ;
}
F_43 ( & V_109 ) ;
F_44 ( & V_107 ) ;
return V_126 ;
}
static T_3 F_62 ( struct V_121 * V_45 ,
struct V_122 * V_123 ,
char * V_124 )
{
struct V_11 * V_125 = F_59 ( V_45 ) ;
struct V_1 * V_66 = V_125 -> V_66 ;
return sprintf ( V_124 , L_6 , V_66 -> V_20 ) ;
}
static T_3 F_63 ( struct V_121 * V_45 ,
struct V_122 * V_123 ,
const char * V_124 ,
T_4 V_126 )
{
struct V_11 * V_15 = F_59 ( V_45 ) ;
bool V_89 ;
if ( F_64 ( V_124 , & V_89 ) )
return - V_94 ;
F_40 ( & V_107 ) ;
F_42 ( & V_109 ) ;
F_3 ( V_15 -> V_66 , V_89 ) ;
F_43 ( & V_109 ) ;
F_44 ( & V_107 ) ;
return V_126 ;
}
void F_65 ( struct V_11 * V_15 )
{
struct V_1 * V_66 = V_15 -> V_66 ;
if ( ! V_66 )
return;
if ( V_66 -> V_80 )
F_66 ( & V_15 -> V_45 . V_127 ,
& V_128 . V_123 , V_129 ) ;
if ( V_66 -> V_21 )
F_66 ( & V_15 -> V_45 . V_127 ,
& V_130 . V_123 , V_129 ) ;
}
void F_67 ( struct V_11 * V_15 )
{
struct V_1 * V_66 = V_15 -> V_66 ;
if ( ! V_66 )
return;
if ( V_66 -> V_80 )
F_68 ( & V_15 -> V_45 . V_127 ,
& V_128 . V_123 , V_129 ) ;
if ( V_66 -> V_21 )
F_68 ( & V_15 -> V_45 . V_127 ,
& V_130 . V_123 , V_129 ) ;
}
static int T_5 F_69 ( char * V_131 )
{
if ( ! strcmp ( V_131 , L_7 ) ) {
V_3 = V_7 ;
V_95 = 1 ;
V_105 = false ;
F_70 ( V_132 L_8 ) ;
} else if ( ! strcmp ( V_131 , L_9 ) ) {
V_97 = 1 ;
F_70 ( V_132 L_10 ) ;
}
return 1 ;
}
void F_71 ( void )
{
if ( ! V_97 ) {
V_3 = V_7 ;
V_95 = 1 ;
}
}
bool F_72 ( void )
{
return V_105 ;
}
