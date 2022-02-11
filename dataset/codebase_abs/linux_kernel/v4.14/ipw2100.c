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
#define F_82 (msecs_to_jiffies(50))
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
int V_63 = 0 ;
T_1 V_202 ;
T_1 V_203 = sizeof( V_202 ) ;
if ( V_6 -> V_204 ) {
F_94 ( V_6 -> V_150 , V_6 -> V_204 ) ;
V_6 -> V_204 = 0 ;
}
if ( V_6 -> V_49 & V_205 ) {
F_31 ( L_79
L_80 , V_6 -> V_33 -> V_51 ) ;
return 0 ;
}
F_95 ( & V_206 , 175 ) ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
F_68 ( V_6 ) ;
F_79 ( V_6 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
if ( V_6 -> V_49 & V_207 ||
( V_6 -> V_49 & V_50 ) ) {
V_63 = F_80 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_81 ,
priv->net_dev->name) ;
goto exit;
}
} else
V_6 -> V_49 |= V_207 ;
V_63 = F_76 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_82 ,
priv->net_dev->name) ;
goto exit;
}
F_69 ( V_6 ) ;
V_63 = F_75 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_83 ,
priv->net_dev->name) ;
goto exit;
}
F_96 ( V_6 -> V_150 , & V_208 [ 0 ] ) ;
V_6 -> V_150 -> V_209 = V_210 ;
V_202 = V_211 ;
V_63 = F_30 ( V_6 , V_212 , & V_202 , & V_203 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_84 ,
priv->net_dev->name) ;
goto exit;
}
V_6 -> V_49 &= ~ V_200 ;
if ( F_71 ( V_6 ) ) {
F_27 ( V_213 L_85 ,
V_6 -> V_33 -> V_51 ) ;
if ( V_6 -> V_214 ) {
V_6 -> V_214 = 0 ;
F_39 ( & V_6 -> V_215 ,
F_97 ( V_53 ) ) ;
}
V_201 = 1 ;
}
F_67 ( V_6 ) ;
V_63 = F_98 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME L_86 ,
priv->net_dev->name) ;
goto exit;
}
if ( ! V_201 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_87 ,
priv->net_dev->name) ;
F_86 ( V_6 ) ;
goto exit;
}
F_90 ( V_6 ) ;
F_92 ( V_6 ) ;
}
exit:
return V_63 ;
}
static void F_99 ( struct V_5 * V_6 )
{
unsigned long V_62 ;
union V_216 V_217 = {
. V_218 = {
. V_219 = V_220 }
} ;
int V_221 = V_6 -> V_49 & V_166 ;
if ( ! V_6 -> V_214 ) {
V_6 -> V_214 = 1 ;
F_89 ( & V_6 -> V_215 ) ;
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
F_95 ( & V_206 , V_222 ) ;
if ( V_221 )
F_100 ( V_6 -> V_33 , V_223 , & V_217 , NULL ) ;
V_6 -> V_49 &= ~ ( V_166 | V_165 ) ;
F_37 ( V_6 -> V_33 ) ;
F_38 ( V_6 -> V_33 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_224 * V_225 = F_102 ( V_6 -> V_150 ) ;
struct V_226 * V_151 = & V_6 -> V_150 -> V_151 ;
int V_19 ;
memcpy ( V_151 -> V_152 -> V_227 , V_6 -> V_228 , V_229 ) ;
if ( V_225 -> V_230 ) {
struct V_231 * V_232 = & V_6 -> V_150 -> V_232 ;
V_232 -> V_233 = V_234 ;
V_232 -> V_235 = V_225 -> V_230 ;
V_232 -> V_236 = F_103 ( V_225 -> V_230 ,
sizeof( struct V_237 ) ,
V_238 ) ;
if ( ! V_232 -> V_236 ) {
F_99 ( V_6 ) ;
return - V_239 ;
}
for ( V_19 = 0 ; V_19 < V_225 -> V_230 ; V_19 ++ ) {
V_232 -> V_236 [ V_19 ] . V_233 = V_234 ;
V_232 -> V_236 [ V_19 ] . V_240 = V_225 -> V_241 [ V_19 ] . V_242 ;
V_232 -> V_236 [ V_19 ] . V_243 = V_225 -> V_241 [ V_19 ] . V_244 ;
V_232 -> V_236 [ V_19 ] . V_245 = V_225 -> V_241 [ V_19 ] . V_245 ;
if ( V_225 -> V_241 [ V_19 ] . V_62 & V_246 )
V_232 -> V_236 [ V_19 ] . V_62 |=
V_247 ;
if ( V_225 -> V_241 [ V_19 ] . V_62 & V_248 )
V_232 -> V_236 [ V_19 ] . V_62 |=
V_247 ;
if ( V_225 -> V_241 [ V_19 ] . V_62 & V_249 )
V_232 -> V_236 [ V_19 ] . V_62 |=
V_250 ;
}
V_232 -> V_251 = V_252 ;
V_232 -> V_253 = V_254 ;
V_151 -> V_152 -> V_255 [ V_234 ] = V_232 ;
}
V_151 -> V_152 -> V_256 = V_257 ;
V_151 -> V_152 -> V_258 = F_104 ( V_257 ) ;
F_105 ( V_151 -> V_152 , & V_6 -> V_259 -> V_2 ) ;
if ( F_106 ( V_151 -> V_152 ) )
return - V_70 ;
return 0 ;
}
static void F_107 ( struct V_260 * V_261 )
{
struct V_5 * V_6 =
F_108 ( V_261 , struct V_5 , V_52 . V_261 ) ;
unsigned long V_62 ;
union V_216 V_217 = {
. V_218 = {
. V_219 = V_220 }
} ;
int V_221 = V_6 -> V_49 & V_166 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
F_31 ( L_89 , V_6 -> V_33 -> V_51 ) ;
V_6 -> V_262 ++ ;
V_6 -> V_49 &= ~ ( V_166 | V_165 ) ;
V_6 -> V_49 |= V_263 ;
F_89 ( & V_6 -> V_52 ) ;
V_6 -> V_49 |= V_50 ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
F_84 ( & V_6 -> V_264 ) ;
V_6 -> V_181 = 1 ;
F_89 ( & V_6 -> V_182 ) ;
if ( V_221 )
F_100 ( V_6 -> V_33 , V_223 , & V_217 , NULL ) ;
F_93 ( V_6 , 0 ) ;
F_85 ( & V_6 -> V_264 ) ;
}
static void F_109 ( struct V_5 * V_6 , T_1 V_49 )
{
#define F_110 (HZ)
int V_265 ;
unsigned int V_14 , V_266 ;
char V_267 [ V_268 ] ;
T_1 V_269 ;
T_1 V_270 ;
char * V_271 ;
T_3 V_272 [ V_229 ] ;
V_266 = V_268 ;
V_265 = F_26 ( V_6 , V_273 ,
V_267 , & V_266 ) ;
if ( V_265 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
V_14 = sizeof( T_1 ) ;
V_265 = F_26 ( V_6 , V_274 , & V_269 , & V_14 ) ;
if ( V_265 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
V_14 = sizeof( T_1 ) ;
V_265 = F_26 ( V_6 , V_275 , & V_270 , & V_14 ) ;
if ( V_265 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
V_14 = V_229 ;
V_265 = F_26 ( V_6 , V_276 , V_272 ,
& V_14 ) ;
if ( V_265 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
memcpy ( V_6 -> V_150 -> V_272 , V_272 , V_229 ) ;
switch ( V_269 ) {
case V_277 :
V_271 = L_90 ;
break;
case V_278 :
V_271 = L_91 ;
break;
case V_279 :
V_271 = L_92 ;
break;
case V_280 :
V_271 = L_93 ;
break;
default:
F_31 ( L_94 , V_269 ) ;
V_271 = L_95 ;
break;
}
F_31 ( L_96 ,
V_6 -> V_33 -> V_51 , V_266 , V_267 ,
V_271 , V_270 , V_272 ) ;
if ( ! ( V_6 -> V_187 & V_281 ) ) {
V_6 -> V_266 = F_34 ( ( T_3 ) V_266 , ( T_3 ) V_268 ) ;
memcpy ( V_6 -> V_267 , V_267 , V_6 -> V_266 ) ;
}
V_6 -> V_244 = V_270 ;
memcpy ( V_6 -> V_272 , V_272 , V_229 ) ;
V_6 -> V_49 |= V_165 ;
V_6 -> V_282 = F_36 () ;
F_39 ( & V_6 -> V_283 , V_53 / 10 ) ;
}
static int F_111 ( struct V_5 * V_6 , char * V_267 ,
int V_284 , int V_285 )
{
int V_286 = F_34 ( V_284 , V_268 ) ;
struct V_56 V_57 = {
. V_56 = V_287 ,
. V_88 = 0 ,
. V_65 = V_286
} ;
int V_63 ;
F_42 ( L_97 , V_286 , V_267 ) ;
if ( V_286 )
memcpy ( V_57 . V_67 , V_267 , V_286 ) ;
if ( ! V_285 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
if ( ! V_286 && ! ( V_6 -> V_187 & V_188 ) ) {
int V_19 ;
T_3 * V_288 = ( T_3 * ) V_57 . V_67 ;
for ( V_19 = 0 ; V_19 < V_268 ; V_19 ++ )
V_288 [ V_19 ] = 0x18 + V_19 ;
V_57 . V_65 = V_268 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_63 ) {
memset ( V_6 -> V_267 + V_286 , 0 , V_268 - V_286 ) ;
memcpy ( V_6 -> V_267 , V_267 , V_286 ) ;
V_6 -> V_266 = V_286 ;
}
if ( ! V_285 ) {
if ( F_83 ( V_6 ) )
V_63 = - V_70 ;
}
return V_63 ;
}
static void F_112 ( struct V_5 * V_6 , T_1 V_49 )
{
F_113 ( V_289 | V_290 | V_291 ,
L_98 , V_6 -> V_266 , V_6 -> V_267 ,
V_6 -> V_272 ) ;
V_6 -> V_49 &= ~ ( V_166 | V_165 ) ;
if ( V_6 -> V_49 & V_184 ) {
F_31 ( L_99 ) ;
return;
}
F_114 ( V_6 -> V_272 ) ;
F_114 ( V_6 -> V_150 -> V_272 ) ;
F_37 ( V_6 -> V_33 ) ;
F_38 ( V_6 -> V_33 ) ;
if ( ! ( V_6 -> V_49 & V_72 ) )
return;
if ( V_6 -> V_49 & V_263 )
F_39 ( & V_6 -> V_292 , 0 ) ;
F_39 ( & V_6 -> V_283 , 0 ) ;
}
static void F_115 ( struct V_5 * V_6 , T_1 V_49 )
{
F_31 ( L_100 ,
V_6 -> V_33 -> V_51 ) ;
F_74 ( V_6 -> V_150 -> V_151 . V_152 , true ) ;
V_6 -> V_49 |= V_153 ;
V_6 -> V_214 = 0 ;
F_116 ( V_293 , & V_6 -> V_215 , F_97 ( V_53 ) ) ;
}
static void F_117 ( struct V_260 * V_261 )
{
struct V_5 * V_6 = F_108 ( V_261 , struct V_5 ,
V_294 . V_261 ) ;
union V_216 V_217 ;
V_217 . V_37 . V_284 = 0 ;
V_217 . V_37 . V_62 = 0 ;
F_100 ( V_6 -> V_33 , V_295 , & V_217 , NULL ) ;
}
static void F_118 ( struct V_5 * V_6 , T_1 V_49 )
{
F_91 ( L_101 ) ;
V_6 -> V_150 -> V_296 ++ ;
V_6 -> V_49 &= ~ V_200 ;
if ( ! V_6 -> V_297 ) {
F_39 ( & V_6 -> V_294 ,
F_97 ( F_55 ( 4000 ) ) ) ;
} else {
V_6 -> V_297 = 0 ;
F_116 ( V_293 , & V_6 -> V_294 , 0 ) ;
}
}
static void F_119 ( struct V_5 * V_6 , T_1 V_49 )
{
F_91 ( L_102 ) ;
V_6 -> V_49 |= V_200 ;
}
static void F_120 ( struct V_5 * V_6 , int V_49 )
{
int V_19 ;
if ( V_49 == V_298 &&
V_6 -> V_49 & V_166 &&
! ( V_6 -> V_49 & V_200 ) ) {
F_31 ( L_103
L_104 ) ;
F_35 ( V_6 ) ;
}
for ( V_19 = 0 ; V_299 [ V_19 ] . V_49 != - 1 ; V_19 ++ ) {
if ( V_49 == V_299 [ V_19 ] . V_49 ) {
F_121 ( L_105 ,
V_299 [ V_19 ] . V_51 ) ;
if ( V_299 [ V_19 ] . V_300 )
V_299 [ V_19 ] . V_300 ( V_6 , V_49 ) ;
V_6 -> V_301 . V_49 = V_49 ;
return;
}
}
F_121 ( L_106 , V_49 ) ;
}
static void F_122 ( struct V_5 * V_6 ,
struct V_302 * V_57 )
{
#ifdef F_123
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
static int F_124 ( struct V_5 * V_6 ,
struct V_303 * V_61 )
{
V_61 -> V_304 = F_125 ( sizeof( struct V_305 ) ) ;
if ( ! V_61 -> V_304 )
return - V_239 ;
V_61 -> V_306 = (struct V_305 * ) V_61 -> V_304 -> V_37 ;
V_61 -> V_307 = F_126 ( V_6 -> V_259 , V_61 -> V_304 -> V_37 ,
sizeof( struct V_305 ) ,
V_308 ) ;
if ( F_127 ( V_6 -> V_259 , V_61 -> V_307 ) ) {
F_128 ( V_61 -> V_304 ) ;
return - V_239 ;
}
return 0 ;
}
static void F_129 ( struct V_5 * V_6 )
{
int V_19 ;
if ( ! V_6 -> V_309 [ 0 ] )
return;
for ( V_19 = 0 ; V_19 < 0x30 ; V_19 ++ )
F_130 ( V_6 -> V_309 [ V_19 ] ) ;
V_6 -> V_309 [ 0 ] = NULL ;
}
static int F_131 ( struct V_5 * V_6 )
{
int V_19 ;
if ( V_6 -> V_309 [ 0 ] )
return 1 ;
for ( V_19 = 0 ; V_19 < 0x30 ; V_19 ++ ) {
V_6 -> V_309 [ V_19 ] = F_132 ( 0x1000 , V_310 ) ;
if ( ! V_6 -> V_309 [ V_19 ] ) {
F_31 ( L_108
L_109 , V_6 -> V_33 -> V_51 , V_19 ) ;
while ( V_19 > 0 )
F_130 ( V_6 -> V_309 [ -- V_19 ] ) ;
V_6 -> V_309 [ 0 ] = NULL ;
return 0 ;
}
}
return 1 ;
}
static T_1 F_133 ( struct V_5 * V_6 , T_3 * V_311 ,
T_4 V_14 , int V_312 )
{
T_1 V_19 , V_40 ;
T_1 V_313 ;
T_3 * V_314 , * V_315 ;
T_1 V_265 ;
V_314 = V_311 ;
if ( V_312 == V_316 ) {
if ( ! F_131 ( V_6 ) )
V_312 = V_317 ;
}
for ( V_265 = V_318 , V_19 = 0 ; V_19 < 0x30000 ; V_19 += 4 ) {
F_15 ( V_6 -> V_33 , V_19 , & V_313 ) ;
if ( V_312 == V_316 )
* ( T_1 * ) F_134 ( V_19 ) = V_313 ;
if ( V_265 == V_318 ) {
V_315 = ( T_3 * ) & V_313 ;
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
if ( * V_314 != * V_315 ) {
V_314 = V_311 ;
continue;
}
V_314 ++ ;
V_315 ++ ;
if ( ( V_314 - V_311 ) == V_14 )
V_265 = ( V_19 + V_40 ) - V_14 + 1 ;
}
} else if ( V_312 == V_317 )
return V_265 ;
}
return V_265 ;
}
static void F_135 ( struct V_5 * V_6 , int V_19 )
{
#ifdef F_136
struct V_319 * V_49 = & V_6 -> V_320 . V_321 [ V_19 ] ;
T_1 V_322 , V_3 ;
int V_40 ;
#endif
F_31 ( L_110 ,
V_19 * sizeof( struct V_319 ) ) ;
#ifdef F_136
F_5 ( V_6 -> V_33 , V_110 ,
V_170 ) ;
V_40 = 5 ;
do {
F_58 ( V_171 ) ;
F_1 ( V_6 -> V_33 , V_110 , & V_3 ) ;
if ( V_3 & V_172 )
break;
} while ( V_40 -- );
V_322 = F_133 ( V_6 , ( T_3 * ) V_49 ,
sizeof( struct V_319 ) ,
V_316 ) ;
if ( V_322 < V_323 )
F_31 ( L_111
L_112 ,
V_6 -> V_33 -> V_51 , V_322 ,
sizeof( struct V_319 ) ) ;
else
F_31 ( L_113
L_114 , V_6 -> V_33 -> V_51 ) ;
F_33 ( ( T_3 * ) V_6 -> V_320 . V_321 ,
sizeof( struct V_319 ) * V_324 ) ;
#endif
V_6 -> V_69 = V_325 ;
V_6 -> V_33 -> V_326 . V_327 ++ ;
F_35 ( V_6 ) ;
}
static void F_137 ( struct V_5 * V_6 , int V_19 ,
struct V_328 * V_326 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
struct V_319 * V_49 = & V_6 -> V_320 . V_321 [ V_19 ] ;
struct V_303 * V_61 = & V_6 -> V_329 [ V_19 ] ;
F_138 ( L_115 ) ;
if ( F_139 ( V_49 -> V_330 > F_140 ( V_61 -> V_304 ) ) ) {
F_31 ( L_116
L_117 ,
V_2 -> V_51 ,
V_49 -> V_330 , F_140 ( V_61 -> V_304 ) ) ;
V_2 -> V_326 . V_327 ++ ;
return;
}
if ( F_139 ( ! F_141 ( V_2 ) ) ) {
V_2 -> V_326 . V_327 ++ ;
V_6 -> V_301 . V_331 . V_332 ++ ;
F_142 ( L_118 ) ;
return;
}
if ( F_139 ( V_6 -> V_150 -> V_198 != V_199 &&
! ( V_6 -> V_49 & V_166 ) ) ) {
F_142 ( L_119 ) ;
V_6 -> V_301 . V_331 . V_332 ++ ;
return;
}
F_143 ( V_6 -> V_259 ,
V_61 -> V_307 ,
sizeof( struct V_305 ) , V_308 ) ;
F_144 ( V_61 -> V_304 , V_49 -> V_330 ) ;
#ifdef F_145
F_146 ( V_61 -> V_304 , V_333 ,
F_147 ( T_1 , V_49 -> V_330 ,
V_334 ) ) ;
#endif
if ( ! F_148 ( V_6 -> V_150 , V_61 -> V_304 , V_326 ) ) {
#ifdef F_145
F_142 ( L_120 ,
V_2 -> V_51 ) ;
F_33 ( V_335 , V_333 , V_49 -> V_330 ) ;
#endif
V_2 -> V_326 . V_327 ++ ;
F_149 ( V_61 -> V_304 ) ;
V_61 -> V_304 = NULL ;
}
if ( F_139 ( F_124 ( V_6 , V_61 ) ) ) {
F_27 (KERN_WARNING DRV_NAME L_67
L_121
L_122 , dev->name) ;
F_31 ( L_123 ) ;
}
V_6 -> V_336 . V_321 [ V_19 ] . V_337 = V_61 -> V_307 ;
}
static void F_150 ( struct V_5 * V_6 , int V_19 ,
struct V_328 * V_326 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
struct V_319 * V_49 = & V_6 -> V_320 . V_321 [ V_19 ] ;
struct V_303 * V_61 = & V_6 -> V_329 [ V_19 ] ;
struct V_338 {
struct V_339 V_340 ;
T_5 V_341 ;
} * V_342 ;
F_138 ( L_115 ) ;
if ( F_139 ( V_49 -> V_330 > F_140 ( V_61 -> V_304 ) -
sizeof( struct V_338 ) ) ) {
F_31 ( L_116
L_117 ,
V_2 -> V_51 ,
V_49 -> V_330 ,
F_140 ( V_61 -> V_304 ) ) ;
V_2 -> V_326 . V_327 ++ ;
return;
}
if ( F_139 ( ! F_141 ( V_2 ) ) ) {
V_2 -> V_326 . V_327 ++ ;
V_6 -> V_301 . V_331 . V_332 ++ ;
F_142 ( L_118 ) ;
return;
}
if ( F_139 ( V_6 -> V_187 & V_343 &&
V_49 -> V_62 & V_344 ) ) {
F_138 ( L_124 ) ;
V_2 -> V_326 . V_327 ++ ;
return;
}
F_143 ( V_6 -> V_259 , V_61 -> V_307 ,
sizeof( struct V_305 ) , V_308 ) ;
memmove ( V_61 -> V_304 -> V_37 + sizeof( struct V_338 ) ,
V_61 -> V_304 -> V_37 , V_49 -> V_330 ) ;
V_342 = (struct V_338 * ) V_61 -> V_304 -> V_37 ;
V_342 -> V_340 . V_345 = V_346 ;
V_342 -> V_340 . V_347 = 0 ;
V_342 -> V_340 . V_348 = F_151 ( sizeof( struct V_338 ) ) ;
V_342 -> V_340 . V_349 = F_152 ( 1 << V_350 ) ;
V_342 -> V_341 = V_49 -> V_351 + V_352 ;
F_144 ( V_61 -> V_304 , V_49 -> V_330 + sizeof( struct V_338 ) ) ;
if ( ! F_148 ( V_6 -> V_150 , V_61 -> V_304 , V_326 ) ) {
V_2 -> V_326 . V_327 ++ ;
F_149 ( V_61 -> V_304 ) ;
V_61 -> V_304 = NULL ;
}
if ( F_139 ( F_124 ( V_6 , V_61 ) ) ) {
F_153 (
L_121
L_122 , V_2 -> V_51 ) ;
F_31 ( L_123 ) ;
}
V_6 -> V_336 . V_321 [ V_19 ] . V_337 = V_61 -> V_307 ;
}
static int F_154 ( struct V_5 * V_6 , int V_19 )
{
struct V_319 * V_49 = & V_6 -> V_320 . V_321 [ V_19 ] ;
struct V_305 * V_353 = V_6 -> V_329 [ V_19 ] . V_306 ;
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
#ifdef F_155
return 0 ;
#else
switch ( F_156 ( F_157 ( V_353 -> V_358 . V_365 . V_366 ) ) ) {
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
static void F_158 ( struct V_5 * V_6 )
{
struct V_371 * V_372 = & V_6 -> V_336 ;
struct V_373 * V_374 = & V_6 -> V_320 ;
struct V_303 * V_61 ;
T_2 V_354 ;
T_1 V_109 , V_375 , V_19 , V_314 ;
struct V_305 * V_353 ;
struct V_328 V_326 = {
. V_376 = V_80 ,
} ;
F_1 ( V_6 -> V_33 , V_377 , & V_109 ) ;
F_1 ( V_6 -> V_33 , V_378 , & V_375 ) ;
if ( V_109 >= V_372 -> V_379 ) {
F_138 ( L_125 ) ;
return;
}
V_19 = ( V_372 -> V_77 + 1 ) % V_372 -> V_379 ;
V_314 = V_19 ;
while ( V_19 != V_109 ) {
V_61 = & V_6 -> V_329 [ V_19 ] ;
F_159 ( V_6 -> V_259 , V_61 -> V_307 ,
sizeof( struct V_305 ) ,
V_308 ) ;
if ( F_139 ( F_154 ( V_6 , V_19 ) ) ) {
F_135 ( V_6 , V_19 ) ;
goto V_380;
}
V_353 = V_61 -> V_306 ;
V_354 = V_374 -> V_321 [ V_19 ] . V_355 & V_356 ;
V_326 . V_351 = V_374 -> V_321 [ V_19 ] . V_351 + V_352 ;
V_326 . V_14 = V_374 -> V_321 [ V_19 ] . V_330 ;
V_326 . V_381 = 0 ;
if ( V_326 . V_351 != 0 )
V_326 . V_381 |= V_382 ;
V_326 . V_242 = V_210 ;
F_138 ( L_126 ,
V_6 -> V_33 -> V_51 , V_383 [ V_354 ] ,
V_326 . V_14 ) ;
switch ( V_354 ) {
case V_357 :
F_122 ( V_6 , & V_353 -> V_358 . V_359 ) ;
break;
case V_360 :
F_120 ( V_6 , V_353 -> V_358 . V_49 ) ;
break;
case V_363 :
case V_364 :
#ifdef F_155
if ( V_6 -> V_150 -> V_198 == V_199 ) {
F_150 ( V_6 , V_19 , & V_326 ) ;
break;
}
#endif
if ( V_326 . V_14 < sizeof( struct V_384 ) )
break;
switch ( F_156 ( F_157 ( V_353 -> V_358 . V_365 . V_366 ) ) ) {
case V_367 :
F_160 ( V_6 -> V_150 ,
& V_353 -> V_358 . V_365 , & V_326 ) ;
break;
case V_368 :
break;
case V_369 :
F_137 ( V_6 , V_19 , & V_326 ) ;
break;
}
break;
}
V_380:
V_372 -> V_321 [ V_19 ] . V_49 . V_81 . V_385 = 0 ;
V_19 = ( V_19 + 1 ) % V_372 -> V_379 ;
}
if ( V_19 != V_314 ) {
V_372 -> V_77 = ( V_19 ? V_19 : V_372 -> V_379 ) - 1 ;
F_5 ( V_6 -> V_33 ,
V_378 , V_372 -> V_77 ) ;
}
}
static int F_161 ( struct V_5 * V_6 )
{
struct V_371 * V_386 = & V_6 -> V_387 ;
struct V_388 * V_389 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
int V_390 ;
int V_391 , V_19 ;
T_1 V_109 , V_375 , V_392 = 0 ;
if ( F_44 ( & V_6 -> V_393 ) )
return 0 ;
V_59 = V_6 -> V_393 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
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
F_27 (KERN_WARNING DRV_NAME L_127 ,
priv->net_dev->name) ;
return 0 ;
}
F_1 ( V_6 -> V_33 , V_399 ,
& V_109 ) ;
F_1 ( V_6 -> V_33 , V_400 ,
& V_375 ) ;
if ( V_375 != V_386 -> V_77 )
F_27 (KERN_WARNING DRV_NAME L_128 ,
priv->net_dev->name) ;
if ( ! ( ( V_109 <= V_375 && ( V_391 < V_109 || V_391 >= V_375 ) ) || ( V_391 < V_109 && V_391 >= V_375 ) ) ) {
F_162 ( L_129 ) ;
return 0 ;
}
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_401 ) ;
#ifdef F_123
{
V_19 = V_386 -> V_396 ;
F_162 ( L_130 , V_19 ,
& V_386 -> V_321 [ V_19 ] ,
( T_1 ) ( V_386 -> V_402 + V_19 * sizeof( struct V_388 ) ) ,
V_386 -> V_321 [ V_19 ] . V_337 , V_386 -> V_321 [ V_19 ] . V_403 ) ;
if ( V_61 -> type == V_397 ) {
V_19 = ( V_19 + 1 ) % V_386 -> V_379 ;
F_162 ( L_130 , V_19 ,
& V_386 -> V_321 [ V_19 ] ,
( T_1 ) ( V_386 -> V_402 + V_19 *
sizeof( struct V_388 ) ) ,
( T_1 ) V_386 -> V_321 [ V_19 ] . V_337 ,
V_386 -> V_321 [ V_19 ] . V_403 ) ;
}
}
#endif
switch ( V_61 -> type ) {
case V_397 :
if ( V_386 -> V_321 [ V_386 -> V_396 ] . V_49 . V_81 . V_404 . V_405 != 0 )
F_27 (KERN_WARNING DRV_NAME L_131
L_132
L_133 ,
priv->net_dev->name, txq->oldest, packet->index) ;
for ( V_19 = 0 ; V_19 < V_392 ; V_19 ++ ) {
V_389 = & V_386 -> V_321 [ ( V_61 -> V_394 + 1 + V_19 ) % V_386 -> V_379 ] ;
F_162 ( L_134 ,
( V_61 -> V_394 + 1 + V_19 ) % V_386 -> V_379 ,
V_389 -> V_337 , V_389 -> V_403 ) ;
F_143 ( V_6 -> V_259 ,
V_389 -> V_337 ,
V_389 -> V_403 , V_406 ) ;
}
F_163 ( V_61 -> V_81 . V_407 . V_408 ) ;
V_61 -> V_81 . V_407 . V_408 = NULL ;
F_48 ( V_59 , & V_6 -> V_409 ) ;
F_49 ( & V_6 -> V_410 ) ;
if ( V_6 -> V_49 & V_166 )
F_164 ( V_6 -> V_33 ) ;
F_165 ( V_6 -> V_33 ) ;
break;
case V_395 :
if ( V_386 -> V_321 [ V_386 -> V_396 ] . V_49 . V_81 . V_404 . V_405 != 1 )
F_27 (KERN_WARNING DRV_NAME L_131
L_135
L_133 ,
priv->net_dev->name, txq->oldest, packet->index) ;
#ifdef F_123
if ( V_61 -> V_81 . V_82 . V_57 -> V_83 <
F_104 ( V_64 ) )
F_162 ( L_136 ,
V_64 [ V_61 -> V_81 . V_82 . V_57 ->
V_83 ] ,
V_61 -> V_81 . V_82 . V_57 ->
V_83 ,
V_61 -> V_81 . V_82 . V_57 -> V_411 ) ;
#endif
F_48 ( V_59 , & V_6 -> V_75 ) ;
F_49 ( & V_6 -> V_90 ) ;
break;
}
V_386 -> V_396 = ( V_391 + 1 ) % V_386 -> V_379 ;
V_386 -> V_412 += V_390 ;
F_166 ( & V_6 -> V_413 , V_386 -> V_412 ) ;
F_162 ( L_137 ,
V_80 - V_61 -> V_79 ) ;
return ( ! F_44 ( & V_6 -> V_393 ) ) ;
}
static inline void F_167 ( struct V_5 * V_6 )
{
int V_19 = 0 ;
while ( F_161 ( V_6 ) && V_19 < 200 )
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
struct V_371 * V_386 = & V_6 -> V_387 ;
struct V_388 * V_389 ;
int V_77 = V_386 -> V_77 ;
while ( ! F_44 ( & V_6 -> V_91 ) ) {
if ( V_386 -> V_412 <= 3 ) {
F_162 ( L_139 ) ;
break;
}
V_59 = V_6 -> V_91 . V_77 ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_92 ) ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
F_162 ( L_140 ,
& V_386 -> V_321 [ V_386 -> V_77 ] ,
( T_1 ) ( V_386 -> V_402 + V_386 -> V_77 *
sizeof( struct V_388 ) ) ) ;
V_61 -> V_394 = V_386 -> V_77 ;
V_389 = & V_386 -> V_321 [ V_386 -> V_77 ] ;
V_389 -> V_337 = V_61 -> V_81 . V_82 . V_414 ;
V_389 -> V_403 = sizeof( struct V_302 ) ;
V_389 -> V_398 = 1 ;
V_389 -> V_49 . V_81 . V_385 =
V_415 |
V_416 ;
V_386 -> V_77 ++ ;
V_386 -> V_77 %= V_386 -> V_379 ;
V_386 -> V_412 -- ;
F_47 ( & V_6 -> V_413 ) ;
F_48 ( V_59 , & V_6 -> V_393 ) ;
F_49 ( & V_6 -> V_401 ) ;
}
if ( V_386 -> V_77 != V_77 ) {
F_168 () ;
F_5 ( V_6 -> V_33 ,
V_400 ,
V_386 -> V_77 ) ;
}
}
static void F_51 ( struct V_5 * V_6 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_371 * V_386 = & V_6 -> V_387 ;
struct V_388 * V_389 ;
int V_77 = V_386 -> V_77 ;
int V_19 = 0 ;
struct V_417 * V_418 ;
struct V_384 * V_419 ;
while ( ! F_44 ( & V_6 -> V_420 ) ) {
V_59 = V_6 -> V_420 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
if ( F_139 ( 1 + V_61 -> V_81 . V_407 . V_408 -> V_421 >
V_422 ) ) {
F_31 ( L_141
L_142 ,
V_6 -> V_33 -> V_51 ) ;
}
if ( V_386 -> V_412 <= 3 + V_61 -> V_81 . V_407 . V_408 -> V_421 ) {
F_162 ( L_139 ) ;
break;
}
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_423 ) ;
V_389 = & V_386 -> V_321 [ V_386 -> V_77 ] ;
V_61 -> V_394 = V_386 -> V_77 ;
V_418 = V_61 -> V_81 . V_407 . V_37 ;
V_419 = (struct V_384 * ) V_61 -> V_81 . V_407 . V_408 ->
V_424 [ 0 ] -> V_37 ;
if ( V_6 -> V_150 -> V_198 == V_425 ) {
memcpy ( V_418 -> V_426 , V_419 -> V_427 , V_229 ) ;
memcpy ( V_418 -> V_428 , V_419 -> V_429 , V_229 ) ;
} else if ( V_6 -> V_150 -> V_198 == V_430 ) {
memcpy ( V_418 -> V_426 , V_419 -> V_427 , V_229 ) ;
memcpy ( V_418 -> V_428 , V_419 -> V_431 , V_229 ) ;
}
V_418 -> V_83 = V_432 ;
V_418 -> V_84 = 0 ;
V_418 -> V_433 = 0 ;
V_418 -> V_434 = V_61 -> V_81 . V_407 . V_408 -> V_434 ;
if ( V_61 -> V_81 . V_407 . V_408 -> V_421 > 1 )
V_418 -> V_435 =
V_61 -> V_81 . V_407 . V_408 -> V_436 -
V_437 ;
else
V_418 -> V_435 = 0 ;
V_389 -> V_337 = V_61 -> V_81 . V_407 . V_438 ;
V_389 -> V_403 = sizeof( struct V_417 ) ;
V_389 -> V_398 = 1 + V_61 -> V_81 . V_407 . V_408 -> V_421 ;
V_389 -> V_49 . V_81 . V_385 =
V_439 |
V_440 ;
V_386 -> V_77 ++ ;
V_386 -> V_77 %= V_386 -> V_379 ;
F_162 ( L_143 ,
V_61 -> V_394 , V_389 -> V_337 , V_389 -> V_403 ) ;
#ifdef F_123
if ( V_61 -> V_81 . V_407 . V_408 -> V_421 > 1 )
F_169 ( L_144 ,
V_61 -> V_81 . V_407 . V_408 -> V_421 ) ;
#endif
for ( V_19 = 0 ; V_19 < V_61 -> V_81 . V_407 . V_408 -> V_421 ; V_19 ++ ) {
V_389 = & V_386 -> V_321 [ V_386 -> V_77 ] ;
if ( V_19 == V_61 -> V_81 . V_407 . V_408 -> V_421 - 1 )
V_389 -> V_49 . V_81 . V_385 =
V_439 |
V_416 ;
else
V_389 -> V_49 . V_81 . V_385 =
V_439 |
V_440 ;
V_389 -> V_403 = V_61 -> V_81 . V_407 . V_408 ->
V_424 [ V_19 ] -> V_14 - V_437 ;
V_389 -> V_337 = F_126 ( V_6 -> V_259 ,
V_61 -> V_81 . V_407 .
V_408 -> V_424 [ V_19 ] ->
V_37 +
V_437 ,
V_389 -> V_403 ,
V_406 ) ;
if ( F_127 ( V_6 -> V_259 ,
V_389 -> V_337 ) ) {
F_162 ( L_145 ) ;
break;
}
F_162 ( L_146 ,
V_386 -> V_77 , V_389 -> V_337 ,
V_389 -> V_403 ) ;
F_170 ( V_6 -> V_259 ,
V_389 -> V_337 ,
V_389 -> V_403 ,
V_406 ) ;
V_386 -> V_77 ++ ;
V_386 -> V_77 %= V_386 -> V_379 ;
}
V_386 -> V_412 -= 1 + V_61 -> V_81 . V_407 . V_408 -> V_421 ;
F_166 ( & V_6 -> V_413 , V_386 -> V_412 ) ;
F_48 ( V_59 , & V_6 -> V_393 ) ;
F_49 ( & V_6 -> V_401 ) ;
}
if ( V_386 -> V_77 != V_77 ) {
F_5 ( V_6 -> V_33 ,
V_400 ,
V_386 -> V_77 ) ;
}
}
static void F_171 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
unsigned long V_62 ;
T_1 V_157 , V_313 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
F_68 ( V_6 ) ;
F_1 ( V_2 , V_160 , & V_157 ) ;
F_172 ( L_147 ,
( unsigned long ) V_157 & V_138 ) ;
V_6 -> V_441 ++ ;
V_6 -> V_442 ++ ;
F_172 ( L_148 ,
( unsigned long ) V_157 & V_138 ) ;
if ( V_157 & V_162 ) {
F_27 (KERN_WARNING DRV_NAME
L_149 ) ;
V_6 -> V_443 ++ ;
F_5 ( V_2 , V_160 , V_162 ) ;
F_15 ( V_2 , V_444 , & V_6 -> V_69 ) ;
F_31 ( L_150 ,
V_6 -> V_33 -> V_51 , V_6 -> V_69 ) ;
F_15 ( V_2 , F_173 ( V_6 -> V_69 ) , & V_313 ) ;
F_31 ( L_151 ,
V_6 -> V_33 -> V_51 , V_313 ) ;
F_35 ( V_6 ) ;
}
if ( V_157 & V_163 ) {
F_27 (KERN_ERR DRV_NAME
L_152 ) ;
V_6 -> V_443 ++ ;
F_5 ( V_2 , V_160 , V_163 ) ;
}
if ( V_157 & V_445 ) {
F_172 ( L_153 ) ;
V_6 -> V_446 ++ ;
F_5 ( V_2 , V_160 , V_445 ) ;
F_158 ( V_6 ) ;
F_167 ( V_6 ) ;
}
if ( V_157 & V_447 ) {
F_172 ( L_154 ) ;
V_6 -> V_448 ++ ;
F_5 ( V_2 , V_160 , V_447 ) ;
F_167 ( V_6 ) ;
F_50 ( V_6 ) ;
F_51 ( V_6 ) ;
}
if ( V_157 & V_449 ) {
F_172 ( L_155 ) ;
V_6 -> V_443 ++ ;
F_5 ( V_2 , V_160 , V_449 ) ;
F_167 ( V_6 ) ;
}
if ( V_157 & V_450 ) {
V_6 -> V_443 ++ ;
F_5 ( V_2 , V_160 , V_450 ) ;
}
if ( V_157 & V_161 ) {
F_172 ( L_156 ) ;
V_6 -> V_443 ++ ;
F_1 ( V_2 , V_160 , & V_313 ) ;
if ( V_313 & ( V_162 |
V_163 ) ) {
F_5 ( V_2 , V_160 ,
V_162 |
V_163 ) ;
}
F_5 ( V_2 , V_160 , V_161 ) ;
}
if ( V_157 & V_451 ) {
F_172 ( L_157 ) ;
V_6 -> V_443 ++ ;
F_5 ( V_2 , V_160 , V_451 ) ;
}
if ( V_157 & V_452 ) {
F_172 ( L_158 ) ;
V_6 -> V_443 ++ ;
F_5 ( V_2 , V_160 ,
V_452 ) ;
}
V_6 -> V_441 -- ;
F_67 ( V_6 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
F_172 ( L_45 ) ;
}
static T_6 F_174 ( int V_453 , void * V_37 )
{
struct V_5 * V_6 = V_37 ;
T_1 V_157 , V_158 ;
if ( ! V_37 )
return V_454 ;
F_175 ( & V_6 -> V_68 ) ;
if ( ! ( V_6 -> V_49 & V_136 ) ) {
goto V_455;
}
F_1 ( V_6 -> V_33 , V_137 , & V_158 ) ;
F_1 ( V_6 -> V_33 , V_160 , & V_157 ) ;
if ( V_157 == 0xFFFFFFFF ) {
F_27 (KERN_WARNING DRV_NAME L_159 ) ;
goto V_455;
}
V_157 &= V_138 ;
if ( ! ( V_157 & V_158 ) ) {
goto V_455;
}
F_68 ( V_6 ) ;
F_176 ( & V_6 -> V_456 ) ;
F_177 ( & V_6 -> V_68 ) ;
return V_457 ;
V_455:
F_177 ( & V_6 -> V_68 ) ;
return V_454 ;
}
static T_7 F_178 ( struct V_458 * V_408 ,
struct V_1 * V_2 , int V_459 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
unsigned long V_62 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( ! ( V_6 -> V_49 & V_166 ) ) {
F_31 ( L_160 ) ;
V_6 -> V_33 -> V_326 . V_460 ++ ;
F_38 ( V_2 ) ;
goto V_71;
}
if ( F_44 ( & V_6 -> V_409 ) )
goto V_71;
V_59 = V_6 -> V_409 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
V_61 -> V_81 . V_407 . V_408 = V_408 ;
F_162 ( L_161 , V_408 -> V_424 [ 0 ] -> V_14 ) ;
F_33 ( V_461 , V_408 -> V_424 [ 0 ] -> V_37 , V_408 -> V_424 [ 0 ] -> V_14 ) ;
V_61 -> V_79 = V_80 ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_410 ) ;
F_48 ( V_59 , & V_6 -> V_420 ) ;
F_49 ( & V_6 -> V_423 ) ;
F_51 ( V_6 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
return V_462 ;
V_71:
F_38 ( V_2 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
return V_463 ;
}
static int F_179 ( struct V_5 * V_6 )
{
int V_19 , V_40 , V_63 = - V_31 ;
void * V_464 ;
T_8 V_465 ;
V_6 -> V_466 =
F_132 ( V_467 * sizeof( struct V_60 ) ,
V_238 ) ;
if ( ! V_6 -> V_466 )
return - V_239 ;
for ( V_19 = 0 ; V_19 < V_467 ; V_19 ++ ) {
V_464 = F_180 ( V_6 -> V_259 ,
sizeof( struct V_302 ) ,
& V_465 ) ;
if ( ! V_464 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_162
L_163 , priv->net_dev->name) ;
V_63 = - V_239 ;
break;
}
V_6 -> V_466 [ V_19 ] . type = V_395 ;
V_6 -> V_466 [ V_19 ] . V_81 . V_82 . V_57 =
(struct V_302 * ) V_464 ;
V_6 -> V_466 [ V_19 ] . V_81 . V_82 . V_414 = V_465 ;
}
if ( V_19 == V_467 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_19 ; V_40 ++ ) {
F_181 ( V_6 -> V_259 ,
sizeof( struct V_302 ) ,
V_6 -> V_466 [ V_40 ] . V_81 . V_82 . V_57 ,
V_6 -> V_466 [ V_40 ] . V_81 . V_82 .
V_414 ) ;
}
F_130 ( V_6 -> V_466 ) ;
V_6 -> V_466 = NULL ;
return V_63 ;
}
static int F_182 ( struct V_5 * V_6 )
{
int V_19 ;
F_183 ( & V_6 -> V_75 ) ;
F_183 ( & V_6 -> V_91 ) ;
for ( V_19 = 0 ; V_19 < V_467 ; V_19 ++ )
F_48 ( & V_6 -> V_466 [ V_19 ] . V_78 , & V_6 -> V_75 ) ;
F_166 ( & V_6 -> V_90 , V_19 ) ;
return 0 ;
}
static void F_184 ( struct V_5 * V_6 )
{
int V_19 ;
if ( ! V_6 -> V_466 )
return;
for ( V_19 = 0 ; V_19 < V_467 ; V_19 ++ ) {
F_181 ( V_6 -> V_259 ,
sizeof( struct V_302 ) ,
V_6 -> V_466 [ V_19 ] . V_81 . V_82 . V_57 ,
V_6 -> V_466 [ V_19 ] . V_81 . V_82 .
V_414 ) ;
}
F_130 ( V_6 -> V_466 ) ;
V_6 -> V_466 = NULL ;
}
static T_9 F_185 ( struct V_468 * V_315 , struct V_469 * V_470 ,
char * V_15 )
{
struct V_259 * V_259 = F_186 ( V_315 ) ;
char * V_39 = V_15 ;
int V_19 , V_40 ;
T_1 V_4 ;
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ ) {
V_39 += sprintf ( V_39 , L_164 , V_19 * 16 ) ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 += 4 ) {
F_187 ( V_259 , V_19 * 16 + V_40 , & V_4 ) ;
V_39 += sprintf ( V_39 , L_165 , V_4 ) ;
}
V_39 += sprintf ( V_39 , L_166 ) ;
}
return V_39 - V_15 ;
}
static T_9 F_188 ( struct V_468 * V_315 , struct V_469 * V_470 ,
char * V_15 )
{
struct V_5 * V_465 = F_189 ( V_315 ) ;
return sprintf ( V_15 , L_167 , ( int ) V_465 -> V_187 ) ;
}
static T_9 F_190 ( struct V_468 * V_315 , struct V_469 * V_470 ,
char * V_15 )
{
struct V_5 * V_465 = F_189 ( V_315 ) ;
return sprintf ( V_15 , L_167 , ( int ) V_465 -> V_49 ) ;
}
static T_9 F_191 ( struct V_468 * V_315 , struct V_469 * V_470 ,
char * V_15 )
{
struct V_5 * V_465 = F_189 ( V_315 ) ;
return sprintf ( V_15 , L_167 , ( int ) V_465 -> V_471 ) ;
}
static T_9 F_192 ( struct V_468 * V_315 , struct V_469 * V_470 ,
char * V_15 )
{
int V_19 ;
struct V_5 * V_6 = F_189 ( V_315 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
char * V_39 = V_15 ;
T_1 V_4 = 0 ;
V_39 += sprintf ( V_39 , L_168 , L_169 ) ;
for ( V_19 = 0 ; V_19 < F_104 ( V_472 ) ; V_19 ++ ) {
F_1 ( V_2 , V_472 [ V_19 ] . V_8 , & V_4 ) ;
V_39 += sprintf ( V_39 , L_170 ,
V_472 [ V_19 ] . V_51 , V_472 [ V_19 ] . V_8 , V_4 ) ;
}
return V_39 - V_15 ;
}
static T_9 F_193 ( struct V_468 * V_315 , struct V_469 * V_470 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_315 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
char * V_39 = V_15 ;
int V_19 ;
V_39 += sprintf ( V_39 , L_168 , L_171 ) ;
for ( V_19 = 0 ; V_19 < F_104 ( V_473 ) ; V_19 ++ ) {
T_3 V_474 ;
T_2 V_475 ;
T_1 V_476 ;
switch ( V_473 [ V_19 ] . V_477 ) {
case 1 :
F_19 ( V_2 , V_473 [ V_19 ] . V_8 , & V_474 ) ;
V_39 += sprintf ( V_39 , L_172 ,
V_473 [ V_19 ] . V_51 , V_473 [ V_19 ] . V_8 ,
V_474 ) ;
break;
case 2 :
F_17 ( V_2 , V_473 [ V_19 ] . V_8 , & V_475 ) ;
V_39 += sprintf ( V_39 , L_173 ,
V_473 [ V_19 ] . V_51 , V_473 [ V_19 ] . V_8 ,
V_475 ) ;
break;
case 4 :
F_15 ( V_2 , V_473 [ V_19 ] . V_8 , & V_476 ) ;
V_39 += sprintf ( V_39 , L_170 ,
V_473 [ V_19 ] . V_51 , V_473 [ V_19 ] . V_8 ,
V_476 ) ;
break;
}
}
return V_39 - V_15 ;
}
static T_9 F_194 ( struct V_468 * V_315 , struct V_469 * V_470 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_315 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
static unsigned long V_478 = 0 ;
int V_14 = 0 ;
T_1 V_479 [ 4 ] ;
int V_19 ;
char line [ 81 ] ;
if ( V_478 >= 0x30000 )
V_478 = 0 ;
while ( V_14 < V_480 - 128 && V_478 < 0x30000 ) {
if ( V_6 -> V_309 [ 0 ] )
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ )
V_479 [ V_19 ] =
* ( T_1 * ) F_134 ( V_478 + V_19 * 4 ) ;
else
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ )
F_15 ( V_2 , V_478 + V_19 * 4 , & V_479 [ V_19 ] ) ;
if ( V_6 -> V_481 )
V_14 += sprintf ( V_15 + V_14 ,
L_174
L_174
L_174
L_174 ,
( ( T_3 * ) V_479 ) [ 0x0 ] ,
( ( T_3 * ) V_479 ) [ 0x1 ] ,
( ( T_3 * ) V_479 ) [ 0x2 ] ,
( ( T_3 * ) V_479 ) [ 0x3 ] ,
( ( T_3 * ) V_479 ) [ 0x4 ] ,
( ( T_3 * ) V_479 ) [ 0x5 ] ,
( ( T_3 * ) V_479 ) [ 0x6 ] ,
( ( T_3 * ) V_479 ) [ 0x7 ] ,
( ( T_3 * ) V_479 ) [ 0x8 ] ,
( ( T_3 * ) V_479 ) [ 0x9 ] ,
( ( T_3 * ) V_479 ) [ 0xa ] ,
( ( T_3 * ) V_479 ) [ 0xb ] ,
( ( T_3 * ) V_479 ) [ 0xc ] ,
( ( T_3 * ) V_479 ) [ 0xd ] ,
( ( T_3 * ) V_479 ) [ 0xe ] ,
( ( T_3 * ) V_479 ) [ 0xf ] ) ;
else
V_14 += sprintf ( V_15 + V_14 , L_19 ,
F_32 ( line , sizeof( line ) ,
( T_3 * ) V_479 , 16 , V_478 ) ) ;
V_478 += 16 ;
}
return V_14 ;
}
static T_9 F_195 ( struct V_468 * V_315 , struct V_469 * V_470 ,
const char * V_15 , T_4 V_36 )
{
struct V_5 * V_6 = F_189 ( V_315 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
const char * V_465 = V_15 ;
( void ) V_2 ;
if ( V_36 < 1 )
return V_36 ;
if ( V_465 [ 0 ] == '1' ||
( V_36 >= 2 && tolower ( V_465 [ 0 ] ) == 'o' && tolower ( V_465 [ 1 ] ) == 'n' ) ) {
F_31 ( L_175 ,
V_2 -> V_51 ) ;
V_6 -> V_481 = 1 ;
} else if ( V_465 [ 0 ] == '0' || ( V_36 >= 2 && tolower ( V_465 [ 0 ] ) == 'o' &&
tolower ( V_465 [ 1 ] ) == 'f' ) ) {
F_31 ( L_176 ,
V_2 -> V_51 ) ;
V_6 -> V_481 = 0 ;
} else if ( tolower ( V_465 [ 0 ] ) == 'r' ) {
F_31 ( L_177 , V_2 -> V_51 ) ;
F_129 ( V_6 ) ;
} else
F_31 ( L_178
L_179 , V_2 -> V_51 ) ;
return V_36 ;
}
static T_9 F_196 ( struct V_468 * V_315 , struct V_469 * V_470 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_315 ) ;
T_1 V_4 = 0 ;
int V_14 = 0 ;
T_1 V_482 ;
static int V_478 = 0 ;
if ( V_6 -> V_49 & V_483 )
return 0 ;
if ( V_478 >= F_104 ( V_484 ) )
V_478 = 0 ;
while ( V_14 < V_480 - 128 && V_478 < F_104 ( V_484 ) ) {
V_482 = sizeof( T_1 ) ;
if ( F_26 ( V_6 , V_484 [ V_478 ] . V_394 , & V_4 ,
& V_482 ) )
V_14 += sprintf ( V_15 + V_14 , L_180 ,
V_484 [ V_478 ] . V_394 ,
V_484 [ V_478 ] . V_485 ) ;
else
V_14 += sprintf ( V_15 + V_14 , L_181 ,
V_484 [ V_478 ] . V_394 , V_4 ,
V_484 [ V_478 ] . V_485 ) ;
V_478 ++ ;
}
return V_14 ;
}
static T_9 F_197 ( struct V_468 * V_315 , struct V_469 * V_470 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_315 ) ;
char * V_39 = V_15 ;
V_39 += sprintf ( V_39 , L_182 ,
V_6 -> V_442 , V_6 -> V_448 ,
V_6 -> V_446 , V_6 -> V_443 ) ;
V_39 += sprintf ( V_39 , L_183 , V_6 -> V_262 ) ;
V_39 += sprintf ( V_39 , L_184 , V_6 -> V_486 ) ;
#ifdef F_123
V_39 += sprintf ( V_39 , L_185 ,
V_6 -> V_309 [ 0 ] ? L_186 : L_187 ) ;
#endif
return V_39 - V_15 ;
}
static int F_198 ( struct V_5 * V_6 , T_1 V_312 )
{
int V_63 ;
if ( V_312 == V_6 -> V_150 -> V_198 )
return 0 ;
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
switch ( V_312 ) {
case V_425 :
V_6 -> V_33 -> type = V_220 ;
break;
case V_430 :
V_6 -> V_33 -> type = V_220 ;
break;
#ifdef F_155
case V_199 :
V_6 -> V_487 = V_6 -> V_150 -> V_198 ;
V_6 -> V_33 -> type = V_488 ;
break;
#endif
}
V_6 -> V_150 -> V_198 = V_312 ;
#ifdef F_61
V_120 . V_121 = 0 ;
#endif
F_27 ( V_213 L_189 , V_6 -> V_33 -> V_51 ) ;
V_6 -> V_47 = 0 ;
F_35 ( V_6 ) ;
return 0 ;
}
static T_9 F_199 ( struct V_468 * V_315 , struct V_469 * V_470 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_315 ) ;
int V_14 = 0 ;
#define F_200 ( T_10 , T_11 ) len += sprintf(buf + len, # x ": %" y "\n", priv-> x)
if ( V_6 -> V_49 & V_166 )
V_14 += sprintf ( V_15 + V_14 , L_190 ,
F_36 () - V_6 -> V_282 ) ;
else
V_14 += sprintf ( V_15 + V_14 , L_191 ) ;
F_200 ( V_150 -> V_489 . V_490 [ V_6 -> V_150 -> V_489 . V_491 ] , L_192 ) ;
F_200 ( V_49 , L_193 ) ;
F_200 ( V_187 , L_193 ) ;
F_200 ( V_471 , L_193 ) ;
V_14 +=
sprintf ( V_15 + V_14 , L_194 ,
( unsigned long ) V_6 -> V_492 ) ;
F_200 ( V_69 , L_195 ) ;
F_200 ( V_181 , L_195 ) ;
F_200 ( V_214 , L_195 ) ;
F_200 ( V_76 , L_195 ) ;
F_200 ( V_423 . V_147 , L_195 ) ;
F_200 ( V_423 . V_493 , L_195 ) ;
F_200 ( V_410 . V_147 , L_195 ) ;
F_200 ( V_410 . V_494 , L_195 ) ;
F_200 ( V_90 . V_147 , L_195 ) ;
F_200 ( V_90 . V_494 , L_195 ) ;
F_200 ( V_92 . V_147 , L_195 ) ;
F_200 ( V_92 . V_493 , L_195 ) ;
F_200 ( V_401 . V_147 , L_195 ) ;
F_200 ( V_401 . V_493 , L_195 ) ;
F_200 ( V_413 . V_147 , L_195 ) ;
F_200 ( V_413 . V_494 , L_195 ) ;
F_200 ( V_150 -> V_296 , L_195 ) ;
F_200 ( V_47 , L_195 ) ;
return V_14 ;
}
static T_9 F_201 ( struct V_468 * V_315 , struct V_469 * V_470 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_315 ) ;
char V_267 [ V_268 + 1 ] ;
T_3 V_272 [ V_229 ] ;
T_1 V_270 = 0 ;
char * V_39 = V_15 ;
unsigned int V_284 ;
int V_265 ;
if ( V_6 -> V_49 & V_483 )
return 0 ;
memset ( V_267 , 0 , sizeof( V_267 ) ) ;
memset ( V_272 , 0 , sizeof( V_272 ) ) ;
V_284 = V_268 ;
V_265 = F_26 ( V_6 , V_273 , V_267 , & V_284 ) ;
if ( V_265 )
F_31 ( L_46 ,
__LINE__ ) ;
V_284 = sizeof( V_272 ) ;
V_265 = F_26 ( V_6 , V_276 ,
V_272 , & V_284 ) ;
if ( V_265 )
F_31 ( L_46 ,
__LINE__ ) ;
V_284 = sizeof( T_1 ) ;
V_265 = F_26 ( V_6 , V_275 , & V_270 , & V_284 ) ;
if ( V_265 )
F_31 ( L_46 ,
__LINE__ ) ;
V_39 += sprintf ( V_39 , L_196 , V_267 ) ;
V_39 += sprintf ( V_39 , L_197 , V_272 ) ;
V_39 += sprintf ( V_39 , L_198 , V_270 ) ;
return V_39 - V_15 ;
}
static T_9 F_202 ( struct V_495 * V_315 , char * V_15 )
{
return sprintf ( V_15 , L_199 , V_44 ) ;
}
static T_9 F_203 ( struct V_495 * V_315 ,
const char * V_15 , T_4 V_36 )
{
T_1 V_4 ;
int V_265 ;
V_265 = F_204 ( V_15 , 0 , & V_4 ) ;
if ( V_265 )
F_31 ( L_200 , V_15 ) ;
else
V_44 = V_4 ;
return F_205 ( V_15 , V_36 ) ;
}
static T_9 F_206 ( struct V_468 * V_315 ,
struct V_469 * V_470 , char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_315 ) ;
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
static T_9 F_207 ( struct V_468 * V_315 ,
struct V_469 * V_470 , const char * V_15 ,
T_4 V_36 )
{
struct V_5 * V_6 = F_189 ( V_315 ) ;
F_35 ( V_6 ) ;
return V_36 ;
}
static T_9 F_208 ( struct V_468 * V_315 , struct V_469 * V_470 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_315 ) ;
return sprintf ( V_15 , L_203 , V_6 -> V_150 -> V_496 ) ;
}
static T_9 F_209 ( struct V_468 * V_315 , struct V_469 * V_470 ,
const char * V_15 , T_4 V_36 )
{
struct V_5 * V_6 = F_189 ( V_315 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
unsigned long V_4 ;
int V_265 ;
( void ) V_2 ;
F_31 ( L_42 ) ;
V_265 = F_210 ( V_15 , 0 , & V_4 ) ;
if ( V_265 ) {
F_31 ( L_204 , V_2 -> V_51 ) ;
} else {
V_6 -> V_150 -> V_496 = V_4 ;
F_31 ( L_205 , V_6 -> V_150 -> V_496 ) ;
}
F_31 ( L_45 ) ;
return F_205 ( V_15 , V_36 ) ;
}
static T_9 F_211 ( struct V_468 * V_315 , struct V_469 * V_470 ,
char * V_15 )
{
struct V_5 * V_6 = F_189 ( V_315 ) ;
int V_4 = ( ( V_6 -> V_49 & V_205 ) ? 0x1 : 0x0 ) |
( F_71 ( V_6 ) ? 0x2 : 0x0 ) ;
return sprintf ( V_15 , L_206 , V_4 ) ;
}
static int F_212 ( struct V_5 * V_6 , int V_497 )
{
if ( ( V_497 ? 1 : 0 ) ==
( V_6 -> V_49 & V_205 ? 1 : 0 ) )
return 0 ;
F_213 ( L_207 ,
V_497 ? L_208 : L_209 ) ;
F_84 ( & V_6 -> V_264 ) ;
if ( V_497 ) {
V_6 -> V_49 |= V_205 ;
F_99 ( V_6 ) ;
} else {
V_6 -> V_49 &= ~ V_205 ;
if ( F_71 ( V_6 ) ) {
F_213 ( L_210
L_211 ) ;
V_6 -> V_214 = 0 ;
F_116 ( V_293 , & V_6 -> V_215 ,
F_97 ( V_53 ) ) ;
} else
F_35 ( V_6 ) ;
}
F_85 ( & V_6 -> V_264 ) ;
return 1 ;
}
static T_9 F_214 ( struct V_468 * V_315 , struct V_469 * V_470 ,
const char * V_15 , T_4 V_36 )
{
struct V_5 * V_6 = F_189 ( V_315 ) ;
F_212 ( V_6 , V_15 [ 0 ] == '1' ) ;
return V_36 ;
}
static int F_215 ( struct V_5 * V_6 , int V_379 )
{
struct V_373 * V_498 = & V_6 -> V_320 ;
F_31 ( L_42 ) ;
V_498 -> V_477 = V_379 * sizeof( struct V_319 ) ;
V_498 -> V_321 = F_180 ( V_6 -> V_259 , V_498 -> V_477 , & V_498 -> V_402 ) ;
if ( ! V_498 -> V_321 ) {
F_153 ( L_212 ) ;
return - V_239 ;
}
F_31 ( L_45 ) ;
return 0 ;
}
static void F_216 ( struct V_5 * V_6 )
{
F_31 ( L_42 ) ;
if ( V_6 -> V_320 . V_321 ) {
F_181 ( V_6 -> V_259 , V_6 -> V_320 . V_477 ,
V_6 -> V_320 . V_321 ,
V_6 -> V_320 . V_402 ) ;
V_6 -> V_320 . V_321 = NULL ;
}
F_31 ( L_45 ) ;
}
static int F_217 ( struct V_5 * V_6 ,
struct V_371 * V_498 , int V_379 )
{
F_31 ( L_42 ) ;
memset ( V_498 , 0 , sizeof( struct V_371 ) ) ;
V_498 -> V_379 = V_379 ;
V_498 -> V_477 = V_379 * sizeof( struct V_388 ) ;
V_498 -> V_321 = F_180 ( V_6 -> V_259 , V_498 -> V_477 , & V_498 -> V_402 ) ;
if ( ! V_498 -> V_321 ) {
F_31
( L_213 ) ;
return - V_239 ;
}
F_31 ( L_45 ) ;
return 0 ;
}
static void F_218 ( struct V_5 * V_6 , struct V_371 * V_498 )
{
F_31 ( L_42 ) ;
if ( ! V_498 )
return;
if ( V_498 -> V_321 ) {
F_181 ( V_6 -> V_259 , V_498 -> V_477 , V_498 -> V_321 , V_498 -> V_402 ) ;
V_498 -> V_321 = NULL ;
}
F_31 ( L_45 ) ;
}
static void F_219 ( struct V_5 * V_6 ,
struct V_371 * V_498 , T_1 V_499 , T_1 V_477 ,
T_1 V_109 , T_1 V_375 )
{
F_31 ( L_42 ) ;
F_31 ( L_214 , V_498 -> V_321 ,
( T_1 ) V_498 -> V_402 ) ;
F_5 ( V_6 -> V_33 , V_499 , V_498 -> V_402 ) ;
F_5 ( V_6 -> V_33 , V_477 , V_498 -> V_379 ) ;
F_5 ( V_6 -> V_33 , V_109 , V_498 -> V_396 ) ;
F_5 ( V_6 -> V_33 , V_375 , V_498 -> V_77 ) ;
F_31 ( L_45 ) ;
}
static void F_220 ( struct V_5 * V_6 )
{
V_6 -> V_214 = 1 ;
V_6 -> V_181 = 1 ;
F_221 ( & V_6 -> V_52 ) ;
F_221 ( & V_6 -> V_292 ) ;
F_221 ( & V_6 -> V_283 ) ;
F_221 ( & V_6 -> V_182 ) ;
F_221 ( & V_6 -> V_215 ) ;
F_221 ( & V_6 -> V_294 ) ;
}
static int F_222 ( struct V_5 * V_6 )
{
int V_19 , V_40 , V_63 = - V_31 ;
void * V_464 ;
T_8 V_465 ;
F_31 ( L_42 ) ;
V_63 = F_217 ( V_6 , & V_6 -> V_387 , V_500 ) ;
if ( V_63 ) {
F_62 ( L_215 ,
V_6 -> V_33 -> V_51 ) ;
return V_63 ;
}
V_6 -> V_501 = F_223 ( V_502 ,
sizeof( struct V_60 ) ,
V_310 ) ;
if ( ! V_6 -> V_501 ) {
F_218 ( V_6 , & V_6 -> V_387 ) ;
return - V_239 ;
}
for ( V_19 = 0 ; V_19 < V_502 ; V_19 ++ ) {
V_464 = F_224 ( V_6 -> V_259 ,
sizeof( struct V_417 ) ,
& V_465 ) ;
if ( ! V_464 ) {
F_27 (KERN_ERR DRV_NAME
L_216 L_163 ,
priv->net_dev->name) ;
V_63 = - V_239 ;
break;
}
V_6 -> V_501 [ V_19 ] . type = V_397 ;
V_6 -> V_501 [ V_19 ] . V_81 . V_407 . V_37 =
(struct V_417 * ) V_464 ;
V_6 -> V_501 [ V_19 ] . V_81 . V_407 . V_438 = V_465 ;
V_6 -> V_501 [ V_19 ] . V_81 . V_407 . V_408 = NULL ;
}
if ( V_19 == V_502 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_19 ; V_40 ++ ) {
F_181 ( V_6 -> V_259 ,
sizeof( struct V_417 ) ,
V_6 -> V_501 [ V_40 ] . V_81 . V_407 . V_37 ,
V_6 -> V_501 [ V_40 ] . V_81 . V_407 .
V_438 ) ;
}
F_130 ( V_6 -> V_501 ) ;
V_6 -> V_501 = NULL ;
return V_63 ;
}
static void F_225 ( struct V_5 * V_6 )
{
int V_19 ;
F_31 ( L_42 ) ;
F_183 ( & V_6 -> V_393 ) ;
F_226 ( & V_6 -> V_401 ) ;
F_183 ( & V_6 -> V_420 ) ;
F_183 ( & V_6 -> V_409 ) ;
F_226 ( & V_6 -> V_423 ) ;
F_226 ( & V_6 -> V_410 ) ;
for ( V_19 = 0 ; V_19 < V_502 ; V_19 ++ ) {
if ( V_6 -> V_501 [ V_19 ] . V_81 . V_407 . V_408 ) {
F_163 ( V_6 -> V_501 [ V_19 ] . V_81 . V_407 .
V_408 ) ;
V_6 -> V_501 [ V_19 ] . V_81 . V_407 . V_408 = NULL ;
}
F_48 ( & V_6 -> V_501 [ V_19 ] . V_78 , & V_6 -> V_409 ) ;
}
F_166 ( & V_6 -> V_410 , V_19 ) ;
V_6 -> V_387 . V_396 = 0 ;
V_6 -> V_387 . V_412 = V_6 -> V_387 . V_379 ;
V_6 -> V_387 . V_77 = 0 ;
F_226 ( & V_6 -> V_413 ) ;
F_166 ( & V_6 -> V_413 , V_6 -> V_387 . V_412 ) ;
F_219 ( V_6 , & V_6 -> V_387 ,
V_503 ,
V_504 ,
V_399 ,
V_400 ) ;
F_31 ( L_45 ) ;
}
static void F_227 ( struct V_5 * V_6 )
{
int V_19 ;
F_31 ( L_42 ) ;
F_218 ( V_6 , & V_6 -> V_387 ) ;
if ( ! V_6 -> V_501 )
return;
for ( V_19 = 0 ; V_19 < V_502 ; V_19 ++ ) {
if ( V_6 -> V_501 [ V_19 ] . V_81 . V_407 . V_408 ) {
F_163 ( V_6 -> V_501 [ V_19 ] . V_81 . V_407 .
V_408 ) ;
V_6 -> V_501 [ V_19 ] . V_81 . V_407 . V_408 = NULL ;
}
if ( V_6 -> V_501 [ V_19 ] . V_81 . V_407 . V_37 )
F_181 ( V_6 -> V_259 ,
sizeof( struct V_417 ) ,
V_6 -> V_501 [ V_19 ] . V_81 . V_407 .
V_37 ,
V_6 -> V_501 [ V_19 ] . V_81 . V_407 .
V_438 ) ;
}
F_130 ( V_6 -> V_501 ) ;
V_6 -> V_501 = NULL ;
F_31 ( L_45 ) ;
}
static int F_228 ( struct V_5 * V_6 )
{
int V_19 , V_40 , V_63 = - V_31 ;
F_31 ( L_42 ) ;
V_63 = F_217 ( V_6 , & V_6 -> V_336 , V_324 ) ;
if ( V_63 ) {
F_31 ( L_217 ) ;
return V_63 ;
}
V_63 = F_215 ( V_6 , V_324 ) ;
if ( V_63 ) {
F_31 ( L_218 ) ;
F_218 ( V_6 , & V_6 -> V_336 ) ;
return V_63 ;
}
V_6 -> V_329 = F_132 ( V_324 *
sizeof( struct V_303 ) ,
V_238 ) ;
if ( ! V_6 -> V_329 ) {
F_31 ( L_219 ) ;
F_218 ( V_6 , & V_6 -> V_336 ) ;
F_216 ( V_6 ) ;
return - V_239 ;
}
for ( V_19 = 0 ; V_19 < V_324 ; V_19 ++ ) {
struct V_303 * V_61 = & V_6 -> V_329 [ V_19 ] ;
V_63 = F_124 ( V_6 , V_61 ) ;
if ( F_139 ( V_63 ) ) {
V_63 = - V_239 ;
break;
}
V_6 -> V_336 . V_321 [ V_19 ] . V_337 = V_61 -> V_307 ;
V_6 -> V_336 . V_321 [ V_19 ] . V_403 = V_334 ;
V_6 -> V_320 . V_321 [ V_19 ] . V_355 = 0 ;
}
if ( V_19 == V_324 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_19 ; V_40 ++ ) {
F_143 ( V_6 -> V_259 , V_6 -> V_329 [ V_40 ] . V_307 ,
sizeof( struct V_303 ) ,
V_308 ) ;
F_128 ( V_6 -> V_329 [ V_40 ] . V_304 ) ;
}
F_130 ( V_6 -> V_329 ) ;
V_6 -> V_329 = NULL ;
F_218 ( V_6 , & V_6 -> V_336 ) ;
F_216 ( V_6 ) ;
return V_63 ;
}
static void F_229 ( struct V_5 * V_6 )
{
F_31 ( L_42 ) ;
V_6 -> V_336 . V_396 = 0 ;
V_6 -> V_336 . V_412 = V_6 -> V_336 . V_379 - 1 ;
V_6 -> V_336 . V_77 = V_6 -> V_336 . V_379 - 1 ;
F_226 ( & V_6 -> V_505 ) ;
F_166 ( & V_6 -> V_505 , V_6 -> V_336 . V_412 ) ;
F_219 ( V_6 , & V_6 -> V_336 ,
V_506 ,
V_507 ,
V_377 ,
V_378 ) ;
F_5 ( V_6 -> V_33 , V_508 ,
V_6 -> V_320 . V_402 ) ;
F_31 ( L_45 ) ;
}
static void F_230 ( struct V_5 * V_6 )
{
int V_19 ;
F_31 ( L_42 ) ;
F_218 ( V_6 , & V_6 -> V_336 ) ;
F_216 ( V_6 ) ;
if ( ! V_6 -> V_329 )
return;
for ( V_19 = 0 ; V_19 < V_324 ; V_19 ++ ) {
if ( V_6 -> V_329 [ V_19 ] . V_306 ) {
F_143 ( V_6 -> V_259 ,
V_6 -> V_329 [ V_19 ] . V_307 ,
sizeof( struct V_305 ) ,
V_308 ) ;
F_128 ( V_6 -> V_329 [ V_19 ] . V_304 ) ;
}
}
F_130 ( V_6 -> V_329 ) ;
V_6 -> V_329 = NULL ;
F_31 ( L_45 ) ;
}
static int F_231 ( struct V_5 * V_6 )
{
T_1 V_284 = V_229 ;
T_3 V_8 [ V_229 ] ;
int V_63 ;
V_63 = F_26 ( V_6 , V_509 , V_8 , & V_284 ) ;
if ( V_63 ) {
F_31 ( L_220 ) ;
return - V_70 ;
}
memcpy ( V_6 -> V_33 -> V_510 , V_8 , V_229 ) ;
F_31 ( L_221 , V_6 -> V_33 -> V_510 ) ;
return 0 ;
}
static int F_232 ( struct V_5 * V_6 , int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_511 ,
. V_88 = 0 ,
. V_65 = V_229
} ;
int V_63 ;
F_42 ( L_222 ) ;
F_31 ( L_42 ) ;
if ( V_6 -> V_187 & V_512 ) {
memcpy ( V_57 . V_67 , V_6 -> V_228 , V_229 ) ;
memcpy ( V_6 -> V_33 -> V_510 , V_6 -> V_228 , V_229 ) ;
} else
memcpy ( V_57 . V_67 , V_6 -> V_33 -> V_510 ,
V_229 ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
F_31 ( L_45 ) ;
return V_63 ;
}
static int F_233 ( struct V_5 * V_6 , T_1 V_513 ,
int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_514 ,
. V_88 = 0 ,
. V_65 = sizeof( T_1 )
} ;
int V_63 ;
switch ( V_513 ) {
case V_425 :
V_57 . V_67 [ 0 ] = V_515 ;
break;
case V_430 :
V_57 . V_67 [ 0 ] = V_516 ;
break;
}
F_42 ( L_223 ,
V_513 == V_516 ? L_224 : L_225 ) ;
if ( ! V_285 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_285 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_234 ( struct V_5 * V_6 , T_1 V_244 ,
int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_517 ,
. V_88 = 0 ,
. V_65 = sizeof( T_1 )
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_244 ;
F_42 ( L_226 , V_244 ) ;
if ( V_6 -> V_150 -> V_198 == V_425 )
return 0 ;
if ( ( V_244 != 0 ) &&
( ( V_244 < V_518 ) || ( V_244 > V_519 ) ) )
return - V_31 ;
if ( ! V_285 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 ) {
F_31 ( L_227 , V_244 ) ;
return V_63 ;
}
if ( V_244 )
V_6 -> V_187 |= V_520 ;
else
V_6 -> V_187 &= ~ V_520 ;
V_6 -> V_244 = V_244 ;
if ( ! V_285 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static int F_235 ( struct V_5 * V_6 , int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_521 ,
. V_88 = 0 ,
. V_65 = 12 ,
} ;
T_1 V_522 , V_14 = sizeof( T_1 ) ;
int V_63 ;
if ( ! V_285 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
if ( V_6 -> V_150 -> V_198 == V_430 )
V_57 . V_67 [ 0 ] |= V_523 ;
V_57 . V_67 [ 0 ] |= V_524 |
V_525 | V_526 ;
if ( ! ( V_6 -> V_187 & V_527 ) )
V_57 . V_67 [ 0 ] |= V_528 ;
V_63 = F_26 ( V_6 ,
V_529 ,
& V_522 , & V_14 ) ;
if ( V_63 )
V_522 = V_530 ;
V_57 . V_67 [ 1 ] = V_531 ;
V_57 . V_67 [ 2 ] = V_531 & V_522 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
#if ! F_236 ( V_532 ) && ! F_236 ( V_533 )
V_57 . V_56 = V_534 ;
V_57 . V_88 = 0 ;
V_57 . V_65 = 0 ;
F_41 ( V_6 , & V_57 ) ;
#endif
if ( ! V_285 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static int F_237 ( struct V_5 * V_6 , T_1 V_535 ,
int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_536 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_535 & V_537 ;
if ( ! V_285 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
F_41 ( V_6 , & V_57 ) ;
V_57 . V_56 = V_538 ;
F_41 ( V_6 , & V_57 ) ;
V_57 . V_56 = V_539 ;
F_41 ( V_6 , & V_57 ) ;
if ( ! V_285 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_6 -> V_540 = V_535 ;
return 0 ;
}
static int F_238 ( struct V_5 * V_6 , int V_541 )
{
struct V_56 V_57 = {
. V_56 = V_542 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_541 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
if ( V_541 == V_543 )
V_6 -> V_544 = F_239 ( V_6 -> V_544 ) ;
else
V_6 -> V_544 = V_545 | V_541 ;
#ifdef F_240
if ( V_6 -> V_513 == V_546 && V_6 -> V_547 != V_548 ) {
V_57 . V_56 = V_549 ;
V_57 . V_67 [ 0 ] = ( T_1 ) V_6 -> V_547 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
}
#endif
return 0 ;
}
static int F_241 ( struct V_5 * V_6 , T_1 V_550 )
{
struct V_56 V_57 = {
. V_56 = V_551 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
if ( V_550 & V_552 )
V_57 . V_67 [ 0 ] = V_553 ;
else
V_57 . V_67 [ 0 ] = V_550 & ~ V_552 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_554 = V_550 ;
return 0 ;
}
static int F_242 ( struct V_5 * V_6 , T_1 V_555 )
{
struct V_56 V_57 = {
. V_56 = V_556 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_555 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_557 = V_555 ;
return 0 ;
}
static int F_243 ( struct V_5 * V_6 , T_1 V_555 )
{
struct V_56 V_57 = {
. V_56 = V_558 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_555 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_559 = V_555 ;
return 0 ;
}
static int F_244 ( struct V_5 * V_6 , T_3 * V_272 ,
int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_560 ,
. V_88 = 0 ,
. V_65 = ( V_272 == NULL ) ? 0 : V_229
} ;
int V_63 ;
#ifdef F_123
if ( V_272 != NULL )
F_42 ( L_228 , V_272 ) ;
else
F_42 ( L_229 ) ;
#endif
if ( V_272 != NULL )
memcpy ( V_57 . V_67 , V_272 , V_229 ) ;
if ( ! V_285 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_285 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_245 ( struct V_5 * V_6 )
{
struct V_56 V_57 = {
. V_56 = V_561 ,
. V_88 = 0 ,
. V_65 = V_229
} ;
int V_63 ;
int V_14 ;
F_42 ( L_230 ) ;
V_14 = V_229 ;
memcpy ( V_57 . V_67 , V_6 -> V_272 , V_229 ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
return V_63 ;
}
static int F_246 ( struct V_5 * V_6 ,
struct V_562 * V_563 ,
int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_564 ,
. V_88 = 0 ,
. V_65 = sizeof( struct V_562 ) ,
} ;
int V_63 ;
F_42 ( L_231 ) ;
if ( ! V_285 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
memcpy ( V_57 . V_67 , V_563 ,
sizeof( struct V_562 ) ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_285 ) {
if ( F_83 ( V_6 ) )
V_63 = - V_70 ;
}
return V_63 ;
}
static int F_247 ( struct V_5 * V_6 ,
int V_565 ,
int V_566 ,
int V_567 ,
int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_568 ,
. V_88 = 0 ,
. V_65 = sizeof(struct V_569 )
} ;
struct V_569 * V_570 =
(struct V_569 * ) & V_57 . V_67 ;
int V_63 ;
memset ( V_570 , 0 , sizeof( * V_570 ) ) ;
V_570 -> V_565 = V_565 ;
V_570 -> V_567 = V_567 ;
switch ( V_566 ) {
default:
case V_571 :
V_570 -> V_572 = V_573 ;
break;
case V_574 :
V_570 -> V_572 = V_575 |
V_576 ;
break;
case V_577 :
V_570 -> V_572 = V_575 |
V_576 | V_578 ;
break;
case V_579 :
V_570 -> V_572 = V_575 |
V_576 | V_580 ;
break;
case V_581 :
V_570 -> V_572 = V_575 |
V_576 | V_578 | V_582 ;
break;
}
F_42
( L_232 ,
V_570 -> V_565 , V_570 -> V_572 , V_566 ) ;
V_570 -> V_583 = 0 ;
if ( ! V_285 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_285 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_248 ( struct V_5 * V_6 , T_1 V_584 )
{
struct V_56 V_57 = {
. V_56 = V_549 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 = 0 ;
T_1 V_313 = V_584 ;
if ( V_584 != V_585 )
V_313 = ( V_584 - V_586 ) * 16 /
( V_587 - V_586 ) ;
V_57 . V_67 [ 0 ] = V_313 ;
if ( V_6 -> V_150 -> V_198 == V_430 )
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_63 )
V_6 -> V_584 = V_584 ;
return 0 ;
}
static int F_249 ( struct V_5 * V_6 ,
T_1 V_588 , int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_589 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_588 ;
F_31 ( L_42 ) ;
if ( V_6 -> V_150 -> V_198 == V_430 ) {
if ( ! V_285 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
F_41 ( V_6 , & V_57 ) ;
if ( ! V_285 ) {
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
F_225 ( V_6 ) ;
F_229 ( V_6 ) ;
F_182 ( V_6 ) ;
}
static void F_250 ( struct V_5 * V_6 )
{
F_227 ( V_6 ) ;
F_230 ( V_6 ) ;
F_184 ( V_6 ) ;
}
static int F_251 ( struct V_5 * V_6 )
{
if ( F_222 ( V_6 ) ||
F_228 ( V_6 ) || F_179 ( V_6 ) )
goto V_123;
return 0 ;
V_123:
F_227 ( V_6 ) ;
F_230 ( V_6 ) ;
F_184 ( V_6 ) ;
return - V_239 ;
}
static int F_252 ( struct V_5 * V_6 , T_1 V_62 ,
int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_590 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_62 ;
F_42 ( L_233 , V_62 ) ;
if ( ! V_285 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_285 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_253 ( struct V_5 * V_6 ,
int V_591 , char * V_592 , int V_14 , int V_285 )
{
int V_593 = V_14 ? ( V_14 <= 5 ? 5 : 13 ) : 0 ;
struct V_56 V_57 = {
. V_56 = V_594 ,
. V_88 = 0 ,
. V_65 = sizeof( struct V_595 ) ,
} ;
struct V_595 * V_596 = ( void * ) V_57 . V_67 ;
int V_63 ;
F_42 ( L_234 ,
V_591 , V_593 , V_14 ) ;
V_596 -> V_591 = V_591 ;
V_596 -> V_14 = V_593 ;
if ( V_593 ) {
memcpy ( V_596 -> V_592 , V_592 , V_14 ) ;
memset ( V_596 -> V_592 + V_14 , 0 , V_593 - V_14 ) ;
}
if ( V_593 == 0 )
F_254 ( L_235 ,
V_6 -> V_33 -> V_51 , V_596 -> V_591 ) ;
else if ( V_593 == 5 )
F_254 ( L_236 V_597 L_166 ,
V_6 -> V_33 -> V_51 , V_596 -> V_591 , V_596 -> V_14 ,
F_255 ( V_596 -> V_592 ) ) ;
else
F_254 ( L_236 V_598
L_166 ,
V_6 -> V_33 -> V_51 , V_596 -> V_591 , V_596 -> V_14 ,
F_256 ( V_596 -> V_592 ) ) ;
if ( ! V_285 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_285 ) {
int V_599 = F_83 ( V_6 ) ;
if ( V_63 == 0 )
V_63 = V_599 ;
}
return V_63 ;
}
static int F_257 ( struct V_5 * V_6 ,
int V_591 , int V_285 )
{
struct V_56 V_57 = {
. V_56 = V_600 ,
. V_88 = 0 ,
. V_65 = 4 ,
. V_67 = { V_591 } ,
} ;
int V_63 ;
F_42 ( L_237 , V_591 ) ;
if ( V_591 < 0 || V_591 > 3 )
return - V_31 ;
if ( ! V_285 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_285 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_258 ( struct V_5 * V_6 , int V_285 )
{
int V_19 , V_63 , V_565 , V_601 , V_602 ;
if ( ! ( V_6 -> V_49 & V_72 ) )
return 0 ;
if ( ! V_285 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
if ( ! V_6 -> V_150 -> V_190 . V_192 ) {
V_63 =
F_247 ( V_6 , V_603 ,
V_571 , 0 , 1 ) ;
} else {
V_565 = V_603 ;
if ( V_6 -> V_150 -> V_190 . V_62 & V_604 ) {
if ( V_6 -> V_150 -> V_190 . V_565 == V_605 )
V_565 = V_606 ;
else if ( V_6 -> V_150 -> V_190 . V_565 == V_607 )
V_565 = V_608 ;
}
V_601 = V_571 ;
if ( V_6 -> V_150 -> V_190 . V_62 & V_609 )
V_601 = V_6 -> V_150 -> V_190 . V_43 ;
V_602 = 0 ;
if ( V_6 -> V_150 -> V_190 . V_62 & V_610 )
V_602 = V_6 -> V_150 -> V_190 . V_611 ;
V_63 =
F_247 ( V_6 , V_565 , V_601 ,
V_602 , 1 ) ;
}
if ( V_63 )
goto exit;
if ( V_6 -> V_150 -> V_190 . V_192 ) {
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
if ( ! ( V_6 -> V_150 -> V_190 . V_62 & ( 1 << V_19 ) ) ) {
memset ( V_6 -> V_150 -> V_190 . V_612 [ V_19 ] , 0 , V_613 ) ;
V_6 -> V_150 -> V_190 . V_614 [ V_19 ] = 0 ;
} else {
V_63 = F_253 ( V_6 , V_19 ,
V_6 -> V_150 -> V_190 . V_612 [ V_19 ] ,
V_6 -> V_150 -> V_190 .
V_614 [ V_19 ] , 1 ) ;
if ( V_63 )
goto exit;
}
}
F_257 ( V_6 , V_6 -> V_150 -> V_489 . V_491 , 1 ) ;
}
V_63 =
F_252 ( V_6 ,
V_6 -> V_150 -> V_190 .
V_192 ? V_615 : 0 , 1 ) ;
if ( V_63 )
goto exit;
V_6 -> V_49 &= ~ V_263 ;
exit:
if ( ! V_285 )
F_83 ( V_6 ) ;
return V_63 ;
}
static void F_259 ( struct V_260 * V_261 )
{
struct V_5 * V_6 =
F_108 ( V_261 , struct V_5 , V_292 . V_261 ) ;
if ( ! ( V_6 -> V_49 & V_166 ) &&
V_6 -> V_49 & V_263 )
F_258 ( V_6 , 0 ) ;
}
static void F_260 ( struct V_1 * V_2 ,
struct V_616 * V_190 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_19 , V_617 = 0 ;
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) )
goto V_619;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
if ( V_190 -> V_62 & ( 1 << V_19 ) ) {
V_6 -> V_150 -> V_190 . V_614 [ V_19 ] = V_190 -> V_614 [ V_19 ] ;
if ( V_190 -> V_614 [ V_19 ] == 0 )
V_6 -> V_150 -> V_190 . V_62 &= ~ ( 1 << V_19 ) ;
else
memcpy ( V_6 -> V_150 -> V_190 . V_612 [ V_19 ] , V_190 -> V_612 [ V_19 ] ,
V_190 -> V_614 [ V_19 ] ) ;
if ( V_190 -> V_43 == V_574 ) {
V_6 -> V_150 -> V_190 . V_62 |= ( 1 << V_19 ) ;
V_6 -> V_49 |= V_263 ;
} else
V_6 -> V_150 -> V_190 . V_62 &= ~ ( 1 << V_19 ) ;
}
}
if ( ( V_190 -> V_62 & V_620 ) &&
V_6 -> V_150 -> V_190 . V_621 != V_190 -> V_621 ) {
if ( V_190 -> V_621 <= 3 ) {
V_6 -> V_150 -> V_190 . V_621 = V_190 -> V_621 ;
V_6 -> V_150 -> V_190 . V_62 |= V_620 ;
} else
V_6 -> V_150 -> V_190 . V_62 &= ~ V_620 ;
V_6 -> V_49 |= V_263 ;
}
if ( ( V_190 -> V_62 & V_604 ) &&
( V_6 -> V_150 -> V_190 . V_565 != V_190 -> V_565 ) ) {
V_6 -> V_150 -> V_190 . V_565 = V_190 -> V_565 ;
V_6 -> V_150 -> V_190 . V_62 |= V_604 ;
V_6 -> V_49 |= V_263 ;
}
if ( V_190 -> V_62 & V_191 && V_6 -> V_150 -> V_190 . V_192 != V_190 -> V_192 ) {
V_6 -> V_150 -> V_190 . V_62 |= V_191 ;
V_6 -> V_150 -> V_190 . V_192 = V_190 -> V_192 ;
V_6 -> V_49 |= V_263 ;
V_617 = 1 ;
}
if ( V_190 -> V_62 & V_622 )
V_6 -> V_150 -> V_190 . V_623 = V_190 -> V_623 ;
if ( V_190 -> V_62 & V_609 && V_6 -> V_150 -> V_190 . V_43 != V_190 -> V_43 ) {
V_6 -> V_150 -> V_190 . V_43 = V_190 -> V_43 ;
V_6 -> V_150 -> V_190 . V_62 |= V_609 ;
V_6 -> V_49 |= V_263 ;
}
F_254 ( L_238 ,
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
V_619:
F_85 ( & V_6 -> V_264 ) ;
}
static int F_98 ( struct V_5 * V_6 )
{
int V_63 ;
int V_285 = 1 ;
T_3 * V_272 ;
F_31 ( L_42 ) ;
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
#ifdef F_155
if ( V_6 -> V_150 -> V_198 == V_199 ) {
V_63 = F_234 ( V_6 , V_6 -> V_244 , V_285 ) ;
if ( V_63 )
return V_63 ;
F_31 ( L_45 ) ;
return 0 ;
}
#endif
V_63 = F_231 ( V_6 ) ;
if ( V_63 )
return - V_70 ;
V_63 = F_232 ( V_6 , V_285 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_233 ( V_6 , V_6 -> V_150 -> V_198 , V_285 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_150 -> V_198 == V_430 ) {
V_63 = F_234 ( V_6 , V_6 -> V_244 , V_285 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_235 ( V_6 , V_285 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_237 ( V_6 , V_6 -> V_540 , V_285 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_238 ( V_6 , V_543 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_241 ( V_6 , V_6 -> V_554 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_187 & V_624 )
V_272 = V_6 -> V_272 ;
else
V_272 = NULL ;
V_63 = F_244 ( V_6 , V_272 , V_285 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_187 & V_281 )
V_63 = F_111 ( V_6 , V_6 -> V_267 , V_6 -> V_266 ,
V_285 ) ;
else
V_63 = F_111 ( V_6 , NULL , 0 , V_285 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_258 ( V_6 , V_285 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_150 -> V_198 == V_430 ) {
V_63 =
F_249 ( V_6 ,
V_6 -> V_625 ,
V_285 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_248 ( V_6 , V_6 -> V_584 ) ;
if ( V_63 )
return V_63 ;
}
F_31 ( L_45 ) ;
return 0 ;
}
static int F_261 ( struct V_1 * V_2 , void * V_465 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_626 * V_8 = V_465 ;
int V_63 = 0 ;
if ( ! F_262 ( V_8 -> V_627 ) )
return - V_628 ;
F_84 ( & V_6 -> V_264 ) ;
V_6 -> V_187 |= V_512 ;
memcpy ( V_6 -> V_228 , V_8 -> V_627 , V_229 ) ;
V_63 = F_232 ( V_6 , 0 ) ;
if ( V_63 )
goto V_619;
V_6 -> V_47 = 0 ;
F_85 ( & V_6 -> V_264 ) ;
F_107 ( & V_6 -> V_52 . V_261 ) ;
return 0 ;
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_263 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_62 ;
F_31 ( L_239 ) ;
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
while ( ! F_44 ( & V_6 -> V_420 ) ) {
V_59 = V_6 -> V_420 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_423 ) ;
F_163 ( V_61 -> V_81 . V_407 . V_408 ) ;
V_61 -> V_81 . V_407 . V_408 = NULL ;
F_48 ( V_59 , & V_6 -> V_409 ) ;
F_49 ( & V_6 -> V_410 ) ;
}
F_52 ( & V_6 -> V_68 , V_62 ) ;
F_31 ( L_45 ) ;
return 0 ;
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_2 -> V_326 . V_629 ++ ;
#ifdef F_155
if ( V_6 -> V_150 -> V_198 == V_199 )
return;
#endif
F_31 ( L_240 ,
V_2 -> V_51 ) ;
F_35 ( V_6 ) ;
}
static int F_268 ( struct V_5 * V_6 , int V_147 )
{
V_6 -> V_150 -> V_630 = V_147 ;
return 0 ;
}
static int F_269 ( struct V_5 * V_6 , int V_147 )
{
struct V_631 * V_150 = V_6 -> V_150 ;
struct V_616 V_190 = {
. V_62 = V_604 ,
} ;
int V_265 = 0 ;
if ( V_147 & V_632 ) {
V_190 . V_565 = V_605 ;
V_150 -> V_633 = 0 ;
} else if ( V_147 & V_634 ) {
V_190 . V_565 = V_635 ;
V_150 -> V_633 = 1 ;
} else if ( V_147 & V_636 ) {
V_190 . V_565 = V_607 ;
V_150 -> V_633 = 1 ;
} else
return - V_31 ;
if ( V_150 -> V_637 )
V_150 -> V_637 ( V_150 -> V_2 , & V_190 ) ;
else
V_265 = - V_638 ;
return V_265 ;
}
static void V_562 ( struct V_5 * V_6 ,
char * V_639 , int V_640 )
{
struct V_562 V_641 ;
V_641 . V_642 = 0 ;
memcpy ( V_641 . V_643 , V_639 , V_640 ) ;
V_641 . V_644 = V_640 ;
F_268 ( V_6 , 1 ) ;
F_246 ( V_6 , & V_641 , 0 ) ;
}
static void F_270 ( struct V_1 * V_2 ,
struct V_645 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char V_646 [ 64 ] , V_647 [ 64 ] ;
F_271 ( V_81 -> V_648 , V_649 , sizeof( V_81 -> V_648 ) ) ;
F_271 ( V_81 -> V_121 , V_650 , sizeof( V_81 -> V_121 ) ) ;
F_272 ( V_6 , V_646 , sizeof( V_646 ) ) ;
F_273 ( V_6 , V_647 , sizeof( V_647 ) ) ;
snprintf ( V_81 -> V_651 , sizeof( V_81 -> V_651 ) , L_241 ,
V_646 , V_6 -> V_156 , V_647 ) ;
F_271 ( V_81 -> V_652 , F_274 ( V_6 -> V_259 ) ,
sizeof( V_81 -> V_652 ) ) ;
}
static T_1 F_275 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return ( V_6 -> V_49 & V_166 ) ? 1 : 0 ;
}
static void F_276 ( struct V_260 * V_261 )
{
struct V_5 * V_6 =
F_108 ( V_261 , struct V_5 , V_182 . V_261 ) ;
unsigned long V_62 ;
T_1 V_653 = 0xa5a5a5a5 ;
T_1 V_14 = sizeof( V_653 ) ;
int V_654 = 0 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( V_6 -> V_69 != 0 ) {
F_31 ( L_242 ,
V_6 -> V_33 -> V_51 ) ;
V_654 = 1 ;
} else if ( F_26 ( V_6 , V_655 , & V_653 , & V_14 ) ||
( V_653 == V_6 -> V_492 ) ) {
F_31 ( L_243 ,
V_6 -> V_33 -> V_51 ) ;
V_654 = 1 ;
}
if ( V_654 ) {
V_6 -> V_181 = 1 ;
V_6 -> V_486 ++ ;
F_35 ( V_6 ) ;
}
V_6 -> V_492 = V_653 ;
if ( ! V_6 -> V_181 )
F_39 ( & V_6 -> V_182 , V_53 / 2 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
}
static void F_277 ( struct V_260 * V_261 )
{
struct V_5 * V_6 =
F_108 ( V_261 , struct V_5 , V_215 . V_261 ) ;
unsigned long V_62 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( F_71 ( V_6 ) ) {
F_213 ( L_244 ) ;
if ( ! V_6 -> V_214 )
F_39 ( & V_6 -> V_215 ,
F_97 ( V_53 ) ) ;
goto V_656;
}
if ( ! ( V_6 -> V_49 & V_483 ) ) {
F_213 ( L_245
L_246 ) ;
F_35 ( V_6 ) ;
} else
F_213 ( L_247
L_248 ) ;
V_656:
F_52 ( & V_6 -> V_68 , V_62 ) ;
}
static struct V_1 * F_278 ( struct V_259 * V_259 ,
void T_12 * V_7 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_279 ( sizeof( struct V_5 ) , 0 ) ;
if ( ! V_2 )
return NULL ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_150 = F_280 ( V_2 ) ;
V_6 -> V_259 = V_259 ;
V_6 -> V_33 = V_2 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_150 -> V_657 = F_178 ;
V_6 -> V_150 -> V_637 = F_260 ;
V_6 -> V_150 -> V_658 = - 20 ;
V_6 -> V_150 -> V_659 = - 85 ;
V_2 -> V_660 = & V_661 ;
V_2 -> V_662 = & V_663 ;
V_2 -> V_664 = & V_665 ;
V_6 -> V_666 . V_667 = V_6 -> V_150 ;
V_2 -> V_666 = & V_6 -> V_666 ;
V_2 -> V_668 = 3 * V_53 ;
V_2 -> V_453 = 0 ;
V_2 -> V_669 = 68 ;
V_2 -> V_670 = V_671 ;
V_6 -> V_544 = V_672 ;
#ifdef F_155
V_6 -> V_187 |= V_343 ;
#endif
V_6 -> V_150 -> V_630 = 0 ;
V_6 -> V_150 -> V_673 = 0 ;
V_6 -> V_150 -> V_674 = 0 ;
V_6 -> V_150 -> V_675 = 1 ;
switch ( V_676 ) {
case 1 :
V_6 -> V_150 -> V_198 = V_430 ;
break;
#ifdef F_155
case 2 :
V_6 -> V_150 -> V_198 = V_199 ;
break;
#endif
default:
case 0 :
V_6 -> V_150 -> V_198 = V_425 ;
break;
}
if ( V_677 == 1 )
V_6 -> V_49 |= V_205 ;
if ( V_244 != 0 &&
( ( V_244 >= V_518 ) && ( V_244 <= V_519 ) ) ) {
V_6 -> V_187 |= V_520 ;
V_6 -> V_244 = V_244 ;
}
if ( V_678 )
V_6 -> V_187 |= V_188 ;
V_6 -> V_625 = V_679 ;
V_6 -> V_557 = V_680 ;
V_6 -> V_559 = V_681 ;
V_6 -> V_554 = V_682 | V_552 ;
V_6 -> V_683 = V_684 | V_685 ;
V_6 -> V_584 = V_585 ;
V_6 -> V_540 = V_686 ;
strcpy ( V_6 -> V_687 , L_249 ) ;
F_281 ( & V_6 -> V_68 ) ;
F_282 ( & V_6 -> V_264 ) ;
F_282 ( & V_6 -> V_179 ) ;
F_283 ( & V_6 -> V_55 ) ;
F_37 ( V_2 ) ;
F_183 ( & V_6 -> V_75 ) ;
F_183 ( & V_6 -> V_91 ) ;
F_226 ( & V_6 -> V_90 ) ;
F_226 ( & V_6 -> V_92 ) ;
F_183 ( & V_6 -> V_409 ) ;
F_183 ( & V_6 -> V_420 ) ;
F_226 ( & V_6 -> V_410 ) ;
F_226 ( & V_6 -> V_423 ) ;
F_183 ( & V_6 -> V_393 ) ;
F_226 ( & V_6 -> V_401 ) ;
F_284 ( & V_6 -> V_52 , F_107 ) ;
F_284 ( & V_6 -> V_292 , F_259 ) ;
F_284 ( & V_6 -> V_283 , V_688 ) ;
F_284 ( & V_6 -> V_182 , F_276 ) ;
F_284 ( & V_6 -> V_215 , F_277 ) ;
F_284 ( & V_6 -> V_294 , F_117 ) ;
F_285 ( & V_6 -> V_456 , ( void (*) ( unsigned long ) )
F_171 , ( unsigned long ) V_6 ) ;
V_6 -> V_214 = 1 ;
V_6 -> V_181 = 1 ;
return V_2 ;
}
static int F_286 ( struct V_259 * V_259 ,
const struct V_689 * V_690 )
{
void T_12 * V_7 ;
struct V_1 * V_2 = NULL ;
struct V_5 * V_6 = NULL ;
int V_63 = 0 ;
int V_691 = 0 ;
T_1 V_4 ;
F_31 ( L_42 ) ;
if ( ! ( F_287 ( V_259 , 0 ) & V_692 ) ) {
F_31 ( L_250 ) ;
V_63 = - V_693 ;
goto V_39;
}
V_7 = F_288 ( V_259 , 0 , 0 ) ;
if ( ! V_7 ) {
F_27 (KERN_WARNING DRV_NAME
L_251 ) ;
V_63 = - V_70 ;
goto V_123;
}
V_2 = F_278 ( V_259 , V_7 ) ;
if ( ! V_2 ) {
F_27 (KERN_WARNING DRV_NAME
L_252 ) ;
V_63 = - V_239 ;
goto V_123;
}
V_63 = F_289 ( V_259 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_253 ) ;
return V_63 ;
}
V_6 = F_2 ( V_2 ) ;
F_290 ( V_259 ) ;
F_291 ( V_259 , V_6 ) ;
V_63 = F_292 ( V_259 , F_293 ( 32 ) ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_254 ) ;
F_294 ( V_259 ) ;
return V_63 ;
}
V_63 = F_295 ( V_259 , V_649 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_255 ) ;
F_294 ( V_259 ) ;
return V_63 ;
}
F_187 ( V_259 , 0x40 , & V_4 ) ;
if ( ( V_4 & 0x0000ff00 ) != 0 )
F_296 ( V_259 , 0x40 , V_4 & 0xffff00ff ) ;
if ( ! F_25 ( V_2 ) ) {
F_27 (KERN_WARNING DRV_NAME
L_256 ) ;
V_63 = - V_693 ;
goto V_123;
}
F_297 ( V_2 , & V_259 -> V_2 ) ;
V_6 -> V_49 |= V_136 ;
F_68 ( V_6 ) ;
if ( F_251 ( V_6 ) ) {
F_27 (KERN_WARNING DRV_NAME
L_257 ) ;
V_63 = - V_239 ;
goto V_123;
}
F_77 ( V_6 ) ;
V_63 = F_298 ( V_259 -> V_453 ,
F_174 , V_694 , V_2 -> V_51 , V_6 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_258 , pci_dev->irq) ;
goto V_123;
}
V_2 -> V_453 = V_259 -> V_453 ;
F_31 ( L_259 ) ;
F_27 (KERN_INFO DRV_NAME
L_260 ) ;
V_63 = F_93 ( V_6 , 1 ) ;
if ( V_63 )
goto V_123;
V_63 = F_101 ( V_2 ) ;
if ( V_63 )
goto V_123;
V_691 = 1 ;
V_63 = F_299 ( V_2 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_261 ) ;
goto V_123;
}
V_691 = 2 ;
F_84 ( & V_6 -> V_264 ) ;
F_31 ( L_262 , V_2 -> V_51 , F_274 ( V_259 ) ) ;
V_63 = F_300 ( & V_259 -> V_2 . V_695 , & V_696 ) ;
if ( V_63 )
goto V_71;
if ( ! ( V_6 -> V_49 & V_483 ) ) {
if ( F_83 ( V_6 ) ) {
F_27 (KERN_WARNING DRV_NAME
L_263 ,
priv->net_dev->name) ;
F_86 ( V_6 ) ;
V_63 = - V_70 ;
goto V_71;
}
F_90 ( V_6 ) ;
F_92 ( V_6 ) ;
}
F_31 ( L_45 ) ;
V_6 -> V_49 |= V_618 ;
F_85 ( & V_6 -> V_264 ) ;
V_39:
return V_63 ;
V_71:
F_85 ( & V_6 -> V_264 ) ;
V_123:
if ( V_2 ) {
if ( V_691 >= 2 )
F_301 ( V_2 ) ;
if ( V_691 ) {
F_302 ( V_6 -> V_150 -> V_151 . V_152 ) ;
F_130 ( V_6 -> V_150 -> V_232 . V_236 ) ;
}
F_86 ( V_6 ) ;
F_68 ( V_6 ) ;
if ( V_2 -> V_453 )
F_303 ( V_2 -> V_453 , V_6 ) ;
F_220 ( V_6 ) ;
F_250 ( V_6 ) ;
F_304 ( & V_259 -> V_2 . V_695 ,
& V_696 ) ;
F_305 ( V_2 , 0 ) ;
}
F_306 ( V_259 , V_7 ) ;
F_307 ( V_259 ) ;
F_294 ( V_259 ) ;
goto V_39;
}
static void F_308 ( struct V_259 * V_259 )
{
struct V_5 * V_6 = F_309 ( V_259 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
F_84 ( & V_6 -> V_264 ) ;
V_6 -> V_49 &= ~ V_618 ;
F_304 ( & V_259 -> V_2 . V_695 , & V_696 ) ;
#ifdef F_61
if ( V_120 . V_121 )
F_66 ( V_6 , & V_120 ) ;
#endif
F_99 ( V_6 ) ;
F_85 ( & V_6 -> V_264 ) ;
F_301 ( V_2 ) ;
F_220 ( V_6 ) ;
F_250 ( V_6 ) ;
F_129 ( V_6 ) ;
F_303 ( V_2 -> V_453 , V_6 ) ;
F_306 ( V_259 , V_6 -> V_7 ) ;
F_302 ( V_6 -> V_150 -> V_151 . V_152 ) ;
F_130 ( V_6 -> V_150 -> V_232 . V_236 ) ;
F_305 ( V_2 , 0 ) ;
F_307 ( V_259 ) ;
F_294 ( V_259 ) ;
F_31 ( L_45 ) ;
}
static int F_310 ( struct V_259 * V_259 , T_13 V_102 )
{
struct V_5 * V_6 = F_309 ( V_259 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
F_31 ( L_264 , V_2 -> V_51 ) ;
F_84 ( & V_6 -> V_264 ) ;
if ( V_6 -> V_49 & V_618 ) {
F_99 ( V_6 ) ;
}
F_311 ( V_2 ) ;
F_312 ( V_259 ) ;
F_294 ( V_259 ) ;
F_313 ( V_259 , V_697 ) ;
V_6 -> V_698 = F_36 () ;
F_85 ( & V_6 -> V_264 ) ;
return 0 ;
}
static int F_314 ( struct V_259 * V_259 )
{
struct V_5 * V_6 = F_309 ( V_259 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
int V_63 ;
T_1 V_4 ;
if ( V_699 )
return 0 ;
F_84 ( & V_6 -> V_264 ) ;
F_31 ( L_265 , V_2 -> V_51 ) ;
F_313 ( V_259 , V_700 ) ;
V_63 = F_289 ( V_259 ) ;
if ( V_63 ) {
F_27 ( V_701 L_266 ,
V_2 -> V_51 ) ;
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
F_315 ( V_259 ) ;
F_187 ( V_259 , 0x40 , & V_4 ) ;
if ( ( V_4 & 0x0000ff00 ) != 0 )
F_296 ( V_259 , 0x40 , V_4 & 0xffff00ff ) ;
F_316 ( V_2 ) ;
V_6 -> V_204 = F_36 () - V_6 -> V_698 ;
if ( ! ( V_6 -> V_49 & V_205 ) )
F_93 ( V_6 , 0 ) ;
F_85 ( & V_6 -> V_264 ) ;
return 0 ;
}
static void F_317 ( struct V_259 * V_259 )
{
struct V_5 * V_6 = F_309 ( V_259 ) ;
F_99 ( V_6 ) ;
F_294 ( V_259 ) ;
}
static int T_14 F_318 ( void )
{
int V_265 ;
F_27 (KERN_INFO DRV_NAME L_267 , DRV_DESCRIPTION, DRV_VERSION) ;
F_27 (KERN_INFO DRV_NAME L_268 , DRV_COPYRIGHT) ;
F_319 ( & V_206 , V_702 ,
V_222 ) ;
V_265 = F_320 ( & V_703 ) ;
if ( V_265 )
goto V_39;
#ifdef F_123
V_44 = V_704 ;
V_265 = F_321 ( & V_703 . V_648 ,
& V_705 ) ;
#endif
V_39:
return V_265 ;
}
static void T_15 F_322 ( void )
{
#ifdef F_123
F_323 ( & V_703 . V_648 ,
& V_705 ) ;
#endif
F_324 ( & V_703 ) ;
F_325 ( & V_206 ) ;
}
static int F_326 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_49 & V_166 ) )
strcpy ( V_217 -> V_51 , L_269 ) ;
else
snprintf ( V_217 -> V_51 , V_708 , L_270 ) ;
F_327 ( L_271 , V_217 -> V_51 ) ;
return 0 ;
}
static int F_328 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_709 * V_710 = & V_217 -> V_242 ;
int V_63 = 0 ;
if ( V_6 -> V_150 -> V_198 == V_425 )
return - V_638 ;
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) ) {
V_63 = - V_70 ;
goto V_619;
}
if ( V_710 -> V_391 == 1 ) {
if ( ( V_710 -> V_711 >= ( int ) 2.412e8 && V_710 -> V_711 <= ( int ) 2.487e8 ) ) {
int V_712 = V_710 -> V_711 / 100000 ;
int V_42 = 0 ;
while ( ( V_42 < V_519 ) &&
( V_712 != V_713 [ V_42 ] ) )
V_42 ++ ;
V_710 -> V_391 = 0 ;
V_710 -> V_711 = V_42 + 1 ;
}
}
if ( V_710 -> V_391 > 0 || V_710 -> V_711 > 1000 ) {
V_63 = - V_638 ;
goto V_619;
} else {
F_327 ( L_272 , V_710 -> V_711 ) ;
V_63 = F_234 ( V_6 , V_710 -> V_711 , 0 ) ;
}
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_329 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_217 -> V_242 . V_391 = 0 ;
if ( V_6 -> V_187 & V_520 ||
V_6 -> V_49 & V_166 )
V_217 -> V_242 . V_711 = V_6 -> V_244 ;
else
V_217 -> V_242 . V_711 = 0 ;
F_327 ( L_273 , V_6 -> V_244 ) ;
return 0 ;
}
static int F_330 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
F_327 ( L_274 , V_217 -> V_312 ) ;
if ( V_217 -> V_312 == V_6 -> V_150 -> V_198 )
return 0 ;
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) ) {
V_63 = - V_70 ;
goto V_619;
}
switch ( V_217 -> V_312 ) {
#ifdef F_155
case V_199 :
V_63 = F_198 ( V_6 , V_199 ) ;
break;
#endif
case V_430 :
V_63 = F_198 ( V_6 , V_430 ) ;
break;
case V_425 :
case V_714 :
default:
V_63 = F_198 ( V_6 , V_425 ) ;
break;
}
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_331 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_217 -> V_312 = V_6 -> V_150 -> V_198 ;
F_327 ( L_275 , V_217 -> V_312 ) ;
return 0 ;
}
static int F_332 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_715 * V_716 = (struct V_715 * ) V_707 ;
T_2 V_4 ;
int V_19 , V_43 ;
V_217 -> V_37 . V_284 = sizeof( * V_716 ) ;
memset ( V_716 , 0 , sizeof( * V_716 ) ) ;
V_716 -> V_717 = 5 * 1000 * 1000 ;
V_716 -> V_718 . V_719 = 100 ;
V_716 -> V_718 . V_43 = 0 ;
V_716 -> V_718 . V_720 = 0 ;
V_716 -> V_718 . V_721 = 7 ;
V_716 -> V_722 . V_719 = 70 ;
V_716 -> V_722 . V_43 = 20 + V_352 ;
V_716 -> V_722 . V_720 = 0 ;
V_716 -> V_722 . V_721 = 7 ;
V_716 -> V_723 = V_254 ;
for ( V_19 = 0 ; V_19 < V_254 && V_19 < V_724 ; V_19 ++ ) {
V_716 -> V_725 [ V_19 ] = V_252 [ V_19 ] . V_725 * 100 * 1000 ;
}
V_716 -> V_726 = V_727 ;
V_716 -> V_728 = V_553 ;
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
if ( V_6 -> V_150 -> V_198 == V_430 ) {
V_716 -> V_749 = V_750 ;
V_716 -> V_751 = V_752 ;
for ( V_19 = 0 , V_43 = ( V_587 * 16 ) ;
V_19 < V_752 ;
V_19 ++ , V_43 -=
( ( V_587 -
V_586 ) * 16 ) / ( V_752 - 1 ) )
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
V_716 -> V_242 [ V_4 ] . V_19 = V_19 + 1 ;
V_716 -> V_242 [ V_4 ] . V_711 = V_713 [ V_19 ] * 100000 ;
V_716 -> V_242 [ V_4 ] . V_391 = 1 ;
V_4 ++ ;
if ( V_4 == V_759 )
break;
}
V_716 -> V_760 = V_4 ;
V_716 -> V_761 [ 0 ] = ( V_762 |
F_333 ( V_223 ) ) ;
V_716 -> V_761 [ 1 ] = V_763 ;
V_716 -> V_764 = V_765 | V_766 |
V_767 | V_768 ;
F_327 ( L_276 ) ;
return 0 ;
}
static int F_334 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
if ( V_217 -> V_218 . V_219 != V_220 )
return - V_31 ;
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) ) {
V_63 = - V_70 ;
goto V_619;
}
if ( F_335 ( V_217 -> V_218 . V_627 ) ||
F_336 ( V_217 -> V_218 . V_627 ) ) {
F_327 ( L_277 ) ;
V_6 -> V_187 &= ~ V_624 ;
V_63 = F_244 ( V_6 , NULL , 0 ) ;
goto V_619;
}
V_6 -> V_187 |= V_624 ;
memcpy ( V_6 -> V_769 , V_217 -> V_218 . V_627 , V_229 ) ;
V_63 = F_244 ( V_6 , V_217 -> V_218 . V_627 , 0 ) ;
F_327 ( L_278 , V_217 -> V_218 . V_627 ) ;
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_337 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_624 || V_6 -> V_49 & V_166 ) {
V_217 -> V_218 . V_219 = V_220 ;
memcpy ( V_217 -> V_218 . V_627 , V_6 -> V_272 , V_229 ) ;
} else
F_114 ( V_217 -> V_218 . V_627 ) ;
F_327 ( L_279 , V_217 -> V_218 . V_627 ) ;
return 0 ;
}
static int F_338 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char * V_267 = L_50 ;
int V_284 = 0 ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) ) {
V_63 = - V_70 ;
goto V_619;
}
if ( V_217 -> V_267 . V_62 && V_217 -> V_267 . V_284 ) {
V_284 = V_217 -> V_267 . V_284 ;
V_267 = V_707 ;
}
if ( V_284 == 0 ) {
F_327 ( L_280 ) ;
V_6 -> V_187 &= ~ V_281 ;
V_63 = F_111 ( V_6 , NULL , 0 , 0 ) ;
goto V_619;
}
V_284 = F_34 ( V_284 , V_268 ) ;
V_6 -> V_187 |= V_281 ;
if ( V_6 -> V_266 == V_284 && ! memcmp ( V_6 -> V_267 , V_707 , V_284 ) ) {
F_327 ( L_281 ) ;
V_63 = 0 ;
goto V_619;
}
F_327 ( L_282 , V_284 , V_267 , V_284 ) ;
V_6 -> V_266 = V_284 ;
memcpy ( V_6 -> V_267 , V_267 , V_6 -> V_266 ) ;
V_63 = F_111 ( V_6 , V_267 , V_284 , 0 ) ;
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_339 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_281 || V_6 -> V_49 & V_166 ) {
F_327 ( L_283 ,
V_6 -> V_266 , V_6 -> V_267 ) ;
memcpy ( V_707 , V_6 -> V_267 , V_6 -> V_266 ) ;
V_217 -> V_267 . V_284 = V_6 -> V_266 ;
V_217 -> V_267 . V_62 = 1 ;
} else {
F_327 ( L_284 ) ;
V_217 -> V_267 . V_284 = 0 ;
V_217 -> V_267 . V_62 = 0 ;
}
return 0 ;
}
static int F_340 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_217 -> V_37 . V_284 > V_268 )
return - V_770 ;
V_217 -> V_37 . V_284 = F_147 ( T_4 , V_217 -> V_37 . V_284 , sizeof( V_6 -> V_687 ) ) ;
memset ( V_6 -> V_687 , 0 , sizeof( V_6 -> V_687 ) ) ;
memcpy ( V_6 -> V_687 , V_707 , V_217 -> V_37 . V_284 ) ;
F_327 ( L_285 , V_6 -> V_687 ) ;
return 0 ;
}
static int F_341 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_217 -> V_37 . V_284 = strlen ( V_6 -> V_687 ) ;
memcpy ( V_707 , V_6 -> V_687 , V_217 -> V_37 . V_284 ) ;
V_217 -> V_37 . V_62 = 1 ;
F_327 ( L_286 , V_707 ) ;
return 0 ;
}
static int F_342 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_771 = V_217 -> V_725 . V_147 ;
T_1 V_535 ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) ) {
V_63 = - V_70 ;
goto V_619;
}
V_535 = 0 ;
if ( V_771 == 1000000 ||
( ! V_217 -> V_725 . V_772 && V_771 > 1000000 ) )
V_535 |= V_277 ;
if ( V_771 == 2000000 ||
( ! V_217 -> V_725 . V_772 && V_771 > 2000000 ) )
V_535 |= V_278 ;
if ( V_771 == 5500000 ||
( ! V_217 -> V_725 . V_772 && V_771 > 5500000 ) )
V_535 |= V_279 ;
if ( V_771 == 11000000 ||
( ! V_217 -> V_725 . V_772 && V_771 > 11000000 ) )
V_535 |= V_280 ;
if ( V_535 == 0 )
V_535 = V_686 ;
V_63 = F_237 ( V_6 , V_535 , 0 ) ;
F_327 ( L_287 , V_535 ) ;
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_343 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_4 ;
unsigned int V_14 = sizeof( V_4 ) ;
int V_63 = 0 ;
if ( ! ( V_6 -> V_49 & V_106 ) ||
V_6 -> V_49 & V_483 ||
! ( V_6 -> V_49 & V_166 ) ) {
V_217 -> V_725 . V_147 = 0 ;
return 0 ;
}
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) ) {
V_63 = - V_70 ;
goto V_619;
}
V_63 = F_26 ( V_6 , V_274 , & V_4 , & V_14 ) ;
if ( V_63 ) {
F_327 ( L_288 ) ;
goto V_619;
}
switch ( V_4 & V_537 ) {
case V_277 :
V_217 -> V_725 . V_147 = 1000000 ;
break;
case V_278 :
V_217 -> V_725 . V_147 = 2000000 ;
break;
case V_279 :
V_217 -> V_725 . V_147 = 5500000 ;
break;
case V_280 :
V_217 -> V_725 . V_147 = 11000000 ;
break;
default:
V_217 -> V_725 . V_147 = 0 ;
}
F_327 ( L_289 , V_217 -> V_725 . V_147 ) ;
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_344 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_147 , V_63 ;
if ( V_217 -> V_773 . V_772 == 0 )
return - V_31 ;
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) ) {
V_63 = - V_70 ;
goto V_619;
}
if ( V_217 -> V_773 . V_774 )
V_147 = V_6 -> V_554 | V_552 ;
else {
if ( V_217 -> V_773 . V_147 < 1 || V_217 -> V_773 . V_147 > 2304 ) {
V_63 = - V_31 ;
goto V_619;
}
V_147 = V_217 -> V_773 . V_147 ;
}
V_63 = F_241 ( V_6 , V_147 ) ;
F_327 ( L_290 , V_147 ) ;
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_345 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_217 -> V_773 . V_147 = V_6 -> V_554 & ~ V_552 ;
V_217 -> V_773 . V_772 = 1 ;
V_217 -> V_773 . V_774 = ( V_6 -> V_554 & V_552 ) ? 1 : 0 ;
F_327 ( L_291 , V_217 -> V_773 . V_147 ) ;
return 0 ;
}
static int F_346 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 , V_147 ;
if ( F_212 ( V_6 , V_217 -> V_753 . V_774 ) )
return - V_775 ;
if ( V_6 -> V_150 -> V_198 != V_430 )
return 0 ;
if ( ( V_217 -> V_753 . V_62 & V_776 ) != V_750 )
return - V_31 ;
if ( V_217 -> V_753 . V_772 == 0 )
V_147 = V_585 ;
else {
if ( V_217 -> V_753 . V_147 < V_586 ||
V_217 -> V_753 . V_147 > V_587 )
return - V_31 ;
V_147 = V_217 -> V_753 . V_147 ;
}
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) ) {
V_63 = - V_70 ;
goto V_619;
}
V_63 = F_248 ( V_6 , V_147 ) ;
F_327 ( L_292 , V_147 ) ;
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_347 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_217 -> V_753 . V_774 = ( V_6 -> V_49 & V_483 ) ? 1 : 0 ;
if ( V_6 -> V_584 == V_585 ) {
V_217 -> V_753 . V_772 = 0 ;
V_217 -> V_753 . V_147 = V_587 ;
} else {
V_217 -> V_753 . V_772 = 1 ;
V_217 -> V_753 . V_147 = V_6 -> V_584 ;
}
V_217 -> V_753 . V_62 = V_750 ;
F_327 ( L_293 , V_217 -> V_753 . V_147 ) ;
return 0 ;
}
static int F_348 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_217 -> V_777 . V_772 )
return - V_31 ;
if ( V_217 -> V_777 . V_774 ) {
V_6 -> V_683 |= V_685 ;
V_6 -> V_150 -> V_778 = V_684 ;
} else {
if ( V_217 -> V_777 . V_147 < V_730 ||
V_217 -> V_777 . V_147 > V_732 )
return - V_31 ;
V_6 -> V_150 -> V_778 = V_217 -> V_777 . V_147 & ~ 0x1 ;
V_6 -> V_683 = V_6 -> V_150 -> V_778 ;
}
F_327 ( L_294 , V_6 -> V_150 -> V_778 ) ;
return 0 ;
}
static int F_349 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_217 -> V_777 . V_147 = V_6 -> V_683 & ~ V_685 ;
V_217 -> V_777 . V_772 = 0 ;
V_217 -> V_777 . V_774 = ( V_6 -> V_683 & V_685 ) ? 1 : 0 ;
F_327 ( L_295 , V_217 -> V_777 . V_147 ) ;
return 0 ;
}
static int F_350 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
if ( V_217 -> V_555 . V_62 & V_779 || V_217 -> V_555 . V_774 )
return - V_31 ;
if ( ! ( V_217 -> V_555 . V_62 & V_780 ) )
return 0 ;
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) ) {
V_63 = - V_70 ;
goto V_619;
}
if ( V_217 -> V_555 . V_62 & V_781 ) {
V_63 = F_242 ( V_6 , V_217 -> V_555 . V_147 ) ;
F_327 ( L_296 ,
V_217 -> V_555 . V_147 ) ;
goto V_619;
}
if ( V_217 -> V_555 . V_62 & V_782 ) {
V_63 = F_243 ( V_6 , V_217 -> V_555 . V_147 ) ;
F_327 ( L_297 ,
V_217 -> V_555 . V_147 ) ;
goto V_619;
}
V_63 = F_242 ( V_6 , V_217 -> V_555 . V_147 ) ;
if ( ! V_63 )
V_63 = F_243 ( V_6 , V_217 -> V_555 . V_147 ) ;
F_327 ( L_298 , V_217 -> V_555 . V_147 ) ;
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_351 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_217 -> V_555 . V_774 = 0 ;
if ( ( V_217 -> V_555 . V_62 & V_783 ) == V_779 )
return - V_31 ;
if ( V_217 -> V_555 . V_62 & V_782 ) {
V_217 -> V_555 . V_62 = V_780 | V_782 ;
V_217 -> V_555 . V_147 = V_6 -> V_559 ;
} else {
V_217 -> V_555 . V_62 =
( V_6 -> V_557 !=
V_6 -> V_559 ) ?
V_780 | V_781 : V_780 ;
V_217 -> V_555 . V_147 = V_6 -> V_557 ;
}
F_327 ( L_299 , V_217 -> V_555 . V_147 ) ;
return 0 ;
}
static int F_352 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) ) {
V_63 = - V_70 ;
goto V_619;
}
F_327 ( L_300 ) ;
V_6 -> V_297 = 1 ;
if ( F_90 ( V_6 ) || F_92 ( V_6 ) ) {
F_327 ( L_301 ) ;
}
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_353 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_354 ( V_6 -> V_150 , V_81 , V_217 , V_707 ) ;
}
static int F_355 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_592 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_356 ( V_6 -> V_150 , V_81 , V_217 , V_592 ) ;
}
static int F_357 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_592 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_358 ( V_6 -> V_150 , V_81 , V_217 , V_592 ) ;
}
static int F_359 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) ) {
V_63 = - V_70 ;
goto V_619;
}
if ( V_217 -> V_784 . V_774 ) {
V_6 -> V_544 = F_239 ( V_6 -> V_544 ) ;
V_63 = F_238 ( V_6 , V_543 ) ;
F_327 ( L_302 ) ;
goto V_619;
}
switch ( V_217 -> V_784 . V_62 & V_785 ) {
case V_786 :
case V_785 :
case V_787 :
break;
default:
F_327 ( L_303 ,
V_217 -> V_784 . V_62 ) ;
V_63 = - V_638 ;
goto V_619;
}
V_6 -> V_544 = V_545 | V_6 -> V_544 ;
V_63 = F_238 ( V_6 , F_239 ( V_6 -> V_544 ) ) ;
F_327 ( L_304 , V_6 -> V_544 ) ;
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_360 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_544 & V_545 ) )
V_217 -> V_784 . V_774 = 1 ;
else {
V_217 -> V_784 . V_774 = 0 ;
V_217 -> V_784 . V_62 = 0 ;
}
F_327 ( L_305 , V_6 -> V_544 ) ;
return 0 ;
}
static int F_361 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_631 * V_150 = V_6 -> V_150 ;
T_3 * V_15 ;
if ( ! V_150 -> V_630 )
return - V_638 ;
if ( V_217 -> V_37 . V_284 > V_788 ||
( V_217 -> V_37 . V_284 && V_707 == NULL ) )
return - V_31 ;
if ( V_217 -> V_37 . V_284 ) {
V_15 = F_362 ( V_707 , V_217 -> V_37 . V_284 , V_238 ) ;
if ( V_15 == NULL )
return - V_239 ;
F_130 ( V_150 -> V_639 ) ;
V_150 -> V_639 = V_15 ;
V_150 -> V_640 = V_217 -> V_37 . V_284 ;
} else {
F_130 ( V_150 -> V_639 ) ;
V_150 -> V_639 = NULL ;
V_150 -> V_640 = 0 ;
}
V_562 ( V_6 , V_150 -> V_639 , V_150 -> V_640 ) ;
return 0 ;
}
static int F_363 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_631 * V_150 = V_6 -> V_150 ;
if ( V_150 -> V_640 == 0 || V_150 -> V_639 == NULL ) {
V_217 -> V_37 . V_284 = 0 ;
return 0 ;
}
if ( V_217 -> V_37 . V_284 < V_150 -> V_640 )
return - V_770 ;
V_217 -> V_37 . V_284 = V_150 -> V_640 ;
memcpy ( V_707 , V_150 -> V_639 , V_150 -> V_640 ) ;
return 0 ;
}
static int F_364 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_631 * V_150 = V_6 -> V_150 ;
struct V_789 * V_790 = & V_217 -> V_790 ;
struct V_791 * V_490 ;
unsigned long V_62 ;
int V_265 = 0 ;
switch ( V_790 -> V_62 & V_792 ) {
case V_793 :
case V_794 :
case V_795 :
case V_796 :
break;
case V_797 :
V_490 = V_6 -> V_150 -> V_489 . V_490 [ V_6 -> V_150 -> V_489 . V_491 ] ;
if ( ! V_490 || ! V_490 -> V_798 -> V_799 || ! V_490 -> V_798 -> V_800 )
break;
V_62 = V_490 -> V_798 -> V_800 ( V_490 -> V_6 ) ;
if ( V_790 -> V_147 )
V_62 |= V_801 ;
else
V_62 &= ~ V_801 ;
V_490 -> V_798 -> V_799 ( V_62 , V_490 -> V_6 ) ;
break;
case V_802 : {
struct V_616 V_190 = {
. V_62 = V_191 ,
. V_192 = V_790 -> V_147 ,
} ;
V_6 -> V_150 -> V_673 = V_790 -> V_147 ;
if ( ! V_790 -> V_147 ) {
V_190 . V_62 |= V_609 ;
V_190 . V_43 = V_571 ;
} else {
V_190 . V_62 |= V_609 ;
V_190 . V_43 = V_574 ;
}
if ( V_6 -> V_150 -> V_637 )
V_6 -> V_150 -> V_637 ( V_6 -> V_150 -> V_2 , & V_190 ) ;
break;
}
case V_803 :
V_265 = F_269 ( V_6 , V_790 -> V_147 ) ;
break;
case V_804 :
V_265 = F_268 ( V_6 , V_790 -> V_147 ) ;
break;
case V_805 :
V_150 -> V_675 = V_790 -> V_147 ;
break;
case V_806 :
V_150 -> V_674 = V_790 -> V_147 ;
break;
default:
return - V_638 ;
}
return V_265 ;
}
static int F_365 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_631 * V_150 = V_6 -> V_150 ;
struct V_791 * V_490 ;
struct V_789 * V_790 = & V_217 -> V_790 ;
int V_265 = 0 ;
switch ( V_790 -> V_62 & V_792 ) {
case V_793 :
case V_794 :
case V_795 :
case V_796 :
V_265 = - V_638 ;
break;
case V_797 :
V_490 = V_6 -> V_150 -> V_489 . V_490 [ V_6 -> V_150 -> V_489 . V_491 ] ;
if ( ! V_490 || ! V_490 -> V_798 -> V_800 ) {
F_153 ( L_306
L_307 ) ;
break;
}
V_790 -> V_147 = ( V_490 -> V_798 -> V_800 ( V_490 -> V_6 ) &
V_801 ) ? 1 : 0 ;
break;
case V_802 :
V_790 -> V_147 = V_150 -> V_673 ;
break;
case V_803 :
V_790 -> V_147 = V_6 -> V_150 -> V_190 . V_565 ;
break;
case V_804 :
V_790 -> V_147 = V_150 -> V_630 ;
break;
case V_805 :
V_790 -> V_147 = V_150 -> V_675 ;
break;
case V_807 :
case V_806 :
V_790 -> V_147 = V_150 -> V_674 ;
break;
default:
return - V_638 ;
}
return 0 ;
}
static int F_366 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_367 ( V_6 -> V_150 , V_81 , V_217 , V_707 ) ;
}
static int F_368 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_369 ( V_6 -> V_150 , V_81 , V_217 , V_707 ) ;
}
static int F_370 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_808 * V_809 = (struct V_808 * ) V_707 ;
T_16 V_810 ;
V_810 = F_151 ( V_809 -> V_811 ) ;
switch ( V_809 -> V_57 ) {
case V_812 :
break;
case V_813 :
F_245 ( V_6 ) ;
break;
default:
return - V_638 ;
}
return 0 ;
}
static int F_371 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int * V_814 = ( int * ) V_707 ;
int V_815 = ( V_814 [ 0 ] > 0 ) ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) ) {
V_63 = - V_70 ;
goto V_619;
}
if ( V_815 ) {
if ( V_6 -> V_150 -> V_198 == V_199 ) {
V_63 = F_234 ( V_6 , V_814 [ 1 ] , 0 ) ;
goto V_619;
}
V_6 -> V_244 = V_814 [ 1 ] ;
V_63 = F_198 ( V_6 , V_199 ) ;
} else {
if ( V_6 -> V_150 -> V_198 == V_199 )
V_63 = F_198 ( V_6 , V_6 -> V_487 ) ;
}
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_372 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_49 & V_618 )
F_35 ( V_6 ) ;
return 0 ;
}
static int F_373 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 , V_312 = * ( int * ) V_707 ;
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) ) {
V_63 = - V_70 ;
goto V_619;
}
if ( ( V_312 < 0 ) || ( V_312 > V_736 ) )
V_312 = V_672 ;
if ( F_239 ( V_6 -> V_544 ) != V_312 )
V_63 = F_238 ( V_6 , V_312 ) ;
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_374 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_43 = F_239 ( V_6 -> V_544 ) ;
T_17 V_816 , V_817 ;
if ( ! ( V_6 -> V_544 & V_545 ) ) {
snprintf ( V_707 , V_818 ,
L_308 , V_43 ) ;
} else {
switch ( V_43 ) {
case V_543 :
snprintf ( V_707 , V_818 ,
L_309 , V_43 ) ;
break;
case V_672 :
snprintf ( V_707 , V_818 ,
L_310 , V_43 ) ;
break;
default:
V_816 = V_738 [ V_43 - 1 ] / 1000 ;
V_817 = V_734 [ V_43 - 1 ] / 1000 ;
snprintf ( V_707 , V_818 ,
L_311
L_312 ,
V_43 , V_816 , V_817 ) ;
}
}
V_217 -> V_37 . V_284 = strlen ( V_707 ) + 1 ;
return 0 ;
}
static int F_375 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 , V_312 = * ( int * ) V_707 ;
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) ) {
V_63 = - V_70 ;
goto V_619;
}
if ( V_312 == 1 )
V_6 -> V_187 |= V_527 ;
else if ( V_312 == 0 )
V_6 -> V_187 &= ~ V_527 ;
else {
V_63 = - V_31 ;
goto V_619;
}
V_63 = F_235 ( V_6 , 0 ) ;
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_376 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_527 )
snprintf ( V_217 -> V_51 , V_708 , L_313 ) ;
else
snprintf ( V_217 -> V_51 , V_708 , L_314 ) ;
return 0 ;
}
static int F_377 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 , V_312 = * ( int * ) V_707 ;
F_84 ( & V_6 -> V_264 ) ;
if ( ! ( V_6 -> V_49 & V_618 ) ) {
V_63 = - V_70 ;
goto V_619;
}
if ( V_312 == 1 )
V_6 -> V_187 |= V_343 ;
else if ( V_312 == 0 )
V_6 -> V_187 &= ~ V_343 ;
else {
V_63 = - V_31 ;
goto V_619;
}
V_63 = 0 ;
V_619:
F_85 ( & V_6 -> V_264 ) ;
return V_63 ;
}
static int F_378 ( struct V_1 * V_2 ,
struct V_706 * V_81 ,
union V_216 * V_217 , char * V_707 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_343 )
snprintf ( V_217 -> V_51 , V_708 , L_315 ) ;
else
snprintf ( V_217 -> V_51 , V_708 , L_316 ) ;
return 0 ;
}
static struct V_819 * F_379 ( struct V_1 * V_2 )
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
struct V_819 * V_301 ;
T_1 V_351 , V_830 , V_831 , V_832 ;
T_1 V_203 = sizeof( T_1 ) ;
if ( ! V_6 )
return (struct V_819 * ) NULL ;
V_301 = & V_6 -> V_301 ;
if ( ! ( V_6 -> V_49 & V_166 ) ) {
V_301 -> V_833 . V_834 = 0 ;
V_301 -> V_331 . V_835 = 0 ;
V_301 -> V_719 . V_719 = 0 ;
V_301 -> V_719 . V_43 = 0 ;
V_301 -> V_719 . V_720 = 0 ;
V_301 -> V_719 . V_721 = 7 ;
V_301 -> V_719 . V_721 |= V_836 |
V_837 | V_838 ;
return V_301 ;
}
if ( F_26 ( V_6 , V_839 ,
& V_831 , & V_203 ) )
goto V_840;
if ( ! ( V_6 -> V_49 & V_166 ) ) {
V_301 -> V_719 . V_719 = 0 ;
V_301 -> V_719 . V_43 = 0 ;
} else {
if ( F_26 ( V_6 , V_841 ,
& V_351 , & V_203 ) )
goto V_840;
V_301 -> V_719 . V_43 = V_351 + V_352 ;
if ( V_351 < 10 )
V_826 = V_351 * V_820 / 10 ;
else if ( V_351 < 15 )
V_826 = ( V_351 - 10 ) * ( V_821 - V_820 ) / 5 + V_820 ;
else if ( V_351 < 20 )
V_826 = ( V_351 - 15 ) * ( V_822 - V_821 ) / 5 + V_821 ;
else if ( V_351 < 30 )
V_826 = ( V_351 - 20 ) * ( V_823 - V_822 ) /
10 + V_822 ;
else
V_826 = ( V_351 - 30 ) * ( V_825 - V_823 ) /
10 + V_823 ;
if ( F_26 ( V_6 , V_842 ,
& V_830 , & V_203 ) )
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
#ifdef F_123
if ( V_828 == V_829 )
F_327 ( L_317 ) ;
else if ( V_827 == V_829 )
F_327 ( L_318 ) ;
else if ( V_829 != 100 )
F_327 ( L_319 ) ;
else
F_327 ( L_320 ) ;
#endif
V_301 -> V_719 . V_719 = V_829 ;
V_301 -> V_719 . V_43 = V_351 + V_352 ;
}
V_301 -> V_719 . V_720 = 0 ;
V_301 -> V_719 . V_721 = 7 ;
V_301 -> V_719 . V_721 |= V_836 ;
V_301 -> V_833 . V_834 = V_831 ;
if ( F_26 ( V_6 , V_843 ,
& V_832 , & V_203 ) )
goto V_840;
V_301 -> V_331 . V_835 = V_832 ;
return V_301 ;
V_840:
F_327 ( L_288 ) ;
return (struct V_819 * ) NULL ;
}
static void V_688 ( struct V_260 * V_261 )
{
struct V_5 * V_6 =
F_108 ( V_261 , struct V_5 , V_283 . V_261 ) ;
union V_216 V_217 ;
unsigned int V_14 = V_229 ;
if ( V_6 -> V_49 & V_184 )
return;
F_84 ( & V_6 -> V_264 ) ;
F_327 ( L_42 ) ;
F_85 ( & V_6 -> V_264 ) ;
V_217 . V_218 . V_219 = V_220 ;
if ( ! ( V_6 -> V_49 & ( V_165 | V_166 ) ) ||
V_6 -> V_49 & V_483 ||
F_26 ( V_6 , V_276 ,
& V_6 -> V_272 , & V_14 ) ) {
F_114 ( V_217 . V_218 . V_627 ) ;
} else {
memcpy ( V_217 . V_218 . V_627 , V_6 -> V_272 , V_229 ) ;
memcpy ( V_6 -> V_150 -> V_272 , V_6 -> V_272 , V_229 ) ;
V_6 -> V_49 &= ~ V_165 ;
V_6 -> V_49 |= V_166 ;
F_264 ( V_6 -> V_33 ) ;
F_164 ( V_6 -> V_33 ) ;
}
if ( ! ( V_6 -> V_49 & V_166 ) ) {
F_327 ( L_321 ) ;
F_84 ( & V_6 -> V_264 ) ;
if ( V_6 -> V_187 & V_281 )
F_111 ( V_6 , V_6 -> V_267 , V_6 -> V_266 ,
0 ) ;
else
F_111 ( V_6 , NULL , 0 , 0 ) ;
F_85 ( & V_6 -> V_264 ) ;
}
F_100 ( V_6 -> V_33 , V_223 , & V_217 , NULL ) ;
}
static int F_380 ( struct V_119 * V_844 )
{
struct V_845 * V_846 =
(struct V_845 * ) V_844 -> V_847 -> V_37 ;
if ( F_381 ( V_846 -> V_121 ) != V_848 ) {
F_27 (KERN_WARNING DRV_NAME L_322
L_323
L_324 ,
h->version) ;
return 1 ;
}
V_844 -> V_121 = V_846 -> V_121 ;
V_844 -> V_844 . V_37 = V_844 -> V_847 -> V_37 + sizeof( struct V_845 ) ;
V_844 -> V_844 . V_477 = V_846 -> V_849 ;
V_844 -> V_850 . V_37 = V_844 -> V_844 . V_37 + V_846 -> V_849 ;
V_844 -> V_850 . V_477 = V_846 -> V_851 ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 ,
struct V_119 * V_844 )
{
char * V_852 ;
int V_853 ;
F_31 ( L_325 ,
V_6 -> V_33 -> V_51 ) ;
switch ( V_6 -> V_150 -> V_198 ) {
case V_430 :
V_852 = F_382 ( L_326 ) ;
break;
#ifdef F_155
case V_199 :
V_852 = F_382 ( L_327 ) ;
break;
#endif
case V_425 :
default:
V_852 = F_382 ( L_50 ) ;
break;
}
V_853 = F_383 ( & V_844 -> V_847 , V_852 , & V_6 -> V_259 -> V_2 ) ;
if ( V_853 < 0 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_328 ,
priv->net_dev->name, fw_name) ;
return V_853 ;
}
F_31 ( L_329 , V_844 -> V_847 -> V_37 ,
V_844 -> V_847 -> V_477 ) ;
F_380 ( V_844 ) ;
return 0 ;
}
static void F_66 ( struct V_5 * V_6 ,
struct V_119 * V_844 )
{
V_844 -> V_121 = 0 ;
F_384 ( V_844 -> V_847 ) ;
V_844 -> V_847 = NULL ;
}
static int F_272 ( struct V_5 * V_6 , char * V_15 ,
T_4 V_854 )
{
char V_855 [ V_856 ] ;
T_1 V_14 = V_856 ;
T_1 V_313 ;
int V_19 ;
if ( F_26 ( V_6 , V_857 , V_855 , & V_14 ) )
return - V_70 ;
V_313 = V_854 ;
if ( V_14 >= V_854 )
V_14 = V_854 - 1 ;
for ( V_19 = 0 ; V_19 < V_14 ; V_19 ++ )
V_15 [ V_19 ] = V_855 [ V_19 ] ;
V_15 [ V_19 ] = '\0' ;
return V_313 ;
}
static int F_273 ( struct V_5 * V_6 , char * V_15 ,
T_4 V_854 )
{
T_1 V_855 ;
T_1 V_14 = sizeof( V_855 ) ;
if ( F_26 ( V_6 , V_858 , & V_855 , & V_14 ) )
return - V_70 ;
return snprintf ( V_15 , V_854 , L_14 , V_855 ) ;
}
static int F_65 ( struct V_5 * V_6 , struct V_119 * V_844 )
{
unsigned int V_8 ;
unsigned short V_14 ;
const unsigned char * V_859 = V_844 -> V_844 . V_37 ;
unsigned int V_860 = V_844 -> V_844 . V_477 ;
while ( V_860 > 0 ) {
V_8 = * ( T_1 * ) ( V_859 ) ;
V_859 += 4 ;
V_860 -= 4 ;
V_14 = * ( T_2 * ) ( V_859 ) ;
V_859 += 2 ;
V_860 -= 2 ;
if ( V_14 > 32 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_330 ,
len) ;
return - V_31 ;
}
F_23 ( V_6 -> V_33 , V_8 , V_14 , V_859 ) ;
V_859 += V_14 ;
V_860 -= V_14 ;
}
return 0 ;
}
static int F_64 ( struct V_5 * V_6 ,
struct V_119 * V_844 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
const unsigned char * V_861 = V_844 -> V_850 . V_37 ;
unsigned int V_862 = V_844 -> V_850 . V_477 ;
void T_12 * V_3 = V_6 -> V_7 ;
struct V_863 V_864 ;
int V_19 , V_40 ;
T_3 V_37 ;
F_18 ( V_2 , V_174 , 0x703 ) ;
F_385 ( V_3 ) ;
F_18 ( V_2 , V_174 , 0x707 ) ;
F_385 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_385 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_385 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x40 ) ;
F_385 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x0 ) ;
F_385 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x40 ) ;
F_385 ( V_3 ) ;
while ( V_862 > 0 ) {
F_20 ( V_2 , 0x210010 , * V_861 ++ ) ;
F_20 ( V_2 , 0x210010 , * V_861 ++ ) ;
V_862 -= 2 ;
}
F_20 ( V_2 , 0x210000 , 0x0 ) ;
F_385 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x0 ) ;
F_385 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x80 ) ;
F_385 ( V_3 ) ;
F_18 ( V_2 , V_174 , 0x703 ) ;
F_385 ( V_3 ) ;
F_18 ( V_2 , V_174 , 0x707 ) ;
F_385 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_385 ( V_3 ) ;
F_20 ( V_2 , 0x210014 , 0x72 ) ;
F_385 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x00 ) ;
F_385 ( V_3 ) ;
F_20 ( V_2 , 0x210000 , 0x80 ) ;
for ( V_19 = 0 ; V_19 < 10 ; V_19 ++ ) {
F_58 ( 10 ) ;
F_19 ( V_2 , 0x210000 , & V_37 ) ;
if ( V_37 & 0x1 )
break;
}
if ( V_19 == 10 ) {
F_27 (KERN_ERR DRV_NAME L_331 ,
dev->name) ;
return - V_70 ;
}
for ( V_19 = 0 ; V_19 < 30 ; V_19 ++ ) {
for ( V_40 = 0 ;
V_40 < ( sizeof( struct V_863 ) >> 1 ) ; V_40 ++ )
F_17 ( V_2 , 0x210004 , ( ( T_2 * ) & V_864 ) + V_40 ) ;
if ( ( V_864 . V_865 == 1 ) && ( V_864 . V_866 == 0x1 ) )
break;
F_58 ( 10 ) ;
}
if ( V_19 == 30 ) {
F_27 (KERN_ERR DRV_NAME
L_332 ,
dev->name) ;
F_33 ( V_867 , ( T_3 * ) & V_864 , sizeof( V_864 ) ) ;
return - V_70 ;
}
return 0 ;
}
