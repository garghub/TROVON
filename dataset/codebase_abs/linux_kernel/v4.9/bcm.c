static inline T_1 F_1 ( const struct V_1 * V_2 , int V_3 )
{
return * ( T_1 * ) ( V_2 -> V_4 + V_3 ) ;
}
static inline struct V_5 * F_2 ( const struct V_6 * V_7 )
{
return (struct V_5 * ) V_7 ;
}
static inline T_2 F_3 ( struct V_8 V_9 )
{
return F_4 ( V_9 . V_10 , V_9 . V_11 * V_12 ) ;
}
static char * F_5 ( char * V_13 , int V_14 )
{
struct V_15 * V_16 ;
if ( ! V_14 )
return L_1 ;
F_6 () ;
V_16 = F_7 ( & V_17 , V_14 ) ;
if ( V_16 )
strcpy ( V_13 , V_16 -> V_18 ) ;
else
strcpy ( V_13 , L_2 ) ;
F_8 () ;
return V_13 ;
}
static int F_9 ( struct V_19 * V_20 , void * V_21 )
{
char V_22 [ V_23 ] ;
struct V_6 * V_7 = (struct V_6 * ) V_20 -> V_24 ;
struct V_5 * V_25 = F_2 ( V_7 ) ;
struct V_26 * V_27 ;
F_10 ( V_20 , L_3 , V_7 -> V_28 ) ;
F_10 ( V_20 , L_4 , V_7 ) ;
F_10 ( V_20 , L_5 , V_25 ) ;
F_10 ( V_20 , L_6 , V_25 -> V_29 ) ;
F_10 ( V_20 , L_7 , F_5 ( V_22 , V_25 -> V_14 ) ) ;
F_10 ( V_20 , L_8 ) ;
F_11 (op, &bo->rx_ops, list) {
unsigned long V_30 ;
if ( ! V_27 -> V_31 )
continue;
F_10 ( V_20 , L_9 , V_27 -> V_32 ,
F_5 ( V_22 , V_27 -> V_14 ) ) ;
if ( V_27 -> V_33 & V_34 )
F_10 ( V_20 , L_10 , V_27 -> V_35 ) ;
else
F_10 ( V_20 , L_11 , V_27 -> V_35 ) ;
F_10 ( V_20 , L_12 , ( V_27 -> V_33 & V_36 ) ? 'd' : ' ' ) ;
if ( V_27 -> V_37 . V_38 )
F_10 ( V_20 , L_13 ,
( long long ) F_12 ( V_27 -> V_37 ) ) ;
if ( V_27 -> V_39 . V_38 )
F_10 ( V_20 , L_14 ,
( long long ) F_12 ( V_27 -> V_39 ) ) ;
F_10 ( V_20 , L_15 ,
V_27 -> V_40 , V_27 -> V_31 ) ;
V_30 = 100 - ( V_27 -> V_40 * 100 ) / V_27 -> V_31 ;
F_10 ( V_20 , L_16 ,
( V_30 == 100 ) ? L_17 : L_18 , V_30 ) ;
}
F_11 (op, &bo->tx_ops, list) {
F_10 ( V_20 , L_19 , V_27 -> V_32 ,
F_5 ( V_22 , V_27 -> V_14 ) ) ;
if ( V_27 -> V_33 & V_34 )
F_10 ( V_20 , L_20 , V_27 -> V_35 ) ;
else
F_10 ( V_20 , L_21 , V_27 -> V_35 ) ;
if ( V_27 -> V_37 . V_38 )
F_10 ( V_20 , L_22 ,
( long long ) F_12 ( V_27 -> V_37 ) ) ;
if ( V_27 -> V_39 . V_38 )
F_10 ( V_20 , L_23 ,
( long long ) F_12 ( V_27 -> V_39 ) ) ;
F_10 ( V_20 , L_24 , V_27 -> V_31 ) ;
}
F_13 ( V_20 , '\n' ) ;
return 0 ;
}
static int F_14 ( struct V_41 * V_41 , struct V_42 * V_42 )
{
return F_15 ( V_42 , F_9 , F_16 ( V_41 ) ) ;
}
static void F_17 ( struct V_26 * V_27 )
{
struct V_43 * V_44 ;
struct V_15 * V_16 ;
struct V_1 * V_45 = V_27 -> V_46 + V_27 -> V_47 * V_27 -> V_48 ;
if ( ! V_27 -> V_14 )
return;
V_16 = F_18 ( & V_17 , V_27 -> V_14 ) ;
if ( ! V_16 ) {
return;
}
V_44 = F_19 ( V_27 -> V_47 + sizeof( struct V_49 ) , F_20 () ) ;
if ( ! V_44 )
goto V_50;
F_21 ( V_44 ) ;
F_22 ( V_44 ) -> V_14 = V_16 -> V_14 ;
F_22 ( V_44 ) -> V_51 = 0 ;
memcpy ( F_23 ( V_44 , V_27 -> V_47 ) , V_45 , V_27 -> V_47 ) ;
V_44 -> V_16 = V_16 ;
F_24 ( V_44 , V_27 -> V_7 ) ;
F_25 ( V_44 , 1 ) ;
V_27 -> V_48 ++ ;
V_27 -> V_31 ++ ;
if ( V_27 -> V_48 >= V_27 -> V_35 )
V_27 -> V_48 = 0 ;
V_50:
F_26 ( V_16 ) ;
}
static void F_27 ( struct V_26 * V_27 , struct V_52 * V_53 ,
struct V_1 * V_46 , int V_54 )
{
struct V_43 * V_44 ;
struct V_1 * V_55 ;
struct V_56 * V_57 ;
struct V_6 * V_7 = V_27 -> V_7 ;
unsigned int V_58 = V_53 -> V_35 * V_27 -> V_47 ;
int V_59 ;
V_44 = F_19 ( sizeof( * V_53 ) + V_58 , F_20 () ) ;
if ( ! V_44 )
return;
memcpy ( F_23 ( V_44 , sizeof( * V_53 ) ) , V_53 , sizeof( * V_53 ) ) ;
if ( V_53 -> V_35 ) {
V_55 = (struct V_1 * ) F_28 ( V_44 ) ;
memcpy ( F_23 ( V_44 , V_58 ) , V_46 , V_58 ) ;
if ( V_53 -> V_35 == 1 )
V_55 -> V_33 &= V_60 ;
}
if ( V_54 ) {
V_44 -> V_61 = V_27 -> V_62 ;
}
F_29 ( sizeof( struct V_56 ) ) ;
V_57 = (struct V_56 * ) V_44 -> V_63 ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_57 -> V_64 = V_65 ;
V_57 -> V_66 = V_27 -> V_67 ;
V_59 = F_30 ( V_7 , V_44 ) ;
if ( V_59 < 0 ) {
struct V_5 * V_25 = F_2 ( V_7 ) ;
F_31 ( V_44 ) ;
V_25 -> V_29 ++ ;
}
}
static void F_32 ( struct V_26 * V_27 )
{
if ( V_27 -> V_37 . V_38 && V_27 -> V_68 )
F_33 ( & V_27 -> V_69 ,
F_34 ( F_35 () , V_27 -> V_37 ) ,
V_70 ) ;
else if ( V_27 -> V_39 . V_38 )
F_33 ( & V_27 -> V_69 ,
F_34 ( F_35 () , V_27 -> V_39 ) ,
V_70 ) ;
}
static void F_36 ( unsigned long V_4 )
{
struct V_26 * V_27 = (struct V_26 * ) V_4 ;
struct V_52 V_71 ;
if ( V_27 -> V_37 . V_38 && ( V_27 -> V_68 > 0 ) ) {
V_27 -> V_68 -- ;
if ( ! V_27 -> V_68 && ( V_27 -> V_33 & V_72 ) ) {
V_71 . V_73 = V_74 ;
V_71 . V_33 = V_27 -> V_33 ;
V_71 . V_68 = V_27 -> V_68 ;
V_71 . V_75 = V_27 -> V_75 ;
V_71 . V_76 = V_27 -> V_76 ;
V_71 . V_32 = V_27 -> V_32 ;
V_71 . V_35 = 0 ;
F_27 ( V_27 , & V_71 , NULL , 0 ) ;
}
F_17 ( V_27 ) ;
} else if ( V_27 -> V_39 . V_38 )
F_17 ( V_27 ) ;
F_32 ( V_27 ) ;
}
static enum V_77 F_37 ( struct V_78 * V_78 )
{
struct V_26 * V_27 = F_38 ( V_78 , struct V_26 , V_69 ) ;
F_39 ( & V_27 -> V_79 ) ;
return V_80 ;
}
static void F_40 ( struct V_26 * V_27 , struct V_1 * V_4 )
{
struct V_52 V_53 ;
V_27 -> V_40 ++ ;
if ( V_27 -> V_40 > V_81 / 100 )
V_27 -> V_40 = V_27 -> V_31 = 0 ;
V_4 -> V_33 &= ( V_60 | V_82 ) ;
V_53 . V_73 = V_83 ;
V_53 . V_33 = V_27 -> V_33 ;
V_53 . V_68 = V_27 -> V_68 ;
V_53 . V_75 = V_27 -> V_75 ;
V_53 . V_76 = V_27 -> V_76 ;
V_53 . V_32 = V_27 -> V_32 ;
V_53 . V_35 = 1 ;
F_27 ( V_27 , & V_53 , V_4 , 1 ) ;
}
static void F_41 ( struct V_26 * V_27 ,
struct V_1 * V_84 ,
const struct V_1 * V_85 )
{
memcpy ( V_84 , V_85 , V_27 -> V_47 ) ;
V_84 -> V_33 |= ( V_82 | V_86 ) ;
if ( ! V_27 -> V_39 . V_38 ) {
F_40 ( V_27 , V_84 ) ;
return;
}
if ( F_42 ( & V_27 -> V_87 ) )
return;
if ( ! V_27 -> V_88 . V_38 )
goto V_89;
if ( F_43 ( F_35 () , V_27 -> V_88 ) <
F_12 ( V_27 -> V_39 ) ) {
F_33 ( & V_27 -> V_87 ,
F_34 ( V_27 -> V_88 , V_27 -> V_39 ) ,
V_70 ) ;
return;
}
V_89:
F_40 ( V_27 , V_84 ) ;
V_27 -> V_88 = F_35 () ;
}
static void F_44 ( struct V_26 * V_27 , unsigned int V_90 ,
const struct V_1 * V_85 )
{
struct V_1 * V_45 = V_27 -> V_46 + V_27 -> V_47 * V_90 ;
struct V_1 * V_91 = V_27 -> V_92 + V_27 -> V_47 * V_90 ;
int V_93 ;
if ( ! ( V_91 -> V_33 & V_82 ) ) {
F_41 ( V_27 , V_91 , V_85 ) ;
return;
}
for ( V_93 = 0 ; V_93 < V_85 -> V_94 ; V_93 += 8 ) {
if ( ( F_1 ( V_45 , V_93 ) & F_1 ( V_85 , V_93 ) ) !=
( F_1 ( V_45 , V_93 ) & F_1 ( V_91 , V_93 ) ) ) {
F_41 ( V_27 , V_91 , V_85 ) ;
return;
}
}
if ( V_27 -> V_33 & V_36 ) {
if ( V_85 -> V_94 != V_91 -> V_94 ) {
F_41 ( V_27 , V_91 , V_85 ) ;
return;
}
}
}
static void F_45 ( struct V_26 * V_27 )
{
if ( V_27 -> V_33 & V_95 )
return;
if ( V_27 -> V_37 . V_38 )
F_33 ( & V_27 -> V_69 , V_27 -> V_37 , V_96 ) ;
}
static void F_46 ( unsigned long V_4 )
{
struct V_26 * V_27 = (struct V_26 * ) V_4 ;
struct V_52 V_71 ;
V_71 . V_73 = V_97 ;
V_71 . V_33 = V_27 -> V_33 ;
V_71 . V_68 = V_27 -> V_68 ;
V_71 . V_75 = V_27 -> V_75 ;
V_71 . V_76 = V_27 -> V_76 ;
V_71 . V_32 = V_27 -> V_32 ;
V_71 . V_35 = 0 ;
F_27 ( V_27 , & V_71 , NULL , 0 ) ;
}
static enum V_77 F_47 ( struct V_78 * V_78 )
{
struct V_26 * V_27 = F_38 ( V_78 , struct V_26 , V_69 ) ;
F_48 ( & V_27 -> V_79 ) ;
if ( ( V_27 -> V_33 & V_98 ) && V_27 -> V_92 ) {
memset ( V_27 -> V_92 , 0 , V_27 -> V_35 * V_27 -> V_47 ) ;
}
return V_80 ;
}
static inline int F_49 ( struct V_26 * V_27 , int V_99 ,
unsigned int V_90 )
{
struct V_1 * V_91 = V_27 -> V_92 + V_27 -> V_47 * V_90 ;
if ( ( V_27 -> V_92 ) && ( V_91 -> V_33 & V_86 ) ) {
if ( V_99 )
F_40 ( V_27 , V_91 ) ;
return 1 ;
}
return 0 ;
}
static int F_50 ( struct V_26 * V_27 , int V_99 )
{
int V_100 = 0 ;
if ( V_27 -> V_35 > 1 ) {
unsigned int V_93 ;
for ( V_93 = 1 ; V_93 < V_27 -> V_35 ; V_93 ++ )
V_100 += F_49 ( V_27 , V_99 , V_93 ) ;
} else {
V_100 += F_49 ( V_27 , V_99 , 0 ) ;
}
return V_100 ;
}
static void F_51 ( unsigned long V_4 )
{
struct V_26 * V_27 = (struct V_26 * ) V_4 ;
F_50 ( V_27 , 1 ) ;
}
static enum V_77 F_52 ( struct V_78 * V_78 )
{
struct V_26 * V_27 = F_38 ( V_78 , struct V_26 , V_87 ) ;
F_39 ( & V_27 -> V_101 ) ;
if ( F_50 ( V_27 , 0 ) ) {
F_53 ( V_78 , F_35 () , V_27 -> V_39 ) ;
return V_102 ;
} else {
V_27 -> V_88 = F_4 ( 0 , 0 ) ;
return V_80 ;
}
}
static void F_54 ( struct V_43 * V_44 , void * V_4 )
{
struct V_26 * V_27 = (struct V_26 * ) V_4 ;
const struct V_1 * V_103 = (struct V_1 * ) V_44 -> V_4 ;
unsigned int V_93 ;
if ( V_27 -> V_32 != V_103 -> V_32 )
return;
if ( V_44 -> V_94 != V_27 -> V_47 )
return;
F_55 ( & V_27 -> V_69 ) ;
V_27 -> V_62 = V_44 -> V_61 ;
V_27 -> V_67 = V_44 -> V_16 -> V_14 ;
V_27 -> V_31 ++ ;
if ( V_27 -> V_33 & V_104 ) {
F_17 ( V_27 ) ;
return;
}
if ( V_27 -> V_33 & V_105 ) {
F_41 ( V_27 , V_27 -> V_92 , V_103 ) ;
goto V_106;
}
if ( V_27 -> V_35 == 1 ) {
F_44 ( V_27 , 0 , V_103 ) ;
goto V_106;
}
if ( V_27 -> V_35 > 1 ) {
for ( V_93 = 1 ; V_93 < V_27 -> V_35 ; V_93 ++ ) {
if ( ( F_1 ( V_27 -> V_46 , 0 ) & F_1 ( V_103 , 0 ) ) ==
( F_1 ( V_27 -> V_46 , 0 ) &
F_1 ( V_27 -> V_46 + V_27 -> V_47 * V_93 , 0 ) ) ) {
F_44 ( V_27 , V_93 , V_103 ) ;
break;
}
}
}
V_106:
F_45 ( V_27 ) ;
}
static struct V_26 * F_56 ( struct V_107 * V_108 ,
struct V_52 * V_109 , int V_14 )
{
struct V_26 * V_27 ;
F_11 (op, ops, list) {
if ( ( V_27 -> V_32 == V_109 -> V_32 ) && ( V_27 -> V_14 == V_14 ) &&
( V_27 -> V_33 & V_34 ) == ( V_109 -> V_33 & V_34 ) )
return V_27 ;
}
return NULL ;
}
static void F_57 ( struct V_26 * V_27 )
{
F_55 ( & V_27 -> V_69 ) ;
F_55 ( & V_27 -> V_87 ) ;
if ( V_27 -> V_79 . V_110 )
F_58 ( & V_27 -> V_79 ) ;
if ( V_27 -> V_101 . V_110 )
F_58 ( & V_27 -> V_101 ) ;
if ( ( V_27 -> V_46 ) && ( V_27 -> V_46 != & V_27 -> V_111 ) )
F_59 ( V_27 -> V_46 ) ;
if ( ( V_27 -> V_92 ) && ( V_27 -> V_92 != & V_27 -> V_112 ) )
F_59 ( V_27 -> V_92 ) ;
F_59 ( V_27 ) ;
}
static void F_60 ( struct V_15 * V_16 , struct V_26 * V_27 )
{
if ( V_27 -> V_113 == V_16 ) {
F_61 ( V_16 , V_27 -> V_32 , F_62 ( V_27 -> V_32 ) ,
F_54 , V_27 ) ;
V_27 -> V_113 = NULL ;
} else
F_63 ( V_114 L_25
L_26 , V_27 -> V_113 , V_16 ) ;
}
static int F_64 ( struct V_107 * V_108 , struct V_52 * V_109 ,
int V_14 )
{
struct V_26 * V_27 , * V_115 ;
F_65 (op, n, ops, list) {
if ( ( V_27 -> V_32 == V_109 -> V_32 ) && ( V_27 -> V_14 == V_14 ) &&
( V_27 -> V_33 & V_34 ) == ( V_109 -> V_33 & V_34 ) ) {
if ( V_27 -> V_14 ) {
if ( V_27 -> V_113 ) {
struct V_15 * V_16 ;
V_16 = F_18 ( & V_17 ,
V_27 -> V_14 ) ;
if ( V_16 ) {
F_60 ( V_16 , V_27 ) ;
F_26 ( V_16 ) ;
}
}
} else
F_61 ( NULL , V_27 -> V_32 ,
F_62 ( V_27 -> V_32 ) ,
F_54 , V_27 ) ;
F_66 ( & V_27 -> V_116 ) ;
F_57 ( V_27 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_67 ( struct V_107 * V_108 , struct V_52 * V_109 ,
int V_14 )
{
struct V_26 * V_27 , * V_115 ;
F_65 (op, n, ops, list) {
if ( ( V_27 -> V_32 == V_109 -> V_32 ) && ( V_27 -> V_14 == V_14 ) &&
( V_27 -> V_33 & V_34 ) == ( V_109 -> V_33 & V_34 ) ) {
F_66 ( & V_27 -> V_116 ) ;
F_57 ( V_27 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_68 ( struct V_107 * V_108 , struct V_52 * V_71 ,
int V_14 )
{
struct V_26 * V_27 = F_56 ( V_108 , V_71 , V_14 ) ;
if ( ! V_27 )
return - V_117 ;
V_71 -> V_33 = V_27 -> V_33 ;
V_71 -> V_68 = V_27 -> V_68 ;
V_71 -> V_75 = V_27 -> V_75 ;
V_71 -> V_76 = V_27 -> V_76 ;
V_71 -> V_35 = V_27 -> V_35 ;
F_27 ( V_27 , V_71 , V_27 -> V_46 , 0 ) ;
return V_118 ;
}
static int F_69 ( struct V_52 * V_71 , struct V_119 * V_120 ,
int V_14 , struct V_6 * V_7 )
{
struct V_5 * V_25 = F_2 ( V_7 ) ;
struct V_26 * V_27 ;
struct V_1 * V_45 ;
unsigned int V_93 ;
int V_59 ;
if ( ! V_14 )
return - V_121 ;
if ( V_71 -> V_35 < 1 || V_71 -> V_35 > V_122 )
return - V_117 ;
V_27 = F_56 ( & V_25 -> V_123 , V_71 , V_14 ) ;
if ( V_27 ) {
if ( V_71 -> V_35 > V_27 -> V_35 )
return - V_124 ;
for ( V_93 = 0 ; V_93 < V_71 -> V_35 ; V_93 ++ ) {
V_45 = V_27 -> V_46 + V_27 -> V_47 * V_93 ;
V_59 = F_70 ( ( V_125 * ) V_45 , V_120 , V_27 -> V_47 ) ;
if ( V_27 -> V_33 & V_34 ) {
if ( V_45 -> V_94 > 64 )
V_59 = - V_117 ;
} else {
if ( V_45 -> V_94 > 8 )
V_59 = - V_117 ;
}
if ( V_59 < 0 )
return V_59 ;
if ( V_71 -> V_33 & V_126 ) {
V_45 -> V_32 = V_71 -> V_32 ;
}
}
V_27 -> V_33 = V_71 -> V_33 ;
} else {
V_27 = F_71 ( V_127 , V_128 ) ;
if ( ! V_27 )
return - V_129 ;
V_27 -> V_32 = V_71 -> V_32 ;
V_27 -> V_47 = F_72 ( V_71 -> V_33 ) ;
V_27 -> V_33 = V_71 -> V_33 ;
if ( V_71 -> V_35 > 1 ) {
V_27 -> V_46 = F_73 ( V_71 -> V_35 * V_27 -> V_47 ,
V_128 ) ;
if ( ! V_27 -> V_46 ) {
F_59 ( V_27 ) ;
return - V_129 ;
}
} else
V_27 -> V_46 = & V_27 -> V_111 ;
for ( V_93 = 0 ; V_93 < V_71 -> V_35 ; V_93 ++ ) {
V_45 = V_27 -> V_46 + V_27 -> V_47 * V_93 ;
V_59 = F_70 ( ( V_125 * ) V_45 , V_120 , V_27 -> V_47 ) ;
if ( V_27 -> V_33 & V_34 ) {
if ( V_45 -> V_94 > 64 )
V_59 = - V_117 ;
} else {
if ( V_45 -> V_94 > 8 )
V_59 = - V_117 ;
}
if ( V_59 < 0 ) {
if ( V_27 -> V_46 != & V_27 -> V_111 )
F_59 ( V_27 -> V_46 ) ;
F_59 ( V_27 ) ;
return V_59 ;
}
if ( V_71 -> V_33 & V_126 ) {
V_45 -> V_32 = V_71 -> V_32 ;
}
}
V_27 -> V_92 = NULL ;
V_27 -> V_7 = V_7 ;
V_27 -> V_14 = V_14 ;
F_74 ( & V_27 -> V_69 , V_130 , V_96 ) ;
V_27 -> V_69 . V_131 = F_37 ;
F_75 ( & V_27 -> V_79 , F_36 ,
( unsigned long ) V_27 ) ;
F_74 ( & V_27 -> V_87 , V_130 , V_96 ) ;
F_76 ( & V_27 -> V_116 , & V_25 -> V_123 ) ;
}
if ( V_27 -> V_35 != V_71 -> V_35 ) {
V_27 -> V_35 = V_71 -> V_35 ;
V_27 -> V_48 = 0 ;
}
if ( V_27 -> V_33 & V_132 ) {
V_27 -> V_48 = 0 ;
}
if ( V_27 -> V_33 & V_133 ) {
V_27 -> V_68 = V_71 -> V_68 ;
V_27 -> V_75 = V_71 -> V_75 ;
V_27 -> V_76 = V_71 -> V_76 ;
V_27 -> V_37 = F_3 ( V_71 -> V_75 ) ;
V_27 -> V_39 = F_3 ( V_71 -> V_76 ) ;
if ( ! V_27 -> V_37 . V_38 && ! V_27 -> V_39 . V_38 )
F_55 ( & V_27 -> V_69 ) ;
}
if ( V_27 -> V_33 & V_134 ) {
F_55 ( & V_27 -> V_69 ) ;
V_27 -> V_33 |= V_135 ;
}
if ( V_27 -> V_33 & V_135 ) {
F_17 ( V_27 ) ;
if ( V_27 -> V_68 )
V_27 -> V_68 -- ;
}
if ( V_27 -> V_33 & V_134 )
F_32 ( V_27 ) ;
return V_71 -> V_35 * V_27 -> V_47 + V_118 ;
}
static int F_77 ( struct V_52 * V_71 , struct V_119 * V_120 ,
int V_14 , struct V_6 * V_7 )
{
struct V_5 * V_25 = F_2 ( V_7 ) ;
struct V_26 * V_27 ;
int V_136 ;
int V_59 = 0 ;
if ( ( V_71 -> V_33 & V_105 ) || ( ! ( V_71 -> V_35 ) ) ) {
V_71 -> V_33 |= V_105 ;
V_71 -> V_35 = 0 ;
}
if ( V_71 -> V_35 > V_122 + 1 )
return - V_117 ;
if ( ( V_71 -> V_33 & V_104 ) &&
( ( V_71 -> V_35 != 1 ) ||
( ! ( V_71 -> V_32 & V_137 ) ) ) )
return - V_117 ;
V_27 = F_56 ( & V_25 -> V_138 , V_71 , V_14 ) ;
if ( V_27 ) {
if ( V_71 -> V_35 > V_27 -> V_35 )
return - V_124 ;
if ( V_71 -> V_35 ) {
V_59 = F_70 ( V_27 -> V_46 , V_120 ,
V_71 -> V_35 * V_27 -> V_47 ) ;
if ( V_59 < 0 )
return V_59 ;
memset ( V_27 -> V_92 , 0 , V_71 -> V_35 * V_27 -> V_47 ) ;
}
V_27 -> V_35 = V_71 -> V_35 ;
V_27 -> V_33 = V_71 -> V_33 ;
V_136 = 0 ;
} else {
V_27 = F_71 ( V_127 , V_128 ) ;
if ( ! V_27 )
return - V_129 ;
V_27 -> V_32 = V_71 -> V_32 ;
V_27 -> V_35 = V_71 -> V_35 ;
V_27 -> V_47 = F_72 ( V_71 -> V_33 ) ;
V_27 -> V_33 = V_71 -> V_33 ;
if ( V_71 -> V_35 > 1 ) {
V_27 -> V_46 = F_73 ( V_71 -> V_35 * V_27 -> V_47 ,
V_128 ) ;
if ( ! V_27 -> V_46 ) {
F_59 ( V_27 ) ;
return - V_129 ;
}
V_27 -> V_92 = F_71 ( V_71 -> V_35 * V_27 -> V_47 ,
V_128 ) ;
if ( ! V_27 -> V_92 ) {
F_59 ( V_27 -> V_46 ) ;
F_59 ( V_27 ) ;
return - V_129 ;
}
} else {
V_27 -> V_46 = & V_27 -> V_111 ;
V_27 -> V_92 = & V_27 -> V_112 ;
}
if ( V_71 -> V_35 ) {
V_59 = F_70 ( V_27 -> V_46 , V_120 ,
V_71 -> V_35 * V_27 -> V_47 ) ;
if ( V_59 < 0 ) {
if ( V_27 -> V_46 != & V_27 -> V_111 )
F_59 ( V_27 -> V_46 ) ;
if ( V_27 -> V_92 != & V_27 -> V_112 )
F_59 ( V_27 -> V_92 ) ;
F_59 ( V_27 ) ;
return V_59 ;
}
}
V_27 -> V_7 = V_7 ;
V_27 -> V_14 = V_14 ;
V_27 -> V_67 = V_14 ;
F_74 ( & V_27 -> V_69 , V_130 , V_96 ) ;
V_27 -> V_69 . V_131 = F_47 ;
F_75 ( & V_27 -> V_79 , F_46 ,
( unsigned long ) V_27 ) ;
F_74 ( & V_27 -> V_87 , V_130 , V_96 ) ;
V_27 -> V_87 . V_131 = F_52 ;
F_75 ( & V_27 -> V_101 , F_51 ,
( unsigned long ) V_27 ) ;
F_76 ( & V_27 -> V_116 , & V_25 -> V_138 ) ;
V_136 = 1 ;
}
if ( V_27 -> V_33 & V_104 ) {
struct V_1 * V_139 = V_27 -> V_46 ;
F_55 ( & V_27 -> V_87 ) ;
F_55 ( & V_27 -> V_69 ) ;
if ( ( V_27 -> V_33 & V_126 ) ||
( V_139 -> V_32 == V_27 -> V_32 ) )
V_139 -> V_32 = V_27 -> V_32 & ~ V_137 ;
} else {
if ( V_27 -> V_33 & V_133 ) {
V_27 -> V_75 = V_71 -> V_75 ;
V_27 -> V_76 = V_71 -> V_76 ;
V_27 -> V_37 = F_3 ( V_71 -> V_75 ) ;
V_27 -> V_39 = F_3 ( V_71 -> V_76 ) ;
if ( ! V_27 -> V_37 . V_38 )
F_55 ( & V_27 -> V_69 ) ;
V_27 -> V_88 = F_4 ( 0 , 0 ) ;
F_55 ( & V_27 -> V_87 ) ;
F_50 ( V_27 , 1 ) ;
}
if ( ( V_27 -> V_33 & V_134 ) && V_27 -> V_37 . V_38 )
F_33 ( & V_27 -> V_69 , V_27 -> V_37 ,
V_96 ) ;
}
if ( V_136 ) {
if ( V_14 ) {
struct V_15 * V_16 ;
V_16 = F_18 ( & V_17 , V_14 ) ;
if ( V_16 ) {
V_59 = F_78 ( V_16 , V_27 -> V_32 ,
F_62 ( V_27 -> V_32 ) ,
F_54 , V_27 ,
L_27 ) ;
V_27 -> V_113 = V_16 ;
F_26 ( V_16 ) ;
}
} else
V_59 = F_78 ( NULL , V_27 -> V_32 ,
F_62 ( V_27 -> V_32 ) ,
F_54 , V_27 , L_27 ) ;
if ( V_59 ) {
F_66 ( & V_27 -> V_116 ) ;
F_57 ( V_27 ) ;
return V_59 ;
}
}
return V_71 -> V_35 * V_27 -> V_47 + V_118 ;
}
static int F_79 ( struct V_119 * V_120 , int V_14 , struct V_6 * V_7 ,
int V_47 )
{
struct V_43 * V_44 ;
struct V_15 * V_16 ;
int V_59 ;
if ( ! V_14 )
return - V_121 ;
V_44 = F_19 ( V_47 + sizeof( struct V_49 ) , V_128 ) ;
if ( ! V_44 )
return - V_129 ;
F_21 ( V_44 ) ;
V_59 = F_70 ( F_23 ( V_44 , V_47 ) , V_120 , V_47 ) ;
if ( V_59 < 0 ) {
F_31 ( V_44 ) ;
return V_59 ;
}
V_16 = F_18 ( & V_17 , V_14 ) ;
if ( ! V_16 ) {
F_31 ( V_44 ) ;
return - V_121 ;
}
F_22 ( V_44 ) -> V_14 = V_16 -> V_14 ;
F_22 ( V_44 ) -> V_51 = 0 ;
V_44 -> V_16 = V_16 ;
F_24 ( V_44 , V_7 ) ;
V_59 = F_25 ( V_44 , 1 ) ;
F_26 ( V_16 ) ;
if ( V_59 )
return V_59 ;
return V_47 + V_118 ;
}
static int F_80 ( struct V_140 * V_6 , struct V_119 * V_120 , T_3 V_141 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_5 * V_25 = F_2 ( V_7 ) ;
int V_14 = V_25 -> V_14 ;
struct V_52 V_71 ;
int V_47 ;
int V_142 ;
if ( ! V_25 -> V_143 )
return - V_144 ;
if ( V_141 < V_118 )
return - V_117 ;
V_142 = F_70 ( ( V_125 * ) & V_71 , V_120 , V_118 ) ;
if ( V_142 < 0 )
return V_142 ;
V_47 = F_72 ( V_71 . V_33 ) ;
if ( ( V_141 - V_118 ) % V_47 )
return - V_117 ;
if ( ! V_14 && V_120 -> V_145 ) {
F_81 ( struct V_56 * , V_57 , V_120 -> V_145 ) ;
if ( V_120 -> V_146 < sizeof( * V_57 ) )
return - V_117 ;
if ( V_57 -> V_64 != V_65 )
return - V_117 ;
V_14 = V_57 -> V_66 ;
if ( V_14 ) {
struct V_15 * V_16 ;
V_16 = F_18 ( & V_17 , V_14 ) ;
if ( ! V_16 )
return - V_121 ;
if ( V_16 -> type != V_147 ) {
F_26 ( V_16 ) ;
return - V_121 ;
}
F_26 ( V_16 ) ;
}
}
F_82 ( V_7 ) ;
switch ( V_71 . V_73 ) {
case V_148 :
V_142 = F_69 ( & V_71 , V_120 , V_14 , V_7 ) ;
break;
case V_149 :
V_142 = F_77 ( & V_71 , V_120 , V_14 , V_7 ) ;
break;
case V_150 :
if ( F_67 ( & V_25 -> V_123 , & V_71 , V_14 ) )
V_142 = V_118 ;
else
V_142 = - V_117 ;
break;
case V_151 :
if ( F_64 ( & V_25 -> V_138 , & V_71 , V_14 ) )
V_142 = V_118 ;
else
V_142 = - V_117 ;
break;
case V_152 :
V_71 . V_73 = V_153 ;
V_142 = F_68 ( & V_25 -> V_123 , & V_71 , V_14 ) ;
break;
case V_154 :
V_71 . V_73 = V_155 ;
V_142 = F_68 ( & V_25 -> V_138 , & V_71 , V_14 ) ;
break;
case V_156 :
if ( ( V_71 . V_35 != 1 ) || ( V_141 != V_47 + V_118 ) )
V_142 = - V_117 ;
else
V_142 = F_79 ( V_120 , V_14 , V_7 , V_47 ) ;
break;
default:
V_142 = - V_117 ;
break;
}
F_83 ( V_7 ) ;
return V_142 ;
}
static int F_84 ( struct V_157 * V_158 , unsigned long V_120 ,
void * V_159 )
{
struct V_15 * V_16 = F_85 ( V_159 ) ;
struct V_5 * V_25 = F_38 ( V_158 , struct V_5 , V_160 ) ;
struct V_6 * V_7 = & V_25 -> V_7 ;
struct V_26 * V_27 ;
int V_161 = 0 ;
if ( ! F_86 ( F_87 ( V_16 ) , & V_17 ) )
return V_162 ;
if ( V_16 -> type != V_147 )
return V_162 ;
switch ( V_120 ) {
case V_163 :
F_82 ( V_7 ) ;
F_11 (op, &bo->rx_ops, list)
if ( V_27 -> V_113 == V_16 )
F_60 ( V_16 , V_27 ) ;
if ( V_25 -> V_143 && V_25 -> V_14 == V_16 -> V_14 ) {
V_25 -> V_143 = 0 ;
V_25 -> V_14 = 0 ;
V_161 = 1 ;
}
F_83 ( V_7 ) ;
if ( V_161 ) {
V_7 -> V_164 = V_121 ;
if ( ! F_88 ( V_7 , V_165 ) )
V_7 -> V_166 ( V_7 ) ;
}
break;
case V_167 :
if ( V_25 -> V_143 && V_25 -> V_14 == V_16 -> V_14 ) {
V_7 -> V_164 = V_168 ;
if ( ! F_88 ( V_7 , V_165 ) )
V_7 -> V_166 ( V_7 ) ;
}
}
return V_162 ;
}
static int F_89 ( struct V_6 * V_7 )
{
struct V_5 * V_25 = F_2 ( V_7 ) ;
V_25 -> V_143 = 0 ;
V_25 -> V_14 = 0 ;
V_25 -> V_29 = 0 ;
V_25 -> V_169 = NULL ;
F_90 ( & V_25 -> V_123 ) ;
F_90 ( & V_25 -> V_138 ) ;
V_25 -> V_160 . V_170 = F_84 ;
F_91 ( & V_25 -> V_160 ) ;
return 0 ;
}
static int F_92 ( struct V_140 * V_6 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_5 * V_25 ;
struct V_26 * V_27 , * V_171 ;
if ( V_7 == NULL )
return 0 ;
V_25 = F_2 ( V_7 ) ;
F_93 ( & V_25 -> V_160 ) ;
F_82 ( V_7 ) ;
F_65 (op, next, &bo->tx_ops, list)
F_57 ( V_27 ) ;
F_65 (op, next, &bo->rx_ops, list) {
if ( V_27 -> V_14 ) {
if ( V_27 -> V_113 ) {
struct V_15 * V_16 ;
V_16 = F_18 ( & V_17 , V_27 -> V_14 ) ;
if ( V_16 ) {
F_60 ( V_16 , V_27 ) ;
F_26 ( V_16 ) ;
}
}
} else
F_61 ( NULL , V_27 -> V_32 ,
F_62 ( V_27 -> V_32 ) ,
F_54 , V_27 ) ;
F_57 ( V_27 ) ;
}
if ( V_172 && V_25 -> V_169 )
F_94 ( V_25 -> V_173 , V_172 ) ;
if ( V_25 -> V_143 ) {
V_25 -> V_143 = 0 ;
V_25 -> V_14 = 0 ;
}
F_95 ( V_7 ) ;
V_6 -> V_7 = NULL ;
F_83 ( V_7 ) ;
F_96 ( V_7 ) ;
return 0 ;
}
static int F_97 ( struct V_140 * V_6 , struct V_174 * V_175 , int V_94 ,
int V_33 )
{
struct V_56 * V_57 = (struct V_56 * ) V_175 ;
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_5 * V_25 = F_2 ( V_7 ) ;
int V_142 = 0 ;
if ( V_94 < sizeof( * V_57 ) )
return - V_117 ;
F_82 ( V_7 ) ;
if ( V_25 -> V_143 ) {
V_142 = - V_176 ;
goto V_177;
}
if ( V_57 -> V_66 ) {
struct V_15 * V_16 ;
V_16 = F_18 ( & V_17 , V_57 -> V_66 ) ;
if ( ! V_16 ) {
V_142 = - V_121 ;
goto V_177;
}
if ( V_16 -> type != V_147 ) {
F_26 ( V_16 ) ;
V_142 = - V_121 ;
goto V_177;
}
V_25 -> V_14 = V_16 -> V_14 ;
F_26 ( V_16 ) ;
} else {
V_25 -> V_14 = 0 ;
}
if ( V_172 ) {
sprintf ( V_25 -> V_173 , L_28 , F_98 ( V_7 ) ) ;
V_25 -> V_169 = F_99 ( V_25 -> V_173 , 0644 ,
V_172 ,
& V_178 , V_7 ) ;
if ( ! V_25 -> V_169 ) {
V_142 = - V_129 ;
goto V_177;
}
}
V_25 -> V_143 = 1 ;
V_177:
F_83 ( V_7 ) ;
return V_142 ;
}
static int F_100 ( struct V_140 * V_6 , struct V_119 * V_120 , T_3 V_141 ,
int V_33 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_43 * V_44 ;
int error = 0 ;
int V_179 ;
int V_59 ;
V_179 = V_33 & V_180 ;
V_33 &= ~ V_180 ;
V_44 = F_101 ( V_7 , V_33 , V_179 , & error ) ;
if ( ! V_44 )
return error ;
if ( V_44 -> V_94 < V_141 )
V_141 = V_44 -> V_94 ;
V_59 = F_102 ( V_120 , V_44 -> V_4 , V_141 ) ;
if ( V_59 < 0 ) {
F_103 ( V_7 , V_44 ) ;
return V_59 ;
}
F_104 ( V_120 , V_7 , V_44 ) ;
if ( V_120 -> V_145 ) {
F_105 ( sizeof( struct V_56 ) ) ;
V_120 -> V_146 = sizeof( struct V_56 ) ;
memcpy ( V_120 -> V_145 , V_44 -> V_63 , V_120 -> V_146 ) ;
}
F_103 ( V_7 , V_44 ) ;
return V_141 ;
}
static int T_4 F_106 ( void )
{
int V_59 ;
F_107 ( L_29 V_181 L_30 ) ;
V_59 = F_108 ( & V_182 ) ;
if ( V_59 < 0 ) {
F_63 ( V_114 L_31 ) ;
return V_59 ;
}
V_172 = F_109 ( L_32 , V_17 . V_183 ) ;
return 0 ;
}
static void T_5 F_110 ( void )
{
F_111 ( & V_182 ) ;
if ( V_172 )
F_94 ( L_32 , V_17 . V_183 ) ;
}
