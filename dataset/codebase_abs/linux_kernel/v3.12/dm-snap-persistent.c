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
F_13 ( V_2 -> V_40 ) ;
return V_18 . V_19 ;
}
static T_2 F_14 ( struct V_1 * V_2 , T_2 V_9 )
{
return V_41 + ( ( V_2 -> V_42 + 1 ) * V_9 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_3 V_43 = V_2 -> V_42 + 1 ;
T_2 V_44 = V_2 -> V_44 ;
if ( F_16 ( V_44 , V_43 ) == V_41 )
V_2 -> V_44 ++ ;
}
static int F_17 ( struct V_1 * V_2 , int V_23 )
{
int V_3 ;
T_2 V_22 ;
V_22 = F_14 ( V_2 , V_2 -> V_45 ) ;
V_3 = F_9 ( V_2 , V_2 -> V_9 , V_22 , V_23 , 0 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_9 , 0 , V_2 -> V_6 -> V_7 << V_8 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_9 )
{
return F_9 ( V_2 , V_2 -> V_11 , F_14 ( V_2 , V_9 ) , V_46 , 0 ) ;
}
static int F_20 ( struct V_1 * V_2 , int * V_47 )
{
int V_3 ;
struct V_48 * V_49 ;
unsigned V_7 ;
int V_50 = 1 ;
char * V_51 ;
if ( ! V_2 -> V_6 -> V_7 ) {
V_2 -> V_6 -> V_7 = F_21 ( V_52 ,
F_22 ( F_10 ( V_2 -> V_6 -> V_27 ) ->
V_26 ) >> 9 ) ;
V_2 -> V_6 -> V_53 = V_2 -> V_6 -> V_7 - 1 ;
V_2 -> V_6 -> V_54 = F_23 ( V_2 -> V_6 -> V_7 ) - 1 ;
V_50 = 0 ;
}
V_2 -> V_37 = F_24 () ;
if ( F_25 ( V_2 -> V_37 ) )
return F_26 ( V_2 -> V_37 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_9 ( V_2 , V_2 -> V_13 , 0 , V_55 , 1 ) ;
if ( V_3 )
goto V_56;
V_49 = V_2 -> V_13 ;
if ( F_27 ( V_49 -> V_57 ) == 0 ) {
* V_47 = 1 ;
return 0 ;
}
if ( F_27 ( V_49 -> V_57 ) != V_58 ) {
F_28 ( L_1 ) ;
V_3 = - V_59 ;
goto V_56;
}
* V_47 = 0 ;
V_2 -> V_60 = F_27 ( V_49 -> V_60 ) ;
V_2 -> V_61 = F_27 ( V_49 -> V_61 ) ;
V_7 = F_27 ( V_49 -> V_7 ) ;
if ( V_2 -> V_6 -> V_7 == V_7 )
return 0 ;
if ( V_50 )
F_28 ( L_2
L_3 ,
V_7 , V_2 -> V_6 -> V_7 ) ;
F_5 ( V_2 ) ;
V_3 = F_29 ( V_2 -> V_6 , V_7 ,
& V_51 ) ;
if ( V_3 ) {
F_30 ( L_4 ,
V_7 , V_51 ) ;
return V_3 ;
}
V_3 = F_1 ( V_2 ) ;
return V_3 ;
V_56:
F_5 ( V_2 ) ;
return V_3 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
memset ( V_2 -> V_13 , 0 , V_2 -> V_6 -> V_7 << V_8 ) ;
V_49 = V_2 -> V_13 ;
V_49 -> V_57 = F_32 ( V_58 ) ;
V_49 -> V_60 = F_32 ( V_2 -> V_60 ) ;
V_49 -> V_61 = F_32 ( V_2 -> V_61 ) ;
V_49 -> V_7 = F_32 ( V_2 -> V_6 -> V_7 ) ;
return F_9 ( V_2 , V_2 -> V_13 , 0 , V_46 , 1 ) ;
}
static struct V_62 * F_33 ( struct V_1 * V_2 , T_3 V_63 )
{
F_34 ( V_63 >= V_2 -> V_42 ) ;
return ( (struct V_62 * ) V_2 -> V_9 ) + V_63 ;
}
static void F_35 ( struct V_1 * V_2 ,
T_3 V_63 , struct V_64 * V_19 )
{
struct V_62 * V_65 = F_33 ( V_2 , V_63 ) ;
V_19 -> V_66 = F_36 ( V_65 -> V_66 ) ;
V_19 -> V_67 = F_36 ( V_65 -> V_67 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
T_3 V_63 , struct V_64 * V_68 )
{
struct V_62 * V_65 = F_33 ( V_2 , V_63 ) ;
V_65 -> V_66 = F_38 ( V_68 -> V_66 ) ;
V_65 -> V_67 = F_38 ( V_68 -> V_67 ) ;
}
static void F_39 ( struct V_1 * V_2 , T_3 V_63 )
{
struct V_62 * V_65 = F_33 ( V_2 , V_63 ) ;
V_65 -> V_66 = 0 ;
V_65 -> V_67 = 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
int (* F_41)( void * V_69 ,
T_2 V_70 , T_2 V_71 ) ,
void * V_69 ,
int * V_72 )
{
int V_3 ;
unsigned int V_73 ;
struct V_64 V_68 ;
* V_72 = 1 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_42 ; V_73 ++ ) {
F_35 ( V_2 , V_73 , & V_68 ) ;
if ( V_68 . V_67 == 0LL ) {
V_2 -> V_74 = V_73 ;
* V_72 = 0 ;
break;
}
if ( V_2 -> V_44 <= V_68 . V_67 )
V_2 -> V_44 = V_68 . V_67 + 1 ;
V_3 = F_41 ( V_69 , V_68 . V_66 , V_68 . V_67 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
int (* F_41)( void * V_69 , T_2 V_70 ,
T_2 V_71 ) ,
void * V_69 )
{
int V_3 , V_72 = 1 ;
for ( V_2 -> V_45 = 0 ; V_72 ; V_2 -> V_45 ++ ) {
V_3 = F_17 ( V_2 , V_55 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_40 ( V_2 , F_41 , V_69 , & V_72 ) ;
if ( V_3 )
return V_3 ;
}
V_2 -> V_45 -- ;
F_15 ( V_2 ) ;
return 0 ;
}
static struct V_1 * F_43 ( struct V_75 * V_6 )
{
return (struct V_1 * ) V_6 -> V_76 ;
}
static void F_44 ( struct V_75 * V_6 ,
T_4 * V_77 ,
T_4 * V_78 ,
T_4 * V_79 )
{
struct V_1 * V_2 = F_43 ( V_6 ) ;
* V_78 = V_2 -> V_44 * V_6 -> V_7 ;
* V_77 = F_45 ( F_10 ( V_6 -> V_27 ) -> V_26 ) ;
* V_79 = ( V_2 -> V_45 + 1 + V_41 ) *
V_6 -> V_7 ;
}
static void F_46 ( struct V_75 * V_6 )
{
struct V_1 * V_2 = F_43 ( V_6 ) ;
F_47 ( V_2 -> V_40 ) ;
if ( V_2 -> V_37 )
F_48 ( V_2 -> V_37 ) ;
F_5 ( V_2 ) ;
if ( V_2 -> V_80 )
F_4 ( V_2 -> V_80 ) ;
F_49 ( V_2 ) ;
}
static int F_50 ( struct V_75 * V_6 ,
int (* F_41)( void * V_69 ,
T_2 V_70 , T_2 V_71 ) ,
void * V_69 )
{
int V_3 , V_81 ( V_47 ) ;
struct V_1 * V_2 = F_43 ( V_6 ) ;
V_3 = F_20 ( V_2 , & V_47 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_42 = ( V_2 -> V_6 -> V_7 << V_8 ) /
sizeof( struct V_62 ) ;
V_2 -> V_80 = F_51 ( V_2 -> V_42 ,
sizeof( * V_2 -> V_80 ) ) ;
if ( ! V_2 -> V_80 )
return - V_4 ;
if ( V_47 ) {
V_3 = F_31 ( V_2 ) ;
if ( V_3 ) {
F_28 ( L_5 ) ;
return V_3 ;
}
V_2 -> V_45 = 0 ;
F_18 ( V_2 ) ;
V_3 = F_19 ( V_2 , 0 ) ;
if ( V_3 )
F_28 ( L_6 ) ;
return V_3 ;
}
if ( V_2 -> V_61 != V_82 ) {
F_28 ( L_7 ,
V_2 -> V_61 ) ;
return - V_83 ;
}
if ( ! V_2 -> V_60 )
return 1 ;
V_3 = F_42 ( V_2 , F_41 , V_69 ) ;
return V_3 ;
}
static int F_52 ( struct V_75 * V_6 ,
struct V_84 * V_68 )
{
struct V_1 * V_2 = F_43 ( V_6 ) ;
T_4 V_85 = F_45 ( F_10 ( V_6 -> V_27 ) -> V_26 ) ;
if ( V_85 < ( ( V_2 -> V_44 + 1 ) * V_6 -> V_7 ) )
return - V_86 ;
V_68 -> V_67 = V_2 -> V_44 ;
V_2 -> V_44 ++ ;
F_15 ( V_2 ) ;
F_53 ( & V_2 -> V_87 ) ;
return 0 ;
}
static void F_54 ( struct V_75 * V_6 ,
struct V_84 * V_68 ,
void (* F_41) ( void * , int V_88 ) ,
void * V_69 )
{
unsigned int V_73 ;
struct V_1 * V_2 = F_43 ( V_6 ) ;
struct V_64 V_89 ;
struct V_90 * V_91 ;
V_89 . V_66 = V_68 -> V_66 ;
V_89 . V_67 = V_68 -> V_67 ;
F_37 ( V_2 , V_2 -> V_74 ++ , & V_89 ) ;
V_91 = V_2 -> V_80 + V_2 -> V_92 ++ ;
V_91 -> F_41 = F_41 ;
V_91 -> V_76 = V_69 ;
if ( ! F_55 ( & V_2 -> V_87 ) &&
( V_2 -> V_74 != V_2 -> V_42 ) )
return;
if ( ( V_2 -> V_74 == V_2 -> V_42 ) &&
F_19 ( V_2 , V_2 -> V_45 + 1 ) )
V_2 -> V_60 = 0 ;
if ( V_2 -> V_60 && F_17 ( V_2 , V_93 ) )
V_2 -> V_60 = 0 ;
if ( V_2 -> V_74 == V_2 -> V_42 ) {
V_2 -> V_74 = 0 ;
V_2 -> V_45 ++ ;
F_18 ( V_2 ) ;
}
for ( V_73 = 0 ; V_73 < V_2 -> V_92 ; V_73 ++ ) {
V_91 = V_2 -> V_80 + V_73 ;
V_91 -> F_41 ( V_91 -> V_76 , V_2 -> V_60 ) ;
}
V_2 -> V_92 = 0 ;
}
static int F_56 ( struct V_75 * V_6 ,
T_2 * V_94 ,
T_2 * V_95 )
{
struct V_1 * V_2 = F_43 ( V_6 ) ;
struct V_64 V_89 ;
int V_96 ;
int V_3 ;
if ( ! V_2 -> V_74 ) {
if ( ! V_2 -> V_45 )
return 0 ;
V_2 -> V_45 -- ;
V_3 = F_17 ( V_2 , V_55 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_74 = V_2 -> V_42 ;
}
F_35 ( V_2 , V_2 -> V_74 - 1 , & V_89 ) ;
* V_94 = V_89 . V_66 ;
* V_95 = V_89 . V_67 ;
for ( V_96 = 1 ; V_96 < V_2 -> V_74 ;
V_96 ++ ) {
F_35 ( V_2 , V_2 -> V_74 - 1 - V_96 ,
& V_89 ) ;
if ( V_89 . V_66 != * V_94 - V_96 ||
V_89 . V_67 != * V_95 - V_96 )
break;
}
return V_96 ;
}
static int F_57 ( struct V_75 * V_6 ,
int V_97 )
{
int V_3 , V_73 ;
struct V_1 * V_2 = F_43 ( V_6 ) ;
F_34 ( V_97 > V_2 -> V_74 ) ;
for ( V_73 = 0 ; V_73 < V_97 ; V_73 ++ )
F_39 ( V_2 , V_2 -> V_74 - 1 - V_73 ) ;
V_3 = F_17 ( V_2 , V_93 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_74 -= V_97 ;
V_2 -> V_44 = F_14 ( V_2 , V_2 -> V_45 ) +
V_2 -> V_74 + 1 ;
return 0 ;
}
static void F_58 ( struct V_75 * V_6 )
{
struct V_1 * V_2 = F_43 ( V_6 ) ;
V_2 -> V_60 = 0 ;
if ( F_31 ( V_2 ) )
F_28 ( L_8 ) ;
}
static int F_59 ( struct V_75 * V_6 ,
unsigned V_98 , char * * V_99 )
{
struct V_1 * V_2 ;
V_2 = F_60 ( sizeof( * V_2 ) , V_100 ) ;
if ( ! V_2 )
return - V_4 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_60 = 1 ;
V_2 -> V_61 = V_82 ;
V_2 -> V_9 = NULL ;
V_2 -> V_11 = NULL ;
V_2 -> V_13 = NULL ;
V_2 -> V_44 = V_41 + 1 ;
V_2 -> V_74 = 0 ;
V_2 -> V_92 = 0 ;
F_61 ( & V_2 -> V_87 , 0 ) ;
V_2 -> V_80 = NULL ;
V_2 -> V_40 = F_62 ( L_9 , V_101 , 0 ) ;
if ( ! V_2 -> V_40 ) {
F_49 ( V_2 ) ;
F_30 ( L_10 ) ;
return - V_4 ;
}
V_6 -> V_76 = V_2 ;
return 0 ;
}
static unsigned F_63 ( struct V_75 * V_6 ,
T_5 V_102 , char * V_19 ,
unsigned V_103 )
{
unsigned V_104 = 0 ;
switch ( V_102 ) {
case V_105 :
break;
case V_106 :
F_64 ( L_11 , ( unsigned long long ) V_6 -> V_7 ) ;
}
return V_104 ;
}
int F_65 ( void )
{
int V_3 ;
V_3 = F_66 ( & V_107 ) ;
if ( V_3 ) {
F_30 ( L_12 ) ;
return V_3 ;
}
V_3 = F_66 ( & V_108 ) ;
if ( V_3 ) {
F_30 ( L_13
L_14 ) ;
F_67 ( & V_107 ) ;
return V_3 ;
}
return V_3 ;
}
void F_68 ( void )
{
F_67 ( & V_107 ) ;
F_67 ( & V_108 ) ;
}
