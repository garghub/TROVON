void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( ! V_2 ) ;
F_2 ( ! F_3 ( V_2 ) ) ;
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
F_29 (s, n, &bt_sk(parent)->accept_q, accept_q) {
V_2 = (struct V_1 * ) V_33 ;
F_30 ( V_2 ) ;
if ( V_2 -> V_30 == V_35 ) {
F_25 ( V_2 ) ;
F_31 ( V_2 ) ;
continue;
}
if ( V_2 -> V_30 == V_36 || ! V_31 ||
F_32 ( V_37 , & F_24 ( V_27 ) -> V_38 ) ) {
F_25 ( V_2 ) ;
if ( V_31 )
F_33 ( V_2 , V_31 ) ;
F_31 ( V_2 ) ;
return V_2 ;
}
F_31 ( V_2 ) ;
}
return NULL ;
}
int F_34 ( struct V_17 * V_1 , struct V_39 * V_40 , T_1 V_41 ,
int V_38 )
{
int V_42 = V_38 & V_43 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_44 * V_45 ;
T_1 V_46 ;
T_1 V_47 ;
int V_10 ;
F_21 ( L_5 , V_1 , V_2 , V_41 ) ;
if ( V_38 & V_48 )
return - V_49 ;
V_45 = F_35 ( V_2 , V_38 , V_42 , & V_10 ) ;
if ( ! V_45 ) {
if ( V_2 -> V_50 & V_51 )
return 0 ;
return V_10 ;
}
V_47 = V_45 -> V_41 ;
V_46 = V_45 -> V_41 ;
if ( V_41 < V_46 ) {
V_40 -> V_52 |= V_53 ;
V_46 = V_41 ;
}
F_36 ( V_45 ) ;
V_10 = F_37 ( V_45 , 0 , V_40 , V_46 ) ;
if ( V_10 == 0 ) {
F_38 ( V_40 , V_2 , V_45 ) ;
if ( F_24 ( V_2 ) -> V_54 )
F_24 ( V_2 ) -> V_54 ( V_45 , V_40 -> V_55 ,
& V_40 -> V_56 ) ;
}
F_39 ( V_2 , V_45 ) ;
if ( V_38 & V_53 )
V_46 = V_47 ;
return V_10 ? : V_46 ;
}
static long F_40 ( struct V_1 * V_2 , long V_57 )
{
F_41 ( V_58 , V_59 ) ;
F_42 ( F_43 ( V_2 ) , & V_58 ) ;
for (; ; ) {
F_44 ( V_60 ) ;
if ( ! F_45 ( & V_2 -> V_61 ) )
break;
if ( V_2 -> V_62 || ( V_2 -> V_50 & V_51 ) )
break;
if ( F_46 ( V_59 ) || ! V_57 )
break;
F_47 ( V_63 , V_2 ) ;
F_31 ( V_2 ) ;
V_57 = F_48 ( V_57 ) ;
F_30 ( V_2 ) ;
F_49 ( V_63 , V_2 ) ;
}
F_50 ( V_64 ) ;
F_51 ( F_43 ( V_2 ) , & V_58 ) ;
return V_57 ;
}
int F_52 ( struct V_17 * V_1 , struct V_39 * V_40 ,
T_1 V_65 , int V_38 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_10 = 0 ;
T_1 V_66 , V_46 = 0 ;
long V_57 ;
if ( V_38 & V_48 )
return - V_49 ;
F_21 ( L_6 , V_2 , V_65 ) ;
F_30 ( V_2 ) ;
V_66 = F_53 ( V_2 , V_38 & V_67 , V_65 ) ;
V_57 = F_54 ( V_2 , V_38 & V_43 ) ;
do {
struct V_44 * V_45 ;
int V_68 ;
V_45 = F_55 ( & V_2 -> V_61 ) ;
if ( ! V_45 ) {
if ( V_46 >= V_66 )
break;
V_10 = F_56 ( V_2 ) ;
if ( V_10 )
break;
if ( V_2 -> V_50 & V_51 )
break;
V_10 = - V_69 ;
if ( ! V_57 )
break;
V_57 = F_40 ( V_2 , V_57 ) ;
if ( F_46 ( V_59 ) ) {
V_10 = F_57 ( V_57 ) ;
goto V_70;
}
continue;
}
V_68 = F_58 (unsigned int, skb->len, size) ;
if ( F_37 ( V_45 , 0 , V_40 , V_68 ) ) {
F_59 ( & V_2 -> V_61 , V_45 ) ;
if ( ! V_46 )
V_46 = - V_71 ;
break;
}
V_46 += V_68 ;
V_65 -= V_68 ;
F_38 ( V_40 , V_2 , V_45 ) ;
if ( ! ( V_38 & V_72 ) ) {
int V_73 = F_60 ( V_45 ) ;
if ( V_68 <= V_73 ) {
F_61 ( V_45 , V_68 ) ;
} else {
struct V_44 * V_74 ;
F_61 ( V_45 , V_73 ) ;
V_68 -= V_73 ;
F_62 (skb, frag) {
if ( V_68 <= V_74 -> V_41 ) {
V_45 -> V_41 -= V_68 ;
V_45 -> V_75 -= V_68 ;
F_61 ( V_74 , V_68 ) ;
break;
} else if ( V_74 -> V_41 ) {
V_68 -= V_74 -> V_41 ;
V_45 -> V_41 -= V_74 -> V_41 ;
V_45 -> V_75 -= V_74 -> V_41 ;
F_61 ( V_74 , V_74 -> V_41 ) ;
}
}
}
if ( V_45 -> V_41 ) {
F_59 ( & V_2 -> V_61 , V_45 ) ;
break;
}
F_63 ( V_45 ) ;
} else {
F_59 ( & V_2 -> V_61 , V_45 ) ;
break;
}
} while ( V_65 );
V_70:
F_31 ( V_2 ) ;
return V_46 ? : V_10 ;
}
static inline unsigned int F_64 ( struct V_1 * V_27 )
{
struct V_32 * V_33 , * V_34 ;
struct V_1 * V_2 ;
F_29 (s, n, &bt_sk(parent)->accept_q, accept_q) {
V_2 = (struct V_1 * ) V_33 ;
if ( V_2 -> V_30 == V_36 ||
( F_32 ( V_37 , & F_24 ( V_27 ) -> V_38 ) &&
V_2 -> V_30 == V_76 ) )
return V_77 | V_78 ;
}
return 0 ;
}
unsigned int F_65 ( struct V_79 * V_79 , struct V_17 * V_1 ,
T_2 * V_58 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned int V_80 = 0 ;
F_21 ( L_7 , V_1 , V_2 ) ;
F_66 ( V_79 , F_43 ( V_2 ) , V_58 ) ;
if ( V_2 -> V_30 == V_81 )
return F_64 ( V_2 ) ;
if ( V_2 -> V_62 || ! F_45 ( & V_2 -> V_82 ) )
V_80 |= V_83 |
( F_67 ( V_2 , V_84 ) ? V_85 : 0 ) ;
if ( V_2 -> V_50 & V_51 )
V_80 |= V_86 | V_77 | V_78 ;
if ( V_2 -> V_50 == V_87 )
V_80 |= V_88 ;
if ( ! F_45 ( & V_2 -> V_61 ) )
V_80 |= V_77 | V_78 ;
if ( V_2 -> V_30 == V_35 )
V_80 |= V_88 ;
if ( V_2 -> V_30 == V_89 ||
V_2 -> V_30 == V_76 ||
V_2 -> V_30 == V_90 )
return V_80 ;
if ( ! F_32 ( V_91 , & F_24 ( V_2 ) -> V_38 ) && F_68 ( V_2 ) )
V_80 |= V_92 | V_93 | V_94 ;
else
F_47 ( V_95 , V_2 ) ;
return V_80 ;
}
int F_69 ( struct V_17 * V_1 , unsigned int V_96 , unsigned long V_97 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_44 * V_45 ;
long V_98 ;
int V_10 ;
F_21 ( L_8 , V_2 , V_96 , V_97 ) ;
switch ( V_96 ) {
case V_99 :
if ( V_2 -> V_30 == V_81 )
return - V_12 ;
V_98 = V_2 -> V_100 - F_70 ( V_2 ) ;
if ( V_98 < 0 )
V_98 = 0 ;
V_10 = F_71 ( V_98 , ( int V_101 * ) V_97 ) ;
break;
case V_102 :
if ( V_2 -> V_30 == V_81 )
return - V_12 ;
F_30 ( V_2 ) ;
V_45 = F_72 ( & V_2 -> V_61 ) ;
V_98 = V_45 ? V_45 -> V_41 : 0 ;
F_31 ( V_2 ) ;
V_10 = F_71 ( V_98 , ( int V_101 * ) V_97 ) ;
break;
case V_103 :
V_10 = F_73 ( V_2 , (struct V_104 V_101 * ) V_97 ) ;
break;
case V_105 :
V_10 = F_74 ( V_2 , (struct V_106 V_101 * ) V_97 ) ;
break;
default:
V_10 = - V_107 ;
break;
}
return V_10 ;
}
int F_75 ( struct V_1 * V_2 , int V_108 , unsigned long V_57 )
{
F_41 ( V_58 , V_59 ) ;
int V_10 = 0 ;
F_21 ( L_9 , V_2 ) ;
F_42 ( F_43 ( V_2 ) , & V_58 ) ;
F_44 ( V_60 ) ;
while ( V_2 -> V_30 != V_108 ) {
if ( ! V_57 ) {
V_10 = - V_109 ;
break;
}
if ( F_46 ( V_59 ) ) {
V_10 = F_57 ( V_57 ) ;
break;
}
F_31 ( V_2 ) ;
V_57 = F_48 ( V_57 ) ;
F_30 ( V_2 ) ;
F_44 ( V_60 ) ;
V_10 = F_56 ( V_2 ) ;
if ( V_10 )
break;
}
F_50 ( V_64 ) ;
F_51 ( F_43 ( V_2 ) , & V_58 ) ;
return V_10 ;
}
int F_76 ( struct V_1 * V_2 , unsigned long V_38 )
{
F_41 ( V_58 , V_59 ) ;
unsigned long V_57 ;
int V_10 = 0 ;
F_21 ( L_9 , V_2 ) ;
V_57 = F_77 ( V_2 , V_38 & V_110 ) ;
F_42 ( F_43 ( V_2 ) , & V_58 ) ;
F_44 ( V_60 ) ;
while ( F_32 ( V_91 , & F_24 ( V_2 ) -> V_38 ) ) {
if ( ! V_57 ) {
V_10 = - V_69 ;
break;
}
if ( F_46 ( V_59 ) ) {
V_10 = F_57 ( V_57 ) ;
break;
}
F_31 ( V_2 ) ;
V_57 = F_48 ( V_57 ) ;
F_30 ( V_2 ) ;
F_44 ( V_60 ) ;
V_10 = F_56 ( V_2 ) ;
if ( V_10 )
break;
}
F_50 ( V_64 ) ;
F_51 ( F_43 ( V_2 ) , & V_58 ) ;
return V_10 ;
}
static void * F_78 ( struct V_111 * V_112 , T_3 * V_113 )
__acquires( V_112 -> V_114 -> V_24 -> V_25 )
{
struct V_115 * V_33 = V_112 -> V_114 ;
struct V_23 * V_24 = V_33 -> V_24 ;
F_11 ( & V_24 -> V_25 ) ;
return F_79 ( & V_24 -> V_26 , * V_113 ) ;
}
static void * F_80 ( struct V_111 * V_112 , void * V_116 , T_3 * V_113 )
{
struct V_115 * V_33 = V_112 -> V_114 ;
struct V_23 * V_24 = V_33 -> V_24 ;
return F_81 ( V_116 , & V_24 -> V_26 , V_113 ) ;
}
static void F_82 ( struct V_111 * V_112 , void * V_116 )
__releases( V_112 -> V_114 -> V_24 -> V_25 )
{
struct V_115 * V_33 = V_112 -> V_114 ;
struct V_23 * V_24 = V_33 -> V_24 ;
F_15 ( & V_24 -> V_25 ) ;
}
static int F_83 ( struct V_111 * V_112 , void * V_116 )
{
struct V_115 * V_33 = V_112 -> V_114 ;
struct V_23 * V_24 = V_33 -> V_24 ;
if ( V_116 == V_117 ) {
F_84 ( V_112 , L_10 ) ;
if ( V_24 -> V_118 ) {
F_85 ( V_112 , ' ' ) ;
V_24 -> V_118 ( V_112 , V_116 ) ;
}
F_85 ( V_112 , '\n' ) ;
} else {
struct V_1 * V_2 = F_86 ( V_116 ) ;
struct V_32 * V_119 = F_24 ( V_2 ) ;
F_87 ( V_112 ,
L_11 ,
V_2 ,
F_88 ( & V_2 -> V_120 ) ,
F_89 ( V_2 ) ,
F_70 ( V_2 ) ,
F_90 ( F_91 ( V_112 ) , F_92 ( V_2 ) ) ,
F_93 ( V_2 ) ,
V_119 -> V_27 ? F_93 ( V_119 -> V_27 ) : 0LU ) ;
if ( V_24 -> V_118 ) {
F_85 ( V_112 , ' ' ) ;
V_24 -> V_118 ( V_112 , V_116 ) ;
}
F_85 ( V_112 , '\n' ) ;
}
return 0 ;
}
static int F_94 ( struct V_121 * V_121 , struct V_79 * V_79 )
{
struct V_23 * V_122 ;
struct V_115 * V_33 ;
V_122 = F_95 ( V_121 ) ;
V_33 = F_96 ( V_79 , & V_123 ,
sizeof( struct V_115 ) ) ;
if ( ! V_33 )
return - V_124 ;
V_33 -> V_24 = V_122 ;
return 0 ;
}
int F_97 ( struct V_16 * V_16 , const char * V_125 ,
struct V_23 * V_122 ,
int (* F_98)( struct V_111 * , void * ) )
{
V_122 -> V_118 = F_98 ;
if ( ! F_99 ( V_125 , 0 , V_16 -> V_126 , & V_127 , V_122 ) )
return - V_124 ;
return 0 ;
}
void F_100 ( struct V_16 * V_16 , const char * V_125 )
{
F_101 ( V_125 , V_16 -> V_126 ) ;
}
int F_97 ( struct V_16 * V_16 , const char * V_125 ,
struct V_23 * V_122 ,
int (* F_98)( struct V_111 * , void * ) )
{
return 0 ;
}
void F_100 ( struct V_16 * V_16 , const char * V_125 )
{
}
static int T_4 F_102 ( void )
{
int V_10 ;
F_103 ( sizeof( struct V_128 ) ) ;
F_104 ( L_12 , V_129 ) ;
V_10 = F_105 () ;
if ( V_10 < 0 )
return V_10 ;
V_130 = F_106 ( L_13 , NULL ) ;
F_107 () ;
V_10 = F_108 () ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_109 ( & V_131 ) ;
if ( V_10 < 0 ) {
F_110 () ;
return V_10 ;
}
F_104 ( L_14 ) ;
V_10 = F_111 () ;
if ( V_10 < 0 )
goto error;
V_10 = F_112 () ;
if ( V_10 < 0 )
goto V_132;
V_10 = F_113 () ;
if ( V_10 < 0 ) {
F_114 () ;
goto V_132;
}
V_10 = F_115 () ;
if ( V_10 < 0 ) {
F_116 () ;
F_114 () ;
goto V_132;
}
return 0 ;
V_132:
F_117 () ;
error:
F_118 ( V_133 ) ;
F_110 () ;
return V_10 ;
}
static void T_5 F_119 ( void )
{
F_120 () ;
F_116 () ;
F_114 () ;
F_117 () ;
F_118 ( V_133 ) ;
F_110 () ;
F_121 () ;
F_122 ( V_130 ) ;
}
