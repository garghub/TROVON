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
F_14 ( & V_18 . V_16 ) ;
return V_18 . V_19 ;
}
static T_2 F_15 ( struct V_1 * V_2 , T_2 V_9 )
{
return V_41 + ( ( V_2 -> V_42 + 1 ) * V_9 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_3 V_43 = V_2 -> V_42 + 1 ;
T_2 V_44 = V_2 -> V_44 ;
if ( F_17 ( V_44 , V_43 ) == V_41 )
V_2 -> V_44 ++ ;
}
static int F_18 ( struct V_1 * V_2 , int V_23 )
{
int V_3 ;
T_2 V_22 ;
V_22 = F_15 ( V_2 , V_2 -> V_45 ) ;
V_3 = F_9 ( V_2 , V_2 -> V_9 , V_22 , V_23 , 0 ) ;
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
return F_9 ( V_2 , V_2 -> V_11 , F_15 ( V_2 , V_9 ) , V_46 , 0 ) ;
}
static int F_21 ( struct V_1 * V_2 , int * V_47 )
{
int V_3 ;
struct V_48 * V_49 ;
unsigned V_7 ;
int V_50 = 1 ;
char * V_51 ;
if ( ! V_2 -> V_6 -> V_7 ) {
V_2 -> V_6 -> V_7 = F_22 ( V_52 ,
F_23 ( F_10 ( V_2 -> V_6 -> V_27 ) ->
V_26 ) >> 9 ) ;
V_2 -> V_6 -> V_53 = V_2 -> V_6 -> V_7 - 1 ;
V_2 -> V_6 -> V_54 = F_24 ( V_2 -> V_6 -> V_7 ) ;
V_50 = 0 ;
}
V_2 -> V_37 = F_25 () ;
if ( F_26 ( V_2 -> V_37 ) )
return F_27 ( V_2 -> V_37 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_9 ( V_2 , V_2 -> V_13 , 0 , V_55 , 1 ) ;
if ( V_3 )
goto V_56;
V_49 = V_2 -> V_13 ;
if ( F_28 ( V_49 -> V_57 ) == 0 ) {
* V_47 = 1 ;
return 0 ;
}
if ( F_28 ( V_49 -> V_57 ) != V_58 ) {
F_29 ( L_1 ) ;
V_3 = - V_59 ;
goto V_56;
}
* V_47 = 0 ;
V_2 -> V_60 = F_28 ( V_49 -> V_60 ) ;
V_2 -> V_61 = F_28 ( V_49 -> V_61 ) ;
V_7 = F_28 ( V_49 -> V_7 ) ;
if ( V_2 -> V_6 -> V_7 == V_7 )
return 0 ;
if ( V_50 )
F_29 ( L_2
L_3 ,
V_7 , V_2 -> V_6 -> V_7 ) ;
F_5 ( V_2 ) ;
V_3 = F_30 ( V_2 -> V_6 , V_7 ,
& V_51 ) ;
if ( V_3 ) {
F_31 ( L_4 ,
V_7 , V_51 ) ;
return V_3 ;
}
V_3 = F_1 ( V_2 ) ;
return V_3 ;
V_56:
F_5 ( V_2 ) ;
return V_3 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
memset ( V_2 -> V_13 , 0 , V_2 -> V_6 -> V_7 << V_8 ) ;
V_49 = V_2 -> V_13 ;
V_49 -> V_57 = F_33 ( V_58 ) ;
V_49 -> V_60 = F_33 ( V_2 -> V_60 ) ;
V_49 -> V_61 = F_33 ( V_2 -> V_61 ) ;
V_49 -> V_7 = F_33 ( V_2 -> V_6 -> V_7 ) ;
return F_9 ( V_2 , V_2 -> V_13 , 0 , V_46 , 1 ) ;
}
static struct V_62 * F_34 ( struct V_1 * V_2 , void * V_63 ,
T_3 V_64 )
{
F_35 ( V_64 >= V_2 -> V_42 ) ;
return ( (struct V_62 * ) V_63 ) + V_64 ;
}
static void F_36 ( struct V_1 * V_2 , void * V_63 ,
T_3 V_64 , struct V_65 * V_19 )
{
struct V_62 * V_66 = F_34 ( V_2 , V_63 , V_64 ) ;
V_19 -> V_67 = F_37 ( V_66 -> V_67 ) ;
V_19 -> V_68 = F_37 ( V_66 -> V_68 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
T_3 V_64 , struct V_65 * V_69 )
{
struct V_62 * V_66 = F_34 ( V_2 , V_2 -> V_9 , V_64 ) ;
V_66 -> V_67 = F_39 ( V_69 -> V_67 ) ;
V_66 -> V_68 = F_39 ( V_69 -> V_68 ) ;
}
static void F_40 ( struct V_1 * V_2 , T_3 V_64 )
{
struct V_62 * V_66 = F_34 ( V_2 , V_2 -> V_9 , V_64 ) ;
V_66 -> V_67 = 0 ;
V_66 -> V_68 = 0 ;
}
static int F_41 ( struct V_1 * V_2 , void * V_63 ,
int (* F_42)( void * V_70 ,
T_2 V_71 , T_2 V_72 ) ,
void * V_70 ,
int * V_73 )
{
int V_3 ;
unsigned int V_74 ;
struct V_65 V_69 ;
* V_73 = 1 ;
for ( V_74 = 0 ; V_74 < V_2 -> V_42 ; V_74 ++ ) {
F_36 ( V_2 , V_63 , V_74 , & V_69 ) ;
if ( V_69 . V_68 == 0LL ) {
V_2 -> V_75 = V_74 ;
* V_73 = 0 ;
break;
}
if ( V_2 -> V_44 <= V_69 . V_68 )
V_2 -> V_44 = V_69 . V_68 + 1 ;
V_3 = F_42 ( V_70 , V_69 . V_67 , V_69 . V_68 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
int (* F_42)( void * V_70 , T_2 V_71 ,
T_2 V_72 ) ,
void * V_70 )
{
int V_3 , V_73 = 1 ;
struct V_76 * V_36 ;
T_2 V_77 = 0 ;
V_36 = F_44 ( F_10 ( V_2 -> V_6 -> V_27 ) -> V_26 ,
V_2 -> V_6 -> V_7 << V_8 ,
1 , 0 , NULL , NULL ) ;
if ( F_26 ( V_36 ) )
return F_27 ( V_36 ) ;
F_45 ( V_36 , 1 + V_78 ) ;
for ( V_2 -> V_45 = 0 ; V_73 ; V_2 -> V_45 ++ ) {
struct V_79 * V_80 ;
void * V_9 ;
T_2 V_22 ;
if ( F_46 ( V_77 < V_2 -> V_45 ) )
V_77 = V_2 -> V_45 ;
if ( V_78 ) do {
T_2 V_81 = F_15 ( V_2 , V_77 ) ;
if ( F_46 ( V_81 >= F_47 ( V_36 ) ) )
break;
F_48 ( V_36 , V_81 , 1 ) ;
V_77 ++ ;
if ( F_46 ( ! V_77 ) )
break;
} while ( V_77 <= V_2 -> V_45 + V_78 );
V_22 = F_15 ( V_2 , V_2 -> V_45 ) ;
V_9 = F_49 ( V_36 , V_22 , & V_80 ) ;
if ( F_26 ( V_9 ) ) {
V_3 = F_27 ( V_9 ) ;
goto V_82;
}
V_3 = F_41 ( V_2 , V_9 , F_42 , V_70 ,
& V_73 ) ;
if ( ! V_73 )
memcpy ( V_2 -> V_9 , V_9 , V_2 -> V_6 -> V_7 << V_8 ) ;
F_50 ( V_80 ) ;
F_51 ( V_36 , V_22 ) ;
if ( F_46 ( V_3 ) )
goto V_82;
}
V_2 -> V_45 -- ;
F_16 ( V_2 ) ;
V_3 = 0 ;
V_82:
F_52 ( V_36 ) ;
return V_3 ;
}
static struct V_1 * F_53 ( struct V_83 * V_6 )
{
return (struct V_1 * ) V_6 -> V_84 ;
}
static void F_54 ( struct V_83 * V_6 ,
T_4 * V_85 ,
T_4 * V_86 ,
T_4 * V_87 )
{
struct V_1 * V_2 = F_53 ( V_6 ) ;
* V_86 = V_2 -> V_44 * V_6 -> V_7 ;
* V_85 = F_55 ( F_10 ( V_6 -> V_27 ) -> V_26 ) ;
* V_87 = ( V_2 -> V_45 + 1 + V_41 ) *
V_6 -> V_7 ;
}
static void F_56 ( struct V_83 * V_6 )
{
struct V_1 * V_2 = F_53 ( V_6 ) ;
F_57 ( V_2 -> V_40 ) ;
if ( V_2 -> V_37 )
F_58 ( V_2 -> V_37 ) ;
F_5 ( V_2 ) ;
F_4 ( V_2 -> V_88 ) ;
F_59 ( V_2 ) ;
}
static int F_60 ( struct V_83 * V_6 ,
int (* F_42)( void * V_70 ,
T_2 V_71 , T_2 V_72 ) ,
void * V_70 )
{
int V_3 , V_89 ( V_47 ) ;
struct V_1 * V_2 = F_53 ( V_6 ) ;
V_3 = F_21 ( V_2 , & V_47 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_42 = ( V_2 -> V_6 -> V_7 << V_8 ) /
sizeof( struct V_62 ) ;
V_2 -> V_88 = F_61 ( V_2 -> V_42 ,
sizeof( * V_2 -> V_88 ) ) ;
if ( ! V_2 -> V_88 )
return - V_4 ;
if ( V_47 ) {
V_3 = F_32 ( V_2 ) ;
if ( V_3 ) {
F_29 ( L_5 ) ;
return V_3 ;
}
V_2 -> V_45 = 0 ;
F_19 ( V_2 ) ;
V_3 = F_20 ( V_2 , 0 ) ;
if ( V_3 )
F_29 ( L_6 ) ;
return V_3 ;
}
if ( V_2 -> V_61 != V_90 ) {
F_29 ( L_7 ,
V_2 -> V_61 ) ;
return - V_91 ;
}
if ( ! V_2 -> V_60 )
return 1 ;
V_3 = F_43 ( V_2 , F_42 , V_70 ) ;
return V_3 ;
}
static int F_62 ( struct V_83 * V_6 ,
struct V_92 * V_69 )
{
struct V_1 * V_2 = F_53 ( V_6 ) ;
T_4 V_93 = F_55 ( F_10 ( V_6 -> V_27 ) -> V_26 ) ;
if ( V_93 < ( ( V_2 -> V_44 + 1 ) * V_6 -> V_7 ) )
return - V_94 ;
V_69 -> V_68 = V_2 -> V_44 ;
V_2 -> V_44 ++ ;
F_16 ( V_2 ) ;
F_63 ( & V_2 -> V_95 ) ;
return 0 ;
}
static void F_64 ( struct V_83 * V_6 ,
struct V_92 * V_69 ,
void (* F_42) ( void * , int V_96 ) ,
void * V_70 )
{
unsigned int V_74 ;
struct V_1 * V_2 = F_53 ( V_6 ) ;
struct V_65 V_97 ;
struct V_98 * V_99 ;
V_97 . V_67 = V_69 -> V_67 ;
V_97 . V_68 = V_69 -> V_68 ;
F_38 ( V_2 , V_2 -> V_75 ++ , & V_97 ) ;
V_99 = V_2 -> V_88 + V_2 -> V_100 ++ ;
V_99 -> F_42 = F_42 ;
V_99 -> V_84 = V_70 ;
if ( ! F_65 ( & V_2 -> V_95 ) &&
( V_2 -> V_75 != V_2 -> V_42 ) )
return;
if ( ( V_2 -> V_75 == V_2 -> V_42 ) &&
F_20 ( V_2 , V_2 -> V_45 + 1 ) )
V_2 -> V_60 = 0 ;
if ( V_2 -> V_60 && F_18 ( V_2 , V_101 ) )
V_2 -> V_60 = 0 ;
if ( V_2 -> V_75 == V_2 -> V_42 ) {
V_2 -> V_75 = 0 ;
V_2 -> V_45 ++ ;
F_19 ( V_2 ) ;
}
for ( V_74 = 0 ; V_74 < V_2 -> V_100 ; V_74 ++ ) {
V_99 = V_2 -> V_88 + V_74 ;
V_99 -> F_42 ( V_99 -> V_84 , V_2 -> V_60 ) ;
}
V_2 -> V_100 = 0 ;
}
static int F_66 ( struct V_83 * V_6 ,
T_2 * V_102 ,
T_2 * V_103 )
{
struct V_1 * V_2 = F_53 ( V_6 ) ;
struct V_65 V_97 ;
int V_104 ;
int V_3 ;
if ( ! V_2 -> V_75 ) {
if ( ! V_2 -> V_45 )
return 0 ;
V_2 -> V_45 -- ;
V_3 = F_18 ( V_2 , V_55 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_75 = V_2 -> V_42 ;
}
F_36 ( V_2 , V_2 -> V_9 , V_2 -> V_75 - 1 , & V_97 ) ;
* V_102 = V_97 . V_67 ;
* V_103 = V_97 . V_68 ;
for ( V_104 = 1 ; V_104 < V_2 -> V_75 ;
V_104 ++ ) {
F_36 ( V_2 , V_2 -> V_9 ,
V_2 -> V_75 - 1 - V_104 , & V_97 ) ;
if ( V_97 . V_67 != * V_102 - V_104 ||
V_97 . V_68 != * V_103 - V_104 )
break;
}
return V_104 ;
}
static int F_67 ( struct V_83 * V_6 ,
int V_105 )
{
int V_3 , V_74 ;
struct V_1 * V_2 = F_53 ( V_6 ) ;
F_35 ( V_105 > V_2 -> V_75 ) ;
for ( V_74 = 0 ; V_74 < V_105 ; V_74 ++ )
F_40 ( V_2 , V_2 -> V_75 - 1 - V_74 ) ;
V_3 = F_18 ( V_2 , V_101 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_75 -= V_105 ;
V_2 -> V_44 = F_15 ( V_2 , V_2 -> V_45 ) +
V_2 -> V_75 + 1 ;
return 0 ;
}
static void F_68 ( struct V_83 * V_6 )
{
struct V_1 * V_2 = F_53 ( V_6 ) ;
V_2 -> V_60 = 0 ;
if ( F_32 ( V_2 ) )
F_29 ( L_8 ) ;
}
static int F_69 ( struct V_83 * V_6 , char * V_106 )
{
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_70 ( sizeof( * V_2 ) , V_107 ) ;
if ( ! V_2 )
return - V_4 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_60 = 1 ;
V_2 -> V_61 = V_90 ;
V_2 -> V_9 = NULL ;
V_2 -> V_11 = NULL ;
V_2 -> V_13 = NULL ;
V_2 -> V_44 = V_41 + 1 ;
V_2 -> V_75 = 0 ;
V_2 -> V_100 = 0 ;
F_71 ( & V_2 -> V_95 , 0 ) ;
V_2 -> V_88 = NULL ;
V_2 -> V_40 = F_72 ( L_9 , V_108 , 0 ) ;
if ( ! V_2 -> V_40 ) {
F_31 ( L_10 ) ;
V_3 = - V_4 ;
goto V_109;
}
if ( V_106 ) {
char V_110 = toupper ( V_106 [ 0 ] ) ;
if ( V_110 == 'O' )
V_6 -> V_111 = true ;
else {
F_31 ( L_11 , V_106 ) ;
V_3 = - V_91 ;
goto V_112;
}
}
V_6 -> V_84 = V_2 ;
return 0 ;
V_112:
F_57 ( V_2 -> V_40 ) ;
V_109:
F_59 ( V_2 ) ;
return V_3 ;
}
static unsigned F_73 ( struct V_83 * V_6 ,
T_5 V_113 , char * V_19 ,
unsigned V_114 )
{
unsigned V_115 = 0 ;
switch ( V_113 ) {
case V_116 :
break;
case V_117 :
F_74 ( L_12 , V_6 -> V_111 ? L_13 : L_14 ,
( unsigned long long ) V_6 -> V_7 ) ;
}
return V_115 ;
}
int F_75 ( void )
{
int V_3 ;
V_3 = F_76 ( & V_118 ) ;
if ( V_3 ) {
F_31 ( L_15 ) ;
return V_3 ;
}
V_3 = F_76 ( & V_119 ) ;
if ( V_3 ) {
F_31 ( L_16
L_17 ) ;
F_77 ( & V_118 ) ;
return V_3 ;
}
return V_3 ;
}
void F_78 ( void )
{
F_77 ( & V_118 ) ;
F_77 ( & V_119 ) ;
}
