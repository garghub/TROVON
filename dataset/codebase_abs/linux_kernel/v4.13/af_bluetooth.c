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
F_23 ( V_2 ) ;
F_24 ( & F_25 ( V_2 ) -> V_28 , & F_25 ( V_27 ) -> V_28 ) ;
F_25 ( V_2 ) -> V_27 = V_27 ;
F_26 ( V_2 ) ;
V_27 -> V_29 ++ ;
}
void F_27 ( struct V_1 * V_2 )
{
F_21 ( L_3 , V_2 , V_2 -> V_30 ) ;
F_28 ( & F_25 ( V_2 ) -> V_28 ) ;
F_25 ( V_2 ) -> V_27 -> V_29 -- ;
F_25 ( V_2 ) -> V_27 = NULL ;
F_29 ( V_2 ) ;
}
struct V_1 * F_30 ( struct V_1 * V_27 , struct V_17 * V_31 )
{
struct V_32 * V_33 , * V_34 ;
struct V_1 * V_2 ;
F_21 ( L_4 , V_27 ) ;
V_35:
F_31 (s, n, &bt_sk(parent)->accept_q, accept_q) {
V_2 = (struct V_1 * ) V_33 ;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
if ( ! F_25 ( V_2 ) -> V_27 ) {
F_21 ( L_5 , V_2 ) ;
F_26 ( V_2 ) ;
F_29 ( V_2 ) ;
goto V_35;
}
F_29 ( V_2 ) ;
if ( V_2 -> V_30 == V_36 ) {
F_27 ( V_2 ) ;
F_26 ( V_2 ) ;
continue;
}
if ( V_2 -> V_30 == V_37 || ! V_31 ||
F_32 ( V_38 , & F_25 ( V_27 ) -> V_39 ) ) {
F_27 ( V_2 ) ;
if ( V_31 )
F_33 ( V_2 , V_31 ) ;
F_26 ( V_2 ) ;
return V_2 ;
}
F_26 ( V_2 ) ;
}
return NULL ;
}
int F_34 ( struct V_17 * V_1 , struct V_40 * V_41 , T_1 V_42 ,
int V_39 )
{
int V_43 = V_39 & V_44 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 ;
T_1 V_47 ;
T_1 V_48 ;
int V_10 ;
F_21 ( L_6 , V_1 , V_2 , V_42 ) ;
if ( V_39 & V_49 )
return - V_50 ;
V_46 = F_35 ( V_2 , V_39 , V_43 , & V_10 ) ;
if ( ! V_46 ) {
if ( V_2 -> V_51 & V_52 )
return 0 ;
return V_10 ;
}
V_48 = V_46 -> V_42 ;
V_47 = V_46 -> V_42 ;
if ( V_42 < V_47 ) {
V_41 -> V_53 |= V_54 ;
V_47 = V_42 ;
}
F_36 ( V_46 ) ;
V_10 = F_37 ( V_46 , 0 , V_41 , V_47 ) ;
if ( V_10 == 0 ) {
F_38 ( V_41 , V_2 , V_46 ) ;
if ( V_41 -> V_55 && F_25 ( V_2 ) -> V_56 )
F_25 ( V_2 ) -> V_56 ( V_46 , V_41 -> V_55 ,
& V_41 -> V_57 ) ;
}
F_39 ( V_2 , V_46 ) ;
if ( V_39 & V_54 )
V_47 = V_48 ;
return V_10 ? : V_47 ;
}
static long F_40 ( struct V_1 * V_2 , long V_58 )
{
F_41 ( V_59 , V_60 ) ;
F_42 ( F_43 ( V_2 ) , & V_59 ) ;
for (; ; ) {
F_44 ( V_61 ) ;
if ( ! F_45 ( & V_2 -> V_62 ) )
break;
if ( V_2 -> V_63 || ( V_2 -> V_51 & V_52 ) )
break;
if ( F_46 ( V_60 ) || ! V_58 )
break;
F_47 ( V_64 , V_2 ) ;
F_26 ( V_2 ) ;
V_58 = F_48 ( V_58 ) ;
F_23 ( V_2 ) ;
F_49 ( V_64 , V_2 ) ;
}
F_50 ( V_65 ) ;
F_51 ( F_43 ( V_2 ) , & V_59 ) ;
return V_58 ;
}
int F_52 ( struct V_17 * V_1 , struct V_40 * V_41 ,
T_1 V_66 , int V_39 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_10 = 0 ;
T_1 V_67 , V_47 = 0 ;
long V_58 ;
if ( V_39 & V_49 )
return - V_50 ;
F_21 ( L_7 , V_2 , V_66 ) ;
F_23 ( V_2 ) ;
V_67 = F_53 ( V_2 , V_39 & V_68 , V_66 ) ;
V_58 = F_54 ( V_2 , V_39 & V_44 ) ;
do {
struct V_45 * V_46 ;
int V_69 ;
V_46 = F_55 ( & V_2 -> V_62 ) ;
if ( ! V_46 ) {
if ( V_47 >= V_67 )
break;
V_10 = F_56 ( V_2 ) ;
if ( V_10 )
break;
if ( V_2 -> V_51 & V_52 )
break;
V_10 = - V_70 ;
if ( ! V_58 )
break;
V_58 = F_40 ( V_2 , V_58 ) ;
if ( F_46 ( V_60 ) ) {
V_10 = F_57 ( V_58 ) ;
goto V_71;
}
continue;
}
V_69 = F_58 (unsigned int, skb->len, size) ;
if ( F_37 ( V_46 , 0 , V_41 , V_69 ) ) {
F_59 ( & V_2 -> V_62 , V_46 ) ;
if ( ! V_47 )
V_47 = - V_72 ;
break;
}
V_47 += V_69 ;
V_66 -= V_69 ;
F_38 ( V_41 , V_2 , V_46 ) ;
if ( ! ( V_39 & V_73 ) ) {
int V_74 = F_60 ( V_46 ) ;
if ( V_69 <= V_74 ) {
F_61 ( V_46 , V_69 ) ;
} else {
struct V_45 * V_75 ;
F_61 ( V_46 , V_74 ) ;
V_69 -= V_74 ;
F_62 (skb, frag) {
if ( V_69 <= V_75 -> V_42 ) {
V_46 -> V_42 -= V_69 ;
V_46 -> V_76 -= V_69 ;
F_61 ( V_75 , V_69 ) ;
break;
} else if ( V_75 -> V_42 ) {
V_69 -= V_75 -> V_42 ;
V_46 -> V_42 -= V_75 -> V_42 ;
V_46 -> V_76 -= V_75 -> V_42 ;
F_61 ( V_75 , V_75 -> V_42 ) ;
}
}
}
if ( V_46 -> V_42 ) {
F_59 ( & V_2 -> V_62 , V_46 ) ;
break;
}
F_63 ( V_46 ) ;
} else {
F_59 ( & V_2 -> V_62 , V_46 ) ;
break;
}
} while ( V_66 );
V_71:
F_26 ( V_2 ) ;
return V_47 ? : V_10 ;
}
static inline unsigned int F_64 ( struct V_1 * V_27 )
{
struct V_32 * V_33 , * V_34 ;
struct V_1 * V_2 ;
F_31 (s, n, &bt_sk(parent)->accept_q, accept_q) {
V_2 = (struct V_1 * ) V_33 ;
if ( V_2 -> V_30 == V_37 ||
( F_32 ( V_38 , & F_25 ( V_27 ) -> V_39 ) &&
V_2 -> V_30 == V_77 ) )
return V_78 | V_79 ;
}
return 0 ;
}
unsigned int F_65 ( struct V_80 * V_80 , struct V_17 * V_1 ,
T_2 * V_59 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned int V_81 = 0 ;
F_21 ( L_8 , V_1 , V_2 ) ;
F_66 ( V_80 , F_43 ( V_2 ) , V_59 ) ;
if ( V_2 -> V_30 == V_82 )
return F_64 ( V_2 ) ;
if ( V_2 -> V_63 || ! F_45 ( & V_2 -> V_83 ) )
V_81 |= V_84 |
( F_67 ( V_2 , V_85 ) ? V_86 : 0 ) ;
if ( V_2 -> V_51 & V_52 )
V_81 |= V_87 | V_78 | V_79 ;
if ( V_2 -> V_51 == V_88 )
V_81 |= V_89 ;
if ( ! F_45 ( & V_2 -> V_62 ) )
V_81 |= V_78 | V_79 ;
if ( V_2 -> V_30 == V_36 )
V_81 |= V_89 ;
if ( V_2 -> V_30 == V_90 ||
V_2 -> V_30 == V_77 ||
V_2 -> V_30 == V_91 )
return V_81 ;
if ( ! F_32 ( V_92 , & F_25 ( V_2 ) -> V_39 ) && F_68 ( V_2 ) )
V_81 |= V_93 | V_94 | V_95 ;
else
F_47 ( V_96 , V_2 ) ;
return V_81 ;
}
int F_69 ( struct V_17 * V_1 , unsigned int V_97 , unsigned long V_98 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 ;
long V_99 ;
int V_10 ;
F_21 ( L_9 , V_2 , V_97 , V_98 ) ;
switch ( V_97 ) {
case V_100 :
if ( V_2 -> V_30 == V_82 )
return - V_12 ;
V_99 = V_2 -> V_101 - F_70 ( V_2 ) ;
if ( V_99 < 0 )
V_99 = 0 ;
V_10 = F_71 ( V_99 , ( int V_102 * ) V_98 ) ;
break;
case V_103 :
if ( V_2 -> V_30 == V_82 )
return - V_12 ;
F_23 ( V_2 ) ;
V_46 = F_72 ( & V_2 -> V_62 ) ;
V_99 = V_46 ? V_46 -> V_42 : 0 ;
F_26 ( V_2 ) ;
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
int F_75 ( struct V_1 * V_2 , int V_109 , unsigned long V_58 )
{
F_41 ( V_59 , V_60 ) ;
int V_10 = 0 ;
F_21 ( L_10 , V_2 ) ;
F_42 ( F_43 ( V_2 ) , & V_59 ) ;
F_44 ( V_61 ) ;
while ( V_2 -> V_30 != V_109 ) {
if ( ! V_58 ) {
V_10 = - V_110 ;
break;
}
if ( F_46 ( V_60 ) ) {
V_10 = F_57 ( V_58 ) ;
break;
}
F_26 ( V_2 ) ;
V_58 = F_48 ( V_58 ) ;
F_23 ( V_2 ) ;
F_44 ( V_61 ) ;
V_10 = F_56 ( V_2 ) ;
if ( V_10 )
break;
}
F_50 ( V_65 ) ;
F_51 ( F_43 ( V_2 ) , & V_59 ) ;
return V_10 ;
}
int F_76 ( struct V_1 * V_2 , unsigned long V_39 )
{
F_41 ( V_59 , V_60 ) ;
unsigned long V_58 ;
int V_10 = 0 ;
F_21 ( L_10 , V_2 ) ;
V_58 = F_77 ( V_2 , V_39 & V_111 ) ;
F_42 ( F_43 ( V_2 ) , & V_59 ) ;
F_44 ( V_61 ) ;
while ( F_32 ( V_92 , & F_25 ( V_2 ) -> V_39 ) ) {
if ( ! V_58 ) {
V_10 = - V_70 ;
break;
}
if ( F_46 ( V_60 ) ) {
V_10 = F_57 ( V_58 ) ;
break;
}
F_26 ( V_2 ) ;
V_58 = F_48 ( V_58 ) ;
F_23 ( V_2 ) ;
F_44 ( V_61 ) ;
V_10 = F_56 ( V_2 ) ;
if ( V_10 )
break;
}
F_50 ( V_65 ) ;
F_51 ( F_43 ( V_2 ) , & V_59 ) ;
return V_10 ;
}
static void * F_78 ( struct V_112 * V_113 , T_3 * V_114 )
__acquires( V_113 -> V_115 -> V_24 -> V_25 )
{
struct V_116 * V_33 = V_113 -> V_115 ;
struct V_23 * V_24 = V_33 -> V_24 ;
F_11 ( & V_24 -> V_25 ) ;
return F_79 ( & V_24 -> V_26 , * V_114 ) ;
}
static void * F_80 ( struct V_112 * V_113 , void * V_117 , T_3 * V_114 )
{
struct V_116 * V_33 = V_113 -> V_115 ;
struct V_23 * V_24 = V_33 -> V_24 ;
return F_81 ( V_117 , & V_24 -> V_26 , V_114 ) ;
}
static void F_82 ( struct V_112 * V_113 , void * V_117 )
__releases( V_113 -> V_115 -> V_24 -> V_25 )
{
struct V_116 * V_33 = V_113 -> V_115 ;
struct V_23 * V_24 = V_33 -> V_24 ;
F_15 ( & V_24 -> V_25 ) ;
}
static int F_83 ( struct V_112 * V_113 , void * V_117 )
{
struct V_116 * V_33 = V_113 -> V_115 ;
struct V_23 * V_24 = V_33 -> V_24 ;
if ( V_117 == V_118 ) {
F_84 ( V_113 , L_11 ) ;
if ( V_24 -> V_119 ) {
F_85 ( V_113 , ' ' ) ;
V_24 -> V_119 ( V_113 , V_117 ) ;
}
F_85 ( V_113 , '\n' ) ;
} else {
struct V_1 * V_2 = F_86 ( V_117 ) ;
struct V_32 * V_120 = F_25 ( V_2 ) ;
F_87 ( V_113 ,
L_12 ,
V_2 ,
F_88 ( & V_2 -> V_121 ) ,
F_89 ( V_2 ) ,
F_70 ( V_2 ) ,
F_90 ( F_91 ( V_113 ) , F_92 ( V_2 ) ) ,
F_93 ( V_2 ) ,
V_120 -> V_27 ? F_93 ( V_120 -> V_27 ) : 0LU ) ;
if ( V_24 -> V_119 ) {
F_85 ( V_113 , ' ' ) ;
V_24 -> V_119 ( V_113 , V_117 ) ;
}
F_85 ( V_113 , '\n' ) ;
}
return 0 ;
}
static int F_94 ( struct V_122 * V_122 , struct V_80 * V_80 )
{
struct V_23 * V_123 ;
struct V_116 * V_33 ;
V_123 = F_95 ( V_122 ) ;
V_33 = F_96 ( V_80 , & V_124 ,
sizeof( struct V_116 ) ) ;
if ( ! V_33 )
return - V_125 ;
V_33 -> V_24 = V_123 ;
return 0 ;
}
int F_97 ( struct V_16 * V_16 , const char * V_126 ,
struct V_23 * V_123 ,
int (* F_98)( struct V_112 * , void * ) )
{
V_123 -> V_119 = F_98 ;
if ( ! F_99 ( V_126 , 0 , V_16 -> V_127 , & V_128 , V_123 ) )
return - V_125 ;
return 0 ;
}
void F_100 ( struct V_16 * V_16 , const char * V_126 )
{
F_101 ( V_126 , V_16 -> V_127 ) ;
}
int F_97 ( struct V_16 * V_16 , const char * V_126 ,
struct V_23 * V_123 ,
int (* F_98)( struct V_112 * , void * ) )
{
return 0 ;
}
void F_100 ( struct V_16 * V_16 , const char * V_126 )
{
}
static int T_4 F_102 ( void )
{
int V_10 ;
F_103 ( sizeof( struct V_129 ) ) ;
F_104 ( L_13 , V_130 ) ;
V_10 = F_105 () ;
if ( V_10 < 0 )
return V_10 ;
V_131 = F_106 ( L_14 , NULL ) ;
F_107 () ;
V_10 = F_108 () ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_109 ( & V_132 ) ;
if ( V_10 < 0 ) {
F_110 () ;
return V_10 ;
}
F_104 ( L_15 ) ;
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
F_121 () ;
F_122 ( V_131 ) ;
}
