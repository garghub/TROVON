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
static void F_25 ( struct V_20 * V_21 , struct V_44 * V_45 ,
struct V_1 * V_39 , int V_46 )
{
struct V_36 * V_37 ;
struct V_1 * V_47 ;
struct V_48 * V_49 ;
struct V_5 * V_6 = V_21 -> V_6 ;
unsigned int V_50 = V_45 -> V_27 * V_41 ;
int V_51 ;
V_37 = F_17 ( sizeof( * V_45 ) + V_50 , F_18 () ) ;
if ( ! V_37 )
return;
memcpy ( F_21 ( V_37 , sizeof( * V_45 ) ) , V_45 , sizeof( * V_45 ) ) ;
if ( V_45 -> V_27 ) {
V_47 = (struct V_1 * ) F_26 ( V_37 ) ;
memcpy ( F_21 ( V_37 , V_50 ) , V_39 , V_50 ) ;
if ( V_45 -> V_27 == 1 )
V_47 -> V_52 &= V_53 ;
}
if ( V_46 ) {
V_37 -> V_54 = V_21 -> V_55 ;
}
F_27 ( sizeof( struct V_48 ) ) ;
V_49 = (struct V_48 * ) V_37 -> V_56 ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
V_49 -> V_57 = V_58 ;
V_49 -> V_59 = V_21 -> V_60 ;
V_51 = F_28 ( V_6 , V_37 ) ;
if ( V_51 < 0 ) {
struct V_4 * V_19 = F_2 ( V_6 ) ;
F_29 ( V_37 ) ;
V_19 -> V_23 ++ ;
}
}
static void F_30 ( struct V_20 * V_21 )
{
if ( V_21 -> V_30 . V_31 && V_21 -> V_61 )
F_31 ( & V_21 -> V_62 ,
F_32 ( F_33 () , V_21 -> V_30 ) ,
V_63 ) ;
else if ( V_21 -> V_32 . V_31 )
F_31 ( & V_21 -> V_62 ,
F_32 ( F_33 () , V_21 -> V_32 ) ,
V_63 ) ;
}
static void F_34 ( unsigned long V_3 )
{
struct V_20 * V_21 = (struct V_20 * ) V_3 ;
struct V_44 V_64 ;
if ( V_21 -> V_30 . V_31 && ( V_21 -> V_61 > 0 ) ) {
V_21 -> V_61 -- ;
if ( ! V_21 -> V_61 && ( V_21 -> V_28 & V_65 ) ) {
V_64 . V_66 = V_67 ;
V_64 . V_28 = V_21 -> V_28 ;
V_64 . V_61 = V_21 -> V_61 ;
V_64 . V_68 = V_21 -> V_68 ;
V_64 . V_69 = V_21 -> V_69 ;
V_64 . V_26 = V_21 -> V_26 ;
V_64 . V_27 = 0 ;
F_25 ( V_21 , & V_64 , NULL , 0 ) ;
}
F_15 ( V_21 ) ;
} else if ( V_21 -> V_32 . V_31 )
F_15 ( V_21 ) ;
F_30 ( V_21 ) ;
}
static enum V_70 F_35 ( struct V_71 * V_71 )
{
struct V_20 * V_21 = F_36 ( V_71 , struct V_20 , V_62 ) ;
F_37 ( & V_21 -> V_72 ) ;
return V_73 ;
}
static void F_38 ( struct V_20 * V_21 , struct V_1 * V_3 )
{
struct V_44 V_45 ;
V_21 -> V_33 ++ ;
if ( V_21 -> V_33 > V_74 / 100 )
V_21 -> V_33 = V_21 -> V_25 = 0 ;
V_3 -> V_52 &= ( V_53 | V_75 ) ;
V_45 . V_66 = V_76 ;
V_45 . V_28 = V_21 -> V_28 ;
V_45 . V_61 = V_21 -> V_61 ;
V_45 . V_68 = V_21 -> V_68 ;
V_45 . V_69 = V_21 -> V_69 ;
V_45 . V_26 = V_21 -> V_26 ;
V_45 . V_27 = 1 ;
F_25 ( V_21 , & V_45 , V_3 , 1 ) ;
}
static void F_39 ( struct V_20 * V_21 ,
struct V_1 * V_77 ,
const struct V_1 * V_78 )
{
memcpy ( V_77 , V_78 , V_41 ) ;
V_77 -> V_52 |= ( V_75 | V_79 ) ;
if ( ! V_21 -> V_32 . V_31 ) {
F_38 ( V_21 , V_77 ) ;
return;
}
if ( F_40 ( & V_21 -> V_80 ) )
return;
if ( ! V_21 -> V_81 . V_31 )
goto V_82;
if ( F_41 ( F_33 () , V_21 -> V_81 ) <
F_10 ( V_21 -> V_32 ) ) {
F_31 ( & V_21 -> V_80 ,
F_32 ( V_21 -> V_81 , V_21 -> V_32 ) ,
V_63 ) ;
return;
}
V_82:
F_38 ( V_21 , V_77 ) ;
V_21 -> V_81 = F_33 () ;
}
static void F_42 ( struct V_20 * V_21 , unsigned int V_83 ,
const struct V_1 * V_78 )
{
if ( ! ( V_21 -> V_84 [ V_83 ] . V_52 & V_75 ) ) {
F_39 ( V_21 , & V_21 -> V_84 [ V_83 ] , V_78 ) ;
return;
}
if ( ( F_1 ( & V_21 -> V_39 [ V_83 ] ) & F_1 ( V_78 ) ) !=
( F_1 ( & V_21 -> V_39 [ V_83 ] ) & F_1 ( & V_21 -> V_84 [ V_83 ] ) ) ) {
F_39 ( V_21 , & V_21 -> V_84 [ V_83 ] , V_78 ) ;
return;
}
if ( V_21 -> V_28 & V_29 ) {
if ( V_78 -> V_52 != ( V_21 -> V_84 [ V_83 ] . V_52 &
V_53 ) ) {
F_39 ( V_21 , & V_21 -> V_84 [ V_83 ] ,
V_78 ) ;
return;
}
}
}
static void F_43 ( struct V_20 * V_21 )
{
if ( V_21 -> V_28 & V_85 )
return;
if ( V_21 -> V_30 . V_31 )
F_31 ( & V_21 -> V_62 , V_21 -> V_30 , V_86 ) ;
}
static void F_44 ( unsigned long V_3 )
{
struct V_20 * V_21 = (struct V_20 * ) V_3 ;
struct V_44 V_64 ;
V_64 . V_66 = V_87 ;
V_64 . V_28 = V_21 -> V_28 ;
V_64 . V_61 = V_21 -> V_61 ;
V_64 . V_68 = V_21 -> V_68 ;
V_64 . V_69 = V_21 -> V_69 ;
V_64 . V_26 = V_21 -> V_26 ;
V_64 . V_27 = 0 ;
F_25 ( V_21 , & V_64 , NULL , 0 ) ;
}
static enum V_70 F_45 ( struct V_71 * V_71 )
{
struct V_20 * V_21 = F_36 ( V_71 , struct V_20 , V_62 ) ;
F_46 ( & V_21 -> V_72 ) ;
if ( ( V_21 -> V_28 & V_88 ) && V_21 -> V_84 ) {
memset ( V_21 -> V_84 , 0 , V_21 -> V_27 * V_41 ) ;
}
return V_73 ;
}
static inline int F_47 ( struct V_20 * V_21 , int V_89 ,
unsigned int V_83 )
{
if ( ( V_21 -> V_84 ) && ( V_21 -> V_84 [ V_83 ] . V_52 & V_79 ) ) {
if ( V_89 )
F_38 ( V_21 , & V_21 -> V_84 [ V_83 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_48 ( struct V_20 * V_21 , int V_89 )
{
int V_90 = 0 ;
if ( V_21 -> V_27 > 1 ) {
unsigned int V_91 ;
for ( V_91 = 1 ; V_91 < V_21 -> V_27 ; V_91 ++ )
V_90 += F_47 ( V_21 , V_89 , V_91 ) ;
} else {
V_90 += F_47 ( V_21 , V_89 , 0 ) ;
}
return V_90 ;
}
static void F_49 ( unsigned long V_3 )
{
struct V_20 * V_21 = (struct V_20 * ) V_3 ;
F_48 ( V_21 , 1 ) ;
}
static enum V_70 F_50 ( struct V_71 * V_71 )
{
struct V_20 * V_21 = F_36 ( V_71 , struct V_20 , V_80 ) ;
F_37 ( & V_21 -> V_92 ) ;
if ( F_48 ( V_21 , 0 ) ) {
F_51 ( V_71 , F_33 () , V_21 -> V_32 ) ;
return V_93 ;
} else {
V_21 -> V_81 = F_52 ( 0 , 0 ) ;
return V_73 ;
}
}
static void F_53 ( struct V_36 * V_37 , void * V_3 )
{
struct V_20 * V_21 = (struct V_20 * ) V_3 ;
const struct V_1 * V_94 = (struct V_1 * ) V_37 -> V_3 ;
unsigned int V_91 ;
F_54 ( & V_21 -> V_62 ) ;
if ( V_21 -> V_26 != V_94 -> V_26 )
return;
V_21 -> V_55 = V_37 -> V_54 ;
V_21 -> V_60 = V_37 -> V_10 -> V_8 ;
V_21 -> V_25 ++ ;
if ( V_21 -> V_28 & V_95 ) {
F_15 ( V_21 ) ;
return;
}
if ( V_21 -> V_28 & V_96 ) {
F_39 ( V_21 , & V_21 -> V_84 [ 0 ] , V_94 ) ;
goto V_97;
}
if ( V_21 -> V_27 == 1 ) {
F_42 ( V_21 , 0 , V_94 ) ;
goto V_97;
}
if ( V_21 -> V_27 > 1 ) {
for ( V_91 = 1 ; V_91 < V_21 -> V_27 ; V_91 ++ ) {
if ( ( F_1 ( & V_21 -> V_39 [ 0 ] ) & F_1 ( V_94 ) ) ==
( F_1 ( & V_21 -> V_39 [ 0 ] ) &
F_1 ( & V_21 -> V_39 [ V_91 ] ) ) ) {
F_42 ( V_21 , V_91 , V_94 ) ;
break;
}
}
}
V_97:
F_43 ( V_21 ) ;
}
static struct V_20 * F_55 ( struct V_98 * V_99 , T_2 V_26 ,
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
F_54 ( & V_21 -> V_62 ) ;
F_54 ( & V_21 -> V_80 ) ;
if ( V_21 -> V_72 . V_100 )
F_57 ( & V_21 -> V_72 ) ;
if ( V_21 -> V_92 . V_100 )
F_57 ( & V_21 -> V_92 ) ;
if ( ( V_21 -> V_39 ) && ( V_21 -> V_39 != & V_21 -> V_101 ) )
F_58 ( V_21 -> V_39 ) ;
if ( ( V_21 -> V_84 ) && ( V_21 -> V_84 != & V_21 -> V_102 ) )
F_58 ( V_21 -> V_84 ) ;
F_58 ( V_21 ) ;
}
static void F_59 ( struct V_9 * V_10 , struct V_20 * V_21 )
{
if ( V_21 -> V_103 == V_10 ) {
F_60 ( V_10 , V_21 -> V_26 , F_61 ( V_21 -> V_26 ) ,
F_53 , V_21 ) ;
V_21 -> V_103 = NULL ;
} else
F_62 ( V_104 L_21
L_22 , V_21 -> V_103 , V_10 ) ;
}
static int F_63 ( struct V_98 * V_99 , T_2 V_26 , int V_8 )
{
struct V_20 * V_21 , * V_105 ;
F_64 (op, n, ops, list) {
if ( ( V_21 -> V_26 == V_26 ) && ( V_21 -> V_8 == V_8 ) ) {
if ( V_21 -> V_8 ) {
if ( V_21 -> V_103 ) {
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
F_65 ( & V_21 -> V_106 ) ;
F_56 ( V_21 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_66 ( struct V_98 * V_99 , T_2 V_26 , int V_8 )
{
struct V_20 * V_21 , * V_105 ;
F_64 (op, n, ops, list) {
if ( ( V_21 -> V_26 == V_26 ) && ( V_21 -> V_8 == V_8 ) ) {
F_65 ( & V_21 -> V_106 ) ;
F_56 ( V_21 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_67 ( struct V_98 * V_99 , struct V_44 * V_64 ,
int V_8 )
{
struct V_20 * V_21 = F_55 ( V_99 , V_64 -> V_26 , V_8 ) ;
if ( ! V_21 )
return - V_107 ;
V_64 -> V_28 = V_21 -> V_28 ;
V_64 -> V_61 = V_21 -> V_61 ;
V_64 -> V_68 = V_21 -> V_68 ;
V_64 -> V_69 = V_21 -> V_69 ;
V_64 -> V_27 = V_21 -> V_27 ;
F_25 ( V_21 , V_64 , V_21 -> V_39 , 0 ) ;
return V_108 ;
}
static int F_68 ( struct V_44 * V_64 , struct V_109 * V_110 ,
int V_8 , struct V_5 * V_6 )
{
struct V_4 * V_19 = F_2 ( V_6 ) ;
struct V_20 * V_21 ;
unsigned int V_91 ;
int V_51 ;
if ( ! V_8 )
return - V_111 ;
if ( V_64 -> V_27 < 1 || V_64 -> V_27 > V_112 )
return - V_107 ;
V_21 = F_55 ( & V_19 -> V_113 , V_64 -> V_26 , V_8 ) ;
if ( V_21 ) {
if ( V_64 -> V_27 > V_21 -> V_27 )
return - V_114 ;
for ( V_91 = 0 ; V_91 < V_64 -> V_27 ; V_91 ++ ) {
V_51 = F_69 ( ( V_115 * ) & V_21 -> V_39 [ V_91 ] , V_110 , V_41 ) ;
if ( V_21 -> V_39 [ V_91 ] . V_52 > 8 )
V_51 = - V_107 ;
if ( V_51 < 0 )
return V_51 ;
if ( V_64 -> V_28 & V_116 ) {
V_21 -> V_39 [ V_91 ] . V_26 = V_64 -> V_26 ;
}
}
} else {
V_21 = F_70 ( V_117 , V_118 ) ;
if ( ! V_21 )
return - V_119 ;
V_21 -> V_26 = V_64 -> V_26 ;
if ( V_64 -> V_27 > 1 ) {
V_21 -> V_39 = F_71 ( V_64 -> V_27 * V_41 ,
V_118 ) ;
if ( ! V_21 -> V_39 ) {
F_58 ( V_21 ) ;
return - V_119 ;
}
} else
V_21 -> V_39 = & V_21 -> V_101 ;
for ( V_91 = 0 ; V_91 < V_64 -> V_27 ; V_91 ++ ) {
V_51 = F_69 ( ( V_115 * ) & V_21 -> V_39 [ V_91 ] , V_110 , V_41 ) ;
if ( V_21 -> V_39 [ V_91 ] . V_52 > 8 )
V_51 = - V_107 ;
if ( V_51 < 0 ) {
if ( V_21 -> V_39 != & V_21 -> V_101 )
F_58 ( V_21 -> V_39 ) ;
F_58 ( V_21 ) ;
return V_51 ;
}
if ( V_64 -> V_28 & V_116 ) {
V_21 -> V_39 [ V_91 ] . V_26 = V_64 -> V_26 ;
}
}
V_21 -> V_84 = NULL ;
V_21 -> V_6 = V_6 ;
V_21 -> V_8 = V_8 ;
F_72 ( & V_21 -> V_62 , V_120 , V_86 ) ;
V_21 -> V_62 . V_121 = F_35 ;
F_73 ( & V_21 -> V_72 , F_34 ,
( unsigned long ) V_21 ) ;
F_72 ( & V_21 -> V_80 , V_120 , V_86 ) ;
F_74 ( & V_21 -> V_106 , & V_19 -> V_113 ) ;
}
if ( V_21 -> V_27 != V_64 -> V_27 ) {
V_21 -> V_27 = V_64 -> V_27 ;
V_21 -> V_40 = 0 ;
}
V_21 -> V_28 = V_64 -> V_28 ;
if ( V_21 -> V_28 & V_122 ) {
V_21 -> V_40 = 0 ;
}
if ( V_21 -> V_28 & V_123 ) {
V_21 -> V_61 = V_64 -> V_61 ;
V_21 -> V_68 = V_64 -> V_68 ;
V_21 -> V_69 = V_64 -> V_69 ;
V_21 -> V_30 = F_75 ( V_64 -> V_68 ) ;
V_21 -> V_32 = F_75 ( V_64 -> V_69 ) ;
if ( ! V_21 -> V_30 . V_31 && ! V_21 -> V_32 . V_31 )
F_54 ( & V_21 -> V_62 ) ;
}
if ( V_21 -> V_28 & V_124 ) {
F_54 ( & V_21 -> V_62 ) ;
V_21 -> V_28 |= V_125 ;
}
if ( V_21 -> V_28 & V_125 ) {
F_15 ( V_21 ) ;
if ( V_21 -> V_61 )
V_21 -> V_61 -- ;
}
if ( V_21 -> V_28 & V_124 )
F_30 ( V_21 ) ;
return V_64 -> V_27 * V_41 + V_108 ;
}
static int F_76 ( struct V_44 * V_64 , struct V_109 * V_110 ,
int V_8 , struct V_5 * V_6 )
{
struct V_4 * V_19 = F_2 ( V_6 ) ;
struct V_20 * V_21 ;
int V_126 ;
int V_51 = 0 ;
if ( ( V_64 -> V_28 & V_96 ) || ( ! ( V_64 -> V_27 ) ) ) {
V_64 -> V_28 |= V_96 ;
V_64 -> V_27 = 0 ;
}
if ( V_64 -> V_27 > V_112 + 1 )
return - V_107 ;
if ( ( V_64 -> V_28 & V_95 ) &&
( ( V_64 -> V_27 != 1 ) ||
( ! ( V_64 -> V_26 & V_127 ) ) ) )
return - V_107 ;
V_21 = F_55 ( & V_19 -> V_128 , V_64 -> V_26 , V_8 ) ;
if ( V_21 ) {
if ( V_64 -> V_27 > V_21 -> V_27 )
return - V_114 ;
if ( V_64 -> V_27 ) {
V_51 = F_69 ( ( V_115 * ) V_21 -> V_39 , V_110 ,
V_64 -> V_27 * V_41 ) ;
if ( V_51 < 0 )
return V_51 ;
memset ( V_21 -> V_84 , 0 , V_64 -> V_27 * V_41 ) ;
}
V_21 -> V_27 = V_64 -> V_27 ;
V_126 = 0 ;
} else {
V_21 = F_70 ( V_117 , V_118 ) ;
if ( ! V_21 )
return - V_119 ;
V_21 -> V_26 = V_64 -> V_26 ;
V_21 -> V_27 = V_64 -> V_27 ;
if ( V_64 -> V_27 > 1 ) {
V_21 -> V_39 = F_71 ( V_64 -> V_27 * V_41 ,
V_118 ) ;
if ( ! V_21 -> V_39 ) {
F_58 ( V_21 ) ;
return - V_119 ;
}
V_21 -> V_84 = F_70 ( V_64 -> V_27 * V_41 ,
V_118 ) ;
if ( ! V_21 -> V_84 ) {
F_58 ( V_21 -> V_39 ) ;
F_58 ( V_21 ) ;
return - V_119 ;
}
} else {
V_21 -> V_39 = & V_21 -> V_101 ;
V_21 -> V_84 = & V_21 -> V_102 ;
}
if ( V_64 -> V_27 ) {
V_51 = F_69 ( ( V_115 * ) V_21 -> V_39 , V_110 ,
V_64 -> V_27 * V_41 ) ;
if ( V_51 < 0 ) {
if ( V_21 -> V_39 != & V_21 -> V_101 )
F_58 ( V_21 -> V_39 ) ;
if ( V_21 -> V_84 != & V_21 -> V_102 )
F_58 ( V_21 -> V_84 ) ;
F_58 ( V_21 ) ;
return V_51 ;
}
}
V_21 -> V_6 = V_6 ;
V_21 -> V_8 = V_8 ;
V_21 -> V_60 = V_8 ;
F_72 ( & V_21 -> V_62 , V_120 , V_86 ) ;
V_21 -> V_62 . V_121 = F_45 ;
F_73 ( & V_21 -> V_72 , F_44 ,
( unsigned long ) V_21 ) ;
F_72 ( & V_21 -> V_80 , V_120 , V_86 ) ;
V_21 -> V_80 . V_121 = F_50 ;
F_73 ( & V_21 -> V_92 , F_49 ,
( unsigned long ) V_21 ) ;
F_74 ( & V_21 -> V_106 , & V_19 -> V_128 ) ;
V_126 = 1 ;
}
V_21 -> V_28 = V_64 -> V_28 ;
if ( V_21 -> V_28 & V_95 ) {
F_54 ( & V_21 -> V_80 ) ;
F_54 ( & V_21 -> V_62 ) ;
if ( ( V_21 -> V_28 & V_116 ) ||
( V_21 -> V_39 [ 0 ] . V_26 == V_21 -> V_26 ) )
V_21 -> V_39 [ 0 ] . V_26 = V_21 -> V_26 & ~ V_127 ;
} else {
if ( V_21 -> V_28 & V_123 ) {
V_21 -> V_68 = V_64 -> V_68 ;
V_21 -> V_69 = V_64 -> V_69 ;
V_21 -> V_30 = F_75 ( V_64 -> V_68 ) ;
V_21 -> V_32 = F_75 ( V_64 -> V_69 ) ;
if ( ! V_21 -> V_30 . V_31 )
F_54 ( & V_21 -> V_62 ) ;
V_21 -> V_81 = F_52 ( 0 , 0 ) ;
F_54 ( & V_21 -> V_80 ) ;
F_48 ( V_21 , 1 ) ;
}
if ( ( V_21 -> V_28 & V_124 ) && V_21 -> V_30 . V_31 )
F_31 ( & V_21 -> V_62 , V_21 -> V_30 ,
V_86 ) ;
}
if ( V_126 ) {
if ( V_8 ) {
struct V_9 * V_10 ;
V_10 = F_16 ( & V_11 , V_8 ) ;
if ( V_10 ) {
V_51 = F_77 ( V_10 , V_21 -> V_26 ,
F_61 ( V_21 -> V_26 ) ,
F_53 , V_21 ,
L_23 ) ;
V_21 -> V_103 = V_10 ;
F_24 ( V_10 ) ;
}
} else
V_51 = F_77 ( NULL , V_21 -> V_26 ,
F_61 ( V_21 -> V_26 ) ,
F_53 , V_21 , L_23 ) ;
if ( V_51 ) {
F_65 ( & V_21 -> V_106 ) ;
F_56 ( V_21 ) ;
return V_51 ;
}
}
return V_64 -> V_27 * V_41 + V_108 ;
}
static int F_78 ( struct V_109 * V_110 , int V_8 , struct V_5 * V_6 )
{
struct V_36 * V_37 ;
struct V_9 * V_10 ;
int V_51 ;
if ( ! V_8 )
return - V_111 ;
V_37 = F_17 ( V_41 + sizeof( struct V_42 ) , V_118 ) ;
if ( ! V_37 )
return - V_119 ;
F_19 ( V_37 ) ;
V_51 = F_69 ( F_21 ( V_37 , V_41 ) , V_110 , V_41 ) ;
if ( V_51 < 0 ) {
F_29 ( V_37 ) ;
return V_51 ;
}
V_10 = F_16 ( & V_11 , V_8 ) ;
if ( ! V_10 ) {
F_29 ( V_37 ) ;
return - V_111 ;
}
F_20 ( V_37 ) -> V_8 = V_10 -> V_8 ;
V_37 -> V_10 = V_10 ;
F_22 ( V_37 , V_6 ) ;
V_51 = F_23 ( V_37 , 1 ) ;
F_24 ( V_10 ) ;
if ( V_51 )
return V_51 ;
return V_41 + V_108 ;
}
static int F_79 ( struct V_129 * V_5 , struct V_109 * V_110 , T_3 V_130 )
{
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_4 * V_19 = F_2 ( V_6 ) ;
int V_8 = V_19 -> V_8 ;
struct V_44 V_64 ;
int V_131 ;
if ( ! V_19 -> V_132 )
return - V_133 ;
if ( V_130 < V_108 || ( V_130 - V_108 ) % V_41 )
return - V_107 ;
if ( ! V_8 && V_110 -> V_134 ) {
F_80 ( struct V_48 * , V_49 , V_110 -> V_134 ) ;
if ( V_110 -> V_135 < sizeof( * V_49 ) )
return - V_107 ;
if ( V_49 -> V_57 != V_58 )
return - V_107 ;
V_8 = V_49 -> V_59 ;
if ( V_8 ) {
struct V_9 * V_10 ;
V_10 = F_16 ( & V_11 , V_8 ) ;
if ( ! V_10 )
return - V_111 ;
if ( V_10 -> type != V_136 ) {
F_24 ( V_10 ) ;
return - V_111 ;
}
F_24 ( V_10 ) ;
}
}
V_131 = F_69 ( ( V_115 * ) & V_64 , V_110 , V_108 ) ;
if ( V_131 < 0 )
return V_131 ;
F_81 ( V_6 ) ;
switch ( V_64 . V_66 ) {
case V_137 :
V_131 = F_68 ( & V_64 , V_110 , V_8 , V_6 ) ;
break;
case V_138 :
V_131 = F_76 ( & V_64 , V_110 , V_8 , V_6 ) ;
break;
case V_139 :
if ( F_66 ( & V_19 -> V_113 , V_64 . V_26 , V_8 ) )
V_131 = V_108 ;
else
V_131 = - V_107 ;
break;
case V_140 :
if ( F_63 ( & V_19 -> V_128 , V_64 . V_26 , V_8 ) )
V_131 = V_108 ;
else
V_131 = - V_107 ;
break;
case V_141 :
V_64 . V_66 = V_142 ;
V_131 = F_67 ( & V_19 -> V_113 , & V_64 , V_8 ) ;
break;
case V_143 :
V_64 . V_66 = V_144 ;
V_131 = F_67 ( & V_19 -> V_128 , & V_64 , V_8 ) ;
break;
case V_145 :
if ( ( V_64 . V_27 != 1 ) || ( V_130 != V_41 + V_108 ) )
V_131 = - V_107 ;
else
V_131 = F_78 ( V_110 , V_8 , V_6 ) ;
break;
default:
V_131 = - V_107 ;
break;
}
F_82 ( V_6 ) ;
return V_131 ;
}
static int F_83 ( struct V_146 * V_147 , unsigned long V_110 ,
void * V_148 )
{
struct V_9 * V_10 = F_84 ( V_148 ) ;
struct V_4 * V_19 = F_36 ( V_147 , struct V_4 , V_149 ) ;
struct V_5 * V_6 = & V_19 -> V_6 ;
struct V_20 * V_21 ;
int V_150 = 0 ;
if ( ! F_85 ( F_86 ( V_10 ) , & V_11 ) )
return V_151 ;
if ( V_10 -> type != V_136 )
return V_151 ;
switch ( V_110 ) {
case V_152 :
F_81 ( V_6 ) ;
F_9 (op, &bo->rx_ops, list)
if ( V_21 -> V_103 == V_10 )
F_59 ( V_10 , V_21 ) ;
if ( V_19 -> V_132 && V_19 -> V_8 == V_10 -> V_8 ) {
V_19 -> V_132 = 0 ;
V_19 -> V_8 = 0 ;
V_150 = 1 ;
}
F_82 ( V_6 ) ;
if ( V_150 ) {
V_6 -> V_153 = V_111 ;
if ( ! F_87 ( V_6 , V_154 ) )
V_6 -> V_155 ( V_6 ) ;
}
break;
case V_156 :
if ( V_19 -> V_132 && V_19 -> V_8 == V_10 -> V_8 ) {
V_6 -> V_153 = V_157 ;
if ( ! F_87 ( V_6 , V_154 ) )
V_6 -> V_155 ( V_6 ) ;
}
}
return V_151 ;
}
static int F_88 ( struct V_5 * V_6 )
{
struct V_4 * V_19 = F_2 ( V_6 ) ;
V_19 -> V_132 = 0 ;
V_19 -> V_8 = 0 ;
V_19 -> V_23 = 0 ;
V_19 -> V_158 = NULL ;
F_89 ( & V_19 -> V_113 ) ;
F_89 ( & V_19 -> V_128 ) ;
V_19 -> V_149 . V_159 = F_83 ;
F_90 ( & V_19 -> V_149 ) ;
return 0 ;
}
static int F_91 ( struct V_129 * V_5 )
{
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_4 * V_19 ;
struct V_20 * V_21 , * V_160 ;
if ( V_6 == NULL )
return 0 ;
V_19 = F_2 ( V_6 ) ;
F_92 ( & V_19 -> V_149 ) ;
F_81 ( V_6 ) ;
F_64 (op, next, &bo->tx_ops, list)
F_56 ( V_21 ) ;
F_64 (op, next, &bo->rx_ops, list) {
if ( V_21 -> V_8 ) {
if ( V_21 -> V_103 ) {
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
if ( V_161 && V_19 -> V_158 )
F_93 ( V_19 -> V_162 , V_161 ) ;
if ( V_19 -> V_132 ) {
V_19 -> V_132 = 0 ;
V_19 -> V_8 = 0 ;
}
F_94 ( V_6 ) ;
V_5 -> V_6 = NULL ;
F_82 ( V_6 ) ;
F_95 ( V_6 ) ;
return 0 ;
}
static int F_96 ( struct V_129 * V_5 , struct V_163 * V_164 , int V_165 ,
int V_28 )
{
struct V_48 * V_49 = (struct V_48 * ) V_164 ;
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_4 * V_19 = F_2 ( V_6 ) ;
if ( V_165 < sizeof( * V_49 ) )
return - V_107 ;
if ( V_19 -> V_132 )
return - V_166 ;
if ( V_49 -> V_59 ) {
struct V_9 * V_10 ;
V_10 = F_16 ( & V_11 , V_49 -> V_59 ) ;
if ( ! V_10 )
return - V_111 ;
if ( V_10 -> type != V_136 ) {
F_24 ( V_10 ) ;
return - V_111 ;
}
V_19 -> V_8 = V_10 -> V_8 ;
F_24 ( V_10 ) ;
} else {
V_19 -> V_8 = 0 ;
}
V_19 -> V_132 = 1 ;
if ( V_161 ) {
sprintf ( V_19 -> V_162 , L_24 , F_97 ( V_6 ) ) ;
V_19 -> V_158 = F_98 ( V_19 -> V_162 , 0644 ,
V_161 ,
& V_167 , V_6 ) ;
}
return 0 ;
}
static int F_99 ( struct V_129 * V_5 , struct V_109 * V_110 , T_3 V_130 ,
int V_28 )
{
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_36 * V_37 ;
int error = 0 ;
int V_168 ;
int V_51 ;
V_168 = V_28 & V_169 ;
V_28 &= ~ V_169 ;
V_37 = F_100 ( V_6 , V_28 , V_168 , & error ) ;
if ( ! V_37 )
return error ;
if ( V_37 -> V_165 < V_130 )
V_130 = V_37 -> V_165 ;
V_51 = F_101 ( V_110 , V_37 -> V_3 , V_130 ) ;
if ( V_51 < 0 ) {
F_102 ( V_6 , V_37 ) ;
return V_51 ;
}
F_103 ( V_110 , V_6 , V_37 ) ;
if ( V_110 -> V_134 ) {
F_104 ( sizeof( struct V_48 ) ) ;
V_110 -> V_135 = sizeof( struct V_48 ) ;
memcpy ( V_110 -> V_134 , V_37 -> V_56 , V_110 -> V_135 ) ;
}
F_102 ( V_6 , V_37 ) ;
return V_130 ;
}
static int T_4 F_105 ( void )
{
int V_51 ;
F_106 ( L_25 V_170 L_26 ) ;
V_51 = F_107 ( & V_171 ) ;
if ( V_51 < 0 ) {
F_62 ( V_104 L_27 ) ;
return V_51 ;
}
V_161 = F_108 ( L_28 , V_11 . V_172 ) ;
return 0 ;
}
static void T_5 F_109 ( void )
{
F_110 ( & V_171 ) ;
if ( V_161 )
F_93 ( L_28 , V_11 . V_172 ) ;
}
