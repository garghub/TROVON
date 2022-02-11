static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
* V_4 = F_2 ( ( void V_5 * ) ( V_2 -> V_6 + V_3 ) ) ;
F_3 ( L_1 , V_3 , * V_4 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_5 ( V_4 , ( void V_5 * ) ( V_2 -> V_6 + V_3 ) ) ;
F_3 ( L_2 , V_3 , V_4 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 )
{
* V_4 = F_7 ( ( void V_5 * ) ( V_2 -> V_6 + V_3 ) ) ;
F_3 ( L_3 , V_3 , * V_4 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_3 , T_3 * V_4 )
{
* V_4 = F_9 ( ( void V_5 * ) ( V_2 -> V_6 + V_3 ) ) ;
F_3 ( L_4 , V_3 , * V_4 ) ;
}
static inline void F_10 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_11 ( V_4 , ( void V_5 * ) ( V_2 -> V_6 + V_3 ) ) ;
F_3 ( L_5 , V_3 , V_4 ) ;
}
static inline void F_12 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_4 )
{
F_13 ( V_4 , ( void V_5 * ) ( V_2 -> V_6 + V_3 ) ) ;
F_3 ( L_6 , V_3 , V_4 ) ;
}
static inline void F_14 ( struct V_1 * V_2 , T_1 V_7 , T_1 * V_4 )
{
F_4 ( V_2 , V_8 ,
V_7 & V_9 ) ;
F_1 ( V_2 , V_10 , V_4 ) ;
}
static inline void F_15 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_4 )
{
F_4 ( V_2 , V_8 ,
V_7 & V_9 ) ;
F_4 ( V_2 , V_10 , V_4 ) ;
}
static inline void F_16 ( struct V_1 * V_2 , T_1 V_7 , T_2 * V_4 )
{
F_4 ( V_2 , V_8 ,
V_7 & V_9 ) ;
F_6 ( V_2 , V_10 , V_4 ) ;
}
static inline void F_17 ( struct V_1 * V_2 , T_1 V_7 , T_2 V_4 )
{
F_4 ( V_2 , V_8 ,
V_7 & V_9 ) ;
F_10 ( V_2 , V_10 , V_4 ) ;
}
static inline void F_18 ( struct V_1 * V_2 , T_1 V_7 , T_3 * V_4 )
{
F_4 ( V_2 , V_8 ,
V_7 & V_9 ) ;
F_8 ( V_2 , V_10 , V_4 ) ;
}
static inline void F_19 ( struct V_1 * V_2 , T_1 V_7 , T_3 V_4 )
{
F_4 ( V_2 , V_8 ,
V_7 & V_9 ) ;
F_12 ( V_2 , V_10 , V_4 ) ;
}
static inline void F_20 ( struct V_1 * V_2 , T_1 V_7 )
{
F_4 ( V_2 , V_11 ,
V_7 & V_9 ) ;
}
static inline void F_21 ( struct V_1 * V_2 , T_1 V_4 )
{
F_4 ( V_2 , V_12 , V_4 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_13 ,
const T_3 * V_14 )
{
T_1 V_15 ;
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
V_15 = V_7 & ( ~ 0x3 ) ;
V_17 = V_7 - V_15 ;
if ( V_17 ) {
F_4 ( V_2 , V_8 ,
V_15 ) ;
for ( V_18 = V_17 ; V_18 < 4 ; V_18 ++ , V_14 ++ )
F_12 ( V_2 ,
V_10 + V_18 ,
* V_14 ) ;
V_13 -= V_17 ;
V_15 += 4 ;
}
F_4 ( V_2 , V_11 , V_15 ) ;
V_16 = V_13 & ( ~ 0x3 ) ;
for ( V_18 = 0 ; V_18 < V_16 ; V_18 += 4 , V_14 += 4 , V_15 += 4 )
F_4 ( V_2 , V_12 , * ( T_1 * ) V_14 ) ;
V_17 = V_13 - V_16 ;
F_4 ( V_2 , V_8 , V_15 ) ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ , V_14 ++ )
F_12 ( V_2 , V_10 + V_18 ,
* V_14 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_13 ,
T_3 * V_14 )
{
T_1 V_15 ;
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
V_15 = V_7 & ( ~ 0x3 ) ;
V_17 = V_7 - V_15 ;
if ( V_17 ) {
F_4 ( V_2 , V_8 ,
V_15 ) ;
for ( V_18 = V_17 ; V_18 < 4 ; V_18 ++ , V_14 ++ )
F_8 ( V_2 ,
V_10 + V_18 ,
V_14 ) ;
V_13 -= V_17 ;
V_15 += 4 ;
}
F_4 ( V_2 , V_11 , V_15 ) ;
V_16 = V_13 & ( ~ 0x3 ) ;
for ( V_18 = 0 ; V_18 < V_16 ; V_18 += 4 , V_14 += 4 , V_15 += 4 )
F_1 ( V_2 , V_12 , ( T_1 * ) V_14 ) ;
V_17 = V_13 - V_16 ;
F_4 ( V_2 , V_8 , V_15 ) ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ , V_14 ++ )
F_8 ( V_2 , V_10 + V_18 , V_14 ) ;
}
static inline int F_24 ( struct V_1 * V_2 )
{
return ( V_2 -> V_6 &&
( F_2
( ( void V_5 * ) ( V_2 -> V_6 +
V_19 ) )
== V_20 ) ) ;
}
static int F_25 ( struct V_21 * V_22 , T_1 V_23 ,
void * V_4 , T_1 * V_13 )
{
struct V_24 * V_25 = & V_22 -> V_25 ;
T_1 V_7 ;
T_1 V_26 ;
T_2 V_27 ;
T_2 V_28 ;
T_1 V_29 ;
if ( V_25 -> V_30 == 0 ) {
F_26 (KERN_WARNING DRV_NAME L_7
L_8 ) ;
return - V_31 ;
}
if ( F_27 ( V_25 , V_23 ) ) {
if ( * V_13 < V_32 ) {
* V_13 = V_32 ;
F_26 (KERN_WARNING DRV_NAME
L_9 ,
IPW_ORD_TAB_1_ENTRY_SIZE) ;
return - V_31 ;
}
F_14 ( V_22 -> V_33 ,
V_25 -> V_30 + ( V_23 << 2 ) , & V_7 ) ;
F_14 ( V_22 -> V_33 , V_7 , V_4 ) ;
* V_13 = V_32 ;
return 0 ;
}
if ( F_28 ( V_25 , V_23 ) ) {
V_23 -= V_34 ;
F_14 ( V_22 -> V_33 ,
V_25 -> V_35 + ( V_23 << 3 ) , & V_7 ) ;
F_14 ( V_22 -> V_33 ,
V_25 -> V_35 + ( V_23 << 3 ) + sizeof( T_1 ) ,
& V_26 ) ;
V_27 = * ( ( T_2 * ) & V_26 ) ;
V_28 = * ( ( ( T_2 * ) & V_26 ) + 1 ) ;
V_29 = V_27 * V_28 ;
if ( V_29 > * V_13 ) {
* V_13 = V_29 ;
return - V_31 ;
}
* V_13 = V_29 ;
if ( ! V_29 )
return 0 ;
F_23 ( V_22 -> V_33 , V_7 , V_29 , V_4 ) ;
return 0 ;
}
F_26 (KERN_WARNING DRV_NAME L_10
L_11 , ord) ;
return - V_31 ;
}
static int F_29 ( struct V_21 * V_22 , T_1 V_23 , T_1 * V_4 ,
T_1 * V_13 )
{
struct V_24 * V_25 = & V_22 -> V_25 ;
T_1 V_7 ;
if ( F_27 ( V_25 , V_23 ) ) {
if ( * V_13 != V_32 ) {
* V_13 = V_32 ;
F_30 ( L_12 ) ;
return - V_31 ;
}
F_14 ( V_22 -> V_33 ,
V_25 -> V_30 + ( V_23 << 2 ) , & V_7 ) ;
F_15 ( V_22 -> V_33 , V_7 , * V_4 ) ;
* V_13 = V_32 ;
return 0 ;
}
F_30 ( L_13 ) ;
if ( F_28 ( V_25 , V_23 ) )
return - V_31 ;
return - V_31 ;
}
static char * F_31 ( char * V_14 , T_4 V_36 ,
const T_3 * V_37 , T_1 V_13 , T_1 V_38 )
{
int V_39 , V_18 , V_40 , V_41 ;
char V_42 ;
V_39 = snprintf ( V_14 , V_36 , L_14 , V_38 ) ;
for ( V_41 = 0 , V_18 = 0 ; V_18 < 2 ; V_18 ++ ) {
V_39 += snprintf ( V_14 + V_39 , V_36 - V_39 , L_15 ) ;
for ( V_40 = 0 ; V_40 < 8 && V_41 < V_13 ; V_40 ++ , V_41 ++ )
V_39 += snprintf ( V_14 + V_39 , V_36 - V_39 , L_16 ,
V_37 [ ( V_18 * 8 + V_40 ) ] ) ;
for (; V_40 < 8 ; V_40 ++ )
V_39 += snprintf ( V_14 + V_39 , V_36 - V_39 , L_17 ) ;
}
V_39 += snprintf ( V_14 + V_39 , V_36 - V_39 , L_15 ) ;
for ( V_41 = 0 , V_18 = 0 ; V_18 < 2 ; V_18 ++ ) {
V_39 += snprintf ( V_14 + V_39 , V_36 - V_39 , L_15 ) ;
for ( V_40 = 0 ; V_40 < 8 && V_41 < V_13 ; V_40 ++ , V_41 ++ ) {
V_42 = V_37 [ ( V_18 * 8 + V_40 ) ] ;
if ( ! isascii ( V_42 ) || ! isprint ( V_42 ) )
V_42 = '.' ;
V_39 += snprintf ( V_14 + V_39 , V_36 - V_39 , L_18 , V_42 ) ;
}
for (; V_40 < 8 ; V_40 ++ )
V_39 += snprintf ( V_14 + V_39 , V_36 - V_39 , L_15 ) ;
}
return V_14 ;
}
static void F_32 ( int V_43 , const T_3 * V_37 , T_1 V_13 )
{
char line [ 81 ] ;
T_1 V_38 = 0 ;
if ( ! ( V_44 & V_43 ) )
return;
while ( V_13 ) {
F_26 ( V_45 L_19 ,
F_31 ( line , sizeof( line ) , & V_37 [ V_38 ] ,
F_33 ( V_13 , 16U ) , V_38 ) ) ;
V_38 += 16 ;
V_13 -= F_33 ( V_13 , 16U ) ;
}
}
static void F_34 ( struct V_21 * V_22 )
{
unsigned long V_46 = F_35 () ;
if ( V_22 -> V_47 &&
( V_46 - V_22 -> V_48 > V_22 -> V_47 ) )
V_22 -> V_47 = 0 ;
V_22 -> V_48 = F_35 () ;
if ( ! ( V_22 -> V_49 & V_50 ) ) {
F_30 ( L_20 ,
V_22 -> V_33 -> V_51 , V_22 -> V_47 ) ;
F_36 ( V_22 -> V_33 ) ;
F_37 ( V_22 -> V_33 ) ;
V_22 -> V_49 |= V_50 ;
if ( V_22 -> V_47 )
F_38 ( & V_22 -> V_52 ,
V_22 -> V_47 * V_53 ) ;
else
F_38 ( & V_22 -> V_52 , 0 ) ;
if ( V_22 -> V_47 < V_54 )
V_22 -> V_47 ++ ;
F_39 ( & V_22 -> V_55 ) ;
} else
F_30 ( L_21 ,
V_22 -> V_33 -> V_51 ) ;
}
static int F_40 ( struct V_21 * V_22 ,
struct V_56 * V_57 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
unsigned long V_62 ;
int V_63 = 0 ;
F_41 ( L_22 ,
V_64 [ V_57 -> V_56 ] , V_57 -> V_56 ,
V_57 -> V_65 ) ;
F_32 ( V_66 , ( T_3 * ) V_57 -> V_67 ,
V_57 -> V_65 ) ;
F_42 ( & V_22 -> V_68 , V_62 ) ;
if ( V_22 -> V_69 ) {
F_30
( L_23 ) ;
V_63 = - V_70 ;
goto V_71;
}
if ( ! ( V_22 -> V_49 & V_72 ) ) {
F_30
( L_24 ) ;
V_63 = - V_70 ;
goto V_71;
}
if ( V_22 -> V_49 & V_73 ) {
F_30
( L_25 ) ;
V_63 = - V_74 ;
goto V_71;
}
if ( F_43 ( & V_22 -> V_75 ) ) {
F_30 ( L_26 ) ;
goto V_71;
}
V_22 -> V_49 |= V_73 ;
V_22 -> V_76 ++ ;
V_59 = V_22 -> V_75 . V_77 ;
V_61 = F_44 ( V_59 , struct V_60 , V_78 ) ;
V_61 -> V_79 = V_80 ;
V_61 -> V_81 . V_82 . V_57 -> V_83 = V_57 -> V_56 ;
V_61 -> V_81 . V_82 . V_57 -> V_84 = V_57 -> V_85 ;
V_61 -> V_81 . V_82 . V_57 -> V_86 =
V_57 -> V_65 ;
V_61 -> V_81 . V_82 . V_57 -> V_87 = V_57 -> V_88 ;
memcpy ( V_61 -> V_81 . V_82 . V_57 -> V_89 ,
V_57 -> V_67 ,
sizeof( V_61 -> V_81 . V_82 . V_57 -> V_89 ) ) ;
F_45 ( V_59 ) ;
F_46 ( & V_22 -> V_90 ) ;
F_47 ( V_59 , & V_22 -> V_91 ) ;
F_48 ( & V_22 -> V_92 ) ;
F_49 ( V_22 ) ;
F_50 ( V_22 ) ;
F_51 ( & V_22 -> V_68 , V_62 ) ;
V_63 =
F_52 ( V_22 -> V_55 ,
! ( V_22 ->
V_49 & V_73 ) ,
V_93 ) ;
if ( V_63 == 0 ) {
F_30 ( L_27 ,
1000 * ( V_93 / V_53 ) ) ;
V_22 -> V_69 = V_94 ;
V_22 -> V_49 &= ~ V_73 ;
F_34 ( V_22 ) ;
return - V_70 ;
}
if ( V_22 -> V_69 ) {
F_26 (KERN_WARNING DRV_NAME L_28 ,
priv->net_dev->name) ;
return - V_70 ;
}
F_53 ( F_54 ( 10 ) ) ;
return 0 ;
V_71:
F_51 ( & V_22 -> V_68 , V_62 ) ;
return V_63 ;
}
static int F_55 ( struct V_21 * V_22 )
{
T_1 V_95 , V_96 ;
T_1 V_97 ;
T_1 V_98 = 0x76543210 ;
T_1 V_99 = 0xFEDCBA98 ;
for ( V_97 = V_19 ;
V_97 < V_100 ; V_97 += sizeof( T_1 ) ) {
F_1 ( V_22 -> V_33 , V_97 , & V_95 ) ;
if ( V_95 != V_20 )
return - V_70 ;
}
for ( V_97 = 0 ; V_97 < 5 ; V_97 ++ ) {
F_4 ( V_22 -> V_33 , V_101 + 0x32 ,
V_98 ) ;
F_4 ( V_22 -> V_33 , V_101 + 0x36 ,
V_99 ) ;
F_1 ( V_22 -> V_33 , V_101 + 0x32 ,
& V_95 ) ;
F_1 ( V_22 -> V_33 , V_101 + 0x36 ,
& V_96 ) ;
if ( V_98 == V_95 && V_99 == V_96 )
return 0 ;
}
return - V_70 ;
}
static int F_56 ( struct V_21 * V_22 , int V_102 )
{
int V_18 ;
T_1 V_103 ;
T_1 V_13 = sizeof( V_103 ) ;
int V_63 ;
for ( V_18 = 0 ; V_18 <= V_104 * 1000 ; V_18 += 50 ) {
V_63 = F_25 ( V_22 , V_105 ,
& V_103 , & V_13 ) ;
if ( V_63 ) {
F_30 ( L_29
L_30 ) ;
return 0 ;
}
if ( ( V_103 == V_102 ) ||
( ( V_22 -> V_49 & V_106 ) ?
V_107 : V_108 ) == V_102 ) {
if ( V_102 == V_107 )
V_22 -> V_49 |= V_106 ;
else
V_22 -> V_49 &= ~ V_106 ;
return 0 ;
}
F_57 ( 50 ) ;
}
F_30 ( L_31 ,
V_102 ? L_32 : L_33 ) ;
return - V_70 ;
}
static int F_58 ( struct V_21 * V_22 )
{
int V_18 ;
T_1 V_109 ;
F_4 ( V_22 -> V_33 , V_110 ,
V_111 ) ;
for ( V_18 = 0 ; V_18 < 1000 ; V_18 ++ ) {
F_57 ( V_112 ) ;
F_1 ( V_22 -> V_33 , V_110 , & V_109 ) ;
if ( V_109 & V_113 )
break;
}
if ( V_18 == 1000 )
return - V_70 ;
F_4 ( V_22 -> V_33 , V_114 ,
V_115 ) ;
for ( V_18 = 0 ; V_18 < 10000 ; V_18 ++ ) {
F_57 ( V_116 * 4 ) ;
F_1 ( V_22 -> V_33 , V_114 , & V_109 ) ;
if ( V_109 & V_117 )
break;
}
if ( V_18 == 10000 )
return - V_70 ;
F_1 ( V_22 -> V_33 , V_114 , & V_109 ) ;
F_4 ( V_22 -> V_33 , V_114 ,
V_109 | V_118 ) ;
return 0 ;
}
static int F_59 ( struct V_21 * V_22 )
{
T_1 V_97 ;
int V_63 ;
#ifndef F_60
struct V_119 V_120 ;
#endif
if ( V_22 -> V_69 ) {
F_61 ( L_34
L_35 ,
V_22 -> V_33 -> V_51 , V_22 -> V_69 ) ;
return - V_31 ;
}
#ifdef F_60
if ( ! V_120 . V_121 ) {
V_63 = F_62 ( V_22 , & V_120 ) ;
if ( V_63 ) {
F_61 ( L_36 ,
V_22 -> V_33 -> V_51 , V_63 ) ;
V_22 -> V_69 = V_122 ;
goto V_123;
}
}
#else
V_63 = F_62 ( V_22 , & V_120 ) ;
if ( V_63 ) {
F_61 ( L_36 ,
V_22 -> V_33 -> V_51 , V_63 ) ;
V_22 -> V_69 = V_122 ;
goto V_123;
}
#endif
V_22 -> V_124 = V_120 . V_121 ;
V_63 = F_58 ( V_22 ) ;
if ( V_63 ) {
F_61 ( L_37 ,
V_22 -> V_33 -> V_51 , V_63 ) ;
goto V_123;
}
V_63 = F_55 ( V_22 ) ;
if ( V_63 ) {
F_61 ( L_38 ,
V_22 -> V_33 -> V_51 , V_63 ) ;
goto V_123;
}
F_15 ( V_22 -> V_33 ,
V_125 , 0x80000000 ) ;
F_4 ( V_22 -> V_33 , V_110 , 0 ) ;
V_63 = F_63 ( V_22 , & V_120 ) ;
if ( V_63 ) {
F_26 (KERN_ERR DRV_NAME L_39 ,
priv->net_dev->name, err) ;
goto V_123;
}
F_15 ( V_22 -> V_33 ,
V_125 , 0x00000000 ) ;
V_63 = F_58 ( V_22 ) ;
if ( V_63 ) {
F_26 (KERN_ERR DRV_NAME
L_40 ,
priv->net_dev->name, err) ;
goto V_123;
}
V_63 = F_64 ( V_22 , & V_120 ) ;
if ( V_63 ) {
F_61 ( L_41 ,
V_22 -> V_33 -> V_51 , V_63 ) ;
goto V_123;
}
#ifndef F_60
F_65 ( V_22 , & V_120 ) ;
#endif
for ( V_97 = V_126 ;
V_97 < V_127 ; V_97 += 4 )
F_15 ( V_22 -> V_33 , V_97 , 0 ) ;
for ( V_97 = V_128 ;
V_97 < V_129 ; V_97 += 4 )
F_15 ( V_22 -> V_33 , V_97 , 0 ) ;
for ( V_97 = V_130 ;
V_97 < V_131 ; V_97 += 4 )
F_15 ( V_22 -> V_33 , V_97 , 0 ) ;
for ( V_97 = V_132 ;
V_97 < V_133 ; V_97 += 4 )
F_15 ( V_22 -> V_33 , V_97 , 0 ) ;
for ( V_97 = V_134 ;
V_97 < V_135 ; V_97 += 4 )
F_15 ( V_22 -> V_33 , V_97 , 0 ) ;
return 0 ;
V_123:
F_65 ( V_22 , & V_120 ) ;
return V_63 ;
}
static inline void F_66 ( struct V_21 * V_22 )
{
if ( V_22 -> V_49 & V_136 )
return;
V_22 -> V_49 |= V_136 ;
F_4 ( V_22 -> V_33 , V_137 , V_138 ) ;
}
static inline void F_67 ( struct V_21 * V_22 )
{
if ( ! ( V_22 -> V_49 & V_136 ) )
return;
V_22 -> V_49 &= ~ V_136 ;
F_4 ( V_22 -> V_33 , V_137 , 0x0 ) ;
}
static void F_68 ( struct V_21 * V_22 )
{
struct V_24 * V_23 = & V_22 -> V_25 ;
F_30 ( L_42 ) ;
F_1 ( V_22 -> V_33 , V_139 ,
& V_23 -> V_30 ) ;
F_1 ( V_22 -> V_33 , V_140 ,
& V_23 -> V_35 ) ;
F_14 ( V_22 -> V_33 , V_23 -> V_30 , & V_23 -> V_141 ) ;
F_14 ( V_22 -> V_33 , V_23 -> V_35 , & V_23 -> V_142 ) ;
V_23 -> V_142 &= 0x0000FFFF ;
F_30 ( L_43 , V_23 -> V_141 ) ;
F_30 ( L_44 , V_23 -> V_142 ) ;
F_30 ( L_45 ) ;
}
static inline void F_69 ( struct V_21 * V_22 )
{
T_1 V_3 = 0 ;
V_3 = ( V_143 | V_144 |
V_145 ) ;
F_4 ( V_22 -> V_33 , V_146 , V_3 ) ;
}
static int F_70 ( struct V_21 * V_22 )
{
#define F_71 5
#define F_72 40
unsigned short V_147 = 0 ;
T_1 V_3 = 0 ;
int V_18 ;
if ( ! ( V_22 -> V_148 & V_149 ) ) {
F_73 ( V_22 -> V_150 -> V_151 . V_152 , false ) ;
V_22 -> V_49 &= ~ V_153 ;
return 0 ;
}
for ( V_18 = 0 ; V_18 < F_71 ; V_18 ++ ) {
F_57 ( F_72 ) ;
F_1 ( V_22 -> V_33 , V_146 , & V_3 ) ;
V_147 = ( V_147 << 1 ) | ( ( V_3 & V_154 ) ? 0 : 1 ) ;
}
if ( V_147 == 0 ) {
F_73 ( V_22 -> V_150 -> V_151 . V_152 , true ) ;
V_22 -> V_49 |= V_153 ;
} else {
F_73 ( V_22 -> V_150 -> V_151 . V_152 , false ) ;
V_22 -> V_49 &= ~ V_153 ;
}
return ( V_147 == 0 ) ;
}
static int F_74 ( struct V_21 * V_22 )
{
T_1 V_7 , V_13 ;
T_1 V_4 ;
V_13 = sizeof( V_7 ) ;
if ( F_25
( V_22 , V_155 , & V_7 , & V_13 ) ) {
F_30 ( L_46 ,
__LINE__ ) ;
return - V_70 ;
}
F_30 ( L_47 , V_7 ) ;
F_14 ( V_22 -> V_33 , V_7 + 0xFC , & V_4 ) ;
V_22 -> V_156 = ( V_4 >> 24 ) & 0xFF ;
F_30 ( L_48 , V_22 -> V_156 ) ;
F_14 ( V_22 -> V_33 , V_7 + 0x20 , & V_4 ) ;
if ( ! ( ( V_4 >> 24 ) & 0x01 ) )
V_22 -> V_148 |= V_149 ;
F_30 ( L_49 ,
( V_22 -> V_148 & V_149 ) ? L_50 : L_51 ) ;
return 0 ;
}
static int F_75 ( struct V_21 * V_22 )
{
int V_18 ;
T_1 V_157 , V_158 , V_159 ;
F_30 ( L_42 ) ;
if ( V_22 -> V_49 & V_72 )
return 0 ;
if ( F_59 ( V_22 ) ) {
F_26 (KERN_ERR DRV_NAME
L_52 ,
priv->net_dev->name) ;
return - V_70 ;
}
F_76 ( V_22 ) ;
F_69 ( V_22 ) ;
F_4 ( V_22 -> V_33 , V_110 , 0 ) ;
F_77 ( L_53 ) ;
V_18 = 5000 ;
do {
F_53 ( F_54 ( 40 ) ) ;
F_1 ( V_22 -> V_33 , V_160 , & V_157 ) ;
if ( V_157 & V_161 ) {
F_4 ( V_22 -> V_33 , V_160 ,
V_161 ) ;
break;
}
if ( V_157 &
( V_162 | V_163 ) ) {
F_4 ( V_22 -> V_33 , V_160 ,
V_162 |
V_163 ) ;
}
} while ( -- V_18 );
F_1 ( V_22 -> V_33 , V_160 , & V_157 ) ;
F_1 ( V_22 -> V_33 , V_137 , & V_158 ) ;
V_157 &= V_138 ;
if ( V_157 & V_158 )
F_4 ( V_22 -> V_33 , V_160 , V_157 ) ;
F_77 ( L_54 ,
V_18 ? L_55 : L_56 ) ;
if ( ! V_18 ) {
F_26 (KERN_WARNING DRV_NAME
L_57 ,
priv->net_dev->name) ;
return - V_70 ;
}
F_1 ( V_22 -> V_33 , V_146 , & V_159 ) ;
V_159 |= ( V_164 | V_143 ) ;
F_4 ( V_22 -> V_33 , V_146 , V_159 ) ;
V_22 -> V_49 |= V_72 ;
V_22 -> V_49 &= ~ ( V_165 | V_166 ) ;
F_30 ( L_45 ) ;
return 0 ;
}
static inline void F_78 ( struct V_21 * V_22 )
{
if ( ! V_22 -> V_69 )
return;
V_22 -> V_167 [ V_22 -> V_168 ++ ] = V_22 -> V_69 ;
V_22 -> V_168 %= V_169 ;
V_22 -> V_69 = 0 ;
}
static int F_79 ( struct V_21 * V_22 )
{
T_1 V_3 ;
int V_18 ;
F_30 ( L_58 ) ;
F_69 ( V_22 ) ;
F_4 ( V_22 -> V_33 , V_110 ,
V_170 ) ;
V_18 = 5 ;
do {
F_57 ( V_171 ) ;
F_1 ( V_22 -> V_33 , V_110 , & V_3 ) ;
if ( V_3 & V_172 )
break;
} while ( -- V_18 );
V_22 -> V_49 &= ~ V_50 ;
if ( ! V_18 ) {
F_30
( L_59 ) ;
return - V_70 ;
}
F_4 ( V_22 -> V_33 , V_110 ,
V_111 ) ;
F_78 ( V_22 ) ;
V_22 -> V_49 &= ~ ( V_72 | V_165 |
V_166 | V_106 ) ;
return 0 ;
}
static int F_80 ( struct V_21 * V_22 )
{
#define F_81 (HZ / 5000)
struct V_56 V_57 = {
. V_56 = V_173 ,
. V_88 = 0 ,
. V_65 = 0 ,
} ;
int V_63 , V_18 ;
T_1 V_98 , V_99 ;
F_41 ( L_60 ) ;
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( V_63 )
return V_63 ;
for ( V_18 = 0 ; V_18 < 2500 ; V_18 ++ ) {
F_14 ( V_22 -> V_33 , V_174 , & V_98 ) ;
F_14 ( V_22 -> V_33 , V_175 , & V_99 ) ;
if ( ( V_98 & V_176 ) &&
( V_99 & V_177 ) )
return 0 ;
F_53 ( F_81 ) ;
}
return - V_70 ;
}
static int F_82 ( struct V_21 * V_22 )
{
struct V_56 V_57 = {
. V_56 = V_178 ,
. V_88 = 0 ,
. V_65 = 0
} ;
int V_63 = 0 ;
F_41 ( L_61 ) ;
if ( V_22 -> V_49 & V_106 )
return 0 ;
F_83 ( & V_22 -> V_179 ) ;
if ( F_70 ( V_22 ) ) {
F_41 ( L_62 ) ;
goto V_180;
}
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( V_63 ) {
F_30 ( L_63 ) ;
goto V_180;
}
V_63 = F_56 ( V_22 , V_107 ) ;
if ( V_63 ) {
F_30 ( L_64 ,
V_22 -> V_33 -> V_51 ) ;
goto V_180;
}
if ( V_22 -> V_181 ) {
V_22 -> V_181 = 0 ;
F_38 ( & V_22 -> V_182 , V_53 / 2 ) ;
}
V_180:
F_84 ( & V_22 -> V_179 ) ;
return V_63 ;
}
static int F_85 ( struct V_21 * V_22 )
{
#define F_86 (msecs_to_jiffies(100))
struct V_56 V_57 = {
. V_56 = V_183 ,
. V_88 = 0 ,
. V_65 = 0 ,
} ;
int V_63 , V_18 ;
T_1 V_3 ;
if ( ! ( V_22 -> V_49 & V_72 ) )
return 0 ;
V_22 -> V_49 |= V_184 ;
if ( ! V_22 -> V_69 ) {
F_82 ( V_22 ) ;
V_63 = F_80 ( V_22 ) ;
if ( V_63 )
F_26 (KERN_WARNING DRV_NAME
L_65 , err) ;
F_41 ( L_66 ) ;
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( V_63 )
F_26 (KERN_WARNING DRV_NAME L_67
L_68 ,
priv->net_dev->name, err) ;
else
F_53 ( F_86 ) ;
}
V_22 -> V_49 &= ~ V_106 ;
F_69 ( V_22 ) ;
F_4 ( V_22 -> V_33 , V_110 ,
V_170 ) ;
for ( V_18 = 5 ; V_18 > 0 ; V_18 -- ) {
F_57 ( 10 ) ;
F_1 ( V_22 -> V_33 , V_110 , & V_3 ) ;
if ( V_3 & V_172 )
break;
}
if ( V_18 == 0 )
F_26 (KERN_WARNING DRV_NAME
L_69 ,
priv->net_dev->name) ;
F_4 ( V_22 -> V_33 , V_110 ,
V_111 ) ;
V_22 -> V_49 &= ~ ( V_72 | V_184 ) ;
return 0 ;
}
static int F_87 ( struct V_21 * V_22 )
{
struct V_56 V_57 = {
. V_56 = V_185 ,
. V_88 = 0 ,
. V_65 = 0
} ;
int V_63 = 0 ;
F_41 ( L_70 ) ;
if ( ! ( V_22 -> V_49 & V_106 ) )
return 0 ;
V_22 -> V_49 &= ~ ( V_166 | V_165 ) ;
if ( ! V_22 -> V_181 ) {
V_22 -> V_181 = 1 ;
F_88 ( & V_22 -> V_182 ) ;
}
F_83 ( & V_22 -> V_179 ) ;
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( V_63 ) {
F_26 (KERN_WARNING DRV_NAME
L_71 ) ;
goto V_180;
}
V_63 = F_56 ( V_22 , V_108 ) ;
if ( V_63 ) {
F_26 (KERN_WARNING DRV_NAME
L_72 ) ;
goto V_180;
}
F_30 ( L_73 ) ;
V_180:
F_84 ( & V_22 -> V_179 ) ;
return V_63 ;
}
static int F_89 ( struct V_21 * V_22 )
{
struct V_56 V_57 = {
. V_56 = V_186 ,
. V_88 = 0 ,
. V_65 = 8
} ;
int V_63 ;
F_30 ( L_42 ) ;
F_90 ( L_74 ) ;
V_57 . V_67 [ 0 ] = 0 ;
if ( ! ( V_22 -> V_187 & V_188 ) )
V_57 . V_67 [ 0 ] |= V_189 ;
if ( ( V_22 -> V_150 -> V_190 . V_62 & V_191 ) && V_22 -> V_150 -> V_190 . V_192 )
V_57 . V_67 [ 0 ] |= V_193 ;
if ( V_22 -> V_187 & V_194 )
V_57 . V_67 [ 0 ] |= V_195 ;
V_57 . V_67 [ 1 ] = V_22 -> V_196 ;
V_63 = F_40 ( V_22 , & V_57 ) ;
F_41 ( L_75 ,
V_57 . V_67 [ 0 ] ) ;
return V_63 ;
}
static int F_91 ( struct V_21 * V_22 )
{
struct V_56 V_57 = {
. V_56 = V_197 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
F_41 ( L_76 ) ;
V_57 . V_67 [ 0 ] = 0 ;
if ( V_22 -> V_150 -> V_198 == V_199 )
return 1 ;
if ( V_22 -> V_49 & V_200 ) {
F_90 ( L_77 ) ;
return 0 ;
}
F_30 ( L_42 ) ;
F_90 ( L_78 ) ;
V_22 -> V_49 |= V_200 ;
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( V_63 )
V_22 -> V_49 &= ~ V_200 ;
F_30 ( L_45 ) ;
return V_63 ;
}
static int F_92 ( struct V_21 * V_22 , int V_201 )
{
unsigned long V_62 ;
int V_202 = 0 ;
T_1 V_203 ;
T_1 V_204 = sizeof( V_203 ) ;
if ( V_22 -> V_205 ) {
F_93 ( V_22 -> V_150 , V_22 -> V_205 ) ;
V_22 -> V_205 = 0 ;
}
if ( V_22 -> V_49 & V_206 ) {
F_30 ( L_79
L_80 , V_22 -> V_33 -> V_51 ) ;
return 0 ;
}
F_94 ( & V_207 , 175 ) ;
F_42 ( & V_22 -> V_68 , V_62 ) ;
F_67 ( V_22 ) ;
F_78 ( V_22 ) ;
F_51 ( & V_22 -> V_68 , V_62 ) ;
if ( V_22 -> V_49 & V_208 ||
( V_22 -> V_49 & V_50 ) ) {
if ( F_79 ( V_22 ) ) {
F_26 (KERN_WARNING DRV_NAME
L_81 ,
priv->net_dev->name) ;
V_202 = 1 ;
goto exit;
}
} else
V_22 -> V_49 |= V_208 ;
if ( F_75 ( V_22 ) ) {
F_26 (KERN_ERR DRV_NAME
L_82 ,
priv->net_dev->name) ;
V_202 = 1 ;
goto exit;
}
F_68 ( V_22 ) ;
if ( F_74 ( V_22 ) ) {
F_26 (KERN_ERR DRV_NAME
L_83 ,
priv->net_dev->name) ;
V_202 = 1 ;
goto exit;
}
if ( F_95 ( V_22 -> V_150 , & V_209 [ 0 ] ) ) {
F_26 (KERN_WARNING DRV_NAME L_84 ) ;
return 0 ;
}
V_22 -> V_150 -> V_210 = V_211 ;
V_203 = V_212 ;
if ( F_29 ( V_22 , V_213 , & V_203 , & V_204 ) ) {
F_26 (KERN_ERR DRV_NAME
L_85 ,
priv->net_dev->name) ;
V_202 = 1 ;
goto exit;
}
V_22 -> V_49 &= ~ V_200 ;
if ( F_70 ( V_22 ) ) {
F_26 ( V_214 L_86 ,
V_22 -> V_33 -> V_51 ) ;
if ( V_22 -> V_215 ) {
V_22 -> V_215 = 0 ;
F_38 ( & V_22 -> V_216 ,
F_96 ( V_53 ) ) ;
}
V_201 = 1 ;
}
F_66 ( V_22 ) ;
if ( F_97 ( V_22 ) ) {
F_26 (KERN_ERR DRV_NAME L_87 ,
priv->net_dev->name) ;
V_202 = 1 ;
goto exit;
}
if ( ! V_201 ) {
if ( F_82 ( V_22 ) ) {
F_26 (KERN_ERR DRV_NAME L_67
L_88 ,
priv->net_dev->name) ;
F_85 ( V_22 ) ;
V_202 = 1 ;
goto exit;
}
F_89 ( V_22 ) ;
F_91 ( V_22 ) ;
}
exit:
return V_202 ;
}
static void F_98 ( struct V_21 * V_22 )
{
unsigned long V_62 ;
union V_217 V_218 = {
. V_219 = {
. V_220 = V_221 }
} ;
int V_222 = V_22 -> V_49 & V_166 ;
if ( ! V_22 -> V_215 ) {
V_22 -> V_215 = 1 ;
F_88 ( & V_22 -> V_216 ) ;
}
if ( ! V_22 -> V_181 ) {
V_22 -> V_181 = 1 ;
F_88 ( & V_22 -> V_182 ) ;
}
if ( V_22 -> V_49 & V_50 )
F_88 ( & V_22 -> V_52 ) ;
F_42 ( & V_22 -> V_68 , V_62 ) ;
F_66 ( V_22 ) ;
F_51 ( & V_22 -> V_68 , V_62 ) ;
if ( F_85 ( V_22 ) )
F_26 (KERN_ERR DRV_NAME L_89 ,
priv->net_dev->name) ;
F_42 ( & V_22 -> V_68 , V_62 ) ;
F_67 ( V_22 ) ;
F_51 ( & V_22 -> V_68 , V_62 ) ;
F_94 ( & V_207 , V_223 ) ;
if ( V_222 )
F_99 ( V_22 -> V_33 , V_224 , & V_218 , NULL ) ;
V_22 -> V_49 &= ~ ( V_166 | V_165 ) ;
F_36 ( V_22 -> V_33 ) ;
F_37 ( V_22 -> V_33 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
const struct V_225 * V_226 = F_102 ( V_22 -> V_150 ) ;
struct V_227 * V_151 = & V_22 -> V_150 -> V_151 ;
int V_228 ;
int V_18 ;
V_228 = F_92 ( V_22 , 1 ) ;
if ( V_228 )
return V_228 ;
memcpy ( V_151 -> V_152 -> V_229 , V_22 -> V_230 , V_231 ) ;
if ( V_226 -> V_232 ) {
struct V_233 * V_234 = & V_22 -> V_150 -> V_234 ;
V_234 -> V_235 = V_236 ;
V_234 -> V_237 = V_226 -> V_232 ;
V_234 -> V_238 = F_103 ( V_226 -> V_232 ,
sizeof( struct V_239 ) ,
V_240 ) ;
if ( ! V_234 -> V_238 ) {
F_98 ( V_22 ) ;
return - V_241 ;
}
for ( V_18 = 0 ; V_18 < V_226 -> V_232 ; V_18 ++ ) {
V_234 -> V_238 [ V_18 ] . V_235 = V_236 ;
V_234 -> V_238 [ V_18 ] . V_242 = V_226 -> V_243 [ V_18 ] . V_244 ;
V_234 -> V_238 [ V_18 ] . V_245 = V_226 -> V_243 [ V_18 ] . V_246 ;
V_234 -> V_238 [ V_18 ] . V_247 = V_226 -> V_243 [ V_18 ] . V_247 ;
if ( V_226 -> V_243 [ V_18 ] . V_62 & V_248 )
V_234 -> V_238 [ V_18 ] . V_62 |=
V_249 ;
if ( V_226 -> V_243 [ V_18 ] . V_62 & V_250 )
V_234 -> V_238 [ V_18 ] . V_62 |=
V_251 ;
if ( V_226 -> V_243 [ V_18 ] . V_62 & V_252 )
V_234 -> V_238 [ V_18 ] . V_62 |=
V_253 ;
}
V_234 -> V_254 = V_255 ;
V_234 -> V_256 = V_257 ;
V_151 -> V_152 -> V_258 [ V_236 ] = V_234 ;
}
F_104 ( V_151 -> V_152 , & V_22 -> V_259 -> V_2 ) ;
if ( F_105 ( V_151 -> V_152 ) ) {
F_98 ( V_22 ) ;
return - V_70 ;
}
return 0 ;
}
static void F_106 ( struct V_260 * V_261 )
{
struct V_21 * V_22 =
F_107 ( V_261 , struct V_21 , V_52 . V_261 ) ;
unsigned long V_62 ;
union V_217 V_218 = {
. V_219 = {
. V_220 = V_221 }
} ;
int V_222 = V_22 -> V_49 & V_166 ;
F_42 ( & V_22 -> V_68 , V_62 ) ;
F_30 ( L_90 , V_22 -> V_33 -> V_51 ) ;
V_22 -> V_262 ++ ;
V_22 -> V_49 &= ~ ( V_166 | V_165 ) ;
V_22 -> V_49 |= V_263 ;
F_88 ( & V_22 -> V_52 ) ;
V_22 -> V_49 |= V_50 ;
F_51 ( & V_22 -> V_68 , V_62 ) ;
F_83 ( & V_22 -> V_264 ) ;
V_22 -> V_181 = 1 ;
F_88 ( & V_22 -> V_182 ) ;
if ( V_222 )
F_99 ( V_22 -> V_33 , V_224 , & V_218 , NULL ) ;
F_92 ( V_22 , 0 ) ;
F_84 ( & V_22 -> V_264 ) ;
}
static void F_108 ( struct V_21 * V_22 , T_1 V_49 )
{
#define F_109 (HZ)
int V_228 ;
unsigned int V_13 , V_265 ;
char V_266 [ V_267 ] ;
T_1 V_268 ;
T_1 V_269 ;
char * V_270 ;
T_3 V_271 [ V_231 ] ;
F_110 ( V_272 ) ;
V_265 = V_267 ;
V_228 = F_25 ( V_22 , V_273 ,
V_266 , & V_265 ) ;
if ( V_228 ) {
F_30 ( L_46 ,
__LINE__ ) ;
return;
}
V_13 = sizeof( T_1 ) ;
V_228 = F_25 ( V_22 , V_274 , & V_268 , & V_13 ) ;
if ( V_228 ) {
F_30 ( L_46 ,
__LINE__ ) ;
return;
}
V_13 = sizeof( T_1 ) ;
V_228 = F_25 ( V_22 , V_275 , & V_269 , & V_13 ) ;
if ( V_228 ) {
F_30 ( L_46 ,
__LINE__ ) ;
return;
}
V_13 = V_231 ;
F_25 ( V_22 , V_276 , & V_271 , & V_13 ) ;
if ( V_228 ) {
F_30 ( L_46 ,
__LINE__ ) ;
return;
}
memcpy ( V_22 -> V_150 -> V_271 , V_271 , V_231 ) ;
switch ( V_268 ) {
case V_277 :
V_270 = L_91 ;
break;
case V_278 :
V_270 = L_92 ;
break;
case V_279 :
V_270 = L_93 ;
break;
case V_280 :
V_270 = L_94 ;
break;
default:
F_30 ( L_95 , V_268 ) ;
V_270 = L_96 ;
break;
}
F_30 ( L_97 ,
V_22 -> V_33 -> V_51 , F_111 ( V_272 , V_266 , V_265 ) ,
V_270 , V_269 , V_271 ) ;
if ( ! ( V_22 -> V_187 & V_281 ) ) {
V_22 -> V_265 = F_33 ( ( T_3 ) V_265 , ( T_3 ) V_267 ) ;
memcpy ( V_22 -> V_266 , V_266 , V_22 -> V_265 ) ;
}
V_22 -> V_246 = V_269 ;
memcpy ( V_22 -> V_271 , V_271 , V_231 ) ;
V_22 -> V_49 |= V_165 ;
V_22 -> V_282 = F_35 () ;
F_38 ( & V_22 -> V_283 , V_53 / 10 ) ;
}
static int F_112 ( struct V_21 * V_22 , char * V_266 ,
int V_284 , int V_285 )
{
int V_286 = F_33 ( V_284 , V_267 ) ;
struct V_56 V_57 = {
. V_56 = V_287 ,
. V_88 = 0 ,
. V_65 = V_286
} ;
int V_63 ;
F_110 ( V_272 ) ;
F_41 ( L_98 , F_111 ( V_272 , V_266 , V_286 ) ) ;
if ( V_286 )
memcpy ( V_57 . V_67 , V_266 , V_286 ) ;
if ( ! V_285 ) {
V_63 = F_87 ( V_22 ) ;
if ( V_63 )
return V_63 ;
}
if ( ! V_286 && ! ( V_22 -> V_187 & V_188 ) ) {
int V_18 ;
T_3 * V_288 = ( T_3 * ) V_57 . V_67 ;
for ( V_18 = 0 ; V_18 < V_267 ; V_18 ++ )
V_288 [ V_18 ] = 0x18 + V_18 ;
V_57 . V_65 = V_267 ;
}
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( ! V_63 ) {
memset ( V_22 -> V_266 + V_286 , 0 , V_267 - V_286 ) ;
memcpy ( V_22 -> V_266 , V_266 , V_286 ) ;
V_22 -> V_265 = V_286 ;
}
if ( ! V_285 ) {
if ( F_82 ( V_22 ) )
V_63 = - V_70 ;
}
return V_63 ;
}
static void F_113 ( struct V_21 * V_22 , T_1 V_49 )
{
F_110 ( V_272 ) ;
F_114 ( V_289 | V_290 | V_291 ,
L_99 ,
F_111 ( V_272 , V_22 -> V_266 , V_22 -> V_265 ) ,
V_22 -> V_271 ) ;
V_22 -> V_49 &= ~ ( V_166 | V_165 ) ;
if ( V_22 -> V_49 & V_184 ) {
F_30 ( L_100 ) ;
return;
}
memset ( V_22 -> V_271 , 0 , V_231 ) ;
memset ( V_22 -> V_150 -> V_271 , 0 , V_231 ) ;
F_36 ( V_22 -> V_33 ) ;
F_37 ( V_22 -> V_33 ) ;
if ( ! ( V_22 -> V_49 & V_72 ) )
return;
if ( V_22 -> V_49 & V_263 )
F_38 ( & V_22 -> V_292 , 0 ) ;
F_38 ( & V_22 -> V_283 , 0 ) ;
}
static void F_115 ( struct V_21 * V_22 , T_1 V_49 )
{
F_30 ( L_101 ,
V_22 -> V_33 -> V_51 ) ;
F_73 ( V_22 -> V_150 -> V_151 . V_152 , true ) ;
V_22 -> V_49 |= V_153 ;
V_22 -> V_215 = 0 ;
F_88 ( & V_22 -> V_216 ) ;
F_38 ( & V_22 -> V_216 , F_96 ( V_53 ) ) ;
}
static void F_116 ( void * V_37 )
{
struct V_21 * V_22 = V_37 ;
union V_217 V_218 ;
V_218 . V_37 . V_284 = 0 ;
V_218 . V_37 . V_62 = 0 ;
F_99 ( V_22 -> V_33 , V_293 , & V_218 , NULL ) ;
}
static void F_117 ( struct V_260 * V_261 )
{
F_116 ( F_107 ( V_261 , struct V_21 ,
V_294 . V_261 ) ) ;
}
static void F_118 ( struct V_260 * V_261 )
{
F_116 ( F_107 ( V_261 , struct V_21 ,
V_295 ) ) ;
}
static void F_119 ( struct V_21 * V_22 , T_1 V_49 )
{
F_90 ( L_102 ) ;
V_22 -> V_150 -> V_296 ++ ;
V_22 -> V_49 &= ~ V_200 ;
if ( ! V_22 -> V_297 ) {
if ( ! F_120 ( & V_22 -> V_294 ) )
F_38 ( & V_22 -> V_294 ,
F_96 ( F_54 ( 4000 ) ) ) ;
} else {
V_22 -> V_297 = 0 ;
F_88 ( & V_22 -> V_294 ) ;
F_121 ( & V_22 -> V_295 ) ;
}
}
static void F_122 ( struct V_21 * V_22 , T_1 V_49 )
{
F_90 ( L_103 ) ;
V_22 -> V_49 |= V_200 ;
}
static void F_123 ( struct V_21 * V_22 , int V_49 )
{
int V_18 ;
if ( V_49 == V_298 &&
V_22 -> V_49 & V_166 &&
! ( V_22 -> V_49 & V_200 ) ) {
F_30 ( L_104
L_105 ) ;
F_34 ( V_22 ) ;
}
for ( V_18 = 0 ; V_299 [ V_18 ] . V_49 != - 1 ; V_18 ++ ) {
if ( V_49 == V_299 [ V_18 ] . V_49 ) {
F_124 ( L_106 ,
V_299 [ V_18 ] . V_51 ) ;
if ( V_299 [ V_18 ] . V_300 )
V_299 [ V_18 ] . V_300 ( V_22 , V_49 ) ;
V_22 -> V_301 . V_49 = V_49 ;
return;
}
}
F_124 ( L_107 , V_49 ) ;
}
static void F_125 ( struct V_21 * V_22 ,
struct V_302 * V_57 )
{
#ifdef F_126
if ( V_57 -> V_83 < F_127 ( V_64 ) ) {
F_41 ( L_108 ,
V_64 [ V_57 -> V_83 ] ,
V_57 -> V_83 ) ;
}
#endif
if ( V_57 -> V_83 == V_178 )
V_22 -> V_49 |= V_106 ;
if ( V_57 -> V_83 == V_185 )
V_22 -> V_49 &= ~ V_106 ;
V_22 -> V_49 &= ~ V_73 ;
F_39 ( & V_22 -> V_55 ) ;
}
static int F_128 ( struct V_21 * V_22 ,
struct V_303 * V_61 )
{
V_61 -> V_304 = F_129 ( sizeof( struct V_305 ) ) ;
if ( ! V_61 -> V_304 )
return - V_241 ;
V_61 -> V_306 = (struct V_305 * ) V_61 -> V_304 -> V_37 ;
V_61 -> V_307 = F_130 ( V_22 -> V_259 , V_61 -> V_304 -> V_37 ,
sizeof( struct V_305 ) ,
V_308 ) ;
return 0 ;
}
static void F_131 ( struct V_21 * V_22 )
{
int V_18 ;
if ( ! V_22 -> V_309 [ 0 ] )
return;
for ( V_18 = 0 ; V_18 < 0x30 ; V_18 ++ )
F_132 ( V_22 -> V_309 [ V_18 ] ) ;
V_22 -> V_309 [ 0 ] = NULL ;
}
static int F_133 ( struct V_21 * V_22 )
{
int V_18 ;
if ( V_22 -> V_309 [ 0 ] )
return 1 ;
for ( V_18 = 0 ; V_18 < 0x30 ; V_18 ++ ) {
V_22 -> V_309 [ V_18 ] = F_134 ( 0x1000 , V_310 ) ;
if ( ! V_22 -> V_309 [ V_18 ] ) {
F_30 ( L_109
L_110 , V_22 -> V_33 -> V_51 , V_18 ) ;
while ( V_18 > 0 )
F_132 ( V_22 -> V_309 [ -- V_18 ] ) ;
V_22 -> V_309 [ 0 ] = NULL ;
return 0 ;
}
}
return 1 ;
}
static T_1 F_135 ( struct V_21 * V_22 , T_3 * V_311 ,
T_4 V_13 , int V_312 )
{
T_1 V_18 , V_40 ;
T_1 V_313 ;
T_3 * V_314 , * V_315 ;
T_1 V_228 ;
V_314 = V_311 ;
if ( V_312 == V_316 ) {
if ( ! F_133 ( V_22 ) )
V_312 = V_317 ;
}
for ( V_228 = V_318 , V_18 = 0 ; V_18 < 0x30000 ; V_18 += 4 ) {
F_14 ( V_22 -> V_33 , V_18 , & V_313 ) ;
if ( V_312 == V_316 )
* ( T_1 * ) F_136 ( V_18 ) = V_313 ;
if ( V_228 == V_318 ) {
V_315 = ( T_3 * ) & V_313 ;
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
if ( * V_314 != * V_315 ) {
V_314 = V_311 ;
continue;
}
V_314 ++ ;
V_315 ++ ;
if ( ( V_314 - V_311 ) == V_13 )
V_228 = ( V_18 + V_40 ) - V_13 + 1 ;
}
} else if ( V_312 == V_317 )
return V_228 ;
}
return V_228 ;
}
static void F_137 ( struct V_21 * V_22 , int V_18 )
{
#ifdef F_138
struct V_319 * V_49 = & V_22 -> V_320 . V_321 [ V_18 ] ;
T_1 V_322 , V_3 ;
int V_40 ;
#endif
F_30 ( L_111 ,
V_18 * sizeof( struct V_319 ) ) ;
#ifdef F_138
F_4 ( V_22 -> V_33 , V_110 ,
V_170 ) ;
V_40 = 5 ;
do {
F_57 ( V_171 ) ;
F_1 ( V_22 -> V_33 , V_110 , & V_3 ) ;
if ( V_3 & V_172 )
break;
} while ( V_40 -- );
V_322 = F_135 ( V_22 , ( T_3 * ) V_49 ,
sizeof( struct V_319 ) ,
V_316 ) ;
if ( V_322 < V_323 )
F_30 ( L_112
L_113 ,
V_22 -> V_33 -> V_51 , V_322 ,
sizeof( struct V_319 ) ) ;
else
F_30 ( L_114
L_115 , V_22 -> V_33 -> V_51 ) ;
F_32 ( ( T_3 * ) V_22 -> V_320 . V_321 ,
sizeof( struct V_319 ) * V_324 ) ;
#endif
V_22 -> V_69 = V_325 ;
V_22 -> V_33 -> V_326 . V_327 ++ ;
F_34 ( V_22 ) ;
}
static void F_139 ( struct V_21 * V_22 , int V_18 ,
struct V_328 * V_326 )
{
struct V_1 * V_2 = V_22 -> V_33 ;
struct V_319 * V_49 = & V_22 -> V_320 . V_321 [ V_18 ] ;
struct V_303 * V_61 = & V_22 -> V_329 [ V_18 ] ;
F_140 ( L_116 ) ;
if ( F_141 ( V_49 -> V_330 > F_142 ( V_61 -> V_304 ) ) ) {
F_30 ( L_117
L_118 ,
V_2 -> V_51 ,
V_49 -> V_330 , F_142 ( V_61 -> V_304 ) ) ;
V_2 -> V_326 . V_327 ++ ;
return;
}
if ( F_141 ( ! F_143 ( V_2 ) ) ) {
V_2 -> V_326 . V_327 ++ ;
V_22 -> V_301 . V_331 . V_332 ++ ;
F_144 ( L_119 ) ;
return;
}
if ( F_141 ( V_22 -> V_150 -> V_198 != V_199 &&
! ( V_22 -> V_49 & V_166 ) ) ) {
F_144 ( L_120 ) ;
V_22 -> V_301 . V_331 . V_332 ++ ;
return;
}
F_145 ( V_22 -> V_259 ,
V_61 -> V_307 ,
sizeof( struct V_305 ) , V_308 ) ;
F_146 ( V_61 -> V_304 , V_49 -> V_330 ) ;
#ifdef F_147
F_148 ( V_61 -> V_304 , V_333 ,
F_149 ( T_1 , V_49 -> V_330 ,
V_334 ) ) ;
#endif
if ( ! F_150 ( V_22 -> V_150 , V_61 -> V_304 , V_326 ) ) {
#ifdef F_147
F_144 ( L_121 ,
V_2 -> V_51 ) ;
F_32 ( V_335 , V_333 , V_49 -> V_330 ) ;
#endif
V_2 -> V_326 . V_327 ++ ;
F_151 ( V_61 -> V_304 ) ;
V_61 -> V_304 = NULL ;
}
if ( F_141 ( F_128 ( V_22 , V_61 ) ) ) {
F_26 (KERN_WARNING DRV_NAME L_67
L_122
L_123 , dev->name) ;
F_30 ( L_124 ) ;
}
V_22 -> V_336 . V_321 [ V_18 ] . V_337 = V_61 -> V_307 ;
}
static void F_152 ( struct V_21 * V_22 , int V_18 ,
struct V_328 * V_326 )
{
struct V_1 * V_2 = V_22 -> V_33 ;
struct V_319 * V_49 = & V_22 -> V_320 . V_321 [ V_18 ] ;
struct V_303 * V_61 = & V_22 -> V_329 [ V_18 ] ;
struct V_338 {
struct V_339 V_340 ;
T_5 V_341 ;
} * V_342 ;
F_140 ( L_116 ) ;
if ( F_141 ( V_49 -> V_330 > F_142 ( V_61 -> V_304 ) -
sizeof( struct V_338 ) ) ) {
F_30 ( L_117
L_118 ,
V_2 -> V_51 ,
V_49 -> V_330 ,
F_142 ( V_61 -> V_304 ) ) ;
V_2 -> V_326 . V_327 ++ ;
return;
}
if ( F_141 ( ! F_143 ( V_2 ) ) ) {
V_2 -> V_326 . V_327 ++ ;
V_22 -> V_301 . V_331 . V_332 ++ ;
F_144 ( L_119 ) ;
return;
}
if ( F_141 ( V_22 -> V_187 & V_343 &&
V_49 -> V_62 & V_344 ) ) {
F_140 ( L_125 ) ;
V_2 -> V_326 . V_327 ++ ;
return;
}
F_145 ( V_22 -> V_259 , V_61 -> V_307 ,
sizeof( struct V_305 ) , V_308 ) ;
memmove ( V_61 -> V_304 -> V_37 + sizeof( struct V_338 ) ,
V_61 -> V_304 -> V_37 , V_49 -> V_330 ) ;
V_342 = (struct V_338 * ) V_61 -> V_304 -> V_37 ;
V_342 -> V_340 . V_345 = V_346 ;
V_342 -> V_340 . V_347 = 0 ;
V_342 -> V_340 . V_348 = F_153 ( sizeof( struct V_338 ) ) ;
V_342 -> V_340 . V_349 = F_154 ( 1 << V_350 ) ;
V_342 -> V_341 = V_49 -> V_351 + V_352 ;
F_146 ( V_61 -> V_304 , V_49 -> V_330 + sizeof( struct V_338 ) ) ;
if ( ! F_150 ( V_22 -> V_150 , V_61 -> V_304 , V_326 ) ) {
V_2 -> V_326 . V_327 ++ ;
F_151 ( V_61 -> V_304 ) ;
V_61 -> V_304 = NULL ;
}
if ( F_141 ( F_128 ( V_22 , V_61 ) ) ) {
F_155 (
L_122
L_123 , V_2 -> V_51 ) ;
F_30 ( L_124 ) ;
}
V_22 -> V_336 . V_321 [ V_18 ] . V_337 = V_61 -> V_307 ;
}
static int F_156 ( struct V_21 * V_22 , int V_18 )
{
struct V_319 * V_49 = & V_22 -> V_320 . V_321 [ V_18 ] ;
struct V_305 * V_353 = V_22 -> V_329 [ V_18 ] . V_306 ;
T_2 V_354 = V_49 -> V_355 & V_356 ;
switch ( V_354 ) {
case V_357 :
return ( V_49 -> V_330 != sizeof( V_353 -> V_358 . V_359 ) ) ;
case V_360 :
return ( V_49 -> V_330 != sizeof( V_353 -> V_358 . V_49 ) ) ;
case V_361 :
return ( V_49 -> V_330 < sizeof( V_353 -> V_358 . V_362 ) ) ;
case V_363 :
case V_364 :
#ifdef F_157
return 0 ;
#else
switch ( F_158 ( F_159 ( V_353 -> V_358 . V_365 . V_366 ) ) ) {
case V_367 :
case V_368 :
return 0 ;
case V_369 :
return ( V_49 -> V_330 >
V_370 ) ;
}
#endif
}
return 1 ;
}
static void F_160 ( struct V_21 * V_22 )
{
struct V_371 * V_372 = & V_22 -> V_336 ;
struct V_373 * V_374 = & V_22 -> V_320 ;
struct V_303 * V_61 ;
T_2 V_354 ;
T_1 V_109 , V_375 , V_18 , V_314 ;
struct V_305 * V_353 ;
struct V_328 V_326 = {
. V_376 = V_80 ,
} ;
F_1 ( V_22 -> V_33 , V_377 , & V_109 ) ;
F_1 ( V_22 -> V_33 , V_378 , & V_375 ) ;
if ( V_109 >= V_372 -> V_379 ) {
F_140 ( L_126 ) ;
return;
}
V_18 = ( V_372 -> V_77 + 1 ) % V_372 -> V_379 ;
V_314 = V_18 ;
while ( V_18 != V_109 ) {
V_61 = & V_22 -> V_329 [ V_18 ] ;
F_161 ( V_22 -> V_259 , V_61 -> V_307 ,
sizeof( struct V_305 ) ,
V_308 ) ;
if ( F_141 ( F_156 ( V_22 , V_18 ) ) ) {
F_137 ( V_22 , V_18 ) ;
goto V_380;
}
V_353 = V_61 -> V_306 ;
V_354 = V_374 -> V_321 [ V_18 ] . V_355 & V_356 ;
V_326 . V_351 = V_374 -> V_321 [ V_18 ] . V_351 + V_352 ;
V_326 . V_13 = V_374 -> V_321 [ V_18 ] . V_330 ;
V_326 . V_381 = 0 ;
if ( V_326 . V_351 != 0 )
V_326 . V_381 |= V_382 ;
V_326 . V_244 = V_211 ;
F_140 ( L_127 ,
V_22 -> V_33 -> V_51 , V_383 [ V_354 ] ,
V_326 . V_13 ) ;
switch ( V_354 ) {
case V_357 :
F_125 ( V_22 , & V_353 -> V_358 . V_359 ) ;
break;
case V_360 :
F_123 ( V_22 , V_353 -> V_358 . V_49 ) ;
break;
case V_363 :
case V_364 :
#ifdef F_157
if ( V_22 -> V_150 -> V_198 == V_199 ) {
F_152 ( V_22 , V_18 , & V_326 ) ;
break;
}
#endif
if ( V_326 . V_13 < sizeof( struct V_384 ) )
break;
switch ( F_158 ( F_159 ( V_353 -> V_358 . V_365 . V_366 ) ) ) {
case V_367 :
F_162 ( V_22 -> V_150 ,
& V_353 -> V_358 . V_365 , & V_326 ) ;
break;
case V_368 :
break;
case V_369 :
F_139 ( V_22 , V_18 , & V_326 ) ;
break;
}
break;
}
V_380:
V_372 -> V_321 [ V_18 ] . V_49 . V_81 . V_385 = 0 ;
V_18 = ( V_18 + 1 ) % V_372 -> V_379 ;
}
if ( V_18 != V_314 ) {
V_372 -> V_77 = ( V_18 ? V_18 : V_372 -> V_379 ) - 1 ;
F_4 ( V_22 -> V_33 ,
V_378 , V_372 -> V_77 ) ;
}
}
static int F_163 ( struct V_21 * V_22 )
{
struct V_371 * V_386 = & V_22 -> V_387 ;
struct V_388 * V_389 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
int V_390 ;
int V_391 , V_18 ;
T_1 V_109 , V_375 , V_392 = 0 ;
if ( F_43 ( & V_22 -> V_393 ) )
return 0 ;
V_59 = V_22 -> V_393 . V_77 ;
V_61 = F_44 ( V_59 , struct V_60 , V_78 ) ;
V_389 = & V_386 -> V_321 [ V_61 -> V_394 ] ;
switch ( V_61 -> type ) {
case V_395 :
V_390 = 1 ;
V_391 = V_386 -> V_396 ;
break;
case V_397 :
V_390 = V_389 -> V_398 ;
V_392 = V_389 -> V_398 - 1 ;
V_391 = V_386 -> V_396 + V_392 ;
V_391 %= V_386 -> V_379 ;
break;
default:
F_26 (KERN_WARNING DRV_NAME L_128 ,
priv->net_dev->name) ;
return 0 ;
}
F_1 ( V_22 -> V_33 , V_399 ,
& V_109 ) ;
F_1 ( V_22 -> V_33 , V_400 ,
& V_375 ) ;
if ( V_375 != V_386 -> V_77 )
F_26 (KERN_WARNING DRV_NAME L_129 ,
priv->net_dev->name) ;
if ( ! ( ( V_109 <= V_375 && ( V_391 < V_109 || V_391 >= V_375 ) ) || ( V_391 < V_109 && V_391 >= V_375 ) ) ) {
F_164 ( L_130 ) ;
return 0 ;
}
F_45 ( V_59 ) ;
F_46 ( & V_22 -> V_401 ) ;
#ifdef F_126
{
V_18 = V_386 -> V_396 ;
F_164 ( L_131 , V_18 ,
& V_386 -> V_321 [ V_18 ] ,
( T_1 ) ( V_386 -> V_402 + V_18 * sizeof( struct V_388 ) ) ,
V_386 -> V_321 [ V_18 ] . V_337 , V_386 -> V_321 [ V_18 ] . V_403 ) ;
if ( V_61 -> type == V_397 ) {
V_18 = ( V_18 + 1 ) % V_386 -> V_379 ;
F_164 ( L_131 , V_18 ,
& V_386 -> V_321 [ V_18 ] ,
( T_1 ) ( V_386 -> V_402 + V_18 *
sizeof( struct V_388 ) ) ,
( T_1 ) V_386 -> V_321 [ V_18 ] . V_337 ,
V_386 -> V_321 [ V_18 ] . V_403 ) ;
}
}
#endif
switch ( V_61 -> type ) {
case V_397 :
if ( V_386 -> V_321 [ V_386 -> V_396 ] . V_49 . V_81 . V_404 . V_405 != 0 )
F_26 (KERN_WARNING DRV_NAME L_132
L_133
L_134 ,
priv->net_dev->name, txq->oldest, packet->index) ;
for ( V_18 = 0 ; V_18 < V_392 ; V_18 ++ ) {
V_389 = & V_386 -> V_321 [ ( V_61 -> V_394 + 1 + V_18 ) % V_386 -> V_379 ] ;
F_164 ( L_135 ,
( V_61 -> V_394 + 1 + V_18 ) % V_386 -> V_379 ,
V_389 -> V_337 , V_389 -> V_403 ) ;
F_145 ( V_22 -> V_259 ,
V_389 -> V_337 ,
V_389 -> V_403 , V_406 ) ;
}
F_165 ( V_61 -> V_81 . V_407 . V_408 ) ;
V_61 -> V_81 . V_407 . V_408 = NULL ;
F_47 ( V_59 , & V_22 -> V_409 ) ;
F_48 ( & V_22 -> V_410 ) ;
if ( V_22 -> V_49 & V_166 )
F_166 ( V_22 -> V_33 ) ;
V_22 -> V_33 -> V_411 = V_80 ;
break;
case V_395 :
if ( V_386 -> V_321 [ V_386 -> V_396 ] . V_49 . V_81 . V_404 . V_405 != 1 )
F_26 (KERN_WARNING DRV_NAME L_132
L_136
L_134 ,
priv->net_dev->name, txq->oldest, packet->index) ;
#ifdef F_126
if ( V_61 -> V_81 . V_82 . V_57 -> V_83 <
F_127 ( V_64 ) )
F_164 ( L_137 ,
V_64 [ V_61 -> V_81 . V_82 . V_57 ->
V_83 ] ,
V_61 -> V_81 . V_82 . V_57 ->
V_83 ,
V_61 -> V_81 . V_82 . V_57 -> V_412 ) ;
#endif
F_47 ( V_59 , & V_22 -> V_75 ) ;
F_48 ( & V_22 -> V_90 ) ;
break;
}
V_386 -> V_396 = ( V_391 + 1 ) % V_386 -> V_379 ;
V_386 -> V_413 += V_390 ;
F_167 ( & V_22 -> V_414 , V_386 -> V_413 ) ;
F_164 ( L_138 ,
V_80 - V_61 -> V_79 ) ;
return ( ! F_43 ( & V_22 -> V_393 ) ) ;
}
static inline void F_168 ( struct V_21 * V_22 )
{
int V_18 = 0 ;
while ( F_163 ( V_22 ) && V_18 < 200 )
V_18 ++ ;
if ( V_18 == 200 ) {
F_26 (KERN_WARNING DRV_NAME L_67
L_139 ,
priv->net_dev->name, i) ;
}
}
static void F_49 ( struct V_21 * V_22 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_371 * V_386 = & V_22 -> V_387 ;
struct V_388 * V_389 ;
int V_77 = V_386 -> V_77 ;
while ( ! F_43 ( & V_22 -> V_91 ) ) {
if ( V_386 -> V_413 <= 3 ) {
F_164 ( L_140 ) ;
break;
}
V_59 = V_22 -> V_91 . V_77 ;
F_45 ( V_59 ) ;
F_46 ( & V_22 -> V_92 ) ;
V_61 = F_44 ( V_59 , struct V_60 , V_78 ) ;
F_164 ( L_141 ,
& V_386 -> V_321 [ V_386 -> V_77 ] ,
( T_1 ) ( V_386 -> V_402 + V_386 -> V_77 *
sizeof( struct V_388 ) ) ) ;
V_61 -> V_394 = V_386 -> V_77 ;
V_389 = & V_386 -> V_321 [ V_386 -> V_77 ] ;
V_389 -> V_337 = V_61 -> V_81 . V_82 . V_415 ;
V_389 -> V_403 = sizeof( struct V_302 ) ;
V_389 -> V_398 = 1 ;
V_389 -> V_49 . V_81 . V_385 =
V_416 |
V_417 ;
V_386 -> V_77 ++ ;
V_386 -> V_77 %= V_386 -> V_379 ;
V_386 -> V_413 -- ;
F_46 ( & V_22 -> V_414 ) ;
F_47 ( V_59 , & V_22 -> V_393 ) ;
F_48 ( & V_22 -> V_401 ) ;
}
if ( V_386 -> V_77 != V_77 ) {
F_169 () ;
F_4 ( V_22 -> V_33 ,
V_400 ,
V_386 -> V_77 ) ;
}
}
static void F_50 ( struct V_21 * V_22 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_371 * V_386 = & V_22 -> V_387 ;
struct V_388 * V_389 ;
int V_77 = V_386 -> V_77 ;
int V_18 = 0 ;
struct V_418 * V_419 ;
struct V_384 * V_420 ;
while ( ! F_43 ( & V_22 -> V_421 ) ) {
V_59 = V_22 -> V_421 . V_77 ;
V_61 = F_44 ( V_59 , struct V_60 , V_78 ) ;
if ( F_141 ( 1 + V_61 -> V_81 . V_407 . V_408 -> V_422 >
V_423 ) ) {
F_30 ( L_142
L_143 ,
V_22 -> V_33 -> V_51 ) ;
}
if ( V_386 -> V_413 <= 3 + V_61 -> V_81 . V_407 . V_408 -> V_422 ) {
F_164 ( L_140 ) ;
break;
}
F_45 ( V_59 ) ;
F_46 ( & V_22 -> V_424 ) ;
V_389 = & V_386 -> V_321 [ V_386 -> V_77 ] ;
V_61 -> V_394 = V_386 -> V_77 ;
V_419 = V_61 -> V_81 . V_407 . V_37 ;
V_420 = (struct V_384 * ) V_61 -> V_81 . V_407 . V_408 ->
V_425 [ 0 ] -> V_37 ;
if ( V_22 -> V_150 -> V_198 == V_426 ) {
memcpy ( V_419 -> V_427 , V_420 -> V_428 , V_231 ) ;
memcpy ( V_419 -> V_429 , V_420 -> V_430 , V_231 ) ;
} else if ( V_22 -> V_150 -> V_198 == V_431 ) {
memcpy ( V_419 -> V_427 , V_420 -> V_428 , V_231 ) ;
memcpy ( V_419 -> V_429 , V_420 -> V_432 , V_231 ) ;
}
V_419 -> V_83 = V_433 ;
V_419 -> V_84 = 0 ;
V_419 -> V_434 = 0 ;
V_419 -> V_435 = V_61 -> V_81 . V_407 . V_408 -> V_435 ;
if ( V_61 -> V_81 . V_407 . V_408 -> V_422 > 1 )
V_419 -> V_436 =
V_61 -> V_81 . V_407 . V_408 -> V_437 -
V_438 ;
else
V_419 -> V_436 = 0 ;
V_389 -> V_337 = V_61 -> V_81 . V_407 . V_439 ;
V_389 -> V_403 = sizeof( struct V_418 ) ;
V_389 -> V_398 = 1 + V_61 -> V_81 . V_407 . V_408 -> V_422 ;
V_389 -> V_49 . V_81 . V_385 =
V_440 |
V_441 ;
V_386 -> V_77 ++ ;
V_386 -> V_77 %= V_386 -> V_379 ;
F_164 ( L_144 ,
V_61 -> V_394 , V_389 -> V_337 , V_389 -> V_403 ) ;
#ifdef F_126
if ( V_61 -> V_81 . V_407 . V_408 -> V_422 > 1 )
F_170 ( L_145 ,
V_61 -> V_81 . V_407 . V_408 -> V_422 ) ;
#endif
for ( V_18 = 0 ; V_18 < V_61 -> V_81 . V_407 . V_408 -> V_422 ; V_18 ++ ) {
V_389 = & V_386 -> V_321 [ V_386 -> V_77 ] ;
if ( V_18 == V_61 -> V_81 . V_407 . V_408 -> V_422 - 1 )
V_389 -> V_49 . V_81 . V_385 =
V_440 |
V_417 ;
else
V_389 -> V_49 . V_81 . V_385 =
V_440 |
V_441 ;
V_389 -> V_403 = V_61 -> V_81 . V_407 . V_408 ->
V_425 [ V_18 ] -> V_13 - V_438 ;
V_389 -> V_337 = F_130 ( V_22 -> V_259 ,
V_61 -> V_81 . V_407 .
V_408 -> V_425 [ V_18 ] ->
V_37 +
V_438 ,
V_389 -> V_403 ,
V_406 ) ;
F_164 ( L_146 ,
V_386 -> V_77 , V_389 -> V_337 ,
V_389 -> V_403 ) ;
F_171 ( V_22 -> V_259 ,
V_389 -> V_337 ,
V_389 -> V_403 ,
V_406 ) ;
V_386 -> V_77 ++ ;
V_386 -> V_77 %= V_386 -> V_379 ;
}
V_386 -> V_413 -= 1 + V_61 -> V_81 . V_407 . V_408 -> V_422 ;
F_167 ( & V_22 -> V_414 , V_386 -> V_413 ) ;
F_47 ( V_59 , & V_22 -> V_393 ) ;
F_48 ( & V_22 -> V_401 ) ;
}
if ( V_386 -> V_77 != V_77 ) {
F_4 ( V_22 -> V_33 ,
V_400 ,
V_386 -> V_77 ) ;
}
}
static void F_172 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_33 ;
unsigned long V_62 ;
T_1 V_157 , V_313 ;
F_42 ( & V_22 -> V_68 , V_62 ) ;
F_67 ( V_22 ) ;
F_1 ( V_2 , V_160 , & V_157 ) ;
F_173 ( L_147 ,
( unsigned long ) V_157 & V_138 ) ;
V_22 -> V_442 ++ ;
V_22 -> V_443 ++ ;
F_173 ( L_148 ,
( unsigned long ) V_157 & V_138 ) ;
if ( V_157 & V_162 ) {
F_26 (KERN_WARNING DRV_NAME
L_149 ) ;
V_22 -> V_444 ++ ;
F_4 ( V_2 , V_160 , V_162 ) ;
F_14 ( V_2 , V_445 , & V_22 -> V_69 ) ;
F_30 ( L_150 ,
V_22 -> V_33 -> V_51 , V_22 -> V_69 ) ;
F_14 ( V_2 , F_174 ( V_22 -> V_69 ) , & V_313 ) ;
F_30 ( L_151 ,
V_22 -> V_33 -> V_51 , V_313 ) ;
F_34 ( V_22 ) ;
}
if ( V_157 & V_163 ) {
F_26 (KERN_ERR DRV_NAME
L_152 ) ;
V_22 -> V_444 ++ ;
F_4 ( V_2 , V_160 , V_163 ) ;
}
if ( V_157 & V_446 ) {
F_173 ( L_153 ) ;
V_22 -> V_447 ++ ;
F_4 ( V_2 , V_160 , V_446 ) ;
F_160 ( V_22 ) ;
F_168 ( V_22 ) ;
}
if ( V_157 & V_448 ) {
F_173 ( L_154 ) ;
V_22 -> V_449 ++ ;
F_4 ( V_2 , V_160 , V_448 ) ;
F_168 ( V_22 ) ;
F_49 ( V_22 ) ;
F_50 ( V_22 ) ;
}
if ( V_157 & V_450 ) {
F_173 ( L_155 ) ;
V_22 -> V_444 ++ ;
F_4 ( V_2 , V_160 , V_450 ) ;
F_168 ( V_22 ) ;
}
if ( V_157 & V_451 ) {
V_22 -> V_444 ++ ;
F_4 ( V_2 , V_160 , V_451 ) ;
}
if ( V_157 & V_161 ) {
F_173 ( L_156 ) ;
V_22 -> V_444 ++ ;
F_1 ( V_2 , V_160 , & V_313 ) ;
if ( V_313 & ( V_162 |
V_163 ) ) {
F_4 ( V_2 , V_160 ,
V_162 |
V_163 ) ;
}
F_4 ( V_2 , V_160 , V_161 ) ;
}
if ( V_157 & V_452 ) {
F_173 ( L_157 ) ;
V_22 -> V_444 ++ ;
F_4 ( V_2 , V_160 , V_452 ) ;
}
if ( V_157 & V_453 ) {
F_173 ( L_158 ) ;
V_22 -> V_444 ++ ;
F_4 ( V_2 , V_160 ,
V_453 ) ;
}
V_22 -> V_442 -- ;
F_66 ( V_22 ) ;
F_51 ( & V_22 -> V_68 , V_62 ) ;
F_173 ( L_45 ) ;
}
static T_6 F_175 ( int V_454 , void * V_37 )
{
struct V_21 * V_22 = V_37 ;
T_1 V_157 , V_158 ;
if ( ! V_37 )
return V_455 ;
F_176 ( & V_22 -> V_68 ) ;
if ( ! ( V_22 -> V_49 & V_136 ) ) {
goto V_456;
}
F_1 ( V_22 -> V_33 , V_137 , & V_158 ) ;
F_1 ( V_22 -> V_33 , V_160 , & V_157 ) ;
if ( V_157 == 0xFFFFFFFF ) {
F_26 (KERN_WARNING DRV_NAME L_159 ) ;
goto V_456;
}
V_157 &= V_138 ;
if ( ! ( V_157 & V_158 ) ) {
goto V_456;
}
F_67 ( V_22 ) ;
F_177 ( & V_22 -> V_457 ) ;
F_178 ( & V_22 -> V_68 ) ;
return V_458 ;
V_456:
F_178 ( & V_22 -> V_68 ) ;
return V_455 ;
}
static T_7 F_179 ( struct V_459 * V_408 ,
struct V_1 * V_2 , int V_460 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
unsigned long V_62 ;
F_42 ( & V_22 -> V_68 , V_62 ) ;
if ( ! ( V_22 -> V_49 & V_166 ) ) {
F_30 ( L_160 ) ;
V_22 -> V_33 -> V_326 . V_461 ++ ;
F_37 ( V_2 ) ;
goto V_71;
}
if ( F_43 ( & V_22 -> V_409 ) )
goto V_71;
V_59 = V_22 -> V_409 . V_77 ;
V_61 = F_44 ( V_59 , struct V_60 , V_78 ) ;
V_61 -> V_81 . V_407 . V_408 = V_408 ;
F_164 ( L_161 , V_408 -> V_425 [ 0 ] -> V_13 ) ;
F_32 ( V_462 , V_408 -> V_425 [ 0 ] -> V_37 , V_408 -> V_425 [ 0 ] -> V_13 ) ;
V_61 -> V_79 = V_80 ;
F_45 ( V_59 ) ;
F_46 ( & V_22 -> V_410 ) ;
F_47 ( V_59 , & V_22 -> V_421 ) ;
F_48 ( & V_22 -> V_424 ) ;
F_50 ( V_22 ) ;
F_51 ( & V_22 -> V_68 , V_62 ) ;
return V_463 ;
V_71:
F_37 ( V_2 ) ;
F_51 ( & V_22 -> V_68 , V_62 ) ;
return V_464 ;
}
static int F_180 ( struct V_21 * V_22 )
{
int V_18 , V_40 , V_63 = - V_31 ;
void * V_465 ;
T_8 V_466 ;
V_22 -> V_467 =
F_134 ( V_468 * sizeof( struct V_60 ) ,
V_240 ) ;
if ( ! V_22 -> V_467 ) {
F_26 (KERN_ERR DRV_NAME L_162
L_163 , priv->net_dev->name) ;
return - V_241 ;
}
for ( V_18 = 0 ; V_18 < V_468 ; V_18 ++ ) {
V_465 = F_181 ( V_22 -> V_259 ,
sizeof( struct V_302 ) , & V_466 ) ;
if ( ! V_465 ) {
F_26 (KERN_ERR DRV_NAME L_67
L_164
L_163 , priv->net_dev->name) ;
V_63 = - V_241 ;
break;
}
memset ( V_465 , 0 , sizeof( struct V_302 ) ) ;
V_22 -> V_467 [ V_18 ] . type = V_395 ;
V_22 -> V_467 [ V_18 ] . V_81 . V_82 . V_57 =
(struct V_302 * ) V_465 ;
V_22 -> V_467 [ V_18 ] . V_81 . V_82 . V_415 = V_466 ;
}
if ( V_18 == V_468 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_18 ; V_40 ++ ) {
F_182 ( V_22 -> V_259 ,
sizeof( struct V_302 ) ,
V_22 -> V_467 [ V_40 ] . V_81 . V_82 . V_57 ,
V_22 -> V_467 [ V_40 ] . V_81 . V_82 .
V_415 ) ;
}
F_132 ( V_22 -> V_467 ) ;
V_22 -> V_467 = NULL ;
return V_63 ;
}
static int F_183 ( struct V_21 * V_22 )
{
int V_18 ;
F_184 ( & V_22 -> V_75 ) ;
F_184 ( & V_22 -> V_91 ) ;
for ( V_18 = 0 ; V_18 < V_468 ; V_18 ++ )
F_47 ( & V_22 -> V_467 [ V_18 ] . V_78 , & V_22 -> V_75 ) ;
F_167 ( & V_22 -> V_90 , V_18 ) ;
return 0 ;
}
static void F_185 ( struct V_21 * V_22 )
{
int V_18 ;
if ( ! V_22 -> V_467 )
return;
for ( V_18 = 0 ; V_18 < V_468 ; V_18 ++ ) {
F_182 ( V_22 -> V_259 ,
sizeof( struct V_302 ) ,
V_22 -> V_467 [ V_18 ] . V_81 . V_82 . V_57 ,
V_22 -> V_467 [ V_18 ] . V_81 . V_82 .
V_415 ) ;
}
F_132 ( V_22 -> V_467 ) ;
V_22 -> V_467 = NULL ;
}
static T_9 F_186 ( struct V_469 * V_315 , struct V_470 * V_471 ,
char * V_14 )
{
struct V_259 * V_259 = F_107 ( V_315 , struct V_259 , V_2 ) ;
char * V_39 = V_14 ;
int V_18 , V_40 ;
T_1 V_4 ;
for ( V_18 = 0 ; V_18 < 16 ; V_18 ++ ) {
V_39 += sprintf ( V_39 , L_165 , V_18 * 16 ) ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 += 4 ) {
F_187 ( V_259 , V_18 * 16 + V_40 , & V_4 ) ;
V_39 += sprintf ( V_39 , L_166 , V_4 ) ;
}
V_39 += sprintf ( V_39 , L_167 ) ;
}
return V_39 - V_14 ;
}
static T_9 F_188 ( struct V_469 * V_315 , struct V_470 * V_471 ,
char * V_14 )
{
struct V_21 * V_466 = F_189 ( V_315 ) ;
return sprintf ( V_14 , L_168 , ( int ) V_466 -> V_187 ) ;
}
static T_9 F_190 ( struct V_469 * V_315 , struct V_470 * V_471 ,
char * V_14 )
{
struct V_21 * V_466 = F_189 ( V_315 ) ;
return sprintf ( V_14 , L_168 , ( int ) V_466 -> V_49 ) ;
}
static T_9 F_191 ( struct V_469 * V_315 , struct V_470 * V_471 ,
char * V_14 )
{
struct V_21 * V_466 = F_189 ( V_315 ) ;
return sprintf ( V_14 , L_168 , ( int ) V_466 -> V_472 ) ;
}
static T_9 F_192 ( struct V_469 * V_315 , struct V_470 * V_471 ,
char * V_14 )
{
int V_18 ;
struct V_21 * V_22 = F_189 ( V_315 ) ;
struct V_1 * V_2 = V_22 -> V_33 ;
char * V_39 = V_14 ;
T_1 V_4 = 0 ;
V_39 += sprintf ( V_39 , L_169 , L_170 ) ;
for ( V_18 = 0 ; V_18 < F_127 ( V_473 ) ; V_18 ++ ) {
F_1 ( V_2 , V_473 [ V_18 ] . V_7 , & V_4 ) ;
V_39 += sprintf ( V_39 , L_171 ,
V_473 [ V_18 ] . V_51 , V_473 [ V_18 ] . V_7 , V_4 ) ;
}
return V_39 - V_14 ;
}
static T_9 F_193 ( struct V_469 * V_315 , struct V_470 * V_471 ,
char * V_14 )
{
struct V_21 * V_22 = F_189 ( V_315 ) ;
struct V_1 * V_2 = V_22 -> V_33 ;
char * V_39 = V_14 ;
int V_18 ;
V_39 += sprintf ( V_39 , L_169 , L_172 ) ;
for ( V_18 = 0 ; V_18 < F_127 ( V_474 ) ; V_18 ++ ) {
T_3 V_475 ;
T_2 V_476 ;
T_1 V_477 ;
switch ( V_474 [ V_18 ] . V_478 ) {
case 1 :
F_18 ( V_2 , V_474 [ V_18 ] . V_7 , & V_475 ) ;
V_39 += sprintf ( V_39 , L_173 ,
V_474 [ V_18 ] . V_51 , V_474 [ V_18 ] . V_7 ,
V_475 ) ;
break;
case 2 :
F_16 ( V_2 , V_474 [ V_18 ] . V_7 , & V_476 ) ;
V_39 += sprintf ( V_39 , L_174 ,
V_474 [ V_18 ] . V_51 , V_474 [ V_18 ] . V_7 ,
V_476 ) ;
break;
case 4 :
F_14 ( V_2 , V_474 [ V_18 ] . V_7 , & V_477 ) ;
V_39 += sprintf ( V_39 , L_171 ,
V_474 [ V_18 ] . V_51 , V_474 [ V_18 ] . V_7 ,
V_477 ) ;
break;
}
}
return V_39 - V_14 ;
}
static T_9 F_194 ( struct V_469 * V_315 , struct V_470 * V_471 ,
char * V_14 )
{
struct V_21 * V_22 = F_189 ( V_315 ) ;
struct V_1 * V_2 = V_22 -> V_33 ;
static unsigned long V_479 = 0 ;
int V_13 = 0 ;
T_1 V_480 [ 4 ] ;
int V_18 ;
char line [ 81 ] ;
if ( V_479 >= 0x30000 )
V_479 = 0 ;
while ( V_13 < V_481 - 128 && V_479 < 0x30000 ) {
if ( V_22 -> V_309 [ 0 ] )
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ )
V_480 [ V_18 ] =
* ( T_1 * ) F_136 ( V_479 + V_18 * 4 ) ;
else
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ )
F_14 ( V_2 , V_479 + V_18 * 4 , & V_480 [ V_18 ] ) ;
if ( V_22 -> V_482 )
V_13 += sprintf ( V_14 + V_13 ,
L_175
L_175
L_175
L_175 ,
( ( T_3 * ) V_480 ) [ 0x0 ] ,
( ( T_3 * ) V_480 ) [ 0x1 ] ,
( ( T_3 * ) V_480 ) [ 0x2 ] ,
( ( T_3 * ) V_480 ) [ 0x3 ] ,
( ( T_3 * ) V_480 ) [ 0x4 ] ,
( ( T_3 * ) V_480 ) [ 0x5 ] ,
( ( T_3 * ) V_480 ) [ 0x6 ] ,
( ( T_3 * ) V_480 ) [ 0x7 ] ,
( ( T_3 * ) V_480 ) [ 0x8 ] ,
( ( T_3 * ) V_480 ) [ 0x9 ] ,
( ( T_3 * ) V_480 ) [ 0xa ] ,
( ( T_3 * ) V_480 ) [ 0xb ] ,
( ( T_3 * ) V_480 ) [ 0xc ] ,
( ( T_3 * ) V_480 ) [ 0xd ] ,
( ( T_3 * ) V_480 ) [ 0xe ] ,
( ( T_3 * ) V_480 ) [ 0xf ] ) ;
else
V_13 += sprintf ( V_14 + V_13 , L_19 ,
F_31 ( line , sizeof( line ) ,
( T_3 * ) V_480 , 16 , V_479 ) ) ;
V_479 += 16 ;
}
return V_13 ;
}
static T_9 F_195 ( struct V_469 * V_315 , struct V_470 * V_471 ,
const char * V_14 , T_4 V_36 )
{
struct V_21 * V_22 = F_189 ( V_315 ) ;
struct V_1 * V_2 = V_22 -> V_33 ;
const char * V_466 = V_14 ;
( void ) V_2 ;
if ( V_36 < 1 )
return V_36 ;
if ( V_466 [ 0 ] == '1' ||
( V_36 >= 2 && tolower ( V_466 [ 0 ] ) == 'o' && tolower ( V_466 [ 1 ] ) == 'n' ) ) {
F_30 ( L_176 ,
V_2 -> V_51 ) ;
V_22 -> V_482 = 1 ;
} else if ( V_466 [ 0 ] == '0' || ( V_36 >= 2 && tolower ( V_466 [ 0 ] ) == 'o' &&
tolower ( V_466 [ 1 ] ) == 'f' ) ) {
F_30 ( L_177 ,
V_2 -> V_51 ) ;
V_22 -> V_482 = 0 ;
} else if ( tolower ( V_466 [ 0 ] ) == 'r' ) {
F_30 ( L_178 , V_2 -> V_51 ) ;
F_131 ( V_22 ) ;
} else
F_30 ( L_179
L_180 , V_2 -> V_51 ) ;
return V_36 ;
}
static T_9 F_196 ( struct V_469 * V_315 , struct V_470 * V_471 ,
char * V_14 )
{
struct V_21 * V_22 = F_189 ( V_315 ) ;
T_1 V_4 = 0 ;
int V_13 = 0 ;
T_1 V_483 ;
static int V_479 = 0 ;
if ( V_22 -> V_49 & V_484 )
return 0 ;
if ( V_479 >= F_127 ( V_485 ) )
V_479 = 0 ;
while ( V_13 < V_481 - 128 && V_479 < F_127 ( V_485 ) ) {
V_483 = sizeof( T_1 ) ;
if ( F_25 ( V_22 , V_485 [ V_479 ] . V_394 , & V_4 ,
& V_483 ) )
V_13 += sprintf ( V_14 + V_13 , L_181 ,
V_485 [ V_479 ] . V_394 ,
V_485 [ V_479 ] . V_486 ) ;
else
V_13 += sprintf ( V_14 + V_13 , L_182 ,
V_485 [ V_479 ] . V_394 , V_4 ,
V_485 [ V_479 ] . V_486 ) ;
V_479 ++ ;
}
return V_13 ;
}
static T_9 F_197 ( struct V_469 * V_315 , struct V_470 * V_471 ,
char * V_14 )
{
struct V_21 * V_22 = F_189 ( V_315 ) ;
char * V_39 = V_14 ;
V_39 += sprintf ( V_39 , L_183 ,
V_22 -> V_443 , V_22 -> V_449 ,
V_22 -> V_447 , V_22 -> V_444 ) ;
V_39 += sprintf ( V_39 , L_184 , V_22 -> V_262 ) ;
V_39 += sprintf ( V_39 , L_185 , V_22 -> V_487 ) ;
#ifdef F_126
V_39 += sprintf ( V_39 , L_186 ,
V_22 -> V_309 [ 0 ] ? L_187 : L_188 ) ;
#endif
return V_39 - V_14 ;
}
static int F_198 ( struct V_21 * V_22 , T_1 V_312 )
{
int V_63 ;
if ( V_312 == V_22 -> V_150 -> V_198 )
return 0 ;
V_63 = F_87 ( V_22 ) ;
if ( V_63 ) {
F_26 (KERN_ERR DRV_NAME L_189 ,
priv->net_dev->name, err) ;
return V_63 ;
}
switch ( V_312 ) {
case V_426 :
V_22 -> V_33 -> type = V_221 ;
break;
case V_431 :
V_22 -> V_33 -> type = V_221 ;
break;
#ifdef F_157
case V_199 :
V_22 -> V_488 = V_22 -> V_150 -> V_198 ;
V_22 -> V_33 -> type = V_489 ;
break;
#endif
}
V_22 -> V_150 -> V_198 = V_312 ;
#ifdef F_60
V_120 . V_121 = 0 ;
#endif
F_26 ( V_214 L_190 , V_22 -> V_33 -> V_51 ) ;
V_22 -> V_47 = 0 ;
F_34 ( V_22 ) ;
return 0 ;
}
static T_9 F_199 ( struct V_469 * V_315 , struct V_470 * V_471 ,
char * V_14 )
{
struct V_21 * V_22 = F_189 ( V_315 ) ;
int V_13 = 0 ;
#define F_200 ( T_10 , T_11 ) len += sprintf(buf + len, # x ": %" y "\n", priv-> x)
if ( V_22 -> V_49 & V_166 )
V_13 += sprintf ( V_14 + V_13 , L_191 ,
F_35 () - V_22 -> V_282 ) ;
else
V_13 += sprintf ( V_14 + V_13 , L_192 ) ;
F_200 ( V_150 -> V_490 . V_491 [ V_22 -> V_150 -> V_490 . V_492 ] , L_193 ) ;
F_200 ( V_49 , L_194 ) ;
F_200 ( V_187 , L_194 ) ;
F_200 ( V_472 , L_194 ) ;
V_13 +=
sprintf ( V_14 + V_13 , L_195 ,
( unsigned long ) V_22 -> V_493 ) ;
F_200 ( V_69 , L_196 ) ;
F_200 ( V_181 , L_196 ) ;
F_200 ( V_215 , L_196 ) ;
F_200 ( V_76 , L_196 ) ;
F_200 ( V_424 . V_147 , L_196 ) ;
F_200 ( V_424 . V_494 , L_196 ) ;
F_200 ( V_410 . V_147 , L_196 ) ;
F_200 ( V_410 . V_495 , L_196 ) ;
F_200 ( V_90 . V_147 , L_196 ) ;
F_200 ( V_90 . V_495 , L_196 ) ;
F_200 ( V_92 . V_147 , L_196 ) ;
F_200 ( V_92 . V_494 , L_196 ) ;
F_200 ( V_401 . V_147 , L_196 ) ;
F_200 ( V_401 . V_494 , L_196 ) ;
F_200 ( V_414 . V_147 , L_196 ) ;
F_200 ( V_414 . V_495 , L_196 ) ;
F_200 ( V_150 -> V_296 , L_196 ) ;
F_200 ( V_47 , L_196 ) ;
return V_13 ;
}
static T_9 F_201 ( struct V_469 * V_315 , struct V_470 * V_471 ,
char * V_14 )
{
struct V_21 * V_22 = F_189 ( V_315 ) ;
char V_266 [ V_267 + 1 ] ;
T_3 V_271 [ V_231 ] ;
T_1 V_269 = 0 ;
char * V_39 = V_14 ;
unsigned int V_284 ;
int V_228 ;
if ( V_22 -> V_49 & V_484 )
return 0 ;
memset ( V_266 , 0 , sizeof( V_266 ) ) ;
memset ( V_271 , 0 , sizeof( V_271 ) ) ;
V_284 = V_267 ;
V_228 = F_25 ( V_22 , V_273 , V_266 , & V_284 ) ;
if ( V_228 )
F_30 ( L_46 ,
__LINE__ ) ;
V_284 = sizeof( V_271 ) ;
V_228 = F_25 ( V_22 , V_276 ,
V_271 , & V_284 ) ;
if ( V_228 )
F_30 ( L_46 ,
__LINE__ ) ;
V_284 = sizeof( T_1 ) ;
V_228 = F_25 ( V_22 , V_275 , & V_269 , & V_284 ) ;
if ( V_228 )
F_30 ( L_46 ,
__LINE__ ) ;
V_39 += sprintf ( V_39 , L_197 , V_266 ) ;
V_39 += sprintf ( V_39 , L_198 , V_271 ) ;
V_39 += sprintf ( V_39 , L_199 , V_269 ) ;
return V_39 - V_14 ;
}
static T_9 F_202 ( struct V_496 * V_315 , char * V_14 )
{
return sprintf ( V_14 , L_200 , V_44 ) ;
}
static T_9 F_203 ( struct V_496 * V_315 ,
const char * V_14 , T_4 V_36 )
{
char * V_466 = ( char * ) V_14 ;
T_1 V_4 ;
if ( V_466 [ 1 ] == 'x' || V_466 [ 1 ] == 'X' || V_466 [ 0 ] == 'x' || V_466 [ 0 ] == 'X' ) {
V_466 ++ ;
if ( V_466 [ 0 ] == 'x' || V_466 [ 0 ] == 'X' )
V_466 ++ ;
V_4 = F_204 ( V_466 , & V_466 , 16 ) ;
} else
V_4 = F_204 ( V_466 , & V_466 , 10 ) ;
if ( V_466 == V_14 )
F_30 ( L_201 , V_14 ) ;
else
V_44 = V_4 ;
return F_205 ( V_14 , V_36 ) ;
}
static T_9 F_206 ( struct V_469 * V_315 ,
struct V_470 * V_471 , char * V_14 )
{
struct V_21 * V_22 = F_189 ( V_315 ) ;
char * V_39 = V_14 ;
int V_18 ;
if ( V_22 -> V_69 )
V_39 += sprintf ( V_39 , L_200 , V_22 -> V_69 ) ;
else
V_39 += sprintf ( V_39 , L_202 ) ;
for ( V_18 = 1 ; V_18 <= V_169 ; V_18 ++ ) {
if ( ! V_22 -> V_167 [ ( V_22 -> V_168 - V_18 ) %
V_169 ] )
continue;
V_39 += sprintf ( V_39 , L_203 , V_18 ,
V_22 -> V_167 [ ( V_22 -> V_168 - V_18 ) %
V_169 ] ) ;
}
return V_39 - V_14 ;
}
static T_9 F_207 ( struct V_469 * V_315 ,
struct V_470 * V_471 , const char * V_14 ,
T_4 V_36 )
{
struct V_21 * V_22 = F_189 ( V_315 ) ;
F_34 ( V_22 ) ;
return V_36 ;
}
static T_9 F_208 ( struct V_469 * V_315 , struct V_470 * V_471 ,
char * V_14 )
{
struct V_21 * V_22 = F_189 ( V_315 ) ;
return sprintf ( V_14 , L_204 , V_22 -> V_150 -> V_497 ) ;
}
static T_9 F_209 ( struct V_469 * V_315 , struct V_470 * V_471 ,
const char * V_14 , T_4 V_36 )
{
struct V_21 * V_22 = F_189 ( V_315 ) ;
struct V_1 * V_2 = V_22 -> V_33 ;
char V_480 [] = L_205 ;
unsigned long V_13 =
( sizeof( V_480 ) - 1 ) > V_36 ? V_36 : sizeof( V_480 ) - 1 ;
unsigned long V_4 ;
char * V_466 = V_480 ;
( void ) V_2 ;
F_30 ( L_42 ) ;
strncpy ( V_480 , V_14 , V_13 ) ;
V_480 [ V_13 ] = 0 ;
if ( V_466 [ 1 ] == 'x' || V_466 [ 1 ] == 'X' || V_466 [ 0 ] == 'x' || V_466 [ 0 ] == 'X' ) {
V_466 ++ ;
if ( V_466 [ 0 ] == 'x' || V_466 [ 0 ] == 'X' )
V_466 ++ ;
V_4 = F_204 ( V_466 , & V_466 , 16 ) ;
} else
V_4 = F_204 ( V_466 , & V_466 , 10 ) ;
if ( V_466 == V_480 ) {
F_30 ( L_206 , V_2 -> V_51 ) ;
} else {
V_22 -> V_150 -> V_497 = V_4 ;
F_30 ( L_207 , V_22 -> V_150 -> V_497 ) ;
}
F_30 ( L_45 ) ;
return V_13 ;
}
static T_9 F_210 ( struct V_469 * V_315 , struct V_470 * V_471 ,
char * V_14 )
{
struct V_21 * V_22 = F_189 ( V_315 ) ;
int V_4 = ( ( V_22 -> V_49 & V_206 ) ? 0x1 : 0x0 ) |
( F_70 ( V_22 ) ? 0x2 : 0x0 ) ;
return sprintf ( V_14 , L_208 , V_4 ) ;
}
static int F_211 ( struct V_21 * V_22 , int V_498 )
{
if ( ( V_498 ? 1 : 0 ) ==
( V_22 -> V_49 & V_206 ? 1 : 0 ) )
return 0 ;
F_212 ( L_209 ,
V_498 ? L_210 : L_211 ) ;
F_83 ( & V_22 -> V_264 ) ;
if ( V_498 ) {
V_22 -> V_49 |= V_206 ;
F_98 ( V_22 ) ;
} else {
V_22 -> V_49 &= ~ V_206 ;
if ( F_70 ( V_22 ) ) {
F_212 ( L_212
L_213 ) ;
V_22 -> V_215 = 0 ;
F_88 ( & V_22 -> V_216 ) ;
F_38 ( & V_22 -> V_216 ,
F_96 ( V_53 ) ) ;
} else
F_34 ( V_22 ) ;
}
F_84 ( & V_22 -> V_264 ) ;
return 1 ;
}
static T_9 F_213 ( struct V_469 * V_315 , struct V_470 * V_471 ,
const char * V_14 , T_4 V_36 )
{
struct V_21 * V_22 = F_189 ( V_315 ) ;
F_211 ( V_22 , V_14 [ 0 ] == '1' ) ;
return V_36 ;
}
static int F_214 ( struct V_21 * V_22 , int V_379 )
{
struct V_373 * V_499 = & V_22 -> V_320 ;
F_30 ( L_42 ) ;
V_499 -> V_478 = V_379 * sizeof( struct V_319 ) ;
V_499 -> V_321 =
(struct V_319 * ) F_181 ( V_22 -> V_259 ,
V_499 -> V_478 , & V_499 -> V_402 ) ;
if ( ! V_499 -> V_321 ) {
F_155 ( L_214 ) ;
return - V_241 ;
}
memset ( V_499 -> V_321 , 0 , V_499 -> V_478 ) ;
F_30 ( L_45 ) ;
return 0 ;
}
static void F_215 ( struct V_21 * V_22 )
{
F_30 ( L_42 ) ;
if ( V_22 -> V_320 . V_321 ) {
F_182 ( V_22 -> V_259 , V_22 -> V_320 . V_478 ,
V_22 -> V_320 . V_321 ,
V_22 -> V_320 . V_402 ) ;
V_22 -> V_320 . V_321 = NULL ;
}
F_30 ( L_45 ) ;
}
static int F_216 ( struct V_21 * V_22 ,
struct V_371 * V_499 , int V_379 )
{
F_30 ( L_42 ) ;
memset ( V_499 , 0 , sizeof( struct V_371 ) ) ;
V_499 -> V_379 = V_379 ;
V_499 -> V_478 = V_379 * sizeof( struct V_388 ) ;
V_499 -> V_321 = F_181 ( V_22 -> V_259 , V_499 -> V_478 , & V_499 -> V_402 ) ;
if ( ! V_499 -> V_321 ) {
F_30
( L_215 ) ;
return - V_241 ;
}
memset ( V_499 -> V_321 , 0 , V_499 -> V_478 ) ;
F_30 ( L_45 ) ;
return 0 ;
}
static void F_217 ( struct V_21 * V_22 , struct V_371 * V_499 )
{
F_30 ( L_42 ) ;
if ( ! V_499 )
return;
if ( V_499 -> V_321 ) {
F_182 ( V_22 -> V_259 , V_499 -> V_478 , V_499 -> V_321 , V_499 -> V_402 ) ;
V_499 -> V_321 = NULL ;
}
F_30 ( L_45 ) ;
}
static void F_218 ( struct V_21 * V_22 ,
struct V_371 * V_499 , T_1 V_500 , T_1 V_478 ,
T_1 V_109 , T_1 V_375 )
{
F_30 ( L_42 ) ;
F_30 ( L_216 , V_499 -> V_321 ,
( T_1 ) V_499 -> V_402 ) ;
F_4 ( V_22 -> V_33 , V_500 , V_499 -> V_402 ) ;
F_4 ( V_22 -> V_33 , V_478 , V_499 -> V_379 ) ;
F_4 ( V_22 -> V_33 , V_109 , V_499 -> V_396 ) ;
F_4 ( V_22 -> V_33 , V_375 , V_499 -> V_77 ) ;
F_30 ( L_45 ) ;
}
static void F_219 ( struct V_21 * V_22 )
{
V_22 -> V_215 = 1 ;
V_22 -> V_181 = 1 ;
F_220 ( & V_22 -> V_52 ) ;
F_220 ( & V_22 -> V_292 ) ;
F_220 ( & V_22 -> V_283 ) ;
F_220 ( & V_22 -> V_182 ) ;
F_220 ( & V_22 -> V_216 ) ;
F_221 ( & V_22 -> V_295 ) ;
F_220 ( & V_22 -> V_294 ) ;
}
static int F_222 ( struct V_21 * V_22 )
{
int V_18 , V_40 , V_63 = - V_31 ;
void * V_465 ;
T_8 V_466 ;
F_30 ( L_42 ) ;
V_63 = F_216 ( V_22 , & V_22 -> V_387 , V_501 ) ;
if ( V_63 ) {
F_61 ( L_217 ,
V_22 -> V_33 -> V_51 ) ;
return V_63 ;
}
V_22 -> V_502 =
F_134 ( V_503 * sizeof( struct V_60 ) ,
V_310 ) ;
if ( ! V_22 -> V_502 ) {
F_26 (KERN_ERR DRV_NAME
L_218 ,
priv->net_dev->name) ;
F_217 ( V_22 , & V_22 -> V_387 ) ;
return - V_241 ;
}
for ( V_18 = 0 ; V_18 < V_503 ; V_18 ++ ) {
V_465 = F_181 ( V_22 -> V_259 ,
sizeof( struct V_418 ) ,
& V_466 ) ;
if ( ! V_465 ) {
F_26 (KERN_ERR DRV_NAME
L_219 L_163 ,
priv->net_dev->name) ;
V_63 = - V_241 ;
break;
}
V_22 -> V_502 [ V_18 ] . type = V_397 ;
V_22 -> V_502 [ V_18 ] . V_81 . V_407 . V_37 =
(struct V_418 * ) V_465 ;
V_22 -> V_502 [ V_18 ] . V_81 . V_407 . V_439 = V_466 ;
V_22 -> V_502 [ V_18 ] . V_81 . V_407 . V_408 = NULL ;
}
if ( V_18 == V_503 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_18 ; V_40 ++ ) {
F_182 ( V_22 -> V_259 ,
sizeof( struct V_418 ) ,
V_22 -> V_502 [ V_40 ] . V_81 . V_407 . V_37 ,
V_22 -> V_502 [ V_40 ] . V_81 . V_407 .
V_439 ) ;
}
F_132 ( V_22 -> V_502 ) ;
V_22 -> V_502 = NULL ;
return V_63 ;
}
static void F_223 ( struct V_21 * V_22 )
{
int V_18 ;
F_30 ( L_42 ) ;
F_184 ( & V_22 -> V_393 ) ;
F_224 ( & V_22 -> V_401 ) ;
F_184 ( & V_22 -> V_421 ) ;
F_184 ( & V_22 -> V_409 ) ;
F_224 ( & V_22 -> V_424 ) ;
F_224 ( & V_22 -> V_410 ) ;
for ( V_18 = 0 ; V_18 < V_503 ; V_18 ++ ) {
if ( V_22 -> V_502 [ V_18 ] . V_81 . V_407 . V_408 ) {
F_165 ( V_22 -> V_502 [ V_18 ] . V_81 . V_407 .
V_408 ) ;
V_22 -> V_502 [ V_18 ] . V_81 . V_407 . V_408 = NULL ;
}
F_47 ( & V_22 -> V_502 [ V_18 ] . V_78 , & V_22 -> V_409 ) ;
}
F_167 ( & V_22 -> V_410 , V_18 ) ;
V_22 -> V_387 . V_396 = 0 ;
V_22 -> V_387 . V_413 = V_22 -> V_387 . V_379 ;
V_22 -> V_387 . V_77 = 0 ;
F_224 ( & V_22 -> V_414 ) ;
F_167 ( & V_22 -> V_414 , V_22 -> V_387 . V_413 ) ;
F_218 ( V_22 , & V_22 -> V_387 ,
V_504 ,
V_505 ,
V_399 ,
V_400 ) ;
F_30 ( L_45 ) ;
}
static void F_225 ( struct V_21 * V_22 )
{
int V_18 ;
F_30 ( L_42 ) ;
F_217 ( V_22 , & V_22 -> V_387 ) ;
if ( ! V_22 -> V_502 )
return;
for ( V_18 = 0 ; V_18 < V_503 ; V_18 ++ ) {
if ( V_22 -> V_502 [ V_18 ] . V_81 . V_407 . V_408 ) {
F_165 ( V_22 -> V_502 [ V_18 ] . V_81 . V_407 .
V_408 ) ;
V_22 -> V_502 [ V_18 ] . V_81 . V_407 . V_408 = NULL ;
}
if ( V_22 -> V_502 [ V_18 ] . V_81 . V_407 . V_37 )
F_182 ( V_22 -> V_259 ,
sizeof( struct V_418 ) ,
V_22 -> V_502 [ V_18 ] . V_81 . V_407 .
V_37 ,
V_22 -> V_502 [ V_18 ] . V_81 . V_407 .
V_439 ) ;
}
F_132 ( V_22 -> V_502 ) ;
V_22 -> V_502 = NULL ;
F_30 ( L_45 ) ;
}
static int F_226 ( struct V_21 * V_22 )
{
int V_18 , V_40 , V_63 = - V_31 ;
F_30 ( L_42 ) ;
V_63 = F_216 ( V_22 , & V_22 -> V_336 , V_324 ) ;
if ( V_63 ) {
F_30 ( L_220 ) ;
return V_63 ;
}
V_63 = F_214 ( V_22 , V_324 ) ;
if ( V_63 ) {
F_30 ( L_221 ) ;
F_217 ( V_22 , & V_22 -> V_336 ) ;
return V_63 ;
}
V_22 -> V_329 = F_134 ( V_324 *
sizeof( struct V_303 ) ,
V_240 ) ;
if ( ! V_22 -> V_329 ) {
F_30 ( L_222 ) ;
F_217 ( V_22 , & V_22 -> V_336 ) ;
F_215 ( V_22 ) ;
return - V_241 ;
}
for ( V_18 = 0 ; V_18 < V_324 ; V_18 ++ ) {
struct V_303 * V_61 = & V_22 -> V_329 [ V_18 ] ;
V_63 = F_128 ( V_22 , V_61 ) ;
if ( F_141 ( V_63 ) ) {
V_63 = - V_241 ;
break;
}
V_22 -> V_336 . V_321 [ V_18 ] . V_337 = V_61 -> V_307 ;
V_22 -> V_336 . V_321 [ V_18 ] . V_403 = V_334 ;
V_22 -> V_320 . V_321 [ V_18 ] . V_355 = 0 ;
}
if ( V_18 == V_324 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_18 ; V_40 ++ ) {
F_145 ( V_22 -> V_259 , V_22 -> V_329 [ V_40 ] . V_307 ,
sizeof( struct V_303 ) ,
V_308 ) ;
F_227 ( V_22 -> V_329 [ V_40 ] . V_304 ) ;
}
F_132 ( V_22 -> V_329 ) ;
V_22 -> V_329 = NULL ;
F_217 ( V_22 , & V_22 -> V_336 ) ;
F_215 ( V_22 ) ;
return V_63 ;
}
static void F_228 ( struct V_21 * V_22 )
{
F_30 ( L_42 ) ;
V_22 -> V_336 . V_396 = 0 ;
V_22 -> V_336 . V_413 = V_22 -> V_336 . V_379 - 1 ;
V_22 -> V_336 . V_77 = V_22 -> V_336 . V_379 - 1 ;
F_224 ( & V_22 -> V_506 ) ;
F_167 ( & V_22 -> V_506 , V_22 -> V_336 . V_413 ) ;
F_218 ( V_22 , & V_22 -> V_336 ,
V_507 ,
V_508 ,
V_377 ,
V_378 ) ;
F_4 ( V_22 -> V_33 , V_509 ,
V_22 -> V_320 . V_402 ) ;
F_30 ( L_45 ) ;
}
static void F_229 ( struct V_21 * V_22 )
{
int V_18 ;
F_30 ( L_42 ) ;
F_217 ( V_22 , & V_22 -> V_336 ) ;
F_215 ( V_22 ) ;
if ( ! V_22 -> V_329 )
return;
for ( V_18 = 0 ; V_18 < V_324 ; V_18 ++ ) {
if ( V_22 -> V_329 [ V_18 ] . V_306 ) {
F_145 ( V_22 -> V_259 ,
V_22 -> V_329 [ V_18 ] . V_307 ,
sizeof( struct V_305 ) ,
V_308 ) ;
F_227 ( V_22 -> V_329 [ V_18 ] . V_304 ) ;
}
}
F_132 ( V_22 -> V_329 ) ;
V_22 -> V_329 = NULL ;
F_30 ( L_45 ) ;
}
static int F_230 ( struct V_21 * V_22 )
{
T_1 V_284 = V_231 ;
T_3 V_7 [ V_231 ] ;
int V_63 ;
V_63 = F_25 ( V_22 , V_510 , V_7 , & V_284 ) ;
if ( V_63 ) {
F_30 ( L_223 ) ;
return - V_70 ;
}
memcpy ( V_22 -> V_33 -> V_511 , V_7 , V_231 ) ;
F_30 ( L_224 , V_22 -> V_33 -> V_511 ) ;
return 0 ;
}
static int F_231 ( struct V_21 * V_22 , int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_512 ,
. V_88 = 0 ,
. V_65 = V_231
} ;
int V_63 ;
F_41 ( L_225 ) ;
F_30 ( L_42 ) ;
if ( V_22 -> V_187 & V_513 ) {
memcpy ( V_57 . V_67 , V_22 -> V_230 , V_231 ) ;
memcpy ( V_22 -> V_33 -> V_511 , V_22 -> V_230 , V_231 ) ;
} else
memcpy ( V_57 . V_67 , V_22 -> V_33 -> V_511 ,
V_231 ) ;
V_63 = F_40 ( V_22 , & V_57 ) ;
F_30 ( L_45 ) ;
return V_63 ;
}
static int F_232 ( struct V_21 * V_22 , T_1 V_514 ,
int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_515 ,
. V_88 = 0 ,
. V_65 = sizeof( T_1 )
} ;
int V_63 ;
switch ( V_514 ) {
case V_426 :
V_57 . V_67 [ 0 ] = V_516 ;
break;
case V_431 :
V_57 . V_67 [ 0 ] = V_517 ;
break;
}
F_41 ( L_226 ,
V_514 == V_517 ? L_227 : L_228 ) ;
if ( ! V_285 ) {
V_63 = F_87 ( V_22 ) ;
if ( V_63 ) {
F_26 (KERN_ERR DRV_NAME
L_189 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( ! V_285 )
F_82 ( V_22 ) ;
return V_63 ;
}
static int F_233 ( struct V_21 * V_22 , T_1 V_246 ,
int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_518 ,
. V_88 = 0 ,
. V_65 = sizeof( T_1 )
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_246 ;
F_41 ( L_229 , V_246 ) ;
if ( V_22 -> V_150 -> V_198 == V_426 )
return 0 ;
if ( ( V_246 != 0 ) &&
( ( V_246 < V_519 ) || ( V_246 > V_520 ) ) )
return - V_31 ;
if ( ! V_285 ) {
V_63 = F_87 ( V_22 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( V_63 ) {
F_30 ( L_230 , V_246 ) ;
return V_63 ;
}
if ( V_246 )
V_22 -> V_187 |= V_521 ;
else
V_22 -> V_187 &= ~ V_521 ;
V_22 -> V_246 = V_246 ;
if ( ! V_285 ) {
V_63 = F_82 ( V_22 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static int F_234 ( struct V_21 * V_22 , int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_522 ,
. V_88 = 0 ,
. V_65 = 12 ,
} ;
T_1 V_523 , V_13 = sizeof( T_1 ) ;
int V_63 ;
if ( ! V_285 ) {
V_63 = F_87 ( V_22 ) ;
if ( V_63 )
return V_63 ;
}
if ( V_22 -> V_150 -> V_198 == V_431 )
V_57 . V_67 [ 0 ] |= V_524 ;
V_57 . V_67 [ 0 ] |= V_525 |
V_526 | V_527 ;
if ( ! ( V_22 -> V_187 & V_528 ) )
V_57 . V_67 [ 0 ] |= V_529 ;
V_63 = F_25 ( V_22 ,
V_530 ,
& V_523 , & V_13 ) ;
if ( V_63 )
V_523 = V_531 ;
V_57 . V_67 [ 1 ] = V_532 ;
V_57 . V_67 [ 2 ] = V_532 & V_523 ;
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( V_63 )
return V_63 ;
#if ! F_235 ( V_533 ) && ! F_235 ( V_534 )
V_57 . V_56 = V_535 ;
V_57 . V_88 = 0 ;
V_57 . V_65 = 0 ;
F_40 ( V_22 , & V_57 ) ;
#endif
if ( ! V_285 ) {
V_63 = F_82 ( V_22 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static int F_236 ( struct V_21 * V_22 , T_1 V_536 ,
int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_537 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_536 & V_538 ;
if ( ! V_285 ) {
V_63 = F_87 ( V_22 ) ;
if ( V_63 )
return V_63 ;
}
F_40 ( V_22 , & V_57 ) ;
V_57 . V_56 = V_539 ;
F_40 ( V_22 , & V_57 ) ;
V_57 . V_56 = V_540 ;
F_40 ( V_22 , & V_57 ) ;
if ( ! V_285 ) {
V_63 = F_82 ( V_22 ) ;
if ( V_63 )
return V_63 ;
}
V_22 -> V_541 = V_536 ;
return 0 ;
}
static int F_237 ( struct V_21 * V_22 , int V_542 )
{
struct V_56 V_57 = {
. V_56 = V_543 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_542 ;
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( V_63 )
return V_63 ;
if ( V_542 == V_544 )
V_22 -> V_545 = F_238 ( V_22 -> V_545 ) ;
else
V_22 -> V_545 = V_546 | V_542 ;
#ifdef F_239
if ( V_22 -> V_514 == V_547 && V_22 -> V_548 != V_549 ) {
V_57 . V_56 = V_550 ;
V_57 . V_67 [ 0 ] = ( T_1 ) V_22 -> V_548 ;
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( V_63 )
return V_63 ;
}
#endif
return 0 ;
}
static int F_240 ( struct V_21 * V_22 , T_1 V_551 )
{
struct V_56 V_57 = {
. V_56 = V_552 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
if ( V_551 & V_553 )
V_57 . V_67 [ 0 ] = V_554 ;
else
V_57 . V_67 [ 0 ] = V_551 & ~ V_553 ;
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_22 -> V_555 = V_551 ;
return 0 ;
}
static int F_241 ( struct V_21 * V_22 , T_1 V_556 )
{
struct V_56 V_57 = {
. V_56 = V_557 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_556 ;
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_22 -> V_558 = V_556 ;
return 0 ;
}
static int F_242 ( struct V_21 * V_22 , T_1 V_556 )
{
struct V_56 V_57 = {
. V_56 = V_559 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_556 ;
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_22 -> V_560 = V_556 ;
return 0 ;
}
static int F_243 ( struct V_21 * V_22 , T_3 * V_271 ,
int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_561 ,
. V_88 = 0 ,
. V_65 = ( V_271 == NULL ) ? 0 : V_231
} ;
int V_63 ;
#ifdef F_126
if ( V_271 != NULL )
F_41 ( L_231 , V_271 ) ;
else
F_41 ( L_232 ) ;
#endif
if ( V_271 != NULL )
memcpy ( V_57 . V_67 , V_271 , V_231 ) ;
if ( ! V_285 ) {
V_63 = F_87 ( V_22 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( ! V_285 )
F_82 ( V_22 ) ;
return V_63 ;
}
static int F_244 ( struct V_21 * V_22 )
{
struct V_56 V_57 = {
. V_56 = V_562 ,
. V_88 = 0 ,
. V_65 = V_231
} ;
int V_63 ;
int V_13 ;
F_41 ( L_233 ) ;
V_13 = V_231 ;
memcpy ( V_57 . V_67 , V_22 -> V_271 , V_231 ) ;
V_63 = F_40 ( V_22 , & V_57 ) ;
return V_63 ;
}
static int F_245 ( struct V_21 * V_22 ,
struct V_563 * V_564 ,
int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_565 ,
. V_88 = 0 ,
. V_65 = sizeof( struct V_563 ) ,
} ;
int V_63 ;
F_41 ( L_234 ) ;
if ( ! V_285 ) {
V_63 = F_87 ( V_22 ) ;
if ( V_63 )
return V_63 ;
}
memcpy ( V_57 . V_67 , V_564 ,
sizeof( struct V_563 ) ) ;
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( ! V_285 ) {
if ( F_82 ( V_22 ) )
V_63 = - V_70 ;
}
return V_63 ;
}
static int F_246 ( struct V_21 * V_22 ,
int V_566 ,
int V_567 ,
int V_568 ,
int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_569 ,
. V_88 = 0 ,
. V_65 = sizeof(struct V_570 )
} ;
struct V_570 * V_571 =
(struct V_570 * ) & V_57 . V_67 ;
int V_63 ;
memset ( V_571 , 0 , sizeof( * V_571 ) ) ;
V_571 -> V_566 = V_566 ;
V_571 -> V_568 = V_568 ;
switch ( V_567 ) {
default:
case V_572 :
V_571 -> V_573 = V_574 ;
break;
case V_575 :
V_571 -> V_573 = V_576 |
V_577 ;
break;
case V_578 :
V_571 -> V_573 = V_576 |
V_577 | V_579 ;
break;
case V_580 :
V_571 -> V_573 = V_576 |
V_577 | V_581 ;
break;
case V_582 :
V_571 -> V_573 = V_576 |
V_577 | V_579 | V_583 ;
break;
}
F_41
( L_235 ,
V_571 -> V_566 , V_571 -> V_573 , V_567 ) ;
V_571 -> V_584 = 0 ;
if ( ! V_285 ) {
V_63 = F_87 ( V_22 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( ! V_285 )
F_82 ( V_22 ) ;
return V_63 ;
}
static int F_247 ( struct V_21 * V_22 , T_1 V_585 )
{
struct V_56 V_57 = {
. V_56 = V_550 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 = 0 ;
T_1 V_313 = V_585 ;
if ( V_585 != V_586 )
V_313 = ( V_585 - V_587 ) * 16 /
( V_588 - V_587 ) ;
V_57 . V_67 [ 0 ] = V_313 ;
if ( V_22 -> V_150 -> V_198 == V_431 )
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( ! V_63 )
V_22 -> V_585 = V_585 ;
return 0 ;
}
static int F_248 ( struct V_21 * V_22 ,
T_1 V_589 , int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_590 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_589 ;
F_30 ( L_42 ) ;
if ( V_22 -> V_150 -> V_198 == V_431 ) {
if ( ! V_285 ) {
V_63 = F_87 ( V_22 ) ;
if ( V_63 )
return V_63 ;
}
F_40 ( V_22 , & V_57 ) ;
if ( ! V_285 ) {
V_63 = F_82 ( V_22 ) ;
if ( V_63 )
return V_63 ;
}
}
F_30 ( L_45 ) ;
return 0 ;
}
static void F_76 ( struct V_21 * V_22 )
{
F_223 ( V_22 ) ;
F_228 ( V_22 ) ;
F_183 ( V_22 ) ;
}
static void F_249 ( struct V_21 * V_22 )
{
F_225 ( V_22 ) ;
F_229 ( V_22 ) ;
F_185 ( V_22 ) ;
}
static int F_250 ( struct V_21 * V_22 )
{
if ( F_222 ( V_22 ) ||
F_226 ( V_22 ) || F_180 ( V_22 ) )
goto V_123;
return 0 ;
V_123:
F_225 ( V_22 ) ;
F_229 ( V_22 ) ;
F_185 ( V_22 ) ;
return - V_241 ;
}
static int F_251 ( struct V_21 * V_22 , T_1 V_62 ,
int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_591 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_62 ;
F_41 ( L_236 , V_62 ) ;
if ( ! V_285 ) {
V_63 = F_87 ( V_22 ) ;
if ( V_63 ) {
F_26 (KERN_ERR DRV_NAME
L_189 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( ! V_285 )
F_82 ( V_22 ) ;
return V_63 ;
}
static int F_252 ( struct V_21 * V_22 ,
int V_592 , char * V_593 , int V_13 , int V_285 )
{
int V_594 = V_13 ? ( V_13 <= 5 ? 5 : 13 ) : 0 ;
struct V_56 V_57 = {
. V_56 = V_595 ,
. V_88 = 0 ,
. V_65 = sizeof( struct V_596 ) ,
} ;
struct V_596 * V_597 = ( void * ) V_57 . V_67 ;
int V_63 ;
F_41 ( L_237 ,
V_592 , V_594 , V_13 ) ;
V_597 -> V_592 = V_592 ;
V_597 -> V_13 = V_594 ;
if ( V_594 ) {
memcpy ( V_597 -> V_593 , V_593 , V_13 ) ;
memset ( V_597 -> V_593 + V_13 , 0 , V_594 - V_13 ) ;
}
if ( V_594 == 0 )
F_253 ( L_238 ,
V_22 -> V_33 -> V_51 , V_597 -> V_592 ) ;
else if ( V_594 == 5 )
F_253 ( L_239 V_598 L_167 ,
V_22 -> V_33 -> V_51 , V_597 -> V_592 , V_597 -> V_13 ,
F_254 ( V_597 -> V_593 ) ) ;
else
F_253 ( L_239 V_599
L_167 ,
V_22 -> V_33 -> V_51 , V_597 -> V_592 , V_597 -> V_13 ,
F_255 ( V_597 -> V_593 ) ) ;
if ( ! V_285 ) {
V_63 = F_87 ( V_22 ) ;
if ( V_63 ) {
F_26 (KERN_ERR DRV_NAME
L_189 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( ! V_285 ) {
int V_600 = F_82 ( V_22 ) ;
if ( V_63 == 0 )
V_63 = V_600 ;
}
return V_63 ;
}
static int F_256 ( struct V_21 * V_22 ,
int V_592 , int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_601 ,
. V_88 = 0 ,
. V_65 = 4 ,
. V_67 = { V_592 } ,
} ;
int V_63 ;
F_41 ( L_240 , V_592 ) ;
if ( V_592 < 0 || V_592 > 3 )
return - V_31 ;
if ( ! V_285 ) {
V_63 = F_87 ( V_22 ) ;
if ( V_63 ) {
F_26 (KERN_ERR DRV_NAME
L_189 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_40 ( V_22 , & V_57 ) ;
if ( ! V_285 )
F_82 ( V_22 ) ;
return V_63 ;
}
static int F_257 ( struct V_21 * V_22 , int V_285 )
{
int V_18 , V_63 , V_566 , V_602 , V_603 ;
if ( ! ( V_22 -> V_49 & V_72 ) )
return 0 ;
if ( ! V_285 ) {
V_63 = F_87 ( V_22 ) ;
if ( V_63 )
return V_63 ;
}
if ( ! V_22 -> V_150 -> V_190 . V_192 ) {
V_63 =
F_246 ( V_22 , V_604 ,
V_572 , 0 , 1 ) ;
} else {
V_566 = V_604 ;
if ( V_22 -> V_150 -> V_190 . V_62 & V_605 ) {
if ( V_22 -> V_150 -> V_190 . V_566 == V_606 )
V_566 = V_607 ;
else if ( V_22 -> V_150 -> V_190 . V_566 == V_608 )
V_566 = V_609 ;
}
V_602 = V_572 ;
if ( V_22 -> V_150 -> V_190 . V_62 & V_610 )
V_602 = V_22 -> V_150 -> V_190 . V_43 ;
V_603 = 0 ;
if ( V_22 -> V_150 -> V_190 . V_62 & V_611 )
V_603 = V_22 -> V_150 -> V_190 . V_612 ;
V_63 =
F_246 ( V_22 , V_566 , V_602 ,
V_603 , 1 ) ;
}
if ( V_63 )
goto exit;
if ( V_22 -> V_150 -> V_190 . V_192 ) {
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
if ( ! ( V_22 -> V_150 -> V_190 . V_62 & ( 1 << V_18 ) ) ) {
memset ( V_22 -> V_150 -> V_190 . V_613 [ V_18 ] , 0 , V_614 ) ;
V_22 -> V_150 -> V_190 . V_615 [ V_18 ] = 0 ;
} else {
V_63 = F_252 ( V_22 , V_18 ,
V_22 -> V_150 -> V_190 . V_613 [ V_18 ] ,
V_22 -> V_150 -> V_190 .
V_615 [ V_18 ] , 1 ) ;
if ( V_63 )
goto exit;
}
}
F_256 ( V_22 , V_22 -> V_150 -> V_490 . V_492 , 1 ) ;
}
V_63 =
F_251 ( V_22 ,
V_22 -> V_150 -> V_190 .
V_192 ? V_616 : 0 , 1 ) ;
if ( V_63 )
goto exit;
V_22 -> V_49 &= ~ V_263 ;
exit:
if ( ! V_285 )
F_82 ( V_22 ) ;
return V_63 ;
}
static void F_258 ( struct V_260 * V_261 )
{
struct V_21 * V_22 =
F_107 ( V_261 , struct V_21 , V_292 . V_261 ) ;
if ( ! ( V_22 -> V_49 & V_166 ) &&
V_22 -> V_49 & V_263 )
F_257 ( V_22 , 0 ) ;
}
static void F_259 ( struct V_1 * V_2 ,
struct V_617 * V_190 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
int V_18 , V_618 = 0 ;
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) )
goto V_620;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
if ( V_190 -> V_62 & ( 1 << V_18 ) ) {
V_22 -> V_150 -> V_190 . V_615 [ V_18 ] = V_190 -> V_615 [ V_18 ] ;
if ( V_190 -> V_615 [ V_18 ] == 0 )
V_22 -> V_150 -> V_190 . V_62 &= ~ ( 1 << V_18 ) ;
else
memcpy ( V_22 -> V_150 -> V_190 . V_613 [ V_18 ] , V_190 -> V_613 [ V_18 ] ,
V_190 -> V_615 [ V_18 ] ) ;
if ( V_190 -> V_43 == V_575 ) {
V_22 -> V_150 -> V_190 . V_62 |= ( 1 << V_18 ) ;
V_22 -> V_49 |= V_263 ;
} else
V_22 -> V_150 -> V_190 . V_62 &= ~ ( 1 << V_18 ) ;
}
}
if ( ( V_190 -> V_62 & V_621 ) &&
V_22 -> V_150 -> V_190 . V_622 != V_190 -> V_622 ) {
if ( V_190 -> V_622 <= 3 ) {
V_22 -> V_150 -> V_190 . V_622 = V_190 -> V_622 ;
V_22 -> V_150 -> V_190 . V_62 |= V_621 ;
} else
V_22 -> V_150 -> V_190 . V_62 &= ~ V_621 ;
V_22 -> V_49 |= V_263 ;
}
if ( ( V_190 -> V_62 & V_605 ) &&
( V_22 -> V_150 -> V_190 . V_566 != V_190 -> V_566 ) ) {
V_22 -> V_150 -> V_190 . V_566 = V_190 -> V_566 ;
V_22 -> V_150 -> V_190 . V_62 |= V_605 ;
V_22 -> V_49 |= V_263 ;
}
if ( V_190 -> V_62 & V_191 && V_22 -> V_150 -> V_190 . V_192 != V_190 -> V_192 ) {
V_22 -> V_150 -> V_190 . V_62 |= V_191 ;
V_22 -> V_150 -> V_190 . V_192 = V_190 -> V_192 ;
V_22 -> V_49 |= V_263 ;
V_618 = 1 ;
}
if ( V_190 -> V_62 & V_623 )
V_22 -> V_150 -> V_190 . V_624 = V_190 -> V_624 ;
if ( V_190 -> V_62 & V_610 && V_22 -> V_150 -> V_190 . V_43 != V_190 -> V_43 ) {
V_22 -> V_150 -> V_190 . V_43 = V_190 -> V_43 ;
V_22 -> V_150 -> V_190 . V_62 |= V_610 ;
V_22 -> V_49 |= V_263 ;
}
F_253 ( L_241 ,
V_22 -> V_150 -> V_190 . V_62 & ( 1 << 8 ) ? '1' : '0' ,
V_22 -> V_150 -> V_190 . V_62 & ( 1 << 7 ) ? '1' : '0' ,
V_22 -> V_150 -> V_190 . V_62 & ( 1 << 6 ) ? '1' : '0' ,
V_22 -> V_150 -> V_190 . V_62 & ( 1 << 5 ) ? '1' : '0' ,
V_22 -> V_150 -> V_190 . V_62 & ( 1 << 4 ) ? '1' : '0' ,
V_22 -> V_150 -> V_190 . V_62 & ( 1 << 3 ) ? '1' : '0' ,
V_22 -> V_150 -> V_190 . V_62 & ( 1 << 2 ) ? '1' : '0' ,
V_22 -> V_150 -> V_190 . V_62 & ( 1 << 1 ) ? '1' : '0' ,
V_22 -> V_150 -> V_190 . V_62 & ( 1 << 0 ) ? '1' : '0' ) ;
if ( ! ( V_22 -> V_49 & ( V_166 | V_165 ) ) )
F_257 ( V_22 , 0 ) ;
V_620:
F_84 ( & V_22 -> V_264 ) ;
}
static int F_97 ( struct V_21 * V_22 )
{
int V_63 ;
int V_285 = 1 ;
T_3 * V_271 ;
F_30 ( L_42 ) ;
V_63 = F_87 ( V_22 ) ;
if ( V_63 )
return V_63 ;
#ifdef F_157
if ( V_22 -> V_150 -> V_198 == V_199 ) {
V_63 = F_233 ( V_22 , V_22 -> V_246 , V_285 ) ;
if ( V_63 )
return V_63 ;
F_30 ( L_45 ) ;
return 0 ;
}
#endif
V_63 = F_230 ( V_22 ) ;
if ( V_63 )
return - V_70 ;
V_63 = F_231 ( V_22 , V_285 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_232 ( V_22 , V_22 -> V_150 -> V_198 , V_285 ) ;
if ( V_63 )
return V_63 ;
if ( V_22 -> V_150 -> V_198 == V_431 ) {
V_63 = F_233 ( V_22 , V_22 -> V_246 , V_285 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_234 ( V_22 , V_285 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_236 ( V_22 , V_22 -> V_541 , V_285 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_237 ( V_22 , V_544 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_240 ( V_22 , V_22 -> V_555 ) ;
if ( V_63 )
return V_63 ;
if ( V_22 -> V_187 & V_625 )
V_271 = V_22 -> V_271 ;
else
V_271 = NULL ;
V_63 = F_243 ( V_22 , V_271 , V_285 ) ;
if ( V_63 )
return V_63 ;
if ( V_22 -> V_187 & V_281 )
V_63 = F_112 ( V_22 , V_22 -> V_266 , V_22 -> V_265 ,
V_285 ) ;
else
V_63 = F_112 ( V_22 , NULL , 0 , V_285 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_257 ( V_22 , V_285 ) ;
if ( V_63 )
return V_63 ;
if ( V_22 -> V_150 -> V_198 == V_431 ) {
V_63 =
F_248 ( V_22 ,
V_22 -> V_626 ,
V_285 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_247 ( V_22 , V_22 -> V_585 ) ;
if ( V_63 )
return V_63 ;
}
F_30 ( L_45 ) ;
return 0 ;
}
static int F_260 ( struct V_1 * V_2 , void * V_466 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
struct V_627 * V_7 = V_466 ;
int V_63 = 0 ;
if ( ! F_261 ( V_7 -> V_628 ) )
return - V_629 ;
F_83 ( & V_22 -> V_264 ) ;
V_22 -> V_187 |= V_513 ;
memcpy ( V_22 -> V_230 , V_7 -> V_628 , V_231 ) ;
V_63 = F_231 ( V_22 , 0 ) ;
if ( V_63 )
goto V_620;
V_22 -> V_47 = 0 ;
F_84 ( & V_22 -> V_264 ) ;
F_106 ( & V_22 -> V_52 . V_261 ) ;
return 0 ;
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_262 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
unsigned long V_62 ;
F_30 ( L_242 ) ;
F_42 ( & V_22 -> V_68 , V_62 ) ;
if ( V_22 -> V_49 & V_166 ) {
F_263 ( V_2 ) ;
F_264 ( V_2 ) ;
}
F_51 ( & V_22 -> V_68 , V_62 ) ;
return 0 ;
}
static int F_265 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
unsigned long V_62 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
F_30 ( L_42 ) ;
F_42 ( & V_22 -> V_68 , V_62 ) ;
if ( V_22 -> V_49 & V_166 )
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
while ( ! F_43 ( & V_22 -> V_421 ) ) {
V_59 = V_22 -> V_421 . V_77 ;
V_61 = F_44 ( V_59 , struct V_60 , V_78 ) ;
F_45 ( V_59 ) ;
F_46 ( & V_22 -> V_424 ) ;
F_165 ( V_61 -> V_81 . V_407 . V_408 ) ;
V_61 -> V_81 . V_407 . V_408 = NULL ;
F_47 ( V_59 , & V_22 -> V_409 ) ;
F_48 ( & V_22 -> V_410 ) ;
}
F_51 ( & V_22 -> V_68 , V_62 ) ;
F_30 ( L_45 ) ;
return 0 ;
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
V_2 -> V_326 . V_630 ++ ;
#ifdef F_157
if ( V_22 -> V_150 -> V_198 == V_199 )
return;
#endif
F_30 ( L_243 ,
V_2 -> V_51 ) ;
F_34 ( V_22 ) ;
}
static int F_267 ( struct V_21 * V_22 , int V_147 )
{
V_22 -> V_150 -> V_631 = V_147 ;
return 0 ;
}
static int F_268 ( struct V_21 * V_22 , int V_147 )
{
struct V_632 * V_150 = V_22 -> V_150 ;
struct V_617 V_190 = {
. V_62 = V_605 ,
} ;
int V_228 = 0 ;
if ( V_147 & V_633 ) {
V_190 . V_566 = V_606 ;
V_150 -> V_634 = 0 ;
} else if ( V_147 & V_635 ) {
V_190 . V_566 = V_636 ;
V_150 -> V_634 = 1 ;
} else if ( V_147 & V_637 ) {
V_190 . V_566 = V_608 ;
V_150 -> V_634 = 1 ;
} else
return - V_31 ;
if ( V_150 -> V_638 )
V_150 -> V_638 ( V_150 -> V_2 , & V_190 ) ;
else
V_228 = - V_639 ;
return V_228 ;
}
static void V_563 ( struct V_21 * V_22 ,
char * V_640 , int V_641 )
{
struct V_563 V_642 ;
V_642 . V_643 = 0 ;
memcpy ( V_642 . V_644 , V_640 , V_641 ) ;
V_642 . V_645 = V_641 ;
F_267 ( V_22 , 1 ) ;
F_245 ( V_22 , & V_642 , 0 ) ;
}
static void F_269 ( struct V_1 * V_2 ,
struct V_646 * V_81 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
char V_647 [ 64 ] , V_648 [ 64 ] ;
strcpy ( V_81 -> V_649 , V_650 ) ;
strcpy ( V_81 -> V_121 , V_651 ) ;
F_270 ( V_22 , V_647 , sizeof( V_647 ) ) ;
F_271 ( V_22 , V_648 , sizeof( V_648 ) ) ;
snprintf ( V_81 -> V_652 , sizeof( V_81 -> V_652 ) , L_244 ,
V_647 , V_22 -> V_156 , V_648 ) ;
strcpy ( V_81 -> V_653 , F_272 ( V_22 -> V_259 ) ) ;
}
static T_1 F_273 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
return ( V_22 -> V_49 & V_166 ) ? 1 : 0 ;
}
static void F_274 ( struct V_260 * V_261 )
{
struct V_21 * V_22 =
F_107 ( V_261 , struct V_21 , V_182 . V_261 ) ;
unsigned long V_62 ;
T_1 V_654 = 0xa5a5a5a5 ;
T_1 V_13 = sizeof( V_654 ) ;
int V_655 = 0 ;
F_42 ( & V_22 -> V_68 , V_62 ) ;
if ( V_22 -> V_69 != 0 ) {
F_30 ( L_245 ,
V_22 -> V_33 -> V_51 ) ;
V_655 = 1 ;
} else if ( F_25 ( V_22 , V_656 , & V_654 , & V_13 ) ||
( V_654 == V_22 -> V_493 ) ) {
F_30 ( L_246 ,
V_22 -> V_33 -> V_51 ) ;
V_655 = 1 ;
}
if ( V_655 ) {
V_22 -> V_181 = 1 ;
V_22 -> V_487 ++ ;
F_34 ( V_22 ) ;
}
V_22 -> V_493 = V_654 ;
if ( ! V_22 -> V_181 )
F_38 ( & V_22 -> V_182 , V_53 / 2 ) ;
F_51 ( & V_22 -> V_68 , V_62 ) ;
}
static void F_275 ( struct V_260 * V_261 )
{
struct V_21 * V_22 =
F_107 ( V_261 , struct V_21 , V_216 . V_261 ) ;
unsigned long V_62 ;
F_42 ( & V_22 -> V_68 , V_62 ) ;
if ( F_70 ( V_22 ) ) {
F_212 ( L_247 ) ;
if ( ! V_22 -> V_215 )
F_38 ( & V_22 -> V_216 ,
F_96 ( V_53 ) ) ;
goto V_657;
}
if ( ! ( V_22 -> V_49 & V_484 ) ) {
F_212 ( L_248
L_249 ) ;
F_34 ( V_22 ) ;
} else
F_212 ( L_250
L_251 ) ;
V_657:
F_51 ( & V_22 -> V_68 , V_62 ) ;
}
static struct V_1 * F_276 ( struct V_259 * V_259 ,
void V_5 * V_6 ,
unsigned long V_658 ,
unsigned long V_659 )
{
struct V_21 * V_22 ;
struct V_1 * V_2 ;
V_2 = F_277 ( sizeof( struct V_21 ) , 0 ) ;
if ( ! V_2 )
return NULL ;
V_22 = F_101 ( V_2 ) ;
V_22 -> V_150 = F_278 ( V_2 ) ;
V_22 -> V_259 = V_259 ;
V_22 -> V_33 = V_2 ;
V_22 -> V_150 -> V_660 = F_179 ;
V_22 -> V_150 -> V_638 = F_259 ;
V_22 -> V_150 -> V_661 = - 20 ;
V_22 -> V_150 -> V_662 = - 85 ;
V_2 -> V_663 = & V_664 ;
V_2 -> V_665 = & V_666 ;
V_2 -> V_667 = & V_668 ;
V_22 -> V_669 . V_670 = V_22 -> V_150 ;
V_2 -> V_669 = & V_22 -> V_669 ;
V_2 -> V_671 = 3 * V_53 ;
V_2 -> V_454 = 0 ;
V_2 -> V_6 = ( unsigned long ) V_6 ;
V_2 -> V_658 = V_658 ;
V_2 -> V_672 = V_2 -> V_658 + V_659 - 1 ;
V_22 -> V_545 = V_673 ;
#ifdef F_157
V_22 -> V_187 |= V_343 ;
#endif
V_22 -> V_150 -> V_631 = 0 ;
V_22 -> V_150 -> V_674 = 0 ;
V_22 -> V_150 -> V_675 = 0 ;
V_22 -> V_150 -> V_676 = 1 ;
switch ( V_677 ) {
case 1 :
V_22 -> V_150 -> V_198 = V_431 ;
break;
#ifdef F_157
case 2 :
V_22 -> V_150 -> V_198 = V_199 ;
break;
#endif
default:
case 0 :
V_22 -> V_150 -> V_198 = V_426 ;
break;
}
if ( V_678 == 1 )
V_22 -> V_49 |= V_206 ;
if ( V_246 != 0 &&
( ( V_246 >= V_519 ) && ( V_246 <= V_520 ) ) ) {
V_22 -> V_187 |= V_521 ;
V_22 -> V_246 = V_246 ;
}
if ( V_679 )
V_22 -> V_187 |= V_188 ;
V_22 -> V_626 = V_680 ;
V_22 -> V_558 = V_681 ;
V_22 -> V_560 = V_682 ;
V_22 -> V_555 = V_683 | V_553 ;
V_22 -> V_684 = V_685 | V_686 ;
V_22 -> V_585 = V_586 ;
V_22 -> V_541 = V_687 ;
strcpy ( V_22 -> V_688 , L_252 ) ;
F_279 ( & V_22 -> V_68 ) ;
F_280 ( & V_22 -> V_264 ) ;
F_280 ( & V_22 -> V_179 ) ;
F_281 ( & V_22 -> V_55 ) ;
F_36 ( V_2 ) ;
F_184 ( & V_22 -> V_75 ) ;
F_184 ( & V_22 -> V_91 ) ;
F_224 ( & V_22 -> V_90 ) ;
F_224 ( & V_22 -> V_92 ) ;
F_184 ( & V_22 -> V_409 ) ;
F_184 ( & V_22 -> V_421 ) ;
F_224 ( & V_22 -> V_410 ) ;
F_224 ( & V_22 -> V_424 ) ;
F_184 ( & V_22 -> V_393 ) ;
F_224 ( & V_22 -> V_401 ) ;
F_282 ( & V_22 -> V_52 , F_106 ) ;
F_282 ( & V_22 -> V_292 , F_258 ) ;
F_282 ( & V_22 -> V_283 , V_689 ) ;
F_282 ( & V_22 -> V_182 , F_274 ) ;
F_282 ( & V_22 -> V_216 , F_275 ) ;
F_283 ( & V_22 -> V_295 , F_118 ) ;
F_282 ( & V_22 -> V_294 , F_117 ) ;
F_284 ( & V_22 -> V_457 , ( void (*) ( unsigned long ) )
F_172 , ( unsigned long ) V_22 ) ;
V_22 -> V_215 = 1 ;
V_22 -> V_181 = 1 ;
return V_2 ;
}
static int F_285 ( struct V_259 * V_259 ,
const struct V_690 * V_691 )
{
unsigned long V_658 , V_659 , V_692 ;
void V_5 * V_6 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_21 * V_22 = NULL ;
int V_63 = 0 ;
int V_693 = 0 ;
T_1 V_4 ;
F_30 ( L_42 ) ;
V_658 = F_286 ( V_259 , 0 ) ;
V_659 = F_287 ( V_259 , 0 ) ;
V_692 = F_288 ( V_259 , 0 ) ;
if ( ( V_692 & V_694 ) != V_694 ) {
F_30 ( L_253 ) ;
V_63 = - V_695 ;
goto V_123;
}
V_6 = F_289 ( V_658 , V_659 ) ;
if ( ! V_6 ) {
F_26 (KERN_WARNING DRV_NAME
L_254 ) ;
V_63 = - V_70 ;
goto V_123;
}
V_2 = F_276 ( V_259 , V_6 , V_658 , V_659 ) ;
if ( ! V_2 ) {
F_26 (KERN_WARNING DRV_NAME
L_255 ) ;
V_63 = - V_241 ;
goto V_123;
}
V_63 = F_290 ( V_259 ) ;
if ( V_63 ) {
F_26 (KERN_WARNING DRV_NAME
L_256 ) ;
return V_63 ;
}
V_22 = F_101 ( V_2 ) ;
F_291 ( V_259 ) ;
F_292 ( V_259 , V_22 ) ;
V_63 = F_293 ( V_259 , F_294 ( 32 ) ) ;
if ( V_63 ) {
F_26 (KERN_WARNING DRV_NAME
L_257 ) ;
F_295 ( V_259 ) ;
return V_63 ;
}
V_63 = F_296 ( V_259 , V_650 ) ;
if ( V_63 ) {
F_26 (KERN_WARNING DRV_NAME
L_258 ) ;
F_295 ( V_259 ) ;
return V_63 ;
}
F_187 ( V_259 , 0x40 , & V_4 ) ;
if ( ( V_4 & 0x0000ff00 ) != 0 )
F_297 ( V_259 , 0x40 , V_4 & 0xffff00ff ) ;
F_298 ( V_259 , V_696 ) ;
if ( ! F_24 ( V_2 ) ) {
F_26 (KERN_WARNING DRV_NAME
L_259 ) ;
V_63 = - V_695 ;
goto V_123;
}
F_299 ( V_2 , & V_259 -> V_2 ) ;
V_22 -> V_49 |= V_136 ;
F_67 ( V_22 ) ;
if ( F_250 ( V_22 ) ) {
F_26 (KERN_WARNING DRV_NAME
L_260 ) ;
V_63 = - V_241 ;
goto V_123;
}
F_76 ( V_22 ) ;
V_63 = F_300 ( V_259 -> V_454 ,
F_175 , V_697 , V_2 -> V_51 , V_22 ) ;
if ( V_63 ) {
F_26 (KERN_WARNING DRV_NAME
L_261 , pci_dev->irq) ;
goto V_123;
}
V_2 -> V_454 = V_259 -> V_454 ;
F_30 ( L_262 ) ;
F_26 (KERN_INFO DRV_NAME
L_263 ) ;
V_63 = F_301 ( V_2 ) ;
if ( V_63 ) {
F_26 (KERN_WARNING DRV_NAME
L_264 ) ;
goto V_123;
}
F_83 ( & V_22 -> V_264 ) ;
V_693 = 1 ;
F_30 ( L_265 , V_2 -> V_51 , F_272 ( V_259 ) ) ;
V_63 = F_302 ( & V_259 -> V_2 . V_698 , & V_699 ) ;
if ( V_63 )
goto V_71;
if ( ! ( V_22 -> V_49 & V_484 ) ) {
if ( F_82 ( V_22 ) ) {
F_26 (KERN_WARNING DRV_NAME
L_266 ,
priv->net_dev->name) ;
F_85 ( V_22 ) ;
V_63 = - V_70 ;
goto V_71;
}
F_89 ( V_22 ) ;
F_91 ( V_22 ) ;
}
F_30 ( L_45 ) ;
V_22 -> V_49 |= V_619 ;
F_84 ( & V_22 -> V_264 ) ;
return 0 ;
V_71:
F_84 ( & V_22 -> V_264 ) ;
V_123:
if ( V_2 ) {
if ( V_693 )
F_303 ( V_2 ) ;
F_85 ( V_22 ) ;
F_67 ( V_22 ) ;
if ( V_2 -> V_454 )
F_304 ( V_2 -> V_454 , V_22 ) ;
F_219 ( V_22 ) ;
F_249 ( V_22 ) ;
F_305 ( & V_259 -> V_2 . V_698 ,
& V_699 ) ;
F_306 ( V_2 , 0 ) ;
F_292 ( V_259 , NULL ) ;
}
if ( V_6 )
F_307 ( V_6 ) ;
F_308 ( V_259 ) ;
F_295 ( V_259 ) ;
return V_63 ;
}
static void T_12 F_309 ( struct V_259 * V_259 )
{
struct V_21 * V_22 = F_310 ( V_259 ) ;
struct V_1 * V_2 ;
if ( V_22 ) {
F_83 ( & V_22 -> V_264 ) ;
V_22 -> V_49 &= ~ V_619 ;
V_2 = V_22 -> V_33 ;
F_305 ( & V_259 -> V_2 . V_698 ,
& V_699 ) ;
#ifdef F_60
if ( V_120 . V_121 )
F_65 ( V_22 , & V_120 ) ;
#endif
F_98 ( V_22 ) ;
F_84 ( & V_22 -> V_264 ) ;
F_303 ( V_2 ) ;
F_219 ( V_22 ) ;
F_249 ( V_22 ) ;
F_131 ( V_22 ) ;
if ( V_2 -> V_454 )
F_304 ( V_2 -> V_454 , V_22 ) ;
if ( V_2 -> V_6 )
F_307 ( ( void V_5 * ) V_2 -> V_6 ) ;
F_311 ( V_22 -> V_150 -> V_151 . V_152 ) ;
F_132 ( V_22 -> V_150 -> V_234 . V_238 ) ;
F_306 ( V_2 , 0 ) ;
}
F_308 ( V_259 ) ;
F_295 ( V_259 ) ;
F_30 ( L_45 ) ;
}
static int F_312 ( struct V_259 * V_259 , T_13 V_102 )
{
struct V_21 * V_22 = F_310 ( V_259 ) ;
struct V_1 * V_2 = V_22 -> V_33 ;
F_30 ( L_267 , V_2 -> V_51 ) ;
F_83 ( & V_22 -> V_264 ) ;
if ( V_22 -> V_49 & V_619 ) {
F_98 ( V_22 ) ;
}
F_313 ( V_2 ) ;
F_314 ( V_259 ) ;
F_295 ( V_259 ) ;
F_298 ( V_259 , V_700 ) ;
V_22 -> V_701 = F_35 () ;
F_84 ( & V_22 -> V_264 ) ;
return 0 ;
}
static int F_315 ( struct V_259 * V_259 )
{
struct V_21 * V_22 = F_310 ( V_259 ) ;
struct V_1 * V_2 = V_22 -> V_33 ;
int V_63 ;
T_1 V_4 ;
if ( V_702 )
return 0 ;
F_83 ( & V_22 -> V_264 ) ;
F_30 ( L_268 , V_2 -> V_51 ) ;
F_298 ( V_259 , V_696 ) ;
V_63 = F_290 ( V_259 ) ;
if ( V_63 ) {
F_26 ( V_703 L_269 ,
V_2 -> V_51 ) ;
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
F_316 ( V_259 ) ;
F_187 ( V_259 , 0x40 , & V_4 ) ;
if ( ( V_4 & 0x0000ff00 ) != 0 )
F_297 ( V_259 , 0x40 , V_4 & 0xffff00ff ) ;
F_317 ( V_2 ) ;
V_22 -> V_205 = F_35 () - V_22 -> V_701 ;
if ( ! ( V_22 -> V_49 & V_206 ) )
F_92 ( V_22 , 0 ) ;
F_84 ( & V_22 -> V_264 ) ;
return 0 ;
}
static void F_318 ( struct V_259 * V_259 )
{
struct V_21 * V_22 = F_310 ( V_259 ) ;
F_98 ( V_22 ) ;
F_295 ( V_259 ) ;
}
static int T_14 F_319 ( void )
{
int V_228 ;
F_26 (KERN_INFO DRV_NAME L_270 , DRV_DESCRIPTION, DRV_VERSION) ;
F_26 (KERN_INFO DRV_NAME L_271 , DRV_COPYRIGHT) ;
F_320 ( & V_207 , V_704 ,
V_223 ) ;
V_228 = F_321 ( & V_705 ) ;
if ( V_228 )
goto V_39;
#ifdef F_126
V_44 = V_706 ;
V_228 = F_322 ( & V_705 . V_649 ,
& V_707 ) ;
#endif
V_39:
return V_228 ;
}
static void T_15 F_323 ( void )
{
#ifdef F_126
F_324 ( & V_705 . V_649 ,
& V_707 ) ;
#endif
F_325 ( & V_705 ) ;
F_326 ( & V_207 ) ;
}
static int F_327 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
if ( ! ( V_22 -> V_49 & V_166 ) )
strcpy ( V_218 -> V_51 , L_272 ) ;
else
snprintf ( V_218 -> V_51 , V_710 , L_273 ) ;
F_328 ( L_274 , V_218 -> V_51 ) ;
return 0 ;
}
static int F_329 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
struct V_711 * V_712 = & V_218 -> V_244 ;
int V_63 = 0 ;
if ( V_22 -> V_150 -> V_198 == V_426 )
return - V_639 ;
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) ) {
V_63 = - V_70 ;
goto V_620;
}
if ( V_712 -> V_391 == 1 ) {
if ( ( V_712 -> V_713 >= ( int ) 2.412e8 && V_712 -> V_713 <= ( int ) 2.487e8 ) ) {
int V_714 = V_712 -> V_713 / 100000 ;
int V_42 = 0 ;
while ( ( V_42 < V_520 ) &&
( V_714 != V_715 [ V_42 ] ) )
V_42 ++ ;
V_712 -> V_391 = 0 ;
V_712 -> V_713 = V_42 + 1 ;
}
}
if ( V_712 -> V_391 > 0 || V_712 -> V_713 > 1000 ) {
V_63 = - V_639 ;
goto V_620;
} else {
F_328 ( L_275 , V_712 -> V_713 ) ;
V_63 = F_233 ( V_22 , V_712 -> V_713 , 0 ) ;
}
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_330 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
V_218 -> V_244 . V_391 = 0 ;
if ( V_22 -> V_187 & V_521 ||
V_22 -> V_49 & V_166 )
V_218 -> V_244 . V_713 = V_22 -> V_246 ;
else
V_218 -> V_244 . V_713 = 0 ;
F_328 ( L_276 , V_22 -> V_246 ) ;
return 0 ;
}
static int F_331 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
int V_63 = 0 ;
F_328 ( L_277 , V_218 -> V_312 ) ;
if ( V_218 -> V_312 == V_22 -> V_150 -> V_198 )
return 0 ;
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) ) {
V_63 = - V_70 ;
goto V_620;
}
switch ( V_218 -> V_312 ) {
#ifdef F_157
case V_199 :
V_63 = F_198 ( V_22 , V_199 ) ;
break;
#endif
case V_431 :
V_63 = F_198 ( V_22 , V_431 ) ;
break;
case V_426 :
case V_716 :
default:
V_63 = F_198 ( V_22 , V_426 ) ;
break;
}
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_332 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
V_218 -> V_312 = V_22 -> V_150 -> V_198 ;
F_328 ( L_278 , V_218 -> V_312 ) ;
return 0 ;
}
static int F_333 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
struct V_717 * V_718 = (struct V_717 * ) V_709 ;
T_2 V_4 ;
int V_18 , V_43 ;
V_218 -> V_37 . V_284 = sizeof( * V_718 ) ;
memset ( V_718 , 0 , sizeof( * V_718 ) ) ;
V_718 -> V_719 = 5 * 1000 * 1000 ;
V_718 -> V_720 . V_721 = 100 ;
V_718 -> V_720 . V_43 = 0 ;
V_718 -> V_720 . V_722 = 0 ;
V_718 -> V_720 . V_723 = 7 ;
V_718 -> V_724 . V_721 = 70 ;
V_718 -> V_724 . V_43 = 20 + V_352 ;
V_718 -> V_724 . V_722 = 0 ;
V_718 -> V_724 . V_723 = 7 ;
V_718 -> V_725 = V_257 ;
for ( V_18 = 0 ; V_18 < V_257 && V_18 < V_726 ; V_18 ++ ) {
V_718 -> V_727 [ V_18 ] = V_728 [ V_18 ] ;
}
V_718 -> V_729 = V_730 ;
V_718 -> V_731 = V_554 ;
V_718 -> V_732 = V_733 ;
V_718 -> V_734 = V_735 ;
V_718 -> V_736 = V_737 [ 0 ] ;
V_718 -> V_738 = V_737 [ V_739 - 1 ] ;
V_718 -> V_740 = V_741 [ V_739 - 1 ] ;
V_718 -> V_742 = V_741 [ 0 ] ;
V_718 -> V_743 = V_744 ;
V_718 -> V_745 = V_746 ;
V_718 -> V_747 = V_746 | V_744 ;
V_718 -> V_748 [ 0 ] = 5 ;
V_718 -> V_748 [ 1 ] = 13 ;
V_718 -> V_749 = 2 ;
V_718 -> V_750 = V_751 ;
if ( V_22 -> V_150 -> V_198 == V_431 ) {
V_718 -> V_752 = V_753 ;
V_718 -> V_754 = V_755 ;
for ( V_18 = 0 , V_43 = ( V_588 * 16 ) ;
V_18 < V_755 ;
V_18 ++ , V_43 -=
( ( V_588 -
V_587 ) * 16 ) / ( V_755 - 1 ) )
V_718 -> V_756 [ V_18 ] = V_43 / 16 ;
} else {
V_718 -> V_752 = 0 ;
V_718 -> V_754 = 0 ;
}
V_718 -> V_757 = V_758 ;
V_718 -> V_759 = 18 ;
V_718 -> V_760 = V_761 ;
V_4 = 0 ;
for ( V_18 = 0 ; V_18 < V_761 ; V_18 ++ ) {
V_718 -> V_244 [ V_4 ] . V_18 = V_18 + 1 ;
V_718 -> V_244 [ V_4 ] . V_713 = V_715 [ V_18 ] * 100000 ;
V_718 -> V_244 [ V_4 ] . V_391 = 1 ;
V_4 ++ ;
if ( V_4 == V_762 )
break;
}
V_718 -> V_763 = V_4 ;
V_718 -> V_764 [ 0 ] = ( V_765 |
F_334 ( V_224 ) ) ;
V_718 -> V_764 [ 1 ] = V_766 ;
V_718 -> V_767 = V_768 | V_769 |
V_770 | V_771 ;
F_328 ( L_279 ) ;
return 0 ;
}
static int F_335 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
int V_63 = 0 ;
static const unsigned char V_772 [] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
static const unsigned char V_773 [] = {
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00
} ;
if ( V_218 -> V_219 . V_220 != V_221 )
return - V_31 ;
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) ) {
V_63 = - V_70 ;
goto V_620;
}
if ( ! memcmp ( V_772 , V_218 -> V_219 . V_628 , V_231 ) ||
! memcmp ( V_773 , V_218 -> V_219 . V_628 , V_231 ) ) {
F_328 ( L_280 ) ;
V_22 -> V_187 &= ~ V_625 ;
V_63 = F_243 ( V_22 , NULL , 0 ) ;
goto V_620;
}
V_22 -> V_187 |= V_625 ;
memcpy ( V_22 -> V_774 , V_218 -> V_219 . V_628 , V_231 ) ;
V_63 = F_243 ( V_22 , V_218 -> V_219 . V_628 , 0 ) ;
F_328 ( L_281 , V_218 -> V_219 . V_628 ) ;
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_336 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
if ( V_22 -> V_187 & V_625 || V_22 -> V_49 & V_166 ) {
V_218 -> V_219 . V_220 = V_221 ;
memcpy ( V_218 -> V_219 . V_628 , V_22 -> V_271 , V_231 ) ;
} else
memset ( V_218 -> V_219 . V_628 , 0 , V_231 ) ;
F_328 ( L_282 , V_218 -> V_219 . V_628 ) ;
return 0 ;
}
static int F_337 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
char * V_266 = L_50 ;
int V_284 = 0 ;
int V_63 = 0 ;
F_110 ( V_272 ) ;
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) ) {
V_63 = - V_70 ;
goto V_620;
}
if ( V_218 -> V_266 . V_62 && V_218 -> V_266 . V_284 ) {
V_284 = V_218 -> V_266 . V_284 ;
V_266 = V_709 ;
}
if ( V_284 == 0 ) {
F_328 ( L_283 ) ;
V_22 -> V_187 &= ~ V_281 ;
V_63 = F_112 ( V_22 , NULL , 0 , 0 ) ;
goto V_620;
}
V_284 = F_33 ( V_284 , V_267 ) ;
V_22 -> V_187 |= V_281 ;
if ( V_22 -> V_265 == V_284 && ! memcmp ( V_22 -> V_266 , V_709 , V_284 ) ) {
F_328 ( L_284 ) ;
V_63 = 0 ;
goto V_620;
}
F_328 ( L_285 ,
F_111 ( V_272 , V_266 , V_284 ) , V_284 ) ;
V_22 -> V_265 = V_284 ;
memcpy ( V_22 -> V_266 , V_266 , V_22 -> V_265 ) ;
V_63 = F_112 ( V_22 , V_266 , V_284 , 0 ) ;
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_338 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
F_110 ( V_272 ) ;
if ( V_22 -> V_187 & V_281 || V_22 -> V_49 & V_166 ) {
F_328 ( L_286 ,
F_111 ( V_272 , V_22 -> V_266 , V_22 -> V_265 ) ) ;
memcpy ( V_709 , V_22 -> V_266 , V_22 -> V_265 ) ;
V_218 -> V_266 . V_284 = V_22 -> V_265 ;
V_218 -> V_266 . V_62 = 1 ;
} else {
F_328 ( L_287 ) ;
V_218 -> V_266 . V_284 = 0 ;
V_218 -> V_266 . V_62 = 0 ;
}
return 0 ;
}
static int F_339 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
if ( V_218 -> V_37 . V_284 > V_267 )
return - V_775 ;
V_218 -> V_37 . V_284 = F_33 ( ( T_4 ) V_218 -> V_37 . V_284 , sizeof( V_22 -> V_688 ) ) ;
memset ( V_22 -> V_688 , 0 , sizeof( V_22 -> V_688 ) ) ;
memcpy ( V_22 -> V_688 , V_709 , V_218 -> V_37 . V_284 ) ;
F_328 ( L_288 , V_22 -> V_688 ) ;
return 0 ;
}
static int F_340 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
V_218 -> V_37 . V_284 = strlen ( V_22 -> V_688 ) ;
memcpy ( V_709 , V_22 -> V_688 , V_218 -> V_37 . V_284 ) ;
V_218 -> V_37 . V_62 = 1 ;
F_328 ( L_289 , V_709 ) ;
return 0 ;
}
static int F_341 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
T_1 V_776 = V_218 -> V_727 . V_147 ;
T_1 V_536 ;
int V_63 = 0 ;
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) ) {
V_63 = - V_70 ;
goto V_620;
}
V_536 = 0 ;
if ( V_776 == 1000000 ||
( ! V_218 -> V_727 . V_777 && V_776 > 1000000 ) )
V_536 |= V_277 ;
if ( V_776 == 2000000 ||
( ! V_218 -> V_727 . V_777 && V_776 > 2000000 ) )
V_536 |= V_278 ;
if ( V_776 == 5500000 ||
( ! V_218 -> V_727 . V_777 && V_776 > 5500000 ) )
V_536 |= V_279 ;
if ( V_776 == 11000000 ||
( ! V_218 -> V_727 . V_777 && V_776 > 11000000 ) )
V_536 |= V_280 ;
if ( V_536 == 0 )
V_536 = V_687 ;
V_63 = F_236 ( V_22 , V_536 , 0 ) ;
F_328 ( L_290 , V_536 ) ;
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_342 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
int V_4 ;
unsigned int V_13 = sizeof( V_4 ) ;
int V_63 = 0 ;
if ( ! ( V_22 -> V_49 & V_106 ) ||
V_22 -> V_49 & V_484 ||
! ( V_22 -> V_49 & V_166 ) ) {
V_218 -> V_727 . V_147 = 0 ;
return 0 ;
}
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) ) {
V_63 = - V_70 ;
goto V_620;
}
V_63 = F_25 ( V_22 , V_274 , & V_4 , & V_13 ) ;
if ( V_63 ) {
F_328 ( L_291 ) ;
goto V_620;
}
switch ( V_4 & V_538 ) {
case V_277 :
V_218 -> V_727 . V_147 = 1000000 ;
break;
case V_278 :
V_218 -> V_727 . V_147 = 2000000 ;
break;
case V_279 :
V_218 -> V_727 . V_147 = 5500000 ;
break;
case V_280 :
V_218 -> V_727 . V_147 = 11000000 ;
break;
default:
V_218 -> V_727 . V_147 = 0 ;
}
F_328 ( L_292 , V_218 -> V_727 . V_147 ) ;
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_343 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
int V_147 , V_63 ;
if ( V_218 -> V_778 . V_777 == 0 )
return - V_31 ;
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) ) {
V_63 = - V_70 ;
goto V_620;
}
if ( V_218 -> V_778 . V_779 )
V_147 = V_22 -> V_555 | V_553 ;
else {
if ( V_218 -> V_778 . V_147 < 1 || V_218 -> V_778 . V_147 > 2304 ) {
V_63 = - V_31 ;
goto V_620;
}
V_147 = V_218 -> V_778 . V_147 ;
}
V_63 = F_240 ( V_22 , V_147 ) ;
F_328 ( L_293 , V_147 ) ;
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_344 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
V_218 -> V_778 . V_147 = V_22 -> V_555 & ~ V_553 ;
V_218 -> V_778 . V_777 = 1 ;
V_218 -> V_778 . V_779 = ( V_22 -> V_555 & V_553 ) ? 1 : 0 ;
F_328 ( L_294 , V_218 -> V_778 . V_147 ) ;
return 0 ;
}
static int F_345 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
int V_63 = 0 , V_147 ;
if ( F_211 ( V_22 , V_218 -> V_756 . V_779 ) )
return - V_780 ;
if ( V_22 -> V_150 -> V_198 != V_431 )
return 0 ;
if ( ( V_218 -> V_756 . V_62 & V_781 ) != V_753 )
return - V_31 ;
if ( V_218 -> V_756 . V_777 == 0 )
V_147 = V_586 ;
else {
if ( V_218 -> V_756 . V_147 < V_587 ||
V_218 -> V_756 . V_147 > V_588 )
return - V_31 ;
V_147 = V_218 -> V_756 . V_147 ;
}
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) ) {
V_63 = - V_70 ;
goto V_620;
}
V_63 = F_247 ( V_22 , V_147 ) ;
F_328 ( L_295 , V_147 ) ;
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_346 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
V_218 -> V_756 . V_779 = ( V_22 -> V_49 & V_484 ) ? 1 : 0 ;
if ( V_22 -> V_585 == V_586 ) {
V_218 -> V_756 . V_777 = 0 ;
V_218 -> V_756 . V_147 = V_588 ;
} else {
V_218 -> V_756 . V_777 = 1 ;
V_218 -> V_756 . V_147 = V_22 -> V_585 ;
}
V_218 -> V_756 . V_62 = V_753 ;
F_328 ( L_296 , V_218 -> V_756 . V_147 ) ;
return 0 ;
}
static int F_347 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
if ( ! V_218 -> V_782 . V_777 )
return - V_31 ;
if ( V_218 -> V_782 . V_779 ) {
V_22 -> V_684 |= V_686 ;
V_22 -> V_150 -> V_783 = V_685 ;
} else {
if ( V_218 -> V_782 . V_147 < V_733 ||
V_218 -> V_782 . V_147 > V_735 )
return - V_31 ;
V_22 -> V_150 -> V_783 = V_218 -> V_782 . V_147 & ~ 0x1 ;
V_22 -> V_684 = V_22 -> V_150 -> V_783 ;
}
F_328 ( L_297 , V_22 -> V_150 -> V_783 ) ;
return 0 ;
}
static int F_348 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
V_218 -> V_782 . V_147 = V_22 -> V_684 & ~ V_686 ;
V_218 -> V_782 . V_777 = 0 ;
V_218 -> V_782 . V_779 = ( V_22 -> V_684 & V_686 ) ? 1 : 0 ;
F_328 ( L_298 , V_218 -> V_782 . V_147 ) ;
return 0 ;
}
static int F_349 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
int V_63 = 0 ;
if ( V_218 -> V_556 . V_62 & V_784 || V_218 -> V_556 . V_779 )
return - V_31 ;
if ( ! ( V_218 -> V_556 . V_62 & V_785 ) )
return 0 ;
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) ) {
V_63 = - V_70 ;
goto V_620;
}
if ( V_218 -> V_556 . V_62 & V_786 ) {
V_63 = F_241 ( V_22 , V_218 -> V_556 . V_147 ) ;
F_328 ( L_299 ,
V_218 -> V_556 . V_147 ) ;
goto V_620;
}
if ( V_218 -> V_556 . V_62 & V_787 ) {
V_63 = F_242 ( V_22 , V_218 -> V_556 . V_147 ) ;
F_328 ( L_300 ,
V_218 -> V_556 . V_147 ) ;
goto V_620;
}
V_63 = F_241 ( V_22 , V_218 -> V_556 . V_147 ) ;
if ( ! V_63 )
V_63 = F_242 ( V_22 , V_218 -> V_556 . V_147 ) ;
F_328 ( L_301 , V_218 -> V_556 . V_147 ) ;
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_350 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
V_218 -> V_556 . V_779 = 0 ;
if ( ( V_218 -> V_556 . V_62 & V_788 ) == V_784 )
return - V_31 ;
if ( V_218 -> V_556 . V_62 & V_787 ) {
V_218 -> V_556 . V_62 = V_785 | V_787 ;
V_218 -> V_556 . V_147 = V_22 -> V_560 ;
} else {
V_218 -> V_556 . V_62 =
( V_22 -> V_558 !=
V_22 -> V_560 ) ?
V_785 | V_786 : V_785 ;
V_218 -> V_556 . V_147 = V_22 -> V_558 ;
}
F_328 ( L_302 , V_218 -> V_556 . V_147 ) ;
return 0 ;
}
static int F_351 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
int V_63 = 0 ;
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) ) {
V_63 = - V_70 ;
goto V_620;
}
F_328 ( L_303 ) ;
V_22 -> V_297 = 1 ;
if ( F_89 ( V_22 ) || F_91 ( V_22 ) ) {
F_328 ( L_304 ) ;
}
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_352 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
return F_353 ( V_22 -> V_150 , V_81 , V_218 , V_709 ) ;
}
static int F_354 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_593 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
return F_355 ( V_22 -> V_150 , V_81 , V_218 , V_593 ) ;
}
static int F_356 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_593 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
return F_357 ( V_22 -> V_150 , V_81 , V_218 , V_593 ) ;
}
static int F_358 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
int V_63 = 0 ;
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) ) {
V_63 = - V_70 ;
goto V_620;
}
if ( V_218 -> V_789 . V_779 ) {
V_22 -> V_545 = F_238 ( V_22 -> V_545 ) ;
V_63 = F_237 ( V_22 , V_544 ) ;
F_328 ( L_305 ) ;
goto V_620;
}
switch ( V_218 -> V_789 . V_62 & V_790 ) {
case V_791 :
case V_790 :
case V_792 :
break;
default:
F_328 ( L_306 ,
V_218 -> V_789 . V_62 ) ;
V_63 = - V_639 ;
goto V_620;
}
V_22 -> V_545 = V_546 | V_22 -> V_545 ;
V_63 = F_237 ( V_22 , F_238 ( V_22 -> V_545 ) ) ;
F_328 ( L_307 , V_22 -> V_545 ) ;
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_359 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
if ( ! ( V_22 -> V_545 & V_546 ) )
V_218 -> V_789 . V_779 = 1 ;
else {
V_218 -> V_789 . V_779 = 0 ;
V_218 -> V_789 . V_62 = 0 ;
}
F_328 ( L_308 , V_22 -> V_545 ) ;
return 0 ;
}
static int F_360 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
struct V_632 * V_150 = V_22 -> V_150 ;
T_3 * V_14 ;
if ( ! V_150 -> V_631 )
return - V_639 ;
if ( V_218 -> V_37 . V_284 > V_793 ||
( V_218 -> V_37 . V_284 && V_709 == NULL ) )
return - V_31 ;
if ( V_218 -> V_37 . V_284 ) {
V_14 = F_361 ( V_709 , V_218 -> V_37 . V_284 , V_240 ) ;
if ( V_14 == NULL )
return - V_241 ;
F_132 ( V_150 -> V_640 ) ;
V_150 -> V_640 = V_14 ;
V_150 -> V_641 = V_218 -> V_37 . V_284 ;
} else {
F_132 ( V_150 -> V_640 ) ;
V_150 -> V_640 = NULL ;
V_150 -> V_641 = 0 ;
}
V_563 ( V_22 , V_150 -> V_640 , V_150 -> V_641 ) ;
return 0 ;
}
static int F_362 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
struct V_632 * V_150 = V_22 -> V_150 ;
if ( V_150 -> V_641 == 0 || V_150 -> V_640 == NULL ) {
V_218 -> V_37 . V_284 = 0 ;
return 0 ;
}
if ( V_218 -> V_37 . V_284 < V_150 -> V_641 )
return - V_775 ;
V_218 -> V_37 . V_284 = V_150 -> V_641 ;
memcpy ( V_709 , V_150 -> V_640 , V_150 -> V_641 ) ;
return 0 ;
}
static int F_363 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
struct V_632 * V_150 = V_22 -> V_150 ;
struct V_794 * V_795 = & V_218 -> V_795 ;
struct V_796 * V_491 ;
unsigned long V_62 ;
int V_228 = 0 ;
switch ( V_795 -> V_62 & V_797 ) {
case V_798 :
case V_799 :
case V_800 :
case V_801 :
break;
case V_802 :
V_491 = V_22 -> V_150 -> V_490 . V_491 [ V_22 -> V_150 -> V_490 . V_492 ] ;
if ( ! V_491 || ! V_491 -> V_803 -> V_804 || ! V_491 -> V_803 -> V_805 )
break;
V_62 = V_491 -> V_803 -> V_805 ( V_491 -> V_22 ) ;
if ( V_795 -> V_147 )
V_62 |= V_806 ;
else
V_62 &= ~ V_806 ;
V_491 -> V_803 -> V_804 ( V_62 , V_491 -> V_22 ) ;
break;
case V_807 : {
struct V_617 V_190 = {
. V_62 = V_191 ,
. V_192 = V_795 -> V_147 ,
} ;
V_22 -> V_150 -> V_674 = V_795 -> V_147 ;
if ( ! V_795 -> V_147 ) {
V_190 . V_62 |= V_610 ;
V_190 . V_43 = V_572 ;
} else {
V_190 . V_62 |= V_610 ;
V_190 . V_43 = V_575 ;
}
if ( V_22 -> V_150 -> V_638 )
V_22 -> V_150 -> V_638 ( V_22 -> V_150 -> V_2 , & V_190 ) ;
break;
}
case V_808 :
V_228 = F_268 ( V_22 , V_795 -> V_147 ) ;
break;
case V_809 :
V_228 = F_267 ( V_22 , V_795 -> V_147 ) ;
break;
case V_810 :
V_150 -> V_676 = V_795 -> V_147 ;
break;
case V_811 :
V_150 -> V_675 = V_795 -> V_147 ;
break;
default:
return - V_639 ;
}
return V_228 ;
}
static int F_364 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
struct V_632 * V_150 = V_22 -> V_150 ;
struct V_796 * V_491 ;
struct V_794 * V_795 = & V_218 -> V_795 ;
int V_228 = 0 ;
switch ( V_795 -> V_62 & V_797 ) {
case V_798 :
case V_799 :
case V_800 :
case V_801 :
V_228 = - V_639 ;
break;
case V_802 :
V_491 = V_22 -> V_150 -> V_490 . V_491 [ V_22 -> V_150 -> V_490 . V_492 ] ;
if ( ! V_491 || ! V_491 -> V_803 -> V_805 ) {
F_155 ( L_309
L_310 ) ;
break;
}
V_795 -> V_147 = ( V_491 -> V_803 -> V_805 ( V_491 -> V_22 ) &
V_806 ) ? 1 : 0 ;
break;
case V_807 :
V_795 -> V_147 = V_150 -> V_674 ;
break;
case V_808 :
V_795 -> V_147 = V_22 -> V_150 -> V_190 . V_566 ;
break;
case V_809 :
V_795 -> V_147 = V_150 -> V_631 ;
break;
case V_810 :
V_795 -> V_147 = V_150 -> V_676 ;
break;
case V_812 :
case V_811 :
V_795 -> V_147 = V_150 -> V_675 ;
break;
default:
return - V_639 ;
}
return 0 ;
}
static int F_365 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
return F_366 ( V_22 -> V_150 , V_81 , V_218 , V_709 ) ;
}
static int F_367 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
return F_368 ( V_22 -> V_150 , V_81 , V_218 , V_709 ) ;
}
static int F_369 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
struct V_813 * V_814 = (struct V_813 * ) V_709 ;
T_16 V_815 ;
V_815 = F_153 ( V_814 -> V_816 ) ;
switch ( V_814 -> V_57 ) {
case V_817 :
break;
case V_818 :
F_244 ( V_22 ) ;
break;
default:
return - V_639 ;
}
return 0 ;
}
static int F_370 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
int * V_819 = ( int * ) V_709 ;
int V_820 = ( V_819 [ 0 ] > 0 ) ;
int V_63 = 0 ;
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) ) {
V_63 = - V_70 ;
goto V_620;
}
if ( V_820 ) {
if ( V_22 -> V_150 -> V_198 == V_199 ) {
V_63 = F_233 ( V_22 , V_819 [ 1 ] , 0 ) ;
goto V_620;
}
V_22 -> V_246 = V_819 [ 1 ] ;
V_63 = F_198 ( V_22 , V_199 ) ;
} else {
if ( V_22 -> V_150 -> V_198 == V_199 )
V_63 = F_198 ( V_22 , V_22 -> V_488 ) ;
}
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_371 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
if ( V_22 -> V_49 & V_619 )
F_34 ( V_22 ) ;
return 0 ;
}
static int F_372 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
int V_63 = 0 , V_312 = * ( int * ) V_709 ;
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) ) {
V_63 = - V_70 ;
goto V_620;
}
if ( ( V_312 < 0 ) || ( V_312 > V_739 ) )
V_312 = V_673 ;
if ( F_238 ( V_22 -> V_545 ) != V_312 )
V_63 = F_237 ( V_22 , V_312 ) ;
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_373 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
int V_43 = F_238 ( V_22 -> V_545 ) ;
T_17 V_821 , V_822 ;
if ( ! ( V_22 -> V_545 & V_546 ) ) {
snprintf ( V_709 , V_823 ,
L_311 , V_43 ) ;
} else {
switch ( V_43 ) {
case V_544 :
snprintf ( V_709 , V_823 ,
L_312 , V_43 ) ;
break;
case V_673 :
snprintf ( V_709 , V_823 ,
L_313 , V_43 ) ;
break;
default:
V_821 = V_741 [ V_43 - 1 ] / 1000 ;
V_822 = V_737 [ V_43 - 1 ] / 1000 ;
snprintf ( V_709 , V_823 ,
L_314
L_315 ,
V_43 , V_821 , V_822 ) ;
}
}
V_218 -> V_37 . V_284 = strlen ( V_709 ) + 1 ;
return 0 ;
}
static int F_374 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
int V_63 , V_312 = * ( int * ) V_709 ;
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) ) {
V_63 = - V_70 ;
goto V_620;
}
if ( V_312 == 1 )
V_22 -> V_187 |= V_528 ;
else if ( V_312 == 0 )
V_22 -> V_187 &= ~ V_528 ;
else {
V_63 = - V_31 ;
goto V_620;
}
V_63 = F_234 ( V_22 , 0 ) ;
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_375 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
if ( V_22 -> V_187 & V_528 )
snprintf ( V_218 -> V_51 , V_710 , L_316 ) ;
else
snprintf ( V_218 -> V_51 , V_710 , L_317 ) ;
return 0 ;
}
static int F_376 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
int V_63 , V_312 = * ( int * ) V_709 ;
F_83 ( & V_22 -> V_264 ) ;
if ( ! ( V_22 -> V_49 & V_619 ) ) {
V_63 = - V_70 ;
goto V_620;
}
if ( V_312 == 1 )
V_22 -> V_187 |= V_343 ;
else if ( V_312 == 0 )
V_22 -> V_187 &= ~ V_343 ;
else {
V_63 = - V_31 ;
goto V_620;
}
V_63 = 0 ;
V_620:
F_84 ( & V_22 -> V_264 ) ;
return V_63 ;
}
static int F_377 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_21 * V_22 = F_101 ( V_2 ) ;
if ( V_22 -> V_187 & V_343 )
snprintf ( V_218 -> V_51 , V_710 , L_318 ) ;
else
snprintf ( V_218 -> V_51 , V_710 , L_319 ) ;
return 0 ;
}
static struct V_824 * F_378 ( struct V_1 * V_2 )
{
enum {
V_825 = 30 ,
V_826 = 60 ,
V_827 = 80 ,
V_828 = 90 ,
V_829 = 95 ,
V_830 = 100
};
int V_831 ;
int V_832 ;
int V_833 ;
int V_834 ;
struct V_21 * V_22 = F_101 ( V_2 ) ;
struct V_824 * V_301 ;
T_1 V_351 , V_835 , V_836 , V_837 ;
T_1 V_204 = sizeof( T_1 ) ;
if ( ! V_22 )
return (struct V_824 * ) NULL ;
V_301 = & V_22 -> V_301 ;
if ( ! ( V_22 -> V_49 & V_166 ) ) {
V_301 -> V_838 . V_839 = 0 ;
V_301 -> V_331 . V_840 = 0 ;
V_301 -> V_721 . V_721 = 0 ;
V_301 -> V_721 . V_43 = 0 ;
V_301 -> V_721 . V_722 = 0 ;
V_301 -> V_721 . V_723 = 7 ;
V_301 -> V_721 . V_723 |= V_841 |
V_842 | V_843 ;
return V_301 ;
}
if ( F_25 ( V_22 , V_844 ,
& V_836 , & V_204 ) )
goto V_845;
if ( ! ( V_22 -> V_49 & V_166 ) ) {
V_301 -> V_721 . V_721 = 0 ;
V_301 -> V_721 . V_43 = 0 ;
} else {
if ( F_25 ( V_22 , V_846 ,
& V_351 , & V_204 ) )
goto V_845;
V_301 -> V_721 . V_43 = V_351 + V_352 ;
if ( V_351 < 10 )
V_831 = V_351 * V_825 / 10 ;
else if ( V_351 < 15 )
V_831 = ( V_351 - 10 ) * ( V_826 - V_825 ) / 5 + V_825 ;
else if ( V_351 < 20 )
V_831 = ( V_351 - 15 ) * ( V_827 - V_826 ) / 5 + V_826 ;
else if ( V_351 < 30 )
V_831 = ( V_351 - 20 ) * ( V_828 - V_827 ) /
10 + V_827 ;
else
V_831 = ( V_351 - 30 ) * ( V_830 - V_828 ) /
10 + V_828 ;
if ( F_25 ( V_22 , V_847 ,
& V_835 , & V_204 ) )
goto V_845;
if ( V_835 > 75 )
V_832 = ( 90 - V_835 ) * V_825 / 15 ;
else if ( V_835 > 70 )
V_832 = ( 75 - V_835 ) * ( V_826 - V_825 ) / 5 + V_825 ;
else if ( V_835 > 65 )
V_832 = ( 70 - V_835 ) * ( V_827 - V_826 ) / 5 + V_826 ;
else if ( V_835 > 50 )
V_832 = ( 65 - V_835 ) * ( V_828 - V_827 ) /
15 + V_827 ;
else
V_832 = ( 50 - V_835 ) *
( V_830 - V_828 ) / 50 + V_828 ;
if ( V_836 > 50 )
V_833 = ( 60 - V_836 ) * V_825 / 10 ;
else if ( V_836 > 40 )
V_833 = ( 50 - V_836 ) * ( V_826 - V_825 ) /
10 + V_825 ;
else if ( V_836 > 32 )
V_833 = ( 40 - V_836 ) * ( V_827 - V_826 ) /
18 + V_826 ;
else if ( V_836 > 20 )
V_833 = ( 32 - V_836 ) *
( V_828 - V_827 ) / 20 + V_827 ;
else
V_833 = ( 20 - V_836 ) *
( V_830 - V_828 ) / 20 + V_828 ;
V_834 = F_33 ( V_832 , V_831 ) ;
V_834 = F_33 ( V_833 , V_834 ) ;
#ifdef F_126
if ( V_833 == V_834 )
F_328 ( L_320 ) ;
else if ( V_832 == V_834 )
F_328 ( L_321 ) ;
else if ( V_834 != 100 )
F_328 ( L_322 ) ;
else
F_328 ( L_323 ) ;
#endif
V_301 -> V_721 . V_721 = V_834 ;
V_301 -> V_721 . V_43 = V_351 + V_352 ;
}
V_301 -> V_721 . V_722 = 0 ;
V_301 -> V_721 . V_723 = 7 ;
V_301 -> V_721 . V_723 |= V_841 ;
V_301 -> V_838 . V_839 = V_836 ;
if ( F_25 ( V_22 , V_848 ,
& V_837 , & V_204 ) )
goto V_845;
V_301 -> V_331 . V_840 = V_837 ;
return V_301 ;
V_845:
F_328 ( L_291 ) ;
return (struct V_824 * ) NULL ;
}
static void V_689 ( struct V_260 * V_261 )
{
struct V_21 * V_22 =
F_107 ( V_261 , struct V_21 , V_283 . V_261 ) ;
union V_217 V_218 ;
unsigned int V_13 = V_231 ;
if ( V_22 -> V_49 & V_184 )
return;
F_83 ( & V_22 -> V_264 ) ;
F_328 ( L_42 ) ;
F_84 ( & V_22 -> V_264 ) ;
V_218 . V_219 . V_220 = V_221 ;
if ( ! ( V_22 -> V_49 & ( V_165 | V_166 ) ) ||
V_22 -> V_49 & V_484 ||
F_25 ( V_22 , V_276 ,
& V_22 -> V_271 , & V_13 ) ) {
memset ( V_218 . V_219 . V_628 , 0 , V_231 ) ;
} else {
memcpy ( V_218 . V_219 . V_628 , V_22 -> V_271 , V_231 ) ;
memcpy ( V_22 -> V_150 -> V_271 , V_22 -> V_271 , V_231 ) ;
V_22 -> V_49 &= ~ V_165 ;
V_22 -> V_49 |= V_166 ;
F_263 ( V_22 -> V_33 ) ;
F_166 ( V_22 -> V_33 ) ;
}
if ( ! ( V_22 -> V_49 & V_166 ) ) {
F_328 ( L_324 ) ;
F_83 ( & V_22 -> V_264 ) ;
if ( V_22 -> V_187 & V_281 )
F_112 ( V_22 , V_22 -> V_266 , V_22 -> V_265 ,
0 ) ;
else
F_112 ( V_22 , NULL , 0 , 0 ) ;
F_84 ( & V_22 -> V_264 ) ;
}
F_99 ( V_22 -> V_33 , V_224 , & V_218 , NULL ) ;
}
static int F_379 ( struct V_119 * V_849 )
{
struct V_850 * V_851 =
(struct V_850 * ) V_849 -> V_852 -> V_37 ;
if ( F_380 ( V_851 -> V_121 ) != V_853 ) {
F_26 (KERN_WARNING DRV_NAME L_325
L_326
L_327 ,
h->version) ;
return 1 ;
}
V_849 -> V_121 = V_851 -> V_121 ;
V_849 -> V_849 . V_37 = V_849 -> V_852 -> V_37 + sizeof( struct V_850 ) ;
V_849 -> V_849 . V_478 = V_851 -> V_854 ;
V_849 -> V_855 . V_37 = V_849 -> V_849 . V_37 + V_851 -> V_854 ;
V_849 -> V_855 . V_478 = V_851 -> V_856 ;
return 0 ;
}
static int F_62 ( struct V_21 * V_22 ,
struct V_119 * V_849 )
{
char * V_857 ;
int V_202 ;
F_30 ( L_328 ,
V_22 -> V_33 -> V_51 ) ;
switch ( V_22 -> V_150 -> V_198 ) {
case V_431 :
V_857 = F_381 ( L_329 ) ;
break;
#ifdef F_157
case V_199 :
V_857 = F_381 ( L_330 ) ;
break;
#endif
case V_426 :
default:
V_857 = F_381 ( L_50 ) ;
break;
}
V_202 = F_382 ( & V_849 -> V_852 , V_857 , & V_22 -> V_259 -> V_2 ) ;
if ( V_202 < 0 ) {
F_26 (KERN_ERR DRV_NAME L_67
L_331 ,
priv->net_dev->name, fw_name) ;
return V_202 ;
}
F_30 ( L_332 , V_849 -> V_852 -> V_37 ,
V_849 -> V_852 -> V_478 ) ;
F_379 ( V_849 ) ;
return 0 ;
}
static void F_65 ( struct V_21 * V_22 ,
struct V_119 * V_849 )
{
V_849 -> V_121 = 0 ;
if ( V_849 -> V_852 )
F_383 ( V_849 -> V_852 ) ;
V_849 -> V_852 = NULL ;
}
static int F_270 ( struct V_21 * V_22 , char * V_14 ,
T_4 V_858 )
{
char V_859 [ V_860 ] ;
T_1 V_13 = V_860 ;
T_1 V_313 ;
int V_18 ;
if ( F_25 ( V_22 , V_861 , V_859 , & V_13 ) )
return - V_70 ;
V_313 = V_858 ;
if ( V_13 >= V_858 )
V_13 = V_858 - 1 ;
for ( V_18 = 0 ; V_18 < V_13 ; V_18 ++ )
V_14 [ V_18 ] = V_859 [ V_18 ] ;
V_14 [ V_18 ] = '\0' ;
return V_313 ;
}
static int F_271 ( struct V_21 * V_22 , char * V_14 ,
T_4 V_858 )
{
T_1 V_859 ;
T_1 V_13 = sizeof( V_859 ) ;
if ( F_25 ( V_22 , V_862 , & V_859 , & V_13 ) )
return - V_70 ;
return snprintf ( V_14 , V_858 , L_14 , V_859 ) ;
}
static int F_64 ( struct V_21 * V_22 , struct V_119 * V_849 )
{
unsigned int V_7 ;
unsigned short V_13 ;
const unsigned char * V_863 = V_849 -> V_849 . V_37 ;
unsigned int V_864 = V_849 -> V_849 . V_478 ;
while ( V_864 > 0 ) {
V_7 = * ( T_1 * ) ( V_863 ) ;
V_863 += 4 ;
V_864 -= 4 ;
V_13 = * ( T_2 * ) ( V_863 ) ;
V_863 += 2 ;
V_864 -= 2 ;
if ( V_13 > 32 ) {
F_26 (KERN_ERR DRV_NAME L_67
L_333 ,
len) ;
return - V_31 ;
}
F_22 ( V_22 -> V_33 , V_7 , V_13 , V_863 ) ;
V_863 += V_13 ;
V_864 -= V_13 ;
}
return 0 ;
}
static int F_63 ( struct V_21 * V_22 ,
struct V_119 * V_849 )
{
struct V_1 * V_2 = V_22 -> V_33 ;
const unsigned char * V_865 = V_849 -> V_855 . V_37 ;
unsigned int V_866 = V_849 -> V_855 . V_478 ;
void V_5 * V_3 = ( void V_5 * ) V_2 -> V_6 ;
struct V_867 V_868 ;
int V_18 , V_40 ;
T_3 V_37 ;
F_17 ( V_2 , V_174 , 0x703 ) ;
F_2 ( V_3 ) ;
F_17 ( V_2 , V_174 , 0x707 ) ;
F_2 ( V_3 ) ;
F_19 ( V_2 , 0x210014 , 0x72 ) ;
F_2 ( V_3 ) ;
F_19 ( V_2 , 0x210014 , 0x72 ) ;
F_2 ( V_3 ) ;
F_19 ( V_2 , 0x210000 , 0x40 ) ;
F_2 ( V_3 ) ;
F_19 ( V_2 , 0x210000 , 0x0 ) ;
F_2 ( V_3 ) ;
F_19 ( V_2 , 0x210000 , 0x40 ) ;
F_2 ( V_3 ) ;
while ( V_866 > 0 ) {
F_19 ( V_2 , 0x210010 , * V_865 ++ ) ;
F_19 ( V_2 , 0x210010 , * V_865 ++ ) ;
V_866 -= 2 ;
}
F_19 ( V_2 , 0x210000 , 0x0 ) ;
F_2 ( V_3 ) ;
F_19 ( V_2 , 0x210000 , 0x0 ) ;
F_2 ( V_3 ) ;
F_19 ( V_2 , 0x210000 , 0x80 ) ;
F_2 ( V_3 ) ;
F_17 ( V_2 , V_174 , 0x703 ) ;
F_2 ( V_3 ) ;
F_17 ( V_2 , V_174 , 0x707 ) ;
F_2 ( V_3 ) ;
F_19 ( V_2 , 0x210014 , 0x72 ) ;
F_2 ( V_3 ) ;
F_19 ( V_2 , 0x210014 , 0x72 ) ;
F_2 ( V_3 ) ;
F_19 ( V_2 , 0x210000 , 0x00 ) ;
F_2 ( V_3 ) ;
F_19 ( V_2 , 0x210000 , 0x80 ) ;
for ( V_18 = 0 ; V_18 < 10 ; V_18 ++ ) {
F_57 ( 10 ) ;
F_18 ( V_2 , 0x210000 , & V_37 ) ;
if ( V_37 & 0x1 )
break;
}
if ( V_18 == 10 ) {
F_26 (KERN_ERR DRV_NAME L_334 ,
dev->name) ;
return - V_70 ;
}
for ( V_18 = 0 ; V_18 < 30 ; V_18 ++ ) {
for ( V_40 = 0 ;
V_40 < ( sizeof( struct V_867 ) >> 1 ) ; V_40 ++ )
F_16 ( V_2 , 0x210004 , ( ( T_2 * ) & V_868 ) + V_40 ) ;
if ( ( V_868 . V_869 == 1 ) && ( V_868 . V_870 == 0x1 ) )
break;
F_57 ( 10 ) ;
}
if ( V_18 == 30 ) {
F_26 (KERN_ERR DRV_NAME
L_335 ,
dev->name) ;
F_32 ( V_871 , ( T_3 * ) & V_868 , sizeof( V_868 ) ) ;
return - V_70 ;
}
return 0 ;
}
