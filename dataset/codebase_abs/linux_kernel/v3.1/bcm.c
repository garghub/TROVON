static inline T_1 F_1 ( const struct V_1 * V_2 )
{
return * ( T_1 * ) V_2 -> V_3 ;
}
static inline struct V_4 * F_2 ( const struct V_5 * V_6 )
{
return (struct V_4 * ) V_6 ;
}
static char * F_3 ( char * V_7 , int V_8 )
{
struct V_9 * V_10 ;
if ( ! V_8 )
return L_1 ;
F_4 () ;
V_10 = F_5 ( & V_11 , V_8 ) ;
if ( V_10 )
strcpy ( V_7 , V_10 -> V_12 ) ;
else
strcpy ( V_7 , L_2 ) ;
F_6 () ;
return V_7 ;
}
static int F_7 ( struct V_13 * V_14 , void * V_15 )
{
char V_16 [ V_17 ] ;
struct V_5 * V_6 = (struct V_5 * ) V_14 -> V_18 ;
struct V_4 * V_19 = F_2 ( V_6 ) ;
struct V_20 * V_21 ;
F_8 ( V_14 , L_3 , V_6 -> V_22 ) ;
F_8 ( V_14 , L_4 , V_6 ) ;
F_8 ( V_14 , L_5 , V_19 ) ;
F_8 ( V_14 , L_6 , V_19 -> V_23 ) ;
F_8 ( V_14 , L_7 , F_3 ( V_16 , V_19 -> V_8 ) ) ;
F_8 ( V_14 , L_8 ) ;
F_9 (op, &bo->rx_ops, list) {
unsigned long V_24 ;
if ( ! V_21 -> V_25 )
continue;
F_8 ( V_14 , L_9 ,
V_21 -> V_26 , F_3 ( V_16 , V_21 -> V_8 ) ) ;
F_8 ( V_14 , L_10 , V_21 -> V_27 ,
( V_21 -> V_28 & V_29 ) ? 'd' : ' ' ) ;
if ( V_21 -> V_30 . V_31 )
F_8 ( V_14 , L_11 ,
( long long )
F_10 ( V_21 -> V_30 ) ) ;
if ( V_21 -> V_32 . V_31 )
F_8 ( V_14 , L_12 ,
( long long )
F_10 ( V_21 -> V_32 ) ) ;
F_8 ( V_14 , L_13 ,
V_21 -> V_33 , V_21 -> V_25 ) ;
V_24 = 100 - ( V_21 -> V_33 * 100 ) / V_21 -> V_25 ;
F_8 ( V_14 , L_14 ,
( V_24 == 100 ) ? L_15 : L_16 , V_24 ) ;
}
F_9 (op, &bo->tx_ops, list) {
F_8 ( V_14 , L_17 ,
V_21 -> V_26 ,
F_3 ( V_16 , V_21 -> V_8 ) ,
V_21 -> V_27 ) ;
if ( V_21 -> V_30 . V_31 )
F_8 ( V_14 , L_18 ,
( long long ) F_10 ( V_21 -> V_30 ) ) ;
if ( V_21 -> V_32 . V_31 )
F_8 ( V_14 , L_19 ,
( long long ) F_10 ( V_21 -> V_32 ) ) ;
F_8 ( V_14 , L_20 , V_21 -> V_25 ) ;
}
F_11 ( V_14 , '\n' ) ;
return 0 ;
}
static int F_12 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
return F_13 ( V_35 , F_7 , F_14 ( V_34 ) -> V_3 ) ;
}
static void F_15 ( struct V_20 * V_21 )
{
struct V_36 * V_37 ;
struct V_9 * V_10 ;
struct V_1 * V_38 = & V_21 -> V_39 [ V_21 -> V_40 ] ;
if ( ! V_21 -> V_8 )
return;
V_10 = F_16 ( & V_11 , V_21 -> V_8 ) ;
if ( ! V_10 ) {
return;
}
V_37 = F_17 ( V_41 , F_18 () ) ;
if ( ! V_37 )
goto V_42;
memcpy ( F_19 ( V_37 , V_41 ) , V_38 , V_41 ) ;
V_37 -> V_10 = V_10 ;
V_37 -> V_6 = V_21 -> V_6 ;
F_20 ( V_37 , 1 ) ;
V_21 -> V_40 ++ ;
V_21 -> V_25 ++ ;
if ( V_21 -> V_40 >= V_21 -> V_27 )
V_21 -> V_40 = 0 ;
V_42:
F_21 ( V_10 ) ;
}
static void F_22 ( struct V_20 * V_21 , struct V_43 * V_44 ,
struct V_1 * V_39 , int V_45 )
{
struct V_36 * V_37 ;
struct V_1 * V_46 ;
struct V_47 * V_48 ;
struct V_5 * V_6 = V_21 -> V_6 ;
unsigned int V_49 = V_44 -> V_27 * V_41 ;
int V_50 ;
V_37 = F_17 ( sizeof( * V_44 ) + V_49 , F_18 () ) ;
if ( ! V_37 )
return;
memcpy ( F_19 ( V_37 , sizeof( * V_44 ) ) , V_44 , sizeof( * V_44 ) ) ;
if ( V_44 -> V_27 ) {
V_46 = (struct V_1 * ) F_23 ( V_37 ) ;
memcpy ( F_19 ( V_37 , V_49 ) , V_39 , V_49 ) ;
if ( V_44 -> V_27 == 1 )
V_46 -> V_51 &= V_52 ;
}
if ( V_45 ) {
V_37 -> V_53 = V_21 -> V_54 ;
}
F_24 ( sizeof( V_37 -> V_55 ) < sizeof( struct V_47 ) ) ;
V_48 = (struct V_47 * ) V_37 -> V_55 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_56 = V_57 ;
V_48 -> V_58 = V_21 -> V_59 ;
V_50 = F_25 ( V_6 , V_37 ) ;
if ( V_50 < 0 ) {
struct V_4 * V_19 = F_2 ( V_6 ) ;
F_26 ( V_37 ) ;
V_19 -> V_23 ++ ;
}
}
static void F_27 ( struct V_20 * V_21 )
{
if ( V_21 -> V_30 . V_31 && V_21 -> V_60 )
F_28 ( & V_21 -> V_61 ,
F_29 ( F_30 () , V_21 -> V_30 ) ,
V_62 ) ;
else if ( V_21 -> V_32 . V_31 )
F_28 ( & V_21 -> V_61 ,
F_29 ( F_30 () , V_21 -> V_32 ) ,
V_62 ) ;
}
static void F_31 ( unsigned long V_3 )
{
struct V_20 * V_21 = (struct V_20 * ) V_3 ;
struct V_43 V_63 ;
if ( V_21 -> V_30 . V_31 && ( V_21 -> V_60 > 0 ) ) {
V_21 -> V_60 -- ;
if ( ! V_21 -> V_60 && ( V_21 -> V_28 & V_64 ) ) {
V_63 . V_65 = V_66 ;
V_63 . V_28 = V_21 -> V_28 ;
V_63 . V_60 = V_21 -> V_60 ;
V_63 . V_67 = V_21 -> V_67 ;
V_63 . V_68 = V_21 -> V_68 ;
V_63 . V_26 = V_21 -> V_26 ;
V_63 . V_27 = 0 ;
F_22 ( V_21 , & V_63 , NULL , 0 ) ;
}
F_15 ( V_21 ) ;
} else if ( V_21 -> V_32 . V_31 )
F_15 ( V_21 ) ;
F_27 ( V_21 ) ;
}
static enum V_69 F_32 ( struct V_70 * V_70 )
{
struct V_20 * V_21 = F_33 ( V_70 , struct V_20 , V_61 ) ;
F_34 ( & V_21 -> V_71 ) ;
return V_72 ;
}
static void F_35 ( struct V_20 * V_21 , struct V_1 * V_3 )
{
struct V_43 V_44 ;
V_21 -> V_33 ++ ;
if ( V_21 -> V_33 > V_73 / 100 )
V_21 -> V_33 = V_21 -> V_25 = 0 ;
V_3 -> V_51 &= ( V_52 | V_74 ) ;
V_44 . V_65 = V_75 ;
V_44 . V_28 = V_21 -> V_28 ;
V_44 . V_60 = V_21 -> V_60 ;
V_44 . V_67 = V_21 -> V_67 ;
V_44 . V_68 = V_21 -> V_68 ;
V_44 . V_26 = V_21 -> V_26 ;
V_44 . V_27 = 1 ;
F_22 ( V_21 , & V_44 , V_3 , 1 ) ;
}
static void F_36 ( struct V_20 * V_21 ,
struct V_1 * V_76 ,
const struct V_1 * V_77 )
{
memcpy ( V_76 , V_77 , V_41 ) ;
V_76 -> V_51 |= ( V_74 | V_78 ) ;
if ( ! V_21 -> V_32 . V_31 ) {
F_35 ( V_21 , V_76 ) ;
return;
}
if ( F_37 ( & V_21 -> V_79 ) )
return;
if ( ! V_21 -> V_80 . V_31 )
goto V_81;
if ( F_38 ( F_30 () , V_21 -> V_80 ) <
F_10 ( V_21 -> V_32 ) ) {
F_28 ( & V_21 -> V_79 ,
F_29 ( V_21 -> V_80 , V_21 -> V_32 ) ,
V_62 ) ;
return;
}
V_81:
F_35 ( V_21 , V_76 ) ;
V_21 -> V_80 = F_30 () ;
}
static void F_39 ( struct V_20 * V_21 , unsigned int V_82 ,
const struct V_1 * V_77 )
{
if ( ! ( V_21 -> V_83 [ V_82 ] . V_51 & V_74 ) ) {
F_36 ( V_21 , & V_21 -> V_83 [ V_82 ] , V_77 ) ;
return;
}
if ( ( F_1 ( & V_21 -> V_39 [ V_82 ] ) & F_1 ( V_77 ) ) !=
( F_1 ( & V_21 -> V_39 [ V_82 ] ) & F_1 ( & V_21 -> V_83 [ V_82 ] ) ) ) {
F_36 ( V_21 , & V_21 -> V_83 [ V_82 ] , V_77 ) ;
return;
}
if ( V_21 -> V_28 & V_29 ) {
if ( V_77 -> V_51 != ( V_21 -> V_83 [ V_82 ] . V_51 &
V_52 ) ) {
F_36 ( V_21 , & V_21 -> V_83 [ V_82 ] ,
V_77 ) ;
return;
}
}
}
static void F_40 ( struct V_20 * V_21 )
{
if ( V_21 -> V_28 & V_84 )
return;
if ( V_21 -> V_30 . V_31 )
F_28 ( & V_21 -> V_61 , V_21 -> V_30 , V_85 ) ;
}
static void F_41 ( unsigned long V_3 )
{
struct V_20 * V_21 = (struct V_20 * ) V_3 ;
struct V_43 V_63 ;
V_63 . V_65 = V_86 ;
V_63 . V_28 = V_21 -> V_28 ;
V_63 . V_60 = V_21 -> V_60 ;
V_63 . V_67 = V_21 -> V_67 ;
V_63 . V_68 = V_21 -> V_68 ;
V_63 . V_26 = V_21 -> V_26 ;
V_63 . V_27 = 0 ;
F_22 ( V_21 , & V_63 , NULL , 0 ) ;
}
static enum V_69 F_42 ( struct V_70 * V_70 )
{
struct V_20 * V_21 = F_33 ( V_70 , struct V_20 , V_61 ) ;
F_43 ( & V_21 -> V_71 ) ;
if ( ( V_21 -> V_28 & V_87 ) && V_21 -> V_83 ) {
memset ( V_21 -> V_83 , 0 , V_21 -> V_27 * V_41 ) ;
}
return V_72 ;
}
static inline int F_44 ( struct V_20 * V_21 , int V_88 ,
unsigned int V_82 )
{
if ( ( V_21 -> V_83 ) && ( V_21 -> V_83 [ V_82 ] . V_51 & V_78 ) ) {
if ( V_88 )
F_35 ( V_21 , & V_21 -> V_83 [ V_82 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_45 ( struct V_20 * V_21 , int V_88 )
{
int V_89 = 0 ;
if ( V_21 -> V_27 > 1 ) {
unsigned int V_90 ;
for ( V_90 = 1 ; V_90 < V_21 -> V_27 ; V_90 ++ )
V_89 += F_44 ( V_21 , V_88 , V_90 ) ;
} else {
V_89 += F_44 ( V_21 , V_88 , 0 ) ;
}
return V_89 ;
}
static void F_46 ( unsigned long V_3 )
{
struct V_20 * V_21 = (struct V_20 * ) V_3 ;
F_45 ( V_21 , 1 ) ;
}
static enum V_69 F_47 ( struct V_70 * V_70 )
{
struct V_20 * V_21 = F_33 ( V_70 , struct V_20 , V_79 ) ;
F_34 ( & V_21 -> V_91 ) ;
if ( F_45 ( V_21 , 0 ) ) {
F_48 ( V_70 , F_30 () , V_21 -> V_32 ) ;
return V_92 ;
} else {
V_21 -> V_80 = F_49 ( 0 , 0 ) ;
return V_72 ;
}
}
static void F_50 ( struct V_36 * V_37 , void * V_3 )
{
struct V_20 * V_21 = (struct V_20 * ) V_3 ;
const struct V_1 * V_93 = (struct V_1 * ) V_37 -> V_3 ;
unsigned int V_90 ;
F_51 ( & V_21 -> V_61 ) ;
if ( V_21 -> V_26 != V_93 -> V_26 )
return;
V_21 -> V_54 = V_37 -> V_53 ;
V_21 -> V_59 = V_37 -> V_10 -> V_8 ;
V_21 -> V_25 ++ ;
if ( V_21 -> V_28 & V_94 ) {
F_15 ( V_21 ) ;
return;
}
if ( V_21 -> V_28 & V_95 ) {
F_36 ( V_21 , & V_21 -> V_83 [ 0 ] , V_93 ) ;
goto V_96;
}
if ( V_21 -> V_27 == 1 ) {
F_39 ( V_21 , 0 , V_93 ) ;
goto V_96;
}
if ( V_21 -> V_27 > 1 ) {
for ( V_90 = 1 ; V_90 < V_21 -> V_27 ; V_90 ++ ) {
if ( ( F_1 ( & V_21 -> V_39 [ 0 ] ) & F_1 ( V_93 ) ) ==
( F_1 ( & V_21 -> V_39 [ 0 ] ) &
F_1 ( & V_21 -> V_39 [ V_90 ] ) ) ) {
F_39 ( V_21 , V_90 , V_93 ) ;
break;
}
}
}
V_96:
F_40 ( V_21 ) ;
}
static struct V_20 * F_52 ( struct V_97 * V_98 , T_2 V_26 ,
int V_8 )
{
struct V_20 * V_21 ;
F_9 (op, ops, list) {
if ( ( V_21 -> V_26 == V_26 ) && ( V_21 -> V_8 == V_8 ) )
return V_21 ;
}
return NULL ;
}
static void F_53 ( struct V_20 * V_21 )
{
F_51 ( & V_21 -> V_61 ) ;
F_51 ( & V_21 -> V_79 ) ;
if ( V_21 -> V_71 . V_99 )
F_54 ( & V_21 -> V_71 ) ;
if ( V_21 -> V_91 . V_99 )
F_54 ( & V_21 -> V_91 ) ;
if ( ( V_21 -> V_39 ) && ( V_21 -> V_39 != & V_21 -> V_100 ) )
F_55 ( V_21 -> V_39 ) ;
if ( ( V_21 -> V_83 ) && ( V_21 -> V_83 != & V_21 -> V_101 ) )
F_55 ( V_21 -> V_83 ) ;
F_55 ( V_21 ) ;
}
static void F_56 ( struct V_9 * V_10 , struct V_20 * V_21 )
{
if ( V_21 -> V_102 == V_10 ) {
F_57 ( V_10 , V_21 -> V_26 , F_58 ( V_21 -> V_26 ) ,
F_50 , V_21 ) ;
V_21 -> V_102 = NULL ;
} else
F_59 ( V_103 L_21
L_22 , V_21 -> V_102 , V_10 ) ;
}
static int F_60 ( struct V_97 * V_98 , T_2 V_26 , int V_8 )
{
struct V_20 * V_21 , * V_104 ;
F_61 (op, n, ops, list) {
if ( ( V_21 -> V_26 == V_26 ) && ( V_21 -> V_8 == V_8 ) ) {
if ( V_21 -> V_8 ) {
if ( V_21 -> V_102 ) {
struct V_9 * V_10 ;
V_10 = F_16 ( & V_11 ,
V_21 -> V_8 ) ;
if ( V_10 ) {
F_56 ( V_10 , V_21 ) ;
F_21 ( V_10 ) ;
}
}
} else
F_57 ( NULL , V_21 -> V_26 ,
F_58 ( V_21 -> V_26 ) ,
F_50 , V_21 ) ;
F_62 ( & V_21 -> V_105 ) ;
F_53 ( V_21 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_63 ( struct V_97 * V_98 , T_2 V_26 , int V_8 )
{
struct V_20 * V_21 , * V_104 ;
F_61 (op, n, ops, list) {
if ( ( V_21 -> V_26 == V_26 ) && ( V_21 -> V_8 == V_8 ) ) {
F_62 ( & V_21 -> V_105 ) ;
F_53 ( V_21 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_64 ( struct V_97 * V_98 , struct V_43 * V_63 ,
int V_8 )
{
struct V_20 * V_21 = F_52 ( V_98 , V_63 -> V_26 , V_8 ) ;
if ( ! V_21 )
return - V_106 ;
V_63 -> V_28 = V_21 -> V_28 ;
V_63 -> V_60 = V_21 -> V_60 ;
V_63 -> V_67 = V_21 -> V_67 ;
V_63 -> V_68 = V_21 -> V_68 ;
V_63 -> V_27 = V_21 -> V_27 ;
F_22 ( V_21 , V_63 , V_21 -> V_39 , 0 ) ;
return V_107 ;
}
static int F_65 ( struct V_43 * V_63 , struct V_108 * V_109 ,
int V_8 , struct V_5 * V_6 )
{
struct V_4 * V_19 = F_2 ( V_6 ) ;
struct V_20 * V_21 ;
unsigned int V_90 ;
int V_50 ;
if ( ! V_8 )
return - V_110 ;
if ( V_63 -> V_27 < 1 || V_63 -> V_27 > V_111 )
return - V_106 ;
V_21 = F_52 ( & V_19 -> V_112 , V_63 -> V_26 , V_8 ) ;
if ( V_21 ) {
if ( V_63 -> V_27 > V_21 -> V_27 )
return - V_113 ;
for ( V_90 = 0 ; V_90 < V_63 -> V_27 ; V_90 ++ ) {
V_50 = F_66 ( ( V_114 * ) & V_21 -> V_39 [ V_90 ] ,
V_109 -> V_115 , V_41 ) ;
if ( V_21 -> V_39 [ V_90 ] . V_51 > 8 )
V_50 = - V_106 ;
if ( V_50 < 0 )
return V_50 ;
if ( V_63 -> V_28 & V_116 ) {
V_21 -> V_39 [ V_90 ] . V_26 = V_63 -> V_26 ;
}
}
} else {
V_21 = F_67 ( V_117 , V_118 ) ;
if ( ! V_21 )
return - V_119 ;
V_21 -> V_26 = V_63 -> V_26 ;
if ( V_63 -> V_27 > 1 ) {
V_21 -> V_39 = F_68 ( V_63 -> V_27 * V_41 ,
V_118 ) ;
if ( ! V_21 -> V_39 ) {
F_55 ( V_21 ) ;
return - V_119 ;
}
} else
V_21 -> V_39 = & V_21 -> V_100 ;
for ( V_90 = 0 ; V_90 < V_63 -> V_27 ; V_90 ++ ) {
V_50 = F_66 ( ( V_114 * ) & V_21 -> V_39 [ V_90 ] ,
V_109 -> V_115 , V_41 ) ;
if ( V_21 -> V_39 [ V_90 ] . V_51 > 8 )
V_50 = - V_106 ;
if ( V_50 < 0 ) {
if ( V_21 -> V_39 != & V_21 -> V_100 )
F_55 ( V_21 -> V_39 ) ;
F_55 ( V_21 ) ;
return V_50 ;
}
if ( V_63 -> V_28 & V_116 ) {
V_21 -> V_39 [ V_90 ] . V_26 = V_63 -> V_26 ;
}
}
V_21 -> V_83 = NULL ;
V_21 -> V_6 = V_6 ;
V_21 -> V_8 = V_8 ;
F_69 ( & V_21 -> V_61 , V_120 , V_85 ) ;
V_21 -> V_61 . V_121 = F_32 ;
F_70 ( & V_21 -> V_71 , F_31 ,
( unsigned long ) V_21 ) ;
F_69 ( & V_21 -> V_79 , V_120 , V_85 ) ;
F_71 ( & V_21 -> V_105 , & V_19 -> V_112 ) ;
}
if ( V_21 -> V_27 != V_63 -> V_27 ) {
V_21 -> V_27 = V_63 -> V_27 ;
V_21 -> V_40 = 0 ;
}
V_21 -> V_28 = V_63 -> V_28 ;
if ( V_21 -> V_28 & V_122 ) {
V_21 -> V_40 = 0 ;
}
if ( V_21 -> V_28 & V_123 ) {
V_21 -> V_60 = V_63 -> V_60 ;
V_21 -> V_67 = V_63 -> V_67 ;
V_21 -> V_68 = V_63 -> V_68 ;
V_21 -> V_30 = F_72 ( V_63 -> V_67 ) ;
V_21 -> V_32 = F_72 ( V_63 -> V_68 ) ;
if ( ! V_21 -> V_30 . V_31 && ! V_21 -> V_32 . V_31 )
F_51 ( & V_21 -> V_61 ) ;
}
if ( V_21 -> V_28 & V_124 ) {
F_51 ( & V_21 -> V_61 ) ;
V_21 -> V_28 |= V_125 ;
}
if ( V_21 -> V_28 & V_125 ) {
F_15 ( V_21 ) ;
if ( V_21 -> V_60 )
V_21 -> V_60 -- ;
}
if ( V_21 -> V_28 & V_124 )
F_27 ( V_21 ) ;
return V_63 -> V_27 * V_41 + V_107 ;
}
static int F_73 ( struct V_43 * V_63 , struct V_108 * V_109 ,
int V_8 , struct V_5 * V_6 )
{
struct V_4 * V_19 = F_2 ( V_6 ) ;
struct V_20 * V_21 ;
int V_126 ;
int V_50 = 0 ;
if ( ( V_63 -> V_28 & V_95 ) || ( ! ( V_63 -> V_27 ) ) ) {
V_63 -> V_28 |= V_95 ;
V_63 -> V_27 = 0 ;
}
if ( V_63 -> V_27 > V_111 + 1 )
return - V_106 ;
if ( ( V_63 -> V_28 & V_94 ) &&
( ( V_63 -> V_27 != 1 ) ||
( ! ( V_63 -> V_26 & V_127 ) ) ) )
return - V_106 ;
V_21 = F_52 ( & V_19 -> V_128 , V_63 -> V_26 , V_8 ) ;
if ( V_21 ) {
if ( V_63 -> V_27 > V_21 -> V_27 )
return - V_113 ;
if ( V_63 -> V_27 ) {
V_50 = F_66 ( ( V_114 * ) V_21 -> V_39 ,
V_109 -> V_115 ,
V_63 -> V_27 * V_41 ) ;
if ( V_50 < 0 )
return V_50 ;
memset ( V_21 -> V_83 , 0 , V_63 -> V_27 * V_41 ) ;
}
V_21 -> V_27 = V_63 -> V_27 ;
V_126 = 0 ;
} else {
V_21 = F_67 ( V_117 , V_118 ) ;
if ( ! V_21 )
return - V_119 ;
V_21 -> V_26 = V_63 -> V_26 ;
V_21 -> V_27 = V_63 -> V_27 ;
if ( V_63 -> V_27 > 1 ) {
V_21 -> V_39 = F_68 ( V_63 -> V_27 * V_41 ,
V_118 ) ;
if ( ! V_21 -> V_39 ) {
F_55 ( V_21 ) ;
return - V_119 ;
}
V_21 -> V_83 = F_67 ( V_63 -> V_27 * V_41 ,
V_118 ) ;
if ( ! V_21 -> V_83 ) {
F_55 ( V_21 -> V_39 ) ;
F_55 ( V_21 ) ;
return - V_119 ;
}
} else {
V_21 -> V_39 = & V_21 -> V_100 ;
V_21 -> V_83 = & V_21 -> V_101 ;
}
if ( V_63 -> V_27 ) {
V_50 = F_66 ( ( V_114 * ) V_21 -> V_39 , V_109 -> V_115 ,
V_63 -> V_27 * V_41 ) ;
if ( V_50 < 0 ) {
if ( V_21 -> V_39 != & V_21 -> V_100 )
F_55 ( V_21 -> V_39 ) ;
if ( V_21 -> V_83 != & V_21 -> V_101 )
F_55 ( V_21 -> V_83 ) ;
F_55 ( V_21 ) ;
return V_50 ;
}
}
V_21 -> V_6 = V_6 ;
V_21 -> V_8 = V_8 ;
F_69 ( & V_21 -> V_61 , V_120 , V_85 ) ;
V_21 -> V_61 . V_121 = F_42 ;
F_70 ( & V_21 -> V_71 , F_41 ,
( unsigned long ) V_21 ) ;
F_69 ( & V_21 -> V_79 , V_120 , V_85 ) ;
V_21 -> V_79 . V_121 = F_47 ;
F_70 ( & V_21 -> V_91 , F_46 ,
( unsigned long ) V_21 ) ;
F_71 ( & V_21 -> V_105 , & V_19 -> V_128 ) ;
V_126 = 1 ;
}
V_21 -> V_28 = V_63 -> V_28 ;
if ( V_21 -> V_28 & V_94 ) {
F_51 ( & V_21 -> V_79 ) ;
F_51 ( & V_21 -> V_61 ) ;
if ( ( V_21 -> V_28 & V_116 ) ||
( V_21 -> V_39 [ 0 ] . V_26 == V_21 -> V_26 ) )
V_21 -> V_39 [ 0 ] . V_26 = V_21 -> V_26 & ~ V_127 ;
} else {
if ( V_21 -> V_28 & V_123 ) {
V_21 -> V_67 = V_63 -> V_67 ;
V_21 -> V_68 = V_63 -> V_68 ;
V_21 -> V_30 = F_72 ( V_63 -> V_67 ) ;
V_21 -> V_32 = F_72 ( V_63 -> V_68 ) ;
if ( ! V_21 -> V_30 . V_31 )
F_51 ( & V_21 -> V_61 ) ;
V_21 -> V_80 = F_49 ( 0 , 0 ) ;
F_51 ( & V_21 -> V_79 ) ;
F_45 ( V_21 , 1 ) ;
}
if ( ( V_21 -> V_28 & V_124 ) && V_21 -> V_30 . V_31 )
F_28 ( & V_21 -> V_61 , V_21 -> V_30 ,
V_85 ) ;
}
if ( V_126 ) {
if ( V_8 ) {
struct V_9 * V_10 ;
V_10 = F_16 ( & V_11 , V_8 ) ;
if ( V_10 ) {
V_50 = F_74 ( V_10 , V_21 -> V_26 ,
F_58 ( V_21 -> V_26 ) ,
F_50 , V_21 ,
L_23 ) ;
V_21 -> V_102 = V_10 ;
F_21 ( V_10 ) ;
}
} else
V_50 = F_74 ( NULL , V_21 -> V_26 ,
F_58 ( V_21 -> V_26 ) ,
F_50 , V_21 , L_23 ) ;
if ( V_50 ) {
F_62 ( & V_21 -> V_105 ) ;
F_53 ( V_21 ) ;
return V_50 ;
}
}
return V_63 -> V_27 * V_41 + V_107 ;
}
static int F_75 ( struct V_108 * V_109 , int V_8 , struct V_5 * V_6 )
{
struct V_36 * V_37 ;
struct V_9 * V_10 ;
int V_50 ;
if ( ! V_8 )
return - V_110 ;
V_37 = F_17 ( V_41 , V_118 ) ;
if ( ! V_37 )
return - V_119 ;
V_50 = F_66 ( F_19 ( V_37 , V_41 ) , V_109 -> V_115 , V_41 ) ;
if ( V_50 < 0 ) {
F_26 ( V_37 ) ;
return V_50 ;
}
V_10 = F_16 ( & V_11 , V_8 ) ;
if ( ! V_10 ) {
F_26 ( V_37 ) ;
return - V_110 ;
}
V_37 -> V_10 = V_10 ;
V_37 -> V_6 = V_6 ;
V_50 = F_20 ( V_37 , 1 ) ;
F_21 ( V_10 ) ;
if ( V_50 )
return V_50 ;
return V_41 + V_107 ;
}
static int F_76 ( struct V_129 * V_130 , struct V_131 * V_5 ,
struct V_108 * V_109 , T_3 V_132 )
{
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_4 * V_19 = F_2 ( V_6 ) ;
int V_8 = V_19 -> V_8 ;
struct V_43 V_63 ;
int V_133 ;
if ( ! V_19 -> V_134 )
return - V_135 ;
if ( V_132 < V_107 || ( V_132 - V_107 ) % V_41 )
return - V_106 ;
if ( ! V_8 && V_109 -> V_136 ) {
struct V_47 * V_48 =
(struct V_47 * ) V_109 -> V_136 ;
if ( V_109 -> V_137 < sizeof( * V_48 ) )
return - V_106 ;
if ( V_48 -> V_56 != V_57 )
return - V_106 ;
V_8 = V_48 -> V_58 ;
if ( V_8 ) {
struct V_9 * V_10 ;
V_10 = F_16 ( & V_11 , V_8 ) ;
if ( ! V_10 )
return - V_110 ;
if ( V_10 -> type != V_138 ) {
F_21 ( V_10 ) ;
return - V_110 ;
}
F_21 ( V_10 ) ;
}
}
V_133 = F_66 ( ( V_114 * ) & V_63 , V_109 -> V_115 , V_107 ) ;
if ( V_133 < 0 )
return V_133 ;
F_77 ( V_6 ) ;
switch ( V_63 . V_65 ) {
case V_139 :
V_133 = F_65 ( & V_63 , V_109 , V_8 , V_6 ) ;
break;
case V_140 :
V_133 = F_73 ( & V_63 , V_109 , V_8 , V_6 ) ;
break;
case V_141 :
if ( F_63 ( & V_19 -> V_112 , V_63 . V_26 , V_8 ) )
V_133 = V_107 ;
else
V_133 = - V_106 ;
break;
case V_142 :
if ( F_60 ( & V_19 -> V_128 , V_63 . V_26 , V_8 ) )
V_133 = V_107 ;
else
V_133 = - V_106 ;
break;
case V_143 :
V_63 . V_65 = V_144 ;
V_133 = F_64 ( & V_19 -> V_112 , & V_63 , V_8 ) ;
break;
case V_145 :
V_63 . V_65 = V_146 ;
V_133 = F_64 ( & V_19 -> V_128 , & V_63 , V_8 ) ;
break;
case V_147 :
if ( ( V_63 . V_27 != 1 ) || ( V_132 != V_41 + V_107 ) )
V_133 = - V_106 ;
else
V_133 = F_75 ( V_109 , V_8 , V_6 ) ;
break;
default:
V_133 = - V_106 ;
break;
}
F_78 ( V_6 ) ;
return V_133 ;
}
static int F_79 ( struct V_148 * V_149 , unsigned long V_109 ,
void * V_3 )
{
struct V_9 * V_10 = (struct V_9 * ) V_3 ;
struct V_4 * V_19 = F_33 ( V_149 , struct V_4 , V_150 ) ;
struct V_5 * V_6 = & V_19 -> V_6 ;
struct V_20 * V_21 ;
int V_151 = 0 ;
if ( ! F_80 ( F_81 ( V_10 ) , & V_11 ) )
return V_152 ;
if ( V_10 -> type != V_138 )
return V_152 ;
switch ( V_109 ) {
case V_153 :
F_77 ( V_6 ) ;
F_9 (op, &bo->rx_ops, list)
if ( V_21 -> V_102 == V_10 )
F_56 ( V_10 , V_21 ) ;
if ( V_19 -> V_134 && V_19 -> V_8 == V_10 -> V_8 ) {
V_19 -> V_134 = 0 ;
V_19 -> V_8 = 0 ;
V_151 = 1 ;
}
F_78 ( V_6 ) ;
if ( V_151 ) {
V_6 -> V_154 = V_110 ;
if ( ! F_82 ( V_6 , V_155 ) )
V_6 -> V_156 ( V_6 ) ;
}
break;
case V_157 :
if ( V_19 -> V_134 && V_19 -> V_8 == V_10 -> V_8 ) {
V_6 -> V_154 = V_158 ;
if ( ! F_82 ( V_6 , V_155 ) )
V_6 -> V_156 ( V_6 ) ;
}
}
return V_152 ;
}
static int F_83 ( struct V_5 * V_6 )
{
struct V_4 * V_19 = F_2 ( V_6 ) ;
V_19 -> V_134 = 0 ;
V_19 -> V_8 = 0 ;
V_19 -> V_23 = 0 ;
V_19 -> V_159 = NULL ;
F_84 ( & V_19 -> V_112 ) ;
F_84 ( & V_19 -> V_128 ) ;
V_19 -> V_150 . V_160 = F_79 ;
F_85 ( & V_19 -> V_150 ) ;
return 0 ;
}
static int F_86 ( struct V_131 * V_5 )
{
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_4 * V_19 ;
struct V_20 * V_21 , * V_161 ;
if ( V_6 == NULL )
return 0 ;
V_19 = F_2 ( V_6 ) ;
F_87 ( & V_19 -> V_150 ) ;
F_77 ( V_6 ) ;
F_61 (op, next, &bo->tx_ops, list)
F_53 ( V_21 ) ;
F_61 (op, next, &bo->rx_ops, list) {
if ( V_21 -> V_8 ) {
if ( V_21 -> V_102 ) {
struct V_9 * V_10 ;
V_10 = F_16 ( & V_11 , V_21 -> V_8 ) ;
if ( V_10 ) {
F_56 ( V_10 , V_21 ) ;
F_21 ( V_10 ) ;
}
}
} else
F_57 ( NULL , V_21 -> V_26 ,
F_58 ( V_21 -> V_26 ) ,
F_50 , V_21 ) ;
F_53 ( V_21 ) ;
}
if ( V_162 && V_19 -> V_159 )
F_88 ( V_19 -> V_163 , V_162 ) ;
if ( V_19 -> V_134 ) {
V_19 -> V_134 = 0 ;
V_19 -> V_8 = 0 ;
}
F_89 ( V_6 ) ;
V_5 -> V_6 = NULL ;
F_78 ( V_6 ) ;
F_90 ( V_6 ) ;
return 0 ;
}
static int F_91 ( struct V_131 * V_5 , struct V_164 * V_165 , int V_166 ,
int V_28 )
{
struct V_47 * V_48 = (struct V_47 * ) V_165 ;
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_4 * V_19 = F_2 ( V_6 ) ;
if ( V_166 < sizeof( * V_48 ) )
return - V_106 ;
if ( V_19 -> V_134 )
return - V_167 ;
if ( V_48 -> V_58 ) {
struct V_9 * V_10 ;
V_10 = F_16 ( & V_11 , V_48 -> V_58 ) ;
if ( ! V_10 )
return - V_110 ;
if ( V_10 -> type != V_138 ) {
F_21 ( V_10 ) ;
return - V_110 ;
}
V_19 -> V_8 = V_10 -> V_8 ;
F_21 ( V_10 ) ;
} else {
V_19 -> V_8 = 0 ;
}
V_19 -> V_134 = 1 ;
if ( V_162 ) {
sprintf ( V_19 -> V_163 , L_24 , F_92 ( V_6 ) ) ;
V_19 -> V_159 = F_93 ( V_19 -> V_163 , 0644 ,
V_162 ,
& V_168 , V_6 ) ;
}
return 0 ;
}
static int F_94 ( struct V_129 * V_130 , struct V_131 * V_5 ,
struct V_108 * V_109 , T_3 V_132 , int V_28 )
{
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_36 * V_37 ;
int error = 0 ;
int V_169 ;
int V_50 ;
V_169 = V_28 & V_170 ;
V_28 &= ~ V_170 ;
V_37 = F_95 ( V_6 , V_28 , V_169 , & error ) ;
if ( ! V_37 )
return error ;
if ( V_37 -> V_166 < V_132 )
V_132 = V_37 -> V_166 ;
V_50 = F_96 ( V_109 -> V_115 , V_37 -> V_3 , V_132 ) ;
if ( V_50 < 0 ) {
F_97 ( V_6 , V_37 ) ;
return V_50 ;
}
F_98 ( V_109 , V_6 , V_37 ) ;
if ( V_109 -> V_136 ) {
V_109 -> V_137 = sizeof( struct V_47 ) ;
memcpy ( V_109 -> V_136 , V_37 -> V_55 , V_109 -> V_137 ) ;
}
F_97 ( V_6 , V_37 ) ;
return V_132 ;
}
static int T_4 F_99 ( void )
{
int V_50 ;
F_59 ( V_171 ) ;
V_50 = F_100 ( & V_172 ) ;
if ( V_50 < 0 ) {
F_59 ( V_103 L_25 ) ;
return V_50 ;
}
V_162 = F_101 ( L_26 , V_11 . V_173 ) ;
return 0 ;
}
static void T_5 F_102 ( void )
{
F_103 ( & V_172 ) ;
if ( V_162 )
F_104 ( & V_11 , L_26 ) ;
}
