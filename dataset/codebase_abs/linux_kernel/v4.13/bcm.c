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
static char * F_5 ( struct V_13 * V_13 , char * V_14 , int V_15 )
{
struct V_16 * V_17 ;
if ( ! V_15 )
return L_1 ;
F_6 () ;
V_17 = F_7 ( V_13 , V_15 ) ;
if ( V_17 )
strcpy ( V_14 , V_17 -> V_18 ) ;
else
strcpy ( V_14 , L_2 ) ;
F_8 () ;
return V_14 ;
}
static int F_9 ( struct V_19 * V_20 , void * V_21 )
{
char V_22 [ V_23 ] ;
struct V_13 * V_13 = V_20 -> V_24 ;
struct V_6 * V_7 = (struct V_6 * ) F_10 ( V_20 -> V_25 -> V_26 ) ;
struct V_5 * V_27 = F_2 ( V_7 ) ;
struct V_28 * V_29 ;
F_11 ( V_20 , L_3 , V_7 -> V_30 ) ;
F_11 ( V_20 , L_4 , V_7 ) ;
F_11 ( V_20 , L_5 , V_27 ) ;
F_11 ( V_20 , L_6 , V_27 -> V_31 ) ;
F_11 ( V_20 , L_7 , F_5 ( V_13 , V_22 , V_27 -> V_15 ) ) ;
F_11 ( V_20 , L_8 ) ;
F_12 (op, &bo->rx_ops, list) {
unsigned long V_32 ;
if ( ! V_29 -> V_33 )
continue;
F_11 ( V_20 , L_9 , V_29 -> V_34 ,
F_5 ( V_13 , V_22 , V_29 -> V_15 ) ) ;
if ( V_29 -> V_35 & V_36 )
F_11 ( V_20 , L_10 , V_29 -> V_37 ) ;
else
F_11 ( V_20 , L_11 , V_29 -> V_37 ) ;
F_11 ( V_20 , L_12 , ( V_29 -> V_35 & V_38 ) ? 'd' : ' ' ) ;
if ( V_29 -> V_39 )
F_11 ( V_20 , L_13 ,
( long long ) F_13 ( V_29 -> V_39 ) ) ;
if ( V_29 -> V_40 )
F_11 ( V_20 , L_14 ,
( long long ) F_13 ( V_29 -> V_40 ) ) ;
F_11 ( V_20 , L_15 ,
V_29 -> V_41 , V_29 -> V_33 ) ;
V_32 = 100 - ( V_29 -> V_41 * 100 ) / V_29 -> V_33 ;
F_11 ( V_20 , L_16 ,
( V_32 == 100 ) ? L_17 : L_18 , V_32 ) ;
}
F_12 (op, &bo->tx_ops, list) {
F_11 ( V_20 , L_19 , V_29 -> V_34 ,
F_5 ( V_13 , V_22 , V_29 -> V_15 ) ) ;
if ( V_29 -> V_35 & V_36 )
F_11 ( V_20 , L_20 , V_29 -> V_37 ) ;
else
F_11 ( V_20 , L_21 , V_29 -> V_37 ) ;
if ( V_29 -> V_39 )
F_11 ( V_20 , L_22 ,
( long long ) F_13 ( V_29 -> V_39 ) ) ;
if ( V_29 -> V_40 )
F_11 ( V_20 , L_23 ,
( long long ) F_13 ( V_29 -> V_40 ) ) ;
F_11 ( V_20 , L_24 , V_29 -> V_33 ) ;
}
F_14 ( V_20 , '\n' ) ;
return 0 ;
}
static int F_15 ( struct V_42 * V_42 , struct V_25 * V_25 )
{
return F_16 ( V_42 , V_25 , F_9 ) ;
}
static void F_17 ( struct V_28 * V_29 )
{
struct V_43 * V_44 ;
struct V_16 * V_17 ;
struct V_1 * V_45 = V_29 -> V_46 + V_29 -> V_47 * V_29 -> V_48 ;
if ( ! V_29 -> V_15 )
return;
V_17 = F_18 ( F_19 ( V_29 -> V_7 ) , V_29 -> V_15 ) ;
if ( ! V_17 ) {
return;
}
V_44 = F_20 ( V_29 -> V_47 + sizeof( struct V_49 ) , F_21 () ) ;
if ( ! V_44 )
goto V_50;
F_22 ( V_44 ) ;
F_23 ( V_44 ) -> V_15 = V_17 -> V_15 ;
F_23 ( V_44 ) -> V_51 = 0 ;
F_24 ( V_44 , V_45 , V_29 -> V_47 ) ;
V_44 -> V_17 = V_17 ;
F_25 ( V_44 , V_29 -> V_7 ) ;
F_26 ( V_44 , 1 ) ;
V_29 -> V_48 ++ ;
V_29 -> V_33 ++ ;
if ( V_29 -> V_48 >= V_29 -> V_37 )
V_29 -> V_48 = 0 ;
V_50:
F_27 ( V_17 ) ;
}
static void F_28 ( struct V_28 * V_29 , struct V_52 * V_53 ,
struct V_1 * V_46 , int V_54 )
{
struct V_43 * V_44 ;
struct V_1 * V_55 ;
struct V_56 * V_57 ;
struct V_6 * V_7 = V_29 -> V_7 ;
unsigned int V_58 = V_53 -> V_37 * V_29 -> V_47 ;
int V_59 ;
V_44 = F_20 ( sizeof( * V_53 ) + V_58 , F_21 () ) ;
if ( ! V_44 )
return;
F_24 ( V_44 , V_53 , sizeof( * V_53 ) ) ;
if ( V_53 -> V_37 ) {
V_55 = (struct V_1 * ) F_29 ( V_44 ) ;
F_24 ( V_44 , V_46 , V_58 ) ;
if ( V_53 -> V_37 == 1 )
V_55 -> V_35 &= V_60 ;
}
if ( V_54 ) {
V_44 -> V_61 = V_29 -> V_62 ;
}
F_30 ( sizeof( struct V_56 ) ) ;
V_57 = (struct V_56 * ) V_44 -> V_63 ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_57 -> V_64 = V_65 ;
V_57 -> V_66 = V_29 -> V_67 ;
V_59 = F_31 ( V_7 , V_44 ) ;
if ( V_59 < 0 ) {
struct V_5 * V_27 = F_2 ( V_7 ) ;
F_32 ( V_44 ) ;
V_27 -> V_31 ++ ;
}
}
static void F_33 ( struct V_28 * V_29 )
{
if ( V_29 -> V_39 && V_29 -> V_68 )
F_34 ( & V_29 -> V_69 ,
F_35 ( F_36 () , V_29 -> V_39 ) ,
V_70 ) ;
else if ( V_29 -> V_40 )
F_34 ( & V_29 -> V_69 ,
F_35 ( F_36 () , V_29 -> V_40 ) ,
V_70 ) ;
}
static void F_37 ( unsigned long V_4 )
{
struct V_28 * V_29 = (struct V_28 * ) V_4 ;
struct V_52 V_71 ;
if ( V_29 -> V_39 && ( V_29 -> V_68 > 0 ) ) {
V_29 -> V_68 -- ;
if ( ! V_29 -> V_68 && ( V_29 -> V_35 & V_72 ) ) {
V_71 . V_73 = V_74 ;
V_71 . V_35 = V_29 -> V_35 ;
V_71 . V_68 = V_29 -> V_68 ;
V_71 . V_75 = V_29 -> V_75 ;
V_71 . V_76 = V_29 -> V_76 ;
V_71 . V_34 = V_29 -> V_34 ;
V_71 . V_37 = 0 ;
F_28 ( V_29 , & V_71 , NULL , 0 ) ;
}
F_17 ( V_29 ) ;
} else if ( V_29 -> V_40 )
F_17 ( V_29 ) ;
F_33 ( V_29 ) ;
}
static enum V_77 F_38 ( struct V_78 * V_78 )
{
struct V_28 * V_29 = F_39 ( V_78 , struct V_28 , V_69 ) ;
F_40 ( & V_29 -> V_79 ) ;
return V_80 ;
}
static void F_41 ( struct V_28 * V_29 , struct V_1 * V_4 )
{
struct V_52 V_53 ;
V_29 -> V_41 ++ ;
if ( V_29 -> V_41 > V_81 / 100 )
V_29 -> V_41 = V_29 -> V_33 = 0 ;
V_4 -> V_35 &= ( V_60 | V_82 ) ;
V_53 . V_73 = V_83 ;
V_53 . V_35 = V_29 -> V_35 ;
V_53 . V_68 = V_29 -> V_68 ;
V_53 . V_75 = V_29 -> V_75 ;
V_53 . V_76 = V_29 -> V_76 ;
V_53 . V_34 = V_29 -> V_34 ;
V_53 . V_37 = 1 ;
F_28 ( V_29 , & V_53 , V_4 , 1 ) ;
}
static void F_42 ( struct V_28 * V_29 ,
struct V_1 * V_84 ,
const struct V_1 * V_85 )
{
memcpy ( V_84 , V_85 , V_29 -> V_47 ) ;
V_84 -> V_35 |= ( V_82 | V_86 ) ;
if ( ! V_29 -> V_40 ) {
F_41 ( V_29 , V_84 ) ;
return;
}
if ( F_43 ( & V_29 -> V_87 ) )
return;
if ( ! V_29 -> V_88 )
goto V_89;
if ( F_44 ( F_36 () , V_29 -> V_88 ) <
F_13 ( V_29 -> V_40 ) ) {
F_34 ( & V_29 -> V_87 ,
F_35 ( V_29 -> V_88 , V_29 -> V_40 ) ,
V_70 ) ;
return;
}
V_89:
F_41 ( V_29 , V_84 ) ;
V_29 -> V_88 = F_36 () ;
}
static void F_45 ( struct V_28 * V_29 , unsigned int V_90 ,
const struct V_1 * V_85 )
{
struct V_1 * V_45 = V_29 -> V_46 + V_29 -> V_47 * V_90 ;
struct V_1 * V_91 = V_29 -> V_92 + V_29 -> V_47 * V_90 ;
int V_93 ;
if ( ! ( V_91 -> V_35 & V_82 ) ) {
F_42 ( V_29 , V_91 , V_85 ) ;
return;
}
for ( V_93 = 0 ; V_93 < V_85 -> V_94 ; V_93 += 8 ) {
if ( ( F_1 ( V_45 , V_93 ) & F_1 ( V_85 , V_93 ) ) !=
( F_1 ( V_45 , V_93 ) & F_1 ( V_91 , V_93 ) ) ) {
F_42 ( V_29 , V_91 , V_85 ) ;
return;
}
}
if ( V_29 -> V_35 & V_38 ) {
if ( V_85 -> V_94 != V_91 -> V_94 ) {
F_42 ( V_29 , V_91 , V_85 ) ;
return;
}
}
}
static void F_46 ( struct V_28 * V_29 )
{
if ( V_29 -> V_35 & V_95 )
return;
if ( V_29 -> V_39 )
F_34 ( & V_29 -> V_69 , V_29 -> V_39 , V_96 ) ;
}
static void F_47 ( unsigned long V_4 )
{
struct V_28 * V_29 = (struct V_28 * ) V_4 ;
struct V_52 V_71 ;
V_71 . V_73 = V_97 ;
V_71 . V_35 = V_29 -> V_35 ;
V_71 . V_68 = V_29 -> V_68 ;
V_71 . V_75 = V_29 -> V_75 ;
V_71 . V_76 = V_29 -> V_76 ;
V_71 . V_34 = V_29 -> V_34 ;
V_71 . V_37 = 0 ;
F_28 ( V_29 , & V_71 , NULL , 0 ) ;
}
static enum V_77 F_48 ( struct V_78 * V_78 )
{
struct V_28 * V_29 = F_39 ( V_78 , struct V_28 , V_69 ) ;
F_49 ( & V_29 -> V_79 ) ;
if ( ( V_29 -> V_35 & V_98 ) && V_29 -> V_92 ) {
memset ( V_29 -> V_92 , 0 , V_29 -> V_37 * V_29 -> V_47 ) ;
}
return V_80 ;
}
static inline int F_50 ( struct V_28 * V_29 , int V_99 ,
unsigned int V_90 )
{
struct V_1 * V_91 = V_29 -> V_92 + V_29 -> V_47 * V_90 ;
if ( ( V_29 -> V_92 ) && ( V_91 -> V_35 & V_86 ) ) {
if ( V_99 )
F_41 ( V_29 , V_91 ) ;
return 1 ;
}
return 0 ;
}
static int F_51 ( struct V_28 * V_29 , int V_99 )
{
int V_100 = 0 ;
if ( V_29 -> V_37 > 1 ) {
unsigned int V_93 ;
for ( V_93 = 1 ; V_93 < V_29 -> V_37 ; V_93 ++ )
V_100 += F_50 ( V_29 , V_99 , V_93 ) ;
} else {
V_100 += F_50 ( V_29 , V_99 , 0 ) ;
}
return V_100 ;
}
static void F_52 ( unsigned long V_4 )
{
struct V_28 * V_29 = (struct V_28 * ) V_4 ;
F_51 ( V_29 , 1 ) ;
}
static enum V_77 F_53 ( struct V_78 * V_78 )
{
struct V_28 * V_29 = F_39 ( V_78 , struct V_28 , V_87 ) ;
F_40 ( & V_29 -> V_101 ) ;
if ( F_51 ( V_29 , 0 ) ) {
F_54 ( V_78 , F_36 () , V_29 -> V_40 ) ;
return V_102 ;
} else {
V_29 -> V_88 = 0 ;
return V_80 ;
}
}
static void F_55 ( struct V_43 * V_44 , void * V_4 )
{
struct V_28 * V_29 = (struct V_28 * ) V_4 ;
const struct V_1 * V_103 = (struct V_1 * ) V_44 -> V_4 ;
unsigned int V_93 ;
if ( V_29 -> V_34 != V_103 -> V_34 )
return;
if ( V_44 -> V_94 != V_29 -> V_47 )
return;
F_56 ( & V_29 -> V_69 ) ;
V_29 -> V_62 = V_44 -> V_61 ;
V_29 -> V_67 = V_44 -> V_17 -> V_15 ;
V_29 -> V_33 ++ ;
if ( V_29 -> V_35 & V_104 ) {
F_17 ( V_29 ) ;
return;
}
if ( V_29 -> V_35 & V_105 ) {
F_42 ( V_29 , V_29 -> V_92 , V_103 ) ;
goto V_106;
}
if ( V_29 -> V_37 == 1 ) {
F_45 ( V_29 , 0 , V_103 ) ;
goto V_106;
}
if ( V_29 -> V_37 > 1 ) {
for ( V_93 = 1 ; V_93 < V_29 -> V_37 ; V_93 ++ ) {
if ( ( F_1 ( V_29 -> V_46 , 0 ) & F_1 ( V_103 , 0 ) ) ==
( F_1 ( V_29 -> V_46 , 0 ) &
F_1 ( V_29 -> V_46 + V_29 -> V_47 * V_93 , 0 ) ) ) {
F_45 ( V_29 , V_93 , V_103 ) ;
break;
}
}
}
V_106:
F_46 ( V_29 ) ;
}
static struct V_28 * F_57 ( struct V_107 * V_108 ,
struct V_52 * V_109 , int V_15 )
{
struct V_28 * V_29 ;
F_12 (op, ops, list) {
if ( ( V_29 -> V_34 == V_109 -> V_34 ) && ( V_29 -> V_15 == V_15 ) &&
( V_29 -> V_35 & V_36 ) == ( V_109 -> V_35 & V_36 ) )
return V_29 ;
}
return NULL ;
}
static void F_58 ( struct V_28 * V_29 )
{
if ( V_29 -> V_79 . V_110 ) {
while ( F_59 ( V_111 , & V_29 -> V_79 . V_112 ) ||
F_59 ( V_113 , & V_29 -> V_79 . V_112 ) ||
F_43 ( & V_29 -> V_69 ) ) {
F_56 ( & V_29 -> V_69 ) ;
F_60 ( & V_29 -> V_79 ) ;
}
}
if ( V_29 -> V_101 . V_110 ) {
while ( F_59 ( V_111 , & V_29 -> V_101 . V_112 ) ||
F_59 ( V_113 , & V_29 -> V_101 . V_112 ) ||
F_43 ( & V_29 -> V_87 ) ) {
F_56 ( & V_29 -> V_87 ) ;
F_60 ( & V_29 -> V_101 ) ;
}
}
if ( ( V_29 -> V_46 ) && ( V_29 -> V_46 != & V_29 -> V_114 ) )
F_61 ( V_29 -> V_46 ) ;
if ( ( V_29 -> V_92 ) && ( V_29 -> V_92 != & V_29 -> V_115 ) )
F_61 ( V_29 -> V_92 ) ;
F_61 ( V_29 ) ;
}
static void F_62 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
if ( V_29 -> V_116 == V_17 ) {
F_63 ( F_64 ( V_17 ) , V_17 , V_29 -> V_34 ,
F_65 ( V_29 -> V_34 ) , F_55 , V_29 ) ;
V_29 -> V_116 = NULL ;
} else
F_66 ( V_117 L_25
L_26 , V_29 -> V_116 , V_17 ) ;
}
static int F_67 ( struct V_107 * V_108 , struct V_52 * V_109 ,
int V_15 )
{
struct V_28 * V_29 , * V_118 ;
F_68 (op, n, ops, list) {
if ( ( V_29 -> V_34 == V_109 -> V_34 ) && ( V_29 -> V_15 == V_15 ) &&
( V_29 -> V_35 & V_36 ) == ( V_109 -> V_35 & V_36 ) ) {
if ( V_29 -> V_15 ) {
if ( V_29 -> V_116 ) {
struct V_16 * V_17 ;
V_17 = F_18 ( F_19 ( V_29 -> V_7 ) ,
V_29 -> V_15 ) ;
if ( V_17 ) {
F_62 ( V_17 , V_29 ) ;
F_27 ( V_17 ) ;
}
}
} else
F_63 ( F_19 ( V_29 -> V_7 ) , NULL ,
V_29 -> V_34 ,
F_65 ( V_29 -> V_34 ) ,
F_55 , V_29 ) ;
F_69 ( & V_29 -> V_119 ) ;
F_58 ( V_29 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_70 ( struct V_107 * V_108 , struct V_52 * V_109 ,
int V_15 )
{
struct V_28 * V_29 , * V_118 ;
F_68 (op, n, ops, list) {
if ( ( V_29 -> V_34 == V_109 -> V_34 ) && ( V_29 -> V_15 == V_15 ) &&
( V_29 -> V_35 & V_36 ) == ( V_109 -> V_35 & V_36 ) ) {
F_69 ( & V_29 -> V_119 ) ;
F_58 ( V_29 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_71 ( struct V_107 * V_108 , struct V_52 * V_71 ,
int V_15 )
{
struct V_28 * V_29 = F_57 ( V_108 , V_71 , V_15 ) ;
if ( ! V_29 )
return - V_120 ;
V_71 -> V_35 = V_29 -> V_35 ;
V_71 -> V_68 = V_29 -> V_68 ;
V_71 -> V_75 = V_29 -> V_75 ;
V_71 -> V_76 = V_29 -> V_76 ;
V_71 -> V_37 = V_29 -> V_37 ;
F_28 ( V_29 , V_71 , V_29 -> V_46 , 0 ) ;
return V_121 ;
}
static int F_72 ( struct V_52 * V_71 , struct V_122 * V_123 ,
int V_15 , struct V_6 * V_7 )
{
struct V_5 * V_27 = F_2 ( V_7 ) ;
struct V_28 * V_29 ;
struct V_1 * V_45 ;
unsigned int V_93 ;
int V_59 ;
if ( ! V_15 )
return - V_124 ;
if ( V_71 -> V_37 < 1 || V_71 -> V_37 > V_125 )
return - V_120 ;
V_29 = F_57 ( & V_27 -> V_126 , V_71 , V_15 ) ;
if ( V_29 ) {
if ( V_71 -> V_37 > V_29 -> V_37 )
return - V_127 ;
for ( V_93 = 0 ; V_93 < V_71 -> V_37 ; V_93 ++ ) {
V_45 = V_29 -> V_46 + V_29 -> V_47 * V_93 ;
V_59 = F_73 ( ( V_128 * ) V_45 , V_123 , V_29 -> V_47 ) ;
if ( V_29 -> V_35 & V_36 ) {
if ( V_45 -> V_94 > 64 )
V_59 = - V_120 ;
} else {
if ( V_45 -> V_94 > 8 )
V_59 = - V_120 ;
}
if ( V_59 < 0 )
return V_59 ;
if ( V_71 -> V_35 & V_129 ) {
V_45 -> V_34 = V_71 -> V_34 ;
}
}
V_29 -> V_35 = V_71 -> V_35 ;
} else {
V_29 = F_74 ( V_130 , V_131 ) ;
if ( ! V_29 )
return - V_132 ;
V_29 -> V_34 = V_71 -> V_34 ;
V_29 -> V_47 = F_75 ( V_71 -> V_35 ) ;
V_29 -> V_35 = V_71 -> V_35 ;
if ( V_71 -> V_37 > 1 ) {
V_29 -> V_46 = F_76 ( V_71 -> V_37 * V_29 -> V_47 ,
V_131 ) ;
if ( ! V_29 -> V_46 ) {
F_61 ( V_29 ) ;
return - V_132 ;
}
} else
V_29 -> V_46 = & V_29 -> V_114 ;
for ( V_93 = 0 ; V_93 < V_71 -> V_37 ; V_93 ++ ) {
V_45 = V_29 -> V_46 + V_29 -> V_47 * V_93 ;
V_59 = F_73 ( ( V_128 * ) V_45 , V_123 , V_29 -> V_47 ) ;
if ( V_29 -> V_35 & V_36 ) {
if ( V_45 -> V_94 > 64 )
V_59 = - V_120 ;
} else {
if ( V_45 -> V_94 > 8 )
V_59 = - V_120 ;
}
if ( V_59 < 0 ) {
if ( V_29 -> V_46 != & V_29 -> V_114 )
F_61 ( V_29 -> V_46 ) ;
F_61 ( V_29 ) ;
return V_59 ;
}
if ( V_71 -> V_35 & V_129 ) {
V_45 -> V_34 = V_71 -> V_34 ;
}
}
V_29 -> V_92 = NULL ;
V_29 -> V_7 = V_7 ;
V_29 -> V_15 = V_15 ;
F_77 ( & V_29 -> V_69 , V_133 , V_96 ) ;
V_29 -> V_69 . V_134 = F_38 ;
F_78 ( & V_29 -> V_79 , F_37 ,
( unsigned long ) V_29 ) ;
F_77 ( & V_29 -> V_87 , V_133 , V_96 ) ;
F_79 ( & V_29 -> V_119 , & V_27 -> V_126 ) ;
}
if ( V_29 -> V_37 != V_71 -> V_37 ) {
V_29 -> V_37 = V_71 -> V_37 ;
V_29 -> V_48 = 0 ;
}
if ( V_29 -> V_35 & V_135 ) {
V_29 -> V_48 = 0 ;
}
if ( V_29 -> V_35 & V_136 ) {
V_29 -> V_68 = V_71 -> V_68 ;
V_29 -> V_75 = V_71 -> V_75 ;
V_29 -> V_76 = V_71 -> V_76 ;
V_29 -> V_39 = F_3 ( V_71 -> V_75 ) ;
V_29 -> V_40 = F_3 ( V_71 -> V_76 ) ;
if ( ! V_29 -> V_39 && ! V_29 -> V_40 )
F_56 ( & V_29 -> V_69 ) ;
}
if ( V_29 -> V_35 & V_137 ) {
F_56 ( & V_29 -> V_69 ) ;
V_29 -> V_35 |= V_138 ;
}
if ( V_29 -> V_35 & V_138 ) {
F_17 ( V_29 ) ;
if ( V_29 -> V_68 )
V_29 -> V_68 -- ;
}
if ( V_29 -> V_35 & V_137 )
F_33 ( V_29 ) ;
return V_71 -> V_37 * V_29 -> V_47 + V_121 ;
}
static int F_80 ( struct V_52 * V_71 , struct V_122 * V_123 ,
int V_15 , struct V_6 * V_7 )
{
struct V_5 * V_27 = F_2 ( V_7 ) ;
struct V_28 * V_29 ;
int V_139 ;
int V_59 = 0 ;
if ( ( V_71 -> V_35 & V_105 ) || ( ! ( V_71 -> V_37 ) ) ) {
V_71 -> V_35 |= V_105 ;
V_71 -> V_37 = 0 ;
}
if ( V_71 -> V_37 > V_125 + 1 )
return - V_120 ;
if ( ( V_71 -> V_35 & V_104 ) &&
( ( V_71 -> V_37 != 1 ) ||
( ! ( V_71 -> V_34 & V_140 ) ) ) )
return - V_120 ;
V_29 = F_57 ( & V_27 -> V_141 , V_71 , V_15 ) ;
if ( V_29 ) {
if ( V_71 -> V_37 > V_29 -> V_37 )
return - V_127 ;
if ( V_71 -> V_37 ) {
V_59 = F_73 ( V_29 -> V_46 , V_123 ,
V_71 -> V_37 * V_29 -> V_47 ) ;
if ( V_59 < 0 )
return V_59 ;
memset ( V_29 -> V_92 , 0 , V_71 -> V_37 * V_29 -> V_47 ) ;
}
V_29 -> V_37 = V_71 -> V_37 ;
V_29 -> V_35 = V_71 -> V_35 ;
V_139 = 0 ;
} else {
V_29 = F_74 ( V_130 , V_131 ) ;
if ( ! V_29 )
return - V_132 ;
V_29 -> V_34 = V_71 -> V_34 ;
V_29 -> V_37 = V_71 -> V_37 ;
V_29 -> V_47 = F_75 ( V_71 -> V_35 ) ;
V_29 -> V_35 = V_71 -> V_35 ;
if ( V_71 -> V_37 > 1 ) {
V_29 -> V_46 = F_76 ( V_71 -> V_37 * V_29 -> V_47 ,
V_131 ) ;
if ( ! V_29 -> V_46 ) {
F_61 ( V_29 ) ;
return - V_132 ;
}
V_29 -> V_92 = F_74 ( V_71 -> V_37 * V_29 -> V_47 ,
V_131 ) ;
if ( ! V_29 -> V_92 ) {
F_61 ( V_29 -> V_46 ) ;
F_61 ( V_29 ) ;
return - V_132 ;
}
} else {
V_29 -> V_46 = & V_29 -> V_114 ;
V_29 -> V_92 = & V_29 -> V_115 ;
}
if ( V_71 -> V_37 ) {
V_59 = F_73 ( V_29 -> V_46 , V_123 ,
V_71 -> V_37 * V_29 -> V_47 ) ;
if ( V_59 < 0 ) {
if ( V_29 -> V_46 != & V_29 -> V_114 )
F_61 ( V_29 -> V_46 ) ;
if ( V_29 -> V_92 != & V_29 -> V_115 )
F_61 ( V_29 -> V_92 ) ;
F_61 ( V_29 ) ;
return V_59 ;
}
}
V_29 -> V_7 = V_7 ;
V_29 -> V_15 = V_15 ;
V_29 -> V_67 = V_15 ;
F_77 ( & V_29 -> V_69 , V_133 , V_96 ) ;
V_29 -> V_69 . V_134 = F_48 ;
F_78 ( & V_29 -> V_79 , F_47 ,
( unsigned long ) V_29 ) ;
F_77 ( & V_29 -> V_87 , V_133 , V_96 ) ;
V_29 -> V_87 . V_134 = F_53 ;
F_78 ( & V_29 -> V_101 , F_52 ,
( unsigned long ) V_29 ) ;
F_79 ( & V_29 -> V_119 , & V_27 -> V_141 ) ;
V_139 = 1 ;
}
if ( V_29 -> V_35 & V_104 ) {
struct V_1 * V_142 = V_29 -> V_46 ;
F_56 ( & V_29 -> V_87 ) ;
F_56 ( & V_29 -> V_69 ) ;
if ( ( V_29 -> V_35 & V_129 ) ||
( V_142 -> V_34 == V_29 -> V_34 ) )
V_142 -> V_34 = V_29 -> V_34 & ~ V_140 ;
} else {
if ( V_29 -> V_35 & V_136 ) {
V_29 -> V_75 = V_71 -> V_75 ;
V_29 -> V_76 = V_71 -> V_76 ;
V_29 -> V_39 = F_3 ( V_71 -> V_75 ) ;
V_29 -> V_40 = F_3 ( V_71 -> V_76 ) ;
if ( ! V_29 -> V_39 )
F_56 ( & V_29 -> V_69 ) ;
V_29 -> V_88 = 0 ;
F_56 ( & V_29 -> V_87 ) ;
F_51 ( V_29 , 1 ) ;
}
if ( ( V_29 -> V_35 & V_137 ) && V_29 -> V_39 )
F_34 ( & V_29 -> V_69 , V_29 -> V_39 ,
V_96 ) ;
}
if ( V_139 ) {
if ( V_15 ) {
struct V_16 * V_17 ;
V_17 = F_18 ( F_19 ( V_7 ) , V_15 ) ;
if ( V_17 ) {
V_59 = F_81 ( F_19 ( V_7 ) , V_17 ,
V_29 -> V_34 ,
F_65 ( V_29 -> V_34 ) ,
F_55 , V_29 ,
L_27 , V_7 ) ;
V_29 -> V_116 = V_17 ;
F_27 ( V_17 ) ;
}
} else
V_59 = F_81 ( F_19 ( V_7 ) , NULL , V_29 -> V_34 ,
F_65 ( V_29 -> V_34 ) ,
F_55 , V_29 , L_27 , V_7 ) ;
if ( V_59 ) {
F_69 ( & V_29 -> V_119 ) ;
F_58 ( V_29 ) ;
return V_59 ;
}
}
return V_71 -> V_37 * V_29 -> V_47 + V_121 ;
}
static int F_82 ( struct V_122 * V_123 , int V_15 , struct V_6 * V_7 ,
int V_47 )
{
struct V_43 * V_44 ;
struct V_16 * V_17 ;
int V_59 ;
if ( ! V_15 )
return - V_124 ;
V_44 = F_20 ( V_47 + sizeof( struct V_49 ) , V_131 ) ;
if ( ! V_44 )
return - V_132 ;
F_22 ( V_44 ) ;
V_59 = F_73 ( F_83 ( V_44 , V_47 ) , V_123 , V_47 ) ;
if ( V_59 < 0 ) {
F_32 ( V_44 ) ;
return V_59 ;
}
V_17 = F_18 ( F_19 ( V_7 ) , V_15 ) ;
if ( ! V_17 ) {
F_32 ( V_44 ) ;
return - V_124 ;
}
F_23 ( V_44 ) -> V_15 = V_17 -> V_15 ;
F_23 ( V_44 ) -> V_51 = 0 ;
V_44 -> V_17 = V_17 ;
F_25 ( V_44 , V_7 ) ;
V_59 = F_26 ( V_44 , 1 ) ;
F_27 ( V_17 ) ;
if ( V_59 )
return V_59 ;
return V_47 + V_121 ;
}
static int F_84 ( struct V_143 * V_6 , struct V_122 * V_123 , T_3 V_144 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_5 * V_27 = F_2 ( V_7 ) ;
int V_15 = V_27 -> V_15 ;
struct V_52 V_71 ;
int V_47 ;
int V_145 ;
if ( ! V_27 -> V_146 )
return - V_147 ;
if ( V_144 < V_121 )
return - V_120 ;
V_145 = F_73 ( ( V_128 * ) & V_71 , V_123 , V_121 ) ;
if ( V_145 < 0 )
return V_145 ;
V_47 = F_75 ( V_71 . V_35 ) ;
if ( ( V_144 - V_121 ) % V_47 )
return - V_120 ;
if ( ! V_15 && V_123 -> V_148 ) {
F_85 ( struct V_56 * , V_57 , V_123 -> V_148 ) ;
if ( V_123 -> V_149 < sizeof( * V_57 ) )
return - V_120 ;
if ( V_57 -> V_64 != V_65 )
return - V_120 ;
V_15 = V_57 -> V_66 ;
if ( V_15 ) {
struct V_16 * V_17 ;
V_17 = F_18 ( F_19 ( V_7 ) , V_15 ) ;
if ( ! V_17 )
return - V_124 ;
if ( V_17 -> type != V_150 ) {
F_27 ( V_17 ) ;
return - V_124 ;
}
F_27 ( V_17 ) ;
}
}
F_86 ( V_7 ) ;
switch ( V_71 . V_73 ) {
case V_151 :
V_145 = F_72 ( & V_71 , V_123 , V_15 , V_7 ) ;
break;
case V_152 :
V_145 = F_80 ( & V_71 , V_123 , V_15 , V_7 ) ;
break;
case V_153 :
if ( F_70 ( & V_27 -> V_126 , & V_71 , V_15 ) )
V_145 = V_121 ;
else
V_145 = - V_120 ;
break;
case V_154 :
if ( F_67 ( & V_27 -> V_141 , & V_71 , V_15 ) )
V_145 = V_121 ;
else
V_145 = - V_120 ;
break;
case V_155 :
V_71 . V_73 = V_156 ;
V_145 = F_71 ( & V_27 -> V_126 , & V_71 , V_15 ) ;
break;
case V_157 :
V_71 . V_73 = V_158 ;
V_145 = F_71 ( & V_27 -> V_141 , & V_71 , V_15 ) ;
break;
case V_159 :
if ( ( V_71 . V_37 != 1 ) || ( V_144 != V_47 + V_121 ) )
V_145 = - V_120 ;
else
V_145 = F_82 ( V_123 , V_15 , V_7 , V_47 ) ;
break;
default:
V_145 = - V_120 ;
break;
}
F_87 ( V_7 ) ;
return V_145 ;
}
static int F_88 ( struct V_160 * V_161 , unsigned long V_123 ,
void * V_162 )
{
struct V_16 * V_17 = F_89 ( V_162 ) ;
struct V_5 * V_27 = F_39 ( V_161 , struct V_5 , V_163 ) ;
struct V_6 * V_7 = & V_27 -> V_7 ;
struct V_28 * V_29 ;
int V_164 = 0 ;
if ( ! F_90 ( F_64 ( V_17 ) , F_19 ( V_7 ) ) )
return V_165 ;
if ( V_17 -> type != V_150 )
return V_165 ;
switch ( V_123 ) {
case V_166 :
F_86 ( V_7 ) ;
F_12 (op, &bo->rx_ops, list)
if ( V_29 -> V_116 == V_17 )
F_62 ( V_17 , V_29 ) ;
if ( V_27 -> V_146 && V_27 -> V_15 == V_17 -> V_15 ) {
V_27 -> V_146 = 0 ;
V_27 -> V_15 = 0 ;
V_164 = 1 ;
}
F_87 ( V_7 ) ;
if ( V_164 ) {
V_7 -> V_167 = V_124 ;
if ( ! F_91 ( V_7 , V_168 ) )
V_7 -> V_169 ( V_7 ) ;
}
break;
case V_170 :
if ( V_27 -> V_146 && V_27 -> V_15 == V_17 -> V_15 ) {
V_7 -> V_167 = V_171 ;
if ( ! F_91 ( V_7 , V_168 ) )
V_7 -> V_169 ( V_7 ) ;
}
}
return V_165 ;
}
static int F_92 ( struct V_6 * V_7 )
{
struct V_5 * V_27 = F_2 ( V_7 ) ;
V_27 -> V_146 = 0 ;
V_27 -> V_15 = 0 ;
V_27 -> V_31 = 0 ;
V_27 -> V_172 = NULL ;
F_93 ( & V_27 -> V_126 ) ;
F_93 ( & V_27 -> V_141 ) ;
V_27 -> V_163 . V_173 = F_88 ;
F_94 ( & V_27 -> V_163 ) ;
return 0 ;
}
static int F_95 ( struct V_143 * V_6 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_13 * V_13 = F_19 ( V_7 ) ;
struct V_5 * V_27 ;
struct V_28 * V_29 , * V_174 ;
if ( V_7 == NULL )
return 0 ;
V_27 = F_2 ( V_7 ) ;
F_96 ( & V_27 -> V_163 ) ;
F_86 ( V_7 ) ;
F_68 (op, next, &bo->tx_ops, list)
F_58 ( V_29 ) ;
F_68 (op, next, &bo->rx_ops, list) {
if ( V_29 -> V_15 ) {
if ( V_29 -> V_116 ) {
struct V_16 * V_17 ;
V_17 = F_18 ( V_13 , V_29 -> V_15 ) ;
if ( V_17 ) {
F_62 ( V_17 , V_29 ) ;
F_27 ( V_17 ) ;
}
}
} else
F_63 ( V_13 , NULL , V_29 -> V_34 ,
F_65 ( V_29 -> V_34 ) ,
F_55 , V_29 ) ;
F_58 ( V_29 ) ;
}
#if F_97 ( V_175 )
if ( V_13 -> V_176 . V_177 && V_27 -> V_172 )
F_98 ( V_27 -> V_178 , V_13 -> V_176 . V_177 ) ;
#endif
if ( V_27 -> V_146 ) {
V_27 -> V_146 = 0 ;
V_27 -> V_15 = 0 ;
}
F_99 ( V_7 ) ;
V_6 -> V_7 = NULL ;
F_87 ( V_7 ) ;
F_100 ( V_7 ) ;
return 0 ;
}
static int F_101 ( struct V_143 * V_6 , struct V_179 * V_180 , int V_94 ,
int V_35 )
{
struct V_56 * V_57 = (struct V_56 * ) V_180 ;
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_5 * V_27 = F_2 ( V_7 ) ;
struct V_13 * V_13 = F_19 ( V_7 ) ;
int V_145 = 0 ;
if ( V_94 < sizeof( * V_57 ) )
return - V_120 ;
F_86 ( V_7 ) ;
if ( V_27 -> V_146 ) {
V_145 = - V_181 ;
goto V_182;
}
if ( V_57 -> V_66 ) {
struct V_16 * V_17 ;
V_17 = F_18 ( V_13 , V_57 -> V_66 ) ;
if ( ! V_17 ) {
V_145 = - V_124 ;
goto V_182;
}
if ( V_17 -> type != V_150 ) {
F_27 ( V_17 ) ;
V_145 = - V_124 ;
goto V_182;
}
V_27 -> V_15 = V_17 -> V_15 ;
F_27 ( V_17 ) ;
} else {
V_27 -> V_15 = 0 ;
}
#if F_97 ( V_175 )
if ( V_13 -> V_176 . V_177 ) {
sprintf ( V_27 -> V_178 , L_28 , F_102 ( V_7 ) ) ;
V_27 -> V_172 = F_103 ( V_27 -> V_178 , 0644 ,
V_13 -> V_176 . V_177 ,
& V_183 , V_7 ) ;
if ( ! V_27 -> V_172 ) {
V_145 = - V_132 ;
goto V_182;
}
}
#endif
V_27 -> V_146 = 1 ;
V_182:
F_87 ( V_7 ) ;
return V_145 ;
}
static int F_104 ( struct V_143 * V_6 , struct V_122 * V_123 , T_3 V_144 ,
int V_35 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_43 * V_44 ;
int error = 0 ;
int V_184 ;
int V_59 ;
V_184 = V_35 & V_185 ;
V_35 &= ~ V_185 ;
V_44 = F_105 ( V_7 , V_35 , V_184 , & error ) ;
if ( ! V_44 )
return error ;
if ( V_44 -> V_94 < V_144 )
V_144 = V_44 -> V_94 ;
V_59 = F_106 ( V_123 , V_44 -> V_4 , V_144 ) ;
if ( V_59 < 0 ) {
F_107 ( V_7 , V_44 ) ;
return V_59 ;
}
F_108 ( V_123 , V_7 , V_44 ) ;
if ( V_123 -> V_148 ) {
F_109 ( sizeof( struct V_56 ) ) ;
V_123 -> V_149 = sizeof( struct V_56 ) ;
memcpy ( V_123 -> V_148 , V_44 -> V_63 , V_123 -> V_149 ) ;
}
F_107 ( V_7 , V_44 ) ;
return V_144 ;
}
static int F_110 ( struct V_13 * V_13 )
{
#if F_97 ( V_175 )
V_13 -> V_176 . V_177 = F_111 ( V_13 , L_29 , V_13 -> V_186 ) ;
#endif
return 0 ;
}
static void F_112 ( struct V_13 * V_13 )
{
#if F_97 ( V_175 )
if ( V_13 -> V_176 . V_177 )
F_98 ( L_29 , V_13 -> V_186 ) ;
#endif
}
static int T_4 F_113 ( void )
{
int V_59 ;
F_114 ( L_30 V_187 L_31 ) ;
V_59 = F_115 ( & V_188 ) ;
if ( V_59 < 0 ) {
F_66 ( V_117 L_32 ) ;
return V_59 ;
}
F_116 ( & V_189 ) ;
return 0 ;
}
static void T_5 F_117 ( void )
{
F_118 ( & V_188 ) ;
F_119 ( & V_189 ) ;
}
