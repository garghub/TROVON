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
int F_35 ( struct V_17 * V_1 , struct V_40 * V_41 , T_1 V_42 ,
int V_39 )
{
int V_43 = V_39 & V_44 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 ;
T_1 V_47 ;
int V_10 ;
F_21 ( L_5 , V_1 , V_2 , V_42 ) ;
if ( V_39 & V_48 )
return - V_49 ;
V_46 = F_36 ( V_2 , V_39 , V_43 , & V_10 ) ;
if ( ! V_46 ) {
if ( V_2 -> V_50 & V_51 )
return 0 ;
return V_10 ;
}
V_47 = V_46 -> V_42 ;
if ( V_42 < V_47 ) {
V_41 -> V_52 |= V_53 ;
V_47 = V_42 ;
}
F_37 ( V_46 ) ;
V_10 = F_38 ( V_46 , 0 , V_41 , V_47 ) ;
if ( V_10 == 0 ) {
F_39 ( V_41 , V_2 , V_46 ) ;
if ( F_24 ( V_2 ) -> V_54 )
F_24 ( V_2 ) -> V_54 ( V_46 , V_41 -> V_55 ,
& V_41 -> V_56 ) ;
}
F_40 ( V_2 , V_46 ) ;
return V_10 ? : V_47 ;
}
static long F_41 ( struct V_1 * V_2 , long V_57 )
{
F_42 ( V_58 , V_59 ) ;
F_43 ( F_44 ( V_2 ) , & V_58 ) ;
for (; ; ) {
F_45 ( V_60 ) ;
if ( ! F_46 ( & V_2 -> V_61 ) )
break;
if ( V_2 -> V_62 || ( V_2 -> V_50 & V_51 ) )
break;
if ( F_47 ( V_59 ) || ! V_57 )
break;
F_48 ( V_63 , V_2 ) ;
F_32 ( V_2 ) ;
V_57 = F_49 ( V_57 ) ;
F_31 ( V_2 ) ;
F_50 ( V_63 , V_2 ) ;
}
F_51 ( V_64 ) ;
F_52 ( F_44 ( V_2 ) , & V_58 ) ;
return V_57 ;
}
int F_53 ( struct V_17 * V_1 , struct V_40 * V_41 ,
T_1 V_65 , int V_39 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_10 = 0 ;
T_1 V_66 , V_47 = 0 ;
long V_57 ;
if ( V_39 & V_48 )
return - V_49 ;
F_21 ( L_6 , V_2 , V_65 ) ;
F_31 ( V_2 ) ;
V_66 = F_54 ( V_2 , V_39 & V_67 , V_65 ) ;
V_57 = F_55 ( V_2 , V_39 & V_44 ) ;
do {
struct V_45 * V_46 ;
int V_68 ;
V_46 = F_56 ( & V_2 -> V_61 ) ;
if ( ! V_46 ) {
if ( V_47 >= V_66 )
break;
V_10 = F_57 ( V_2 ) ;
if ( V_10 )
break;
if ( V_2 -> V_50 & V_51 )
break;
V_10 = - V_69 ;
if ( ! V_57 )
break;
V_57 = F_41 ( V_2 , V_57 ) ;
if ( F_47 ( V_59 ) ) {
V_10 = F_58 ( V_57 ) ;
goto V_70;
}
continue;
}
V_68 = F_59 (unsigned int, skb->len, size) ;
if ( F_38 ( V_46 , 0 , V_41 , V_68 ) ) {
F_60 ( & V_2 -> V_61 , V_46 ) ;
if ( ! V_47 )
V_47 = - V_71 ;
break;
}
V_47 += V_68 ;
V_65 -= V_68 ;
F_39 ( V_41 , V_2 , V_46 ) ;
if ( ! ( V_39 & V_72 ) ) {
int V_73 = F_61 ( V_46 ) ;
if ( V_68 <= V_73 ) {
F_62 ( V_46 , V_68 ) ;
} else {
struct V_45 * V_74 ;
F_62 ( V_46 , V_73 ) ;
V_68 -= V_73 ;
F_63 (skb, frag) {
if ( V_68 <= V_74 -> V_42 ) {
V_46 -> V_42 -= V_68 ;
V_46 -> V_75 -= V_68 ;
F_62 ( V_74 , V_68 ) ;
break;
} else if ( V_74 -> V_42 ) {
V_68 -= V_74 -> V_42 ;
V_46 -> V_42 -= V_74 -> V_42 ;
V_46 -> V_75 -= V_74 -> V_42 ;
F_62 ( V_74 , V_74 -> V_42 ) ;
}
}
}
if ( V_46 -> V_42 ) {
F_60 ( & V_2 -> V_61 , V_46 ) ;
break;
}
F_64 ( V_46 ) ;
} else {
F_60 ( & V_2 -> V_61 , V_46 ) ;
break;
}
} while ( V_65 );
V_70:
F_32 ( V_2 ) ;
return V_47 ? : V_10 ;
}
static inline unsigned int F_65 ( struct V_1 * V_27 )
{
struct V_32 * V_33 , * V_34 ;
struct V_1 * V_2 ;
F_29 (p, n, &bt_sk(parent)->accept_q) {
V_2 = (struct V_1 * ) F_30 ( V_33 , struct V_35 , V_28 ) ;
if ( V_2 -> V_30 == V_37 ||
( F_33 ( V_38 , & F_24 ( V_27 ) -> V_39 ) &&
V_2 -> V_30 == V_76 ) )
return V_77 | V_78 ;
}
return 0 ;
}
unsigned int F_66 ( struct V_79 * V_79 , struct V_17 * V_1 ,
T_2 * V_58 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned int V_80 = 0 ;
F_21 ( L_7 , V_1 , V_2 ) ;
F_67 ( V_79 , F_44 ( V_2 ) , V_58 ) ;
if ( V_2 -> V_30 == V_81 )
return F_65 ( V_2 ) ;
if ( V_2 -> V_62 || ! F_46 ( & V_2 -> V_82 ) )
V_80 |= V_83 |
( F_68 ( V_2 , V_84 ) ? V_85 : 0 ) ;
if ( V_2 -> V_50 & V_51 )
V_80 |= V_86 | V_77 | V_78 ;
if ( V_2 -> V_50 == V_87 )
V_80 |= V_88 ;
if ( ! F_46 ( & V_2 -> V_61 ) )
V_80 |= V_77 | V_78 ;
if ( V_2 -> V_30 == V_36 )
V_80 |= V_88 ;
if ( V_2 -> V_30 == V_89 ||
V_2 -> V_30 == V_76 ||
V_2 -> V_30 == V_90 )
return V_80 ;
if ( ! F_33 ( V_91 , & F_24 ( V_2 ) -> V_39 ) && F_69 ( V_2 ) )
V_80 |= V_92 | V_93 | V_94 ;
else
F_48 ( V_95 , V_2 ) ;
return V_80 ;
}
int F_70 ( struct V_17 * V_1 , unsigned int V_96 , unsigned long V_97 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 ;
long V_98 ;
int V_10 ;
F_21 ( L_8 , V_2 , V_96 , V_97 ) ;
switch ( V_96 ) {
case V_99 :
if ( V_2 -> V_30 == V_81 )
return - V_12 ;
V_98 = V_2 -> V_100 - F_71 ( V_2 ) ;
if ( V_98 < 0 )
V_98 = 0 ;
V_10 = F_72 ( V_98 , ( int V_101 * ) V_97 ) ;
break;
case V_102 :
if ( V_2 -> V_30 == V_81 )
return - V_12 ;
F_31 ( V_2 ) ;
V_46 = F_73 ( & V_2 -> V_61 ) ;
V_98 = V_46 ? V_46 -> V_42 : 0 ;
F_32 ( V_2 ) ;
V_10 = F_72 ( V_98 , ( int V_101 * ) V_97 ) ;
break;
case V_103 :
V_10 = F_74 ( V_2 , (struct V_104 V_101 * ) V_97 ) ;
break;
case V_105 :
V_10 = F_75 ( V_2 , (struct V_106 V_101 * ) V_97 ) ;
break;
default:
V_10 = - V_107 ;
break;
}
return V_10 ;
}
int F_76 ( struct V_1 * V_2 , int V_108 , unsigned long V_57 )
{
F_42 ( V_58 , V_59 ) ;
int V_10 = 0 ;
F_21 ( L_9 , V_2 ) ;
F_43 ( F_44 ( V_2 ) , & V_58 ) ;
F_45 ( V_60 ) ;
while ( V_2 -> V_30 != V_108 ) {
if ( ! V_57 ) {
V_10 = - V_109 ;
break;
}
if ( F_47 ( V_59 ) ) {
V_10 = F_58 ( V_57 ) ;
break;
}
F_32 ( V_2 ) ;
V_57 = F_49 ( V_57 ) ;
F_31 ( V_2 ) ;
F_45 ( V_60 ) ;
V_10 = F_57 ( V_2 ) ;
if ( V_10 )
break;
}
F_51 ( V_64 ) ;
F_52 ( F_44 ( V_2 ) , & V_58 ) ;
return V_10 ;
}
int F_77 ( struct V_1 * V_2 , unsigned long V_39 )
{
F_42 ( V_58 , V_59 ) ;
unsigned long V_57 ;
int V_10 = 0 ;
F_21 ( L_9 , V_2 ) ;
V_57 = F_78 ( V_2 , V_39 & V_110 ) ;
F_43 ( F_44 ( V_2 ) , & V_58 ) ;
F_45 ( V_60 ) ;
while ( F_33 ( V_91 , & F_24 ( V_2 ) -> V_39 ) ) {
if ( ! V_57 ) {
V_10 = - V_69 ;
break;
}
if ( F_47 ( V_59 ) ) {
V_10 = F_58 ( V_57 ) ;
break;
}
F_32 ( V_2 ) ;
V_57 = F_49 ( V_57 ) ;
F_31 ( V_2 ) ;
F_45 ( V_60 ) ;
V_10 = F_57 ( V_2 ) ;
if ( V_10 )
break;
}
F_51 ( V_64 ) ;
F_52 ( F_44 ( V_2 ) , & V_58 ) ;
return V_10 ;
}
static void * F_79 ( struct V_111 * V_112 , T_3 * V_113 )
__acquires( V_112 -> V_114 -> V_24 -> V_25 )
{
struct V_115 * V_116 = V_112 -> V_114 ;
struct V_23 * V_24 = V_116 -> V_24 ;
F_11 ( & V_24 -> V_25 ) ;
return F_80 ( & V_24 -> V_26 , * V_113 ) ;
}
static void * F_81 ( struct V_111 * V_112 , void * V_117 , T_3 * V_113 )
{
struct V_115 * V_116 = V_112 -> V_114 ;
struct V_23 * V_24 = V_116 -> V_24 ;
return F_82 ( V_117 , & V_24 -> V_26 , V_113 ) ;
}
static void F_83 ( struct V_111 * V_112 , void * V_117 )
__releases( V_112 -> V_114 -> V_24 -> V_25 )
{
struct V_115 * V_116 = V_112 -> V_114 ;
struct V_23 * V_24 = V_116 -> V_24 ;
F_15 ( & V_24 -> V_25 ) ;
}
static int F_84 ( struct V_111 * V_112 , void * V_117 )
{
struct V_115 * V_116 = V_112 -> V_114 ;
struct V_23 * V_24 = V_116 -> V_24 ;
if ( V_117 == V_118 ) {
F_85 ( V_112 , L_10 ) ;
if ( V_24 -> V_119 ) {
F_86 ( V_112 , ' ' ) ;
V_24 -> V_119 ( V_112 , V_117 ) ;
}
F_86 ( V_112 , '\n' ) ;
} else {
struct V_1 * V_2 = F_87 ( V_117 ) ;
struct V_35 * V_120 = F_24 ( V_2 ) ;
F_88 ( V_112 ,
L_11 ,
V_2 ,
F_89 ( & V_2 -> V_121 ) ,
F_90 ( V_2 ) ,
F_71 ( V_2 ) ,
F_91 ( F_92 ( V_112 ) , F_93 ( V_2 ) ) ,
F_94 ( V_2 ) ,
V_120 -> V_27 ? F_94 ( V_120 -> V_27 ) : 0LU ) ;
if ( V_24 -> V_119 ) {
F_86 ( V_112 , ' ' ) ;
V_24 -> V_119 ( V_112 , V_117 ) ;
}
F_86 ( V_112 , '\n' ) ;
}
return 0 ;
}
static int F_95 ( struct V_122 * V_122 , struct V_79 * V_79 )
{
struct V_23 * V_123 ;
struct V_115 * V_116 ;
V_123 = F_96 ( V_122 ) ;
V_116 = F_97 ( V_79 , & V_124 ,
sizeof( struct V_115 ) ) ;
if ( ! V_116 )
return - V_125 ;
V_116 -> V_24 = V_123 ;
return 0 ;
}
int F_98 ( struct V_16 * V_16 , const char * V_126 ,
struct V_23 * V_123 ,
int (* F_99)( struct V_111 * , void * ) )
{
V_123 -> V_119 = F_99 ;
if ( ! F_100 ( V_126 , 0 , V_16 -> V_127 , & V_128 , V_123 ) )
return - V_125 ;
return 0 ;
}
void F_101 ( struct V_16 * V_16 , const char * V_126 )
{
F_102 ( V_126 , V_16 -> V_127 ) ;
}
int F_98 ( struct V_16 * V_16 , const char * V_126 ,
struct V_23 * V_123 ,
int (* F_99)( struct V_111 * , void * ) )
{
return 0 ;
}
void F_101 ( struct V_16 * V_16 , const char * V_126 )
{
}
static int T_4 F_103 ( void )
{
int V_10 ;
F_104 ( sizeof( struct V_129 ) ) ;
F_105 ( L_12 , V_130 ) ;
V_10 = F_106 () ;
if ( V_10 < 0 )
return V_10 ;
V_131 = F_107 ( L_13 , NULL ) ;
V_10 = F_108 () ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_109 ( & V_132 ) ;
if ( V_10 < 0 ) {
F_110 () ;
return V_10 ;
}
F_105 ( L_14 ) ;
V_10 = F_111 () ;
if ( V_10 < 0 )
goto error;
V_10 = F_112 () ;
if ( V_10 < 0 )
goto V_133;
V_10 = F_113 () ;
if ( V_10 < 0 ) {
F_114 () ;
goto V_133;
}
V_10 = F_115 () ;
if ( V_10 < 0 ) {
F_116 () ;
F_114 () ;
goto V_133;
}
return 0 ;
V_133:
F_117 () ;
error:
F_118 ( V_134 ) ;
F_110 () ;
return V_10 ;
}
static void T_5 F_119 ( void )
{
F_120 () ;
F_116 () ;
F_114 () ;
F_117 () ;
F_118 ( V_134 ) ;
F_110 () ;
F_121 ( V_131 ) ;
}
