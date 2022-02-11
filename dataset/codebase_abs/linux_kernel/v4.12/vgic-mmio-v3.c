unsigned long F_1 ( T_1 V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
return ( V_1 >> ( V_2 * 8 ) ) & F_2 ( V_3 * 8 - 1 , 0 ) ;
}
T_1 F_3 ( T_1 V_4 , unsigned int V_2 , unsigned int V_5 ,
unsigned long V_6 )
{
int V_7 = ( V_2 & 4 ) * 8 ;
int V_8 = V_7 + 8 * V_5 - 1 ;
V_4 &= ~ F_2 ( V_8 , V_7 ) ;
V_6 &= F_2 ( V_5 * 8 - 1 , 0 ) ;
return V_4 | ( ( T_1 ) V_6 << V_7 ) ;
}
bool F_4 ( struct V_9 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 . V_13 ;
if ( V_11 -> V_14 != V_15 )
return false ;
return V_11 -> V_16 ;
}
static unsigned long F_5 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
T_3 V_20 = 0 ;
switch ( V_19 & 0x0c ) {
case V_21 :
if ( V_18 -> V_9 -> V_12 . V_13 . V_22 )
V_20 |= V_23 ;
V_20 |= V_24 | V_25 ;
break;
case V_26 :
V_20 = V_18 -> V_9 -> V_12 . V_13 . V_27 + V_28 ;
V_20 = ( V_20 >> 5 ) - 1 ;
if ( F_4 ( V_18 -> V_9 ) ) {
V_20 |= ( V_29 - 1 ) << 19 ;
V_20 |= V_30 ;
} else {
V_20 |= ( V_31 - 1 ) << 19 ;
}
break;
case V_32 :
V_20 = ( V_33 << 24 ) | ( V_34 << 0 ) ;
break;
default:
return 0 ;
}
return V_20 ;
}
static void F_6 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 ,
unsigned long V_6 )
{
struct V_10 * V_11 = & V_18 -> V_9 -> V_12 . V_13 ;
bool V_35 = V_11 -> V_22 ;
switch ( V_19 & 0x0c ) {
case V_21 :
V_11 -> V_22 = V_6 & V_23 ;
if ( ! V_35 && V_11 -> V_22 )
F_7 ( V_18 -> V_9 ) ;
break;
case V_26 :
case V_32 :
return;
}
}
static unsigned long F_8 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
int V_36 = F_9 ( V_19 , 64 ) ;
struct V_37 * V_38 = F_10 ( V_18 -> V_9 , NULL , V_36 ) ;
unsigned long V_39 = 0 ;
if ( ! V_38 )
return 0 ;
if ( ! ( V_19 & 4 ) )
V_39 = F_1 ( F_11 ( V_38 -> V_40 ) , V_19 & 7 , V_5 ) ;
F_12 ( V_18 -> V_9 , V_38 ) ;
return V_39 ;
}
static void F_13 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 ,
unsigned long V_6 )
{
int V_36 = F_9 ( V_19 , 64 ) ;
struct V_37 * V_38 ;
if ( V_19 & 4 )
return;
V_38 = F_10 ( V_18 -> V_9 , NULL , V_36 ) ;
if ( ! V_38 )
return;
F_14 ( & V_38 -> V_41 ) ;
V_38 -> V_40 = V_6 & F_15 ( 23 , 0 ) ;
V_38 -> V_42 = F_16 ( V_18 -> V_9 , V_38 -> V_40 ) ;
F_17 ( & V_38 -> V_41 ) ;
F_12 ( V_18 -> V_9 , V_38 ) ;
}
static unsigned long F_18 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
struct V_43 * V_43 = & V_18 -> V_12 . V_43 ;
return V_43 -> V_44 ? V_45 : 0 ;
}
static void F_19 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 ,
unsigned long V_6 )
{
struct V_43 * V_43 = & V_18 -> V_12 . V_43 ;
bool V_35 = V_43 -> V_44 ;
if ( ! F_4 ( V_18 -> V_9 ) )
return;
V_43 -> V_44 = V_6 & V_45 ;
if ( ! V_35 && V_43 -> V_44 )
F_20 ( V_18 ) ;
}
static unsigned long F_21 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
unsigned long V_40 = F_22 ( V_18 ) ;
int V_46 = V_18 -> V_47 ;
T_1 V_20 ;
V_20 = ( T_1 ) ( V_40 & F_15 ( 23 , 0 ) ) << 32 ;
V_20 |= ( ( V_46 & 0xffff ) << 8 ) ;
if ( V_46 == F_23 ( & V_18 -> V_9 -> V_48 ) - 1 )
V_20 |= V_49 ;
if ( F_4 ( V_18 -> V_9 ) )
V_20 |= V_50 ;
return F_1 ( V_20 , V_19 & 7 , V_5 ) ;
}
static unsigned long F_24 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
return ( V_33 << 24 ) | ( V_34 << 0 ) ;
}
static unsigned long F_25 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
switch ( V_19 & 0xffff ) {
case V_51 :
return 0x3b ;
}
return 0 ;
}
static unsigned long F_26 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
T_3 V_36 = F_9 ( V_19 , 1 ) ;
T_3 V_20 = 0 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_5 * 8 ; V_52 ++ ) {
struct V_37 * V_38 = F_10 ( V_18 -> V_9 , V_18 , V_36 + V_52 ) ;
if ( V_38 -> V_53 )
V_20 |= ( 1U << V_52 ) ;
F_12 ( V_18 -> V_9 , V_38 ) ;
}
return V_20 ;
}
static void F_27 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 ,
unsigned long V_6 )
{
T_3 V_36 = F_9 ( V_19 , 1 ) ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_5 * 8 ; V_52 ++ ) {
struct V_37 * V_38 = F_10 ( V_18 -> V_9 , V_18 , V_36 + V_52 ) ;
F_14 ( & V_38 -> V_41 ) ;
if ( F_28 ( V_52 , & V_6 ) ) {
V_38 -> V_53 = true ;
F_29 ( V_18 -> V_9 , V_38 ) ;
} else {
V_38 -> V_53 = false ;
F_17 ( & V_38 -> V_41 ) ;
}
F_12 ( V_18 -> V_9 , V_38 ) ;
}
}
T_1 F_30 ( T_1 V_54 )
{
switch ( V_54 ) {
case V_55 :
return V_56 ;
default:
return V_54 ;
}
}
T_1 F_31 ( T_1 V_54 )
{
switch ( V_54 ) {
case V_57 :
case V_58 :
return V_59 ;
default:
return V_54 ;
}
}
T_1 F_32 ( T_1 V_54 )
{
switch ( V_54 ) {
case V_60 :
case V_58 :
return V_54 ;
default:
return V_58 ;
}
}
T_1 F_33 ( T_1 V_4 , T_1 V_61 , int V_62 ,
T_1 (* F_34)( T_1 ) )
{
T_1 V_54 = ( V_4 & V_61 ) >> V_62 ;
V_54 = F_34 ( V_54 ) << V_62 ;
return ( V_4 & ~ V_61 ) | V_54 ;
}
static T_1 F_35 ( T_1 V_4 )
{
V_4 = F_33 ( V_4 , V_63 ,
V_64 ,
F_30 ) ;
V_4 = F_33 ( V_4 , V_65 ,
V_66 ,
F_31 ) ;
V_4 = F_33 ( V_4 , V_67 ,
V_68 ,
F_32 ) ;
V_4 &= ~ V_69 ;
V_4 &= ~ F_2 ( 51 , 48 ) ;
return V_4 ;
}
static T_1 F_36 ( T_1 V_4 )
{
V_4 = F_33 ( V_4 , V_70 ,
V_71 ,
F_30 ) ;
V_4 = F_33 ( V_4 , V_72 ,
V_73 ,
F_31 ) ;
V_4 = F_33 ( V_4 , V_74 ,
V_75 ,
F_32 ) ;
V_4 &= ~ V_76 ;
V_4 &= ~ F_2 ( 51 , 48 ) ;
return V_4 ;
}
static unsigned long F_37 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
struct V_10 * V_11 = & V_18 -> V_9 -> V_12 . V_13 ;
return F_1 ( V_11 -> V_77 , V_19 & 7 , V_5 ) ;
}
static void F_38 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 ,
unsigned long V_6 )
{
struct V_10 * V_11 = & V_18 -> V_9 -> V_12 . V_13 ;
struct V_43 * V_43 = & V_18 -> V_12 . V_43 ;
T_1 V_78 , V_77 ;
if ( V_43 -> V_44 )
return;
do {
V_78 = V_11 -> V_77 ;
V_77 = V_78 ;
V_77 = F_3 ( V_77 , V_19 & 4 , V_5 , V_6 ) ;
V_77 = F_36 ( V_77 ) ;
} while ( F_39 ( & V_11 -> V_77 , V_78 ,
V_77 ) != V_78 );
}
static unsigned long F_40 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
struct V_43 * V_43 = & V_18 -> V_12 . V_43 ;
return F_1 ( V_43 -> V_79 , V_19 & 7 , V_5 ) ;
}
static void F_41 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 ,
unsigned long V_6 )
{
struct V_43 * V_43 = & V_18 -> V_12 . V_43 ;
T_1 V_80 , V_79 ;
if ( V_43 -> V_44 )
return;
do {
V_80 = V_43 -> V_79 ;
V_79 = V_80 ;
V_79 = F_3 ( V_79 , V_19 & 4 , V_5 , V_6 ) ;
V_79 = F_35 ( V_79 ) ;
} while ( F_39 ( & V_43 -> V_79 , V_80 ,
V_79 ) != V_80 );
}
unsigned int F_42 ( struct V_81 * V_82 )
{
V_82 -> V_83 = V_84 ;
V_82 -> V_85 = F_43 ( V_84 ) ;
F_44 ( & V_82 -> V_82 , & V_86 ) ;
return V_87 ;
}
int F_45 ( struct V_17 * V_18 )
{
struct V_9 * V_9 = V_18 -> V_9 ;
struct V_10 * V_13 = & V_9 -> V_12 . V_13 ;
struct V_81 * V_88 = & V_18 -> V_12 . V_43 . V_89 ;
struct V_81 * V_90 = & V_18 -> V_12 . V_43 . V_91 ;
T_2 V_92 , V_93 ;
int V_39 ;
if ( F_46 ( V_13 -> V_94 ) )
return 0 ;
if ( ! F_47 ( V_9 ) )
return - V_95 ;
V_92 = V_13 -> V_94 + V_13 -> V_96 ;
V_93 = V_92 + V_87 ;
F_44 ( & V_88 -> V_82 , & V_86 ) ;
V_88 -> V_97 = V_92 ;
V_88 -> V_98 = V_99 ;
V_88 -> V_83 = V_100 ;
V_88 -> V_85 = F_43 ( V_100 ) ;
V_88 -> V_101 = V_18 ;
F_48 ( & V_9 -> V_102 ) ;
V_39 = F_49 ( V_9 , V_103 , V_92 ,
V_87 , & V_88 -> V_82 ) ;
F_50 ( & V_9 -> V_102 ) ;
if ( V_39 )
return V_39 ;
F_44 ( & V_90 -> V_82 , & V_86 ) ;
V_90 -> V_97 = V_93 ;
V_90 -> V_98 = V_99 ;
V_90 -> V_83 = V_104 ;
V_90 -> V_85 = F_43 ( V_104 ) ;
V_90 -> V_101 = V_18 ;
F_48 ( & V_9 -> V_102 ) ;
V_39 = F_49 ( V_9 , V_103 , V_93 ,
V_87 , & V_90 -> V_82 ) ;
if ( V_39 ) {
F_51 ( V_9 , V_103 ,
& V_88 -> V_82 ) ;
goto V_105;
}
V_13 -> V_96 += 2 * V_87 ;
V_105:
F_50 ( & V_9 -> V_102 ) ;
return V_39 ;
}
static void F_52 ( struct V_17 * V_18 )
{
struct V_81 * V_88 = & V_18 -> V_12 . V_43 . V_89 ;
struct V_81 * V_90 = & V_18 -> V_12 . V_43 . V_91 ;
F_51 ( V_18 -> V_9 , V_103 , & V_88 -> V_82 ) ;
F_51 ( V_18 -> V_9 , V_103 , & V_90 -> V_82 ) ;
}
static int F_53 ( struct V_9 * V_9 )
{
struct V_17 * V_18 ;
int V_106 , V_39 = 0 ;
F_54 (c, vcpu, kvm) {
V_39 = F_45 ( V_18 ) ;
if ( V_39 )
break;
}
if ( V_39 ) {
F_48 ( & V_9 -> V_102 ) ;
for ( V_106 -- ; V_106 >= 0 ; V_106 -- ) {
V_18 = F_55 ( V_9 , V_106 ) ;
F_52 ( V_18 ) ;
}
F_50 ( & V_9 -> V_102 ) ;
}
return V_39 ;
}
int F_56 ( struct V_9 * V_9 , T_1 V_19 )
{
struct V_10 * V_13 = & V_9 -> V_12 . V_13 ;
int V_39 ;
V_39 = F_57 ( V_9 , & V_13 -> V_94 , V_19 , V_87 ) ;
if ( V_39 )
return V_39 ;
V_13 -> V_94 = V_19 ;
if ( ! F_47 ( V_9 ) ) {
V_13 -> V_94 = V_107 ;
return - V_95 ;
}
V_39 = F_53 ( V_9 ) ;
if ( V_39 )
return V_39 ;
return 0 ;
}
int F_58 ( struct V_108 * V_82 , struct V_109 * V_110 )
{
const struct V_111 * V_112 ;
struct V_81 V_113 ;
struct V_114 V_115 ;
struct V_17 * V_18 ;
T_2 V_19 ;
int V_39 ;
V_39 = F_59 ( V_82 , V_110 , & V_115 ) ;
if ( V_39 )
return V_39 ;
V_18 = V_115 . V_18 ;
V_19 = V_115 . V_19 ;
switch ( V_110 -> V_116 ) {
case V_117 :
V_113 . V_83 = V_84 ;
V_113 . V_85 = F_43 ( V_84 ) ;
V_113 . V_97 = 0 ;
break;
case V_118 : {
V_113 . V_83 = V_100 ;
V_113 . V_85 = F_43 ( V_100 ) ;
V_113 . V_97 = 0 ;
break;
}
case V_119 : {
T_1 V_4 , V_120 ;
V_120 = ( V_110 -> V_110 & V_121 ) ;
return F_60 ( V_18 , 0 , V_120 , & V_4 ) ;
}
default:
return - V_122 ;
}
if ( V_19 & 3 )
return - V_122 ;
V_112 = F_61 ( V_18 , & V_113 , V_19 , sizeof( T_3 ) ) ;
if ( ! V_112 )
return - V_122 ;
return 0 ;
}
static int F_62 ( T_1 V_123 , T_4 V_124 , struct V_17 * V_18 )
{
unsigned long V_125 ;
int V_126 ;
V_125 = F_22 ( V_18 ) ;
V_126 = F_63 ( V_125 , 0 ) ;
V_125 &= ~ V_127 ;
if ( V_123 != V_125 )
return - 1 ;
if ( ! ( V_124 & F_64 ( V_126 ) ) )
return - 1 ;
return V_126 ;
}
void F_65 ( struct V_17 * V_18 , T_1 V_4 )
{
struct V_9 * V_9 = V_18 -> V_9 ;
struct V_17 * V_128 ;
T_4 V_129 ;
T_1 V_40 ;
int V_130 , V_106 ;
int V_47 = V_18 -> V_47 ;
bool V_131 ;
V_130 = ( V_4 & V_132 ) >> V_133 ;
V_131 = V_4 & F_66 ( V_134 ) ;
V_129 = ( V_4 & V_135 ) >> V_136 ;
V_40 = F_67 ( V_4 , 3 ) ;
V_40 |= F_67 ( V_4 , 2 ) ;
V_40 |= F_67 ( V_4 , 1 ) ;
F_54 (c, c_vcpu, kvm) {
struct V_37 * V_38 ;
if ( ! V_131 && V_129 == 0 )
break;
if ( V_131 && V_106 == V_47 )
continue;
if ( ! V_131 ) {
int V_126 ;
V_126 = F_62 ( V_40 , V_129 , V_128 ) ;
if ( V_126 == - 1 )
continue;
V_129 &= ~ F_64 ( V_126 ) ;
}
V_38 = F_10 ( V_18 -> V_9 , V_128 , V_130 ) ;
F_14 ( & V_38 -> V_41 ) ;
V_38 -> V_53 = true ;
F_29 ( V_18 -> V_9 , V_38 ) ;
F_12 ( V_18 -> V_9 , V_38 ) ;
}
}
int F_68 ( struct V_17 * V_18 , bool V_137 ,
int V_2 , T_3 * V_6 )
{
struct V_81 V_82 = {
. V_83 = V_84 ,
. V_85 = F_43 ( V_84 ) ,
} ;
return F_69 ( V_18 , & V_82 , V_137 , V_2 , V_6 ) ;
}
int F_70 ( struct V_17 * V_18 , bool V_137 ,
int V_2 , T_3 * V_6 )
{
struct V_81 V_88 = {
. V_83 = V_100 ,
. V_85 = F_43 ( V_100 ) ,
} ;
struct V_81 V_90 = {
. V_83 = V_104 ,
. V_85 = F_43 ( V_104 ) ,
} ;
if ( V_2 >= V_87 )
return F_69 ( V_18 , & V_90 , V_137 , V_2 - V_87 ,
V_6 ) ;
else
return F_69 ( V_18 , & V_88 , V_137 , V_2 , V_6 ) ;
}
int F_71 ( struct V_17 * V_18 , bool V_137 ,
T_3 V_36 , T_1 * V_6 )
{
if ( V_36 % 32 )
return - V_95 ;
if ( V_137 )
F_72 ( V_18 , V_36 , * V_6 ) ;
else
* V_6 = F_73 ( V_18 , V_36 ) ;
return 0 ;
}
