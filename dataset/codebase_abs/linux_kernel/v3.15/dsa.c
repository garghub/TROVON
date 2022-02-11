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
struct V_18 * V_19 , struct V_6 * V_7 )
{
struct V_20 * V_21 = V_16 -> V_21 -> V_22 + V_17 ;
struct V_1 * V_2 ;
struct V_14 * V_23 ;
int V_10 ;
char * V_12 ;
int V_24 ;
bool V_25 = false ;
V_2 = F_7 ( V_7 , V_21 -> V_8 , & V_12 ) ;
if ( V_2 == NULL ) {
F_11 ( V_26 L_1 ,
V_16 -> V_27 -> V_12 , V_17 ) ;
return F_12 ( - V_28 ) ;
}
F_11 ( V_29 L_2 ,
V_16 -> V_27 -> V_12 , V_17 , V_12 ) ;
V_23 = F_13 ( sizeof( * V_23 ) + V_2 -> V_30 , V_31 ) ;
if ( V_23 == NULL )
return F_12 ( - V_32 ) ;
V_23 -> V_16 = V_16 ;
V_23 -> V_17 = V_17 ;
V_23 -> V_21 = V_16 -> V_21 -> V_22 + V_17 ;
V_23 -> V_2 = V_2 ;
V_23 -> V_33 = V_7 ;
for ( V_24 = 0 ; V_24 < V_34 ; V_24 ++ ) {
char * V_12 ;
V_12 = V_21 -> V_35 [ V_24 ] ;
if ( V_12 == NULL )
continue;
if ( ! strcmp ( V_12 , L_3 ) ) {
if ( V_16 -> V_36 != - 1 ) {
F_11 ( V_26 L_4 ) ;
V_10 = - V_28 ;
goto V_37;
}
V_16 -> V_36 = V_17 ;
V_16 -> V_38 = V_24 ;
} else if ( ! strcmp ( V_12 , L_5 ) ) {
V_23 -> V_39 |= 1 << V_24 ;
} else {
V_23 -> V_40 |= 1 << V_24 ;
}
V_25 = true ;
}
if ( ! V_25 && V_24 == V_34 ) {
V_10 = - V_28 ;
goto V_37;
}
if ( V_23 -> V_16 -> V_36 == V_17 )
V_23 -> V_16 -> V_41 = V_2 -> V_41 ;
V_10 = V_2 -> V_42 ( V_23 ) ;
if ( V_10 < 0 )
goto V_37;
V_10 = V_2 -> V_43 ( V_23 , V_16 -> V_27 -> V_44 ) ;
if ( V_10 < 0 )
goto V_37;
V_23 -> V_45 = F_14 () ;
if ( V_23 -> V_45 == NULL ) {
V_10 = - V_32 ;
goto V_37;
}
F_15 ( V_23 ) ;
V_10 = F_16 ( V_23 -> V_45 ) ;
if ( V_10 < 0 )
goto V_46;
for ( V_24 = 0 ; V_24 < V_34 ; V_24 ++ ) {
struct V_47 * V_48 ;
if ( ! ( V_23 -> V_40 & ( 1 << V_24 ) ) )
continue;
V_48 = F_17 ( V_23 , V_19 , V_24 , V_21 -> V_35 [ V_24 ] ) ;
if ( V_48 == NULL ) {
F_11 ( V_26 L_6
L_7 ,
V_16 -> V_27 -> V_12 ,
V_17 , V_24 , V_21 -> V_35 [ V_24 ] ) ;
continue;
}
V_23 -> V_49 [ V_24 ] = V_48 ;
}
return V_23 ;
V_46:
F_18 ( V_23 -> V_45 ) ;
V_37:
F_19 ( V_23 ) ;
return F_12 ( V_10 ) ;
}
static void F_20 ( struct V_14 * V_23 )
{
}
static void F_21 ( struct V_50 * V_51 )
{
struct V_15 * V_16 ;
int V_24 ;
V_16 = F_22 ( V_51 , struct V_15 , V_52 ) ;
for ( V_24 = 0 ; V_24 < V_16 -> V_21 -> V_53 ; V_24 ++ ) {
struct V_14 * V_23 = V_16 -> V_23 [ V_24 ] ;
if ( V_23 != NULL && V_23 -> V_2 -> V_54 != NULL )
V_23 -> V_2 -> V_54 ( V_23 ) ;
}
F_23 ( & V_16 -> V_55 , F_24 ( V_56 + V_57 ) ) ;
}
static void F_25 ( unsigned long V_58 )
{
struct V_15 * V_16 = ( void * ) V_58 ;
F_26 ( & V_16 -> V_52 ) ;
}
static int F_27 ( struct V_18 * V_59 , void * V_60 )
{
if ( V_59 -> V_60 != NULL && ! strcmp ( V_59 -> V_60 -> V_12 , V_60 ) )
return 1 ;
return 0 ;
}
static struct V_18 * F_28 ( struct V_18 * V_19 , char * V_60 )
{
if ( F_27 ( V_19 , V_60 ) ) {
F_29 ( V_19 ) ;
return V_19 ;
}
return F_30 ( V_19 , V_60 , F_27 ) ;
}
static struct V_6 * F_31 ( struct V_18 * V_59 )
{
struct V_18 * V_61 ;
V_61 = F_28 ( V_59 , L_8 ) ;
if ( V_61 != NULL ) {
struct V_6 * V_7 ;
V_7 = F_32 ( V_61 ) ;
F_33 ( V_61 ) ;
return V_7 ;
}
return NULL ;
}
static struct V_47 * F_34 ( struct V_18 * V_59 )
{
struct V_18 * V_61 ;
V_61 = F_28 ( V_59 , L_9 ) ;
if ( V_61 != NULL ) {
struct V_47 * V_62 ;
V_62 = F_35 ( V_61 ) ;
F_36 ( V_62 ) ;
F_33 ( V_61 ) ;
return V_62 ;
}
return NULL ;
}
static int F_37 ( struct V_63 * V_21 ,
struct V_20 * V_64 ,
int V_65 ,
struct V_66 * V_67 )
{
int V_10 ;
const T_1 * V_68 ;
int V_69 ;
int V_70 ;
struct V_66 * V_71 ;
int V_72 ;
V_71 = F_38 ( V_67 ) ;
if ( ! V_71 )
return - V_28 ;
V_68 = F_39 ( V_71 , L_10 , & V_72 ) ;
if ( ! V_68 || ( V_72 != sizeof( * V_68 ) * 2 ) )
return - V_28 ;
V_70 = F_40 ( V_68 + 1 ) ;
if ( V_70 >= V_21 -> V_53 )
return - V_28 ;
if ( ! V_64 -> V_73 ) {
V_64 -> V_73 = F_41 ( V_21 -> V_53 * sizeof( V_74 ) , V_31 ) ;
if ( ! V_64 -> V_73 )
return - V_32 ;
memset ( V_64 -> V_73 , - 1 , V_21 -> V_53 * sizeof( V_74 ) ) ;
}
V_68 = F_39 ( V_67 , L_10 , NULL ) ;
if ( ! V_68 ) {
V_10 = - V_28 ;
goto V_37;
}
V_69 = F_40 ( V_68 ) ;
V_64 -> V_73 [ V_70 ] = V_69 ;
return 0 ;
V_37:
F_19 ( V_64 -> V_73 ) ;
return V_10 ;
}
static void F_42 ( struct V_63 * V_21 )
{
int V_24 ;
int V_75 ;
for ( V_24 = 0 ; V_24 < V_21 -> V_53 ; V_24 ++ ) {
V_75 = 0 ;
while ( V_75 < V_34 ) {
if ( V_21 -> V_22 [ V_24 ] . V_35 [ V_75 ] )
F_19 ( V_21 -> V_22 [ V_24 ] . V_35 [ V_75 ] ) ;
V_75 ++ ;
}
F_19 ( V_21 -> V_22 [ V_24 ] . V_73 ) ;
}
F_19 ( V_21 -> V_22 ) ;
}
static int F_43 ( struct V_76 * V_77 )
{
struct V_66 * V_78 = V_77 -> V_59 . V_79 ;
struct V_66 * V_80 , * V_81 , * V_82 , * V_83 , * V_67 ;
struct V_6 * V_84 ;
struct V_76 * V_85 ;
struct V_63 * V_21 ;
struct V_20 * V_64 ;
const char * V_86 ;
int V_65 , V_75 ;
const unsigned int * V_8 , * V_87 ;
int V_10 ;
V_81 = F_44 ( V_78 , L_11 , 0 ) ;
if ( ! V_81 )
return - V_28 ;
V_84 = F_45 ( V_81 ) ;
if ( ! V_84 )
return - V_28 ;
V_82 = F_44 ( V_78 , L_12 , 0 ) ;
if ( ! V_82 )
return - V_28 ;
V_85 = F_46 ( V_82 ) ;
if ( ! V_85 )
return - V_88 ;
V_21 = F_13 ( sizeof( * V_21 ) , V_31 ) ;
if ( ! V_21 )
return - V_32 ;
V_77 -> V_59 . V_89 = V_21 ;
V_21 -> V_90 = & V_85 -> V_59 ;
V_21 -> V_53 = F_47 ( V_78 ) ;
if ( V_21 -> V_53 > V_91 )
V_21 -> V_53 = V_91 ;
V_21 -> V_22 = F_13 ( V_21 -> V_53 * sizeof( struct V_20 ) ,
V_31 ) ;
if ( ! V_21 -> V_22 ) {
V_10 = - V_32 ;
goto V_46;
}
V_65 = - 1 ;
F_48 (np, child) {
V_65 ++ ;
V_64 = & V_21 -> V_22 [ V_65 ] ;
V_64 -> V_6 = & V_84 -> V_59 ;
V_8 = F_39 ( V_80 , L_10 , NULL ) ;
if ( ! V_8 )
continue;
V_64 -> V_8 = F_40 ( V_8 ) ;
if ( V_64 -> V_8 > V_92 )
continue;
F_48 (child, port) {
V_87 = F_39 ( V_83 , L_10 , NULL ) ;
if ( ! V_87 )
continue;
V_75 = F_40 ( V_87 ) ;
V_86 = F_39 ( V_83 , L_13 , NULL ) ;
if ( ! V_86 )
continue;
V_64 -> V_35 [ V_75 ] = F_49 ( V_86 ,
V_31 ) ;
if ( ! V_64 -> V_35 [ V_75 ] ) {
V_10 = - V_32 ;
goto V_93;
}
V_67 = F_44 ( V_83 , L_14 , 0 ) ;
if ( ! strcmp ( V_86 , L_5 ) && V_67 &&
V_21 -> V_53 > 1 ) {
V_10 = F_37 ( V_21 , V_64 ,
V_65 , V_67 ) ;
if ( V_10 )
goto V_93;
}
if ( V_75 == V_34 )
break;
}
}
return 0 ;
V_93:
F_42 ( V_21 ) ;
V_46:
F_19 ( V_21 ) ;
V_77 -> V_59 . V_89 = NULL ;
return V_10 ;
}
static void F_50 ( struct V_76 * V_77 )
{
struct V_63 * V_21 = V_77 -> V_59 . V_89 ;
if ( ! V_77 -> V_59 . V_79 )
return;
F_42 ( V_21 ) ;
F_19 ( V_21 ) ;
}
static inline int F_43 ( struct V_76 * V_77 )
{
return 0 ;
}
static inline void F_50 ( struct V_76 * V_77 )
{
}
static int F_51 ( struct V_76 * V_77 )
{
static int V_94 ;
struct V_63 * V_21 = V_77 -> V_59 . V_89 ;
struct V_47 * V_59 ;
struct V_15 * V_16 ;
int V_24 , V_10 ;
if ( ! V_94 ++ )
F_11 ( V_95 L_15
L_16 , V_96 ) ;
if ( V_77 -> V_59 . V_79 ) {
V_10 = F_43 ( V_77 ) ;
if ( V_10 )
return V_10 ;
V_21 = V_77 -> V_59 . V_89 ;
}
if ( V_21 == NULL || V_21 -> V_90 == NULL )
return - V_28 ;
V_59 = F_34 ( V_21 -> V_90 ) ;
if ( V_59 == NULL ) {
V_10 = - V_28 ;
goto V_37;
}
if ( V_59 -> V_97 != NULL ) {
F_52 ( V_59 ) ;
V_10 = - V_98 ;
goto V_37;
}
V_16 = F_13 ( sizeof( * V_16 ) , V_31 ) ;
if ( V_16 == NULL ) {
F_52 ( V_59 ) ;
V_10 = - V_32 ;
goto V_37;
}
F_53 ( V_77 , V_16 ) ;
V_16 -> V_21 = V_21 ;
V_16 -> V_27 = V_59 ;
V_16 -> V_36 = - 1 ;
V_16 -> V_38 = - 1 ;
for ( V_24 = 0 ; V_24 < V_21 -> V_53 ; V_24 ++ ) {
struct V_6 * V_7 ;
struct V_14 * V_23 ;
V_7 = F_31 ( V_21 -> V_22 [ V_24 ] . V_6 ) ;
if ( V_7 == NULL ) {
F_11 ( V_26 L_17
L_18 , V_59 -> V_12 , V_24 ) ;
continue;
}
V_23 = F_10 ( V_16 , V_24 , & V_77 -> V_59 , V_7 ) ;
if ( F_54 ( V_23 ) ) {
F_11 ( V_26 L_19
L_20 , V_59 -> V_12 , V_24 ,
F_55 ( V_23 ) ) ;
continue;
}
V_16 -> V_23 [ V_24 ] = V_23 ;
if ( V_23 -> V_2 -> V_54 != NULL )
V_16 -> V_99 = 1 ;
}
F_56 () ;
V_59 -> V_97 = ( void * ) V_16 ;
if ( V_16 -> V_99 ) {
F_57 ( & V_16 -> V_52 , F_21 ) ;
F_58 ( & V_16 -> V_55 ) ;
V_16 -> V_55 . V_100 = ( unsigned long ) V_16 ;
V_16 -> V_55 . V_101 = F_25 ;
V_16 -> V_55 . V_102 = F_24 ( V_56 + V_57 ) ;
F_59 ( & V_16 -> V_55 ) ;
}
return 0 ;
V_37:
F_50 ( V_77 ) ;
return V_10 ;
}
static int F_60 ( struct V_76 * V_77 )
{
struct V_15 * V_16 = F_61 ( V_77 ) ;
int V_24 ;
if ( V_16 -> V_99 )
F_62 ( & V_16 -> V_55 ) ;
F_63 ( & V_16 -> V_52 ) ;
for ( V_24 = 0 ; V_24 < V_16 -> V_21 -> V_53 ; V_24 ++ ) {
struct V_14 * V_23 = V_16 -> V_23 [ V_24 ] ;
if ( V_23 != NULL )
F_20 ( V_23 ) ;
}
F_50 ( V_77 ) ;
return 0 ;
}
static void F_64 ( struct V_76 * V_77 )
{
}
static int T_2 F_65 ( void )
{
int V_103 ;
V_103 = F_66 ( & V_104 ) ;
if ( V_103 )
return V_103 ;
#ifdef F_67
F_68 ( & V_105 ) ;
#endif
#ifdef F_69
F_68 ( & V_106 ) ;
#endif
#ifdef F_70
F_68 ( & V_107 ) ;
#endif
return 0 ;
}
static void T_3 F_71 ( void )
{
#ifdef F_70
F_72 ( & V_107 ) ;
#endif
#ifdef F_69
F_72 ( & V_106 ) ;
#endif
#ifdef F_67
F_72 ( & V_105 ) ;
#endif
F_73 ( & V_104 ) ;
}
