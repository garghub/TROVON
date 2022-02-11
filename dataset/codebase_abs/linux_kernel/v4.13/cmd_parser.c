static inline T_1 F_1 ( T_1 V_1 , int V_2 )
{
struct V_3 * V_4 ;
V_4 = V_5 [ V_2 ] [ F_2 ( V_1 ) ] ;
if ( V_4 == NULL )
return V_6 ;
return V_1 >> ( 32 - V_4 -> V_7 ) ;
}
static inline struct V_8 * F_3 ( struct V_9 * V_10 ,
unsigned int V_11 , int V_2 )
{
struct V_12 * V_13 ;
F_4 (gvt->cmd_table, e, hlist, opcode) {
if ( ( V_11 == V_13 -> V_14 -> V_11 ) &&
( V_13 -> V_14 -> V_15 & ( 1 << V_2 ) ) )
return V_13 -> V_14 ;
}
return NULL ;
}
static inline struct V_8 * F_5 ( struct V_9 * V_10 ,
T_1 V_1 , int V_2 )
{
T_1 V_11 ;
V_11 = F_1 ( V_1 , V_2 ) ;
if ( V_11 == V_6 )
return NULL ;
return F_3 ( V_10 , V_11 , V_2 ) ;
}
static inline T_1 F_6 ( T_1 V_1 , T_1 V_16 , T_1 V_17 )
{
return ( V_1 >> V_17 ) & ( ( 1U << ( V_16 - V_17 + 1 ) ) - 1 ) ;
}
static inline void F_7 ( T_1 V_1 , int V_2 )
{
struct V_3 * V_4 ;
int V_18 ;
V_4 = V_5 [ V_2 ] [ F_2 ( V_1 ) ] ;
if ( V_4 == NULL )
return;
F_8 ( L_1 ,
V_1 >> ( 32 - V_4 -> V_7 ) , V_4 -> V_19 ) ;
for ( V_18 = 0 ; V_18 < V_4 -> V_20 ; V_18 ++ )
F_9 ( L_2 , F_6 ( V_1 , V_4 -> V_21 [ V_18 ] . V_16 ,
V_4 -> V_21 [ V_18 ] . V_17 ) ) ;
F_9 ( L_3 ) ;
}
static inline T_1 * F_10 ( struct V_22 * V_23 , int V_24 )
{
return V_23 -> V_25 + ( V_24 << 2 ) ;
}
static inline T_1 F_11 ( struct V_22 * V_23 , int V_24 )
{
return * F_10 ( V_23 , V_24 ) ;
}
static void F_12 ( struct V_22 * V_23 )
{
int V_26 = 0 ;
int V_18 ;
F_8 ( L_4
L_5 , V_23 -> V_27 -> V_28 ,
V_23 -> V_2 , V_23 -> V_29 , V_23 -> V_29 + V_23 -> V_30 ,
V_23 -> V_31 , V_23 -> V_32 ) ;
F_8 ( L_6 ,
V_23 -> V_33 == V_34 ?
L_7 : L_8 ,
V_23 -> V_35 == V_36 ?
L_9 : L_10 , V_23 -> V_37 ) ;
if ( V_23 -> V_25 == NULL ) {
F_8 ( L_11 ) ;
return;
}
F_8 ( L_12 ,
V_23 -> V_25 , F_11 ( V_23 , 0 ) , F_11 ( V_23 , 1 ) ,
F_11 ( V_23 , 2 ) , F_11 ( V_23 , 3 ) ) ;
F_7 ( F_11 ( V_23 , 0 ) , V_23 -> V_2 ) ;
F_9 ( L_13 ,
V_23 -> V_25 , F_11 ( V_23 , 0 ) , F_11 ( V_23 , 1 ) ,
F_11 ( V_23 , 2 ) , F_11 ( V_23 , 3 ) ) ;
V_23 -> V_25 = ( T_1 * ) ( ( ( ( V_38 ) V_23 -> V_25 ) >> 12 ) << 12 ) ;
while ( V_26 < 1024 ) {
F_9 ( L_14 , V_23 -> V_25 ) ;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ )
F_9 ( L_15 , F_11 ( V_23 , V_18 ) ) ;
F_9 ( L_3 ) ;
V_23 -> V_25 += 8 * sizeof( T_1 ) ;
V_26 += 8 ;
}
}
static inline void F_13 ( struct V_22 * V_23 )
{
unsigned long V_39 = 0 ;
if ( F_14 ( V_23 -> V_31 == V_23 -> V_32 ) )
return;
if ( V_23 -> V_33 == V_34 ) {
unsigned long V_40 = V_23 -> V_29 + V_23 -> V_30 ;
if ( V_23 -> V_31 > V_23 -> V_32 ) {
if ( V_23 -> V_37 >= V_23 -> V_31 && V_23 -> V_37 < V_40 )
V_39 = ( V_23 -> V_37 - V_23 -> V_31 ) ;
else if ( V_23 -> V_37 >= V_23 -> V_29 &&
V_23 -> V_37 <= V_23 -> V_32 )
V_39 = ( V_40 - V_23 -> V_31 ) +
( V_23 -> V_37 - V_23 -> V_29 ) ;
} else
V_39 = ( V_23 -> V_37 - V_23 -> V_31 ) ;
V_23 -> V_25 = V_23 -> V_41 + V_39 ;
} else {
V_23 -> V_25 = V_23 -> V_42 ;
}
}
static inline int F_15 ( struct V_22 * V_23 ,
unsigned long V_37 )
{
F_14 ( ! F_16 ( V_37 , 4 ) ) ;
V_23 -> V_37 = V_37 ;
F_13 ( V_23 ) ;
return 0 ;
}
static inline int F_17 ( struct V_22 * V_23 ,
unsigned int V_43 )
{
V_23 -> V_37 += ( V_43 << 2 ) ;
if ( V_23 -> V_33 == V_34 ) {
if ( V_23 -> V_37 >= V_23 -> V_29 + V_23 -> V_30 )
V_23 -> V_37 -= V_23 -> V_30 ;
F_13 ( V_23 ) ;
} else {
V_23 -> V_25 += ( V_43 << 2 ) ;
}
return 0 ;
}
static inline int F_18 ( struct V_8 * V_14 , T_1 V_1 )
{
if ( ( V_14 -> V_44 & V_45 ) == V_46 )
return V_14 -> V_39 ;
else
return ( V_1 & ( ( 1U << V_14 -> V_39 ) - 1 ) ) + 2 ;
return 0 ;
}
static inline int F_19 ( struct V_22 * V_23 )
{
return F_18 ( V_23 -> V_14 , F_11 ( V_23 , 0 ) ) ;
}
static bool F_20 ( unsigned int V_47 )
{
bool V_48 = false ;
if ( ( V_47 == 0x2168 ) ||
( V_47 == 0x2140 ) ||
( V_47 == 0x211c ) ||
( V_47 == 0x2114 ) ) {
V_48 = true ;
}
return V_48 ;
}
static inline bool F_21 ( unsigned int V_47 )
{
return ( V_47 >= 0x24d0 && V_47 < 0x2500 ) ;
}
static int F_22 ( struct V_22 * V_23 ,
unsigned int V_47 , unsigned int V_24 )
{
struct V_9 * V_10 = V_23 -> V_27 -> V_10 ;
unsigned int V_49 = F_11 ( V_23 , V_24 + 1 ) ;
if ( ! F_23 ( V_10 , V_49 ) ) {
F_24 ( L_16 ,
V_47 , V_49 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_25 ( struct V_22 * V_23 ,
unsigned int V_47 , unsigned int V_24 , char * V_1 )
{
struct V_51 * V_27 = V_23 -> V_27 ;
struct V_9 * V_10 = V_27 -> V_10 ;
if ( V_47 + 4 > V_10 -> V_52 . V_53 ) {
F_26 ( L_17 ,
V_1 , V_47 ) ;
return - V_50 ;
}
if ( ! F_27 ( V_10 , V_47 ) ) {
F_26 ( L_18 ,
V_1 , V_47 ) ;
return 0 ;
}
if ( F_20 ( V_47 ) ) {
F_26 ( L_19 , V_47 ) ;
return 0 ;
}
if ( F_21 ( V_47 ) &&
F_22 ( V_23 , V_47 , V_24 ) )
return - V_50 ;
if ( V_47 == F_28 ( V_54 ) ||
V_47 == F_28 ( V_55 ) ) {
F_29 ( V_23 , F_10 ( V_23 , V_24 ) , V_56 ) ;
}
F_30 ( V_10 , V_47 ) ;
return 0 ;
}
static int F_31 ( struct V_22 * V_23 )
{
int V_18 , V_48 = 0 ;
int V_57 = F_19 ( V_23 ) ;
struct V_9 * V_10 = V_23 -> V_27 -> V_10 ;
for ( V_18 = 1 ; V_18 < V_57 ; V_18 += 2 ) {
if ( F_32 ( V_10 -> V_58 ) &&
( V_23 -> V_2 != V_59 ) ) {
if ( V_23 -> V_2 == V_60 &&
F_33 ( V_23 , V_18 ) ==
F_28 ( V_54 ) )
V_48 |= 0 ;
else
V_48 |= ( F_34 ( V_23 , V_18 ) ) ? - V_50 : 0 ;
}
if ( V_48 )
break;
V_48 |= F_25 ( V_23 , F_33 ( V_23 , V_18 ) , V_18 , L_20 ) ;
}
return V_48 ;
}
static int F_35 ( struct V_22 * V_23 )
{
int V_18 , V_48 = 0 ;
int V_57 = F_19 ( V_23 ) ;
for ( V_18 = 1 ; V_18 < V_57 ; V_18 += 2 ) {
if ( F_32 ( V_23 -> V_27 -> V_10 -> V_58 ) )
V_48 |= ( ( F_34 ( V_23 , V_18 ) ||
( F_34 ( V_23 , V_18 + 1 ) ) ) ) ?
- V_50 : 0 ;
if ( V_48 )
break;
V_48 |= F_25 ( V_23 , F_33 ( V_23 , V_18 ) , V_18 , L_21 ) ;
V_48 |= F_25 ( V_23 , F_33 ( V_23 , V_18 + 1 ) , V_18 , L_22 ) ;
}
return V_48 ;
}
static int F_36 ( struct V_22 * V_23 )
{
struct V_9 * V_10 = V_23 -> V_27 -> V_10 ;
int V_61 = V_10 -> V_52 . V_62 ;
unsigned long V_63 ;
int V_18 , V_48 = 0 ;
int V_57 = F_19 ( V_23 ) ;
for ( V_18 = 1 ; V_18 < V_57 ; ) {
if ( F_32 ( V_10 -> V_58 ) )
V_48 |= ( F_34 ( V_23 , V_18 ) ) ? - V_50 : 0 ;
if ( V_48 )
break;
V_48 |= F_25 ( V_23 , F_33 ( V_23 , V_18 ) , V_18 , L_23 ) ;
if ( F_11 ( V_23 , 0 ) & ( 1 << 22 ) ) {
V_63 = F_37 ( V_23 , V_18 + 1 ) ;
if ( V_61 == 8 )
V_63 |= ( F_38 ( V_23 , V_18 + 2 ) ) << 32 ;
V_48 |= F_39 ( V_23 , V_63 , sizeof( T_1 ) , false ) ;
}
V_18 += F_40 ( V_23 ) + 1 ;
}
return V_48 ;
}
static int F_41 ( struct V_22 * V_23 )
{
int V_61 = V_23 -> V_27 -> V_10 -> V_52 . V_62 ;
unsigned long V_63 ;
int V_18 , V_48 = 0 ;
int V_57 = F_19 ( V_23 ) ;
for ( V_18 = 1 ; V_18 < V_57 ; ) {
V_48 |= F_25 ( V_23 , F_33 ( V_23 , V_18 ) , V_18 , L_24 ) ;
if ( F_11 ( V_23 , 0 ) & ( 1 << 22 ) ) {
V_63 = F_37 ( V_23 , V_18 + 1 ) ;
if ( V_61 == 8 )
V_63 |= ( F_38 ( V_23 , V_18 + 2 ) ) << 32 ;
V_48 |= F_39 ( V_23 , V_63 , sizeof( T_1 ) , false ) ;
}
V_18 += F_40 ( V_23 ) + 1 ;
}
return V_48 ;
}
static int F_42 ( struct V_22 * V_23 )
{
int V_61 = V_23 -> V_27 -> V_10 -> V_52 . V_62 ;
unsigned long V_63 ;
bool V_64 = false ;
unsigned int V_65 ;
int V_48 = 0 ;
V_65 = ( F_11 ( V_23 , 1 ) & V_66 ) >> 14 ;
if ( F_11 ( V_23 , 1 ) & V_67 )
V_48 = F_25 ( V_23 , F_33 ( V_23 , 2 ) , 1 , L_25 ) ;
else if ( V_65 ) {
if ( V_65 == 2 )
V_48 = F_25 ( V_23 , 0x2350 , 1 , L_25 ) ;
else if ( V_65 == 3 )
V_48 = F_25 ( V_23 , 0x2358 , 1 , L_25 ) ;
else if ( V_65 == 1 ) {
if ( ( F_11 ( V_23 , 1 ) & V_68 ) ) {
V_63 = F_11 ( V_23 , 2 ) & F_43 ( 31 , 3 ) ;
if ( V_61 == 8 )
V_63 |= ( F_38 ( V_23 , 3 ) ) << 32 ;
if ( F_11 ( V_23 , 1 ) & ( 1 << 21 ) )
V_64 = true ;
V_48 |= F_39 ( V_23 , V_63 , sizeof( V_38 ) ,
V_64 ) ;
}
}
}
if ( V_48 )
return V_48 ;
if ( F_11 ( V_23 , 1 ) & V_69 )
F_44 ( V_70 [ V_23 -> V_2 ] . V_71 ,
V_23 -> V_72 -> V_73 ) ;
return 0 ;
}
static int F_45 ( struct V_22 * V_23 )
{
F_44 ( V_70 [ V_23 -> V_2 ] . V_74 ,
V_23 -> V_72 -> V_73 ) ;
return 0 ;
}
static int F_46 ( struct V_22 * V_23 )
{
return F_17 ( V_23 , F_19 ( V_23 ) ) ;
}
static int F_47 ( struct V_22 * V_23 )
{
int V_48 ;
if ( V_23 -> V_33 == V_75 ) {
V_23 -> V_33 = V_76 ;
V_48 = F_15 ( V_23 , V_23 -> V_77 ) ;
V_23 -> V_35 = V_23 -> V_78 ;
} else {
V_23 -> V_33 = V_34 ;
V_23 -> V_35 = V_36 ;
if ( V_23 -> V_79 >= V_23 -> V_29 + V_23 -> V_30 )
V_23 -> V_79 -= V_23 -> V_30 ;
V_48 = F_15 ( V_23 , V_23 -> V_79 ) ;
}
return V_48 ;
}
static int F_48 ( struct V_22 * V_23 ,
struct V_80 * V_14 )
{
struct V_81 * V_58 = V_23 -> V_27 -> V_10 -> V_58 ;
struct V_82 V_83 [] = {
[ 0 ] = { V_84 , V_85 , V_86 } ,
[ 1 ] = { V_87 , V_85 , V_88 } ,
[ 2 ] = { V_84 , V_89 , V_90 } ,
[ 3 ] = { V_87 , V_89 , V_91 } ,
[ 4 ] = { V_92 , V_85 , V_93 } ,
[ 5 ] = { V_92 , V_89 , V_94 } ,
} ;
T_1 V_95 , V_96 , V_97 ;
T_1 V_98 ;
V_95 = F_11 ( V_23 , 0 ) ;
V_96 = F_11 ( V_23 , 1 ) ;
V_97 = F_11 ( V_23 , 2 ) ;
V_98 = ( V_95 & F_43 ( 21 , 19 ) ) >> 19 ;
if ( F_14 ( V_98 >= F_49 ( V_83 ) ) )
return - V_50 ;
V_14 -> V_99 = V_83 [ V_98 ] . V_99 ;
V_14 -> V_100 = V_83 [ V_98 ] . V_100 ;
V_14 -> V_101 = V_83 [ V_98 ] . V_101 ;
V_14 -> V_102 = ( V_96 & F_43 ( 15 , 6 ) ) >> 6 ;
V_14 -> V_103 = ( V_96 & 0x1 ) ;
V_14 -> V_104 = ( V_97 & F_43 ( 31 , 12 ) ) >> 12 ;
V_14 -> V_105 = ( ( V_97 & F_43 ( 1 , 0 ) ) == 0x1 ) ;
if ( V_14 -> V_100 == V_85 ) {
V_14 -> V_106 = F_50 ( V_14 -> V_99 ) ;
V_14 -> V_107 = F_51 ( V_14 -> V_99 ) ;
V_14 -> V_108 = F_52 ( V_14 -> V_99 ) ;
} else if ( V_14 -> V_100 == V_89 ) {
V_14 -> V_106 = F_53 ( V_14 -> V_99 ) ;
V_14 -> V_107 = F_54 ( V_14 -> V_99 ) ;
V_14 -> V_108 = F_55 ( V_14 -> V_99 ) ;
} else {
F_14 ( 1 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_56 ( struct V_22 * V_23 ,
struct V_80 * V_14 )
{
struct V_81 * V_58 = V_23 -> V_27 -> V_10 -> V_58 ;
struct V_51 * V_27 = V_23 -> V_27 ;
T_1 V_95 = F_11 ( V_23 , 0 ) ;
T_1 V_96 = F_11 ( V_23 , 1 ) ;
T_1 V_97 = F_11 ( V_23 , 2 ) ;
T_1 V_100 = ( V_95 & F_43 ( 12 , 8 ) ) >> 8 ;
V_14 -> V_100 = V_109 ;
switch ( V_100 ) {
case V_110 :
V_14 -> V_99 = V_84 ;
V_14 -> V_101 = V_86 ;
break;
case V_111 :
V_14 -> V_99 = V_87 ;
V_14 -> V_101 = V_88 ;
break;
case V_112 :
V_14 -> V_99 = V_92 ;
V_14 -> V_101 = V_93 ;
break;
case V_113 :
V_14 -> V_99 = V_84 ;
V_14 -> V_101 = V_90 ;
V_14 -> V_100 = V_114 ;
break;
case V_115 :
V_14 -> V_99 = V_87 ;
V_14 -> V_101 = V_91 ;
V_14 -> V_100 = V_114 ;
break;
case V_116 :
V_14 -> V_99 = V_92 ;
V_14 -> V_101 = V_94 ;
V_14 -> V_100 = V_114 ;
break;
default:
F_26 ( L_26 , V_100 ) ;
return - V_50 ;
}
V_14 -> V_102 = ( V_96 & F_43 ( 15 , 6 ) ) >> 6 ;
V_14 -> V_103 = ( V_96 & F_43 ( 2 , 0 ) ) ;
V_14 -> V_104 = ( V_97 & F_43 ( 31 , 12 ) ) >> 12 ;
V_14 -> V_105 = ( ( V_97 & F_43 ( 1 , 0 ) ) == 0x1 ) ;
V_14 -> V_106 = F_50 ( V_14 -> V_99 ) ;
V_14 -> V_107 = F_51 ( V_14 -> V_99 ) ;
V_14 -> V_108 = F_52 ( V_14 -> V_99 ) ;
return 0 ;
}
static int F_57 ( struct V_22 * V_23 ,
struct V_80 * V_14 )
{
struct V_81 * V_58 = V_23 -> V_27 -> V_10 -> V_58 ;
T_1 V_117 , V_118 ;
if ( ! V_14 -> V_105 )
return 0 ;
if ( F_58 ( V_58 ) || F_59 ( V_58 ) ) {
V_117 = F_60 ( V_23 -> V_27 , V_14 -> V_107 ) & F_43 ( 9 , 0 ) ;
V_118 = ( F_60 ( V_23 -> V_27 , V_14 -> V_106 ) &
F_43 ( 12 , 10 ) ) >> 10 ;
} else {
V_117 = ( F_60 ( V_23 -> V_27 , V_14 -> V_107 ) &
F_43 ( 15 , 6 ) ) >> 6 ;
V_118 = ( F_60 ( V_23 -> V_27 , V_14 -> V_106 ) & ( 1 << 10 ) ) >> 10 ;
}
if ( V_117 != V_14 -> V_102 )
F_8 ( L_27 ) ;
if ( V_118 != V_14 -> V_103 )
F_8 ( L_28 ) ;
return 0 ;
}
static int F_61 (
struct V_22 * V_23 ,
struct V_80 * V_14 )
{
struct V_81 * V_58 = V_23 -> V_27 -> V_10 -> V_58 ;
struct V_51 * V_27 = V_23 -> V_27 ;
F_62 ( & F_60 ( V_27 , V_14 -> V_108 ) , F_43 ( 31 , 12 ) ,
V_14 -> V_104 << 12 ) ;
if ( F_58 ( V_58 ) || F_59 ( V_58 ) ) {
F_62 ( & F_60 ( V_27 , V_14 -> V_107 ) , F_43 ( 9 , 0 ) ,
V_14 -> V_102 ) ;
F_62 ( & F_60 ( V_27 , V_14 -> V_106 ) , F_43 ( 12 , 10 ) ,
V_14 -> V_103 << 10 ) ;
} else {
F_62 ( & F_60 ( V_27 , V_14 -> V_107 ) , F_43 ( 15 , 6 ) ,
V_14 -> V_102 << 6 ) ;
F_62 ( & F_60 ( V_27 , V_14 -> V_106 ) , F_43 ( 10 , 10 ) ,
V_14 -> V_103 << 10 ) ;
}
F_60 ( V_27 , F_63 ( V_14 -> V_99 ) ) ++ ;
F_64 ( V_27 , V_14 -> V_101 ) ;
return 0 ;
}
static int F_65 ( struct V_22 * V_23 ,
struct V_80 * V_14 )
{
struct V_81 * V_58 = V_23 -> V_27 -> V_10 -> V_58 ;
if ( F_32 ( V_58 ) )
return F_48 ( V_23 , V_14 ) ;
if ( F_58 ( V_58 ) || F_59 ( V_58 ) )
return F_56 ( V_23 , V_14 ) ;
return - V_119 ;
}
static int F_66 ( struct V_22 * V_23 ,
struct V_80 * V_14 )
{
struct V_81 * V_58 = V_23 -> V_27 -> V_10 -> V_58 ;
if ( F_32 ( V_58 )
|| F_58 ( V_58 )
|| F_59 ( V_58 ) )
return F_57 ( V_23 , V_14 ) ;
return - V_119 ;
}
static int F_67 (
struct V_22 * V_23 ,
struct V_80 * V_14 )
{
struct V_81 * V_58 = V_23 -> V_27 -> V_10 -> V_58 ;
if ( F_32 ( V_58 )
|| F_58 ( V_58 )
|| F_59 ( V_58 ) )
return F_61 ( V_23 , V_14 ) ;
return - V_119 ;
}
static int F_68 ( struct V_22 * V_23 )
{
struct V_80 V_14 ;
struct V_51 * V_27 = V_23 -> V_27 ;
int V_48 ;
int V_18 ;
int V_39 = F_19 ( V_23 ) ;
V_48 = F_65 ( V_23 , & V_14 ) ;
if ( V_48 ) {
F_26 ( L_29 ) ;
return V_48 ;
}
V_48 = F_66 ( V_23 , & V_14 ) ;
if ( V_48 ) {
F_26 ( L_30 ) ;
return V_48 ;
}
V_48 = F_67 ( V_23 , & V_14 ) ;
if ( V_48 ) {
F_26 ( L_31 ) ;
return V_48 ;
}
for ( V_18 = 0 ; V_18 < V_39 ; V_18 ++ )
F_29 ( V_23 , F_10 ( V_23 , V_18 ) , V_120 ) ;
return 0 ;
}
static bool F_69 ( T_1 V_1 )
{
return V_1 & ( V_121 |
V_122 |
V_123 |
V_124 |
V_125 |
V_126 ) ;
}
static int F_70 ( struct V_22 * V_23 )
{
T_1 V_1 = F_11 ( V_23 , 0 ) ;
if ( ! F_69 ( V_1 ) )
return 0 ;
F_29 ( V_23 , F_10 ( V_23 , 0 ) , V_120 ) ;
return 0 ;
}
static unsigned long F_71 ( struct V_22 * V_23 , int V_24 )
{
unsigned long V_127 ;
unsigned long V_128 , V_129 ;
int V_61 = V_23 -> V_27 -> V_10 -> V_52 . V_62 ;
if ( F_14 ( V_61 != 4 && V_61 != 8 ) )
return V_130 ;
V_129 = F_11 ( V_23 , V_24 ) & V_131 ;
if ( V_61 == 4 ) {
V_127 = V_129 ;
} else {
V_128 = F_11 ( V_23 , V_24 + 1 ) & V_132 ;
V_127 = ( ( ( unsigned long ) V_128 ) << 32 ) | V_129 ;
}
return V_127 ;
}
static inline int F_39 ( struct V_22 * V_23 ,
unsigned long V_133 , int V_134 , bool V_64 )
{
struct V_51 * V_27 = V_23 -> V_27 ;
T_1 V_135 = V_27 -> V_10 -> V_52 . V_135 ;
int V_18 ;
int V_48 ;
if ( V_134 > V_135 ) {
F_26 ( L_32 ,
V_23 -> V_14 -> V_19 ) ;
return - V_50 ;
}
if ( V_64 ) {
if ( V_133 >= V_136 / sizeof( V_38 ) ) {
V_48 = - V_50 ;
goto V_137;
}
} else if ( ( ! F_72 ( V_23 -> V_27 , V_133 ) ) ||
( ! F_72 ( V_23 -> V_27 ,
V_133 + V_134 - 1 ) ) ) {
V_48 = - V_50 ;
goto V_137;
}
return 0 ;
V_137:
F_26 ( L_33 ,
V_23 -> V_14 -> V_19 , V_133 , V_134 ) ;
F_9 ( L_34 ) ;
for ( V_18 = 0 ; V_18 < F_19 ( V_23 ) ; V_18 ++ ) {
if ( ! ( V_18 % 4 ) )
F_9 ( L_35 , F_11 ( V_23 , V_18 ) ) ;
else
F_9 ( L_15 , F_11 ( V_23 , V_18 ) ) ;
}
F_9 ( L_36 ,
V_27 -> V_28 ,
F_73 ( V_27 ) ,
F_74 ( V_27 ) ,
F_75 ( V_27 ) ,
F_76 ( V_27 ) ) ;
return V_48 ;
}
static int F_77 ( struct V_22 * V_23 )
{
int V_61 = V_23 -> V_27 -> V_10 -> V_52 . V_62 ;
int V_134 = ( F_19 ( V_23 ) - 3 ) * sizeof( T_1 ) ;
int V_138 = ( F_11 ( V_23 , 2 ) & ( 1 << 0 ) ) ? 1 : 0 ;
unsigned long V_63 , V_129 , V_128 ;
int V_48 = 0 ;
if ( ! ( F_11 ( V_23 , 0 ) & ( 1 << 22 ) ) )
return 0 ;
V_63 = F_11 ( V_23 , 2 ) & F_43 ( 31 , 2 ) ;
if ( V_61 == 8 ) {
V_129 = F_11 ( V_23 , 1 ) & F_43 ( 31 , 2 ) ;
V_128 = F_11 ( V_23 , 2 ) & F_43 ( 15 , 0 ) ;
V_63 = ( V_128 << 32 ) | V_129 ;
V_138 = ( F_11 ( V_23 , 1 ) & ( 1 << 0 ) ) ? 1 : 0 ;
}
V_48 = F_39 ( V_23 , V_63 + V_134 * V_138 , V_134 , false ) ;
return V_48 ;
}
static inline int F_78 ( struct V_22 * V_23 )
{
struct V_51 * V_27 = V_23 -> V_27 ;
F_26 ( L_37 , V_23 -> V_14 -> V_19 ) ;
return - V_50 ;
}
static int F_79 ( struct V_22 * V_23 )
{
return F_78 ( V_23 ) ;
}
static int F_80 ( struct V_22 * V_23 )
{
return F_78 ( V_23 ) ;
}
static int F_81 ( struct V_22 * V_23 )
{
return F_78 ( V_23 ) ;
}
static int F_82 ( struct V_22 * V_23 )
{
int V_61 = V_23 -> V_27 -> V_10 -> V_52 . V_62 ;
int V_134 = ( 1 << ( ( F_11 ( V_23 , 0 ) & F_43 ( 20 , 19 ) ) >> 19 ) ) *
sizeof( T_1 ) ;
unsigned long V_63 , V_128 ;
int V_48 = 0 ;
if ( ! ( F_11 ( V_23 , 0 ) & ( 1 << 22 ) ) )
return V_48 ;
V_63 = F_11 ( V_23 , 1 ) & F_43 ( 31 , 2 ) ;
if ( V_61 == 8 ) {
V_128 = F_11 ( V_23 , 2 ) & F_43 ( 15 , 0 ) ;
V_63 = ( V_128 << 32 ) | V_63 ;
}
V_48 = F_39 ( V_23 , V_63 , V_134 , false ) ;
return V_48 ;
}
static int F_83 ( struct V_22 * V_23 )
{
return F_78 ( V_23 ) ;
}
static int F_84 ( struct V_22 * V_23 )
{
return F_78 ( V_23 ) ;
}
static int F_85 (
struct V_22 * V_23 )
{
return F_78 ( V_23 ) ;
}
static int F_86 ( struct V_22 * V_23 )
{
return F_78 ( V_23 ) ;
}
static int F_87 ( struct V_22 * V_23 )
{
int V_61 = V_23 -> V_27 -> V_10 -> V_52 . V_62 ;
unsigned long V_63 ;
bool V_64 = false ;
int V_48 = 0 ;
if ( ( ( F_11 ( V_23 , 0 ) >> 14 ) & 0x3 ) && ( F_11 ( V_23 , 1 ) & ( 1 << 2 ) ) ) {
V_63 = F_11 ( V_23 , 1 ) & F_43 ( 31 , 3 ) ;
if ( V_61 == 8 )
V_63 |= ( F_11 ( V_23 , 2 ) & F_43 ( 15 , 0 ) ) << 32 ;
if ( F_11 ( V_23 , 0 ) & ( 1 << 21 ) )
V_64 = true ;
V_48 = F_39 ( V_23 , V_63 , sizeof( V_38 ) , V_64 ) ;
}
if ( ( F_11 ( V_23 , 0 ) & ( 1 << 8 ) ) )
F_44 ( V_70 [ V_23 -> V_2 ] . V_139 ,
V_23 -> V_72 -> V_73 ) ;
return V_48 ;
}
static void F_88 ( struct V_22 * V_23 )
{
if ( ( V_23 -> V_33 == V_34 ) &&
( F_89 ( F_11 ( V_23 , 0 ) ) == 1 ) ) {
V_23 -> V_35 = V_140 ;
}
}
static int F_90 ( struct V_51 * V_27 , struct V_141 * V_142 ,
unsigned long V_63 , unsigned long V_143 , void * V_144 )
{
unsigned long V_145 , V_47 ;
unsigned long V_39 = 0 ;
unsigned long V_146 ;
while ( V_63 != V_143 ) {
V_146 = F_91 ( V_142 , V_63 ) ;
if ( V_146 == V_130 ) {
F_26 ( L_38 , V_63 ) ;
return - V_147 ;
}
V_47 = V_63 & ( V_136 - 1 ) ;
V_145 = ( V_143 - V_63 ) >= ( V_136 - V_47 ) ?
V_136 - V_47 : V_143 - V_63 ;
F_92 ( V_27 , V_146 , V_144 + V_39 , V_145 ) ;
V_39 += V_145 ;
V_63 += V_145 ;
}
return V_39 ;
}
static int F_93 ( struct V_22 * V_23 )
{
struct V_9 * V_10 = V_23 -> V_27 -> V_10 ;
if ( F_32 ( V_10 -> V_58 ) || F_58 ( V_10 -> V_58 )
|| F_59 ( V_10 -> V_58 ) ) {
if ( F_11 ( V_23 , 0 ) & ( 1 << 8 ) )
return 0 ;
}
return 1 ;
}
static T_2 F_94 ( struct V_22 * V_23 )
{
unsigned long V_63 = 0 ;
struct V_8 * V_14 ;
T_2 V_148 = 0 ;
T_2 V_57 = 0 ;
bool V_149 = false ;
struct V_51 * V_27 = V_23 -> V_27 ;
T_1 V_1 ;
V_63 = F_71 ( V_23 , 1 ) ;
V_1 = F_11 ( V_23 , 0 ) ;
V_14 = F_5 ( V_23 -> V_27 -> V_10 , V_1 , V_23 -> V_2 ) ;
if ( V_14 == NULL ) {
F_26 ( L_39 ,
V_1 , F_1 ( V_1 , V_23 -> V_2 ) ) ;
return - V_50 ;
}
do {
F_90 ( V_23 -> V_27 , V_23 -> V_27 -> V_150 . V_151 ,
V_63 , V_63 + 4 , & V_1 ) ;
V_14 = F_5 ( V_23 -> V_27 -> V_10 , V_1 , V_23 -> V_2 ) ;
if ( V_14 == NULL ) {
F_26 ( L_39 ,
V_1 , F_1 ( V_1 , V_23 -> V_2 ) ) ;
return - V_50 ;
}
if ( V_14 -> V_11 == V_152 ) {
V_149 = true ;
} else if ( V_14 -> V_11 == V_153 ) {
if ( F_95 ( V_1 ) == 0 ) {
V_149 = true ;
}
}
V_57 = F_18 ( V_14 , V_1 ) << 2 ;
V_148 += V_57 ;
V_63 += V_57 ;
} while ( ! V_149 );
return V_148 ;
}
static int F_96 ( struct V_22 * V_23 )
{
struct V_154 * V_155 ;
struct V_51 * V_27 = V_23 -> V_27 ;
unsigned long V_63 = 0 ;
T_2 V_148 ;
void * V_156 = NULL ;
int V_48 = 0 ;
V_63 = F_71 ( V_23 , 1 ) ;
V_148 = F_94 ( V_23 ) ;
V_155 = F_97 ( sizeof( * V_155 ) , V_157 ) ;
if ( V_155 == NULL )
return - V_158 ;
V_155 -> V_159 =
F_98 ( V_23 -> V_27 -> V_10 -> V_58 ,
F_99 ( V_148 , V_160 ) ) ;
if ( F_100 ( V_155 -> V_159 ) ) {
V_48 = F_101 ( V_155 -> V_159 ) ;
goto V_161;
}
V_155 -> V_39 = V_148 ;
F_102 ( & V_155 -> V_162 ) ;
V_156 = F_103 ( V_155 -> V_159 , V_163 ) ;
if ( F_100 ( V_156 ) ) {
V_48 = F_101 ( V_156 ) ;
goto V_164;
}
V_48 = F_104 ( V_155 -> V_159 , false ) ;
if ( V_48 ) {
F_26 ( L_40 ) ;
goto V_165;
}
V_155 -> V_144 = V_156 ;
V_155 -> V_166 = V_23 -> V_25 ;
V_48 = F_90 ( V_23 -> V_27 , V_23 -> V_27 -> V_150 . V_151 ,
V_63 , V_63 + V_148 ,
V_156 ) ;
if ( V_48 < 0 ) {
F_26 ( L_41 ) ;
goto V_165;
}
F_105 ( & V_155 -> V_162 , & V_23 -> V_72 -> V_167 ) ;
V_23 -> V_25 = V_156 ;
V_23 -> V_37 = V_63 ;
return 0 ;
V_165:
F_106 ( V_155 -> V_159 ) ;
V_164:
F_107 ( V_155 -> V_159 ) ;
V_161:
F_108 ( V_155 ) ;
return V_48 ;
}
static int F_109 ( struct V_22 * V_23 )
{
bool V_168 ;
int V_48 = 0 ;
struct V_51 * V_27 = V_23 -> V_27 ;
if ( V_23 -> V_33 == V_75 ) {
F_26 ( L_42 ) ;
return - V_50 ;
}
V_168 = F_95 ( F_11 ( V_23 , 0 ) ) == 1 ;
if ( V_168 && ( V_23 -> V_33 != V_76 ) ) {
F_26 ( L_43 ) ;
return - V_50 ;
}
V_23 -> V_78 = V_23 -> V_35 ;
F_88 ( V_23 ) ;
if ( V_23 -> V_33 == V_34 ) {
V_23 -> V_79 = V_23 -> V_37 + F_19 ( V_23 ) * sizeof( T_1 ) ;
V_23 -> V_33 = V_76 ;
} else if ( V_168 ) {
V_23 -> V_33 = V_75 ;
V_23 -> V_77 = V_23 -> V_37 + F_19 ( V_23 ) * sizeof( T_1 ) ;
V_23 -> V_42 = V_23 -> V_25 + F_19 ( V_23 ) * sizeof( T_1 ) ;
}
if ( F_93 ( V_23 ) ) {
V_48 = F_96 ( V_23 ) ;
if ( V_48 < 0 )
F_26 ( L_44 ) ;
} else {
V_48 = F_47 ( V_23 ) ;
if ( V_48 < 0 )
return V_48 ;
}
return V_48 ;
}
static void F_110 ( struct V_9 * V_10 , struct V_12 * V_13 )
{
F_111 ( V_10 -> V_169 , & V_13 -> V_170 , V_13 -> V_14 -> V_11 ) ;
}
static int F_112 ( struct V_22 * V_23 )
{
struct V_51 * V_27 = V_23 -> V_27 ;
struct V_8 * V_14 ;
T_1 V_1 ;
int V_48 = 0 ;
V_1 = F_11 ( V_23 , 0 ) ;
V_14 = F_5 ( V_23 -> V_27 -> V_10 , V_1 , V_23 -> V_2 ) ;
if ( V_14 == NULL ) {
F_26 ( L_39 ,
V_1 , F_1 ( V_1 , V_23 -> V_2 ) ) ;
return - V_50 ;
}
V_23 -> V_14 = V_14 ;
F_113 ( V_27 -> V_28 , V_23 -> V_2 , V_23 -> V_37 , V_23 -> V_25 ,
F_19 ( V_23 ) , V_23 -> V_33 ) ;
if ( V_14 -> V_171 ) {
V_48 = V_14 -> V_171 ( V_23 ) ;
if ( V_48 < 0 ) {
F_26 ( L_45 , V_14 -> V_19 ) ;
return V_48 ;
}
}
if ( ! ( V_14 -> V_44 & V_172 ) ) {
V_48 = F_46 ( V_23 ) ;
if ( V_48 ) {
F_26 ( L_46 , V_14 -> V_19 ) ;
return V_48 ;
}
}
return 0 ;
}
static inline bool F_114 ( unsigned long V_63 ,
unsigned long V_173 , unsigned int V_174 )
{
if ( V_174 >= V_173 )
return ( V_63 < V_173 ) || ( V_63 > V_174 ) ;
else
return ( V_63 > V_174 ) && ( V_63 < V_173 ) ;
}
static int F_115 ( struct V_22 * V_23 ,
unsigned long V_175 , unsigned long V_176 ,
unsigned long V_177 , unsigned long V_178 )
{
unsigned long V_173 , V_174 , V_179 ;
int V_48 = 0 ;
struct V_51 * V_27 = V_23 -> V_27 ;
V_173 = V_177 + V_175 ;
V_174 = V_177 + V_176 ;
V_179 = V_177 + V_178 ;
while ( V_23 -> V_37 != V_174 ) {
if ( V_23 -> V_33 == V_34 ) {
if ( ! ( V_23 -> V_37 >= V_177 ) ||
! ( V_23 -> V_37 < V_179 ) ) {
F_26 ( L_47
L_48 ,
V_23 -> V_37 , V_177 ,
V_179 ) ;
F_12 ( V_23 ) ;
return - V_50 ;
}
if ( F_114 ( V_23 -> V_37 , V_173 , V_174 ) ) {
F_26 ( L_49
L_50 ,
V_23 -> V_37 , V_177 ,
V_175 , V_176 ) ;
F_12 ( V_23 ) ;
break;
}
}
V_48 = F_112 ( V_23 ) ;
if ( V_48 ) {
F_26 ( L_51 ) ;
F_12 ( V_23 ) ;
break;
}
}
return V_48 ;
}
static int F_116 ( struct V_180 * V_72 )
{
unsigned long V_173 , V_174 , V_179 ;
struct V_22 V_23 ;
int V_48 = 0 ;
if ( F_14 ( ! F_16 ( V_72 -> V_177 , V_136 ) ) )
return - V_50 ;
V_173 = V_72 -> V_177 + V_72 -> V_175 ;
V_174 = V_72 -> V_177 + V_72 -> V_176 ;
V_179 = V_72 -> V_177 + F_117 ( V_72 -> V_181 ) ;
V_23 . V_33 = V_34 ;
V_23 . V_35 = V_36 ;
V_23 . V_27 = V_72 -> V_27 ;
V_23 . V_2 = V_72 -> V_2 ;
V_23 . V_29 = V_72 -> V_177 ;
V_23 . V_30 = F_117 ( V_72 -> V_181 ) ;
V_23 . V_31 = V_173 ;
V_23 . V_32 = V_174 ;
V_23 . V_41 = V_72 -> V_182 ;
V_23 . V_72 = V_72 ;
if ( ( V_183 & ( 1 << V_72 -> V_2 ) ) ||
V_173 == V_174 )
return 0 ;
if ( ! F_118 ( V_23 . V_27 , V_23 . V_29 , V_23 . V_30 ) ) {
V_48 = - V_50 ;
goto V_184;
}
V_48 = F_15 ( & V_23 , V_173 ) ;
if ( V_48 )
goto V_184;
V_48 = F_115 ( & V_23 , V_72 -> V_175 , V_72 -> V_176 ,
V_72 -> V_177 , F_117 ( V_72 -> V_181 ) ) ;
V_184:
return V_48 ;
}
static int F_119 ( struct V_185 * V_186 )
{
unsigned long V_173 , V_174 , V_179 , V_30 , V_32 ;
struct V_22 V_23 ;
int V_48 = 0 ;
struct V_180 * V_72 = F_120 ( V_186 ,
struct V_180 ,
V_186 ) ;
if ( F_14 ( ! F_16 ( V_186 -> V_187 . V_133 , V_136 ) ) )
return - V_50 ;
V_32 = V_186 -> V_187 . V_188 + 3 * sizeof( T_2 ) ;
V_30 = F_121 ( V_186 -> V_187 . V_188 + V_189 ,
V_160 ) ;
V_173 = V_186 -> V_187 . V_133 ;
V_174 = V_186 -> V_187 . V_133 + V_32 ;
V_179 = V_186 -> V_187 . V_133 + V_30 ;
V_23 . V_33 = V_34 ;
V_23 . V_35 = V_36 ;
V_23 . V_27 = V_72 -> V_27 ;
V_23 . V_2 = V_72 -> V_2 ;
V_23 . V_29 = V_186 -> V_187 . V_133 ;
V_23 . V_30 = V_30 ;
V_23 . V_31 = V_173 ;
V_23 . V_32 = V_174 ;
V_23 . V_41 = V_186 -> V_187 . V_190 ;
V_23 . V_72 = V_72 ;
if ( ! F_118 ( V_23 . V_27 , V_23 . V_29 , V_23 . V_30 ) ) {
V_48 = - V_50 ;
goto V_184;
}
V_48 = F_15 ( & V_23 , V_173 ) ;
if ( V_48 )
goto V_184;
V_48 = F_115 ( & V_23 , 0 , V_32 ,
V_186 -> V_187 . V_133 , V_30 ) ;
V_184:
return V_48 ;
}
static int F_122 ( struct V_180 * V_72 )
{
struct V_51 * V_27 = V_72 -> V_27 ;
unsigned long V_173 , V_174 , V_191 , V_192 ;
T_1 * V_193 ;
int V_48 ;
V_192 = F_117 ( V_72 -> V_181 ) ;
V_72 -> V_178 = ( V_72 -> V_176 + V_192 -
V_72 -> V_175 ) % V_192 ;
V_173 = V_72 -> V_177 + V_72 -> V_175 ;
V_174 = V_72 -> V_177 + V_72 -> V_176 ;
V_191 = V_72 -> V_177 + V_192 ;
V_193 = F_123 ( V_72 -> V_194 , V_72 -> V_178 / sizeof( T_1 ) ) ;
if ( F_100 ( V_193 ) )
return F_101 ( V_193 ) ;
V_72 -> V_182 = V_193 ;
if ( V_173 > V_174 ) {
V_48 = F_90 ( V_27 , V_27 -> V_150 . V_151 ,
V_173 , V_191 , V_193 ) ;
if ( V_48 < 0 ) {
F_26 ( L_41 ) ;
return V_48 ;
}
V_193 += V_48 / sizeof( T_1 ) ;
V_173 = V_72 -> V_177 ;
}
V_48 = F_90 ( V_27 , V_27 -> V_150 . V_151 , V_173 , V_174 , V_193 ) ;
if ( V_48 < 0 ) {
F_26 ( L_41 ) ;
return V_48 ;
}
V_193 += V_48 / sizeof( T_1 ) ;
F_124 ( V_72 -> V_194 , V_193 ) ;
return 0 ;
}
int F_125 ( struct V_180 * V_72 )
{
int V_48 ;
struct V_51 * V_27 = V_72 -> V_27 ;
V_48 = F_122 ( V_72 ) ;
if ( V_48 ) {
F_26 ( L_52 ) ;
return V_48 ;
}
V_48 = F_116 ( V_72 ) ;
if ( V_48 ) {
F_26 ( L_53 ) ;
return V_48 ;
}
return 0 ;
}
static int F_126 ( struct V_185 * V_186 )
{
int V_195 = V_186 -> V_187 . V_188 ;
unsigned long V_133 = V_186 -> V_187 . V_133 ;
struct V_180 * V_72 = F_120 ( V_186 ,
struct V_180 ,
V_186 ) ;
struct V_51 * V_27 = V_72 -> V_27 ;
struct V_196 * V_159 ;
int V_48 = 0 ;
void * V_197 ;
V_159 = F_98 ( V_72 -> V_27 -> V_10 -> V_58 ,
F_99 ( V_195 + V_189 ,
V_160 ) ) ;
if ( F_100 ( V_159 ) )
return F_101 ( V_159 ) ;
V_197 = F_103 ( V_159 , V_163 ) ;
if ( F_100 ( V_197 ) ) {
F_26 ( L_54 ) ;
V_48 = F_101 ( V_197 ) ;
goto V_164;
}
V_48 = F_104 ( V_159 , false ) ;
if ( V_48 ) {
F_26 ( L_55 ) ;
goto V_165;
}
V_48 = F_90 ( V_72 -> V_27 ,
V_72 -> V_27 -> V_150 . V_151 ,
V_133 , V_133 + V_195 ,
V_197 ) ;
if ( V_48 < 0 ) {
F_26 ( L_56 ) ;
goto V_165;
}
V_186 -> V_187 . V_159 = V_159 ;
V_186 -> V_187 . V_190 = V_197 ;
return 0 ;
V_165:
F_106 ( V_159 ) ;
V_164:
F_107 ( V_159 ) ;
return V_48 ;
}
static int F_127 ( struct V_185 * V_186 )
{
T_2 V_198 [ V_199 ] = { 0 } ;
unsigned char * V_200 ;
V_198 [ 0 ] = 0x18800001 ;
V_198 [ 1 ] = V_186 -> V_201 . V_133 ;
V_200 = ( unsigned char * ) V_186 -> V_187 . V_190 +
V_186 -> V_187 . V_188 ;
memcpy ( V_200 , V_198 , V_189 ) ;
return 0 ;
}
int F_128 ( struct V_185 * V_186 )
{
int V_48 ;
struct V_180 * V_72 = F_120 ( V_186 ,
struct V_180 ,
V_186 ) ;
struct V_51 * V_27 = V_72 -> V_27 ;
if ( V_186 -> V_187 . V_188 == 0 )
return 0 ;
V_48 = F_126 ( V_186 ) ;
if ( V_48 ) {
F_26 ( L_57 ) ;
return V_48 ;
}
F_127 ( V_186 ) ;
V_48 = F_119 ( V_186 ) ;
if ( V_48 ) {
F_26 ( L_58 ) ;
return V_48 ;
}
return 0 ;
}
static struct V_8 * F_129 ( struct V_9 * V_10 ,
unsigned int V_11 , int V_15 )
{
struct V_8 * V_14 = NULL ;
unsigned int V_202 ;
F_130 (ring, (unsigned long *)&rings, I915_NUM_ENGINES) {
V_14 = F_3 ( V_10 , V_11 , V_202 ) ;
if ( V_14 )
break;
}
return V_14 ;
}
static int F_131 ( struct V_9 * V_10 )
{
int V_18 ;
struct V_12 * V_13 ;
struct V_8 * V_14 ;
unsigned int V_203 ;
V_203 = F_132 ( V_10 ) ;
for ( V_18 = 0 ; V_18 < F_49 ( V_8 ) ; V_18 ++ ) {
if ( ! ( V_8 [ V_18 ] . V_204 & V_203 ) )
continue;
V_13 = F_133 ( sizeof( * V_13 ) , V_157 ) ;
if ( ! V_13 )
return - V_158 ;
V_13 -> V_14 = & V_8 [ V_18 ] ;
V_14 = F_129 ( V_10 ,
V_13 -> V_14 -> V_11 , V_13 -> V_14 -> V_15 ) ;
if ( V_14 ) {
F_24 ( L_59 , V_13 -> V_14 -> V_19 ,
V_14 -> V_19 ) ;
return - V_205 ;
}
F_134 ( & V_13 -> V_170 ) ;
F_110 ( V_10 , V_13 ) ;
F_8 ( L_60 ,
V_13 -> V_14 -> V_19 , V_13 -> V_14 -> V_11 , V_13 -> V_14 -> V_44 ,
V_13 -> V_14 -> V_204 , V_13 -> V_14 -> V_15 ) ;
}
return 0 ;
}
static void F_135 ( struct V_9 * V_10 )
{
struct V_206 * V_207 ;
struct V_12 * V_13 ;
int V_18 ;
F_136 (gvt->cmd_table, i, tmp, e, hlist)
F_108 ( V_13 ) ;
F_137 ( V_10 -> V_169 ) ;
}
void F_138 ( struct V_9 * V_10 )
{
F_135 ( V_10 ) ;
}
int F_139 ( struct V_9 * V_10 )
{
int V_48 ;
V_48 = F_131 ( V_10 ) ;
if ( V_48 ) {
F_138 ( V_10 ) ;
return V_48 ;
}
return 0 ;
}
