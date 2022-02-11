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
int V_11 ;
T_1 V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 = V_2 -> V_17 -> V_18 ;
F_4 (child, &linkbus->devices, bus_list) {
V_11 = F_5 ( V_14 ) ;
if ( ! V_11 )
return;
F_6 ( V_14 , V_11 + V_19 , & V_12 ) ;
if ( V_10 )
V_12 |= V_20 ;
else
V_12 &= ~ V_20 ;
F_7 ( V_14 , V_11 + V_19 , V_12 ) ;
}
V_2 -> V_21 = ! ! V_10 ;
}
static void F_8 ( struct V_1 * V_2 , int V_10 )
{
if ( ! V_2 -> V_22 && V_10 )
V_10 = 0 ;
if ( V_2 -> V_21 == V_10 )
return;
F_3 ( V_2 , V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_23 )
{
int V_11 , V_24 = 1 , V_25 = 1 ;
T_2 V_26 ;
T_1 V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 = V_2 -> V_17 -> V_18 ;
F_4 (child, &linkbus->devices, bus_list) {
V_11 = F_5 ( V_14 ) ;
if ( ! V_11 )
return;
F_10 ( V_14 , V_11 + V_27 , & V_26 ) ;
if ( ! ( V_26 & V_28 ) ) {
V_24 = 0 ;
V_25 = 0 ;
break;
}
F_6 ( V_14 , V_11 + V_19 , & V_12 ) ;
if ( ! ( V_12 & V_20 ) )
V_25 = 0 ;
}
V_2 -> V_21 = V_25 ;
V_2 -> V_9 = V_25 ;
V_2 -> V_22 = ( V_23 ) ? 0 : V_24 ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_29 , V_30 , V_31 = 1 ;
T_1 V_12 , V_32 , V_33 [ 8 ] ;
unsigned long V_34 ;
struct V_13 * V_14 , * V_35 = V_2 -> V_17 ;
struct V_15 * V_16 = V_35 -> V_18 ;
V_14 = F_12 ( V_16 -> V_36 . V_37 , struct V_13 , V_38 ) ;
F_13 ( ! F_14 ( V_14 ) ) ;
V_30 = F_5 ( V_14 ) ;
F_6 ( V_14 , V_30 + V_39 , & V_12 ) ;
if ( ! ( V_12 & V_40 ) )
V_31 = 0 ;
V_29 = F_5 ( V_35 ) ;
F_6 ( V_35 , V_29 + V_39 , & V_12 ) ;
if ( ! ( V_12 & V_40 ) )
V_31 = 0 ;
F_4 (child, &linkbus->devices, bus_list) {
V_30 = F_5 ( V_14 ) ;
F_6 ( V_14 , V_30 + V_19 , & V_12 ) ;
V_33 [ F_15 ( V_14 -> V_41 ) ] = V_12 ;
if ( V_31 )
V_12 |= V_42 ;
else
V_12 &= ~ V_42 ;
F_7 ( V_14 , V_30 + V_19 , V_12 ) ;
}
F_6 ( V_35 , V_29 + V_19 , & V_12 ) ;
V_32 = V_12 ;
if ( V_31 )
V_12 |= V_42 ;
else
V_12 &= ~ V_42 ;
F_7 ( V_35 , V_29 + V_19 , V_12 ) ;
V_12 |= V_43 ;
F_7 ( V_35 , V_29 + V_19 , V_12 ) ;
V_34 = V_44 ;
for (; ; ) {
F_6 ( V_35 , V_29 + V_39 , & V_12 ) ;
if ( ! ( V_12 & V_45 ) )
break;
if ( F_16 ( V_44 , V_34 + V_46 ) )
break;
F_17 ( 1 ) ;
}
if ( ! ( V_12 & V_45 ) )
return;
F_18 ( V_47 , & V_35 -> V_48 ,
L_1 ) ;
F_4 (child, &linkbus->devices, bus_list) {
V_30 = F_5 ( V_14 ) ;
F_7 ( V_14 , V_30 + V_19 ,
V_33 [ F_15 ( V_14 -> V_41 ) ] ) ;
}
F_7 ( V_35 , V_29 + V_19 , V_32 ) ;
}
static T_2 F_19 ( T_2 V_49 )
{
if ( V_49 == 0x7 )
return ( 5 * 1000 ) ;
return ( 64 << V_49 ) ;
}
static T_2 F_20 ( T_2 V_49 )
{
if ( V_49 == 0x7 )
return - 1U ;
return ( 64 << V_49 ) ;
}
static T_2 F_21 ( T_2 V_49 )
{
if ( V_49 == 0x7 )
return ( 65 * 1000 ) ;
return ( 1000 << V_49 ) ;
}
static T_2 F_22 ( T_2 V_49 )
{
if ( V_49 == 0x7 )
return - 1U ;
return ( 1000 << V_49 ) ;
}
static void F_23 ( struct V_13 * V_17 ,
struct V_50 * V_51 )
{
int V_11 ;
T_1 V_12 ;
T_2 V_26 ;
V_11 = F_5 ( V_17 ) ;
F_10 ( V_17 , V_11 + V_27 , & V_26 ) ;
V_51 -> V_52 = ( V_26 & V_53 ) >> 10 ;
V_51 -> V_54 = ( V_26 & V_55 ) >> 12 ;
V_51 -> V_56 = ( V_26 & V_57 ) >> 15 ;
F_6 ( V_17 , V_11 + V_19 , & V_12 ) ;
V_51 -> V_25 = V_12 & V_58 ;
}
static void F_24 ( struct V_13 * V_59 )
{
T_2 V_60 , V_61 = 0 ;
struct V_62 * V_63 ;
struct V_1 * V_2 ;
if ( ( V_59 -> V_64 != V_65 ) &&
( V_59 -> V_64 != V_66 ) )
return;
V_2 = V_59 -> V_67 -> V_68 -> V_69 ;
V_63 = & V_2 -> V_63 [ F_15 ( V_59 -> V_41 ) ] ;
while ( V_2 ) {
if ( ( V_2 -> V_70 & V_71 ) &&
( V_2 -> V_72 . V_73 > V_63 -> V_73 ) )
V_2 -> V_70 &= ~ V_71 ;
if ( ( V_2 -> V_70 & V_74 ) &&
( V_2 -> V_75 . V_73 > V_63 -> V_73 ) )
V_2 -> V_70 &= ~ V_74 ;
V_60 = F_25 ( T_2 , V_2 -> V_72 . V_76 , V_2 -> V_75 . V_76 ) ;
if ( ( V_2 -> V_70 & V_77 ) &&
( V_60 + V_61 > V_63 -> V_76 ) )
V_2 -> V_70 &= ~ V_77 ;
V_61 += 1000 ;
V_2 = V_2 -> V_35 ;
}
}
static void F_26 ( struct V_1 * V_2 , int V_23 )
{
struct V_13 * V_14 , * V_35 = V_2 -> V_17 ;
struct V_15 * V_16 = V_35 -> V_18 ;
struct V_50 V_78 , V_79 ;
if ( V_23 ) {
V_2 -> V_80 = V_6 ;
V_2 -> V_81 = V_6 ;
return;
}
F_11 ( V_2 ) ;
F_23 ( V_35 , & V_78 ) ;
V_14 = F_12 ( V_16 -> V_36 . V_37 , struct V_13 , V_38 ) ;
F_23 ( V_14 , & V_79 ) ;
if ( V_79 . V_52 & V_78 . V_52 & V_82 )
V_2 -> V_83 |= V_84 ;
if ( V_79 . V_25 & V_82 )
V_2 -> V_80 |= V_71 ;
if ( V_78 . V_25 & V_82 )
V_2 -> V_80 |= V_74 ;
V_2 -> V_72 . V_73 = F_19 ( V_78 . V_54 ) ;
V_2 -> V_75 . V_73 = F_19 ( V_79 . V_54 ) ;
if ( V_78 . V_52 & V_79 . V_52 & V_85 )
V_2 -> V_83 |= V_77 ;
if ( V_78 . V_25 & V_79 . V_25 & V_85 )
V_2 -> V_80 |= V_77 ;
V_2 -> V_72 . V_76 = F_21 ( V_78 . V_56 ) ;
V_2 -> V_75 . V_76 = F_21 ( V_79 . V_56 ) ;
V_2 -> V_8 = V_2 -> V_80 ;
V_2 -> V_70 = V_2 -> V_83 ;
F_4 (child, &linkbus->devices, bus_list) {
if ( V_14 -> V_86 == V_87 ) {
V_2 -> V_81 = V_6 ;
break;
}
}
F_4 (child, &linkbus->devices, bus_list) {
int V_11 ;
T_2 V_26 , V_49 ;
struct V_62 * V_63 =
& V_2 -> V_63 [ F_15 ( V_14 -> V_41 ) ] ;
if ( V_14 -> V_86 != V_88 &&
V_14 -> V_86 != V_89 )
continue;
V_11 = F_5 ( V_14 ) ;
F_10 ( V_14 , V_11 + V_90 , & V_26 ) ;
V_49 = ( V_26 & V_91 ) >> 6 ;
V_63 -> V_73 = F_20 ( V_49 ) ;
V_49 = ( V_26 & V_92 ) >> 9 ;
V_63 -> V_76 = F_22 ( V_49 ) ;
F_24 ( V_14 ) ;
}
}
static void F_27 ( struct V_13 * V_17 , T_2 V_93 )
{
T_1 V_12 ;
int V_11 = F_5 ( V_17 ) ;
F_6 ( V_17 , V_11 + V_19 , & V_12 ) ;
V_12 &= ~ 0x3 ;
V_12 |= V_93 ;
F_7 ( V_17 , V_11 + V_19 , V_12 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_2 V_94 )
{
T_2 V_95 = 0 , V_96 = 0 ;
struct V_13 * V_14 , * V_35 = V_2 -> V_17 ;
struct V_15 * V_16 = V_35 -> V_18 ;
V_94 &= ( V_2 -> V_70 & ~ V_2 -> V_81 ) ;
if ( V_2 -> V_80 == V_94 )
return;
if ( V_94 & V_71 )
V_96 |= V_82 ;
if ( V_94 & V_74 )
V_95 |= V_82 ;
if ( V_94 & V_77 ) {
V_95 |= V_85 ;
V_96 |= V_85 ;
}
if ( V_94 & V_77 )
F_27 ( V_35 , V_95 ) ;
F_4 (child, &linkbus->devices, bus_list)
F_27 ( V_14 , V_96 ) ;
if ( ! ( V_94 & V_77 ) )
F_27 ( V_35 , V_95 ) ;
V_2 -> V_80 = V_94 ;
}
static void F_29 ( struct V_1 * V_2 )
{
while ( V_2 ) {
F_28 ( V_2 , F_1 ( V_2 ) ) ;
V_2 = V_2 -> V_35 ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
V_2 -> V_17 -> V_69 = NULL ;
F_31 ( V_2 ) ;
}
static int F_32 ( struct V_13 * V_17 )
{
struct V_13 * V_14 ;
int V_11 ;
T_2 V_26 ;
if ( V_97 )
return 0 ;
F_4 (child, &pdev->subordinate->devices, bus_list) {
V_11 = F_5 ( V_14 ) ;
if ( ! V_11 )
return - V_98 ;
F_10 ( V_14 , V_11 + V_90 , & V_26 ) ;
if ( ! ( V_26 & V_99 ) && ! V_100 ) {
F_18 ( V_101 , & V_14 -> V_48 , L_2
L_3
L_4 ) ;
return - V_98 ;
}
}
return 0 ;
}
static struct V_1 * F_33 ( struct V_13 * V_17 )
{
struct V_1 * V_2 ;
V_2 = F_34 ( sizeof( * V_2 ) , V_102 ) ;
if ( ! V_2 )
return NULL ;
F_35 ( & V_2 -> V_103 ) ;
F_35 ( & V_2 -> V_104 ) ;
F_35 ( & V_2 -> V_2 ) ;
V_2 -> V_17 = V_17 ;
if ( V_17 -> V_86 == V_105 ) {
struct V_1 * V_35 ;
V_35 = V_17 -> V_67 -> V_35 -> V_68 -> V_69 ;
if ( ! V_35 ) {
F_31 ( V_2 ) ;
return NULL ;
}
V_2 -> V_35 = V_35 ;
F_36 ( & V_2 -> V_2 , & V_35 -> V_104 ) ;
}
if ( ! V_2 -> V_35 )
V_2 -> V_106 = V_2 ;
else
V_2 -> V_106 = V_2 -> V_35 -> V_106 ;
F_36 ( & V_2 -> V_103 , & V_107 ) ;
V_17 -> V_69 = V_2 ;
return V_2 ;
}
void F_37 ( struct V_13 * V_17 )
{
struct V_1 * V_2 ;
int V_23 = ! ! F_32 ( V_17 ) ;
if ( ! F_14 ( V_17 ) || V_17 -> V_69 )
return;
if ( V_17 -> V_86 != V_108 &&
V_17 -> V_86 != V_105 )
return;
if ( V_17 -> V_86 == V_108 &&
V_17 -> V_67 -> V_68 )
return;
F_38 ( & V_109 ) ;
if ( F_39 ( & V_17 -> V_18 -> V_36 ) )
goto V_110;
F_40 ( & V_111 ) ;
V_2 = F_33 ( V_17 ) ;
if ( ! V_2 )
goto V_112;
F_26 ( V_2 , V_23 ) ;
F_9 ( V_2 , V_23 ) ;
if ( V_3 != V_5 ) {
F_29 ( V_2 ) ;
F_8 ( V_2 , F_2 ( V_2 ) ) ;
}
V_112:
F_41 ( & V_111 ) ;
V_110:
F_42 ( & V_109 ) ;
}
static void F_43 ( struct V_1 * V_106 )
{
struct V_1 * V_2 ;
F_13 ( V_106 -> V_35 ) ;
F_4 (link, &link_list, sibling) {
if ( V_2 -> V_106 != V_106 )
continue;
V_2 -> V_70 = V_2 -> V_83 ;
}
F_4 (link, &link_list, sibling) {
struct V_13 * V_14 ;
struct V_15 * V_16 = V_2 -> V_17 -> V_18 ;
if ( V_2 -> V_106 != V_106 )
continue;
F_4 (child, &linkbus->devices, bus_list) {
if ( ( V_14 -> V_86 != V_88 ) &&
( V_14 -> V_86 != V_89 ) )
continue;
F_24 ( V_14 ) ;
}
}
}
void F_44 ( struct V_13 * V_17 )
{
struct V_13 * V_35 = V_17 -> V_67 -> V_68 ;
struct V_1 * V_2 , * V_106 , * V_113 ;
if ( ! F_14 ( V_17 ) || ! V_35 || ! V_35 -> V_69 )
return;
if ( ( V_35 -> V_86 != V_108 ) &&
( V_35 -> V_86 != V_105 ) )
return;
F_38 ( & V_109 ) ;
F_40 ( & V_111 ) ;
if ( ! F_45 ( & V_17 -> V_38 , & V_35 -> V_18 -> V_36 ) )
goto V_110;
V_2 = V_35 -> V_69 ;
V_106 = V_2 -> V_106 ;
V_113 = V_2 -> V_35 ;
F_28 ( V_2 , 0 ) ;
F_46 ( & V_2 -> V_103 ) ;
F_46 ( & V_2 -> V_2 ) ;
F_30 ( V_2 ) ;
if ( V_113 ) {
F_43 ( V_106 ) ;
F_29 ( V_113 ) ;
}
V_110:
F_41 ( & V_111 ) ;
F_42 ( & V_109 ) ;
}
void F_47 ( struct V_13 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_69 ;
if ( V_97 || ! F_14 ( V_17 ) || ! V_2 )
return;
if ( ( V_17 -> V_86 != V_108 ) &&
( V_17 -> V_86 != V_105 ) )
return;
F_38 ( & V_109 ) ;
F_40 ( & V_111 ) ;
F_43 ( V_2 -> V_106 ) ;
F_29 ( V_2 ) ;
F_41 ( & V_111 ) ;
F_42 ( & V_109 ) ;
}
void F_48 ( struct V_13 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_69 ;
if ( V_97 || ! F_14 ( V_17 ) || ! V_2 )
return;
if ( V_3 != V_5 )
return;
if ( ( V_17 -> V_86 != V_108 ) &&
( V_17 -> V_86 != V_105 ) )
return;
F_38 ( & V_109 ) ;
F_40 ( & V_111 ) ;
F_29 ( V_2 ) ;
F_8 ( V_2 , F_2 ( V_2 ) ) ;
F_41 ( & V_111 ) ;
F_42 ( & V_109 ) ;
}
static void F_49 ( struct V_13 * V_17 , int V_94 , bool V_114 ,
bool V_115 )
{
struct V_13 * V_35 = V_17 -> V_67 -> V_68 ;
struct V_1 * V_2 ;
if ( V_97 && ! V_115 )
return;
if ( ! F_14 ( V_17 ) )
return;
if ( V_17 -> V_86 == V_108 ||
V_17 -> V_86 == V_105 )
V_35 = V_17 ;
if ( ! V_35 || ! V_35 -> V_69 )
return;
if ( V_114 )
F_38 ( & V_109 ) ;
F_40 ( & V_111 ) ;
V_2 = V_35 -> V_69 ;
if ( V_94 & V_82 )
V_2 -> V_81 |= V_84 ;
if ( V_94 & V_85 )
V_2 -> V_81 |= V_77 ;
F_28 ( V_2 , F_1 ( V_2 ) ) ;
if ( V_94 & V_116 ) {
V_2 -> V_22 = 0 ;
F_8 ( V_2 , 0 ) ;
}
F_41 ( & V_111 ) ;
if ( V_114 )
F_42 ( & V_109 ) ;
}
void F_50 ( struct V_13 * V_17 , int V_94 )
{
F_49 ( V_17 , V_94 , false , false ) ;
}
void F_51 ( struct V_13 * V_17 , int V_94 )
{
F_49 ( V_17 , V_94 , true , false ) ;
}
void F_52 ( struct V_15 * V_67 )
{
struct V_13 * V_14 ;
F_4 (child, &bus->devices, bus_list) {
F_49 ( V_14 , V_82 |
V_85 |
V_116 ,
false , true ) ;
}
}
static int F_53 ( const char * V_93 , struct V_117 * V_118 )
{
int V_119 ;
struct V_1 * V_2 ;
if ( V_97 )
return - V_120 ;
for ( V_119 = 0 ; V_119 < F_54 ( V_121 ) ; V_119 ++ )
if ( ! strncmp ( V_93 , V_121 [ V_119 ] , strlen ( V_121 [ V_119 ] ) ) )
break;
if ( V_119 >= F_54 ( V_121 ) )
return - V_98 ;
if ( V_119 == V_3 )
return 0 ;
F_38 ( & V_109 ) ;
F_40 ( & V_111 ) ;
V_3 = V_119 ;
F_4 (link, &link_list, sibling) {
F_28 ( V_2 , F_1 ( V_2 ) ) ;
F_8 ( V_2 , F_2 ( V_2 ) ) ;
}
F_41 ( & V_111 ) ;
F_42 ( & V_109 ) ;
return 0 ;
}
static int F_55 ( char * V_122 , struct V_117 * V_118 )
{
int V_119 , V_123 = 0 ;
for ( V_119 = 0 ; V_119 < F_54 ( V_121 ) ; V_119 ++ )
if ( V_119 == V_3 )
V_123 += sprintf ( V_122 + V_123 , L_5 , V_121 [ V_119 ] ) ;
else
V_123 += sprintf ( V_122 + V_123 , L_6 , V_121 [ V_119 ] ) ;
return V_123 ;
}
static T_3 F_56 ( struct V_124 * V_48 ,
struct V_125 * V_126 ,
char * V_127 )
{
struct V_13 * V_128 = F_57 ( V_48 ) ;
struct V_1 * V_69 = V_128 -> V_69 ;
return sprintf ( V_127 , L_7 , V_69 -> V_80 ) ;
}
static T_3 F_58 ( struct V_124 * V_48 ,
struct V_125 * V_126 ,
const char * V_127 ,
T_4 V_129 )
{
struct V_13 * V_17 = F_57 ( V_48 ) ;
struct V_1 * V_2 , * V_106 = V_17 -> V_69 -> V_106 ;
T_2 V_93 = V_127 [ 0 ] - '0' , V_94 = 0 ;
if ( V_97 )
return - V_120 ;
if ( V_129 < 1 || V_93 > 3 )
return - V_98 ;
if ( V_93 & V_82 )
V_94 |= V_84 ;
if ( V_93 & V_85 )
V_94 |= V_77 ;
F_38 ( & V_109 ) ;
F_40 ( & V_111 ) ;
F_4 (link, &link_list, sibling) {
if ( V_2 -> V_106 != V_106 )
continue;
F_28 ( V_2 , V_94 ) ;
}
F_41 ( & V_111 ) ;
F_42 ( & V_109 ) ;
return V_129 ;
}
static T_3 F_59 ( struct V_124 * V_48 ,
struct V_125 * V_126 ,
char * V_127 )
{
struct V_13 * V_128 = F_57 ( V_48 ) ;
struct V_1 * V_69 = V_128 -> V_69 ;
return sprintf ( V_127 , L_7 , V_69 -> V_21 ) ;
}
static T_3 F_60 ( struct V_124 * V_48 ,
struct V_125 * V_126 ,
const char * V_127 ,
T_4 V_129 )
{
struct V_13 * V_17 = F_57 ( V_48 ) ;
int V_94 ;
if ( V_129 < 1 )
return - V_98 ;
V_94 = V_127 [ 0 ] - '0' ;
F_38 ( & V_109 ) ;
F_40 ( & V_111 ) ;
F_3 ( V_17 -> V_69 , ! ! V_94 ) ;
F_41 ( & V_111 ) ;
F_42 ( & V_109 ) ;
return V_129 ;
}
void F_61 ( struct V_13 * V_17 )
{
struct V_1 * V_69 = V_17 -> V_69 ;
if ( ! F_14 ( V_17 ) ||
( V_17 -> V_86 != V_108 &&
V_17 -> V_86 != V_105 ) || ! V_69 )
return;
if ( V_69 -> V_83 )
F_62 ( & V_17 -> V_48 . V_130 ,
& V_131 . V_126 , V_132 ) ;
if ( V_69 -> V_22 )
F_62 ( & V_17 -> V_48 . V_130 ,
& V_133 . V_126 , V_132 ) ;
}
void F_63 ( struct V_13 * V_17 )
{
struct V_1 * V_69 = V_17 -> V_69 ;
if ( ! F_14 ( V_17 ) ||
( V_17 -> V_86 != V_108 &&
V_17 -> V_86 != V_105 ) || ! V_69 )
return;
if ( V_69 -> V_83 )
F_64 ( & V_17 -> V_48 . V_130 ,
& V_131 . V_126 , V_132 ) ;
if ( V_69 -> V_22 )
F_64 ( & V_17 -> V_48 . V_130 ,
& V_133 . V_126 , V_132 ) ;
}
static int T_5 F_65 ( char * V_134 )
{
if ( ! strcmp ( V_134 , L_8 ) ) {
V_3 = V_7 ;
V_97 = 1 ;
V_135 = false ;
F_66 ( V_101 L_9 ) ;
} else if ( ! strcmp ( V_134 , L_10 ) ) {
V_100 = 1 ;
F_66 ( V_101 L_11 ) ;
}
return 1 ;
}
void F_67 ( void )
{
if ( ! V_100 ) {
V_3 = V_7 ;
V_97 = 1 ;
}
}
int F_68 ( void )
{
return ! V_97 ;
}
bool F_69 ( void )
{
return V_135 ;
}
