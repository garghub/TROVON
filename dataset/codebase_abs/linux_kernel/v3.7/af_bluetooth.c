void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( ! V_2 ) ;
F_2 ( F_3 ( V_2 ) ) ;
F_4 ( V_2 ,
V_4 [ V_3 ] , & V_5 [ V_3 ] ,
V_6 [ V_3 ] , & V_7 [ V_3 ] ) ;
}
int F_5 ( int V_3 , const struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( V_3 < 0 || V_3 >= V_11 )
return - V_12 ;
F_6 ( & V_13 ) ;
if ( V_14 [ V_3 ] )
V_10 = - V_15 ;
else
V_14 [ V_3 ] = V_9 ;
F_7 ( & V_13 ) ;
return V_10 ;
}
int F_8 ( int V_3 )
{
int V_10 = 0 ;
if ( V_3 < 0 || V_3 >= V_11 )
return - V_12 ;
F_6 ( & V_13 ) ;
if ( ! V_14 [ V_3 ] )
V_10 = - V_16 ;
else
V_14 [ V_3 ] = NULL ;
F_7 ( & V_13 ) ;
return V_10 ;
}
static int F_9 ( struct V_17 * V_17 , struct V_18 * V_1 , int V_3 ,
int V_19 )
{
int V_10 ;
if ( V_17 != & V_20 )
return - V_21 ;
if ( V_3 < 0 || V_3 >= V_11 )
return - V_12 ;
if ( ! V_14 [ V_3 ] )
F_10 ( L_1 , V_3 ) ;
V_10 = - V_22 ;
F_11 ( & V_13 ) ;
if ( V_14 [ V_3 ] && F_12 ( V_14 [ V_3 ] -> V_23 ) ) {
V_10 = V_14 [ V_3 ] -> F_13 ( V_17 , V_1 , V_3 , V_19 ) ;
if ( ! V_10 )
F_1 ( V_1 -> V_2 , V_3 ) ;
F_14 ( V_14 [ V_3 ] -> V_23 ) ;
}
F_15 ( & V_13 ) ;
return V_10 ;
}
void F_16 ( struct V_24 * V_25 , struct V_1 * V_2 )
{
F_6 ( & V_25 -> V_26 ) ;
F_17 ( V_2 , & V_25 -> V_27 ) ;
F_7 ( & V_25 -> V_26 ) ;
}
void F_18 ( struct V_24 * V_25 , struct V_1 * V_2 )
{
F_6 ( & V_25 -> V_26 ) ;
F_19 ( V_2 ) ;
F_7 ( & V_25 -> V_26 ) ;
}
void F_20 ( struct V_1 * V_28 , struct V_1 * V_2 )
{
F_21 ( L_2 , V_28 , V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( & F_24 ( V_2 ) -> V_29 , & F_24 ( V_28 ) -> V_29 ) ;
F_24 ( V_2 ) -> V_28 = V_28 ;
V_28 -> V_30 ++ ;
}
void F_25 ( struct V_1 * V_2 )
{
F_21 ( L_3 , V_2 , V_2 -> V_31 ) ;
F_26 ( & F_24 ( V_2 ) -> V_29 ) ;
F_24 ( V_2 ) -> V_28 -> V_30 -- ;
F_24 ( V_2 ) -> V_28 = NULL ;
F_27 ( V_2 ) ;
}
struct V_1 * F_28 ( struct V_1 * V_28 , struct V_18 * V_32 )
{
struct V_33 * V_34 , * V_35 ;
struct V_1 * V_2 ;
F_21 ( L_4 , V_28 ) ;
F_29 (p, n, &bt_sk(parent)->accept_q) {
V_2 = (struct V_1 * ) F_30 ( V_34 , struct V_36 , V_29 ) ;
F_31 ( V_2 ) ;
if ( V_2 -> V_31 == V_37 ) {
F_32 ( V_2 ) ;
F_25 ( V_2 ) ;
continue;
}
if ( V_2 -> V_31 == V_38 || ! V_32 ||
F_33 ( V_39 , & F_24 ( V_28 ) -> V_40 ) ) {
F_25 ( V_2 ) ;
if ( V_32 )
F_34 ( V_2 , V_32 ) ;
F_32 ( V_2 ) ;
return V_2 ;
}
F_32 ( V_2 ) ;
}
return NULL ;
}
int F_35 ( struct V_41 * V_42 , struct V_18 * V_1 ,
struct V_43 * V_44 , T_1 V_45 , int V_40 )
{
int V_46 = V_40 & V_47 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_48 * V_49 ;
T_1 V_50 ;
int V_10 ;
F_21 ( L_5 , V_1 , V_2 , V_45 ) ;
if ( V_40 & ( V_51 ) )
return - V_52 ;
V_49 = F_36 ( V_2 , V_40 , V_46 , & V_10 ) ;
if ( ! V_49 ) {
if ( V_2 -> V_53 & V_54 )
return 0 ;
return V_10 ;
}
V_44 -> V_55 = 0 ;
V_50 = V_49 -> V_45 ;
if ( V_45 < V_50 ) {
V_44 -> V_56 |= V_57 ;
V_50 = V_45 ;
}
F_37 ( V_49 ) ;
V_10 = F_38 ( V_49 , 0 , V_44 -> V_58 , V_50 ) ;
if ( V_10 == 0 )
F_39 ( V_44 , V_2 , V_49 ) ;
F_40 ( V_2 , V_49 ) ;
return V_10 ? : V_50 ;
}
static long F_41 ( struct V_1 * V_2 , long V_59 )
{
F_42 ( V_60 , V_61 ) ;
F_43 ( F_44 ( V_2 ) , & V_60 ) ;
for (; ; ) {
F_45 ( V_62 ) ;
if ( ! F_46 ( & V_2 -> V_63 ) )
break;
if ( V_2 -> V_64 || ( V_2 -> V_53 & V_54 ) )
break;
if ( F_47 ( V_61 ) || ! V_59 )
break;
F_48 ( V_65 , & V_2 -> V_66 -> V_40 ) ;
F_32 ( V_2 ) ;
V_59 = F_49 ( V_59 ) ;
F_31 ( V_2 ) ;
F_50 ( V_65 , & V_2 -> V_66 -> V_40 ) ;
}
F_51 ( V_67 ) ;
F_52 ( F_44 ( V_2 ) , & V_60 ) ;
return V_59 ;
}
int F_53 ( struct V_41 * V_42 , struct V_18 * V_1 ,
struct V_43 * V_44 , T_1 V_68 , int V_40 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_10 = 0 ;
T_1 V_69 , V_50 = 0 ;
long V_59 ;
if ( V_40 & V_51 )
return - V_52 ;
V_44 -> V_55 = 0 ;
F_21 ( L_6 , V_2 , V_68 ) ;
F_31 ( V_2 ) ;
V_69 = F_54 ( V_2 , V_40 & V_70 , V_68 ) ;
V_59 = F_55 ( V_2 , V_40 & V_47 ) ;
do {
struct V_48 * V_49 ;
int V_71 ;
V_49 = F_56 ( & V_2 -> V_63 ) ;
if ( ! V_49 ) {
if ( V_50 >= V_69 )
break;
V_10 = F_57 ( V_2 ) ;
if ( V_10 )
break;
if ( V_2 -> V_53 & V_54 )
break;
V_10 = - V_72 ;
if ( ! V_59 )
break;
V_59 = F_41 ( V_2 , V_59 ) ;
if ( F_47 ( V_61 ) ) {
V_10 = F_58 ( V_59 ) ;
goto V_73;
}
continue;
}
V_71 = F_59 (unsigned int, skb->len, size) ;
if ( F_38 ( V_49 , 0 , V_44 -> V_58 , V_71 ) ) {
F_60 ( & V_2 -> V_63 , V_49 ) ;
if ( ! V_50 )
V_50 = - V_74 ;
break;
}
V_50 += V_71 ;
V_68 -= V_71 ;
F_39 ( V_44 , V_2 , V_49 ) ;
if ( ! ( V_40 & V_75 ) ) {
int V_76 = F_61 ( V_49 ) ;
if ( V_71 <= V_76 ) {
F_62 ( V_49 , V_71 ) ;
} else {
struct V_48 * V_77 ;
F_62 ( V_49 , V_76 ) ;
V_71 -= V_76 ;
F_63 (skb, frag) {
if ( V_71 <= V_77 -> V_45 ) {
V_49 -> V_45 -= V_71 ;
V_49 -> V_78 -= V_71 ;
F_62 ( V_77 , V_71 ) ;
break;
} else if ( V_77 -> V_45 ) {
V_71 -= V_77 -> V_45 ;
V_49 -> V_45 -= V_77 -> V_45 ;
V_49 -> V_78 -= V_77 -> V_45 ;
F_62 ( V_77 , V_77 -> V_45 ) ;
}
}
}
if ( V_49 -> V_45 ) {
F_60 ( & V_2 -> V_63 , V_49 ) ;
break;
}
F_64 ( V_49 ) ;
} else {
F_60 ( & V_2 -> V_63 , V_49 ) ;
break;
}
} while ( V_68 );
V_73:
F_32 ( V_2 ) ;
return V_50 ? : V_10 ;
}
static inline unsigned int F_65 ( struct V_1 * V_28 )
{
struct V_33 * V_34 , * V_35 ;
struct V_1 * V_2 ;
F_29 (p, n, &bt_sk(parent)->accept_q) {
V_2 = (struct V_1 * ) F_30 ( V_34 , struct V_36 , V_29 ) ;
if ( V_2 -> V_31 == V_38 ||
( F_33 ( V_39 , & F_24 ( V_28 ) -> V_40 ) &&
V_2 -> V_31 == V_79 ) )
return V_80 | V_81 ;
}
return 0 ;
}
unsigned int F_66 ( struct V_82 * V_82 , struct V_18 * V_1 ,
T_2 * V_60 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned int V_83 = 0 ;
F_21 ( L_7 , V_1 , V_2 ) ;
F_67 ( V_82 , F_44 ( V_2 ) , V_60 ) ;
if ( V_2 -> V_31 == V_84 )
return F_65 ( V_2 ) ;
if ( V_2 -> V_64 || ! F_46 ( & V_2 -> V_85 ) )
V_83 |= V_86 ;
if ( V_2 -> V_53 & V_54 )
V_83 |= V_87 | V_80 | V_81 ;
if ( V_2 -> V_53 == V_88 )
V_83 |= V_89 ;
if ( ! F_46 ( & V_2 -> V_63 ) )
V_83 |= V_80 | V_81 ;
if ( V_2 -> V_31 == V_37 )
V_83 |= V_89 ;
if ( V_2 -> V_31 == V_90 ||
V_2 -> V_31 == V_79 ||
V_2 -> V_31 == V_91 )
return V_83 ;
if ( ! F_33 ( V_92 , & F_24 ( V_2 ) -> V_40 ) && F_68 ( V_2 ) )
V_83 |= V_93 | V_94 | V_95 ;
else
F_48 ( V_96 , & V_2 -> V_66 -> V_40 ) ;
return V_83 ;
}
int F_69 ( struct V_18 * V_1 , unsigned int V_97 , unsigned long V_98 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_48 * V_49 ;
long V_99 ;
int V_10 ;
F_21 ( L_8 , V_2 , V_97 , V_98 ) ;
switch ( V_97 ) {
case V_100 :
if ( V_2 -> V_31 == V_84 )
return - V_12 ;
V_99 = V_2 -> V_101 - F_70 ( V_2 ) ;
if ( V_99 < 0 )
V_99 = 0 ;
V_10 = F_71 ( V_99 , ( int V_102 * ) V_98 ) ;
break;
case V_103 :
if ( V_2 -> V_31 == V_84 )
return - V_12 ;
F_31 ( V_2 ) ;
V_49 = F_72 ( & V_2 -> V_63 ) ;
V_99 = V_49 ? V_49 -> V_45 : 0 ;
F_32 ( V_2 ) ;
V_10 = F_71 ( V_99 , ( int V_102 * ) V_98 ) ;
break;
case V_104 :
V_10 = F_73 ( V_2 , (struct V_105 V_102 * ) V_98 ) ;
break;
case V_106 :
V_10 = F_74 ( V_2 , (struct V_107 V_102 * ) V_98 ) ;
break;
default:
V_10 = - V_108 ;
break;
}
return V_10 ;
}
int F_75 ( struct V_1 * V_2 , int V_109 , unsigned long V_59 )
{
F_42 ( V_60 , V_61 ) ;
int V_10 = 0 ;
F_21 ( L_9 , V_2 ) ;
F_43 ( F_44 ( V_2 ) , & V_60 ) ;
F_45 ( V_62 ) ;
while ( V_2 -> V_31 != V_109 ) {
if ( ! V_59 ) {
V_10 = - V_110 ;
break;
}
if ( F_47 ( V_61 ) ) {
V_10 = F_58 ( V_59 ) ;
break;
}
F_32 ( V_2 ) ;
V_59 = F_49 ( V_59 ) ;
F_31 ( V_2 ) ;
F_45 ( V_62 ) ;
V_10 = F_57 ( V_2 ) ;
if ( V_10 )
break;
}
F_51 ( V_67 ) ;
F_52 ( F_44 ( V_2 ) , & V_60 ) ;
return V_10 ;
}
static void * F_76 ( struct V_111 * V_112 , T_3 * V_113 )
__acquires( V_112 -> V_114 -> V_25 -> V_26 )
{
struct V_115 * V_116 = V_112 -> V_114 ;
struct V_24 * V_25 = V_116 -> V_25 ;
F_11 ( & V_25 -> V_26 ) ;
return F_77 ( & V_25 -> V_27 , * V_113 ) ;
}
static void * F_78 ( struct V_111 * V_112 , void * V_117 , T_3 * V_113 )
{
struct V_115 * V_116 = V_112 -> V_114 ;
struct V_24 * V_25 = V_116 -> V_25 ;
return F_79 ( V_117 , & V_25 -> V_27 , V_113 ) ;
}
static void F_80 ( struct V_111 * V_112 , void * V_117 )
__releases( V_112 -> V_114 -> V_25 -> V_26 )
{
struct V_115 * V_116 = V_112 -> V_114 ;
struct V_24 * V_25 = V_116 -> V_25 ;
F_15 ( & V_25 -> V_26 ) ;
}
static int F_81 ( struct V_111 * V_112 , void * V_117 )
{
struct V_115 * V_116 = V_112 -> V_114 ;
struct V_24 * V_25 = V_116 -> V_25 ;
T_4 V_118 , V_119 ;
if ( V_117 == V_120 ) {
F_82 ( V_112 , L_10 ) ;
if ( V_25 -> V_121 ) {
F_83 ( V_112 , ' ' ) ;
V_25 -> V_121 ( V_112 , V_117 ) ;
}
F_83 ( V_112 , '\n' ) ;
} else {
struct V_1 * V_2 = F_84 ( V_117 ) ;
struct V_36 * V_122 = F_24 ( V_2 ) ;
F_85 ( & V_118 , & V_122 -> V_123 ) ;
F_85 ( & V_119 , & V_122 -> V_124 ) ;
F_86 ( V_112 , L_11 ,
V_2 ,
F_87 ( & V_2 -> V_125 ) ,
F_88 ( V_2 ) ,
F_70 ( V_2 ) ,
F_89 ( F_90 ( V_112 ) , F_91 ( V_2 ) ) ,
F_92 ( V_2 ) ,
& V_118 ,
& V_119 ,
V_122 -> V_28 ? F_92 ( V_122 -> V_28 ) : 0LU ) ;
if ( V_25 -> V_121 ) {
F_83 ( V_112 , ' ' ) ;
V_25 -> V_121 ( V_112 , V_117 ) ;
}
F_83 ( V_112 , '\n' ) ;
}
return 0 ;
}
static int F_93 ( struct V_126 * V_126 , struct V_82 * V_82 )
{
struct V_24 * V_127 ;
struct V_115 * V_116 ;
V_127 = F_94 ( V_126 ) -> V_128 ;
V_116 = F_95 ( V_82 , & V_129 ,
sizeof( struct V_115 ) ) ;
if ( ! V_116 )
return - V_130 ;
V_116 -> V_25 = V_127 ;
return 0 ;
}
int F_96 ( struct V_131 * V_131 , struct V_17 * V_17 , const char * V_132 ,
struct V_24 * V_127 ,
int (* F_97)( struct V_111 * , void * ) )
{
struct V_133 * V_134 ;
V_127 -> V_121 = F_97 ;
V_127 -> V_135 . V_23 = V_131 ;
V_127 -> V_135 . V_136 = F_93 ;
V_127 -> V_135 . V_137 = V_138 ;
V_127 -> V_135 . V_139 = V_140 ;
V_127 -> V_135 . V_141 = V_142 ;
V_134 = F_98 ( V_17 , V_132 , 0 , & V_127 -> V_135 ) ;
if ( ! V_134 )
return - V_130 ;
V_134 -> V_128 = V_127 ;
return 0 ;
}
void F_99 ( struct V_17 * V_17 , const char * V_132 )
{
F_100 ( V_17 , V_132 ) ;
}
int F_96 ( struct V_131 * V_131 , struct V_17 * V_17 , const char * V_132 ,
struct V_24 * V_127 ,
int (* F_97)( struct V_111 * , void * ) )
{
return 0 ;
}
void F_99 ( struct V_17 * V_17 , const char * V_132 )
{
}
static int T_5 F_101 ( void )
{
int V_10 ;
F_102 ( L_12 , V_143 ) ;
V_10 = F_103 () ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_104 ( & V_144 ) ;
if ( V_10 < 0 ) {
F_105 () ;
return V_10 ;
}
F_102 ( L_13 ) ;
V_10 = F_106 () ;
if ( V_10 < 0 )
goto error;
V_10 = F_107 () ;
if ( V_10 < 0 )
goto V_145;
V_10 = F_108 () ;
if ( V_10 < 0 ) {
F_109 () ;
goto V_145;
}
return 0 ;
V_145:
F_110 () ;
error:
F_111 ( V_146 ) ;
F_105 () ;
return V_10 ;
}
static void T_6 F_112 ( void )
{
F_113 () ;
F_109 () ;
F_110 () ;
F_111 ( V_146 ) ;
F_105 () ;
}
