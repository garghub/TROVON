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
static int F_10 ( struct V_18 * V_19 )
{
int V_13 , V_20 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_21 ; V_20 ++ ) {
if ( ! ( F_11 ( V_19 , V_20 ) || F_12 ( V_19 , V_20 ) ) )
continue;
V_13 = F_13 ( & V_19 -> V_22 [ V_20 ] ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
static int F_14 ( struct V_18 * V_19 ,
struct V_23 * V_24 )
{
const struct V_6 * V_16 = V_19 -> V_16 ;
struct V_25 * V_26 = V_19 -> V_26 ;
struct V_27 * V_28 = V_19 -> V_28 ;
bool V_29 = false ;
int V_30 = V_19 -> V_30 ;
int V_31 , V_13 ;
for ( V_31 = 0 ; V_31 < V_19 -> V_21 ; V_31 ++ ) {
char * V_15 ;
V_15 = V_28 -> V_32 [ V_31 ] ;
if ( V_15 == NULL )
continue;
if ( ! strcmp ( V_15 , L_1 ) ) {
if ( V_26 -> V_33 ) {
F_15 ( V_24 ,
L_2 ) ;
return - V_34 ;
}
V_26 -> V_33 = & V_19 -> V_22 [ V_31 ] ;
V_26 -> V_33 -> V_35 = V_24 ;
V_19 -> V_36 |= 1 << V_31 ;
} else if ( ! strcmp ( V_15 , L_3 ) ) {
V_19 -> V_37 |= 1 << V_31 ;
} else {
V_19 -> V_38 |= 1 << V_31 ;
}
V_29 = true ;
}
if ( ! V_29 && V_31 == V_19 -> V_21 )
return - V_34 ;
V_19 -> V_39 = V_19 -> V_38 ;
if ( V_26 -> V_33 -> V_19 == V_19 ) {
enum V_40 V_41 ;
V_41 = V_16 -> V_42 ( V_19 ) ;
V_26 -> V_43 = F_16 ( V_41 ) ;
if ( F_17 ( V_26 -> V_43 ) )
return F_18 ( V_26 -> V_43 ) ;
V_26 -> V_44 = V_26 -> V_43 -> V_44 ;
}
memcpy ( V_19 -> V_45 , V_28 -> V_45 , sizeof( V_19 -> V_45 ) ) ;
V_13 = V_16 -> V_46 ( V_19 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_19 ( V_19 ) ;
if ( V_13 )
return V_13 ;
if ( V_16 -> V_47 ) {
V_13 = V_16 -> V_47 ( V_19 , V_24 -> V_48 ) ;
if ( V_13 < 0 )
return V_13 ;
}
if ( ! V_19 -> V_49 && V_16 -> V_50 ) {
V_19 -> V_49 = F_20 ( V_19 -> V_51 ) ;
if ( ! V_19 -> V_49 )
return - V_52 ;
F_21 ( V_19 ) ;
V_13 = F_22 ( V_19 -> V_49 ) ;
if ( V_13 < 0 )
return V_13 ;
}
for ( V_31 = 0 ; V_31 < V_19 -> V_21 ; V_31 ++ ) {
V_19 -> V_22 [ V_31 ] . V_53 = V_28 -> V_54 [ V_31 ] ;
V_19 -> V_22 [ V_31 ] . V_33 = V_26 -> V_33 ;
if ( ! ( V_19 -> V_38 & ( 1 << V_31 ) ) )
continue;
V_13 = F_23 ( & V_19 -> V_22 [ V_31 ] , V_28 -> V_32 [ V_31 ] ) ;
if ( V_13 < 0 )
F_15 ( V_24 , L_4 ,
V_30 , V_31 , V_28 -> V_32 [ V_31 ] , V_13 ) ;
}
V_13 = F_10 ( V_19 ) ;
if ( V_13 < 0 )
F_15 ( V_24 , L_5 ,
V_30 ) ;
V_13 = F_24 ( V_19 -> V_26 -> V_33 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static struct V_18 *
F_25 ( struct V_25 * V_26 , struct V_23 * V_24 ,
int V_30 , struct V_7 * V_8 , struct V_7 * V_9 )
{
struct V_27 * V_28 = V_26 -> V_55 -> V_56 + V_30 ;
const struct V_6 * V_16 ;
struct V_18 * V_19 ;
int V_13 ;
const char * V_15 ;
void * V_12 ;
V_16 = F_7 ( V_8 , V_9 , V_28 -> V_10 , & V_15 , & V_12 ) ;
if ( ! V_16 ) {
F_15 ( V_24 , L_6 ,
V_30 ) ;
return F_26 ( - V_34 ) ;
}
F_27 ( V_24 , L_7 ,
V_30 , V_15 ) ;
V_19 = F_28 ( V_8 , V_57 ) ;
if ( ! V_19 )
return F_26 ( - V_52 ) ;
V_19 -> V_26 = V_26 ;
V_19 -> V_30 = V_30 ;
V_19 -> V_28 = V_28 ;
V_19 -> V_16 = V_16 ;
V_19 -> V_12 = V_12 ;
V_13 = F_14 ( V_19 , V_24 ) ;
if ( V_13 )
return F_26 ( V_13 ) ;
return V_19 ;
}
static void F_29 ( struct V_18 * V_19 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_21 ; V_20 ++ ) {
if ( ! ( V_19 -> V_38 & ( 1 << V_20 ) ) )
continue;
if ( ! V_19 -> V_22 [ V_20 ] . V_35 )
continue;
F_30 ( V_19 -> V_22 [ V_20 ] . V_35 ) ;
}
for ( V_20 = 0 ; V_20 < V_19 -> V_21 ; V_20 ++ ) {
if ( ! ( F_11 ( V_19 , V_20 ) || F_12 ( V_19 , V_20 ) ) )
continue;
F_31 ( & V_19 -> V_22 [ V_20 ] ) ;
V_19 -> V_36 |= ~ ( 1 << V_20 ) ;
V_19 -> V_37 |= ~ ( 1 << V_20 ) ;
}
if ( V_19 -> V_49 && V_19 -> V_16 -> V_50 )
F_32 ( V_19 -> V_49 ) ;
F_33 ( V_19 ) ;
}
static int F_34 ( struct V_7 * V_51 , void * V_58 )
{
if ( V_51 -> V_58 != NULL && ! strcmp ( V_51 -> V_58 -> V_15 , V_58 ) )
return 1 ;
return 0 ;
}
static struct V_7 * F_35 ( struct V_7 * V_8 , char * V_58 )
{
if ( F_34 ( V_8 , V_58 ) ) {
F_36 ( V_8 ) ;
return V_8 ;
}
return F_37 ( V_8 , V_58 , F_34 ) ;
}
struct V_59 * F_38 ( struct V_7 * V_51 )
{
struct V_7 * V_60 ;
V_60 = F_35 ( V_51 , L_8 ) ;
if ( V_60 != NULL ) {
struct V_59 * V_61 ;
V_61 = F_39 ( V_60 ) ;
F_40 ( V_60 ) ;
return V_61 ;
}
return NULL ;
}
static int F_41 ( struct V_62 * V_55 ,
struct V_27 * V_28 ,
int V_63 , int V_64 ,
struct V_65 * V_66 )
{
const T_1 * V_67 ;
int V_68 ;
struct V_65 * V_69 ;
int V_70 ;
V_69 = F_42 ( V_66 ) ;
if ( ! V_69 )
return - V_34 ;
V_67 = F_43 ( V_69 , L_9 , & V_70 ) ;
if ( ! V_67 || ( V_70 != sizeof( * V_67 ) * 2 ) )
return - V_34 ;
V_68 = F_44 ( V_67 + 1 ) ;
if ( V_68 >= V_55 -> V_71 )
return - V_34 ;
V_28 -> V_45 [ V_68 ] = V_64 ;
return 0 ;
}
static int F_45 ( struct V_62 * V_55 ,
struct V_27 * V_28 ,
int V_63 , int V_64 ,
struct V_65 * V_20 ,
const char * V_72 )
{
struct V_65 * V_66 ;
int V_73 ;
int V_13 ;
for ( V_73 = 0 ; ; V_73 ++ ) {
V_66 = F_46 ( V_20 , L_10 , V_73 ) ;
if ( ! V_66 )
break;
if ( ! strcmp ( V_72 , L_3 ) && V_55 -> V_71 > 1 ) {
V_13 = F_41 ( V_55 , V_28 , V_63 ,
V_64 , V_66 ) ;
if ( V_13 )
return V_13 ;
}
}
return 0 ;
}
static void F_47 ( struct V_62 * V_55 )
{
int V_31 ;
int V_64 ;
for ( V_31 = 0 ; V_31 < V_55 -> V_71 ; V_31 ++ ) {
V_64 = 0 ;
while ( V_64 < V_57 ) {
F_48 ( V_55 -> V_56 [ V_31 ] . V_32 [ V_64 ] ) ;
V_64 ++ ;
}
if ( V_55 -> V_56 [ V_31 ] . V_9 )
F_40 ( V_55 -> V_56 [ V_31 ] . V_9 ) ;
}
F_48 ( V_55 -> V_56 ) ;
}
static int F_49 ( struct V_7 * V_51 )
{
struct V_65 * V_74 = V_51 -> V_75 ;
struct V_65 * V_76 , * V_77 , * V_78 , * V_20 ;
struct V_59 * V_79 , * V_80 ;
struct V_23 * V_81 ;
struct V_62 * V_55 ;
struct V_27 * V_28 ;
const char * V_72 ;
int V_63 , V_64 ;
const unsigned int * V_10 , * V_82 ;
T_2 V_83 ;
int V_13 ;
V_77 = F_46 ( V_74 , L_11 , 0 ) ;
if ( ! V_77 )
return - V_34 ;
V_79 = F_50 ( V_77 ) ;
if ( ! V_79 )
return - V_84 ;
V_78 = F_46 ( V_74 , L_12 , 0 ) ;
if ( ! V_78 ) {
V_13 = - V_34 ;
goto V_85;
}
V_81 = F_51 ( V_78 ) ;
if ( ! V_81 ) {
V_13 = - V_84 ;
goto V_85;
}
V_55 = F_52 ( sizeof( * V_55 ) , V_86 ) ;
if ( ! V_55 ) {
V_13 = - V_52 ;
goto V_87;
}
V_51 -> V_88 = V_55 ;
V_55 -> V_89 = V_81 ;
V_55 -> V_71 = F_53 ( V_74 ) ;
if ( V_55 -> V_71 > V_90 )
V_55 -> V_71 = V_90 ;
V_55 -> V_56 = F_54 ( V_55 -> V_71 , sizeof( struct V_27 ) ,
V_86 ) ;
if ( ! V_55 -> V_56 ) {
V_13 = - V_52 ;
goto V_91;
}
V_63 = - 1 ;
F_55 (np, child) {
int V_31 ;
V_63 ++ ;
V_28 = & V_55 -> V_56 [ V_63 ] ;
V_28 -> V_75 = V_76 ;
for ( V_31 = 0 ; V_31 < V_90 ; ++ V_31 )
V_28 -> V_45 [ V_31 ] = V_92 ;
V_28 -> V_9 = F_36 ( & V_79 -> V_51 ) ;
V_10 = F_43 ( V_76 , L_9 , NULL ) ;
if ( ! V_10 )
continue;
V_28 -> V_10 = F_44 ( V_10 ) ;
if ( V_28 -> V_10 >= V_93 )
continue;
if ( ! F_56 ( V_76 , L_13 , & V_83 ) )
V_28 -> V_83 = V_83 ;
V_77 = F_46 ( V_76 , L_14 , 0 ) ;
if ( V_77 ) {
V_80 = F_50 ( V_77 ) ;
if ( ! V_80 ) {
V_13 = - V_84 ;
goto V_94;
}
F_40 ( V_28 -> V_9 ) ;
V_28 -> V_9 = & V_80 -> V_51 ;
}
F_55 (child, port) {
V_82 = F_43 ( V_20 , L_9 , NULL ) ;
if ( ! V_82 )
continue;
V_64 = F_44 ( V_82 ) ;
if ( V_64 >= V_57 )
break;
V_72 = F_43 ( V_20 , L_15 , NULL ) ;
if ( ! V_72 )
continue;
V_28 -> V_54 [ V_64 ] = V_20 ;
V_28 -> V_32 [ V_64 ] = F_57 ( V_72 ,
V_86 ) ;
if ( ! V_28 -> V_32 [ V_64 ] ) {
V_13 = - V_52 ;
goto V_94;
}
V_13 = F_45 ( V_55 , V_28 , V_63 ,
V_64 , V_20 , V_72 ) ;
if ( V_13 )
goto V_94;
}
}
F_40 ( & V_79 -> V_51 ) ;
return 0 ;
V_94:
F_47 ( V_55 ) ;
V_91:
F_48 ( V_55 ) ;
V_51 -> V_88 = NULL ;
V_87:
F_40 ( & V_81 -> V_51 ) ;
V_85:
F_40 ( & V_79 -> V_51 ) ;
return V_13 ;
}
static void F_58 ( struct V_7 * V_51 )
{
struct V_62 * V_55 = V_51 -> V_88 ;
if ( ! V_51 -> V_75 )
return;
F_47 ( V_55 ) ;
F_40 ( & V_55 -> V_89 -> V_51 ) ;
F_48 ( V_55 ) ;
}
static inline int F_49 ( struct V_7 * V_51 )
{
return 0 ;
}
static inline void F_58 ( struct V_7 * V_51 )
{
}
static int F_59 ( struct V_25 * V_26 , struct V_23 * V_51 ,
struct V_7 * V_8 , struct V_62 * V_55 )
{
int V_31 ;
unsigned V_95 = 0 ;
V_26 -> V_55 = V_55 ;
for ( V_31 = 0 ; V_31 < V_55 -> V_71 ; V_31 ++ ) {
struct V_18 * V_19 ;
V_19 = F_25 ( V_26 , V_51 , V_31 , V_8 , V_55 -> V_56 [ V_31 ] . V_9 ) ;
if ( F_17 ( V_19 ) ) {
F_15 ( V_51 , L_16 ,
V_31 , F_18 ( V_19 ) ) ;
continue;
}
V_26 -> V_19 [ V_31 ] = V_19 ;
++ V_95 ;
}
if ( ! V_95 )
return - V_84 ;
F_60 () ;
V_51 -> V_96 = V_26 ;
return 0 ;
}
static int F_61 ( struct V_97 * V_98 )
{
struct V_62 * V_55 = V_98 -> V_51 . V_88 ;
struct V_23 * V_51 ;
struct V_25 * V_26 ;
int V_13 ;
if ( V_98 -> V_51 . V_75 ) {
V_13 = F_49 ( & V_98 -> V_51 ) ;
if ( V_13 )
return V_13 ;
V_55 = V_98 -> V_51 . V_88 ;
}
if ( V_55 == NULL || ( V_55 -> V_35 == NULL && V_55 -> V_89 == NULL ) )
return - V_34 ;
if ( V_55 -> V_89 ) {
V_51 = V_55 -> V_89 ;
F_62 ( V_51 ) ;
} else {
V_51 = F_63 ( V_55 -> V_35 ) ;
}
if ( V_51 == NULL ) {
V_13 = - V_84 ;
goto V_99;
}
if ( V_51 -> V_96 != NULL ) {
F_64 ( V_51 ) ;
V_13 = - V_100 ;
goto V_99;
}
V_26 = F_65 ( & V_98 -> V_51 , sizeof( * V_26 ) , V_86 ) ;
if ( V_26 == NULL ) {
F_64 ( V_51 ) ;
V_13 = - V_52 ;
goto V_99;
}
F_66 ( V_98 , V_26 ) ;
V_13 = F_59 ( V_26 , V_51 , & V_98 -> V_51 , V_55 ) ;
if ( V_13 ) {
F_64 ( V_51 ) ;
goto V_99;
}
return 0 ;
V_99:
F_58 ( & V_98 -> V_51 ) ;
return V_13 ;
}
static void F_67 ( struct V_25 * V_26 )
{
int V_31 ;
V_26 -> V_33 -> V_35 -> V_96 = NULL ;
F_60 () ;
for ( V_31 = 0 ; V_31 < V_26 -> V_55 -> V_71 ; V_31 ++ ) {
struct V_18 * V_19 = V_26 -> V_19 [ V_31 ] ;
if ( V_19 )
F_29 ( V_19 ) ;
}
F_68 ( V_26 -> V_33 ) ;
F_64 ( V_26 -> V_33 -> V_35 ) ;
}
static int F_69 ( struct V_97 * V_98 )
{
struct V_25 * V_26 = F_70 ( V_98 ) ;
F_67 ( V_26 ) ;
F_58 ( & V_98 -> V_51 ) ;
return 0 ;
}
static void F_71 ( struct V_97 * V_98 )
{
}
static int F_72 ( struct V_7 * V_60 )
{
struct V_97 * V_98 = F_73 ( V_60 ) ;
struct V_25 * V_26 = F_70 ( V_98 ) ;
int V_31 , V_13 = 0 ;
for ( V_31 = 0 ; V_31 < V_26 -> V_55 -> V_71 ; V_31 ++ ) {
struct V_18 * V_19 = V_26 -> V_19 [ V_31 ] ;
if ( V_19 != NULL )
V_13 = F_74 ( V_19 ) ;
}
return V_13 ;
}
static int F_75 ( struct V_7 * V_60 )
{
struct V_97 * V_98 = F_73 ( V_60 ) ;
struct V_25 * V_26 = F_70 ( V_98 ) ;
int V_31 , V_13 = 0 ;
for ( V_31 = 0 ; V_31 < V_26 -> V_55 -> V_71 ; V_31 ++ ) {
struct V_18 * V_19 = V_26 -> V_19 [ V_31 ] ;
if ( V_19 != NULL )
V_13 = F_76 ( V_19 ) ;
}
return V_13 ;
}
int F_77 ( struct V_101 * V_102 , struct V_103 * V_104 [] ,
struct V_23 * V_51 ,
const unsigned char * V_105 , T_3 V_106 ,
T_3 V_107 )
{
struct V_108 * V_109 = F_78 ( V_51 ) ;
struct V_110 * V_111 = V_109 -> V_111 ;
return F_79 ( V_111 , V_105 , V_106 ) ;
}
int F_80 ( struct V_101 * V_102 , struct V_103 * V_104 [] ,
struct V_23 * V_51 ,
const unsigned char * V_105 , T_3 V_106 )
{
struct V_108 * V_109 = F_78 ( V_51 ) ;
struct V_110 * V_111 = V_109 -> V_111 ;
return F_81 ( V_111 , V_105 , V_106 ) ;
}
int F_82 ( void )
{
return F_83 ( & V_112 ) ;
}
void F_84 ( void )
{
F_85 ( & V_112 ) ;
}
