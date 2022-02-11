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
return F_13 ( V_35 , F_7 , F_14 ( V_34 ) ) ;
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
V_37 = F_17 ( V_41 + sizeof( struct V_42 ) , F_18 () ) ;
if ( ! V_37 )
goto V_43;
F_19 ( V_37 ) ;
F_20 ( V_37 ) -> V_8 = V_10 -> V_8 ;
F_20 ( V_37 ) -> V_44 = 0 ;
memcpy ( F_21 ( V_37 , V_41 ) , V_38 , V_41 ) ;
V_37 -> V_10 = V_10 ;
F_22 ( V_37 , V_21 -> V_6 ) ;
F_23 ( V_37 , 1 ) ;
V_21 -> V_40 ++ ;
V_21 -> V_25 ++ ;
if ( V_21 -> V_40 >= V_21 -> V_27 )
V_21 -> V_40 = 0 ;
V_43:
F_24 ( V_10 ) ;
}
static void F_25 ( struct V_20 * V_21 , struct V_45 * V_46 ,
struct V_1 * V_39 , int V_47 )
{
struct V_36 * V_37 ;
struct V_1 * V_48 ;
struct V_49 * V_50 ;
struct V_5 * V_6 = V_21 -> V_6 ;
unsigned int V_51 = V_46 -> V_27 * V_41 ;
int V_52 ;
V_37 = F_17 ( sizeof( * V_46 ) + V_51 , F_18 () ) ;
if ( ! V_37 )
return;
memcpy ( F_21 ( V_37 , sizeof( * V_46 ) ) , V_46 , sizeof( * V_46 ) ) ;
if ( V_46 -> V_27 ) {
V_48 = (struct V_1 * ) F_26 ( V_37 ) ;
memcpy ( F_21 ( V_37 , V_51 ) , V_39 , V_51 ) ;
if ( V_46 -> V_27 == 1 )
V_48 -> V_53 &= V_54 ;
}
if ( V_47 ) {
V_37 -> V_55 = V_21 -> V_56 ;
}
F_27 ( sizeof( struct V_49 ) ) ;
V_50 = (struct V_49 * ) V_37 -> V_57 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_58 = V_59 ;
V_50 -> V_60 = V_21 -> V_61 ;
V_52 = F_28 ( V_6 , V_37 ) ;
if ( V_52 < 0 ) {
struct V_4 * V_19 = F_2 ( V_6 ) ;
F_29 ( V_37 ) ;
V_19 -> V_23 ++ ;
}
}
static void F_30 ( struct V_20 * V_21 )
{
if ( V_21 -> V_30 . V_31 && V_21 -> V_62 )
F_31 ( & V_21 -> V_63 ,
F_32 ( F_33 () , V_21 -> V_30 ) ,
V_64 ) ;
else if ( V_21 -> V_32 . V_31 )
F_31 ( & V_21 -> V_63 ,
F_32 ( F_33 () , V_21 -> V_32 ) ,
V_64 ) ;
}
static void F_34 ( unsigned long V_3 )
{
struct V_20 * V_21 = (struct V_20 * ) V_3 ;
struct V_45 V_65 ;
if ( V_21 -> V_30 . V_31 && ( V_21 -> V_62 > 0 ) ) {
V_21 -> V_62 -- ;
if ( ! V_21 -> V_62 && ( V_21 -> V_28 & V_66 ) ) {
V_65 . V_67 = V_68 ;
V_65 . V_28 = V_21 -> V_28 ;
V_65 . V_62 = V_21 -> V_62 ;
V_65 . V_69 = V_21 -> V_69 ;
V_65 . V_70 = V_21 -> V_70 ;
V_65 . V_26 = V_21 -> V_26 ;
V_65 . V_27 = 0 ;
F_25 ( V_21 , & V_65 , NULL , 0 ) ;
}
F_15 ( V_21 ) ;
} else if ( V_21 -> V_32 . V_31 )
F_15 ( V_21 ) ;
F_30 ( V_21 ) ;
}
static enum V_71 F_35 ( struct V_72 * V_72 )
{
struct V_20 * V_21 = F_36 ( V_72 , struct V_20 , V_63 ) ;
F_37 ( & V_21 -> V_73 ) ;
return V_74 ;
}
static void F_38 ( struct V_20 * V_21 , struct V_1 * V_3 )
{
struct V_45 V_46 ;
V_21 -> V_33 ++ ;
if ( V_21 -> V_33 > V_75 / 100 )
V_21 -> V_33 = V_21 -> V_25 = 0 ;
V_3 -> V_53 &= ( V_54 | V_76 ) ;
V_46 . V_67 = V_77 ;
V_46 . V_28 = V_21 -> V_28 ;
V_46 . V_62 = V_21 -> V_62 ;
V_46 . V_69 = V_21 -> V_69 ;
V_46 . V_70 = V_21 -> V_70 ;
V_46 . V_26 = V_21 -> V_26 ;
V_46 . V_27 = 1 ;
F_25 ( V_21 , & V_46 , V_3 , 1 ) ;
}
static void F_39 ( struct V_20 * V_21 ,
struct V_1 * V_78 ,
const struct V_1 * V_79 )
{
memcpy ( V_78 , V_79 , V_41 ) ;
V_78 -> V_53 |= ( V_76 | V_80 ) ;
if ( ! V_21 -> V_32 . V_31 ) {
F_38 ( V_21 , V_78 ) ;
return;
}
if ( F_40 ( & V_21 -> V_81 ) )
return;
if ( ! V_21 -> V_82 . V_31 )
goto V_83;
if ( F_41 ( F_33 () , V_21 -> V_82 ) <
F_10 ( V_21 -> V_32 ) ) {
F_31 ( & V_21 -> V_81 ,
F_32 ( V_21 -> V_82 , V_21 -> V_32 ) ,
V_64 ) ;
return;
}
V_83:
F_38 ( V_21 , V_78 ) ;
V_21 -> V_82 = F_33 () ;
}
static void F_42 ( struct V_20 * V_21 , unsigned int V_84 ,
const struct V_1 * V_79 )
{
if ( ! ( V_21 -> V_85 [ V_84 ] . V_53 & V_76 ) ) {
F_39 ( V_21 , & V_21 -> V_85 [ V_84 ] , V_79 ) ;
return;
}
if ( ( F_1 ( & V_21 -> V_39 [ V_84 ] ) & F_1 ( V_79 ) ) !=
( F_1 ( & V_21 -> V_39 [ V_84 ] ) & F_1 ( & V_21 -> V_85 [ V_84 ] ) ) ) {
F_39 ( V_21 , & V_21 -> V_85 [ V_84 ] , V_79 ) ;
return;
}
if ( V_21 -> V_28 & V_29 ) {
if ( V_79 -> V_53 != ( V_21 -> V_85 [ V_84 ] . V_53 &
V_54 ) ) {
F_39 ( V_21 , & V_21 -> V_85 [ V_84 ] ,
V_79 ) ;
return;
}
}
}
static void F_43 ( struct V_20 * V_21 )
{
if ( V_21 -> V_28 & V_86 )
return;
if ( V_21 -> V_30 . V_31 )
F_31 ( & V_21 -> V_63 , V_21 -> V_30 , V_87 ) ;
}
static void F_44 ( unsigned long V_3 )
{
struct V_20 * V_21 = (struct V_20 * ) V_3 ;
struct V_45 V_65 ;
V_65 . V_67 = V_88 ;
V_65 . V_28 = V_21 -> V_28 ;
V_65 . V_62 = V_21 -> V_62 ;
V_65 . V_69 = V_21 -> V_69 ;
V_65 . V_70 = V_21 -> V_70 ;
V_65 . V_26 = V_21 -> V_26 ;
V_65 . V_27 = 0 ;
F_25 ( V_21 , & V_65 , NULL , 0 ) ;
}
static enum V_71 F_45 ( struct V_72 * V_72 )
{
struct V_20 * V_21 = F_36 ( V_72 , struct V_20 , V_63 ) ;
F_46 ( & V_21 -> V_73 ) ;
if ( ( V_21 -> V_28 & V_89 ) && V_21 -> V_85 ) {
memset ( V_21 -> V_85 , 0 , V_21 -> V_27 * V_41 ) ;
}
return V_74 ;
}
static inline int F_47 ( struct V_20 * V_21 , int V_90 ,
unsigned int V_84 )
{
if ( ( V_21 -> V_85 ) && ( V_21 -> V_85 [ V_84 ] . V_53 & V_80 ) ) {
if ( V_90 )
F_38 ( V_21 , & V_21 -> V_85 [ V_84 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_48 ( struct V_20 * V_21 , int V_90 )
{
int V_91 = 0 ;
if ( V_21 -> V_27 > 1 ) {
unsigned int V_92 ;
for ( V_92 = 1 ; V_92 < V_21 -> V_27 ; V_92 ++ )
V_91 += F_47 ( V_21 , V_90 , V_92 ) ;
} else {
V_91 += F_47 ( V_21 , V_90 , 0 ) ;
}
return V_91 ;
}
static void F_49 ( unsigned long V_3 )
{
struct V_20 * V_21 = (struct V_20 * ) V_3 ;
F_48 ( V_21 , 1 ) ;
}
static enum V_71 F_50 ( struct V_72 * V_72 )
{
struct V_20 * V_21 = F_36 ( V_72 , struct V_20 , V_81 ) ;
F_37 ( & V_21 -> V_93 ) ;
if ( F_48 ( V_21 , 0 ) ) {
F_51 ( V_72 , F_33 () , V_21 -> V_32 ) ;
return V_94 ;
} else {
V_21 -> V_82 = F_52 ( 0 , 0 ) ;
return V_74 ;
}
}
static void F_53 ( struct V_36 * V_37 , void * V_3 )
{
struct V_20 * V_21 = (struct V_20 * ) V_3 ;
const struct V_1 * V_95 = (struct V_1 * ) V_37 -> V_3 ;
unsigned int V_92 ;
F_54 ( & V_21 -> V_63 ) ;
if ( V_21 -> V_26 != V_95 -> V_26 )
return;
V_21 -> V_56 = V_37 -> V_55 ;
V_21 -> V_61 = V_37 -> V_10 -> V_8 ;
V_21 -> V_25 ++ ;
if ( V_21 -> V_28 & V_96 ) {
F_15 ( V_21 ) ;
return;
}
if ( V_21 -> V_28 & V_97 ) {
F_39 ( V_21 , & V_21 -> V_85 [ 0 ] , V_95 ) ;
goto V_98;
}
if ( V_21 -> V_27 == 1 ) {
F_42 ( V_21 , 0 , V_95 ) ;
goto V_98;
}
if ( V_21 -> V_27 > 1 ) {
for ( V_92 = 1 ; V_92 < V_21 -> V_27 ; V_92 ++ ) {
if ( ( F_1 ( & V_21 -> V_39 [ 0 ] ) & F_1 ( V_95 ) ) ==
( F_1 ( & V_21 -> V_39 [ 0 ] ) &
F_1 ( & V_21 -> V_39 [ V_92 ] ) ) ) {
F_42 ( V_21 , V_92 , V_95 ) ;
break;
}
}
}
V_98:
F_43 ( V_21 ) ;
}
static struct V_20 * F_55 ( struct V_99 * V_100 , T_2 V_26 ,
int V_8 )
{
struct V_20 * V_21 ;
F_9 (op, ops, list) {
if ( ( V_21 -> V_26 == V_26 ) && ( V_21 -> V_8 == V_8 ) )
return V_21 ;
}
return NULL ;
}
static void F_56 ( struct V_20 * V_21 )
{
F_54 ( & V_21 -> V_63 ) ;
F_54 ( & V_21 -> V_81 ) ;
if ( V_21 -> V_73 . V_101 )
F_57 ( & V_21 -> V_73 ) ;
if ( V_21 -> V_93 . V_101 )
F_57 ( & V_21 -> V_93 ) ;
if ( ( V_21 -> V_39 ) && ( V_21 -> V_39 != & V_21 -> V_102 ) )
F_58 ( V_21 -> V_39 ) ;
if ( ( V_21 -> V_85 ) && ( V_21 -> V_85 != & V_21 -> V_103 ) )
F_58 ( V_21 -> V_85 ) ;
F_58 ( V_21 ) ;
}
static void F_59 ( struct V_9 * V_10 , struct V_20 * V_21 )
{
if ( V_21 -> V_104 == V_10 ) {
F_60 ( V_10 , V_21 -> V_26 , F_61 ( V_21 -> V_26 ) ,
F_53 , V_21 ) ;
V_21 -> V_104 = NULL ;
} else
F_62 ( V_105 L_21
L_22 , V_21 -> V_104 , V_10 ) ;
}
static int F_63 ( struct V_99 * V_100 , T_2 V_26 , int V_8 )
{
struct V_20 * V_21 , * V_106 ;
F_64 (op, n, ops, list) {
if ( ( V_21 -> V_26 == V_26 ) && ( V_21 -> V_8 == V_8 ) ) {
if ( V_21 -> V_8 ) {
if ( V_21 -> V_104 ) {
struct V_9 * V_10 ;
V_10 = F_16 ( & V_11 ,
V_21 -> V_8 ) ;
if ( V_10 ) {
F_59 ( V_10 , V_21 ) ;
F_24 ( V_10 ) ;
}
}
} else
F_60 ( NULL , V_21 -> V_26 ,
F_61 ( V_21 -> V_26 ) ,
F_53 , V_21 ) ;
F_65 ( & V_21 -> V_107 ) ;
F_56 ( V_21 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_66 ( struct V_99 * V_100 , T_2 V_26 , int V_8 )
{
struct V_20 * V_21 , * V_106 ;
F_64 (op, n, ops, list) {
if ( ( V_21 -> V_26 == V_26 ) && ( V_21 -> V_8 == V_8 ) ) {
F_65 ( & V_21 -> V_107 ) ;
F_56 ( V_21 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_67 ( struct V_99 * V_100 , struct V_45 * V_65 ,
int V_8 )
{
struct V_20 * V_21 = F_55 ( V_100 , V_65 -> V_26 , V_8 ) ;
if ( ! V_21 )
return - V_108 ;
V_65 -> V_28 = V_21 -> V_28 ;
V_65 -> V_62 = V_21 -> V_62 ;
V_65 -> V_69 = V_21 -> V_69 ;
V_65 -> V_70 = V_21 -> V_70 ;
V_65 -> V_27 = V_21 -> V_27 ;
F_25 ( V_21 , V_65 , V_21 -> V_39 , 0 ) ;
return V_109 ;
}
static int F_68 ( struct V_45 * V_65 , struct V_110 * V_111 ,
int V_8 , struct V_5 * V_6 )
{
struct V_4 * V_19 = F_2 ( V_6 ) ;
struct V_20 * V_21 ;
unsigned int V_92 ;
int V_52 ;
if ( ! V_8 )
return - V_112 ;
if ( V_65 -> V_27 < 1 || V_65 -> V_27 > V_113 )
return - V_108 ;
V_21 = F_55 ( & V_19 -> V_114 , V_65 -> V_26 , V_8 ) ;
if ( V_21 ) {
if ( V_65 -> V_27 > V_21 -> V_27 )
return - V_115 ;
for ( V_92 = 0 ; V_92 < V_65 -> V_27 ; V_92 ++ ) {
V_52 = F_69 ( ( V_116 * ) & V_21 -> V_39 [ V_92 ] , V_111 , V_41 ) ;
if ( V_21 -> V_39 [ V_92 ] . V_53 > 8 )
V_52 = - V_108 ;
if ( V_52 < 0 )
return V_52 ;
if ( V_65 -> V_28 & V_117 ) {
V_21 -> V_39 [ V_92 ] . V_26 = V_65 -> V_26 ;
}
}
} else {
V_21 = F_70 ( V_118 , V_119 ) ;
if ( ! V_21 )
return - V_120 ;
V_21 -> V_26 = V_65 -> V_26 ;
if ( V_65 -> V_27 > 1 ) {
V_21 -> V_39 = F_71 ( V_65 -> V_27 * V_41 ,
V_119 ) ;
if ( ! V_21 -> V_39 ) {
F_58 ( V_21 ) ;
return - V_120 ;
}
} else
V_21 -> V_39 = & V_21 -> V_102 ;
for ( V_92 = 0 ; V_92 < V_65 -> V_27 ; V_92 ++ ) {
V_52 = F_69 ( ( V_116 * ) & V_21 -> V_39 [ V_92 ] , V_111 , V_41 ) ;
if ( V_21 -> V_39 [ V_92 ] . V_53 > 8 )
V_52 = - V_108 ;
if ( V_52 < 0 ) {
if ( V_21 -> V_39 != & V_21 -> V_102 )
F_58 ( V_21 -> V_39 ) ;
F_58 ( V_21 ) ;
return V_52 ;
}
if ( V_65 -> V_28 & V_117 ) {
V_21 -> V_39 [ V_92 ] . V_26 = V_65 -> V_26 ;
}
}
V_21 -> V_85 = NULL ;
V_21 -> V_6 = V_6 ;
V_21 -> V_8 = V_8 ;
F_72 ( & V_21 -> V_63 , V_121 , V_87 ) ;
V_21 -> V_63 . V_122 = F_35 ;
F_73 ( & V_21 -> V_73 , F_34 ,
( unsigned long ) V_21 ) ;
F_72 ( & V_21 -> V_81 , V_121 , V_87 ) ;
F_74 ( & V_21 -> V_107 , & V_19 -> V_114 ) ;
}
if ( V_21 -> V_27 != V_65 -> V_27 ) {
V_21 -> V_27 = V_65 -> V_27 ;
V_21 -> V_40 = 0 ;
}
V_21 -> V_28 = V_65 -> V_28 ;
if ( V_21 -> V_28 & V_123 ) {
V_21 -> V_40 = 0 ;
}
if ( V_21 -> V_28 & V_124 ) {
V_21 -> V_62 = V_65 -> V_62 ;
V_21 -> V_69 = V_65 -> V_69 ;
V_21 -> V_70 = V_65 -> V_70 ;
V_21 -> V_30 = F_75 ( V_65 -> V_69 ) ;
V_21 -> V_32 = F_75 ( V_65 -> V_70 ) ;
if ( ! V_21 -> V_30 . V_31 && ! V_21 -> V_32 . V_31 )
F_54 ( & V_21 -> V_63 ) ;
}
if ( V_21 -> V_28 & V_125 ) {
F_54 ( & V_21 -> V_63 ) ;
V_21 -> V_28 |= V_126 ;
}
if ( V_21 -> V_28 & V_126 ) {
F_15 ( V_21 ) ;
if ( V_21 -> V_62 )
V_21 -> V_62 -- ;
}
if ( V_21 -> V_28 & V_125 )
F_30 ( V_21 ) ;
return V_65 -> V_27 * V_41 + V_109 ;
}
static int F_76 ( struct V_45 * V_65 , struct V_110 * V_111 ,
int V_8 , struct V_5 * V_6 )
{
struct V_4 * V_19 = F_2 ( V_6 ) ;
struct V_20 * V_21 ;
int V_127 ;
int V_52 = 0 ;
if ( ( V_65 -> V_28 & V_97 ) || ( ! ( V_65 -> V_27 ) ) ) {
V_65 -> V_28 |= V_97 ;
V_65 -> V_27 = 0 ;
}
if ( V_65 -> V_27 > V_113 + 1 )
return - V_108 ;
if ( ( V_65 -> V_28 & V_96 ) &&
( ( V_65 -> V_27 != 1 ) ||
( ! ( V_65 -> V_26 & V_128 ) ) ) )
return - V_108 ;
V_21 = F_55 ( & V_19 -> V_129 , V_65 -> V_26 , V_8 ) ;
if ( V_21 ) {
if ( V_65 -> V_27 > V_21 -> V_27 )
return - V_115 ;
if ( V_65 -> V_27 ) {
V_52 = F_69 ( ( V_116 * ) V_21 -> V_39 , V_111 ,
V_65 -> V_27 * V_41 ) ;
if ( V_52 < 0 )
return V_52 ;
memset ( V_21 -> V_85 , 0 , V_65 -> V_27 * V_41 ) ;
}
V_21 -> V_27 = V_65 -> V_27 ;
V_127 = 0 ;
} else {
V_21 = F_70 ( V_118 , V_119 ) ;
if ( ! V_21 )
return - V_120 ;
V_21 -> V_26 = V_65 -> V_26 ;
V_21 -> V_27 = V_65 -> V_27 ;
if ( V_65 -> V_27 > 1 ) {
V_21 -> V_39 = F_71 ( V_65 -> V_27 * V_41 ,
V_119 ) ;
if ( ! V_21 -> V_39 ) {
F_58 ( V_21 ) ;
return - V_120 ;
}
V_21 -> V_85 = F_70 ( V_65 -> V_27 * V_41 ,
V_119 ) ;
if ( ! V_21 -> V_85 ) {
F_58 ( V_21 -> V_39 ) ;
F_58 ( V_21 ) ;
return - V_120 ;
}
} else {
V_21 -> V_39 = & V_21 -> V_102 ;
V_21 -> V_85 = & V_21 -> V_103 ;
}
if ( V_65 -> V_27 ) {
V_52 = F_69 ( ( V_116 * ) V_21 -> V_39 , V_111 ,
V_65 -> V_27 * V_41 ) ;
if ( V_52 < 0 ) {
if ( V_21 -> V_39 != & V_21 -> V_102 )
F_58 ( V_21 -> V_39 ) ;
if ( V_21 -> V_85 != & V_21 -> V_103 )
F_58 ( V_21 -> V_85 ) ;
F_58 ( V_21 ) ;
return V_52 ;
}
}
V_21 -> V_6 = V_6 ;
V_21 -> V_8 = V_8 ;
V_21 -> V_61 = V_8 ;
F_72 ( & V_21 -> V_63 , V_121 , V_87 ) ;
V_21 -> V_63 . V_122 = F_45 ;
F_73 ( & V_21 -> V_73 , F_44 ,
( unsigned long ) V_21 ) ;
F_72 ( & V_21 -> V_81 , V_121 , V_87 ) ;
V_21 -> V_81 . V_122 = F_50 ;
F_73 ( & V_21 -> V_93 , F_49 ,
( unsigned long ) V_21 ) ;
F_74 ( & V_21 -> V_107 , & V_19 -> V_129 ) ;
V_127 = 1 ;
}
V_21 -> V_28 = V_65 -> V_28 ;
if ( V_21 -> V_28 & V_96 ) {
F_54 ( & V_21 -> V_81 ) ;
F_54 ( & V_21 -> V_63 ) ;
if ( ( V_21 -> V_28 & V_117 ) ||
( V_21 -> V_39 [ 0 ] . V_26 == V_21 -> V_26 ) )
V_21 -> V_39 [ 0 ] . V_26 = V_21 -> V_26 & ~ V_128 ;
} else {
if ( V_21 -> V_28 & V_124 ) {
V_21 -> V_69 = V_65 -> V_69 ;
V_21 -> V_70 = V_65 -> V_70 ;
V_21 -> V_30 = F_75 ( V_65 -> V_69 ) ;
V_21 -> V_32 = F_75 ( V_65 -> V_70 ) ;
if ( ! V_21 -> V_30 . V_31 )
F_54 ( & V_21 -> V_63 ) ;
V_21 -> V_82 = F_52 ( 0 , 0 ) ;
F_54 ( & V_21 -> V_81 ) ;
F_48 ( V_21 , 1 ) ;
}
if ( ( V_21 -> V_28 & V_125 ) && V_21 -> V_30 . V_31 )
F_31 ( & V_21 -> V_63 , V_21 -> V_30 ,
V_87 ) ;
}
if ( V_127 ) {
if ( V_8 ) {
struct V_9 * V_10 ;
V_10 = F_16 ( & V_11 , V_8 ) ;
if ( V_10 ) {
V_52 = F_77 ( V_10 , V_21 -> V_26 ,
F_61 ( V_21 -> V_26 ) ,
F_53 , V_21 ,
L_23 ) ;
V_21 -> V_104 = V_10 ;
F_24 ( V_10 ) ;
}
} else
V_52 = F_77 ( NULL , V_21 -> V_26 ,
F_61 ( V_21 -> V_26 ) ,
F_53 , V_21 , L_23 ) ;
if ( V_52 ) {
F_65 ( & V_21 -> V_107 ) ;
F_56 ( V_21 ) ;
return V_52 ;
}
}
return V_65 -> V_27 * V_41 + V_109 ;
}
static int F_78 ( struct V_110 * V_111 , int V_8 , struct V_5 * V_6 )
{
struct V_36 * V_37 ;
struct V_9 * V_10 ;
int V_52 ;
if ( ! V_8 )
return - V_112 ;
V_37 = F_17 ( V_41 + sizeof( struct V_42 ) , V_119 ) ;
if ( ! V_37 )
return - V_120 ;
F_19 ( V_37 ) ;
V_52 = F_69 ( F_21 ( V_37 , V_41 ) , V_111 , V_41 ) ;
if ( V_52 < 0 ) {
F_29 ( V_37 ) ;
return V_52 ;
}
V_10 = F_16 ( & V_11 , V_8 ) ;
if ( ! V_10 ) {
F_29 ( V_37 ) ;
return - V_112 ;
}
F_20 ( V_37 ) -> V_8 = V_10 -> V_8 ;
F_20 ( V_37 ) -> V_44 = 0 ;
V_37 -> V_10 = V_10 ;
F_22 ( V_37 , V_6 ) ;
V_52 = F_23 ( V_37 , 1 ) ;
F_24 ( V_10 ) ;
if ( V_52 )
return V_52 ;
return V_41 + V_109 ;
}
static int F_79 ( struct V_130 * V_5 , struct V_110 * V_111 , T_3 V_131 )
{
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_4 * V_19 = F_2 ( V_6 ) ;
int V_8 = V_19 -> V_8 ;
struct V_45 V_65 ;
int V_132 ;
if ( ! V_19 -> V_133 )
return - V_134 ;
if ( V_131 < V_109 || ( V_131 - V_109 ) % V_41 )
return - V_108 ;
if ( ! V_8 && V_111 -> V_135 ) {
F_80 ( struct V_49 * , V_50 , V_111 -> V_135 ) ;
if ( V_111 -> V_136 < sizeof( * V_50 ) )
return - V_108 ;
if ( V_50 -> V_58 != V_59 )
return - V_108 ;
V_8 = V_50 -> V_60 ;
if ( V_8 ) {
struct V_9 * V_10 ;
V_10 = F_16 ( & V_11 , V_8 ) ;
if ( ! V_10 )
return - V_112 ;
if ( V_10 -> type != V_137 ) {
F_24 ( V_10 ) ;
return - V_112 ;
}
F_24 ( V_10 ) ;
}
}
V_132 = F_69 ( ( V_116 * ) & V_65 , V_111 , V_109 ) ;
if ( V_132 < 0 )
return V_132 ;
F_81 ( V_6 ) ;
switch ( V_65 . V_67 ) {
case V_138 :
V_132 = F_68 ( & V_65 , V_111 , V_8 , V_6 ) ;
break;
case V_139 :
V_132 = F_76 ( & V_65 , V_111 , V_8 , V_6 ) ;
break;
case V_140 :
if ( F_66 ( & V_19 -> V_114 , V_65 . V_26 , V_8 ) )
V_132 = V_109 ;
else
V_132 = - V_108 ;
break;
case V_141 :
if ( F_63 ( & V_19 -> V_129 , V_65 . V_26 , V_8 ) )
V_132 = V_109 ;
else
V_132 = - V_108 ;
break;
case V_142 :
V_65 . V_67 = V_143 ;
V_132 = F_67 ( & V_19 -> V_114 , & V_65 , V_8 ) ;
break;
case V_144 :
V_65 . V_67 = V_145 ;
V_132 = F_67 ( & V_19 -> V_129 , & V_65 , V_8 ) ;
break;
case V_146 :
if ( ( V_65 . V_27 != 1 ) || ( V_131 != V_41 + V_109 ) )
V_132 = - V_108 ;
else
V_132 = F_78 ( V_111 , V_8 , V_6 ) ;
break;
default:
V_132 = - V_108 ;
break;
}
F_82 ( V_6 ) ;
return V_132 ;
}
static int F_83 ( struct V_147 * V_148 , unsigned long V_111 ,
void * V_149 )
{
struct V_9 * V_10 = F_84 ( V_149 ) ;
struct V_4 * V_19 = F_36 ( V_148 , struct V_4 , V_150 ) ;
struct V_5 * V_6 = & V_19 -> V_6 ;
struct V_20 * V_21 ;
int V_151 = 0 ;
if ( ! F_85 ( F_86 ( V_10 ) , & V_11 ) )
return V_152 ;
if ( V_10 -> type != V_137 )
return V_152 ;
switch ( V_111 ) {
case V_153 :
F_81 ( V_6 ) ;
F_9 (op, &bo->rx_ops, list)
if ( V_21 -> V_104 == V_10 )
F_59 ( V_10 , V_21 ) ;
if ( V_19 -> V_133 && V_19 -> V_8 == V_10 -> V_8 ) {
V_19 -> V_133 = 0 ;
V_19 -> V_8 = 0 ;
V_151 = 1 ;
}
F_82 ( V_6 ) ;
if ( V_151 ) {
V_6 -> V_154 = V_112 ;
if ( ! F_87 ( V_6 , V_155 ) )
V_6 -> V_156 ( V_6 ) ;
}
break;
case V_157 :
if ( V_19 -> V_133 && V_19 -> V_8 == V_10 -> V_8 ) {
V_6 -> V_154 = V_158 ;
if ( ! F_87 ( V_6 , V_155 ) )
V_6 -> V_156 ( V_6 ) ;
}
}
return V_152 ;
}
static int F_88 ( struct V_5 * V_6 )
{
struct V_4 * V_19 = F_2 ( V_6 ) ;
V_19 -> V_133 = 0 ;
V_19 -> V_8 = 0 ;
V_19 -> V_23 = 0 ;
V_19 -> V_159 = NULL ;
F_89 ( & V_19 -> V_114 ) ;
F_89 ( & V_19 -> V_129 ) ;
V_19 -> V_150 . V_160 = F_83 ;
F_90 ( & V_19 -> V_150 ) ;
return 0 ;
}
static int F_91 ( struct V_130 * V_5 )
{
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_4 * V_19 ;
struct V_20 * V_21 , * V_161 ;
if ( V_6 == NULL )
return 0 ;
V_19 = F_2 ( V_6 ) ;
F_92 ( & V_19 -> V_150 ) ;
F_81 ( V_6 ) ;
F_64 (op, next, &bo->tx_ops, list)
F_56 ( V_21 ) ;
F_64 (op, next, &bo->rx_ops, list) {
if ( V_21 -> V_8 ) {
if ( V_21 -> V_104 ) {
struct V_9 * V_10 ;
V_10 = F_16 ( & V_11 , V_21 -> V_8 ) ;
if ( V_10 ) {
F_59 ( V_10 , V_21 ) ;
F_24 ( V_10 ) ;
}
}
} else
F_60 ( NULL , V_21 -> V_26 ,
F_61 ( V_21 -> V_26 ) ,
F_53 , V_21 ) ;
F_56 ( V_21 ) ;
}
if ( V_162 && V_19 -> V_159 )
F_93 ( V_19 -> V_163 , V_162 ) ;
if ( V_19 -> V_133 ) {
V_19 -> V_133 = 0 ;
V_19 -> V_8 = 0 ;
}
F_94 ( V_6 ) ;
V_5 -> V_6 = NULL ;
F_82 ( V_6 ) ;
F_95 ( V_6 ) ;
return 0 ;
}
static int F_96 ( struct V_130 * V_5 , struct V_164 * V_165 , int V_166 ,
int V_28 )
{
struct V_49 * V_50 = (struct V_49 * ) V_165 ;
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_4 * V_19 = F_2 ( V_6 ) ;
if ( V_166 < sizeof( * V_50 ) )
return - V_108 ;
if ( V_19 -> V_133 )
return - V_167 ;
if ( V_50 -> V_60 ) {
struct V_9 * V_10 ;
V_10 = F_16 ( & V_11 , V_50 -> V_60 ) ;
if ( ! V_10 )
return - V_112 ;
if ( V_10 -> type != V_137 ) {
F_24 ( V_10 ) ;
return - V_112 ;
}
V_19 -> V_8 = V_10 -> V_8 ;
F_24 ( V_10 ) ;
} else {
V_19 -> V_8 = 0 ;
}
V_19 -> V_133 = 1 ;
if ( V_162 ) {
sprintf ( V_19 -> V_163 , L_24 , F_97 ( V_6 ) ) ;
V_19 -> V_159 = F_98 ( V_19 -> V_163 , 0644 ,
V_162 ,
& V_168 , V_6 ) ;
}
return 0 ;
}
static int F_99 ( struct V_130 * V_5 , struct V_110 * V_111 , T_3 V_131 ,
int V_28 )
{
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_36 * V_37 ;
int error = 0 ;
int V_169 ;
int V_52 ;
V_169 = V_28 & V_170 ;
V_28 &= ~ V_170 ;
V_37 = F_100 ( V_6 , V_28 , V_169 , & error ) ;
if ( ! V_37 )
return error ;
if ( V_37 -> V_166 < V_131 )
V_131 = V_37 -> V_166 ;
V_52 = F_101 ( V_111 , V_37 -> V_3 , V_131 ) ;
if ( V_52 < 0 ) {
F_102 ( V_6 , V_37 ) ;
return V_52 ;
}
F_103 ( V_111 , V_6 , V_37 ) ;
if ( V_111 -> V_135 ) {
F_104 ( sizeof( struct V_49 ) ) ;
V_111 -> V_136 = sizeof( struct V_49 ) ;
memcpy ( V_111 -> V_135 , V_37 -> V_57 , V_111 -> V_136 ) ;
}
F_102 ( V_6 , V_37 ) ;
return V_131 ;
}
static int T_4 F_105 ( void )
{
int V_52 ;
F_106 ( L_25 V_171 L_26 ) ;
V_52 = F_107 ( & V_172 ) ;
if ( V_52 < 0 ) {
F_62 ( V_105 L_27 ) ;
return V_52 ;
}
V_162 = F_108 ( L_28 , V_11 . V_173 ) ;
return 0 ;
}
static void T_5 F_109 ( void )
{
F_110 ( & V_172 ) ;
if ( V_162 )
F_93 ( L_28 , V_11 . V_173 ) ;
}
