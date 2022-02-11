static inline T_1 F_1 ( const struct V_1 * V_2 )
{
return * ( T_1 * ) V_2 -> V_3 ;
}
static inline struct V_4 * F_2 ( const struct V_5 * V_6 )
{
return (struct V_4 * ) V_6 ;
}
static inline T_2 F_3 ( struct V_7 V_8 )
{
return F_4 ( V_8 . V_9 , V_8 . V_10 * V_11 ) ;
}
static char * F_5 ( char * V_12 , int V_13 )
{
struct V_14 * V_15 ;
if ( ! V_13 )
return L_1 ;
F_6 () ;
V_15 = F_7 ( & V_16 , V_13 ) ;
if ( V_15 )
strcpy ( V_12 , V_15 -> V_17 ) ;
else
strcpy ( V_12 , L_2 ) ;
F_8 () ;
return V_12 ;
}
static int F_9 ( struct V_18 * V_19 , void * V_20 )
{
char V_21 [ V_22 ] ;
struct V_5 * V_6 = (struct V_5 * ) V_19 -> V_23 ;
struct V_4 * V_24 = F_2 ( V_6 ) ;
struct V_25 * V_26 ;
F_10 ( V_19 , L_3 , V_6 -> V_27 ) ;
F_10 ( V_19 , L_4 , V_6 ) ;
F_10 ( V_19 , L_5 , V_24 ) ;
F_10 ( V_19 , L_6 , V_24 -> V_28 ) ;
F_10 ( V_19 , L_7 , F_5 ( V_21 , V_24 -> V_13 ) ) ;
F_10 ( V_19 , L_8 ) ;
F_11 (op, &bo->rx_ops, list) {
unsigned long V_29 ;
if ( ! V_26 -> V_30 )
continue;
F_10 ( V_19 , L_9 ,
V_26 -> V_31 , F_5 ( V_21 , V_26 -> V_13 ) ) ;
F_10 ( V_19 , L_10 , V_26 -> V_32 ,
( V_26 -> V_33 & V_34 ) ? 'd' : ' ' ) ;
if ( V_26 -> V_35 . V_36 )
F_10 ( V_19 , L_11 ,
( long long )
F_12 ( V_26 -> V_35 ) ) ;
if ( V_26 -> V_37 . V_36 )
F_10 ( V_19 , L_12 ,
( long long )
F_12 ( V_26 -> V_37 ) ) ;
F_10 ( V_19 , L_13 ,
V_26 -> V_38 , V_26 -> V_30 ) ;
V_29 = 100 - ( V_26 -> V_38 * 100 ) / V_26 -> V_30 ;
F_10 ( V_19 , L_14 ,
( V_29 == 100 ) ? L_15 : L_16 , V_29 ) ;
}
F_11 (op, &bo->tx_ops, list) {
F_10 ( V_19 , L_17 ,
V_26 -> V_31 ,
F_5 ( V_21 , V_26 -> V_13 ) ,
V_26 -> V_32 ) ;
if ( V_26 -> V_35 . V_36 )
F_10 ( V_19 , L_18 ,
( long long ) F_12 ( V_26 -> V_35 ) ) ;
if ( V_26 -> V_37 . V_36 )
F_10 ( V_19 , L_19 ,
( long long ) F_12 ( V_26 -> V_37 ) ) ;
F_10 ( V_19 , L_20 , V_26 -> V_30 ) ;
}
F_13 ( V_19 , '\n' ) ;
return 0 ;
}
static int F_14 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
return F_15 ( V_40 , F_9 , F_16 ( V_39 ) ) ;
}
static void F_17 ( struct V_25 * V_26 )
{
struct V_41 * V_42 ;
struct V_14 * V_15 ;
struct V_1 * V_43 = & V_26 -> V_44 [ V_26 -> V_45 ] ;
if ( ! V_26 -> V_13 )
return;
V_15 = F_18 ( & V_16 , V_26 -> V_13 ) ;
if ( ! V_15 ) {
return;
}
V_42 = F_19 ( V_46 + sizeof( struct V_47 ) , F_20 () ) ;
if ( ! V_42 )
goto V_48;
F_21 ( V_42 ) ;
F_22 ( V_42 ) -> V_13 = V_15 -> V_13 ;
F_22 ( V_42 ) -> V_49 = 0 ;
memcpy ( F_23 ( V_42 , V_46 ) , V_43 , V_46 ) ;
V_42 -> V_15 = V_15 ;
F_24 ( V_42 , V_26 -> V_6 ) ;
F_25 ( V_42 , 1 ) ;
V_26 -> V_45 ++ ;
V_26 -> V_30 ++ ;
if ( V_26 -> V_45 >= V_26 -> V_32 )
V_26 -> V_45 = 0 ;
V_48:
F_26 ( V_15 ) ;
}
static void F_27 ( struct V_25 * V_26 , struct V_50 * V_51 ,
struct V_1 * V_44 , int V_52 )
{
struct V_41 * V_42 ;
struct V_1 * V_53 ;
struct V_54 * V_55 ;
struct V_5 * V_6 = V_26 -> V_6 ;
unsigned int V_56 = V_51 -> V_32 * V_46 ;
int V_57 ;
V_42 = F_19 ( sizeof( * V_51 ) + V_56 , F_20 () ) ;
if ( ! V_42 )
return;
memcpy ( F_23 ( V_42 , sizeof( * V_51 ) ) , V_51 , sizeof( * V_51 ) ) ;
if ( V_51 -> V_32 ) {
V_53 = (struct V_1 * ) F_28 ( V_42 ) ;
memcpy ( F_23 ( V_42 , V_56 ) , V_44 , V_56 ) ;
if ( V_51 -> V_32 == 1 )
V_53 -> V_58 &= V_59 ;
}
if ( V_52 ) {
V_42 -> V_60 = V_26 -> V_61 ;
}
F_29 ( sizeof( struct V_54 ) ) ;
V_55 = (struct V_54 * ) V_42 -> V_62 ;
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
V_55 -> V_63 = V_64 ;
V_55 -> V_65 = V_26 -> V_66 ;
V_57 = F_30 ( V_6 , V_42 ) ;
if ( V_57 < 0 ) {
struct V_4 * V_24 = F_2 ( V_6 ) ;
F_31 ( V_42 ) ;
V_24 -> V_28 ++ ;
}
}
static void F_32 ( struct V_25 * V_26 )
{
if ( V_26 -> V_35 . V_36 && V_26 -> V_67 )
F_33 ( & V_26 -> V_68 ,
F_34 ( F_35 () , V_26 -> V_35 ) ,
V_69 ) ;
else if ( V_26 -> V_37 . V_36 )
F_33 ( & V_26 -> V_68 ,
F_34 ( F_35 () , V_26 -> V_37 ) ,
V_69 ) ;
}
static void F_36 ( unsigned long V_3 )
{
struct V_25 * V_26 = (struct V_25 * ) V_3 ;
struct V_50 V_70 ;
if ( V_26 -> V_35 . V_36 && ( V_26 -> V_67 > 0 ) ) {
V_26 -> V_67 -- ;
if ( ! V_26 -> V_67 && ( V_26 -> V_33 & V_71 ) ) {
V_70 . V_72 = V_73 ;
V_70 . V_33 = V_26 -> V_33 ;
V_70 . V_67 = V_26 -> V_67 ;
V_70 . V_74 = V_26 -> V_74 ;
V_70 . V_75 = V_26 -> V_75 ;
V_70 . V_31 = V_26 -> V_31 ;
V_70 . V_32 = 0 ;
F_27 ( V_26 , & V_70 , NULL , 0 ) ;
}
F_17 ( V_26 ) ;
} else if ( V_26 -> V_37 . V_36 )
F_17 ( V_26 ) ;
F_32 ( V_26 ) ;
}
static enum V_76 F_37 ( struct V_77 * V_77 )
{
struct V_25 * V_26 = F_38 ( V_77 , struct V_25 , V_68 ) ;
F_39 ( & V_26 -> V_78 ) ;
return V_79 ;
}
static void F_40 ( struct V_25 * V_26 , struct V_1 * V_3 )
{
struct V_50 V_51 ;
V_26 -> V_38 ++ ;
if ( V_26 -> V_38 > V_80 / 100 )
V_26 -> V_38 = V_26 -> V_30 = 0 ;
V_3 -> V_58 &= ( V_59 | V_81 ) ;
V_51 . V_72 = V_82 ;
V_51 . V_33 = V_26 -> V_33 ;
V_51 . V_67 = V_26 -> V_67 ;
V_51 . V_74 = V_26 -> V_74 ;
V_51 . V_75 = V_26 -> V_75 ;
V_51 . V_31 = V_26 -> V_31 ;
V_51 . V_32 = 1 ;
F_27 ( V_26 , & V_51 , V_3 , 1 ) ;
}
static void F_41 ( struct V_25 * V_26 ,
struct V_1 * V_83 ,
const struct V_1 * V_84 )
{
memcpy ( V_83 , V_84 , V_46 ) ;
V_83 -> V_58 |= ( V_81 | V_85 ) ;
if ( ! V_26 -> V_37 . V_36 ) {
F_40 ( V_26 , V_83 ) ;
return;
}
if ( F_42 ( & V_26 -> V_86 ) )
return;
if ( ! V_26 -> V_87 . V_36 )
goto V_88;
if ( F_43 ( F_35 () , V_26 -> V_87 ) <
F_12 ( V_26 -> V_37 ) ) {
F_33 ( & V_26 -> V_86 ,
F_34 ( V_26 -> V_87 , V_26 -> V_37 ) ,
V_69 ) ;
return;
}
V_88:
F_40 ( V_26 , V_83 ) ;
V_26 -> V_87 = F_35 () ;
}
static void F_44 ( struct V_25 * V_26 , unsigned int V_89 ,
const struct V_1 * V_84 )
{
if ( ! ( V_26 -> V_90 [ V_89 ] . V_58 & V_81 ) ) {
F_41 ( V_26 , & V_26 -> V_90 [ V_89 ] , V_84 ) ;
return;
}
if ( ( F_1 ( & V_26 -> V_44 [ V_89 ] ) & F_1 ( V_84 ) ) !=
( F_1 ( & V_26 -> V_44 [ V_89 ] ) & F_1 ( & V_26 -> V_90 [ V_89 ] ) ) ) {
F_41 ( V_26 , & V_26 -> V_90 [ V_89 ] , V_84 ) ;
return;
}
if ( V_26 -> V_33 & V_34 ) {
if ( V_84 -> V_58 != ( V_26 -> V_90 [ V_89 ] . V_58 &
V_59 ) ) {
F_41 ( V_26 , & V_26 -> V_90 [ V_89 ] ,
V_84 ) ;
return;
}
}
}
static void F_45 ( struct V_25 * V_26 )
{
if ( V_26 -> V_33 & V_91 )
return;
if ( V_26 -> V_35 . V_36 )
F_33 ( & V_26 -> V_68 , V_26 -> V_35 , V_92 ) ;
}
static void F_46 ( unsigned long V_3 )
{
struct V_25 * V_26 = (struct V_25 * ) V_3 ;
struct V_50 V_70 ;
V_70 . V_72 = V_93 ;
V_70 . V_33 = V_26 -> V_33 ;
V_70 . V_67 = V_26 -> V_67 ;
V_70 . V_74 = V_26 -> V_74 ;
V_70 . V_75 = V_26 -> V_75 ;
V_70 . V_31 = V_26 -> V_31 ;
V_70 . V_32 = 0 ;
F_27 ( V_26 , & V_70 , NULL , 0 ) ;
}
static enum V_76 F_47 ( struct V_77 * V_77 )
{
struct V_25 * V_26 = F_38 ( V_77 , struct V_25 , V_68 ) ;
F_48 ( & V_26 -> V_78 ) ;
if ( ( V_26 -> V_33 & V_94 ) && V_26 -> V_90 ) {
memset ( V_26 -> V_90 , 0 , V_26 -> V_32 * V_46 ) ;
}
return V_79 ;
}
static inline int F_49 ( struct V_25 * V_26 , int V_95 ,
unsigned int V_89 )
{
if ( ( V_26 -> V_90 ) && ( V_26 -> V_90 [ V_89 ] . V_58 & V_85 ) ) {
if ( V_95 )
F_40 ( V_26 , & V_26 -> V_90 [ V_89 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_50 ( struct V_25 * V_26 , int V_95 )
{
int V_96 = 0 ;
if ( V_26 -> V_32 > 1 ) {
unsigned int V_97 ;
for ( V_97 = 1 ; V_97 < V_26 -> V_32 ; V_97 ++ )
V_96 += F_49 ( V_26 , V_95 , V_97 ) ;
} else {
V_96 += F_49 ( V_26 , V_95 , 0 ) ;
}
return V_96 ;
}
static void F_51 ( unsigned long V_3 )
{
struct V_25 * V_26 = (struct V_25 * ) V_3 ;
F_50 ( V_26 , 1 ) ;
}
static enum V_76 F_52 ( struct V_77 * V_77 )
{
struct V_25 * V_26 = F_38 ( V_77 , struct V_25 , V_86 ) ;
F_39 ( & V_26 -> V_98 ) ;
if ( F_50 ( V_26 , 0 ) ) {
F_53 ( V_77 , F_35 () , V_26 -> V_37 ) ;
return V_99 ;
} else {
V_26 -> V_87 = F_4 ( 0 , 0 ) ;
return V_79 ;
}
}
static void F_54 ( struct V_41 * V_42 , void * V_3 )
{
struct V_25 * V_26 = (struct V_25 * ) V_3 ;
const struct V_1 * V_100 = (struct V_1 * ) V_42 -> V_3 ;
unsigned int V_97 ;
F_55 ( & V_26 -> V_68 ) ;
if ( V_26 -> V_31 != V_100 -> V_31 )
return;
V_26 -> V_61 = V_42 -> V_60 ;
V_26 -> V_66 = V_42 -> V_15 -> V_13 ;
V_26 -> V_30 ++ ;
if ( V_26 -> V_33 & V_101 ) {
F_17 ( V_26 ) ;
return;
}
if ( V_26 -> V_33 & V_102 ) {
F_41 ( V_26 , & V_26 -> V_90 [ 0 ] , V_100 ) ;
goto V_103;
}
if ( V_26 -> V_32 == 1 ) {
F_44 ( V_26 , 0 , V_100 ) ;
goto V_103;
}
if ( V_26 -> V_32 > 1 ) {
for ( V_97 = 1 ; V_97 < V_26 -> V_32 ; V_97 ++ ) {
if ( ( F_1 ( & V_26 -> V_44 [ 0 ] ) & F_1 ( V_100 ) ) ==
( F_1 ( & V_26 -> V_44 [ 0 ] ) &
F_1 ( & V_26 -> V_44 [ V_97 ] ) ) ) {
F_44 ( V_26 , V_97 , V_100 ) ;
break;
}
}
}
V_103:
F_45 ( V_26 ) ;
}
static struct V_25 * F_56 ( struct V_104 * V_105 , T_3 V_31 ,
int V_13 )
{
struct V_25 * V_26 ;
F_11 (op, ops, list) {
if ( ( V_26 -> V_31 == V_31 ) && ( V_26 -> V_13 == V_13 ) )
return V_26 ;
}
return NULL ;
}
static void F_57 ( struct V_25 * V_26 )
{
F_55 ( & V_26 -> V_68 ) ;
F_55 ( & V_26 -> V_86 ) ;
if ( V_26 -> V_78 . V_106 )
F_58 ( & V_26 -> V_78 ) ;
if ( V_26 -> V_98 . V_106 )
F_58 ( & V_26 -> V_98 ) ;
if ( ( V_26 -> V_44 ) && ( V_26 -> V_44 != & V_26 -> V_107 ) )
F_59 ( V_26 -> V_44 ) ;
if ( ( V_26 -> V_90 ) && ( V_26 -> V_90 != & V_26 -> V_108 ) )
F_59 ( V_26 -> V_90 ) ;
F_59 ( V_26 ) ;
}
static void F_60 ( struct V_14 * V_15 , struct V_25 * V_26 )
{
if ( V_26 -> V_109 == V_15 ) {
F_61 ( V_15 , V_26 -> V_31 , F_62 ( V_26 -> V_31 ) ,
F_54 , V_26 ) ;
V_26 -> V_109 = NULL ;
} else
F_63 ( V_110 L_21
L_22 , V_26 -> V_109 , V_15 ) ;
}
static int F_64 ( struct V_104 * V_105 , T_3 V_31 , int V_13 )
{
struct V_25 * V_26 , * V_111 ;
F_65 (op, n, ops, list) {
if ( ( V_26 -> V_31 == V_31 ) && ( V_26 -> V_13 == V_13 ) ) {
if ( V_26 -> V_13 ) {
if ( V_26 -> V_109 ) {
struct V_14 * V_15 ;
V_15 = F_18 ( & V_16 ,
V_26 -> V_13 ) ;
if ( V_15 ) {
F_60 ( V_15 , V_26 ) ;
F_26 ( V_15 ) ;
}
}
} else
F_61 ( NULL , V_26 -> V_31 ,
F_62 ( V_26 -> V_31 ) ,
F_54 , V_26 ) ;
F_66 ( & V_26 -> V_112 ) ;
F_57 ( V_26 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_67 ( struct V_104 * V_105 , T_3 V_31 , int V_13 )
{
struct V_25 * V_26 , * V_111 ;
F_65 (op, n, ops, list) {
if ( ( V_26 -> V_31 == V_31 ) && ( V_26 -> V_13 == V_13 ) ) {
F_66 ( & V_26 -> V_112 ) ;
F_57 ( V_26 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_68 ( struct V_104 * V_105 , struct V_50 * V_70 ,
int V_13 )
{
struct V_25 * V_26 = F_56 ( V_105 , V_70 -> V_31 , V_13 ) ;
if ( ! V_26 )
return - V_113 ;
V_70 -> V_33 = V_26 -> V_33 ;
V_70 -> V_67 = V_26 -> V_67 ;
V_70 -> V_74 = V_26 -> V_74 ;
V_70 -> V_75 = V_26 -> V_75 ;
V_70 -> V_32 = V_26 -> V_32 ;
F_27 ( V_26 , V_70 , V_26 -> V_44 , 0 ) ;
return V_114 ;
}
static int F_69 ( struct V_50 * V_70 , struct V_115 * V_116 ,
int V_13 , struct V_5 * V_6 )
{
struct V_4 * V_24 = F_2 ( V_6 ) ;
struct V_25 * V_26 ;
unsigned int V_97 ;
int V_57 ;
if ( ! V_13 )
return - V_117 ;
if ( V_70 -> V_32 < 1 || V_70 -> V_32 > V_118 )
return - V_113 ;
V_26 = F_56 ( & V_24 -> V_119 , V_70 -> V_31 , V_13 ) ;
if ( V_26 ) {
if ( V_70 -> V_32 > V_26 -> V_32 )
return - V_120 ;
for ( V_97 = 0 ; V_97 < V_70 -> V_32 ; V_97 ++ ) {
V_57 = F_70 ( ( V_121 * ) & V_26 -> V_44 [ V_97 ] , V_116 , V_46 ) ;
if ( V_26 -> V_44 [ V_97 ] . V_58 > 8 )
V_57 = - V_113 ;
if ( V_57 < 0 )
return V_57 ;
if ( V_70 -> V_33 & V_122 ) {
V_26 -> V_44 [ V_97 ] . V_31 = V_70 -> V_31 ;
}
}
} else {
V_26 = F_71 ( V_123 , V_124 ) ;
if ( ! V_26 )
return - V_125 ;
V_26 -> V_31 = V_70 -> V_31 ;
if ( V_70 -> V_32 > 1 ) {
V_26 -> V_44 = F_72 ( V_70 -> V_32 * V_46 ,
V_124 ) ;
if ( ! V_26 -> V_44 ) {
F_59 ( V_26 ) ;
return - V_125 ;
}
} else
V_26 -> V_44 = & V_26 -> V_107 ;
for ( V_97 = 0 ; V_97 < V_70 -> V_32 ; V_97 ++ ) {
V_57 = F_70 ( ( V_121 * ) & V_26 -> V_44 [ V_97 ] , V_116 , V_46 ) ;
if ( V_26 -> V_44 [ V_97 ] . V_58 > 8 )
V_57 = - V_113 ;
if ( V_57 < 0 ) {
if ( V_26 -> V_44 != & V_26 -> V_107 )
F_59 ( V_26 -> V_44 ) ;
F_59 ( V_26 ) ;
return V_57 ;
}
if ( V_70 -> V_33 & V_122 ) {
V_26 -> V_44 [ V_97 ] . V_31 = V_70 -> V_31 ;
}
}
V_26 -> V_90 = NULL ;
V_26 -> V_6 = V_6 ;
V_26 -> V_13 = V_13 ;
F_73 ( & V_26 -> V_68 , V_126 , V_92 ) ;
V_26 -> V_68 . V_127 = F_37 ;
F_74 ( & V_26 -> V_78 , F_36 ,
( unsigned long ) V_26 ) ;
F_73 ( & V_26 -> V_86 , V_126 , V_92 ) ;
F_75 ( & V_26 -> V_112 , & V_24 -> V_119 ) ;
}
if ( V_26 -> V_32 != V_70 -> V_32 ) {
V_26 -> V_32 = V_70 -> V_32 ;
V_26 -> V_45 = 0 ;
}
V_26 -> V_33 = V_70 -> V_33 ;
if ( V_26 -> V_33 & V_128 ) {
V_26 -> V_45 = 0 ;
}
if ( V_26 -> V_33 & V_129 ) {
V_26 -> V_67 = V_70 -> V_67 ;
V_26 -> V_74 = V_70 -> V_74 ;
V_26 -> V_75 = V_70 -> V_75 ;
V_26 -> V_35 = F_3 ( V_70 -> V_74 ) ;
V_26 -> V_37 = F_3 ( V_70 -> V_75 ) ;
if ( ! V_26 -> V_35 . V_36 && ! V_26 -> V_37 . V_36 )
F_55 ( & V_26 -> V_68 ) ;
}
if ( V_26 -> V_33 & V_130 ) {
F_55 ( & V_26 -> V_68 ) ;
V_26 -> V_33 |= V_131 ;
}
if ( V_26 -> V_33 & V_131 ) {
F_17 ( V_26 ) ;
if ( V_26 -> V_67 )
V_26 -> V_67 -- ;
}
if ( V_26 -> V_33 & V_130 )
F_32 ( V_26 ) ;
return V_70 -> V_32 * V_46 + V_114 ;
}
static int F_76 ( struct V_50 * V_70 , struct V_115 * V_116 ,
int V_13 , struct V_5 * V_6 )
{
struct V_4 * V_24 = F_2 ( V_6 ) ;
struct V_25 * V_26 ;
int V_132 ;
int V_57 = 0 ;
if ( ( V_70 -> V_33 & V_102 ) || ( ! ( V_70 -> V_32 ) ) ) {
V_70 -> V_33 |= V_102 ;
V_70 -> V_32 = 0 ;
}
if ( V_70 -> V_32 > V_118 + 1 )
return - V_113 ;
if ( ( V_70 -> V_33 & V_101 ) &&
( ( V_70 -> V_32 != 1 ) ||
( ! ( V_70 -> V_31 & V_133 ) ) ) )
return - V_113 ;
V_26 = F_56 ( & V_24 -> V_134 , V_70 -> V_31 , V_13 ) ;
if ( V_26 ) {
if ( V_70 -> V_32 > V_26 -> V_32 )
return - V_120 ;
if ( V_70 -> V_32 ) {
V_57 = F_70 ( ( V_121 * ) V_26 -> V_44 , V_116 ,
V_70 -> V_32 * V_46 ) ;
if ( V_57 < 0 )
return V_57 ;
memset ( V_26 -> V_90 , 0 , V_70 -> V_32 * V_46 ) ;
}
V_26 -> V_32 = V_70 -> V_32 ;
V_132 = 0 ;
} else {
V_26 = F_71 ( V_123 , V_124 ) ;
if ( ! V_26 )
return - V_125 ;
V_26 -> V_31 = V_70 -> V_31 ;
V_26 -> V_32 = V_70 -> V_32 ;
if ( V_70 -> V_32 > 1 ) {
V_26 -> V_44 = F_72 ( V_70 -> V_32 * V_46 ,
V_124 ) ;
if ( ! V_26 -> V_44 ) {
F_59 ( V_26 ) ;
return - V_125 ;
}
V_26 -> V_90 = F_71 ( V_70 -> V_32 * V_46 ,
V_124 ) ;
if ( ! V_26 -> V_90 ) {
F_59 ( V_26 -> V_44 ) ;
F_59 ( V_26 ) ;
return - V_125 ;
}
} else {
V_26 -> V_44 = & V_26 -> V_107 ;
V_26 -> V_90 = & V_26 -> V_108 ;
}
if ( V_70 -> V_32 ) {
V_57 = F_70 ( ( V_121 * ) V_26 -> V_44 , V_116 ,
V_70 -> V_32 * V_46 ) ;
if ( V_57 < 0 ) {
if ( V_26 -> V_44 != & V_26 -> V_107 )
F_59 ( V_26 -> V_44 ) ;
if ( V_26 -> V_90 != & V_26 -> V_108 )
F_59 ( V_26 -> V_90 ) ;
F_59 ( V_26 ) ;
return V_57 ;
}
}
V_26 -> V_6 = V_6 ;
V_26 -> V_13 = V_13 ;
V_26 -> V_66 = V_13 ;
F_73 ( & V_26 -> V_68 , V_126 , V_92 ) ;
V_26 -> V_68 . V_127 = F_47 ;
F_74 ( & V_26 -> V_78 , F_46 ,
( unsigned long ) V_26 ) ;
F_73 ( & V_26 -> V_86 , V_126 , V_92 ) ;
V_26 -> V_86 . V_127 = F_52 ;
F_74 ( & V_26 -> V_98 , F_51 ,
( unsigned long ) V_26 ) ;
F_75 ( & V_26 -> V_112 , & V_24 -> V_134 ) ;
V_132 = 1 ;
}
V_26 -> V_33 = V_70 -> V_33 ;
if ( V_26 -> V_33 & V_101 ) {
F_55 ( & V_26 -> V_86 ) ;
F_55 ( & V_26 -> V_68 ) ;
if ( ( V_26 -> V_33 & V_122 ) ||
( V_26 -> V_44 [ 0 ] . V_31 == V_26 -> V_31 ) )
V_26 -> V_44 [ 0 ] . V_31 = V_26 -> V_31 & ~ V_133 ;
} else {
if ( V_26 -> V_33 & V_129 ) {
V_26 -> V_74 = V_70 -> V_74 ;
V_26 -> V_75 = V_70 -> V_75 ;
V_26 -> V_35 = F_3 ( V_70 -> V_74 ) ;
V_26 -> V_37 = F_3 ( V_70 -> V_75 ) ;
if ( ! V_26 -> V_35 . V_36 )
F_55 ( & V_26 -> V_68 ) ;
V_26 -> V_87 = F_4 ( 0 , 0 ) ;
F_55 ( & V_26 -> V_86 ) ;
F_50 ( V_26 , 1 ) ;
}
if ( ( V_26 -> V_33 & V_130 ) && V_26 -> V_35 . V_36 )
F_33 ( & V_26 -> V_68 , V_26 -> V_35 ,
V_92 ) ;
}
if ( V_132 ) {
if ( V_13 ) {
struct V_14 * V_15 ;
V_15 = F_18 ( & V_16 , V_13 ) ;
if ( V_15 ) {
V_57 = F_77 ( V_15 , V_26 -> V_31 ,
F_62 ( V_26 -> V_31 ) ,
F_54 , V_26 ,
L_23 ) ;
V_26 -> V_109 = V_15 ;
F_26 ( V_15 ) ;
}
} else
V_57 = F_77 ( NULL , V_26 -> V_31 ,
F_62 ( V_26 -> V_31 ) ,
F_54 , V_26 , L_23 ) ;
if ( V_57 ) {
F_66 ( & V_26 -> V_112 ) ;
F_57 ( V_26 ) ;
return V_57 ;
}
}
return V_70 -> V_32 * V_46 + V_114 ;
}
static int F_78 ( struct V_115 * V_116 , int V_13 , struct V_5 * V_6 )
{
struct V_41 * V_42 ;
struct V_14 * V_15 ;
int V_57 ;
if ( ! V_13 )
return - V_117 ;
V_42 = F_19 ( V_46 + sizeof( struct V_47 ) , V_124 ) ;
if ( ! V_42 )
return - V_125 ;
F_21 ( V_42 ) ;
V_57 = F_70 ( F_23 ( V_42 , V_46 ) , V_116 , V_46 ) ;
if ( V_57 < 0 ) {
F_31 ( V_42 ) ;
return V_57 ;
}
V_15 = F_18 ( & V_16 , V_13 ) ;
if ( ! V_15 ) {
F_31 ( V_42 ) ;
return - V_117 ;
}
F_22 ( V_42 ) -> V_13 = V_15 -> V_13 ;
F_22 ( V_42 ) -> V_49 = 0 ;
V_42 -> V_15 = V_15 ;
F_24 ( V_42 , V_6 ) ;
V_57 = F_25 ( V_42 , 1 ) ;
F_26 ( V_15 ) ;
if ( V_57 )
return V_57 ;
return V_46 + V_114 ;
}
static int F_79 ( struct V_135 * V_5 , struct V_115 * V_116 , T_4 V_136 )
{
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_4 * V_24 = F_2 ( V_6 ) ;
int V_13 = V_24 -> V_13 ;
struct V_50 V_70 ;
int V_137 ;
if ( ! V_24 -> V_138 )
return - V_139 ;
if ( V_136 < V_114 || ( V_136 - V_114 ) % V_46 )
return - V_113 ;
if ( ! V_13 && V_116 -> V_140 ) {
F_80 ( struct V_54 * , V_55 , V_116 -> V_140 ) ;
if ( V_116 -> V_141 < sizeof( * V_55 ) )
return - V_113 ;
if ( V_55 -> V_63 != V_64 )
return - V_113 ;
V_13 = V_55 -> V_65 ;
if ( V_13 ) {
struct V_14 * V_15 ;
V_15 = F_18 ( & V_16 , V_13 ) ;
if ( ! V_15 )
return - V_117 ;
if ( V_15 -> type != V_142 ) {
F_26 ( V_15 ) ;
return - V_117 ;
}
F_26 ( V_15 ) ;
}
}
V_137 = F_70 ( ( V_121 * ) & V_70 , V_116 , V_114 ) ;
if ( V_137 < 0 )
return V_137 ;
F_81 ( V_6 ) ;
switch ( V_70 . V_72 ) {
case V_143 :
V_137 = F_69 ( & V_70 , V_116 , V_13 , V_6 ) ;
break;
case V_144 :
V_137 = F_76 ( & V_70 , V_116 , V_13 , V_6 ) ;
break;
case V_145 :
if ( F_67 ( & V_24 -> V_119 , V_70 . V_31 , V_13 ) )
V_137 = V_114 ;
else
V_137 = - V_113 ;
break;
case V_146 :
if ( F_64 ( & V_24 -> V_134 , V_70 . V_31 , V_13 ) )
V_137 = V_114 ;
else
V_137 = - V_113 ;
break;
case V_147 :
V_70 . V_72 = V_148 ;
V_137 = F_68 ( & V_24 -> V_119 , & V_70 , V_13 ) ;
break;
case V_149 :
V_70 . V_72 = V_150 ;
V_137 = F_68 ( & V_24 -> V_134 , & V_70 , V_13 ) ;
break;
case V_151 :
if ( ( V_70 . V_32 != 1 ) || ( V_136 != V_46 + V_114 ) )
V_137 = - V_113 ;
else
V_137 = F_78 ( V_116 , V_13 , V_6 ) ;
break;
default:
V_137 = - V_113 ;
break;
}
F_82 ( V_6 ) ;
return V_137 ;
}
static int F_83 ( struct V_152 * V_153 , unsigned long V_116 ,
void * V_154 )
{
struct V_14 * V_15 = F_84 ( V_154 ) ;
struct V_4 * V_24 = F_38 ( V_153 , struct V_4 , V_155 ) ;
struct V_5 * V_6 = & V_24 -> V_6 ;
struct V_25 * V_26 ;
int V_156 = 0 ;
if ( ! F_85 ( F_86 ( V_15 ) , & V_16 ) )
return V_157 ;
if ( V_15 -> type != V_142 )
return V_157 ;
switch ( V_116 ) {
case V_158 :
F_81 ( V_6 ) ;
F_11 (op, &bo->rx_ops, list)
if ( V_26 -> V_109 == V_15 )
F_60 ( V_15 , V_26 ) ;
if ( V_24 -> V_138 && V_24 -> V_13 == V_15 -> V_13 ) {
V_24 -> V_138 = 0 ;
V_24 -> V_13 = 0 ;
V_156 = 1 ;
}
F_82 ( V_6 ) ;
if ( V_156 ) {
V_6 -> V_159 = V_117 ;
if ( ! F_87 ( V_6 , V_160 ) )
V_6 -> V_161 ( V_6 ) ;
}
break;
case V_162 :
if ( V_24 -> V_138 && V_24 -> V_13 == V_15 -> V_13 ) {
V_6 -> V_159 = V_163 ;
if ( ! F_87 ( V_6 , V_160 ) )
V_6 -> V_161 ( V_6 ) ;
}
}
return V_157 ;
}
static int F_88 ( struct V_5 * V_6 )
{
struct V_4 * V_24 = F_2 ( V_6 ) ;
V_24 -> V_138 = 0 ;
V_24 -> V_13 = 0 ;
V_24 -> V_28 = 0 ;
V_24 -> V_164 = NULL ;
F_89 ( & V_24 -> V_119 ) ;
F_89 ( & V_24 -> V_134 ) ;
V_24 -> V_155 . V_165 = F_83 ;
F_90 ( & V_24 -> V_155 ) ;
return 0 ;
}
static int F_91 ( struct V_135 * V_5 )
{
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_4 * V_24 ;
struct V_25 * V_26 , * V_166 ;
if ( V_6 == NULL )
return 0 ;
V_24 = F_2 ( V_6 ) ;
F_92 ( & V_24 -> V_155 ) ;
F_81 ( V_6 ) ;
F_65 (op, next, &bo->tx_ops, list)
F_57 ( V_26 ) ;
F_65 (op, next, &bo->rx_ops, list) {
if ( V_26 -> V_13 ) {
if ( V_26 -> V_109 ) {
struct V_14 * V_15 ;
V_15 = F_18 ( & V_16 , V_26 -> V_13 ) ;
if ( V_15 ) {
F_60 ( V_15 , V_26 ) ;
F_26 ( V_15 ) ;
}
}
} else
F_61 ( NULL , V_26 -> V_31 ,
F_62 ( V_26 -> V_31 ) ,
F_54 , V_26 ) ;
F_57 ( V_26 ) ;
}
if ( V_167 && V_24 -> V_164 )
F_93 ( V_24 -> V_168 , V_167 ) ;
if ( V_24 -> V_138 ) {
V_24 -> V_138 = 0 ;
V_24 -> V_13 = 0 ;
}
F_94 ( V_6 ) ;
V_5 -> V_6 = NULL ;
F_82 ( V_6 ) ;
F_95 ( V_6 ) ;
return 0 ;
}
static int F_96 ( struct V_135 * V_5 , struct V_169 * V_170 , int V_171 ,
int V_33 )
{
struct V_54 * V_55 = (struct V_54 * ) V_170 ;
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_4 * V_24 = F_2 ( V_6 ) ;
if ( V_171 < sizeof( * V_55 ) )
return - V_113 ;
if ( V_24 -> V_138 )
return - V_172 ;
if ( V_55 -> V_65 ) {
struct V_14 * V_15 ;
V_15 = F_18 ( & V_16 , V_55 -> V_65 ) ;
if ( ! V_15 )
return - V_117 ;
if ( V_15 -> type != V_142 ) {
F_26 ( V_15 ) ;
return - V_117 ;
}
V_24 -> V_13 = V_15 -> V_13 ;
F_26 ( V_15 ) ;
} else {
V_24 -> V_13 = 0 ;
}
V_24 -> V_138 = 1 ;
if ( V_167 ) {
sprintf ( V_24 -> V_168 , L_24 , F_97 ( V_6 ) ) ;
V_24 -> V_164 = F_98 ( V_24 -> V_168 , 0644 ,
V_167 ,
& V_173 , V_6 ) ;
}
return 0 ;
}
static int F_99 ( struct V_135 * V_5 , struct V_115 * V_116 , T_4 V_136 ,
int V_33 )
{
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_41 * V_42 ;
int error = 0 ;
int V_174 ;
int V_57 ;
V_174 = V_33 & V_175 ;
V_33 &= ~ V_175 ;
V_42 = F_100 ( V_6 , V_33 , V_174 , & error ) ;
if ( ! V_42 )
return error ;
if ( V_42 -> V_171 < V_136 )
V_136 = V_42 -> V_171 ;
V_57 = F_101 ( V_116 , V_42 -> V_3 , V_136 ) ;
if ( V_57 < 0 ) {
F_102 ( V_6 , V_42 ) ;
return V_57 ;
}
F_103 ( V_116 , V_6 , V_42 ) ;
if ( V_116 -> V_140 ) {
F_104 ( sizeof( struct V_54 ) ) ;
V_116 -> V_141 = sizeof( struct V_54 ) ;
memcpy ( V_116 -> V_140 , V_42 -> V_62 , V_116 -> V_141 ) ;
}
F_102 ( V_6 , V_42 ) ;
return V_136 ;
}
static int T_5 F_105 ( void )
{
int V_57 ;
F_106 ( L_25 V_176 L_26 ) ;
V_57 = F_107 ( & V_177 ) ;
if ( V_57 < 0 ) {
F_63 ( V_110 L_27 ) ;
return V_57 ;
}
V_167 = F_108 ( L_28 , V_16 . V_178 ) ;
return 0 ;
}
static void T_6 F_109 ( void )
{
F_110 ( & V_177 ) ;
if ( V_167 )
F_93 ( L_28 , V_16 . V_178 ) ;
}
