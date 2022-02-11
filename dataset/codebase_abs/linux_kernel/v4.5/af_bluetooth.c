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
int V_10 ;
F_21 ( L_5 , V_1 , V_2 , V_41 ) ;
if ( V_38 & V_47 )
return - V_48 ;
V_45 = F_35 ( V_2 , V_38 , V_42 , & V_10 ) ;
if ( ! V_45 ) {
if ( V_2 -> V_49 & V_50 )
return 0 ;
return V_10 ;
}
V_46 = V_45 -> V_41 ;
if ( V_41 < V_46 ) {
V_40 -> V_51 |= V_52 ;
V_46 = V_41 ;
}
F_36 ( V_45 ) ;
V_10 = F_37 ( V_45 , 0 , V_40 , V_46 ) ;
if ( V_10 == 0 ) {
F_38 ( V_40 , V_2 , V_45 ) ;
if ( F_24 ( V_2 ) -> V_53 )
F_24 ( V_2 ) -> V_53 ( V_45 , V_40 -> V_54 ,
& V_40 -> V_55 ) ;
}
F_39 ( V_2 , V_45 ) ;
return V_10 ? : V_46 ;
}
static long F_40 ( struct V_1 * V_2 , long V_56 )
{
F_41 ( V_57 , V_58 ) ;
F_42 ( F_43 ( V_2 ) , & V_57 ) ;
for (; ; ) {
F_44 ( V_59 ) ;
if ( ! F_45 ( & V_2 -> V_60 ) )
break;
if ( V_2 -> V_61 || ( V_2 -> V_49 & V_50 ) )
break;
if ( F_46 ( V_58 ) || ! V_56 )
break;
F_47 ( V_62 , V_2 ) ;
F_31 ( V_2 ) ;
V_56 = F_48 ( V_56 ) ;
F_30 ( V_2 ) ;
F_49 ( V_62 , V_2 ) ;
}
F_50 ( V_63 ) ;
F_51 ( F_43 ( V_2 ) , & V_57 ) ;
return V_56 ;
}
int F_52 ( struct V_17 * V_1 , struct V_39 * V_40 ,
T_1 V_64 , int V_38 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_10 = 0 ;
T_1 V_65 , V_46 = 0 ;
long V_56 ;
if ( V_38 & V_47 )
return - V_48 ;
F_21 ( L_6 , V_2 , V_64 ) ;
F_30 ( V_2 ) ;
V_65 = F_53 ( V_2 , V_38 & V_66 , V_64 ) ;
V_56 = F_54 ( V_2 , V_38 & V_43 ) ;
do {
struct V_44 * V_45 ;
int V_67 ;
V_45 = F_55 ( & V_2 -> V_60 ) ;
if ( ! V_45 ) {
if ( V_46 >= V_65 )
break;
V_10 = F_56 ( V_2 ) ;
if ( V_10 )
break;
if ( V_2 -> V_49 & V_50 )
break;
V_10 = - V_68 ;
if ( ! V_56 )
break;
V_56 = F_40 ( V_2 , V_56 ) ;
if ( F_46 ( V_58 ) ) {
V_10 = F_57 ( V_56 ) ;
goto V_69;
}
continue;
}
V_67 = F_58 (unsigned int, skb->len, size) ;
if ( F_37 ( V_45 , 0 , V_40 , V_67 ) ) {
F_59 ( & V_2 -> V_60 , V_45 ) ;
if ( ! V_46 )
V_46 = - V_70 ;
break;
}
V_46 += V_67 ;
V_64 -= V_67 ;
F_38 ( V_40 , V_2 , V_45 ) ;
if ( ! ( V_38 & V_71 ) ) {
int V_72 = F_60 ( V_45 ) ;
if ( V_67 <= V_72 ) {
F_61 ( V_45 , V_67 ) ;
} else {
struct V_44 * V_73 ;
F_61 ( V_45 , V_72 ) ;
V_67 -= V_72 ;
F_62 (skb, frag) {
if ( V_67 <= V_73 -> V_41 ) {
V_45 -> V_41 -= V_67 ;
V_45 -> V_74 -= V_67 ;
F_61 ( V_73 , V_67 ) ;
break;
} else if ( V_73 -> V_41 ) {
V_67 -= V_73 -> V_41 ;
V_45 -> V_41 -= V_73 -> V_41 ;
V_45 -> V_74 -= V_73 -> V_41 ;
F_61 ( V_73 , V_73 -> V_41 ) ;
}
}
}
if ( V_45 -> V_41 ) {
F_59 ( & V_2 -> V_60 , V_45 ) ;
break;
}
F_63 ( V_45 ) ;
} else {
F_59 ( & V_2 -> V_60 , V_45 ) ;
break;
}
} while ( V_64 );
V_69:
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
V_2 -> V_30 == V_75 ) )
return V_76 | V_77 ;
}
return 0 ;
}
unsigned int F_65 ( struct V_78 * V_78 , struct V_17 * V_1 ,
T_2 * V_57 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned int V_79 = 0 ;
F_21 ( L_7 , V_1 , V_2 ) ;
F_66 ( V_78 , F_43 ( V_2 ) , V_57 ) ;
if ( V_2 -> V_30 == V_80 )
return F_64 ( V_2 ) ;
if ( V_2 -> V_61 || ! F_45 ( & V_2 -> V_81 ) )
V_79 |= V_82 |
( F_67 ( V_2 , V_83 ) ? V_84 : 0 ) ;
if ( V_2 -> V_49 & V_50 )
V_79 |= V_85 | V_76 | V_77 ;
if ( V_2 -> V_49 == V_86 )
V_79 |= V_87 ;
if ( ! F_45 ( & V_2 -> V_60 ) )
V_79 |= V_76 | V_77 ;
if ( V_2 -> V_30 == V_35 )
V_79 |= V_87 ;
if ( V_2 -> V_30 == V_88 ||
V_2 -> V_30 == V_75 ||
V_2 -> V_30 == V_89 )
return V_79 ;
if ( ! F_32 ( V_90 , & F_24 ( V_2 ) -> V_38 ) && F_68 ( V_2 ) )
V_79 |= V_91 | V_92 | V_93 ;
else
F_47 ( V_94 , V_2 ) ;
return V_79 ;
}
int F_69 ( struct V_17 * V_1 , unsigned int V_95 , unsigned long V_96 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_44 * V_45 ;
long V_97 ;
int V_10 ;
F_21 ( L_8 , V_2 , V_95 , V_96 ) ;
switch ( V_95 ) {
case V_98 :
if ( V_2 -> V_30 == V_80 )
return - V_12 ;
V_97 = V_2 -> V_99 - F_70 ( V_2 ) ;
if ( V_97 < 0 )
V_97 = 0 ;
V_10 = F_71 ( V_97 , ( int V_100 * ) V_96 ) ;
break;
case V_101 :
if ( V_2 -> V_30 == V_80 )
return - V_12 ;
F_30 ( V_2 ) ;
V_45 = F_72 ( & V_2 -> V_60 ) ;
V_97 = V_45 ? V_45 -> V_41 : 0 ;
F_31 ( V_2 ) ;
V_10 = F_71 ( V_97 , ( int V_100 * ) V_96 ) ;
break;
case V_102 :
V_10 = F_73 ( V_2 , (struct V_103 V_100 * ) V_96 ) ;
break;
case V_104 :
V_10 = F_74 ( V_2 , (struct V_105 V_100 * ) V_96 ) ;
break;
default:
V_10 = - V_106 ;
break;
}
return V_10 ;
}
int F_75 ( struct V_1 * V_2 , int V_107 , unsigned long V_56 )
{
F_41 ( V_57 , V_58 ) ;
int V_10 = 0 ;
F_21 ( L_9 , V_2 ) ;
F_42 ( F_43 ( V_2 ) , & V_57 ) ;
F_44 ( V_59 ) ;
while ( V_2 -> V_30 != V_107 ) {
if ( ! V_56 ) {
V_10 = - V_108 ;
break;
}
if ( F_46 ( V_58 ) ) {
V_10 = F_57 ( V_56 ) ;
break;
}
F_31 ( V_2 ) ;
V_56 = F_48 ( V_56 ) ;
F_30 ( V_2 ) ;
F_44 ( V_59 ) ;
V_10 = F_56 ( V_2 ) ;
if ( V_10 )
break;
}
F_50 ( V_63 ) ;
F_51 ( F_43 ( V_2 ) , & V_57 ) ;
return V_10 ;
}
int F_76 ( struct V_1 * V_2 , unsigned long V_38 )
{
F_41 ( V_57 , V_58 ) ;
unsigned long V_56 ;
int V_10 = 0 ;
F_21 ( L_9 , V_2 ) ;
V_56 = F_77 ( V_2 , V_38 & V_109 ) ;
F_42 ( F_43 ( V_2 ) , & V_57 ) ;
F_44 ( V_59 ) ;
while ( F_32 ( V_90 , & F_24 ( V_2 ) -> V_38 ) ) {
if ( ! V_56 ) {
V_10 = - V_68 ;
break;
}
if ( F_46 ( V_58 ) ) {
V_10 = F_57 ( V_56 ) ;
break;
}
F_31 ( V_2 ) ;
V_56 = F_48 ( V_56 ) ;
F_30 ( V_2 ) ;
F_44 ( V_59 ) ;
V_10 = F_56 ( V_2 ) ;
if ( V_10 )
break;
}
F_50 ( V_63 ) ;
F_51 ( F_43 ( V_2 ) , & V_57 ) ;
return V_10 ;
}
static void * F_78 ( struct V_110 * V_111 , T_3 * V_112 )
__acquires( V_111 -> V_113 -> V_24 -> V_25 )
{
struct V_114 * V_33 = V_111 -> V_113 ;
struct V_23 * V_24 = V_33 -> V_24 ;
F_11 ( & V_24 -> V_25 ) ;
return F_79 ( & V_24 -> V_26 , * V_112 ) ;
}
static void * F_80 ( struct V_110 * V_111 , void * V_115 , T_3 * V_112 )
{
struct V_114 * V_33 = V_111 -> V_113 ;
struct V_23 * V_24 = V_33 -> V_24 ;
return F_81 ( V_115 , & V_24 -> V_26 , V_112 ) ;
}
static void F_82 ( struct V_110 * V_111 , void * V_115 )
__releases( V_111 -> V_113 -> V_24 -> V_25 )
{
struct V_114 * V_33 = V_111 -> V_113 ;
struct V_23 * V_24 = V_33 -> V_24 ;
F_15 ( & V_24 -> V_25 ) ;
}
static int F_83 ( struct V_110 * V_111 , void * V_115 )
{
struct V_114 * V_33 = V_111 -> V_113 ;
struct V_23 * V_24 = V_33 -> V_24 ;
if ( V_115 == V_116 ) {
F_84 ( V_111 , L_10 ) ;
if ( V_24 -> V_117 ) {
F_85 ( V_111 , ' ' ) ;
V_24 -> V_117 ( V_111 , V_115 ) ;
}
F_85 ( V_111 , '\n' ) ;
} else {
struct V_1 * V_2 = F_86 ( V_115 ) ;
struct V_32 * V_118 = F_24 ( V_2 ) ;
F_87 ( V_111 ,
L_11 ,
V_2 ,
F_88 ( & V_2 -> V_119 ) ,
F_89 ( V_2 ) ,
F_70 ( V_2 ) ,
F_90 ( F_91 ( V_111 ) , F_92 ( V_2 ) ) ,
F_93 ( V_2 ) ,
V_118 -> V_27 ? F_93 ( V_118 -> V_27 ) : 0LU ) ;
if ( V_24 -> V_117 ) {
F_85 ( V_111 , ' ' ) ;
V_24 -> V_117 ( V_111 , V_115 ) ;
}
F_85 ( V_111 , '\n' ) ;
}
return 0 ;
}
static int F_94 ( struct V_120 * V_120 , struct V_78 * V_78 )
{
struct V_23 * V_121 ;
struct V_114 * V_33 ;
V_121 = F_95 ( V_120 ) ;
V_33 = F_96 ( V_78 , & V_122 ,
sizeof( struct V_114 ) ) ;
if ( ! V_33 )
return - V_123 ;
V_33 -> V_24 = V_121 ;
return 0 ;
}
int F_97 ( struct V_16 * V_16 , const char * V_124 ,
struct V_23 * V_121 ,
int (* F_98)( struct V_110 * , void * ) )
{
V_121 -> V_117 = F_98 ;
if ( ! F_99 ( V_124 , 0 , V_16 -> V_125 , & V_126 , V_121 ) )
return - V_123 ;
return 0 ;
}
void F_100 ( struct V_16 * V_16 , const char * V_124 )
{
F_101 ( V_124 , V_16 -> V_125 ) ;
}
int F_97 ( struct V_16 * V_16 , const char * V_124 ,
struct V_23 * V_121 ,
int (* F_98)( struct V_110 * , void * ) )
{
return 0 ;
}
void F_100 ( struct V_16 * V_16 , const char * V_124 )
{
}
static int T_4 F_102 ( void )
{
int V_10 ;
F_103 ( sizeof( struct V_127 ) ) ;
F_104 ( L_12 , V_128 ) ;
V_10 = F_105 () ;
if ( V_10 < 0 )
return V_10 ;
V_129 = F_106 ( L_13 , NULL ) ;
V_10 = F_107 () ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_108 ( & V_130 ) ;
if ( V_10 < 0 ) {
F_109 () ;
return V_10 ;
}
F_104 ( L_14 ) ;
V_10 = F_110 () ;
if ( V_10 < 0 )
goto error;
V_10 = F_111 () ;
if ( V_10 < 0 )
goto V_131;
V_10 = F_112 () ;
if ( V_10 < 0 ) {
F_113 () ;
goto V_131;
}
V_10 = F_114 () ;
if ( V_10 < 0 ) {
F_115 () ;
F_113 () ;
goto V_131;
}
return 0 ;
V_131:
F_116 () ;
error:
F_117 ( V_132 ) ;
F_109 () ;
return V_10 ;
}
static void T_5 F_118 ( void )
{
F_119 () ;
F_115 () ;
F_113 () ;
F_116 () ;
F_117 ( V_132 ) ;
F_109 () ;
F_120 ( V_129 ) ;
}
