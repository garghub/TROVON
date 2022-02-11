int
F_1 ( unsigned long V_1 , unsigned long V_2 , int * V_3 ,
unsigned long V_4 )
{
unsigned long long V_5 ;
int V_6 ;
if ( ! V_7 -> V_8 )
return - V_9 ;
F_2 () ;
if ( V_7 -> V_10 == V_11 - 1 ) {
F_3 ( & V_7 -> V_12 ) ;
return - V_9 ;
}
V_5 = F_4 () ;
V_6 = ++ V_7 -> V_10 ;
F_5 () ;
V_7 -> V_8 [ V_6 ] . V_1 = V_1 ;
V_7 -> V_8 [ V_6 ] . V_2 = V_2 ;
V_7 -> V_8 [ V_6 ] . V_5 = V_5 ;
V_7 -> V_8 [ V_6 ] . V_13 = 0 ;
V_7 -> V_8 [ V_6 ] . V_14 = V_4 ;
* V_3 = V_6 ;
return 0 ;
}
static void
F_6 ( struct V_15 * V_16 , unsigned long * V_1 ,
unsigned long V_4 )
{
int V_6 ;
V_6 = V_7 -> V_10 ;
if ( F_7 ( V_6 < 0 ) ) {
F_8 () ;
F_9 ( 1 ) ;
* V_1 = ( unsigned long ) V_17 ;
return;
}
#ifdef F_10
if ( F_7 ( V_7 -> V_8 [ V_6 ] . V_14 != V_4 ) ) {
F_8 () ;
F_11 ( 1 , L_1
L_2 ,
V_7 -> V_8 [ V_6 ] . V_14 ,
V_4 ,
( void * ) V_7 -> V_8 [ V_6 ] . V_2 ,
V_7 -> V_8 [ V_6 ] . V_1 ) ;
* V_1 = ( unsigned long ) V_17 ;
return;
}
#endif
* V_1 = V_7 -> V_8 [ V_6 ] . V_1 ;
V_16 -> V_2 = V_7 -> V_8 [ V_6 ] . V_2 ;
V_16 -> V_5 = V_7 -> V_8 [ V_6 ] . V_5 ;
V_16 -> V_18 = F_12 ( & V_7 -> V_12 ) ;
V_16 -> V_3 = V_6 ;
}
unsigned long F_13 ( unsigned long V_4 )
{
struct V_15 V_16 ;
unsigned long V_1 ;
F_6 ( & V_16 , & V_1 , V_4 ) ;
V_16 . V_19 = F_4 () ;
F_14 ( & V_16 ) ;
F_5 () ;
V_7 -> V_10 -- ;
if ( F_7 ( ! V_1 ) ) {
F_8 () ;
F_9 ( 1 ) ;
V_1 = ( unsigned long ) V_17 ;
}
return V_1 ;
}
int F_15 ( struct V_20 * V_21 ,
struct V_22 * V_16 ,
unsigned long V_23 ,
int V_24 )
{
struct V_25 * V_26 = & V_27 ;
struct V_28 * V_29 ;
struct V_30 * V_31 = V_21 -> V_31 ;
struct V_32 * V_33 ;
if ( F_7 ( F_16 ( V_34 ) ) )
return 0 ;
V_29 = F_17 ( V_31 , V_35 ,
sizeof( * V_33 ) , V_23 , V_24 ) ;
if ( ! V_29 )
return 0 ;
V_33 = F_18 ( V_29 ) ;
V_33 -> V_36 = * V_16 ;
if ( ! F_19 ( V_31 , V_26 , V_33 , V_29 ) )
F_20 ( V_31 , V_29 ) ;
return 1 ;
}
static inline int F_21 ( void )
{
if ( ! V_37 || F_22 ( V_38 ) )
return 0 ;
return F_23 () ;
}
int F_24 ( struct V_22 * V_16 )
{
struct V_20 * V_21 = V_39 ;
struct V_40 * V_41 ;
unsigned long V_23 ;
long V_42 ;
int V_1 ;
int V_43 ;
int V_24 ;
if ( ! F_25 ( V_7 ) )
return 0 ;
if ( ! ( V_16 -> V_3 || F_26 ( V_16 -> V_2 ) ) ||
F_21 () )
return 0 ;
F_27 ( V_23 ) ;
V_43 = F_28 () ;
V_41 = V_21 -> V_41 [ V_43 ] ;
V_42 = F_29 ( & V_41 -> V_42 ) ;
if ( F_30 ( V_42 == 1 ) ) {
V_24 = F_31 () ;
V_1 = F_15 ( V_21 , V_16 , V_23 , V_24 ) ;
} else {
V_1 = 0 ;
}
F_32 ( & V_41 -> V_42 ) ;
F_33 ( V_23 ) ;
return V_1 ;
}
int F_34 ( struct V_22 * V_16 )
{
if ( V_44 )
return 1 ;
else
return F_24 ( V_16 ) ;
}
static void
F_35 ( struct V_20 * V_21 ,
unsigned long V_45 , unsigned long V_23 , int V_24 )
{
T_1 time = F_4 () ;
struct V_22 V_46 = {
. V_2 = V_45 ,
. V_3 = 0 ,
} ;
struct V_15 V_1 = {
. V_2 = V_45 ,
. V_3 = 0 ,
. V_5 = time ,
. V_19 = time ,
} ;
F_15 ( V_21 , & V_46 , V_23 , V_24 ) ;
F_36 ( V_21 , & V_1 , V_23 , V_24 ) ;
}
void
F_37 ( struct V_20 * V_21 ,
unsigned long V_45 , unsigned long V_47 ,
unsigned long V_23 , int V_24 )
{
F_35 ( V_21 , V_45 , V_23 , V_24 ) ;
}
void F_36 ( struct V_20 * V_21 ,
struct V_15 * V_16 ,
unsigned long V_23 ,
int V_24 )
{
struct V_25 * V_26 = & V_48 ;
struct V_28 * V_29 ;
struct V_30 * V_31 = V_21 -> V_31 ;
struct V_49 * V_33 ;
if ( F_7 ( F_16 ( V_34 ) ) )
return;
V_29 = F_17 ( V_31 , V_50 ,
sizeof( * V_33 ) , V_23 , V_24 ) ;
if ( ! V_29 )
return;
V_33 = F_18 ( V_29 ) ;
V_33 -> V_1 = * V_16 ;
if ( ! F_19 ( V_31 , V_26 , V_33 , V_29 ) )
F_20 ( V_31 , V_29 ) ;
}
void F_38 ( struct V_15 * V_16 )
{
struct V_20 * V_21 = V_39 ;
struct V_40 * V_41 ;
unsigned long V_23 ;
long V_42 ;
int V_43 ;
int V_24 ;
F_27 ( V_23 ) ;
V_43 = F_28 () ;
V_41 = V_21 -> V_41 [ V_43 ] ;
V_42 = F_29 ( & V_41 -> V_42 ) ;
if ( F_30 ( V_42 == 1 ) ) {
V_24 = F_31 () ;
F_36 ( V_21 , V_16 , V_23 , V_24 ) ;
}
F_32 ( & V_41 -> V_42 ) ;
F_33 ( V_23 ) ;
}
void F_39 ( struct V_20 * V_21 )
{
V_39 = V_21 ;
F_40 () ;
}
void F_41 ( struct V_15 * V_16 )
{
if ( V_44 &&
( V_16 -> V_19 - V_16 -> V_5 < V_44 ) )
return;
else
F_38 ( V_16 ) ;
}
static int F_42 ( struct V_20 * V_21 )
{
int V_1 ;
F_39 ( V_21 ) ;
if ( V_44 )
V_1 = F_43 ( & F_41 ,
& F_34 ) ;
else
V_1 = F_43 ( & F_38 ,
& F_24 ) ;
if ( V_1 )
return V_1 ;
F_44 () ;
return 0 ;
}
static void F_45 ( struct V_20 * V_21 )
{
F_46 () ;
F_47 () ;
}
static enum V_51
F_48 ( struct V_52 * V_53 , int V_43 )
{
int V_1 ;
V_1 = F_49 ( V_53 , L_3 , V_54 , V_43 ) ;
if ( ! V_1 )
return V_55 ;
return V_56 ;
}
static enum V_51
F_50 ( struct V_52 * V_53 , T_2 V_57 )
{
char V_58 [ V_59 ] ;
char V_60 [ 11 ] ;
int V_61 = 0 ;
int V_1 ;
int V_62 ;
int V_63 ;
F_51 ( V_57 , V_58 ) ;
V_58 [ 7 ] = '\0' ;
sprintf ( V_60 , L_4 , V_57 ) ;
V_62 = strlen ( V_58 ) + strlen ( V_60 ) + 1 ;
if ( V_62 < V_64 )
V_61 = V_64 - V_62 ;
for ( V_63 = 0 ; V_63 < V_61 / 2 ; V_63 ++ ) {
V_1 = F_49 ( V_53 , L_5 ) ;
if ( ! V_1 )
return V_55 ;
}
V_1 = F_49 ( V_53 , L_6 , V_58 , V_60 ) ;
if ( ! V_1 )
return V_55 ;
for ( V_63 = 0 ; V_63 < V_61 - ( V_61 / 2 ) ; V_63 ++ ) {
V_1 = F_49 ( V_53 , L_5 ) ;
if ( ! V_1 )
return V_55 ;
}
return V_56 ;
}
static enum V_51
F_52 ( struct V_52 * V_53 , struct V_65 * V_33 )
{
if ( ! F_53 ( V_53 , ' ' ) )
return 0 ;
return F_54 ( V_53 , V_33 ) ;
}
static enum V_51
F_55 ( struct V_52 * V_53 , T_2 V_57 , int V_43 , struct V_66 * V_41 )
{
T_2 V_67 ;
T_2 * V_68 ;
int V_1 ;
if ( ! V_41 )
return V_56 ;
V_68 = & ( F_56 ( V_41 -> V_69 , V_43 ) -> V_68 ) ;
if ( * V_68 == V_57 )
return V_56 ;
V_67 = * V_68 ;
* V_68 = V_57 ;
if ( V_67 == - 1 )
return V_56 ;
V_1 = F_49 ( V_53 ,
L_7 ) ;
if ( ! V_1 )
return V_55 ;
V_1 = F_48 ( V_53 , V_43 ) ;
if ( V_1 == V_55 )
return V_55 ;
V_1 = F_50 ( V_53 , V_67 ) ;
if ( V_1 == V_55 )
return V_55 ;
V_1 = F_49 ( V_53 , L_8 ) ;
if ( ! V_1 )
return V_55 ;
V_1 = F_50 ( V_53 , V_57 ) ;
if ( V_1 == V_55 )
return V_55 ;
V_1 = F_49 ( V_53 ,
L_9 ) ;
if ( ! V_1 )
return V_55 ;
return V_56 ;
}
static struct V_49 *
F_57 ( struct V_70 * V_71 ,
struct V_32 * V_72 )
{
struct V_66 * V_41 = V_71 -> V_73 ;
struct V_74 * V_75 = NULL ;
struct V_28 * V_29 ;
struct V_49 * V_76 ;
if ( V_41 && V_41 -> V_77 ) {
V_72 = & V_41 -> V_46 ;
V_76 = & V_41 -> V_1 ;
} else {
V_75 = V_71 -> V_78 [ V_71 -> V_43 ] ;
if ( V_75 )
V_29 = F_58 ( V_75 , NULL ) ;
else {
F_59 ( V_71 -> V_21 -> V_31 , V_71 -> V_43 ,
NULL , NULL ) ;
V_29 = F_60 ( V_71 -> V_21 -> V_31 , V_71 -> V_43 ,
NULL , NULL ) ;
}
if ( ! V_29 )
return NULL ;
V_76 = F_18 ( V_29 ) ;
if ( V_41 ) {
V_41 -> V_46 = * V_72 ;
if ( V_76 -> V_46 . type == V_50 )
V_41 -> V_1 = * V_76 ;
else
V_41 -> V_1 . V_46 . type = V_76 -> V_46 . type ;
}
}
if ( V_76 -> V_46 . type != V_50 )
return NULL ;
if ( V_72 -> V_46 . V_57 != V_76 -> V_46 . V_57 ||
V_72 -> V_36 . V_2 != V_76 -> V_1 . V_2 )
return NULL ;
if ( V_75 )
F_61 ( V_75 , NULL ) ;
return V_76 ;
}
static int F_62 ( T_1 V_79 , struct V_52 * V_53 )
{
unsigned long V_80 ;
V_80 = F_63 ( V_79 , V_81 ) ;
V_80 /= 1000 ;
return F_49 ( V_53 , L_10 ,
( unsigned long ) V_79 , V_80 ) ;
}
static enum V_51
F_64 ( struct V_70 * V_71 , unsigned long V_82 ,
enum V_83 type , int V_43 , T_2 V_57 , T_3 V_23 )
{
int V_1 ;
struct V_52 * V_53 = & V_71 -> V_84 ;
if ( V_82 < ( unsigned long ) V_85 ||
V_82 >= ( unsigned long ) V_86 )
return V_87 ;
if ( V_88 & V_89 ) {
if ( V_23 & V_90 ) {
V_1 = F_62 ( V_71 -> V_91 , V_53 ) ;
if ( ! V_1 )
return V_55 ;
}
if ( V_23 & V_92 ) {
V_1 = F_48 ( V_53 , V_43 ) ;
if ( V_1 == V_55 )
return V_55 ;
}
if ( V_23 & V_93 ) {
V_1 = F_50 ( V_53 , V_57 ) ;
if ( V_1 == V_55 )
return V_55 ;
V_1 = F_49 ( V_53 , L_11 ) ;
if ( ! V_1 )
return V_55 ;
}
}
V_1 = F_65 ( V_94 , V_53 , V_23 ) ;
if ( V_1 != V_56 )
return V_1 ;
if ( type == V_35 )
V_1 = F_49 ( V_53 , L_12 ) ;
else
V_1 = F_49 ( V_53 , L_13 ) ;
if ( ! V_1 )
return V_55 ;
V_1 = F_65 ( V_95 , V_53 , V_23 ) ;
if ( V_1 != V_56 )
return V_1 ;
V_1 = F_49 ( V_53 , L_14 ) ;
if ( ! V_1 )
return V_55 ;
return V_56 ;
}
enum V_51
F_66 ( unsigned long long V_96 , struct V_52 * V_53 )
{
unsigned long V_97 = F_63 ( V_96 , 1000 ) ;
char V_98 [ 21 ] ;
char V_99 [ 5 ] ;
int V_1 , V_62 ;
int V_63 ;
sprintf ( V_98 , L_15 , ( unsigned long ) V_96 ) ;
V_1 = F_49 ( V_53 , L_16 , V_98 ) ;
if ( ! V_1 )
return V_55 ;
V_62 = strlen ( V_98 ) ;
if ( V_62 < 7 ) {
T_4 V_100 = F_67 ( T_4 , sizeof( V_99 ) , 8UL - V_62 ) ;
snprintf ( V_99 , V_100 , L_17 , V_97 ) ;
V_1 = F_49 ( V_53 , L_18 , V_99 ) ;
if ( ! V_1 )
return V_55 ;
V_62 += strlen ( V_99 ) ;
}
V_1 = F_49 ( V_53 , L_19 ) ;
if ( ! V_1 )
return V_55 ;
for ( V_63 = V_62 ; V_63 < 7 ; V_63 ++ ) {
V_1 = F_49 ( V_53 , L_5 ) ;
if ( ! V_1 )
return V_55 ;
}
return V_56 ;
}
static enum V_51
F_65 ( unsigned long long V_96 , struct V_52 * V_53 ,
T_3 V_23 )
{
int V_1 = - 1 ;
if ( ! ( V_23 & V_101 ) ||
! ( V_88 & V_89 ) )
return V_56 ;
switch ( V_96 ) {
case V_102 :
V_1 = F_49 ( V_53 , L_20 ) ;
return V_1 ? V_56 : V_55 ;
case V_94 :
V_1 = F_49 ( V_53 , L_21 ) ;
return V_1 ? V_56 : V_55 ;
case V_95 :
V_1 = F_49 ( V_53 , L_22 ) ;
return V_1 ? V_56 : V_55 ;
}
if ( V_23 & V_103 ) {
if ( V_96 > 100000ULL )
V_1 = F_49 ( V_53 , L_23 ) ;
else if ( V_96 > 10000ULL )
V_1 = F_49 ( V_53 , L_24 ) ;
}
if ( V_1 == - 1 )
V_1 = F_49 ( V_53 , L_21 ) ;
if ( ! V_1 )
return V_55 ;
V_1 = F_66 ( V_96 , V_53 ) ;
if ( V_1 != V_56 )
return V_1 ;
V_1 = F_49 ( V_53 , L_25 ) ;
if ( ! V_1 )
return V_55 ;
return V_56 ;
}
static enum V_51
F_68 ( struct V_70 * V_71 ,
struct V_32 * V_33 ,
struct V_49 * V_104 ,
struct V_52 * V_53 , T_3 V_23 )
{
struct V_66 * V_41 = V_71 -> V_73 ;
struct V_15 * V_105 ;
struct V_22 * V_26 ;
unsigned long long V_96 ;
int V_1 ;
int V_63 ;
V_105 = & V_104 -> V_1 ;
V_26 = & V_33 -> V_36 ;
V_96 = V_105 -> V_19 - V_105 -> V_5 ;
if ( V_41 ) {
struct V_106 * V_69 ;
int V_43 = V_71 -> V_43 ;
V_69 = F_56 ( V_41 -> V_69 , V_43 ) ;
V_69 -> V_3 = V_26 -> V_3 - 1 ;
if ( V_26 -> V_3 < V_11 )
V_69 -> V_107 [ V_26 -> V_3 ] = 0 ;
}
V_1 = F_65 ( V_96 , V_53 , V_23 ) ;
if ( V_1 == V_55 )
return V_55 ;
for ( V_63 = 0 ; V_63 < V_26 -> V_3 * V_108 ; V_63 ++ ) {
V_1 = F_49 ( V_53 , L_5 ) ;
if ( ! V_1 )
return V_55 ;
}
V_1 = F_49 ( V_53 , L_26 , ( void * ) V_26 -> V_2 ) ;
if ( ! V_1 )
return V_55 ;
return V_56 ;
}
static enum V_51
F_69 ( struct V_70 * V_71 ,
struct V_32 * V_33 ,
struct V_52 * V_53 , int V_43 , T_3 V_23 )
{
struct V_22 * V_26 = & V_33 -> V_36 ;
struct V_66 * V_41 = V_71 -> V_73 ;
int V_1 ;
int V_63 ;
if ( V_41 ) {
struct V_106 * V_69 ;
int V_43 = V_71 -> V_43 ;
V_69 = F_56 ( V_41 -> V_69 , V_43 ) ;
V_69 -> V_3 = V_26 -> V_3 ;
if ( V_26 -> V_3 < V_11 )
V_69 -> V_107 [ V_26 -> V_3 ] = V_26 -> V_2 ;
}
V_1 = F_65 ( V_102 , V_53 , V_23 ) ;
if ( V_1 != V_56 )
return V_1 ;
for ( V_63 = 0 ; V_63 < V_26 -> V_3 * V_108 ; V_63 ++ ) {
V_1 = F_49 ( V_53 , L_5 ) ;
if ( ! V_1 )
return V_55 ;
}
V_1 = F_49 ( V_53 , L_27 , ( void * ) V_26 -> V_2 ) ;
if ( ! V_1 )
return V_55 ;
return V_109 ;
}
static enum V_51
F_70 ( struct V_70 * V_71 , struct V_52 * V_53 ,
int type , unsigned long V_82 , T_3 V_23 )
{
struct V_66 * V_41 = V_71 -> V_73 ;
struct V_65 * V_46 = V_71 -> V_46 ;
int V_43 = V_71 -> V_43 ;
int V_1 ;
if ( F_55 ( V_53 , V_46 -> V_57 , V_43 , V_41 ) == V_55 )
return V_55 ;
if ( type ) {
V_1 = F_64 ( V_71 , V_82 , type , V_43 , V_46 -> V_57 , V_23 ) ;
if ( V_1 == V_55 )
return V_55 ;
}
if ( ! ( V_88 & V_89 ) )
return 0 ;
if ( V_23 & V_90 ) {
V_1 = F_62 ( V_71 -> V_91 , V_53 ) ;
if ( ! V_1 )
return V_55 ;
}
if ( V_23 & V_92 ) {
V_1 = F_48 ( V_53 , V_43 ) ;
if ( V_1 == V_55 )
return V_55 ;
}
if ( V_23 & V_93 ) {
V_1 = F_50 ( V_53 , V_46 -> V_57 ) ;
if ( V_1 == V_55 )
return V_55 ;
V_1 = F_49 ( V_53 , L_11 ) ;
if ( ! V_1 )
return V_55 ;
}
if ( V_88 & V_110 ) {
V_1 = F_52 ( V_53 , V_46 ) ;
if ( V_1 == V_55 )
return V_55 ;
}
return 0 ;
}
static int
F_71 ( struct V_70 * V_71 , T_3 V_23 ,
unsigned long V_82 , int V_3 )
{
int V_43 = V_71 -> V_43 ;
int * V_111 ;
struct V_66 * V_41 = V_71 -> V_73 ;
if ( ( V_23 & V_112 ) ||
( ! V_41 ) )
return 0 ;
V_111 = & ( F_56 ( V_41 -> V_69 , V_43 ) -> V_111 ) ;
if ( * V_111 >= 0 )
return 1 ;
if ( ( V_82 < ( unsigned long ) V_85 ) ||
( V_82 >= ( unsigned long ) V_86 ) )
return 0 ;
* V_111 = V_3 ;
return 1 ;
}
static int
F_72 ( struct V_70 * V_71 , T_3 V_23 , int V_3 )
{
int V_43 = V_71 -> V_43 ;
int * V_111 ;
struct V_66 * V_41 = V_71 -> V_73 ;
if ( ( V_23 & V_112 ) ||
( ! V_41 ) )
return 0 ;
V_111 = & ( F_56 ( V_41 -> V_69 , V_43 ) -> V_111 ) ;
if ( * V_111 == - 1 )
return 0 ;
if ( * V_111 >= V_3 ) {
* V_111 = - 1 ;
return 1 ;
}
return 1 ;
}
static enum V_51
F_73 ( struct V_32 * V_113 , struct V_52 * V_53 ,
struct V_70 * V_71 , T_3 V_23 )
{
struct V_66 * V_41 = V_71 -> V_73 ;
struct V_22 * V_26 = & V_113 -> V_36 ;
struct V_49 * V_114 ;
static enum V_51 V_1 ;
int V_43 = V_71 -> V_43 ;
if ( F_71 ( V_71 , V_23 , V_26 -> V_2 , V_26 -> V_3 ) )
return V_56 ;
if ( F_70 ( V_71 , V_53 , V_35 , V_26 -> V_2 , V_23 ) )
return V_55 ;
V_114 = F_57 ( V_71 , V_113 ) ;
if ( V_114 )
V_1 = F_68 ( V_71 , V_113 , V_114 , V_53 , V_23 ) ;
else
V_1 = F_69 ( V_71 , V_113 , V_53 , V_43 , V_23 ) ;
if ( V_41 ) {
if ( V_53 -> V_115 ) {
V_41 -> V_77 = 1 ;
V_41 -> V_43 = V_43 ;
} else
V_41 -> V_77 = 0 ;
}
return V_1 ;
}
static enum V_51
F_74 ( struct V_15 * V_16 , struct V_52 * V_53 ,
struct V_65 * V_46 , struct V_70 * V_71 ,
T_3 V_23 )
{
unsigned long long V_96 = V_16 -> V_19 - V_16 -> V_5 ;
struct V_66 * V_41 = V_71 -> V_73 ;
T_2 V_57 = V_46 -> V_57 ;
int V_43 = V_71 -> V_43 ;
int V_116 = 1 ;
int V_1 ;
int V_63 ;
if ( F_72 ( V_71 , V_23 , V_16 -> V_3 ) )
return V_56 ;
if ( V_41 ) {
struct V_106 * V_69 ;
int V_43 = V_71 -> V_43 ;
V_69 = F_56 ( V_41 -> V_69 , V_43 ) ;
V_69 -> V_3 = V_16 -> V_3 - 1 ;
if ( V_16 -> V_3 < V_11 ) {
if ( V_69 -> V_107 [ V_16 -> V_3 ] != V_16 -> V_2 )
V_116 = 0 ;
V_69 -> V_107 [ V_16 -> V_3 ] = 0 ;
}
}
if ( F_70 ( V_71 , V_53 , 0 , 0 , V_23 ) )
return V_55 ;
V_1 = F_65 ( V_96 , V_53 , V_23 ) ;
if ( V_1 == V_55 )
return V_55 ;
for ( V_63 = 0 ; V_63 < V_16 -> V_3 * V_108 ; V_63 ++ ) {
V_1 = F_49 ( V_53 , L_5 ) ;
if ( ! V_1 )
return V_55 ;
}
if ( V_116 ) {
V_1 = F_49 ( V_53 , L_28 ) ;
if ( ! V_1 )
return V_55 ;
} else {
V_1 = F_49 ( V_53 , L_29 , ( void * ) V_16 -> V_2 ) ;
if ( ! V_1 )
return V_55 ;
}
if ( V_23 & V_117 ) {
V_1 = F_49 ( V_53 , L_30 ,
V_16 -> V_18 ) ;
if ( ! V_1 )
return V_55 ;
}
V_1 = F_64 ( V_71 , V_16 -> V_2 , V_50 ,
V_43 , V_57 , V_23 ) ;
if ( V_1 == V_55 )
return V_55 ;
return V_56 ;
}
static enum V_51
F_75 ( struct V_52 * V_53 , struct V_65 * V_46 ,
struct V_70 * V_71 , T_3 V_23 )
{
unsigned long V_118 = ( V_88 & V_119 ) ;
struct V_66 * V_41 = V_71 -> V_73 ;
struct V_120 * V_29 ;
int V_3 = 0 ;
int V_1 ;
int V_63 ;
if ( V_41 )
V_3 = F_56 ( V_41 -> V_69 , V_71 -> V_43 ) -> V_3 ;
if ( F_70 ( V_71 , V_53 , 0 , 0 , V_23 ) )
return V_55 ;
V_1 = F_65 ( V_102 , V_53 , V_23 ) ;
if ( V_1 != V_56 )
return V_1 ;
if ( V_3 > 0 )
for ( V_63 = 0 ; V_63 < ( V_3 + 1 ) * V_108 ; V_63 ++ ) {
V_1 = F_49 ( V_53 , L_5 ) ;
if ( ! V_1 )
return V_55 ;
}
V_1 = F_49 ( V_53 , L_31 ) ;
if ( ! V_1 )
return V_55 ;
switch ( V_71 -> V_46 -> type ) {
case V_121 :
V_1 = F_76 ( V_71 ) ;
if ( V_1 != V_56 )
return V_1 ;
break;
case V_122 :
V_1 = F_77 ( V_71 ) ;
if ( V_1 != V_56 )
return V_1 ;
break;
default:
V_29 = F_78 ( V_46 -> type ) ;
if ( ! V_29 )
return V_87 ;
V_1 = V_29 -> V_123 -> V_16 ( V_71 , V_118 , V_29 ) ;
if ( V_1 != V_56 )
return V_1 ;
}
if ( V_53 -> V_31 [ V_53 -> V_62 - 1 ] == '\n' ) {
V_53 -> V_31 [ V_53 -> V_62 - 1 ] = '\0' ;
V_53 -> V_62 -- ;
}
V_1 = F_49 ( V_53 , L_32 ) ;
if ( ! V_1 )
return V_55 ;
return V_56 ;
}
enum V_51
F_79 ( struct V_70 * V_71 , T_3 V_23 )
{
struct V_32 * V_113 ;
struct V_66 * V_41 = V_71 -> V_73 ;
struct V_65 * V_33 = V_71 -> V_46 ;
struct V_52 * V_53 = & V_71 -> V_84 ;
int V_43 = V_71 -> V_43 ;
int V_1 ;
if ( V_41 && F_56 ( V_41 -> V_69 , V_43 ) -> V_124 ) {
F_56 ( V_41 -> V_69 , V_43 ) -> V_124 = 0 ;
return V_56 ;
}
if ( V_41 && V_41 -> V_77 ) {
V_113 = & V_41 -> V_46 ;
V_71 -> V_43 = V_41 -> V_43 ;
V_1 = F_73 ( V_113 , V_53 , V_71 , V_23 ) ;
if ( V_1 == V_56 && V_71 -> V_43 != V_43 ) {
F_56 ( V_41 -> V_69 , V_71 -> V_43 ) -> V_124 = 1 ;
V_1 = V_109 ;
}
V_71 -> V_43 = V_43 ;
return V_1 ;
}
switch ( V_33 -> type ) {
case V_35 : {
struct V_32 V_125 ;
F_80 ( V_113 , V_33 ) ;
V_125 = * V_113 ;
return F_73 ( & V_125 , V_53 , V_71 , V_23 ) ;
}
case V_50 : {
struct V_49 * V_113 ;
F_80 ( V_113 , V_33 ) ;
return F_74 ( & V_113 -> V_1 , V_53 , V_33 , V_71 , V_23 ) ;
}
case V_126 :
case V_127 :
return V_87 ;
default:
return F_75 ( V_53 , V_33 , V_71 , V_23 ) ;
}
return V_56 ;
}
static enum V_51
F_81 ( struct V_70 * V_71 )
{
return F_79 ( V_71 , V_128 . V_129 ) ;
}
static enum V_51
F_82 ( struct V_70 * V_71 , int V_23 ,
struct V_120 * V_29 )
{
return F_81 ( V_71 ) ;
}
static void F_83 ( struct V_130 * V_53 , T_3 V_23 )
{
static const char V_61 [] = L_33
L_34
L_35 ;
int V_131 = 0 ;
if ( V_23 & V_90 )
V_131 += 16 ;
if ( V_23 & V_92 )
V_131 += 4 ;
if ( V_23 & V_93 )
V_131 += 17 ;
F_84 ( V_53 , L_36 , V_131 , V_61 ) ;
F_84 ( V_53 , L_37 , V_131 , V_61 ) ;
F_84 ( V_53 , L_38 , V_131 , V_61 ) ;
F_84 ( V_53 , L_39 , V_131 , V_61 ) ;
F_84 ( V_53 , L_40 , V_131 , V_61 ) ;
}
static void F_85 ( struct V_130 * V_53 , T_3 V_23 )
{
int V_132 = V_88 & V_110 ;
if ( V_132 )
F_83 ( V_53 , V_23 ) ;
F_84 ( V_53 , L_41 ) ;
if ( V_23 & V_90 )
F_84 ( V_53 , L_42 ) ;
if ( V_23 & V_92 )
F_84 ( V_53 , L_43 ) ;
if ( V_23 & V_93 )
F_84 ( V_53 , L_44 ) ;
if ( V_132 )
F_84 ( V_53 , L_45 ) ;
if ( V_23 & V_101 )
F_84 ( V_53 , L_46 ) ;
F_84 ( V_53 , L_47 ) ;
F_84 ( V_53 , L_41 ) ;
if ( V_23 & V_90 )
F_84 ( V_53 , L_48 ) ;
if ( V_23 & V_92 )
F_84 ( V_53 , L_49 ) ;
if ( V_23 & V_93 )
F_84 ( V_53 , L_50 ) ;
if ( V_132 )
F_84 ( V_53 , L_45 ) ;
if ( V_23 & V_101 )
F_84 ( V_53 , L_51 ) ;
F_84 ( V_53 , L_52 ) ;
}
void F_86 ( struct V_130 * V_53 )
{
F_87 ( V_53 , V_128 . V_129 ) ;
}
void F_87 ( struct V_130 * V_53 , T_3 V_23 )
{
struct V_70 * V_71 = V_53 -> V_73 ;
if ( ! ( V_88 & V_89 ) )
return;
if ( V_88 & V_110 ) {
if ( F_88 ( V_71 ) )
return;
F_89 ( V_53 , V_71 ) ;
}
F_85 ( V_53 , V_23 ) ;
}
void F_90 ( struct V_70 * V_71 )
{
struct V_66 * V_41 ;
int V_43 ;
V_71 -> V_73 = NULL ;
V_41 = F_91 ( sizeof( * V_41 ) , V_133 ) ;
if ( ! V_41 )
goto V_134;
V_41 -> V_69 = F_92 ( struct V_106 ) ;
if ( ! V_41 -> V_69 )
goto V_135;
F_93 (cpu) {
T_2 * V_57 = & ( F_56 ( V_41 -> V_69 , V_43 ) -> V_68 ) ;
int * V_3 = & ( F_56 ( V_41 -> V_69 , V_43 ) -> V_3 ) ;
int * V_124 = & ( F_56 ( V_41 -> V_69 , V_43 ) -> V_124 ) ;
int * V_111 = & ( F_56 ( V_41 -> V_69 , V_43 ) -> V_111 ) ;
* V_57 = - 1 ;
* V_3 = 0 ;
* V_124 = 0 ;
* V_111 = - 1 ;
}
V_71 -> V_73 = V_41 ;
return;
V_135:
F_94 ( V_41 ) ;
V_134:
F_95 ( L_53 ) ;
}
void F_96 ( struct V_70 * V_71 )
{
struct V_66 * V_41 = V_71 -> V_73 ;
if ( V_41 ) {
F_97 ( V_41 -> V_69 ) ;
F_94 ( V_41 ) ;
}
}
static int F_98 ( T_3 V_136 , T_3 V_137 , int V_138 )
{
if ( V_137 == V_112 )
V_37 = ! V_138 ;
return 0 ;
}
static T_5 int F_99 ( void )
{
V_54 = snprintf ( NULL , 0 , L_4 , V_139 - 1 ) ;
if ( ! F_100 ( & V_140 ) ) {
F_95 ( L_54 ) ;
return 1 ;
}
if ( ! F_100 ( & V_141 ) ) {
F_95 ( L_54 ) ;
return 1 ;
}
return F_101 ( & V_142 ) ;
}
