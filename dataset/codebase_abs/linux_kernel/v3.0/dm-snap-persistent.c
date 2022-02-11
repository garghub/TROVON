static int F_1 ( struct V_1 * V_2 )
{
int V_3 = - V_4 ;
T_1 V_5 ;
V_5 = V_2 -> V_6 -> V_7 << V_8 ;
V_2 -> V_9 = F_2 ( V_5 ) ;
if ( ! V_2 -> V_9 )
goto V_10;
V_2 -> V_11 = F_2 ( V_5 ) ;
if ( ! V_2 -> V_11 )
goto V_12;
memset ( V_2 -> V_11 , 0 , V_5 ) ;
V_2 -> V_13 = F_2 ( V_5 ) ;
if ( ! V_2 -> V_13 )
goto V_14;
return 0 ;
V_14:
F_3 ( V_2 -> V_11 ) ;
V_12:
F_3 ( V_2 -> V_9 ) ;
V_10:
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 )
F_3 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
if ( V_2 -> V_11 )
F_3 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
if ( V_2 -> V_13 )
F_3 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
static void F_5 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_6 ( V_16 , struct V_17 , V_16 ) ;
V_18 -> V_19 = F_7 ( V_18 -> V_20 , 1 , V_18 -> V_21 , NULL ) ;
}
static int F_8 ( struct V_1 * V_2 , void * V_9 , T_2 V_22 , int V_23 ,
int V_24 )
{
struct V_25 V_21 = {
. V_26 = F_9 ( V_2 -> V_6 -> V_27 ) -> V_26 ,
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
return F_7 ( & V_20 , 1 , & V_21 , NULL ) ;
V_18 . V_21 = & V_21 ;
V_18 . V_20 = & V_20 ;
F_10 ( & V_18 . V_16 , F_5 ) ;
F_11 ( V_2 -> V_40 , & V_18 . V_16 ) ;
F_12 ( & V_18 . V_16 ) ;
return V_18 . V_19 ;
}
static T_2 F_13 ( struct V_1 * V_2 , T_2 V_9 )
{
return V_41 + ( ( V_2 -> V_42 + 1 ) * V_9 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_23 )
{
int V_3 ;
T_2 V_22 ;
V_22 = F_13 ( V_2 , V_2 -> V_43 ) ;
V_3 = F_8 ( V_2 , V_2 -> V_9 , V_22 , V_23 , 0 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_9 , 0 , V_2 -> V_6 -> V_7 << V_8 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_9 )
{
return F_8 ( V_2 , V_2 -> V_11 , F_13 ( V_2 , V_9 ) , V_44 , 0 ) ;
}
static int F_17 ( struct V_1 * V_2 , int * V_45 )
{
int V_3 ;
struct V_46 * V_47 ;
unsigned V_7 ;
int V_48 = 1 ;
char * V_49 ;
if ( ! V_2 -> V_6 -> V_7 ) {
V_2 -> V_6 -> V_7 = F_18 ( V_50 ,
F_19 ( F_9 ( V_2 -> V_6 -> V_27 ) ->
V_26 ) >> 9 ) ;
V_2 -> V_6 -> V_51 = V_2 -> V_6 -> V_7 - 1 ;
V_2 -> V_6 -> V_52 = F_20 ( V_2 -> V_6 -> V_7 ) - 1 ;
V_48 = 0 ;
}
V_2 -> V_37 = F_21 () ;
if ( F_22 ( V_2 -> V_37 ) )
return F_23 ( V_2 -> V_37 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_8 ( V_2 , V_2 -> V_13 , 0 , V_53 , 1 ) ;
if ( V_3 )
goto V_54;
V_47 = V_2 -> V_13 ;
if ( F_24 ( V_47 -> V_55 ) == 0 ) {
* V_45 = 1 ;
return 0 ;
}
if ( F_24 ( V_47 -> V_55 ) != V_56 ) {
F_25 ( L_1 ) ;
V_3 = - V_57 ;
goto V_54;
}
* V_45 = 0 ;
V_2 -> V_58 = F_24 ( V_47 -> V_58 ) ;
V_2 -> V_59 = F_24 ( V_47 -> V_59 ) ;
V_7 = F_24 ( V_47 -> V_7 ) ;
if ( V_2 -> V_6 -> V_7 == V_7 )
return 0 ;
if ( V_48 )
F_25 ( L_2
L_3 ,
V_7 , V_2 -> V_6 -> V_7 ) ;
F_4 ( V_2 ) ;
V_3 = F_26 ( V_2 -> V_6 , V_7 ,
& V_49 ) ;
if ( V_3 ) {
F_27 ( L_4 ,
V_7 , V_49 ) ;
return V_3 ;
}
V_3 = F_1 ( V_2 ) ;
return V_3 ;
V_54:
F_4 ( V_2 ) ;
return V_3 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
memset ( V_2 -> V_13 , 0 , V_2 -> V_6 -> V_7 << V_8 ) ;
V_47 = V_2 -> V_13 ;
V_47 -> V_55 = F_29 ( V_56 ) ;
V_47 -> V_58 = F_29 ( V_2 -> V_58 ) ;
V_47 -> V_59 = F_29 ( V_2 -> V_59 ) ;
V_47 -> V_7 = F_29 ( V_2 -> V_6 -> V_7 ) ;
return F_8 ( V_2 , V_2 -> V_13 , 0 , V_44 , 1 ) ;
}
static struct V_60 * F_30 ( struct V_1 * V_2 , T_3 V_61 )
{
F_31 ( V_61 >= V_2 -> V_42 ) ;
return ( (struct V_60 * ) V_2 -> V_9 ) + V_61 ;
}
static void F_32 ( struct V_1 * V_2 ,
T_3 V_61 , struct V_60 * V_19 )
{
struct V_60 * V_62 = F_30 ( V_2 , V_61 ) ;
V_19 -> V_63 = F_33 ( V_62 -> V_63 ) ;
V_19 -> V_64 = F_33 ( V_62 -> V_64 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
T_3 V_61 , struct V_60 * V_65 )
{
struct V_60 * V_62 = F_30 ( V_2 , V_61 ) ;
V_62 -> V_63 = F_35 ( V_65 -> V_63 ) ;
V_62 -> V_64 = F_35 ( V_65 -> V_64 ) ;
}
static void F_36 ( struct V_1 * V_2 , T_3 V_61 )
{
struct V_60 * V_62 = F_30 ( V_2 , V_61 ) ;
V_62 -> V_63 = 0 ;
V_62 -> V_64 = 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
int (* F_38)( void * V_66 ,
T_2 V_67 , T_2 V_68 ) ,
void * V_66 ,
int * V_69 )
{
int V_3 ;
unsigned int V_70 ;
struct V_60 V_65 ;
* V_69 = 1 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_42 ; V_70 ++ ) {
F_32 ( V_2 , V_70 , & V_65 ) ;
if ( V_65 . V_64 == 0LL ) {
V_2 -> V_71 = V_70 ;
* V_69 = 0 ;
break;
}
if ( V_2 -> V_72 <= V_65 . V_64 )
V_2 -> V_72 = V_65 . V_64 + 1 ;
V_3 = F_38 ( V_66 , V_65 . V_63 , V_65 . V_64 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
int (* F_38)( void * V_66 , T_2 V_67 ,
T_2 V_68 ) ,
void * V_66 )
{
int V_3 , V_69 = 1 ;
for ( V_2 -> V_43 = 0 ; V_69 ; V_2 -> V_43 ++ ) {
V_3 = F_14 ( V_2 , V_53 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_37 ( V_2 , F_38 , V_66 , & V_69 ) ;
if ( V_3 )
return V_3 ;
}
V_2 -> V_43 -- ;
return 0 ;
}
static struct V_1 * F_40 ( struct V_73 * V_6 )
{
return (struct V_1 * ) V_6 -> V_74 ;
}
static void F_41 ( struct V_73 * V_6 ,
T_4 * V_75 ,
T_4 * V_76 ,
T_4 * V_77 )
{
struct V_1 * V_2 = F_40 ( V_6 ) ;
* V_76 = V_2 -> V_72 * V_6 -> V_7 ;
* V_75 = F_42 ( F_9 ( V_6 -> V_27 ) -> V_26 ) ;
* V_77 = ( V_2 -> V_43 + 1 + V_41 ) *
V_6 -> V_7 ;
}
static void F_43 ( struct V_73 * V_6 )
{
struct V_1 * V_2 = F_40 ( V_6 ) ;
F_44 ( V_2 -> V_40 ) ;
if ( V_2 -> V_37 )
F_45 ( V_2 -> V_37 ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_78 )
F_3 ( V_2 -> V_78 ) ;
F_46 ( V_2 ) ;
}
static int F_47 ( struct V_73 * V_6 ,
int (* F_38)( void * V_66 ,
T_2 V_67 , T_2 V_68 ) ,
void * V_66 )
{
int V_3 , V_79 ( V_45 ) ;
struct V_1 * V_2 = F_40 ( V_6 ) ;
V_3 = F_17 ( V_2 , & V_45 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_42 = ( V_2 -> V_6 -> V_7 << V_8 ) /
sizeof( struct V_60 ) ;
V_2 -> V_78 = F_48 ( V_2 -> V_42 ,
sizeof( * V_2 -> V_78 ) ) ;
if ( ! V_2 -> V_78 )
return - V_4 ;
if ( V_45 ) {
V_3 = F_28 ( V_2 ) ;
if ( V_3 ) {
F_25 ( L_5 ) ;
return V_3 ;
}
V_2 -> V_43 = 0 ;
F_15 ( V_2 ) ;
V_3 = F_16 ( V_2 , 0 ) ;
if ( V_3 )
F_25 ( L_6 ) ;
return V_3 ;
}
if ( V_2 -> V_59 != V_80 ) {
F_25 ( L_7 ,
V_2 -> V_59 ) ;
return - V_81 ;
}
if ( ! V_2 -> V_58 )
return 1 ;
V_3 = F_39 ( V_2 , F_38 , V_66 ) ;
return V_3 ;
}
static int F_49 ( struct V_73 * V_6 ,
struct V_82 * V_62 )
{
struct V_1 * V_2 = F_40 ( V_6 ) ;
T_3 V_83 ;
T_2 V_72 ;
T_4 V_84 = F_42 ( F_9 ( V_6 -> V_27 ) -> V_26 ) ;
if ( V_84 < ( ( V_2 -> V_72 + 1 ) * V_6 -> V_7 ) )
return - V_85 ;
V_62 -> V_64 = V_2 -> V_72 ;
V_83 = ( V_2 -> V_42 + 1 ) ;
V_72 = ++ V_2 -> V_72 ;
if ( F_50 ( V_72 , V_83 ) == 1 )
V_2 -> V_72 ++ ;
F_51 ( & V_2 -> V_86 ) ;
return 0 ;
}
static void F_52 ( struct V_73 * V_6 ,
struct V_82 * V_62 ,
void (* F_38) ( void * , int V_87 ) ,
void * V_66 )
{
unsigned int V_70 ;
struct V_1 * V_2 = F_40 ( V_6 ) ;
struct V_60 V_65 ;
struct V_88 * V_89 ;
V_65 . V_63 = V_62 -> V_63 ;
V_65 . V_64 = V_62 -> V_64 ;
F_34 ( V_2 , V_2 -> V_71 ++ , & V_65 ) ;
V_89 = V_2 -> V_78 + V_2 -> V_90 ++ ;
V_89 -> F_38 = F_38 ;
V_89 -> V_74 = V_66 ;
if ( ! F_53 ( & V_2 -> V_86 ) &&
( V_2 -> V_71 != V_2 -> V_42 ) )
return;
if ( ( V_2 -> V_71 == V_2 -> V_42 ) &&
F_16 ( V_2 , V_2 -> V_43 + 1 ) )
V_2 -> V_58 = 0 ;
if ( V_2 -> V_58 && F_14 ( V_2 , V_91 ) )
V_2 -> V_58 = 0 ;
if ( V_2 -> V_71 == V_2 -> V_42 ) {
V_2 -> V_71 = 0 ;
V_2 -> V_43 ++ ;
F_15 ( V_2 ) ;
}
for ( V_70 = 0 ; V_70 < V_2 -> V_90 ; V_70 ++ ) {
V_89 = V_2 -> V_78 + V_70 ;
V_89 -> F_38 ( V_89 -> V_74 , V_2 -> V_58 ) ;
}
V_2 -> V_90 = 0 ;
}
static int F_54 ( struct V_73 * V_6 ,
T_2 * V_92 ,
T_2 * V_93 )
{
struct V_1 * V_2 = F_40 ( V_6 ) ;
struct V_60 V_65 ;
int V_94 ;
int V_3 ;
if ( ! V_2 -> V_71 ) {
if ( ! V_2 -> V_43 )
return 0 ;
V_2 -> V_43 -- ;
V_3 = F_14 ( V_2 , V_53 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_71 = V_2 -> V_42 ;
}
F_32 ( V_2 , V_2 -> V_71 - 1 , & V_65 ) ;
* V_92 = V_65 . V_63 ;
* V_93 = V_65 . V_64 ;
for ( V_94 = 1 ; V_94 < V_2 -> V_71 ;
V_94 ++ ) {
F_32 ( V_2 , V_2 -> V_71 - 1 - V_94 ,
& V_65 ) ;
if ( V_65 . V_63 != * V_92 - V_94 ||
V_65 . V_64 != * V_93 - V_94 )
break;
}
return V_94 ;
}
static int F_55 ( struct V_73 * V_6 ,
int V_95 )
{
int V_3 , V_70 ;
struct V_1 * V_2 = F_40 ( V_6 ) ;
F_31 ( V_95 > V_2 -> V_71 ) ;
for ( V_70 = 0 ; V_70 < V_95 ; V_70 ++ )
F_36 ( V_2 , V_2 -> V_71 - 1 - V_70 ) ;
V_3 = F_14 ( V_2 , V_44 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_71 -= V_95 ;
V_2 -> V_72 = F_13 ( V_2 , V_2 -> V_43 ) +
V_2 -> V_71 + 1 ;
return 0 ;
}
static void F_56 ( struct V_73 * V_6 )
{
struct V_1 * V_2 = F_40 ( V_6 ) ;
V_2 -> V_58 = 0 ;
if ( F_28 ( V_2 ) )
F_25 ( L_8 ) ;
}
static int F_57 ( struct V_73 * V_6 ,
unsigned V_96 , char * * V_97 )
{
struct V_1 * V_2 ;
V_2 = F_58 ( sizeof( * V_2 ) , V_98 ) ;
if ( ! V_2 )
return - V_4 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_58 = 1 ;
V_2 -> V_59 = V_80 ;
V_2 -> V_9 = NULL ;
V_2 -> V_11 = NULL ;
V_2 -> V_13 = NULL ;
V_2 -> V_72 = V_41 + 1 ;
V_2 -> V_71 = 0 ;
V_2 -> V_90 = 0 ;
F_59 ( & V_2 -> V_86 , 0 ) ;
V_2 -> V_78 = NULL ;
V_2 -> V_40 = F_60 ( L_9 , V_99 , 0 ) ;
if ( ! V_2 -> V_40 ) {
F_46 ( V_2 ) ;
F_27 ( L_10 ) ;
return - V_4 ;
}
V_6 -> V_74 = V_2 ;
return 0 ;
}
static unsigned F_61 ( struct V_73 * V_6 ,
T_5 V_100 , char * V_19 ,
unsigned V_101 )
{
unsigned V_102 = 0 ;
switch ( V_100 ) {
case V_103 :
break;
case V_104 :
F_62 ( L_11 , ( unsigned long long ) V_6 -> V_7 ) ;
}
return V_102 ;
}
int F_63 ( void )
{
int V_3 ;
V_3 = F_64 ( & V_105 ) ;
if ( V_3 ) {
F_27 ( L_12 ) ;
return V_3 ;
}
V_3 = F_64 ( & V_106 ) ;
if ( V_3 ) {
F_27 ( L_13
L_14 ) ;
F_65 ( & V_105 ) ;
return V_3 ;
}
return V_3 ;
}
void F_66 ( void )
{
F_65 ( & V_105 ) ;
F_65 ( & V_106 ) ;
}
