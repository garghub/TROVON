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
memcpy ( V_314 , & V_23 -> V_123 [ V_384 ] , 6 ) ;
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
if ( ! memcmp ( V_441 -> V_216 , V_23 -> V_216 , V_217 ) ) {
F_213 ( V_438 ) ;
F_214 ( & V_441 -> V_442 ,
& V_23 -> V_163 -> V_443 ) ;
}
}
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
}
static inline int F_215 ( struct V_17 * V_23 )
{
return F_36 ( V_23 , 0x90 ) == 0xd55555d5 ;
}
static int F_216 ( struct V_17 * V_23 , T_3 V_32 , T_3 V_36 ,
int V_444 )
{
int V_7 = 0 ;
do {
if ( ( F_36 ( V_23 , V_32 ) & V_36 ) == V_36 )
return V_7 ;
F_217 ( 10 ) ;
V_7 += 10 ;
} while ( V_7 < V_444 );
return - V_445 ;
}
static int F_218 ( struct V_17 * V_23 )
{
int V_155 ;
F_195 ( L_150 ) ;
F_34 ( V_23 , V_404 , V_406 ) ;
V_155 = F_216 ( V_23 , V_404 ,
V_405 , 100 ) ;
if ( V_155 < 0 ) {
F_46 ( L_170 ) ;
return - 1 ;
}
F_74 ( L_171 , V_155 ) ;
return V_155 ;
}
static void F_219 ( struct V_17 * V_23 )
{
F_195 ( L_150 ) ;
F_217 ( 5 ) ;
F_37 ( V_23 , V_404 , V_446 ) ;
F_217 ( 5 ) ;
}
static int F_220 ( struct V_17 * V_23 , T_2 * V_3 , T_1 V_4 )
{
int V_155 = 0 , V_7 , V_32 ;
T_2 V_447 = 0 ;
T_8 * V_448 ;
V_448 = ( T_8 * ) V_3 ;
F_195 ( L_150 ) ;
V_155 = F_218 ( V_23 ) ;
if ( V_155 < 0 )
return V_155 ;
for ( V_32 = V_449 ;
V_32 < V_450 ; V_32 += 4 ) {
F_35 ( V_23 , V_32 , 0 ) ;
}
memset ( & V_23 -> V_451 , 0 , sizeof( V_23 -> V_451 ) ) ;
F_12 ( V_23 , V_452 , V_453 ) ;
F_219 ( V_23 ) ;
F_12 ( V_23 , V_452 , V_454 ) ;
F_217 ( 1 ) ;
F_12 ( V_23 , V_174 , V_455 ) ;
F_217 ( 1 ) ;
F_12 ( V_23 , V_174 , 0 ) ;
F_217 ( 1 ) ;
F_7 ( V_23 , V_456 , 0x0 ) ;
F_7 ( V_23 , V_456 , V_457 ) ;
F_217 ( 1 ) ;
for ( V_7 = 0 ; V_7 < V_4 / 2 ; V_7 ++ )
F_10 ( V_23 , V_458 ,
F_221 ( V_448 [ V_7 ] ) ) ;
F_7 ( V_23 , V_456 , 0 ) ;
F_7 ( V_23 , V_456 , V_459 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ ) {
V_447 = F_119 ( V_23 , V_456 ) ;
if ( V_447 & V_460 )
break;
F_217 ( 1 ) ;
}
if ( V_447 & V_460 ) {
T_6 V_461 [ ( sizeof( V_23 -> V_451 ) + 3 ) / 4 ] ;
for ( V_7 = 0 ; V_7 < F_222 ( V_461 ) ; V_7 ++ )
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
static int F_223 ( struct V_17 * V_23 , T_2 * V_3 , T_1 V_4 )
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
V_473 = F_224 ( L_176 , V_23 -> V_477 , V_433 , 0 , 0 ) ;
if ( ! V_473 ) {
F_46 ( L_177 ) ;
F_87 ( V_475 ) ;
F_87 ( V_474 ) ;
return - V_476 ;
}
V_432 = F_200 ( V_23 ) ;
F_225 ( V_23 -> V_398 . V_399 > 0 ) ;
do {
T_3 V_478 ;
T_2 * V_389 ;
int V_15 ;
int V_431 = 0 ;
V_470 = (struct V_469 * ) ( V_3 + V_468 ) ;
V_468 += sizeof( struct V_469 ) ;
V_478 = F_226 ( V_470 -> V_415 ) ;
V_389 = V_3 + V_468 ;
V_431 = ( V_478 + V_433 - 1 ) / V_433 ;
for ( V_7 = 0 ; V_7 < V_431 ; V_7 ++ ) {
V_474 [ V_471 ] = F_227 ( V_473 , V_148 ,
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
F_225 ( V_471 > V_391 ) ;
}
V_432 = F_209 ( V_23 , & V_475 [ V_471 - V_431 ] ,
V_431 , F_226 ( V_470 -> V_402 ) ,
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
F_228 ( V_473 , V_474 [ V_7 ] , V_475 [ V_7 ] ) ;
F_229 ( V_473 ) ;
F_87 ( V_475 ) ;
F_87 ( V_474 ) ;
return V_432 ;
}
static int F_230 ( struct V_17 * V_23 )
{
int V_155 = 0 ;
F_35 ( V_23 , V_404 , V_406 ) ;
V_155 = F_216 ( V_23 , V_404 ,
V_405 , 500 ) ;
if ( V_155 < 0 ) {
F_46 ( L_181 ) ;
return V_155 ;
}
F_34 ( V_23 , V_404 , V_446 ) ;
return V_155 ;
}
static void F_231 ( struct V_17 * V_23 )
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
static int F_232 ( struct V_17 * V_23 )
{
int V_155 ;
F_195 ( L_150 ) ;
F_34 ( V_23 , V_479 , V_481 ) ;
F_35 ( V_23 , V_482 ,
V_483 ) ;
V_155 = F_216 ( V_23 , V_479 ,
V_484 , 250 ) ;
if ( V_155 < 0 )
F_74 ( L_182 ) ;
F_34 ( V_23 , V_404 , V_485 ) ;
F_187 ( 10 ) ;
F_34 ( V_23 , V_479 , V_481 ) ;
F_195 ( L_150 ) ;
return 0 ;
}
static int F_233 ( struct V_17 * V_23 )
{
int V_155 = 0 ;
unsigned long V_41 ;
F_195 ( L_150 ) ;
V_155 = F_232 ( V_23 ) ;
F_41 ( & V_23 -> V_98 , V_41 ) ;
V_23 -> V_37 &= ~ V_227 ;
F_144 ( & V_23 -> V_228 ) ;
V_23 -> V_37 &= ~ ( V_321 | V_319 ) ;
F_144 ( & V_23 -> V_486 ) ;
F_42 ( & V_23 -> V_98 , V_41 ) ;
F_195 ( L_151 ) ;
return V_155 ;
}
static int F_234 ( struct V_17 * V_23 ,
const struct V_487 * * V_488 , const char * V_158 )
{
struct V_489 * V_490 ;
int V_155 ;
V_155 = F_235 ( V_488 , V_158 , & V_23 -> V_477 -> V_166 ) ;
if ( V_155 < 0 ) {
F_46 ( L_183 , V_158 , V_155 ) ;
return V_155 ;
}
if ( ( * V_488 ) -> V_15 < sizeof( * V_490 ) ) {
F_46 ( L_184 , V_158 , ( * V_488 ) -> V_15 ) ;
return - V_75 ;
}
V_490 = ( void * ) ( * V_488 ) -> V_3 ;
if ( ( * V_488 ) -> V_15 < sizeof( * V_490 ) + F_226 ( V_490 -> V_491 ) +
F_226 ( V_490 -> V_492 ) + F_226 ( V_490 -> V_493 ) ) {
F_46 ( L_185 ,
V_158 , ( * V_488 ) -> V_15 ) ;
return - V_75 ;
}
F_74 ( L_186 ,
V_158 ,
F_226 ( V_490 -> V_494 ) >> 16 ,
F_226 ( V_490 -> V_494 ) & 0xff ,
( * V_488 ) -> V_15 - sizeof( * V_490 ) ) ;
return 0 ;
}
static void F_236 ( struct V_17 * V_23 ,
struct V_495 * V_496 )
{
unsigned long V_41 ;
int V_7 ;
F_41 ( & V_496 -> V_98 , V_41 ) ;
F_237 ( & V_496 -> V_497 ) ;
F_237 ( & V_496 -> V_498 ) ;
for ( V_7 = 0 ; V_7 < V_499 + V_500 ; V_7 ++ ) {
if ( V_496 -> V_473 [ V_7 ] . V_501 != NULL ) {
F_238 ( V_23 -> V_477 , V_496 -> V_473 [ V_7 ] . V_502 ,
V_503 , V_504 ) ;
F_239 ( V_496 -> V_473 [ V_7 ] . V_501 ) ;
V_496 -> V_473 [ V_7 ] . V_501 = NULL ;
}
F_214 ( & V_496 -> V_473 [ V_7 ] . V_442 , & V_496 -> V_498 ) ;
}
V_496 -> V_505 = V_496 -> V_506 = 0 ;
V_496 -> V_507 = 0 ;
F_42 ( & V_496 -> V_98 , V_41 ) ;
}
static void F_240 ( void )
{
if ( V_508 ) {
F_241 ( V_488 ) ;
V_488 = NULL ;
V_508 = 0 ;
}
}
static int F_242 ( struct V_17 * V_23 )
{
#ifndef F_243
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
#ifdef F_244
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
#ifdef F_243
if ( ! V_508 ) {
#endif
V_155 = F_234 ( V_23 , & V_488 , V_158 ) ;
if ( V_155 < 0 )
goto error;
#ifdef F_243
}
#endif
V_490 = ( void * ) V_488 -> V_3 ;
V_509 = & V_490 -> V_3 [ 0 ] ;
V_510 = & V_490 -> V_3 [ F_226 ( V_490 -> V_491 ) ] ;
V_511 = & V_490 -> V_3 [ F_226 ( V_490 -> V_491 ) +
F_226 ( V_490 -> V_492 ) ] ;
if ( V_155 < 0 )
goto error;
if ( ! V_23 -> V_496 )
V_23 -> V_496 = F_245 ( V_23 ) ;
else
F_236 ( V_23 , V_23 -> V_496 ) ;
if ( ! V_23 -> V_496 ) {
F_46 ( L_190 ) ;
goto error;
}
V_517:
F_35 ( V_23 , V_39 , ~ V_40 ) ;
V_23 -> V_37 &= ~ V_38 ;
F_35 ( V_23 , V_222 , V_40 ) ;
F_230 ( V_23 ) ;
V_155 = F_233 ( V_23 ) ;
if ( V_155 < 0 ) {
F_46 ( L_191 ) ;
goto error;
}
F_198 ( V_23 , V_518 ,
V_519 - V_518 ) ;
V_155 = F_223 ( V_23 , V_509 , F_226 ( V_490 -> V_491 ) ) ;
if ( V_155 < 0 ) {
F_46 ( L_192 , V_155 ) ;
goto error;
}
F_231 ( V_23 ) ;
V_155 = F_216 ( V_23 , V_222 ,
V_237 , 500 ) ;
if ( V_155 < 0 ) {
F_46 ( L_193 ) ;
goto error;
}
F_74 ( L_194 , V_155 ) ;
F_35 ( V_23 , V_222 , V_237 ) ;
V_155 = F_220 ( V_23 , V_510 , F_226 ( V_490 -> V_492 ) ) ;
if ( V_155 < 0 ) {
F_46 ( L_195 , V_155 ) ;
goto error;
}
F_230 ( V_23 ) ;
V_155 = F_223 ( V_23 , V_511 , F_226 ( V_490 -> V_493 ) ) ;
if ( V_155 < 0 ) {
F_46 ( L_196 , V_155 ) ;
goto error;
}
#ifdef F_243
V_508 = 1 ;
#endif
F_35 ( V_23 , V_388 , 0 ) ;
V_155 = F_246 ( V_23 ) ;
if ( V_155 < 0 ) {
F_46 ( L_197 ) ;
goto error;
}
F_35 ( V_23 , V_39 , ~ V_40 ) ;
F_35 ( V_23 , V_222 , V_40 ) ;
F_231 ( V_23 ) ;
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
V_155 = F_216 ( V_23 , V_222 ,
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
F_247 ( V_23 ) ;
F_35 ( V_23 , V_520 , V_23 -> V_496 -> V_505 ) ;
F_35 ( V_23 , V_222 , V_40 ) ;
#ifndef F_243
F_241 ( V_488 ) ;
#endif
return 0 ;
error:
if ( V_23 -> V_496 ) {
F_248 ( V_23 , V_23 -> V_496 ) ;
V_23 -> V_496 = NULL ;
}
F_249 ( V_23 ) ;
F_241 ( V_488 ) ;
#ifdef F_243
V_508 = 0 ;
V_488 = NULL ;
#endif
return V_155 ;
}
static int F_250 ( const struct V_495 * V_521 )
{
int V_522 = V_521 -> V_505 - V_521 -> V_506 ;
if ( V_522 <= 0 )
V_522 += V_500 ;
V_522 -= 2 ;
if ( V_522 < 0 )
V_522 = 0 ;
return V_522 ;
}
static inline int F_251 ( const struct V_523 * V_521 )
{
int V_522 = V_521 -> V_524 - V_521 -> V_525 ;
if ( V_522 <= 0 )
V_522 += V_521 -> V_526 ;
V_522 -= 2 ;
if ( V_522 < 0 )
V_522 = 0 ;
return V_522 ;
}
static inline int F_252 ( int V_400 , int V_526 )
{
return ( ++ V_400 == V_526 ) ? 0 : V_400 ;
}
static void F_253 ( struct V_17 * V_23 , struct V_523 * V_521 ,
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
static int F_254 ( struct V_17 * V_23 ,
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
F_255 ( V_166 , sizeof( V_521 -> V_533 [ 0 ] ) * V_2 , & V_521 -> V_521 . V_502 ) ;
if ( ! V_521 -> V_533 ) {
F_46 ( L_203 ,
sizeof( V_521 -> V_533 [ 0 ] ) * V_2 ) ;
F_87 ( V_521 -> V_532 ) ;
V_521 -> V_532 = NULL ;
return - V_476 ;
}
F_253 ( V_23 , & V_521 -> V_521 , V_2 , V_505 , V_506 , V_137 , V_15 ) ;
return 0 ;
}
static void F_256 ( struct V_17 * V_23 ,
struct V_531 * V_230 )
{
struct V_534 * V_533 = & V_230 -> V_533 [ V_230 -> V_521 . V_524 ] ;
struct V_477 * V_166 = V_23 -> V_477 ;
int V_7 ;
if ( V_533 -> V_535 . V_536 == V_537 )
return;
if ( F_226 ( V_533 -> V_538 . V_3 . V_539 ) > V_540 ) {
F_46 ( L_204 ,
F_226 ( V_533 -> V_538 . V_3 . V_539 ) ) ;
return;
}
for ( V_7 = 0 ; V_7 < F_226 ( V_533 -> V_538 . V_3 . V_539 ) ; V_7 ++ ) {
F_238 ( V_166 , F_226 ( V_533 -> V_538 . V_3 . V_541 [ V_7 ] ) ,
F_221 ( V_533 -> V_538 . V_3 . V_478 [ V_7 ] ) ,
V_542 ) ;
if ( V_230 -> V_532 [ V_230 -> V_521 . V_524 ] ) {
F_257 ( V_230 -> V_532 [ V_230 -> V_521 . V_524 ] ) ;
V_230 -> V_532 [ V_230 -> V_521 . V_524 ] = NULL ;
}
}
}
static void F_258 ( struct V_17 * V_23 , struct V_531 * V_230 )
{
struct V_523 * V_521 = & V_230 -> V_521 ;
struct V_477 * V_166 = V_23 -> V_477 ;
if ( V_521 -> V_526 == 0 )
return;
for (; V_521 -> V_525 != V_521 -> V_524 ;
V_521 -> V_524 = F_252 ( V_521 -> V_524 , V_521 -> V_526 ) ) {
F_256 ( V_23 , V_230 ) ;
}
F_259 ( V_166 , sizeof( V_230 -> V_533 [ 0 ] ) * V_521 -> V_526 , V_230 -> V_533 ,
V_521 -> V_502 ) ;
F_87 ( V_230 -> V_532 ) ;
memset ( V_230 , 0 , sizeof( * V_230 ) ) ;
}
static void F_249 ( struct V_17 * V_23 )
{
F_258 ( V_23 , & V_23 -> V_226 ) ;
F_258 ( V_23 , & V_23 -> V_230 [ 0 ] ) ;
F_258 ( V_23 , & V_23 -> V_230 [ 1 ] ) ;
F_258 ( V_23 , & V_23 -> V_230 [ 2 ] ) ;
F_258 ( V_23 , & V_23 -> V_230 [ 3 ] ) ;
}
static void F_260 ( struct V_17 * V_23 , T_2 * V_216 )
{
V_216 [ 0 ] = V_23 -> V_543 [ 0 ] ;
V_216 [ 1 ] = V_23 -> V_543 [ 1 ] ;
V_216 [ 2 ] = V_23 -> V_543 [ 2 ] ;
F_177 ( & V_216 [ 3 ] , V_217 - 3 ) ;
V_216 [ 0 ] &= 0xfe ;
V_216 [ 0 ] |= 0x02 ;
}
static T_2 F_261 ( struct V_17 * V_23 , T_2 * V_216 )
{
struct V_544 V_545 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_23 -> V_546 ; V_7 ++ ) {
if ( ! memcmp ( V_23 -> V_547 [ V_7 ] , V_216 , V_217 ) ) {
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
static T_2 F_262 ( struct V_17 * V_23 , T_2 * V_216 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_23 -> V_546 ; V_7 ++ )
if ( ! memcmp ( V_23 -> V_547 [ V_7 ] , V_216 , V_217 ) )
return V_7 ;
return V_552 ;
}
static void F_263 ( struct V_17 * V_23 , int V_556 )
{
int V_557 ;
if ( V_23 -> V_37 & V_240 ) {
F_264 ( L_206 ) ;
F_128 ( & V_23 -> V_558 ) ;
return;
}
if ( ! ( V_23 -> V_37 & V_103 ) ) {
F_264 ( L_207 ) ;
return;
}
F_264 ( L_208
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
static int F_265 ( void * V_3 )
{
struct V_17 * V_23 = V_3 ;
if ( ! ( V_23 -> V_37 & ( V_103 | V_240 ) ) )
return 0 ;
F_263 ( V_3 , 0 ) ;
F_266 ( V_23 -> V_167 ) ;
return 1 ;
}
static void F_267 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_558 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_265 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_268 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_564 ) ;
#ifdef F_269
if ( V_23 -> V_157 && F_92 ( V_23 -> V_157 ) ) {
V_23 -> V_310 . V_565 = 1 ;
V_23 -> V_310 . V_566 = 1 ;
V_23 -> V_310 . V_567 = 1 ;
V_23 -> V_310 . V_568 = 1 ;
}
#endif
F_157 ( V_23 ) ;
}
static const char * F_270 ( T_4 V_37 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_222 ( V_569 ) ; V_7 ++ )
if ( V_569 [ V_7 ] . V_37 == ( V_37 & 0xff ) )
return V_569 [ V_7 ] . V_570 ;
return L_211 ;
}
static void inline F_271 ( struct V_571 * V_572 )
{
memset ( V_572 , 0 , sizeof( * V_572 ) ) ;
}
static T_10 F_272 ( T_10 V_573 , T_10 V_21 , T_2 V_574 )
{
return ( ( V_574 - 1 ) * V_573 + V_21 ) / V_574 ;
}
static void F_273 ( struct V_571 * V_572 , T_10 V_21 )
{
V_572 -> V_575 -= V_572 -> V_576 [ V_572 -> V_194 ] ;
V_572 -> V_575 += V_21 ;
V_572 -> V_576 [ V_572 -> V_194 ++ ] = V_21 ;
if ( F_29 ( V_572 -> V_194 == V_577 ) ) {
V_572 -> V_578 = 1 ;
V_572 -> V_194 = 0 ;
}
}
static T_10 F_274 ( struct V_571 * V_572 )
{
if ( ! F_29 ( V_572 -> V_578 ) ) {
if ( V_572 -> V_194 )
return V_572 -> V_575 / V_572 -> V_194 ;
return 0 ;
}
return V_572 -> V_575 / V_577 ;
}
static void F_275 ( struct V_17 * V_23 )
{
T_3 V_4 = sizeof( T_3 ) ;
V_23 -> V_579 = 0 ;
F_271 ( & V_23 -> V_580 ) ;
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
static T_3 F_276 ( struct V_17 * V_23 )
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
static T_3 F_277 ( struct V_17 * V_23 )
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
return F_276 ( V_23 ) ;
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
static void F_278 ( struct V_17 * V_23 )
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
( V_192 * F_221 ( V_23 -> V_559 . V_640 ) ) /
( V_641 * 10 ) ;
} else {
V_630 = 0 ;
}
F_273 ( & V_23 -> V_580 , V_630 ) ;
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
#define F_279 5
V_633 = 100 - V_630 ;
if ( V_633 < F_279 )
V_633 = 0 ;
else
V_633 = ( V_633 - F_279 ) * 100 /
( 100 - F_279 ) ;
F_280 ( L_213 ,
V_633 , V_630 ) ;
V_23 -> V_583 = F_277 ( V_23 ) ;
V_638 = F_276 ( V_23 ) ;
V_637 = V_23 -> V_583 * 40 / V_638 + 60 ;
F_280 ( L_214 ,
V_637 , V_23 -> V_583 / 1000000 ) ;
if ( V_626 > 100 && V_626 + V_625 )
V_636 = 100 - ( V_625 * 100 ) /
( V_626 + V_625 ) ;
else
V_636 = 100 ;
F_280 ( L_215 ,
V_636 , V_625 , V_626 ) ;
if ( V_629 > 100 && V_629 + V_628 )
V_635 = 100 - ( V_628 * 100 ) /
( V_629 + V_628 ) ;
else
V_635 = 100 ;
F_280 ( L_216 ,
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
F_280 ( L_217 ,
V_634 , V_632 ) ;
V_579 = F_3 ( V_636 , V_634 ) ;
V_579 = F_3 ( V_635 , V_579 ) ;
V_579 = F_3 ( V_637 , V_579 ) ;
V_579 = F_3 ( V_633 , V_579 ) ;
if ( V_579 == V_633 )
F_280 ( L_218 ,
V_579 ) ;
if ( V_579 == V_637 )
F_280 ( L_219 ,
V_579 ) ;
if ( V_579 == V_635 )
F_280 ( L_220 ,
V_579 ) ;
if ( V_579 == V_636 )
F_280 ( L_221 ,
V_579 ) ;
if ( V_579 == V_634 )
F_280 ( L_222 ,
V_579 ) ;
V_23 -> V_579 = V_579 ;
F_56 ( & V_23 -> V_644 , V_641 ) ;
}
static void F_281 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_644 . V_107 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_278 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_282 ( struct V_17 * V_23 ,
int V_645 )
{
V_23 -> V_646 = V_645 ;
if ( V_645 > V_23 -> V_647 &&
V_23 -> V_37 & V_103 ) {
F_283 ( V_648 | V_649 |
V_650 | V_651 ,
L_223 , V_645 ) ;
V_23 -> V_37 &= ~ V_652 ;
if ( V_23 -> V_37 & V_321 ) {
F_283 ( V_648 | V_649 |
V_650 ,
L_224 ) ;
F_128 ( & V_23 -> V_653 ) ;
}
F_128 ( & V_23 -> V_558 ) ;
return;
}
if ( V_23 -> V_37 & V_652 ) {
F_283 ( V_649 | V_650 ,
L_225 ,
V_645 ) ;
return;
}
if ( V_654 &&
( V_645 > V_23 -> V_655 &&
V_645 <= V_23 -> V_647 ) ) {
F_283 ( V_649 | V_650 ,
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
F_283 ( V_648 | V_649 | V_650 ,
L_224 ) ;
F_128 ( & V_23 -> V_653 ) ;
}
F_284 ( L_228 , V_645 ) ;
}
static void F_285 ( struct V_106 * V_107 )
{
union V_210 V_211 ;
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_189 . V_107 ) ;
V_211 . V_3 . V_415 = 0 ;
V_211 . V_3 . V_41 = 0 ;
F_139 ( V_23 -> V_167 , V_657 , & V_211 , NULL ) ;
}
static void F_286 ( struct V_17 * V_23 )
{
if ( ! V_23 -> V_658 ) {
F_56 ( & V_23 -> V_189 ,
F_129 ( F_287 ( 4000 ) ) ) ;
} else {
V_23 -> V_658 = 0 ;
F_288 ( V_659 , & V_23 -> V_189 , 0 ) ;
}
}
static void F_289 ( struct V_17 * V_23 ,
struct F_289 * V_660 )
{
F_290 ( V_311 ) ;
T_4 V_15 = F_221 ( V_660 -> V_15 ) ;
F_284 ( L_229 , V_660 -> V_661 , V_15 ) ;
switch ( V_660 -> V_661 ) {
case V_662 : {
struct V_663 * V_664 = & V_660 -> V_538 . V_664 ;
switch ( V_664 -> V_665 ) {
case V_666 : {
F_283 ( V_649 | V_650 |
V_651 ,
L_230 ,
F_291 ( V_311 , V_23 -> V_667 ,
V_23 -> V_668 ) ,
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
F_264
( L_231 ) ;
F_56 (
& V_23 -> V_669 ,
F_221 ( V_23 ->
V_559 .
V_640 ) ) ;
break;
}
V_23 -> V_37 &= ~ V_240 ;
V_23 -> V_37 |= V_103 ;
F_128 ( & V_23 -> V_564 ) ;
#ifdef F_292
#define F_293 ( T_11 ) WLAN_FC_GET_STYPE( \
le16_to_cpu(((struct ieee80211_hdr *)(x))->frame_control))
if ( ( V_23 -> V_37 & V_670 ) &&
( F_293 ( & V_660 -> V_538 . V_488 )
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
F_294
( L_232
L_233 , V_15 ) ;
F_295 ( V_23 ->
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
F_283 ( V_649 |
V_650 |
V_651 ,
L_234
L_235
L_236 ,
F_291 ( V_311 ,
V_23 ->
V_667 ,
V_23 ->
V_668 ) ,
V_23 -> V_216 ,
F_221 ( V_679 -> V_37 ) ,
F_270
( F_221
( V_679 -> V_37 ) ) ) ;
V_23 -> V_37 &=
~ ( V_240 |
V_670 |
V_103 ) ;
F_128 ( & V_23 -> V_241 ) ;
break;
}
F_283 ( V_649 | V_650 |
V_651 ,
L_237 ,
F_291 ( V_311 , V_23 -> V_667 ,
V_23 -> V_668 ) ,
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
F_283 ( V_649 |
V_650 |
V_651 ,
L_238 ,
F_221 ( V_681 -> V_37 ) ,
F_270
( F_221
( V_681 -> V_37 ) ) ) ;
}
F_283 ( V_649 | V_650 |
V_651 ,
L_239 ,
F_291 ( V_311 , V_23 -> V_667 ,
V_23 -> V_668 ) ,
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
F_46 ( L_240 ,
V_664 -> V_665 ) ;
break;
}
break;
}
case V_683 : {
struct V_678 * V_679 = & V_660 -> V_538 . V_679 ;
switch ( V_679 -> V_665 ) {
case V_677 :
F_283 ( V_649 | V_650 ,
L_237 ,
F_291 ( V_311 , V_23 -> V_667 ,
V_23 -> V_668 ) ,
V_23 -> V_216 ) ;
V_23 -> V_37 |= V_670 ;
break;
case V_680 :
if ( V_23 -> V_37 & V_670 ) {
F_283 ( V_649 | V_650 |
V_651 ,
L_241 ,
F_221 ( V_679 -> V_37 ) ,
F_270 ( F_221
( V_679 ->
V_37 ) ) ) ;
}
F_283 ( V_649 | V_650 |
V_651 ,
L_242 ,
F_291 ( V_311 , V_23 -> V_667 ,
V_23 -> V_668 ) ,
V_23 -> V_216 ) ;
V_23 -> V_37 &= ~ ( V_240 |
V_670 |
V_103 ) ;
F_128 ( & V_23 -> V_241 ) ;
break;
case V_684 :
F_283 ( V_649 | V_650 |
V_651 , L_243 ) ;
break;
case V_685 :
F_283 ( V_649 | V_650 |
V_651 , L_244 ) ;
break;
case V_686 :
F_283 ( V_649 | V_650 |
V_651 , L_245 ) ;
break;
case V_687 :
F_283 ( V_649 | V_650 |
V_651 , L_246 ) ;
break;
case V_688 :
F_283 ( V_649 | V_650 |
V_651 , L_247 ) ;
break;
case V_689 :
F_283 ( V_649 | V_650 |
V_651 , L_248 ) ;
break;
case V_690 :
F_283 ( V_649 | V_650 |
V_651 , L_249 ) ;
break;
case V_691 :
F_283 ( V_649 | V_650 |
V_651 , L_250 ) ;
break;
case V_692 :
F_283 ( V_649 | V_650 |
V_651 , L_251 ) ;
break;
case V_682 :
F_283 ( V_649 | V_650 |
V_651 , L_252 ) ;
break;
case V_666 :
F_283 ( V_649 | V_650 |
V_651 , L_253 ) ;
break;
default:
F_284 ( L_254 ,
V_679 -> V_665 ) ;
break;
}
break;
}
case V_693 : {
struct V_694 * T_11 =
& V_660 -> V_538 . V_695 ;
if ( V_15 == sizeof( * T_11 ) ) {
F_166 ( L_255 ,
T_11 -> V_696 ) ;
} else {
F_166 ( L_256
L_257 ,
V_15 , sizeof( * T_11 ) ) ;
}
break;
}
case V_697 : {
struct V_698 * T_11 = & V_660 -> V_538 . V_699 ;
if ( V_15 == sizeof( * T_11 ) ) {
F_166
( L_258
L_259 , T_11 -> V_700 ,
T_11 -> V_349 , T_11 -> V_37 ) ;
} else {
F_46 ( L_260
L_257 ,
V_15 , sizeof( * T_11 ) ) ;
}
V_23 -> V_37 &=
~ ( V_321 | V_319 ) ;
F_144 ( & V_23 -> V_486 ) ;
F_64 ( & V_23 -> V_322 ) ;
if ( V_23 -> V_37 & V_701 )
break;
V_23 -> V_163 -> V_702 ++ ;
#ifdef F_244
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
F_286 ( V_23 ) ;
break;
}
case V_709 : {
struct V_710 * T_11 = & V_660 -> V_538 . V_711 ;
if ( V_15 == sizeof( * T_11 ) )
F_46 ( L_261 ,
F_221 ( T_11 -> V_712 ) ) ;
else
F_46 ( L_262
L_257 ,
V_15 , sizeof( * T_11 ) ) ;
break;
}
case V_713 : {
struct V_714 * T_11 =
& V_660 -> V_538 . V_715 ;
if ( V_15 == sizeof( * T_11 ) ) {
F_283 ( V_649 | V_650 ,
L_263 ,
T_11 -> V_716 ,
T_11 -> V_717 ) ;
memcpy ( & V_23 -> V_718 , T_11 ,
sizeof( * T_11 ) ) ;
} else {
F_46 ( L_264
L_257 ,
V_15 , sizeof( * T_11 ) ) ;
}
break;
}
case V_719 : {
F_46 ( L_265 ) ;
if ( V_23 -> V_720
&& V_23 -> V_720 -> V_153 != V_721 )
F_46 ( L_266 ) ;
break;
}
case V_722 : {
struct V_723 * T_11 = & V_660 -> V_538 . V_724 ;
if ( V_15 != sizeof( * T_11 ) ) {
F_46
( L_267
L_268 , V_15 , sizeof( * T_11 ) ) ;
break;
}
if ( F_226 ( T_11 -> V_665 ) ==
V_725 )
F_282 ( V_23 ,
F_226 ( T_11 ->
V_726 ) ) ;
break;
}
case V_727 : {
struct V_728 * T_11 = & V_660 -> V_538 . V_729 ;
if ( V_15 == sizeof( * T_11 ) ) {
F_46 ( L_269
L_270 ,
T_11 -> V_730 , T_11 -> V_731 ,
T_11 -> V_732 ) ;
break;
}
F_46
( L_271 ,
V_15 , sizeof( * T_11 ) ) ;
break;
}
case V_733 : {
struct V_734 * T_11 = & V_660 -> V_538 . V_735 ;
if ( V_15 == sizeof( * T_11 ) ) {
memcpy ( & V_23 -> V_329 , T_11 , sizeof( * T_11 ) ) ;
F_74 ( L_272 ) ;
break;
}
F_46
( L_273 ,
V_15 , sizeof( * T_11 ) ) ;
break;
}
case V_736 : {
if ( V_15 == sizeof( T_3 ) ) {
V_23 -> V_582 =
F_272 ( V_23 -> V_582 ,
( T_2 ) ( F_226 ( V_660 -> V_538 . V_737 . V_25 ) & 0xff ) ,
V_738 ) ;
break;
}
F_46
( L_274 ,
V_15 , sizeof( T_3 ) ) ;
break;
}
default:
F_284 ( L_275
L_276 ,
V_660 -> V_661 , V_660 -> V_41 , V_15 ) ;
}
}
static int F_246 ( struct V_17 * V_23 )
{
int V_155 = 0 ;
int V_739 = 64 , V_740 = 8 ;
F_249 ( V_23 ) ;
V_155 = F_254 ( V_23 , & V_23 -> V_226 , V_740 ,
V_741 ,
V_742 ,
V_743 ,
V_744 ) ;
if ( V_155 ) {
F_46 ( L_277 ) ;
goto error;
}
V_155 = F_254 ( V_23 , & V_23 -> V_230 [ 0 ] , V_739 ,
V_745 ,
V_746 ,
V_747 , V_748 ) ;
if ( V_155 ) {
F_46 ( L_278 ) ;
goto error;
}
V_155 = F_254 ( V_23 , & V_23 -> V_230 [ 1 ] , V_739 ,
V_749 ,
V_750 ,
V_751 , V_752 ) ;
if ( V_155 ) {
F_46 ( L_279 ) ;
goto error;
}
V_155 = F_254 ( V_23 , & V_23 -> V_230 [ 2 ] , V_739 ,
V_753 ,
V_754 ,
V_755 , V_756 ) ;
if ( V_155 ) {
F_46 ( L_280 ) ;
goto error;
}
V_155 = F_254 ( V_23 , & V_23 -> V_230 [ 3 ] , V_739 ,
V_757 ,
V_758 ,
V_759 , V_760 ) ;
if ( V_155 ) {
F_46 ( L_281 ) ;
goto error;
}
V_23 -> V_761 = 0 ;
V_23 -> V_762 = 0 ;
return V_155 ;
error:
F_249 ( V_23 ) ;
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
( L_282 ,
V_764 , V_521 -> V_526 ) ;
goto V_766;
}
for (; V_521 -> V_524 != V_764 ;
V_521 -> V_524 = F_252 ( V_521 -> V_524 , V_521 -> V_526 ) ) {
F_256 ( V_23 , V_230 ) ;
V_23 -> V_592 ++ ;
}
V_766:
if ( ( F_251 ( V_521 ) > V_521 -> V_527 ) &&
( V_763 >= 0 ) )
F_296 ( V_23 -> V_167 ) ;
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
if ( F_251 ( V_521 ) < ( V_767 ? 1 : 2 ) ) {
F_46 ( L_283 ) ;
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
V_521 -> V_525 = F_252 ( V_521 -> V_525 , V_521 -> V_526 ) ;
F_35 ( V_23 , V_521 -> V_530 , V_521 -> V_525 ) ;
F_24 ( V_23 , 0x90 ) ;
return 0 ;
}
static void F_297 ( struct V_17 * V_23 )
{
struct V_495 * V_496 = V_23 -> V_496 ;
struct V_437 * V_438 ;
struct V_773 * V_774 ;
unsigned long V_41 ;
int V_506 ;
F_41 ( & V_496 -> V_98 , V_41 ) ;
V_506 = V_496 -> V_506 ;
while ( ( F_250 ( V_496 ) > 0 ) && ( V_496 -> V_507 ) ) {
V_438 = V_496 -> V_497 . V_775 ;
V_774 = F_212 ( V_438 , struct V_773 , V_442 ) ;
F_213 ( V_438 ) ;
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
static void F_247 ( void * V_3 )
{
struct V_17 * V_23 = V_3 ;
struct V_495 * V_496 = V_23 -> V_496 ;
struct V_437 * V_438 ;
struct V_773 * V_774 ;
unsigned long V_41 ;
F_41 ( & V_496 -> V_98 , V_41 ) ;
while ( ! F_298 ( & V_496 -> V_498 ) ) {
V_438 = V_496 -> V_498 . V_775 ;
V_774 = F_212 ( V_438 , struct V_773 , V_442 ) ;
V_774 -> V_501 = F_299 ( V_503 , V_139 ) ;
if ( ! V_774 -> V_501 ) {
F_4 ( V_782 L_284 ,
V_23 -> V_167 -> V_158 ) ;
break;
}
F_213 ( V_438 ) ;
V_774 -> V_502 =
F_300 ( V_23 -> V_477 , V_774 -> V_501 -> V_3 ,
V_503 , V_504 ) ;
F_214 ( & V_774 -> V_442 , & V_496 -> V_497 ) ;
V_496 -> V_507 ++ ;
}
F_42 ( & V_496 -> V_98 , V_41 ) ;
F_297 ( V_23 ) ;
}
static void F_301 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_780 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_247 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_248 ( struct V_17 * V_23 , struct V_495 * V_496 )
{
int V_7 ;
if ( ! V_496 )
return;
for ( V_7 = 0 ; V_7 < V_500 + V_499 ; V_7 ++ ) {
if ( V_496 -> V_473 [ V_7 ] . V_501 != NULL ) {
F_238 ( V_23 -> V_477 , V_496 -> V_473 [ V_7 ] . V_502 ,
V_503 , V_504 ) ;
F_239 ( V_496 -> V_473 [ V_7 ] . V_501 ) ;
}
}
F_87 ( V_496 ) ;
}
static struct V_495 * F_245 ( struct V_17 * V_23 )
{
struct V_495 * V_496 ;
int V_7 ;
V_496 = F_86 ( sizeof( * V_496 ) , V_148 ) ;
if ( F_29 ( ! V_496 ) ) {
F_46 ( L_285 ) ;
return NULL ;
}
F_302 ( & V_496 -> V_98 ) ;
F_237 ( & V_496 -> V_497 ) ;
F_237 ( & V_496 -> V_498 ) ;
for ( V_7 = 0 ; V_7 < V_499 + V_500 ; V_7 ++ )
F_214 ( & V_496 -> V_473 [ V_7 ] . V_442 , & V_496 -> V_498 ) ;
V_496 -> V_505 = V_496 -> V_506 = 0 ;
V_496 -> V_507 = 0 ;
return V_496 ;
}
static int F_303 ( struct V_17 * V_23 , int V_347 , T_2 V_609 )
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
static int F_304 ( struct V_17 * V_23 ,
const struct V_440 * V_441 ,
struct V_335 * V_336 )
{
int V_796 , V_7 ;
memset ( V_336 , 0 , sizeof( * V_336 ) ) ;
V_796 = F_3 ( V_441 -> V_797 , ( T_2 ) V_798 ) ;
V_336 -> V_796 = 0 ;
for ( V_7 = 0 ; V_7 < V_796 ; V_7 ++ ) {
if ( ! F_303 ( V_23 , V_441 -> V_118 ,
V_441 -> V_336 [ V_7 ] ) ) {
if ( V_441 -> V_336 [ V_7 ] & V_783 ) {
F_166 ( L_286
L_287 ,
V_441 -> V_336 [ V_7 ] ) ;
V_336 -> V_799 [ V_336 -> V_796 ++ ] =
V_441 -> V_336 [ V_7 ] ;
continue;
}
F_166 ( L_288 ,
V_441 -> V_336 [ V_7 ] , V_23 -> V_594 ) ;
continue;
}
V_336 -> V_799 [ V_336 -> V_796 ++ ] = V_441 -> V_336 [ V_7 ] ;
}
V_796 = F_3 ( V_441 -> V_800 ,
( T_2 ) ( V_798 - V_796 ) ) ;
for ( V_7 = 0 ; V_7 < V_796 ; V_7 ++ ) {
if ( ! F_303 ( V_23 , V_441 -> V_118 ,
V_441 -> V_801 [ V_7 ] ) ) {
if ( V_441 -> V_801 [ V_7 ] & V_783 ) {
F_166 ( L_286
L_287 ,
V_441 -> V_801 [ V_7 ] ) ;
V_336 -> V_799 [ V_336 -> V_796 ++ ] =
V_441 -> V_336 [ V_7 ] ;
continue;
}
F_166 ( L_288 ,
V_441 -> V_801 [ V_7 ] , V_23 -> V_594 ) ;
continue;
}
V_336 -> V_799 [ V_336 -> V_796 ++ ] =
V_441 -> V_801 [ V_7 ] ;
}
return 1 ;
}
static void F_305 ( struct V_335 * V_802 ,
const struct V_335 * V_803 )
{
T_2 V_7 ;
for ( V_7 = 0 ; V_7 < V_803 -> V_796 ; V_7 ++ )
V_802 -> V_799 [ V_7 ] = V_803 -> V_799 [ V_7 ] ;
V_802 -> V_796 = V_803 -> V_796 ;
}
static void F_306 ( struct V_335 * V_336 ,
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
static void F_307 ( struct V_335 * V_336 ,
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
static int F_308 ( struct V_17 * V_23 ,
struct V_808 * V_809 ,
struct V_440 * V_441 ,
int V_654 )
{
struct V_335 V_336 ;
F_290 ( V_311 ) ;
if ( ( V_23 -> V_163 -> V_513 == V_514 &&
! ( V_441 -> V_317 & V_318 ) ) ) {
F_309 ( L_289
L_290 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ) ;
return 0 ;
}
if ( F_29 ( V_654 ) ) {
if ( ( V_441 -> V_810 != V_809 -> V_441 -> V_810 ) ||
memcmp ( V_441 -> V_311 , V_809 -> V_441 -> V_311 ,
V_441 -> V_810 ) ) {
F_309 ( L_291
L_292 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ) ;
return 0 ;
}
} else {
if ( ( V_23 -> V_59 & V_811 ) &&
( ( V_441 -> V_810 != V_23 -> V_668 ) ||
memcmp ( V_441 -> V_311 , V_23 -> V_667 ,
F_3 ( V_441 -> V_810 , V_23 -> V_668 ) ) ) ) {
char V_812 [ V_313 * 2 + 1 ] ;
strncpy ( V_812 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
sizeof( V_812 ) ) ;
F_309 ( L_291
L_293 ,
V_812 , V_441 -> V_216 ,
F_291 ( V_311 , V_23 -> V_667 ,
V_23 -> V_668 ) ) ;
return 0 ;
}
}
if ( V_441 -> V_467 [ 0 ] < V_809 -> V_441 -> V_467 [ 0 ] ) {
F_309 ( L_294
L_295 ,
F_291 ( V_311 , V_809 -> V_441 -> V_311 ,
V_809 -> V_441 -> V_810 ) ) ;
return 0 ;
} else if ( V_441 -> V_467 [ 1 ] < V_809 -> V_441 -> V_467 [ 1 ] ) {
F_309 ( L_294
L_295 ,
F_291 ( V_311 , V_809 -> V_441 -> V_311 ,
V_809 -> V_441 -> V_810 ) ) ;
return 0 ;
}
if ( V_23 -> V_163 -> V_164 != 0 &&
F_310 ( V_140 , V_441 -> V_813 + V_23 -> V_163 -> V_164 ) ) {
F_309 ( L_291
L_296 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ,
F_167 ( V_140 -
V_441 -> V_813 ) ) ;
return 0 ;
}
if ( ( V_23 -> V_59 & V_549 ) &&
( V_441 -> V_197 != V_23 -> V_197 ) ) {
F_309 ( L_291
L_297 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ,
V_441 -> V_197 , V_23 -> V_197 ) ;
return 0 ;
}
if ( ( ( V_23 -> V_317 & V_814 ) ? 1 : 0 ) !=
( ( V_441 -> V_317 & V_815 ) ? 1 : 0 ) ) {
F_309 ( L_291
L_298 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ,
V_23 ->
V_317 & V_814 ? L_299 : L_300 ,
V_441 ->
V_317 & V_815 ? L_299 :
L_300 ) ;
return 0 ;
}
if ( ! memcmp ( V_441 -> V_216 , V_23 -> V_216 , V_217 ) ) {
F_309 ( L_291
L_301
L_302 , F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ,
V_23 -> V_216 ) ;
return 0 ;
}
if ( ! F_311 ( V_23 -> V_163 , V_441 -> V_118 ) ) {
F_309 ( L_291
L_303
L_304 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ) ;
return 0 ;
}
if ( ! F_304 ( V_23 , V_441 , & V_336 ) ) {
F_309 ( L_291
L_305
L_306 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ) ;
return 0 ;
}
if ( V_336 . V_796 == 0 ) {
F_309 ( L_291
L_307 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ) ;
return 0 ;
}
F_305 ( & V_809 -> V_336 , & V_336 ) ;
V_809 -> V_441 = V_441 ;
F_309 ( L_308 ,
F_291 ( V_311 , V_441 -> V_311 , V_441 -> V_810 ) ,
V_441 -> V_216 ) ;
return 1 ;
}
static void F_312 ( struct V_106 * V_107 )
{
F_290 ( V_311 ) ;
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_816 ) ;
struct V_440 * V_441 = NULL ;
struct V_808 V_809 = {
. V_441 = V_23 -> V_117
} ;
if ( ( V_23 -> V_37 & V_103 ) &&
( V_23 -> V_163 -> V_513 == V_514 ) ) {
unsigned long V_41 ;
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
F_313 (network, &priv->ieee->network_list, list) {
if ( V_441 != V_23 -> V_117 )
F_308 ( V_23 , & V_809 , V_441 ,
1 ) ;
}
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
if ( V_809 . V_441 == V_23 -> V_117 ) {
F_309 ( L_309
L_310 ) ;
return;
}
F_59 ( & V_23 -> V_109 ) ;
if ( ( V_23 -> V_163 -> V_513 == V_514 ) ) {
F_309 ( L_311 ,
F_291 ( V_311 , V_23 -> V_667 ,
V_23 -> V_668 ) ) ;
F_162 ( V_23 ) ;
}
F_265 ( V_23 ) ;
V_23 -> V_117 = V_809 . V_441 ;
F_60 ( & V_23 -> V_109 ) ;
return;
}
}
static int F_314 ( struct V_17 * V_23 ,
struct V_808 * V_809 ,
struct V_440 * V_441 , int V_654 )
{
struct V_335 V_336 ;
F_290 ( V_311 ) ;
if ( ( V_23 -> V_163 -> V_513 == V_516 &&
! ( V_441 -> V_317 & V_817 ) ) ||
( V_23 -> V_163 -> V_513 == V_514 &&
! ( V_441 -> V_317 & V_318 ) ) ) {
F_264 ( L_289
L_290 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ) ;
return 0 ;
}
if ( F_29 ( V_654 ) ) {
if ( ( V_441 -> V_810 != V_809 -> V_441 -> V_810 ) ||
memcmp ( V_441 -> V_311 , V_809 -> V_441 -> V_311 ,
V_441 -> V_810 ) ) {
F_264 ( L_291
L_292 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ) ;
return 0 ;
}
} else {
if ( ( V_23 -> V_59 & V_811 ) &&
( ( V_441 -> V_810 != V_23 -> V_668 ) ||
memcmp ( V_441 -> V_311 , V_23 -> V_667 ,
F_3 ( V_441 -> V_810 , V_23 -> V_668 ) ) ) ) {
char V_812 [ V_313 * 2 + 1 ] ;
strncpy ( V_812 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
sizeof( V_812 ) ) ;
F_264 ( L_291
L_293 ,
V_812 , V_441 -> V_216 ,
F_291 ( V_311 , V_23 -> V_667 ,
V_23 -> V_668 ) ) ;
return 0 ;
}
}
if ( V_809 -> V_441 && V_809 -> V_441 -> V_674 . V_632 > V_441 -> V_674 . V_632 ) {
char V_812 [ V_313 * 2 + 1 ] ;
strncpy ( V_812 ,
F_291 ( V_311 , V_441 -> V_311 , V_441 -> V_810 ) ,
sizeof( V_812 ) ) ;
F_264 ( L_312
L_313 ,
V_812 , V_441 -> V_216 ,
F_291 ( V_311 , V_809 -> V_441 -> V_311 ,
V_809 -> V_441 -> V_810 ) ,
V_809 -> V_441 -> V_216 ) ;
return 0 ;
}
if ( V_441 -> V_818 &&
F_310 ( V_441 -> V_818 + ( V_192 * 3UL ) , V_140 ) ) {
F_264 ( L_291
L_314
L_315 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ,
F_167 ( V_140 -
V_441 -> V_818 ) ) ;
return 0 ;
}
if ( V_23 -> V_163 -> V_164 != 0 &&
F_310 ( V_140 , V_441 -> V_813 + V_23 -> V_163 -> V_164 ) ) {
F_264 ( L_291
L_296 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ,
F_167 ( V_140 -
V_441 -> V_813 ) ) ;
return 0 ;
}
if ( ( V_23 -> V_59 & V_549 ) &&
( V_441 -> V_197 != V_23 -> V_197 ) ) {
F_264 ( L_291
L_297 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ,
V_441 -> V_197 , V_23 -> V_197 ) ;
return 0 ;
}
if ( ( ( V_23 -> V_317 & V_814 ) ? 1 : 0 ) !=
( ( V_441 -> V_317 & V_815 ) ? 1 : 0 ) ) {
F_264 ( L_291
L_298 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ,
V_23 -> V_317 & V_814 ? L_299 :
L_300 ,
V_441 -> V_317 &
V_815 ? L_299 : L_300 ) ;
return 0 ;
}
if ( ( V_23 -> V_59 & V_819 ) &&
memcmp ( V_441 -> V_216 , V_23 -> V_216 , V_217 ) ) {
F_264 ( L_291
L_316 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 , V_23 -> V_216 ) ;
return 0 ;
}
if ( ! F_311 ( V_23 -> V_163 , V_441 -> V_118 ) ) {
F_264 ( L_291
L_303
L_304 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ) ;
return 0 ;
}
if ( ! F_133 ( V_23 -> V_163 , V_441 -> V_197 ) ) {
F_264 ( L_291
L_317 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ) ;
return 0 ;
}
if ( ! F_304 ( V_23 , V_441 , & V_336 ) ) {
F_264 ( L_291
L_305
L_306 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ) ;
return 0 ;
}
if ( V_336 . V_796 == 0 ) {
F_264 ( L_291
L_307 ,
F_291 ( V_311 , V_441 -> V_311 ,
V_441 -> V_810 ) ,
V_441 -> V_216 ) ;
return 0 ;
}
F_305 ( & V_809 -> V_336 , & V_336 ) ;
V_809 -> V_441 = V_441 ;
F_264 ( L_308 ,
F_291 ( V_311 , V_441 -> V_311 , V_441 -> V_810 ) ,
V_441 -> V_216 ) ;
return 1 ;
}
static void F_315 ( struct V_17 * V_23 ,
struct V_440 * V_441 )
{
const struct V_201 * V_202 = F_137 ( V_23 -> V_163 ) ;
int V_7 ;
switch ( F_133 ( V_23 -> V_163 , V_23 -> V_197 ) ) {
case V_820 :
V_441 -> V_118 = V_119 ;
V_7 = F_316 ( V_23 -> V_163 , V_23 -> V_197 ) ;
F_225 ( V_7 == - 1 ) ;
if ( V_202 -> V_18 [ V_7 ] . V_41 & V_207 ) {
F_93 ( L_318 ) ;
V_23 -> V_197 = V_202 -> V_18 [ 0 ] . V_197 ;
}
break;
case V_821 :
if ( V_23 -> V_163 -> V_118 & V_121 )
V_441 -> V_118 = V_121 ;
else
V_441 -> V_118 = V_608 ;
V_7 = F_316 ( V_23 -> V_163 , V_23 -> V_197 ) ;
F_225 ( V_7 == - 1 ) ;
if ( V_202 -> V_204 [ V_7 ] . V_41 & V_207 ) {
F_93 ( L_318 ) ;
V_23 -> V_197 = V_202 -> V_204 [ 0 ] . V_197 ;
}
break;
default:
F_93 ( L_318 ) ;
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
F_260 ( V_23 , V_441 -> V_216 ) ;
V_441 -> V_810 = V_23 -> V_668 ;
memcpy ( V_441 -> V_311 , V_23 -> V_667 , V_23 -> V_668 ) ;
memset ( & V_441 -> V_674 , 0 , sizeof( V_441 -> V_674 ) ) ;
V_441 -> V_317 = V_318 ;
if ( ! ( V_23 -> V_59 & V_822 ) )
V_441 -> V_317 |= V_823 ;
if ( V_23 -> V_317 & V_814 )
V_441 -> V_317 |= V_815 ;
V_441 -> V_797 = F_3 ( V_23 -> V_336 . V_796 , V_824 ) ;
memcpy ( V_441 -> V_336 , V_23 -> V_336 . V_799 , V_441 -> V_797 ) ;
V_441 -> V_800 = V_23 -> V_336 . V_796 - V_441 -> V_797 ;
memcpy ( V_441 -> V_801 ,
& V_23 -> V_336 . V_799 [ V_441 -> V_797 ] ,
V_441 -> V_800 ) ;
V_441 -> V_813 = 0 ;
V_441 -> V_41 = 0 ;
V_441 -> V_818 = 0 ;
V_441 -> V_467 [ 0 ] = 0 ;
V_441 -> V_467 [ 1 ] = 0 ;
V_441 -> V_640 = 100 ;
V_441 -> V_825 = 10 ;
V_441 -> V_826 = 0 ;
V_441 -> V_827 = 0 ;
V_441 -> V_828 = 0 ;
}
static void F_317 ( struct V_17 * V_23 , int type , int V_400 )
{
struct V_829 V_830 ;
if ( ! ( V_23 -> V_163 -> V_244 . V_41 & ( 1 << V_400 ) ) )
return;
V_830 . V_831 = V_400 ;
memcpy ( V_830 . V_830 , V_23 -> V_163 -> V_244 . V_832 [ V_400 ] , V_833 ) ;
V_830 . V_731 = type ;
V_830 . V_732 = 0 ;
V_830 . V_41 = 0 ;
V_830 . V_834 [ 0 ] = F_179 ( 0 ) ;
V_830 . V_834 [ 1 ] = F_179 ( 0 ) ;
F_155 ( V_23 , V_835 , sizeof( V_830 ) , & V_830 ) ;
}
static void F_318 ( struct V_17 * V_23 , int type )
{
struct V_836 V_830 ;
int V_7 ;
V_830 . V_837 = V_838 ;
V_830 . V_839 = 0 ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_830 . V_840 = V_7 | type ;
if ( ! ( V_23 -> V_163 -> V_244 . V_41 & ( 1 << V_7 ) ) ) {
V_830 . V_841 = 0 ;
continue;
}
V_830 . V_841 = V_23 -> V_163 -> V_244 . V_842 [ V_7 ] ;
memcpy ( V_830 . V_830 , V_23 -> V_163 -> V_244 . V_832 [ V_7 ] , V_830 . V_841 ) ;
F_155 ( V_23 , V_302 , sizeof( V_830 ) , & V_830 ) ;
}
}
static void F_319 ( struct V_17 * V_23 , int V_11 )
{
if ( V_23 -> V_163 -> V_843 )
return;
switch ( V_11 ) {
case V_844 :
V_23 -> V_310 . V_845 = 0 ;
V_23 -> V_163 -> V_846 = 0 ;
break;
case V_847 :
V_23 -> V_310 . V_845 = 1 ;
V_23 -> V_163 -> V_846 = 1 ;
break;
case V_848 :
V_23 -> V_310 . V_845 = 0 ;
V_23 -> V_163 -> V_846 = 0 ;
break;
case V_849 :
V_23 -> V_310 . V_845 = 1 ;
break;
default:
break;
}
}
static void F_320 ( struct V_17 * V_23 , int V_11 )
{
if ( V_23 -> V_163 -> V_843 )
return;
switch ( V_11 ) {
case V_844 :
V_23 -> V_310 . V_850 = 0 ;
break;
case V_847 :
V_23 -> V_310 . V_850 = 1 ;
break;
case V_848 :
V_23 -> V_310 . V_850 = 0 ;
break;
case V_849 :
V_23 -> V_310 . V_850 = 1 ;
break;
default:
break;
}
}
static void F_321 ( struct V_17 * V_23 )
{
switch ( V_23 -> V_163 -> V_244 . V_11 ) {
case V_844 :
if ( V_23 -> V_163 -> V_244 . V_41 & V_851 )
F_317 ( V_23 ,
V_852 ,
V_23 -> V_163 -> V_244 . V_853 ) ;
if ( ! V_23 -> V_163 -> V_854 )
F_318 ( V_23 , V_855 ) ;
break;
case V_847 :
if ( V_23 -> V_163 -> V_244 . V_41 & V_851 )
F_317 ( V_23 ,
V_856 ,
V_23 -> V_163 -> V_244 . V_853 ) ;
break;
case V_848 :
F_318 ( V_23 , V_857 ) ;
F_319 ( V_23 , V_23 -> V_163 -> V_244 . V_11 ) ;
F_320 ( V_23 , V_23 -> V_163 -> V_244 . V_11 ) ;
break;
case V_849 :
default:
break;
}
}
static void F_322 ( void * V_3 )
{
struct V_17 * V_23 = V_3 ;
if ( V_23 -> V_548 ++ > V_23 -> V_647 &&
! ( V_23 -> V_59 & V_550 ) ) {
F_283 ( V_648 | V_649 |
V_650 | V_651 ,
L_223 ,
V_23 -> V_548 ) ;
F_162 ( V_23 ) ;
F_265 ( V_23 ) ;
return;
}
F_56 ( & V_23 -> V_669 ,
F_221 ( V_23 -> V_559 . V_640 ) ) ;
}
static void F_323 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_669 . V_107 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_322 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_324 ( struct V_17 * V_23 )
{
F_290 ( V_311 ) ;
F_74 ( L_319
L_320 , V_23 -> V_59 ) ;
if ( V_23 -> V_59 & V_549 )
F_74 ( L_321 , V_23 -> V_197 ) ;
else
F_74 ( L_322 ) ;
if ( V_23 -> V_59 & V_811 )
F_74 ( L_323 ,
F_291 ( V_311 , V_23 -> V_667 , V_23 -> V_668 ) ) ;
else
F_74 ( L_324 ) ;
if ( V_23 -> V_59 & V_819 )
F_74 ( L_325 , V_23 -> V_216 ) ;
else
F_74 ( L_326 ) ;
if ( V_23 -> V_317 & V_814 )
F_74 ( L_327 ) ;
else
F_74 ( L_328 ) ;
F_74 ( L_329 , V_23 -> V_594 ) ;
}
static void F_325 ( struct V_17 * V_23 , int V_118 )
{
struct V_858 V_859 ;
T_3 V_24 ;
T_4 V_36 = 0 ;
T_4 V_860 = V_23 -> V_594 ;
switch ( V_23 -> V_163 -> V_861 ) {
case V_820 :
if ( V_23 -> V_594 & ~ V_862 ) {
F_326
( L_330 ) ;
V_860 = 0 ;
break;
}
V_860 >>= V_863 ;
break;
default:
if ( V_118 == V_608 ) {
if ( V_860 & ~ V_595 ) {
F_326
( L_330 ) ;
V_860 = 0 ;
}
break;
}
if ( V_860 & ~ ( V_595 |
V_862 ) ) {
F_326
( L_330 ) ;
V_860 = 0 ;
break;
}
if ( V_599 & V_860 ) {
V_36 |= ( V_599 >> 1 ) ;
V_860 &= ~ V_599 ;
}
if ( V_600 & V_860 ) {
V_36 |= ( V_600 >> 1 ) ;
V_860 &= ~ V_600 ;
}
if ( V_602 & V_860 ) {
V_36 |= ( V_602 >> 1 ) ;
V_860 &= ~ V_602 ;
}
V_860 |= V_36 ;
break;
}
V_859 . V_864 = F_173 ( V_860 ) ;
V_24 = F_36 ( V_23 , V_865 ) ;
F_12 ( V_23 , V_24 , * ( T_3 * ) & V_859 ) ;
}
static void F_168 ( struct V_17 * V_23 )
{
int V_557 ;
if ( V_23 -> V_37 & V_319 ) {
F_142 ( L_331 ) ;
return;
}
V_23 -> V_37 |= V_319 ;
V_557 = F_171 ( V_23 ) ;
if ( V_557 )
F_142 ( L_332 ) ;
}
static void F_327 ( struct V_17 * V_23 ,
struct V_323 * V_866 ,
int V_700 )
{
int V_867 = 0 ;
const struct V_201 * V_202 ;
int V_7 ;
V_202 = F_137 ( V_23 -> V_163 ) ;
if ( V_23 -> V_163 -> V_861 & V_820 ) {
int V_389 = V_867 ;
for ( V_7 = 0 ; V_7 < V_202 -> V_209 ; V_7 ++ ) {
if ( ( V_23 -> V_37 & V_103 ) &&
V_202 -> V_18 [ V_7 ] . V_197 == V_23 -> V_197 )
continue;
V_867 ++ ;
V_866 -> V_868 [ V_867 ] = V_202 -> V_18 [ V_7 ] . V_197 ;
F_328 ( V_866 , V_867 ,
V_202 -> V_18 [ V_7 ] .
V_41 & V_207 ?
V_869 :
V_700 ) ;
}
if ( V_389 != V_867 ) {
V_866 -> V_868 [ V_389 ] = ( T_2 ) ( V_354 << 6 ) |
( V_867 - V_389 ) ;
V_867 ++ ;
}
}
if ( V_23 -> V_163 -> V_861 & V_821 ) {
int V_389 = V_867 ;
if ( V_23 -> V_59 & V_195 ) {
int V_400 ;
T_2 V_870 [ V_871 ] = {
[ 0 ] = 0
} ;
T_2 V_197 ;
while ( V_867 < V_872 - 1 ) {
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
if ( V_870 [ V_197 - 1 ] != 0 )
break;
V_870 [ V_197 - 1 ] = 1 ;
V_23 -> V_199 ++ ;
V_867 ++ ;
V_866 -> V_868 [ V_867 ] = V_197 ;
V_400 =
F_316 ( V_23 -> V_163 , V_197 ) ;
F_328 ( V_866 , V_867 ,
V_202 -> V_204 [ V_400 ] .
V_41 &
V_207 ?
V_869
: V_700 ) ;
}
} else {
for ( V_7 = 0 ; V_7 < V_202 -> V_203 ; V_7 ++ ) {
if ( ( V_23 -> V_37 & V_103 ) &&
V_202 -> V_204 [ V_7 ] . V_197 == V_23 -> V_197 )
continue;
V_867 ++ ;
V_866 -> V_868 [ V_867 ] =
V_202 -> V_204 [ V_7 ] . V_197 ;
F_328 ( V_866 , V_867 ,
V_202 -> V_204 [ V_7 ] .
V_41 &
V_207 ?
V_869
: V_700 ) ;
}
}
if ( V_389 != V_867 ) {
V_866 -> V_868 [ V_389 ] = ( T_2 ) ( V_352 << 6 ) |
( V_867 - V_389 ) ;
}
}
}
static int F_329 ( struct V_17 * V_23 )
{
if ( V_23 -> V_37 & V_103
&& V_23 -> V_117 -> V_640 > 10 )
return V_23 -> V_117 -> V_640 - 10 ;
else
return 120 ;
}
static int F_330 ( struct V_17 * V_23 , int type , int V_873 )
{
struct V_323 V_866 ;
int V_557 = 0 , V_700 ;
if ( ! ( V_23 -> V_37 & V_69 ) ||
( V_23 -> V_37 & V_701 ) )
return 0 ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_873 && ( V_23 -> V_874 == 0 ) ) {
F_142 ( L_333 ) ;
V_23 -> V_37 &= ~ V_704 ;
goto V_766;
}
if ( V_23 -> V_37 & V_321 ) {
F_142 ( L_334 ) ;
V_23 -> V_37 |= V_873 ? V_704 :
V_707 ;
goto V_766;
}
if ( ! ( V_23 -> V_37 & V_703 ) &&
V_23 -> V_37 & V_319 ) {
F_142 ( L_335 ) ;
V_23 -> V_37 |= V_873 ? V_704 :
V_707 ;
goto V_766;
}
if ( V_23 -> V_37 & V_99 ) {
F_142 ( L_336 ) ;
V_23 -> V_37 |= V_873 ? V_704 :
V_707 ;
goto V_766;
}
memset ( & V_866 , 0 , sizeof( V_866 ) ) ;
V_866 . V_875 = F_179 ( F_331 ( V_23 -> V_163 ) ) ;
if ( type == V_876 ) {
F_326 ( L_337 ) ;
V_700 = V_869 ;
V_866 . V_877 [ V_869 ] =
F_173 ( F_329 ( V_23 ) ) ;
F_327 ( V_23 , & V_866 , V_700 ) ;
goto V_878;
}
if ( V_23 -> V_59 & V_195 )
V_866 . V_877 [ V_879 ] =
F_173 ( 30 ) ;
else
V_866 . V_877 [ V_879 ] =
F_173 ( 20 ) ;
V_866 . V_877 [ V_880 ] =
F_173 ( 20 ) ;
V_866 . V_877 [ V_869 ] =
F_173 ( F_329 ( V_23 ) ) ;
V_866 . V_877 [ V_881 ] = F_173 ( 20 ) ;
#ifdef F_244
if ( V_23 -> V_163 -> V_513 == V_515 ) {
T_2 V_197 ;
T_2 V_882 = 0 ;
switch ( F_133 ( V_23 -> V_163 , V_23 -> V_197 ) ) {
case V_820 :
V_882 = ( T_2 ) ( V_354 << 6 ) | 1 ;
V_197 = V_23 -> V_197 ;
break;
case V_821 :
V_882 = ( T_2 ) ( V_352 << 6 ) | 1 ;
V_197 = V_23 -> V_197 ;
break;
default:
V_882 = ( T_2 ) ( V_352 << 6 ) | 1 ;
V_197 = 9 ;
break;
}
V_866 . V_868 [ 0 ] = V_882 ;
V_866 . V_868 [ 1 ] = V_197 ;
F_328 ( & V_866 , 1 , V_869 ) ;
V_866 . V_877 [ V_869 ] =
F_173 ( 2000 ) ;
} else {
#endif
if ( V_873 ) {
V_557 = F_158 ( V_23 , V_23 -> V_883 ,
V_23 -> V_874 ) ;
if ( V_557 ) {
F_142 ( L_338
L_339 ) ;
goto V_766;
}
V_700 = V_880 ;
} else if ( ( V_23 -> V_37 & V_652 )
|| ( ! ( V_23 -> V_37 & V_103 )
&& ( V_23 -> V_59 & V_811 )
&& ( F_226 ( V_866 . V_875 ) % 2 ) ) ) {
V_557 = F_158 ( V_23 , V_23 -> V_667 , V_23 -> V_668 ) ;
if ( V_557 ) {
F_142 ( L_340
L_65 ) ;
goto V_766;
}
V_700 = V_880 ;
} else
V_700 = V_879 ;
F_327 ( V_23 , & V_866 , V_700 ) ;
#ifdef F_244
}
#endif
V_878:
V_557 = F_170 ( V_23 , & V_866 ) ;
if ( V_557 ) {
F_142 ( L_341 , V_557 ) ;
goto V_766;
}
V_23 -> V_37 |= V_321 ;
if ( V_873 ) {
V_23 -> V_37 &= ~ V_704 ;
V_23 -> V_874 = 0 ;
} else
V_23 -> V_37 &= ~ V_707 ;
F_56 ( & V_23 -> V_322 , V_320 ) ;
V_766:
F_60 ( & V_23 -> V_109 ) ;
return V_557 ;
}
static void F_332 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_188 . V_107 ) ;
F_330 ( V_23 , V_876 , 0 ) ;
}
static void F_333 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_186 . V_107 ) ;
F_330 ( V_23 , V_884 , 0 ) ;
}
static void F_334 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_187 . V_107 ) ;
F_330 ( V_23 , V_884 , 1 ) ;
}
static void F_335 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_653 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_168 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int F_336 ( struct V_17 * V_23 , int V_25 )
{
V_23 -> V_163 -> V_885 = V_25 ;
return 0 ;
}
static int F_337 ( struct V_17 * V_23 , int V_25 )
{
struct V_886 * V_163 = V_23 -> V_163 ;
struct V_887 V_244 = {
. V_41 = V_888 ,
} ;
int V_432 = 0 ;
if ( V_25 & V_889 ) {
V_244 . V_890 = V_891 ;
V_163 -> V_892 = 0 ;
} else if ( V_25 & V_893 ) {
V_244 . V_890 = V_894 ;
V_163 -> V_892 = 1 ;
} else if ( V_25 & V_895 ) {
V_244 . V_890 = V_896 ;
V_163 -> V_892 = 1 ;
} else
return - V_75 ;
if ( V_163 -> V_897 )
V_163 -> V_897 ( V_163 -> V_166 , & V_244 ) ;
else
V_432 = - V_898 ;
return V_432 ;
}
static void F_338 ( struct V_17 * V_23 , char * V_899 ,
int V_827 )
{
F_336 ( V_23 , 1 ) ;
}
static int F_339 ( struct V_17 * V_23 ,
char * V_900 , int V_415 )
{
F_142 ( L_342 ) ;
return F_155 ( V_23 , V_901 , V_415 ,
V_900 ) ;
}
static int F_340 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
struct V_886 * V_163 = V_23 -> V_163 ;
T_2 * V_1 ;
int V_557 = 0 ;
if ( V_211 -> V_3 . V_415 > V_905 ||
( V_211 -> V_3 . V_415 && V_904 == NULL ) )
return - V_75 ;
if ( V_211 -> V_3 . V_415 ) {
V_1 = F_342 ( V_904 , V_211 -> V_3 . V_415 , V_148 ) ;
if ( V_1 == NULL ) {
V_557 = - V_476 ;
goto V_6;
}
F_87 ( V_163 -> V_899 ) ;
V_163 -> V_899 = V_1 ;
V_163 -> V_827 = V_211 -> V_3 . V_415 ;
} else {
F_87 ( V_163 -> V_899 ) ;
V_163 -> V_899 = NULL ;
V_163 -> V_827 = 0 ;
}
F_338 ( V_23 , V_163 -> V_899 , V_163 -> V_827 ) ;
V_6:
return V_557 ;
}
static int F_343 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
struct V_886 * V_163 = V_23 -> V_163 ;
int V_557 = 0 ;
if ( V_163 -> V_827 == 0 || V_163 -> V_899 == NULL ) {
V_211 -> V_3 . V_415 = 0 ;
goto V_6;
}
if ( V_211 -> V_3 . V_415 < V_163 -> V_827 ) {
V_557 = - V_906 ;
goto V_6;
}
V_211 -> V_3 . V_415 = V_163 -> V_827 ;
memcpy ( V_904 , V_163 -> V_899 , V_163 -> V_827 ) ;
V_6:
return V_557 ;
}
static int F_344 ( int V_907 )
{
switch ( V_907 ) {
case V_908 :
return V_849 ;
case V_909 :
case V_910 :
return V_848 ;
case V_911 :
return V_847 ;
case V_912 :
return V_844 ;
default:
return - 1 ;
}
}
static int F_345 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
struct V_886 * V_163 = V_23 -> V_163 ;
struct V_913 * V_154 = & V_211 -> V_154 ;
struct V_914 * V_915 ;
unsigned long V_41 ;
int V_432 = 0 ;
switch ( V_154 -> V_41 & V_916 ) {
case V_917 :
break;
case V_918 :
F_319 ( V_23 ,
F_344 ( V_154 -> V_25 ) ) ;
break;
case V_919 :
F_320 ( V_23 ,
F_344 ( V_154 -> V_25 ) ) ;
break;
case V_920 :
break;
case V_921 :
V_915 = V_23 -> V_163 -> V_922 . V_915 [ V_23 -> V_163 -> V_922 . V_923 ] ;
if ( ! V_915 || ! V_915 -> V_924 -> V_925 || ! V_915 -> V_924 -> V_926 )
break;
V_41 = V_915 -> V_924 -> V_926 ( V_915 -> V_23 ) ;
if ( V_154 -> V_25 )
V_41 |= V_927 ;
else
V_41 &= ~ V_927 ;
V_915 -> V_924 -> V_925 ( V_41 , V_915 -> V_23 ) ;
break;
case V_928 : {
struct V_887 V_244 = {
. V_41 = V_929 ,
. V_930 = V_154 -> V_25 ,
} ;
V_23 -> V_163 -> V_931 = V_154 -> V_25 ;
if ( ! V_154 -> V_25 ) {
V_244 . V_41 |= V_932 ;
V_244 . V_11 = V_849 ;
} else {
V_244 . V_41 |= V_932 ;
V_244 . V_11 = V_848 ;
}
if ( V_23 -> V_163 -> V_897 )
V_23 -> V_163 -> V_897 ( V_23 -> V_163 -> V_166 , & V_244 ) ;
break;
}
case V_933 :
V_432 = F_337 ( V_23 , V_154 -> V_25 ) ;
break;
case V_934 :
V_432 = F_336 ( V_23 , V_154 -> V_25 ) ;
F_265 ( V_23 ) ;
break;
case V_935 :
V_163 -> V_936 = V_154 -> V_25 ;
break;
case V_937 :
V_163 -> V_938 = V_154 -> V_25 ;
break;
default:
return - V_898 ;
}
return V_432 ;
}
static int F_346 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
struct V_886 * V_163 = V_23 -> V_163 ;
struct V_914 * V_915 ;
struct V_913 * V_154 = & V_211 -> V_154 ;
switch ( V_154 -> V_41 & V_916 ) {
case V_917 :
case V_918 :
case V_919 :
case V_920 :
return - V_898 ;
case V_921 :
V_915 = V_23 -> V_163 -> V_922 . V_915 [ V_23 -> V_163 -> V_922 . V_923 ] ;
if ( ! V_915 || ! V_915 -> V_924 -> V_926 )
break;
V_154 -> V_25 = ( V_915 -> V_924 -> V_926 ( V_915 -> V_23 ) &
V_927 ) ? 1 : 0 ;
break;
case V_928 :
V_154 -> V_25 = V_163 -> V_931 ;
break;
case V_933 :
V_154 -> V_25 = V_163 -> V_244 . V_890 ;
break;
case V_934 :
V_154 -> V_25 = V_163 -> V_885 ;
break;
case V_935 :
V_154 -> V_25 = V_163 -> V_936 ;
break;
case V_939 :
case V_937 :
V_154 -> V_25 = V_163 -> V_938 ;
break;
default:
return - V_898 ;
}
return 0 ;
}
static int F_347 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
struct V_940 * V_941 = (struct V_940 * ) V_904 ;
if ( V_942 ) {
if ( V_941 -> V_943 == V_944 ) {
if ( V_941 -> V_945 & V_946 )
V_23 -> V_163 -> V_854 = 1 ;
else {
V_23 -> V_163 -> V_843 = 0 ;
V_23 -> V_163 -> V_947 = 1 ;
V_23 -> V_163 -> V_846 = 1 ;
}
} else {
V_23 -> V_163 -> V_843 = 0 ;
V_23 -> V_163 -> V_947 = 0 ;
V_23 -> V_163 -> V_846 = 0 ;
V_23 -> V_163 -> V_854 = 0 ;
}
}
return F_348 ( V_23 -> V_163 , V_903 , V_211 , V_904 ) ;
}
static int F_349 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
return F_350 ( V_23 -> V_163 , V_903 , V_211 , V_904 ) ;
}
static int F_351 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
struct V_948 * V_949 = (struct V_948 * ) V_904 ;
T_8 V_570 ;
V_570 = F_173 ( V_949 -> V_950 ) ;
switch ( V_949 -> V_153 ) {
case V_951 :
break;
case V_952 :
F_265 ( V_23 ) ;
break;
default:
return - V_898 ;
}
return 0 ;
}
static T_2 F_352 ( struct V_17 * V_23 )
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
F_294 ( L_343 , V_118 ) ;
return V_118 ;
}
static int F_353 ( struct V_17 * V_23 ,
int V_953 ,
struct V_440 * V_441 )
{
T_3 V_15 = sizeof( struct V_954 ) ;
if ( V_441 -> V_317 & V_318 )
V_441 -> V_955 . V_956 = V_441 -> V_955 . V_957 ;
if ( V_441 -> V_41 & V_958 ) {
if ( V_953 &&
( V_441 -> V_41 & V_959 ) )
V_441 -> V_955 . V_956 = V_441 -> V_955 . V_957 ;
if ( ( V_441 -> V_955 . V_956 == 1 ) && ( V_953 == 1 ) &&
( V_441 -> V_41 & V_959 ) &&
( V_441 -> V_955 . V_960 !=
V_441 -> V_955 . V_961 ) ) {
V_441 -> V_955 . V_960 =
V_441 -> V_955 . V_961 ;
F_128 ( & V_23 -> V_962 ) ;
F_294 ( L_344
L_345 ) ;
}
} else {
if ( ( V_23 -> V_163 -> V_118 == V_608 ) || ( V_441 -> V_118 == V_608 ) )
memcpy ( & V_441 -> V_955 . V_963 ,
& V_964 , V_15 ) ;
else
memcpy ( & V_441 -> V_955 . V_963 ,
& V_965 , V_15 ) ;
if ( ( V_441 -> V_955 . V_956 == 1 ) && ( V_953 == 1 ) ) {
F_294 ( L_346 ) ;
F_128 ( & V_23 -> V_962 ) ;
}
V_441 -> V_955 . V_956 = 0 ;
V_441 -> V_955 . V_957 = 0 ;
}
if ( ( V_23 -> V_37 & V_103 ) &&
( V_23 -> V_163 -> V_513 == V_514 ) && ( V_953 == 0 ) ) {
if ( memcmp ( V_441 -> V_216 , V_23 -> V_216 , V_217 ) )
if ( V_441 -> V_317 & V_318 )
if ( ( V_441 -> V_810 ==
V_23 -> V_117 -> V_810 ) &&
! memcmp ( V_441 -> V_311 ,
V_23 -> V_117 -> V_311 ,
V_441 -> V_810 ) ) {
F_128 ( & V_23 -> V_816 ) ;
}
}
return 0 ;
}
static int F_354 ( struct V_17 * V_23 ,
struct V_966 * V_967 )
{
int V_557 ;
struct V_954 V_968 [ V_969 ] ;
struct V_954 * V_970 = NULL ;
T_3 V_15 = sizeof( struct V_954 ) ;
T_3 V_971 ;
int V_7 ;
T_2 type ;
type = F_352 ( V_23 ) ;
V_970 = & ( V_968 [ V_972 ] ) ;
memcpy ( V_970 , V_23 -> V_955 . V_973 , V_15 ) ;
V_970 = & ( V_968 [ V_974 ] ) ;
memcpy ( V_970 , V_23 -> V_955 . V_975 , V_15 ) ;
if ( V_967 == NULL ) {
if ( type == V_608 ) {
F_294 ( L_347 , type ) ;
V_970 = & V_964 ;
} else
V_970 = & V_965 ;
memcpy ( & V_968 [ V_976 ] , V_970 , V_15 ) ;
V_971 = F_355 ( V_23 ) ;
for ( V_7 = 0 ; V_7 < V_977 ; V_7 ++ )
V_968 [ V_976 ] . V_978 [ V_7 ] =
F_173 ( V_971 ) ;
} else if ( V_23 -> V_163 -> V_513 == V_514 ) {
if ( type == V_608 ) {
F_294 ( L_348 ,
type ) ;
if ( V_23 -> V_955 . V_979 == 0 )
V_970 = & V_964 ;
else
V_970 = V_23 -> V_955 . V_973 ;
} else {
if ( V_23 -> V_955 . V_979 == 0 )
V_970 = & V_965 ;
else
V_970 = V_23 -> V_955 . V_975 ;
}
memcpy ( & V_968 [ V_976 ] , V_970 , V_15 ) ;
} else {
unsigned long V_41 ;
int V_956 ;
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
V_970 = & ( V_967 -> V_963 ) ;
V_967 -> V_960 =
V_967 -> V_961 ;
memcpy ( & V_968 [ V_976 ] , V_970 , V_15 ) ;
V_956 = V_967 -> V_957 ;
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
if ( V_956 == 0 ) {
V_971 = F_355 ( V_23 ) ;
for ( V_7 = 0 ; V_7 < V_977 ; V_7 ++ )
V_968 [ V_976 ] .
V_978 [ V_7 ] = F_173 ( V_971 ) ;
}
}
F_294 ( L_349 ) ;
V_557 = F_356 ( V_23 , & V_968 [ 0 ] ) ;
if ( V_557 )
F_294 ( L_350 ) ;
return V_557 ;
}
static int F_357 ( struct V_17 * V_23 )
{
int V_432 = 0 ;
struct V_980 V_981 ;
if ( V_23 == NULL )
return - 1 ;
V_981 . V_982 = V_983 ;
V_981 . V_415 = sizeof( struct V_980 ) - 2 ;
V_981 . V_984 = V_985 ;
V_981 . V_986 = 0 ;
memcpy ( V_981 . V_987 , V_988 , V_989 ) ;
V_981 . V_990 = V_991 ;
V_981 . V_992 = V_993 ;
V_432 = F_358 ( V_23 , & V_981 ) ;
if ( V_432 != 0 ) {
F_294 ( L_351 ) ;
}
return V_432 ;
}
static int F_359 ( struct V_17 * V_23 ,
struct V_440 * V_441 )
{
int V_557 = 0 ;
struct V_966 * V_955 = NULL ;
struct V_966 V_994 = {
. V_957 = 1 ,
. V_956 = 1 ,
} ;
switch ( V_23 -> V_163 -> V_513 ) {
case V_514 :
F_225 ( ! ( V_441 -> V_317 & V_318 ) ) ;
V_955 = & V_994 ;
break;
case V_516 :
V_955 = & V_441 -> V_955 ;
break;
default:
F_360 () ;
break;
}
V_557 = F_354 ( V_23 , V_955 ) ;
if ( V_557 ) {
V_23 -> V_559 . V_995 &= ~ V_996 ;
return V_557 ;
}
if ( V_23 -> V_955 . V_979 && V_955 -> V_957 ) {
F_294 ( L_352 ) ;
V_23 -> V_559 . V_995 |= V_996 ;
return F_357 ( V_23 ) ;
}
return 0 ;
}
static int F_361 ( struct V_17 * V_23 ,
struct V_440 * V_441 )
{
int V_432 = 0 ;
unsigned long V_41 ;
T_3 V_15 = sizeof( struct V_954 ) ;
int V_997 = 0 ;
if ( ( V_23 == NULL ) || ( V_441 == NULL ) ||
( V_23 -> V_117 == NULL ) )
return V_432 ;
if ( ! ( V_23 -> V_37 & V_103 ) )
return V_432 ;
if ( ( V_23 -> V_163 -> V_513 != V_516 ) )
return V_432 ;
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
if ( V_441 -> V_41 & V_959 ) {
memcpy ( & V_23 -> V_117 -> V_955 , & V_441 -> V_955 ,
sizeof( struct V_966 ) ) ;
V_23 -> V_117 -> V_955 . V_956 = 1 ;
if ( ( V_441 -> V_955 . V_960 !=
V_441 -> V_955 . V_961 ) ) {
V_997 = 1 ;
V_441 -> V_955 . V_960 =
V_441 -> V_955 . V_961 ;
}
} else {
if ( ( V_441 -> V_118 == V_608 ) || ( V_23 -> V_163 -> V_118 == V_608 ) )
memcpy ( & V_23 -> V_117 -> V_955 . V_963 ,
& V_964 , V_15 ) ;
else
memcpy ( & V_23 -> V_117 -> V_955 . V_963 ,
& V_965 , V_15 ) ;
V_23 -> V_117 -> V_955 . V_956 = 0 ;
V_23 -> V_117 -> V_955 . V_957 = 0 ;
V_997 = 1 ;
}
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
if ( V_997 == 1 )
F_128 ( & V_23 -> V_962 ) ;
return V_432 ;
}
static T_3 F_355 ( struct V_17 * V_23 )
{
T_3 V_432 = 0 ;
if ( ( V_23 == NULL ) )
return 0 ;
if ( ! ( V_23 -> V_163 -> V_804 & V_807 ) )
V_432 = V_23 -> V_955 . V_998 ;
else
V_432 = V_23 -> V_955 . V_999 ;
return V_432 ;
}
static void F_362 ( struct V_17 * V_23 , int V_1000 ,
int V_1001 , T_3 V_998 ,
T_3 V_999 )
{
V_23 -> V_955 . V_979 = V_1000 ;
if ( V_23 -> V_955 . V_979 ) {
V_23 -> V_955 . V_973 = & V_1002 ;
V_23 -> V_955 . V_975 = & V_1003 ;
F_294 ( L_353 ) ;
} else {
V_23 -> V_955 . V_973 = & V_964 ;
V_23 -> V_955 . V_975 = & V_965 ;
F_294 ( L_354 ) ;
}
V_23 -> V_955 . V_1001 = V_1001 ;
if ( V_1001 ) {
V_23 -> V_955 . V_998 = V_998 ;
V_23 -> V_955 . V_999 = V_999 ;
} else {
V_23 -> V_955 . V_998 = 0 ;
V_23 -> V_955 . V_999 = 0 ;
}
}
static int F_363 ( struct V_17 * V_23 , T_4 V_1004 )
{
if ( V_1004 > 7 || ! V_23 -> V_955 . V_979 )
V_1004 = 0 ;
return V_1005 [ V_1004 ] - 1 ;
}
static int F_364 ( struct V_165 * V_166 ,
struct V_1006 * V_501 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
struct V_966 * V_955 = NULL ;
int V_956 , V_957 ;
T_2 * V_1007 = V_501 -> V_3 + V_217 ;
int V_1008 = ! F_365 ( V_1007 ) ;
if ( ! ( V_23 -> V_37 & V_103 ) )
return 0 ;
V_955 = & V_23 -> V_117 -> V_955 ;
if ( V_23 -> V_163 -> V_513 == V_514 ) {
if ( V_1008 == 0 )
V_955 -> V_956 = 0 ;
else
V_955 -> V_956 = V_955 -> V_957 ;
}
V_956 = V_955 -> V_956 ;
V_957 = V_955 -> V_957 ;
F_294 ( L_355
L_356 ,
V_23 -> V_955 . V_979 , V_956 , V_957 , V_1008 ) ;
if ( V_956 && V_23 -> V_955 . V_979 )
return 1 ;
return 0 ;
}
static int F_366 ( struct V_17 * V_23 ,
T_4 V_1004 ,
struct V_1009 * V_768 )
{
int V_1010 = 0 ;
V_1010 = V_1005 [ V_1004 ] - 1 ;
V_768 -> V_1011 |= V_1012 ;
if ( V_23 -> V_955 . V_1013 & ( 1UL << V_1010 ) ) {
V_768 -> V_1014 &= ~ V_1015 ;
V_768 -> V_768 . V_1016 . V_1017 . V_1018 |= F_173 ( V_1019 ) ;
}
return 0 ;
}
static void F_367 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_962 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_37 & V_103 )
F_354 ( V_23 , & ( V_23 -> V_117 -> V_955 ) ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int F_368 ( struct V_165 * V_166 ,
struct V_1020 * V_681 ,
struct V_440 * V_441 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
int V_953 = ( ( V_23 -> V_37 & V_103 ) &&
( V_441 == V_23 -> V_117 ) ) ;
F_353 ( V_23 , V_953 , V_441 ) ;
return 0 ;
}
static int F_369 ( struct V_165 * V_166 ,
struct V_1021 * V_681 ,
struct V_440 * V_441 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
int V_953 = ( ( V_23 -> V_37 & V_103 ) &&
( V_441 == V_23 -> V_117 ) ) ;
F_353 ( V_23 , V_953 , V_441 ) ;
return 0 ;
}
static int F_370 ( struct V_165 * V_166 ,
struct V_672 * V_681 ,
struct V_440 * V_441 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_361 ( V_23 , V_441 ) ;
return 0 ;
}
static int F_356 ( struct V_17 * V_23 , struct V_954
* V_1022 )
{
return F_155 ( V_23 , V_1023 ,
sizeof( * V_1022 ) * 3 , V_1022 ) ;
}
static int F_358 ( struct V_17 * V_23 , struct V_980
* V_1022 )
{
return F_155 ( V_23 , V_1024 , sizeof( * V_1022 ) ,
V_1022 ) ;
}
static int F_371 ( struct V_17 * V_23 ,
struct V_440 * V_441 ,
struct V_335 * V_336 , int V_654 )
{
int V_557 ;
F_290 ( V_311 ) ;
if ( V_23 -> V_59 & V_1025 )
F_325 ( V_23 , V_441 -> V_118 ) ;
if ( ! ( V_23 -> V_59 & V_811 ) ) {
V_23 -> V_668 = F_3 ( V_441 -> V_810 ,
( T_2 ) V_313 ) ;
memcpy ( V_23 -> V_667 , V_441 -> V_311 , V_23 -> V_668 ) ;
}
V_441 -> V_818 = V_140 ;
memset ( & V_23 -> V_559 , 0 , sizeof( V_23 -> V_559 ) ) ;
V_23 -> V_559 . V_197 = V_441 -> V_197 ;
V_23 -> V_559 . V_1026 = 0 ;
if ( ( V_23 -> V_317 & V_814 ) &&
( V_23 -> V_163 -> V_244 . V_890 == V_891 ) ) {
V_23 -> V_559 . V_1027 = V_1028 ;
V_23 -> V_559 . V_1026 = V_23 -> V_163 -> V_244 . V_853 ;
if ( V_23 -> V_163 -> V_244 . V_11 == V_848 )
F_318 ( V_23 , V_857 ) ;
} else if ( ( V_23 -> V_317 & V_814 ) &&
( V_23 -> V_163 -> V_244 . V_890 == V_896 ) )
V_23 -> V_559 . V_1027 = V_1029 ;
else
V_23 -> V_559 . V_1027 = V_1030 ;
if ( V_23 -> V_163 -> V_827 ) {
V_23 -> V_559 . V_995 = F_173 ( 0x02 ) ;
F_339 ( V_23 , V_23 -> V_163 -> V_899 ,
V_23 -> V_163 -> V_827 ) ;
}
if ( V_441 -> V_118 & V_23 -> V_163 -> V_118 & V_119 )
V_23 -> V_559 . V_347 = V_354 ;
else if ( V_441 -> V_118 & V_23 -> V_163 -> V_118 & V_121 )
V_23 -> V_559 . V_347 = V_348 ;
else if ( V_441 -> V_118 & V_23 -> V_163 -> V_118 & V_608 )
V_23 -> V_559 . V_347 = V_352 ;
V_23 -> V_559 . V_317 = F_173 ( V_441 -> V_317 ) ;
if ( ( V_441 -> V_317 & V_823 )
&& ! ( V_23 -> V_59 & V_822 ) ) {
V_23 -> V_559 . V_1031 = V_1032 ;
} else {
V_23 -> V_559 . V_1031 = V_1033 ;
V_23 -> V_559 . V_317 &=
~ F_173 ( V_823 ) ;
}
if ( V_23 -> V_163 -> V_513 == V_514 )
V_23 -> V_559 . V_317 &=
~ F_173 ( V_1034 ) ;
F_264 ( L_357
L_358 ,
V_654 ? L_359 : L_360 ,
F_291 ( V_311 , V_23 -> V_667 , V_23 -> V_668 ) ,
V_441 -> V_197 ,
V_1035 [ V_23 -> V_559 . V_347 ] ,
V_336 -> V_796 ,
( V_23 -> V_559 . V_1031 ==
V_1033 ) ? L_361 : L_362 ,
V_441 -> V_317 &
V_823 ? L_362 : L_361 ,
V_23 -> V_317 & V_814 ? L_363 : L_300 ,
V_23 -> V_317 & V_814 ?
( V_23 -> V_317 & V_1036 ? L_364 :
L_365 ) : L_108 ,
V_23 -> V_317 & V_814 ? L_366 : L_108 ,
V_23 -> V_317 & V_814 ?
'1' + V_23 -> V_163 -> V_244 . V_853 : '.' ,
V_23 -> V_317 & V_814 ? '.' : ' ' ) ;
V_23 -> V_559 . V_640 = F_173 ( V_441 -> V_640 ) ;
if ( ( V_23 -> V_163 -> V_513 == V_514 ) &&
( V_441 -> V_467 [ 0 ] == 0 ) && ( V_441 -> V_467 [ 1 ] == 0 ) ) {
V_23 -> V_559 . V_561 = V_1037 ;
V_23 -> V_559 . V_1038 = 0 ;
V_23 -> V_559 . V_1039 = 0 ;
} else {
if ( F_29 ( V_654 ) )
V_23 -> V_559 . V_561 = V_1040 ;
else
V_23 -> V_559 . V_561 = V_1041 ;
V_23 -> V_559 . V_1038 = F_179 ( V_441 -> V_467 [ 1 ] ) ;
V_23 -> V_559 . V_1039 = F_179 ( V_441 -> V_467 [ 0 ] ) ;
}
memcpy ( V_23 -> V_559 . V_216 , V_441 -> V_216 , V_217 ) ;
if ( V_23 -> V_163 -> V_513 == V_514 ) {
memset ( & V_23 -> V_559 . V_802 , 0xFF , V_217 ) ;
V_23 -> V_559 . V_826 = F_173 ( V_441 -> V_826 ) ;
} else {
memcpy ( V_23 -> V_559 . V_802 , V_441 -> V_216 , V_217 ) ;
V_23 -> V_559 . V_826 = 0 ;
}
V_23 -> V_559 . V_825 = F_173 ( V_441 -> V_825 ) ;
V_557 = F_158 ( V_23 , V_23 -> V_667 , V_23 -> V_668 ) ;
if ( V_557 ) {
F_142 ( L_367 ) ;
return V_557 ;
}
V_336 -> V_347 = V_23 -> V_559 . V_347 ;
V_336 -> V_1042 = V_1043 ;
F_175 ( V_23 , V_336 ) ;
if ( V_23 -> V_559 . V_347 == V_348 )
V_23 -> V_310 . V_1044 = 1 ;
else
V_23 -> V_310 . V_1044 = 0 ;
if ( V_23 -> V_163 -> V_513 == V_514 )
V_23 -> V_310 . V_1045 = 1 ;
else
V_23 -> V_310 . V_1045 = 0 ;
V_557 = F_157 ( V_23 ) ;
if ( V_557 ) {
F_142 ( L_368 ) ;
return V_557 ;
}
F_264 ( L_369 , V_441 -> V_674 . V_632 ) ;
V_557 = F_172 ( V_23 , V_441 -> V_674 . V_632 + V_1046 ) ;
if ( V_557 ) {
F_142 ( L_370 ) ;
return V_557 ;
}
V_23 -> V_197 = V_441 -> V_197 ;
memcpy ( V_23 -> V_216 , V_441 -> V_216 , V_217 ) ;
V_23 -> V_37 |= V_240 ;
V_23 -> V_37 &= ~ V_1047 ;
V_23 -> V_117 = V_441 ;
#ifdef F_292
F_359 ( V_23 , V_441 ) ;
#endif
V_557 = F_174 ( V_23 , & V_23 -> V_559 ) ;
if ( V_557 ) {
F_142 ( L_370 ) ;
return V_557 ;
}
F_283 ( V_650 , L_371 ,
F_291 ( V_311 , V_23 -> V_667 , V_23 -> V_668 ) ,
V_23 -> V_216 ) ;
return 0 ;
}
static void F_372 ( void * V_3 )
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
F_313 (network, &priv->ieee->network_list, list) {
if ( V_441 != V_23 -> V_117 )
F_314 ( V_23 , & V_809 , V_441 , 1 ) ;
}
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
V_23 -> V_117 -> V_674 . V_632 = V_632 ;
if ( V_809 . V_441 == V_23 -> V_117 ) {
F_264 ( L_372
L_373 ) ;
V_23 -> V_37 &= ~ V_652 ;
F_324 ( V_23 ) ;
return;
}
F_263 ( V_23 , 1 ) ;
V_23 -> V_117 = V_809 . V_441 ;
return;
}
F_304 ( V_23 , V_23 -> V_117 , & V_809 . V_336 ) ;
F_371 ( V_23 , V_23 -> V_117 , & V_809 . V_336 , 1 ) ;
V_23 -> V_37 &= ~ V_652 ;
}
static void F_373 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_706 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_372 ( V_23 ) ;
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
F_290 ( V_311 ) ;
if ( V_23 -> V_163 -> V_513 == V_515 ) {
F_264 ( L_374 ) ;
return 0 ;
}
if ( V_23 -> V_37 & ( V_103 | V_240 ) ) {
F_264 ( L_375
L_376 ) ;
return 0 ;
}
if ( V_23 -> V_37 & V_560 ) {
F_264 ( L_377
L_378 ) ;
F_128 ( & V_23 -> V_333 ) ;
return 0 ;
}
if ( ! F_47 ( V_23 ) || ( V_23 -> V_37 & V_321 ) ) {
F_264 ( L_379
L_380 ) ;
return 0 ;
}
if ( ! ( V_23 -> V_59 & V_1048 ) &&
! ( V_23 -> V_59 & ( V_811 | V_819 ) ) ) {
F_264 ( L_381 ) ;
return 0 ;
}
F_41 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
F_313 (network, &priv->ieee->network_list, list)
F_314 ( V_23 , & V_809 , V_441 , 0 ) ;
V_441 = V_809 . V_441 ;
V_336 = & V_809 . V_336 ;
if ( V_441 == NULL &&
V_23 -> V_163 -> V_513 == V_514 &&
V_23 -> V_59 & V_1049 &&
V_23 -> V_59 & V_811 &&
V_23 -> V_59 & V_549 ) {
if ( F_298 ( & V_23 -> V_163 -> V_443 ) ) {
struct V_440 * V_1050 = NULL ;
struct V_440 * V_1051 ;
F_313 (target, &priv->ieee->network_list, list) {
if ( ( V_1050 == NULL ) ||
( V_1051 -> V_813 < V_1050 -> V_813 ) )
V_1050 = V_1051 ;
}
F_213 ( & V_1050 -> V_442 ) ;
V_1051 = V_1050 ;
F_264 ( L_382
L_383 ,
F_291 ( V_311 , V_1051 -> V_311 ,
V_1051 -> V_810 ) ,
V_1051 -> V_216 ) ;
F_214 ( & V_1051 -> V_442 ,
& V_23 -> V_163 -> V_443 ) ;
}
V_438 = V_23 -> V_163 -> V_443 . V_775 ;
V_441 = F_212 ( V_438 , struct V_440 , V_442 ) ;
F_315 ( V_23 , V_441 ) ;
V_336 = & V_23 -> V_336 ;
F_213 ( V_438 ) ;
F_214 ( & V_441 -> V_442 , & V_23 -> V_163 -> V_1052 ) ;
}
F_42 ( & V_23 -> V_163 -> V_98 , V_41 ) ;
if ( ! V_441 ) {
F_324 ( V_23 ) ;
if ( ! ( V_23 -> V_37 & V_321 ) ) {
if ( ! ( V_23 -> V_59 & V_195 ) )
F_56 ( & V_23 -> V_186 ,
V_1053 ) ;
else
F_56 ( & V_23 -> V_186 , 0 ) ;
}
return 0 ;
}
F_371 ( V_23 , V_441 , V_336 , 0 ) ;
return 1 ;
}
static void F_374 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_333 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_332 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_375 ( struct V_17 * V_23 ,
struct V_1006 * V_501 )
{
struct V_1054 * V_1055 ;
T_4 V_1056 ;
V_1055 = (struct V_1054 * ) V_501 -> V_3 ;
V_1056 = F_221 ( V_1055 -> V_1057 ) ;
if ( ! ( V_1056 & V_1058 ) )
return;
V_1056 &= ~ V_1058 ;
V_1055 -> V_1057 = F_173 ( V_1056 ) ;
switch ( V_23 -> V_163 -> V_244 . V_11 ) {
case V_844 :
memmove ( V_501 -> V_3 + V_1059 ,
V_501 -> V_3 + V_1059 + 8 ,
V_501 -> V_4 - V_1059 - 8 ) ;
F_376 ( V_501 , V_501 -> V_4 - 16 ) ;
break;
case V_847 :
break;
case V_848 :
memmove ( V_501 -> V_3 + V_1059 ,
V_501 -> V_3 + V_1059 + 4 ,
V_501 -> V_4 - V_1059 - 4 ) ;
F_376 ( V_501 , V_501 -> V_4 - 8 ) ;
break;
case V_849 :
break;
default:
F_4 ( V_1060 L_384 ,
V_23 -> V_163 -> V_244 . V_11 ) ;
break;
}
}
static void F_377 ( struct V_17 * V_23 ,
struct V_773 * V_774 ,
struct V_673 * V_674 )
{
struct V_165 * V_166 = V_23 -> V_167 ;
struct V_675 * V_1055 ;
struct V_1061 * V_1062 = (struct V_1061 * ) V_774 -> V_501 -> V_3 ;
V_166 -> V_1063 = V_140 ;
if ( F_29 ( ( F_221 ( V_1062 -> V_538 . V_1064 . V_415 ) + V_1065 ) >
F_378 ( V_774 -> V_501 ) ) ) {
V_166 -> V_674 . V_1066 ++ ;
V_23 -> V_1067 . V_1068 . V_1069 ++ ;
F_379 ( L_385 ) ;
return;
} else if ( F_29 ( ! F_92 ( V_23 -> V_167 ) ) ) {
V_166 -> V_674 . V_1070 ++ ;
V_23 -> V_1067 . V_1068 . V_1069 ++ ;
F_379 ( L_386 ) ;
return;
}
F_380 ( V_774 -> V_501 , F_381 ( struct V_1061 , V_538 . V_1064 . V_3 ) ) ;
F_382 ( V_774 -> V_501 , F_221 ( V_1062 -> V_538 . V_1064 . V_415 ) ) ;
F_383 ( L_387 , V_774 -> V_501 -> V_4 ) ;
V_1055 = (struct V_675 * ) V_774 -> V_501 -> V_3 ;
if ( V_23 -> V_163 -> V_513 != V_515 &&
( F_365 ( V_1055 -> V_1071 ) ?
! V_23 -> V_163 -> V_854 : ! V_23 -> V_163 -> V_846 ) )
F_375 ( V_23 , V_774 -> V_501 ) ;
if ( ! F_384 ( V_23 -> V_163 , V_774 -> V_501 , V_674 ) )
V_166 -> V_674 . V_1066 ++ ;
else {
V_774 -> V_501 = NULL ;
F_63 ( V_23 ) ;
}
}
static void F_385 ( struct V_17 * V_23 ,
struct V_773 * V_774 ,
struct V_673 * V_674 )
{
struct V_165 * V_166 = V_23 -> V_167 ;
struct V_1061 * V_1062 = (struct V_1061 * ) V_774 -> V_501 -> V_3 ;
struct V_1072 * V_1064 = & V_1062 -> V_538 . V_1064 ;
T_4 V_1073 = V_1064 -> V_1073 ;
T_2 V_1074 = V_1064 -> V_1074 ;
T_7 V_1075 = V_1064 -> V_1076 - V_1046 ;
T_4 V_1077 = V_1064 -> V_609 ;
struct V_1078 * V_1079 ;
unsigned short V_4 = F_221 ( V_1062 -> V_538 . V_1064 . V_415 ) ;
V_166 -> V_1063 = V_140 ;
if ( F_29 ( ( F_221 ( V_1062 -> V_538 . V_1064 . V_415 ) + V_1065 ) >
F_378 ( V_774 -> V_501 ) ) ) {
V_166 -> V_674 . V_1066 ++ ;
V_23 -> V_1067 . V_1068 . V_1069 ++ ;
F_379 ( L_385 ) ;
return;
} else if ( F_29 ( ! F_92 ( V_23 -> V_167 ) ) ) {
V_166 -> V_674 . V_1070 ++ ;
V_23 -> V_1067 . V_1068 . V_1069 ++ ;
F_379 ( L_386 ) ;
return;
}
if ( V_4 > V_503 - sizeof( struct V_1078 ) ) {
V_166 -> V_674 . V_1070 ++ ;
V_23 -> V_1067 . V_1068 . V_1069 ++ ;
F_379 ( L_388 ) ;
return;
}
memmove ( V_774 -> V_501 -> V_3 + sizeof( struct V_1078 ) ,
V_774 -> V_501 -> V_3 + V_1065 , V_4 ) ;
V_1079 = (struct V_1078 * ) V_774 -> V_501 -> V_3 ;
V_1079 -> V_1080 . V_1081 = V_1082 ;
V_1079 -> V_1080 . V_1083 = 0 ;
V_1079 -> V_1080 . V_1084 = F_173 ( sizeof( struct V_1078 ) ) ;
V_1079 -> V_1080 . V_1085 = F_179 (
( 1 << V_1086 ) |
( 1 << V_1087 ) |
( 1 << V_1088 ) |
( 1 << V_1089 ) |
( 1 << V_1090 ) |
( 1 << V_1091 ) |
( 1 << V_1092 ) ) ;
V_1079 -> V_1093 = 0 ;
V_1079 -> V_1094 = ( V_1095 ) ( V_1064 -> V_1096 [ 3 ] << 24 |
V_1064 -> V_1096 [ 2 ] << 16 |
V_1064 -> V_1096 [ 1 ] << 8 |
V_1064 -> V_1096 [ 0 ] ) ;
V_1079 -> V_1097 = V_1075 ;
V_1079 -> V_1098 = ( T_7 ) F_221 ( V_1064 -> V_737 ) ;
V_1079 -> V_1099 = F_173 ( F_386 ( V_1073 ) ) ;
if ( V_1073 > 14 ) {
V_1079 -> V_1100 =
F_173 ( ( V_1101 | V_1102 ) ) ;
} else if ( V_1074 & 32 ) {
V_1079 -> V_1100 =
F_173 ( ( V_1103 | V_1104 ) ) ;
} else {
V_1079 -> V_1100 =
F_173 ( V_1101 | V_1104 ) ;
}
switch ( V_1077 ) {
case V_612 :
V_1079 -> V_1105 = 2 ;
break;
case V_613 :
V_1079 -> V_1105 = 4 ;
break;
case V_614 :
V_1079 -> V_1105 = 10 ;
break;
case V_615 :
V_1079 -> V_1105 = 12 ;
break;
case V_616 :
V_1079 -> V_1105 = 18 ;
break;
case V_617 :
V_1079 -> V_1105 = 22 ;
break;
case V_618 :
V_1079 -> V_1105 = 24 ;
break;
case V_619 :
V_1079 -> V_1105 = 36 ;
break;
case V_620 :
V_1079 -> V_1105 = 48 ;
break;
case V_621 :
V_1079 -> V_1105 = 72 ;
break;
case V_622 :
V_1079 -> V_1105 = 96 ;
break;
case V_623 :
V_1079 -> V_1105 = 108 ;
break;
default:
V_1079 -> V_1105 = 0 ;
break;
}
V_1079 -> V_1106 = ( V_1074 & 3 ) ;
if ( ( V_1074 & 64 ) )
V_1079 -> V_1093 |= V_1107 ;
F_382 ( V_774 -> V_501 , V_4 + sizeof( struct V_1078 ) ) ;
F_383 ( L_387 , V_774 -> V_501 -> V_4 ) ;
if ( ! F_384 ( V_23 -> V_163 , V_774 -> V_501 , V_674 ) )
V_166 -> V_674 . V_1066 ++ ;
else {
V_774 -> V_501 = NULL ;
}
}
static void F_387 ( struct V_17 * V_23 ,
struct V_773 * V_774 ,
struct V_673 * V_674 )
{
struct V_165 * V_166 = V_23 -> V_157 ;
struct V_1061 * V_1062 = (struct V_1061 * ) V_774 -> V_501 -> V_3 ;
struct V_1072 * V_1064 = & V_1062 -> V_538 . V_1064 ;
struct V_1078 * V_1079 ;
struct V_1054 * V_1055 ;
T_4 V_197 = V_1064 -> V_1073 ;
T_2 V_1108 = V_1064 -> V_1074 ;
T_7 signal = V_1064 -> V_1076 - V_1046 ;
T_7 V_737 = ( T_7 ) F_221 ( V_1064 -> V_737 ) ;
T_2 V_609 = V_1064 -> V_609 ;
unsigned short V_4 = F_221 ( V_1062 -> V_538 . V_1064 . V_415 ) ;
struct V_1006 * V_501 ;
int V_1109 = 0 ;
T_4 V_161 = V_23 -> V_159 -> V_161 ;
if ( V_161 & V_1110 )
return;
V_166 -> V_1063 = V_140 ;
if ( F_29 ( ( V_4 + V_1065 ) > F_378 ( V_774 -> V_501 ) ) ) {
V_166 -> V_674 . V_1066 ++ ;
F_379 ( L_385 ) ;
return;
}
if ( F_29 ( ! F_92 ( V_166 ) ) ) {
V_166 -> V_674 . V_1070 ++ ;
F_379 ( L_386 ) ;
return;
}
if ( V_4 > V_503 - sizeof( struct V_1078 ) ) {
V_166 -> V_674 . V_1070 ++ ;
F_379 ( L_388 ) ;
return;
}
V_1055 = ( void * ) V_774 -> V_501 -> V_3 + V_1065 ;
if ( F_388 ( F_221 ( V_1055 -> V_1057 ) ) ) {
if ( V_161 & V_1111 )
return;
if ( V_161 & V_1112 )
V_1109 = 1 ;
} else if ( F_389 ( F_221 ( V_1055 -> V_1057 ) ) ) {
if ( V_161 & V_1113 )
return;
if ( V_161 & V_1114 )
V_1109 = 1 ;
} else if ( F_390 ( F_221 ( V_1055 -> V_1057 ) ) ) {
if ( V_161 & V_1115 )
return;
if ( V_161 & V_1116 )
V_1109 = 1 ;
}
V_501 = F_391 ( V_774 -> V_501 , V_139 ) ;
if ( V_501 == NULL ) {
F_46 ( L_389 ) ;
return;
}
V_1079 = ( void * ) V_501 -> V_3 ;
if ( V_1109 )
V_4 = F_392 ( F_221 ( V_1055 -> V_1057 ) ) ;
memcpy ( V_1079 -> V_142 , V_1055 , V_4 ) ;
V_1079 -> V_1080 . V_1081 = V_1082 ;
V_1079 -> V_1080 . V_1083 = 0 ;
V_1079 -> V_1080 . V_1084 = F_173 ( sizeof( * V_1079 ) ) ;
F_382 ( V_501 , sizeof( * V_1079 ) + V_4 ) ;
V_1079 -> V_1080 . V_1085 = F_179 (
( 1 << V_1086 ) |
( 1 << V_1087 ) |
( 1 << V_1088 ) |
( 1 << V_1089 ) |
( 1 << V_1090 ) |
( 1 << V_1091 ) |
( 1 << V_1092 ) ) ;
V_1079 -> V_1093 = 0 ;
V_1079 -> V_1094 = ( V_1095 ) ( V_1064 -> V_1096 [ 3 ] << 24 |
V_1064 -> V_1096 [ 2 ] << 16 |
V_1064 -> V_1096 [ 1 ] << 8 |
V_1064 -> V_1096 [ 0 ] ) ;
V_1079 -> V_1097 = signal ;
V_1079 -> V_1098 = V_737 ;
V_1079 -> V_1099 = F_173 ( F_386 ( V_197 ) ) ;
if ( V_197 > 14 ) {
V_1079 -> V_1100 =
F_173 ( ( V_1101 | V_1102 ) ) ;
} else if ( V_1108 & ( 1 << 5 ) ) {
V_1079 -> V_1100 =
F_173 ( ( V_1103 | V_1104 ) ) ;
} else {
V_1079 -> V_1100 =
F_173 ( V_1101 | V_1104 ) ;
}
switch ( V_609 ) {
case V_612 :
V_1079 -> V_1105 = 2 ;
break;
case V_613 :
V_1079 -> V_1105 = 4 ;
break;
case V_614 :
V_1079 -> V_1105 = 10 ;
break;
case V_615 :
V_1079 -> V_1105 = 12 ;
break;
case V_616 :
V_1079 -> V_1105 = 18 ;
break;
case V_617 :
V_1079 -> V_1105 = 22 ;
break;
case V_618 :
V_1079 -> V_1105 = 24 ;
break;
case V_619 :
V_1079 -> V_1105 = 36 ;
break;
case V_620 :
V_1079 -> V_1105 = 48 ;
break;
case V_621 :
V_1079 -> V_1105 = 72 ;
break;
case V_622 :
V_1079 -> V_1105 = 96 ;
break;
case V_623 :
V_1079 -> V_1105 = 108 ;
break;
default:
V_1079 -> V_1105 = 0 ;
break;
}
V_1079 -> V_1106 = ( V_1108 & 3 ) ;
if ( V_1108 & ( 1 << 6 ) )
V_1079 -> V_1093 |= V_1107 ;
F_383 ( L_387 , V_501 -> V_4 ) ;
if ( ! F_384 ( V_23 -> V_159 -> V_163 , V_501 , V_674 ) ) {
V_166 -> V_674 . V_1066 ++ ;
F_393 ( V_501 ) ;
}
}
static int F_394 ( struct V_17 * V_23 ,
struct V_675 * V_1117 )
{
switch ( V_23 -> V_163 -> V_513 ) {
case V_514 :
if ( ! memcmp ( V_1117 -> V_1118 , V_23 -> V_167 -> V_1119 , V_217 ) )
return 0 ;
if ( F_365 ( V_1117 -> V_1071 ) )
return ! memcmp ( V_1117 -> V_1120 , V_23 -> V_216 , V_217 ) ;
return ! memcmp ( V_1117 -> V_1071 , V_23 -> V_167 -> V_1119 ,
V_217 ) ;
case V_516 :
if ( ! memcmp ( V_1117 -> V_1120 , V_23 -> V_167 -> V_1119 , V_217 ) )
return 0 ;
if ( F_365 ( V_1117 -> V_1071 ) )
return ! memcmp ( V_1117 -> V_1118 , V_23 -> V_216 , V_217 ) ;
return ! memcmp ( V_1117 -> V_1071 , V_23 -> V_167 -> V_1119 ,
V_217 ) ;
}
return 1 ;
}
static int F_395 ( struct V_17 * V_23 ,
struct V_675 * V_1117 )
{
T_4 V_1121 = F_221 ( V_1117 -> V_1122 ) ;
T_4 V_1123 = F_396 ( V_1121 ) ;
T_4 V_359 = F_397 ( V_1121 ) ;
T_4 * V_1124 , * V_1125 ;
unsigned long * V_1126 ;
switch ( V_23 -> V_163 -> V_513 ) {
case V_514 :
{
struct V_437 * V_134 ;
struct V_1127 * V_545 = NULL ;
T_2 * V_314 = V_1117 -> V_1118 ;
int V_400 = V_314 [ 5 ] % V_1128 ;
F_398 (p, &priv->ibss_mac_hash[index]) {
V_545 =
F_212 ( V_134 , struct V_1127 , V_442 ) ;
if ( ! memcmp ( V_545 -> V_314 , V_314 , V_217 ) )
break;
}
if ( V_134 == & V_23 -> V_1129 [ V_400 ] ) {
V_545 = F_83 ( sizeof( * V_545 ) , V_139 ) ;
if ( ! V_545 ) {
F_46
( L_390 ) ;
return 0 ;
}
memcpy ( V_545 -> V_314 , V_314 , V_217 ) ;
V_545 -> V_839 = V_1123 ;
V_545 -> V_1130 = V_359 ;
V_545 -> V_1131 = V_140 ;
F_399 ( & V_545 -> V_442 ,
& V_23 -> V_1129 [ V_400 ] ) ;
return 0 ;
}
V_1124 = & V_545 -> V_839 ;
V_1125 = & V_545 -> V_1130 ;
V_1126 = & V_545 -> V_1131 ;
break;
}
case V_516 :
V_1124 = & V_23 -> V_1132 ;
V_1125 = & V_23 -> V_1133 ;
V_1126 = & V_23 -> V_1134 ;
break;
default:
return 0 ;
}
if ( ( * V_1124 == V_1123 ) &&
F_310 ( * V_1126 + V_1135 , V_140 ) ) {
if ( * V_1125 == V_359 )
goto V_1136;
if ( * V_1125 + 1 != V_359 )
goto V_1136;
} else
* V_1124 = V_1123 ;
* V_1125 = V_359 ;
* V_1126 = V_140 ;
return 0 ;
V_1136:
return 1 ;
}
static void F_400 ( struct V_17 * V_23 ,
struct V_773 * V_774 ,
struct V_673 * V_674 )
{
struct V_1006 * V_501 = V_774 -> V_501 ;
struct V_1061 * V_1062 = (struct V_1061 * ) V_501 -> V_3 ;
struct V_675 * V_1117 = (struct V_675 * )
( V_501 -> V_3 + V_1065 ) ;
F_295 ( V_23 -> V_163 , V_1117 , V_674 ) ;
if ( V_23 -> V_163 -> V_513 == V_514 &&
( ( F_401 ( F_221 ( V_1117 -> V_1137 ) ) ==
V_1138 ) ||
( F_401 ( F_221 ( V_1117 -> V_1137 ) ) ==
V_1139 ) ) ) {
if ( ! memcmp ( V_1117 -> V_1120 , V_23 -> V_216 , V_217 ) )
F_261 ( V_23 , V_1117 -> V_1118 ) ;
}
if ( V_23 -> V_59 & V_200 ) {
F_142 ( L_391 ) ;
F_382 ( V_501 , F_221 ( V_1062 -> V_538 . V_1064 . V_415 ) +
V_1065 ) ;
F_402 ( V_501 , V_1065 ) ;
memcpy ( F_403 ( V_501 , sizeof( * V_674 ) ) , V_674 , sizeof( * V_674 ) ) ;
V_501 -> V_166 = V_23 -> V_163 -> V_166 ;
F_404 ( V_501 ) ;
V_501 -> V_1140 = V_1141 ;
V_501 -> V_1142 = F_405 ( V_1143 ) ;
memset ( V_501 -> V_401 , 0 , sizeof( V_774 -> V_501 -> V_401 ) ) ;
F_406 ( V_501 ) ;
V_774 -> V_501 = NULL ;
}
}
static void F_141 ( struct V_17 * V_23 )
{
struct V_773 * V_774 ;
struct V_1061 * V_1062 ;
struct V_675 * V_1117 ;
T_3 V_381 , V_1144 , V_7 ;
T_2 V_1145 ;
T_2 V_1146 = 0 ;
V_381 = F_36 ( V_23 , V_520 ) ;
V_1144 = F_36 ( V_23 , V_781 ) ;
V_7 = V_23 -> V_496 -> V_505 ;
if ( F_250 ( V_23 -> V_496 ) > ( V_500 / 2 ) )
V_1146 = 1 ;
while ( V_7 != V_381 ) {
V_774 = V_23 -> V_496 -> V_778 [ V_7 ] ;
if ( F_29 ( V_774 == NULL ) ) {
F_4 ( V_782 L_392 ) ;
break;
}
V_23 -> V_496 -> V_778 [ V_7 ] = NULL ;
F_407 ( V_23 -> V_477 , V_774 -> V_502 ,
V_503 ,
V_504 ) ;
V_1062 = (struct V_1061 * ) V_774 -> V_501 -> V_3 ;
F_383 ( L_393 ,
V_1062 -> V_1117 . V_536 ,
V_1062 -> V_1117 . V_1147 , V_1062 -> V_1117 . V_770 ) ;
switch ( V_1062 -> V_1117 . V_536 ) {
case V_1148 : {
struct V_673 V_674 = {
. V_632 = V_1062 -> V_538 . V_1064 . V_1076 -
V_1046 ,
. signal =
V_1062 -> V_538 . V_1064 . V_1076 -
V_1046 + 0x100 ,
. V_737 =
F_221 ( V_1062 -> V_538 . V_1064 . V_737 ) ,
. V_609 = V_1062 -> V_538 . V_1064 . V_609 ,
. V_1149 = V_140 ,
. V_1073 =
V_1062 -> V_538 . V_1064 . V_1073 ,
. V_1150 =
( V_1062 -> V_538 . V_1064 .
V_394 & ( 1 << 0 ) ) ?
V_821 :
V_820 ,
. V_4 = F_221 ( V_1062 -> V_538 . V_1064 . V_415 ) ,
} ;
if ( V_674 . V_632 != 0 )
V_674 . V_36 |= V_1151 ;
if ( V_674 . signal != 0 )
V_674 . V_36 |= V_1152 ;
if ( V_674 . V_737 != 0 )
V_674 . V_36 |= V_1153 ;
if ( V_674 . V_609 != 0 )
V_674 . V_36 |= V_1154 ;
V_23 -> V_593 ++ ;
#ifdef F_269
if ( V_23 -> V_157 && F_92 ( V_23 -> V_157 ) )
F_387 ( V_23 , V_774 , & V_674 ) ;
#endif
#ifdef F_244
if ( V_23 -> V_163 -> V_513 == V_515 ) {
#ifdef F_408
F_385 ( V_23 ,
V_774 ,
& V_674 ) ;
#else
F_377 ( V_23 , V_774 ,
& V_674 ) ;
#endif
break;
}
#endif
V_1117 =
(struct V_675 * ) ( V_774 -> V_501 ->
V_3 +
V_1065 ) ;
V_1145 =
F_394 ( V_23 , V_1117 ) ;
if ( V_1145 && V_23 -> V_117 ) {
V_23 -> V_117 -> V_674 . V_632 =
V_674 . V_632 ;
V_23 -> V_581 =
F_272 ( V_23 -> V_581 ,
V_674 . V_632 , V_1155 ) ;
}
F_383 ( L_394 ,
F_221 ( V_1062 -> V_538 . V_1064 . V_415 ) ) ;
if ( F_221 ( V_1062 -> V_538 . V_1064 . V_415 ) <
F_392 ( F_221 (
V_1117 -> V_1137 ) ) ) {
F_379
( L_395
L_396 ) ;
V_23 -> V_167 -> V_674 . V_1066 ++ ;
V_23 -> V_1067 . V_1068 . V_1069 ++ ;
break;
}
switch ( F_409
( F_221 ( V_1117 -> V_1137 ) ) ) {
case V_1156 :
F_400 ( V_23 , V_774 ,
& V_674 ) ;
break;
case V_1157 :
break;
case V_1158 :
if ( F_29 ( ! V_1145 ||
F_395 ( V_23 ,
V_1117 ) ) )
{
F_379 ( L_397
L_398
L_398
L_399 ,
V_1117 -> V_1071 ,
V_1117 -> V_1118 ,
V_1117 -> V_1120 ) ;
break;
}
F_377 ( V_23 , V_774 ,
& V_674 ) ;
break;
}
break;
}
case V_1159 : {
F_383
( L_400 ,
V_1062 -> V_538 . V_1160 . V_661 ,
V_1062 -> V_538 . V_1160 . V_41 ,
F_221 ( V_1062 -> V_538 . V_1160 . V_15 ) ) ;
F_289 ( V_23 , & V_1062 -> V_538 . V_1160 ) ;
break;
}
default:
F_383 ( L_401 ,
V_1062 -> V_1117 . V_536 ) ;
break;
}
if ( V_774 -> V_501 != NULL ) {
F_393 ( V_774 -> V_501 ) ;
V_774 -> V_501 = NULL ;
}
F_238 ( V_23 -> V_477 , V_774 -> V_502 ,
V_503 , V_504 ) ;
F_214 ( & V_774 -> V_442 , & V_23 -> V_496 -> V_498 ) ;
V_7 = ( V_7 + 1 ) % V_500 ;
if ( V_1146 ) {
V_23 -> V_496 -> V_505 = V_7 ;
F_247 ( V_23 ) ;
}
}
V_23 -> V_496 -> V_505 = V_7 ;
F_297 ( V_23 ) ;
}
static int F_410 ( struct V_17 * V_23 , int V_1161 )
{
int V_882 , V_804 ;
int V_1162 = V_23 -> V_163 -> V_513 ;
V_23 -> V_59 = 0 ;
if ( ! V_1163 )
V_23 -> V_59 |= V_95 ;
if ( V_333 )
V_23 -> V_59 |= V_1048 ;
else
F_74 ( L_402 ) ;
if ( V_1164 )
V_23 -> V_59 |= V_1049 ;
else
F_74 ( L_403 ) ;
V_23 -> V_59 &= ~ V_811 ;
V_23 -> V_668 = 0 ;
memset ( V_23 -> V_667 , 0 , V_313 ) ;
if ( V_1165 && V_1161 ) {
V_23 -> V_37 |= V_184 ;
F_74 ( L_404 ) ;
}
if ( V_1166 != 0 ) {
V_23 -> V_59 |= V_549 ;
V_23 -> V_197 = V_1166 ;
F_74 ( L_405 , V_1166 ) ;
}
#ifdef F_292
F_362 ( V_23 , V_979 , V_1167 ,
V_998 , V_999 ) ;
#endif
switch ( V_1168 ) {
case 1 :
V_23 -> V_163 -> V_513 = V_514 ;
V_23 -> V_167 -> type = V_214 ;
break;
#ifdef F_244
case 2 :
V_23 -> V_163 -> V_513 = V_515 ;
#ifdef F_408
V_23 -> V_167 -> type = V_1169 ;
#else
V_23 -> V_167 -> type = V_1170 ;
#endif
break;
#endif
default:
case 0 :
V_23 -> V_167 -> type = V_214 ;
V_23 -> V_163 -> V_513 = V_516 ;
break;
}
if ( V_942 ) {
V_23 -> V_163 -> V_843 = 0 ;
V_23 -> V_163 -> V_947 = 0 ;
V_23 -> V_163 -> V_846 = 0 ;
V_23 -> V_163 -> V_854 = 0 ;
}
F_74 ( L_406 , V_942 ? L_299 : L_300 ) ;
V_23 -> V_163 -> V_1171 = 0 ;
if ( ( V_23 -> V_477 -> V_143 == 0x4223 ) ||
( V_23 -> V_477 -> V_143 == 0x4224 ) ) {
if ( V_1161 == 1 )
F_4 (KERN_INFO DRV_NAME
L_407
L_408 ) ;
V_23 -> V_163 -> V_353 = 1 ;
V_882 = V_820 | V_821 ;
V_804 = V_807 |
V_1172 ;
V_23 -> V_316 = V_1173 ;
V_23 -> V_163 -> V_118 = V_119 | V_121 | V_608 ;
} else {
if ( V_1161 == 1 )
F_4 (KERN_INFO DRV_NAME
L_409
L_408 ) ;
V_23 -> V_163 -> V_353 = 0 ;
V_882 = V_821 ;
V_804 = V_807 |
V_1172 ;
V_23 -> V_316 = V_1174 ;
V_23 -> V_163 -> V_118 = V_121 | V_608 ;
}
V_23 -> V_163 -> V_861 = V_882 ;
V_23 -> V_163 -> V_804 = V_804 ;
V_23 -> V_594 = V_1175 ;
V_23 -> V_647 = V_1176 ;
V_23 -> V_655 = V_1177 ;
V_23 -> V_357 = V_1178 ;
V_23 -> V_372 = V_1179 ;
V_23 -> V_373 = V_1180 ;
V_23 -> V_1181 = V_365 ;
V_23 -> V_345 = V_1182 ;
return V_1162 == V_23 -> V_163 -> V_513 ;
}
static int F_411 ( struct V_17 * V_23 , T_2 V_197 )
{
if ( V_197 == 0 ) {
F_74 ( L_410 ) ;
V_23 -> V_59 &= ~ V_549 ;
F_264 ( L_411
L_412 ) ;
V_332 ( V_23 ) ;
return 0 ;
}
V_23 -> V_59 |= V_549 ;
if ( V_23 -> V_197 == V_197 ) {
F_74 ( L_413 ,
V_197 ) ;
return 0 ;
}
F_74 ( L_414 , ( int ) V_197 ) ;
V_23 -> V_197 = V_197 ;
#ifdef F_244
if ( V_23 -> V_163 -> V_513 == V_515 ) {
int V_7 ;
if ( V_23 -> V_37 & V_321 ) {
F_166 ( L_415
L_416 ) ;
F_168 ( V_23 ) ;
}
for ( V_7 = 1000 ; V_7 && ( V_23 -> V_37 & V_321 ) ; V_7 -- )
F_187 ( 10 ) ;
if ( V_23 -> V_37 & V_321 )
F_166 ( L_417 ) ;
else
F_166 ( L_418 ,
1000 - V_7 ) ;
return 0 ;
}
#endif
F_264 ( L_419 ) ;
if ( ! F_265 ( V_23 ) )
V_332 ( V_23 ) ;
return 0 ;
}
static int F_412 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
const struct V_201 * V_202 = F_137 ( V_23 -> V_163 ) ;
struct V_1183 * V_1184 = & V_211 -> V_1150 ;
int V_432 = 0 , V_7 ;
T_2 V_197 , V_41 ;
int V_882 ;
if ( V_1184 -> V_1185 == 0 ) {
F_326 ( L_420 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_432 = F_411 ( V_23 , 0 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_432 ;
}
if ( V_1184 -> V_1186 == 1 ) {
V_197 = F_413 ( V_23 -> V_163 , V_1184 -> V_1185 ) ;
if ( V_197 == 0 )
return - V_75 ;
} else
V_197 = V_1184 -> V_1185 ;
if ( ! ( V_882 = F_133 ( V_23 -> V_163 , V_197 ) ) )
return - V_75 ;
if ( V_23 -> V_163 -> V_513 == V_514 ) {
V_7 = F_316 ( V_23 -> V_163 , V_197 ) ;
if ( V_7 == - 1 )
return - V_75 ;
V_41 = ( V_882 == V_821 ) ?
V_202 -> V_204 [ V_7 ] . V_41 : V_202 -> V_18 [ V_7 ] . V_41 ;
if ( V_41 & V_207 ) {
F_326 ( L_421 ) ;
return - V_75 ;
}
}
F_326 ( L_422 , V_1184 -> V_1185 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_432 = F_411 ( V_23 , V_197 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_432 ;
}
static int F_414 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
V_211 -> V_1150 . V_1186 = 0 ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_59 & V_549 ||
V_23 -> V_37 & ( V_240 | V_103 ) ) {
int V_7 ;
V_7 = F_316 ( V_23 -> V_163 , V_23 -> V_197 ) ;
F_225 ( V_7 == - 1 ) ;
V_211 -> V_1150 . V_1186 = 1 ;
switch ( F_133 ( V_23 -> V_163 , V_23 -> V_197 ) ) {
case V_820 :
V_211 -> V_1150 . V_1185 = V_23 -> V_163 -> V_202 . V_18 [ V_7 ] . V_1150 * 100000 ;
break;
case V_821 :
V_211 -> V_1150 . V_1185 = V_23 -> V_163 -> V_202 . V_204 [ V_7 ] . V_1150 * 100000 ;
break;
default:
F_360 () ;
}
} else
V_211 -> V_1150 . V_1185 = 0 ;
F_60 ( & V_23 -> V_109 ) ;
F_326 ( L_423 , V_23 -> V_197 ) ;
return 0 ;
}
static int F_415 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
int V_557 = 0 ;
F_326 ( L_424 , V_211 -> V_118 ) ;
switch ( V_211 -> V_118 ) {
#ifdef F_244
case V_515 :
#endif
case V_514 :
case V_516 :
break;
case V_1187 :
V_211 -> V_118 = V_516 ;
break;
default:
return - V_75 ;
}
if ( V_211 -> V_118 == V_23 -> V_163 -> V_513 )
return 0 ;
F_59 ( & V_23 -> V_109 ) ;
F_410 ( V_23 , 0 ) ;
#ifdef F_244
if ( V_23 -> V_163 -> V_513 == V_515 )
V_23 -> V_167 -> type = V_214 ;
if ( V_211 -> V_118 == V_515 )
#ifdef F_408
V_23 -> V_167 -> type = V_1169 ;
#else
V_23 -> V_167 -> type = V_1170 ;
#endif
#endif
F_240 () ;
V_23 -> V_163 -> V_513 = V_211 -> V_118 ;
F_128 ( & V_23 -> V_246 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_557 ;
}
static int F_416 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_118 = V_23 -> V_163 -> V_513 ;
F_326 ( L_425 , V_211 -> V_118 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_417 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
struct V_1188 * V_1189 = (struct V_1188 * ) V_904 ;
const struct V_201 * V_202 = F_137 ( V_23 -> V_163 ) ;
int V_7 = 0 , V_8 ;
V_211 -> V_3 . V_415 = sizeof( * V_1189 ) ;
memset ( V_1189 , 0 , sizeof( * V_1189 ) ) ;
V_1189 -> V_1190 = 27 * 1000 * 1000 ;
V_1189 -> V_1191 . V_1192 = 100 ;
V_1189 -> V_1191 . V_11 = 0 ;
V_1189 -> V_1191 . V_737 = 0 ;
V_1189 -> V_1191 . V_1193 = 7 ;
V_1189 -> V_1194 . V_1192 = 70 ;
V_1189 -> V_1194 . V_11 = 0 ;
V_1189 -> V_1194 . V_737 = 0 ;
V_1189 -> V_1194 . V_1193 = 7 ;
F_59 ( & V_23 -> V_109 ) ;
V_1189 -> V_1195 = F_3 ( V_23 -> V_336 . V_796 , ( T_2 ) V_1196 ) ;
for ( V_7 = 0 ; V_7 < V_1189 -> V_1195 ; V_7 ++ )
V_1189 -> V_1197 [ V_7 ] = ( V_23 -> V_336 . V_799 [ V_7 ] & 0x7F ) *
500000 ;
V_1189 -> V_1198 = V_1178 ;
V_1189 -> V_1199 = V_1200 ;
V_1189 -> V_1201 = V_1202 ;
V_1189 -> V_1203 [ 0 ] = 5 ;
V_1189 -> V_1203 [ 1 ] = 13 ;
V_1189 -> V_1204 = 2 ;
V_1189 -> V_1205 = V_1206 ;
V_1189 -> V_1207 = V_1208 ;
V_1189 -> V_1209 = 18 ;
V_7 = 0 ;
if ( V_23 -> V_163 -> V_118 & ( V_608 | V_121 ) ) {
for ( V_8 = 0 ; V_8 < V_202 -> V_203 && V_7 < V_1210 ; V_8 ++ ) {
if ( ( V_23 -> V_163 -> V_513 == V_514 ) &&
( V_202 -> V_204 [ V_8 ] . V_41 & V_207 ) )
continue;
V_1189 -> V_1150 [ V_7 ] . V_7 = V_202 -> V_204 [ V_8 ] . V_197 ;
V_1189 -> V_1150 [ V_7 ] . V_1185 = V_202 -> V_204 [ V_8 ] . V_1150 * 100000 ;
V_1189 -> V_1150 [ V_7 ] . V_1186 = 1 ;
V_7 ++ ;
}
}
if ( V_23 -> V_163 -> V_118 & V_119 ) {
for ( V_8 = 0 ; V_8 < V_202 -> V_209 && V_7 < V_1210 ; V_8 ++ ) {
if ( ( V_23 -> V_163 -> V_513 == V_514 ) &&
( V_202 -> V_18 [ V_8 ] . V_41 & V_207 ) )
continue;
V_1189 -> V_1150 [ V_7 ] . V_7 = V_202 -> V_18 [ V_8 ] . V_197 ;
V_1189 -> V_1150 [ V_7 ] . V_1185 = V_202 -> V_18 [ V_8 ] . V_1150 * 100000 ;
V_1189 -> V_1150 [ V_7 ] . V_1186 = 1 ;
V_7 ++ ;
}
}
V_1189 -> V_349 = V_7 ;
V_1189 -> V_1211 = V_7 ;
F_60 ( & V_23 -> V_109 ) ;
V_1189 -> V_1212 [ 0 ] = ( V_1213 |
F_418 ( V_1214 ) |
F_418 ( V_218 ) |
F_418 ( V_657 ) ) ;
V_1189 -> V_1212 [ 1 ] = V_1215 ;
V_1189 -> V_1216 = V_1217 | V_1218 |
V_1219 | V_1220 ;
V_1189 -> V_1221 = V_1222 | V_1223 ;
F_326 ( L_426 ) ;
return 0 ;
}
static int F_419 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
if ( V_211 -> V_212 . V_213 != V_214 )
return - V_75 ;
F_59 ( & V_23 -> V_109 ) ;
if ( F_420 ( V_211 -> V_212 . V_215 ) ||
F_421 ( V_211 -> V_212 . V_215 ) ) {
F_326 ( L_427 ) ;
V_23 -> V_59 &= ~ V_819 ;
F_264 ( L_411
L_412 ) ;
V_332 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
V_23 -> V_59 |= V_819 ;
if ( ! memcmp ( V_23 -> V_216 , V_211 -> V_212 . V_215 , V_217 ) ) {
F_326 ( L_428 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
F_326 ( L_429 ,
V_211 -> V_212 . V_215 ) ;
memcpy ( V_23 -> V_216 , V_211 -> V_212 . V_215 , V_217 ) ;
F_264 ( L_430 ) ;
if ( ! F_265 ( V_23 ) )
V_332 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_422 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_59 & V_819 ||
V_23 -> V_37 & ( V_103 | V_240 ) ) {
V_211 -> V_212 . V_213 = V_214 ;
memcpy ( V_211 -> V_212 . V_215 , V_23 -> V_216 , V_217 ) ;
} else
memset ( V_211 -> V_212 . V_215 , 0 , V_217 ) ;
F_326 ( L_431 ,
V_211 -> V_212 . V_215 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_423 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
int V_415 ;
F_290 ( V_311 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( ! V_211 -> V_667 . V_41 )
{
F_326 ( L_432 ) ;
F_265 ( V_23 ) ;
V_23 -> V_59 &= ~ V_811 ;
V_332 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
V_415 = F_3 ( ( int ) V_211 -> V_667 . V_415 , V_313 ) ;
V_23 -> V_59 |= V_811 ;
if ( V_23 -> V_668 == V_415 && ! memcmp ( V_23 -> V_667 , V_904 , V_415 )
&& ( V_23 -> V_37 & ( V_103 | V_240 ) ) ) {
F_326 ( L_433 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
F_326 ( L_434 ,
F_291 ( V_311 , V_904 , V_415 ) , V_415 ) ;
V_23 -> V_668 = V_415 ;
memcpy ( V_23 -> V_667 , V_904 , V_23 -> V_668 ) ;
F_264 ( L_435 ) ;
if ( ! F_265 ( V_23 ) )
V_332 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_424 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_290 ( V_311 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_59 & V_811 ||
V_23 -> V_37 & ( V_103 | V_240 ) ) {
F_326 ( L_436 ,
F_291 ( V_311 , V_23 -> V_667 , V_23 -> V_668 ) ) ;
memcpy ( V_904 , V_23 -> V_667 , V_23 -> V_668 ) ;
V_211 -> V_667 . V_415 = V_23 -> V_668 ;
V_211 -> V_667 . V_41 = 1 ;
} else {
F_326 ( L_437 ) ;
V_211 -> V_667 . V_415 = 0 ;
V_211 -> V_667 . V_41 = 0 ;
}
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_425 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_326 ( L_438 , V_904 ) ;
if ( V_211 -> V_3 . V_415 > V_313 )
return - V_906 ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_3 . V_415 = F_3 ( ( T_1 ) V_211 -> V_3 . V_415 , sizeof( V_23 -> V_1224 ) ) ;
memset ( V_23 -> V_1224 , 0 , sizeof( V_23 -> V_1224 ) ) ;
memcpy ( V_23 -> V_1224 , V_904 , V_211 -> V_3 . V_415 ) ;
F_195 ( L_151 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_426 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_326 ( L_439 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_3 . V_415 = strlen ( V_23 -> V_1224 ) ;
memcpy ( V_904 , V_23 -> V_1224 , V_211 -> V_3 . V_415 ) ;
V_211 -> V_3 . V_41 = 1 ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_427 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
int V_557 = 0 ;
F_326 ( L_440 , V_211 -> V_327 . V_25 ) ;
F_326 ( L_441 , 3 * V_211 -> V_327 . V_25 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_211 -> V_327 . V_1225 == 0 )
{
V_23 -> V_655 = V_1177 ;
V_23 -> V_647 = V_1176 ;
goto V_6;
}
if ( ( V_211 -> V_327 . V_25 > V_1226 ) ||
( V_211 -> V_327 . V_25 < V_1227 ) ) {
V_557 = - V_75 ;
goto V_6;
}
V_23 -> V_655 = V_211 -> V_327 . V_25 ;
V_23 -> V_647 = 3 * V_211 -> V_327 . V_25 ;
V_6:
F_60 ( & V_23 -> V_109 ) ;
return V_557 ;
}
static int F_428 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_327 . V_1225 = 1 ;
V_211 -> V_327 . V_25 = V_23 -> V_655 ;
F_60 ( & V_23 -> V_109 ) ;
F_326 ( L_442 ,
V_211 -> V_343 . V_1228 ? L_96 : L_97 , V_211 -> V_343 . V_25 ) ;
return 0 ;
}
static int F_429 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
T_3 V_1229 = V_211 -> V_1197 . V_25 ;
T_3 V_1225 , V_36 ;
if ( V_1229 == - 1 ) {
V_1225 = 0 ;
V_36 = V_1175 ;
goto V_1230;
}
V_36 = 0 ;
V_1225 = V_211 -> V_1197 . V_1225 ;
if ( V_1229 == 1000000 || ! V_1225 )
V_36 |= V_596 ;
if ( V_1229 == 1000000 )
goto V_1230;
if ( V_1229 == 2000000 || ! V_1225 )
V_36 |= V_597 ;
if ( V_1229 == 2000000 )
goto V_1230;
if ( V_1229 == 5500000 || ! V_1225 )
V_36 |= V_598 ;
if ( V_1229 == 5500000 )
goto V_1230;
if ( V_1229 == 6000000 || ! V_1225 )
V_36 |= V_599 ;
if ( V_1229 == 6000000 )
goto V_1230;
if ( V_1229 == 9000000 || ! V_1225 )
V_36 |= V_600 ;
if ( V_1229 == 9000000 )
goto V_1230;
if ( V_1229 == 11000000 || ! V_1225 )
V_36 |= V_601 ;
if ( V_1229 == 11000000 )
goto V_1230;
if ( V_1229 == 12000000 || ! V_1225 )
V_36 |= V_602 ;
if ( V_1229 == 12000000 )
goto V_1230;
if ( V_1229 == 18000000 || ! V_1225 )
V_36 |= V_603 ;
if ( V_1229 == 18000000 )
goto V_1230;
if ( V_1229 == 24000000 || ! V_1225 )
V_36 |= V_604 ;
if ( V_1229 == 24000000 )
goto V_1230;
if ( V_1229 == 36000000 || ! V_1225 )
V_36 |= V_605 ;
if ( V_1229 == 36000000 )
goto V_1230;
if ( V_1229 == 48000000 || ! V_1225 )
V_36 |= V_606 ;
if ( V_1229 == 48000000 )
goto V_1230;
if ( V_1229 == 54000000 || ! V_1225 )
V_36 |= V_607 ;
if ( V_1229 == 54000000 )
goto V_1230;
F_326 ( L_443 ) ;
return - V_75 ;
V_1230:
F_326 ( L_444 ,
V_36 , V_1225 ? L_445 : L_446 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_36 == V_1175 ) {
V_23 -> V_59 &= ~ V_1025 ;
F_325 ( V_23 , V_23 -> V_163 -> V_118 ) ;
} else
V_23 -> V_59 |= V_1025 ;
if ( V_23 -> V_594 == V_36 ) {
F_326 ( L_447 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
V_23 -> V_594 = V_36 ;
F_264 ( L_448 ) ;
if ( ! F_265 ( V_23 ) )
V_332 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_430 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_1197 . V_25 = V_23 -> V_583 ;
V_211 -> V_1197 . V_1225 = ( V_23 -> V_59 & V_1025 ) ? 1 : 0 ;
F_60 ( & V_23 -> V_109 ) ;
F_326 ( L_449 , V_211 -> V_1197 . V_25 ) ;
return 0 ;
}
static int F_431 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_211 -> V_355 . V_1228 || ! V_211 -> V_355 . V_1225 )
V_23 -> V_357 = V_1178 ;
else {
if ( V_211 -> V_355 . V_25 < V_1231 ||
V_211 -> V_355 . V_25 > V_1232 ) {
F_60 ( & V_23 -> V_109 ) ;
return - V_75 ;
}
V_23 -> V_357 = V_211 -> V_355 . V_25 ;
}
F_182 ( V_23 , V_23 -> V_357 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_326 ( L_450 , V_23 -> V_357 ) ;
return 0 ;
}
static int F_432 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_355 . V_25 = V_23 -> V_357 ;
V_211 -> V_355 . V_1225 = 0 ;
V_211 -> V_355 . V_1228 = ( V_211 -> V_355 . V_25 == V_1178 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_326 ( L_451 , V_211 -> V_355 . V_25 ) ;
return 0 ;
}
static int F_433 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
int V_557 = 0 ;
F_59 ( & V_23 -> V_109 ) ;
if ( F_126 ( V_23 , V_211 -> V_343 . V_1228 ) ) {
V_557 = - V_1233 ;
goto V_6;
}
if ( ! V_211 -> V_343 . V_1225 )
V_211 -> V_343 . V_25 = V_1182 ;
if ( V_211 -> V_343 . V_41 != V_1234 ) {
V_557 = - V_75 ;
goto V_6;
}
if ( ( V_211 -> V_343 . V_25 > V_1235 ) ||
( V_211 -> V_343 . V_25 < V_1236 ) ) {
V_557 = - V_75 ;
goto V_6;
}
V_23 -> V_345 = V_211 -> V_343 . V_25 ;
V_557 = F_181 ( V_23 ) ;
V_6:
F_60 ( & V_23 -> V_109 ) ;
return V_557 ;
}
static int F_434 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_343 . V_25 = V_23 -> V_345 ;
V_211 -> V_343 . V_1225 = 1 ;
V_211 -> V_343 . V_41 = V_1234 ;
V_211 -> V_343 . V_1228 = ( V_23 -> V_37 & V_99 ) ? 1 : 0 ;
F_60 ( & V_23 -> V_109 ) ;
F_326 ( L_452 ,
V_211 -> V_343 . V_1228 ? L_96 : L_97 , V_211 -> V_343 . V_25 ) ;
return 0 ;
}
static int F_435 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_211 -> V_359 . V_1228 || ! V_211 -> V_359 . V_1225 )
V_23 -> V_163 -> V_1237 = V_1238 ;
else {
if ( V_211 -> V_359 . V_25 < V_1200 ||
V_211 -> V_359 . V_25 > V_1202 ) {
F_60 ( & V_23 -> V_109 ) ;
return - V_75 ;
}
V_23 -> V_163 -> V_1237 = V_211 -> V_359 . V_25 & ~ 0x1 ;
}
F_183 ( V_23 , V_211 -> V_359 . V_25 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_326 ( L_453 , V_211 -> V_359 . V_25 ) ;
return 0 ;
}
static int F_436 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_359 . V_25 = V_23 -> V_163 -> V_1237 ;
V_211 -> V_359 . V_1225 = 0 ;
V_211 -> V_359 . V_1228 = ( V_211 -> V_359 . V_25 == V_1238 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_326 ( L_454 , V_211 -> V_359 . V_25 ) ;
return 0 ;
}
static int F_437 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
if ( V_211 -> V_517 . V_41 & V_1239 || V_211 -> V_517 . V_1228 )
return - V_75 ;
if ( ! ( V_211 -> V_517 . V_41 & V_1240 ) )
return 0 ;
if ( V_211 -> V_517 . V_25 < 0 || V_211 -> V_517 . V_25 >= 255 )
return - V_75 ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_211 -> V_517 . V_41 & V_1241 )
V_23 -> V_372 = ( T_2 ) V_211 -> V_517 . V_25 ;
else if ( V_211 -> V_517 . V_41 & V_1242 )
V_23 -> V_373 = ( T_2 ) V_211 -> V_517 . V_25 ;
else {
V_23 -> V_372 = ( T_2 ) V_211 -> V_517 . V_25 ;
V_23 -> V_373 = ( T_2 ) V_211 -> V_517 . V_25 ;
}
F_185 ( V_23 , V_23 -> V_372 ,
V_23 -> V_373 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_326 ( L_455 ,
V_23 -> V_372 , V_23 -> V_373 ) ;
return 0 ;
}
static int F_438 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_211 -> V_517 . V_1228 = 0 ;
if ( ( V_211 -> V_517 . V_41 & V_1243 ) == V_1239 ) {
F_60 ( & V_23 -> V_109 ) ;
return - V_75 ;
}
if ( V_211 -> V_517 . V_41 & V_1242 ) {
V_211 -> V_517 . V_41 = V_1240 | V_1242 ;
V_211 -> V_517 . V_25 = V_23 -> V_373 ;
} else if ( V_211 -> V_517 . V_41 & V_1241 ) {
V_211 -> V_517 . V_41 = V_1240 | V_1241 ;
V_211 -> V_517 . V_25 = V_23 -> V_372 ;
} else {
V_211 -> V_517 . V_41 = V_1240 ;
V_211 -> V_517 . V_25 = V_23 -> V_372 ;
}
F_60 ( & V_23 -> V_109 ) ;
F_326 ( L_456 , V_211 -> V_517 . V_25 ) ;
return 0 ;
}
static int F_439 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
struct V_1244 * V_1245 = (struct V_1244 * ) V_904 ;
struct V_1246 * V_107 = NULL ;
F_59 ( & V_23 -> V_109 ) ;
V_23 -> V_658 = 1 ;
if ( V_211 -> V_3 . V_415 == sizeof( struct V_1244 ) ) {
if ( V_211 -> V_3 . V_41 & V_1247 ) {
int V_4 = F_3 ( ( int ) V_1245 -> V_668 ,
( int ) sizeof( V_23 -> V_883 ) ) ;
memcpy ( V_23 -> V_883 , V_1245 -> V_667 , V_4 ) ;
V_23 -> V_874 = V_4 ;
V_107 = & V_23 -> V_187 ;
} else if ( V_1245 -> V_700 == V_876 ) {
V_107 = & V_23 -> V_188 ;
}
} else {
V_107 = & V_23 -> V_186 ;
}
F_60 ( & V_23 -> V_109 ) ;
F_326 ( L_457 ) ;
F_56 ( V_107 , 0 ) ;
return 0 ;
}
static int F_440 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
return F_441 ( V_23 -> V_163 , V_903 , V_211 , V_904 ) ;
}
static int F_442 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_830 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
int V_432 ;
T_3 V_1248 = V_23 -> V_317 ;
F_59 ( & V_23 -> V_109 ) ;
V_432 = F_443 ( V_23 -> V_163 , V_903 , V_211 , V_830 ) ;
if ( V_1248 != V_23 -> V_317 &&
V_23 -> V_163 -> V_513 == V_514 &&
V_23 -> V_37 & V_103 )
F_265 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_432 ;
}
static int F_444 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_830 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
return F_445 ( V_23 -> V_163 , V_903 , V_211 , V_830 ) ;
}
static int F_446 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
int V_557 ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_211 -> V_343 . V_1228 ) {
V_23 -> V_1181 = F_447 ( V_23 -> V_1181 ) ;
V_557 = F_184 ( V_23 , V_366 ) ;
if ( V_557 ) {
F_326 ( L_458 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_557 ;
}
F_326 ( L_459 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
switch ( V_211 -> V_343 . V_41 & V_1249 ) {
case V_1250 :
case V_1249 :
case V_1251 :
break;
default:
F_326 ( L_460 ,
V_211 -> V_343 . V_41 ) ;
F_60 ( & V_23 -> V_109 ) ;
return - V_898 ;
}
if ( F_447 ( V_23 -> V_1181 ) == V_365 )
V_23 -> V_1181 = V_1252 | V_363 ;
else
V_23 -> V_1181 = V_1252 | V_23 -> V_1181 ;
V_557 = F_184 ( V_23 , F_447 ( V_23 -> V_1181 ) ) ;
if ( V_557 ) {
F_326 ( L_458 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_557 ;
}
F_326 ( L_461 , V_23 -> V_1181 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_448 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( ! ( V_23 -> V_1181 & V_1252 ) )
V_211 -> V_343 . V_1228 = 1 ;
else
V_211 -> V_343 . V_1228 = 0 ;
F_60 ( & V_23 -> V_109 ) ;
F_326 ( L_462 , V_23 -> V_1181 ) ;
return 0 ;
}
static int F_449 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
int V_118 = * ( int * ) V_904 ;
int V_557 ;
F_59 ( & V_23 -> V_109 ) ;
if ( ( V_118 < 1 ) || ( V_118 > V_1253 ) )
V_118 = V_365 ;
if ( F_447 ( V_23 -> V_1181 ) != V_118 ) {
V_557 = F_184 ( V_23 , V_118 ) ;
if ( V_557 ) {
F_326 ( L_458 ) ;
F_60 ( & V_23 -> V_109 ) ;
return V_557 ;
}
V_23 -> V_1181 = V_1252 | V_118 ;
}
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_450 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
int V_11 = F_447 ( V_23 -> V_1181 ) ;
char * V_134 = V_904 ;
V_134 += snprintf ( V_134 , V_1254 , L_463 , V_11 ) ;
switch ( V_11 ) {
case V_365 :
V_134 += snprintf ( V_134 , V_1254 - ( V_134 - V_904 ) , L_464 ) ;
break;
case V_363 :
V_134 += snprintf ( V_134 , V_1254 - ( V_134 - V_904 ) , L_465 ) ;
break;
default:
V_134 += snprintf ( V_134 , V_1254 - ( V_134 - V_904 ) ,
L_466 ,
V_1255 [ V_11 - 1 ] / 1000 ,
V_1256 [ V_11 - 1 ] / 1000 ) ;
}
if ( ! ( V_23 -> V_1181 & V_1252 ) )
V_134 += snprintf ( V_134 , V_1254 - ( V_134 - V_904 ) , L_467 ) ;
V_211 -> V_3 . V_415 = V_134 - V_904 + 1 ;
return 0 ;
}
static int F_451 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
int V_118 = * ( int * ) V_904 ;
T_2 V_882 = 0 , V_804 = 0 ;
if ( V_118 == 0 || V_118 & ~ V_1257 ) {
F_93 ( L_468 , V_118 ) ;
return - V_75 ;
}
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_316 == V_1173 ) {
V_23 -> V_163 -> V_353 = 1 ;
if ( V_118 & V_119 ) {
V_882 |= V_820 ;
V_804 |= V_807 ;
} else
V_23 -> V_163 -> V_353 = 0 ;
} else {
if ( V_118 & V_119 ) {
F_93 ( L_469
L_470 ) ;
F_60 ( & V_23 -> V_109 ) ;
return - V_75 ;
}
V_23 -> V_163 -> V_353 = 0 ;
}
if ( V_118 & V_608 ) {
V_882 |= V_821 ;
V_804 |= V_1172 ;
} else
V_23 -> V_163 -> V_353 = 0 ;
if ( V_118 & V_121 ) {
V_882 |= V_821 ;
V_804 |= V_807 ;
} else
V_23 -> V_163 -> V_353 = 0 ;
V_23 -> V_163 -> V_118 = V_118 ;
V_23 -> V_163 -> V_861 = V_882 ;
V_23 -> V_163 -> V_804 = V_804 ;
F_452 ( V_23 , & V_23 -> V_336 ) ;
F_264 ( L_471 ) ;
if ( ! F_265 ( V_23 ) ) {
F_175 ( V_23 , & V_23 -> V_336 ) ;
V_332 ( V_23 ) ;
}
F_67 ( V_23 ) ;
F_326 ( L_472 ,
V_118 & V_119 ? 'a' : '.' ,
V_118 & V_608 ? 'b' : '.' , V_118 & V_121 ? 'g' : '.' ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_453 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
switch ( V_23 -> V_163 -> V_118 ) {
case V_119 :
strncpy ( V_904 , L_473 , V_1254 ) ;
break;
case V_608 :
strncpy ( V_904 , L_474 , V_1254 ) ;
break;
case V_119 | V_608 :
strncpy ( V_904 , L_475 , V_1254 ) ;
break;
case V_121 :
strncpy ( V_904 , L_476 , V_1254 ) ;
break;
case V_119 | V_121 :
strncpy ( V_904 , L_477 , V_1254 ) ;
break;
case V_608 | V_121 :
strncpy ( V_904 , L_478 , V_1254 ) ;
break;
case V_119 | V_608 | V_121 :
strncpy ( V_904 , L_479 , V_1254 ) ;
break;
default:
strncpy ( V_904 , L_480 , V_1254 ) ;
break;
}
F_326 ( L_481 , V_904 ) ;
V_211 -> V_3 . V_415 = strlen ( V_904 ) + 1 ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_454 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
int V_118 = * ( int * ) V_904 ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_118 == 1 ) {
if ( ! ( V_23 -> V_59 & V_822 ) ) {
V_23 -> V_59 |= V_822 ;
F_264
( L_482 ) ;
if ( ! F_265 ( V_23 ) )
V_332 ( V_23 ) ;
}
goto V_766;
}
if ( V_118 == 0 ) {
V_23 -> V_59 &= ~ V_822 ;
goto V_766;
}
F_60 ( & V_23 -> V_109 ) ;
return - V_75 ;
V_766:
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_455 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( V_23 -> V_59 & V_822 )
snprintf ( V_211 -> V_158 , V_1258 , L_483 ) ;
else
snprintf ( V_211 -> V_158 , V_1258 , L_484 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static int F_456 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
int * V_1259 = ( int * ) V_904 ;
int V_1000 = ( V_1259 [ 0 ] > 0 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_326 ( L_485 , V_1000 , V_1259 [ 1 ] ) ;
if ( V_1000 ) {
if ( V_23 -> V_163 -> V_513 != V_515 ) {
#ifdef F_408
V_23 -> V_167 -> type = V_1169 ;
#else
V_23 -> V_167 -> type = V_1170 ;
#endif
F_128 ( & V_23 -> V_246 ) ;
}
F_411 ( V_23 , V_1259 [ 1 ] ) ;
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
static int F_457 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
F_326 ( L_486 ) ;
F_128 ( & V_23 -> V_246 ) ;
return 0 ;
}
static int F_458 ( struct V_165 * V_166 ,
struct V_902 * V_903 ,
union V_210 * V_211 , char * V_904 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
union V_210 V_1260 = {
. V_1261 = {
. V_41 = V_1262 ,
} ,
} ;
int V_432 ;
F_326 ( L_487 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_432 = F_410 ( V_23 , 2 ) ;
if ( ! V_432 ) {
F_240 () ;
F_160 ( V_23 ) ;
}
F_126 ( V_23 , V_23 -> V_37 & V_184 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_443 ( V_23 -> V_163 , V_903 , & V_1260 , NULL ) ;
F_59 ( & V_23 -> V_109 ) ;
if ( ! ( V_23 -> V_37 & V_99 ) ) {
F_264 ( L_488
L_489 ) ;
if ( ! F_265 ( V_23 ) )
V_332 ( V_23 ) ;
}
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static struct V_1263 * F_459 ( struct V_165 * V_166 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
struct V_1263 * V_1067 ;
V_1067 = & V_23 -> V_1067 ;
if ( ! ( V_23 -> V_37 & V_103 ) ) {
V_1067 -> V_1264 . V_1265 = 0 ;
V_1067 -> V_1068 . V_512 = 0 ;
V_1067 -> V_1192 . V_1192 = 0 ;
V_1067 -> V_1192 . V_11 = 0 ;
V_1067 -> V_1192 . V_737 = 0 ;
V_1067 -> V_1192 . V_1193 = 7 ;
V_1067 -> V_1192 . V_1193 |= V_1266 |
V_1267 | V_1268 ;
return V_1067 ;
}
V_1067 -> V_1192 . V_1192 = V_23 -> V_579 ;
V_1067 -> V_1192 . V_11 = V_23 -> V_581 ;
V_1067 -> V_1192 . V_737 = V_23 -> V_582 ;
V_1067 -> V_1192 . V_1193 = V_1269 | V_1270 |
V_1271 | V_1272 ;
V_1067 -> V_1264 . V_1265 = F_274 ( & V_23 -> V_580 ) ;
V_1067 -> V_1068 . V_512 = V_23 -> V_587 ;
V_1067 -> V_1068 . V_1273 = V_23 -> V_163 -> V_1274 . V_1275 ;
return V_1067 ;
}
static void F_460 ( struct V_1276 * V_310 )
{
memset ( V_310 , 0 , sizeof( struct V_1276 ) ) ;
V_310 -> V_1277 = 0 ;
V_310 -> V_1045 = 0 ;
V_310 -> V_565 = 0 ;
V_310 -> V_566 = 1 ;
V_310 -> V_1278 = 0 ;
V_310 -> V_845 = 1 ;
V_310 -> V_1279 = 0 ;
V_310 -> V_850 = 1 ;
if ( V_1280 < V_1281 || V_1280 > V_1282 )
V_1280 = V_1281 ;
V_310 -> V_1283 = V_1280 ;
V_310 -> V_1284 = 0 ;
V_310 -> V_1044 = 0 ;
V_310 -> V_1285 = 0 ;
V_310 -> V_1286 = 0 ;
V_310 -> V_1287 = 1 ;
V_310 -> V_1288 = 0x1e ;
}
static int F_461 ( struct V_165 * V_166 )
{
F_74 ( L_490 ) ;
F_462 ( V_166 ) ;
return 0 ;
}
static int F_463 ( struct V_165 * V_166 )
{
F_74 ( L_491 ) ;
F_464 ( V_166 ) ;
return 0 ;
}
static int F_465 ( struct V_17 * V_23 , struct V_1289 * V_532 ,
int V_1290 )
{
struct V_1291 * V_1055 = (struct V_1291 * )
V_532 -> V_1292 [ 0 ] -> V_3 ;
int V_7 = 0 ;
struct V_534 * V_768 ;
#ifdef F_292
int V_1293 = F_363 ( V_23 , V_1290 ) ;
struct V_531 * V_230 = & V_23 -> V_230 [ V_1293 ] ;
#else
struct V_531 * V_230 = & V_23 -> V_230 [ 0 ] ;
#endif
struct V_523 * V_521 = & V_230 -> V_521 ;
T_2 V_1294 , V_1295 , V_1008 ;
int V_1056 ;
if ( ! ( V_23 -> V_37 & V_103 ) )
goto V_1136;
V_1295 = F_392 ( F_221 ( V_1055 -> V_1137 ) ) ;
switch ( V_23 -> V_163 -> V_513 ) {
case V_514 :
V_1008 = ! F_365 ( V_1055 -> V_1071 ) ;
V_1294 = F_262 ( V_23 , V_1055 -> V_1071 ) ;
if ( V_1294 == V_552 ) {
V_1294 = F_261 ( V_23 , V_1055 -> V_1071 ) ;
if ( V_1294 == V_552 ) {
F_93 ( L_492
L_493 ,
V_1055 -> V_1071 ) ;
goto V_1136;
}
}
break;
case V_516 :
default:
V_1008 = ! F_365 ( V_1055 -> V_1120 ) ;
V_1294 = 0 ;
break;
}
V_768 = & V_230 -> V_533 [ V_521 -> V_525 ] ;
V_230 -> V_532 [ V_521 -> V_525 ] = V_532 ;
memset ( V_768 , 0 , sizeof( * V_768 ) ) ;
V_768 -> V_538 . V_3 . V_1296 = V_1294 ;
V_768 -> V_535 . V_536 = V_1297 ;
V_768 -> V_535 . V_770 = V_771 ;
V_768 -> V_538 . V_3 . V_837 = V_1298 ;
V_768 -> V_538 . V_3 . V_4 = F_173 ( V_532 -> V_1299 ) ;
if ( V_23 -> V_559 . V_347 == V_352 )
V_768 -> V_538 . V_3 . V_1011 |= V_1300 ;
else
V_768 -> V_538 . V_3 . V_1011 |= V_1301 ;
if ( V_23 -> V_559 . V_1031 == V_1032 )
V_768 -> V_538 . V_3 . V_1014 |= V_1032 ;
V_1056 = F_221 ( V_1055 -> V_1137 ) ;
V_1055 -> V_1137 = F_173 ( V_1056 & ~ V_1302 ) ;
memcpy ( & V_768 -> V_538 . V_3 . V_768 . V_1303 . V_1017 , V_1055 , V_1295 ) ;
if ( F_466 ( V_1008 ) )
V_768 -> V_538 . V_3 . V_1014 |= V_1015 ;
if ( V_532 -> V_1304 && ! V_23 -> V_163 -> V_843 ) {
switch ( V_23 -> V_163 -> V_244 . V_11 ) {
case V_844 :
V_768 -> V_538 . V_3 . V_768 . V_1303 . V_1017 . V_1137 |=
F_173 ( V_1058 ) ;
if ( ! V_1008 )
V_768 -> V_538 . V_3 . V_1014 |= V_1015 ;
V_768 -> V_538 . V_3 . V_1014 &= ~ V_1305 ;
V_768 -> V_538 . V_3 . V_1011 |= V_852 ;
V_768 -> V_538 . V_3 . V_840 = 0 ;
V_768 -> V_538 . V_3 . V_840 |= V_1306 ;
break;
case V_847 :
V_768 -> V_538 . V_3 . V_768 . V_1303 . V_1017 . V_1137 |=
F_173 ( V_1058 ) ;
V_768 -> V_538 . V_3 . V_1014 &= ~ V_1305 ;
V_768 -> V_538 . V_3 . V_1011 |= V_856 ;
V_768 -> V_538 . V_3 . V_840 = V_1306 ;
break;
case V_848 :
V_768 -> V_538 . V_3 . V_768 . V_1303 . V_1017 . V_1137 |=
F_173 ( V_1058 ) ;
V_768 -> V_538 . V_3 . V_840 = V_23 -> V_163 -> V_922 . V_923 ;
if ( V_23 -> V_163 -> V_244 . V_842 [ V_23 -> V_163 -> V_922 . V_923 ] <=
40 )
V_768 -> V_538 . V_3 . V_840 |= V_1307 ;
else
V_768 -> V_538 . V_3 . V_840 |= V_1308 ;
break;
case V_849 :
break;
default:
F_4 ( V_1060 L_384 ,
V_23 -> V_163 -> V_244 . V_11 ) ;
break;
}
} else
V_768 -> V_538 . V_3 . V_1014 |= V_1305 ;
#ifdef F_292
if ( V_1056 & V_1309 )
F_366 ( V_23 , V_1290 , & ( V_768 -> V_538 . V_3 ) ) ;
#endif
V_768 -> V_538 . V_3 . V_539 = F_179 ( F_3 ( ( T_2 ) ( V_540 - 2 ) ,
V_532 -> V_1310 ) ) ;
F_467 ( L_494 ,
V_532 -> V_1310 , F_226 ( V_768 -> V_538 . V_3 . V_539 ) ) ;
for ( V_7 = 0 ; V_7 < F_226 ( V_768 -> V_538 . V_3 . V_539 ) ; V_7 ++ ) {
F_467 ( L_495 ,
V_7 , F_226 ( V_768 -> V_538 . V_3 . V_539 ) ,
V_532 -> V_1292 [ V_7 ] -> V_4 - V_1295 ) ;
F_145 ( L_496 ,
V_7 , V_768 -> V_538 . V_3 . V_539 ,
V_532 -> V_1292 [ V_7 ] -> V_4 - V_1295 ) ;
F_2 ( V_1311 , V_532 -> V_1292 [ V_7 ] -> V_3 + V_1295 ,
V_532 -> V_1292 [ V_7 ] -> V_4 - V_1295 ) ;
V_768 -> V_538 . V_3 . V_541 [ V_7 ] =
F_179 ( F_300
( V_23 -> V_477 ,
V_532 -> V_1292 [ V_7 ] -> V_3 + V_1295 ,
V_532 -> V_1292 [ V_7 ] -> V_4 - V_1295 ,
V_542 ) ) ;
V_768 -> V_538 . V_3 . V_478 [ V_7 ] =
F_173 ( V_532 -> V_1292 [ V_7 ] -> V_4 - V_1295 ) ;
}
if ( V_7 != V_532 -> V_1310 ) {
struct V_1006 * V_501 ;
T_4 V_1312 = 0 ;
int V_8 ;
for ( V_8 = V_7 ; V_8 < V_532 -> V_1310 ; V_8 ++ )
V_1312 += V_532 -> V_1292 [ V_8 ] -> V_4 - V_1295 ;
F_4 ( V_1313 L_497 ,
V_1312 ) ;
V_501 = F_299 ( V_1312 , V_139 ) ;
if ( V_501 != NULL ) {
V_768 -> V_538 . V_3 . V_478 [ V_7 ] = F_173 ( V_1312 ) ;
for ( V_8 = V_7 ; V_8 < V_532 -> V_1310 ; V_8 ++ ) {
int V_15 = V_532 -> V_1292 [ V_8 ] -> V_4 - V_1295 ;
F_4 ( V_1313 L_498 ,
V_8 , V_15 ) ;
memcpy ( F_382 ( V_501 , V_15 ) ,
V_532 -> V_1292 [ V_8 ] -> V_3 + V_1295 , V_15 ) ;
}
F_393 ( V_532 -> V_1292 [ V_7 ] ) ;
V_532 -> V_1292 [ V_7 ] = V_501 ;
V_768 -> V_538 . V_3 . V_541 [ V_7 ] =
F_179 ( F_300
( V_23 -> V_477 , V_501 -> V_3 ,
V_1312 ,
V_542 ) ) ;
F_468 ( & V_768 -> V_538 . V_3 . V_539 , 1 ) ;
}
}
V_521 -> V_525 = F_252 ( V_521 -> V_525 , V_521 -> V_526 ) ;
F_35 ( V_23 , V_521 -> V_530 , V_521 -> V_525 ) ;
if ( F_251 ( V_521 ) < V_521 -> V_528 )
F_464 ( V_23 -> V_167 ) ;
return V_1314 ;
V_1136:
F_379 ( L_499 ) ;
F_257 ( V_532 ) ;
return V_1314 ;
}
static int F_469 ( struct V_165 * V_166 , int V_1290 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
#ifdef F_292
int V_1293 = F_363 ( V_23 , V_1290 ) ;
struct V_531 * V_230 = & V_23 -> V_230 [ V_1293 ] ;
#else
struct V_531 * V_230 = & V_23 -> V_230 [ 0 ] ;
#endif
if ( F_251 ( & V_230 -> V_521 ) < V_230 -> V_521 . V_528 )
return 1 ;
return 0 ;
}
static void F_470 ( struct V_17 * V_23 ,
struct V_1289 * V_532 )
{
struct V_673 V_1315 ;
struct V_1054 * V_1055 ;
T_2 V_172 ;
T_4 V_161 = V_23 -> V_159 -> V_161 ;
int V_1109 = 0 ;
if ( V_161 & V_1316 )
return;
memset ( & V_1315 , 0 , sizeof( V_1315 ) ) ;
V_1055 = ( void * ) V_532 -> V_1292 [ 0 ] -> V_3 ;
if ( F_388 ( F_221 ( V_1055 -> V_1057 ) ) ) {
if ( V_161 & V_1111 )
return;
if ( V_161 & V_1112 )
V_1109 = 1 ;
} else if ( F_389 ( F_221 ( V_1055 -> V_1057 ) ) ) {
if ( V_161 & V_1113 )
return;
if ( V_161 & V_1114 )
V_1109 = 1 ;
} else if ( F_390 ( F_221 ( V_1055 -> V_1057 ) ) ) {
if ( V_161 & V_1115 )
return;
if ( V_161 & V_1116 )
V_1109 = 1 ;
}
for( V_172 = 0 ; V_172 < V_532 -> V_1310 ; ++ V_172 ) {
struct V_1006 * V_803 = V_532 -> V_1292 [ V_172 ] ;
struct V_1006 * V_1317 ;
struct V_1318 * V_1080 ;
int V_4 ;
if ( V_1109 ) {
V_1055 = ( void * ) V_803 -> V_3 ;
V_4 = F_392 ( F_221 ( V_1055 -> V_1057 ) ) ;
} else
V_4 = V_803 -> V_4 ;
V_1317 = F_299 ( V_4 + sizeof( * V_1080 ) + sizeof( T_4 ) * 2 , V_139 ) ;
if ( ! V_1317 )
continue;
V_1080 = ( void * ) F_382 ( V_1317 , sizeof( * V_1080 ) ) ;
V_1080 -> V_1081 = V_1082 ;
V_1080 -> V_1083 = 0 ;
V_1080 -> V_1085 = 0 ;
V_1080 -> V_1085 |= F_179 ( 1 << V_1089 ) ;
* ( T_8 * ) F_382 ( V_1317 , sizeof( T_4 ) ) = F_173 (
F_386 ( V_23 -> V_197 ) ) ;
if ( V_23 -> V_197 > 14 )
* ( T_8 * ) F_382 ( V_1317 , sizeof( T_4 ) ) =
F_173 ( V_1101 |
V_1102 ) ;
else if ( V_23 -> V_163 -> V_118 == V_608 )
* ( T_8 * ) F_382 ( V_1317 , sizeof( T_4 ) ) =
F_173 ( V_1103 |
V_1104 ) ;
else
* ( T_8 * ) F_382 ( V_1317 , sizeof( T_4 ) ) =
F_173 ( V_1101 |
V_1104 ) ;
V_1080 -> V_1084 = F_173 ( V_1317 -> V_4 ) ;
F_471 ( V_803 , F_382 ( V_1317 , V_4 ) , V_4 ) ;
if ( ! F_384 ( V_23 -> V_159 -> V_163 , V_1317 , & V_1315 ) )
F_393 ( V_1317 ) ;
}
}
static T_12 F_472 ( struct V_1289 * V_532 ,
struct V_165 * V_166 , int V_1290 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
unsigned long V_41 ;
T_12 V_432 ;
F_145 ( L_500 , V_532 -> V_1299 ) ;
F_41 ( & V_23 -> V_98 , V_41 ) ;
#ifdef F_269
if ( V_156 && F_92 ( V_23 -> V_157 ) )
F_470 ( V_23 , V_532 ) ;
#endif
V_432 = F_465 ( V_23 , V_532 , V_1290 ) ;
if ( V_432 == V_1314 )
F_63 ( V_23 ) ;
F_42 ( & V_23 -> V_98 , V_41 ) ;
return V_432 ;
}
static void F_473 ( struct V_165 * V_166 )
{
}
static int F_474 ( struct V_165 * V_166 , void * V_134 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
struct V_1319 * V_32 = V_134 ;
if ( ! F_475 ( V_32 -> V_215 ) )
return - V_1320 ;
F_59 ( & V_23 -> V_109 ) ;
V_23 -> V_59 |= V_1321 ;
memcpy ( V_23 -> V_543 , V_32 -> V_215 , V_217 ) ;
F_4 ( V_1313 L_144 ,
V_23 -> V_167 -> V_158 , V_23 -> V_543 ) ;
F_128 ( & V_23 -> V_246 ) ;
F_60 ( & V_23 -> V_109 ) ;
return 0 ;
}
static void F_476 ( struct V_165 * V_166 ,
struct V_1322 * V_903 )
{
struct V_17 * V_134 = F_341 ( V_166 ) ;
char V_1323 [ 64 ] ;
char V_1324 [ 32 ] ;
T_3 V_4 ;
F_477 ( V_903 -> V_1325 , V_1326 , sizeof( V_903 -> V_1325 ) ) ;
F_477 ( V_903 -> V_984 , V_1327 , sizeof( V_903 -> V_984 ) ) ;
V_4 = sizeof( V_1323 ) ;
F_48 ( V_134 , V_1328 , V_1323 , & V_4 ) ;
V_4 = sizeof( V_1324 ) ;
F_48 ( V_134 , V_1329 , V_1324 , & V_4 ) ;
snprintf ( V_903 -> V_1330 , sizeof( V_903 -> V_1330 ) , L_501 ,
V_1323 , V_1324 ) ;
F_477 ( V_903 -> V_1331 , F_478 ( V_134 -> V_477 ) ,
sizeof( V_903 -> V_1331 ) ) ;
V_903 -> V_1332 = V_386 ;
}
static T_3 F_479 ( struct V_165 * V_166 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
return ( V_23 -> V_37 & V_103 ) != 0 ;
}
static int F_480 ( struct V_165 * V_166 )
{
return V_386 ;
}
static int F_481 ( struct V_165 * V_166 ,
struct V_1333 * V_123 , T_2 * V_1334 )
{
struct V_17 * V_134 = F_341 ( V_166 ) ;
if ( V_123 -> V_468 + V_123 -> V_4 > V_386 )
return - V_75 ;
F_59 ( & V_134 -> V_109 ) ;
memcpy ( V_1334 , & V_134 -> V_123 [ V_123 -> V_468 ] , V_123 -> V_4 ) ;
F_60 ( & V_134 -> V_109 ) ;
return 0 ;
}
static int F_482 ( struct V_165 * V_166 ,
struct V_1333 * V_123 , T_2 * V_1334 )
{
struct V_17 * V_134 = F_341 ( V_166 ) ;
int V_7 ;
if ( V_123 -> V_468 + V_123 -> V_4 > V_386 )
return - V_75 ;
F_59 ( & V_134 -> V_109 ) ;
memcpy ( & V_134 -> V_123 [ V_123 -> V_468 ] , V_1334 , V_123 -> V_4 ) ;
for ( V_7 = 0 ; V_7 < V_386 ; V_7 ++ )
F_197 ( V_134 , V_7 + V_387 , V_134 -> V_123 [ V_7 ] ) ;
F_60 ( & V_134 -> V_109 ) ;
return 0 ;
}
static T_13 F_483 ( int V_1335 , void * V_3 )
{
struct V_17 * V_23 = V_3 ;
T_3 V_219 , V_220 ;
if ( ! V_23 )
return V_1336 ;
F_484 ( & V_23 -> V_42 ) ;
if ( ! ( V_23 -> V_37 & V_38 ) ) {
goto V_1337;
}
V_219 = F_36 ( V_23 , V_222 ) ;
V_220 = F_36 ( V_23 , V_39 ) ;
if ( V_219 == 0xFFFFFFFF ) {
F_93 ( L_502 ) ;
goto V_1337;
}
if ( ! ( V_219 & ( V_40 & V_220 ) ) ) {
goto V_1337;
}
F_39 ( V_23 ) ;
V_219 &= ( V_40 & V_220 ) ;
F_35 ( V_23 , V_222 , V_219 ) ;
V_23 -> V_223 = V_219 ;
F_485 ( & V_23 -> V_1338 ) ;
F_486 ( & V_23 -> V_42 ) ;
return V_1339 ;
V_1337:
F_486 ( & V_23 -> V_42 ) ;
return V_1336 ;
}
static void F_487 ( void * V_316 )
{
struct V_17 * V_23 = V_316 ;
unsigned long V_41 ;
F_41 ( & V_23 -> V_98 , V_41 ) ;
if ( F_123 ( V_23 ) ) {
F_127 ( L_503 ) ;
F_56 ( & V_23 -> V_191 , 2 * V_192 ) ;
goto V_1340;
}
if ( ! ( V_23 -> V_37 & V_99 ) ) {
F_127 ( L_504
L_505 ) ;
F_128 ( & V_23 -> V_246 ) ;
} else
F_127 ( L_506
L_507 ) ;
V_1340:
F_42 ( & V_23 -> V_98 , V_41 ) ;
}
static void F_488 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_191 . V_107 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_487 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_489 ( struct V_17 * V_23 )
{
V_23 -> V_1132 = - 1 ;
V_23 -> V_1133 = - 1 ;
V_23 -> V_1134 = 0 ;
F_490 ( V_23 -> V_167 ) ;
F_64 ( & V_23 -> V_186 ) ;
F_64 ( & V_23 -> V_187 ) ;
F_64 ( & V_23 -> V_188 ) ;
F_64 ( & V_23 -> V_189 ) ;
F_275 ( V_23 ) ;
V_23 -> V_583 = F_277 ( V_23 ) ;
F_278 ( V_23 ) ;
F_71 ( V_23 ) ;
F_138 ( V_23 ) ;
if ( V_23 -> V_59 & V_708 )
F_56 ( & V_23 -> V_186 , V_192 ) ;
}
static void F_491 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_676 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_489 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_492 ( struct V_17 * V_23 )
{
F_72 ( V_23 ) ;
F_266 ( V_23 -> V_167 ) ;
F_138 ( V_23 ) ;
F_64 ( & V_23 -> V_186 ) ;
F_64 ( & V_23 -> V_187 ) ;
F_64 ( & V_23 -> V_188 ) ;
F_64 ( & V_23 -> V_669 ) ;
F_64 ( & V_23 -> V_644 ) ;
F_275 ( V_23 ) ;
if ( ! ( V_23 -> V_37 & V_701 ) ) {
F_56 ( & V_23 -> V_186 , 0 ) ;
} else
F_64 ( & V_23 -> V_189 ) ;
}
static void F_493 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_241 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_492 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int F_494 ( struct V_17 * V_23 )
{
int V_432 = 0 ;
F_495 ( & V_23 -> V_228 ) ;
F_495 ( & V_23 -> V_486 ) ;
F_496 ( & V_23 -> V_669 , F_323 ) ;
F_497 ( & V_23 -> V_333 , F_374 ) ;
F_497 ( & V_23 -> V_558 , F_267 ) ;
F_497 ( & V_23 -> V_564 , F_268 ) ;
F_497 ( & V_23 -> V_780 , F_301 ) ;
F_497 ( & V_23 -> V_246 , F_164 ) ;
F_496 ( & V_23 -> V_191 , F_488 ) ;
F_497 ( & V_23 -> V_193 , V_1341 ) ;
F_497 ( & V_23 -> V_190 , V_1342 ) ;
F_496 ( & V_23 -> V_186 , F_333 ) ;
F_496 ( & V_23 -> V_187 , F_334 ) ;
F_496 ( & V_23 -> V_188 , F_332 ) ;
F_496 ( & V_23 -> V_189 , F_285 ) ;
F_496 ( & V_23 -> V_644 , F_281 ) ;
F_497 ( & V_23 -> V_653 , F_335 ) ;
F_497 ( & V_23 -> V_706 , F_373 ) ;
F_496 ( & V_23 -> V_322 , F_169 ) ;
F_497 ( & V_23 -> V_676 , F_491 ) ;
F_497 ( & V_23 -> V_241 , F_493 ) ;
F_496 ( & V_23 -> V_108 , F_57 ) ;
F_496 ( & V_23 -> V_104 , F_62 ) ;
F_496 ( & V_23 -> V_114 , F_66 ) ;
F_497 ( & V_23 -> V_816 , F_312 ) ;
#ifdef F_292
F_497 ( & V_23 -> V_962 , F_367 ) ;
#endif
F_498 ( & V_23 -> V_1338 , ( void (*) ( unsigned long ) )
F_140 , ( unsigned long ) V_23 ) ;
return V_432 ;
}
static void F_499 ( struct V_165 * V_166 ,
struct V_887 * V_244 )
{
struct V_17 * V_23 = F_341 ( V_166 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
if ( V_244 -> V_41 & ( 1 << V_7 ) ) {
V_23 -> V_163 -> V_244 . V_1343 [ V_7 ] = V_244 -> V_1343 [ V_7 ] ;
V_23 -> V_163 -> V_244 . V_842 [ V_7 ] = V_244 -> V_842 [ V_7 ] ;
if ( V_244 -> V_842 [ V_7 ] == 0 )
V_23 -> V_163 -> V_244 . V_41 &= ~ ( 1 << V_7 ) ;
else {
memcpy ( V_23 -> V_163 -> V_244 . V_832 [ V_7 ] , V_244 -> V_832 [ V_7 ] ,
V_244 -> V_842 [ V_7 ] ) ;
V_23 -> V_163 -> V_244 . V_41 |= ( 1 << V_7 ) ;
}
V_23 -> V_37 |= V_1047 ;
} else if ( V_244 -> V_11 != V_848 )
V_23 -> V_163 -> V_244 . V_41 &= ~ ( 1 << V_7 ) ;
}
if ( V_244 -> V_41 & V_851 ) {
if ( V_244 -> V_853 <= 3 ) {
V_23 -> V_163 -> V_244 . V_853 = V_244 -> V_853 ;
V_23 -> V_163 -> V_244 . V_41 |= V_851 ;
} else
V_23 -> V_163 -> V_244 . V_41 &= ~ V_851 ;
V_23 -> V_37 |= V_1047 ;
} else
V_23 -> V_163 -> V_244 . V_41 &= ~ V_851 ;
if ( ( V_244 -> V_41 & V_888 ) &&
( V_23 -> V_163 -> V_244 . V_890 != V_244 -> V_890 ) ) {
V_23 -> V_163 -> V_244 . V_890 = V_244 -> V_890 ;
V_23 -> V_163 -> V_244 . V_41 |= V_888 ;
if ( V_244 -> V_890 == V_891 )
V_23 -> V_317 |= V_1036 ;
else
V_23 -> V_317 &= ~ V_1036 ;
V_23 -> V_37 |= V_1047 ;
}
if ( V_244 -> V_41 & V_929 && V_23 -> V_163 -> V_244 . V_930 != V_244 -> V_930 ) {
V_23 -> V_163 -> V_244 . V_41 |= V_929 ;
V_23 -> V_163 -> V_244 . V_930 = V_244 -> V_930 ;
V_23 -> V_37 |= V_1047 ;
if ( V_244 -> V_930 )
V_23 -> V_317 |= V_814 ;
else
V_23 -> V_317 &= ~ V_814 ;
}
if ( V_244 -> V_41 & V_1344 )
V_23 -> V_163 -> V_244 . V_245 = V_244 -> V_245 ;
if ( V_244 -> V_41 & V_932 && V_23 -> V_163 -> V_244 . V_11 != V_244 -> V_11 ) {
V_23 -> V_163 -> V_244 . V_11 = V_244 -> V_11 ;
V_23 -> V_163 -> V_244 . V_41 |= V_932 ;
V_23 -> V_37 |= V_1047 ;
}
if ( ! V_23 -> V_163 -> V_843 && ( V_244 -> V_41 & V_1344 ) )
F_321 ( V_23 ) ;
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
static int F_452 ( struct V_17 * V_23 ,
struct V_335 * V_336 )
{
memset ( V_336 , 0 , sizeof( * V_336 ) ) ;
switch ( V_23 -> V_163 -> V_861 ) {
case V_820 :
V_336 -> V_347 = V_354 ;
V_336 -> V_1042 = V_1345 ;
F_307 ( V_336 , V_1172 ,
V_1346 ) ;
break;
default:
V_336 -> V_347 = V_348 ;
V_336 -> V_1042 = V_1345 ;
F_306 ( V_336 , V_1172 ,
V_1347 ) ;
if ( V_23 -> V_163 -> V_804 & V_807 ) {
F_307 ( V_336 , V_1172 ,
V_1346 ) ;
}
break;
}
return 0 ;
}
static int F_500 ( struct V_17 * V_23 )
{
if ( F_181 ( V_23 ) )
goto error;
if ( F_159 ( V_23 , V_23 -> V_167 -> V_1119 ) )
goto error;
F_460 ( & V_23 -> V_310 ) ;
if ( V_1348 ) {
unsigned char V_1349 = V_23 -> V_123 [ V_1350 ] ;
if ( V_1349 & V_1351 )
V_23 -> V_310 . V_1277
|= V_1352 ;
if ( V_1349 & V_1353 )
V_23 -> V_310 . V_1277
|= V_1354 ;
}
#ifdef F_269
if ( V_23 -> V_157 && F_92 ( V_23 -> V_157 ) ) {
V_23 -> V_310 . V_565 = 1 ;
V_23 -> V_310 . V_566 = 1 ;
V_23 -> V_310 . V_567 = 1 ;
V_23 -> V_310 . V_568 = 1 ;
}
#endif
if ( V_23 -> V_163 -> V_513 == V_514 )
V_23 -> V_310 . V_1045 = 1 ;
else
V_23 -> V_310 . V_1045 = 0 ;
if ( F_157 ( V_23 ) )
goto error;
F_452 ( V_23 , & V_23 -> V_336 ) ;
if ( F_175 ( V_23 , & V_23 -> V_336 ) )
goto error;
if ( V_23 -> V_357 ) {
if ( F_182 ( V_23 , V_23 -> V_357 ) )
goto error;
}
#ifdef F_292
F_294 ( L_508 ) ;
F_354 ( V_23 , NULL ) ;
#endif
if ( F_176 ( V_23 ) )
goto error;
if ( F_156 ( V_23 ) )
goto error;
V_23 -> V_37 |= V_69 ;
F_73 ( V_23 ) ;
F_69 ( V_23 ) ;
V_23 -> V_646 = 0 ;
if ( ( V_23 -> V_317 & V_814 ) &&
( V_23 -> V_163 -> V_244 . V_11 == V_848 ) &&
! ( V_23 -> V_163 -> V_843 || V_23 -> V_163 -> V_846 ) )
F_321 ( V_23 ) ;
return 0 ;
error:
return - V_306 ;
}
static void F_501 ( struct V_17 * V_23 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_222 ( V_1355 ) ; V_8 ++ ) {
if ( ! memcmp ( & V_23 -> V_123 [ V_1356 ] ,
V_1355 [ V_8 ] . V_158 , 3 ) )
break;
}
if ( V_8 == F_222 ( V_1355 ) ) {
F_93 ( L_509 ,
V_23 -> V_123 [ V_1356 + 0 ] ,
V_23 -> V_123 [ V_1356 + 1 ] ,
V_23 -> V_123 [ V_1356 + 2 ] ) ;
V_8 = 0 ;
}
F_502 ( V_23 -> V_163 , & V_1355 [ V_8 ] ) ;
}
static int F_163 ( struct V_17 * V_23 )
{
int V_155 , V_7 ;
if ( V_23 -> V_1357 ) {
F_503 ( V_23 -> V_163 , V_23 -> V_1357 ) ;
V_23 -> V_1357 = 0 ;
}
if ( V_23 -> V_37 & V_701 )
return - V_306 ;
if ( V_149 && ! V_23 -> V_149 ) {
V_23 -> V_149 = F_504 ( V_149 , sizeof( * V_23 -> V_149 ) ,
V_148 ) ;
if ( V_23 -> V_149 == NULL ) {
F_46 ( L_510 ,
V_149 ) ;
return - V_476 ;
} else {
V_23 -> V_151 = V_149 ;
}
}
for ( V_7 = 0 ; V_7 < V_1358 ; V_7 ++ ) {
V_155 = F_242 ( V_23 ) ;
if ( V_155 ) {
F_46 ( L_196 , V_155 ) ;
return V_155 ;
}
F_52 ( V_23 ) ;
if ( ! ( V_23 -> V_59 & V_1321 ) )
F_193 ( V_23 , V_23 -> V_543 ) ;
memcpy ( V_23 -> V_167 -> V_1119 , V_23 -> V_543 , V_217 ) ;
F_501 ( V_23 ) ;
if ( V_23 -> V_37 & V_184 ) {
F_93 ( L_511 ) ;
return 0 ;
} else if ( F_123 ( V_23 ) ) {
F_93 ( L_512
L_513
L_514 ) ;
F_56 ( & V_23 -> V_191 , 2 * V_192 ) ;
return 0 ;
}
V_155 = F_500 ( V_23 ) ;
if ( ! V_155 ) {
F_74 ( L_515 , V_7 ) ;
F_56 ( & V_23 -> V_186 , 0 ) ;
return 0 ;
}
F_74 ( L_516 , V_155 ) ;
F_74 ( L_517 ,
V_7 , V_1358 ) ;
F_161 ( V_23 ) ;
}
F_46 ( L_518 , V_7 ) ;
return - V_306 ;
}
static void V_1341 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_193 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_163 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static void F_505 ( struct V_17 * V_23 )
{
int V_7 ;
if ( V_23 -> V_37 & V_321 ) {
F_74 ( L_519 ) ;
F_168 ( V_23 ) ;
}
if ( V_23 -> V_37 & V_103 ) {
F_74 ( L_520 ) ;
F_265 ( V_23 ) ;
}
F_75 ( V_23 ) ;
for ( V_7 = 1000 ; V_7 && ( V_23 -> V_37 &
( V_560 |
V_103 | V_321 ) ) ; V_7 -- )
F_187 ( 10 ) ;
if ( V_23 -> V_37 & ( V_560 |
V_103 | V_321 ) )
F_74 ( L_521 ) ;
else
F_74 ( L_522 , 1000 - V_7 ) ;
F_178 ( V_23 , 0 ) ;
V_23 -> V_37 &= ~ V_69 ;
}
static void F_161 ( struct V_17 * V_23 )
{
int V_1359 = V_23 -> V_37 & V_701 ;
V_23 -> V_37 |= V_701 ;
if ( F_47 ( V_23 ) )
F_505 ( V_23 ) ;
if ( ! V_1359 )
V_23 -> V_37 &= ~ V_701 ;
F_43 ( V_23 ) ;
V_23 -> V_37 &= V_99 | V_701 ;
F_266 ( V_23 -> V_167 ) ;
F_230 ( V_23 ) ;
F_70 ( V_23 ) ;
}
static void V_1342 ( struct V_106 * V_107 )
{
struct V_17 * V_23 =
F_58 ( V_107 , struct V_17 , V_190 ) ;
F_59 ( & V_23 -> V_109 ) ;
F_161 ( V_23 ) ;
F_60 ( & V_23 -> V_109 ) ;
}
static int F_506 ( struct V_165 * V_166 )
{
int V_7 , V_155 = 0 ;
struct V_17 * V_23 = F_341 ( V_166 ) ;
const struct V_201 * V_202 = F_137 ( V_23 -> V_163 ) ;
struct V_1360 * V_182 = & V_23 -> V_163 -> V_182 ;
memcpy ( V_182 -> V_183 -> V_1361 , V_23 -> V_543 , V_217 ) ;
if ( V_202 -> V_203 ) {
struct V_1362 * V_1363 = & V_23 -> V_163 -> V_1363 ;
V_1363 -> V_882 = V_1364 ;
V_1363 -> V_1365 = V_202 -> V_203 ;
V_1363 -> V_870 = F_504 ( V_202 -> V_203 ,
sizeof( struct V_1366 ) ,
V_148 ) ;
if ( ! V_1363 -> V_870 ) {
V_155 = - V_476 ;
goto V_6;
}
for ( V_7 = 0 ; V_7 < V_202 -> V_203 ; V_7 ++ ) {
V_1363 -> V_870 [ V_7 ] . V_882 = V_1364 ;
V_1363 -> V_870 [ V_7 ] . V_1367 = V_202 -> V_204 [ V_7 ] . V_1150 ;
V_1363 -> V_870 [ V_7 ] . V_1368 = V_202 -> V_204 [ V_7 ] . V_197 ;
V_1363 -> V_870 [ V_7 ] . V_346 = V_202 -> V_204 [ V_7 ] . V_346 ;
if ( V_202 -> V_204 [ V_7 ] . V_41 & V_207 )
V_1363 -> V_870 [ V_7 ] . V_41 |=
V_1369 ;
if ( V_202 -> V_204 [ V_7 ] . V_41 & V_206 )
V_1363 -> V_870 [ V_7 ] . V_41 |=
V_1370 ;
if ( V_202 -> V_204 [ V_7 ] . V_41 & V_205 )
V_1363 -> V_870 [ V_7 ] . V_41 |=
V_1371 ;
}
V_1363 -> V_1372 = V_1373 ;
V_1363 -> V_1374 = V_1375 ;
V_182 -> V_183 -> V_1376 [ V_1364 ] = V_1363 ;
}
if ( V_202 -> V_209 ) {
struct V_1362 * V_1377 = & V_23 -> V_163 -> V_1377 ;
V_1377 -> V_882 = V_1378 ;
V_1377 -> V_1365 = V_202 -> V_209 ;
V_1377 -> V_870 = F_504 ( V_202 -> V_209 ,
sizeof( struct V_1366 ) ,
V_148 ) ;
if ( ! V_1377 -> V_870 ) {
V_155 = - V_476 ;
goto V_6;
}
for ( V_7 = 0 ; V_7 < V_202 -> V_209 ; V_7 ++ ) {
V_1377 -> V_870 [ V_7 ] . V_882 = V_1378 ;
V_1377 -> V_870 [ V_7 ] . V_1367 = V_202 -> V_18 [ V_7 ] . V_1150 ;
V_1377 -> V_870 [ V_7 ] . V_1368 = V_202 -> V_18 [ V_7 ] . V_197 ;
V_1377 -> V_870 [ V_7 ] . V_346 = V_202 -> V_18 [ V_7 ] . V_346 ;
if ( V_202 -> V_18 [ V_7 ] . V_41 & V_207 )
V_1377 -> V_870 [ V_7 ] . V_41 |=
V_1369 ;
if ( V_202 -> V_18 [ V_7 ] . V_41 & V_206 )
V_1377 -> V_870 [ V_7 ] . V_41 |=
V_1370 ;
if ( V_202 -> V_18 [ V_7 ] . V_41 & V_205 )
V_1377 -> V_870 [ V_7 ] . V_41 |=
V_1371 ;
}
V_1377 -> V_1372 = V_1379 ;
V_1377 -> V_1374 = V_1380 ;
V_182 -> V_183 -> V_1376 [ V_1378 ] = V_1377 ;
}
V_182 -> V_183 -> V_1381 = V_1382 ;
V_182 -> V_183 -> V_1383 = F_222 ( V_1382 ) ;
F_507 ( V_182 -> V_183 , & V_23 -> V_477 -> V_166 ) ;
if ( F_508 ( V_182 -> V_183 ) )
V_155 = - V_306 ;
V_6:
return V_155 ;
}
static int F_509 ( struct V_165 * V_166 )
{
struct V_1384 * V_159 = F_341 ( V_166 ) ;
struct V_17 * V_23 = V_159 -> V_23 ;
F_74 ( L_523 ) ;
F_266 ( V_166 ) ;
if ( V_23 -> V_163 -> V_513 != V_515 ) {
V_23 -> V_310 . V_565 = 1 ;
V_23 -> V_310 . V_566 = 1 ;
V_23 -> V_310 . V_567 = 1 ;
V_23 -> V_310 . V_568 = 1 ;
F_157 ( V_23 ) ;
}
return 0 ;
}
static int F_510 ( struct V_165 * V_166 )
{
struct V_1384 * V_159 = F_341 ( V_166 ) ;
struct V_17 * V_23 = V_159 -> V_23 ;
F_74 ( L_524 ) ;
if ( V_23 -> V_163 -> V_513 != V_515 ) {
V_23 -> V_310 . V_565 = 0 ;
V_23 -> V_310 . V_566 = 0 ;
V_23 -> V_310 . V_567 = 0 ;
V_23 -> V_310 . V_568 = 0 ;
F_157 ( V_23 ) ;
}
return 0 ;
}
static T_12 F_511 ( struct V_1006 * V_501 ,
struct V_165 * V_166 )
{
F_74 ( L_525 ) ;
F_239 ( V_501 ) ;
return V_1314 ;
}
static int F_95 ( struct V_17 * V_23 )
{
int V_155 = 0 ;
if ( V_23 -> V_157 )
return - V_160 ;
V_23 -> V_157 = F_512 ( sizeof( struct V_1384 ) , 1 ) ;
if ( V_23 -> V_157 == NULL )
return - V_476 ;
V_23 -> V_159 = F_341 ( V_23 -> V_157 ) ;
V_23 -> V_159 -> V_163 = F_513 ( V_23 -> V_157 ) ;
V_23 -> V_159 -> V_23 = V_23 ;
strcpy ( V_23 -> V_157 -> V_158 , L_526 ) ;
memcpy ( V_23 -> V_157 -> V_1119 , V_23 -> V_543 , V_217 ) ;
V_23 -> V_157 -> type = V_1169 ;
V_23 -> V_157 -> V_1385 = & V_1386 ;
V_23 -> V_159 -> V_163 -> V_513 = V_515 ;
F_514 ( V_23 -> V_157 , & V_23 -> V_477 -> V_166 ) ;
V_155 = F_515 ( V_23 -> V_157 ) ;
if ( V_155 ) {
F_516 ( V_23 -> V_157 , 1 ) ;
V_23 -> V_157 = NULL ;
return V_155 ;
}
return 0 ;
}
static void F_94 ( struct V_17 * V_23 )
{
if ( ! V_23 -> V_157 )
return;
F_517 ( V_23 -> V_157 ) ;
F_516 ( V_23 -> V_157 , 1 ) ;
V_23 -> V_157 = NULL ;
}
static int F_518 ( struct V_477 * V_1387 ,
const struct V_1388 * V_1389 )
{
int V_557 = 0 ;
struct V_165 * V_167 ;
void T_14 * V_137 ;
T_3 V_415 , V_21 ;
struct V_17 * V_23 ;
int V_7 ;
V_167 = F_512 ( sizeof( struct V_17 ) , 0 ) ;
if ( V_167 == NULL ) {
V_557 = - V_476 ;
goto V_6;
}
V_23 = F_341 ( V_167 ) ;
V_23 -> V_163 = F_513 ( V_167 ) ;
V_23 -> V_167 = V_167 ;
V_23 -> V_477 = V_1387 ;
V_12 = V_1390 ;
F_302 ( & V_23 -> V_42 ) ;
F_302 ( & V_23 -> V_98 ) ;
for ( V_7 = 0 ; V_7 < V_1128 ; V_7 ++ )
F_237 ( & V_23 -> V_1129 [ V_7 ] ) ;
F_519 ( & V_23 -> V_109 ) ;
if ( F_520 ( V_1387 ) ) {
V_557 = - V_1391 ;
goto V_1392;
}
F_521 ( V_1387 ) ;
V_557 = F_522 ( V_1387 , F_523 ( 32 ) ) ;
if ( ! V_557 )
V_557 = F_524 ( V_1387 , F_523 ( 32 ) ) ;
if ( V_557 ) {
F_4 (KERN_WARNING DRV_NAME L_527 ) ;
goto V_1393;
}
F_525 ( V_1387 , V_23 ) ;
V_557 = F_526 ( V_1387 , V_1326 ) ;
if ( V_557 )
goto V_1393;
F_527 ( V_1387 , 0x40 , & V_21 ) ;
if ( ( V_21 & 0x0000ff00 ) != 0 )
F_528 ( V_1387 , 0x40 , V_21 & 0xffff00ff ) ;
V_415 = F_529 ( V_1387 , 0 ) ;
V_23 -> V_1394 = V_415 ;
V_137 = F_530 ( V_1387 , 0 ) ;
if ( ! V_137 ) {
V_557 = - V_1391 ;
goto V_1395;
}
V_23 -> V_22 = V_137 ;
F_74 ( L_528 , V_415 ) ;
F_74 ( L_529 , V_137 ) ;
V_557 = F_494 ( V_23 ) ;
if ( V_557 ) {
F_46 ( L_530 ) ;
goto V_1396;
}
F_410 ( V_23 , 1 ) ;
V_557 = F_531 ( V_1387 -> V_1335 , F_483 , V_1397 , V_1326 , V_23 ) ;
if ( V_557 ) {
F_46 ( L_531 , V_1387 -> V_1335 ) ;
goto V_1396;
}
F_514 ( V_167 , & V_1387 -> V_166 ) ;
F_59 ( & V_23 -> V_109 ) ;
V_23 -> V_163 -> V_1398 = F_472 ;
V_23 -> V_163 -> V_897 = F_499 ;
V_23 -> V_163 -> V_1399 = F_469 ;
#ifdef F_292
V_23 -> V_163 -> V_1400 = F_364 ;
V_23 -> V_163 -> V_1401 = F_369 ;
V_23 -> V_163 -> V_1402 = F_368 ;
V_23 -> V_163 -> V_1403 = F_370 ;
#endif
V_23 -> V_163 -> V_642 = - 20 ;
V_23 -> V_163 -> V_643 = - 85 ;
V_167 -> V_1385 = & V_1404 ;
V_23 -> V_1405 . V_1406 = & V_23 -> V_163 -> V_1406 ;
V_167 -> V_1405 = & V_23 -> V_1405 ;
V_167 -> V_1407 = & V_1408 ;
V_167 -> V_1409 = & V_1410 ;
V_557 = F_532 ( & V_1387 -> V_166 . V_1411 , & V_1412 ) ;
if ( V_557 ) {
F_46 ( L_532 ) ;
F_60 ( & V_23 -> V_109 ) ;
goto V_1413;
}
if ( F_163 ( V_23 ) ) {
F_60 ( & V_23 -> V_109 ) ;
V_557 = - V_306 ;
goto V_1414;
}
F_60 ( & V_23 -> V_109 ) ;
V_557 = F_506 ( V_167 ) ;
if ( V_557 ) {
F_46 ( L_533 ) ;
goto V_1414;
}
V_557 = F_515 ( V_167 ) ;
if ( V_557 ) {
F_46 ( L_534 ) ;
goto V_1415;
}
#ifdef F_269
if ( V_156 ) {
V_557 = F_95 ( V_23 ) ;
if ( V_557 ) {
F_46 ( L_74
L_75 , V_557 ) ;
F_517 ( V_23 -> V_167 ) ;
goto V_1415;
}
}
#endif
F_4 (KERN_INFO DRV_NAME L_535
L_536 ,
priv->ieee->geo.name, priv->ieee->geo.bg_channels,
priv->ieee->geo.a_channels) ;
return 0 ;
V_1415:
F_533 ( V_23 -> V_163 -> V_182 . V_183 ) ;
F_87 ( V_23 -> V_163 -> V_1377 . V_870 ) ;
F_87 ( V_23 -> V_163 -> V_1363 . V_870 ) ;
V_1414:
F_534 ( & V_1387 -> V_166 . V_1411 , & V_1412 ) ;
V_1413:
F_535 ( V_1387 -> V_1335 , V_23 ) ;
V_1396:
F_536 ( V_23 -> V_22 ) ;
V_1395:
F_537 ( V_1387 ) ;
V_1393:
F_538 ( V_1387 ) ;
F_525 ( V_1387 , NULL ) ;
V_1392:
F_516 ( V_23 -> V_167 , 0 ) ;
V_6:
return V_557 ;
}
static void F_539 ( struct V_477 * V_1387 )
{
struct V_17 * V_23 = F_540 ( V_1387 ) ;
struct V_437 * V_134 , * V_521 ;
int V_7 ;
if ( ! V_23 )
return;
F_59 ( & V_23 -> V_109 ) ;
V_23 -> V_37 |= V_701 ;
F_161 ( V_23 ) ;
F_534 ( & V_1387 -> V_166 . V_1411 , & V_1412 ) ;
F_60 ( & V_23 -> V_109 ) ;
F_517 ( V_23 -> V_167 ) ;
if ( V_23 -> V_496 ) {
F_248 ( V_23 , V_23 -> V_496 ) ;
V_23 -> V_496 = NULL ;
}
F_249 ( V_23 ) ;
if ( V_23 -> V_149 ) {
F_87 ( V_23 -> V_149 ) ;
V_23 -> V_149 = NULL ;
}
F_541 ( & V_23 -> V_669 ) ;
F_542 ( & V_23 -> V_333 ) ;
F_542 ( & V_23 -> V_558 ) ;
F_542 ( & V_23 -> V_564 ) ;
F_542 ( & V_23 -> V_780 ) ;
F_542 ( & V_23 -> V_246 ) ;
F_541 ( & V_23 -> V_191 ) ;
F_542 ( & V_23 -> V_193 ) ;
F_542 ( & V_23 -> V_190 ) ;
F_541 ( & V_23 -> V_186 ) ;
F_541 ( & V_23 -> V_187 ) ;
F_541 ( & V_23 -> V_188 ) ;
F_541 ( & V_23 -> V_189 ) ;
F_541 ( & V_23 -> V_644 ) ;
F_542 ( & V_23 -> V_653 ) ;
F_542 ( & V_23 -> V_706 ) ;
F_541 ( & V_23 -> V_322 ) ;
F_542 ( & V_23 -> V_676 ) ;
F_542 ( & V_23 -> V_241 ) ;
F_541 ( & V_23 -> V_108 ) ;
F_541 ( & V_23 -> V_104 ) ;
F_541 ( & V_23 -> V_114 ) ;
F_542 ( & V_23 -> V_816 ) ;
for ( V_7 = 0 ; V_7 < V_1128 ; V_7 ++ ) {
F_211 (p, q, &priv->ibss_mac_hash[i]) {
F_213 ( V_134 ) ;
F_87 ( F_212 ( V_134 , struct V_1127 , V_442 ) ) ;
}
}
F_87 ( V_23 -> error ) ;
V_23 -> error = NULL ;
#ifdef F_269
F_94 ( V_23 ) ;
#endif
F_535 ( V_1387 -> V_1335 , V_23 ) ;
F_536 ( V_23 -> V_22 ) ;
F_537 ( V_1387 ) ;
F_538 ( V_1387 ) ;
F_525 ( V_1387 , NULL ) ;
F_533 ( V_23 -> V_163 -> V_182 . V_183 ) ;
F_87 ( V_23 -> V_163 -> V_1377 . V_870 ) ;
F_87 ( V_23 -> V_163 -> V_1363 . V_870 ) ;
F_516 ( V_23 -> V_167 , 0 ) ;
F_240 () ;
}
static int F_543 ( struct V_477 * V_1387 , T_15 V_665 )
{
struct V_17 * V_23 = F_540 ( V_1387 ) ;
struct V_165 * V_166 = V_23 -> V_167 ;
F_4 ( V_1313 L_537 , V_166 -> V_158 ) ;
F_161 ( V_23 ) ;
F_544 ( V_166 ) ;
F_545 ( V_1387 ) ;
F_538 ( V_1387 ) ;
F_546 ( V_1387 , F_547 ( V_1387 , V_665 ) ) ;
V_23 -> V_1416 = F_548 () ;
return 0 ;
}
static int F_549 ( struct V_477 * V_1387 )
{
struct V_17 * V_23 = F_540 ( V_1387 ) ;
struct V_165 * V_166 = V_23 -> V_167 ;
int V_557 ;
T_3 V_21 ;
F_4 ( V_1313 L_538 , V_166 -> V_158 ) ;
F_546 ( V_1387 , V_1417 ) ;
V_557 = F_520 ( V_1387 ) ;
if ( V_557 ) {
F_4 ( V_1060 L_539 ,
V_166 -> V_158 ) ;
return V_557 ;
}
F_550 ( V_1387 ) ;
F_527 ( V_1387 , 0x40 , & V_21 ) ;
if ( ( V_21 & 0x0000ff00 ) != 0 )
F_528 ( V_1387 , 0x40 , V_21 & 0xffff00ff ) ;
F_551 ( V_166 ) ;
V_23 -> V_1357 = F_548 () - V_23 -> V_1416 ;
F_128 ( & V_23 -> V_193 ) ;
return 0 ;
}
static void F_552 ( struct V_477 * V_1387 )
{
struct V_17 * V_23 = F_540 ( V_1387 ) ;
F_161 ( V_23 ) ;
F_538 ( V_1387 ) ;
}
static int T_16 F_553 ( void )
{
int V_432 ;
F_4 (KERN_INFO DRV_NAME L_540 DRV_DESCRIPTION L_541 DRV_VERSION L_68 ) ;
F_4 (KERN_INFO DRV_NAME L_540 DRV_COPYRIGHT L_68 ) ;
V_432 = F_554 ( & V_1418 ) ;
if ( V_432 ) {
F_46 ( L_542 ) ;
return V_432 ;
}
V_432 = F_555 ( & V_1418 . V_1325 , & V_1419 ) ;
if ( V_432 ) {
F_46 ( L_543 ) ;
F_556 ( & V_1418 ) ;
return V_432 ;
}
return V_432 ;
}
static void T_17 F_557 ( void )
{
F_558 ( & V_1418 . V_1325 , & V_1419 ) ;
F_556 ( & V_1418 ) ;
}
