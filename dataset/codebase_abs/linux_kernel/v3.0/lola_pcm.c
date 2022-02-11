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
F_16 (KERN_WARNING SFX L_1 , str->dsd) ;
}
static int F_17 ( struct V_4 * V_5 ,
struct V_8 * V_18 ,
bool V_32 )
{
unsigned int V_19 = V_32 ? V_33 : 0 ;
unsigned long V_29 = V_30 + F_13 ( 200 ) ;
while ( F_14 ( V_30 , V_29 ) ) {
unsigned int V_34 = F_8 ( V_5 , V_18 -> V_20 , V_21 ) ;
if ( ( V_34 & V_33 ) == V_19 )
return 0 ;
F_15 ( 1 ) ;
}
F_16 (KERN_WARNING SFX L_2 , str->dsd) ;
return - V_35 ;
}
static int F_18 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
bool V_32 )
{
unsigned int V_19 = V_32 ? V_33 : 0 ;
unsigned long V_29 = V_30 + F_13 ( 200 ) ;
struct V_2 * V_36 ;
int V_37 = 0 ;
while ( F_14 ( V_30 , V_29 ) ) {
V_37 = 0 ;
F_19 (s, substream) {
struct V_8 * V_18 ;
if ( V_36 -> V_6 -> V_38 != V_3 -> V_6 -> V_38 )
continue;
V_18 = F_3 ( V_36 ) ;
if ( V_18 -> V_39 && V_18 -> V_40 ) {
unsigned int V_34 ;
V_34 = F_8 ( V_5 , V_18 -> V_20 , V_21 ) ;
if ( ( V_34 & V_33 ) != V_19 ) {
V_37 = V_18 -> V_20 + 1 ;
break;
}
if ( V_32 )
V_18 -> V_40 = 0 ;
}
}
if ( ! V_37 )
return 0 ;
F_15 ( 1 ) ;
}
F_16 (KERN_WARNING SFX L_3 , pending - 1 ) ;
return - V_35 ;
}
static void F_20 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
struct V_2 * V_36 ;
F_18 ( V_5 , V_3 , false ) ;
F_19 (s, substream) {
struct V_8 * V_18 ;
if ( V_36 -> V_6 -> V_38 != V_3 -> V_6 -> V_38 )
continue;
V_18 = F_3 ( V_36 ) ;
if ( V_18 -> V_40 && V_18 -> V_39 )
F_9 ( V_5 , V_18 -> V_20 , V_24 , V_25 |
V_26 | V_27 ) ;
}
F_18 ( V_5 , V_3 , true ) ;
}
static void F_21 ( struct V_4 * V_5 , struct V_8 * V_18 )
{
if ( V_18 -> V_39 ) {
if ( V_18 -> V_40 )
F_20 ( V_5 , V_18 -> V_3 ) ;
V_18 -> V_39 = 0 ;
F_9 ( V_5 , V_18 -> V_20 , V_24 ,
V_26 | V_27 ) ;
F_17 ( V_5 , V_18 , false ) ;
F_7 ( V_5 , V_18 ) ;
F_9 ( V_5 , V_18 -> V_20 , V_24 , V_31 ) ;
F_9 ( V_5 , V_18 -> V_20 , V_41 , 0 ) ;
F_9 ( V_5 , V_18 -> V_20 , V_42 , 0 ) ;
F_9 ( V_5 , V_18 -> V_20 , V_43 , 0 ) ;
F_12 ( V_5 , V_18 ) ;
}
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_8 * V_18 = F_3 ( V_3 ) ;
struct V_44 * V_45 = V_3 -> V_45 ;
F_23 ( & V_5 -> V_46 ) ;
if ( V_18 -> V_47 ) {
F_24 ( & V_5 -> V_46 ) ;
return - V_48 ;
}
V_18 -> V_3 = V_3 ;
V_18 -> V_49 = NULL ;
V_18 -> V_47 = 1 ;
V_45 -> V_50 = V_51 ;
V_45 -> V_50 . V_52 = V_6 -> V_53 - V_18 -> V_54 ;
if ( V_5 -> V_55 ) {
V_45 -> V_50 . V_56 = V_5 -> V_55 ;
V_45 -> V_50 . V_57 = V_5 -> V_55 ;
} else {
V_45 -> V_50 . V_56 = V_5 -> V_58 ;
V_45 -> V_50 . V_57 = V_5 -> V_59 ;
}
V_5 -> V_60 ++ ;
F_25 ( V_45 , V_61 ) ;
F_26 ( V_45 , 0 , V_62 ,
V_5 -> V_16 ) ;
F_26 ( V_45 , 0 , V_63 ,
V_5 -> V_16 ) ;
F_24 ( & V_5 -> V_46 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_6 ,
struct V_8 * V_18 )
{
int V_64 ;
for ( V_64 = V_18 -> V_54 + 1 ; V_64 < V_6 -> V_53 ; V_64 ++ ) {
struct V_8 * V_36 = & V_6 -> V_11 [ V_64 ] ;
if ( V_36 -> V_49 != V_18 )
break;
V_36 -> V_49 = NULL ;
V_36 -> V_47 = 0 ;
}
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_8 * V_18 = F_3 ( V_3 ) ;
F_23 ( & V_5 -> V_46 ) ;
if ( V_18 -> V_3 == V_3 ) {
V_18 -> V_3 = NULL ;
V_18 -> V_47 = 0 ;
}
if ( -- V_5 -> V_60 == 0 ) {
V_5 -> V_55 = 0 ;
}
F_24 ( & V_5 -> V_46 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_65 * V_66 )
{
struct V_8 * V_18 = F_3 ( V_3 ) ;
V_18 -> V_67 = 0 ;
V_18 -> V_68 = 0 ;
V_18 -> V_69 = 0 ;
return F_30 ( V_3 ,
F_31 ( V_66 ) ) ;
}
static int F_32 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_8 * V_18 = F_3 ( V_3 ) ;
F_23 ( & V_5 -> V_46 ) ;
F_21 ( V_5 , V_18 ) ;
F_27 ( V_6 , V_18 ) ;
F_24 ( & V_5 -> V_46 ) ;
return F_33 ( V_3 ) ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_8 * V_18 , T_1 * * V_70 ,
int V_71 , int V_72 )
{
T_1 * V_73 = * V_70 ;
while ( V_72 > 0 ) {
T_2 V_74 ;
int V_75 ;
if ( V_18 -> V_76 >= V_77 )
return - V_78 ;
V_74 = F_35 ( V_3 , V_71 ) ;
V_73 [ 0 ] = F_36 ( ( T_1 ) V_74 ) ;
V_73 [ 1 ] = F_36 ( F_37 ( V_74 ) ) ;
V_75 = F_38 ( V_3 , V_71 , V_72 ) ;
V_73 [ 2 ] = F_36 ( V_75 ) ;
V_72 -= V_75 ;
V_73 [ 3 ] = V_72 ? 0 : F_36 ( 0x01 ) ;
V_73 += 4 ;
V_18 -> V_76 ++ ;
V_71 += V_75 ;
}
* V_70 = V_73 ;
return V_71 ;
}
static int F_39 ( struct V_4 * V_5 , struct V_1 * V_6 ,
struct V_2 * V_3 ,
struct V_8 * V_18 )
{
T_1 * V_73 ;
int V_64 , V_71 , V_79 , V_68 ;
V_68 = V_18 -> V_68 ;
V_79 = V_18 -> V_67 / V_68 ;
V_73 = ( T_1 * ) ( V_6 -> V_73 . V_80 + V_81 * V_18 -> V_54 ) ;
V_71 = 0 ;
V_18 -> V_76 = 0 ;
for ( V_64 = 0 ; V_64 < V_79 ; V_64 ++ ) {
V_71 = F_34 ( V_3 , V_18 , & V_73 , V_71 , V_68 ) ;
if ( V_71 < 0 )
goto error;
}
return 0 ;
error:
F_40 (KERN_ERR SFX L_4 ,
str->bufsize, period_bytes) ;
return - V_78 ;
}
static unsigned int F_41 ( struct V_2 * V_3 )
{
unsigned int V_82 ;
switch ( V_3 -> V_45 -> V_83 ) {
case V_84 :
V_82 = 0x00000000 ;
break;
case V_85 :
V_82 = 0x00000200 ;
break;
case V_86 :
V_82 = 0x00000300 ;
break;
case V_87 :
V_82 = 0x00001300 ;
break;
default:
return 0 ;
}
V_82 |= V_3 -> V_45 -> V_88 ;
return V_82 ;
}
static int F_42 ( struct V_4 * V_5 ,
struct V_8 * V_18 ,
int V_88 )
{
int V_64 , V_89 ;
unsigned int V_82 , V_19 ;
V_89 = F_43 ( V_5 , V_18 -> V_90 , V_91 ,
V_18 -> V_69 , 0 , & V_19 , NULL ) ;
if ( V_89 < 0 ) {
F_16 (KERN_ERR SFX L_5 ,
str->format_verb) ;
return V_89 ;
}
for ( V_64 = 0 ; V_64 < V_88 ; V_64 ++ ) {
V_82 = ( V_18 -> V_54 << 6 ) | V_64 ;
V_89 = F_43 ( V_5 , V_18 [ V_64 ] . V_90 ,
V_92 , 0 , V_82 ,
& V_19 , NULL ) ;
if ( V_89 < 0 ) {
F_16 (KERN_ERR SFX L_6 , i) ;
return V_89 ;
}
}
return 0 ;
}
static int F_44 ( struct V_4 * V_5 , struct V_1 * V_6 ,
struct V_8 * V_18 )
{
T_2 V_73 ;
if ( V_18 -> V_39 )
return - V_78 ;
V_73 = V_6 -> V_73 . V_74 + V_81 * V_18 -> V_54 ;
F_9 ( V_5 , V_18 -> V_20 , V_43 , ( T_1 ) V_73 ) ;
F_9 ( V_5 , V_18 -> V_20 , V_42 , F_37 ( V_73 ) ) ;
F_9 ( V_5 , V_18 -> V_20 , V_41 , V_18 -> V_76 - 1 ) ;
F_7 ( V_5 , V_18 ) ;
F_9 ( V_5 , V_18 -> V_20 , V_24 ,
V_26 | V_27 | V_25 ) ;
V_18 -> V_39 = 1 ;
return F_17 ( V_5 , V_18 , true ) ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_8 * V_18 = F_3 ( V_3 ) ;
struct V_44 * V_45 = V_3 -> V_45 ;
unsigned int V_67 , V_68 , V_69 ;
int V_64 , V_89 ;
F_23 ( & V_5 -> V_46 ) ;
F_21 ( V_5 , V_18 ) ;
F_27 ( V_6 , V_18 ) ;
if ( V_18 -> V_54 + V_45 -> V_88 > V_6 -> V_53 ) {
F_24 ( & V_5 -> V_46 ) ;
return - V_78 ;
}
for ( V_64 = 1 ; V_64 < V_45 -> V_88 ; V_64 ++ ) {
V_18 [ V_64 ] . V_49 = V_18 ;
V_18 [ V_64 ] . V_47 = 1 ;
}
F_24 ( & V_5 -> V_46 ) ;
V_67 = F_46 ( V_3 ) ;
V_68 = F_47 ( V_3 ) ;
V_69 = F_41 ( V_3 ) ;
V_18 -> V_67 = V_67 ;
V_18 -> V_68 = V_68 ;
V_18 -> V_69 = V_69 ;
V_89 = F_39 ( V_5 , V_6 , V_3 , V_18 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = F_48 ( V_5 , V_45 -> V_93 ) ;
if ( V_89 < 0 )
return V_89 ;
V_5 -> V_55 = V_45 -> V_93 ;
V_89 = F_42 ( V_5 , V_18 , V_45 -> V_88 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = F_44 ( V_5 , V_6 , V_18 ) ;
if ( V_89 < 0 ) {
F_21 ( V_5 , V_18 ) ;
return V_89 ;
}
return 0 ;
}
static int F_49 ( struct V_2 * V_3 , int V_94 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_8 * V_18 ;
struct V_2 * V_36 ;
unsigned int V_95 ;
unsigned int V_15 ;
bool V_96 ;
switch ( V_94 ) {
case V_97 :
case V_98 :
case V_99 :
V_95 = 1 ;
break;
case V_100 :
case V_101 :
case V_102 :
V_95 = 0 ;
break;
default:
return - V_78 ;
}
V_96 = ( V_95 && F_50 ( V_3 ) ) ;
V_15 = F_6 ( V_5 , ! V_96 ) ;
F_51 ( & V_5 -> V_103 ) ;
F_19 (s, substream) {
if ( V_36 -> V_6 -> V_38 != V_3 -> V_6 -> V_38 )
continue;
V_18 = F_3 ( V_36 ) ;
if ( V_95 )
F_10 ( V_5 , V_18 , V_15 ) ;
else
F_11 ( V_5 , V_18 , V_15 ) ;
V_18 -> V_104 = V_95 ;
V_18 -> V_40 = ! V_95 ;
F_52 ( V_36 , V_3 ) ;
}
F_53 ( & V_5 -> V_103 ) ;
return 0 ;
}
static T_3 F_54 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_8 * V_18 = F_3 ( V_3 ) ;
unsigned int V_105 = F_8 ( V_5 , V_18 -> V_20 , V_106 ) ;
if ( V_105 >= V_18 -> V_67 )
V_105 = 0 ;
return F_55 ( V_3 -> V_45 , V_105 ) ;
}
void F_56 ( struct V_4 * V_5 , struct V_1 * V_6 , unsigned int V_107 )
{
int V_64 ;
for ( V_64 = 0 ; V_107 && V_64 < V_6 -> V_53 ; V_64 ++ ) {
if ( V_107 & ( 1 << V_64 ) ) {
struct V_8 * V_18 = & V_6 -> V_11 [ V_64 ] ;
if ( V_18 -> V_3 && V_18 -> V_104 )
F_57 ( V_18 -> V_3 ) ;
V_107 &= ~ ( 1 << V_64 ) ;
}
}
}
int T_4 F_58 ( struct V_4 * V_5 )
{
struct V_108 * V_6 ;
int V_64 , V_89 ;
for ( V_64 = 0 ; V_64 < 2 ; V_64 ++ ) {
V_89 = F_59 ( V_109 ,
F_60 ( V_5 -> V_110 ) ,
V_111 , & V_5 -> V_6 [ V_64 ] . V_73 ) ;
if ( V_89 < 0 )
return V_89 ;
}
V_89 = F_61 ( V_5 -> V_38 , L_7 , 0 ,
V_5 -> V_6 [ V_112 ] . V_53 ,
V_5 -> V_6 [ V_113 ] . V_53 ,
& V_6 ) ;
if ( V_89 < 0 )
return V_89 ;
F_62 ( V_6 -> V_114 , L_7 , sizeof( V_6 -> V_114 ) ) ;
V_6 -> V_115 = V_5 ;
for ( V_64 = 0 ; V_64 < 2 ; V_64 ++ ) {
if ( V_5 -> V_6 [ V_64 ] . V_53 )
F_63 ( V_6 , V_64 , & V_116 ) ;
}
F_64 ( V_6 , V_117 ,
F_60 ( V_5 -> V_110 ) ,
1024 * 64 , 32 * 1024 * 1024 ) ;
return 0 ;
}
void F_65 ( struct V_4 * V_5 )
{
F_66 ( & V_5 -> V_6 [ 0 ] . V_73 ) ;
F_66 ( & V_5 -> V_6 [ 1 ] . V_73 ) ;
}
static int F_67 ( struct V_4 * V_5 , struct V_8 * V_18 ,
int V_9 , int V_90 , int V_118 )
{
unsigned int V_19 ;
int V_89 ;
V_18 -> V_90 = V_90 ;
V_18 -> V_54 = V_9 ;
V_18 -> V_20 = V_9 ;
if ( V_118 == V_119 )
V_18 -> V_20 += V_120 ;
V_89 = F_68 ( V_5 , V_90 , V_121 , & V_19 ) ;
if ( V_89 < 0 ) {
F_16 (KERN_ERR SFX L_8 , nid) ;
return V_89 ;
}
if ( V_118 == V_119 ) {
if ( ( V_19 & 0x00f00dff ) != 0x00000010 ) {
F_16 (KERN_ERR SFX L_9 ,
val, nid) ;
return - V_78 ;
}
} else {
if ( ( V_19 & 0x00f00cff ) != 0x00100010 ) {
F_16 (KERN_ERR SFX L_9 ,
val, nid) ;
return - V_78 ;
}
if ( ( V_19 & 0x00001200 ) == 0x00001200 )
V_5 -> V_122 |= ( 1 << V_9 ) ;
}
V_89 = F_68 ( V_5 , V_90 , V_123 , & V_19 ) ;
if ( V_89 < 0 ) {
F_16 (KERN_ERR SFX L_10 , nid) ;
return V_89 ;
}
V_19 &= 3 ;
if ( V_19 == 3 )
V_18 -> V_124 = true ;
if ( ! ( V_19 & 1 ) ) {
F_16 (KERN_ERR SFX L_11 , val, nid) ;
return - V_78 ;
}
return 0 ;
}
int T_4 F_69 ( struct V_4 * V_5 , int V_118 , int * V_125 )
{
struct V_1 * V_6 = & V_5 -> V_6 [ V_118 ] ;
int V_64 , V_90 , V_89 ;
V_90 = * V_125 ;
for ( V_64 = 0 ; V_64 < V_6 -> V_53 ; V_64 ++ , V_90 ++ ) {
V_89 = F_67 ( V_5 , & V_6 -> V_11 [ V_64 ] , V_64 , V_90 , V_118 ) ;
if ( V_89 < 0 )
return V_89 ;
}
* V_125 = V_90 ;
return 0 ;
}
