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
V_267 = V_269 ;
V_266 = F_26 ( V_6 , V_274 ,
V_268 , & V_267 ) ;
if ( V_266 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
V_14 = sizeof( T_1 ) ;
V_266 = F_26 ( V_6 , V_275 , & V_270 , & V_14 ) ;
if ( V_266 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
V_14 = sizeof( T_1 ) ;
V_266 = F_26 ( V_6 , V_276 , & V_271 , & V_14 ) ;
if ( V_266 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
V_14 = V_230 ;
V_266 = F_26 ( V_6 , V_277 , V_273 ,
& V_14 ) ;
if ( V_266 ) {
F_31 ( L_46 ,
__LINE__ ) ;
return;
}
memcpy ( V_6 -> V_150 -> V_273 , V_273 , V_230 ) ;
switch ( V_270 ) {
case V_278 :
V_272 = L_90 ;
break;
case V_279 :
V_272 = L_91 ;
break;
case V_280 :
V_272 = L_92 ;
break;
case V_281 :
V_272 = L_93 ;
break;
default:
F_31 ( L_94 , V_270 ) ;
V_272 = L_95 ;
break;
}
F_31 ( L_96 ,
V_6 -> V_33 -> V_51 , V_267 , V_268 ,
V_272 , V_271 , V_273 ) ;
if ( ! ( V_6 -> V_187 & V_282 ) ) {
V_6 -> V_267 = F_34 ( ( T_3 ) V_267 , ( T_3 ) V_269 ) ;
memcpy ( V_6 -> V_268 , V_268 , V_6 -> V_267 ) ;
}
V_6 -> V_245 = V_271 ;
memcpy ( V_6 -> V_273 , V_273 , V_230 ) ;
V_6 -> V_49 |= V_165 ;
V_6 -> V_283 = F_36 () ;
F_39 ( & V_6 -> V_284 , V_53 / 10 ) ;
}
static int F_111 ( struct V_5 * V_6 , char * V_268 ,
int V_285 , int V_286 )
{
int V_287 = F_34 ( V_285 , V_269 ) ;
struct V_56 V_57 = {
. V_56 = V_288 ,
. V_88 = 0 ,
. V_65 = V_287
} ;
int V_63 ;
F_42 ( L_97 , V_287 , V_268 ) ;
if ( V_287 )
memcpy ( V_57 . V_67 , V_268 , V_287 ) ;
if ( ! V_286 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
if ( ! V_287 && ! ( V_6 -> V_187 & V_188 ) ) {
int V_19 ;
T_3 * V_289 = ( T_3 * ) V_57 . V_67 ;
for ( V_19 = 0 ; V_19 < V_269 ; V_19 ++ )
V_289 [ V_19 ] = 0x18 + V_19 ;
V_57 . V_65 = V_269 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_63 ) {
memset ( V_6 -> V_268 + V_287 , 0 , V_269 - V_287 ) ;
memcpy ( V_6 -> V_268 , V_268 , V_287 ) ;
V_6 -> V_267 = V_287 ;
}
if ( ! V_286 ) {
if ( F_83 ( V_6 ) )
V_63 = - V_70 ;
}
return V_63 ;
}
static void F_112 ( struct V_5 * V_6 , T_1 V_49 )
{
F_113 ( V_290 | V_291 | V_292 ,
L_98 , V_6 -> V_267 , V_6 -> V_268 ,
V_6 -> V_273 ) ;
V_6 -> V_49 &= ~ ( V_166 | V_165 ) ;
if ( V_6 -> V_49 & V_184 ) {
F_31 ( L_99 ) ;
return;
}
F_114 ( V_6 -> V_273 ) ;
F_114 ( V_6 -> V_150 -> V_273 ) ;
F_37 ( V_6 -> V_33 ) ;
F_38 ( V_6 -> V_33 ) ;
if ( ! ( V_6 -> V_49 & V_72 ) )
return;
if ( V_6 -> V_49 & V_264 )
F_39 ( & V_6 -> V_293 , 0 ) ;
F_39 ( & V_6 -> V_284 , 0 ) ;
}
static void F_115 ( struct V_5 * V_6 , T_1 V_49 )
{
F_31 ( L_100 ,
V_6 -> V_33 -> V_51 ) ;
F_74 ( V_6 -> V_150 -> V_151 . V_152 , true ) ;
V_6 -> V_49 |= V_153 ;
V_6 -> V_215 = 0 ;
F_116 ( V_294 , & V_6 -> V_216 , F_97 ( V_53 ) ) ;
}
static void F_117 ( struct V_261 * V_262 )
{
struct V_5 * V_6 = F_108 ( V_262 , struct V_5 ,
V_295 . V_262 ) ;
union V_217 V_218 ;
V_218 . V_37 . V_285 = 0 ;
V_218 . V_37 . V_62 = 0 ;
F_100 ( V_6 -> V_33 , V_296 , & V_218 , NULL ) ;
}
static void F_118 ( struct V_5 * V_6 , T_1 V_49 )
{
F_91 ( L_101 ) ;
V_6 -> V_150 -> V_297 ++ ;
V_6 -> V_49 &= ~ V_200 ;
if ( ! V_6 -> V_298 ) {
F_39 ( & V_6 -> V_295 ,
F_97 ( F_55 ( 4000 ) ) ) ;
} else {
V_6 -> V_298 = 0 ;
F_116 ( V_294 , & V_6 -> V_295 , 0 ) ;
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
if ( V_49 == V_299 &&
V_6 -> V_49 & V_166 &&
! ( V_6 -> V_49 & V_200 ) ) {
F_31 ( L_103
L_104 ) ;
F_35 ( V_6 ) ;
}
for ( V_19 = 0 ; V_300 [ V_19 ] . V_49 != - 1 ; V_19 ++ ) {
if ( V_49 == V_300 [ V_19 ] . V_49 ) {
F_121 ( L_105 ,
V_300 [ V_19 ] . V_51 ) ;
if ( V_300 [ V_19 ] . V_301 )
V_300 [ V_19 ] . V_301 ( V_6 , V_49 ) ;
V_6 -> V_302 . V_49 = V_49 ;
return;
}
}
F_121 ( L_106 , V_49 ) ;
}
static void F_122 ( struct V_5 * V_6 ,
struct V_303 * V_57 )
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
struct V_304 * V_61 )
{
V_61 -> V_305 = F_125 ( sizeof( struct V_306 ) ) ;
if ( ! V_61 -> V_305 )
return - V_240 ;
V_61 -> V_307 = (struct V_306 * ) V_61 -> V_305 -> V_37 ;
V_61 -> V_308 = F_126 ( V_6 -> V_260 , V_61 -> V_305 -> V_37 ,
sizeof( struct V_306 ) ,
V_309 ) ;
if ( F_127 ( V_6 -> V_260 , V_61 -> V_308 ) ) {
F_128 ( V_61 -> V_305 ) ;
return - V_240 ;
}
return 0 ;
}
static void F_129 ( struct V_5 * V_6 )
{
int V_19 ;
if ( ! V_6 -> V_310 [ 0 ] )
return;
for ( V_19 = 0 ; V_19 < 0x30 ; V_19 ++ )
F_130 ( V_6 -> V_310 [ V_19 ] ) ;
V_6 -> V_310 [ 0 ] = NULL ;
}
static int F_131 ( struct V_5 * V_6 )
{
int V_19 ;
if ( V_6 -> V_310 [ 0 ] )
return 1 ;
for ( V_19 = 0 ; V_19 < 0x30 ; V_19 ++ ) {
V_6 -> V_310 [ V_19 ] = F_132 ( 0x1000 , V_311 ) ;
if ( ! V_6 -> V_310 [ V_19 ] ) {
F_31 ( L_108
L_109 , V_6 -> V_33 -> V_51 , V_19 ) ;
while ( V_19 > 0 )
F_130 ( V_6 -> V_310 [ -- V_19 ] ) ;
V_6 -> V_310 [ 0 ] = NULL ;
return 0 ;
}
}
return 1 ;
}
static T_1 F_133 ( struct V_5 * V_6 , T_3 * V_312 ,
T_4 V_14 , int V_313 )
{
T_1 V_19 , V_40 ;
T_1 V_314 ;
T_3 * V_315 , * V_316 ;
T_1 V_266 ;
V_315 = V_312 ;
if ( V_313 == V_317 ) {
if ( ! F_131 ( V_6 ) )
V_313 = V_318 ;
}
for ( V_266 = V_319 , V_19 = 0 ; V_19 < 0x30000 ; V_19 += 4 ) {
F_15 ( V_6 -> V_33 , V_19 , & V_314 ) ;
if ( V_313 == V_317 )
* ( T_1 * ) F_134 ( V_19 ) = V_314 ;
if ( V_266 == V_319 ) {
V_316 = ( T_3 * ) & V_314 ;
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
if ( * V_315 != * V_316 ) {
V_315 = V_312 ;
continue;
}
V_315 ++ ;
V_316 ++ ;
if ( ( V_315 - V_312 ) == V_14 )
V_266 = ( V_19 + V_40 ) - V_14 + 1 ;
}
} else if ( V_313 == V_318 )
return V_266 ;
}
return V_266 ;
}
static void F_135 ( struct V_5 * V_6 , int V_19 )
{
#ifdef F_136
struct V_320 * V_49 = & V_6 -> V_321 . V_322 [ V_19 ] ;
T_1 V_323 , V_3 ;
int V_40 ;
#endif
F_31 ( L_110 ,
V_19 * sizeof( struct V_320 ) ) ;
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
V_323 = F_133 ( V_6 , ( T_3 * ) V_49 ,
sizeof( struct V_320 ) ,
V_317 ) ;
if ( V_323 < V_324 )
F_31 ( L_111
L_112 ,
V_6 -> V_33 -> V_51 , V_323 ,
sizeof( struct V_320 ) ) ;
else
F_31 ( L_113
L_114 , V_6 -> V_33 -> V_51 ) ;
F_33 ( ( T_3 * ) V_6 -> V_321 . V_322 ,
sizeof( struct V_320 ) * V_325 ) ;
#endif
V_6 -> V_69 = V_326 ;
V_6 -> V_33 -> V_327 . V_328 ++ ;
F_35 ( V_6 ) ;
}
static void F_137 ( struct V_5 * V_6 , int V_19 ,
struct V_329 * V_327 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
struct V_320 * V_49 = & V_6 -> V_321 . V_322 [ V_19 ] ;
struct V_304 * V_61 = & V_6 -> V_330 [ V_19 ] ;
F_138 ( L_115 ) ;
if ( F_139 ( V_49 -> V_331 > F_140 ( V_61 -> V_305 ) ) ) {
F_31 ( L_116
L_117 ,
V_2 -> V_51 ,
V_49 -> V_331 , F_140 ( V_61 -> V_305 ) ) ;
V_2 -> V_327 . V_328 ++ ;
return;
}
if ( F_139 ( ! F_141 ( V_2 ) ) ) {
V_2 -> V_327 . V_328 ++ ;
V_6 -> V_302 . V_332 . V_333 ++ ;
F_142 ( L_118 ) ;
return;
}
if ( F_139 ( V_6 -> V_150 -> V_198 != V_199 &&
! ( V_6 -> V_49 & V_166 ) ) ) {
F_142 ( L_119 ) ;
V_6 -> V_302 . V_332 . V_333 ++ ;
return;
}
F_143 ( V_6 -> V_260 ,
V_61 -> V_308 ,
sizeof( struct V_306 ) , V_309 ) ;
F_144 ( V_61 -> V_305 , V_49 -> V_331 ) ;
#ifdef F_145
F_146 ( V_61 -> V_305 , V_334 ,
F_147 ( T_1 , V_49 -> V_331 ,
V_335 ) ) ;
#endif
if ( ! F_148 ( V_6 -> V_150 , V_61 -> V_305 , V_327 ) ) {
#ifdef F_145
F_142 ( L_120 ,
V_2 -> V_51 ) ;
F_33 ( V_336 , V_334 , V_49 -> V_331 ) ;
#endif
V_2 -> V_327 . V_328 ++ ;
F_149 ( V_61 -> V_305 ) ;
V_61 -> V_305 = NULL ;
}
if ( F_139 ( F_124 ( V_6 , V_61 ) ) ) {
F_27 (KERN_WARNING DRV_NAME L_67
L_121
L_122 , dev->name) ;
F_31 ( L_123 ) ;
}
V_6 -> V_337 . V_322 [ V_19 ] . V_338 = V_61 -> V_308 ;
}
static void F_150 ( struct V_5 * V_6 , int V_19 ,
struct V_329 * V_327 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
struct V_320 * V_49 = & V_6 -> V_321 . V_322 [ V_19 ] ;
struct V_304 * V_61 = & V_6 -> V_330 [ V_19 ] ;
struct V_339 {
struct V_340 V_341 ;
T_5 V_342 ;
} * V_343 ;
F_138 ( L_115 ) ;
if ( F_139 ( V_49 -> V_331 > F_140 ( V_61 -> V_305 ) -
sizeof( struct V_339 ) ) ) {
F_31 ( L_116
L_117 ,
V_2 -> V_51 ,
V_49 -> V_331 ,
F_140 ( V_61 -> V_305 ) ) ;
V_2 -> V_327 . V_328 ++ ;
return;
}
if ( F_139 ( ! F_141 ( V_2 ) ) ) {
V_2 -> V_327 . V_328 ++ ;
V_6 -> V_302 . V_332 . V_333 ++ ;
F_142 ( L_118 ) ;
return;
}
if ( F_139 ( V_6 -> V_187 & V_344 &&
V_49 -> V_62 & V_345 ) ) {
F_138 ( L_124 ) ;
V_2 -> V_327 . V_328 ++ ;
return;
}
F_143 ( V_6 -> V_260 , V_61 -> V_308 ,
sizeof( struct V_306 ) , V_309 ) ;
memmove ( V_61 -> V_305 -> V_37 + sizeof( struct V_339 ) ,
V_61 -> V_305 -> V_37 , V_49 -> V_331 ) ;
V_343 = (struct V_339 * ) V_61 -> V_305 -> V_37 ;
V_343 -> V_341 . V_346 = V_347 ;
V_343 -> V_341 . V_348 = 0 ;
V_343 -> V_341 . V_349 = F_151 ( sizeof( struct V_339 ) ) ;
V_343 -> V_341 . V_350 = F_152 ( 1 << V_351 ) ;
V_343 -> V_342 = V_49 -> V_352 + V_353 ;
F_144 ( V_61 -> V_305 , V_49 -> V_331 + sizeof( struct V_339 ) ) ;
if ( ! F_148 ( V_6 -> V_150 , V_61 -> V_305 , V_327 ) ) {
V_2 -> V_327 . V_328 ++ ;
F_149 ( V_61 -> V_305 ) ;
V_61 -> V_305 = NULL ;
}
if ( F_139 ( F_124 ( V_6 , V_61 ) ) ) {
F_153 (
L_121
L_122 , V_2 -> V_51 ) ;
F_31 ( L_123 ) ;
}
V_6 -> V_337 . V_322 [ V_19 ] . V_338 = V_61 -> V_308 ;
}
static int F_154 ( struct V_5 * V_6 , int V_19 )
{
struct V_320 * V_49 = & V_6 -> V_321 . V_322 [ V_19 ] ;
struct V_306 * V_354 = V_6 -> V_330 [ V_19 ] . V_307 ;
T_2 V_355 = V_49 -> V_356 & V_357 ;
switch ( V_355 ) {
case V_358 :
return ( V_49 -> V_331 != sizeof( V_354 -> V_359 . V_360 ) ) ;
case V_361 :
return ( V_49 -> V_331 != sizeof( V_354 -> V_359 . V_49 ) ) ;
case V_362 :
return ( V_49 -> V_331 < sizeof( V_354 -> V_359 . V_363 ) ) ;
case V_364 :
case V_365 :
#ifdef F_155
return 0 ;
#else
switch ( F_156 ( F_157 ( V_354 -> V_359 . V_366 . V_367 ) ) ) {
case V_368 :
case V_369 :
return 0 ;
case V_370 :
return ( V_49 -> V_331 >
V_371 ) ;
}
#endif
}
return 1 ;
}
static void F_158 ( struct V_5 * V_6 )
{
struct V_372 * V_373 = & V_6 -> V_337 ;
struct V_374 * V_375 = & V_6 -> V_321 ;
struct V_304 * V_61 ;
T_2 V_355 ;
T_1 V_109 , V_376 , V_19 , V_315 ;
struct V_306 * V_354 ;
struct V_329 V_327 = {
. V_377 = V_80 ,
} ;
F_1 ( V_6 -> V_33 , V_378 , & V_109 ) ;
F_1 ( V_6 -> V_33 , V_379 , & V_376 ) ;
if ( V_109 >= V_373 -> V_380 ) {
F_138 ( L_125 ) ;
return;
}
V_19 = ( V_373 -> V_77 + 1 ) % V_373 -> V_380 ;
V_315 = V_19 ;
while ( V_19 != V_109 ) {
V_61 = & V_6 -> V_330 [ V_19 ] ;
F_159 ( V_6 -> V_260 , V_61 -> V_308 ,
sizeof( struct V_306 ) ,
V_309 ) ;
if ( F_139 ( F_154 ( V_6 , V_19 ) ) ) {
F_135 ( V_6 , V_19 ) ;
goto V_381;
}
V_354 = V_61 -> V_307 ;
V_355 = V_375 -> V_322 [ V_19 ] . V_356 & V_357 ;
V_327 . V_352 = V_375 -> V_322 [ V_19 ] . V_352 + V_353 ;
V_327 . V_14 = V_375 -> V_322 [ V_19 ] . V_331 ;
V_327 . V_382 = 0 ;
if ( V_327 . V_352 != 0 )
V_327 . V_382 |= V_383 ;
V_327 . V_243 = V_211 ;
F_138 ( L_126 ,
V_6 -> V_33 -> V_51 , V_384 [ V_355 ] ,
V_327 . V_14 ) ;
switch ( V_355 ) {
case V_358 :
F_122 ( V_6 , & V_354 -> V_359 . V_360 ) ;
break;
case V_361 :
F_120 ( V_6 , V_354 -> V_359 . V_49 ) ;
break;
case V_364 :
case V_365 :
#ifdef F_155
if ( V_6 -> V_150 -> V_198 == V_199 ) {
F_150 ( V_6 , V_19 , & V_327 ) ;
break;
}
#endif
if ( V_327 . V_14 < sizeof( struct V_385 ) )
break;
switch ( F_156 ( F_157 ( V_354 -> V_359 . V_366 . V_367 ) ) ) {
case V_368 :
F_160 ( V_6 -> V_150 ,
& V_354 -> V_359 . V_366 , & V_327 ) ;
break;
case V_369 :
break;
case V_370 :
F_137 ( V_6 , V_19 , & V_327 ) ;
break;
}
break;
}
V_381:
V_373 -> V_322 [ V_19 ] . V_49 . V_81 . V_386 = 0 ;
V_19 = ( V_19 + 1 ) % V_373 -> V_380 ;
}
if ( V_19 != V_315 ) {
V_373 -> V_77 = ( V_19 ? V_19 : V_373 -> V_380 ) - 1 ;
F_5 ( V_6 -> V_33 ,
V_379 , V_373 -> V_77 ) ;
}
}
static int F_161 ( struct V_5 * V_6 )
{
struct V_372 * V_387 = & V_6 -> V_388 ;
struct V_389 * V_390 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
int V_391 ;
int V_392 , V_19 ;
T_1 V_109 , V_376 , V_393 = 0 ;
if ( F_44 ( & V_6 -> V_394 ) )
return 0 ;
V_59 = V_6 -> V_394 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
V_390 = & V_387 -> V_322 [ V_61 -> V_395 ] ;
switch ( V_61 -> type ) {
case V_396 :
V_391 = 1 ;
V_392 = V_387 -> V_397 ;
break;
case V_398 :
V_391 = V_390 -> V_399 ;
V_393 = V_390 -> V_399 - 1 ;
V_392 = V_387 -> V_397 + V_393 ;
V_392 %= V_387 -> V_380 ;
break;
default:
F_27 (KERN_WARNING DRV_NAME L_127 ,
priv->net_dev->name) ;
return 0 ;
}
F_1 ( V_6 -> V_33 , V_400 ,
& V_109 ) ;
F_1 ( V_6 -> V_33 , V_401 ,
& V_376 ) ;
if ( V_376 != V_387 -> V_77 )
F_27 (KERN_WARNING DRV_NAME L_128 ,
priv->net_dev->name) ;
if ( ! ( ( V_109 <= V_376 && ( V_392 < V_109 || V_392 >= V_376 ) ) || ( V_392 < V_109 && V_392 >= V_376 ) ) ) {
F_162 ( L_129 ) ;
return 0 ;
}
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_402 ) ;
#ifdef F_123
{
V_19 = V_387 -> V_397 ;
F_162 ( L_130 , V_19 ,
& V_387 -> V_322 [ V_19 ] ,
( T_1 ) ( V_387 -> V_403 + V_19 * sizeof( struct V_389 ) ) ,
V_387 -> V_322 [ V_19 ] . V_338 , V_387 -> V_322 [ V_19 ] . V_404 ) ;
if ( V_61 -> type == V_398 ) {
V_19 = ( V_19 + 1 ) % V_387 -> V_380 ;
F_162 ( L_130 , V_19 ,
& V_387 -> V_322 [ V_19 ] ,
( T_1 ) ( V_387 -> V_403 + V_19 *
sizeof( struct V_389 ) ) ,
( T_1 ) V_387 -> V_322 [ V_19 ] . V_338 ,
V_387 -> V_322 [ V_19 ] . V_404 ) ;
}
}
#endif
switch ( V_61 -> type ) {
case V_398 :
if ( V_387 -> V_322 [ V_387 -> V_397 ] . V_49 . V_81 . V_405 . V_406 != 0 )
F_27 (KERN_WARNING DRV_NAME L_131
L_132
L_133 ,
priv->net_dev->name, txq->oldest, packet->index) ;
for ( V_19 = 0 ; V_19 < V_393 ; V_19 ++ ) {
V_390 = & V_387 -> V_322 [ ( V_61 -> V_395 + 1 + V_19 ) % V_387 -> V_380 ] ;
F_162 ( L_134 ,
( V_61 -> V_395 + 1 + V_19 ) % V_387 -> V_380 ,
V_390 -> V_338 , V_390 -> V_404 ) ;
F_143 ( V_6 -> V_260 ,
V_390 -> V_338 ,
V_390 -> V_404 , V_407 ) ;
}
F_163 ( V_61 -> V_81 . V_408 . V_409 ) ;
V_61 -> V_81 . V_408 . V_409 = NULL ;
F_48 ( V_59 , & V_6 -> V_410 ) ;
F_49 ( & V_6 -> V_411 ) ;
if ( V_6 -> V_49 & V_166 )
F_164 ( V_6 -> V_33 ) ;
V_6 -> V_33 -> V_412 = V_80 ;
break;
case V_396 :
if ( V_387 -> V_322 [ V_387 -> V_397 ] . V_49 . V_81 . V_405 . V_406 != 1 )
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
V_61 -> V_81 . V_82 . V_57 -> V_413 ) ;
#endif
F_48 ( V_59 , & V_6 -> V_75 ) ;
F_49 ( & V_6 -> V_90 ) ;
break;
}
V_387 -> V_397 = ( V_392 + 1 ) % V_387 -> V_380 ;
V_387 -> V_414 += V_391 ;
F_165 ( & V_6 -> V_415 , V_387 -> V_414 ) ;
F_162 ( L_137 ,
V_80 - V_61 -> V_79 ) ;
return ( ! F_44 ( & V_6 -> V_394 ) ) ;
}
static inline void F_166 ( struct V_5 * V_6 )
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
struct V_372 * V_387 = & V_6 -> V_388 ;
struct V_389 * V_390 ;
int V_77 = V_387 -> V_77 ;
while ( ! F_44 ( & V_6 -> V_91 ) ) {
if ( V_387 -> V_414 <= 3 ) {
F_162 ( L_139 ) ;
break;
}
V_59 = V_6 -> V_91 . V_77 ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_92 ) ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
F_162 ( L_140 ,
& V_387 -> V_322 [ V_387 -> V_77 ] ,
( T_1 ) ( V_387 -> V_403 + V_387 -> V_77 *
sizeof( struct V_389 ) ) ) ;
V_61 -> V_395 = V_387 -> V_77 ;
V_390 = & V_387 -> V_322 [ V_387 -> V_77 ] ;
V_390 -> V_338 = V_61 -> V_81 . V_82 . V_416 ;
V_390 -> V_404 = sizeof( struct V_303 ) ;
V_390 -> V_399 = 1 ;
V_390 -> V_49 . V_81 . V_386 =
V_417 |
V_418 ;
V_387 -> V_77 ++ ;
V_387 -> V_77 %= V_387 -> V_380 ;
V_387 -> V_414 -- ;
F_47 ( & V_6 -> V_415 ) ;
F_48 ( V_59 , & V_6 -> V_394 ) ;
F_49 ( & V_6 -> V_402 ) ;
}
if ( V_387 -> V_77 != V_77 ) {
F_167 () ;
F_5 ( V_6 -> V_33 ,
V_401 ,
V_387 -> V_77 ) ;
}
}
static void F_51 ( struct V_5 * V_6 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_372 * V_387 = & V_6 -> V_388 ;
struct V_389 * V_390 ;
int V_77 = V_387 -> V_77 ;
int V_19 = 0 ;
struct V_419 * V_420 ;
struct V_385 * V_421 ;
while ( ! F_44 ( & V_6 -> V_422 ) ) {
V_59 = V_6 -> V_422 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
if ( F_139 ( 1 + V_61 -> V_81 . V_408 . V_409 -> V_423 >
V_424 ) ) {
F_31 ( L_141
L_142 ,
V_6 -> V_33 -> V_51 ) ;
}
if ( V_387 -> V_414 <= 3 + V_61 -> V_81 . V_408 . V_409 -> V_423 ) {
F_162 ( L_139 ) ;
break;
}
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_425 ) ;
V_390 = & V_387 -> V_322 [ V_387 -> V_77 ] ;
V_61 -> V_395 = V_387 -> V_77 ;
V_420 = V_61 -> V_81 . V_408 . V_37 ;
V_421 = (struct V_385 * ) V_61 -> V_81 . V_408 . V_409 ->
V_426 [ 0 ] -> V_37 ;
if ( V_6 -> V_150 -> V_198 == V_427 ) {
memcpy ( V_420 -> V_428 , V_421 -> V_429 , V_230 ) ;
memcpy ( V_420 -> V_430 , V_421 -> V_431 , V_230 ) ;
} else if ( V_6 -> V_150 -> V_198 == V_432 ) {
memcpy ( V_420 -> V_428 , V_421 -> V_429 , V_230 ) ;
memcpy ( V_420 -> V_430 , V_421 -> V_433 , V_230 ) ;
}
V_420 -> V_83 = V_434 ;
V_420 -> V_84 = 0 ;
V_420 -> V_435 = 0 ;
V_420 -> V_436 = V_61 -> V_81 . V_408 . V_409 -> V_436 ;
if ( V_61 -> V_81 . V_408 . V_409 -> V_423 > 1 )
V_420 -> V_437 =
V_61 -> V_81 . V_408 . V_409 -> V_438 -
V_439 ;
else
V_420 -> V_437 = 0 ;
V_390 -> V_338 = V_61 -> V_81 . V_408 . V_440 ;
V_390 -> V_404 = sizeof( struct V_419 ) ;
V_390 -> V_399 = 1 + V_61 -> V_81 . V_408 . V_409 -> V_423 ;
V_390 -> V_49 . V_81 . V_386 =
V_441 |
V_442 ;
V_387 -> V_77 ++ ;
V_387 -> V_77 %= V_387 -> V_380 ;
F_162 ( L_143 ,
V_61 -> V_395 , V_390 -> V_338 , V_390 -> V_404 ) ;
#ifdef F_123
if ( V_61 -> V_81 . V_408 . V_409 -> V_423 > 1 )
F_168 ( L_144 ,
V_61 -> V_81 . V_408 . V_409 -> V_423 ) ;
#endif
for ( V_19 = 0 ; V_19 < V_61 -> V_81 . V_408 . V_409 -> V_423 ; V_19 ++ ) {
V_390 = & V_387 -> V_322 [ V_387 -> V_77 ] ;
if ( V_19 == V_61 -> V_81 . V_408 . V_409 -> V_423 - 1 )
V_390 -> V_49 . V_81 . V_386 =
V_441 |
V_418 ;
else
V_390 -> V_49 . V_81 . V_386 =
V_441 |
V_442 ;
V_390 -> V_404 = V_61 -> V_81 . V_408 . V_409 ->
V_426 [ V_19 ] -> V_14 - V_439 ;
V_390 -> V_338 = F_126 ( V_6 -> V_260 ,
V_61 -> V_81 . V_408 .
V_409 -> V_426 [ V_19 ] ->
V_37 +
V_439 ,
V_390 -> V_404 ,
V_407 ) ;
if ( F_127 ( V_6 -> V_260 ,
V_390 -> V_338 ) ) {
F_162 ( L_145 ) ;
break;
}
F_162 ( L_146 ,
V_387 -> V_77 , V_390 -> V_338 ,
V_390 -> V_404 ) ;
F_169 ( V_6 -> V_260 ,
V_390 -> V_338 ,
V_390 -> V_404 ,
V_407 ) ;
V_387 -> V_77 ++ ;
V_387 -> V_77 %= V_387 -> V_380 ;
}
V_387 -> V_414 -= 1 + V_61 -> V_81 . V_408 . V_409 -> V_423 ;
F_165 ( & V_6 -> V_415 , V_387 -> V_414 ) ;
F_48 ( V_59 , & V_6 -> V_394 ) ;
F_49 ( & V_6 -> V_402 ) ;
}
if ( V_387 -> V_77 != V_77 ) {
F_5 ( V_6 -> V_33 ,
V_401 ,
V_387 -> V_77 ) ;
}
}
static void F_170 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
unsigned long V_62 ;
T_1 V_157 , V_314 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
F_68 ( V_6 ) ;
F_1 ( V_2 , V_160 , & V_157 ) ;
F_171 ( L_147 ,
( unsigned long ) V_157 & V_138 ) ;
V_6 -> V_443 ++ ;
V_6 -> V_444 ++ ;
F_171 ( L_148 ,
( unsigned long ) V_157 & V_138 ) ;
if ( V_157 & V_162 ) {
F_27 (KERN_WARNING DRV_NAME
L_149 ) ;
V_6 -> V_445 ++ ;
F_5 ( V_2 , V_160 , V_162 ) ;
F_15 ( V_2 , V_446 , & V_6 -> V_69 ) ;
F_31 ( L_150 ,
V_6 -> V_33 -> V_51 , V_6 -> V_69 ) ;
F_15 ( V_2 , F_172 ( V_6 -> V_69 ) , & V_314 ) ;
F_31 ( L_151 ,
V_6 -> V_33 -> V_51 , V_314 ) ;
F_35 ( V_6 ) ;
}
if ( V_157 & V_163 ) {
F_27 (KERN_ERR DRV_NAME
L_152 ) ;
V_6 -> V_445 ++ ;
F_5 ( V_2 , V_160 , V_163 ) ;
}
if ( V_157 & V_447 ) {
F_171 ( L_153 ) ;
V_6 -> V_448 ++ ;
F_5 ( V_2 , V_160 , V_447 ) ;
F_158 ( V_6 ) ;
F_166 ( V_6 ) ;
}
if ( V_157 & V_449 ) {
F_171 ( L_154 ) ;
V_6 -> V_450 ++ ;
F_5 ( V_2 , V_160 , V_449 ) ;
F_166 ( V_6 ) ;
F_50 ( V_6 ) ;
F_51 ( V_6 ) ;
}
if ( V_157 & V_451 ) {
F_171 ( L_155 ) ;
V_6 -> V_445 ++ ;
F_5 ( V_2 , V_160 , V_451 ) ;
F_166 ( V_6 ) ;
}
if ( V_157 & V_452 ) {
V_6 -> V_445 ++ ;
F_5 ( V_2 , V_160 , V_452 ) ;
}
if ( V_157 & V_161 ) {
F_171 ( L_156 ) ;
V_6 -> V_445 ++ ;
F_1 ( V_2 , V_160 , & V_314 ) ;
if ( V_314 & ( V_162 |
V_163 ) ) {
F_5 ( V_2 , V_160 ,
V_162 |
V_163 ) ;
}
F_5 ( V_2 , V_160 , V_161 ) ;
}
if ( V_157 & V_453 ) {
F_171 ( L_157 ) ;
V_6 -> V_445 ++ ;
F_5 ( V_2 , V_160 , V_453 ) ;
}
if ( V_157 & V_454 ) {
F_171 ( L_158 ) ;
V_6 -> V_445 ++ ;
F_5 ( V_2 , V_160 ,
V_454 ) ;
}
V_6 -> V_443 -- ;
F_67 ( V_6 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
F_171 ( L_45 ) ;
}
static T_6 F_173 ( int V_455 , void * V_37 )
{
struct V_5 * V_6 = V_37 ;
T_1 V_157 , V_158 ;
if ( ! V_37 )
return V_456 ;
F_174 ( & V_6 -> V_68 ) ;
if ( ! ( V_6 -> V_49 & V_136 ) ) {
goto V_457;
}
F_1 ( V_6 -> V_33 , V_137 , & V_158 ) ;
F_1 ( V_6 -> V_33 , V_160 , & V_157 ) ;
if ( V_157 == 0xFFFFFFFF ) {
F_27 (KERN_WARNING DRV_NAME L_159 ) ;
goto V_457;
}
V_157 &= V_138 ;
if ( ! ( V_157 & V_158 ) ) {
goto V_457;
}
F_68 ( V_6 ) ;
F_175 ( & V_6 -> V_458 ) ;
F_176 ( & V_6 -> V_68 ) ;
return V_459 ;
V_457:
F_176 ( & V_6 -> V_68 ) ;
return V_456 ;
}
static T_7 F_177 ( struct V_460 * V_409 ,
struct V_1 * V_2 , int V_461 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
unsigned long V_62 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( ! ( V_6 -> V_49 & V_166 ) ) {
F_31 ( L_160 ) ;
V_6 -> V_33 -> V_327 . V_462 ++ ;
F_38 ( V_2 ) ;
goto V_71;
}
if ( F_44 ( & V_6 -> V_410 ) )
goto V_71;
V_59 = V_6 -> V_410 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
V_61 -> V_81 . V_408 . V_409 = V_409 ;
F_162 ( L_161 , V_409 -> V_426 [ 0 ] -> V_14 ) ;
F_33 ( V_463 , V_409 -> V_426 [ 0 ] -> V_37 , V_409 -> V_426 [ 0 ] -> V_14 ) ;
V_61 -> V_79 = V_80 ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_411 ) ;
F_48 ( V_59 , & V_6 -> V_422 ) ;
F_49 ( & V_6 -> V_425 ) ;
F_51 ( V_6 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
return V_464 ;
V_71:
F_38 ( V_2 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
return V_465 ;
}
static int F_178 ( struct V_5 * V_6 )
{
int V_19 , V_40 , V_63 = - V_31 ;
void * V_466 ;
T_8 V_467 ;
V_6 -> V_468 =
F_132 ( V_469 * sizeof( struct V_60 ) ,
V_239 ) ;
if ( ! V_6 -> V_468 )
return - V_240 ;
for ( V_19 = 0 ; V_19 < V_469 ; V_19 ++ ) {
V_466 = F_179 ( V_6 -> V_260 ,
sizeof( struct V_303 ) ,
& V_467 ) ;
if ( ! V_466 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_162
L_163 , priv->net_dev->name) ;
V_63 = - V_240 ;
break;
}
V_6 -> V_468 [ V_19 ] . type = V_396 ;
V_6 -> V_468 [ V_19 ] . V_81 . V_82 . V_57 =
(struct V_303 * ) V_466 ;
V_6 -> V_468 [ V_19 ] . V_81 . V_82 . V_416 = V_467 ;
}
if ( V_19 == V_469 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_19 ; V_40 ++ ) {
F_180 ( V_6 -> V_260 ,
sizeof( struct V_303 ) ,
V_6 -> V_468 [ V_40 ] . V_81 . V_82 . V_57 ,
V_6 -> V_468 [ V_40 ] . V_81 . V_82 .
V_416 ) ;
}
F_130 ( V_6 -> V_468 ) ;
V_6 -> V_468 = NULL ;
return V_63 ;
}
static int F_181 ( struct V_5 * V_6 )
{
int V_19 ;
F_182 ( & V_6 -> V_75 ) ;
F_182 ( & V_6 -> V_91 ) ;
for ( V_19 = 0 ; V_19 < V_469 ; V_19 ++ )
F_48 ( & V_6 -> V_468 [ V_19 ] . V_78 , & V_6 -> V_75 ) ;
F_165 ( & V_6 -> V_90 , V_19 ) ;
return 0 ;
}
static void F_183 ( struct V_5 * V_6 )
{
int V_19 ;
if ( ! V_6 -> V_468 )
return;
for ( V_19 = 0 ; V_19 < V_469 ; V_19 ++ ) {
F_180 ( V_6 -> V_260 ,
sizeof( struct V_303 ) ,
V_6 -> V_468 [ V_19 ] . V_81 . V_82 . V_57 ,
V_6 -> V_468 [ V_19 ] . V_81 . V_82 .
V_416 ) ;
}
F_130 ( V_6 -> V_468 ) ;
V_6 -> V_468 = NULL ;
}
static T_9 F_184 ( struct V_470 * V_316 , struct V_471 * V_472 ,
char * V_15 )
{
struct V_260 * V_260 = F_108 ( V_316 , struct V_260 , V_2 ) ;
char * V_39 = V_15 ;
int V_19 , V_40 ;
T_1 V_4 ;
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ ) {
V_39 += sprintf ( V_39 , L_164 , V_19 * 16 ) ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 += 4 ) {
F_185 ( V_260 , V_19 * 16 + V_40 , & V_4 ) ;
V_39 += sprintf ( V_39 , L_165 , V_4 ) ;
}
V_39 += sprintf ( V_39 , L_166 ) ;
}
return V_39 - V_15 ;
}
static T_9 F_186 ( struct V_470 * V_316 , struct V_471 * V_472 ,
char * V_15 )
{
struct V_5 * V_467 = F_187 ( V_316 ) ;
return sprintf ( V_15 , L_167 , ( int ) V_467 -> V_187 ) ;
}
static T_9 F_188 ( struct V_470 * V_316 , struct V_471 * V_472 ,
char * V_15 )
{
struct V_5 * V_467 = F_187 ( V_316 ) ;
return sprintf ( V_15 , L_167 , ( int ) V_467 -> V_49 ) ;
}
static T_9 F_189 ( struct V_470 * V_316 , struct V_471 * V_472 ,
char * V_15 )
{
struct V_5 * V_467 = F_187 ( V_316 ) ;
return sprintf ( V_15 , L_167 , ( int ) V_467 -> V_473 ) ;
}
static T_9 F_190 ( struct V_470 * V_316 , struct V_471 * V_472 ,
char * V_15 )
{
int V_19 ;
struct V_5 * V_6 = F_187 ( V_316 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
char * V_39 = V_15 ;
T_1 V_4 = 0 ;
V_39 += sprintf ( V_39 , L_168 , L_169 ) ;
for ( V_19 = 0 ; V_19 < F_104 ( V_474 ) ; V_19 ++ ) {
F_1 ( V_2 , V_474 [ V_19 ] . V_8 , & V_4 ) ;
V_39 += sprintf ( V_39 , L_170 ,
V_474 [ V_19 ] . V_51 , V_474 [ V_19 ] . V_8 , V_4 ) ;
}
return V_39 - V_15 ;
}
static T_9 F_191 ( struct V_470 * V_316 , struct V_471 * V_472 ,
char * V_15 )
{
struct V_5 * V_6 = F_187 ( V_316 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
char * V_39 = V_15 ;
int V_19 ;
V_39 += sprintf ( V_39 , L_168 , L_171 ) ;
for ( V_19 = 0 ; V_19 < F_104 ( V_475 ) ; V_19 ++ ) {
T_3 V_476 ;
T_2 V_477 ;
T_1 V_478 ;
switch ( V_475 [ V_19 ] . V_479 ) {
case 1 :
F_19 ( V_2 , V_475 [ V_19 ] . V_8 , & V_476 ) ;
V_39 += sprintf ( V_39 , L_172 ,
V_475 [ V_19 ] . V_51 , V_475 [ V_19 ] . V_8 ,
V_476 ) ;
break;
case 2 :
F_17 ( V_2 , V_475 [ V_19 ] . V_8 , & V_477 ) ;
V_39 += sprintf ( V_39 , L_173 ,
V_475 [ V_19 ] . V_51 , V_475 [ V_19 ] . V_8 ,
V_477 ) ;
break;
case 4 :
F_15 ( V_2 , V_475 [ V_19 ] . V_8 , & V_478 ) ;
V_39 += sprintf ( V_39 , L_170 ,
V_475 [ V_19 ] . V_51 , V_475 [ V_19 ] . V_8 ,
V_478 ) ;
break;
}
}
return V_39 - V_15 ;
}
static T_9 F_192 ( struct V_470 * V_316 , struct V_471 * V_472 ,
char * V_15 )
{
struct V_5 * V_6 = F_187 ( V_316 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
static unsigned long V_480 = 0 ;
int V_14 = 0 ;
T_1 V_481 [ 4 ] ;
int V_19 ;
char line [ 81 ] ;
if ( V_480 >= 0x30000 )
V_480 = 0 ;
while ( V_14 < V_482 - 128 && V_480 < 0x30000 ) {
if ( V_6 -> V_310 [ 0 ] )
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ )
V_481 [ V_19 ] =
* ( T_1 * ) F_134 ( V_480 + V_19 * 4 ) ;
else
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ )
F_15 ( V_2 , V_480 + V_19 * 4 , & V_481 [ V_19 ] ) ;
if ( V_6 -> V_483 )
V_14 += sprintf ( V_15 + V_14 ,
L_174
L_174
L_174
L_174 ,
( ( T_3 * ) V_481 ) [ 0x0 ] ,
( ( T_3 * ) V_481 ) [ 0x1 ] ,
( ( T_3 * ) V_481 ) [ 0x2 ] ,
( ( T_3 * ) V_481 ) [ 0x3 ] ,
( ( T_3 * ) V_481 ) [ 0x4 ] ,
( ( T_3 * ) V_481 ) [ 0x5 ] ,
( ( T_3 * ) V_481 ) [ 0x6 ] ,
( ( T_3 * ) V_481 ) [ 0x7 ] ,
( ( T_3 * ) V_481 ) [ 0x8 ] ,
( ( T_3 * ) V_481 ) [ 0x9 ] ,
( ( T_3 * ) V_481 ) [ 0xa ] ,
( ( T_3 * ) V_481 ) [ 0xb ] ,
( ( T_3 * ) V_481 ) [ 0xc ] ,
( ( T_3 * ) V_481 ) [ 0xd ] ,
( ( T_3 * ) V_481 ) [ 0xe ] ,
( ( T_3 * ) V_481 ) [ 0xf ] ) ;
else
V_14 += sprintf ( V_15 + V_14 , L_19 ,
F_32 ( line , sizeof( line ) ,
( T_3 * ) V_481 , 16 , V_480 ) ) ;
V_480 += 16 ;
}
return V_14 ;
}
static T_9 F_193 ( struct V_470 * V_316 , struct V_471 * V_472 ,
const char * V_15 , T_4 V_36 )
{
struct V_5 * V_6 = F_187 ( V_316 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
const char * V_467 = V_15 ;
( void ) V_2 ;
if ( V_36 < 1 )
return V_36 ;
if ( V_467 [ 0 ] == '1' ||
( V_36 >= 2 && tolower ( V_467 [ 0 ] ) == 'o' && tolower ( V_467 [ 1 ] ) == 'n' ) ) {
F_31 ( L_175 ,
V_2 -> V_51 ) ;
V_6 -> V_483 = 1 ;
} else if ( V_467 [ 0 ] == '0' || ( V_36 >= 2 && tolower ( V_467 [ 0 ] ) == 'o' &&
tolower ( V_467 [ 1 ] ) == 'f' ) ) {
F_31 ( L_176 ,
V_2 -> V_51 ) ;
V_6 -> V_483 = 0 ;
} else if ( tolower ( V_467 [ 0 ] ) == 'r' ) {
F_31 ( L_177 , V_2 -> V_51 ) ;
F_129 ( V_6 ) ;
} else
F_31 ( L_178
L_179 , V_2 -> V_51 ) ;
return V_36 ;
}
static T_9 F_194 ( struct V_470 * V_316 , struct V_471 * V_472 ,
char * V_15 )
{
struct V_5 * V_6 = F_187 ( V_316 ) ;
T_1 V_4 = 0 ;
int V_14 = 0 ;
T_1 V_484 ;
static int V_480 = 0 ;
if ( V_6 -> V_49 & V_485 )
return 0 ;
if ( V_480 >= F_104 ( V_486 ) )
V_480 = 0 ;
while ( V_14 < V_482 - 128 && V_480 < F_104 ( V_486 ) ) {
V_484 = sizeof( T_1 ) ;
if ( F_26 ( V_6 , V_486 [ V_480 ] . V_395 , & V_4 ,
& V_484 ) )
V_14 += sprintf ( V_15 + V_14 , L_180 ,
V_486 [ V_480 ] . V_395 ,
V_486 [ V_480 ] . V_487 ) ;
else
V_14 += sprintf ( V_15 + V_14 , L_181 ,
V_486 [ V_480 ] . V_395 , V_4 ,
V_486 [ V_480 ] . V_487 ) ;
V_480 ++ ;
}
return V_14 ;
}
static T_9 F_195 ( struct V_470 * V_316 , struct V_471 * V_472 ,
char * V_15 )
{
struct V_5 * V_6 = F_187 ( V_316 ) ;
char * V_39 = V_15 ;
V_39 += sprintf ( V_39 , L_182 ,
V_6 -> V_444 , V_6 -> V_450 ,
V_6 -> V_448 , V_6 -> V_445 ) ;
V_39 += sprintf ( V_39 , L_183 , V_6 -> V_263 ) ;
V_39 += sprintf ( V_39 , L_184 , V_6 -> V_488 ) ;
#ifdef F_123
V_39 += sprintf ( V_39 , L_185 ,
V_6 -> V_310 [ 0 ] ? L_186 : L_187 ) ;
#endif
return V_39 - V_15 ;
}
static int F_196 ( struct V_5 * V_6 , T_1 V_313 )
{
int V_63 ;
if ( V_313 == V_6 -> V_150 -> V_198 )
return 0 ;
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
switch ( V_313 ) {
case V_427 :
V_6 -> V_33 -> type = V_221 ;
break;
case V_432 :
V_6 -> V_33 -> type = V_221 ;
break;
#ifdef F_155
case V_199 :
V_6 -> V_489 = V_6 -> V_150 -> V_198 ;
V_6 -> V_33 -> type = V_490 ;
break;
#endif
}
V_6 -> V_150 -> V_198 = V_313 ;
#ifdef F_61
V_120 . V_121 = 0 ;
#endif
F_27 ( V_214 L_189 , V_6 -> V_33 -> V_51 ) ;
V_6 -> V_47 = 0 ;
F_35 ( V_6 ) ;
return 0 ;
}
static T_9 F_197 ( struct V_470 * V_316 , struct V_471 * V_472 ,
char * V_15 )
{
struct V_5 * V_6 = F_187 ( V_316 ) ;
int V_14 = 0 ;
#define F_198 ( T_10 , T_11 ) len += sprintf(buf + len, # x ": %" y "\n", priv-> x)
if ( V_6 -> V_49 & V_166 )
V_14 += sprintf ( V_15 + V_14 , L_190 ,
F_36 () - V_6 -> V_283 ) ;
else
V_14 += sprintf ( V_15 + V_14 , L_191 ) ;
F_198 ( V_150 -> V_491 . V_492 [ V_6 -> V_150 -> V_491 . V_493 ] , L_192 ) ;
F_198 ( V_49 , L_193 ) ;
F_198 ( V_187 , L_193 ) ;
F_198 ( V_473 , L_193 ) ;
V_14 +=
sprintf ( V_15 + V_14 , L_194 ,
( unsigned long ) V_6 -> V_494 ) ;
F_198 ( V_69 , L_195 ) ;
F_198 ( V_181 , L_195 ) ;
F_198 ( V_215 , L_195 ) ;
F_198 ( V_76 , L_195 ) ;
F_198 ( V_425 . V_147 , L_195 ) ;
F_198 ( V_425 . V_495 , L_195 ) ;
F_198 ( V_411 . V_147 , L_195 ) ;
F_198 ( V_411 . V_496 , L_195 ) ;
F_198 ( V_90 . V_147 , L_195 ) ;
F_198 ( V_90 . V_496 , L_195 ) ;
F_198 ( V_92 . V_147 , L_195 ) ;
F_198 ( V_92 . V_495 , L_195 ) ;
F_198 ( V_402 . V_147 , L_195 ) ;
F_198 ( V_402 . V_495 , L_195 ) ;
F_198 ( V_415 . V_147 , L_195 ) ;
F_198 ( V_415 . V_496 , L_195 ) ;
F_198 ( V_150 -> V_297 , L_195 ) ;
F_198 ( V_47 , L_195 ) ;
return V_14 ;
}
static T_9 F_199 ( struct V_470 * V_316 , struct V_471 * V_472 ,
char * V_15 )
{
struct V_5 * V_6 = F_187 ( V_316 ) ;
char V_268 [ V_269 + 1 ] ;
T_3 V_273 [ V_230 ] ;
T_1 V_271 = 0 ;
char * V_39 = V_15 ;
unsigned int V_285 ;
int V_266 ;
if ( V_6 -> V_49 & V_485 )
return 0 ;
memset ( V_268 , 0 , sizeof( V_268 ) ) ;
memset ( V_273 , 0 , sizeof( V_273 ) ) ;
V_285 = V_269 ;
V_266 = F_26 ( V_6 , V_274 , V_268 , & V_285 ) ;
if ( V_266 )
F_31 ( L_46 ,
__LINE__ ) ;
V_285 = sizeof( V_273 ) ;
V_266 = F_26 ( V_6 , V_277 ,
V_273 , & V_285 ) ;
if ( V_266 )
F_31 ( L_46 ,
__LINE__ ) ;
V_285 = sizeof( T_1 ) ;
V_266 = F_26 ( V_6 , V_276 , & V_271 , & V_285 ) ;
if ( V_266 )
F_31 ( L_46 ,
__LINE__ ) ;
V_39 += sprintf ( V_39 , L_196 , V_268 ) ;
V_39 += sprintf ( V_39 , L_197 , V_273 ) ;
V_39 += sprintf ( V_39 , L_198 , V_271 ) ;
return V_39 - V_15 ;
}
static T_9 F_200 ( struct V_497 * V_316 , char * V_15 )
{
return sprintf ( V_15 , L_199 , V_44 ) ;
}
static T_9 F_201 ( struct V_497 * V_316 ,
const char * V_15 , T_4 V_36 )
{
T_1 V_4 ;
int V_266 ;
V_266 = F_202 ( V_15 , 0 , & V_4 ) ;
if ( V_266 )
F_31 ( L_200 , V_15 ) ;
else
V_44 = V_4 ;
return F_203 ( V_15 , V_36 ) ;
}
static T_9 F_204 ( struct V_470 * V_316 ,
struct V_471 * V_472 , char * V_15 )
{
struct V_5 * V_6 = F_187 ( V_316 ) ;
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
static T_9 F_205 ( struct V_470 * V_316 ,
struct V_471 * V_472 , const char * V_15 ,
T_4 V_36 )
{
struct V_5 * V_6 = F_187 ( V_316 ) ;
F_35 ( V_6 ) ;
return V_36 ;
}
static T_9 F_206 ( struct V_470 * V_316 , struct V_471 * V_472 ,
char * V_15 )
{
struct V_5 * V_6 = F_187 ( V_316 ) ;
return sprintf ( V_15 , L_203 , V_6 -> V_150 -> V_498 ) ;
}
static T_9 F_207 ( struct V_470 * V_316 , struct V_471 * V_472 ,
const char * V_15 , T_4 V_36 )
{
struct V_5 * V_6 = F_187 ( V_316 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
unsigned long V_4 ;
int V_266 ;
( void ) V_2 ;
F_31 ( L_42 ) ;
V_266 = F_208 ( V_15 , 0 , & V_4 ) ;
if ( V_266 ) {
F_31 ( L_204 , V_2 -> V_51 ) ;
} else {
V_6 -> V_150 -> V_498 = V_4 ;
F_31 ( L_205 , V_6 -> V_150 -> V_498 ) ;
}
F_31 ( L_45 ) ;
return F_203 ( V_15 , V_36 ) ;
}
static T_9 F_209 ( struct V_470 * V_316 , struct V_471 * V_472 ,
char * V_15 )
{
struct V_5 * V_6 = F_187 ( V_316 ) ;
int V_4 = ( ( V_6 -> V_49 & V_206 ) ? 0x1 : 0x0 ) |
( F_71 ( V_6 ) ? 0x2 : 0x0 ) ;
return sprintf ( V_15 , L_206 , V_4 ) ;
}
static int F_210 ( struct V_5 * V_6 , int V_499 )
{
if ( ( V_499 ? 1 : 0 ) ==
( V_6 -> V_49 & V_206 ? 1 : 0 ) )
return 0 ;
F_211 ( L_207 ,
V_499 ? L_208 : L_209 ) ;
F_84 ( & V_6 -> V_265 ) ;
if ( V_499 ) {
V_6 -> V_49 |= V_206 ;
F_99 ( V_6 ) ;
} else {
V_6 -> V_49 &= ~ V_206 ;
if ( F_71 ( V_6 ) ) {
F_211 ( L_210
L_211 ) ;
V_6 -> V_215 = 0 ;
F_116 ( V_294 , & V_6 -> V_216 ,
F_97 ( V_53 ) ) ;
} else
F_35 ( V_6 ) ;
}
F_85 ( & V_6 -> V_265 ) ;
return 1 ;
}
static T_9 F_212 ( struct V_470 * V_316 , struct V_471 * V_472 ,
const char * V_15 , T_4 V_36 )
{
struct V_5 * V_6 = F_187 ( V_316 ) ;
F_210 ( V_6 , V_15 [ 0 ] == '1' ) ;
return V_36 ;
}
static int F_213 ( struct V_5 * V_6 , int V_380 )
{
struct V_374 * V_500 = & V_6 -> V_321 ;
F_31 ( L_42 ) ;
V_500 -> V_479 = V_380 * sizeof( struct V_320 ) ;
V_500 -> V_322 = F_179 ( V_6 -> V_260 , V_500 -> V_479 , & V_500 -> V_403 ) ;
if ( ! V_500 -> V_322 ) {
F_153 ( L_212 ) ;
return - V_240 ;
}
F_31 ( L_45 ) ;
return 0 ;
}
static void F_214 ( struct V_5 * V_6 )
{
F_31 ( L_42 ) ;
if ( V_6 -> V_321 . V_322 ) {
F_180 ( V_6 -> V_260 , V_6 -> V_321 . V_479 ,
V_6 -> V_321 . V_322 ,
V_6 -> V_321 . V_403 ) ;
V_6 -> V_321 . V_322 = NULL ;
}
F_31 ( L_45 ) ;
}
static int F_215 ( struct V_5 * V_6 ,
struct V_372 * V_500 , int V_380 )
{
F_31 ( L_42 ) ;
memset ( V_500 , 0 , sizeof( struct V_372 ) ) ;
V_500 -> V_380 = V_380 ;
V_500 -> V_479 = V_380 * sizeof( struct V_389 ) ;
V_500 -> V_322 = F_179 ( V_6 -> V_260 , V_500 -> V_479 , & V_500 -> V_403 ) ;
if ( ! V_500 -> V_322 ) {
F_31
( L_213 ) ;
return - V_240 ;
}
F_31 ( L_45 ) ;
return 0 ;
}
static void F_216 ( struct V_5 * V_6 , struct V_372 * V_500 )
{
F_31 ( L_42 ) ;
if ( ! V_500 )
return;
if ( V_500 -> V_322 ) {
F_180 ( V_6 -> V_260 , V_500 -> V_479 , V_500 -> V_322 , V_500 -> V_403 ) ;
V_500 -> V_322 = NULL ;
}
F_31 ( L_45 ) ;
}
static void F_217 ( struct V_5 * V_6 ,
struct V_372 * V_500 , T_1 V_501 , T_1 V_479 ,
T_1 V_109 , T_1 V_376 )
{
F_31 ( L_42 ) ;
F_31 ( L_214 , V_500 -> V_322 ,
( T_1 ) V_500 -> V_403 ) ;
F_5 ( V_6 -> V_33 , V_501 , V_500 -> V_403 ) ;
F_5 ( V_6 -> V_33 , V_479 , V_500 -> V_380 ) ;
F_5 ( V_6 -> V_33 , V_109 , V_500 -> V_397 ) ;
F_5 ( V_6 -> V_33 , V_376 , V_500 -> V_77 ) ;
F_31 ( L_45 ) ;
}
static void F_218 ( struct V_5 * V_6 )
{
V_6 -> V_215 = 1 ;
V_6 -> V_181 = 1 ;
F_219 ( & V_6 -> V_52 ) ;
F_219 ( & V_6 -> V_293 ) ;
F_219 ( & V_6 -> V_284 ) ;
F_219 ( & V_6 -> V_182 ) ;
F_219 ( & V_6 -> V_216 ) ;
F_219 ( & V_6 -> V_295 ) ;
}
static int F_220 ( struct V_5 * V_6 )
{
int V_19 , V_40 , V_63 = - V_31 ;
void * V_466 ;
T_8 V_467 ;
F_31 ( L_42 ) ;
V_63 = F_215 ( V_6 , & V_6 -> V_388 , V_502 ) ;
if ( V_63 ) {
F_62 ( L_215 ,
V_6 -> V_33 -> V_51 ) ;
return V_63 ;
}
V_6 -> V_503 = F_221 ( V_504 ,
sizeof( struct V_60 ) ,
V_311 ) ;
if ( ! V_6 -> V_503 ) {
F_216 ( V_6 , & V_6 -> V_388 ) ;
return - V_240 ;
}
for ( V_19 = 0 ; V_19 < V_504 ; V_19 ++ ) {
V_466 = F_222 ( V_6 -> V_260 ,
sizeof( struct V_419 ) ,
& V_467 ) ;
if ( ! V_466 ) {
F_27 (KERN_ERR DRV_NAME
L_216 L_163 ,
priv->net_dev->name) ;
V_63 = - V_240 ;
break;
}
V_6 -> V_503 [ V_19 ] . type = V_398 ;
V_6 -> V_503 [ V_19 ] . V_81 . V_408 . V_37 =
(struct V_419 * ) V_466 ;
V_6 -> V_503 [ V_19 ] . V_81 . V_408 . V_440 = V_467 ;
V_6 -> V_503 [ V_19 ] . V_81 . V_408 . V_409 = NULL ;
}
if ( V_19 == V_504 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_19 ; V_40 ++ ) {
F_180 ( V_6 -> V_260 ,
sizeof( struct V_419 ) ,
V_6 -> V_503 [ V_40 ] . V_81 . V_408 . V_37 ,
V_6 -> V_503 [ V_40 ] . V_81 . V_408 .
V_440 ) ;
}
F_130 ( V_6 -> V_503 ) ;
V_6 -> V_503 = NULL ;
return V_63 ;
}
static void F_223 ( struct V_5 * V_6 )
{
int V_19 ;
F_31 ( L_42 ) ;
F_182 ( & V_6 -> V_394 ) ;
F_224 ( & V_6 -> V_402 ) ;
F_182 ( & V_6 -> V_422 ) ;
F_182 ( & V_6 -> V_410 ) ;
F_224 ( & V_6 -> V_425 ) ;
F_224 ( & V_6 -> V_411 ) ;
for ( V_19 = 0 ; V_19 < V_504 ; V_19 ++ ) {
if ( V_6 -> V_503 [ V_19 ] . V_81 . V_408 . V_409 ) {
F_163 ( V_6 -> V_503 [ V_19 ] . V_81 . V_408 .
V_409 ) ;
V_6 -> V_503 [ V_19 ] . V_81 . V_408 . V_409 = NULL ;
}
F_48 ( & V_6 -> V_503 [ V_19 ] . V_78 , & V_6 -> V_410 ) ;
}
F_165 ( & V_6 -> V_411 , V_19 ) ;
V_6 -> V_388 . V_397 = 0 ;
V_6 -> V_388 . V_414 = V_6 -> V_388 . V_380 ;
V_6 -> V_388 . V_77 = 0 ;
F_224 ( & V_6 -> V_415 ) ;
F_165 ( & V_6 -> V_415 , V_6 -> V_388 . V_414 ) ;
F_217 ( V_6 , & V_6 -> V_388 ,
V_505 ,
V_506 ,
V_400 ,
V_401 ) ;
F_31 ( L_45 ) ;
}
static void F_225 ( struct V_5 * V_6 )
{
int V_19 ;
F_31 ( L_42 ) ;
F_216 ( V_6 , & V_6 -> V_388 ) ;
if ( ! V_6 -> V_503 )
return;
for ( V_19 = 0 ; V_19 < V_504 ; V_19 ++ ) {
if ( V_6 -> V_503 [ V_19 ] . V_81 . V_408 . V_409 ) {
F_163 ( V_6 -> V_503 [ V_19 ] . V_81 . V_408 .
V_409 ) ;
V_6 -> V_503 [ V_19 ] . V_81 . V_408 . V_409 = NULL ;
}
if ( V_6 -> V_503 [ V_19 ] . V_81 . V_408 . V_37 )
F_180 ( V_6 -> V_260 ,
sizeof( struct V_419 ) ,
V_6 -> V_503 [ V_19 ] . V_81 . V_408 .
V_37 ,
V_6 -> V_503 [ V_19 ] . V_81 . V_408 .
V_440 ) ;
}
F_130 ( V_6 -> V_503 ) ;
V_6 -> V_503 = NULL ;
F_31 ( L_45 ) ;
}
static int F_226 ( struct V_5 * V_6 )
{
int V_19 , V_40 , V_63 = - V_31 ;
F_31 ( L_42 ) ;
V_63 = F_215 ( V_6 , & V_6 -> V_337 , V_325 ) ;
if ( V_63 ) {
F_31 ( L_217 ) ;
return V_63 ;
}
V_63 = F_213 ( V_6 , V_325 ) ;
if ( V_63 ) {
F_31 ( L_218 ) ;
F_216 ( V_6 , & V_6 -> V_337 ) ;
return V_63 ;
}
V_6 -> V_330 = F_132 ( V_325 *
sizeof( struct V_304 ) ,
V_239 ) ;
if ( ! V_6 -> V_330 ) {
F_31 ( L_219 ) ;
F_216 ( V_6 , & V_6 -> V_337 ) ;
F_214 ( V_6 ) ;
return - V_240 ;
}
for ( V_19 = 0 ; V_19 < V_325 ; V_19 ++ ) {
struct V_304 * V_61 = & V_6 -> V_330 [ V_19 ] ;
V_63 = F_124 ( V_6 , V_61 ) ;
if ( F_139 ( V_63 ) ) {
V_63 = - V_240 ;
break;
}
V_6 -> V_337 . V_322 [ V_19 ] . V_338 = V_61 -> V_308 ;
V_6 -> V_337 . V_322 [ V_19 ] . V_404 = V_335 ;
V_6 -> V_321 . V_322 [ V_19 ] . V_356 = 0 ;
}
if ( V_19 == V_325 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_19 ; V_40 ++ ) {
F_143 ( V_6 -> V_260 , V_6 -> V_330 [ V_40 ] . V_308 ,
sizeof( struct V_304 ) ,
V_309 ) ;
F_128 ( V_6 -> V_330 [ V_40 ] . V_305 ) ;
}
F_130 ( V_6 -> V_330 ) ;
V_6 -> V_330 = NULL ;
F_216 ( V_6 , & V_6 -> V_337 ) ;
F_214 ( V_6 ) ;
return V_63 ;
}
static void F_227 ( struct V_5 * V_6 )
{
F_31 ( L_42 ) ;
V_6 -> V_337 . V_397 = 0 ;
V_6 -> V_337 . V_414 = V_6 -> V_337 . V_380 - 1 ;
V_6 -> V_337 . V_77 = V_6 -> V_337 . V_380 - 1 ;
F_224 ( & V_6 -> V_507 ) ;
F_165 ( & V_6 -> V_507 , V_6 -> V_337 . V_414 ) ;
F_217 ( V_6 , & V_6 -> V_337 ,
V_508 ,
V_509 ,
V_378 ,
V_379 ) ;
F_5 ( V_6 -> V_33 , V_510 ,
V_6 -> V_321 . V_403 ) ;
F_31 ( L_45 ) ;
}
static void F_228 ( struct V_5 * V_6 )
{
int V_19 ;
F_31 ( L_42 ) ;
F_216 ( V_6 , & V_6 -> V_337 ) ;
F_214 ( V_6 ) ;
if ( ! V_6 -> V_330 )
return;
for ( V_19 = 0 ; V_19 < V_325 ; V_19 ++ ) {
if ( V_6 -> V_330 [ V_19 ] . V_307 ) {
F_143 ( V_6 -> V_260 ,
V_6 -> V_330 [ V_19 ] . V_308 ,
sizeof( struct V_306 ) ,
V_309 ) ;
F_128 ( V_6 -> V_330 [ V_19 ] . V_305 ) ;
}
}
F_130 ( V_6 -> V_330 ) ;
V_6 -> V_330 = NULL ;
F_31 ( L_45 ) ;
}
static int F_229 ( struct V_5 * V_6 )
{
T_1 V_285 = V_230 ;
T_3 V_8 [ V_230 ] ;
int V_63 ;
V_63 = F_26 ( V_6 , V_511 , V_8 , & V_285 ) ;
if ( V_63 ) {
F_31 ( L_220 ) ;
return - V_70 ;
}
memcpy ( V_6 -> V_33 -> V_512 , V_8 , V_230 ) ;
F_31 ( L_221 , V_6 -> V_33 -> V_512 ) ;
return 0 ;
}
static int F_230 ( struct V_5 * V_6 , int V_286 )
{
struct V_56 V_57 = {
. V_56 = V_513 ,
. V_88 = 0 ,
. V_65 = V_230
} ;
int V_63 ;
F_42 ( L_222 ) ;
F_31 ( L_42 ) ;
if ( V_6 -> V_187 & V_514 ) {
memcpy ( V_57 . V_67 , V_6 -> V_229 , V_230 ) ;
memcpy ( V_6 -> V_33 -> V_512 , V_6 -> V_229 , V_230 ) ;
} else
memcpy ( V_57 . V_67 , V_6 -> V_33 -> V_512 ,
V_230 ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
F_31 ( L_45 ) ;
return V_63 ;
}
static int F_231 ( struct V_5 * V_6 , T_1 V_515 ,
int V_286 )
{
struct V_56 V_57 = {
. V_56 = V_516 ,
. V_88 = 0 ,
. V_65 = sizeof( T_1 )
} ;
int V_63 ;
switch ( V_515 ) {
case V_427 :
V_57 . V_67 [ 0 ] = V_517 ;
break;
case V_432 :
V_57 . V_67 [ 0 ] = V_518 ;
break;
}
F_42 ( L_223 ,
V_515 == V_518 ? L_224 : L_225 ) ;
if ( ! V_286 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_286 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_232 ( struct V_5 * V_6 , T_1 V_245 ,
int V_286 )
{
struct V_56 V_57 = {
. V_56 = V_519 ,
. V_88 = 0 ,
. V_65 = sizeof( T_1 )
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_245 ;
F_42 ( L_226 , V_245 ) ;
if ( V_6 -> V_150 -> V_198 == V_427 )
return 0 ;
if ( ( V_245 != 0 ) &&
( ( V_245 < V_520 ) || ( V_245 > V_521 ) ) )
return - V_31 ;
if ( ! V_286 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 ) {
F_31 ( L_227 , V_245 ) ;
return V_63 ;
}
if ( V_245 )
V_6 -> V_187 |= V_522 ;
else
V_6 -> V_187 &= ~ V_522 ;
V_6 -> V_245 = V_245 ;
if ( ! V_286 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static int F_233 ( struct V_5 * V_6 , int V_286 )
{
struct V_56 V_57 = {
. V_56 = V_523 ,
. V_88 = 0 ,
. V_65 = 12 ,
} ;
T_1 V_524 , V_14 = sizeof( T_1 ) ;
int V_63 ;
if ( ! V_286 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
if ( V_6 -> V_150 -> V_198 == V_432 )
V_57 . V_67 [ 0 ] |= V_525 ;
V_57 . V_67 [ 0 ] |= V_526 |
V_527 | V_528 ;
if ( ! ( V_6 -> V_187 & V_529 ) )
V_57 . V_67 [ 0 ] |= V_530 ;
V_63 = F_26 ( V_6 ,
V_531 ,
& V_524 , & V_14 ) ;
if ( V_63 )
V_524 = V_532 ;
V_57 . V_67 [ 1 ] = V_533 ;
V_57 . V_67 [ 2 ] = V_533 & V_524 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
#if ! F_234 ( V_534 ) && ! F_234 ( V_535 )
V_57 . V_56 = V_536 ;
V_57 . V_88 = 0 ;
V_57 . V_65 = 0 ;
F_41 ( V_6 , & V_57 ) ;
#endif
if ( ! V_286 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static int F_235 ( struct V_5 * V_6 , T_1 V_537 ,
int V_286 )
{
struct V_56 V_57 = {
. V_56 = V_538 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_537 & V_539 ;
if ( ! V_286 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
F_41 ( V_6 , & V_57 ) ;
V_57 . V_56 = V_540 ;
F_41 ( V_6 , & V_57 ) ;
V_57 . V_56 = V_541 ;
F_41 ( V_6 , & V_57 ) ;
if ( ! V_286 ) {
V_63 = F_83 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_6 -> V_542 = V_537 ;
return 0 ;
}
static int F_236 ( struct V_5 * V_6 , int V_543 )
{
struct V_56 V_57 = {
. V_56 = V_544 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_543 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
if ( V_543 == V_545 )
V_6 -> V_546 = F_237 ( V_6 -> V_546 ) ;
else
V_6 -> V_546 = V_547 | V_543 ;
#ifdef F_238
if ( V_6 -> V_515 == V_548 && V_6 -> V_549 != V_550 ) {
V_57 . V_56 = V_551 ;
V_57 . V_67 [ 0 ] = ( T_1 ) V_6 -> V_549 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
}
#endif
return 0 ;
}
static int F_239 ( struct V_5 * V_6 , T_1 V_552 )
{
struct V_56 V_57 = {
. V_56 = V_553 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
if ( V_552 & V_554 )
V_57 . V_67 [ 0 ] = V_555 ;
else
V_57 . V_67 [ 0 ] = V_552 & ~ V_554 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_556 = V_552 ;
return 0 ;
}
static int F_240 ( struct V_5 * V_6 , T_1 V_557 )
{
struct V_56 V_57 = {
. V_56 = V_558 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_557 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_559 = V_557 ;
return 0 ;
}
static int F_241 ( struct V_5 * V_6 , T_1 V_557 )
{
struct V_56 V_57 = {
. V_56 = V_560 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_557 ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_561 = V_557 ;
return 0 ;
}
static int F_242 ( struct V_5 * V_6 , T_3 * V_273 ,
int V_286 )
{
struct V_56 V_57 = {
. V_56 = V_562 ,
. V_88 = 0 ,
. V_65 = ( V_273 == NULL ) ? 0 : V_230
} ;
int V_63 ;
#ifdef F_123
if ( V_273 != NULL )
F_42 ( L_228 , V_273 ) ;
else
F_42 ( L_229 ) ;
#endif
if ( V_273 != NULL )
memcpy ( V_57 . V_67 , V_273 , V_230 ) ;
if ( ! V_286 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_286 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_243 ( struct V_5 * V_6 )
{
struct V_56 V_57 = {
. V_56 = V_563 ,
. V_88 = 0 ,
. V_65 = V_230
} ;
int V_63 ;
int V_14 ;
F_42 ( L_230 ) ;
V_14 = V_230 ;
memcpy ( V_57 . V_67 , V_6 -> V_273 , V_230 ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
return V_63 ;
}
static int F_244 ( struct V_5 * V_6 ,
struct V_564 * V_565 ,
int V_286 )
{
struct V_56 V_57 = {
. V_56 = V_566 ,
. V_88 = 0 ,
. V_65 = sizeof( struct V_564 ) ,
} ;
int V_63 ;
F_42 ( L_231 ) ;
if ( ! V_286 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
memcpy ( V_57 . V_67 , V_565 ,
sizeof( struct V_564 ) ) ;
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_286 ) {
if ( F_83 ( V_6 ) )
V_63 = - V_70 ;
}
return V_63 ;
}
static int F_245 ( struct V_5 * V_6 ,
int V_567 ,
int V_568 ,
int V_569 ,
int V_286 )
{
struct V_56 V_57 = {
. V_56 = V_570 ,
. V_88 = 0 ,
. V_65 = sizeof(struct V_571 )
} ;
struct V_571 * V_572 =
(struct V_571 * ) & V_57 . V_67 ;
int V_63 ;
memset ( V_572 , 0 , sizeof( * V_572 ) ) ;
V_572 -> V_567 = V_567 ;
V_572 -> V_569 = V_569 ;
switch ( V_568 ) {
default:
case V_573 :
V_572 -> V_574 = V_575 ;
break;
case V_576 :
V_572 -> V_574 = V_577 |
V_578 ;
break;
case V_579 :
V_572 -> V_574 = V_577 |
V_578 | V_580 ;
break;
case V_581 :
V_572 -> V_574 = V_577 |
V_578 | V_582 ;
break;
case V_583 :
V_572 -> V_574 = V_577 |
V_578 | V_580 | V_584 ;
break;
}
F_42
( L_232 ,
V_572 -> V_567 , V_572 -> V_574 , V_568 ) ;
V_572 -> V_585 = 0 ;
if ( ! V_286 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_286 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_246 ( struct V_5 * V_6 , T_1 V_586 )
{
struct V_56 V_57 = {
. V_56 = V_551 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 = 0 ;
T_1 V_314 = V_586 ;
if ( V_586 != V_587 )
V_314 = ( V_586 - V_588 ) * 16 /
( V_589 - V_588 ) ;
V_57 . V_67 [ 0 ] = V_314 ;
if ( V_6 -> V_150 -> V_198 == V_432 )
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_63 )
V_6 -> V_586 = V_586 ;
return 0 ;
}
static int F_247 ( struct V_5 * V_6 ,
T_1 V_590 , int V_286 )
{
struct V_56 V_57 = {
. V_56 = V_591 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_590 ;
F_31 ( L_42 ) ;
if ( V_6 -> V_150 -> V_198 == V_432 ) {
if ( ! V_286 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
F_41 ( V_6 , & V_57 ) ;
if ( ! V_286 ) {
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
F_227 ( V_6 ) ;
F_181 ( V_6 ) ;
}
static void F_248 ( struct V_5 * V_6 )
{
F_225 ( V_6 ) ;
F_228 ( V_6 ) ;
F_183 ( V_6 ) ;
}
static int F_249 ( struct V_5 * V_6 )
{
if ( F_220 ( V_6 ) ||
F_226 ( V_6 ) || F_178 ( V_6 ) )
goto V_123;
return 0 ;
V_123:
F_225 ( V_6 ) ;
F_228 ( V_6 ) ;
F_183 ( V_6 ) ;
return - V_240 ;
}
static int F_250 ( struct V_5 * V_6 , T_1 V_62 ,
int V_286 )
{
struct V_56 V_57 = {
. V_56 = V_592 ,
. V_88 = 0 ,
. V_65 = 4
} ;
int V_63 ;
V_57 . V_67 [ 0 ] = V_62 ;
F_42 ( L_233 , V_62 ) ;
if ( ! V_286 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_286 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_251 ( struct V_5 * V_6 ,
int V_593 , char * V_594 , int V_14 , int V_286 )
{
int V_595 = V_14 ? ( V_14 <= 5 ? 5 : 13 ) : 0 ;
struct V_56 V_57 = {
. V_56 = V_596 ,
. V_88 = 0 ,
. V_65 = sizeof( struct V_597 ) ,
} ;
struct V_597 * V_598 = ( void * ) V_57 . V_67 ;
int V_63 ;
F_42 ( L_234 ,
V_593 , V_595 , V_14 ) ;
V_598 -> V_593 = V_593 ;
V_598 -> V_14 = V_595 ;
if ( V_595 ) {
memcpy ( V_598 -> V_594 , V_594 , V_14 ) ;
memset ( V_598 -> V_594 + V_14 , 0 , V_595 - V_14 ) ;
}
if ( V_595 == 0 )
F_252 ( L_235 ,
V_6 -> V_33 -> V_51 , V_598 -> V_593 ) ;
else if ( V_595 == 5 )
F_252 ( L_236 V_599 L_166 ,
V_6 -> V_33 -> V_51 , V_598 -> V_593 , V_598 -> V_14 ,
F_253 ( V_598 -> V_594 ) ) ;
else
F_252 ( L_236 V_600
L_166 ,
V_6 -> V_33 -> V_51 , V_598 -> V_593 , V_598 -> V_14 ,
F_254 ( V_598 -> V_594 ) ) ;
if ( ! V_286 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_286 ) {
int V_601 = F_83 ( V_6 ) ;
if ( V_63 == 0 )
V_63 = V_601 ;
}
return V_63 ;
}
static int F_255 ( struct V_5 * V_6 ,
int V_593 , int V_286 )
{
struct V_56 V_57 = {
. V_56 = V_602 ,
. V_88 = 0 ,
. V_65 = 4 ,
. V_67 = { V_593 } ,
} ;
int V_63 ;
F_42 ( L_237 , V_593 ) ;
if ( V_593 < 0 || V_593 > 3 )
return - V_31 ;
if ( ! V_286 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 ) {
F_27 (KERN_ERR DRV_NAME
L_188 ,
priv->net_dev->name, err) ;
return V_63 ;
}
}
V_63 = F_41 ( V_6 , & V_57 ) ;
if ( ! V_286 )
F_83 ( V_6 ) ;
return V_63 ;
}
static int F_256 ( struct V_5 * V_6 , int V_286 )
{
int V_19 , V_63 , V_567 , V_603 , V_604 ;
if ( ! ( V_6 -> V_49 & V_72 ) )
return 0 ;
if ( ! V_286 ) {
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
}
if ( ! V_6 -> V_150 -> V_190 . V_192 ) {
V_63 =
F_245 ( V_6 , V_605 ,
V_573 , 0 , 1 ) ;
} else {
V_567 = V_605 ;
if ( V_6 -> V_150 -> V_190 . V_62 & V_606 ) {
if ( V_6 -> V_150 -> V_190 . V_567 == V_607 )
V_567 = V_608 ;
else if ( V_6 -> V_150 -> V_190 . V_567 == V_609 )
V_567 = V_610 ;
}
V_603 = V_573 ;
if ( V_6 -> V_150 -> V_190 . V_62 & V_611 )
V_603 = V_6 -> V_150 -> V_190 . V_43 ;
V_604 = 0 ;
if ( V_6 -> V_150 -> V_190 . V_62 & V_612 )
V_604 = V_6 -> V_150 -> V_190 . V_613 ;
V_63 =
F_245 ( V_6 , V_567 , V_603 ,
V_604 , 1 ) ;
}
if ( V_63 )
goto exit;
if ( V_6 -> V_150 -> V_190 . V_192 ) {
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
if ( ! ( V_6 -> V_150 -> V_190 . V_62 & ( 1 << V_19 ) ) ) {
memset ( V_6 -> V_150 -> V_190 . V_614 [ V_19 ] , 0 , V_615 ) ;
V_6 -> V_150 -> V_190 . V_616 [ V_19 ] = 0 ;
} else {
V_63 = F_251 ( V_6 , V_19 ,
V_6 -> V_150 -> V_190 . V_614 [ V_19 ] ,
V_6 -> V_150 -> V_190 .
V_616 [ V_19 ] , 1 ) ;
if ( V_63 )
goto exit;
}
}
F_255 ( V_6 , V_6 -> V_150 -> V_491 . V_493 , 1 ) ;
}
V_63 =
F_250 ( V_6 ,
V_6 -> V_150 -> V_190 .
V_192 ? V_617 : 0 , 1 ) ;
if ( V_63 )
goto exit;
V_6 -> V_49 &= ~ V_264 ;
exit:
if ( ! V_286 )
F_83 ( V_6 ) ;
return V_63 ;
}
static void F_257 ( struct V_261 * V_262 )
{
struct V_5 * V_6 =
F_108 ( V_262 , struct V_5 , V_293 . V_262 ) ;
if ( ! ( V_6 -> V_49 & V_166 ) &&
V_6 -> V_49 & V_264 )
F_256 ( V_6 , 0 ) ;
}
static void F_258 ( struct V_1 * V_2 ,
struct V_618 * V_190 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_19 , V_619 = 0 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) )
goto V_621;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
if ( V_190 -> V_62 & ( 1 << V_19 ) ) {
V_6 -> V_150 -> V_190 . V_616 [ V_19 ] = V_190 -> V_616 [ V_19 ] ;
if ( V_190 -> V_616 [ V_19 ] == 0 )
V_6 -> V_150 -> V_190 . V_62 &= ~ ( 1 << V_19 ) ;
else
memcpy ( V_6 -> V_150 -> V_190 . V_614 [ V_19 ] , V_190 -> V_614 [ V_19 ] ,
V_190 -> V_616 [ V_19 ] ) ;
if ( V_190 -> V_43 == V_576 ) {
V_6 -> V_150 -> V_190 . V_62 |= ( 1 << V_19 ) ;
V_6 -> V_49 |= V_264 ;
} else
V_6 -> V_150 -> V_190 . V_62 &= ~ ( 1 << V_19 ) ;
}
}
if ( ( V_190 -> V_62 & V_622 ) &&
V_6 -> V_150 -> V_190 . V_623 != V_190 -> V_623 ) {
if ( V_190 -> V_623 <= 3 ) {
V_6 -> V_150 -> V_190 . V_623 = V_190 -> V_623 ;
V_6 -> V_150 -> V_190 . V_62 |= V_622 ;
} else
V_6 -> V_150 -> V_190 . V_62 &= ~ V_622 ;
V_6 -> V_49 |= V_264 ;
}
if ( ( V_190 -> V_62 & V_606 ) &&
( V_6 -> V_150 -> V_190 . V_567 != V_190 -> V_567 ) ) {
V_6 -> V_150 -> V_190 . V_567 = V_190 -> V_567 ;
V_6 -> V_150 -> V_190 . V_62 |= V_606 ;
V_6 -> V_49 |= V_264 ;
}
if ( V_190 -> V_62 & V_191 && V_6 -> V_150 -> V_190 . V_192 != V_190 -> V_192 ) {
V_6 -> V_150 -> V_190 . V_62 |= V_191 ;
V_6 -> V_150 -> V_190 . V_192 = V_190 -> V_192 ;
V_6 -> V_49 |= V_264 ;
V_619 = 1 ;
}
if ( V_190 -> V_62 & V_624 )
V_6 -> V_150 -> V_190 . V_625 = V_190 -> V_625 ;
if ( V_190 -> V_62 & V_611 && V_6 -> V_150 -> V_190 . V_43 != V_190 -> V_43 ) {
V_6 -> V_150 -> V_190 . V_43 = V_190 -> V_43 ;
V_6 -> V_150 -> V_190 . V_62 |= V_611 ;
V_6 -> V_49 |= V_264 ;
}
F_252 ( L_238 ,
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
F_256 ( V_6 , 0 ) ;
V_621:
F_85 ( & V_6 -> V_265 ) ;
}
static int F_98 ( struct V_5 * V_6 )
{
int V_63 ;
int V_286 = 1 ;
T_3 * V_273 ;
F_31 ( L_42 ) ;
V_63 = F_88 ( V_6 ) ;
if ( V_63 )
return V_63 ;
#ifdef F_155
if ( V_6 -> V_150 -> V_198 == V_199 ) {
V_63 = F_232 ( V_6 , V_6 -> V_245 , V_286 ) ;
if ( V_63 )
return V_63 ;
F_31 ( L_45 ) ;
return 0 ;
}
#endif
V_63 = F_229 ( V_6 ) ;
if ( V_63 )
return - V_70 ;
V_63 = F_230 ( V_6 , V_286 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_231 ( V_6 , V_6 -> V_150 -> V_198 , V_286 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_150 -> V_198 == V_432 ) {
V_63 = F_232 ( V_6 , V_6 -> V_245 , V_286 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_233 ( V_6 , V_286 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_235 ( V_6 , V_6 -> V_542 , V_286 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_236 ( V_6 , V_545 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_239 ( V_6 , V_6 -> V_556 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_187 & V_626 )
V_273 = V_6 -> V_273 ;
else
V_273 = NULL ;
V_63 = F_242 ( V_6 , V_273 , V_286 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_187 & V_282 )
V_63 = F_111 ( V_6 , V_6 -> V_268 , V_6 -> V_267 ,
V_286 ) ;
else
V_63 = F_111 ( V_6 , NULL , 0 , V_286 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_256 ( V_6 , V_286 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_150 -> V_198 == V_432 ) {
V_63 =
F_247 ( V_6 ,
V_6 -> V_627 ,
V_286 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_246 ( V_6 , V_6 -> V_586 ) ;
if ( V_63 )
return V_63 ;
}
F_31 ( L_45 ) ;
return 0 ;
}
static int F_259 ( struct V_1 * V_2 , void * V_467 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_628 * V_8 = V_467 ;
int V_63 = 0 ;
if ( ! F_260 ( V_8 -> V_629 ) )
return - V_630 ;
F_84 ( & V_6 -> V_265 ) ;
V_6 -> V_187 |= V_514 ;
memcpy ( V_6 -> V_229 , V_8 -> V_629 , V_230 ) ;
V_63 = F_230 ( V_6 , 0 ) ;
if ( V_63 )
goto V_621;
V_6 -> V_47 = 0 ;
F_85 ( & V_6 -> V_265 ) ;
F_107 ( & V_6 -> V_52 . V_262 ) ;
return 0 ;
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_261 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_62 ;
F_31 ( L_239 ) ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( V_6 -> V_49 & V_166 ) {
F_262 ( V_2 ) ;
F_263 ( V_2 ) ;
}
F_52 ( & V_6 -> V_68 , V_62 ) ;
return 0 ;
}
static int F_264 ( struct V_1 * V_2 )
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
while ( ! F_44 ( & V_6 -> V_422 ) ) {
V_59 = V_6 -> V_422 . V_77 ;
V_61 = F_45 ( V_59 , struct V_60 , V_78 ) ;
F_46 ( V_59 ) ;
F_47 ( & V_6 -> V_425 ) ;
F_163 ( V_61 -> V_81 . V_408 . V_409 ) ;
V_61 -> V_81 . V_408 . V_409 = NULL ;
F_48 ( V_59 , & V_6 -> V_410 ) ;
F_49 ( & V_6 -> V_411 ) ;
}
F_52 ( & V_6 -> V_68 , V_62 ) ;
F_31 ( L_45 ) ;
return 0 ;
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_2 -> V_327 . V_631 ++ ;
#ifdef F_155
if ( V_6 -> V_150 -> V_198 == V_199 )
return;
#endif
F_31 ( L_240 ,
V_2 -> V_51 ) ;
F_35 ( V_6 ) ;
}
static int F_266 ( struct V_5 * V_6 , int V_147 )
{
V_6 -> V_150 -> V_632 = V_147 ;
return 0 ;
}
static int F_267 ( struct V_5 * V_6 , int V_147 )
{
struct V_633 * V_150 = V_6 -> V_150 ;
struct V_618 V_190 = {
. V_62 = V_606 ,
} ;
int V_266 = 0 ;
if ( V_147 & V_634 ) {
V_190 . V_567 = V_607 ;
V_150 -> V_635 = 0 ;
} else if ( V_147 & V_636 ) {
V_190 . V_567 = V_637 ;
V_150 -> V_635 = 1 ;
} else if ( V_147 & V_638 ) {
V_190 . V_567 = V_609 ;
V_150 -> V_635 = 1 ;
} else
return - V_31 ;
if ( V_150 -> V_639 )
V_150 -> V_639 ( V_150 -> V_2 , & V_190 ) ;
else
V_266 = - V_640 ;
return V_266 ;
}
static void V_564 ( struct V_5 * V_6 ,
char * V_641 , int V_642 )
{
struct V_564 V_643 ;
V_643 . V_644 = 0 ;
memcpy ( V_643 . V_645 , V_641 , V_642 ) ;
V_643 . V_646 = V_642 ;
F_266 ( V_6 , 1 ) ;
F_244 ( V_6 , & V_643 , 0 ) ;
}
static void F_268 ( struct V_1 * V_2 ,
struct V_647 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char V_648 [ 64 ] , V_649 [ 64 ] ;
F_269 ( V_81 -> V_650 , V_651 , sizeof( V_81 -> V_650 ) ) ;
F_269 ( V_81 -> V_121 , V_652 , sizeof( V_81 -> V_121 ) ) ;
F_270 ( V_6 , V_648 , sizeof( V_648 ) ) ;
F_271 ( V_6 , V_649 , sizeof( V_649 ) ) ;
snprintf ( V_81 -> V_653 , sizeof( V_81 -> V_653 ) , L_241 ,
V_648 , V_6 -> V_156 , V_649 ) ;
F_269 ( V_81 -> V_654 , F_272 ( V_6 -> V_260 ) ,
sizeof( V_81 -> V_654 ) ) ;
}
static T_1 F_273 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return ( V_6 -> V_49 & V_166 ) ? 1 : 0 ;
}
static void F_274 ( struct V_261 * V_262 )
{
struct V_5 * V_6 =
F_108 ( V_262 , struct V_5 , V_182 . V_262 ) ;
unsigned long V_62 ;
T_1 V_655 = 0xa5a5a5a5 ;
T_1 V_14 = sizeof( V_655 ) ;
int V_656 = 0 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( V_6 -> V_69 != 0 ) {
F_31 ( L_242 ,
V_6 -> V_33 -> V_51 ) ;
V_656 = 1 ;
} else if ( F_26 ( V_6 , V_657 , & V_655 , & V_14 ) ||
( V_655 == V_6 -> V_494 ) ) {
F_31 ( L_243 ,
V_6 -> V_33 -> V_51 ) ;
V_656 = 1 ;
}
if ( V_656 ) {
V_6 -> V_181 = 1 ;
V_6 -> V_488 ++ ;
F_35 ( V_6 ) ;
}
V_6 -> V_494 = V_655 ;
if ( ! V_6 -> V_181 )
F_39 ( & V_6 -> V_182 , V_53 / 2 ) ;
F_52 ( & V_6 -> V_68 , V_62 ) ;
}
static void F_275 ( struct V_261 * V_262 )
{
struct V_5 * V_6 =
F_108 ( V_262 , struct V_5 , V_216 . V_262 ) ;
unsigned long V_62 ;
F_43 ( & V_6 -> V_68 , V_62 ) ;
if ( F_71 ( V_6 ) ) {
F_211 ( L_244 ) ;
if ( ! V_6 -> V_215 )
F_39 ( & V_6 -> V_216 ,
F_97 ( V_53 ) ) ;
goto V_658;
}
if ( ! ( V_6 -> V_49 & V_485 ) ) {
F_211 ( L_245
L_246 ) ;
F_35 ( V_6 ) ;
} else
F_211 ( L_247
L_248 ) ;
V_658:
F_52 ( & V_6 -> V_68 , V_62 ) ;
}
static struct V_1 * F_276 ( struct V_260 * V_260 ,
void T_12 * V_7 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_277 ( sizeof( struct V_5 ) , 0 ) ;
if ( ! V_2 )
return NULL ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_150 = F_278 ( V_2 ) ;
V_6 -> V_260 = V_260 ;
V_6 -> V_33 = V_2 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_150 -> V_659 = F_177 ;
V_6 -> V_150 -> V_639 = F_258 ;
V_6 -> V_150 -> V_660 = - 20 ;
V_6 -> V_150 -> V_661 = - 85 ;
V_2 -> V_662 = & V_663 ;
V_2 -> V_664 = & V_665 ;
V_2 -> V_666 = & V_667 ;
V_6 -> V_668 . V_669 = V_6 -> V_150 ;
V_2 -> V_668 = & V_6 -> V_668 ;
V_2 -> V_670 = 3 * V_53 ;
V_2 -> V_455 = 0 ;
V_6 -> V_546 = V_671 ;
#ifdef F_155
V_6 -> V_187 |= V_344 ;
#endif
V_6 -> V_150 -> V_632 = 0 ;
V_6 -> V_150 -> V_672 = 0 ;
V_6 -> V_150 -> V_673 = 0 ;
V_6 -> V_150 -> V_674 = 1 ;
switch ( V_675 ) {
case 1 :
V_6 -> V_150 -> V_198 = V_432 ;
break;
#ifdef F_155
case 2 :
V_6 -> V_150 -> V_198 = V_199 ;
break;
#endif
default:
case 0 :
V_6 -> V_150 -> V_198 = V_427 ;
break;
}
if ( V_676 == 1 )
V_6 -> V_49 |= V_206 ;
if ( V_245 != 0 &&
( ( V_245 >= V_520 ) && ( V_245 <= V_521 ) ) ) {
V_6 -> V_187 |= V_522 ;
V_6 -> V_245 = V_245 ;
}
if ( V_677 )
V_6 -> V_187 |= V_188 ;
V_6 -> V_627 = V_678 ;
V_6 -> V_559 = V_679 ;
V_6 -> V_561 = V_680 ;
V_6 -> V_556 = V_681 | V_554 ;
V_6 -> V_682 = V_683 | V_684 ;
V_6 -> V_586 = V_587 ;
V_6 -> V_542 = V_685 ;
strcpy ( V_6 -> V_686 , L_249 ) ;
F_279 ( & V_6 -> V_68 ) ;
F_280 ( & V_6 -> V_265 ) ;
F_280 ( & V_6 -> V_179 ) ;
F_281 ( & V_6 -> V_55 ) ;
F_37 ( V_2 ) ;
F_182 ( & V_6 -> V_75 ) ;
F_182 ( & V_6 -> V_91 ) ;
F_224 ( & V_6 -> V_90 ) ;
F_224 ( & V_6 -> V_92 ) ;
F_182 ( & V_6 -> V_410 ) ;
F_182 ( & V_6 -> V_422 ) ;
F_224 ( & V_6 -> V_411 ) ;
F_224 ( & V_6 -> V_425 ) ;
F_182 ( & V_6 -> V_394 ) ;
F_224 ( & V_6 -> V_402 ) ;
F_282 ( & V_6 -> V_52 , F_107 ) ;
F_282 ( & V_6 -> V_293 , F_257 ) ;
F_282 ( & V_6 -> V_284 , V_687 ) ;
F_282 ( & V_6 -> V_182 , F_274 ) ;
F_282 ( & V_6 -> V_216 , F_275 ) ;
F_282 ( & V_6 -> V_295 , F_117 ) ;
F_283 ( & V_6 -> V_458 , ( void (*) ( unsigned long ) )
F_170 , ( unsigned long ) V_6 ) ;
V_6 -> V_215 = 1 ;
V_6 -> V_181 = 1 ;
return V_2 ;
}
static int F_284 ( struct V_260 * V_260 ,
const struct V_688 * V_689 )
{
void T_12 * V_7 ;
struct V_1 * V_2 = NULL ;
struct V_5 * V_6 = NULL ;
int V_63 = 0 ;
int V_690 = 0 ;
T_1 V_4 ;
F_31 ( L_42 ) ;
if ( ! ( F_285 ( V_260 , 0 ) & V_691 ) ) {
F_31 ( L_250 ) ;
V_63 = - V_692 ;
goto V_39;
}
V_7 = F_286 ( V_260 , 0 , 0 ) ;
if ( ! V_7 ) {
F_27 (KERN_WARNING DRV_NAME
L_251 ) ;
V_63 = - V_70 ;
goto V_123;
}
V_2 = F_276 ( V_260 , V_7 ) ;
if ( ! V_2 ) {
F_27 (KERN_WARNING DRV_NAME
L_252 ) ;
V_63 = - V_240 ;
goto V_123;
}
V_63 = F_287 ( V_260 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_253 ) ;
return V_63 ;
}
V_6 = F_2 ( V_2 ) ;
F_288 ( V_260 ) ;
F_289 ( V_260 , V_6 ) ;
V_63 = F_290 ( V_260 , F_291 ( 32 ) ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_254 ) ;
F_292 ( V_260 ) ;
return V_63 ;
}
V_63 = F_293 ( V_260 , V_651 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_255 ) ;
F_292 ( V_260 ) ;
return V_63 ;
}
F_185 ( V_260 , 0x40 , & V_4 ) ;
if ( ( V_4 & 0x0000ff00 ) != 0 )
F_294 ( V_260 , 0x40 , V_4 & 0xffff00ff ) ;
if ( ! F_25 ( V_2 ) ) {
F_27 (KERN_WARNING DRV_NAME
L_256 ) ;
V_63 = - V_692 ;
goto V_123;
}
F_295 ( V_2 , & V_260 -> V_2 ) ;
V_6 -> V_49 |= V_136 ;
F_68 ( V_6 ) ;
if ( F_249 ( V_6 ) ) {
F_27 (KERN_WARNING DRV_NAME
L_257 ) ;
V_63 = - V_240 ;
goto V_123;
}
F_77 ( V_6 ) ;
V_63 = F_296 ( V_260 -> V_455 ,
F_173 , V_693 , V_2 -> V_51 , V_6 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_258 , pci_dev->irq) ;
goto V_123;
}
V_2 -> V_455 = V_260 -> V_455 ;
F_31 ( L_259 ) ;
F_27 (KERN_INFO DRV_NAME
L_260 ) ;
V_63 = F_93 ( V_6 , 1 ) ;
if ( V_63 )
goto V_123;
V_63 = F_101 ( V_2 ) ;
if ( V_63 )
goto V_123;
V_690 = 1 ;
V_63 = F_297 ( V_2 ) ;
if ( V_63 ) {
F_27 (KERN_WARNING DRV_NAME
L_261 ) ;
goto V_123;
}
V_690 = 2 ;
F_84 ( & V_6 -> V_265 ) ;
F_31 ( L_262 , V_2 -> V_51 , F_272 ( V_260 ) ) ;
V_63 = F_298 ( & V_260 -> V_2 . V_694 , & V_695 ) ;
if ( V_63 )
goto V_71;
if ( ! ( V_6 -> V_49 & V_485 ) ) {
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
V_6 -> V_49 |= V_620 ;
F_85 ( & V_6 -> V_265 ) ;
V_39:
return V_63 ;
V_71:
F_85 ( & V_6 -> V_265 ) ;
V_123:
if ( V_2 ) {
if ( V_690 >= 2 )
F_299 ( V_2 ) ;
if ( V_690 ) {
F_300 ( V_6 -> V_150 -> V_151 . V_152 ) ;
F_130 ( V_6 -> V_150 -> V_233 . V_237 ) ;
}
F_86 ( V_6 ) ;
F_68 ( V_6 ) ;
if ( V_2 -> V_455 )
F_301 ( V_2 -> V_455 , V_6 ) ;
F_218 ( V_6 ) ;
F_248 ( V_6 ) ;
F_302 ( & V_260 -> V_2 . V_694 ,
& V_695 ) ;
F_303 ( V_2 , 0 ) ;
}
F_304 ( V_260 , V_7 ) ;
F_305 ( V_260 ) ;
F_292 ( V_260 ) ;
goto V_39;
}
static void F_306 ( struct V_260 * V_260 )
{
struct V_5 * V_6 = F_307 ( V_260 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
F_84 ( & V_6 -> V_265 ) ;
V_6 -> V_49 &= ~ V_620 ;
F_302 ( & V_260 -> V_2 . V_694 , & V_695 ) ;
#ifdef F_61
if ( V_120 . V_121 )
F_66 ( V_6 , & V_120 ) ;
#endif
F_99 ( V_6 ) ;
F_85 ( & V_6 -> V_265 ) ;
F_299 ( V_2 ) ;
F_218 ( V_6 ) ;
F_248 ( V_6 ) ;
F_129 ( V_6 ) ;
F_301 ( V_2 -> V_455 , V_6 ) ;
F_304 ( V_260 , V_6 -> V_7 ) ;
F_300 ( V_6 -> V_150 -> V_151 . V_152 ) ;
F_130 ( V_6 -> V_150 -> V_233 . V_237 ) ;
F_303 ( V_2 , 0 ) ;
F_305 ( V_260 ) ;
F_292 ( V_260 ) ;
F_31 ( L_45 ) ;
}
static int F_308 ( struct V_260 * V_260 , T_13 V_102 )
{
struct V_5 * V_6 = F_307 ( V_260 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
F_31 ( L_264 , V_2 -> V_51 ) ;
F_84 ( & V_6 -> V_265 ) ;
if ( V_6 -> V_49 & V_620 ) {
F_99 ( V_6 ) ;
}
F_309 ( V_2 ) ;
F_310 ( V_260 ) ;
F_292 ( V_260 ) ;
F_311 ( V_260 , V_696 ) ;
V_6 -> V_697 = F_36 () ;
F_85 ( & V_6 -> V_265 ) ;
return 0 ;
}
static int F_312 ( struct V_260 * V_260 )
{
struct V_5 * V_6 = F_307 ( V_260 ) ;
struct V_1 * V_2 = V_6 -> V_33 ;
int V_63 ;
T_1 V_4 ;
if ( V_698 )
return 0 ;
F_84 ( & V_6 -> V_265 ) ;
F_31 ( L_265 , V_2 -> V_51 ) ;
F_311 ( V_260 , V_699 ) ;
V_63 = F_287 ( V_260 ) ;
if ( V_63 ) {
F_27 ( V_700 L_266 ,
V_2 -> V_51 ) ;
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
F_313 ( V_260 ) ;
F_185 ( V_260 , 0x40 , & V_4 ) ;
if ( ( V_4 & 0x0000ff00 ) != 0 )
F_294 ( V_260 , 0x40 , V_4 & 0xffff00ff ) ;
F_314 ( V_2 ) ;
V_6 -> V_205 = F_36 () - V_6 -> V_697 ;
if ( ! ( V_6 -> V_49 & V_206 ) )
F_93 ( V_6 , 0 ) ;
F_85 ( & V_6 -> V_265 ) ;
return 0 ;
}
static void F_315 ( struct V_260 * V_260 )
{
struct V_5 * V_6 = F_307 ( V_260 ) ;
F_99 ( V_6 ) ;
F_292 ( V_260 ) ;
}
static int T_14 F_316 ( void )
{
int V_266 ;
F_27 (KERN_INFO DRV_NAME L_267 , DRV_DESCRIPTION, DRV_VERSION) ;
F_27 (KERN_INFO DRV_NAME L_268 , DRV_COPYRIGHT) ;
F_317 ( & V_207 , V_701 ,
V_223 ) ;
V_266 = F_318 ( & V_702 ) ;
if ( V_266 )
goto V_39;
#ifdef F_123
V_44 = V_703 ;
V_266 = F_319 ( & V_702 . V_650 ,
& V_704 ) ;
#endif
V_39:
return V_266 ;
}
static void T_15 F_320 ( void )
{
#ifdef F_123
F_321 ( & V_702 . V_650 ,
& V_704 ) ;
#endif
F_322 ( & V_702 ) ;
F_323 ( & V_207 ) ;
}
static int F_324 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_49 & V_166 ) )
strcpy ( V_218 -> V_51 , L_269 ) ;
else
snprintf ( V_218 -> V_51 , V_707 , L_270 ) ;
F_325 ( L_271 , V_218 -> V_51 ) ;
return 0 ;
}
static int F_326 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_708 * V_709 = & V_218 -> V_243 ;
int V_63 = 0 ;
if ( V_6 -> V_150 -> V_198 == V_427 )
return - V_640 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) ) {
V_63 = - V_70 ;
goto V_621;
}
if ( V_709 -> V_392 == 1 ) {
if ( ( V_709 -> V_710 >= ( int ) 2.412e8 && V_709 -> V_710 <= ( int ) 2.487e8 ) ) {
int V_711 = V_709 -> V_710 / 100000 ;
int V_42 = 0 ;
while ( ( V_42 < V_521 ) &&
( V_711 != V_712 [ V_42 ] ) )
V_42 ++ ;
V_709 -> V_392 = 0 ;
V_709 -> V_710 = V_42 + 1 ;
}
}
if ( V_709 -> V_392 > 0 || V_709 -> V_710 > 1000 ) {
V_63 = - V_640 ;
goto V_621;
} else {
F_325 ( L_272 , V_709 -> V_710 ) ;
V_63 = F_232 ( V_6 , V_709 -> V_710 , 0 ) ;
}
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_327 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_243 . V_392 = 0 ;
if ( V_6 -> V_187 & V_522 ||
V_6 -> V_49 & V_166 )
V_218 -> V_243 . V_710 = V_6 -> V_245 ;
else
V_218 -> V_243 . V_710 = 0 ;
F_325 ( L_273 , V_6 -> V_245 ) ;
return 0 ;
}
static int F_328 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
F_325 ( L_274 , V_218 -> V_313 ) ;
if ( V_218 -> V_313 == V_6 -> V_150 -> V_198 )
return 0 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) ) {
V_63 = - V_70 ;
goto V_621;
}
switch ( V_218 -> V_313 ) {
#ifdef F_155
case V_199 :
V_63 = F_196 ( V_6 , V_199 ) ;
break;
#endif
case V_432 :
V_63 = F_196 ( V_6 , V_432 ) ;
break;
case V_427 :
case V_713 :
default:
V_63 = F_196 ( V_6 , V_427 ) ;
break;
}
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_329 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_313 = V_6 -> V_150 -> V_198 ;
F_325 ( L_275 , V_218 -> V_313 ) ;
return 0 ;
}
static int F_330 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_714 * V_715 = (struct V_714 * ) V_706 ;
T_2 V_4 ;
int V_19 , V_43 ;
V_218 -> V_37 . V_285 = sizeof( * V_715 ) ;
memset ( V_715 , 0 , sizeof( * V_715 ) ) ;
V_715 -> V_716 = 5 * 1000 * 1000 ;
V_715 -> V_717 . V_718 = 100 ;
V_715 -> V_717 . V_43 = 0 ;
V_715 -> V_717 . V_719 = 0 ;
V_715 -> V_717 . V_720 = 7 ;
V_715 -> V_721 . V_718 = 70 ;
V_715 -> V_721 . V_43 = 20 + V_353 ;
V_715 -> V_721 . V_719 = 0 ;
V_715 -> V_721 . V_720 = 7 ;
V_715 -> V_722 = V_255 ;
for ( V_19 = 0 ; V_19 < V_255 && V_19 < V_723 ; V_19 ++ ) {
V_715 -> V_724 [ V_19 ] = V_253 [ V_19 ] . V_724 * 100 * 1000 ;
}
V_715 -> V_725 = V_726 ;
V_715 -> V_727 = V_555 ;
V_715 -> V_728 = V_729 ;
V_715 -> V_730 = V_731 ;
V_715 -> V_732 = V_733 [ 0 ] ;
V_715 -> V_734 = V_733 [ V_735 - 1 ] ;
V_715 -> V_736 = V_737 [ V_735 - 1 ] ;
V_715 -> V_738 = V_737 [ 0 ] ;
V_715 -> V_739 = V_740 ;
V_715 -> V_741 = V_742 ;
V_715 -> V_743 = V_742 | V_740 ;
V_715 -> V_744 [ 0 ] = 5 ;
V_715 -> V_744 [ 1 ] = 13 ;
V_715 -> V_745 = 2 ;
V_715 -> V_746 = V_747 ;
if ( V_6 -> V_150 -> V_198 == V_432 ) {
V_715 -> V_748 = V_749 ;
V_715 -> V_750 = V_751 ;
for ( V_19 = 0 , V_43 = ( V_589 * 16 ) ;
V_19 < V_751 ;
V_19 ++ , V_43 -=
( ( V_589 -
V_588 ) * 16 ) / ( V_751 - 1 ) )
V_715 -> V_752 [ V_19 ] = V_43 / 16 ;
} else {
V_715 -> V_748 = 0 ;
V_715 -> V_750 = 0 ;
}
V_715 -> V_753 = V_754 ;
V_715 -> V_755 = 18 ;
V_715 -> V_756 = V_757 ;
V_4 = 0 ;
for ( V_19 = 0 ; V_19 < V_757 ; V_19 ++ ) {
V_715 -> V_243 [ V_4 ] . V_19 = V_19 + 1 ;
V_715 -> V_243 [ V_4 ] . V_710 = V_712 [ V_19 ] * 100000 ;
V_715 -> V_243 [ V_4 ] . V_392 = 1 ;
V_4 ++ ;
if ( V_4 == V_758 )
break;
}
V_715 -> V_759 = V_4 ;
V_715 -> V_760 [ 0 ] = ( V_761 |
F_331 ( V_224 ) ) ;
V_715 -> V_760 [ 1 ] = V_762 ;
V_715 -> V_763 = V_764 | V_765 |
V_766 | V_767 ;
F_325 ( L_276 ) ;
return 0 ;
}
static int F_332 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
if ( V_218 -> V_219 . V_220 != V_221 )
return - V_31 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) ) {
V_63 = - V_70 ;
goto V_621;
}
if ( F_333 ( V_218 -> V_219 . V_629 ) ||
F_334 ( V_218 -> V_219 . V_629 ) ) {
F_325 ( L_277 ) ;
V_6 -> V_187 &= ~ V_626 ;
V_63 = F_242 ( V_6 , NULL , 0 ) ;
goto V_621;
}
V_6 -> V_187 |= V_626 ;
memcpy ( V_6 -> V_768 , V_218 -> V_219 . V_629 , V_230 ) ;
V_63 = F_242 ( V_6 , V_218 -> V_219 . V_629 , 0 ) ;
F_325 ( L_278 , V_218 -> V_219 . V_629 ) ;
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_335 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_626 || V_6 -> V_49 & V_166 ) {
V_218 -> V_219 . V_220 = V_221 ;
memcpy ( V_218 -> V_219 . V_629 , V_6 -> V_273 , V_230 ) ;
} else
F_114 ( V_218 -> V_219 . V_629 ) ;
F_325 ( L_279 , V_218 -> V_219 . V_629 ) ;
return 0 ;
}
static int F_336 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char * V_268 = L_50 ;
int V_285 = 0 ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) ) {
V_63 = - V_70 ;
goto V_621;
}
if ( V_218 -> V_268 . V_62 && V_218 -> V_268 . V_285 ) {
V_285 = V_218 -> V_268 . V_285 ;
V_268 = V_706 ;
}
if ( V_285 == 0 ) {
F_325 ( L_280 ) ;
V_6 -> V_187 &= ~ V_282 ;
V_63 = F_111 ( V_6 , NULL , 0 , 0 ) ;
goto V_621;
}
V_285 = F_34 ( V_285 , V_269 ) ;
V_6 -> V_187 |= V_282 ;
if ( V_6 -> V_267 == V_285 && ! memcmp ( V_6 -> V_268 , V_706 , V_285 ) ) {
F_325 ( L_281 ) ;
V_63 = 0 ;
goto V_621;
}
F_325 ( L_282 , V_285 , V_268 , V_285 ) ;
V_6 -> V_267 = V_285 ;
memcpy ( V_6 -> V_268 , V_268 , V_6 -> V_267 ) ;
V_63 = F_111 ( V_6 , V_268 , V_285 , 0 ) ;
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_337 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_282 || V_6 -> V_49 & V_166 ) {
F_325 ( L_283 ,
V_6 -> V_267 , V_6 -> V_268 ) ;
memcpy ( V_706 , V_6 -> V_268 , V_6 -> V_267 ) ;
V_218 -> V_268 . V_285 = V_6 -> V_267 ;
V_218 -> V_268 . V_62 = 1 ;
} else {
F_325 ( L_284 ) ;
V_218 -> V_268 . V_285 = 0 ;
V_218 -> V_268 . V_62 = 0 ;
}
return 0 ;
}
static int F_338 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_218 -> V_37 . V_285 > V_269 )
return - V_769 ;
V_218 -> V_37 . V_285 = F_147 ( T_4 , V_218 -> V_37 . V_285 , sizeof( V_6 -> V_686 ) ) ;
memset ( V_6 -> V_686 , 0 , sizeof( V_6 -> V_686 ) ) ;
memcpy ( V_6 -> V_686 , V_706 , V_218 -> V_37 . V_285 ) ;
F_325 ( L_285 , V_6 -> V_686 ) ;
return 0 ;
}
static int F_339 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_37 . V_285 = strlen ( V_6 -> V_686 ) ;
memcpy ( V_706 , V_6 -> V_686 , V_218 -> V_37 . V_285 ) ;
V_218 -> V_37 . V_62 = 1 ;
F_325 ( L_286 , V_706 ) ;
return 0 ;
}
static int F_340 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_770 = V_218 -> V_724 . V_147 ;
T_1 V_537 ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) ) {
V_63 = - V_70 ;
goto V_621;
}
V_537 = 0 ;
if ( V_770 == 1000000 ||
( ! V_218 -> V_724 . V_771 && V_770 > 1000000 ) )
V_537 |= V_278 ;
if ( V_770 == 2000000 ||
( ! V_218 -> V_724 . V_771 && V_770 > 2000000 ) )
V_537 |= V_279 ;
if ( V_770 == 5500000 ||
( ! V_218 -> V_724 . V_771 && V_770 > 5500000 ) )
V_537 |= V_280 ;
if ( V_770 == 11000000 ||
( ! V_218 -> V_724 . V_771 && V_770 > 11000000 ) )
V_537 |= V_281 ;
if ( V_537 == 0 )
V_537 = V_685 ;
V_63 = F_235 ( V_6 , V_537 , 0 ) ;
F_325 ( L_287 , V_537 ) ;
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_341 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_4 ;
unsigned int V_14 = sizeof( V_4 ) ;
int V_63 = 0 ;
if ( ! ( V_6 -> V_49 & V_106 ) ||
V_6 -> V_49 & V_485 ||
! ( V_6 -> V_49 & V_166 ) ) {
V_218 -> V_724 . V_147 = 0 ;
return 0 ;
}
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) ) {
V_63 = - V_70 ;
goto V_621;
}
V_63 = F_26 ( V_6 , V_275 , & V_4 , & V_14 ) ;
if ( V_63 ) {
F_325 ( L_288 ) ;
goto V_621;
}
switch ( V_4 & V_539 ) {
case V_278 :
V_218 -> V_724 . V_147 = 1000000 ;
break;
case V_279 :
V_218 -> V_724 . V_147 = 2000000 ;
break;
case V_280 :
V_218 -> V_724 . V_147 = 5500000 ;
break;
case V_281 :
V_218 -> V_724 . V_147 = 11000000 ;
break;
default:
V_218 -> V_724 . V_147 = 0 ;
}
F_325 ( L_289 , V_218 -> V_724 . V_147 ) ;
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_342 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_147 , V_63 ;
if ( V_218 -> V_772 . V_771 == 0 )
return - V_31 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) ) {
V_63 = - V_70 ;
goto V_621;
}
if ( V_218 -> V_772 . V_773 )
V_147 = V_6 -> V_556 | V_554 ;
else {
if ( V_218 -> V_772 . V_147 < 1 || V_218 -> V_772 . V_147 > 2304 ) {
V_63 = - V_31 ;
goto V_621;
}
V_147 = V_218 -> V_772 . V_147 ;
}
V_63 = F_239 ( V_6 , V_147 ) ;
F_325 ( L_290 , V_147 ) ;
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_343 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_772 . V_147 = V_6 -> V_556 & ~ V_554 ;
V_218 -> V_772 . V_771 = 1 ;
V_218 -> V_772 . V_773 = ( V_6 -> V_556 & V_554 ) ? 1 : 0 ;
F_325 ( L_291 , V_218 -> V_772 . V_147 ) ;
return 0 ;
}
static int F_344 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 , V_147 ;
if ( F_210 ( V_6 , V_218 -> V_752 . V_773 ) )
return - V_774 ;
if ( V_6 -> V_150 -> V_198 != V_432 )
return 0 ;
if ( ( V_218 -> V_752 . V_62 & V_775 ) != V_749 )
return - V_31 ;
if ( V_218 -> V_752 . V_771 == 0 )
V_147 = V_587 ;
else {
if ( V_218 -> V_752 . V_147 < V_588 ||
V_218 -> V_752 . V_147 > V_589 )
return - V_31 ;
V_147 = V_218 -> V_752 . V_147 ;
}
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) ) {
V_63 = - V_70 ;
goto V_621;
}
V_63 = F_246 ( V_6 , V_147 ) ;
F_325 ( L_292 , V_147 ) ;
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_345 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_752 . V_773 = ( V_6 -> V_49 & V_485 ) ? 1 : 0 ;
if ( V_6 -> V_586 == V_587 ) {
V_218 -> V_752 . V_771 = 0 ;
V_218 -> V_752 . V_147 = V_589 ;
} else {
V_218 -> V_752 . V_771 = 1 ;
V_218 -> V_752 . V_147 = V_6 -> V_586 ;
}
V_218 -> V_752 . V_62 = V_749 ;
F_325 ( L_293 , V_218 -> V_752 . V_147 ) ;
return 0 ;
}
static int F_346 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_218 -> V_776 . V_771 )
return - V_31 ;
if ( V_218 -> V_776 . V_773 ) {
V_6 -> V_682 |= V_684 ;
V_6 -> V_150 -> V_777 = V_683 ;
} else {
if ( V_218 -> V_776 . V_147 < V_729 ||
V_218 -> V_776 . V_147 > V_731 )
return - V_31 ;
V_6 -> V_150 -> V_777 = V_218 -> V_776 . V_147 & ~ 0x1 ;
V_6 -> V_682 = V_6 -> V_150 -> V_777 ;
}
F_325 ( L_294 , V_6 -> V_150 -> V_777 ) ;
return 0 ;
}
static int F_347 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_776 . V_147 = V_6 -> V_682 & ~ V_684 ;
V_218 -> V_776 . V_771 = 0 ;
V_218 -> V_776 . V_773 = ( V_6 -> V_682 & V_684 ) ? 1 : 0 ;
F_325 ( L_295 , V_218 -> V_776 . V_147 ) ;
return 0 ;
}
static int F_348 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
if ( V_218 -> V_557 . V_62 & V_778 || V_218 -> V_557 . V_773 )
return - V_31 ;
if ( ! ( V_218 -> V_557 . V_62 & V_779 ) )
return 0 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) ) {
V_63 = - V_70 ;
goto V_621;
}
if ( V_218 -> V_557 . V_62 & V_780 ) {
V_63 = F_240 ( V_6 , V_218 -> V_557 . V_147 ) ;
F_325 ( L_296 ,
V_218 -> V_557 . V_147 ) ;
goto V_621;
}
if ( V_218 -> V_557 . V_62 & V_781 ) {
V_63 = F_241 ( V_6 , V_218 -> V_557 . V_147 ) ;
F_325 ( L_297 ,
V_218 -> V_557 . V_147 ) ;
goto V_621;
}
V_63 = F_240 ( V_6 , V_218 -> V_557 . V_147 ) ;
if ( ! V_63 )
V_63 = F_241 ( V_6 , V_218 -> V_557 . V_147 ) ;
F_325 ( L_298 , V_218 -> V_557 . V_147 ) ;
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_349 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_218 -> V_557 . V_773 = 0 ;
if ( ( V_218 -> V_557 . V_62 & V_782 ) == V_778 )
return - V_31 ;
if ( V_218 -> V_557 . V_62 & V_781 ) {
V_218 -> V_557 . V_62 = V_779 | V_781 ;
V_218 -> V_557 . V_147 = V_6 -> V_561 ;
} else {
V_218 -> V_557 . V_62 =
( V_6 -> V_559 !=
V_6 -> V_561 ) ?
V_779 | V_780 : V_779 ;
V_218 -> V_557 . V_147 = V_6 -> V_559 ;
}
F_325 ( L_299 , V_218 -> V_557 . V_147 ) ;
return 0 ;
}
static int F_350 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) ) {
V_63 = - V_70 ;
goto V_621;
}
F_325 ( L_300 ) ;
V_6 -> V_298 = 1 ;
if ( F_90 ( V_6 ) || F_92 ( V_6 ) ) {
F_325 ( L_301 ) ;
}
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_351 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_352 ( V_6 -> V_150 , V_81 , V_218 , V_706 ) ;
}
static int F_353 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_594 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_354 ( V_6 -> V_150 , V_81 , V_218 , V_594 ) ;
}
static int F_355 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_594 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_356 ( V_6 -> V_150 , V_81 , V_218 , V_594 ) ;
}
static int F_357 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) ) {
V_63 = - V_70 ;
goto V_621;
}
if ( V_218 -> V_783 . V_773 ) {
V_6 -> V_546 = F_237 ( V_6 -> V_546 ) ;
V_63 = F_236 ( V_6 , V_545 ) ;
F_325 ( L_302 ) ;
goto V_621;
}
switch ( V_218 -> V_783 . V_62 & V_784 ) {
case V_785 :
case V_784 :
case V_786 :
break;
default:
F_325 ( L_303 ,
V_218 -> V_783 . V_62 ) ;
V_63 = - V_640 ;
goto V_621;
}
V_6 -> V_546 = V_547 | V_6 -> V_546 ;
V_63 = F_236 ( V_6 , F_237 ( V_6 -> V_546 ) ) ;
F_325 ( L_304 , V_6 -> V_546 ) ;
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_358 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_546 & V_547 ) )
V_218 -> V_783 . V_773 = 1 ;
else {
V_218 -> V_783 . V_773 = 0 ;
V_218 -> V_783 . V_62 = 0 ;
}
F_325 ( L_305 , V_6 -> V_546 ) ;
return 0 ;
}
static int F_359 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_633 * V_150 = V_6 -> V_150 ;
T_3 * V_15 ;
if ( ! V_150 -> V_632 )
return - V_640 ;
if ( V_218 -> V_37 . V_285 > V_787 ||
( V_218 -> V_37 . V_285 && V_706 == NULL ) )
return - V_31 ;
if ( V_218 -> V_37 . V_285 ) {
V_15 = F_360 ( V_706 , V_218 -> V_37 . V_285 , V_239 ) ;
if ( V_15 == NULL )
return - V_240 ;
F_130 ( V_150 -> V_641 ) ;
V_150 -> V_641 = V_15 ;
V_150 -> V_642 = V_218 -> V_37 . V_285 ;
} else {
F_130 ( V_150 -> V_641 ) ;
V_150 -> V_641 = NULL ;
V_150 -> V_642 = 0 ;
}
V_564 ( V_6 , V_150 -> V_641 , V_150 -> V_642 ) ;
return 0 ;
}
static int F_361 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_633 * V_150 = V_6 -> V_150 ;
if ( V_150 -> V_642 == 0 || V_150 -> V_641 == NULL ) {
V_218 -> V_37 . V_285 = 0 ;
return 0 ;
}
if ( V_218 -> V_37 . V_285 < V_150 -> V_642 )
return - V_769 ;
V_218 -> V_37 . V_285 = V_150 -> V_642 ;
memcpy ( V_706 , V_150 -> V_641 , V_150 -> V_642 ) ;
return 0 ;
}
static int F_362 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_633 * V_150 = V_6 -> V_150 ;
struct V_788 * V_789 = & V_218 -> V_789 ;
struct V_790 * V_492 ;
unsigned long V_62 ;
int V_266 = 0 ;
switch ( V_789 -> V_62 & V_791 ) {
case V_792 :
case V_793 :
case V_794 :
case V_795 :
break;
case V_796 :
V_492 = V_6 -> V_150 -> V_491 . V_492 [ V_6 -> V_150 -> V_491 . V_493 ] ;
if ( ! V_492 || ! V_492 -> V_797 -> V_798 || ! V_492 -> V_797 -> V_799 )
break;
V_62 = V_492 -> V_797 -> V_799 ( V_492 -> V_6 ) ;
if ( V_789 -> V_147 )
V_62 |= V_800 ;
else
V_62 &= ~ V_800 ;
V_492 -> V_797 -> V_798 ( V_62 , V_492 -> V_6 ) ;
break;
case V_801 : {
struct V_618 V_190 = {
. V_62 = V_191 ,
. V_192 = V_789 -> V_147 ,
} ;
V_6 -> V_150 -> V_672 = V_789 -> V_147 ;
if ( ! V_789 -> V_147 ) {
V_190 . V_62 |= V_611 ;
V_190 . V_43 = V_573 ;
} else {
V_190 . V_62 |= V_611 ;
V_190 . V_43 = V_576 ;
}
if ( V_6 -> V_150 -> V_639 )
V_6 -> V_150 -> V_639 ( V_6 -> V_150 -> V_2 , & V_190 ) ;
break;
}
case V_802 :
V_266 = F_267 ( V_6 , V_789 -> V_147 ) ;
break;
case V_803 :
V_266 = F_266 ( V_6 , V_789 -> V_147 ) ;
break;
case V_804 :
V_150 -> V_674 = V_789 -> V_147 ;
break;
case V_805 :
V_150 -> V_673 = V_789 -> V_147 ;
break;
default:
return - V_640 ;
}
return V_266 ;
}
static int F_363 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_633 * V_150 = V_6 -> V_150 ;
struct V_790 * V_492 ;
struct V_788 * V_789 = & V_218 -> V_789 ;
int V_266 = 0 ;
switch ( V_789 -> V_62 & V_791 ) {
case V_792 :
case V_793 :
case V_794 :
case V_795 :
V_266 = - V_640 ;
break;
case V_796 :
V_492 = V_6 -> V_150 -> V_491 . V_492 [ V_6 -> V_150 -> V_491 . V_493 ] ;
if ( ! V_492 || ! V_492 -> V_797 -> V_799 ) {
F_153 ( L_306
L_307 ) ;
break;
}
V_789 -> V_147 = ( V_492 -> V_797 -> V_799 ( V_492 -> V_6 ) &
V_800 ) ? 1 : 0 ;
break;
case V_801 :
V_789 -> V_147 = V_150 -> V_672 ;
break;
case V_802 :
V_789 -> V_147 = V_6 -> V_150 -> V_190 . V_567 ;
break;
case V_803 :
V_789 -> V_147 = V_150 -> V_632 ;
break;
case V_804 :
V_789 -> V_147 = V_150 -> V_674 ;
break;
case V_806 :
case V_805 :
V_789 -> V_147 = V_150 -> V_673 ;
break;
default:
return - V_640 ;
}
return 0 ;
}
static int F_364 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_365 ( V_6 -> V_150 , V_81 , V_218 , V_706 ) ;
}
static int F_366 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_367 ( V_6 -> V_150 , V_81 , V_218 , V_706 ) ;
}
static int F_368 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_807 * V_808 = (struct V_807 * ) V_706 ;
T_16 V_809 ;
V_809 = F_151 ( V_808 -> V_810 ) ;
switch ( V_808 -> V_57 ) {
case V_811 :
break;
case V_812 :
F_243 ( V_6 ) ;
break;
default:
return - V_640 ;
}
return 0 ;
}
static int F_369 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int * V_813 = ( int * ) V_706 ;
int V_814 = ( V_813 [ 0 ] > 0 ) ;
int V_63 = 0 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) ) {
V_63 = - V_70 ;
goto V_621;
}
if ( V_814 ) {
if ( V_6 -> V_150 -> V_198 == V_199 ) {
V_63 = F_232 ( V_6 , V_813 [ 1 ] , 0 ) ;
goto V_621;
}
V_6 -> V_245 = V_813 [ 1 ] ;
V_63 = F_196 ( V_6 , V_199 ) ;
} else {
if ( V_6 -> V_150 -> V_198 == V_199 )
V_63 = F_196 ( V_6 , V_6 -> V_489 ) ;
}
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_370 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_49 & V_620 )
F_35 ( V_6 ) ;
return 0 ;
}
static int F_371 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 , V_313 = * ( int * ) V_706 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) ) {
V_63 = - V_70 ;
goto V_621;
}
if ( ( V_313 < 0 ) || ( V_313 > V_735 ) )
V_313 = V_671 ;
if ( F_237 ( V_6 -> V_546 ) != V_313 )
V_63 = F_236 ( V_6 , V_313 ) ;
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_372 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_43 = F_237 ( V_6 -> V_546 ) ;
T_17 V_815 , V_816 ;
if ( ! ( V_6 -> V_546 & V_547 ) ) {
snprintf ( V_706 , V_817 ,
L_308 , V_43 ) ;
} else {
switch ( V_43 ) {
case V_545 :
snprintf ( V_706 , V_817 ,
L_309 , V_43 ) ;
break;
case V_671 :
snprintf ( V_706 , V_817 ,
L_310 , V_43 ) ;
break;
default:
V_815 = V_737 [ V_43 - 1 ] / 1000 ;
V_816 = V_733 [ V_43 - 1 ] / 1000 ;
snprintf ( V_706 , V_817 ,
L_311
L_312 ,
V_43 , V_815 , V_816 ) ;
}
}
V_218 -> V_37 . V_285 = strlen ( V_706 ) + 1 ;
return 0 ;
}
static int F_373 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 , V_313 = * ( int * ) V_706 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) ) {
V_63 = - V_70 ;
goto V_621;
}
if ( V_313 == 1 )
V_6 -> V_187 |= V_529 ;
else if ( V_313 == 0 )
V_6 -> V_187 &= ~ V_529 ;
else {
V_63 = - V_31 ;
goto V_621;
}
V_63 = F_233 ( V_6 , 0 ) ;
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_374 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_529 )
snprintf ( V_218 -> V_51 , V_707 , L_313 ) ;
else
snprintf ( V_218 -> V_51 , V_707 , L_314 ) ;
return 0 ;
}
static int F_375 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 , V_313 = * ( int * ) V_706 ;
F_84 ( & V_6 -> V_265 ) ;
if ( ! ( V_6 -> V_49 & V_620 ) ) {
V_63 = - V_70 ;
goto V_621;
}
if ( V_313 == 1 )
V_6 -> V_187 |= V_344 ;
else if ( V_313 == 0 )
V_6 -> V_187 &= ~ V_344 ;
else {
V_63 = - V_31 ;
goto V_621;
}
V_63 = 0 ;
V_621:
F_85 ( & V_6 -> V_265 ) ;
return V_63 ;
}
static int F_376 ( struct V_1 * V_2 ,
struct V_705 * V_81 ,
union V_217 * V_218 , char * V_706 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_187 & V_344 )
snprintf ( V_218 -> V_51 , V_707 , L_315 ) ;
else
snprintf ( V_218 -> V_51 , V_707 , L_316 ) ;
return 0 ;
}
static struct V_818 * F_377 ( struct V_1 * V_2 )
{
enum {
V_819 = 30 ,
V_820 = 60 ,
V_821 = 80 ,
V_822 = 90 ,
V_823 = 95 ,
V_824 = 100
};
int V_825 ;
int V_826 ;
int V_827 ;
int V_828 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_818 * V_302 ;
T_1 V_352 , V_829 , V_830 , V_831 ;
T_1 V_204 = sizeof( T_1 ) ;
if ( ! V_6 )
return (struct V_818 * ) NULL ;
V_302 = & V_6 -> V_302 ;
if ( ! ( V_6 -> V_49 & V_166 ) ) {
V_302 -> V_832 . V_833 = 0 ;
V_302 -> V_332 . V_834 = 0 ;
V_302 -> V_718 . V_718 = 0 ;
V_302 -> V_718 . V_43 = 0 ;
V_302 -> V_718 . V_719 = 0 ;
V_302 -> V_718 . V_720 = 7 ;
V_302 -> V_718 . V_720 |= V_835 |
V_836 | V_837 ;
return V_302 ;
}
if ( F_26 ( V_6 , V_838 ,
& V_830 , & V_204 ) )
goto V_839;
if ( ! ( V_6 -> V_49 & V_166 ) ) {
V_302 -> V_718 . V_718 = 0 ;
V_302 -> V_718 . V_43 = 0 ;
} else {
if ( F_26 ( V_6 , V_840 ,
& V_352 , & V_204 ) )
goto V_839;
V_302 -> V_718 . V_43 = V_352 + V_353 ;
if ( V_352 < 10 )
V_825 = V_352 * V_819 / 10 ;
else if ( V_352 < 15 )
V_825 = ( V_352 - 10 ) * ( V_820 - V_819 ) / 5 + V_819 ;
else if ( V_352 < 20 )
V_825 = ( V_352 - 15 ) * ( V_821 - V_820 ) / 5 + V_820 ;
else if ( V_352 < 30 )
V_825 = ( V_352 - 20 ) * ( V_822 - V_821 ) /
10 + V_821 ;
else
V_825 = ( V_352 - 30 ) * ( V_824 - V_822 ) /
10 + V_822 ;
if ( F_26 ( V_6 , V_841 ,
& V_829 , & V_204 ) )
goto V_839;
if ( V_829 > 75 )
V_826 = ( 90 - V_829 ) * V_819 / 15 ;
else if ( V_829 > 70 )
V_826 = ( 75 - V_829 ) * ( V_820 - V_819 ) / 5 + V_819 ;
else if ( V_829 > 65 )
V_826 = ( 70 - V_829 ) * ( V_821 - V_820 ) / 5 + V_820 ;
else if ( V_829 > 50 )
V_826 = ( 65 - V_829 ) * ( V_822 - V_821 ) /
15 + V_821 ;
else
V_826 = ( 50 - V_829 ) *
( V_824 - V_822 ) / 50 + V_822 ;
if ( V_830 > 50 )
V_827 = ( 60 - V_830 ) * V_819 / 10 ;
else if ( V_830 > 40 )
V_827 = ( 50 - V_830 ) * ( V_820 - V_819 ) /
10 + V_819 ;
else if ( V_830 > 32 )
V_827 = ( 40 - V_830 ) * ( V_821 - V_820 ) /
18 + V_820 ;
else if ( V_830 > 20 )
V_827 = ( 32 - V_830 ) *
( V_822 - V_821 ) / 20 + V_821 ;
else
V_827 = ( 20 - V_830 ) *
( V_824 - V_822 ) / 20 + V_822 ;
V_828 = F_34 ( V_826 , V_825 ) ;
V_828 = F_34 ( V_827 , V_828 ) ;
#ifdef F_123
if ( V_827 == V_828 )
F_325 ( L_317 ) ;
else if ( V_826 == V_828 )
F_325 ( L_318 ) ;
else if ( V_828 != 100 )
F_325 ( L_319 ) ;
else
F_325 ( L_320 ) ;
#endif
V_302 -> V_718 . V_718 = V_828 ;
V_302 -> V_718 . V_43 = V_352 + V_353 ;
}
V_302 -> V_718 . V_719 = 0 ;
V_302 -> V_718 . V_720 = 7 ;
V_302 -> V_718 . V_720 |= V_835 ;
V_302 -> V_832 . V_833 = V_830 ;
if ( F_26 ( V_6 , V_842 ,
& V_831 , & V_204 ) )
goto V_839;
V_302 -> V_332 . V_834 = V_831 ;
return V_302 ;
V_839:
F_325 ( L_288 ) ;
return (struct V_818 * ) NULL ;
}
static void V_687 ( struct V_261 * V_262 )
{
struct V_5 * V_6 =
F_108 ( V_262 , struct V_5 , V_284 . V_262 ) ;
union V_217 V_218 ;
unsigned int V_14 = V_230 ;
if ( V_6 -> V_49 & V_184 )
return;
F_84 ( & V_6 -> V_265 ) ;
F_325 ( L_42 ) ;
F_85 ( & V_6 -> V_265 ) ;
V_218 . V_219 . V_220 = V_221 ;
if ( ! ( V_6 -> V_49 & ( V_165 | V_166 ) ) ||
V_6 -> V_49 & V_485 ||
F_26 ( V_6 , V_277 ,
& V_6 -> V_273 , & V_14 ) ) {
F_114 ( V_218 . V_219 . V_629 ) ;
} else {
memcpy ( V_218 . V_219 . V_629 , V_6 -> V_273 , V_230 ) ;
memcpy ( V_6 -> V_150 -> V_273 , V_6 -> V_273 , V_230 ) ;
V_6 -> V_49 &= ~ V_165 ;
V_6 -> V_49 |= V_166 ;
F_262 ( V_6 -> V_33 ) ;
F_164 ( V_6 -> V_33 ) ;
}
if ( ! ( V_6 -> V_49 & V_166 ) ) {
F_325 ( L_321 ) ;
F_84 ( & V_6 -> V_265 ) ;
if ( V_6 -> V_187 & V_282 )
F_111 ( V_6 , V_6 -> V_268 , V_6 -> V_267 ,
0 ) ;
else
F_111 ( V_6 , NULL , 0 , 0 ) ;
F_85 ( & V_6 -> V_265 ) ;
}
F_100 ( V_6 -> V_33 , V_224 , & V_218 , NULL ) ;
}
static int F_378 ( struct V_119 * V_843 )
{
struct V_844 * V_845 =
(struct V_844 * ) V_843 -> V_846 -> V_37 ;
if ( F_379 ( V_845 -> V_121 ) != V_847 ) {
F_27 (KERN_WARNING DRV_NAME L_322
L_323
L_324 ,
h->version) ;
return 1 ;
}
V_843 -> V_121 = V_845 -> V_121 ;
V_843 -> V_843 . V_37 = V_843 -> V_846 -> V_37 + sizeof( struct V_844 ) ;
V_843 -> V_843 . V_479 = V_845 -> V_848 ;
V_843 -> V_849 . V_37 = V_843 -> V_843 . V_37 + V_845 -> V_848 ;
V_843 -> V_849 . V_479 = V_845 -> V_850 ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 ,
struct V_119 * V_843 )
{
char * V_851 ;
int V_202 ;
F_31 ( L_325 ,
V_6 -> V_33 -> V_51 ) ;
switch ( V_6 -> V_150 -> V_198 ) {
case V_432 :
V_851 = F_380 ( L_326 ) ;
break;
#ifdef F_155
case V_199 :
V_851 = F_380 ( L_327 ) ;
break;
#endif
case V_427 :
default:
V_851 = F_380 ( L_50 ) ;
break;
}
V_202 = F_381 ( & V_843 -> V_846 , V_851 , & V_6 -> V_260 -> V_2 ) ;
if ( V_202 < 0 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_328 ,
priv->net_dev->name, fw_name) ;
return V_202 ;
}
F_31 ( L_329 , V_843 -> V_846 -> V_37 ,
V_843 -> V_846 -> V_479 ) ;
F_378 ( V_843 ) ;
return 0 ;
}
static void F_66 ( struct V_5 * V_6 ,
struct V_119 * V_843 )
{
V_843 -> V_121 = 0 ;
F_382 ( V_843 -> V_846 ) ;
V_843 -> V_846 = NULL ;
}
static int F_270 ( struct V_5 * V_6 , char * V_15 ,
T_4 V_852 )
{
char V_853 [ V_854 ] ;
T_1 V_14 = V_854 ;
T_1 V_314 ;
int V_19 ;
if ( F_26 ( V_6 , V_855 , V_853 , & V_14 ) )
return - V_70 ;
V_314 = V_852 ;
if ( V_14 >= V_852 )
V_14 = V_852 - 1 ;
for ( V_19 = 0 ; V_19 < V_14 ; V_19 ++ )
V_15 [ V_19 ] = V_853 [ V_19 ] ;
V_15 [ V_19 ] = '\0' ;
return V_314 ;
}
static int F_271 ( struct V_5 * V_6 , char * V_15 ,
T_4 V_852 )
{
T_1 V_853 ;
T_1 V_14 = sizeof( V_853 ) ;
if ( F_26 ( V_6 , V_856 , & V_853 , & V_14 ) )
return - V_70 ;
return snprintf ( V_15 , V_852 , L_14 , V_853 ) ;
}
static int F_65 ( struct V_5 * V_6 , struct V_119 * V_843 )
{
unsigned int V_8 ;
unsigned short V_14 ;
const unsigned char * V_857 = V_843 -> V_843 . V_37 ;
unsigned int V_858 = V_843 -> V_843 . V_479 ;
while ( V_858 > 0 ) {
V_8 = * ( T_1 * ) ( V_857 ) ;
V_857 += 4 ;
V_858 -= 4 ;
V_14 = * ( T_2 * ) ( V_857 ) ;
V_857 += 2 ;
V_858 -= 2 ;
if ( V_14 > 32 ) {
F_27 (KERN_ERR DRV_NAME L_67
L_330 ,
len) ;
return - V_31 ;
}
F_23 ( V_6 -> V_33 , V_8 , V_14 , V_857 ) ;
V_857 += V_14 ;
V_858 -= V_14 ;
}
return 0 ;
}
static int F_64 ( struct V_5 * V_6 ,
struct V_119 * V_843 )
{
struct V_1 * V_2 = V_6 -> V_33 ;
const unsigned char * V_859 = V_843 -> V_849 . V_37 ;
unsigned int V_860 = V_843 -> V_849 . V_479 ;
void T_12 * V_3 = V_6 -> V_7 ;
struct V_861 V_862 ;
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
while ( V_860 > 0 ) {
F_20 ( V_2 , 0x210010 , * V_859 ++ ) ;
F_20 ( V_2 , 0x210010 , * V_859 ++ ) ;
V_860 -= 2 ;
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
F_27 (KERN_ERR DRV_NAME L_331 ,
dev->name) ;
return - V_70 ;
}
for ( V_19 = 0 ; V_19 < 30 ; V_19 ++ ) {
for ( V_40 = 0 ;
V_40 < ( sizeof( struct V_861 ) >> 1 ) ; V_40 ++ )
F_17 ( V_2 , 0x210004 , ( ( T_2 * ) & V_862 ) + V_40 ) ;
if ( ( V_862 . V_863 == 1 ) && ( V_862 . V_864 == 0x1 ) )
break;
F_58 ( 10 ) ;
}
if ( V_19 == 30 ) {
F_27 (KERN_ERR DRV_NAME
L_332 ,
dev->name) ;
F_33 ( V_865 , ( T_3 * ) & V_862 , sizeof( V_862 ) ) ;
return - V_70 ;
}
return 0 ;
}
