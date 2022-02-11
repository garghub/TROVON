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
static const struct V_6 *
F_7 ( struct V_7 * V_8 , struct V_7 * V_9 , int V_10 ,
const char * * V_11 , void * * V_12 )
{
const struct V_6 * V_13 ;
struct V_14 * V_4 ;
const char * V_15 ;
V_13 = NULL ;
V_15 = NULL ;
F_2 ( & V_3 ) ;
F_8 (list, &dsa_switch_drivers) {
const struct V_6 * V_16 ;
struct V_1 * V_2 ;
V_2 = F_9 ( V_4 , struct V_1 , V_4 ) ;
V_16 = V_2 -> V_16 ;
V_15 = V_16 -> V_17 ( V_8 , V_9 , V_10 , V_12 ) ;
if ( V_15 != NULL ) {
V_13 = V_16 ;
break;
}
}
F_4 ( & V_3 ) ;
* V_11 = V_15 ;
return V_13 ;
}
static int F_10 ( struct V_18 * V_19 , struct V_7 * V_20 )
{
struct V_21 * V_22 ;
int V_13 , V_23 ;
for ( V_23 = 0 ; V_23 < V_19 -> V_24 ; V_23 ++ ) {
if ( ! ( F_11 ( V_19 , V_23 ) || F_12 ( V_19 , V_23 ) ) )
continue;
V_22 = & V_19 -> V_25 [ V_23 ] ;
V_13 = F_13 ( V_19 , V_20 , V_22 , V_23 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
static int F_14 ( struct V_18 * V_19 , struct V_7 * V_8 )
{
const struct V_6 * V_16 = V_19 -> V_16 ;
struct V_26 * V_27 = V_19 -> V_27 ;
struct V_28 * V_29 = V_19 -> V_29 ;
bool V_30 = false ;
int V_31 = V_19 -> V_31 ;
int V_32 , V_13 ;
for ( V_32 = 0 ; V_32 < V_19 -> V_24 ; V_32 ++ ) {
char * V_15 ;
V_15 = V_29 -> V_33 [ V_32 ] ;
if ( V_15 == NULL )
continue;
if ( ! strcmp ( V_15 , L_1 ) ) {
if ( V_27 -> V_34 ) {
F_15 ( V_27 -> V_35 ,
L_2 ) ;
return - V_36 ;
}
V_27 -> V_34 = V_19 ;
V_27 -> V_37 = V_32 ;
V_19 -> V_38 |= 1 << V_32 ;
} else if ( ! strcmp ( V_15 , L_3 ) ) {
V_19 -> V_39 |= 1 << V_32 ;
} else {
V_19 -> V_40 |= 1 << V_32 ;
}
V_30 = true ;
}
if ( ! V_30 && V_32 == V_19 -> V_24 )
return - V_36 ;
V_19 -> V_41 = V_19 -> V_40 ;
if ( V_27 -> V_34 == V_19 ) {
enum V_42 V_43 ;
V_43 = V_16 -> V_44 ( V_19 ) ;
V_27 -> V_45 = F_16 ( V_43 ) ;
if ( F_17 ( V_27 -> V_45 ) )
return F_18 ( V_27 -> V_45 ) ;
V_27 -> V_46 = V_27 -> V_45 -> V_46 ;
}
memcpy ( V_19 -> V_47 , V_29 -> V_47 , sizeof( V_19 -> V_47 ) ) ;
V_13 = V_16 -> V_48 ( V_19 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_19 ( V_19 ) ;
if ( V_13 )
return V_13 ;
if ( V_16 -> V_49 ) {
V_13 = V_16 -> V_49 ( V_19 , V_27 -> V_35 -> V_50 ) ;
if ( V_13 < 0 )
return V_13 ;
}
if ( ! V_19 -> V_51 && V_16 -> V_52 ) {
V_19 -> V_51 = F_20 ( V_8 ) ;
if ( ! V_19 -> V_51 )
return - V_53 ;
F_21 ( V_19 ) ;
V_13 = F_22 ( V_19 -> V_51 ) ;
if ( V_13 < 0 )
return V_13 ;
}
for ( V_32 = 0 ; V_32 < V_19 -> V_24 ; V_32 ++ ) {
V_19 -> V_25 [ V_32 ] . V_54 = V_29 -> V_55 [ V_32 ] ;
if ( ! ( V_19 -> V_40 & ( 1 << V_32 ) ) )
continue;
V_13 = F_23 ( V_19 , V_8 , V_32 , V_29 -> V_33 [ V_32 ] ) ;
if ( V_13 < 0 )
F_15 ( V_27 -> V_35 , L_4 ,
V_31 , V_32 , V_29 -> V_33 [ V_32 ] , V_13 ) ;
}
V_13 = F_10 ( V_19 , V_8 ) ;
if ( V_13 < 0 )
F_15 ( V_27 -> V_35 , L_5 ,
V_31 ) ;
V_13 = F_24 ( V_19 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static struct V_18 *
F_25 ( struct V_26 * V_27 , int V_31 ,
struct V_7 * V_8 , struct V_7 * V_9 )
{
struct V_28 * V_29 = V_27 -> V_56 -> V_57 + V_31 ;
const struct V_6 * V_16 ;
struct V_18 * V_19 ;
int V_13 ;
const char * V_15 ;
void * V_12 ;
V_16 = F_7 ( V_8 , V_9 , V_29 -> V_10 , & V_15 , & V_12 ) ;
if ( ! V_16 ) {
F_15 ( V_27 -> V_35 , L_6 ,
V_31 ) ;
return F_26 ( - V_36 ) ;
}
F_27 ( V_27 -> V_35 , L_7 ,
V_31 , V_15 ) ;
V_19 = F_28 ( V_8 , V_58 ) ;
if ( ! V_19 )
return F_26 ( - V_53 ) ;
V_19 -> V_27 = V_27 ;
V_19 -> V_31 = V_31 ;
V_19 -> V_29 = V_29 ;
V_19 -> V_16 = V_16 ;
V_19 -> V_12 = V_12 ;
V_13 = F_14 ( V_19 , V_8 ) ;
if ( V_13 )
return F_26 ( V_13 ) ;
return V_19 ;
}
static void F_29 ( struct V_18 * V_19 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_19 -> V_24 ; V_23 ++ ) {
if ( ! ( V_19 -> V_40 & ( 1 << V_23 ) ) )
continue;
if ( ! V_19 -> V_25 [ V_23 ] . V_59 )
continue;
F_30 ( V_19 -> V_25 [ V_23 ] . V_59 ) ;
}
for ( V_23 = 0 ; V_23 < V_19 -> V_24 ; V_23 ++ ) {
if ( ! ( F_11 ( V_19 , V_23 ) || F_12 ( V_19 , V_23 ) ) )
continue;
F_31 ( & V_19 -> V_25 [ V_23 ] ) ;
V_19 -> V_38 |= ~ ( 1 << V_23 ) ;
V_19 -> V_39 |= ~ ( 1 << V_23 ) ;
}
if ( V_19 -> V_51 && V_19 -> V_16 -> V_52 )
F_32 ( V_19 -> V_51 ) ;
F_33 ( V_19 ) ;
}
static int F_34 ( struct V_7 * V_20 , void * V_60 )
{
if ( V_20 -> V_60 != NULL && ! strcmp ( V_20 -> V_60 -> V_15 , V_60 ) )
return 1 ;
return 0 ;
}
static struct V_7 * F_35 ( struct V_7 * V_8 , char * V_60 )
{
if ( F_34 ( V_8 , V_60 ) ) {
F_36 ( V_8 ) ;
return V_8 ;
}
return F_37 ( V_8 , V_60 , F_34 ) ;
}
struct V_61 * F_38 ( struct V_7 * V_20 )
{
struct V_7 * V_62 ;
V_62 = F_35 ( V_20 , L_8 ) ;
if ( V_62 != NULL ) {
struct V_61 * V_63 ;
V_63 = F_39 ( V_62 ) ;
F_40 ( V_62 ) ;
return V_63 ;
}
return NULL ;
}
static int F_41 ( struct V_64 * V_56 ,
struct V_28 * V_29 ,
int V_65 , int V_66 ,
struct V_67 * V_68 )
{
const T_1 * V_69 ;
int V_70 ;
struct V_67 * V_71 ;
int V_72 ;
V_71 = F_42 ( V_68 ) ;
if ( ! V_71 )
return - V_36 ;
V_69 = F_43 ( V_71 , L_9 , & V_72 ) ;
if ( ! V_69 || ( V_72 != sizeof( * V_69 ) * 2 ) )
return - V_36 ;
V_70 = F_44 ( V_69 + 1 ) ;
if ( V_70 >= V_56 -> V_73 )
return - V_36 ;
V_29 -> V_47 [ V_70 ] = V_66 ;
return 0 ;
}
static int F_45 ( struct V_64 * V_56 ,
struct V_28 * V_29 ,
int V_65 , int V_66 ,
struct V_67 * V_23 ,
const char * V_74 )
{
struct V_67 * V_68 ;
int V_75 ;
int V_13 ;
for ( V_75 = 0 ; ; V_75 ++ ) {
V_68 = F_46 ( V_23 , L_10 , V_75 ) ;
if ( ! V_68 )
break;
if ( ! strcmp ( V_74 , L_3 ) && V_56 -> V_73 > 1 ) {
V_13 = F_41 ( V_56 , V_29 , V_65 ,
V_66 , V_68 ) ;
if ( V_13 )
return V_13 ;
}
}
return 0 ;
}
static void F_47 ( struct V_64 * V_56 )
{
int V_32 ;
int V_66 ;
for ( V_32 = 0 ; V_32 < V_56 -> V_73 ; V_32 ++ ) {
V_66 = 0 ;
while ( V_66 < V_58 ) {
F_48 ( V_56 -> V_57 [ V_32 ] . V_33 [ V_66 ] ) ;
V_66 ++ ;
}
if ( V_56 -> V_57 [ V_32 ] . V_9 )
F_40 ( V_56 -> V_57 [ V_32 ] . V_9 ) ;
}
F_48 ( V_56 -> V_57 ) ;
}
static int F_49 ( struct V_7 * V_20 )
{
struct V_67 * V_76 = V_20 -> V_77 ;
struct V_67 * V_78 , * V_79 , * V_80 , * V_23 ;
struct V_61 * V_81 , * V_82 ;
struct V_83 * V_84 ;
struct V_64 * V_56 ;
struct V_28 * V_29 ;
const char * V_74 ;
int V_65 , V_66 ;
const unsigned int * V_10 , * V_85 ;
T_2 V_86 ;
int V_13 ;
V_79 = F_46 ( V_76 , L_11 , 0 ) ;
if ( ! V_79 )
return - V_36 ;
V_81 = F_50 ( V_79 ) ;
if ( ! V_81 )
return - V_87 ;
V_80 = F_46 ( V_76 , L_12 , 0 ) ;
if ( ! V_80 ) {
V_13 = - V_36 ;
goto V_88;
}
V_84 = F_51 ( V_80 ) ;
if ( ! V_84 ) {
V_13 = - V_87 ;
goto V_88;
}
V_56 = F_52 ( sizeof( * V_56 ) , V_89 ) ;
if ( ! V_56 ) {
V_13 = - V_53 ;
goto V_90;
}
V_20 -> V_91 = V_56 ;
V_56 -> V_92 = V_84 ;
V_56 -> V_73 = F_53 ( V_76 ) ;
if ( V_56 -> V_73 > V_93 )
V_56 -> V_73 = V_93 ;
V_56 -> V_57 = F_54 ( V_56 -> V_73 , sizeof( struct V_28 ) ,
V_89 ) ;
if ( ! V_56 -> V_57 ) {
V_13 = - V_53 ;
goto V_94;
}
V_65 = - 1 ;
F_55 (np, child) {
int V_32 ;
V_65 ++ ;
V_29 = & V_56 -> V_57 [ V_65 ] ;
V_29 -> V_77 = V_78 ;
for ( V_32 = 0 ; V_32 < V_93 ; ++ V_32 )
V_29 -> V_47 [ V_32 ] = V_95 ;
V_29 -> V_9 = F_36 ( & V_81 -> V_20 ) ;
V_10 = F_43 ( V_78 , L_9 , NULL ) ;
if ( ! V_10 )
continue;
V_29 -> V_10 = F_44 ( V_10 ) ;
if ( V_29 -> V_10 >= V_96 )
continue;
if ( ! F_56 ( V_78 , L_13 , & V_86 ) )
V_29 -> V_86 = V_86 ;
V_79 = F_46 ( V_78 , L_14 , 0 ) ;
if ( V_79 ) {
V_82 = F_50 ( V_79 ) ;
if ( ! V_82 ) {
V_13 = - V_87 ;
goto V_97;
}
F_40 ( V_29 -> V_9 ) ;
V_29 -> V_9 = & V_82 -> V_20 ;
}
F_55 (child, port) {
V_85 = F_43 ( V_23 , L_9 , NULL ) ;
if ( ! V_85 )
continue;
V_66 = F_44 ( V_85 ) ;
if ( V_66 >= V_58 )
break;
V_74 = F_43 ( V_23 , L_15 , NULL ) ;
if ( ! V_74 )
continue;
V_29 -> V_55 [ V_66 ] = V_23 ;
V_29 -> V_33 [ V_66 ] = F_57 ( V_74 ,
V_89 ) ;
if ( ! V_29 -> V_33 [ V_66 ] ) {
V_13 = - V_53 ;
goto V_97;
}
V_13 = F_45 ( V_56 , V_29 , V_65 ,
V_66 , V_23 , V_74 ) ;
if ( V_13 )
goto V_97;
}
}
F_40 ( & V_81 -> V_20 ) ;
return 0 ;
V_97:
F_47 ( V_56 ) ;
V_94:
F_48 ( V_56 ) ;
V_20 -> V_91 = NULL ;
V_90:
F_40 ( & V_84 -> V_20 ) ;
V_88:
F_40 ( & V_81 -> V_20 ) ;
return V_13 ;
}
static void F_58 ( struct V_7 * V_20 )
{
struct V_64 * V_56 = V_20 -> V_91 ;
if ( ! V_20 -> V_77 )
return;
F_47 ( V_56 ) ;
F_40 ( & V_56 -> V_92 -> V_20 ) ;
F_48 ( V_56 ) ;
}
static inline int F_49 ( struct V_7 * V_20 )
{
return 0 ;
}
static inline void F_58 ( struct V_7 * V_20 )
{
}
static int F_59 ( struct V_26 * V_27 , struct V_83 * V_20 ,
struct V_7 * V_8 , struct V_64 * V_56 )
{
int V_32 ;
unsigned V_98 = 0 ;
V_27 -> V_56 = V_56 ;
V_27 -> V_35 = V_20 ;
V_27 -> V_37 = - 1 ;
for ( V_32 = 0 ; V_32 < V_56 -> V_73 ; V_32 ++ ) {
struct V_18 * V_19 ;
V_19 = F_25 ( V_27 , V_32 , V_8 , V_56 -> V_57 [ V_32 ] . V_9 ) ;
if ( F_17 ( V_19 ) ) {
F_15 ( V_20 , L_16 ,
V_32 , F_18 ( V_19 ) ) ;
continue;
}
V_27 -> V_19 [ V_32 ] = V_19 ;
++ V_98 ;
}
if ( ! V_98 )
return - V_87 ;
F_60 () ;
V_20 -> V_99 = ( void * ) V_27 ;
return 0 ;
}
static int F_61 ( struct V_100 * V_101 )
{
struct V_64 * V_56 = V_101 -> V_20 . V_91 ;
struct V_83 * V_20 ;
struct V_26 * V_27 ;
int V_13 ;
if ( V_101 -> V_20 . V_77 ) {
V_13 = F_49 ( & V_101 -> V_20 ) ;
if ( V_13 )
return V_13 ;
V_56 = V_101 -> V_20 . V_91 ;
}
if ( V_56 == NULL || ( V_56 -> V_59 == NULL && V_56 -> V_92 == NULL ) )
return - V_36 ;
if ( V_56 -> V_92 ) {
V_20 = V_56 -> V_92 ;
F_62 ( V_20 ) ;
} else {
V_20 = F_63 ( V_56 -> V_59 ) ;
}
if ( V_20 == NULL ) {
V_13 = - V_87 ;
goto V_102;
}
if ( V_20 -> V_99 != NULL ) {
F_64 ( V_20 ) ;
V_13 = - V_103 ;
goto V_102;
}
V_27 = F_65 ( & V_101 -> V_20 , sizeof( * V_27 ) , V_89 ) ;
if ( V_27 == NULL ) {
F_64 ( V_20 ) ;
V_13 = - V_53 ;
goto V_102;
}
F_66 ( V_101 , V_27 ) ;
V_13 = F_59 ( V_27 , V_20 , & V_101 -> V_20 , V_56 ) ;
if ( V_13 ) {
F_64 ( V_20 ) ;
goto V_102;
}
return 0 ;
V_102:
F_58 ( & V_101 -> V_20 ) ;
return V_13 ;
}
static void F_67 ( struct V_26 * V_27 )
{
int V_32 ;
V_27 -> V_35 -> V_99 = NULL ;
F_60 () ;
for ( V_32 = 0 ; V_32 < V_27 -> V_56 -> V_73 ; V_32 ++ ) {
struct V_18 * V_19 = V_27 -> V_19 [ V_32 ] ;
if ( V_19 )
F_29 ( V_19 ) ;
}
F_68 ( V_27 -> V_34 ) ;
F_64 ( V_27 -> V_35 ) ;
}
static int F_69 ( struct V_100 * V_101 )
{
struct V_26 * V_27 = F_70 ( V_101 ) ;
F_67 ( V_27 ) ;
F_58 ( & V_101 -> V_20 ) ;
return 0 ;
}
static void F_71 ( struct V_100 * V_101 )
{
}
static int F_72 ( struct V_7 * V_62 )
{
struct V_100 * V_101 = F_73 ( V_62 ) ;
struct V_26 * V_27 = F_70 ( V_101 ) ;
int V_32 , V_13 = 0 ;
for ( V_32 = 0 ; V_32 < V_27 -> V_56 -> V_73 ; V_32 ++ ) {
struct V_18 * V_19 = V_27 -> V_19 [ V_32 ] ;
if ( V_19 != NULL )
V_13 = F_74 ( V_19 ) ;
}
return V_13 ;
}
static int F_75 ( struct V_7 * V_62 )
{
struct V_100 * V_101 = F_73 ( V_62 ) ;
struct V_26 * V_27 = F_70 ( V_101 ) ;
int V_32 , V_13 = 0 ;
for ( V_32 = 0 ; V_32 < V_27 -> V_56 -> V_73 ; V_32 ++ ) {
struct V_18 * V_19 = V_27 -> V_19 [ V_32 ] ;
if ( V_19 != NULL )
V_13 = F_76 ( V_19 ) ;
}
return V_13 ;
}
int F_77 ( void )
{
return F_78 ( & V_104 ) ;
}
void F_79 ( void )
{
F_80 ( & V_104 ) ;
}
