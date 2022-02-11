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
if ( ! ( V_16 -> V_3 || F_26 ( V_16 -> V_2 ) ) ||
F_21 () )
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
if ( V_46 )
return 1 ;
else
return F_24 ( V_16 ) ;
}
static void
F_35 ( struct V_22 * V_23 ,
unsigned long V_47 , unsigned long V_25 , int V_26 )
{
T_1 time = F_4 () ;
struct V_24 V_48 = {
. V_2 = V_47 ,
. V_3 = 0 ,
} ;
struct V_15 V_1 = {
. V_2 = V_47 ,
. V_3 = 0 ,
. V_5 = time ,
. V_21 = time ,
} ;
F_15 ( V_23 , & V_48 , V_25 , V_26 ) ;
F_36 ( V_23 , & V_1 , V_25 , V_26 ) ;
}
void
F_37 ( struct V_22 * V_23 ,
unsigned long V_47 , unsigned long V_49 ,
unsigned long V_25 , int V_26 )
{
F_35 ( V_23 , V_47 , V_25 , V_26 ) ;
}
void F_36 ( struct V_22 * V_23 ,
struct V_15 * V_16 ,
unsigned long V_25 ,
int V_26 )
{
struct V_27 * V_28 = & V_50 ;
struct V_30 * V_31 ;
struct V_32 * V_33 = V_23 -> V_33 ;
struct V_51 * V_35 ;
if ( F_7 ( F_16 ( V_36 ) ) )
return;
V_31 = F_17 ( V_33 , V_52 ,
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
if ( V_46 &&
( V_16 -> V_21 - V_16 -> V_5 < V_46 ) )
return;
else
F_38 ( V_16 ) ;
}
static int F_42 ( struct V_22 * V_23 )
{
int V_1 ;
F_39 ( V_23 ) ;
if ( V_46 )
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
static enum V_53
F_48 ( struct V_54 * V_55 , int V_45 )
{
int V_1 ;
V_1 = F_49 ( V_55 , L_3 , V_56 , V_45 ) ;
if ( ! V_1 )
return V_57 ;
return V_58 ;
}
static enum V_53
F_50 ( struct V_54 * V_55 , T_2 V_59 )
{
char V_60 [ V_61 ] ;
char V_62 [ 11 ] ;
int V_63 = 0 ;
int V_1 ;
int V_64 ;
int V_65 ;
F_51 ( V_59 , V_60 ) ;
V_60 [ 7 ] = '\0' ;
sprintf ( V_62 , L_4 , V_59 ) ;
V_64 = strlen ( V_60 ) + strlen ( V_62 ) + 1 ;
if ( V_64 < V_66 )
V_63 = V_66 - V_64 ;
for ( V_65 = 0 ; V_65 < V_63 / 2 ; V_65 ++ ) {
V_1 = F_49 ( V_55 , L_5 ) ;
if ( ! V_1 )
return V_57 ;
}
V_1 = F_49 ( V_55 , L_6 , V_60 , V_62 ) ;
if ( ! V_1 )
return V_57 ;
for ( V_65 = 0 ; V_65 < V_63 - ( V_63 / 2 ) ; V_65 ++ ) {
V_1 = F_49 ( V_55 , L_5 ) ;
if ( ! V_1 )
return V_57 ;
}
return V_58 ;
}
static enum V_53
F_52 ( struct V_54 * V_55 , struct V_67 * V_35 )
{
if ( ! F_53 ( V_55 , ' ' ) )
return 0 ;
return F_54 ( V_55 , V_35 ) ;
}
static enum V_53
F_55 ( struct V_54 * V_55 , T_2 V_59 , int V_45 , struct V_68 * V_43 )
{
T_2 V_69 ;
T_2 * V_70 ;
int V_1 ;
if ( ! V_43 )
return V_58 ;
V_70 = & ( F_56 ( V_43 -> V_71 , V_45 ) -> V_70 ) ;
if ( * V_70 == V_59 )
return V_58 ;
V_69 = * V_70 ;
* V_70 = V_59 ;
if ( V_69 == - 1 )
return V_58 ;
V_1 = F_49 ( V_55 ,
L_7 ) ;
if ( ! V_1 )
return V_57 ;
V_1 = F_48 ( V_55 , V_45 ) ;
if ( V_1 == V_57 )
return V_57 ;
V_1 = F_50 ( V_55 , V_69 ) ;
if ( V_1 == V_57 )
return V_57 ;
V_1 = F_49 ( V_55 , L_8 ) ;
if ( ! V_1 )
return V_57 ;
V_1 = F_50 ( V_55 , V_59 ) ;
if ( V_1 == V_57 )
return V_57 ;
V_1 = F_49 ( V_55 ,
L_9 ) ;
if ( ! V_1 )
return V_57 ;
return V_58 ;
}
static struct V_51 *
F_57 ( struct V_72 * V_73 ,
struct V_34 * V_74 )
{
struct V_68 * V_43 = V_73 -> V_75 ;
struct V_76 * V_77 = NULL ;
struct V_30 * V_31 ;
struct V_51 * V_78 ;
if ( V_43 && V_43 -> V_79 ) {
V_74 = & V_43 -> V_48 ;
V_78 = & V_43 -> V_1 ;
} else {
V_77 = F_58 ( V_73 , V_73 -> V_45 ) ;
if ( V_77 )
V_31 = F_59 ( V_77 , NULL ) ;
else {
F_60 ( V_73 -> V_23 -> V_33 , V_73 -> V_45 ,
NULL , NULL ) ;
V_31 = F_61 ( V_73 -> V_23 -> V_33 , V_73 -> V_45 ,
NULL , NULL ) ;
}
if ( ! V_31 )
return NULL ;
V_78 = F_18 ( V_31 ) ;
if ( V_43 ) {
V_43 -> V_48 = * V_74 ;
if ( V_78 -> V_48 . type == V_52 )
V_43 -> V_1 = * V_78 ;
else
V_43 -> V_1 . V_48 . type = V_78 -> V_48 . type ;
}
}
if ( V_78 -> V_48 . type != V_52 )
return NULL ;
if ( V_74 -> V_48 . V_59 != V_78 -> V_48 . V_59 ||
V_74 -> V_38 . V_2 != V_78 -> V_1 . V_2 )
return NULL ;
if ( V_77 )
F_62 ( V_77 , NULL ) ;
return V_78 ;
}
static int F_63 ( T_1 V_80 , struct V_54 * V_55 )
{
unsigned long V_81 ;
V_81 = F_64 ( V_80 , V_82 ) ;
V_81 /= 1000 ;
return F_49 ( V_55 , L_10 ,
( unsigned long ) V_80 , V_81 ) ;
}
static enum V_53
F_65 ( struct V_72 * V_73 , unsigned long V_83 ,
enum V_84 type , int V_45 , T_2 V_59 , T_3 V_25 )
{
int V_1 ;
struct V_54 * V_55 = & V_73 -> V_85 ;
if ( V_83 < ( unsigned long ) V_86 ||
V_83 >= ( unsigned long ) V_87 )
return V_88 ;
if ( V_89 & V_90 ) {
if ( V_25 & V_91 ) {
V_1 = F_63 ( V_73 -> V_92 , V_55 ) ;
if ( ! V_1 )
return V_57 ;
}
if ( V_25 & V_93 ) {
V_1 = F_48 ( V_55 , V_45 ) ;
if ( V_1 == V_57 )
return V_57 ;
}
if ( V_25 & V_94 ) {
V_1 = F_50 ( V_55 , V_59 ) ;
if ( V_1 == V_57 )
return V_57 ;
V_1 = F_49 ( V_55 , L_11 ) ;
if ( ! V_1 )
return V_57 ;
}
}
V_1 = F_66 ( V_95 , V_55 , V_25 ) ;
if ( V_1 != V_58 )
return V_1 ;
if ( type == V_37 )
V_1 = F_49 ( V_55 , L_12 ) ;
else
V_1 = F_49 ( V_55 , L_13 ) ;
if ( ! V_1 )
return V_57 ;
V_1 = F_66 ( V_96 , V_55 , V_25 ) ;
if ( V_1 != V_58 )
return V_1 ;
V_1 = F_49 ( V_55 , L_14 ) ;
if ( ! V_1 )
return V_57 ;
return V_58 ;
}
enum V_53
F_67 ( unsigned long long V_97 , struct V_54 * V_55 )
{
unsigned long V_98 = F_64 ( V_97 , 1000 ) ;
char V_99 [ 21 ] ;
char V_100 [ 5 ] ;
int V_1 , V_64 ;
int V_65 ;
sprintf ( V_99 , L_15 , ( unsigned long ) V_97 ) ;
V_1 = F_49 ( V_55 , L_16 , V_99 ) ;
if ( ! V_1 )
return V_57 ;
V_64 = strlen ( V_99 ) ;
if ( V_64 < 7 ) {
T_4 V_101 = F_68 ( T_4 , sizeof( V_100 ) , 8UL - V_64 ) ;
snprintf ( V_100 , V_101 , L_17 , V_98 ) ;
V_1 = F_49 ( V_55 , L_18 , V_100 ) ;
if ( ! V_1 )
return V_57 ;
V_64 += strlen ( V_100 ) ;
}
V_1 = F_49 ( V_55 , L_19 ) ;
if ( ! V_1 )
return V_57 ;
for ( V_65 = V_64 ; V_65 < 7 ; V_65 ++ ) {
V_1 = F_49 ( V_55 , L_5 ) ;
if ( ! V_1 )
return V_57 ;
}
return V_58 ;
}
static enum V_53
F_66 ( unsigned long long V_97 , struct V_54 * V_55 ,
T_3 V_25 )
{
int V_1 = - 1 ;
if ( ! ( V_25 & V_102 ) ||
! ( V_89 & V_90 ) )
return V_58 ;
switch ( V_97 ) {
case V_103 :
V_1 = F_49 ( V_55 , L_20 ) ;
return V_1 ? V_58 : V_57 ;
case V_95 :
V_1 = F_49 ( V_55 , L_21 ) ;
return V_1 ? V_58 : V_57 ;
case V_96 :
V_1 = F_49 ( V_55 , L_22 ) ;
return V_1 ? V_58 : V_57 ;
}
if ( V_25 & V_104 ) {
if ( V_97 > 100000ULL )
V_1 = F_49 ( V_55 , L_23 ) ;
else if ( V_97 > 10000ULL )
V_1 = F_49 ( V_55 , L_24 ) ;
}
if ( V_1 == - 1 )
V_1 = F_49 ( V_55 , L_21 ) ;
if ( ! V_1 )
return V_57 ;
V_1 = F_67 ( V_97 , V_55 ) ;
if ( V_1 != V_58 )
return V_1 ;
V_1 = F_49 ( V_55 , L_25 ) ;
if ( ! V_1 )
return V_57 ;
return V_58 ;
}
static enum V_53
F_69 ( struct V_72 * V_73 ,
struct V_34 * V_35 ,
struct V_51 * V_105 ,
struct V_54 * V_55 , T_3 V_25 )
{
struct V_68 * V_43 = V_73 -> V_75 ;
struct V_15 * V_106 ;
struct V_24 * V_28 ;
unsigned long long V_97 ;
int V_1 ;
int V_65 ;
V_106 = & V_105 -> V_1 ;
V_28 = & V_35 -> V_38 ;
V_97 = V_106 -> V_21 - V_106 -> V_5 ;
if ( V_43 ) {
struct V_107 * V_71 ;
int V_45 = V_73 -> V_45 ;
V_71 = F_56 ( V_43 -> V_71 , V_45 ) ;
V_71 -> V_3 = V_28 -> V_3 - 1 ;
if ( V_28 -> V_3 < V_11 )
V_71 -> V_108 [ V_28 -> V_3 ] = 0 ;
}
V_1 = F_66 ( V_97 , V_55 , V_25 ) ;
if ( V_1 == V_57 )
return V_57 ;
for ( V_65 = 0 ; V_65 < V_28 -> V_3 * V_109 ; V_65 ++ ) {
V_1 = F_49 ( V_55 , L_5 ) ;
if ( ! V_1 )
return V_57 ;
}
V_1 = F_49 ( V_55 , L_26 , ( void * ) V_28 -> V_2 ) ;
if ( ! V_1 )
return V_57 ;
return V_58 ;
}
static enum V_53
F_70 ( struct V_72 * V_73 ,
struct V_34 * V_35 ,
struct V_54 * V_55 , int V_45 , T_3 V_25 )
{
struct V_24 * V_28 = & V_35 -> V_38 ;
struct V_68 * V_43 = V_73 -> V_75 ;
int V_1 ;
int V_65 ;
if ( V_43 ) {
struct V_107 * V_71 ;
int V_45 = V_73 -> V_45 ;
V_71 = F_56 ( V_43 -> V_71 , V_45 ) ;
V_71 -> V_3 = V_28 -> V_3 ;
if ( V_28 -> V_3 < V_11 )
V_71 -> V_108 [ V_28 -> V_3 ] = V_28 -> V_2 ;
}
V_1 = F_66 ( V_103 , V_55 , V_25 ) ;
if ( V_1 != V_58 )
return V_1 ;
for ( V_65 = 0 ; V_65 < V_28 -> V_3 * V_109 ; V_65 ++ ) {
V_1 = F_49 ( V_55 , L_5 ) ;
if ( ! V_1 )
return V_57 ;
}
V_1 = F_49 ( V_55 , L_27 , ( void * ) V_28 -> V_2 ) ;
if ( ! V_1 )
return V_57 ;
return V_110 ;
}
static enum V_53
F_71 ( struct V_72 * V_73 , struct V_54 * V_55 ,
int type , unsigned long V_83 , T_3 V_25 )
{
struct V_68 * V_43 = V_73 -> V_75 ;
struct V_67 * V_48 = V_73 -> V_48 ;
int V_45 = V_73 -> V_45 ;
int V_1 ;
if ( F_55 ( V_55 , V_48 -> V_59 , V_45 , V_43 ) == V_57 )
return V_57 ;
if ( type ) {
V_1 = F_65 ( V_73 , V_83 , type , V_45 , V_48 -> V_59 , V_25 ) ;
if ( V_1 == V_57 )
return V_57 ;
}
if ( ! ( V_89 & V_90 ) )
return 0 ;
if ( V_25 & V_91 ) {
V_1 = F_63 ( V_73 -> V_92 , V_55 ) ;
if ( ! V_1 )
return V_57 ;
}
if ( V_25 & V_93 ) {
V_1 = F_48 ( V_55 , V_45 ) ;
if ( V_1 == V_57 )
return V_57 ;
}
if ( V_25 & V_94 ) {
V_1 = F_50 ( V_55 , V_48 -> V_59 ) ;
if ( V_1 == V_57 )
return V_57 ;
V_1 = F_49 ( V_55 , L_11 ) ;
if ( ! V_1 )
return V_57 ;
}
if ( V_89 & V_111 ) {
V_1 = F_52 ( V_55 , V_48 ) ;
if ( V_1 == V_57 )
return V_57 ;
}
return 0 ;
}
static int
F_72 ( struct V_72 * V_73 , T_3 V_25 ,
unsigned long V_83 , int V_3 )
{
int V_45 = V_73 -> V_45 ;
int * V_112 ;
struct V_68 * V_43 = V_73 -> V_75 ;
if ( ( V_25 & V_113 ) ||
( ! V_43 ) )
return 0 ;
V_112 = & ( F_56 ( V_43 -> V_71 , V_45 ) -> V_112 ) ;
if ( * V_112 >= 0 )
return 1 ;
if ( ( V_83 < ( unsigned long ) V_86 ) ||
( V_83 >= ( unsigned long ) V_87 ) )
return 0 ;
* V_112 = V_3 ;
return 1 ;
}
static int
F_73 ( struct V_72 * V_73 , T_3 V_25 , int V_3 )
{
int V_45 = V_73 -> V_45 ;
int * V_112 ;
struct V_68 * V_43 = V_73 -> V_75 ;
if ( ( V_25 & V_113 ) ||
( ! V_43 ) )
return 0 ;
V_112 = & ( F_56 ( V_43 -> V_71 , V_45 ) -> V_112 ) ;
if ( * V_112 == - 1 )
return 0 ;
if ( * V_112 >= V_3 ) {
* V_112 = - 1 ;
return 1 ;
}
return 1 ;
}
static enum V_53
F_74 ( struct V_34 * V_114 , struct V_54 * V_55 ,
struct V_72 * V_73 , T_3 V_25 )
{
struct V_68 * V_43 = V_73 -> V_75 ;
struct V_24 * V_28 = & V_114 -> V_38 ;
struct V_51 * V_115 ;
static enum V_53 V_1 ;
int V_45 = V_73 -> V_45 ;
if ( F_72 ( V_73 , V_25 , V_28 -> V_2 , V_28 -> V_3 ) )
return V_58 ;
if ( F_71 ( V_73 , V_55 , V_37 , V_28 -> V_2 , V_25 ) )
return V_57 ;
V_115 = F_57 ( V_73 , V_114 ) ;
if ( V_115 )
V_1 = F_69 ( V_73 , V_114 , V_115 , V_55 , V_25 ) ;
else
V_1 = F_70 ( V_73 , V_114 , V_55 , V_45 , V_25 ) ;
if ( V_43 ) {
if ( V_55 -> V_116 ) {
V_43 -> V_79 = 1 ;
V_43 -> V_45 = V_45 ;
} else
V_43 -> V_79 = 0 ;
}
return V_1 ;
}
static enum V_53
F_75 ( struct V_15 * V_16 , struct V_54 * V_55 ,
struct V_67 * V_48 , struct V_72 * V_73 ,
T_3 V_25 )
{
unsigned long long V_97 = V_16 -> V_21 - V_16 -> V_5 ;
struct V_68 * V_43 = V_73 -> V_75 ;
T_2 V_59 = V_48 -> V_59 ;
int V_45 = V_73 -> V_45 ;
int V_117 = 1 ;
int V_1 ;
int V_65 ;
if ( F_73 ( V_73 , V_25 , V_16 -> V_3 ) )
return V_58 ;
if ( V_43 ) {
struct V_107 * V_71 ;
int V_45 = V_73 -> V_45 ;
V_71 = F_56 ( V_43 -> V_71 , V_45 ) ;
V_71 -> V_3 = V_16 -> V_3 - 1 ;
if ( V_16 -> V_3 < V_11 ) {
if ( V_71 -> V_108 [ V_16 -> V_3 ] != V_16 -> V_2 )
V_117 = 0 ;
V_71 -> V_108 [ V_16 -> V_3 ] = 0 ;
}
}
if ( F_71 ( V_73 , V_55 , 0 , 0 , V_25 ) )
return V_57 ;
V_1 = F_66 ( V_97 , V_55 , V_25 ) ;
if ( V_1 == V_57 )
return V_57 ;
for ( V_65 = 0 ; V_65 < V_16 -> V_3 * V_109 ; V_65 ++ ) {
V_1 = F_49 ( V_55 , L_5 ) ;
if ( ! V_1 )
return V_57 ;
}
if ( V_117 ) {
V_1 = F_49 ( V_55 , L_28 ) ;
if ( ! V_1 )
return V_57 ;
} else {
V_1 = F_49 ( V_55 , L_29 , ( void * ) V_16 -> V_2 ) ;
if ( ! V_1 )
return V_57 ;
}
if ( V_25 & V_118 ) {
V_1 = F_49 ( V_55 , L_30 ,
V_16 -> V_20 ) ;
if ( ! V_1 )
return V_57 ;
}
V_1 = F_65 ( V_73 , V_16 -> V_2 , V_52 ,
V_45 , V_59 , V_25 ) ;
if ( V_1 == V_57 )
return V_57 ;
return V_58 ;
}
static enum V_53
F_76 ( struct V_54 * V_55 , struct V_67 * V_48 ,
struct V_72 * V_73 , T_3 V_25 )
{
unsigned long V_119 = ( V_89 & V_120 ) ;
struct V_68 * V_43 = V_73 -> V_75 ;
struct V_121 * V_31 ;
int V_3 = 0 ;
int V_1 ;
int V_65 ;
if ( V_43 )
V_3 = F_56 ( V_43 -> V_71 , V_73 -> V_45 ) -> V_3 ;
if ( F_71 ( V_73 , V_55 , 0 , 0 , V_25 ) )
return V_57 ;
V_1 = F_66 ( V_103 , V_55 , V_25 ) ;
if ( V_1 != V_58 )
return V_1 ;
if ( V_3 > 0 )
for ( V_65 = 0 ; V_65 < ( V_3 + 1 ) * V_109 ; V_65 ++ ) {
V_1 = F_49 ( V_55 , L_5 ) ;
if ( ! V_1 )
return V_57 ;
}
V_1 = F_49 ( V_55 , L_31 ) ;
if ( ! V_1 )
return V_57 ;
switch ( V_73 -> V_48 -> type ) {
case V_122 :
V_1 = F_77 ( V_73 ) ;
if ( V_1 != V_58 )
return V_1 ;
break;
case V_123 :
V_1 = F_78 ( V_73 ) ;
if ( V_1 != V_58 )
return V_1 ;
break;
default:
V_31 = F_79 ( V_48 -> type ) ;
if ( ! V_31 )
return V_88 ;
V_1 = V_31 -> V_124 -> V_16 ( V_73 , V_119 , V_31 ) ;
if ( V_1 != V_58 )
return V_1 ;
}
if ( V_55 -> V_33 [ V_55 -> V_64 - 1 ] == '\n' ) {
V_55 -> V_33 [ V_55 -> V_64 - 1 ] = '\0' ;
V_55 -> V_64 -- ;
}
V_1 = F_49 ( V_55 , L_32 ) ;
if ( ! V_1 )
return V_57 ;
return V_58 ;
}
enum V_53
F_80 ( struct V_72 * V_73 , T_3 V_25 )
{
struct V_34 * V_114 ;
struct V_68 * V_43 = V_73 -> V_75 ;
struct V_67 * V_35 = V_73 -> V_48 ;
struct V_54 * V_55 = & V_73 -> V_85 ;
int V_45 = V_73 -> V_45 ;
int V_1 ;
if ( V_43 && F_56 ( V_43 -> V_71 , V_45 ) -> V_125 ) {
F_56 ( V_43 -> V_71 , V_45 ) -> V_125 = 0 ;
return V_58 ;
}
if ( V_43 && V_43 -> V_79 ) {
V_114 = & V_43 -> V_48 ;
V_73 -> V_45 = V_43 -> V_45 ;
V_1 = F_74 ( V_114 , V_55 , V_73 , V_25 ) ;
if ( V_1 == V_58 && V_73 -> V_45 != V_45 ) {
F_56 ( V_43 -> V_71 , V_73 -> V_45 ) -> V_125 = 1 ;
V_1 = V_110 ;
}
V_73 -> V_45 = V_45 ;
return V_1 ;
}
switch ( V_35 -> type ) {
case V_37 : {
struct V_34 V_126 ;
F_81 ( V_114 , V_35 ) ;
V_126 = * V_114 ;
return F_74 ( & V_126 , V_55 , V_73 , V_25 ) ;
}
case V_52 : {
struct V_51 * V_114 ;
F_81 ( V_114 , V_35 ) ;
return F_75 ( & V_114 -> V_1 , V_55 , V_35 , V_73 , V_25 ) ;
}
case V_127 :
case V_128 :
return V_88 ;
default:
return F_76 ( V_55 , V_35 , V_73 , V_25 ) ;
}
return V_58 ;
}
static enum V_53
F_82 ( struct V_72 * V_73 )
{
return F_80 ( V_73 , V_129 . V_130 ) ;
}
static enum V_53
F_83 ( struct V_72 * V_73 , int V_25 ,
struct V_121 * V_31 )
{
return F_82 ( V_73 ) ;
}
static void F_84 ( struct V_131 * V_55 , T_3 V_25 )
{
static const char V_63 [] = L_33
L_34
L_35 ;
int V_132 = 0 ;
if ( V_25 & V_91 )
V_132 += 16 ;
if ( V_25 & V_93 )
V_132 += 4 ;
if ( V_25 & V_94 )
V_132 += 17 ;
F_85 ( V_55 , L_36 , V_132 , V_63 ) ;
F_85 ( V_55 , L_37 , V_132 , V_63 ) ;
F_85 ( V_55 , L_38 , V_132 , V_63 ) ;
F_85 ( V_55 , L_39 , V_132 , V_63 ) ;
F_85 ( V_55 , L_40 , V_132 , V_63 ) ;
}
static void F_86 ( struct V_131 * V_55 , T_3 V_25 )
{
int V_133 = V_89 & V_111 ;
if ( V_133 )
F_84 ( V_55 , V_25 ) ;
F_85 ( V_55 , L_41 ) ;
if ( V_25 & V_91 )
F_85 ( V_55 , L_42 ) ;
if ( V_25 & V_93 )
F_85 ( V_55 , L_43 ) ;
if ( V_25 & V_94 )
F_85 ( V_55 , L_44 ) ;
if ( V_133 )
F_85 ( V_55 , L_45 ) ;
if ( V_25 & V_102 )
F_85 ( V_55 , L_46 ) ;
F_85 ( V_55 , L_47 ) ;
F_85 ( V_55 , L_41 ) ;
if ( V_25 & V_91 )
F_85 ( V_55 , L_48 ) ;
if ( V_25 & V_93 )
F_85 ( V_55 , L_49 ) ;
if ( V_25 & V_94 )
F_85 ( V_55 , L_50 ) ;
if ( V_133 )
F_85 ( V_55 , L_45 ) ;
if ( V_25 & V_102 )
F_85 ( V_55 , L_51 ) ;
F_85 ( V_55 , L_52 ) ;
}
void F_87 ( struct V_131 * V_55 )
{
F_88 ( V_55 , V_129 . V_130 ) ;
}
void F_88 ( struct V_131 * V_55 , T_3 V_25 )
{
struct V_72 * V_73 = V_55 -> V_75 ;
if ( ! ( V_89 & V_90 ) )
return;
if ( V_89 & V_111 ) {
if ( F_89 ( V_73 ) )
return;
F_90 ( V_55 , V_73 ) ;
}
F_86 ( V_55 , V_25 ) ;
}
void F_91 ( struct V_72 * V_73 )
{
struct V_68 * V_43 ;
int V_45 ;
V_73 -> V_75 = NULL ;
V_43 = F_92 ( sizeof( * V_43 ) , V_134 ) ;
if ( ! V_43 )
goto V_135;
V_43 -> V_71 = F_93 ( struct V_107 ) ;
if ( ! V_43 -> V_71 )
goto V_136;
F_94 (cpu) {
T_2 * V_59 = & ( F_56 ( V_43 -> V_71 , V_45 ) -> V_70 ) ;
int * V_3 = & ( F_56 ( V_43 -> V_71 , V_45 ) -> V_3 ) ;
int * V_125 = & ( F_56 ( V_43 -> V_71 , V_45 ) -> V_125 ) ;
int * V_112 = & ( F_56 ( V_43 -> V_71 , V_45 ) -> V_112 ) ;
* V_59 = - 1 ;
* V_3 = 0 ;
* V_125 = 0 ;
* V_112 = - 1 ;
}
V_73 -> V_75 = V_43 ;
return;
V_136:
F_95 ( V_43 ) ;
V_135:
F_96 ( L_53 ) ;
}
void F_97 ( struct V_72 * V_73 )
{
struct V_68 * V_43 = V_73 -> V_75 ;
if ( V_43 ) {
F_98 ( V_43 -> V_71 ) ;
F_95 ( V_43 ) ;
}
}
static int F_99 ( T_3 V_137 , T_3 V_138 , int V_139 )
{
if ( V_138 == V_113 )
V_39 = ! V_139 ;
return 0 ;
}
static T_5 int F_100 ( void )
{
V_56 = snprintf ( NULL , 0 , L_4 , V_140 - 1 ) ;
if ( ! F_101 ( & V_141 ) ) {
F_96 ( L_54 ) ;
return 1 ;
}
if ( ! F_101 ( & V_142 ) ) {
F_96 ( L_54 ) ;
return 1 ;
}
return F_102 ( & V_143 ) ;
}
