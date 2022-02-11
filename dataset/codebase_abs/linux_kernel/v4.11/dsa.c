static struct V_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return V_2 ;
}
void F_2 ( struct V_5 * V_6 )
{
F_3 ( & V_7 ) ;
F_4 ( & V_6 -> V_8 , & V_9 ) ;
F_5 ( & V_7 ) ;
}
void F_6 ( struct V_5 * V_6 )
{
F_3 ( & V_7 ) ;
F_7 ( & V_6 -> V_8 ) ;
F_5 ( & V_7 ) ;
}
static const struct V_10 *
F_8 ( struct V_11 * V_12 , struct V_11 * V_13 , int V_14 ,
const char * * V_15 , void * * V_16 )
{
const struct V_10 * V_17 ;
struct V_18 * V_8 ;
const char * V_19 ;
V_17 = NULL ;
V_19 = NULL ;
F_3 ( & V_7 ) ;
F_9 (list, &dsa_switch_drivers) {
const struct V_10 * V_20 ;
struct V_5 * V_6 ;
V_6 = F_10 ( V_8 , struct V_5 , V_8 ) ;
V_20 = V_6 -> V_20 ;
V_19 = V_20 -> V_21 ( V_12 , V_13 , V_14 , V_16 ) ;
if ( V_19 != NULL ) {
V_17 = V_20 ;
break;
}
}
F_5 ( & V_7 ) ;
* V_15 = V_19 ;
return V_17 ;
}
int F_11 ( struct V_22 * V_23 , struct V_11 * V_4 ,
struct V_24 * V_25 , int V_26 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
struct V_30 * V_31 ;
int V_17 , V_32 ;
if ( F_12 ( V_28 ) ) {
V_17 = F_13 ( V_28 ) ;
if ( V_17 ) {
F_14 ( V_4 , L_1 ) ;
return V_17 ;
}
V_31 = F_15 ( V_28 ) ;
V_32 = F_16 ( V_28 ) ;
if ( V_32 < 0 )
V_32 = V_33 ;
V_31 -> V_34 = V_32 ;
F_17 ( V_31 ) ;
F_18 ( V_31 ) ;
if ( V_23 -> V_20 -> V_35 )
V_23 -> V_20 -> V_35 ( V_23 , V_26 , V_31 ) ;
F_19 ( & V_31 -> V_36 . V_4 ) ;
}
return 0 ;
}
static int F_20 ( struct V_22 * V_23 , struct V_11 * V_4 )
{
struct V_24 * V_25 ;
int V_17 , V_26 ;
for ( V_26 = 0 ; V_26 < V_23 -> V_37 ; V_26 ++ ) {
if ( ! ( F_21 ( V_23 , V_26 ) || F_22 ( V_23 , V_26 ) ) )
continue;
V_25 = & V_23 -> V_38 [ V_26 ] ;
V_17 = F_11 ( V_23 , V_4 , V_25 , V_26 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
const struct V_39 * F_23 ( int V_40 )
{
const struct V_39 * V_20 ;
if ( V_40 >= V_41 )
return F_24 ( - V_42 ) ;
V_20 = V_39 [ V_40 ] ;
if ( ! V_20 )
return F_24 ( - V_43 ) ;
return V_20 ;
}
int F_25 ( struct V_22 * V_23 )
{
struct V_3 * V_44 ;
struct V_45 * V_46 ;
V_44 = V_23 -> V_47 -> V_48 ;
if ( V_23 -> V_48 )
V_44 = V_23 -> V_48 ;
V_46 = F_26 ( V_23 -> V_4 , sizeof( * V_46 ) , V_49 ) ;
if ( ! V_46 )
return - V_50 ;
memcpy ( & V_23 -> V_47 -> V_51 , V_44 -> V_45 ,
sizeof( struct V_45 ) ) ;
V_23 -> V_47 -> V_52 = V_44 -> V_45 ;
memcpy ( V_46 , & V_23 -> V_47 -> V_51 ,
sizeof( struct V_45 ) ) ;
F_27 ( V_46 ) ;
V_44 -> V_45 = V_46 ;
return 0 ;
}
void F_28 ( struct V_22 * V_23 )
{
struct V_3 * V_44 ;
V_44 = V_23 -> V_47 -> V_48 ;
if ( V_23 -> V_48 )
V_44 = V_23 -> V_48 ;
V_44 -> V_45 = V_23 -> V_47 -> V_52 ;
}
static int F_29 ( struct V_22 * V_23 , struct V_11 * V_12 )
{
const struct V_10 * V_20 = V_23 -> V_20 ;
struct V_53 * V_47 = V_23 -> V_47 ;
struct V_54 * V_55 = V_23 -> V_55 ;
bool V_56 = false ;
int V_57 = V_23 -> V_57 ;
int V_58 , V_17 ;
for ( V_58 = 0 ; V_58 < V_23 -> V_37 ; V_58 ++ ) {
char * V_19 ;
V_19 = V_55 -> V_59 [ V_58 ] ;
if ( V_19 == NULL )
continue;
if ( ! strcmp ( V_19 , L_2 ) ) {
if ( V_47 -> V_60 ) {
F_30 ( V_47 -> V_48 ,
L_3 ) ;
return - V_42 ;
}
V_47 -> V_60 = V_23 ;
V_47 -> V_61 = V_58 ;
V_23 -> V_62 |= 1 << V_58 ;
} else if ( ! strcmp ( V_19 , L_4 ) ) {
V_23 -> V_63 |= 1 << V_58 ;
} else {
V_23 -> V_64 |= 1 << V_58 ;
}
V_56 = true ;
}
if ( ! V_56 && V_58 == V_23 -> V_37 )
return - V_42 ;
V_23 -> V_65 = V_23 -> V_64 ;
if ( V_47 -> V_60 == V_23 ) {
enum V_66 V_40 ;
V_40 = V_20 -> V_67 ( V_23 ) ;
V_47 -> V_68 = F_23 ( V_40 ) ;
if ( F_31 ( V_47 -> V_68 ) )
return F_32 ( V_47 -> V_68 ) ;
V_47 -> V_69 = V_47 -> V_68 -> V_69 ;
}
memcpy ( V_23 -> V_70 , V_55 -> V_70 , sizeof( V_23 -> V_70 ) ) ;
V_17 = V_20 -> V_71 ( V_23 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_33 ( V_23 ) ;
if ( V_17 )
return V_17 ;
if ( V_20 -> V_72 ) {
V_17 = V_20 -> V_72 ( V_23 , V_47 -> V_48 -> V_73 ) ;
if ( V_17 < 0 )
return V_17 ;
}
if ( ! V_23 -> V_74 && V_20 -> V_75 ) {
V_23 -> V_74 = F_34 ( V_12 ) ;
if ( ! V_23 -> V_74 )
return - V_50 ;
F_35 ( V_23 ) ;
V_17 = F_36 ( V_23 -> V_74 ) ;
if ( V_17 < 0 )
return V_17 ;
}
for ( V_58 = 0 ; V_58 < V_23 -> V_37 ; V_58 ++ ) {
V_23 -> V_38 [ V_58 ] . V_29 = V_55 -> V_28 [ V_58 ] ;
if ( ! ( V_23 -> V_64 & ( 1 << V_58 ) ) )
continue;
V_17 = F_37 ( V_23 , V_12 , V_58 , V_55 -> V_59 [ V_58 ] ) ;
if ( V_17 < 0 )
F_30 ( V_47 -> V_48 , L_5 ,
V_57 , V_58 , V_55 -> V_59 [ V_58 ] , V_17 ) ;
}
V_17 = F_20 ( V_23 , V_12 ) ;
if ( V_17 < 0 )
F_30 ( V_47 -> V_48 , L_6 ,
V_57 ) ;
V_17 = F_25 ( V_23 ) ;
if ( V_17 )
return V_17 ;
return 0 ;
}
static struct V_22 *
F_38 ( struct V_53 * V_47 , int V_57 ,
struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_54 * V_55 = V_47 -> V_76 -> V_77 + V_57 ;
const struct V_10 * V_20 ;
struct V_22 * V_23 ;
int V_17 ;
const char * V_19 ;
void * V_16 ;
V_20 = F_8 ( V_12 , V_13 , V_55 -> V_14 , & V_19 , & V_16 ) ;
if ( ! V_20 ) {
F_30 ( V_47 -> V_48 , L_7 ,
V_57 ) ;
return F_24 ( - V_42 ) ;
}
F_39 ( V_47 -> V_48 , L_8 ,
V_57 , V_19 ) ;
V_23 = F_40 ( V_12 , V_78 ) ;
if ( ! V_23 )
return F_24 ( - V_50 ) ;
V_23 -> V_47 = V_47 ;
V_23 -> V_57 = V_57 ;
V_23 -> V_55 = V_55 ;
V_23 -> V_20 = V_20 ;
V_23 -> V_16 = V_16 ;
V_17 = F_29 ( V_23 , V_12 ) ;
if ( V_17 )
return F_24 ( V_17 ) ;
return V_23 ;
}
void F_41 ( struct V_24 * V_26 )
{
struct V_27 * V_28 = V_26 -> V_29 ;
if ( F_12 ( V_28 ) )
F_42 ( V_28 ) ;
}
static void F_43 ( struct V_22 * V_23 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_23 -> V_37 ; V_26 ++ ) {
if ( ! ( V_23 -> V_64 & ( 1 << V_26 ) ) )
continue;
if ( ! V_23 -> V_38 [ V_26 ] . V_79 )
continue;
F_44 ( V_23 -> V_38 [ V_26 ] . V_79 ) ;
}
for ( V_26 = 0 ; V_26 < V_23 -> V_37 ; V_26 ++ ) {
if ( ! ( F_21 ( V_23 , V_26 ) || F_22 ( V_23 , V_26 ) ) )
continue;
F_41 ( & V_23 -> V_38 [ V_26 ] ) ;
V_23 -> V_62 |= ~ ( 1 << V_26 ) ;
V_23 -> V_63 |= ~ ( 1 << V_26 ) ;
}
if ( V_23 -> V_74 && V_23 -> V_20 -> V_75 )
F_45 ( V_23 -> V_74 ) ;
F_46 ( V_23 ) ;
}
int F_47 ( struct V_22 * V_23 )
{
int V_58 , V_17 = 0 ;
for ( V_58 = 0 ; V_58 < V_23 -> V_37 ; V_58 ++ ) {
if ( ! F_48 ( V_23 , V_58 ) )
continue;
V_17 = F_49 ( V_23 -> V_38 [ V_58 ] . V_79 ) ;
if ( V_17 )
return V_17 ;
}
if ( V_23 -> V_20 -> V_80 )
V_17 = V_23 -> V_20 -> V_80 ( V_23 ) ;
return V_17 ;
}
int F_50 ( struct V_22 * V_23 )
{
int V_58 , V_17 = 0 ;
if ( V_23 -> V_20 -> V_81 )
V_17 = V_23 -> V_20 -> V_81 ( V_23 ) ;
if ( V_17 )
return V_17 ;
for ( V_58 = 0 ; V_58 < V_23 -> V_37 ; V_58 ++ ) {
if ( ! F_48 ( V_23 , V_58 ) )
continue;
V_17 = F_51 ( V_23 -> V_38 [ V_58 ] . V_79 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_52 ( struct V_11 * V_4 , void * V_82 )
{
if ( V_4 -> V_82 != NULL && ! strcmp ( V_4 -> V_82 -> V_19 , V_82 ) )
return 1 ;
return 0 ;
}
static struct V_11 * F_53 ( struct V_11 * V_12 , char * V_82 )
{
if ( F_52 ( V_12 , V_82 ) ) {
F_54 ( V_12 ) ;
return V_12 ;
}
return F_55 ( V_12 , V_82 , F_52 ) ;
}
struct V_83 * F_56 ( struct V_11 * V_4 )
{
struct V_11 * V_84 ;
V_84 = F_53 ( V_4 , L_9 ) ;
if ( V_84 != NULL ) {
struct V_83 * V_85 ;
V_85 = F_57 ( V_84 ) ;
F_19 ( V_84 ) ;
return V_85 ;
}
return NULL ;
}
struct V_3 * F_58 ( struct V_11 * V_4 )
{
struct V_11 * V_84 ;
V_84 = F_53 ( V_4 , L_10 ) ;
if ( V_84 != NULL ) {
struct V_3 * V_86 ;
V_86 = F_59 ( V_84 ) ;
F_60 ( V_86 ) ;
F_19 ( V_84 ) ;
return V_86 ;
}
return NULL ;
}
static int F_61 ( struct V_87 * V_76 ,
struct V_54 * V_55 ,
int V_88 , int V_89 ,
struct V_27 * V_90 )
{
const T_1 * V_91 ;
int V_92 ;
struct V_27 * V_93 ;
int V_94 ;
V_93 = F_62 ( V_90 ) ;
if ( ! V_93 )
return - V_42 ;
V_91 = F_63 ( V_93 , L_11 , & V_94 ) ;
if ( ! V_91 || ( V_94 != sizeof( * V_91 ) * 2 ) )
return - V_42 ;
V_92 = F_64 ( V_91 + 1 ) ;
if ( V_92 >= V_76 -> V_95 )
return - V_42 ;
V_55 -> V_70 [ V_92 ] = V_89 ;
return 0 ;
}
static int F_65 ( struct V_87 * V_76 ,
struct V_54 * V_55 ,
int V_88 , int V_89 ,
struct V_27 * V_26 ,
const char * V_96 )
{
struct V_27 * V_90 ;
int V_97 ;
int V_17 ;
for ( V_97 = 0 ; ; V_97 ++ ) {
V_90 = F_66 ( V_26 , L_12 , V_97 ) ;
if ( ! V_90 )
break;
if ( ! strcmp ( V_96 , L_4 ) && V_76 -> V_95 > 1 ) {
V_17 = F_61 ( V_76 , V_55 , V_88 ,
V_89 , V_90 ) ;
if ( V_17 )
return V_17 ;
}
}
return 0 ;
}
static void F_67 ( struct V_87 * V_76 )
{
int V_58 ;
int V_89 ;
for ( V_58 = 0 ; V_58 < V_76 -> V_95 ; V_58 ++ ) {
V_89 = 0 ;
while ( V_89 < V_78 ) {
F_68 ( V_76 -> V_77 [ V_58 ] . V_59 [ V_89 ] ) ;
V_89 ++ ;
}
if ( V_76 -> V_77 [ V_58 ] . V_13 )
F_19 ( V_76 -> V_77 [ V_58 ] . V_13 ) ;
}
F_68 ( V_76 -> V_77 ) ;
}
static int F_69 ( struct V_11 * V_4 )
{
struct V_27 * V_98 = V_4 -> V_99 ;
struct V_27 * V_100 , * V_36 , * V_101 , * V_26 ;
struct V_83 * V_102 , * V_103 ;
struct V_3 * V_104 ;
struct V_87 * V_76 ;
struct V_54 * V_55 ;
const char * V_96 ;
int V_88 , V_89 ;
const unsigned int * V_14 , * V_105 ;
T_2 V_106 ;
int V_17 ;
V_36 = F_66 ( V_98 , L_13 , 0 ) ;
if ( ! V_36 )
return - V_42 ;
V_102 = F_70 ( V_36 ) ;
if ( ! V_102 )
return - V_107 ;
V_101 = F_66 ( V_98 , L_14 , 0 ) ;
if ( ! V_101 ) {
V_17 = - V_42 ;
goto V_108;
}
V_104 = F_71 ( V_101 ) ;
if ( ! V_104 ) {
V_17 = - V_107 ;
goto V_108;
}
V_76 = F_72 ( sizeof( * V_76 ) , V_49 ) ;
if ( ! V_76 ) {
V_17 = - V_50 ;
goto V_109;
}
V_4 -> V_110 = V_76 ;
V_76 -> V_111 = V_104 ;
V_76 -> V_95 = F_73 ( V_98 ) ;
if ( V_76 -> V_95 > V_112 )
V_76 -> V_95 = V_112 ;
V_76 -> V_77 = F_74 ( V_76 -> V_95 , sizeof( struct V_54 ) ,
V_49 ) ;
if ( ! V_76 -> V_77 ) {
V_17 = - V_50 ;
goto V_113;
}
V_88 = - 1 ;
F_75 (np, child) {
int V_58 ;
V_88 ++ ;
V_55 = & V_76 -> V_77 [ V_88 ] ;
V_55 -> V_99 = V_100 ;
for ( V_58 = 0 ; V_58 < V_112 ; ++ V_58 )
V_55 -> V_70 [ V_58 ] = V_114 ;
V_55 -> V_13 = F_54 ( & V_102 -> V_4 ) ;
V_14 = F_63 ( V_100 , L_11 , NULL ) ;
if ( ! V_14 )
continue;
V_55 -> V_14 = F_64 ( V_14 ) ;
if ( V_55 -> V_14 >= V_115 )
continue;
if ( ! F_76 ( V_100 , L_15 , & V_106 ) )
V_55 -> V_106 = V_106 ;
V_36 = F_66 ( V_100 , L_16 , 0 ) ;
if ( V_36 ) {
V_103 = F_70 ( V_36 ) ;
if ( ! V_103 ) {
V_17 = - V_107 ;
goto V_116;
}
F_19 ( V_55 -> V_13 ) ;
V_55 -> V_13 = & V_103 -> V_4 ;
}
F_75 (child, port) {
V_105 = F_63 ( V_26 , L_11 , NULL ) ;
if ( ! V_105 )
continue;
V_89 = F_64 ( V_105 ) ;
if ( V_89 >= V_78 )
break;
V_96 = F_63 ( V_26 , L_17 , NULL ) ;
if ( ! V_96 )
continue;
V_55 -> V_28 [ V_89 ] = V_26 ;
V_55 -> V_59 [ V_89 ] = F_77 ( V_96 ,
V_49 ) ;
if ( ! V_55 -> V_59 [ V_89 ] ) {
V_17 = - V_50 ;
goto V_116;
}
V_17 = F_65 ( V_76 , V_55 , V_88 ,
V_89 , V_26 , V_96 ) ;
if ( V_17 )
goto V_116;
}
}
F_19 ( & V_102 -> V_4 ) ;
return 0 ;
V_116:
F_67 ( V_76 ) ;
V_113:
F_68 ( V_76 ) ;
V_4 -> V_110 = NULL ;
V_109:
F_19 ( & V_104 -> V_4 ) ;
V_108:
F_19 ( & V_102 -> V_4 ) ;
return V_17 ;
}
static void F_78 ( struct V_11 * V_4 )
{
struct V_87 * V_76 = V_4 -> V_110 ;
if ( ! V_4 -> V_99 )
return;
F_67 ( V_76 ) ;
F_19 ( & V_76 -> V_111 -> V_4 ) ;
F_68 ( V_76 ) ;
}
static inline int F_69 ( struct V_11 * V_4 )
{
return 0 ;
}
static inline void F_78 ( struct V_11 * V_4 )
{
}
static int F_79 ( struct V_53 * V_47 , struct V_3 * V_4 ,
struct V_11 * V_12 , struct V_87 * V_76 )
{
int V_58 ;
unsigned V_117 = 0 ;
V_47 -> V_76 = V_76 ;
V_47 -> V_48 = V_4 ;
V_47 -> V_61 = - 1 ;
for ( V_58 = 0 ; V_58 < V_76 -> V_95 ; V_58 ++ ) {
struct V_22 * V_23 ;
V_23 = F_38 ( V_47 , V_58 , V_12 , V_76 -> V_77 [ V_58 ] . V_13 ) ;
if ( F_31 ( V_23 ) ) {
F_30 ( V_4 , L_18 ,
V_58 , F_32 ( V_23 ) ) ;
continue;
}
V_47 -> V_23 [ V_58 ] = V_23 ;
++ V_117 ;
}
if ( ! V_117 )
return - V_107 ;
F_80 () ;
V_4 -> V_118 = ( void * ) V_47 ;
return 0 ;
}
static int F_81 ( struct V_119 * V_120 )
{
struct V_87 * V_76 = V_120 -> V_4 . V_110 ;
struct V_3 * V_4 ;
struct V_53 * V_47 ;
int V_17 ;
if ( V_120 -> V_4 . V_99 ) {
V_17 = F_69 ( & V_120 -> V_4 ) ;
if ( V_17 )
return V_17 ;
V_76 = V_120 -> V_4 . V_110 ;
}
if ( V_76 == NULL || ( V_76 -> V_79 == NULL && V_76 -> V_111 == NULL ) )
return - V_42 ;
if ( V_76 -> V_111 ) {
V_4 = V_76 -> V_111 ;
F_60 ( V_4 ) ;
} else {
V_4 = F_58 ( V_76 -> V_79 ) ;
}
if ( V_4 == NULL ) {
V_17 = - V_107 ;
goto V_121;
}
if ( V_4 -> V_118 != NULL ) {
F_82 ( V_4 ) ;
V_17 = - V_122 ;
goto V_121;
}
V_47 = F_26 ( & V_120 -> V_4 , sizeof( * V_47 ) , V_49 ) ;
if ( V_47 == NULL ) {
F_82 ( V_4 ) ;
V_17 = - V_50 ;
goto V_121;
}
F_83 ( V_120 , V_47 ) ;
V_17 = F_79 ( V_47 , V_4 , & V_120 -> V_4 , V_76 ) ;
if ( V_17 ) {
F_82 ( V_4 ) ;
goto V_121;
}
return 0 ;
V_121:
F_78 ( & V_120 -> V_4 ) ;
return V_17 ;
}
static void F_84 ( struct V_53 * V_47 )
{
int V_58 ;
V_47 -> V_48 -> V_118 = NULL ;
F_80 () ;
for ( V_58 = 0 ; V_58 < V_47 -> V_76 -> V_95 ; V_58 ++ ) {
struct V_22 * V_23 = V_47 -> V_23 [ V_58 ] ;
if ( V_23 )
F_43 ( V_23 ) ;
}
F_28 ( V_47 -> V_60 ) ;
F_82 ( V_47 -> V_48 ) ;
}
static int F_85 ( struct V_119 * V_120 )
{
struct V_53 * V_47 = F_86 ( V_120 ) ;
F_84 ( V_47 ) ;
F_78 ( & V_120 -> V_4 ) ;
return 0 ;
}
static void F_87 ( struct V_119 * V_120 )
{
}
static int F_88 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_123 * V_124 , struct V_3 * V_125 )
{
struct V_53 * V_47 = V_4 -> V_118 ;
if ( F_89 ( V_47 == NULL ) ) {
F_90 ( V_2 ) ;
return 0 ;
}
return V_47 -> V_69 ( V_2 , V_4 , V_124 , V_125 ) ;
}
static int F_91 ( struct V_11 * V_84 )
{
struct V_119 * V_120 = F_92 ( V_84 ) ;
struct V_53 * V_47 = F_86 ( V_120 ) ;
int V_58 , V_17 = 0 ;
for ( V_58 = 0 ; V_58 < V_47 -> V_76 -> V_95 ; V_58 ++ ) {
struct V_22 * V_23 = V_47 -> V_23 [ V_58 ] ;
if ( V_23 != NULL )
V_17 = F_47 ( V_23 ) ;
}
return V_17 ;
}
static int F_93 ( struct V_11 * V_84 )
{
struct V_119 * V_120 = F_92 ( V_84 ) ;
struct V_53 * V_47 = F_86 ( V_120 ) ;
int V_58 , V_17 = 0 ;
for ( V_58 = 0 ; V_58 < V_47 -> V_76 -> V_95 ; V_58 ++ ) {
struct V_22 * V_23 = V_47 -> V_23 [ V_58 ] ;
if ( V_23 != NULL )
V_17 = F_50 ( V_23 ) ;
}
return V_17 ;
}
static int T_3 F_94 ( void )
{
int V_126 ;
V_126 = F_95 () ;
if ( V_126 )
return V_126 ;
V_126 = F_96 ( & V_127 ) ;
if ( V_126 )
return V_126 ;
F_97 ( & V_128 ) ;
return 0 ;
}
static void T_4 F_98 ( void )
{
F_99 () ;
F_100 ( & V_128 ) ;
F_101 ( & V_127 ) ;
}
