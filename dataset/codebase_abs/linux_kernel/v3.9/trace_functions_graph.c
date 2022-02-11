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
#if F_10 ( V_18 ) && ! F_10 ( V_19 )
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
V_16 -> V_20 = F_12 ( & V_7 -> V_12 ) ;
V_16 -> V_3 = V_6 ;
}
unsigned long F_13 ( unsigned long V_4 )
{
struct V_15 V_16 ;
unsigned long V_1 ;
F_6 ( & V_16 , & V_1 , V_4 ) ;
V_16 . V_21 = F_4 () ;
F_5 () ;
V_7 -> V_10 -- ;
F_14 ( & V_16 ) ;
if ( F_7 ( ! V_1 ) ) {
F_8 () ;
F_9 ( 1 ) ;
V_1 = ( unsigned long ) V_17 ;
}
return V_1 ;
}
int F_15 ( struct V_22 * V_23 ,
struct V_24 * V_16 ,
unsigned long V_25 ,
int V_26 )
{
struct V_27 * V_28 = & V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_33 = V_23 -> V_33 ;
struct V_34 * V_35 ;
if ( F_7 ( F_16 ( V_36 ) ) )
return 0 ;
V_31 = F_17 ( V_33 , V_37 ,
sizeof( * V_35 ) , V_25 , V_26 ) ;
if ( ! V_31 )
return 0 ;
V_35 = F_18 ( V_31 ) ;
V_35 -> V_38 = * V_16 ;
if ( ! F_19 ( V_33 , V_28 , V_35 , V_31 ) )
F_20 ( V_33 , V_31 ) ;
return 1 ;
}
static inline int F_21 ( void )
{
if ( ! V_39 || F_22 ( V_40 ) )
return 0 ;
return F_23 () ;
}
int F_24 ( struct V_24 * V_16 )
{
struct V_22 * V_23 = V_41 ;
struct V_42 * V_43 ;
unsigned long V_25 ;
long V_44 ;
int V_1 ;
int V_45 ;
int V_26 ;
if ( ! F_25 ( V_7 ) )
return 0 ;
if ( ( ! ( V_16 -> V_3 || F_26 ( V_16 -> V_2 ) ) ||
F_21 () ) ||
( V_46 && V_16 -> V_3 >= V_46 ) )
return 0 ;
F_27 ( V_25 ) ;
V_45 = F_28 () ;
V_43 = V_23 -> V_43 [ V_45 ] ;
V_44 = F_29 ( & V_43 -> V_44 ) ;
if ( F_30 ( V_44 == 1 ) ) {
V_26 = F_31 () ;
V_1 = F_15 ( V_23 , V_16 , V_25 , V_26 ) ;
} else {
V_1 = 0 ;
}
F_32 ( & V_43 -> V_44 ) ;
F_33 ( V_25 ) ;
return V_1 ;
}
int F_34 ( struct V_24 * V_16 )
{
if ( V_47 )
return 1 ;
else
return F_24 ( V_16 ) ;
}
static void
F_35 ( struct V_22 * V_23 ,
unsigned long V_48 , unsigned long V_25 , int V_26 )
{
T_1 time = F_4 () ;
struct V_24 V_49 = {
. V_2 = V_48 ,
. V_3 = 0 ,
} ;
struct V_15 V_1 = {
. V_2 = V_48 ,
. V_3 = 0 ,
. V_5 = time ,
. V_21 = time ,
} ;
F_15 ( V_23 , & V_49 , V_25 , V_26 ) ;
F_36 ( V_23 , & V_1 , V_25 , V_26 ) ;
}
void
F_37 ( struct V_22 * V_23 ,
unsigned long V_48 , unsigned long V_50 ,
unsigned long V_25 , int V_26 )
{
F_35 ( V_23 , V_48 , V_25 , V_26 ) ;
}
void F_36 ( struct V_22 * V_23 ,
struct V_15 * V_16 ,
unsigned long V_25 ,
int V_26 )
{
struct V_27 * V_28 = & V_51 ;
struct V_30 * V_31 ;
struct V_32 * V_33 = V_23 -> V_33 ;
struct V_52 * V_35 ;
if ( F_7 ( F_16 ( V_36 ) ) )
return;
V_31 = F_17 ( V_33 , V_53 ,
sizeof( * V_35 ) , V_25 , V_26 ) ;
if ( ! V_31 )
return;
V_35 = F_18 ( V_31 ) ;
V_35 -> V_1 = * V_16 ;
if ( ! F_19 ( V_33 , V_28 , V_35 , V_31 ) )
F_20 ( V_33 , V_31 ) ;
}
void F_38 ( struct V_15 * V_16 )
{
struct V_22 * V_23 = V_41 ;
struct V_42 * V_43 ;
unsigned long V_25 ;
long V_44 ;
int V_45 ;
int V_26 ;
F_27 ( V_25 ) ;
V_45 = F_28 () ;
V_43 = V_23 -> V_43 [ V_45 ] ;
V_44 = F_29 ( & V_43 -> V_44 ) ;
if ( F_30 ( V_44 == 1 ) ) {
V_26 = F_31 () ;
F_36 ( V_23 , V_16 , V_25 , V_26 ) ;
}
F_32 ( & V_43 -> V_44 ) ;
F_33 ( V_25 ) ;
}
void F_39 ( struct V_22 * V_23 )
{
V_41 = V_23 ;
F_40 () ;
}
void F_41 ( struct V_15 * V_16 )
{
if ( V_47 &&
( V_16 -> V_21 - V_16 -> V_5 < V_47 ) )
return;
else
F_38 ( V_16 ) ;
}
static int F_42 ( struct V_22 * V_23 )
{
int V_1 ;
F_39 ( V_23 ) ;
if ( V_47 )
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
static void F_45 ( struct V_22 * V_23 )
{
F_46 () ;
F_47 () ;
}
static enum V_54
F_48 ( struct V_55 * V_56 , int V_45 )
{
int V_1 ;
V_1 = F_49 ( V_56 , L_3 , V_57 , V_45 ) ;
if ( ! V_1 )
return V_58 ;
return V_59 ;
}
static enum V_54
F_50 ( struct V_55 * V_56 , T_2 V_60 )
{
char V_61 [ V_62 ] ;
char V_63 [ 11 ] ;
int V_64 = 0 ;
int V_1 ;
int V_65 ;
int V_66 ;
F_51 ( V_60 , V_61 ) ;
V_61 [ 7 ] = '\0' ;
sprintf ( V_63 , L_4 , V_60 ) ;
V_65 = strlen ( V_61 ) + strlen ( V_63 ) + 1 ;
if ( V_65 < V_67 )
V_64 = V_67 - V_65 ;
for ( V_66 = 0 ; V_66 < V_64 / 2 ; V_66 ++ ) {
V_1 = F_49 ( V_56 , L_5 ) ;
if ( ! V_1 )
return V_58 ;
}
V_1 = F_49 ( V_56 , L_6 , V_61 , V_63 ) ;
if ( ! V_1 )
return V_58 ;
for ( V_66 = 0 ; V_66 < V_64 - ( V_64 / 2 ) ; V_66 ++ ) {
V_1 = F_49 ( V_56 , L_5 ) ;
if ( ! V_1 )
return V_58 ;
}
return V_59 ;
}
static enum V_54
F_52 ( struct V_55 * V_56 , struct V_68 * V_35 )
{
if ( ! F_53 ( V_56 , ' ' ) )
return 0 ;
return F_54 ( V_56 , V_35 ) ;
}
static enum V_54
F_55 ( struct V_55 * V_56 , T_2 V_60 , int V_45 , struct V_69 * V_43 )
{
T_2 V_70 ;
T_2 * V_71 ;
int V_1 ;
if ( ! V_43 )
return V_59 ;
V_71 = & ( F_56 ( V_43 -> V_72 , V_45 ) -> V_71 ) ;
if ( * V_71 == V_60 )
return V_59 ;
V_70 = * V_71 ;
* V_71 = V_60 ;
if ( V_70 == - 1 )
return V_59 ;
V_1 = F_49 ( V_56 ,
L_7 ) ;
if ( ! V_1 )
return V_58 ;
V_1 = F_48 ( V_56 , V_45 ) ;
if ( V_1 == V_58 )
return V_58 ;
V_1 = F_50 ( V_56 , V_70 ) ;
if ( V_1 == V_58 )
return V_58 ;
V_1 = F_49 ( V_56 , L_8 ) ;
if ( ! V_1 )
return V_58 ;
V_1 = F_50 ( V_56 , V_60 ) ;
if ( V_1 == V_58 )
return V_58 ;
V_1 = F_49 ( V_56 ,
L_9 ) ;
if ( ! V_1 )
return V_58 ;
return V_59 ;
}
static struct V_52 *
F_57 ( struct V_73 * V_74 ,
struct V_34 * V_75 )
{
struct V_69 * V_43 = V_74 -> V_76 ;
struct V_77 * V_78 = NULL ;
struct V_30 * V_31 ;
struct V_52 * V_79 ;
if ( V_43 && V_43 -> V_80 ) {
V_75 = & V_43 -> V_49 ;
V_79 = & V_43 -> V_1 ;
} else {
V_78 = F_58 ( V_74 , V_74 -> V_45 ) ;
if ( V_78 )
V_31 = F_59 ( V_78 , NULL ) ;
else {
F_60 ( V_74 -> V_23 -> V_33 , V_74 -> V_45 ,
NULL , NULL ) ;
V_31 = F_61 ( V_74 -> V_23 -> V_33 , V_74 -> V_45 ,
NULL , NULL ) ;
}
if ( ! V_31 )
return NULL ;
V_79 = F_18 ( V_31 ) ;
if ( V_43 ) {
V_43 -> V_49 = * V_75 ;
if ( V_79 -> V_49 . type == V_53 )
V_43 -> V_1 = * V_79 ;
else
V_43 -> V_1 . V_49 . type = V_79 -> V_49 . type ;
}
}
if ( V_79 -> V_49 . type != V_53 )
return NULL ;
if ( V_75 -> V_49 . V_60 != V_79 -> V_49 . V_60 ||
V_75 -> V_38 . V_2 != V_79 -> V_1 . V_2 )
return NULL ;
if ( V_78 )
F_62 ( V_78 , NULL ) ;
return V_79 ;
}
static int F_63 ( T_1 V_81 , struct V_55 * V_56 )
{
unsigned long V_82 ;
V_82 = F_64 ( V_81 , V_83 ) ;
V_82 /= 1000 ;
return F_49 ( V_56 , L_10 ,
( unsigned long ) V_81 , V_82 ) ;
}
static enum V_54
F_65 ( struct V_73 * V_74 , unsigned long V_84 ,
enum V_85 type , int V_45 , T_2 V_60 , T_3 V_25 )
{
int V_1 ;
struct V_55 * V_56 = & V_74 -> V_86 ;
if ( V_84 < ( unsigned long ) V_87 ||
V_84 >= ( unsigned long ) V_88 )
return V_89 ;
if ( V_90 & V_91 ) {
if ( V_25 & V_92 ) {
V_1 = F_63 ( V_74 -> V_93 , V_56 ) ;
if ( ! V_1 )
return V_58 ;
}
if ( V_25 & V_94 ) {
V_1 = F_48 ( V_56 , V_45 ) ;
if ( V_1 == V_58 )
return V_58 ;
}
if ( V_25 & V_95 ) {
V_1 = F_50 ( V_56 , V_60 ) ;
if ( V_1 == V_58 )
return V_58 ;
V_1 = F_49 ( V_56 , L_11 ) ;
if ( ! V_1 )
return V_58 ;
}
}
V_1 = F_66 ( V_96 , V_56 , V_25 ) ;
if ( V_1 != V_59 )
return V_1 ;
if ( type == V_37 )
V_1 = F_49 ( V_56 , L_12 ) ;
else
V_1 = F_49 ( V_56 , L_13 ) ;
if ( ! V_1 )
return V_58 ;
V_1 = F_66 ( V_97 , V_56 , V_25 ) ;
if ( V_1 != V_59 )
return V_1 ;
V_1 = F_49 ( V_56 , L_14 ) ;
if ( ! V_1 )
return V_58 ;
return V_59 ;
}
enum V_54
F_67 ( unsigned long long V_98 , struct V_55 * V_56 )
{
unsigned long V_99 = F_64 ( V_98 , 1000 ) ;
char V_100 [ 21 ] ;
char V_101 [ 5 ] ;
int V_1 , V_65 ;
int V_66 ;
sprintf ( V_100 , L_15 , ( unsigned long ) V_98 ) ;
V_1 = F_49 ( V_56 , L_16 , V_100 ) ;
if ( ! V_1 )
return V_58 ;
V_65 = strlen ( V_100 ) ;
if ( V_65 < 7 ) {
T_4 V_102 = F_68 ( T_4 , sizeof( V_101 ) , 8UL - V_65 ) ;
snprintf ( V_101 , V_102 , L_17 , V_99 ) ;
V_1 = F_49 ( V_56 , L_18 , V_101 ) ;
if ( ! V_1 )
return V_58 ;
V_65 += strlen ( V_101 ) ;
}
V_1 = F_49 ( V_56 , L_19 ) ;
if ( ! V_1 )
return V_58 ;
for ( V_66 = V_65 ; V_66 < 7 ; V_66 ++ ) {
V_1 = F_49 ( V_56 , L_5 ) ;
if ( ! V_1 )
return V_58 ;
}
return V_59 ;
}
static enum V_54
F_66 ( unsigned long long V_98 , struct V_55 * V_56 ,
T_3 V_25 )
{
int V_1 = - 1 ;
if ( ! ( V_25 & V_103 ) ||
! ( V_90 & V_91 ) )
return V_59 ;
switch ( V_98 ) {
case V_104 :
V_1 = F_49 ( V_56 , L_20 ) ;
return V_1 ? V_59 : V_58 ;
case V_96 :
V_1 = F_49 ( V_56 , L_21 ) ;
return V_1 ? V_59 : V_58 ;
case V_97 :
V_1 = F_49 ( V_56 , L_22 ) ;
return V_1 ? V_59 : V_58 ;
}
if ( V_25 & V_105 ) {
if ( V_98 > 100000ULL )
V_1 = F_49 ( V_56 , L_23 ) ;
else if ( V_98 > 10000ULL )
V_1 = F_49 ( V_56 , L_24 ) ;
}
if ( V_1 == - 1 )
V_1 = F_49 ( V_56 , L_21 ) ;
if ( ! V_1 )
return V_58 ;
V_1 = F_67 ( V_98 , V_56 ) ;
if ( V_1 != V_59 )
return V_1 ;
V_1 = F_49 ( V_56 , L_25 ) ;
if ( ! V_1 )
return V_58 ;
return V_59 ;
}
static enum V_54
F_69 ( struct V_73 * V_74 ,
struct V_34 * V_35 ,
struct V_52 * V_106 ,
struct V_55 * V_56 , T_3 V_25 )
{
struct V_69 * V_43 = V_74 -> V_76 ;
struct V_15 * V_107 ;
struct V_24 * V_28 ;
unsigned long long V_98 ;
int V_1 ;
int V_66 ;
V_107 = & V_106 -> V_1 ;
V_28 = & V_35 -> V_38 ;
V_98 = V_107 -> V_21 - V_107 -> V_5 ;
if ( V_43 ) {
struct V_108 * V_72 ;
int V_45 = V_74 -> V_45 ;
V_72 = F_56 ( V_43 -> V_72 , V_45 ) ;
V_72 -> V_3 = V_28 -> V_3 - 1 ;
if ( V_28 -> V_3 < V_11 )
V_72 -> V_109 [ V_28 -> V_3 ] = 0 ;
}
V_1 = F_66 ( V_98 , V_56 , V_25 ) ;
if ( V_1 == V_58 )
return V_58 ;
for ( V_66 = 0 ; V_66 < V_28 -> V_3 * V_110 ; V_66 ++ ) {
V_1 = F_49 ( V_56 , L_5 ) ;
if ( ! V_1 )
return V_58 ;
}
V_1 = F_49 ( V_56 , L_26 , ( void * ) V_28 -> V_2 ) ;
if ( ! V_1 )
return V_58 ;
return V_59 ;
}
static enum V_54
F_70 ( struct V_73 * V_74 ,
struct V_34 * V_35 ,
struct V_55 * V_56 , int V_45 , T_3 V_25 )
{
struct V_24 * V_28 = & V_35 -> V_38 ;
struct V_69 * V_43 = V_74 -> V_76 ;
int V_1 ;
int V_66 ;
if ( V_43 ) {
struct V_108 * V_72 ;
int V_45 = V_74 -> V_45 ;
V_72 = F_56 ( V_43 -> V_72 , V_45 ) ;
V_72 -> V_3 = V_28 -> V_3 ;
if ( V_28 -> V_3 < V_11 )
V_72 -> V_109 [ V_28 -> V_3 ] = V_28 -> V_2 ;
}
V_1 = F_66 ( V_104 , V_56 , V_25 ) ;
if ( V_1 != V_59 )
return V_1 ;
for ( V_66 = 0 ; V_66 < V_28 -> V_3 * V_110 ; V_66 ++ ) {
V_1 = F_49 ( V_56 , L_5 ) ;
if ( ! V_1 )
return V_58 ;
}
V_1 = F_49 ( V_56 , L_27 , ( void * ) V_28 -> V_2 ) ;
if ( ! V_1 )
return V_58 ;
return V_111 ;
}
static enum V_54
F_71 ( struct V_73 * V_74 , struct V_55 * V_56 ,
int type , unsigned long V_84 , T_3 V_25 )
{
struct V_69 * V_43 = V_74 -> V_76 ;
struct V_68 * V_49 = V_74 -> V_49 ;
int V_45 = V_74 -> V_45 ;
int V_1 ;
if ( F_55 ( V_56 , V_49 -> V_60 , V_45 , V_43 ) == V_58 )
return V_58 ;
if ( type ) {
V_1 = F_65 ( V_74 , V_84 , type , V_45 , V_49 -> V_60 , V_25 ) ;
if ( V_1 == V_58 )
return V_58 ;
}
if ( ! ( V_90 & V_91 ) )
return 0 ;
if ( V_25 & V_92 ) {
V_1 = F_63 ( V_74 -> V_93 , V_56 ) ;
if ( ! V_1 )
return V_58 ;
}
if ( V_25 & V_94 ) {
V_1 = F_48 ( V_56 , V_45 ) ;
if ( V_1 == V_58 )
return V_58 ;
}
if ( V_25 & V_95 ) {
V_1 = F_50 ( V_56 , V_49 -> V_60 ) ;
if ( V_1 == V_58 )
return V_58 ;
V_1 = F_49 ( V_56 , L_11 ) ;
if ( ! V_1 )
return V_58 ;
}
if ( V_90 & V_112 ) {
V_1 = F_52 ( V_56 , V_49 ) ;
if ( V_1 == V_58 )
return V_58 ;
}
return 0 ;
}
static int
F_72 ( struct V_73 * V_74 , T_3 V_25 ,
unsigned long V_84 , int V_3 )
{
int V_45 = V_74 -> V_45 ;
int * V_113 ;
struct V_69 * V_43 = V_74 -> V_76 ;
if ( ( V_25 & V_114 ) ||
( ! V_43 ) )
return 0 ;
V_113 = & ( F_56 ( V_43 -> V_72 , V_45 ) -> V_113 ) ;
if ( * V_113 >= 0 )
return 1 ;
if ( ( V_84 < ( unsigned long ) V_87 ) ||
( V_84 >= ( unsigned long ) V_88 ) )
return 0 ;
* V_113 = V_3 ;
return 1 ;
}
static int
F_73 ( struct V_73 * V_74 , T_3 V_25 , int V_3 )
{
int V_45 = V_74 -> V_45 ;
int * V_113 ;
struct V_69 * V_43 = V_74 -> V_76 ;
if ( ( V_25 & V_114 ) ||
( ! V_43 ) )
return 0 ;
V_113 = & ( F_56 ( V_43 -> V_72 , V_45 ) -> V_113 ) ;
if ( * V_113 == - 1 )
return 0 ;
if ( * V_113 >= V_3 ) {
* V_113 = - 1 ;
return 1 ;
}
return 1 ;
}
static enum V_54
F_74 ( struct V_34 * V_115 , struct V_55 * V_56 ,
struct V_73 * V_74 , T_3 V_25 )
{
struct V_69 * V_43 = V_74 -> V_76 ;
struct V_24 * V_28 = & V_115 -> V_38 ;
struct V_52 * V_116 ;
static enum V_54 V_1 ;
int V_45 = V_74 -> V_45 ;
if ( F_72 ( V_74 , V_25 , V_28 -> V_2 , V_28 -> V_3 ) )
return V_59 ;
if ( F_71 ( V_74 , V_56 , V_37 , V_28 -> V_2 , V_25 ) )
return V_58 ;
V_116 = F_57 ( V_74 , V_115 ) ;
if ( V_116 )
V_1 = F_69 ( V_74 , V_115 , V_116 , V_56 , V_25 ) ;
else
V_1 = F_70 ( V_74 , V_115 , V_56 , V_45 , V_25 ) ;
if ( V_43 ) {
if ( V_56 -> V_117 ) {
V_43 -> V_80 = 1 ;
V_43 -> V_45 = V_45 ;
} else
V_43 -> V_80 = 0 ;
}
return V_1 ;
}
static enum V_54
F_75 ( struct V_15 * V_16 , struct V_55 * V_56 ,
struct V_68 * V_49 , struct V_73 * V_74 ,
T_3 V_25 )
{
unsigned long long V_98 = V_16 -> V_21 - V_16 -> V_5 ;
struct V_69 * V_43 = V_74 -> V_76 ;
T_2 V_60 = V_49 -> V_60 ;
int V_45 = V_74 -> V_45 ;
int V_118 = 1 ;
int V_1 ;
int V_66 ;
if ( F_73 ( V_74 , V_25 , V_16 -> V_3 ) )
return V_59 ;
if ( V_43 ) {
struct V_108 * V_72 ;
int V_45 = V_74 -> V_45 ;
V_72 = F_56 ( V_43 -> V_72 , V_45 ) ;
V_72 -> V_3 = V_16 -> V_3 - 1 ;
if ( V_16 -> V_3 < V_11 ) {
if ( V_72 -> V_109 [ V_16 -> V_3 ] != V_16 -> V_2 )
V_118 = 0 ;
V_72 -> V_109 [ V_16 -> V_3 ] = 0 ;
}
}
if ( F_71 ( V_74 , V_56 , 0 , 0 , V_25 ) )
return V_58 ;
V_1 = F_66 ( V_98 , V_56 , V_25 ) ;
if ( V_1 == V_58 )
return V_58 ;
for ( V_66 = 0 ; V_66 < V_16 -> V_3 * V_110 ; V_66 ++ ) {
V_1 = F_49 ( V_56 , L_5 ) ;
if ( ! V_1 )
return V_58 ;
}
if ( V_118 ) {
V_1 = F_49 ( V_56 , L_28 ) ;
if ( ! V_1 )
return V_58 ;
} else {
V_1 = F_49 ( V_56 , L_29 , ( void * ) V_16 -> V_2 ) ;
if ( ! V_1 )
return V_58 ;
}
if ( V_25 & V_119 ) {
V_1 = F_49 ( V_56 , L_30 ,
V_16 -> V_20 ) ;
if ( ! V_1 )
return V_58 ;
}
V_1 = F_65 ( V_74 , V_16 -> V_2 , V_53 ,
V_45 , V_60 , V_25 ) ;
if ( V_1 == V_58 )
return V_58 ;
return V_59 ;
}
static enum V_54
F_76 ( struct V_55 * V_56 , struct V_68 * V_49 ,
struct V_73 * V_74 , T_3 V_25 )
{
unsigned long V_120 = ( V_90 & V_121 ) ;
struct V_69 * V_43 = V_74 -> V_76 ;
struct V_122 * V_31 ;
int V_3 = 0 ;
int V_1 ;
int V_66 ;
if ( V_43 )
V_3 = F_56 ( V_43 -> V_72 , V_74 -> V_45 ) -> V_3 ;
if ( F_71 ( V_74 , V_56 , 0 , 0 , V_25 ) )
return V_58 ;
V_1 = F_66 ( V_104 , V_56 , V_25 ) ;
if ( V_1 != V_59 )
return V_1 ;
if ( V_3 > 0 )
for ( V_66 = 0 ; V_66 < ( V_3 + 1 ) * V_110 ; V_66 ++ ) {
V_1 = F_49 ( V_56 , L_5 ) ;
if ( ! V_1 )
return V_58 ;
}
V_1 = F_49 ( V_56 , L_31 ) ;
if ( ! V_1 )
return V_58 ;
switch ( V_74 -> V_49 -> type ) {
case V_123 :
V_1 = F_77 ( V_74 ) ;
if ( V_1 != V_59 )
return V_1 ;
break;
case V_124 :
V_1 = F_78 ( V_74 ) ;
if ( V_1 != V_59 )
return V_1 ;
break;
default:
V_31 = F_79 ( V_49 -> type ) ;
if ( ! V_31 )
return V_89 ;
V_1 = V_31 -> V_125 -> V_16 ( V_74 , V_120 , V_31 ) ;
if ( V_1 != V_59 )
return V_1 ;
}
if ( V_56 -> V_33 [ V_56 -> V_65 - 1 ] == '\n' ) {
V_56 -> V_33 [ V_56 -> V_65 - 1 ] = '\0' ;
V_56 -> V_65 -- ;
}
V_1 = F_49 ( V_56 , L_32 ) ;
if ( ! V_1 )
return V_58 ;
return V_59 ;
}
enum V_54
F_80 ( struct V_73 * V_74 , T_3 V_25 )
{
struct V_34 * V_115 ;
struct V_69 * V_43 = V_74 -> V_76 ;
struct V_68 * V_35 = V_74 -> V_49 ;
struct V_55 * V_56 = & V_74 -> V_86 ;
int V_45 = V_74 -> V_45 ;
int V_1 ;
if ( V_43 && F_56 ( V_43 -> V_72 , V_45 ) -> V_126 ) {
F_56 ( V_43 -> V_72 , V_45 ) -> V_126 = 0 ;
return V_59 ;
}
if ( V_43 && V_43 -> V_80 ) {
V_115 = & V_43 -> V_49 ;
V_74 -> V_45 = V_43 -> V_45 ;
V_1 = F_74 ( V_115 , V_56 , V_74 , V_25 ) ;
if ( V_1 == V_59 && V_74 -> V_45 != V_45 ) {
F_56 ( V_43 -> V_72 , V_74 -> V_45 ) -> V_126 = 1 ;
V_1 = V_111 ;
}
V_74 -> V_45 = V_45 ;
return V_1 ;
}
switch ( V_35 -> type ) {
case V_37 : {
struct V_34 V_127 ;
F_81 ( V_115 , V_35 ) ;
V_127 = * V_115 ;
return F_74 ( & V_127 , V_56 , V_74 , V_25 ) ;
}
case V_53 : {
struct V_52 * V_115 ;
F_81 ( V_115 , V_35 ) ;
return F_75 ( & V_115 -> V_1 , V_56 , V_35 , V_74 , V_25 ) ;
}
case V_128 :
case V_129 :
return V_89 ;
default:
return F_76 ( V_56 , V_35 , V_74 , V_25 ) ;
}
return V_59 ;
}
static enum V_54
F_82 ( struct V_73 * V_74 )
{
return F_80 ( V_74 , V_130 . V_131 ) ;
}
static enum V_54
F_83 ( struct V_73 * V_74 , int V_25 ,
struct V_122 * V_31 )
{
return F_82 ( V_74 ) ;
}
static void F_84 ( struct V_132 * V_56 , T_3 V_25 )
{
static const char V_64 [] = L_33
L_34
L_35 ;
int V_133 = 0 ;
if ( V_25 & V_92 )
V_133 += 16 ;
if ( V_25 & V_94 )
V_133 += 4 ;
if ( V_25 & V_95 )
V_133 += 17 ;
F_85 ( V_56 , L_36 , V_133 , V_64 ) ;
F_85 ( V_56 , L_37 , V_133 , V_64 ) ;
F_85 ( V_56 , L_38 , V_133 , V_64 ) ;
F_85 ( V_56 , L_39 , V_133 , V_64 ) ;
F_85 ( V_56 , L_40 , V_133 , V_64 ) ;
}
static void F_86 ( struct V_132 * V_56 , T_3 V_25 )
{
int V_134 = V_90 & V_112 ;
if ( V_134 )
F_84 ( V_56 , V_25 ) ;
F_85 ( V_56 , L_41 ) ;
if ( V_25 & V_92 )
F_85 ( V_56 , L_42 ) ;
if ( V_25 & V_94 )
F_85 ( V_56 , L_43 ) ;
if ( V_25 & V_95 )
F_85 ( V_56 , L_44 ) ;
if ( V_134 )
F_85 ( V_56 , L_45 ) ;
if ( V_25 & V_103 )
F_85 ( V_56 , L_46 ) ;
F_85 ( V_56 , L_47 ) ;
F_85 ( V_56 , L_41 ) ;
if ( V_25 & V_92 )
F_85 ( V_56 , L_48 ) ;
if ( V_25 & V_94 )
F_85 ( V_56 , L_49 ) ;
if ( V_25 & V_95 )
F_85 ( V_56 , L_50 ) ;
if ( V_134 )
F_85 ( V_56 , L_45 ) ;
if ( V_25 & V_103 )
F_85 ( V_56 , L_51 ) ;
F_85 ( V_56 , L_52 ) ;
}
void F_87 ( struct V_132 * V_56 )
{
F_88 ( V_56 , V_130 . V_131 ) ;
}
void F_88 ( struct V_132 * V_56 , T_3 V_25 )
{
struct V_73 * V_74 = V_56 -> V_76 ;
if ( ! ( V_90 & V_91 ) )
return;
if ( V_90 & V_112 ) {
if ( F_89 ( V_74 ) )
return;
F_90 ( V_56 , V_74 ) ;
}
F_86 ( V_56 , V_25 ) ;
}
void F_91 ( struct V_73 * V_74 )
{
struct V_69 * V_43 ;
int V_45 ;
V_74 -> V_76 = NULL ;
V_43 = F_92 ( sizeof( * V_43 ) , V_135 ) ;
if ( ! V_43 )
goto V_136;
V_43 -> V_72 = F_93 ( struct V_108 ) ;
if ( ! V_43 -> V_72 )
goto V_137;
F_94 (cpu) {
T_2 * V_60 = & ( F_56 ( V_43 -> V_72 , V_45 ) -> V_71 ) ;
int * V_3 = & ( F_56 ( V_43 -> V_72 , V_45 ) -> V_3 ) ;
int * V_126 = & ( F_56 ( V_43 -> V_72 , V_45 ) -> V_126 ) ;
int * V_113 = & ( F_56 ( V_43 -> V_72 , V_45 ) -> V_113 ) ;
* V_60 = - 1 ;
* V_3 = 0 ;
* V_126 = 0 ;
* V_113 = - 1 ;
}
V_74 -> V_76 = V_43 ;
return;
V_137:
F_95 ( V_43 ) ;
V_136:
F_96 ( L_53 ) ;
}
void F_97 ( struct V_73 * V_74 )
{
struct V_69 * V_43 = V_74 -> V_76 ;
if ( V_43 ) {
F_98 ( V_43 -> V_72 ) ;
F_95 ( V_43 ) ;
}
}
static int F_99 ( T_3 V_138 , T_3 V_139 , int V_140 )
{
if ( V_139 == V_114 )
V_39 = ! V_140 ;
return 0 ;
}
static T_5
F_100 ( struct V_141 * V_142 , const char T_6 * V_143 , T_4 V_144 ,
T_7 * V_145 )
{
unsigned long V_131 ;
int V_1 ;
V_1 = F_101 ( V_143 , V_144 , 10 , & V_131 ) ;
if ( V_1 )
return V_1 ;
V_46 = V_131 ;
* V_145 += V_144 ;
return V_144 ;
}
static T_5
F_102 ( struct V_141 * V_142 , char T_6 * V_143 , T_4 V_144 ,
T_7 * V_145 )
{
char V_146 [ 15 ] ;
int V_147 ;
V_147 = sprintf ( V_146 , L_54 , V_46 ) ;
return F_103 ( V_143 , V_144 , V_145 , V_146 , V_147 ) ;
}
static T_8 int F_104 ( void )
{
struct V_148 * V_149 ;
V_149 = F_105 () ;
if ( ! V_149 )
return 0 ;
F_106 ( L_55 , 0644 , V_149 ,
NULL , & V_150 ) ;
return 0 ;
}
static T_8 int F_107 ( void )
{
V_57 = snprintf ( NULL , 0 , L_4 , V_151 - 1 ) ;
if ( ! F_108 ( & V_152 ) ) {
F_96 ( L_56 ) ;
return 1 ;
}
if ( ! F_108 ( & V_153 ) ) {
F_96 ( L_56 ) ;
return 1 ;
}
return F_109 ( & V_154 ) ;
}
