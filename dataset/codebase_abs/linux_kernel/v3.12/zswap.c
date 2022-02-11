static int F_1 ( enum V_1 V_2 , const T_1 * V_3 , unsigned int V_4 ,
T_1 * V_5 , unsigned int * V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = * F_2 ( V_10 , F_3 () ) ;
switch ( V_2 ) {
case V_11 :
V_9 = F_4 ( V_8 , V_3 , V_4 , V_5 , V_6 ) ;
break;
case V_12 :
V_9 = F_5 ( V_8 , V_3 , V_4 , V_5 , V_6 ) ;
break;
default:
V_9 = - V_13 ;
}
F_6 () ;
return V_9 ;
}
static int T_2 F_7 ( void )
{
if ( ! F_8 ( V_14 , 0 , 0 ) ) {
F_9 ( L_1 , V_14 ) ;
V_14 = V_15 ;
if ( ! F_8 ( V_14 , 0 , 0 ) )
return - V_16 ;
}
F_9 ( L_2 , V_14 ) ;
V_10 = F_10 ( struct V_7 * ) ;
if ( ! V_10 )
return - V_17 ;
return 0 ;
}
static void F_11 ( void )
{
if ( V_10 )
F_12 ( V_10 ) ;
}
static int F_13 ( void )
{
V_18 = F_14 ( V_19 , 0 ) ;
return ( V_18 == NULL ) ;
}
static void F_15 ( void )
{
F_16 ( V_18 ) ;
}
static struct V_19 * F_17 ( T_3 V_20 )
{
struct V_19 * V_21 ;
V_21 = F_18 ( V_18 , V_20 ) ;
if ( ! V_21 )
return NULL ;
V_21 -> V_22 = 1 ;
return V_21 ;
}
static void F_19 ( struct V_19 * V_21 )
{
F_20 ( V_18 , V_21 ) ;
}
static void F_21 ( struct V_19 * V_21 )
{
V_21 -> V_22 ++ ;
}
static int F_22 ( struct V_19 * V_21 )
{
V_21 -> V_22 -- ;
return V_21 -> V_22 ;
}
static struct V_19 * F_23 ( struct V_23 * V_24 , T_4 V_25 )
{
struct V_26 * V_27 = V_24 -> V_26 ;
struct V_19 * V_21 ;
while ( V_27 ) {
V_21 = F_24 ( V_27 , struct V_19 , V_28 ) ;
if ( V_21 -> V_25 > V_25 )
V_27 = V_27 -> V_29 ;
else if ( V_21 -> V_25 < V_25 )
V_27 = V_27 -> V_30 ;
else
return V_21 ;
}
return NULL ;
}
static int F_25 ( struct V_23 * V_24 , struct V_19 * V_21 ,
struct V_19 * * V_31 )
{
struct V_26 * * V_32 = & V_24 -> V_26 , * V_33 = NULL ;
struct V_19 * V_34 ;
while ( * V_32 ) {
V_33 = * V_32 ;
V_34 = F_24 ( V_33 , struct V_19 , V_28 ) ;
if ( V_34 -> V_25 > V_21 -> V_25 )
V_32 = & ( * V_32 ) -> V_29 ;
else if ( V_34 -> V_25 < V_21 -> V_25 )
V_32 = & ( * V_32 ) -> V_30 ;
else {
* V_31 = V_34 ;
return - V_35 ;
}
}
F_26 ( & V_21 -> V_28 , V_33 , V_32 ) ;
F_27 ( & V_21 -> V_28 , V_24 ) ;
return 0 ;
}
static int F_28 ( unsigned long V_36 , unsigned long V_37 )
{
struct V_7 * V_8 ;
T_1 * V_5 ;
switch ( V_36 ) {
case V_38 :
V_8 = F_29 ( V_14 , 0 , 0 ) ;
if ( F_30 ( V_8 ) ) {
F_31 ( L_3 ) ;
return V_39 ;
}
* F_2 ( V_10 , V_37 ) = V_8 ;
V_5 = F_32 ( V_40 * 2 , V_41 ) ;
if ( ! V_5 ) {
F_31 ( L_4 ) ;
F_33 ( V_8 ) ;
* F_2 ( V_10 , V_37 ) = NULL ;
return V_39 ;
}
F_34 ( V_42 , V_37 ) = V_5 ;
break;
case V_43 :
case V_44 :
V_8 = * F_2 ( V_10 , V_37 ) ;
if ( V_8 ) {
F_33 ( V_8 ) ;
* F_2 ( V_10 , V_37 ) = NULL ;
}
V_5 = F_34 ( V_42 , V_37 ) ;
F_35 ( V_5 ) ;
F_34 ( V_42 , V_37 ) = NULL ;
break;
default:
break;
}
return V_45 ;
}
static int F_36 ( struct V_46 * V_47 ,
unsigned long V_36 , void * V_48 )
{
unsigned long V_37 = ( unsigned long ) V_48 ;
return F_28 ( V_36 , V_37 ) ;
}
static int F_37 ( void )
{
unsigned long V_37 ;
F_38 () ;
F_39 (cpu)
if ( F_28 ( V_38 , V_37 ) != V_45 )
goto V_49;
F_40 ( & V_50 ) ;
F_41 () ;
return 0 ;
V_49:
F_39 (cpu)
F_28 ( V_44 , V_37 ) ;
F_41 () ;
return - V_17 ;
}
static bool F_42 ( void )
{
return ( V_51 * V_52 / 100 <
V_53 ) ;
}
static void F_43 ( struct V_54 * V_55 , struct V_19 * V_21 )
{
F_44 ( V_55 -> V_56 , V_21 -> V_57 ) ;
F_19 ( V_21 ) ;
F_45 ( & V_58 ) ;
V_53 = F_46 ( V_55 -> V_56 ) ;
}
static int F_47 ( T_5 V_21 ,
struct V_59 * * V_60 )
{
struct V_59 * V_61 , * V_62 = NULL ;
struct V_63 * V_64 = F_48 ( V_21 ) ;
int V_65 ;
* V_60 = NULL ;
do {
V_61 = F_49 ( V_64 , V_21 . V_66 ) ;
if ( V_61 )
break;
if ( ! V_62 ) {
V_62 = F_50 ( V_41 ) ;
if ( ! V_62 )
break;
}
V_65 = F_51 ( V_41 ) ;
if ( V_65 )
break;
V_65 = F_52 ( V_21 ) ;
if ( V_65 == - V_35 ) {
F_53 () ;
continue;
}
if ( V_65 ) {
F_53 () ;
break;
}
F_54 ( V_62 ) ;
F_55 ( V_62 ) ;
V_65 = F_56 ( V_62 , V_21 ) ;
if ( F_57 ( ! V_65 ) ) {
F_53 () ;
F_58 ( V_62 ) ;
* V_60 = V_62 ;
return V_67 ;
}
F_53 () ;
F_59 ( V_62 ) ;
F_60 ( V_62 ) ;
F_61 ( V_21 , NULL ) ;
} while ( V_65 != - V_17 );
if ( V_62 )
F_62 ( V_62 ) ;
if ( ! V_61 )
return V_68 ;
* V_60 = V_61 ;
return V_69 ;
}
static int F_63 ( struct V_70 * V_56 , unsigned long V_57 )
{
struct V_71 * V_72 ;
T_5 V_73 ;
struct V_54 * V_55 ;
T_4 V_25 ;
struct V_19 * V_21 ;
struct V_59 * V_59 ;
T_1 * V_3 , * V_5 ;
unsigned int V_6 ;
int V_9 , V_22 ;
struct V_74 V_75 = {
. V_76 = V_77 ,
} ;
V_72 = F_64 ( V_56 , V_57 ) ;
V_73 = V_72 -> V_73 ;
F_65 ( V_56 , V_57 ) ;
V_55 = V_78 [ F_66 ( V_73 ) ] ;
V_25 = F_67 ( V_73 ) ;
F_68 ( V_56 != V_55 -> V_56 ) ;
F_69 ( & V_55 -> V_79 ) ;
V_21 = F_23 ( & V_55 -> V_80 , V_25 ) ;
if ( ! V_21 ) {
F_70 ( & V_55 -> V_79 ) ;
return 0 ;
}
F_21 ( V_21 ) ;
F_70 ( & V_55 -> V_79 ) ;
F_68 ( V_25 != V_21 -> V_25 ) ;
switch ( F_47 ( V_73 , & V_59 ) ) {
case V_68 :
V_9 = - V_17 ;
goto V_81;
case V_69 :
F_62 ( V_59 ) ;
V_9 = - V_35 ;
goto V_81;
case V_67 :
V_6 = V_40 ;
V_3 = ( T_1 * ) F_64 ( V_55 -> V_56 , V_21 -> V_57 ) +
sizeof( struct V_71 ) ;
V_5 = F_71 ( V_59 ) ;
V_9 = F_1 ( V_12 , V_3 ,
V_21 -> V_82 , V_5 , & V_6 ) ;
F_72 ( V_5 ) ;
F_65 ( V_55 -> V_56 , V_21 -> V_57 ) ;
F_68 ( V_9 ) ;
F_68 ( V_6 != V_40 ) ;
F_73 ( V_59 ) ;
}
F_74 ( V_59 , & V_75 , V_83 ) ;
F_62 ( V_59 ) ;
V_84 ++ ;
F_69 ( & V_55 -> V_79 ) ;
F_22 ( V_21 ) ;
V_22 = F_22 ( V_21 ) ;
if ( V_22 >= 0 ) {
F_75 ( & V_21 -> V_28 , & V_55 -> V_80 ) ;
}
F_70 ( & V_55 -> V_79 ) ;
if ( V_22 <= 0 ) {
F_43 ( V_55 , V_21 ) ;
return 0 ;
}
return - V_85 ;
V_81:
F_69 ( & V_55 -> V_79 ) ;
F_22 ( V_21 ) ;
F_70 ( & V_55 -> V_79 ) ;
return V_9 ;
}
static int F_76 ( unsigned type , T_4 V_25 ,
struct V_59 * V_59 )
{
struct V_54 * V_55 = V_78 [ type ] ;
struct V_19 * V_21 , * V_31 ;
int V_9 ;
unsigned int V_6 = V_40 , V_86 ;
unsigned long V_57 ;
char * V_87 ;
T_1 * V_3 , * V_5 ;
struct V_71 * V_72 ;
if ( ! V_55 ) {
V_9 = - V_16 ;
goto V_88;
}
if ( F_42 () ) {
V_89 ++ ;
if ( F_77 ( V_55 -> V_56 , 8 ) ) {
V_90 ++ ;
V_9 = - V_17 ;
goto V_88;
}
}
V_21 = F_17 ( V_41 ) ;
if ( ! V_21 ) {
V_91 ++ ;
V_9 = - V_17 ;
goto V_88;
}
V_5 = F_78 ( V_42 ) ;
V_3 = F_71 ( V_59 ) ;
V_9 = F_1 ( V_11 , V_3 , V_40 , V_5 , & V_6 ) ;
F_72 ( V_3 ) ;
if ( V_9 ) {
V_9 = - V_13 ;
goto V_92;
}
V_86 = V_6 + sizeof( struct V_71 ) ;
V_9 = F_79 ( V_55 -> V_56 , V_86 , V_93 | V_94 ,
& V_57 ) ;
if ( V_9 == - V_95 ) {
V_96 ++ ;
goto V_92;
}
if ( V_9 ) {
V_97 ++ ;
goto V_92;
}
V_72 = F_64 ( V_55 -> V_56 , V_57 ) ;
V_72 -> V_73 = F_80 ( type , V_25 ) ;
V_87 = ( T_1 * ) ( V_72 + 1 ) ;
memcpy ( V_87 , V_5 , V_6 ) ;
F_65 ( V_55 -> V_56 , V_57 ) ;
F_81 ( V_42 ) ;
V_21 -> V_25 = V_25 ;
V_21 -> V_57 = V_57 ;
V_21 -> V_82 = V_6 ;
F_69 ( & V_55 -> V_79 ) ;
do {
V_9 = F_25 ( & V_55 -> V_80 , V_21 , & V_31 ) ;
if ( V_9 == - V_35 ) {
V_98 ++ ;
F_75 ( & V_31 -> V_28 , & V_55 -> V_80 ) ;
if ( ! F_22 ( V_31 ) ) {
F_43 ( V_55 , V_31 ) ;
}
}
} while ( V_9 == - V_35 );
F_70 ( & V_55 -> V_79 ) ;
F_82 ( & V_58 ) ;
V_53 = F_46 ( V_55 -> V_56 ) ;
return 0 ;
V_92:
F_81 ( V_42 ) ;
F_19 ( V_21 ) ;
V_88:
return V_9 ;
}
static int F_83 ( unsigned type , T_4 V_25 ,
struct V_59 * V_59 )
{
struct V_54 * V_55 = V_78 [ type ] ;
struct V_19 * V_21 ;
T_1 * V_3 , * V_5 ;
unsigned int V_6 ;
int V_22 , V_9 ;
F_69 ( & V_55 -> V_79 ) ;
V_21 = F_23 ( & V_55 -> V_80 , V_25 ) ;
if ( ! V_21 ) {
F_70 ( & V_55 -> V_79 ) ;
return - 1 ;
}
F_21 ( V_21 ) ;
F_70 ( & V_55 -> V_79 ) ;
V_6 = V_40 ;
V_3 = ( T_1 * ) F_64 ( V_55 -> V_56 , V_21 -> V_57 ) +
sizeof( struct V_71 ) ;
V_5 = F_71 ( V_59 ) ;
V_9 = F_1 ( V_12 , V_3 , V_21 -> V_82 ,
V_5 , & V_6 ) ;
F_72 ( V_5 ) ;
F_65 ( V_55 -> V_56 , V_21 -> V_57 ) ;
F_68 ( V_9 ) ;
F_69 ( & V_55 -> V_79 ) ;
V_22 = F_22 ( V_21 ) ;
if ( F_57 ( V_22 ) ) {
F_70 ( & V_55 -> V_79 ) ;
return 0 ;
}
F_70 ( & V_55 -> V_79 ) ;
F_43 ( V_55 , V_21 ) ;
return 0 ;
}
static void F_84 ( unsigned type , T_4 V_25 )
{
struct V_54 * V_55 = V_78 [ type ] ;
struct V_19 * V_21 ;
int V_22 ;
F_69 ( & V_55 -> V_79 ) ;
V_21 = F_23 ( & V_55 -> V_80 , V_25 ) ;
if ( ! V_21 ) {
F_70 ( & V_55 -> V_79 ) ;
return;
}
F_75 ( & V_21 -> V_28 , & V_55 -> V_80 ) ;
V_22 = F_22 ( V_21 ) ;
F_70 ( & V_55 -> V_79 ) ;
if ( V_22 ) {
return;
}
F_43 ( V_55 , V_21 ) ;
}
static void F_85 ( unsigned type )
{
struct V_54 * V_55 = V_78 [ type ] ;
struct V_19 * V_21 , * V_99 ;
if ( ! V_55 )
return;
F_69 ( & V_55 -> V_79 ) ;
F_86 (entry, n, &tree->rbroot, rbnode) {
F_44 ( V_55 -> V_56 , V_21 -> V_57 ) ;
F_19 ( V_21 ) ;
F_45 ( & V_58 ) ;
}
V_55 -> V_80 = V_100 ;
F_70 ( & V_55 -> V_79 ) ;
F_87 ( V_55 -> V_56 ) ;
F_35 ( V_55 ) ;
V_78 [ type ] = NULL ;
}
static void F_88 ( unsigned type )
{
struct V_54 * V_55 ;
V_55 = F_89 ( sizeof( struct V_54 ) , V_41 ) ;
if ( ! V_55 )
goto V_65;
V_55 -> V_56 = F_90 ( V_41 , & V_101 ) ;
if ( ! V_55 -> V_56 )
goto V_102;
V_55 -> V_80 = V_100 ;
F_91 ( & V_55 -> V_79 ) ;
V_78 [ type ] = V_55 ;
return;
V_102:
F_35 ( V_55 ) ;
V_65:
F_31 ( L_5 , type ) ;
}
static int T_2 F_92 ( void )
{
if ( ! F_93 () )
return - V_16 ;
V_103 = F_94 ( L_6 , NULL ) ;
if ( ! V_103 )
return - V_17 ;
F_95 ( L_7 , V_104 ,
V_103 , & V_89 ) ;
F_95 ( L_8 , V_104 ,
V_103 , & V_90 ) ;
F_95 ( L_9 , V_104 ,
V_103 , & V_97 ) ;
F_95 ( L_10 , V_104 ,
V_103 , & V_91 ) ;
F_95 ( L_11 , V_104 ,
V_103 , & V_96 ) ;
F_95 ( L_12 , V_104 ,
V_103 , & V_84 ) ;
F_95 ( L_13 , V_104 ,
V_103 , & V_98 ) ;
F_95 ( L_14 , V_104 ,
V_103 , & V_53 ) ;
F_96 ( L_15 , V_104 ,
V_103 , & V_58 ) ;
return 0 ;
}
static void T_6 F_97 ( void )
{
F_98 ( V_103 ) ;
}
static int T_2 F_92 ( void )
{
return 0 ;
}
static void T_6 F_97 ( void ) { }
static int T_2 F_99 ( void )
{
if ( ! V_105 )
return 0 ;
F_9 ( L_16 ) ;
if ( F_13 () ) {
F_31 ( L_17 ) ;
goto error;
}
if ( F_7 () ) {
F_31 ( L_18 ) ;
goto V_106;
}
if ( F_37 () ) {
F_31 ( L_19 ) ;
goto V_107;
}
F_100 ( & V_108 ) ;
if ( F_92 () )
F_101 ( L_20 ) ;
return 0 ;
V_107:
F_11 () ;
V_106:
F_15 () ;
error:
return - V_17 ;
}
