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
struct V_32 * V_33 = V_23 -> V_34 . V_33 ;
struct V_35 * V_36 ;
if ( F_7 ( F_16 ( V_37 ) ) )
return 0 ;
V_31 = F_17 ( V_33 , V_38 ,
sizeof( * V_36 ) , V_25 , V_26 ) ;
if ( ! V_31 )
return 0 ;
V_36 = F_18 ( V_31 ) ;
V_36 -> V_39 = * V_16 ;
if ( ! F_19 ( V_33 , V_28 , V_36 , V_31 ) )
F_20 ( V_33 , V_31 ) ;
return 1 ;
}
static inline int F_21 ( void )
{
if ( ! V_40 || F_22 ( V_41 ) )
return 0 ;
return F_23 () ;
}
int F_24 ( struct V_24 * V_16 )
{
struct V_22 * V_23 = V_42 ;
struct V_43 * V_44 ;
unsigned long V_25 ;
long V_45 ;
int V_1 ;
int V_46 ;
int V_26 ;
if ( ! F_25 ( V_7 ) )
return 0 ;
if ( ( ! ( V_16 -> V_3 || F_26 ( V_16 -> V_2 ) ) ||
F_21 () ) ||
( V_47 && V_16 -> V_3 >= V_47 ) )
return 0 ;
F_27 ( V_25 ) ;
V_46 = F_28 () ;
V_44 = F_29 ( V_23 -> V_34 . V_44 , V_46 ) ;
V_45 = F_30 ( & V_44 -> V_45 ) ;
if ( F_31 ( V_45 == 1 ) ) {
V_26 = F_32 () ;
V_1 = F_15 ( V_23 , V_16 , V_25 , V_26 ) ;
} else {
V_1 = 0 ;
}
F_33 ( & V_44 -> V_45 ) ;
F_34 ( V_25 ) ;
return V_1 ;
}
int F_35 ( struct V_24 * V_16 )
{
if ( V_48 )
return 1 ;
else
return F_24 ( V_16 ) ;
}
static void
F_36 ( struct V_22 * V_23 ,
unsigned long V_49 , unsigned long V_25 , int V_26 )
{
T_1 time = F_4 () ;
struct V_24 V_50 = {
. V_2 = V_49 ,
. V_3 = 0 ,
} ;
struct V_15 V_1 = {
. V_2 = V_49 ,
. V_3 = 0 ,
. V_5 = time ,
. V_21 = time ,
} ;
F_15 ( V_23 , & V_50 , V_25 , V_26 ) ;
F_37 ( V_23 , & V_1 , V_25 , V_26 ) ;
}
void
F_38 ( struct V_22 * V_23 ,
unsigned long V_49 , unsigned long V_51 ,
unsigned long V_25 , int V_26 )
{
F_36 ( V_23 , V_49 , V_25 , V_26 ) ;
}
void F_37 ( struct V_22 * V_23 ,
struct V_15 * V_16 ,
unsigned long V_25 ,
int V_26 )
{
struct V_27 * V_28 = & V_52 ;
struct V_30 * V_31 ;
struct V_32 * V_33 = V_23 -> V_34 . V_33 ;
struct V_53 * V_36 ;
if ( F_7 ( F_16 ( V_37 ) ) )
return;
V_31 = F_17 ( V_33 , V_54 ,
sizeof( * V_36 ) , V_25 , V_26 ) ;
if ( ! V_31 )
return;
V_36 = F_18 ( V_31 ) ;
V_36 -> V_1 = * V_16 ;
if ( ! F_19 ( V_33 , V_28 , V_36 , V_31 ) )
F_20 ( V_33 , V_31 ) ;
}
void F_39 ( struct V_15 * V_16 )
{
struct V_22 * V_23 = V_42 ;
struct V_43 * V_44 ;
unsigned long V_25 ;
long V_45 ;
int V_46 ;
int V_26 ;
F_27 ( V_25 ) ;
V_46 = F_28 () ;
V_44 = F_29 ( V_23 -> V_34 . V_44 , V_46 ) ;
V_45 = F_30 ( & V_44 -> V_45 ) ;
if ( F_31 ( V_45 == 1 ) ) {
V_26 = F_32 () ;
F_37 ( V_23 , V_16 , V_25 , V_26 ) ;
}
F_33 ( & V_44 -> V_45 ) ;
F_34 ( V_25 ) ;
}
void F_40 ( struct V_22 * V_23 )
{
V_42 = V_23 ;
F_41 () ;
}
void F_42 ( struct V_15 * V_16 )
{
if ( V_48 &&
( V_16 -> V_21 - V_16 -> V_5 < V_48 ) )
return;
else
F_39 ( V_16 ) ;
}
static int F_43 ( struct V_22 * V_23 )
{
int V_1 ;
F_40 ( V_23 ) ;
if ( V_48 )
V_1 = F_44 ( & F_42 ,
& F_35 ) ;
else
V_1 = F_44 ( & F_39 ,
& F_24 ) ;
if ( V_1 )
return V_1 ;
F_45 () ;
return 0 ;
}
static void F_46 ( struct V_22 * V_23 )
{
F_47 () ;
F_48 () ;
}
static enum V_55
F_49 ( struct V_56 * V_57 , int V_46 )
{
int V_1 ;
V_1 = F_50 ( V_57 , L_3 , V_58 , V_46 ) ;
if ( ! V_1 )
return V_59 ;
return V_60 ;
}
static enum V_55
F_51 ( struct V_56 * V_57 , T_2 V_61 )
{
char V_62 [ V_63 ] ;
char V_64 [ 11 ] ;
int V_65 = 0 ;
int V_1 ;
int V_66 ;
int V_67 ;
F_52 ( V_61 , V_62 ) ;
V_62 [ 7 ] = '\0' ;
sprintf ( V_64 , L_4 , V_61 ) ;
V_66 = strlen ( V_62 ) + strlen ( V_64 ) + 1 ;
if ( V_66 < V_68 )
V_65 = V_68 - V_66 ;
for ( V_67 = 0 ; V_67 < V_65 / 2 ; V_67 ++ ) {
V_1 = F_50 ( V_57 , L_5 ) ;
if ( ! V_1 )
return V_59 ;
}
V_1 = F_50 ( V_57 , L_6 , V_62 , V_64 ) ;
if ( ! V_1 )
return V_59 ;
for ( V_67 = 0 ; V_67 < V_65 - ( V_65 / 2 ) ; V_67 ++ ) {
V_1 = F_50 ( V_57 , L_5 ) ;
if ( ! V_1 )
return V_59 ;
}
return V_60 ;
}
static enum V_55
F_53 ( struct V_56 * V_57 , struct V_69 * V_36 )
{
if ( ! F_54 ( V_57 , ' ' ) )
return 0 ;
return F_55 ( V_57 , V_36 ) ;
}
static enum V_55
F_56 ( struct V_56 * V_57 , T_2 V_61 , int V_46 , struct V_70 * V_44 )
{
T_2 V_71 ;
T_2 * V_72 ;
int V_1 ;
if ( ! V_44 )
return V_60 ;
V_72 = & ( F_29 ( V_44 -> V_73 , V_46 ) -> V_72 ) ;
if ( * V_72 == V_61 )
return V_60 ;
V_71 = * V_72 ;
* V_72 = V_61 ;
if ( V_71 == - 1 )
return V_60 ;
V_1 = F_50 ( V_57 ,
L_7 ) ;
if ( ! V_1 )
return V_59 ;
V_1 = F_49 ( V_57 , V_46 ) ;
if ( V_1 == V_59 )
return V_59 ;
V_1 = F_51 ( V_57 , V_71 ) ;
if ( V_1 == V_59 )
return V_59 ;
V_1 = F_50 ( V_57 , L_8 ) ;
if ( ! V_1 )
return V_59 ;
V_1 = F_51 ( V_57 , V_61 ) ;
if ( V_1 == V_59 )
return V_59 ;
V_1 = F_50 ( V_57 ,
L_9 ) ;
if ( ! V_1 )
return V_59 ;
return V_60 ;
}
static struct V_53 *
F_57 ( struct V_74 * V_75 ,
struct V_35 * V_76 )
{
struct V_70 * V_44 = V_75 -> V_77 ;
struct V_78 * V_79 = NULL ;
struct V_30 * V_31 ;
struct V_53 * V_80 ;
if ( V_44 && V_44 -> V_81 ) {
V_76 = & V_44 -> V_50 ;
V_80 = & V_44 -> V_1 ;
} else {
V_79 = F_58 ( V_75 , V_75 -> V_46 ) ;
if ( V_79 )
V_31 = F_59 ( V_79 , NULL ) ;
else {
F_60 ( V_75 -> V_34 -> V_33 , V_75 -> V_46 ,
NULL , NULL ) ;
V_31 = F_61 ( V_75 -> V_34 -> V_33 , V_75 -> V_46 ,
NULL , NULL ) ;
}
if ( ! V_31 )
return NULL ;
V_80 = F_18 ( V_31 ) ;
if ( V_44 ) {
V_44 -> V_50 = * V_76 ;
if ( V_80 -> V_50 . type == V_54 )
V_44 -> V_1 = * V_80 ;
else
V_44 -> V_1 . V_50 . type = V_80 -> V_50 . type ;
}
}
if ( V_80 -> V_50 . type != V_54 )
return NULL ;
if ( V_76 -> V_50 . V_61 != V_80 -> V_50 . V_61 ||
V_76 -> V_39 . V_2 != V_80 -> V_1 . V_2 )
return NULL ;
if ( V_79 )
F_62 ( V_79 , NULL ) ;
return V_80 ;
}
static int F_63 ( T_1 V_82 , struct V_56 * V_57 )
{
unsigned long V_83 ;
V_83 = F_64 ( V_82 , V_84 ) ;
V_83 /= 1000 ;
return F_50 ( V_57 , L_10 ,
( unsigned long ) V_82 , V_83 ) ;
}
static enum V_55
F_65 ( struct V_74 * V_75 , unsigned long V_85 ,
enum V_86 type , int V_46 , T_2 V_61 , T_3 V_25 )
{
int V_1 ;
struct V_56 * V_57 = & V_75 -> V_87 ;
if ( V_85 < ( unsigned long ) V_88 ||
V_85 >= ( unsigned long ) V_89 )
return V_90 ;
if ( V_91 & V_92 ) {
if ( V_25 & V_93 ) {
V_1 = F_63 ( V_75 -> V_94 , V_57 ) ;
if ( ! V_1 )
return V_59 ;
}
if ( V_25 & V_95 ) {
V_1 = F_49 ( V_57 , V_46 ) ;
if ( V_1 == V_59 )
return V_59 ;
}
if ( V_25 & V_96 ) {
V_1 = F_51 ( V_57 , V_61 ) ;
if ( V_1 == V_59 )
return V_59 ;
V_1 = F_50 ( V_57 , L_11 ) ;
if ( ! V_1 )
return V_59 ;
}
}
V_1 = F_66 ( V_97 , V_57 , V_25 ) ;
if ( V_1 != V_60 )
return V_1 ;
if ( type == V_38 )
V_1 = F_50 ( V_57 , L_12 ) ;
else
V_1 = F_50 ( V_57 , L_13 ) ;
if ( ! V_1 )
return V_59 ;
V_1 = F_66 ( V_98 , V_57 , V_25 ) ;
if ( V_1 != V_60 )
return V_1 ;
V_1 = F_50 ( V_57 , L_14 ) ;
if ( ! V_1 )
return V_59 ;
return V_60 ;
}
enum V_55
F_67 ( unsigned long long V_99 , struct V_56 * V_57 )
{
unsigned long V_100 = F_64 ( V_99 , 1000 ) ;
char V_101 [ 21 ] ;
char V_102 [ 5 ] ;
int V_1 , V_66 ;
int V_67 ;
sprintf ( V_101 , L_15 , ( unsigned long ) V_99 ) ;
V_1 = F_50 ( V_57 , L_16 , V_101 ) ;
if ( ! V_1 )
return V_59 ;
V_66 = strlen ( V_101 ) ;
if ( V_66 < 7 ) {
T_4 V_103 = F_68 ( T_4 , sizeof( V_102 ) , 8UL - V_66 ) ;
snprintf ( V_102 , V_103 , L_17 , V_100 ) ;
V_1 = F_50 ( V_57 , L_18 , V_102 ) ;
if ( ! V_1 )
return V_59 ;
V_66 += strlen ( V_102 ) ;
}
V_1 = F_50 ( V_57 , L_19 ) ;
if ( ! V_1 )
return V_59 ;
for ( V_67 = V_66 ; V_67 < 7 ; V_67 ++ ) {
V_1 = F_50 ( V_57 , L_5 ) ;
if ( ! V_1 )
return V_59 ;
}
return V_60 ;
}
static enum V_55
F_66 ( unsigned long long V_99 , struct V_56 * V_57 ,
T_3 V_25 )
{
int V_1 = - 1 ;
if ( ! ( V_25 & V_104 ) ||
! ( V_91 & V_92 ) )
return V_60 ;
switch ( V_99 ) {
case V_105 :
V_1 = F_50 ( V_57 , L_20 ) ;
return V_1 ? V_60 : V_59 ;
case V_97 :
V_1 = F_50 ( V_57 , L_21 ) ;
return V_1 ? V_60 : V_59 ;
case V_98 :
V_1 = F_50 ( V_57 , L_22 ) ;
return V_1 ? V_60 : V_59 ;
}
if ( V_25 & V_106 ) {
if ( V_99 > 100000ULL )
V_1 = F_50 ( V_57 , L_23 ) ;
else if ( V_99 > 10000ULL )
V_1 = F_50 ( V_57 , L_24 ) ;
}
if ( V_1 == - 1 )
V_1 = F_50 ( V_57 , L_21 ) ;
if ( ! V_1 )
return V_59 ;
V_1 = F_67 ( V_99 , V_57 ) ;
if ( V_1 != V_60 )
return V_1 ;
V_1 = F_50 ( V_57 , L_25 ) ;
if ( ! V_1 )
return V_59 ;
return V_60 ;
}
static enum V_55
F_69 ( struct V_74 * V_75 ,
struct V_35 * V_36 ,
struct V_53 * V_107 ,
struct V_56 * V_57 , T_3 V_25 )
{
struct V_70 * V_44 = V_75 -> V_77 ;
struct V_15 * V_108 ;
struct V_24 * V_28 ;
unsigned long long V_99 ;
int V_1 ;
int V_67 ;
V_108 = & V_107 -> V_1 ;
V_28 = & V_36 -> V_39 ;
V_99 = V_108 -> V_21 - V_108 -> V_5 ;
if ( V_44 ) {
struct V_109 * V_73 ;
int V_46 = V_75 -> V_46 ;
V_73 = F_29 ( V_44 -> V_73 , V_46 ) ;
V_73 -> V_3 = V_28 -> V_3 - 1 ;
if ( V_28 -> V_3 < V_11 )
V_73 -> V_110 [ V_28 -> V_3 ] = 0 ;
}
V_1 = F_66 ( V_99 , V_57 , V_25 ) ;
if ( V_1 == V_59 )
return V_59 ;
for ( V_67 = 0 ; V_67 < V_28 -> V_3 * V_111 ; V_67 ++ ) {
V_1 = F_50 ( V_57 , L_5 ) ;
if ( ! V_1 )
return V_59 ;
}
V_1 = F_50 ( V_57 , L_26 , ( void * ) V_28 -> V_2 ) ;
if ( ! V_1 )
return V_59 ;
return V_60 ;
}
static enum V_55
F_70 ( struct V_74 * V_75 ,
struct V_35 * V_36 ,
struct V_56 * V_57 , int V_46 , T_3 V_25 )
{
struct V_24 * V_28 = & V_36 -> V_39 ;
struct V_70 * V_44 = V_75 -> V_77 ;
int V_1 ;
int V_67 ;
if ( V_44 ) {
struct V_109 * V_73 ;
int V_46 = V_75 -> V_46 ;
V_73 = F_29 ( V_44 -> V_73 , V_46 ) ;
V_73 -> V_3 = V_28 -> V_3 ;
if ( V_28 -> V_3 < V_11 )
V_73 -> V_110 [ V_28 -> V_3 ] = V_28 -> V_2 ;
}
V_1 = F_66 ( V_105 , V_57 , V_25 ) ;
if ( V_1 != V_60 )
return V_1 ;
for ( V_67 = 0 ; V_67 < V_28 -> V_3 * V_111 ; V_67 ++ ) {
V_1 = F_50 ( V_57 , L_5 ) ;
if ( ! V_1 )
return V_59 ;
}
V_1 = F_50 ( V_57 , L_27 , ( void * ) V_28 -> V_2 ) ;
if ( ! V_1 )
return V_59 ;
return V_112 ;
}
static enum V_55
F_71 ( struct V_74 * V_75 , struct V_56 * V_57 ,
int type , unsigned long V_85 , T_3 V_25 )
{
struct V_70 * V_44 = V_75 -> V_77 ;
struct V_69 * V_50 = V_75 -> V_50 ;
int V_46 = V_75 -> V_46 ;
int V_1 ;
if ( F_56 ( V_57 , V_50 -> V_61 , V_46 , V_44 ) == V_59 )
return V_59 ;
if ( type ) {
V_1 = F_65 ( V_75 , V_85 , type , V_46 , V_50 -> V_61 , V_25 ) ;
if ( V_1 == V_59 )
return V_59 ;
}
if ( ! ( V_91 & V_92 ) )
return 0 ;
if ( V_25 & V_93 ) {
V_1 = F_63 ( V_75 -> V_94 , V_57 ) ;
if ( ! V_1 )
return V_59 ;
}
if ( V_25 & V_95 ) {
V_1 = F_49 ( V_57 , V_46 ) ;
if ( V_1 == V_59 )
return V_59 ;
}
if ( V_25 & V_96 ) {
V_1 = F_51 ( V_57 , V_50 -> V_61 ) ;
if ( V_1 == V_59 )
return V_59 ;
V_1 = F_50 ( V_57 , L_11 ) ;
if ( ! V_1 )
return V_59 ;
}
if ( V_91 & V_113 ) {
V_1 = F_53 ( V_57 , V_50 ) ;
if ( V_1 == V_59 )
return V_59 ;
}
return 0 ;
}
static int
F_72 ( struct V_74 * V_75 , T_3 V_25 ,
unsigned long V_85 , int V_3 )
{
int V_46 = V_75 -> V_46 ;
int * V_114 ;
struct V_70 * V_44 = V_75 -> V_77 ;
if ( ( V_25 & V_115 ) ||
( ! V_44 ) )
return 0 ;
V_114 = & ( F_29 ( V_44 -> V_73 , V_46 ) -> V_114 ) ;
if ( * V_114 >= 0 )
return 1 ;
if ( ( V_85 < ( unsigned long ) V_88 ) ||
( V_85 >= ( unsigned long ) V_89 ) )
return 0 ;
* V_114 = V_3 ;
return 1 ;
}
static int
F_73 ( struct V_74 * V_75 , T_3 V_25 , int V_3 )
{
int V_46 = V_75 -> V_46 ;
int * V_114 ;
struct V_70 * V_44 = V_75 -> V_77 ;
if ( ( V_25 & V_115 ) ||
( ! V_44 ) )
return 0 ;
V_114 = & ( F_29 ( V_44 -> V_73 , V_46 ) -> V_114 ) ;
if ( * V_114 == - 1 )
return 0 ;
if ( * V_114 >= V_3 ) {
* V_114 = - 1 ;
return 1 ;
}
return 1 ;
}
static enum V_55
F_74 ( struct V_35 * V_116 , struct V_56 * V_57 ,
struct V_74 * V_75 , T_3 V_25 )
{
struct V_70 * V_44 = V_75 -> V_77 ;
struct V_24 * V_28 = & V_116 -> V_39 ;
struct V_53 * V_117 ;
static enum V_55 V_1 ;
int V_46 = V_75 -> V_46 ;
if ( F_72 ( V_75 , V_25 , V_28 -> V_2 , V_28 -> V_3 ) )
return V_60 ;
if ( F_71 ( V_75 , V_57 , V_38 , V_28 -> V_2 , V_25 ) )
return V_59 ;
V_117 = F_57 ( V_75 , V_116 ) ;
if ( V_117 )
V_1 = F_69 ( V_75 , V_116 , V_117 , V_57 , V_25 ) ;
else
V_1 = F_70 ( V_75 , V_116 , V_57 , V_46 , V_25 ) ;
if ( V_44 ) {
if ( V_57 -> V_118 ) {
V_44 -> V_81 = 1 ;
V_44 -> V_46 = V_46 ;
} else
V_44 -> V_81 = 0 ;
}
return V_1 ;
}
static enum V_55
F_75 ( struct V_15 * V_16 , struct V_56 * V_57 ,
struct V_69 * V_50 , struct V_74 * V_75 ,
T_3 V_25 )
{
unsigned long long V_99 = V_16 -> V_21 - V_16 -> V_5 ;
struct V_70 * V_44 = V_75 -> V_77 ;
T_2 V_61 = V_50 -> V_61 ;
int V_46 = V_75 -> V_46 ;
int V_119 = 1 ;
int V_1 ;
int V_67 ;
if ( F_73 ( V_75 , V_25 , V_16 -> V_3 ) )
return V_60 ;
if ( V_44 ) {
struct V_109 * V_73 ;
int V_46 = V_75 -> V_46 ;
V_73 = F_29 ( V_44 -> V_73 , V_46 ) ;
V_73 -> V_3 = V_16 -> V_3 - 1 ;
if ( V_16 -> V_3 < V_11 ) {
if ( V_73 -> V_110 [ V_16 -> V_3 ] != V_16 -> V_2 )
V_119 = 0 ;
V_73 -> V_110 [ V_16 -> V_3 ] = 0 ;
}
}
if ( F_71 ( V_75 , V_57 , 0 , 0 , V_25 ) )
return V_59 ;
V_1 = F_66 ( V_99 , V_57 , V_25 ) ;
if ( V_1 == V_59 )
return V_59 ;
for ( V_67 = 0 ; V_67 < V_16 -> V_3 * V_111 ; V_67 ++ ) {
V_1 = F_50 ( V_57 , L_5 ) ;
if ( ! V_1 )
return V_59 ;
}
if ( V_119 ) {
V_1 = F_50 ( V_57 , L_28 ) ;
if ( ! V_1 )
return V_59 ;
} else {
V_1 = F_50 ( V_57 , L_29 , ( void * ) V_16 -> V_2 ) ;
if ( ! V_1 )
return V_59 ;
}
if ( V_25 & V_120 ) {
V_1 = F_50 ( V_57 , L_30 ,
V_16 -> V_20 ) ;
if ( ! V_1 )
return V_59 ;
}
V_1 = F_65 ( V_75 , V_16 -> V_2 , V_54 ,
V_46 , V_61 , V_25 ) ;
if ( V_1 == V_59 )
return V_59 ;
return V_60 ;
}
static enum V_55
F_76 ( struct V_56 * V_57 , struct V_69 * V_50 ,
struct V_74 * V_75 , T_3 V_25 )
{
unsigned long V_121 = ( V_91 & V_122 ) ;
struct V_70 * V_44 = V_75 -> V_77 ;
struct V_123 * V_31 ;
int V_3 = 0 ;
int V_1 ;
int V_67 ;
if ( V_44 )
V_3 = F_29 ( V_44 -> V_73 , V_75 -> V_46 ) -> V_3 ;
if ( F_71 ( V_75 , V_57 , 0 , 0 , V_25 ) )
return V_59 ;
V_1 = F_66 ( V_105 , V_57 , V_25 ) ;
if ( V_1 != V_60 )
return V_1 ;
if ( V_3 > 0 )
for ( V_67 = 0 ; V_67 < ( V_3 + 1 ) * V_111 ; V_67 ++ ) {
V_1 = F_50 ( V_57 , L_5 ) ;
if ( ! V_1 )
return V_59 ;
}
V_1 = F_50 ( V_57 , L_31 ) ;
if ( ! V_1 )
return V_59 ;
switch ( V_75 -> V_50 -> type ) {
case V_124 :
V_1 = F_77 ( V_75 ) ;
if ( V_1 != V_60 )
return V_1 ;
break;
case V_125 :
V_1 = F_78 ( V_75 ) ;
if ( V_1 != V_60 )
return V_1 ;
break;
default:
V_31 = F_79 ( V_50 -> type ) ;
if ( ! V_31 )
return V_90 ;
V_1 = V_31 -> V_126 -> V_16 ( V_75 , V_121 , V_31 ) ;
if ( V_1 != V_60 )
return V_1 ;
}
if ( V_57 -> V_33 [ V_57 -> V_66 - 1 ] == '\n' ) {
V_57 -> V_33 [ V_57 -> V_66 - 1 ] = '\0' ;
V_57 -> V_66 -- ;
}
V_1 = F_50 ( V_57 , L_32 ) ;
if ( ! V_1 )
return V_59 ;
return V_60 ;
}
enum V_55
F_80 ( struct V_74 * V_75 , T_3 V_25 )
{
struct V_35 * V_116 ;
struct V_70 * V_44 = V_75 -> V_77 ;
struct V_69 * V_36 = V_75 -> V_50 ;
struct V_56 * V_57 = & V_75 -> V_87 ;
int V_46 = V_75 -> V_46 ;
int V_1 ;
if ( V_44 && F_29 ( V_44 -> V_73 , V_46 ) -> V_127 ) {
F_29 ( V_44 -> V_73 , V_46 ) -> V_127 = 0 ;
return V_60 ;
}
if ( V_44 && V_44 -> V_81 ) {
V_116 = & V_44 -> V_50 ;
V_75 -> V_46 = V_44 -> V_46 ;
V_1 = F_74 ( V_116 , V_57 , V_75 , V_25 ) ;
if ( V_1 == V_60 && V_75 -> V_46 != V_46 ) {
F_29 ( V_44 -> V_73 , V_75 -> V_46 ) -> V_127 = 1 ;
V_1 = V_112 ;
}
V_75 -> V_46 = V_46 ;
return V_1 ;
}
switch ( V_36 -> type ) {
case V_38 : {
struct V_35 V_128 ;
F_81 ( V_116 , V_36 ) ;
V_128 = * V_116 ;
return F_74 ( & V_128 , V_57 , V_75 , V_25 ) ;
}
case V_54 : {
struct V_53 * V_116 ;
F_81 ( V_116 , V_36 ) ;
return F_75 ( & V_116 -> V_1 , V_57 , V_36 , V_75 , V_25 ) ;
}
case V_129 :
case V_130 :
return V_90 ;
default:
return F_76 ( V_57 , V_36 , V_75 , V_25 ) ;
}
return V_60 ;
}
static enum V_55
F_82 ( struct V_74 * V_75 )
{
return F_80 ( V_75 , V_131 . V_132 ) ;
}
static enum V_55
F_83 ( struct V_74 * V_75 , int V_25 ,
struct V_123 * V_31 )
{
return F_82 ( V_75 ) ;
}
static void F_84 ( struct V_133 * V_57 , T_3 V_25 )
{
static const char V_65 [] = L_33
L_34
L_35 ;
int V_134 = 0 ;
if ( V_25 & V_93 )
V_134 += 16 ;
if ( V_25 & V_95 )
V_134 += 4 ;
if ( V_25 & V_96 )
V_134 += 17 ;
F_85 ( V_57 , L_36 , V_134 , V_65 ) ;
F_85 ( V_57 , L_37 , V_134 , V_65 ) ;
F_85 ( V_57 , L_38 , V_134 , V_65 ) ;
F_85 ( V_57 , L_39 , V_134 , V_65 ) ;
F_85 ( V_57 , L_40 , V_134 , V_65 ) ;
}
static void F_86 ( struct V_133 * V_57 , T_3 V_25 )
{
int V_135 = V_91 & V_113 ;
if ( V_135 )
F_84 ( V_57 , V_25 ) ;
F_85 ( V_57 , L_41 ) ;
if ( V_25 & V_93 )
F_85 ( V_57 , L_42 ) ;
if ( V_25 & V_95 )
F_85 ( V_57 , L_43 ) ;
if ( V_25 & V_96 )
F_85 ( V_57 , L_44 ) ;
if ( V_135 )
F_85 ( V_57 , L_45 ) ;
if ( V_25 & V_104 )
F_85 ( V_57 , L_46 ) ;
F_85 ( V_57 , L_47 ) ;
F_85 ( V_57 , L_41 ) ;
if ( V_25 & V_93 )
F_85 ( V_57 , L_48 ) ;
if ( V_25 & V_95 )
F_85 ( V_57 , L_49 ) ;
if ( V_25 & V_96 )
F_85 ( V_57 , L_50 ) ;
if ( V_135 )
F_85 ( V_57 , L_45 ) ;
if ( V_25 & V_104 )
F_85 ( V_57 , L_51 ) ;
F_85 ( V_57 , L_52 ) ;
}
void F_87 ( struct V_133 * V_57 )
{
F_88 ( V_57 , V_131 . V_132 ) ;
}
void F_88 ( struct V_133 * V_57 , T_3 V_25 )
{
struct V_74 * V_75 = V_57 -> V_77 ;
if ( ! ( V_91 & V_92 ) )
return;
if ( V_91 & V_113 ) {
if ( F_89 ( V_75 ) )
return;
F_90 ( V_57 , V_75 ) ;
}
F_86 ( V_57 , V_25 ) ;
}
void F_91 ( struct V_74 * V_75 )
{
struct V_70 * V_44 ;
int V_46 ;
V_75 -> V_77 = NULL ;
V_44 = F_92 ( sizeof( * V_44 ) , V_136 ) ;
if ( ! V_44 )
goto V_137;
V_44 -> V_73 = F_93 ( struct V_109 ) ;
if ( ! V_44 -> V_73 )
goto V_138;
F_94 (cpu) {
T_2 * V_61 = & ( F_29 ( V_44 -> V_73 , V_46 ) -> V_72 ) ;
int * V_3 = & ( F_29 ( V_44 -> V_73 , V_46 ) -> V_3 ) ;
int * V_127 = & ( F_29 ( V_44 -> V_73 , V_46 ) -> V_127 ) ;
int * V_114 = & ( F_29 ( V_44 -> V_73 , V_46 ) -> V_114 ) ;
* V_61 = - 1 ;
* V_3 = 0 ;
* V_127 = 0 ;
* V_114 = - 1 ;
}
V_75 -> V_77 = V_44 ;
return;
V_138:
F_95 ( V_44 ) ;
V_137:
F_96 ( L_53 ) ;
}
void F_97 ( struct V_74 * V_75 )
{
struct V_70 * V_44 = V_75 -> V_77 ;
if ( V_44 ) {
F_98 ( V_44 -> V_73 ) ;
F_95 ( V_44 ) ;
}
}
static int F_99 ( T_3 V_139 , T_3 V_140 , int V_141 )
{
if ( V_140 == V_115 )
V_40 = ! V_141 ;
return 0 ;
}
static T_5
F_100 ( struct V_142 * V_143 , const char T_6 * V_144 , T_4 V_145 ,
T_7 * V_146 )
{
unsigned long V_132 ;
int V_1 ;
V_1 = F_101 ( V_144 , V_145 , 10 , & V_132 ) ;
if ( V_1 )
return V_1 ;
V_47 = V_132 ;
* V_146 += V_145 ;
return V_145 ;
}
static T_5
F_102 ( struct V_142 * V_143 , char T_6 * V_144 , T_4 V_145 ,
T_7 * V_146 )
{
char V_147 [ 15 ] ;
int V_148 ;
V_148 = sprintf ( V_147 , L_54 , V_47 ) ;
return F_103 ( V_144 , V_145 , V_146 , V_147 , V_148 ) ;
}
static T_8 int F_104 ( void )
{
struct V_149 * V_150 ;
V_150 = F_105 () ;
if ( ! V_150 )
return 0 ;
F_106 ( L_55 , 0644 , V_150 ,
NULL , & V_151 ) ;
return 0 ;
}
static T_8 int F_107 ( void )
{
V_58 = snprintf ( NULL , 0 , L_4 , V_152 - 1 ) ;
if ( ! F_108 ( & V_153 ) ) {
F_96 ( L_56 ) ;
return 1 ;
}
if ( ! F_108 ( & V_154 ) ) {
F_96 ( L_56 ) ;
return 1 ;
}
return F_109 ( & V_155 ) ;
}
