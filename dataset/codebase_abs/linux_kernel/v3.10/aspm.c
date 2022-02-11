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
F_4 (child, &linkbus->devices, bus_list) {
if ( V_10 )
F_5 ( V_12 , V_17 ,
V_18 ) ;
else
F_6 ( V_12 , V_17 ,
V_18 ) ;
}
V_2 -> V_19 = ! ! V_10 ;
}
static void F_7 ( struct V_1 * V_2 , int V_10 )
{
if ( ! V_2 -> V_20 && V_10 )
V_10 = 0 ;
if ( V_2 -> V_19 == V_10 )
return;
F_3 ( V_2 , V_10 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_21 )
{
int V_22 = 1 , V_23 = 1 ;
T_1 V_24 ;
T_2 V_25 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = V_2 -> V_15 -> V_16 ;
F_4 (child, &linkbus->devices, bus_list) {
F_9 ( V_12 , V_26 , & V_24 ) ;
if ( ! ( V_24 & V_27 ) ) {
V_22 = 0 ;
V_23 = 0 ;
break;
}
F_10 ( V_12 , V_17 , & V_25 ) ;
if ( ! ( V_25 & V_18 ) )
V_23 = 0 ;
}
V_2 -> V_19 = V_23 ;
V_2 -> V_9 = V_23 ;
V_2 -> V_20 = ( V_21 ) ? 0 : V_22 ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_28 = 1 ;
T_2 V_25 , V_29 , V_30 [ 8 ] ;
unsigned long V_31 ;
struct V_11 * V_12 , * V_32 = V_2 -> V_15 ;
struct V_13 * V_14 = V_32 -> V_16 ;
V_12 = F_12 ( V_14 -> V_33 . V_34 , struct V_11 , V_35 ) ;
F_13 ( ! F_14 ( V_12 ) ) ;
F_10 ( V_12 , V_36 , & V_25 ) ;
if ( ! ( V_25 & V_37 ) )
V_28 = 0 ;
F_10 ( V_32 , V_36 , & V_25 ) ;
if ( ! ( V_25 & V_37 ) )
V_28 = 0 ;
F_4 (child, &linkbus->devices, bus_list) {
F_10 ( V_12 , V_17 , & V_25 ) ;
V_30 [ F_15 ( V_12 -> V_38 ) ] = V_25 ;
if ( V_28 )
V_25 |= V_39 ;
else
V_25 &= ~ V_39 ;
F_16 ( V_12 , V_17 , V_25 ) ;
}
F_10 ( V_32 , V_17 , & V_25 ) ;
V_29 = V_25 ;
if ( V_28 )
V_25 |= V_39 ;
else
V_25 &= ~ V_39 ;
F_16 ( V_32 , V_17 , V_25 ) ;
V_25 |= V_40 ;
F_16 ( V_32 , V_17 , V_25 ) ;
V_31 = V_41 ;
for (; ; ) {
F_10 ( V_32 , V_36 , & V_25 ) ;
if ( ! ( V_25 & V_42 ) )
break;
if ( F_17 ( V_41 , V_31 + V_43 ) )
break;
F_18 ( 1 ) ;
}
if ( ! ( V_25 & V_42 ) )
return;
F_19 ( & V_32 -> V_44 , L_1 ) ;
F_4 (child, &linkbus->devices, bus_list)
F_16 ( V_12 , V_17 ,
V_30 [ F_15 ( V_12 -> V_38 ) ] ) ;
F_16 ( V_32 , V_17 , V_29 ) ;
}
static T_1 F_20 ( T_1 V_45 )
{
if ( V_45 == 0x7 )
return ( 5 * 1000 ) ;
return ( 64 << V_45 ) ;
}
static T_1 F_21 ( T_1 V_45 )
{
if ( V_45 == 0x7 )
return - 1U ;
return ( 64 << V_45 ) ;
}
static T_1 F_22 ( T_1 V_45 )
{
if ( V_45 == 0x7 )
return ( 65 * 1000 ) ;
return ( 1000 << V_45 ) ;
}
static T_1 F_23 ( T_1 V_45 )
{
if ( V_45 == 0x7 )
return - 1U ;
return ( 1000 << V_45 ) ;
}
static void F_24 ( struct V_11 * V_15 ,
struct V_46 * V_47 )
{
T_2 V_25 ;
T_1 V_24 ;
F_9 ( V_15 , V_26 , & V_24 ) ;
V_47 -> V_48 = ( V_24 & V_49 ) >> 10 ;
V_47 -> V_50 = ( V_24 & V_51 ) >> 12 ;
V_47 -> V_52 = ( V_24 & V_53 ) >> 15 ;
F_10 ( V_15 , V_17 , & V_25 ) ;
V_47 -> V_23 = V_25 & V_54 ;
}
static void F_25 ( struct V_11 * V_55 )
{
T_1 V_56 , V_57 = 0 ;
struct V_58 * V_59 ;
struct V_1 * V_2 ;
if ( ( V_55 -> V_60 != V_61 ) &&
( V_55 -> V_60 != V_62 ) )
return;
V_2 = V_55 -> V_63 -> V_64 -> V_65 ;
V_59 = & V_2 -> V_59 [ F_15 ( V_55 -> V_38 ) ] ;
while ( V_2 ) {
if ( ( V_2 -> V_66 & V_67 ) &&
( V_2 -> V_68 . V_69 > V_59 -> V_69 ) )
V_2 -> V_66 &= ~ V_67 ;
if ( ( V_2 -> V_66 & V_70 ) &&
( V_2 -> V_71 . V_69 > V_59 -> V_69 ) )
V_2 -> V_66 &= ~ V_70 ;
V_56 = F_26 ( T_1 , V_2 -> V_68 . V_72 , V_2 -> V_71 . V_72 ) ;
if ( ( V_2 -> V_66 & V_73 ) &&
( V_56 + V_57 > V_59 -> V_72 ) )
V_2 -> V_66 &= ~ V_73 ;
V_57 += 1000 ;
V_2 = V_2 -> V_32 ;
}
}
static void F_27 ( struct V_1 * V_2 , int V_21 )
{
struct V_11 * V_12 , * V_32 = V_2 -> V_15 ;
struct V_13 * V_14 = V_32 -> V_16 ;
struct V_46 V_74 , V_75 ;
if ( V_21 ) {
V_2 -> V_76 = V_6 ;
V_2 -> V_77 = V_6 ;
return;
}
F_11 ( V_2 ) ;
F_24 ( V_32 , & V_74 ) ;
V_12 = F_12 ( V_14 -> V_33 . V_34 , struct V_11 , V_35 ) ;
F_24 ( V_12 , & V_75 ) ;
if ( V_75 . V_48 & V_74 . V_48 & V_78 )
V_2 -> V_79 |= V_80 ;
if ( V_75 . V_23 & V_78 )
V_2 -> V_76 |= V_67 ;
if ( V_74 . V_23 & V_78 )
V_2 -> V_76 |= V_70 ;
V_2 -> V_68 . V_69 = F_20 ( V_74 . V_50 ) ;
V_2 -> V_71 . V_69 = F_20 ( V_75 . V_50 ) ;
if ( V_74 . V_48 & V_75 . V_48 & V_81 )
V_2 -> V_79 |= V_73 ;
if ( V_74 . V_23 & V_75 . V_23 & V_81 )
V_2 -> V_76 |= V_73 ;
V_2 -> V_68 . V_72 = F_22 ( V_74 . V_52 ) ;
V_2 -> V_71 . V_72 = F_22 ( V_75 . V_52 ) ;
V_2 -> V_8 = V_2 -> V_76 ;
V_2 -> V_66 = V_2 -> V_79 ;
F_4 (child, &linkbus->devices, bus_list) {
if ( F_28 ( V_12 ) == V_82 ) {
V_2 -> V_77 = V_6 ;
break;
}
}
F_4 (child, &linkbus->devices, bus_list) {
T_1 V_24 , V_45 ;
struct V_58 * V_59 =
& V_2 -> V_59 [ F_15 ( V_12 -> V_38 ) ] ;
if ( F_28 ( V_12 ) != V_83 &&
F_28 ( V_12 ) != V_84 )
continue;
F_9 ( V_12 , V_85 , & V_24 ) ;
V_45 = ( V_24 & V_86 ) >> 6 ;
V_59 -> V_69 = F_21 ( V_45 ) ;
V_45 = ( V_24 & V_87 ) >> 9 ;
V_59 -> V_72 = F_23 ( V_45 ) ;
F_25 ( V_12 ) ;
}
}
static void F_29 ( struct V_11 * V_15 , T_1 V_88 )
{
F_30 ( V_15 , V_17 ,
V_54 , V_88 ) ;
}
static void F_31 ( struct V_1 * V_2 , T_1 V_89 )
{
T_1 V_90 = 0 , V_91 = 0 ;
struct V_11 * V_12 , * V_32 = V_2 -> V_15 ;
struct V_13 * V_14 = V_32 -> V_16 ;
V_89 &= ( V_2 -> V_66 & ~ V_2 -> V_77 ) ;
if ( V_2 -> V_76 == V_89 )
return;
if ( V_89 & V_67 )
V_91 |= V_92 ;
if ( V_89 & V_70 )
V_90 |= V_92 ;
if ( V_89 & V_73 ) {
V_90 |= V_93 ;
V_91 |= V_93 ;
}
if ( V_89 & V_73 )
F_29 ( V_32 , V_90 ) ;
F_4 (child, &linkbus->devices, bus_list)
F_29 ( V_12 , V_91 ) ;
if ( ! ( V_89 & V_73 ) )
F_29 ( V_32 , V_90 ) ;
V_2 -> V_76 = V_89 ;
}
static void F_32 ( struct V_1 * V_2 )
{
while ( V_2 ) {
F_31 ( V_2 , F_1 ( V_2 ) ) ;
V_2 = V_2 -> V_32 ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
V_2 -> V_15 -> V_65 = NULL ;
F_34 ( V_2 ) ;
}
static int F_35 ( struct V_11 * V_15 )
{
struct V_11 * V_12 ;
T_1 V_24 ;
F_4 (child, &pdev->subordinate->devices, bus_list) {
if ( ! F_14 ( V_12 ) )
return - V_94 ;
if ( V_95 )
continue;
F_9 ( V_12 , V_85 , & V_24 ) ;
if ( ! ( V_24 & V_96 ) && ! V_97 ) {
F_36 ( & V_12 -> V_44 , L_2 ) ;
return - V_94 ;
}
}
return 0 ;
}
static struct V_1 * F_37 ( struct V_11 * V_15 )
{
struct V_1 * V_2 ;
V_2 = F_38 ( sizeof( * V_2 ) , V_98 ) ;
if ( ! V_2 )
return NULL ;
F_39 ( & V_2 -> V_99 ) ;
F_39 ( & V_2 -> V_100 ) ;
F_39 ( & V_2 -> V_2 ) ;
V_2 -> V_15 = V_15 ;
if ( F_28 ( V_15 ) == V_101 ) {
struct V_1 * V_32 ;
V_32 = V_15 -> V_63 -> V_32 -> V_64 -> V_65 ;
if ( ! V_32 ) {
F_34 ( V_2 ) ;
return NULL ;
}
V_2 -> V_32 = V_32 ;
F_40 ( & V_2 -> V_2 , & V_32 -> V_100 ) ;
}
if ( ! V_2 -> V_32 )
V_2 -> V_102 = V_2 ;
else
V_2 -> V_102 = V_2 -> V_32 -> V_102 ;
F_40 ( & V_2 -> V_99 , & V_103 ) ;
V_15 -> V_65 = V_2 ;
return V_2 ;
}
void F_41 ( struct V_11 * V_15 )
{
struct V_1 * V_2 ;
int V_21 = ! ! F_35 ( V_15 ) ;
if ( ! V_104 )
return;
if ( ! F_14 ( V_15 ) || V_15 -> V_65 )
return;
if ( F_28 ( V_15 ) != V_105 &&
F_28 ( V_15 ) != V_101 )
return;
if ( F_28 ( V_15 ) == V_105 &&
V_15 -> V_63 -> V_64 )
return;
F_42 ( & V_106 ) ;
if ( F_43 ( & V_15 -> V_16 -> V_33 ) )
goto V_107;
F_44 ( & V_108 ) ;
V_2 = F_37 ( V_15 ) ;
if ( ! V_2 )
goto V_109;
F_27 ( V_2 , V_21 ) ;
F_8 ( V_2 , V_21 ) ;
if ( V_3 != V_5 ) {
F_32 ( V_2 ) ;
F_7 ( V_2 , F_2 ( V_2 ) ) ;
}
V_109:
F_45 ( & V_108 ) ;
V_107:
F_46 ( & V_106 ) ;
}
static void F_47 ( struct V_1 * V_102 )
{
struct V_1 * V_2 ;
F_13 ( V_102 -> V_32 ) ;
F_4 (link, &link_list, sibling) {
if ( V_2 -> V_102 != V_102 )
continue;
V_2 -> V_66 = V_2 -> V_79 ;
}
F_4 (link, &link_list, sibling) {
struct V_11 * V_12 ;
struct V_13 * V_14 = V_2 -> V_15 -> V_16 ;
if ( V_2 -> V_102 != V_102 )
continue;
F_4 (child, &linkbus->devices, bus_list) {
if ( ( F_28 ( V_12 ) != V_83 ) &&
( F_28 ( V_12 ) != V_84 ) )
continue;
F_25 ( V_12 ) ;
}
}
}
void F_48 ( struct V_11 * V_15 )
{
struct V_11 * V_32 = V_15 -> V_63 -> V_64 ;
struct V_1 * V_2 , * V_102 , * V_110 ;
if ( ! V_32 || ! V_32 -> V_65 )
return;
F_42 ( & V_106 ) ;
F_44 ( & V_108 ) ;
if ( ! F_49 ( & V_15 -> V_35 , & V_32 -> V_16 -> V_33 ) )
goto V_107;
V_2 = V_32 -> V_65 ;
V_102 = V_2 -> V_102 ;
V_110 = V_2 -> V_32 ;
F_31 ( V_2 , 0 ) ;
F_50 ( & V_2 -> V_99 ) ;
F_50 ( & V_2 -> V_2 ) ;
F_33 ( V_2 ) ;
if ( V_110 ) {
F_47 ( V_102 ) ;
F_32 ( V_110 ) ;
}
V_107:
F_45 ( & V_108 ) ;
F_46 ( & V_106 ) ;
}
void F_51 ( struct V_11 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_65 ;
if ( V_95 || ! F_14 ( V_15 ) || ! V_2 )
return;
if ( ( F_28 ( V_15 ) != V_105 ) &&
( F_28 ( V_15 ) != V_101 ) )
return;
F_42 ( & V_106 ) ;
F_44 ( & V_108 ) ;
F_47 ( V_2 -> V_102 ) ;
F_32 ( V_2 ) ;
F_45 ( & V_108 ) ;
F_46 ( & V_106 ) ;
}
void F_52 ( struct V_11 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_65 ;
if ( V_95 || ! F_14 ( V_15 ) || ! V_2 )
return;
if ( V_3 != V_5 )
return;
if ( ( F_28 ( V_15 ) != V_105 ) &&
( F_28 ( V_15 ) != V_101 ) )
return;
F_42 ( & V_106 ) ;
F_44 ( & V_108 ) ;
F_32 ( V_2 ) ;
F_7 ( V_2 , F_2 ( V_2 ) ) ;
F_45 ( & V_108 ) ;
F_46 ( & V_106 ) ;
}
static void F_53 ( struct V_11 * V_15 , int V_89 , bool V_111 ,
bool V_112 )
{
struct V_11 * V_32 = V_15 -> V_63 -> V_64 ;
struct V_1 * V_2 ;
if ( V_95 && ! V_112 )
return;
if ( ! F_14 ( V_15 ) )
return;
if ( F_28 ( V_15 ) == V_105 ||
F_28 ( V_15 ) == V_101 )
V_32 = V_15 ;
if ( ! V_32 || ! V_32 -> V_65 )
return;
if ( V_111 )
F_42 ( & V_106 ) ;
F_44 ( & V_108 ) ;
V_2 = V_32 -> V_65 ;
if ( V_89 & V_78 )
V_2 -> V_77 |= V_80 ;
if ( V_89 & V_81 )
V_2 -> V_77 |= V_73 ;
F_31 ( V_2 , F_1 ( V_2 ) ) ;
if ( V_89 & V_113 ) {
V_2 -> V_20 = 0 ;
F_7 ( V_2 , 0 ) ;
}
F_45 ( & V_108 ) ;
if ( V_111 )
F_46 ( & V_106 ) ;
}
void F_54 ( struct V_11 * V_15 , int V_89 )
{
F_53 ( V_15 , V_89 , false , false ) ;
}
void F_55 ( struct V_11 * V_15 , int V_89 )
{
F_53 ( V_15 , V_89 , true , false ) ;
}
void F_56 ( struct V_13 * V_63 )
{
struct V_11 * V_12 ;
if ( V_97 )
return;
F_4 (child, &bus->devices, bus_list) {
F_53 ( V_12 , V_78 |
V_81 |
V_113 ,
false , true ) ;
}
}
static int F_57 ( const char * V_88 , struct V_114 * V_115 )
{
int V_116 ;
struct V_1 * V_2 ;
if ( V_95 )
return - V_117 ;
for ( V_116 = 0 ; V_116 < F_58 ( V_118 ) ; V_116 ++ )
if ( ! strncmp ( V_88 , V_118 [ V_116 ] , strlen ( V_118 [ V_116 ] ) ) )
break;
if ( V_116 >= F_58 ( V_118 ) )
return - V_94 ;
if ( V_116 == V_3 )
return 0 ;
F_42 ( & V_106 ) ;
F_44 ( & V_108 ) ;
V_3 = V_116 ;
F_4 (link, &link_list, sibling) {
F_31 ( V_2 , F_1 ( V_2 ) ) ;
F_7 ( V_2 , F_2 ( V_2 ) ) ;
}
F_45 ( & V_108 ) ;
F_46 ( & V_106 ) ;
return 0 ;
}
static int F_59 ( char * V_119 , struct V_114 * V_115 )
{
int V_116 , V_120 = 0 ;
for ( V_116 = 0 ; V_116 < F_58 ( V_118 ) ; V_116 ++ )
if ( V_116 == V_3 )
V_120 += sprintf ( V_119 + V_120 , L_3 , V_118 [ V_116 ] ) ;
else
V_120 += sprintf ( V_119 + V_120 , L_4 , V_118 [ V_116 ] ) ;
return V_120 ;
}
static T_3 F_60 ( struct V_121 * V_44 ,
struct V_122 * V_123 ,
char * V_124 )
{
struct V_11 * V_125 = F_61 ( V_44 ) ;
struct V_1 * V_65 = V_125 -> V_65 ;
return sprintf ( V_124 , L_5 , V_65 -> V_76 ) ;
}
static T_3 F_62 ( struct V_121 * V_44 ,
struct V_122 * V_123 ,
const char * V_124 ,
T_4 V_126 )
{
struct V_11 * V_15 = F_61 ( V_44 ) ;
struct V_1 * V_2 , * V_102 = V_15 -> V_65 -> V_102 ;
T_1 V_88 = V_124 [ 0 ] - '0' , V_89 = 0 ;
if ( V_95 )
return - V_117 ;
if ( V_126 < 1 || V_88 > 3 )
return - V_94 ;
if ( V_88 & V_78 )
V_89 |= V_80 ;
if ( V_88 & V_81 )
V_89 |= V_73 ;
F_42 ( & V_106 ) ;
F_44 ( & V_108 ) ;
F_4 (link, &link_list, sibling) {
if ( V_2 -> V_102 != V_102 )
continue;
F_31 ( V_2 , V_89 ) ;
}
F_45 ( & V_108 ) ;
F_46 ( & V_106 ) ;
return V_126 ;
}
static T_3 F_63 ( struct V_121 * V_44 ,
struct V_122 * V_123 ,
char * V_124 )
{
struct V_11 * V_125 = F_61 ( V_44 ) ;
struct V_1 * V_65 = V_125 -> V_65 ;
return sprintf ( V_124 , L_5 , V_65 -> V_19 ) ;
}
static T_3 F_64 ( struct V_121 * V_44 ,
struct V_122 * V_123 ,
const char * V_124 ,
T_4 V_126 )
{
struct V_11 * V_15 = F_61 ( V_44 ) ;
int V_89 ;
if ( V_126 < 1 )
return - V_94 ;
V_89 = V_124 [ 0 ] - '0' ;
F_42 ( & V_106 ) ;
F_44 ( & V_108 ) ;
F_3 ( V_15 -> V_65 , ! ! V_89 ) ;
F_45 ( & V_108 ) ;
F_46 ( & V_106 ) ;
return V_126 ;
}
void F_65 ( struct V_11 * V_15 )
{
struct V_1 * V_65 = V_15 -> V_65 ;
if ( ! F_14 ( V_15 ) ||
( F_28 ( V_15 ) != V_105 &&
F_28 ( V_15 ) != V_101 ) || ! V_65 )
return;
if ( V_65 -> V_79 )
F_66 ( & V_15 -> V_44 . V_127 ,
& V_128 . V_123 , V_129 ) ;
if ( V_65 -> V_20 )
F_66 ( & V_15 -> V_44 . V_127 ,
& V_130 . V_123 , V_129 ) ;
}
void F_67 ( struct V_11 * V_15 )
{
struct V_1 * V_65 = V_15 -> V_65 ;
if ( ! F_14 ( V_15 ) ||
( F_28 ( V_15 ) != V_105 &&
F_28 ( V_15 ) != V_101 ) || ! V_65 )
return;
if ( V_65 -> V_79 )
F_68 ( & V_15 -> V_44 . V_127 ,
& V_128 . V_123 , V_129 ) ;
if ( V_65 -> V_20 )
F_68 ( & V_15 -> V_44 . V_127 ,
& V_130 . V_123 , V_129 ) ;
}
static int T_5 F_69 ( char * V_131 )
{
if ( ! strcmp ( V_131 , L_6 ) ) {
V_3 = V_7 ;
V_95 = 1 ;
V_104 = false ;
F_70 ( V_132 L_7 ) ;
} else if ( ! strcmp ( V_131 , L_8 ) ) {
V_97 = 1 ;
F_70 ( V_132 L_9 ) ;
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
int F_72 ( void )
{
return ! V_95 ;
}
bool F_73 ( void )
{
return V_104 ;
}
