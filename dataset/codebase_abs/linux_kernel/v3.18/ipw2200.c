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
unsigned long V_299 , V_300 ;
F_41 ( & V_23 -> V_98 , V_41 ) ;
if ( V_23 -> V_37 & V_227 ) {
F_46 ( L_137 ,
F_147 ( V_153 -> V_153 ) ) ;
F_42 ( & V_23 -> V_98 , V_41 ) ;
return - V_301 ;
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
if ( V_153 -> V_153 == V_302 )
F_142 ( L_139 ) ;
else
#endif
F_2 ( V_303 , ( T_2 * ) V_153 -> V_154 , V_153 -> V_4 ) ;
V_155 = F_151 ( V_23 , V_153 -> V_153 , V_153 -> V_154 , V_153 -> V_4 , 0 ) ;
if ( V_155 ) {
V_23 -> V_37 &= ~ V_227 ;
F_46 ( L_140 ,
F_147 ( V_153 -> V_153 ) , V_155 ) ;
F_42 ( & V_23 -> V_98 , V_41 ) ;
goto exit;
}
F_42 ( & V_23 -> V_98 , V_41 ) ;
V_299 = V_140 ;
V_300 = V_299 + V_304 ;
V_305:
V_155 = F_152 ( V_23 -> V_228 ,
! ( V_23 ->
V_37 & V_227 ) ,
V_300 - V_299 ) ;
if ( V_155 < 0 ) {
V_299 = V_140 ;
if ( F_153 ( V_299 , V_300 ) )
goto V_305;
V_155 = 0 ;
}
if ( V_155 == 0 ) {
F_41 ( & V_23 -> V_98 , V_41 ) ;
if ( V_23 -> V_37 & V_227 ) {
F_46 ( L_141 ,
F_147 ( V_153 -> V_153 ) ) ;
V_23 -> V_37 &= ~ V_227 ;
F_42 ( & V_23 -> V_98 , V_41 ) ;
V_155 = - V_306 ;
goto exit;
}
F_42 ( & V_23 -> V_98 , V_41 ) ;
} else
V_155 = 0 ;
if ( V_23 -> V_37 & V_181 ) {
F_46 ( L_142 ,
F_147 ( V_153 -> V_153 ) ) ;
V_155 = - V_306 ;
goto exit;
}
exit:
if ( V_23 -> V_149 ) {
V_23 -> V_149 [ V_23 -> V_150 ++ ] . V_152 = V_155 ;
V_23 -> V_150 %= V_23 -> V_151 ;
}
return V_155 ;
}
static int F_154 ( struct V_17 * V_23 , T_2 V_307 )
{
struct V_298 V_153 = {
. V_153 = V_307 ,
} ;
return F_149 ( V_23 , & V_153 ) ;
}
static int F_155 ( struct V_17 * V_23 , T_2 V_307 , T_2 V_4 ,
void * V_3 )
{
struct V_298 V_153 = {
. V_153 = V_307 ,
. V_4 = V_4 ,
. V_154 = V_3 ,
} ;
return F_149 ( V_23 , & V_153 ) ;
}
static int F_156 ( struct V_17 * V_23 )
{
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_154 ( V_23 , V_308 ) ;
}
static int F_157 ( struct V_17 * V_23 )
{
return F_155 ( V_23 , V_309 ,
sizeof( V_23 -> V_310 ) ,
& V_23 -> V_310 ) ;
}
static int F_158 ( struct V_17 * V_23 , T_2 * V_311 , int V_4 )
{
if ( ! V_23 || ! V_311 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_155 ( V_23 , V_312 , F_3 ( V_4 , V_313 ) ,
V_311 ) ;
}
static int F_159 ( struct V_17 * V_23 , T_2 * V_314 )
{
if ( ! V_23 || ! V_314 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
F_74 ( L_144 ,
V_23 -> V_167 -> V_158 , V_314 ) ;
return F_155 ( V_23 , V_315 , V_217 , V_314 ) ;
}
static void F_160 ( void * V_316 )
{
struct V_17 * V_23 = V_316 ;
if ( V_23 -> V_37 & V_99 )
return;
F_161 ( V_23 ) ;
if ( V_23 -> V_117 &&
( V_23 -> V_117 -> V_317 & V_318 ) )
F_162 ( V_23 ) ;
if ( F_163 ( V_23 ) ) {
F_46 ( L_145 ) ;
return;
}
}
static void F_164 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_246 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_160 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_165 ( void * V_3 )
{
struct V_17 * V_23 = V_3 ;
if ( V_23 -> V_37 & V_319 ) {
F_166 ( L_146
L_147 ,
F_167 ( V_320 ) ) ;
F_128 ( & V_23 -> V_246 ) ;
} else if ( V_23 -> V_37 & V_321 ) {
F_166 ( L_148
L_149 ,
F_167 ( V_320 ) ) ;
F_168 ( V_23 ) ;
F_56 ( & V_23 -> V_322 , V_192 ) ;
}
}
static void F_169 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_322 . V_107 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_165 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int F_170 ( struct V_17 * V_23 ,
struct V_323 * V_324 )
{
return F_155 ( V_23 , V_325 ,
sizeof( * V_324 ) , V_324 ) ;
}
static int F_171 ( struct V_17 * V_23 )
{
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_154 ( V_23 , V_326 ) ;
}
static int F_172 ( struct V_17 * V_23 , T_4 V_327 )
{
struct V_328 V_329 = {
. V_330 = F_173 ( V_327 ) ,
} ;
return F_155 ( V_23 , V_331 , sizeof( V_329 ) ,
& V_329 ) ;
}
static int F_174 ( struct V_17 * V_23 ,
struct V_332 * V_333 )
{
if ( ! V_23 || ! V_333 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_155 ( V_23 , V_334 , sizeof( * V_333 ) ,
V_333 ) ;
}
static int F_175 ( struct V_17 * V_23 ,
struct V_335 * V_336 )
{
if ( ! V_23 || ! V_336 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_155 ( V_23 , V_337 , sizeof( * V_336 ) ,
V_336 ) ;
}
static int F_176 ( struct V_17 * V_23 )
{
T_3 V_21 ;
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
F_177 ( & V_21 , sizeof( V_21 ) ) ;
return F_155 ( V_23 , V_338 , sizeof( V_21 ) , & V_21 ) ;
}
static int F_178 ( struct V_17 * V_23 , T_3 V_339 )
{
T_6 V_340 = F_179 ( V_339 ) ;
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_155 ( V_23 , V_341 , sizeof( V_340 ) , & V_340 ) ;
}
static int F_180 ( struct V_17 * V_23 , struct V_342 * V_343 )
{
if ( ! V_23 || ! V_343 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_155 ( V_23 , V_344 , sizeof( * V_343 ) , V_343 ) ;
}
static int F_181 ( struct V_17 * V_23 )
{
const struct V_201 * V_202 = F_137 ( V_23 -> V_163 ) ;
struct V_342 V_345 ;
T_7 V_346 ;
int V_7 ;
memset ( & V_345 , 0 , sizeof( V_345 ) ) ;
V_345 . V_347 = V_348 ;
V_345 . V_349 = V_202 -> V_203 ;
for ( V_7 = 0 ; V_7 < V_202 -> V_203 ; V_7 ++ ) {
V_346 = V_202 -> V_204 [ V_7 ] . V_346 ;
V_345 . V_350 [ V_7 ] . V_351 =
V_202 -> V_204 [ V_7 ] . V_197 ;
V_345 . V_350 [ V_7 ] . V_345 = V_346 ?
F_3 ( V_346 , V_23 -> V_345 ) : V_23 -> V_345 ;
}
if ( F_180 ( V_23 , & V_345 ) )
return - V_306 ;
V_345 . V_347 = V_352 ;
if ( F_180 ( V_23 , & V_345 ) )
return - V_306 ;
if ( V_23 -> V_163 -> V_353 ) {
V_345 . V_347 = V_354 ;
V_345 . V_349 = V_202 -> V_209 ;
for ( V_7 = 0 ; V_7 < V_345 . V_349 ; V_7 ++ ) {
V_346 = V_202 -> V_18 [ V_7 ] . V_346 ;
V_345 . V_350 [ V_7 ] . V_351 =
V_202 -> V_18 [ V_7 ] . V_197 ;
V_345 . V_350 [ V_7 ] . V_345 = V_346 ?
F_3 ( V_346 , V_23 -> V_345 ) : V_23 -> V_345 ;
}
if ( F_180 ( V_23 , & V_345 ) )
return - V_306 ;
}
return 0 ;
}
static int F_182 ( struct V_17 * V_23 , T_4 V_355 )
{
struct V_356 V_357 = {
. V_357 = F_173 ( V_355 ) ,
} ;
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_155 ( V_23 , V_358 ,
sizeof( V_357 ) , & V_357 ) ;
}
static int F_183 ( struct V_17 * V_23 , T_4 V_359 )
{
struct V_360 V_361 = {
. V_361 = F_173 ( V_359 ) ,
} ;
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_155 ( V_23 , V_362 ,
sizeof( V_361 ) , & V_361 ) ;
}
static int F_184 ( struct V_17 * V_23 , T_3 V_118 )
{
T_6 V_154 ;
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
switch ( V_118 ) {
case V_363 :
V_154 = F_179 ( V_364 ) ;
break;
case V_365 :
V_154 = F_179 ( V_366 ) ;
break;
default:
V_154 = F_179 ( V_118 ) ;
break;
}
return F_155 ( V_23 , V_367 , sizeof( V_154 ) ,
& V_154 ) ;
}
static int F_185 ( struct V_17 * V_23 , T_2 V_368 , T_2 V_369 )
{
struct V_370 V_371 = {
. V_372 = V_368 ,
. V_373 = V_369
} ;
if ( ! V_23 ) {
F_46 ( L_143 ) ;
return - 1 ;
}
return F_155 ( V_23 , V_374 , sizeof( V_371 ) ,
& V_371 ) ;
}
static inline void F_186 ( struct V_17 * V_134 , T_3 V_3 )
{
F_12 ( V_134 , V_375 , V_3 ) ;
F_187 ( V_134 -> V_173 ) ;
}
static void F_188 ( struct V_17 * V_23 )
{
F_186 ( V_23 , 0 ) ;
F_186 ( V_23 , V_376 ) ;
F_186 ( V_23 , V_376 | V_377 ) ;
F_186 ( V_23 , V_376 ) ;
}
static void F_189 ( struct V_17 * V_23 )
{
F_186 ( V_23 , V_376 ) ;
F_186 ( V_23 , 0 ) ;
F_186 ( V_23 , V_377 ) ;
}
static inline void F_190 ( struct V_17 * V_134 , T_2 V_378 )
{
int V_133 = ( V_378 ? V_379 : 0 ) ;
F_186 ( V_134 , V_376 | V_133 ) ;
F_186 ( V_134 , V_376 | V_133 | V_377 ) ;
}
static void F_191 ( struct V_17 * V_23 , T_2 V_380 , T_2 V_32 )
{
int V_7 ;
F_188 ( V_23 ) ;
F_190 ( V_23 , 1 ) ;
F_190 ( V_23 , V_380 & 2 ) ;
F_190 ( V_23 , V_380 & 1 ) ;
for ( V_7 = 7 ; V_7 >= 0 ; V_7 -- ) {
F_190 ( V_23 , V_32 & ( 1 << V_7 ) ) ;
}
}
static T_4 F_192 ( struct V_17 * V_23 , T_2 V_32 )
{
int V_7 ;
T_4 V_381 = 0 ;
F_191 ( V_23 , V_382 , V_32 ) ;
F_186 ( V_23 , V_376 ) ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ ) {
T_3 V_3 = 0 ;
F_186 ( V_23 , V_376 | V_377 ) ;
F_186 ( V_23 , V_376 ) ;
V_3 = F_50 ( V_23 , V_375 ) ;
V_381 = ( V_381 << 1 ) | ( ( V_3 & V_383 ) ? 1 : 0 ) ;
}
F_186 ( V_23 , 0 ) ;
F_189 ( V_23 ) ;
return V_381 ;
}
static void F_193 ( struct V_17 * V_23 , T_2 * V_314 )
{
memcpy ( V_314 , & V_23 -> V_123 [ V_384 ] , V_217 ) ;
}
static void F_194 ( struct V_17 * V_23 )
{
int V_7 ;
T_8 * V_123 = ( T_8 * ) V_23 -> V_123 ;
F_195 ( L_150 ) ;
for ( V_7 = 0 ; V_7 < 128 ; V_7 ++ )
V_123 [ V_7 ] = F_173 ( F_192 ( V_23 , ( T_2 ) V_7 ) ) ;
F_195 ( L_151 ) ;
}
static void F_196 ( struct V_17 * V_23 )
{
int V_7 ;
F_195 ( L_150 ) ;
if ( V_23 -> V_123 [ V_385 ] != 0 ) {
F_74 ( L_152 ) ;
for ( V_7 = 0 ; V_7 < V_386 ; V_7 ++ )
F_197 ( V_23 , V_387 + V_7 , V_23 -> V_123 [ V_7 ] ) ;
F_35 ( V_23 , V_388 , 0 ) ;
} else {
F_74 ( L_153 ) ;
F_35 ( V_23 , V_388 , 1 ) ;
}
F_195 ( L_151 ) ;
}
static void F_198 ( struct V_17 * V_23 , T_3 V_389 , T_3 V_2 )
{
V_2 >>= 2 ;
if ( ! V_2 )
return;
F_18 ( V_23 , V_34 , V_389 ) ;
while ( V_2 -- )
F_18 ( V_23 , V_35 , 0 ) ;
}
static inline void F_199 ( struct V_17 * V_23 )
{
F_198 ( V_23 , V_390 ,
V_391 *
sizeof( struct V_392 ) ) ;
}
static int F_200 ( struct V_17 * V_23 )
{
F_146 ( L_154 ) ;
F_199 ( V_23 ) ;
F_12 ( V_23 , V_393 , V_390 ) ;
F_146 ( L_155 ) ;
return 0 ;
}
static void F_201 ( struct V_17 * V_23 )
{
T_3 V_394 = 0 ;
F_146 ( L_154 ) ;
V_394 = V_395 | V_396 ;
F_12 ( V_23 , V_397 , V_394 ) ;
V_23 -> V_398 . V_399 = 0 ;
F_146 ( L_151 ) ;
}
static int F_202 ( struct V_17 * V_23 , int V_400 ,
struct V_392 * V_401 )
{
T_3 V_402 =
V_390 +
( sizeof( struct V_392 ) * V_400 ) ;
F_146 ( L_154 ) ;
F_203 ( V_23 , V_402 , ( T_2 * ) V_401 ,
( int ) sizeof( struct V_392 ) ) ;
F_146 ( L_155 ) ;
return 0 ;
}
static int F_204 ( struct V_17 * V_23 )
{
T_3 V_394 = 0 ;
T_3 V_400 = 0 ;
F_146 ( L_154 ) ;
for ( V_400 = 0 ; V_400 < V_23 -> V_398 . V_399 ; V_400 ++ )
F_202 ( V_23 , V_400 ,
& V_23 -> V_398 . V_403 [ V_400 ] ) ;
F_37 ( V_23 , V_404 ,
V_405 |
V_406 ) ;
V_394 = V_395 | V_407 ;
F_12 ( V_23 , V_397 , V_394 ) ;
F_146 ( L_155 ) ;
return 0 ;
}
static void F_205 ( struct V_17 * V_23 )
{
T_3 V_402 ;
T_3 V_408 = 0 ;
T_3 V_409 = 0 ;
F_146 ( L_154 ) ;
V_402 = F_50 ( V_23 , V_410 ) ;
F_206 ( L_156 , V_402 ) ;
V_408 = F_50 ( V_23 , V_397 ) ;
F_206 ( L_157 , V_408 ) ;
V_409 = V_402 ;
V_408 = F_50 ( V_23 , V_409 ) ;
F_206 ( L_158 , V_408 ) ;
V_409 += sizeof( T_3 ) ;
V_408 = F_50 ( V_23 , V_409 ) ;
F_206 ( L_159 , V_408 ) ;
V_409 += sizeof( T_3 ) ;
V_408 = F_50 ( V_23 , V_409 ) ;
F_206 ( L_160 ,
V_408 ) ;
V_409 += sizeof( T_3 ) ;
V_408 = F_50 ( V_23 , V_409 ) ;
F_206 ( L_161 , V_408 ) ;
F_146 ( L_154 ) ;
}
static int F_207 ( struct V_17 * V_23 )
{
T_3 V_411 = 0 ;
T_3 V_412 = 0 ;
F_146 ( L_155 ) ;
V_411 = F_50 ( V_23 , V_410 ) ;
V_412 = ( V_411 - V_390 ) /
sizeof( struct V_392 ) ;
F_206 ( L_162 ,
V_412 , V_411 ) ;
F_146 ( L_154 ) ;
return V_412 ;
}
static int F_208 ( struct V_17 * V_23 ,
T_3 V_413 ,
T_3 V_414 ,
T_3 V_415 ,
int V_416 , int V_417 )
{
T_3 V_394 = V_418 | V_419 | V_420 | V_421 |
V_422 | V_423 | V_424 |
V_425 ;
struct V_392 * V_401 ;
T_3 V_426 = 0 ;
F_206 ( L_163 ,
V_413 , V_414 , V_415 ) ;
if ( V_23 -> V_398 . V_399 >= V_391 )
return - 1 ;
V_426 = V_23 -> V_398 . V_399 ;
V_401 = & V_23 -> V_398 . V_403 [ V_426 ] ;
V_23 -> V_398 . V_399 ++ ;
if ( V_416 )
V_394 |= V_427 ;
if ( V_417 )
V_394 |= V_428 ;
V_394 |= V_415 ;
V_401 -> V_37 = V_394 ^ V_413 ^ V_414 ;
V_401 -> V_429 = V_414 ;
V_401 -> V_430 = V_413 ;
V_401 -> V_394 = V_394 ;
return 0 ;
}
static int F_209 ( struct V_17 * V_23 , T_9 * V_413 ,
int V_431 , T_3 V_414 , T_3 V_4 )
{
int V_432 , V_7 ;
T_3 V_15 ;
F_146 ( L_150 ) ;
F_206 ( L_164 ,
V_431 , V_414 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_431 ; V_7 ++ ) {
V_15 = F_6 ( T_3 , V_4 - V_7 * V_433 , V_433 ) ;
V_432 = F_208 ( V_23 , V_413 [ V_7 ] ,
V_414 +
V_7 * V_433 , V_15 ,
0 , 0 ) ;
if ( V_432 ) {
F_206 ( L_165 ) ;
return - 1 ;
} else
F_206 ( L_166 ) ;
}
F_146 ( L_151 ) ;
return 0 ;
}
static int F_210 ( struct V_17 * V_23 )
{
T_3 V_434 = 0 , V_435 ;
T_3 V_436 = 0 ;
F_146 ( L_154 ) ;
V_434 = F_207 ( V_23 ) ;
F_206 ( L_167 ,
( int ) V_23 -> V_398 . V_399 ) ;
while ( V_434 < V_23 -> V_398 . V_399 ) {
F_187 ( 50 ) ;
V_435 = V_434 ;
V_434 = F_207 ( V_23 ) ;
if ( V_435 < V_434 ) {
V_436 = 0 ;
continue;
}
if ( ++ V_436 > 400 ) {
F_206 ( L_168 ) ;
F_205 ( V_23 ) ;
F_201 ( V_23 ) ;
return - 1 ;
}
}
F_201 ( V_23 ) ;
F_34 ( V_23 , V_404 ,
V_405 | V_406 ) ;
F_146 ( L_169 ) ;
return 0 ;
}
static void F_162 ( struct V_17 * V_23 )
{
struct V_437 * V_438 , * V_439 ;
struct V_440 * V_441 = NULL ;
unsigned long V_41 ;
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
F_211 (element, safe, &priv->ieee->network_list) {
V_441 = F_212 ( V_438 , struct V_440 , V_442 ) ;
if ( F_213 ( V_441 -> V_216 , V_23 -> V_216 ) ) {
F_214 ( V_438 ) ;
F_215 ( & V_441 -> V_442 ,
& V_23 -> V_163 -> V_443 ) ;
}
}
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
}
static inline int F_216 ( struct V_17 * V_23 )
{
return F_36 ( V_23 , 0x90 ) == 0xd55555d5 ;
}
static int F_217 ( struct V_17 * V_23 , T_3 V_32 , T_3 V_36 ,
int V_444 )
{
int V_7 = 0 ;
do {
if ( ( F_36 ( V_23 , V_32 ) & V_36 ) == V_36 )
return V_7 ;
F_218 ( 10 ) ;
V_7 += 10 ;
} while ( V_7 < V_444 );
return - V_445 ;
}
static int F_219 ( struct V_17 * V_23 )
{
int V_155 ;
F_195 ( L_150 ) ;
F_34 ( V_23 , V_404 , V_406 ) ;
V_155 = F_217 ( V_23 , V_404 ,
V_405 , 100 ) ;
if ( V_155 < 0 ) {
F_46 ( L_170 ) ;
return - 1 ;
}
F_74 ( L_171 , V_155 ) ;
return V_155 ;
}
static void F_220 ( struct V_17 * V_23 )
{
F_195 ( L_150 ) ;
F_218 ( 5 ) ;
F_37 ( V_23 , V_404 , V_446 ) ;
F_218 ( 5 ) ;
}
static int F_221 ( struct V_17 * V_23 , T_2 * V_3 , T_1 V_4 )
{
int V_155 = 0 , V_7 , V_32 ;
T_2 V_447 = 0 ;
T_8 * V_448 ;
V_448 = ( T_8 * ) V_3 ;
F_195 ( L_150 ) ;
V_155 = F_219 ( V_23 ) ;
if ( V_155 < 0 )
return V_155 ;
for ( V_32 = V_449 ;
V_32 < V_450 ; V_32 += 4 ) {
F_35 ( V_23 , V_32 , 0 ) ;
}
memset ( & V_23 -> V_451 , 0 , sizeof( V_23 -> V_451 ) ) ;
F_12 ( V_23 , V_452 , V_453 ) ;
F_220 ( V_23 ) ;
F_12 ( V_23 , V_452 , V_454 ) ;
F_218 ( 1 ) ;
F_12 ( V_23 , V_174 , V_455 ) ;
F_218 ( 1 ) ;
F_12 ( V_23 , V_174 , 0 ) ;
F_218 ( 1 ) ;
F_7 ( V_23 , V_456 , 0x0 ) ;
F_7 ( V_23 , V_456 , V_457 ) ;
F_218 ( 1 ) ;
for ( V_7 = 0 ; V_7 < V_4 / 2 ; V_7 ++ )
F_10 ( V_23 , V_458 ,
F_222 ( V_448 [ V_7 ] ) ) ;
F_7 ( V_23 , V_456 , 0 ) ;
F_7 ( V_23 , V_456 , V_459 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ ) {
V_447 = F_119 ( V_23 , V_456 ) ;
if ( V_447 & V_460 )
break;
F_218 ( 1 ) ;
}
if ( V_447 & V_460 ) {
T_6 V_461 [ ( sizeof( V_23 -> V_451 ) + 3 ) / 4 ] ;
for ( V_7 = 0 ; V_7 < F_223 ( V_461 ) ; V_7 ++ )
V_461 [ V_7 ] =
F_179 ( F_50 ( V_23 ,
V_462 ) ) ;
memcpy ( & V_23 -> V_451 , V_461 ,
sizeof( V_23 -> V_451 ) ) ;
if ( V_23 -> V_451 . V_463 == 1
&& V_23 -> V_451 . V_464 == 1 ) {
V_155 = 0 ;
F_74
( L_172
L_173 ,
V_23 -> V_451 . V_465 ,
V_23 -> V_451 . V_465 ,
V_23 -> V_451 . V_466 ,
V_23 -> V_451 . V_466 ,
V_23 -> V_451 . V_467 [ 0 ] ,
V_23 -> V_451 . V_467 [ 1 ] ,
V_23 -> V_451 . V_467 [ 2 ] ,
V_23 -> V_451 . V_467 [ 3 ] ,
V_23 -> V_451 . V_467 [ 4 ] ) ;
} else {
F_74 ( L_174 ) ;
V_155 = - V_75 ;
}
} else {
F_74 ( L_175 ) ;
V_155 = - V_445 ;
}
F_7 ( V_23 , V_456 , 0 ) ;
return V_155 ;
}
static int F_224 ( struct V_17 * V_23 , T_2 * V_3 , T_1 V_4 )
{
int V_432 = - 1 ;
int V_468 = 0 ;
struct V_469 * V_470 ;
int V_471 = 0 ;
int V_7 ;
struct V_472 * V_473 ;
void * * V_474 ;
T_9 * V_475 ;
F_195 ( L_155 ) ;
V_474 = F_83 ( sizeof( void * ) * V_391 ,
V_148 ) ;
if ( ! V_474 )
return - V_476 ;
V_475 = F_83 ( sizeof( T_9 ) * V_391 ,
V_148 ) ;
if ( ! V_475 ) {
F_87 ( V_474 ) ;
return - V_476 ;
}
V_473 = F_225 ( L_176 , V_23 -> V_477 , V_433 , 0 , 0 ) ;
if ( ! V_473 ) {
F_46 ( L_177 ) ;
F_87 ( V_475 ) ;
F_87 ( V_474 ) ;
return - V_476 ;
}
V_432 = F_200 ( V_23 ) ;
F_226 ( V_23 -> V_398 . V_399 > 0 ) ;
do {
T_3 V_478 ;
T_2 * V_389 ;
int V_15 ;
int V_431 = 0 ;
V_470 = (struct V_469 * ) ( V_3 + V_468 ) ;
V_468 += sizeof( struct V_469 ) ;
V_478 = F_227 ( V_470 -> V_415 ) ;
V_389 = V_3 + V_468 ;
V_431 = ( V_478 + V_433 - 1 ) / V_433 ;
for ( V_7 = 0 ; V_7 < V_431 ; V_7 ++ ) {
V_474 [ V_471 ] = F_228 ( V_473 , V_148 ,
& V_475 [ V_471 ] ) ;
if ( ! V_474 [ V_471 ] ) {
V_432 = - V_476 ;
goto V_6;
}
V_15 = F_6 ( T_3 , V_478 - V_7 * V_433 ,
V_433 ) ;
memcpy ( V_474 [ V_471 ] , V_389 , V_15 ) ;
V_389 += V_15 ;
V_471 ++ ;
F_226 ( V_471 > V_391 ) ;
}
V_432 = F_209 ( V_23 , & V_475 [ V_471 - V_431 ] ,
V_431 , F_227 ( V_470 -> V_402 ) ,
V_478 ) ;
if ( V_432 ) {
F_74 ( L_178 ) ;
goto V_6;
}
V_468 += V_478 ;
} while ( V_468 < V_4 );
V_432 = F_204 ( V_23 ) ;
if ( V_432 ) {
F_46 ( L_179 ) ;
goto V_6;
}
V_432 = F_210 ( V_23 ) ;
if ( V_432 ) {
F_46 ( L_180 ) ;
goto V_6;
}
V_6:
for ( V_7 = 0 ; V_7 < V_471 ; V_7 ++ )
F_229 ( V_473 , V_474 [ V_7 ] , V_475 [ V_7 ] ) ;
F_230 ( V_473 ) ;
F_87 ( V_475 ) ;
F_87 ( V_474 ) ;
return V_432 ;
}
static int F_231 ( struct V_17 * V_23 )
{
int V_155 = 0 ;
F_35 ( V_23 , V_404 , V_406 ) ;
V_155 = F_217 ( V_23 , V_404 ,
V_405 , 500 ) ;
if ( V_155 < 0 ) {
F_46 ( L_181 ) ;
return V_155 ;
}
F_34 ( V_23 , V_404 , V_446 ) ;
return V_155 ;
}
static void F_232 ( struct V_17 * V_23 )
{
F_195 ( L_150 ) ;
F_37 ( V_23 , V_404 ,
V_405 |
V_406 |
V_446 ) ;
F_34 ( V_23 , V_479 ,
V_480 ) ;
F_195 ( L_151 ) ;
}
static int F_233 ( struct V_17 * V_23 )
{
int V_155 ;
F_195 ( L_150 ) ;
F_34 ( V_23 , V_479 , V_481 ) ;
F_35 ( V_23 , V_482 ,
V_483 ) ;
V_155 = F_217 ( V_23 , V_479 ,
V_484 , 250 ) ;
if ( V_155 < 0 )
F_74 ( L_182 ) ;
F_34 ( V_23 , V_404 , V_485 ) ;
F_187 ( 10 ) ;
F_34 ( V_23 , V_479 , V_481 ) ;
F_195 ( L_150 ) ;
return 0 ;
}
static int F_234 ( struct V_17 * V_23 )
{
int V_155 = 0 ;
unsigned long V_41 ;
F_195 ( L_150 ) ;
V_155 = F_233 ( V_23 ) ;
F_41 ( & V_23 -> V_98 , V_41 ) ;
V_23 -> V_37 &= ~ V_227 ;
F_144 ( & V_23 -> V_228 ) ;
V_23 -> V_37 &= ~ ( V_321 | V_319 ) ;
F_144 ( & V_23 -> V_486 ) ;
F_42 ( & V_23 -> V_98 , V_41 ) ;
F_195 ( L_151 ) ;
return V_155 ;
}
static int F_235 ( struct V_17 * V_23 ,
const struct V_487 * * V_488 , const char * V_158 )
{
struct V_489 * V_490 ;
int V_155 ;
V_155 = F_236 ( V_488 , V_158 , & V_23 -> V_477 -> V_166 ) ;
if ( V_155 < 0 ) {
F_46 ( L_183 , V_158 , V_155 ) ;
return V_155 ;
}
if ( ( * V_488 ) -> V_15 < sizeof( * V_490 ) ) {
F_46 ( L_184 , V_158 , ( * V_488 ) -> V_15 ) ;
return - V_75 ;
}
V_490 = ( void * ) ( * V_488 ) -> V_3 ;
if ( ( * V_488 ) -> V_15 < sizeof( * V_490 ) + F_227 ( V_490 -> V_491 ) +
F_227 ( V_490 -> V_492 ) + F_227 ( V_490 -> V_493 ) ) {
F_46 ( L_185 ,
V_158 , ( * V_488 ) -> V_15 ) ;
return - V_75 ;
}
F_74 ( L_186 ,
V_158 ,
F_227 ( V_490 -> V_494 ) >> 16 ,
F_227 ( V_490 -> V_494 ) & 0xff ,
( * V_488 ) -> V_15 - sizeof( * V_490 ) ) ;
return 0 ;
}
static void F_237 ( struct V_17 * V_23 ,
struct V_495 * V_496 )
{
unsigned long V_41 ;
int V_7 ;
F_41 ( & V_496 -> V_98 , V_41 ) ;
F_238 ( & V_496 -> V_497 ) ;
F_238 ( & V_496 -> V_498 ) ;
for ( V_7 = 0 ; V_7 < V_499 + V_500 ; V_7 ++ ) {
if ( V_496 -> V_473 [ V_7 ] . V_501 != NULL ) {
F_239 ( V_23 -> V_477 , V_496 -> V_473 [ V_7 ] . V_502 ,
V_503 , V_504 ) ;
F_240 ( V_496 -> V_473 [ V_7 ] . V_501 ) ;
V_496 -> V_473 [ V_7 ] . V_501 = NULL ;
}
F_215 ( & V_496 -> V_473 [ V_7 ] . V_442 , & V_496 -> V_498 ) ;
}
V_496 -> V_505 = V_496 -> V_506 = 0 ;
V_496 -> V_507 = 0 ;
F_42 ( & V_496 -> V_98 , V_41 ) ;
}
static void F_241 ( void )
{
if ( V_508 ) {
F_242 ( V_488 ) ;
V_488 = NULL ;
V_508 = 0 ;
}
}
static int F_243 ( struct V_17 * V_23 )
{
#ifndef F_244
const struct V_487 * V_488 = NULL ;
#endif
struct V_489 * V_490 ;
T_2 * V_509 , * V_510 , * V_511 ;
T_2 * V_158 = NULL ;
int V_155 = 0 , V_512 = 3 ;
switch ( V_23 -> V_163 -> V_513 ) {
case V_514 :
V_158 = L_187 ;
break;
#ifdef F_245
case V_515 :
V_158 = L_188 ;
break;
#endif
case V_516 :
V_158 = L_189 ;
break;
}
if ( ! V_158 ) {
V_155 = - V_75 ;
goto error;
}
#ifdef F_244
if ( ! V_508 ) {
#endif
V_155 = F_235 ( V_23 , & V_488 , V_158 ) ;
if ( V_155 < 0 )
goto error;
#ifdef F_244
}
#endif
V_490 = ( void * ) V_488 -> V_3 ;
V_509 = & V_490 -> V_3 [ 0 ] ;
V_510 = & V_490 -> V_3 [ F_227 ( V_490 -> V_491 ) ] ;
V_511 = & V_490 -> V_3 [ F_227 ( V_490 -> V_491 ) +
F_227 ( V_490 -> V_492 ) ] ;
if ( V_155 < 0 )
goto error;
if ( ! V_23 -> V_496 )
V_23 -> V_496 = F_246 ( V_23 ) ;
else
F_237 ( V_23 , V_23 -> V_496 ) ;
if ( ! V_23 -> V_496 ) {
F_46 ( L_190 ) ;
V_155 = - V_476 ;
goto error;
}
V_517:
F_35 ( V_23 , V_39 , ~ V_40 ) ;
V_23 -> V_37 &= ~ V_38 ;
F_35 ( V_23 , V_222 , V_40 ) ;
F_231 ( V_23 ) ;
V_155 = F_234 ( V_23 ) ;
if ( V_155 < 0 ) {
F_46 ( L_191 ) ;
goto error;
}
F_198 ( V_23 , V_518 ,
V_519 - V_518 ) ;
V_155 = F_224 ( V_23 , V_509 , F_227 ( V_490 -> V_491 ) ) ;
if ( V_155 < 0 ) {
F_46 ( L_192 , V_155 ) ;
goto error;
}
F_232 ( V_23 ) ;
V_155 = F_217 ( V_23 , V_222 ,
V_237 , 500 ) ;
if ( V_155 < 0 ) {
F_46 ( L_193 ) ;
goto error;
}
F_74 ( L_194 , V_155 ) ;
F_35 ( V_23 , V_222 , V_237 ) ;
V_155 = F_221 ( V_23 , V_510 , F_227 ( V_490 -> V_492 ) ) ;
if ( V_155 < 0 ) {
F_46 ( L_195 , V_155 ) ;
goto error;
}
F_231 ( V_23 ) ;
V_155 = F_224 ( V_23 , V_511 , F_227 ( V_490 -> V_493 ) ) ;
if ( V_155 < 0 ) {
F_46 ( L_196 , V_155 ) ;
goto error;
}
#ifdef F_244
V_508 = 1 ;
#endif
F_35 ( V_23 , V_388 , 0 ) ;
V_155 = F_247 ( V_23 ) ;
if ( V_155 < 0 ) {
F_46 ( L_197 ) ;
goto error;
}
F_35 ( V_23 , V_39 , ~ V_40 ) ;
F_35 ( V_23 , V_222 , V_40 ) ;
F_232 ( V_23 ) ;
if ( F_36 ( V_23 , V_222 ) & V_247 ) {
if ( V_512 > 0 ) {
F_93 ( L_198 ) ;
V_512 -- ;
goto V_517;
}
F_46 ( L_199 ) ;
V_155 = - V_306 ;
goto error;
}
V_155 = F_217 ( V_23 , V_222 ,
V_237 , 500 ) ;
if ( V_155 < 0 ) {
F_46 ( L_200 ) ;
goto error;
}
F_74 ( L_201 , V_155 ) ;
F_35 ( V_23 , V_222 , V_237 ) ;
V_23 -> V_173 = 1 ;
F_194 ( V_23 ) ;
F_196 ( V_23 ) ;
F_40 ( V_23 ) ;
F_248 ( V_23 ) ;
F_35 ( V_23 , V_520 , V_23 -> V_496 -> V_505 ) ;
F_35 ( V_23 , V_222 , V_40 ) ;
#ifndef F_244
F_242 ( V_488 ) ;
#endif
return 0 ;
error:
if ( V_23 -> V_496 ) {
F_249 ( V_23 , V_23 -> V_496 ) ;
V_23 -> V_496 = NULL ;
}
F_250 ( V_23 ) ;
F_242 ( V_488 ) ;
#ifdef F_244
V_508 = 0 ;
V_488 = NULL ;
#endif
return V_155 ;
}
static int F_251 ( const struct V_495 * V_521 )
{
int V_522 = V_521 -> V_505 - V_521 -> V_506 ;
if ( V_522 <= 0 )
V_522 += V_500 ;
V_522 -= 2 ;
if ( V_522 < 0 )
V_522 = 0 ;
return V_522 ;
}
static inline int F_252 ( const struct V_523 * V_521 )
{
int V_522 = V_521 -> V_524 - V_521 -> V_525 ;
if ( V_522 <= 0 )
V_522 += V_521 -> V_526 ;
V_522 -= 2 ;
if ( V_522 < 0 )
V_522 = 0 ;
return V_522 ;
}
static inline int F_253 ( int V_400 , int V_526 )
{
return ( ++ V_400 == V_526 ) ? 0 : V_400 ;
}
static void F_254 ( struct V_17 * V_23 , struct V_523 * V_521 ,
int V_2 , T_3 V_505 , T_3 V_506 , T_3 V_137 , T_3 V_15 )
{
V_521 -> V_526 = V_2 ;
V_521 -> V_527 = V_521 -> V_526 / 4 ;
if ( V_521 -> V_527 < 4 )
V_521 -> V_527 = 4 ;
V_521 -> V_528 = V_521 -> V_526 / 8 ;
if ( V_521 -> V_528 < 2 )
V_521 -> V_528 = 2 ;
V_521 -> V_525 = V_521 -> V_524 = 0 ;
V_521 -> V_529 = V_505 ;
V_521 -> V_530 = V_506 ;
F_35 ( V_23 , V_137 , V_521 -> V_502 ) ;
F_35 ( V_23 , V_15 , V_2 ) ;
F_35 ( V_23 , V_505 , 0 ) ;
F_35 ( V_23 , V_506 , 0 ) ;
F_24 ( V_23 , 0x90 ) ;
}
static int F_255 ( struct V_17 * V_23 ,
struct V_531 * V_521 ,
int V_2 , T_3 V_505 , T_3 V_506 , T_3 V_137 , T_3 V_15 )
{
struct V_477 * V_166 = V_23 -> V_477 ;
V_521 -> V_532 = F_83 ( sizeof( V_521 -> V_532 [ 0 ] ) * V_2 , V_148 ) ;
if ( ! V_521 -> V_532 ) {
F_46 ( L_202 ) ;
return - V_476 ;
}
V_521 -> V_533 =
F_256 ( V_166 , sizeof( V_521 -> V_533 [ 0 ] ) * V_2 , & V_521 -> V_521 . V_502 ) ;
if ( ! V_521 -> V_533 ) {
F_46 ( L_203 ,
sizeof( V_521 -> V_533 [ 0 ] ) * V_2 ) ;
F_87 ( V_521 -> V_532 ) ;
V_521 -> V_532 = NULL ;
return - V_476 ;
}
F_254 ( V_23 , & V_521 -> V_521 , V_2 , V_505 , V_506 , V_137 , V_15 ) ;
return 0 ;
}
static void F_257 ( struct V_17 * V_23 ,
struct V_531 * V_230 )
{
struct V_534 * V_533 = & V_230 -> V_533 [ V_230 -> V_521 . V_524 ] ;
struct V_477 * V_166 = V_23 -> V_477 ;
int V_7 ;
if ( V_533 -> V_535 . V_536 == V_537 )
return;
if ( F_227 ( V_533 -> V_538 . V_3 . V_539 ) > V_540 ) {
F_46 ( L_204 ,
F_227 ( V_533 -> V_538 . V_3 . V_539 ) ) ;
return;
}
for ( V_7 = 0 ; V_7 < F_227 ( V_533 -> V_538 . V_3 . V_539 ) ; V_7 ++ ) {
F_239 ( V_166 , F_227 ( V_533 -> V_538 . V_3 . V_541 [ V_7 ] ) ,
F_222 ( V_533 -> V_538 . V_3 . V_478 [ V_7 ] ) ,
V_542 ) ;
if ( V_230 -> V_532 [ V_230 -> V_521 . V_524 ] ) {
F_258 ( V_230 -> V_532 [ V_230 -> V_521 . V_524 ] ) ;
V_230 -> V_532 [ V_230 -> V_521 . V_524 ] = NULL ;
}
}
}
static void F_259 ( struct V_17 * V_23 , struct V_531 * V_230 )
{
struct V_523 * V_521 = & V_230 -> V_521 ;
struct V_477 * V_166 = V_23 -> V_477 ;
if ( V_521 -> V_526 == 0 )
return;
for (; V_521 -> V_525 != V_521 -> V_524 ;
V_521 -> V_524 = F_253 ( V_521 -> V_524 , V_521 -> V_526 ) ) {
F_257 ( V_23 , V_230 ) ;
}
F_260 ( V_166 , sizeof( V_230 -> V_533 [ 0 ] ) * V_521 -> V_526 , V_230 -> V_533 ,
V_521 -> V_502 ) ;
F_87 ( V_230 -> V_532 ) ;
memset ( V_230 , 0 , sizeof( * V_230 ) ) ;
}
static void F_250 ( struct V_17 * V_23 )
{
F_259 ( V_23 , & V_23 -> V_226 ) ;
F_259 ( V_23 , & V_23 -> V_230 [ 0 ] ) ;
F_259 ( V_23 , & V_23 -> V_230 [ 1 ] ) ;
F_259 ( V_23 , & V_23 -> V_230 [ 2 ] ) ;
F_259 ( V_23 , & V_23 -> V_230 [ 3 ] ) ;
}
static void F_261 ( struct V_17 * V_23 , T_2 * V_216 )
{
V_216 [ 0 ] = V_23 -> V_543 [ 0 ] ;
V_216 [ 1 ] = V_23 -> V_543 [ 1 ] ;
V_216 [ 2 ] = V_23 -> V_543 [ 2 ] ;
F_177 ( & V_216 [ 3 ] , V_217 - 3 ) ;
V_216 [ 0 ] &= 0xfe ;
V_216 [ 0 ] |= 0x02 ;
}
static T_2 F_262 ( struct V_17 * V_23 , T_2 * V_216 )
{
struct V_544 V_545 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_23 -> V_546 ; V_7 ++ ) {
if ( F_213 ( V_23 -> V_547 [ V_7 ] , V_216 ) ) {
V_23 -> V_548 = 0 ;
if ( ! ( V_23 -> V_59 & V_549 ) )
V_23 -> V_59 &= ~ V_550 ;
return V_7 ;
}
}
if ( V_7 == V_551 )
return V_552 ;
F_166 ( L_205 , V_216 ) ;
V_545 . V_553 = 0 ;
V_545 . V_554 = 0 ;
memcpy ( V_545 . V_543 , V_216 , V_217 ) ;
memcpy ( V_23 -> V_547 [ V_7 ] , V_216 , V_217 ) ;
F_32 ( V_23 , V_555 + V_7 * sizeof( V_545 ) ,
& V_545 , sizeof( V_545 ) ) ;
V_23 -> V_546 ++ ;
return V_7 ;
}
static T_2 F_263 ( struct V_17 * V_23 , T_2 * V_216 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_23 -> V_546 ; V_7 ++ )
if ( F_213 ( V_23 -> V_547 [ V_7 ] , V_216 ) )
return V_7 ;
return V_552 ;
}
static void F_264 ( struct V_17 * V_23 , int V_556 )
{
int V_557 ;
if ( V_23 -> V_37 & V_240 ) {
F_265 ( L_206 ) ;
F_128 ( & V_23 -> V_558 ) ;
return;
}
if ( ! ( V_23 -> V_37 & V_103 ) ) {
F_265 ( L_207 ) ;
return;
}
F_265 ( L_208
L_209 ,
V_23 -> V_559 . V_216 ,
V_23 -> V_559 . V_197 ) ;
V_23 -> V_37 &= ~ ( V_240 | V_103 ) ;
V_23 -> V_37 |= V_560 ;
if ( V_556 )
V_23 -> V_559 . V_561 = V_562 ;
else
V_23 -> V_559 . V_561 = V_563 ;
V_557 = F_174 ( V_23 , & V_23 -> V_559 ) ;
if ( V_557 ) {
F_142 ( L_210
L_65 ) ;
return;
}
}
static int F_266 ( void * V_3 )
{
struct V_17 * V_23 = V_3 ;
if ( ! ( V_23 -> V_37 & ( V_103 | V_240 ) ) )
return 0 ;
F_264 ( V_3 , 0 ) ;
F_267 ( V_23 -> V_167 ) ;
return 1 ;
}
static void F_268 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_558 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_266 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_269 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_564 ) ;
#ifdef F_270
if ( V_23 -> V_157 && F_92 ( V_23 -> V_157 ) ) {
V_23 -> V_310 . V_565 = 1 ;
V_23 -> V_310 . V_566 = 1 ;
V_23 -> V_310 . V_567 = 1 ;
V_23 -> V_310 . V_568 = 1 ;
}
#endif
F_157 ( V_23 ) ;
}
static const char * F_271 ( T_4 V_37 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_223 ( V_569 ) ; V_7 ++ )
if ( V_569 [ V_7 ] . V_37 == ( V_37 & 0xff ) )
return V_569 [ V_7 ] . V_570 ;
return L_211 ;
}
static void inline F_272 ( struct V_571 * V_572 )
{
memset ( V_572 , 0 , sizeof( * V_572 ) ) ;
}
static T_10 F_273 ( T_10 V_573 , T_10 V_21 , T_2 V_574 )
{
return ( ( V_574 - 1 ) * V_573 + V_21 ) / V_574 ;
}
static void F_274 ( struct V_571 * V_572 , T_10 V_21 )
{
V_572 -> V_575 -= V_572 -> V_576 [ V_572 -> V_194 ] ;
V_572 -> V_575 += V_21 ;
V_572 -> V_576 [ V_572 -> V_194 ++ ] = V_21 ;
if ( F_29 ( V_572 -> V_194 == V_577 ) ) {
V_572 -> V_578 = 1 ;
V_572 -> V_194 = 0 ;
}
}
static T_10 F_275 ( struct V_571 * V_572 )
{
if ( ! F_29 ( V_572 -> V_578 ) ) {
if ( V_572 -> V_194 )
return V_572 -> V_575 / V_572 -> V_194 ;
return 0 ;
}
return V_572 -> V_575 / V_577 ;
}
static void F_276 ( struct V_17 * V_23 )
{
T_3 V_4 = sizeof( T_3 ) ;
V_23 -> V_579 = 0 ;
F_272 ( & V_23 -> V_580 ) ;
V_23 -> V_581 = - 60 ;
V_23 -> V_582 = - 85 + 0x100 ;
V_23 -> V_583 = 0 ;
V_23 -> V_584 = 0 ;
V_23 -> V_585 = 0 ;
V_23 -> V_586 = 0 ;
V_23 -> V_587 = 0 ;
F_48 ( V_23 , V_588 ,
& V_23 -> V_589 , & V_4 ) ;
F_48 ( V_23 , V_590 ,
& V_23 -> V_587 , & V_4 ) ;
V_23 -> V_548 = 0 ;
V_23 -> V_591 = 0 ;
V_23 -> V_592 = 0 ;
V_23 -> V_593 = 0 ;
}
static T_3 F_277 ( struct V_17 * V_23 )
{
T_3 V_7 = 0x80000000 ;
T_3 V_36 = V_23 -> V_594 ;
if ( V_23 -> V_559 . V_347 == V_352 )
V_36 &= V_595 ;
while ( V_7 && ! ( V_36 & V_7 ) )
V_7 >>= 1 ;
switch ( V_7 ) {
case V_596 :
return 1000000 ;
case V_597 :
return 2000000 ;
case V_598 :
return 5500000 ;
case V_599 :
return 6000000 ;
case V_600 :
return 9000000 ;
case V_601 :
return 11000000 ;
case V_602 :
return 12000000 ;
case V_603 :
return 18000000 ;
case V_604 :
return 24000000 ;
case V_605 :
return 36000000 ;
case V_606 :
return 48000000 ;
case V_607 :
return 54000000 ;
}
if ( V_23 -> V_163 -> V_118 == V_608 )
return 11000000 ;
else
return 54000000 ;
}
static T_3 F_278 ( struct V_17 * V_23 )
{
T_3 V_609 , V_4 = sizeof( V_609 ) ;
int V_557 ;
if ( ! ( V_23 -> V_37 & V_103 ) )
return 0 ;
if ( V_23 -> V_592 > V_610 ) {
V_557 = F_48 ( V_23 , V_611 , & V_609 ,
& V_4 ) ;
if ( V_557 ) {
F_74 ( L_212 ) ;
return 0 ;
}
} else
return F_277 ( V_23 ) ;
switch ( V_609 ) {
case V_612 :
return 1000000 ;
case V_613 :
return 2000000 ;
case V_614 :
return 5500000 ;
case V_615 :
return 6000000 ;
case V_616 :
return 9000000 ;
case V_617 :
return 11000000 ;
case V_618 :
return 12000000 ;
case V_619 :
return 18000000 ;
case V_620 :
return 24000000 ;
case V_621 :
return 36000000 ;
case V_622 :
return 48000000 ;
case V_623 :
return 54000000 ;
}
return 0 ;
}
static void F_279 ( struct V_17 * V_23 )
{
T_3 V_624 , V_625 , V_626 ;
T_3 V_627 , V_628 , V_629 ;
T_3 V_630 , V_631 ;
T_3 V_579 = 0 ;
T_3 V_4 = sizeof( T_3 ) ;
T_10 V_632 ;
T_3 V_633 , V_634 , V_635 , V_636 ,
V_637 ;
T_3 V_638 ;
if ( ! ( V_23 -> V_37 & V_103 ) ) {
V_23 -> V_579 = 0 ;
return;
}
F_48 ( V_23 , V_639 ,
& V_23 -> V_591 , & V_4 ) ;
V_631 = V_23 -> V_591 - V_23 -> V_584 ;
V_23 -> V_584 = V_23 -> V_591 ;
if ( V_23 -> V_559 . V_640 ) {
V_630 = V_631 *
( V_192 * F_222 ( V_23 -> V_559 . V_640 ) ) /
( V_641 * 10 ) ;
} else {
V_630 = 0 ;
}
F_274 ( & V_23 -> V_580 , V_630 ) ;
F_48 ( V_23 , V_588 , & V_624 , & V_4 ) ;
V_625 = V_624 - V_23 -> V_589 ;
V_23 -> V_589 = V_624 ;
F_48 ( V_23 , V_590 , & V_627 , & V_4 ) ;
V_628 = V_627 - V_23 -> V_587 ;
V_23 -> V_587 = V_627 ;
V_626 = V_23 -> V_593 - V_23 -> V_585 ;
V_23 -> V_585 = V_23 -> V_593 ;
V_629 = V_23 -> V_592 - V_23 -> V_586 ;
V_23 -> V_586 = V_23 -> V_592 ;
#define F_280 5
V_633 = 100 - V_630 ;
if ( V_633 < F_280 )
V_633 = 0 ;
else
V_633 = ( V_633 - F_280 ) * 100 /
( 100 - F_280 ) ;
F_281 ( L_213 ,
V_633 , V_630 ) ;
V_23 -> V_583 = F_278 ( V_23 ) ;
V_638 = F_277 ( V_23 ) ;
V_637 = V_23 -> V_583 * 40 / V_638 + 60 ;
F_281 ( L_214 ,
V_637 , V_23 -> V_583 / 1000000 ) ;
if ( V_626 > 100 && V_626 + V_625 )
V_636 = 100 - ( V_625 * 100 ) /
( V_626 + V_625 ) ;
else
V_636 = 100 ;
F_281 ( L_215 ,
V_636 , V_625 , V_626 ) ;
if ( V_629 > 100 && V_629 + V_628 )
V_635 = 100 - ( V_628 * 100 ) /
( V_629 + V_628 ) ;
else
V_635 = 100 ;
F_281 ( L_216 ,
V_635 , V_628 , V_629 ) ;
V_632 = V_23 -> V_581 ;
V_634 =
( 100 *
( V_23 -> V_163 -> V_642 - V_23 -> V_163 -> V_643 ) *
( V_23 -> V_163 -> V_642 - V_23 -> V_163 -> V_643 ) -
( V_23 -> V_163 -> V_642 - V_632 ) *
( 15 * ( V_23 -> V_163 -> V_642 - V_23 -> V_163 -> V_643 ) +
62 * ( V_23 -> V_163 -> V_642 - V_632 ) ) ) /
( ( V_23 -> V_163 -> V_642 - V_23 -> V_163 -> V_643 ) *
( V_23 -> V_163 -> V_642 - V_23 -> V_163 -> V_643 ) ) ;
if ( V_634 > 100 )
V_634 = 100 ;
else if ( V_634 < 1 )
V_634 = 0 ;
F_281 ( L_217 ,
V_634 , V_632 ) ;
V_579 = F_3 ( V_636 , V_634 ) ;
V_579 = F_3 ( V_635 , V_579 ) ;
V_579 = F_3 ( V_637 , V_579 ) ;
V_579 = F_3 ( V_633 , V_579 ) ;
if ( V_579 == V_633 )
F_281 ( L_218 ,
V_579 ) ;
if ( V_579 == V_637 )
F_281 ( L_219 ,
V_579 ) ;
if ( V_579 == V_635 )
F_281 ( L_220 ,
V_579 ) ;
if ( V_579 == V_636 )
F_281 ( L_221 ,
V_579 ) ;
if ( V_579 == V_634 )
F_281 ( L_222 ,
V_579 ) ;
V_23 -> V_579 = V_579 ;
F_56 ( & V_23 -> V_644 , V_641 ) ;
}
static void F_282 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_644 . V_107 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_279 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_283 ( struct V_17 * V_23 ,
int V_645 )
{
V_23 -> V_646 = V_645 ;
if ( V_645 > V_23 -> V_647 &&
V_23 -> V_37 & V_103 ) {
F_284 ( V_648 | V_649 |
V_650 | V_651 ,
L_223 , V_645 ) ;
V_23 -> V_37 &= ~ V_652 ;
if ( V_23 -> V_37 & V_321 ) {
F_284 ( V_648 | V_649 |
V_650 ,
L_224 ) ;
F_128 ( & V_23 -> V_653 ) ;
}
F_128 ( & V_23 -> V_558 ) ;
return;
}
if ( V_23 -> V_37 & V_652 ) {
F_284 ( V_649 | V_650 ,
L_225 ,
V_645 ) ;
return;
}
if ( V_654 &&
( V_645 > V_23 -> V_655 &&
V_645 <= V_23 -> V_647 ) ) {
F_284 ( V_649 | V_650 ,
L_226
L_227 , V_645 ) ;
if ( ! ( V_23 -> V_37 & V_652 ) ) {
V_23 -> V_37 |= V_652 ;
if ( ! ( V_23 -> V_37 & V_321 ) )
F_56 ( & V_23 -> V_186 , 0 ) ;
}
return;
}
if ( V_23 -> V_37 & V_321 &&
V_645 > V_656 ) {
F_284 ( V_648 | V_649 | V_650 ,
L_224 ) ;
F_128 ( & V_23 -> V_653 ) ;
}
F_285 ( L_228 , V_645 ) ;
}
static void F_286 ( struct V_106 * V_107 )
{
union V_210 V_211 ;
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_189 . V_107 ) ;
V_211 . V_3 . V_415 = 0 ;
V_211 . V_3 . V_41 = 0 ;
F_139 ( V_23 -> V_167 , V_657 , & V_211 , NULL ) ;
}
static void F_287 ( struct V_17 * V_23 )
{
if ( ! V_23 -> V_658 ) {
F_56 ( & V_23 -> V_189 ,
F_129 ( F_288 ( 4000 ) ) ) ;
} else {
V_23 -> V_658 = 0 ;
F_289 ( V_659 , & V_23 -> V_189 , 0 ) ;
}
}
static void F_290 ( struct V_17 * V_23 ,
struct F_290 * V_660 )
{
T_4 V_15 = F_222 ( V_660 -> V_15 ) ;
F_285 ( L_229 , V_660 -> V_661 , V_15 ) ;
switch ( V_660 -> V_661 ) {
case V_662 : {
struct V_663 * V_664 = & V_660 -> V_538 . V_664 ;
switch ( V_664 -> V_665 ) {
case V_666 : {
F_284 ( V_649 | V_650 |
V_651 ,
L_230 ,
V_23 -> V_667 , V_23 -> V_668 ,
V_23 -> V_216 ) ;
switch ( V_23 -> V_163 -> V_513 ) {
case V_516 :
memcpy ( V_23 -> V_163 -> V_216 ,
V_23 -> V_216 , V_217 ) ;
break;
case V_514 :
memcpy ( V_23 -> V_163 -> V_216 ,
V_23 -> V_216 , V_217 ) ;
V_23 -> V_546 = 0 ;
F_265
( L_231 ) ;
F_56 (
& V_23 -> V_669 ,
F_222 ( V_23 ->
V_559 .
V_640 ) ) ;
break;
}
V_23 -> V_37 &= ~ V_240 ;
V_23 -> V_37 |= V_103 ;
F_128 ( & V_23 -> V_564 ) ;
#ifdef F_291
#define F_292 ( T_11 ) WLAN_FC_GET_STYPE( \
le16_to_cpu(((struct ieee80211_hdr *)(x))->frame_control))
if ( ( V_23 -> V_37 & V_670 ) &&
( F_292 ( & V_660 -> V_538 . V_488 )
== V_671 ) ) {
if ( ( sizeof
( struct
V_672 )
<= V_15 )
&& ( V_15 <= 2314 ) ) {
struct
V_673
V_674 = {
. V_4 = V_15 - 1 ,
} ;
F_293
( L_232
L_233 , V_15 ) ;
F_294 ( V_23 ->
V_163 ,
(struct
V_675
* )
& V_660 -> V_538 . V_488 , & V_674 ) ;
}
}
#endif
F_128 ( & V_23 -> V_676 ) ;
break;
}
case V_677 : {
if ( V_23 ->
V_37 & ( V_103 |
V_670 ) ) {
struct V_678 * V_679
= & V_660 -> V_538 . V_679 ;
F_284 ( V_649 |
V_650 |
V_651 ,
L_234 ,
V_23 -> V_667 ,
V_23 -> V_668 ,
V_23 -> V_216 ,
F_222 ( V_679 -> V_37 ) ,
F_271
( F_222
( V_679 -> V_37 ) ) ) ;
V_23 -> V_37 &=
~ ( V_240 |
V_670 |
V_103 ) ;
F_128 ( & V_23 -> V_241 ) ;
break;
}
F_284 ( V_649 | V_650 |
V_651 ,
L_235 ,
V_23 -> V_667 , V_23 -> V_668 ,
V_23 -> V_216 ) ;
break;
}
case V_680 : {
if ( V_23 -> V_37 & V_670 ) {
struct
V_672
* V_681 ;
V_681 =
(struct
V_672
* ) & V_660 -> V_538 . V_488 ;
F_284 ( V_649 |
V_650 |
V_651 ,
L_236 ,
F_222 ( V_681 -> V_37 ) ,
F_271
( F_222
( V_681 -> V_37 ) ) ) ;
}
F_284 ( V_649 | V_650 |
V_651 ,
L_237 ,
V_23 -> V_667 , V_23 -> V_668 ,
V_23 -> V_216 ) ;
V_23 -> V_37 &=
~ ( V_560 |
V_240 |
V_103 | V_670 ) ;
if ( V_23 -> V_117
&& ( V_23 -> V_117 ->
V_317 &
V_318 ) )
F_162
( V_23 ) ;
F_128 ( & V_23 -> V_241 ) ;
break;
}
case V_682 :
break;
default:
F_46 ( L_238 ,
V_664 -> V_665 ) ;
break;
}
break;
}
case V_683 : {
struct V_678 * V_679 = & V_660 -> V_538 . V_679 ;
switch ( V_679 -> V_665 ) {
case V_677 :
F_284 ( V_649 | V_650 ,
L_235 ,
V_23 -> V_667 , V_23 -> V_668 ,
V_23 -> V_216 ) ;
V_23 -> V_37 |= V_670 ;
break;
case V_680 :
if ( V_23 -> V_37 & V_670 ) {
F_284 ( V_649 | V_650 |
V_651 ,
L_239 ,
F_222 ( V_679 -> V_37 ) ,
F_271 ( F_222
( V_679 ->
V_37 ) ) ) ;
}
F_284 ( V_649 | V_650 |
V_651 ,
L_240 ,
V_23 -> V_667 , V_23 -> V_668 ,
V_23 -> V_216 ) ;
V_23 -> V_37 &= ~ ( V_240 |
V_670 |
V_103 ) ;
F_128 ( & V_23 -> V_241 ) ;
break;
case V_684 :
F_284 ( V_649 | V_650 |
V_651 , L_241 ) ;
break;
case V_685 :
F_284 ( V_649 | V_650 |
V_651 , L_242 ) ;
break;
case V_686 :
F_284 ( V_649 | V_650 |
V_651 , L_243 ) ;
break;
case V_687 :
F_284 ( V_649 | V_650 |
V_651 , L_244 ) ;
break;
case V_688 :
F_284 ( V_649 | V_650 |
V_651 , L_245 ) ;
break;
case V_689 :
F_284 ( V_649 | V_650 |
V_651 , L_246 ) ;
break;
case V_690 :
F_284 ( V_649 | V_650 |
V_651 , L_247 ) ;
break;
case V_691 :
F_284 ( V_649 | V_650 |
V_651 , L_248 ) ;
break;
case V_692 :
F_284 ( V_649 | V_650 |
V_651 , L_249 ) ;
break;
case V_682 :
F_284 ( V_649 | V_650 |
V_651 , L_250 ) ;
break;
case V_666 :
F_284 ( V_649 | V_650 |
V_651 , L_251 ) ;
break;
default:
F_285 ( L_252 ,
V_679 -> V_665 ) ;
break;
}
break;
}
case V_693 : {
struct V_694 * T_11 =
& V_660 -> V_538 . V_695 ;
if ( V_15 == sizeof( * T_11 ) ) {
F_166 ( L_253 ,
T_11 -> V_696 ) ;
} else {
F_166 ( L_254
L_255 ,
V_15 , sizeof( * T_11 ) ) ;
}
break;
}
case V_697 : {
struct V_698 * T_11 = & V_660 -> V_538 . V_699 ;
if ( V_15 == sizeof( * T_11 ) ) {
F_166
( L_256
L_257 , T_11 -> V_700 ,
T_11 -> V_349 , T_11 -> V_37 ) ;
} else {
F_46 ( L_258
L_255 ,
V_15 , sizeof( * T_11 ) ) ;
}
V_23 -> V_37 &=
~ ( V_321 | V_319 ) ;
F_144 ( & V_23 -> V_486 ) ;
F_64 ( & V_23 -> V_322 ) ;
if ( V_23 -> V_37 & V_701 )
break;
V_23 -> V_163 -> V_702 ++ ;
#ifdef F_245
if ( V_23 -> V_163 -> V_513 == V_515 ) {
V_23 -> V_37 |= V_703 ;
F_56 ( & V_23 -> V_186 , 0 ) ;
break;
}
V_23 -> V_37 &= ~ V_703 ;
#endif
if ( V_23 -> V_37 & V_704 )
F_56 ( & V_23 -> V_187 , 0 ) ;
if ( ! ( V_23 -> V_37 & ( V_103 |
V_240 |
V_652 |
V_560 ) ) )
F_128 ( & V_23 -> V_333 ) ;
else if ( V_23 -> V_37 & V_652 ) {
if ( T_11 -> V_37 == V_705 )
F_128 ( & V_23 -> V_706 ) ;
else
V_23 -> V_37 &= ~ V_652 ;
} else if ( V_23 -> V_37 & V_707 )
F_56 ( & V_23 -> V_186 , 0 ) ;
else if ( V_23 -> V_59 & V_708
&& V_23 -> V_37 & V_103 )
F_56 ( & V_23 -> V_186 ,
F_129 ( V_192 ) ) ;
if ( T_11 -> V_37 == V_705 )
F_287 ( V_23 ) ;
break;
}
case V_709 : {
struct V_710 * T_11 = & V_660 -> V_538 . V_711 ;
if ( V_15 == sizeof( * T_11 ) )
F_46 ( L_259 ,
F_222 ( T_11 -> V_712 ) ) ;
else
F_46 ( L_260
L_255 ,
V_15 , sizeof( * T_11 ) ) ;
break;
}
case V_713 : {
struct V_714 * T_11 =
& V_660 -> V_538 . V_715 ;
if ( V_15 == sizeof( * T_11 ) ) {
F_284 ( V_649 | V_650 ,
L_261 ,
T_11 -> V_716 ,
T_11 -> V_717 ) ;
memcpy ( & V_23 -> V_718 , T_11 ,
sizeof( * T_11 ) ) ;
} else {
F_46 ( L_262
L_255 ,
V_15 , sizeof( * T_11 ) ) ;
}
break;
}
case V_719 : {
F_46 ( L_263 ) ;
if ( V_23 -> V_720
&& V_23 -> V_720 -> V_153 != V_721 )
F_46 ( L_264 ) ;
break;
}
case V_722 : {
struct V_723 * T_11 = & V_660 -> V_538 . V_724 ;
if ( V_15 != sizeof( * T_11 ) ) {
F_46
( L_265
L_266 , V_15 , sizeof( * T_11 ) ) ;
break;
}
if ( F_227 ( T_11 -> V_665 ) ==
V_725 )
F_283 ( V_23 ,
F_227 ( T_11 ->
V_726 ) ) ;
break;
}
case V_727 : {
struct V_728 * T_11 = & V_660 -> V_538 . V_729 ;
if ( V_15 == sizeof( * T_11 ) ) {
F_46 ( L_267
L_268 ,
T_11 -> V_730 , T_11 -> V_731 ,
T_11 -> V_732 ) ;
break;
}
F_46
( L_269 ,
V_15 , sizeof( * T_11 ) ) ;
break;
}
case V_733 : {
struct V_734 * T_11 = & V_660 -> V_538 . V_735 ;
if ( V_15 == sizeof( * T_11 ) ) {
memcpy ( & V_23 -> V_329 , T_11 , sizeof( * T_11 ) ) ;
F_74 ( L_270 ) ;
break;
}
F_46
( L_271 ,
V_15 , sizeof( * T_11 ) ) ;
break;
}
case V_736 : {
if ( V_15 == sizeof( T_3 ) ) {
V_23 -> V_582 =
F_273 ( V_23 -> V_582 ,
( T_2 ) ( F_227 ( V_660 -> V_538 . V_737 . V_25 ) & 0xff ) ,
V_738 ) ;
break;
}
F_46
( L_272 ,
V_15 , sizeof( T_3 ) ) ;
break;
}
default:
F_285 ( L_273
L_274 ,
V_660 -> V_661 , V_660 -> V_41 , V_15 ) ;
}
}
static int F_247 ( struct V_17 * V_23 )
{
int V_155 = 0 ;
int V_739 = 64 , V_740 = 8 ;
F_250 ( V_23 ) ;
V_155 = F_255 ( V_23 , & V_23 -> V_226 , V_740 ,
V_741 ,
V_742 ,
V_743 ,
V_744 ) ;
if ( V_155 ) {
F_46 ( L_275 ) ;
goto error;
}
V_155 = F_255 ( V_23 , & V_23 -> V_230 [ 0 ] , V_739 ,
V_745 ,
V_746 ,
V_747 , V_748 ) ;
if ( V_155 ) {
F_46 ( L_276 ) ;
goto error;
}
V_155 = F_255 ( V_23 , & V_23 -> V_230 [ 1 ] , V_739 ,
V_749 ,
V_750 ,
V_751 , V_752 ) ;
if ( V_155 ) {
F_46 ( L_277 ) ;
goto error;
}
V_155 = F_255 ( V_23 , & V_23 -> V_230 [ 2 ] , V_739 ,
V_753 ,
V_754 ,
V_755 , V_756 ) ;
if ( V_155 ) {
F_46 ( L_278 ) ;
goto error;
}
V_155 = F_255 ( V_23 , & V_23 -> V_230 [ 3 ] , V_739 ,
V_757 ,
V_758 ,
V_759 , V_760 ) ;
if ( V_155 ) {
F_46 ( L_279 ) ;
goto error;
}
V_23 -> V_761 = 0 ;
V_23 -> V_762 = 0 ;
return V_155 ;
error:
F_250 ( V_23 ) ;
return V_155 ;
}
static int F_143 ( struct V_17 * V_23 ,
struct V_531 * V_230 , int V_763 )
{
T_3 V_764 ;
int V_765 ;
struct V_523 * V_521 = & V_230 -> V_521 ;
V_764 = F_36 ( V_23 , V_521 -> V_529 ) ;
if ( V_764 >= V_521 -> V_526 ) {
F_46
( L_280 ,
V_764 , V_521 -> V_526 ) ;
goto V_766;
}
for (; V_521 -> V_524 != V_764 ;
V_521 -> V_524 = F_253 ( V_521 -> V_524 , V_521 -> V_526 ) ) {
F_257 ( V_23 , V_230 ) ;
V_23 -> V_592 ++ ;
}
V_766:
if ( ( F_252 ( V_521 ) > V_521 -> V_527 ) &&
( V_763 >= 0 ) )
F_295 ( V_23 -> V_167 ) ;
V_765 = V_521 -> V_525 - V_521 -> V_524 ;
if ( V_765 < 0 )
V_765 += V_521 -> V_526 ;
return V_765 ;
}
static int F_151 ( struct V_17 * V_23 , int V_720 , void * V_1 ,
int V_4 , int V_767 )
{
struct V_531 * V_230 = & V_23 -> V_226 ;
struct V_523 * V_521 = & V_230 -> V_521 ;
struct V_534 * V_768 ;
if ( F_252 ( V_521 ) < ( V_767 ? 1 : 2 ) ) {
F_46 ( L_281 ) ;
return - V_769 ;
}
V_768 = & V_230 -> V_533 [ V_521 -> V_525 ] ;
V_230 -> V_532 [ V_521 -> V_525 ] = NULL ;
memset ( V_768 , 0 , sizeof( * V_768 ) ) ;
V_768 -> V_535 . V_536 = V_537 ;
V_768 -> V_535 . V_770 = V_771 ;
V_23 -> V_772 ++ ;
V_768 -> V_538 . V_153 . V_400 = V_720 ;
V_768 -> V_538 . V_153 . V_415 = V_4 ;
memcpy ( V_768 -> V_538 . V_153 . V_142 , V_1 , V_4 ) ;
V_521 -> V_525 = F_253 ( V_521 -> V_525 , V_521 -> V_526 ) ;
F_35 ( V_23 , V_521 -> V_530 , V_521 -> V_525 ) ;
F_24 ( V_23 , 0x90 ) ;
return 0 ;
}
static void F_296 ( struct V_17 * V_23 )
{
struct V_495 * V_496 = V_23 -> V_496 ;
struct V_437 * V_438 ;
struct V_773 * V_774 ;
unsigned long V_41 ;
int V_506 ;
F_41 ( & V_496 -> V_98 , V_41 ) ;
V_506 = V_496 -> V_506 ;
while ( ( F_251 ( V_496 ) > 0 ) && ( V_496 -> V_507 ) ) {
V_438 = V_496 -> V_497 . V_775 ;
V_774 = F_212 ( V_438 , struct V_773 , V_442 ) ;
F_214 ( V_438 ) ;
F_35 ( V_23 , V_776 + V_496 -> V_506 * V_777 ,
V_774 -> V_502 ) ;
V_496 -> V_778 [ V_496 -> V_506 ] = V_774 ;
V_496 -> V_506 = ( V_496 -> V_506 + 1 ) % V_500 ;
V_496 -> V_507 -- ;
}
F_42 ( & V_496 -> V_98 , V_41 ) ;
if ( V_496 -> V_507 <= V_779 )
F_128 ( & V_23 -> V_780 ) ;
if ( V_506 != V_496 -> V_506 )
F_35 ( V_23 , V_781 , V_496 -> V_506 ) ;
}
static void F_248 ( void * V_3 )
{
struct V_17 * V_23 = V_3 ;
struct V_495 * V_496 = V_23 -> V_496 ;
struct V_437 * V_438 ;
struct V_773 * V_774 ;
unsigned long V_41 ;
F_41 ( & V_496 -> V_98 , V_41 ) ;
while ( ! F_297 ( & V_496 -> V_498 ) ) {
V_438 = V_496 -> V_498 . V_775 ;
V_774 = F_212 ( V_438 , struct V_773 , V_442 ) ;
V_774 -> V_501 = F_298 ( V_503 , V_139 ) ;
if ( ! V_774 -> V_501 ) {
F_4 ( V_782 L_282 ,
V_23 -> V_167 -> V_158 ) ;
break;
}
F_214 ( V_438 ) ;
V_774 -> V_502 =
F_299 ( V_23 -> V_477 , V_774 -> V_501 -> V_3 ,
V_503 , V_504 ) ;
F_215 ( & V_774 -> V_442 , & V_496 -> V_497 ) ;
V_496 -> V_507 ++ ;
}
F_42 ( & V_496 -> V_98 , V_41 ) ;
F_296 ( V_23 ) ;
}
static void F_300 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_780 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_248 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_249 ( struct V_17 * V_23 , struct V_495 * V_496 )
{
int V_7 ;
if ( ! V_496 )
return;
for ( V_7 = 0 ; V_7 < V_500 + V_499 ; V_7 ++ ) {
if ( V_496 -> V_473 [ V_7 ] . V_501 != NULL ) {
F_239 ( V_23 -> V_477 , V_496 -> V_473 [ V_7 ] . V_502 ,
V_503 , V_504 ) ;
F_240 ( V_496 -> V_473 [ V_7 ] . V_501 ) ;
}
}
F_87 ( V_496 ) ;
}
static struct V_495 * F_246 ( struct V_17 * V_23 )
{
struct V_495 * V_496 ;
int V_7 ;
V_496 = F_86 ( sizeof( * V_496 ) , V_148 ) ;
if ( F_29 ( ! V_496 ) ) {
F_46 ( L_283 ) ;
return NULL ;
}
F_301 ( & V_496 -> V_98 ) ;
F_238 ( & V_496 -> V_497 ) ;
F_238 ( & V_496 -> V_498 ) ;
for ( V_7 = 0 ; V_7 < V_499 + V_500 ; V_7 ++ )
F_215 ( & V_496 -> V_473 [ V_7 ] . V_442 , & V_496 -> V_498 ) ;
V_496 -> V_505 = V_496 -> V_506 = 0 ;
V_496 -> V_507 = 0 ;
return V_496 ;
}
static int F_302 ( struct V_17 * V_23 , int V_347 , T_2 V_609 )
{
V_609 &= ~ V_783 ;
if ( V_347 == V_119 ) {
switch ( V_609 ) {
case V_784 :
return V_23 -> V_594 & V_599 ?
1 : 0 ;
case V_785 :
return V_23 -> V_594 & V_600 ?
1 : 0 ;
case V_786 :
return V_23 ->
V_594 & V_602 ? 1 : 0 ;
case V_787 :
return V_23 ->
V_594 & V_603 ? 1 : 0 ;
case V_788 :
return V_23 ->
V_594 & V_604 ? 1 : 0 ;
case V_789 :
return V_23 ->
V_594 & V_605 ? 1 : 0 ;
case V_790 :
return V_23 ->
V_594 & V_606 ? 1 : 0 ;
case V_791 :
return V_23 ->
V_594 & V_607 ? 1 : 0 ;
default:
return 0 ;
}
}
switch ( V_609 ) {
case V_792 :
return V_23 -> V_594 & V_596 ? 1 : 0 ;
case V_793 :
return V_23 -> V_594 & V_597 ? 1 : 0 ;
case V_794 :
return V_23 -> V_594 & V_598 ? 1 : 0 ;
case V_795 :
return V_23 -> V_594 & V_601 ? 1 : 0 ;
}
if ( V_347 == V_608 )
return 0 ;
switch ( V_609 ) {
case V_784 :
return V_23 -> V_594 & V_599 ? 1 : 0 ;
case V_785 :
return V_23 -> V_594 & V_600 ? 1 : 0 ;
case V_786 :
return V_23 -> V_594 & V_602 ? 1 : 0 ;
case V_787 :
return V_23 -> V_594 & V_603 ? 1 : 0 ;
case V_788 :
return V_23 -> V_594 & V_604 ? 1 : 0 ;
case V_789 :
return V_23 -> V_594 & V_605 ? 1 : 0 ;
case V_790 :
return V_23 -> V_594 & V_606 ? 1 : 0 ;
case V_791 :
return V_23 -> V_594 & V_607 ? 1 : 0 ;
}
return 0 ;
}
static int F_303 ( struct V_17 * V_23 ,
const struct V_440 * V_441 ,
struct V_335 * V_336 )
{
int V_796 , V_7 ;
memset ( V_336 , 0 , sizeof( * V_336 ) ) ;
V_796 = F_3 ( V_441 -> V_797 , ( T_2 ) V_798 ) ;
V_336 -> V_796 = 0 ;
for ( V_7 = 0 ; V_7 < V_796 ; V_7 ++ ) {
if ( ! F_302 ( V_23 , V_441 -> V_118 ,
V_441 -> V_336 [ V_7 ] ) ) {
if ( V_441 -> V_336 [ V_7 ] & V_783 ) {
F_166 ( L_284
L_285 ,
V_441 -> V_336 [ V_7 ] ) ;
V_336 -> V_799 [ V_336 -> V_796 ++ ] =
V_441 -> V_336 [ V_7 ] ;
continue;
}
F_166 ( L_286 ,
V_441 -> V_336 [ V_7 ] , V_23 -> V_594 ) ;
continue;
}
V_336 -> V_799 [ V_336 -> V_796 ++ ] = V_441 -> V_336 [ V_7 ] ;
}
V_796 = F_3 ( V_441 -> V_800 ,
( T_2 ) ( V_798 - V_796 ) ) ;
for ( V_7 = 0 ; V_7 < V_796 ; V_7 ++ ) {
if ( ! F_302 ( V_23 , V_441 -> V_118 ,
V_441 -> V_801 [ V_7 ] ) ) {
if ( V_441 -> V_801 [ V_7 ] & V_783 ) {
F_166 ( L_284
L_285 ,
V_441 -> V_801 [ V_7 ] ) ;
V_336 -> V_799 [ V_336 -> V_796 ++ ] =
V_441 -> V_336 [ V_7 ] ;
continue;
}
F_166 ( L_286 ,
V_441 -> V_801 [ V_7 ] , V_23 -> V_594 ) ;
continue;
}
V_336 -> V_799 [ V_336 -> V_796 ++ ] =
V_441 -> V_801 [ V_7 ] ;
}
return 1 ;
}
static void F_304 ( struct V_335 * V_802 ,
const struct V_335 * V_803 )
{
T_2 V_7 ;
for ( V_7 = 0 ; V_7 < V_803 -> V_796 ; V_7 ++ )
V_802 -> V_799 [ V_7 ] = V_803 -> V_799 [ V_7 ] ;
V_802 -> V_796 = V_803 -> V_796 ;
}
static void F_305 ( struct V_335 * V_336 ,
T_2 V_804 , T_3 V_805 )
{
T_2 V_806 = ( V_807 == V_804 ) ?
V_783 : 0 ;
if ( V_805 & V_596 )
V_336 -> V_799 [ V_336 -> V_796 ++ ] =
V_783 | V_792 ;
if ( V_805 & V_597 )
V_336 -> V_799 [ V_336 -> V_796 ++ ] =
V_783 | V_793 ;
if ( V_805 & V_598 )
V_336 -> V_799 [ V_336 -> V_796 ++ ] = V_806 |
V_794 ;
if ( V_805 & V_601 )
V_336 -> V_799 [ V_336 -> V_796 ++ ] = V_806 |
V_795 ;
}
static void F_306 ( struct V_335 * V_336 ,
T_2 V_804 , T_3 V_805 )
{
T_2 V_806 = ( V_807 == V_804 ) ?
V_783 : 0 ;
if ( V_805 & V_599 )
V_336 -> V_799 [ V_336 -> V_796 ++ ] = V_806 |
V_784 ;
if ( V_805 & V_600 )
V_336 -> V_799 [ V_336 -> V_796 ++ ] =
V_785 ;
if ( V_805 & V_602 )
V_336 -> V_799 [ V_336 -> V_796 ++ ] = V_806 |
V_786 ;
if ( V_805 & V_603 )
V_336 -> V_799 [ V_336 -> V_796 ++ ] =
V_787 ;
if ( V_805 & V_604 )
V_336 -> V_799 [ V_336 -> V_796 ++ ] = V_806 |
V_788 ;
if ( V_805 & V_605 )
V_336 -> V_799 [ V_336 -> V_796 ++ ] =
V_789 ;
if ( V_805 & V_606 )
V_336 -> V_799 [ V_336 -> V_796 ++ ] =
V_790 ;
if ( V_805 & V_607 )
V_336 -> V_799 [ V_336 -> V_796 ++ ] =
V_791 ;
}
static int F_307 ( struct V_17 * V_23 ,
struct V_808 * V_809 ,
struct V_440 * V_441 ,
int V_654 )
{
struct V_335 V_336 ;
if ( ( V_23 -> V_163 -> V_513 == V_514 &&
! ( V_441 -> V_317 & V_318 ) ) ) {
F_308 ( L_287 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ) ;
return 0 ;
}
if ( F_29 ( V_654 ) ) {
if ( ( V_441 -> V_810 != V_809 -> V_441 -> V_810 ) ||
memcmp ( V_441 -> V_311 , V_809 -> V_441 -> V_311 ,
V_441 -> V_810 ) ) {
F_308 ( L_288 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ) ;
return 0 ;
}
} else {
if ( ( V_23 -> V_59 & V_811 ) &&
( ( V_441 -> V_810 != V_23 -> V_667 ) ||
memcmp ( V_441 -> V_311 , V_23 -> V_668 ,
F_3 ( V_441 -> V_810 , V_23 -> V_667 ) ) ) ) {
F_308 ( L_289 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 , V_23 -> V_667 ,
V_23 -> V_668 ) ;
return 0 ;
}
}
if ( V_441 -> V_467 [ 0 ] < V_809 -> V_441 -> V_467 [ 0 ] ) {
F_308 ( L_290 ,
V_809 -> V_441 -> V_810 , V_809 -> V_441 -> V_311 ) ;
return 0 ;
} else if ( V_441 -> V_467 [ 1 ] < V_809 -> V_441 -> V_467 [ 1 ] ) {
F_308 ( L_290 ,
V_809 -> V_441 -> V_810 , V_809 -> V_441 -> V_311 ) ;
return 0 ;
}
if ( V_23 -> V_163 -> V_164 != 0 &&
F_309 ( V_140 , V_441 -> V_812 + V_23 -> V_163 -> V_164 ) ) {
F_308 ( L_291 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ,
F_167 ( V_140 -
V_441 -> V_812 ) ) ;
return 0 ;
}
if ( ( V_23 -> V_59 & V_549 ) &&
( V_441 -> V_197 != V_23 -> V_197 ) ) {
F_308 ( L_292 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ,
V_441 -> V_197 , V_23 -> V_197 ) ;
return 0 ;
}
if ( ( ( V_23 -> V_317 & V_813 ) ? 1 : 0 ) !=
( ( V_441 -> V_317 & V_814 ) ? 1 : 0 ) ) {
F_308 ( L_293 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ,
V_23 ->
V_317 & V_813 ? L_294 : L_295 ,
V_441 ->
V_317 & V_814 ? L_294 :
L_295 ) ;
return 0 ;
}
if ( F_213 ( V_441 -> V_216 , V_23 -> V_216 ) ) {
F_308 ( L_296 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 , V_23 -> V_216 ) ;
return 0 ;
}
if ( ! F_310 ( V_23 -> V_163 , V_441 -> V_118 ) ) {
F_308 ( L_297 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ) ;
return 0 ;
}
if ( ! F_303 ( V_23 , V_441 , & V_336 ) ) {
F_308 ( L_298 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ) ;
return 0 ;
}
if ( V_336 . V_796 == 0 ) {
F_308 ( L_299 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ) ;
return 0 ;
}
F_304 ( & V_809 -> V_336 , & V_336 ) ;
V_809 -> V_441 = V_441 ;
F_308 ( L_300 ,
V_441 -> V_810 , V_441 -> V_311 , V_441 -> V_216 ) ;
return 1 ;
}
static void F_311 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_815 ) ;
struct V_440 * V_441 = NULL ;
struct V_808 V_809 = {
. V_441 = V_23 -> V_117
} ;
if ( ( V_23 -> V_37 & V_103 ) &&
( V_23 -> V_163 -> V_513 == V_514 ) ) {
unsigned long V_41 ;
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
F_312 (network, &priv->ieee->network_list, list) {
if ( V_441 != V_23 -> V_117 )
F_307 ( V_23 , & V_809 , V_441 ,
1 ) ;
}
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
if ( V_809 . V_441 == V_23 -> V_117 ) {
F_308 ( L_301
L_302 ) ;
return;
}
F_59 ( & V_23 -> V_109 ) ;
if ( ( V_23 -> V_163 -> V_513 == V_514 ) ) {
F_308 ( L_303 ,
V_23 -> V_667 , V_23 -> V_668 ) ;
F_162 ( V_23 ) ;
}
F_266 ( V_23 ) ;
V_23 -> V_117 = V_809 . V_441 ;
F_60 ( & V_23 -> V_109 ) ;
return;
}
}
static int F_313 ( struct V_17 * V_23 ,
struct V_808 * V_809 ,
struct V_440 * V_441 , int V_654 )
{
struct V_335 V_336 ;
if ( ( V_23 -> V_163 -> V_513 == V_516 &&
! ( V_441 -> V_317 & V_816 ) ) ||
( V_23 -> V_163 -> V_513 == V_514 &&
! ( V_441 -> V_317 & V_318 ) ) ) {
F_265 ( L_287 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ) ;
return 0 ;
}
if ( F_29 ( V_654 ) ) {
if ( ( V_441 -> V_810 != V_809 -> V_441 -> V_810 ) ||
memcmp ( V_441 -> V_311 , V_809 -> V_441 -> V_311 ,
V_441 -> V_810 ) ) {
F_265 ( L_288 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ) ;
return 0 ;
}
} else {
if ( ( V_23 -> V_59 & V_811 ) &&
( ( V_441 -> V_810 != V_23 -> V_667 ) ||
memcmp ( V_441 -> V_311 , V_23 -> V_668 ,
F_3 ( V_441 -> V_810 , V_23 -> V_667 ) ) ) ) {
F_265 ( L_289 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 , V_23 -> V_667 ,
V_23 -> V_668 ) ;
return 0 ;
}
}
if ( V_809 -> V_441 && V_809 -> V_441 -> V_674 . V_632 > V_441 -> V_674 . V_632 ) {
F_265 ( L_304 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 , V_809 -> V_441 -> V_810 ,
V_809 -> V_441 -> V_311 , V_809 -> V_441 -> V_216 ) ;
return 0 ;
}
if ( V_441 -> V_817 &&
F_309 ( V_441 -> V_817 + ( V_192 * 3UL ) , V_140 ) ) {
F_265 ( L_305 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ,
F_167 ( V_140 -
V_441 -> V_817 ) ) ;
return 0 ;
}
if ( V_23 -> V_163 -> V_164 != 0 &&
F_309 ( V_140 , V_441 -> V_812 + V_23 -> V_163 -> V_164 ) ) {
F_265 ( L_291 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ,
F_167 ( V_140 -
V_441 -> V_812 ) ) ;
return 0 ;
}
if ( ( V_23 -> V_59 & V_549 ) &&
( V_441 -> V_197 != V_23 -> V_197 ) ) {
F_265 ( L_292 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ,
V_441 -> V_197 , V_23 -> V_197 ) ;
return 0 ;
}
if ( ( ( V_23 -> V_317 & V_813 ) ? 1 : 0 ) !=
( ( V_441 -> V_317 & V_814 ) ? 1 : 0 ) ) {
F_265 ( L_293 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ,
V_23 -> V_317 & V_813 ? L_294 :
L_295 ,
V_441 -> V_317 &
V_814 ? L_294 : L_295 ) ;
return 0 ;
}
if ( ( V_23 -> V_59 & V_818 ) &&
! F_213 ( V_441 -> V_216 , V_23 -> V_216 ) ) {
F_265 ( L_306 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 , V_23 -> V_216 ) ;
return 0 ;
}
if ( ! F_310 ( V_23 -> V_163 , V_441 -> V_118 ) ) {
F_265 ( L_297 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ) ;
return 0 ;
}
if ( ! F_133 ( V_23 -> V_163 , V_441 -> V_197 ) ) {
F_265 ( L_307 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ) ;
return 0 ;
}
if ( ! F_303 ( V_23 , V_441 , & V_336 ) ) {
F_265 ( L_298 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ) ;
return 0 ;
}
if ( V_336 . V_796 == 0 ) {
F_265 ( L_299 ,
V_441 -> V_810 , V_441 -> V_311 ,
V_441 -> V_216 ) ;
return 0 ;
}
F_304 ( & V_809 -> V_336 , & V_336 ) ;
V_809 -> V_441 = V_441 ;
F_265 ( L_300 ,
V_441 -> V_810 , V_441 -> V_311 , V_441 -> V_216 ) ;
return 1 ;
}
static void F_314 ( struct V_17 * V_23 ,
struct V_440 * V_441 )
{
const struct V_201 * V_202 = F_137 ( V_23 -> V_163 ) ;
int V_7 ;
switch ( F_133 ( V_23 -> V_163 , V_23 -> V_197 ) ) {
case V_819 :
V_441 -> V_118 = V_119 ;
V_7 = F_315 ( V_23 -> V_163 , V_23 -> V_197 ) ;
F_226 ( V_7 == - 1 ) ;
if ( V_202 -> V_18 [ V_7 ] . V_41 & V_207 ) {
F_93 ( L_308 ) ;
V_23 -> V_197 = V_202 -> V_18 [ 0 ] . V_197 ;
}
break;
case V_820 :
if ( V_23 -> V_163 -> V_118 & V_121 )
V_441 -> V_118 = V_121 ;
else
V_441 -> V_118 = V_608 ;
V_7 = F_315 ( V_23 -> V_163 , V_23 -> V_197 ) ;
F_226 ( V_7 == - 1 ) ;
if ( V_202 -> V_204 [ V_7 ] . V_41 & V_207 ) {
F_93 ( L_308 ) ;
V_23 -> V_197 = V_202 -> V_204 [ 0 ] . V_197 ;
}
break;
default:
F_93 ( L_308 ) ;
if ( V_23 -> V_163 -> V_118 & V_119 ) {
V_441 -> V_118 = V_119 ;
V_23 -> V_197 = V_202 -> V_18 [ 0 ] . V_197 ;
} else if ( V_23 -> V_163 -> V_118 & V_121 ) {
V_441 -> V_118 = V_121 ;
V_23 -> V_197 = V_202 -> V_204 [ 0 ] . V_197 ;
} else {
V_441 -> V_118 = V_608 ;
V_23 -> V_197 = V_202 -> V_204 [ 0 ] . V_197 ;
}
break;
}
V_441 -> V_197 = V_23 -> V_197 ;
V_23 -> V_59 |= V_550 ;
F_261 ( V_23 , V_441 -> V_216 ) ;
V_441 -> V_810 = V_23 -> V_667 ;
memcpy ( V_441 -> V_311 , V_23 -> V_668 , V_23 -> V_667 ) ;
memset ( & V_441 -> V_674 , 0 , sizeof( V_441 -> V_674 ) ) ;
V_441 -> V_317 = V_318 ;
if ( ! ( V_23 -> V_59 & V_821 ) )
V_441 -> V_317 |= V_822 ;
if ( V_23 -> V_317 & V_813 )
V_441 -> V_317 |= V_814 ;
V_441 -> V_797 = F_3 ( V_23 -> V_336 . V_796 , V_823 ) ;
memcpy ( V_441 -> V_336 , V_23 -> V_336 . V_799 , V_441 -> V_797 ) ;
V_441 -> V_800 = V_23 -> V_336 . V_796 - V_441 -> V_797 ;
memcpy ( V_441 -> V_801 ,
& V_23 -> V_336 . V_799 [ V_441 -> V_797 ] ,
V_441 -> V_800 ) ;
V_441 -> V_812 = 0 ;
V_441 -> V_41 = 0 ;
V_441 -> V_817 = 0 ;
V_441 -> V_467 [ 0 ] = 0 ;
V_441 -> V_467 [ 1 ] = 0 ;
V_441 -> V_640 = 100 ;
V_441 -> V_824 = 10 ;
V_441 -> V_825 = 0 ;
V_441 -> V_826 = 0 ;
V_441 -> V_827 = 0 ;
}
static void F_316 ( struct V_17 * V_23 , int type , int V_400 )
{
struct V_828 V_829 ;
if ( ! ( V_23 -> V_163 -> V_244 . V_41 & ( 1 << V_400 ) ) )
return;
V_829 . V_830 = V_400 ;
memcpy ( V_829 . V_829 , V_23 -> V_163 -> V_244 . V_831 [ V_400 ] , V_832 ) ;
V_829 . V_731 = type ;
V_829 . V_732 = 0 ;
V_829 . V_41 = 0 ;
V_829 . V_833 [ 0 ] = F_179 ( 0 ) ;
V_829 . V_833 [ 1 ] = F_179 ( 0 ) ;
F_155 ( V_23 , V_834 , sizeof( V_829 ) , & V_829 ) ;
}
static void F_317 ( struct V_17 * V_23 , int type )
{
struct V_835 V_829 ;
int V_7 ;
V_829 . V_836 = V_837 ;
V_829 . V_838 = 0 ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_829 . V_839 = V_7 | type ;
if ( ! ( V_23 -> V_163 -> V_244 . V_41 & ( 1 << V_7 ) ) ) {
V_829 . V_840 = 0 ;
continue;
}
V_829 . V_840 = V_23 -> V_163 -> V_244 . V_841 [ V_7 ] ;
memcpy ( V_829 . V_829 , V_23 -> V_163 -> V_244 . V_831 [ V_7 ] , V_829 . V_840 ) ;
F_155 ( V_23 , V_302 , sizeof( V_829 ) , & V_829 ) ;
}
}
static void F_318 ( struct V_17 * V_23 , int V_11 )
{
if ( V_23 -> V_163 -> V_842 )
return;
switch ( V_11 ) {
case V_843 :
V_23 -> V_310 . V_844 = 0 ;
V_23 -> V_163 -> V_845 = 0 ;
break;
case V_846 :
V_23 -> V_310 . V_844 = 1 ;
V_23 -> V_163 -> V_845 = 1 ;
break;
case V_847 :
V_23 -> V_310 . V_844 = 0 ;
V_23 -> V_163 -> V_845 = 0 ;
break;
case V_848 :
V_23 -> V_310 . V_844 = 1 ;
break;
default:
break;
}
}
static void F_319 ( struct V_17 * V_23 , int V_11 )
{
if ( V_23 -> V_163 -> V_842 )
return;
switch ( V_11 ) {
case V_843 :
V_23 -> V_310 . V_849 = 0 ;
break;
case V_846 :
V_23 -> V_310 . V_849 = 1 ;
break;
case V_847 :
V_23 -> V_310 . V_849 = 0 ;
break;
case V_848 :
V_23 -> V_310 . V_849 = 1 ;
break;
default:
break;
}
}
static void F_320 ( struct V_17 * V_23 )
{
switch ( V_23 -> V_163 -> V_244 . V_11 ) {
case V_843 :
if ( V_23 -> V_163 -> V_244 . V_41 & V_850 )
F_316 ( V_23 ,
V_851 ,
V_23 -> V_163 -> V_244 . V_852 ) ;
if ( ! V_23 -> V_163 -> V_853 )
F_317 ( V_23 , V_854 ) ;
break;
case V_846 :
if ( V_23 -> V_163 -> V_244 . V_41 & V_850 )
F_316 ( V_23 ,
V_855 ,
V_23 -> V_163 -> V_244 . V_852 ) ;
break;
case V_847 :
F_317 ( V_23 , V_856 ) ;
F_318 ( V_23 , V_23 -> V_163 -> V_244 . V_11 ) ;
F_319 ( V_23 , V_23 -> V_163 -> V_244 . V_11 ) ;
break;
case V_848 :
default:
break;
}
}
static void F_321 ( void * V_3 )
{
struct V_17 * V_23 = V_3 ;
if ( V_23 -> V_548 ++ > V_23 -> V_647 &&
! ( V_23 -> V_59 & V_550 ) ) {
F_284 ( V_648 | V_649 |
V_650 | V_651 ,
L_223 ,
V_23 -> V_548 ) ;
F_162 ( V_23 ) ;
F_266 ( V_23 ) ;
return;
}
F_56 ( & V_23 -> V_669 ,
F_222 ( V_23 -> V_559 . V_640 ) ) ;
}
static void F_322 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_669 . V_107 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_321 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_323 ( struct V_17 * V_23 )
{
F_74 ( L_309
L_310 , V_23 -> V_59 ) ;
if ( V_23 -> V_59 & V_549 )
F_74 ( L_311 , V_23 -> V_197 ) ;
else
F_74 ( L_312 ) ;
if ( V_23 -> V_59 & V_811 )
F_74 ( L_313 ,
V_23 -> V_667 , V_23 -> V_668 ) ;
else
F_74 ( L_314 ) ;
if ( V_23 -> V_59 & V_818 )
F_74 ( L_315 , V_23 -> V_216 ) ;
else
F_74 ( L_316 ) ;
if ( V_23 -> V_317 & V_813 )
F_74 ( L_317 ) ;
else
F_74 ( L_318 ) ;
F_74 ( L_319 , V_23 -> V_594 ) ;
}
static void F_324 ( struct V_17 * V_23 , int V_118 )
{
struct V_857 V_858 ;
T_3 V_24 ;
T_4 V_36 = 0 ;
T_4 V_859 = V_23 -> V_594 ;
switch ( V_23 -> V_163 -> V_860 ) {
case V_819 :
if ( V_23 -> V_594 & ~ V_861 ) {
F_325
( L_320 ) ;
V_859 = 0 ;
break;
}
V_859 >>= V_862 ;
break;
default:
if ( V_118 == V_608 ) {
if ( V_859 & ~ V_595 ) {
F_325
( L_320 ) ;
V_859 = 0 ;
}
break;
}
if ( V_859 & ~ ( V_595 |
V_861 ) ) {
F_325
( L_320 ) ;
V_859 = 0 ;
break;
}
if ( V_599 & V_859 ) {
V_36 |= ( V_599 >> 1 ) ;
V_859 &= ~ V_599 ;
}
if ( V_600 & V_859 ) {
V_36 |= ( V_600 >> 1 ) ;
V_859 &= ~ V_600 ;
}
if ( V_602 & V_859 ) {
V_36 |= ( V_602 >> 1 ) ;
V_859 &= ~ V_602 ;
}
V_859 |= V_36 ;
break;
}
V_858 . V_863 = F_173 ( V_859 ) ;
V_24 = F_36 ( V_23 , V_864 ) ;
F_12 ( V_23 , V_24 , * ( T_3 * ) & V_858 ) ;
}
static void F_168 ( struct V_17 * V_23 )
{
int V_557 ;
if ( V_23 -> V_37 & V_319 ) {
F_142 ( L_321 ) ;
return;
}
V_23 -> V_37 |= V_319 ;
V_557 = F_171 ( V_23 ) ;
if ( V_557 )
F_142 ( L_322 ) ;
}
static void F_326 ( struct V_17 * V_23 ,
struct V_323 * V_865 ,
int V_700 )
{
int V_866 = 0 ;
const struct V_201 * V_202 ;
int V_7 ;
V_202 = F_137 ( V_23 -> V_163 ) ;
if ( V_23 -> V_163 -> V_860 & V_819 ) {
int V_389 = V_866 ;
for ( V_7 = 0 ; V_7 < V_202 -> V_209 ; V_7 ++ ) {
if ( ( V_23 -> V_37 & V_103 ) &&
V_202 -> V_18 [ V_7 ] . V_197 == V_23 -> V_197 )
continue;
V_866 ++ ;
V_865 -> V_867 [ V_866 ] = V_202 -> V_18 [ V_7 ] . V_197 ;
F_327 ( V_865 , V_866 ,
V_202 -> V_18 [ V_7 ] .
V_41 & V_207 ?
V_868 :
V_700 ) ;
}
if ( V_389 != V_866 ) {
V_865 -> V_867 [ V_389 ] = ( T_2 ) ( V_354 << 6 ) |
( V_866 - V_389 ) ;
V_866 ++ ;
}
}
if ( V_23 -> V_163 -> V_860 & V_820 ) {
int V_389 = V_866 ;
if ( V_23 -> V_59 & V_195 ) {
int V_400 ;
T_2 V_869 [ V_870 ] = {
[ 0 ] = 0
} ;
T_2 V_197 ;
while ( V_866 < V_871 - 1 ) {
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
if ( V_869 [ V_197 - 1 ] != 0 )
break;
V_869 [ V_197 - 1 ] = 1 ;
V_23 -> V_199 ++ ;
V_866 ++ ;
V_865 -> V_867 [ V_866 ] = V_197 ;
V_400 =
F_315 ( V_23 -> V_163 , V_197 ) ;
F_327 ( V_865 , V_866 ,
V_202 -> V_204 [ V_400 ] .
V_41 &
V_207 ?
V_868
: V_700 ) ;
}
} else {
for ( V_7 = 0 ; V_7 < V_202 -> V_203 ; V_7 ++ ) {
if ( ( V_23 -> V_37 & V_103 ) &&
V_202 -> V_204 [ V_7 ] . V_197 == V_23 -> V_197 )
continue;
V_866 ++ ;
V_865 -> V_867 [ V_866 ] =
V_202 -> V_204 [ V_7 ] . V_197 ;
F_327 ( V_865 , V_866 ,
V_202 -> V_204 [ V_7 ] .
V_41 &
V_207 ?
V_868
: V_700 ) ;
}
}
if ( V_389 != V_866 ) {
V_865 -> V_867 [ V_389 ] = ( T_2 ) ( V_352 << 6 ) |
( V_866 - V_389 ) ;
}
}
}
static int F_328 ( struct V_17 * V_23 )
{
if ( V_23 -> V_37 & V_103
&& V_23 -> V_117 -> V_640 > 10 )
return V_23 -> V_117 -> V_640 - 10 ;
else
return 120 ;
}
static int F_329 ( struct V_17 * V_23 , int type , int V_872 )
{
struct V_323 V_865 ;
int V_557 = 0 , V_700 ;
if ( ! ( V_23 -> V_37 & V_69 ) ||
( V_23 -> V_37 & V_701 ) )
return 0 ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_872 && ( V_23 -> V_873 == 0 ) ) {
F_142 ( L_323 ) ;
V_23 -> V_37 &= ~ V_704 ;
goto V_766;
}
if ( V_23 -> V_37 & V_321 ) {
F_142 ( L_324 ) ;
V_23 -> V_37 |= V_872 ? V_704 :
V_707 ;
goto V_766;
}
if ( ! ( V_23 -> V_37 & V_703 ) &&
V_23 -> V_37 & V_319 ) {
F_142 ( L_325 ) ;
V_23 -> V_37 |= V_872 ? V_704 :
V_707 ;
goto V_766;
}
if ( V_23 -> V_37 & V_99 ) {
F_142 ( L_326 ) ;
V_23 -> V_37 |= V_872 ? V_704 :
V_707 ;
goto V_766;
}
memset ( & V_865 , 0 , sizeof( V_865 ) ) ;
V_865 . V_874 = F_179 ( F_330 ( V_23 -> V_163 ) ) ;
if ( type == V_875 ) {
F_325 ( L_327 ) ;
V_700 = V_868 ;
V_865 . V_876 [ V_868 ] =
F_173 ( F_328 ( V_23 ) ) ;
F_326 ( V_23 , & V_865 , V_700 ) ;
goto V_877;
}
if ( V_23 -> V_59 & V_195 )
V_865 . V_876 [ V_878 ] =
F_173 ( 30 ) ;
else
V_865 . V_876 [ V_878 ] =
F_173 ( 20 ) ;
V_865 . V_876 [ V_879 ] =
F_173 ( 20 ) ;
V_865 . V_876 [ V_868 ] =
F_173 ( F_328 ( V_23 ) ) ;
V_865 . V_876 [ V_880 ] = F_173 ( 20 ) ;
#ifdef F_245
if ( V_23 -> V_163 -> V_513 == V_515 ) {
T_2 V_197 ;
T_2 V_881 = 0 ;
switch ( F_133 ( V_23 -> V_163 , V_23 -> V_197 ) ) {
case V_819 :
V_881 = ( T_2 ) ( V_354 << 6 ) | 1 ;
V_197 = V_23 -> V_197 ;
break;
case V_820 :
V_881 = ( T_2 ) ( V_352 << 6 ) | 1 ;
V_197 = V_23 -> V_197 ;
break;
default:
V_881 = ( T_2 ) ( V_352 << 6 ) | 1 ;
V_197 = 9 ;
break;
}
V_865 . V_867 [ 0 ] = V_881 ;
V_865 . V_867 [ 1 ] = V_197 ;
F_327 ( & V_865 , 1 , V_868 ) ;
V_865 . V_876 [ V_868 ] =
F_173 ( 2000 ) ;
} else {
#endif
if ( V_872 ) {
V_557 = F_158 ( V_23 , V_23 -> V_882 ,
V_23 -> V_873 ) ;
if ( V_557 ) {
F_142 ( L_328
L_329 ) ;
goto V_766;
}
V_700 = V_879 ;
} else if ( ( V_23 -> V_37 & V_652 )
|| ( ! ( V_23 -> V_37 & V_103 )
&& ( V_23 -> V_59 & V_811 )
&& ( F_227 ( V_865 . V_874 ) % 2 ) ) ) {
V_557 = F_158 ( V_23 , V_23 -> V_668 , V_23 -> V_667 ) ;
if ( V_557 ) {
F_142 ( L_330
L_65 ) ;
goto V_766;
}
V_700 = V_879 ;
} else
V_700 = V_878 ;
F_326 ( V_23 , & V_865 , V_700 ) ;
#ifdef F_245
}
#endif
V_877:
V_557 = F_170 ( V_23 , & V_865 ) ;
if ( V_557 ) {
F_142 ( L_331 , V_557 ) ;
goto V_766;
}
V_23 -> V_37 |= V_321 ;
if ( V_872 ) {
V_23 -> V_37 &= ~ V_704 ;
V_23 -> V_873 = 0 ;
} else
V_23 -> V_37 &= ~ V_707 ;
F_56 ( & V_23 -> V_322 , V_320 ) ;
V_766:
F_60 ( & V_23 -> V_109 ) ;
return V_557 ;
}
static void F_331 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_188 . V_107 ) ;
F_329 ( V_23 , V_875 , 0 ) ;
}
static void F_332 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_186 . V_107 ) ;
F_329 ( V_23 , V_883 , 0 ) ;
}
static void F_333 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_187 . V_107 ) ;
F_329 ( V_23 , V_883 , 1 ) ;
}
static void F_334 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_653 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_168 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int F_335 ( struct V_17 * V_23 , int V_25 )
{
V_23 -> V_163 -> V_884 = V_25 ;
return 0 ;
}
static int F_336 ( struct V_17 * V_23 , int V_25 )
{
struct V_885 * V_163 = V_23 -> V_163 ;
struct V_886 V_244 = {
. V_41 = V_887 ,
} ;
int V_432 = 0 ;
if ( V_25 & V_888 ) {
V_244 . V_889 = V_890 ;
V_163 -> V_891 = 0 ;
} else if ( V_25 & V_892 ) {
V_244 . V_889 = V_893 ;
V_163 -> V_891 = 1 ;
} else if ( V_25 & V_894 ) {
V_244 . V_889 = V_895 ;
V_163 -> V_891 = 1 ;
} else
return - V_75 ;
if ( V_163 -> V_896 )
V_163 -> V_896 ( V_163 -> V_166 , & V_244 ) ;
else
V_432 = - V_897 ;
return V_432 ;
}
static void F_337 ( struct V_17 * V_23 , char * V_898 ,
int V_826 )
{
F_335 ( V_23 , 1 ) ;
}
static int F_338 ( struct V_17 * V_23 ,
char * V_899 , int V_415 )
{
F_142 ( L_332 ) ;
return F_155 ( V_23 , V_900 , V_415 ,
V_899 ) ;
}
static int F_339 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
struct V_885 * V_163 = V_23 -> V_163 ;
T_2 * V_1 ;
int V_557 = 0 ;
if ( V_211 -> V_3 . V_415 > V_904 ||
( V_211 -> V_3 . V_415 && V_903 == NULL ) )
return - V_75 ;
if ( V_211 -> V_3 . V_415 ) {
V_1 = F_341 ( V_903 , V_211 -> V_3 . V_415 , V_148 ) ;
if ( V_1 == NULL ) {
V_557 = - V_476 ;
goto V_6;
}
F_87 ( V_163 -> V_898 ) ;
V_163 -> V_898 = V_1 ;
V_163 -> V_826 = V_211 -> V_3 . V_415 ;
} else {
F_87 ( V_163 -> V_898 ) ;
V_163 -> V_898 = NULL ;
V_163 -> V_826 = 0 ;
}
F_337 ( V_23 , V_163 -> V_898 , V_163 -> V_826 ) ;
V_6:
return V_557 ;
}
static int F_342 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
struct V_885 * V_163 = V_23 -> V_163 ;
int V_557 = 0 ;
if ( V_163 -> V_826 == 0 || V_163 -> V_898 == NULL ) {
V_211 -> V_3 . V_415 = 0 ;
goto V_6;
}
if ( V_211 -> V_3 . V_415 < V_163 -> V_826 ) {
V_557 = - V_905 ;
goto V_6;
}
V_211 -> V_3 . V_415 = V_163 -> V_826 ;
memcpy ( V_903 , V_163 -> V_898 , V_163 -> V_826 ) ;
V_6:
return V_557 ;
}
static int F_343 ( int V_906 )
{
switch ( V_906 ) {
case V_907 :
return V_848 ;
case V_908 :
case V_909 :
return V_847 ;
case V_910 :
return V_846 ;
case V_911 :
return V_843 ;
default:
return - 1 ;
}
}
static int F_344 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
struct V_885 * V_163 = V_23 -> V_163 ;
struct V_912 * V_154 = & V_211 -> V_154 ;
struct V_913 * V_914 ;
unsigned long V_41 ;
int V_432 = 0 ;
switch ( V_154 -> V_41 & V_915 ) {
case V_916 :
break;
case V_917 :
F_318 ( V_23 ,
F_343 ( V_154 -> V_25 ) ) ;
break;
case V_918 :
F_319 ( V_23 ,
F_343 ( V_154 -> V_25 ) ) ;
break;
case V_919 :
break;
case V_920 :
V_914 = V_23 -> V_163 -> V_921 . V_914 [ V_23 -> V_163 -> V_921 . V_922 ] ;
if ( ! V_914 || ! V_914 -> V_923 -> V_924 || ! V_914 -> V_923 -> V_925 )
break;
V_41 = V_914 -> V_923 -> V_925 ( V_914 -> V_23 ) ;
if ( V_154 -> V_25 )
V_41 |= V_926 ;
else
V_41 &= ~ V_926 ;
V_914 -> V_923 -> V_924 ( V_41 , V_914 -> V_23 ) ;
break;
case V_927 : {
struct V_886 V_244 = {
. V_41 = V_928 ,
. V_929 = V_154 -> V_25 ,
} ;
V_23 -> V_163 -> V_930 = V_154 -> V_25 ;
if ( ! V_154 -> V_25 ) {
V_244 . V_41 |= V_931 ;
V_244 . V_11 = V_848 ;
} else {
V_244 . V_41 |= V_931 ;
V_244 . V_11 = V_847 ;
}
if ( V_23 -> V_163 -> V_896 )
V_23 -> V_163 -> V_896 ( V_23 -> V_163 -> V_166 , & V_244 ) ;
break;
}
case V_932 :
V_432 = F_336 ( V_23 , V_154 -> V_25 ) ;
break;
case V_933 :
V_432 = F_335 ( V_23 , V_154 -> V_25 ) ;
F_266 ( V_23 ) ;
break;
case V_934 :
V_163 -> V_935 = V_154 -> V_25 ;
break;
case V_936 :
V_163 -> V_937 = V_154 -> V_25 ;
break;
default:
return - V_897 ;
}
return V_432 ;
}
static int F_345 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
struct V_885 * V_163 = V_23 -> V_163 ;
struct V_913 * V_914 ;
struct V_912 * V_154 = & V_211 -> V_154 ;
switch ( V_154 -> V_41 & V_915 ) {
case V_916 :
case V_917 :
case V_918 :
case V_919 :
return - V_897 ;
case V_920 :
V_914 = V_23 -> V_163 -> V_921 . V_914 [ V_23 -> V_163 -> V_921 . V_922 ] ;
if ( ! V_914 || ! V_914 -> V_923 -> V_925 )
break;
V_154 -> V_25 = ( V_914 -> V_923 -> V_925 ( V_914 -> V_23 ) &
V_926 ) ? 1 : 0 ;
break;
case V_927 :
V_154 -> V_25 = V_163 -> V_930 ;
break;
case V_932 :
V_154 -> V_25 = V_163 -> V_244 . V_889 ;
break;
case V_933 :
V_154 -> V_25 = V_163 -> V_884 ;
break;
case V_934 :
V_154 -> V_25 = V_163 -> V_935 ;
break;
case V_938 :
case V_936 :
V_154 -> V_25 = V_163 -> V_937 ;
break;
default:
return - V_897 ;
}
return 0 ;
}
static int F_346 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
struct V_939 * V_940 = (struct V_939 * ) V_903 ;
if ( V_941 ) {
if ( V_940 -> V_942 == V_943 ) {
if ( V_940 -> V_944 & V_945 )
V_23 -> V_163 -> V_853 = 1 ;
else {
V_23 -> V_163 -> V_842 = 0 ;
V_23 -> V_163 -> V_946 = 1 ;
V_23 -> V_163 -> V_845 = 1 ;
}
} else {
V_23 -> V_163 -> V_842 = 0 ;
V_23 -> V_163 -> V_946 = 0 ;
V_23 -> V_163 -> V_845 = 0 ;
V_23 -> V_163 -> V_853 = 0 ;
}
}
return F_347 ( V_23 -> V_163 , V_902 , V_211 , V_903 ) ;
}
static int F_348 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
return F_349 ( V_23 -> V_163 , V_902 , V_211 , V_903 ) ;
}
static int F_350 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
struct V_947 * V_948 = (struct V_947 * ) V_903 ;
T_8 V_570 ;
V_570 = F_173 ( V_948 -> V_949 ) ;
switch ( V_948 -> V_153 ) {
case V_950 :
break;
case V_951 :
F_266 ( V_23 ) ;
break;
default:
return - V_897 ;
}
return 0 ;
}
static T_2 F_351 ( struct V_17 * V_23 )
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
F_293 ( L_333 , V_118 ) ;
return V_118 ;
}
static int F_352 ( struct V_17 * V_23 ,
int V_952 ,
struct V_440 * V_441 )
{
T_3 V_15 = sizeof( struct V_953 ) ;
if ( V_441 -> V_317 & V_318 )
V_441 -> V_954 . V_955 = V_441 -> V_954 . V_956 ;
if ( V_441 -> V_41 & V_957 ) {
if ( V_952 &&
( V_441 -> V_41 & V_958 ) )
V_441 -> V_954 . V_955 = V_441 -> V_954 . V_956 ;
if ( ( V_441 -> V_954 . V_955 == 1 ) && ( V_952 == 1 ) &&
( V_441 -> V_41 & V_958 ) &&
( V_441 -> V_954 . V_959 !=
V_441 -> V_954 . V_960 ) ) {
V_441 -> V_954 . V_959 =
V_441 -> V_954 . V_960 ;
F_128 ( & V_23 -> V_961 ) ;
F_293 ( L_334
L_335 ) ;
}
} else {
if ( ( V_23 -> V_163 -> V_118 == V_608 ) || ( V_441 -> V_118 == V_608 ) )
memcpy ( & V_441 -> V_954 . V_962 ,
& V_963 , V_15 ) ;
else
memcpy ( & V_441 -> V_954 . V_962 ,
& V_964 , V_15 ) ;
if ( ( V_441 -> V_954 . V_955 == 1 ) && ( V_952 == 1 ) ) {
F_293 ( L_336 ) ;
F_128 ( & V_23 -> V_961 ) ;
}
V_441 -> V_954 . V_955 = 0 ;
V_441 -> V_954 . V_956 = 0 ;
}
if ( ( V_23 -> V_37 & V_103 ) &&
( V_23 -> V_163 -> V_513 == V_514 ) && ( V_952 == 0 ) ) {
if ( ! F_213 ( V_441 -> V_216 , V_23 -> V_216 ) )
if ( V_441 -> V_317 & V_318 )
if ( ( V_441 -> V_810 ==
V_23 -> V_117 -> V_810 ) &&
! memcmp ( V_441 -> V_311 ,
V_23 -> V_117 -> V_311 ,
V_441 -> V_810 ) ) {
F_128 ( & V_23 -> V_815 ) ;
}
}
return 0 ;
}
static int F_353 ( struct V_17 * V_23 ,
struct V_965 * V_966 )
{
int V_557 ;
struct V_953 V_967 [ V_968 ] ;
struct V_953 * V_969 = NULL ;
T_3 V_15 = sizeof( struct V_953 ) ;
T_3 V_970 ;
int V_7 ;
T_2 type ;
type = F_351 ( V_23 ) ;
V_969 = & ( V_967 [ V_971 ] ) ;
memcpy ( V_969 , V_23 -> V_954 . V_972 , V_15 ) ;
V_969 = & ( V_967 [ V_973 ] ) ;
memcpy ( V_969 , V_23 -> V_954 . V_974 , V_15 ) ;
if ( V_966 == NULL ) {
if ( type == V_608 ) {
F_293 ( L_337 , type ) ;
V_969 = & V_963 ;
} else
V_969 = & V_964 ;
memcpy ( & V_967 [ V_975 ] , V_969 , V_15 ) ;
V_970 = F_354 ( V_23 ) ;
for ( V_7 = 0 ; V_7 < V_976 ; V_7 ++ )
V_967 [ V_975 ] . V_977 [ V_7 ] =
F_173 ( V_970 ) ;
} else if ( V_23 -> V_163 -> V_513 == V_514 ) {
if ( type == V_608 ) {
F_293 ( L_338 ,
type ) ;
if ( V_23 -> V_954 . V_978 == 0 )
V_969 = & V_963 ;
else
V_969 = V_23 -> V_954 . V_972 ;
} else {
if ( V_23 -> V_954 . V_978 == 0 )
V_969 = & V_964 ;
else
V_969 = V_23 -> V_954 . V_974 ;
}
memcpy ( & V_967 [ V_975 ] , V_969 , V_15 ) ;
} else {
unsigned long V_41 ;
int V_955 ;
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
V_969 = & ( V_966 -> V_962 ) ;
V_966 -> V_959 =
V_966 -> V_960 ;
memcpy ( & V_967 [ V_975 ] , V_969 , V_15 ) ;
V_955 = V_966 -> V_956 ;
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
if ( V_955 == 0 ) {
V_970 = F_354 ( V_23 ) ;
for ( V_7 = 0 ; V_7 < V_976 ; V_7 ++ )
V_967 [ V_975 ] .
V_977 [ V_7 ] = F_173 ( V_970 ) ;
}
}
F_293 ( L_339 ) ;
V_557 = F_355 ( V_23 , & V_967 [ 0 ] ) ;
if ( V_557 )
F_293 ( L_340 ) ;
return V_557 ;
}
static int F_356 ( struct V_17 * V_23 )
{
int V_432 = 0 ;
struct V_979 V_980 ;
if ( V_23 == NULL )
return - 1 ;
V_980 . V_981 = V_982 ;
V_980 . V_415 = sizeof( struct V_979 ) - 2 ;
V_980 . V_983 = V_984 ;
V_980 . V_985 = 0 ;
memcpy ( V_980 . V_986 , V_987 , V_988 ) ;
V_980 . V_989 = V_990 ;
V_980 . V_991 = V_992 ;
V_432 = F_357 ( V_23 , & V_980 ) ;
if ( V_432 != 0 ) {
F_293 ( L_341 ) ;
}
return V_432 ;
}
static int F_358 ( struct V_17 * V_23 ,
struct V_440 * V_441 )
{
int V_557 = 0 ;
struct V_965 * V_954 = NULL ;
struct V_965 V_993 = {
. V_956 = 1 ,
. V_955 = 1 ,
} ;
switch ( V_23 -> V_163 -> V_513 ) {
case V_514 :
F_226 ( ! ( V_441 -> V_317 & V_318 ) ) ;
V_954 = & V_993 ;
break;
case V_516 :
V_954 = & V_441 -> V_954 ;
break;
default:
F_359 () ;
break;
}
V_557 = F_353 ( V_23 , V_954 ) ;
if ( V_557 ) {
V_23 -> V_559 . V_994 &= ~ V_995 ;
return V_557 ;
}
if ( V_23 -> V_954 . V_978 && V_954 -> V_956 ) {
F_293 ( L_342 ) ;
V_23 -> V_559 . V_994 |= V_995 ;
return F_356 ( V_23 ) ;
}
return 0 ;
}
static int F_360 ( struct V_17 * V_23 ,
struct V_440 * V_441 )
{
int V_432 = 0 ;
unsigned long V_41 ;
T_3 V_15 = sizeof( struct V_953 ) ;
int V_996 = 0 ;
if ( ( V_23 == NULL ) || ( V_441 == NULL ) ||
( V_23 -> V_117 == NULL ) )
return V_432 ;
if ( ! ( V_23 -> V_37 & V_103 ) )
return V_432 ;
if ( ( V_23 -> V_163 -> V_513 != V_516 ) )
return V_432 ;
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
if ( V_441 -> V_41 & V_958 ) {
memcpy ( & V_23 -> V_117 -> V_954 , & V_441 -> V_954 ,
sizeof( struct V_965 ) ) ;
V_23 -> V_117 -> V_954 . V_955 = 1 ;
if ( ( V_441 -> V_954 . V_959 !=
V_441 -> V_954 . V_960 ) ) {
V_996 = 1 ;
V_441 -> V_954 . V_959 =
V_441 -> V_954 . V_960 ;
}
} else {
if ( ( V_441 -> V_118 == V_608 ) || ( V_23 -> V_163 -> V_118 == V_608 ) )
memcpy ( & V_23 -> V_117 -> V_954 . V_962 ,
& V_963 , V_15 ) ;
else
memcpy ( & V_23 -> V_117 -> V_954 . V_962 ,
& V_964 , V_15 ) ;
V_23 -> V_117 -> V_954 . V_955 = 0 ;
V_23 -> V_117 -> V_954 . V_956 = 0 ;
V_996 = 1 ;
}
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
if ( V_996 == 1 )
F_128 ( & V_23 -> V_961 ) ;
return V_432 ;
}
static T_3 F_354 ( struct V_17 * V_23 )
{
T_3 V_432 = 0 ;
if ( ( V_23 == NULL ) )
return 0 ;
if ( ! ( V_23 -> V_163 -> V_804 & V_807 ) )
V_432 = V_23 -> V_954 . V_997 ;
else
V_432 = V_23 -> V_954 . V_998 ;
return V_432 ;
}
static void F_361 ( struct V_17 * V_23 , int V_999 ,
int V_1000 , T_3 V_997 ,
T_3 V_998 )
{
V_23 -> V_954 . V_978 = V_999 ;
if ( V_23 -> V_954 . V_978 ) {
V_23 -> V_954 . V_972 = & V_1001 ;
V_23 -> V_954 . V_974 = & V_1002 ;
F_293 ( L_343 ) ;
} else {
V_23 -> V_954 . V_972 = & V_963 ;
V_23 -> V_954 . V_974 = & V_964 ;
F_293 ( L_344 ) ;
}
V_23 -> V_954 . V_1000 = V_1000 ;
if ( V_1000 ) {
V_23 -> V_954 . V_997 = V_997 ;
V_23 -> V_954 . V_998 = V_998 ;
} else {
V_23 -> V_954 . V_997 = 0 ;
V_23 -> V_954 . V_998 = 0 ;
}
}
static int F_362 ( struct V_17 * V_23 , T_4 V_1003 )
{
if ( V_1003 > 7 || ! V_23 -> V_954 . V_978 )
V_1003 = 0 ;
return V_1004 [ V_1003 ] - 1 ;
}
static int F_363 ( struct V_165 * V_166 ,
struct V_1005 * V_501 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
struct V_965 * V_954 = NULL ;
int V_955 , V_956 ;
T_2 * V_1006 = V_501 -> V_3 + V_217 ;
int V_1007 = ! F_364 ( V_1006 ) ;
if ( ! ( V_23 -> V_37 & V_103 ) )
return 0 ;
V_954 = & V_23 -> V_117 -> V_954 ;
if ( V_23 -> V_163 -> V_513 == V_514 ) {
if ( V_1007 == 0 )
V_954 -> V_955 = 0 ;
else
V_954 -> V_955 = V_954 -> V_956 ;
}
V_955 = V_954 -> V_955 ;
V_956 = V_954 -> V_956 ;
F_293 ( L_345
L_346 ,
V_23 -> V_954 . V_978 , V_955 , V_956 , V_1007 ) ;
if ( V_955 && V_23 -> V_954 . V_978 )
return 1 ;
return 0 ;
}
static int F_365 ( struct V_17 * V_23 ,
T_4 V_1003 ,
struct V_1008 * V_768 )
{
int V_1009 = 0 ;
V_1009 = V_1004 [ V_1003 ] - 1 ;
V_768 -> V_1010 |= V_1011 ;
if ( V_23 -> V_954 . V_1012 & ( 1UL << V_1009 ) ) {
V_768 -> V_1013 &= ~ V_1014 ;
V_768 -> V_768 . V_1015 . V_1016 . V_1017 |= F_173 ( V_1018 ) ;
}
return 0 ;
}
static void F_366 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_961 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_37 & V_103 )
F_353 ( V_23 , & ( V_23 -> V_117 -> V_954 ) ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int F_367 ( struct V_165 * V_166 ,
struct V_1019 * V_681 ,
struct V_440 * V_441 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
int V_952 = ( ( V_23 -> V_37 & V_103 ) &&
( V_441 == V_23 -> V_117 ) ) ;
F_352 ( V_23 , V_952 , V_441 ) ;
return 0 ;
}
static int F_368 ( struct V_165 * V_166 ,
struct V_1020 * V_681 ,
struct V_440 * V_441 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
int V_952 = ( ( V_23 -> V_37 & V_103 ) &&
( V_441 == V_23 -> V_117 ) ) ;
F_352 ( V_23 , V_952 , V_441 ) ;
return 0 ;
}
static int F_369 ( struct V_165 * V_166 ,
struct V_672 * V_681 ,
struct V_440 * V_441 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_360 ( V_23 , V_441 ) ;
return 0 ;
}
static int F_355 ( struct V_17 * V_23 , struct V_953
* V_1021 )
{
return F_155 ( V_23 , V_1022 ,
sizeof( * V_1021 ) * 3 , V_1021 ) ;
}
static int F_357 ( struct V_17 * V_23 , struct V_979
* V_1021 )
{
return F_155 ( V_23 , V_1023 , sizeof( * V_1021 ) ,
V_1021 ) ;
}
static int F_370 ( struct V_17 * V_23 ,
struct V_440 * V_441 ,
struct V_335 * V_336 , int V_654 )
{
int V_557 ;
if ( V_23 -> V_59 & V_1024 )
F_324 ( V_23 , V_441 -> V_118 ) ;
if ( ! ( V_23 -> V_59 & V_811 ) ) {
V_23 -> V_667 = F_3 ( V_441 -> V_810 ,
( T_2 ) V_313 ) ;
memcpy ( V_23 -> V_668 , V_441 -> V_311 , V_23 -> V_667 ) ;
}
V_441 -> V_817 = V_140 ;
memset ( & V_23 -> V_559 , 0 , sizeof( V_23 -> V_559 ) ) ;
V_23 -> V_559 . V_197 = V_441 -> V_197 ;
V_23 -> V_559 . V_1025 = 0 ;
if ( ( V_23 -> V_317 & V_813 ) &&
( V_23 -> V_163 -> V_244 . V_889 == V_890 ) ) {
V_23 -> V_559 . V_1026 = V_1027 ;
V_23 -> V_559 . V_1025 = V_23 -> V_163 -> V_244 . V_852 ;
if ( V_23 -> V_163 -> V_244 . V_11 == V_847 )
F_317 ( V_23 , V_856 ) ;
} else if ( ( V_23 -> V_317 & V_813 ) &&
( V_23 -> V_163 -> V_244 . V_889 == V_895 ) )
V_23 -> V_559 . V_1026 = V_1028 ;
else
V_23 -> V_559 . V_1026 = V_1029 ;
if ( V_23 -> V_163 -> V_826 ) {
V_23 -> V_559 . V_994 = F_173 ( 0x02 ) ;
F_338 ( V_23 , V_23 -> V_163 -> V_898 ,
V_23 -> V_163 -> V_826 ) ;
}
if ( V_441 -> V_118 & V_23 -> V_163 -> V_118 & V_119 )
V_23 -> V_559 . V_347 = V_354 ;
else if ( V_441 -> V_118 & V_23 -> V_163 -> V_118 & V_121 )
V_23 -> V_559 . V_347 = V_348 ;
else if ( V_441 -> V_118 & V_23 -> V_163 -> V_118 & V_608 )
V_23 -> V_559 . V_347 = V_352 ;
V_23 -> V_559 . V_317 = F_173 ( V_441 -> V_317 ) ;
if ( ( V_441 -> V_317 & V_822 )
&& ! ( V_23 -> V_59 & V_821 ) ) {
V_23 -> V_559 . V_1030 = V_1031 ;
} else {
V_23 -> V_559 . V_1030 = V_1032 ;
V_23 -> V_559 . V_317 &=
~ F_173 ( V_822 ) ;
}
if ( V_23 -> V_163 -> V_513 == V_514 )
V_23 -> V_559 . V_317 &=
~ F_173 ( V_1033 ) ;
F_265 ( L_347 ,
V_654 ? L_348 : L_349 ,
V_23 -> V_667 , V_23 -> V_668 ,
V_441 -> V_197 ,
V_1034 [ V_23 -> V_559 . V_347 ] ,
V_336 -> V_796 ,
( V_23 -> V_559 . V_1030 ==
V_1032 ) ? L_350 : L_351 ,
V_441 -> V_317 &
V_822 ? L_351 : L_350 ,
V_23 -> V_317 & V_813 ? L_352 : L_295 ,
V_23 -> V_317 & V_813 ?
( V_23 -> V_317 & V_1035 ? L_353 :
L_354 ) : L_108 ,
V_23 -> V_317 & V_813 ? L_355 : L_108 ,
V_23 -> V_317 & V_813 ?
'1' + V_23 -> V_163 -> V_244 . V_852 : '.' ,
V_23 -> V_317 & V_813 ? '.' : ' ' ) ;
V_23 -> V_559 . V_640 = F_173 ( V_441 -> V_640 ) ;
if ( ( V_23 -> V_163 -> V_513 == V_514 ) &&
( V_441 -> V_467 [ 0 ] == 0 ) && ( V_441 -> V_467 [ 1 ] == 0 ) ) {
V_23 -> V_559 . V_561 = V_1036 ;
V_23 -> V_559 . V_1037 = 0 ;
V_23 -> V_559 . V_1038 = 0 ;
} else {
if ( F_29 ( V_654 ) )
V_23 -> V_559 . V_561 = V_1039 ;
else
V_23 -> V_559 . V_561 = V_1040 ;
V_23 -> V_559 . V_1037 = F_179 ( V_441 -> V_467 [ 1 ] ) ;
V_23 -> V_559 . V_1038 = F_179 ( V_441 -> V_467 [ 0 ] ) ;
}
memcpy ( V_23 -> V_559 . V_216 , V_441 -> V_216 , V_217 ) ;
if ( V_23 -> V_163 -> V_513 == V_514 ) {
memset ( & V_23 -> V_559 . V_802 , 0xFF , V_217 ) ;
V_23 -> V_559 . V_825 = F_173 ( V_441 -> V_825 ) ;
} else {
memcpy ( V_23 -> V_559 . V_802 , V_441 -> V_216 , V_217 ) ;
V_23 -> V_559 . V_825 = 0 ;
}
V_23 -> V_559 . V_824 = F_173 ( V_441 -> V_824 ) ;
V_557 = F_158 ( V_23 , V_23 -> V_668 , V_23 -> V_667 ) ;
if ( V_557 ) {
F_142 ( L_356 ) ;
return V_557 ;
}
V_336 -> V_347 = V_23 -> V_559 . V_347 ;
V_336 -> V_1041 = V_1042 ;
F_175 ( V_23 , V_336 ) ;
if ( V_23 -> V_559 . V_347 == V_348 )
V_23 -> V_310 . V_1043 = 1 ;
else
V_23 -> V_310 . V_1043 = 0 ;
if ( V_23 -> V_163 -> V_513 == V_514 )
V_23 -> V_310 . V_1044 = 1 ;
else
V_23 -> V_310 . V_1044 = 0 ;
V_557 = F_157 ( V_23 ) ;
if ( V_557 ) {
F_142 ( L_357 ) ;
return V_557 ;
}
F_265 ( L_358 , V_441 -> V_674 . V_632 ) ;
V_557 = F_172 ( V_23 , V_441 -> V_674 . V_632 + V_1045 ) ;
if ( V_557 ) {
F_142 ( L_359 ) ;
return V_557 ;
}
V_23 -> V_197 = V_441 -> V_197 ;
memcpy ( V_23 -> V_216 , V_441 -> V_216 , V_217 ) ;
V_23 -> V_37 |= V_240 ;
V_23 -> V_37 &= ~ V_1046 ;
V_23 -> V_117 = V_441 ;
#ifdef F_291
F_358 ( V_23 , V_441 ) ;
#endif
V_557 = F_174 ( V_23 , & V_23 -> V_559 ) ;
if ( V_557 ) {
F_142 ( L_359 ) ;
return V_557 ;
}
F_284 ( V_650 , L_360 ,
V_23 -> V_667 , V_23 -> V_668 , V_23 -> V_216 ) ;
return 0 ;
}
static void F_371 ( void * V_3 )
{
struct V_17 * V_23 = V_3 ;
struct V_440 * V_441 = NULL ;
struct V_808 V_809 = {
. V_441 = V_23 -> V_117
} ;
if ( ! ( V_23 -> V_37 & ( V_103 | V_652 ) ) )
return;
if ( V_23 -> V_37 & V_103 ) {
unsigned long V_41 ;
T_2 V_632 = V_23 -> V_117 -> V_674 . V_632 ;
V_23 -> V_117 -> V_674 . V_632 = - 128 ;
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
F_312 (network, &priv->ieee->network_list, list) {
if ( V_441 != V_23 -> V_117 )
F_313 ( V_23 , & V_809 , V_441 , 1 ) ;
}
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
V_23 -> V_117 -> V_674 . V_632 = V_632 ;
if ( V_809 . V_441 == V_23 -> V_117 ) {
F_265 ( L_361
L_362 ) ;
V_23 -> V_37 &= ~ V_652 ;
F_323 ( V_23 ) ;
return;
}
F_264 ( V_23 , 1 ) ;
V_23 -> V_117 = V_809 . V_441 ;
return;
}
F_303 ( V_23 , V_23 -> V_117 , & V_809 . V_336 ) ;
F_370 ( V_23 , V_23 -> V_117 , & V_809 . V_336 , 1 ) ;
V_23 -> V_37 &= ~ V_652 ;
}
static void F_372 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_706 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_371 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int V_332 ( void * V_3 )
{
struct V_17 * V_23 = V_3 ;
struct V_440 * V_441 = NULL ;
struct V_808 V_809 = {
. V_441 = NULL
} ;
struct V_335 * V_336 ;
struct V_437 * V_438 ;
unsigned long V_41 ;
if ( V_23 -> V_163 -> V_513 == V_515 ) {
F_265 ( L_363 ) ;
return 0 ;
}
if ( V_23 -> V_37 & ( V_103 | V_240 ) ) {
F_265 ( L_364
L_365 ) ;
return 0 ;
}
if ( V_23 -> V_37 & V_560 ) {
F_265 ( L_366
L_367 ) ;
F_128 ( & V_23 -> V_333 ) ;
return 0 ;
}
if ( ! F_47 ( V_23 ) || ( V_23 -> V_37 & V_321 ) ) {
F_265 ( L_368
L_369 ) ;
return 0 ;
}
if ( ! ( V_23 -> V_59 & V_1047 ) &&
! ( V_23 -> V_59 & ( V_811 | V_818 ) ) ) {
F_265 ( L_370 ) ;
return 0 ;
}
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
F_312 (network, &priv->ieee->network_list, list)
F_313 ( V_23 , & V_809 , V_441 , 0 ) ;
V_441 = V_809 . V_441 ;
V_336 = & V_809 . V_336 ;
if ( V_441 == NULL &&
V_23 -> V_163 -> V_513 == V_514 &&
V_23 -> V_59 & V_1048 &&
V_23 -> V_59 & V_811 &&
V_23 -> V_59 & V_549 ) {
if ( F_297 ( & V_23 -> V_163 -> V_443 ) ) {
struct V_440 * V_1049 = NULL ;
struct V_440 * V_1050 ;
F_312 (target, &priv->ieee->network_list, list) {
if ( ( V_1049 == NULL ) ||
( V_1050 -> V_812 < V_1049 -> V_812 ) )
V_1049 = V_1050 ;
}
F_214 ( & V_1049 -> V_442 ) ;
V_1050 = V_1049 ;
F_265 ( L_371 ,
V_1050 -> V_810 , V_1050 -> V_311 ,
V_1050 -> V_216 ) ;
F_215 ( & V_1050 -> V_442 ,
& V_23 -> V_163 -> V_443 ) ;
}
V_438 = V_23 -> V_163 -> V_443 . V_775 ;
V_441 = F_212 ( V_438 , struct V_440 , V_442 ) ;
F_314 ( V_23 , V_441 ) ;
V_336 = & V_23 -> V_336 ;
F_214 ( V_438 ) ;
F_215 ( & V_441 -> V_442 , & V_23 -> V_163 -> V_1051 ) ;
}
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
if ( ! V_441 ) {
F_323 ( V_23 ) ;
if ( ! ( V_23 -> V_37 & V_321 ) ) {
if ( ! ( V_23 -> V_59 & V_195 ) )
F_56 ( & V_23 -> V_186 ,
V_1052 ) ;
else
F_56 ( & V_23 -> V_186 , 0 ) ;
}
return 0 ;
}
F_370 ( V_23 , V_441 , V_336 , 0 ) ;
return 1 ;
}
static void F_373 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_333 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_332 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_374 ( struct V_17 * V_23 ,
struct V_1005 * V_501 )
{
struct V_1053 * V_1054 ;
T_4 V_1055 ;
V_1054 = (struct V_1053 * ) V_501 -> V_3 ;
V_1055 = F_222 ( V_1054 -> V_1056 ) ;
if ( ! ( V_1055 & V_1057 ) )
return;
V_1055 &= ~ V_1057 ;
V_1054 -> V_1056 = F_173 ( V_1055 ) ;
switch ( V_23 -> V_163 -> V_244 . V_11 ) {
case V_843 :
memmove ( V_501 -> V_3 + V_1058 ,
V_501 -> V_3 + V_1058 + 8 ,
V_501 -> V_4 - V_1058 - 8 ) ;
F_375 ( V_501 , V_501 -> V_4 - 16 ) ;
break;
case V_846 :
break;
case V_847 :
memmove ( V_501 -> V_3 + V_1058 ,
V_501 -> V_3 + V_1058 + 4 ,
V_501 -> V_4 - V_1058 - 4 ) ;
F_375 ( V_501 , V_501 -> V_4 - 8 ) ;
break;
case V_848 :
break;
default:
F_4 ( V_1059 L_372 ,
V_23 -> V_163 -> V_244 . V_11 ) ;
break;
}
}
static void F_376 ( struct V_17 * V_23 ,
struct V_773 * V_774 ,
struct V_673 * V_674 )
{
struct V_165 * V_166 = V_23 -> V_167 ;
struct V_675 * V_1054 ;
struct V_1060 * V_1061 = (struct V_1060 * ) V_774 -> V_501 -> V_3 ;
V_166 -> V_1062 = V_140 ;
if ( F_29 ( ( F_222 ( V_1061 -> V_538 . V_1063 . V_415 ) + V_1064 ) >
F_377 ( V_774 -> V_501 ) ) ) {
V_166 -> V_674 . V_1065 ++ ;
V_23 -> V_1066 . V_1067 . V_1068 ++ ;
F_378 ( L_373 ) ;
return;
} else if ( F_29 ( ! F_92 ( V_23 -> V_167 ) ) ) {
V_166 -> V_674 . V_1069 ++ ;
V_23 -> V_1066 . V_1067 . V_1068 ++ ;
F_378 ( L_374 ) ;
return;
}
F_379 ( V_774 -> V_501 , F_380 ( struct V_1060 , V_538 . V_1063 . V_3 ) ) ;
F_381 ( V_774 -> V_501 , F_222 ( V_1061 -> V_538 . V_1063 . V_415 ) ) ;
F_382 ( L_375 , V_774 -> V_501 -> V_4 ) ;
V_1054 = (struct V_675 * ) V_774 -> V_501 -> V_3 ;
if ( V_23 -> V_163 -> V_513 != V_515 &&
( F_364 ( V_1054 -> V_1070 ) ?
! V_23 -> V_163 -> V_853 : ! V_23 -> V_163 -> V_845 ) )
F_374 ( V_23 , V_774 -> V_501 ) ;
if ( ! F_383 ( V_23 -> V_163 , V_774 -> V_501 , V_674 ) )
V_166 -> V_674 . V_1065 ++ ;
else {
V_774 -> V_501 = NULL ;
F_63 ( V_23 ) ;
}
}
static void F_384 ( struct V_17 * V_23 ,
struct V_773 * V_774 ,
struct V_673 * V_674 )
{
struct V_165 * V_166 = V_23 -> V_167 ;
struct V_1060 * V_1061 = (struct V_1060 * ) V_774 -> V_501 -> V_3 ;
struct V_1071 * V_1063 = & V_1061 -> V_538 . V_1063 ;
T_4 V_1072 = V_1063 -> V_1072 ;
T_2 V_1073 = V_1063 -> V_1073 ;
T_7 V_1074 = V_1063 -> V_1075 - V_1045 ;
T_4 V_1076 = V_1063 -> V_609 ;
struct V_1077 * V_1078 ;
unsigned short V_4 = F_222 ( V_1061 -> V_538 . V_1063 . V_415 ) ;
V_166 -> V_1062 = V_140 ;
if ( F_29 ( ( F_222 ( V_1061 -> V_538 . V_1063 . V_415 ) + V_1064 ) >
F_377 ( V_774 -> V_501 ) ) ) {
V_166 -> V_674 . V_1065 ++ ;
V_23 -> V_1066 . V_1067 . V_1068 ++ ;
F_378 ( L_373 ) ;
return;
} else if ( F_29 ( ! F_92 ( V_23 -> V_167 ) ) ) {
V_166 -> V_674 . V_1069 ++ ;
V_23 -> V_1066 . V_1067 . V_1068 ++ ;
F_378 ( L_374 ) ;
return;
}
if ( V_4 > V_503 - sizeof( struct V_1077 ) ) {
V_166 -> V_674 . V_1069 ++ ;
V_23 -> V_1066 . V_1067 . V_1068 ++ ;
F_378 ( L_376 ) ;
return;
}
memmove ( V_774 -> V_501 -> V_3 + sizeof( struct V_1077 ) ,
V_774 -> V_501 -> V_3 + V_1064 , V_4 ) ;
V_1078 = (struct V_1077 * ) V_774 -> V_501 -> V_3 ;
V_1078 -> V_1079 . V_1080 = V_1081 ;
V_1078 -> V_1079 . V_1082 = 0 ;
V_1078 -> V_1079 . V_1083 = F_173 ( sizeof( struct V_1077 ) ) ;
V_1078 -> V_1079 . V_1084 = F_179 (
( 1 << V_1085 ) |
( 1 << V_1086 ) |
( 1 << V_1087 ) |
( 1 << V_1088 ) |
( 1 << V_1089 ) |
( 1 << V_1090 ) |
( 1 << V_1091 ) ) ;
V_1078 -> V_1092 = 0 ;
V_1078 -> V_1093 = ( V_1094 ) ( V_1063 -> V_1095 [ 3 ] << 24 |
V_1063 -> V_1095 [ 2 ] << 16 |
V_1063 -> V_1095 [ 1 ] << 8 |
V_1063 -> V_1095 [ 0 ] ) ;
V_1078 -> V_1096 = V_1074 ;
V_1078 -> V_1097 = ( T_7 ) F_222 ( V_1063 -> V_737 ) ;
V_1078 -> V_1098 = F_173 ( F_385 ( V_1072 ) ) ;
if ( V_1072 > 14 ) {
V_1078 -> V_1099 =
F_173 ( ( V_1100 | V_1101 ) ) ;
} else if ( V_1073 & 32 ) {
V_1078 -> V_1099 =
F_173 ( ( V_1102 | V_1103 ) ) ;
} else {
V_1078 -> V_1099 =
F_173 ( V_1100 | V_1103 ) ;
}
switch ( V_1076 ) {
case V_612 :
V_1078 -> V_1104 = 2 ;
break;
case V_613 :
V_1078 -> V_1104 = 4 ;
break;
case V_614 :
V_1078 -> V_1104 = 10 ;
break;
case V_615 :
V_1078 -> V_1104 = 12 ;
break;
case V_616 :
V_1078 -> V_1104 = 18 ;
break;
case V_617 :
V_1078 -> V_1104 = 22 ;
break;
case V_618 :
V_1078 -> V_1104 = 24 ;
break;
case V_619 :
V_1078 -> V_1104 = 36 ;
break;
case V_620 :
V_1078 -> V_1104 = 48 ;
break;
case V_621 :
V_1078 -> V_1104 = 72 ;
break;
case V_622 :
V_1078 -> V_1104 = 96 ;
break;
case V_623 :
V_1078 -> V_1104 = 108 ;
break;
default:
V_1078 -> V_1104 = 0 ;
break;
}
V_1078 -> V_1105 = ( V_1073 & 3 ) ;
if ( ( V_1073 & 64 ) )
V_1078 -> V_1092 |= V_1106 ;
F_381 ( V_774 -> V_501 , V_4 + sizeof( struct V_1077 ) ) ;
F_382 ( L_375 , V_774 -> V_501 -> V_4 ) ;
if ( ! F_383 ( V_23 -> V_163 , V_774 -> V_501 , V_674 ) )
V_166 -> V_674 . V_1065 ++ ;
else {
V_774 -> V_501 = NULL ;
}
}
static void F_386 ( struct V_17 * V_23 ,
struct V_773 * V_774 ,
struct V_673 * V_674 )
{
struct V_165 * V_166 = V_23 -> V_157 ;
struct V_1060 * V_1061 = (struct V_1060 * ) V_774 -> V_501 -> V_3 ;
struct V_1071 * V_1063 = & V_1061 -> V_538 . V_1063 ;
struct V_1077 * V_1078 ;
struct V_1053 * V_1054 ;
T_4 V_197 = V_1063 -> V_1072 ;
T_2 V_1107 = V_1063 -> V_1073 ;
T_7 signal = V_1063 -> V_1075 - V_1045 ;
T_7 V_737 = ( T_7 ) F_222 ( V_1063 -> V_737 ) ;
T_2 V_609 = V_1063 -> V_609 ;
unsigned short V_4 = F_222 ( V_1061 -> V_538 . V_1063 . V_415 ) ;
struct V_1005 * V_501 ;
int V_1108 = 0 ;
T_4 V_161 = V_23 -> V_159 -> V_161 ;
if ( V_161 & V_1109 )
return;
V_166 -> V_1062 = V_140 ;
if ( F_29 ( ( V_4 + V_1064 ) > F_377 ( V_774 -> V_501 ) ) ) {
V_166 -> V_674 . V_1065 ++ ;
F_378 ( L_373 ) ;
return;
}
if ( F_29 ( ! F_92 ( V_166 ) ) ) {
V_166 -> V_674 . V_1069 ++ ;
F_378 ( L_374 ) ;
return;
}
if ( V_4 > V_503 - sizeof( struct V_1077 ) ) {
V_166 -> V_674 . V_1069 ++ ;
F_378 ( L_376 ) ;
return;
}
V_1054 = ( void * ) V_774 -> V_501 -> V_3 + V_1064 ;
if ( F_387 ( F_222 ( V_1054 -> V_1056 ) ) ) {
if ( V_161 & V_1110 )
return;
if ( V_161 & V_1111 )
V_1108 = 1 ;
} else if ( F_388 ( F_222 ( V_1054 -> V_1056 ) ) ) {
if ( V_161 & V_1112 )
return;
if ( V_161 & V_1113 )
V_1108 = 1 ;
} else if ( F_389 ( F_222 ( V_1054 -> V_1056 ) ) ) {
if ( V_161 & V_1114 )
return;
if ( V_161 & V_1115 )
V_1108 = 1 ;
}
V_501 = F_390 ( V_774 -> V_501 , V_139 ) ;
if ( V_501 == NULL ) {
F_46 ( L_377 ) ;
return;
}
V_1078 = ( void * ) V_501 -> V_3 ;
if ( V_1108 )
V_4 = F_391 ( F_222 ( V_1054 -> V_1056 ) ) ;
memcpy ( V_1078 -> V_142 , V_1054 , V_4 ) ;
V_1078 -> V_1079 . V_1080 = V_1081 ;
V_1078 -> V_1079 . V_1082 = 0 ;
V_1078 -> V_1079 . V_1083 = F_173 ( sizeof( * V_1078 ) ) ;
F_381 ( V_501 , sizeof( * V_1078 ) + V_4 ) ;
V_1078 -> V_1079 . V_1084 = F_179 (
( 1 << V_1085 ) |
( 1 << V_1086 ) |
( 1 << V_1087 ) |
( 1 << V_1088 ) |
( 1 << V_1089 ) |
( 1 << V_1090 ) |
( 1 << V_1091 ) ) ;
V_1078 -> V_1092 = 0 ;
V_1078 -> V_1093 = ( V_1094 ) ( V_1063 -> V_1095 [ 3 ] << 24 |
V_1063 -> V_1095 [ 2 ] << 16 |
V_1063 -> V_1095 [ 1 ] << 8 |
V_1063 -> V_1095 [ 0 ] ) ;
V_1078 -> V_1096 = signal ;
V_1078 -> V_1097 = V_737 ;
V_1078 -> V_1098 = F_173 ( F_385 ( V_197 ) ) ;
if ( V_197 > 14 ) {
V_1078 -> V_1099 =
F_173 ( ( V_1100 | V_1101 ) ) ;
} else if ( V_1107 & ( 1 << 5 ) ) {
V_1078 -> V_1099 =
F_173 ( ( V_1102 | V_1103 ) ) ;
} else {
V_1078 -> V_1099 =
F_173 ( V_1100 | V_1103 ) ;
}
switch ( V_609 ) {
case V_612 :
V_1078 -> V_1104 = 2 ;
break;
case V_613 :
V_1078 -> V_1104 = 4 ;
break;
case V_614 :
V_1078 -> V_1104 = 10 ;
break;
case V_615 :
V_1078 -> V_1104 = 12 ;
break;
case V_616 :
V_1078 -> V_1104 = 18 ;
break;
case V_617 :
V_1078 -> V_1104 = 22 ;
break;
case V_618 :
V_1078 -> V_1104 = 24 ;
break;
case V_619 :
V_1078 -> V_1104 = 36 ;
break;
case V_620 :
V_1078 -> V_1104 = 48 ;
break;
case V_621 :
V_1078 -> V_1104 = 72 ;
break;
case V_622 :
V_1078 -> V_1104 = 96 ;
break;
case V_623 :
V_1078 -> V_1104 = 108 ;
break;
default:
V_1078 -> V_1104 = 0 ;
break;
}
V_1078 -> V_1105 = ( V_1107 & 3 ) ;
if ( V_1107 & ( 1 << 6 ) )
V_1078 -> V_1092 |= V_1106 ;
F_382 ( L_375 , V_501 -> V_4 ) ;
if ( ! F_383 ( V_23 -> V_159 -> V_163 , V_501 , V_674 ) ) {
V_166 -> V_674 . V_1065 ++ ;
F_392 ( V_501 ) ;
}
}
static int F_393 ( struct V_17 * V_23 ,
struct V_675 * V_1116 )
{
switch ( V_23 -> V_163 -> V_513 ) {
case V_514 :
if ( F_213 ( V_1116 -> V_1117 , V_23 -> V_167 -> V_1118 ) )
return 0 ;
if ( F_364 ( V_1116 -> V_1070 ) )
return F_213 ( V_1116 -> V_1119 , V_23 -> V_216 ) ;
return F_213 ( V_1116 -> V_1070 ,
V_23 -> V_167 -> V_1118 ) ;
case V_516 :
if ( F_213 ( V_1116 -> V_1119 , V_23 -> V_167 -> V_1118 ) )
return 0 ;
if ( F_364 ( V_1116 -> V_1070 ) )
return F_213 ( V_1116 -> V_1117 , V_23 -> V_216 ) ;
return F_213 ( V_1116 -> V_1070 ,
V_23 -> V_167 -> V_1118 ) ;
}
return 1 ;
}
static int F_394 ( struct V_17 * V_23 ,
struct V_675 * V_1116 )
{
T_4 V_1120 = F_222 ( V_1116 -> V_1121 ) ;
T_4 V_1122 = F_395 ( V_1120 ) ;
T_4 V_359 = F_396 ( V_1120 ) ;
T_4 * V_1123 , * V_1124 ;
unsigned long * V_1125 ;
switch ( V_23 -> V_163 -> V_513 ) {
case V_514 :
{
struct V_437 * V_134 ;
struct V_1126 * V_545 = NULL ;
T_2 * V_314 = V_1116 -> V_1117 ;
int V_400 = V_314 [ 5 ] % V_1127 ;
F_397 (p, &priv->ibss_mac_hash[index]) {
V_545 =
F_212 ( V_134 , struct V_1126 , V_442 ) ;
if ( F_213 ( V_545 -> V_314 , V_314 ) )
break;
}
if ( V_134 == & V_23 -> V_1128 [ V_400 ] ) {
V_545 = F_83 ( sizeof( * V_545 ) , V_139 ) ;
if ( ! V_545 ) {
F_46
( L_378 ) ;
return 0 ;
}
memcpy ( V_545 -> V_314 , V_314 , V_217 ) ;
V_545 -> V_838 = V_1122 ;
V_545 -> V_1129 = V_359 ;
V_545 -> V_1130 = V_140 ;
F_398 ( & V_545 -> V_442 ,
& V_23 -> V_1128 [ V_400 ] ) ;
return 0 ;
}
V_1123 = & V_545 -> V_838 ;
V_1124 = & V_545 -> V_1129 ;
V_1125 = & V_545 -> V_1130 ;
break;
}
case V_516 :
V_1123 = & V_23 -> V_1131 ;
V_1124 = & V_23 -> V_1132 ;
V_1125 = & V_23 -> V_1133 ;
break;
default:
return 0 ;
}
if ( ( * V_1123 == V_1122 ) &&
F_309 ( * V_1125 + V_1134 , V_140 ) ) {
if ( * V_1124 == V_359 )
goto V_1135;
if ( * V_1124 + 1 != V_359 )
goto V_1135;
} else
* V_1123 = V_1122 ;
* V_1124 = V_359 ;
* V_1125 = V_140 ;
return 0 ;
V_1135:
return 1 ;
}
static void F_399 ( struct V_17 * V_23 ,
struct V_773 * V_774 ,
struct V_673 * V_674 )
{
struct V_1005 * V_501 = V_774 -> V_501 ;
struct V_1060 * V_1061 = (struct V_1060 * ) V_501 -> V_3 ;
struct V_675 * V_1116 = (struct V_675 * )
( V_501 -> V_3 + V_1064 ) ;
F_294 ( V_23 -> V_163 , V_1116 , V_674 ) ;
if ( V_23 -> V_163 -> V_513 == V_514 &&
( ( F_400 ( F_222 ( V_1116 -> V_1136 ) ) ==
V_1137 ) ||
( F_400 ( F_222 ( V_1116 -> V_1136 ) ) ==
V_1138 ) ) ) {
if ( F_213 ( V_1116 -> V_1119 , V_23 -> V_216 ) )
F_262 ( V_23 , V_1116 -> V_1117 ) ;
}
if ( V_23 -> V_59 & V_200 ) {
F_142 ( L_379 ) ;
F_381 ( V_501 , F_222 ( V_1061 -> V_538 . V_1063 . V_415 ) +
V_1064 ) ;
F_401 ( V_501 , V_1064 ) ;
memcpy ( F_402 ( V_501 , sizeof( * V_674 ) ) , V_674 , sizeof( * V_674 ) ) ;
V_501 -> V_166 = V_23 -> V_163 -> V_166 ;
F_403 ( V_501 ) ;
V_501 -> V_1139 = V_1140 ;
V_501 -> V_1141 = F_404 ( V_1142 ) ;
memset ( V_501 -> V_401 , 0 , sizeof( V_774 -> V_501 -> V_401 ) ) ;
F_405 ( V_501 ) ;
V_774 -> V_501 = NULL ;
}
}
static void F_141 ( struct V_17 * V_23 )
{
struct V_773 * V_774 ;
struct V_1060 * V_1061 ;
struct V_675 * V_1116 ;
T_3 V_381 , V_1143 , V_7 ;
T_2 V_1144 ;
T_2 V_1145 = 0 ;
V_381 = F_36 ( V_23 , V_520 ) ;
V_1143 = F_36 ( V_23 , V_781 ) ;
V_7 = V_23 -> V_496 -> V_505 ;
if ( F_251 ( V_23 -> V_496 ) > ( V_500 / 2 ) )
V_1145 = 1 ;
while ( V_7 != V_381 ) {
V_774 = V_23 -> V_496 -> V_778 [ V_7 ] ;
if ( F_29 ( V_774 == NULL ) ) {
F_4 ( V_782 L_380 ) ;
break;
}
V_23 -> V_496 -> V_778 [ V_7 ] = NULL ;
F_406 ( V_23 -> V_477 , V_774 -> V_502 ,
V_503 ,
V_504 ) ;
V_1061 = (struct V_1060 * ) V_774 -> V_501 -> V_3 ;
F_382 ( L_381 ,
V_1061 -> V_1116 . V_536 ,
V_1061 -> V_1116 . V_1146 , V_1061 -> V_1116 . V_770 ) ;
switch ( V_1061 -> V_1116 . V_536 ) {
case V_1147 : {
struct V_673 V_674 = {
. V_632 = V_1061 -> V_538 . V_1063 . V_1075 -
V_1045 ,
. signal =
V_1061 -> V_538 . V_1063 . V_1075 -
V_1045 + 0x100 ,
. V_737 =
F_222 ( V_1061 -> V_538 . V_1063 . V_737 ) ,
. V_609 = V_1061 -> V_538 . V_1063 . V_609 ,
. V_1148 = V_140 ,
. V_1072 =
V_1061 -> V_538 . V_1063 . V_1072 ,
. V_1149 =
( V_1061 -> V_538 . V_1063 .
V_394 & ( 1 << 0 ) ) ?
V_820 :
V_819 ,
. V_4 = F_222 ( V_1061 -> V_538 . V_1063 . V_415 ) ,
} ;
if ( V_674 . V_632 != 0 )
V_674 . V_36 |= V_1150 ;
if ( V_674 . signal != 0 )
V_674 . V_36 |= V_1151 ;
if ( V_674 . V_737 != 0 )
V_674 . V_36 |= V_1152 ;
if ( V_674 . V_609 != 0 )
V_674 . V_36 |= V_1153 ;
V_23 -> V_593 ++ ;
#ifdef F_270
if ( V_23 -> V_157 && F_92 ( V_23 -> V_157 ) )
F_386 ( V_23 , V_774 , & V_674 ) ;
#endif
#ifdef F_245
if ( V_23 -> V_163 -> V_513 == V_515 ) {
#ifdef F_407
F_384 ( V_23 ,
V_774 ,
& V_674 ) ;
#else
F_376 ( V_23 , V_774 ,
& V_674 ) ;
#endif
break;
}
#endif
V_1116 =
(struct V_675 * ) ( V_774 -> V_501 ->
V_3 +
V_1064 ) ;
V_1144 =
F_393 ( V_23 , V_1116 ) ;
if ( V_1144 && V_23 -> V_117 ) {
V_23 -> V_117 -> V_674 . V_632 =
V_674 . V_632 ;
V_23 -> V_581 =
F_273 ( V_23 -> V_581 ,
V_674 . V_632 , V_1154 ) ;
}
F_382 ( L_382 ,
F_222 ( V_1061 -> V_538 . V_1063 . V_415 ) ) ;
if ( F_222 ( V_1061 -> V_538 . V_1063 . V_415 ) <
F_391 ( F_222 (
V_1116 -> V_1136 ) ) ) {
F_378
( L_383
L_384 ) ;
V_23 -> V_167 -> V_674 . V_1065 ++ ;
V_23 -> V_1066 . V_1067 . V_1068 ++ ;
break;
}
switch ( F_408
( F_222 ( V_1116 -> V_1136 ) ) ) {
case V_1155 :
F_399 ( V_23 , V_774 ,
& V_674 ) ;
break;
case V_1156 :
break;
case V_1157 :
if ( F_29 ( ! V_1144 ||
F_394 ( V_23 ,
V_1116 ) ) )
{
F_378 ( L_385
L_386
L_386
L_387 ,
V_1116 -> V_1070 ,
V_1116 -> V_1117 ,
V_1116 -> V_1119 ) ;
break;
}
F_376 ( V_23 , V_774 ,
& V_674 ) ;
break;
}
break;
}
case V_1158 : {
F_382
( L_388 ,
V_1061 -> V_538 . V_1159 . V_661 ,
V_1061 -> V_538 . V_1159 . V_41 ,
F_222 ( V_1061 -> V_538 . V_1159 . V_15 ) ) ;
F_290 ( V_23 , & V_1061 -> V_538 . V_1159 ) ;
break;
}
default:
F_382 ( L_389 ,
V_1061 -> V_1116 . V_536 ) ;
break;
}
if ( V_774 -> V_501 != NULL ) {
F_392 ( V_774 -> V_501 ) ;
V_774 -> V_501 = NULL ;
}
F_239 ( V_23 -> V_477 , V_774 -> V_502 ,
V_503 , V_504 ) ;
F_215 ( & V_774 -> V_442 , & V_23 -> V_496 -> V_498 ) ;
V_7 = ( V_7 + 1 ) % V_500 ;
if ( V_1145 ) {
V_23 -> V_496 -> V_505 = V_7 ;
F_248 ( V_23 ) ;
}
}
V_23 -> V_496 -> V_505 = V_7 ;
F_296 ( V_23 ) ;
}
static int F_409 ( struct V_17 * V_23 , int V_1160 )
{
int V_881 , V_804 ;
int V_1161 = V_23 -> V_163 -> V_513 ;
V_23 -> V_59 = 0 ;
if ( ! V_1162 )
V_23 -> V_59 |= V_95 ;
if ( V_333 )
V_23 -> V_59 |= V_1047 ;
else
F_74 ( L_390 ) ;
if ( V_1163 )
V_23 -> V_59 |= V_1048 ;
else
F_74 ( L_391 ) ;
V_23 -> V_59 &= ~ V_811 ;
V_23 -> V_667 = 0 ;
memset ( V_23 -> V_668 , 0 , V_313 ) ;
if ( V_1164 && V_1160 ) {
V_23 -> V_37 |= V_184 ;
F_74 ( L_392 ) ;
}
if ( V_1165 != 0 ) {
V_23 -> V_59 |= V_549 ;
V_23 -> V_197 = V_1165 ;
F_74 ( L_393 , V_1165 ) ;
}
#ifdef F_291
F_361 ( V_23 , V_978 , V_1166 ,
V_997 , V_998 ) ;
#endif
switch ( V_1167 ) {
case 1 :
V_23 -> V_163 -> V_513 = V_514 ;
V_23 -> V_167 -> type = V_214 ;
break;
#ifdef F_245
case 2 :
V_23 -> V_163 -> V_513 = V_515 ;
#ifdef F_407
V_23 -> V_167 -> type = V_1168 ;
#else
V_23 -> V_167 -> type = V_1169 ;
#endif
break;
#endif
default:
case 0 :
V_23 -> V_167 -> type = V_214 ;
V_23 -> V_163 -> V_513 = V_516 ;
break;
}
if ( V_941 ) {
V_23 -> V_163 -> V_842 = 0 ;
V_23 -> V_163 -> V_946 = 0 ;
V_23 -> V_163 -> V_845 = 0 ;
V_23 -> V_163 -> V_853 = 0 ;
}
F_74 ( L_394 , V_941 ? L_294 : L_295 ) ;
V_23 -> V_163 -> V_1170 = 0 ;
if ( ( V_23 -> V_477 -> V_143 == 0x4223 ) ||
( V_23 -> V_477 -> V_143 == 0x4224 ) ) {
if ( V_1160 == 1 )
F_4 (KERN_INFO DRV_NAME
L_395
L_396 ) ;
V_23 -> V_163 -> V_353 = 1 ;
V_881 = V_819 | V_820 ;
V_804 = V_807 |
V_1171 ;
V_23 -> V_316 = V_1172 ;
V_23 -> V_163 -> V_118 = V_119 | V_121 | V_608 ;
} else {
if ( V_1160 == 1 )
F_4 (KERN_INFO DRV_NAME
L_397
L_396 ) ;
V_23 -> V_163 -> V_353 = 0 ;
V_881 = V_820 ;
V_804 = V_807 |
V_1171 ;
V_23 -> V_316 = V_1173 ;
V_23 -> V_163 -> V_118 = V_121 | V_608 ;
}
V_23 -> V_163 -> V_860 = V_881 ;
V_23 -> V_163 -> V_804 = V_804 ;
V_23 -> V_594 = V_1174 ;
V_23 -> V_647 = V_1175 ;
V_23 -> V_655 = V_1176 ;
V_23 -> V_357 = V_1177 ;
V_23 -> V_372 = V_1178 ;
V_23 -> V_373 = V_1179 ;
V_23 -> V_1180 = V_365 ;
V_23 -> V_345 = V_1181 ;
return V_1161 == V_23 -> V_163 -> V_513 ;
}
static int F_410 ( struct V_17 * V_23 , T_2 V_197 )
{
if ( V_197 == 0 ) {
F_74 ( L_398 ) ;
V_23 -> V_59 &= ~ V_549 ;
F_265 ( L_399
L_400 ) ;
V_332 ( V_23 ) ;
return 0 ;
}
V_23 -> V_59 |= V_549 ;
if ( V_23 -> V_197 == V_197 ) {
F_74 ( L_401 ,
V_197 ) ;
return 0 ;
}
F_74 ( L_402 , ( int ) V_197 ) ;
V_23 -> V_197 = V_197 ;
#ifdef F_245
if ( V_23 -> V_163 -> V_513 == V_515 ) {
int V_7 ;
if ( V_23 -> V_37 & V_321 ) {
F_166 ( L_403
L_404 ) ;
F_168 ( V_23 ) ;
}
for ( V_7 = 1000 ; V_7 && ( V_23 -> V_37 & V_321 ) ; V_7 -- )
F_187 ( 10 ) ;
if ( V_23 -> V_37 & V_321 )
F_166 ( L_405 ) ;
else
F_166 ( L_406 ,
1000 - V_7 ) ;
return 0 ;
}
#endif
F_265 ( L_407 ) ;
if ( ! F_266 ( V_23 ) )
V_332 ( V_23 ) ;
return 0 ;
}
static int F_411 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
const struct V_201 * V_202 = F_137 ( V_23 -> V_163 ) ;
struct V_1182 * V_1183 = & V_211 -> V_1149 ;
int V_432 = 0 , V_7 ;
T_2 V_197 , V_41 ;
int V_881 ;
if ( V_1183 -> V_1184 == 0 ) {
F_325 ( L_408 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_432 = F_410 ( V_23 , 0 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_432 ;
}
if ( V_1183 -> V_1185 == 1 ) {
V_197 = F_412 ( V_23 -> V_163 , V_1183 -> V_1184 ) ;
if ( V_197 == 0 )
return - V_75 ;
} else
V_197 = V_1183 -> V_1184 ;
if ( ! ( V_881 = F_133 ( V_23 -> V_163 , V_197 ) ) )
return - V_75 ;
if ( V_23 -> V_163 -> V_513 == V_514 ) {
V_7 = F_315 ( V_23 -> V_163 , V_197 ) ;
if ( V_7 == - 1 )
return - V_75 ;
V_41 = ( V_881 == V_820 ) ?
V_202 -> V_204 [ V_7 ] . V_41 : V_202 -> V_18 [ V_7 ] . V_41 ;
if ( V_41 & V_207 ) {
F_325 ( L_409 ) ;
return - V_75 ;
}
}
F_325 ( L_410 , V_1183 -> V_1184 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_432 = F_410 ( V_23 , V_197 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_432 ;
}
static int F_413 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
V_211 -> V_1149 . V_1185 = 0 ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_59 & V_549 ||
V_23 -> V_37 & ( V_240 | V_103 ) ) {
int V_7 ;
V_7 = F_315 ( V_23 -> V_163 , V_23 -> V_197 ) ;
F_226 ( V_7 == - 1 ) ;
V_211 -> V_1149 . V_1185 = 1 ;
switch ( F_133 ( V_23 -> V_163 , V_23 -> V_197 ) ) {
case V_819 :
V_211 -> V_1149 . V_1184 = V_23 -> V_163 -> V_202 . V_18 [ V_7 ] . V_1149 * 100000 ;
break;
case V_820 :
V_211 -> V_1149 . V_1184 = V_23 -> V_163 -> V_202 . V_204 [ V_7 ] . V_1149 * 100000 ;
break;
default:
F_359 () ;
}
} else
V_211 -> V_1149 . V_1184 = 0 ;
F_60 ( & V_23 -> V_109 ) ;
F_325 ( L_411 , V_23 -> V_197 ) ;
return 0 ;
}
static int F_414 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
int V_557 = 0 ;
F_325 ( L_412 , V_211 -> V_118 ) ;
switch ( V_211 -> V_118 ) {
#ifdef F_245
case V_515 :
#endif
case V_514 :
case V_516 :
break;
case V_1186 :
V_211 -> V_118 = V_516 ;
break;
default:
return - V_75 ;
}
if ( V_211 -> V_118 == V_23 -> V_163 -> V_513 )
return 0 ;
F_59 ( & V_23 -> V_109 ) ;
F_409 ( V_23 , 0 ) ;
#ifdef F_245
if ( V_23 -> V_163 -> V_513 == V_515 )
V_23 -> V_167 -> type = V_214 ;
if ( V_211 -> V_118 == V_515 )
#ifdef F_407
V_23 -> V_167 -> type = V_1168 ;
#else
V_23 -> V_167 -> type = V_1169 ;
#endif
#endif
F_241 () ;
V_23 -> V_163 -> V_513 = V_211 -> V_118 ;
F_128 ( & V_23 -> V_246 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_557 ;
}
static int F_415 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_118 = V_23 -> V_163 -> V_513 ;
F_325 ( L_413 , V_211 -> V_118 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_416 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
struct V_1187 * V_1188 = (struct V_1187 * ) V_903 ;
const struct V_201 * V_202 = F_137 ( V_23 -> V_163 ) ;
int V_7 = 0 , V_8 ;
V_211 -> V_3 . V_415 = sizeof( * V_1188 ) ;
memset ( V_1188 , 0 , sizeof( * V_1188 ) ) ;
V_1188 -> V_1189 = 27 * 1000 * 1000 ;
V_1188 -> V_1190 . V_1191 = 100 ;
V_1188 -> V_1190 . V_11 = 0 ;
V_1188 -> V_1190 . V_737 = 0 ;
V_1188 -> V_1190 . V_1192 = 7 ;
V_1188 -> V_1193 . V_1191 = 70 ;
V_1188 -> V_1193 . V_11 = 0 ;
V_1188 -> V_1193 . V_737 = 0 ;
V_1188 -> V_1193 . V_1192 = 7 ;
F_59 ( & V_23 -> V_109 ) ;
V_1188 -> V_1194 = F_3 ( V_23 -> V_336 . V_796 , ( T_2 ) V_1195 ) ;
for ( V_7 = 0 ; V_7 < V_1188 -> V_1194 ; V_7 ++ )
V_1188 -> V_1196 [ V_7 ] = ( V_23 -> V_336 . V_799 [ V_7 ] & 0x7F ) *
500000 ;
V_1188 -> V_1197 = V_1177 ;
V_1188 -> V_1198 = V_1199 ;
V_1188 -> V_1200 = V_1201 ;
V_1188 -> V_1202 [ 0 ] = 5 ;
V_1188 -> V_1202 [ 1 ] = 13 ;
V_1188 -> V_1203 = 2 ;
V_1188 -> V_1204 = V_1205 ;
V_1188 -> V_1206 = V_1207 ;
V_1188 -> V_1208 = 18 ;
V_7 = 0 ;
if ( V_23 -> V_163 -> V_118 & ( V_608 | V_121 ) ) {
for ( V_8 = 0 ; V_8 < V_202 -> V_203 && V_7 < V_1209 ; V_8 ++ ) {
if ( ( V_23 -> V_163 -> V_513 == V_514 ) &&
( V_202 -> V_204 [ V_8 ] . V_41 & V_207 ) )
continue;
V_1188 -> V_1149 [ V_7 ] . V_7 = V_202 -> V_204 [ V_8 ] . V_197 ;
V_1188 -> V_1149 [ V_7 ] . V_1184 = V_202 -> V_204 [ V_8 ] . V_1149 * 100000 ;
V_1188 -> V_1149 [ V_7 ] . V_1185 = 1 ;
V_7 ++ ;
}
}
if ( V_23 -> V_163 -> V_118 & V_119 ) {
for ( V_8 = 0 ; V_8 < V_202 -> V_209 && V_7 < V_1209 ; V_8 ++ ) {
if ( ( V_23 -> V_163 -> V_513 == V_514 ) &&
( V_202 -> V_18 [ V_8 ] . V_41 & V_207 ) )
continue;
V_1188 -> V_1149 [ V_7 ] . V_7 = V_202 -> V_18 [ V_8 ] . V_197 ;
V_1188 -> V_1149 [ V_7 ] . V_1184 = V_202 -> V_18 [ V_8 ] . V_1149 * 100000 ;
V_1188 -> V_1149 [ V_7 ] . V_1185 = 1 ;
V_7 ++ ;
}
}
V_1188 -> V_349 = V_7 ;
V_1188 -> V_1210 = V_7 ;
F_60 ( & V_23 -> V_109 ) ;
V_1188 -> V_1211 [ 0 ] = ( V_1212 |
F_417 ( V_1213 ) |
F_417 ( V_218 ) |
F_417 ( V_657 ) ) ;
V_1188 -> V_1211 [ 1 ] = V_1214 ;
V_1188 -> V_1215 = V_1216 | V_1217 |
V_1218 | V_1219 ;
V_1188 -> V_1220 = V_1221 | V_1222 ;
F_325 ( L_414 ) ;
return 0 ;
}
static int F_418 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
if ( V_211 -> V_212 . V_213 != V_214 )
return - V_75 ;
F_59 ( & V_23 -> V_109 ) ;
if ( F_419 ( V_211 -> V_212 . V_215 ) ||
F_420 ( V_211 -> V_212 . V_215 ) ) {
F_325 ( L_415 ) ;
V_23 -> V_59 &= ~ V_818 ;
F_265 ( L_399
L_400 ) ;
V_332 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
V_23 -> V_59 |= V_818 ;
if ( F_213 ( V_23 -> V_216 , V_211 -> V_212 . V_215 ) ) {
F_325 ( L_416 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
F_325 ( L_417 ,
V_211 -> V_212 . V_215 ) ;
memcpy ( V_23 -> V_216 , V_211 -> V_212 . V_215 , V_217 ) ;
F_265 ( L_418 ) ;
if ( ! F_266 ( V_23 ) )
V_332 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_421 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_59 & V_818 ||
V_23 -> V_37 & ( V_103 | V_240 ) ) {
V_211 -> V_212 . V_213 = V_214 ;
memcpy ( V_211 -> V_212 . V_215 , V_23 -> V_216 , V_217 ) ;
} else
memset ( V_211 -> V_212 . V_215 , 0 , V_217 ) ;
F_325 ( L_419 ,
V_211 -> V_212 . V_215 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_422 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
int V_415 ;
F_59 ( & V_23 -> V_109 ) ;
if ( ! V_211 -> V_668 . V_41 )
{
F_325 ( L_420 ) ;
F_266 ( V_23 ) ;
V_23 -> V_59 &= ~ V_811 ;
V_332 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
V_415 = F_3 ( ( int ) V_211 -> V_668 . V_415 , V_313 ) ;
V_23 -> V_59 |= V_811 ;
if ( V_23 -> V_667 == V_415 && ! memcmp ( V_23 -> V_668 , V_903 , V_415 )
&& ( V_23 -> V_37 & ( V_103 | V_240 ) ) ) {
F_325 ( L_421 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
F_325 ( L_422 , V_415 , V_903 , V_415 ) ;
V_23 -> V_667 = V_415 ;
memcpy ( V_23 -> V_668 , V_903 , V_23 -> V_667 ) ;
F_265 ( L_423 ) ;
if ( ! F_266 ( V_23 ) )
V_332 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_423 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_59 & V_811 ||
V_23 -> V_37 & ( V_103 | V_240 ) ) {
F_325 ( L_424 ,
V_23 -> V_667 , V_23 -> V_668 ) ;
memcpy ( V_903 , V_23 -> V_668 , V_23 -> V_667 ) ;
V_211 -> V_668 . V_415 = V_23 -> V_667 ;
V_211 -> V_668 . V_41 = 1 ;
} else {
F_325 ( L_425 ) ;
V_211 -> V_668 . V_415 = 0 ;
V_211 -> V_668 . V_41 = 0 ;
}
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_424 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_325 ( L_426 , V_903 ) ;
if ( V_211 -> V_3 . V_415 > V_313 )
return - V_905 ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_3 . V_415 = F_6 ( T_1 , V_211 -> V_3 . V_415 , sizeof( V_23 -> V_1223 ) ) ;
memset ( V_23 -> V_1223 , 0 , sizeof( V_23 -> V_1223 ) ) ;
memcpy ( V_23 -> V_1223 , V_903 , V_211 -> V_3 . V_415 ) ;
F_195 ( L_151 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_425 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_325 ( L_427 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_3 . V_415 = strlen ( V_23 -> V_1223 ) ;
memcpy ( V_903 , V_23 -> V_1223 , V_211 -> V_3 . V_415 ) ;
V_211 -> V_3 . V_41 = 1 ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_426 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
int V_557 = 0 ;
F_325 ( L_428 , V_211 -> V_327 . V_25 ) ;
F_325 ( L_429 , 3 * V_211 -> V_327 . V_25 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_211 -> V_327 . V_1224 == 0 )
{
V_23 -> V_655 = V_1176 ;
V_23 -> V_647 = V_1175 ;
goto V_6;
}
if ( ( V_211 -> V_327 . V_25 > V_1225 ) ||
( V_211 -> V_327 . V_25 < V_1226 ) ) {
V_557 = - V_75 ;
goto V_6;
}
V_23 -> V_655 = V_211 -> V_327 . V_25 ;
V_23 -> V_647 = 3 * V_211 -> V_327 . V_25 ;
V_6:
F_60 ( & V_23 -> V_109 ) ;
return V_557 ;
}
static int F_427 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_327 . V_1224 = 1 ;
V_211 -> V_327 . V_25 = V_23 -> V_655 ;
F_60 ( & V_23 -> V_109 ) ;
F_325 ( L_430 ,
V_211 -> V_343 . V_1227 ? L_96 : L_97 , V_211 -> V_343 . V_25 ) ;
return 0 ;
}
static int F_428 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
T_3 V_1228 = V_211 -> V_1196 . V_25 ;
T_3 V_1224 , V_36 ;
if ( V_1228 == - 1 ) {
V_1224 = 0 ;
V_36 = V_1174 ;
goto V_1229;
}
V_36 = 0 ;
V_1224 = V_211 -> V_1196 . V_1224 ;
if ( V_1228 == 1000000 || ! V_1224 )
V_36 |= V_596 ;
if ( V_1228 == 1000000 )
goto V_1229;
if ( V_1228 == 2000000 || ! V_1224 )
V_36 |= V_597 ;
if ( V_1228 == 2000000 )
goto V_1229;
if ( V_1228 == 5500000 || ! V_1224 )
V_36 |= V_598 ;
if ( V_1228 == 5500000 )
goto V_1229;
if ( V_1228 == 6000000 || ! V_1224 )
V_36 |= V_599 ;
if ( V_1228 == 6000000 )
goto V_1229;
if ( V_1228 == 9000000 || ! V_1224 )
V_36 |= V_600 ;
if ( V_1228 == 9000000 )
goto V_1229;
if ( V_1228 == 11000000 || ! V_1224 )
V_36 |= V_601 ;
if ( V_1228 == 11000000 )
goto V_1229;
if ( V_1228 == 12000000 || ! V_1224 )
V_36 |= V_602 ;
if ( V_1228 == 12000000 )
goto V_1229;
if ( V_1228 == 18000000 || ! V_1224 )
V_36 |= V_603 ;
if ( V_1228 == 18000000 )
goto V_1229;
if ( V_1228 == 24000000 || ! V_1224 )
V_36 |= V_604 ;
if ( V_1228 == 24000000 )
goto V_1229;
if ( V_1228 == 36000000 || ! V_1224 )
V_36 |= V_605 ;
if ( V_1228 == 36000000 )
goto V_1229;
if ( V_1228 == 48000000 || ! V_1224 )
V_36 |= V_606 ;
if ( V_1228 == 48000000 )
goto V_1229;
if ( V_1228 == 54000000 || ! V_1224 )
V_36 |= V_607 ;
if ( V_1228 == 54000000 )
goto V_1229;
F_325 ( L_431 ) ;
return - V_75 ;
V_1229:
F_325 ( L_432 ,
V_36 , V_1224 ? L_433 : L_434 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_36 == V_1174 ) {
V_23 -> V_59 &= ~ V_1024 ;
F_324 ( V_23 , V_23 -> V_163 -> V_118 ) ;
} else
V_23 -> V_59 |= V_1024 ;
if ( V_23 -> V_594 == V_36 ) {
F_325 ( L_435 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
V_23 -> V_594 = V_36 ;
F_265 ( L_436 ) ;
if ( ! F_266 ( V_23 ) )
V_332 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_429 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_1196 . V_25 = V_23 -> V_583 ;
V_211 -> V_1196 . V_1224 = ( V_23 -> V_59 & V_1024 ) ? 1 : 0 ;
F_60 ( & V_23 -> V_109 ) ;
F_325 ( L_437 , V_211 -> V_1196 . V_25 ) ;
return 0 ;
}
static int F_430 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_211 -> V_355 . V_1227 || ! V_211 -> V_355 . V_1224 )
V_23 -> V_357 = V_1177 ;
else {
if ( V_211 -> V_355 . V_25 < V_1230 ||
V_211 -> V_355 . V_25 > V_1231 ) {
F_60 ( & V_23 -> V_109 ) ;
return - V_75 ;
}
V_23 -> V_357 = V_211 -> V_355 . V_25 ;
}
F_182 ( V_23 , V_23 -> V_357 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_325 ( L_438 , V_23 -> V_357 ) ;
return 0 ;
}
static int F_431 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_355 . V_25 = V_23 -> V_357 ;
V_211 -> V_355 . V_1224 = 0 ;
V_211 -> V_355 . V_1227 = ( V_211 -> V_355 . V_25 == V_1177 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_325 ( L_439 , V_211 -> V_355 . V_25 ) ;
return 0 ;
}
static int F_432 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
int V_557 = 0 ;
F_59 ( & V_23 -> V_109 ) ;
if ( F_126 ( V_23 , V_211 -> V_343 . V_1227 ) ) {
V_557 = - V_1232 ;
goto V_6;
}
if ( ! V_211 -> V_343 . V_1224 )
V_211 -> V_343 . V_25 = V_1181 ;
if ( V_211 -> V_343 . V_41 != V_1233 ) {
V_557 = - V_75 ;
goto V_6;
}
if ( ( V_211 -> V_343 . V_25 > V_1234 ) ||
( V_211 -> V_343 . V_25 < V_1235 ) ) {
V_557 = - V_75 ;
goto V_6;
}
V_23 -> V_345 = V_211 -> V_343 . V_25 ;
V_557 = F_181 ( V_23 ) ;
V_6:
F_60 ( & V_23 -> V_109 ) ;
return V_557 ;
}
static int F_433 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_343 . V_25 = V_23 -> V_345 ;
V_211 -> V_343 . V_1224 = 1 ;
V_211 -> V_343 . V_41 = V_1233 ;
V_211 -> V_343 . V_1227 = ( V_23 -> V_37 & V_99 ) ? 1 : 0 ;
F_60 ( & V_23 -> V_109 ) ;
F_325 ( L_440 ,
V_211 -> V_343 . V_1227 ? L_96 : L_97 , V_211 -> V_343 . V_25 ) ;
return 0 ;
}
static int F_434 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_211 -> V_359 . V_1227 || ! V_211 -> V_359 . V_1224 )
V_23 -> V_163 -> V_1236 = V_1237 ;
else {
if ( V_211 -> V_359 . V_25 < V_1199 ||
V_211 -> V_359 . V_25 > V_1201 ) {
F_60 ( & V_23 -> V_109 ) ;
return - V_75 ;
}
V_23 -> V_163 -> V_1236 = V_211 -> V_359 . V_25 & ~ 0x1 ;
}
F_183 ( V_23 , V_211 -> V_359 . V_25 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_325 ( L_441 , V_211 -> V_359 . V_25 ) ;
return 0 ;
}
static int F_435 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_359 . V_25 = V_23 -> V_163 -> V_1236 ;
V_211 -> V_359 . V_1224 = 0 ;
V_211 -> V_359 . V_1227 = ( V_211 -> V_359 . V_25 == V_1237 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_325 ( L_442 , V_211 -> V_359 . V_25 ) ;
return 0 ;
}
static int F_436 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
if ( V_211 -> V_517 . V_41 & V_1238 || V_211 -> V_517 . V_1227 )
return - V_75 ;
if ( ! ( V_211 -> V_517 . V_41 & V_1239 ) )
return 0 ;
if ( V_211 -> V_517 . V_25 < 0 || V_211 -> V_517 . V_25 >= 255 )
return - V_75 ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_211 -> V_517 . V_41 & V_1240 )
V_23 -> V_372 = ( T_2 ) V_211 -> V_517 . V_25 ;
else if ( V_211 -> V_517 . V_41 & V_1241 )
V_23 -> V_373 = ( T_2 ) V_211 -> V_517 . V_25 ;
else {
V_23 -> V_372 = ( T_2 ) V_211 -> V_517 . V_25 ;
V_23 -> V_373 = ( T_2 ) V_211 -> V_517 . V_25 ;
}
F_185 ( V_23 , V_23 -> V_372 ,
V_23 -> V_373 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_325 ( L_443 ,
V_23 -> V_372 , V_23 -> V_373 ) ;
return 0 ;
}
static int F_437 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_517 . V_1227 = 0 ;
if ( ( V_211 -> V_517 . V_41 & V_1242 ) == V_1238 ) {
F_60 ( & V_23 -> V_109 ) ;
return - V_75 ;
}
if ( V_211 -> V_517 . V_41 & V_1241 ) {
V_211 -> V_517 . V_41 = V_1239 | V_1241 ;
V_211 -> V_517 . V_25 = V_23 -> V_373 ;
} else if ( V_211 -> V_517 . V_41 & V_1240 ) {
V_211 -> V_517 . V_41 = V_1239 | V_1240 ;
V_211 -> V_517 . V_25 = V_23 -> V_372 ;
} else {
V_211 -> V_517 . V_41 = V_1239 ;
V_211 -> V_517 . V_25 = V_23 -> V_372 ;
}
F_60 ( & V_23 -> V_109 ) ;
F_325 ( L_444 , V_211 -> V_517 . V_25 ) ;
return 0 ;
}
static int F_438 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
struct V_1243 * V_1244 = (struct V_1243 * ) V_903 ;
struct V_1245 * V_107 = NULL ;
F_59 ( & V_23 -> V_109 ) ;
V_23 -> V_658 = 1 ;
if ( V_211 -> V_3 . V_415 == sizeof( struct V_1243 ) ) {
if ( V_211 -> V_3 . V_41 & V_1246 ) {
int V_4 = F_3 ( ( int ) V_1244 -> V_667 ,
( int ) sizeof( V_23 -> V_882 ) ) ;
memcpy ( V_23 -> V_882 , V_1244 -> V_668 , V_4 ) ;
V_23 -> V_873 = V_4 ;
V_107 = & V_23 -> V_187 ;
} else if ( V_1244 -> V_700 == V_875 ) {
V_107 = & V_23 -> V_188 ;
}
} else {
V_107 = & V_23 -> V_186 ;
}
F_60 ( & V_23 -> V_109 ) ;
F_325 ( L_445 ) ;
F_56 ( V_107 , 0 ) ;
return 0 ;
}
static int F_439 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
return F_440 ( V_23 -> V_163 , V_902 , V_211 , V_903 ) ;
}
static int F_441 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_829 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
int V_432 ;
T_3 V_1247 = V_23 -> V_317 ;
F_59 ( & V_23 -> V_109 ) ;
V_432 = F_442 ( V_23 -> V_163 , V_902 , V_211 , V_829 ) ;
if ( V_1247 != V_23 -> V_317 &&
V_23 -> V_163 -> V_513 == V_514 &&
V_23 -> V_37 & V_103 )
F_266 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_432 ;
}
static int F_443 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_829 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
return F_444 ( V_23 -> V_163 , V_902 , V_211 , V_829 ) ;
}
static int F_445 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
int V_557 ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_211 -> V_343 . V_1227 ) {
V_23 -> V_1180 = F_446 ( V_23 -> V_1180 ) ;
V_557 = F_184 ( V_23 , V_366 ) ;
if ( V_557 ) {
F_325 ( L_446 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_557 ;
}
F_325 ( L_447 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
switch ( V_211 -> V_343 . V_41 & V_1248 ) {
case V_1249 :
case V_1248 :
case V_1250 :
break;
default:
F_325 ( L_448 ,
V_211 -> V_343 . V_41 ) ;
F_60 ( & V_23 -> V_109 ) ;
return - V_897 ;
}
if ( F_446 ( V_23 -> V_1180 ) == V_365 )
V_23 -> V_1180 = V_1251 | V_363 ;
else
V_23 -> V_1180 = V_1251 | V_23 -> V_1180 ;
V_557 = F_184 ( V_23 , F_446 ( V_23 -> V_1180 ) ) ;
if ( V_557 ) {
F_325 ( L_446 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_557 ;
}
F_325 ( L_449 , V_23 -> V_1180 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_447 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( ! ( V_23 -> V_1180 & V_1251 ) )
V_211 -> V_343 . V_1227 = 1 ;
else
V_211 -> V_343 . V_1227 = 0 ;
F_60 ( & V_23 -> V_109 ) ;
F_325 ( L_450 , V_23 -> V_1180 ) ;
return 0 ;
}
static int F_448 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
int V_118 = * ( int * ) V_903 ;
int V_557 ;
F_59 ( & V_23 -> V_109 ) ;
if ( ( V_118 < 1 ) || ( V_118 > V_1252 ) )
V_118 = V_365 ;
if ( F_446 ( V_23 -> V_1180 ) != V_118 ) {
V_557 = F_184 ( V_23 , V_118 ) ;
if ( V_557 ) {
F_325 ( L_446 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_557 ;
}
V_23 -> V_1180 = V_1251 | V_118 ;
}
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_449 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
int V_11 = F_446 ( V_23 -> V_1180 ) ;
char * V_134 = V_903 ;
V_134 += snprintf ( V_134 , V_1253 , L_451 , V_11 ) ;
switch ( V_11 ) {
case V_365 :
V_134 += snprintf ( V_134 , V_1253 - ( V_134 - V_903 ) , L_452 ) ;
break;
case V_363 :
V_134 += snprintf ( V_134 , V_1253 - ( V_134 - V_903 ) , L_453 ) ;
break;
default:
V_134 += snprintf ( V_134 , V_1253 - ( V_134 - V_903 ) ,
L_454 ,
V_1254 [ V_11 - 1 ] / 1000 ,
V_1255 [ V_11 - 1 ] / 1000 ) ;
}
if ( ! ( V_23 -> V_1180 & V_1251 ) )
V_134 += snprintf ( V_134 , V_1253 - ( V_134 - V_903 ) , L_455 ) ;
V_211 -> V_3 . V_415 = V_134 - V_903 + 1 ;
return 0 ;
}
static int F_450 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
int V_118 = * ( int * ) V_903 ;
T_2 V_881 = 0 , V_804 = 0 ;
if ( V_118 == 0 || V_118 & ~ V_1256 ) {
F_93 ( L_456 , V_118 ) ;
return - V_75 ;
}
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_316 == V_1172 ) {
V_23 -> V_163 -> V_353 = 1 ;
if ( V_118 & V_119 ) {
V_881 |= V_819 ;
V_804 |= V_807 ;
} else
V_23 -> V_163 -> V_353 = 0 ;
} else {
if ( V_118 & V_119 ) {
F_93 ( L_457
L_458 ) ;
F_60 ( & V_23 -> V_109 ) ;
return - V_75 ;
}
V_23 -> V_163 -> V_353 = 0 ;
}
if ( V_118 & V_608 ) {
V_881 |= V_820 ;
V_804 |= V_1171 ;
} else
V_23 -> V_163 -> V_353 = 0 ;
if ( V_118 & V_121 ) {
V_881 |= V_820 ;
V_804 |= V_807 ;
} else
V_23 -> V_163 -> V_353 = 0 ;
V_23 -> V_163 -> V_118 = V_118 ;
V_23 -> V_163 -> V_860 = V_881 ;
V_23 -> V_163 -> V_804 = V_804 ;
F_451 ( V_23 , & V_23 -> V_336 ) ;
F_265 ( L_459 ) ;
if ( ! F_266 ( V_23 ) ) {
F_175 ( V_23 , & V_23 -> V_336 ) ;
V_332 ( V_23 ) ;
}
F_67 ( V_23 ) ;
F_325 ( L_460 ,
V_118 & V_119 ? 'a' : '.' ,
V_118 & V_608 ? 'b' : '.' , V_118 & V_121 ? 'g' : '.' ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_452 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
switch ( V_23 -> V_163 -> V_118 ) {
case V_119 :
strncpy ( V_903 , L_461 , V_1253 ) ;
break;
case V_608 :
strncpy ( V_903 , L_462 , V_1253 ) ;
break;
case V_119 | V_608 :
strncpy ( V_903 , L_463 , V_1253 ) ;
break;
case V_121 :
strncpy ( V_903 , L_464 , V_1253 ) ;
break;
case V_119 | V_121 :
strncpy ( V_903 , L_465 , V_1253 ) ;
break;
case V_608 | V_121 :
strncpy ( V_903 , L_466 , V_1253 ) ;
break;
case V_119 | V_608 | V_121 :
strncpy ( V_903 , L_467 , V_1253 ) ;
break;
default:
strncpy ( V_903 , L_468 , V_1253 ) ;
break;
}
V_903 [ V_1253 - 1 ] = '\0' ;
F_325 ( L_469 , V_903 ) ;
V_211 -> V_3 . V_415 = strlen ( V_903 ) + 1 ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_453 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
int V_118 = * ( int * ) V_903 ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_118 == 1 ) {
if ( ! ( V_23 -> V_59 & V_821 ) ) {
V_23 -> V_59 |= V_821 ;
F_265
( L_470 ) ;
if ( ! F_266 ( V_23 ) )
V_332 ( V_23 ) ;
}
goto V_766;
}
if ( V_118 == 0 ) {
V_23 -> V_59 &= ~ V_821 ;
goto V_766;
}
F_60 ( & V_23 -> V_109 ) ;
return - V_75 ;
V_766:
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_454 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_59 & V_821 )
snprintf ( V_211 -> V_158 , V_1257 , L_471 ) ;
else
snprintf ( V_211 -> V_158 , V_1257 , L_472 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_455 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
int * V_1258 = ( int * ) V_903 ;
int V_999 = ( V_1258 [ 0 ] > 0 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_325 ( L_473 , V_999 , V_1258 [ 1 ] ) ;
if ( V_999 ) {
if ( V_23 -> V_163 -> V_513 != V_515 ) {
#ifdef F_407
V_23 -> V_167 -> type = V_1168 ;
#else
V_23 -> V_167 -> type = V_1169 ;
#endif
F_128 ( & V_23 -> V_246 ) ;
}
F_410 ( V_23 , V_1258 [ 1 ] ) ;
} else {
if ( V_23 -> V_163 -> V_513 != V_515 ) {
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
V_23 -> V_167 -> type = V_214 ;
F_128 ( & V_23 -> V_246 ) ;
}
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_456 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
F_325 ( L_474 ) ;
F_128 ( & V_23 -> V_246 ) ;
return 0 ;
}
static int F_457 ( struct V_165 * V_166 ,
struct V_901 * V_902 ,
union V_210 * V_211 , char * V_903 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
union V_210 V_1259 = {
. V_1260 = {
. V_41 = V_1261 ,
} ,
} ;
int V_432 ;
F_325 ( L_475 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_432 = F_409 ( V_23 , 2 ) ;
if ( ! V_432 ) {
F_241 () ;
F_160 ( V_23 ) ;
}
F_126 ( V_23 , V_23 -> V_37 & V_184 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_442 ( V_23 -> V_163 , V_902 , & V_1259 , NULL ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( ! ( V_23 -> V_37 & V_99 ) ) {
F_265 ( L_476
L_477 ) ;
if ( ! F_266 ( V_23 ) )
V_332 ( V_23 ) ;
}
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static struct V_1262 * F_458 ( struct V_165 * V_166 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
struct V_1262 * V_1066 ;
V_1066 = & V_23 -> V_1066 ;
if ( ! ( V_23 -> V_37 & V_103 ) ) {
V_1066 -> V_1263 . V_1264 = 0 ;
V_1066 -> V_1067 . V_512 = 0 ;
V_1066 -> V_1191 . V_1191 = 0 ;
V_1066 -> V_1191 . V_11 = 0 ;
V_1066 -> V_1191 . V_737 = 0 ;
V_1066 -> V_1191 . V_1192 = 7 ;
V_1066 -> V_1191 . V_1192 |= V_1265 |
V_1266 | V_1267 ;
return V_1066 ;
}
V_1066 -> V_1191 . V_1191 = V_23 -> V_579 ;
V_1066 -> V_1191 . V_11 = V_23 -> V_581 ;
V_1066 -> V_1191 . V_737 = V_23 -> V_582 ;
V_1066 -> V_1191 . V_1192 = V_1268 | V_1269 |
V_1270 | V_1271 ;
V_1066 -> V_1263 . V_1264 = F_275 ( & V_23 -> V_580 ) ;
V_1066 -> V_1067 . V_512 = V_23 -> V_587 ;
V_1066 -> V_1067 . V_1272 = V_23 -> V_163 -> V_1273 . V_1274 ;
return V_1066 ;
}
static void F_459 ( struct V_1275 * V_310 )
{
memset ( V_310 , 0 , sizeof( struct V_1275 ) ) ;
V_310 -> V_1276 = 0 ;
V_310 -> V_1044 = 0 ;
V_310 -> V_565 = 0 ;
V_310 -> V_566 = 1 ;
V_310 -> V_1277 = 0 ;
V_310 -> V_844 = 1 ;
V_310 -> V_1278 = 0 ;
V_310 -> V_849 = 1 ;
if ( V_1279 < V_1280 || V_1279 > V_1281 )
V_1279 = V_1280 ;
V_310 -> V_1282 = V_1279 ;
V_310 -> V_1283 = 0 ;
V_310 -> V_1043 = 0 ;
V_310 -> V_1284 = 0 ;
V_310 -> V_1285 = 0 ;
V_310 -> V_1286 = 1 ;
V_310 -> V_1287 = 0x1e ;
}
static int F_460 ( struct V_165 * V_166 )
{
F_74 ( L_478 ) ;
F_461 ( V_166 ) ;
return 0 ;
}
static int F_462 ( struct V_165 * V_166 )
{
F_74 ( L_479 ) ;
F_463 ( V_166 ) ;
return 0 ;
}
static int F_464 ( struct V_17 * V_23 , struct V_1288 * V_532 ,
int V_1289 )
{
struct V_1290 * V_1054 = (struct V_1290 * )
V_532 -> V_1291 [ 0 ] -> V_3 ;
int V_7 = 0 ;
struct V_534 * V_768 ;
#ifdef F_291
int V_1292 = F_362 ( V_23 , V_1289 ) ;
struct V_531 * V_230 = & V_23 -> V_230 [ V_1292 ] ;
#else
struct V_531 * V_230 = & V_23 -> V_230 [ 0 ] ;
#endif
struct V_523 * V_521 = & V_230 -> V_521 ;
T_2 V_1293 , V_1294 , V_1007 ;
int V_1055 ;
if ( ! ( V_23 -> V_37 & V_103 ) )
goto V_1135;
V_1294 = F_391 ( F_222 ( V_1054 -> V_1136 ) ) ;
switch ( V_23 -> V_163 -> V_513 ) {
case V_514 :
V_1007 = ! F_364 ( V_1054 -> V_1070 ) ;
V_1293 = F_263 ( V_23 , V_1054 -> V_1070 ) ;
if ( V_1293 == V_552 ) {
V_1293 = F_262 ( V_23 , V_1054 -> V_1070 ) ;
if ( V_1293 == V_552 ) {
F_93 ( L_480
L_481 ,
V_1054 -> V_1070 ) ;
goto V_1135;
}
}
break;
case V_516 :
default:
V_1007 = ! F_364 ( V_1054 -> V_1119 ) ;
V_1293 = 0 ;
break;
}
V_768 = & V_230 -> V_533 [ V_521 -> V_525 ] ;
V_230 -> V_532 [ V_521 -> V_525 ] = V_532 ;
memset ( V_768 , 0 , sizeof( * V_768 ) ) ;
V_768 -> V_538 . V_3 . V_1295 = V_1293 ;
V_768 -> V_535 . V_536 = V_1296 ;
V_768 -> V_535 . V_770 = V_771 ;
V_768 -> V_538 . V_3 . V_836 = V_1297 ;
V_768 -> V_538 . V_3 . V_4 = F_173 ( V_532 -> V_1298 ) ;
if ( V_23 -> V_559 . V_347 == V_352 )
V_768 -> V_538 . V_3 . V_1010 |= V_1299 ;
else
V_768 -> V_538 . V_3 . V_1010 |= V_1300 ;
if ( V_23 -> V_559 . V_1030 == V_1031 )
V_768 -> V_538 . V_3 . V_1013 |= V_1031 ;
V_1055 = F_222 ( V_1054 -> V_1136 ) ;
V_1054 -> V_1136 = F_173 ( V_1055 & ~ V_1301 ) ;
memcpy ( & V_768 -> V_538 . V_3 . V_768 . V_1302 . V_1016 , V_1054 , V_1294 ) ;
if ( F_465 ( V_1007 ) )
V_768 -> V_538 . V_3 . V_1013 |= V_1014 ;
if ( V_532 -> V_1303 && ! V_23 -> V_163 -> V_842 ) {
switch ( V_23 -> V_163 -> V_244 . V_11 ) {
case V_843 :
V_768 -> V_538 . V_3 . V_768 . V_1302 . V_1016 . V_1136 |=
F_173 ( V_1057 ) ;
if ( ! V_1007 )
V_768 -> V_538 . V_3 . V_1013 |= V_1014 ;
V_768 -> V_538 . V_3 . V_1013 &= ~ V_1304 ;
V_768 -> V_538 . V_3 . V_1010 |= V_851 ;
V_768 -> V_538 . V_3 . V_839 = 0 ;
V_768 -> V_538 . V_3 . V_839 |= V_1305 ;
break;
case V_846 :
V_768 -> V_538 . V_3 . V_768 . V_1302 . V_1016 . V_1136 |=
F_173 ( V_1057 ) ;
V_768 -> V_538 . V_3 . V_1013 &= ~ V_1304 ;
V_768 -> V_538 . V_3 . V_1010 |= V_855 ;
V_768 -> V_538 . V_3 . V_839 = V_1305 ;
break;
case V_847 :
V_768 -> V_538 . V_3 . V_768 . V_1302 . V_1016 . V_1136 |=
F_173 ( V_1057 ) ;
V_768 -> V_538 . V_3 . V_839 = V_23 -> V_163 -> V_921 . V_922 ;
if ( V_23 -> V_163 -> V_244 . V_841 [ V_23 -> V_163 -> V_921 . V_922 ] <=
40 )
V_768 -> V_538 . V_3 . V_839 |= V_1306 ;
else
V_768 -> V_538 . V_3 . V_839 |= V_1307 ;
break;
case V_848 :
break;
default:
F_4 ( V_1059 L_372 ,
V_23 -> V_163 -> V_244 . V_11 ) ;
break;
}
} else
V_768 -> V_538 . V_3 . V_1013 |= V_1304 ;
#ifdef F_291
if ( V_1055 & V_1308 )
F_365 ( V_23 , V_1289 , & ( V_768 -> V_538 . V_3 ) ) ;
#endif
V_768 -> V_538 . V_3 . V_539 = F_179 ( F_3 ( ( T_2 ) ( V_540 - 2 ) ,
V_532 -> V_1309 ) ) ;
F_466 ( L_482 ,
V_532 -> V_1309 , F_227 ( V_768 -> V_538 . V_3 . V_539 ) ) ;
for ( V_7 = 0 ; V_7 < F_227 ( V_768 -> V_538 . V_3 . V_539 ) ; V_7 ++ ) {
F_466 ( L_483 ,
V_7 , F_227 ( V_768 -> V_538 . V_3 . V_539 ) ,
V_532 -> V_1291 [ V_7 ] -> V_4 - V_1294 ) ;
F_145 ( L_484 ,
V_7 , V_768 -> V_538 . V_3 . V_539 ,
V_532 -> V_1291 [ V_7 ] -> V_4 - V_1294 ) ;
F_2 ( V_1310 , V_532 -> V_1291 [ V_7 ] -> V_3 + V_1294 ,
V_532 -> V_1291 [ V_7 ] -> V_4 - V_1294 ) ;
V_768 -> V_538 . V_3 . V_541 [ V_7 ] =
F_179 ( F_299
( V_23 -> V_477 ,
V_532 -> V_1291 [ V_7 ] -> V_3 + V_1294 ,
V_532 -> V_1291 [ V_7 ] -> V_4 - V_1294 ,
V_542 ) ) ;
V_768 -> V_538 . V_3 . V_478 [ V_7 ] =
F_173 ( V_532 -> V_1291 [ V_7 ] -> V_4 - V_1294 ) ;
}
if ( V_7 != V_532 -> V_1309 ) {
struct V_1005 * V_501 ;
T_4 V_1311 = 0 ;
int V_8 ;
for ( V_8 = V_7 ; V_8 < V_532 -> V_1309 ; V_8 ++ )
V_1311 += V_532 -> V_1291 [ V_8 ] -> V_4 - V_1294 ;
F_4 ( V_1312 L_485 ,
V_1311 ) ;
V_501 = F_298 ( V_1311 , V_139 ) ;
if ( V_501 != NULL ) {
V_768 -> V_538 . V_3 . V_478 [ V_7 ] = F_173 ( V_1311 ) ;
for ( V_8 = V_7 ; V_8 < V_532 -> V_1309 ; V_8 ++ ) {
int V_15 = V_532 -> V_1291 [ V_8 ] -> V_4 - V_1294 ;
F_4 ( V_1312 L_486 ,
V_8 , V_15 ) ;
memcpy ( F_381 ( V_501 , V_15 ) ,
V_532 -> V_1291 [ V_8 ] -> V_3 + V_1294 , V_15 ) ;
}
F_392 ( V_532 -> V_1291 [ V_7 ] ) ;
V_532 -> V_1291 [ V_7 ] = V_501 ;
V_768 -> V_538 . V_3 . V_541 [ V_7 ] =
F_179 ( F_299
( V_23 -> V_477 , V_501 -> V_3 ,
V_1311 ,
V_542 ) ) ;
F_467 ( & V_768 -> V_538 . V_3 . V_539 , 1 ) ;
}
}
V_521 -> V_525 = F_253 ( V_521 -> V_525 , V_521 -> V_526 ) ;
F_35 ( V_23 , V_521 -> V_530 , V_521 -> V_525 ) ;
if ( F_252 ( V_521 ) < V_521 -> V_528 )
F_463 ( V_23 -> V_167 ) ;
return V_1313 ;
V_1135:
F_378 ( L_487 ) ;
F_258 ( V_532 ) ;
return V_1313 ;
}
static int F_468 ( struct V_165 * V_166 , int V_1289 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
#ifdef F_291
int V_1292 = F_362 ( V_23 , V_1289 ) ;
struct V_531 * V_230 = & V_23 -> V_230 [ V_1292 ] ;
#else
struct V_531 * V_230 = & V_23 -> V_230 [ 0 ] ;
#endif
if ( F_252 ( & V_230 -> V_521 ) < V_230 -> V_521 . V_528 )
return 1 ;
return 0 ;
}
static void F_469 ( struct V_17 * V_23 ,
struct V_1288 * V_532 )
{
struct V_673 V_1314 ;
struct V_1053 * V_1054 ;
T_2 V_172 ;
T_4 V_161 = V_23 -> V_159 -> V_161 ;
int V_1108 = 0 ;
if ( V_161 & V_1315 )
return;
memset ( & V_1314 , 0 , sizeof( V_1314 ) ) ;
V_1054 = ( void * ) V_532 -> V_1291 [ 0 ] -> V_3 ;
if ( F_387 ( F_222 ( V_1054 -> V_1056 ) ) ) {
if ( V_161 & V_1110 )
return;
if ( V_161 & V_1111 )
V_1108 = 1 ;
} else if ( F_388 ( F_222 ( V_1054 -> V_1056 ) ) ) {
if ( V_161 & V_1112 )
return;
if ( V_161 & V_1113 )
V_1108 = 1 ;
} else if ( F_389 ( F_222 ( V_1054 -> V_1056 ) ) ) {
if ( V_161 & V_1114 )
return;
if ( V_161 & V_1115 )
V_1108 = 1 ;
}
for( V_172 = 0 ; V_172 < V_532 -> V_1309 ; ++ V_172 ) {
struct V_1005 * V_803 = V_532 -> V_1291 [ V_172 ] ;
struct V_1005 * V_1316 ;
struct V_1317 * V_1079 ;
int V_4 ;
if ( V_1108 ) {
V_1054 = ( void * ) V_803 -> V_3 ;
V_4 = F_391 ( F_222 ( V_1054 -> V_1056 ) ) ;
} else
V_4 = V_803 -> V_4 ;
V_1316 = F_298 ( V_4 + sizeof( * V_1079 ) + sizeof( T_4 ) * 2 , V_139 ) ;
if ( ! V_1316 )
continue;
V_1079 = ( void * ) F_381 ( V_1316 , sizeof( * V_1079 ) ) ;
V_1079 -> V_1080 = V_1081 ;
V_1079 -> V_1082 = 0 ;
V_1079 -> V_1084 = 0 ;
V_1079 -> V_1084 |= F_179 ( 1 << V_1088 ) ;
* ( T_8 * ) F_381 ( V_1316 , sizeof( T_4 ) ) = F_173 (
F_385 ( V_23 -> V_197 ) ) ;
if ( V_23 -> V_197 > 14 )
* ( T_8 * ) F_381 ( V_1316 , sizeof( T_4 ) ) =
F_173 ( V_1100 |
V_1101 ) ;
else if ( V_23 -> V_163 -> V_118 == V_608 )
* ( T_8 * ) F_381 ( V_1316 , sizeof( T_4 ) ) =
F_173 ( V_1102 |
V_1103 ) ;
else
* ( T_8 * ) F_381 ( V_1316 , sizeof( T_4 ) ) =
F_173 ( V_1100 |
V_1103 ) ;
V_1079 -> V_1083 = F_173 ( V_1316 -> V_4 ) ;
F_470 ( V_803 , F_381 ( V_1316 , V_4 ) , V_4 ) ;
if ( ! F_383 ( V_23 -> V_159 -> V_163 , V_1316 , & V_1314 ) )
F_392 ( V_1316 ) ;
}
}
static T_12 F_471 ( struct V_1288 * V_532 ,
struct V_165 * V_166 , int V_1289 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
unsigned long V_41 ;
T_12 V_432 ;
F_145 ( L_488 , V_532 -> V_1298 ) ;
F_41 ( & V_23 -> V_98 , V_41 ) ;
#ifdef F_270
if ( V_156 && F_92 ( V_23 -> V_157 ) )
F_469 ( V_23 , V_532 ) ;
#endif
V_432 = F_464 ( V_23 , V_532 , V_1289 ) ;
if ( V_432 == V_1313 )
F_63 ( V_23 ) ;
F_42 ( & V_23 -> V_98 , V_41 ) ;
return V_432 ;
}
static void F_472 ( struct V_165 * V_166 )
{
}
static int F_473 ( struct V_165 * V_166 , void * V_134 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
struct V_1318 * V_32 = V_134 ;
if ( ! F_474 ( V_32 -> V_215 ) )
return - V_1319 ;
F_59 ( & V_23 -> V_109 ) ;
V_23 -> V_59 |= V_1320 ;
memcpy ( V_23 -> V_543 , V_32 -> V_215 , V_217 ) ;
F_4 ( V_1312 L_144 ,
V_23 -> V_167 -> V_158 , V_23 -> V_543 ) ;
F_128 ( & V_23 -> V_246 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static void F_475 ( struct V_165 * V_166 ,
struct V_1321 * V_902 )
{
struct V_17 * V_134 = F_340 ( V_166 ) ;
char V_1322 [ 64 ] ;
char V_1323 [ 32 ] ;
T_3 V_4 ;
F_476 ( V_902 -> V_1324 , V_1325 , sizeof( V_902 -> V_1324 ) ) ;
F_476 ( V_902 -> V_983 , V_1326 , sizeof( V_902 -> V_983 ) ) ;
V_4 = sizeof( V_1322 ) ;
F_48 ( V_134 , V_1327 , V_1322 , & V_4 ) ;
V_4 = sizeof( V_1323 ) ;
F_48 ( V_134 , V_1328 , V_1323 , & V_4 ) ;
snprintf ( V_902 -> V_1329 , sizeof( V_902 -> V_1329 ) , L_489 ,
V_1322 , V_1323 ) ;
F_476 ( V_902 -> V_1330 , F_477 ( V_134 -> V_477 ) ,
sizeof( V_902 -> V_1330 ) ) ;
V_902 -> V_1331 = V_386 ;
}
static T_3 F_478 ( struct V_165 * V_166 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
return ( V_23 -> V_37 & V_103 ) != 0 ;
}
static int F_479 ( struct V_165 * V_166 )
{
return V_386 ;
}
static int F_480 ( struct V_165 * V_166 ,
struct V_1332 * V_123 , T_2 * V_1333 )
{
struct V_17 * V_134 = F_340 ( V_166 ) ;
if ( V_123 -> V_468 + V_123 -> V_4 > V_386 )
return - V_75 ;
F_59 ( & V_134 -> V_109 ) ;
memcpy ( V_1333 , & V_134 -> V_123 [ V_123 -> V_468 ] , V_123 -> V_4 ) ;
F_60 ( & V_134 -> V_109 ) ;
return 0 ;
}
static int F_481 ( struct V_165 * V_166 ,
struct V_1332 * V_123 , T_2 * V_1333 )
{
struct V_17 * V_134 = F_340 ( V_166 ) ;
int V_7 ;
if ( V_123 -> V_468 + V_123 -> V_4 > V_386 )
return - V_75 ;
F_59 ( & V_134 -> V_109 ) ;
memcpy ( & V_134 -> V_123 [ V_123 -> V_468 ] , V_1333 , V_123 -> V_4 ) ;
for ( V_7 = 0 ; V_7 < V_386 ; V_7 ++ )
F_197 ( V_134 , V_7 + V_387 , V_134 -> V_123 [ V_7 ] ) ;
F_60 ( & V_134 -> V_109 ) ;
return 0 ;
}
static T_13 F_482 ( int V_1334 , void * V_3 )
{
struct V_17 * V_23 = V_3 ;
T_3 V_219 , V_220 ;
if ( ! V_23 )
return V_1335 ;
F_483 ( & V_23 -> V_42 ) ;
if ( ! ( V_23 -> V_37 & V_38 ) ) {
goto V_1336;
}
V_219 = F_36 ( V_23 , V_222 ) ;
V_220 = F_36 ( V_23 , V_39 ) ;
if ( V_219 == 0xFFFFFFFF ) {
F_93 ( L_490 ) ;
goto V_1336;
}
if ( ! ( V_219 & ( V_40 & V_220 ) ) ) {
goto V_1336;
}
F_39 ( V_23 ) ;
V_219 &= ( V_40 & V_220 ) ;
F_35 ( V_23 , V_222 , V_219 ) ;
V_23 -> V_223 = V_219 ;
F_484 ( & V_23 -> V_1337 ) ;
F_485 ( & V_23 -> V_42 ) ;
return V_1338 ;
V_1336:
F_485 ( & V_23 -> V_42 ) ;
return V_1335 ;
}
static void F_486 ( void * V_316 )
{
struct V_17 * V_23 = V_316 ;
unsigned long V_41 ;
F_41 ( & V_23 -> V_98 , V_41 ) ;
if ( F_123 ( V_23 ) ) {
F_127 ( L_491 ) ;
F_56 ( & V_23 -> V_191 , 2 * V_192 ) ;
goto V_1339;
}
if ( ! ( V_23 -> V_37 & V_99 ) ) {
F_127 ( L_492
L_493 ) ;
F_128 ( & V_23 -> V_246 ) ;
} else
F_127 ( L_494
L_495 ) ;
V_1339:
F_42 ( & V_23 -> V_98 , V_41 ) ;
}
static void F_487 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_191 . V_107 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_486 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_488 ( struct V_17 * V_23 )
{
V_23 -> V_1131 = - 1 ;
V_23 -> V_1132 = - 1 ;
V_23 -> V_1133 = 0 ;
F_489 ( V_23 -> V_167 ) ;
F_64 ( & V_23 -> V_186 ) ;
F_64 ( & V_23 -> V_187 ) ;
F_64 ( & V_23 -> V_188 ) ;
F_64 ( & V_23 -> V_189 ) ;
F_276 ( V_23 ) ;
V_23 -> V_583 = F_278 ( V_23 ) ;
F_279 ( V_23 ) ;
F_71 ( V_23 ) ;
F_138 ( V_23 ) ;
if ( V_23 -> V_59 & V_708 )
F_56 ( & V_23 -> V_186 , V_192 ) ;
}
static void F_490 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_676 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_488 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_491 ( struct V_17 * V_23 )
{
F_72 ( V_23 ) ;
F_267 ( V_23 -> V_167 ) ;
F_138 ( V_23 ) ;
F_64 ( & V_23 -> V_186 ) ;
F_64 ( & V_23 -> V_187 ) ;
F_64 ( & V_23 -> V_188 ) ;
F_64 ( & V_23 -> V_669 ) ;
F_64 ( & V_23 -> V_644 ) ;
F_276 ( V_23 ) ;
if ( ! ( V_23 -> V_37 & V_701 ) ) {
F_56 ( & V_23 -> V_186 , 0 ) ;
} else
F_64 ( & V_23 -> V_189 ) ;
}
static void F_492 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_241 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_491 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int F_493 ( struct V_17 * V_23 )
{
int V_432 = 0 ;
F_494 ( & V_23 -> V_228 ) ;
F_494 ( & V_23 -> V_486 ) ;
F_495 ( & V_23 -> V_669 , F_322 ) ;
F_496 ( & V_23 -> V_333 , F_373 ) ;
F_496 ( & V_23 -> V_558 , F_268 ) ;
F_496 ( & V_23 -> V_564 , F_269 ) ;
F_496 ( & V_23 -> V_780 , F_300 ) ;
F_496 ( & V_23 -> V_246 , F_164 ) ;
F_495 ( & V_23 -> V_191 , F_487 ) ;
F_496 ( & V_23 -> V_193 , V_1340 ) ;
F_496 ( & V_23 -> V_190 , V_1341 ) ;
F_495 ( & V_23 -> V_186 , F_332 ) ;
F_495 ( & V_23 -> V_187 , F_333 ) ;
F_495 ( & V_23 -> V_188 , F_331 ) ;
F_495 ( & V_23 -> V_189 , F_286 ) ;
F_495 ( & V_23 -> V_644 , F_282 ) ;
F_496 ( & V_23 -> V_653 , F_334 ) ;
F_496 ( & V_23 -> V_706 , F_372 ) ;
F_495 ( & V_23 -> V_322 , F_169 ) ;
F_496 ( & V_23 -> V_676 , F_490 ) ;
F_496 ( & V_23 -> V_241 , F_492 ) ;
F_495 ( & V_23 -> V_108 , F_57 ) ;
F_495 ( & V_23 -> V_104 , F_62 ) ;
F_495 ( & V_23 -> V_114 , F_66 ) ;
F_496 ( & V_23 -> V_815 , F_311 ) ;
#ifdef F_291
F_496 ( & V_23 -> V_961 , F_366 ) ;
#endif
F_497 ( & V_23 -> V_1337 , ( void (*) ( unsigned long ) )
F_140 , ( unsigned long ) V_23 ) ;
return V_432 ;
}
static void F_498 ( struct V_165 * V_166 ,
struct V_886 * V_244 )
{
struct V_17 * V_23 = F_340 ( V_166 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
if ( V_244 -> V_41 & ( 1 << V_7 ) ) {
V_23 -> V_163 -> V_244 . V_1342 [ V_7 ] = V_244 -> V_1342 [ V_7 ] ;
V_23 -> V_163 -> V_244 . V_841 [ V_7 ] = V_244 -> V_841 [ V_7 ] ;
if ( V_244 -> V_841 [ V_7 ] == 0 )
V_23 -> V_163 -> V_244 . V_41 &= ~ ( 1 << V_7 ) ;
else {
memcpy ( V_23 -> V_163 -> V_244 . V_831 [ V_7 ] , V_244 -> V_831 [ V_7 ] ,
V_244 -> V_841 [ V_7 ] ) ;
V_23 -> V_163 -> V_244 . V_41 |= ( 1 << V_7 ) ;
}
V_23 -> V_37 |= V_1046 ;
} else if ( V_244 -> V_11 != V_847 )
V_23 -> V_163 -> V_244 . V_41 &= ~ ( 1 << V_7 ) ;
}
if ( V_244 -> V_41 & V_850 ) {
if ( V_244 -> V_852 <= 3 ) {
V_23 -> V_163 -> V_244 . V_852 = V_244 -> V_852 ;
V_23 -> V_163 -> V_244 . V_41 |= V_850 ;
} else
V_23 -> V_163 -> V_244 . V_41 &= ~ V_850 ;
V_23 -> V_37 |= V_1046 ;
} else
V_23 -> V_163 -> V_244 . V_41 &= ~ V_850 ;
if ( ( V_244 -> V_41 & V_887 ) &&
( V_23 -> V_163 -> V_244 . V_889 != V_244 -> V_889 ) ) {
V_23 -> V_163 -> V_244 . V_889 = V_244 -> V_889 ;
V_23 -> V_163 -> V_244 . V_41 |= V_887 ;
if ( V_244 -> V_889 == V_890 )
V_23 -> V_317 |= V_1035 ;
else
V_23 -> V_317 &= ~ V_1035 ;
V_23 -> V_37 |= V_1046 ;
}
if ( V_244 -> V_41 & V_928 && V_23 -> V_163 -> V_244 . V_929 != V_244 -> V_929 ) {
V_23 -> V_163 -> V_244 . V_41 |= V_928 ;
V_23 -> V_163 -> V_244 . V_929 = V_244 -> V_929 ;
V_23 -> V_37 |= V_1046 ;
if ( V_244 -> V_929 )
V_23 -> V_317 |= V_813 ;
else
V_23 -> V_317 &= ~ V_813 ;
}
if ( V_244 -> V_41 & V_1343 )
V_23 -> V_163 -> V_244 . V_245 = V_244 -> V_245 ;
if ( V_244 -> V_41 & V_931 && V_23 -> V_163 -> V_244 . V_11 != V_244 -> V_11 ) {
V_23 -> V_163 -> V_244 . V_11 = V_244 -> V_11 ;
V_23 -> V_163 -> V_244 . V_41 |= V_931 ;
V_23 -> V_37 |= V_1046 ;
}
if ( ! V_23 -> V_163 -> V_842 && ( V_244 -> V_41 & V_1343 ) )
F_320 ( V_23 ) ;
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
static int F_451 ( struct V_17 * V_23 ,
struct V_335 * V_336 )
{
memset ( V_336 , 0 , sizeof( * V_336 ) ) ;
switch ( V_23 -> V_163 -> V_860 ) {
case V_819 :
V_336 -> V_347 = V_354 ;
V_336 -> V_1041 = V_1344 ;
F_306 ( V_336 , V_1171 ,
V_1345 ) ;
break;
default:
V_336 -> V_347 = V_348 ;
V_336 -> V_1041 = V_1344 ;
F_305 ( V_336 , V_1171 ,
V_1346 ) ;
if ( V_23 -> V_163 -> V_804 & V_807 ) {
F_306 ( V_336 , V_1171 ,
V_1345 ) ;
}
break;
}
return 0 ;
}
static int F_499 ( struct V_17 * V_23 )
{
if ( F_181 ( V_23 ) )
goto error;
if ( F_159 ( V_23 , V_23 -> V_167 -> V_1118 ) )
goto error;
F_459 ( & V_23 -> V_310 ) ;
if ( V_1347 ) {
unsigned char V_1348 = V_23 -> V_123 [ V_1349 ] ;
if ( V_1348 & V_1350 )
V_23 -> V_310 . V_1276
|= V_1351 ;
if ( V_1348 & V_1352 )
V_23 -> V_310 . V_1276
|= V_1353 ;
}
#ifdef F_270
if ( V_23 -> V_157 && F_92 ( V_23 -> V_157 ) ) {
V_23 -> V_310 . V_565 = 1 ;
V_23 -> V_310 . V_566 = 1 ;
V_23 -> V_310 . V_567 = 1 ;
V_23 -> V_310 . V_568 = 1 ;
}
#endif
if ( V_23 -> V_163 -> V_513 == V_514 )
V_23 -> V_310 . V_1044 = 1 ;
else
V_23 -> V_310 . V_1044 = 0 ;
if ( F_157 ( V_23 ) )
goto error;
F_451 ( V_23 , & V_23 -> V_336 ) ;
if ( F_175 ( V_23 , & V_23 -> V_336 ) )
goto error;
if ( V_23 -> V_357 ) {
if ( F_182 ( V_23 , V_23 -> V_357 ) )
goto error;
}
#ifdef F_291
F_293 ( L_496 ) ;
F_353 ( V_23 , NULL ) ;
#endif
if ( F_176 ( V_23 ) )
goto error;
if ( F_156 ( V_23 ) )
goto error;
V_23 -> V_37 |= V_69 ;
F_73 ( V_23 ) ;
F_69 ( V_23 ) ;
V_23 -> V_646 = 0 ;
if ( ( V_23 -> V_317 & V_813 ) &&
( V_23 -> V_163 -> V_244 . V_11 == V_847 ) &&
! ( V_23 -> V_163 -> V_842 || V_23 -> V_163 -> V_845 ) )
F_320 ( V_23 ) ;
return 0 ;
error:
return - V_306 ;
}
static void F_500 ( struct V_17 * V_23 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_223 ( V_1354 ) ; V_8 ++ ) {
if ( ! memcmp ( & V_23 -> V_123 [ V_1355 ] ,
V_1354 [ V_8 ] . V_158 , 3 ) )
break;
}
if ( V_8 == F_223 ( V_1354 ) ) {
F_93 ( L_497 ,
V_23 -> V_123 [ V_1355 + 0 ] ,
V_23 -> V_123 [ V_1355 + 1 ] ,
V_23 -> V_123 [ V_1355 + 2 ] ) ;
V_8 = 0 ;
}
F_501 ( V_23 -> V_163 , & V_1354 [ V_8 ] ) ;
}
static int F_163 ( struct V_17 * V_23 )
{
int V_155 , V_7 ;
if ( V_23 -> V_1356 ) {
F_502 ( V_23 -> V_163 , V_23 -> V_1356 ) ;
V_23 -> V_1356 = 0 ;
}
if ( V_23 -> V_37 & V_701 )
return - V_306 ;
if ( V_149 && ! V_23 -> V_149 ) {
V_23 -> V_149 = F_503 ( V_149 , sizeof( * V_23 -> V_149 ) ,
V_148 ) ;
if ( V_23 -> V_149 == NULL ) {
F_46 ( L_498 ,
V_149 ) ;
return - V_476 ;
} else {
V_23 -> V_151 = V_149 ;
}
}
for ( V_7 = 0 ; V_7 < V_1357 ; V_7 ++ ) {
V_155 = F_243 ( V_23 ) ;
if ( V_155 ) {
F_46 ( L_196 , V_155 ) ;
return V_155 ;
}
F_52 ( V_23 ) ;
if ( ! ( V_23 -> V_59 & V_1320 ) )
F_193 ( V_23 , V_23 -> V_543 ) ;
memcpy ( V_23 -> V_167 -> V_1118 , V_23 -> V_543 , V_217 ) ;
F_500 ( V_23 ) ;
if ( V_23 -> V_37 & V_184 ) {
F_93 ( L_499 ) ;
return 0 ;
} else if ( F_123 ( V_23 ) ) {
F_93 ( L_500
L_501
L_502 ) ;
F_56 ( & V_23 -> V_191 , 2 * V_192 ) ;
return 0 ;
}
V_155 = F_499 ( V_23 ) ;
if ( ! V_155 ) {
F_74 ( L_503 , V_7 ) ;
F_56 ( & V_23 -> V_186 , 0 ) ;
return 0 ;
}
F_74 ( L_504 , V_155 ) ;
F_74 ( L_505 ,
V_7 , V_1357 ) ;
F_161 ( V_23 ) ;
}
F_46 ( L_506 , V_7 ) ;
return - V_306 ;
}
static void V_1340 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_193 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_163 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_504 ( struct V_17 * V_23 )
{
int V_7 ;
if ( V_23 -> V_37 & V_321 ) {
F_74 ( L_507 ) ;
F_168 ( V_23 ) ;
}
if ( V_23 -> V_37 & V_103 ) {
F_74 ( L_508 ) ;
F_266 ( V_23 ) ;
}
F_75 ( V_23 ) ;
for ( V_7 = 1000 ; V_7 && ( V_23 -> V_37 &
( V_560 |
V_103 | V_321 ) ) ; V_7 -- )
F_187 ( 10 ) ;
if ( V_23 -> V_37 & ( V_560 |
V_103 | V_321 ) )
F_74 ( L_509 ) ;
else
F_74 ( L_510 , 1000 - V_7 ) ;
F_178 ( V_23 , 0 ) ;
V_23 -> V_37 &= ~ V_69 ;
}
static void F_161 ( struct V_17 * V_23 )
{
int V_1358 = V_23 -> V_37 & V_701 ;
V_23 -> V_37 |= V_701 ;
if ( F_47 ( V_23 ) )
F_504 ( V_23 ) ;
if ( ! V_1358 )
V_23 -> V_37 &= ~ V_701 ;
F_43 ( V_23 ) ;
V_23 -> V_37 &= V_99 | V_701 ;
F_267 ( V_23 -> V_167 ) ;
F_231 ( V_23 ) ;
F_70 ( V_23 ) ;
}
static void V_1341 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_190 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_161 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int F_505 ( struct V_165 * V_166 )
{
int V_7 , V_155 = 0 ;
struct V_17 * V_23 = F_340 ( V_166 ) ;
const struct V_201 * V_202 = F_137 ( V_23 -> V_163 ) ;
struct V_1359 * V_182 = & V_23 -> V_163 -> V_182 ;
memcpy ( V_182 -> V_183 -> V_1360 , V_23 -> V_543 , V_217 ) ;
if ( V_202 -> V_203 ) {
struct V_1361 * V_1362 = & V_23 -> V_163 -> V_1362 ;
V_1362 -> V_881 = V_1363 ;
V_1362 -> V_1364 = V_202 -> V_203 ;
V_1362 -> V_869 = F_503 ( V_202 -> V_203 ,
sizeof( struct V_1365 ) ,
V_148 ) ;
if ( ! V_1362 -> V_869 ) {
V_155 = - V_476 ;
goto V_6;
}
for ( V_7 = 0 ; V_7 < V_202 -> V_203 ; V_7 ++ ) {
V_1362 -> V_869 [ V_7 ] . V_881 = V_1363 ;
V_1362 -> V_869 [ V_7 ] . V_1366 = V_202 -> V_204 [ V_7 ] . V_1149 ;
V_1362 -> V_869 [ V_7 ] . V_1367 = V_202 -> V_204 [ V_7 ] . V_197 ;
V_1362 -> V_869 [ V_7 ] . V_346 = V_202 -> V_204 [ V_7 ] . V_346 ;
if ( V_202 -> V_204 [ V_7 ] . V_41 & V_207 )
V_1362 -> V_869 [ V_7 ] . V_41 |=
V_1368 ;
if ( V_202 -> V_204 [ V_7 ] . V_41 & V_206 )
V_1362 -> V_869 [ V_7 ] . V_41 |=
V_1368 ;
if ( V_202 -> V_204 [ V_7 ] . V_41 & V_205 )
V_1362 -> V_869 [ V_7 ] . V_41 |=
V_1369 ;
}
V_1362 -> V_1370 = V_1371 ;
V_1362 -> V_1372 = V_1373 ;
V_182 -> V_183 -> V_1374 [ V_1363 ] = V_1362 ;
}
if ( V_202 -> V_209 ) {
struct V_1361 * V_1375 = & V_23 -> V_163 -> V_1375 ;
V_1375 -> V_881 = V_1376 ;
V_1375 -> V_1364 = V_202 -> V_209 ;
V_1375 -> V_869 = F_503 ( V_202 -> V_209 ,
sizeof( struct V_1365 ) ,
V_148 ) ;
if ( ! V_1375 -> V_869 ) {
V_155 = - V_476 ;
goto V_6;
}
for ( V_7 = 0 ; V_7 < V_202 -> V_209 ; V_7 ++ ) {
V_1375 -> V_869 [ V_7 ] . V_881 = V_1376 ;
V_1375 -> V_869 [ V_7 ] . V_1366 = V_202 -> V_18 [ V_7 ] . V_1149 ;
V_1375 -> V_869 [ V_7 ] . V_1367 = V_202 -> V_18 [ V_7 ] . V_197 ;
V_1375 -> V_869 [ V_7 ] . V_346 = V_202 -> V_18 [ V_7 ] . V_346 ;
if ( V_202 -> V_18 [ V_7 ] . V_41 & V_207 )
V_1375 -> V_869 [ V_7 ] . V_41 |=
V_1368 ;
if ( V_202 -> V_18 [ V_7 ] . V_41 & V_206 )
V_1375 -> V_869 [ V_7 ] . V_41 |=
V_1368 ;
if ( V_202 -> V_18 [ V_7 ] . V_41 & V_205 )
V_1375 -> V_869 [ V_7 ] . V_41 |=
V_1369 ;
}
V_1375 -> V_1370 = V_1377 ;
V_1375 -> V_1372 = V_1378 ;
V_182 -> V_183 -> V_1374 [ V_1376 ] = V_1375 ;
}
V_182 -> V_183 -> V_1379 = V_1380 ;
V_182 -> V_183 -> V_1381 = F_223 ( V_1380 ) ;
F_506 ( V_182 -> V_183 , & V_23 -> V_477 -> V_166 ) ;
if ( F_507 ( V_182 -> V_183 ) )
V_155 = - V_306 ;
V_6:
return V_155 ;
}
static int F_508 ( struct V_165 * V_166 )
{
struct V_1382 * V_159 = F_340 ( V_166 ) ;
struct V_17 * V_23 = V_159 -> V_23 ;
F_74 ( L_511 ) ;
F_267 ( V_166 ) ;
if ( V_23 -> V_163 -> V_513 != V_515 ) {
V_23 -> V_310 . V_565 = 1 ;
V_23 -> V_310 . V_566 = 1 ;
V_23 -> V_310 . V_567 = 1 ;
V_23 -> V_310 . V_568 = 1 ;
F_157 ( V_23 ) ;
}
return 0 ;
}
static int F_509 ( struct V_165 * V_166 )
{
struct V_1382 * V_159 = F_340 ( V_166 ) ;
struct V_17 * V_23 = V_159 -> V_23 ;
F_74 ( L_512 ) ;
if ( V_23 -> V_163 -> V_513 != V_515 ) {
V_23 -> V_310 . V_565 = 0 ;
V_23 -> V_310 . V_566 = 0 ;
V_23 -> V_310 . V_567 = 0 ;
V_23 -> V_310 . V_568 = 0 ;
F_157 ( V_23 ) ;
}
return 0 ;
}
static T_12 F_510 ( struct V_1005 * V_501 ,
struct V_165 * V_166 )
{
F_74 ( L_513 ) ;
F_240 ( V_501 ) ;
return V_1313 ;
}
static int F_95 ( struct V_17 * V_23 )
{
int V_155 = 0 ;
if ( V_23 -> V_157 )
return - V_160 ;
V_23 -> V_157 = F_511 ( sizeof( struct V_1382 ) , 1 ) ;
if ( V_23 -> V_157 == NULL )
return - V_476 ;
V_23 -> V_159 = F_340 ( V_23 -> V_157 ) ;
V_23 -> V_159 -> V_163 = F_512 ( V_23 -> V_157 ) ;
V_23 -> V_159 -> V_23 = V_23 ;
strcpy ( V_23 -> V_157 -> V_158 , L_514 ) ;
memcpy ( V_23 -> V_157 -> V_1118 , V_23 -> V_543 , V_217 ) ;
V_23 -> V_157 -> type = V_1168 ;
V_23 -> V_157 -> V_1383 = & V_1384 ;
V_23 -> V_159 -> V_163 -> V_513 = V_515 ;
F_513 ( V_23 -> V_157 , & V_23 -> V_477 -> V_166 ) ;
V_155 = F_514 ( V_23 -> V_157 ) ;
if ( V_155 ) {
F_515 ( V_23 -> V_157 , 1 ) ;
V_23 -> V_157 = NULL ;
return V_155 ;
}
return 0 ;
}
static void F_94 ( struct V_17 * V_23 )
{
if ( ! V_23 -> V_157 )
return;
F_516 ( V_23 -> V_157 ) ;
F_515 ( V_23 -> V_157 , 1 ) ;
V_23 -> V_157 = NULL ;
}
static int F_517 ( struct V_477 * V_1385 ,
const struct V_1386 * V_1387 )
{
int V_557 = 0 ;
struct V_165 * V_167 ;
void T_14 * V_137 ;
T_3 V_415 , V_21 ;
struct V_17 * V_23 ;
int V_7 ;
V_167 = F_511 ( sizeof( struct V_17 ) , 0 ) ;
if ( V_167 == NULL ) {
V_557 = - V_476 ;
goto V_6;
}
V_23 = F_340 ( V_167 ) ;
V_23 -> V_163 = F_512 ( V_167 ) ;
V_23 -> V_167 = V_167 ;
V_23 -> V_477 = V_1385 ;
V_12 = V_1388 ;
F_301 ( & V_23 -> V_42 ) ;
F_301 ( & V_23 -> V_98 ) ;
for ( V_7 = 0 ; V_7 < V_1127 ; V_7 ++ )
F_238 ( & V_23 -> V_1128 [ V_7 ] ) ;
F_518 ( & V_23 -> V_109 ) ;
if ( F_519 ( V_1385 ) ) {
V_557 = - V_1389 ;
goto V_1390;
}
F_520 ( V_1385 ) ;
V_557 = F_521 ( V_1385 , F_522 ( 32 ) ) ;
if ( ! V_557 )
V_557 = F_523 ( V_1385 , F_522 ( 32 ) ) ;
if ( V_557 ) {
F_4 (KERN_WARNING DRV_NAME L_515 ) ;
goto V_1391;
}
F_524 ( V_1385 , V_23 ) ;
V_557 = F_525 ( V_1385 , V_1325 ) ;
if ( V_557 )
goto V_1391;
F_526 ( V_1385 , 0x40 , & V_21 ) ;
if ( ( V_21 & 0x0000ff00 ) != 0 )
F_527 ( V_1385 , 0x40 , V_21 & 0xffff00ff ) ;
V_415 = F_528 ( V_1385 , 0 ) ;
V_23 -> V_1392 = V_415 ;
V_137 = F_529 ( V_1385 , 0 ) ;
if ( ! V_137 ) {
V_557 = - V_1389 ;
goto V_1393;
}
V_23 -> V_22 = V_137 ;
F_74 ( L_516 , V_415 ) ;
F_74 ( L_517 , V_137 ) ;
V_557 = F_493 ( V_23 ) ;
if ( V_557 ) {
F_46 ( L_518 ) ;
goto V_1394;
}
F_409 ( V_23 , 1 ) ;
V_557 = F_530 ( V_1385 -> V_1334 , F_482 , V_1395 , V_1325 , V_23 ) ;
if ( V_557 ) {
F_46 ( L_519 , V_1385 -> V_1334 ) ;
goto V_1394;
}
F_513 ( V_167 , & V_1385 -> V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_23 -> V_163 -> V_1396 = F_471 ;
V_23 -> V_163 -> V_896 = F_498 ;
V_23 -> V_163 -> V_1397 = F_468 ;
#ifdef F_291
V_23 -> V_163 -> V_1398 = F_363 ;
V_23 -> V_163 -> V_1399 = F_368 ;
V_23 -> V_163 -> V_1400 = F_367 ;
V_23 -> V_163 -> V_1401 = F_369 ;
#endif
V_23 -> V_163 -> V_642 = - 20 ;
V_23 -> V_163 -> V_643 = - 85 ;
V_167 -> V_1383 = & V_1402 ;
V_23 -> V_1403 . V_1404 = & V_23 -> V_163 -> V_1404 ;
V_167 -> V_1403 = & V_23 -> V_1403 ;
V_167 -> V_1405 = & V_1406 ;
V_167 -> V_1407 = & V_1408 ;
V_557 = F_531 ( & V_1385 -> V_166 . V_1409 , & V_1410 ) ;
if ( V_557 ) {
F_46 ( L_520 ) ;
F_60 ( & V_23 -> V_109 ) ;
goto V_1411;
}
if ( F_163 ( V_23 ) ) {
F_60 ( & V_23 -> V_109 ) ;
V_557 = - V_306 ;
goto V_1412;
}
F_60 ( & V_23 -> V_109 ) ;
V_557 = F_505 ( V_167 ) ;
if ( V_557 ) {
F_46 ( L_521 ) ;
goto V_1412;
}
V_557 = F_514 ( V_167 ) ;
if ( V_557 ) {
F_46 ( L_522 ) ;
goto V_1413;
}
#ifdef F_270
if ( V_156 ) {
V_557 = F_95 ( V_23 ) ;
if ( V_557 ) {
F_46 ( L_74
L_75 , V_557 ) ;
F_516 ( V_23 -> V_167 ) ;
goto V_1413;
}
}
#endif
F_4 (KERN_INFO DRV_NAME L_523
L_524 ,
priv->ieee->geo.name, priv->ieee->geo.bg_channels,
priv->ieee->geo.a_channels) ;
return 0 ;
V_1413:
F_532 ( V_23 -> V_163 -> V_182 . V_183 ) ;
F_87 ( V_23 -> V_163 -> V_1375 . V_869 ) ;
F_87 ( V_23 -> V_163 -> V_1362 . V_869 ) ;
V_1412:
F_533 ( & V_1385 -> V_166 . V_1409 , & V_1410 ) ;
V_1411:
F_534 ( V_1385 -> V_1334 , V_23 ) ;
V_1394:
F_535 ( V_23 -> V_22 ) ;
V_1393:
F_536 ( V_1385 ) ;
V_1391:
F_537 ( V_1385 ) ;
V_1390:
F_515 ( V_23 -> V_167 , 0 ) ;
V_6:
return V_557 ;
}
static void F_538 ( struct V_477 * V_1385 )
{
struct V_17 * V_23 = F_539 ( V_1385 ) ;
struct V_437 * V_134 , * V_521 ;
int V_7 ;
if ( ! V_23 )
return;
F_59 ( & V_23 -> V_109 ) ;
V_23 -> V_37 |= V_701 ;
F_161 ( V_23 ) ;
F_533 ( & V_1385 -> V_166 . V_1409 , & V_1410 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_516 ( V_23 -> V_167 ) ;
if ( V_23 -> V_496 ) {
F_249 ( V_23 , V_23 -> V_496 ) ;
V_23 -> V_496 = NULL ;
}
F_250 ( V_23 ) ;
if ( V_23 -> V_149 ) {
F_87 ( V_23 -> V_149 ) ;
V_23 -> V_149 = NULL ;
}
F_540 ( & V_23 -> V_669 ) ;
F_541 ( & V_23 -> V_333 ) ;
F_541 ( & V_23 -> V_558 ) ;
F_541 ( & V_23 -> V_564 ) ;
F_541 ( & V_23 -> V_780 ) ;
F_541 ( & V_23 -> V_246 ) ;
F_540 ( & V_23 -> V_191 ) ;
F_541 ( & V_23 -> V_193 ) ;
F_541 ( & V_23 -> V_190 ) ;
F_540 ( & V_23 -> V_186 ) ;
F_540 ( & V_23 -> V_187 ) ;
F_540 ( & V_23 -> V_188 ) ;
F_540 ( & V_23 -> V_189 ) ;
F_540 ( & V_23 -> V_644 ) ;
F_541 ( & V_23 -> V_653 ) ;
F_541 ( & V_23 -> V_706 ) ;
F_540 ( & V_23 -> V_322 ) ;
F_541 ( & V_23 -> V_676 ) ;
F_541 ( & V_23 -> V_241 ) ;
F_540 ( & V_23 -> V_108 ) ;
F_540 ( & V_23 -> V_104 ) ;
F_540 ( & V_23 -> V_114 ) ;
F_541 ( & V_23 -> V_815 ) ;
for ( V_7 = 0 ; V_7 < V_1127 ; V_7 ++ ) {
F_211 (p, q, &priv->ibss_mac_hash[i]) {
F_214 ( V_134 ) ;
F_87 ( F_212 ( V_134 , struct V_1126 , V_442 ) ) ;
}
}
F_87 ( V_23 -> error ) ;
V_23 -> error = NULL ;
#ifdef F_270
F_94 ( V_23 ) ;
#endif
F_534 ( V_1385 -> V_1334 , V_23 ) ;
F_535 ( V_23 -> V_22 ) ;
F_536 ( V_1385 ) ;
F_537 ( V_1385 ) ;
F_532 ( V_23 -> V_163 -> V_182 . V_183 ) ;
F_87 ( V_23 -> V_163 -> V_1375 . V_869 ) ;
F_87 ( V_23 -> V_163 -> V_1362 . V_869 ) ;
F_515 ( V_23 -> V_167 , 0 ) ;
F_241 () ;
}
static int F_542 ( struct V_477 * V_1385 , T_15 V_665 )
{
struct V_17 * V_23 = F_539 ( V_1385 ) ;
struct V_165 * V_166 = V_23 -> V_167 ;
F_4 ( V_1312 L_525 , V_166 -> V_158 ) ;
F_161 ( V_23 ) ;
F_543 ( V_166 ) ;
F_544 ( V_1385 ) ;
F_537 ( V_1385 ) ;
F_545 ( V_1385 , F_546 ( V_1385 , V_665 ) ) ;
V_23 -> V_1414 = F_547 () ;
return 0 ;
}
static int F_548 ( struct V_477 * V_1385 )
{
struct V_17 * V_23 = F_539 ( V_1385 ) ;
struct V_165 * V_166 = V_23 -> V_167 ;
int V_557 ;
T_3 V_21 ;
F_4 ( V_1312 L_526 , V_166 -> V_158 ) ;
F_545 ( V_1385 , V_1415 ) ;
V_557 = F_519 ( V_1385 ) ;
if ( V_557 ) {
F_4 ( V_1059 L_527 ,
V_166 -> V_158 ) ;
return V_557 ;
}
F_549 ( V_1385 ) ;
F_526 ( V_1385 , 0x40 , & V_21 ) ;
if ( ( V_21 & 0x0000ff00 ) != 0 )
F_527 ( V_1385 , 0x40 , V_21 & 0xffff00ff ) ;
F_550 ( V_166 ) ;
V_23 -> V_1356 = F_547 () - V_23 -> V_1414 ;
F_128 ( & V_23 -> V_193 ) ;
return 0 ;
}
static void F_551 ( struct V_477 * V_1385 )
{
struct V_17 * V_23 = F_539 ( V_1385 ) ;
F_161 ( V_23 ) ;
F_537 ( V_1385 ) ;
}
static int T_16 F_552 ( void )
{
int V_432 ;
F_4 (KERN_INFO DRV_NAME L_528 DRV_DESCRIPTION L_529 DRV_VERSION L_68 ) ;
F_4 (KERN_INFO DRV_NAME L_528 DRV_COPYRIGHT L_68 ) ;
V_432 = F_553 ( & V_1416 ) ;
if ( V_432 ) {
F_46 ( L_530 ) ;
return V_432 ;
}
V_432 = F_554 ( & V_1416 . V_1324 , & V_1417 ) ;
if ( V_432 ) {
F_46 ( L_531 ) ;
F_555 ( & V_1416 ) ;
return V_432 ;
}
return V_432 ;
}
static void T_17 F_556 ( void )
{
F_557 ( & V_1416 . V_1324 , & V_1417 ) ;
F_555 ( & V_1416 ) ;
}
