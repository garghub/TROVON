static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_5 )
{
V_4 -> V_6 . type = V_7 ;
V_4 -> V_6 . V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_7 , F_2 ( V_2 ) ,
V_5 , V_4 ) < 0 )
return - V_8 ;
return 0 ;
}
static void F_4 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
if ( V_4 -> V_9 )
F_5 ( V_4 ) ;
}
static inline void F_6 ( struct V_10 * V_11 , int V_12 , int V_13 )
{
F_7 ( V_13 , V_11 -> V_14 + V_12 ) ;
}
static inline unsigned int F_8 ( struct V_10 * V_11 , int V_12 )
{
return F_9 ( V_11 -> V_14 + V_12 ) ;
}
static inline int F_10 ( struct V_10 * V_11 )
{
unsigned long V_15 ;
int V_16 = 1 ;
F_11 ( & V_11 -> V_17 , V_15 ) ;
if ( ( V_11 -> V_18 != V_11 -> V_19 ) &&
( V_11 -> V_18 >= 0 ) && ( V_11 -> V_19 >= 0 ) ) {
V_16 = 0 ;
}
F_12 ( & V_11 -> V_17 , V_15 ) ;
return V_16 ;
}
static inline int F_13 ( struct V_10 * V_11 )
{
if ( F_14 ( V_11 ) ) {
return ( F_8 ( V_11 , V_20 ) &
V_21 ) ? 96000 : 88200 ;
} else {
return ( F_8 ( V_11 , V_20 ) &
V_21 ) ? 48000 : 44100 ;
}
}
static inline void F_15 ( struct V_10 * V_11 )
{
unsigned int V_22 ;
V_22 = V_11 -> V_23 & V_24 ;
V_11 -> V_25 = 1 << ( ( F_16 ( V_22 ) + 8 ) ) ;
V_11 -> V_26 =
( V_11 -> V_25 * 2 - 1 ) & V_27 ;
V_11 -> V_28 = 80 ;
}
static T_2 F_17 ( struct V_10 * V_11 )
{
int V_29 ;
unsigned int V_30 , V_31 ;
T_2 V_32 = V_11 -> V_25 / 4 ;
T_3 V_33 ;
V_29 = F_8 ( V_11 , V_20 ) ;
if ( ! V_11 -> V_34 )
return ( V_29 & V_35 ) ? V_32 : 0 ;
V_30 = V_29 & V_27 ;
V_33 = V_11 -> V_36 - V_30 ;
V_33 &= 0xffff ;
if ( V_33 <= ( T_3 ) V_11 -> V_28 * 4 )
V_30 = V_11 -> V_36 ;
else
V_11 -> V_36 = V_30 ;
V_30 &= V_11 -> V_26 ;
V_30 /= 4 ;
V_31 = V_29 & V_35 ;
if ( V_30 < V_32 ) {
if ( V_30 > V_11 -> V_28 ) {
if ( V_31 )
F_18 ( V_11 -> V_37 -> V_6 ,
L_1 ,
V_29 , V_30 ) ;
} else if ( ! V_31 )
return 0 ;
V_30 -= V_11 -> V_28 ;
if ( ( int ) V_30 < 0 )
V_30 += V_32 * 2 ;
} else {
if ( V_30 > V_32 + V_11 -> V_28 ) {
if ( ! V_31 )
F_18 ( V_11 -> V_37 -> V_6 ,
L_2 ,
V_29 , V_30 ) ;
} else if ( V_31 )
return V_32 ;
V_30 -= V_11 -> V_28 ;
}
return V_30 ;
}
static inline void F_19 ( struct V_10 * V_11 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
F_6 ( V_11 , V_22 * 4 , 0 ) ;
F_20 ( 10 ) ;
}
V_11 -> V_36 = 0 ;
}
static inline void F_21 ( struct V_10 * V_38 )
{
V_38 -> V_23 |= ( V_39 | V_40 ) ;
F_6 ( V_38 , V_41 , V_38 -> V_23 ) ;
}
static inline void F_22 ( struct V_10 * V_38 )
{
V_38 -> V_23 &= ~ ( V_40 | V_39 ) ;
F_6 ( V_38 , V_41 , V_38 -> V_23 ) ;
}
static int F_23 ( struct V_10 * V_38 ,
unsigned int V_42 )
{
int V_43 = 0 ;
int V_44 ;
F_24 ( & V_38 -> V_17 ) ;
if ( ( V_43 = V_38 -> V_45 ) ) {
F_22 ( V_38 ) ;
}
V_42 >>= 7 ;
V_44 = 0 ;
while ( V_42 ) {
V_44 ++ ;
V_42 >>= 1 ;
}
V_38 -> V_23 &= ~ V_24 ;
V_38 -> V_23 |= F_25 ( V_44 ) ;
F_6 ( V_38 , V_41 , V_38 -> V_23 ) ;
F_15 ( V_38 ) ;
if ( V_43 )
F_21 ( V_38 ) ;
F_26 ( & V_38 -> V_17 ) ;
return 0 ;
}
static int F_27 ( struct V_10 * V_11 , int V_46 )
{
int V_43 ;
int V_47 = 0 ;
int V_48 ;
if ( ! F_10 ( V_11 ) ) {
return - V_49 ;
}
F_24 ( & V_11 -> V_17 ) ;
V_48 = F_13 ( V_11 ) ;
switch ( V_46 ) {
case 44100 :
if ( V_48 > 48000 ) {
V_47 = 1 ;
}
V_46 = 0 ;
break;
case 48000 :
if ( V_48 > 48000 ) {
V_47 = 1 ;
}
V_46 = V_50 ;
break;
case 88200 :
if ( V_48 < 48000 ) {
V_47 = 1 ;
}
V_46 = V_51 ;
break;
case 96000 :
if ( V_48 < 48000 ) {
V_47 = 1 ;
}
V_46 = V_51 | V_50 ;
break;
default:
F_26 ( & V_11 -> V_17 ) ;
return - V_52 ;
}
if ( V_47 && ( V_11 -> V_19 >= 0 || V_11 -> V_18 >= 0 ) ) {
F_26 ( & V_11 -> V_17 ) ;
return - V_49 ;
}
if ( ( V_43 = V_11 -> V_45 ) ) {
F_22 ( V_11 ) ;
}
V_11 -> V_23 &= ~ ( V_50 | V_51 ) ;
V_11 -> V_23 |= V_46 ;
F_6 ( V_11 , V_41 , V_11 -> V_23 ) ;
if ( V_43 ) {
F_21 ( V_11 ) ;
}
if ( V_46 & V_51 ) {
if ( V_11 -> V_53 == V_54 ) {
V_11 -> V_55 = V_56 ;
} else {
V_11 -> V_55 = V_57 ;
}
} else {
if ( V_11 -> V_53 == V_54 ) {
V_11 -> V_55 = V_58 ;
} else {
V_11 -> V_55 = V_59 ;
}
}
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static void F_28 ( struct V_10 * V_11 , int V_60 , int V_61 )
{
int V_22 ;
V_11 -> V_62 = 0 ;
if ( V_60 < 0 ) {
if ( V_61 ) {
for ( V_22 = 0 ; V_22 < V_54 ; V_22 ++ ) {
V_11 -> V_63 |= ( 1 << V_22 ) ;
F_6 ( V_11 , V_64 + V_22 * 4 , 1 ) ;
}
} else {
for ( V_22 = 0 ; V_22 < V_54 ; V_22 ++ ) {
V_11 -> V_63 &= ~ ( 1 << V_22 ) ;
F_6 ( V_11 , V_64 + V_22 * 4 , 0 ) ;
}
}
} else {
int V_65 ;
V_65 = V_11 -> V_55 [ V_60 ] ;
if ( V_61 ) {
V_11 -> V_63 |= ( 1 << V_65 ) ;
} else {
V_11 -> V_63 &= ~ ( 1 << V_65 ) ;
}
F_6 ( V_11 ,
V_64 + V_65 * 4 ,
V_61 ? 1 : 0 ) ;
}
}
static int F_29 ( struct V_10 * V_11 , int V_66 )
{
if ( V_66 ) {
F_28 ( V_11 , - 1 , 1 ) ;
V_11 -> V_23 =
V_67 |
F_25 ( 7 ) |
V_40 ;
F_19 ( V_11 ) ;
F_6 ( V_11 , V_41 ,
V_11 -> V_23 ) ;
V_11 -> V_62 = 1 ;
} else {
F_28 ( V_11 , - 1 , 0 ) ;
F_22 ( V_11 ) ;
V_11 -> V_62 = 0 ;
}
return 0 ;
}
static void F_30 ( struct V_10 * V_11 , int V_68 , int V_66 )
{
if ( V_66 )
V_11 -> V_23 |= V_68 ;
else
V_11 -> V_23 &= ~ V_68 ;
F_6 ( V_11 , V_41 , V_11 -> V_23 ) ;
}
static void F_31 ( struct V_10 * V_11 , const int V_13 )
{
long V_68 ;
long V_22 ;
for ( V_22 = 0 , V_68 = 0x80 ; V_22 < 8 ; V_22 ++ , V_68 >>= 1 ) {
if ( V_13 & V_68 )
F_30 ( V_11 , V_69 , 1 ) ;
else
F_30 ( V_11 , V_69 , 0 ) ;
F_30 ( V_11 , V_70 , 1 ) ;
F_30 ( V_11 , V_70 , 0 ) ;
}
}
static int F_32 ( struct V_10 * V_11 )
{
long V_68 ;
long V_13 ;
long V_22 ;
V_13 = 0 ;
for ( V_22 = 0 , V_68 = 0x80 ; V_22 < 8 ; V_22 ++ , V_68 >>= 1 ) {
F_30 ( V_11 , V_70 , 1 ) ;
if ( F_8 ( V_11 , V_20 ) & V_71 )
V_13 |= V_68 ;
F_30 ( V_11 , V_70 , 0 ) ;
}
return V_13 ;
}
static void F_33 ( struct V_10 * V_11 , const int V_72 , const int V_73 )
{
F_30 ( V_11 , V_74 , 1 ) ;
F_31 ( V_11 , 0x20 ) ;
F_31 ( V_11 , V_72 ) ;
F_31 ( V_11 , V_73 ) ;
F_30 ( V_11 , V_74 , 0 ) ;
}
static int F_34 ( struct V_10 * V_11 , const int V_72 )
{
int V_16 ;
F_30 ( V_11 , V_74 , 1 ) ;
F_31 ( V_11 , 0x20 ) ;
F_31 ( V_11 , V_72 ) ;
F_30 ( V_11 , V_74 , 0 ) ;
F_30 ( V_11 , V_74 , 1 ) ;
F_31 ( V_11 , 0x21 ) ;
V_16 = F_32 ( V_11 ) ;
F_30 ( V_11 , V_74 , 0 ) ;
return V_16 ;
}
static void F_35 ( struct V_10 * V_11 )
{
V_11 -> V_23 |= V_75 ;
F_33 ( V_11 , 4 , 0x40 ) ;
F_33 ( V_11 , 17 , 0x13 ) ;
F_33 ( V_11 , 6 , 0x02 ) ;
}
static inline int F_36 ( struct V_10 * V_38 )
{
unsigned int V_76 ;
if ( F_8 ( V_38 , V_20 ) & V_77 ) {
return - 1 ;
}
if ( V_38 -> V_78 == 15 ) {
int V_79 , V_80 , V_16 ;
V_79 = F_34 ( V_38 , 30 ) ;
if ( V_79 != 0 )
V_80 = 48000 * 64 / V_79 ;
else
V_80 = 0 ;
if ( V_80 > 30400 && V_80 < 33600 ) V_16 = 32000 ;
else if ( V_80 > 41900 && V_80 < 46000 ) V_16 = 44100 ;
else if ( V_80 > 46000 && V_80 < 50400 ) V_16 = 48000 ;
else if ( V_80 > 60800 && V_80 < 67200 ) V_16 = 64000 ;
else if ( V_80 > 83700 && V_80 < 92000 ) V_16 = 88200 ;
else if ( V_80 > 92000 && V_80 < 100000 ) V_16 = 96000 ;
else V_16 = 0 ;
return V_16 ;
}
V_76 = F_8 ( V_38 , V_20 ) & V_81 ;
switch ( F_37 ( V_76 ) ) {
case 0x7 :
return 32000 ;
break;
case 0x6 :
return 44100 ;
break;
case 0x5 :
return 48000 ;
break;
case 0x4 :
return 88200 ;
break;
case 0x3 :
return 96000 ;
break;
case 0x0 :
return 64000 ;
break;
default:
F_18 ( V_38 -> V_37 -> V_6 ,
L_3 ,
V_38 -> V_82 , V_76 ) ;
return 0 ;
break;
}
}
static T_4 F_38 ( struct V_83 * V_84 )
{
T_4 V_13 = 0 ;
V_13 |= ( V_84 -> V_29 [ 0 ] & V_85 ) ? V_86 : 0 ;
V_13 |= ( V_84 -> V_29 [ 0 ] & V_87 ) ? V_88 : 0 ;
if ( V_13 & V_86 )
V_13 |= ( V_84 -> V_29 [ 0 ] & V_89 ) ? V_90 : 0 ;
else
V_13 |= ( V_84 -> V_29 [ 0 ] & V_91 ) ? V_90 : 0 ;
return V_13 ;
}
static void F_39 ( struct V_83 * V_84 , T_4 V_13 )
{
V_84 -> V_29 [ 0 ] = ( ( V_13 & V_86 ) ? V_85 : 0 ) |
( ( V_13 & V_88 ) ? V_87 : 0 ) ;
if ( V_13 & V_86 )
V_84 -> V_29 [ 0 ] |= ( V_13 & V_90 ) ? V_89 : 0 ;
else
V_84 -> V_29 [ 0 ] |= ( V_13 & V_90 ) ? V_91 : 0 ;
}
static int F_40 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
V_95 -> type = V_96 ;
V_95 -> V_97 = 1 ;
return 0 ;
}
static int F_41 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_39 ( & V_99 -> V_100 . V_101 , V_11 -> V_102 ) ;
return 0 ;
}
static int F_43 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 ;
T_4 V_13 ;
V_13 = F_38 ( & V_99 -> V_100 . V_101 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_103 = V_13 != V_11 -> V_102 ;
V_11 -> V_102 = V_13 ;
F_26 ( & V_11 -> V_17 ) ;
return V_103 ;
}
static int F_44 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
V_95 -> type = V_96 ;
V_95 -> V_97 = 1 ;
return 0 ;
}
static int F_45 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_39 ( & V_99 -> V_100 . V_101 , V_11 -> V_104 ) ;
return 0 ;
}
static int F_46 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 ;
T_4 V_13 ;
V_13 = F_38 ( & V_99 -> V_100 . V_101 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_103 = V_13 != V_11 -> V_104 ;
V_11 -> V_104 = V_13 ;
V_11 -> V_23 &= ~ ( V_86 | V_88 | V_90 ) ;
F_6 ( V_11 , V_41 , V_11 -> V_23 |= V_13 ) ;
F_26 ( & V_11 -> V_17 ) ;
return V_103 ;
}
static int F_47 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
V_95 -> type = V_96 ;
V_95 -> V_97 = 1 ;
return 0 ;
}
static int F_48 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
V_99 -> V_100 . V_101 . V_29 [ 0 ] = V_93 -> V_105 ;
return 0 ;
}
static unsigned int F_49 ( struct V_10 * V_11 )
{
if ( V_11 -> V_23 & V_106 )
return 1 ;
return 0 ;
}
static int F_50 ( struct V_10 * V_11 , int V_107 )
{
int V_43 = 0 ;
if ( V_107 ) {
V_11 -> V_23 |= V_106 ;
} else {
V_11 -> V_23 &= ~ V_106 ;
}
if ( ( V_43 = V_11 -> V_45 ) ) {
F_22 ( V_11 ) ;
}
F_6 ( V_11 , V_41 , V_11 -> V_23 ) ;
if ( V_43 ) {
F_21 ( V_11 ) ;
}
return 0 ;
}
static int F_51 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
static const char * const V_108 [ 2 ] = { L_4 , L_5 } ;
return F_52 ( V_95 , 1 , 2 , V_108 ) ;
}
static int F_53 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_99 -> V_100 . V_109 . V_110 [ 0 ] = F_49 ( V_11 ) ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_54 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 ;
unsigned int V_13 ;
if ( ! F_10 ( V_11 ) )
return - V_49 ;
V_13 = V_99 -> V_100 . V_109 . V_110 [ 0 ] % 2 ;
F_24 ( & V_11 -> V_17 ) ;
V_103 = V_13 != F_49 ( V_11 ) ;
if ( V_103 )
F_50 ( V_11 , V_13 ) ;
F_26 ( & V_11 -> V_17 ) ;
return V_103 ;
}
static unsigned int F_55 ( struct V_10 * V_11 )
{
return F_56 ( V_11 -> V_23 &
V_111 ) ;
}
static int F_57 ( struct V_10 * V_11 , int V_112 )
{
int V_43 = 0 ;
V_11 -> V_23 &= ~ V_111 ;
V_11 -> V_23 |= F_58 ( V_112 ) ;
if ( ( V_43 = V_11 -> V_45 ) ) {
F_22 ( V_11 ) ;
}
F_6 ( V_11 , V_41 , V_11 -> V_23 ) ;
if ( V_43 ) {
F_21 ( V_11 ) ;
}
return 0 ;
}
static int F_59 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
static const char * const V_108 [ 3 ] = { L_4 , L_6 , L_5 } ;
return F_52 ( V_95 , 1 , 3 , V_108 ) ;
}
static int F_60 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_99 -> V_100 . V_109 . V_110 [ 0 ] = F_55 ( V_11 ) ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_61 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 ;
unsigned int V_13 ;
if ( ! F_10 ( V_11 ) )
return - V_49 ;
V_13 = V_99 -> V_100 . V_109 . V_110 [ 0 ] % 3 ;
F_24 ( & V_11 -> V_17 ) ;
V_103 = V_13 != F_55 ( V_11 ) ;
if ( V_103 )
F_57 ( V_11 , V_13 ) ;
F_26 ( & V_11 -> V_17 ) ;
return V_103 ;
}
static int F_62 ( struct V_10 * V_11 )
{
return ( V_11 -> V_23 & V_113 ) ? 1 : 0 ;
}
static int F_63 ( struct V_10 * V_11 , int V_114 )
{
int V_43 = 0 ;
if ( V_114 ) {
V_11 -> V_23 |= V_113 ;
} else {
V_11 -> V_23 &= ~ V_113 ;
}
if ( ( V_43 = V_11 -> V_45 ) ) {
F_22 ( V_11 ) ;
}
F_6 ( V_11 , V_41 , V_11 -> V_23 ) ;
if ( V_43 ) {
F_21 ( V_11 ) ;
}
return 0 ;
}
static int F_64 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_99 -> V_100 . integer . V_100 [ 0 ] = F_62 ( V_11 ) ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_65 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 ;
unsigned int V_13 ;
if ( ! F_10 ( V_11 ) )
return - V_49 ;
V_13 = V_99 -> V_100 . integer . V_100 [ 0 ] & 1 ;
F_24 ( & V_11 -> V_17 ) ;
V_103 = ( int ) V_13 != F_62 ( V_11 ) ;
F_63 ( V_11 , V_13 ) ;
F_26 ( & V_11 -> V_17 ) ;
return V_103 ;
}
static int F_66 ( struct V_10 * V_11 )
{
if ( V_11 -> V_23 & V_115 ) {
return 2 ;
} else if ( V_11 -> V_23 & V_116 ) {
return 1 ;
} else {
return 0 ;
}
}
static int F_67 ( struct V_10 * V_11 , int V_117 )
{
int V_43 = 0 ;
switch ( V_117 ) {
case 0 :
V_11 -> V_23 &=
~ ( V_116 | V_115 ) ;
break;
case 1 :
V_11 -> V_23 =
( V_11 -> V_23 & ~ V_115 ) | V_116 ;
break;
case 2 :
V_11 -> V_23 |=
( V_116 | V_115 ) ;
break;
}
if ( ( V_43 = V_11 -> V_45 ) ) {
F_22 ( V_11 ) ;
}
F_6 ( V_11 , V_41 , V_11 -> V_23 ) ;
if ( V_43 ) {
F_21 ( V_11 ) ;
}
return 0 ;
}
static int F_68 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
static const char * const V_108 [ 3 ] = {
L_7 , L_8 , L_9
} ;
return F_52 ( V_95 , 1 , 3 , V_108 ) ;
}
static int F_69 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_99 -> V_100 . V_109 . V_110 [ 0 ] = F_66 ( V_11 ) ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_70 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 ;
unsigned int V_13 ;
V_13 = V_99 -> V_100 . V_109 . V_110 [ 0 ] % 3 ;
F_24 ( & V_11 -> V_17 ) ;
V_103 = ( int ) V_13 != F_66 ( V_11 ) ;
F_67 ( V_11 , V_13 ) ;
F_26 ( & V_11 -> V_17 ) ;
return V_103 ;
}
static int F_71 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_23 & V_118 ) {
case V_119 :
return V_120 ;
case V_121 :
return V_122 ;
case V_123 :
return V_124 ;
case V_125 :
return V_126 ;
}
return 0 ;
}
static int F_72 ( struct V_10 * V_11 , int V_127 )
{
int V_43 ;
V_11 -> V_23 &= ~ V_118 ;
switch ( V_127 ) {
case V_120 :
V_11 -> V_23 |= V_119 ;
break;
case V_122 :
V_11 -> V_23 |= V_121 ;
break;
case V_124 :
V_11 -> V_23 |= V_123 ;
break;
case V_126 :
V_11 -> V_23 |= V_125 ;
break;
}
if ( ( V_43 = V_11 -> V_45 ) ) {
F_22 ( V_11 ) ;
}
F_6 ( V_11 , V_41 , V_11 -> V_23 ) ;
if ( V_43 ) {
F_21 ( V_11 ) ;
}
return 0 ;
}
static int F_73 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
static const char * const V_108 [ 4 ] = {
L_10 , L_11 , L_12 , L_13
} ;
struct V_10 * V_11 = F_42 ( V_93 ) ;
return F_52 ( V_95 , 1 ,
V_11 -> V_53 == V_54 ? 4 : 3 ,
V_108 ) ;
}
static int F_74 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_99 -> V_100 . V_109 . V_110 [ 0 ] = F_71 ( V_11 ) ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_75 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 , V_128 ;
unsigned int V_13 ;
if ( ! F_10 ( V_11 ) )
return - V_49 ;
V_128 = V_11 -> V_53 == V_54 ? 4 : 3 ;
V_13 = V_99 -> V_100 . V_109 . V_110 [ 0 ] % V_128 ;
F_24 ( & V_11 -> V_17 ) ;
V_103 = ( int ) V_13 != F_71 ( V_11 ) ;
F_72 ( V_11 , V_13 ) ;
F_26 ( & V_11 -> V_17 ) ;
return V_103 ;
}
static int F_76 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
V_95 -> type = V_129 ;
V_95 -> V_97 = V_11 -> V_53 ;
V_95 -> V_100 . integer . V_130 = 0 ;
V_95 -> V_100 . integer . V_128 = 1 ;
return 0 ;
}
static int F_77 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
unsigned int V_131 ;
T_4 V_63 = V_11 -> V_63 ;
for ( V_131 = 0 ; V_131 < V_11 -> V_53 ; ++ V_131 ) {
V_99 -> V_100 . integer . V_100 [ V_131 ] = ! ! ( V_63 & ( 1 << V_131 ) ) ;
}
return 0 ;
}
static int F_78 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 ;
unsigned int V_132 ;
T_4 V_63 = 0 ;
if ( ! F_10 ( V_11 ) )
return - V_49 ;
for ( V_132 = 0 ; V_132 < V_11 -> V_53 ; ++ V_132 ) {
if ( V_99 -> V_100 . integer . V_100 [ V_132 ] )
V_63 |= 1 << V_132 ;
}
F_24 ( & V_11 -> V_17 ) ;
V_103 = V_63 ^ V_11 -> V_63 ;
if ( V_103 ) {
for ( V_132 = 0 ; V_132 < V_11 -> V_53 ; ++ V_132 ) {
if ( ! ( V_103 & ( 1 << V_132 ) ) )
continue;
F_28 ( V_11 , V_132 , V_63 & ( 1 << V_132 ) ) ;
}
}
F_26 ( & V_11 -> V_17 ) ;
return ! ! V_103 ;
}
static int F_79 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_99 -> V_100 . integer . V_100 [ 0 ] = V_11 -> V_62 ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_80 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 ;
unsigned int V_13 ;
int V_133 = 0 ;
if ( ! F_10 ( V_11 ) )
return - V_49 ;
V_13 = V_99 -> V_100 . integer . V_100 [ 0 ] & 1 ;
F_24 ( & V_11 -> V_17 ) ;
V_103 = ( V_99 -> V_100 . integer . V_100 [ 0 ] != V_11 -> V_62 ) ;
if ( V_103 )
V_133 = F_29 ( V_11 , V_13 ) ;
F_26 ( & V_11 -> V_17 ) ;
return V_133 ? V_133 : V_103 ;
}
static int F_81 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
V_95 -> type = V_134 ;
V_95 -> V_97 = 1 ;
V_95 -> V_100 . integer . V_130 = 0 ;
V_95 -> V_100 . integer . V_128 = 96000 ;
return 0 ;
}
static int F_82 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_99 -> V_100 . integer . V_100 [ 0 ] = F_36 ( V_11 ) ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_83 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
static const char * const V_108 [ 4 ] = {
L_14 , L_15 , L_16 , L_17
} ;
return F_52 ( V_95 , 1 , 4 , V_108 ) ;
}
static int F_84 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
unsigned int V_135 , V_136 , V_13 ;
switch ( V_93 -> V_105 ) {
case 0 : V_135 = V_137 ; V_136 = V_138 ; break;
case 1 : V_135 = V_139 ; V_136 = V_140 ; break;
case 2 : V_135 = V_141 ; V_136 = V_142 ; break;
default: return - V_52 ;
}
V_13 = F_8 ( V_11 , V_20 ) ;
V_99 -> V_100 . V_109 . V_110 [ 0 ] = ( V_13 & V_135 ) ? 1 : 0 ;
V_99 -> V_100 . V_109 . V_110 [ 0 ] |= ( V_13 & V_136 ) ? 2 : 0 ;
return 0 ;
}
static int F_85 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
V_99 -> V_100 . integer . V_100 [ 0 ] =
( F_8 ( V_11 , V_20 ) & V_143 ) ? 1 : 0 ;
return 0 ;
}
static int F_86 ( void * V_144 ,
T_5 * V_145 ,
T_6 * V_146 )
{
struct V_10 * V_38 = (struct V_10 * ) V_144 ;
T_4 V_100 ;
int V_22 ;
V_146 -> type = V_147 ;
if ( ( F_8 ( V_38 , V_20 ) &
V_143 ) == 0 ) {
V_146 -> V_100 . V_148 [ 0 ] = 0 ;
return 0 ;
}
F_6 ( V_38 , V_149 , 0 ) ;
for ( V_22 = 0 ; V_22 < 50 ; V_22 ++ ) {
if ( ! ( F_8 ( V_38 , V_22 * 4 ) & V_150 ) )
break;
}
if ( ! ( F_8 ( V_38 , V_22 * 4 ) & V_150 ) ) {
return - V_151 ;
}
V_100 = 0 ;
for ( V_22 = 0 ; V_22 < 32 ; V_22 ++ ) {
V_100 >>= 1 ;
if ( F_8 ( V_38 , V_22 * 4 ) & V_152 )
V_100 |= 0x80000000 ;
}
if ( V_100 > 2 * 60 * 48000 ) {
V_100 -= 2 * 60 * 48000 ;
} else {
V_100 = 0 ;
}
V_146 -> V_100 . V_148 [ 0 ] = V_100 ;
return 0 ;
}
static int F_87 ( struct V_153 * V_37 , struct V_10 * V_11 )
{
unsigned int V_154 ;
int V_133 ;
struct V_92 * V_155 ;
for ( V_154 = 0 ; V_154 < F_88 ( V_156 ) ; V_154 ++ ) {
if ( ( V_133 = F_89 ( V_37 , V_155 = F_90 ( & V_156 [ V_154 ] , V_11 ) ) ) < 0 )
return V_133 ;
if ( V_154 == 1 )
V_11 -> V_157 = V_155 ;
}
if ( V_11 -> V_53 == V_54 )
if ( ( V_133 = F_89 ( V_37 , V_155 = F_90 ( & V_158 , V_11 ) ) ) < 0 )
return V_133 ;
if ( V_11 -> V_78 >= 15 )
if ( ( V_133 = F_89 ( V_37 , V_155 = F_90 ( & V_159 , V_11 ) ) ) < 0 )
return V_133 ;
return 0 ;
}
static void
F_91 ( struct V_160 * V_161 , struct V_162 * V_163 )
{
struct V_10 * V_11 = (struct V_10 * ) V_161 -> V_144 ;
T_4 V_63 = V_11 -> V_63 ;
int V_164 = 0 ;
int V_22 ;
unsigned int V_29 ;
int V_79 ;
V_29 = F_8 ( V_11 , V_20 ) ;
F_92 ( V_163 , L_18 , V_11 -> V_82 , V_11 -> V_37 -> V_165 + 1 ) ;
F_92 ( V_163 , L_19 ,
V_11 -> V_166 , V_11 -> V_167 ) ;
F_92 ( V_163 , L_20 ,
V_11 -> V_168 , V_11 -> V_169 , ( unsigned long ) V_11 -> V_14 ) ;
F_92 ( V_163 , L_21 , V_11 -> V_23 ) ;
F_92 ( V_163 , L_22 ) ;
V_79 = 1 << ( 6 + F_16 ( V_11 -> V_23 &
V_24 ) ) ;
F_92 ( V_163 , L_23 ,
V_79 , ( unsigned long ) V_11 -> V_25 ) ;
F_92 ( V_163 , L_24 ,
F_17 ( V_11 ) ) ;
F_92 ( V_163 , L_25 ,
V_11 -> V_62 ? L_26 : L_27 ) ;
if ( ( V_11 -> V_23 & ( V_116 | V_115 ) ) == 0 ) {
F_92 ( V_163 , L_28 ) ;
V_164 = 1 ;
} else if ( V_11 -> V_23 & V_115 ) {
if ( V_29 & V_170 ) {
F_92 ( V_163 , L_29 ) ;
} else {
F_92 ( V_163 , L_30 ) ;
}
} else {
F_92 ( V_163 , L_31 ) ;
}
if ( V_164 ) {
switch ( V_11 -> V_23 & V_118 ) {
case V_119 :
F_92 ( V_163 , L_32 ) ;
break;
case V_121 :
F_92 ( V_163 , L_33 ) ;
break;
case V_123 :
F_92 ( V_163 , L_34 ) ;
break;
case V_125 :
F_92 ( V_163 , L_35 ) ;
break;
default:
F_92 ( V_163 , L_36 ) ;
}
}
if ( V_11 -> V_78 >= 15 )
F_92 ( V_163 , L_37 ,
( V_11 -> V_23 & V_106 ) ?
L_5 : L_38 ) ;
F_92 ( V_163 , L_22 ) ;
switch ( F_56 ( V_11 -> V_23 &
V_111 ) ) {
case V_171 :
F_92 ( V_163 , L_39 ) ;
break;
case V_172 :
F_92 ( V_163 , L_40 ) ;
break;
case V_173 :
F_92 ( V_163 , L_41 ) ;
break;
default:
F_92 ( V_163 , L_42 ) ;
break;
}
if ( V_11 -> V_23 & V_113 ) {
F_92 ( V_163 , L_43 ) ;
} else {
F_92 ( V_163 , L_44 ) ;
}
if ( V_11 -> V_23 & V_86 ) {
F_92 ( V_163 , L_45 ) ;
} else {
F_92 ( V_163 , L_46 ) ;
}
if ( V_11 -> V_23 & V_90 ) {
F_92 ( V_163 , L_47 ) ;
} else {
F_92 ( V_163 , L_48 ) ;
}
if ( V_11 -> V_23 & V_88 ) {
F_92 ( V_163 , L_49 ) ;
} else {
F_92 ( V_163 , L_50 ) ;
}
V_22 = F_36 ( V_11 ) ;
if ( V_22 < 0 ) {
F_92 ( V_163 ,
L_51 ) ;
} else if ( V_22 == 0 ) {
F_92 ( V_163 , L_52 ) ;
} else {
F_92 ( V_163 , L_53 , V_22 ) ;
}
F_92 ( V_163 , L_22 ) ;
F_92 ( V_163 , L_54 ,
F_13 ( V_11 ) ) ;
V_79 = V_29 & V_138 ;
if ( V_29 & V_137 ) {
F_92 ( V_163 , L_55 , V_79 ? L_56 : L_15 ) ;
} else {
F_92 ( V_163 , L_57 ) ;
}
V_79 = V_29 & V_140 ;
if ( V_29 & V_139 ) {
F_92 ( V_163 , L_58 , V_79 ? L_56 : L_15 ) ;
} else {
F_92 ( V_163 , L_59 ) ;
}
V_79 = V_29 & V_142 ;
if ( V_29 & V_141 ) {
F_92 ( V_163 , L_60 , V_79 ? L_56 : L_15 ) ;
} else {
F_92 ( V_163 , L_61 ) ;
}
F_92 ( V_163 , L_22 ) ;
F_92 ( V_163 , L_62 ,
( V_29 & V_143 ) ? L_26 : L_27 ) ;
F_92 ( V_163 , L_63 ) ;
for ( V_22 = 0 ; V_22 < V_11 -> V_53 ; V_22 ++ ) {
if ( V_63 & ( 1 << V_22 ) ) {
F_92 ( V_163 , L_64 , V_22 + 1 ) ;
} else {
F_92 ( V_163 , L_65 , V_22 + 1 ) ;
}
if ( ( ( V_22 + 1 ) % 8 ) == 0 ) {
F_92 ( V_163 , L_22 ) ;
}
}
F_92 ( V_163 , L_22 ) ;
}
static void F_93 ( struct V_10 * V_11 )
{
struct V_160 * V_161 ;
if ( ! F_94 ( V_11 -> V_37 , L_66 , & V_161 ) )
F_95 ( V_161 , V_11 , F_91 ) ;
}
static void F_96 ( struct V_10 * V_11 )
{
F_4 ( & V_11 -> V_174 , V_11 -> V_2 ) ;
F_4 ( & V_11 -> V_175 , V_11 -> V_2 ) ;
}
static int F_97 ( struct V_10 * V_11 )
{
if ( V_11 -> V_168 >= 0 )
F_22 ( V_11 ) ;
F_96 ( V_11 ) ;
if ( V_11 -> V_168 >= 0 )
F_98 ( V_11 -> V_168 , ( void * ) V_11 ) ;
if ( V_11 -> V_14 )
F_99 ( V_11 -> V_14 ) ;
if ( V_11 -> V_169 )
F_100 ( V_11 -> V_2 ) ;
F_101 ( V_11 -> V_2 ) ;
return 0 ;
}
static int F_102 ( struct V_10 * V_11 )
{
unsigned long V_176 , V_177 ;
if ( F_1 ( V_11 -> V_2 , & V_11 -> V_174 , V_178 ) < 0 ||
F_1 ( V_11 -> V_2 , & V_11 -> V_175 , V_178 ) < 0 ) {
if ( V_11 -> V_174 . V_9 )
F_5 ( & V_11 -> V_174 ) ;
F_18 ( V_11 -> V_37 -> V_6 ,
L_67 , V_11 -> V_82 ) ;
return - V_8 ;
}
V_177 = F_103 ( V_11 -> V_174 . V_179 , 0x10000ul ) ;
V_176 = F_103 ( V_11 -> V_175 . V_179 , 0x10000ul ) ;
F_6 ( V_11 , V_180 , V_177 ) ;
F_6 ( V_11 , V_181 , V_176 ) ;
V_11 -> V_166 = V_11 -> V_174 . V_9 + ( V_177 - V_11 -> V_174 . V_179 ) ;
V_11 -> V_167 = V_11 -> V_175 . V_9 + ( V_176 - V_11 -> V_175 . V_179 ) ;
return 0 ;
}
static void F_104 ( struct V_10 * V_11 )
{
unsigned int V_131 ;
V_11 -> V_23 =
V_67 | F_25 ( 7 ) ;
F_6 ( V_11 , V_41 , V_11 -> V_23 ) ;
F_19 ( V_11 ) ;
F_15 ( V_11 ) ;
for ( V_131 = 0 ; V_131 < V_54 ; ++ V_131 )
F_6 ( V_11 , V_64 + V_131 * 4 , 0 ) ;
V_11 -> V_63 = 0 ;
V_11 -> V_62 = 0 ;
F_27 ( V_11 , 48000 ) ;
}
static T_7 F_105 ( int V_168 , void * V_182 )
{
struct V_10 * V_11 = (struct V_10 * ) V_182 ;
if ( ! ( F_8 ( V_11 , V_20 ) & V_183 ) ) {
return V_184 ;
}
F_6 ( V_11 , V_185 , 0 ) ;
if ( V_11 -> V_186 ) {
F_106 ( V_11 -> V_187 -> V_188 [ V_189 ] . V_190 ) ;
}
if ( V_11 -> V_191 ) {
F_106 ( V_11 -> V_187 -> V_188 [ V_192 ] . V_190 ) ;
}
return V_193 ;
}
static T_2 F_107 ( struct V_194 * V_190 )
{
struct V_10 * V_11 = F_108 ( V_190 ) ;
return F_17 ( V_11 ) ;
}
static char * F_109 ( struct V_10 * V_11 ,
int V_195 ,
int V_60 )
{
int V_65 ;
if ( F_110 ( V_60 < 0 || V_60 >= V_54 ) )
return NULL ;
if ( ( V_65 = V_11 -> V_55 [ V_60 ] ) < 0 ) {
return NULL ;
}
if ( V_195 == V_189 ) {
return V_11 -> V_166 +
( V_65 * V_196 ) ;
} else {
return V_11 -> V_167 +
( V_65 * V_196 ) ;
}
}
static int F_111 ( struct V_194 * V_190 , int V_60 ,
T_2 V_197 , void T_8 * V_198 , T_2 V_97 )
{
struct V_10 * V_11 = F_108 ( V_190 ) ;
char * V_199 ;
if ( F_110 ( V_197 + V_97 > V_196 / 4 ) )
return - V_52 ;
V_199 = F_109 ( V_11 ,
V_190 -> V_200 -> V_195 ,
V_60 ) ;
if ( F_110 ( ! V_199 ) )
return - V_151 ;
if ( F_112 ( V_199 + V_197 * 4 , V_198 , V_97 * 4 ) )
return - V_201 ;
return V_97 ;
}
static int F_113 ( struct V_194 * V_190 , int V_60 ,
T_2 V_197 , void T_8 * V_202 , T_2 V_97 )
{
struct V_10 * V_11 = F_108 ( V_190 ) ;
char * V_199 ;
if ( F_110 ( V_197 + V_97 > V_196 / 4 ) )
return - V_52 ;
V_199 = F_109 ( V_11 ,
V_190 -> V_200 -> V_195 ,
V_60 ) ;
if ( F_110 ( ! V_199 ) )
return - V_151 ;
if ( F_114 ( V_202 , V_199 + V_197 * 4 , V_97 * 4 ) )
return - V_201 ;
return V_97 ;
}
static int F_115 ( struct V_194 * V_190 , int V_60 ,
T_2 V_197 , T_2 V_97 )
{
struct V_10 * V_11 = F_108 ( V_190 ) ;
char * V_199 ;
V_199 = F_109 ( V_11 ,
V_190 -> V_200 -> V_195 ,
V_60 ) ;
if ( F_110 ( ! V_199 ) )
return - V_151 ;
memset ( V_199 + V_197 * 4 , 0 , V_97 * 4 ) ;
return V_97 ;
}
static int F_116 ( struct V_194 * V_190 )
{
struct V_203 * V_204 = V_190 -> V_204 ;
struct V_10 * V_11 = F_108 ( V_190 ) ;
struct V_194 * V_205 ;
if ( V_190 -> V_195 == V_192 )
V_205 = V_11 -> V_186 ;
else
V_205 = V_11 -> V_191 ;
if ( V_11 -> V_45 )
V_204 -> V_29 -> V_206 = F_17 ( V_11 ) ;
else
V_204 -> V_29 -> V_206 = 0 ;
if ( V_205 ) {
struct V_194 * V_38 ;
struct V_203 * V_207 = V_205 -> V_204 ;
F_117 (s, substream) {
if ( V_38 == V_205 ) {
V_207 -> V_29 -> V_206 = V_204 -> V_29 -> V_206 ;
break;
}
}
}
return 0 ;
}
static int F_118 ( struct V_194 * V_190 ,
struct V_208 * V_209 )
{
struct V_10 * V_11 = F_108 ( V_190 ) ;
int V_133 ;
T_9 V_210 ;
T_9 V_211 ;
F_24 ( & V_11 -> V_17 ) ;
if ( V_190 -> V_200 -> V_195 == V_192 ) {
V_11 -> V_23 &= ~ ( V_86 | V_88 | V_90 ) ;
F_6 ( V_11 , V_41 , V_11 -> V_23 |= V_11 -> V_104 ) ;
V_210 = V_11 -> V_18 ;
V_211 = V_11 -> V_19 ;
} else {
V_210 = V_11 -> V_19 ;
V_211 = V_11 -> V_18 ;
}
if ( ( V_211 > 0 ) && ( V_210 != V_211 ) ) {
if ( ( int ) F_119 ( V_209 ) !=
F_13 ( V_11 ) ) {
F_26 ( & V_11 -> V_17 ) ;
F_120 ( V_209 , V_212 ) ;
return - V_49 ;
}
if ( F_121 ( V_209 ) != V_11 -> V_25 / 4 ) {
F_26 ( & V_11 -> V_17 ) ;
F_120 ( V_209 , V_213 ) ;
return - V_49 ;
}
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
} else {
F_26 ( & V_11 -> V_17 ) ;
}
if ( ( V_133 = F_27 ( V_11 , F_119 ( V_209 ) ) ) < 0 ) {
F_120 ( V_209 , V_212 ) ;
return V_133 ;
}
if ( ( V_133 = F_23 ( V_11 , F_121 ( V_209 ) ) ) < 0 ) {
F_120 ( V_209 , V_213 ) ;
return V_133 ;
}
return 0 ;
}
static int F_122 ( struct V_194 * V_190 ,
struct V_214 * V_215 )
{
struct V_10 * V_11 = F_108 ( V_190 ) ;
int V_132 ;
if ( F_110 ( V_215 -> V_60 >= V_54 ) )
return - V_52 ;
if ( ( V_132 = V_11 -> V_55 [ V_215 -> V_60 ] ) < 0 ) {
return - V_52 ;
}
V_215 -> V_30 = V_132 * V_196 ;
V_215 -> V_216 = 0 ;
V_215 -> V_217 = 32 ;
return 0 ;
}
static int F_123 ( struct V_194 * V_190 ,
unsigned int V_218 , void * V_219 )
{
switch ( V_218 ) {
case V_220 :
{
return F_116 ( V_190 ) ;
}
case V_221 :
{
struct V_214 * V_215 = V_219 ;
return F_122 ( V_190 , V_215 ) ;
}
default:
break;
}
return F_124 ( V_190 , V_218 , V_219 ) ;
}
static void F_125 ( struct V_10 * V_11 )
{
memset ( V_11 -> V_167 , 0 , V_178 ) ;
}
static int F_126 ( struct V_194 * V_190 ,
int V_218 )
{
struct V_10 * V_11 = F_108 ( V_190 ) ;
struct V_194 * V_205 ;
int V_45 ;
F_127 ( & V_11 -> V_17 ) ;
V_45 = V_11 -> V_45 ;
switch ( V_218 ) {
case V_222 :
V_45 |= 1 << V_190 -> V_195 ;
break;
case V_223 :
V_45 &= ~ ( 1 << V_190 -> V_195 ) ;
break;
default:
F_128 () ;
F_129 ( & V_11 -> V_17 ) ;
return - V_52 ;
}
if ( V_190 -> V_195 == V_192 )
V_205 = V_11 -> V_186 ;
else
V_205 = V_11 -> V_191 ;
if ( V_205 ) {
struct V_194 * V_38 ;
F_117 (s, substream) {
if ( V_38 == V_205 ) {
F_130 ( V_38 , V_190 ) ;
if ( V_218 == V_222 )
V_45 |= 1 << V_38 -> V_195 ;
else
V_45 &= ~ ( 1 << V_38 -> V_195 ) ;
goto V_224;
}
}
if ( V_218 == V_222 ) {
if ( ! ( V_45 & ( 1 << V_192 ) ) &&
V_190 -> V_195 == V_189 )
F_125 ( V_11 ) ;
} else {
if ( V_45 &&
V_190 -> V_195 == V_192 )
F_125 ( V_11 ) ;
}
} else {
if ( V_190 -> V_195 == V_189 )
F_125 ( V_11 ) ;
}
V_224:
F_130 ( V_190 , V_190 ) ;
if ( ! V_11 -> V_45 && V_45 )
F_21 ( V_11 ) ;
else if ( V_11 -> V_45 && ! V_45 )
F_22 ( V_11 ) ;
V_11 -> V_45 = V_45 ;
F_129 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_131 ( struct V_194 * V_190 )
{
struct V_10 * V_11 = F_108 ( V_190 ) ;
unsigned long V_15 ;
int V_225 = 0 ;
F_11 ( & V_11 -> V_17 , V_15 ) ;
if ( ! V_11 -> V_45 )
F_19 ( V_11 ) ;
F_12 ( & V_11 -> V_17 , V_15 ) ;
return V_225 ;
}
static int F_132 ( struct V_208 * V_209 ,
struct V_226 * V_227 )
{
struct V_10 * V_11 = V_227 -> V_228 ;
struct V_229 * V_230 = F_133 ( V_209 , V_231 ) ;
unsigned int V_232 [ 2 ] = { V_11 -> V_233 , V_11 -> V_53 } ;
return F_134 ( V_230 , 2 , V_232 , 0 ) ;
}
static int F_135 ( struct V_208 * V_209 ,
struct V_226 * V_227 )
{
struct V_10 * V_11 = V_227 -> V_228 ;
struct V_229 * V_230 = F_133 ( V_209 , V_231 ) ;
struct V_229 * V_234 = F_133 ( V_209 , V_212 ) ;
if ( V_234 -> V_130 > 48000 ) {
struct V_229 V_235 = {
. V_130 = V_11 -> V_233 ,
. V_128 = V_11 -> V_233 ,
. integer = 1 ,
} ;
return F_136 ( V_230 , & V_235 ) ;
} else if ( V_234 -> V_128 < 88200 ) {
struct V_229 V_235 = {
. V_130 = V_11 -> V_53 ,
. V_128 = V_11 -> V_53 ,
. integer = 1 ,
} ;
return F_136 ( V_230 , & V_235 ) ;
}
return 0 ;
}
static int F_137 ( struct V_208 * V_209 ,
struct V_226 * V_227 )
{
struct V_10 * V_11 = V_227 -> V_228 ;
struct V_229 * V_230 = F_133 ( V_209 , V_231 ) ;
struct V_229 * V_234 = F_133 ( V_209 , V_212 ) ;
if ( V_230 -> V_130 >= V_11 -> V_53 ) {
struct V_229 V_235 = {
. V_130 = 44100 ,
. V_128 = 48000 ,
. integer = 1 ,
} ;
return F_136 ( V_234 , & V_235 ) ;
} else if ( V_230 -> V_128 <= V_11 -> V_233 ) {
struct V_229 V_235 = {
. V_130 = 88200 ,
. V_128 = 96000 ,
. integer = 1 ,
} ;
return F_136 ( V_234 , & V_235 ) ;
}
return 0 ;
}
static int F_138 ( struct V_194 * V_190 )
{
struct V_10 * V_11 = F_108 ( V_190 ) ;
struct V_203 * V_204 = V_190 -> V_204 ;
F_24 ( & V_11 -> V_17 ) ;
F_139 ( V_190 ) ;
V_204 -> V_236 = V_237 ;
V_204 -> V_238 = V_11 -> V_167 ;
V_204 -> V_239 = V_178 ;
if ( V_11 -> V_186 == NULL ) {
F_22 ( V_11 ) ;
F_28 ( V_11 , - 1 , 0 ) ;
}
V_11 -> V_18 = V_240 -> V_241 ;
V_11 -> V_191 = V_190 ;
F_26 ( & V_11 -> V_17 ) ;
F_140 ( V_204 , 0 , 32 , 24 ) ;
F_141 ( V_204 , 0 , V_213 , & V_242 ) ;
F_142 ( V_204 , 0 , V_231 ,
F_132 , V_11 ,
V_231 , - 1 ) ;
F_142 ( V_204 , 0 , V_231 ,
F_135 , V_11 ,
V_212 , - 1 ) ;
F_142 ( V_204 , 0 , V_212 ,
F_137 , V_11 ,
V_231 , - 1 ) ;
V_11 -> V_104 = V_11 -> V_102 ;
V_11 -> V_157 -> V_243 [ 0 ] . V_244 &= ~ V_245 ;
F_143 ( V_11 -> V_37 , V_246 |
V_247 , & V_11 -> V_157 -> V_248 ) ;
return 0 ;
}
static int F_144 ( struct V_194 * V_190 )
{
struct V_10 * V_11 = F_108 ( V_190 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_11 -> V_18 = - 1 ;
V_11 -> V_191 = NULL ;
F_26 ( & V_11 -> V_17 ) ;
V_11 -> V_157 -> V_243 [ 0 ] . V_244 |= V_245 ;
F_143 ( V_11 -> V_37 , V_246 |
V_247 , & V_11 -> V_157 -> V_248 ) ;
return 0 ;
}
static int F_145 ( struct V_194 * V_190 )
{
struct V_10 * V_11 = F_108 ( V_190 ) ;
struct V_203 * V_204 = V_190 -> V_204 ;
F_24 ( & V_11 -> V_17 ) ;
F_139 ( V_190 ) ;
V_204 -> V_236 = V_249 ;
V_204 -> V_238 = V_11 -> V_166 ;
V_204 -> V_239 = V_178 ;
if ( V_11 -> V_191 == NULL ) {
F_22 ( V_11 ) ;
F_28 ( V_11 , - 1 , 0 ) ;
}
V_11 -> V_19 = V_240 -> V_241 ;
V_11 -> V_186 = V_190 ;
F_26 ( & V_11 -> V_17 ) ;
F_140 ( V_204 , 0 , 32 , 24 ) ;
F_141 ( V_204 , 0 , V_213 , & V_242 ) ;
F_142 ( V_204 , 0 , V_231 ,
F_132 , V_11 ,
V_231 , - 1 ) ;
F_142 ( V_204 , 0 , V_231 ,
F_135 , V_11 ,
V_212 , - 1 ) ;
F_142 ( V_204 , 0 , V_212 ,
F_137 , V_11 ,
V_231 , - 1 ) ;
return 0 ;
}
static int F_146 ( struct V_194 * V_190 )
{
struct V_10 * V_11 = F_108 ( V_190 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_11 -> V_19 = - 1 ;
V_11 -> V_186 = NULL ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_147 ( struct V_153 * V_37 ,
struct V_10 * V_11 )
{
struct V_250 * V_187 ;
int V_133 ;
if ( ( V_133 = F_148 ( V_37 ,
V_11 -> V_82 ,
0 , 1 , 1 , & V_187 ) ) < 0 ) {
return V_133 ;
}
V_11 -> V_187 = V_187 ;
V_187 -> V_144 = V_11 ;
strcpy ( V_187 -> V_251 , V_11 -> V_82 ) ;
F_149 ( V_187 , V_192 , & V_252 ) ;
F_149 ( V_187 , V_189 , & V_253 ) ;
V_187 -> V_254 = V_255 ;
return 0 ;
}
static int F_150 ( struct V_153 * V_37 ,
struct V_10 * V_11 ,
int V_34 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_133 ;
int V_29 ;
unsigned short V_256 ;
V_11 -> V_168 = - 1 ;
V_11 -> V_37 = V_37 ;
F_151 ( V_11 -> V_2 , V_257 , & V_256 ) ;
switch ( V_256 & 0xff ) {
case 3 :
case 4 :
case 8 :
case 9 :
break;
default:
return - V_258 ;
}
if ( ( V_133 = F_152 ( V_2 ) ) < 0 )
return V_133 ;
F_153 ( & V_11 -> V_17 ) ;
if ( ( V_133 = F_154 ( V_2 , L_66 ) ) < 0 )
return V_133 ;
V_11 -> V_169 = F_155 ( V_2 , 0 ) ;
V_11 -> V_14 = F_156 ( V_11 -> V_169 , V_259 ) ;
if ( V_11 -> V_14 == NULL ) {
F_18 ( V_37 -> V_6 , L_68 ,
V_11 -> V_169 , V_11 -> V_169 + V_259 - 1 ) ;
return - V_49 ;
}
if ( F_157 ( V_2 -> V_168 , F_105 , V_260 ,
V_261 , V_11 ) ) {
F_18 ( V_37 -> V_6 , L_69 , V_2 -> V_168 ) ;
return - V_49 ;
}
V_11 -> V_168 = V_2 -> V_168 ;
V_11 -> V_34 = V_34 ;
V_29 = F_8 ( V_11 , V_20 ) ;
if ( F_37 ( V_29 & V_81 ) == 1 ) {
V_11 -> V_78 = 15 ;
} else {
V_11 -> V_78 = 11 ;
}
switch ( V_256 ) {
case 8 :
strcpy ( V_37 -> V_262 , L_70 ) ;
if ( V_11 -> V_78 == 15 ) {
V_11 -> V_82 = L_71 ;
} else {
V_11 -> V_82 = L_72 ;
}
V_11 -> V_53 = V_263 ;
break;
case 9 :
strcpy ( V_37 -> V_262 , L_70 ) ;
V_11 -> V_82 = L_73 ;
V_11 -> V_53 = V_263 ;
break;
case 4 :
strcpy ( V_37 -> V_262 , L_74 ) ;
V_11 -> V_82 = L_75 ;
V_11 -> V_53 = V_54 ;
break;
case 3 :
strcpy ( V_37 -> V_262 , L_74 ) ;
if ( V_11 -> V_78 == 15 ) {
V_11 -> V_82 = L_76 ;
} else {
V_11 -> V_82 = L_77 ;
}
V_11 -> V_53 = V_54 ;
break;
}
V_11 -> V_233 = ( V_11 -> V_53 - 2 ) / 2 + 2 ;
F_158 ( V_11 -> V_2 ) ;
if ( ( V_133 = F_102 ( V_11 ) ) < 0 ) {
return V_133 ;
}
if ( ( V_133 = F_147 ( V_37 , V_11 ) ) < 0 ) {
return V_133 ;
}
if ( ( V_133 = F_87 ( V_37 , V_11 ) ) < 0 ) {
return V_133 ;
}
F_93 ( V_11 ) ;
V_11 -> V_264 = - 1 ;
V_11 -> V_265 = - 1 ;
V_11 -> V_18 = - 1 ;
V_11 -> V_19 = - 1 ;
V_11 -> V_186 = NULL ;
V_11 -> V_191 = NULL ;
F_104 ( V_11 ) ;
if ( V_11 -> V_78 == 15 ) {
F_35 ( V_11 ) ;
}
return 0 ;
}
static void F_159 ( struct V_153 * V_37 )
{
struct V_10 * V_11 = (struct V_10 * ) V_37 -> V_144 ;
if ( V_11 )
F_97 ( V_11 ) ;
}
static int F_160 ( struct V_1 * V_2 ,
const struct V_266 * V_267 )
{
static int V_6 ;
struct V_10 * V_11 ;
struct V_153 * V_37 ;
int V_133 ;
if ( V_6 >= V_268 )
return - V_258 ;
if ( ! V_61 [ V_6 ] ) {
V_6 ++ ;
return - V_269 ;
}
V_133 = F_161 ( & V_2 -> V_6 , V_270 [ V_6 ] , V_248 [ V_6 ] , V_271 ,
sizeof( struct V_10 ) , & V_37 ) ;
if ( V_133 < 0 )
return V_133 ;
V_11 = (struct V_10 * ) V_37 -> V_144 ;
V_37 -> V_272 = F_159 ;
V_11 -> V_6 = V_6 ;
V_11 -> V_2 = V_2 ;
if ( ( V_133 = F_150 ( V_37 , V_11 , V_34 [ V_6 ] ) ) < 0 ) {
F_162 ( V_37 ) ;
return V_133 ;
}
strcpy ( V_37 -> V_273 , V_11 -> V_82 ) ;
sprintf ( V_37 -> V_274 , L_78 ,
V_37 -> V_273 , V_11 -> V_169 , V_11 -> V_168 ) ;
if ( ( V_133 = F_163 ( V_37 ) ) < 0 ) {
F_162 ( V_37 ) ;
return V_133 ;
}
F_164 ( V_2 , V_37 ) ;
V_6 ++ ;
return 0 ;
}
static void F_165 ( struct V_1 * V_2 )
{
F_162 ( F_166 ( V_2 ) ) ;
}
