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
void F_8 ( int V_3 )
{
if ( V_3 < 0 || V_3 >= V_11 )
return;
F_6 ( & V_13 ) ;
V_14 [ V_3 ] = NULL ;
F_7 ( & V_13 ) ;
}
static int F_9 ( struct V_16 * V_16 , struct V_17 * V_1 , int V_3 ,
int V_18 )
{
int V_10 ;
if ( V_16 != & V_19 )
return - V_20 ;
if ( V_3 < 0 || V_3 >= V_11 )
return - V_12 ;
if ( ! V_14 [ V_3 ] )
F_10 ( L_1 , V_3 ) ;
V_10 = - V_21 ;
F_11 ( & V_13 ) ;
if ( V_14 [ V_3 ] && F_12 ( V_14 [ V_3 ] -> V_22 ) ) {
V_10 = V_14 [ V_3 ] -> F_13 ( V_16 , V_1 , V_3 , V_18 ) ;
if ( ! V_10 )
F_1 ( V_1 -> V_2 , V_3 ) ;
F_14 ( V_14 [ V_3 ] -> V_22 ) ;
}
F_15 ( & V_13 ) ;
return V_10 ;
}
void F_16 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
F_6 ( & V_24 -> V_25 ) ;
F_17 ( V_2 , & V_24 -> V_26 ) ;
F_7 ( & V_24 -> V_25 ) ;
}
void F_18 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
F_6 ( & V_24 -> V_25 ) ;
F_19 ( V_2 ) ;
F_7 ( & V_24 -> V_25 ) ;
}
void F_20 ( struct V_1 * V_27 , struct V_1 * V_2 )
{
F_21 ( L_2 , V_27 , V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( & F_24 ( V_2 ) -> V_28 , & F_24 ( V_27 ) -> V_28 ) ;
F_24 ( V_2 ) -> V_27 = V_27 ;
V_27 -> V_29 ++ ;
}
void F_25 ( struct V_1 * V_2 )
{
F_21 ( L_3 , V_2 , V_2 -> V_30 ) ;
F_26 ( & F_24 ( V_2 ) -> V_28 ) ;
F_24 ( V_2 ) -> V_27 -> V_29 -- ;
F_24 ( V_2 ) -> V_27 = NULL ;
F_27 ( V_2 ) ;
}
struct V_1 * F_28 ( struct V_1 * V_27 , struct V_17 * V_31 )
{
struct V_32 * V_33 , * V_34 ;
struct V_1 * V_2 ;
F_21 ( L_4 , V_27 ) ;
F_29 (p, n, &bt_sk(parent)->accept_q) {
V_2 = (struct V_1 * ) F_30 ( V_33 , struct V_35 , V_28 ) ;
F_31 ( V_2 ) ;
if ( V_2 -> V_30 == V_36 ) {
F_32 ( V_2 ) ;
F_25 ( V_2 ) ;
continue;
}
if ( V_2 -> V_30 == V_37 || ! V_31 ||
F_33 ( V_38 , & F_24 ( V_27 ) -> V_39 ) ) {
F_25 ( V_2 ) ;
if ( V_31 )
F_34 ( V_2 , V_31 ) ;
F_32 ( V_2 ) ;
return V_2 ;
}
F_32 ( V_2 ) ;
}
return NULL ;
}
int F_35 ( struct V_40 * V_41 , struct V_17 * V_1 ,
struct V_42 * V_43 , T_1 V_44 , int V_39 )
{
int V_45 = V_39 & V_46 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_47 * V_48 ;
T_1 V_49 ;
int V_10 ;
F_21 ( L_5 , V_1 , V_2 , V_44 ) ;
if ( V_39 & ( V_50 ) )
return - V_51 ;
V_43 -> V_52 = 0 ;
V_48 = F_36 ( V_2 , V_39 , V_45 , & V_10 ) ;
if ( ! V_48 ) {
if ( V_2 -> V_53 & V_54 )
return 0 ;
return V_10 ;
}
V_49 = V_48 -> V_44 ;
if ( V_44 < V_49 ) {
V_43 -> V_55 |= V_56 ;
V_49 = V_44 ;
}
F_37 ( V_48 ) ;
V_10 = F_38 ( V_48 , 0 , V_43 -> V_57 , V_49 ) ;
if ( V_10 == 0 )
F_39 ( V_43 , V_2 , V_48 ) ;
F_40 ( V_2 , V_48 ) ;
return V_10 ? : V_49 ;
}
static long F_41 ( struct V_1 * V_2 , long V_58 )
{
F_42 ( V_59 , V_60 ) ;
F_43 ( F_44 ( V_2 ) , & V_59 ) ;
for (; ; ) {
F_45 ( V_61 ) ;
if ( ! F_46 ( & V_2 -> V_62 ) )
break;
if ( V_2 -> V_63 || ( V_2 -> V_53 & V_54 ) )
break;
if ( F_47 ( V_60 ) || ! V_58 )
break;
F_48 ( V_64 , & V_2 -> V_65 -> V_39 ) ;
F_32 ( V_2 ) ;
V_58 = F_49 ( V_58 ) ;
F_31 ( V_2 ) ;
F_50 ( V_64 , & V_2 -> V_65 -> V_39 ) ;
}
F_51 ( V_66 ) ;
F_52 ( F_44 ( V_2 ) , & V_59 ) ;
return V_58 ;
}
int F_53 ( struct V_40 * V_41 , struct V_17 * V_1 ,
struct V_42 * V_43 , T_1 V_67 , int V_39 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_10 = 0 ;
T_1 V_68 , V_49 = 0 ;
long V_58 ;
if ( V_39 & V_50 )
return - V_51 ;
V_43 -> V_52 = 0 ;
F_21 ( L_6 , V_2 , V_67 ) ;
F_31 ( V_2 ) ;
V_68 = F_54 ( V_2 , V_39 & V_69 , V_67 ) ;
V_58 = F_55 ( V_2 , V_39 & V_46 ) ;
do {
struct V_47 * V_48 ;
int V_70 ;
V_48 = F_56 ( & V_2 -> V_62 ) ;
if ( ! V_48 ) {
if ( V_49 >= V_68 )
break;
V_10 = F_57 ( V_2 ) ;
if ( V_10 )
break;
if ( V_2 -> V_53 & V_54 )
break;
V_10 = - V_71 ;
if ( ! V_58 )
break;
V_58 = F_41 ( V_2 , V_58 ) ;
if ( F_47 ( V_60 ) ) {
V_10 = F_58 ( V_58 ) ;
goto V_72;
}
continue;
}
V_70 = F_59 (unsigned int, skb->len, size) ;
if ( F_38 ( V_48 , 0 , V_43 -> V_57 , V_70 ) ) {
F_60 ( & V_2 -> V_62 , V_48 ) ;
if ( ! V_49 )
V_49 = - V_73 ;
break;
}
V_49 += V_70 ;
V_67 -= V_70 ;
F_39 ( V_43 , V_2 , V_48 ) ;
if ( ! ( V_39 & V_74 ) ) {
int V_75 = F_61 ( V_48 ) ;
if ( V_70 <= V_75 ) {
F_62 ( V_48 , V_70 ) ;
} else {
struct V_47 * V_76 ;
F_62 ( V_48 , V_75 ) ;
V_70 -= V_75 ;
F_63 (skb, frag) {
if ( V_70 <= V_76 -> V_44 ) {
V_48 -> V_44 -= V_70 ;
V_48 -> V_77 -= V_70 ;
F_62 ( V_76 , V_70 ) ;
break;
} else if ( V_76 -> V_44 ) {
V_70 -= V_76 -> V_44 ;
V_48 -> V_44 -= V_76 -> V_44 ;
V_48 -> V_77 -= V_76 -> V_44 ;
F_62 ( V_76 , V_76 -> V_44 ) ;
}
}
}
if ( V_48 -> V_44 ) {
F_60 ( & V_2 -> V_62 , V_48 ) ;
break;
}
F_64 ( V_48 ) ;
} else {
F_60 ( & V_2 -> V_62 , V_48 ) ;
break;
}
} while ( V_67 );
V_72:
F_32 ( V_2 ) ;
return V_49 ? : V_10 ;
}
static inline unsigned int F_65 ( struct V_1 * V_27 )
{
struct V_32 * V_33 , * V_34 ;
struct V_1 * V_2 ;
F_29 (p, n, &bt_sk(parent)->accept_q) {
V_2 = (struct V_1 * ) F_30 ( V_33 , struct V_35 , V_28 ) ;
if ( V_2 -> V_30 == V_37 ||
( F_33 ( V_38 , & F_24 ( V_27 ) -> V_39 ) &&
V_2 -> V_30 == V_78 ) )
return V_79 | V_80 ;
}
return 0 ;
}
unsigned int F_66 ( struct V_81 * V_81 , struct V_17 * V_1 ,
T_2 * V_59 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned int V_82 = 0 ;
F_21 ( L_7 , V_1 , V_2 ) ;
F_67 ( V_81 , F_44 ( V_2 ) , V_59 ) ;
if ( V_2 -> V_30 == V_83 )
return F_65 ( V_2 ) ;
if ( V_2 -> V_63 || ! F_46 ( & V_2 -> V_84 ) )
V_82 |= V_85 |
( F_68 ( V_2 , V_86 ) ? V_87 : 0 ) ;
if ( V_2 -> V_53 & V_54 )
V_82 |= V_88 | V_79 | V_80 ;
if ( V_2 -> V_53 == V_89 )
V_82 |= V_90 ;
if ( ! F_46 ( & V_2 -> V_62 ) )
V_82 |= V_79 | V_80 ;
if ( V_2 -> V_30 == V_36 )
V_82 |= V_90 ;
if ( V_2 -> V_30 == V_91 ||
V_2 -> V_30 == V_78 ||
V_2 -> V_30 == V_92 )
return V_82 ;
if ( ! F_33 ( V_93 , & F_24 ( V_2 ) -> V_39 ) && F_69 ( V_2 ) )
V_82 |= V_94 | V_95 | V_96 ;
else
F_48 ( V_97 , & V_2 -> V_65 -> V_39 ) ;
return V_82 ;
}
int F_70 ( struct V_17 * V_1 , unsigned int V_98 , unsigned long V_99 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_47 * V_48 ;
long V_100 ;
int V_10 ;
F_21 ( L_8 , V_2 , V_98 , V_99 ) ;
switch ( V_98 ) {
case V_101 :
if ( V_2 -> V_30 == V_83 )
return - V_12 ;
V_100 = V_2 -> V_102 - F_71 ( V_2 ) ;
if ( V_100 < 0 )
V_100 = 0 ;
V_10 = F_72 ( V_100 , ( int V_103 * ) V_99 ) ;
break;
case V_104 :
if ( V_2 -> V_30 == V_83 )
return - V_12 ;
F_31 ( V_2 ) ;
V_48 = F_73 ( & V_2 -> V_62 ) ;
V_100 = V_48 ? V_48 -> V_44 : 0 ;
F_32 ( V_2 ) ;
V_10 = F_72 ( V_100 , ( int V_103 * ) V_99 ) ;
break;
case V_105 :
V_10 = F_74 ( V_2 , (struct V_106 V_103 * ) V_99 ) ;
break;
case V_107 :
V_10 = F_75 ( V_2 , (struct V_108 V_103 * ) V_99 ) ;
break;
default:
V_10 = - V_109 ;
break;
}
return V_10 ;
}
int F_76 ( struct V_1 * V_2 , int V_110 , unsigned long V_58 )
{
F_42 ( V_59 , V_60 ) ;
int V_10 = 0 ;
F_21 ( L_9 , V_2 ) ;
F_43 ( F_44 ( V_2 ) , & V_59 ) ;
F_45 ( V_61 ) ;
while ( V_2 -> V_30 != V_110 ) {
if ( ! V_58 ) {
V_10 = - V_111 ;
break;
}
if ( F_47 ( V_60 ) ) {
V_10 = F_58 ( V_58 ) ;
break;
}
F_32 ( V_2 ) ;
V_58 = F_49 ( V_58 ) ;
F_31 ( V_2 ) ;
F_45 ( V_61 ) ;
V_10 = F_57 ( V_2 ) ;
if ( V_10 )
break;
}
F_51 ( V_66 ) ;
F_52 ( F_44 ( V_2 ) , & V_59 ) ;
return V_10 ;
}
static void * F_77 ( struct V_112 * V_113 , T_3 * V_114 )
__acquires( V_113 -> V_115 -> V_24 -> V_25 )
{
struct V_116 * V_117 = V_113 -> V_115 ;
struct V_23 * V_24 = V_117 -> V_24 ;
F_11 ( & V_24 -> V_25 ) ;
return F_78 ( & V_24 -> V_26 , * V_114 ) ;
}
static void * F_79 ( struct V_112 * V_113 , void * V_118 , T_3 * V_114 )
{
struct V_116 * V_117 = V_113 -> V_115 ;
struct V_23 * V_24 = V_117 -> V_24 ;
return F_80 ( V_118 , & V_24 -> V_26 , V_114 ) ;
}
static void F_81 ( struct V_112 * V_113 , void * V_118 )
__releases( V_113 -> V_115 -> V_24 -> V_25 )
{
struct V_116 * V_117 = V_113 -> V_115 ;
struct V_23 * V_24 = V_117 -> V_24 ;
F_15 ( & V_24 -> V_25 ) ;
}
static int F_82 ( struct V_112 * V_113 , void * V_118 )
{
struct V_116 * V_117 = V_113 -> V_115 ;
struct V_23 * V_24 = V_117 -> V_24 ;
if ( V_118 == V_119 ) {
F_83 ( V_113 , L_10 ) ;
if ( V_24 -> V_120 ) {
F_84 ( V_113 , ' ' ) ;
V_24 -> V_120 ( V_113 , V_118 ) ;
}
F_84 ( V_113 , '\n' ) ;
} else {
struct V_1 * V_2 = F_85 ( V_118 ) ;
struct V_35 * V_121 = F_24 ( V_2 ) ;
F_86 ( V_113 ,
L_11 ,
V_2 ,
F_87 ( & V_2 -> V_122 ) ,
F_88 ( V_2 ) ,
F_71 ( V_2 ) ,
F_89 ( F_90 ( V_113 ) , F_91 ( V_2 ) ) ,
F_92 ( V_2 ) ,
& V_121 -> V_123 ,
& V_121 -> V_124 ,
V_121 -> V_27 ? F_92 ( V_121 -> V_27 ) : 0LU ) ;
if ( V_24 -> V_120 ) {
F_84 ( V_113 , ' ' ) ;
V_24 -> V_120 ( V_113 , V_118 ) ;
}
F_84 ( V_113 , '\n' ) ;
}
return 0 ;
}
static int F_93 ( struct V_125 * V_125 , struct V_81 * V_81 )
{
struct V_23 * V_126 ;
struct V_116 * V_117 ;
V_126 = F_94 ( V_125 ) ;
V_117 = F_95 ( V_81 , & V_127 ,
sizeof( struct V_116 ) ) ;
if ( ! V_117 )
return - V_128 ;
V_117 -> V_24 = V_126 ;
return 0 ;
}
int F_96 ( struct V_16 * V_16 , const char * V_129 ,
struct V_23 * V_126 ,
int (* F_97)( struct V_112 * , void * ) )
{
V_126 -> V_120 = F_97 ;
if ( ! F_98 ( V_129 , 0 , V_16 -> V_130 , & V_131 , V_126 ) )
return - V_128 ;
return 0 ;
}
void F_99 ( struct V_16 * V_16 , const char * V_129 )
{
F_100 ( V_129 , V_16 -> V_130 ) ;
}
int F_96 ( struct V_16 * V_16 , const char * V_129 ,
struct V_23 * V_126 ,
int (* F_97)( struct V_112 * , void * ) )
{
return 0 ;
}
void F_99 ( struct V_16 * V_16 , const char * V_129 )
{
}
static int T_4 F_101 ( void )
{
int V_10 ;
F_102 ( L_12 , V_132 ) ;
V_10 = F_103 () ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_104 ( & V_133 ) ;
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
goto V_134;
V_10 = F_108 () ;
if ( V_10 < 0 ) {
F_109 () ;
goto V_134;
}
return 0 ;
V_134:
F_110 () ;
error:
F_111 ( V_135 ) ;
F_105 () ;
return V_10 ;
}
static void T_5 F_112 ( void )
{
F_113 () ;
F_109 () ;
F_110 () ;
F_111 ( V_135 ) ;
F_105 () ;
}
