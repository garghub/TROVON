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
if ( F_96 ( V_6 -> V_150 , & V_209 [ 0 ] ) ) {
F_27 (KERN_WARNING DRV_NAME L_84 ) ;
return 0 ;
}
V_6 -> V_150 -> V_210 = V_211 ;
V_203 = V_212 ;
if ( F_30 ( V_6 , V_213 , & V_203 , & V_204 ) ) {
F_27 (KERN_ERR DRV_NAME
L_85 ,
priv->net_dev->name) ;
V_202 = 1 ;
goto exit;
}
V_6 -> V_49 &= ~ V_200 ;
if ( F_71 ( V_6 ) ) {
F_27 ( V_214 L_86 ,
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
F_27 (KERN_ERR DRV_NAME L_87 ,
priv->net_dev->name) ;
V_202 = 1 ;
goto exit;
}
if ( ! V_201 ) {
if ( F_83 ( V_6 ) ) {
F_27 (KERN_ERR DRV_NAME L_67
L_88 ,
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
F_27 (KERN_ERR DRV_NAME L_89 ,
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
V_250 ;
if ( V_226 -> V_242 [ V_19 ] . V_62 & V_251 )
V_233 -> V_237 [ V_19 ] . V_62 |=
V_252 ;
}
V_233 -> V_253 = V_254 ;
V_233 -> V_255 = V_256 ;
V_151 -> V_152 -> V_257 [ V_235 ] = V_233 ;
}
V_151 -> V_152 -> V_258 = V_259 ;
V_151 -> V_152 -> V_260 = F_104 ( V_259 ) ;
F_105 ( V_151 -> V_152 , & V_6 -> V_261 -> V_2 ) ;
if ( F_106 ( V_151 -> V_152 ) )
return - V_70 ;
return 0 ;
}
static void F_107 ( struct V_262 * V_263 )
{
struct V_5 * V_6 =
F_108 ( V_263 , struct V_5 , V_52 . V_263 ) ;
unsigned long V_62 ;
union V_217 V_218 = {
. V_219 = {
. V_220 = V_221 }
} ;
int V_222 = V_6 -> V_49 & V_166 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
F_31 ( L_90 , V_6 -> V_33 -> V_51 ) ;
V_6 -> V_264 ++ ;
V_6 -> V_49 &= ~ ( V_166 | V_165 ) ;
V_6 -> V_49 |= V_265 ;
F_89 ( & V_6 -> V_52 ) ;
V_6 -> V_49 |= V_50 ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
F_84 ( & V_6 -> V_266 ) ;
V_6 -> V_181 = 1 ;
F_89 ( & V_6 -> V_182 ) ;
if ( V_222 )
F_100 ( V_6 -> V_33 , V_224 , & V_218 , NULL ) ;
F_93 ( V_6 , 0 ) ;
F_85 ( & V_6 -> V_266 ) ;
}
static void F_109 ( struct V_5 * V_6 , T_1 V_49 )
{
#define F_110 (HZ)
int V_267 ;
unsigned int V_14 , V_268 ;
char V_269 [ V_270 ] ;
T_1 V_271 ;
T_1 V_272 ;
char * V_273 ;
T_3 V_274 [ V_230 ] ;
F_111 ( V_275 ) ;
V_268 = V_270 ;
V_267 = F_26 ( V_6 , V_276 ,
V_269 , & V_268 ) ;
if ( V_267 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
V_14 = sizeof( T_1 ) ;
V_267 = F_26 ( V_6 , V_277 , & V_271 , & V_14 ) ;
if ( V_267 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
V_14 = sizeof( T_1 ) ;
V_267 = F_26 ( V_6 , V_278 , & V_272 , & V_14 ) ;
if ( V_267 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
V_14 = V_230 ;
V_267 = F_26 ( V_6 , V_279 , V_274 ,
& V_14 ) ;
if ( V_267 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
memcpy ( V_6 -> V_150 -> V_274 , V_274 , V_230 ) ;
switch ( V_271 ) {
case V_280 :
V_273 = L_91 ;
break;
case V_281 :
V_273 = L_92 ;
break;
case V_282 :
V_273 = L_93 ;
break;
case V_283 :
V_273 = L_94 ;
break;
default:
F_31 ( L_95 , V_271 ) ;
V_273 = L_96 ;
break;
}
F_31 ( L_97 ,
V_6 -> V_33 -> V_51 , F_112 ( V_275 , V_269 , V_268 ) ,
V_273 , V_272 , V_274 ) ;
if ( ! ( V_6 -> V_187 & V_284 ) ) {
V_6 -> V_268 = F_34 ( ( T_3 ) V_268 , ( T_3 ) V_270 ) ;
memcpy ( V_6 -> V_269 , V_269 , V_6 -> V_268 ) ;
}
V_6 -> V_245 = V_272 ;
memcpy ( V_6 -> V_274 , V_274 , V_230 ) ;
V_6 -> V_49 |= V_165 ;
V_6 -> V_285 = F_36 () ;
F_39 ( & V_6 -> V_286 , V_53 / 10 ) ;
}
static int F_113 ( struct V_5 * V_6 , char * V_269 ,
int V_287 , int V_288 )
{
int V_289 = F_34 ( V_287 , V_270 ) ;
struct V_56 V_57 = {
. V_56 = V_290 ,
. V_88 = 0 ,
. V_65 = V_289
} ;
int V_63 ;
F_111 ( V_275 ) ;
F_42 ( L_98 , F_112 ( V_275 , V_269 , V_289 ) ) ;
if ( V_289 )
memcpy ( V_57 . V_67 , V_269 , V_289 ) ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
if ( ! V_289 && ! ( V_6 -> V_187 & V_188 ) ) {
int V_19 ;
T_3 * V_291 = ( T_3 * ) V_57 . V_67 ;
for ( V_19 = 0 ; V_19 < V_270 ; V_19 ++ )
V_291 [ V_19 ] = 0x18 + V_19 ;
V_57 . V_65 = V_270 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_63 ) {
memset ( V_6 -> V_269 + V_289 , 0 , V_270 - V_289 ) ;
memcpy ( V_6 -> V_269 , V_269 , V_289 ) ;
V_6 -> V_268 = V_289 ;
}
if ( ! V_288 ) {
if ( F_83 ( V_6 ) )
V_63 = - V_70 ;
}
return V_63 ;
}
static void F_114 ( struct V_5 * V_6 , T_1 V_49 )
{
F_111 ( V_275 ) ;
F_115 ( V_292 | V_293 | V_294 ,
L_99 ,
F_112 ( V_275 , V_6 -> V_269 , V_6 -> V_268 ) ,
V_6 -> V_274 ) ;
V_6 -> V_49 &= ~ ( V_166 | V_165 ) ;
if ( V_6 -> V_49 & V_184 ) {
F_31 ( L_100 ) ;
return;
}
memset ( V_6 -> V_274 , 0 , V_230 ) ;
memset ( V_6 -> V_150 -> V_274 , 0 , V_230 ) ;
F_37 ( V_6 -> V_33 ) ;
F_38 ( V_6 -> V_33 ) ;
if ( ! ( V_6 -> V_49 & V_72 ) )
return;
if ( V_6 -> V_49 & V_265 )
F_39 ( & V_6 -> V_295 , 0 ) ;
F_39 ( & V_6 -> V_286 , 0 ) ;
}
static void F_116 ( struct V_5 * V_6 , T_1 V_49 )
{
F_31 ( L_101 ,
V_6 -> V_33 -> V_51 ) ;
F_74 ( V_6 -> V_150 -> V_151 . V_152 , true ) ;
V_6 -> V_49 |= V_153 ;
V_6 -> V_215 = 0 ;
F_89 ( & V_6 -> V_216 ) ;
F_39 ( & V_6 -> V_216 , F_97 ( V_53 ) ) ;
}
static void F_117 ( void * V_37 )
{
struct V_5 * V_6 = V_37 ;
union V_217 V_218 ;
V_218 . V_37 . V_287 = 0 ;
V_218 . V_37 . V_62 = 0 ;
F_100 ( V_6 -> V_33 , V_296 , & V_218 , NULL ) ;
}
static void F_118 ( struct V_262 * V_263 )
{
F_117 ( F_108 ( V_263 , struct V_5 ,
V_297 . V_263 ) ) ;
}
static void F_119 ( struct V_262 * V_263 )
{
F_117 ( F_108 ( V_263 , struct V_5 ,
V_298 ) ) ;
}
static void F_120 ( struct V_5 * V_6 , T_1 V_49 )
{
F_91 ( L_102 ) ;
V_6 -> V_150 -> V_299 ++ ;
V_6 -> V_49 &= ~ V_200 ;
if ( ! V_6 -> V_300 ) {
if ( ! F_121 ( & V_6 -> V_297 ) )
F_39 ( & V_6 -> V_297 ,
F_97 ( F_55 ( 4000 ) ) ) ;
} else {
V_6 -> V_300 = 0 ;
F_89 ( & V_6 -> V_297 ) ;
F_122 ( & V_6 -> V_298 ) ;
}
}
static void F_123 ( struct V_5 * V_6 , T_1 V_49 )
{
F_91 ( L_103 ) ;
V_6 -> V_49 |= V_200 ;
}
static void F_124 ( struct V_5 * V_6 , int V_49 )
{
int V_19 ;
if ( V_49 == V_301 &&
V_6 -> V_49 & V_166 &&
! ( V_6 -> V_49 & V_200 ) ) {
F_31 ( L_104
L_105 ) ;
F_35 ( V_6 ) ;
}
for ( V_19 = 0 ; V_302 [ V_19 ] . V_49 != - 1 ; V_19 ++ ) {
if ( V_49 == V_302 [ V_19 ] . V_49 ) {
F_125 ( L_106 ,
V_302 [ V_19 ] . V_51 ) ;
if ( V_302 [ V_19 ] . V_303 )
V_302 [ V_19 ] . V_303 ( V_6 , V_49 ) ;
V_6 -> V_304 . V_49 = V_49 ;
return;
}
}
F_125 ( L_107 , V_49 ) ;
}
static void F_126 ( struct V_5 * V_6 ,
struct V_305 * V_57 )
{
#ifdef F_127
if ( V_57 -> V_83 < F_104 ( V_64 ) ) {
F_42 ( L_108 ,
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
static int F_128 ( struct V_5 * V_6 ,
struct V_306 * V_61 )
{
V_61 -> V_307 = F_129 ( sizeof( struct V_308 ) ) ;
if ( ! V_61 -> V_307 )
return - V_240 ;
V_61 -> V_309 = (struct V_308 * ) V_61 -> V_307 -> V_37 ;
V_61 -> V_310 = F_130 ( V_6 -> V_261 , V_61 -> V_307 -> V_37 ,
sizeof( struct V_308 ) ,
V_311 ) ;
return 0 ;
}
static void F_131 ( struct V_5 * V_6 )
{
int V_19 ;
if ( ! V_6 -> V_312 [ 0 ] )
return;
for ( V_19 = 0 ; V_19 < 0x30 ; V_19 ++ )
F_132 ( V_6 -> V_312 [ V_19 ] ) ;
V_6 -> V_312 [ 0 ] = NULL ;
}
static int F_133 ( struct V_5 * V_6 )
{
int V_19 ;
if ( V_6 -> V_312 [ 0 ] )
return 1 ;
for ( V_19 = 0 ; V_19 < 0x30 ; V_19 ++ ) {
V_6 -> V_312 [ V_19 ] = F_134 ( 0x1000 , V_313 ) ;
if ( ! V_6 -> V_312 [ V_19 ] ) {
F_31 ( L_109
L_110 , V_6 -> V_33 -> V_51 , V_19 ) ;
while ( V_19 > 0 )
F_132 ( V_6 -> V_312 [ -- V_19 ] ) ;
V_6 -> V_312 [ 0 ] = NULL ;
return 0 ;
}
}
return 1 ;
}
static T_1 F_135 ( struct V_5 * V_6 , T_3 * V_314 ,
T_4 V_14 , int V_315 )
{
T_1 V_19 , V_40 ;
T_1 V_316 ;
T_3 * V_317 , * V_318 ;
T_1 V_267 ;
V_317 = V_314 ;
if ( V_315 == V_319 ) {
if ( ! F_133 ( V_6 ) )
V_315 = V_320 ;
}
for ( V_267 = V_321 , V_19 = 0 ; V_19 < 0x30000 ; V_19 += 4 ) {
F_15 ( V_6 -> V_33 , V_19 , & V_316 ) ;
if ( V_315 == V_319 )
* ( T_1 * ) F_136 ( V_19 ) = V_316 ;
if ( V_267 == V_321 ) {
V_318 = ( T_3 * ) & V_316 ;
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
if ( * V_317 != * V_318 ) {
V_317 = V_314 ;
continue;
}
V_317 ++ ;
V_318 ++ ;
if ( ( V_317 - V_314 ) == V_14 )
V_267 = ( V_19 + V_40 ) - V_14 + 1 ;
}
} else if ( V_315 == V_320 )
return V_267 ;
}
return V_267 ;
}
static void F_137 ( struct V_5 * V_6 , int V_19 )
{
#ifdef F_138
struct V_322 * V_49 = & V_6 -> V_323 . V_324 [ V_19 ] ;
T_1 V_325 , V_3 ;
int V_40 ;
#endif
F_31 ( L_111 ,
V_19 * sizeof( struct V_322 ) ) ;
#ifdef F_138
F_5 ( V_6 -> V_33 , V_110 ,
V_170 ) ;
V_40 = 5 ;
do {
F_58 ( V_171 ) ;
F_1 ( V_6 -> V_33 , V_110 , & V_3 ) ;
if ( V_3 & V_172 )
break;
} while ( V_40 -- );
V_325 = F_135 ( V_6 , ( T_3 * ) V_49 ,
sizeof( struct V_322 ) ,
V_319 ) ;
if ( V_325 < V_326 )
F_31 ( L_112
L_113 ,
V_6 -> V_33 -> V_51 , V_325 ,
sizeof( struct V_322 ) ) ;
else
F_31 ( L_114
L_115 , V_6 -> V_33 -> V_51 ) ;
F_33 ( ( T_3 * ) V_6 -> V_323 . V_324 ,
sizeof( struct V_322 ) * V_327 ) ;
#endif
V_6 -> V_69 = V_328 ;
V_6 -> V_33 -> V_329 . V_330 ++ ;
F_35 ( V_6 ) ;
}
static void F_139 ( struct V_5 * V_6 , int V_19 ,
struct V_331 * V_329 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
struct V_322 * V_49 = & V_6 -> V_323 . V_324 [ V_19 ] ;
struct V_306 * V_61 = & V_6 -> V_332 [ V_19 ] ;
F_140 ( L_116 ) ;
if ( F_141 ( V_49 -> V_333 > F_142 ( V_61 -> V_307 ) ) ) {
F_31 ( L_117
L_118 ,
V_2 -> V_51 ,
V_49 -> V_333 , F_142 ( V_61 -> V_307 ) ) ;
V_2 -> V_329 . V_330 ++ ;
return;
}
if ( F_141 ( ! F_143 ( V_2 ) ) ) {
V_2 -> V_329 . V_330 ++ ;
V_6 -> V_304 . V_334 . V_335 ++ ;
F_144 ( L_119 ) ;
return;
}
if ( F_141 ( V_6 -> V_150 -> V_198 != V_199 &&
! ( V_6 -> V_49 & V_166 ) ) ) {
F_144 ( L_120 ) ;
V_6 -> V_304 . V_334 . V_335 ++ ;
return;
}
F_145 ( V_6 -> V_261 ,
V_61 -> V_310 ,
sizeof( struct V_308 ) , V_311 ) ;
F_146 ( V_61 -> V_307 , V_49 -> V_333 ) ;
#ifdef F_147
F_148 ( V_61 -> V_307 , V_336 ,
F_149 ( T_1 , V_49 -> V_333 ,
V_337 ) ) ;
#endif
if ( ! F_150 ( V_6 -> V_150 , V_61 -> V_307 , V_329 ) ) {
#ifdef F_147
F_144 ( L_121 ,
V_2 -> V_51 ) ;
F_33 ( V_338 , V_336 , V_49 -> V_333 ) ;
#endif
V_2 -> V_329 . V_330 ++ ;
F_151 ( V_61 -> V_307 ) ;
V_61 -> V_307 = NULL ;
}
if ( F_141 ( F_128 ( V_6 , V_61 ) ) ) {
F_27 (KERN_WARNING DRV_NAME L_67
L_122
L_123 , dev->name) ;
F_31 ( L_124 ) ;
}
V_6 -> V_339 . V_324 [ V_19 ] . V_340 = V_61 -> V_310 ;
}
static void F_152 ( struct V_5 * V_6 , int V_19 ,
struct V_331 * V_329 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
struct V_322 * V_49 = & V_6 -> V_323 . V_324 [ V_19 ] ;
struct V_306 * V_61 = & V_6 -> V_332 [ V_19 ] ;
struct V_341 {
struct V_342 V_343 ;
T_5 V_344 ;
} * V_345 ;
F_140 ( L_116 ) ;
if ( F_141 ( V_49 -> V_333 > F_142 ( V_61 -> V_307 ) -
sizeof( struct V_341 ) ) ) {
F_31 ( L_117
L_118 ,
V_2 -> V_51 ,
V_49 -> V_333 ,
F_142 ( V_61 -> V_307 ) ) ;
V_2 -> V_329 . V_330 ++ ;
return;
}
if ( F_141 ( ! F_143 ( V_2 ) ) ) {
V_2 -> V_329 . V_330 ++ ;
V_6 -> V_304 . V_334 . V_335 ++ ;
F_144 ( L_119 ) ;
return;
}
if ( F_141 ( V_6 -> V_187 & V_346 &&
V_49 -> V_62 & V_347 ) ) {
F_140 ( L_125 ) ;
V_2 -> V_329 . V_330 ++ ;
return;
}
F_145 ( V_6 -> V_261 , V_61 -> V_310 ,
sizeof( struct V_308 ) , V_311 ) ;
memmove ( V_61 -> V_307 -> V_37 + sizeof( struct V_341 ) ,
V_61 -> V_307 -> V_37 , V_49 -> V_333 ) ;
V_345 = (struct V_341 * ) V_61 -> V_307 -> V_37 ;
V_345 -> V_343 . V_348 = V_349 ;
V_345 -> V_343 . V_350 = 0 ;
V_345 -> V_343 . V_351 = F_153 ( sizeof( struct V_341 ) ) ;
V_345 -> V_343 . V_352 = F_154 ( 1 << V_353 ) ;
V_345 -> V_344 = V_49 -> V_354 + V_355 ;
F_146 ( V_61 -> V_307 , V_49 -> V_333 + sizeof( struct V_341 ) ) ;
if ( ! F_150 ( V_6 -> V_150 , V_61 -> V_307 , V_329 ) ) {
V_2 -> V_329 . V_330 ++ ;
F_151 ( V_61 -> V_307 ) ;
V_61 -> V_307 = NULL ;
}
if ( F_141 ( F_128 ( V_6 , V_61 ) ) ) {
F_155 (
L_122
L_123 , V_2 -> V_51 ) ;
F_31 ( L_124 ) ;
}
V_6 -> V_339 . V_324 [ V_19 ] . V_340 = V_61 -> V_310 ;
}
static int F_156 ( struct V_5 * V_6 , int V_19 )
{
struct V_322 * V_49 = & V_6 -> V_323 . V_324 [ V_19 ] ;
struct V_308 * V_356 = V_6 -> V_332 [ V_19 ] . V_309 ;
T_2 V_357 = V_49 -> V_358 & V_359 ;
switch ( V_357 ) {
case V_360 :
return ( V_49 -> V_333 != sizeof( V_356 -> V_361 . V_362 ) ) ;
case V_363 :
return ( V_49 -> V_333 != sizeof( V_356 -> V_361 . V_49 ) ) ;
case V_364 :
return ( V_49 -> V_333 < sizeof( V_356 -> V_361 . V_365 ) ) ;
case V_366 :
case V_367 :
#ifdef F_157
return 0 ;
#else
switch ( F_158 ( F_159 ( V_356 -> V_361 . V_368 . V_369 ) ) ) {
case V_370 :
case V_371 :
return 0 ;
case V_372 :
return ( V_49 -> V_333 >
V_373 ) ;
}
#endif
}
return 1 ;
}
static void F_160 ( struct V_5 * V_6 )
{
struct V_374 * V_375 = & V_6 -> V_339 ;
struct V_376 * V_377 = & V_6 -> V_323 ;
struct V_306 * V_61 ;
T_2 V_357 ;
T_1 V_109 , V_378 , V_19 , V_317 ;
struct V_308 * V_356 ;
struct V_331 V_329 = {
. V_379 = V_80 ,
} ;
F_1 ( V_6 -> V_33 , V_380 , & V_109 ) ;
F_1 ( V_6 -> V_33 , V_381 , & V_378 ) ;
if ( V_109 >= V_375 -> V_382 ) {
F_140 ( L_126 ) ;
return;
}
V_19 = ( V_375 -> V_77 + 1 ) % V_375 -> V_382 ;
V_317 = V_19 ;
while ( V_19 != V_109 ) {
V_61 = & V_6 -> V_332 [ V_19 ] ;
F_161 ( V_6 -> V_261 , V_61 -> V_310 ,
sizeof( struct V_308 ) ,
V_311 ) ;
if ( F_141 ( F_156 ( V_6 , V_19 ) ) ) {
F_137 ( V_6 , V_19 ) ;
goto V_383;
}
V_356 = V_61 -> V_309 ;
V_357 = V_377 -> V_324 [ V_19 ] . V_358 & V_359 ;
V_329 . V_354 = V_377 -> V_324 [ V_19 ] . V_354 + V_355 ;
V_329 . V_14 = V_377 -> V_324 [ V_19 ] . V_333 ;
V_329 . V_384 = 0 ;
if ( V_329 . V_354 != 0 )
V_329 . V_384 |= V_385 ;
V_329 . V_243 = V_211 ;
F_140 ( L_127 ,
V_6 -> V_33 -> V_51 , V_386 [ V_357 ] ,
V_329 . V_14 ) ;
switch ( V_357 ) {
case V_360 :
F_126 ( V_6 , & V_356 -> V_361 . V_362 ) ;
break;
case V_363 :
F_124 ( V_6 , V_356 -> V_361 . V_49 ) ;
break;
case V_366 :
case V_367 :
#ifdef F_157
if ( V_6 -> V_150 -> V_198 == V_199 ) {
F_152 ( V_6 , V_19 , & V_329 ) ;
break;
}
#endif
if ( V_329 . V_14 < sizeof( struct V_387 ) )
break;
switch ( F_158 ( F_159 ( V_356 -> V_361 . V_368 . V_369 ) ) ) {
case V_370 :
F_162 ( V_6 -> V_150 ,
& V_356 -> V_361 . V_368 , & V_329 ) ;
break;
case V_371 :
break;
case V_372 :
F_139 ( V_6 , V_19 , & V_329 ) ;
break;
}
break;
}
V_383:
V_375 -> V_324 [ V_19 ] . V_49 . V_81 . V_388 = 0 ;
V_19 = ( V_19 + 1 ) % V_375 -> V_382 ;
}
if ( V_19 != V_317 ) {
V_375 -> V_77 = ( V_19 ? V_19 : V_375 -> V_382 ) - 1 ;
F_5 ( V_6 -> V_33 ,
V_381 , V_375 -> V_77 ) ;
}
}
static int F_163 ( struct V_5 * V_6 )
{
struct V_374 * V_389 = & V_6 -> V_390 ;
struct V_391 * V_392 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
int V_393 ;
int V_394 , V_19 ;
T_1 V_109 , V_378 , V_395 = 0 ;
if ( F_44 ( & V_6 -> V_396 ) )
return 0 ;
V_59 = V_6 -> V_396 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
V_392 = & V_389 -> V_324 [ V_61 -> V_397 ] ;
switch ( V_61 -> type ) {
case V_398 :
V_393 = 1 ;
V_394 = V_389 -> V_399 ;
break;
case V_400 :
V_393 = V_392 -> V_401 ;
V_395 = V_392 -> V_401 - 1 ;
V_394 = V_389 -> V_399 + V_395 ;
V_394 %= V_389 -> V_382 ;
break;
default:
F_27 (KERN_WARNING DRV_NAME L_128 ,
priv->net_dev->name) ;
return 0 ;
}
F_1 ( V_6 -> V_33 , V_402 ,
& V_109 ) ;
F_1 ( V_6 -> V_33 , V_403 ,
& V_378 ) ;
if ( V_378 != V_389 -> V_77 )
F_27 (KERN_WARNING DRV_NAME L_129 ,
priv->net_dev->name) ;
if ( ! ( ( V_109 <= V_378 && ( V_394 < V_109 || V_394 >= V_378 ) ) || ( V_394 < V_109 && V_394 >= V_378 ) ) ) {
F_164 ( L_130 ) ;
return 0 ;
}
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_404 ) ;
#ifdef F_127
{
V_19 = V_389 -> V_399 ;
F_164 ( L_131 , V_19 ,
& V_389 -> V_324 [ V_19 ] ,
( T_1 ) ( V_389 -> V_405 + V_19 * sizeof( struct V_391 ) ) ,
V_389 -> V_324 [ V_19 ] . V_340 , V_389 -> V_324 [ V_19 ] . V_406 ) ;
if ( V_61 -> type == V_400 ) {
V_19 = ( V_19 + 1 ) % V_389 -> V_382 ;
F_164 ( L_131 , V_19 ,
& V_389 -> V_324 [ V_19 ] ,
( T_1 ) ( V_389 -> V_405 + V_19 *
sizeof( struct V_391 ) ) ,
( T_1 ) V_389 -> V_324 [ V_19 ] . V_340 ,
V_389 -> V_324 [ V_19 ] . V_406 ) ;
}
}
#endif
switch ( V_61 -> type ) {
case V_400 :
if ( V_389 -> V_324 [ V_389 -> V_399 ] . V_49 . V_81 . V_407 . V_408 != 0 )
F_27 (KERN_WARNING DRV_NAME L_132
L_133
L_134 ,
priv->net_dev->name, txq->oldest, packet->index) ;
for ( V_19 = 0 ; V_19 < V_395 ; V_19 ++ ) {
V_392 = & V_389 -> V_324 [ ( V_61 -> V_397 + 1 + V_19 ) % V_389 -> V_382 ] ;
F_164 ( L_135 ,
( V_61 -> V_397 + 1 + V_19 ) % V_389 -> V_382 ,
V_392 -> V_340 , V_392 -> V_406 ) ;
F_145 ( V_6 -> V_261 ,
V_392 -> V_340 ,
V_392 -> V_406 , V_409 ) ;
}
F_165 ( V_61 -> V_81 . V_410 . V_411 ) ;
V_61 -> V_81 . V_410 . V_411 = NULL ;
F_48 ( V_59 , & V_6 -> V_412 ) ;
F_49 ( & V_6 -> V_413 ) ;
if ( V_6 -> V_49 & V_166 )
F_166 ( V_6 -> V_33 ) ;
V_6 -> V_33 -> V_414 = V_80 ;
break;
case V_398 :
if ( V_389 -> V_324 [ V_389 -> V_399 ] . V_49 . V_81 . V_407 . V_408 != 1 )
F_27 (KERN_WARNING DRV_NAME L_132
L_136
L_134 ,
priv->net_dev->name, txq->oldest, packet->index) ;
#ifdef F_127
if ( V_61 -> V_81 . V_82 . V_57 -> V_83 <
F_104 ( V_64 ) )
F_164 ( L_137 ,
V_64 [ V_61 -> V_81 . V_82 . V_57 ->
V_83 ] ,
V_61 -> V_81 . V_82 . V_57 ->
V_83 ,
V_61 -> V_81 . V_82 . V_57 -> V_415 ) ;
#endif
F_48 ( V_59 , & V_6 -> V_75 ) ;
F_49 ( & V_6 -> V_90 ) ;
break;
}
V_389 -> V_399 = ( V_394 + 1 ) % V_389 -> V_382 ;
V_389 -> V_416 += V_393 ;
F_167 ( & V_6 -> V_417 , V_389 -> V_416 ) ;
F_164 ( L_138 ,
V_80 - V_61 -> V_79 ) ;
return ( ! F_44 ( & V_6 -> V_396 ) ) ;
}
static inline void F_168 ( struct V_5 * V_6 )
{
int V_19 = 0 ;
while ( F_163 ( V_6 ) && V_19 < 200 )
V_19 ++ ;
if ( V_19 == 200 ) {
F_27 (KERN_WARNING DRV_NAME L_67
L_139 ,
priv->net_dev->name, i) ;
}
}
static void F_50 ( struct V_5 * V_6 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_374 * V_389 = & V_6 -> V_390 ;
struct V_391 * V_392 ;
int V_77 = V_389 -> V_77 ;
while ( ! F_44 ( & V_6 -> V_91 ) ) {
if ( V_389 -> V_416 <= 3 ) {
F_164 ( L_140 ) ;
break;
}
V_59 = V_6 -> V_91 . V_77 ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_92 ) ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
F_164 ( L_141 ,
& V_389 -> V_324 [ V_389 -> V_77 ] ,
( T_1 ) ( V_389 -> V_405 + V_389 -> V_77 *
sizeof( struct V_391 ) ) ) ;
V_61 -> V_397 = V_389 -> V_77 ;
V_392 = & V_389 -> V_324 [ V_389 -> V_77 ] ;
V_392 -> V_340 = V_61 -> V_81 . V_82 . V_418 ;
V_392 -> V_406 = sizeof( struct V_305 ) ;
V_392 -> V_401 = 1 ;
V_392 -> V_49 . V_81 . V_388 =
V_419 |
V_420 ;
V_389 -> V_77 ++ ;
V_389 -> V_77 %= V_389 -> V_382 ;
V_389 -> V_416 -- ;
F_47 ( & V_6 -> V_417 ) ;
F_48 ( V_59 , & V_6 -> V_396 ) ;
F_49 ( & V_6 -> V_404 ) ;
}
if ( V_389 -> V_77 != V_77 ) {
F_169 () ;
F_5 ( V_6 -> V_33 ,
V_403 ,
V_389 -> V_77 ) ;
}
}
static void F_51 ( struct V_5 * V_6 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_374 * V_389 = & V_6 -> V_390 ;
struct V_391 * V_392 ;
int V_77 = V_389 -> V_77 ;
int V_19 = 0 ;
struct V_421 * V_422 ;
struct V_387 * V_423 ;
while ( ! F_44 ( & V_6 -> V_424 ) ) {
V_59 = V_6 -> V_424 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
if ( F_141 ( 1 + V_61 -> V_81 . V_410 . V_411 -> V_425 >
V_426 ) ) {
F_31 ( L_142
L_143 ,
V_6 -> V_33 -> V_51 ) ;
}
if ( V_389 -> V_416 <= 3 + V_61 -> V_81 . V_410 . V_411 -> V_425 ) {
F_164 ( L_140 ) ;
break;
}
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_427 ) ;
V_392 = & V_389 -> V_324 [ V_389 -> V_77 ] ;
V_61 -> V_397 = V_389 -> V_77 ;
V_422 = V_61 -> V_81 . V_410 . V_37 ;
V_423 = (struct V_387 * ) V_61 -> V_81 . V_410 . V_411 ->
V_428 [ 0 ] -> V_37 ;
if ( V_6 -> V_150 -> V_198 == V_429 ) {
memcpy ( V_422 -> V_430 , V_423 -> V_431 , V_230 ) ;
memcpy ( V_422 -> V_432 , V_423 -> V_433 , V_230 ) ;
} else if ( V_6 -> V_150 -> V_198 == V_434 ) {
memcpy ( V_422 -> V_430 , V_423 -> V_431 , V_230 ) ;
memcpy ( V_422 -> V_432 , V_423 -> V_435 , V_230 ) ;
}
V_422 -> V_83 = V_436 ;
V_422 -> V_84 = 0 ;
V_422 -> V_437 = 0 ;
V_422 -> V_438 = V_61 -> V_81 . V_410 . V_411 -> V_438 ;
if ( V_61 -> V_81 . V_410 . V_411 -> V_425 > 1 )
V_422 -> V_439 =
V_61 -> V_81 . V_410 . V_411 -> V_440 -
V_441 ;
else
V_422 -> V_439 = 0 ;
V_392 -> V_340 = V_61 -> V_81 . V_410 . V_442 ;
V_392 -> V_406 = sizeof( struct V_421 ) ;
V_392 -> V_401 = 1 + V_61 -> V_81 . V_410 . V_411 -> V_425 ;
V_392 -> V_49 . V_81 . V_388 =
V_443 |
V_444 ;
V_389 -> V_77 ++ ;
V_389 -> V_77 %= V_389 -> V_382 ;
F_164 ( L_144 ,
V_61 -> V_397 , V_392 -> V_340 , V_392 -> V_406 ) ;
#ifdef F_127
if ( V_61 -> V_81 . V_410 . V_411 -> V_425 > 1 )
F_170 ( L_145 ,
V_61 -> V_81 . V_410 . V_411 -> V_425 ) ;
#endif
for ( V_19 = 0 ; V_19 < V_61 -> V_81 . V_410 . V_411 -> V_425 ; V_19 ++ ) {
V_392 = & V_389 -> V_324 [ V_389 -> V_77 ] ;
if ( V_19 == V_61 -> V_81 . V_410 . V_411 -> V_425 - 1 )
V_392 -> V_49 . V_81 . V_388 =
V_443 |
V_420 ;
else
V_392 -> V_49 . V_81 . V_388 =
V_443 |
V_444 ;
V_392 -> V_406 = V_61 -> V_81 . V_410 . V_411 ->
V_428 [ V_19 ] -> V_14 - V_441 ;
V_392 -> V_340 = F_130 ( V_6 -> V_261 ,
V_61 -> V_81 . V_410 .
V_411 -> V_428 [ V_19 ] ->
V_37 +
V_441 ,
V_392 -> V_406 ,
V_409 ) ;
F_164 ( L_146 ,
V_389 -> V_77 , V_392 -> V_340 ,
V_392 -> V_406 ) ;
F_171 ( V_6 -> V_261 ,
V_392 -> V_340 ,
V_392 -> V_406 ,
V_409 ) ;
V_389 -> V_77 ++ ;
V_389 -> V_77 %= V_389 -> V_382 ;
}
V_389 -> V_416 -= 1 + V_61 -> V_81 . V_410 . V_411 -> V_425 ;
F_167 ( & V_6 -> V_417 , V_389 -> V_416 ) ;
F_48 ( V_59 , & V_6 -> V_396 ) ;
F_49 ( & V_6 -> V_404 ) ;
}
if ( V_389 -> V_77 != V_77 ) {
F_5 ( V_6 -> V_33 ,
V_403 ,
V_389 -> V_77 ) ;
}
}
static void F_172 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
unsigned long V_62 ;
T_1 V_157 , V_316 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
F_68 ( V_6 ) ;
F_1 ( V_2 , V_160 , & V_157 ) ;
F_173 ( L_147 ,
( unsigned long ) V_157 & V_138 ) ;
V_6 -> V_445 ++ ;
V_6 -> V_446 ++ ;
F_173 ( L_148 ,
( unsigned long ) V_157 & V_138 ) ;
if ( V_157 & V_162 ) {
F_27 (KERN_WARNING DRV_NAME
L_149 ) ;
V_6 -> V_447 ++ ;
F_5 ( V_2 , V_160 , V_162 ) ;
F_15 ( V_2 , V_448 , & V_6 -> V_69 ) ;
F_31 ( L_150 ,
V_6 -> V_33 -> V_51 , V_6 -> V_69 ) ;
F_15 ( V_2 , F_174 ( V_6 -> V_69 ) , & V_316 ) ;
F_31 ( L_151 ,
V_6 -> V_33 -> V_51 , V_316 ) ;
F_35 ( V_6 ) ;
}
if ( V_157 & V_163 ) {
F_27 (KERN_ERR DRV_NAME
L_152 ) ;
V_6 -> V_447 ++ ;
F_5 ( V_2 , V_160 , V_163 ) ;
}
if ( V_157 & V_449 ) {
F_173 ( L_153 ) ;
V_6 -> V_450 ++ ;
F_5 ( V_2 , V_160 , V_449 ) ;
F_160 ( V_6 ) ;
F_168 ( V_6 ) ;
}
if ( V_157 & V_451 ) {
F_173 ( L_154 ) ;
V_6 -> V_452 ++ ;
F_5 ( V_2 , V_160 , V_451 ) ;
F_168 ( V_6 ) ;
F_50 ( V_6 ) ;
F_51 ( V_6 ) ;
}
if ( V_157 & V_453 ) {
F_173 ( L_155 ) ;
V_6 -> V_447 ++ ;
F_5 ( V_2 , V_160 , V_453 ) ;
F_168 ( V_6 ) ;
}
if ( V_157 & V_454 ) {
V_6 -> V_447 ++ ;
F_5 ( V_2 , V_160 , V_454 ) ;
}
if ( V_157 & V_161 ) {
F_173 ( L_156 ) ;
V_6 -> V_447 ++ ;
F_1 ( V_2 , V_160 , & V_316 ) ;
if ( V_316 & ( V_162 |
V_163 ) ) {
F_5 ( V_2 , V_160 ,
V_162 |
V_163 ) ;
}
F_5 ( V_2 , V_160 , V_161 ) ;
}
if ( V_157 & V_455 ) {
F_173 ( L_157 ) ;
V_6 -> V_447 ++ ;
F_5 ( V_2 , V_160 , V_455 ) ;
}
if ( V_157 & V_456 ) {
F_173 ( L_158 ) ;
V_6 -> V_447 ++ ;
F_5 ( V_2 , V_160 ,
V_456 ) ;
}
V_6 -> V_445 -- ;
F_67 ( V_6 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
F_173 ( L_45 ) ;
}
static T_6 F_175 ( int V_457 , void * V_37 )
{
struct V_5 * V_6 = V_37 ;
T_1 V_157 , V_158 ;
if ( ! V_37 )
return V_458 ;
F_176 ( & V_6 -> V_68 ) ;
if ( ! ( V_6 -> V_49 & V_136 ) ) {
goto V_459;
}
F_1 ( V_6 -> V_33 , V_137 , & V_158 ) ;
F_1 ( V_6 -> V_33 , V_160 , & V_157 ) ;
if ( V_157 == 0xFFFFFFFF ) {
F_27 (KERN_WARNING DRV_NAME L_159 ) ;
goto V_459;
}
V_157 &= V_138 ;
if ( ! ( V_157 & V_158 ) ) {
goto V_459;
}
F_68 ( V_6 ) ;
F_177 ( & V_6 -> V_460 ) ;
F_178 ( & V_6 -> V_68 ) ;
return V_461 ;
V_459:
F_178 ( & V_6 -> V_68 ) ;
return V_458 ;
}
static T_7 F_179 ( struct V_462 * V_411 ,
struct V_1 * V_2 , int V_463 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
unsigned long V_62 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( ! ( V_6 -> V_49 & V_166 ) ) {
F_31 ( L_160 ) ;
V_6 -> V_33 -> V_329 . V_464 ++ ;
F_38 ( V_2 ) ;
goto V_71;
}
if ( F_44 ( & V_6 -> V_412 ) )
goto V_71;
V_59 = V_6 -> V_412 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
V_61 -> V_81 . V_410 . V_411 = V_411 ;
F_164 ( L_161 , V_411 -> V_428 [ 0 ] -> V_14 ) ;
F_33 ( V_465 , V_411 -> V_428 [ 0 ] -> V_37 , V_411 -> V_428 [ 0 ] -> V_14 ) ;
V_61 -> V_79 = V_80 ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_413 ) ;
F_48 ( V_59 , & V_6 -> V_424 ) ;
F_49 ( & V_6 -> V_427 ) ;
F_51 ( V_6 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
return V_466 ;
V_71:
F_38 ( V_2 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
return V_467 ;
}
static int F_180 ( struct V_5 * V_6 )
{
int V_19 , V_40 , V_63 = - V_31 ;
void * V_468 ;
T_8 V_469 ;
V_6 -> V_470 =
F_134 ( V_471 * sizeof( struct V_60 ) ,
V_239 ) ;
if ( ! V_6 -> V_470 )
return - V_240 ;
for ( V_19 = 0 ; V_19 < V_471 ; V_19 ++ ) {
V_468 = F_181 ( V_6 -> V_261 ,
sizeof( struct V_305 ) , & V_469 ) ;
if ( ! V_468 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_162
L_163 , priv->net_dev->name) ;
V_63 = - V_240 ;
break;
}
memset ( V_468 , 0 , sizeof( struct V_305 ) ) ;
V_6 -> V_470 [ V_19 ] . type = V_398 ;
V_6 -> V_470 [ V_19 ] . V_81 . V_82 . V_57 =
(struct V_305 * ) V_468 ;
V_6 -> V_470 [ V_19 ] . V_81 . V_82 . V_418 = V_469 ;
}
if ( V_19 == V_471 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_19 ; V_40 ++ ) {
F_182 ( V_6 -> V_261 ,
sizeof( struct V_305 ) ,
V_6 -> V_470 [ V_40 ] . V_81 . V_82 . V_57 ,
V_6 -> V_470 [ V_40 ] . V_81 . V_82 .
V_418 ) ;
}
F_132 ( V_6 -> V_470 ) ;
V_6 -> V_470 = NULL ;
return V_63 ;
}
static int F_183 ( struct V_5 * V_6 )
{
int V_19 ;
F_184 ( & V_6 -> V_75 ) ;
F_184 ( & V_6 -> V_91 ) ;
for ( V_19 = 0 ; V_19 < V_471 ; V_19 ++ )
F_48 ( & V_6 -> V_470 [ V_19 ] . V_78 , & V_6 -> V_75 ) ;
F_167 ( & V_6 -> V_90 , V_19 ) ;
return 0 ;
}
static void F_185 ( struct V_5 * V_6 )
{
int V_19 ;
if ( ! V_6 -> V_470 )
return;
for ( V_19 = 0 ; V_19 < V_471 ; V_19 ++ ) {
F_182 ( V_6 -> V_261 ,
sizeof( struct V_305 ) ,
V_6 -> V_470 [ V_19 ] . V_81 . V_82 . V_57 ,
V_6 -> V_470 [ V_19 ] . V_81 . V_82 .
V_418 ) ;
}
F_132 ( V_6 -> V_470 ) ;
V_6 -> V_470 = NULL ;
}
static T_9 F_186 ( struct V_472 * V_318 , struct V_473 * V_474 ,
char * V_15 )
{
struct V_261 * V_261 = F_108 ( V_318 , struct V_261 , V_2 ) ;
char * V_39 = V_15 ;
int V_19 , V_40 ;
T_1 V_4 ;
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ ) {
V_39 += sprintf ( V_39 , L_164 , V_19 * 16 ) ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 += 4 ) {
F_187 ( V_261 , V_19 * 16 + V_40 , & V_4 ) ;
V_39 += sprintf ( V_39 , L_165 , V_4 ) ;
}
V_39 += sprintf ( V_39 , L_166 ) ;
}
return V_39 - V_15 ;
}
static T_9 F_188 ( struct V_472 * V_318 , struct V_473 * V_474 ,
char * V_15 )
{
struct V_5 * V_469 = F_189 ( V_318 ) ;
return sprintf ( V_15 , L_167 , ( int ) V_469 -> V_187 ) ;
}
static T_9 F_190 ( struct V_472 * V_318 , struct V_473 * V_474 ,
char * V_15 )
{
struct V_5 * V_469 = F_189 ( V_318 ) ;
return sprintf ( V_15 , L_167 , ( int ) V_469 -> V_49 ) ;
}
static T_9 F_191 ( struct V_472 * V_318 , struct V_473 * V_474 ,
char * V_15 )
{
struct V_5 * V_469 = F_189 ( V_318 ) ;
return sprintf ( V_15 , L_167 , ( int ) V_469 -> V_475 ) ;
}
static T_9 F_192 ( struct V_472 * V_318 , struct V_473 * V_474 ,
char * V_15 )
{
int V_19 ;
struct V_5 * V_6 = F_189 ( V_318 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
char * V_39 = V_15 ;
T_1 V_4 = 0 ;
V_39 += sprintf ( V_39 , L_168 , L_169 ) ;
for ( V_19 = 0 ; V_19 < F_104 ( V_476 ) ; V_19 ++ ) {
F_1 ( V_2 , V_476 [ V_19 ] . V_8 , & V_4 ) ;
V_39 += sprintf ( V_39 , L_170 ,
V_476 [ V_19 ] . V_51 , V_476 [ V_19 ] . V_8 , V_4 ) ;
}
return V_39 - V_15 ;
}
static T_9 F_193 ( struct V_472 * V_318 , struct V_473 * V_474 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_318 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
char * V_39 = V_15 ;
int V_19 ;
V_39 += sprintf ( V_39 , L_168 , L_171 ) ;
for ( V_19 = 0 ; V_19 < F_104 ( V_477 ) ; V_19 ++ ) {
T_3 V_478 ;
T_2 V_479 ;
T_1 V_480 ;
switch ( V_477 [ V_19 ] . V_481 ) {
case 1 :
F_19 ( V_2 , V_477 [ V_19 ] . V_8 , & V_478 ) ;
V_39 += sprintf ( V_39 , L_172 ,
V_477 [ V_19 ] . V_51 , V_477 [ V_19 ] . V_8 ,
V_478 ) ;
break;
case 2 :
F_17 ( V_2 , V_477 [ V_19 ] . V_8 , & V_479 ) ;
V_39 += sprintf ( V_39 , L_173 ,
V_477 [ V_19 ] . V_51 , V_477 [ V_19 ] . V_8 ,
V_479 ) ;
break;
case 4 :
F_15 ( V_2 , V_477 [ V_19 ] . V_8 , & V_480 ) ;
V_39 += sprintf ( V_39 , L_170 ,
V_477 [ V_19 ] . V_51 , V_477 [ V_19 ] . V_8 ,
V_480 ) ;
break;
}
}
return V_39 - V_15 ;
}
static T_9 F_194 ( struct V_472 * V_318 , struct V_473 * V_474 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_318 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
static unsigned long V_482 = 0 ;
int V_14 = 0 ;
T_1 V_483 [ 4 ] ;
int V_19 ;
char line [ 81 ] ;
if ( V_482 >= 0x30000 )
V_482 = 0 ;
while ( V_14 < V_484 - 128 && V_482 < 0x30000 ) {
if ( V_6 -> V_312 [ 0 ] )
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ )
V_483 [ V_19 ] =
* ( T_1 * ) F_136 ( V_482 + V_19 * 4 ) ;
else
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ )
F_15 ( V_2 , V_482 + V_19 * 4 , & V_483 [ V_19 ] ) ;
if ( V_6 -> V_485 )
V_14 += sprintf ( V_15 + V_14 ,
L_174
L_174
L_174
L_174 ,
( ( T_3 * ) V_483 ) [ 0x0 ] ,
( ( T_3 * ) V_483 ) [ 0x1 ] ,
( ( T_3 * ) V_483 ) [ 0x2 ] ,
( ( T_3 * ) V_483 ) [ 0x3 ] ,
( ( T_3 * ) V_483 ) [ 0x4 ] ,
( ( T_3 * ) V_483 ) [ 0x5 ] ,
( ( T_3 * ) V_483 ) [ 0x6 ] ,
( ( T_3 * ) V_483 ) [ 0x7 ] ,
( ( T_3 * ) V_483 ) [ 0x8 ] ,
( ( T_3 * ) V_483 ) [ 0x9 ] ,
( ( T_3 * ) V_483 ) [ 0xa ] ,
( ( T_3 * ) V_483 ) [ 0xb ] ,
( ( T_3 * ) V_483 ) [ 0xc ] ,
( ( T_3 * ) V_483 ) [ 0xd ] ,
( ( T_3 * ) V_483 ) [ 0xe ] ,
( ( T_3 * ) V_483 ) [ 0xf ] ) ;
else
V_14 += sprintf ( V_15 + V_14 , L_19 ,
F_32 ( line , sizeof( line ) ,
( T_3 * ) V_483 , 16 , V_482 ) ) ;
V_482 += 16 ;
}
return V_14 ;
}
static T_9 F_195 ( struct V_472 * V_318 , struct V_473 * V_474 ,
const char * V_15 , T_4 V_36 )
{
struct V_5 * V_6 = F_189 ( V_318 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
const char * V_469 = V_15 ;
( void ) V_2 ;
if ( V_36 < 1 )
return V_36 ;
if ( V_469 [ 0 ] == '1' ||
( V_36 >= 2 && tolower ( V_469 [ 0 ] ) == 'o' && tolower ( V_469 [ 1 ] ) == 'n' ) ) {
F_31 ( L_175 ,
V_2 -> V_51 ) ;
V_6 -> V_485 = 1 ;
} else if ( V_469 [ 0 ] == '0' || ( V_36 >= 2 && tolower ( V_469 [ 0 ] ) == 'o' &&
tolower ( V_469 [ 1 ] ) == 'f' ) ) {
F_31 ( L_176 ,
V_2 -> V_51 ) ;
V_6 -> V_485 = 0 ;
} else if ( tolower ( V_469 [ 0 ] ) == 'r' ) {
F_31 ( L_177 , V_2 -> V_51 ) ;
F_131 ( V_6 ) ;
} else
F_31 ( L_178
L_179 , V_2 -> V_51 ) ;
return V_36 ;
}
static T_9 F_196 ( struct V_472 * V_318 , struct V_473 * V_474 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_318 ) ;
T_1 V_4 = 0 ;
int V_14 = 0 ;
T_1 V_486 ;
static int V_482 = 0 ;
if ( V_6 -> V_49 & V_487 )
return 0 ;
if ( V_482 >= F_104 ( V_488 ) )
V_482 = 0 ;
while ( V_14 < V_484 - 128 && V_482 < F_104 ( V_488 ) ) {
V_486 = sizeof( T_1 ) ;
if ( F_26 ( V_6 , V_488 [ V_482 ] . V_397 , & V_4 ,
& V_486 ) )
V_14 += sprintf ( V_15 + V_14 , L_180 ,
V_488 [ V_482 ] . V_397 ,
V_488 [ V_482 ] . V_489 ) ;
else
V_14 += sprintf ( V_15 + V_14 , L_181 ,
V_488 [ V_482 ] . V_397 , V_4 ,
V_488 [ V_482 ] . V_489 ) ;
V_482 ++ ;
}
return V_14 ;
}
static T_9 F_197 ( struct V_472 * V_318 , struct V_473 * V_474 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_318 ) ;
char * V_39 = V_15 ;
V_39 += sprintf ( V_39 , L_182 ,
V_6 -> V_446 , V_6 -> V_452 ,
V_6 -> V_450 , V_6 -> V_447 ) ;
V_39 += sprintf ( V_39 , L_183 , V_6 -> V_264 ) ;
V_39 += sprintf ( V_39 , L_184 , V_6 -> V_490 ) ;
#ifdef F_127
V_39 += sprintf ( V_39 , L_185 ,
V_6 -> V_312 [ 0 ] ? L_186 : L_187 ) ;
#endif
return V_39 - V_15 ;
}
static int F_198 ( struct V_5 * V_6 , T_1 V_315 )
{
int V_63 ;
if ( V_315 == V_6 -> V_150 -> V_198 )
return 0 ;
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
switch ( V_315 ) {
case V_429 :
V_6 -> V_33 -> type = V_221 ;
break;
case V_434 :
V_6 -> V_33 -> type = V_221 ;
break;
#ifdef F_157
case V_199 :
V_6 -> V_491 = V_6 -> V_150 -> V_198 ;
V_6 -> V_33 -> type = V_492 ;
break;
#endif
}
V_6 -> V_150 -> V_198 = V_315 ;
#ifdef F_61
V_120 . V_121 = 0 ;
#endif
F_27 ( V_214 L_189 , V_6 -> V_33 -> V_51 ) ;
V_6 -> V_47 = 0 ;
F_35 ( V_6 ) ;
return 0 ;
}
static T_9 F_199 ( struct V_472 * V_318 , struct V_473 * V_474 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_318 ) ;
int V_14 = 0 ;
#define F_200 ( T_10 , T_11 ) len += sprintf(buf + len, # x ": %" y "\n", priv-> x)
if ( V_6 -> V_49 & V_166 )
V_14 += sprintf ( V_15 + V_14 , L_190 ,
F_36 () - V_6 -> V_285 ) ;
else
V_14 += sprintf ( V_15 + V_14 , L_191 ) ;
F_200 ( V_150 -> V_493 . V_494 [ V_6 -> V_150 -> V_493 . V_495 ] , L_192 ) ;
F_200 ( V_49 , L_193 ) ;
F_200 ( V_187 , L_193 ) ;
F_200 ( V_475 , L_193 ) ;
V_14 +=
sprintf ( V_15 + V_14 , L_194 ,
( unsigned long ) V_6 -> V_496 ) ;
F_200 ( V_69 , L_195 ) ;
F_200 ( V_181 , L_195 ) ;
F_200 ( V_215 , L_195 ) ;
F_200 ( V_76 , L_195 ) ;
F_200 ( V_427 . V_147 , L_195 ) ;
F_200 ( V_427 . V_497 , L_195 ) ;
F_200 ( V_413 . V_147 , L_195 ) ;
F_200 ( V_413 . V_498 , L_195 ) ;
F_200 ( V_90 . V_147 , L_195 ) ;
F_200 ( V_90 . V_498 , L_195 ) ;
F_200 ( V_92 . V_147 , L_195 ) ;
F_200 ( V_92 . V_497 , L_195 ) ;
F_200 ( V_404 . V_147 , L_195 ) ;
F_200 ( V_404 . V_497 , L_195 ) ;
F_200 ( V_417 . V_147 , L_195 ) ;
F_200 ( V_417 . V_498 , L_195 ) ;
F_200 ( V_150 -> V_299 , L_195 ) ;
F_200 ( V_47 , L_195 ) ;
return V_14 ;
}
static T_9 F_201 ( struct V_472 * V_318 , struct V_473 * V_474 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_318 ) ;
char V_269 [ V_270 + 1 ] ;
T_3 V_274 [ V_230 ] ;
T_1 V_272 = 0 ;
char * V_39 = V_15 ;
unsigned int V_287 ;
int V_267 ;
if ( V_6 -> V_49 & V_487 )
return 0 ;
memset ( V_269 , 0 , sizeof( V_269 ) ) ;
memset ( V_274 , 0 , sizeof( V_274 ) ) ;
V_287 = V_270 ;
V_267 = F_26 ( V_6 , V_276 , V_269 , & V_287 ) ;
if ( V_267 )
F_31 ( L_46 ,
__LINE__ ) ;
V_287 = sizeof( V_274 ) ;
V_267 = F_26 ( V_6 , V_279 ,
V_274 , & V_287 ) ;
if ( V_267 )
F_31 ( L_46 ,
__LINE__ ) ;
V_287 = sizeof( T_1 ) ;
V_267 = F_26 ( V_6 , V_278 , & V_272 , & V_287 ) ;
if ( V_267 )
F_31 ( L_46 ,
__LINE__ ) ;
V_39 += sprintf ( V_39 , L_196 , V_269 ) ;
V_39 += sprintf ( V_39 , L_197 , V_274 ) ;
V_39 += sprintf ( V_39 , L_198 , V_272 ) ;
return V_39 - V_15 ;
}
static T_9 F_202 ( struct V_499 * V_318 , char * V_15 )
{
return sprintf ( V_15 , L_199 , V_44 ) ;
}
static T_9 F_203 ( struct V_499 * V_318 ,
const char * V_15 , T_4 V_36 )
{
char * V_469 = ( char * ) V_15 ;
T_1 V_4 ;
if ( V_469 [ 1 ] == 'x' || V_469 [ 1 ] == 'X' || V_469 [ 0 ] == 'x' || V_469 [ 0 ] == 'X' ) {
V_469 ++ ;
if ( V_469 [ 0 ] == 'x' || V_469 [ 0 ] == 'X' )
V_469 ++ ;
V_4 = F_204 ( V_469 , & V_469 , 16 ) ;
} else
V_4 = F_204 ( V_469 , & V_469 , 10 ) ;
if ( V_469 == V_15 )
F_31 ( L_200 , V_15 ) ;
else
V_44 = V_4 ;
return F_205 ( V_15 , V_36 ) ;
}
static T_9 F_206 ( struct V_472 * V_318 ,
struct V_473 * V_474 , char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_318 ) ;
char * V_39 = V_15 ;
int V_19 ;
if ( V_6 -> V_69 )
V_39 += sprintf ( V_39 , L_199 , V_6 -> V_69 ) ;
else
V_39 += sprintf ( V_39 , L_201 ) ;
for ( V_19 = 1 ; V_19 <= V_169 ; V_19 ++ ) {
if ( ! V_6 -> V_167 [ ( V_6 -> V_168 - V_19 ) %
V_169 ] )
continue;
V_39 += sprintf ( V_39 , L_202 , V_19 ,
V_6 -> V_167 [ ( V_6 -> V_168 - V_19 ) %
V_169 ] ) ;
}
return V_39 - V_15 ;
}
static T_9 F_207 ( struct V_472 * V_318 ,
struct V_473 * V_474 , const char * V_15 ,
T_4 V_36 )
{
struct V_5 * V_6 = F_189 ( V_318 ) ;
F_35 ( V_6 ) ;
return V_36 ;
}
static T_9 F_208 ( struct V_472 * V_318 , struct V_473 * V_474 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_318 ) ;
return sprintf ( V_15 , L_203 , V_6 -> V_150 -> V_500 ) ;
}
static T_9 F_209 ( struct V_472 * V_318 , struct V_473 * V_474 ,
const char * V_15 , T_4 V_36 )
{
struct V_5 * V_6 = F_189 ( V_318 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
char V_483 [] = L_204 ;
unsigned long V_14 =
( sizeof( V_483 ) - 1 ) > V_36 ? V_36 : sizeof( V_483 ) - 1 ;
unsigned long V_4 ;
char * V_469 = V_483 ;
( void ) V_2 ;
F_31 ( L_42 ) ;
strncpy ( V_483 , V_15 , V_14 ) ;
V_483 [ V_14 ] = 0 ;
if ( V_469 [ 1 ] == 'x' || V_469 [ 1 ] == 'X' || V_469 [ 0 ] == 'x' || V_469 [ 0 ] == 'X' ) {
V_469 ++ ;
if ( V_469 [ 0 ] == 'x' || V_469 [ 0 ] == 'X' )
V_469 ++ ;
V_4 = F_204 ( V_469 , & V_469 , 16 ) ;
} else
V_4 = F_204 ( V_469 , & V_469 , 10 ) ;
if ( V_469 == V_483 ) {
F_31 ( L_205 , V_2 -> V_51 ) ;
} else {
V_6 -> V_150 -> V_500 = V_4 ;
F_31 ( L_206 , V_6 -> V_150 -> V_500 ) ;
}
F_31 ( L_45 ) ;
return V_14 ;
}
static T_9 F_210 ( struct V_472 * V_318 , struct V_473 * V_474 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_318 ) ;
int V_4 = ( ( V_6 -> V_49 & V_206 ) ? 0x1 : 0x0 ) |
( F_71 ( V_6 ) ? 0x2 : 0x0 ) ;
return sprintf ( V_15 , L_207 , V_4 ) ;
}
static int F_211 ( struct V_5 * V_6 , int V_501 )
{
if ( ( V_501 ? 1 : 0 ) ==
( V_6 -> V_49 & V_206 ? 1 : 0 ) )
return 0 ;
F_212 ( L_208 ,
V_501 ? L_209 : L_210 ) ;
F_84 ( & V_6 -> V_266 ) ;
if ( V_501 ) {
V_6 -> V_49 |= V_206 ;
F_99 ( V_6 ) ;
} else {
V_6 -> V_49 &= ~ V_206 ;
if ( F_71 ( V_6 ) ) {
F_212 ( L_211
L_212 ) ;
V_6 -> V_215 = 0 ;
F_89 ( & V_6 -> V_216 ) ;
F_39 ( & V_6 -> V_216 ,
F_97 ( V_53 ) ) ;
} else
F_35 ( V_6 ) ;
}
F_85 ( & V_6 -> V_266 ) ;
return 1 ;
}
static T_9 F_213 ( struct V_472 * V_318 , struct V_473 * V_474 ,
const char * V_15 , T_4 V_36 )
{
struct V_5 * V_6 = F_189 ( V_318 ) ;
F_211 ( V_6 , V_15 [ 0 ] == '1' ) ;
return V_36 ;
}
static int F_214 ( struct V_5 * V_6 , int V_382 )
{
struct V_376 * V_502 = & V_6 -> V_323 ;
F_31 ( L_42 ) ;
V_502 -> V_481 = V_382 * sizeof( struct V_322 ) ;
V_502 -> V_324 =
(struct V_322 * ) F_181 ( V_6 -> V_261 ,
V_502 -> V_481 , & V_502 -> V_405 ) ;
if ( ! V_502 -> V_324 ) {
F_155 ( L_213 ) ;
return - V_240 ;
}
memset ( V_502 -> V_324 , 0 , V_502 -> V_481 ) ;
F_31 ( L_45 ) ;
return 0 ;
}
static void F_215 ( struct V_5 * V_6 )
{
F_31 ( L_42 ) ;
if ( V_6 -> V_323 . V_324 ) {
F_182 ( V_6 -> V_261 , V_6 -> V_323 . V_481 ,
V_6 -> V_323 . V_324 ,
V_6 -> V_323 . V_405 ) ;
V_6 -> V_323 . V_324 = NULL ;
}
F_31 ( L_45 ) ;
}
static int F_216 ( struct V_5 * V_6 ,
struct V_374 * V_502 , int V_382 )
{
F_31 ( L_42 ) ;
memset ( V_502 , 0 , sizeof( struct V_374 ) ) ;
V_502 -> V_382 = V_382 ;
V_502 -> V_481 = V_382 * sizeof( struct V_391 ) ;
V_502 -> V_324 = F_181 ( V_6 -> V_261 , V_502 -> V_481 , & V_502 -> V_405 ) ;
if ( ! V_502 -> V_324 ) {
F_31
( L_214 ) ;
return - V_240 ;
}
memset ( V_502 -> V_324 , 0 , V_502 -> V_481 ) ;
F_31 ( L_45 ) ;
return 0 ;
}
static void F_217 ( struct V_5 * V_6 , struct V_374 * V_502 )
{
F_31 ( L_42 ) ;
if ( ! V_502 )
return;
if ( V_502 -> V_324 ) {
F_182 ( V_6 -> V_261 , V_502 -> V_481 , V_502 -> V_324 , V_502 -> V_405 ) ;
V_502 -> V_324 = NULL ;
}
F_31 ( L_45 ) ;
}
static void F_218 ( struct V_5 * V_6 ,
struct V_374 * V_502 , T_1 V_503 , T_1 V_481 ,
T_1 V_109 , T_1 V_378 )
{
F_31 ( L_42 ) ;
F_31 ( L_215 , V_502 -> V_324 ,
( T_1 ) V_502 -> V_405 ) ;
F_5 ( V_6 -> V_33 , V_503 , V_502 -> V_405 ) ;
F_5 ( V_6 -> V_33 , V_481 , V_502 -> V_382 ) ;
F_5 ( V_6 -> V_33 , V_109 , V_502 -> V_399 ) ;
F_5 ( V_6 -> V_33 , V_378 , V_502 -> V_77 ) ;
F_31 ( L_45 ) ;
}
static void F_219 ( struct V_5 * V_6 )
{
V_6 -> V_215 = 1 ;
V_6 -> V_181 = 1 ;
F_220 ( & V_6 -> V_52 ) ;
F_220 ( & V_6 -> V_295 ) ;
F_220 ( & V_6 -> V_286 ) ;
F_220 ( & V_6 -> V_182 ) ;
F_220 ( & V_6 -> V_216 ) ;
F_221 ( & V_6 -> V_298 ) ;
F_220 ( & V_6 -> V_297 ) ;
}
static int F_222 ( struct V_5 * V_6 )
{
int V_19 , V_40 , V_63 = - V_31 ;
void * V_468 ;
T_8 V_469 ;
F_31 ( L_42 ) ;
V_63 = F_216 ( V_6 , & V_6 -> V_390 , V_504 ) ;
if ( V_63 ) {
F_62 ( L_216 ,
V_6 -> V_33 -> V_51 ) ;
return V_63 ;
}
V_6 -> V_505 =
F_134 ( V_506 * sizeof( struct V_60 ) ,
V_313 ) ;
if ( ! V_6 -> V_505 ) {
F_27 (KERN_ERR DRV_NAME
L_217 ,
priv->net_dev->name) ;
F_217 ( V_6 , & V_6 -> V_390 ) ;
return - V_240 ;
}
for ( V_19 = 0 ; V_19 < V_506 ; V_19 ++ ) {
V_468 = F_181 ( V_6 -> V_261 ,
sizeof( struct V_421 ) ,
& V_469 ) ;
if ( ! V_468 ) {
F_27 (KERN_ERR DRV_NAME
L_218 L_163 ,
priv->net_dev->name) ;
V_63 = - V_240 ;
break;
}
V_6 -> V_505 [ V_19 ] . type = V_400 ;
V_6 -> V_505 [ V_19 ] . V_81 . V_410 . V_37 =
(struct V_421 * ) V_468 ;
V_6 -> V_505 [ V_19 ] . V_81 . V_410 . V_442 = V_469 ;
V_6 -> V_505 [ V_19 ] . V_81 . V_410 . V_411 = NULL ;
}
if ( V_19 == V_506 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_19 ; V_40 ++ ) {
F_182 ( V_6 -> V_261 ,
sizeof( struct V_421 ) ,
V_6 -> V_505 [ V_40 ] . V_81 . V_410 . V_37 ,
V_6 -> V_505 [ V_40 ] . V_81 . V_410 .
V_442 ) ;
}
F_132 ( V_6 -> V_505 ) ;
V_6 -> V_505 = NULL ;
return V_63 ;
}
static void F_223 ( struct V_5 * V_6 )
{
int V_19 ;
F_31 ( L_42 ) ;
F_184 ( & V_6 -> V_396 ) ;
F_224 ( & V_6 -> V_404 ) ;
F_184 ( & V_6 -> V_424 ) ;
F_184 ( & V_6 -> V_412 ) ;
F_224 ( & V_6 -> V_427 ) ;
F_224 ( & V_6 -> V_413 ) ;
for ( V_19 = 0 ; V_19 < V_506 ; V_19 ++ ) {
if ( V_6 -> V_505 [ V_19 ] . V_81 . V_410 . V_411 ) {
F_165 ( V_6 -> V_505 [ V_19 ] . V_81 . V_410 .
V_411 ) ;
V_6 -> V_505 [ V_19 ] . V_81 . V_410 . V_411 = NULL ;
}
F_48 ( & V_6 -> V_505 [ V_19 ] . V_78 , & V_6 -> V_412 ) ;
}
F_167 ( & V_6 -> V_413 , V_19 ) ;
V_6 -> V_390 . V_399 = 0 ;
V_6 -> V_390 . V_416 = V_6 -> V_390 . V_382 ;
V_6 -> V_390 . V_77 = 0 ;
F_224 ( & V_6 -> V_417 ) ;
F_167 ( & V_6 -> V_417 , V_6 -> V_390 . V_416 ) ;
F_218 ( V_6 , & V_6 -> V_390 ,
V_507 ,
V_508 ,
V_402 ,
V_403 ) ;
F_31 ( L_45 ) ;
}
static void F_225 ( struct V_5 * V_6 )
{
int V_19 ;
F_31 ( L_42 ) ;
F_217 ( V_6 , & V_6 -> V_390 ) ;
if ( ! V_6 -> V_505 )
return;
for ( V_19 = 0 ; V_19 < V_506 ; V_19 ++ ) {
if ( V_6 -> V_505 [ V_19 ] . V_81 . V_410 . V_411 ) {
F_165 ( V_6 -> V_505 [ V_19 ] . V_81 . V_410 .
V_411 ) ;
V_6 -> V_505 [ V_19 ] . V_81 . V_410 . V_411 = NULL ;
}
if ( V_6 -> V_505 [ V_19 ] . V_81 . V_410 . V_37 )
F_182 ( V_6 -> V_261 ,
sizeof( struct V_421 ) ,
V_6 -> V_505 [ V_19 ] . V_81 . V_410 .
V_37 ,
V_6 -> V_505 [ V_19 ] . V_81 . V_410 .
V_442 ) ;
}
F_132 ( V_6 -> V_505 ) ;
V_6 -> V_505 = NULL ;
F_31 ( L_45 ) ;
}
static int F_226 ( struct V_5 * V_6 )
{
int V_19 , V_40 , V_63 = - V_31 ;
F_31 ( L_42 ) ;
V_63 = F_216 ( V_6 , & V_6 -> V_339 , V_327 ) ;
if ( V_63 ) {
F_31 ( L_219 ) ;
return V_63 ;
}
V_63 = F_214 ( V_6 , V_327 ) ;
if ( V_63 ) {
F_31 ( L_220 ) ;
F_217 ( V_6 , & V_6 -> V_339 ) ;
return V_63 ;
}
V_6 -> V_332 = F_134 ( V_327 *
sizeof( struct V_306 ) ,
V_239 ) ;
if ( ! V_6 -> V_332 ) {
F_31 ( L_221 ) ;
F_217 ( V_6 , & V_6 -> V_339 ) ;
F_215 ( V_6 ) ;
return - V_240 ;
}
for ( V_19 = 0 ; V_19 < V_327 ; V_19 ++ ) {
struct V_306 * V_61 = & V_6 -> V_332 [ V_19 ] ;
V_63 = F_128 ( V_6 , V_61 ) ;
if ( F_141 ( V_63 ) ) {
V_63 = - V_240 ;
break;
}
V_6 -> V_339 . V_324 [ V_19 ] . V_340 = V_61 -> V_310 ;
V_6 -> V_339 . V_324 [ V_19 ] . V_406 = V_337 ;
V_6 -> V_323 . V_324 [ V_19 ] . V_358 = 0 ;
}
if ( V_19 == V_327 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_19 ; V_40 ++ ) {
F_145 ( V_6 -> V_261 , V_6 -> V_332 [ V_40 ] . V_310 ,
sizeof( struct V_306 ) ,
V_311 ) ;
F_227 ( V_6 -> V_332 [ V_40 ] . V_307 ) ;
}
F_132 ( V_6 -> V_332 ) ;
V_6 -> V_332 = NULL ;
F_217 ( V_6 , & V_6 -> V_339 ) ;
F_215 ( V_6 ) ;
return V_63 ;
}
static void F_228 ( struct V_5 * V_6 )
{
F_31 ( L_42 ) ;
V_6 -> V_339 . V_399 = 0 ;
V_6 -> V_339 . V_416 = V_6 -> V_339 . V_382 - 1 ;
V_6 -> V_339 . V_77 = V_6 -> V_339 . V_382 - 1 ;
F_224 ( & V_6 -> V_509 ) ;
F_167 ( & V_6 -> V_509 , V_6 -> V_339 . V_416 ) ;
F_218 ( V_6 , & V_6 -> V_339 ,
V_510 ,
V_511 ,
V_380 ,
V_381 ) ;
F_5 ( V_6 -> V_33 , V_512 ,
V_6 -> V_323 . V_405 ) ;
F_31 ( L_45 ) ;
}
static void F_229 ( struct V_5 * V_6 )
{
int V_19 ;
F_31 ( L_42 ) ;
F_217 ( V_6 , & V_6 -> V_339 ) ;
F_215 ( V_6 ) ;
if ( ! V_6 -> V_332 )
return;
for ( V_19 = 0 ; V_19 < V_327 ; V_19 ++ ) {
if ( V_6 -> V_332 [ V_19 ] . V_309 ) {
F_145 ( V_6 -> V_261 ,
V_6 -> V_332 [ V_19 ] . V_310 ,
sizeof( struct V_308 ) ,
V_311 ) ;
F_227 ( V_6 -> V_332 [ V_19 ] . V_307 ) ;
}
}
F_132 ( V_6 -> V_332 ) ;
V_6 -> V_332 = NULL ;
F_31 ( L_45 ) ;
}
static int F_230 ( struct V_5 * V_6 )
{
T_1 V_287 = V_230 ;
T_3 V_8 [ V_230 ] ;
int V_63 ;
V_63 = F_26 ( V_6 , V_513 , V_8 , & V_287 ) ;
if ( V_63 ) {
F_31 ( L_222 ) ;
return - V_70 ;
}
memcpy ( V_6 -> V_33 -> V_514 , V_8 , V_230 ) ;
F_31 ( L_223 , V_6 -> V_33 -> V_514 ) ;
return 0 ;
}
static int F_231 ( struct V_5 * V_6 , int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_515 ,
. V_88 = 0 ,
. V_65 = V_230
} ;
int V_63 ;
F_42 ( L_224 ) ;
F_31 ( L_42 ) ;
if ( V_6 -> V_187 & V_516 ) {
memcpy ( V_57 . V_67 , V_6 -> V_229 , V_230 ) ;
memcpy ( V_6 -> V_33 -> V_514 , V_6 -> V_229 , V_230 ) ;
} else
memcpy ( V_57 . V_67 , V_6 -> V_33 -> V_514 ,
V_230 ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
F_31 ( L_45 ) ;
return V_63 ;
}
static int F_232 ( struct V_5 * V_6 , T_1 V_517 ,
int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_518 ,
. V_88 = 0 ,
. V_65 = sizeof( T_1 )
} ;
int V_63 ;
switch ( V_517 ) {
case V_429 :
V_57 . V_67 [ 0 ] = V_519 ;
break;
case V_434 :
V_57 . V_67 [ 0 ] = V_520 ;
break;
}
F_42 ( L_225 ,
V_517 == V_520 ? L_226 : L_227 ) ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_288 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_233 ( struct V_5 * V_6 , T_1 V_245 ,
int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_521 ,
. V_88 = 0 ,
. V_65 = sizeof( T_1 )
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_245 ;
F_42 ( L_228 , V_245 ) ;
if ( V_6 -> V_150 -> V_198 == V_429 )
return 0 ;
if ( ( V_245 != 0 ) &&
( ( V_245 < V_522 ) || ( V_245 > V_523 ) ) )
return - V_31 ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 ) {
F_31 ( L_229 , V_245 ) ;
return V_63 ;
}
if ( V_245 )
V_6 -> V_187 |= V_524 ;
else
V_6 -> V_187 &= ~ V_524 ;
V_6 -> V_245 = V_245 ;
if ( ! V_288 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static int F_234 ( struct V_5 * V_6 , int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_525 ,
. V_88 = 0 ,
. V_65 = 12 ,
} ;
T_1 V_526 , V_14 = sizeof( T_1 ) ;
int V_63 ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
if ( V_6 -> V_150 -> V_198 == V_434 )
V_57 . V_67 [ 0 ] |= V_527 ;
V_57 . V_67 [ 0 ] |= V_528 |
V_529 | V_530 ;
if ( ! ( V_6 -> V_187 & V_531 ) )
V_57 . V_67 [ 0 ] |= V_532 ;
V_63 = F_26 ( V_6 ,
V_533 ,
& V_526 , & V_14 ) ;
if ( V_63 )
V_526 = V_534 ;
V_57 . V_67 [ 1 ] = V_535 ;
V_57 . V_67 [ 2 ] = V_535 & V_526 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
#if ! F_235 ( V_536 ) && ! F_235 ( V_537 )
V_57 . V_56 = V_538 ;
V_57 . V_88 = 0 ;
V_57 . V_65 = 0 ;
F_41 ( V_6 , & V_57 ) ;
#endif
if ( ! V_288 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static int F_236 ( struct V_5 * V_6 , T_1 V_539 ,
int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_540 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_539 & V_541 ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
F_41 ( V_6 , & V_57 ) ;
V_57 . V_56 = V_542 ;
F_41 ( V_6 , & V_57 ) ;
V_57 . V_56 = V_543 ;
F_41 ( V_6 , & V_57 ) ;
if ( ! V_288 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_6 -> V_544 = V_539 ;
return 0 ;
}
static int F_237 ( struct V_5 * V_6 , int V_545 )
{
struct V_56 V_57 = {
. V_56 = V_546 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_545 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
if ( V_545 == V_547 )
V_6 -> V_548 = F_238 ( V_6 -> V_548 ) ;
else
V_6 -> V_548 = V_549 | V_545 ;
#ifdef F_239
if ( V_6 -> V_517 == V_550 && V_6 -> V_551 != V_552 ) {
V_57 . V_56 = V_553 ;
V_57 . V_67 [ 0 ] = ( T_1 ) V_6 -> V_551 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
}
#endif
return 0 ;
}
static int F_240 ( struct V_5 * V_6 , T_1 V_554 )
{
struct V_56 V_57 = {
. V_56 = V_555 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
if ( V_554 & V_556 )
V_57 . V_67 [ 0 ] = V_557 ;
else
V_57 . V_67 [ 0 ] = V_554 & ~ V_556 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_558 = V_554 ;
return 0 ;
}
static int F_241 ( struct V_5 * V_6 , T_1 V_559 )
{
struct V_56 V_57 = {
. V_56 = V_560 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_559 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_561 = V_559 ;
return 0 ;
}
static int F_242 ( struct V_5 * V_6 , T_1 V_559 )
{
struct V_56 V_57 = {
. V_56 = V_562 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_559 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_563 = V_559 ;
return 0 ;
}
static int F_243 ( struct V_5 * V_6 , T_3 * V_274 ,
int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_564 ,
. V_88 = 0 ,
. V_65 = ( V_274 == NULL ) ? 0 : V_230
} ;
int V_63 ;
#ifdef F_127
if ( V_274 != NULL )
F_42 ( L_230 , V_274 ) ;
else
F_42 ( L_231 ) ;
#endif
if ( V_274 != NULL )
memcpy ( V_57 . V_67 , V_274 , V_230 ) ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_288 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_244 ( struct V_5 * V_6 )
{
struct V_56 V_57 = {
. V_56 = V_565 ,
. V_88 = 0 ,
. V_65 = V_230
} ;
int V_63 ;
int V_14 ;
F_42 ( L_232 ) ;
V_14 = V_230 ;
memcpy ( V_57 . V_67 , V_6 -> V_274 , V_230 ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
return V_63 ;
}
static int F_245 ( struct V_5 * V_6 ,
struct V_566 * V_567 ,
int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_568 ,
. V_88 = 0 ,
. V_65 = sizeof( struct V_566 ) ,
} ;
int V_63 ;
F_42 ( L_233 ) ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
memcpy ( V_57 . V_67 , V_567 ,
sizeof( struct V_566 ) ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_288 ) {
if ( F_83 ( V_6 ) )
V_63 = - V_70 ;
}
return V_63 ;
}
static int F_246 ( struct V_5 * V_6 ,
int V_569 ,
int V_570 ,
int V_571 ,
int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_572 ,
. V_88 = 0 ,
. V_65 = sizeof(struct V_573 )
} ;
struct V_573 * V_574 =
(struct V_573 * ) & V_57 . V_67 ;
int V_63 ;
memset ( V_574 , 0 , sizeof( * V_574 ) ) ;
V_574 -> V_569 = V_569 ;
V_574 -> V_571 = V_571 ;
switch ( V_570 ) {
default:
case V_575 :
V_574 -> V_576 = V_577 ;
break;
case V_578 :
V_574 -> V_576 = V_579 |
V_580 ;
break;
case V_581 :
V_574 -> V_576 = V_579 |
V_580 | V_582 ;
break;
case V_583 :
V_574 -> V_576 = V_579 |
V_580 | V_584 ;
break;
case V_585 :
V_574 -> V_576 = V_579 |
V_580 | V_582 | V_586 ;
break;
}
F_42
( L_234 ,
V_574 -> V_569 , V_574 -> V_576 , V_570 ) ;
V_574 -> V_587 = 0 ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_288 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_247 ( struct V_5 * V_6 , T_1 V_588 )
{
struct V_56 V_57 = {
. V_56 = V_553 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 = 0 ;
T_1 V_316 = V_588 ;
if ( V_588 != V_589 )
V_316 = ( V_588 - V_590 ) * 16 /
( V_591 - V_590 ) ;
V_57 . V_67 [ 0 ] = V_316 ;
if ( V_6 -> V_150 -> V_198 == V_434 )
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_63 )
V_6 -> V_588 = V_588 ;
return 0 ;
}
static int F_248 ( struct V_5 * V_6 ,
T_1 V_592 , int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_593 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_592 ;
F_31 ( L_42 ) ;
if ( V_6 -> V_150 -> V_198 == V_434 ) {
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
F_41 ( V_6 , & V_57 ) ;
if ( ! V_288 ) {
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
F_223 ( V_6 ) ;
F_228 ( V_6 ) ;
F_183 ( V_6 ) ;
}
static void F_249 ( struct V_5 * V_6 )
{
F_225 ( V_6 ) ;
F_229 ( V_6 ) ;
F_185 ( V_6 ) ;
}
static int F_250 ( struct V_5 * V_6 )
{
if ( F_222 ( V_6 ) ||
F_226 ( V_6 ) || F_180 ( V_6 ) )
goto V_123;
return 0 ;
V_123:
F_225 ( V_6 ) ;
F_229 ( V_6 ) ;
F_185 ( V_6 ) ;
return - V_240 ;
}
static int F_251 ( struct V_5 * V_6 , T_1 V_62 ,
int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_594 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_62 ;
F_42 ( L_235 , V_62 ) ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_288 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_252 ( struct V_5 * V_6 ,
int V_595 , char * V_596 , int V_14 , int V_288 )
{
int V_597 = V_14 ? ( V_14 <= 5 ? 5 : 13 ) : 0 ;
struct V_56 V_57 = {
. V_56 = V_598 ,
. V_88 = 0 ,
. V_65 = sizeof( struct V_599 ) ,
} ;
struct V_599 * V_600 = ( void * ) V_57 . V_67 ;
int V_63 ;
F_42 ( L_236 ,
V_595 , V_597 , V_14 ) ;
V_600 -> V_595 = V_595 ;
V_600 -> V_14 = V_597 ;
if ( V_597 ) {
memcpy ( V_600 -> V_596 , V_596 , V_14 ) ;
memset ( V_600 -> V_596 + V_14 , 0 , V_597 - V_14 ) ;
}
if ( V_597 == 0 )
F_253 ( L_237 ,
V_6 -> V_33 -> V_51 , V_600 -> V_595 ) ;
else if ( V_597 == 5 )
F_253 ( L_238 V_601 L_166 ,
V_6 -> V_33 -> V_51 , V_600 -> V_595 , V_600 -> V_14 ,
F_254 ( V_600 -> V_596 ) ) ;
else
F_253 ( L_238 V_602
L_166 ,
V_6 -> V_33 -> V_51 , V_600 -> V_595 , V_600 -> V_14 ,
F_255 ( V_600 -> V_596 ) ) ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_288 ) {
int V_603 = F_83 ( V_6 ) ;
if ( V_63 == 0 )
V_63 = V_603 ;
}
return V_63 ;
}
static int F_256 ( struct V_5 * V_6 ,
int V_595 , int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_604 ,
. V_88 = 0 ,
. V_65 = 4 ,
. V_67 = { V_595 } ,
} ;
int V_63 ;
F_42 ( L_239 , V_595 ) ;
if ( V_595 < 0 || V_595 > 3 )
return - V_31 ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_288 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_257 ( struct V_5 * V_6 , int V_288 )
{
int V_19 , V_63 , V_569 , V_605 , V_606 ;
if ( ! ( V_6 -> V_49 & V_72 ) )
return 0 ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
if ( ! V_6 -> V_150 -> V_190 . V_192 ) {
V_63 =
F_246 ( V_6 , V_607 ,
V_575 , 0 , 1 ) ;
} else {
V_569 = V_607 ;
if ( V_6 -> V_150 -> V_190 . V_62 & V_608 ) {
if ( V_6 -> V_150 -> V_190 . V_569 == V_609 )
V_569 = V_610 ;
else if ( V_6 -> V_150 -> V_190 . V_569 == V_611 )
V_569 = V_612 ;
}
V_605 = V_575 ;
if ( V_6 -> V_150 -> V_190 . V_62 & V_613 )
V_605 = V_6 -> V_150 -> V_190 . V_43 ;
V_606 = 0 ;
if ( V_6 -> V_150 -> V_190 . V_62 & V_614 )
V_606 = V_6 -> V_150 -> V_190 . V_615 ;
V_63 =
F_246 ( V_6 , V_569 , V_605 ,
V_606 , 1 ) ;
}
if ( V_63 )
goto exit;
if ( V_6 -> V_150 -> V_190 . V_192 ) {
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
if ( ! ( V_6 -> V_150 -> V_190 . V_62 & ( 1 << V_19 ) ) ) {
memset ( V_6 -> V_150 -> V_190 . V_616 [ V_19 ] , 0 , V_617 ) ;
V_6 -> V_150 -> V_190 . V_618 [ V_19 ] = 0 ;
} else {
V_63 = F_252 ( V_6 , V_19 ,
V_6 -> V_150 -> V_190 . V_616 [ V_19 ] ,
V_6 -> V_150 -> V_190 .
V_618 [ V_19 ] , 1 ) ;
if ( V_63 )
goto exit;
}
}
F_256 ( V_6 , V_6 -> V_150 -> V_493 . V_495 , 1 ) ;
}
V_63 =
F_251 ( V_6 ,
V_6 -> V_150 -> V_190 .
V_192 ? V_619 : 0 , 1 ) ;
if ( V_63 )
goto exit;
V_6 -> V_49 &= ~ V_265 ;
exit:
if ( ! V_288 )
F_83 ( V_6 ) ;
return V_63 ;
}
static void F_258 ( struct V_262 * V_263 )
{
struct V_5 * V_6 =
F_108 ( V_263 , struct V_5 , V_295 . V_263 ) ;
if ( ! ( V_6 -> V_49 & V_166 ) &&
V_6 -> V_49 & V_265 )
F_257 ( V_6 , 0 ) ;
}
static void F_259 ( struct V_1 * V_2 ,
struct V_620 * V_190 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_19 , V_621 = 0 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) )
goto V_623;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
if ( V_190 -> V_62 & ( 1 << V_19 ) ) {
V_6 -> V_150 -> V_190 . V_618 [ V_19 ] = V_190 -> V_618 [ V_19 ] ;
if ( V_190 -> V_618 [ V_19 ] == 0 )
V_6 -> V_150 -> V_190 . V_62 &= ~ ( 1 << V_19 ) ;
else
memcpy ( V_6 -> V_150 -> V_190 . V_616 [ V_19 ] , V_190 -> V_616 [ V_19 ] ,
V_190 -> V_618 [ V_19 ] ) ;
if ( V_190 -> V_43 == V_578 ) {
V_6 -> V_150 -> V_190 . V_62 |= ( 1 << V_19 ) ;
V_6 -> V_49 |= V_265 ;
} else
V_6 -> V_150 -> V_190 . V_62 &= ~ ( 1 << V_19 ) ;
}
}
if ( ( V_190 -> V_62 & V_624 ) &&
V_6 -> V_150 -> V_190 . V_625 != V_190 -> V_625 ) {
if ( V_190 -> V_625 <= 3 ) {
V_6 -> V_150 -> V_190 . V_625 = V_190 -> V_625 ;
V_6 -> V_150 -> V_190 . V_62 |= V_624 ;
} else
V_6 -> V_150 -> V_190 . V_62 &= ~ V_624 ;
V_6 -> V_49 |= V_265 ;
}
if ( ( V_190 -> V_62 & V_608 ) &&
( V_6 -> V_150 -> V_190 . V_569 != V_190 -> V_569 ) ) {
V_6 -> V_150 -> V_190 . V_569 = V_190 -> V_569 ;
V_6 -> V_150 -> V_190 . V_62 |= V_608 ;
V_6 -> V_49 |= V_265 ;
}
if ( V_190 -> V_62 & V_191 && V_6 -> V_150 -> V_190 . V_192 != V_190 -> V_192 ) {
V_6 -> V_150 -> V_190 . V_62 |= V_191 ;
V_6 -> V_150 -> V_190 . V_192 = V_190 -> V_192 ;
V_6 -> V_49 |= V_265 ;
V_621 = 1 ;
}
if ( V_190 -> V_62 & V_626 )
V_6 -> V_150 -> V_190 . V_627 = V_190 -> V_627 ;
if ( V_190 -> V_62 & V_613 && V_6 -> V_150 -> V_190 . V_43 != V_190 -> V_43 ) {
V_6 -> V_150 -> V_190 . V_43 = V_190 -> V_43 ;
V_6 -> V_150 -> V_190 . V_62 |= V_613 ;
V_6 -> V_49 |= V_265 ;
}
F_253 ( L_240 ,
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
F_257 ( V_6 , 0 ) ;
V_623:
F_85 ( & V_6 -> V_266 ) ;
}
static int F_98 ( struct V_5 * V_6 )
{
int V_63 ;
int V_288 = 1 ;
T_3 * V_274 ;
F_31 ( L_42 ) ;
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
#ifdef F_157
if ( V_6 -> V_150 -> V_198 == V_199 ) {
V_63 = F_233 ( V_6 , V_6 -> V_245 , V_288 ) ;
if ( V_63 )
return V_63 ;
F_31 ( L_45 ) ;
return 0 ;
}
#endif
V_63 = F_230 ( V_6 ) ;
if ( V_63 )
return - V_70 ;
V_63 = F_231 ( V_6 , V_288 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_232 ( V_6 , V_6 -> V_150 -> V_198 , V_288 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_150 -> V_198 == V_434 ) {
V_63 = F_233 ( V_6 , V_6 -> V_245 , V_288 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_234 ( V_6 , V_288 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_236 ( V_6 , V_6 -> V_544 , V_288 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_237 ( V_6 , V_547 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_240 ( V_6 , V_6 -> V_558 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_187 & V_628 )
V_274 = V_6 -> V_274 ;
else
V_274 = NULL ;
V_63 = F_243 ( V_6 , V_274 , V_288 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_187 & V_284 )
V_63 = F_113 ( V_6 , V_6 -> V_269 , V_6 -> V_268 ,
V_288 ) ;
else
V_63 = F_113 ( V_6 , NULL , 0 , V_288 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_257 ( V_6 , V_288 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_150 -> V_198 == V_434 ) {
V_63 =
F_248 ( V_6 ,
V_6 -> V_629 ,
V_288 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_247 ( V_6 , V_6 -> V_588 ) ;
if ( V_63 )
return V_63 ;
}
F_31 ( L_45 ) ;
return 0 ;
}
static int F_260 ( struct V_1 * V_2 , void * V_469 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_630 * V_8 = V_469 ;
int V_63 = 0 ;
if ( ! F_261 ( V_8 -> V_631 ) )
return - V_632 ;
F_84 ( & V_6 -> V_266 ) ;
V_6 -> V_187 |= V_516 ;
memcpy ( V_6 -> V_229 , V_8 -> V_631 , V_230 ) ;
V_63 = F_231 ( V_6 , 0 ) ;
if ( V_63 )
goto V_623;
V_6 -> V_47 = 0 ;
F_85 ( & V_6 -> V_266 ) ;
F_107 ( & V_6 -> V_52 . V_263 ) ;
return 0 ;
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_262 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_62 ;
F_31 ( L_241 ) ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( V_6 -> V_49 & V_166 ) {
F_263 ( V_2 ) ;
F_264 ( V_2 ) ;
}
F_52 ( & V_6 -> V_68 , V_62 ) ;
return 0 ;
}
static int F_265 ( struct V_1 * V_2 )
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
while ( ! F_44 ( & V_6 -> V_424 ) ) {
V_59 = V_6 -> V_424 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_427 ) ;
F_165 ( V_61 -> V_81 . V_410 . V_411 ) ;
V_61 -> V_81 . V_410 . V_411 = NULL ;
F_48 ( V_59 , & V_6 -> V_412 ) ;
F_49 ( & V_6 -> V_413 ) ;
}
F_52 ( & V_6 -> V_68 , V_62 ) ;
F_31 ( L_45 ) ;
return 0 ;
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_2 -> V_329 . V_633 ++ ;
#ifdef F_157
if ( V_6 -> V_150 -> V_198 == V_199 )
return;
#endif
F_31 ( L_242 ,
V_2 -> V_51 ) ;
F_35 ( V_6 ) ;
}
static int F_267 ( struct V_5 * V_6 , int V_147 )
{
V_6 -> V_150 -> V_634 = V_147 ;
return 0 ;
}
static int F_268 ( struct V_5 * V_6 , int V_147 )
{
struct V_635 * V_150 = V_6 -> V_150 ;
struct V_620 V_190 = {
. V_62 = V_608 ,
} ;
int V_267 = 0 ;
if ( V_147 & V_636 ) {
V_190 . V_569 = V_609 ;
V_150 -> V_637 = 0 ;
} else if ( V_147 & V_638 ) {
V_190 . V_569 = V_639 ;
V_150 -> V_637 = 1 ;
} else if ( V_147 & V_640 ) {
V_190 . V_569 = V_611 ;
V_150 -> V_637 = 1 ;
} else
return - V_31 ;
if ( V_150 -> V_641 )
V_150 -> V_641 ( V_150 -> V_2 , & V_190 ) ;
else
V_267 = - V_642 ;
return V_267 ;
}
static void V_566 ( struct V_5 * V_6 ,
char * V_643 , int V_644 )
{
struct V_566 V_645 ;
V_645 . V_646 = 0 ;
memcpy ( V_645 . V_647 , V_643 , V_644 ) ;
V_645 . V_648 = V_644 ;
F_267 ( V_6 , 1 ) ;
F_245 ( V_6 , & V_645 , 0 ) ;
}
static void F_269 ( struct V_1 * V_2 ,
struct V_649 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char V_650 [ 64 ] , V_651 [ 64 ] ;
F_270 ( V_81 -> V_652 , V_653 , sizeof( V_81 -> V_652 ) ) ;
F_270 ( V_81 -> V_121 , V_654 , sizeof( V_81 -> V_121 ) ) ;
F_271 ( V_6 , V_650 , sizeof( V_650 ) ) ;
F_272 ( V_6 , V_651 , sizeof( V_651 ) ) ;
snprintf ( V_81 -> V_655 , sizeof( V_81 -> V_655 ) , L_243 ,
V_650 , V_6 -> V_156 , V_651 ) ;
F_270 ( V_81 -> V_656 , F_273 ( V_6 -> V_261 ) ,
sizeof( V_81 -> V_656 ) ) ;
}
static T_1 F_274 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return ( V_6 -> V_49 & V_166 ) ? 1 : 0 ;
}
static void F_275 ( struct V_262 * V_263 )
{
struct V_5 * V_6 =
F_108 ( V_263 , struct V_5 , V_182 . V_263 ) ;
unsigned long V_62 ;
T_1 V_657 = 0xa5a5a5a5 ;
T_1 V_14 = sizeof( V_657 ) ;
int V_658 = 0 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( V_6 -> V_69 != 0 ) {
F_31 ( L_244 ,
V_6 -> V_33 -> V_51 ) ;
V_658 = 1 ;
} else if ( F_26 ( V_6 , V_659 , & V_657 , & V_14 ) ||
( V_657 == V_6 -> V_496 ) ) {
F_31 ( L_245 ,
V_6 -> V_33 -> V_51 ) ;
V_658 = 1 ;
}
if ( V_658 ) {
V_6 -> V_181 = 1 ;
V_6 -> V_490 ++ ;
F_35 ( V_6 ) ;
}
V_6 -> V_496 = V_657 ;
if ( ! V_6 -> V_181 )
F_39 ( & V_6 -> V_182 , V_53 / 2 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
}
static void F_276 ( struct V_262 * V_263 )
{
struct V_5 * V_6 =
F_108 ( V_263 , struct V_5 , V_216 . V_263 ) ;
unsigned long V_62 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( F_71 ( V_6 ) ) {
F_212 ( L_246 ) ;
if ( ! V_6 -> V_215 )
F_39 ( & V_6 -> V_216 ,
F_97 ( V_53 ) ) ;
goto V_660;
}
if ( ! ( V_6 -> V_49 & V_487 ) ) {
F_212 ( L_247
L_248 ) ;
F_35 ( V_6 ) ;
} else
F_212 ( L_249
L_250 ) ;
V_660:
F_52 ( & V_6 -> V_68 , V_62 ) ;
}
static struct V_1 * F_277 ( struct V_261 * V_261 ,
void T_12 * V_7 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_278 ( sizeof( struct V_5 ) , 0 ) ;
if ( ! V_2 )
return NULL ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_150 = F_279 ( V_2 ) ;
V_6 -> V_261 = V_261 ;
V_6 -> V_33 = V_2 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_150 -> V_661 = F_179 ;
V_6 -> V_150 -> V_641 = F_259 ;
V_6 -> V_150 -> V_662 = - 20 ;
V_6 -> V_150 -> V_663 = - 85 ;
V_2 -> V_664 = & V_665 ;
V_2 -> V_666 = & V_667 ;
V_2 -> V_668 = & V_669 ;
V_6 -> V_670 . V_671 = V_6 -> V_150 ;
V_2 -> V_670 = & V_6 -> V_670 ;
V_2 -> V_672 = 3 * V_53 ;
V_2 -> V_457 = 0 ;
V_6 -> V_548 = V_673 ;
#ifdef F_157
V_6 -> V_187 |= V_346 ;
#endif
V_6 -> V_150 -> V_634 = 0 ;
V_6 -> V_150 -> V_674 = 0 ;
V_6 -> V_150 -> V_675 = 0 ;
V_6 -> V_150 -> V_676 = 1 ;
switch ( V_677 ) {
case 1 :
V_6 -> V_150 -> V_198 = V_434 ;
break;
#ifdef F_157
case 2 :
V_6 -> V_150 -> V_198 = V_199 ;
break;
#endif
default:
case 0 :
V_6 -> V_150 -> V_198 = V_429 ;
break;
}
if ( V_678 == 1 )
V_6 -> V_49 |= V_206 ;
if ( V_245 != 0 &&
( ( V_245 >= V_522 ) && ( V_245 <= V_523 ) ) ) {
V_6 -> V_187 |= V_524 ;
V_6 -> V_245 = V_245 ;
}
if ( V_679 )
V_6 -> V_187 |= V_188 ;
V_6 -> V_629 = V_680 ;
V_6 -> V_561 = V_681 ;
V_6 -> V_563 = V_682 ;
V_6 -> V_558 = V_683 | V_556 ;
V_6 -> V_684 = V_685 | V_686 ;
V_6 -> V_588 = V_589 ;
V_6 -> V_544 = V_687 ;
strcpy ( V_6 -> V_688 , L_251 ) ;
F_280 ( & V_6 -> V_68 ) ;
F_281 ( & V_6 -> V_266 ) ;
F_281 ( & V_6 -> V_179 ) ;
F_282 ( & V_6 -> V_55 ) ;
F_37 ( V_2 ) ;
F_184 ( & V_6 -> V_75 ) ;
F_184 ( & V_6 -> V_91 ) ;
F_224 ( & V_6 -> V_90 ) ;
F_224 ( & V_6 -> V_92 ) ;
F_184 ( & V_6 -> V_412 ) ;
F_184 ( & V_6 -> V_424 ) ;
F_224 ( & V_6 -> V_413 ) ;
F_224 ( & V_6 -> V_427 ) ;
F_184 ( & V_6 -> V_396 ) ;
F_224 ( & V_6 -> V_404 ) ;
F_283 ( & V_6 -> V_52 , F_107 ) ;
F_283 ( & V_6 -> V_295 , F_258 ) ;
F_283 ( & V_6 -> V_286 , V_689 ) ;
F_283 ( & V_6 -> V_182 , F_275 ) ;
F_283 ( & V_6 -> V_216 , F_276 ) ;
F_284 ( & V_6 -> V_298 , F_119 ) ;
F_283 ( & V_6 -> V_297 , F_118 ) ;
F_285 ( & V_6 -> V_460 , ( void (*) ( unsigned long ) )
F_172 , ( unsigned long ) V_6 ) ;
V_6 -> V_215 = 1 ;
V_6 -> V_181 = 1 ;
return V_2 ;
}
static int F_286 ( struct V_261 * V_261 ,
const struct V_690 * V_691 )
{
void T_12 * V_7 ;
struct V_1 * V_2 = NULL ;
struct V_5 * V_6 = NULL ;
int V_63 = 0 ;
int V_692 = 0 ;
T_1 V_4 ;
F_31 ( L_42 ) ;
if ( ! ( F_287 ( V_261 , 0 ) & V_693 ) ) {
F_31 ( L_252 ) ;
V_63 = - V_694 ;
goto V_39;
}
V_7 = F_288 ( V_261 , 0 , 0 ) ;
if ( ! V_7 ) {
F_27 (KERN_WARNING DRV_NAME
L_253 ) ;
V_63 = - V_70 ;
goto V_123;
}
V_2 = F_277 ( V_261 , V_7 ) ;
if ( ! V_2 ) {
F_27 (KERN_WARNING DRV_NAME
L_254 ) ;
V_63 = - V_240 ;
goto V_123;
}
V_63 = F_289 ( V_261 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_255 ) ;
return V_63 ;
}
V_6 = F_2 ( V_2 ) ;
F_290 ( V_261 ) ;
F_291 ( V_261 , V_6 ) ;
V_63 = F_292 ( V_261 , F_293 ( 32 ) ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_256 ) ;
F_294 ( V_261 ) ;
return V_63 ;
}
V_63 = F_295 ( V_261 , V_653 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_257 ) ;
F_294 ( V_261 ) ;
return V_63 ;
}
F_187 ( V_261 , 0x40 , & V_4 ) ;
if ( ( V_4 & 0x0000ff00 ) != 0 )
F_296 ( V_261 , 0x40 , V_4 & 0xffff00ff ) ;
F_297 ( V_261 , V_695 ) ;
if ( ! F_25 ( V_2 ) ) {
F_27 (KERN_WARNING DRV_NAME
L_258 ) ;
V_63 = - V_694 ;
goto V_123;
}
F_298 ( V_2 , & V_261 -> V_2 ) ;
V_6 -> V_49 |= V_136 ;
F_68 ( V_6 ) ;
if ( F_250 ( V_6 ) ) {
F_27 (KERN_WARNING DRV_NAME
L_259 ) ;
V_63 = - V_240 ;
goto V_123;
}
F_77 ( V_6 ) ;
V_63 = F_299 ( V_261 -> V_457 ,
F_175 , V_696 , V_2 -> V_51 , V_6 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_260 , pci_dev->irq) ;
goto V_123;
}
V_2 -> V_457 = V_261 -> V_457 ;
F_31 ( L_261 ) ;
F_27 (KERN_INFO DRV_NAME
L_262 ) ;
V_63 = F_93 ( V_6 , 1 ) ;
if ( V_63 )
goto V_123;
V_63 = F_101 ( V_2 ) ;
if ( V_63 )
goto V_123;
V_692 = 1 ;
V_63 = F_300 ( V_2 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_263 ) ;
goto V_123;
}
V_692 = 2 ;
F_84 ( & V_6 -> V_266 ) ;
F_31 ( L_264 , V_2 -> V_51 , F_273 ( V_261 ) ) ;
V_63 = F_301 ( & V_261 -> V_2 . V_697 , & V_698 ) ;
if ( V_63 )
goto V_71;
if ( ! ( V_6 -> V_49 & V_487 ) ) {
if ( F_83 ( V_6 ) ) {
F_27 (KERN_WARNING DRV_NAME
L_265 ,
priv->net_dev->name) ;
F_86 ( V_6 ) ;
V_63 = - V_70 ;
goto V_71;
}
F_90 ( V_6 ) ;
F_92 ( V_6 ) ;
}
F_31 ( L_45 ) ;
V_6 -> V_49 |= V_622 ;
F_85 ( & V_6 -> V_266 ) ;
V_39:
return V_63 ;
V_71:
F_85 ( & V_6 -> V_266 ) ;
V_123:
if ( V_2 ) {
if ( V_692 >= 2 )
F_302 ( V_2 ) ;
if ( V_692 ) {
F_303 ( V_6 -> V_150 -> V_151 . V_152 ) ;
F_132 ( V_6 -> V_150 -> V_233 . V_237 ) ;
}
F_86 ( V_6 ) ;
F_68 ( V_6 ) ;
if ( V_2 -> V_457 )
F_304 ( V_2 -> V_457 , V_6 ) ;
F_219 ( V_6 ) ;
F_249 ( V_6 ) ;
F_305 ( & V_261 -> V_2 . V_697 ,
& V_698 ) ;
F_306 ( V_2 , 0 ) ;
F_291 ( V_261 , NULL ) ;
}
F_307 ( V_261 , V_7 ) ;
F_308 ( V_261 ) ;
F_294 ( V_261 ) ;
goto V_39;
}
static void T_13 F_309 ( struct V_261 * V_261 )
{
struct V_5 * V_6 = F_310 ( V_261 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
F_84 ( & V_6 -> V_266 ) ;
V_6 -> V_49 &= ~ V_622 ;
F_305 ( & V_261 -> V_2 . V_697 , & V_698 ) ;
#ifdef F_61
if ( V_120 . V_121 )
F_66 ( V_6 , & V_120 ) ;
#endif
F_99 ( V_6 ) ;
F_85 ( & V_6 -> V_266 ) ;
F_302 ( V_2 ) ;
F_219 ( V_6 ) ;
F_249 ( V_6 ) ;
F_131 ( V_6 ) ;
F_304 ( V_2 -> V_457 , V_6 ) ;
F_307 ( V_261 , V_6 -> V_7 ) ;
F_303 ( V_6 -> V_150 -> V_151 . V_152 ) ;
F_132 ( V_6 -> V_150 -> V_233 . V_237 ) ;
F_306 ( V_2 , 0 ) ;
F_308 ( V_261 ) ;
F_294 ( V_261 ) ;
F_31 ( L_45 ) ;
}
static int F_311 ( struct V_261 * V_261 , T_14 V_102 )
{
struct V_5 * V_6 = F_310 ( V_261 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
F_31 ( L_266 , V_2 -> V_51 ) ;
F_84 ( & V_6 -> V_266 ) ;
if ( V_6 -> V_49 & V_622 ) {
F_99 ( V_6 ) ;
}
F_312 ( V_2 ) ;
F_313 ( V_261 ) ;
F_294 ( V_261 ) ;
F_297 ( V_261 , V_699 ) ;
V_6 -> V_700 = F_36 () ;
F_85 ( & V_6 -> V_266 ) ;
return 0 ;
}
static int F_314 ( struct V_261 * V_261 )
{
struct V_5 * V_6 = F_310 ( V_261 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
int V_63 ;
T_1 V_4 ;
if ( V_701 )
return 0 ;
F_84 ( & V_6 -> V_266 ) ;
F_31 ( L_267 , V_2 -> V_51 ) ;
F_297 ( V_261 , V_695 ) ;
V_63 = F_289 ( V_261 ) ;
if ( V_63 ) {
F_27 ( V_702 L_268 ,
V_2 -> V_51 ) ;
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
F_315 ( V_261 ) ;
F_187 ( V_261 , 0x40 , & V_4 ) ;
if ( ( V_4 & 0x0000ff00 ) != 0 )
F_296 ( V_261 , 0x40 , V_4 & 0xffff00ff ) ;
F_316 ( V_2 ) ;
V_6 -> V_205 = F_36 () - V_6 -> V_700 ;
if ( ! ( V_6 -> V_49 & V_206 ) )
F_93 ( V_6 , 0 ) ;
F_85 ( & V_6 -> V_266 ) ;
return 0 ;
}
static void F_317 ( struct V_261 * V_261 )
{
struct V_5 * V_6 = F_310 ( V_261 ) ;
F_99 ( V_6 ) ;
F_294 ( V_261 ) ;
}
static int T_15 F_318 ( void )
{
int V_267 ;
F_27 (KERN_INFO DRV_NAME L_269 , DRV_DESCRIPTION, DRV_VERSION) ;
F_27 (KERN_INFO DRV_NAME L_270 , DRV_COPYRIGHT) ;
F_319 ( & V_207 , V_703 ,
V_223 ) ;
V_267 = F_320 ( & V_704 ) ;
if ( V_267 )
goto V_39;
#ifdef F_127
V_44 = V_705 ;
V_267 = F_321 ( & V_704 . V_652 ,
& V_706 ) ;
#endif
V_39:
return V_267 ;
}
static void T_16 F_322 ( void )
{
#ifdef F_127
F_323 ( & V_704 . V_652 ,
& V_706 ) ;
#endif
F_324 ( & V_704 ) ;
F_325 ( & V_207 ) ;
}
static int F_326 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_49 & V_166 ) )
strcpy ( V_218 -> V_51 , L_271 ) ;
else
snprintf ( V_218 -> V_51 , V_709 , L_272 ) ;
F_327 ( L_273 , V_218 -> V_51 ) ;
return 0 ;
}
static int F_328 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_710 * V_711 = & V_218 -> V_243 ;
int V_63 = 0 ;
if ( V_6 -> V_150 -> V_198 == V_429 )
return - V_642 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) ) {
V_63 = - V_70 ;
goto V_623;
}
if ( V_711 -> V_394 == 1 ) {
if ( ( V_711 -> V_712 >= ( int ) 2.412e8 && V_711 -> V_712 <= ( int ) 2.487e8 ) ) {
int V_713 = V_711 -> V_712 / 100000 ;
int V_42 = 0 ;
while ( ( V_42 < V_523 ) &&
( V_713 != V_714 [ V_42 ] ) )
V_42 ++ ;
V_711 -> V_394 = 0 ;
V_711 -> V_712 = V_42 + 1 ;
}
}
if ( V_711 -> V_394 > 0 || V_711 -> V_712 > 1000 ) {
V_63 = - V_642 ;
goto V_623;
} else {
F_327 ( L_274 , V_711 -> V_712 ) ;
V_63 = F_233 ( V_6 , V_711 -> V_712 , 0 ) ;
}
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_329 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_243 . V_394 = 0 ;
if ( V_6 -> V_187 & V_524 ||
V_6 -> V_49 & V_166 )
V_218 -> V_243 . V_712 = V_6 -> V_245 ;
else
V_218 -> V_243 . V_712 = 0 ;
F_327 ( L_275 , V_6 -> V_245 ) ;
return 0 ;
}
static int F_330 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
F_327 ( L_276 , V_218 -> V_315 ) ;
if ( V_218 -> V_315 == V_6 -> V_150 -> V_198 )
return 0 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) ) {
V_63 = - V_70 ;
goto V_623;
}
switch ( V_218 -> V_315 ) {
#ifdef F_157
case V_199 :
V_63 = F_198 ( V_6 , V_199 ) ;
break;
#endif
case V_434 :
V_63 = F_198 ( V_6 , V_434 ) ;
break;
case V_429 :
case V_715 :
default:
V_63 = F_198 ( V_6 , V_429 ) ;
break;
}
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_331 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_315 = V_6 -> V_150 -> V_198 ;
F_327 ( L_277 , V_218 -> V_315 ) ;
return 0 ;
}
static int F_332 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_716 * V_717 = (struct V_716 * ) V_708 ;
T_2 V_4 ;
int V_19 , V_43 ;
V_218 -> V_37 . V_287 = sizeof( * V_717 ) ;
memset ( V_717 , 0 , sizeof( * V_717 ) ) ;
V_717 -> V_718 = 5 * 1000 * 1000 ;
V_717 -> V_719 . V_720 = 100 ;
V_717 -> V_719 . V_43 = 0 ;
V_717 -> V_719 . V_721 = 0 ;
V_717 -> V_719 . V_722 = 7 ;
V_717 -> V_723 . V_720 = 70 ;
V_717 -> V_723 . V_43 = 20 + V_355 ;
V_717 -> V_723 . V_721 = 0 ;
V_717 -> V_723 . V_722 = 7 ;
V_717 -> V_724 = V_256 ;
for ( V_19 = 0 ; V_19 < V_256 && V_19 < V_725 ; V_19 ++ ) {
V_717 -> V_726 [ V_19 ] = V_254 [ V_19 ] . V_726 * 100 * 1000 ;
}
V_717 -> V_727 = V_728 ;
V_717 -> V_729 = V_557 ;
V_717 -> V_730 = V_731 ;
V_717 -> V_732 = V_733 ;
V_717 -> V_734 = V_735 [ 0 ] ;
V_717 -> V_736 = V_735 [ V_737 - 1 ] ;
V_717 -> V_738 = V_739 [ V_737 - 1 ] ;
V_717 -> V_740 = V_739 [ 0 ] ;
V_717 -> V_741 = V_742 ;
V_717 -> V_743 = V_744 ;
V_717 -> V_745 = V_744 | V_742 ;
V_717 -> V_746 [ 0 ] = 5 ;
V_717 -> V_746 [ 1 ] = 13 ;
V_717 -> V_747 = 2 ;
V_717 -> V_748 = V_749 ;
if ( V_6 -> V_150 -> V_198 == V_434 ) {
V_717 -> V_750 = V_751 ;
V_717 -> V_752 = V_753 ;
for ( V_19 = 0 , V_43 = ( V_591 * 16 ) ;
V_19 < V_753 ;
V_19 ++ , V_43 -=
( ( V_591 -
V_590 ) * 16 ) / ( V_753 - 1 ) )
V_717 -> V_754 [ V_19 ] = V_43 / 16 ;
} else {
V_717 -> V_750 = 0 ;
V_717 -> V_752 = 0 ;
}
V_717 -> V_755 = V_756 ;
V_717 -> V_757 = 18 ;
V_717 -> V_758 = V_759 ;
V_4 = 0 ;
for ( V_19 = 0 ; V_19 < V_759 ; V_19 ++ ) {
V_717 -> V_243 [ V_4 ] . V_19 = V_19 + 1 ;
V_717 -> V_243 [ V_4 ] . V_712 = V_714 [ V_19 ] * 100000 ;
V_717 -> V_243 [ V_4 ] . V_394 = 1 ;
V_4 ++ ;
if ( V_4 == V_760 )
break;
}
V_717 -> V_761 = V_4 ;
V_717 -> V_762 [ 0 ] = ( V_763 |
F_333 ( V_224 ) ) ;
V_717 -> V_762 [ 1 ] = V_764 ;
V_717 -> V_765 = V_766 | V_767 |
V_768 | V_769 ;
F_327 ( L_278 ) ;
return 0 ;
}
static int F_334 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
static const unsigned char V_770 [] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
static const unsigned char V_771 [] = {
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00
} ;
if ( V_218 -> V_219 . V_220 != V_221 )
return - V_31 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) ) {
V_63 = - V_70 ;
goto V_623;
}
if ( ! memcmp ( V_770 , V_218 -> V_219 . V_631 , V_230 ) ||
! memcmp ( V_771 , V_218 -> V_219 . V_631 , V_230 ) ) {
F_327 ( L_279 ) ;
V_6 -> V_187 &= ~ V_628 ;
V_63 = F_243 ( V_6 , NULL , 0 ) ;
goto V_623;
}
V_6 -> V_187 |= V_628 ;
memcpy ( V_6 -> V_772 , V_218 -> V_219 . V_631 , V_230 ) ;
V_63 = F_243 ( V_6 , V_218 -> V_219 . V_631 , 0 ) ;
F_327 ( L_280 , V_218 -> V_219 . V_631 ) ;
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_335 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_628 || V_6 -> V_49 & V_166 ) {
V_218 -> V_219 . V_220 = V_221 ;
memcpy ( V_218 -> V_219 . V_631 , V_6 -> V_274 , V_230 ) ;
} else
memset ( V_218 -> V_219 . V_631 , 0 , V_230 ) ;
F_327 ( L_281 , V_218 -> V_219 . V_631 ) ;
return 0 ;
}
static int F_336 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char * V_269 = L_50 ;
int V_287 = 0 ;
int V_63 = 0 ;
F_111 ( V_275 ) ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) ) {
V_63 = - V_70 ;
goto V_623;
}
if ( V_218 -> V_269 . V_62 && V_218 -> V_269 . V_287 ) {
V_287 = V_218 -> V_269 . V_287 ;
V_269 = V_708 ;
}
if ( V_287 == 0 ) {
F_327 ( L_282 ) ;
V_6 -> V_187 &= ~ V_284 ;
V_63 = F_113 ( V_6 , NULL , 0 , 0 ) ;
goto V_623;
}
V_287 = F_34 ( V_287 , V_270 ) ;
V_6 -> V_187 |= V_284 ;
if ( V_6 -> V_268 == V_287 && ! memcmp ( V_6 -> V_269 , V_708 , V_287 ) ) {
F_327 ( L_283 ) ;
V_63 = 0 ;
goto V_623;
}
F_327 ( L_284 ,
F_112 ( V_275 , V_269 , V_287 ) , V_287 ) ;
V_6 -> V_268 = V_287 ;
memcpy ( V_6 -> V_269 , V_269 , V_6 -> V_268 ) ;
V_63 = F_113 ( V_6 , V_269 , V_287 , 0 ) ;
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_337 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_111 ( V_275 ) ;
if ( V_6 -> V_187 & V_284 || V_6 -> V_49 & V_166 ) {
F_327 ( L_285 ,
F_112 ( V_275 , V_6 -> V_269 , V_6 -> V_268 ) ) ;
memcpy ( V_708 , V_6 -> V_269 , V_6 -> V_268 ) ;
V_218 -> V_269 . V_287 = V_6 -> V_268 ;
V_218 -> V_269 . V_62 = 1 ;
} else {
F_327 ( L_286 ) ;
V_218 -> V_269 . V_287 = 0 ;
V_218 -> V_269 . V_62 = 0 ;
}
return 0 ;
}
static int F_338 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_218 -> V_37 . V_287 > V_270 )
return - V_773 ;
V_218 -> V_37 . V_287 = F_34 ( ( T_4 ) V_218 -> V_37 . V_287 , sizeof( V_6 -> V_688 ) ) ;
memset ( V_6 -> V_688 , 0 , sizeof( V_6 -> V_688 ) ) ;
memcpy ( V_6 -> V_688 , V_708 , V_218 -> V_37 . V_287 ) ;
F_327 ( L_287 , V_6 -> V_688 ) ;
return 0 ;
}
static int F_339 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_37 . V_287 = strlen ( V_6 -> V_688 ) ;
memcpy ( V_708 , V_6 -> V_688 , V_218 -> V_37 . V_287 ) ;
V_218 -> V_37 . V_62 = 1 ;
F_327 ( L_288 , V_708 ) ;
return 0 ;
}
static int F_340 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_774 = V_218 -> V_726 . V_147 ;
T_1 V_539 ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) ) {
V_63 = - V_70 ;
goto V_623;
}
V_539 = 0 ;
if ( V_774 == 1000000 ||
( ! V_218 -> V_726 . V_775 && V_774 > 1000000 ) )
V_539 |= V_280 ;
if ( V_774 == 2000000 ||
( ! V_218 -> V_726 . V_775 && V_774 > 2000000 ) )
V_539 |= V_281 ;
if ( V_774 == 5500000 ||
( ! V_218 -> V_726 . V_775 && V_774 > 5500000 ) )
V_539 |= V_282 ;
if ( V_774 == 11000000 ||
( ! V_218 -> V_726 . V_775 && V_774 > 11000000 ) )
V_539 |= V_283 ;
if ( V_539 == 0 )
V_539 = V_687 ;
V_63 = F_236 ( V_6 , V_539 , 0 ) ;
F_327 ( L_289 , V_539 ) ;
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_341 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_4 ;
unsigned int V_14 = sizeof( V_4 ) ;
int V_63 = 0 ;
if ( ! ( V_6 -> V_49 & V_106 ) ||
V_6 -> V_49 & V_487 ||
! ( V_6 -> V_49 & V_166 ) ) {
V_218 -> V_726 . V_147 = 0 ;
return 0 ;
}
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) ) {
V_63 = - V_70 ;
goto V_623;
}
V_63 = F_26 ( V_6 , V_277 , & V_4 , & V_14 ) ;
if ( V_63 ) {
F_327 ( L_290 ) ;
goto V_623;
}
switch ( V_4 & V_541 ) {
case V_280 :
V_218 -> V_726 . V_147 = 1000000 ;
break;
case V_281 :
V_218 -> V_726 . V_147 = 2000000 ;
break;
case V_282 :
V_218 -> V_726 . V_147 = 5500000 ;
break;
case V_283 :
V_218 -> V_726 . V_147 = 11000000 ;
break;
default:
V_218 -> V_726 . V_147 = 0 ;
}
F_327 ( L_291 , V_218 -> V_726 . V_147 ) ;
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_342 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_147 , V_63 ;
if ( V_218 -> V_776 . V_775 == 0 )
return - V_31 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) ) {
V_63 = - V_70 ;
goto V_623;
}
if ( V_218 -> V_776 . V_777 )
V_147 = V_6 -> V_558 | V_556 ;
else {
if ( V_218 -> V_776 . V_147 < 1 || V_218 -> V_776 . V_147 > 2304 ) {
V_63 = - V_31 ;
goto V_623;
}
V_147 = V_218 -> V_776 . V_147 ;
}
V_63 = F_240 ( V_6 , V_147 ) ;
F_327 ( L_292 , V_147 ) ;
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_343 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_776 . V_147 = V_6 -> V_558 & ~ V_556 ;
V_218 -> V_776 . V_775 = 1 ;
V_218 -> V_776 . V_777 = ( V_6 -> V_558 & V_556 ) ? 1 : 0 ;
F_327 ( L_293 , V_218 -> V_776 . V_147 ) ;
return 0 ;
}
static int F_344 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 , V_147 ;
if ( F_211 ( V_6 , V_218 -> V_754 . V_777 ) )
return - V_778 ;
if ( V_6 -> V_150 -> V_198 != V_434 )
return 0 ;
if ( ( V_218 -> V_754 . V_62 & V_779 ) != V_751 )
return - V_31 ;
if ( V_218 -> V_754 . V_775 == 0 )
V_147 = V_589 ;
else {
if ( V_218 -> V_754 . V_147 < V_590 ||
V_218 -> V_754 . V_147 > V_591 )
return - V_31 ;
V_147 = V_218 -> V_754 . V_147 ;
}
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) ) {
V_63 = - V_70 ;
goto V_623;
}
V_63 = F_247 ( V_6 , V_147 ) ;
F_327 ( L_294 , V_147 ) ;
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_345 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_754 . V_777 = ( V_6 -> V_49 & V_487 ) ? 1 : 0 ;
if ( V_6 -> V_588 == V_589 ) {
V_218 -> V_754 . V_775 = 0 ;
V_218 -> V_754 . V_147 = V_591 ;
} else {
V_218 -> V_754 . V_775 = 1 ;
V_218 -> V_754 . V_147 = V_6 -> V_588 ;
}
V_218 -> V_754 . V_62 = V_751 ;
F_327 ( L_295 , V_218 -> V_754 . V_147 ) ;
return 0 ;
}
static int F_346 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_218 -> V_780 . V_775 )
return - V_31 ;
if ( V_218 -> V_780 . V_777 ) {
V_6 -> V_684 |= V_686 ;
V_6 -> V_150 -> V_781 = V_685 ;
} else {
if ( V_218 -> V_780 . V_147 < V_731 ||
V_218 -> V_780 . V_147 > V_733 )
return - V_31 ;
V_6 -> V_150 -> V_781 = V_218 -> V_780 . V_147 & ~ 0x1 ;
V_6 -> V_684 = V_6 -> V_150 -> V_781 ;
}
F_327 ( L_296 , V_6 -> V_150 -> V_781 ) ;
return 0 ;
}
static int F_347 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_780 . V_147 = V_6 -> V_684 & ~ V_686 ;
V_218 -> V_780 . V_775 = 0 ;
V_218 -> V_780 . V_777 = ( V_6 -> V_684 & V_686 ) ? 1 : 0 ;
F_327 ( L_297 , V_218 -> V_780 . V_147 ) ;
return 0 ;
}
static int F_348 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
if ( V_218 -> V_559 . V_62 & V_782 || V_218 -> V_559 . V_777 )
return - V_31 ;
if ( ! ( V_218 -> V_559 . V_62 & V_783 ) )
return 0 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) ) {
V_63 = - V_70 ;
goto V_623;
}
if ( V_218 -> V_559 . V_62 & V_784 ) {
V_63 = F_241 ( V_6 , V_218 -> V_559 . V_147 ) ;
F_327 ( L_298 ,
V_218 -> V_559 . V_147 ) ;
goto V_623;
}
if ( V_218 -> V_559 . V_62 & V_785 ) {
V_63 = F_242 ( V_6 , V_218 -> V_559 . V_147 ) ;
F_327 ( L_299 ,
V_218 -> V_559 . V_147 ) ;
goto V_623;
}
V_63 = F_241 ( V_6 , V_218 -> V_559 . V_147 ) ;
if ( ! V_63 )
V_63 = F_242 ( V_6 , V_218 -> V_559 . V_147 ) ;
F_327 ( L_300 , V_218 -> V_559 . V_147 ) ;
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_349 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_559 . V_777 = 0 ;
if ( ( V_218 -> V_559 . V_62 & V_786 ) == V_782 )
return - V_31 ;
if ( V_218 -> V_559 . V_62 & V_785 ) {
V_218 -> V_559 . V_62 = V_783 | V_785 ;
V_218 -> V_559 . V_147 = V_6 -> V_563 ;
} else {
V_218 -> V_559 . V_62 =
( V_6 -> V_561 !=
V_6 -> V_563 ) ?
V_783 | V_784 : V_783 ;
V_218 -> V_559 . V_147 = V_6 -> V_561 ;
}
F_327 ( L_301 , V_218 -> V_559 . V_147 ) ;
return 0 ;
}
static int F_350 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) ) {
V_63 = - V_70 ;
goto V_623;
}
F_327 ( L_302 ) ;
V_6 -> V_300 = 1 ;
if ( F_90 ( V_6 ) || F_92 ( V_6 ) ) {
F_327 ( L_303 ) ;
}
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_351 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_352 ( V_6 -> V_150 , V_81 , V_218 , V_708 ) ;
}
static int F_353 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_596 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_354 ( V_6 -> V_150 , V_81 , V_218 , V_596 ) ;
}
static int F_355 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_596 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_356 ( V_6 -> V_150 , V_81 , V_218 , V_596 ) ;
}
static int F_357 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) ) {
V_63 = - V_70 ;
goto V_623;
}
if ( V_218 -> V_787 . V_777 ) {
V_6 -> V_548 = F_238 ( V_6 -> V_548 ) ;
V_63 = F_237 ( V_6 , V_547 ) ;
F_327 ( L_304 ) ;
goto V_623;
}
switch ( V_218 -> V_787 . V_62 & V_788 ) {
case V_789 :
case V_788 :
case V_790 :
break;
default:
F_327 ( L_305 ,
V_218 -> V_787 . V_62 ) ;
V_63 = - V_642 ;
goto V_623;
}
V_6 -> V_548 = V_549 | V_6 -> V_548 ;
V_63 = F_237 ( V_6 , F_238 ( V_6 -> V_548 ) ) ;
F_327 ( L_306 , V_6 -> V_548 ) ;
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_358 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_548 & V_549 ) )
V_218 -> V_787 . V_777 = 1 ;
else {
V_218 -> V_787 . V_777 = 0 ;
V_218 -> V_787 . V_62 = 0 ;
}
F_327 ( L_307 , V_6 -> V_548 ) ;
return 0 ;
}
static int F_359 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_635 * V_150 = V_6 -> V_150 ;
T_3 * V_15 ;
if ( ! V_150 -> V_634 )
return - V_642 ;
if ( V_218 -> V_37 . V_287 > V_791 ||
( V_218 -> V_37 . V_287 && V_708 == NULL ) )
return - V_31 ;
if ( V_218 -> V_37 . V_287 ) {
V_15 = F_360 ( V_708 , V_218 -> V_37 . V_287 , V_239 ) ;
if ( V_15 == NULL )
return - V_240 ;
F_132 ( V_150 -> V_643 ) ;
V_150 -> V_643 = V_15 ;
V_150 -> V_644 = V_218 -> V_37 . V_287 ;
} else {
F_132 ( V_150 -> V_643 ) ;
V_150 -> V_643 = NULL ;
V_150 -> V_644 = 0 ;
}
V_566 ( V_6 , V_150 -> V_643 , V_150 -> V_644 ) ;
return 0 ;
}
static int F_361 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_635 * V_150 = V_6 -> V_150 ;
if ( V_150 -> V_644 == 0 || V_150 -> V_643 == NULL ) {
V_218 -> V_37 . V_287 = 0 ;
return 0 ;
}
if ( V_218 -> V_37 . V_287 < V_150 -> V_644 )
return - V_773 ;
V_218 -> V_37 . V_287 = V_150 -> V_644 ;
memcpy ( V_708 , V_150 -> V_643 , V_150 -> V_644 ) ;
return 0 ;
}
static int F_362 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_635 * V_150 = V_6 -> V_150 ;
struct V_792 * V_793 = & V_218 -> V_793 ;
struct V_794 * V_494 ;
unsigned long V_62 ;
int V_267 = 0 ;
switch ( V_793 -> V_62 & V_795 ) {
case V_796 :
case V_797 :
case V_798 :
case V_799 :
break;
case V_800 :
V_494 = V_6 -> V_150 -> V_493 . V_494 [ V_6 -> V_150 -> V_493 . V_495 ] ;
if ( ! V_494 || ! V_494 -> V_801 -> V_802 || ! V_494 -> V_801 -> V_803 )
break;
V_62 = V_494 -> V_801 -> V_803 ( V_494 -> V_6 ) ;
if ( V_793 -> V_147 )
V_62 |= V_804 ;
else
V_62 &= ~ V_804 ;
V_494 -> V_801 -> V_802 ( V_62 , V_494 -> V_6 ) ;
break;
case V_805 : {
struct V_620 V_190 = {
. V_62 = V_191 ,
. V_192 = V_793 -> V_147 ,
} ;
V_6 -> V_150 -> V_674 = V_793 -> V_147 ;
if ( ! V_793 -> V_147 ) {
V_190 . V_62 |= V_613 ;
V_190 . V_43 = V_575 ;
} else {
V_190 . V_62 |= V_613 ;
V_190 . V_43 = V_578 ;
}
if ( V_6 -> V_150 -> V_641 )
V_6 -> V_150 -> V_641 ( V_6 -> V_150 -> V_2 , & V_190 ) ;
break;
}
case V_806 :
V_267 = F_268 ( V_6 , V_793 -> V_147 ) ;
break;
case V_807 :
V_267 = F_267 ( V_6 , V_793 -> V_147 ) ;
break;
case V_808 :
V_150 -> V_676 = V_793 -> V_147 ;
break;
case V_809 :
V_150 -> V_675 = V_793 -> V_147 ;
break;
default:
return - V_642 ;
}
return V_267 ;
}
static int F_363 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_635 * V_150 = V_6 -> V_150 ;
struct V_794 * V_494 ;
struct V_792 * V_793 = & V_218 -> V_793 ;
int V_267 = 0 ;
switch ( V_793 -> V_62 & V_795 ) {
case V_796 :
case V_797 :
case V_798 :
case V_799 :
V_267 = - V_642 ;
break;
case V_800 :
V_494 = V_6 -> V_150 -> V_493 . V_494 [ V_6 -> V_150 -> V_493 . V_495 ] ;
if ( ! V_494 || ! V_494 -> V_801 -> V_803 ) {
F_155 ( L_308
L_309 ) ;
break;
}
V_793 -> V_147 = ( V_494 -> V_801 -> V_803 ( V_494 -> V_6 ) &
V_804 ) ? 1 : 0 ;
break;
case V_805 :
V_793 -> V_147 = V_150 -> V_674 ;
break;
case V_806 :
V_793 -> V_147 = V_6 -> V_150 -> V_190 . V_569 ;
break;
case V_807 :
V_793 -> V_147 = V_150 -> V_634 ;
break;
case V_808 :
V_793 -> V_147 = V_150 -> V_676 ;
break;
case V_810 :
case V_809 :
V_793 -> V_147 = V_150 -> V_675 ;
break;
default:
return - V_642 ;
}
return 0 ;
}
static int F_364 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_365 ( V_6 -> V_150 , V_81 , V_218 , V_708 ) ;
}
static int F_366 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_367 ( V_6 -> V_150 , V_81 , V_218 , V_708 ) ;
}
static int F_368 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_811 * V_812 = (struct V_811 * ) V_708 ;
T_17 V_813 ;
V_813 = F_153 ( V_812 -> V_814 ) ;
switch ( V_812 -> V_57 ) {
case V_815 :
break;
case V_816 :
F_244 ( V_6 ) ;
break;
default:
return - V_642 ;
}
return 0 ;
}
static int F_369 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int * V_817 = ( int * ) V_708 ;
int V_818 = ( V_817 [ 0 ] > 0 ) ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) ) {
V_63 = - V_70 ;
goto V_623;
}
if ( V_818 ) {
if ( V_6 -> V_150 -> V_198 == V_199 ) {
V_63 = F_233 ( V_6 , V_817 [ 1 ] , 0 ) ;
goto V_623;
}
V_6 -> V_245 = V_817 [ 1 ] ;
V_63 = F_198 ( V_6 , V_199 ) ;
} else {
if ( V_6 -> V_150 -> V_198 == V_199 )
V_63 = F_198 ( V_6 , V_6 -> V_491 ) ;
}
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_370 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_49 & V_622 )
F_35 ( V_6 ) ;
return 0 ;
}
static int F_371 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 , V_315 = * ( int * ) V_708 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) ) {
V_63 = - V_70 ;
goto V_623;
}
if ( ( V_315 < 0 ) || ( V_315 > V_737 ) )
V_315 = V_673 ;
if ( F_238 ( V_6 -> V_548 ) != V_315 )
V_63 = F_237 ( V_6 , V_315 ) ;
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_372 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_43 = F_238 ( V_6 -> V_548 ) ;
T_18 V_819 , V_820 ;
if ( ! ( V_6 -> V_548 & V_549 ) ) {
snprintf ( V_708 , V_821 ,
L_310 , V_43 ) ;
} else {
switch ( V_43 ) {
case V_547 :
snprintf ( V_708 , V_821 ,
L_311 , V_43 ) ;
break;
case V_673 :
snprintf ( V_708 , V_821 ,
L_312 , V_43 ) ;
break;
default:
V_819 = V_739 [ V_43 - 1 ] / 1000 ;
V_820 = V_735 [ V_43 - 1 ] / 1000 ;
snprintf ( V_708 , V_821 ,
L_313
L_314 ,
V_43 , V_819 , V_820 ) ;
}
}
V_218 -> V_37 . V_287 = strlen ( V_708 ) + 1 ;
return 0 ;
}
static int F_373 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 , V_315 = * ( int * ) V_708 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) ) {
V_63 = - V_70 ;
goto V_623;
}
if ( V_315 == 1 )
V_6 -> V_187 |= V_531 ;
else if ( V_315 == 0 )
V_6 -> V_187 &= ~ V_531 ;
else {
V_63 = - V_31 ;
goto V_623;
}
V_63 = F_234 ( V_6 , 0 ) ;
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_374 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_531 )
snprintf ( V_218 -> V_51 , V_709 , L_315 ) ;
else
snprintf ( V_218 -> V_51 , V_709 , L_316 ) ;
return 0 ;
}
static int F_375 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 , V_315 = * ( int * ) V_708 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_622 ) ) {
V_63 = - V_70 ;
goto V_623;
}
if ( V_315 == 1 )
V_6 -> V_187 |= V_346 ;
else if ( V_315 == 0 )
V_6 -> V_187 &= ~ V_346 ;
else {
V_63 = - V_31 ;
goto V_623;
}
V_63 = 0 ;
V_623:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_376 ( struct V_1 * V_2 ,
struct V_707 * V_81 ,
union V_217 * V_218 , char * V_708 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_346 )
snprintf ( V_218 -> V_51 , V_709 , L_317 ) ;
else
snprintf ( V_218 -> V_51 , V_709 , L_318 ) ;
return 0 ;
}
static struct V_822 * F_377 ( struct V_1 * V_2 )
{
enum {
V_823 = 30 ,
V_824 = 60 ,
V_825 = 80 ,
V_826 = 90 ,
V_827 = 95 ,
V_828 = 100
};
int V_829 ;
int V_830 ;
int V_831 ;
int V_832 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_822 * V_304 ;
T_1 V_354 , V_833 , V_834 , V_835 ;
T_1 V_204 = sizeof( T_1 ) ;
if ( ! V_6 )
return (struct V_822 * ) NULL ;
V_304 = & V_6 -> V_304 ;
if ( ! ( V_6 -> V_49 & V_166 ) ) {
V_304 -> V_836 . V_837 = 0 ;
V_304 -> V_334 . V_838 = 0 ;
V_304 -> V_720 . V_720 = 0 ;
V_304 -> V_720 . V_43 = 0 ;
V_304 -> V_720 . V_721 = 0 ;
V_304 -> V_720 . V_722 = 7 ;
V_304 -> V_720 . V_722 |= V_839 |
V_840 | V_841 ;
return V_304 ;
}
if ( F_26 ( V_6 , V_842 ,
& V_834 , & V_204 ) )
goto V_843;
if ( ! ( V_6 -> V_49 & V_166 ) ) {
V_304 -> V_720 . V_720 = 0 ;
V_304 -> V_720 . V_43 = 0 ;
} else {
if ( F_26 ( V_6 , V_844 ,
& V_354 , & V_204 ) )
goto V_843;
V_304 -> V_720 . V_43 = V_354 + V_355 ;
if ( V_354 < 10 )
V_829 = V_354 * V_823 / 10 ;
else if ( V_354 < 15 )
V_829 = ( V_354 - 10 ) * ( V_824 - V_823 ) / 5 + V_823 ;
else if ( V_354 < 20 )
V_829 = ( V_354 - 15 ) * ( V_825 - V_824 ) / 5 + V_824 ;
else if ( V_354 < 30 )
V_829 = ( V_354 - 20 ) * ( V_826 - V_825 ) /
10 + V_825 ;
else
V_829 = ( V_354 - 30 ) * ( V_828 - V_826 ) /
10 + V_826 ;
if ( F_26 ( V_6 , V_845 ,
& V_833 , & V_204 ) )
goto V_843;
if ( V_833 > 75 )
V_830 = ( 90 - V_833 ) * V_823 / 15 ;
else if ( V_833 > 70 )
V_830 = ( 75 - V_833 ) * ( V_824 - V_823 ) / 5 + V_823 ;
else if ( V_833 > 65 )
V_830 = ( 70 - V_833 ) * ( V_825 - V_824 ) / 5 + V_824 ;
else if ( V_833 > 50 )
V_830 = ( 65 - V_833 ) * ( V_826 - V_825 ) /
15 + V_825 ;
else
V_830 = ( 50 - V_833 ) *
( V_828 - V_826 ) / 50 + V_826 ;
if ( V_834 > 50 )
V_831 = ( 60 - V_834 ) * V_823 / 10 ;
else if ( V_834 > 40 )
V_831 = ( 50 - V_834 ) * ( V_824 - V_823 ) /
10 + V_823 ;
else if ( V_834 > 32 )
V_831 = ( 40 - V_834 ) * ( V_825 - V_824 ) /
18 + V_824 ;
else if ( V_834 > 20 )
V_831 = ( 32 - V_834 ) *
( V_826 - V_825 ) / 20 + V_825 ;
else
V_831 = ( 20 - V_834 ) *
( V_828 - V_826 ) / 20 + V_826 ;
V_832 = F_34 ( V_830 , V_829 ) ;
V_832 = F_34 ( V_831 , V_832 ) ;
#ifdef F_127
if ( V_831 == V_832 )
F_327 ( L_319 ) ;
else if ( V_830 == V_832 )
F_327 ( L_320 ) ;
else if ( V_832 != 100 )
F_327 ( L_321 ) ;
else
F_327 ( L_322 ) ;
#endif
V_304 -> V_720 . V_720 = V_832 ;
V_304 -> V_720 . V_43 = V_354 + V_355 ;
}
V_304 -> V_720 . V_721 = 0 ;
V_304 -> V_720 . V_722 = 7 ;
V_304 -> V_720 . V_722 |= V_839 ;
V_304 -> V_836 . V_837 = V_834 ;
if ( F_26 ( V_6 , V_846 ,
& V_835 , & V_204 ) )
goto V_843;
V_304 -> V_334 . V_838 = V_835 ;
return V_304 ;
V_843:
F_327 ( L_290 ) ;
return (struct V_822 * ) NULL ;
}
static void V_689 ( struct V_262 * V_263 )
{
struct V_5 * V_6 =
F_108 ( V_263 , struct V_5 , V_286 . V_263 ) ;
union V_217 V_218 ;
unsigned int V_14 = V_230 ;
if ( V_6 -> V_49 & V_184 )
return;
F_84 ( & V_6 -> V_266 ) ;
F_327 ( L_42 ) ;
F_85 ( & V_6 -> V_266 ) ;
V_218 . V_219 . V_220 = V_221 ;
if ( ! ( V_6 -> V_49 & ( V_165 | V_166 ) ) ||
V_6 -> V_49 & V_487 ||
F_26 ( V_6 , V_279 ,
& V_6 -> V_274 , & V_14 ) ) {
memset ( V_218 . V_219 . V_631 , 0 , V_230 ) ;
} else {
memcpy ( V_218 . V_219 . V_631 , V_6 -> V_274 , V_230 ) ;
memcpy ( V_6 -> V_150 -> V_274 , V_6 -> V_274 , V_230 ) ;
V_6 -> V_49 &= ~ V_165 ;
V_6 -> V_49 |= V_166 ;
F_263 ( V_6 -> V_33 ) ;
F_166 ( V_6 -> V_33 ) ;
}
if ( ! ( V_6 -> V_49 & V_166 ) ) {
F_327 ( L_323 ) ;
F_84 ( & V_6 -> V_266 ) ;
if ( V_6 -> V_187 & V_284 )
F_113 ( V_6 , V_6 -> V_269 , V_6 -> V_268 ,
0 ) ;
else
F_113 ( V_6 , NULL , 0 , 0 ) ;
F_85 ( & V_6 -> V_266 ) ;
}
F_100 ( V_6 -> V_33 , V_224 , & V_218 , NULL ) ;
}
static int F_378 ( struct V_119 * V_847 )
{
struct V_848 * V_849 =
(struct V_848 * ) V_847 -> V_850 -> V_37 ;
if ( F_379 ( V_849 -> V_121 ) != V_851 ) {
F_27 (KERN_WARNING DRV_NAME L_324
L_325
L_326 ,
h->version) ;
return 1 ;
}
V_847 -> V_121 = V_849 -> V_121 ;
V_847 -> V_847 . V_37 = V_847 -> V_850 -> V_37 + sizeof( struct V_848 ) ;
V_847 -> V_847 . V_481 = V_849 -> V_852 ;
V_847 -> V_853 . V_37 = V_847 -> V_847 . V_37 + V_849 -> V_852 ;
V_847 -> V_853 . V_481 = V_849 -> V_854 ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 ,
struct V_119 * V_847 )
{
char * V_855 ;
int V_202 ;
F_31 ( L_327 ,
V_6 -> V_33 -> V_51 ) ;
switch ( V_6 -> V_150 -> V_198 ) {
case V_434 :
V_855 = F_380 ( L_328 ) ;
break;
#ifdef F_157
case V_199 :
V_855 = F_380 ( L_329 ) ;
break;
#endif
case V_429 :
default:
V_855 = F_380 ( L_50 ) ;
break;
}
V_202 = F_381 ( & V_847 -> V_850 , V_855 , & V_6 -> V_261 -> V_2 ) ;
if ( V_202 < 0 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_330 ,
priv->net_dev->name, fw_name) ;
return V_202 ;
}
F_31 ( L_331 , V_847 -> V_850 -> V_37 ,
V_847 -> V_850 -> V_481 ) ;
F_378 ( V_847 ) ;
return 0 ;
}
static void F_66 ( struct V_5 * V_6 ,
struct V_119 * V_847 )
{
V_847 -> V_121 = 0 ;
F_382 ( V_847 -> V_850 ) ;
V_847 -> V_850 = NULL ;
}
static int F_271 ( struct V_5 * V_6 , char * V_15 ,
T_4 V_856 )
{
char V_857 [ V_858 ] ;
T_1 V_14 = V_858 ;
T_1 V_316 ;
int V_19 ;
if ( F_26 ( V_6 , V_859 , V_857 , & V_14 ) )
return - V_70 ;
V_316 = V_856 ;
if ( V_14 >= V_856 )
V_14 = V_856 - 1 ;
for ( V_19 = 0 ; V_19 < V_14 ; V_19 ++ )
V_15 [ V_19 ] = V_857 [ V_19 ] ;
V_15 [ V_19 ] = '\0' ;
return V_316 ;
}
static int F_272 ( struct V_5 * V_6 , char * V_15 ,
T_4 V_856 )
{
T_1 V_857 ;
T_1 V_14 = sizeof( V_857 ) ;
if ( F_26 ( V_6 , V_860 , & V_857 , & V_14 ) )
return - V_70 ;
return snprintf ( V_15 , V_856 , L_14 , V_857 ) ;
}
static int F_65 ( struct V_5 * V_6 , struct V_119 * V_847 )
{
unsigned int V_8 ;
unsigned short V_14 ;
const unsigned char * V_861 = V_847 -> V_847 . V_37 ;
unsigned int V_862 = V_847 -> V_847 . V_481 ;
while ( V_862 > 0 ) {
V_8 = * ( T_1 * ) ( V_861 ) ;
V_861 += 4 ;
V_862 -= 4 ;
V_14 = * ( T_2 * ) ( V_861 ) ;
V_861 += 2 ;
V_862 -= 2 ;
if ( V_14 > 32 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_332 ,
len) ;
return - V_31 ;
}
F_23 ( V_6 -> V_33 , V_8 , V_14 , V_861 ) ;
V_861 += V_14 ;
V_862 -= V_14 ;
}
return 0 ;
}
static int F_64 ( struct V_5 * V_6 ,
struct V_119 * V_847 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
const unsigned char * V_863 = V_847 -> V_853 . V_37 ;
unsigned int V_864 = V_847 -> V_853 . V_481 ;
void T_12 * V_3 = V_6 -> V_7 ;
struct V_865 V_866 ;
int V_19 , V_40 ;
T_3 V_37 ;
F_18 ( V_2 , V_174 , 0x703 ) ;
F_383 ( V_3 ) ;
F_18 ( V_2 , V_174 , 0x707 ) ;
F_383 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_383 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_383 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x40 ) ;
F_383 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x0 ) ;
F_383 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x40 ) ;
F_383 ( V_3 ) ;
while ( V_864 > 0 ) {
F_20 ( V_2 , 0x210010 , * V_863 ++ ) ;
F_20 ( V_2 , 0x210010 , * V_863 ++ ) ;
V_864 -= 2 ;
}
F_20 ( V_2 , 0x210000 , 0x0 ) ;
F_383 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x0 ) ;
F_383 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x80 ) ;
F_383 ( V_3 ) ;
F_18 ( V_2 , V_174 , 0x703 ) ;
F_383 ( V_3 ) ;
F_18 ( V_2 , V_174 , 0x707 ) ;
F_383 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_383 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_383 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x00 ) ;
F_383 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x80 ) ;
for ( V_19 = 0 ; V_19 < 10 ; V_19 ++ ) {
F_58 ( 10 ) ;
F_19 ( V_2 , 0x210000 , & V_37 ) ;
if ( V_37 & 0x1 )
break;
}
if ( V_19 == 10 ) {
F_27 (KERN_ERR DRV_NAME L_333 ,
dev->name) ;
return - V_70 ;
}
for ( V_19 = 0 ; V_19 < 30 ; V_19 ++ ) {
for ( V_40 = 0 ;
V_40 < ( sizeof( struct V_865 ) >> 1 ) ; V_40 ++ )
F_17 ( V_2 , 0x210004 , ( ( T_2 * ) & V_866 ) + V_40 ) ;
if ( ( V_866 . V_867 == 1 ) && ( V_866 . V_868 == 0x1 ) )
break;
F_58 ( 10 ) ;
}
if ( V_19 == 30 ) {
F_27 (KERN_ERR DRV_NAME
L_334 ,
dev->name) ;
F_33 ( V_869 , ( T_3 * ) & V_866 , sizeof( V_866 ) ) ;
return - V_70 ;
}
return 0 ;
}
