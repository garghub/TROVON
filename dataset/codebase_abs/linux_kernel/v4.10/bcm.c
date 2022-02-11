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
if ( V_27 -> V_37 )
F_10 ( V_20 , L_13 ,
( long long ) F_12 ( V_27 -> V_37 ) ) ;
if ( V_27 -> V_38 )
F_10 ( V_20 , L_14 ,
( long long ) F_12 ( V_27 -> V_38 ) ) ;
F_10 ( V_20 , L_15 ,
V_27 -> V_39 , V_27 -> V_31 ) ;
V_30 = 100 - ( V_27 -> V_39 * 100 ) / V_27 -> V_31 ;
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
if ( V_27 -> V_37 )
F_10 ( V_20 , L_22 ,
( long long ) F_12 ( V_27 -> V_37 ) ) ;
if ( V_27 -> V_38 )
F_10 ( V_20 , L_23 ,
( long long ) F_12 ( V_27 -> V_38 ) ) ;
F_10 ( V_20 , L_24 , V_27 -> V_31 ) ;
}
F_13 ( V_20 , '\n' ) ;
return 0 ;
}
static int F_14 ( struct V_40 * V_40 , struct V_41 * V_41 )
{
return F_15 ( V_41 , F_9 , F_16 ( V_40 ) ) ;
}
static void F_17 ( struct V_26 * V_27 )
{
struct V_42 * V_43 ;
struct V_15 * V_16 ;
struct V_1 * V_44 = V_27 -> V_45 + V_27 -> V_46 * V_27 -> V_47 ;
if ( ! V_27 -> V_14 )
return;
V_16 = F_18 ( & V_17 , V_27 -> V_14 ) ;
if ( ! V_16 ) {
return;
}
V_43 = F_19 ( V_27 -> V_46 + sizeof( struct V_48 ) , F_20 () ) ;
if ( ! V_43 )
goto V_49;
F_21 ( V_43 ) ;
F_22 ( V_43 ) -> V_14 = V_16 -> V_14 ;
F_22 ( V_43 ) -> V_50 = 0 ;
memcpy ( F_23 ( V_43 , V_27 -> V_46 ) , V_44 , V_27 -> V_46 ) ;
V_43 -> V_16 = V_16 ;
F_24 ( V_43 , V_27 -> V_7 ) ;
F_25 ( V_43 , 1 ) ;
V_27 -> V_47 ++ ;
V_27 -> V_31 ++ ;
if ( V_27 -> V_47 >= V_27 -> V_35 )
V_27 -> V_47 = 0 ;
V_49:
F_26 ( V_16 ) ;
}
static void F_27 ( struct V_26 * V_27 , struct V_51 * V_52 ,
struct V_1 * V_45 , int V_53 )
{
struct V_42 * V_43 ;
struct V_1 * V_54 ;
struct V_55 * V_56 ;
struct V_6 * V_7 = V_27 -> V_7 ;
unsigned int V_57 = V_52 -> V_35 * V_27 -> V_46 ;
int V_58 ;
V_43 = F_19 ( sizeof( * V_52 ) + V_57 , F_20 () ) ;
if ( ! V_43 )
return;
memcpy ( F_23 ( V_43 , sizeof( * V_52 ) ) , V_52 , sizeof( * V_52 ) ) ;
if ( V_52 -> V_35 ) {
V_54 = (struct V_1 * ) F_28 ( V_43 ) ;
memcpy ( F_23 ( V_43 , V_57 ) , V_45 , V_57 ) ;
if ( V_52 -> V_35 == 1 )
V_54 -> V_33 &= V_59 ;
}
if ( V_53 ) {
V_43 -> V_60 = V_27 -> V_61 ;
}
F_29 ( sizeof( struct V_55 ) ) ;
V_56 = (struct V_55 * ) V_43 -> V_62 ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_56 -> V_63 = V_64 ;
V_56 -> V_65 = V_27 -> V_66 ;
V_58 = F_30 ( V_7 , V_43 ) ;
if ( V_58 < 0 ) {
struct V_5 * V_25 = F_2 ( V_7 ) ;
F_31 ( V_43 ) ;
V_25 -> V_29 ++ ;
}
}
static void F_32 ( struct V_26 * V_27 )
{
if ( V_27 -> V_37 && V_27 -> V_67 )
F_33 ( & V_27 -> V_68 ,
F_34 ( F_35 () , V_27 -> V_37 ) ,
V_69 ) ;
else if ( V_27 -> V_38 )
F_33 ( & V_27 -> V_68 ,
F_34 ( F_35 () , V_27 -> V_38 ) ,
V_69 ) ;
}
static void F_36 ( unsigned long V_4 )
{
struct V_26 * V_27 = (struct V_26 * ) V_4 ;
struct V_51 V_70 ;
if ( V_27 -> V_37 && ( V_27 -> V_67 > 0 ) ) {
V_27 -> V_67 -- ;
if ( ! V_27 -> V_67 && ( V_27 -> V_33 & V_71 ) ) {
V_70 . V_72 = V_73 ;
V_70 . V_33 = V_27 -> V_33 ;
V_70 . V_67 = V_27 -> V_67 ;
V_70 . V_74 = V_27 -> V_74 ;
V_70 . V_75 = V_27 -> V_75 ;
V_70 . V_32 = V_27 -> V_32 ;
V_70 . V_35 = 0 ;
F_27 ( V_27 , & V_70 , NULL , 0 ) ;
}
F_17 ( V_27 ) ;
} else if ( V_27 -> V_38 )
F_17 ( V_27 ) ;
F_32 ( V_27 ) ;
}
static enum V_76 F_37 ( struct V_77 * V_77 )
{
struct V_26 * V_27 = F_38 ( V_77 , struct V_26 , V_68 ) ;
F_39 ( & V_27 -> V_78 ) ;
return V_79 ;
}
static void F_40 ( struct V_26 * V_27 , struct V_1 * V_4 )
{
struct V_51 V_52 ;
V_27 -> V_39 ++ ;
if ( V_27 -> V_39 > V_80 / 100 )
V_27 -> V_39 = V_27 -> V_31 = 0 ;
V_4 -> V_33 &= ( V_59 | V_81 ) ;
V_52 . V_72 = V_82 ;
V_52 . V_33 = V_27 -> V_33 ;
V_52 . V_67 = V_27 -> V_67 ;
V_52 . V_74 = V_27 -> V_74 ;
V_52 . V_75 = V_27 -> V_75 ;
V_52 . V_32 = V_27 -> V_32 ;
V_52 . V_35 = 1 ;
F_27 ( V_27 , & V_52 , V_4 , 1 ) ;
}
static void F_41 ( struct V_26 * V_27 ,
struct V_1 * V_83 ,
const struct V_1 * V_84 )
{
memcpy ( V_83 , V_84 , V_27 -> V_46 ) ;
V_83 -> V_33 |= ( V_81 | V_85 ) ;
if ( ! V_27 -> V_38 ) {
F_40 ( V_27 , V_83 ) ;
return;
}
if ( F_42 ( & V_27 -> V_86 ) )
return;
if ( ! V_27 -> V_87 )
goto V_88;
if ( F_43 ( F_35 () , V_27 -> V_87 ) <
F_12 ( V_27 -> V_38 ) ) {
F_33 ( & V_27 -> V_86 ,
F_34 ( V_27 -> V_87 , V_27 -> V_38 ) ,
V_69 ) ;
return;
}
V_88:
F_40 ( V_27 , V_83 ) ;
V_27 -> V_87 = F_35 () ;
}
static void F_44 ( struct V_26 * V_27 , unsigned int V_89 ,
const struct V_1 * V_84 )
{
struct V_1 * V_44 = V_27 -> V_45 + V_27 -> V_46 * V_89 ;
struct V_1 * V_90 = V_27 -> V_91 + V_27 -> V_46 * V_89 ;
int V_92 ;
if ( ! ( V_90 -> V_33 & V_81 ) ) {
F_41 ( V_27 , V_90 , V_84 ) ;
return;
}
for ( V_92 = 0 ; V_92 < V_84 -> V_93 ; V_92 += 8 ) {
if ( ( F_1 ( V_44 , V_92 ) & F_1 ( V_84 , V_92 ) ) !=
( F_1 ( V_44 , V_92 ) & F_1 ( V_90 , V_92 ) ) ) {
F_41 ( V_27 , V_90 , V_84 ) ;
return;
}
}
if ( V_27 -> V_33 & V_36 ) {
if ( V_84 -> V_93 != V_90 -> V_93 ) {
F_41 ( V_27 , V_90 , V_84 ) ;
return;
}
}
}
static void F_45 ( struct V_26 * V_27 )
{
if ( V_27 -> V_33 & V_94 )
return;
if ( V_27 -> V_37 )
F_33 ( & V_27 -> V_68 , V_27 -> V_37 , V_95 ) ;
}
static void F_46 ( unsigned long V_4 )
{
struct V_26 * V_27 = (struct V_26 * ) V_4 ;
struct V_51 V_70 ;
V_70 . V_72 = V_96 ;
V_70 . V_33 = V_27 -> V_33 ;
V_70 . V_67 = V_27 -> V_67 ;
V_70 . V_74 = V_27 -> V_74 ;
V_70 . V_75 = V_27 -> V_75 ;
V_70 . V_32 = V_27 -> V_32 ;
V_70 . V_35 = 0 ;
F_27 ( V_27 , & V_70 , NULL , 0 ) ;
}
static enum V_76 F_47 ( struct V_77 * V_77 )
{
struct V_26 * V_27 = F_38 ( V_77 , struct V_26 , V_68 ) ;
F_48 ( & V_27 -> V_78 ) ;
if ( ( V_27 -> V_33 & V_97 ) && V_27 -> V_91 ) {
memset ( V_27 -> V_91 , 0 , V_27 -> V_35 * V_27 -> V_46 ) ;
}
return V_79 ;
}
static inline int F_49 ( struct V_26 * V_27 , int V_98 ,
unsigned int V_89 )
{
struct V_1 * V_90 = V_27 -> V_91 + V_27 -> V_46 * V_89 ;
if ( ( V_27 -> V_91 ) && ( V_90 -> V_33 & V_85 ) ) {
if ( V_98 )
F_40 ( V_27 , V_90 ) ;
return 1 ;
}
return 0 ;
}
static int F_50 ( struct V_26 * V_27 , int V_98 )
{
int V_99 = 0 ;
if ( V_27 -> V_35 > 1 ) {
unsigned int V_92 ;
for ( V_92 = 1 ; V_92 < V_27 -> V_35 ; V_92 ++ )
V_99 += F_49 ( V_27 , V_98 , V_92 ) ;
} else {
V_99 += F_49 ( V_27 , V_98 , 0 ) ;
}
return V_99 ;
}
static void F_51 ( unsigned long V_4 )
{
struct V_26 * V_27 = (struct V_26 * ) V_4 ;
F_50 ( V_27 , 1 ) ;
}
static enum V_76 F_52 ( struct V_77 * V_77 )
{
struct V_26 * V_27 = F_38 ( V_77 , struct V_26 , V_86 ) ;
F_39 ( & V_27 -> V_100 ) ;
if ( F_50 ( V_27 , 0 ) ) {
F_53 ( V_77 , F_35 () , V_27 -> V_38 ) ;
return V_101 ;
} else {
V_27 -> V_87 = 0 ;
return V_79 ;
}
}
static void F_54 ( struct V_42 * V_43 , void * V_4 )
{
struct V_26 * V_27 = (struct V_26 * ) V_4 ;
const struct V_1 * V_102 = (struct V_1 * ) V_43 -> V_4 ;
unsigned int V_92 ;
if ( V_27 -> V_32 != V_102 -> V_32 )
return;
if ( V_43 -> V_93 != V_27 -> V_46 )
return;
F_55 ( & V_27 -> V_68 ) ;
V_27 -> V_61 = V_43 -> V_60 ;
V_27 -> V_66 = V_43 -> V_16 -> V_14 ;
V_27 -> V_31 ++ ;
if ( V_27 -> V_33 & V_103 ) {
F_17 ( V_27 ) ;
return;
}
if ( V_27 -> V_33 & V_104 ) {
F_41 ( V_27 , V_27 -> V_91 , V_102 ) ;
goto V_105;
}
if ( V_27 -> V_35 == 1 ) {
F_44 ( V_27 , 0 , V_102 ) ;
goto V_105;
}
if ( V_27 -> V_35 > 1 ) {
for ( V_92 = 1 ; V_92 < V_27 -> V_35 ; V_92 ++ ) {
if ( ( F_1 ( V_27 -> V_45 , 0 ) & F_1 ( V_102 , 0 ) ) ==
( F_1 ( V_27 -> V_45 , 0 ) &
F_1 ( V_27 -> V_45 + V_27 -> V_46 * V_92 , 0 ) ) ) {
F_44 ( V_27 , V_92 , V_102 ) ;
break;
}
}
}
V_105:
F_45 ( V_27 ) ;
}
static struct V_26 * F_56 ( struct V_106 * V_107 ,
struct V_51 * V_108 , int V_14 )
{
struct V_26 * V_27 ;
F_11 (op, ops, list) {
if ( ( V_27 -> V_32 == V_108 -> V_32 ) && ( V_27 -> V_14 == V_14 ) &&
( V_27 -> V_33 & V_34 ) == ( V_108 -> V_33 & V_34 ) )
return V_27 ;
}
return NULL ;
}
static void F_57 ( struct V_26 * V_27 )
{
if ( V_27 -> V_78 . V_109 ) {
while ( F_58 ( V_110 , & V_27 -> V_78 . V_111 ) ||
F_58 ( V_112 , & V_27 -> V_78 . V_111 ) ||
F_42 ( & V_27 -> V_68 ) ) {
F_55 ( & V_27 -> V_68 ) ;
F_59 ( & V_27 -> V_78 ) ;
}
}
if ( V_27 -> V_100 . V_109 ) {
while ( F_58 ( V_110 , & V_27 -> V_100 . V_111 ) ||
F_58 ( V_112 , & V_27 -> V_100 . V_111 ) ||
F_42 ( & V_27 -> V_86 ) ) {
F_55 ( & V_27 -> V_86 ) ;
F_59 ( & V_27 -> V_100 ) ;
}
}
if ( ( V_27 -> V_45 ) && ( V_27 -> V_45 != & V_27 -> V_113 ) )
F_60 ( V_27 -> V_45 ) ;
if ( ( V_27 -> V_91 ) && ( V_27 -> V_91 != & V_27 -> V_114 ) )
F_60 ( V_27 -> V_91 ) ;
F_60 ( V_27 ) ;
}
static void F_61 ( struct V_15 * V_16 , struct V_26 * V_27 )
{
if ( V_27 -> V_115 == V_16 ) {
F_62 ( V_16 , V_27 -> V_32 , F_63 ( V_27 -> V_32 ) ,
F_54 , V_27 ) ;
V_27 -> V_115 = NULL ;
} else
F_64 ( V_116 L_25
L_26 , V_27 -> V_115 , V_16 ) ;
}
static int F_65 ( struct V_106 * V_107 , struct V_51 * V_108 ,
int V_14 )
{
struct V_26 * V_27 , * V_117 ;
F_66 (op, n, ops, list) {
if ( ( V_27 -> V_32 == V_108 -> V_32 ) && ( V_27 -> V_14 == V_14 ) &&
( V_27 -> V_33 & V_34 ) == ( V_108 -> V_33 & V_34 ) ) {
if ( V_27 -> V_14 ) {
if ( V_27 -> V_115 ) {
struct V_15 * V_16 ;
V_16 = F_18 ( & V_17 ,
V_27 -> V_14 ) ;
if ( V_16 ) {
F_61 ( V_16 , V_27 ) ;
F_26 ( V_16 ) ;
}
}
} else
F_62 ( NULL , V_27 -> V_32 ,
F_63 ( V_27 -> V_32 ) ,
F_54 , V_27 ) ;
F_67 ( & V_27 -> V_118 ) ;
F_57 ( V_27 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_68 ( struct V_106 * V_107 , struct V_51 * V_108 ,
int V_14 )
{
struct V_26 * V_27 , * V_117 ;
F_66 (op, n, ops, list) {
if ( ( V_27 -> V_32 == V_108 -> V_32 ) && ( V_27 -> V_14 == V_14 ) &&
( V_27 -> V_33 & V_34 ) == ( V_108 -> V_33 & V_34 ) ) {
F_67 ( & V_27 -> V_118 ) ;
F_57 ( V_27 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_69 ( struct V_106 * V_107 , struct V_51 * V_70 ,
int V_14 )
{
struct V_26 * V_27 = F_56 ( V_107 , V_70 , V_14 ) ;
if ( ! V_27 )
return - V_119 ;
V_70 -> V_33 = V_27 -> V_33 ;
V_70 -> V_67 = V_27 -> V_67 ;
V_70 -> V_74 = V_27 -> V_74 ;
V_70 -> V_75 = V_27 -> V_75 ;
V_70 -> V_35 = V_27 -> V_35 ;
F_27 ( V_27 , V_70 , V_27 -> V_45 , 0 ) ;
return V_120 ;
}
static int F_70 ( struct V_51 * V_70 , struct V_121 * V_122 ,
int V_14 , struct V_6 * V_7 )
{
struct V_5 * V_25 = F_2 ( V_7 ) ;
struct V_26 * V_27 ;
struct V_1 * V_44 ;
unsigned int V_92 ;
int V_58 ;
if ( ! V_14 )
return - V_123 ;
if ( V_70 -> V_35 < 1 || V_70 -> V_35 > V_124 )
return - V_119 ;
V_27 = F_56 ( & V_25 -> V_125 , V_70 , V_14 ) ;
if ( V_27 ) {
if ( V_70 -> V_35 > V_27 -> V_35 )
return - V_126 ;
for ( V_92 = 0 ; V_92 < V_70 -> V_35 ; V_92 ++ ) {
V_44 = V_27 -> V_45 + V_27 -> V_46 * V_92 ;
V_58 = F_71 ( ( V_127 * ) V_44 , V_122 , V_27 -> V_46 ) ;
if ( V_27 -> V_33 & V_34 ) {
if ( V_44 -> V_93 > 64 )
V_58 = - V_119 ;
} else {
if ( V_44 -> V_93 > 8 )
V_58 = - V_119 ;
}
if ( V_58 < 0 )
return V_58 ;
if ( V_70 -> V_33 & V_128 ) {
V_44 -> V_32 = V_70 -> V_32 ;
}
}
V_27 -> V_33 = V_70 -> V_33 ;
} else {
V_27 = F_72 ( V_129 , V_130 ) ;
if ( ! V_27 )
return - V_131 ;
V_27 -> V_32 = V_70 -> V_32 ;
V_27 -> V_46 = F_73 ( V_70 -> V_33 ) ;
V_27 -> V_33 = V_70 -> V_33 ;
if ( V_70 -> V_35 > 1 ) {
V_27 -> V_45 = F_74 ( V_70 -> V_35 * V_27 -> V_46 ,
V_130 ) ;
if ( ! V_27 -> V_45 ) {
F_60 ( V_27 ) ;
return - V_131 ;
}
} else
V_27 -> V_45 = & V_27 -> V_113 ;
for ( V_92 = 0 ; V_92 < V_70 -> V_35 ; V_92 ++ ) {
V_44 = V_27 -> V_45 + V_27 -> V_46 * V_92 ;
V_58 = F_71 ( ( V_127 * ) V_44 , V_122 , V_27 -> V_46 ) ;
if ( V_27 -> V_33 & V_34 ) {
if ( V_44 -> V_93 > 64 )
V_58 = - V_119 ;
} else {
if ( V_44 -> V_93 > 8 )
V_58 = - V_119 ;
}
if ( V_58 < 0 ) {
if ( V_27 -> V_45 != & V_27 -> V_113 )
F_60 ( V_27 -> V_45 ) ;
F_60 ( V_27 ) ;
return V_58 ;
}
if ( V_70 -> V_33 & V_128 ) {
V_44 -> V_32 = V_70 -> V_32 ;
}
}
V_27 -> V_91 = NULL ;
V_27 -> V_7 = V_7 ;
V_27 -> V_14 = V_14 ;
F_75 ( & V_27 -> V_68 , V_132 , V_95 ) ;
V_27 -> V_68 . V_133 = F_37 ;
F_76 ( & V_27 -> V_78 , F_36 ,
( unsigned long ) V_27 ) ;
F_75 ( & V_27 -> V_86 , V_132 , V_95 ) ;
F_77 ( & V_27 -> V_118 , & V_25 -> V_125 ) ;
}
if ( V_27 -> V_35 != V_70 -> V_35 ) {
V_27 -> V_35 = V_70 -> V_35 ;
V_27 -> V_47 = 0 ;
}
if ( V_27 -> V_33 & V_134 ) {
V_27 -> V_47 = 0 ;
}
if ( V_27 -> V_33 & V_135 ) {
V_27 -> V_67 = V_70 -> V_67 ;
V_27 -> V_74 = V_70 -> V_74 ;
V_27 -> V_75 = V_70 -> V_75 ;
V_27 -> V_37 = F_3 ( V_70 -> V_74 ) ;
V_27 -> V_38 = F_3 ( V_70 -> V_75 ) ;
if ( ! V_27 -> V_37 && ! V_27 -> V_38 )
F_55 ( & V_27 -> V_68 ) ;
}
if ( V_27 -> V_33 & V_136 ) {
F_55 ( & V_27 -> V_68 ) ;
V_27 -> V_33 |= V_137 ;
}
if ( V_27 -> V_33 & V_137 ) {
F_17 ( V_27 ) ;
if ( V_27 -> V_67 )
V_27 -> V_67 -- ;
}
if ( V_27 -> V_33 & V_136 )
F_32 ( V_27 ) ;
return V_70 -> V_35 * V_27 -> V_46 + V_120 ;
}
static int F_78 ( struct V_51 * V_70 , struct V_121 * V_122 ,
int V_14 , struct V_6 * V_7 )
{
struct V_5 * V_25 = F_2 ( V_7 ) ;
struct V_26 * V_27 ;
int V_138 ;
int V_58 = 0 ;
if ( ( V_70 -> V_33 & V_104 ) || ( ! ( V_70 -> V_35 ) ) ) {
V_70 -> V_33 |= V_104 ;
V_70 -> V_35 = 0 ;
}
if ( V_70 -> V_35 > V_124 + 1 )
return - V_119 ;
if ( ( V_70 -> V_33 & V_103 ) &&
( ( V_70 -> V_35 != 1 ) ||
( ! ( V_70 -> V_32 & V_139 ) ) ) )
return - V_119 ;
V_27 = F_56 ( & V_25 -> V_140 , V_70 , V_14 ) ;
if ( V_27 ) {
if ( V_70 -> V_35 > V_27 -> V_35 )
return - V_126 ;
if ( V_70 -> V_35 ) {
V_58 = F_71 ( V_27 -> V_45 , V_122 ,
V_70 -> V_35 * V_27 -> V_46 ) ;
if ( V_58 < 0 )
return V_58 ;
memset ( V_27 -> V_91 , 0 , V_70 -> V_35 * V_27 -> V_46 ) ;
}
V_27 -> V_35 = V_70 -> V_35 ;
V_27 -> V_33 = V_70 -> V_33 ;
V_138 = 0 ;
} else {
V_27 = F_72 ( V_129 , V_130 ) ;
if ( ! V_27 )
return - V_131 ;
V_27 -> V_32 = V_70 -> V_32 ;
V_27 -> V_35 = V_70 -> V_35 ;
V_27 -> V_46 = F_73 ( V_70 -> V_33 ) ;
V_27 -> V_33 = V_70 -> V_33 ;
if ( V_70 -> V_35 > 1 ) {
V_27 -> V_45 = F_74 ( V_70 -> V_35 * V_27 -> V_46 ,
V_130 ) ;
if ( ! V_27 -> V_45 ) {
F_60 ( V_27 ) ;
return - V_131 ;
}
V_27 -> V_91 = F_72 ( V_70 -> V_35 * V_27 -> V_46 ,
V_130 ) ;
if ( ! V_27 -> V_91 ) {
F_60 ( V_27 -> V_45 ) ;
F_60 ( V_27 ) ;
return - V_131 ;
}
} else {
V_27 -> V_45 = & V_27 -> V_113 ;
V_27 -> V_91 = & V_27 -> V_114 ;
}
if ( V_70 -> V_35 ) {
V_58 = F_71 ( V_27 -> V_45 , V_122 ,
V_70 -> V_35 * V_27 -> V_46 ) ;
if ( V_58 < 0 ) {
if ( V_27 -> V_45 != & V_27 -> V_113 )
F_60 ( V_27 -> V_45 ) ;
if ( V_27 -> V_91 != & V_27 -> V_114 )
F_60 ( V_27 -> V_91 ) ;
F_60 ( V_27 ) ;
return V_58 ;
}
}
V_27 -> V_7 = V_7 ;
V_27 -> V_14 = V_14 ;
V_27 -> V_66 = V_14 ;
F_75 ( & V_27 -> V_68 , V_132 , V_95 ) ;
V_27 -> V_68 . V_133 = F_47 ;
F_76 ( & V_27 -> V_78 , F_46 ,
( unsigned long ) V_27 ) ;
F_75 ( & V_27 -> V_86 , V_132 , V_95 ) ;
V_27 -> V_86 . V_133 = F_52 ;
F_76 ( & V_27 -> V_100 , F_51 ,
( unsigned long ) V_27 ) ;
F_77 ( & V_27 -> V_118 , & V_25 -> V_140 ) ;
V_138 = 1 ;
}
if ( V_27 -> V_33 & V_103 ) {
struct V_1 * V_141 = V_27 -> V_45 ;
F_55 ( & V_27 -> V_86 ) ;
F_55 ( & V_27 -> V_68 ) ;
if ( ( V_27 -> V_33 & V_128 ) ||
( V_141 -> V_32 == V_27 -> V_32 ) )
V_141 -> V_32 = V_27 -> V_32 & ~ V_139 ;
} else {
if ( V_27 -> V_33 & V_135 ) {
V_27 -> V_74 = V_70 -> V_74 ;
V_27 -> V_75 = V_70 -> V_75 ;
V_27 -> V_37 = F_3 ( V_70 -> V_74 ) ;
V_27 -> V_38 = F_3 ( V_70 -> V_75 ) ;
if ( ! V_27 -> V_37 )
F_55 ( & V_27 -> V_68 ) ;
V_27 -> V_87 = 0 ;
F_55 ( & V_27 -> V_86 ) ;
F_50 ( V_27 , 1 ) ;
}
if ( ( V_27 -> V_33 & V_136 ) && V_27 -> V_37 )
F_33 ( & V_27 -> V_68 , V_27 -> V_37 ,
V_95 ) ;
}
if ( V_138 ) {
if ( V_14 ) {
struct V_15 * V_16 ;
V_16 = F_18 ( & V_17 , V_14 ) ;
if ( V_16 ) {
V_58 = F_79 ( V_16 , V_27 -> V_32 ,
F_63 ( V_27 -> V_32 ) ,
F_54 , V_27 ,
L_27 , V_7 ) ;
V_27 -> V_115 = V_16 ;
F_26 ( V_16 ) ;
}
} else
V_58 = F_79 ( NULL , V_27 -> V_32 ,
F_63 ( V_27 -> V_32 ) ,
F_54 , V_27 , L_27 , V_7 ) ;
if ( V_58 ) {
F_67 ( & V_27 -> V_118 ) ;
F_57 ( V_27 ) ;
return V_58 ;
}
}
return V_70 -> V_35 * V_27 -> V_46 + V_120 ;
}
static int F_80 ( struct V_121 * V_122 , int V_14 , struct V_6 * V_7 ,
int V_46 )
{
struct V_42 * V_43 ;
struct V_15 * V_16 ;
int V_58 ;
if ( ! V_14 )
return - V_123 ;
V_43 = F_19 ( V_46 + sizeof( struct V_48 ) , V_130 ) ;
if ( ! V_43 )
return - V_131 ;
F_21 ( V_43 ) ;
V_58 = F_71 ( F_23 ( V_43 , V_46 ) , V_122 , V_46 ) ;
if ( V_58 < 0 ) {
F_31 ( V_43 ) ;
return V_58 ;
}
V_16 = F_18 ( & V_17 , V_14 ) ;
if ( ! V_16 ) {
F_31 ( V_43 ) ;
return - V_123 ;
}
F_22 ( V_43 ) -> V_14 = V_16 -> V_14 ;
F_22 ( V_43 ) -> V_50 = 0 ;
V_43 -> V_16 = V_16 ;
F_24 ( V_43 , V_7 ) ;
V_58 = F_25 ( V_43 , 1 ) ;
F_26 ( V_16 ) ;
if ( V_58 )
return V_58 ;
return V_46 + V_120 ;
}
static int F_81 ( struct V_142 * V_6 , struct V_121 * V_122 , T_3 V_143 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_5 * V_25 = F_2 ( V_7 ) ;
int V_14 = V_25 -> V_14 ;
struct V_51 V_70 ;
int V_46 ;
int V_144 ;
if ( ! V_25 -> V_145 )
return - V_146 ;
if ( V_143 < V_120 )
return - V_119 ;
V_144 = F_71 ( ( V_127 * ) & V_70 , V_122 , V_120 ) ;
if ( V_144 < 0 )
return V_144 ;
V_46 = F_73 ( V_70 . V_33 ) ;
if ( ( V_143 - V_120 ) % V_46 )
return - V_119 ;
if ( ! V_14 && V_122 -> V_147 ) {
F_82 ( struct V_55 * , V_56 , V_122 -> V_147 ) ;
if ( V_122 -> V_148 < sizeof( * V_56 ) )
return - V_119 ;
if ( V_56 -> V_63 != V_64 )
return - V_119 ;
V_14 = V_56 -> V_65 ;
if ( V_14 ) {
struct V_15 * V_16 ;
V_16 = F_18 ( & V_17 , V_14 ) ;
if ( ! V_16 )
return - V_123 ;
if ( V_16 -> type != V_149 ) {
F_26 ( V_16 ) ;
return - V_123 ;
}
F_26 ( V_16 ) ;
}
}
F_83 ( V_7 ) ;
switch ( V_70 . V_72 ) {
case V_150 :
V_144 = F_70 ( & V_70 , V_122 , V_14 , V_7 ) ;
break;
case V_151 :
V_144 = F_78 ( & V_70 , V_122 , V_14 , V_7 ) ;
break;
case V_152 :
if ( F_68 ( & V_25 -> V_125 , & V_70 , V_14 ) )
V_144 = V_120 ;
else
V_144 = - V_119 ;
break;
case V_153 :
if ( F_65 ( & V_25 -> V_140 , & V_70 , V_14 ) )
V_144 = V_120 ;
else
V_144 = - V_119 ;
break;
case V_154 :
V_70 . V_72 = V_155 ;
V_144 = F_69 ( & V_25 -> V_125 , & V_70 , V_14 ) ;
break;
case V_156 :
V_70 . V_72 = V_157 ;
V_144 = F_69 ( & V_25 -> V_140 , & V_70 , V_14 ) ;
break;
case V_158 :
if ( ( V_70 . V_35 != 1 ) || ( V_143 != V_46 + V_120 ) )
V_144 = - V_119 ;
else
V_144 = F_80 ( V_122 , V_14 , V_7 , V_46 ) ;
break;
default:
V_144 = - V_119 ;
break;
}
F_84 ( V_7 ) ;
return V_144 ;
}
static int F_85 ( struct V_159 * V_160 , unsigned long V_122 ,
void * V_161 )
{
struct V_15 * V_16 = F_86 ( V_161 ) ;
struct V_5 * V_25 = F_38 ( V_160 , struct V_5 , V_162 ) ;
struct V_6 * V_7 = & V_25 -> V_7 ;
struct V_26 * V_27 ;
int V_163 = 0 ;
if ( ! F_87 ( F_88 ( V_16 ) , & V_17 ) )
return V_164 ;
if ( V_16 -> type != V_149 )
return V_164 ;
switch ( V_122 ) {
case V_165 :
F_83 ( V_7 ) ;
F_11 (op, &bo->rx_ops, list)
if ( V_27 -> V_115 == V_16 )
F_61 ( V_16 , V_27 ) ;
if ( V_25 -> V_145 && V_25 -> V_14 == V_16 -> V_14 ) {
V_25 -> V_145 = 0 ;
V_25 -> V_14 = 0 ;
V_163 = 1 ;
}
F_84 ( V_7 ) ;
if ( V_163 ) {
V_7 -> V_166 = V_123 ;
if ( ! F_89 ( V_7 , V_167 ) )
V_7 -> V_168 ( V_7 ) ;
}
break;
case V_169 :
if ( V_25 -> V_145 && V_25 -> V_14 == V_16 -> V_14 ) {
V_7 -> V_166 = V_170 ;
if ( ! F_89 ( V_7 , V_167 ) )
V_7 -> V_168 ( V_7 ) ;
}
}
return V_164 ;
}
static int F_90 ( struct V_6 * V_7 )
{
struct V_5 * V_25 = F_2 ( V_7 ) ;
V_25 -> V_145 = 0 ;
V_25 -> V_14 = 0 ;
V_25 -> V_29 = 0 ;
V_25 -> V_171 = NULL ;
F_91 ( & V_25 -> V_125 ) ;
F_91 ( & V_25 -> V_140 ) ;
V_25 -> V_162 . V_172 = F_85 ;
F_92 ( & V_25 -> V_162 ) ;
return 0 ;
}
static int F_93 ( struct V_142 * V_6 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_5 * V_25 ;
struct V_26 * V_27 , * V_173 ;
if ( V_7 == NULL )
return 0 ;
V_25 = F_2 ( V_7 ) ;
F_94 ( & V_25 -> V_162 ) ;
F_83 ( V_7 ) ;
F_66 (op, next, &bo->tx_ops, list)
F_57 ( V_27 ) ;
F_66 (op, next, &bo->rx_ops, list) {
if ( V_27 -> V_14 ) {
if ( V_27 -> V_115 ) {
struct V_15 * V_16 ;
V_16 = F_18 ( & V_17 , V_27 -> V_14 ) ;
if ( V_16 ) {
F_61 ( V_16 , V_27 ) ;
F_26 ( V_16 ) ;
}
}
} else
F_62 ( NULL , V_27 -> V_32 ,
F_63 ( V_27 -> V_32 ) ,
F_54 , V_27 ) ;
F_57 ( V_27 ) ;
}
if ( V_174 && V_25 -> V_171 )
F_95 ( V_25 -> V_175 , V_174 ) ;
if ( V_25 -> V_145 ) {
V_25 -> V_145 = 0 ;
V_25 -> V_14 = 0 ;
}
F_96 ( V_7 ) ;
V_6 -> V_7 = NULL ;
F_84 ( V_7 ) ;
F_97 ( V_7 ) ;
return 0 ;
}
static int F_98 ( struct V_142 * V_6 , struct V_176 * V_177 , int V_93 ,
int V_33 )
{
struct V_55 * V_56 = (struct V_55 * ) V_177 ;
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_5 * V_25 = F_2 ( V_7 ) ;
int V_144 = 0 ;
if ( V_93 < sizeof( * V_56 ) )
return - V_119 ;
F_83 ( V_7 ) ;
if ( V_25 -> V_145 ) {
V_144 = - V_178 ;
goto V_179;
}
if ( V_56 -> V_65 ) {
struct V_15 * V_16 ;
V_16 = F_18 ( & V_17 , V_56 -> V_65 ) ;
if ( ! V_16 ) {
V_144 = - V_123 ;
goto V_179;
}
if ( V_16 -> type != V_149 ) {
F_26 ( V_16 ) ;
V_144 = - V_123 ;
goto V_179;
}
V_25 -> V_14 = V_16 -> V_14 ;
F_26 ( V_16 ) ;
} else {
V_25 -> V_14 = 0 ;
}
if ( V_174 ) {
sprintf ( V_25 -> V_175 , L_28 , F_99 ( V_7 ) ) ;
V_25 -> V_171 = F_100 ( V_25 -> V_175 , 0644 ,
V_174 ,
& V_180 , V_7 ) ;
if ( ! V_25 -> V_171 ) {
V_144 = - V_131 ;
goto V_179;
}
}
V_25 -> V_145 = 1 ;
V_179:
F_84 ( V_7 ) ;
return V_144 ;
}
static int F_101 ( struct V_142 * V_6 , struct V_121 * V_122 , T_3 V_143 ,
int V_33 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_42 * V_43 ;
int error = 0 ;
int V_181 ;
int V_58 ;
V_181 = V_33 & V_182 ;
V_33 &= ~ V_182 ;
V_43 = F_102 ( V_7 , V_33 , V_181 , & error ) ;
if ( ! V_43 )
return error ;
if ( V_43 -> V_93 < V_143 )
V_143 = V_43 -> V_93 ;
V_58 = F_103 ( V_122 , V_43 -> V_4 , V_143 ) ;
if ( V_58 < 0 ) {
F_104 ( V_7 , V_43 ) ;
return V_58 ;
}
F_105 ( V_122 , V_7 , V_43 ) ;
if ( V_122 -> V_147 ) {
F_106 ( sizeof( struct V_55 ) ) ;
V_122 -> V_148 = sizeof( struct V_55 ) ;
memcpy ( V_122 -> V_147 , V_43 -> V_62 , V_122 -> V_148 ) ;
}
F_104 ( V_7 , V_43 ) ;
return V_143 ;
}
static int T_4 F_107 ( void )
{
int V_58 ;
F_108 ( L_29 V_183 L_30 ) ;
V_58 = F_109 ( & V_184 ) ;
if ( V_58 < 0 ) {
F_64 ( V_116 L_31 ) ;
return V_58 ;
}
V_174 = F_110 ( L_32 , V_17 . V_185 ) ;
return 0 ;
}
static void T_5 F_111 ( void )
{
F_112 ( & V_184 ) ;
if ( V_174 )
F_95 ( L_32 , V_17 . V_185 ) ;
}
