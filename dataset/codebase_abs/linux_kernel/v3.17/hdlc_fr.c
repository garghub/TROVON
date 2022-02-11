static inline T_1 F_1 ( T_2 * V_1 )
{
return ( ( V_1 [ 0 ] & 0xFC ) << 2 ) | ( ( V_1 [ 1 ] & 0xF0 ) >> 4 ) ;
}
static inline void F_2 ( T_2 * V_1 , T_1 V_2 )
{
V_1 [ 0 ] = ( V_2 >> 2 ) & 0xFC ;
V_1 [ 1 ] = ( ( V_2 << 4 ) & 0xF0 ) | 0x01 ;
}
static inline struct V_3 * F_3 ( T_3 * V_4 )
{
return (struct V_3 * ) ( V_4 -> F_3 ) ;
}
static inline struct V_5 * F_4 ( T_3 * V_4 , T_1 V_2 )
{
struct V_5 * V_6 = F_3 ( V_4 ) -> V_7 ;
while ( V_6 ) {
if ( V_6 -> V_2 == V_2 )
return V_6 ;
if ( V_6 -> V_2 > V_2 )
return NULL ;
V_6 = V_6 -> V_8 ;
}
return NULL ;
}
static struct V_5 * F_5 ( struct V_9 * V_10 , T_1 V_2 )
{
T_3 * V_4 = F_6 ( V_10 ) ;
struct V_5 * V_6 , * * V_11 = & F_3 ( V_4 ) -> V_7 ;
while ( * V_11 ) {
if ( ( * V_11 ) -> V_2 == V_2 )
return * V_11 ;
if ( ( * V_11 ) -> V_2 > V_2 )
break;
V_11 = & ( * V_11 ) -> V_8 ;
}
V_6 = F_7 ( sizeof( * V_6 ) , V_12 ) ;
#ifdef F_8
F_9 ( V_13 L_1 , V_6 , V_10 ) ;
#endif
if ( ! V_6 )
return NULL ;
V_6 -> V_2 = V_2 ;
V_6 -> V_14 = V_10 ;
V_6 -> V_8 = * V_11 ;
* V_11 = V_6 ;
return V_6 ;
}
static inline int F_10 ( struct V_5 * V_6 )
{
return V_6 -> main || V_6 -> V_15 ;
}
static inline void F_11 ( int V_16 , struct V_5 * V_6 )
{
if ( V_16 ) {
if ( V_6 -> main)
if ( ! F_12 ( V_6 -> main ) )
F_13 ( V_6 -> main ) ;
if ( V_6 -> V_15 )
if ( ! F_12 ( V_6 -> V_15 ) )
F_13 ( V_6 -> V_15 ) ;
} else {
if ( V_6 -> main)
if ( F_12 ( V_6 -> main ) )
F_14 ( V_6 -> main ) ;
if ( V_6 -> V_15 )
if ( F_12 ( V_6 -> V_15 ) )
F_14 ( V_6 -> V_15 ) ;
}
}
static inline void F_15 ( T_3 * V_4 )
{
struct V_5 * * V_11 = & F_3 ( V_4 ) -> V_7 ;
while ( * V_11 ) {
if ( ! F_10 ( * V_11 ) ) {
struct V_5 * V_6 = * V_11 ;
#ifdef F_8
F_9 ( V_13 L_2 , V_6 ) ;
#endif
* V_11 = V_6 -> V_8 ;
F_16 ( V_6 ) ;
continue;
}
V_11 = & ( * V_11 ) -> V_8 ;
}
}
static inline struct V_9 * * F_17 ( struct V_5 * V_6 ,
int type )
{
if ( type == V_17 )
return & V_6 -> V_15 ;
else
return & V_6 -> main;
}
static int F_18 ( struct V_18 * * V_19 , T_1 V_2 )
{
T_1 V_20 ;
struct V_18 * V_21 = * V_19 ;
switch ( V_21 -> V_22 ) {
case F_19 ( V_23 ) :
V_20 = 4 ;
F_20 ( V_21 , V_20 ) ;
V_21 -> V_24 [ 3 ] = V_23 ;
break;
case F_19 ( V_25 ) :
V_20 = 4 ;
F_20 ( V_21 , V_20 ) ;
V_21 -> V_24 [ 3 ] = V_25 ;
break;
case F_19 ( V_26 ) :
V_20 = 4 ;
F_20 ( V_21 , V_20 ) ;
V_21 -> V_24 [ 3 ] = V_27 ;
break;
case F_19 ( V_28 ) :
V_20 = 4 ;
F_20 ( V_21 , V_20 ) ;
V_21 -> V_24 [ 3 ] = V_29 ;
break;
case F_19 ( V_30 ) :
V_20 = 10 ;
if ( F_21 ( V_21 ) < V_20 ) {
struct V_18 * V_31 = F_22 ( V_21 ,
V_20 ) ;
if ( ! V_31 )
return - V_32 ;
F_23 ( V_21 ) ;
V_21 = * V_19 = V_31 ;
}
F_20 ( V_21 , V_20 ) ;
V_21 -> V_24 [ 3 ] = V_33 ;
V_21 -> V_24 [ 4 ] = V_34 ;
V_21 -> V_24 [ 5 ] = V_33 ;
V_21 -> V_24 [ 6 ] = 0x80 ;
V_21 -> V_24 [ 7 ] = 0xC2 ;
V_21 -> V_24 [ 8 ] = 0x00 ;
V_21 -> V_24 [ 9 ] = 0x07 ;
break;
default:
V_20 = 10 ;
F_20 ( V_21 , V_20 ) ;
V_21 -> V_24 [ 3 ] = V_33 ;
V_21 -> V_24 [ 4 ] = V_34 ;
V_21 -> V_24 [ 5 ] = V_33 ;
V_21 -> V_24 [ 6 ] = V_33 ;
V_21 -> V_24 [ 7 ] = V_33 ;
* ( V_35 * ) ( V_21 -> V_24 + 8 ) = V_21 -> V_22 ;
}
F_2 ( V_21 -> V_24 , V_2 ) ;
V_21 -> V_24 [ 2 ] = V_36 ;
return 0 ;
}
static int F_24 ( struct V_9 * V_10 )
{
struct V_5 * V_6 = V_10 -> V_37 ;
if ( ( V_6 -> V_14 -> V_38 & V_39 ) == 0 )
return - V_40 ;
if ( V_6 -> V_41 ++ == 0 ) {
T_3 * V_4 = F_6 ( V_6 -> V_14 ) ;
if ( F_3 ( V_4 ) -> V_42 . V_43 == V_44 )
V_6 -> F_3 . V_45 = F_12 ( V_6 -> V_14 ) ;
F_11 ( V_6 -> F_3 . V_45 , V_6 ) ;
F_3 ( V_4 ) -> V_46 = 1 ;
}
return 0 ;
}
static int F_25 ( struct V_9 * V_10 )
{
struct V_5 * V_6 = V_10 -> V_37 ;
if ( -- V_6 -> V_41 == 0 ) {
T_3 * V_4 = F_6 ( V_6 -> V_14 ) ;
if ( F_3 ( V_4 ) -> V_42 . V_43 == V_44 )
V_6 -> F_3 . V_45 = 0 ;
if ( F_3 ( V_4 ) -> V_42 . V_47 ) {
F_3 ( V_4 ) -> V_46 = 1 ;
V_6 -> F_3 . V_45 = 0 ;
}
}
return 0 ;
}
static int F_26 ( struct V_9 * V_10 , struct V_48 * V_49 , int V_50 )
{
struct V_5 * V_6 = V_10 -> V_37 ;
T_4 V_51 ;
if ( V_49 -> V_52 . type == V_53 ) {
if ( V_10 -> type == V_17 )
V_49 -> V_52 . type = V_54 ;
else
V_49 -> V_52 . type = V_55 ;
if ( V_49 -> V_52 . V_56 < sizeof( V_51 ) ) {
V_49 -> V_52 . V_56 = sizeof( V_51 ) ;
return - V_32 ;
}
V_51 . V_2 = V_6 -> V_2 ;
memcpy ( V_51 . V_57 , V_6 -> V_14 -> V_58 , V_59 ) ;
if ( F_27 ( V_49 -> V_52 . V_60 . V_61 ,
& V_51 , sizeof( V_51 ) ) )
return - V_62 ;
return 0 ;
}
return - V_63 ;
}
static T_5 F_28 ( struct V_18 * V_21 , struct V_9 * V_10 )
{
struct V_5 * V_6 = V_10 -> V_37 ;
if ( V_6 -> F_3 . V_45 ) {
if ( V_10 -> type == V_17 ) {
int V_64 = V_65 - V_21 -> V_66 ;
if ( V_64 > 0 ) {
int V_66 = V_21 -> V_66 ;
if ( F_29 ( V_21 ) < V_64 )
if ( F_30 ( V_21 , 0 , V_64 ,
V_12 ) ) {
V_10 -> V_67 . V_68 ++ ;
F_23 ( V_21 ) ;
return V_69 ;
}
F_31 ( V_21 , V_64 ) ;
memset ( V_21 -> V_24 + V_66 , 0 , V_64 ) ;
}
V_21 -> V_22 = F_19 ( V_30 ) ;
}
if ( ! F_18 ( & V_21 , V_6 -> V_2 ) ) {
V_10 -> V_67 . V_70 += V_21 -> V_66 ;
V_10 -> V_67 . V_71 ++ ;
if ( V_6 -> F_3 . V_72 )
V_10 -> V_67 . V_73 ++ ;
V_21 -> V_10 = V_6 -> V_14 ;
F_32 ( V_21 ) ;
return V_69 ;
}
}
V_10 -> V_67 . V_68 ++ ;
F_23 ( V_21 ) ;
return V_69 ;
}
static inline void F_33 ( struct V_5 * V_6 )
{
F_34 ( V_6 -> V_14 , L_3 ,
V_6 -> V_2 ,
V_6 -> main ? V_6 -> main-> V_58 : L_4 ,
V_6 -> main && V_6 -> V_15 ? L_5 : L_4 ,
V_6 -> V_15 ? V_6 -> V_15 -> V_58 : L_4 ,
V_6 -> F_3 . V_74 ? L_6 : L_4 ,
! V_6 -> F_3 . V_75 ? L_7 :
V_6 -> F_3 . V_45 ? L_8 : L_9 ) ;
}
static inline T_2 F_35 ( T_2 V_76 )
{
V_76 ++ ;
return V_76 ? V_76 : 1 ;
}
static void F_36 ( struct V_9 * V_10 , int V_77 )
{
T_3 * V_4 = F_6 ( V_10 ) ;
struct V_18 * V_21 ;
struct V_5 * V_6 = F_3 ( V_4 ) -> V_7 ;
int V_43 = F_3 ( V_4 ) -> V_42 . V_43 ;
int V_47 = F_3 ( V_4 ) -> V_42 . V_47 ;
int V_66 = V_43 == V_78 ? V_79 : V_80 ;
int V_81 = ( V_43 == V_82 ) ? 6 : 3 ;
T_2 * V_24 ;
int V_83 = 0 ;
if ( V_47 && V_77 ) {
V_66 += F_3 ( V_4 ) -> V_84 * ( 2 + V_81 ) ;
if ( V_66 > V_85 ) {
F_37 ( V_10 , L_10 ) ;
return;
}
}
V_21 = F_38 ( V_66 ) ;
if ( ! V_21 ) {
F_37 ( V_10 , L_11 ) ;
return;
}
memset ( V_21 -> V_24 , 0 , V_66 ) ;
F_39 ( V_21 , 4 ) ;
if ( V_43 == V_82 ) {
V_21 -> V_22 = F_19 ( V_25 ) ;
F_18 ( & V_21 , V_86 ) ;
} else {
V_21 -> V_22 = F_19 ( V_23 ) ;
F_18 ( & V_21 , V_87 ) ;
}
V_24 = F_40 ( V_21 ) ;
V_24 [ V_83 ++ ] = V_88 ;
V_24 [ V_83 ++ ] = V_47 ? V_89 : V_90 ;
if ( V_43 == V_78 )
V_24 [ V_83 ++ ] = V_91 ;
V_24 [ V_83 ++ ] = V_43 == V_92 ? V_93 :
V_94 ;
V_24 [ V_83 ++ ] = V_95 ;
V_24 [ V_83 ++ ] = V_77 ? V_96 : V_97 ;
V_24 [ V_83 ++ ] = V_43 == V_92 ? V_98 : V_99 ;
V_24 [ V_83 ++ ] = V_100 ;
V_24 [ V_83 ++ ] = F_3 ( V_4 ) -> V_101 =
F_35 ( F_3 ( V_4 ) -> V_101 ) ;
V_24 [ V_83 ++ ] = F_3 ( V_4 ) -> V_102 ;
if ( V_47 && V_77 ) {
while ( V_6 ) {
V_24 [ V_83 ++ ] = V_43 == V_92 ? V_103 :
V_104 ;
V_24 [ V_83 ++ ] = V_81 ;
if ( F_3 ( V_4 ) -> V_105 && ! V_6 -> F_3 . V_75 ) {
V_6 -> F_3 . V_75 = V_6 -> F_3 . V_74 = 1 ;
F_33 ( V_6 ) ;
}
if ( V_6 -> V_41 && ! V_6 -> F_3 . V_45 &&
V_6 -> F_3 . V_75 && ! V_6 -> F_3 . V_74 ) {
F_11 ( 1 , V_6 ) ;
V_6 -> F_3 . V_45 = 1 ;
F_33 ( V_6 ) ;
}
if ( V_43 == V_82 ) {
V_24 [ V_83 ] = V_6 -> V_2 >> 8 ;
V_24 [ V_83 + 1 ] = V_6 -> V_2 & 0xFF ;
} else {
V_24 [ V_83 ] = ( V_6 -> V_2 >> 4 ) & 0x3F ;
V_24 [ V_83 + 1 ] = ( ( V_6 -> V_2 << 3 ) & 0x78 ) | 0x80 ;
V_24 [ V_83 + 2 ] = 0x80 ;
}
if ( V_6 -> F_3 . V_74 )
V_24 [ V_83 + 2 ] |= 0x08 ;
else if ( V_6 -> F_3 . V_45 )
V_24 [ V_83 + 2 ] |= 0x02 ;
V_83 += V_81 ;
V_6 = V_6 -> V_8 ;
}
}
F_31 ( V_21 , V_83 ) ;
V_21 -> V_106 = V_107 ;
V_21 -> V_10 = V_10 ;
F_41 ( V_21 ) ;
F_32 ( V_21 ) ;
}
static void F_42 ( int V_105 , struct V_9 * V_10 )
{
T_3 * V_4 = F_6 ( V_10 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) -> V_7 ;
F_3 ( V_4 ) -> V_105 = V_105 ;
if ( V_105 ) {
F_43 ( V_10 ) ;
F_3 ( V_4 ) -> V_108 = 0 ;
F_3 ( V_4 ) -> V_46 = 1 ;
if ( F_3 ( V_4 ) -> V_42 . V_43 == V_44 ) {
while ( V_6 ) {
F_11 ( 1 , V_6 ) ;
V_6 -> F_3 . V_75 = V_6 -> F_3 . V_45 = 1 ;
V_6 -> F_3 . V_74 = 0 ;
V_6 = V_6 -> V_8 ;
}
}
} else {
F_44 ( V_10 ) ;
while ( V_6 ) {
F_11 ( 0 , V_6 ) ;
V_6 -> F_3 . V_75 = V_6 -> F_3 . V_45 = 0 ;
V_6 -> F_3 . V_74 = 0 ;
if ( ! F_3 ( V_4 ) -> V_42 . V_47 )
V_6 -> F_3 . V_109 = 0 ;
V_6 = V_6 -> V_8 ;
}
}
}
static void F_45 ( unsigned long V_110 )
{
struct V_9 * V_10 = (struct V_9 * ) V_110 ;
T_3 * V_4 = F_6 ( V_10 ) ;
int V_83 , V_111 = 0 , V_105 ;
T_6 V_112 ;
if ( F_3 ( V_4 ) -> V_42 . V_47 ) {
V_105 = F_3 ( V_4 ) -> V_113 &&
F_46 ( V_114 , F_3 ( V_4 ) -> V_115 +
F_3 ( V_4 ) -> V_42 . V_116 * V_117 ) ;
F_3 ( V_4 ) -> V_113 = 0 ;
} else {
F_3 ( V_4 ) -> V_118 <<= 1 ;
if ( F_3 ( V_4 ) -> V_113 ) {
if ( F_3 ( V_4 ) -> V_105 )
F_34 ( V_10 , L_12 ) ;
F_3 ( V_4 ) -> V_118 |= 1 ;
}
V_112 = F_3 ( V_4 ) -> V_118 ;
for ( V_83 = 0 ; V_83 < F_3 ( V_4 ) -> V_42 . V_119 ; V_83 ++ , V_112 >>= 1 )
V_111 += ( V_112 & 1 ) ;
V_105 = ( V_111 < F_3 ( V_4 ) -> V_42 . V_120 ) ;
}
if ( F_3 ( V_4 ) -> V_105 != V_105 ) {
F_34 ( V_10 , L_13 , V_105 ? L_4 : L_14 ) ;
F_42 ( V_105 , V_10 ) ;
}
if ( F_3 ( V_4 ) -> V_42 . V_47 )
F_3 ( V_4 ) -> V_121 . V_122 = V_114 +
F_3 ( V_4 ) -> V_42 . V_116 * V_117 ;
else {
if ( F_3 ( V_4 ) -> V_108 )
F_3 ( V_4 ) -> V_108 -- ;
F_36 ( V_10 , F_3 ( V_4 ) -> V_108 == 0 ) ;
F_3 ( V_4 ) -> V_115 = V_114 ;
F_3 ( V_4 ) -> V_113 = 1 ;
F_3 ( V_4 ) -> V_121 . V_122 = V_114 +
F_3 ( V_4 ) -> V_42 . V_123 * V_117 ;
}
F_3 ( V_4 ) -> V_121 . V_124 = F_45 ;
F_3 ( V_4 ) -> V_121 . V_24 = V_110 ;
F_47 ( & F_3 ( V_4 ) -> V_121 ) ;
}
static int F_48 ( struct V_9 * V_10 , struct V_18 * V_21 )
{
T_3 * V_4 = F_6 ( V_10 ) ;
struct V_5 * V_6 ;
T_2 V_102 , V_101 ;
int V_43 = F_3 ( V_4 ) -> V_42 . V_43 ;
int V_47 = F_3 ( V_4 ) -> V_42 . V_47 ;
int V_81 = ( V_43 == V_82 ) ? 6 : 3 , V_125 , error , V_126 , V_83 ;
if ( V_21 -> V_66 < ( V_43 == V_78 ? V_79 :
V_80 ) ) {
F_34 ( V_10 , L_15 ) ;
return 1 ;
}
if ( V_21 -> V_24 [ 3 ] != ( V_43 == V_82 ? V_25 :
V_23 ) ) {
F_34 ( V_10 , L_16 ) ;
return 1 ;
}
if ( V_21 -> V_24 [ 4 ] != V_88 ) {
F_34 ( V_10 , L_17 ,
V_21 -> V_24 [ 4 ] ) ;
return 1 ;
}
if ( V_21 -> V_24 [ 5 ] != ( V_47 ? V_90 : V_89 ) ) {
F_34 ( V_10 , L_18 ,
V_21 -> V_24 [ 5 ] ) ;
return 1 ;
}
if ( V_43 == V_78 ) {
if ( V_21 -> V_24 [ 6 ] != V_91 ) {
F_34 ( V_10 , L_19 ,
V_21 -> V_24 [ 6 ] ) ;
return 1 ;
}
V_83 = 7 ;
} else
V_83 = 6 ;
if ( V_21 -> V_24 [ V_83 ] != ( V_43 == V_92 ? V_93 :
V_94 ) ) {
F_34 ( V_10 , L_20 ,
V_21 -> V_24 [ V_83 ] ) ;
return 1 ;
}
if ( V_21 -> V_24 [ ++ V_83 ] != V_95 ) {
F_34 ( V_10 , L_21 ,
V_21 -> V_24 [ V_83 ] ) ;
return 1 ;
}
V_125 = V_21 -> V_24 [ ++ V_83 ] ;
if ( V_125 != V_97 && V_125 != V_96 ) {
F_34 ( V_10 , L_22 ,
V_125 ) ;
return 1 ;
}
if ( V_21 -> V_24 [ ++ V_83 ] != ( V_43 == V_92 ? V_98 :
V_99 ) ) {
F_34 ( V_10 , L_23 ,
V_21 -> V_24 [ V_83 ] ) ;
return 1 ;
}
if ( V_21 -> V_24 [ ++ V_83 ] != V_100 ) {
F_34 ( V_10 , L_24 ,
V_21 -> V_24 [ V_83 ] ) ;
return 1 ;
}
V_83 ++ ;
F_3 ( V_4 ) -> V_102 = V_21 -> V_24 [ V_83 ++ ] ;
V_102 = V_21 -> V_24 [ V_83 ++ ] ;
V_101 = F_3 ( V_4 ) -> V_101 ;
if ( V_47 )
F_3 ( V_4 ) -> V_115 = V_114 ;
error = 0 ;
if ( ! F_3 ( V_4 ) -> V_105 )
error = 1 ;
if ( V_102 == 0 || V_102 != V_101 ) {
F_3 ( V_4 ) -> V_108 = 0 ;
error = 1 ;
}
if ( V_47 ) {
if ( F_3 ( V_4 ) -> V_127 && ! error ) {
F_3 ( V_4 ) -> V_127 = 0 ;
V_6 = F_3 ( V_4 ) -> V_7 ;
while ( V_6 ) {
if ( V_6 -> F_3 . V_74 ) {
V_6 -> F_3 . V_74 = 0 ;
F_3 ( V_4 ) -> V_46 = 1 ;
}
V_6 = V_6 -> V_8 ;
}
}
if ( F_3 ( V_4 ) -> V_46 ) {
V_125 = V_96 ;
F_3 ( V_4 ) -> V_127 = 1 ;
F_3 ( V_4 ) -> V_46 = 0 ;
}
F_3 ( V_4 ) -> V_113 = 1 ;
F_36 ( V_10 , V_125 == V_96 ? 1 : 0 ) ;
return 0 ;
}
F_3 ( V_4 ) -> V_113 = 0 ;
if ( error )
return 0 ;
if ( V_125 != V_96 )
return 0 ;
V_6 = F_3 ( V_4 ) -> V_7 ;
while ( V_6 ) {
V_6 -> F_3 . V_128 = 1 ;
V_6 = V_6 -> V_8 ;
}
V_126 = 0 ;
while ( V_21 -> V_66 >= V_83 + 2 + V_81 ) {
T_1 V_2 ;
T_6 V_129 ;
unsigned int V_45 , V_74 ;
if ( V_21 -> V_24 [ V_83 ] != ( V_43 == V_92 ? V_103 :
V_104 ) ) {
F_34 ( V_10 , L_25 ,
V_21 -> V_24 [ V_83 ] ) ;
return 1 ;
}
if ( V_21 -> V_24 [ ++ V_83 ] != V_81 ) {
F_34 ( V_10 , L_26 ,
V_21 -> V_24 [ V_83 ] ) ;
return 1 ;
}
V_83 ++ ;
V_74 = ! ! ( V_21 -> V_24 [ V_83 + 2 ] & 0x08 ) ;
V_45 = ! ! ( V_21 -> V_24 [ V_83 + 2 ] & 0x02 ) ;
if ( V_43 == V_82 ) {
V_2 = ( V_21 -> V_24 [ V_83 ] << 8 ) | V_21 -> V_24 [ V_83 + 1 ] ;
V_129 = ( V_21 -> V_24 [ V_83 + 3 ] << 16 ) |
( V_21 -> V_24 [ V_83 + 4 ] << 8 ) |
( V_21 -> V_24 [ V_83 + 5 ] ) ;
} else {
V_2 = ( ( V_21 -> V_24 [ V_83 ] & 0x3F ) << 4 ) |
( ( V_21 -> V_24 [ V_83 + 1 ] & 0x78 ) >> 3 ) ;
V_129 = 0 ;
}
V_6 = F_5 ( V_10 , V_2 ) ;
if ( ! V_6 && ! V_126 ) {
F_37 ( V_10 , L_27 ) ;
V_126 = 1 ;
}
if ( V_6 ) {
V_6 -> F_3 . V_75 = 1 ;
V_6 -> F_3 . V_128 = 0 ;
if ( V_45 != V_6 -> F_3 . V_45 ||
V_74 != V_6 -> F_3 . V_74 ||
V_129 != V_6 -> F_3 . V_109 ||
! V_6 -> F_3 . V_75 ) {
V_6 -> F_3 . V_74 = V_74 ;
V_6 -> F_3 . V_45 = V_45 ;
V_6 -> F_3 . V_109 = V_129 ;
F_11 ( V_45 , V_6 ) ;
F_33 ( V_6 ) ;
}
}
V_83 += V_81 ;
}
V_6 = F_3 ( V_4 ) -> V_7 ;
while ( V_6 ) {
if ( V_6 -> F_3 . V_128 && V_6 -> F_3 . V_75 ) {
F_11 ( 0 , V_6 ) ;
V_6 -> F_3 . V_45 = V_6 -> F_3 . V_74 = 0 ;
V_6 -> F_3 . V_75 = 0 ;
V_6 -> F_3 . V_109 = 0 ;
F_33 ( V_6 ) ;
}
V_6 = V_6 -> V_8 ;
}
F_3 ( V_4 ) -> V_108 = F_3 ( V_4 ) -> V_42 . V_130 ;
return 0 ;
}
static int F_49 ( struct V_18 * V_21 )
{
struct V_9 * V_14 = V_21 -> V_10 ;
T_3 * V_4 = F_6 ( V_14 ) ;
struct V_131 * V_132 = (struct V_131 * ) V_21 -> V_24 ;
T_2 * V_24 = V_21 -> V_24 ;
T_1 V_2 ;
struct V_5 * V_6 ;
struct V_9 * V_10 = NULL ;
if ( V_21 -> V_66 <= 4 || V_132 -> V_133 || V_24 [ 2 ] != V_36 )
goto V_134;
V_2 = F_1 ( V_21 -> V_24 ) ;
if ( ( V_2 == V_87 &&
( F_3 ( V_4 ) -> V_42 . V_43 == V_78 ||
F_3 ( V_4 ) -> V_42 . V_43 == V_92 ) ) ||
( V_2 == V_86 &&
F_3 ( V_4 ) -> V_42 . V_43 == V_82 ) ) {
if ( F_48 ( V_14 , V_21 ) )
goto V_134;
F_50 ( V_21 ) ;
return V_135 ;
}
V_6 = F_4 ( V_4 , V_2 ) ;
if ( ! V_6 ) {
#ifdef F_51
F_34 ( V_14 , L_28 ,
V_2 ) ;
#endif
F_50 ( V_21 ) ;
return V_136 ;
}
if ( V_6 -> F_3 . V_72 != V_132 -> V_72 ) {
#ifdef F_52
F_9 ( V_13 L_29 , V_14 -> V_58 ,
V_2 , V_132 -> V_72 ? L_30 : L_31 ) ;
#endif
V_6 -> F_3 . V_72 ^= 1 ;
}
if ( V_6 -> F_3 . V_137 != V_132 -> V_137 ) {
#ifdef F_52
F_9 ( V_13 L_32 , V_14 -> V_58 ,
V_2 , V_132 -> V_137 ? L_30 : L_31 ) ;
#endif
V_6 -> F_3 . V_137 ^= 1 ;
}
if ( ( V_21 = F_53 ( V_21 , V_12 ) ) == NULL ) {
V_14 -> V_67 . V_138 ++ ;
return V_136 ;
}
if ( V_24 [ 3 ] == V_27 ) {
F_54 ( V_21 , 4 ) ;
V_10 = V_6 -> main;
V_21 -> V_22 = F_55 ( V_26 ) ;
} else if ( V_24 [ 3 ] == V_29 ) {
F_54 ( V_21 , 4 ) ;
V_10 = V_6 -> main;
V_21 -> V_22 = F_55 ( V_28 ) ;
} else if ( V_21 -> V_66 > 10 && V_24 [ 3 ] == V_33 &&
V_24 [ 4 ] == V_34 && V_24 [ 5 ] == V_33 ) {
T_1 V_139 = F_56 ( * ( V_35 * ) ( V_24 + 6 ) ) ;
T_1 V_140 = F_56 ( * ( V_35 * ) ( V_24 + 8 ) ) ;
F_54 ( V_21 , 10 ) ;
switch ( ( ( ( T_6 ) V_139 ) << 16 ) | V_140 ) {
case V_141 :
case V_142 :
case V_26 :
case V_28 :
V_10 = V_6 -> main;
V_21 -> V_22 = F_55 ( V_140 ) ;
break;
case 0x80C20007 :
if ( ( V_10 = V_6 -> V_15 ) != NULL )
V_21 -> V_22 = F_57 ( V_21 , V_10 ) ;
break;
default:
F_34 ( V_14 , L_33 ,
V_139 , V_140 ) ;
F_50 ( V_21 ) ;
return V_136 ;
}
} else {
F_34 ( V_14 , L_34 ,
V_24 [ 3 ] , V_21 -> V_66 ) ;
F_50 ( V_21 ) ;
return V_136 ;
}
if ( V_10 ) {
V_10 -> V_67 . V_143 ++ ;
V_10 -> V_67 . V_144 += V_21 -> V_66 ;
if ( V_6 -> F_3 . V_137 )
V_10 -> V_67 . V_145 ++ ;
V_21 -> V_10 = V_10 ;
F_58 ( V_21 ) ;
return V_135 ;
} else {
F_50 ( V_21 ) ;
return V_136 ;
}
V_134:
V_14 -> V_67 . V_146 ++ ;
F_50 ( V_21 ) ;
return V_136 ;
}
static void F_59 ( struct V_9 * V_10 )
{
T_3 * V_4 = F_6 ( V_10 ) ;
#ifdef F_60
F_9 ( V_13 L_35 ) ;
#endif
if ( F_3 ( V_4 ) -> V_42 . V_43 != V_44 ) {
F_3 ( V_4 ) -> V_105 = 0 ;
F_3 ( V_4 ) -> V_46 = 1 ;
F_3 ( V_4 ) -> V_113 = 0 ;
F_3 ( V_4 ) -> V_127 = 0 ;
F_3 ( V_4 ) -> V_118 = 0xFFFFFFFF ;
F_3 ( V_4 ) -> V_108 = 0 ;
F_3 ( V_4 ) -> V_101 = F_3 ( V_4 ) -> V_102 = 0 ;
F_61 ( & F_3 ( V_4 ) -> V_121 ) ;
F_3 ( V_4 ) -> V_121 . V_122 = V_114 + V_117 ;
F_3 ( V_4 ) -> V_121 . V_124 = F_45 ;
F_3 ( V_4 ) -> V_121 . V_24 = ( unsigned long ) V_10 ;
F_47 ( & F_3 ( V_4 ) -> V_121 ) ;
} else
F_42 ( 1 , V_10 ) ;
}
static void F_62 ( struct V_9 * V_10 )
{
T_3 * V_4 = F_6 ( V_10 ) ;
#ifdef F_60
F_9 ( V_13 L_36 ) ;
#endif
if ( F_3 ( V_4 ) -> V_42 . V_43 != V_44 )
F_63 ( & F_3 ( V_4 ) -> V_121 ) ;
F_42 ( 0 , V_10 ) ;
}
static void F_64 ( struct V_9 * V_10 )
{
T_3 * V_4 = F_6 ( V_10 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) -> V_7 ;
while ( V_6 ) {
if ( V_6 -> main)
F_65 ( V_6 -> main ) ;
if ( V_6 -> V_15 )
F_65 ( V_6 -> V_15 ) ;
V_6 = V_6 -> V_8 ;
}
}
static void F_66 ( struct V_9 * V_10 )
{
V_10 -> type = V_147 ;
V_10 -> V_38 = V_148 ;
V_10 -> V_149 = 10 ;
V_10 -> V_150 = 2 ;
V_10 -> V_151 &= ~ V_152 ;
}
static int F_67 ( struct V_9 * V_14 , unsigned int V_2 , int type )
{
T_3 * V_4 = F_6 ( V_14 ) ;
struct V_5 * V_6 ;
struct V_9 * V_10 ;
int V_153 ;
if ( ( V_6 = F_5 ( V_14 , V_2 ) ) == NULL ) {
F_37 ( V_14 , L_37 ) ;
return - V_32 ;
}
if ( * F_17 ( V_6 , type ) )
return - V_154 ;
V_153 = F_10 ( V_6 ) ;
if ( type == V_17 ) {
V_10 = F_68 ( 0 , L_38 , V_155 ,
V_156 ) ;
V_10 -> V_151 &= ~ V_157 ;
} else
V_10 = F_68 ( 0 , L_39 , V_155 , F_66 ) ;
if ( ! V_10 ) {
F_37 ( V_14 , L_40 ) ;
F_15 ( V_4 ) ;
return - V_32 ;
}
if ( type == V_17 )
F_69 ( V_10 ) ;
else {
* ( V_35 * ) V_10 -> V_158 = F_55 ( V_2 ) ;
F_2 ( V_10 -> V_159 , V_2 ) ;
}
V_10 -> V_160 = & V_161 ;
V_10 -> V_162 = V_163 ;
V_10 -> V_164 = 0 ;
V_10 -> V_37 = V_6 ;
if ( F_70 ( V_10 ) != 0 ) {
F_71 ( V_10 ) ;
F_15 ( V_4 ) ;
return - V_40 ;
}
V_10 -> V_165 = F_71 ;
* F_17 ( V_6 , type ) = V_10 ;
if ( ! V_153 ) {
F_3 ( V_4 ) -> V_46 = 1 ;
F_3 ( V_4 ) -> V_84 ++ ;
}
return 0 ;
}
static int F_72 ( T_3 * V_4 , unsigned int V_2 , int type )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
if ( ( V_6 = F_4 ( V_4 , V_2 ) ) == NULL )
return - V_166 ;
if ( ( V_10 = * F_17 ( V_6 , type ) ) == NULL )
return - V_166 ;
if ( V_10 -> V_38 & V_39 )
return - V_167 ;
F_73 ( V_10 ) ;
* F_17 ( V_6 , type ) = NULL ;
if ( ! F_10 ( V_6 ) ) {
F_3 ( V_4 ) -> V_84 -- ;
F_3 ( V_4 ) -> V_46 = 1 ;
}
F_15 ( V_4 ) ;
return 0 ;
}
static void F_74 ( struct V_9 * V_14 )
{
T_3 * V_4 = F_6 ( V_14 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) -> V_7 ;
F_3 ( V_4 ) -> V_7 = NULL ;
F_3 ( V_4 ) -> V_84 = 0 ;
F_3 ( V_4 ) -> V_46 = 1 ;
while ( V_6 ) {
struct V_5 * V_8 = V_6 -> V_8 ;
if ( V_6 -> main)
F_73 ( V_6 -> main ) ;
if ( V_6 -> V_15 )
F_73 ( V_6 -> V_15 ) ;
F_16 ( V_6 ) ;
V_6 = V_8 ;
}
}
static int F_75 ( struct V_9 * V_10 , struct V_48 * V_49 )
{
T_7 T_8 * V_168 = V_49 -> V_52 . V_60 . V_169 ;
const T_9 V_56 = sizeof( T_7 ) ;
T_7 V_170 ;
T_3 * V_4 = F_6 ( V_10 ) ;
T_10 V_6 ;
int V_171 ;
switch ( V_49 -> V_52 . type ) {
case V_53 :
if ( F_6 ( V_10 ) -> V_172 != & V_172 )
return - V_63 ;
V_49 -> V_52 . type = V_173 ;
if ( V_49 -> V_52 . V_56 < V_56 ) {
V_49 -> V_52 . V_56 = V_56 ;
return - V_32 ;
}
if ( F_27 ( V_168 , & F_3 ( V_4 ) -> V_42 , V_56 ) )
return - V_62 ;
return 0 ;
case V_173 :
if ( ! F_76 ( V_174 ) )
return - V_175 ;
if ( V_10 -> V_38 & V_39 )
return - V_167 ;
if ( F_77 ( & V_170 , V_168 , V_56 ) )
return - V_62 ;
if ( V_170 . V_43 == V_176 )
V_170 . V_43 = V_78 ;
if ( ( V_170 . V_43 != V_44 &&
V_170 . V_43 != V_78 &&
V_170 . V_43 != V_92 &&
V_170 . V_43 != V_82 ) ||
V_170 . V_123 < 1 ||
V_170 . V_116 < 2 ||
V_170 . V_130 < 1 ||
V_170 . V_120 < 1 ||
V_170 . V_119 < V_170 . V_120 ||
V_170 . V_119 > 32 ||
( V_170 . V_47 != 0 &&
V_170 . V_47 != 1 ) )
return - V_63 ;
V_171 = V_4 -> V_177 ( V_10 , V_178 , V_179 ) ;
if ( V_171 )
return V_171 ;
if ( F_6 ( V_10 ) -> V_172 != & V_172 ) {
V_171 = F_78 ( V_10 , & V_172 ,
sizeof( struct V_3 ) ) ;
if ( V_171 )
return V_171 ;
F_3 ( V_4 ) -> V_7 = NULL ;
F_3 ( V_4 ) -> V_84 = 0 ;
}
memcpy ( & F_3 ( V_4 ) -> V_42 , & V_170 , V_56 ) ;
V_10 -> type = V_180 ;
return 0 ;
case V_181 :
case V_182 :
case V_183 :
case V_184 :
if ( F_6 ( V_10 ) -> V_172 != & V_172 )
return - V_63 ;
if ( ! F_76 ( V_174 ) )
return - V_175 ;
if ( F_77 ( & V_6 , V_49 -> V_52 . V_60 . V_185 ,
sizeof( T_10 ) ) )
return - V_62 ;
if ( V_6 . V_2 <= 0 || V_6 . V_2 >= 1024 )
return - V_63 ;
if ( V_49 -> V_52 . type == V_183 ||
V_49 -> V_52 . type == V_184 )
V_171 = V_17 ;
else
V_171 = V_147 ;
if ( V_49 -> V_52 . type == V_181 ||
V_49 -> V_52 . type == V_183 )
return F_67 ( V_10 , V_6 . V_2 , V_171 ) ;
else
return F_72 ( V_4 , V_6 . V_2 , V_171 ) ;
}
return - V_63 ;
}
static int T_11 F_79 ( void )
{
F_80 ( & V_172 ) ;
return 0 ;
}
static void T_12 F_81 ( void )
{
F_82 ( & V_172 ) ;
}
