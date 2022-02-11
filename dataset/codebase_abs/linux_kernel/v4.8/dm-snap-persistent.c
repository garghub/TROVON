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
F_4 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
F_4 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
F_4 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
static void F_6 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 , V_16 ) ;
V_18 -> V_19 = F_8 ( V_18 -> V_20 , 1 , V_18 -> V_21 , NULL ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_9 , T_2 V_22 , int V_23 ,
int V_24 , int V_25 )
{
struct V_26 V_21 = {
. V_27 = F_10 ( V_2 -> V_6 -> V_28 ) -> V_27 ,
. V_29 = V_2 -> V_6 -> V_7 * V_22 ,
. V_30 = V_2 -> V_6 -> V_7 ,
} ;
struct V_31 V_20 = {
. V_32 = V_23 ,
. V_33 = V_24 ,
. V_34 . type = V_35 ,
. V_34 . V_36 . V_37 = V_9 ,
. V_38 = V_2 -> V_39 ,
. V_40 . V_41 = NULL ,
} ;
struct V_17 V_18 ;
if ( ! V_25 )
return F_8 ( & V_20 , 1 , & V_21 , NULL ) ;
V_18 . V_21 = & V_21 ;
V_18 . V_20 = & V_20 ;
F_11 ( & V_18 . V_16 , F_6 ) ;
F_12 ( V_2 -> V_42 , & V_18 . V_16 ) ;
F_13 ( V_2 -> V_42 ) ;
F_14 ( & V_18 . V_16 ) ;
return V_18 . V_19 ;
}
static T_2 F_15 ( struct V_1 * V_2 , T_2 V_9 )
{
return V_43 + ( ( V_2 -> V_44 + 1 ) * V_9 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_3 V_45 = V_2 -> V_44 + 1 ;
T_2 V_46 = V_2 -> V_46 ;
if ( F_17 ( V_46 , V_45 ) == V_43 )
V_2 -> V_46 ++ ;
}
static int F_18 ( struct V_1 * V_2 , int V_23 , int V_24 )
{
int V_3 ;
T_2 V_22 ;
V_22 = F_15 ( V_2 , V_2 -> V_47 ) ;
V_3 = F_9 ( V_2 , V_2 -> V_9 , V_22 , V_23 , V_24 , 0 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_9 , 0 , V_2 -> V_6 -> V_7 << V_8 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_2 V_9 )
{
return F_9 ( V_2 , V_2 -> V_11 , F_15 ( V_2 , V_9 ) ,
V_48 , 0 , 0 ) ;
}
static int F_21 ( struct V_1 * V_2 , int * V_49 )
{
int V_3 ;
struct V_50 * V_51 ;
unsigned V_7 ;
int V_52 = 1 ;
char * V_53 ;
if ( ! V_2 -> V_6 -> V_7 ) {
V_2 -> V_6 -> V_7 = F_22 ( V_54 ,
F_23 ( F_10 ( V_2 -> V_6 -> V_28 ) ->
V_27 ) >> 9 ) ;
V_2 -> V_6 -> V_55 = V_2 -> V_6 -> V_7 - 1 ;
V_2 -> V_6 -> V_56 = F_24 ( V_2 -> V_6 -> V_7 ) ;
V_52 = 0 ;
}
V_2 -> V_39 = F_25 () ;
if ( F_26 ( V_2 -> V_39 ) )
return F_27 ( V_2 -> V_39 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_9 ( V_2 , V_2 -> V_13 , 0 , V_57 , 0 , 1 ) ;
if ( V_3 )
goto V_58;
V_51 = V_2 -> V_13 ;
if ( F_28 ( V_51 -> V_59 ) == 0 ) {
* V_49 = 1 ;
return 0 ;
}
if ( F_28 ( V_51 -> V_59 ) != V_60 ) {
F_29 ( L_1 ) ;
V_3 = - V_61 ;
goto V_58;
}
* V_49 = 0 ;
V_2 -> V_62 = F_28 ( V_51 -> V_62 ) ;
V_2 -> V_63 = F_28 ( V_51 -> V_63 ) ;
V_7 = F_28 ( V_51 -> V_7 ) ;
if ( V_2 -> V_6 -> V_7 == V_7 )
return 0 ;
if ( V_52 )
F_29 ( L_2
L_3 ,
V_7 , V_2 -> V_6 -> V_7 ) ;
F_5 ( V_2 ) ;
V_3 = F_30 ( V_2 -> V_6 , V_7 ,
& V_53 ) ;
if ( V_3 ) {
F_31 ( L_4 ,
V_7 , V_53 ) ;
return V_3 ;
}
V_3 = F_1 ( V_2 ) ;
return V_3 ;
V_58:
F_5 ( V_2 ) ;
return V_3 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
memset ( V_2 -> V_13 , 0 , V_2 -> V_6 -> V_7 << V_8 ) ;
V_51 = V_2 -> V_13 ;
V_51 -> V_59 = F_33 ( V_60 ) ;
V_51 -> V_62 = F_33 ( V_2 -> V_62 ) ;
V_51 -> V_63 = F_33 ( V_2 -> V_63 ) ;
V_51 -> V_7 = F_33 ( V_2 -> V_6 -> V_7 ) ;
return F_9 ( V_2 , V_2 -> V_13 , 0 , V_48 , 0 , 1 ) ;
}
static struct V_64 * F_34 ( struct V_1 * V_2 , void * V_65 ,
T_3 V_66 )
{
F_35 ( V_66 >= V_2 -> V_44 ) ;
return ( (struct V_64 * ) V_65 ) + V_66 ;
}
static void F_36 ( struct V_1 * V_2 , void * V_65 ,
T_3 V_66 , struct V_67 * V_19 )
{
struct V_64 * V_68 = F_34 ( V_2 , V_65 , V_66 ) ;
V_19 -> V_69 = F_37 ( V_68 -> V_69 ) ;
V_19 -> V_70 = F_37 ( V_68 -> V_70 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
T_3 V_66 , struct V_67 * V_71 )
{
struct V_64 * V_68 = F_34 ( V_2 , V_2 -> V_9 , V_66 ) ;
V_68 -> V_69 = F_39 ( V_71 -> V_69 ) ;
V_68 -> V_70 = F_39 ( V_71 -> V_70 ) ;
}
static void F_40 ( struct V_1 * V_2 , T_3 V_66 )
{
struct V_64 * V_68 = F_34 ( V_2 , V_2 -> V_9 , V_66 ) ;
V_68 -> V_69 = 0 ;
V_68 -> V_70 = 0 ;
}
static int F_41 ( struct V_1 * V_2 , void * V_65 ,
int (* F_42)( void * V_72 ,
T_2 V_73 , T_2 V_74 ) ,
void * V_72 ,
int * V_75 )
{
int V_3 ;
unsigned int V_76 ;
struct V_67 V_71 ;
* V_75 = 1 ;
for ( V_76 = 0 ; V_76 < V_2 -> V_44 ; V_76 ++ ) {
F_36 ( V_2 , V_65 , V_76 , & V_71 ) ;
if ( V_71 . V_70 == 0LL ) {
V_2 -> V_77 = V_76 ;
* V_75 = 0 ;
break;
}
if ( V_2 -> V_46 <= V_71 . V_70 )
V_2 -> V_46 = V_71 . V_70 + 1 ;
V_3 = F_42 ( V_72 , V_71 . V_69 , V_71 . V_70 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
int (* F_42)( void * V_72 , T_2 V_73 ,
T_2 V_74 ) ,
void * V_72 )
{
int V_3 , V_75 = 1 ;
struct V_78 * V_38 ;
T_2 V_79 = 0 ;
V_38 = F_44 ( F_10 ( V_2 -> V_6 -> V_28 ) -> V_27 ,
V_2 -> V_6 -> V_7 << V_8 ,
1 , 0 , NULL , NULL ) ;
if ( F_26 ( V_38 ) )
return F_27 ( V_38 ) ;
F_45 ( V_38 , 1 + V_80 ) ;
for ( V_2 -> V_47 = 0 ; V_75 ; V_2 -> V_47 ++ ) {
struct V_81 * V_82 ;
void * V_9 ;
T_2 V_22 ;
if ( F_46 ( V_79 < V_2 -> V_47 ) )
V_79 = V_2 -> V_47 ;
if ( V_80 ) do {
T_2 V_83 = F_15 ( V_2 , V_79 ) ;
if ( F_46 ( V_83 >= F_47 ( V_38 ) ) )
break;
F_48 ( V_38 , V_83 , 1 ) ;
V_79 ++ ;
if ( F_46 ( ! V_79 ) )
break;
} while ( V_79 <= V_2 -> V_47 + V_80 );
V_22 = F_15 ( V_2 , V_2 -> V_47 ) ;
V_9 = F_49 ( V_38 , V_22 , & V_82 ) ;
if ( F_26 ( V_9 ) ) {
V_3 = F_27 ( V_9 ) ;
goto V_84;
}
V_3 = F_41 ( V_2 , V_9 , F_42 , V_72 ,
& V_75 ) ;
if ( ! V_75 )
memcpy ( V_2 -> V_9 , V_9 , V_2 -> V_6 -> V_7 << V_8 ) ;
F_50 ( V_82 ) ;
F_51 ( V_38 , V_22 ) ;
if ( F_46 ( V_3 ) )
goto V_84;
}
V_2 -> V_47 -- ;
F_16 ( V_2 ) ;
V_3 = 0 ;
V_84:
F_52 ( V_38 ) ;
return V_3 ;
}
static struct V_1 * F_53 ( struct V_85 * V_6 )
{
return (struct V_1 * ) V_6 -> V_86 ;
}
static void F_54 ( struct V_85 * V_6 ,
T_4 * V_87 ,
T_4 * V_88 ,
T_4 * V_89 )
{
struct V_1 * V_2 = F_53 ( V_6 ) ;
* V_88 = V_2 -> V_46 * V_6 -> V_7 ;
* V_87 = F_55 ( F_10 ( V_6 -> V_28 ) -> V_27 ) ;
* V_89 = ( V_2 -> V_47 + 1 + V_43 ) *
V_6 -> V_7 ;
}
static void F_56 ( struct V_85 * V_6 )
{
struct V_1 * V_2 = F_53 ( V_6 ) ;
F_57 ( V_2 -> V_42 ) ;
if ( V_2 -> V_39 )
F_58 ( V_2 -> V_39 ) ;
F_5 ( V_2 ) ;
F_4 ( V_2 -> V_90 ) ;
F_59 ( V_2 ) ;
}
static int F_60 ( struct V_85 * V_6 ,
int (* F_42)( void * V_72 ,
T_2 V_73 , T_2 V_74 ) ,
void * V_72 )
{
int V_3 , V_91 ( V_49 ) ;
struct V_1 * V_2 = F_53 ( V_6 ) ;
V_3 = F_21 ( V_2 , & V_49 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_44 = ( V_2 -> V_6 -> V_7 << V_8 ) /
sizeof( struct V_64 ) ;
V_2 -> V_90 = F_61 ( V_2 -> V_44 ,
sizeof( * V_2 -> V_90 ) ) ;
if ( ! V_2 -> V_90 )
return - V_4 ;
if ( V_49 ) {
V_3 = F_32 ( V_2 ) ;
if ( V_3 ) {
F_29 ( L_5 ) ;
return V_3 ;
}
V_2 -> V_47 = 0 ;
F_19 ( V_2 ) ;
V_3 = F_20 ( V_2 , 0 ) ;
if ( V_3 )
F_29 ( L_6 ) ;
return V_3 ;
}
if ( V_2 -> V_63 != V_92 ) {
F_29 ( L_7 ,
V_2 -> V_63 ) ;
return - V_93 ;
}
if ( ! V_2 -> V_62 )
return 1 ;
V_3 = F_43 ( V_2 , F_42 , V_72 ) ;
return V_3 ;
}
static int F_62 ( struct V_85 * V_6 ,
struct V_94 * V_71 )
{
struct V_1 * V_2 = F_53 ( V_6 ) ;
T_4 V_95 = F_55 ( F_10 ( V_6 -> V_28 ) -> V_27 ) ;
if ( V_95 < ( ( V_2 -> V_46 + 1 ) * V_6 -> V_7 ) )
return - V_96 ;
V_71 -> V_70 = V_2 -> V_46 ;
V_2 -> V_46 ++ ;
F_16 ( V_2 ) ;
F_63 ( & V_2 -> V_97 ) ;
return 0 ;
}
static void F_64 ( struct V_85 * V_6 ,
struct V_94 * V_71 , int V_62 ,
void (* F_42) ( void * , int V_98 ) ,
void * V_72 )
{
unsigned int V_76 ;
struct V_1 * V_2 = F_53 ( V_6 ) ;
struct V_67 V_99 ;
struct V_100 * V_101 ;
if ( ! V_62 )
V_2 -> V_62 = 0 ;
V_99 . V_69 = V_71 -> V_69 ;
V_99 . V_70 = V_71 -> V_70 ;
F_38 ( V_2 , V_2 -> V_77 ++ , & V_99 ) ;
V_101 = V_2 -> V_90 + V_2 -> V_102 ++ ;
V_101 -> F_42 = F_42 ;
V_101 -> V_86 = V_72 ;
if ( ! F_65 ( & V_2 -> V_97 ) &&
( V_2 -> V_77 != V_2 -> V_44 ) )
return;
if ( ( V_2 -> V_77 == V_2 -> V_44 ) &&
F_20 ( V_2 , V_2 -> V_47 + 1 ) )
V_2 -> V_62 = 0 ;
if ( V_2 -> V_62 && F_18 ( V_2 , V_48 , V_103 ) )
V_2 -> V_62 = 0 ;
if ( V_2 -> V_77 == V_2 -> V_44 ) {
V_2 -> V_77 = 0 ;
V_2 -> V_47 ++ ;
F_19 ( V_2 ) ;
}
for ( V_76 = 0 ; V_76 < V_2 -> V_102 ; V_76 ++ ) {
V_101 = V_2 -> V_90 + V_76 ;
V_101 -> F_42 ( V_101 -> V_86 , V_2 -> V_62 ) ;
}
V_2 -> V_102 = 0 ;
}
static int F_66 ( struct V_85 * V_6 ,
T_2 * V_104 ,
T_2 * V_105 )
{
struct V_1 * V_2 = F_53 ( V_6 ) ;
struct V_67 V_99 ;
int V_106 ;
int V_3 ;
if ( ! V_2 -> V_77 ) {
if ( ! V_2 -> V_47 )
return 0 ;
V_2 -> V_47 -- ;
V_3 = F_18 ( V_2 , V_57 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_77 = V_2 -> V_44 ;
}
F_36 ( V_2 , V_2 -> V_9 , V_2 -> V_77 - 1 , & V_99 ) ;
* V_104 = V_99 . V_69 ;
* V_105 = V_99 . V_70 ;
for ( V_106 = 1 ; V_106 < V_2 -> V_77 ;
V_106 ++ ) {
F_36 ( V_2 , V_2 -> V_9 ,
V_2 -> V_77 - 1 - V_106 , & V_99 ) ;
if ( V_99 . V_69 != * V_104 - V_106 ||
V_99 . V_70 != * V_105 - V_106 )
break;
}
return V_106 ;
}
static int F_67 ( struct V_85 * V_6 ,
int V_107 )
{
int V_3 , V_76 ;
struct V_1 * V_2 = F_53 ( V_6 ) ;
F_35 ( V_107 > V_2 -> V_77 ) ;
for ( V_76 = 0 ; V_76 < V_107 ; V_76 ++ )
F_40 ( V_2 , V_2 -> V_77 - 1 - V_76 ) ;
V_3 = F_18 ( V_2 , V_48 , V_103 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_77 -= V_107 ;
V_2 -> V_46 = F_15 ( V_2 , V_2 -> V_47 ) +
V_2 -> V_77 + 1 ;
return 0 ;
}
static void F_68 ( struct V_85 * V_6 )
{
struct V_1 * V_2 = F_53 ( V_6 ) ;
V_2 -> V_62 = 0 ;
if ( F_32 ( V_2 ) )
F_29 ( L_8 ) ;
}
static int F_69 ( struct V_85 * V_6 , char * V_108 )
{
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_70 ( sizeof( * V_2 ) , V_109 ) ;
if ( ! V_2 )
return - V_4 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_62 = 1 ;
V_2 -> V_63 = V_92 ;
V_2 -> V_9 = NULL ;
V_2 -> V_11 = NULL ;
V_2 -> V_13 = NULL ;
V_2 -> V_46 = V_43 + 1 ;
V_2 -> V_77 = 0 ;
V_2 -> V_102 = 0 ;
F_71 ( & V_2 -> V_97 , 0 ) ;
V_2 -> V_90 = NULL ;
V_2 -> V_42 = F_72 ( L_9 , V_110 , 0 ) ;
if ( ! V_2 -> V_42 ) {
F_31 ( L_10 ) ;
V_3 = - V_4 ;
goto V_111;
}
if ( V_108 ) {
char V_112 = toupper ( V_108 [ 0 ] ) ;
if ( V_112 == 'O' )
V_6 -> V_113 = true ;
else {
F_31 ( L_11 , V_108 ) ;
V_3 = - V_93 ;
goto V_114;
}
}
V_6 -> V_86 = V_2 ;
return 0 ;
V_114:
F_57 ( V_2 -> V_42 ) ;
V_111:
F_59 ( V_2 ) ;
return V_3 ;
}
static unsigned F_73 ( struct V_85 * V_6 ,
T_5 V_115 , char * V_19 ,
unsigned V_116 )
{
unsigned V_117 = 0 ;
switch ( V_115 ) {
case V_118 :
break;
case V_119 :
F_74 ( L_12 , V_6 -> V_113 ? L_13 : L_14 ,
( unsigned long long ) V_6 -> V_7 ) ;
}
return V_117 ;
}
int F_75 ( void )
{
int V_3 ;
V_3 = F_76 ( & V_120 ) ;
if ( V_3 ) {
F_31 ( L_15 ) ;
return V_3 ;
}
V_3 = F_76 ( & V_121 ) ;
if ( V_3 ) {
F_31 ( L_16
L_17 ) ;
F_77 ( & V_120 ) ;
return V_3 ;
}
return V_3 ;
}
void F_78 ( void )
{
F_77 ( & V_120 ) ;
F_77 ( & V_121 ) ;
}
