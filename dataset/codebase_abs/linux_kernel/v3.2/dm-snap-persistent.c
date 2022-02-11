static int F_1 ( struct V_1 * V_2 )
{
int V_3 = - V_4 ;
T_1 V_5 ;
V_5 = V_2 -> V_6 -> V_7 << V_8 ;
V_2 -> V_9 = F_2 ( V_5 ) ;
if ( ! V_2 -> V_9 )
goto V_10;
V_2 -> V_11 = F_3 ( V_5 ) ;
if ( ! V_2 -> V_11 )
goto V_12;
V_2 -> V_13 = F_2 ( V_5 ) ;
if ( ! V_2 -> V_13 )
goto V_14;
return 0 ;
V_14:
F_4 ( V_2 -> V_11 ) ;
V_12:
F_4 ( V_2 -> V_9 ) ;
V_10:
return V_3 ;
}
static void F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 )
F_4 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
if ( V_2 -> V_11 )
F_4 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
if ( V_2 -> V_13 )
F_4 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
static void F_6 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 , V_16 ) ;
V_18 -> V_19 = F_8 ( V_18 -> V_20 , 1 , V_18 -> V_21 , NULL ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_9 , T_2 V_22 , int V_23 ,
int V_24 )
{
struct V_25 V_21 = {
. V_26 = F_10 ( V_2 -> V_6 -> V_27 ) -> V_26 ,
. V_28 = V_2 -> V_6 -> V_7 * V_22 ,
. V_29 = V_2 -> V_6 -> V_7 ,
} ;
struct V_30 V_20 = {
. V_31 = V_23 ,
. V_32 . type = V_33 ,
. V_32 . V_34 . V_35 = V_9 ,
. V_36 = V_2 -> V_37 ,
. V_38 . V_39 = NULL ,
} ;
struct V_17 V_18 ;
if ( ! V_24 )
return F_8 ( & V_20 , 1 , & V_21 , NULL ) ;
V_18 . V_21 = & V_21 ;
V_18 . V_20 = & V_20 ;
F_11 ( & V_18 . V_16 , F_6 ) ;
F_12 ( V_2 -> V_40 , & V_18 . V_16 ) ;
F_13 ( & V_18 . V_16 ) ;
return V_18 . V_19 ;
}
static T_2 F_14 ( struct V_1 * V_2 , T_2 V_9 )
{
return V_41 + ( ( V_2 -> V_42 + 1 ) * V_9 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_23 )
{
int V_3 ;
T_2 V_22 ;
V_22 = F_14 ( V_2 , V_2 -> V_43 ) ;
V_3 = F_9 ( V_2 , V_2 -> V_9 , V_22 , V_23 , 0 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_9 , 0 , V_2 -> V_6 -> V_7 << V_8 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_2 V_9 )
{
return F_9 ( V_2 , V_2 -> V_11 , F_14 ( V_2 , V_9 ) , V_44 , 0 ) ;
}
static int F_18 ( struct V_1 * V_2 , int * V_45 )
{
int V_3 ;
struct V_46 * V_47 ;
unsigned V_7 ;
int V_48 = 1 ;
char * V_49 ;
if ( ! V_2 -> V_6 -> V_7 ) {
V_2 -> V_6 -> V_7 = F_19 ( V_50 ,
F_20 ( F_10 ( V_2 -> V_6 -> V_27 ) ->
V_26 ) >> 9 ) ;
V_2 -> V_6 -> V_51 = V_2 -> V_6 -> V_7 - 1 ;
V_2 -> V_6 -> V_52 = F_21 ( V_2 -> V_6 -> V_7 ) - 1 ;
V_48 = 0 ;
}
V_2 -> V_37 = F_22 () ;
if ( F_23 ( V_2 -> V_37 ) )
return F_24 ( V_2 -> V_37 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_9 ( V_2 , V_2 -> V_13 , 0 , V_53 , 1 ) ;
if ( V_3 )
goto V_54;
V_47 = V_2 -> V_13 ;
if ( F_25 ( V_47 -> V_55 ) == 0 ) {
* V_45 = 1 ;
return 0 ;
}
if ( F_25 ( V_47 -> V_55 ) != V_56 ) {
F_26 ( L_1 ) ;
V_3 = - V_57 ;
goto V_54;
}
* V_45 = 0 ;
V_2 -> V_58 = F_25 ( V_47 -> V_58 ) ;
V_2 -> V_59 = F_25 ( V_47 -> V_59 ) ;
V_7 = F_25 ( V_47 -> V_7 ) ;
if ( V_2 -> V_6 -> V_7 == V_7 )
return 0 ;
if ( V_48 )
F_26 ( L_2
L_3 ,
V_7 , V_2 -> V_6 -> V_7 ) ;
F_5 ( V_2 ) ;
V_3 = F_27 ( V_2 -> V_6 , V_7 ,
& V_49 ) ;
if ( V_3 ) {
F_28 ( L_4 ,
V_7 , V_49 ) ;
return V_3 ;
}
V_3 = F_1 ( V_2 ) ;
return V_3 ;
V_54:
F_5 ( V_2 ) ;
return V_3 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
memset ( V_2 -> V_13 , 0 , V_2 -> V_6 -> V_7 << V_8 ) ;
V_47 = V_2 -> V_13 ;
V_47 -> V_55 = F_30 ( V_56 ) ;
V_47 -> V_58 = F_30 ( V_2 -> V_58 ) ;
V_47 -> V_59 = F_30 ( V_2 -> V_59 ) ;
V_47 -> V_7 = F_30 ( V_2 -> V_6 -> V_7 ) ;
return F_9 ( V_2 , V_2 -> V_13 , 0 , V_44 , 1 ) ;
}
static struct V_60 * F_31 ( struct V_1 * V_2 , T_3 V_61 )
{
F_32 ( V_61 >= V_2 -> V_42 ) ;
return ( (struct V_60 * ) V_2 -> V_9 ) + V_61 ;
}
static void F_33 ( struct V_1 * V_2 ,
T_3 V_61 , struct V_62 * V_19 )
{
struct V_60 * V_63 = F_31 ( V_2 , V_61 ) ;
V_19 -> V_64 = F_34 ( V_63 -> V_64 ) ;
V_19 -> V_65 = F_34 ( V_63 -> V_65 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
T_3 V_61 , struct V_62 * V_66 )
{
struct V_60 * V_63 = F_31 ( V_2 , V_61 ) ;
V_63 -> V_64 = F_36 ( V_66 -> V_64 ) ;
V_63 -> V_65 = F_36 ( V_66 -> V_65 ) ;
}
static void F_37 ( struct V_1 * V_2 , T_3 V_61 )
{
struct V_60 * V_63 = F_31 ( V_2 , V_61 ) ;
V_63 -> V_64 = 0 ;
V_63 -> V_65 = 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
int (* F_39)( void * V_67 ,
T_2 V_68 , T_2 V_69 ) ,
void * V_67 ,
int * V_70 )
{
int V_3 ;
unsigned int V_71 ;
struct V_62 V_66 ;
* V_70 = 1 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_42 ; V_71 ++ ) {
F_33 ( V_2 , V_71 , & V_66 ) ;
if ( V_66 . V_65 == 0LL ) {
V_2 -> V_72 = V_71 ;
* V_70 = 0 ;
break;
}
if ( V_2 -> V_73 <= V_66 . V_65 )
V_2 -> V_73 = V_66 . V_65 + 1 ;
V_3 = F_39 ( V_67 , V_66 . V_64 , V_66 . V_65 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
int (* F_39)( void * V_67 , T_2 V_68 ,
T_2 V_69 ) ,
void * V_67 )
{
int V_3 , V_70 = 1 ;
for ( V_2 -> V_43 = 0 ; V_70 ; V_2 -> V_43 ++ ) {
V_3 = F_15 ( V_2 , V_53 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_38 ( V_2 , F_39 , V_67 , & V_70 ) ;
if ( V_3 )
return V_3 ;
}
V_2 -> V_43 -- ;
return 0 ;
}
static struct V_1 * F_41 ( struct V_74 * V_6 )
{
return (struct V_1 * ) V_6 -> V_75 ;
}
static void F_42 ( struct V_74 * V_6 ,
T_4 * V_76 ,
T_4 * V_77 ,
T_4 * V_78 )
{
struct V_1 * V_2 = F_41 ( V_6 ) ;
* V_77 = V_2 -> V_73 * V_6 -> V_7 ;
* V_76 = F_43 ( F_10 ( V_6 -> V_27 ) -> V_26 ) ;
* V_78 = ( V_2 -> V_43 + 1 + V_41 ) *
V_6 -> V_7 ;
}
static void F_44 ( struct V_74 * V_6 )
{
struct V_1 * V_2 = F_41 ( V_6 ) ;
F_45 ( V_2 -> V_40 ) ;
if ( V_2 -> V_37 )
F_46 ( V_2 -> V_37 ) ;
F_5 ( V_2 ) ;
if ( V_2 -> V_79 )
F_4 ( V_2 -> V_79 ) ;
F_47 ( V_2 ) ;
}
static int F_48 ( struct V_74 * V_6 ,
int (* F_39)( void * V_67 ,
T_2 V_68 , T_2 V_69 ) ,
void * V_67 )
{
int V_3 , V_80 ( V_45 ) ;
struct V_1 * V_2 = F_41 ( V_6 ) ;
V_3 = F_18 ( V_2 , & V_45 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_42 = ( V_2 -> V_6 -> V_7 << V_8 ) /
sizeof( struct V_60 ) ;
V_2 -> V_79 = F_49 ( V_2 -> V_42 ,
sizeof( * V_2 -> V_79 ) ) ;
if ( ! V_2 -> V_79 )
return - V_4 ;
if ( V_45 ) {
V_3 = F_29 ( V_2 ) ;
if ( V_3 ) {
F_26 ( L_5 ) ;
return V_3 ;
}
V_2 -> V_43 = 0 ;
F_16 ( V_2 ) ;
V_3 = F_17 ( V_2 , 0 ) ;
if ( V_3 )
F_26 ( L_6 ) ;
return V_3 ;
}
if ( V_2 -> V_59 != V_81 ) {
F_26 ( L_7 ,
V_2 -> V_59 ) ;
return - V_82 ;
}
if ( ! V_2 -> V_58 )
return 1 ;
V_3 = F_40 ( V_2 , F_39 , V_67 ) ;
return V_3 ;
}
static int F_50 ( struct V_74 * V_6 ,
struct V_83 * V_66 )
{
struct V_1 * V_2 = F_41 ( V_6 ) ;
T_3 V_84 ;
T_2 V_73 ;
T_4 V_85 = F_43 ( F_10 ( V_6 -> V_27 ) -> V_26 ) ;
if ( V_85 < ( ( V_2 -> V_73 + 1 ) * V_6 -> V_7 ) )
return - V_86 ;
V_66 -> V_65 = V_2 -> V_73 ;
V_84 = ( V_2 -> V_42 + 1 ) ;
V_73 = ++ V_2 -> V_73 ;
if ( F_51 ( V_73 , V_84 ) == 1 )
V_2 -> V_73 ++ ;
F_52 ( & V_2 -> V_87 ) ;
return 0 ;
}
static void F_53 ( struct V_74 * V_6 ,
struct V_83 * V_66 ,
void (* F_39) ( void * , int V_88 ) ,
void * V_67 )
{
unsigned int V_71 ;
struct V_1 * V_2 = F_41 ( V_6 ) ;
struct V_62 V_89 ;
struct V_90 * V_91 ;
V_89 . V_64 = V_66 -> V_64 ;
V_89 . V_65 = V_66 -> V_65 ;
F_35 ( V_2 , V_2 -> V_72 ++ , & V_89 ) ;
V_91 = V_2 -> V_79 + V_2 -> V_92 ++ ;
V_91 -> F_39 = F_39 ;
V_91 -> V_75 = V_67 ;
if ( ! F_54 ( & V_2 -> V_87 ) &&
( V_2 -> V_72 != V_2 -> V_42 ) )
return;
if ( ( V_2 -> V_72 == V_2 -> V_42 ) &&
F_17 ( V_2 , V_2 -> V_43 + 1 ) )
V_2 -> V_58 = 0 ;
if ( V_2 -> V_58 && F_15 ( V_2 , V_93 ) )
V_2 -> V_58 = 0 ;
if ( V_2 -> V_72 == V_2 -> V_42 ) {
V_2 -> V_72 = 0 ;
V_2 -> V_43 ++ ;
F_16 ( V_2 ) ;
}
for ( V_71 = 0 ; V_71 < V_2 -> V_92 ; V_71 ++ ) {
V_91 = V_2 -> V_79 + V_71 ;
V_91 -> F_39 ( V_91 -> V_75 , V_2 -> V_58 ) ;
}
V_2 -> V_92 = 0 ;
}
static int F_55 ( struct V_74 * V_6 ,
T_2 * V_94 ,
T_2 * V_95 )
{
struct V_1 * V_2 = F_41 ( V_6 ) ;
struct V_62 V_89 ;
int V_96 ;
int V_3 ;
if ( ! V_2 -> V_72 ) {
if ( ! V_2 -> V_43 )
return 0 ;
V_2 -> V_43 -- ;
V_3 = F_15 ( V_2 , V_53 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_72 = V_2 -> V_42 ;
}
F_33 ( V_2 , V_2 -> V_72 - 1 , & V_89 ) ;
* V_94 = V_89 . V_64 ;
* V_95 = V_89 . V_65 ;
for ( V_96 = 1 ; V_96 < V_2 -> V_72 ;
V_96 ++ ) {
F_33 ( V_2 , V_2 -> V_72 - 1 - V_96 ,
& V_89 ) ;
if ( V_89 . V_64 != * V_94 - V_96 ||
V_89 . V_65 != * V_95 - V_96 )
break;
}
return V_96 ;
}
static int F_56 ( struct V_74 * V_6 ,
int V_97 )
{
int V_3 , V_71 ;
struct V_1 * V_2 = F_41 ( V_6 ) ;
F_32 ( V_97 > V_2 -> V_72 ) ;
for ( V_71 = 0 ; V_71 < V_97 ; V_71 ++ )
F_37 ( V_2 , V_2 -> V_72 - 1 - V_71 ) ;
V_3 = F_15 ( V_2 , V_93 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_72 -= V_97 ;
V_2 -> V_73 = F_14 ( V_2 , V_2 -> V_43 ) +
V_2 -> V_72 + 1 ;
return 0 ;
}
static void F_57 ( struct V_74 * V_6 )
{
struct V_1 * V_2 = F_41 ( V_6 ) ;
V_2 -> V_58 = 0 ;
if ( F_29 ( V_2 ) )
F_26 ( L_8 ) ;
}
static int F_58 ( struct V_74 * V_6 ,
unsigned V_98 , char * * V_99 )
{
struct V_1 * V_2 ;
V_2 = F_59 ( sizeof( * V_2 ) , V_100 ) ;
if ( ! V_2 )
return - V_4 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_58 = 1 ;
V_2 -> V_59 = V_81 ;
V_2 -> V_9 = NULL ;
V_2 -> V_11 = NULL ;
V_2 -> V_13 = NULL ;
V_2 -> V_73 = V_41 + 1 ;
V_2 -> V_72 = 0 ;
V_2 -> V_92 = 0 ;
F_60 ( & V_2 -> V_87 , 0 ) ;
V_2 -> V_79 = NULL ;
V_2 -> V_40 = F_61 ( L_9 , V_101 , 0 ) ;
if ( ! V_2 -> V_40 ) {
F_47 ( V_2 ) ;
F_28 ( L_10 ) ;
return - V_4 ;
}
V_6 -> V_75 = V_2 ;
return 0 ;
}
static unsigned F_62 ( struct V_74 * V_6 ,
T_5 V_102 , char * V_19 ,
unsigned V_103 )
{
unsigned V_104 = 0 ;
switch ( V_102 ) {
case V_105 :
break;
case V_106 :
F_63 ( L_11 , ( unsigned long long ) V_6 -> V_7 ) ;
}
return V_104 ;
}
int F_64 ( void )
{
int V_3 ;
V_3 = F_65 ( & V_107 ) ;
if ( V_3 ) {
F_28 ( L_12 ) ;
return V_3 ;
}
V_3 = F_65 ( & V_108 ) ;
if ( V_3 ) {
F_28 ( L_13
L_14 ) ;
F_66 ( & V_107 ) ;
return V_3 ;
}
return V_3 ;
}
void F_67 ( void )
{
F_66 ( & V_107 ) ;
F_66 ( & V_108 ) ;
}
