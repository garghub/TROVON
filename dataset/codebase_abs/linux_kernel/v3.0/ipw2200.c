static int F_1 ( char * V_1 , T_1 V_2 ,
const T_2 * V_3 , T_3 V_4 , T_3 V_5 )
{
int V_6 , V_7 , V_8 , V_9 ;
char V_10 ;
V_6 = snprintf ( V_1 , V_2 , L_1 , V_5 ) ;
for ( V_9 = 0 , V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
V_6 += snprintf ( V_1 + V_6 , V_2 - V_6 , L_2 ) ;
for ( V_8 = 0 ; V_8 < 8 && V_9 < V_4 ; V_8 ++ , V_9 ++ )
V_6 += snprintf ( V_1 + V_6 , V_2 - V_6 , L_3 ,
V_3 [ ( V_7 * 8 + V_8 ) ] ) ;
for (; V_8 < 8 ; V_8 ++ )
V_6 += snprintf ( V_1 + V_6 , V_2 - V_6 , L_4 ) ;
}
V_6 += snprintf ( V_1 + V_6 , V_2 - V_6 , L_2 ) ;
for ( V_9 = 0 , V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
V_6 += snprintf ( V_1 + V_6 , V_2 - V_6 , L_2 ) ;
for ( V_8 = 0 ; V_8 < 8 && V_9 < V_4 ; V_8 ++ , V_9 ++ ) {
V_10 = V_3 [ ( V_7 * 8 + V_8 ) ] ;
if ( ! isascii ( V_10 ) || ! isprint ( V_10 ) )
V_10 = '.' ;
V_6 += snprintf ( V_1 + V_6 , V_2 - V_6 , L_5 , V_10 ) ;
}
for (; V_8 < 8 ; V_8 ++ )
V_6 += snprintf ( V_1 + V_6 , V_2 - V_6 , L_2 ) ;
}
return V_6 ;
}
static void F_2 ( int V_11 , const T_2 * V_3 , T_3 V_4 )
{
char line [ 81 ] ;
T_3 V_5 = 0 ;
if ( ! ( V_12 & V_11 ) )
return;
while ( V_4 ) {
F_1 ( line , sizeof( line ) , & V_3 [ V_5 ] ,
F_3 ( V_4 , 16U ) , V_5 ) ;
F_4 ( V_13 L_6 , line ) ;
V_5 += 16 ;
V_4 -= F_3 ( V_4 , 16U ) ;
}
}
static int F_5 ( T_2 * V_14 , T_1 V_15 , const T_2 * V_3 , T_1 V_4 )
{
T_1 V_6 = V_15 ;
T_3 V_5 = 0 ;
int V_16 = 0 ;
while ( V_15 && V_4 ) {
V_6 = F_1 ( V_14 , V_15 , & V_3 [ V_5 ] ,
F_6 ( T_1 , V_4 , 16U ) , V_5 ) ;
V_5 += 16 ;
V_14 += V_6 ;
V_15 -= V_6 ;
V_4 -= F_6 ( T_1 , V_4 , 16U ) ;
V_16 += V_6 ;
}
return V_16 ;
}
static inline void F_7 ( struct V_17 * V_18 , T_3 V_19 , T_2 V_10 )
{
F_8 ( L_7 , __FILE__ ,
__LINE__ , ( T_3 ) ( V_19 ) , ( T_3 ) ( V_10 ) ) ;
F_9 ( V_18 , V_19 , V_10 ) ;
}
static inline void F_10 ( struct V_17 * V_18 , T_3 V_19 , T_4 V_10 )
{
F_8 ( L_8 , __FILE__ ,
__LINE__ , ( T_3 ) ( V_19 ) , ( T_3 ) ( V_10 ) ) ;
F_11 ( V_18 , V_19 , V_10 ) ;
}
static inline void F_12 ( struct V_17 * V_18 , T_3 V_19 , T_3 V_10 )
{
F_8 ( L_9 , __FILE__ ,
__LINE__ , ( T_3 ) ( V_19 ) , ( T_3 ) ( V_10 ) ) ;
F_13 ( V_18 , V_19 , V_10 ) ;
}
static inline void F_14 ( struct V_17 * V_20 , unsigned long V_5 ,
T_2 V_21 )
{
F_15 ( V_21 , V_20 -> V_22 + V_5 ) ;
}
static inline void F_16 ( struct V_17 * V_20 , unsigned long V_5 ,
T_4 V_21 )
{
F_17 ( V_21 , V_20 -> V_22 + V_5 ) ;
}
static inline void F_18 ( struct V_17 * V_20 , unsigned long V_5 ,
T_3 V_21 )
{
F_19 ( V_21 , V_20 -> V_22 + V_5 ) ;
}
static inline T_2 F_20 ( struct V_17 * V_20 , unsigned long V_5 )
{
return F_21 ( V_20 -> V_22 + V_5 ) ;
}
static inline T_4 F_22 ( struct V_17 * V_20 , unsigned long V_5 )
{
return F_23 ( V_20 -> V_22 + V_5 ) ;
}
static inline T_3 F_24 ( struct V_17 * V_20 , unsigned long V_5 )
{
return F_25 ( V_20 -> V_22 + V_5 ) ;
}
static void F_13 ( struct V_17 * V_23 , T_3 V_24 , T_3 V_25 )
{
F_8 ( L_10 , V_23 , V_24 , V_25 ) ;
F_18 ( V_23 , V_26 , V_24 ) ;
F_18 ( V_23 , V_27 , V_25 ) ;
}
static void F_9 ( struct V_17 * V_23 , T_3 V_24 , T_2 V_25 )
{
T_3 V_28 = V_24 & V_29 ;
T_3 V_30 = V_24 - V_28 ;
F_8 ( L_11 , V_24 , V_25 ) ;
F_18 ( V_23 , V_26 , V_28 ) ;
F_14 ( V_23 , V_27 + V_30 , V_25 ) ;
}
static void F_11 ( struct V_17 * V_23 , T_3 V_24 , T_4 V_25 )
{
T_3 V_28 = V_24 & V_29 ;
T_3 V_30 = ( V_24 - V_28 ) & ( ~ 0x1ul ) ;
F_8 ( L_11 , V_24 , V_25 ) ;
F_18 ( V_23 , V_26 , V_28 ) ;
F_16 ( V_23 , V_27 + V_30 , V_25 ) ;
}
static T_2 F_26 ( struct V_17 * V_23 , T_3 V_24 )
{
T_3 V_31 ;
F_18 ( V_23 , V_26 , V_24 & V_29 ) ;
F_8 ( L_12 , V_24 ) ;
V_31 = F_24 ( V_23 , V_27 ) ;
return ( V_31 >> ( ( V_24 & 0x3 ) * 8 ) ) & 0xff ;
}
static T_3 F_27 ( struct V_17 * V_23 , T_3 V_24 )
{
T_3 V_25 ;
F_8 ( L_13 , V_23 , V_24 ) ;
F_18 ( V_23 , V_26 , V_24 ) ;
V_25 = F_24 ( V_23 , V_27 ) ;
F_8 ( L_14 , V_24 , V_25 ) ;
return V_25 ;
}
static void F_28 ( struct V_17 * V_23 , T_3 V_32 , T_2 * V_1 ,
int V_33 )
{
T_3 V_28 = V_32 & V_29 ;
T_3 V_30 = V_32 - V_28 ;
T_3 V_7 ;
F_8 ( L_15 , V_32 , V_1 , V_33 ) ;
if ( V_33 <= 0 ) {
return;
}
if ( F_29 ( V_30 ) ) {
F_18 ( V_23 , V_26 , V_28 ) ;
for ( V_7 = V_30 ; ( ( V_7 < 4 ) && ( V_33 > 0 ) ) ; V_7 ++ , V_33 -- )
* V_1 ++ = F_20 ( V_23 , V_27 + V_7 ) ;
V_28 += 4 ;
}
F_18 ( V_23 , V_34 , V_28 ) ;
for (; V_33 >= 4 ; V_1 += 4 , V_28 += 4 , V_33 -= 4 )
* ( T_3 * ) V_1 = F_24 ( V_23 , V_35 ) ;
if ( F_29 ( V_33 ) ) {
F_18 ( V_23 , V_26 , V_28 ) ;
for ( V_7 = 0 ; V_33 > 0 ; V_7 ++ , V_33 -- )
* V_1 ++ = F_30 ( V_23 , V_27 + V_7 ) ;
}
}
static void F_31 ( struct V_17 * V_23 , T_3 V_32 , T_2 * V_1 ,
int V_33 )
{
T_3 V_28 = V_32 & V_29 ;
T_3 V_30 = V_32 - V_28 ;
T_3 V_7 ;
F_8 ( L_15 , V_32 , V_1 , V_33 ) ;
if ( V_33 <= 0 ) {
return;
}
if ( F_29 ( V_30 ) ) {
F_18 ( V_23 , V_26 , V_28 ) ;
for ( V_7 = V_30 ; ( ( V_7 < 4 ) && ( V_33 > 0 ) ) ; V_7 ++ , V_33 -- , V_1 ++ )
F_14 ( V_23 , V_27 + V_7 , * V_1 ) ;
V_28 += 4 ;
}
F_18 ( V_23 , V_34 , V_28 ) ;
for (; V_33 >= 4 ; V_1 += 4 , V_28 += 4 , V_33 -= 4 )
F_18 ( V_23 , V_35 , * ( T_3 * ) V_1 ) ;
if ( F_29 ( V_33 ) ) {
F_18 ( V_23 , V_26 , V_28 ) ;
for ( V_7 = 0 ; V_33 > 0 ; V_7 ++ , V_33 -- , V_1 ++ )
F_14 ( V_23 , V_27 + V_7 , * V_1 ) ;
}
}
static void F_32 ( struct V_17 * V_23 , T_3 V_32 , void * V_1 ,
int V_33 )
{
F_33 ( ( V_23 -> V_22 + V_32 ) , V_1 , V_33 ) ;
}
static inline void F_34 ( struct V_17 * V_23 , T_3 V_24 , T_3 V_36 )
{
F_35 ( V_23 , V_24 , F_36 ( V_23 , V_24 ) | V_36 ) ;
}
static inline void F_37 ( struct V_17 * V_23 , T_3 V_24 , T_3 V_36 )
{
F_35 ( V_23 , V_24 , F_36 ( V_23 , V_24 ) & ~ V_36 ) ;
}
static inline void F_38 ( struct V_17 * V_23 )
{
if ( V_23 -> V_37 & V_38 )
return;
V_23 -> V_37 |= V_38 ;
F_35 ( V_23 , V_39 , V_40 ) ;
}
static inline void F_39 ( struct V_17 * V_23 )
{
if ( ! ( V_23 -> V_37 & V_38 ) )
return;
V_23 -> V_37 &= ~ V_38 ;
F_35 ( V_23 , V_39 , ~ V_40 ) ;
}
static inline void F_40 ( struct V_17 * V_23 )
{
unsigned long V_41 ;
F_41 ( & V_23 -> V_42 , V_41 ) ;
F_38 ( V_23 ) ;
F_42 ( & V_23 -> V_42 , V_41 ) ;
}
static inline void F_43 ( struct V_17 * V_23 )
{
unsigned long V_41 ;
F_41 ( & V_23 -> V_42 , V_41 ) ;
F_39 ( V_23 ) ;
F_42 ( & V_23 -> V_42 , V_41 ) ;
}
static char * F_44 ( T_3 V_21 )
{
switch ( V_21 ) {
case V_43 :
return L_16 ;
case V_44 :
return L_17 ;
case V_45 :
return L_18 ;
case V_46 :
return L_19 ;
case V_47 :
return L_20 ;
case V_48 :
return L_21 ;
case V_49 :
return L_22 ;
case V_50 :
return L_23 ;
case V_51 :
return L_24 ;
case V_52 :
return L_25 ;
case V_53 :
return L_26 ;
case V_54 :
return L_27 ;
case V_55 :
return L_28 ;
case V_56 :
return L_29 ;
case V_57 :
return L_30 ;
default:
return L_31 ;
}
}
static void F_45 ( struct V_17 * V_23 ,
struct V_58 * error )
{
T_3 V_7 ;
if ( ! error ) {
F_46 ( L_32
L_33 ) ;
return;
}
F_46 ( L_34 ) ;
F_46 ( L_35 ,
error -> V_37 , error -> V_59 ) ;
for ( V_7 = 0 ; V_7 < error -> V_60 ; V_7 ++ )
F_46 ( L_36 ,
F_44 ( error -> V_61 [ V_7 ] . V_62 ) ,
error -> V_61 [ V_7 ] . time ,
error -> V_61 [ V_7 ] . V_63 ,
error -> V_61 [ V_7 ] . V_64 ,
error -> V_61 [ V_7 ] . V_65 ,
error -> V_61 [ V_7 ] . V_66 , error -> V_61 [ V_7 ] . V_3 ) ;
for ( V_7 = 0 ; V_7 < error -> V_67 ; V_7 ++ )
F_46 ( L_37 ,
error -> log [ V_7 ] . time ,
error -> log [ V_7 ] . V_3 , error -> log [ V_7 ] . V_68 ) ;
}
static inline int F_47 ( struct V_17 * V_23 )
{
return ( V_23 -> V_37 & V_69 ) ? 1 : 0 ;
}
static int F_48 ( struct V_17 * V_23 , T_3 V_70 , void * V_21 , T_3 * V_4 )
{
T_3 V_32 , V_71 , V_72 , V_73 , V_74 ;
F_49 ( L_38 , V_70 ) ;
if ( ! V_23 || ! V_21 || ! V_4 ) {
F_49 ( L_39 ) ;
return - V_75 ;
}
if ( ! V_23 -> V_76 || ! V_23 -> V_77 || ! V_23 -> V_78 ) {
F_49 ( L_40 ) ;
return - V_75 ;
}
switch ( V_79 & V_70 ) {
case V_80 :
V_70 &= V_81 ;
if ( V_70 > V_23 -> V_82 ) {
F_49 ( L_41
L_42 , V_70 , V_23 -> V_82 ) ;
return - V_75 ;
}
if ( * V_4 < sizeof( T_3 ) ) {
F_49 ( L_43
L_44 , sizeof( T_3 ) ) ;
return - V_75 ;
}
F_49 ( L_45 ,
V_70 , V_23 -> V_76 + ( V_70 << 2 ) ) ;
* V_4 = sizeof( T_3 ) ;
V_70 <<= 2 ;
* ( ( T_3 * ) V_21 ) = F_36 ( V_23 , V_23 -> V_76 + V_70 ) ;
break;
case V_83 :
V_70 &= V_81 ;
if ( V_70 > V_23 -> V_84 ) {
F_49 ( L_46 ) ;
return - V_75 ;
}
if ( * V_4 < sizeof( T_3 ) ) {
F_49 ( L_43
L_44 , sizeof( T_3 ) ) ;
return - V_75 ;
}
* ( ( T_3 * ) V_21 ) =
F_50 ( V_23 , ( V_23 -> V_77 + ( V_70 << 2 ) ) ) ;
* V_4 = sizeof( T_3 ) ;
break;
case V_85 :
V_70 &= V_81 ;
if ( V_70 > V_23 -> V_86 ) {
F_49 ( L_46 ) ;
return - V_75 ;
}
V_32 = F_50 ( V_23 , V_23 -> V_78 + ( V_70 << 3 ) ) ;
V_71 =
F_50 ( V_23 ,
V_23 -> V_78 + ( V_70 << 3 ) +
sizeof( T_3 ) ) ;
V_72 = * ( ( T_4 * ) & V_71 ) ;
V_73 = * ( ( ( T_4 * ) & V_71 ) + 1 ) ;
V_74 = V_72 * V_73 ;
if ( V_74 > * V_4 ) {
* V_4 = V_74 ;
return - V_75 ;
}
* V_4 = V_74 ;
if ( ! V_74 )
return 0 ;
F_49 ( L_47
L_48 ,
V_32 , V_74 , V_71 ) ;
F_51 ( V_23 , V_32 , V_21 , V_74 ) ;
break;
default:
F_49 ( L_49 ) ;
return - V_75 ;
}
return 0 ;
}
static void F_52 ( struct V_17 * V_23 )
{
V_23 -> V_76 = V_87 ;
V_23 -> V_82 = F_36 ( V_23 , V_23 -> V_76 ) ;
F_49 ( L_50 ,
V_23 -> V_76 , V_23 -> V_82 ) ;
V_23 -> V_77 = F_36 ( V_23 , V_88 ) ;
V_23 -> V_84 = F_50 ( V_23 , V_23 -> V_77 ) ;
F_49 ( L_51 ,
V_23 -> V_77 , V_23 -> V_84 ) ;
V_23 -> V_78 = F_36 ( V_23 , V_89 ) ;
V_23 -> V_86 = F_50 ( V_23 , V_23 -> V_78 ) ;
V_23 -> V_86 &= 0x0000ffff ;
F_49 ( L_52 ,
V_23 -> V_78 , V_23 -> V_86 ) ;
}
static T_3 F_53 ( T_3 V_24 )
{
V_24 &= ~ V_90 ;
if ( V_24 & V_91 )
V_24 &= ~ V_91 ;
if ( V_24 & V_92 )
V_24 &= ~ V_92 ;
if ( V_24 & V_93 )
V_24 &= ~ V_93 ;
return V_24 ;
}
static void F_54 ( struct V_17 * V_23 )
{
unsigned long V_41 ;
T_3 V_94 ;
if ( V_23 -> V_59 & V_95 || V_23 -> V_96 == V_97 )
return;
F_41 ( & V_23 -> V_98 , V_41 ) ;
if ( ! ( V_23 -> V_37 & V_99 ) &&
! ( V_23 -> V_37 & V_100 ) ) {
F_55 ( L_53 ) ;
V_94 = F_50 ( V_23 , V_101 ) ;
V_94 |= V_23 -> V_102 ;
V_94 = F_53 ( V_94 ) ;
F_55 ( L_54 , V_94 ) ;
F_12 ( V_23 , V_101 , V_94 ) ;
V_23 -> V_37 |= V_100 ;
if ( ! ( V_23 -> V_37 & V_103 ) )
F_56 ( & V_23 -> V_104 ,
V_105 ) ;
}
F_42 ( & V_23 -> V_98 , V_41 ) ;
}
static void F_57 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_108 . V_107 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_54 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_61 ( struct V_17 * V_23 )
{
unsigned long V_41 ;
T_3 V_94 ;
if ( V_23 -> V_59 & V_95 || V_23 -> V_96 == V_97 )
return;
F_41 ( & V_23 -> V_98 , V_41 ) ;
if ( V_23 -> V_37 & V_100 ) {
V_94 = F_50 ( V_23 , V_101 ) ;
V_94 &= V_23 -> V_110 ;
V_94 = F_53 ( V_94 ) ;
F_55 ( L_54 , V_94 ) ;
F_12 ( V_23 , V_101 , V_94 ) ;
F_55 ( L_55 ) ;
V_23 -> V_37 &= ~ V_100 ;
if ( ! ( V_23 -> V_37 & V_99 ) &&
! ( V_23 -> V_37 & V_103 ) )
F_56 ( & V_23 -> V_108 ,
V_111 ) ;
}
F_42 ( & V_23 -> V_98 , V_41 ) ;
}
static void F_62 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_104 . V_107 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_61 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_63 ( struct V_17 * V_23 )
{
T_3 V_94 ;
if ( V_23 -> V_59 & V_95 )
return;
if ( V_23 -> V_37 & V_99 )
return;
if ( ! ( V_23 -> V_37 & V_112 ) ) {
V_94 = F_50 ( V_23 , V_101 ) ;
V_94 |= V_23 -> V_113 ;
V_94 = F_53 ( V_94 ) ;
F_55 ( L_54 , V_94 ) ;
F_12 ( V_23 , V_101 , V_94 ) ;
F_55 ( L_56 ) ;
V_23 -> V_37 |= V_112 ;
F_64 ( & V_23 -> V_114 ) ;
F_56 ( & V_23 -> V_114 , V_115 ) ;
} else {
F_64 ( & V_23 -> V_114 ) ;
F_56 ( & V_23 -> V_114 , V_115 ) ;
}
}
static void F_65 ( struct V_17 * V_23 )
{
unsigned long V_41 ;
T_3 V_94 ;
if ( V_23 -> V_59 & V_95 )
return;
F_41 ( & V_23 -> V_98 , V_41 ) ;
if ( V_23 -> V_37 & V_112 ) {
V_94 = F_50 ( V_23 , V_101 ) ;
V_94 &= V_23 -> V_116 ;
V_94 = F_53 ( V_94 ) ;
F_55 ( L_54 , V_94 ) ;
F_12 ( V_23 , V_101 , V_94 ) ;
F_55 ( L_57 ) ;
V_23 -> V_37 &= ~ V_112 ;
}
F_42 ( & V_23 -> V_98 , V_41 ) ;
}
static void F_66 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_114 . V_107 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_65 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_67 ( struct V_17 * V_23 )
{
unsigned long V_41 ;
T_3 V_94 ;
if ( V_23 -> V_59 & V_95 ||
V_23 -> V_96 != V_97 || ! V_23 -> V_117 )
return;
F_41 ( & V_23 -> V_98 , V_41 ) ;
V_94 = F_50 ( V_23 , V_101 ) ;
if ( V_23 -> V_117 -> V_118 == V_119 ) {
V_94 |= V_23 -> V_120 ;
V_94 &= V_23 -> V_110 ;
F_55 ( L_58 ) ;
} else if ( V_23 -> V_117 -> V_118 == V_121 ) {
V_94 |= V_23 -> V_120 ;
V_94 |= V_23 -> V_102 ;
F_55 ( L_59 ) ;
} else {
V_94 &= V_23 -> V_122 ;
V_94 |= V_23 -> V_102 ;
F_55 ( L_60 ) ;
}
V_94 = F_53 ( V_94 ) ;
F_55 ( L_54 , V_94 ) ;
F_12 ( V_23 , V_101 , V_94 ) ;
F_42 ( & V_23 -> V_98 , V_41 ) ;
}
static void F_68 ( struct V_17 * V_23 )
{
unsigned long V_41 ;
T_3 V_94 ;
if ( V_23 -> V_59 & V_95 || V_23 -> V_96 != V_97 )
return;
F_41 ( & V_23 -> V_98 , V_41 ) ;
V_94 = F_50 ( V_23 , V_101 ) ;
V_94 &= V_23 -> V_122 ;
V_94 &= V_23 -> V_110 ;
V_94 = F_53 ( V_94 ) ;
F_55 ( L_54 , V_94 ) ;
F_12 ( V_23 , V_101 , V_94 ) ;
F_42 ( & V_23 -> V_98 , V_41 ) ;
}
static void F_69 ( struct V_17 * V_23 )
{
F_54 ( V_23 ) ;
}
static void F_70 ( struct V_17 * V_23 )
{
F_65 ( V_23 ) ;
F_61 ( V_23 ) ;
}
static void F_71 ( struct V_17 * V_23 )
{
F_54 ( V_23 ) ;
}
static void F_72 ( struct V_17 * V_23 )
{
F_65 ( V_23 ) ;
F_61 ( V_23 ) ;
if ( V_23 -> V_37 & V_99 )
F_70 ( V_23 ) ;
}
static void F_73 ( struct V_17 * V_23 )
{
V_23 -> V_96 = V_23 -> V_123 [ V_124 ] ;
V_23 -> V_113 = V_125 ;
V_23 -> V_116 = ~ ( V_125 ) ;
V_23 -> V_102 = V_126 ;
V_23 -> V_110 = ~ ( V_126 ) ;
V_23 -> V_120 = V_127 ;
V_23 -> V_122 = ~ ( V_127 ) ;
switch ( V_23 -> V_96 ) {
case V_97 :
V_23 -> V_113 = V_126 ;
V_23 -> V_116 = ~ ( V_126 ) ;
V_23 -> V_102 = V_125 ;
V_23 -> V_110 = ~ ( V_125 ) ;
if ( ! ( V_23 -> V_59 & V_95 ) )
F_67 ( V_23 ) ;
return;
case V_128 :
case V_129 :
case V_130 :
case V_131 :
break;
default:
F_74 ( L_61 ,
V_23 -> V_96 ) ;
V_23 -> V_96 = V_131 ;
break;
}
if ( ! ( V_23 -> V_59 & V_95 ) ) {
if ( V_23 -> V_37 & V_103 )
F_54 ( V_23 ) ;
else
F_61 ( V_23 ) ;
}
}
static void F_75 ( struct V_17 * V_23 )
{
F_65 ( V_23 ) ;
F_61 ( V_23 ) ;
F_68 ( V_23 ) ;
F_64 ( & V_23 -> V_108 ) ;
F_64 ( & V_23 -> V_104 ) ;
F_64 ( & V_23 -> V_114 ) ;
}
static T_5 F_76 ( struct V_132 * V_133 , char * V_1 )
{
return sprintf ( V_1 , L_62 , V_12 ) ;
}
static T_5 F_77 ( struct V_132 * V_133 , const char * V_1 ,
T_1 V_2 )
{
char * V_134 = ( char * ) V_1 ;
T_3 V_21 ;
if ( V_134 [ 1 ] == 'x' || V_134 [ 1 ] == 'X' || V_134 [ 0 ] == 'x' || V_134 [ 0 ] == 'X' ) {
V_134 ++ ;
if ( V_134 [ 0 ] == 'x' || V_134 [ 0 ] == 'X' )
V_134 ++ ;
V_21 = F_78 ( V_134 , & V_134 , 16 ) ;
} else
V_21 = F_78 ( V_134 , & V_134 , 10 ) ;
if ( V_134 == V_1 )
F_4 (KERN_INFO DRV_NAME
L_63 , buf) ;
else
V_12 = V_21 ;
return F_79 ( V_1 , V_2 ) ;
}
static inline T_3 F_80 ( struct V_17 * V_23 )
{
return F_50 ( V_23 , F_36 ( V_23 , V_135 ) ) ;
}
static void F_81 ( struct V_17 * V_23 ,
T_3 V_67 , struct V_136 * log )
{
T_3 V_137 ;
if ( V_67 ) {
V_137 = F_36 ( V_23 , V_135 ) ;
F_51 ( V_23 , V_137 + sizeof( V_137 ) + sizeof( T_3 ) ,
( T_2 * ) log , sizeof( * log ) * V_67 ) ;
}
}
static struct V_58 * F_82 ( struct V_17 * V_23 )
{
struct V_58 * error ;
T_3 V_67 = F_80 ( V_23 ) ;
T_3 V_137 = F_36 ( V_23 , V_138 ) ;
T_3 V_60 = F_50 ( V_23 , V_137 ) ;
error = F_83 ( sizeof( * error ) +
sizeof( * error -> V_61 ) * V_60 +
sizeof( * error -> log ) * V_67 , V_139 ) ;
if ( ! error ) {
F_46 ( L_64
L_65 ) ;
return NULL ;
}
error -> V_140 = V_140 ;
error -> V_37 = V_23 -> V_37 ;
error -> V_59 = V_23 -> V_59 ;
error -> V_60 = V_60 ;
error -> V_67 = V_67 ;
error -> V_61 = (struct V_141 * ) error -> V_142 ;
error -> log = (struct V_136 * ) ( error -> V_61 + V_60 ) ;
F_81 ( V_23 , V_67 , error -> log ) ;
if ( V_60 )
F_51 ( V_23 , V_137 + sizeof( V_137 ) , ( T_2 * ) error -> V_61 ,
sizeof( * error -> V_61 ) * V_60 ) ;
return error ;
}
static T_5 F_84 ( struct V_143 * V_133 ,
struct V_144 * V_145 , char * V_1 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
T_3 V_67 = F_80 ( V_23 ) ;
T_3 V_146 ;
struct V_136 * log ;
T_3 V_4 = 0 , V_7 ;
V_146 = V_147 / sizeof( * log ) > V_67 ?
sizeof( * log ) * V_67 : V_147 ;
log = F_86 ( V_146 , V_148 ) ;
if ( ! log ) {
F_46 ( L_66 ) ;
return 0 ;
}
V_67 = V_146 / sizeof( * log ) ;
F_81 ( V_23 , V_67 , log ) ;
V_4 += snprintf ( V_1 + V_4 , V_147 - V_4 , L_1 , V_67 ) ;
for ( V_7 = 0 ; V_7 < V_67 ; V_7 ++ )
V_4 += snprintf ( V_1 + V_4 , V_147 - V_4 ,
L_67 ,
log [ V_7 ] . time , log [ V_7 ] . V_68 , log [ V_7 ] . V_3 ) ;
V_4 += snprintf ( V_1 + V_4 , V_147 - V_4 , L_68 ) ;
F_87 ( log ) ;
return V_4 ;
}
static T_5 F_88 ( struct V_143 * V_133 ,
struct V_144 * V_145 , char * V_1 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
T_3 V_4 = 0 , V_7 ;
if ( ! V_23 -> error )
return 0 ;
V_4 += snprintf ( V_1 + V_4 , V_147 - V_4 ,
L_69 ,
V_23 -> error -> V_140 ,
V_23 -> error -> V_37 ,
V_23 -> error -> V_59 , V_23 -> error -> V_60 ) ;
for ( V_7 = 0 ; V_7 < V_23 -> error -> V_60 ; V_7 ++ )
V_4 += snprintf ( V_1 + V_4 , V_147 - V_4 ,
L_70 ,
V_23 -> error -> V_61 [ V_7 ] . time ,
V_23 -> error -> V_61 [ V_7 ] . V_62 ,
V_23 -> error -> V_61 [ V_7 ] . V_63 ,
V_23 -> error -> V_61 [ V_7 ] . V_64 ,
V_23 -> error -> V_61 [ V_7 ] . V_65 ,
V_23 -> error -> V_61 [ V_7 ] . V_66 ,
V_23 -> error -> V_61 [ V_7 ] . V_3 ) ;
V_4 += snprintf ( V_1 + V_4 , V_147 - V_4 ,
L_71 , V_23 -> error -> V_67 ) ;
for ( V_7 = 0 ; V_7 < V_23 -> error -> V_67 ; V_7 ++ )
V_4 += snprintf ( V_1 + V_4 , V_147 - V_4 ,
L_67 ,
V_23 -> error -> log [ V_7 ] . time ,
V_23 -> error -> log [ V_7 ] . V_68 ,
V_23 -> error -> log [ V_7 ] . V_3 ) ;
V_4 += snprintf ( V_1 + V_4 , V_147 - V_4 , L_68 ) ;
return V_4 ;
}
static T_5 F_89 ( struct V_143 * V_133 ,
struct V_144 * V_145 ,
const char * V_1 , T_1 V_2 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
F_87 ( V_23 -> error ) ;
V_23 -> error = NULL ;
return V_2 ;
}
static T_5 F_90 ( struct V_143 * V_133 ,
struct V_144 * V_145 , char * V_1 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
T_3 V_4 = 0 , V_7 ;
if ( ! V_23 -> V_149 )
return 0 ;
for ( V_7 = ( V_23 -> V_150 + 1 ) % V_23 -> V_151 ;
( V_7 != V_23 -> V_150 ) && ( V_147 - V_4 ) ;
V_7 = ( V_7 + 1 ) % V_23 -> V_151 ) {
V_4 +=
snprintf ( V_1 + V_4 , V_147 - V_4 ,
L_72 , V_23 -> V_149 [ V_7 ] . V_140 ,
V_23 -> V_149 [ V_7 ] . V_152 , V_23 -> V_149 [ V_7 ] . V_153 . V_153 ,
V_23 -> V_149 [ V_7 ] . V_153 . V_4 ) ;
V_4 +=
F_5 ( V_1 + V_4 , V_147 - V_4 ,
( T_2 * ) V_23 -> V_149 [ V_7 ] . V_153 . V_154 ,
V_23 -> V_149 [ V_7 ] . V_153 . V_4 ) ;
V_4 += snprintf ( V_1 + V_4 , V_147 - V_4 , L_68 ) ;
}
V_4 += snprintf ( V_1 + V_4 , V_147 - V_4 , L_68 ) ;
return V_4 ;
}
static T_5 F_91 ( struct V_143 * V_133 ,
struct V_144 * V_145 ,
const char * V_1 , T_1 V_2 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
int V_155 = 0 ;
if ( V_2 < 1 )
return - V_75 ;
switch ( V_1 [ 0 ] ) {
case '0' :
if ( ! V_156 )
return V_2 ;
if ( F_92 ( V_23 -> V_157 ) ) {
F_93 ( L_73 ) ;
return V_2 ;
}
F_94 ( V_23 ) ;
V_156 = 0 ;
break;
case '1' :
if ( V_156 )
return V_2 ;
V_155 = F_95 ( V_23 ) ;
if ( ! V_155 )
V_156 = 1 ;
break;
default:
return - V_75 ;
}
if ( V_155 ) {
F_46 ( L_74
L_75 , V_155 ) ;
}
return V_2 ;
}
static T_5 F_96 ( struct V_143 * V_133 ,
struct V_144 * V_145 ,
char * V_1 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
if ( V_156 )
return sprintf ( V_1 , L_76 , V_23 -> V_157 -> V_158 ) ;
else {
V_1 [ 0 ] = '-' ;
V_1 [ 1 ] = '1' ;
V_1 [ 2 ] = '\0' ;
return 3 ;
}
}
static T_5 F_97 ( struct V_143 * V_133 ,
struct V_144 * V_145 ,
const char * V_1 , T_1 V_2 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
if ( ! V_23 -> V_159 ) {
F_46 ( L_77
L_78 ) ;
return - V_160 ;
}
V_23 -> V_159 -> V_161 = F_98 ( V_1 , NULL , 0 ) ;
F_74 ( L_79 V_162 L_68 ,
F_99 ( V_23 -> V_159 -> V_161 ) ) ;
return V_2 ;
}
static T_5 F_100 ( struct V_143 * V_133 ,
struct V_144 * V_145 ,
char * V_1 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
return sprintf ( V_1 , L_80 ,
V_23 -> V_159 ? V_23 -> V_159 -> V_161 : 0 ) ;
}
static T_5 F_101 ( struct V_143 * V_133 , struct V_144 * V_145 ,
char * V_1 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
return sprintf ( V_1 , L_81 , V_23 -> V_163 -> V_164 ) ;
}
static T_5 F_102 ( struct V_143 * V_133 , struct V_144 * V_145 ,
const char * V_1 , T_1 V_2 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
struct V_165 * V_166 = V_23 -> V_167 ;
char V_168 [] = L_82 ;
unsigned long V_4 =
( sizeof( V_168 ) - 1 ) > V_2 ? V_2 : sizeof( V_168 ) - 1 ;
unsigned long V_21 ;
char * V_134 = V_168 ;
F_74 ( L_83 ) ;
strncpy ( V_168 , V_1 , V_4 ) ;
V_168 [ V_4 ] = 0 ;
if ( V_134 [ 1 ] == 'x' || V_134 [ 1 ] == 'X' || V_134 [ 0 ] == 'x' || V_134 [ 0 ] == 'X' ) {
V_134 ++ ;
if ( V_134 [ 0 ] == 'x' || V_134 [ 0 ] == 'X' )
V_134 ++ ;
V_21 = F_78 ( V_134 , & V_134 , 16 ) ;
} else
V_21 = F_78 ( V_134 , & V_134 , 10 ) ;
if ( V_134 == V_168 ) {
F_74 ( L_84 , V_166 -> V_158 ) ;
} else {
V_23 -> V_163 -> V_164 = V_21 ;
F_74 ( L_85 , V_23 -> V_163 -> V_164 ) ;
}
F_74 ( L_86 ) ;
return V_4 ;
}
static T_5 F_103 ( struct V_143 * V_133 , struct V_144 * V_145 ,
char * V_1 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
return sprintf ( V_1 , L_81 , ( V_23 -> V_59 & V_95 ) ? 0 : 1 ) ;
}
static T_5 F_104 ( struct V_143 * V_133 , struct V_144 * V_145 ,
const char * V_1 , T_1 V_2 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
F_74 ( L_83 ) ;
if ( V_2 == 0 )
return 0 ;
if ( * V_1 == 0 ) {
F_55 ( L_87 ) ;
V_23 -> V_59 |= V_95 ;
F_75 ( V_23 ) ;
} else {
F_55 ( L_88 ) ;
V_23 -> V_59 &= ~ V_95 ;
F_73 ( V_23 ) ;
}
F_74 ( L_86 ) ;
return V_2 ;
}
static T_5 F_105 ( struct V_143 * V_133 ,
struct V_144 * V_145 , char * V_1 )
{
struct V_17 * V_134 = F_85 ( V_133 ) ;
return sprintf ( V_1 , L_89 , ( int ) V_134 -> V_37 ) ;
}
static T_5 F_106 ( struct V_143 * V_133 , struct V_144 * V_145 ,
char * V_1 )
{
struct V_17 * V_134 = F_85 ( V_133 ) ;
return sprintf ( V_1 , L_89 , ( int ) V_134 -> V_59 ) ;
}
static T_5 F_107 ( struct V_143 * V_133 ,
struct V_144 * V_145 , char * V_1 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
return sprintf ( V_1 , L_90 , V_23 -> V_96 ) ;
}
static T_5 F_108 ( struct V_143 * V_133 ,
struct V_144 * V_145 , char * V_1 )
{
T_3 V_4 = sizeof( T_3 ) , V_169 = 0 ;
struct V_17 * V_134 = F_85 ( V_133 ) ;
if ( F_48 ( V_134 , V_170 , & V_169 , & V_4 ) )
return 0 ;
return sprintf ( V_1 , L_89 , V_169 ) ;
}
static T_5 F_109 ( struct V_143 * V_133 , struct V_144 * V_145 ,
char * V_1 )
{
T_3 V_4 = sizeof( T_3 ) , V_169 = 0 ;
struct V_17 * V_134 = F_85 ( V_133 ) ;
if ( F_48 ( V_134 , V_171 , & V_169 , & V_4 ) )
return 0 ;
return sprintf ( V_1 , L_89 , V_169 ) ;
}
static T_5 F_110 ( struct V_143 * V_133 ,
struct V_144 * V_145 , char * V_1 )
{
struct V_17 * V_134 = F_85 ( V_133 ) ;
int V_172 = V_134 -> V_173 ;
return sprintf ( V_1 , L_91 , V_172 ) ;
}
static T_5 F_111 ( struct V_143 * V_133 ,
struct V_144 * V_145 ,
const char * V_1 , T_1 V_2 )
{
struct V_17 * V_134 = F_85 ( V_133 ) ;
sscanf ( V_1 , L_92 , & V_134 -> V_173 ) ;
return F_79 ( V_1 , V_2 ) ;
}
static T_5 F_112 ( struct V_143 * V_133 ,
struct V_144 * V_145 , char * V_1 )
{
T_3 V_24 = 0 ;
struct V_17 * V_134 = F_85 ( V_133 ) ;
V_24 = F_50 ( V_134 , V_174 ) ;
return sprintf ( V_1 , L_89 , V_24 ) ;
}
static T_5 F_113 ( struct V_143 * V_133 ,
struct V_144 * V_145 ,
const char * V_1 , T_1 V_2 )
{
T_3 V_24 ;
struct V_17 * V_134 = F_85 ( V_133 ) ;
sscanf ( V_1 , L_93 , & V_24 ) ;
F_12 ( V_134 , V_174 , V_24 ) ;
return F_79 ( V_1 , V_2 ) ;
}
static T_5 F_114 ( struct V_143 * V_133 ,
struct V_144 * V_145 , char * V_1 )
{
T_3 V_24 = 0 ;
struct V_17 * V_134 = F_85 ( V_133 ) ;
V_24 = F_50 ( V_134 , 0x301100 ) ;
return sprintf ( V_1 , L_89 , V_24 ) ;
}
static T_5 F_115 ( struct V_143 * V_133 ,
struct V_144 * V_145 ,
const char * V_1 , T_1 V_2 )
{
T_3 V_24 ;
struct V_17 * V_134 = F_85 ( V_133 ) ;
sscanf ( V_1 , L_93 , & V_24 ) ;
F_12 ( V_134 , 0x301100 , V_24 ) ;
return F_79 ( V_1 , V_2 ) ;
}
static T_5 F_116 ( struct V_143 * V_133 ,
struct V_144 * V_145 , char * V_1 )
{
T_3 V_24 = 0 ;
struct V_17 * V_23 = F_85 ( V_133 ) ;
if ( V_23 -> V_37 & V_175 )
V_24 = F_50 ( V_23 , V_23 -> V_176 ) ;
else
V_24 = 0 ;
return sprintf ( V_1 , L_89 , V_24 ) ;
}
static T_5 F_117 ( struct V_143 * V_133 ,
struct V_144 * V_145 ,
const char * V_1 , T_1 V_2 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
sscanf ( V_1 , L_93 , & V_23 -> V_176 ) ;
V_23 -> V_37 |= V_175 ;
return F_79 ( V_1 , V_2 ) ;
}
static T_5 F_118 ( struct V_143 * V_133 ,
struct V_144 * V_145 , char * V_1 )
{
T_2 V_24 = 0 ;
struct V_17 * V_23 = F_85 ( V_133 ) ;
if ( V_23 -> V_37 & V_177 )
V_24 = F_119 ( V_23 , V_23 -> V_178 ) ;
else
V_24 = 0 ;
return sprintf ( V_1 , L_94 , V_24 ) ;
}
static T_5 F_120 ( struct V_143 * V_133 ,
struct V_144 * V_145 ,
const char * V_1 , T_1 V_2 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
sscanf ( V_1 , L_93 , & V_23 -> V_178 ) ;
V_23 -> V_37 |= V_177 ;
return F_79 ( V_1 , V_2 ) ;
}
static T_5 F_121 ( struct V_143 * V_133 ,
struct V_144 * V_145 , char * V_1 )
{
T_3 V_24 = 0 ;
struct V_17 * V_23 = F_85 ( V_133 ) ;
if ( V_23 -> V_37 & V_179 )
V_24 = F_36 ( V_23 , V_23 -> V_180 ) ;
else
V_24 = 0 ;
return sprintf ( V_1 , L_89 , V_24 ) ;
}
static T_5 F_122 ( struct V_143 * V_133 ,
struct V_144 * V_145 ,
const char * V_1 , T_1 V_2 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
sscanf ( V_1 , L_93 , & V_23 -> V_180 ) ;
V_23 -> V_37 |= V_179 ;
return F_79 ( V_1 , V_2 ) ;
}
static int F_123 ( struct V_17 * V_23 )
{
if ( 0 == ( F_36 ( V_23 , 0x30 ) & 0x10000 ) ) {
V_23 -> V_37 |= V_181 ;
F_124 ( V_23 -> V_163 -> V_182 . V_183 , true ) ;
} else {
V_23 -> V_37 &= ~ V_181 ;
F_124 ( V_23 -> V_163 -> V_182 . V_183 , false ) ;
}
return ( V_23 -> V_37 & V_181 ) ? 1 : 0 ;
}
static T_5 F_125 ( struct V_143 * V_133 , struct V_144 * V_145 ,
char * V_1 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
int V_21 = ( ( V_23 -> V_37 & V_184 ) ? 0x1 : 0x0 ) |
( F_123 ( V_23 ) ? 0x2 : 0x0 ) ;
return sprintf ( V_1 , L_91 , V_21 ) ;
}
static int F_126 ( struct V_17 * V_23 , int V_185 )
{
if ( ( V_185 ? 1 : 0 ) ==
( ( V_23 -> V_37 & V_184 ) ? 1 : 0 ) )
return 0 ;
F_127 ( L_95 ,
V_185 ? L_96 : L_97 ) ;
if ( V_185 ) {
V_23 -> V_37 |= V_184 ;
F_64 ( & V_23 -> V_186 ) ;
F_64 ( & V_23 -> V_187 ) ;
F_64 ( & V_23 -> V_188 ) ;
F_64 ( & V_23 -> V_189 ) ;
F_128 ( & V_23 -> V_190 ) ;
} else {
V_23 -> V_37 &= ~ V_184 ;
if ( F_123 ( V_23 ) ) {
F_127 ( L_98
L_99 ) ;
F_64 ( & V_23 -> V_191 ) ;
F_56 ( & V_23 -> V_191 ,
F_129 ( 2 * V_192 ) ) ;
} else
F_128 ( & V_23 -> V_193 ) ;
}
return 1 ;
}
static T_5 F_130 ( struct V_143 * V_133 , struct V_144 * V_145 ,
const char * V_1 , T_1 V_2 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
F_126 ( V_23 , V_1 [ 0 ] == '1' ) ;
return V_2 ;
}
static T_5 F_131 ( struct V_143 * V_133 , struct V_144 * V_145 ,
char * V_1 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
int V_194 = 0 , V_4 = 0 ;
if ( V_23 -> V_59 & V_195 ) {
while ( V_23 -> V_196 [ V_194 ] != 0 )
V_4 += sprintf ( & V_1 [ V_4 ] , L_100 ,
V_23 -> V_196 [ V_194 ++ ] ) ;
return V_4 + sprintf ( & V_1 [ V_4 ] , L_68 ) ;
}
return sprintf ( V_1 , L_101 ) ;
}
static T_5 F_132 ( struct V_143 * V_133 , struct V_144 * V_145 ,
const char * V_1 , T_1 V_2 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
int V_197 , V_194 = 0 ;
const char * V_134 = V_1 ;
while ( ( V_197 = F_98 ( V_134 , NULL , 0 ) ) ) {
if ( V_194 == V_198 - 1 ) {
V_23 -> V_196 [ V_194 ] = 0 ;
break;
}
if ( F_133 ( V_23 -> V_163 , V_197 ) )
V_23 -> V_196 [ V_194 ++ ] = V_197 ;
else
F_93 ( L_102 ,
V_197 ) ;
V_134 = strchr ( V_134 , ' ' ) ;
if ( ! V_134 )
break;
while ( * V_134 == ' ' || * V_134 == '\t' )
V_134 ++ ;
}
if ( V_194 == 0 )
V_23 -> V_59 &= ~ V_195 ;
else {
V_23 -> V_199 = 0 ;
V_23 -> V_59 |= V_195 ;
}
return V_2 ;
}
static T_5 F_134 ( struct V_143 * V_133 , struct V_144 * V_145 ,
char * V_1 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
return sprintf ( V_1 , L_103 , ( V_23 -> V_59 & V_200 ) ? '1' : '0' ) ;
}
static T_5 F_135 ( struct V_143 * V_133 , struct V_144 * V_145 ,
const char * V_1 , T_1 V_2 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
if ( V_1 [ 0 ] == '1' )
V_23 -> V_59 |= V_200 ;
else
V_23 -> V_59 &= ~ V_200 ;
return V_2 ;
}
static T_5 F_136 ( struct V_143 * V_133 ,
struct V_144 * V_145 ,
char * V_1 )
{
struct V_17 * V_23 = F_85 ( V_133 ) ;
const struct V_201 * V_202 = F_137 ( V_23 -> V_163 ) ;
int V_4 = 0 , V_7 ;
V_4 = sprintf ( & V_1 [ V_4 ] ,
L_104
L_105 , V_202 -> V_203 ) ;
for ( V_7 = 0 ; V_7 < V_202 -> V_203 ; V_7 ++ ) {
V_4 += sprintf ( & V_1 [ V_4 ] , L_106 ,
V_202 -> V_204 [ V_7 ] . V_197 ,
V_202 -> V_204 [ V_7 ] . V_41 & V_205 ?
L_107 : L_108 ,
( ( V_202 -> V_204 [ V_7 ] . V_41 & V_206 ) ||
( V_202 -> V_204 [ V_7 ] . V_41 & V_205 ) )
? L_108 : L_109 ,
V_202 -> V_204 [ V_7 ] . V_41 & V_207 ?
L_110 : L_111 ,
V_202 -> V_204 [ V_7 ] . V_41 & V_208 ?
L_112 : L_113 ) ;
}
V_4 += sprintf ( & V_1 [ V_4 ] ,
L_114
L_115 , V_202 -> V_209 ) ;
for ( V_7 = 0 ; V_7 < V_202 -> V_209 ; V_7 ++ ) {
V_4 += sprintf ( & V_1 [ V_4 ] , L_116 ,
V_202 -> V_18 [ V_7 ] . V_197 ,
V_202 -> V_18 [ V_7 ] . V_41 & V_205 ?
L_107 : L_108 ,
( ( V_202 -> V_18 [ V_7 ] . V_41 & V_206 ) ||
( V_202 -> V_18 [ V_7 ] . V_41 & V_205 ) )
? L_108 : L_109 ,
V_202 -> V_18 [ V_7 ] . V_41 & V_207 ?
L_110 : L_111 ) ;
}
return V_4 ;
}
static void F_138 ( struct V_17 * V_23 )
{
union V_210 V_211 ;
V_211 . V_212 . V_213 = V_214 ;
if ( V_23 -> V_37 & V_103 )
memcpy ( V_211 . V_212 . V_215 , V_23 -> V_216 , V_217 ) ;
else
memset ( V_211 . V_212 . V_215 , 0 , V_217 ) ;
F_139 ( V_23 -> V_167 , V_218 , & V_211 , NULL ) ;
}
static void F_140 ( struct V_17 * V_23 )
{
T_3 V_219 , V_220 , V_221 = 0 ;
unsigned long V_41 ;
int V_155 = 0 ;
F_41 ( & V_23 -> V_42 , V_41 ) ;
V_219 = F_36 ( V_23 , V_222 ) ;
V_220 = F_36 ( V_23 , V_39 ) ;
if ( V_219 == 0xFFFFFFFF ) {
F_93 ( L_117 ) ;
V_219 = 0 ;
}
V_219 &= ( V_40 & V_220 ) ;
V_219 |= V_23 -> V_223 ;
F_42 ( & V_23 -> V_42 , V_41 ) ;
F_41 ( & V_23 -> V_98 , V_41 ) ;
if ( V_219 & V_224 ) {
F_141 ( V_23 ) ;
V_221 |= V_224 ;
}
if ( V_219 & V_225 ) {
F_142 ( L_118 ) ;
V_155 = F_143 ( V_23 , & V_23 -> V_226 , - 1 ) ;
V_23 -> V_37 &= ~ V_227 ;
F_144 ( & V_23 -> V_228 ) ;
V_221 |= V_225 ;
}
if ( V_219 & V_229 ) {
F_145 ( L_119 ) ;
V_155 = F_143 ( V_23 , & V_23 -> V_230 [ 0 ] , 0 ) ;
V_221 |= V_229 ;
}
if ( V_219 & V_231 ) {
F_145 ( L_120 ) ;
V_155 = F_143 ( V_23 , & V_23 -> V_230 [ 1 ] , 1 ) ;
V_221 |= V_231 ;
}
if ( V_219 & V_232 ) {
F_145 ( L_121 ) ;
V_155 = F_143 ( V_23 , & V_23 -> V_230 [ 2 ] , 2 ) ;
V_221 |= V_232 ;
}
if ( V_219 & V_233 ) {
F_145 ( L_122 ) ;
V_155 = F_143 ( V_23 , & V_23 -> V_230 [ 3 ] , 3 ) ;
V_221 |= V_233 ;
}
if ( V_219 & V_234 ) {
F_93 ( L_123 ) ;
V_221 |= V_234 ;
}
if ( V_219 & V_235 ) {
F_93 ( L_124 ) ;
V_221 |= V_235 ;
}
if ( V_219 & V_236 ) {
F_93 ( L_125 ) ;
V_221 |= V_236 ;
}
if ( V_219 & V_237 ) {
F_93 ( L_126 ) ;
V_221 |= V_237 ;
}
if ( V_219 & V_238 ) {
F_93 ( L_127 ) ;
V_221 |= V_238 ;
}
if ( V_219 & V_239 ) {
F_127 ( L_128 ) ;
V_23 -> V_37 |= V_181 ;
F_124 ( V_23 -> V_163 -> V_182 . V_183 , true ) ;
F_144 ( & V_23 -> V_228 ) ;
V_23 -> V_37 &= ~ ( V_103 | V_240 ) ;
F_64 ( & V_23 -> V_186 ) ;
F_64 ( & V_23 -> V_187 ) ;
F_64 ( & V_23 -> V_188 ) ;
F_64 ( & V_23 -> V_189 ) ;
F_128 ( & V_23 -> V_241 ) ;
F_56 ( & V_23 -> V_191 , 2 * V_192 ) ;
V_221 |= V_239 ;
}
if ( V_219 & V_242 ) {
F_93 ( L_129 ) ;
if ( V_23 -> error ) {
F_146 ( L_130 ) ;
if ( V_12 & V_243 ) {
struct V_58 * error =
F_82 ( V_23 ) ;
F_45 ( V_23 , error ) ;
F_87 ( error ) ;
}
} else {
V_23 -> error = F_82 ( V_23 ) ;
if ( V_23 -> error )
F_146 ( L_131 ) ;
else
F_146 ( L_132
L_133 ) ;
if ( V_12 & V_243 )
F_45 ( V_23 , V_23 -> error ) ;
}
if ( V_23 -> V_163 -> V_244 . V_245 ) {
V_23 -> V_37 &= ~ V_103 ;
F_138 ( V_23 ) ;
}
V_23 -> V_37 &= ~ V_69 ;
V_23 -> V_37 &= ~ V_227 ;
F_144 ( & V_23 -> V_228 ) ;
F_128 ( & V_23 -> V_246 ) ;
V_221 |= V_242 ;
}
if ( V_219 & V_247 ) {
F_46 ( L_134 ) ;
V_221 |= V_247 ;
}
if ( V_221 != V_219 ) {
F_46 ( L_135 , V_219 & ~ V_221 ) ;
}
F_42 ( & V_23 -> V_98 , V_41 ) ;
F_40 ( V_23 ) ;
}
static char * F_147 ( T_2 V_153 )
{
switch ( V_153 ) {
F_148 ( V_248 ) ;
F_148 ( V_249 ) ;
F_148 ( V_250 ) ;
F_148 ( V_251 ) ;
F_148 ( V_252 ) ;
F_148 ( V_253 ) ;
F_148 ( V_254 ) ;
F_148 ( V_255 ) ;
F_148 ( V_256 ) ;
F_148 ( V_257 ) ;
F_148 ( V_258 ) ;
F_148 ( V_259 ) ;
F_148 ( V_260 ) ;
F_148 ( V_261 ) ;
F_148 ( V_262 ) ;
F_148 ( V_263 ) ;
F_148 ( V_264 ) ;
F_148 ( V_265 ) ;
F_148 ( V_266 ) ;
F_148 ( V_267 ) ;
F_148 ( V_268 ) ;
F_148 ( V_269 ) ;
F_148 ( V_270 ) ;
F_148 ( V_271 ) ;
F_148 ( V_272 ) ;
F_148 ( V_273 ) ;
F_148 ( V_274 ) ;
F_148 ( V_275 ) ;
F_148 ( V_276 ) ;
F_148 ( V_277 ) ;
F_148 ( V_278 ) ;
F_148 ( V_279 ) ;
F_148 ( V_280 ) ;
F_148 ( V_281 ) ;
F_148 ( V_282 ) ;
F_148 ( V_283 ) ;
F_148 ( V_284 ) ;
F_148 ( V_285 ) ;
F_148 ( V_286 ) ;
F_148 ( V_287 ) ;
F_148 ( V_288 ) ;
F_148 ( V_289 ) ;
F_148 ( V_290 ) ;
F_148 ( V_291 ) ;
F_148 ( V_292 ) ;
F_148 ( V_293 ) ;
F_148 ( V_294 ) ;
F_148 ( V_295 ) ;
F_148 ( V_296 ) ;
F_148 ( V_297 ) ;
default:
return L_136 ;
}
}
static int F_149 ( struct V_17 * V_23 , struct V_298 * V_153 )
{
int V_155 = 0 ;
unsigned long V_41 ;
F_41 ( & V_23 -> V_98 , V_41 ) ;
if ( V_23 -> V_37 & V_227 ) {
F_46 ( L_137 ,
F_147 ( V_153 -> V_153 ) ) ;
F_42 ( & V_23 -> V_98 , V_41 ) ;
return - V_299 ;
}
V_23 -> V_37 |= V_227 ;
if ( V_23 -> V_149 ) {
V_23 -> V_149 [ V_23 -> V_150 ] . V_140 = V_140 ;
V_23 -> V_149 [ V_23 -> V_150 ] . V_153 . V_153 = V_153 -> V_153 ;
V_23 -> V_149 [ V_23 -> V_150 ] . V_153 . V_4 = V_153 -> V_4 ;
memcpy ( V_23 -> V_149 [ V_23 -> V_150 ] . V_153 . V_154 , V_153 -> V_154 ,
V_153 -> V_4 ) ;
V_23 -> V_149 [ V_23 -> V_150 ] . V_152 = - 1 ;
}
F_142 ( L_138 ,
F_147 ( V_153 -> V_153 ) , V_153 -> V_153 , V_153 -> V_4 ,
V_23 -> V_37 ) ;
#ifndef F_150
if ( V_153 -> V_153 == V_300 )
F_142 ( L_139 ) ;
else
#endif
F_2 ( V_301 , ( T_2 * ) V_153 -> V_154 , V_153 -> V_4 ) ;
V_155 = F_151 ( V_23 , V_153 -> V_153 , V_153 -> V_154 , V_153 -> V_4 , 0 ) ;
if ( V_155 ) {
V_23 -> V_37 &= ~ V_227 ;
F_46 ( L_140 ,
F_147 ( V_153 -> V_153 ) , V_155 ) ;
F_42 ( & V_23 -> V_98 , V_41 ) ;
goto exit;
}
F_42 ( & V_23 -> V_98 , V_41 ) ;
V_155 = F_152 ( V_23 -> V_228 ,
! ( V_23 ->
V_37 & V_227 ) ,
V_302 ) ;
if ( V_155 == 0 ) {
F_41 ( & V_23 -> V_98 , V_41 ) ;
if ( V_23 -> V_37 & V_227 ) {
F_46 ( L_141 ,
F_147 ( V_153 -> V_153 ) ) ;
V_23 -> V_37 &= ~ V_227 ;
F_42 ( & V_23 -> V_98 , V_41 ) ;
V_155 = - V_303 ;
goto exit;
}
F_42 ( & V_23 -> V_98 , V_41 ) ;
} else
V_155 = 0 ;
if ( V_23 -> V_37 & V_181 ) {
F_46 ( L_142 ,
F_147 ( V_153 -> V_153 ) ) ;
V_155 = - V_303 ;
goto exit;
}
exit:
if ( V_23 -> V_149 ) {
V_23 -> V_149 [ V_23 -> V_150 ++ ] . V_152 = V_155 ;
V_23 -> V_150 %= V_23 -> V_151 ;
}
return V_155 ;
}
static int F_153 ( struct V_17 * V_23 , T_2 V_304 )
{
struct V_298 V_153 = {
. V_153 = V_304 ,
} ;
return F_149 ( V_23 , & V_153 ) ;
}
static int F_154 ( struct V_17 * V_23 , T_2 V_304 , T_2 V_4 ,
void * V_3 )
{
struct V_298 V_153 = {
. V_153 = V_304 ,
. V_4 = V_4 ,
. V_154 = V_3 ,
} ;
return F_149 ( V_23 , & V_153 ) ;
}
static int F_155 ( struct V_17 * V_23 )
{
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_153 ( V_23 , V_305 ) ;
}
static int F_156 ( struct V_17 * V_23 )
{
return F_154 ( V_23 , V_306 ,
sizeof( V_23 -> V_307 ) ,
& V_23 -> V_307 ) ;
}
static int F_157 ( struct V_17 * V_23 , T_2 * V_308 , int V_4 )
{
if ( ! V_23 || ! V_308 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_154 ( V_23 , V_309 , F_3 ( V_4 , V_310 ) ,
V_308 ) ;
}
static int F_158 ( struct V_17 * V_23 , T_2 * V_311 )
{
if ( ! V_23 || ! V_311 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
F_74 ( L_144 ,
V_23 -> V_167 -> V_158 , V_311 ) ;
return F_154 ( V_23 , V_312 , V_217 , V_311 ) ;
}
static void F_159 ( void * V_313 )
{
struct V_17 * V_23 = V_313 ;
if ( V_23 -> V_37 & V_99 )
return;
F_160 ( V_23 ) ;
if ( V_23 -> V_117 &&
( V_23 -> V_117 -> V_314 & V_315 ) )
F_161 ( V_23 ) ;
if ( F_162 ( V_23 ) ) {
F_46 ( L_145 ) ;
return;
}
}
static void F_163 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_246 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_159 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_164 ( void * V_3 )
{
struct V_17 * V_23 = V_3 ;
if ( V_23 -> V_37 & V_316 ) {
F_165 ( L_146
L_147 ,
F_166 ( V_317 ) ) ;
F_128 ( & V_23 -> V_246 ) ;
} else if ( V_23 -> V_37 & V_318 ) {
F_165 ( L_148
L_149 ,
F_166 ( V_317 ) ) ;
F_167 ( V_23 ) ;
F_56 ( & V_23 -> V_319 , V_192 ) ;
}
}
static void F_168 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_319 . V_107 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_164 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int F_169 ( struct V_17 * V_23 ,
struct V_320 * V_321 )
{
return F_154 ( V_23 , V_322 ,
sizeof( * V_321 ) , V_321 ) ;
}
static int F_170 ( struct V_17 * V_23 )
{
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_153 ( V_23 , V_323 ) ;
}
static int F_171 ( struct V_17 * V_23 , T_4 V_324 )
{
struct V_325 V_326 = {
. V_327 = F_172 ( V_324 ) ,
} ;
return F_154 ( V_23 , V_328 , sizeof( V_326 ) ,
& V_326 ) ;
}
static int F_173 ( struct V_17 * V_23 ,
struct V_329 * V_330 )
{
if ( ! V_23 || ! V_330 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_154 ( V_23 , V_331 , sizeof( * V_330 ) ,
V_330 ) ;
}
static int F_174 ( struct V_17 * V_23 ,
struct V_332 * V_333 )
{
if ( ! V_23 || ! V_333 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_154 ( V_23 , V_334 , sizeof( * V_333 ) ,
V_333 ) ;
}
static int F_175 ( struct V_17 * V_23 )
{
T_3 V_21 ;
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
F_176 ( & V_21 , sizeof( V_21 ) ) ;
return F_154 ( V_23 , V_335 , sizeof( V_21 ) , & V_21 ) ;
}
static int F_177 ( struct V_17 * V_23 , T_3 V_336 )
{
T_6 V_337 = F_178 ( V_336 ) ;
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_154 ( V_23 , V_338 , sizeof( V_337 ) , & V_337 ) ;
}
static int F_179 ( struct V_17 * V_23 , struct V_339 * V_340 )
{
if ( ! V_23 || ! V_340 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_154 ( V_23 , V_341 , sizeof( * V_340 ) , V_340 ) ;
}
static int F_180 ( struct V_17 * V_23 )
{
const struct V_201 * V_202 = F_137 ( V_23 -> V_163 ) ;
struct V_339 V_342 ;
T_7 V_343 ;
int V_7 ;
memset ( & V_342 , 0 , sizeof( V_342 ) ) ;
V_342 . V_344 = V_345 ;
V_342 . V_346 = V_202 -> V_203 ;
for ( V_7 = 0 ; V_7 < V_202 -> V_203 ; V_7 ++ ) {
V_343 = V_202 -> V_204 [ V_7 ] . V_343 ;
V_342 . V_347 [ V_7 ] . V_348 =
V_202 -> V_204 [ V_7 ] . V_197 ;
V_342 . V_347 [ V_7 ] . V_342 = V_343 ?
F_3 ( V_343 , V_23 -> V_342 ) : V_23 -> V_342 ;
}
if ( F_179 ( V_23 , & V_342 ) )
return - V_303 ;
V_342 . V_344 = V_349 ;
if ( F_179 ( V_23 , & V_342 ) )
return - V_303 ;
if ( V_23 -> V_163 -> V_350 ) {
V_342 . V_344 = V_351 ;
V_342 . V_346 = V_202 -> V_209 ;
for ( V_7 = 0 ; V_7 < V_342 . V_346 ; V_7 ++ ) {
V_343 = V_202 -> V_18 [ V_7 ] . V_343 ;
V_342 . V_347 [ V_7 ] . V_348 =
V_202 -> V_18 [ V_7 ] . V_197 ;
V_342 . V_347 [ V_7 ] . V_342 = V_343 ?
F_3 ( V_343 , V_23 -> V_342 ) : V_23 -> V_342 ;
}
if ( F_179 ( V_23 , & V_342 ) )
return - V_303 ;
}
return 0 ;
}
static int F_181 ( struct V_17 * V_23 , T_4 V_352 )
{
struct V_353 V_354 = {
. V_354 = F_172 ( V_352 ) ,
} ;
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_154 ( V_23 , V_355 ,
sizeof( V_354 ) , & V_354 ) ;
}
static int F_182 ( struct V_17 * V_23 , T_4 V_356 )
{
struct V_357 V_358 = {
. V_358 = F_172 ( V_356 ) ,
} ;
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_154 ( V_23 , V_359 ,
sizeof( V_358 ) , & V_358 ) ;
}
static int F_183 ( struct V_17 * V_23 , T_3 V_118 )
{
T_6 V_154 ;
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
switch ( V_118 ) {
case V_360 :
V_154 = F_178 ( V_361 ) ;
break;
case V_362 :
V_154 = F_178 ( V_363 ) ;
break;
default:
V_154 = F_178 ( V_118 ) ;
break;
}
return F_154 ( V_23 , V_364 , sizeof( V_154 ) ,
& V_154 ) ;
}
static int F_184 ( struct V_17 * V_23 , T_2 V_365 , T_2 V_366 )
{
struct V_367 V_368 = {
. V_369 = V_365 ,
. V_370 = V_366
} ;
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_154 ( V_23 , V_371 , sizeof( V_368 ) ,
& V_368 ) ;
}
static inline void F_185 ( struct V_17 * V_134 , T_3 V_3 )
{
F_12 ( V_134 , V_372 , V_3 ) ;
F_186 ( V_134 -> V_173 ) ;
}
static void F_187 ( struct V_17 * V_23 )
{
F_185 ( V_23 , 0 ) ;
F_185 ( V_23 , V_373 ) ;
F_185 ( V_23 , V_373 | V_374 ) ;
F_185 ( V_23 , V_373 ) ;
}
static void F_188 ( struct V_17 * V_23 )
{
F_185 ( V_23 , V_373 ) ;
F_185 ( V_23 , 0 ) ;
F_185 ( V_23 , V_374 ) ;
}
static inline void F_189 ( struct V_17 * V_134 , T_2 V_375 )
{
int V_133 = ( V_375 ? V_376 : 0 ) ;
F_185 ( V_134 , V_373 | V_133 ) ;
F_185 ( V_134 , V_373 | V_133 | V_374 ) ;
}
static void F_190 ( struct V_17 * V_23 , T_2 V_377 , T_2 V_32 )
{
int V_7 ;
F_187 ( V_23 ) ;
F_189 ( V_23 , 1 ) ;
F_189 ( V_23 , V_377 & 2 ) ;
F_189 ( V_23 , V_377 & 1 ) ;
for ( V_7 = 7 ; V_7 >= 0 ; V_7 -- ) {
F_189 ( V_23 , V_32 & ( 1 << V_7 ) ) ;
}
}
static T_4 F_191 ( struct V_17 * V_23 , T_2 V_32 )
{
int V_7 ;
T_4 V_378 = 0 ;
F_190 ( V_23 , V_379 , V_32 ) ;
F_185 ( V_23 , V_373 ) ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ ) {
T_3 V_3 = 0 ;
F_185 ( V_23 , V_373 | V_374 ) ;
F_185 ( V_23 , V_373 ) ;
V_3 = F_50 ( V_23 , V_372 ) ;
V_378 = ( V_378 << 1 ) | ( ( V_3 & V_380 ) ? 1 : 0 ) ;
}
F_185 ( V_23 , 0 ) ;
F_188 ( V_23 ) ;
return V_378 ;
}
static void F_192 ( struct V_17 * V_23 , T_2 * V_311 )
{
memcpy ( V_311 , & V_23 -> V_123 [ V_381 ] , 6 ) ;
}
static void F_193 ( struct V_17 * V_23 )
{
int V_7 ;
T_8 * V_123 = ( T_8 * ) V_23 -> V_123 ;
F_194 ( L_150 ) ;
for ( V_7 = 0 ; V_7 < 128 ; V_7 ++ )
V_123 [ V_7 ] = F_172 ( F_191 ( V_23 , ( T_2 ) V_7 ) ) ;
if ( V_23 -> V_123 [ V_382 ] != 0 ) {
F_74 ( L_151 ) ;
for ( V_7 = 0 ; V_7 < V_383 ; V_7 ++ )
F_195 ( V_23 , V_384 + V_7 , V_23 -> V_123 [ V_7 ] ) ;
F_35 ( V_23 , V_385 , 0 ) ;
} else {
F_74 ( L_152 ) ;
F_35 ( V_23 , V_385 , 1 ) ;
}
F_194 ( L_153 ) ;
}
static void F_196 ( struct V_17 * V_23 , T_3 V_386 , T_3 V_2 )
{
V_2 >>= 2 ;
if ( ! V_2 )
return;
F_18 ( V_23 , V_34 , V_386 ) ;
while ( V_2 -- )
F_18 ( V_23 , V_35 , 0 ) ;
}
static inline void F_197 ( struct V_17 * V_23 )
{
F_196 ( V_23 , V_387 ,
V_388 *
sizeof( struct V_389 ) ) ;
}
static int F_198 ( struct V_17 * V_23 )
{
F_146 ( L_154 ) ;
F_197 ( V_23 ) ;
F_12 ( V_23 , V_390 , V_387 ) ;
F_146 ( L_155 ) ;
return 0 ;
}
static void F_199 ( struct V_17 * V_23 )
{
T_3 V_391 = 0 ;
F_146 ( L_154 ) ;
V_391 = V_392 | V_393 ;
F_12 ( V_23 , V_394 , V_391 ) ;
V_23 -> V_395 . V_396 = 0 ;
F_146 ( L_153 ) ;
}
static int F_200 ( struct V_17 * V_23 , int V_397 ,
struct V_389 * V_398 )
{
T_3 V_399 =
V_387 +
( sizeof( struct V_389 ) * V_397 ) ;
F_146 ( L_154 ) ;
F_201 ( V_23 , V_399 , ( T_2 * ) V_398 ,
( int ) sizeof( struct V_389 ) ) ;
F_146 ( L_155 ) ;
return 0 ;
}
static int F_202 ( struct V_17 * V_23 )
{
T_3 V_391 = 0 ;
T_3 V_397 = 0 ;
F_146 ( L_154 ) ;
for ( V_397 = 0 ; V_397 < V_23 -> V_395 . V_396 ; V_397 ++ )
F_200 ( V_23 , V_397 ,
& V_23 -> V_395 . V_400 [ V_397 ] ) ;
F_37 ( V_23 , V_401 ,
V_402 |
V_403 ) ;
V_391 = V_392 | V_404 ;
F_12 ( V_23 , V_394 , V_391 ) ;
F_146 ( L_155 ) ;
return 0 ;
}
static void F_203 ( struct V_17 * V_23 )
{
T_3 V_399 ;
T_3 V_405 = 0 ;
T_3 V_406 = 0 ;
F_146 ( L_154 ) ;
V_399 = F_50 ( V_23 , V_407 ) ;
F_204 ( L_156 , V_399 ) ;
V_405 = F_50 ( V_23 , V_394 ) ;
F_204 ( L_157 , V_405 ) ;
V_406 = V_399 ;
V_405 = F_50 ( V_23 , V_406 ) ;
F_204 ( L_158 , V_405 ) ;
V_406 += sizeof( T_3 ) ;
V_405 = F_50 ( V_23 , V_406 ) ;
F_204 ( L_159 , V_405 ) ;
V_406 += sizeof( T_3 ) ;
V_405 = F_50 ( V_23 , V_406 ) ;
F_204 ( L_160 ,
V_405 ) ;
V_406 += sizeof( T_3 ) ;
V_405 = F_50 ( V_23 , V_406 ) ;
F_204 ( L_161 , V_405 ) ;
F_146 ( L_154 ) ;
}
static int F_205 ( struct V_17 * V_23 )
{
T_3 V_408 = 0 ;
T_3 V_409 = 0 ;
F_146 ( L_155 ) ;
V_408 = F_50 ( V_23 , V_407 ) ;
V_409 = ( V_408 - V_387 ) /
sizeof( struct V_389 ) ;
F_204 ( L_162 ,
V_409 , V_408 ) ;
F_146 ( L_154 ) ;
return V_409 ;
}
static int F_206 ( struct V_17 * V_23 ,
T_3 V_410 ,
T_3 V_411 ,
T_3 V_412 ,
int V_413 , int V_414 )
{
T_3 V_391 = V_415 | V_416 | V_417 | V_418 |
V_419 | V_420 | V_421 |
V_422 ;
struct V_389 * V_398 ;
T_3 V_423 = 0 ;
F_204 ( L_163 ,
V_410 , V_411 , V_412 ) ;
if ( V_23 -> V_395 . V_396 >= V_388 )
return - 1 ;
V_423 = V_23 -> V_395 . V_396 ;
V_398 = & V_23 -> V_395 . V_400 [ V_423 ] ;
V_23 -> V_395 . V_396 ++ ;
if ( V_413 )
V_391 |= V_424 ;
if ( V_414 )
V_391 |= V_425 ;
V_391 |= V_412 ;
V_398 -> V_37 = V_391 ^ V_410 ^ V_411 ;
V_398 -> V_426 = V_411 ;
V_398 -> V_427 = V_410 ;
V_398 -> V_391 = V_391 ;
return 0 ;
}
static int F_207 ( struct V_17 * V_23 , T_9 * V_410 ,
int V_428 , T_3 V_411 , T_3 V_4 )
{
int V_429 , V_7 ;
T_3 V_15 ;
F_146 ( L_150 ) ;
F_204 ( L_164 ,
V_428 , V_411 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_428 ; V_7 ++ ) {
V_15 = F_6 ( T_3 , V_4 - V_7 * V_430 , V_430 ) ;
V_429 = F_206 ( V_23 , V_410 [ V_7 ] ,
V_411 +
V_7 * V_430 , V_15 ,
0 , 0 ) ;
if ( V_429 ) {
F_204 ( L_165 ) ;
return - 1 ;
} else
F_204 ( L_166 ) ;
}
F_146 ( L_153 ) ;
return 0 ;
}
static int F_208 ( struct V_17 * V_23 )
{
T_3 V_431 = 0 , V_432 ;
T_3 V_433 = 0 ;
F_146 ( L_154 ) ;
V_431 = F_205 ( V_23 ) ;
F_204 ( L_167 ,
( int ) V_23 -> V_395 . V_396 ) ;
while ( V_431 < V_23 -> V_395 . V_396 ) {
F_186 ( 50 ) ;
V_432 = V_431 ;
V_431 = F_205 ( V_23 ) ;
if ( V_432 < V_431 ) {
V_433 = 0 ;
continue;
}
if ( ++ V_433 > 400 ) {
F_204 ( L_168 ) ;
F_203 ( V_23 ) ;
F_199 ( V_23 ) ;
return - 1 ;
}
}
F_199 ( V_23 ) ;
F_34 ( V_23 , V_401 ,
V_402 | V_403 ) ;
F_146 ( L_169 ) ;
return 0 ;
}
static void F_161 ( struct V_17 * V_23 )
{
struct V_434 * V_435 , * V_436 ;
struct V_437 * V_438 = NULL ;
unsigned long V_41 ;
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
F_209 (element, safe, &priv->ieee->network_list) {
V_438 = F_210 ( V_435 , struct V_437 , V_439 ) ;
if ( ! memcmp ( V_438 -> V_216 , V_23 -> V_216 , V_217 ) ) {
F_211 ( V_435 ) ;
F_212 ( & V_438 -> V_439 ,
& V_23 -> V_163 -> V_440 ) ;
}
}
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
}
static inline int F_213 ( struct V_17 * V_23 )
{
return F_36 ( V_23 , 0x90 ) == 0xd55555d5 ;
}
static int F_214 ( struct V_17 * V_23 , T_3 V_32 , T_3 V_36 ,
int V_441 )
{
int V_7 = 0 ;
do {
if ( ( F_36 ( V_23 , V_32 ) & V_36 ) == V_36 )
return V_7 ;
F_215 ( 10 ) ;
V_7 += 10 ;
} while ( V_7 < V_441 );
return - V_442 ;
}
static int F_216 ( struct V_17 * V_23 )
{
int V_155 ;
F_194 ( L_150 ) ;
F_34 ( V_23 , V_401 , V_403 ) ;
V_155 = F_214 ( V_23 , V_401 ,
V_402 , 100 ) ;
if ( V_155 < 0 ) {
F_46 ( L_170 ) ;
return - 1 ;
}
F_74 ( L_171 , V_155 ) ;
return V_155 ;
}
static void F_217 ( struct V_17 * V_23 )
{
F_194 ( L_150 ) ;
F_215 ( 5 ) ;
F_37 ( V_23 , V_401 , V_443 ) ;
F_215 ( 5 ) ;
}
static int F_218 ( struct V_17 * V_23 , T_2 * V_3 , T_1 V_4 )
{
int V_155 = 0 , V_7 , V_32 ;
T_2 V_444 = 0 ;
T_8 * V_445 ;
V_445 = ( T_8 * ) V_3 ;
F_194 ( L_150 ) ;
V_155 = F_216 ( V_23 ) ;
if ( V_155 < 0 )
return V_155 ;
for ( V_32 = V_446 ;
V_32 < V_447 ; V_32 += 4 ) {
F_35 ( V_23 , V_32 , 0 ) ;
}
memset ( & V_23 -> V_448 , 0 , sizeof( V_23 -> V_448 ) ) ;
F_12 ( V_23 , V_449 , V_450 ) ;
F_217 ( V_23 ) ;
F_12 ( V_23 , V_449 , V_451 ) ;
F_215 ( 1 ) ;
F_12 ( V_23 , V_174 , V_452 ) ;
F_215 ( 1 ) ;
F_12 ( V_23 , V_174 , 0 ) ;
F_215 ( 1 ) ;
F_7 ( V_23 , V_453 , 0x0 ) ;
F_7 ( V_23 , V_453 , V_454 ) ;
F_215 ( 1 ) ;
for ( V_7 = 0 ; V_7 < V_4 / 2 ; V_7 ++ )
F_10 ( V_23 , V_455 ,
F_219 ( V_445 [ V_7 ] ) ) ;
F_7 ( V_23 , V_453 , 0 ) ;
F_7 ( V_23 , V_453 , V_456 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ ) {
V_444 = F_119 ( V_23 , V_453 ) ;
if ( V_444 & V_457 )
break;
F_215 ( 1 ) ;
}
if ( V_444 & V_457 ) {
T_6 V_458 [ ( sizeof( V_23 -> V_448 ) + 3 ) / 4 ] ;
for ( V_7 = 0 ; V_7 < F_220 ( V_458 ) ; V_7 ++ )
V_458 [ V_7 ] =
F_178 ( F_50 ( V_23 ,
V_459 ) ) ;
memcpy ( & V_23 -> V_448 , V_458 ,
sizeof( V_23 -> V_448 ) ) ;
if ( V_23 -> V_448 . V_460 == 1
&& V_23 -> V_448 . V_461 == 1 ) {
V_155 = 0 ;
F_74
( L_172
L_173 ,
V_23 -> V_448 . V_462 ,
V_23 -> V_448 . V_462 ,
V_23 -> V_448 . V_463 ,
V_23 -> V_448 . V_463 ,
V_23 -> V_448 . V_464 [ 0 ] ,
V_23 -> V_448 . V_464 [ 1 ] ,
V_23 -> V_448 . V_464 [ 2 ] ,
V_23 -> V_448 . V_464 [ 3 ] ,
V_23 -> V_448 . V_464 [ 4 ] ) ;
} else {
F_74 ( L_174 ) ;
V_155 = - V_75 ;
}
} else {
F_74 ( L_175 ) ;
V_155 = - V_442 ;
}
F_7 ( V_23 , V_453 , 0 ) ;
return V_155 ;
}
static int F_221 ( struct V_17 * V_23 , T_2 * V_3 , T_1 V_4 )
{
int V_429 = - 1 ;
int V_465 = 0 ;
struct V_466 * V_467 ;
int V_468 = 0 ;
int V_7 ;
struct V_469 * V_470 ;
void * * V_471 ;
T_9 * V_472 ;
F_194 ( L_155 ) ;
V_471 = F_83 ( sizeof( void * ) * V_388 ,
V_148 ) ;
if ( ! V_471 )
return - V_473 ;
V_472 = F_83 ( sizeof( T_9 ) * V_388 ,
V_148 ) ;
if ( ! V_472 ) {
F_87 ( V_471 ) ;
return - V_473 ;
}
V_470 = F_222 ( L_176 , V_23 -> V_474 , V_430 , 0 , 0 ) ;
if ( ! V_470 ) {
F_46 ( L_177 ) ;
F_87 ( V_472 ) ;
F_87 ( V_471 ) ;
return - V_473 ;
}
V_429 = F_198 ( V_23 ) ;
F_223 ( V_23 -> V_395 . V_396 > 0 ) ;
do {
T_3 V_475 ;
T_2 * V_386 ;
int V_15 ;
int V_428 = 0 ;
V_467 = (struct V_466 * ) ( V_3 + V_465 ) ;
V_465 += sizeof( struct V_466 ) ;
V_475 = F_224 ( V_467 -> V_412 ) ;
V_386 = V_3 + V_465 ;
V_428 = ( V_475 + V_430 - 1 ) / V_430 ;
for ( V_7 = 0 ; V_7 < V_428 ; V_7 ++ ) {
V_471 [ V_468 ] = F_225 ( V_470 , V_148 ,
& V_472 [ V_468 ] ) ;
if ( ! V_471 [ V_468 ] ) {
V_429 = - V_473 ;
goto V_6;
}
V_15 = F_6 ( T_3 , V_475 - V_7 * V_430 ,
V_430 ) ;
memcpy ( V_471 [ V_468 ] , V_386 , V_15 ) ;
V_386 += V_15 ;
V_468 ++ ;
F_223 ( V_468 > V_388 ) ;
}
V_429 = F_207 ( V_23 , & V_472 [ V_468 - V_428 ] ,
V_428 , F_224 ( V_467 -> V_399 ) ,
V_475 ) ;
if ( V_429 ) {
F_74 ( L_178 ) ;
goto V_6;
}
V_465 += V_475 ;
} while ( V_465 < V_4 );
V_429 = F_202 ( V_23 ) ;
if ( V_429 ) {
F_46 ( L_179 ) ;
goto V_6;
}
V_429 = F_208 ( V_23 ) ;
if ( V_429 ) {
F_46 ( L_180 ) ;
goto V_6;
}
V_6:
for ( V_7 = 0 ; V_7 < V_468 ; V_7 ++ )
F_226 ( V_470 , V_471 [ V_7 ] , V_472 [ V_7 ] ) ;
F_227 ( V_470 ) ;
F_87 ( V_472 ) ;
F_87 ( V_471 ) ;
return V_429 ;
}
static int F_228 ( struct V_17 * V_23 )
{
int V_155 = 0 ;
F_35 ( V_23 , V_401 , V_403 ) ;
V_155 = F_214 ( V_23 , V_401 ,
V_402 , 500 ) ;
if ( V_155 < 0 ) {
F_46 ( L_181 ) ;
return V_155 ;
}
F_34 ( V_23 , V_401 , V_443 ) ;
return V_155 ;
}
static void F_229 ( struct V_17 * V_23 )
{
F_194 ( L_150 ) ;
F_37 ( V_23 , V_401 ,
V_402 |
V_403 |
V_443 ) ;
F_34 ( V_23 , V_476 ,
V_477 ) ;
F_194 ( L_153 ) ;
}
static int F_230 ( struct V_17 * V_23 )
{
int V_155 ;
F_194 ( L_150 ) ;
F_34 ( V_23 , V_476 , V_478 ) ;
F_35 ( V_23 , V_479 ,
V_480 ) ;
V_155 = F_214 ( V_23 , V_476 ,
V_481 , 250 ) ;
if ( V_155 < 0 )
F_74 ( L_182 ) ;
F_34 ( V_23 , V_401 , V_482 ) ;
F_186 ( 10 ) ;
F_34 ( V_23 , V_476 , V_478 ) ;
F_194 ( L_150 ) ;
return 0 ;
}
static int F_231 ( struct V_17 * V_23 )
{
int V_155 = 0 ;
unsigned long V_41 ;
F_194 ( L_150 ) ;
V_155 = F_230 ( V_23 ) ;
F_41 ( & V_23 -> V_98 , V_41 ) ;
V_23 -> V_37 &= ~ V_227 ;
F_144 ( & V_23 -> V_228 ) ;
V_23 -> V_37 &= ~ ( V_318 | V_316 ) ;
F_144 ( & V_23 -> V_483 ) ;
F_42 ( & V_23 -> V_98 , V_41 ) ;
F_194 ( L_153 ) ;
return V_155 ;
}
static int F_232 ( struct V_17 * V_23 ,
const struct V_484 * * V_485 , const char * V_158 )
{
struct V_486 * V_487 ;
int V_155 ;
V_155 = F_233 ( V_485 , V_158 , & V_23 -> V_474 -> V_166 ) ;
if ( V_155 < 0 ) {
F_46 ( L_183 , V_158 , V_155 ) ;
return V_155 ;
}
if ( ( * V_485 ) -> V_15 < sizeof( * V_487 ) ) {
F_46 ( L_184 , V_158 , ( * V_485 ) -> V_15 ) ;
return - V_75 ;
}
V_487 = ( void * ) ( * V_485 ) -> V_3 ;
if ( ( * V_485 ) -> V_15 < sizeof( * V_487 ) + F_224 ( V_487 -> V_488 ) +
F_224 ( V_487 -> V_489 ) + F_224 ( V_487 -> V_490 ) ) {
F_46 ( L_185 ,
V_158 , ( * V_485 ) -> V_15 ) ;
return - V_75 ;
}
F_74 ( L_186 ,
V_158 ,
F_224 ( V_487 -> V_491 ) >> 16 ,
F_224 ( V_487 -> V_491 ) & 0xff ,
( * V_485 ) -> V_15 - sizeof( * V_487 ) ) ;
return 0 ;
}
static void F_234 ( struct V_17 * V_23 ,
struct V_492 * V_493 )
{
unsigned long V_41 ;
int V_7 ;
F_41 ( & V_493 -> V_98 , V_41 ) ;
F_235 ( & V_493 -> V_494 ) ;
F_235 ( & V_493 -> V_495 ) ;
for ( V_7 = 0 ; V_7 < V_496 + V_497 ; V_7 ++ ) {
if ( V_493 -> V_470 [ V_7 ] . V_498 != NULL ) {
F_236 ( V_23 -> V_474 , V_493 -> V_470 [ V_7 ] . V_499 ,
V_500 , V_501 ) ;
F_237 ( V_493 -> V_470 [ V_7 ] . V_498 ) ;
V_493 -> V_470 [ V_7 ] . V_498 = NULL ;
}
F_212 ( & V_493 -> V_470 [ V_7 ] . V_439 , & V_493 -> V_495 ) ;
}
V_493 -> V_502 = V_493 -> V_503 = 0 ;
V_493 -> V_504 = 0 ;
F_42 ( & V_493 -> V_98 , V_41 ) ;
}
static void F_238 ( void )
{
if ( V_505 ) {
F_239 ( V_485 ) ;
V_485 = NULL ;
V_505 = 0 ;
}
}
static int F_240 ( struct V_17 * V_23 )
{
#ifndef F_241
const struct V_484 * V_485 = NULL ;
#endif
struct V_486 * V_487 ;
T_2 * V_506 , * V_507 , * V_508 ;
T_2 * V_158 = NULL ;
int V_155 = 0 , V_509 = 3 ;
switch ( V_23 -> V_163 -> V_510 ) {
case V_511 :
V_158 = L_187 ;
break;
#ifdef F_242
case V_512 :
V_158 = L_188 ;
break;
#endif
case V_513 :
V_158 = L_189 ;
break;
}
if ( ! V_158 ) {
V_155 = - V_75 ;
goto error;
}
#ifdef F_241
if ( ! V_505 ) {
#endif
V_155 = F_232 ( V_23 , & V_485 , V_158 ) ;
if ( V_155 < 0 )
goto error;
#ifdef F_241
}
#endif
V_487 = ( void * ) V_485 -> V_3 ;
V_506 = & V_487 -> V_3 [ 0 ] ;
V_507 = & V_487 -> V_3 [ F_224 ( V_487 -> V_488 ) ] ;
V_508 = & V_487 -> V_3 [ F_224 ( V_487 -> V_488 ) +
F_224 ( V_487 -> V_489 ) ] ;
if ( V_155 < 0 )
goto error;
if ( ! V_23 -> V_493 )
V_23 -> V_493 = F_243 ( V_23 ) ;
else
F_234 ( V_23 , V_23 -> V_493 ) ;
if ( ! V_23 -> V_493 ) {
F_46 ( L_190 ) ;
goto error;
}
V_514:
F_35 ( V_23 , V_39 , ~ V_40 ) ;
V_23 -> V_37 &= ~ V_38 ;
F_35 ( V_23 , V_222 , V_40 ) ;
F_228 ( V_23 ) ;
V_155 = F_231 ( V_23 ) ;
if ( V_155 < 0 ) {
F_46 ( L_191 ) ;
goto error;
}
F_196 ( V_23 , V_515 ,
V_516 - V_515 ) ;
V_155 = F_221 ( V_23 , V_506 , F_224 ( V_487 -> V_488 ) ) ;
if ( V_155 < 0 ) {
F_46 ( L_192 , V_155 ) ;
goto error;
}
F_229 ( V_23 ) ;
V_155 = F_214 ( V_23 , V_222 ,
V_237 , 500 ) ;
if ( V_155 < 0 ) {
F_46 ( L_193 ) ;
goto error;
}
F_74 ( L_194 , V_155 ) ;
F_35 ( V_23 , V_222 , V_237 ) ;
V_155 = F_218 ( V_23 , V_507 , F_224 ( V_487 -> V_489 ) ) ;
if ( V_155 < 0 ) {
F_46 ( L_195 , V_155 ) ;
goto error;
}
F_228 ( V_23 ) ;
V_155 = F_221 ( V_23 , V_508 , F_224 ( V_487 -> V_490 ) ) ;
if ( V_155 < 0 ) {
F_46 ( L_196 , V_155 ) ;
goto error;
}
#ifdef F_241
V_505 = 1 ;
#endif
F_35 ( V_23 , V_385 , 0 ) ;
V_155 = F_244 ( V_23 ) ;
if ( V_155 < 0 ) {
F_46 ( L_197 ) ;
goto error;
}
F_35 ( V_23 , V_39 , ~ V_40 ) ;
F_35 ( V_23 , V_222 , V_40 ) ;
F_229 ( V_23 ) ;
if ( F_36 ( V_23 , V_222 ) & V_247 ) {
if ( V_509 > 0 ) {
F_93 ( L_198 ) ;
V_509 -- ;
goto V_514;
}
F_46 ( L_199 ) ;
V_155 = - V_303 ;
goto error;
}
V_155 = F_214 ( V_23 , V_222 ,
V_237 , 500 ) ;
if ( V_155 < 0 ) {
F_46 ( L_200 ) ;
goto error;
}
F_74 ( L_201 , V_155 ) ;
F_35 ( V_23 , V_222 , V_237 ) ;
V_23 -> V_173 = 1 ;
F_193 ( V_23 ) ;
F_40 ( V_23 ) ;
F_245 ( V_23 ) ;
F_35 ( V_23 , V_517 , V_23 -> V_493 -> V_502 ) ;
F_35 ( V_23 , V_222 , V_40 ) ;
#ifndef F_241
F_239 ( V_485 ) ;
#endif
return 0 ;
error:
if ( V_23 -> V_493 ) {
F_246 ( V_23 , V_23 -> V_493 ) ;
V_23 -> V_493 = NULL ;
}
F_247 ( V_23 ) ;
if ( V_485 )
F_239 ( V_485 ) ;
#ifdef F_241
V_505 = 0 ;
V_485 = NULL ;
#endif
return V_155 ;
}
static int F_248 ( const struct V_492 * V_518 )
{
int V_519 = V_518 -> V_502 - V_518 -> V_503 ;
if ( V_519 <= 0 )
V_519 += V_497 ;
V_519 -= 2 ;
if ( V_519 < 0 )
V_519 = 0 ;
return V_519 ;
}
static inline int F_249 ( const struct V_520 * V_518 )
{
int V_519 = V_518 -> V_521 - V_518 -> V_522 ;
if ( V_519 <= 0 )
V_519 += V_518 -> V_523 ;
V_519 -= 2 ;
if ( V_519 < 0 )
V_519 = 0 ;
return V_519 ;
}
static inline int F_250 ( int V_397 , int V_523 )
{
return ( ++ V_397 == V_523 ) ? 0 : V_397 ;
}
static void F_251 ( struct V_17 * V_23 , struct V_520 * V_518 ,
int V_2 , T_3 V_502 , T_3 V_503 , T_3 V_137 , T_3 V_15 )
{
V_518 -> V_523 = V_2 ;
V_518 -> V_524 = V_518 -> V_523 / 4 ;
if ( V_518 -> V_524 < 4 )
V_518 -> V_524 = 4 ;
V_518 -> V_525 = V_518 -> V_523 / 8 ;
if ( V_518 -> V_525 < 2 )
V_518 -> V_525 = 2 ;
V_518 -> V_522 = V_518 -> V_521 = 0 ;
V_518 -> V_526 = V_502 ;
V_518 -> V_527 = V_503 ;
F_35 ( V_23 , V_137 , V_518 -> V_499 ) ;
F_35 ( V_23 , V_15 , V_2 ) ;
F_35 ( V_23 , V_502 , 0 ) ;
F_35 ( V_23 , V_503 , 0 ) ;
F_24 ( V_23 , 0x90 ) ;
}
static int F_252 ( struct V_17 * V_23 ,
struct V_528 * V_518 ,
int V_2 , T_3 V_502 , T_3 V_503 , T_3 V_137 , T_3 V_15 )
{
struct V_474 * V_166 = V_23 -> V_474 ;
V_518 -> V_529 = F_83 ( sizeof( V_518 -> V_529 [ 0 ] ) * V_2 , V_148 ) ;
if ( ! V_518 -> V_529 ) {
F_46 ( L_202 ) ;
return - V_473 ;
}
V_518 -> V_530 =
F_253 ( V_166 , sizeof( V_518 -> V_530 [ 0 ] ) * V_2 , & V_518 -> V_518 . V_499 ) ;
if ( ! V_518 -> V_530 ) {
F_46 ( L_203 ,
sizeof( V_518 -> V_530 [ 0 ] ) * V_2 ) ;
F_87 ( V_518 -> V_529 ) ;
V_518 -> V_529 = NULL ;
return - V_473 ;
}
F_251 ( V_23 , & V_518 -> V_518 , V_2 , V_502 , V_503 , V_137 , V_15 ) ;
return 0 ;
}
static void F_254 ( struct V_17 * V_23 ,
struct V_528 * V_230 )
{
struct V_531 * V_530 = & V_230 -> V_530 [ V_230 -> V_518 . V_521 ] ;
struct V_474 * V_166 = V_23 -> V_474 ;
int V_7 ;
if ( V_530 -> V_532 . V_533 == V_534 )
return;
if ( F_224 ( V_530 -> V_535 . V_3 . V_536 ) > V_537 ) {
F_46 ( L_204 ,
F_224 ( V_530 -> V_535 . V_3 . V_536 ) ) ;
return;
}
for ( V_7 = 0 ; V_7 < F_224 ( V_530 -> V_535 . V_3 . V_536 ) ; V_7 ++ ) {
F_236 ( V_166 , F_224 ( V_530 -> V_535 . V_3 . V_538 [ V_7 ] ) ,
F_219 ( V_530 -> V_535 . V_3 . V_475 [ V_7 ] ) ,
V_539 ) ;
if ( V_230 -> V_529 [ V_230 -> V_518 . V_521 ] ) {
F_255 ( V_230 -> V_529 [ V_230 -> V_518 . V_521 ] ) ;
V_230 -> V_529 [ V_230 -> V_518 . V_521 ] = NULL ;
}
}
}
static void F_256 ( struct V_17 * V_23 , struct V_528 * V_230 )
{
struct V_520 * V_518 = & V_230 -> V_518 ;
struct V_474 * V_166 = V_23 -> V_474 ;
if ( V_518 -> V_523 == 0 )
return;
for (; V_518 -> V_522 != V_518 -> V_521 ;
V_518 -> V_521 = F_250 ( V_518 -> V_521 , V_518 -> V_523 ) ) {
F_254 ( V_23 , V_230 ) ;
}
F_257 ( V_166 , sizeof( V_230 -> V_530 [ 0 ] ) * V_518 -> V_523 , V_230 -> V_530 ,
V_518 -> V_499 ) ;
F_87 ( V_230 -> V_529 ) ;
memset ( V_230 , 0 , sizeof( * V_230 ) ) ;
}
static void F_247 ( struct V_17 * V_23 )
{
F_256 ( V_23 , & V_23 -> V_226 ) ;
F_256 ( V_23 , & V_23 -> V_230 [ 0 ] ) ;
F_256 ( V_23 , & V_23 -> V_230 [ 1 ] ) ;
F_256 ( V_23 , & V_23 -> V_230 [ 2 ] ) ;
F_256 ( V_23 , & V_23 -> V_230 [ 3 ] ) ;
}
static void F_258 ( struct V_17 * V_23 , T_2 * V_216 )
{
V_216 [ 0 ] = V_23 -> V_540 [ 0 ] ;
V_216 [ 1 ] = V_23 -> V_540 [ 1 ] ;
V_216 [ 2 ] = V_23 -> V_540 [ 2 ] ;
F_176 ( & V_216 [ 3 ] , V_217 - 3 ) ;
V_216 [ 0 ] &= 0xfe ;
V_216 [ 0 ] |= 0x02 ;
}
static T_2 F_259 ( struct V_17 * V_23 , T_2 * V_216 )
{
struct V_541 V_542 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_23 -> V_543 ; V_7 ++ ) {
if ( ! memcmp ( V_23 -> V_544 [ V_7 ] , V_216 , V_217 ) ) {
V_23 -> V_545 = 0 ;
if ( ! ( V_23 -> V_59 & V_546 ) )
V_23 -> V_59 &= ~ V_547 ;
return V_7 ;
}
}
if ( V_7 == V_548 )
return V_549 ;
F_165 ( L_205 , V_216 ) ;
V_542 . V_550 = 0 ;
V_542 . V_551 = 0 ;
memcpy ( V_542 . V_540 , V_216 , V_217 ) ;
memcpy ( V_23 -> V_544 [ V_7 ] , V_216 , V_217 ) ;
F_32 ( V_23 , V_552 + V_7 * sizeof( V_542 ) ,
& V_542 , sizeof( V_542 ) ) ;
V_23 -> V_543 ++ ;
return V_7 ;
}
static T_2 F_260 ( struct V_17 * V_23 , T_2 * V_216 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_23 -> V_543 ; V_7 ++ )
if ( ! memcmp ( V_23 -> V_544 [ V_7 ] , V_216 , V_217 ) )
return V_7 ;
return V_549 ;
}
static void F_261 ( struct V_17 * V_23 , int V_553 )
{
int V_554 ;
if ( V_23 -> V_37 & V_240 ) {
F_262 ( L_206 ) ;
F_128 ( & V_23 -> V_555 ) ;
return;
}
if ( ! ( V_23 -> V_37 & V_103 ) ) {
F_262 ( L_207 ) ;
return;
}
F_262 ( L_208
L_209 ,
V_23 -> V_556 . V_216 ,
V_23 -> V_556 . V_197 ) ;
V_23 -> V_37 &= ~ ( V_240 | V_103 ) ;
V_23 -> V_37 |= V_557 ;
if ( V_553 )
V_23 -> V_556 . V_558 = V_559 ;
else
V_23 -> V_556 . V_558 = V_560 ;
V_554 = F_173 ( V_23 , & V_23 -> V_556 ) ;
if ( V_554 ) {
F_142 ( L_210
L_65 ) ;
return;
}
}
static int F_263 ( void * V_3 )
{
struct V_17 * V_23 = V_3 ;
if ( ! ( V_23 -> V_37 & ( V_103 | V_240 ) ) )
return 0 ;
F_261 ( V_3 , 0 ) ;
F_264 ( V_23 -> V_167 ) ;
return 1 ;
}
static void F_265 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_555 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_263 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_266 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_561 ) ;
#ifdef F_267
if ( V_23 -> V_157 && F_92 ( V_23 -> V_157 ) ) {
V_23 -> V_307 . V_562 = 1 ;
V_23 -> V_307 . V_563 = 1 ;
V_23 -> V_307 . V_564 = 1 ;
V_23 -> V_307 . V_565 = 1 ;
}
#endif
F_156 ( V_23 ) ;
}
static const char * F_268 ( T_4 V_37 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_220 ( V_566 ) ; V_7 ++ )
if ( V_566 [ V_7 ] . V_37 == ( V_37 & 0xff ) )
return V_566 [ V_7 ] . V_567 ;
return L_211 ;
}
static void inline F_269 ( struct V_568 * V_569 )
{
memset ( V_569 , 0 , sizeof( * V_569 ) ) ;
}
static T_10 F_270 ( T_10 V_570 , T_10 V_21 , T_2 V_571 )
{
return ( ( V_571 - 1 ) * V_570 + V_21 ) / V_571 ;
}
static void F_271 ( struct V_568 * V_569 , T_10 V_21 )
{
V_569 -> V_572 -= V_569 -> V_573 [ V_569 -> V_194 ] ;
V_569 -> V_572 += V_21 ;
V_569 -> V_573 [ V_569 -> V_194 ++ ] = V_21 ;
if ( F_29 ( V_569 -> V_194 == V_574 ) ) {
V_569 -> V_575 = 1 ;
V_569 -> V_194 = 0 ;
}
}
static T_10 F_272 ( struct V_568 * V_569 )
{
if ( ! F_29 ( V_569 -> V_575 ) ) {
if ( V_569 -> V_194 )
return V_569 -> V_572 / V_569 -> V_194 ;
return 0 ;
}
return V_569 -> V_572 / V_574 ;
}
static void F_273 ( struct V_17 * V_23 )
{
T_3 V_4 = sizeof( T_3 ) ;
V_23 -> V_576 = 0 ;
F_269 ( & V_23 -> V_577 ) ;
V_23 -> V_578 = - 60 ;
V_23 -> V_579 = - 85 + 0x100 ;
V_23 -> V_580 = 0 ;
V_23 -> V_581 = 0 ;
V_23 -> V_582 = 0 ;
V_23 -> V_583 = 0 ;
V_23 -> V_584 = 0 ;
F_48 ( V_23 , V_585 ,
& V_23 -> V_586 , & V_4 ) ;
F_48 ( V_23 , V_587 ,
& V_23 -> V_584 , & V_4 ) ;
V_23 -> V_545 = 0 ;
V_23 -> V_588 = 0 ;
V_23 -> V_589 = 0 ;
V_23 -> V_590 = 0 ;
}
static T_3 F_274 ( struct V_17 * V_23 )
{
T_3 V_7 = 0x80000000 ;
T_3 V_36 = V_23 -> V_591 ;
if ( V_23 -> V_556 . V_344 == V_349 )
V_36 &= V_592 ;
while ( V_7 && ! ( V_36 & V_7 ) )
V_7 >>= 1 ;
switch ( V_7 ) {
case V_593 :
return 1000000 ;
case V_594 :
return 2000000 ;
case V_595 :
return 5500000 ;
case V_596 :
return 6000000 ;
case V_597 :
return 9000000 ;
case V_598 :
return 11000000 ;
case V_599 :
return 12000000 ;
case V_600 :
return 18000000 ;
case V_601 :
return 24000000 ;
case V_602 :
return 36000000 ;
case V_603 :
return 48000000 ;
case V_604 :
return 54000000 ;
}
if ( V_23 -> V_163 -> V_118 == V_605 )
return 11000000 ;
else
return 54000000 ;
}
static T_3 F_275 ( struct V_17 * V_23 )
{
T_3 V_606 , V_4 = sizeof( V_606 ) ;
int V_554 ;
if ( ! ( V_23 -> V_37 & V_103 ) )
return 0 ;
if ( V_23 -> V_589 > V_607 ) {
V_554 = F_48 ( V_23 , V_608 , & V_606 ,
& V_4 ) ;
if ( V_554 ) {
F_74 ( L_212 ) ;
return 0 ;
}
} else
return F_274 ( V_23 ) ;
switch ( V_606 ) {
case V_609 :
return 1000000 ;
case V_610 :
return 2000000 ;
case V_611 :
return 5500000 ;
case V_612 :
return 6000000 ;
case V_613 :
return 9000000 ;
case V_614 :
return 11000000 ;
case V_615 :
return 12000000 ;
case V_616 :
return 18000000 ;
case V_617 :
return 24000000 ;
case V_618 :
return 36000000 ;
case V_619 :
return 48000000 ;
case V_620 :
return 54000000 ;
}
return 0 ;
}
static void F_276 ( struct V_17 * V_23 )
{
T_3 V_621 , V_622 , V_623 ;
T_3 V_624 , V_625 , V_626 ;
T_3 V_627 , V_628 ;
T_3 V_576 = 0 ;
T_3 V_4 = sizeof( T_3 ) ;
T_10 V_629 ;
T_3 V_630 , V_631 , V_632 , V_633 ,
V_634 ;
T_3 V_635 ;
if ( ! ( V_23 -> V_37 & V_103 ) ) {
V_23 -> V_576 = 0 ;
return;
}
F_48 ( V_23 , V_636 ,
& V_23 -> V_588 , & V_4 ) ;
V_628 = V_23 -> V_588 - V_23 -> V_581 ;
V_23 -> V_581 = V_23 -> V_588 ;
if ( V_23 -> V_556 . V_637 ) {
V_627 = V_628 *
( V_192 * F_219 ( V_23 -> V_556 . V_637 ) ) /
( V_638 * 10 ) ;
} else {
V_627 = 0 ;
}
F_271 ( & V_23 -> V_577 , V_627 ) ;
F_48 ( V_23 , V_585 , & V_621 , & V_4 ) ;
V_622 = V_621 - V_23 -> V_586 ;
V_23 -> V_586 = V_621 ;
F_48 ( V_23 , V_587 , & V_624 , & V_4 ) ;
V_625 = V_624 - V_23 -> V_584 ;
V_23 -> V_584 = V_624 ;
V_623 = V_23 -> V_590 - V_23 -> V_582 ;
V_23 -> V_582 = V_23 -> V_590 ;
V_626 = V_23 -> V_589 - V_23 -> V_583 ;
V_23 -> V_583 = V_23 -> V_589 ;
#define F_277 5
V_630 = 100 - V_627 ;
if ( V_630 < F_277 )
V_630 = 0 ;
else
V_630 = ( V_630 - F_277 ) * 100 /
( 100 - F_277 ) ;
F_278 ( L_213 ,
V_630 , V_627 ) ;
V_23 -> V_580 = F_275 ( V_23 ) ;
V_635 = F_274 ( V_23 ) ;
V_634 = V_23 -> V_580 * 40 / V_635 + 60 ;
F_278 ( L_214 ,
V_634 , V_23 -> V_580 / 1000000 ) ;
if ( V_623 > 100 && V_623 + V_622 )
V_633 = 100 - ( V_622 * 100 ) /
( V_623 + V_622 ) ;
else
V_633 = 100 ;
F_278 ( L_215 ,
V_633 , V_622 , V_623 ) ;
if ( V_626 > 100 && V_626 + V_625 )
V_632 = 100 - ( V_625 * 100 ) /
( V_626 + V_625 ) ;
else
V_632 = 100 ;
F_278 ( L_216 ,
V_632 , V_625 , V_626 ) ;
V_629 = V_23 -> V_578 ;
V_631 =
( 100 *
( V_23 -> V_163 -> V_639 - V_23 -> V_163 -> V_640 ) *
( V_23 -> V_163 -> V_639 - V_23 -> V_163 -> V_640 ) -
( V_23 -> V_163 -> V_639 - V_629 ) *
( 15 * ( V_23 -> V_163 -> V_639 - V_23 -> V_163 -> V_640 ) +
62 * ( V_23 -> V_163 -> V_639 - V_629 ) ) ) /
( ( V_23 -> V_163 -> V_639 - V_23 -> V_163 -> V_640 ) *
( V_23 -> V_163 -> V_639 - V_23 -> V_163 -> V_640 ) ) ;
if ( V_631 > 100 )
V_631 = 100 ;
else if ( V_631 < 1 )
V_631 = 0 ;
F_278 ( L_217 ,
V_631 , V_629 ) ;
V_576 = F_3 ( V_633 , V_631 ) ;
V_576 = F_3 ( V_632 , V_576 ) ;
V_576 = F_3 ( V_634 , V_576 ) ;
V_576 = F_3 ( V_630 , V_576 ) ;
if ( V_576 == V_630 )
F_278 ( L_218 ,
V_576 ) ;
if ( V_576 == V_634 )
F_278 ( L_219 ,
V_576 ) ;
if ( V_576 == V_632 )
F_278 ( L_220 ,
V_576 ) ;
if ( V_576 == V_633 )
F_278 ( L_221 ,
V_576 ) ;
if ( V_576 == V_631 )
F_278 ( L_222 ,
V_576 ) ;
V_23 -> V_576 = V_576 ;
F_56 ( & V_23 -> V_641 , V_638 ) ;
}
static void F_279 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_641 . V_107 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_276 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_280 ( struct V_17 * V_23 ,
int V_642 )
{
V_23 -> V_643 = V_642 ;
if ( V_642 > V_23 -> V_644 &&
V_23 -> V_37 & V_103 ) {
F_281 ( V_645 | V_646 |
V_647 | V_648 ,
L_223 , V_642 ) ;
V_23 -> V_37 &= ~ V_649 ;
if ( V_23 -> V_37 & V_318 ) {
F_281 ( V_645 | V_646 |
V_647 ,
L_224 ) ;
F_128 ( & V_23 -> V_650 ) ;
}
F_128 ( & V_23 -> V_555 ) ;
return;
}
if ( V_23 -> V_37 & V_649 ) {
F_281 ( V_646 | V_647 ,
L_225 ,
V_642 ) ;
return;
}
if ( V_651 &&
( V_642 > V_23 -> V_652 &&
V_642 <= V_23 -> V_644 ) ) {
F_281 ( V_646 | V_647 ,
L_226
L_227 , V_642 ) ;
if ( ! ( V_23 -> V_37 & V_649 ) ) {
V_23 -> V_37 |= V_649 ;
if ( ! ( V_23 -> V_37 & V_318 ) )
F_56 ( & V_23 -> V_186 , 0 ) ;
}
return;
}
if ( V_23 -> V_37 & V_318 &&
V_642 > V_653 ) {
F_281 ( V_645 | V_646 | V_647 ,
L_224 ) ;
F_128 ( & V_23 -> V_650 ) ;
}
F_282 ( L_228 , V_642 ) ;
}
static void F_283 ( struct V_106 * V_107 )
{
union V_210 V_211 ;
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_189 . V_107 ) ;
V_211 . V_3 . V_412 = 0 ;
V_211 . V_3 . V_41 = 0 ;
F_139 ( V_23 -> V_167 , V_654 , & V_211 , NULL ) ;
}
static void F_284 ( struct V_17 * V_23 )
{
if ( ! V_23 -> V_655 ) {
if ( ! F_285 ( & V_23 -> V_189 ) )
F_56 ( & V_23 -> V_189 ,
F_129 ( F_286 ( 4000 ) ) ) ;
} else {
union V_210 V_211 ;
V_23 -> V_655 = 0 ;
F_64 ( & V_23 -> V_189 ) ;
V_211 . V_3 . V_412 = 0 ;
V_211 . V_3 . V_41 = 0 ;
F_139 ( V_23 -> V_167 , V_654 , & V_211 , NULL ) ;
}
}
static void F_287 ( struct V_17 * V_23 ,
struct F_287 * V_656 )
{
F_288 ( V_308 ) ;
T_4 V_15 = F_219 ( V_656 -> V_15 ) ;
F_282 ( L_229 , V_656 -> V_657 , V_15 ) ;
switch ( V_656 -> V_657 ) {
case V_658 : {
struct V_659 * V_660 = & V_656 -> V_535 . V_660 ;
switch ( V_660 -> V_661 ) {
case V_662 : {
F_281 ( V_646 | V_647 |
V_648 ,
L_230 ,
F_289 ( V_308 , V_23 -> V_663 ,
V_23 -> V_664 ) ,
V_23 -> V_216 ) ;
switch ( V_23 -> V_163 -> V_510 ) {
case V_513 :
memcpy ( V_23 -> V_163 -> V_216 ,
V_23 -> V_216 , V_217 ) ;
break;
case V_511 :
memcpy ( V_23 -> V_163 -> V_216 ,
V_23 -> V_216 , V_217 ) ;
V_23 -> V_543 = 0 ;
F_262
( L_231 ) ;
F_56 (
& V_23 -> V_665 ,
F_219 ( V_23 ->
V_556 .
V_637 ) ) ;
break;
}
V_23 -> V_37 &= ~ V_240 ;
V_23 -> V_37 |= V_103 ;
F_128 ( & V_23 -> V_561 ) ;
#ifdef F_290
#define F_291 ( T_11 ) WLAN_FC_GET_STYPE( \
le16_to_cpu(((struct ieee80211_hdr *)(x))->frame_control))
if ( ( V_23 -> V_37 & V_666 ) &&
( F_291 ( & V_656 -> V_535 . V_485 )
== V_667 ) ) {
if ( ( sizeof
( struct
V_668 )
<= V_15 )
&& ( V_15 <= 2314 ) ) {
struct
V_669
V_670 = {
. V_4 = V_15 - 1 ,
} ;
F_292
( L_232
L_233 , V_15 ) ;
F_293 ( V_23 ->
V_163 ,
(struct
V_671
* )
& V_656 -> V_535 . V_485 , & V_670 ) ;
}
}
#endif
F_128 ( & V_23 -> V_672 ) ;
break;
}
case V_673 : {
if ( V_23 ->
V_37 & ( V_103 |
V_666 ) ) {
struct V_674 * V_675
= & V_656 -> V_535 . V_675 ;
F_281 ( V_646 |
V_647 |
V_648 ,
L_234
L_235
L_236 ,
F_289 ( V_308 ,
V_23 ->
V_663 ,
V_23 ->
V_664 ) ,
V_23 -> V_216 ,
F_219 ( V_675 -> V_37 ) ,
F_268
( F_219
( V_675 -> V_37 ) ) ) ;
V_23 -> V_37 &=
~ ( V_240 |
V_666 |
V_103 ) ;
F_128 ( & V_23 -> V_241 ) ;
break;
}
F_281 ( V_646 | V_647 |
V_648 ,
L_237 ,
F_289 ( V_308 , V_23 -> V_663 ,
V_23 -> V_664 ) ,
V_23 -> V_216 ) ;
break;
}
case V_676 : {
if ( V_23 -> V_37 & V_666 ) {
struct
V_668
* V_677 ;
V_677 =
(struct
V_668
* ) & V_656 -> V_535 . V_485 ;
F_281 ( V_646 |
V_647 |
V_648 ,
L_238 ,
F_219 ( V_677 -> V_37 ) ,
F_268
( F_219
( V_677 -> V_37 ) ) ) ;
}
F_281 ( V_646 | V_647 |
V_648 ,
L_239 ,
F_289 ( V_308 , V_23 -> V_663 ,
V_23 -> V_664 ) ,
V_23 -> V_216 ) ;
V_23 -> V_37 &=
~ ( V_557 |
V_240 |
V_103 | V_666 ) ;
if ( V_23 -> V_117
&& ( V_23 -> V_117 ->
V_314 &
V_315 ) )
F_161
( V_23 ) ;
F_128 ( & V_23 -> V_241 ) ;
break;
}
case V_678 :
break;
default:
F_46 ( L_240 ,
V_660 -> V_661 ) ;
break;
}
break;
}
case V_679 : {
struct V_674 * V_675 = & V_656 -> V_535 . V_675 ;
switch ( V_675 -> V_661 ) {
case V_673 :
F_281 ( V_646 | V_647 ,
L_237 ,
F_289 ( V_308 , V_23 -> V_663 ,
V_23 -> V_664 ) ,
V_23 -> V_216 ) ;
V_23 -> V_37 |= V_666 ;
break;
case V_676 :
if ( V_23 -> V_37 & V_666 ) {
F_281 ( V_646 | V_647 |
V_648 ,
L_241 ,
F_219 ( V_675 -> V_37 ) ,
F_268 ( F_219
( V_675 ->
V_37 ) ) ) ;
}
F_281 ( V_646 | V_647 |
V_648 ,
L_242 ,
F_289 ( V_308 , V_23 -> V_663 ,
V_23 -> V_664 ) ,
V_23 -> V_216 ) ;
V_23 -> V_37 &= ~ ( V_240 |
V_666 |
V_103 ) ;
F_128 ( & V_23 -> V_241 ) ;
break;
case V_680 :
F_281 ( V_646 | V_647 |
V_648 , L_243 ) ;
break;
case V_681 :
F_281 ( V_646 | V_647 |
V_648 , L_244 ) ;
break;
case V_682 :
F_281 ( V_646 | V_647 |
V_648 , L_245 ) ;
break;
case V_683 :
F_281 ( V_646 | V_647 |
V_648 , L_246 ) ;
break;
case V_684 :
F_281 ( V_646 | V_647 |
V_648 , L_247 ) ;
break;
case V_685 :
F_281 ( V_646 | V_647 |
V_648 , L_248 ) ;
break;
case V_686 :
F_281 ( V_646 | V_647 |
V_648 , L_249 ) ;
break;
case V_687 :
F_281 ( V_646 | V_647 |
V_648 , L_250 ) ;
break;
case V_688 :
F_281 ( V_646 | V_647 |
V_648 , L_251 ) ;
break;
case V_678 :
F_281 ( V_646 | V_647 |
V_648 , L_252 ) ;
break;
case V_662 :
F_281 ( V_646 | V_647 |
V_648 , L_253 ) ;
break;
default:
F_282 ( L_254 ,
V_675 -> V_661 ) ;
break;
}
break;
}
case V_689 : {
struct V_690 * T_11 =
& V_656 -> V_535 . V_691 ;
if ( V_15 == sizeof( * T_11 ) ) {
F_165 ( L_255 ,
T_11 -> V_692 ) ;
} else {
F_165 ( L_256
L_257 ,
V_15 , sizeof( * T_11 ) ) ;
}
break;
}
case V_693 : {
struct V_694 * T_11 = & V_656 -> V_535 . V_695 ;
if ( V_15 == sizeof( * T_11 ) ) {
F_165
( L_258
L_259 , T_11 -> V_696 ,
T_11 -> V_346 , T_11 -> V_37 ) ;
} else {
F_46 ( L_260
L_257 ,
V_15 , sizeof( * T_11 ) ) ;
}
V_23 -> V_37 &=
~ ( V_318 | V_316 ) ;
F_144 ( & V_23 -> V_483 ) ;
F_64 ( & V_23 -> V_319 ) ;
if ( V_23 -> V_37 & V_697 )
break;
V_23 -> V_163 -> V_698 ++ ;
#ifdef F_242
if ( V_23 -> V_163 -> V_510 == V_512 ) {
V_23 -> V_37 |= V_699 ;
F_56 ( & V_23 -> V_186 , 0 ) ;
break;
}
V_23 -> V_37 &= ~ V_699 ;
#endif
if ( V_23 -> V_37 & V_700 )
F_56 ( & V_23 -> V_187 , 0 ) ;
if ( ! ( V_23 -> V_37 & ( V_103 |
V_240 |
V_649 |
V_557 ) ) )
F_128 ( & V_23 -> V_330 ) ;
else if ( V_23 -> V_37 & V_649 ) {
if ( T_11 -> V_37 == V_701 )
F_128 ( & V_23 -> V_702 ) ;
else
V_23 -> V_37 &= ~ V_649 ;
} else if ( V_23 -> V_37 & V_703 )
F_56 ( & V_23 -> V_186 , 0 ) ;
else if ( V_23 -> V_59 & V_704
&& V_23 -> V_37 & V_103 )
F_56 ( & V_23 -> V_186 ,
F_129 ( V_192 ) ) ;
if ( T_11 -> V_37 == V_701 )
F_284 ( V_23 ) ;
break;
}
case V_705 : {
struct V_706 * T_11 = & V_656 -> V_535 . V_707 ;
if ( V_15 == sizeof( * T_11 ) )
F_46 ( L_261 ,
F_219 ( T_11 -> V_708 ) ) ;
else
F_46 ( L_262
L_257 ,
V_15 , sizeof( * T_11 ) ) ;
break;
}
case V_709 : {
struct V_710 * T_11 =
& V_656 -> V_535 . V_711 ;
if ( V_15 == sizeof( * T_11 ) ) {
F_281 ( V_646 | V_647 ,
L_263 ,
T_11 -> V_712 ,
T_11 -> V_713 ) ;
memcpy ( & V_23 -> V_714 , T_11 ,
sizeof( * T_11 ) ) ;
} else {
F_46 ( L_264
L_257 ,
V_15 , sizeof( * T_11 ) ) ;
}
break;
}
case V_715 : {
F_46 ( L_265 ) ;
if ( V_23 -> V_716
&& V_23 -> V_716 -> V_153 != V_717 )
F_46 ( L_266 ) ;
break;
}
case V_718 : {
struct V_719 * T_11 = & V_656 -> V_535 . V_720 ;
if ( V_15 != sizeof( * T_11 ) ) {
F_46
( L_267
L_268 , V_15 , sizeof( * T_11 ) ) ;
break;
}
if ( F_224 ( T_11 -> V_661 ) ==
V_721 )
F_280 ( V_23 ,
F_224 ( T_11 ->
V_722 ) ) ;
break;
}
case V_723 : {
struct V_724 * T_11 = & V_656 -> V_535 . V_725 ;
if ( V_15 == sizeof( * T_11 ) ) {
F_46 ( L_269
L_270 ,
T_11 -> V_726 , T_11 -> V_727 ,
T_11 -> V_728 ) ;
break;
}
F_46
( L_271 ,
V_15 , sizeof( * T_11 ) ) ;
break;
}
case V_729 : {
struct V_730 * T_11 = & V_656 -> V_535 . V_731 ;
if ( V_15 == sizeof( * T_11 ) ) {
memcpy ( & V_23 -> V_326 , T_11 , sizeof( * T_11 ) ) ;
F_74 ( L_272 ) ;
break;
}
F_46
( L_273 ,
V_15 , sizeof( * T_11 ) ) ;
break;
}
case V_732 : {
if ( V_15 == sizeof( T_3 ) ) {
V_23 -> V_579 =
F_270 ( V_23 -> V_579 ,
( T_2 ) ( F_224 ( V_656 -> V_535 . V_733 . V_25 ) & 0xff ) ,
V_734 ) ;
break;
}
F_46
( L_274 ,
V_15 , sizeof( T_3 ) ) ;
break;
}
default:
F_282 ( L_275
L_276 ,
V_656 -> V_657 , V_656 -> V_41 , V_15 ) ;
}
}
static int F_244 ( struct V_17 * V_23 )
{
int V_155 = 0 ;
int V_735 = 64 , V_736 = 8 ;
F_247 ( V_23 ) ;
V_155 = F_252 ( V_23 , & V_23 -> V_226 , V_736 ,
V_737 ,
V_738 ,
V_739 ,
V_740 ) ;
if ( V_155 ) {
F_46 ( L_277 ) ;
goto error;
}
V_155 = F_252 ( V_23 , & V_23 -> V_230 [ 0 ] , V_735 ,
V_741 ,
V_742 ,
V_743 , V_744 ) ;
if ( V_155 ) {
F_46 ( L_278 ) ;
goto error;
}
V_155 = F_252 ( V_23 , & V_23 -> V_230 [ 1 ] , V_735 ,
V_745 ,
V_746 ,
V_747 , V_748 ) ;
if ( V_155 ) {
F_46 ( L_279 ) ;
goto error;
}
V_155 = F_252 ( V_23 , & V_23 -> V_230 [ 2 ] , V_735 ,
V_749 ,
V_750 ,
V_751 , V_752 ) ;
if ( V_155 ) {
F_46 ( L_280 ) ;
goto error;
}
V_155 = F_252 ( V_23 , & V_23 -> V_230 [ 3 ] , V_735 ,
V_753 ,
V_754 ,
V_755 , V_756 ) ;
if ( V_155 ) {
F_46 ( L_281 ) ;
goto error;
}
V_23 -> V_757 = 0 ;
V_23 -> V_758 = 0 ;
return V_155 ;
error:
F_247 ( V_23 ) ;
return V_155 ;
}
static int F_143 ( struct V_17 * V_23 ,
struct V_528 * V_230 , int V_759 )
{
T_3 V_760 ;
int V_761 ;
struct V_520 * V_518 = & V_230 -> V_518 ;
V_760 = F_36 ( V_23 , V_518 -> V_526 ) ;
if ( V_760 >= V_518 -> V_523 ) {
F_46
( L_282 ,
V_760 , V_518 -> V_523 ) ;
goto V_762;
}
for (; V_518 -> V_521 != V_760 ;
V_518 -> V_521 = F_250 ( V_518 -> V_521 , V_518 -> V_523 ) ) {
F_254 ( V_23 , V_230 ) ;
V_23 -> V_589 ++ ;
}
V_762:
if ( ( F_249 ( V_518 ) > V_518 -> V_524 ) &&
( V_759 >= 0 ) )
F_294 ( V_23 -> V_167 ) ;
V_761 = V_518 -> V_522 - V_518 -> V_521 ;
if ( V_761 < 0 )
V_761 += V_518 -> V_523 ;
return V_761 ;
}
static int F_151 ( struct V_17 * V_23 , int V_716 , void * V_1 ,
int V_4 , int V_763 )
{
struct V_528 * V_230 = & V_23 -> V_226 ;
struct V_520 * V_518 = & V_230 -> V_518 ;
struct V_531 * V_764 ;
if ( F_249 ( V_518 ) < ( V_763 ? 1 : 2 ) ) {
F_46 ( L_283 ) ;
return - V_765 ;
}
V_764 = & V_230 -> V_530 [ V_518 -> V_522 ] ;
V_230 -> V_529 [ V_518 -> V_522 ] = NULL ;
memset ( V_764 , 0 , sizeof( * V_764 ) ) ;
V_764 -> V_532 . V_533 = V_534 ;
V_764 -> V_532 . V_766 = V_767 ;
V_23 -> V_768 ++ ;
V_764 -> V_535 . V_153 . V_397 = V_716 ;
V_764 -> V_535 . V_153 . V_412 = V_4 ;
memcpy ( V_764 -> V_535 . V_153 . V_142 , V_1 , V_4 ) ;
V_518 -> V_522 = F_250 ( V_518 -> V_522 , V_518 -> V_523 ) ;
F_35 ( V_23 , V_518 -> V_527 , V_518 -> V_522 ) ;
F_24 ( V_23 , 0x90 ) ;
return 0 ;
}
static void F_295 ( struct V_17 * V_23 )
{
struct V_492 * V_493 = V_23 -> V_493 ;
struct V_434 * V_435 ;
struct V_769 * V_770 ;
unsigned long V_41 ;
int V_503 ;
F_41 ( & V_493 -> V_98 , V_41 ) ;
V_503 = V_493 -> V_503 ;
while ( ( F_248 ( V_493 ) > 0 ) && ( V_493 -> V_504 ) ) {
V_435 = V_493 -> V_494 . V_771 ;
V_770 = F_210 ( V_435 , struct V_769 , V_439 ) ;
F_211 ( V_435 ) ;
F_35 ( V_23 , V_772 + V_493 -> V_503 * V_773 ,
V_770 -> V_499 ) ;
V_493 -> V_774 [ V_493 -> V_503 ] = V_770 ;
V_493 -> V_503 = ( V_493 -> V_503 + 1 ) % V_497 ;
V_493 -> V_504 -- ;
}
F_42 ( & V_493 -> V_98 , V_41 ) ;
if ( V_493 -> V_504 <= V_775 )
F_128 ( & V_23 -> V_776 ) ;
if ( V_503 != V_493 -> V_503 )
F_35 ( V_23 , V_777 , V_493 -> V_503 ) ;
}
static void F_245 ( void * V_3 )
{
struct V_17 * V_23 = V_3 ;
struct V_492 * V_493 = V_23 -> V_493 ;
struct V_434 * V_435 ;
struct V_769 * V_770 ;
unsigned long V_41 ;
F_41 ( & V_493 -> V_98 , V_41 ) ;
while ( ! F_296 ( & V_493 -> V_495 ) ) {
V_435 = V_493 -> V_495 . V_771 ;
V_770 = F_210 ( V_435 , struct V_769 , V_439 ) ;
V_770 -> V_498 = F_297 ( V_500 , V_139 ) ;
if ( ! V_770 -> V_498 ) {
F_4 ( V_778 L_284 ,
V_23 -> V_167 -> V_158 ) ;
break;
}
F_211 ( V_435 ) ;
V_770 -> V_499 =
F_298 ( V_23 -> V_474 , V_770 -> V_498 -> V_3 ,
V_500 , V_501 ) ;
F_212 ( & V_770 -> V_439 , & V_493 -> V_494 ) ;
V_493 -> V_504 ++ ;
}
F_42 ( & V_493 -> V_98 , V_41 ) ;
F_295 ( V_23 ) ;
}
static void F_299 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_776 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_245 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_246 ( struct V_17 * V_23 , struct V_492 * V_493 )
{
int V_7 ;
if ( ! V_493 )
return;
for ( V_7 = 0 ; V_7 < V_497 + V_496 ; V_7 ++ ) {
if ( V_493 -> V_470 [ V_7 ] . V_498 != NULL ) {
F_236 ( V_23 -> V_474 , V_493 -> V_470 [ V_7 ] . V_499 ,
V_500 , V_501 ) ;
F_237 ( V_493 -> V_470 [ V_7 ] . V_498 ) ;
}
}
F_87 ( V_493 ) ;
}
static struct V_492 * F_243 ( struct V_17 * V_23 )
{
struct V_492 * V_493 ;
int V_7 ;
V_493 = F_86 ( sizeof( * V_493 ) , V_148 ) ;
if ( F_29 ( ! V_493 ) ) {
F_46 ( L_285 ) ;
return NULL ;
}
F_300 ( & V_493 -> V_98 ) ;
F_235 ( & V_493 -> V_494 ) ;
F_235 ( & V_493 -> V_495 ) ;
for ( V_7 = 0 ; V_7 < V_496 + V_497 ; V_7 ++ )
F_212 ( & V_493 -> V_470 [ V_7 ] . V_439 , & V_493 -> V_495 ) ;
V_493 -> V_502 = V_493 -> V_503 = 0 ;
V_493 -> V_504 = 0 ;
return V_493 ;
}
static int F_301 ( struct V_17 * V_23 , int V_344 , T_2 V_606 )
{
V_606 &= ~ V_779 ;
if ( V_344 == V_119 ) {
switch ( V_606 ) {
case V_780 :
return V_23 -> V_591 & V_596 ?
1 : 0 ;
case V_781 :
return V_23 -> V_591 & V_597 ?
1 : 0 ;
case V_782 :
return V_23 ->
V_591 & V_599 ? 1 : 0 ;
case V_783 :
return V_23 ->
V_591 & V_600 ? 1 : 0 ;
case V_784 :
return V_23 ->
V_591 & V_601 ? 1 : 0 ;
case V_785 :
return V_23 ->
V_591 & V_602 ? 1 : 0 ;
case V_786 :
return V_23 ->
V_591 & V_603 ? 1 : 0 ;
case V_787 :
return V_23 ->
V_591 & V_604 ? 1 : 0 ;
default:
return 0 ;
}
}
switch ( V_606 ) {
case V_788 :
return V_23 -> V_591 & V_593 ? 1 : 0 ;
case V_789 :
return V_23 -> V_591 & V_594 ? 1 : 0 ;
case V_790 :
return V_23 -> V_591 & V_595 ? 1 : 0 ;
case V_791 :
return V_23 -> V_591 & V_598 ? 1 : 0 ;
}
if ( V_344 == V_605 )
return 0 ;
switch ( V_606 ) {
case V_780 :
return V_23 -> V_591 & V_596 ? 1 : 0 ;
case V_781 :
return V_23 -> V_591 & V_597 ? 1 : 0 ;
case V_782 :
return V_23 -> V_591 & V_599 ? 1 : 0 ;
case V_783 :
return V_23 -> V_591 & V_600 ? 1 : 0 ;
case V_784 :
return V_23 -> V_591 & V_601 ? 1 : 0 ;
case V_785 :
return V_23 -> V_591 & V_602 ? 1 : 0 ;
case V_786 :
return V_23 -> V_591 & V_603 ? 1 : 0 ;
case V_787 :
return V_23 -> V_591 & V_604 ? 1 : 0 ;
}
return 0 ;
}
static int F_302 ( struct V_17 * V_23 ,
const struct V_437 * V_438 ,
struct V_332 * V_333 )
{
int V_792 , V_7 ;
memset ( V_333 , 0 , sizeof( * V_333 ) ) ;
V_792 = F_3 ( V_438 -> V_793 , ( T_2 ) V_794 ) ;
V_333 -> V_792 = 0 ;
for ( V_7 = 0 ; V_7 < V_792 ; V_7 ++ ) {
if ( ! F_301 ( V_23 , V_438 -> V_118 ,
V_438 -> V_333 [ V_7 ] ) ) {
if ( V_438 -> V_333 [ V_7 ] & V_779 ) {
F_165 ( L_286
L_287 ,
V_438 -> V_333 [ V_7 ] ) ;
V_333 -> V_795 [ V_333 -> V_792 ++ ] =
V_438 -> V_333 [ V_7 ] ;
continue;
}
F_165 ( L_288 ,
V_438 -> V_333 [ V_7 ] , V_23 -> V_591 ) ;
continue;
}
V_333 -> V_795 [ V_333 -> V_792 ++ ] = V_438 -> V_333 [ V_7 ] ;
}
V_792 = F_3 ( V_438 -> V_796 ,
( T_2 ) ( V_794 - V_792 ) ) ;
for ( V_7 = 0 ; V_7 < V_792 ; V_7 ++ ) {
if ( ! F_301 ( V_23 , V_438 -> V_118 ,
V_438 -> V_797 [ V_7 ] ) ) {
if ( V_438 -> V_797 [ V_7 ] & V_779 ) {
F_165 ( L_286
L_287 ,
V_438 -> V_797 [ V_7 ] ) ;
V_333 -> V_795 [ V_333 -> V_792 ++ ] =
V_438 -> V_333 [ V_7 ] ;
continue;
}
F_165 ( L_288 ,
V_438 -> V_797 [ V_7 ] , V_23 -> V_591 ) ;
continue;
}
V_333 -> V_795 [ V_333 -> V_792 ++ ] =
V_438 -> V_797 [ V_7 ] ;
}
return 1 ;
}
static void F_303 ( struct V_332 * V_798 ,
const struct V_332 * V_799 )
{
T_2 V_7 ;
for ( V_7 = 0 ; V_7 < V_799 -> V_792 ; V_7 ++ )
V_798 -> V_795 [ V_7 ] = V_799 -> V_795 [ V_7 ] ;
V_798 -> V_792 = V_799 -> V_792 ;
}
static void F_304 ( struct V_332 * V_333 ,
T_2 V_800 , T_3 V_801 )
{
T_2 V_802 = ( V_803 == V_800 ) ?
V_779 : 0 ;
if ( V_801 & V_593 )
V_333 -> V_795 [ V_333 -> V_792 ++ ] =
V_779 | V_788 ;
if ( V_801 & V_594 )
V_333 -> V_795 [ V_333 -> V_792 ++ ] =
V_779 | V_789 ;
if ( V_801 & V_595 )
V_333 -> V_795 [ V_333 -> V_792 ++ ] = V_802 |
V_790 ;
if ( V_801 & V_598 )
V_333 -> V_795 [ V_333 -> V_792 ++ ] = V_802 |
V_791 ;
}
static void F_305 ( struct V_332 * V_333 ,
T_2 V_800 , T_3 V_801 )
{
T_2 V_802 = ( V_803 == V_800 ) ?
V_779 : 0 ;
if ( V_801 & V_596 )
V_333 -> V_795 [ V_333 -> V_792 ++ ] = V_802 |
V_780 ;
if ( V_801 & V_597 )
V_333 -> V_795 [ V_333 -> V_792 ++ ] =
V_781 ;
if ( V_801 & V_599 )
V_333 -> V_795 [ V_333 -> V_792 ++ ] = V_802 |
V_782 ;
if ( V_801 & V_600 )
V_333 -> V_795 [ V_333 -> V_792 ++ ] =
V_783 ;
if ( V_801 & V_601 )
V_333 -> V_795 [ V_333 -> V_792 ++ ] = V_802 |
V_784 ;
if ( V_801 & V_602 )
V_333 -> V_795 [ V_333 -> V_792 ++ ] =
V_785 ;
if ( V_801 & V_603 )
V_333 -> V_795 [ V_333 -> V_792 ++ ] =
V_786 ;
if ( V_801 & V_604 )
V_333 -> V_795 [ V_333 -> V_792 ++ ] =
V_787 ;
}
static int F_306 ( struct V_17 * V_23 ,
struct V_804 * V_805 ,
struct V_437 * V_438 ,
int V_651 )
{
struct V_332 V_333 ;
F_288 ( V_308 ) ;
if ( ( V_23 -> V_163 -> V_510 == V_511 &&
! ( V_438 -> V_314 & V_315 ) ) ) {
F_307 ( L_289
L_290 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ) ;
return 0 ;
}
if ( F_29 ( V_651 ) ) {
if ( ( V_438 -> V_806 != V_805 -> V_438 -> V_806 ) ||
memcmp ( V_438 -> V_308 , V_805 -> V_438 -> V_308 ,
V_438 -> V_806 ) ) {
F_307 ( L_291
L_292 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ) ;
return 0 ;
}
} else {
if ( ( V_23 -> V_59 & V_807 ) &&
( ( V_438 -> V_806 != V_23 -> V_664 ) ||
memcmp ( V_438 -> V_308 , V_23 -> V_663 ,
F_3 ( V_438 -> V_806 , V_23 -> V_664 ) ) ) ) {
char V_808 [ V_310 * 2 + 1 ] ;
strncpy ( V_808 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
sizeof( V_808 ) ) ;
F_307 ( L_291
L_293 ,
V_808 , V_438 -> V_216 ,
F_289 ( V_308 , V_23 -> V_663 ,
V_23 -> V_664 ) ) ;
return 0 ;
}
}
if ( V_438 -> V_464 [ 0 ] < V_805 -> V_438 -> V_464 [ 0 ] ) {
F_307 ( L_294
L_295 ,
F_289 ( V_308 , V_805 -> V_438 -> V_308 ,
V_805 -> V_438 -> V_806 ) ) ;
return 0 ;
} else if ( V_438 -> V_464 [ 1 ] < V_805 -> V_438 -> V_464 [ 1 ] ) {
F_307 ( L_294
L_295 ,
F_289 ( V_308 , V_805 -> V_438 -> V_308 ,
V_805 -> V_438 -> V_806 ) ) ;
return 0 ;
}
if ( V_23 -> V_163 -> V_164 != 0 &&
F_308 ( V_140 , V_438 -> V_809 + V_23 -> V_163 -> V_164 ) ) {
F_307 ( L_291
L_296 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ,
F_166 ( V_140 -
V_438 -> V_809 ) ) ;
return 0 ;
}
if ( ( V_23 -> V_59 & V_546 ) &&
( V_438 -> V_197 != V_23 -> V_197 ) ) {
F_307 ( L_291
L_297 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ,
V_438 -> V_197 , V_23 -> V_197 ) ;
return 0 ;
}
if ( ( ( V_23 -> V_314 & V_810 ) ? 1 : 0 ) !=
( ( V_438 -> V_314 & V_811 ) ? 1 : 0 ) ) {
F_307 ( L_291
L_298 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ,
V_23 ->
V_314 & V_810 ? L_299 : L_300 ,
V_438 ->
V_314 & V_811 ? L_299 :
L_300 ) ;
return 0 ;
}
if ( ! memcmp ( V_438 -> V_216 , V_23 -> V_216 , V_217 ) ) {
F_307 ( L_291
L_301
L_302 , F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ,
V_23 -> V_216 ) ;
return 0 ;
}
if ( ! F_309 ( V_23 -> V_163 , V_438 -> V_118 ) ) {
F_307 ( L_291
L_303
L_304 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ) ;
return 0 ;
}
if ( ! F_302 ( V_23 , V_438 , & V_333 ) ) {
F_307 ( L_291
L_305
L_306 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ) ;
return 0 ;
}
if ( V_333 . V_792 == 0 ) {
F_307 ( L_291
L_307 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ) ;
return 0 ;
}
F_303 ( & V_805 -> V_333 , & V_333 ) ;
V_805 -> V_438 = V_438 ;
F_307 ( L_308 ,
F_289 ( V_308 , V_438 -> V_308 , V_438 -> V_806 ) ,
V_438 -> V_216 ) ;
return 1 ;
}
static void F_310 ( struct V_106 * V_107 )
{
F_288 ( V_308 ) ;
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_812 ) ;
struct V_437 * V_438 = NULL ;
struct V_804 V_805 = {
. V_438 = V_23 -> V_117
} ;
if ( ( V_23 -> V_37 & V_103 ) &&
( V_23 -> V_163 -> V_510 == V_511 ) ) {
unsigned long V_41 ;
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
F_311 (network, &priv->ieee->network_list, list) {
if ( V_438 != V_23 -> V_117 )
F_306 ( V_23 , & V_805 , V_438 ,
1 ) ;
}
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
if ( V_805 . V_438 == V_23 -> V_117 ) {
F_307 ( L_309
L_310 ) ;
return;
}
F_59 ( & V_23 -> V_109 ) ;
if ( ( V_23 -> V_163 -> V_510 == V_511 ) ) {
F_307 ( L_311 ,
F_289 ( V_308 , V_23 -> V_663 ,
V_23 -> V_664 ) ) ;
F_161 ( V_23 ) ;
}
F_263 ( V_23 ) ;
V_23 -> V_117 = V_805 . V_438 ;
F_60 ( & V_23 -> V_109 ) ;
return;
}
}
static int F_312 ( struct V_17 * V_23 ,
struct V_804 * V_805 ,
struct V_437 * V_438 , int V_651 )
{
struct V_332 V_333 ;
F_288 ( V_308 ) ;
if ( ( V_23 -> V_163 -> V_510 == V_513 &&
! ( V_438 -> V_314 & V_813 ) ) ||
( V_23 -> V_163 -> V_510 == V_511 &&
! ( V_438 -> V_314 & V_315 ) ) ) {
F_262 ( L_289
L_290 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ) ;
return 0 ;
}
if ( F_29 ( V_651 ) ) {
if ( ( V_438 -> V_806 != V_805 -> V_438 -> V_806 ) ||
memcmp ( V_438 -> V_308 , V_805 -> V_438 -> V_308 ,
V_438 -> V_806 ) ) {
F_262 ( L_291
L_292 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ) ;
return 0 ;
}
} else {
if ( ( V_23 -> V_59 & V_807 ) &&
( ( V_438 -> V_806 != V_23 -> V_664 ) ||
memcmp ( V_438 -> V_308 , V_23 -> V_663 ,
F_3 ( V_438 -> V_806 , V_23 -> V_664 ) ) ) ) {
char V_808 [ V_310 * 2 + 1 ] ;
strncpy ( V_808 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
sizeof( V_808 ) ) ;
F_262 ( L_291
L_293 ,
V_808 , V_438 -> V_216 ,
F_289 ( V_308 , V_23 -> V_663 ,
V_23 -> V_664 ) ) ;
return 0 ;
}
}
if ( V_805 -> V_438 && V_805 -> V_438 -> V_670 . V_629 > V_438 -> V_670 . V_629 ) {
char V_808 [ V_310 * 2 + 1 ] ;
strncpy ( V_808 ,
F_289 ( V_308 , V_438 -> V_308 , V_438 -> V_806 ) ,
sizeof( V_808 ) ) ;
F_262 ( L_312
L_313 ,
V_808 , V_438 -> V_216 ,
F_289 ( V_308 , V_805 -> V_438 -> V_308 ,
V_805 -> V_438 -> V_806 ) ,
V_805 -> V_438 -> V_216 ) ;
return 0 ;
}
if ( V_438 -> V_814 &&
F_308 ( V_438 -> V_814 + ( V_192 * 3UL ) , V_140 ) ) {
F_262 ( L_291
L_314
L_315 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ,
F_166 ( V_140 -
V_438 -> V_814 ) ) ;
return 0 ;
}
if ( V_23 -> V_163 -> V_164 != 0 &&
F_308 ( V_140 , V_438 -> V_809 + V_23 -> V_163 -> V_164 ) ) {
F_262 ( L_291
L_296 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ,
F_166 ( V_140 -
V_438 -> V_809 ) ) ;
return 0 ;
}
if ( ( V_23 -> V_59 & V_546 ) &&
( V_438 -> V_197 != V_23 -> V_197 ) ) {
F_262 ( L_291
L_297 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ,
V_438 -> V_197 , V_23 -> V_197 ) ;
return 0 ;
}
if ( ( ( V_23 -> V_314 & V_810 ) ? 1 : 0 ) !=
( ( V_438 -> V_314 & V_811 ) ? 1 : 0 ) ) {
F_262 ( L_291
L_298 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ,
V_23 -> V_314 & V_810 ? L_299 :
L_300 ,
V_438 -> V_314 &
V_811 ? L_299 : L_300 ) ;
return 0 ;
}
if ( ( V_23 -> V_59 & V_815 ) &&
memcmp ( V_438 -> V_216 , V_23 -> V_216 , V_217 ) ) {
F_262 ( L_291
L_316 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 , V_23 -> V_216 ) ;
return 0 ;
}
if ( ! F_309 ( V_23 -> V_163 , V_438 -> V_118 ) ) {
F_262 ( L_291
L_303
L_304 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ) ;
return 0 ;
}
if ( ! F_133 ( V_23 -> V_163 , V_438 -> V_197 ) ) {
F_262 ( L_291
L_317 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ) ;
return 0 ;
}
if ( ! F_302 ( V_23 , V_438 , & V_333 ) ) {
F_262 ( L_291
L_305
L_306 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ) ;
return 0 ;
}
if ( V_333 . V_792 == 0 ) {
F_262 ( L_291
L_307 ,
F_289 ( V_308 , V_438 -> V_308 ,
V_438 -> V_806 ) ,
V_438 -> V_216 ) ;
return 0 ;
}
F_303 ( & V_805 -> V_333 , & V_333 ) ;
V_805 -> V_438 = V_438 ;
F_262 ( L_308 ,
F_289 ( V_308 , V_438 -> V_308 , V_438 -> V_806 ) ,
V_438 -> V_216 ) ;
return 1 ;
}
static void F_313 ( struct V_17 * V_23 ,
struct V_437 * V_438 )
{
const struct V_201 * V_202 = F_137 ( V_23 -> V_163 ) ;
int V_7 ;
switch ( F_133 ( V_23 -> V_163 , V_23 -> V_197 ) ) {
case V_816 :
V_438 -> V_118 = V_119 ;
V_7 = F_314 ( V_23 -> V_163 , V_23 -> V_197 ) ;
F_223 ( V_7 == - 1 ) ;
if ( V_202 -> V_18 [ V_7 ] . V_41 & V_207 ) {
F_93 ( L_318 ) ;
V_23 -> V_197 = V_202 -> V_18 [ 0 ] . V_197 ;
}
break;
case V_817 :
if ( V_23 -> V_163 -> V_118 & V_121 )
V_438 -> V_118 = V_121 ;
else
V_438 -> V_118 = V_605 ;
V_7 = F_314 ( V_23 -> V_163 , V_23 -> V_197 ) ;
F_223 ( V_7 == - 1 ) ;
if ( V_202 -> V_204 [ V_7 ] . V_41 & V_207 ) {
F_93 ( L_318 ) ;
V_23 -> V_197 = V_202 -> V_204 [ 0 ] . V_197 ;
}
break;
default:
F_93 ( L_318 ) ;
if ( V_23 -> V_163 -> V_118 & V_119 ) {
V_438 -> V_118 = V_119 ;
V_23 -> V_197 = V_202 -> V_18 [ 0 ] . V_197 ;
} else if ( V_23 -> V_163 -> V_118 & V_121 ) {
V_438 -> V_118 = V_121 ;
V_23 -> V_197 = V_202 -> V_204 [ 0 ] . V_197 ;
} else {
V_438 -> V_118 = V_605 ;
V_23 -> V_197 = V_202 -> V_204 [ 0 ] . V_197 ;
}
break;
}
V_438 -> V_197 = V_23 -> V_197 ;
V_23 -> V_59 |= V_547 ;
F_258 ( V_23 , V_438 -> V_216 ) ;
V_438 -> V_806 = V_23 -> V_664 ;
memcpy ( V_438 -> V_308 , V_23 -> V_663 , V_23 -> V_664 ) ;
memset ( & V_438 -> V_670 , 0 , sizeof( V_438 -> V_670 ) ) ;
V_438 -> V_314 = V_315 ;
if ( ! ( V_23 -> V_59 & V_818 ) )
V_438 -> V_314 |= V_819 ;
if ( V_23 -> V_314 & V_810 )
V_438 -> V_314 |= V_811 ;
V_438 -> V_793 = F_3 ( V_23 -> V_333 . V_792 , V_820 ) ;
memcpy ( V_438 -> V_333 , V_23 -> V_333 . V_795 , V_438 -> V_793 ) ;
V_438 -> V_796 = V_23 -> V_333 . V_792 - V_438 -> V_793 ;
memcpy ( V_438 -> V_797 ,
& V_23 -> V_333 . V_795 [ V_438 -> V_793 ] ,
V_438 -> V_796 ) ;
V_438 -> V_809 = 0 ;
V_438 -> V_41 = 0 ;
V_438 -> V_814 = 0 ;
V_438 -> V_464 [ 0 ] = 0 ;
V_438 -> V_464 [ 1 ] = 0 ;
V_438 -> V_637 = 100 ;
V_438 -> V_821 = 10 ;
V_438 -> V_822 = 0 ;
V_438 -> V_823 = 0 ;
V_438 -> V_824 = 0 ;
}
static void F_315 ( struct V_17 * V_23 , int type , int V_397 )
{
struct V_825 V_826 ;
if ( ! ( V_23 -> V_163 -> V_244 . V_41 & ( 1 << V_397 ) ) )
return;
V_826 . V_827 = V_397 ;
memcpy ( V_826 . V_826 , V_23 -> V_163 -> V_244 . V_828 [ V_397 ] , V_829 ) ;
V_826 . V_727 = type ;
V_826 . V_728 = 0 ;
V_826 . V_41 = 0 ;
V_826 . V_830 [ 0 ] = F_178 ( 0 ) ;
V_826 . V_830 [ 1 ] = F_178 ( 0 ) ;
F_154 ( V_23 , V_831 , sizeof( V_826 ) , & V_826 ) ;
}
static void F_316 ( struct V_17 * V_23 , int type )
{
struct V_832 V_826 ;
int V_7 ;
V_826 . V_833 = V_834 ;
V_826 . V_835 = 0 ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_826 . V_836 = V_7 | type ;
if ( ! ( V_23 -> V_163 -> V_244 . V_41 & ( 1 << V_7 ) ) ) {
V_826 . V_837 = 0 ;
continue;
}
V_826 . V_837 = V_23 -> V_163 -> V_244 . V_838 [ V_7 ] ;
memcpy ( V_826 . V_826 , V_23 -> V_163 -> V_244 . V_828 [ V_7 ] , V_826 . V_837 ) ;
F_154 ( V_23 , V_300 , sizeof( V_826 ) , & V_826 ) ;
}
}
static void F_317 ( struct V_17 * V_23 , int V_11 )
{
if ( V_23 -> V_163 -> V_839 )
return;
switch ( V_11 ) {
case V_840 :
V_23 -> V_307 . V_841 = 0 ;
V_23 -> V_163 -> V_842 = 0 ;
break;
case V_843 :
V_23 -> V_307 . V_841 = 1 ;
V_23 -> V_163 -> V_842 = 1 ;
break;
case V_844 :
V_23 -> V_307 . V_841 = 0 ;
V_23 -> V_163 -> V_842 = 0 ;
break;
case V_845 :
V_23 -> V_307 . V_841 = 1 ;
break;
default:
break;
}
}
static void F_318 ( struct V_17 * V_23 , int V_11 )
{
if ( V_23 -> V_163 -> V_839 )
return;
switch ( V_11 ) {
case V_840 :
V_23 -> V_307 . V_846 = 0 ;
break;
case V_843 :
V_23 -> V_307 . V_846 = 1 ;
break;
case V_844 :
V_23 -> V_307 . V_846 = 0 ;
break;
case V_845 :
V_23 -> V_307 . V_846 = 1 ;
break;
default:
break;
}
}
static void F_319 ( struct V_17 * V_23 )
{
switch ( V_23 -> V_163 -> V_244 . V_11 ) {
case V_840 :
if ( V_23 -> V_163 -> V_244 . V_41 & V_847 )
F_315 ( V_23 ,
V_848 ,
V_23 -> V_163 -> V_244 . V_849 ) ;
if ( ! V_23 -> V_163 -> V_850 )
F_316 ( V_23 , V_851 ) ;
break;
case V_843 :
if ( V_23 -> V_163 -> V_244 . V_41 & V_847 )
F_315 ( V_23 ,
V_852 ,
V_23 -> V_163 -> V_244 . V_849 ) ;
break;
case V_844 :
F_316 ( V_23 , V_853 ) ;
F_317 ( V_23 , V_23 -> V_163 -> V_244 . V_11 ) ;
F_318 ( V_23 , V_23 -> V_163 -> V_244 . V_11 ) ;
break;
case V_845 :
default:
break;
}
}
static void F_320 ( void * V_3 )
{
struct V_17 * V_23 = V_3 ;
if ( V_23 -> V_545 ++ > V_23 -> V_644 &&
! ( V_23 -> V_59 & V_547 ) ) {
F_281 ( V_645 | V_646 |
V_647 | V_648 ,
L_223 ,
V_23 -> V_545 ) ;
F_161 ( V_23 ) ;
F_263 ( V_23 ) ;
return;
}
F_56 ( & V_23 -> V_665 ,
F_219 ( V_23 -> V_556 . V_637 ) ) ;
}
static void F_321 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_665 . V_107 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_320 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_322 ( struct V_17 * V_23 )
{
F_288 ( V_308 ) ;
F_74 ( L_319
L_320 , V_23 -> V_59 ) ;
if ( V_23 -> V_59 & V_546 )
F_74 ( L_321 , V_23 -> V_197 ) ;
else
F_74 ( L_322 ) ;
if ( V_23 -> V_59 & V_807 )
F_74 ( L_323 ,
F_289 ( V_308 , V_23 -> V_663 , V_23 -> V_664 ) ) ;
else
F_74 ( L_324 ) ;
if ( V_23 -> V_59 & V_815 )
F_74 ( L_325 , V_23 -> V_216 ) ;
else
F_74 ( L_326 ) ;
if ( V_23 -> V_314 & V_810 )
F_74 ( L_327 ) ;
else
F_74 ( L_328 ) ;
F_74 ( L_329 , V_23 -> V_591 ) ;
}
static void F_323 ( struct V_17 * V_23 , int V_118 )
{
struct V_854 V_855 ;
T_3 V_24 ;
T_4 V_36 = 0 ;
T_4 V_856 = V_23 -> V_591 ;
switch ( V_23 -> V_163 -> V_857 ) {
case V_816 :
if ( V_23 -> V_591 & ~ V_858 ) {
F_324
( L_330 ) ;
V_856 = 0 ;
break;
}
V_856 >>= V_859 ;
break;
default:
if ( V_118 == V_605 ) {
if ( V_856 & ~ V_592 ) {
F_324
( L_330 ) ;
V_856 = 0 ;
}
break;
}
if ( V_856 & ~ ( V_592 |
V_858 ) ) {
F_324
( L_330 ) ;
V_856 = 0 ;
break;
}
if ( V_596 & V_856 ) {
V_36 |= ( V_596 >> 1 ) ;
V_856 &= ~ V_596 ;
}
if ( V_597 & V_856 ) {
V_36 |= ( V_597 >> 1 ) ;
V_856 &= ~ V_597 ;
}
if ( V_599 & V_856 ) {
V_36 |= ( V_599 >> 1 ) ;
V_856 &= ~ V_599 ;
}
V_856 |= V_36 ;
break;
}
V_855 . V_860 = F_172 ( V_856 ) ;
V_24 = F_36 ( V_23 , V_861 ) ;
F_12 ( V_23 , V_24 , * ( T_3 * ) & V_855 ) ;
}
static void F_167 ( struct V_17 * V_23 )
{
int V_554 ;
if ( V_23 -> V_37 & V_316 ) {
F_142 ( L_331 ) ;
return;
}
V_23 -> V_37 |= V_316 ;
V_554 = F_170 ( V_23 ) ;
if ( V_554 )
F_142 ( L_332 ) ;
}
static void F_325 ( struct V_17 * V_23 ,
struct V_320 * V_862 ,
int V_696 )
{
int V_863 = 0 ;
const struct V_201 * V_202 ;
int V_7 ;
V_202 = F_137 ( V_23 -> V_163 ) ;
if ( V_23 -> V_163 -> V_857 & V_816 ) {
int V_386 = V_863 ;
for ( V_7 = 0 ; V_7 < V_202 -> V_209 ; V_7 ++ ) {
if ( ( V_23 -> V_37 & V_103 ) &&
V_202 -> V_18 [ V_7 ] . V_197 == V_23 -> V_197 )
continue;
V_863 ++ ;
V_862 -> V_864 [ V_863 ] = V_202 -> V_18 [ V_7 ] . V_197 ;
F_326 ( V_862 , V_863 ,
V_202 -> V_18 [ V_7 ] .
V_41 & V_207 ?
V_865 :
V_696 ) ;
}
if ( V_386 != V_863 ) {
V_862 -> V_864 [ V_386 ] = ( T_2 ) ( V_351 << 6 ) |
( V_863 - V_386 ) ;
V_863 ++ ;
}
}
if ( V_23 -> V_163 -> V_857 & V_817 ) {
int V_386 = V_863 ;
if ( V_23 -> V_59 & V_195 ) {
int V_397 ;
T_2 V_866 [ V_867 ] = {
[ 0 ] = 0
} ;
T_2 V_197 ;
while ( V_863 < V_868 - 1 ) {
V_197 =
V_23 -> V_196 [ V_23 -> V_199 ] ;
if ( V_197 == 0 ) {
V_23 -> V_199 = 0 ;
V_197 = V_23 -> V_196 [ 0 ] ;
}
if ( ( V_23 -> V_37 & V_103 ) &&
V_197 == V_23 -> V_197 ) {
V_23 -> V_199 ++ ;
continue;
}
if ( V_866 [ V_197 - 1 ] != 0 )
break;
V_866 [ V_197 - 1 ] = 1 ;
V_23 -> V_199 ++ ;
V_863 ++ ;
V_862 -> V_864 [ V_863 ] = V_197 ;
V_397 =
F_314 ( V_23 -> V_163 , V_197 ) ;
F_326 ( V_862 , V_863 ,
V_202 -> V_204 [ V_397 ] .
V_41 &
V_207 ?
V_865
: V_696 ) ;
}
} else {
for ( V_7 = 0 ; V_7 < V_202 -> V_203 ; V_7 ++ ) {
if ( ( V_23 -> V_37 & V_103 ) &&
V_202 -> V_204 [ V_7 ] . V_197 == V_23 -> V_197 )
continue;
V_863 ++ ;
V_862 -> V_864 [ V_863 ] =
V_202 -> V_204 [ V_7 ] . V_197 ;
F_326 ( V_862 , V_863 ,
V_202 -> V_204 [ V_7 ] .
V_41 &
V_207 ?
V_865
: V_696 ) ;
}
}
if ( V_386 != V_863 ) {
V_862 -> V_864 [ V_386 ] = ( T_2 ) ( V_349 << 6 ) |
( V_863 - V_386 ) ;
}
}
}
static int F_327 ( struct V_17 * V_23 )
{
if ( V_23 -> V_37 & V_103
&& V_23 -> V_117 -> V_637 > 10 )
return V_23 -> V_117 -> V_637 - 10 ;
else
return 120 ;
}
static int F_328 ( struct V_17 * V_23 , int type , int V_869 )
{
struct V_320 V_862 ;
int V_554 = 0 , V_696 ;
if ( ! ( V_23 -> V_37 & V_69 ) ||
( V_23 -> V_37 & V_697 ) )
return 0 ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_869 && ( V_23 -> V_870 == 0 ) ) {
F_142 ( L_333 ) ;
V_23 -> V_37 &= ~ V_700 ;
goto V_762;
}
if ( V_23 -> V_37 & V_318 ) {
F_142 ( L_334 ) ;
V_23 -> V_37 |= V_869 ? V_700 :
V_703 ;
goto V_762;
}
if ( ! ( V_23 -> V_37 & V_699 ) &&
V_23 -> V_37 & V_316 ) {
F_142 ( L_335 ) ;
V_23 -> V_37 |= V_869 ? V_700 :
V_703 ;
goto V_762;
}
if ( V_23 -> V_37 & V_99 ) {
F_142 ( L_336 ) ;
V_23 -> V_37 |= V_869 ? V_700 :
V_703 ;
goto V_762;
}
memset ( & V_862 , 0 , sizeof( V_862 ) ) ;
V_862 . V_871 = F_178 ( F_329 ( V_23 -> V_163 ) ) ;
if ( type == V_872 ) {
F_324 ( L_337 ) ;
V_696 = V_865 ;
V_862 . V_873 [ V_865 ] =
F_172 ( F_327 ( V_23 ) ) ;
F_325 ( V_23 , & V_862 , V_696 ) ;
goto V_874;
}
if ( V_23 -> V_59 & V_195 )
V_862 . V_873 [ V_875 ] =
F_172 ( 30 ) ;
else
V_862 . V_873 [ V_875 ] =
F_172 ( 20 ) ;
V_862 . V_873 [ V_876 ] =
F_172 ( 20 ) ;
V_862 . V_873 [ V_865 ] =
F_172 ( F_327 ( V_23 ) ) ;
V_862 . V_873 [ V_877 ] = F_172 ( 20 ) ;
#ifdef F_242
if ( V_23 -> V_163 -> V_510 == V_512 ) {
T_2 V_197 ;
T_2 V_878 = 0 ;
switch ( F_133 ( V_23 -> V_163 , V_23 -> V_197 ) ) {
case V_816 :
V_878 = ( T_2 ) ( V_351 << 6 ) | 1 ;
V_197 = V_23 -> V_197 ;
break;
case V_817 :
V_878 = ( T_2 ) ( V_349 << 6 ) | 1 ;
V_197 = V_23 -> V_197 ;
break;
default:
V_878 = ( T_2 ) ( V_349 << 6 ) | 1 ;
V_197 = 9 ;
break;
}
V_862 . V_864 [ 0 ] = V_878 ;
V_862 . V_864 [ 1 ] = V_197 ;
F_326 ( & V_862 , 1 , V_865 ) ;
V_862 . V_873 [ V_865 ] =
F_172 ( 2000 ) ;
} else {
#endif
if ( V_869 ) {
V_554 = F_157 ( V_23 , V_23 -> V_879 ,
V_23 -> V_870 ) ;
if ( V_554 ) {
F_142 ( L_338
L_339 ) ;
goto V_762;
}
V_696 = V_876 ;
} else if ( ( V_23 -> V_37 & V_649 )
|| ( ! ( V_23 -> V_37 & V_103 )
&& ( V_23 -> V_59 & V_807 )
&& ( F_224 ( V_862 . V_871 ) % 2 ) ) ) {
V_554 = F_157 ( V_23 , V_23 -> V_663 , V_23 -> V_664 ) ;
if ( V_554 ) {
F_142 ( L_340
L_65 ) ;
goto V_762;
}
V_696 = V_876 ;
} else
V_696 = V_875 ;
F_325 ( V_23 , & V_862 , V_696 ) ;
#ifdef F_242
}
#endif
V_874:
V_554 = F_169 ( V_23 , & V_862 ) ;
if ( V_554 ) {
F_142 ( L_341 , V_554 ) ;
goto V_762;
}
V_23 -> V_37 |= V_318 ;
if ( V_869 ) {
V_23 -> V_37 &= ~ V_700 ;
V_23 -> V_870 = 0 ;
} else
V_23 -> V_37 &= ~ V_703 ;
F_56 ( & V_23 -> V_319 , V_317 ) ;
V_762:
F_60 ( & V_23 -> V_109 ) ;
return V_554 ;
}
static void F_330 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_188 . V_107 ) ;
F_328 ( V_23 , V_872 , 0 ) ;
}
static void F_331 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_186 . V_107 ) ;
F_328 ( V_23 , V_880 , 0 ) ;
}
static void F_332 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_187 . V_107 ) ;
F_328 ( V_23 , V_880 , 1 ) ;
}
static void F_333 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_650 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_167 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int F_334 ( struct V_17 * V_23 , int V_25 )
{
V_23 -> V_163 -> V_881 = V_25 ;
return 0 ;
}
static int F_335 ( struct V_17 * V_23 , int V_25 )
{
struct V_882 * V_163 = V_23 -> V_163 ;
struct V_883 V_244 = {
. V_41 = V_884 ,
} ;
int V_429 = 0 ;
if ( V_25 & V_885 ) {
V_244 . V_886 = V_887 ;
V_163 -> V_888 = 0 ;
} else if ( V_25 & V_889 ) {
V_244 . V_886 = V_890 ;
V_163 -> V_888 = 1 ;
} else if ( V_25 & V_891 ) {
V_244 . V_886 = V_892 ;
V_163 -> V_888 = 1 ;
} else
return - V_75 ;
if ( V_163 -> V_893 )
V_163 -> V_893 ( V_163 -> V_166 , & V_244 ) ;
else
V_429 = - V_894 ;
return V_429 ;
}
static void F_336 ( struct V_17 * V_23 , char * V_895 ,
int V_823 )
{
F_334 ( V_23 , 1 ) ;
}
static int F_337 ( struct V_17 * V_23 ,
char * V_896 , int V_412 )
{
F_142 ( L_342 ) ;
return F_154 ( V_23 , V_897 , V_412 ,
V_896 ) ;
}
static int F_338 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
struct V_882 * V_163 = V_23 -> V_163 ;
T_2 * V_1 ;
int V_554 = 0 ;
if ( V_211 -> V_3 . V_412 > V_901 ||
( V_211 -> V_3 . V_412 && V_900 == NULL ) )
return - V_75 ;
if ( V_211 -> V_3 . V_412 ) {
V_1 = F_340 ( V_900 , V_211 -> V_3 . V_412 , V_148 ) ;
if ( V_1 == NULL ) {
V_554 = - V_473 ;
goto V_6;
}
F_87 ( V_163 -> V_895 ) ;
V_163 -> V_895 = V_1 ;
V_163 -> V_823 = V_211 -> V_3 . V_412 ;
} else {
F_87 ( V_163 -> V_895 ) ;
V_163 -> V_895 = NULL ;
V_163 -> V_823 = 0 ;
}
F_336 ( V_23 , V_163 -> V_895 , V_163 -> V_823 ) ;
V_6:
return V_554 ;
}
static int F_341 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
struct V_882 * V_163 = V_23 -> V_163 ;
int V_554 = 0 ;
if ( V_163 -> V_823 == 0 || V_163 -> V_895 == NULL ) {
V_211 -> V_3 . V_412 = 0 ;
goto V_6;
}
if ( V_211 -> V_3 . V_412 < V_163 -> V_823 ) {
V_554 = - V_902 ;
goto V_6;
}
V_211 -> V_3 . V_412 = V_163 -> V_823 ;
memcpy ( V_900 , V_163 -> V_895 , V_163 -> V_823 ) ;
V_6:
return V_554 ;
}
static int F_342 ( int V_903 )
{
switch ( V_903 ) {
case V_904 :
return V_845 ;
case V_905 :
case V_906 :
return V_844 ;
case V_907 :
return V_843 ;
case V_908 :
return V_840 ;
default:
return - 1 ;
}
}
static int F_343 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
struct V_882 * V_163 = V_23 -> V_163 ;
struct V_909 * V_154 = & V_211 -> V_154 ;
struct V_910 * V_911 ;
unsigned long V_41 ;
int V_429 = 0 ;
switch ( V_154 -> V_41 & V_912 ) {
case V_913 :
break;
case V_914 :
F_317 ( V_23 ,
F_342 ( V_154 -> V_25 ) ) ;
break;
case V_915 :
F_318 ( V_23 ,
F_342 ( V_154 -> V_25 ) ) ;
break;
case V_916 :
break;
case V_917 :
V_911 = V_23 -> V_163 -> V_918 . V_911 [ V_23 -> V_163 -> V_918 . V_919 ] ;
if ( ! V_911 || ! V_911 -> V_920 -> V_921 || ! V_911 -> V_920 -> V_922 )
break;
V_41 = V_911 -> V_920 -> V_922 ( V_911 -> V_23 ) ;
if ( V_154 -> V_25 )
V_41 |= V_923 ;
else
V_41 &= ~ V_923 ;
V_911 -> V_920 -> V_921 ( V_41 , V_911 -> V_23 ) ;
break;
case V_924 : {
struct V_883 V_244 = {
. V_41 = V_925 ,
. V_926 = V_154 -> V_25 ,
} ;
V_23 -> V_163 -> V_927 = V_154 -> V_25 ;
if ( ! V_154 -> V_25 ) {
V_244 . V_41 |= V_928 ;
V_244 . V_11 = V_845 ;
} else {
V_244 . V_41 |= V_928 ;
V_244 . V_11 = V_844 ;
}
if ( V_23 -> V_163 -> V_893 )
V_23 -> V_163 -> V_893 ( V_23 -> V_163 -> V_166 , & V_244 ) ;
break;
}
case V_929 :
V_429 = F_335 ( V_23 , V_154 -> V_25 ) ;
break;
case V_930 :
V_429 = F_334 ( V_23 , V_154 -> V_25 ) ;
F_263 ( V_23 ) ;
break;
case V_931 :
V_163 -> V_932 = V_154 -> V_25 ;
break;
case V_933 :
V_163 -> V_934 = V_154 -> V_25 ;
break;
default:
return - V_894 ;
}
return V_429 ;
}
static int F_344 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
struct V_882 * V_163 = V_23 -> V_163 ;
struct V_910 * V_911 ;
struct V_909 * V_154 = & V_211 -> V_154 ;
int V_429 = 0 ;
switch ( V_154 -> V_41 & V_912 ) {
case V_913 :
case V_914 :
case V_915 :
case V_916 :
V_429 = - V_894 ;
break;
case V_917 :
V_911 = V_23 -> V_163 -> V_918 . V_911 [ V_23 -> V_163 -> V_918 . V_919 ] ;
if ( ! V_911 || ! V_911 -> V_920 -> V_922 )
break;
V_154 -> V_25 = ( V_911 -> V_920 -> V_922 ( V_911 -> V_23 ) &
V_923 ) ? 1 : 0 ;
break;
case V_924 :
V_154 -> V_25 = V_163 -> V_927 ;
break;
case V_929 :
V_154 -> V_25 = V_163 -> V_244 . V_886 ;
break;
case V_930 :
V_154 -> V_25 = V_163 -> V_881 ;
break;
case V_931 :
V_154 -> V_25 = V_163 -> V_932 ;
break;
case V_935 :
case V_933 :
V_154 -> V_25 = V_163 -> V_934 ;
break;
default:
return - V_894 ;
}
return 0 ;
}
static int F_345 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
struct V_936 * V_937 = (struct V_936 * ) V_900 ;
if ( V_938 ) {
if ( V_937 -> V_939 == V_940 ) {
if ( V_937 -> V_941 & V_942 )
V_23 -> V_163 -> V_850 = 1 ;
else {
V_23 -> V_163 -> V_839 = 0 ;
V_23 -> V_163 -> V_943 = 1 ;
V_23 -> V_163 -> V_842 = 1 ;
}
} else {
V_23 -> V_163 -> V_839 = 0 ;
V_23 -> V_163 -> V_943 = 0 ;
V_23 -> V_163 -> V_842 = 0 ;
V_23 -> V_163 -> V_850 = 0 ;
}
}
return F_346 ( V_23 -> V_163 , V_899 , V_211 , V_900 ) ;
}
static int F_347 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
return F_348 ( V_23 -> V_163 , V_899 , V_211 , V_900 ) ;
}
static int F_349 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
struct V_944 * V_945 = (struct V_944 * ) V_900 ;
T_8 V_567 ;
V_567 = F_172 ( V_945 -> V_946 ) ;
switch ( V_945 -> V_153 ) {
case V_947 :
break;
case V_948 :
F_263 ( V_23 ) ;
break;
default:
return - V_894 ;
}
return 0 ;
}
static T_2 F_350 ( struct V_17 * V_23 )
{
T_2 V_118 = 0 ;
if ( V_23 -> V_37 & V_103 ) {
unsigned long V_41 ;
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
V_118 = V_23 -> V_117 -> V_118 ;
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
} else {
V_118 = V_23 -> V_163 -> V_118 ;
}
F_292 ( L_343 , V_118 ) ;
return V_118 ;
}
static int F_351 ( struct V_17 * V_23 ,
int V_949 ,
struct V_437 * V_438 )
{
T_3 V_15 = sizeof( struct V_950 ) ;
if ( V_438 -> V_314 & V_315 )
V_438 -> V_951 . V_952 = V_438 -> V_951 . V_953 ;
if ( V_438 -> V_41 & V_954 ) {
if ( V_949 &&
( V_438 -> V_41 & V_955 ) )
V_438 -> V_951 . V_952 = V_438 -> V_951 . V_953 ;
if ( ( V_438 -> V_951 . V_952 == 1 ) && ( V_949 == 1 ) &&
( V_438 -> V_41 & V_955 ) &&
( V_438 -> V_951 . V_956 !=
V_438 -> V_951 . V_957 ) ) {
V_438 -> V_951 . V_956 =
V_438 -> V_951 . V_957 ;
F_128 ( & V_23 -> V_958 ) ;
F_292 ( L_344
L_345 ) ;
}
} else {
if ( ( V_23 -> V_163 -> V_118 == V_605 ) || ( V_438 -> V_118 == V_605 ) )
memcpy ( & V_438 -> V_951 . V_959 ,
& V_960 , V_15 ) ;
else
memcpy ( & V_438 -> V_951 . V_959 ,
& V_961 , V_15 ) ;
if ( ( V_438 -> V_951 . V_952 == 1 ) && ( V_949 == 1 ) ) {
F_292 ( L_346 ) ;
F_128 ( & V_23 -> V_958 ) ;
}
V_438 -> V_951 . V_952 = 0 ;
V_438 -> V_951 . V_953 = 0 ;
}
if ( ( V_23 -> V_37 & V_103 ) &&
( V_23 -> V_163 -> V_510 == V_511 ) && ( V_949 == 0 ) ) {
if ( memcmp ( V_438 -> V_216 , V_23 -> V_216 , V_217 ) )
if ( V_438 -> V_314 & V_315 )
if ( ( V_438 -> V_806 ==
V_23 -> V_117 -> V_806 ) &&
! memcmp ( V_438 -> V_308 ,
V_23 -> V_117 -> V_308 ,
V_438 -> V_806 ) ) {
F_128 ( & V_23 -> V_812 ) ;
}
}
return 0 ;
}
static int F_352 ( struct V_17 * V_23 ,
struct V_962 * V_963 )
{
int V_554 ;
struct V_950 V_964 [ V_965 ] ;
struct V_950 * V_966 = NULL ;
T_3 V_15 = sizeof( struct V_950 ) ;
T_3 V_967 ;
int V_7 ;
T_2 type ;
type = F_350 ( V_23 ) ;
V_966 = & ( V_964 [ V_968 ] ) ;
memcpy ( V_966 , V_23 -> V_951 . V_969 , V_15 ) ;
V_966 = & ( V_964 [ V_970 ] ) ;
memcpy ( V_966 , V_23 -> V_951 . V_971 , V_15 ) ;
if ( V_963 == NULL ) {
if ( type == V_605 ) {
F_292 ( L_347 , type ) ;
V_966 = & V_960 ;
} else
V_966 = & V_961 ;
memcpy ( & V_964 [ V_972 ] , V_966 , V_15 ) ;
V_967 = F_353 ( V_23 ) ;
for ( V_7 = 0 ; V_7 < V_973 ; V_7 ++ )
V_964 [ V_972 ] . V_974 [ V_7 ] =
F_172 ( V_967 ) ;
} else if ( V_23 -> V_163 -> V_510 == V_511 ) {
if ( type == V_605 ) {
F_292 ( L_348 ,
type ) ;
if ( V_23 -> V_951 . V_975 == 0 )
V_966 = & V_960 ;
else
V_966 = V_23 -> V_951 . V_969 ;
} else {
if ( V_23 -> V_951 . V_975 == 0 )
V_966 = & V_961 ;
else
V_966 = V_23 -> V_951 . V_971 ;
}
memcpy ( & V_964 [ V_972 ] , V_966 , V_15 ) ;
} else {
unsigned long V_41 ;
int V_952 ;
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
V_966 = & ( V_963 -> V_959 ) ;
V_963 -> V_956 =
V_963 -> V_957 ;
memcpy ( & V_964 [ V_972 ] , V_966 , V_15 ) ;
V_952 = V_963 -> V_953 ;
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
if ( V_952 == 0 ) {
V_967 = F_353 ( V_23 ) ;
for ( V_7 = 0 ; V_7 < V_973 ; V_7 ++ )
V_964 [ V_972 ] .
V_974 [ V_7 ] = F_172 ( V_967 ) ;
}
}
F_292 ( L_349 ) ;
V_554 = F_354 ( V_23 ,
(struct V_950 * )
& ( V_964 [ 0 ] ) ) ;
if ( V_554 )
F_292 ( L_350 ) ;
return V_554 ;
}
static int F_355 ( struct V_17 * V_23 )
{
int V_429 = 0 ;
struct V_976 V_977 ;
if ( V_23 == NULL )
return - 1 ;
V_977 . V_978 = V_979 ;
V_977 . V_412 = sizeof( struct V_976 ) - 2 ;
V_977 . V_980 = V_981 ;
V_977 . V_982 = 0 ;
memcpy ( V_977 . V_983 , V_984 , V_985 ) ;
V_977 . V_986 = V_987 ;
V_977 . V_988 = V_989 ;
V_429 = F_356 ( V_23 , & V_977 ) ;
if ( V_429 != 0 ) {
F_292 ( L_351 ) ;
}
return V_429 ;
}
static int F_357 ( struct V_17 * V_23 ,
struct V_437 * V_438 )
{
int V_554 = 0 ;
struct V_962 * V_951 = NULL ;
struct V_962 V_990 = {
. V_953 = 1 ,
. V_952 = 1 ,
} ;
switch ( V_23 -> V_163 -> V_510 ) {
case V_511 :
F_223 ( ! ( V_438 -> V_314 & V_315 ) ) ;
V_951 = & V_990 ;
break;
case V_513 :
V_951 = & V_438 -> V_951 ;
break;
default:
F_358 () ;
break;
}
V_554 = F_352 ( V_23 , V_951 ) ;
if ( V_554 ) {
V_23 -> V_556 . V_991 &= ~ V_992 ;
return V_554 ;
}
if ( V_23 -> V_951 . V_975 && V_951 -> V_953 ) {
F_292 ( L_352 ) ;
V_23 -> V_556 . V_991 |= V_992 ;
return F_355 ( V_23 ) ;
}
return 0 ;
}
static int F_359 ( struct V_17 * V_23 ,
struct V_437 * V_438 )
{
int V_429 = 0 ;
unsigned long V_41 ;
T_3 V_15 = sizeof( struct V_950 ) ;
int V_993 = 0 ;
if ( ( V_23 == NULL ) || ( V_438 == NULL ) ||
( V_23 -> V_117 == NULL ) )
return V_429 ;
if ( ! ( V_23 -> V_37 & V_103 ) )
return V_429 ;
if ( ( V_23 -> V_163 -> V_510 != V_513 ) )
return V_429 ;
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
if ( V_438 -> V_41 & V_955 ) {
memcpy ( & V_23 -> V_117 -> V_951 , & V_438 -> V_951 ,
sizeof( struct V_962 ) ) ;
V_23 -> V_117 -> V_951 . V_952 = 1 ;
if ( ( V_438 -> V_951 . V_956 !=
V_438 -> V_951 . V_957 ) ) {
V_993 = 1 ;
V_438 -> V_951 . V_956 =
V_438 -> V_951 . V_957 ;
}
} else {
if ( ( V_438 -> V_118 == V_605 ) || ( V_23 -> V_163 -> V_118 == V_605 ) )
memcpy ( & V_23 -> V_117 -> V_951 . V_959 ,
& V_960 , V_15 ) ;
else
memcpy ( & V_23 -> V_117 -> V_951 . V_959 ,
& V_961 , V_15 ) ;
V_23 -> V_117 -> V_951 . V_952 = 0 ;
V_23 -> V_117 -> V_951 . V_953 = 0 ;
V_993 = 1 ;
}
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
if ( V_993 == 1 )
F_128 ( & V_23 -> V_958 ) ;
return V_429 ;
}
static T_3 F_353 ( struct V_17 * V_23 )
{
T_3 V_429 = 0 ;
if ( ( V_23 == NULL ) )
return 0 ;
if ( ! ( V_23 -> V_163 -> V_800 & V_803 ) )
V_429 = V_23 -> V_951 . V_994 ;
else
V_429 = V_23 -> V_951 . V_995 ;
return V_429 ;
}
static void F_360 ( struct V_17 * V_23 , int V_996 ,
int V_997 , T_3 V_994 ,
T_3 V_995 )
{
V_23 -> V_951 . V_975 = V_996 ;
if ( V_23 -> V_951 . V_975 ) {
V_23 -> V_951 . V_969 = & V_998 ;
V_23 -> V_951 . V_971 = & V_999 ;
F_292 ( L_353 ) ;
} else {
V_23 -> V_951 . V_969 = & V_960 ;
V_23 -> V_951 . V_971 = & V_961 ;
F_292 ( L_354 ) ;
}
V_23 -> V_951 . V_997 = V_997 ;
if ( V_997 ) {
V_23 -> V_951 . V_994 = V_994 ;
V_23 -> V_951 . V_995 = V_995 ;
} else {
V_23 -> V_951 . V_994 = 0 ;
V_23 -> V_951 . V_995 = 0 ;
}
}
static int F_361 ( struct V_17 * V_23 , T_4 V_1000 )
{
if ( V_1000 > 7 || ! V_23 -> V_951 . V_975 )
V_1000 = 0 ;
return V_1001 [ V_1000 ] - 1 ;
}
static int F_362 ( struct V_165 * V_166 ,
struct V_1002 * V_498 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
struct V_962 * V_951 = NULL ;
int V_952 , V_953 ;
T_2 * V_1003 = V_498 -> V_3 + V_217 ;
int V_1004 = ! F_363 ( V_1003 ) ;
if ( ! ( V_23 -> V_37 & V_103 ) )
return 0 ;
V_951 = & V_23 -> V_117 -> V_951 ;
if ( V_23 -> V_163 -> V_510 == V_511 ) {
if ( V_1004 == 0 )
V_951 -> V_952 = 0 ;
else
V_951 -> V_952 = V_951 -> V_953 ;
}
V_952 = V_951 -> V_952 ;
V_953 = V_951 -> V_953 ;
F_292 ( L_355
L_356 ,
V_23 -> V_951 . V_975 , V_952 , V_953 , V_1004 ) ;
if ( V_952 && V_23 -> V_951 . V_975 )
return 1 ;
return 0 ;
}
static int F_364 ( struct V_17 * V_23 ,
T_4 V_1000 ,
struct V_1005 * V_764 )
{
int V_1006 = 0 ;
V_1006 = V_1001 [ V_1000 ] - 1 ;
V_764 -> V_1007 |= V_1008 ;
if ( V_23 -> V_951 . V_1009 & ( 1UL << V_1006 ) ) {
V_764 -> V_1010 &= ~ V_1011 ;
V_764 -> V_764 . V_1012 . V_1013 . V_1014 |= F_172 ( V_1015 ) ;
}
return 0 ;
}
static void F_365 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_958 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_37 & V_103 )
F_352 ( V_23 , & ( V_23 -> V_117 -> V_951 ) ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int F_366 ( struct V_165 * V_166 ,
struct V_1016 * V_677 ,
struct V_437 * V_438 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
int V_949 = ( ( V_23 -> V_37 & V_103 ) &&
( V_438 == V_23 -> V_117 ) ) ;
F_351 ( V_23 , V_949 , V_438 ) ;
return 0 ;
}
static int F_367 ( struct V_165 * V_166 ,
struct V_1017 * V_677 ,
struct V_437 * V_438 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
int V_949 = ( ( V_23 -> V_37 & V_103 ) &&
( V_438 == V_23 -> V_117 ) ) ;
F_351 ( V_23 , V_949 , V_438 ) ;
return 0 ;
}
static int F_368 ( struct V_165 * V_166 ,
struct V_668 * V_677 ,
struct V_437 * V_438 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_359 ( V_23 , V_438 ) ;
return 0 ;
}
static int F_354 ( struct V_17 * V_23 , struct V_950
* V_1018 )
{
return F_154 ( V_23 , V_1019 ,
sizeof( * V_1018 ) * 3 , V_1018 ) ;
}
static int F_356 ( struct V_17 * V_23 , struct V_976
* V_1018 )
{
return F_154 ( V_23 , V_1020 , sizeof( * V_1018 ) ,
V_1018 ) ;
}
static int F_369 ( struct V_17 * V_23 ,
struct V_437 * V_438 ,
struct V_332 * V_333 , int V_651 )
{
int V_554 ;
F_288 ( V_308 ) ;
if ( V_23 -> V_59 & V_1021 )
F_323 ( V_23 , V_438 -> V_118 ) ;
if ( ! ( V_23 -> V_59 & V_807 ) ) {
V_23 -> V_664 = F_3 ( V_438 -> V_806 ,
( T_2 ) V_310 ) ;
memcpy ( V_23 -> V_663 , V_438 -> V_308 , V_23 -> V_664 ) ;
}
V_438 -> V_814 = V_140 ;
memset ( & V_23 -> V_556 , 0 , sizeof( V_23 -> V_556 ) ) ;
V_23 -> V_556 . V_197 = V_438 -> V_197 ;
V_23 -> V_556 . V_1022 = 0 ;
if ( ( V_23 -> V_314 & V_810 ) &&
( V_23 -> V_163 -> V_244 . V_886 == V_887 ) ) {
V_23 -> V_556 . V_1023 = V_1024 ;
V_23 -> V_556 . V_1022 = V_23 -> V_163 -> V_244 . V_849 ;
if ( V_23 -> V_163 -> V_244 . V_11 == V_844 )
F_316 ( V_23 , V_853 ) ;
} else if ( ( V_23 -> V_314 & V_810 ) &&
( V_23 -> V_163 -> V_244 . V_886 == V_892 ) )
V_23 -> V_556 . V_1023 = V_1025 ;
else
V_23 -> V_556 . V_1023 = V_1026 ;
if ( V_23 -> V_163 -> V_823 ) {
V_23 -> V_556 . V_991 = F_172 ( 0x02 ) ;
F_337 ( V_23 , V_23 -> V_163 -> V_895 ,
V_23 -> V_163 -> V_823 ) ;
}
if ( V_438 -> V_118 & V_23 -> V_163 -> V_118 & V_119 )
V_23 -> V_556 . V_344 = V_351 ;
else if ( V_438 -> V_118 & V_23 -> V_163 -> V_118 & V_121 )
V_23 -> V_556 . V_344 = V_345 ;
else if ( V_438 -> V_118 & V_23 -> V_163 -> V_118 & V_605 )
V_23 -> V_556 . V_344 = V_349 ;
V_23 -> V_556 . V_314 = F_172 ( V_438 -> V_314 ) ;
if ( ( V_438 -> V_314 & V_819 )
&& ! ( V_23 -> V_59 & V_818 ) ) {
V_23 -> V_556 . V_1027 = V_1028 ;
} else {
V_23 -> V_556 . V_1027 = V_1029 ;
V_23 -> V_556 . V_314 &=
~ F_172 ( V_819 ) ;
}
if ( V_23 -> V_163 -> V_510 == V_511 )
V_23 -> V_556 . V_314 &=
~ F_172 ( V_1030 ) ;
F_262 ( L_357
L_358 ,
V_651 ? L_359 : L_360 ,
F_289 ( V_308 , V_23 -> V_663 , V_23 -> V_664 ) ,
V_438 -> V_197 ,
V_1031 [ V_23 -> V_556 . V_344 ] ,
V_333 -> V_792 ,
( V_23 -> V_556 . V_1027 ==
V_1029 ) ? L_361 : L_362 ,
V_438 -> V_314 &
V_819 ? L_362 : L_361 ,
V_23 -> V_314 & V_810 ? L_363 : L_300 ,
V_23 -> V_314 & V_810 ?
( V_23 -> V_314 & V_1032 ? L_364 :
L_365 ) : L_108 ,
V_23 -> V_314 & V_810 ? L_366 : L_108 ,
V_23 -> V_314 & V_810 ?
'1' + V_23 -> V_163 -> V_244 . V_849 : '.' ,
V_23 -> V_314 & V_810 ? '.' : ' ' ) ;
V_23 -> V_556 . V_637 = F_172 ( V_438 -> V_637 ) ;
if ( ( V_23 -> V_163 -> V_510 == V_511 ) &&
( V_438 -> V_464 [ 0 ] == 0 ) && ( V_438 -> V_464 [ 1 ] == 0 ) ) {
V_23 -> V_556 . V_558 = V_1033 ;
V_23 -> V_556 . V_1034 = 0 ;
V_23 -> V_556 . V_1035 = 0 ;
} else {
if ( F_29 ( V_651 ) )
V_23 -> V_556 . V_558 = V_1036 ;
else
V_23 -> V_556 . V_558 = V_1037 ;
V_23 -> V_556 . V_1034 = F_178 ( V_438 -> V_464 [ 1 ] ) ;
V_23 -> V_556 . V_1035 = F_178 ( V_438 -> V_464 [ 0 ] ) ;
}
memcpy ( V_23 -> V_556 . V_216 , V_438 -> V_216 , V_217 ) ;
if ( V_23 -> V_163 -> V_510 == V_511 ) {
memset ( & V_23 -> V_556 . V_798 , 0xFF , V_217 ) ;
V_23 -> V_556 . V_822 = F_172 ( V_438 -> V_822 ) ;
} else {
memcpy ( V_23 -> V_556 . V_798 , V_438 -> V_216 , V_217 ) ;
V_23 -> V_556 . V_822 = 0 ;
}
V_23 -> V_556 . V_821 = F_172 ( V_438 -> V_821 ) ;
V_554 = F_157 ( V_23 , V_23 -> V_663 , V_23 -> V_664 ) ;
if ( V_554 ) {
F_142 ( L_367 ) ;
return V_554 ;
}
V_333 -> V_344 = V_23 -> V_556 . V_344 ;
V_333 -> V_1038 = V_1039 ;
F_174 ( V_23 , V_333 ) ;
if ( V_23 -> V_556 . V_344 == V_345 )
V_23 -> V_307 . V_1040 = 1 ;
else
V_23 -> V_307 . V_1040 = 0 ;
if ( V_23 -> V_163 -> V_510 == V_511 )
V_23 -> V_307 . V_1041 = 1 ;
else
V_23 -> V_307 . V_1041 = 0 ;
V_554 = F_156 ( V_23 ) ;
if ( V_554 ) {
F_142 ( L_368 ) ;
return V_554 ;
}
F_262 ( L_369 , V_438 -> V_670 . V_629 ) ;
V_554 = F_171 ( V_23 , V_438 -> V_670 . V_629 + V_1042 ) ;
if ( V_554 ) {
F_142 ( L_370 ) ;
return V_554 ;
}
V_23 -> V_197 = V_438 -> V_197 ;
memcpy ( V_23 -> V_216 , V_438 -> V_216 , V_217 ) ;
V_23 -> V_37 |= V_240 ;
V_23 -> V_37 &= ~ V_1043 ;
V_23 -> V_117 = V_438 ;
#ifdef F_290
F_357 ( V_23 , V_438 ) ;
#endif
V_554 = F_173 ( V_23 , & V_23 -> V_556 ) ;
if ( V_554 ) {
F_142 ( L_370 ) ;
return V_554 ;
}
F_281 ( V_647 , L_371 ,
F_289 ( V_308 , V_23 -> V_663 , V_23 -> V_664 ) ,
V_23 -> V_216 ) ;
return 0 ;
}
static void F_370 ( void * V_3 )
{
struct V_17 * V_23 = V_3 ;
struct V_437 * V_438 = NULL ;
struct V_804 V_805 = {
. V_438 = V_23 -> V_117
} ;
if ( ! ( V_23 -> V_37 & ( V_103 | V_649 ) ) )
return;
if ( V_23 -> V_37 & V_103 ) {
unsigned long V_41 ;
T_2 V_629 = V_23 -> V_117 -> V_670 . V_629 ;
V_23 -> V_117 -> V_670 . V_629 = - 128 ;
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
F_311 (network, &priv->ieee->network_list, list) {
if ( V_438 != V_23 -> V_117 )
F_312 ( V_23 , & V_805 , V_438 , 1 ) ;
}
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
V_23 -> V_117 -> V_670 . V_629 = V_629 ;
if ( V_805 . V_438 == V_23 -> V_117 ) {
F_262 ( L_372
L_373 ) ;
V_23 -> V_37 &= ~ V_649 ;
F_322 ( V_23 ) ;
return;
}
F_261 ( V_23 , 1 ) ;
V_23 -> V_117 = V_805 . V_438 ;
return;
}
F_302 ( V_23 , V_23 -> V_117 , & V_805 . V_333 ) ;
F_369 ( V_23 , V_23 -> V_117 , & V_805 . V_333 , 1 ) ;
V_23 -> V_37 &= ~ V_649 ;
}
static void F_371 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_702 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_370 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int V_329 ( void * V_3 )
{
struct V_17 * V_23 = V_3 ;
struct V_437 * V_438 = NULL ;
struct V_804 V_805 = {
. V_438 = NULL
} ;
struct V_332 * V_333 ;
struct V_434 * V_435 ;
unsigned long V_41 ;
F_288 ( V_308 ) ;
if ( V_23 -> V_163 -> V_510 == V_512 ) {
F_262 ( L_374 ) ;
return 0 ;
}
if ( V_23 -> V_37 & ( V_103 | V_240 ) ) {
F_262 ( L_375
L_376 ) ;
return 0 ;
}
if ( V_23 -> V_37 & V_557 ) {
F_262 ( L_377
L_378 ) ;
F_128 ( & V_23 -> V_330 ) ;
return 0 ;
}
if ( ! F_47 ( V_23 ) || ( V_23 -> V_37 & V_318 ) ) {
F_262 ( L_379
L_380 ) ;
return 0 ;
}
if ( ! ( V_23 -> V_59 & V_1044 ) &&
! ( V_23 -> V_59 & ( V_807 | V_815 ) ) ) {
F_262 ( L_381 ) ;
return 0 ;
}
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
F_311 (network, &priv->ieee->network_list, list)
F_312 ( V_23 , & V_805 , V_438 , 0 ) ;
V_438 = V_805 . V_438 ;
V_333 = & V_805 . V_333 ;
if ( V_438 == NULL &&
V_23 -> V_163 -> V_510 == V_511 &&
V_23 -> V_59 & V_1045 &&
V_23 -> V_59 & V_807 &&
V_23 -> V_59 & V_546 ) {
if ( F_296 ( & V_23 -> V_163 -> V_440 ) ) {
struct V_437 * V_1046 = NULL ;
struct V_437 * V_1047 ;
F_311 (target, &priv->ieee->network_list, list) {
if ( ( V_1046 == NULL ) ||
( V_1047 -> V_809 < V_1046 -> V_809 ) )
V_1046 = V_1047 ;
}
F_211 ( & V_1046 -> V_439 ) ;
V_1047 = V_1046 ;
F_262 ( L_382
L_383 ,
F_289 ( V_308 , V_1047 -> V_308 ,
V_1047 -> V_806 ) ,
V_1047 -> V_216 ) ;
F_212 ( & V_1047 -> V_439 ,
& V_23 -> V_163 -> V_440 ) ;
}
V_435 = V_23 -> V_163 -> V_440 . V_771 ;
V_438 = F_210 ( V_435 , struct V_437 , V_439 ) ;
F_313 ( V_23 , V_438 ) ;
V_333 = & V_23 -> V_333 ;
F_211 ( V_435 ) ;
F_212 ( & V_438 -> V_439 , & V_23 -> V_163 -> V_1048 ) ;
}
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
if ( ! V_438 ) {
F_322 ( V_23 ) ;
if ( ! ( V_23 -> V_37 & V_318 ) ) {
if ( ! ( V_23 -> V_59 & V_195 ) )
F_56 ( & V_23 -> V_186 ,
V_1049 ) ;
else
F_56 ( & V_23 -> V_186 , 0 ) ;
}
return 0 ;
}
F_369 ( V_23 , V_438 , V_333 , 0 ) ;
return 1 ;
}
static void F_372 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_330 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_329 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_373 ( struct V_17 * V_23 ,
struct V_1002 * V_498 )
{
struct V_1050 * V_1051 ;
T_4 V_1052 ;
V_1051 = (struct V_1050 * ) V_498 -> V_3 ;
V_1052 = F_219 ( V_1051 -> V_1053 ) ;
if ( ! ( V_1052 & V_1054 ) )
return;
V_1052 &= ~ V_1054 ;
V_1051 -> V_1053 = F_172 ( V_1052 ) ;
switch ( V_23 -> V_163 -> V_244 . V_11 ) {
case V_840 :
memmove ( V_498 -> V_3 + V_1055 ,
V_498 -> V_3 + V_1055 + 8 ,
V_498 -> V_4 - V_1055 - 8 ) ;
F_374 ( V_498 , V_498 -> V_4 - 16 ) ;
break;
case V_843 :
break;
case V_844 :
memmove ( V_498 -> V_3 + V_1055 ,
V_498 -> V_3 + V_1055 + 4 ,
V_498 -> V_4 - V_1055 - 4 ) ;
F_374 ( V_498 , V_498 -> V_4 - 8 ) ;
break;
case V_845 :
break;
default:
F_4 ( V_1056 L_384 ,
V_23 -> V_163 -> V_244 . V_11 ) ;
break;
}
}
static void F_375 ( struct V_17 * V_23 ,
struct V_769 * V_770 ,
struct V_669 * V_670 )
{
struct V_165 * V_166 = V_23 -> V_167 ;
struct V_671 * V_1051 ;
struct V_1057 * V_1058 = (struct V_1057 * ) V_770 -> V_498 -> V_3 ;
V_166 -> V_1059 = V_140 ;
if ( F_29 ( ( F_219 ( V_1058 -> V_535 . V_1060 . V_412 ) + V_1061 ) >
F_376 ( V_770 -> V_498 ) ) ) {
V_166 -> V_670 . V_1062 ++ ;
V_23 -> V_1063 . V_1064 . V_1065 ++ ;
F_377 ( L_385 ) ;
return;
} else if ( F_29 ( ! F_92 ( V_23 -> V_167 ) ) ) {
V_166 -> V_670 . V_1066 ++ ;
V_23 -> V_1063 . V_1064 . V_1065 ++ ;
F_377 ( L_386 ) ;
return;
}
F_378 ( V_770 -> V_498 , F_379 ( struct V_1057 , V_535 . V_1060 . V_3 ) ) ;
F_380 ( V_770 -> V_498 , F_219 ( V_1058 -> V_535 . V_1060 . V_412 ) ) ;
F_381 ( L_387 , V_770 -> V_498 -> V_4 ) ;
V_1051 = (struct V_671 * ) V_770 -> V_498 -> V_3 ;
if ( V_23 -> V_163 -> V_510 != V_512 &&
( F_363 ( V_1051 -> V_1067 ) ?
! V_23 -> V_163 -> V_850 : ! V_23 -> V_163 -> V_842 ) )
F_373 ( V_23 , V_770 -> V_498 ) ;
if ( ! F_382 ( V_23 -> V_163 , V_770 -> V_498 , V_670 ) )
V_166 -> V_670 . V_1062 ++ ;
else {
V_770 -> V_498 = NULL ;
F_63 ( V_23 ) ;
}
}
static void F_383 ( struct V_17 * V_23 ,
struct V_769 * V_770 ,
struct V_669 * V_670 )
{
struct V_165 * V_166 = V_23 -> V_167 ;
struct V_1057 * V_1058 = (struct V_1057 * ) V_770 -> V_498 -> V_3 ;
struct V_1068 * V_1060 = & V_1058 -> V_535 . V_1060 ;
T_4 V_1069 = V_1060 -> V_1069 ;
T_2 V_1070 = V_1060 -> V_1070 ;
T_7 V_1071 = V_1060 -> V_1072 - V_1042 ;
T_4 V_1073 = V_1060 -> V_606 ;
struct V_1074 * V_1075 ;
short V_4 = F_219 ( V_1058 -> V_535 . V_1060 . V_412 ) ;
V_166 -> V_1059 = V_140 ;
if ( F_29 ( ( F_219 ( V_1058 -> V_535 . V_1060 . V_412 ) + V_1061 ) >
F_376 ( V_770 -> V_498 ) ) ) {
V_166 -> V_670 . V_1062 ++ ;
V_23 -> V_1063 . V_1064 . V_1065 ++ ;
F_377 ( L_385 ) ;
return;
} else if ( F_29 ( ! F_92 ( V_23 -> V_167 ) ) ) {
V_166 -> V_670 . V_1066 ++ ;
V_23 -> V_1063 . V_1064 . V_1065 ++ ;
F_377 ( L_386 ) ;
return;
}
if ( V_4 > V_500 - sizeof( struct V_1074 ) ) {
V_166 -> V_670 . V_1066 ++ ;
V_23 -> V_1063 . V_1064 . V_1065 ++ ;
F_377 ( L_388 ) ;
return;
}
memmove ( V_770 -> V_498 -> V_3 + sizeof( struct V_1074 ) ,
V_770 -> V_498 -> V_3 + V_1061 , V_4 ) ;
V_1075 = (struct V_1074 * ) V_770 -> V_498 -> V_3 ;
V_1075 -> V_1076 . V_1077 = V_1078 ;
V_1075 -> V_1076 . V_1079 = 0 ;
V_1075 -> V_1076 . V_1080 = F_172 ( sizeof( struct V_1074 ) ) ;
V_1075 -> V_1076 . V_1081 = F_178 (
( 1 << V_1082 ) |
( 1 << V_1083 ) |
( 1 << V_1084 ) |
( 1 << V_1085 ) |
( 1 << V_1086 ) |
( 1 << V_1087 ) |
( 1 << V_1088 ) ) ;
V_1075 -> V_1089 = 0 ;
V_1075 -> V_1090 = ( V_1091 ) ( V_1060 -> V_1092 [ 3 ] << 24 |
V_1060 -> V_1092 [ 2 ] << 16 |
V_1060 -> V_1092 [ 1 ] << 8 |
V_1060 -> V_1092 [ 0 ] ) ;
V_1075 -> V_1093 = V_1071 ;
V_1075 -> V_1094 = ( T_7 ) F_219 ( V_1060 -> V_733 ) ;
V_1075 -> V_1095 = F_172 ( F_384 ( V_1069 ) ) ;
if ( V_1069 > 14 ) {
V_1075 -> V_1096 =
F_172 ( ( V_1097 | V_1098 ) ) ;
} else if ( V_1070 & 32 ) {
V_1075 -> V_1096 =
F_172 ( ( V_1099 | V_1100 ) ) ;
} else {
V_1075 -> V_1096 =
F_172 ( V_1097 | V_1100 ) ;
}
switch ( V_1073 ) {
case V_609 :
V_1075 -> V_1101 = 2 ;
break;
case V_610 :
V_1075 -> V_1101 = 4 ;
break;
case V_611 :
V_1075 -> V_1101 = 10 ;
break;
case V_612 :
V_1075 -> V_1101 = 12 ;
break;
case V_613 :
V_1075 -> V_1101 = 18 ;
break;
case V_614 :
V_1075 -> V_1101 = 22 ;
break;
case V_615 :
V_1075 -> V_1101 = 24 ;
break;
case V_616 :
V_1075 -> V_1101 = 36 ;
break;
case V_617 :
V_1075 -> V_1101 = 48 ;
break;
case V_618 :
V_1075 -> V_1101 = 72 ;
break;
case V_619 :
V_1075 -> V_1101 = 96 ;
break;
case V_620 :
V_1075 -> V_1101 = 108 ;
break;
default:
V_1075 -> V_1101 = 0 ;
break;
}
V_1075 -> V_1102 = ( V_1070 & 3 ) ;
if ( ( V_1070 & 64 ) )
V_1075 -> V_1089 |= V_1103 ;
F_380 ( V_770 -> V_498 , V_4 + sizeof( struct V_1074 ) ) ;
F_381 ( L_387 , V_770 -> V_498 -> V_4 ) ;
if ( ! F_382 ( V_23 -> V_163 , V_770 -> V_498 , V_670 ) )
V_166 -> V_670 . V_1062 ++ ;
else {
V_770 -> V_498 = NULL ;
}
}
static void F_385 ( struct V_17 * V_23 ,
struct V_769 * V_770 ,
struct V_669 * V_670 )
{
struct V_165 * V_166 = V_23 -> V_157 ;
struct V_1057 * V_1058 = (struct V_1057 * ) V_770 -> V_498 -> V_3 ;
struct V_1068 * V_1060 = & V_1058 -> V_535 . V_1060 ;
struct V_1074 * V_1075 ;
struct V_1050 * V_1051 ;
T_4 V_197 = V_1060 -> V_1069 ;
T_2 V_1104 = V_1060 -> V_1070 ;
T_7 signal = V_1060 -> V_1072 - V_1042 ;
T_7 V_733 = ( T_7 ) F_219 ( V_1060 -> V_733 ) ;
T_2 V_606 = V_1060 -> V_606 ;
short V_4 = F_219 ( V_1058 -> V_535 . V_1060 . V_412 ) ;
struct V_1002 * V_498 ;
int V_1105 = 0 ;
T_4 V_161 = V_23 -> V_159 -> V_161 ;
if ( V_161 & V_1106 )
return;
V_166 -> V_1059 = V_140 ;
if ( F_29 ( ( V_4 + V_1061 ) > F_376 ( V_770 -> V_498 ) ) ) {
V_166 -> V_670 . V_1062 ++ ;
F_377 ( L_385 ) ;
return;
}
if ( F_29 ( ! F_92 ( V_166 ) ) ) {
V_166 -> V_670 . V_1066 ++ ;
F_377 ( L_386 ) ;
return;
}
if ( V_4 > V_500 - sizeof( struct V_1074 ) ) {
V_166 -> V_670 . V_1066 ++ ;
F_377 ( L_388 ) ;
return;
}
V_1051 = ( void * ) V_770 -> V_498 -> V_3 + V_1061 ;
if ( F_386 ( F_219 ( V_1051 -> V_1053 ) ) ) {
if ( V_161 & V_1107 )
return;
if ( V_161 & V_1108 )
V_1105 = 1 ;
} else if ( F_387 ( F_219 ( V_1051 -> V_1053 ) ) ) {
if ( V_161 & V_1109 )
return;
if ( V_161 & V_1110 )
V_1105 = 1 ;
} else if ( F_388 ( F_219 ( V_1051 -> V_1053 ) ) ) {
if ( V_161 & V_1111 )
return;
if ( V_161 & V_1112 )
V_1105 = 1 ;
}
V_498 = F_389 ( V_770 -> V_498 , V_139 ) ;
if ( V_498 == NULL ) {
F_46 ( L_389 ) ;
return;
}
V_1075 = ( void * ) V_498 -> V_3 ;
if ( V_1105 )
V_4 = F_390 ( F_219 ( V_1051 -> V_1053 ) ) ;
memcpy ( V_1075 -> V_142 , V_1051 , V_4 ) ;
V_1075 -> V_1076 . V_1077 = V_1078 ;
V_1075 -> V_1076 . V_1079 = 0 ;
V_1075 -> V_1076 . V_1080 = F_172 ( sizeof( * V_1075 ) ) ;
F_380 ( V_498 , sizeof( * V_1075 ) + V_4 ) ;
V_1075 -> V_1076 . V_1081 = F_178 (
( 1 << V_1082 ) |
( 1 << V_1083 ) |
( 1 << V_1084 ) |
( 1 << V_1085 ) |
( 1 << V_1086 ) |
( 1 << V_1087 ) |
( 1 << V_1088 ) ) ;
V_1075 -> V_1089 = 0 ;
V_1075 -> V_1090 = ( V_1091 ) ( V_1060 -> V_1092 [ 3 ] << 24 |
V_1060 -> V_1092 [ 2 ] << 16 |
V_1060 -> V_1092 [ 1 ] << 8 |
V_1060 -> V_1092 [ 0 ] ) ;
V_1075 -> V_1093 = signal ;
V_1075 -> V_1094 = V_733 ;
V_1075 -> V_1095 = F_172 ( F_384 ( V_197 ) ) ;
if ( V_197 > 14 ) {
V_1075 -> V_1096 =
F_172 ( ( V_1097 | V_1098 ) ) ;
} else if ( V_1104 & ( 1 << 5 ) ) {
V_1075 -> V_1096 =
F_172 ( ( V_1099 | V_1100 ) ) ;
} else {
V_1075 -> V_1096 =
F_172 ( V_1097 | V_1100 ) ;
}
switch ( V_606 ) {
case V_609 :
V_1075 -> V_1101 = 2 ;
break;
case V_610 :
V_1075 -> V_1101 = 4 ;
break;
case V_611 :
V_1075 -> V_1101 = 10 ;
break;
case V_612 :
V_1075 -> V_1101 = 12 ;
break;
case V_613 :
V_1075 -> V_1101 = 18 ;
break;
case V_614 :
V_1075 -> V_1101 = 22 ;
break;
case V_615 :
V_1075 -> V_1101 = 24 ;
break;
case V_616 :
V_1075 -> V_1101 = 36 ;
break;
case V_617 :
V_1075 -> V_1101 = 48 ;
break;
case V_618 :
V_1075 -> V_1101 = 72 ;
break;
case V_619 :
V_1075 -> V_1101 = 96 ;
break;
case V_620 :
V_1075 -> V_1101 = 108 ;
break;
default:
V_1075 -> V_1101 = 0 ;
break;
}
V_1075 -> V_1102 = ( V_1104 & 3 ) ;
if ( V_1104 & ( 1 << 6 ) )
V_1075 -> V_1089 |= V_1103 ;
F_381 ( L_387 , V_498 -> V_4 ) ;
if ( ! F_382 ( V_23 -> V_159 -> V_163 , V_498 , V_670 ) ) {
V_166 -> V_670 . V_1062 ++ ;
F_391 ( V_498 ) ;
}
}
static int F_392 ( struct V_17 * V_23 ,
struct V_671 * V_1113 )
{
switch ( V_23 -> V_163 -> V_510 ) {
case V_511 :
if ( ! memcmp ( V_1113 -> V_1114 , V_23 -> V_167 -> V_1115 , V_217 ) )
return 0 ;
if ( F_363 ( V_1113 -> V_1067 ) )
return ! memcmp ( V_1113 -> V_1116 , V_23 -> V_216 , V_217 ) ;
return ! memcmp ( V_1113 -> V_1067 , V_23 -> V_167 -> V_1115 ,
V_217 ) ;
case V_513 :
if ( ! memcmp ( V_1113 -> V_1116 , V_23 -> V_167 -> V_1115 , V_217 ) )
return 0 ;
if ( F_363 ( V_1113 -> V_1067 ) )
return ! memcmp ( V_1113 -> V_1114 , V_23 -> V_216 , V_217 ) ;
return ! memcmp ( V_1113 -> V_1067 , V_23 -> V_167 -> V_1115 ,
V_217 ) ;
}
return 1 ;
}
static int F_393 ( struct V_17 * V_23 ,
struct V_671 * V_1113 )
{
T_4 V_1117 = F_219 ( V_1113 -> V_1118 ) ;
T_4 V_1119 = F_394 ( V_1117 ) ;
T_4 V_356 = F_395 ( V_1117 ) ;
T_4 * V_1120 , * V_1121 ;
unsigned long * V_1122 ;
switch ( V_23 -> V_163 -> V_510 ) {
case V_511 :
{
struct V_434 * V_134 ;
struct V_1123 * V_542 = NULL ;
T_2 * V_311 = V_1113 -> V_1114 ;
int V_397 = V_311 [ 5 ] % V_1124 ;
F_396 (p, &priv->ibss_mac_hash[index]) {
V_542 =
F_210 ( V_134 , struct V_1123 , V_439 ) ;
if ( ! memcmp ( V_542 -> V_311 , V_311 , V_217 ) )
break;
}
if ( V_134 == & V_23 -> V_1125 [ V_397 ] ) {
V_542 = F_83 ( sizeof( * V_542 ) , V_139 ) ;
if ( ! V_542 ) {
F_46
( L_390 ) ;
return 0 ;
}
memcpy ( V_542 -> V_311 , V_311 , V_217 ) ;
V_542 -> V_835 = V_1119 ;
V_542 -> V_1126 = V_356 ;
V_542 -> V_1127 = V_140 ;
F_397 ( & V_542 -> V_439 ,
& V_23 -> V_1125 [ V_397 ] ) ;
return 0 ;
}
V_1120 = & V_542 -> V_835 ;
V_1121 = & V_542 -> V_1126 ;
V_1122 = & V_542 -> V_1127 ;
break;
}
case V_513 :
V_1120 = & V_23 -> V_1128 ;
V_1121 = & V_23 -> V_1129 ;
V_1122 = & V_23 -> V_1130 ;
break;
default:
return 0 ;
}
if ( ( * V_1120 == V_1119 ) &&
F_308 ( * V_1122 + V_1131 , V_140 ) ) {
if ( * V_1121 == V_356 )
goto V_1132;
if ( * V_1121 + 1 != V_356 )
goto V_1132;
} else
* V_1120 = V_1119 ;
* V_1121 = V_356 ;
* V_1122 = V_140 ;
return 0 ;
V_1132:
return 1 ;
}
static void F_398 ( struct V_17 * V_23 ,
struct V_769 * V_770 ,
struct V_669 * V_670 )
{
struct V_1002 * V_498 = V_770 -> V_498 ;
struct V_1057 * V_1058 = (struct V_1057 * ) V_498 -> V_3 ;
struct V_671 * V_1113 = (struct V_671 * )
( V_498 -> V_3 + V_1061 ) ;
F_293 ( V_23 -> V_163 , V_1113 , V_670 ) ;
if ( V_23 -> V_163 -> V_510 == V_511 &&
( ( F_399 ( F_219 ( V_1113 -> V_1133 ) ) ==
V_1134 ) ||
( F_399 ( F_219 ( V_1113 -> V_1133 ) ) ==
V_1135 ) ) ) {
if ( ! memcmp ( V_1113 -> V_1116 , V_23 -> V_216 , V_217 ) )
F_259 ( V_23 , V_1113 -> V_1114 ) ;
}
if ( V_23 -> V_59 & V_200 ) {
F_142 ( L_391 ) ;
F_380 ( V_498 , F_219 ( V_1058 -> V_535 . V_1060 . V_412 ) +
V_1061 ) ;
F_400 ( V_498 , V_1061 ) ;
memcpy ( F_401 ( V_498 , sizeof( * V_670 ) ) , V_670 , sizeof( * V_670 ) ) ;
V_498 -> V_166 = V_23 -> V_163 -> V_166 ;
F_402 ( V_498 ) ;
V_498 -> V_1136 = V_1137 ;
V_498 -> V_1138 = F_403 ( V_1139 ) ;
memset ( V_498 -> V_398 , 0 , sizeof( V_770 -> V_498 -> V_398 ) ) ;
F_404 ( V_498 ) ;
V_770 -> V_498 = NULL ;
}
}
static void F_141 ( struct V_17 * V_23 )
{
struct V_769 * V_770 ;
struct V_1057 * V_1058 ;
struct V_671 * V_1113 ;
T_3 V_378 , V_1140 , V_7 ;
T_2 V_1141 ;
T_2 V_1142 = 0 ;
V_378 = F_36 ( V_23 , V_517 ) ;
V_1140 = F_36 ( V_23 , V_777 ) ;
V_7 = V_23 -> V_493 -> V_502 ;
if ( F_248 ( V_23 -> V_493 ) > ( V_497 / 2 ) )
V_1142 = 1 ;
while ( V_7 != V_378 ) {
V_770 = V_23 -> V_493 -> V_774 [ V_7 ] ;
if ( F_29 ( V_770 == NULL ) ) {
F_4 ( V_778 L_392 ) ;
break;
}
V_23 -> V_493 -> V_774 [ V_7 ] = NULL ;
F_405 ( V_23 -> V_474 , V_770 -> V_499 ,
V_500 ,
V_501 ) ;
V_1058 = (struct V_1057 * ) V_770 -> V_498 -> V_3 ;
F_381 ( L_393 ,
V_1058 -> V_1113 . V_533 ,
V_1058 -> V_1113 . V_1143 , V_1058 -> V_1113 . V_766 ) ;
switch ( V_1058 -> V_1113 . V_533 ) {
case V_1144 : {
struct V_669 V_670 = {
. V_629 = V_1058 -> V_535 . V_1060 . V_1072 -
V_1042 ,
. signal =
V_1058 -> V_535 . V_1060 . V_1072 -
V_1042 + 0x100 ,
. V_733 =
F_219 ( V_1058 -> V_535 . V_1060 . V_733 ) ,
. V_606 = V_1058 -> V_535 . V_1060 . V_606 ,
. V_1145 = V_140 ,
. V_1069 =
V_1058 -> V_535 . V_1060 . V_1069 ,
. V_1146 =
( V_1058 -> V_535 . V_1060 .
V_391 & ( 1 << 0 ) ) ?
V_817 :
V_816 ,
. V_4 = F_219 ( V_1058 -> V_535 . V_1060 . V_412 ) ,
} ;
if ( V_670 . V_629 != 0 )
V_670 . V_36 |= V_1147 ;
if ( V_670 . signal != 0 )
V_670 . V_36 |= V_1148 ;
if ( V_670 . V_733 != 0 )
V_670 . V_36 |= V_1149 ;
if ( V_670 . V_606 != 0 )
V_670 . V_36 |= V_1150 ;
V_23 -> V_590 ++ ;
#ifdef F_267
if ( V_23 -> V_157 && F_92 ( V_23 -> V_157 ) )
F_385 ( V_23 , V_770 , & V_670 ) ;
#endif
#ifdef F_242
if ( V_23 -> V_163 -> V_510 == V_512 ) {
#ifdef F_406
F_383 ( V_23 ,
V_770 ,
& V_670 ) ;
#else
F_375 ( V_23 , V_770 ,
& V_670 ) ;
#endif
break;
}
#endif
V_1113 =
(struct V_671 * ) ( V_770 -> V_498 ->
V_3 +
V_1061 ) ;
V_1141 =
F_392 ( V_23 , V_1113 ) ;
if ( V_1141 && V_23 -> V_117 ) {
V_23 -> V_117 -> V_670 . V_629 =
V_670 . V_629 ;
V_23 -> V_578 =
F_270 ( V_23 -> V_578 ,
V_670 . V_629 , V_1151 ) ;
}
F_381 ( L_394 ,
F_219 ( V_1058 -> V_535 . V_1060 . V_412 ) ) ;
if ( F_219 ( V_1058 -> V_535 . V_1060 . V_412 ) <
F_390 ( F_219 (
V_1113 -> V_1133 ) ) ) {
F_377
( L_395
L_396 ) ;
V_23 -> V_167 -> V_670 . V_1062 ++ ;
V_23 -> V_1063 . V_1064 . V_1065 ++ ;
break;
}
switch ( F_407
( F_219 ( V_1113 -> V_1133 ) ) ) {
case V_1152 :
F_398 ( V_23 , V_770 ,
& V_670 ) ;
break;
case V_1153 :
break;
case V_1154 :
if ( F_29 ( ! V_1141 ||
F_393 ( V_23 ,
V_1113 ) ) )
{
F_377 ( L_397
L_398
L_398
L_399 ,
V_1113 -> V_1067 ,
V_1113 -> V_1114 ,
V_1113 -> V_1116 ) ;
break;
}
F_375 ( V_23 , V_770 ,
& V_670 ) ;
break;
}
break;
}
case V_1155 : {
F_381
( L_400 ,
V_1058 -> V_535 . V_1156 . V_657 ,
V_1058 -> V_535 . V_1156 . V_41 ,
F_219 ( V_1058 -> V_535 . V_1156 . V_15 ) ) ;
F_287 ( V_23 , & V_1058 -> V_535 . V_1156 ) ;
break;
}
default:
F_381 ( L_401 ,
V_1058 -> V_1113 . V_533 ) ;
break;
}
if ( V_770 -> V_498 != NULL ) {
F_391 ( V_770 -> V_498 ) ;
V_770 -> V_498 = NULL ;
}
F_236 ( V_23 -> V_474 , V_770 -> V_499 ,
V_500 , V_501 ) ;
F_212 ( & V_770 -> V_439 , & V_23 -> V_493 -> V_495 ) ;
V_7 = ( V_7 + 1 ) % V_497 ;
if ( V_1142 ) {
V_23 -> V_493 -> V_502 = V_7 ;
F_245 ( V_23 ) ;
}
}
V_23 -> V_493 -> V_502 = V_7 ;
F_295 ( V_23 ) ;
}
static int F_408 ( struct V_17 * V_23 , int V_1157 )
{
int V_878 , V_800 ;
int V_1158 = V_23 -> V_163 -> V_510 ;
V_23 -> V_59 = 0 ;
if ( ! V_1159 )
V_23 -> V_59 |= V_95 ;
if ( V_330 )
V_23 -> V_59 |= V_1044 ;
else
F_74 ( L_402 ) ;
if ( V_1160 )
V_23 -> V_59 |= V_1045 ;
else
F_74 ( L_403 ) ;
V_23 -> V_59 &= ~ V_807 ;
V_23 -> V_664 = 0 ;
memset ( V_23 -> V_663 , 0 , V_310 ) ;
if ( V_1161 && V_1157 ) {
V_23 -> V_37 |= V_184 ;
F_74 ( L_404 ) ;
}
if ( V_1162 != 0 ) {
V_23 -> V_59 |= V_546 ;
V_23 -> V_197 = V_1162 ;
F_74 ( L_405 , V_1162 ) ;
}
#ifdef F_290
F_360 ( V_23 , V_975 , V_1163 ,
V_994 , V_995 ) ;
#endif
switch ( V_1164 ) {
case 1 :
V_23 -> V_163 -> V_510 = V_511 ;
V_23 -> V_167 -> type = V_214 ;
break;
#ifdef F_242
case 2 :
V_23 -> V_163 -> V_510 = V_512 ;
#ifdef F_406
V_23 -> V_167 -> type = V_1165 ;
#else
V_23 -> V_167 -> type = V_1166 ;
#endif
break;
#endif
default:
case 0 :
V_23 -> V_167 -> type = V_214 ;
V_23 -> V_163 -> V_510 = V_513 ;
break;
}
if ( V_938 ) {
V_23 -> V_163 -> V_839 = 0 ;
V_23 -> V_163 -> V_943 = 0 ;
V_23 -> V_163 -> V_842 = 0 ;
V_23 -> V_163 -> V_850 = 0 ;
}
F_74 ( L_406 , V_938 ? L_299 : L_300 ) ;
V_23 -> V_163 -> V_1167 = 0 ;
if ( ( V_23 -> V_474 -> V_143 == 0x4223 ) ||
( V_23 -> V_474 -> V_143 == 0x4224 ) ) {
if ( V_1157 == 1 )
F_4 (KERN_INFO DRV_NAME
L_407
L_408 ) ;
V_23 -> V_163 -> V_350 = 1 ;
V_878 = V_816 | V_817 ;
V_800 = V_803 |
V_1168 ;
V_23 -> V_313 = V_1169 ;
V_23 -> V_163 -> V_118 = V_119 | V_121 | V_605 ;
} else {
if ( V_1157 == 1 )
F_4 (KERN_INFO DRV_NAME
L_409
L_408 ) ;
V_23 -> V_163 -> V_350 = 0 ;
V_878 = V_817 ;
V_800 = V_803 |
V_1168 ;
V_23 -> V_313 = V_1170 ;
V_23 -> V_163 -> V_118 = V_121 | V_605 ;
}
V_23 -> V_163 -> V_857 = V_878 ;
V_23 -> V_163 -> V_800 = V_800 ;
V_23 -> V_591 = V_1171 ;
V_23 -> V_644 = V_1172 ;
V_23 -> V_652 = V_1173 ;
V_23 -> V_354 = V_1174 ;
V_23 -> V_369 = V_1175 ;
V_23 -> V_370 = V_1176 ;
V_23 -> V_1177 = V_362 ;
V_23 -> V_342 = V_1178 ;
return V_1158 == V_23 -> V_163 -> V_510 ;
}
static int F_409 ( struct V_17 * V_23 , T_2 V_197 )
{
if ( V_197 == 0 ) {
F_74 ( L_410 ) ;
V_23 -> V_59 &= ~ V_546 ;
F_262 ( L_411
L_412 ) ;
V_329 ( V_23 ) ;
return 0 ;
}
V_23 -> V_59 |= V_546 ;
if ( V_23 -> V_197 == V_197 ) {
F_74 ( L_413 ,
V_197 ) ;
return 0 ;
}
F_74 ( L_414 , ( int ) V_197 ) ;
V_23 -> V_197 = V_197 ;
#ifdef F_242
if ( V_23 -> V_163 -> V_510 == V_512 ) {
int V_7 ;
if ( V_23 -> V_37 & V_318 ) {
F_165 ( L_415
L_416 ) ;
F_167 ( V_23 ) ;
}
for ( V_7 = 1000 ; V_7 && ( V_23 -> V_37 & V_318 ) ; V_7 -- )
F_186 ( 10 ) ;
if ( V_23 -> V_37 & V_318 )
F_165 ( L_417 ) ;
else
F_165 ( L_418 ,
1000 - V_7 ) ;
return 0 ;
}
#endif
F_262 ( L_419 ) ;
if ( ! F_263 ( V_23 ) )
V_329 ( V_23 ) ;
return 0 ;
}
static int F_410 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
const struct V_201 * V_202 = F_137 ( V_23 -> V_163 ) ;
struct V_1179 * V_1180 = & V_211 -> V_1146 ;
int V_429 = 0 , V_7 ;
T_2 V_197 , V_41 ;
int V_878 ;
if ( V_1180 -> V_1181 == 0 ) {
F_324 ( L_420 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_429 = F_409 ( V_23 , 0 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_429 ;
}
if ( V_1180 -> V_1182 == 1 ) {
V_197 = F_411 ( V_23 -> V_163 , V_1180 -> V_1181 ) ;
if ( V_197 == 0 )
return - V_75 ;
} else
V_197 = V_1180 -> V_1181 ;
if ( ! ( V_878 = F_133 ( V_23 -> V_163 , V_197 ) ) )
return - V_75 ;
if ( V_23 -> V_163 -> V_510 == V_511 ) {
V_7 = F_314 ( V_23 -> V_163 , V_197 ) ;
if ( V_7 == - 1 )
return - V_75 ;
V_41 = ( V_878 == V_817 ) ?
V_202 -> V_204 [ V_7 ] . V_41 : V_202 -> V_18 [ V_7 ] . V_41 ;
if ( V_41 & V_207 ) {
F_324 ( L_421 ) ;
return - V_75 ;
}
}
F_324 ( L_422 , V_1180 -> V_1181 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_429 = F_409 ( V_23 , V_197 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_429 ;
}
static int F_412 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
V_211 -> V_1146 . V_1182 = 0 ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_59 & V_546 ||
V_23 -> V_37 & ( V_240 | V_103 ) ) {
int V_7 ;
V_7 = F_314 ( V_23 -> V_163 , V_23 -> V_197 ) ;
F_223 ( V_7 == - 1 ) ;
V_211 -> V_1146 . V_1182 = 1 ;
switch ( F_133 ( V_23 -> V_163 , V_23 -> V_197 ) ) {
case V_816 :
V_211 -> V_1146 . V_1181 = V_23 -> V_163 -> V_202 . V_18 [ V_7 ] . V_1146 * 100000 ;
break;
case V_817 :
V_211 -> V_1146 . V_1181 = V_23 -> V_163 -> V_202 . V_204 [ V_7 ] . V_1146 * 100000 ;
break;
default:
F_358 () ;
}
} else
V_211 -> V_1146 . V_1181 = 0 ;
F_60 ( & V_23 -> V_109 ) ;
F_324 ( L_423 , V_23 -> V_197 ) ;
return 0 ;
}
static int F_413 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
int V_554 = 0 ;
F_324 ( L_424 , V_211 -> V_118 ) ;
switch ( V_211 -> V_118 ) {
#ifdef F_242
case V_512 :
#endif
case V_511 :
case V_513 :
break;
case V_1183 :
V_211 -> V_118 = V_513 ;
break;
default:
return - V_75 ;
}
if ( V_211 -> V_118 == V_23 -> V_163 -> V_510 )
return 0 ;
F_59 ( & V_23 -> V_109 ) ;
F_408 ( V_23 , 0 ) ;
#ifdef F_242
if ( V_23 -> V_163 -> V_510 == V_512 )
V_23 -> V_167 -> type = V_214 ;
if ( V_211 -> V_118 == V_512 )
#ifdef F_406
V_23 -> V_167 -> type = V_1165 ;
#else
V_23 -> V_167 -> type = V_1166 ;
#endif
#endif
F_238 () ;
V_23 -> V_163 -> V_510 = V_211 -> V_118 ;
F_128 ( & V_23 -> V_246 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_554 ;
}
static int F_414 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_118 = V_23 -> V_163 -> V_510 ;
F_324 ( L_425 , V_211 -> V_118 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_415 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
struct V_1184 * V_1185 = (struct V_1184 * ) V_900 ;
const struct V_201 * V_202 = F_137 ( V_23 -> V_163 ) ;
int V_7 = 0 , V_8 ;
V_211 -> V_3 . V_412 = sizeof( * V_1185 ) ;
memset ( V_1185 , 0 , sizeof( * V_1185 ) ) ;
V_1185 -> V_1186 = 27 * 1000 * 1000 ;
V_1185 -> V_1187 . V_1188 = 100 ;
V_1185 -> V_1187 . V_11 = 0 ;
V_1185 -> V_1187 . V_733 = 0 ;
V_1185 -> V_1187 . V_1189 = 7 ;
V_1185 -> V_1190 . V_1188 = 70 ;
V_1185 -> V_1190 . V_11 = 0 ;
V_1185 -> V_1190 . V_733 = 0 ;
V_1185 -> V_1190 . V_1189 = 7 ;
F_59 ( & V_23 -> V_109 ) ;
V_1185 -> V_1191 = F_3 ( V_23 -> V_333 . V_792 , ( T_2 ) V_1192 ) ;
for ( V_7 = 0 ; V_7 < V_1185 -> V_1191 ; V_7 ++ )
V_1185 -> V_1193 [ V_7 ] = ( V_23 -> V_333 . V_795 [ V_7 ] & 0x7F ) *
500000 ;
V_1185 -> V_1194 = V_1174 ;
V_1185 -> V_1195 = V_1196 ;
V_1185 -> V_1197 = V_1198 ;
V_1185 -> V_1199 [ 0 ] = 5 ;
V_1185 -> V_1199 [ 1 ] = 13 ;
V_1185 -> V_1200 = 2 ;
V_1185 -> V_1201 = V_1202 ;
V_1185 -> V_1203 = V_1204 ;
V_1185 -> V_1205 = 18 ;
V_7 = 0 ;
if ( V_23 -> V_163 -> V_118 & ( V_605 | V_121 ) ) {
for ( V_8 = 0 ; V_8 < V_202 -> V_203 && V_7 < V_1206 ; V_8 ++ ) {
if ( ( V_23 -> V_163 -> V_510 == V_511 ) &&
( V_202 -> V_204 [ V_8 ] . V_41 & V_207 ) )
continue;
V_1185 -> V_1146 [ V_7 ] . V_7 = V_202 -> V_204 [ V_8 ] . V_197 ;
V_1185 -> V_1146 [ V_7 ] . V_1181 = V_202 -> V_204 [ V_8 ] . V_1146 * 100000 ;
V_1185 -> V_1146 [ V_7 ] . V_1182 = 1 ;
V_7 ++ ;
}
}
if ( V_23 -> V_163 -> V_118 & V_119 ) {
for ( V_8 = 0 ; V_8 < V_202 -> V_209 && V_7 < V_1206 ; V_8 ++ ) {
if ( ( V_23 -> V_163 -> V_510 == V_511 ) &&
( V_202 -> V_18 [ V_8 ] . V_41 & V_207 ) )
continue;
V_1185 -> V_1146 [ V_7 ] . V_7 = V_202 -> V_18 [ V_8 ] . V_197 ;
V_1185 -> V_1146 [ V_7 ] . V_1181 = V_202 -> V_18 [ V_8 ] . V_1146 * 100000 ;
V_1185 -> V_1146 [ V_7 ] . V_1182 = 1 ;
V_7 ++ ;
}
}
V_1185 -> V_346 = V_7 ;
V_1185 -> V_1207 = V_7 ;
F_60 ( & V_23 -> V_109 ) ;
V_1185 -> V_1208 [ 0 ] = ( V_1209 |
F_416 ( V_1210 ) |
F_416 ( V_218 ) |
F_416 ( V_654 ) ) ;
V_1185 -> V_1208 [ 1 ] = V_1211 ;
V_1185 -> V_1212 = V_1213 | V_1214 |
V_1215 | V_1216 ;
V_1185 -> V_1217 = V_1218 | V_1219 ;
F_324 ( L_426 ) ;
return 0 ;
}
static int F_417 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
static const unsigned char V_1220 [] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
static const unsigned char V_1221 [] = {
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00
} ;
if ( V_211 -> V_212 . V_213 != V_214 )
return - V_75 ;
F_59 ( & V_23 -> V_109 ) ;
if ( ! memcmp ( V_1220 , V_211 -> V_212 . V_215 , V_217 ) ||
! memcmp ( V_1221 , V_211 -> V_212 . V_215 , V_217 ) ) {
F_324 ( L_427 ) ;
V_23 -> V_59 &= ~ V_815 ;
F_262 ( L_411
L_412 ) ;
V_329 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
V_23 -> V_59 |= V_815 ;
if ( ! memcmp ( V_23 -> V_216 , V_211 -> V_212 . V_215 , V_217 ) ) {
F_324 ( L_428 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
F_324 ( L_429 ,
V_211 -> V_212 . V_215 ) ;
memcpy ( V_23 -> V_216 , V_211 -> V_212 . V_215 , V_217 ) ;
F_262 ( L_430 ) ;
if ( ! F_263 ( V_23 ) )
V_329 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_418 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_59 & V_815 ||
V_23 -> V_37 & ( V_103 | V_240 ) ) {
V_211 -> V_212 . V_213 = V_214 ;
memcpy ( V_211 -> V_212 . V_215 , V_23 -> V_216 , V_217 ) ;
} else
memset ( V_211 -> V_212 . V_215 , 0 , V_217 ) ;
F_324 ( L_431 ,
V_211 -> V_212 . V_215 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_419 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
int V_412 ;
F_288 ( V_308 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( ! V_211 -> V_663 . V_41 )
{
F_324 ( L_432 ) ;
F_263 ( V_23 ) ;
V_23 -> V_59 &= ~ V_807 ;
V_329 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
V_412 = F_3 ( ( int ) V_211 -> V_663 . V_412 , V_310 ) ;
V_23 -> V_59 |= V_807 ;
if ( V_23 -> V_664 == V_412 && ! memcmp ( V_23 -> V_663 , V_900 , V_412 )
&& ( V_23 -> V_37 & ( V_103 | V_240 ) ) ) {
F_324 ( L_433 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
F_324 ( L_434 ,
F_289 ( V_308 , V_900 , V_412 ) , V_412 ) ;
V_23 -> V_664 = V_412 ;
memcpy ( V_23 -> V_663 , V_900 , V_23 -> V_664 ) ;
F_262 ( L_435 ) ;
if ( ! F_263 ( V_23 ) )
V_329 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_420 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_288 ( V_308 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_59 & V_807 ||
V_23 -> V_37 & ( V_103 | V_240 ) ) {
F_324 ( L_436 ,
F_289 ( V_308 , V_23 -> V_663 , V_23 -> V_664 ) ) ;
memcpy ( V_900 , V_23 -> V_663 , V_23 -> V_664 ) ;
V_211 -> V_663 . V_412 = V_23 -> V_664 ;
V_211 -> V_663 . V_41 = 1 ;
} else {
F_324 ( L_437 ) ;
V_211 -> V_663 . V_412 = 0 ;
V_211 -> V_663 . V_41 = 0 ;
}
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_421 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_324 ( L_438 , V_900 ) ;
if ( V_211 -> V_3 . V_412 > V_310 )
return - V_902 ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_3 . V_412 = F_3 ( ( T_1 ) V_211 -> V_3 . V_412 , sizeof( V_23 -> V_1222 ) ) ;
memset ( V_23 -> V_1222 , 0 , sizeof( V_23 -> V_1222 ) ) ;
memcpy ( V_23 -> V_1222 , V_900 , V_211 -> V_3 . V_412 ) ;
F_194 ( L_153 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_422 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_324 ( L_439 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_3 . V_412 = strlen ( V_23 -> V_1222 ) ;
memcpy ( V_900 , V_23 -> V_1222 , V_211 -> V_3 . V_412 ) ;
V_211 -> V_3 . V_41 = 1 ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_423 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
int V_554 = 0 ;
F_324 ( L_440 , V_211 -> V_324 . V_25 ) ;
F_324 ( L_441 , 3 * V_211 -> V_324 . V_25 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_211 -> V_324 . V_1223 == 0 )
{
V_23 -> V_652 = V_1173 ;
V_23 -> V_644 = V_1172 ;
goto V_6;
}
if ( ( V_211 -> V_324 . V_25 > V_1224 ) ||
( V_211 -> V_324 . V_25 < V_1225 ) ) {
V_554 = - V_75 ;
goto V_6;
}
V_23 -> V_652 = V_211 -> V_324 . V_25 ;
V_23 -> V_644 = 3 * V_211 -> V_324 . V_25 ;
V_6:
F_60 ( & V_23 -> V_109 ) ;
return V_554 ;
}
static int F_424 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_324 . V_1223 = 1 ;
V_211 -> V_324 . V_25 = V_23 -> V_652 ;
F_60 ( & V_23 -> V_109 ) ;
F_324 ( L_442 ,
V_211 -> V_340 . V_1226 ? L_96 : L_97 , V_211 -> V_340 . V_25 ) ;
return 0 ;
}
static int F_425 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
T_3 V_1227 = V_211 -> V_1193 . V_25 ;
T_3 V_1223 , V_36 ;
if ( V_1227 == - 1 ) {
V_1223 = 0 ;
V_36 = V_1171 ;
goto V_1228;
}
V_36 = 0 ;
V_1223 = V_211 -> V_1193 . V_1223 ;
if ( V_1227 == 1000000 || ! V_1223 )
V_36 |= V_593 ;
if ( V_1227 == 1000000 )
goto V_1228;
if ( V_1227 == 2000000 || ! V_1223 )
V_36 |= V_594 ;
if ( V_1227 == 2000000 )
goto V_1228;
if ( V_1227 == 5500000 || ! V_1223 )
V_36 |= V_595 ;
if ( V_1227 == 5500000 )
goto V_1228;
if ( V_1227 == 6000000 || ! V_1223 )
V_36 |= V_596 ;
if ( V_1227 == 6000000 )
goto V_1228;
if ( V_1227 == 9000000 || ! V_1223 )
V_36 |= V_597 ;
if ( V_1227 == 9000000 )
goto V_1228;
if ( V_1227 == 11000000 || ! V_1223 )
V_36 |= V_598 ;
if ( V_1227 == 11000000 )
goto V_1228;
if ( V_1227 == 12000000 || ! V_1223 )
V_36 |= V_599 ;
if ( V_1227 == 12000000 )
goto V_1228;
if ( V_1227 == 18000000 || ! V_1223 )
V_36 |= V_600 ;
if ( V_1227 == 18000000 )
goto V_1228;
if ( V_1227 == 24000000 || ! V_1223 )
V_36 |= V_601 ;
if ( V_1227 == 24000000 )
goto V_1228;
if ( V_1227 == 36000000 || ! V_1223 )
V_36 |= V_602 ;
if ( V_1227 == 36000000 )
goto V_1228;
if ( V_1227 == 48000000 || ! V_1223 )
V_36 |= V_603 ;
if ( V_1227 == 48000000 )
goto V_1228;
if ( V_1227 == 54000000 || ! V_1223 )
V_36 |= V_604 ;
if ( V_1227 == 54000000 )
goto V_1228;
F_324 ( L_443 ) ;
return - V_75 ;
V_1228:
F_324 ( L_444 ,
V_36 , V_1223 ? L_445 : L_446 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_36 == V_1171 ) {
V_23 -> V_59 &= ~ V_1021 ;
F_323 ( V_23 , V_23 -> V_163 -> V_118 ) ;
} else
V_23 -> V_59 |= V_1021 ;
if ( V_23 -> V_591 == V_36 ) {
F_324 ( L_447 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
V_23 -> V_591 = V_36 ;
F_262 ( L_448 ) ;
if ( ! F_263 ( V_23 ) )
V_329 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_426 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_1193 . V_25 = V_23 -> V_580 ;
V_211 -> V_1193 . V_1223 = ( V_23 -> V_59 & V_1021 ) ? 1 : 0 ;
F_60 ( & V_23 -> V_109 ) ;
F_324 ( L_449 , V_211 -> V_1193 . V_25 ) ;
return 0 ;
}
static int F_427 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_211 -> V_352 . V_1226 || ! V_211 -> V_352 . V_1223 )
V_23 -> V_354 = V_1174 ;
else {
if ( V_211 -> V_352 . V_25 < V_1229 ||
V_211 -> V_352 . V_25 > V_1230 ) {
F_60 ( & V_23 -> V_109 ) ;
return - V_75 ;
}
V_23 -> V_354 = V_211 -> V_352 . V_25 ;
}
F_181 ( V_23 , V_23 -> V_354 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_324 ( L_450 , V_23 -> V_354 ) ;
return 0 ;
}
static int F_428 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_352 . V_25 = V_23 -> V_354 ;
V_211 -> V_352 . V_1223 = 0 ;
V_211 -> V_352 . V_1226 = ( V_211 -> V_352 . V_25 == V_1174 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_324 ( L_451 , V_211 -> V_352 . V_25 ) ;
return 0 ;
}
static int F_429 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
int V_554 = 0 ;
F_59 ( & V_23 -> V_109 ) ;
if ( F_126 ( V_23 , V_211 -> V_340 . V_1226 ) ) {
V_554 = - V_1231 ;
goto V_6;
}
if ( ! V_211 -> V_340 . V_1223 )
V_211 -> V_340 . V_25 = V_1178 ;
if ( V_211 -> V_340 . V_41 != V_1232 ) {
V_554 = - V_75 ;
goto V_6;
}
if ( ( V_211 -> V_340 . V_25 > V_1233 ) ||
( V_211 -> V_340 . V_25 < V_1234 ) ) {
V_554 = - V_75 ;
goto V_6;
}
V_23 -> V_342 = V_211 -> V_340 . V_25 ;
V_554 = F_180 ( V_23 ) ;
V_6:
F_60 ( & V_23 -> V_109 ) ;
return V_554 ;
}
static int F_430 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_340 . V_25 = V_23 -> V_342 ;
V_211 -> V_340 . V_1223 = 1 ;
V_211 -> V_340 . V_41 = V_1232 ;
V_211 -> V_340 . V_1226 = ( V_23 -> V_37 & V_99 ) ? 1 : 0 ;
F_60 ( & V_23 -> V_109 ) ;
F_324 ( L_452 ,
V_211 -> V_340 . V_1226 ? L_96 : L_97 , V_211 -> V_340 . V_25 ) ;
return 0 ;
}
static int F_431 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_211 -> V_356 . V_1226 || ! V_211 -> V_356 . V_1223 )
V_23 -> V_163 -> V_1235 = V_1236 ;
else {
if ( V_211 -> V_356 . V_25 < V_1196 ||
V_211 -> V_356 . V_25 > V_1198 ) {
F_60 ( & V_23 -> V_109 ) ;
return - V_75 ;
}
V_23 -> V_163 -> V_1235 = V_211 -> V_356 . V_25 & ~ 0x1 ;
}
F_182 ( V_23 , V_211 -> V_356 . V_25 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_324 ( L_453 , V_211 -> V_356 . V_25 ) ;
return 0 ;
}
static int F_432 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_356 . V_25 = V_23 -> V_163 -> V_1235 ;
V_211 -> V_356 . V_1223 = 0 ;
V_211 -> V_356 . V_1226 = ( V_211 -> V_356 . V_25 == V_1236 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_324 ( L_454 , V_211 -> V_356 . V_25 ) ;
return 0 ;
}
static int F_433 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
if ( V_211 -> V_514 . V_41 & V_1237 || V_211 -> V_514 . V_1226 )
return - V_75 ;
if ( ! ( V_211 -> V_514 . V_41 & V_1238 ) )
return 0 ;
if ( V_211 -> V_514 . V_25 < 0 || V_211 -> V_514 . V_25 >= 255 )
return - V_75 ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_211 -> V_514 . V_41 & V_1239 )
V_23 -> V_369 = ( T_2 ) V_211 -> V_514 . V_25 ;
else if ( V_211 -> V_514 . V_41 & V_1240 )
V_23 -> V_370 = ( T_2 ) V_211 -> V_514 . V_25 ;
else {
V_23 -> V_369 = ( T_2 ) V_211 -> V_514 . V_25 ;
V_23 -> V_370 = ( T_2 ) V_211 -> V_514 . V_25 ;
}
F_184 ( V_23 , V_23 -> V_369 ,
V_23 -> V_370 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_324 ( L_455 ,
V_23 -> V_369 , V_23 -> V_370 ) ;
return 0 ;
}
static int F_434 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_514 . V_1226 = 0 ;
if ( ( V_211 -> V_514 . V_41 & V_1241 ) == V_1237 ) {
F_60 ( & V_23 -> V_109 ) ;
return - V_75 ;
}
if ( V_211 -> V_514 . V_41 & V_1240 ) {
V_211 -> V_514 . V_41 = V_1238 | V_1240 ;
V_211 -> V_514 . V_25 = V_23 -> V_370 ;
} else if ( V_211 -> V_514 . V_41 & V_1239 ) {
V_211 -> V_514 . V_41 = V_1238 | V_1239 ;
V_211 -> V_514 . V_25 = V_23 -> V_369 ;
} else {
V_211 -> V_514 . V_41 = V_1238 ;
V_211 -> V_514 . V_25 = V_23 -> V_369 ;
}
F_60 ( & V_23 -> V_109 ) ;
F_324 ( L_456 , V_211 -> V_514 . V_25 ) ;
return 0 ;
}
static int F_435 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
struct V_1242 * V_1243 = (struct V_1242 * ) V_900 ;
struct V_1244 * V_107 = NULL ;
F_59 ( & V_23 -> V_109 ) ;
V_23 -> V_655 = 1 ;
if ( V_211 -> V_3 . V_412 == sizeof( struct V_1242 ) ) {
if ( V_211 -> V_3 . V_41 & V_1245 ) {
int V_4 = F_3 ( ( int ) V_1243 -> V_664 ,
( int ) sizeof( V_23 -> V_879 ) ) ;
memcpy ( V_23 -> V_879 , V_1243 -> V_663 , V_4 ) ;
V_23 -> V_870 = V_4 ;
V_107 = & V_23 -> V_187 ;
} else if ( V_1243 -> V_696 == V_872 ) {
V_107 = & V_23 -> V_188 ;
}
} else {
V_107 = & V_23 -> V_186 ;
}
F_60 ( & V_23 -> V_109 ) ;
F_324 ( L_457 ) ;
F_56 ( V_107 , 0 ) ;
return 0 ;
}
static int F_436 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
return F_437 ( V_23 -> V_163 , V_899 , V_211 , V_900 ) ;
}
static int F_438 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_826 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
int V_429 ;
T_3 V_1246 = V_23 -> V_314 ;
F_59 ( & V_23 -> V_109 ) ;
V_429 = F_439 ( V_23 -> V_163 , V_899 , V_211 , V_826 ) ;
if ( V_1246 != V_23 -> V_314 &&
V_23 -> V_163 -> V_510 == V_511 &&
V_23 -> V_37 & V_103 )
F_263 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_429 ;
}
static int F_440 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_826 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
return F_441 ( V_23 -> V_163 , V_899 , V_211 , V_826 ) ;
}
static int F_442 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
int V_554 ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_211 -> V_340 . V_1226 ) {
V_23 -> V_1177 = F_443 ( V_23 -> V_1177 ) ;
V_554 = F_183 ( V_23 , V_363 ) ;
if ( V_554 ) {
F_324 ( L_458 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_554 ;
}
F_324 ( L_459 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
switch ( V_211 -> V_340 . V_41 & V_1247 ) {
case V_1248 :
case V_1247 :
case V_1249 :
break;
default:
F_324 ( L_460 ,
V_211 -> V_340 . V_41 ) ;
F_60 ( & V_23 -> V_109 ) ;
return - V_894 ;
}
if ( F_443 ( V_23 -> V_1177 ) == V_362 )
V_23 -> V_1177 = V_1250 | V_360 ;
else
V_23 -> V_1177 = V_1250 | V_23 -> V_1177 ;
V_554 = F_183 ( V_23 , F_443 ( V_23 -> V_1177 ) ) ;
if ( V_554 ) {
F_324 ( L_458 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_554 ;
}
F_324 ( L_461 , V_23 -> V_1177 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_444 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( ! ( V_23 -> V_1177 & V_1250 ) )
V_211 -> V_340 . V_1226 = 1 ;
else
V_211 -> V_340 . V_1226 = 0 ;
F_60 ( & V_23 -> V_109 ) ;
F_324 ( L_462 , V_23 -> V_1177 ) ;
return 0 ;
}
static int F_445 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
int V_118 = * ( int * ) V_900 ;
int V_554 ;
F_59 ( & V_23 -> V_109 ) ;
if ( ( V_118 < 1 ) || ( V_118 > V_1251 ) )
V_118 = V_362 ;
if ( F_443 ( V_23 -> V_1177 ) != V_118 ) {
V_554 = F_183 ( V_23 , V_118 ) ;
if ( V_554 ) {
F_324 ( L_458 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_554 ;
}
V_23 -> V_1177 = V_1250 | V_118 ;
}
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_446 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
int V_11 = F_443 ( V_23 -> V_1177 ) ;
char * V_134 = V_900 ;
V_134 += snprintf ( V_134 , V_1252 , L_463 , V_11 ) ;
switch ( V_11 ) {
case V_362 :
V_134 += snprintf ( V_134 , V_1252 - ( V_134 - V_900 ) , L_464 ) ;
break;
case V_360 :
V_134 += snprintf ( V_134 , V_1252 - ( V_134 - V_900 ) , L_465 ) ;
break;
default:
V_134 += snprintf ( V_134 , V_1252 - ( V_134 - V_900 ) ,
L_466 ,
V_1253 [ V_11 - 1 ] / 1000 ,
V_1254 [ V_11 - 1 ] / 1000 ) ;
}
if ( ! ( V_23 -> V_1177 & V_1250 ) )
V_134 += snprintf ( V_134 , V_1252 - ( V_134 - V_900 ) , L_467 ) ;
V_211 -> V_3 . V_412 = V_134 - V_900 + 1 ;
return 0 ;
}
static int F_447 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
int V_118 = * ( int * ) V_900 ;
T_2 V_878 = 0 , V_800 = 0 ;
if ( V_118 == 0 || V_118 & ~ V_1255 ) {
F_93 ( L_468 , V_118 ) ;
return - V_75 ;
}
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_313 == V_1169 ) {
V_23 -> V_163 -> V_350 = 1 ;
if ( V_118 & V_119 ) {
V_878 |= V_816 ;
V_800 |= V_803 ;
} else
V_23 -> V_163 -> V_350 = 0 ;
} else {
if ( V_118 & V_119 ) {
F_93 ( L_469
L_470 ) ;
F_60 ( & V_23 -> V_109 ) ;
return - V_75 ;
}
V_23 -> V_163 -> V_350 = 0 ;
}
if ( V_118 & V_605 ) {
V_878 |= V_817 ;
V_800 |= V_1168 ;
} else
V_23 -> V_163 -> V_350 = 0 ;
if ( V_118 & V_121 ) {
V_878 |= V_817 ;
V_800 |= V_803 ;
} else
V_23 -> V_163 -> V_350 = 0 ;
V_23 -> V_163 -> V_118 = V_118 ;
V_23 -> V_163 -> V_857 = V_878 ;
V_23 -> V_163 -> V_800 = V_800 ;
F_448 ( V_23 , & V_23 -> V_333 ) ;
F_262 ( L_471 ) ;
if ( ! F_263 ( V_23 ) ) {
F_174 ( V_23 , & V_23 -> V_333 ) ;
V_329 ( V_23 ) ;
}
F_67 ( V_23 ) ;
F_324 ( L_472 ,
V_118 & V_119 ? 'a' : '.' ,
V_118 & V_605 ? 'b' : '.' , V_118 & V_121 ? 'g' : '.' ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_449 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
switch ( V_23 -> V_163 -> V_118 ) {
case V_119 :
strncpy ( V_900 , L_473 , V_1252 ) ;
break;
case V_605 :
strncpy ( V_900 , L_474 , V_1252 ) ;
break;
case V_119 | V_605 :
strncpy ( V_900 , L_475 , V_1252 ) ;
break;
case V_121 :
strncpy ( V_900 , L_476 , V_1252 ) ;
break;
case V_119 | V_121 :
strncpy ( V_900 , L_477 , V_1252 ) ;
break;
case V_605 | V_121 :
strncpy ( V_900 , L_478 , V_1252 ) ;
break;
case V_119 | V_605 | V_121 :
strncpy ( V_900 , L_479 , V_1252 ) ;
break;
default:
strncpy ( V_900 , L_480 , V_1252 ) ;
break;
}
F_324 ( L_481 , V_900 ) ;
V_211 -> V_3 . V_412 = strlen ( V_900 ) + 1 ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_450 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
int V_118 = * ( int * ) V_900 ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_118 == 1 ) {
if ( ! ( V_23 -> V_59 & V_818 ) ) {
V_23 -> V_59 |= V_818 ;
F_262
( L_482 ) ;
if ( ! F_263 ( V_23 ) )
V_329 ( V_23 ) ;
}
goto V_762;
}
if ( V_118 == 0 ) {
V_23 -> V_59 &= ~ V_818 ;
goto V_762;
}
F_60 ( & V_23 -> V_109 ) ;
return - V_75 ;
V_762:
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_451 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_59 & V_818 )
snprintf ( V_211 -> V_158 , V_1256 , L_483 ) ;
else
snprintf ( V_211 -> V_158 , V_1256 , L_484 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_452 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
int * V_1257 = ( int * ) V_900 ;
int V_996 = ( V_1257 [ 0 ] > 0 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_324 ( L_485 , V_996 , V_1257 [ 1 ] ) ;
if ( V_996 ) {
if ( V_23 -> V_163 -> V_510 != V_512 ) {
#ifdef F_406
V_23 -> V_167 -> type = V_1165 ;
#else
V_23 -> V_167 -> type = V_1166 ;
#endif
F_128 ( & V_23 -> V_246 ) ;
}
F_409 ( V_23 , V_1257 [ 1 ] ) ;
} else {
if ( V_23 -> V_163 -> V_510 != V_512 ) {
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
V_23 -> V_167 -> type = V_214 ;
F_128 ( & V_23 -> V_246 ) ;
}
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_453 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
F_324 ( L_486 ) ;
F_128 ( & V_23 -> V_246 ) ;
return 0 ;
}
static int F_454 ( struct V_165 * V_166 ,
struct V_898 * V_899 ,
union V_210 * V_211 , char * V_900 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
union V_210 V_1258 = {
. V_1259 = {
. V_41 = V_1260 ,
} ,
} ;
int V_429 ;
F_324 ( L_487 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_429 = F_408 ( V_23 , 2 ) ;
if ( ! V_429 ) {
F_238 () ;
F_159 ( V_23 ) ;
}
F_126 ( V_23 , V_23 -> V_37 & V_184 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_439 ( V_23 -> V_163 , V_899 , & V_1258 , NULL ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( ! ( V_23 -> V_37 & V_99 ) ) {
F_262 ( L_488
L_489 ) ;
if ( ! F_263 ( V_23 ) )
V_329 ( V_23 ) ;
}
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static struct V_1261 * F_455 ( struct V_165 * V_166 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
struct V_1261 * V_1063 ;
V_1063 = & V_23 -> V_1063 ;
if ( ! ( V_23 -> V_37 & V_103 ) ) {
V_1063 -> V_1262 . V_1263 = 0 ;
V_1063 -> V_1064 . V_509 = 0 ;
V_1063 -> V_1188 . V_1188 = 0 ;
V_1063 -> V_1188 . V_11 = 0 ;
V_1063 -> V_1188 . V_733 = 0 ;
V_1063 -> V_1188 . V_1189 = 7 ;
V_1063 -> V_1188 . V_1189 |= V_1264 |
V_1265 | V_1266 ;
return V_1063 ;
}
V_1063 -> V_1188 . V_1188 = V_23 -> V_576 ;
V_1063 -> V_1188 . V_11 = V_23 -> V_578 ;
V_1063 -> V_1188 . V_733 = V_23 -> V_579 ;
V_1063 -> V_1188 . V_1189 = V_1267 | V_1268 |
V_1269 | V_1270 ;
V_1063 -> V_1262 . V_1263 = F_272 ( & V_23 -> V_577 ) ;
V_1063 -> V_1064 . V_509 = V_23 -> V_584 ;
V_1063 -> V_1064 . V_1271 = V_23 -> V_163 -> V_1272 . V_1273 ;
return V_1063 ;
}
static void F_456 ( struct V_1274 * V_307 )
{
memset ( V_307 , 0 , sizeof( struct V_1274 ) ) ;
V_307 -> V_1275 = 0 ;
V_307 -> V_1041 = 0 ;
V_307 -> V_562 = 0 ;
V_307 -> V_563 = 1 ;
V_307 -> V_1276 = 0 ;
V_307 -> V_841 = 1 ;
V_307 -> V_1277 = 0 ;
V_307 -> V_846 = 1 ;
if ( V_1278 < V_1279 || V_1278 > V_1280 )
V_1278 = V_1279 ;
V_307 -> V_1281 = V_1278 ;
V_307 -> V_1282 = 0 ;
V_307 -> V_1040 = 0 ;
V_307 -> V_1283 = 0 ;
V_307 -> V_1284 = 0 ;
V_307 -> V_1285 = 1 ;
V_307 -> V_1286 = 0x1e ;
}
static int F_457 ( struct V_165 * V_166 )
{
F_74 ( L_490 ) ;
F_458 ( V_166 ) ;
return 0 ;
}
static int F_459 ( struct V_165 * V_166 )
{
F_74 ( L_491 ) ;
F_460 ( V_166 ) ;
return 0 ;
}
static int F_461 ( struct V_17 * V_23 , struct V_1287 * V_529 ,
int V_1288 )
{
struct V_1289 * V_1051 = (struct V_1289 * )
V_529 -> V_1290 [ 0 ] -> V_3 ;
int V_7 = 0 ;
struct V_531 * V_764 ;
#ifdef F_290
int V_1291 = F_361 ( V_23 , V_1288 ) ;
struct V_528 * V_230 = & V_23 -> V_230 [ V_1291 ] ;
#else
struct V_528 * V_230 = & V_23 -> V_230 [ 0 ] ;
#endif
struct V_520 * V_518 = & V_230 -> V_518 ;
T_2 V_1292 , V_1293 , V_1004 ;
int V_1052 ;
if ( ! ( V_23 -> V_37 & V_103 ) )
goto V_1132;
V_1293 = F_390 ( F_219 ( V_1051 -> V_1133 ) ) ;
switch ( V_23 -> V_163 -> V_510 ) {
case V_511 :
V_1004 = ! F_363 ( V_1051 -> V_1067 ) ;
V_1292 = F_260 ( V_23 , V_1051 -> V_1067 ) ;
if ( V_1292 == V_549 ) {
V_1292 = F_259 ( V_23 , V_1051 -> V_1067 ) ;
if ( V_1292 == V_549 ) {
F_93 ( L_492
L_493 ,
V_1051 -> V_1067 ) ;
goto V_1132;
}
}
break;
case V_513 :
default:
V_1004 = ! F_363 ( V_1051 -> V_1116 ) ;
V_1292 = 0 ;
break;
}
V_764 = & V_230 -> V_530 [ V_518 -> V_522 ] ;
V_230 -> V_529 [ V_518 -> V_522 ] = V_529 ;
memset ( V_764 , 0 , sizeof( * V_764 ) ) ;
V_764 -> V_535 . V_3 . V_1294 = V_1292 ;
V_764 -> V_532 . V_533 = V_1295 ;
V_764 -> V_532 . V_766 = V_767 ;
V_764 -> V_535 . V_3 . V_833 = V_1296 ;
V_764 -> V_535 . V_3 . V_4 = F_172 ( V_529 -> V_1297 ) ;
if ( V_23 -> V_556 . V_344 == V_349 )
V_764 -> V_535 . V_3 . V_1007 |= V_1298 ;
else
V_764 -> V_535 . V_3 . V_1007 |= V_1299 ;
if ( V_23 -> V_556 . V_1027 == V_1028 )
V_764 -> V_535 . V_3 . V_1010 |= V_1028 ;
V_1052 = F_219 ( V_1051 -> V_1133 ) ;
V_1051 -> V_1133 = F_172 ( V_1052 & ~ V_1300 ) ;
memcpy ( & V_764 -> V_535 . V_3 . V_764 . V_1301 . V_1013 , V_1051 , V_1293 ) ;
if ( F_462 ( V_1004 ) )
V_764 -> V_535 . V_3 . V_1010 |= V_1011 ;
if ( V_529 -> V_1302 && ! V_23 -> V_163 -> V_839 ) {
switch ( V_23 -> V_163 -> V_244 . V_11 ) {
case V_840 :
V_764 -> V_535 . V_3 . V_764 . V_1301 . V_1013 . V_1133 |=
F_172 ( V_1054 ) ;
if ( ! V_1004 )
V_764 -> V_535 . V_3 . V_1010 |= V_1011 ;
V_764 -> V_535 . V_3 . V_1010 &= ~ V_1303 ;
V_764 -> V_535 . V_3 . V_1007 |= V_848 ;
V_764 -> V_535 . V_3 . V_836 = 0 ;
V_764 -> V_535 . V_3 . V_836 |= V_1304 ;
break;
case V_843 :
V_764 -> V_535 . V_3 . V_764 . V_1301 . V_1013 . V_1133 |=
F_172 ( V_1054 ) ;
V_764 -> V_535 . V_3 . V_1010 &= ~ V_1303 ;
V_764 -> V_535 . V_3 . V_1007 |= V_852 ;
V_764 -> V_535 . V_3 . V_836 = V_1304 ;
break;
case V_844 :
V_764 -> V_535 . V_3 . V_764 . V_1301 . V_1013 . V_1133 |=
F_172 ( V_1054 ) ;
V_764 -> V_535 . V_3 . V_836 = V_23 -> V_163 -> V_918 . V_919 ;
if ( V_23 -> V_163 -> V_244 . V_838 [ V_23 -> V_163 -> V_918 . V_919 ] <=
40 )
V_764 -> V_535 . V_3 . V_836 |= V_1305 ;
else
V_764 -> V_535 . V_3 . V_836 |= V_1306 ;
break;
case V_845 :
break;
default:
F_4 ( V_1056 L_384 ,
V_23 -> V_163 -> V_244 . V_11 ) ;
break;
}
} else
V_764 -> V_535 . V_3 . V_1010 |= V_1303 ;
#ifdef F_290
if ( V_1052 & V_1307 )
F_364 ( V_23 , V_1288 , & ( V_764 -> V_535 . V_3 ) ) ;
#endif
V_764 -> V_535 . V_3 . V_536 = F_178 ( F_3 ( ( T_2 ) ( V_537 - 2 ) ,
V_529 -> V_1308 ) ) ;
F_463 ( L_494 ,
V_529 -> V_1308 , F_224 ( V_764 -> V_535 . V_3 . V_536 ) ) ;
for ( V_7 = 0 ; V_7 < F_224 ( V_764 -> V_535 . V_3 . V_536 ) ; V_7 ++ ) {
F_463 ( L_495 ,
V_7 , F_224 ( V_764 -> V_535 . V_3 . V_536 ) ,
V_529 -> V_1290 [ V_7 ] -> V_4 - V_1293 ) ;
F_145 ( L_496 ,
V_7 , V_764 -> V_535 . V_3 . V_536 ,
V_529 -> V_1290 [ V_7 ] -> V_4 - V_1293 ) ;
F_2 ( V_1309 , V_529 -> V_1290 [ V_7 ] -> V_3 + V_1293 ,
V_529 -> V_1290 [ V_7 ] -> V_4 - V_1293 ) ;
V_764 -> V_535 . V_3 . V_538 [ V_7 ] =
F_178 ( F_298
( V_23 -> V_474 ,
V_529 -> V_1290 [ V_7 ] -> V_3 + V_1293 ,
V_529 -> V_1290 [ V_7 ] -> V_4 - V_1293 ,
V_539 ) ) ;
V_764 -> V_535 . V_3 . V_475 [ V_7 ] =
F_172 ( V_529 -> V_1290 [ V_7 ] -> V_4 - V_1293 ) ;
}
if ( V_7 != V_529 -> V_1308 ) {
struct V_1002 * V_498 ;
T_4 V_1310 = 0 ;
int V_8 ;
for ( V_8 = V_7 ; V_8 < V_529 -> V_1308 ; V_8 ++ )
V_1310 += V_529 -> V_1290 [ V_8 ] -> V_4 - V_1293 ;
F_4 ( V_1311 L_497 ,
V_1310 ) ;
V_498 = F_297 ( V_1310 , V_139 ) ;
if ( V_498 != NULL ) {
V_764 -> V_535 . V_3 . V_475 [ V_7 ] = F_172 ( V_1310 ) ;
for ( V_8 = V_7 ; V_8 < V_529 -> V_1308 ; V_8 ++ ) {
int V_15 = V_529 -> V_1290 [ V_8 ] -> V_4 - V_1293 ;
F_4 ( V_1311 L_498 ,
V_8 , V_15 ) ;
memcpy ( F_380 ( V_498 , V_15 ) ,
V_529 -> V_1290 [ V_8 ] -> V_3 + V_1293 , V_15 ) ;
}
F_391 ( V_529 -> V_1290 [ V_7 ] ) ;
V_529 -> V_1290 [ V_7 ] = V_498 ;
V_764 -> V_535 . V_3 . V_538 [ V_7 ] =
F_178 ( F_298
( V_23 -> V_474 , V_498 -> V_3 ,
V_1310 ,
V_539 ) ) ;
F_464 ( & V_764 -> V_535 . V_3 . V_536 , 1 ) ;
}
}
V_518 -> V_522 = F_250 ( V_518 -> V_522 , V_518 -> V_523 ) ;
F_35 ( V_23 , V_518 -> V_527 , V_518 -> V_522 ) ;
if ( F_249 ( V_518 ) < V_518 -> V_525 )
F_460 ( V_23 -> V_167 ) ;
return V_1312 ;
V_1132:
F_377 ( L_499 ) ;
F_255 ( V_529 ) ;
return V_1312 ;
}
static int F_465 ( struct V_165 * V_166 , int V_1288 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
#ifdef F_290
int V_1291 = F_361 ( V_23 , V_1288 ) ;
struct V_528 * V_230 = & V_23 -> V_230 [ V_1291 ] ;
#else
struct V_528 * V_230 = & V_23 -> V_230 [ 0 ] ;
#endif
if ( F_249 ( & V_230 -> V_518 ) < V_230 -> V_518 . V_525 )
return 1 ;
return 0 ;
}
static void F_466 ( struct V_17 * V_23 ,
struct V_1287 * V_529 )
{
struct V_669 V_1313 ;
struct V_1050 * V_1051 ;
T_2 V_172 ;
T_4 V_161 = V_23 -> V_159 -> V_161 ;
int V_1105 = 0 ;
if ( V_161 & V_1314 )
return;
memset ( & V_1313 , 0 , sizeof( V_1313 ) ) ;
V_1051 = ( void * ) V_529 -> V_1290 [ 0 ] -> V_3 ;
if ( F_386 ( F_219 ( V_1051 -> V_1053 ) ) ) {
if ( V_161 & V_1107 )
return;
if ( V_161 & V_1108 )
V_1105 = 1 ;
} else if ( F_387 ( F_219 ( V_1051 -> V_1053 ) ) ) {
if ( V_161 & V_1109 )
return;
if ( V_161 & V_1110 )
V_1105 = 1 ;
} else if ( F_388 ( F_219 ( V_1051 -> V_1053 ) ) ) {
if ( V_161 & V_1111 )
return;
if ( V_161 & V_1112 )
V_1105 = 1 ;
}
for( V_172 = 0 ; V_172 < V_529 -> V_1308 ; ++ V_172 ) {
struct V_1002 * V_799 = V_529 -> V_1290 [ V_172 ] ;
struct V_1002 * V_1315 ;
struct V_1316 * V_1076 ;
int V_4 ;
if ( V_1105 ) {
V_1051 = ( void * ) V_799 -> V_3 ;
V_4 = F_390 ( F_219 ( V_1051 -> V_1053 ) ) ;
} else
V_4 = V_799 -> V_4 ;
V_1315 = F_297 ( V_4 + sizeof( * V_1076 ) , V_139 ) ;
if ( ! V_1315 )
continue;
V_1076 = ( void * ) F_380 ( V_1315 , sizeof( * V_1076 ) ) ;
V_1076 -> V_1077 = V_1078 ;
V_1076 -> V_1079 = 0 ;
V_1076 -> V_1081 = 0 ;
V_1076 -> V_1081 |= F_178 ( 1 << V_1085 ) ;
* ( T_8 * ) F_380 ( V_1315 , sizeof( T_4 ) ) = F_172 (
F_384 ( V_23 -> V_197 ) ) ;
if ( V_23 -> V_197 > 14 )
* ( T_8 * ) F_380 ( V_1315 , sizeof( T_4 ) ) =
F_172 ( V_1097 |
V_1098 ) ;
else if ( V_23 -> V_163 -> V_118 == V_605 )
* ( T_8 * ) F_380 ( V_1315 , sizeof( T_4 ) ) =
F_172 ( V_1099 |
V_1100 ) ;
else
* ( T_8 * ) F_380 ( V_1315 , sizeof( T_4 ) ) =
F_172 ( V_1097 |
V_1100 ) ;
V_1076 -> V_1080 = F_172 ( V_1315 -> V_4 ) ;
F_467 ( V_799 , F_380 ( V_1315 , V_4 ) , V_4 ) ;
if ( ! F_382 ( V_23 -> V_159 -> V_163 , V_1315 , & V_1313 ) )
F_391 ( V_1315 ) ;
}
}
static T_12 F_468 ( struct V_1287 * V_529 ,
struct V_165 * V_166 , int V_1288 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
unsigned long V_41 ;
T_12 V_429 ;
F_145 ( L_500 , V_529 -> V_1297 ) ;
F_41 ( & V_23 -> V_98 , V_41 ) ;
#ifdef F_267
if ( V_156 && F_92 ( V_23 -> V_157 ) )
F_466 ( V_23 , V_529 ) ;
#endif
V_429 = F_461 ( V_23 , V_529 , V_1288 ) ;
if ( V_429 == V_1312 )
F_63 ( V_23 ) ;
F_42 ( & V_23 -> V_98 , V_41 ) ;
return V_429 ;
}
static void F_469 ( struct V_165 * V_166 )
{
}
static int F_470 ( struct V_165 * V_166 , void * V_134 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
struct V_1317 * V_32 = V_134 ;
if ( ! F_471 ( V_32 -> V_215 ) )
return - V_1318 ;
F_59 ( & V_23 -> V_109 ) ;
V_23 -> V_59 |= V_1319 ;
memcpy ( V_23 -> V_540 , V_32 -> V_215 , V_217 ) ;
F_4 ( V_1311 L_144 ,
V_23 -> V_167 -> V_158 , V_23 -> V_540 ) ;
F_128 ( & V_23 -> V_246 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static void F_472 ( struct V_165 * V_166 ,
struct V_1320 * V_899 )
{
struct V_17 * V_134 = F_339 ( V_166 ) ;
char V_1321 [ 64 ] ;
char V_1322 [ 32 ] ;
T_3 V_4 ;
strcpy ( V_899 -> V_1323 , V_1324 ) ;
strcpy ( V_899 -> V_980 , V_1325 ) ;
V_4 = sizeof( V_1321 ) ;
F_48 ( V_134 , V_1326 , V_1321 , & V_4 ) ;
V_4 = sizeof( V_1322 ) ;
F_48 ( V_134 , V_1327 , V_1322 , & V_4 ) ;
snprintf ( V_899 -> V_1328 , sizeof( V_899 -> V_1328 ) , L_501 ,
V_1321 , V_1322 ) ;
strcpy ( V_899 -> V_1329 , F_473 ( V_134 -> V_474 ) ) ;
V_899 -> V_1330 = V_383 ;
}
static T_3 F_474 ( struct V_165 * V_166 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
return ( V_23 -> V_37 & V_103 ) != 0 ;
}
static int F_475 ( struct V_165 * V_166 )
{
return V_383 ;
}
static int F_476 ( struct V_165 * V_166 ,
struct V_1331 * V_123 , T_2 * V_1332 )
{
struct V_17 * V_134 = F_339 ( V_166 ) ;
if ( V_123 -> V_465 + V_123 -> V_4 > V_383 )
return - V_75 ;
F_59 ( & V_134 -> V_109 ) ;
memcpy ( V_1332 , & V_134 -> V_123 [ V_123 -> V_465 ] , V_123 -> V_4 ) ;
F_60 ( & V_134 -> V_109 ) ;
return 0 ;
}
static int F_477 ( struct V_165 * V_166 ,
struct V_1331 * V_123 , T_2 * V_1332 )
{
struct V_17 * V_134 = F_339 ( V_166 ) ;
int V_7 ;
if ( V_123 -> V_465 + V_123 -> V_4 > V_383 )
return - V_75 ;
F_59 ( & V_134 -> V_109 ) ;
memcpy ( & V_134 -> V_123 [ V_123 -> V_465 ] , V_1332 , V_123 -> V_4 ) ;
for ( V_7 = 0 ; V_7 < V_383 ; V_7 ++ )
F_195 ( V_134 , V_7 + V_384 , V_134 -> V_123 [ V_7 ] ) ;
F_60 ( & V_134 -> V_109 ) ;
return 0 ;
}
static T_13 F_478 ( int V_1333 , void * V_3 )
{
struct V_17 * V_23 = V_3 ;
T_3 V_219 , V_220 ;
if ( ! V_23 )
return V_1334 ;
F_479 ( & V_23 -> V_42 ) ;
if ( ! ( V_23 -> V_37 & V_38 ) ) {
goto V_1335;
}
V_219 = F_36 ( V_23 , V_222 ) ;
V_220 = F_36 ( V_23 , V_39 ) ;
if ( V_219 == 0xFFFFFFFF ) {
F_93 ( L_502 ) ;
goto V_1335;
}
if ( ! ( V_219 & ( V_40 & V_220 ) ) ) {
goto V_1335;
}
F_39 ( V_23 ) ;
V_219 &= ( V_40 & V_220 ) ;
F_35 ( V_23 , V_222 , V_219 ) ;
V_23 -> V_223 = V_219 ;
F_480 ( & V_23 -> V_1336 ) ;
F_481 ( & V_23 -> V_42 ) ;
return V_1337 ;
V_1335:
F_481 ( & V_23 -> V_42 ) ;
return V_1334 ;
}
static void F_482 ( void * V_313 )
{
struct V_17 * V_23 = V_313 ;
unsigned long V_41 ;
F_41 ( & V_23 -> V_98 , V_41 ) ;
if ( F_123 ( V_23 ) ) {
F_127 ( L_503 ) ;
F_56 ( & V_23 -> V_191 , 2 * V_192 ) ;
goto V_1338;
}
if ( ! ( V_23 -> V_37 & V_99 ) ) {
F_127 ( L_504
L_505 ) ;
F_128 ( & V_23 -> V_246 ) ;
} else
F_127 ( L_506
L_507 ) ;
V_1338:
F_42 ( & V_23 -> V_98 , V_41 ) ;
}
static void F_483 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_191 . V_107 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_482 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_484 ( struct V_17 * V_23 )
{
V_23 -> V_1128 = - 1 ;
V_23 -> V_1129 = - 1 ;
V_23 -> V_1130 = 0 ;
F_485 ( V_23 -> V_167 ) ;
F_64 ( & V_23 -> V_186 ) ;
F_64 ( & V_23 -> V_187 ) ;
F_64 ( & V_23 -> V_188 ) ;
F_64 ( & V_23 -> V_189 ) ;
F_273 ( V_23 ) ;
V_23 -> V_580 = F_275 ( V_23 ) ;
F_276 ( V_23 ) ;
F_71 ( V_23 ) ;
F_138 ( V_23 ) ;
if ( V_23 -> V_59 & V_704 )
F_56 ( & V_23 -> V_186 , V_192 ) ;
}
static void F_486 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_672 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_484 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_487 ( struct V_17 * V_23 )
{
F_72 ( V_23 ) ;
F_264 ( V_23 -> V_167 ) ;
F_138 ( V_23 ) ;
F_64 ( & V_23 -> V_186 ) ;
F_64 ( & V_23 -> V_187 ) ;
F_64 ( & V_23 -> V_188 ) ;
F_64 ( & V_23 -> V_665 ) ;
F_64 ( & V_23 -> V_641 ) ;
F_273 ( V_23 ) ;
if ( ! ( V_23 -> V_37 & V_697 ) ) {
F_56 ( & V_23 -> V_186 , 0 ) ;
} else
F_64 ( & V_23 -> V_189 ) ;
}
static void F_488 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_241 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_487 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int T_14 F_489 ( struct V_17 * V_23 )
{
int V_429 = 0 ;
F_490 ( & V_23 -> V_228 ) ;
F_490 ( & V_23 -> V_483 ) ;
F_491 ( & V_23 -> V_665 , F_321 ) ;
F_492 ( & V_23 -> V_330 , F_372 ) ;
F_492 ( & V_23 -> V_555 , F_265 ) ;
F_492 ( & V_23 -> V_561 , F_266 ) ;
F_492 ( & V_23 -> V_776 , F_299 ) ;
F_492 ( & V_23 -> V_246 , F_163 ) ;
F_491 ( & V_23 -> V_191 , F_483 ) ;
F_492 ( & V_23 -> V_193 , V_1339 ) ;
F_492 ( & V_23 -> V_190 , V_1340 ) ;
F_491 ( & V_23 -> V_186 , F_331 ) ;
F_491 ( & V_23 -> V_187 , F_332 ) ;
F_491 ( & V_23 -> V_188 , F_330 ) ;
F_491 ( & V_23 -> V_189 , F_283 ) ;
F_491 ( & V_23 -> V_641 , F_279 ) ;
F_492 ( & V_23 -> V_650 , F_333 ) ;
F_492 ( & V_23 -> V_702 , F_371 ) ;
F_491 ( & V_23 -> V_319 , F_168 ) ;
F_492 ( & V_23 -> V_672 , F_486 ) ;
F_492 ( & V_23 -> V_241 , F_488 ) ;
F_491 ( & V_23 -> V_108 , F_57 ) ;
F_491 ( & V_23 -> V_104 , F_62 ) ;
F_491 ( & V_23 -> V_114 , F_66 ) ;
F_492 ( & V_23 -> V_812 , F_310 ) ;
#ifdef F_290
F_492 ( & V_23 -> V_958 , F_365 ) ;
#endif
F_493 ( & V_23 -> V_1336 , ( void (*) ( unsigned long ) )
F_140 , ( unsigned long ) V_23 ) ;
return V_429 ;
}
static void F_494 ( struct V_165 * V_166 ,
struct V_883 * V_244 )
{
struct V_17 * V_23 = F_339 ( V_166 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
if ( V_244 -> V_41 & ( 1 << V_7 ) ) {
V_23 -> V_163 -> V_244 . V_1341 [ V_7 ] = V_244 -> V_1341 [ V_7 ] ;
V_23 -> V_163 -> V_244 . V_838 [ V_7 ] = V_244 -> V_838 [ V_7 ] ;
if ( V_244 -> V_838 [ V_7 ] == 0 )
V_23 -> V_163 -> V_244 . V_41 &= ~ ( 1 << V_7 ) ;
else {
memcpy ( V_23 -> V_163 -> V_244 . V_828 [ V_7 ] , V_244 -> V_828 [ V_7 ] ,
V_244 -> V_838 [ V_7 ] ) ;
V_23 -> V_163 -> V_244 . V_41 |= ( 1 << V_7 ) ;
}
V_23 -> V_37 |= V_1043 ;
} else if ( V_244 -> V_11 != V_844 )
V_23 -> V_163 -> V_244 . V_41 &= ~ ( 1 << V_7 ) ;
}
if ( V_244 -> V_41 & V_847 ) {
if ( V_244 -> V_849 <= 3 ) {
V_23 -> V_163 -> V_244 . V_849 = V_244 -> V_849 ;
V_23 -> V_163 -> V_244 . V_41 |= V_847 ;
} else
V_23 -> V_163 -> V_244 . V_41 &= ~ V_847 ;
V_23 -> V_37 |= V_1043 ;
} else
V_23 -> V_163 -> V_244 . V_41 &= ~ V_847 ;
if ( ( V_244 -> V_41 & V_884 ) &&
( V_23 -> V_163 -> V_244 . V_886 != V_244 -> V_886 ) ) {
V_23 -> V_163 -> V_244 . V_886 = V_244 -> V_886 ;
V_23 -> V_163 -> V_244 . V_41 |= V_884 ;
if ( V_244 -> V_886 == V_887 )
V_23 -> V_314 |= V_1032 ;
else
V_23 -> V_314 &= ~ V_1032 ;
V_23 -> V_37 |= V_1043 ;
}
if ( V_244 -> V_41 & V_925 && V_23 -> V_163 -> V_244 . V_926 != V_244 -> V_926 ) {
V_23 -> V_163 -> V_244 . V_41 |= V_925 ;
V_23 -> V_163 -> V_244 . V_926 = V_244 -> V_926 ;
V_23 -> V_37 |= V_1043 ;
if ( V_244 -> V_926 )
V_23 -> V_314 |= V_810 ;
else
V_23 -> V_314 &= ~ V_810 ;
}
if ( V_244 -> V_41 & V_1342 )
V_23 -> V_163 -> V_244 . V_245 = V_244 -> V_245 ;
if ( V_244 -> V_41 & V_928 && V_23 -> V_163 -> V_244 . V_11 != V_244 -> V_11 ) {
V_23 -> V_163 -> V_244 . V_11 = V_244 -> V_11 ;
V_23 -> V_163 -> V_244 . V_41 |= V_928 ;
V_23 -> V_37 |= V_1043 ;
}
if ( ! V_23 -> V_163 -> V_839 && ( V_244 -> V_41 & V_1342 ) )
F_319 ( V_23 ) ;
#if 0
if ((priv->status & (STATUS_ASSOCIATED | STATUS_ASSOCIATING)) &&
(((priv->assoc_request.capability &
cpu_to_le16(WLAN_CAPABILITY_PRIVACY)) && !sec->enabled) ||
(!(priv->assoc_request.capability &
cpu_to_le16(WLAN_CAPABILITY_PRIVACY)) && sec->enabled))) {
IPW_DEBUG_ASSOC("Disassociating due to capability "
"change.\n");
ipw_disassociate(priv);
}
#endif
}
static int F_448 ( struct V_17 * V_23 ,
struct V_332 * V_333 )
{
memset ( V_333 , 0 , sizeof( * V_333 ) ) ;
switch ( V_23 -> V_163 -> V_857 ) {
case V_816 :
V_333 -> V_344 = V_351 ;
V_333 -> V_1038 = V_1343 ;
F_305 ( V_333 , V_1168 ,
V_1344 ) ;
break;
default:
V_333 -> V_344 = V_345 ;
V_333 -> V_1038 = V_1343 ;
F_304 ( V_333 , V_1168 ,
V_1345 ) ;
if ( V_23 -> V_163 -> V_800 & V_803 ) {
F_305 ( V_333 , V_1168 ,
V_1344 ) ;
}
break;
}
return 0 ;
}
static int F_495 ( struct V_17 * V_23 )
{
if ( F_180 ( V_23 ) )
goto error;
if ( F_158 ( V_23 , V_23 -> V_167 -> V_1115 ) )
goto error;
F_456 ( & V_23 -> V_307 ) ;
if ( V_1346 ) {
unsigned char V_1347 = V_23 -> V_123 [ V_1348 ] ;
if ( V_1347 & V_1349 )
V_23 -> V_307 . V_1275
|= V_1350 ;
if ( V_1347 & V_1351 )
V_23 -> V_307 . V_1275
|= V_1352 ;
}
#ifdef F_267
if ( V_23 -> V_157 && F_92 ( V_23 -> V_157 ) ) {
V_23 -> V_307 . V_562 = 1 ;
V_23 -> V_307 . V_563 = 1 ;
V_23 -> V_307 . V_564 = 1 ;
V_23 -> V_307 . V_565 = 1 ;
}
#endif
if ( V_23 -> V_163 -> V_510 == V_511 )
V_23 -> V_307 . V_1041 = 1 ;
else
V_23 -> V_307 . V_1041 = 0 ;
if ( F_156 ( V_23 ) )
goto error;
F_448 ( V_23 , & V_23 -> V_333 ) ;
if ( F_174 ( V_23 , & V_23 -> V_333 ) )
goto error;
if ( V_23 -> V_354 ) {
if ( F_181 ( V_23 , V_23 -> V_354 ) )
goto error;
}
#ifdef F_290
F_292 ( L_508 ) ;
F_352 ( V_23 , NULL ) ;
#endif
if ( F_175 ( V_23 ) )
goto error;
if ( F_155 ( V_23 ) )
goto error;
V_23 -> V_37 |= V_69 ;
F_73 ( V_23 ) ;
F_69 ( V_23 ) ;
V_23 -> V_643 = 0 ;
if ( ( V_23 -> V_314 & V_810 ) &&
( V_23 -> V_163 -> V_244 . V_11 == V_844 ) &&
! ( V_23 -> V_163 -> V_839 || V_23 -> V_163 -> V_842 ) )
F_319 ( V_23 ) ;
return 0 ;
error:
return - V_303 ;
}
static int F_162 ( struct V_17 * V_23 )
{
int V_155 , V_7 , V_8 ;
if ( V_23 -> V_1353 ) {
F_496 ( V_23 -> V_163 , V_23 -> V_1353 ) ;
V_23 -> V_1353 = 0 ;
}
if ( V_23 -> V_37 & V_697 )
return - V_303 ;
if ( V_149 && ! V_23 -> V_149 ) {
V_23 -> V_149 = F_497 ( V_149 , sizeof( * V_23 -> V_149 ) ,
V_148 ) ;
if ( V_23 -> V_149 == NULL ) {
F_46 ( L_509 ,
V_149 ) ;
return - V_473 ;
} else {
V_23 -> V_151 = V_149 ;
}
}
for ( V_7 = 0 ; V_7 < V_1354 ; V_7 ++ ) {
V_155 = F_240 ( V_23 ) ;
if ( V_155 ) {
F_46 ( L_196 , V_155 ) ;
return V_155 ;
}
F_52 ( V_23 ) ;
if ( ! ( V_23 -> V_59 & V_1319 ) )
F_192 ( V_23 , V_23 -> V_540 ) ;
memcpy ( V_23 -> V_167 -> V_1115 , V_23 -> V_540 , V_217 ) ;
memcpy ( V_23 -> V_167 -> V_1355 , V_23 -> V_540 , V_217 ) ;
for ( V_8 = 0 ; V_8 < F_220 ( V_1356 ) ; V_8 ++ ) {
if ( ! memcmp ( & V_23 -> V_123 [ V_1357 ] ,
V_1356 [ V_8 ] . V_158 , 3 ) )
break;
}
if ( V_8 == F_220 ( V_1356 ) ) {
F_93 ( L_510 ,
V_23 -> V_123 [ V_1357 + 0 ] ,
V_23 -> V_123 [ V_1357 + 1 ] ,
V_23 -> V_123 [ V_1357 + 2 ] ) ;
V_8 = 0 ;
}
if ( F_498 ( V_23 -> V_163 , & V_1356 [ V_8 ] ) ) {
F_93 ( L_511 ) ;
return 0 ;
}
if ( V_23 -> V_37 & V_184 ) {
F_93 ( L_512 ) ;
return 0 ;
} else if ( F_123 ( V_23 ) ) {
F_93 ( L_513
L_514
L_515 ) ;
F_56 ( & V_23 -> V_191 , 2 * V_192 ) ;
return 0 ;
}
V_155 = F_495 ( V_23 ) ;
if ( ! V_155 ) {
F_74 ( L_516 , V_7 ) ;
F_56 ( & V_23 -> V_186 , 0 ) ;
return 0 ;
}
F_74 ( L_517 , V_155 ) ;
F_74 ( L_518 ,
V_7 , V_1354 ) ;
F_160 ( V_23 ) ;
}
F_46 ( L_519 , V_7 ) ;
return - V_303 ;
}
static void V_1339 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_193 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_162 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_499 ( struct V_17 * V_23 )
{
int V_7 ;
if ( V_23 -> V_37 & V_318 ) {
F_74 ( L_520 ) ;
F_167 ( V_23 ) ;
}
if ( V_23 -> V_37 & V_103 ) {
F_74 ( L_521 ) ;
F_263 ( V_23 ) ;
}
F_75 ( V_23 ) ;
for ( V_7 = 1000 ; V_7 && ( V_23 -> V_37 &
( V_557 |
V_103 | V_318 ) ) ; V_7 -- )
F_186 ( 10 ) ;
if ( V_23 -> V_37 & ( V_557 |
V_103 | V_318 ) )
F_74 ( L_522 ) ;
else
F_74 ( L_523 , 1000 - V_7 ) ;
F_177 ( V_23 , 0 ) ;
V_23 -> V_37 &= ~ V_69 ;
}
static void F_160 ( struct V_17 * V_23 )
{
int V_1358 = V_23 -> V_37 & V_697 ;
V_23 -> V_37 |= V_697 ;
if ( F_47 ( V_23 ) )
F_499 ( V_23 ) ;
if ( ! V_1358 )
V_23 -> V_37 &= ~ V_697 ;
F_43 ( V_23 ) ;
V_23 -> V_37 &= V_99 | V_697 ;
F_264 ( V_23 -> V_167 ) ;
F_228 ( V_23 ) ;
F_70 ( V_23 ) ;
}
static void V_1340 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_190 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_160 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int F_500 ( struct V_165 * V_166 )
{
int V_7 , V_155 = 0 ;
struct V_17 * V_23 = F_339 ( V_166 ) ;
const struct V_201 * V_202 = F_137 ( V_23 -> V_163 ) ;
struct V_1359 * V_182 = & V_23 -> V_163 -> V_182 ;
F_59 ( & V_23 -> V_109 ) ;
if ( F_162 ( V_23 ) ) {
V_155 = - V_303 ;
goto V_6;
}
memcpy ( V_182 -> V_183 -> V_1355 , V_23 -> V_540 , V_217 ) ;
if ( V_202 -> V_203 ) {
struct V_1360 * V_1361 = & V_23 -> V_163 -> V_1361 ;
V_1361 -> V_878 = V_1362 ;
V_1361 -> V_1363 = V_202 -> V_203 ;
V_1361 -> V_866 = F_497 ( V_202 -> V_203 ,
sizeof( struct V_1364 ) ,
V_148 ) ;
if ( ! V_1361 -> V_866 ) {
V_155 = - V_473 ;
goto V_6;
}
for ( V_7 = 0 ; V_7 < V_202 -> V_203 ; V_7 ++ ) {
V_1361 -> V_866 [ V_7 ] . V_878 = V_1362 ;
V_1361 -> V_866 [ V_7 ] . V_1365 = V_202 -> V_204 [ V_7 ] . V_1146 ;
V_1361 -> V_866 [ V_7 ] . V_1366 = V_202 -> V_204 [ V_7 ] . V_197 ;
V_1361 -> V_866 [ V_7 ] . V_343 = V_202 -> V_204 [ V_7 ] . V_343 ;
if ( V_202 -> V_204 [ V_7 ] . V_41 & V_207 )
V_1361 -> V_866 [ V_7 ] . V_41 |=
V_1367 ;
if ( V_202 -> V_204 [ V_7 ] . V_41 & V_206 )
V_1361 -> V_866 [ V_7 ] . V_41 |=
V_1368 ;
if ( V_202 -> V_204 [ V_7 ] . V_41 & V_205 )
V_1361 -> V_866 [ V_7 ] . V_41 |=
V_1369 ;
}
V_1361 -> V_1370 = V_1371 ;
V_1361 -> V_1372 = V_1373 ;
V_182 -> V_183 -> V_1374 [ V_1362 ] = V_1361 ;
}
if ( V_202 -> V_209 ) {
struct V_1360 * V_1375 = & V_23 -> V_163 -> V_1375 ;
V_1375 -> V_878 = V_1376 ;
V_1375 -> V_1363 = V_202 -> V_209 ;
V_1375 -> V_866 = F_497 ( V_202 -> V_209 ,
sizeof( struct V_1364 ) ,
V_148 ) ;
if ( ! V_1375 -> V_866 ) {
V_155 = - V_473 ;
goto V_6;
}
for ( V_7 = 0 ; V_7 < V_202 -> V_209 ; V_7 ++ ) {
V_1375 -> V_866 [ V_7 ] . V_878 = V_1362 ;
V_1375 -> V_866 [ V_7 ] . V_1365 = V_202 -> V_18 [ V_7 ] . V_1146 ;
V_1375 -> V_866 [ V_7 ] . V_1366 = V_202 -> V_18 [ V_7 ] . V_197 ;
V_1375 -> V_866 [ V_7 ] . V_343 = V_202 -> V_18 [ V_7 ] . V_343 ;
if ( V_202 -> V_18 [ V_7 ] . V_41 & V_207 )
V_1375 -> V_866 [ V_7 ] . V_41 |=
V_1367 ;
if ( V_202 -> V_18 [ V_7 ] . V_41 & V_206 )
V_1375 -> V_866 [ V_7 ] . V_41 |=
V_1368 ;
if ( V_202 -> V_18 [ V_7 ] . V_41 & V_205 )
V_1375 -> V_866 [ V_7 ] . V_41 |=
V_1369 ;
}
V_1375 -> V_1370 = V_1377 ;
V_1375 -> V_1372 = V_1378 ;
V_182 -> V_183 -> V_1374 [ V_1376 ] = V_1375 ;
}
F_501 ( V_182 -> V_183 , & V_23 -> V_474 -> V_166 ) ;
if ( F_502 ( V_182 -> V_183 ) ) {
V_155 = - V_303 ;
goto V_6;
}
V_6:
F_60 ( & V_23 -> V_109 ) ;
return V_155 ;
}
static int F_503 ( struct V_165 * V_166 )
{
struct V_1379 * V_159 = F_339 ( V_166 ) ;
struct V_17 * V_23 = V_159 -> V_23 ;
F_74 ( L_524 ) ;
F_264 ( V_166 ) ;
if ( V_23 -> V_163 -> V_510 != V_512 ) {
V_23 -> V_307 . V_562 = 1 ;
V_23 -> V_307 . V_563 = 1 ;
V_23 -> V_307 . V_564 = 1 ;
V_23 -> V_307 . V_565 = 1 ;
F_156 ( V_23 ) ;
}
return 0 ;
}
static int F_504 ( struct V_165 * V_166 )
{
struct V_1379 * V_159 = F_339 ( V_166 ) ;
struct V_17 * V_23 = V_159 -> V_23 ;
F_74 ( L_525 ) ;
if ( V_23 -> V_163 -> V_510 != V_512 ) {
V_23 -> V_307 . V_562 = 0 ;
V_23 -> V_307 . V_563 = 0 ;
V_23 -> V_307 . V_564 = 0 ;
V_23 -> V_307 . V_565 = 0 ;
F_156 ( V_23 ) ;
}
return 0 ;
}
static T_12 F_505 ( struct V_1002 * V_498 ,
struct V_165 * V_166 )
{
F_74 ( L_526 ) ;
F_237 ( V_498 ) ;
return V_1312 ;
}
static int F_95 ( struct V_17 * V_23 )
{
int V_155 = 0 ;
if ( V_23 -> V_157 )
return - V_160 ;
V_23 -> V_157 = F_506 ( sizeof( struct V_1379 ) , 1 ) ;
if ( V_23 -> V_157 == NULL )
return - V_473 ;
V_23 -> V_159 = F_339 ( V_23 -> V_157 ) ;
V_23 -> V_159 -> V_163 = F_507 ( V_23 -> V_157 ) ;
V_23 -> V_159 -> V_23 = V_23 ;
strcpy ( V_23 -> V_157 -> V_158 , L_527 ) ;
memcpy ( V_23 -> V_157 -> V_1115 , V_23 -> V_540 , V_217 ) ;
V_23 -> V_157 -> type = V_1165 ;
V_23 -> V_157 -> V_1380 = & V_1381 ;
V_23 -> V_159 -> V_163 -> V_510 = V_512 ;
F_508 ( V_23 -> V_157 , & V_23 -> V_474 -> V_166 ) ;
V_155 = F_509 ( V_23 -> V_157 ) ;
if ( V_155 ) {
F_510 ( V_23 -> V_157 , 1 ) ;
V_23 -> V_157 = NULL ;
return V_155 ;
}
return 0 ;
}
static void F_94 ( struct V_17 * V_23 )
{
if ( ! V_23 -> V_157 )
return;
F_511 ( V_23 -> V_157 ) ;
F_510 ( V_23 -> V_157 , 1 ) ;
V_23 -> V_157 = NULL ;
}
static int T_14 F_512 ( struct V_474 * V_1382 ,
const struct V_1383 * V_1384 )
{
int V_554 = 0 ;
struct V_165 * V_167 ;
void T_15 * V_137 ;
T_3 V_412 , V_21 ;
struct V_17 * V_23 ;
int V_7 ;
V_167 = F_506 ( sizeof( struct V_17 ) , 0 ) ;
if ( V_167 == NULL ) {
V_554 = - V_473 ;
goto V_6;
}
V_23 = F_339 ( V_167 ) ;
V_23 -> V_163 = F_507 ( V_167 ) ;
V_23 -> V_167 = V_167 ;
V_23 -> V_474 = V_1382 ;
V_12 = V_1385 ;
F_300 ( & V_23 -> V_42 ) ;
F_300 ( & V_23 -> V_98 ) ;
for ( V_7 = 0 ; V_7 < V_1124 ; V_7 ++ )
F_235 ( & V_23 -> V_1125 [ V_7 ] ) ;
F_513 ( & V_23 -> V_109 ) ;
if ( F_514 ( V_1382 ) ) {
V_554 = - V_1386 ;
goto V_1387;
}
F_515 ( V_1382 ) ;
V_554 = F_516 ( V_1382 , F_517 ( 32 ) ) ;
if ( ! V_554 )
V_554 = F_518 ( V_1382 , F_517 ( 32 ) ) ;
if ( V_554 ) {
F_4 (KERN_WARNING DRV_NAME L_528 ) ;
goto V_1388;
}
F_519 ( V_1382 , V_23 ) ;
V_554 = F_520 ( V_1382 , V_1324 ) ;
if ( V_554 )
goto V_1388;
F_521 ( V_1382 , 0x40 , & V_21 ) ;
if ( ( V_21 & 0x0000ff00 ) != 0 )
F_522 ( V_1382 , 0x40 , V_21 & 0xffff00ff ) ;
V_412 = F_523 ( V_1382 , 0 ) ;
V_23 -> V_1389 = V_412 ;
V_137 = F_524 ( V_1382 , 0 ) ;
if ( ! V_137 ) {
V_554 = - V_1386 ;
goto V_1390;
}
V_23 -> V_22 = V_137 ;
F_74 ( L_529 , V_412 ) ;
F_74 ( L_530 , V_137 ) ;
V_554 = F_489 ( V_23 ) ;
if ( V_554 ) {
F_46 ( L_531 ) ;
goto V_1391;
}
F_408 ( V_23 , 1 ) ;
V_554 = F_525 ( V_1382 -> V_1333 , F_478 , V_1392 , V_1324 , V_23 ) ;
if ( V_554 ) {
F_46 ( L_532 , V_1382 -> V_1333 ) ;
goto V_1391;
}
F_508 ( V_167 , & V_1382 -> V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_23 -> V_163 -> V_1393 = F_468 ;
V_23 -> V_163 -> V_893 = F_494 ;
V_23 -> V_163 -> V_1394 = F_465 ;
#ifdef F_290
V_23 -> V_163 -> V_1395 = F_362 ;
V_23 -> V_163 -> V_1396 = F_367 ;
V_23 -> V_163 -> V_1397 = F_366 ;
V_23 -> V_163 -> V_1398 = F_368 ;
#endif
V_23 -> V_163 -> V_639 = - 20 ;
V_23 -> V_163 -> V_640 = - 85 ;
V_167 -> V_1380 = & V_1399 ;
V_23 -> V_1400 . V_1401 = & V_23 -> V_163 -> V_1401 ;
V_167 -> V_1400 = & V_23 -> V_1400 ;
V_167 -> V_1402 = & V_1403 ;
V_167 -> V_1404 = & V_1405 ;
V_167 -> V_1333 = V_1382 -> V_1333 ;
V_167 -> V_1406 = ( unsigned long ) V_23 -> V_22 ;
V_167 -> V_1407 = F_526 ( V_1382 , 0 ) ;
V_167 -> V_1408 = V_167 -> V_1407 + F_523 ( V_1382 , 0 ) - 1 ;
V_554 = F_527 ( & V_1382 -> V_166 . V_1409 , & V_1410 ) ;
if ( V_554 ) {
F_46 ( L_533 ) ;
F_60 ( & V_23 -> V_109 ) ;
goto V_1411;
}
F_60 ( & V_23 -> V_109 ) ;
V_554 = F_509 ( V_167 ) ;
if ( V_554 ) {
F_46 ( L_534 ) ;
goto V_1412;
}
#ifdef F_267
if ( V_156 ) {
V_554 = F_95 ( V_23 ) ;
if ( V_554 ) {
F_46 ( L_74
L_75 , V_554 ) ;
F_511 ( V_23 -> V_167 ) ;
goto V_1412;
}
}
#endif
F_4 (KERN_INFO DRV_NAME L_535
L_536 ,
priv->ieee->geo.name, priv->ieee->geo.bg_channels,
priv->ieee->geo.a_channels) ;
return 0 ;
V_1412:
F_528 ( & V_1382 -> V_166 . V_1409 , & V_1410 ) ;
V_1411:
F_529 ( V_1382 -> V_1333 , V_23 ) ;
V_1391:
F_530 ( V_23 -> V_22 ) ;
V_1390:
F_531 ( V_1382 ) ;
V_1388:
F_532 ( V_1382 ) ;
F_519 ( V_1382 , NULL ) ;
V_1387:
F_510 ( V_23 -> V_167 , 0 ) ;
V_6:
return V_554 ;
}
static void T_16 F_533 ( struct V_474 * V_1382 )
{
struct V_17 * V_23 = F_534 ( V_1382 ) ;
struct V_434 * V_134 , * V_518 ;
int V_7 ;
if ( ! V_23 )
return;
F_59 ( & V_23 -> V_109 ) ;
V_23 -> V_37 |= V_697 ;
F_160 ( V_23 ) ;
F_528 ( & V_1382 -> V_166 . V_1409 , & V_1410 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_511 ( V_23 -> V_167 ) ;
if ( V_23 -> V_493 ) {
F_246 ( V_23 , V_23 -> V_493 ) ;
V_23 -> V_493 = NULL ;
}
F_247 ( V_23 ) ;
if ( V_23 -> V_149 ) {
F_87 ( V_23 -> V_149 ) ;
V_23 -> V_149 = NULL ;
}
F_535 ( & V_23 -> V_665 ) ;
F_536 ( & V_23 -> V_330 ) ;
F_536 ( & V_23 -> V_555 ) ;
F_536 ( & V_23 -> V_561 ) ;
F_536 ( & V_23 -> V_776 ) ;
F_536 ( & V_23 -> V_246 ) ;
F_535 ( & V_23 -> V_191 ) ;
F_536 ( & V_23 -> V_193 ) ;
F_536 ( & V_23 -> V_190 ) ;
F_535 ( & V_23 -> V_186 ) ;
F_535 ( & V_23 -> V_187 ) ;
F_535 ( & V_23 -> V_188 ) ;
F_535 ( & V_23 -> V_189 ) ;
F_535 ( & V_23 -> V_641 ) ;
F_536 ( & V_23 -> V_650 ) ;
F_536 ( & V_23 -> V_702 ) ;
F_535 ( & V_23 -> V_319 ) ;
F_536 ( & V_23 -> V_672 ) ;
F_536 ( & V_23 -> V_241 ) ;
F_535 ( & V_23 -> V_108 ) ;
F_535 ( & V_23 -> V_104 ) ;
F_535 ( & V_23 -> V_114 ) ;
F_536 ( & V_23 -> V_812 ) ;
for ( V_7 = 0 ; V_7 < V_1124 ; V_7 ++ ) {
F_209 (p, q, &priv->ibss_mac_hash[i]) {
F_211 ( V_134 ) ;
F_87 ( F_210 ( V_134 , struct V_1123 , V_439 ) ) ;
}
}
F_87 ( V_23 -> error ) ;
V_23 -> error = NULL ;
#ifdef F_267
F_94 ( V_23 ) ;
#endif
F_529 ( V_1382 -> V_1333 , V_23 ) ;
F_530 ( V_23 -> V_22 ) ;
F_531 ( V_1382 ) ;
F_532 ( V_1382 ) ;
F_519 ( V_1382 , NULL ) ;
F_537 ( V_23 -> V_163 -> V_182 . V_183 ) ;
F_87 ( V_23 -> V_163 -> V_1375 . V_866 ) ;
F_87 ( V_23 -> V_163 -> V_1361 . V_866 ) ;
F_510 ( V_23 -> V_167 , 0 ) ;
F_238 () ;
}
static int F_538 ( struct V_474 * V_1382 , T_17 V_661 )
{
struct V_17 * V_23 = F_534 ( V_1382 ) ;
struct V_165 * V_166 = V_23 -> V_167 ;
F_4 ( V_1311 L_537 , V_166 -> V_158 ) ;
F_160 ( V_23 ) ;
F_539 ( V_166 ) ;
F_540 ( V_1382 ) ;
F_532 ( V_1382 ) ;
F_541 ( V_1382 , F_542 ( V_1382 , V_661 ) ) ;
V_23 -> V_1413 = F_543 () ;
return 0 ;
}
static int F_544 ( struct V_474 * V_1382 )
{
struct V_17 * V_23 = F_534 ( V_1382 ) ;
struct V_165 * V_166 = V_23 -> V_167 ;
int V_554 ;
T_3 V_21 ;
F_4 ( V_1311 L_538 , V_166 -> V_158 ) ;
F_541 ( V_1382 , V_1414 ) ;
V_554 = F_514 ( V_1382 ) ;
if ( V_554 ) {
F_4 ( V_1056 L_539 ,
V_166 -> V_158 ) ;
return V_554 ;
}
F_545 ( V_1382 ) ;
F_521 ( V_1382 , 0x40 , & V_21 ) ;
if ( ( V_21 & 0x0000ff00 ) != 0 )
F_522 ( V_1382 , 0x40 , V_21 & 0xffff00ff ) ;
F_546 ( V_166 ) ;
V_23 -> V_1353 = F_543 () - V_23 -> V_1413 ;
F_128 ( & V_23 -> V_193 ) ;
return 0 ;
}
static void F_547 ( struct V_474 * V_1382 )
{
struct V_17 * V_23 = F_534 ( V_1382 ) ;
F_160 ( V_23 ) ;
F_532 ( V_1382 ) ;
}
static int T_18 F_548 ( void )
{
int V_429 ;
F_4 (KERN_INFO DRV_NAME L_540 DRV_DESCRIPTION L_541 DRV_VERSION L_68 ) ;
F_4 (KERN_INFO DRV_NAME L_540 DRV_COPYRIGHT L_68 ) ;
V_429 = F_549 ( & V_1415 ) ;
if ( V_429 ) {
F_46 ( L_542 ) ;
return V_429 ;
}
V_429 = F_550 ( & V_1415 . V_1323 , & V_1416 ) ;
if ( V_429 ) {
F_46 ( L_543 ) ;
F_551 ( & V_1415 ) ;
return V_429 ;
}
return V_429 ;
}
static void T_19 F_552 ( void )
{
F_553 ( & V_1415 . V_1323 , & V_1416 ) ;
F_551 ( & V_1415 ) ;
}
