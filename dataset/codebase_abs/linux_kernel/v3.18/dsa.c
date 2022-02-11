void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
}
static struct V_1 *
F_7 ( struct V_6 * V_7 , int V_8 , char * * V_9 )
{
struct V_1 * V_10 ;
struct V_11 * V_4 ;
char * V_12 ;
V_10 = NULL ;
V_12 = NULL ;
F_2 ( & V_3 ) ;
F_8 (list, &dsa_switch_drivers) {
struct V_1 * V_2 ;
V_2 = F_9 ( V_4 , struct V_1 , V_4 ) ;
V_12 = V_2 -> V_13 ( V_7 , V_8 ) ;
if ( V_12 != NULL ) {
V_10 = V_2 ;
break;
}
}
F_4 ( & V_3 ) ;
* V_9 = V_12 ;
return V_10 ;
}
static struct V_14 *
F_10 ( struct V_15 * V_16 , int V_17 ,
struct V_6 * V_18 , struct V_6 * V_7 )
{
struct V_19 * V_20 = V_16 -> V_20 -> V_21 + V_17 ;
struct V_1 * V_2 ;
struct V_14 * V_22 ;
int V_10 ;
char * V_12 ;
int V_23 ;
bool V_24 = false ;
V_2 = F_7 ( V_7 , V_20 -> V_8 , & V_12 ) ;
if ( V_2 == NULL ) {
F_11 ( V_25 L_1 ,
V_16 -> V_26 -> V_12 , V_17 ) ;
return F_12 ( - V_27 ) ;
}
F_11 ( V_28 L_2 ,
V_16 -> V_26 -> V_12 , V_17 , V_12 ) ;
V_22 = F_13 ( sizeof( * V_22 ) + V_2 -> V_29 , V_30 ) ;
if ( V_22 == NULL )
return F_12 ( - V_31 ) ;
V_22 -> V_16 = V_16 ;
V_22 -> V_17 = V_17 ;
V_22 -> V_20 = V_16 -> V_20 -> V_21 + V_17 ;
V_22 -> V_2 = V_2 ;
V_22 -> V_32 = V_7 ;
for ( V_23 = 0 ; V_23 < V_33 ; V_23 ++ ) {
char * V_12 ;
V_12 = V_20 -> V_34 [ V_23 ] ;
if ( V_12 == NULL )
continue;
if ( ! strcmp ( V_12 , L_3 ) ) {
if ( V_16 -> V_35 != - 1 ) {
F_11 ( V_25 L_4 ) ;
V_10 = - V_27 ;
goto V_36;
}
V_16 -> V_35 = V_17 ;
V_16 -> V_37 = V_23 ;
} else if ( ! strcmp ( V_12 , L_5 ) ) {
V_22 -> V_38 |= 1 << V_23 ;
} else {
V_22 -> V_39 |= 1 << V_23 ;
}
V_24 = true ;
}
if ( ! V_24 && V_23 == V_33 ) {
V_10 = - V_27 ;
goto V_36;
}
V_22 -> V_40 = V_22 -> V_39 ;
if ( V_16 -> V_35 == V_17 ) {
switch ( V_2 -> V_41 ) {
#ifdef F_14
case V_42 :
V_16 -> V_43 = V_44 . V_43 ;
break;
#endif
#ifdef F_15
case V_45 :
V_16 -> V_43 = V_46 . V_43 ;
break;
#endif
#ifdef F_16
case V_47 :
V_16 -> V_43 = V_48 . V_43 ;
break;
#endif
#ifdef F_17
case V_49 :
V_16 -> V_43 = V_50 . V_43 ;
break;
#endif
case V_51 :
break;
default:
V_10 = - V_52 ;
goto V_36;
}
V_16 -> V_41 = V_2 -> V_41 ;
}
V_10 = V_2 -> V_53 ( V_22 ) ;
if ( V_10 < 0 )
goto V_36;
V_10 = V_2 -> V_54 ( V_22 , V_16 -> V_26 -> V_55 ) ;
if ( V_10 < 0 )
goto V_36;
V_22 -> V_56 = F_18 () ;
if ( V_22 -> V_56 == NULL ) {
V_10 = - V_31 ;
goto V_36;
}
F_19 ( V_22 ) ;
V_10 = F_20 ( V_22 -> V_56 ) ;
if ( V_10 < 0 )
goto V_57;
for ( V_23 = 0 ; V_23 < V_33 ; V_23 ++ ) {
struct V_58 * V_59 ;
if ( ! ( V_22 -> V_39 & ( 1 << V_23 ) ) )
continue;
V_59 = F_21 ( V_22 , V_18 , V_23 , V_20 -> V_34 [ V_23 ] ) ;
if ( V_59 == NULL ) {
F_11 ( V_25 L_6
L_7 ,
V_16 -> V_26 -> V_12 ,
V_17 , V_23 , V_20 -> V_34 [ V_23 ] ) ;
continue;
}
V_22 -> V_60 [ V_23 ] = V_59 ;
}
return V_22 ;
V_57:
F_22 ( V_22 -> V_56 ) ;
V_36:
F_23 ( V_22 ) ;
return F_12 ( V_10 ) ;
}
static void F_24 ( struct V_14 * V_22 )
{
}
static int F_25 ( struct V_14 * V_22 )
{
int V_23 , V_10 = 0 ;
for ( V_23 = 0 ; V_23 < V_33 ; V_23 ++ ) {
if ( ! ( V_22 -> V_39 & ( 1 << V_23 ) ) )
continue;
V_10 = F_26 ( V_22 -> V_60 [ V_23 ] ) ;
if ( V_10 )
return V_10 ;
}
if ( V_22 -> V_2 -> V_61 )
V_10 = V_22 -> V_2 -> V_61 ( V_22 ) ;
return V_10 ;
}
static int F_27 ( struct V_14 * V_22 )
{
int V_23 , V_10 = 0 ;
if ( V_22 -> V_2 -> V_62 )
V_10 = V_22 -> V_2 -> V_62 ( V_22 ) ;
if ( V_10 )
return V_10 ;
for ( V_23 = 0 ; V_23 < V_33 ; V_23 ++ ) {
if ( ! ( V_22 -> V_39 & ( 1 << V_23 ) ) )
continue;
V_10 = F_28 ( V_22 -> V_60 [ V_23 ] ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static void F_29 ( struct V_63 * V_64 )
{
struct V_15 * V_16 ;
int V_23 ;
V_16 = F_30 ( V_64 , struct V_15 , V_65 ) ;
for ( V_23 = 0 ; V_23 < V_16 -> V_20 -> V_66 ; V_23 ++ ) {
struct V_14 * V_22 = V_16 -> V_22 [ V_23 ] ;
if ( V_22 != NULL && V_22 -> V_2 -> V_67 != NULL )
V_22 -> V_2 -> V_67 ( V_22 ) ;
}
F_31 ( & V_16 -> V_68 , F_32 ( V_69 + V_70 ) ) ;
}
static void F_33 ( unsigned long V_71 )
{
struct V_15 * V_16 = ( void * ) V_71 ;
F_34 ( & V_16 -> V_65 ) ;
}
static int F_35 ( struct V_6 * V_72 , void * V_73 )
{
if ( V_72 -> V_73 != NULL && ! strcmp ( V_72 -> V_73 -> V_12 , V_73 ) )
return 1 ;
return 0 ;
}
static struct V_6 * F_36 ( struct V_6 * V_18 , char * V_73 )
{
if ( F_35 ( V_18 , V_73 ) ) {
F_37 ( V_18 ) ;
return V_18 ;
}
return F_38 ( V_18 , V_73 , F_35 ) ;
}
struct V_74 * F_39 ( struct V_6 * V_72 )
{
struct V_6 * V_75 ;
V_75 = F_36 ( V_72 , L_8 ) ;
if ( V_75 != NULL ) {
struct V_74 * V_76 ;
V_76 = F_40 ( V_75 ) ;
F_41 ( V_75 ) ;
return V_76 ;
}
return NULL ;
}
static struct V_58 * F_42 ( struct V_6 * V_72 )
{
struct V_6 * V_75 ;
V_75 = F_36 ( V_72 , L_9 ) ;
if ( V_75 != NULL ) {
struct V_58 * V_77 ;
V_77 = F_43 ( V_75 ) ;
F_44 ( V_77 ) ;
F_41 ( V_75 ) ;
return V_77 ;
}
return NULL ;
}
static int F_45 ( struct V_78 * V_20 ,
struct V_19 * V_79 ,
int V_80 ,
struct V_81 * V_82 )
{
int V_10 ;
const T_1 * V_83 ;
int V_84 ;
int V_85 ;
struct V_81 * V_86 ;
int V_87 ;
V_86 = F_46 ( V_82 ) ;
if ( ! V_86 )
return - V_27 ;
V_83 = F_47 ( V_86 , L_10 , & V_87 ) ;
if ( ! V_83 || ( V_87 != sizeof( * V_83 ) * 2 ) )
return - V_27 ;
V_85 = F_48 ( V_83 + 1 ) ;
if ( V_85 >= V_20 -> V_66 )
return - V_27 ;
if ( ! V_79 -> V_88 ) {
V_79 -> V_88 = F_49 ( V_20 -> V_66 * sizeof( V_89 ) , V_30 ) ;
if ( ! V_79 -> V_88 )
return - V_31 ;
memset ( V_79 -> V_88 , - 1 , V_20 -> V_66 * sizeof( V_89 ) ) ;
}
V_83 = F_47 ( V_82 , L_10 , NULL ) ;
if ( ! V_83 ) {
V_10 = - V_27 ;
goto V_36;
}
V_84 = F_48 ( V_83 ) ;
V_79 -> V_88 [ V_85 ] = V_84 ;
return 0 ;
V_36:
F_23 ( V_79 -> V_88 ) ;
return V_10 ;
}
static void F_50 ( struct V_78 * V_20 )
{
int V_23 ;
int V_90 ;
for ( V_23 = 0 ; V_23 < V_20 -> V_66 ; V_23 ++ ) {
V_90 = 0 ;
while ( V_90 < V_33 ) {
F_23 ( V_20 -> V_21 [ V_23 ] . V_34 [ V_90 ] ) ;
V_90 ++ ;
}
F_23 ( V_20 -> V_21 [ V_23 ] . V_88 ) ;
}
F_23 ( V_20 -> V_21 ) ;
}
static int F_51 ( struct V_91 * V_92 )
{
struct V_81 * V_93 = V_92 -> V_72 . V_94 ;
struct V_81 * V_95 , * V_96 , * V_97 , * V_98 , * V_82 ;
struct V_74 * V_99 ;
struct V_91 * V_100 ;
struct V_78 * V_20 ;
struct V_19 * V_79 ;
const char * V_101 ;
int V_80 , V_90 ;
const unsigned int * V_8 , * V_102 ;
int V_10 ;
V_96 = F_52 ( V_93 , L_11 , 0 ) ;
if ( ! V_96 )
return - V_27 ;
V_99 = F_53 ( V_96 ) ;
if ( ! V_99 )
return - V_27 ;
V_97 = F_52 ( V_93 , L_12 , 0 ) ;
if ( ! V_97 )
return - V_27 ;
V_100 = F_54 ( V_97 ) ;
if ( ! V_100 )
return - V_103 ;
V_20 = F_13 ( sizeof( * V_20 ) , V_30 ) ;
if ( ! V_20 )
return - V_31 ;
V_92 -> V_72 . V_104 = V_20 ;
V_20 -> V_105 = & V_100 -> V_72 ;
V_20 -> V_66 = F_55 ( V_93 ) ;
if ( V_20 -> V_66 > V_106 )
V_20 -> V_66 = V_106 ;
V_20 -> V_21 = F_13 ( V_20 -> V_66 * sizeof( struct V_19 ) ,
V_30 ) ;
if ( ! V_20 -> V_21 ) {
V_10 = - V_31 ;
goto V_57;
}
V_80 = - 1 ;
F_56 (np, child) {
V_80 ++ ;
V_79 = & V_20 -> V_21 [ V_80 ] ;
V_79 -> V_94 = V_95 ;
V_79 -> V_7 = & V_99 -> V_72 ;
V_8 = F_47 ( V_95 , L_10 , NULL ) ;
if ( ! V_8 )
continue;
V_79 -> V_8 = F_48 ( V_8 ) ;
if ( V_79 -> V_8 > V_107 )
continue;
F_56 (child, port) {
V_102 = F_47 ( V_98 , L_10 , NULL ) ;
if ( ! V_102 )
continue;
V_90 = F_48 ( V_102 ) ;
V_101 = F_47 ( V_98 , L_13 , NULL ) ;
if ( ! V_101 )
continue;
V_79 -> V_108 [ V_90 ] = V_98 ;
V_79 -> V_34 [ V_90 ] = F_57 ( V_101 ,
V_30 ) ;
if ( ! V_79 -> V_34 [ V_90 ] ) {
V_10 = - V_31 ;
goto V_109;
}
V_82 = F_52 ( V_98 , L_14 , 0 ) ;
if ( ! strcmp ( V_101 , L_5 ) && V_82 &&
V_20 -> V_66 > 1 ) {
V_10 = F_45 ( V_20 , V_79 ,
V_80 , V_82 ) ;
if ( V_10 )
goto V_109;
}
if ( V_90 == V_33 )
break;
}
}
return 0 ;
V_109:
F_50 ( V_20 ) ;
V_57:
F_23 ( V_20 ) ;
V_92 -> V_72 . V_104 = NULL ;
return V_10 ;
}
static void F_58 ( struct V_91 * V_92 )
{
struct V_78 * V_20 = V_92 -> V_72 . V_104 ;
if ( ! V_92 -> V_72 . V_94 )
return;
F_50 ( V_20 ) ;
F_23 ( V_20 ) ;
}
static inline int F_51 ( struct V_91 * V_92 )
{
return 0 ;
}
static inline void F_58 ( struct V_91 * V_92 )
{
}
static int F_59 ( struct V_91 * V_92 )
{
static int V_110 ;
struct V_78 * V_20 = V_92 -> V_72 . V_104 ;
struct V_58 * V_72 ;
struct V_15 * V_16 ;
int V_23 , V_10 ;
if ( ! V_110 ++ )
F_11 ( V_111 L_15
L_16 , V_112 ) ;
if ( V_92 -> V_72 . V_94 ) {
V_10 = F_51 ( V_92 ) ;
if ( V_10 )
return V_10 ;
V_20 = V_92 -> V_72 . V_104 ;
}
if ( V_20 == NULL || V_20 -> V_105 == NULL )
return - V_27 ;
V_72 = F_42 ( V_20 -> V_105 ) ;
if ( V_72 == NULL ) {
V_10 = - V_27 ;
goto V_36;
}
if ( V_72 -> V_113 != NULL ) {
F_60 ( V_72 ) ;
V_10 = - V_114 ;
goto V_36;
}
V_16 = F_13 ( sizeof( * V_16 ) , V_30 ) ;
if ( V_16 == NULL ) {
F_60 ( V_72 ) ;
V_10 = - V_31 ;
goto V_36;
}
F_61 ( V_92 , V_16 ) ;
V_16 -> V_20 = V_20 ;
V_16 -> V_26 = V_72 ;
V_16 -> V_35 = - 1 ;
V_16 -> V_37 = - 1 ;
for ( V_23 = 0 ; V_23 < V_20 -> V_66 ; V_23 ++ ) {
struct V_14 * V_22 ;
V_22 = F_10 ( V_16 , V_23 , & V_92 -> V_72 , V_20 -> V_21 [ V_23 ] . V_7 ) ;
if ( F_62 ( V_22 ) ) {
F_11 ( V_25 L_17
L_18 , V_72 -> V_12 , V_23 ,
F_63 ( V_22 ) ) ;
continue;
}
V_16 -> V_22 [ V_23 ] = V_22 ;
if ( V_22 -> V_2 -> V_67 != NULL )
V_16 -> V_115 = 1 ;
}
F_64 () ;
V_72 -> V_113 = ( void * ) V_16 ;
if ( V_16 -> V_115 ) {
F_65 ( & V_16 -> V_65 , F_29 ) ;
F_66 ( & V_16 -> V_68 ) ;
V_16 -> V_68 . V_116 = ( unsigned long ) V_16 ;
V_16 -> V_68 . V_117 = F_33 ;
V_16 -> V_68 . V_118 = F_32 ( V_69 + V_70 ) ;
F_67 ( & V_16 -> V_68 ) ;
}
return 0 ;
V_36:
F_58 ( V_92 ) ;
return V_10 ;
}
static int F_68 ( struct V_91 * V_92 )
{
struct V_15 * V_16 = F_69 ( V_92 ) ;
int V_23 ;
if ( V_16 -> V_115 )
F_70 ( & V_16 -> V_68 ) ;
F_71 ( & V_16 -> V_65 ) ;
for ( V_23 = 0 ; V_23 < V_16 -> V_20 -> V_66 ; V_23 ++ ) {
struct V_14 * V_22 = V_16 -> V_22 [ V_23 ] ;
if ( V_22 != NULL )
F_24 ( V_22 ) ;
}
F_58 ( V_92 ) ;
return 0 ;
}
static void F_72 ( struct V_91 * V_92 )
{
}
static int F_73 ( struct V_119 * V_120 , struct V_58 * V_72 ,
struct V_121 * V_122 , struct V_58 * V_123 )
{
struct V_15 * V_16 = V_72 -> V_113 ;
if ( F_74 ( V_16 == NULL ) ) {
F_75 ( V_120 ) ;
return 0 ;
}
return V_16 -> V_43 ( V_120 , V_72 , V_122 , V_123 ) ;
}
static int F_76 ( struct V_6 * V_75 )
{
struct V_91 * V_92 = F_77 ( V_75 ) ;
struct V_15 * V_16 = F_69 ( V_92 ) ;
int V_23 , V_10 = 0 ;
for ( V_23 = 0 ; V_23 < V_16 -> V_20 -> V_66 ; V_23 ++ ) {
struct V_14 * V_22 = V_16 -> V_22 [ V_23 ] ;
if ( V_22 != NULL )
V_10 = F_25 ( V_22 ) ;
}
return V_10 ;
}
static int F_78 ( struct V_6 * V_75 )
{
struct V_91 * V_92 = F_77 ( V_75 ) ;
struct V_15 * V_16 = F_69 ( V_92 ) ;
int V_23 , V_10 = 0 ;
for ( V_23 = 0 ; V_23 < V_16 -> V_20 -> V_66 ; V_23 ++ ) {
struct V_14 * V_22 = V_16 -> V_22 [ V_23 ] ;
if ( V_22 != NULL )
V_10 = F_27 ( V_22 ) ;
}
return V_10 ;
}
static int T_2 F_79 ( void )
{
int V_124 ;
V_124 = F_80 ( & V_125 ) ;
if ( V_124 )
return V_124 ;
F_81 ( & V_126 ) ;
return 0 ;
}
static void T_3 F_82 ( void )
{
F_83 ( & V_126 ) ;
F_84 ( & V_125 ) ;
}
