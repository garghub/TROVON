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
static char * V_108 [ 2 ] = { L_4 , L_5 } ;
V_95 -> type = V_109 ;
V_95 -> V_97 = 1 ;
V_95 -> V_100 . V_110 . V_111 = 2 ;
if ( V_95 -> V_100 . V_110 . V_112 > 1 )
V_95 -> V_100 . V_110 . V_112 = 1 ;
strcpy ( V_95 -> V_100 . V_110 . V_113 , V_108 [ V_95 -> V_100 . V_110 . V_112 ] ) ;
return 0 ;
}
static int F_52 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_99 -> V_100 . V_110 . V_112 [ 0 ] = F_49 ( V_11 ) ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_53 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 ;
unsigned int V_13 ;
if ( ! F_10 ( V_11 ) )
return - V_49 ;
V_13 = V_99 -> V_100 . V_110 . V_112 [ 0 ] % 2 ;
F_24 ( & V_11 -> V_17 ) ;
V_103 = V_13 != F_49 ( V_11 ) ;
if ( V_103 )
F_50 ( V_11 , V_13 ) ;
F_26 ( & V_11 -> V_17 ) ;
return V_103 ;
}
static unsigned int F_54 ( struct V_10 * V_11 )
{
return F_55 ( V_11 -> V_23 &
V_114 ) ;
}
static int F_56 ( struct V_10 * V_11 , int V_115 )
{
int V_43 = 0 ;
V_11 -> V_23 &= ~ V_114 ;
V_11 -> V_23 |= F_57 ( V_115 ) ;
if ( ( V_43 = V_11 -> V_45 ) ) {
F_22 ( V_11 ) ;
}
F_6 ( V_11 , V_41 , V_11 -> V_23 ) ;
if ( V_43 ) {
F_21 ( V_11 ) ;
}
return 0 ;
}
static int F_58 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
static char * V_108 [ 3 ] = { L_4 , L_6 , L_5 } ;
V_95 -> type = V_109 ;
V_95 -> V_97 = 1 ;
V_95 -> V_100 . V_110 . V_111 = 3 ;
if ( V_95 -> V_100 . V_110 . V_112 > 2 )
V_95 -> V_100 . V_110 . V_112 = 2 ;
strcpy ( V_95 -> V_100 . V_110 . V_113 , V_108 [ V_95 -> V_100 . V_110 . V_112 ] ) ;
return 0 ;
}
static int F_59 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_99 -> V_100 . V_110 . V_112 [ 0 ] = F_54 ( V_11 ) ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_60 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 ;
unsigned int V_13 ;
if ( ! F_10 ( V_11 ) )
return - V_49 ;
V_13 = V_99 -> V_100 . V_110 . V_112 [ 0 ] % 3 ;
F_24 ( & V_11 -> V_17 ) ;
V_103 = V_13 != F_54 ( V_11 ) ;
if ( V_103 )
F_56 ( V_11 , V_13 ) ;
F_26 ( & V_11 -> V_17 ) ;
return V_103 ;
}
static int F_61 ( struct V_10 * V_11 )
{
return ( V_11 -> V_23 & V_116 ) ? 1 : 0 ;
}
static int F_62 ( struct V_10 * V_11 , int V_117 )
{
int V_43 = 0 ;
if ( V_117 ) {
V_11 -> V_23 |= V_116 ;
} else {
V_11 -> V_23 &= ~ V_116 ;
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
static int F_63 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_99 -> V_100 . integer . V_100 [ 0 ] = F_61 ( V_11 ) ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_64 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 ;
unsigned int V_13 ;
if ( ! F_10 ( V_11 ) )
return - V_49 ;
V_13 = V_99 -> V_100 . integer . V_100 [ 0 ] & 1 ;
F_24 ( & V_11 -> V_17 ) ;
V_103 = ( int ) V_13 != F_61 ( V_11 ) ;
F_62 ( V_11 , V_13 ) ;
F_26 ( & V_11 -> V_17 ) ;
return V_103 ;
}
static int F_65 ( struct V_10 * V_11 )
{
if ( V_11 -> V_23 & V_118 ) {
return 2 ;
} else if ( V_11 -> V_23 & V_119 ) {
return 1 ;
} else {
return 0 ;
}
}
static int F_66 ( struct V_10 * V_11 , int V_120 )
{
int V_43 = 0 ;
switch ( V_120 ) {
case 0 :
V_11 -> V_23 &=
~ ( V_119 | V_118 ) ;
break;
case 1 :
V_11 -> V_23 =
( V_11 -> V_23 & ~ V_118 ) | V_119 ;
break;
case 2 :
V_11 -> V_23 |=
( V_119 | V_118 ) ;
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
static int F_67 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
static char * V_108 [ 3 ] = { L_7 , L_8 , L_9 } ;
V_95 -> type = V_109 ;
V_95 -> V_97 = 1 ;
V_95 -> V_100 . V_110 . V_111 = 3 ;
if ( V_95 -> V_100 . V_110 . V_112 > 2 )
V_95 -> V_100 . V_110 . V_112 = 2 ;
strcpy ( V_95 -> V_100 . V_110 . V_113 , V_108 [ V_95 -> V_100 . V_110 . V_112 ] ) ;
return 0 ;
}
static int F_68 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_99 -> V_100 . V_110 . V_112 [ 0 ] = F_65 ( V_11 ) ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_69 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 ;
unsigned int V_13 ;
V_13 = V_99 -> V_100 . V_110 . V_112 [ 0 ] % 3 ;
F_24 ( & V_11 -> V_17 ) ;
V_103 = ( int ) V_13 != F_65 ( V_11 ) ;
F_66 ( V_11 , V_13 ) ;
F_26 ( & V_11 -> V_17 ) ;
return V_103 ;
}
static int F_70 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_23 & V_121 ) {
case V_122 :
return V_123 ;
case V_124 :
return V_125 ;
case V_126 :
return V_127 ;
case V_128 :
return V_129 ;
}
return 0 ;
}
static int F_71 ( struct V_10 * V_11 , int V_130 )
{
int V_43 ;
V_11 -> V_23 &= ~ V_121 ;
switch ( V_130 ) {
case V_123 :
V_11 -> V_23 |= V_122 ;
break;
case V_125 :
V_11 -> V_23 |= V_124 ;
break;
case V_127 :
V_11 -> V_23 |= V_126 ;
break;
case V_129 :
V_11 -> V_23 |= V_128 ;
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
static int F_72 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
static char * V_108 [ 4 ] = { L_10 , L_11 , L_12 , L_13 } ;
struct V_10 * V_11 = F_42 ( V_93 ) ;
V_95 -> type = V_109 ;
V_95 -> V_97 = 1 ;
V_95 -> V_100 . V_110 . V_111 = V_11 -> V_53 == V_54 ? 4 : 3 ;
if ( V_95 -> V_100 . V_110 . V_112 >= V_95 -> V_100 . V_110 . V_111 )
V_95 -> V_100 . V_110 . V_112 = V_95 -> V_100 . V_110 . V_111 - 1 ;
strcpy ( V_95 -> V_100 . V_110 . V_113 , V_108 [ V_95 -> V_100 . V_110 . V_112 ] ) ;
return 0 ;
}
static int F_73 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_99 -> V_100 . V_110 . V_112 [ 0 ] = F_70 ( V_11 ) ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_74 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 , V_131 ;
unsigned int V_13 ;
if ( ! F_10 ( V_11 ) )
return - V_49 ;
V_131 = V_11 -> V_53 == V_54 ? 4 : 3 ;
V_13 = V_99 -> V_100 . V_110 . V_112 [ 0 ] % V_131 ;
F_24 ( & V_11 -> V_17 ) ;
V_103 = ( int ) V_13 != F_70 ( V_11 ) ;
F_71 ( V_11 , V_13 ) ;
F_26 ( & V_11 -> V_17 ) ;
return V_103 ;
}
static int F_75 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
V_95 -> type = V_132 ;
V_95 -> V_97 = V_11 -> V_53 ;
V_95 -> V_100 . integer . V_133 = 0 ;
V_95 -> V_100 . integer . V_131 = 1 ;
return 0 ;
}
static int F_76 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
unsigned int V_134 ;
T_4 V_63 = V_11 -> V_63 ;
for ( V_134 = 0 ; V_134 < V_11 -> V_53 ; ++ V_134 ) {
V_99 -> V_100 . integer . V_100 [ V_134 ] = ! ! ( V_63 & ( 1 << V_134 ) ) ;
}
return 0 ;
}
static int F_77 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 ;
unsigned int V_135 ;
T_4 V_63 = 0 ;
if ( ! F_10 ( V_11 ) )
return - V_49 ;
for ( V_135 = 0 ; V_135 < V_11 -> V_53 ; ++ V_135 ) {
if ( V_99 -> V_100 . integer . V_100 [ V_135 ] )
V_63 |= 1 << V_135 ;
}
F_24 ( & V_11 -> V_17 ) ;
V_103 = V_63 ^ V_11 -> V_63 ;
if ( V_103 ) {
for ( V_135 = 0 ; V_135 < V_11 -> V_53 ; ++ V_135 ) {
if ( ! ( V_103 & ( 1 << V_135 ) ) )
continue;
F_28 ( V_11 , V_135 , V_63 & ( 1 << V_135 ) ) ;
}
}
F_26 ( & V_11 -> V_17 ) ;
return ! ! V_103 ;
}
static int F_78 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_99 -> V_100 . integer . V_100 [ 0 ] = V_11 -> V_62 ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_79 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
int V_103 ;
unsigned int V_13 ;
int V_136 = 0 ;
if ( ! F_10 ( V_11 ) )
return - V_49 ;
V_13 = V_99 -> V_100 . integer . V_100 [ 0 ] & 1 ;
F_24 ( & V_11 -> V_17 ) ;
V_103 = ( V_99 -> V_100 . integer . V_100 [ 0 ] != V_11 -> V_62 ) ;
if ( V_103 )
V_136 = F_29 ( V_11 , V_13 ) ;
F_26 ( & V_11 -> V_17 ) ;
return V_136 ? V_136 : V_103 ;
}
static int F_80 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
V_95 -> type = V_137 ;
V_95 -> V_97 = 1 ;
V_95 -> V_100 . integer . V_133 = 0 ;
V_95 -> V_100 . integer . V_131 = 96000 ;
return 0 ;
}
static int F_81 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_99 -> V_100 . integer . V_100 [ 0 ] = F_36 ( V_11 ) ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_82 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
static char * V_108 [ 4 ] = { L_14 , L_15 , L_16 , L_17 } ;
V_95 -> type = V_109 ;
V_95 -> V_97 = 1 ;
V_95 -> V_100 . V_110 . V_111 = 4 ;
if ( V_95 -> V_100 . V_110 . V_112 >= V_95 -> V_100 . V_110 . V_111 )
V_95 -> V_100 . V_110 . V_112 = V_95 -> V_100 . V_110 . V_111 - 1 ;
strcpy ( V_95 -> V_100 . V_110 . V_113 , V_108 [ V_95 -> V_100 . V_110 . V_112 ] ) ;
return 0 ;
}
static int F_83 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
unsigned int V_138 , V_139 , V_13 ;
switch ( V_93 -> V_105 ) {
case 0 : V_138 = V_140 ; V_139 = V_141 ; break;
case 1 : V_138 = V_142 ; V_139 = V_143 ; break;
case 2 : V_138 = V_144 ; V_139 = V_145 ; break;
default: return - V_52 ;
}
V_13 = F_8 ( V_11 , V_20 ) ;
V_99 -> V_100 . V_110 . V_112 [ 0 ] = ( V_13 & V_138 ) ? 1 : 0 ;
V_99 -> V_100 . V_110 . V_112 [ 0 ] |= ( V_13 & V_139 ) ? 2 : 0 ;
return 0 ;
}
static int F_84 ( struct V_92 * V_93 , struct V_98 * V_99 )
{
struct V_10 * V_11 = F_42 ( V_93 ) ;
V_99 -> V_100 . integer . V_100 [ 0 ] =
( F_8 ( V_11 , V_20 ) & V_146 ) ? 1 : 0 ;
return 0 ;
}
static int F_85 ( void * V_147 ,
T_5 * V_148 ,
T_6 * V_149 )
{
struct V_10 * V_38 = (struct V_10 * ) V_147 ;
T_4 V_100 ;
int V_22 ;
V_149 -> type = V_150 ;
if ( ( F_8 ( V_38 , V_20 ) &
V_146 ) == 0 ) {
V_149 -> V_100 . V_151 [ 0 ] = 0 ;
return 0 ;
}
F_6 ( V_38 , V_152 , 0 ) ;
for ( V_22 = 0 ; V_22 < 50 ; V_22 ++ ) {
if ( ! ( F_8 ( V_38 , V_22 * 4 ) & V_153 ) )
break;
}
if ( ! ( F_8 ( V_38 , V_22 * 4 ) & V_153 ) ) {
return - V_154 ;
}
V_100 = 0 ;
for ( V_22 = 0 ; V_22 < 32 ; V_22 ++ ) {
V_100 >>= 1 ;
if ( F_8 ( V_38 , V_22 * 4 ) & V_155 )
V_100 |= 0x80000000 ;
}
if ( V_100 > 2 * 60 * 48000 ) {
V_100 -= 2 * 60 * 48000 ;
} else {
V_100 = 0 ;
}
V_149 -> V_100 . V_151 [ 0 ] = V_100 ;
return 0 ;
}
static int F_86 ( struct V_156 * V_37 , struct V_10 * V_11 )
{
unsigned int V_157 ;
int V_136 ;
struct V_92 * V_158 ;
for ( V_157 = 0 ; V_157 < F_87 ( V_159 ) ; V_157 ++ ) {
if ( ( V_136 = F_88 ( V_37 , V_158 = F_89 ( & V_159 [ V_157 ] , V_11 ) ) ) < 0 )
return V_136 ;
if ( V_157 == 1 )
V_11 -> V_160 = V_158 ;
}
if ( V_11 -> V_53 == V_54 )
if ( ( V_136 = F_88 ( V_37 , V_158 = F_89 ( & V_161 , V_11 ) ) ) < 0 )
return V_136 ;
if ( V_11 -> V_78 >= 15 )
if ( ( V_136 = F_88 ( V_37 , V_158 = F_89 ( & V_162 , V_11 ) ) ) < 0 )
return V_136 ;
return 0 ;
}
static void
F_90 ( struct V_163 * V_164 , struct V_165 * V_166 )
{
struct V_10 * V_11 = (struct V_10 * ) V_164 -> V_147 ;
T_4 V_63 = V_11 -> V_63 ;
int V_167 = 0 ;
int V_22 ;
unsigned int V_29 ;
int V_79 ;
V_29 = F_8 ( V_11 , V_20 ) ;
F_91 ( V_166 , L_18 , V_11 -> V_82 , V_11 -> V_37 -> V_168 + 1 ) ;
F_91 ( V_166 , L_19 ,
V_11 -> V_169 , V_11 -> V_170 ) ;
F_91 ( V_166 , L_20 ,
V_11 -> V_171 , V_11 -> V_172 , ( unsigned long ) V_11 -> V_14 ) ;
F_91 ( V_166 , L_21 , V_11 -> V_23 ) ;
F_91 ( V_166 , L_22 ) ;
V_79 = 1 << ( 6 + F_16 ( V_11 -> V_23 &
V_24 ) ) ;
F_91 ( V_166 , L_23 ,
V_79 , ( unsigned long ) V_11 -> V_25 ) ;
F_91 ( V_166 , L_24 ,
F_17 ( V_11 ) ) ;
F_91 ( V_166 , L_25 ,
V_11 -> V_62 ? L_26 : L_27 ) ;
if ( ( V_11 -> V_23 & ( V_119 | V_118 ) ) == 0 ) {
F_91 ( V_166 , L_28 ) ;
V_167 = 1 ;
} else if ( V_11 -> V_23 & V_118 ) {
if ( V_29 & V_173 ) {
F_91 ( V_166 , L_29 ) ;
} else {
F_91 ( V_166 , L_30 ) ;
}
} else {
F_91 ( V_166 , L_31 ) ;
}
if ( V_167 ) {
switch ( V_11 -> V_23 & V_121 ) {
case V_122 :
F_91 ( V_166 , L_32 ) ;
break;
case V_124 :
F_91 ( V_166 , L_33 ) ;
break;
case V_126 :
F_91 ( V_166 , L_34 ) ;
break;
case V_128 :
F_91 ( V_166 , L_35 ) ;
break;
default:
F_91 ( V_166 , L_36 ) ;
}
}
if ( V_11 -> V_78 >= 15 )
F_91 ( V_166 , L_37 ,
( V_11 -> V_23 & V_106 ) ?
L_5 : L_38 ) ;
F_91 ( V_166 , L_22 ) ;
switch ( F_55 ( V_11 -> V_23 &
V_114 ) ) {
case V_174 :
F_91 ( V_166 , L_39 ) ;
break;
case V_175 :
F_91 ( V_166 , L_40 ) ;
break;
case V_176 :
F_91 ( V_166 , L_41 ) ;
break;
default:
F_91 ( V_166 , L_42 ) ;
break;
}
if ( V_11 -> V_23 & V_116 ) {
F_91 ( V_166 , L_43 ) ;
} else {
F_91 ( V_166 , L_44 ) ;
}
if ( V_11 -> V_23 & V_86 ) {
F_91 ( V_166 , L_45 ) ;
} else {
F_91 ( V_166 , L_46 ) ;
}
if ( V_11 -> V_23 & V_90 ) {
F_91 ( V_166 , L_47 ) ;
} else {
F_91 ( V_166 , L_48 ) ;
}
if ( V_11 -> V_23 & V_88 ) {
F_91 ( V_166 , L_49 ) ;
} else {
F_91 ( V_166 , L_50 ) ;
}
V_22 = F_36 ( V_11 ) ;
if ( V_22 < 0 ) {
F_91 ( V_166 ,
L_51 ) ;
} else if ( V_22 == 0 ) {
F_91 ( V_166 , L_52 ) ;
} else {
F_91 ( V_166 , L_53 , V_22 ) ;
}
F_91 ( V_166 , L_22 ) ;
F_91 ( V_166 , L_54 ,
F_13 ( V_11 ) ) ;
V_79 = V_29 & V_141 ;
if ( V_29 & V_140 ) {
F_91 ( V_166 , L_55 , V_79 ? L_56 : L_15 ) ;
} else {
F_91 ( V_166 , L_57 ) ;
}
V_79 = V_29 & V_143 ;
if ( V_29 & V_142 ) {
F_91 ( V_166 , L_58 , V_79 ? L_56 : L_15 ) ;
} else {
F_91 ( V_166 , L_59 ) ;
}
V_79 = V_29 & V_145 ;
if ( V_29 & V_144 ) {
F_91 ( V_166 , L_60 , V_79 ? L_56 : L_15 ) ;
} else {
F_91 ( V_166 , L_61 ) ;
}
F_91 ( V_166 , L_22 ) ;
F_91 ( V_166 , L_62 ,
( V_29 & V_146 ) ? L_26 : L_27 ) ;
F_91 ( V_166 , L_63 ) ;
for ( V_22 = 0 ; V_22 < V_11 -> V_53 ; V_22 ++ ) {
if ( V_63 & ( 1 << V_22 ) ) {
F_91 ( V_166 , L_64 , V_22 + 1 ) ;
} else {
F_91 ( V_166 , L_65 , V_22 + 1 ) ;
}
if ( ( ( V_22 + 1 ) % 8 ) == 0 ) {
F_91 ( V_166 , L_22 ) ;
}
}
F_91 ( V_166 , L_22 ) ;
}
static void F_92 ( struct V_10 * V_11 )
{
struct V_163 * V_164 ;
if ( ! F_93 ( V_11 -> V_37 , L_66 , & V_164 ) )
F_94 ( V_164 , V_11 , F_90 ) ;
}
static void F_95 ( struct V_10 * V_11 )
{
F_4 ( & V_11 -> V_177 , V_11 -> V_2 ) ;
F_4 ( & V_11 -> V_178 , V_11 -> V_2 ) ;
}
static int F_96 ( struct V_10 * V_11 )
{
if ( V_11 -> V_171 >= 0 )
F_22 ( V_11 ) ;
F_95 ( V_11 ) ;
if ( V_11 -> V_171 >= 0 )
F_97 ( V_11 -> V_171 , ( void * ) V_11 ) ;
if ( V_11 -> V_14 )
F_98 ( V_11 -> V_14 ) ;
if ( V_11 -> V_172 )
F_99 ( V_11 -> V_2 ) ;
F_100 ( V_11 -> V_2 ) ;
return 0 ;
}
static int F_101 ( struct V_10 * V_11 )
{
unsigned long V_179 , V_180 ;
if ( F_1 ( V_11 -> V_2 , & V_11 -> V_177 , V_181 ) < 0 ||
F_1 ( V_11 -> V_2 , & V_11 -> V_178 , V_181 ) < 0 ) {
if ( V_11 -> V_177 . V_9 )
F_5 ( & V_11 -> V_177 ) ;
F_18 ( V_11 -> V_37 -> V_6 ,
L_67 , V_11 -> V_82 ) ;
return - V_8 ;
}
V_180 = F_102 ( V_11 -> V_177 . V_182 , 0x10000ul ) ;
V_179 = F_102 ( V_11 -> V_178 . V_182 , 0x10000ul ) ;
F_6 ( V_11 , V_183 , V_180 ) ;
F_6 ( V_11 , V_184 , V_179 ) ;
V_11 -> V_169 = V_11 -> V_177 . V_9 + ( V_180 - V_11 -> V_177 . V_182 ) ;
V_11 -> V_170 = V_11 -> V_178 . V_9 + ( V_179 - V_11 -> V_178 . V_182 ) ;
return 0 ;
}
static void F_103 ( struct V_10 * V_11 )
{
unsigned int V_134 ;
V_11 -> V_23 =
V_67 | F_25 ( 7 ) ;
F_6 ( V_11 , V_41 , V_11 -> V_23 ) ;
F_19 ( V_11 ) ;
F_15 ( V_11 ) ;
for ( V_134 = 0 ; V_134 < V_54 ; ++ V_134 )
F_6 ( V_11 , V_64 + V_134 * 4 , 0 ) ;
V_11 -> V_63 = 0 ;
V_11 -> V_62 = 0 ;
F_27 ( V_11 , 48000 ) ;
}
static T_7 F_104 ( int V_171 , void * V_185 )
{
struct V_10 * V_11 = (struct V_10 * ) V_185 ;
if ( ! ( F_8 ( V_11 , V_20 ) & V_186 ) ) {
return V_187 ;
}
F_6 ( V_11 , V_188 , 0 ) ;
if ( V_11 -> V_189 ) {
F_105 ( V_11 -> V_190 -> V_191 [ V_192 ] . V_193 ) ;
}
if ( V_11 -> V_194 ) {
F_105 ( V_11 -> V_190 -> V_191 [ V_195 ] . V_193 ) ;
}
return V_196 ;
}
static T_2 F_106 ( struct V_197 * V_193 )
{
struct V_10 * V_11 = F_107 ( V_193 ) ;
return F_17 ( V_11 ) ;
}
static char * F_108 ( struct V_10 * V_11 ,
int V_198 ,
int V_60 )
{
int V_65 ;
if ( F_109 ( V_60 < 0 || V_60 >= V_54 ) )
return NULL ;
if ( ( V_65 = V_11 -> V_55 [ V_60 ] ) < 0 ) {
return NULL ;
}
if ( V_198 == V_192 ) {
return V_11 -> V_169 +
( V_65 * V_199 ) ;
} else {
return V_11 -> V_170 +
( V_65 * V_199 ) ;
}
}
static int F_110 ( struct V_197 * V_193 , int V_60 ,
T_2 V_200 , void T_8 * V_201 , T_2 V_97 )
{
struct V_10 * V_11 = F_107 ( V_193 ) ;
char * V_202 ;
if ( F_109 ( V_200 + V_97 > V_199 / 4 ) )
return - V_52 ;
V_202 = F_108 ( V_11 ,
V_193 -> V_203 -> V_198 ,
V_60 ) ;
if ( F_109 ( ! V_202 ) )
return - V_154 ;
if ( F_111 ( V_202 + V_200 * 4 , V_201 , V_97 * 4 ) )
return - V_204 ;
return V_97 ;
}
static int F_112 ( struct V_197 * V_193 , int V_60 ,
T_2 V_200 , void T_8 * V_205 , T_2 V_97 )
{
struct V_10 * V_11 = F_107 ( V_193 ) ;
char * V_202 ;
if ( F_109 ( V_200 + V_97 > V_199 / 4 ) )
return - V_52 ;
V_202 = F_108 ( V_11 ,
V_193 -> V_203 -> V_198 ,
V_60 ) ;
if ( F_109 ( ! V_202 ) )
return - V_154 ;
if ( F_113 ( V_205 , V_202 + V_200 * 4 , V_97 * 4 ) )
return - V_204 ;
return V_97 ;
}
static int F_114 ( struct V_197 * V_193 , int V_60 ,
T_2 V_200 , T_2 V_97 )
{
struct V_10 * V_11 = F_107 ( V_193 ) ;
char * V_202 ;
V_202 = F_108 ( V_11 ,
V_193 -> V_203 -> V_198 ,
V_60 ) ;
if ( F_109 ( ! V_202 ) )
return - V_154 ;
memset ( V_202 + V_200 * 4 , 0 , V_97 * 4 ) ;
return V_97 ;
}
static int F_115 ( struct V_197 * V_193 )
{
struct V_206 * V_207 = V_193 -> V_207 ;
struct V_10 * V_11 = F_107 ( V_193 ) ;
struct V_197 * V_208 ;
if ( V_193 -> V_198 == V_195 )
V_208 = V_11 -> V_189 ;
else
V_208 = V_11 -> V_194 ;
if ( V_11 -> V_45 )
V_207 -> V_29 -> V_209 = F_17 ( V_11 ) ;
else
V_207 -> V_29 -> V_209 = 0 ;
if ( V_208 ) {
struct V_197 * V_38 ;
struct V_206 * V_210 = V_208 -> V_207 ;
F_116 (s, substream) {
if ( V_38 == V_208 ) {
V_210 -> V_29 -> V_209 = V_207 -> V_29 -> V_209 ;
break;
}
}
}
return 0 ;
}
static int F_117 ( struct V_197 * V_193 ,
struct V_211 * V_212 )
{
struct V_10 * V_11 = F_107 ( V_193 ) ;
int V_136 ;
T_9 V_213 ;
T_9 V_214 ;
F_24 ( & V_11 -> V_17 ) ;
if ( V_193 -> V_203 -> V_198 == V_195 ) {
V_11 -> V_23 &= ~ ( V_86 | V_88 | V_90 ) ;
F_6 ( V_11 , V_41 , V_11 -> V_23 |= V_11 -> V_104 ) ;
V_213 = V_11 -> V_18 ;
V_214 = V_11 -> V_19 ;
} else {
V_213 = V_11 -> V_19 ;
V_214 = V_11 -> V_18 ;
}
if ( ( V_214 > 0 ) && ( V_213 != V_214 ) ) {
if ( ( int ) F_118 ( V_212 ) !=
F_13 ( V_11 ) ) {
F_26 ( & V_11 -> V_17 ) ;
F_119 ( V_212 , V_215 ) ;
return - V_49 ;
}
if ( F_120 ( V_212 ) != V_11 -> V_25 / 4 ) {
F_26 ( & V_11 -> V_17 ) ;
F_119 ( V_212 , V_216 ) ;
return - V_49 ;
}
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
} else {
F_26 ( & V_11 -> V_17 ) ;
}
if ( ( V_136 = F_27 ( V_11 , F_118 ( V_212 ) ) ) < 0 ) {
F_119 ( V_212 , V_215 ) ;
return V_136 ;
}
if ( ( V_136 = F_23 ( V_11 , F_120 ( V_212 ) ) ) < 0 ) {
F_119 ( V_212 , V_216 ) ;
return V_136 ;
}
return 0 ;
}
static int F_121 ( struct V_197 * V_193 ,
struct V_217 * V_218 )
{
struct V_10 * V_11 = F_107 ( V_193 ) ;
int V_135 ;
if ( F_109 ( V_218 -> V_60 >= V_54 ) )
return - V_52 ;
if ( ( V_135 = V_11 -> V_55 [ V_218 -> V_60 ] ) < 0 ) {
return - V_52 ;
}
V_218 -> V_30 = V_135 * V_199 ;
V_218 -> V_219 = 0 ;
V_218 -> V_220 = 32 ;
return 0 ;
}
static int F_122 ( struct V_197 * V_193 ,
unsigned int V_221 , void * V_222 )
{
switch ( V_221 ) {
case V_223 :
{
return F_115 ( V_193 ) ;
}
case V_224 :
{
struct V_217 * V_218 = V_222 ;
return F_121 ( V_193 , V_218 ) ;
}
default:
break;
}
return F_123 ( V_193 , V_221 , V_222 ) ;
}
static void F_124 ( struct V_10 * V_11 )
{
memset ( V_11 -> V_170 , 0 , V_181 ) ;
}
static int F_125 ( struct V_197 * V_193 ,
int V_221 )
{
struct V_10 * V_11 = F_107 ( V_193 ) ;
struct V_197 * V_208 ;
int V_45 ;
F_126 ( & V_11 -> V_17 ) ;
V_45 = V_11 -> V_45 ;
switch ( V_221 ) {
case V_225 :
V_45 |= 1 << V_193 -> V_198 ;
break;
case V_226 :
V_45 &= ~ ( 1 << V_193 -> V_198 ) ;
break;
default:
F_127 () ;
F_128 ( & V_11 -> V_17 ) ;
return - V_52 ;
}
if ( V_193 -> V_198 == V_195 )
V_208 = V_11 -> V_189 ;
else
V_208 = V_11 -> V_194 ;
if ( V_208 ) {
struct V_197 * V_38 ;
F_116 (s, substream) {
if ( V_38 == V_208 ) {
F_129 ( V_38 , V_193 ) ;
if ( V_221 == V_225 )
V_45 |= 1 << V_38 -> V_198 ;
else
V_45 &= ~ ( 1 << V_38 -> V_198 ) ;
goto V_227;
}
}
if ( V_221 == V_225 ) {
if ( ! ( V_45 & ( 1 << V_195 ) ) &&
V_193 -> V_198 == V_192 )
F_124 ( V_11 ) ;
} else {
if ( V_45 &&
V_193 -> V_198 == V_195 )
F_124 ( V_11 ) ;
}
} else {
if ( V_193 -> V_198 == V_192 )
F_124 ( V_11 ) ;
}
V_227:
F_129 ( V_193 , V_193 ) ;
if ( ! V_11 -> V_45 && V_45 )
F_21 ( V_11 ) ;
else if ( V_11 -> V_45 && ! V_45 )
F_22 ( V_11 ) ;
V_11 -> V_45 = V_45 ;
F_128 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_130 ( struct V_197 * V_193 )
{
struct V_10 * V_11 = F_107 ( V_193 ) ;
unsigned long V_15 ;
int V_228 = 0 ;
F_11 ( & V_11 -> V_17 , V_15 ) ;
if ( ! V_11 -> V_45 )
F_19 ( V_11 ) ;
F_12 ( & V_11 -> V_17 , V_15 ) ;
return V_228 ;
}
static int F_131 ( struct V_211 * V_212 ,
struct V_229 * V_230 )
{
struct V_10 * V_11 = V_230 -> V_231 ;
struct V_232 * V_233 = F_132 ( V_212 , V_234 ) ;
unsigned int V_235 [ 2 ] = { V_11 -> V_236 , V_11 -> V_53 } ;
return F_133 ( V_233 , 2 , V_235 , 0 ) ;
}
static int F_134 ( struct V_211 * V_212 ,
struct V_229 * V_230 )
{
struct V_10 * V_11 = V_230 -> V_231 ;
struct V_232 * V_233 = F_132 ( V_212 , V_234 ) ;
struct V_232 * V_237 = F_132 ( V_212 , V_215 ) ;
if ( V_237 -> V_133 > 48000 ) {
struct V_232 V_238 = {
. V_133 = V_11 -> V_236 ,
. V_131 = V_11 -> V_236 ,
. integer = 1 ,
} ;
return F_135 ( V_233 , & V_238 ) ;
} else if ( V_237 -> V_131 < 88200 ) {
struct V_232 V_238 = {
. V_133 = V_11 -> V_53 ,
. V_131 = V_11 -> V_53 ,
. integer = 1 ,
} ;
return F_135 ( V_233 , & V_238 ) ;
}
return 0 ;
}
static int F_136 ( struct V_211 * V_212 ,
struct V_229 * V_230 )
{
struct V_10 * V_11 = V_230 -> V_231 ;
struct V_232 * V_233 = F_132 ( V_212 , V_234 ) ;
struct V_232 * V_237 = F_132 ( V_212 , V_215 ) ;
if ( V_233 -> V_133 >= V_11 -> V_53 ) {
struct V_232 V_238 = {
. V_133 = 44100 ,
. V_131 = 48000 ,
. integer = 1 ,
} ;
return F_135 ( V_237 , & V_238 ) ;
} else if ( V_233 -> V_131 <= V_11 -> V_236 ) {
struct V_232 V_238 = {
. V_133 = 88200 ,
. V_131 = 96000 ,
. integer = 1 ,
} ;
return F_135 ( V_237 , & V_238 ) ;
}
return 0 ;
}
static int F_137 ( struct V_197 * V_193 )
{
struct V_10 * V_11 = F_107 ( V_193 ) ;
struct V_206 * V_207 = V_193 -> V_207 ;
F_24 ( & V_11 -> V_17 ) ;
F_138 ( V_193 ) ;
V_207 -> V_239 = V_240 ;
V_207 -> V_241 = V_11 -> V_170 ;
V_207 -> V_242 = V_181 ;
if ( V_11 -> V_189 == NULL ) {
F_22 ( V_11 ) ;
F_28 ( V_11 , - 1 , 0 ) ;
}
V_11 -> V_18 = V_243 -> V_244 ;
V_11 -> V_194 = V_193 ;
F_26 ( & V_11 -> V_17 ) ;
F_139 ( V_207 , 0 , 32 , 24 ) ;
F_140 ( V_207 , 0 , V_216 , & V_245 ) ;
F_141 ( V_207 , 0 , V_234 ,
F_131 , V_11 ,
V_234 , - 1 ) ;
F_141 ( V_207 , 0 , V_234 ,
F_134 , V_11 ,
V_215 , - 1 ) ;
F_141 ( V_207 , 0 , V_215 ,
F_136 , V_11 ,
V_234 , - 1 ) ;
V_11 -> V_104 = V_11 -> V_102 ;
V_11 -> V_160 -> V_246 [ 0 ] . V_247 &= ~ V_248 ;
F_142 ( V_11 -> V_37 , V_249 |
V_250 , & V_11 -> V_160 -> V_251 ) ;
return 0 ;
}
static int F_143 ( struct V_197 * V_193 )
{
struct V_10 * V_11 = F_107 ( V_193 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_11 -> V_18 = - 1 ;
V_11 -> V_194 = NULL ;
F_26 ( & V_11 -> V_17 ) ;
V_11 -> V_160 -> V_246 [ 0 ] . V_247 |= V_248 ;
F_142 ( V_11 -> V_37 , V_249 |
V_250 , & V_11 -> V_160 -> V_251 ) ;
return 0 ;
}
static int F_144 ( struct V_197 * V_193 )
{
struct V_10 * V_11 = F_107 ( V_193 ) ;
struct V_206 * V_207 = V_193 -> V_207 ;
F_24 ( & V_11 -> V_17 ) ;
F_138 ( V_193 ) ;
V_207 -> V_239 = V_252 ;
V_207 -> V_241 = V_11 -> V_169 ;
V_207 -> V_242 = V_181 ;
if ( V_11 -> V_194 == NULL ) {
F_22 ( V_11 ) ;
F_28 ( V_11 , - 1 , 0 ) ;
}
V_11 -> V_19 = V_243 -> V_244 ;
V_11 -> V_189 = V_193 ;
F_26 ( & V_11 -> V_17 ) ;
F_139 ( V_207 , 0 , 32 , 24 ) ;
F_140 ( V_207 , 0 , V_216 , & V_245 ) ;
F_141 ( V_207 , 0 , V_234 ,
F_131 , V_11 ,
V_234 , - 1 ) ;
F_141 ( V_207 , 0 , V_234 ,
F_134 , V_11 ,
V_215 , - 1 ) ;
F_141 ( V_207 , 0 , V_215 ,
F_136 , V_11 ,
V_234 , - 1 ) ;
return 0 ;
}
static int F_145 ( struct V_197 * V_193 )
{
struct V_10 * V_11 = F_107 ( V_193 ) ;
F_24 ( & V_11 -> V_17 ) ;
V_11 -> V_19 = - 1 ;
V_11 -> V_189 = NULL ;
F_26 ( & V_11 -> V_17 ) ;
return 0 ;
}
static int F_146 ( struct V_156 * V_37 ,
struct V_10 * V_11 )
{
struct V_253 * V_190 ;
int V_136 ;
if ( ( V_136 = F_147 ( V_37 ,
V_11 -> V_82 ,
0 , 1 , 1 , & V_190 ) ) < 0 ) {
return V_136 ;
}
V_11 -> V_190 = V_190 ;
V_190 -> V_147 = V_11 ;
strcpy ( V_190 -> V_113 , V_11 -> V_82 ) ;
F_148 ( V_190 , V_195 , & V_254 ) ;
F_148 ( V_190 , V_192 , & V_255 ) ;
V_190 -> V_256 = V_257 ;
return 0 ;
}
static int F_149 ( struct V_156 * V_37 ,
struct V_10 * V_11 ,
int V_34 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_136 ;
int V_29 ;
unsigned short V_258 ;
V_11 -> V_171 = - 1 ;
V_11 -> V_37 = V_37 ;
F_150 ( V_11 -> V_2 , V_259 , & V_258 ) ;
switch ( V_258 & 0xff ) {
case 3 :
case 4 :
case 8 :
case 9 :
break;
default:
return - V_260 ;
}
if ( ( V_136 = F_151 ( V_2 ) ) < 0 )
return V_136 ;
F_152 ( & V_11 -> V_17 ) ;
if ( ( V_136 = F_153 ( V_2 , L_66 ) ) < 0 )
return V_136 ;
V_11 -> V_172 = F_154 ( V_2 , 0 ) ;
V_11 -> V_14 = F_155 ( V_11 -> V_172 , V_261 ) ;
if ( V_11 -> V_14 == NULL ) {
F_18 ( V_37 -> V_6 , L_68 ,
V_11 -> V_172 , V_11 -> V_172 + V_261 - 1 ) ;
return - V_49 ;
}
if ( F_156 ( V_2 -> V_171 , F_104 , V_262 ,
V_263 , V_11 ) ) {
F_18 ( V_37 -> V_6 , L_69 , V_2 -> V_171 ) ;
return - V_49 ;
}
V_11 -> V_171 = V_2 -> V_171 ;
V_11 -> V_34 = V_34 ;
V_29 = F_8 ( V_11 , V_20 ) ;
if ( F_37 ( V_29 & V_81 ) == 1 ) {
V_11 -> V_78 = 15 ;
} else {
V_11 -> V_78 = 11 ;
}
switch ( V_258 ) {
case 8 :
strcpy ( V_37 -> V_264 , L_70 ) ;
if ( V_11 -> V_78 == 15 ) {
V_11 -> V_82 = L_71 ;
} else {
V_11 -> V_82 = L_72 ;
}
V_11 -> V_53 = V_265 ;
break;
case 9 :
strcpy ( V_37 -> V_264 , L_70 ) ;
V_11 -> V_82 = L_73 ;
V_11 -> V_53 = V_265 ;
break;
case 4 :
strcpy ( V_37 -> V_264 , L_74 ) ;
V_11 -> V_82 = L_75 ;
V_11 -> V_53 = V_54 ;
break;
case 3 :
strcpy ( V_37 -> V_264 , L_74 ) ;
if ( V_11 -> V_78 == 15 ) {
V_11 -> V_82 = L_76 ;
} else {
V_11 -> V_82 = L_77 ;
}
V_11 -> V_53 = V_54 ;
break;
}
V_11 -> V_236 = ( V_11 -> V_53 - 2 ) / 2 + 2 ;
F_157 ( V_11 -> V_2 ) ;
if ( ( V_136 = F_101 ( V_11 ) ) < 0 ) {
return V_136 ;
}
if ( ( V_136 = F_146 ( V_37 , V_11 ) ) < 0 ) {
return V_136 ;
}
if ( ( V_136 = F_86 ( V_37 , V_11 ) ) < 0 ) {
return V_136 ;
}
F_92 ( V_11 ) ;
V_11 -> V_266 = - 1 ;
V_11 -> V_267 = - 1 ;
V_11 -> V_18 = - 1 ;
V_11 -> V_19 = - 1 ;
V_11 -> V_189 = NULL ;
V_11 -> V_194 = NULL ;
F_103 ( V_11 ) ;
if ( V_11 -> V_78 == 15 ) {
F_35 ( V_11 ) ;
}
return 0 ;
}
static void F_158 ( struct V_156 * V_37 )
{
struct V_10 * V_11 = (struct V_10 * ) V_37 -> V_147 ;
if ( V_11 )
F_96 ( V_11 ) ;
}
static int F_159 ( struct V_1 * V_2 ,
const struct V_268 * V_269 )
{
static int V_6 ;
struct V_10 * V_11 ;
struct V_156 * V_37 ;
int V_136 ;
if ( V_6 >= V_270 )
return - V_260 ;
if ( ! V_61 [ V_6 ] ) {
V_6 ++ ;
return - V_271 ;
}
V_136 = F_160 ( & V_2 -> V_6 , V_272 [ V_6 ] , V_251 [ V_6 ] , V_273 ,
sizeof( struct V_10 ) , & V_37 ) ;
if ( V_136 < 0 )
return V_136 ;
V_11 = (struct V_10 * ) V_37 -> V_147 ;
V_37 -> V_274 = F_158 ;
V_11 -> V_6 = V_6 ;
V_11 -> V_2 = V_2 ;
if ( ( V_136 = F_149 ( V_37 , V_11 , V_34 [ V_6 ] ) ) < 0 ) {
F_161 ( V_37 ) ;
return V_136 ;
}
strcpy ( V_37 -> V_275 , V_11 -> V_82 ) ;
sprintf ( V_37 -> V_276 , L_78 ,
V_37 -> V_275 , V_11 -> V_172 , V_11 -> V_171 ) ;
if ( ( V_136 = F_162 ( V_37 ) ) < 0 ) {
F_161 ( V_37 ) ;
return V_136 ;
}
F_163 ( V_2 , V_37 ) ;
V_6 ++ ;
return 0 ;
}
static void F_164 ( struct V_1 * V_2 )
{
F_161 ( F_165 ( V_2 ) ) ;
}
