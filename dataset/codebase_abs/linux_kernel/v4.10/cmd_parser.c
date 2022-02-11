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
static int F_21 ( struct V_23 * V_24 ,
unsigned int V_48 , unsigned int V_25 , char * V_1 )
{
struct V_50 * V_28 = V_24 -> V_28 ;
struct V_10 * V_11 = V_28 -> V_11 ;
if ( V_48 + 4 > V_11 -> V_51 . V_52 ) {
F_8 ( L_16 ,
V_1 , V_48 ) ;
return - V_53 ;
}
if ( ! F_22 ( V_11 , V_48 ) ) {
F_8 ( L_17 ,
V_24 -> V_28 -> V_29 , V_1 , V_48 ) ;
return 0 ;
}
if ( F_20 ( V_48 ) ) {
F_8 ( L_18 ,
V_24 -> V_28 -> V_29 , V_48 ) ;
return 0 ;
}
if ( V_48 == F_23 ( V_54 ) ||
V_48 == F_23 ( V_55 ) ) {
F_24 ( V_24 , F_10 ( V_24 , V_25 ) , V_56 ) ;
}
F_25 ( V_11 , V_48 ) ;
return 0 ;
}
static int F_26 ( struct V_23 * V_24 )
{
int V_19 , V_49 = 0 ;
int V_57 = F_19 ( V_24 ) ;
struct V_10 * V_11 = V_24 -> V_28 -> V_11 ;
for ( V_19 = 1 ; V_19 < V_57 ; V_19 += 2 ) {
if ( F_27 ( V_11 -> V_58 ) &&
( V_24 -> V_2 != V_59 ) ) {
if ( V_24 -> V_2 == V_60 &&
F_28 ( V_24 , V_19 ) ==
F_23 ( V_54 ) )
V_49 |= 0 ;
else
V_49 |= ( F_29 ( V_24 , V_19 ) ) ? - V_53 : 0 ;
}
if ( V_49 )
break;
V_49 |= F_21 ( V_24 , F_28 ( V_24 , V_19 ) , V_19 , L_19 ) ;
}
return V_49 ;
}
static int F_30 ( struct V_23 * V_24 )
{
int V_19 , V_49 = 0 ;
int V_57 = F_19 ( V_24 ) ;
for ( V_19 = 1 ; V_19 < V_57 ; V_19 += 2 ) {
if ( F_27 ( V_24 -> V_28 -> V_11 -> V_58 ) )
V_49 |= ( ( F_29 ( V_24 , V_19 ) ||
( F_29 ( V_24 , V_19 + 1 ) ) ) ) ?
- V_53 : 0 ;
if ( V_49 )
break;
V_49 |= F_21 ( V_24 , F_28 ( V_24 , V_19 ) , V_19 , L_20 ) ;
V_49 |= F_21 ( V_24 , F_28 ( V_24 , V_19 + 1 ) , V_19 , L_21 ) ;
}
return V_49 ;
}
static int F_31 ( struct V_23 * V_24 )
{
struct V_10 * V_11 = V_24 -> V_28 -> V_11 ;
int V_61 = V_11 -> V_51 . V_62 ;
unsigned long V_63 ;
int V_19 , V_49 = 0 ;
int V_57 = F_19 ( V_24 ) ;
for ( V_19 = 1 ; V_19 < V_57 ; ) {
if ( F_27 ( V_11 -> V_58 ) )
V_49 |= ( F_29 ( V_24 , V_19 ) ) ? - V_53 : 0 ;
if ( V_49 )
break;
V_49 |= F_21 ( V_24 , F_28 ( V_24 , V_19 ) , V_19 , L_22 ) ;
if ( F_11 ( V_24 , 0 ) & ( 1 << 22 ) ) {
V_63 = F_32 ( V_24 , V_19 + 1 ) ;
if ( V_61 == 8 )
V_63 |= ( F_33 ( V_24 , V_19 + 2 ) ) << 32 ;
V_49 |= F_34 ( V_24 , V_63 , sizeof( T_1 ) , false ) ;
}
V_19 += F_35 ( V_24 ) + 1 ;
}
return V_49 ;
}
static int F_36 ( struct V_23 * V_24 )
{
int V_61 = V_24 -> V_28 -> V_11 -> V_51 . V_62 ;
unsigned long V_63 ;
int V_19 , V_49 = 0 ;
int V_57 = F_19 ( V_24 ) ;
for ( V_19 = 1 ; V_19 < V_57 ; ) {
V_49 |= F_21 ( V_24 , F_28 ( V_24 , V_19 ) , V_19 , L_23 ) ;
if ( F_11 ( V_24 , 0 ) & ( 1 << 22 ) ) {
V_63 = F_32 ( V_24 , V_19 + 1 ) ;
if ( V_61 == 8 )
V_63 |= ( F_33 ( V_24 , V_19 + 2 ) ) << 32 ;
V_49 |= F_34 ( V_24 , V_63 , sizeof( T_1 ) , false ) ;
}
V_19 += F_35 ( V_24 ) + 1 ;
}
return V_49 ;
}
static int F_37 ( struct V_23 * V_24 )
{
int V_61 = V_24 -> V_28 -> V_11 -> V_51 . V_62 ;
unsigned long V_63 ;
bool V_64 = false ;
unsigned int V_65 ;
int V_49 = 0 ;
V_65 = ( F_11 ( V_24 , 1 ) & V_66 ) >> 14 ;
if ( F_11 ( V_24 , 1 ) & V_67 )
V_49 = F_21 ( V_24 , F_28 ( V_24 , 2 ) , 1 , L_24 ) ;
else if ( V_65 ) {
if ( V_65 == 2 )
V_49 = F_21 ( V_24 , 0x2350 , 1 , L_24 ) ;
else if ( V_65 == 3 )
V_49 = F_21 ( V_24 , 0x2358 , 1 , L_24 ) ;
else if ( V_65 == 1 ) {
if ( ( F_11 ( V_24 , 2 ) & ( 1 << 2 ) ) ) {
V_63 = F_11 ( V_24 , 2 ) & F_38 ( 31 , 3 ) ;
if ( V_61 == 8 )
V_63 |= ( F_33 ( V_24 , 3 ) ) << 32 ;
if ( F_11 ( V_24 , 1 ) & ( 1 << 21 ) )
V_64 = true ;
V_49 |= F_34 ( V_24 , V_63 , sizeof( V_39 ) ,
V_64 ) ;
}
}
}
if ( V_49 )
return V_49 ;
if ( F_11 ( V_24 , 1 ) & V_68 )
F_39 ( V_69 [ V_24 -> V_2 ] . V_70 ,
V_24 -> V_71 -> V_72 ) ;
return 0 ;
}
static int F_40 ( struct V_23 * V_24 )
{
F_39 ( V_69 [ V_24 -> V_2 ] . V_73 ,
V_24 -> V_71 -> V_72 ) ;
return 0 ;
}
static int F_41 ( struct V_23 * V_24 )
{
return F_17 ( V_24 , F_19 ( V_24 ) ) ;
}
static int F_42 ( struct V_23 * V_24 )
{
int V_49 ;
if ( V_24 -> V_34 == V_74 ) {
V_24 -> V_34 = V_75 ;
V_49 = F_15 ( V_24 , V_24 -> V_76 ) ;
V_24 -> V_36 = V_24 -> V_77 ;
} else {
V_24 -> V_34 = V_35 ;
V_24 -> V_36 = V_37 ;
if ( V_24 -> V_78 >= V_24 -> V_30 + V_24 -> V_31 )
V_24 -> V_78 -= V_24 -> V_31 ;
V_49 = F_15 ( V_24 , V_24 -> V_78 ) ;
}
return V_49 ;
}
static int F_43 ( struct V_23 * V_24 ,
struct V_79 * V_15 )
{
struct V_80 * V_58 = V_24 -> V_28 -> V_11 -> V_58 ;
struct V_81 V_82 [] = {
[ 0 ] = { V_83 , V_84 , V_85 } ,
[ 1 ] = { V_86 , V_84 , V_87 } ,
[ 2 ] = { V_83 , V_88 , V_89 } ,
[ 3 ] = { V_86 , V_88 , V_90 } ,
[ 4 ] = { V_91 , V_84 , V_92 } ,
[ 5 ] = { V_91 , V_88 , V_93 } ,
} ;
T_1 V_94 , V_95 , V_96 ;
T_1 V_97 ;
V_94 = F_11 ( V_24 , 0 ) ;
V_95 = F_11 ( V_24 , 1 ) ;
V_96 = F_11 ( V_24 , 2 ) ;
V_97 = ( V_94 & F_38 ( 21 , 19 ) ) >> 19 ;
if ( F_14 ( V_97 >= F_44 ( V_82 ) ) )
return - V_53 ;
V_15 -> V_98 = V_82 [ V_97 ] . V_98 ;
V_15 -> V_99 = V_82 [ V_97 ] . V_99 ;
V_15 -> V_100 = V_82 [ V_97 ] . V_100 ;
V_15 -> V_101 = ( V_95 & F_38 ( 15 , 6 ) ) >> 6 ;
V_15 -> V_102 = ( V_95 & 0x1 ) ;
V_15 -> V_103 = ( V_96 & F_38 ( 31 , 12 ) ) >> 12 ;
V_15 -> V_104 = ( ( V_96 & F_38 ( 1 , 0 ) ) == 0x1 ) ;
if ( V_15 -> V_99 == V_84 ) {
V_15 -> V_105 = F_45 ( V_15 -> V_98 ) ;
V_15 -> V_106 = F_46 ( V_15 -> V_98 ) ;
V_15 -> V_107 = F_47 ( V_15 -> V_98 ) ;
} else if ( V_15 -> V_99 == V_88 ) {
V_15 -> V_105 = F_48 ( V_15 -> V_98 ) ;
V_15 -> V_106 = F_49 ( V_15 -> V_98 ) ;
V_15 -> V_107 = F_50 ( V_15 -> V_98 ) ;
} else {
F_14 ( 1 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_51 ( struct V_23 * V_24 ,
struct V_79 * V_15 )
{
struct V_80 * V_58 = V_24 -> V_28 -> V_11 -> V_58 ;
T_1 V_94 = F_11 ( V_24 , 0 ) ;
T_1 V_95 = F_11 ( V_24 , 1 ) ;
T_1 V_96 = F_11 ( V_24 , 2 ) ;
T_1 V_99 = ( V_94 & F_38 ( 12 , 8 ) ) >> 8 ;
switch ( V_99 ) {
case V_108 :
V_15 -> V_98 = V_83 ;
V_15 -> V_100 = V_85 ;
break;
case V_109 :
V_15 -> V_98 = V_86 ;
V_15 -> V_100 = V_87 ;
break;
case V_110 :
V_15 -> V_98 = V_91 ;
V_15 -> V_100 = V_92 ;
break;
default:
F_8 ( L_25 , V_99 ) ;
return - V_53 ;
}
V_15 -> V_98 = V_111 ;
V_15 -> V_101 = ( V_95 & F_38 ( 15 , 6 ) ) >> 6 ;
V_15 -> V_102 = ( V_95 & F_38 ( 2 , 0 ) ) ;
V_15 -> V_103 = ( V_96 & F_38 ( 31 , 12 ) ) >> 12 ;
V_15 -> V_104 = ( ( V_96 & F_38 ( 1 , 0 ) ) == 0x1 ) ;
V_15 -> V_105 = F_45 ( V_15 -> V_98 ) ;
V_15 -> V_106 = F_46 ( V_15 -> V_98 ) ;
V_15 -> V_107 = F_47 ( V_15 -> V_98 ) ;
return 0 ;
}
static int F_52 ( struct V_23 * V_24 ,
struct V_79 * V_15 )
{
struct V_80 * V_58 = V_24 -> V_28 -> V_11 -> V_58 ;
T_1 V_112 , V_113 ;
if ( ! V_15 -> V_104 )
return 0 ;
if ( F_53 ( V_58 ) ) {
V_112 = F_54 ( V_24 -> V_28 , V_15 -> V_106 ) & F_38 ( 9 , 0 ) ;
V_113 = ( F_54 ( V_24 -> V_28 , V_15 -> V_105 ) &
F_38 ( 12 , 10 ) ) >> 10 ;
} else {
V_112 = ( F_54 ( V_24 -> V_28 , V_15 -> V_106 ) &
F_38 ( 15 , 6 ) ) >> 6 ;
V_113 = ( F_54 ( V_24 -> V_28 , V_15 -> V_105 ) & ( 1 << 10 ) ) >> 10 ;
}
if ( V_112 != V_15 -> V_101 )
F_55 ( L_26 ) ;
if ( V_113 != V_15 -> V_102 )
F_55 ( L_27 ) ;
return 0 ;
}
static int F_56 (
struct V_23 * V_24 ,
struct V_79 * V_15 )
{
struct V_80 * V_58 = V_24 -> V_28 -> V_11 -> V_58 ;
struct V_50 * V_28 = V_24 -> V_28 ;
F_57 ( & F_54 ( V_28 , V_15 -> V_107 ) , F_38 ( 31 , 12 ) ,
V_15 -> V_103 << 12 ) ;
if ( F_53 ( V_58 ) ) {
F_57 ( & F_54 ( V_28 , V_15 -> V_106 ) , F_38 ( 9 , 0 ) ,
V_15 -> V_101 ) ;
F_57 ( & F_54 ( V_28 , V_15 -> V_105 ) , F_38 ( 12 , 10 ) ,
V_15 -> V_102 << 10 ) ;
} else {
F_57 ( & F_54 ( V_28 , V_15 -> V_106 ) , F_38 ( 15 , 6 ) ,
V_15 -> V_101 << 6 ) ;
F_57 ( & F_54 ( V_28 , V_15 -> V_105 ) , F_38 ( 10 , 10 ) ,
V_15 -> V_102 << 10 ) ;
}
F_54 ( V_28 , F_58 ( V_15 -> V_98 ) ) ++ ;
F_59 ( V_28 , V_15 -> V_100 ) ;
return 0 ;
}
static int F_60 ( struct V_23 * V_24 ,
struct V_79 * V_15 )
{
struct V_80 * V_58 = V_24 -> V_28 -> V_11 -> V_58 ;
if ( F_27 ( V_58 ) )
return F_43 ( V_24 , V_15 ) ;
if ( F_53 ( V_58 ) )
return F_51 ( V_24 , V_15 ) ;
return - V_114 ;
}
static int F_61 ( struct V_23 * V_24 ,
struct V_79 * V_15 )
{
struct V_80 * V_58 = V_24 -> V_28 -> V_11 -> V_58 ;
if ( F_27 ( V_58 ) || F_53 ( V_58 ) )
return F_52 ( V_24 , V_15 ) ;
return - V_114 ;
}
static int F_62 (
struct V_23 * V_24 ,
struct V_79 * V_15 )
{
struct V_80 * V_58 = V_24 -> V_28 -> V_11 -> V_58 ;
if ( F_27 ( V_58 ) || F_53 ( V_58 ) )
return F_56 ( V_24 , V_15 ) ;
return - V_114 ;
}
static int F_63 ( struct V_23 * V_24 )
{
struct V_79 V_15 ;
int V_49 ;
int V_19 ;
int V_40 = F_19 ( V_24 ) ;
V_49 = F_60 ( V_24 , & V_15 ) ;
if ( V_49 ) {
F_8 ( L_28 ) ;
return V_49 ;
}
V_49 = F_61 ( V_24 , & V_15 ) ;
if ( V_49 ) {
F_8 ( L_29 ) ;
return V_49 ;
}
V_49 = F_62 ( V_24 , & V_15 ) ;
if ( V_49 ) {
F_8 ( L_30 ) ;
return V_49 ;
}
for ( V_19 = 0 ; V_19 < V_40 ; V_19 ++ )
F_24 ( V_24 , F_10 ( V_24 , V_19 ) , V_115 ) ;
return 0 ;
}
static bool F_64 ( T_1 V_1 )
{
return V_1 & ( V_116 |
V_117 |
V_118 |
V_119 |
V_120 |
V_121 ) ;
}
static int F_65 ( struct V_23 * V_24 )
{
T_1 V_1 = F_11 ( V_24 , 0 ) ;
if ( ! F_64 ( V_1 ) )
return 0 ;
F_24 ( V_24 , F_10 ( V_24 , 0 ) , V_115 ) ;
return 0 ;
}
static unsigned long F_66 ( struct V_23 * V_24 , int V_25 )
{
unsigned long V_122 ;
unsigned long V_123 , V_124 ;
int V_61 = V_24 -> V_28 -> V_11 -> V_51 . V_62 ;
if ( F_14 ( V_61 != 4 && V_61 != 8 ) )
return V_125 ;
V_124 = F_11 ( V_24 , V_25 ) & V_126 ;
if ( V_61 == 4 ) {
V_122 = V_124 ;
} else {
V_123 = F_11 ( V_24 , V_25 + 1 ) & V_127 ;
V_122 = ( ( ( unsigned long ) V_123 ) << 32 ) | V_124 ;
}
return V_122 ;
}
static inline int F_34 ( struct V_23 * V_24 ,
unsigned long V_128 , int V_129 , bool V_64 )
{
struct V_50 * V_28 = V_24 -> V_28 ;
T_1 V_130 = V_28 -> V_11 -> V_51 . V_130 ;
int V_19 ;
int V_49 ;
if ( V_129 > V_130 ) {
F_8 ( L_31 , V_24 -> V_15 -> V_20 ) ;
return - V_53 ;
}
if ( V_64 ) {
if ( V_128 >= V_131 / sizeof( V_39 ) ) {
V_49 = - V_53 ;
goto V_132;
}
} else if ( ( ! F_67 ( V_24 -> V_28 , V_128 ) ) ||
( ! F_67 ( V_24 -> V_28 ,
V_128 + V_129 - 1 ) ) ) {
V_49 = - V_53 ;
goto V_132;
}
return 0 ;
V_132:
F_8 ( L_32 ,
V_24 -> V_15 -> V_20 , V_128 , V_129 ) ;
F_9 ( L_33 ) ;
for ( V_19 = 0 ; V_19 < F_19 ( V_24 ) ; V_19 ++ ) {
if ( ! ( V_19 % 4 ) )
F_9 ( L_34 , F_11 ( V_24 , V_19 ) ) ;
else
F_9 ( L_15 , F_11 ( V_24 , V_19 ) ) ;
}
F_9 ( L_35 ,
V_28 -> V_29 ,
F_68 ( V_28 ) ,
F_69 ( V_28 ) ,
F_70 ( V_28 ) ,
F_71 ( V_28 ) ) ;
return V_49 ;
}
static int F_72 ( struct V_23 * V_24 )
{
int V_61 = V_24 -> V_28 -> V_11 -> V_51 . V_62 ;
int V_129 = ( F_19 ( V_24 ) - 3 ) * sizeof( T_1 ) ;
int V_133 = ( F_11 ( V_24 , 2 ) & ( 1 << 0 ) ) ? 1 : 0 ;
unsigned long V_63 , V_124 , V_123 ;
int V_49 = 0 ;
if ( ! ( F_11 ( V_24 , 0 ) & ( 1 << 22 ) ) )
return 0 ;
V_63 = F_11 ( V_24 , 2 ) & F_38 ( 31 , 2 ) ;
if ( V_61 == 8 ) {
V_124 = F_11 ( V_24 , 1 ) & F_38 ( 31 , 2 ) ;
V_123 = F_11 ( V_24 , 2 ) & F_38 ( 15 , 0 ) ;
V_63 = ( V_123 << 32 ) | V_124 ;
V_133 = ( F_11 ( V_24 , 1 ) & ( 1 << 0 ) ) ? 1 : 0 ;
}
V_49 = F_34 ( V_24 , V_63 + V_129 * V_133 , V_129 , false ) ;
return V_49 ;
}
static inline int F_73 ( struct V_23 * V_24 )
{
F_8 ( L_36 ,
V_24 -> V_28 -> V_29 , V_24 -> V_15 -> V_20 ) ;
return - V_53 ;
}
static int F_74 ( struct V_23 * V_24 )
{
return F_73 ( V_24 ) ;
}
static int F_75 ( struct V_23 * V_24 )
{
return F_73 ( V_24 ) ;
}
static int F_76 ( struct V_23 * V_24 )
{
return F_73 ( V_24 ) ;
}
static int F_77 ( struct V_23 * V_24 )
{
int V_61 = V_24 -> V_28 -> V_11 -> V_51 . V_62 ;
int V_129 = ( 1 << ( ( F_11 ( V_24 , 0 ) & F_38 ( 20 , 19 ) ) >> 19 ) ) *
sizeof( T_1 ) ;
unsigned long V_63 , V_123 ;
int V_49 = 0 ;
if ( ! ( F_11 ( V_24 , 0 ) & ( 1 << 22 ) ) )
return V_49 ;
V_63 = F_11 ( V_24 , 1 ) & F_38 ( 31 , 2 ) ;
if ( V_61 == 8 ) {
V_123 = F_11 ( V_24 , 2 ) & F_38 ( 15 , 0 ) ;
V_63 = ( V_123 << 32 ) | V_63 ;
}
V_49 = F_34 ( V_24 , V_63 , V_129 , false ) ;
return V_49 ;
}
static int F_78 ( struct V_23 * V_24 )
{
return F_73 ( V_24 ) ;
}
static int F_79 ( struct V_23 * V_24 )
{
return F_73 ( V_24 ) ;
}
static int F_80 (
struct V_23 * V_24 )
{
return F_73 ( V_24 ) ;
}
static int F_81 ( struct V_23 * V_24 )
{
return F_73 ( V_24 ) ;
}
static int F_82 ( struct V_23 * V_24 )
{
int V_61 = V_24 -> V_28 -> V_11 -> V_51 . V_62 ;
unsigned long V_63 ;
bool V_64 = false ;
int V_49 = 0 ;
if ( ( ( F_11 ( V_24 , 0 ) >> 14 ) & 0x3 ) && ( F_11 ( V_24 , 1 ) & ( 1 << 2 ) ) ) {
V_63 = F_11 ( V_24 , 1 ) & F_38 ( 31 , 3 ) ;
if ( V_61 == 8 )
V_63 |= ( F_11 ( V_24 , 2 ) & F_38 ( 15 , 0 ) ) << 32 ;
if ( F_11 ( V_24 , 0 ) & ( 1 << 21 ) )
V_64 = true ;
V_49 = F_34 ( V_24 , V_63 , sizeof( V_39 ) , V_64 ) ;
}
if ( ( F_11 ( V_24 , 0 ) & ( 1 << 8 ) ) )
F_39 ( V_69 [ V_24 -> V_2 ] . V_134 ,
V_24 -> V_71 -> V_72 ) ;
return V_49 ;
}
static void F_83 ( struct V_23 * V_24 )
{
if ( ( V_24 -> V_34 == V_35 ) &&
( F_84 ( F_11 ( V_24 , 0 ) ) == 1 ) ) {
V_24 -> V_36 = V_135 ;
}
}
static int F_85 ( struct V_50 * V_28 , struct V_136 * V_137 ,
unsigned long V_63 , unsigned long V_138 , void * V_139 )
{
unsigned long V_140 , V_48 ;
unsigned long V_40 = 0 ;
unsigned long V_141 ;
while ( V_63 != V_138 ) {
V_141 = F_86 ( V_137 , V_63 ) ;
if ( V_141 == V_125 ) {
F_8 ( L_37 , V_63 ) ;
return - V_142 ;
}
V_48 = V_63 & ( V_131 - 1 ) ;
V_140 = ( V_138 - V_63 ) >= ( V_131 - V_48 ) ?
V_131 - V_48 : V_138 - V_63 ;
F_87 ( V_28 , V_141 , V_139 + V_40 , V_140 ) ;
V_40 += V_140 ;
V_63 += V_140 ;
}
return 0 ;
}
static int F_88 ( struct V_23 * V_24 )
{
struct V_10 * V_11 = V_24 -> V_28 -> V_11 ;
if ( F_27 ( V_11 -> V_58 ) || F_53 ( V_11 -> V_58 ) ) {
if ( F_11 ( V_24 , 0 ) & ( 1 << 8 ) )
return 0 ;
}
return 1 ;
}
static T_2 F_89 ( struct V_23 * V_24 )
{
unsigned long V_63 = 0 ;
struct V_9 * V_15 ;
T_2 V_143 = 0 ;
T_2 V_57 = 0 ;
bool V_144 = false ;
T_1 V_1 ;
V_63 = F_66 ( V_24 , 1 ) ;
V_1 = F_11 ( V_24 , 0 ) ;
V_15 = F_5 ( V_24 -> V_28 -> V_11 , V_1 , V_24 -> V_2 ) ;
if ( V_15 == NULL ) {
F_8 ( L_38 ,
V_1 , F_1 ( V_1 , V_24 -> V_2 ) ) ;
return - V_53 ;
}
do {
F_85 ( V_24 -> V_28 , V_24 -> V_28 -> V_145 . V_146 ,
V_63 , V_63 + 4 , & V_1 ) ;
V_15 = F_5 ( V_24 -> V_28 -> V_11 , V_1 , V_24 -> V_2 ) ;
if ( V_15 == NULL ) {
F_8 ( L_38 ,
V_1 , F_1 ( V_1 , V_24 -> V_2 ) ) ;
return - V_53 ;
}
if ( V_15 -> V_12 == V_147 ) {
V_144 = true ;
} else if ( V_15 -> V_12 == V_148 ) {
if ( F_90 ( V_1 ) == 0 ) {
V_144 = true ;
}
}
V_57 = F_18 ( V_15 , V_1 ) << 2 ;
V_143 += V_57 ;
V_63 += V_57 ;
} while ( ! V_144 );
return V_143 ;
}
static int F_91 ( struct V_23 * V_24 )
{
struct V_149 * V_150 ;
unsigned long V_63 = 0 ;
T_2 V_143 ;
void * V_151 = NULL ;
int V_49 = 0 ;
V_63 = F_66 ( V_24 , 1 ) ;
V_143 = F_89 ( V_24 ) ;
V_150 = F_92 ( sizeof( * V_150 ) , V_152 ) ;
if ( V_150 == NULL )
return - V_153 ;
V_150 -> V_154 =
F_93 ( & ( V_24 -> V_28 -> V_11 -> V_58 -> V_155 ) ,
F_94 ( V_143 , V_156 ) ) ;
if ( F_95 ( V_150 -> V_154 ) ) {
V_49 = F_96 ( V_150 -> V_154 ) ;
goto V_157;
}
V_150 -> V_40 = V_143 ;
F_97 ( & V_150 -> V_158 ) ;
V_151 = F_98 ( V_150 -> V_154 , V_159 ) ;
if ( F_95 ( V_151 ) ) {
V_49 = F_96 ( V_151 ) ;
goto V_160;
}
V_49 = F_99 ( V_150 -> V_154 , false ) ;
if ( V_49 ) {
F_8 ( L_39 ) ;
goto V_161;
}
V_150 -> V_139 = V_151 ;
V_150 -> V_162 = V_24 -> V_26 ;
V_49 = F_85 ( V_24 -> V_28 , V_24 -> V_28 -> V_145 . V_146 ,
V_63 , V_63 + V_143 ,
V_151 ) ;
if ( V_49 ) {
F_8 ( L_40 ) ;
goto V_161;
}
F_100 ( & V_150 -> V_158 , & V_24 -> V_71 -> V_163 ) ;
V_24 -> V_26 = V_151 ;
V_24 -> V_38 = V_63 ;
return 0 ;
V_161:
F_101 ( V_150 -> V_154 ) ;
V_160:
F_102 ( V_150 -> V_154 ) ;
V_157:
F_103 ( V_150 ) ;
return V_49 ;
}
static int F_104 ( struct V_23 * V_24 )
{
bool V_164 ;
int V_49 = 0 ;
if ( V_24 -> V_34 == V_74 ) {
F_8 ( L_41 ) ;
return - V_53 ;
}
V_164 = F_90 ( F_11 ( V_24 , 0 ) ) == 1 ;
if ( V_164 && ( V_24 -> V_34 != V_75 ) ) {
F_8 ( L_42 ) ;
return - V_53 ;
}
V_24 -> V_77 = V_24 -> V_36 ;
F_83 ( V_24 ) ;
if ( V_24 -> V_34 == V_35 ) {
V_24 -> V_78 = V_24 -> V_38 + F_19 ( V_24 ) * sizeof( T_1 ) ;
V_24 -> V_34 = V_75 ;
} else if ( V_164 ) {
V_24 -> V_34 = V_74 ;
V_24 -> V_76 = V_24 -> V_38 + F_19 ( V_24 ) * sizeof( T_1 ) ;
V_24 -> V_43 = V_24 -> V_26 + F_19 ( V_24 ) * sizeof( T_1 ) ;
}
if ( F_88 ( V_24 ) ) {
V_49 = F_91 ( V_24 ) ;
if ( V_49 < 0 )
F_8 ( L_43 ) ;
} else {
V_49 = F_42 ( V_24 ) ;
if ( V_49 < 0 )
return V_49 ;
}
return V_49 ;
}
static void F_105 ( struct V_10 * V_11 , struct V_13 * V_14 )
{
F_106 ( V_11 -> V_165 , & V_14 -> V_166 , V_14 -> V_15 -> V_12 ) ;
}
static void F_107 ( struct V_23 * V_24 ,
T_3 V_167 , T_3 V_168 )
{
T_1 V_169 [ V_170 ] ;
int V_19 ;
T_1 V_57 = F_19 ( V_24 ) ;
if ( F_108 ( V_57 > V_170 ) ) {
F_55 ( L_44 ) ;
V_57 = V_170 ;
}
for ( V_19 = 0 ; V_19 < V_57 ; V_19 ++ )
V_169 [ V_19 ] = F_11 ( V_24 , V_19 ) ;
F_109 ( V_24 -> V_28 -> V_29 , V_24 -> V_2 , V_24 -> V_38 , V_169 ,
V_57 , V_24 -> V_34 == V_35 ,
V_167 , V_168 ) ;
}
static int F_110 ( struct V_23 * V_24 )
{
struct V_9 * V_15 ;
T_1 V_1 ;
int V_49 = 0 ;
T_3 V_171 , V_172 , V_173 ;
struct V_23 V_174 ;
V_171 = F_111 () ;
V_1 = F_11 ( V_24 , 0 ) ;
V_15 = F_5 ( V_24 -> V_28 -> V_11 , V_1 , V_24 -> V_2 ) ;
if ( V_15 == NULL ) {
F_8 ( L_38 ,
V_1 , F_1 ( V_1 , V_24 -> V_2 ) ) ;
return - V_53 ;
}
F_55 ( L_45 , V_15 -> V_20 ) ;
V_24 -> V_15 = V_15 ;
V_172 = F_111 () ;
memcpy ( & V_174 , V_24 , sizeof( struct V_23 ) ) ;
if ( V_15 -> V_175 ) {
V_49 = V_15 -> V_175 ( V_24 ) ;
if ( V_49 < 0 ) {
F_8 ( L_46 , V_15 -> V_20 ) ;
return V_49 ;
}
}
V_173 = F_111 () ;
F_107 ( & V_174 , V_172 - V_171 , V_173 - V_172 ) ;
if ( ! ( V_15 -> V_45 & V_176 ) ) {
V_49 = F_41 ( V_24 ) ;
if ( V_49 ) {
F_8 ( L_47 , V_15 -> V_20 ) ;
return V_49 ;
}
}
return 0 ;
}
static inline bool F_112 ( unsigned long V_63 ,
unsigned long V_177 , unsigned int V_178 )
{
if ( V_178 >= V_177 )
return ( V_63 < V_177 ) || ( V_63 > V_178 ) ;
else
return ( V_63 > V_178 ) && ( V_63 < V_177 ) ;
}
static int F_113 ( struct V_23 * V_24 ,
unsigned long V_179 , unsigned long V_180 ,
unsigned long V_181 , unsigned long V_182 )
{
unsigned long V_177 , V_178 , V_183 ;
int V_49 = 0 ;
V_177 = V_181 + V_179 ;
V_178 = V_181 + V_180 ;
V_183 = V_181 + V_182 ;
F_55 ( L_48 , V_177 , V_178 ) ;
while ( V_24 -> V_38 != V_178 ) {
if ( V_24 -> V_34 == V_35 ) {
if ( ! ( V_24 -> V_38 >= V_181 ) ||
! ( V_24 -> V_38 < V_183 ) ) {
F_8 ( L_49
L_50 ,
V_24 -> V_38 , V_181 ,
V_183 ) ;
F_12 ( V_24 ) ;
return - V_53 ;
}
if ( F_112 ( V_24 -> V_38 , V_177 , V_178 ) ) {
F_8 ( L_51
L_52 ,
V_24 -> V_38 , V_181 ,
V_179 , V_180 ) ;
F_12 ( V_24 ) ;
break;
}
}
V_49 = F_110 ( V_24 ) ;
if ( V_49 ) {
F_8 ( L_53 ) ;
F_12 ( V_24 ) ;
break;
}
}
F_55 ( L_54 ) ;
return V_49 ;
}
static int F_114 ( struct V_184 * V_71 )
{
unsigned long V_177 , V_178 , V_183 ;
struct V_23 V_24 ;
int V_49 = 0 ;
if ( F_14 ( ! F_16 ( V_71 -> V_181 , V_131 ) ) )
return - V_53 ;
V_177 = V_71 -> V_181 + V_71 -> V_179 ;
V_178 = V_71 -> V_181 + V_71 -> V_180 ;
V_183 = V_71 -> V_181 + F_115 ( V_71 -> V_185 ) ;
V_24 . V_34 = V_35 ;
V_24 . V_36 = V_37 ;
V_24 . V_28 = V_71 -> V_28 ;
V_24 . V_2 = V_71 -> V_2 ;
V_24 . V_30 = V_71 -> V_181 ;
V_24 . V_31 = F_115 ( V_71 -> V_185 ) ;
V_24 . V_32 = V_177 ;
V_24 . V_33 = V_178 ;
V_24 . V_42 = V_71 -> V_186 ;
V_24 . V_71 = V_71 ;
if ( ( V_187 & ( 1 << V_71 -> V_2 ) ) ||
V_177 == V_178 )
return 0 ;
V_49 = F_15 ( & V_24 , V_177 ) ;
if ( V_49 )
goto V_188;
V_49 = F_113 ( & V_24 , V_71 -> V_179 , V_71 -> V_180 ,
V_71 -> V_181 , F_115 ( V_71 -> V_185 ) ) ;
V_188:
return V_49 ;
}
static int F_116 ( struct V_189 * V_190 )
{
unsigned long V_177 , V_178 , V_183 , V_31 , V_33 ;
struct V_23 V_24 ;
int V_49 = 0 ;
if ( F_14 ( ! F_16 ( V_190 -> V_191 . V_128 , V_131 ) ) )
return - V_53 ;
V_33 = V_190 -> V_191 . V_192 + 3 * sizeof( T_2 ) ;
V_31 = F_117 ( V_190 -> V_191 . V_192 + V_193 ,
V_156 ) ;
V_177 = V_190 -> V_191 . V_128 ;
V_178 = V_190 -> V_191 . V_128 + V_33 ;
V_183 = V_190 -> V_191 . V_128 + V_31 ;
V_24 . V_34 = V_35 ;
V_24 . V_36 = V_37 ;
V_24 . V_28 = V_190 -> V_71 -> V_28 ;
V_24 . V_2 = V_190 -> V_71 -> V_2 ;
V_24 . V_30 = V_190 -> V_191 . V_128 ;
V_24 . V_31 = V_31 ;
V_24 . V_32 = V_177 ;
V_24 . V_33 = V_178 ;
V_24 . V_42 = V_190 -> V_191 . V_194 ;
V_24 . V_71 = V_190 -> V_71 ;
V_49 = F_15 ( & V_24 , V_177 ) ;
if ( V_49 )
goto V_188;
V_49 = F_113 ( & V_24 , 0 , V_33 ,
V_190 -> V_191 . V_128 , V_31 ) ;
V_188:
return V_49 ;
}
static int F_118 ( struct V_184 * V_71 )
{
struct V_50 * V_28 = V_71 -> V_28 ;
int V_2 = V_71 -> V_2 ;
struct V_195 * V_196 = V_28 -> V_196 ;
struct V_197 * V_198 = V_196 -> V_199 [ V_2 ] . V_198 ;
unsigned long V_177 , V_178 , V_200 , V_201 ;
unsigned int V_140 = 0 ;
int V_49 ;
V_201 = F_115 ( V_71 -> V_185 ) ;
V_71 -> V_182 = ( V_71 -> V_180 + V_201 -
V_71 -> V_179 ) % V_201 ;
V_177 = V_71 -> V_181 + V_71 -> V_179 ;
V_178 = V_71 -> V_181 + V_71 -> V_180 ;
V_200 = V_71 -> V_181 + V_201 ;
V_49 = F_119 ( V_71 -> V_202 , V_71 -> V_182 / 4 ) ;
if ( V_49 )
return V_49 ;
V_71 -> V_186 = V_198 -> V_203 + V_198 -> V_204 ;
if ( V_177 > V_178 ) {
V_49 = F_85 ( V_28 , V_28 -> V_145 . V_146 ,
V_177 , V_200 ,
V_71 -> V_186 ) ;
if ( V_49 ) {
F_8 ( L_40 ) ;
return V_49 ;
}
V_140 = V_200 - V_177 ;
V_177 = V_71 -> V_181 ;
}
V_49 = F_85 ( V_28 , V_28 -> V_145 . V_146 ,
V_177 , V_178 ,
V_71 -> V_186 + V_140 ) ;
if ( V_49 ) {
F_8 ( L_40 ) ;
return V_49 ;
}
V_198 -> V_204 += V_71 -> V_182 ;
F_120 ( V_198 ) ;
return 0 ;
}
int F_121 ( struct V_184 * V_71 )
{
int V_49 ;
V_49 = F_118 ( V_71 ) ;
if ( V_49 ) {
F_8 ( L_55 ) ;
return V_49 ;
}
V_49 = F_114 ( V_71 ) ;
if ( V_49 ) {
F_8 ( L_56 ) ;
return V_49 ;
}
return 0 ;
}
static int F_122 ( struct V_189 * V_190 )
{
struct V_205 * V_206 = & V_190 -> V_71 -> V_28 -> V_11 -> V_58 -> V_155 ;
int V_207 = V_190 -> V_191 . V_192 ;
unsigned long V_128 = V_190 -> V_191 . V_128 ;
struct V_208 * V_154 ;
int V_49 = 0 ;
void * V_209 ;
V_154 = F_93 ( V_206 ,
F_94 ( V_207 + V_193 ,
V_156 ) ) ;
if ( F_95 ( V_154 ) )
return F_96 ( V_154 ) ;
V_209 = F_98 ( V_154 , V_159 ) ;
if ( F_95 ( V_209 ) ) {
F_8 ( L_57 ) ;
V_49 = F_96 ( V_209 ) ;
goto V_160;
}
V_49 = F_99 ( V_154 , false ) ;
if ( V_49 ) {
F_8 ( L_58 ) ;
goto V_161;
}
V_49 = F_85 ( V_190 -> V_71 -> V_28 ,
V_190 -> V_71 -> V_28 -> V_145 . V_146 ,
V_128 , V_128 + V_207 ,
V_209 ) ;
if ( V_49 ) {
F_8 ( L_59 ) ;
goto V_161;
}
V_190 -> V_191 . V_154 = V_154 ;
V_190 -> V_191 . V_194 = V_209 ;
return 0 ;
V_161:
F_101 ( V_154 ) ;
V_160:
F_102 ( V_190 -> V_191 . V_154 ) ;
return V_49 ;
}
static int F_123 ( struct V_189 * V_190 )
{
T_2 V_210 [ V_211 ] = { 0 } ;
unsigned char * V_212 ;
V_210 [ 0 ] = 0x18800001 ;
V_210 [ 1 ] = V_190 -> V_213 . V_128 ;
V_212 = ( unsigned char * ) V_190 -> V_191 . V_194 +
V_190 -> V_191 . V_192 ;
memcpy ( V_212 , V_210 , V_193 ) ;
return 0 ;
}
int F_124 ( struct V_189 * V_190 )
{
int V_49 ;
if ( V_190 -> V_191 . V_192 == 0 )
return 0 ;
V_49 = F_122 ( V_190 ) ;
if ( V_49 ) {
F_8 ( L_60 ) ;
return V_49 ;
}
F_123 ( V_190 ) ;
V_49 = F_116 ( V_190 ) ;
if ( V_49 ) {
F_8 ( L_61 ) ;
return V_49 ;
}
return 0 ;
}
static struct V_9 * F_125 ( struct V_10 * V_11 ,
unsigned int V_12 , int V_16 )
{
struct V_9 * V_15 = NULL ;
unsigned int V_198 ;
F_126 (ring, (unsigned long *)&rings, I915_NUM_ENGINES) {
V_15 = F_3 ( V_11 , V_12 , V_198 ) ;
if ( V_15 )
break;
}
return V_15 ;
}
static int F_127 ( struct V_10 * V_11 )
{
int V_19 ;
struct V_13 * V_14 ;
struct V_9 * V_15 ;
unsigned int V_214 ;
V_214 = F_128 ( V_11 ) ;
for ( V_19 = 0 ; V_19 < F_44 ( V_9 ) ; V_19 ++ ) {
if ( ! ( V_9 [ V_19 ] . V_215 & V_214 ) )
continue;
V_14 = F_129 ( sizeof( * V_14 ) , V_152 ) ;
if ( ! V_14 )
return - V_153 ;
V_14 -> V_15 = & V_9 [ V_19 ] ;
V_15 = F_125 ( V_11 ,
V_14 -> V_15 -> V_12 , V_14 -> V_15 -> V_16 ) ;
if ( V_15 ) {
F_8 ( L_62 , V_14 -> V_15 -> V_20 ,
V_15 -> V_20 ) ;
return - V_216 ;
}
F_130 ( & V_14 -> V_166 ) ;
F_105 ( V_11 , V_14 ) ;
F_55 ( L_63 ,
V_14 -> V_15 -> V_20 , V_14 -> V_15 -> V_12 , V_14 -> V_15 -> V_45 ,
V_14 -> V_15 -> V_215 , V_14 -> V_15 -> V_16 ) ;
}
return 0 ;
}
static void F_131 ( struct V_10 * V_11 )
{
struct V_217 * V_218 ;
struct V_13 * V_14 ;
int V_19 ;
F_132 (gvt->cmd_table, i, tmp, e, hlist)
F_103 ( V_14 ) ;
F_133 ( V_11 -> V_165 ) ;
}
void F_134 ( struct V_10 * V_11 )
{
F_131 ( V_11 ) ;
}
int F_135 ( struct V_10 * V_11 )
{
int V_49 ;
V_49 = F_127 ( V_11 ) ;
if ( V_49 ) {
F_134 ( V_11 ) ;
return V_49 ;
}
return 0 ;
}
