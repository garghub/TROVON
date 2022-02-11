static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return & V_5 -> V_6 [ V_3 -> V_7 ] ;
}
static struct V_8 * F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned int V_9 = V_3 -> V_10 ;
return & V_6 -> V_11 [ V_9 ] ;
}
static unsigned int F_4 ( struct V_4 * V_5 )
{
return F_5 ( V_5 , V_12 , V_13 ) ;
}
static unsigned int F_6 ( struct V_4 * V_5 , bool V_14 )
{
unsigned int V_15 = F_4 ( V_5 ) >> 8 ;
if ( V_5 -> V_16 ) {
unsigned int V_17 = V_14 ? 0 : 8 ;
V_15 += ( V_17 + 1 ) * V_5 -> V_16 - 1 ;
V_15 -= V_15 % V_5 -> V_16 ;
}
return V_15 << 8 ;
}
static void F_7 ( struct V_4 * V_5 ,
struct V_8 * V_18 )
{
unsigned int V_19 = F_8 ( V_5 , V_18 -> V_20 , V_21 ) ;
V_19 &= V_22 | V_23 ;
if ( V_19 )
F_9 ( V_5 , V_18 -> V_20 , V_21 , V_19 ) ;
}
static void F_10 ( struct V_4 * V_5 , struct V_8 * V_18 ,
unsigned int V_15 )
{
F_7 ( V_5 , V_18 ) ;
F_9 ( V_5 , V_18 -> V_20 , V_24 ,
V_25 |
V_26 |
V_27 |
V_28 |
V_15 ) ;
}
static void F_11 ( struct V_4 * V_5 , struct V_8 * V_18 ,
unsigned int V_15 )
{
F_9 ( V_5 , V_18 -> V_20 , V_24 ,
V_26 |
V_27 |
V_28 |
V_15 ) ;
F_7 ( V_5 , V_18 ) ;
}
static void F_12 ( struct V_4 * V_5 , struct V_8 * V_18 )
{
unsigned long V_29 = V_30 + F_13 ( 200 ) ;
while ( F_14 ( V_30 , V_29 ) ) {
unsigned int V_19 ;
V_19 = F_8 ( V_5 , V_18 -> V_20 , V_24 ) ;
if ( ! ( V_19 & V_31 ) )
return;
F_15 ( 1 ) ;
}
F_16 ( V_5 -> V_32 -> V_33 , L_1 , V_18 -> V_20 ) ;
}
static int F_17 ( struct V_4 * V_5 ,
struct V_8 * V_18 ,
bool V_34 )
{
unsigned int V_19 = V_34 ? V_35 : 0 ;
unsigned long V_29 = V_30 + F_13 ( 200 ) ;
while ( F_14 ( V_30 , V_29 ) ) {
unsigned int V_36 = F_8 ( V_5 , V_18 -> V_20 , V_21 ) ;
if ( ( V_36 & V_35 ) == V_19 )
return 0 ;
F_15 ( 1 ) ;
}
F_16 ( V_5 -> V_32 -> V_33 , L_2 , V_18 -> V_20 ) ;
return - V_37 ;
}
static int F_18 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
bool V_34 )
{
unsigned int V_19 = V_34 ? V_35 : 0 ;
unsigned long V_29 = V_30 + F_13 ( 200 ) ;
struct V_2 * V_38 ;
int V_39 = 0 ;
while ( F_14 ( V_30 , V_29 ) ) {
V_39 = 0 ;
F_19 (s, substream) {
struct V_8 * V_18 ;
if ( V_38 -> V_6 -> V_32 != V_3 -> V_6 -> V_32 )
continue;
V_18 = F_3 ( V_38 ) ;
if ( V_18 -> V_40 && V_18 -> V_41 ) {
unsigned int V_36 ;
V_36 = F_8 ( V_5 , V_18 -> V_20 , V_21 ) ;
if ( ( V_36 & V_35 ) != V_19 ) {
V_39 = V_18 -> V_20 + 1 ;
break;
}
if ( V_34 )
V_18 -> V_41 = 0 ;
}
}
if ( ! V_39 )
return 0 ;
F_15 ( 1 ) ;
}
F_16 ( V_5 -> V_32 -> V_33 , L_3 , V_39 - 1 ) ;
return - V_37 ;
}
static void F_20 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
struct V_2 * V_38 ;
F_18 ( V_5 , V_3 , false ) ;
F_19 (s, substream) {
struct V_8 * V_18 ;
if ( V_38 -> V_6 -> V_32 != V_3 -> V_6 -> V_32 )
continue;
V_18 = F_3 ( V_38 ) ;
if ( V_18 -> V_41 && V_18 -> V_40 )
F_9 ( V_5 , V_18 -> V_20 , V_24 , V_25 |
V_26 | V_27 ) ;
}
F_18 ( V_5 , V_3 , true ) ;
}
static void F_21 ( struct V_4 * V_5 , struct V_8 * V_18 )
{
if ( V_18 -> V_40 ) {
if ( V_18 -> V_41 )
F_20 ( V_5 , V_18 -> V_3 ) ;
V_18 -> V_40 = 0 ;
F_9 ( V_5 , V_18 -> V_20 , V_24 ,
V_26 | V_27 ) ;
F_17 ( V_5 , V_18 , false ) ;
F_7 ( V_5 , V_18 ) ;
F_9 ( V_5 , V_18 -> V_20 , V_24 , V_31 ) ;
F_9 ( V_5 , V_18 -> V_20 , V_42 , 0 ) ;
F_9 ( V_5 , V_18 -> V_20 , V_43 , 0 ) ;
F_9 ( V_5 , V_18 -> V_20 , V_44 , 0 ) ;
F_12 ( V_5 , V_18 ) ;
}
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_8 * V_18 = F_3 ( V_3 ) ;
struct V_45 * V_46 = V_3 -> V_46 ;
F_23 ( & V_5 -> V_47 ) ;
if ( V_18 -> V_48 ) {
F_24 ( & V_5 -> V_47 ) ;
return - V_49 ;
}
V_18 -> V_3 = V_3 ;
V_18 -> V_50 = NULL ;
V_18 -> V_48 = 1 ;
V_46 -> V_51 = V_52 ;
V_46 -> V_51 . V_53 = V_6 -> V_54 - V_18 -> V_55 ;
if ( V_5 -> V_56 ) {
V_46 -> V_51 . V_57 = V_5 -> V_56 ;
V_46 -> V_51 . V_58 = V_5 -> V_56 ;
} else {
V_46 -> V_51 . V_57 = V_5 -> V_59 ;
V_46 -> V_51 . V_58 = V_5 -> V_60 ;
}
V_5 -> V_61 ++ ;
F_25 ( V_46 , V_62 ) ;
F_26 ( V_46 , 0 , V_63 ,
V_5 -> V_16 ) ;
F_26 ( V_46 , 0 , V_64 ,
V_5 -> V_16 ) ;
F_24 ( & V_5 -> V_47 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_6 ,
struct V_8 * V_18 )
{
int V_65 ;
for ( V_65 = V_18 -> V_55 + 1 ; V_65 < V_6 -> V_54 ; V_65 ++ ) {
struct V_8 * V_38 = & V_6 -> V_11 [ V_65 ] ;
if ( V_38 -> V_50 != V_18 )
break;
V_38 -> V_50 = NULL ;
V_38 -> V_48 = 0 ;
}
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_8 * V_18 = F_3 ( V_3 ) ;
F_23 ( & V_5 -> V_47 ) ;
if ( V_18 -> V_3 == V_3 ) {
V_18 -> V_3 = NULL ;
V_18 -> V_48 = 0 ;
}
if ( -- V_5 -> V_61 == 0 ) {
V_5 -> V_56 = 0 ;
}
F_24 ( & V_5 -> V_47 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_66 * V_67 )
{
struct V_8 * V_18 = F_3 ( V_3 ) ;
V_18 -> V_68 = 0 ;
V_18 -> V_69 = 0 ;
V_18 -> V_70 = 0 ;
return F_30 ( V_3 ,
F_31 ( V_67 ) ) ;
}
static int F_32 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_8 * V_18 = F_3 ( V_3 ) ;
F_23 ( & V_5 -> V_47 ) ;
F_21 ( V_5 , V_18 ) ;
F_27 ( V_6 , V_18 ) ;
F_24 ( & V_5 -> V_47 ) ;
return F_33 ( V_3 ) ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_8 * V_18 , T_1 * * V_71 ,
int V_72 , int V_73 )
{
T_1 * V_74 = * V_71 ;
while ( V_73 > 0 ) {
T_2 V_75 ;
int V_76 ;
if ( V_18 -> V_77 >= V_78 )
return - V_79 ;
V_75 = F_35 ( V_3 , V_72 ) ;
V_74 [ 0 ] = F_36 ( ( T_1 ) V_75 ) ;
V_74 [ 1 ] = F_36 ( F_37 ( V_75 ) ) ;
V_76 = F_38 ( V_3 , V_72 , V_73 ) ;
V_74 [ 2 ] = F_36 ( V_76 ) ;
V_73 -= V_76 ;
V_74 [ 3 ] = V_73 ? 0 : F_36 ( 0x01 ) ;
V_74 += 4 ;
V_18 -> V_77 ++ ;
V_72 += V_76 ;
}
* V_71 = V_74 ;
return V_72 ;
}
static int F_39 ( struct V_4 * V_5 , struct V_1 * V_6 ,
struct V_2 * V_3 ,
struct V_8 * V_18 )
{
T_1 * V_74 ;
int V_65 , V_72 , V_80 , V_69 ;
V_69 = V_18 -> V_69 ;
V_80 = V_18 -> V_68 / V_69 ;
V_74 = ( T_1 * ) ( V_6 -> V_74 . V_81 + V_82 * V_18 -> V_55 ) ;
V_72 = 0 ;
V_18 -> V_77 = 0 ;
for ( V_65 = 0 ; V_65 < V_80 ; V_65 ++ ) {
V_72 = F_34 ( V_3 , V_18 , & V_74 , V_72 , V_69 ) ;
if ( V_72 < 0 )
goto error;
}
return 0 ;
error:
F_40 ( V_5 -> V_32 -> V_33 , L_4 ,
V_18 -> V_68 , V_69 ) ;
return - V_79 ;
}
static unsigned int F_41 ( struct V_2 * V_3 )
{
unsigned int V_83 ;
switch ( V_3 -> V_46 -> V_84 ) {
case V_85 :
V_83 = 0x00000000 ;
break;
case V_86 :
V_83 = 0x00000200 ;
break;
case V_87 :
V_83 = 0x00000300 ;
break;
case V_88 :
V_83 = 0x00001300 ;
break;
default:
return 0 ;
}
V_83 |= V_3 -> V_46 -> V_89 ;
return V_83 ;
}
static int F_42 ( struct V_4 * V_5 ,
struct V_8 * V_18 ,
int V_89 )
{
int V_65 , V_90 ;
unsigned int V_83 , V_19 ;
V_90 = F_43 ( V_5 , V_18 -> V_91 , V_92 ,
V_18 -> V_70 , 0 , & V_19 , NULL ) ;
if ( V_90 < 0 ) {
F_40 ( V_5 -> V_32 -> V_33 , L_5 ,
V_18 -> V_70 ) ;
return V_90 ;
}
for ( V_65 = 0 ; V_65 < V_89 ; V_65 ++ ) {
V_83 = ( V_18 -> V_55 << 6 ) | V_65 ;
V_90 = F_43 ( V_5 , V_18 [ V_65 ] . V_91 ,
V_93 , 0 , V_83 ,
& V_19 , NULL ) ;
if ( V_90 < 0 ) {
F_40 ( V_5 -> V_32 -> V_33 ,
L_6 , V_65 ) ;
return V_90 ;
}
}
return 0 ;
}
static int F_44 ( struct V_4 * V_5 , struct V_1 * V_6 ,
struct V_8 * V_18 )
{
T_2 V_74 ;
if ( V_18 -> V_40 )
return - V_79 ;
V_74 = V_6 -> V_74 . V_75 + V_82 * V_18 -> V_55 ;
F_9 ( V_5 , V_18 -> V_20 , V_44 , ( T_1 ) V_74 ) ;
F_9 ( V_5 , V_18 -> V_20 , V_43 , F_37 ( V_74 ) ) ;
F_9 ( V_5 , V_18 -> V_20 , V_42 , V_18 -> V_77 - 1 ) ;
F_7 ( V_5 , V_18 ) ;
F_9 ( V_5 , V_18 -> V_20 , V_24 ,
V_26 | V_27 | V_25 ) ;
V_18 -> V_40 = 1 ;
return F_17 ( V_5 , V_18 , true ) ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_8 * V_18 = F_3 ( V_3 ) ;
struct V_45 * V_46 = V_3 -> V_46 ;
unsigned int V_68 , V_69 , V_70 ;
int V_65 , V_90 ;
F_23 ( & V_5 -> V_47 ) ;
F_21 ( V_5 , V_18 ) ;
F_27 ( V_6 , V_18 ) ;
if ( V_18 -> V_55 + V_46 -> V_89 > V_6 -> V_54 ) {
F_24 ( & V_5 -> V_47 ) ;
return - V_79 ;
}
for ( V_65 = 1 ; V_65 < V_46 -> V_89 ; V_65 ++ ) {
V_18 [ V_65 ] . V_50 = V_18 ;
V_18 [ V_65 ] . V_48 = 1 ;
}
F_24 ( & V_5 -> V_47 ) ;
V_68 = F_46 ( V_3 ) ;
V_69 = F_47 ( V_3 ) ;
V_70 = F_41 ( V_3 ) ;
V_18 -> V_68 = V_68 ;
V_18 -> V_69 = V_69 ;
V_18 -> V_70 = V_70 ;
V_90 = F_39 ( V_5 , V_6 , V_3 , V_18 ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = F_48 ( V_5 , V_46 -> V_94 ) ;
if ( V_90 < 0 )
return V_90 ;
V_5 -> V_56 = V_46 -> V_94 ;
V_90 = F_42 ( V_5 , V_18 , V_46 -> V_89 ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = F_44 ( V_5 , V_6 , V_18 ) ;
if ( V_90 < 0 ) {
F_21 ( V_5 , V_18 ) ;
return V_90 ;
}
return 0 ;
}
static int F_49 ( struct V_2 * V_3 , int V_95 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_8 * V_18 ;
struct V_2 * V_38 ;
unsigned int V_96 ;
unsigned int V_15 ;
bool V_97 ;
switch ( V_95 ) {
case V_98 :
case V_99 :
case V_100 :
V_96 = 1 ;
break;
case V_101 :
case V_102 :
case V_103 :
V_96 = 0 ;
break;
default:
return - V_79 ;
}
V_97 = ( V_96 && F_50 ( V_3 ) ) ;
V_15 = F_6 ( V_5 , ! V_97 ) ;
F_51 ( & V_5 -> V_104 ) ;
F_19 (s, substream) {
if ( V_38 -> V_6 -> V_32 != V_3 -> V_6 -> V_32 )
continue;
V_18 = F_3 ( V_38 ) ;
if ( V_96 )
F_10 ( V_5 , V_18 , V_15 ) ;
else
F_11 ( V_5 , V_18 , V_15 ) ;
V_18 -> V_105 = V_96 ;
V_18 -> V_41 = ! V_96 ;
F_52 ( V_38 , V_3 ) ;
}
F_53 ( & V_5 -> V_104 ) ;
return 0 ;
}
static T_3 F_54 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_8 * V_18 = F_3 ( V_3 ) ;
unsigned int V_106 = F_8 ( V_5 , V_18 -> V_20 , V_107 ) ;
if ( V_106 >= V_18 -> V_68 )
V_106 = 0 ;
return F_55 ( V_3 -> V_46 , V_106 ) ;
}
void F_56 ( struct V_4 * V_5 , struct V_1 * V_6 , unsigned int V_108 )
{
int V_65 ;
for ( V_65 = 0 ; V_108 && V_65 < V_6 -> V_54 ; V_65 ++ ) {
if ( V_108 & ( 1 << V_65 ) ) {
struct V_8 * V_18 = & V_6 -> V_11 [ V_65 ] ;
if ( V_18 -> V_3 && V_18 -> V_105 )
F_57 ( V_18 -> V_3 ) ;
V_108 &= ~ ( 1 << V_65 ) ;
}
}
}
int F_58 ( struct V_4 * V_5 )
{
struct V_109 * V_6 ;
int V_65 , V_90 ;
for ( V_65 = 0 ; V_65 < 2 ; V_65 ++ ) {
V_90 = F_59 ( V_110 ,
F_60 ( V_5 -> V_111 ) ,
V_112 , & V_5 -> V_6 [ V_65 ] . V_74 ) ;
if ( V_90 < 0 )
return V_90 ;
}
V_90 = F_61 ( V_5 -> V_32 , L_7 , 0 ,
V_5 -> V_6 [ V_113 ] . V_54 ,
V_5 -> V_6 [ V_114 ] . V_54 ,
& V_6 ) ;
if ( V_90 < 0 )
return V_90 ;
F_62 ( V_6 -> V_115 , L_7 , sizeof( V_6 -> V_115 ) ) ;
V_6 -> V_116 = V_5 ;
for ( V_65 = 0 ; V_65 < 2 ; V_65 ++ ) {
if ( V_5 -> V_6 [ V_65 ] . V_54 )
F_63 ( V_6 , V_65 , & V_117 ) ;
}
F_64 ( V_6 , V_118 ,
F_60 ( V_5 -> V_111 ) ,
1024 * 64 , 32 * 1024 * 1024 ) ;
return 0 ;
}
void F_65 ( struct V_4 * V_5 )
{
F_66 ( & V_5 -> V_6 [ 0 ] . V_74 ) ;
F_66 ( & V_5 -> V_6 [ 1 ] . V_74 ) ;
}
static int F_67 ( struct V_4 * V_5 , struct V_8 * V_18 ,
int V_9 , int V_91 , int V_119 )
{
unsigned int V_19 ;
int V_90 ;
V_18 -> V_91 = V_91 ;
V_18 -> V_55 = V_9 ;
V_18 -> V_20 = V_9 ;
if ( V_119 == V_120 )
V_18 -> V_20 += V_121 ;
V_90 = F_68 ( V_5 , V_91 , V_122 , & V_19 ) ;
if ( V_90 < 0 ) {
F_40 ( V_5 -> V_32 -> V_33 , L_8 , V_91 ) ;
return V_90 ;
}
if ( V_119 == V_120 ) {
if ( ( V_19 & 0x00f00dff ) != 0x00000010 ) {
F_40 ( V_5 -> V_32 -> V_33 ,
L_9 ,
V_19 , V_91 ) ;
return - V_79 ;
}
} else {
if ( ( V_19 & 0x00f00cff ) != 0x00100010 ) {
F_40 ( V_5 -> V_32 -> V_33 ,
L_9 ,
V_19 , V_91 ) ;
return - V_79 ;
}
if ( ( V_19 & 0x00001200 ) == 0x00001200 )
V_5 -> V_123 |= ( 1 << V_9 ) ;
}
V_90 = F_68 ( V_5 , V_91 , V_124 , & V_19 ) ;
if ( V_90 < 0 ) {
F_40 ( V_5 -> V_32 -> V_33 , L_10 , V_91 ) ;
return V_90 ;
}
V_19 &= 3 ;
if ( V_19 == 3 )
V_18 -> V_125 = true ;
if ( ! ( V_19 & 1 ) ) {
F_40 ( V_5 -> V_32 -> V_33 ,
L_11 , V_19 , V_91 ) ;
return - V_79 ;
}
return 0 ;
}
int F_69 ( struct V_4 * V_5 , int V_119 , int * V_126 )
{
struct V_1 * V_6 = & V_5 -> V_6 [ V_119 ] ;
int V_65 , V_91 , V_90 ;
V_91 = * V_126 ;
for ( V_65 = 0 ; V_65 < V_6 -> V_54 ; V_65 ++ , V_91 ++ ) {
V_90 = F_67 ( V_5 , & V_6 -> V_11 [ V_65 ] , V_65 , V_91 , V_119 ) ;
if ( V_90 < 0 )
return V_90 ;
}
* V_126 = V_91 ;
return 0 ;
}
