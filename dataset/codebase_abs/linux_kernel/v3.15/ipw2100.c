static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
* V_4 = F_3 ( V_6 -> V_7 + V_3 ) ;
F_4 ( L_1 , V_3 , * V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_6 ( V_4 , V_6 -> V_7 + V_3 ) ;
F_4 ( L_2 , V_3 , V_4 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
* V_4 = F_8 ( V_6 -> V_7 + V_3 ) ;
F_4 ( L_3 , V_3 , * V_4 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_3 , T_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
* V_4 = F_10 ( V_6 -> V_7 + V_3 ) ;
F_4 ( L_4 , V_3 , * V_4 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_12 ( V_4 , V_6 -> V_7 + V_3 ) ;
F_4 ( L_5 , V_3 , V_4 ) ;
}
static inline void F_13 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_14 ( V_4 , V_6 -> V_7 + V_3 ) ;
F_4 ( L_6 , V_3 , V_4 ) ;
}
static inline void F_15 ( struct V_1 * V_2 , T_1 V_8 , T_1 * V_4 )
{
F_5 ( V_2 , V_9 ,
V_8 & V_10 ) ;
F_1 ( V_2 , V_11 , V_4 ) ;
}
static inline void F_16 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_4 )
{
F_5 ( V_2 , V_9 ,
V_8 & V_10 ) ;
F_5 ( V_2 , V_11 , V_4 ) ;
}
static inline void F_17 ( struct V_1 * V_2 , T_1 V_8 , T_2 * V_4 )
{
F_5 ( V_2 , V_9 ,
V_8 & V_10 ) ;
F_7 ( V_2 , V_11 , V_4 ) ;
}
static inline void F_18 ( struct V_1 * V_2 , T_1 V_8 , T_2 V_4 )
{
F_5 ( V_2 , V_9 ,
V_8 & V_10 ) ;
F_11 ( V_2 , V_11 , V_4 ) ;
}
static inline void F_19 ( struct V_1 * V_2 , T_1 V_8 , T_3 * V_4 )
{
F_5 ( V_2 , V_9 ,
V_8 & V_10 ) ;
F_9 ( V_2 , V_11 , V_4 ) ;
}
static inline void F_20 ( struct V_1 * V_2 , T_1 V_8 , T_3 V_4 )
{
F_5 ( V_2 , V_9 ,
V_8 & V_10 ) ;
F_13 ( V_2 , V_11 , V_4 ) ;
}
static inline void F_21 ( struct V_1 * V_2 , T_1 V_8 )
{
F_5 ( V_2 , V_12 ,
V_8 & V_10 ) ;
}
static inline void F_22 ( struct V_1 * V_2 , T_1 V_4 )
{
F_5 ( V_2 , V_13 , V_4 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_14 ,
const T_3 * V_15 )
{
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
T_1 V_19 ;
V_16 = V_8 & ( ~ 0x3 ) ;
V_18 = V_8 - V_16 ;
if ( V_18 ) {
F_5 ( V_2 , V_9 ,
V_16 ) ;
for ( V_19 = V_18 ; V_19 < 4 ; V_19 ++ , V_15 ++ )
F_13 ( V_2 ,
V_11 + V_19 ,
* V_15 ) ;
V_14 -= V_18 ;
V_16 += 4 ;
}
F_5 ( V_2 , V_12 , V_16 ) ;
V_17 = V_14 & ( ~ 0x3 ) ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 += 4 , V_15 += 4 , V_16 += 4 )
F_5 ( V_2 , V_13 , * ( T_1 * ) V_15 ) ;
V_18 = V_14 - V_17 ;
F_5 ( V_2 , V_9 , V_16 ) ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ , V_15 ++ )
F_13 ( V_2 , V_11 + V_19 ,
* V_15 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_14 ,
T_3 * V_15 )
{
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
T_1 V_19 ;
V_16 = V_8 & ( ~ 0x3 ) ;
V_18 = V_8 - V_16 ;
if ( V_18 ) {
F_5 ( V_2 , V_9 ,
V_16 ) ;
for ( V_19 = V_18 ; V_19 < 4 ; V_19 ++ , V_15 ++ )
F_9 ( V_2 ,
V_11 + V_19 ,
V_15 ) ;
V_14 -= V_18 ;
V_16 += 4 ;
}
F_5 ( V_2 , V_12 , V_16 ) ;
V_17 = V_14 & ( ~ 0x3 ) ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 += 4 , V_15 += 4 , V_16 += 4 )
F_1 ( V_2 , V_13 , ( T_1 * ) V_15 ) ;
V_18 = V_14 - V_17 ;
F_5 ( V_2 , V_9 , V_16 ) ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ , V_15 ++ )
F_9 ( V_2 , V_11 + V_19 , V_15 ) ;
}
static bool F_25 ( struct V_1 * V_2 )
{
T_1 V_20 ;
F_1 ( V_2 , V_21 , & V_20 ) ;
return V_20 == V_22 ;
}
static int F_26 ( struct V_5 * V_6 , T_1 V_23 ,
void * V_4 , T_1 * V_14 )
{
struct V_24 * V_25 = & V_6 -> V_25 ;
T_1 V_8 ;
T_1 V_26 ;
T_2 V_27 ;
T_2 V_28 ;
T_1 V_29 ;
if ( V_25 -> V_30 == 0 ) {
F_27 (KERN_WARNING DRV_NAME L_7
L_8 ) ;
return - V_31 ;
}
if ( F_28 ( V_25 , V_23 ) ) {
if ( * V_14 < V_32 ) {
* V_14 = V_32 ;
F_27 (KERN_WARNING DRV_NAME
L_9 ,
IPW_ORD_TAB_1_ENTRY_SIZE) ;
return - V_31 ;
}
F_15 ( V_6 -> V_33 ,
V_25 -> V_30 + ( V_23 << 2 ) , & V_8 ) ;
F_15 ( V_6 -> V_33 , V_8 , V_4 ) ;
* V_14 = V_32 ;
return 0 ;
}
if ( F_29 ( V_25 , V_23 ) ) {
V_23 -= V_34 ;
F_15 ( V_6 -> V_33 ,
V_25 -> V_35 + ( V_23 << 3 ) , & V_8 ) ;
F_15 ( V_6 -> V_33 ,
V_25 -> V_35 + ( V_23 << 3 ) + sizeof( T_1 ) ,
& V_26 ) ;
V_27 = * ( ( T_2 * ) & V_26 ) ;
V_28 = * ( ( ( T_2 * ) & V_26 ) + 1 ) ;
V_29 = V_27 * V_28 ;
if ( V_29 > * V_14 ) {
* V_14 = V_29 ;
return - V_31 ;
}
* V_14 = V_29 ;
if ( ! V_29 )
return 0 ;
F_24 ( V_6 -> V_33 , V_8 , V_29 , V_4 ) ;
return 0 ;
}
F_27 (KERN_WARNING DRV_NAME L_10
L_11 , ord) ;
return - V_31 ;
}
static int F_30 ( struct V_5 * V_6 , T_1 V_23 , T_1 * V_4 ,
T_1 * V_14 )
{
struct V_24 * V_25 = & V_6 -> V_25 ;
T_1 V_8 ;
if ( F_28 ( V_25 , V_23 ) ) {
if ( * V_14 != V_32 ) {
* V_14 = V_32 ;
F_31 ( L_12 ) ;
return - V_31 ;
}
F_15 ( V_6 -> V_33 ,
V_25 -> V_30 + ( V_23 << 2 ) , & V_8 ) ;
F_16 ( V_6 -> V_33 , V_8 , * V_4 ) ;
* V_14 = V_32 ;
return 0 ;
}
F_31 ( L_13 ) ;
if ( F_29 ( V_25 , V_23 ) )
return - V_31 ;
return - V_31 ;
}
static char * F_32 ( char * V_15 , T_4 V_36 ,
const T_3 * V_37 , T_1 V_14 , T_1 V_38 )
{
int V_39 , V_19 , V_40 , V_41 ;
char V_42 ;
V_39 = snprintf ( V_15 , V_36 , L_14 , V_38 ) ;
for ( V_41 = 0 , V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
V_39 += snprintf ( V_15 + V_39 , V_36 - V_39 , L_15 ) ;
for ( V_40 = 0 ; V_40 < 8 && V_41 < V_14 ; V_40 ++ , V_41 ++ )
V_39 += snprintf ( V_15 + V_39 , V_36 - V_39 , L_16 ,
V_37 [ ( V_19 * 8 + V_40 ) ] ) ;
for (; V_40 < 8 ; V_40 ++ )
V_39 += snprintf ( V_15 + V_39 , V_36 - V_39 , L_17 ) ;
}
V_39 += snprintf ( V_15 + V_39 , V_36 - V_39 , L_15 ) ;
for ( V_41 = 0 , V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
V_39 += snprintf ( V_15 + V_39 , V_36 - V_39 , L_15 ) ;
for ( V_40 = 0 ; V_40 < 8 && V_41 < V_14 ; V_40 ++ , V_41 ++ ) {
V_42 = V_37 [ ( V_19 * 8 + V_40 ) ] ;
if ( ! isascii ( V_42 ) || ! isprint ( V_42 ) )
V_42 = '.' ;
V_39 += snprintf ( V_15 + V_39 , V_36 - V_39 , L_18 , V_42 ) ;
}
for (; V_40 < 8 ; V_40 ++ )
V_39 += snprintf ( V_15 + V_39 , V_36 - V_39 , L_15 ) ;
}
return V_15 ;
}
static void F_33 ( int V_43 , const T_3 * V_37 , T_1 V_14 )
{
char line [ 81 ] ;
T_1 V_38 = 0 ;
if ( ! ( V_44 & V_43 ) )
return;
while ( V_14 ) {
F_27 ( V_45 L_19 ,
F_32 ( line , sizeof( line ) , & V_37 [ V_38 ] ,
F_34 ( V_14 , 16U ) , V_38 ) ) ;
V_38 += 16 ;
V_14 -= F_34 ( V_14 , 16U ) ;
}
}
static void F_35 ( struct V_5 * V_6 )
{
unsigned long V_46 = F_36 () ;
if ( V_6 -> V_47 &&
( V_46 - V_6 -> V_48 > V_6 -> V_47 ) )
V_6 -> V_47 = 0 ;
V_6 -> V_48 = F_36 () ;
if ( ! ( V_6 -> V_49 & V_50 ) ) {
F_31 ( L_20 ,
V_6 -> V_33 -> V_51 , V_6 -> V_47 ) ;
F_37 ( V_6 -> V_33 ) ;
F_38 ( V_6 -> V_33 ) ;
V_6 -> V_49 |= V_50 ;
if ( V_6 -> V_47 )
F_39 ( & V_6 -> V_52 ,
V_6 -> V_47 * V_53 ) ;
else
F_39 ( & V_6 -> V_52 , 0 ) ;
if ( V_6 -> V_47 < V_54 )
V_6 -> V_47 ++ ;
F_40 ( & V_6 -> V_55 ) ;
} else
F_31 ( L_21 ,
V_6 -> V_33 -> V_51 ) ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_56 * V_57 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
unsigned long V_62 ;
int V_63 = 0 ;
F_42 ( L_22 ,
V_64 [ V_57 -> V_56 ] , V_57 -> V_56 ,
V_57 -> V_65 ) ;
F_33 ( V_66 , ( T_3 * ) V_57 -> V_67 ,
V_57 -> V_65 ) ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( V_6 -> V_69 ) {
F_31
( L_23 ) ;
V_63 = - V_70 ;
goto V_71;
}
if ( ! ( V_6 -> V_49 & V_72 ) ) {
F_31
( L_24 ) ;
V_63 = - V_70 ;
goto V_71;
}
if ( V_6 -> V_49 & V_73 ) {
F_31
( L_25 ) ;
V_63 = - V_74 ;
goto V_71;
}
if ( F_44 ( & V_6 -> V_75 ) ) {
F_31 ( L_26 ) ;
goto V_71;
}
V_6 -> V_49 |= V_73 ;
V_6 -> V_76 ++ ;
V_59 = V_6 -> V_75 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
V_61 -> V_79 = V_80 ;
V_61 -> V_81 . V_82 . V_57 -> V_83 = V_57 -> V_56 ;
V_61 -> V_81 . V_82 . V_57 -> V_84 = V_57 -> V_85 ;
V_61 -> V_81 . V_82 . V_57 -> V_86 =
V_57 -> V_65 ;
V_61 -> V_81 . V_82 . V_57 -> V_87 = V_57 -> V_88 ;
memcpy ( V_61 -> V_81 . V_82 . V_57 -> V_89 ,
V_57 -> V_67 ,
sizeof( V_61 -> V_81 . V_82 . V_57 -> V_89 ) ) ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_90 ) ;
F_48 ( V_59 , & V_6 -> V_91 ) ;
F_49 ( & V_6 -> V_92 ) ;
F_50 ( V_6 ) ;
F_51 ( V_6 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
V_63 =
F_53 ( V_6 -> V_55 ,
! ( V_6 ->
V_49 & V_73 ) ,
V_93 ) ;
if ( V_63 == 0 ) {
F_31 ( L_27 ,
1000 * ( V_93 / V_53 ) ) ;
V_6 -> V_69 = V_94 ;
V_6 -> V_49 &= ~ V_73 ;
F_35 ( V_6 ) ;
return - V_70 ;
}
if ( V_6 -> V_69 ) {
F_27 (KERN_WARNING DRV_NAME L_28 ,
priv->net_dev->name) ;
return - V_70 ;
}
F_54 ( F_55 ( 10 ) ) ;
return 0 ;
V_71:
F_52 ( & V_6 -> V_68 , V_62 ) ;
return V_63 ;
}
static int F_56 ( struct V_5 * V_6 )
{
T_1 V_95 , V_96 ;
T_1 V_97 ;
T_1 V_98 = 0x76543210 ;
T_1 V_99 = 0xFEDCBA98 ;
for ( V_97 = V_21 ;
V_97 < V_100 ; V_97 += sizeof( T_1 ) ) {
F_1 ( V_6 -> V_33 , V_97 , & V_95 ) ;
if ( V_95 != V_22 )
return - V_70 ;
}
for ( V_97 = 0 ; V_97 < 5 ; V_97 ++ ) {
F_5 ( V_6 -> V_33 , V_101 + 0x32 ,
V_98 ) ;
F_5 ( V_6 -> V_33 , V_101 + 0x36 ,
V_99 ) ;
F_1 ( V_6 -> V_33 , V_101 + 0x32 ,
& V_95 ) ;
F_1 ( V_6 -> V_33 , V_101 + 0x36 ,
& V_96 ) ;
if ( V_98 == V_95 && V_99 == V_96 )
return 0 ;
}
return - V_70 ;
}
static int F_57 ( struct V_5 * V_6 , int V_102 )
{
int V_19 ;
T_1 V_103 ;
T_1 V_14 = sizeof( V_103 ) ;
int V_63 ;
for ( V_19 = 0 ; V_19 <= V_104 * 1000 ; V_19 += 50 ) {
V_63 = F_26 ( V_6 , V_105 ,
& V_103 , & V_14 ) ;
if ( V_63 ) {
F_31 ( L_29
L_30 ) ;
return 0 ;
}
if ( ( V_103 == V_102 ) ||
( ( V_6 -> V_49 & V_106 ) ?
V_107 : V_108 ) == V_102 ) {
if ( V_102 == V_107 )
V_6 -> V_49 |= V_106 ;
else
V_6 -> V_49 &= ~ V_106 ;
return 0 ;
}
F_58 ( 50 ) ;
}
F_31 ( L_31 ,
V_102 ? L_32 : L_33 ) ;
return - V_70 ;
}
static int F_59 ( struct V_5 * V_6 )
{
int V_19 ;
T_1 V_109 ;
F_5 ( V_6 -> V_33 , V_110 ,
V_111 ) ;
for ( V_19 = 0 ; V_19 < 1000 ; V_19 ++ ) {
F_58 ( V_112 ) ;
F_1 ( V_6 -> V_33 , V_110 , & V_109 ) ;
if ( V_109 & V_113 )
break;
}
if ( V_19 == 1000 )
return - V_70 ;
F_5 ( V_6 -> V_33 , V_114 ,
V_115 ) ;
for ( V_19 = 0 ; V_19 < 10000 ; V_19 ++ ) {
F_58 ( V_116 * 4 ) ;
F_1 ( V_6 -> V_33 , V_114 , & V_109 ) ;
if ( V_109 & V_117 )
break;
}
if ( V_19 == 10000 )
return - V_70 ;
F_1 ( V_6 -> V_33 , V_114 , & V_109 ) ;
F_5 ( V_6 -> V_33 , V_114 ,
V_109 | V_118 ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 )
{
T_1 V_97 ;
int V_63 ;
#ifndef F_61
struct V_119 V_120 ;
#endif
if ( V_6 -> V_69 ) {
F_62 ( L_34
L_35 ,
V_6 -> V_33 -> V_51 , V_6 -> V_69 ) ;
return - V_31 ;
}
#ifdef F_61
if ( ! V_120 . V_121 ) {
V_63 = F_63 ( V_6 , & V_120 ) ;
if ( V_63 ) {
F_62 ( L_36 ,
V_6 -> V_33 -> V_51 , V_63 ) ;
V_6 -> V_69 = V_122 ;
goto V_123;
}
}
#else
V_63 = F_63 ( V_6 , & V_120 ) ;
if ( V_63 ) {
F_62 ( L_36 ,
V_6 -> V_33 -> V_51 , V_63 ) ;
V_6 -> V_69 = V_122 ;
goto V_123;
}
#endif
V_6 -> V_124 = V_120 . V_121 ;
V_63 = F_59 ( V_6 ) ;
if ( V_63 ) {
F_62 ( L_37 ,
V_6 -> V_33 -> V_51 , V_63 ) ;
goto V_123;
}
V_63 = F_56 ( V_6 ) ;
if ( V_63 ) {
F_62 ( L_38 ,
V_6 -> V_33 -> V_51 , V_63 ) ;
goto V_123;
}
F_16 ( V_6 -> V_33 ,
V_125 , 0x80000000 ) ;
F_5 ( V_6 -> V_33 , V_110 , 0 ) ;
V_63 = F_64 ( V_6 , & V_120 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME L_39 ,
priv->net_dev->name, err) ;
goto V_123;
}
F_16 ( V_6 -> V_33 ,
V_125 , 0x00000000 ) ;
V_63 = F_59 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_40 ,
priv->net_dev->name, err) ;
goto V_123;
}
V_63 = F_65 ( V_6 , & V_120 ) ;
if ( V_63 ) {
F_62 ( L_41 ,
V_6 -> V_33 -> V_51 , V_63 ) ;
goto V_123;
}
#ifndef F_61
F_66 ( V_6 , & V_120 ) ;
#endif
for ( V_97 = V_126 ;
V_97 < V_127 ; V_97 += 4 )
F_16 ( V_6 -> V_33 , V_97 , 0 ) ;
for ( V_97 = V_128 ;
V_97 < V_129 ; V_97 += 4 )
F_16 ( V_6 -> V_33 , V_97 , 0 ) ;
for ( V_97 = V_130 ;
V_97 < V_131 ; V_97 += 4 )
F_16 ( V_6 -> V_33 , V_97 , 0 ) ;
for ( V_97 = V_132 ;
V_97 < V_133 ; V_97 += 4 )
F_16 ( V_6 -> V_33 , V_97 , 0 ) ;
for ( V_97 = V_134 ;
V_97 < V_135 ; V_97 += 4 )
F_16 ( V_6 -> V_33 , V_97 , 0 ) ;
return 0 ;
V_123:
F_66 ( V_6 , & V_120 ) ;
return V_63 ;
}
static inline void F_67 ( struct V_5 * V_6 )
{
if ( V_6 -> V_49 & V_136 )
return;
V_6 -> V_49 |= V_136 ;
F_5 ( V_6 -> V_33 , V_137 , V_138 ) ;
}
static inline void F_68 ( struct V_5 * V_6 )
{
if ( ! ( V_6 -> V_49 & V_136 ) )
return;
V_6 -> V_49 &= ~ V_136 ;
F_5 ( V_6 -> V_33 , V_137 , 0x0 ) ;
}
static void F_69 ( struct V_5 * V_6 )
{
struct V_24 * V_23 = & V_6 -> V_25 ;
F_31 ( L_42 ) ;
F_1 ( V_6 -> V_33 , V_139 ,
& V_23 -> V_30 ) ;
F_1 ( V_6 -> V_33 , V_140 ,
& V_23 -> V_35 ) ;
F_15 ( V_6 -> V_33 , V_23 -> V_30 , & V_23 -> V_141 ) ;
F_15 ( V_6 -> V_33 , V_23 -> V_35 , & V_23 -> V_142 ) ;
V_23 -> V_142 &= 0x0000FFFF ;
F_31 ( L_43 , V_23 -> V_141 ) ;
F_31 ( L_44 , V_23 -> V_142 ) ;
F_31 ( L_45 ) ;
}
static inline void F_70 ( struct V_5 * V_6 )
{
T_1 V_3 = 0 ;
V_3 = ( V_143 | V_144 |
V_145 ) ;
F_5 ( V_6 -> V_33 , V_146 , V_3 ) ;
}
static int F_71 ( struct V_5 * V_6 )
{
#define F_72 5
#define F_73 40
unsigned short V_147 = 0 ;
T_1 V_3 = 0 ;
int V_19 ;
if ( ! ( V_6 -> V_148 & V_149 ) ) {
F_74 ( V_6 -> V_150 -> V_151 . V_152 , false ) ;
V_6 -> V_49 &= ~ V_153 ;
return 0 ;
}
for ( V_19 = 0 ; V_19 < F_72 ; V_19 ++ ) {
F_58 ( F_73 ) ;
F_1 ( V_6 -> V_33 , V_146 , & V_3 ) ;
V_147 = ( V_147 << 1 ) | ( ( V_3 & V_154 ) ? 0 : 1 ) ;
}
if ( V_147 == 0 ) {
F_74 ( V_6 -> V_150 -> V_151 . V_152 , true ) ;
V_6 -> V_49 |= V_153 ;
} else {
F_74 ( V_6 -> V_150 -> V_151 . V_152 , false ) ;
V_6 -> V_49 &= ~ V_153 ;
}
return ( V_147 == 0 ) ;
}
static int F_75 ( struct V_5 * V_6 )
{
T_1 V_8 , V_14 ;
T_1 V_4 ;
V_14 = sizeof( V_8 ) ;
if ( F_26
( V_6 , V_155 , & V_8 , & V_14 ) ) {
F_31 ( L_46 ,
__LINE__ ) ;
return - V_70 ;
}
F_31 ( L_47 , V_8 ) ;
F_15 ( V_6 -> V_33 , V_8 + 0xFC , & V_4 ) ;
V_6 -> V_156 = ( V_4 >> 24 ) & 0xFF ;
F_31 ( L_48 , V_6 -> V_156 ) ;
F_15 ( V_6 -> V_33 , V_8 + 0x20 , & V_4 ) ;
if ( ! ( ( V_4 >> 24 ) & 0x01 ) )
V_6 -> V_148 |= V_149 ;
F_31 ( L_49 ,
( V_6 -> V_148 & V_149 ) ? L_50 : L_51 ) ;
return 0 ;
}
static int F_76 ( struct V_5 * V_6 )
{
int V_19 ;
T_1 V_157 , V_158 , V_159 ;
F_31 ( L_42 ) ;
if ( V_6 -> V_49 & V_72 )
return 0 ;
if ( F_60 ( V_6 ) ) {
F_27 (KERN_ERR DRV_NAME
L_52 ,
priv->net_dev->name) ;
return - V_70 ;
}
F_77 ( V_6 ) ;
F_70 ( V_6 ) ;
F_5 ( V_6 -> V_33 , V_110 , 0 ) ;
F_78 ( L_53 ) ;
V_19 = 5000 ;
do {
F_54 ( F_55 ( 40 ) ) ;
F_1 ( V_6 -> V_33 , V_160 , & V_157 ) ;
if ( V_157 & V_161 ) {
F_5 ( V_6 -> V_33 , V_160 ,
V_161 ) ;
break;
}
if ( V_157 &
( V_162 | V_163 ) ) {
F_5 ( V_6 -> V_33 , V_160 ,
V_162 |
V_163 ) ;
}
} while ( -- V_19 );
F_1 ( V_6 -> V_33 , V_160 , & V_157 ) ;
F_1 ( V_6 -> V_33 , V_137 , & V_158 ) ;
V_157 &= V_138 ;
if ( V_157 & V_158 )
F_5 ( V_6 -> V_33 , V_160 , V_157 ) ;
F_78 ( L_54 ,
V_19 ? L_55 : L_56 ) ;
if ( ! V_19 ) {
F_27 (KERN_WARNING DRV_NAME
L_57 ,
priv->net_dev->name) ;
return - V_70 ;
}
F_1 ( V_6 -> V_33 , V_146 , & V_159 ) ;
V_159 |= ( V_164 | V_143 ) ;
F_5 ( V_6 -> V_33 , V_146 , V_159 ) ;
V_6 -> V_49 |= V_72 ;
V_6 -> V_49 &= ~ ( V_165 | V_166 ) ;
F_31 ( L_45 ) ;
return 0 ;
}
static inline void F_79 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_69 )
return;
V_6 -> V_167 [ V_6 -> V_168 ++ ] = V_6 -> V_69 ;
V_6 -> V_168 %= V_169 ;
V_6 -> V_69 = 0 ;
}
static int F_80 ( struct V_5 * V_6 )
{
T_1 V_3 ;
int V_19 ;
F_31 ( L_58 ) ;
F_70 ( V_6 ) ;
F_5 ( V_6 -> V_33 , V_110 ,
V_170 ) ;
V_19 = 5 ;
do {
F_58 ( V_171 ) ;
F_1 ( V_6 -> V_33 , V_110 , & V_3 ) ;
if ( V_3 & V_172 )
break;
} while ( -- V_19 );
V_6 -> V_49 &= ~ V_50 ;
if ( ! V_19 ) {
F_31
( L_59 ) ;
return - V_70 ;
}
F_5 ( V_6 -> V_33 , V_110 ,
V_111 ) ;
F_79 ( V_6 ) ;
V_6 -> V_49 &= ~ ( V_72 | V_165 |
V_166 | V_106 ) ;
return 0 ;
}
static int F_81 ( struct V_5 * V_6 )
{
#define F_82 (HZ / 5000)
struct V_56 V_57 = {
. V_56 = V_173 ,
. V_88 = 0 ,
. V_65 = 0 ,
} ;
int V_63 , V_19 ;
T_1 V_98 , V_99 ;
F_42 ( L_60 ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
for ( V_19 = 0 ; V_19 < 2500 ; V_19 ++ ) {
F_15 ( V_6 -> V_33 , V_174 , & V_98 ) ;
F_15 ( V_6 -> V_33 , V_175 , & V_99 ) ;
if ( ( V_98 & V_176 ) &&
( V_99 & V_177 ) )
return 0 ;
F_54 ( F_82 ) ;
}
return - V_70 ;
}
static int F_83 ( struct V_5 * V_6 )
{
struct V_56 V_57 = {
. V_56 = V_178 ,
. V_88 = 0 ,
. V_65 = 0
} ;
int V_63 = 0 ;
F_42 ( L_61 ) ;
if ( V_6 -> V_49 & V_106 )
return 0 ;
F_84 ( & V_6 -> V_179 ) ;
if ( F_71 ( V_6 ) ) {
F_42 ( L_62 ) ;
goto V_180;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 ) {
F_31 ( L_63 ) ;
goto V_180;
}
V_63 = F_57 ( V_6 , V_107 ) ;
if ( V_63 ) {
F_31 ( L_64 ,
V_6 -> V_33 -> V_51 ) ;
goto V_180;
}
if ( V_6 -> V_181 ) {
V_6 -> V_181 = 0 ;
F_39 ( & V_6 -> V_182 , V_53 / 2 ) ;
}
V_180:
F_85 ( & V_6 -> V_179 ) ;
return V_63 ;
}
static int F_86 ( struct V_5 * V_6 )
{
#define F_87 (msecs_to_jiffies(100))
struct V_56 V_57 = {
. V_56 = V_183 ,
. V_88 = 0 ,
. V_65 = 0 ,
} ;
int V_63 , V_19 ;
T_1 V_3 ;
if ( ! ( V_6 -> V_49 & V_72 ) )
return 0 ;
V_6 -> V_49 |= V_184 ;
if ( ! V_6 -> V_69 ) {
F_83 ( V_6 ) ;
V_63 = F_81 ( V_6 ) ;
if ( V_63 )
F_27 (KERN_WARNING DRV_NAME
L_65 , err) ;
F_42 ( L_66 ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
F_27 (KERN_WARNING DRV_NAME L_67
L_68 ,
priv->net_dev->name, err) ;
else
F_54 ( F_87 ) ;
}
V_6 -> V_49 &= ~ V_106 ;
F_70 ( V_6 ) ;
F_5 ( V_6 -> V_33 , V_110 ,
V_170 ) ;
for ( V_19 = 5 ; V_19 > 0 ; V_19 -- ) {
F_58 ( 10 ) ;
F_1 ( V_6 -> V_33 , V_110 , & V_3 ) ;
if ( V_3 & V_172 )
break;
}
if ( V_19 == 0 )
F_27 (KERN_WARNING DRV_NAME
L_69 ,
priv->net_dev->name) ;
F_5 ( V_6 -> V_33 , V_110 ,
V_111 ) ;
V_6 -> V_49 &= ~ ( V_72 | V_184 ) ;
return 0 ;
}
static int F_88 ( struct V_5 * V_6 )
{
struct V_56 V_57 = {
. V_56 = V_185 ,
. V_88 = 0 ,
. V_65 = 0
} ;
int V_63 = 0 ;
F_42 ( L_70 ) ;
if ( ! ( V_6 -> V_49 & V_106 ) )
return 0 ;
V_6 -> V_49 &= ~ ( V_166 | V_165 ) ;
if ( ! V_6 -> V_181 ) {
V_6 -> V_181 = 1 ;
F_89 ( & V_6 -> V_182 ) ;
}
F_84 ( & V_6 -> V_179 ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_71 ) ;
goto V_180;
}
V_63 = F_57 ( V_6 , V_108 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_72 ) ;
goto V_180;
}
F_31 ( L_73 ) ;
V_180:
F_85 ( & V_6 -> V_179 ) ;
return V_63 ;
}
static int F_90 ( struct V_5 * V_6 )
{
struct V_56 V_57 = {
. V_56 = V_186 ,
. V_88 = 0 ,
. V_65 = 8
} ;
int V_63 ;
F_31 ( L_42 ) ;
F_91 ( L_74 ) ;
V_57 . V_67 [ 0 ] = 0 ;
if ( ! ( V_6 -> V_187 & V_188 ) )
V_57 . V_67 [ 0 ] |= V_189 ;
if ( ( V_6 -> V_150 -> V_190 . V_62 & V_191 ) && V_6 -> V_150 -> V_190 . V_192 )
V_57 . V_67 [ 0 ] |= V_193 ;
if ( V_6 -> V_187 & V_194 )
V_57 . V_67 [ 0 ] |= V_195 ;
V_57 . V_67 [ 1 ] = V_6 -> V_196 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
F_42 ( L_75 ,
V_57 . V_67 [ 0 ] ) ;
return V_63 ;
}
static int F_92 ( struct V_5 * V_6 )
{
struct V_56 V_57 = {
. V_56 = V_197 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
F_42 ( L_76 ) ;
V_57 . V_67 [ 0 ] = 0 ;
if ( V_6 -> V_150 -> V_198 == V_199 )
return 1 ;
if ( V_6 -> V_49 & V_200 ) {
F_91 ( L_77 ) ;
return 0 ;
}
F_31 ( L_42 ) ;
F_91 ( L_78 ) ;
V_6 -> V_49 |= V_200 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
V_6 -> V_49 &= ~ V_200 ;
F_31 ( L_45 ) ;
return V_63 ;
}
static int F_93 ( struct V_5 * V_6 , int V_201 )
{
unsigned long V_62 ;
int V_202 = 0 ;
T_1 V_203 ;
T_1 V_204 = sizeof( V_203 ) ;
if ( V_6 -> V_205 ) {
F_94 ( V_6 -> V_150 , V_6 -> V_205 ) ;
V_6 -> V_205 = 0 ;
}
if ( V_6 -> V_49 & V_206 ) {
F_31 ( L_79
L_80 , V_6 -> V_33 -> V_51 ) ;
return 0 ;
}
F_95 ( & V_207 , 175 ) ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
F_68 ( V_6 ) ;
F_79 ( V_6 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
if ( V_6 -> V_49 & V_208 ||
( V_6 -> V_49 & V_50 ) ) {
if ( F_80 ( V_6 ) ) {
F_27 (KERN_WARNING DRV_NAME
L_81 ,
priv->net_dev->name) ;
V_202 = 1 ;
goto exit;
}
} else
V_6 -> V_49 |= V_208 ;
if ( F_76 ( V_6 ) ) {
F_27 (KERN_ERR DRV_NAME
L_82 ,
priv->net_dev->name) ;
V_202 = 1 ;
goto exit;
}
F_69 ( V_6 ) ;
if ( F_75 ( V_6 ) ) {
F_27 (KERN_ERR DRV_NAME
L_83 ,
priv->net_dev->name) ;
V_202 = 1 ;
goto exit;
}
F_96 ( V_6 -> V_150 , & V_209 [ 0 ] ) ;
V_6 -> V_150 -> V_210 = V_211 ;
V_203 = V_212 ;
if ( F_30 ( V_6 , V_213 , & V_203 , & V_204 ) ) {
F_27 (KERN_ERR DRV_NAME
L_84 ,
priv->net_dev->name) ;
V_202 = 1 ;
goto exit;
}
V_6 -> V_49 &= ~ V_200 ;
if ( F_71 ( V_6 ) ) {
F_27 ( V_214 L_85 ,
V_6 -> V_33 -> V_51 ) ;
if ( V_6 -> V_215 ) {
V_6 -> V_215 = 0 ;
F_39 ( & V_6 -> V_216 ,
F_97 ( V_53 ) ) ;
}
V_201 = 1 ;
}
F_67 ( V_6 ) ;
if ( F_98 ( V_6 ) ) {
F_27 (KERN_ERR DRV_NAME L_86 ,
priv->net_dev->name) ;
V_202 = 1 ;
goto exit;
}
if ( ! V_201 ) {
if ( F_83 ( V_6 ) ) {
F_27 (KERN_ERR DRV_NAME L_67
L_87 ,
priv->net_dev->name) ;
F_86 ( V_6 ) ;
V_202 = 1 ;
goto exit;
}
F_90 ( V_6 ) ;
F_92 ( V_6 ) ;
}
exit:
return V_202 ;
}
static void F_99 ( struct V_5 * V_6 )
{
unsigned long V_62 ;
union V_217 V_218 = {
. V_219 = {
. V_220 = V_221 }
} ;
int V_222 = V_6 -> V_49 & V_166 ;
if ( ! V_6 -> V_215 ) {
V_6 -> V_215 = 1 ;
F_89 ( & V_6 -> V_216 ) ;
}
if ( ! V_6 -> V_181 ) {
V_6 -> V_181 = 1 ;
F_89 ( & V_6 -> V_182 ) ;
}
if ( V_6 -> V_49 & V_50 )
F_89 ( & V_6 -> V_52 ) ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
F_67 ( V_6 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
if ( F_86 ( V_6 ) )
F_27 (KERN_ERR DRV_NAME L_88 ,
priv->net_dev->name) ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
F_68 ( V_6 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
F_95 ( & V_207 , V_223 ) ;
if ( V_222 )
F_100 ( V_6 -> V_33 , V_224 , & V_218 , NULL ) ;
V_6 -> V_49 &= ~ ( V_166 | V_165 ) ;
F_37 ( V_6 -> V_33 ) ;
F_38 ( V_6 -> V_33 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_225 * V_226 = F_102 ( V_6 -> V_150 ) ;
struct V_227 * V_151 = & V_6 -> V_150 -> V_151 ;
int V_19 ;
memcpy ( V_151 -> V_152 -> V_228 , V_6 -> V_229 , V_230 ) ;
if ( V_226 -> V_231 ) {
struct V_232 * V_233 = & V_6 -> V_150 -> V_233 ;
V_233 -> V_234 = V_235 ;
V_233 -> V_236 = V_226 -> V_231 ;
V_233 -> V_237 = F_103 ( V_226 -> V_231 ,
sizeof( struct V_238 ) ,
V_239 ) ;
if ( ! V_233 -> V_237 ) {
F_99 ( V_6 ) ;
return - V_240 ;
}
for ( V_19 = 0 ; V_19 < V_226 -> V_231 ; V_19 ++ ) {
V_233 -> V_237 [ V_19 ] . V_234 = V_235 ;
V_233 -> V_237 [ V_19 ] . V_241 = V_226 -> V_242 [ V_19 ] . V_243 ;
V_233 -> V_237 [ V_19 ] . V_244 = V_226 -> V_242 [ V_19 ] . V_245 ;
V_233 -> V_237 [ V_19 ] . V_246 = V_226 -> V_242 [ V_19 ] . V_246 ;
if ( V_226 -> V_242 [ V_19 ] . V_62 & V_247 )
V_233 -> V_237 [ V_19 ] . V_62 |=
V_248 ;
if ( V_226 -> V_242 [ V_19 ] . V_62 & V_249 )
V_233 -> V_237 [ V_19 ] . V_62 |=
V_248 ;
if ( V_226 -> V_242 [ V_19 ] . V_62 & V_250 )
V_233 -> V_237 [ V_19 ] . V_62 |=
V_251 ;
}
V_233 -> V_252 = V_253 ;
V_233 -> V_254 = V_255 ;
V_151 -> V_152 -> V_256 [ V_235 ] = V_233 ;
}
V_151 -> V_152 -> V_257 = V_258 ;
V_151 -> V_152 -> V_259 = F_104 ( V_258 ) ;
F_105 ( V_151 -> V_152 , & V_6 -> V_260 -> V_2 ) ;
if ( F_106 ( V_151 -> V_152 ) )
return - V_70 ;
return 0 ;
}
static void F_107 ( struct V_261 * V_262 )
{
struct V_5 * V_6 =
F_108 ( V_262 , struct V_5 , V_52 . V_262 ) ;
unsigned long V_62 ;
union V_217 V_218 = {
. V_219 = {
. V_220 = V_221 }
} ;
int V_222 = V_6 -> V_49 & V_166 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
F_31 ( L_89 , V_6 -> V_33 -> V_51 ) ;
V_6 -> V_263 ++ ;
V_6 -> V_49 &= ~ ( V_166 | V_165 ) ;
V_6 -> V_49 |= V_264 ;
F_89 ( & V_6 -> V_52 ) ;
V_6 -> V_49 |= V_50 ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
F_84 ( & V_6 -> V_265 ) ;
V_6 -> V_181 = 1 ;
F_89 ( & V_6 -> V_182 ) ;
if ( V_222 )
F_100 ( V_6 -> V_33 , V_224 , & V_218 , NULL ) ;
F_93 ( V_6 , 0 ) ;
F_85 ( & V_6 -> V_265 ) ;
}
static void F_109 ( struct V_5 * V_6 , T_1 V_49 )
{
#define F_110 (HZ)
int V_266 ;
unsigned int V_14 , V_267 ;
char V_268 [ V_269 ] ;
T_1 V_270 ;
T_1 V_271 ;
char * V_272 ;
T_3 V_273 [ V_230 ] ;
F_111 ( V_274 ) ;
V_267 = V_269 ;
V_266 = F_26 ( V_6 , V_275 ,
V_268 , & V_267 ) ;
if ( V_266 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
V_14 = sizeof( T_1 ) ;
V_266 = F_26 ( V_6 , V_276 , & V_270 , & V_14 ) ;
if ( V_266 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
V_14 = sizeof( T_1 ) ;
V_266 = F_26 ( V_6 , V_277 , & V_271 , & V_14 ) ;
if ( V_266 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
V_14 = V_230 ;
V_266 = F_26 ( V_6 , V_278 , V_273 ,
& V_14 ) ;
if ( V_266 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
memcpy ( V_6 -> V_150 -> V_273 , V_273 , V_230 ) ;
switch ( V_270 ) {
case V_279 :
V_272 = L_90 ;
break;
case V_280 :
V_272 = L_91 ;
break;
case V_281 :
V_272 = L_92 ;
break;
case V_282 :
V_272 = L_93 ;
break;
default:
F_31 ( L_94 , V_270 ) ;
V_272 = L_95 ;
break;
}
F_31 ( L_96 ,
V_6 -> V_33 -> V_51 , F_112 ( V_274 , V_268 , V_267 ) ,
V_272 , V_271 , V_273 ) ;
if ( ! ( V_6 -> V_187 & V_283 ) ) {
V_6 -> V_267 = F_34 ( ( T_3 ) V_267 , ( T_3 ) V_269 ) ;
memcpy ( V_6 -> V_268 , V_268 , V_6 -> V_267 ) ;
}
V_6 -> V_245 = V_271 ;
memcpy ( V_6 -> V_273 , V_273 , V_230 ) ;
V_6 -> V_49 |= V_165 ;
V_6 -> V_284 = F_36 () ;
F_39 ( & V_6 -> V_285 , V_53 / 10 ) ;
}
static int F_113 ( struct V_5 * V_6 , char * V_268 ,
int V_286 , int V_287 )
{
int V_288 = F_34 ( V_286 , V_269 ) ;
struct V_56 V_57 = {
. V_56 = V_289 ,
. V_88 = 0 ,
. V_65 = V_288
} ;
int V_63 ;
F_111 ( V_274 ) ;
F_42 ( L_97 , F_112 ( V_274 , V_268 , V_288 ) ) ;
if ( V_288 )
memcpy ( V_57 . V_67 , V_268 , V_288 ) ;
if ( ! V_287 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
if ( ! V_288 && ! ( V_6 -> V_187 & V_188 ) ) {
int V_19 ;
T_3 * V_290 = ( T_3 * ) V_57 . V_67 ;
for ( V_19 = 0 ; V_19 < V_269 ; V_19 ++ )
V_290 [ V_19 ] = 0x18 + V_19 ;
V_57 . V_65 = V_269 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_63 ) {
memset ( V_6 -> V_268 + V_288 , 0 , V_269 - V_288 ) ;
memcpy ( V_6 -> V_268 , V_268 , V_288 ) ;
V_6 -> V_267 = V_288 ;
}
if ( ! V_287 ) {
if ( F_83 ( V_6 ) )
V_63 = - V_70 ;
}
return V_63 ;
}
static void F_114 ( struct V_5 * V_6 , T_1 V_49 )
{
F_111 ( V_274 ) ;
F_115 ( V_291 | V_292 | V_293 ,
L_98 ,
F_112 ( V_274 , V_6 -> V_268 , V_6 -> V_267 ) ,
V_6 -> V_273 ) ;
V_6 -> V_49 &= ~ ( V_166 | V_165 ) ;
if ( V_6 -> V_49 & V_184 ) {
F_31 ( L_99 ) ;
return;
}
memset ( V_6 -> V_273 , 0 , V_230 ) ;
memset ( V_6 -> V_150 -> V_273 , 0 , V_230 ) ;
F_37 ( V_6 -> V_33 ) ;
F_38 ( V_6 -> V_33 ) ;
if ( ! ( V_6 -> V_49 & V_72 ) )
return;
if ( V_6 -> V_49 & V_264 )
F_39 ( & V_6 -> V_294 , 0 ) ;
F_39 ( & V_6 -> V_285 , 0 ) ;
}
static void F_116 ( struct V_5 * V_6 , T_1 V_49 )
{
F_31 ( L_100 ,
V_6 -> V_33 -> V_51 ) ;
F_74 ( V_6 -> V_150 -> V_151 . V_152 , true ) ;
V_6 -> V_49 |= V_153 ;
V_6 -> V_215 = 0 ;
F_117 ( V_295 , & V_6 -> V_216 , F_97 ( V_53 ) ) ;
}
static void F_118 ( struct V_261 * V_262 )
{
struct V_5 * V_6 = F_108 ( V_262 , struct V_5 ,
V_296 . V_262 ) ;
union V_217 V_218 ;
V_218 . V_37 . V_286 = 0 ;
V_218 . V_37 . V_62 = 0 ;
F_100 ( V_6 -> V_33 , V_297 , & V_218 , NULL ) ;
}
static void F_119 ( struct V_5 * V_6 , T_1 V_49 )
{
F_91 ( L_101 ) ;
V_6 -> V_150 -> V_298 ++ ;
V_6 -> V_49 &= ~ V_200 ;
if ( ! V_6 -> V_299 ) {
F_39 ( & V_6 -> V_296 ,
F_97 ( F_55 ( 4000 ) ) ) ;
} else {
V_6 -> V_299 = 0 ;
F_117 ( V_295 , & V_6 -> V_296 , 0 ) ;
}
}
static void F_120 ( struct V_5 * V_6 , T_1 V_49 )
{
F_91 ( L_102 ) ;
V_6 -> V_49 |= V_200 ;
}
static void F_121 ( struct V_5 * V_6 , int V_49 )
{
int V_19 ;
if ( V_49 == V_300 &&
V_6 -> V_49 & V_166 &&
! ( V_6 -> V_49 & V_200 ) ) {
F_31 ( L_103
L_104 ) ;
F_35 ( V_6 ) ;
}
for ( V_19 = 0 ; V_301 [ V_19 ] . V_49 != - 1 ; V_19 ++ ) {
if ( V_49 == V_301 [ V_19 ] . V_49 ) {
F_122 ( L_105 ,
V_301 [ V_19 ] . V_51 ) ;
if ( V_301 [ V_19 ] . V_302 )
V_301 [ V_19 ] . V_302 ( V_6 , V_49 ) ;
V_6 -> V_303 . V_49 = V_49 ;
return;
}
}
F_122 ( L_106 , V_49 ) ;
}
static void F_123 ( struct V_5 * V_6 ,
struct V_304 * V_57 )
{
#ifdef F_124
if ( V_57 -> V_83 < F_104 ( V_64 ) ) {
F_42 ( L_107 ,
V_64 [ V_57 -> V_83 ] ,
V_57 -> V_83 ) ;
}
#endif
if ( V_57 -> V_83 == V_178 )
V_6 -> V_49 |= V_106 ;
if ( V_57 -> V_83 == V_185 )
V_6 -> V_49 &= ~ V_106 ;
V_6 -> V_49 &= ~ V_73 ;
F_40 ( & V_6 -> V_55 ) ;
}
static int F_125 ( struct V_5 * V_6 ,
struct V_305 * V_61 )
{
V_61 -> V_306 = F_126 ( sizeof( struct V_307 ) ) ;
if ( ! V_61 -> V_306 )
return - V_240 ;
V_61 -> V_308 = (struct V_307 * ) V_61 -> V_306 -> V_37 ;
V_61 -> V_309 = F_127 ( V_6 -> V_260 , V_61 -> V_306 -> V_37 ,
sizeof( struct V_307 ) ,
V_310 ) ;
return 0 ;
}
static void F_128 ( struct V_5 * V_6 )
{
int V_19 ;
if ( ! V_6 -> V_311 [ 0 ] )
return;
for ( V_19 = 0 ; V_19 < 0x30 ; V_19 ++ )
F_129 ( V_6 -> V_311 [ V_19 ] ) ;
V_6 -> V_311 [ 0 ] = NULL ;
}
static int F_130 ( struct V_5 * V_6 )
{
int V_19 ;
if ( V_6 -> V_311 [ 0 ] )
return 1 ;
for ( V_19 = 0 ; V_19 < 0x30 ; V_19 ++ ) {
V_6 -> V_311 [ V_19 ] = F_131 ( 0x1000 , V_312 ) ;
if ( ! V_6 -> V_311 [ V_19 ] ) {
F_31 ( L_108
L_109 , V_6 -> V_33 -> V_51 , V_19 ) ;
while ( V_19 > 0 )
F_129 ( V_6 -> V_311 [ -- V_19 ] ) ;
V_6 -> V_311 [ 0 ] = NULL ;
return 0 ;
}
}
return 1 ;
}
static T_1 F_132 ( struct V_5 * V_6 , T_3 * V_313 ,
T_4 V_14 , int V_314 )
{
T_1 V_19 , V_40 ;
T_1 V_315 ;
T_3 * V_316 , * V_317 ;
T_1 V_266 ;
V_316 = V_313 ;
if ( V_314 == V_318 ) {
if ( ! F_130 ( V_6 ) )
V_314 = V_319 ;
}
for ( V_266 = V_320 , V_19 = 0 ; V_19 < 0x30000 ; V_19 += 4 ) {
F_15 ( V_6 -> V_33 , V_19 , & V_315 ) ;
if ( V_314 == V_318 )
* ( T_1 * ) F_133 ( V_19 ) = V_315 ;
if ( V_266 == V_320 ) {
V_317 = ( T_3 * ) & V_315 ;
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
if ( * V_316 != * V_317 ) {
V_316 = V_313 ;
continue;
}
V_316 ++ ;
V_317 ++ ;
if ( ( V_316 - V_313 ) == V_14 )
V_266 = ( V_19 + V_40 ) - V_14 + 1 ;
}
} else if ( V_314 == V_319 )
return V_266 ;
}
return V_266 ;
}
static void F_134 ( struct V_5 * V_6 , int V_19 )
{
#ifdef F_135
struct V_321 * V_49 = & V_6 -> V_322 . V_323 [ V_19 ] ;
T_1 V_324 , V_3 ;
int V_40 ;
#endif
F_31 ( L_110 ,
V_19 * sizeof( struct V_321 ) ) ;
#ifdef F_135
F_5 ( V_6 -> V_33 , V_110 ,
V_170 ) ;
V_40 = 5 ;
do {
F_58 ( V_171 ) ;
F_1 ( V_6 -> V_33 , V_110 , & V_3 ) ;
if ( V_3 & V_172 )
break;
} while ( V_40 -- );
V_324 = F_132 ( V_6 , ( T_3 * ) V_49 ,
sizeof( struct V_321 ) ,
V_318 ) ;
if ( V_324 < V_325 )
F_31 ( L_111
L_112 ,
V_6 -> V_33 -> V_51 , V_324 ,
sizeof( struct V_321 ) ) ;
else
F_31 ( L_113
L_114 , V_6 -> V_33 -> V_51 ) ;
F_33 ( ( T_3 * ) V_6 -> V_322 . V_323 ,
sizeof( struct V_321 ) * V_326 ) ;
#endif
V_6 -> V_69 = V_327 ;
V_6 -> V_33 -> V_328 . V_329 ++ ;
F_35 ( V_6 ) ;
}
static void F_136 ( struct V_5 * V_6 , int V_19 ,
struct V_330 * V_328 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
struct V_321 * V_49 = & V_6 -> V_322 . V_323 [ V_19 ] ;
struct V_305 * V_61 = & V_6 -> V_331 [ V_19 ] ;
F_137 ( L_115 ) ;
if ( F_138 ( V_49 -> V_332 > F_139 ( V_61 -> V_306 ) ) ) {
F_31 ( L_116
L_117 ,
V_2 -> V_51 ,
V_49 -> V_332 , F_139 ( V_61 -> V_306 ) ) ;
V_2 -> V_328 . V_329 ++ ;
return;
}
if ( F_138 ( ! F_140 ( V_2 ) ) ) {
V_2 -> V_328 . V_329 ++ ;
V_6 -> V_303 . V_333 . V_334 ++ ;
F_141 ( L_118 ) ;
return;
}
if ( F_138 ( V_6 -> V_150 -> V_198 != V_199 &&
! ( V_6 -> V_49 & V_166 ) ) ) {
F_141 ( L_119 ) ;
V_6 -> V_303 . V_333 . V_334 ++ ;
return;
}
F_142 ( V_6 -> V_260 ,
V_61 -> V_309 ,
sizeof( struct V_307 ) , V_310 ) ;
F_143 ( V_61 -> V_306 , V_49 -> V_332 ) ;
#ifdef F_144
F_145 ( V_61 -> V_306 , V_335 ,
F_146 ( T_1 , V_49 -> V_332 ,
V_336 ) ) ;
#endif
if ( ! F_147 ( V_6 -> V_150 , V_61 -> V_306 , V_328 ) ) {
#ifdef F_144
F_141 ( L_120 ,
V_2 -> V_51 ) ;
F_33 ( V_337 , V_335 , V_49 -> V_332 ) ;
#endif
V_2 -> V_328 . V_329 ++ ;
F_148 ( V_61 -> V_306 ) ;
V_61 -> V_306 = NULL ;
}
if ( F_138 ( F_125 ( V_6 , V_61 ) ) ) {
F_27 (KERN_WARNING DRV_NAME L_67
L_121
L_122 , dev->name) ;
F_31 ( L_123 ) ;
}
V_6 -> V_338 . V_323 [ V_19 ] . V_339 = V_61 -> V_309 ;
}
static void F_149 ( struct V_5 * V_6 , int V_19 ,
struct V_330 * V_328 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
struct V_321 * V_49 = & V_6 -> V_322 . V_323 [ V_19 ] ;
struct V_305 * V_61 = & V_6 -> V_331 [ V_19 ] ;
struct V_340 {
struct V_341 V_342 ;
T_5 V_343 ;
} * V_344 ;
F_137 ( L_115 ) ;
if ( F_138 ( V_49 -> V_332 > F_139 ( V_61 -> V_306 ) -
sizeof( struct V_340 ) ) ) {
F_31 ( L_116
L_117 ,
V_2 -> V_51 ,
V_49 -> V_332 ,
F_139 ( V_61 -> V_306 ) ) ;
V_2 -> V_328 . V_329 ++ ;
return;
}
if ( F_138 ( ! F_140 ( V_2 ) ) ) {
V_2 -> V_328 . V_329 ++ ;
V_6 -> V_303 . V_333 . V_334 ++ ;
F_141 ( L_118 ) ;
return;
}
if ( F_138 ( V_6 -> V_187 & V_345 &&
V_49 -> V_62 & V_346 ) ) {
F_137 ( L_124 ) ;
V_2 -> V_328 . V_329 ++ ;
return;
}
F_142 ( V_6 -> V_260 , V_61 -> V_309 ,
sizeof( struct V_307 ) , V_310 ) ;
memmove ( V_61 -> V_306 -> V_37 + sizeof( struct V_340 ) ,
V_61 -> V_306 -> V_37 , V_49 -> V_332 ) ;
V_344 = (struct V_340 * ) V_61 -> V_306 -> V_37 ;
V_344 -> V_342 . V_347 = V_348 ;
V_344 -> V_342 . V_349 = 0 ;
V_344 -> V_342 . V_350 = F_150 ( sizeof( struct V_340 ) ) ;
V_344 -> V_342 . V_351 = F_151 ( 1 << V_352 ) ;
V_344 -> V_343 = V_49 -> V_353 + V_354 ;
F_143 ( V_61 -> V_306 , V_49 -> V_332 + sizeof( struct V_340 ) ) ;
if ( ! F_147 ( V_6 -> V_150 , V_61 -> V_306 , V_328 ) ) {
V_2 -> V_328 . V_329 ++ ;
F_148 ( V_61 -> V_306 ) ;
V_61 -> V_306 = NULL ;
}
if ( F_138 ( F_125 ( V_6 , V_61 ) ) ) {
F_152 (
L_121
L_122 , V_2 -> V_51 ) ;
F_31 ( L_123 ) ;
}
V_6 -> V_338 . V_323 [ V_19 ] . V_339 = V_61 -> V_309 ;
}
static int F_153 ( struct V_5 * V_6 , int V_19 )
{
struct V_321 * V_49 = & V_6 -> V_322 . V_323 [ V_19 ] ;
struct V_307 * V_355 = V_6 -> V_331 [ V_19 ] . V_308 ;
T_2 V_356 = V_49 -> V_357 & V_358 ;
switch ( V_356 ) {
case V_359 :
return ( V_49 -> V_332 != sizeof( V_355 -> V_360 . V_361 ) ) ;
case V_362 :
return ( V_49 -> V_332 != sizeof( V_355 -> V_360 . V_49 ) ) ;
case V_363 :
return ( V_49 -> V_332 < sizeof( V_355 -> V_360 . V_364 ) ) ;
case V_365 :
case V_366 :
#ifdef F_154
return 0 ;
#else
switch ( F_155 ( F_156 ( V_355 -> V_360 . V_367 . V_368 ) ) ) {
case V_369 :
case V_370 :
return 0 ;
case V_371 :
return ( V_49 -> V_332 >
V_372 ) ;
}
#endif
}
return 1 ;
}
static void F_157 ( struct V_5 * V_6 )
{
struct V_373 * V_374 = & V_6 -> V_338 ;
struct V_375 * V_376 = & V_6 -> V_322 ;
struct V_305 * V_61 ;
T_2 V_356 ;
T_1 V_109 , V_377 , V_19 , V_316 ;
struct V_307 * V_355 ;
struct V_330 V_328 = {
. V_378 = V_80 ,
} ;
F_1 ( V_6 -> V_33 , V_379 , & V_109 ) ;
F_1 ( V_6 -> V_33 , V_380 , & V_377 ) ;
if ( V_109 >= V_374 -> V_381 ) {
F_137 ( L_125 ) ;
return;
}
V_19 = ( V_374 -> V_77 + 1 ) % V_374 -> V_381 ;
V_316 = V_19 ;
while ( V_19 != V_109 ) {
V_61 = & V_6 -> V_331 [ V_19 ] ;
F_158 ( V_6 -> V_260 , V_61 -> V_309 ,
sizeof( struct V_307 ) ,
V_310 ) ;
if ( F_138 ( F_153 ( V_6 , V_19 ) ) ) {
F_134 ( V_6 , V_19 ) ;
goto V_382;
}
V_355 = V_61 -> V_308 ;
V_356 = V_376 -> V_323 [ V_19 ] . V_357 & V_358 ;
V_328 . V_353 = V_376 -> V_323 [ V_19 ] . V_353 + V_354 ;
V_328 . V_14 = V_376 -> V_323 [ V_19 ] . V_332 ;
V_328 . V_383 = 0 ;
if ( V_328 . V_353 != 0 )
V_328 . V_383 |= V_384 ;
V_328 . V_243 = V_211 ;
F_137 ( L_126 ,
V_6 -> V_33 -> V_51 , V_385 [ V_356 ] ,
V_328 . V_14 ) ;
switch ( V_356 ) {
case V_359 :
F_123 ( V_6 , & V_355 -> V_360 . V_361 ) ;
break;
case V_362 :
F_121 ( V_6 , V_355 -> V_360 . V_49 ) ;
break;
case V_365 :
case V_366 :
#ifdef F_154
if ( V_6 -> V_150 -> V_198 == V_199 ) {
F_149 ( V_6 , V_19 , & V_328 ) ;
break;
}
#endif
if ( V_328 . V_14 < sizeof( struct V_386 ) )
break;
switch ( F_155 ( F_156 ( V_355 -> V_360 . V_367 . V_368 ) ) ) {
case V_369 :
F_159 ( V_6 -> V_150 ,
& V_355 -> V_360 . V_367 , & V_328 ) ;
break;
case V_370 :
break;
case V_371 :
F_136 ( V_6 , V_19 , & V_328 ) ;
break;
}
break;
}
V_382:
V_374 -> V_323 [ V_19 ] . V_49 . V_81 . V_387 = 0 ;
V_19 = ( V_19 + 1 ) % V_374 -> V_381 ;
}
if ( V_19 != V_316 ) {
V_374 -> V_77 = ( V_19 ? V_19 : V_374 -> V_381 ) - 1 ;
F_5 ( V_6 -> V_33 ,
V_380 , V_374 -> V_77 ) ;
}
}
static int F_160 ( struct V_5 * V_6 )
{
struct V_373 * V_388 = & V_6 -> V_389 ;
struct V_390 * V_391 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
int V_392 ;
int V_393 , V_19 ;
T_1 V_109 , V_377 , V_394 = 0 ;
if ( F_44 ( & V_6 -> V_395 ) )
return 0 ;
V_59 = V_6 -> V_395 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
V_391 = & V_388 -> V_323 [ V_61 -> V_396 ] ;
switch ( V_61 -> type ) {
case V_397 :
V_392 = 1 ;
V_393 = V_388 -> V_398 ;
break;
case V_399 :
V_392 = V_391 -> V_400 ;
V_394 = V_391 -> V_400 - 1 ;
V_393 = V_388 -> V_398 + V_394 ;
V_393 %= V_388 -> V_381 ;
break;
default:
F_27 (KERN_WARNING DRV_NAME L_127 ,
priv->net_dev->name) ;
return 0 ;
}
F_1 ( V_6 -> V_33 , V_401 ,
& V_109 ) ;
F_1 ( V_6 -> V_33 , V_402 ,
& V_377 ) ;
if ( V_377 != V_388 -> V_77 )
F_27 (KERN_WARNING DRV_NAME L_128 ,
priv->net_dev->name) ;
if ( ! ( ( V_109 <= V_377 && ( V_393 < V_109 || V_393 >= V_377 ) ) || ( V_393 < V_109 && V_393 >= V_377 ) ) ) {
F_161 ( L_129 ) ;
return 0 ;
}
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_403 ) ;
#ifdef F_124
{
V_19 = V_388 -> V_398 ;
F_161 ( L_130 , V_19 ,
& V_388 -> V_323 [ V_19 ] ,
( T_1 ) ( V_388 -> V_404 + V_19 * sizeof( struct V_390 ) ) ,
V_388 -> V_323 [ V_19 ] . V_339 , V_388 -> V_323 [ V_19 ] . V_405 ) ;
if ( V_61 -> type == V_399 ) {
V_19 = ( V_19 + 1 ) % V_388 -> V_381 ;
F_161 ( L_130 , V_19 ,
& V_388 -> V_323 [ V_19 ] ,
( T_1 ) ( V_388 -> V_404 + V_19 *
sizeof( struct V_390 ) ) ,
( T_1 ) V_388 -> V_323 [ V_19 ] . V_339 ,
V_388 -> V_323 [ V_19 ] . V_405 ) ;
}
}
#endif
switch ( V_61 -> type ) {
case V_399 :
if ( V_388 -> V_323 [ V_388 -> V_398 ] . V_49 . V_81 . V_406 . V_407 != 0 )
F_27 (KERN_WARNING DRV_NAME L_131
L_132
L_133 ,
priv->net_dev->name, txq->oldest, packet->index) ;
for ( V_19 = 0 ; V_19 < V_394 ; V_19 ++ ) {
V_391 = & V_388 -> V_323 [ ( V_61 -> V_396 + 1 + V_19 ) % V_388 -> V_381 ] ;
F_161 ( L_134 ,
( V_61 -> V_396 + 1 + V_19 ) % V_388 -> V_381 ,
V_391 -> V_339 , V_391 -> V_405 ) ;
F_142 ( V_6 -> V_260 ,
V_391 -> V_339 ,
V_391 -> V_405 , V_408 ) ;
}
F_162 ( V_61 -> V_81 . V_409 . V_410 ) ;
V_61 -> V_81 . V_409 . V_410 = NULL ;
F_48 ( V_59 , & V_6 -> V_411 ) ;
F_49 ( & V_6 -> V_412 ) ;
if ( V_6 -> V_49 & V_166 )
F_163 ( V_6 -> V_33 ) ;
V_6 -> V_33 -> V_413 = V_80 ;
break;
case V_397 :
if ( V_388 -> V_323 [ V_388 -> V_398 ] . V_49 . V_81 . V_406 . V_407 != 1 )
F_27 (KERN_WARNING DRV_NAME L_131
L_135
L_133 ,
priv->net_dev->name, txq->oldest, packet->index) ;
#ifdef F_124
if ( V_61 -> V_81 . V_82 . V_57 -> V_83 <
F_104 ( V_64 ) )
F_161 ( L_136 ,
V_64 [ V_61 -> V_81 . V_82 . V_57 ->
V_83 ] ,
V_61 -> V_81 . V_82 . V_57 ->
V_83 ,
V_61 -> V_81 . V_82 . V_57 -> V_414 ) ;
#endif
F_48 ( V_59 , & V_6 -> V_75 ) ;
F_49 ( & V_6 -> V_90 ) ;
break;
}
V_388 -> V_398 = ( V_393 + 1 ) % V_388 -> V_381 ;
V_388 -> V_415 += V_392 ;
F_164 ( & V_6 -> V_416 , V_388 -> V_415 ) ;
F_161 ( L_137 ,
V_80 - V_61 -> V_79 ) ;
return ( ! F_44 ( & V_6 -> V_395 ) ) ;
}
static inline void F_165 ( struct V_5 * V_6 )
{
int V_19 = 0 ;
while ( F_160 ( V_6 ) && V_19 < 200 )
V_19 ++ ;
if ( V_19 == 200 ) {
F_27 (KERN_WARNING DRV_NAME L_67
L_138 ,
priv->net_dev->name, i) ;
}
}
static void F_50 ( struct V_5 * V_6 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_373 * V_388 = & V_6 -> V_389 ;
struct V_390 * V_391 ;
int V_77 = V_388 -> V_77 ;
while ( ! F_44 ( & V_6 -> V_91 ) ) {
if ( V_388 -> V_415 <= 3 ) {
F_161 ( L_139 ) ;
break;
}
V_59 = V_6 -> V_91 . V_77 ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_92 ) ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
F_161 ( L_140 ,
& V_388 -> V_323 [ V_388 -> V_77 ] ,
( T_1 ) ( V_388 -> V_404 + V_388 -> V_77 *
sizeof( struct V_390 ) ) ) ;
V_61 -> V_396 = V_388 -> V_77 ;
V_391 = & V_388 -> V_323 [ V_388 -> V_77 ] ;
V_391 -> V_339 = V_61 -> V_81 . V_82 . V_417 ;
V_391 -> V_405 = sizeof( struct V_304 ) ;
V_391 -> V_400 = 1 ;
V_391 -> V_49 . V_81 . V_387 =
V_418 |
V_419 ;
V_388 -> V_77 ++ ;
V_388 -> V_77 %= V_388 -> V_381 ;
V_388 -> V_415 -- ;
F_47 ( & V_6 -> V_416 ) ;
F_48 ( V_59 , & V_6 -> V_395 ) ;
F_49 ( & V_6 -> V_403 ) ;
}
if ( V_388 -> V_77 != V_77 ) {
F_166 () ;
F_5 ( V_6 -> V_33 ,
V_402 ,
V_388 -> V_77 ) ;
}
}
static void F_51 ( struct V_5 * V_6 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_373 * V_388 = & V_6 -> V_389 ;
struct V_390 * V_391 ;
int V_77 = V_388 -> V_77 ;
int V_19 = 0 ;
struct V_420 * V_421 ;
struct V_386 * V_422 ;
while ( ! F_44 ( & V_6 -> V_423 ) ) {
V_59 = V_6 -> V_423 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
if ( F_138 ( 1 + V_61 -> V_81 . V_409 . V_410 -> V_424 >
V_425 ) ) {
F_31 ( L_141
L_142 ,
V_6 -> V_33 -> V_51 ) ;
}
if ( V_388 -> V_415 <= 3 + V_61 -> V_81 . V_409 . V_410 -> V_424 ) {
F_161 ( L_139 ) ;
break;
}
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_426 ) ;
V_391 = & V_388 -> V_323 [ V_388 -> V_77 ] ;
V_61 -> V_396 = V_388 -> V_77 ;
V_421 = V_61 -> V_81 . V_409 . V_37 ;
V_422 = (struct V_386 * ) V_61 -> V_81 . V_409 . V_410 ->
V_427 [ 0 ] -> V_37 ;
if ( V_6 -> V_150 -> V_198 == V_428 ) {
memcpy ( V_421 -> V_429 , V_422 -> V_430 , V_230 ) ;
memcpy ( V_421 -> V_431 , V_422 -> V_432 , V_230 ) ;
} else if ( V_6 -> V_150 -> V_198 == V_433 ) {
memcpy ( V_421 -> V_429 , V_422 -> V_430 , V_230 ) ;
memcpy ( V_421 -> V_431 , V_422 -> V_434 , V_230 ) ;
}
V_421 -> V_83 = V_435 ;
V_421 -> V_84 = 0 ;
V_421 -> V_436 = 0 ;
V_421 -> V_437 = V_61 -> V_81 . V_409 . V_410 -> V_437 ;
if ( V_61 -> V_81 . V_409 . V_410 -> V_424 > 1 )
V_421 -> V_438 =
V_61 -> V_81 . V_409 . V_410 -> V_439 -
V_440 ;
else
V_421 -> V_438 = 0 ;
V_391 -> V_339 = V_61 -> V_81 . V_409 . V_441 ;
V_391 -> V_405 = sizeof( struct V_420 ) ;
V_391 -> V_400 = 1 + V_61 -> V_81 . V_409 . V_410 -> V_424 ;
V_391 -> V_49 . V_81 . V_387 =
V_442 |
V_443 ;
V_388 -> V_77 ++ ;
V_388 -> V_77 %= V_388 -> V_381 ;
F_161 ( L_143 ,
V_61 -> V_396 , V_391 -> V_339 , V_391 -> V_405 ) ;
#ifdef F_124
if ( V_61 -> V_81 . V_409 . V_410 -> V_424 > 1 )
F_167 ( L_144 ,
V_61 -> V_81 . V_409 . V_410 -> V_424 ) ;
#endif
for ( V_19 = 0 ; V_19 < V_61 -> V_81 . V_409 . V_410 -> V_424 ; V_19 ++ ) {
V_391 = & V_388 -> V_323 [ V_388 -> V_77 ] ;
if ( V_19 == V_61 -> V_81 . V_409 . V_410 -> V_424 - 1 )
V_391 -> V_49 . V_81 . V_387 =
V_442 |
V_419 ;
else
V_391 -> V_49 . V_81 . V_387 =
V_442 |
V_443 ;
V_391 -> V_405 = V_61 -> V_81 . V_409 . V_410 ->
V_427 [ V_19 ] -> V_14 - V_440 ;
V_391 -> V_339 = F_127 ( V_6 -> V_260 ,
V_61 -> V_81 . V_409 .
V_410 -> V_427 [ V_19 ] ->
V_37 +
V_440 ,
V_391 -> V_405 ,
V_408 ) ;
F_161 ( L_145 ,
V_388 -> V_77 , V_391 -> V_339 ,
V_391 -> V_405 ) ;
F_168 ( V_6 -> V_260 ,
V_391 -> V_339 ,
V_391 -> V_405 ,
V_408 ) ;
V_388 -> V_77 ++ ;
V_388 -> V_77 %= V_388 -> V_381 ;
}
V_388 -> V_415 -= 1 + V_61 -> V_81 . V_409 . V_410 -> V_424 ;
F_164 ( & V_6 -> V_416 , V_388 -> V_415 ) ;
F_48 ( V_59 , & V_6 -> V_395 ) ;
F_49 ( & V_6 -> V_403 ) ;
}
if ( V_388 -> V_77 != V_77 ) {
F_5 ( V_6 -> V_33 ,
V_402 ,
V_388 -> V_77 ) ;
}
}
static void F_169 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
unsigned long V_62 ;
T_1 V_157 , V_315 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
F_68 ( V_6 ) ;
F_1 ( V_2 , V_160 , & V_157 ) ;
F_170 ( L_146 ,
( unsigned long ) V_157 & V_138 ) ;
V_6 -> V_444 ++ ;
V_6 -> V_445 ++ ;
F_170 ( L_147 ,
( unsigned long ) V_157 & V_138 ) ;
if ( V_157 & V_162 ) {
F_27 (KERN_WARNING DRV_NAME
L_148 ) ;
V_6 -> V_446 ++ ;
F_5 ( V_2 , V_160 , V_162 ) ;
F_15 ( V_2 , V_447 , & V_6 -> V_69 ) ;
F_31 ( L_149 ,
V_6 -> V_33 -> V_51 , V_6 -> V_69 ) ;
F_15 ( V_2 , F_171 ( V_6 -> V_69 ) , & V_315 ) ;
F_31 ( L_150 ,
V_6 -> V_33 -> V_51 , V_315 ) ;
F_35 ( V_6 ) ;
}
if ( V_157 & V_163 ) {
F_27 (KERN_ERR DRV_NAME
L_151 ) ;
V_6 -> V_446 ++ ;
F_5 ( V_2 , V_160 , V_163 ) ;
}
if ( V_157 & V_448 ) {
F_170 ( L_152 ) ;
V_6 -> V_449 ++ ;
F_5 ( V_2 , V_160 , V_448 ) ;
F_157 ( V_6 ) ;
F_165 ( V_6 ) ;
}
if ( V_157 & V_450 ) {
F_170 ( L_153 ) ;
V_6 -> V_451 ++ ;
F_5 ( V_2 , V_160 , V_450 ) ;
F_165 ( V_6 ) ;
F_50 ( V_6 ) ;
F_51 ( V_6 ) ;
}
if ( V_157 & V_452 ) {
F_170 ( L_154 ) ;
V_6 -> V_446 ++ ;
F_5 ( V_2 , V_160 , V_452 ) ;
F_165 ( V_6 ) ;
}
if ( V_157 & V_453 ) {
V_6 -> V_446 ++ ;
F_5 ( V_2 , V_160 , V_453 ) ;
}
if ( V_157 & V_161 ) {
F_170 ( L_155 ) ;
V_6 -> V_446 ++ ;
F_1 ( V_2 , V_160 , & V_315 ) ;
if ( V_315 & ( V_162 |
V_163 ) ) {
F_5 ( V_2 , V_160 ,
V_162 |
V_163 ) ;
}
F_5 ( V_2 , V_160 , V_161 ) ;
}
if ( V_157 & V_454 ) {
F_170 ( L_156 ) ;
V_6 -> V_446 ++ ;
F_5 ( V_2 , V_160 , V_454 ) ;
}
if ( V_157 & V_455 ) {
F_170 ( L_157 ) ;
V_6 -> V_446 ++ ;
F_5 ( V_2 , V_160 ,
V_455 ) ;
}
V_6 -> V_444 -- ;
F_67 ( V_6 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
F_170 ( L_45 ) ;
}
static T_6 F_172 ( int V_456 , void * V_37 )
{
struct V_5 * V_6 = V_37 ;
T_1 V_157 , V_158 ;
if ( ! V_37 )
return V_457 ;
F_173 ( & V_6 -> V_68 ) ;
if ( ! ( V_6 -> V_49 & V_136 ) ) {
goto V_458;
}
F_1 ( V_6 -> V_33 , V_137 , & V_158 ) ;
F_1 ( V_6 -> V_33 , V_160 , & V_157 ) ;
if ( V_157 == 0xFFFFFFFF ) {
F_27 (KERN_WARNING DRV_NAME L_158 ) ;
goto V_458;
}
V_157 &= V_138 ;
if ( ! ( V_157 & V_158 ) ) {
goto V_458;
}
F_68 ( V_6 ) ;
F_174 ( & V_6 -> V_459 ) ;
F_175 ( & V_6 -> V_68 ) ;
return V_460 ;
V_458:
F_175 ( & V_6 -> V_68 ) ;
return V_457 ;
}
static T_7 F_176 ( struct V_461 * V_410 ,
struct V_1 * V_2 , int V_462 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
unsigned long V_62 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( ! ( V_6 -> V_49 & V_166 ) ) {
F_31 ( L_159 ) ;
V_6 -> V_33 -> V_328 . V_463 ++ ;
F_38 ( V_2 ) ;
goto V_71;
}
if ( F_44 ( & V_6 -> V_411 ) )
goto V_71;
V_59 = V_6 -> V_411 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
V_61 -> V_81 . V_409 . V_410 = V_410 ;
F_161 ( L_160 , V_410 -> V_427 [ 0 ] -> V_14 ) ;
F_33 ( V_464 , V_410 -> V_427 [ 0 ] -> V_37 , V_410 -> V_427 [ 0 ] -> V_14 ) ;
V_61 -> V_79 = V_80 ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_412 ) ;
F_48 ( V_59 , & V_6 -> V_423 ) ;
F_49 ( & V_6 -> V_426 ) ;
F_51 ( V_6 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
return V_465 ;
V_71:
F_38 ( V_2 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
return V_466 ;
}
static int F_177 ( struct V_5 * V_6 )
{
int V_19 , V_40 , V_63 = - V_31 ;
void * V_467 ;
T_8 V_468 ;
V_6 -> V_469 =
F_131 ( V_470 * sizeof( struct V_60 ) ,
V_239 ) ;
if ( ! V_6 -> V_469 )
return - V_240 ;
for ( V_19 = 0 ; V_19 < V_470 ; V_19 ++ ) {
V_467 = F_178 ( V_6 -> V_260 ,
sizeof( struct V_304 ) , & V_468 ) ;
if ( ! V_467 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_161
L_162 , priv->net_dev->name) ;
V_63 = - V_240 ;
break;
}
memset ( V_467 , 0 , sizeof( struct V_304 ) ) ;
V_6 -> V_469 [ V_19 ] . type = V_397 ;
V_6 -> V_469 [ V_19 ] . V_81 . V_82 . V_57 =
(struct V_304 * ) V_467 ;
V_6 -> V_469 [ V_19 ] . V_81 . V_82 . V_417 = V_468 ;
}
if ( V_19 == V_470 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_19 ; V_40 ++ ) {
F_179 ( V_6 -> V_260 ,
sizeof( struct V_304 ) ,
V_6 -> V_469 [ V_40 ] . V_81 . V_82 . V_57 ,
V_6 -> V_469 [ V_40 ] . V_81 . V_82 .
V_417 ) ;
}
F_129 ( V_6 -> V_469 ) ;
V_6 -> V_469 = NULL ;
return V_63 ;
}
static int F_180 ( struct V_5 * V_6 )
{
int V_19 ;
F_181 ( & V_6 -> V_75 ) ;
F_181 ( & V_6 -> V_91 ) ;
for ( V_19 = 0 ; V_19 < V_470 ; V_19 ++ )
F_48 ( & V_6 -> V_469 [ V_19 ] . V_78 , & V_6 -> V_75 ) ;
F_164 ( & V_6 -> V_90 , V_19 ) ;
return 0 ;
}
static void F_182 ( struct V_5 * V_6 )
{
int V_19 ;
if ( ! V_6 -> V_469 )
return;
for ( V_19 = 0 ; V_19 < V_470 ; V_19 ++ ) {
F_179 ( V_6 -> V_260 ,
sizeof( struct V_304 ) ,
V_6 -> V_469 [ V_19 ] . V_81 . V_82 . V_57 ,
V_6 -> V_469 [ V_19 ] . V_81 . V_82 .
V_417 ) ;
}
F_129 ( V_6 -> V_469 ) ;
V_6 -> V_469 = NULL ;
}
static T_9 F_183 ( struct V_471 * V_317 , struct V_472 * V_473 ,
char * V_15 )
{
struct V_260 * V_260 = F_108 ( V_317 , struct V_260 , V_2 ) ;
char * V_39 = V_15 ;
int V_19 , V_40 ;
T_1 V_4 ;
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ ) {
V_39 += sprintf ( V_39 , L_163 , V_19 * 16 ) ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 += 4 ) {
F_184 ( V_260 , V_19 * 16 + V_40 , & V_4 ) ;
V_39 += sprintf ( V_39 , L_164 , V_4 ) ;
}
V_39 += sprintf ( V_39 , L_165 ) ;
}
return V_39 - V_15 ;
}
static T_9 F_185 ( struct V_471 * V_317 , struct V_472 * V_473 ,
char * V_15 )
{
struct V_5 * V_468 = F_186 ( V_317 ) ;
return sprintf ( V_15 , L_166 , ( int ) V_468 -> V_187 ) ;
}
static T_9 F_187 ( struct V_471 * V_317 , struct V_472 * V_473 ,
char * V_15 )
{
struct V_5 * V_468 = F_186 ( V_317 ) ;
return sprintf ( V_15 , L_166 , ( int ) V_468 -> V_49 ) ;
}
static T_9 F_188 ( struct V_471 * V_317 , struct V_472 * V_473 ,
char * V_15 )
{
struct V_5 * V_468 = F_186 ( V_317 ) ;
return sprintf ( V_15 , L_166 , ( int ) V_468 -> V_474 ) ;
}
static T_9 F_189 ( struct V_471 * V_317 , struct V_472 * V_473 ,
char * V_15 )
{
int V_19 ;
struct V_5 * V_6 = F_186 ( V_317 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
char * V_39 = V_15 ;
T_1 V_4 = 0 ;
V_39 += sprintf ( V_39 , L_167 , L_168 ) ;
for ( V_19 = 0 ; V_19 < F_104 ( V_475 ) ; V_19 ++ ) {
F_1 ( V_2 , V_475 [ V_19 ] . V_8 , & V_4 ) ;
V_39 += sprintf ( V_39 , L_169 ,
V_475 [ V_19 ] . V_51 , V_475 [ V_19 ] . V_8 , V_4 ) ;
}
return V_39 - V_15 ;
}
static T_9 F_190 ( struct V_471 * V_317 , struct V_472 * V_473 ,
char * V_15 )
{
struct V_5 * V_6 = F_186 ( V_317 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
char * V_39 = V_15 ;
int V_19 ;
V_39 += sprintf ( V_39 , L_167 , L_170 ) ;
for ( V_19 = 0 ; V_19 < F_104 ( V_476 ) ; V_19 ++ ) {
T_3 V_477 ;
T_2 V_478 ;
T_1 V_479 ;
switch ( V_476 [ V_19 ] . V_480 ) {
case 1 :
F_19 ( V_2 , V_476 [ V_19 ] . V_8 , & V_477 ) ;
V_39 += sprintf ( V_39 , L_171 ,
V_476 [ V_19 ] . V_51 , V_476 [ V_19 ] . V_8 ,
V_477 ) ;
break;
case 2 :
F_17 ( V_2 , V_476 [ V_19 ] . V_8 , & V_478 ) ;
V_39 += sprintf ( V_39 , L_172 ,
V_476 [ V_19 ] . V_51 , V_476 [ V_19 ] . V_8 ,
V_478 ) ;
break;
case 4 :
F_15 ( V_2 , V_476 [ V_19 ] . V_8 , & V_479 ) ;
V_39 += sprintf ( V_39 , L_169 ,
V_476 [ V_19 ] . V_51 , V_476 [ V_19 ] . V_8 ,
V_479 ) ;
break;
}
}
return V_39 - V_15 ;
}
static T_9 F_191 ( struct V_471 * V_317 , struct V_472 * V_473 ,
char * V_15 )
{
struct V_5 * V_6 = F_186 ( V_317 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
static unsigned long V_481 = 0 ;
int V_14 = 0 ;
T_1 V_482 [ 4 ] ;
int V_19 ;
char line [ 81 ] ;
if ( V_481 >= 0x30000 )
V_481 = 0 ;
while ( V_14 < V_483 - 128 && V_481 < 0x30000 ) {
if ( V_6 -> V_311 [ 0 ] )
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ )
V_482 [ V_19 ] =
* ( T_1 * ) F_133 ( V_481 + V_19 * 4 ) ;
else
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ )
F_15 ( V_2 , V_481 + V_19 * 4 , & V_482 [ V_19 ] ) ;
if ( V_6 -> V_484 )
V_14 += sprintf ( V_15 + V_14 ,
L_173
L_173
L_173
L_173 ,
( ( T_3 * ) V_482 ) [ 0x0 ] ,
( ( T_3 * ) V_482 ) [ 0x1 ] ,
( ( T_3 * ) V_482 ) [ 0x2 ] ,
( ( T_3 * ) V_482 ) [ 0x3 ] ,
( ( T_3 * ) V_482 ) [ 0x4 ] ,
( ( T_3 * ) V_482 ) [ 0x5 ] ,
( ( T_3 * ) V_482 ) [ 0x6 ] ,
( ( T_3 * ) V_482 ) [ 0x7 ] ,
( ( T_3 * ) V_482 ) [ 0x8 ] ,
( ( T_3 * ) V_482 ) [ 0x9 ] ,
( ( T_3 * ) V_482 ) [ 0xa ] ,
( ( T_3 * ) V_482 ) [ 0xb ] ,
( ( T_3 * ) V_482 ) [ 0xc ] ,
( ( T_3 * ) V_482 ) [ 0xd ] ,
( ( T_3 * ) V_482 ) [ 0xe ] ,
( ( T_3 * ) V_482 ) [ 0xf ] ) ;
else
V_14 += sprintf ( V_15 + V_14 , L_19 ,
F_32 ( line , sizeof( line ) ,
( T_3 * ) V_482 , 16 , V_481 ) ) ;
V_481 += 16 ;
}
return V_14 ;
}
static T_9 F_192 ( struct V_471 * V_317 , struct V_472 * V_473 ,
const char * V_15 , T_4 V_36 )
{
struct V_5 * V_6 = F_186 ( V_317 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
const char * V_468 = V_15 ;
( void ) V_2 ;
if ( V_36 < 1 )
return V_36 ;
if ( V_468 [ 0 ] == '1' ||
( V_36 >= 2 && tolower ( V_468 [ 0 ] ) == 'o' && tolower ( V_468 [ 1 ] ) == 'n' ) ) {
F_31 ( L_174 ,
V_2 -> V_51 ) ;
V_6 -> V_484 = 1 ;
} else if ( V_468 [ 0 ] == '0' || ( V_36 >= 2 && tolower ( V_468 [ 0 ] ) == 'o' &&
tolower ( V_468 [ 1 ] ) == 'f' ) ) {
F_31 ( L_175 ,
V_2 -> V_51 ) ;
V_6 -> V_484 = 0 ;
} else if ( tolower ( V_468 [ 0 ] ) == 'r' ) {
F_31 ( L_176 , V_2 -> V_51 ) ;
F_128 ( V_6 ) ;
} else
F_31 ( L_177
L_178 , V_2 -> V_51 ) ;
return V_36 ;
}
static T_9 F_193 ( struct V_471 * V_317 , struct V_472 * V_473 ,
char * V_15 )
{
struct V_5 * V_6 = F_186 ( V_317 ) ;
T_1 V_4 = 0 ;
int V_14 = 0 ;
T_1 V_485 ;
static int V_481 = 0 ;
if ( V_6 -> V_49 & V_486 )
return 0 ;
if ( V_481 >= F_104 ( V_487 ) )
V_481 = 0 ;
while ( V_14 < V_483 - 128 && V_481 < F_104 ( V_487 ) ) {
V_485 = sizeof( T_1 ) ;
if ( F_26 ( V_6 , V_487 [ V_481 ] . V_396 , & V_4 ,
& V_485 ) )
V_14 += sprintf ( V_15 + V_14 , L_179 ,
V_487 [ V_481 ] . V_396 ,
V_487 [ V_481 ] . V_488 ) ;
else
V_14 += sprintf ( V_15 + V_14 , L_180 ,
V_487 [ V_481 ] . V_396 , V_4 ,
V_487 [ V_481 ] . V_488 ) ;
V_481 ++ ;
}
return V_14 ;
}
static T_9 F_194 ( struct V_471 * V_317 , struct V_472 * V_473 ,
char * V_15 )
{
struct V_5 * V_6 = F_186 ( V_317 ) ;
char * V_39 = V_15 ;
V_39 += sprintf ( V_39 , L_181 ,
V_6 -> V_445 , V_6 -> V_451 ,
V_6 -> V_449 , V_6 -> V_446 ) ;
V_39 += sprintf ( V_39 , L_182 , V_6 -> V_263 ) ;
V_39 += sprintf ( V_39 , L_183 , V_6 -> V_489 ) ;
#ifdef F_124
V_39 += sprintf ( V_39 , L_184 ,
V_6 -> V_311 [ 0 ] ? L_185 : L_186 ) ;
#endif
return V_39 - V_15 ;
}
static int F_195 ( struct V_5 * V_6 , T_1 V_314 )
{
int V_63 ;
if ( V_314 == V_6 -> V_150 -> V_198 )
return 0 ;
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME L_187 ,
priv->net_dev->name, err) ;
return V_63 ;
}
switch ( V_314 ) {
case V_428 :
V_6 -> V_33 -> type = V_221 ;
break;
case V_433 :
V_6 -> V_33 -> type = V_221 ;
break;
#ifdef F_154
case V_199 :
V_6 -> V_490 = V_6 -> V_150 -> V_198 ;
V_6 -> V_33 -> type = V_491 ;
break;
#endif
}
V_6 -> V_150 -> V_198 = V_314 ;
#ifdef F_61
V_120 . V_121 = 0 ;
#endif
F_27 ( V_214 L_188 , V_6 -> V_33 -> V_51 ) ;
V_6 -> V_47 = 0 ;
F_35 ( V_6 ) ;
return 0 ;
}
static T_9 F_196 ( struct V_471 * V_317 , struct V_472 * V_473 ,
char * V_15 )
{
struct V_5 * V_6 = F_186 ( V_317 ) ;
int V_14 = 0 ;
#define F_197 ( T_10 , T_11 ) len += sprintf(buf + len, # x ": %" y "\n", priv-> x)
if ( V_6 -> V_49 & V_166 )
V_14 += sprintf ( V_15 + V_14 , L_189 ,
F_36 () - V_6 -> V_284 ) ;
else
V_14 += sprintf ( V_15 + V_14 , L_190 ) ;
F_197 ( V_150 -> V_492 . V_493 [ V_6 -> V_150 -> V_492 . V_494 ] , L_191 ) ;
F_197 ( V_49 , L_192 ) ;
F_197 ( V_187 , L_192 ) ;
F_197 ( V_474 , L_192 ) ;
V_14 +=
sprintf ( V_15 + V_14 , L_193 ,
( unsigned long ) V_6 -> V_495 ) ;
F_197 ( V_69 , L_194 ) ;
F_197 ( V_181 , L_194 ) ;
F_197 ( V_215 , L_194 ) ;
F_197 ( V_76 , L_194 ) ;
F_197 ( V_426 . V_147 , L_194 ) ;
F_197 ( V_426 . V_496 , L_194 ) ;
F_197 ( V_412 . V_147 , L_194 ) ;
F_197 ( V_412 . V_497 , L_194 ) ;
F_197 ( V_90 . V_147 , L_194 ) ;
F_197 ( V_90 . V_497 , L_194 ) ;
F_197 ( V_92 . V_147 , L_194 ) ;
F_197 ( V_92 . V_496 , L_194 ) ;
F_197 ( V_403 . V_147 , L_194 ) ;
F_197 ( V_403 . V_496 , L_194 ) ;
F_197 ( V_416 . V_147 , L_194 ) ;
F_197 ( V_416 . V_497 , L_194 ) ;
F_197 ( V_150 -> V_298 , L_194 ) ;
F_197 ( V_47 , L_194 ) ;
return V_14 ;
}
static T_9 F_198 ( struct V_471 * V_317 , struct V_472 * V_473 ,
char * V_15 )
{
struct V_5 * V_6 = F_186 ( V_317 ) ;
char V_268 [ V_269 + 1 ] ;
T_3 V_273 [ V_230 ] ;
T_1 V_271 = 0 ;
char * V_39 = V_15 ;
unsigned int V_286 ;
int V_266 ;
if ( V_6 -> V_49 & V_486 )
return 0 ;
memset ( V_268 , 0 , sizeof( V_268 ) ) ;
memset ( V_273 , 0 , sizeof( V_273 ) ) ;
V_286 = V_269 ;
V_266 = F_26 ( V_6 , V_275 , V_268 , & V_286 ) ;
if ( V_266 )
F_31 ( L_46 ,
__LINE__ ) ;
V_286 = sizeof( V_273 ) ;
V_266 = F_26 ( V_6 , V_278 ,
V_273 , & V_286 ) ;
if ( V_266 )
F_31 ( L_46 ,
__LINE__ ) ;
V_286 = sizeof( T_1 ) ;
V_266 = F_26 ( V_6 , V_277 , & V_271 , & V_286 ) ;
if ( V_266 )
F_31 ( L_46 ,
__LINE__ ) ;
V_39 += sprintf ( V_39 , L_195 , V_268 ) ;
V_39 += sprintf ( V_39 , L_196 , V_273 ) ;
V_39 += sprintf ( V_39 , L_197 , V_271 ) ;
return V_39 - V_15 ;
}
static T_9 F_199 ( struct V_498 * V_317 , char * V_15 )
{
return sprintf ( V_15 , L_198 , V_44 ) ;
}
static T_9 F_200 ( struct V_498 * V_317 ,
const char * V_15 , T_4 V_36 )
{
T_1 V_4 ;
int V_266 ;
V_266 = F_201 ( V_15 , 0 , & V_4 ) ;
if ( V_266 )
F_31 ( L_199 , V_15 ) ;
else
V_44 = V_4 ;
return F_202 ( V_15 , V_36 ) ;
}
static T_9 F_203 ( struct V_471 * V_317 ,
struct V_472 * V_473 , char * V_15 )
{
struct V_5 * V_6 = F_186 ( V_317 ) ;
char * V_39 = V_15 ;
int V_19 ;
if ( V_6 -> V_69 )
V_39 += sprintf ( V_39 , L_198 , V_6 -> V_69 ) ;
else
V_39 += sprintf ( V_39 , L_200 ) ;
for ( V_19 = 1 ; V_19 <= V_169 ; V_19 ++ ) {
if ( ! V_6 -> V_167 [ ( V_6 -> V_168 - V_19 ) %
V_169 ] )
continue;
V_39 += sprintf ( V_39 , L_201 , V_19 ,
V_6 -> V_167 [ ( V_6 -> V_168 - V_19 ) %
V_169 ] ) ;
}
return V_39 - V_15 ;
}
static T_9 F_204 ( struct V_471 * V_317 ,
struct V_472 * V_473 , const char * V_15 ,
T_4 V_36 )
{
struct V_5 * V_6 = F_186 ( V_317 ) ;
F_35 ( V_6 ) ;
return V_36 ;
}
static T_9 F_205 ( struct V_471 * V_317 , struct V_472 * V_473 ,
char * V_15 )
{
struct V_5 * V_6 = F_186 ( V_317 ) ;
return sprintf ( V_15 , L_202 , V_6 -> V_150 -> V_499 ) ;
}
static T_9 F_206 ( struct V_471 * V_317 , struct V_472 * V_473 ,
const char * V_15 , T_4 V_36 )
{
struct V_5 * V_6 = F_186 ( V_317 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
unsigned long V_4 ;
int V_266 ;
( void ) V_2 ;
F_31 ( L_42 ) ;
V_266 = F_207 ( V_15 , 0 , & V_4 ) ;
if ( V_266 ) {
F_31 ( L_203 , V_2 -> V_51 ) ;
} else {
V_6 -> V_150 -> V_499 = V_4 ;
F_31 ( L_204 , V_6 -> V_150 -> V_499 ) ;
}
F_31 ( L_45 ) ;
return F_202 ( V_15 , V_36 ) ;
}
static T_9 F_208 ( struct V_471 * V_317 , struct V_472 * V_473 ,
char * V_15 )
{
struct V_5 * V_6 = F_186 ( V_317 ) ;
int V_4 = ( ( V_6 -> V_49 & V_206 ) ? 0x1 : 0x0 ) |
( F_71 ( V_6 ) ? 0x2 : 0x0 ) ;
return sprintf ( V_15 , L_205 , V_4 ) ;
}
static int F_209 ( struct V_5 * V_6 , int V_500 )
{
if ( ( V_500 ? 1 : 0 ) ==
( V_6 -> V_49 & V_206 ? 1 : 0 ) )
return 0 ;
F_210 ( L_206 ,
V_500 ? L_207 : L_208 ) ;
F_84 ( & V_6 -> V_265 ) ;
if ( V_500 ) {
V_6 -> V_49 |= V_206 ;
F_99 ( V_6 ) ;
} else {
V_6 -> V_49 &= ~ V_206 ;
if ( F_71 ( V_6 ) ) {
F_210 ( L_209
L_210 ) ;
V_6 -> V_215 = 0 ;
F_117 ( V_295 , & V_6 -> V_216 ,
F_97 ( V_53 ) ) ;
} else
F_35 ( V_6 ) ;
}
F_85 ( & V_6 -> V_265 ) ;
return 1 ;
}
static T_9 F_211 ( struct V_471 * V_317 , struct V_472 * V_473 ,
const char * V_15 , T_4 V_36 )
{
struct V_5 * V_6 = F_186 ( V_317 ) ;
F_209 ( V_6 , V_15 [ 0 ] == '1' ) ;
return V_36 ;
}
static int F_212 ( struct V_5 * V_6 , int V_381 )
{
struct V_375 * V_501 = & V_6 -> V_322 ;
F_31 ( L_42 ) ;
V_501 -> V_480 = V_381 * sizeof( struct V_321 ) ;
V_501 -> V_323 =
(struct V_321 * ) F_178 ( V_6 -> V_260 ,
V_501 -> V_480 , & V_501 -> V_404 ) ;
if ( ! V_501 -> V_323 ) {
F_152 ( L_211 ) ;
return - V_240 ;
}
memset ( V_501 -> V_323 , 0 , V_501 -> V_480 ) ;
F_31 ( L_45 ) ;
return 0 ;
}
static void F_213 ( struct V_5 * V_6 )
{
F_31 ( L_42 ) ;
if ( V_6 -> V_322 . V_323 ) {
F_179 ( V_6 -> V_260 , V_6 -> V_322 . V_480 ,
V_6 -> V_322 . V_323 ,
V_6 -> V_322 . V_404 ) ;
V_6 -> V_322 . V_323 = NULL ;
}
F_31 ( L_45 ) ;
}
static int F_214 ( struct V_5 * V_6 ,
struct V_373 * V_501 , int V_381 )
{
F_31 ( L_42 ) ;
memset ( V_501 , 0 , sizeof( struct V_373 ) ) ;
V_501 -> V_381 = V_381 ;
V_501 -> V_480 = V_381 * sizeof( struct V_390 ) ;
V_501 -> V_323 = F_178 ( V_6 -> V_260 , V_501 -> V_480 , & V_501 -> V_404 ) ;
if ( ! V_501 -> V_323 ) {
F_31
( L_212 ) ;
return - V_240 ;
}
memset ( V_501 -> V_323 , 0 , V_501 -> V_480 ) ;
F_31 ( L_45 ) ;
return 0 ;
}
static void F_215 ( struct V_5 * V_6 , struct V_373 * V_501 )
{
F_31 ( L_42 ) ;
if ( ! V_501 )
return;
if ( V_501 -> V_323 ) {
F_179 ( V_6 -> V_260 , V_501 -> V_480 , V_501 -> V_323 , V_501 -> V_404 ) ;
V_501 -> V_323 = NULL ;
}
F_31 ( L_45 ) ;
}
static void F_216 ( struct V_5 * V_6 ,
struct V_373 * V_501 , T_1 V_502 , T_1 V_480 ,
T_1 V_109 , T_1 V_377 )
{
F_31 ( L_42 ) ;
F_31 ( L_213 , V_501 -> V_323 ,
( T_1 ) V_501 -> V_404 ) ;
F_5 ( V_6 -> V_33 , V_502 , V_501 -> V_404 ) ;
F_5 ( V_6 -> V_33 , V_480 , V_501 -> V_381 ) ;
F_5 ( V_6 -> V_33 , V_109 , V_501 -> V_398 ) ;
F_5 ( V_6 -> V_33 , V_377 , V_501 -> V_77 ) ;
F_31 ( L_45 ) ;
}
static void F_217 ( struct V_5 * V_6 )
{
V_6 -> V_215 = 1 ;
V_6 -> V_181 = 1 ;
F_218 ( & V_6 -> V_52 ) ;
F_218 ( & V_6 -> V_294 ) ;
F_218 ( & V_6 -> V_285 ) ;
F_218 ( & V_6 -> V_182 ) ;
F_218 ( & V_6 -> V_216 ) ;
F_218 ( & V_6 -> V_296 ) ;
}
static int F_219 ( struct V_5 * V_6 )
{
int V_19 , V_40 , V_63 = - V_31 ;
void * V_467 ;
T_8 V_468 ;
F_31 ( L_42 ) ;
V_63 = F_214 ( V_6 , & V_6 -> V_389 , V_503 ) ;
if ( V_63 ) {
F_62 ( L_214 ,
V_6 -> V_33 -> V_51 ) ;
return V_63 ;
}
V_6 -> V_504 = F_220 ( V_505 ,
sizeof( struct V_60 ) ,
V_312 ) ;
if ( ! V_6 -> V_504 ) {
F_215 ( V_6 , & V_6 -> V_389 ) ;
return - V_240 ;
}
for ( V_19 = 0 ; V_19 < V_505 ; V_19 ++ ) {
V_467 = F_178 ( V_6 -> V_260 ,
sizeof( struct V_420 ) ,
& V_468 ) ;
if ( ! V_467 ) {
F_27 (KERN_ERR DRV_NAME
L_215 L_162 ,
priv->net_dev->name) ;
V_63 = - V_240 ;
break;
}
V_6 -> V_504 [ V_19 ] . type = V_399 ;
V_6 -> V_504 [ V_19 ] . V_81 . V_409 . V_37 =
(struct V_420 * ) V_467 ;
V_6 -> V_504 [ V_19 ] . V_81 . V_409 . V_441 = V_468 ;
V_6 -> V_504 [ V_19 ] . V_81 . V_409 . V_410 = NULL ;
}
if ( V_19 == V_505 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_19 ; V_40 ++ ) {
F_179 ( V_6 -> V_260 ,
sizeof( struct V_420 ) ,
V_6 -> V_504 [ V_40 ] . V_81 . V_409 . V_37 ,
V_6 -> V_504 [ V_40 ] . V_81 . V_409 .
V_441 ) ;
}
F_129 ( V_6 -> V_504 ) ;
V_6 -> V_504 = NULL ;
return V_63 ;
}
static void F_221 ( struct V_5 * V_6 )
{
int V_19 ;
F_31 ( L_42 ) ;
F_181 ( & V_6 -> V_395 ) ;
F_222 ( & V_6 -> V_403 ) ;
F_181 ( & V_6 -> V_423 ) ;
F_181 ( & V_6 -> V_411 ) ;
F_222 ( & V_6 -> V_426 ) ;
F_222 ( & V_6 -> V_412 ) ;
for ( V_19 = 0 ; V_19 < V_505 ; V_19 ++ ) {
if ( V_6 -> V_504 [ V_19 ] . V_81 . V_409 . V_410 ) {
F_162 ( V_6 -> V_504 [ V_19 ] . V_81 . V_409 .
V_410 ) ;
V_6 -> V_504 [ V_19 ] . V_81 . V_409 . V_410 = NULL ;
}
F_48 ( & V_6 -> V_504 [ V_19 ] . V_78 , & V_6 -> V_411 ) ;
}
F_164 ( & V_6 -> V_412 , V_19 ) ;
V_6 -> V_389 . V_398 = 0 ;
V_6 -> V_389 . V_415 = V_6 -> V_389 . V_381 ;
V_6 -> V_389 . V_77 = 0 ;
F_222 ( & V_6 -> V_416 ) ;
F_164 ( & V_6 -> V_416 , V_6 -> V_389 . V_415 ) ;
F_216 ( V_6 , & V_6 -> V_389 ,
V_506 ,
V_507 ,
V_401 ,
V_402 ) ;
F_31 ( L_45 ) ;
}
static void F_223 ( struct V_5 * V_6 )
{
int V_19 ;
F_31 ( L_42 ) ;
F_215 ( V_6 , & V_6 -> V_389 ) ;
if ( ! V_6 -> V_504 )
return;
for ( V_19 = 0 ; V_19 < V_505 ; V_19 ++ ) {
if ( V_6 -> V_504 [ V_19 ] . V_81 . V_409 . V_410 ) {
F_162 ( V_6 -> V_504 [ V_19 ] . V_81 . V_409 .
V_410 ) ;
V_6 -> V_504 [ V_19 ] . V_81 . V_409 . V_410 = NULL ;
}
if ( V_6 -> V_504 [ V_19 ] . V_81 . V_409 . V_37 )
F_179 ( V_6 -> V_260 ,
sizeof( struct V_420 ) ,
V_6 -> V_504 [ V_19 ] . V_81 . V_409 .
V_37 ,
V_6 -> V_504 [ V_19 ] . V_81 . V_409 .
V_441 ) ;
}
F_129 ( V_6 -> V_504 ) ;
V_6 -> V_504 = NULL ;
F_31 ( L_45 ) ;
}
static int F_224 ( struct V_5 * V_6 )
{
int V_19 , V_40 , V_63 = - V_31 ;
F_31 ( L_42 ) ;
V_63 = F_214 ( V_6 , & V_6 -> V_338 , V_326 ) ;
if ( V_63 ) {
F_31 ( L_216 ) ;
return V_63 ;
}
V_63 = F_212 ( V_6 , V_326 ) ;
if ( V_63 ) {
F_31 ( L_217 ) ;
F_215 ( V_6 , & V_6 -> V_338 ) ;
return V_63 ;
}
V_6 -> V_331 = F_131 ( V_326 *
sizeof( struct V_305 ) ,
V_239 ) ;
if ( ! V_6 -> V_331 ) {
F_31 ( L_218 ) ;
F_215 ( V_6 , & V_6 -> V_338 ) ;
F_213 ( V_6 ) ;
return - V_240 ;
}
for ( V_19 = 0 ; V_19 < V_326 ; V_19 ++ ) {
struct V_305 * V_61 = & V_6 -> V_331 [ V_19 ] ;
V_63 = F_125 ( V_6 , V_61 ) ;
if ( F_138 ( V_63 ) ) {
V_63 = - V_240 ;
break;
}
V_6 -> V_338 . V_323 [ V_19 ] . V_339 = V_61 -> V_309 ;
V_6 -> V_338 . V_323 [ V_19 ] . V_405 = V_336 ;
V_6 -> V_322 . V_323 [ V_19 ] . V_357 = 0 ;
}
if ( V_19 == V_326 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_19 ; V_40 ++ ) {
F_142 ( V_6 -> V_260 , V_6 -> V_331 [ V_40 ] . V_309 ,
sizeof( struct V_305 ) ,
V_310 ) ;
F_225 ( V_6 -> V_331 [ V_40 ] . V_306 ) ;
}
F_129 ( V_6 -> V_331 ) ;
V_6 -> V_331 = NULL ;
F_215 ( V_6 , & V_6 -> V_338 ) ;
F_213 ( V_6 ) ;
return V_63 ;
}
static void F_226 ( struct V_5 * V_6 )
{
F_31 ( L_42 ) ;
V_6 -> V_338 . V_398 = 0 ;
V_6 -> V_338 . V_415 = V_6 -> V_338 . V_381 - 1 ;
V_6 -> V_338 . V_77 = V_6 -> V_338 . V_381 - 1 ;
F_222 ( & V_6 -> V_508 ) ;
F_164 ( & V_6 -> V_508 , V_6 -> V_338 . V_415 ) ;
F_216 ( V_6 , & V_6 -> V_338 ,
V_509 ,
V_510 ,
V_379 ,
V_380 ) ;
F_5 ( V_6 -> V_33 , V_511 ,
V_6 -> V_322 . V_404 ) ;
F_31 ( L_45 ) ;
}
static void F_227 ( struct V_5 * V_6 )
{
int V_19 ;
F_31 ( L_42 ) ;
F_215 ( V_6 , & V_6 -> V_338 ) ;
F_213 ( V_6 ) ;
if ( ! V_6 -> V_331 )
return;
for ( V_19 = 0 ; V_19 < V_326 ; V_19 ++ ) {
if ( V_6 -> V_331 [ V_19 ] . V_308 ) {
F_142 ( V_6 -> V_260 ,
V_6 -> V_331 [ V_19 ] . V_309 ,
sizeof( struct V_307 ) ,
V_310 ) ;
F_225 ( V_6 -> V_331 [ V_19 ] . V_306 ) ;
}
}
F_129 ( V_6 -> V_331 ) ;
V_6 -> V_331 = NULL ;
F_31 ( L_45 ) ;
}
static int F_228 ( struct V_5 * V_6 )
{
T_1 V_286 = V_230 ;
T_3 V_8 [ V_230 ] ;
int V_63 ;
V_63 = F_26 ( V_6 , V_512 , V_8 , & V_286 ) ;
if ( V_63 ) {
F_31 ( L_219 ) ;
return - V_70 ;
}
memcpy ( V_6 -> V_33 -> V_513 , V_8 , V_230 ) ;
F_31 ( L_220 , V_6 -> V_33 -> V_513 ) ;
return 0 ;
}
static int F_229 ( struct V_5 * V_6 , int V_287 )
{
struct V_56 V_57 = {
. V_56 = V_514 ,
. V_88 = 0 ,
. V_65 = V_230
} ;
int V_63 ;
F_42 ( L_221 ) ;
F_31 ( L_42 ) ;
if ( V_6 -> V_187 & V_515 ) {
memcpy ( V_57 . V_67 , V_6 -> V_229 , V_230 ) ;
memcpy ( V_6 -> V_33 -> V_513 , V_6 -> V_229 , V_230 ) ;
} else
memcpy ( V_57 . V_67 , V_6 -> V_33 -> V_513 ,
V_230 ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
F_31 ( L_45 ) ;
return V_63 ;
}
static int F_230 ( struct V_5 * V_6 , T_1 V_516 ,
int V_287 )
{
struct V_56 V_57 = {
. V_56 = V_517 ,
. V_88 = 0 ,
. V_65 = sizeof( T_1 )
} ;
int V_63 ;
switch ( V_516 ) {
case V_428 :
V_57 . V_67 [ 0 ] = V_518 ;
break;
case V_433 :
V_57 . V_67 [ 0 ] = V_519 ;
break;
}
F_42 ( L_222 ,
V_516 == V_519 ? L_223 : L_224 ) ;
if ( ! V_287 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_187 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_287 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_231 ( struct V_5 * V_6 , T_1 V_245 ,
int V_287 )
{
struct V_56 V_57 = {
. V_56 = V_520 ,
. V_88 = 0 ,
. V_65 = sizeof( T_1 )
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_245 ;
F_42 ( L_225 , V_245 ) ;
if ( V_6 -> V_150 -> V_198 == V_428 )
return 0 ;
if ( ( V_245 != 0 ) &&
( ( V_245 < V_521 ) || ( V_245 > V_522 ) ) )
return - V_31 ;
if ( ! V_287 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 ) {
F_31 ( L_226 , V_245 ) ;
return V_63 ;
}
if ( V_245 )
V_6 -> V_187 |= V_523 ;
else
V_6 -> V_187 &= ~ V_523 ;
V_6 -> V_245 = V_245 ;
if ( ! V_287 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static int F_232 ( struct V_5 * V_6 , int V_287 )
{
struct V_56 V_57 = {
. V_56 = V_524 ,
. V_88 = 0 ,
. V_65 = 12 ,
} ;
T_1 V_525 , V_14 = sizeof( T_1 ) ;
int V_63 ;
if ( ! V_287 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
if ( V_6 -> V_150 -> V_198 == V_433 )
V_57 . V_67 [ 0 ] |= V_526 ;
V_57 . V_67 [ 0 ] |= V_527 |
V_528 | V_529 ;
if ( ! ( V_6 -> V_187 & V_530 ) )
V_57 . V_67 [ 0 ] |= V_531 ;
V_63 = F_26 ( V_6 ,
V_532 ,
& V_525 , & V_14 ) ;
if ( V_63 )
V_525 = V_533 ;
V_57 . V_67 [ 1 ] = V_534 ;
V_57 . V_67 [ 2 ] = V_534 & V_525 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
#if ! F_233 ( V_535 ) && ! F_233 ( V_536 )
V_57 . V_56 = V_537 ;
V_57 . V_88 = 0 ;
V_57 . V_65 = 0 ;
F_41 ( V_6 , & V_57 ) ;
#endif
if ( ! V_287 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static int F_234 ( struct V_5 * V_6 , T_1 V_538 ,
int V_287 )
{
struct V_56 V_57 = {
. V_56 = V_539 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_538 & V_540 ;
if ( ! V_287 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
F_41 ( V_6 , & V_57 ) ;
V_57 . V_56 = V_541 ;
F_41 ( V_6 , & V_57 ) ;
V_57 . V_56 = V_542 ;
F_41 ( V_6 , & V_57 ) ;
if ( ! V_287 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_6 -> V_543 = V_538 ;
return 0 ;
}
static int F_235 ( struct V_5 * V_6 , int V_544 )
{
struct V_56 V_57 = {
. V_56 = V_545 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_544 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
if ( V_544 == V_546 )
V_6 -> V_547 = F_236 ( V_6 -> V_547 ) ;
else
V_6 -> V_547 = V_548 | V_544 ;
#ifdef F_237
if ( V_6 -> V_516 == V_549 && V_6 -> V_550 != V_551 ) {
V_57 . V_56 = V_552 ;
V_57 . V_67 [ 0 ] = ( T_1 ) V_6 -> V_550 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
}
#endif
return 0 ;
}
static int F_238 ( struct V_5 * V_6 , T_1 V_553 )
{
struct V_56 V_57 = {
. V_56 = V_554 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
if ( V_553 & V_555 )
V_57 . V_67 [ 0 ] = V_556 ;
else
V_57 . V_67 [ 0 ] = V_553 & ~ V_555 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_557 = V_553 ;
return 0 ;
}
static int F_239 ( struct V_5 * V_6 , T_1 V_558 )
{
struct V_56 V_57 = {
. V_56 = V_559 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_558 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_560 = V_558 ;
return 0 ;
}
static int F_240 ( struct V_5 * V_6 , T_1 V_558 )
{
struct V_56 V_57 = {
. V_56 = V_561 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_558 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_562 = V_558 ;
return 0 ;
}
static int F_241 ( struct V_5 * V_6 , T_3 * V_273 ,
int V_287 )
{
struct V_56 V_57 = {
. V_56 = V_563 ,
. V_88 = 0 ,
. V_65 = ( V_273 == NULL ) ? 0 : V_230
} ;
int V_63 ;
#ifdef F_124
if ( V_273 != NULL )
F_42 ( L_227 , V_273 ) ;
else
F_42 ( L_228 ) ;
#endif
if ( V_273 != NULL )
memcpy ( V_57 . V_67 , V_273 , V_230 ) ;
if ( ! V_287 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_287 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_242 ( struct V_5 * V_6 )
{
struct V_56 V_57 = {
. V_56 = V_564 ,
. V_88 = 0 ,
. V_65 = V_230
} ;
int V_63 ;
int V_14 ;
F_42 ( L_229 ) ;
V_14 = V_230 ;
memcpy ( V_57 . V_67 , V_6 -> V_273 , V_230 ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
return V_63 ;
}
static int F_243 ( struct V_5 * V_6 ,
struct V_565 * V_566 ,
int V_287 )
{
struct V_56 V_57 = {
. V_56 = V_567 ,
. V_88 = 0 ,
. V_65 = sizeof( struct V_565 ) ,
} ;
int V_63 ;
F_42 ( L_230 ) ;
if ( ! V_287 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
memcpy ( V_57 . V_67 , V_566 ,
sizeof( struct V_565 ) ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_287 ) {
if ( F_83 ( V_6 ) )
V_63 = - V_70 ;
}
return V_63 ;
}
static int F_244 ( struct V_5 * V_6 ,
int V_568 ,
int V_569 ,
int V_570 ,
int V_287 )
{
struct V_56 V_57 = {
. V_56 = V_571 ,
. V_88 = 0 ,
. V_65 = sizeof(struct V_572 )
} ;
struct V_572 * V_573 =
(struct V_572 * ) & V_57 . V_67 ;
int V_63 ;
memset ( V_573 , 0 , sizeof( * V_573 ) ) ;
V_573 -> V_568 = V_568 ;
V_573 -> V_570 = V_570 ;
switch ( V_569 ) {
default:
case V_574 :
V_573 -> V_575 = V_576 ;
break;
case V_577 :
V_573 -> V_575 = V_578 |
V_579 ;
break;
case V_580 :
V_573 -> V_575 = V_578 |
V_579 | V_581 ;
break;
case V_582 :
V_573 -> V_575 = V_578 |
V_579 | V_583 ;
break;
case V_584 :
V_573 -> V_575 = V_578 |
V_579 | V_581 | V_585 ;
break;
}
F_42
( L_231 ,
V_573 -> V_568 , V_573 -> V_575 , V_569 ) ;
V_573 -> V_586 = 0 ;
if ( ! V_287 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_287 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_245 ( struct V_5 * V_6 , T_1 V_587 )
{
struct V_56 V_57 = {
. V_56 = V_552 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 = 0 ;
T_1 V_315 = V_587 ;
if ( V_587 != V_588 )
V_315 = ( V_587 - V_589 ) * 16 /
( V_590 - V_589 ) ;
V_57 . V_67 [ 0 ] = V_315 ;
if ( V_6 -> V_150 -> V_198 == V_433 )
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_63 )
V_6 -> V_587 = V_587 ;
return 0 ;
}
static int F_246 ( struct V_5 * V_6 ,
T_1 V_591 , int V_287 )
{
struct V_56 V_57 = {
. V_56 = V_592 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_591 ;
F_31 ( L_42 ) ;
if ( V_6 -> V_150 -> V_198 == V_433 ) {
if ( ! V_287 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
F_41 ( V_6 , & V_57 ) ;
if ( ! V_287 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
}
F_31 ( L_45 ) ;
return 0 ;
}
static void F_77 ( struct V_5 * V_6 )
{
F_221 ( V_6 ) ;
F_226 ( V_6 ) ;
F_180 ( V_6 ) ;
}
static void F_247 ( struct V_5 * V_6 )
{
F_223 ( V_6 ) ;
F_227 ( V_6 ) ;
F_182 ( V_6 ) ;
}
static int F_248 ( struct V_5 * V_6 )
{
if ( F_219 ( V_6 ) ||
F_224 ( V_6 ) || F_177 ( V_6 ) )
goto V_123;
return 0 ;
V_123:
F_223 ( V_6 ) ;
F_227 ( V_6 ) ;
F_182 ( V_6 ) ;
return - V_240 ;
}
static int F_249 ( struct V_5 * V_6 , T_1 V_62 ,
int V_287 )
{
struct V_56 V_57 = {
. V_56 = V_593 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_62 ;
F_42 ( L_232 , V_62 ) ;
if ( ! V_287 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_187 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_287 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_250 ( struct V_5 * V_6 ,
int V_594 , char * V_595 , int V_14 , int V_287 )
{
int V_596 = V_14 ? ( V_14 <= 5 ? 5 : 13 ) : 0 ;
struct V_56 V_57 = {
. V_56 = V_597 ,
. V_88 = 0 ,
. V_65 = sizeof( struct V_598 ) ,
} ;
struct V_598 * V_599 = ( void * ) V_57 . V_67 ;
int V_63 ;
F_42 ( L_233 ,
V_594 , V_596 , V_14 ) ;
V_599 -> V_594 = V_594 ;
V_599 -> V_14 = V_596 ;
if ( V_596 ) {
memcpy ( V_599 -> V_595 , V_595 , V_14 ) ;
memset ( V_599 -> V_595 + V_14 , 0 , V_596 - V_14 ) ;
}
if ( V_596 == 0 )
F_251 ( L_234 ,
V_6 -> V_33 -> V_51 , V_599 -> V_594 ) ;
else if ( V_596 == 5 )
F_251 ( L_235 V_600 L_165 ,
V_6 -> V_33 -> V_51 , V_599 -> V_594 , V_599 -> V_14 ,
F_252 ( V_599 -> V_595 ) ) ;
else
F_251 ( L_235 V_601
L_165 ,
V_6 -> V_33 -> V_51 , V_599 -> V_594 , V_599 -> V_14 ,
F_253 ( V_599 -> V_595 ) ) ;
if ( ! V_287 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_187 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_287 ) {
int V_602 = F_83 ( V_6 ) ;
if ( V_63 == 0 )
V_63 = V_602 ;
}
return V_63 ;
}
static int F_254 ( struct V_5 * V_6 ,
int V_594 , int V_287 )
{
struct V_56 V_57 = {
. V_56 = V_603 ,
. V_88 = 0 ,
. V_65 = 4 ,
. V_67 = { V_594 } ,
} ;
int V_63 ;
F_42 ( L_236 , V_594 ) ;
if ( V_594 < 0 || V_594 > 3 )
return - V_31 ;
if ( ! V_287 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_187 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_287 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_255 ( struct V_5 * V_6 , int V_287 )
{
int V_19 , V_63 , V_568 , V_604 , V_605 ;
if ( ! ( V_6 -> V_49 & V_72 ) )
return 0 ;
if ( ! V_287 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
if ( ! V_6 -> V_150 -> V_190 . V_192 ) {
V_63 =
F_244 ( V_6 , V_606 ,
V_574 , 0 , 1 ) ;
} else {
V_568 = V_606 ;
if ( V_6 -> V_150 -> V_190 . V_62 & V_607 ) {
if ( V_6 -> V_150 -> V_190 . V_568 == V_608 )
V_568 = V_609 ;
else if ( V_6 -> V_150 -> V_190 . V_568 == V_610 )
V_568 = V_611 ;
}
V_604 = V_574 ;
if ( V_6 -> V_150 -> V_190 . V_62 & V_612 )
V_604 = V_6 -> V_150 -> V_190 . V_43 ;
V_605 = 0 ;
if ( V_6 -> V_150 -> V_190 . V_62 & V_613 )
V_605 = V_6 -> V_150 -> V_190 . V_614 ;
V_63 =
F_244 ( V_6 , V_568 , V_604 ,
V_605 , 1 ) ;
}
if ( V_63 )
goto exit;
if ( V_6 -> V_150 -> V_190 . V_192 ) {
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
if ( ! ( V_6 -> V_150 -> V_190 . V_62 & ( 1 << V_19 ) ) ) {
memset ( V_6 -> V_150 -> V_190 . V_615 [ V_19 ] , 0 , V_616 ) ;
V_6 -> V_150 -> V_190 . V_617 [ V_19 ] = 0 ;
} else {
V_63 = F_250 ( V_6 , V_19 ,
V_6 -> V_150 -> V_190 . V_615 [ V_19 ] ,
V_6 -> V_150 -> V_190 .
V_617 [ V_19 ] , 1 ) ;
if ( V_63 )
goto exit;
}
}
F_254 ( V_6 , V_6 -> V_150 -> V_492 . V_494 , 1 ) ;
}
V_63 =
F_249 ( V_6 ,
V_6 -> V_150 -> V_190 .
V_192 ? V_618 : 0 , 1 ) ;
if ( V_63 )
goto exit;
V_6 -> V_49 &= ~ V_264 ;
exit:
if ( ! V_287 )
F_83 ( V_6 ) ;
return V_63 ;
}
static void F_256 ( struct V_261 * V_262 )
{
struct V_5 * V_6 =
F_108 ( V_262 , struct V_5 , V_294 . V_262 ) ;
if ( ! ( V_6 -> V_49 & V_166 ) &&
V_6 -> V_49 & V_264 )
F_255 ( V_6 , 0 ) ;
}
static void F_257 ( struct V_1 * V_2 ,
struct V_619 * V_190 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_19 , V_620 = 0 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) )
goto V_622;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
if ( V_190 -> V_62 & ( 1 << V_19 ) ) {
V_6 -> V_150 -> V_190 . V_617 [ V_19 ] = V_190 -> V_617 [ V_19 ] ;
if ( V_190 -> V_617 [ V_19 ] == 0 )
V_6 -> V_150 -> V_190 . V_62 &= ~ ( 1 << V_19 ) ;
else
memcpy ( V_6 -> V_150 -> V_190 . V_615 [ V_19 ] , V_190 -> V_615 [ V_19 ] ,
V_190 -> V_617 [ V_19 ] ) ;
if ( V_190 -> V_43 == V_577 ) {
V_6 -> V_150 -> V_190 . V_62 |= ( 1 << V_19 ) ;
V_6 -> V_49 |= V_264 ;
} else
V_6 -> V_150 -> V_190 . V_62 &= ~ ( 1 << V_19 ) ;
}
}
if ( ( V_190 -> V_62 & V_623 ) &&
V_6 -> V_150 -> V_190 . V_624 != V_190 -> V_624 ) {
if ( V_190 -> V_624 <= 3 ) {
V_6 -> V_150 -> V_190 . V_624 = V_190 -> V_624 ;
V_6 -> V_150 -> V_190 . V_62 |= V_623 ;
} else
V_6 -> V_150 -> V_190 . V_62 &= ~ V_623 ;
V_6 -> V_49 |= V_264 ;
}
if ( ( V_190 -> V_62 & V_607 ) &&
( V_6 -> V_150 -> V_190 . V_568 != V_190 -> V_568 ) ) {
V_6 -> V_150 -> V_190 . V_568 = V_190 -> V_568 ;
V_6 -> V_150 -> V_190 . V_62 |= V_607 ;
V_6 -> V_49 |= V_264 ;
}
if ( V_190 -> V_62 & V_191 && V_6 -> V_150 -> V_190 . V_192 != V_190 -> V_192 ) {
V_6 -> V_150 -> V_190 . V_62 |= V_191 ;
V_6 -> V_150 -> V_190 . V_192 = V_190 -> V_192 ;
V_6 -> V_49 |= V_264 ;
V_620 = 1 ;
}
if ( V_190 -> V_62 & V_625 )
V_6 -> V_150 -> V_190 . V_626 = V_190 -> V_626 ;
if ( V_190 -> V_62 & V_612 && V_6 -> V_150 -> V_190 . V_43 != V_190 -> V_43 ) {
V_6 -> V_150 -> V_190 . V_43 = V_190 -> V_43 ;
V_6 -> V_150 -> V_190 . V_62 |= V_612 ;
V_6 -> V_49 |= V_264 ;
}
F_251 ( L_237 ,
V_6 -> V_150 -> V_190 . V_62 & ( 1 << 8 ) ? '1' : '0' ,
V_6 -> V_150 -> V_190 . V_62 & ( 1 << 7 ) ? '1' : '0' ,
V_6 -> V_150 -> V_190 . V_62 & ( 1 << 6 ) ? '1' : '0' ,
V_6 -> V_150 -> V_190 . V_62 & ( 1 << 5 ) ? '1' : '0' ,
V_6 -> V_150 -> V_190 . V_62 & ( 1 << 4 ) ? '1' : '0' ,
V_6 -> V_150 -> V_190 . V_62 & ( 1 << 3 ) ? '1' : '0' ,
V_6 -> V_150 -> V_190 . V_62 & ( 1 << 2 ) ? '1' : '0' ,
V_6 -> V_150 -> V_190 . V_62 & ( 1 << 1 ) ? '1' : '0' ,
V_6 -> V_150 -> V_190 . V_62 & ( 1 << 0 ) ? '1' : '0' ) ;
if ( ! ( V_6 -> V_49 & ( V_166 | V_165 ) ) )
F_255 ( V_6 , 0 ) ;
V_622:
F_85 ( & V_6 -> V_265 ) ;
}
static int F_98 ( struct V_5 * V_6 )
{
int V_63 ;
int V_287 = 1 ;
T_3 * V_273 ;
F_31 ( L_42 ) ;
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
#ifdef F_154
if ( V_6 -> V_150 -> V_198 == V_199 ) {
V_63 = F_231 ( V_6 , V_6 -> V_245 , V_287 ) ;
if ( V_63 )
return V_63 ;
F_31 ( L_45 ) ;
return 0 ;
}
#endif
V_63 = F_228 ( V_6 ) ;
if ( V_63 )
return - V_70 ;
V_63 = F_229 ( V_6 , V_287 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_230 ( V_6 , V_6 -> V_150 -> V_198 , V_287 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_150 -> V_198 == V_433 ) {
V_63 = F_231 ( V_6 , V_6 -> V_245 , V_287 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_232 ( V_6 , V_287 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_234 ( V_6 , V_6 -> V_543 , V_287 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_235 ( V_6 , V_546 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_238 ( V_6 , V_6 -> V_557 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_187 & V_627 )
V_273 = V_6 -> V_273 ;
else
V_273 = NULL ;
V_63 = F_241 ( V_6 , V_273 , V_287 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_187 & V_283 )
V_63 = F_113 ( V_6 , V_6 -> V_268 , V_6 -> V_267 ,
V_287 ) ;
else
V_63 = F_113 ( V_6 , NULL , 0 , V_287 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_255 ( V_6 , V_287 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_150 -> V_198 == V_433 ) {
V_63 =
F_246 ( V_6 ,
V_6 -> V_628 ,
V_287 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_245 ( V_6 , V_6 -> V_587 ) ;
if ( V_63 )
return V_63 ;
}
F_31 ( L_45 ) ;
return 0 ;
}
static int F_258 ( struct V_1 * V_2 , void * V_468 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_629 * V_8 = V_468 ;
int V_63 = 0 ;
if ( ! F_259 ( V_8 -> V_630 ) )
return - V_631 ;
F_84 ( & V_6 -> V_265 ) ;
V_6 -> V_187 |= V_515 ;
memcpy ( V_6 -> V_229 , V_8 -> V_630 , V_230 ) ;
V_63 = F_229 ( V_6 , 0 ) ;
if ( V_63 )
goto V_622;
V_6 -> V_47 = 0 ;
F_85 ( & V_6 -> V_265 ) ;
F_107 ( & V_6 -> V_52 . V_262 ) ;
return 0 ;
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_260 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_62 ;
F_31 ( L_238 ) ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( V_6 -> V_49 & V_166 ) {
F_261 ( V_2 ) ;
F_262 ( V_2 ) ;
}
F_52 ( & V_6 -> V_68 , V_62 ) ;
return 0 ;
}
static int F_263 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_62 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
F_31 ( L_42 ) ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( V_6 -> V_49 & V_166 )
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
while ( ! F_44 ( & V_6 -> V_423 ) ) {
V_59 = V_6 -> V_423 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_426 ) ;
F_162 ( V_61 -> V_81 . V_409 . V_410 ) ;
V_61 -> V_81 . V_409 . V_410 = NULL ;
F_48 ( V_59 , & V_6 -> V_411 ) ;
F_49 ( & V_6 -> V_412 ) ;
}
F_52 ( & V_6 -> V_68 , V_62 ) ;
F_31 ( L_45 ) ;
return 0 ;
}
static void F_264 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_2 -> V_328 . V_632 ++ ;
#ifdef F_154
if ( V_6 -> V_150 -> V_198 == V_199 )
return;
#endif
F_31 ( L_239 ,
V_2 -> V_51 ) ;
F_35 ( V_6 ) ;
}
static int F_265 ( struct V_5 * V_6 , int V_147 )
{
V_6 -> V_150 -> V_633 = V_147 ;
return 0 ;
}
static int F_266 ( struct V_5 * V_6 , int V_147 )
{
struct V_634 * V_150 = V_6 -> V_150 ;
struct V_619 V_190 = {
. V_62 = V_607 ,
} ;
int V_266 = 0 ;
if ( V_147 & V_635 ) {
V_190 . V_568 = V_608 ;
V_150 -> V_636 = 0 ;
} else if ( V_147 & V_637 ) {
V_190 . V_568 = V_638 ;
V_150 -> V_636 = 1 ;
} else if ( V_147 & V_639 ) {
V_190 . V_568 = V_610 ;
V_150 -> V_636 = 1 ;
} else
return - V_31 ;
if ( V_150 -> V_640 )
V_150 -> V_640 ( V_150 -> V_2 , & V_190 ) ;
else
V_266 = - V_641 ;
return V_266 ;
}
static void V_565 ( struct V_5 * V_6 ,
char * V_642 , int V_643 )
{
struct V_565 V_644 ;
V_644 . V_645 = 0 ;
memcpy ( V_644 . V_646 , V_642 , V_643 ) ;
V_644 . V_647 = V_643 ;
F_265 ( V_6 , 1 ) ;
F_243 ( V_6 , & V_644 , 0 ) ;
}
static void F_267 ( struct V_1 * V_2 ,
struct V_648 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char V_649 [ 64 ] , V_650 [ 64 ] ;
F_268 ( V_81 -> V_651 , V_652 , sizeof( V_81 -> V_651 ) ) ;
F_268 ( V_81 -> V_121 , V_653 , sizeof( V_81 -> V_121 ) ) ;
F_269 ( V_6 , V_649 , sizeof( V_649 ) ) ;
F_270 ( V_6 , V_650 , sizeof( V_650 ) ) ;
snprintf ( V_81 -> V_654 , sizeof( V_81 -> V_654 ) , L_240 ,
V_649 , V_6 -> V_156 , V_650 ) ;
F_268 ( V_81 -> V_655 , F_271 ( V_6 -> V_260 ) ,
sizeof( V_81 -> V_655 ) ) ;
}
static T_1 F_272 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return ( V_6 -> V_49 & V_166 ) ? 1 : 0 ;
}
static void F_273 ( struct V_261 * V_262 )
{
struct V_5 * V_6 =
F_108 ( V_262 , struct V_5 , V_182 . V_262 ) ;
unsigned long V_62 ;
T_1 V_656 = 0xa5a5a5a5 ;
T_1 V_14 = sizeof( V_656 ) ;
int V_657 = 0 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( V_6 -> V_69 != 0 ) {
F_31 ( L_241 ,
V_6 -> V_33 -> V_51 ) ;
V_657 = 1 ;
} else if ( F_26 ( V_6 , V_658 , & V_656 , & V_14 ) ||
( V_656 == V_6 -> V_495 ) ) {
F_31 ( L_242 ,
V_6 -> V_33 -> V_51 ) ;
V_657 = 1 ;
}
if ( V_657 ) {
V_6 -> V_181 = 1 ;
V_6 -> V_489 ++ ;
F_35 ( V_6 ) ;
}
V_6 -> V_495 = V_656 ;
if ( ! V_6 -> V_181 )
F_39 ( & V_6 -> V_182 , V_53 / 2 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
}
static void F_274 ( struct V_261 * V_262 )
{
struct V_5 * V_6 =
F_108 ( V_262 , struct V_5 , V_216 . V_262 ) ;
unsigned long V_62 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( F_71 ( V_6 ) ) {
F_210 ( L_243 ) ;
if ( ! V_6 -> V_215 )
F_39 ( & V_6 -> V_216 ,
F_97 ( V_53 ) ) ;
goto V_659;
}
if ( ! ( V_6 -> V_49 & V_486 ) ) {
F_210 ( L_244
L_245 ) ;
F_35 ( V_6 ) ;
} else
F_210 ( L_246
L_247 ) ;
V_659:
F_52 ( & V_6 -> V_68 , V_62 ) ;
}
static struct V_1 * F_275 ( struct V_260 * V_260 ,
void T_12 * V_7 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_276 ( sizeof( struct V_5 ) , 0 ) ;
if ( ! V_2 )
return NULL ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_150 = F_277 ( V_2 ) ;
V_6 -> V_260 = V_260 ;
V_6 -> V_33 = V_2 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_150 -> V_660 = F_176 ;
V_6 -> V_150 -> V_640 = F_257 ;
V_6 -> V_150 -> V_661 = - 20 ;
V_6 -> V_150 -> V_662 = - 85 ;
V_2 -> V_663 = & V_664 ;
V_2 -> V_665 = & V_666 ;
V_2 -> V_667 = & V_668 ;
V_6 -> V_669 . V_670 = V_6 -> V_150 ;
V_2 -> V_669 = & V_6 -> V_669 ;
V_2 -> V_671 = 3 * V_53 ;
V_2 -> V_456 = 0 ;
V_6 -> V_547 = V_672 ;
#ifdef F_154
V_6 -> V_187 |= V_345 ;
#endif
V_6 -> V_150 -> V_633 = 0 ;
V_6 -> V_150 -> V_673 = 0 ;
V_6 -> V_150 -> V_674 = 0 ;
V_6 -> V_150 -> V_675 = 1 ;
switch ( V_676 ) {
case 1 :
V_6 -> V_150 -> V_198 = V_433 ;
break;
#ifdef F_154
case 2 :
V_6 -> V_150 -> V_198 = V_199 ;
break;
#endif
default:
case 0 :
V_6 -> V_150 -> V_198 = V_428 ;
break;
}
if ( V_677 == 1 )
V_6 -> V_49 |= V_206 ;
if ( V_245 != 0 &&
( ( V_245 >= V_521 ) && ( V_245 <= V_522 ) ) ) {
V_6 -> V_187 |= V_523 ;
V_6 -> V_245 = V_245 ;
}
if ( V_678 )
V_6 -> V_187 |= V_188 ;
V_6 -> V_628 = V_679 ;
V_6 -> V_560 = V_680 ;
V_6 -> V_562 = V_681 ;
V_6 -> V_557 = V_682 | V_555 ;
V_6 -> V_683 = V_684 | V_685 ;
V_6 -> V_587 = V_588 ;
V_6 -> V_543 = V_686 ;
strcpy ( V_6 -> V_687 , L_248 ) ;
F_278 ( & V_6 -> V_68 ) ;
F_279 ( & V_6 -> V_265 ) ;
F_279 ( & V_6 -> V_179 ) ;
F_280 ( & V_6 -> V_55 ) ;
F_37 ( V_2 ) ;
F_181 ( & V_6 -> V_75 ) ;
F_181 ( & V_6 -> V_91 ) ;
F_222 ( & V_6 -> V_90 ) ;
F_222 ( & V_6 -> V_92 ) ;
F_181 ( & V_6 -> V_411 ) ;
F_181 ( & V_6 -> V_423 ) ;
F_222 ( & V_6 -> V_412 ) ;
F_222 ( & V_6 -> V_426 ) ;
F_181 ( & V_6 -> V_395 ) ;
F_222 ( & V_6 -> V_403 ) ;
F_281 ( & V_6 -> V_52 , F_107 ) ;
F_281 ( & V_6 -> V_294 , F_256 ) ;
F_281 ( & V_6 -> V_285 , V_688 ) ;
F_281 ( & V_6 -> V_182 , F_273 ) ;
F_281 ( & V_6 -> V_216 , F_274 ) ;
F_281 ( & V_6 -> V_296 , F_118 ) ;
F_282 ( & V_6 -> V_459 , ( void (*) ( unsigned long ) )
F_169 , ( unsigned long ) V_6 ) ;
V_6 -> V_215 = 1 ;
V_6 -> V_181 = 1 ;
return V_2 ;
}
static int F_283 ( struct V_260 * V_260 ,
const struct V_689 * V_690 )
{
void T_12 * V_7 ;
struct V_1 * V_2 = NULL ;
struct V_5 * V_6 = NULL ;
int V_63 = 0 ;
int V_691 = 0 ;
T_1 V_4 ;
F_31 ( L_42 ) ;
if ( ! ( F_284 ( V_260 , 0 ) & V_692 ) ) {
F_31 ( L_249 ) ;
V_63 = - V_693 ;
goto V_39;
}
V_7 = F_285 ( V_260 , 0 , 0 ) ;
if ( ! V_7 ) {
F_27 (KERN_WARNING DRV_NAME
L_250 ) ;
V_63 = - V_70 ;
goto V_123;
}
V_2 = F_275 ( V_260 , V_7 ) ;
if ( ! V_2 ) {
F_27 (KERN_WARNING DRV_NAME
L_251 ) ;
V_63 = - V_240 ;
goto V_123;
}
V_63 = F_286 ( V_260 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_252 ) ;
return V_63 ;
}
V_6 = F_2 ( V_2 ) ;
F_287 ( V_260 ) ;
F_288 ( V_260 , V_6 ) ;
V_63 = F_289 ( V_260 , F_290 ( 32 ) ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_253 ) ;
F_291 ( V_260 ) ;
return V_63 ;
}
V_63 = F_292 ( V_260 , V_652 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_254 ) ;
F_291 ( V_260 ) ;
return V_63 ;
}
F_184 ( V_260 , 0x40 , & V_4 ) ;
if ( ( V_4 & 0x0000ff00 ) != 0 )
F_293 ( V_260 , 0x40 , V_4 & 0xffff00ff ) ;
if ( ! F_25 ( V_2 ) ) {
F_27 (KERN_WARNING DRV_NAME
L_255 ) ;
V_63 = - V_693 ;
goto V_123;
}
F_294 ( V_2 , & V_260 -> V_2 ) ;
V_6 -> V_49 |= V_136 ;
F_68 ( V_6 ) ;
if ( F_248 ( V_6 ) ) {
F_27 (KERN_WARNING DRV_NAME
L_256 ) ;
V_63 = - V_240 ;
goto V_123;
}
F_77 ( V_6 ) ;
V_63 = F_295 ( V_260 -> V_456 ,
F_172 , V_694 , V_2 -> V_51 , V_6 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_257 , pci_dev->irq) ;
goto V_123;
}
V_2 -> V_456 = V_260 -> V_456 ;
F_31 ( L_258 ) ;
F_27 (KERN_INFO DRV_NAME
L_259 ) ;
V_63 = F_93 ( V_6 , 1 ) ;
if ( V_63 )
goto V_123;
V_63 = F_101 ( V_2 ) ;
if ( V_63 )
goto V_123;
V_691 = 1 ;
V_63 = F_296 ( V_2 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_260 ) ;
goto V_123;
}
V_691 = 2 ;
F_84 ( & V_6 -> V_265 ) ;
F_31 ( L_261 , V_2 -> V_51 , F_271 ( V_260 ) ) ;
V_63 = F_297 ( & V_260 -> V_2 . V_695 , & V_696 ) ;
if ( V_63 )
goto V_71;
if ( ! ( V_6 -> V_49 & V_486 ) ) {
if ( F_83 ( V_6 ) ) {
F_27 (KERN_WARNING DRV_NAME
L_262 ,
priv->net_dev->name) ;
F_86 ( V_6 ) ;
V_63 = - V_70 ;
goto V_71;
}
F_90 ( V_6 ) ;
F_92 ( V_6 ) ;
}
F_31 ( L_45 ) ;
V_6 -> V_49 |= V_621 ;
F_85 ( & V_6 -> V_265 ) ;
V_39:
return V_63 ;
V_71:
F_85 ( & V_6 -> V_265 ) ;
V_123:
if ( V_2 ) {
if ( V_691 >= 2 )
F_298 ( V_2 ) ;
if ( V_691 ) {
F_299 ( V_6 -> V_150 -> V_151 . V_152 ) ;
F_129 ( V_6 -> V_150 -> V_233 . V_237 ) ;
}
F_86 ( V_6 ) ;
F_68 ( V_6 ) ;
if ( V_2 -> V_456 )
F_300 ( V_2 -> V_456 , V_6 ) ;
F_217 ( V_6 ) ;
F_247 ( V_6 ) ;
F_301 ( & V_260 -> V_2 . V_695 ,
& V_696 ) ;
F_302 ( V_2 , 0 ) ;
}
F_303 ( V_260 , V_7 ) ;
F_304 ( V_260 ) ;
F_291 ( V_260 ) ;
goto V_39;
}
static void F_305 ( struct V_260 * V_260 )
{
struct V_5 * V_6 = F_306 ( V_260 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
F_84 ( & V_6 -> V_265 ) ;
V_6 -> V_49 &= ~ V_621 ;
F_301 ( & V_260 -> V_2 . V_695 , & V_696 ) ;
#ifdef F_61
if ( V_120 . V_121 )
F_66 ( V_6 , & V_120 ) ;
#endif
F_99 ( V_6 ) ;
F_85 ( & V_6 -> V_265 ) ;
F_298 ( V_2 ) ;
F_217 ( V_6 ) ;
F_247 ( V_6 ) ;
F_128 ( V_6 ) ;
F_300 ( V_2 -> V_456 , V_6 ) ;
F_303 ( V_260 , V_6 -> V_7 ) ;
F_299 ( V_6 -> V_150 -> V_151 . V_152 ) ;
F_129 ( V_6 -> V_150 -> V_233 . V_237 ) ;
F_302 ( V_2 , 0 ) ;
F_304 ( V_260 ) ;
F_291 ( V_260 ) ;
F_31 ( L_45 ) ;
}
static int F_307 ( struct V_260 * V_260 , T_13 V_102 )
{
struct V_5 * V_6 = F_306 ( V_260 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
F_31 ( L_263 , V_2 -> V_51 ) ;
F_84 ( & V_6 -> V_265 ) ;
if ( V_6 -> V_49 & V_621 ) {
F_99 ( V_6 ) ;
}
F_308 ( V_2 ) ;
F_309 ( V_260 ) ;
F_291 ( V_260 ) ;
F_310 ( V_260 , V_697 ) ;
V_6 -> V_698 = F_36 () ;
F_85 ( & V_6 -> V_265 ) ;
return 0 ;
}
static int F_311 ( struct V_260 * V_260 )
{
struct V_5 * V_6 = F_306 ( V_260 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
int V_63 ;
T_1 V_4 ;
if ( V_699 )
return 0 ;
F_84 ( & V_6 -> V_265 ) ;
F_31 ( L_264 , V_2 -> V_51 ) ;
F_310 ( V_260 , V_700 ) ;
V_63 = F_286 ( V_260 ) ;
if ( V_63 ) {
F_27 ( V_701 L_265 ,
V_2 -> V_51 ) ;
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
F_312 ( V_260 ) ;
F_184 ( V_260 , 0x40 , & V_4 ) ;
if ( ( V_4 & 0x0000ff00 ) != 0 )
F_293 ( V_260 , 0x40 , V_4 & 0xffff00ff ) ;
F_313 ( V_2 ) ;
V_6 -> V_205 = F_36 () - V_6 -> V_698 ;
if ( ! ( V_6 -> V_49 & V_206 ) )
F_93 ( V_6 , 0 ) ;
F_85 ( & V_6 -> V_265 ) ;
return 0 ;
}
static void F_314 ( struct V_260 * V_260 )
{
struct V_5 * V_6 = F_306 ( V_260 ) ;
F_99 ( V_6 ) ;
F_291 ( V_260 ) ;
}
static int T_14 F_315 ( void )
{
int V_266 ;
F_27 (KERN_INFO DRV_NAME L_266 , DRV_DESCRIPTION, DRV_VERSION) ;
F_27 (KERN_INFO DRV_NAME L_267 , DRV_COPYRIGHT) ;
F_316 ( & V_207 , V_702 ,
V_223 ) ;
V_266 = F_317 ( & V_703 ) ;
if ( V_266 )
goto V_39;
#ifdef F_124
V_44 = V_704 ;
V_266 = F_318 ( & V_703 . V_651 ,
& V_705 ) ;
#endif
V_39:
return V_266 ;
}
static void T_15 F_319 ( void )
{
#ifdef F_124
F_320 ( & V_703 . V_651 ,
& V_705 ) ;
#endif
F_321 ( & V_703 ) ;
F_322 ( & V_207 ) ;
}
static int F_323 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_49 & V_166 ) )
strcpy ( V_218 -> V_51 , L_268 ) ;
else
snprintf ( V_218 -> V_51 , V_708 , L_269 ) ;
F_324 ( L_270 , V_218 -> V_51 ) ;
return 0 ;
}
static int F_325 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_709 * V_710 = & V_218 -> V_243 ;
int V_63 = 0 ;
if ( V_6 -> V_150 -> V_198 == V_428 )
return - V_641 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) ) {
V_63 = - V_70 ;
goto V_622;
}
if ( V_710 -> V_393 == 1 ) {
if ( ( V_710 -> V_711 >= ( int ) 2.412e8 && V_710 -> V_711 <= ( int ) 2.487e8 ) ) {
int V_712 = V_710 -> V_711 / 100000 ;
int V_42 = 0 ;
while ( ( V_42 < V_522 ) &&
( V_712 != V_713 [ V_42 ] ) )
V_42 ++ ;
V_710 -> V_393 = 0 ;
V_710 -> V_711 = V_42 + 1 ;
}
}
if ( V_710 -> V_393 > 0 || V_710 -> V_711 > 1000 ) {
V_63 = - V_641 ;
goto V_622;
} else {
F_324 ( L_271 , V_710 -> V_711 ) ;
V_63 = F_231 ( V_6 , V_710 -> V_711 , 0 ) ;
}
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_326 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_243 . V_393 = 0 ;
if ( V_6 -> V_187 & V_523 ||
V_6 -> V_49 & V_166 )
V_218 -> V_243 . V_711 = V_6 -> V_245 ;
else
V_218 -> V_243 . V_711 = 0 ;
F_324 ( L_272 , V_6 -> V_245 ) ;
return 0 ;
}
static int F_327 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
F_324 ( L_273 , V_218 -> V_314 ) ;
if ( V_218 -> V_314 == V_6 -> V_150 -> V_198 )
return 0 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) ) {
V_63 = - V_70 ;
goto V_622;
}
switch ( V_218 -> V_314 ) {
#ifdef F_154
case V_199 :
V_63 = F_195 ( V_6 , V_199 ) ;
break;
#endif
case V_433 :
V_63 = F_195 ( V_6 , V_433 ) ;
break;
case V_428 :
case V_714 :
default:
V_63 = F_195 ( V_6 , V_428 ) ;
break;
}
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_328 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_314 = V_6 -> V_150 -> V_198 ;
F_324 ( L_274 , V_218 -> V_314 ) ;
return 0 ;
}
static int F_329 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_715 * V_716 = (struct V_715 * ) V_707 ;
T_2 V_4 ;
int V_19 , V_43 ;
V_218 -> V_37 . V_286 = sizeof( * V_716 ) ;
memset ( V_716 , 0 , sizeof( * V_716 ) ) ;
V_716 -> V_717 = 5 * 1000 * 1000 ;
V_716 -> V_718 . V_719 = 100 ;
V_716 -> V_718 . V_43 = 0 ;
V_716 -> V_718 . V_720 = 0 ;
V_716 -> V_718 . V_721 = 7 ;
V_716 -> V_722 . V_719 = 70 ;
V_716 -> V_722 . V_43 = 20 + V_354 ;
V_716 -> V_722 . V_720 = 0 ;
V_716 -> V_722 . V_721 = 7 ;
V_716 -> V_723 = V_255 ;
for ( V_19 = 0 ; V_19 < V_255 && V_19 < V_724 ; V_19 ++ ) {
V_716 -> V_725 [ V_19 ] = V_253 [ V_19 ] . V_725 * 100 * 1000 ;
}
V_716 -> V_726 = V_727 ;
V_716 -> V_728 = V_556 ;
V_716 -> V_729 = V_730 ;
V_716 -> V_731 = V_732 ;
V_716 -> V_733 = V_734 [ 0 ] ;
V_716 -> V_735 = V_734 [ V_736 - 1 ] ;
V_716 -> V_737 = V_738 [ V_736 - 1 ] ;
V_716 -> V_739 = V_738 [ 0 ] ;
V_716 -> V_740 = V_741 ;
V_716 -> V_742 = V_743 ;
V_716 -> V_744 = V_743 | V_741 ;
V_716 -> V_745 [ 0 ] = 5 ;
V_716 -> V_745 [ 1 ] = 13 ;
V_716 -> V_746 = 2 ;
V_716 -> V_747 = V_748 ;
if ( V_6 -> V_150 -> V_198 == V_433 ) {
V_716 -> V_749 = V_750 ;
V_716 -> V_751 = V_752 ;
for ( V_19 = 0 , V_43 = ( V_590 * 16 ) ;
V_19 < V_752 ;
V_19 ++ , V_43 -=
( ( V_590 -
V_589 ) * 16 ) / ( V_752 - 1 ) )
V_716 -> V_753 [ V_19 ] = V_43 / 16 ;
} else {
V_716 -> V_749 = 0 ;
V_716 -> V_751 = 0 ;
}
V_716 -> V_754 = V_755 ;
V_716 -> V_756 = 18 ;
V_716 -> V_757 = V_758 ;
V_4 = 0 ;
for ( V_19 = 0 ; V_19 < V_758 ; V_19 ++ ) {
V_716 -> V_243 [ V_4 ] . V_19 = V_19 + 1 ;
V_716 -> V_243 [ V_4 ] . V_711 = V_713 [ V_19 ] * 100000 ;
V_716 -> V_243 [ V_4 ] . V_393 = 1 ;
V_4 ++ ;
if ( V_4 == V_759 )
break;
}
V_716 -> V_760 = V_4 ;
V_716 -> V_761 [ 0 ] = ( V_762 |
F_330 ( V_224 ) ) ;
V_716 -> V_761 [ 1 ] = V_763 ;
V_716 -> V_764 = V_765 | V_766 |
V_767 | V_768 ;
F_324 ( L_275 ) ;
return 0 ;
}
static int F_331 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
if ( V_218 -> V_219 . V_220 != V_221 )
return - V_31 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) ) {
V_63 = - V_70 ;
goto V_622;
}
if ( F_332 ( V_218 -> V_219 . V_630 ) ||
F_333 ( V_218 -> V_219 . V_630 ) ) {
F_324 ( L_276 ) ;
V_6 -> V_187 &= ~ V_627 ;
V_63 = F_241 ( V_6 , NULL , 0 ) ;
goto V_622;
}
V_6 -> V_187 |= V_627 ;
memcpy ( V_6 -> V_769 , V_218 -> V_219 . V_630 , V_230 ) ;
V_63 = F_241 ( V_6 , V_218 -> V_219 . V_630 , 0 ) ;
F_324 ( L_277 , V_218 -> V_219 . V_630 ) ;
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_334 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_627 || V_6 -> V_49 & V_166 ) {
V_218 -> V_219 . V_220 = V_221 ;
memcpy ( V_218 -> V_219 . V_630 , V_6 -> V_273 , V_230 ) ;
} else
memset ( V_218 -> V_219 . V_630 , 0 , V_230 ) ;
F_324 ( L_278 , V_218 -> V_219 . V_630 ) ;
return 0 ;
}
static int F_335 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char * V_268 = L_50 ;
int V_286 = 0 ;
int V_63 = 0 ;
F_111 ( V_274 ) ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) ) {
V_63 = - V_70 ;
goto V_622;
}
if ( V_218 -> V_268 . V_62 && V_218 -> V_268 . V_286 ) {
V_286 = V_218 -> V_268 . V_286 ;
V_268 = V_707 ;
}
if ( V_286 == 0 ) {
F_324 ( L_279 ) ;
V_6 -> V_187 &= ~ V_283 ;
V_63 = F_113 ( V_6 , NULL , 0 , 0 ) ;
goto V_622;
}
V_286 = F_34 ( V_286 , V_269 ) ;
V_6 -> V_187 |= V_283 ;
if ( V_6 -> V_267 == V_286 && ! memcmp ( V_6 -> V_268 , V_707 , V_286 ) ) {
F_324 ( L_280 ) ;
V_63 = 0 ;
goto V_622;
}
F_324 ( L_281 ,
F_112 ( V_274 , V_268 , V_286 ) , V_286 ) ;
V_6 -> V_267 = V_286 ;
memcpy ( V_6 -> V_268 , V_268 , V_6 -> V_267 ) ;
V_63 = F_113 ( V_6 , V_268 , V_286 , 0 ) ;
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_336 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_111 ( V_274 ) ;
if ( V_6 -> V_187 & V_283 || V_6 -> V_49 & V_166 ) {
F_324 ( L_282 ,
F_112 ( V_274 , V_6 -> V_268 , V_6 -> V_267 ) ) ;
memcpy ( V_707 , V_6 -> V_268 , V_6 -> V_267 ) ;
V_218 -> V_268 . V_286 = V_6 -> V_267 ;
V_218 -> V_268 . V_62 = 1 ;
} else {
F_324 ( L_283 ) ;
V_218 -> V_268 . V_286 = 0 ;
V_218 -> V_268 . V_62 = 0 ;
}
return 0 ;
}
static int F_337 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_218 -> V_37 . V_286 > V_269 )
return - V_770 ;
V_218 -> V_37 . V_286 = F_146 ( T_4 , V_218 -> V_37 . V_286 , sizeof( V_6 -> V_687 ) ) ;
memset ( V_6 -> V_687 , 0 , sizeof( V_6 -> V_687 ) ) ;
memcpy ( V_6 -> V_687 , V_707 , V_218 -> V_37 . V_286 ) ;
F_324 ( L_284 , V_6 -> V_687 ) ;
return 0 ;
}
static int F_338 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_37 . V_286 = strlen ( V_6 -> V_687 ) ;
memcpy ( V_707 , V_6 -> V_687 , V_218 -> V_37 . V_286 ) ;
V_218 -> V_37 . V_62 = 1 ;
F_324 ( L_285 , V_707 ) ;
return 0 ;
}
static int F_339 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_771 = V_218 -> V_725 . V_147 ;
T_1 V_538 ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) ) {
V_63 = - V_70 ;
goto V_622;
}
V_538 = 0 ;
if ( V_771 == 1000000 ||
( ! V_218 -> V_725 . V_772 && V_771 > 1000000 ) )
V_538 |= V_279 ;
if ( V_771 == 2000000 ||
( ! V_218 -> V_725 . V_772 && V_771 > 2000000 ) )
V_538 |= V_280 ;
if ( V_771 == 5500000 ||
( ! V_218 -> V_725 . V_772 && V_771 > 5500000 ) )
V_538 |= V_281 ;
if ( V_771 == 11000000 ||
( ! V_218 -> V_725 . V_772 && V_771 > 11000000 ) )
V_538 |= V_282 ;
if ( V_538 == 0 )
V_538 = V_686 ;
V_63 = F_234 ( V_6 , V_538 , 0 ) ;
F_324 ( L_286 , V_538 ) ;
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_340 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_4 ;
unsigned int V_14 = sizeof( V_4 ) ;
int V_63 = 0 ;
if ( ! ( V_6 -> V_49 & V_106 ) ||
V_6 -> V_49 & V_486 ||
! ( V_6 -> V_49 & V_166 ) ) {
V_218 -> V_725 . V_147 = 0 ;
return 0 ;
}
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) ) {
V_63 = - V_70 ;
goto V_622;
}
V_63 = F_26 ( V_6 , V_276 , & V_4 , & V_14 ) ;
if ( V_63 ) {
F_324 ( L_287 ) ;
goto V_622;
}
switch ( V_4 & V_540 ) {
case V_279 :
V_218 -> V_725 . V_147 = 1000000 ;
break;
case V_280 :
V_218 -> V_725 . V_147 = 2000000 ;
break;
case V_281 :
V_218 -> V_725 . V_147 = 5500000 ;
break;
case V_282 :
V_218 -> V_725 . V_147 = 11000000 ;
break;
default:
V_218 -> V_725 . V_147 = 0 ;
}
F_324 ( L_288 , V_218 -> V_725 . V_147 ) ;
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_341 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_147 , V_63 ;
if ( V_218 -> V_773 . V_772 == 0 )
return - V_31 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) ) {
V_63 = - V_70 ;
goto V_622;
}
if ( V_218 -> V_773 . V_774 )
V_147 = V_6 -> V_557 | V_555 ;
else {
if ( V_218 -> V_773 . V_147 < 1 || V_218 -> V_773 . V_147 > 2304 ) {
V_63 = - V_31 ;
goto V_622;
}
V_147 = V_218 -> V_773 . V_147 ;
}
V_63 = F_238 ( V_6 , V_147 ) ;
F_324 ( L_289 , V_147 ) ;
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_342 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_773 . V_147 = V_6 -> V_557 & ~ V_555 ;
V_218 -> V_773 . V_772 = 1 ;
V_218 -> V_773 . V_774 = ( V_6 -> V_557 & V_555 ) ? 1 : 0 ;
F_324 ( L_290 , V_218 -> V_773 . V_147 ) ;
return 0 ;
}
static int F_343 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 , V_147 ;
if ( F_209 ( V_6 , V_218 -> V_753 . V_774 ) )
return - V_775 ;
if ( V_6 -> V_150 -> V_198 != V_433 )
return 0 ;
if ( ( V_218 -> V_753 . V_62 & V_776 ) != V_750 )
return - V_31 ;
if ( V_218 -> V_753 . V_772 == 0 )
V_147 = V_588 ;
else {
if ( V_218 -> V_753 . V_147 < V_589 ||
V_218 -> V_753 . V_147 > V_590 )
return - V_31 ;
V_147 = V_218 -> V_753 . V_147 ;
}
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) ) {
V_63 = - V_70 ;
goto V_622;
}
V_63 = F_245 ( V_6 , V_147 ) ;
F_324 ( L_291 , V_147 ) ;
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_344 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_753 . V_774 = ( V_6 -> V_49 & V_486 ) ? 1 : 0 ;
if ( V_6 -> V_587 == V_588 ) {
V_218 -> V_753 . V_772 = 0 ;
V_218 -> V_753 . V_147 = V_590 ;
} else {
V_218 -> V_753 . V_772 = 1 ;
V_218 -> V_753 . V_147 = V_6 -> V_587 ;
}
V_218 -> V_753 . V_62 = V_750 ;
F_324 ( L_292 , V_218 -> V_753 . V_147 ) ;
return 0 ;
}
static int F_345 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_218 -> V_777 . V_772 )
return - V_31 ;
if ( V_218 -> V_777 . V_774 ) {
V_6 -> V_683 |= V_685 ;
V_6 -> V_150 -> V_778 = V_684 ;
} else {
if ( V_218 -> V_777 . V_147 < V_730 ||
V_218 -> V_777 . V_147 > V_732 )
return - V_31 ;
V_6 -> V_150 -> V_778 = V_218 -> V_777 . V_147 & ~ 0x1 ;
V_6 -> V_683 = V_6 -> V_150 -> V_778 ;
}
F_324 ( L_293 , V_6 -> V_150 -> V_778 ) ;
return 0 ;
}
static int F_346 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_777 . V_147 = V_6 -> V_683 & ~ V_685 ;
V_218 -> V_777 . V_772 = 0 ;
V_218 -> V_777 . V_774 = ( V_6 -> V_683 & V_685 ) ? 1 : 0 ;
F_324 ( L_294 , V_218 -> V_777 . V_147 ) ;
return 0 ;
}
static int F_347 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
if ( V_218 -> V_558 . V_62 & V_779 || V_218 -> V_558 . V_774 )
return - V_31 ;
if ( ! ( V_218 -> V_558 . V_62 & V_780 ) )
return 0 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) ) {
V_63 = - V_70 ;
goto V_622;
}
if ( V_218 -> V_558 . V_62 & V_781 ) {
V_63 = F_239 ( V_6 , V_218 -> V_558 . V_147 ) ;
F_324 ( L_295 ,
V_218 -> V_558 . V_147 ) ;
goto V_622;
}
if ( V_218 -> V_558 . V_62 & V_782 ) {
V_63 = F_240 ( V_6 , V_218 -> V_558 . V_147 ) ;
F_324 ( L_296 ,
V_218 -> V_558 . V_147 ) ;
goto V_622;
}
V_63 = F_239 ( V_6 , V_218 -> V_558 . V_147 ) ;
if ( ! V_63 )
V_63 = F_240 ( V_6 , V_218 -> V_558 . V_147 ) ;
F_324 ( L_297 , V_218 -> V_558 . V_147 ) ;
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_348 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_558 . V_774 = 0 ;
if ( ( V_218 -> V_558 . V_62 & V_783 ) == V_779 )
return - V_31 ;
if ( V_218 -> V_558 . V_62 & V_782 ) {
V_218 -> V_558 . V_62 = V_780 | V_782 ;
V_218 -> V_558 . V_147 = V_6 -> V_562 ;
} else {
V_218 -> V_558 . V_62 =
( V_6 -> V_560 !=
V_6 -> V_562 ) ?
V_780 | V_781 : V_780 ;
V_218 -> V_558 . V_147 = V_6 -> V_560 ;
}
F_324 ( L_298 , V_218 -> V_558 . V_147 ) ;
return 0 ;
}
static int F_349 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) ) {
V_63 = - V_70 ;
goto V_622;
}
F_324 ( L_299 ) ;
V_6 -> V_299 = 1 ;
if ( F_90 ( V_6 ) || F_92 ( V_6 ) ) {
F_324 ( L_300 ) ;
}
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_350 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_351 ( V_6 -> V_150 , V_81 , V_218 , V_707 ) ;
}
static int F_352 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_595 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_353 ( V_6 -> V_150 , V_81 , V_218 , V_595 ) ;
}
static int F_354 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_595 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_355 ( V_6 -> V_150 , V_81 , V_218 , V_595 ) ;
}
static int F_356 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) ) {
V_63 = - V_70 ;
goto V_622;
}
if ( V_218 -> V_784 . V_774 ) {
V_6 -> V_547 = F_236 ( V_6 -> V_547 ) ;
V_63 = F_235 ( V_6 , V_546 ) ;
F_324 ( L_301 ) ;
goto V_622;
}
switch ( V_218 -> V_784 . V_62 & V_785 ) {
case V_786 :
case V_785 :
case V_787 :
break;
default:
F_324 ( L_302 ,
V_218 -> V_784 . V_62 ) ;
V_63 = - V_641 ;
goto V_622;
}
V_6 -> V_547 = V_548 | V_6 -> V_547 ;
V_63 = F_235 ( V_6 , F_236 ( V_6 -> V_547 ) ) ;
F_324 ( L_303 , V_6 -> V_547 ) ;
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_357 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_547 & V_548 ) )
V_218 -> V_784 . V_774 = 1 ;
else {
V_218 -> V_784 . V_774 = 0 ;
V_218 -> V_784 . V_62 = 0 ;
}
F_324 ( L_304 , V_6 -> V_547 ) ;
return 0 ;
}
static int F_358 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_634 * V_150 = V_6 -> V_150 ;
T_3 * V_15 ;
if ( ! V_150 -> V_633 )
return - V_641 ;
if ( V_218 -> V_37 . V_286 > V_788 ||
( V_218 -> V_37 . V_286 && V_707 == NULL ) )
return - V_31 ;
if ( V_218 -> V_37 . V_286 ) {
V_15 = F_359 ( V_707 , V_218 -> V_37 . V_286 , V_239 ) ;
if ( V_15 == NULL )
return - V_240 ;
F_129 ( V_150 -> V_642 ) ;
V_150 -> V_642 = V_15 ;
V_150 -> V_643 = V_218 -> V_37 . V_286 ;
} else {
F_129 ( V_150 -> V_642 ) ;
V_150 -> V_642 = NULL ;
V_150 -> V_643 = 0 ;
}
V_565 ( V_6 , V_150 -> V_642 , V_150 -> V_643 ) ;
return 0 ;
}
static int F_360 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_634 * V_150 = V_6 -> V_150 ;
if ( V_150 -> V_643 == 0 || V_150 -> V_642 == NULL ) {
V_218 -> V_37 . V_286 = 0 ;
return 0 ;
}
if ( V_218 -> V_37 . V_286 < V_150 -> V_643 )
return - V_770 ;
V_218 -> V_37 . V_286 = V_150 -> V_643 ;
memcpy ( V_707 , V_150 -> V_642 , V_150 -> V_643 ) ;
return 0 ;
}
static int F_361 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_634 * V_150 = V_6 -> V_150 ;
struct V_789 * V_790 = & V_218 -> V_790 ;
struct V_791 * V_493 ;
unsigned long V_62 ;
int V_266 = 0 ;
switch ( V_790 -> V_62 & V_792 ) {
case V_793 :
case V_794 :
case V_795 :
case V_796 :
break;
case V_797 :
V_493 = V_6 -> V_150 -> V_492 . V_493 [ V_6 -> V_150 -> V_492 . V_494 ] ;
if ( ! V_493 || ! V_493 -> V_798 -> V_799 || ! V_493 -> V_798 -> V_800 )
break;
V_62 = V_493 -> V_798 -> V_800 ( V_493 -> V_6 ) ;
if ( V_790 -> V_147 )
V_62 |= V_801 ;
else
V_62 &= ~ V_801 ;
V_493 -> V_798 -> V_799 ( V_62 , V_493 -> V_6 ) ;
break;
case V_802 : {
struct V_619 V_190 = {
. V_62 = V_191 ,
. V_192 = V_790 -> V_147 ,
} ;
V_6 -> V_150 -> V_673 = V_790 -> V_147 ;
if ( ! V_790 -> V_147 ) {
V_190 . V_62 |= V_612 ;
V_190 . V_43 = V_574 ;
} else {
V_190 . V_62 |= V_612 ;
V_190 . V_43 = V_577 ;
}
if ( V_6 -> V_150 -> V_640 )
V_6 -> V_150 -> V_640 ( V_6 -> V_150 -> V_2 , & V_190 ) ;
break;
}
case V_803 :
V_266 = F_266 ( V_6 , V_790 -> V_147 ) ;
break;
case V_804 :
V_266 = F_265 ( V_6 , V_790 -> V_147 ) ;
break;
case V_805 :
V_150 -> V_675 = V_790 -> V_147 ;
break;
case V_806 :
V_150 -> V_674 = V_790 -> V_147 ;
break;
default:
return - V_641 ;
}
return V_266 ;
}
static int F_362 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_634 * V_150 = V_6 -> V_150 ;
struct V_791 * V_493 ;
struct V_789 * V_790 = & V_218 -> V_790 ;
int V_266 = 0 ;
switch ( V_790 -> V_62 & V_792 ) {
case V_793 :
case V_794 :
case V_795 :
case V_796 :
V_266 = - V_641 ;
break;
case V_797 :
V_493 = V_6 -> V_150 -> V_492 . V_493 [ V_6 -> V_150 -> V_492 . V_494 ] ;
if ( ! V_493 || ! V_493 -> V_798 -> V_800 ) {
F_152 ( L_305
L_306 ) ;
break;
}
V_790 -> V_147 = ( V_493 -> V_798 -> V_800 ( V_493 -> V_6 ) &
V_801 ) ? 1 : 0 ;
break;
case V_802 :
V_790 -> V_147 = V_150 -> V_673 ;
break;
case V_803 :
V_790 -> V_147 = V_6 -> V_150 -> V_190 . V_568 ;
break;
case V_804 :
V_790 -> V_147 = V_150 -> V_633 ;
break;
case V_805 :
V_790 -> V_147 = V_150 -> V_675 ;
break;
case V_807 :
case V_806 :
V_790 -> V_147 = V_150 -> V_674 ;
break;
default:
return - V_641 ;
}
return 0 ;
}
static int F_363 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_364 ( V_6 -> V_150 , V_81 , V_218 , V_707 ) ;
}
static int F_365 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_366 ( V_6 -> V_150 , V_81 , V_218 , V_707 ) ;
}
static int F_367 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_808 * V_809 = (struct V_808 * ) V_707 ;
T_16 V_810 ;
V_810 = F_150 ( V_809 -> V_811 ) ;
switch ( V_809 -> V_57 ) {
case V_812 :
break;
case V_813 :
F_242 ( V_6 ) ;
break;
default:
return - V_641 ;
}
return 0 ;
}
static int F_368 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int * V_814 = ( int * ) V_707 ;
int V_815 = ( V_814 [ 0 ] > 0 ) ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) ) {
V_63 = - V_70 ;
goto V_622;
}
if ( V_815 ) {
if ( V_6 -> V_150 -> V_198 == V_199 ) {
V_63 = F_231 ( V_6 , V_814 [ 1 ] , 0 ) ;
goto V_622;
}
V_6 -> V_245 = V_814 [ 1 ] ;
V_63 = F_195 ( V_6 , V_199 ) ;
} else {
if ( V_6 -> V_150 -> V_198 == V_199 )
V_63 = F_195 ( V_6 , V_6 -> V_490 ) ;
}
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_369 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_49 & V_621 )
F_35 ( V_6 ) ;
return 0 ;
}
static int F_370 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 , V_314 = * ( int * ) V_707 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) ) {
V_63 = - V_70 ;
goto V_622;
}
if ( ( V_314 < 0 ) || ( V_314 > V_736 ) )
V_314 = V_672 ;
if ( F_236 ( V_6 -> V_547 ) != V_314 )
V_63 = F_235 ( V_6 , V_314 ) ;
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_371 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_43 = F_236 ( V_6 -> V_547 ) ;
T_17 V_816 , V_817 ;
if ( ! ( V_6 -> V_547 & V_548 ) ) {
snprintf ( V_707 , V_818 ,
L_307 , V_43 ) ;
} else {
switch ( V_43 ) {
case V_546 :
snprintf ( V_707 , V_818 ,
L_308 , V_43 ) ;
break;
case V_672 :
snprintf ( V_707 , V_818 ,
L_309 , V_43 ) ;
break;
default:
V_816 = V_738 [ V_43 - 1 ] / 1000 ;
V_817 = V_734 [ V_43 - 1 ] / 1000 ;
snprintf ( V_707 , V_818 ,
L_310
L_311 ,
V_43 , V_816 , V_817 ) ;
}
}
V_218 -> V_37 . V_286 = strlen ( V_707 ) + 1 ;
return 0 ;
}
static int F_372 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 , V_314 = * ( int * ) V_707 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) ) {
V_63 = - V_70 ;
goto V_622;
}
if ( V_314 == 1 )
V_6 -> V_187 |= V_530 ;
else if ( V_314 == 0 )
V_6 -> V_187 &= ~ V_530 ;
else {
V_63 = - V_31 ;
goto V_622;
}
V_63 = F_232 ( V_6 , 0 ) ;
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_373 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_530 )
snprintf ( V_218 -> V_51 , V_708 , L_312 ) ;
else
snprintf ( V_218 -> V_51 , V_708 , L_313 ) ;
return 0 ;
}
static int F_374 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 , V_314 = * ( int * ) V_707 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_621 ) ) {
V_63 = - V_70 ;
goto V_622;
}
if ( V_314 == 1 )
V_6 -> V_187 |= V_345 ;
else if ( V_314 == 0 )
V_6 -> V_187 &= ~ V_345 ;
else {
V_63 = - V_31 ;
goto V_622;
}
V_63 = 0 ;
V_622:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_375 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_217 * V_218 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_345 )
snprintf ( V_218 -> V_51 , V_708 , L_314 ) ;
else
snprintf ( V_218 -> V_51 , V_708 , L_315 ) ;
return 0 ;
}
static struct V_819 * F_376 ( struct V_1 * V_2 )
{
enum {
V_820 = 30 ,
V_821 = 60 ,
V_822 = 80 ,
V_823 = 90 ,
V_824 = 95 ,
V_825 = 100
};
int V_826 ;
int V_827 ;
int V_828 ;
int V_829 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_819 * V_303 ;
T_1 V_353 , V_830 , V_831 , V_832 ;
T_1 V_204 = sizeof( T_1 ) ;
if ( ! V_6 )
return (struct V_819 * ) NULL ;
V_303 = & V_6 -> V_303 ;
if ( ! ( V_6 -> V_49 & V_166 ) ) {
V_303 -> V_833 . V_834 = 0 ;
V_303 -> V_333 . V_835 = 0 ;
V_303 -> V_719 . V_719 = 0 ;
V_303 -> V_719 . V_43 = 0 ;
V_303 -> V_719 . V_720 = 0 ;
V_303 -> V_719 . V_721 = 7 ;
V_303 -> V_719 . V_721 |= V_836 |
V_837 | V_838 ;
return V_303 ;
}
if ( F_26 ( V_6 , V_839 ,
& V_831 , & V_204 ) )
goto V_840;
if ( ! ( V_6 -> V_49 & V_166 ) ) {
V_303 -> V_719 . V_719 = 0 ;
V_303 -> V_719 . V_43 = 0 ;
} else {
if ( F_26 ( V_6 , V_841 ,
& V_353 , & V_204 ) )
goto V_840;
V_303 -> V_719 . V_43 = V_353 + V_354 ;
if ( V_353 < 10 )
V_826 = V_353 * V_820 / 10 ;
else if ( V_353 < 15 )
V_826 = ( V_353 - 10 ) * ( V_821 - V_820 ) / 5 + V_820 ;
else if ( V_353 < 20 )
V_826 = ( V_353 - 15 ) * ( V_822 - V_821 ) / 5 + V_821 ;
else if ( V_353 < 30 )
V_826 = ( V_353 - 20 ) * ( V_823 - V_822 ) /
10 + V_822 ;
else
V_826 = ( V_353 - 30 ) * ( V_825 - V_823 ) /
10 + V_823 ;
if ( F_26 ( V_6 , V_842 ,
& V_830 , & V_204 ) )
goto V_840;
if ( V_830 > 75 )
V_827 = ( 90 - V_830 ) * V_820 / 15 ;
else if ( V_830 > 70 )
V_827 = ( 75 - V_830 ) * ( V_821 - V_820 ) / 5 + V_820 ;
else if ( V_830 > 65 )
V_827 = ( 70 - V_830 ) * ( V_822 - V_821 ) / 5 + V_821 ;
else if ( V_830 > 50 )
V_827 = ( 65 - V_830 ) * ( V_823 - V_822 ) /
15 + V_822 ;
else
V_827 = ( 50 - V_830 ) *
( V_825 - V_823 ) / 50 + V_823 ;
if ( V_831 > 50 )
V_828 = ( 60 - V_831 ) * V_820 / 10 ;
else if ( V_831 > 40 )
V_828 = ( 50 - V_831 ) * ( V_821 - V_820 ) /
10 + V_820 ;
else if ( V_831 > 32 )
V_828 = ( 40 - V_831 ) * ( V_822 - V_821 ) /
18 + V_821 ;
else if ( V_831 > 20 )
V_828 = ( 32 - V_831 ) *
( V_823 - V_822 ) / 20 + V_822 ;
else
V_828 = ( 20 - V_831 ) *
( V_825 - V_823 ) / 20 + V_823 ;
V_829 = F_34 ( V_827 , V_826 ) ;
V_829 = F_34 ( V_828 , V_829 ) ;
#ifdef F_124
if ( V_828 == V_829 )
F_324 ( L_316 ) ;
else if ( V_827 == V_829 )
F_324 ( L_317 ) ;
else if ( V_829 != 100 )
F_324 ( L_318 ) ;
else
F_324 ( L_319 ) ;
#endif
V_303 -> V_719 . V_719 = V_829 ;
V_303 -> V_719 . V_43 = V_353 + V_354 ;
}
V_303 -> V_719 . V_720 = 0 ;
V_303 -> V_719 . V_721 = 7 ;
V_303 -> V_719 . V_721 |= V_836 ;
V_303 -> V_833 . V_834 = V_831 ;
if ( F_26 ( V_6 , V_843 ,
& V_832 , & V_204 ) )
goto V_840;
V_303 -> V_333 . V_835 = V_832 ;
return V_303 ;
V_840:
F_324 ( L_287 ) ;
return (struct V_819 * ) NULL ;
}
static void V_688 ( struct V_261 * V_262 )
{
struct V_5 * V_6 =
F_108 ( V_262 , struct V_5 , V_285 . V_262 ) ;
union V_217 V_218 ;
unsigned int V_14 = V_230 ;
if ( V_6 -> V_49 & V_184 )
return;
F_84 ( & V_6 -> V_265 ) ;
F_324 ( L_42 ) ;
F_85 ( & V_6 -> V_265 ) ;
V_218 . V_219 . V_220 = V_221 ;
if ( ! ( V_6 -> V_49 & ( V_165 | V_166 ) ) ||
V_6 -> V_49 & V_486 ||
F_26 ( V_6 , V_278 ,
& V_6 -> V_273 , & V_14 ) ) {
memset ( V_218 . V_219 . V_630 , 0 , V_230 ) ;
} else {
memcpy ( V_218 . V_219 . V_630 , V_6 -> V_273 , V_230 ) ;
memcpy ( V_6 -> V_150 -> V_273 , V_6 -> V_273 , V_230 ) ;
V_6 -> V_49 &= ~ V_165 ;
V_6 -> V_49 |= V_166 ;
F_261 ( V_6 -> V_33 ) ;
F_163 ( V_6 -> V_33 ) ;
}
if ( ! ( V_6 -> V_49 & V_166 ) ) {
F_324 ( L_320 ) ;
F_84 ( & V_6 -> V_265 ) ;
if ( V_6 -> V_187 & V_283 )
F_113 ( V_6 , V_6 -> V_268 , V_6 -> V_267 ,
0 ) ;
else
F_113 ( V_6 , NULL , 0 , 0 ) ;
F_85 ( & V_6 -> V_265 ) ;
}
F_100 ( V_6 -> V_33 , V_224 , & V_218 , NULL ) ;
}
static int F_377 ( struct V_119 * V_844 )
{
struct V_845 * V_846 =
(struct V_845 * ) V_844 -> V_847 -> V_37 ;
if ( F_378 ( V_846 -> V_121 ) != V_848 ) {
F_27 (KERN_WARNING DRV_NAME L_321
L_322
L_323 ,
h->version) ;
return 1 ;
}
V_844 -> V_121 = V_846 -> V_121 ;
V_844 -> V_844 . V_37 = V_844 -> V_847 -> V_37 + sizeof( struct V_845 ) ;
V_844 -> V_844 . V_480 = V_846 -> V_849 ;
V_844 -> V_850 . V_37 = V_844 -> V_844 . V_37 + V_846 -> V_849 ;
V_844 -> V_850 . V_480 = V_846 -> V_851 ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 ,
struct V_119 * V_844 )
{
char * V_852 ;
int V_202 ;
F_31 ( L_324 ,
V_6 -> V_33 -> V_51 ) ;
switch ( V_6 -> V_150 -> V_198 ) {
case V_433 :
V_852 = F_379 ( L_325 ) ;
break;
#ifdef F_154
case V_199 :
V_852 = F_379 ( L_326 ) ;
break;
#endif
case V_428 :
default:
V_852 = F_379 ( L_50 ) ;
break;
}
V_202 = F_380 ( & V_844 -> V_847 , V_852 , & V_6 -> V_260 -> V_2 ) ;
if ( V_202 < 0 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_327 ,
priv->net_dev->name, fw_name) ;
return V_202 ;
}
F_31 ( L_328 , V_844 -> V_847 -> V_37 ,
V_844 -> V_847 -> V_480 ) ;
F_377 ( V_844 ) ;
return 0 ;
}
static void F_66 ( struct V_5 * V_6 ,
struct V_119 * V_844 )
{
V_844 -> V_121 = 0 ;
F_381 ( V_844 -> V_847 ) ;
V_844 -> V_847 = NULL ;
}
static int F_269 ( struct V_5 * V_6 , char * V_15 ,
T_4 V_853 )
{
char V_854 [ V_855 ] ;
T_1 V_14 = V_855 ;
T_1 V_315 ;
int V_19 ;
if ( F_26 ( V_6 , V_856 , V_854 , & V_14 ) )
return - V_70 ;
V_315 = V_853 ;
if ( V_14 >= V_853 )
V_14 = V_853 - 1 ;
for ( V_19 = 0 ; V_19 < V_14 ; V_19 ++ )
V_15 [ V_19 ] = V_854 [ V_19 ] ;
V_15 [ V_19 ] = '\0' ;
return V_315 ;
}
static int F_270 ( struct V_5 * V_6 , char * V_15 ,
T_4 V_853 )
{
T_1 V_854 ;
T_1 V_14 = sizeof( V_854 ) ;
if ( F_26 ( V_6 , V_857 , & V_854 , & V_14 ) )
return - V_70 ;
return snprintf ( V_15 , V_853 , L_14 , V_854 ) ;
}
static int F_65 ( struct V_5 * V_6 , struct V_119 * V_844 )
{
unsigned int V_8 ;
unsigned short V_14 ;
const unsigned char * V_858 = V_844 -> V_844 . V_37 ;
unsigned int V_859 = V_844 -> V_844 . V_480 ;
while ( V_859 > 0 ) {
V_8 = * ( T_1 * ) ( V_858 ) ;
V_858 += 4 ;
V_859 -= 4 ;
V_14 = * ( T_2 * ) ( V_858 ) ;
V_858 += 2 ;
V_859 -= 2 ;
if ( V_14 > 32 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_329 ,
len) ;
return - V_31 ;
}
F_23 ( V_6 -> V_33 , V_8 , V_14 , V_858 ) ;
V_858 += V_14 ;
V_859 -= V_14 ;
}
return 0 ;
}
static int F_64 ( struct V_5 * V_6 ,
struct V_119 * V_844 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
const unsigned char * V_860 = V_844 -> V_850 . V_37 ;
unsigned int V_861 = V_844 -> V_850 . V_480 ;
void T_12 * V_3 = V_6 -> V_7 ;
struct V_862 V_863 ;
int V_19 , V_40 ;
T_3 V_37 ;
F_18 ( V_2 , V_174 , 0x703 ) ;
F_382 ( V_3 ) ;
F_18 ( V_2 , V_174 , 0x707 ) ;
F_382 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_382 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_382 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x40 ) ;
F_382 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x0 ) ;
F_382 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x40 ) ;
F_382 ( V_3 ) ;
while ( V_861 > 0 ) {
F_20 ( V_2 , 0x210010 , * V_860 ++ ) ;
F_20 ( V_2 , 0x210010 , * V_860 ++ ) ;
V_861 -= 2 ;
}
F_20 ( V_2 , 0x210000 , 0x0 ) ;
F_382 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x0 ) ;
F_382 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x80 ) ;
F_382 ( V_3 ) ;
F_18 ( V_2 , V_174 , 0x703 ) ;
F_382 ( V_3 ) ;
F_18 ( V_2 , V_174 , 0x707 ) ;
F_382 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_382 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_382 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x00 ) ;
F_382 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x80 ) ;
for ( V_19 = 0 ; V_19 < 10 ; V_19 ++ ) {
F_58 ( 10 ) ;
F_19 ( V_2 , 0x210000 , & V_37 ) ;
if ( V_37 & 0x1 )
break;
}
if ( V_19 == 10 ) {
F_27 (KERN_ERR DRV_NAME L_330 ,
dev->name) ;
return - V_70 ;
}
for ( V_19 = 0 ; V_19 < 30 ; V_19 ++ ) {
for ( V_40 = 0 ;
V_40 < ( sizeof( struct V_862 ) >> 1 ) ; V_40 ++ )
F_17 ( V_2 , 0x210004 , ( ( T_2 * ) & V_863 ) + V_40 ) ;
if ( ( V_863 . V_864 == 1 ) && ( V_863 . V_865 == 0x1 ) )
break;
F_58 ( 10 ) ;
}
if ( V_19 == 30 ) {
F_27 (KERN_ERR DRV_NAME
L_331 ,
dev->name) ;
F_33 ( V_866 , ( T_3 * ) & V_863 , sizeof( V_863 ) ) ;
return - V_70 ;
}
return 0 ;
}
