static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_5 )
{
V_4 -> V_6 . type = V_7 ;
V_4 -> V_6 . V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_4 , F_4 ( V_2 ) ) ) {
if ( V_4 -> V_8 >= V_5 )
return 0 ;
}
if ( F_5 ( V_7 , F_2 ( V_2 ) ,
V_5 , V_4 ) < 0 )
return - V_9 ;
return 0 ;
}
static void F_6 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
if ( V_4 -> V_10 ) {
V_4 -> V_6 . V_6 = NULL ;
F_7 ( V_4 , F_4 ( V_2 ) ) ;
}
}
static inline void F_8 ( struct V_11 * V_12 , int V_13 , int V_14 )
{
F_9 ( V_14 , V_12 -> V_15 + V_13 ) ;
}
static inline unsigned int F_10 ( struct V_11 * V_12 , int V_13 )
{
return F_11 ( V_12 -> V_15 + V_13 ) ;
}
static inline int F_12 ( struct V_11 * V_12 )
{
unsigned long V_16 ;
int V_17 = 1 ;
F_13 ( & V_12 -> V_18 , V_16 ) ;
if ( ( V_12 -> V_19 != V_12 -> V_20 ) &&
( V_12 -> V_19 >= 0 ) && ( V_12 -> V_20 >= 0 ) ) {
V_17 = 0 ;
}
F_14 ( & V_12 -> V_18 , V_16 ) ;
return V_17 ;
}
static inline int F_15 ( struct V_11 * V_12 )
{
if ( F_16 ( V_12 ) ) {
return ( F_10 ( V_12 , V_21 ) &
V_22 ) ? 96000 : 88200 ;
} else {
return ( F_10 ( V_12 , V_21 ) &
V_22 ) ? 48000 : 44100 ;
}
}
static inline void F_17 ( struct V_11 * V_12 )
{
unsigned int V_23 ;
V_23 = V_12 -> V_24 & V_25 ;
V_12 -> V_26 = 1 << ( ( F_18 ( V_23 ) + 8 ) ) ;
V_12 -> V_27 =
( V_12 -> V_26 * 2 - 1 ) & V_28 ;
V_12 -> V_29 = 80 ;
}
static T_2 F_19 ( struct V_11 * V_12 )
{
int V_30 ;
unsigned int V_31 , V_32 ;
T_2 V_33 = V_12 -> V_26 / 4 ;
T_3 V_34 ;
V_30 = F_10 ( V_12 , V_21 ) ;
if ( ! V_12 -> V_35 )
return ( V_30 & V_36 ) ? V_33 : 0 ;
V_31 = V_30 & V_28 ;
V_34 = V_12 -> V_37 - V_31 ;
V_34 &= 0xffff ;
if ( V_34 <= ( T_3 ) V_12 -> V_29 * 4 )
V_31 = V_12 -> V_37 ;
else
V_12 -> V_37 = V_31 ;
V_31 &= V_12 -> V_27 ;
V_31 /= 4 ;
V_32 = V_30 & V_36 ;
if ( V_31 < V_33 ) {
if ( V_31 > V_12 -> V_29 ) {
if ( V_32 )
F_20 ( V_38 L_1 , V_30 , V_31 ) ;
} else if ( ! V_32 )
return 0 ;
V_31 -= V_12 -> V_29 ;
if ( ( int ) V_31 < 0 )
V_31 += V_33 * 2 ;
} else {
if ( V_31 > V_33 + V_12 -> V_29 ) {
if ( ! V_32 )
F_20 ( V_38 L_2 , V_30 , V_31 ) ;
} else if ( V_32 )
return V_33 ;
V_31 -= V_12 -> V_29 ;
}
return V_31 ;
}
static inline void F_21 ( struct V_11 * V_12 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ ) {
F_8 ( V_12 , V_23 * 4 , 0 ) ;
F_22 ( 10 ) ;
}
V_12 -> V_37 = 0 ;
}
static inline void F_23 ( struct V_11 * V_39 )
{
V_39 -> V_24 |= ( V_40 | V_41 ) ;
F_8 ( V_39 , V_42 , V_39 -> V_24 ) ;
}
static inline void F_24 ( struct V_11 * V_39 )
{
V_39 -> V_24 &= ~ ( V_41 | V_40 ) ;
F_8 ( V_39 , V_42 , V_39 -> V_24 ) ;
}
static int F_25 ( struct V_11 * V_39 ,
unsigned int V_43 )
{
int V_44 = 0 ;
int V_45 ;
F_26 ( & V_39 -> V_18 ) ;
if ( ( V_44 = V_39 -> V_46 ) ) {
F_24 ( V_39 ) ;
}
V_43 >>= 7 ;
V_45 = 0 ;
while ( V_43 ) {
V_45 ++ ;
V_43 >>= 1 ;
}
V_39 -> V_24 &= ~ V_25 ;
V_39 -> V_24 |= F_27 ( V_45 ) ;
F_8 ( V_39 , V_42 , V_39 -> V_24 ) ;
F_17 ( V_39 ) ;
if ( V_44 )
F_23 ( V_39 ) ;
F_28 ( & V_39 -> V_18 ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_12 , int V_47 )
{
int V_44 ;
int V_48 = 0 ;
int V_49 ;
if ( ! F_12 ( V_12 ) ) {
return - V_50 ;
}
F_26 ( & V_12 -> V_18 ) ;
V_49 = F_15 ( V_12 ) ;
switch ( V_47 ) {
case 44100 :
if ( V_49 > 48000 ) {
V_48 = 1 ;
}
V_47 = 0 ;
break;
case 48000 :
if ( V_49 > 48000 ) {
V_48 = 1 ;
}
V_47 = V_51 ;
break;
case 88200 :
if ( V_49 < 48000 ) {
V_48 = 1 ;
}
V_47 = V_52 ;
break;
case 96000 :
if ( V_49 < 48000 ) {
V_48 = 1 ;
}
V_47 = V_52 | V_51 ;
break;
default:
F_28 ( & V_12 -> V_18 ) ;
return - V_53 ;
}
if ( V_48 && ( V_12 -> V_20 >= 0 || V_12 -> V_19 >= 0 ) ) {
F_28 ( & V_12 -> V_18 ) ;
return - V_50 ;
}
if ( ( V_44 = V_12 -> V_46 ) ) {
F_24 ( V_12 ) ;
}
V_12 -> V_24 &= ~ ( V_51 | V_52 ) ;
V_12 -> V_24 |= V_47 ;
F_8 ( V_12 , V_42 , V_12 -> V_24 ) ;
if ( V_44 ) {
F_23 ( V_12 ) ;
}
if ( V_47 & V_52 ) {
if ( V_12 -> V_54 == V_55 ) {
V_12 -> V_56 = V_57 ;
} else {
V_12 -> V_56 = V_58 ;
}
} else {
if ( V_12 -> V_54 == V_55 ) {
V_12 -> V_56 = V_59 ;
} else {
V_12 -> V_56 = V_60 ;
}
}
F_28 ( & V_12 -> V_18 ) ;
return 0 ;
}
static void F_30 ( struct V_11 * V_12 , int V_61 , int V_62 )
{
int V_23 ;
V_12 -> V_63 = 0 ;
if ( V_61 < 0 ) {
if ( V_62 ) {
for ( V_23 = 0 ; V_23 < V_55 ; V_23 ++ ) {
V_12 -> V_64 |= ( 1 << V_23 ) ;
F_8 ( V_12 , V_65 + V_23 * 4 , 1 ) ;
}
} else {
for ( V_23 = 0 ; V_23 < V_55 ; V_23 ++ ) {
V_12 -> V_64 &= ~ ( 1 << V_23 ) ;
F_8 ( V_12 , V_65 + V_23 * 4 , 0 ) ;
}
}
} else {
int V_66 ;
V_66 = V_12 -> V_56 [ V_61 ] ;
if ( V_62 ) {
V_12 -> V_64 |= ( 1 << V_66 ) ;
} else {
V_12 -> V_64 &= ~ ( 1 << V_66 ) ;
}
F_8 ( V_12 ,
V_65 + V_66 * 4 ,
V_62 ? 1 : 0 ) ;
}
}
static int F_31 ( struct V_11 * V_12 , int V_67 )
{
if ( V_67 ) {
F_30 ( V_12 , - 1 , 1 ) ;
V_12 -> V_24 =
V_68 |
F_27 ( 7 ) |
V_41 ;
F_21 ( V_12 ) ;
F_8 ( V_12 , V_42 ,
V_12 -> V_24 ) ;
V_12 -> V_63 = 1 ;
} else {
F_30 ( V_12 , - 1 , 0 ) ;
F_24 ( V_12 ) ;
V_12 -> V_63 = 0 ;
}
return 0 ;
}
static void F_32 ( struct V_11 * V_12 , int V_69 , int V_67 )
{
if ( V_67 )
V_12 -> V_24 |= V_69 ;
else
V_12 -> V_24 &= ~ V_69 ;
F_8 ( V_12 , V_42 , V_12 -> V_24 ) ;
}
static void F_33 ( struct V_11 * V_12 , const int V_14 )
{
long V_69 ;
long V_23 ;
for ( V_23 = 0 , V_69 = 0x80 ; V_23 < 8 ; V_23 ++ , V_69 >>= 1 ) {
if ( V_14 & V_69 )
F_32 ( V_12 , V_70 , 1 ) ;
else
F_32 ( V_12 , V_70 , 0 ) ;
F_32 ( V_12 , V_71 , 1 ) ;
F_32 ( V_12 , V_71 , 0 ) ;
}
}
static int F_34 ( struct V_11 * V_12 )
{
long V_69 ;
long V_14 ;
long V_23 ;
V_14 = 0 ;
for ( V_23 = 0 , V_69 = 0x80 ; V_23 < 8 ; V_23 ++ , V_69 >>= 1 ) {
F_32 ( V_12 , V_71 , 1 ) ;
if ( F_10 ( V_12 , V_21 ) & V_72 )
V_14 |= V_69 ;
F_32 ( V_12 , V_71 , 0 ) ;
}
return V_14 ;
}
static void F_35 ( struct V_11 * V_12 , const int V_73 , const int V_74 )
{
F_32 ( V_12 , V_75 , 1 ) ;
F_33 ( V_12 , 0x20 ) ;
F_33 ( V_12 , V_73 ) ;
F_33 ( V_12 , V_74 ) ;
F_32 ( V_12 , V_75 , 0 ) ;
}
static int F_36 ( struct V_11 * V_12 , const int V_73 )
{
int V_17 ;
F_32 ( V_12 , V_75 , 1 ) ;
F_33 ( V_12 , 0x20 ) ;
F_33 ( V_12 , V_73 ) ;
F_32 ( V_12 , V_75 , 0 ) ;
F_32 ( V_12 , V_75 , 1 ) ;
F_33 ( V_12 , 0x21 ) ;
V_17 = F_34 ( V_12 ) ;
F_32 ( V_12 , V_75 , 0 ) ;
return V_17 ;
}
static void F_37 ( struct V_11 * V_12 )
{
V_12 -> V_24 |= V_76 ;
F_35 ( V_12 , 4 , 0x40 ) ;
F_35 ( V_12 , 17 , 0x13 ) ;
F_35 ( V_12 , 6 , 0x02 ) ;
}
static inline int F_38 ( struct V_11 * V_39 )
{
unsigned int V_77 ;
if ( F_10 ( V_39 , V_21 ) & V_78 ) {
return - 1 ;
}
if ( V_39 -> V_79 == 15 ) {
int V_80 , V_81 , V_17 ;
V_80 = F_36 ( V_39 , 30 ) ;
if ( V_80 != 0 )
V_81 = 48000 * 64 / V_80 ;
else
V_81 = 0 ;
if ( V_81 > 30400 && V_81 < 33600 ) V_17 = 32000 ;
else if ( V_81 > 41900 && V_81 < 46000 ) V_17 = 44100 ;
else if ( V_81 > 46000 && V_81 < 50400 ) V_17 = 48000 ;
else if ( V_81 > 60800 && V_81 < 67200 ) V_17 = 64000 ;
else if ( V_81 > 83700 && V_81 < 92000 ) V_17 = 88200 ;
else if ( V_81 > 92000 && V_81 < 100000 ) V_17 = 96000 ;
else V_17 = 0 ;
return V_17 ;
}
V_77 = F_10 ( V_39 , V_21 ) & V_82 ;
switch ( F_39 ( V_77 ) ) {
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
F_40 ( V_38 L_3 ,
V_39 -> V_83 , V_77 ) ;
return 0 ;
break;
}
}
static T_4 F_41 ( struct V_84 * V_85 )
{
T_4 V_14 = 0 ;
V_14 |= ( V_85 -> V_30 [ 0 ] & V_86 ) ? V_87 : 0 ;
V_14 |= ( V_85 -> V_30 [ 0 ] & V_88 ) ? V_89 : 0 ;
if ( V_14 & V_87 )
V_14 |= ( V_85 -> V_30 [ 0 ] & V_90 ) ? V_91 : 0 ;
else
V_14 |= ( V_85 -> V_30 [ 0 ] & V_92 ) ? V_91 : 0 ;
return V_14 ;
}
static void F_42 ( struct V_84 * V_85 , T_4 V_14 )
{
V_85 -> V_30 [ 0 ] = ( ( V_14 & V_87 ) ? V_86 : 0 ) |
( ( V_14 & V_89 ) ? V_88 : 0 ) ;
if ( V_14 & V_87 )
V_85 -> V_30 [ 0 ] |= ( V_14 & V_91 ) ? V_90 : 0 ;
else
V_85 -> V_30 [ 0 ] |= ( V_14 & V_91 ) ? V_92 : 0 ;
}
static int F_43 ( struct V_93 * V_94 , struct V_95 * V_96 )
{
V_96 -> type = V_97 ;
V_96 -> V_98 = 1 ;
return 0 ;
}
static int F_44 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
F_42 ( & V_100 -> V_101 . V_102 , V_12 -> V_103 ) ;
return 0 ;
}
static int F_46 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
int V_104 ;
T_4 V_14 ;
V_14 = F_41 ( & V_100 -> V_101 . V_102 ) ;
F_26 ( & V_12 -> V_18 ) ;
V_104 = V_14 != V_12 -> V_103 ;
V_12 -> V_103 = V_14 ;
F_28 ( & V_12 -> V_18 ) ;
return V_104 ;
}
static int F_47 ( struct V_93 * V_94 , struct V_95 * V_96 )
{
V_96 -> type = V_97 ;
V_96 -> V_98 = 1 ;
return 0 ;
}
static int F_48 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
F_42 ( & V_100 -> V_101 . V_102 , V_12 -> V_105 ) ;
return 0 ;
}
static int F_49 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
int V_104 ;
T_4 V_14 ;
V_14 = F_41 ( & V_100 -> V_101 . V_102 ) ;
F_26 ( & V_12 -> V_18 ) ;
V_104 = V_14 != V_12 -> V_105 ;
V_12 -> V_105 = V_14 ;
V_12 -> V_24 &= ~ ( V_87 | V_89 | V_91 ) ;
F_8 ( V_12 , V_42 , V_12 -> V_24 |= V_14 ) ;
F_28 ( & V_12 -> V_18 ) ;
return V_104 ;
}
static int F_50 ( struct V_93 * V_94 , struct V_95 * V_96 )
{
V_96 -> type = V_97 ;
V_96 -> V_98 = 1 ;
return 0 ;
}
static int F_51 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
V_100 -> V_101 . V_102 . V_30 [ 0 ] = V_94 -> V_106 ;
return 0 ;
}
static unsigned int F_52 ( struct V_11 * V_12 )
{
if ( V_12 -> V_24 & V_107 )
return 1 ;
return 0 ;
}
static int F_53 ( struct V_11 * V_12 , int V_108 )
{
int V_44 = 0 ;
if ( V_108 ) {
V_12 -> V_24 |= V_107 ;
} else {
V_12 -> V_24 &= ~ V_107 ;
}
if ( ( V_44 = V_12 -> V_46 ) ) {
F_24 ( V_12 ) ;
}
F_8 ( V_12 , V_42 , V_12 -> V_24 ) ;
if ( V_44 ) {
F_23 ( V_12 ) ;
}
return 0 ;
}
static int F_54 ( struct V_93 * V_94 , struct V_95 * V_96 )
{
static char * V_109 [ 2 ] = { L_4 , L_5 } ;
V_96 -> type = V_110 ;
V_96 -> V_98 = 1 ;
V_96 -> V_101 . V_111 . V_112 = 2 ;
if ( V_96 -> V_101 . V_111 . V_113 > 1 )
V_96 -> V_101 . V_111 . V_113 = 1 ;
strcpy ( V_96 -> V_101 . V_111 . V_114 , V_109 [ V_96 -> V_101 . V_111 . V_113 ] ) ;
return 0 ;
}
static int F_55 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
F_26 ( & V_12 -> V_18 ) ;
V_100 -> V_101 . V_111 . V_113 [ 0 ] = F_52 ( V_12 ) ;
F_28 ( & V_12 -> V_18 ) ;
return 0 ;
}
static int F_56 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
int V_104 ;
unsigned int V_14 ;
if ( ! F_12 ( V_12 ) )
return - V_50 ;
V_14 = V_100 -> V_101 . V_111 . V_113 [ 0 ] % 2 ;
F_26 ( & V_12 -> V_18 ) ;
V_104 = V_14 != F_52 ( V_12 ) ;
if ( V_104 )
F_53 ( V_12 , V_14 ) ;
F_28 ( & V_12 -> V_18 ) ;
return V_104 ;
}
static unsigned int F_57 ( struct V_11 * V_12 )
{
return F_58 ( V_12 -> V_24 &
V_115 ) ;
}
static int F_59 ( struct V_11 * V_12 , int V_116 )
{
int V_44 = 0 ;
V_12 -> V_24 &= ~ V_115 ;
V_12 -> V_24 |= F_60 ( V_116 ) ;
if ( ( V_44 = V_12 -> V_46 ) ) {
F_24 ( V_12 ) ;
}
F_8 ( V_12 , V_42 , V_12 -> V_24 ) ;
if ( V_44 ) {
F_23 ( V_12 ) ;
}
return 0 ;
}
static int F_61 ( struct V_93 * V_94 , struct V_95 * V_96 )
{
static char * V_109 [ 3 ] = { L_4 , L_6 , L_5 } ;
V_96 -> type = V_110 ;
V_96 -> V_98 = 1 ;
V_96 -> V_101 . V_111 . V_112 = 3 ;
if ( V_96 -> V_101 . V_111 . V_113 > 2 )
V_96 -> V_101 . V_111 . V_113 = 2 ;
strcpy ( V_96 -> V_101 . V_111 . V_114 , V_109 [ V_96 -> V_101 . V_111 . V_113 ] ) ;
return 0 ;
}
static int F_62 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
F_26 ( & V_12 -> V_18 ) ;
V_100 -> V_101 . V_111 . V_113 [ 0 ] = F_57 ( V_12 ) ;
F_28 ( & V_12 -> V_18 ) ;
return 0 ;
}
static int F_63 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
int V_104 ;
unsigned int V_14 ;
if ( ! F_12 ( V_12 ) )
return - V_50 ;
V_14 = V_100 -> V_101 . V_111 . V_113 [ 0 ] % 3 ;
F_26 ( & V_12 -> V_18 ) ;
V_104 = V_14 != F_57 ( V_12 ) ;
if ( V_104 )
F_59 ( V_12 , V_14 ) ;
F_28 ( & V_12 -> V_18 ) ;
return V_104 ;
}
static int F_64 ( struct V_11 * V_12 )
{
return ( V_12 -> V_24 & V_117 ) ? 1 : 0 ;
}
static int F_65 ( struct V_11 * V_12 , int V_118 )
{
int V_44 = 0 ;
if ( V_118 ) {
V_12 -> V_24 |= V_117 ;
} else {
V_12 -> V_24 &= ~ V_117 ;
}
if ( ( V_44 = V_12 -> V_46 ) ) {
F_24 ( V_12 ) ;
}
F_8 ( V_12 , V_42 , V_12 -> V_24 ) ;
if ( V_44 ) {
F_23 ( V_12 ) ;
}
return 0 ;
}
static int F_66 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
F_26 ( & V_12 -> V_18 ) ;
V_100 -> V_101 . integer . V_101 [ 0 ] = F_64 ( V_12 ) ;
F_28 ( & V_12 -> V_18 ) ;
return 0 ;
}
static int F_67 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
int V_104 ;
unsigned int V_14 ;
if ( ! F_12 ( V_12 ) )
return - V_50 ;
V_14 = V_100 -> V_101 . integer . V_101 [ 0 ] & 1 ;
F_26 ( & V_12 -> V_18 ) ;
V_104 = ( int ) V_14 != F_64 ( V_12 ) ;
F_65 ( V_12 , V_14 ) ;
F_28 ( & V_12 -> V_18 ) ;
return V_104 ;
}
static int F_68 ( struct V_11 * V_12 )
{
if ( V_12 -> V_24 & V_119 ) {
return 2 ;
} else if ( V_12 -> V_24 & V_120 ) {
return 1 ;
} else {
return 0 ;
}
}
static int F_69 ( struct V_11 * V_12 , int V_121 )
{
int V_44 = 0 ;
switch ( V_121 ) {
case 0 :
V_12 -> V_24 &=
~ ( V_120 | V_119 ) ;
break;
case 1 :
V_12 -> V_24 =
( V_12 -> V_24 & ~ V_119 ) | V_120 ;
break;
case 2 :
V_12 -> V_24 |=
( V_120 | V_119 ) ;
break;
}
if ( ( V_44 = V_12 -> V_46 ) ) {
F_24 ( V_12 ) ;
}
F_8 ( V_12 , V_42 , V_12 -> V_24 ) ;
if ( V_44 ) {
F_23 ( V_12 ) ;
}
return 0 ;
}
static int F_70 ( struct V_93 * V_94 , struct V_95 * V_96 )
{
static char * V_109 [ 3 ] = { L_7 , L_8 , L_9 } ;
V_96 -> type = V_110 ;
V_96 -> V_98 = 1 ;
V_96 -> V_101 . V_111 . V_112 = 3 ;
if ( V_96 -> V_101 . V_111 . V_113 > 2 )
V_96 -> V_101 . V_111 . V_113 = 2 ;
strcpy ( V_96 -> V_101 . V_111 . V_114 , V_109 [ V_96 -> V_101 . V_111 . V_113 ] ) ;
return 0 ;
}
static int F_71 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
F_26 ( & V_12 -> V_18 ) ;
V_100 -> V_101 . V_111 . V_113 [ 0 ] = F_68 ( V_12 ) ;
F_28 ( & V_12 -> V_18 ) ;
return 0 ;
}
static int F_72 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
int V_104 ;
unsigned int V_14 ;
V_14 = V_100 -> V_101 . V_111 . V_113 [ 0 ] % 3 ;
F_26 ( & V_12 -> V_18 ) ;
V_104 = ( int ) V_14 != F_68 ( V_12 ) ;
F_69 ( V_12 , V_14 ) ;
F_28 ( & V_12 -> V_18 ) ;
return V_104 ;
}
static int F_73 ( struct V_11 * V_12 )
{
switch ( V_12 -> V_24 & V_122 ) {
case V_123 :
return V_124 ;
case V_125 :
return V_126 ;
case V_127 :
return V_128 ;
case V_129 :
return V_130 ;
}
return 0 ;
}
static int F_74 ( struct V_11 * V_12 , int V_131 )
{
int V_44 ;
V_12 -> V_24 &= ~ V_122 ;
switch ( V_131 ) {
case V_124 :
V_12 -> V_24 |= V_123 ;
break;
case V_126 :
V_12 -> V_24 |= V_125 ;
break;
case V_128 :
V_12 -> V_24 |= V_127 ;
break;
case V_130 :
V_12 -> V_24 |= V_129 ;
break;
}
if ( ( V_44 = V_12 -> V_46 ) ) {
F_24 ( V_12 ) ;
}
F_8 ( V_12 , V_42 , V_12 -> V_24 ) ;
if ( V_44 ) {
F_23 ( V_12 ) ;
}
return 0 ;
}
static int F_75 ( struct V_93 * V_94 , struct V_95 * V_96 )
{
static char * V_109 [ 4 ] = { L_10 , L_11 , L_12 , L_13 } ;
struct V_11 * V_12 = F_45 ( V_94 ) ;
V_96 -> type = V_110 ;
V_96 -> V_98 = 1 ;
V_96 -> V_101 . V_111 . V_112 = V_12 -> V_54 == V_55 ? 4 : 3 ;
if ( V_96 -> V_101 . V_111 . V_113 >= V_96 -> V_101 . V_111 . V_112 )
V_96 -> V_101 . V_111 . V_113 = V_96 -> V_101 . V_111 . V_112 - 1 ;
strcpy ( V_96 -> V_101 . V_111 . V_114 , V_109 [ V_96 -> V_101 . V_111 . V_113 ] ) ;
return 0 ;
}
static int F_76 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
F_26 ( & V_12 -> V_18 ) ;
V_100 -> V_101 . V_111 . V_113 [ 0 ] = F_73 ( V_12 ) ;
F_28 ( & V_12 -> V_18 ) ;
return 0 ;
}
static int F_77 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
int V_104 , V_132 ;
unsigned int V_14 ;
if ( ! F_12 ( V_12 ) )
return - V_50 ;
V_132 = V_12 -> V_54 == V_55 ? 4 : 3 ;
V_14 = V_100 -> V_101 . V_111 . V_113 [ 0 ] % V_132 ;
F_26 ( & V_12 -> V_18 ) ;
V_104 = ( int ) V_14 != F_73 ( V_12 ) ;
F_74 ( V_12 , V_14 ) ;
F_28 ( & V_12 -> V_18 ) ;
return V_104 ;
}
static int F_78 ( struct V_93 * V_94 , struct V_95 * V_96 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
V_96 -> type = V_133 ;
V_96 -> V_98 = V_12 -> V_54 ;
V_96 -> V_101 . integer . V_134 = 0 ;
V_96 -> V_101 . integer . V_132 = 1 ;
return 0 ;
}
static int F_79 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
unsigned int V_135 ;
T_4 V_64 = V_12 -> V_64 ;
for ( V_135 = 0 ; V_135 < V_12 -> V_54 ; ++ V_135 ) {
V_100 -> V_101 . integer . V_101 [ V_135 ] = ! ! ( V_64 & ( 1 << V_135 ) ) ;
}
return 0 ;
}
static int F_80 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
int V_104 ;
unsigned int V_136 ;
T_4 V_64 = 0 ;
if ( ! F_12 ( V_12 ) )
return - V_50 ;
for ( V_136 = 0 ; V_136 < V_12 -> V_54 ; ++ V_136 ) {
if ( V_100 -> V_101 . integer . V_101 [ V_136 ] )
V_64 |= 1 << V_136 ;
}
F_26 ( & V_12 -> V_18 ) ;
V_104 = V_64 ^ V_12 -> V_64 ;
if ( V_104 ) {
for ( V_136 = 0 ; V_136 < V_12 -> V_54 ; ++ V_136 ) {
if ( ! ( V_104 & ( 1 << V_136 ) ) )
continue;
F_30 ( V_12 , V_136 , V_64 & ( 1 << V_136 ) ) ;
}
}
F_28 ( & V_12 -> V_18 ) ;
return ! ! V_104 ;
}
static int F_81 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
F_26 ( & V_12 -> V_18 ) ;
V_100 -> V_101 . integer . V_101 [ 0 ] = V_12 -> V_63 ;
F_28 ( & V_12 -> V_18 ) ;
return 0 ;
}
static int F_82 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
int V_104 ;
unsigned int V_14 ;
int V_137 = 0 ;
if ( ! F_12 ( V_12 ) )
return - V_50 ;
V_14 = V_100 -> V_101 . integer . V_101 [ 0 ] & 1 ;
F_26 ( & V_12 -> V_18 ) ;
V_104 = ( V_100 -> V_101 . integer . V_101 [ 0 ] != V_12 -> V_63 ) ;
if ( V_104 )
V_137 = F_31 ( V_12 , V_14 ) ;
F_28 ( & V_12 -> V_18 ) ;
return V_137 ? V_137 : V_104 ;
}
static int F_83 ( struct V_93 * V_94 , struct V_95 * V_96 )
{
V_96 -> type = V_138 ;
V_96 -> V_98 = 1 ;
V_96 -> V_101 . integer . V_134 = 0 ;
V_96 -> V_101 . integer . V_132 = 96000 ;
return 0 ;
}
static int F_84 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
F_26 ( & V_12 -> V_18 ) ;
V_100 -> V_101 . integer . V_101 [ 0 ] = F_38 ( V_12 ) ;
F_28 ( & V_12 -> V_18 ) ;
return 0 ;
}
static int F_85 ( struct V_93 * V_94 , struct V_95 * V_96 )
{
static char * V_109 [ 4 ] = { L_14 , L_15 , L_16 , L_17 } ;
V_96 -> type = V_110 ;
V_96 -> V_98 = 1 ;
V_96 -> V_101 . V_111 . V_112 = 4 ;
if ( V_96 -> V_101 . V_111 . V_113 >= V_96 -> V_101 . V_111 . V_112 )
V_96 -> V_101 . V_111 . V_113 = V_96 -> V_101 . V_111 . V_112 - 1 ;
strcpy ( V_96 -> V_101 . V_111 . V_114 , V_109 [ V_96 -> V_101 . V_111 . V_113 ] ) ;
return 0 ;
}
static int F_86 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
unsigned int V_139 , V_140 , V_14 ;
switch ( V_94 -> V_106 ) {
case 0 : V_139 = V_141 ; V_140 = V_142 ; break;
case 1 : V_139 = V_143 ; V_140 = V_144 ; break;
case 2 : V_139 = V_145 ; V_140 = V_146 ; break;
default: return - V_53 ;
}
V_14 = F_10 ( V_12 , V_21 ) ;
V_100 -> V_101 . V_111 . V_113 [ 0 ] = ( V_14 & V_139 ) ? 1 : 0 ;
V_100 -> V_101 . V_111 . V_113 [ 0 ] |= ( V_14 & V_140 ) ? 2 : 0 ;
return 0 ;
}
static int F_87 ( struct V_93 * V_94 , struct V_99 * V_100 )
{
struct V_11 * V_12 = F_45 ( V_94 ) ;
V_100 -> V_101 . integer . V_101 [ 0 ] =
( F_10 ( V_12 , V_21 ) & V_147 ) ? 1 : 0 ;
return 0 ;
}
static int F_88 ( void * V_148 ,
T_5 * V_149 ,
T_6 * V_150 )
{
struct V_11 * V_39 = (struct V_11 * ) V_148 ;
T_4 V_101 ;
int V_23 ;
V_150 -> type = V_151 ;
if ( ( F_10 ( V_39 , V_21 ) &
V_147 ) == 0 ) {
V_150 -> V_101 . V_152 [ 0 ] = 0 ;
return 0 ;
}
F_8 ( V_39 , V_153 , 0 ) ;
for ( V_23 = 0 ; V_23 < 50 ; V_23 ++ ) {
if ( ! ( F_10 ( V_39 , V_23 * 4 ) & V_154 ) )
break;
}
if ( ! ( F_10 ( V_39 , V_23 * 4 ) & V_154 ) ) {
return - V_155 ;
}
V_101 = 0 ;
for ( V_23 = 0 ; V_23 < 32 ; V_23 ++ ) {
V_101 >>= 1 ;
if ( F_10 ( V_39 , V_23 * 4 ) & V_156 )
V_101 |= 0x80000000 ;
}
if ( V_101 > 2 * 60 * 48000 ) {
V_101 -= 2 * 60 * 48000 ;
} else {
V_101 = 0 ;
}
V_150 -> V_101 . V_152 [ 0 ] = V_101 ;
return 0 ;
}
static int F_89 ( struct V_157 * V_158 , struct V_11 * V_12 )
{
unsigned int V_159 ;
int V_137 ;
struct V_93 * V_160 ;
for ( V_159 = 0 ; V_159 < F_90 ( V_161 ) ; V_159 ++ ) {
if ( ( V_137 = F_91 ( V_158 , V_160 = F_92 ( & V_161 [ V_159 ] , V_12 ) ) ) < 0 )
return V_137 ;
if ( V_159 == 1 )
V_12 -> V_162 = V_160 ;
}
if ( V_12 -> V_54 == V_55 )
if ( ( V_137 = F_91 ( V_158 , V_160 = F_92 ( & V_163 , V_12 ) ) ) < 0 )
return V_137 ;
if ( V_12 -> V_79 >= 15 )
if ( ( V_137 = F_91 ( V_158 , V_160 = F_92 ( & V_164 , V_12 ) ) ) < 0 )
return V_137 ;
return 0 ;
}
static void
F_93 ( struct V_165 * V_166 , struct V_167 * V_168 )
{
struct V_11 * V_12 = (struct V_11 * ) V_166 -> V_148 ;
T_4 V_64 = V_12 -> V_64 ;
int V_169 = 0 ;
int V_23 ;
unsigned int V_30 ;
int V_80 ;
V_30 = F_10 ( V_12 , V_21 ) ;
F_94 ( V_168 , L_18 , V_12 -> V_83 , V_12 -> V_158 -> V_170 + 1 ) ;
F_94 ( V_168 , L_19 ,
V_12 -> V_171 , V_12 -> V_172 ) ;
F_94 ( V_168 , L_20 ,
V_12 -> V_173 , V_12 -> V_174 , ( unsigned long ) V_12 -> V_15 ) ;
F_94 ( V_168 , L_21 , V_12 -> V_24 ) ;
F_94 ( V_168 , L_22 ) ;
V_80 = 1 << ( 6 + F_18 ( V_12 -> V_24 &
V_25 ) ) ;
F_94 ( V_168 , L_23 ,
V_80 , ( unsigned long ) V_12 -> V_26 ) ;
F_94 ( V_168 , L_24 ,
F_19 ( V_12 ) ) ;
F_94 ( V_168 , L_25 ,
V_12 -> V_63 ? L_26 : L_27 ) ;
if ( ( V_12 -> V_24 & ( V_120 | V_119 ) ) == 0 ) {
F_94 ( V_168 , L_28 ) ;
V_169 = 1 ;
} else if ( V_12 -> V_24 & V_119 ) {
if ( V_30 & V_175 ) {
F_94 ( V_168 , L_29 ) ;
} else {
F_94 ( V_168 , L_30 ) ;
}
} else {
F_94 ( V_168 , L_31 ) ;
}
if ( V_169 ) {
switch ( V_12 -> V_24 & V_122 ) {
case V_123 :
F_94 ( V_168 , L_32 ) ;
break;
case V_125 :
F_94 ( V_168 , L_33 ) ;
break;
case V_127 :
F_94 ( V_168 , L_34 ) ;
break;
case V_129 :
F_94 ( V_168 , L_35 ) ;
break;
default:
F_94 ( V_168 , L_36 ) ;
}
}
if ( V_12 -> V_79 >= 15 )
F_94 ( V_168 , L_37 ,
( V_12 -> V_24 & V_107 ) ?
L_5 : L_38 ) ;
F_94 ( V_168 , L_22 ) ;
switch ( F_58 ( V_12 -> V_24 &
V_115 ) ) {
case V_176 :
F_94 ( V_168 , L_39 ) ;
break;
case V_177 :
F_94 ( V_168 , L_40 ) ;
break;
case V_178 :
F_94 ( V_168 , L_41 ) ;
break;
default:
F_94 ( V_168 , L_42 ) ;
break;
}
if ( V_12 -> V_24 & V_117 ) {
F_94 ( V_168 , L_43 ) ;
} else {
F_94 ( V_168 , L_44 ) ;
}
if ( V_12 -> V_24 & V_87 ) {
F_94 ( V_168 , L_45 ) ;
} else {
F_94 ( V_168 , L_46 ) ;
}
if ( V_12 -> V_24 & V_91 ) {
F_94 ( V_168 , L_47 ) ;
} else {
F_94 ( V_168 , L_48 ) ;
}
if ( V_12 -> V_24 & V_89 ) {
F_94 ( V_168 , L_49 ) ;
} else {
F_94 ( V_168 , L_50 ) ;
}
V_23 = F_38 ( V_12 ) ;
if ( V_23 < 0 ) {
F_94 ( V_168 ,
L_51 ) ;
} else if ( V_23 == 0 ) {
F_94 ( V_168 , L_52 ) ;
} else {
F_94 ( V_168 , L_53 , V_23 ) ;
}
F_94 ( V_168 , L_22 ) ;
F_94 ( V_168 , L_54 ,
F_15 ( V_12 ) ) ;
V_80 = V_30 & V_142 ;
if ( V_30 & V_141 ) {
F_94 ( V_168 , L_55 , V_80 ? L_56 : L_15 ) ;
} else {
F_94 ( V_168 , L_57 ) ;
}
V_80 = V_30 & V_144 ;
if ( V_30 & V_143 ) {
F_94 ( V_168 , L_58 , V_80 ? L_56 : L_15 ) ;
} else {
F_94 ( V_168 , L_59 ) ;
}
V_80 = V_30 & V_146 ;
if ( V_30 & V_145 ) {
F_94 ( V_168 , L_60 , V_80 ? L_56 : L_15 ) ;
} else {
F_94 ( V_168 , L_61 ) ;
}
F_94 ( V_168 , L_22 ) ;
F_94 ( V_168 , L_62 ,
( V_30 & V_147 ) ? L_26 : L_27 ) ;
F_94 ( V_168 , L_63 ) ;
for ( V_23 = 0 ; V_23 < V_12 -> V_54 ; V_23 ++ ) {
if ( V_64 & ( 1 << V_23 ) ) {
F_94 ( V_168 , L_64 , V_23 + 1 ) ;
} else {
F_94 ( V_168 , L_65 , V_23 + 1 ) ;
}
if ( ( ( V_23 + 1 ) % 8 ) == 0 ) {
F_94 ( V_168 , L_22 ) ;
}
}
F_94 ( V_168 , L_22 ) ;
}
static void T_7 F_95 ( struct V_11 * V_12 )
{
struct V_165 * V_166 ;
if ( ! F_96 ( V_12 -> V_158 , L_66 , & V_166 ) )
F_97 ( V_166 , V_12 , F_93 ) ;
}
static void F_98 ( struct V_11 * V_12 )
{
F_6 ( & V_12 -> V_179 , V_12 -> V_2 ) ;
F_6 ( & V_12 -> V_180 , V_12 -> V_2 ) ;
}
static int F_99 ( struct V_11 * V_12 )
{
if ( V_12 -> V_173 >= 0 )
F_24 ( V_12 ) ;
F_98 ( V_12 ) ;
if ( V_12 -> V_173 >= 0 )
F_100 ( V_12 -> V_173 , ( void * ) V_12 ) ;
if ( V_12 -> V_15 )
F_101 ( V_12 -> V_15 ) ;
if ( V_12 -> V_174 )
F_102 ( V_12 -> V_2 ) ;
F_103 ( V_12 -> V_2 ) ;
return 0 ;
}
static int T_7 F_104 ( struct V_11 * V_12 )
{
unsigned long V_181 , V_182 ;
if ( F_1 ( V_12 -> V_2 , & V_12 -> V_179 , V_183 ) < 0 ||
F_1 ( V_12 -> V_2 , & V_12 -> V_180 , V_183 ) < 0 ) {
if ( V_12 -> V_179 . V_10 )
F_105 ( & V_12 -> V_179 ) ;
F_20 ( V_38 L_67 , V_12 -> V_83 ) ;
return - V_9 ;
}
V_182 = F_106 ( V_12 -> V_179 . V_184 , 0x10000ul ) ;
V_181 = F_106 ( V_12 -> V_180 . V_184 , 0x10000ul ) ;
F_8 ( V_12 , V_185 , V_182 ) ;
F_8 ( V_12 , V_186 , V_181 ) ;
V_12 -> V_171 = V_12 -> V_179 . V_10 + ( V_182 - V_12 -> V_179 . V_184 ) ;
V_12 -> V_172 = V_12 -> V_180 . V_10 + ( V_181 - V_12 -> V_180 . V_184 ) ;
return 0 ;
}
static void F_107 ( struct V_11 * V_12 )
{
unsigned int V_135 ;
V_12 -> V_24 =
V_68 | F_27 ( 7 ) ;
F_8 ( V_12 , V_42 , V_12 -> V_24 ) ;
F_21 ( V_12 ) ;
F_17 ( V_12 ) ;
for ( V_135 = 0 ; V_135 < V_55 ; ++ V_135 )
F_8 ( V_12 , V_65 + V_135 * 4 , 0 ) ;
V_12 -> V_64 = 0 ;
V_12 -> V_63 = 0 ;
F_29 ( V_12 , 48000 ) ;
}
static T_8 F_108 ( int V_173 , void * V_187 )
{
struct V_11 * V_12 = (struct V_11 * ) V_187 ;
if ( ! ( F_10 ( V_12 , V_21 ) & V_188 ) ) {
return V_189 ;
}
F_8 ( V_12 , V_190 , 0 ) ;
if ( V_12 -> V_191 ) {
F_109 ( V_12 -> V_192 -> V_193 [ V_194 ] . V_195 ) ;
}
if ( V_12 -> V_196 ) {
F_109 ( V_12 -> V_192 -> V_193 [ V_197 ] . V_195 ) ;
}
return V_198 ;
}
static T_2 F_110 ( struct V_199 * V_195 )
{
struct V_11 * V_12 = F_111 ( V_195 ) ;
return F_19 ( V_12 ) ;
}
static char * F_112 ( struct V_11 * V_12 ,
int V_200 ,
int V_61 )
{
int V_66 ;
if ( F_113 ( V_61 < 0 || V_61 >= V_55 ) )
return NULL ;
if ( ( V_66 = V_12 -> V_56 [ V_61 ] ) < 0 ) {
return NULL ;
}
if ( V_200 == V_194 ) {
return V_12 -> V_171 +
( V_66 * V_201 ) ;
} else {
return V_12 -> V_172 +
( V_66 * V_201 ) ;
}
}
static int F_114 ( struct V_199 * V_195 , int V_61 ,
T_2 V_202 , void T_9 * V_203 , T_2 V_98 )
{
struct V_11 * V_12 = F_111 ( V_195 ) ;
char * V_204 ;
if ( F_113 ( V_202 + V_98 > V_201 / 4 ) )
return - V_53 ;
V_204 = F_112 ( V_12 ,
V_195 -> V_205 -> V_200 ,
V_61 ) ;
if ( F_113 ( ! V_204 ) )
return - V_155 ;
if ( F_115 ( V_204 + V_202 * 4 , V_203 , V_98 * 4 ) )
return - V_206 ;
return V_98 ;
}
static int F_116 ( struct V_199 * V_195 , int V_61 ,
T_2 V_202 , void T_9 * V_207 , T_2 V_98 )
{
struct V_11 * V_12 = F_111 ( V_195 ) ;
char * V_204 ;
if ( F_113 ( V_202 + V_98 > V_201 / 4 ) )
return - V_53 ;
V_204 = F_112 ( V_12 ,
V_195 -> V_205 -> V_200 ,
V_61 ) ;
if ( F_113 ( ! V_204 ) )
return - V_155 ;
if ( F_117 ( V_207 , V_204 + V_202 * 4 , V_98 * 4 ) )
return - V_206 ;
return V_98 ;
}
static int F_118 ( struct V_199 * V_195 , int V_61 ,
T_2 V_202 , T_2 V_98 )
{
struct V_11 * V_12 = F_111 ( V_195 ) ;
char * V_204 ;
V_204 = F_112 ( V_12 ,
V_195 -> V_205 -> V_200 ,
V_61 ) ;
if ( F_113 ( ! V_204 ) )
return - V_155 ;
memset ( V_204 + V_202 * 4 , 0 , V_98 * 4 ) ;
return V_98 ;
}
static int F_119 ( struct V_199 * V_195 )
{
struct V_208 * V_209 = V_195 -> V_209 ;
struct V_11 * V_12 = F_111 ( V_195 ) ;
struct V_199 * V_210 ;
if ( V_195 -> V_200 == V_197 )
V_210 = V_12 -> V_191 ;
else
V_210 = V_12 -> V_196 ;
if ( V_12 -> V_46 )
V_209 -> V_30 -> V_211 = F_19 ( V_12 ) ;
else
V_209 -> V_30 -> V_211 = 0 ;
if ( V_210 ) {
struct V_199 * V_39 ;
struct V_208 * V_212 = V_210 -> V_209 ;
F_120 (s, substream) {
if ( V_39 == V_210 ) {
V_212 -> V_30 -> V_211 = V_209 -> V_30 -> V_211 ;
break;
}
}
}
return 0 ;
}
static int F_121 ( struct V_199 * V_195 ,
struct V_213 * V_214 )
{
struct V_11 * V_12 = F_111 ( V_195 ) ;
int V_137 ;
T_10 V_215 ;
T_10 V_216 ;
F_26 ( & V_12 -> V_18 ) ;
if ( V_195 -> V_205 -> V_200 == V_197 ) {
V_12 -> V_24 &= ~ ( V_87 | V_89 | V_91 ) ;
F_8 ( V_12 , V_42 , V_12 -> V_24 |= V_12 -> V_105 ) ;
V_215 = V_12 -> V_19 ;
V_216 = V_12 -> V_20 ;
} else {
V_215 = V_12 -> V_20 ;
V_216 = V_12 -> V_19 ;
}
if ( ( V_216 > 0 ) && ( V_215 != V_216 ) ) {
if ( ( int ) F_122 ( V_214 ) !=
F_15 ( V_12 ) ) {
F_28 ( & V_12 -> V_18 ) ;
F_123 ( V_214 , V_217 ) ;
return - V_50 ;
}
if ( F_124 ( V_214 ) != V_12 -> V_26 / 4 ) {
F_28 ( & V_12 -> V_18 ) ;
F_123 ( V_214 , V_218 ) ;
return - V_50 ;
}
F_28 ( & V_12 -> V_18 ) ;
return 0 ;
} else {
F_28 ( & V_12 -> V_18 ) ;
}
if ( ( V_137 = F_29 ( V_12 , F_122 ( V_214 ) ) ) < 0 ) {
F_123 ( V_214 , V_217 ) ;
return V_137 ;
}
if ( ( V_137 = F_25 ( V_12 , F_124 ( V_214 ) ) ) < 0 ) {
F_123 ( V_214 , V_218 ) ;
return V_137 ;
}
return 0 ;
}
static int F_125 ( struct V_199 * V_195 ,
struct V_219 * V_220 )
{
struct V_11 * V_12 = F_111 ( V_195 ) ;
int V_136 ;
if ( F_113 ( V_220 -> V_61 >= V_55 ) )
return - V_53 ;
if ( ( V_136 = V_12 -> V_56 [ V_220 -> V_61 ] ) < 0 ) {
return - V_53 ;
}
V_220 -> V_31 = V_136 * V_201 ;
V_220 -> V_221 = 0 ;
V_220 -> V_222 = 32 ;
return 0 ;
}
static int F_126 ( struct V_199 * V_195 ,
unsigned int V_223 , void * V_224 )
{
switch ( V_223 ) {
case V_225 :
{
return F_119 ( V_195 ) ;
}
case V_226 :
{
struct V_219 * V_220 = V_224 ;
return F_125 ( V_195 , V_220 ) ;
}
default:
break;
}
return F_127 ( V_195 , V_223 , V_224 ) ;
}
static void F_128 ( struct V_11 * V_12 )
{
memset ( V_12 -> V_172 , 0 , V_183 ) ;
}
static int F_129 ( struct V_199 * V_195 ,
int V_223 )
{
struct V_11 * V_12 = F_111 ( V_195 ) ;
struct V_199 * V_210 ;
int V_46 ;
F_130 ( & V_12 -> V_18 ) ;
V_46 = V_12 -> V_46 ;
switch ( V_223 ) {
case V_227 :
V_46 |= 1 << V_195 -> V_200 ;
break;
case V_228 :
V_46 &= ~ ( 1 << V_195 -> V_200 ) ;
break;
default:
F_131 () ;
F_132 ( & V_12 -> V_18 ) ;
return - V_53 ;
}
if ( V_195 -> V_200 == V_197 )
V_210 = V_12 -> V_191 ;
else
V_210 = V_12 -> V_196 ;
if ( V_210 ) {
struct V_199 * V_39 ;
F_120 (s, substream) {
if ( V_39 == V_210 ) {
F_133 ( V_39 , V_195 ) ;
if ( V_223 == V_227 )
V_46 |= 1 << V_39 -> V_200 ;
else
V_46 &= ~ ( 1 << V_39 -> V_200 ) ;
goto V_229;
}
}
if ( V_223 == V_227 ) {
if ( ! ( V_46 & ( 1 << V_197 ) ) &&
V_195 -> V_200 == V_194 )
F_128 ( V_12 ) ;
} else {
if ( V_46 &&
V_195 -> V_200 == V_197 )
F_128 ( V_12 ) ;
}
} else {
if ( V_195 -> V_200 == V_194 )
F_128 ( V_12 ) ;
}
V_229:
F_133 ( V_195 , V_195 ) ;
if ( ! V_12 -> V_46 && V_46 )
F_23 ( V_12 ) ;
else if ( V_12 -> V_46 && ! V_46 )
F_24 ( V_12 ) ;
V_12 -> V_46 = V_46 ;
F_132 ( & V_12 -> V_18 ) ;
return 0 ;
}
static int F_134 ( struct V_199 * V_195 )
{
struct V_11 * V_12 = F_111 ( V_195 ) ;
unsigned long V_16 ;
int V_230 = 0 ;
F_13 ( & V_12 -> V_18 , V_16 ) ;
if ( ! V_12 -> V_46 )
F_21 ( V_12 ) ;
F_14 ( & V_12 -> V_18 , V_16 ) ;
return V_230 ;
}
static int F_135 ( struct V_213 * V_214 ,
struct V_231 * V_232 )
{
struct V_11 * V_12 = V_232 -> V_233 ;
struct V_234 * V_235 = F_136 ( V_214 , V_236 ) ;
unsigned int V_237 [ 2 ] = { V_12 -> V_238 , V_12 -> V_54 } ;
return F_137 ( V_235 , 2 , V_237 , 0 ) ;
}
static int F_138 ( struct V_213 * V_214 ,
struct V_231 * V_232 )
{
struct V_11 * V_12 = V_232 -> V_233 ;
struct V_234 * V_235 = F_136 ( V_214 , V_236 ) ;
struct V_234 * V_239 = F_136 ( V_214 , V_217 ) ;
if ( V_239 -> V_134 > 48000 ) {
struct V_234 V_240 = {
. V_134 = V_12 -> V_238 ,
. V_132 = V_12 -> V_238 ,
. integer = 1 ,
} ;
return F_139 ( V_235 , & V_240 ) ;
} else if ( V_239 -> V_132 < 88200 ) {
struct V_234 V_240 = {
. V_134 = V_12 -> V_54 ,
. V_132 = V_12 -> V_54 ,
. integer = 1 ,
} ;
return F_139 ( V_235 , & V_240 ) ;
}
return 0 ;
}
static int F_140 ( struct V_213 * V_214 ,
struct V_231 * V_232 )
{
struct V_11 * V_12 = V_232 -> V_233 ;
struct V_234 * V_235 = F_136 ( V_214 , V_236 ) ;
struct V_234 * V_239 = F_136 ( V_214 , V_217 ) ;
if ( V_235 -> V_134 >= V_12 -> V_54 ) {
struct V_234 V_240 = {
. V_134 = 44100 ,
. V_132 = 48000 ,
. integer = 1 ,
} ;
return F_139 ( V_239 , & V_240 ) ;
} else if ( V_235 -> V_132 <= V_12 -> V_238 ) {
struct V_234 V_240 = {
. V_134 = 88200 ,
. V_132 = 96000 ,
. integer = 1 ,
} ;
return F_139 ( V_239 , & V_240 ) ;
}
return 0 ;
}
static int F_141 ( struct V_199 * V_195 )
{
struct V_11 * V_12 = F_111 ( V_195 ) ;
struct V_208 * V_209 = V_195 -> V_209 ;
F_26 ( & V_12 -> V_18 ) ;
F_142 ( V_195 ) ;
V_209 -> V_241 = V_242 ;
V_209 -> V_243 = V_12 -> V_172 ;
V_209 -> V_244 = V_183 ;
if ( V_12 -> V_191 == NULL ) {
F_24 ( V_12 ) ;
F_30 ( V_12 , - 1 , 0 ) ;
}
V_12 -> V_19 = V_245 -> V_246 ;
V_12 -> V_196 = V_195 ;
F_28 ( & V_12 -> V_18 ) ;
F_143 ( V_209 , 0 , 32 , 24 ) ;
F_144 ( V_209 , 0 , V_218 , & V_247 ) ;
F_145 ( V_209 , 0 , V_236 ,
F_135 , V_12 ,
V_236 , - 1 ) ;
F_145 ( V_209 , 0 , V_236 ,
F_138 , V_12 ,
V_217 , - 1 ) ;
F_145 ( V_209 , 0 , V_217 ,
F_140 , V_12 ,
V_236 , - 1 ) ;
V_12 -> V_105 = V_12 -> V_103 ;
V_12 -> V_162 -> V_248 [ 0 ] . V_249 &= ~ V_250 ;
F_146 ( V_12 -> V_158 , V_251 |
V_252 , & V_12 -> V_162 -> V_253 ) ;
return 0 ;
}
static int F_147 ( struct V_199 * V_195 )
{
struct V_11 * V_12 = F_111 ( V_195 ) ;
F_26 ( & V_12 -> V_18 ) ;
V_12 -> V_19 = - 1 ;
V_12 -> V_196 = NULL ;
F_28 ( & V_12 -> V_18 ) ;
V_12 -> V_162 -> V_248 [ 0 ] . V_249 |= V_250 ;
F_146 ( V_12 -> V_158 , V_251 |
V_252 , & V_12 -> V_162 -> V_253 ) ;
return 0 ;
}
static int F_148 ( struct V_199 * V_195 )
{
struct V_11 * V_12 = F_111 ( V_195 ) ;
struct V_208 * V_209 = V_195 -> V_209 ;
F_26 ( & V_12 -> V_18 ) ;
F_142 ( V_195 ) ;
V_209 -> V_241 = V_254 ;
V_209 -> V_243 = V_12 -> V_171 ;
V_209 -> V_244 = V_183 ;
if ( V_12 -> V_196 == NULL ) {
F_24 ( V_12 ) ;
F_30 ( V_12 , - 1 , 0 ) ;
}
V_12 -> V_20 = V_245 -> V_246 ;
V_12 -> V_191 = V_195 ;
F_28 ( & V_12 -> V_18 ) ;
F_143 ( V_209 , 0 , 32 , 24 ) ;
F_144 ( V_209 , 0 , V_218 , & V_247 ) ;
F_145 ( V_209 , 0 , V_236 ,
F_135 , V_12 ,
V_236 , - 1 ) ;
F_145 ( V_209 , 0 , V_236 ,
F_138 , V_12 ,
V_217 , - 1 ) ;
F_145 ( V_209 , 0 , V_217 ,
F_140 , V_12 ,
V_236 , - 1 ) ;
return 0 ;
}
static int F_149 ( struct V_199 * V_195 )
{
struct V_11 * V_12 = F_111 ( V_195 ) ;
F_26 ( & V_12 -> V_18 ) ;
V_12 -> V_20 = - 1 ;
V_12 -> V_191 = NULL ;
F_28 ( & V_12 -> V_18 ) ;
return 0 ;
}
static int T_7 F_150 ( struct V_157 * V_158 ,
struct V_11 * V_12 )
{
struct V_255 * V_192 ;
int V_137 ;
if ( ( V_137 = F_151 ( V_158 ,
V_12 -> V_83 ,
0 , 1 , 1 , & V_192 ) ) < 0 ) {
return V_137 ;
}
V_12 -> V_192 = V_192 ;
V_192 -> V_148 = V_12 ;
strcpy ( V_192 -> V_114 , V_12 -> V_83 ) ;
F_152 ( V_192 , V_197 , & V_256 ) ;
F_152 ( V_192 , V_194 , & V_257 ) ;
V_192 -> V_258 = V_259 ;
return 0 ;
}
static int T_7 F_153 ( struct V_157 * V_158 ,
struct V_11 * V_12 ,
int V_35 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
int V_137 ;
int V_30 ;
unsigned short V_260 ;
V_12 -> V_173 = - 1 ;
V_12 -> V_158 = V_158 ;
F_154 ( V_12 -> V_2 , V_261 , & V_260 ) ;
switch ( V_260 & 0xff ) {
case 3 :
case 4 :
case 8 :
case 9 :
break;
default:
return - V_262 ;
}
if ( ( V_137 = F_155 ( V_2 ) ) < 0 )
return V_137 ;
F_156 ( & V_12 -> V_18 ) ;
if ( ( V_137 = F_157 ( V_2 , L_66 ) ) < 0 )
return V_137 ;
V_12 -> V_174 = F_158 ( V_2 , 0 ) ;
V_12 -> V_15 = F_159 ( V_12 -> V_174 , V_263 ) ;
if ( V_12 -> V_15 == NULL ) {
F_40 ( V_38 L_68 , V_12 -> V_174 , V_12 -> V_174 + V_263 - 1 ) ;
return - V_50 ;
}
if ( F_160 ( V_2 -> V_173 , F_108 , V_264 ,
L_66 , V_12 ) ) {
F_40 ( V_38 L_69 , V_2 -> V_173 ) ;
return - V_50 ;
}
V_12 -> V_173 = V_2 -> V_173 ;
V_12 -> V_35 = V_35 ;
V_30 = F_10 ( V_12 , V_21 ) ;
if ( F_39 ( V_30 & V_82 ) == 1 ) {
V_12 -> V_79 = 15 ;
} else {
V_12 -> V_79 = 11 ;
}
switch ( V_260 ) {
case 8 :
strcpy ( V_158 -> V_265 , L_70 ) ;
if ( V_12 -> V_79 == 15 ) {
V_12 -> V_83 = L_71 ;
} else {
V_12 -> V_83 = L_72 ;
}
V_12 -> V_54 = V_266 ;
break;
case 9 :
strcpy ( V_158 -> V_265 , L_70 ) ;
V_12 -> V_83 = L_73 ;
V_12 -> V_54 = V_266 ;
break;
case 4 :
strcpy ( V_158 -> V_265 , L_74 ) ;
V_12 -> V_83 = L_75 ;
V_12 -> V_54 = V_55 ;
break;
case 3 :
strcpy ( V_158 -> V_265 , L_74 ) ;
if ( V_12 -> V_79 == 15 ) {
V_12 -> V_83 = L_76 ;
} else {
V_12 -> V_83 = L_77 ;
}
V_12 -> V_54 = V_55 ;
break;
}
V_12 -> V_238 = ( V_12 -> V_54 - 2 ) / 2 + 2 ;
F_161 ( V_12 -> V_2 ) ;
if ( ( V_137 = F_104 ( V_12 ) ) < 0 ) {
return V_137 ;
}
if ( ( V_137 = F_150 ( V_158 , V_12 ) ) < 0 ) {
return V_137 ;
}
if ( ( V_137 = F_89 ( V_158 , V_12 ) ) < 0 ) {
return V_137 ;
}
F_95 ( V_12 ) ;
V_12 -> V_267 = - 1 ;
V_12 -> V_268 = - 1 ;
V_12 -> V_19 = - 1 ;
V_12 -> V_20 = - 1 ;
V_12 -> V_191 = NULL ;
V_12 -> V_196 = NULL ;
F_107 ( V_12 ) ;
if ( V_12 -> V_79 == 15 ) {
F_37 ( V_12 ) ;
}
return 0 ;
}
static void F_162 ( struct V_157 * V_158 )
{
struct V_11 * V_12 = (struct V_11 * ) V_158 -> V_148 ;
if ( V_12 )
F_99 ( V_12 ) ;
}
static int T_7 F_163 ( struct V_1 * V_2 ,
const struct V_269 * V_270 )
{
static int V_6 ;
struct V_11 * V_12 ;
struct V_157 * V_158 ;
int V_137 ;
if ( V_6 >= V_271 )
return - V_262 ;
if ( ! V_62 [ V_6 ] ) {
V_6 ++ ;
return - V_272 ;
}
V_137 = F_164 ( V_273 [ V_6 ] , V_253 [ V_6 ] , V_274 ,
sizeof( struct V_11 ) , & V_158 ) ;
if ( V_137 < 0 )
return V_137 ;
V_12 = (struct V_11 * ) V_158 -> V_148 ;
V_158 -> V_275 = F_162 ;
V_12 -> V_6 = V_6 ;
V_12 -> V_2 = V_2 ;
F_165 ( V_158 , & V_2 -> V_6 ) ;
if ( ( V_137 = F_153 ( V_158 , V_12 , V_35 [ V_6 ] ) ) < 0 ) {
F_166 ( V_158 ) ;
return V_137 ;
}
strcpy ( V_158 -> V_276 , V_12 -> V_83 ) ;
sprintf ( V_158 -> V_277 , L_78 ,
V_158 -> V_276 , V_12 -> V_174 , V_12 -> V_173 ) ;
if ( ( V_137 = F_167 ( V_158 ) ) < 0 ) {
F_166 ( V_158 ) ;
return V_137 ;
}
F_168 ( V_2 , V_158 ) ;
V_6 ++ ;
return 0 ;
}
static void T_11 F_169 ( struct V_1 * V_2 )
{
F_166 ( F_170 ( V_2 ) ) ;
F_168 ( V_2 , NULL ) ;
}
static int T_12 F_171 ( void )
{
return F_172 ( & V_265 ) ;
}
static void T_13 F_173 ( void )
{
F_174 ( & V_265 ) ;
}
