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
F_117 ( V_296 , & V_6 -> V_216 , F_97 ( V_53 ) ) ;
}
static void F_118 ( void * V_37 )
{
struct V_5 * V_6 = V_37 ;
union V_217 V_218 ;
V_218 . V_37 . V_287 = 0 ;
V_218 . V_37 . V_62 = 0 ;
F_100 ( V_6 -> V_33 , V_297 , & V_218 , NULL ) ;
}
static void F_119 ( struct V_262 * V_263 )
{
F_118 ( F_108 ( V_263 , struct V_5 ,
V_298 . V_263 ) ) ;
}
static void F_120 ( struct V_262 * V_263 )
{
F_118 ( F_108 ( V_263 , struct V_5 ,
V_299 ) ) ;
}
static void F_121 ( struct V_5 * V_6 , T_1 V_49 )
{
F_91 ( L_102 ) ;
V_6 -> V_150 -> V_300 ++ ;
V_6 -> V_49 &= ~ V_200 ;
if ( ! V_6 -> V_301 ) {
if ( ! F_122 ( & V_6 -> V_298 ) )
F_39 ( & V_6 -> V_298 ,
F_97 ( F_55 ( 4000 ) ) ) ;
} else {
V_6 -> V_301 = 0 ;
F_89 ( & V_6 -> V_298 ) ;
F_123 ( & V_6 -> V_299 ) ;
}
}
static void F_124 ( struct V_5 * V_6 , T_1 V_49 )
{
F_91 ( L_103 ) ;
V_6 -> V_49 |= V_200 ;
}
static void F_125 ( struct V_5 * V_6 , int V_49 )
{
int V_19 ;
if ( V_49 == V_302 &&
V_6 -> V_49 & V_166 &&
! ( V_6 -> V_49 & V_200 ) ) {
F_31 ( L_104
L_105 ) ;
F_35 ( V_6 ) ;
}
for ( V_19 = 0 ; V_303 [ V_19 ] . V_49 != - 1 ; V_19 ++ ) {
if ( V_49 == V_303 [ V_19 ] . V_49 ) {
F_126 ( L_106 ,
V_303 [ V_19 ] . V_51 ) ;
if ( V_303 [ V_19 ] . V_304 )
V_303 [ V_19 ] . V_304 ( V_6 , V_49 ) ;
V_6 -> V_305 . V_49 = V_49 ;
return;
}
}
F_126 ( L_107 , V_49 ) ;
}
static void F_127 ( struct V_5 * V_6 ,
struct V_306 * V_57 )
{
#ifdef F_128
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
static int F_129 ( struct V_5 * V_6 ,
struct V_307 * V_61 )
{
V_61 -> V_308 = F_130 ( sizeof( struct V_309 ) ) ;
if ( ! V_61 -> V_308 )
return - V_240 ;
V_61 -> V_310 = (struct V_309 * ) V_61 -> V_308 -> V_37 ;
V_61 -> V_311 = F_131 ( V_6 -> V_261 , V_61 -> V_308 -> V_37 ,
sizeof( struct V_309 ) ,
V_312 ) ;
return 0 ;
}
static void F_132 ( struct V_5 * V_6 )
{
int V_19 ;
if ( ! V_6 -> V_313 [ 0 ] )
return;
for ( V_19 = 0 ; V_19 < 0x30 ; V_19 ++ )
F_133 ( V_6 -> V_313 [ V_19 ] ) ;
V_6 -> V_313 [ 0 ] = NULL ;
}
static int F_134 ( struct V_5 * V_6 )
{
int V_19 ;
if ( V_6 -> V_313 [ 0 ] )
return 1 ;
for ( V_19 = 0 ; V_19 < 0x30 ; V_19 ++ ) {
V_6 -> V_313 [ V_19 ] = F_135 ( 0x1000 , V_314 ) ;
if ( ! V_6 -> V_313 [ V_19 ] ) {
F_31 ( L_109
L_110 , V_6 -> V_33 -> V_51 , V_19 ) ;
while ( V_19 > 0 )
F_133 ( V_6 -> V_313 [ -- V_19 ] ) ;
V_6 -> V_313 [ 0 ] = NULL ;
return 0 ;
}
}
return 1 ;
}
static T_1 F_136 ( struct V_5 * V_6 , T_3 * V_315 ,
T_4 V_14 , int V_316 )
{
T_1 V_19 , V_40 ;
T_1 V_317 ;
T_3 * V_318 , * V_319 ;
T_1 V_267 ;
V_318 = V_315 ;
if ( V_316 == V_320 ) {
if ( ! F_134 ( V_6 ) )
V_316 = V_321 ;
}
for ( V_267 = V_322 , V_19 = 0 ; V_19 < 0x30000 ; V_19 += 4 ) {
F_15 ( V_6 -> V_33 , V_19 , & V_317 ) ;
if ( V_316 == V_320 )
* ( T_1 * ) F_137 ( V_19 ) = V_317 ;
if ( V_267 == V_322 ) {
V_319 = ( T_3 * ) & V_317 ;
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
if ( * V_318 != * V_319 ) {
V_318 = V_315 ;
continue;
}
V_318 ++ ;
V_319 ++ ;
if ( ( V_318 - V_315 ) == V_14 )
V_267 = ( V_19 + V_40 ) - V_14 + 1 ;
}
} else if ( V_316 == V_321 )
return V_267 ;
}
return V_267 ;
}
static void F_138 ( struct V_5 * V_6 , int V_19 )
{
#ifdef F_139
struct V_323 * V_49 = & V_6 -> V_324 . V_325 [ V_19 ] ;
T_1 V_326 , V_3 ;
int V_40 ;
#endif
F_31 ( L_111 ,
V_19 * sizeof( struct V_323 ) ) ;
#ifdef F_139
F_5 ( V_6 -> V_33 , V_110 ,
V_170 ) ;
V_40 = 5 ;
do {
F_58 ( V_171 ) ;
F_1 ( V_6 -> V_33 , V_110 , & V_3 ) ;
if ( V_3 & V_172 )
break;
} while ( V_40 -- );
V_326 = F_136 ( V_6 , ( T_3 * ) V_49 ,
sizeof( struct V_323 ) ,
V_320 ) ;
if ( V_326 < V_327 )
F_31 ( L_112
L_113 ,
V_6 -> V_33 -> V_51 , V_326 ,
sizeof( struct V_323 ) ) ;
else
F_31 ( L_114
L_115 , V_6 -> V_33 -> V_51 ) ;
F_33 ( ( T_3 * ) V_6 -> V_324 . V_325 ,
sizeof( struct V_323 ) * V_328 ) ;
#endif
V_6 -> V_69 = V_329 ;
V_6 -> V_33 -> V_330 . V_331 ++ ;
F_35 ( V_6 ) ;
}
static void F_140 ( struct V_5 * V_6 , int V_19 ,
struct V_332 * V_330 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
struct V_323 * V_49 = & V_6 -> V_324 . V_325 [ V_19 ] ;
struct V_307 * V_61 = & V_6 -> V_333 [ V_19 ] ;
F_141 ( L_116 ) ;
if ( F_142 ( V_49 -> V_334 > F_143 ( V_61 -> V_308 ) ) ) {
F_31 ( L_117
L_118 ,
V_2 -> V_51 ,
V_49 -> V_334 , F_143 ( V_61 -> V_308 ) ) ;
V_2 -> V_330 . V_331 ++ ;
return;
}
if ( F_142 ( ! F_144 ( V_2 ) ) ) {
V_2 -> V_330 . V_331 ++ ;
V_6 -> V_305 . V_335 . V_336 ++ ;
F_145 ( L_119 ) ;
return;
}
if ( F_142 ( V_6 -> V_150 -> V_198 != V_199 &&
! ( V_6 -> V_49 & V_166 ) ) ) {
F_145 ( L_120 ) ;
V_6 -> V_305 . V_335 . V_336 ++ ;
return;
}
F_146 ( V_6 -> V_261 ,
V_61 -> V_311 ,
sizeof( struct V_309 ) , V_312 ) ;
F_147 ( V_61 -> V_308 , V_49 -> V_334 ) ;
#ifdef F_148
F_149 ( V_61 -> V_308 , V_337 ,
F_150 ( T_1 , V_49 -> V_334 ,
V_338 ) ) ;
#endif
if ( ! F_151 ( V_6 -> V_150 , V_61 -> V_308 , V_330 ) ) {
#ifdef F_148
F_145 ( L_121 ,
V_2 -> V_51 ) ;
F_33 ( V_339 , V_337 , V_49 -> V_334 ) ;
#endif
V_2 -> V_330 . V_331 ++ ;
F_152 ( V_61 -> V_308 ) ;
V_61 -> V_308 = NULL ;
}
if ( F_142 ( F_129 ( V_6 , V_61 ) ) ) {
F_27 (KERN_WARNING DRV_NAME L_67
L_122
L_123 , dev->name) ;
F_31 ( L_124 ) ;
}
V_6 -> V_340 . V_325 [ V_19 ] . V_341 = V_61 -> V_311 ;
}
static void F_153 ( struct V_5 * V_6 , int V_19 ,
struct V_332 * V_330 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
struct V_323 * V_49 = & V_6 -> V_324 . V_325 [ V_19 ] ;
struct V_307 * V_61 = & V_6 -> V_333 [ V_19 ] ;
struct V_342 {
struct V_343 V_344 ;
T_5 V_345 ;
} * V_346 ;
F_141 ( L_116 ) ;
if ( F_142 ( V_49 -> V_334 > F_143 ( V_61 -> V_308 ) -
sizeof( struct V_342 ) ) ) {
F_31 ( L_117
L_118 ,
V_2 -> V_51 ,
V_49 -> V_334 ,
F_143 ( V_61 -> V_308 ) ) ;
V_2 -> V_330 . V_331 ++ ;
return;
}
if ( F_142 ( ! F_144 ( V_2 ) ) ) {
V_2 -> V_330 . V_331 ++ ;
V_6 -> V_305 . V_335 . V_336 ++ ;
F_145 ( L_119 ) ;
return;
}
if ( F_142 ( V_6 -> V_187 & V_347 &&
V_49 -> V_62 & V_348 ) ) {
F_141 ( L_125 ) ;
V_2 -> V_330 . V_331 ++ ;
return;
}
F_146 ( V_6 -> V_261 , V_61 -> V_311 ,
sizeof( struct V_309 ) , V_312 ) ;
memmove ( V_61 -> V_308 -> V_37 + sizeof( struct V_342 ) ,
V_61 -> V_308 -> V_37 , V_49 -> V_334 ) ;
V_346 = (struct V_342 * ) V_61 -> V_308 -> V_37 ;
V_346 -> V_344 . V_349 = V_350 ;
V_346 -> V_344 . V_351 = 0 ;
V_346 -> V_344 . V_352 = F_154 ( sizeof( struct V_342 ) ) ;
V_346 -> V_344 . V_353 = F_155 ( 1 << V_354 ) ;
V_346 -> V_345 = V_49 -> V_355 + V_356 ;
F_147 ( V_61 -> V_308 , V_49 -> V_334 + sizeof( struct V_342 ) ) ;
if ( ! F_151 ( V_6 -> V_150 , V_61 -> V_308 , V_330 ) ) {
V_2 -> V_330 . V_331 ++ ;
F_152 ( V_61 -> V_308 ) ;
V_61 -> V_308 = NULL ;
}
if ( F_142 ( F_129 ( V_6 , V_61 ) ) ) {
F_156 (
L_122
L_123 , V_2 -> V_51 ) ;
F_31 ( L_124 ) ;
}
V_6 -> V_340 . V_325 [ V_19 ] . V_341 = V_61 -> V_311 ;
}
static int F_157 ( struct V_5 * V_6 , int V_19 )
{
struct V_323 * V_49 = & V_6 -> V_324 . V_325 [ V_19 ] ;
struct V_309 * V_357 = V_6 -> V_333 [ V_19 ] . V_310 ;
T_2 V_358 = V_49 -> V_359 & V_360 ;
switch ( V_358 ) {
case V_361 :
return ( V_49 -> V_334 != sizeof( V_357 -> V_362 . V_363 ) ) ;
case V_364 :
return ( V_49 -> V_334 != sizeof( V_357 -> V_362 . V_49 ) ) ;
case V_365 :
return ( V_49 -> V_334 < sizeof( V_357 -> V_362 . V_366 ) ) ;
case V_367 :
case V_368 :
#ifdef F_158
return 0 ;
#else
switch ( F_159 ( F_160 ( V_357 -> V_362 . V_369 . V_370 ) ) ) {
case V_371 :
case V_372 :
return 0 ;
case V_373 :
return ( V_49 -> V_334 >
V_374 ) ;
}
#endif
}
return 1 ;
}
static void F_161 ( struct V_5 * V_6 )
{
struct V_375 * V_376 = & V_6 -> V_340 ;
struct V_377 * V_378 = & V_6 -> V_324 ;
struct V_307 * V_61 ;
T_2 V_358 ;
T_1 V_109 , V_379 , V_19 , V_318 ;
struct V_309 * V_357 ;
struct V_332 V_330 = {
. V_380 = V_80 ,
} ;
F_1 ( V_6 -> V_33 , V_381 , & V_109 ) ;
F_1 ( V_6 -> V_33 , V_382 , & V_379 ) ;
if ( V_109 >= V_376 -> V_383 ) {
F_141 ( L_126 ) ;
return;
}
V_19 = ( V_376 -> V_77 + 1 ) % V_376 -> V_383 ;
V_318 = V_19 ;
while ( V_19 != V_109 ) {
V_61 = & V_6 -> V_333 [ V_19 ] ;
F_162 ( V_6 -> V_261 , V_61 -> V_311 ,
sizeof( struct V_309 ) ,
V_312 ) ;
if ( F_142 ( F_157 ( V_6 , V_19 ) ) ) {
F_138 ( V_6 , V_19 ) ;
goto V_384;
}
V_357 = V_61 -> V_310 ;
V_358 = V_378 -> V_325 [ V_19 ] . V_359 & V_360 ;
V_330 . V_355 = V_378 -> V_325 [ V_19 ] . V_355 + V_356 ;
V_330 . V_14 = V_378 -> V_325 [ V_19 ] . V_334 ;
V_330 . V_385 = 0 ;
if ( V_330 . V_355 != 0 )
V_330 . V_385 |= V_386 ;
V_330 . V_243 = V_211 ;
F_141 ( L_127 ,
V_6 -> V_33 -> V_51 , V_387 [ V_358 ] ,
V_330 . V_14 ) ;
switch ( V_358 ) {
case V_361 :
F_127 ( V_6 , & V_357 -> V_362 . V_363 ) ;
break;
case V_364 :
F_125 ( V_6 , V_357 -> V_362 . V_49 ) ;
break;
case V_367 :
case V_368 :
#ifdef F_158
if ( V_6 -> V_150 -> V_198 == V_199 ) {
F_153 ( V_6 , V_19 , & V_330 ) ;
break;
}
#endif
if ( V_330 . V_14 < sizeof( struct V_388 ) )
break;
switch ( F_159 ( F_160 ( V_357 -> V_362 . V_369 . V_370 ) ) ) {
case V_371 :
F_163 ( V_6 -> V_150 ,
& V_357 -> V_362 . V_369 , & V_330 ) ;
break;
case V_372 :
break;
case V_373 :
F_140 ( V_6 , V_19 , & V_330 ) ;
break;
}
break;
}
V_384:
V_376 -> V_325 [ V_19 ] . V_49 . V_81 . V_389 = 0 ;
V_19 = ( V_19 + 1 ) % V_376 -> V_383 ;
}
if ( V_19 != V_318 ) {
V_376 -> V_77 = ( V_19 ? V_19 : V_376 -> V_383 ) - 1 ;
F_5 ( V_6 -> V_33 ,
V_382 , V_376 -> V_77 ) ;
}
}
static int F_164 ( struct V_5 * V_6 )
{
struct V_375 * V_390 = & V_6 -> V_391 ;
struct V_392 * V_393 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
int V_394 ;
int V_395 , V_19 ;
T_1 V_109 , V_379 , V_396 = 0 ;
if ( F_44 ( & V_6 -> V_397 ) )
return 0 ;
V_59 = V_6 -> V_397 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
V_393 = & V_390 -> V_325 [ V_61 -> V_398 ] ;
switch ( V_61 -> type ) {
case V_399 :
V_394 = 1 ;
V_395 = V_390 -> V_400 ;
break;
case V_401 :
V_394 = V_393 -> V_402 ;
V_396 = V_393 -> V_402 - 1 ;
V_395 = V_390 -> V_400 + V_396 ;
V_395 %= V_390 -> V_383 ;
break;
default:
F_27 (KERN_WARNING DRV_NAME L_128 ,
priv->net_dev->name) ;
return 0 ;
}
F_1 ( V_6 -> V_33 , V_403 ,
& V_109 ) ;
F_1 ( V_6 -> V_33 , V_404 ,
& V_379 ) ;
if ( V_379 != V_390 -> V_77 )
F_27 (KERN_WARNING DRV_NAME L_129 ,
priv->net_dev->name) ;
if ( ! ( ( V_109 <= V_379 && ( V_395 < V_109 || V_395 >= V_379 ) ) || ( V_395 < V_109 && V_395 >= V_379 ) ) ) {
F_165 ( L_130 ) ;
return 0 ;
}
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_405 ) ;
#ifdef F_128
{
V_19 = V_390 -> V_400 ;
F_165 ( L_131 , V_19 ,
& V_390 -> V_325 [ V_19 ] ,
( T_1 ) ( V_390 -> V_406 + V_19 * sizeof( struct V_392 ) ) ,
V_390 -> V_325 [ V_19 ] . V_341 , V_390 -> V_325 [ V_19 ] . V_407 ) ;
if ( V_61 -> type == V_401 ) {
V_19 = ( V_19 + 1 ) % V_390 -> V_383 ;
F_165 ( L_131 , V_19 ,
& V_390 -> V_325 [ V_19 ] ,
( T_1 ) ( V_390 -> V_406 + V_19 *
sizeof( struct V_392 ) ) ,
( T_1 ) V_390 -> V_325 [ V_19 ] . V_341 ,
V_390 -> V_325 [ V_19 ] . V_407 ) ;
}
}
#endif
switch ( V_61 -> type ) {
case V_401 :
if ( V_390 -> V_325 [ V_390 -> V_400 ] . V_49 . V_81 . V_408 . V_409 != 0 )
F_27 (KERN_WARNING DRV_NAME L_132
L_133
L_134 ,
priv->net_dev->name, txq->oldest, packet->index) ;
for ( V_19 = 0 ; V_19 < V_396 ; V_19 ++ ) {
V_393 = & V_390 -> V_325 [ ( V_61 -> V_398 + 1 + V_19 ) % V_390 -> V_383 ] ;
F_165 ( L_135 ,
( V_61 -> V_398 + 1 + V_19 ) % V_390 -> V_383 ,
V_393 -> V_341 , V_393 -> V_407 ) ;
F_146 ( V_6 -> V_261 ,
V_393 -> V_341 ,
V_393 -> V_407 , V_410 ) ;
}
F_166 ( V_61 -> V_81 . V_411 . V_412 ) ;
V_61 -> V_81 . V_411 . V_412 = NULL ;
F_48 ( V_59 , & V_6 -> V_413 ) ;
F_49 ( & V_6 -> V_414 ) ;
if ( V_6 -> V_49 & V_166 )
F_167 ( V_6 -> V_33 ) ;
V_6 -> V_33 -> V_415 = V_80 ;
break;
case V_399 :
if ( V_390 -> V_325 [ V_390 -> V_400 ] . V_49 . V_81 . V_408 . V_409 != 1 )
F_27 (KERN_WARNING DRV_NAME L_132
L_136
L_134 ,
priv->net_dev->name, txq->oldest, packet->index) ;
#ifdef F_128
if ( V_61 -> V_81 . V_82 . V_57 -> V_83 <
F_104 ( V_64 ) )
F_165 ( L_137 ,
V_64 [ V_61 -> V_81 . V_82 . V_57 ->
V_83 ] ,
V_61 -> V_81 . V_82 . V_57 ->
V_83 ,
V_61 -> V_81 . V_82 . V_57 -> V_416 ) ;
#endif
F_48 ( V_59 , & V_6 -> V_75 ) ;
F_49 ( & V_6 -> V_90 ) ;
break;
}
V_390 -> V_400 = ( V_395 + 1 ) % V_390 -> V_383 ;
V_390 -> V_417 += V_394 ;
F_168 ( & V_6 -> V_418 , V_390 -> V_417 ) ;
F_165 ( L_138 ,
V_80 - V_61 -> V_79 ) ;
return ( ! F_44 ( & V_6 -> V_397 ) ) ;
}
static inline void F_169 ( struct V_5 * V_6 )
{
int V_19 = 0 ;
while ( F_164 ( V_6 ) && V_19 < 200 )
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
struct V_375 * V_390 = & V_6 -> V_391 ;
struct V_392 * V_393 ;
int V_77 = V_390 -> V_77 ;
while ( ! F_44 ( & V_6 -> V_91 ) ) {
if ( V_390 -> V_417 <= 3 ) {
F_165 ( L_140 ) ;
break;
}
V_59 = V_6 -> V_91 . V_77 ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_92 ) ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
F_165 ( L_141 ,
& V_390 -> V_325 [ V_390 -> V_77 ] ,
( T_1 ) ( V_390 -> V_406 + V_390 -> V_77 *
sizeof( struct V_392 ) ) ) ;
V_61 -> V_398 = V_390 -> V_77 ;
V_393 = & V_390 -> V_325 [ V_390 -> V_77 ] ;
V_393 -> V_341 = V_61 -> V_81 . V_82 . V_419 ;
V_393 -> V_407 = sizeof( struct V_306 ) ;
V_393 -> V_402 = 1 ;
V_393 -> V_49 . V_81 . V_389 =
V_420 |
V_421 ;
V_390 -> V_77 ++ ;
V_390 -> V_77 %= V_390 -> V_383 ;
V_390 -> V_417 -- ;
F_47 ( & V_6 -> V_418 ) ;
F_48 ( V_59 , & V_6 -> V_397 ) ;
F_49 ( & V_6 -> V_405 ) ;
}
if ( V_390 -> V_77 != V_77 ) {
F_170 () ;
F_5 ( V_6 -> V_33 ,
V_404 ,
V_390 -> V_77 ) ;
}
}
static void F_51 ( struct V_5 * V_6 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_375 * V_390 = & V_6 -> V_391 ;
struct V_392 * V_393 ;
int V_77 = V_390 -> V_77 ;
int V_19 = 0 ;
struct V_422 * V_423 ;
struct V_388 * V_424 ;
while ( ! F_44 ( & V_6 -> V_425 ) ) {
V_59 = V_6 -> V_425 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
if ( F_142 ( 1 + V_61 -> V_81 . V_411 . V_412 -> V_426 >
V_427 ) ) {
F_31 ( L_142
L_143 ,
V_6 -> V_33 -> V_51 ) ;
}
if ( V_390 -> V_417 <= 3 + V_61 -> V_81 . V_411 . V_412 -> V_426 ) {
F_165 ( L_140 ) ;
break;
}
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_428 ) ;
V_393 = & V_390 -> V_325 [ V_390 -> V_77 ] ;
V_61 -> V_398 = V_390 -> V_77 ;
V_423 = V_61 -> V_81 . V_411 . V_37 ;
V_424 = (struct V_388 * ) V_61 -> V_81 . V_411 . V_412 ->
V_429 [ 0 ] -> V_37 ;
if ( V_6 -> V_150 -> V_198 == V_430 ) {
memcpy ( V_423 -> V_431 , V_424 -> V_432 , V_230 ) ;
memcpy ( V_423 -> V_433 , V_424 -> V_434 , V_230 ) ;
} else if ( V_6 -> V_150 -> V_198 == V_435 ) {
memcpy ( V_423 -> V_431 , V_424 -> V_432 , V_230 ) ;
memcpy ( V_423 -> V_433 , V_424 -> V_436 , V_230 ) ;
}
V_423 -> V_83 = V_437 ;
V_423 -> V_84 = 0 ;
V_423 -> V_438 = 0 ;
V_423 -> V_439 = V_61 -> V_81 . V_411 . V_412 -> V_439 ;
if ( V_61 -> V_81 . V_411 . V_412 -> V_426 > 1 )
V_423 -> V_440 =
V_61 -> V_81 . V_411 . V_412 -> V_441 -
V_442 ;
else
V_423 -> V_440 = 0 ;
V_393 -> V_341 = V_61 -> V_81 . V_411 . V_443 ;
V_393 -> V_407 = sizeof( struct V_422 ) ;
V_393 -> V_402 = 1 + V_61 -> V_81 . V_411 . V_412 -> V_426 ;
V_393 -> V_49 . V_81 . V_389 =
V_444 |
V_445 ;
V_390 -> V_77 ++ ;
V_390 -> V_77 %= V_390 -> V_383 ;
F_165 ( L_144 ,
V_61 -> V_398 , V_393 -> V_341 , V_393 -> V_407 ) ;
#ifdef F_128
if ( V_61 -> V_81 . V_411 . V_412 -> V_426 > 1 )
F_171 ( L_145 ,
V_61 -> V_81 . V_411 . V_412 -> V_426 ) ;
#endif
for ( V_19 = 0 ; V_19 < V_61 -> V_81 . V_411 . V_412 -> V_426 ; V_19 ++ ) {
V_393 = & V_390 -> V_325 [ V_390 -> V_77 ] ;
if ( V_19 == V_61 -> V_81 . V_411 . V_412 -> V_426 - 1 )
V_393 -> V_49 . V_81 . V_389 =
V_444 |
V_421 ;
else
V_393 -> V_49 . V_81 . V_389 =
V_444 |
V_445 ;
V_393 -> V_407 = V_61 -> V_81 . V_411 . V_412 ->
V_429 [ V_19 ] -> V_14 - V_442 ;
V_393 -> V_341 = F_131 ( V_6 -> V_261 ,
V_61 -> V_81 . V_411 .
V_412 -> V_429 [ V_19 ] ->
V_37 +
V_442 ,
V_393 -> V_407 ,
V_410 ) ;
F_165 ( L_146 ,
V_390 -> V_77 , V_393 -> V_341 ,
V_393 -> V_407 ) ;
F_172 ( V_6 -> V_261 ,
V_393 -> V_341 ,
V_393 -> V_407 ,
V_410 ) ;
V_390 -> V_77 ++ ;
V_390 -> V_77 %= V_390 -> V_383 ;
}
V_390 -> V_417 -= 1 + V_61 -> V_81 . V_411 . V_412 -> V_426 ;
F_168 ( & V_6 -> V_418 , V_390 -> V_417 ) ;
F_48 ( V_59 , & V_6 -> V_397 ) ;
F_49 ( & V_6 -> V_405 ) ;
}
if ( V_390 -> V_77 != V_77 ) {
F_5 ( V_6 -> V_33 ,
V_404 ,
V_390 -> V_77 ) ;
}
}
static void F_173 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
unsigned long V_62 ;
T_1 V_157 , V_317 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
F_68 ( V_6 ) ;
F_1 ( V_2 , V_160 , & V_157 ) ;
F_174 ( L_147 ,
( unsigned long ) V_157 & V_138 ) ;
V_6 -> V_446 ++ ;
V_6 -> V_447 ++ ;
F_174 ( L_148 ,
( unsigned long ) V_157 & V_138 ) ;
if ( V_157 & V_162 ) {
F_27 (KERN_WARNING DRV_NAME
L_149 ) ;
V_6 -> V_448 ++ ;
F_5 ( V_2 , V_160 , V_162 ) ;
F_15 ( V_2 , V_449 , & V_6 -> V_69 ) ;
F_31 ( L_150 ,
V_6 -> V_33 -> V_51 , V_6 -> V_69 ) ;
F_15 ( V_2 , F_175 ( V_6 -> V_69 ) , & V_317 ) ;
F_31 ( L_151 ,
V_6 -> V_33 -> V_51 , V_317 ) ;
F_35 ( V_6 ) ;
}
if ( V_157 & V_163 ) {
F_27 (KERN_ERR DRV_NAME
L_152 ) ;
V_6 -> V_448 ++ ;
F_5 ( V_2 , V_160 , V_163 ) ;
}
if ( V_157 & V_450 ) {
F_174 ( L_153 ) ;
V_6 -> V_451 ++ ;
F_5 ( V_2 , V_160 , V_450 ) ;
F_161 ( V_6 ) ;
F_169 ( V_6 ) ;
}
if ( V_157 & V_452 ) {
F_174 ( L_154 ) ;
V_6 -> V_453 ++ ;
F_5 ( V_2 , V_160 , V_452 ) ;
F_169 ( V_6 ) ;
F_50 ( V_6 ) ;
F_51 ( V_6 ) ;
}
if ( V_157 & V_454 ) {
F_174 ( L_155 ) ;
V_6 -> V_448 ++ ;
F_5 ( V_2 , V_160 , V_454 ) ;
F_169 ( V_6 ) ;
}
if ( V_157 & V_455 ) {
V_6 -> V_448 ++ ;
F_5 ( V_2 , V_160 , V_455 ) ;
}
if ( V_157 & V_161 ) {
F_174 ( L_156 ) ;
V_6 -> V_448 ++ ;
F_1 ( V_2 , V_160 , & V_317 ) ;
if ( V_317 & ( V_162 |
V_163 ) ) {
F_5 ( V_2 , V_160 ,
V_162 |
V_163 ) ;
}
F_5 ( V_2 , V_160 , V_161 ) ;
}
if ( V_157 & V_456 ) {
F_174 ( L_157 ) ;
V_6 -> V_448 ++ ;
F_5 ( V_2 , V_160 , V_456 ) ;
}
if ( V_157 & V_457 ) {
F_174 ( L_158 ) ;
V_6 -> V_448 ++ ;
F_5 ( V_2 , V_160 ,
V_457 ) ;
}
V_6 -> V_446 -- ;
F_67 ( V_6 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
F_174 ( L_45 ) ;
}
static T_6 F_176 ( int V_458 , void * V_37 )
{
struct V_5 * V_6 = V_37 ;
T_1 V_157 , V_158 ;
if ( ! V_37 )
return V_459 ;
F_177 ( & V_6 -> V_68 ) ;
if ( ! ( V_6 -> V_49 & V_136 ) ) {
goto V_460;
}
F_1 ( V_6 -> V_33 , V_137 , & V_158 ) ;
F_1 ( V_6 -> V_33 , V_160 , & V_157 ) ;
if ( V_157 == 0xFFFFFFFF ) {
F_27 (KERN_WARNING DRV_NAME L_159 ) ;
goto V_460;
}
V_157 &= V_138 ;
if ( ! ( V_157 & V_158 ) ) {
goto V_460;
}
F_68 ( V_6 ) ;
F_178 ( & V_6 -> V_461 ) ;
F_179 ( & V_6 -> V_68 ) ;
return V_462 ;
V_460:
F_179 ( & V_6 -> V_68 ) ;
return V_459 ;
}
static T_7 F_180 ( struct V_463 * V_412 ,
struct V_1 * V_2 , int V_464 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
unsigned long V_62 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( ! ( V_6 -> V_49 & V_166 ) ) {
F_31 ( L_160 ) ;
V_6 -> V_33 -> V_330 . V_465 ++ ;
F_38 ( V_2 ) ;
goto V_71;
}
if ( F_44 ( & V_6 -> V_413 ) )
goto V_71;
V_59 = V_6 -> V_413 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
V_61 -> V_81 . V_411 . V_412 = V_412 ;
F_165 ( L_161 , V_412 -> V_429 [ 0 ] -> V_14 ) ;
F_33 ( V_466 , V_412 -> V_429 [ 0 ] -> V_37 , V_412 -> V_429 [ 0 ] -> V_14 ) ;
V_61 -> V_79 = V_80 ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_414 ) ;
F_48 ( V_59 , & V_6 -> V_425 ) ;
F_49 ( & V_6 -> V_428 ) ;
F_51 ( V_6 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
return V_467 ;
V_71:
F_38 ( V_2 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
return V_468 ;
}
static int F_181 ( struct V_5 * V_6 )
{
int V_19 , V_40 , V_63 = - V_31 ;
void * V_469 ;
T_8 V_470 ;
V_6 -> V_471 =
F_135 ( V_472 * sizeof( struct V_60 ) ,
V_239 ) ;
if ( ! V_6 -> V_471 )
return - V_240 ;
for ( V_19 = 0 ; V_19 < V_472 ; V_19 ++ ) {
V_469 = F_182 ( V_6 -> V_261 ,
sizeof( struct V_306 ) , & V_470 ) ;
if ( ! V_469 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_162
L_163 , priv->net_dev->name) ;
V_63 = - V_240 ;
break;
}
memset ( V_469 , 0 , sizeof( struct V_306 ) ) ;
V_6 -> V_471 [ V_19 ] . type = V_399 ;
V_6 -> V_471 [ V_19 ] . V_81 . V_82 . V_57 =
(struct V_306 * ) V_469 ;
V_6 -> V_471 [ V_19 ] . V_81 . V_82 . V_419 = V_470 ;
}
if ( V_19 == V_472 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_19 ; V_40 ++ ) {
F_183 ( V_6 -> V_261 ,
sizeof( struct V_306 ) ,
V_6 -> V_471 [ V_40 ] . V_81 . V_82 . V_57 ,
V_6 -> V_471 [ V_40 ] . V_81 . V_82 .
V_419 ) ;
}
F_133 ( V_6 -> V_471 ) ;
V_6 -> V_471 = NULL ;
return V_63 ;
}
static int F_184 ( struct V_5 * V_6 )
{
int V_19 ;
F_185 ( & V_6 -> V_75 ) ;
F_185 ( & V_6 -> V_91 ) ;
for ( V_19 = 0 ; V_19 < V_472 ; V_19 ++ )
F_48 ( & V_6 -> V_471 [ V_19 ] . V_78 , & V_6 -> V_75 ) ;
F_168 ( & V_6 -> V_90 , V_19 ) ;
return 0 ;
}
static void F_186 ( struct V_5 * V_6 )
{
int V_19 ;
if ( ! V_6 -> V_471 )
return;
for ( V_19 = 0 ; V_19 < V_472 ; V_19 ++ ) {
F_183 ( V_6 -> V_261 ,
sizeof( struct V_306 ) ,
V_6 -> V_471 [ V_19 ] . V_81 . V_82 . V_57 ,
V_6 -> V_471 [ V_19 ] . V_81 . V_82 .
V_419 ) ;
}
F_133 ( V_6 -> V_471 ) ;
V_6 -> V_471 = NULL ;
}
static T_9 F_187 ( struct V_473 * V_319 , struct V_474 * V_475 ,
char * V_15 )
{
struct V_261 * V_261 = F_108 ( V_319 , struct V_261 , V_2 ) ;
char * V_39 = V_15 ;
int V_19 , V_40 ;
T_1 V_4 ;
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ ) {
V_39 += sprintf ( V_39 , L_164 , V_19 * 16 ) ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 += 4 ) {
F_188 ( V_261 , V_19 * 16 + V_40 , & V_4 ) ;
V_39 += sprintf ( V_39 , L_165 , V_4 ) ;
}
V_39 += sprintf ( V_39 , L_166 ) ;
}
return V_39 - V_15 ;
}
static T_9 F_189 ( struct V_473 * V_319 , struct V_474 * V_475 ,
char * V_15 )
{
struct V_5 * V_470 = F_190 ( V_319 ) ;
return sprintf ( V_15 , L_167 , ( int ) V_470 -> V_187 ) ;
}
static T_9 F_191 ( struct V_473 * V_319 , struct V_474 * V_475 ,
char * V_15 )
{
struct V_5 * V_470 = F_190 ( V_319 ) ;
return sprintf ( V_15 , L_167 , ( int ) V_470 -> V_49 ) ;
}
static T_9 F_192 ( struct V_473 * V_319 , struct V_474 * V_475 ,
char * V_15 )
{
struct V_5 * V_470 = F_190 ( V_319 ) ;
return sprintf ( V_15 , L_167 , ( int ) V_470 -> V_476 ) ;
}
static T_9 F_193 ( struct V_473 * V_319 , struct V_474 * V_475 ,
char * V_15 )
{
int V_19 ;
struct V_5 * V_6 = F_190 ( V_319 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
char * V_39 = V_15 ;
T_1 V_4 = 0 ;
V_39 += sprintf ( V_39 , L_168 , L_169 ) ;
for ( V_19 = 0 ; V_19 < F_104 ( V_477 ) ; V_19 ++ ) {
F_1 ( V_2 , V_477 [ V_19 ] . V_8 , & V_4 ) ;
V_39 += sprintf ( V_39 , L_170 ,
V_477 [ V_19 ] . V_51 , V_477 [ V_19 ] . V_8 , V_4 ) ;
}
return V_39 - V_15 ;
}
static T_9 F_194 ( struct V_473 * V_319 , struct V_474 * V_475 ,
char * V_15 )
{
struct V_5 * V_6 = F_190 ( V_319 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
char * V_39 = V_15 ;
int V_19 ;
V_39 += sprintf ( V_39 , L_168 , L_171 ) ;
for ( V_19 = 0 ; V_19 < F_104 ( V_478 ) ; V_19 ++ ) {
T_3 V_479 ;
T_2 V_480 ;
T_1 V_481 ;
switch ( V_478 [ V_19 ] . V_482 ) {
case 1 :
F_19 ( V_2 , V_478 [ V_19 ] . V_8 , & V_479 ) ;
V_39 += sprintf ( V_39 , L_172 ,
V_478 [ V_19 ] . V_51 , V_478 [ V_19 ] . V_8 ,
V_479 ) ;
break;
case 2 :
F_17 ( V_2 , V_478 [ V_19 ] . V_8 , & V_480 ) ;
V_39 += sprintf ( V_39 , L_173 ,
V_478 [ V_19 ] . V_51 , V_478 [ V_19 ] . V_8 ,
V_480 ) ;
break;
case 4 :
F_15 ( V_2 , V_478 [ V_19 ] . V_8 , & V_481 ) ;
V_39 += sprintf ( V_39 , L_170 ,
V_478 [ V_19 ] . V_51 , V_478 [ V_19 ] . V_8 ,
V_481 ) ;
break;
}
}
return V_39 - V_15 ;
}
static T_9 F_195 ( struct V_473 * V_319 , struct V_474 * V_475 ,
char * V_15 )
{
struct V_5 * V_6 = F_190 ( V_319 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
static unsigned long V_483 = 0 ;
int V_14 = 0 ;
T_1 V_484 [ 4 ] ;
int V_19 ;
char line [ 81 ] ;
if ( V_483 >= 0x30000 )
V_483 = 0 ;
while ( V_14 < V_485 - 128 && V_483 < 0x30000 ) {
if ( V_6 -> V_313 [ 0 ] )
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ )
V_484 [ V_19 ] =
* ( T_1 * ) F_137 ( V_483 + V_19 * 4 ) ;
else
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ )
F_15 ( V_2 , V_483 + V_19 * 4 , & V_484 [ V_19 ] ) ;
if ( V_6 -> V_486 )
V_14 += sprintf ( V_15 + V_14 ,
L_174
L_174
L_174
L_174 ,
( ( T_3 * ) V_484 ) [ 0x0 ] ,
( ( T_3 * ) V_484 ) [ 0x1 ] ,
( ( T_3 * ) V_484 ) [ 0x2 ] ,
( ( T_3 * ) V_484 ) [ 0x3 ] ,
( ( T_3 * ) V_484 ) [ 0x4 ] ,
( ( T_3 * ) V_484 ) [ 0x5 ] ,
( ( T_3 * ) V_484 ) [ 0x6 ] ,
( ( T_3 * ) V_484 ) [ 0x7 ] ,
( ( T_3 * ) V_484 ) [ 0x8 ] ,
( ( T_3 * ) V_484 ) [ 0x9 ] ,
( ( T_3 * ) V_484 ) [ 0xa ] ,
( ( T_3 * ) V_484 ) [ 0xb ] ,
( ( T_3 * ) V_484 ) [ 0xc ] ,
( ( T_3 * ) V_484 ) [ 0xd ] ,
( ( T_3 * ) V_484 ) [ 0xe ] ,
( ( T_3 * ) V_484 ) [ 0xf ] ) ;
else
V_14 += sprintf ( V_15 + V_14 , L_19 ,
F_32 ( line , sizeof( line ) ,
( T_3 * ) V_484 , 16 , V_483 ) ) ;
V_483 += 16 ;
}
return V_14 ;
}
static T_9 F_196 ( struct V_473 * V_319 , struct V_474 * V_475 ,
const char * V_15 , T_4 V_36 )
{
struct V_5 * V_6 = F_190 ( V_319 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
const char * V_470 = V_15 ;
( void ) V_2 ;
if ( V_36 < 1 )
return V_36 ;
if ( V_470 [ 0 ] == '1' ||
( V_36 >= 2 && tolower ( V_470 [ 0 ] ) == 'o' && tolower ( V_470 [ 1 ] ) == 'n' ) ) {
F_31 ( L_175 ,
V_2 -> V_51 ) ;
V_6 -> V_486 = 1 ;
} else if ( V_470 [ 0 ] == '0' || ( V_36 >= 2 && tolower ( V_470 [ 0 ] ) == 'o' &&
tolower ( V_470 [ 1 ] ) == 'f' ) ) {
F_31 ( L_176 ,
V_2 -> V_51 ) ;
V_6 -> V_486 = 0 ;
} else if ( tolower ( V_470 [ 0 ] ) == 'r' ) {
F_31 ( L_177 , V_2 -> V_51 ) ;
F_132 ( V_6 ) ;
} else
F_31 ( L_178
L_179 , V_2 -> V_51 ) ;
return V_36 ;
}
static T_9 F_197 ( struct V_473 * V_319 , struct V_474 * V_475 ,
char * V_15 )
{
struct V_5 * V_6 = F_190 ( V_319 ) ;
T_1 V_4 = 0 ;
int V_14 = 0 ;
T_1 V_487 ;
static int V_483 = 0 ;
if ( V_6 -> V_49 & V_488 )
return 0 ;
if ( V_483 >= F_104 ( V_489 ) )
V_483 = 0 ;
while ( V_14 < V_485 - 128 && V_483 < F_104 ( V_489 ) ) {
V_487 = sizeof( T_1 ) ;
if ( F_26 ( V_6 , V_489 [ V_483 ] . V_398 , & V_4 ,
& V_487 ) )
V_14 += sprintf ( V_15 + V_14 , L_180 ,
V_489 [ V_483 ] . V_398 ,
V_489 [ V_483 ] . V_490 ) ;
else
V_14 += sprintf ( V_15 + V_14 , L_181 ,
V_489 [ V_483 ] . V_398 , V_4 ,
V_489 [ V_483 ] . V_490 ) ;
V_483 ++ ;
}
return V_14 ;
}
static T_9 F_198 ( struct V_473 * V_319 , struct V_474 * V_475 ,
char * V_15 )
{
struct V_5 * V_6 = F_190 ( V_319 ) ;
char * V_39 = V_15 ;
V_39 += sprintf ( V_39 , L_182 ,
V_6 -> V_447 , V_6 -> V_453 ,
V_6 -> V_451 , V_6 -> V_448 ) ;
V_39 += sprintf ( V_39 , L_183 , V_6 -> V_264 ) ;
V_39 += sprintf ( V_39 , L_184 , V_6 -> V_491 ) ;
#ifdef F_128
V_39 += sprintf ( V_39 , L_185 ,
V_6 -> V_313 [ 0 ] ? L_186 : L_187 ) ;
#endif
return V_39 - V_15 ;
}
static int F_199 ( struct V_5 * V_6 , T_1 V_316 )
{
int V_63 ;
if ( V_316 == V_6 -> V_150 -> V_198 )
return 0 ;
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
switch ( V_316 ) {
case V_430 :
V_6 -> V_33 -> type = V_221 ;
break;
case V_435 :
V_6 -> V_33 -> type = V_221 ;
break;
#ifdef F_158
case V_199 :
V_6 -> V_492 = V_6 -> V_150 -> V_198 ;
V_6 -> V_33 -> type = V_493 ;
break;
#endif
}
V_6 -> V_150 -> V_198 = V_316 ;
#ifdef F_61
V_120 . V_121 = 0 ;
#endif
F_27 ( V_214 L_189 , V_6 -> V_33 -> V_51 ) ;
V_6 -> V_47 = 0 ;
F_35 ( V_6 ) ;
return 0 ;
}
static T_9 F_200 ( struct V_473 * V_319 , struct V_474 * V_475 ,
char * V_15 )
{
struct V_5 * V_6 = F_190 ( V_319 ) ;
int V_14 = 0 ;
#define F_201 ( T_10 , T_11 ) len += sprintf(buf + len, # x ": %" y "\n", priv-> x)
if ( V_6 -> V_49 & V_166 )
V_14 += sprintf ( V_15 + V_14 , L_190 ,
F_36 () - V_6 -> V_285 ) ;
else
V_14 += sprintf ( V_15 + V_14 , L_191 ) ;
F_201 ( V_150 -> V_494 . V_495 [ V_6 -> V_150 -> V_494 . V_496 ] , L_192 ) ;
F_201 ( V_49 , L_193 ) ;
F_201 ( V_187 , L_193 ) ;
F_201 ( V_476 , L_193 ) ;
V_14 +=
sprintf ( V_15 + V_14 , L_194 ,
( unsigned long ) V_6 -> V_497 ) ;
F_201 ( V_69 , L_195 ) ;
F_201 ( V_181 , L_195 ) ;
F_201 ( V_215 , L_195 ) ;
F_201 ( V_76 , L_195 ) ;
F_201 ( V_428 . V_147 , L_195 ) ;
F_201 ( V_428 . V_498 , L_195 ) ;
F_201 ( V_414 . V_147 , L_195 ) ;
F_201 ( V_414 . V_499 , L_195 ) ;
F_201 ( V_90 . V_147 , L_195 ) ;
F_201 ( V_90 . V_499 , L_195 ) ;
F_201 ( V_92 . V_147 , L_195 ) ;
F_201 ( V_92 . V_498 , L_195 ) ;
F_201 ( V_405 . V_147 , L_195 ) ;
F_201 ( V_405 . V_498 , L_195 ) ;
F_201 ( V_418 . V_147 , L_195 ) ;
F_201 ( V_418 . V_499 , L_195 ) ;
F_201 ( V_150 -> V_300 , L_195 ) ;
F_201 ( V_47 , L_195 ) ;
return V_14 ;
}
static T_9 F_202 ( struct V_473 * V_319 , struct V_474 * V_475 ,
char * V_15 )
{
struct V_5 * V_6 = F_190 ( V_319 ) ;
char V_269 [ V_270 + 1 ] ;
T_3 V_274 [ V_230 ] ;
T_1 V_272 = 0 ;
char * V_39 = V_15 ;
unsigned int V_287 ;
int V_267 ;
if ( V_6 -> V_49 & V_488 )
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
static T_9 F_203 ( struct V_500 * V_319 , char * V_15 )
{
return sprintf ( V_15 , L_199 , V_44 ) ;
}
static T_9 F_204 ( struct V_500 * V_319 ,
const char * V_15 , T_4 V_36 )
{
char * V_470 = ( char * ) V_15 ;
T_1 V_4 ;
if ( V_470 [ 1 ] == 'x' || V_470 [ 1 ] == 'X' || V_470 [ 0 ] == 'x' || V_470 [ 0 ] == 'X' ) {
V_470 ++ ;
if ( V_470 [ 0 ] == 'x' || V_470 [ 0 ] == 'X' )
V_470 ++ ;
V_4 = F_205 ( V_470 , & V_470 , 16 ) ;
} else
V_4 = F_205 ( V_470 , & V_470 , 10 ) ;
if ( V_470 == V_15 )
F_31 ( L_200 , V_15 ) ;
else
V_44 = V_4 ;
return F_206 ( V_15 , V_36 ) ;
}
static T_9 F_207 ( struct V_473 * V_319 ,
struct V_474 * V_475 , char * V_15 )
{
struct V_5 * V_6 = F_190 ( V_319 ) ;
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
static T_9 F_208 ( struct V_473 * V_319 ,
struct V_474 * V_475 , const char * V_15 ,
T_4 V_36 )
{
struct V_5 * V_6 = F_190 ( V_319 ) ;
F_35 ( V_6 ) ;
return V_36 ;
}
static T_9 F_209 ( struct V_473 * V_319 , struct V_474 * V_475 ,
char * V_15 )
{
struct V_5 * V_6 = F_190 ( V_319 ) ;
return sprintf ( V_15 , L_203 , V_6 -> V_150 -> V_501 ) ;
}
static T_9 F_210 ( struct V_473 * V_319 , struct V_474 * V_475 ,
const char * V_15 , T_4 V_36 )
{
struct V_5 * V_6 = F_190 ( V_319 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
char V_484 [] = L_204 ;
unsigned long V_14 =
( sizeof( V_484 ) - 1 ) > V_36 ? V_36 : sizeof( V_484 ) - 1 ;
unsigned long V_4 ;
char * V_470 = V_484 ;
( void ) V_2 ;
F_31 ( L_42 ) ;
strncpy ( V_484 , V_15 , V_14 ) ;
V_484 [ V_14 ] = 0 ;
if ( V_470 [ 1 ] == 'x' || V_470 [ 1 ] == 'X' || V_470 [ 0 ] == 'x' || V_470 [ 0 ] == 'X' ) {
V_470 ++ ;
if ( V_470 [ 0 ] == 'x' || V_470 [ 0 ] == 'X' )
V_470 ++ ;
V_4 = F_205 ( V_470 , & V_470 , 16 ) ;
} else
V_4 = F_205 ( V_470 , & V_470 , 10 ) ;
if ( V_470 == V_484 ) {
F_31 ( L_205 , V_2 -> V_51 ) ;
} else {
V_6 -> V_150 -> V_501 = V_4 ;
F_31 ( L_206 , V_6 -> V_150 -> V_501 ) ;
}
F_31 ( L_45 ) ;
return V_14 ;
}
static T_9 F_211 ( struct V_473 * V_319 , struct V_474 * V_475 ,
char * V_15 )
{
struct V_5 * V_6 = F_190 ( V_319 ) ;
int V_4 = ( ( V_6 -> V_49 & V_206 ) ? 0x1 : 0x0 ) |
( F_71 ( V_6 ) ? 0x2 : 0x0 ) ;
return sprintf ( V_15 , L_207 , V_4 ) ;
}
static int F_212 ( struct V_5 * V_6 , int V_502 )
{
if ( ( V_502 ? 1 : 0 ) ==
( V_6 -> V_49 & V_206 ? 1 : 0 ) )
return 0 ;
F_213 ( L_208 ,
V_502 ? L_209 : L_210 ) ;
F_84 ( & V_6 -> V_266 ) ;
if ( V_502 ) {
V_6 -> V_49 |= V_206 ;
F_99 ( V_6 ) ;
} else {
V_6 -> V_49 &= ~ V_206 ;
if ( F_71 ( V_6 ) ) {
F_213 ( L_211
L_212 ) ;
V_6 -> V_215 = 0 ;
F_117 ( V_296 , & V_6 -> V_216 ,
F_97 ( V_53 ) ) ;
} else
F_35 ( V_6 ) ;
}
F_85 ( & V_6 -> V_266 ) ;
return 1 ;
}
static T_9 F_214 ( struct V_473 * V_319 , struct V_474 * V_475 ,
const char * V_15 , T_4 V_36 )
{
struct V_5 * V_6 = F_190 ( V_319 ) ;
F_212 ( V_6 , V_15 [ 0 ] == '1' ) ;
return V_36 ;
}
static int F_215 ( struct V_5 * V_6 , int V_383 )
{
struct V_377 * V_503 = & V_6 -> V_324 ;
F_31 ( L_42 ) ;
V_503 -> V_482 = V_383 * sizeof( struct V_323 ) ;
V_503 -> V_325 =
(struct V_323 * ) F_182 ( V_6 -> V_261 ,
V_503 -> V_482 , & V_503 -> V_406 ) ;
if ( ! V_503 -> V_325 ) {
F_156 ( L_213 ) ;
return - V_240 ;
}
memset ( V_503 -> V_325 , 0 , V_503 -> V_482 ) ;
F_31 ( L_45 ) ;
return 0 ;
}
static void F_216 ( struct V_5 * V_6 )
{
F_31 ( L_42 ) ;
if ( V_6 -> V_324 . V_325 ) {
F_183 ( V_6 -> V_261 , V_6 -> V_324 . V_482 ,
V_6 -> V_324 . V_325 ,
V_6 -> V_324 . V_406 ) ;
V_6 -> V_324 . V_325 = NULL ;
}
F_31 ( L_45 ) ;
}
static int F_217 ( struct V_5 * V_6 ,
struct V_375 * V_503 , int V_383 )
{
F_31 ( L_42 ) ;
memset ( V_503 , 0 , sizeof( struct V_375 ) ) ;
V_503 -> V_383 = V_383 ;
V_503 -> V_482 = V_383 * sizeof( struct V_392 ) ;
V_503 -> V_325 = F_182 ( V_6 -> V_261 , V_503 -> V_482 , & V_503 -> V_406 ) ;
if ( ! V_503 -> V_325 ) {
F_31
( L_214 ) ;
return - V_240 ;
}
memset ( V_503 -> V_325 , 0 , V_503 -> V_482 ) ;
F_31 ( L_45 ) ;
return 0 ;
}
static void F_218 ( struct V_5 * V_6 , struct V_375 * V_503 )
{
F_31 ( L_42 ) ;
if ( ! V_503 )
return;
if ( V_503 -> V_325 ) {
F_183 ( V_6 -> V_261 , V_503 -> V_482 , V_503 -> V_325 , V_503 -> V_406 ) ;
V_503 -> V_325 = NULL ;
}
F_31 ( L_45 ) ;
}
static void F_219 ( struct V_5 * V_6 ,
struct V_375 * V_503 , T_1 V_504 , T_1 V_482 ,
T_1 V_109 , T_1 V_379 )
{
F_31 ( L_42 ) ;
F_31 ( L_215 , V_503 -> V_325 ,
( T_1 ) V_503 -> V_406 ) ;
F_5 ( V_6 -> V_33 , V_504 , V_503 -> V_406 ) ;
F_5 ( V_6 -> V_33 , V_482 , V_503 -> V_383 ) ;
F_5 ( V_6 -> V_33 , V_109 , V_503 -> V_400 ) ;
F_5 ( V_6 -> V_33 , V_379 , V_503 -> V_77 ) ;
F_31 ( L_45 ) ;
}
static void F_220 ( struct V_5 * V_6 )
{
V_6 -> V_215 = 1 ;
V_6 -> V_181 = 1 ;
F_221 ( & V_6 -> V_52 ) ;
F_221 ( & V_6 -> V_295 ) ;
F_221 ( & V_6 -> V_286 ) ;
F_221 ( & V_6 -> V_182 ) ;
F_221 ( & V_6 -> V_216 ) ;
F_222 ( & V_6 -> V_299 ) ;
F_221 ( & V_6 -> V_298 ) ;
}
static int F_223 ( struct V_5 * V_6 )
{
int V_19 , V_40 , V_63 = - V_31 ;
void * V_469 ;
T_8 V_470 ;
F_31 ( L_42 ) ;
V_63 = F_217 ( V_6 , & V_6 -> V_391 , V_505 ) ;
if ( V_63 ) {
F_62 ( L_216 ,
V_6 -> V_33 -> V_51 ) ;
return V_63 ;
}
V_6 -> V_506 =
F_135 ( V_507 * sizeof( struct V_60 ) ,
V_314 ) ;
if ( ! V_6 -> V_506 ) {
F_27 (KERN_ERR DRV_NAME
L_217 ,
priv->net_dev->name) ;
F_218 ( V_6 , & V_6 -> V_391 ) ;
return - V_240 ;
}
for ( V_19 = 0 ; V_19 < V_507 ; V_19 ++ ) {
V_469 = F_182 ( V_6 -> V_261 ,
sizeof( struct V_422 ) ,
& V_470 ) ;
if ( ! V_469 ) {
F_27 (KERN_ERR DRV_NAME
L_218 L_163 ,
priv->net_dev->name) ;
V_63 = - V_240 ;
break;
}
V_6 -> V_506 [ V_19 ] . type = V_401 ;
V_6 -> V_506 [ V_19 ] . V_81 . V_411 . V_37 =
(struct V_422 * ) V_469 ;
V_6 -> V_506 [ V_19 ] . V_81 . V_411 . V_443 = V_470 ;
V_6 -> V_506 [ V_19 ] . V_81 . V_411 . V_412 = NULL ;
}
if ( V_19 == V_507 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_19 ; V_40 ++ ) {
F_183 ( V_6 -> V_261 ,
sizeof( struct V_422 ) ,
V_6 -> V_506 [ V_40 ] . V_81 . V_411 . V_37 ,
V_6 -> V_506 [ V_40 ] . V_81 . V_411 .
V_443 ) ;
}
F_133 ( V_6 -> V_506 ) ;
V_6 -> V_506 = NULL ;
return V_63 ;
}
static void F_224 ( struct V_5 * V_6 )
{
int V_19 ;
F_31 ( L_42 ) ;
F_185 ( & V_6 -> V_397 ) ;
F_225 ( & V_6 -> V_405 ) ;
F_185 ( & V_6 -> V_425 ) ;
F_185 ( & V_6 -> V_413 ) ;
F_225 ( & V_6 -> V_428 ) ;
F_225 ( & V_6 -> V_414 ) ;
for ( V_19 = 0 ; V_19 < V_507 ; V_19 ++ ) {
if ( V_6 -> V_506 [ V_19 ] . V_81 . V_411 . V_412 ) {
F_166 ( V_6 -> V_506 [ V_19 ] . V_81 . V_411 .
V_412 ) ;
V_6 -> V_506 [ V_19 ] . V_81 . V_411 . V_412 = NULL ;
}
F_48 ( & V_6 -> V_506 [ V_19 ] . V_78 , & V_6 -> V_413 ) ;
}
F_168 ( & V_6 -> V_414 , V_19 ) ;
V_6 -> V_391 . V_400 = 0 ;
V_6 -> V_391 . V_417 = V_6 -> V_391 . V_383 ;
V_6 -> V_391 . V_77 = 0 ;
F_225 ( & V_6 -> V_418 ) ;
F_168 ( & V_6 -> V_418 , V_6 -> V_391 . V_417 ) ;
F_219 ( V_6 , & V_6 -> V_391 ,
V_508 ,
V_509 ,
V_403 ,
V_404 ) ;
F_31 ( L_45 ) ;
}
static void F_226 ( struct V_5 * V_6 )
{
int V_19 ;
F_31 ( L_42 ) ;
F_218 ( V_6 , & V_6 -> V_391 ) ;
if ( ! V_6 -> V_506 )
return;
for ( V_19 = 0 ; V_19 < V_507 ; V_19 ++ ) {
if ( V_6 -> V_506 [ V_19 ] . V_81 . V_411 . V_412 ) {
F_166 ( V_6 -> V_506 [ V_19 ] . V_81 . V_411 .
V_412 ) ;
V_6 -> V_506 [ V_19 ] . V_81 . V_411 . V_412 = NULL ;
}
if ( V_6 -> V_506 [ V_19 ] . V_81 . V_411 . V_37 )
F_183 ( V_6 -> V_261 ,
sizeof( struct V_422 ) ,
V_6 -> V_506 [ V_19 ] . V_81 . V_411 .
V_37 ,
V_6 -> V_506 [ V_19 ] . V_81 . V_411 .
V_443 ) ;
}
F_133 ( V_6 -> V_506 ) ;
V_6 -> V_506 = NULL ;
F_31 ( L_45 ) ;
}
static int F_227 ( struct V_5 * V_6 )
{
int V_19 , V_40 , V_63 = - V_31 ;
F_31 ( L_42 ) ;
V_63 = F_217 ( V_6 , & V_6 -> V_340 , V_328 ) ;
if ( V_63 ) {
F_31 ( L_219 ) ;
return V_63 ;
}
V_63 = F_215 ( V_6 , V_328 ) ;
if ( V_63 ) {
F_31 ( L_220 ) ;
F_218 ( V_6 , & V_6 -> V_340 ) ;
return V_63 ;
}
V_6 -> V_333 = F_135 ( V_328 *
sizeof( struct V_307 ) ,
V_239 ) ;
if ( ! V_6 -> V_333 ) {
F_31 ( L_221 ) ;
F_218 ( V_6 , & V_6 -> V_340 ) ;
F_216 ( V_6 ) ;
return - V_240 ;
}
for ( V_19 = 0 ; V_19 < V_328 ; V_19 ++ ) {
struct V_307 * V_61 = & V_6 -> V_333 [ V_19 ] ;
V_63 = F_129 ( V_6 , V_61 ) ;
if ( F_142 ( V_63 ) ) {
V_63 = - V_240 ;
break;
}
V_6 -> V_340 . V_325 [ V_19 ] . V_341 = V_61 -> V_311 ;
V_6 -> V_340 . V_325 [ V_19 ] . V_407 = V_338 ;
V_6 -> V_324 . V_325 [ V_19 ] . V_359 = 0 ;
}
if ( V_19 == V_328 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_19 ; V_40 ++ ) {
F_146 ( V_6 -> V_261 , V_6 -> V_333 [ V_40 ] . V_311 ,
sizeof( struct V_307 ) ,
V_312 ) ;
F_228 ( V_6 -> V_333 [ V_40 ] . V_308 ) ;
}
F_133 ( V_6 -> V_333 ) ;
V_6 -> V_333 = NULL ;
F_218 ( V_6 , & V_6 -> V_340 ) ;
F_216 ( V_6 ) ;
return V_63 ;
}
static void F_229 ( struct V_5 * V_6 )
{
F_31 ( L_42 ) ;
V_6 -> V_340 . V_400 = 0 ;
V_6 -> V_340 . V_417 = V_6 -> V_340 . V_383 - 1 ;
V_6 -> V_340 . V_77 = V_6 -> V_340 . V_383 - 1 ;
F_225 ( & V_6 -> V_510 ) ;
F_168 ( & V_6 -> V_510 , V_6 -> V_340 . V_417 ) ;
F_219 ( V_6 , & V_6 -> V_340 ,
V_511 ,
V_512 ,
V_381 ,
V_382 ) ;
F_5 ( V_6 -> V_33 , V_513 ,
V_6 -> V_324 . V_406 ) ;
F_31 ( L_45 ) ;
}
static void F_230 ( struct V_5 * V_6 )
{
int V_19 ;
F_31 ( L_42 ) ;
F_218 ( V_6 , & V_6 -> V_340 ) ;
F_216 ( V_6 ) ;
if ( ! V_6 -> V_333 )
return;
for ( V_19 = 0 ; V_19 < V_328 ; V_19 ++ ) {
if ( V_6 -> V_333 [ V_19 ] . V_310 ) {
F_146 ( V_6 -> V_261 ,
V_6 -> V_333 [ V_19 ] . V_311 ,
sizeof( struct V_309 ) ,
V_312 ) ;
F_228 ( V_6 -> V_333 [ V_19 ] . V_308 ) ;
}
}
F_133 ( V_6 -> V_333 ) ;
V_6 -> V_333 = NULL ;
F_31 ( L_45 ) ;
}
static int F_231 ( struct V_5 * V_6 )
{
T_1 V_287 = V_230 ;
T_3 V_8 [ V_230 ] ;
int V_63 ;
V_63 = F_26 ( V_6 , V_514 , V_8 , & V_287 ) ;
if ( V_63 ) {
F_31 ( L_222 ) ;
return - V_70 ;
}
memcpy ( V_6 -> V_33 -> V_515 , V_8 , V_230 ) ;
F_31 ( L_223 , V_6 -> V_33 -> V_515 ) ;
return 0 ;
}
static int F_232 ( struct V_5 * V_6 , int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_516 ,
. V_88 = 0 ,
. V_65 = V_230
} ;
int V_63 ;
F_42 ( L_224 ) ;
F_31 ( L_42 ) ;
if ( V_6 -> V_187 & V_517 ) {
memcpy ( V_57 . V_67 , V_6 -> V_229 , V_230 ) ;
memcpy ( V_6 -> V_33 -> V_515 , V_6 -> V_229 , V_230 ) ;
} else
memcpy ( V_57 . V_67 , V_6 -> V_33 -> V_515 ,
V_230 ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
F_31 ( L_45 ) ;
return V_63 ;
}
static int F_233 ( struct V_5 * V_6 , T_1 V_518 ,
int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_519 ,
. V_88 = 0 ,
. V_65 = sizeof( T_1 )
} ;
int V_63 ;
switch ( V_518 ) {
case V_430 :
V_57 . V_67 [ 0 ] = V_520 ;
break;
case V_435 :
V_57 . V_67 [ 0 ] = V_521 ;
break;
}
F_42 ( L_225 ,
V_518 == V_521 ? L_226 : L_227 ) ;
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
static int F_234 ( struct V_5 * V_6 , T_1 V_245 ,
int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_522 ,
. V_88 = 0 ,
. V_65 = sizeof( T_1 )
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_245 ;
F_42 ( L_228 , V_245 ) ;
if ( V_6 -> V_150 -> V_198 == V_430 )
return 0 ;
if ( ( V_245 != 0 ) &&
( ( V_245 < V_523 ) || ( V_245 > V_524 ) ) )
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
V_6 -> V_187 |= V_525 ;
else
V_6 -> V_187 &= ~ V_525 ;
V_6 -> V_245 = V_245 ;
if ( ! V_288 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static int F_235 ( struct V_5 * V_6 , int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_526 ,
. V_88 = 0 ,
. V_65 = 12 ,
} ;
T_1 V_527 , V_14 = sizeof( T_1 ) ;
int V_63 ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
if ( V_6 -> V_150 -> V_198 == V_435 )
V_57 . V_67 [ 0 ] |= V_528 ;
V_57 . V_67 [ 0 ] |= V_529 |
V_530 | V_531 ;
if ( ! ( V_6 -> V_187 & V_532 ) )
V_57 . V_67 [ 0 ] |= V_533 ;
V_63 = F_26 ( V_6 ,
V_534 ,
& V_527 , & V_14 ) ;
if ( V_63 )
V_527 = V_535 ;
V_57 . V_67 [ 1 ] = V_536 ;
V_57 . V_67 [ 2 ] = V_536 & V_527 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
#if ! F_236 ( V_537 ) && ! F_236 ( V_538 )
V_57 . V_56 = V_539 ;
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
static int F_237 ( struct V_5 * V_6 , T_1 V_540 ,
int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_541 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_540 & V_542 ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
F_41 ( V_6 , & V_57 ) ;
V_57 . V_56 = V_543 ;
F_41 ( V_6 , & V_57 ) ;
V_57 . V_56 = V_544 ;
F_41 ( V_6 , & V_57 ) ;
if ( ! V_288 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_6 -> V_545 = V_540 ;
return 0 ;
}
static int F_238 ( struct V_5 * V_6 , int V_546 )
{
struct V_56 V_57 = {
. V_56 = V_547 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_546 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
if ( V_546 == V_548 )
V_6 -> V_549 = F_239 ( V_6 -> V_549 ) ;
else
V_6 -> V_549 = V_550 | V_546 ;
#ifdef F_240
if ( V_6 -> V_518 == V_551 && V_6 -> V_552 != V_553 ) {
V_57 . V_56 = V_554 ;
V_57 . V_67 [ 0 ] = ( T_1 ) V_6 -> V_552 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
}
#endif
return 0 ;
}
static int F_241 ( struct V_5 * V_6 , T_1 V_555 )
{
struct V_56 V_57 = {
. V_56 = V_556 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
if ( V_555 & V_557 )
V_57 . V_67 [ 0 ] = V_558 ;
else
V_57 . V_67 [ 0 ] = V_555 & ~ V_557 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_559 = V_555 ;
return 0 ;
}
static int F_242 ( struct V_5 * V_6 , T_1 V_560 )
{
struct V_56 V_57 = {
. V_56 = V_561 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_560 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_562 = V_560 ;
return 0 ;
}
static int F_243 ( struct V_5 * V_6 , T_1 V_560 )
{
struct V_56 V_57 = {
. V_56 = V_563 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_560 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_564 = V_560 ;
return 0 ;
}
static int F_244 ( struct V_5 * V_6 , T_3 * V_274 ,
int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_565 ,
. V_88 = 0 ,
. V_65 = ( V_274 == NULL ) ? 0 : V_230
} ;
int V_63 ;
#ifdef F_128
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
static int F_245 ( struct V_5 * V_6 )
{
struct V_56 V_57 = {
. V_56 = V_566 ,
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
static int F_246 ( struct V_5 * V_6 ,
struct V_567 * V_568 ,
int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_569 ,
. V_88 = 0 ,
. V_65 = sizeof( struct V_567 ) ,
} ;
int V_63 ;
F_42 ( L_233 ) ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
memcpy ( V_57 . V_67 , V_568 ,
sizeof( struct V_567 ) ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_288 ) {
if ( F_83 ( V_6 ) )
V_63 = - V_70 ;
}
return V_63 ;
}
static int F_247 ( struct V_5 * V_6 ,
int V_570 ,
int V_571 ,
int V_572 ,
int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_573 ,
. V_88 = 0 ,
. V_65 = sizeof(struct V_574 )
} ;
struct V_574 * V_575 =
(struct V_574 * ) & V_57 . V_67 ;
int V_63 ;
memset ( V_575 , 0 , sizeof( * V_575 ) ) ;
V_575 -> V_570 = V_570 ;
V_575 -> V_572 = V_572 ;
switch ( V_571 ) {
default:
case V_576 :
V_575 -> V_577 = V_578 ;
break;
case V_579 :
V_575 -> V_577 = V_580 |
V_581 ;
break;
case V_582 :
V_575 -> V_577 = V_580 |
V_581 | V_583 ;
break;
case V_584 :
V_575 -> V_577 = V_580 |
V_581 | V_585 ;
break;
case V_586 :
V_575 -> V_577 = V_580 |
V_581 | V_583 | V_587 ;
break;
}
F_42
( L_234 ,
V_575 -> V_570 , V_575 -> V_577 , V_571 ) ;
V_575 -> V_588 = 0 ;
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
static int F_248 ( struct V_5 * V_6 , T_1 V_589 )
{
struct V_56 V_57 = {
. V_56 = V_554 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 = 0 ;
T_1 V_317 = V_589 ;
if ( V_589 != V_590 )
V_317 = ( V_589 - V_591 ) * 16 /
( V_592 - V_591 ) ;
V_57 . V_67 [ 0 ] = V_317 ;
if ( V_6 -> V_150 -> V_198 == V_435 )
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_63 )
V_6 -> V_589 = V_589 ;
return 0 ;
}
static int F_249 ( struct V_5 * V_6 ,
T_1 V_593 , int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_594 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_593 ;
F_31 ( L_42 ) ;
if ( V_6 -> V_150 -> V_198 == V_435 ) {
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
F_224 ( V_6 ) ;
F_229 ( V_6 ) ;
F_184 ( V_6 ) ;
}
static void F_250 ( struct V_5 * V_6 )
{
F_226 ( V_6 ) ;
F_230 ( V_6 ) ;
F_186 ( V_6 ) ;
}
static int F_251 ( struct V_5 * V_6 )
{
if ( F_223 ( V_6 ) ||
F_227 ( V_6 ) || F_181 ( V_6 ) )
goto V_123;
return 0 ;
V_123:
F_226 ( V_6 ) ;
F_230 ( V_6 ) ;
F_186 ( V_6 ) ;
return - V_240 ;
}
static int F_252 ( struct V_5 * V_6 , T_1 V_62 ,
int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_595 ,
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
static int F_253 ( struct V_5 * V_6 ,
int V_596 , char * V_597 , int V_14 , int V_288 )
{
int V_598 = V_14 ? ( V_14 <= 5 ? 5 : 13 ) : 0 ;
struct V_56 V_57 = {
. V_56 = V_599 ,
. V_88 = 0 ,
. V_65 = sizeof( struct V_600 ) ,
} ;
struct V_600 * V_601 = ( void * ) V_57 . V_67 ;
int V_63 ;
F_42 ( L_236 ,
V_596 , V_598 , V_14 ) ;
V_601 -> V_596 = V_596 ;
V_601 -> V_14 = V_598 ;
if ( V_598 ) {
memcpy ( V_601 -> V_597 , V_597 , V_14 ) ;
memset ( V_601 -> V_597 + V_14 , 0 , V_598 - V_14 ) ;
}
if ( V_598 == 0 )
F_254 ( L_237 ,
V_6 -> V_33 -> V_51 , V_601 -> V_596 ) ;
else if ( V_598 == 5 )
F_254 ( L_238 V_602 L_166 ,
V_6 -> V_33 -> V_51 , V_601 -> V_596 , V_601 -> V_14 ,
F_255 ( V_601 -> V_597 ) ) ;
else
F_254 ( L_238 V_603
L_166 ,
V_6 -> V_33 -> V_51 , V_601 -> V_596 , V_601 -> V_14 ,
F_256 ( V_601 -> V_597 ) ) ;
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
int V_604 = F_83 ( V_6 ) ;
if ( V_63 == 0 )
V_63 = V_604 ;
}
return V_63 ;
}
static int F_257 ( struct V_5 * V_6 ,
int V_596 , int V_288 )
{
struct V_56 V_57 = {
. V_56 = V_605 ,
. V_88 = 0 ,
. V_65 = 4 ,
. V_67 = { V_596 } ,
} ;
int V_63 ;
F_42 ( L_239 , V_596 ) ;
if ( V_596 < 0 || V_596 > 3 )
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
static int F_258 ( struct V_5 * V_6 , int V_288 )
{
int V_19 , V_63 , V_570 , V_606 , V_607 ;
if ( ! ( V_6 -> V_49 & V_72 ) )
return 0 ;
if ( ! V_288 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
if ( ! V_6 -> V_150 -> V_190 . V_192 ) {
V_63 =
F_247 ( V_6 , V_608 ,
V_576 , 0 , 1 ) ;
} else {
V_570 = V_608 ;
if ( V_6 -> V_150 -> V_190 . V_62 & V_609 ) {
if ( V_6 -> V_150 -> V_190 . V_570 == V_610 )
V_570 = V_611 ;
else if ( V_6 -> V_150 -> V_190 . V_570 == V_612 )
V_570 = V_613 ;
}
V_606 = V_576 ;
if ( V_6 -> V_150 -> V_190 . V_62 & V_614 )
V_606 = V_6 -> V_150 -> V_190 . V_43 ;
V_607 = 0 ;
if ( V_6 -> V_150 -> V_190 . V_62 & V_615 )
V_607 = V_6 -> V_150 -> V_190 . V_616 ;
V_63 =
F_247 ( V_6 , V_570 , V_606 ,
V_607 , 1 ) ;
}
if ( V_63 )
goto exit;
if ( V_6 -> V_150 -> V_190 . V_192 ) {
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
if ( ! ( V_6 -> V_150 -> V_190 . V_62 & ( 1 << V_19 ) ) ) {
memset ( V_6 -> V_150 -> V_190 . V_617 [ V_19 ] , 0 , V_618 ) ;
V_6 -> V_150 -> V_190 . V_619 [ V_19 ] = 0 ;
} else {
V_63 = F_253 ( V_6 , V_19 ,
V_6 -> V_150 -> V_190 . V_617 [ V_19 ] ,
V_6 -> V_150 -> V_190 .
V_619 [ V_19 ] , 1 ) ;
if ( V_63 )
goto exit;
}
}
F_257 ( V_6 , V_6 -> V_150 -> V_494 . V_496 , 1 ) ;
}
V_63 =
F_252 ( V_6 ,
V_6 -> V_150 -> V_190 .
V_192 ? V_620 : 0 , 1 ) ;
if ( V_63 )
goto exit;
V_6 -> V_49 &= ~ V_265 ;
exit:
if ( ! V_288 )
F_83 ( V_6 ) ;
return V_63 ;
}
static void F_259 ( struct V_262 * V_263 )
{
struct V_5 * V_6 =
F_108 ( V_263 , struct V_5 , V_295 . V_263 ) ;
if ( ! ( V_6 -> V_49 & V_166 ) &&
V_6 -> V_49 & V_265 )
F_258 ( V_6 , 0 ) ;
}
static void F_260 ( struct V_1 * V_2 ,
struct V_621 * V_190 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_19 , V_622 = 0 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) )
goto V_624;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
if ( V_190 -> V_62 & ( 1 << V_19 ) ) {
V_6 -> V_150 -> V_190 . V_619 [ V_19 ] = V_190 -> V_619 [ V_19 ] ;
if ( V_190 -> V_619 [ V_19 ] == 0 )
V_6 -> V_150 -> V_190 . V_62 &= ~ ( 1 << V_19 ) ;
else
memcpy ( V_6 -> V_150 -> V_190 . V_617 [ V_19 ] , V_190 -> V_617 [ V_19 ] ,
V_190 -> V_619 [ V_19 ] ) ;
if ( V_190 -> V_43 == V_579 ) {
V_6 -> V_150 -> V_190 . V_62 |= ( 1 << V_19 ) ;
V_6 -> V_49 |= V_265 ;
} else
V_6 -> V_150 -> V_190 . V_62 &= ~ ( 1 << V_19 ) ;
}
}
if ( ( V_190 -> V_62 & V_625 ) &&
V_6 -> V_150 -> V_190 . V_626 != V_190 -> V_626 ) {
if ( V_190 -> V_626 <= 3 ) {
V_6 -> V_150 -> V_190 . V_626 = V_190 -> V_626 ;
V_6 -> V_150 -> V_190 . V_62 |= V_625 ;
} else
V_6 -> V_150 -> V_190 . V_62 &= ~ V_625 ;
V_6 -> V_49 |= V_265 ;
}
if ( ( V_190 -> V_62 & V_609 ) &&
( V_6 -> V_150 -> V_190 . V_570 != V_190 -> V_570 ) ) {
V_6 -> V_150 -> V_190 . V_570 = V_190 -> V_570 ;
V_6 -> V_150 -> V_190 . V_62 |= V_609 ;
V_6 -> V_49 |= V_265 ;
}
if ( V_190 -> V_62 & V_191 && V_6 -> V_150 -> V_190 . V_192 != V_190 -> V_192 ) {
V_6 -> V_150 -> V_190 . V_62 |= V_191 ;
V_6 -> V_150 -> V_190 . V_192 = V_190 -> V_192 ;
V_6 -> V_49 |= V_265 ;
V_622 = 1 ;
}
if ( V_190 -> V_62 & V_627 )
V_6 -> V_150 -> V_190 . V_628 = V_190 -> V_628 ;
if ( V_190 -> V_62 & V_614 && V_6 -> V_150 -> V_190 . V_43 != V_190 -> V_43 ) {
V_6 -> V_150 -> V_190 . V_43 = V_190 -> V_43 ;
V_6 -> V_150 -> V_190 . V_62 |= V_614 ;
V_6 -> V_49 |= V_265 ;
}
F_254 ( L_240 ,
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
F_258 ( V_6 , 0 ) ;
V_624:
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
#ifdef F_158
if ( V_6 -> V_150 -> V_198 == V_199 ) {
V_63 = F_234 ( V_6 , V_6 -> V_245 , V_288 ) ;
if ( V_63 )
return V_63 ;
F_31 ( L_45 ) ;
return 0 ;
}
#endif
V_63 = F_231 ( V_6 ) ;
if ( V_63 )
return - V_70 ;
V_63 = F_232 ( V_6 , V_288 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_233 ( V_6 , V_6 -> V_150 -> V_198 , V_288 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_150 -> V_198 == V_435 ) {
V_63 = F_234 ( V_6 , V_6 -> V_245 , V_288 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_235 ( V_6 , V_288 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_237 ( V_6 , V_6 -> V_545 , V_288 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_238 ( V_6 , V_548 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_241 ( V_6 , V_6 -> V_559 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_187 & V_629 )
V_274 = V_6 -> V_274 ;
else
V_274 = NULL ;
V_63 = F_244 ( V_6 , V_274 , V_288 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_187 & V_284 )
V_63 = F_113 ( V_6 , V_6 -> V_269 , V_6 -> V_268 ,
V_288 ) ;
else
V_63 = F_113 ( V_6 , NULL , 0 , V_288 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_258 ( V_6 , V_288 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_150 -> V_198 == V_435 ) {
V_63 =
F_249 ( V_6 ,
V_6 -> V_630 ,
V_288 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_248 ( V_6 , V_6 -> V_589 ) ;
if ( V_63 )
return V_63 ;
}
F_31 ( L_45 ) ;
return 0 ;
}
static int F_261 ( struct V_1 * V_2 , void * V_470 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_631 * V_8 = V_470 ;
int V_63 = 0 ;
if ( ! F_262 ( V_8 -> V_632 ) )
return - V_633 ;
F_84 ( & V_6 -> V_266 ) ;
V_6 -> V_187 |= V_517 ;
memcpy ( V_6 -> V_229 , V_8 -> V_632 , V_230 ) ;
V_63 = F_232 ( V_6 , 0 ) ;
if ( V_63 )
goto V_624;
V_6 -> V_47 = 0 ;
F_85 ( & V_6 -> V_266 ) ;
F_107 ( & V_6 -> V_52 . V_263 ) ;
return 0 ;
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_263 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_62 ;
F_31 ( L_241 ) ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( V_6 -> V_49 & V_166 ) {
F_264 ( V_2 ) ;
F_265 ( V_2 ) ;
}
F_52 ( & V_6 -> V_68 , V_62 ) ;
return 0 ;
}
static int F_266 ( struct V_1 * V_2 )
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
while ( ! F_44 ( & V_6 -> V_425 ) ) {
V_59 = V_6 -> V_425 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_428 ) ;
F_166 ( V_61 -> V_81 . V_411 . V_412 ) ;
V_61 -> V_81 . V_411 . V_412 = NULL ;
F_48 ( V_59 , & V_6 -> V_413 ) ;
F_49 ( & V_6 -> V_414 ) ;
}
F_52 ( & V_6 -> V_68 , V_62 ) ;
F_31 ( L_45 ) ;
return 0 ;
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_2 -> V_330 . V_634 ++ ;
#ifdef F_158
if ( V_6 -> V_150 -> V_198 == V_199 )
return;
#endif
F_31 ( L_242 ,
V_2 -> V_51 ) ;
F_35 ( V_6 ) ;
}
static int F_268 ( struct V_5 * V_6 , int V_147 )
{
V_6 -> V_150 -> V_635 = V_147 ;
return 0 ;
}
static int F_269 ( struct V_5 * V_6 , int V_147 )
{
struct V_636 * V_150 = V_6 -> V_150 ;
struct V_621 V_190 = {
. V_62 = V_609 ,
} ;
int V_267 = 0 ;
if ( V_147 & V_637 ) {
V_190 . V_570 = V_610 ;
V_150 -> V_638 = 0 ;
} else if ( V_147 & V_639 ) {
V_190 . V_570 = V_640 ;
V_150 -> V_638 = 1 ;
} else if ( V_147 & V_641 ) {
V_190 . V_570 = V_612 ;
V_150 -> V_638 = 1 ;
} else
return - V_31 ;
if ( V_150 -> V_642 )
V_150 -> V_642 ( V_150 -> V_2 , & V_190 ) ;
else
V_267 = - V_643 ;
return V_267 ;
}
static void V_567 ( struct V_5 * V_6 ,
char * V_644 , int V_645 )
{
struct V_567 V_646 ;
V_646 . V_647 = 0 ;
memcpy ( V_646 . V_648 , V_644 , V_645 ) ;
V_646 . V_649 = V_645 ;
F_268 ( V_6 , 1 ) ;
F_246 ( V_6 , & V_646 , 0 ) ;
}
static void F_270 ( struct V_1 * V_2 ,
struct V_650 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char V_651 [ 64 ] , V_652 [ 64 ] ;
F_271 ( V_81 -> V_653 , V_654 , sizeof( V_81 -> V_653 ) ) ;
F_271 ( V_81 -> V_121 , V_655 , sizeof( V_81 -> V_121 ) ) ;
F_272 ( V_6 , V_651 , sizeof( V_651 ) ) ;
F_273 ( V_6 , V_652 , sizeof( V_652 ) ) ;
snprintf ( V_81 -> V_656 , sizeof( V_81 -> V_656 ) , L_243 ,
V_651 , V_6 -> V_156 , V_652 ) ;
F_271 ( V_81 -> V_657 , F_274 ( V_6 -> V_261 ) ,
sizeof( V_81 -> V_657 ) ) ;
}
static T_1 F_275 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return ( V_6 -> V_49 & V_166 ) ? 1 : 0 ;
}
static void F_276 ( struct V_262 * V_263 )
{
struct V_5 * V_6 =
F_108 ( V_263 , struct V_5 , V_182 . V_263 ) ;
unsigned long V_62 ;
T_1 V_658 = 0xa5a5a5a5 ;
T_1 V_14 = sizeof( V_658 ) ;
int V_659 = 0 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( V_6 -> V_69 != 0 ) {
F_31 ( L_244 ,
V_6 -> V_33 -> V_51 ) ;
V_659 = 1 ;
} else if ( F_26 ( V_6 , V_660 , & V_658 , & V_14 ) ||
( V_658 == V_6 -> V_497 ) ) {
F_31 ( L_245 ,
V_6 -> V_33 -> V_51 ) ;
V_659 = 1 ;
}
if ( V_659 ) {
V_6 -> V_181 = 1 ;
V_6 -> V_491 ++ ;
F_35 ( V_6 ) ;
}
V_6 -> V_497 = V_658 ;
if ( ! V_6 -> V_181 )
F_39 ( & V_6 -> V_182 , V_53 / 2 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
}
static void F_277 ( struct V_262 * V_263 )
{
struct V_5 * V_6 =
F_108 ( V_263 , struct V_5 , V_216 . V_263 ) ;
unsigned long V_62 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( F_71 ( V_6 ) ) {
F_213 ( L_246 ) ;
if ( ! V_6 -> V_215 )
F_39 ( & V_6 -> V_216 ,
F_97 ( V_53 ) ) ;
goto V_661;
}
if ( ! ( V_6 -> V_49 & V_488 ) ) {
F_213 ( L_247
L_248 ) ;
F_35 ( V_6 ) ;
} else
F_213 ( L_249
L_250 ) ;
V_661:
F_52 ( & V_6 -> V_68 , V_62 ) ;
}
static struct V_1 * F_278 ( struct V_261 * V_261 ,
void T_12 * V_7 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_279 ( sizeof( struct V_5 ) , 0 ) ;
if ( ! V_2 )
return NULL ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_150 = F_280 ( V_2 ) ;
V_6 -> V_261 = V_261 ;
V_6 -> V_33 = V_2 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_150 -> V_662 = F_180 ;
V_6 -> V_150 -> V_642 = F_260 ;
V_6 -> V_150 -> V_663 = - 20 ;
V_6 -> V_150 -> V_664 = - 85 ;
V_2 -> V_665 = & V_666 ;
V_2 -> V_667 = & V_668 ;
V_2 -> V_669 = & V_670 ;
V_6 -> V_671 . V_672 = V_6 -> V_150 ;
V_2 -> V_671 = & V_6 -> V_671 ;
V_2 -> V_673 = 3 * V_53 ;
V_2 -> V_458 = 0 ;
V_6 -> V_549 = V_674 ;
#ifdef F_158
V_6 -> V_187 |= V_347 ;
#endif
V_6 -> V_150 -> V_635 = 0 ;
V_6 -> V_150 -> V_675 = 0 ;
V_6 -> V_150 -> V_676 = 0 ;
V_6 -> V_150 -> V_677 = 1 ;
switch ( V_678 ) {
case 1 :
V_6 -> V_150 -> V_198 = V_435 ;
break;
#ifdef F_158
case 2 :
V_6 -> V_150 -> V_198 = V_199 ;
break;
#endif
default:
case 0 :
V_6 -> V_150 -> V_198 = V_430 ;
break;
}
if ( V_679 == 1 )
V_6 -> V_49 |= V_206 ;
if ( V_245 != 0 &&
( ( V_245 >= V_523 ) && ( V_245 <= V_524 ) ) ) {
V_6 -> V_187 |= V_525 ;
V_6 -> V_245 = V_245 ;
}
if ( V_680 )
V_6 -> V_187 |= V_188 ;
V_6 -> V_630 = V_681 ;
V_6 -> V_562 = V_682 ;
V_6 -> V_564 = V_683 ;
V_6 -> V_559 = V_684 | V_557 ;
V_6 -> V_685 = V_686 | V_687 ;
V_6 -> V_589 = V_590 ;
V_6 -> V_545 = V_688 ;
strcpy ( V_6 -> V_689 , L_251 ) ;
F_281 ( & V_6 -> V_68 ) ;
F_282 ( & V_6 -> V_266 ) ;
F_282 ( & V_6 -> V_179 ) ;
F_283 ( & V_6 -> V_55 ) ;
F_37 ( V_2 ) ;
F_185 ( & V_6 -> V_75 ) ;
F_185 ( & V_6 -> V_91 ) ;
F_225 ( & V_6 -> V_90 ) ;
F_225 ( & V_6 -> V_92 ) ;
F_185 ( & V_6 -> V_413 ) ;
F_185 ( & V_6 -> V_425 ) ;
F_225 ( & V_6 -> V_414 ) ;
F_225 ( & V_6 -> V_428 ) ;
F_185 ( & V_6 -> V_397 ) ;
F_225 ( & V_6 -> V_405 ) ;
F_284 ( & V_6 -> V_52 , F_107 ) ;
F_284 ( & V_6 -> V_295 , F_259 ) ;
F_284 ( & V_6 -> V_286 , V_690 ) ;
F_284 ( & V_6 -> V_182 , F_276 ) ;
F_284 ( & V_6 -> V_216 , F_277 ) ;
F_285 ( & V_6 -> V_299 , F_120 ) ;
F_284 ( & V_6 -> V_298 , F_119 ) ;
F_286 ( & V_6 -> V_461 , ( void (*) ( unsigned long ) )
F_173 , ( unsigned long ) V_6 ) ;
V_6 -> V_215 = 1 ;
V_6 -> V_181 = 1 ;
return V_2 ;
}
static int F_287 ( struct V_261 * V_261 ,
const struct V_691 * V_692 )
{
void T_12 * V_7 ;
struct V_1 * V_2 = NULL ;
struct V_5 * V_6 = NULL ;
int V_63 = 0 ;
int V_693 = 0 ;
T_1 V_4 ;
F_31 ( L_42 ) ;
if ( ! ( F_288 ( V_261 , 0 ) & V_694 ) ) {
F_31 ( L_252 ) ;
V_63 = - V_695 ;
goto V_39;
}
V_7 = F_289 ( V_261 , 0 , 0 ) ;
if ( ! V_7 ) {
F_27 (KERN_WARNING DRV_NAME
L_253 ) ;
V_63 = - V_70 ;
goto V_123;
}
V_2 = F_278 ( V_261 , V_7 ) ;
if ( ! V_2 ) {
F_27 (KERN_WARNING DRV_NAME
L_254 ) ;
V_63 = - V_240 ;
goto V_123;
}
V_63 = F_290 ( V_261 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_255 ) ;
return V_63 ;
}
V_6 = F_2 ( V_2 ) ;
F_291 ( V_261 ) ;
F_292 ( V_261 , V_6 ) ;
V_63 = F_293 ( V_261 , F_294 ( 32 ) ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_256 ) ;
F_295 ( V_261 ) ;
return V_63 ;
}
V_63 = F_296 ( V_261 , V_654 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_257 ) ;
F_295 ( V_261 ) ;
return V_63 ;
}
F_188 ( V_261 , 0x40 , & V_4 ) ;
if ( ( V_4 & 0x0000ff00 ) != 0 )
F_297 ( V_261 , 0x40 , V_4 & 0xffff00ff ) ;
F_298 ( V_261 , V_696 ) ;
if ( ! F_25 ( V_2 ) ) {
F_27 (KERN_WARNING DRV_NAME
L_258 ) ;
V_63 = - V_695 ;
goto V_123;
}
F_299 ( V_2 , & V_261 -> V_2 ) ;
V_6 -> V_49 |= V_136 ;
F_68 ( V_6 ) ;
if ( F_251 ( V_6 ) ) {
F_27 (KERN_WARNING DRV_NAME
L_259 ) ;
V_63 = - V_240 ;
goto V_123;
}
F_77 ( V_6 ) ;
V_63 = F_300 ( V_261 -> V_458 ,
F_176 , V_697 , V_2 -> V_51 , V_6 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_260 , pci_dev->irq) ;
goto V_123;
}
V_2 -> V_458 = V_261 -> V_458 ;
F_31 ( L_261 ) ;
F_27 (KERN_INFO DRV_NAME
L_262 ) ;
V_63 = F_93 ( V_6 , 1 ) ;
if ( V_63 )
goto V_123;
V_63 = F_101 ( V_2 ) ;
if ( V_63 )
goto V_123;
V_693 = 1 ;
V_63 = F_301 ( V_2 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_263 ) ;
goto V_123;
}
V_693 = 2 ;
F_84 ( & V_6 -> V_266 ) ;
F_31 ( L_264 , V_2 -> V_51 , F_274 ( V_261 ) ) ;
V_63 = F_302 ( & V_261 -> V_2 . V_698 , & V_699 ) ;
if ( V_63 )
goto V_71;
if ( ! ( V_6 -> V_49 & V_488 ) ) {
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
V_6 -> V_49 |= V_623 ;
F_85 ( & V_6 -> V_266 ) ;
V_39:
return V_63 ;
V_71:
F_85 ( & V_6 -> V_266 ) ;
V_123:
if ( V_2 ) {
if ( V_693 >= 2 )
F_303 ( V_2 ) ;
if ( V_693 ) {
F_304 ( V_6 -> V_150 -> V_151 . V_152 ) ;
F_133 ( V_6 -> V_150 -> V_233 . V_237 ) ;
}
F_86 ( V_6 ) ;
F_68 ( V_6 ) ;
if ( V_2 -> V_458 )
F_305 ( V_2 -> V_458 , V_6 ) ;
F_220 ( V_6 ) ;
F_250 ( V_6 ) ;
F_306 ( & V_261 -> V_2 . V_698 ,
& V_699 ) ;
F_307 ( V_2 , 0 ) ;
F_292 ( V_261 , NULL ) ;
}
F_308 ( V_261 , V_7 ) ;
F_309 ( V_261 ) ;
F_295 ( V_261 ) ;
goto V_39;
}
static void T_13 F_310 ( struct V_261 * V_261 )
{
struct V_5 * V_6 = F_311 ( V_261 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
F_84 ( & V_6 -> V_266 ) ;
V_6 -> V_49 &= ~ V_623 ;
F_306 ( & V_261 -> V_2 . V_698 , & V_699 ) ;
#ifdef F_61
if ( V_120 . V_121 )
F_66 ( V_6 , & V_120 ) ;
#endif
F_99 ( V_6 ) ;
F_85 ( & V_6 -> V_266 ) ;
F_303 ( V_2 ) ;
F_220 ( V_6 ) ;
F_250 ( V_6 ) ;
F_132 ( V_6 ) ;
F_305 ( V_2 -> V_458 , V_6 ) ;
F_308 ( V_261 , V_6 -> V_7 ) ;
F_304 ( V_6 -> V_150 -> V_151 . V_152 ) ;
F_133 ( V_6 -> V_150 -> V_233 . V_237 ) ;
F_307 ( V_2 , 0 ) ;
F_309 ( V_261 ) ;
F_295 ( V_261 ) ;
F_31 ( L_45 ) ;
}
static int F_312 ( struct V_261 * V_261 , T_14 V_102 )
{
struct V_5 * V_6 = F_311 ( V_261 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
F_31 ( L_266 , V_2 -> V_51 ) ;
F_84 ( & V_6 -> V_266 ) ;
if ( V_6 -> V_49 & V_623 ) {
F_99 ( V_6 ) ;
}
F_313 ( V_2 ) ;
F_314 ( V_261 ) ;
F_295 ( V_261 ) ;
F_298 ( V_261 , V_700 ) ;
V_6 -> V_701 = F_36 () ;
F_85 ( & V_6 -> V_266 ) ;
return 0 ;
}
static int F_315 ( struct V_261 * V_261 )
{
struct V_5 * V_6 = F_311 ( V_261 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
int V_63 ;
T_1 V_4 ;
if ( V_702 )
return 0 ;
F_84 ( & V_6 -> V_266 ) ;
F_31 ( L_267 , V_2 -> V_51 ) ;
F_298 ( V_261 , V_696 ) ;
V_63 = F_290 ( V_261 ) ;
if ( V_63 ) {
F_27 ( V_703 L_268 ,
V_2 -> V_51 ) ;
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
F_316 ( V_261 ) ;
F_188 ( V_261 , 0x40 , & V_4 ) ;
if ( ( V_4 & 0x0000ff00 ) != 0 )
F_297 ( V_261 , 0x40 , V_4 & 0xffff00ff ) ;
F_317 ( V_2 ) ;
V_6 -> V_205 = F_36 () - V_6 -> V_701 ;
if ( ! ( V_6 -> V_49 & V_206 ) )
F_93 ( V_6 , 0 ) ;
F_85 ( & V_6 -> V_266 ) ;
return 0 ;
}
static void F_318 ( struct V_261 * V_261 )
{
struct V_5 * V_6 = F_311 ( V_261 ) ;
F_99 ( V_6 ) ;
F_295 ( V_261 ) ;
}
static int T_15 F_319 ( void )
{
int V_267 ;
F_27 (KERN_INFO DRV_NAME L_269 , DRV_DESCRIPTION, DRV_VERSION) ;
F_27 (KERN_INFO DRV_NAME L_270 , DRV_COPYRIGHT) ;
F_320 ( & V_207 , V_704 ,
V_223 ) ;
V_267 = F_321 ( & V_705 ) ;
if ( V_267 )
goto V_39;
#ifdef F_128
V_44 = V_706 ;
V_267 = F_322 ( & V_705 . V_653 ,
& V_707 ) ;
#endif
V_39:
return V_267 ;
}
static void T_16 F_323 ( void )
{
#ifdef F_128
F_324 ( & V_705 . V_653 ,
& V_707 ) ;
#endif
F_325 ( & V_705 ) ;
F_326 ( & V_207 ) ;
}
static int F_327 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_49 & V_166 ) )
strcpy ( V_218 -> V_51 , L_271 ) ;
else
snprintf ( V_218 -> V_51 , V_710 , L_272 ) ;
F_328 ( L_273 , V_218 -> V_51 ) ;
return 0 ;
}
static int F_329 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_711 * V_712 = & V_218 -> V_243 ;
int V_63 = 0 ;
if ( V_6 -> V_150 -> V_198 == V_430 )
return - V_643 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) ) {
V_63 = - V_70 ;
goto V_624;
}
if ( V_712 -> V_395 == 1 ) {
if ( ( V_712 -> V_713 >= ( int ) 2.412e8 && V_712 -> V_713 <= ( int ) 2.487e8 ) ) {
int V_714 = V_712 -> V_713 / 100000 ;
int V_42 = 0 ;
while ( ( V_42 < V_524 ) &&
( V_714 != V_715 [ V_42 ] ) )
V_42 ++ ;
V_712 -> V_395 = 0 ;
V_712 -> V_713 = V_42 + 1 ;
}
}
if ( V_712 -> V_395 > 0 || V_712 -> V_713 > 1000 ) {
V_63 = - V_643 ;
goto V_624;
} else {
F_328 ( L_274 , V_712 -> V_713 ) ;
V_63 = F_234 ( V_6 , V_712 -> V_713 , 0 ) ;
}
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_330 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_243 . V_395 = 0 ;
if ( V_6 -> V_187 & V_525 ||
V_6 -> V_49 & V_166 )
V_218 -> V_243 . V_713 = V_6 -> V_245 ;
else
V_218 -> V_243 . V_713 = 0 ;
F_328 ( L_275 , V_6 -> V_245 ) ;
return 0 ;
}
static int F_331 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
F_328 ( L_276 , V_218 -> V_316 ) ;
if ( V_218 -> V_316 == V_6 -> V_150 -> V_198 )
return 0 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) ) {
V_63 = - V_70 ;
goto V_624;
}
switch ( V_218 -> V_316 ) {
#ifdef F_158
case V_199 :
V_63 = F_199 ( V_6 , V_199 ) ;
break;
#endif
case V_435 :
V_63 = F_199 ( V_6 , V_435 ) ;
break;
case V_430 :
case V_716 :
default:
V_63 = F_199 ( V_6 , V_430 ) ;
break;
}
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_332 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_316 = V_6 -> V_150 -> V_198 ;
F_328 ( L_277 , V_218 -> V_316 ) ;
return 0 ;
}
static int F_333 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_717 * V_718 = (struct V_717 * ) V_709 ;
T_2 V_4 ;
int V_19 , V_43 ;
V_218 -> V_37 . V_287 = sizeof( * V_718 ) ;
memset ( V_718 , 0 , sizeof( * V_718 ) ) ;
V_718 -> V_719 = 5 * 1000 * 1000 ;
V_718 -> V_720 . V_721 = 100 ;
V_718 -> V_720 . V_43 = 0 ;
V_718 -> V_720 . V_722 = 0 ;
V_718 -> V_720 . V_723 = 7 ;
V_718 -> V_724 . V_721 = 70 ;
V_718 -> V_724 . V_43 = 20 + V_356 ;
V_718 -> V_724 . V_722 = 0 ;
V_718 -> V_724 . V_723 = 7 ;
V_718 -> V_725 = V_256 ;
for ( V_19 = 0 ; V_19 < V_256 && V_19 < V_726 ; V_19 ++ ) {
V_718 -> V_727 [ V_19 ] = V_254 [ V_19 ] . V_727 * 100 * 1000 ;
}
V_718 -> V_728 = V_729 ;
V_718 -> V_730 = V_558 ;
V_718 -> V_731 = V_732 ;
V_718 -> V_733 = V_734 ;
V_718 -> V_735 = V_736 [ 0 ] ;
V_718 -> V_737 = V_736 [ V_738 - 1 ] ;
V_718 -> V_739 = V_740 [ V_738 - 1 ] ;
V_718 -> V_741 = V_740 [ 0 ] ;
V_718 -> V_742 = V_743 ;
V_718 -> V_744 = V_745 ;
V_718 -> V_746 = V_745 | V_743 ;
V_718 -> V_747 [ 0 ] = 5 ;
V_718 -> V_747 [ 1 ] = 13 ;
V_718 -> V_748 = 2 ;
V_718 -> V_749 = V_750 ;
if ( V_6 -> V_150 -> V_198 == V_435 ) {
V_718 -> V_751 = V_752 ;
V_718 -> V_753 = V_754 ;
for ( V_19 = 0 , V_43 = ( V_592 * 16 ) ;
V_19 < V_754 ;
V_19 ++ , V_43 -=
( ( V_592 -
V_591 ) * 16 ) / ( V_754 - 1 ) )
V_718 -> V_755 [ V_19 ] = V_43 / 16 ;
} else {
V_718 -> V_751 = 0 ;
V_718 -> V_753 = 0 ;
}
V_718 -> V_756 = V_757 ;
V_718 -> V_758 = 18 ;
V_718 -> V_759 = V_760 ;
V_4 = 0 ;
for ( V_19 = 0 ; V_19 < V_760 ; V_19 ++ ) {
V_718 -> V_243 [ V_4 ] . V_19 = V_19 + 1 ;
V_718 -> V_243 [ V_4 ] . V_713 = V_715 [ V_19 ] * 100000 ;
V_718 -> V_243 [ V_4 ] . V_395 = 1 ;
V_4 ++ ;
if ( V_4 == V_761 )
break;
}
V_718 -> V_762 = V_4 ;
V_718 -> V_763 [ 0 ] = ( V_764 |
F_334 ( V_224 ) ) ;
V_718 -> V_763 [ 1 ] = V_765 ;
V_718 -> V_766 = V_767 | V_768 |
V_769 | V_770 ;
F_328 ( L_278 ) ;
return 0 ;
}
static int F_335 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
if ( V_218 -> V_219 . V_220 != V_221 )
return - V_31 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) ) {
V_63 = - V_70 ;
goto V_624;
}
if ( F_336 ( V_218 -> V_219 . V_632 ) ||
F_337 ( V_218 -> V_219 . V_632 ) ) {
F_328 ( L_279 ) ;
V_6 -> V_187 &= ~ V_629 ;
V_63 = F_244 ( V_6 , NULL , 0 ) ;
goto V_624;
}
V_6 -> V_187 |= V_629 ;
memcpy ( V_6 -> V_771 , V_218 -> V_219 . V_632 , V_230 ) ;
V_63 = F_244 ( V_6 , V_218 -> V_219 . V_632 , 0 ) ;
F_328 ( L_280 , V_218 -> V_219 . V_632 ) ;
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_338 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_629 || V_6 -> V_49 & V_166 ) {
V_218 -> V_219 . V_220 = V_221 ;
memcpy ( V_218 -> V_219 . V_632 , V_6 -> V_274 , V_230 ) ;
} else
memset ( V_218 -> V_219 . V_632 , 0 , V_230 ) ;
F_328 ( L_281 , V_218 -> V_219 . V_632 ) ;
return 0 ;
}
static int F_339 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char * V_269 = L_50 ;
int V_287 = 0 ;
int V_63 = 0 ;
F_111 ( V_275 ) ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) ) {
V_63 = - V_70 ;
goto V_624;
}
if ( V_218 -> V_269 . V_62 && V_218 -> V_269 . V_287 ) {
V_287 = V_218 -> V_269 . V_287 ;
V_269 = V_709 ;
}
if ( V_287 == 0 ) {
F_328 ( L_282 ) ;
V_6 -> V_187 &= ~ V_284 ;
V_63 = F_113 ( V_6 , NULL , 0 , 0 ) ;
goto V_624;
}
V_287 = F_34 ( V_287 , V_270 ) ;
V_6 -> V_187 |= V_284 ;
if ( V_6 -> V_268 == V_287 && ! memcmp ( V_6 -> V_269 , V_709 , V_287 ) ) {
F_328 ( L_283 ) ;
V_63 = 0 ;
goto V_624;
}
F_328 ( L_284 ,
F_112 ( V_275 , V_269 , V_287 ) , V_287 ) ;
V_6 -> V_268 = V_287 ;
memcpy ( V_6 -> V_269 , V_269 , V_6 -> V_268 ) ;
V_63 = F_113 ( V_6 , V_269 , V_287 , 0 ) ;
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_340 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_111 ( V_275 ) ;
if ( V_6 -> V_187 & V_284 || V_6 -> V_49 & V_166 ) {
F_328 ( L_285 ,
F_112 ( V_275 , V_6 -> V_269 , V_6 -> V_268 ) ) ;
memcpy ( V_709 , V_6 -> V_269 , V_6 -> V_268 ) ;
V_218 -> V_269 . V_287 = V_6 -> V_268 ;
V_218 -> V_269 . V_62 = 1 ;
} else {
F_328 ( L_286 ) ;
V_218 -> V_269 . V_287 = 0 ;
V_218 -> V_269 . V_62 = 0 ;
}
return 0 ;
}
static int F_341 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_218 -> V_37 . V_287 > V_270 )
return - V_772 ;
V_218 -> V_37 . V_287 = F_34 ( ( T_4 ) V_218 -> V_37 . V_287 , sizeof( V_6 -> V_689 ) ) ;
memset ( V_6 -> V_689 , 0 , sizeof( V_6 -> V_689 ) ) ;
memcpy ( V_6 -> V_689 , V_709 , V_218 -> V_37 . V_287 ) ;
F_328 ( L_287 , V_6 -> V_689 ) ;
return 0 ;
}
static int F_342 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_37 . V_287 = strlen ( V_6 -> V_689 ) ;
memcpy ( V_709 , V_6 -> V_689 , V_218 -> V_37 . V_287 ) ;
V_218 -> V_37 . V_62 = 1 ;
F_328 ( L_288 , V_709 ) ;
return 0 ;
}
static int F_343 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_773 = V_218 -> V_727 . V_147 ;
T_1 V_540 ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) ) {
V_63 = - V_70 ;
goto V_624;
}
V_540 = 0 ;
if ( V_773 == 1000000 ||
( ! V_218 -> V_727 . V_774 && V_773 > 1000000 ) )
V_540 |= V_280 ;
if ( V_773 == 2000000 ||
( ! V_218 -> V_727 . V_774 && V_773 > 2000000 ) )
V_540 |= V_281 ;
if ( V_773 == 5500000 ||
( ! V_218 -> V_727 . V_774 && V_773 > 5500000 ) )
V_540 |= V_282 ;
if ( V_773 == 11000000 ||
( ! V_218 -> V_727 . V_774 && V_773 > 11000000 ) )
V_540 |= V_283 ;
if ( V_540 == 0 )
V_540 = V_688 ;
V_63 = F_237 ( V_6 , V_540 , 0 ) ;
F_328 ( L_289 , V_540 ) ;
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_344 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_4 ;
unsigned int V_14 = sizeof( V_4 ) ;
int V_63 = 0 ;
if ( ! ( V_6 -> V_49 & V_106 ) ||
V_6 -> V_49 & V_488 ||
! ( V_6 -> V_49 & V_166 ) ) {
V_218 -> V_727 . V_147 = 0 ;
return 0 ;
}
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) ) {
V_63 = - V_70 ;
goto V_624;
}
V_63 = F_26 ( V_6 , V_277 , & V_4 , & V_14 ) ;
if ( V_63 ) {
F_328 ( L_290 ) ;
goto V_624;
}
switch ( V_4 & V_542 ) {
case V_280 :
V_218 -> V_727 . V_147 = 1000000 ;
break;
case V_281 :
V_218 -> V_727 . V_147 = 2000000 ;
break;
case V_282 :
V_218 -> V_727 . V_147 = 5500000 ;
break;
case V_283 :
V_218 -> V_727 . V_147 = 11000000 ;
break;
default:
V_218 -> V_727 . V_147 = 0 ;
}
F_328 ( L_291 , V_218 -> V_727 . V_147 ) ;
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_345 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_147 , V_63 ;
if ( V_218 -> V_775 . V_774 == 0 )
return - V_31 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) ) {
V_63 = - V_70 ;
goto V_624;
}
if ( V_218 -> V_775 . V_776 )
V_147 = V_6 -> V_559 | V_557 ;
else {
if ( V_218 -> V_775 . V_147 < 1 || V_218 -> V_775 . V_147 > 2304 ) {
V_63 = - V_31 ;
goto V_624;
}
V_147 = V_218 -> V_775 . V_147 ;
}
V_63 = F_241 ( V_6 , V_147 ) ;
F_328 ( L_292 , V_147 ) ;
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_346 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_775 . V_147 = V_6 -> V_559 & ~ V_557 ;
V_218 -> V_775 . V_774 = 1 ;
V_218 -> V_775 . V_776 = ( V_6 -> V_559 & V_557 ) ? 1 : 0 ;
F_328 ( L_293 , V_218 -> V_775 . V_147 ) ;
return 0 ;
}
static int F_347 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 , V_147 ;
if ( F_212 ( V_6 , V_218 -> V_755 . V_776 ) )
return - V_777 ;
if ( V_6 -> V_150 -> V_198 != V_435 )
return 0 ;
if ( ( V_218 -> V_755 . V_62 & V_778 ) != V_752 )
return - V_31 ;
if ( V_218 -> V_755 . V_774 == 0 )
V_147 = V_590 ;
else {
if ( V_218 -> V_755 . V_147 < V_591 ||
V_218 -> V_755 . V_147 > V_592 )
return - V_31 ;
V_147 = V_218 -> V_755 . V_147 ;
}
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) ) {
V_63 = - V_70 ;
goto V_624;
}
V_63 = F_248 ( V_6 , V_147 ) ;
F_328 ( L_294 , V_147 ) ;
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_348 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_755 . V_776 = ( V_6 -> V_49 & V_488 ) ? 1 : 0 ;
if ( V_6 -> V_589 == V_590 ) {
V_218 -> V_755 . V_774 = 0 ;
V_218 -> V_755 . V_147 = V_592 ;
} else {
V_218 -> V_755 . V_774 = 1 ;
V_218 -> V_755 . V_147 = V_6 -> V_589 ;
}
V_218 -> V_755 . V_62 = V_752 ;
F_328 ( L_295 , V_218 -> V_755 . V_147 ) ;
return 0 ;
}
static int F_349 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_218 -> V_779 . V_774 )
return - V_31 ;
if ( V_218 -> V_779 . V_776 ) {
V_6 -> V_685 |= V_687 ;
V_6 -> V_150 -> V_780 = V_686 ;
} else {
if ( V_218 -> V_779 . V_147 < V_732 ||
V_218 -> V_779 . V_147 > V_734 )
return - V_31 ;
V_6 -> V_150 -> V_780 = V_218 -> V_779 . V_147 & ~ 0x1 ;
V_6 -> V_685 = V_6 -> V_150 -> V_780 ;
}
F_328 ( L_296 , V_6 -> V_150 -> V_780 ) ;
return 0 ;
}
static int F_350 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_779 . V_147 = V_6 -> V_685 & ~ V_687 ;
V_218 -> V_779 . V_774 = 0 ;
V_218 -> V_779 . V_776 = ( V_6 -> V_685 & V_687 ) ? 1 : 0 ;
F_328 ( L_297 , V_218 -> V_779 . V_147 ) ;
return 0 ;
}
static int F_351 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
if ( V_218 -> V_560 . V_62 & V_781 || V_218 -> V_560 . V_776 )
return - V_31 ;
if ( ! ( V_218 -> V_560 . V_62 & V_782 ) )
return 0 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) ) {
V_63 = - V_70 ;
goto V_624;
}
if ( V_218 -> V_560 . V_62 & V_783 ) {
V_63 = F_242 ( V_6 , V_218 -> V_560 . V_147 ) ;
F_328 ( L_298 ,
V_218 -> V_560 . V_147 ) ;
goto V_624;
}
if ( V_218 -> V_560 . V_62 & V_784 ) {
V_63 = F_243 ( V_6 , V_218 -> V_560 . V_147 ) ;
F_328 ( L_299 ,
V_218 -> V_560 . V_147 ) ;
goto V_624;
}
V_63 = F_242 ( V_6 , V_218 -> V_560 . V_147 ) ;
if ( ! V_63 )
V_63 = F_243 ( V_6 , V_218 -> V_560 . V_147 ) ;
F_328 ( L_300 , V_218 -> V_560 . V_147 ) ;
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_352 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_560 . V_776 = 0 ;
if ( ( V_218 -> V_560 . V_62 & V_785 ) == V_781 )
return - V_31 ;
if ( V_218 -> V_560 . V_62 & V_784 ) {
V_218 -> V_560 . V_62 = V_782 | V_784 ;
V_218 -> V_560 . V_147 = V_6 -> V_564 ;
} else {
V_218 -> V_560 . V_62 =
( V_6 -> V_562 !=
V_6 -> V_564 ) ?
V_782 | V_783 : V_782 ;
V_218 -> V_560 . V_147 = V_6 -> V_562 ;
}
F_328 ( L_301 , V_218 -> V_560 . V_147 ) ;
return 0 ;
}
static int F_353 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) ) {
V_63 = - V_70 ;
goto V_624;
}
F_328 ( L_302 ) ;
V_6 -> V_301 = 1 ;
if ( F_90 ( V_6 ) || F_92 ( V_6 ) ) {
F_328 ( L_303 ) ;
}
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_354 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_355 ( V_6 -> V_150 , V_81 , V_218 , V_709 ) ;
}
static int F_356 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_597 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_357 ( V_6 -> V_150 , V_81 , V_218 , V_597 ) ;
}
static int F_358 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_597 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_359 ( V_6 -> V_150 , V_81 , V_218 , V_597 ) ;
}
static int F_360 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) ) {
V_63 = - V_70 ;
goto V_624;
}
if ( V_218 -> V_786 . V_776 ) {
V_6 -> V_549 = F_239 ( V_6 -> V_549 ) ;
V_63 = F_238 ( V_6 , V_548 ) ;
F_328 ( L_304 ) ;
goto V_624;
}
switch ( V_218 -> V_786 . V_62 & V_787 ) {
case V_788 :
case V_787 :
case V_789 :
break;
default:
F_328 ( L_305 ,
V_218 -> V_786 . V_62 ) ;
V_63 = - V_643 ;
goto V_624;
}
V_6 -> V_549 = V_550 | V_6 -> V_549 ;
V_63 = F_238 ( V_6 , F_239 ( V_6 -> V_549 ) ) ;
F_328 ( L_306 , V_6 -> V_549 ) ;
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_361 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_549 & V_550 ) )
V_218 -> V_786 . V_776 = 1 ;
else {
V_218 -> V_786 . V_776 = 0 ;
V_218 -> V_786 . V_62 = 0 ;
}
F_328 ( L_307 , V_6 -> V_549 ) ;
return 0 ;
}
static int F_362 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_636 * V_150 = V_6 -> V_150 ;
T_3 * V_15 ;
if ( ! V_150 -> V_635 )
return - V_643 ;
if ( V_218 -> V_37 . V_287 > V_790 ||
( V_218 -> V_37 . V_287 && V_709 == NULL ) )
return - V_31 ;
if ( V_218 -> V_37 . V_287 ) {
V_15 = F_363 ( V_709 , V_218 -> V_37 . V_287 , V_239 ) ;
if ( V_15 == NULL )
return - V_240 ;
F_133 ( V_150 -> V_644 ) ;
V_150 -> V_644 = V_15 ;
V_150 -> V_645 = V_218 -> V_37 . V_287 ;
} else {
F_133 ( V_150 -> V_644 ) ;
V_150 -> V_644 = NULL ;
V_150 -> V_645 = 0 ;
}
V_567 ( V_6 , V_150 -> V_644 , V_150 -> V_645 ) ;
return 0 ;
}
static int F_364 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_636 * V_150 = V_6 -> V_150 ;
if ( V_150 -> V_645 == 0 || V_150 -> V_644 == NULL ) {
V_218 -> V_37 . V_287 = 0 ;
return 0 ;
}
if ( V_218 -> V_37 . V_287 < V_150 -> V_645 )
return - V_772 ;
V_218 -> V_37 . V_287 = V_150 -> V_645 ;
memcpy ( V_709 , V_150 -> V_644 , V_150 -> V_645 ) ;
return 0 ;
}
static int F_365 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_636 * V_150 = V_6 -> V_150 ;
struct V_791 * V_792 = & V_218 -> V_792 ;
struct V_793 * V_495 ;
unsigned long V_62 ;
int V_267 = 0 ;
switch ( V_792 -> V_62 & V_794 ) {
case V_795 :
case V_796 :
case V_797 :
case V_798 :
break;
case V_799 :
V_495 = V_6 -> V_150 -> V_494 . V_495 [ V_6 -> V_150 -> V_494 . V_496 ] ;
if ( ! V_495 || ! V_495 -> V_800 -> V_801 || ! V_495 -> V_800 -> V_802 )
break;
V_62 = V_495 -> V_800 -> V_802 ( V_495 -> V_6 ) ;
if ( V_792 -> V_147 )
V_62 |= V_803 ;
else
V_62 &= ~ V_803 ;
V_495 -> V_800 -> V_801 ( V_62 , V_495 -> V_6 ) ;
break;
case V_804 : {
struct V_621 V_190 = {
. V_62 = V_191 ,
. V_192 = V_792 -> V_147 ,
} ;
V_6 -> V_150 -> V_675 = V_792 -> V_147 ;
if ( ! V_792 -> V_147 ) {
V_190 . V_62 |= V_614 ;
V_190 . V_43 = V_576 ;
} else {
V_190 . V_62 |= V_614 ;
V_190 . V_43 = V_579 ;
}
if ( V_6 -> V_150 -> V_642 )
V_6 -> V_150 -> V_642 ( V_6 -> V_150 -> V_2 , & V_190 ) ;
break;
}
case V_805 :
V_267 = F_269 ( V_6 , V_792 -> V_147 ) ;
break;
case V_806 :
V_267 = F_268 ( V_6 , V_792 -> V_147 ) ;
break;
case V_807 :
V_150 -> V_677 = V_792 -> V_147 ;
break;
case V_808 :
V_150 -> V_676 = V_792 -> V_147 ;
break;
default:
return - V_643 ;
}
return V_267 ;
}
static int F_366 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_636 * V_150 = V_6 -> V_150 ;
struct V_793 * V_495 ;
struct V_791 * V_792 = & V_218 -> V_792 ;
int V_267 = 0 ;
switch ( V_792 -> V_62 & V_794 ) {
case V_795 :
case V_796 :
case V_797 :
case V_798 :
V_267 = - V_643 ;
break;
case V_799 :
V_495 = V_6 -> V_150 -> V_494 . V_495 [ V_6 -> V_150 -> V_494 . V_496 ] ;
if ( ! V_495 || ! V_495 -> V_800 -> V_802 ) {
F_156 ( L_308
L_309 ) ;
break;
}
V_792 -> V_147 = ( V_495 -> V_800 -> V_802 ( V_495 -> V_6 ) &
V_803 ) ? 1 : 0 ;
break;
case V_804 :
V_792 -> V_147 = V_150 -> V_675 ;
break;
case V_805 :
V_792 -> V_147 = V_6 -> V_150 -> V_190 . V_570 ;
break;
case V_806 :
V_792 -> V_147 = V_150 -> V_635 ;
break;
case V_807 :
V_792 -> V_147 = V_150 -> V_677 ;
break;
case V_809 :
case V_808 :
V_792 -> V_147 = V_150 -> V_676 ;
break;
default:
return - V_643 ;
}
return 0 ;
}
static int F_367 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_368 ( V_6 -> V_150 , V_81 , V_218 , V_709 ) ;
}
static int F_369 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_370 ( V_6 -> V_150 , V_81 , V_218 , V_709 ) ;
}
static int F_371 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_810 * V_811 = (struct V_810 * ) V_709 ;
T_17 V_812 ;
V_812 = F_154 ( V_811 -> V_813 ) ;
switch ( V_811 -> V_57 ) {
case V_814 :
break;
case V_815 :
F_245 ( V_6 ) ;
break;
default:
return - V_643 ;
}
return 0 ;
}
static int F_372 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int * V_816 = ( int * ) V_709 ;
int V_817 = ( V_816 [ 0 ] > 0 ) ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) ) {
V_63 = - V_70 ;
goto V_624;
}
if ( V_817 ) {
if ( V_6 -> V_150 -> V_198 == V_199 ) {
V_63 = F_234 ( V_6 , V_816 [ 1 ] , 0 ) ;
goto V_624;
}
V_6 -> V_245 = V_816 [ 1 ] ;
V_63 = F_199 ( V_6 , V_199 ) ;
} else {
if ( V_6 -> V_150 -> V_198 == V_199 )
V_63 = F_199 ( V_6 , V_6 -> V_492 ) ;
}
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_373 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_49 & V_623 )
F_35 ( V_6 ) ;
return 0 ;
}
static int F_374 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 , V_316 = * ( int * ) V_709 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) ) {
V_63 = - V_70 ;
goto V_624;
}
if ( ( V_316 < 0 ) || ( V_316 > V_738 ) )
V_316 = V_674 ;
if ( F_239 ( V_6 -> V_549 ) != V_316 )
V_63 = F_238 ( V_6 , V_316 ) ;
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_375 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_43 = F_239 ( V_6 -> V_549 ) ;
T_18 V_818 , V_819 ;
if ( ! ( V_6 -> V_549 & V_550 ) ) {
snprintf ( V_709 , V_820 ,
L_310 , V_43 ) ;
} else {
switch ( V_43 ) {
case V_548 :
snprintf ( V_709 , V_820 ,
L_311 , V_43 ) ;
break;
case V_674 :
snprintf ( V_709 , V_820 ,
L_312 , V_43 ) ;
break;
default:
V_818 = V_740 [ V_43 - 1 ] / 1000 ;
V_819 = V_736 [ V_43 - 1 ] / 1000 ;
snprintf ( V_709 , V_820 ,
L_313
L_314 ,
V_43 , V_818 , V_819 ) ;
}
}
V_218 -> V_37 . V_287 = strlen ( V_709 ) + 1 ;
return 0 ;
}
static int F_376 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 , V_316 = * ( int * ) V_709 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) ) {
V_63 = - V_70 ;
goto V_624;
}
if ( V_316 == 1 )
V_6 -> V_187 |= V_532 ;
else if ( V_316 == 0 )
V_6 -> V_187 &= ~ V_532 ;
else {
V_63 = - V_31 ;
goto V_624;
}
V_63 = F_235 ( V_6 , 0 ) ;
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_377 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_532 )
snprintf ( V_218 -> V_51 , V_710 , L_315 ) ;
else
snprintf ( V_218 -> V_51 , V_710 , L_316 ) ;
return 0 ;
}
static int F_378 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 , V_316 = * ( int * ) V_709 ;
F_84 ( & V_6 -> V_266 ) ;
if ( ! ( V_6 -> V_49 & V_623 ) ) {
V_63 = - V_70 ;
goto V_624;
}
if ( V_316 == 1 )
V_6 -> V_187 |= V_347 ;
else if ( V_316 == 0 )
V_6 -> V_187 &= ~ V_347 ;
else {
V_63 = - V_31 ;
goto V_624;
}
V_63 = 0 ;
V_624:
F_85 ( & V_6 -> V_266 ) ;
return V_63 ;
}
static int F_379 ( struct V_1 * V_2 ,
struct V_708 * V_81 ,
union V_217 * V_218 , char * V_709 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_347 )
snprintf ( V_218 -> V_51 , V_710 , L_317 ) ;
else
snprintf ( V_218 -> V_51 , V_710 , L_318 ) ;
return 0 ;
}
static struct V_821 * F_380 ( struct V_1 * V_2 )
{
enum {
V_822 = 30 ,
V_823 = 60 ,
V_824 = 80 ,
V_825 = 90 ,
V_826 = 95 ,
V_827 = 100
};
int V_828 ;
int V_829 ;
int V_830 ;
int V_831 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_821 * V_305 ;
T_1 V_355 , V_832 , V_833 , V_834 ;
T_1 V_204 = sizeof( T_1 ) ;
if ( ! V_6 )
return (struct V_821 * ) NULL ;
V_305 = & V_6 -> V_305 ;
if ( ! ( V_6 -> V_49 & V_166 ) ) {
V_305 -> V_835 . V_836 = 0 ;
V_305 -> V_335 . V_837 = 0 ;
V_305 -> V_721 . V_721 = 0 ;
V_305 -> V_721 . V_43 = 0 ;
V_305 -> V_721 . V_722 = 0 ;
V_305 -> V_721 . V_723 = 7 ;
V_305 -> V_721 . V_723 |= V_838 |
V_839 | V_840 ;
return V_305 ;
}
if ( F_26 ( V_6 , V_841 ,
& V_833 , & V_204 ) )
goto V_842;
if ( ! ( V_6 -> V_49 & V_166 ) ) {
V_305 -> V_721 . V_721 = 0 ;
V_305 -> V_721 . V_43 = 0 ;
} else {
if ( F_26 ( V_6 , V_843 ,
& V_355 , & V_204 ) )
goto V_842;
V_305 -> V_721 . V_43 = V_355 + V_356 ;
if ( V_355 < 10 )
V_828 = V_355 * V_822 / 10 ;
else if ( V_355 < 15 )
V_828 = ( V_355 - 10 ) * ( V_823 - V_822 ) / 5 + V_822 ;
else if ( V_355 < 20 )
V_828 = ( V_355 - 15 ) * ( V_824 - V_823 ) / 5 + V_823 ;
else if ( V_355 < 30 )
V_828 = ( V_355 - 20 ) * ( V_825 - V_824 ) /
10 + V_824 ;
else
V_828 = ( V_355 - 30 ) * ( V_827 - V_825 ) /
10 + V_825 ;
if ( F_26 ( V_6 , V_844 ,
& V_832 , & V_204 ) )
goto V_842;
if ( V_832 > 75 )
V_829 = ( 90 - V_832 ) * V_822 / 15 ;
else if ( V_832 > 70 )
V_829 = ( 75 - V_832 ) * ( V_823 - V_822 ) / 5 + V_822 ;
else if ( V_832 > 65 )
V_829 = ( 70 - V_832 ) * ( V_824 - V_823 ) / 5 + V_823 ;
else if ( V_832 > 50 )
V_829 = ( 65 - V_832 ) * ( V_825 - V_824 ) /
15 + V_824 ;
else
V_829 = ( 50 - V_832 ) *
( V_827 - V_825 ) / 50 + V_825 ;
if ( V_833 > 50 )
V_830 = ( 60 - V_833 ) * V_822 / 10 ;
else if ( V_833 > 40 )
V_830 = ( 50 - V_833 ) * ( V_823 - V_822 ) /
10 + V_822 ;
else if ( V_833 > 32 )
V_830 = ( 40 - V_833 ) * ( V_824 - V_823 ) /
18 + V_823 ;
else if ( V_833 > 20 )
V_830 = ( 32 - V_833 ) *
( V_825 - V_824 ) / 20 + V_824 ;
else
V_830 = ( 20 - V_833 ) *
( V_827 - V_825 ) / 20 + V_825 ;
V_831 = F_34 ( V_829 , V_828 ) ;
V_831 = F_34 ( V_830 , V_831 ) ;
#ifdef F_128
if ( V_830 == V_831 )
F_328 ( L_319 ) ;
else if ( V_829 == V_831 )
F_328 ( L_320 ) ;
else if ( V_831 != 100 )
F_328 ( L_321 ) ;
else
F_328 ( L_322 ) ;
#endif
V_305 -> V_721 . V_721 = V_831 ;
V_305 -> V_721 . V_43 = V_355 + V_356 ;
}
V_305 -> V_721 . V_722 = 0 ;
V_305 -> V_721 . V_723 = 7 ;
V_305 -> V_721 . V_723 |= V_838 ;
V_305 -> V_835 . V_836 = V_833 ;
if ( F_26 ( V_6 , V_845 ,
& V_834 , & V_204 ) )
goto V_842;
V_305 -> V_335 . V_837 = V_834 ;
return V_305 ;
V_842:
F_328 ( L_290 ) ;
return (struct V_821 * ) NULL ;
}
static void V_690 ( struct V_262 * V_263 )
{
struct V_5 * V_6 =
F_108 ( V_263 , struct V_5 , V_286 . V_263 ) ;
union V_217 V_218 ;
unsigned int V_14 = V_230 ;
if ( V_6 -> V_49 & V_184 )
return;
F_84 ( & V_6 -> V_266 ) ;
F_328 ( L_42 ) ;
F_85 ( & V_6 -> V_266 ) ;
V_218 . V_219 . V_220 = V_221 ;
if ( ! ( V_6 -> V_49 & ( V_165 | V_166 ) ) ||
V_6 -> V_49 & V_488 ||
F_26 ( V_6 , V_279 ,
& V_6 -> V_274 , & V_14 ) ) {
memset ( V_218 . V_219 . V_632 , 0 , V_230 ) ;
} else {
memcpy ( V_218 . V_219 . V_632 , V_6 -> V_274 , V_230 ) ;
memcpy ( V_6 -> V_150 -> V_274 , V_6 -> V_274 , V_230 ) ;
V_6 -> V_49 &= ~ V_165 ;
V_6 -> V_49 |= V_166 ;
F_264 ( V_6 -> V_33 ) ;
F_167 ( V_6 -> V_33 ) ;
}
if ( ! ( V_6 -> V_49 & V_166 ) ) {
F_328 ( L_323 ) ;
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
static int F_381 ( struct V_119 * V_846 )
{
struct V_847 * V_848 =
(struct V_847 * ) V_846 -> V_849 -> V_37 ;
if ( F_382 ( V_848 -> V_121 ) != V_850 ) {
F_27 (KERN_WARNING DRV_NAME L_324
L_325
L_326 ,
h->version) ;
return 1 ;
}
V_846 -> V_121 = V_848 -> V_121 ;
V_846 -> V_846 . V_37 = V_846 -> V_849 -> V_37 + sizeof( struct V_847 ) ;
V_846 -> V_846 . V_482 = V_848 -> V_851 ;
V_846 -> V_852 . V_37 = V_846 -> V_846 . V_37 + V_848 -> V_851 ;
V_846 -> V_852 . V_482 = V_848 -> V_853 ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 ,
struct V_119 * V_846 )
{
char * V_854 ;
int V_202 ;
F_31 ( L_327 ,
V_6 -> V_33 -> V_51 ) ;
switch ( V_6 -> V_150 -> V_198 ) {
case V_435 :
V_854 = F_383 ( L_328 ) ;
break;
#ifdef F_158
case V_199 :
V_854 = F_383 ( L_329 ) ;
break;
#endif
case V_430 :
default:
V_854 = F_383 ( L_50 ) ;
break;
}
V_202 = F_384 ( & V_846 -> V_849 , V_854 , & V_6 -> V_261 -> V_2 ) ;
if ( V_202 < 0 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_330 ,
priv->net_dev->name, fw_name) ;
return V_202 ;
}
F_31 ( L_331 , V_846 -> V_849 -> V_37 ,
V_846 -> V_849 -> V_482 ) ;
F_381 ( V_846 ) ;
return 0 ;
}
static void F_66 ( struct V_5 * V_6 ,
struct V_119 * V_846 )
{
V_846 -> V_121 = 0 ;
F_385 ( V_846 -> V_849 ) ;
V_846 -> V_849 = NULL ;
}
static int F_272 ( struct V_5 * V_6 , char * V_15 ,
T_4 V_855 )
{
char V_856 [ V_857 ] ;
T_1 V_14 = V_857 ;
T_1 V_317 ;
int V_19 ;
if ( F_26 ( V_6 , V_858 , V_856 , & V_14 ) )
return - V_70 ;
V_317 = V_855 ;
if ( V_14 >= V_855 )
V_14 = V_855 - 1 ;
for ( V_19 = 0 ; V_19 < V_14 ; V_19 ++ )
V_15 [ V_19 ] = V_856 [ V_19 ] ;
V_15 [ V_19 ] = '\0' ;
return V_317 ;
}
static int F_273 ( struct V_5 * V_6 , char * V_15 ,
T_4 V_855 )
{
T_1 V_856 ;
T_1 V_14 = sizeof( V_856 ) ;
if ( F_26 ( V_6 , V_859 , & V_856 , & V_14 ) )
return - V_70 ;
return snprintf ( V_15 , V_855 , L_14 , V_856 ) ;
}
static int F_65 ( struct V_5 * V_6 , struct V_119 * V_846 )
{
unsigned int V_8 ;
unsigned short V_14 ;
const unsigned char * V_860 = V_846 -> V_846 . V_37 ;
unsigned int V_861 = V_846 -> V_846 . V_482 ;
while ( V_861 > 0 ) {
V_8 = * ( T_1 * ) ( V_860 ) ;
V_860 += 4 ;
V_861 -= 4 ;
V_14 = * ( T_2 * ) ( V_860 ) ;
V_860 += 2 ;
V_861 -= 2 ;
if ( V_14 > 32 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_332 ,
len) ;
return - V_31 ;
}
F_23 ( V_6 -> V_33 , V_8 , V_14 , V_860 ) ;
V_860 += V_14 ;
V_861 -= V_14 ;
}
return 0 ;
}
static int F_64 ( struct V_5 * V_6 ,
struct V_119 * V_846 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
const unsigned char * V_862 = V_846 -> V_852 . V_37 ;
unsigned int V_863 = V_846 -> V_852 . V_482 ;
void T_12 * V_3 = V_6 -> V_7 ;
struct V_864 V_865 ;
int V_19 , V_40 ;
T_3 V_37 ;
F_18 ( V_2 , V_174 , 0x703 ) ;
F_386 ( V_3 ) ;
F_18 ( V_2 , V_174 , 0x707 ) ;
F_386 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_386 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_386 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x40 ) ;
F_386 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x0 ) ;
F_386 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x40 ) ;
F_386 ( V_3 ) ;
while ( V_863 > 0 ) {
F_20 ( V_2 , 0x210010 , * V_862 ++ ) ;
F_20 ( V_2 , 0x210010 , * V_862 ++ ) ;
V_863 -= 2 ;
}
F_20 ( V_2 , 0x210000 , 0x0 ) ;
F_386 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x0 ) ;
F_386 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x80 ) ;
F_386 ( V_3 ) ;
F_18 ( V_2 , V_174 , 0x703 ) ;
F_386 ( V_3 ) ;
F_18 ( V_2 , V_174 , 0x707 ) ;
F_386 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_386 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_386 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x00 ) ;
F_386 ( V_3 ) ;
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
V_40 < ( sizeof( struct V_864 ) >> 1 ) ; V_40 ++ )
F_17 ( V_2 , 0x210004 , ( ( T_2 * ) & V_865 ) + V_40 ) ;
if ( ( V_865 . V_866 == 1 ) && ( V_865 . V_867 == 0x1 ) )
break;
F_58 ( 10 ) ;
}
if ( V_19 == 30 ) {
F_27 (KERN_ERR DRV_NAME
L_334 ,
dev->name) ;
F_33 ( V_868 , ( T_3 * ) & V_865 , sizeof( V_865 ) ) ;
return - V_70 ;
}
return 0 ;
}
