static inline unsigned F_1 ( unsigned int V_1 )
{
return ( ( V_1 << 13 ) + 62 ) / 125 ;
}
static inline unsigned F_2 ( unsigned int V_1 )
{
return ( ( V_1 << 10 ) + 62 ) / 125 ;
}
static int F_3 ( struct V_2 * V_3 , int V_4 , int V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 -> V_7 ;
unsigned int V_9 ;
int V_10 ;
V_3 -> V_11 = 0 ;
if ( ! V_4 && V_3 -> V_8 -> V_7 -> V_12 )
return - V_13 ;
V_10 = ! V_5 && V_7 -> V_14 ;
if ( ! V_10 && F_4 () )
return 0 ;
for ( V_9 = 0 ; V_9 < V_3 -> V_15 ; V_9 ++ ) {
if ( F_5 ( V_9 , & V_3 -> V_16 ) ) {
if ( ! F_6 ( V_9 , & V_3 -> V_17 ) ) {
struct V_18 * V_19 = V_3 -> V_20 [ V_9 ] . V_18 ;
if ( V_10 )
F_7 ( V_19 ) ;
else
F_8 ( V_19 ) ;
}
}
}
if ( V_3 -> V_21 ) {
for ( V_9 = 0 ; V_9 < V_22 ; V_9 ++ ) {
if ( F_5 ( V_9 + 16 , & V_3 -> V_16 ) ) {
if ( ! F_6 ( V_9 + 16 , & V_3 -> V_17 ) ) {
struct V_18 * V_19 = V_3 -> V_23 [ V_9 ] . V_18 ;
if ( V_10 )
F_7 ( V_19 ) ;
else
F_8 ( V_19 ) ;
}
}
}
}
return 0 ;
}
static void F_9 ( struct V_24 * V_19 )
{
if ( V_19 -> V_18 ) {
if ( V_19 -> V_25 )
F_10 ( V_19 -> V_3 -> V_26 , V_19 -> V_25 ,
V_19 -> V_18 -> V_27 ,
V_19 -> V_18 -> V_28 ) ;
F_11 ( V_19 -> V_18 ) ;
V_19 -> V_18 = NULL ;
}
}
static int F_12 ( struct V_2 * V_3 )
{
unsigned long V_29 = V_30 + F_13 ( 1000 ) ;
unsigned int V_9 ;
int V_31 ;
do {
V_31 = 0 ;
for ( V_9 = 0 ; V_9 < V_3 -> V_15 ; V_9 ++ ) {
if ( F_5 ( V_9 , & V_3 -> V_16 ) )
V_31 ++ ;
}
if ( V_3 -> V_21 ) {
for ( V_9 = 0 ; V_9 < V_22 ; V_9 ++ ) {
if ( F_5 ( V_9 + 16 , & V_3 -> V_16 ) )
V_31 ++ ;
}
}
if ( ! V_31 )
break;
F_14 ( 1 ) ;
} while ( F_15 ( V_30 , V_29 ) );
if ( V_31 )
F_16 ( V_32 L_1 , V_31 ) ;
return 0 ;
}
void F_17 ( struct V_2 * V_3 , int V_4 )
{
int V_9 ;
F_3 ( V_3 , V_4 , 1 ) ;
F_12 ( V_3 ) ;
for ( V_9 = 0 ; V_9 < V_33 ; V_9 ++ )
F_9 ( & V_3 -> V_20 [ V_9 ] ) ;
for ( V_9 = 0 ; V_9 < V_22 ; V_9 ++ )
F_9 ( & V_3 -> V_23 [ V_9 ] ) ;
F_10 ( V_3 -> V_26 , V_22 * 4 ,
V_3 -> V_34 , V_3 -> V_35 ) ;
V_3 -> V_34 = NULL ;
V_3 -> V_15 = 0 ;
}
static void F_18 ( struct V_18 * V_18 )
{
struct V_24 * V_36 = V_18 -> V_37 ;
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_38 * V_39 = V_36 -> V_3 -> V_40 ;
int V_41 = 0 ;
if ( ( V_3 -> V_11 && V_3 -> V_42 . V_43 ( V_3 , V_39 -> V_44 , V_18 ) ) ||
! V_3 -> V_11 ||
( V_41 = V_3 -> V_42 . V_45 ( V_3 , V_39 -> V_44 , V_18 ) ) < 0 ||
( V_41 = F_19 ( V_18 , V_46 ) ) < 0 ) {
F_20 ( V_36 -> V_47 , & V_3 -> V_16 ) ;
if ( V_41 < 0 ) {
F_21 ( V_32 L_2 , V_41 ) ;
F_22 ( V_39 , V_48 ) ;
}
}
}
static void F_23 ( struct V_18 * V_18 )
{
struct V_24 * V_36 = V_18 -> V_37 ;
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_38 * V_39 = V_36 -> V_3 -> V_40 ;
int V_41 = 0 ;
if ( ( V_3 -> V_11 && V_3 -> V_42 . V_49 ( V_3 , V_39 -> V_44 , V_18 ) ) ||
! V_3 -> V_11 ||
( V_41 = V_3 -> V_42 . V_50 ( V_3 , V_39 -> V_44 , V_18 ) ) < 0 ||
( V_41 = F_19 ( V_18 , V_46 ) ) < 0 ) {
F_20 ( V_36 -> V_47 + 16 , & V_3 -> V_16 ) ;
if ( V_41 < 0 ) {
F_21 ( V_32 L_3 , V_41 ) ;
F_22 ( V_39 , V_48 ) ;
}
}
}
int F_24 ( struct V_2 * V_3 ,
unsigned int V_51 ,
unsigned int V_1 ,
unsigned int V_52 )
{
unsigned int V_53 , V_9 ;
int V_54 = V_3 -> V_55 == V_56 ;
unsigned int V_57 , V_58 , V_59 ;
struct V_6 * V_7 = V_3 -> V_8 -> V_7 ;
if ( F_25 ( V_3 -> V_26 ) == V_60 )
V_3 -> V_61 = F_1 ( V_1 ) ;
else
V_3 -> V_61 = F_2 ( V_1 ) ;
V_3 -> V_62 = V_3 -> V_61 ;
V_3 -> V_63 = V_64 ;
if ( V_3 -> V_65 ) {
V_53 = V_3 -> V_65 ;
V_3 -> V_66 = ( V_53 / ( V_52 >> 3 ) )
<< ( 16 - V_3 -> V_67 ) ;
} else {
V_3 -> V_66 = V_3 -> V_61 + ( V_3 -> V_61 >> 2 ) ;
V_53 = ( ( V_3 -> V_66 + 0xffff ) * ( V_52 >> 3 ) )
>> ( 16 - V_3 -> V_67 ) ;
}
V_3 -> V_68 = 0 ;
if ( V_3 -> V_69 )
V_3 -> V_70 = V_3 -> V_65 ;
else
V_3 -> V_70 = V_53 ;
if ( F_25 ( V_3 -> V_26 ) != V_60 )
V_59 = 8 >> V_3 -> V_67 ;
else
V_59 = 1 ;
if ( V_54 ) {
V_57 = F_26 ( V_7 -> V_71 , 1 ) ;
V_57 = F_27 ( V_57 , ( unsigned int ) V_72 ) ;
} else
V_57 = 1 ;
V_57 *= V_59 ;
if ( V_3 -> V_21 )
V_57 = F_27 ( V_57 , 1U << V_3 -> V_73 ) ;
if ( V_54 ) {
unsigned int V_74 , V_75 ;
V_74 = ( V_3 -> V_61 >> ( 16 - V_3 -> V_67 ) )
* ( V_52 >> 3 ) ;
if ( V_3 -> V_21 )
V_74 -= V_74 >> 3 ;
V_74 = F_26 ( V_74 , 1u ) ;
V_58 = ( V_51 + V_74 - 1 ) / V_74 ;
if ( V_58 < 2 ) {
V_58 = 2 ;
} else {
V_75 = F_26 ( V_76 * V_59 , V_57 * 2 ) ;
V_58 = F_27 ( V_58 , V_75 ) ;
}
} else {
while ( V_57 > 1 && V_57 * V_53 >= V_51 )
V_57 >>= 1 ;
V_58 = V_33 * V_57 ;
}
V_3 -> V_15 = ( V_58 + V_57 - 1 ) / V_57 ;
if ( V_3 -> V_15 > V_33 ) {
V_3 -> V_15 = V_33 ;
V_58 = V_33 * V_57 ;
} else if ( V_3 -> V_15 < 2 ) {
V_3 -> V_15 = 2 ;
}
for ( V_9 = 0 ; V_9 < V_3 -> V_15 ; V_9 ++ ) {
struct V_24 * V_19 = & V_3 -> V_20 [ V_9 ] ;
V_19 -> V_47 = V_9 ;
V_19 -> V_3 = V_3 ;
V_19 -> V_77 = ( V_9 + 1 ) * V_58 / V_3 -> V_15
- V_9 * V_58 / V_3 -> V_15 ;
V_19 -> V_25 = V_53 * V_19 -> V_77 ;
if ( V_3 -> V_78 == V_79 )
V_19 -> V_77 ++ ;
V_19 -> V_18 = F_28 ( V_19 -> V_77 , V_80 ) ;
if ( ! V_19 -> V_18 )
goto V_81;
V_19 -> V_18 -> V_27 =
F_29 ( V_3 -> V_26 , V_19 -> V_25 ,
V_80 , & V_19 -> V_18 -> V_28 ) ;
if ( ! V_19 -> V_18 -> V_27 )
goto V_81;
V_19 -> V_18 -> V_82 = V_3 -> V_83 ;
V_19 -> V_18 -> V_84 = V_85 | V_86 ;
V_19 -> V_18 -> V_87 = 1 << V_3 -> V_67 ;
V_19 -> V_18 -> V_37 = V_19 ;
V_19 -> V_18 -> V_88 = F_18 ;
}
if ( V_3 -> V_21 ) {
V_3 -> V_34 = F_29 ( V_3 -> V_26 , V_22 * 4 ,
V_80 , & V_3 -> V_35 ) ;
if ( ! V_3 -> V_34 )
goto V_81;
for ( V_9 = 0 ; V_9 < V_22 ; V_9 ++ ) {
struct V_24 * V_19 = & V_3 -> V_23 [ V_9 ] ;
V_19 -> V_47 = V_9 ;
V_19 -> V_3 = V_3 ;
V_19 -> V_77 = 1 ;
V_19 -> V_18 = F_28 ( 1 , V_80 ) ;
if ( ! V_19 -> V_18 )
goto V_81;
V_19 -> V_18 -> V_27 = V_3 -> V_34 + V_9 * 4 ;
V_19 -> V_18 -> V_28 = V_3 -> V_35 + V_9 * 4 ;
V_19 -> V_18 -> V_89 = 4 ;
V_19 -> V_18 -> V_82 = V_3 -> V_21 ;
V_19 -> V_18 -> V_84 = V_85 |
V_86 ;
V_19 -> V_18 -> V_90 = 1 ;
V_19 -> V_18 -> V_87 = 1 << V_3 -> V_73 ;
V_19 -> V_18 -> V_37 = V_19 ;
V_19 -> V_18 -> V_88 = F_23 ;
}
}
return 0 ;
V_81:
F_17 ( V_3 , 0 ) ;
return - V_91 ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_92 * V_44 ,
struct V_18 * V_18 )
{
unsigned char * V_93 = V_18 -> V_27 ;
struct V_24 * V_36 = V_18 -> V_37 ;
V_18 -> V_26 = V_36 -> V_3 -> V_26 ;
V_18 -> V_94 [ 0 ] . V_95 = 3 ;
V_18 -> V_94 [ 0 ] . V_96 = 0 ;
V_93 [ 0 ] = V_3 -> V_61 >> 2 ;
V_93 [ 1 ] = V_3 -> V_61 >> 10 ;
V_93 [ 2 ] = V_3 -> V_61 >> 18 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 ,
struct V_92 * V_44 ,
struct V_18 * V_18 )
{
unsigned char * V_93 = V_18 -> V_27 ;
struct V_24 * V_36 = V_18 -> V_37 ;
V_18 -> V_26 = V_36 -> V_3 -> V_26 ;
V_18 -> V_94 [ 0 ] . V_95 = 4 ;
V_18 -> V_94 [ 0 ] . V_96 = 0 ;
V_93 [ 0 ] = V_3 -> V_61 ;
V_93 [ 1 ] = V_3 -> V_61 >> 8 ;
V_93 [ 2 ] = V_3 -> V_61 >> 16 ;
V_93 [ 3 ] = V_3 -> V_61 >> 24 ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_92 * V_44 ,
struct V_18 * V_18 )
{
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_92 * V_44 ,
struct V_18 * V_18 )
{
int V_9 , V_97 ;
struct V_24 * V_36 = V_18 -> V_37 ;
V_97 = 0 ;
V_18 -> V_26 = V_36 -> V_3 -> V_26 ;
for ( V_9 = 0 ; V_9 < V_36 -> V_77 ; V_9 ++ ) {
V_18 -> V_94 [ V_9 ] . V_96 = V_97 ;
V_18 -> V_94 [ V_9 ] . V_95 = V_3 -> V_70 ;
V_97 += V_3 -> V_70 ;
}
V_18 -> V_89 = V_97 ;
V_18 -> V_90 = V_36 -> V_77 ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_92 * V_44 ,
struct V_18 * V_18 )
{
unsigned long V_98 ;
unsigned char * V_93 ;
int V_9 ;
unsigned int V_99 , V_100 , V_101 , V_102 ;
int V_103 = 0 ;
V_99 = V_44 -> V_52 >> 3 ;
for ( V_9 = 0 ; V_9 < V_18 -> V_90 ; V_9 ++ ) {
V_93 = ( unsigned char * ) V_18 -> V_27 + V_18 -> V_94 [ V_9 ] . V_96 ;
if ( V_18 -> V_94 [ V_9 ] . V_104 ) {
F_21 ( V_32 L_4 , V_9 , V_18 -> V_94 [ V_9 ] . V_104 ) ;
}
V_101 = V_18 -> V_94 [ V_9 ] . V_105 ;
V_100 = V_101 / V_99 ;
if ( ! V_3 -> V_106 )
V_101 = V_100 * V_99 ;
if ( V_101 % ( V_44 -> V_107 >> 3 ) != 0 ) {
#ifdef F_35
int V_108 = V_101 ;
#endif
V_101 = V_100 * V_99 ;
F_36 ( V_32 L_5 ,
V_108 , V_101 ) ;
}
F_37 ( & V_3 -> V_109 , V_98 ) ;
V_102 = V_3 -> V_110 ;
V_3 -> V_110 += V_101 ;
if ( V_3 -> V_110 >= V_44 -> V_25 * V_99 )
V_3 -> V_110 -= V_44 -> V_25 * V_99 ;
V_100 = ( V_101 + ( V_102 % V_99 ) ) / V_99 ;
V_3 -> V_111 += V_100 ;
if ( V_3 -> V_111 >= V_44 -> V_112 ) {
V_3 -> V_111 -= V_44 -> V_112 ;
V_103 = 1 ;
}
F_38 ( & V_3 -> V_109 , V_98 ) ;
if ( V_102 + V_101 > V_44 -> V_25 * V_99 ) {
unsigned int V_113 =
V_44 -> V_25 * V_99 - V_102 ;
memcpy ( V_44 -> V_114 + V_102 , V_93 , V_113 ) ;
memcpy ( V_44 -> V_114 , V_93 + V_113 , V_101 - V_113 ) ;
} else {
memcpy ( V_44 -> V_114 + V_102 , V_93 , V_101 ) ;
}
}
if ( V_103 )
F_39 ( V_3 -> V_40 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 ,
struct V_92 * V_44 ,
struct V_18 * V_18 )
{
return 0 ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_92 * V_44 ,
struct V_18 * V_18 )
{
struct V_24 * V_36 = V_18 -> V_37 ;
V_18 -> V_26 = V_36 -> V_3 -> V_26 ;
V_18 -> V_94 [ 0 ] . V_95 = F_27 ( 4u , V_36 -> V_3 -> V_115 ) ;
V_18 -> V_94 [ 0 ] . V_96 = 0 ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 ,
struct V_92 * V_44 ,
struct V_18 * V_18 )
{
unsigned int V_116 ;
int V_117 ;
unsigned long V_98 ;
if ( V_18 -> V_94 [ 0 ] . V_104 != 0 ||
V_18 -> V_94 [ 0 ] . V_105 < 3 )
return 0 ;
V_116 = F_43 ( V_18 -> V_27 ) ;
if ( V_18 -> V_94 [ 0 ] . V_105 == 3 )
V_116 &= 0x00ffffff ;
else
V_116 &= 0x0fffffff ;
if ( V_116 == 0 )
return 0 ;
if ( F_44 ( V_3 -> V_63 == V_64 ) ) {
V_117 = 0 ;
while ( V_116 < V_3 -> V_61 - V_3 -> V_61 / 4 ) {
V_116 <<= 1 ;
V_117 ++ ;
}
while ( V_116 > V_3 -> V_61 + V_3 -> V_61 / 2 ) {
V_116 >>= 1 ;
V_117 -- ;
}
V_3 -> V_63 = V_117 ;
}
else if ( V_3 -> V_63 >= 0 )
V_116 <<= V_3 -> V_63 ;
else
V_116 >>= - V_3 -> V_63 ;
if ( F_45 ( V_116 >= V_3 -> V_61 - V_3 -> V_61 / 8 && V_116 <= V_3 -> V_66 ) ) {
F_37 ( & V_3 -> V_109 , V_98 ) ;
V_3 -> V_62 = V_116 ;
F_38 ( & V_3 -> V_109 , V_98 ) ;
} else {
V_3 -> V_63 = V_64 ;
}
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
if ( V_3 -> V_69 )
return V_3 -> V_118 ;
else {
V_3 -> V_68 = ( V_3 -> V_68 & 0xffff )
+ ( V_3 -> V_62 << V_3 -> V_67 ) ;
return F_27 ( V_3 -> V_68 >> 16 , V_3 -> V_118 ) ;
}
}
static int F_47 ( struct V_2 * V_3 ,
struct V_92 * V_44 ,
struct V_18 * V_18 )
{
unsigned int V_9 , V_97 , V_119 ;
struct V_24 * V_36 = V_18 -> V_37 ;
int V_99 = V_44 -> V_52 >> 3 ;
V_97 = 0 ;
V_18 -> V_26 = V_36 -> V_3 -> V_26 ;
for ( V_9 = 0 ; V_9 < V_36 -> V_77 ; ++ V_9 ) {
V_119 = F_46 ( V_3 ) ;
V_18 -> V_94 [ V_9 ] . V_96 = V_97 * V_99 ;
V_18 -> V_94 [ V_9 ] . V_95 = V_119 * V_99 ;
V_97 += V_119 ;
}
V_18 -> V_90 = V_36 -> V_77 ;
V_18 -> V_89 = V_97 * V_99 ;
memset ( V_18 -> V_27 ,
V_44 -> V_120 == V_121 ? 0x80 : 0 ,
V_97 * V_99 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_3 ,
struct V_92 * V_44 ,
struct V_18 * V_18 )
{
int V_9 , V_99 ;
unsigned int V_119 , V_100 , V_101 ;
unsigned long V_98 ;
int V_103 = 0 ;
struct V_24 * V_36 = V_18 -> V_37 ;
V_99 = V_44 -> V_52 >> 3 ;
V_100 = 0 ;
V_18 -> V_26 = V_36 -> V_3 -> V_26 ;
V_18 -> V_90 = 0 ;
F_37 ( & V_3 -> V_109 , V_98 ) ;
for ( V_9 = 0 ; V_9 < V_36 -> V_77 ; V_9 ++ ) {
V_119 = F_46 ( V_3 ) ;
V_18 -> V_94 [ V_9 ] . V_96 = V_100 * V_99 ;
V_18 -> V_94 [ V_9 ] . V_95 = V_119 * V_99 ;
V_100 += V_119 ;
V_18 -> V_90 ++ ;
V_3 -> V_111 += V_119 ;
if ( V_3 -> V_111 >= V_44 -> V_112 ) {
V_3 -> V_111 -= V_44 -> V_112 ;
V_103 = 1 ;
if ( V_3 -> V_78 == V_79 ) {
if ( V_3 -> V_111 > 0 ) {
V_100 -= V_3 -> V_111 ;
V_119 -= V_3 -> V_111 ;
V_18 -> V_94 [ V_9 ] . V_95 =
V_119 * V_99 ;
V_3 -> V_111 = 0 ;
}
V_9 ++ ;
if ( V_9 < V_36 -> V_77 ) {
V_18 -> V_94 [ V_9 ] . V_96 =
V_100 * V_99 ;
V_18 -> V_94 [ V_9 ] . V_95 = 0 ;
V_18 -> V_90 ++ ;
}
break;
}
}
if ( V_103 )
break;
}
V_101 = V_100 * V_99 ;
if ( V_3 -> V_110 + V_101 > V_44 -> V_25 * V_99 ) {
unsigned int V_113 =
V_44 -> V_25 * V_99 - V_3 -> V_110 ;
memcpy ( V_18 -> V_27 ,
V_44 -> V_114 + V_3 -> V_110 , V_113 ) ;
memcpy ( V_18 -> V_27 + V_113 ,
V_44 -> V_114 , V_101 - V_113 ) ;
} else {
memcpy ( V_18 -> V_27 ,
V_44 -> V_114 + V_3 -> V_110 , V_101 ) ;
}
V_3 -> V_110 += V_101 ;
if ( V_3 -> V_110 >= V_44 -> V_25 * V_99 )
V_3 -> V_110 -= V_44 -> V_25 * V_99 ;
V_44 -> V_122 += V_100 ;
F_38 ( & V_3 -> V_109 , V_98 ) ;
V_18 -> V_89 = V_101 ;
if ( V_103 )
F_39 ( V_3 -> V_40 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_3 ,
struct V_92 * V_44 ,
struct V_18 * V_18 )
{
unsigned long V_98 ;
int V_99 = V_44 -> V_52 >> 3 ;
int V_123 = V_18 -> V_89 / V_99 ;
F_37 ( & V_3 -> V_109 , V_98 ) ;
if ( V_123 > V_44 -> V_122 )
V_44 -> V_122 = 0 ;
else
V_44 -> V_122 -= V_123 ;
F_38 ( & V_3 -> V_109 , V_98 ) ;
return 0 ;
}
static const char * F_50 ( int V_41 )
{
switch ( V_41 ) {
case - V_124 :
return L_6 ;
case - V_125 :
return L_7 ;
case - V_126 :
return L_8 ;
case - V_127 :
return L_9 ;
case - V_128 :
return L_10 ;
case - V_129 :
return L_11 ;
case - V_130 :
case - V_131 :
case - V_132 :
case - V_133 :
return L_12 ;
default:
return L_13 ;
}
}
static int F_51 ( struct V_2 * V_3 , struct V_92 * V_44 )
{
unsigned int V_9 ;
int V_41 ;
if ( V_3 -> V_8 -> V_7 -> V_12 )
return - V_13 ;
for ( V_9 = 0 ; V_9 < V_3 -> V_15 ; V_9 ++ ) {
if ( F_52 ( ! V_3 -> V_20 [ V_9 ] . V_18 ) )
return - V_130 ;
if ( V_3 -> V_42 . V_45 ( V_3 , V_44 , V_3 -> V_20 [ V_9 ] . V_18 ) < 0 ) {
F_16 ( V_32 L_14 , V_9 ) ;
goto V_134;
}
}
if ( V_3 -> V_21 ) {
for ( V_9 = 0 ; V_9 < V_22 ; V_9 ++ ) {
if ( F_52 ( ! V_3 -> V_23 [ V_9 ] . V_18 ) )
return - V_130 ;
if ( V_3 -> V_42 . V_50 ( V_3 , V_44 , V_3 -> V_23 [ V_9 ] . V_18 ) < 0 ) {
F_16 ( V_32 L_15 , V_9 ) ;
goto V_134;
}
}
}
V_3 -> V_16 = 0 ;
V_3 -> V_17 = 0 ;
V_3 -> V_11 = 1 ;
for ( V_9 = 0 ; V_9 < V_3 -> V_15 ; V_9 ++ ) {
V_41 = F_19 ( V_3 -> V_20 [ V_9 ] . V_18 , V_46 ) ;
if ( V_41 < 0 ) {
F_16 ( V_32 L_16
L_17 ,
V_9 , V_41 , F_50 ( V_41 ) ) ;
goto V_134;
}
F_53 ( V_9 , & V_3 -> V_16 ) ;
}
if ( V_3 -> V_21 ) {
for ( V_9 = 0 ; V_9 < V_22 ; V_9 ++ ) {
V_41 = F_19 ( V_3 -> V_23 [ V_9 ] . V_18 , V_46 ) ;
if ( V_41 < 0 ) {
F_16 ( V_32 L_18
L_17 ,
V_9 , V_41 , F_50 ( V_41 ) ) ;
goto V_134;
}
F_53 ( V_9 + 16 , & V_3 -> V_16 ) ;
}
}
return 0 ;
V_134:
F_3 ( V_3 , 0 , 0 ) ;
return - V_126 ;
}
void F_54 ( struct V_135 * V_136 ,
int V_8 , struct V_137 * V_138 )
{
struct V_2 * V_3 = & V_136 -> V_39 [ V_8 ] ;
F_55 ( & V_3 -> V_139 ) ;
F_56 ( & V_3 -> V_109 ) ;
V_3 -> V_8 = V_136 ;
V_3 -> V_55 = V_8 ;
V_3 -> V_26 = V_136 -> V_7 -> V_26 ;
V_3 -> V_106 = V_136 -> V_7 -> V_106 ;
V_3 -> V_42 = V_140 [ V_8 ] ;
if ( F_25 ( V_3 -> V_26 ) >= V_141 )
V_3 -> V_42 . V_50 = F_31 ;
F_57 ( V_136 -> V_142 , V_8 ) ;
F_58 ( & V_138 -> V_143 , & V_3 -> V_139 ) ;
V_3 -> V_144 |= V_138 -> V_144 ;
V_3 -> V_145 = V_138 -> V_145 ;
V_3 -> V_146 ++ ;
V_3 -> V_78 = V_138 -> V_78 ;
}
int F_59 ( struct V_38 * V_39 , int V_147 )
{
struct V_2 * V_3 = V_39 -> V_44 -> V_148 ;
switch ( V_147 ) {
case V_149 :
case V_150 :
V_3 -> V_42 . V_45 = F_48 ;
return 0 ;
case V_151 :
return F_3 ( V_3 , 0 , 0 ) ;
case V_152 :
V_3 -> V_42 . V_45 = F_47 ;
return 0 ;
}
return - V_130 ;
}
int F_60 ( struct V_38 * V_39 , int V_147 )
{
struct V_2 * V_3 = V_39 -> V_44 -> V_148 ;
switch ( V_147 ) {
case V_149 :
V_3 -> V_42 . V_43 = F_34 ;
return F_51 ( V_3 , V_39 -> V_44 ) ;
case V_151 :
return F_3 ( V_3 , 0 , 0 ) ;
case V_152 :
V_3 -> V_42 . V_43 = F_40 ;
return 0 ;
case V_150 :
V_3 -> V_42 . V_43 = F_34 ;
return 0 ;
}
return - V_130 ;
}
int F_61 ( struct V_2 * V_3 ,
struct V_92 * V_44 )
{
F_3 ( V_3 , 0 , 1 ) ;
F_12 ( V_3 ) ;
if ( V_3 -> V_55 == V_56 ) {
V_3 -> V_42 . V_45 = F_47 ;
return F_51 ( V_3 , V_44 ) ;
}
return 0 ;
}
