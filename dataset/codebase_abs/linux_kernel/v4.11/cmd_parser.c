static inline T_1 F_1 ( T_1 V_1 , int V_2 )
{
struct V_3 * V_4 ;
if ( V_2 >= V_5 )
return V_6 ;
V_4 = V_7 [ V_2 ] [ F_2 ( V_1 ) ] ;
if ( V_4 == NULL )
return V_6 ;
return V_1 >> ( 32 - V_4 -> V_8 ) ;
}
static inline struct V_9 * F_3 ( struct V_10 * V_11 ,
unsigned int V_12 , int V_2 )
{
struct V_13 * V_14 ;
F_4 (gvt->cmd_table, e, hlist, opcode) {
if ( ( V_12 == V_14 -> V_15 -> V_12 ) &&
( V_14 -> V_15 -> V_16 & ( 1 << V_2 ) ) )
return V_14 -> V_15 ;
}
return NULL ;
}
static inline struct V_9 * F_5 ( struct V_10 * V_11 ,
T_1 V_1 , int V_2 )
{
T_1 V_12 ;
V_12 = F_1 ( V_1 , V_2 ) ;
if ( V_12 == V_6 )
return NULL ;
return F_3 ( V_11 , V_12 , V_2 ) ;
}
static inline T_1 F_6 ( T_1 V_1 , T_1 V_17 , T_1 V_18 )
{
return ( V_1 >> V_18 ) & ( ( 1U << ( V_17 - V_18 + 1 ) ) - 1 ) ;
}
static inline void F_7 ( T_1 V_1 , int V_2 )
{
struct V_3 * V_4 ;
int V_19 ;
if ( V_2 >= V_5 )
return;
V_4 = V_7 [ V_2 ] [ F_2 ( V_1 ) ] ;
if ( V_4 == NULL )
return;
F_8 ( L_1 ,
V_1 >> ( 32 - V_4 -> V_8 ) , V_4 -> V_20 ) ;
for ( V_19 = 0 ; V_19 < V_4 -> V_21 ; V_19 ++ )
F_9 ( L_2 , F_6 ( V_1 , V_4 -> V_22 [ V_19 ] . V_17 ,
V_4 -> V_22 [ V_19 ] . V_18 ) ) ;
F_9 ( L_3 ) ;
}
static inline T_1 * F_10 ( struct V_23 * V_24 , int V_25 )
{
return V_24 -> V_26 + ( V_25 << 2 ) ;
}
static inline T_1 F_11 ( struct V_23 * V_24 , int V_25 )
{
return * F_10 ( V_24 , V_25 ) ;
}
static void F_12 ( struct V_23 * V_24 )
{
int V_27 = 0 ;
int V_19 ;
F_8 ( L_4
L_5 , V_24 -> V_28 -> V_29 ,
V_24 -> V_2 , V_24 -> V_30 , V_24 -> V_30 + V_24 -> V_31 ,
V_24 -> V_32 , V_24 -> V_33 ) ;
F_8 ( L_6 ,
V_24 -> V_34 == V_35 ?
L_7 : L_8 ,
V_24 -> V_36 == V_37 ?
L_9 : L_10 , V_24 -> V_38 ) ;
if ( V_24 -> V_26 == NULL ) {
F_8 ( L_11 ) ;
return;
}
F_8 ( L_12 ,
V_24 -> V_26 , F_11 ( V_24 , 0 ) , F_11 ( V_24 , 1 ) ,
F_11 ( V_24 , 2 ) , F_11 ( V_24 , 3 ) ) ;
F_7 ( F_11 ( V_24 , 0 ) , V_24 -> V_2 ) ;
F_9 ( L_13 ,
V_24 -> V_26 , F_11 ( V_24 , 0 ) , F_11 ( V_24 , 1 ) ,
F_11 ( V_24 , 2 ) , F_11 ( V_24 , 3 ) ) ;
V_24 -> V_26 = ( T_1 * ) ( ( ( ( V_39 ) V_24 -> V_26 ) >> 12 ) << 12 ) ;
while ( V_27 < 1024 ) {
F_9 ( L_14 , V_24 -> V_26 ) ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ )
F_9 ( L_15 , F_11 ( V_24 , V_19 ) ) ;
F_9 ( L_3 ) ;
V_24 -> V_26 += 8 * sizeof( T_1 ) ;
V_27 += 8 ;
}
}
static inline void F_13 ( struct V_23 * V_24 )
{
unsigned long V_40 = 0 ;
if ( F_14 ( V_24 -> V_32 == V_24 -> V_33 ) )
return;
if ( V_24 -> V_34 == V_35 ) {
unsigned long V_41 = V_24 -> V_30 + V_24 -> V_31 ;
if ( V_24 -> V_32 > V_24 -> V_33 ) {
if ( V_24 -> V_38 >= V_24 -> V_32 && V_24 -> V_38 < V_41 )
V_40 = ( V_24 -> V_38 - V_24 -> V_32 ) ;
else if ( V_24 -> V_38 >= V_24 -> V_30 &&
V_24 -> V_38 <= V_24 -> V_33 )
V_40 = ( V_41 - V_24 -> V_32 ) +
( V_24 -> V_38 - V_24 -> V_30 ) ;
} else
V_40 = ( V_24 -> V_38 - V_24 -> V_32 ) ;
V_24 -> V_26 = V_24 -> V_42 + V_40 ;
} else {
V_24 -> V_26 = V_24 -> V_43 ;
}
}
static inline int F_15 ( struct V_23 * V_24 ,
unsigned long V_38 )
{
F_14 ( ! F_16 ( V_38 , 4 ) ) ;
V_24 -> V_38 = V_38 ;
F_13 ( V_24 ) ;
return 0 ;
}
static inline int F_17 ( struct V_23 * V_24 ,
unsigned int V_44 )
{
V_24 -> V_38 += ( V_44 << 2 ) ;
if ( V_24 -> V_34 == V_35 ) {
if ( V_24 -> V_38 >= V_24 -> V_30 + V_24 -> V_31 )
V_24 -> V_38 -= V_24 -> V_31 ;
F_13 ( V_24 ) ;
} else {
V_24 -> V_26 += ( V_44 << 2 ) ;
}
return 0 ;
}
static inline int F_18 ( struct V_9 * V_15 , T_1 V_1 )
{
if ( ( V_15 -> V_45 & V_46 ) == V_47 )
return V_15 -> V_40 ;
else
return ( V_1 & ( ( 1U << V_15 -> V_40 ) - 1 ) ) + 2 ;
return 0 ;
}
static inline int F_19 ( struct V_23 * V_24 )
{
return F_18 ( V_24 -> V_15 , F_11 ( V_24 , 0 ) ) ;
}
static bool F_20 ( unsigned int V_48 )
{
bool V_49 = false ;
if ( ( V_48 == 0x2168 ) ||
( V_48 == 0x2140 ) ||
( V_48 == 0x211c ) ||
( V_48 == 0x2114 ) ) {
V_49 = true ;
}
return V_49 ;
}
static inline bool F_21 ( unsigned int V_48 )
{
return ( V_48 >= 0x24d0 && V_48 < 0x2500 ) ;
}
static int F_22 ( struct V_23 * V_24 ,
unsigned int V_48 , unsigned int V_25 )
{
struct V_10 * V_11 = V_24 -> V_28 -> V_11 ;
unsigned int V_50 = F_11 ( V_24 , V_25 + 1 ) ;
if ( ! F_23 ( V_11 , V_50 ) ) {
F_24 ( L_16 ,
V_48 , V_50 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_25 ( struct V_23 * V_24 ,
unsigned int V_48 , unsigned int V_25 , char * V_1 )
{
struct V_52 * V_28 = V_24 -> V_28 ;
struct V_10 * V_11 = V_28 -> V_11 ;
if ( V_48 + 4 > V_11 -> V_53 . V_54 ) {
F_26 ( L_17 ,
V_1 , V_48 ) ;
return - V_51 ;
}
if ( ! F_27 ( V_11 , V_48 ) ) {
F_26 ( L_18 ,
V_1 , V_48 ) ;
return 0 ;
}
if ( F_20 ( V_48 ) ) {
F_26 ( L_19 , V_48 ) ;
return 0 ;
}
if ( F_21 ( V_48 ) &&
F_22 ( V_24 , V_48 , V_25 ) )
return - V_51 ;
if ( V_48 == F_28 ( V_55 ) ||
V_48 == F_28 ( V_56 ) ) {
F_29 ( V_24 , F_10 ( V_24 , V_25 ) , V_57 ) ;
}
F_30 ( V_11 , V_48 ) ;
return 0 ;
}
static int F_31 ( struct V_23 * V_24 )
{
int V_19 , V_49 = 0 ;
int V_58 = F_19 ( V_24 ) ;
struct V_10 * V_11 = V_24 -> V_28 -> V_11 ;
for ( V_19 = 1 ; V_19 < V_58 ; V_19 += 2 ) {
if ( F_32 ( V_11 -> V_59 ) &&
( V_24 -> V_2 != V_60 ) ) {
if ( V_24 -> V_2 == V_61 &&
F_33 ( V_24 , V_19 ) ==
F_28 ( V_55 ) )
V_49 |= 0 ;
else
V_49 |= ( F_34 ( V_24 , V_19 ) ) ? - V_51 : 0 ;
}
if ( V_49 )
break;
V_49 |= F_25 ( V_24 , F_33 ( V_24 , V_19 ) , V_19 , L_20 ) ;
}
return V_49 ;
}
static int F_35 ( struct V_23 * V_24 )
{
int V_19 , V_49 = 0 ;
int V_58 = F_19 ( V_24 ) ;
for ( V_19 = 1 ; V_19 < V_58 ; V_19 += 2 ) {
if ( F_32 ( V_24 -> V_28 -> V_11 -> V_59 ) )
V_49 |= ( ( F_34 ( V_24 , V_19 ) ||
( F_34 ( V_24 , V_19 + 1 ) ) ) ) ?
- V_51 : 0 ;
if ( V_49 )
break;
V_49 |= F_25 ( V_24 , F_33 ( V_24 , V_19 ) , V_19 , L_21 ) ;
V_49 |= F_25 ( V_24 , F_33 ( V_24 , V_19 + 1 ) , V_19 , L_22 ) ;
}
return V_49 ;
}
static int F_36 ( struct V_23 * V_24 )
{
struct V_10 * V_11 = V_24 -> V_28 -> V_11 ;
int V_62 = V_11 -> V_53 . V_63 ;
unsigned long V_64 ;
int V_19 , V_49 = 0 ;
int V_58 = F_19 ( V_24 ) ;
for ( V_19 = 1 ; V_19 < V_58 ; ) {
if ( F_32 ( V_11 -> V_59 ) )
V_49 |= ( F_34 ( V_24 , V_19 ) ) ? - V_51 : 0 ;
if ( V_49 )
break;
V_49 |= F_25 ( V_24 , F_33 ( V_24 , V_19 ) , V_19 , L_23 ) ;
if ( F_11 ( V_24 , 0 ) & ( 1 << 22 ) ) {
V_64 = F_37 ( V_24 , V_19 + 1 ) ;
if ( V_62 == 8 )
V_64 |= ( F_38 ( V_24 , V_19 + 2 ) ) << 32 ;
V_49 |= F_39 ( V_24 , V_64 , sizeof( T_1 ) , false ) ;
}
V_19 += F_40 ( V_24 ) + 1 ;
}
return V_49 ;
}
static int F_41 ( struct V_23 * V_24 )
{
int V_62 = V_24 -> V_28 -> V_11 -> V_53 . V_63 ;
unsigned long V_64 ;
int V_19 , V_49 = 0 ;
int V_58 = F_19 ( V_24 ) ;
for ( V_19 = 1 ; V_19 < V_58 ; ) {
V_49 |= F_25 ( V_24 , F_33 ( V_24 , V_19 ) , V_19 , L_24 ) ;
if ( F_11 ( V_24 , 0 ) & ( 1 << 22 ) ) {
V_64 = F_37 ( V_24 , V_19 + 1 ) ;
if ( V_62 == 8 )
V_64 |= ( F_38 ( V_24 , V_19 + 2 ) ) << 32 ;
V_49 |= F_39 ( V_24 , V_64 , sizeof( T_1 ) , false ) ;
}
V_19 += F_40 ( V_24 ) + 1 ;
}
return V_49 ;
}
static int F_42 ( struct V_23 * V_24 )
{
int V_62 = V_24 -> V_28 -> V_11 -> V_53 . V_63 ;
unsigned long V_64 ;
bool V_65 = false ;
unsigned int V_66 ;
int V_49 = 0 ;
V_66 = ( F_11 ( V_24 , 1 ) & V_67 ) >> 14 ;
if ( F_11 ( V_24 , 1 ) & V_68 )
V_49 = F_25 ( V_24 , F_33 ( V_24 , 2 ) , 1 , L_25 ) ;
else if ( V_66 ) {
if ( V_66 == 2 )
V_49 = F_25 ( V_24 , 0x2350 , 1 , L_25 ) ;
else if ( V_66 == 3 )
V_49 = F_25 ( V_24 , 0x2358 , 1 , L_25 ) ;
else if ( V_66 == 1 ) {
if ( ( F_11 ( V_24 , 1 ) & V_69 ) ) {
V_64 = F_11 ( V_24 , 2 ) & F_43 ( 31 , 3 ) ;
if ( V_62 == 8 )
V_64 |= ( F_38 ( V_24 , 3 ) ) << 32 ;
if ( F_11 ( V_24 , 1 ) & ( 1 << 21 ) )
V_65 = true ;
V_49 |= F_39 ( V_24 , V_64 , sizeof( V_39 ) ,
V_65 ) ;
}
}
}
if ( V_49 )
return V_49 ;
if ( F_11 ( V_24 , 1 ) & V_70 )
F_44 ( V_71 [ V_24 -> V_2 ] . V_72 ,
V_24 -> V_73 -> V_74 ) ;
return 0 ;
}
static int F_45 ( struct V_23 * V_24 )
{
F_44 ( V_71 [ V_24 -> V_2 ] . V_75 ,
V_24 -> V_73 -> V_74 ) ;
return 0 ;
}
static int F_46 ( struct V_23 * V_24 )
{
return F_17 ( V_24 , F_19 ( V_24 ) ) ;
}
static int F_47 ( struct V_23 * V_24 )
{
int V_49 ;
if ( V_24 -> V_34 == V_76 ) {
V_24 -> V_34 = V_77 ;
V_49 = F_15 ( V_24 , V_24 -> V_78 ) ;
V_24 -> V_36 = V_24 -> V_79 ;
} else {
V_24 -> V_34 = V_35 ;
V_24 -> V_36 = V_37 ;
if ( V_24 -> V_80 >= V_24 -> V_30 + V_24 -> V_31 )
V_24 -> V_80 -= V_24 -> V_31 ;
V_49 = F_15 ( V_24 , V_24 -> V_80 ) ;
}
return V_49 ;
}
static int F_48 ( struct V_23 * V_24 ,
struct V_81 * V_15 )
{
struct V_82 * V_59 = V_24 -> V_28 -> V_11 -> V_59 ;
struct V_83 V_84 [] = {
[ 0 ] = { V_85 , V_86 , V_87 } ,
[ 1 ] = { V_88 , V_86 , V_89 } ,
[ 2 ] = { V_85 , V_90 , V_91 } ,
[ 3 ] = { V_88 , V_90 , V_92 } ,
[ 4 ] = { V_93 , V_86 , V_94 } ,
[ 5 ] = { V_93 , V_90 , V_95 } ,
} ;
T_1 V_96 , V_97 , V_98 ;
T_1 V_99 ;
V_96 = F_11 ( V_24 , 0 ) ;
V_97 = F_11 ( V_24 , 1 ) ;
V_98 = F_11 ( V_24 , 2 ) ;
V_99 = ( V_96 & F_43 ( 21 , 19 ) ) >> 19 ;
if ( F_14 ( V_99 >= F_49 ( V_84 ) ) )
return - V_51 ;
V_15 -> V_100 = V_84 [ V_99 ] . V_100 ;
V_15 -> V_101 = V_84 [ V_99 ] . V_101 ;
V_15 -> V_102 = V_84 [ V_99 ] . V_102 ;
V_15 -> V_103 = ( V_97 & F_43 ( 15 , 6 ) ) >> 6 ;
V_15 -> V_104 = ( V_97 & 0x1 ) ;
V_15 -> V_105 = ( V_98 & F_43 ( 31 , 12 ) ) >> 12 ;
V_15 -> V_106 = ( ( V_98 & F_43 ( 1 , 0 ) ) == 0x1 ) ;
if ( V_15 -> V_101 == V_86 ) {
V_15 -> V_107 = F_50 ( V_15 -> V_100 ) ;
V_15 -> V_108 = F_51 ( V_15 -> V_100 ) ;
V_15 -> V_109 = F_52 ( V_15 -> V_100 ) ;
} else if ( V_15 -> V_101 == V_90 ) {
V_15 -> V_107 = F_53 ( V_15 -> V_100 ) ;
V_15 -> V_108 = F_54 ( V_15 -> V_100 ) ;
V_15 -> V_109 = F_55 ( V_15 -> V_100 ) ;
} else {
F_14 ( 1 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_56 ( struct V_23 * V_24 ,
struct V_81 * V_15 )
{
struct V_82 * V_59 = V_24 -> V_28 -> V_11 -> V_59 ;
struct V_52 * V_28 = V_24 -> V_28 ;
T_1 V_96 = F_11 ( V_24 , 0 ) ;
T_1 V_97 = F_11 ( V_24 , 1 ) ;
T_1 V_98 = F_11 ( V_24 , 2 ) ;
T_1 V_101 = ( V_96 & F_43 ( 12 , 8 ) ) >> 8 ;
V_15 -> V_101 = V_110 ;
switch ( V_101 ) {
case V_111 :
V_15 -> V_100 = V_85 ;
V_15 -> V_102 = V_87 ;
break;
case V_112 :
V_15 -> V_100 = V_88 ;
V_15 -> V_102 = V_89 ;
break;
case V_113 :
V_15 -> V_100 = V_93 ;
V_15 -> V_102 = V_94 ;
break;
case V_114 :
V_15 -> V_100 = V_85 ;
V_15 -> V_102 = V_91 ;
V_15 -> V_101 = V_115 ;
break;
case V_116 :
V_15 -> V_100 = V_88 ;
V_15 -> V_102 = V_92 ;
V_15 -> V_101 = V_115 ;
break;
case V_117 :
V_15 -> V_100 = V_93 ;
V_15 -> V_102 = V_95 ;
V_15 -> V_101 = V_115 ;
break;
default:
F_26 ( L_26 , V_101 ) ;
return - V_51 ;
}
V_15 -> V_103 = ( V_97 & F_43 ( 15 , 6 ) ) >> 6 ;
V_15 -> V_104 = ( V_97 & F_43 ( 2 , 0 ) ) ;
V_15 -> V_105 = ( V_98 & F_43 ( 31 , 12 ) ) >> 12 ;
V_15 -> V_106 = ( ( V_98 & F_43 ( 1 , 0 ) ) == 0x1 ) ;
V_15 -> V_107 = F_50 ( V_15 -> V_100 ) ;
V_15 -> V_108 = F_51 ( V_15 -> V_100 ) ;
V_15 -> V_109 = F_52 ( V_15 -> V_100 ) ;
return 0 ;
}
static int F_57 ( struct V_23 * V_24 ,
struct V_81 * V_15 )
{
struct V_82 * V_59 = V_24 -> V_28 -> V_11 -> V_59 ;
T_1 V_118 , V_119 ;
if ( ! V_15 -> V_106 )
return 0 ;
if ( F_58 ( V_59 ) ) {
V_118 = F_59 ( V_24 -> V_28 , V_15 -> V_108 ) & F_43 ( 9 , 0 ) ;
V_119 = ( F_59 ( V_24 -> V_28 , V_15 -> V_107 ) &
F_43 ( 12 , 10 ) ) >> 10 ;
} else {
V_118 = ( F_59 ( V_24 -> V_28 , V_15 -> V_108 ) &
F_43 ( 15 , 6 ) ) >> 6 ;
V_119 = ( F_59 ( V_24 -> V_28 , V_15 -> V_107 ) & ( 1 << 10 ) ) >> 10 ;
}
if ( V_118 != V_15 -> V_103 )
F_8 ( L_27 ) ;
if ( V_119 != V_15 -> V_104 )
F_8 ( L_28 ) ;
return 0 ;
}
static int F_60 (
struct V_23 * V_24 ,
struct V_81 * V_15 )
{
struct V_82 * V_59 = V_24 -> V_28 -> V_11 -> V_59 ;
struct V_52 * V_28 = V_24 -> V_28 ;
F_61 ( & F_59 ( V_28 , V_15 -> V_109 ) , F_43 ( 31 , 12 ) ,
V_15 -> V_105 << 12 ) ;
if ( F_58 ( V_59 ) ) {
F_61 ( & F_59 ( V_28 , V_15 -> V_108 ) , F_43 ( 9 , 0 ) ,
V_15 -> V_103 ) ;
F_61 ( & F_59 ( V_28 , V_15 -> V_107 ) , F_43 ( 12 , 10 ) ,
V_15 -> V_104 << 10 ) ;
} else {
F_61 ( & F_59 ( V_28 , V_15 -> V_108 ) , F_43 ( 15 , 6 ) ,
V_15 -> V_103 << 6 ) ;
F_61 ( & F_59 ( V_28 , V_15 -> V_107 ) , F_43 ( 10 , 10 ) ,
V_15 -> V_104 << 10 ) ;
}
F_59 ( V_28 , F_62 ( V_15 -> V_100 ) ) ++ ;
F_63 ( V_28 , V_15 -> V_102 ) ;
return 0 ;
}
static int F_64 ( struct V_23 * V_24 ,
struct V_81 * V_15 )
{
struct V_82 * V_59 = V_24 -> V_28 -> V_11 -> V_59 ;
if ( F_32 ( V_59 ) )
return F_48 ( V_24 , V_15 ) ;
if ( F_58 ( V_59 ) )
return F_56 ( V_24 , V_15 ) ;
return - V_120 ;
}
static int F_65 ( struct V_23 * V_24 ,
struct V_81 * V_15 )
{
struct V_82 * V_59 = V_24 -> V_28 -> V_11 -> V_59 ;
if ( F_32 ( V_59 ) || F_58 ( V_59 ) )
return F_57 ( V_24 , V_15 ) ;
return - V_120 ;
}
static int F_66 (
struct V_23 * V_24 ,
struct V_81 * V_15 )
{
struct V_82 * V_59 = V_24 -> V_28 -> V_11 -> V_59 ;
if ( F_32 ( V_59 ) || F_58 ( V_59 ) )
return F_60 ( V_24 , V_15 ) ;
return - V_120 ;
}
static int F_67 ( struct V_23 * V_24 )
{
struct V_81 V_15 ;
struct V_52 * V_28 = V_24 -> V_28 ;
int V_49 ;
int V_19 ;
int V_40 = F_19 ( V_24 ) ;
V_49 = F_64 ( V_24 , & V_15 ) ;
if ( V_49 ) {
F_26 ( L_29 ) ;
return V_49 ;
}
V_49 = F_65 ( V_24 , & V_15 ) ;
if ( V_49 ) {
F_26 ( L_30 ) ;
return V_49 ;
}
V_49 = F_66 ( V_24 , & V_15 ) ;
if ( V_49 ) {
F_26 ( L_31 ) ;
return V_49 ;
}
for ( V_19 = 0 ; V_19 < V_40 ; V_19 ++ )
F_29 ( V_24 , F_10 ( V_24 , V_19 ) , V_121 ) ;
return 0 ;
}
static bool F_68 ( T_1 V_1 )
{
return V_1 & ( V_122 |
V_123 |
V_124 |
V_125 |
V_126 |
V_127 ) ;
}
static int F_69 ( struct V_23 * V_24 )
{
T_1 V_1 = F_11 ( V_24 , 0 ) ;
if ( ! F_68 ( V_1 ) )
return 0 ;
F_29 ( V_24 , F_10 ( V_24 , 0 ) , V_121 ) ;
return 0 ;
}
static unsigned long F_70 ( struct V_23 * V_24 , int V_25 )
{
unsigned long V_128 ;
unsigned long V_129 , V_130 ;
int V_62 = V_24 -> V_28 -> V_11 -> V_53 . V_63 ;
if ( F_14 ( V_62 != 4 && V_62 != 8 ) )
return V_131 ;
V_130 = F_11 ( V_24 , V_25 ) & V_132 ;
if ( V_62 == 4 ) {
V_128 = V_130 ;
} else {
V_129 = F_11 ( V_24 , V_25 + 1 ) & V_133 ;
V_128 = ( ( ( unsigned long ) V_129 ) << 32 ) | V_130 ;
}
return V_128 ;
}
static inline int F_39 ( struct V_23 * V_24 ,
unsigned long V_134 , int V_135 , bool V_65 )
{
struct V_52 * V_28 = V_24 -> V_28 ;
T_1 V_136 = V_28 -> V_11 -> V_53 . V_136 ;
int V_19 ;
int V_49 ;
if ( V_135 > V_136 ) {
F_26 ( L_32 ,
V_24 -> V_15 -> V_20 ) ;
return - V_51 ;
}
if ( V_65 ) {
if ( V_134 >= V_137 / sizeof( V_39 ) ) {
V_49 = - V_51 ;
goto V_138;
}
} else if ( ( ! F_71 ( V_24 -> V_28 , V_134 ) ) ||
( ! F_71 ( V_24 -> V_28 ,
V_134 + V_135 - 1 ) ) ) {
V_49 = - V_51 ;
goto V_138;
}
return 0 ;
V_138:
F_26 ( L_33 ,
V_24 -> V_15 -> V_20 , V_134 , V_135 ) ;
F_9 ( L_34 ) ;
for ( V_19 = 0 ; V_19 < F_19 ( V_24 ) ; V_19 ++ ) {
if ( ! ( V_19 % 4 ) )
F_9 ( L_35 , F_11 ( V_24 , V_19 ) ) ;
else
F_9 ( L_15 , F_11 ( V_24 , V_19 ) ) ;
}
F_9 ( L_36 ,
V_28 -> V_29 ,
F_72 ( V_28 ) ,
F_73 ( V_28 ) ,
F_74 ( V_28 ) ,
F_75 ( V_28 ) ) ;
return V_49 ;
}
static int F_76 ( struct V_23 * V_24 )
{
int V_62 = V_24 -> V_28 -> V_11 -> V_53 . V_63 ;
int V_135 = ( F_19 ( V_24 ) - 3 ) * sizeof( T_1 ) ;
int V_139 = ( F_11 ( V_24 , 2 ) & ( 1 << 0 ) ) ? 1 : 0 ;
unsigned long V_64 , V_130 , V_129 ;
int V_49 = 0 ;
if ( ! ( F_11 ( V_24 , 0 ) & ( 1 << 22 ) ) )
return 0 ;
V_64 = F_11 ( V_24 , 2 ) & F_43 ( 31 , 2 ) ;
if ( V_62 == 8 ) {
V_130 = F_11 ( V_24 , 1 ) & F_43 ( 31 , 2 ) ;
V_129 = F_11 ( V_24 , 2 ) & F_43 ( 15 , 0 ) ;
V_64 = ( V_129 << 32 ) | V_130 ;
V_139 = ( F_11 ( V_24 , 1 ) & ( 1 << 0 ) ) ? 1 : 0 ;
}
V_49 = F_39 ( V_24 , V_64 + V_135 * V_139 , V_135 , false ) ;
return V_49 ;
}
static inline int F_77 ( struct V_23 * V_24 )
{
struct V_52 * V_28 = V_24 -> V_28 ;
F_26 ( L_37 , V_24 -> V_15 -> V_20 ) ;
return - V_51 ;
}
static int F_78 ( struct V_23 * V_24 )
{
return F_77 ( V_24 ) ;
}
static int F_79 ( struct V_23 * V_24 )
{
return F_77 ( V_24 ) ;
}
static int F_80 ( struct V_23 * V_24 )
{
return F_77 ( V_24 ) ;
}
static int F_81 ( struct V_23 * V_24 )
{
int V_62 = V_24 -> V_28 -> V_11 -> V_53 . V_63 ;
int V_135 = ( 1 << ( ( F_11 ( V_24 , 0 ) & F_43 ( 20 , 19 ) ) >> 19 ) ) *
sizeof( T_1 ) ;
unsigned long V_64 , V_129 ;
int V_49 = 0 ;
if ( ! ( F_11 ( V_24 , 0 ) & ( 1 << 22 ) ) )
return V_49 ;
V_64 = F_11 ( V_24 , 1 ) & F_43 ( 31 , 2 ) ;
if ( V_62 == 8 ) {
V_129 = F_11 ( V_24 , 2 ) & F_43 ( 15 , 0 ) ;
V_64 = ( V_129 << 32 ) | V_64 ;
}
V_49 = F_39 ( V_24 , V_64 , V_135 , false ) ;
return V_49 ;
}
static int F_82 ( struct V_23 * V_24 )
{
return F_77 ( V_24 ) ;
}
static int F_83 ( struct V_23 * V_24 )
{
return F_77 ( V_24 ) ;
}
static int F_84 (
struct V_23 * V_24 )
{
return F_77 ( V_24 ) ;
}
static int F_85 ( struct V_23 * V_24 )
{
return F_77 ( V_24 ) ;
}
static int F_86 ( struct V_23 * V_24 )
{
int V_62 = V_24 -> V_28 -> V_11 -> V_53 . V_63 ;
unsigned long V_64 ;
bool V_65 = false ;
int V_49 = 0 ;
if ( ( ( F_11 ( V_24 , 0 ) >> 14 ) & 0x3 ) && ( F_11 ( V_24 , 1 ) & ( 1 << 2 ) ) ) {
V_64 = F_11 ( V_24 , 1 ) & F_43 ( 31 , 3 ) ;
if ( V_62 == 8 )
V_64 |= ( F_11 ( V_24 , 2 ) & F_43 ( 15 , 0 ) ) << 32 ;
if ( F_11 ( V_24 , 0 ) & ( 1 << 21 ) )
V_65 = true ;
V_49 = F_39 ( V_24 , V_64 , sizeof( V_39 ) , V_65 ) ;
}
if ( ( F_11 ( V_24 , 0 ) & ( 1 << 8 ) ) )
F_44 ( V_71 [ V_24 -> V_2 ] . V_140 ,
V_24 -> V_73 -> V_74 ) ;
return V_49 ;
}
static void F_87 ( struct V_23 * V_24 )
{
if ( ( V_24 -> V_34 == V_35 ) &&
( F_88 ( F_11 ( V_24 , 0 ) ) == 1 ) ) {
V_24 -> V_36 = V_141 ;
}
}
static int F_89 ( struct V_52 * V_28 , struct V_142 * V_143 ,
unsigned long V_64 , unsigned long V_144 , void * V_145 )
{
unsigned long V_146 , V_48 ;
unsigned long V_40 = 0 ;
unsigned long V_147 ;
while ( V_64 != V_144 ) {
V_147 = F_90 ( V_143 , V_64 ) ;
if ( V_147 == V_131 ) {
F_26 ( L_38 , V_64 ) ;
return - V_148 ;
}
V_48 = V_64 & ( V_137 - 1 ) ;
V_146 = ( V_144 - V_64 ) >= ( V_137 - V_48 ) ?
V_137 - V_48 : V_144 - V_64 ;
F_91 ( V_28 , V_147 , V_145 + V_40 , V_146 ) ;
V_40 += V_146 ;
V_64 += V_146 ;
}
return 0 ;
}
static int F_92 ( struct V_23 * V_24 )
{
struct V_10 * V_11 = V_24 -> V_28 -> V_11 ;
if ( F_32 ( V_11 -> V_59 ) || F_58 ( V_11 -> V_59 ) ) {
if ( F_11 ( V_24 , 0 ) & ( 1 << 8 ) )
return 0 ;
}
return 1 ;
}
static T_2 F_93 ( struct V_23 * V_24 )
{
unsigned long V_64 = 0 ;
struct V_9 * V_15 ;
T_2 V_149 = 0 ;
T_2 V_58 = 0 ;
bool V_150 = false ;
struct V_52 * V_28 = V_24 -> V_28 ;
T_1 V_1 ;
V_64 = F_70 ( V_24 , 1 ) ;
V_1 = F_11 ( V_24 , 0 ) ;
V_15 = F_5 ( V_24 -> V_28 -> V_11 , V_1 , V_24 -> V_2 ) ;
if ( V_15 == NULL ) {
F_26 ( L_39 ,
V_1 , F_1 ( V_1 , V_24 -> V_2 ) ) ;
return - V_51 ;
}
do {
F_89 ( V_24 -> V_28 , V_24 -> V_28 -> V_151 . V_152 ,
V_64 , V_64 + 4 , & V_1 ) ;
V_15 = F_5 ( V_24 -> V_28 -> V_11 , V_1 , V_24 -> V_2 ) ;
if ( V_15 == NULL ) {
F_26 ( L_39 ,
V_1 , F_1 ( V_1 , V_24 -> V_2 ) ) ;
return - V_51 ;
}
if ( V_15 -> V_12 == V_153 ) {
V_150 = true ;
} else if ( V_15 -> V_12 == V_154 ) {
if ( F_94 ( V_1 ) == 0 ) {
V_150 = true ;
}
}
V_58 = F_18 ( V_15 , V_1 ) << 2 ;
V_149 += V_58 ;
V_64 += V_58 ;
} while ( ! V_150 );
return V_149 ;
}
static int F_95 ( struct V_23 * V_24 )
{
struct V_155 * V_156 ;
struct V_52 * V_28 = V_24 -> V_28 ;
unsigned long V_64 = 0 ;
T_2 V_149 ;
void * V_157 = NULL ;
int V_49 = 0 ;
V_64 = F_70 ( V_24 , 1 ) ;
V_149 = F_93 ( V_24 ) ;
V_156 = F_96 ( sizeof( * V_156 ) , V_158 ) ;
if ( V_156 == NULL )
return - V_159 ;
V_156 -> V_160 =
F_97 ( V_24 -> V_28 -> V_11 -> V_59 ,
F_98 ( V_149 , V_161 ) ) ;
if ( F_99 ( V_156 -> V_160 ) ) {
V_49 = F_100 ( V_156 -> V_160 ) ;
goto V_162;
}
V_156 -> V_40 = V_149 ;
F_101 ( & V_156 -> V_163 ) ;
V_157 = F_102 ( V_156 -> V_160 , V_164 ) ;
if ( F_99 ( V_157 ) ) {
V_49 = F_100 ( V_157 ) ;
goto V_165;
}
V_49 = F_103 ( V_156 -> V_160 , false ) ;
if ( V_49 ) {
F_26 ( L_40 ) ;
goto V_166;
}
V_156 -> V_145 = V_157 ;
V_156 -> V_167 = V_24 -> V_26 ;
V_49 = F_89 ( V_24 -> V_28 , V_24 -> V_28 -> V_151 . V_152 ,
V_64 , V_64 + V_149 ,
V_157 ) ;
if ( V_49 ) {
F_26 ( L_41 ) ;
goto V_166;
}
F_104 ( & V_156 -> V_163 , & V_24 -> V_73 -> V_168 ) ;
V_24 -> V_26 = V_157 ;
V_24 -> V_38 = V_64 ;
return 0 ;
V_166:
F_105 ( V_156 -> V_160 ) ;
V_165:
F_106 ( V_156 -> V_160 ) ;
V_162:
F_107 ( V_156 ) ;
return V_49 ;
}
static int F_108 ( struct V_23 * V_24 )
{
bool V_169 ;
int V_49 = 0 ;
struct V_52 * V_28 = V_24 -> V_28 ;
if ( V_24 -> V_34 == V_76 ) {
F_26 ( L_42 ) ;
return - V_51 ;
}
V_169 = F_94 ( F_11 ( V_24 , 0 ) ) == 1 ;
if ( V_169 && ( V_24 -> V_34 != V_77 ) ) {
F_26 ( L_43 ) ;
return - V_51 ;
}
V_24 -> V_79 = V_24 -> V_36 ;
F_87 ( V_24 ) ;
if ( V_24 -> V_34 == V_35 ) {
V_24 -> V_80 = V_24 -> V_38 + F_19 ( V_24 ) * sizeof( T_1 ) ;
V_24 -> V_34 = V_77 ;
} else if ( V_169 ) {
V_24 -> V_34 = V_76 ;
V_24 -> V_78 = V_24 -> V_38 + F_19 ( V_24 ) * sizeof( T_1 ) ;
V_24 -> V_43 = V_24 -> V_26 + F_19 ( V_24 ) * sizeof( T_1 ) ;
}
if ( F_92 ( V_24 ) ) {
V_49 = F_95 ( V_24 ) ;
if ( V_49 < 0 )
F_26 ( L_44 ) ;
} else {
V_49 = F_47 ( V_24 ) ;
if ( V_49 < 0 )
return V_49 ;
}
return V_49 ;
}
static void F_109 ( struct V_10 * V_11 , struct V_13 * V_14 )
{
F_110 ( V_11 -> V_170 , & V_14 -> V_171 , V_14 -> V_15 -> V_12 ) ;
}
static void F_111 ( struct V_23 * V_24 ,
T_3 V_172 , T_3 V_173 )
{
T_1 V_174 [ V_175 ] ;
int V_19 ;
T_1 V_58 = F_19 ( V_24 ) ;
if ( F_112 ( V_58 > V_175 ) ) {
F_8 ( L_45 ) ;
V_58 = V_175 ;
}
for ( V_19 = 0 ; V_19 < V_58 ; V_19 ++ )
V_174 [ V_19 ] = F_11 ( V_24 , V_19 ) ;
F_113 ( V_24 -> V_28 -> V_29 , V_24 -> V_2 , V_24 -> V_38 , V_174 ,
V_58 , V_24 -> V_34 == V_35 ,
V_172 , V_173 ) ;
}
static int F_114 ( struct V_23 * V_24 )
{
struct V_9 * V_15 ;
T_1 V_1 ;
int V_49 = 0 ;
T_3 V_176 , V_177 , V_178 ;
struct V_23 V_179 ;
struct V_52 * V_28 = V_24 -> V_28 ;
V_176 = F_115 () ;
V_1 = F_11 ( V_24 , 0 ) ;
V_15 = F_5 ( V_24 -> V_28 -> V_11 , V_1 , V_24 -> V_2 ) ;
if ( V_15 == NULL ) {
F_26 ( L_39 ,
V_1 , F_1 ( V_1 , V_24 -> V_2 ) ) ;
return - V_51 ;
}
F_8 ( L_46 , V_15 -> V_20 ) ;
V_24 -> V_15 = V_15 ;
V_177 = F_115 () ;
memcpy ( & V_179 , V_24 , sizeof( struct V_23 ) ) ;
if ( V_15 -> V_180 ) {
V_49 = V_15 -> V_180 ( V_24 ) ;
if ( V_49 < 0 ) {
F_26 ( L_47 , V_15 -> V_20 ) ;
return V_49 ;
}
}
V_178 = F_115 () ;
F_111 ( & V_179 , V_177 - V_176 , V_178 - V_177 ) ;
if ( ! ( V_15 -> V_45 & V_181 ) ) {
V_49 = F_46 ( V_24 ) ;
if ( V_49 ) {
F_26 ( L_48 , V_15 -> V_20 ) ;
return V_49 ;
}
}
return 0 ;
}
static inline bool F_116 ( unsigned long V_64 ,
unsigned long V_182 , unsigned int V_183 )
{
if ( V_183 >= V_182 )
return ( V_64 < V_182 ) || ( V_64 > V_183 ) ;
else
return ( V_64 > V_183 ) && ( V_64 < V_182 ) ;
}
static int F_117 ( struct V_23 * V_24 ,
unsigned long V_184 , unsigned long V_185 ,
unsigned long V_186 , unsigned long V_187 )
{
unsigned long V_182 , V_183 , V_188 ;
int V_49 = 0 ;
struct V_52 * V_28 = V_24 -> V_28 ;
V_182 = V_186 + V_184 ;
V_183 = V_186 + V_185 ;
V_188 = V_186 + V_187 ;
F_8 ( L_49 , V_182 , V_183 ) ;
while ( V_24 -> V_38 != V_183 ) {
if ( V_24 -> V_34 == V_35 ) {
if ( ! ( V_24 -> V_38 >= V_186 ) ||
! ( V_24 -> V_38 < V_188 ) ) {
F_26 ( L_50
L_51 ,
V_24 -> V_38 , V_186 ,
V_188 ) ;
F_12 ( V_24 ) ;
return - V_51 ;
}
if ( F_116 ( V_24 -> V_38 , V_182 , V_183 ) ) {
F_26 ( L_52
L_53 ,
V_24 -> V_38 , V_186 ,
V_184 , V_185 ) ;
F_12 ( V_24 ) ;
break;
}
}
V_49 = F_114 ( V_24 ) ;
if ( V_49 ) {
F_26 ( L_54 ) ;
F_12 ( V_24 ) ;
break;
}
}
F_8 ( L_55 ) ;
return V_49 ;
}
static int F_118 ( struct V_189 * V_73 )
{
unsigned long V_182 , V_183 , V_188 ;
struct V_23 V_24 ;
int V_49 = 0 ;
if ( F_14 ( ! F_16 ( V_73 -> V_186 , V_137 ) ) )
return - V_51 ;
V_182 = V_73 -> V_186 + V_73 -> V_184 ;
V_183 = V_73 -> V_186 + V_73 -> V_185 ;
V_188 = V_73 -> V_186 + F_119 ( V_73 -> V_190 ) ;
V_24 . V_34 = V_35 ;
V_24 . V_36 = V_37 ;
V_24 . V_28 = V_73 -> V_28 ;
V_24 . V_2 = V_73 -> V_2 ;
V_24 . V_30 = V_73 -> V_186 ;
V_24 . V_31 = F_119 ( V_73 -> V_190 ) ;
V_24 . V_32 = V_182 ;
V_24 . V_33 = V_183 ;
V_24 . V_42 = V_73 -> V_191 ;
V_24 . V_73 = V_73 ;
if ( ( V_192 & ( 1 << V_73 -> V_2 ) ) ||
V_182 == V_183 )
return 0 ;
V_49 = F_15 ( & V_24 , V_182 ) ;
if ( V_49 )
goto V_193;
V_49 = F_117 ( & V_24 , V_73 -> V_184 , V_73 -> V_185 ,
V_73 -> V_186 , F_119 ( V_73 -> V_190 ) ) ;
V_193:
return V_49 ;
}
static int F_120 ( struct V_194 * V_195 )
{
unsigned long V_182 , V_183 , V_188 , V_31 , V_33 ;
struct V_23 V_24 ;
int V_49 = 0 ;
if ( F_14 ( ! F_16 ( V_195 -> V_196 . V_134 , V_137 ) ) )
return - V_51 ;
V_33 = V_195 -> V_196 . V_197 + 3 * sizeof( T_2 ) ;
V_31 = F_121 ( V_195 -> V_196 . V_197 + V_198 ,
V_161 ) ;
V_182 = V_195 -> V_196 . V_134 ;
V_183 = V_195 -> V_196 . V_134 + V_33 ;
V_188 = V_195 -> V_196 . V_134 + V_31 ;
V_24 . V_34 = V_35 ;
V_24 . V_36 = V_37 ;
V_24 . V_28 = V_195 -> V_73 -> V_28 ;
V_24 . V_2 = V_195 -> V_73 -> V_2 ;
V_24 . V_30 = V_195 -> V_196 . V_134 ;
V_24 . V_31 = V_31 ;
V_24 . V_32 = V_182 ;
V_24 . V_33 = V_183 ;
V_24 . V_42 = V_195 -> V_196 . V_199 ;
V_24 . V_73 = V_195 -> V_73 ;
V_49 = F_15 ( & V_24 , V_182 ) ;
if ( V_49 )
goto V_193;
V_49 = F_117 ( & V_24 , 0 , V_33 ,
V_195 -> V_196 . V_134 , V_31 ) ;
V_193:
return V_49 ;
}
static int F_122 ( struct V_189 * V_73 )
{
struct V_52 * V_28 = V_73 -> V_28 ;
int V_2 = V_73 -> V_2 ;
struct V_200 * V_201 = V_28 -> V_201 ;
struct V_202 * V_203 = V_201 -> V_204 [ V_2 ] . V_203 ;
unsigned long V_182 , V_183 , V_205 , V_206 ;
unsigned int V_146 = 0 ;
int V_49 ;
V_206 = F_119 ( V_73 -> V_190 ) ;
V_73 -> V_187 = ( V_73 -> V_185 + V_206 -
V_73 -> V_184 ) % V_206 ;
V_182 = V_73 -> V_186 + V_73 -> V_184 ;
V_183 = V_73 -> V_186 + V_73 -> V_185 ;
V_205 = V_73 -> V_186 + V_206 ;
V_49 = F_123 ( V_73 -> V_207 , V_73 -> V_187 / 4 ) ;
if ( V_49 )
return V_49 ;
V_73 -> V_191 = V_203 -> V_208 + V_203 -> V_209 ;
if ( V_182 > V_183 ) {
V_49 = F_89 ( V_28 , V_28 -> V_151 . V_152 ,
V_182 , V_205 ,
V_73 -> V_191 ) ;
if ( V_49 ) {
F_26 ( L_41 ) ;
return V_49 ;
}
V_146 = V_205 - V_182 ;
V_182 = V_73 -> V_186 ;
}
V_49 = F_89 ( V_28 , V_28 -> V_151 . V_152 ,
V_182 , V_183 ,
V_73 -> V_191 + V_146 ) ;
if ( V_49 ) {
F_26 ( L_41 ) ;
return V_49 ;
}
V_203 -> V_209 += V_73 -> V_187 ;
F_124 ( V_203 ) ;
return 0 ;
}
int F_125 ( struct V_189 * V_73 )
{
int V_49 ;
struct V_52 * V_28 = V_73 -> V_28 ;
V_49 = F_122 ( V_73 ) ;
if ( V_49 ) {
F_26 ( L_56 ) ;
return V_49 ;
}
V_49 = F_118 ( V_73 ) ;
if ( V_49 ) {
F_26 ( L_57 ) ;
return V_49 ;
}
return 0 ;
}
static int F_126 ( struct V_194 * V_195 )
{
int V_210 = V_195 -> V_196 . V_197 ;
unsigned long V_134 = V_195 -> V_196 . V_134 ;
struct V_52 * V_28 = V_195 -> V_73 -> V_28 ;
struct V_211 * V_160 ;
int V_49 = 0 ;
void * V_212 ;
V_160 = F_97 ( V_195 -> V_73 -> V_28 -> V_11 -> V_59 ,
F_98 ( V_210 + V_198 ,
V_161 ) ) ;
if ( F_99 ( V_160 ) )
return F_100 ( V_160 ) ;
V_212 = F_102 ( V_160 , V_164 ) ;
if ( F_99 ( V_212 ) ) {
F_26 ( L_58 ) ;
V_49 = F_100 ( V_212 ) ;
goto V_165;
}
V_49 = F_103 ( V_160 , false ) ;
if ( V_49 ) {
F_26 ( L_59 ) ;
goto V_166;
}
V_49 = F_89 ( V_195 -> V_73 -> V_28 ,
V_195 -> V_73 -> V_28 -> V_151 . V_152 ,
V_134 , V_134 + V_210 ,
V_212 ) ;
if ( V_49 ) {
F_26 ( L_60 ) ;
goto V_166;
}
V_195 -> V_196 . V_160 = V_160 ;
V_195 -> V_196 . V_199 = V_212 ;
return 0 ;
V_166:
F_105 ( V_160 ) ;
V_165:
F_106 ( V_195 -> V_196 . V_160 ) ;
return V_49 ;
}
static int F_127 ( struct V_194 * V_195 )
{
T_2 V_213 [ V_214 ] = { 0 } ;
unsigned char * V_215 ;
V_213 [ 0 ] = 0x18800001 ;
V_213 [ 1 ] = V_195 -> V_216 . V_134 ;
V_215 = ( unsigned char * ) V_195 -> V_196 . V_199 +
V_195 -> V_196 . V_197 ;
memcpy ( V_215 , V_213 , V_198 ) ;
return 0 ;
}
int F_128 ( struct V_194 * V_195 )
{
int V_49 ;
struct V_52 * V_28 = V_195 -> V_73 -> V_28 ;
if ( V_195 -> V_196 . V_197 == 0 )
return 0 ;
V_49 = F_126 ( V_195 ) ;
if ( V_49 ) {
F_26 ( L_61 ) ;
return V_49 ;
}
F_127 ( V_195 ) ;
V_49 = F_120 ( V_195 ) ;
if ( V_49 ) {
F_26 ( L_62 ) ;
return V_49 ;
}
return 0 ;
}
static struct V_9 * F_129 ( struct V_10 * V_11 ,
unsigned int V_12 , int V_16 )
{
struct V_9 * V_15 = NULL ;
unsigned int V_203 ;
F_130 (ring, (unsigned long *)&rings, I915_NUM_ENGINES) {
V_15 = F_3 ( V_11 , V_12 , V_203 ) ;
if ( V_15 )
break;
}
return V_15 ;
}
static int F_131 ( struct V_10 * V_11 )
{
int V_19 ;
struct V_13 * V_14 ;
struct V_9 * V_15 ;
unsigned int V_217 ;
V_217 = F_132 ( V_11 ) ;
for ( V_19 = 0 ; V_19 < F_49 ( V_9 ) ; V_19 ++ ) {
if ( ! ( V_9 [ V_19 ] . V_218 & V_217 ) )
continue;
V_14 = F_133 ( sizeof( * V_14 ) , V_158 ) ;
if ( ! V_14 )
return - V_159 ;
V_14 -> V_15 = & V_9 [ V_19 ] ;
V_15 = F_129 ( V_11 ,
V_14 -> V_15 -> V_12 , V_14 -> V_15 -> V_16 ) ;
if ( V_15 ) {
F_24 ( L_63 , V_14 -> V_15 -> V_20 ,
V_15 -> V_20 ) ;
return - V_219 ;
}
F_134 ( & V_14 -> V_171 ) ;
F_109 ( V_11 , V_14 ) ;
F_8 ( L_64 ,
V_14 -> V_15 -> V_20 , V_14 -> V_15 -> V_12 , V_14 -> V_15 -> V_45 ,
V_14 -> V_15 -> V_218 , V_14 -> V_15 -> V_16 ) ;
}
return 0 ;
}
static void F_135 ( struct V_10 * V_11 )
{
struct V_220 * V_221 ;
struct V_13 * V_14 ;
int V_19 ;
F_136 (gvt->cmd_table, i, tmp, e, hlist)
F_107 ( V_14 ) ;
F_137 ( V_11 -> V_170 ) ;
}
void F_138 ( struct V_10 * V_11 )
{
F_135 ( V_11 ) ;
}
int F_139 ( struct V_10 * V_11 )
{
int V_49 ;
V_49 = F_131 ( V_11 ) ;
if ( V_49 ) {
F_138 ( V_11 ) ;
return V_49 ;
}
return 0 ;
}
