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
V_48 = F_36 ( V_2 , V_39 , V_45 , & V_10 ) ;
if ( ! V_48 ) {
if ( V_2 -> V_52 & V_53 )
return 0 ;
return V_10 ;
}
V_49 = V_48 -> V_44 ;
if ( V_44 < V_49 ) {
V_43 -> V_54 |= V_55 ;
V_49 = V_44 ;
}
F_37 ( V_48 ) ;
V_10 = F_38 ( V_48 , 0 , V_43 -> V_56 , V_49 ) ;
if ( V_10 == 0 ) {
F_39 ( V_43 , V_2 , V_48 ) ;
if ( F_24 ( V_2 ) -> V_57 )
F_24 ( V_2 ) -> V_57 ( V_48 , V_43 -> V_58 ,
& V_43 -> V_59 ) ;
}
F_40 ( V_2 , V_48 ) ;
return V_10 ? : V_49 ;
}
static long F_41 ( struct V_1 * V_2 , long V_60 )
{
F_42 ( V_61 , V_62 ) ;
F_43 ( F_44 ( V_2 ) , & V_61 ) ;
for (; ; ) {
F_45 ( V_63 ) ;
if ( ! F_46 ( & V_2 -> V_64 ) )
break;
if ( V_2 -> V_65 || ( V_2 -> V_52 & V_53 ) )
break;
if ( F_47 ( V_62 ) || ! V_60 )
break;
F_48 ( V_66 , & V_2 -> V_67 -> V_39 ) ;
F_32 ( V_2 ) ;
V_60 = F_49 ( V_60 ) ;
F_31 ( V_2 ) ;
F_50 ( V_66 , & V_2 -> V_67 -> V_39 ) ;
}
F_51 ( V_68 ) ;
F_52 ( F_44 ( V_2 ) , & V_61 ) ;
return V_60 ;
}
int F_53 ( struct V_40 * V_41 , struct V_17 * V_1 ,
struct V_42 * V_43 , T_1 V_69 , int V_39 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_10 = 0 ;
T_1 V_70 , V_49 = 0 ;
long V_60 ;
if ( V_39 & V_50 )
return - V_51 ;
F_21 ( L_6 , V_2 , V_69 ) ;
F_31 ( V_2 ) ;
V_70 = F_54 ( V_2 , V_39 & V_71 , V_69 ) ;
V_60 = F_55 ( V_2 , V_39 & V_46 ) ;
do {
struct V_47 * V_48 ;
int V_72 ;
V_48 = F_56 ( & V_2 -> V_64 ) ;
if ( ! V_48 ) {
if ( V_49 >= V_70 )
break;
V_10 = F_57 ( V_2 ) ;
if ( V_10 )
break;
if ( V_2 -> V_52 & V_53 )
break;
V_10 = - V_73 ;
if ( ! V_60 )
break;
V_60 = F_41 ( V_2 , V_60 ) ;
if ( F_47 ( V_62 ) ) {
V_10 = F_58 ( V_60 ) ;
goto V_74;
}
continue;
}
V_72 = F_59 (unsigned int, skb->len, size) ;
if ( F_38 ( V_48 , 0 , V_43 -> V_56 , V_72 ) ) {
F_60 ( & V_2 -> V_64 , V_48 ) ;
if ( ! V_49 )
V_49 = - V_75 ;
break;
}
V_49 += V_72 ;
V_69 -= V_72 ;
F_39 ( V_43 , V_2 , V_48 ) ;
if ( ! ( V_39 & V_76 ) ) {
int V_77 = F_61 ( V_48 ) ;
if ( V_72 <= V_77 ) {
F_62 ( V_48 , V_72 ) ;
} else {
struct V_47 * V_78 ;
F_62 ( V_48 , V_77 ) ;
V_72 -= V_77 ;
F_63 (skb, frag) {
if ( V_72 <= V_78 -> V_44 ) {
V_48 -> V_44 -= V_72 ;
V_48 -> V_79 -= V_72 ;
F_62 ( V_78 , V_72 ) ;
break;
} else if ( V_78 -> V_44 ) {
V_72 -= V_78 -> V_44 ;
V_48 -> V_44 -= V_78 -> V_44 ;
V_48 -> V_79 -= V_78 -> V_44 ;
F_62 ( V_78 , V_78 -> V_44 ) ;
}
}
}
if ( V_48 -> V_44 ) {
F_60 ( & V_2 -> V_64 , V_48 ) ;
break;
}
F_64 ( V_48 ) ;
} else {
F_60 ( & V_2 -> V_64 , V_48 ) ;
break;
}
} while ( V_69 );
V_74:
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
V_2 -> V_30 == V_80 ) )
return V_81 | V_82 ;
}
return 0 ;
}
unsigned int F_66 ( struct V_83 * V_83 , struct V_17 * V_1 ,
T_2 * V_61 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned int V_84 = 0 ;
F_21 ( L_7 , V_1 , V_2 ) ;
F_67 ( V_83 , F_44 ( V_2 ) , V_61 ) ;
if ( V_2 -> V_30 == V_85 )
return F_65 ( V_2 ) ;
if ( V_2 -> V_65 || ! F_46 ( & V_2 -> V_86 ) )
V_84 |= V_87 |
( F_68 ( V_2 , V_88 ) ? V_89 : 0 ) ;
if ( V_2 -> V_52 & V_53 )
V_84 |= V_90 | V_81 | V_82 ;
if ( V_2 -> V_52 == V_91 )
V_84 |= V_92 ;
if ( ! F_46 ( & V_2 -> V_64 ) )
V_84 |= V_81 | V_82 ;
if ( V_2 -> V_30 == V_36 )
V_84 |= V_92 ;
if ( V_2 -> V_30 == V_93 ||
V_2 -> V_30 == V_80 ||
V_2 -> V_30 == V_94 )
return V_84 ;
if ( ! F_33 ( V_95 , & F_24 ( V_2 ) -> V_39 ) && F_69 ( V_2 ) )
V_84 |= V_96 | V_97 | V_98 ;
else
F_48 ( V_99 , & V_2 -> V_67 -> V_39 ) ;
return V_84 ;
}
int F_70 ( struct V_17 * V_1 , unsigned int V_100 , unsigned long V_101 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_47 * V_48 ;
long V_102 ;
int V_10 ;
F_21 ( L_8 , V_2 , V_100 , V_101 ) ;
switch ( V_100 ) {
case V_103 :
if ( V_2 -> V_30 == V_85 )
return - V_12 ;
V_102 = V_2 -> V_104 - F_71 ( V_2 ) ;
if ( V_102 < 0 )
V_102 = 0 ;
V_10 = F_72 ( V_102 , ( int V_105 * ) V_101 ) ;
break;
case V_106 :
if ( V_2 -> V_30 == V_85 )
return - V_12 ;
F_31 ( V_2 ) ;
V_48 = F_73 ( & V_2 -> V_64 ) ;
V_102 = V_48 ? V_48 -> V_44 : 0 ;
F_32 ( V_2 ) ;
V_10 = F_72 ( V_102 , ( int V_105 * ) V_101 ) ;
break;
case V_107 :
V_10 = F_74 ( V_2 , (struct V_108 V_105 * ) V_101 ) ;
break;
case V_109 :
V_10 = F_75 ( V_2 , (struct V_110 V_105 * ) V_101 ) ;
break;
default:
V_10 = - V_111 ;
break;
}
return V_10 ;
}
int F_76 ( struct V_1 * V_2 , int V_112 , unsigned long V_60 )
{
F_42 ( V_61 , V_62 ) ;
int V_10 = 0 ;
F_21 ( L_9 , V_2 ) ;
F_43 ( F_44 ( V_2 ) , & V_61 ) ;
F_45 ( V_63 ) ;
while ( V_2 -> V_30 != V_112 ) {
if ( ! V_60 ) {
V_10 = - V_113 ;
break;
}
if ( F_47 ( V_62 ) ) {
V_10 = F_58 ( V_60 ) ;
break;
}
F_32 ( V_2 ) ;
V_60 = F_49 ( V_60 ) ;
F_31 ( V_2 ) ;
F_45 ( V_63 ) ;
V_10 = F_57 ( V_2 ) ;
if ( V_10 )
break;
}
F_51 ( V_68 ) ;
F_52 ( F_44 ( V_2 ) , & V_61 ) ;
return V_10 ;
}
int F_77 ( struct V_1 * V_2 , unsigned long V_39 )
{
F_42 ( V_61 , V_62 ) ;
unsigned long V_60 ;
int V_10 = 0 ;
F_21 ( L_9 , V_2 ) ;
V_60 = F_78 ( V_2 , V_39 & V_114 ) ;
F_43 ( F_44 ( V_2 ) , & V_61 ) ;
F_45 ( V_63 ) ;
while ( F_33 ( V_95 , & F_24 ( V_2 ) -> V_39 ) ) {
if ( ! V_60 ) {
V_10 = - V_73 ;
break;
}
if ( F_47 ( V_62 ) ) {
V_10 = F_58 ( V_60 ) ;
break;
}
F_32 ( V_2 ) ;
V_60 = F_49 ( V_60 ) ;
F_31 ( V_2 ) ;
F_45 ( V_63 ) ;
V_10 = F_57 ( V_2 ) ;
if ( V_10 )
break;
}
F_51 ( V_68 ) ;
F_52 ( F_44 ( V_2 ) , & V_61 ) ;
return V_10 ;
}
static void * F_79 ( struct V_115 * V_116 , T_3 * V_117 )
__acquires( V_116 -> V_118 -> V_24 -> V_25 )
{
struct V_119 * V_120 = V_116 -> V_118 ;
struct V_23 * V_24 = V_120 -> V_24 ;
F_11 ( & V_24 -> V_25 ) ;
return F_80 ( & V_24 -> V_26 , * V_117 ) ;
}
static void * F_81 ( struct V_115 * V_116 , void * V_121 , T_3 * V_117 )
{
struct V_119 * V_120 = V_116 -> V_118 ;
struct V_23 * V_24 = V_120 -> V_24 ;
return F_82 ( V_121 , & V_24 -> V_26 , V_117 ) ;
}
static void F_83 ( struct V_115 * V_116 , void * V_121 )
__releases( V_116 -> V_118 -> V_24 -> V_25 )
{
struct V_119 * V_120 = V_116 -> V_118 ;
struct V_23 * V_24 = V_120 -> V_24 ;
F_15 ( & V_24 -> V_25 ) ;
}
static int F_84 ( struct V_115 * V_116 , void * V_121 )
{
struct V_119 * V_120 = V_116 -> V_118 ;
struct V_23 * V_24 = V_120 -> V_24 ;
if ( V_121 == V_122 ) {
F_85 ( V_116 , L_10 ) ;
if ( V_24 -> V_123 ) {
F_86 ( V_116 , ' ' ) ;
V_24 -> V_123 ( V_116 , V_121 ) ;
}
F_86 ( V_116 , '\n' ) ;
} else {
struct V_1 * V_2 = F_87 ( V_121 ) ;
struct V_35 * V_124 = F_24 ( V_2 ) ;
F_88 ( V_116 ,
L_11 ,
V_2 ,
F_89 ( & V_2 -> V_125 ) ,
F_90 ( V_2 ) ,
F_71 ( V_2 ) ,
F_91 ( F_92 ( V_116 ) , F_93 ( V_2 ) ) ,
F_94 ( V_2 ) ,
V_124 -> V_27 ? F_94 ( V_124 -> V_27 ) : 0LU ) ;
if ( V_24 -> V_123 ) {
F_86 ( V_116 , ' ' ) ;
V_24 -> V_123 ( V_116 , V_121 ) ;
}
F_86 ( V_116 , '\n' ) ;
}
return 0 ;
}
static int F_95 ( struct V_126 * V_126 , struct V_83 * V_83 )
{
struct V_23 * V_127 ;
struct V_119 * V_120 ;
V_127 = F_96 ( V_126 ) ;
V_120 = F_97 ( V_83 , & V_128 ,
sizeof( struct V_119 ) ) ;
if ( ! V_120 )
return - V_129 ;
V_120 -> V_24 = V_127 ;
return 0 ;
}
int F_98 ( struct V_16 * V_16 , const char * V_130 ,
struct V_23 * V_127 ,
int (* F_99)( struct V_115 * , void * ) )
{
V_127 -> V_123 = F_99 ;
if ( ! F_100 ( V_130 , 0 , V_16 -> V_131 , & V_132 , V_127 ) )
return - V_129 ;
return 0 ;
}
void F_101 ( struct V_16 * V_16 , const char * V_130 )
{
F_102 ( V_130 , V_16 -> V_131 ) ;
}
int F_98 ( struct V_16 * V_16 , const char * V_130 ,
struct V_23 * V_127 ,
int (* F_99)( struct V_115 * , void * ) )
{
return 0 ;
}
void F_101 ( struct V_16 * V_16 , const char * V_130 )
{
}
static int T_4 F_103 ( void )
{
int V_10 ;
F_104 ( L_12 , V_133 ) ;
V_134 = F_105 ( L_13 , NULL ) ;
V_10 = F_106 () ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_107 ( & V_135 ) ;
if ( V_10 < 0 ) {
F_108 () ;
return V_10 ;
}
F_104 ( L_14 ) ;
V_10 = F_109 () ;
if ( V_10 < 0 )
goto error;
V_10 = F_110 () ;
if ( V_10 < 0 )
goto V_136;
V_10 = F_111 () ;
if ( V_10 < 0 ) {
F_112 () ;
goto V_136;
}
return 0 ;
V_136:
F_113 () ;
error:
F_114 ( V_137 ) ;
F_108 () ;
return V_10 ;
}
static void T_5 F_115 ( void )
{
F_116 () ;
F_112 () ;
F_113 () ;
F_114 ( V_137 ) ;
F_108 () ;
F_117 ( V_134 ) ;
}
