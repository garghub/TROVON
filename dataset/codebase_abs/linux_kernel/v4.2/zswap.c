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
static void T_2 F_11 ( void )
{
F_12 ( V_10 ) ;
}
static int T_2 F_13 ( void )
{
V_18 = F_14 ( V_19 , 0 ) ;
return V_18 == NULL ;
}
static void T_2 F_15 ( void )
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
F_19 ( & V_21 -> V_23 ) ;
return V_21 ;
}
static void F_20 ( struct V_19 * V_21 )
{
F_21 ( V_18 , V_21 ) ;
}
static struct V_19 * F_22 ( struct V_24 * V_25 , T_4 V_26 )
{
struct V_27 * V_28 = V_25 -> V_27 ;
struct V_19 * V_21 ;
while ( V_28 ) {
V_21 = F_23 ( V_28 , struct V_19 , V_23 ) ;
if ( V_21 -> V_26 > V_26 )
V_28 = V_28 -> V_29 ;
else if ( V_21 -> V_26 < V_26 )
V_28 = V_28 -> V_30 ;
else
return V_21 ;
}
return NULL ;
}
static int F_24 ( struct V_24 * V_25 , struct V_19 * V_21 ,
struct V_19 * * V_31 )
{
struct V_27 * * V_32 = & V_25 -> V_27 , * V_33 = NULL ;
struct V_19 * V_34 ;
while ( * V_32 ) {
V_33 = * V_32 ;
V_34 = F_23 ( V_33 , struct V_19 , V_23 ) ;
if ( V_34 -> V_26 > V_21 -> V_26 )
V_32 = & ( * V_32 ) -> V_29 ;
else if ( V_34 -> V_26 < V_21 -> V_26 )
V_32 = & ( * V_32 ) -> V_30 ;
else {
* V_31 = V_34 ;
return - V_35 ;
}
}
F_25 ( & V_21 -> V_23 , V_33 , V_32 ) ;
F_26 ( & V_21 -> V_23 , V_25 ) ;
return 0 ;
}
static void F_27 ( struct V_24 * V_25 , struct V_19 * V_21 )
{
if ( ! F_28 ( & V_21 -> V_23 ) ) {
F_29 ( & V_21 -> V_23 , V_25 ) ;
F_19 ( & V_21 -> V_23 ) ;
}
}
static void F_30 ( struct V_19 * V_21 )
{
F_31 ( V_36 , V_21 -> V_37 ) ;
F_20 ( V_21 ) ;
F_32 ( & V_38 ) ;
V_39 = F_33 ( V_36 ) ;
}
static void F_34 ( struct V_19 * V_21 )
{
V_21 -> V_22 ++ ;
}
static void F_35 ( struct V_40 * V_41 ,
struct V_19 * V_21 )
{
int V_22 = -- V_21 -> V_22 ;
F_36 ( V_22 < 0 ) ;
if ( V_22 == 0 ) {
F_27 ( & V_41 -> V_42 , V_21 ) ;
F_30 ( V_21 ) ;
}
}
static struct V_19 * F_37 ( struct V_24 * V_25 ,
T_4 V_26 )
{
struct V_19 * V_21 = NULL ;
V_21 = F_22 ( V_25 , V_26 ) ;
if ( V_21 )
F_34 ( V_21 ) ;
return V_21 ;
}
static int F_38 ( unsigned long V_43 , unsigned long V_44 )
{
struct V_7 * V_8 ;
T_1 * V_5 ;
switch ( V_43 ) {
case V_45 :
V_8 = F_39 ( V_14 , 0 , 0 ) ;
if ( F_40 ( V_8 ) ) {
F_41 ( L_3 ) ;
return V_46 ;
}
* F_2 ( V_10 , V_44 ) = V_8 ;
V_5 = F_42 ( V_47 * 2 , V_48 , F_43 ( V_44 ) ) ;
if ( ! V_5 ) {
F_41 ( L_4 ) ;
F_44 ( V_8 ) ;
* F_2 ( V_10 , V_44 ) = NULL ;
return V_46 ;
}
F_45 ( V_49 , V_44 ) = V_5 ;
break;
case V_50 :
case V_51 :
V_8 = * F_2 ( V_10 , V_44 ) ;
if ( V_8 ) {
F_44 ( V_8 ) ;
* F_2 ( V_10 , V_44 ) = NULL ;
}
V_5 = F_45 ( V_49 , V_44 ) ;
F_46 ( V_5 ) ;
F_45 ( V_49 , V_44 ) = NULL ;
break;
default:
break;
}
return V_52 ;
}
static int F_47 ( struct V_53 * V_54 ,
unsigned long V_43 , void * V_55 )
{
unsigned long V_44 = ( unsigned long ) V_55 ;
return F_38 ( V_43 , V_44 ) ;
}
static int T_2 F_48 ( void )
{
unsigned long V_44 ;
F_49 () ;
F_50 (cpu)
if ( F_38 ( V_45 , V_44 ) != V_52 )
goto V_56;
F_51 ( & V_57 ) ;
F_52 () ;
return 0 ;
V_56:
F_50 (cpu)
F_38 ( V_51 , V_44 ) ;
F_52 () ;
return - V_17 ;
}
static bool F_53 ( void )
{
return V_58 * V_59 / 100 <
F_54 ( V_39 , V_47 ) ;
}
static int F_55 ( T_5 V_21 ,
struct V_60 * * V_61 )
{
struct V_60 * V_62 , * V_63 = NULL ;
struct V_64 * V_65 = F_56 ( V_21 ) ;
int V_66 ;
* V_61 = NULL ;
do {
V_62 = F_57 ( V_65 , V_21 . V_67 ) ;
if ( V_62 )
break;
if ( ! V_63 ) {
V_63 = F_58 ( V_48 ) ;
if ( ! V_63 )
break;
}
V_66 = F_59 ( V_48 ) ;
if ( V_66 )
break;
V_66 = F_60 ( V_21 ) ;
if ( V_66 == - V_35 ) {
F_61 () ;
continue;
}
if ( V_66 ) {
F_61 () ;
break;
}
F_62 ( V_63 ) ;
F_63 ( V_63 ) ;
V_66 = F_64 ( V_63 , V_21 ) ;
if ( F_65 ( ! V_66 ) ) {
F_61 () ;
F_66 ( V_63 ) ;
* V_61 = V_63 ;
return V_68 ;
}
F_61 () ;
F_67 ( V_63 ) ;
F_68 ( V_63 ) ;
F_69 ( V_21 ) ;
} while ( V_66 != - V_17 );
if ( V_63 )
F_70 ( V_63 ) ;
if ( ! V_62 )
return V_69 ;
* V_61 = V_62 ;
return V_70 ;
}
static int F_71 ( struct V_71 * V_72 , unsigned long V_37 )
{
struct V_73 * V_74 ;
T_5 V_75 ;
struct V_40 * V_41 ;
T_4 V_26 ;
struct V_19 * V_21 ;
struct V_60 * V_60 ;
T_1 * V_3 , * V_5 ;
unsigned int V_6 ;
int V_9 ;
struct V_76 V_77 = {
. V_78 = V_79 ,
} ;
V_74 = F_72 ( V_72 , V_37 , V_80 ) ;
V_75 = V_74 -> V_75 ;
F_73 ( V_72 , V_37 ) ;
V_41 = V_81 [ F_74 ( V_75 ) ] ;
V_26 = F_75 ( V_75 ) ;
F_76 ( & V_41 -> V_82 ) ;
V_21 = F_37 ( & V_41 -> V_42 , V_26 ) ;
if ( ! V_21 ) {
F_77 ( & V_41 -> V_82 ) ;
return 0 ;
}
F_77 ( & V_41 -> V_82 ) ;
F_36 ( V_26 != V_21 -> V_26 ) ;
switch ( F_55 ( V_75 , & V_60 ) ) {
case V_69 :
V_9 = - V_17 ;
goto V_83;
case V_70 :
F_70 ( V_60 ) ;
V_9 = - V_35 ;
goto V_83;
case V_68 :
V_6 = V_47 ;
V_3 = ( T_1 * ) F_72 ( V_36 , V_21 -> V_37 ,
V_80 ) + sizeof( struct V_73 ) ;
V_5 = F_78 ( V_60 ) ;
V_9 = F_1 ( V_12 , V_3 ,
V_21 -> V_84 , V_5 , & V_6 ) ;
F_79 ( V_5 ) ;
F_73 ( V_36 , V_21 -> V_37 ) ;
F_36 ( V_9 ) ;
F_36 ( V_6 != V_47 ) ;
F_80 ( V_60 ) ;
}
F_81 ( V_60 ) ;
F_82 ( V_60 , & V_77 , V_85 ) ;
F_70 ( V_60 ) ;
V_86 ++ ;
F_76 ( & V_41 -> V_82 ) ;
F_35 ( V_41 , V_21 ) ;
if ( V_21 == F_22 ( & V_41 -> V_42 , V_26 ) )
F_35 ( V_41 , V_21 ) ;
F_77 ( & V_41 -> V_82 ) ;
goto V_87;
V_83:
F_76 ( & V_41 -> V_82 ) ;
F_35 ( V_41 , V_21 ) ;
F_77 ( & V_41 -> V_82 ) ;
V_87:
return V_9 ;
}
static int F_83 ( unsigned type , T_4 V_26 ,
struct V_60 * V_60 )
{
struct V_40 * V_41 = V_81 [ type ] ;
struct V_19 * V_21 , * V_31 ;
int V_9 ;
unsigned int V_6 = V_47 , V_88 ;
unsigned long V_37 ;
char * V_89 ;
T_1 * V_3 , * V_5 ;
struct V_73 * V_74 ;
if ( ! V_90 || ! V_41 ) {
V_9 = - V_16 ;
goto V_91;
}
if ( F_53 () ) {
V_92 ++ ;
if ( F_84 ( V_36 , 1 , NULL ) ) {
V_93 ++ ;
V_9 = - V_17 ;
goto V_91;
}
}
V_21 = F_17 ( V_48 ) ;
if ( ! V_21 ) {
V_94 ++ ;
V_9 = - V_17 ;
goto V_91;
}
V_5 = F_85 ( V_49 ) ;
V_3 = F_78 ( V_60 ) ;
V_9 = F_1 ( V_11 , V_3 , V_47 , V_5 , & V_6 ) ;
F_79 ( V_3 ) ;
if ( V_9 ) {
V_9 = - V_13 ;
goto V_95;
}
V_88 = V_6 + sizeof( struct V_73 ) ;
V_9 = F_86 ( V_36 , V_88 , V_96 | V_97 ,
& V_37 ) ;
if ( V_9 == - V_98 ) {
V_99 ++ ;
goto V_95;
}
if ( V_9 ) {
V_100 ++ ;
goto V_95;
}
V_74 = F_72 ( V_36 , V_37 , V_101 ) ;
V_74 -> V_75 = F_87 ( type , V_26 ) ;
V_89 = ( T_1 * ) ( V_74 + 1 ) ;
memcpy ( V_89 , V_5 , V_6 ) ;
F_73 ( V_36 , V_37 ) ;
F_88 ( V_49 ) ;
V_21 -> V_26 = V_26 ;
V_21 -> V_37 = V_37 ;
V_21 -> V_84 = V_6 ;
F_76 ( & V_41 -> V_82 ) ;
do {
V_9 = F_24 ( & V_41 -> V_42 , V_21 , & V_31 ) ;
if ( V_9 == - V_35 ) {
V_102 ++ ;
F_27 ( & V_41 -> V_42 , V_31 ) ;
F_35 ( V_41 , V_31 ) ;
}
} while ( V_9 == - V_35 );
F_77 ( & V_41 -> V_82 ) ;
F_89 ( & V_38 ) ;
V_39 = F_33 ( V_36 ) ;
return 0 ;
V_95:
F_88 ( V_49 ) ;
F_20 ( V_21 ) ;
V_91:
return V_9 ;
}
static int F_90 ( unsigned type , T_4 V_26 ,
struct V_60 * V_60 )
{
struct V_40 * V_41 = V_81 [ type ] ;
struct V_19 * V_21 ;
T_1 * V_3 , * V_5 ;
unsigned int V_6 ;
int V_9 ;
F_76 ( & V_41 -> V_82 ) ;
V_21 = F_37 ( & V_41 -> V_42 , V_26 ) ;
if ( ! V_21 ) {
F_77 ( & V_41 -> V_82 ) ;
return - 1 ;
}
F_77 ( & V_41 -> V_82 ) ;
V_6 = V_47 ;
V_3 = ( T_1 * ) F_72 ( V_36 , V_21 -> V_37 ,
V_80 ) + sizeof( struct V_73 ) ;
V_5 = F_78 ( V_60 ) ;
V_9 = F_1 ( V_12 , V_3 , V_21 -> V_84 ,
V_5 , & V_6 ) ;
F_79 ( V_5 ) ;
F_73 ( V_36 , V_21 -> V_37 ) ;
F_36 ( V_9 ) ;
F_76 ( & V_41 -> V_82 ) ;
F_35 ( V_41 , V_21 ) ;
F_77 ( & V_41 -> V_82 ) ;
return 0 ;
}
static void F_91 ( unsigned type , T_4 V_26 )
{
struct V_40 * V_41 = V_81 [ type ] ;
struct V_19 * V_21 ;
F_76 ( & V_41 -> V_82 ) ;
V_21 = F_22 ( & V_41 -> V_42 , V_26 ) ;
if ( ! V_21 ) {
F_77 ( & V_41 -> V_82 ) ;
return;
}
F_27 ( & V_41 -> V_42 , V_21 ) ;
F_35 ( V_41 , V_21 ) ;
F_77 ( & V_41 -> V_82 ) ;
}
static void F_92 ( unsigned type )
{
struct V_40 * V_41 = V_81 [ type ] ;
struct V_19 * V_21 , * V_103 ;
if ( ! V_41 )
return;
F_76 ( & V_41 -> V_82 ) ;
F_93 (entry, n, &tree->rbroot, rbnode)
F_30 ( V_21 ) ;
V_41 -> V_42 = V_104 ;
F_77 ( & V_41 -> V_82 ) ;
F_46 ( V_41 ) ;
V_81 [ type ] = NULL ;
}
static void F_94 ( unsigned type )
{
struct V_40 * V_41 ;
V_41 = F_95 ( sizeof( struct V_40 ) , V_48 ) ;
if ( ! V_41 ) {
F_41 ( L_5 , type ) ;
return;
}
V_41 -> V_42 = V_104 ;
F_96 ( & V_41 -> V_82 ) ;
V_81 [ type ] = V_41 ;
}
static int T_2 F_97 ( void )
{
if ( ! F_98 () )
return - V_16 ;
V_105 = F_99 ( L_6 , NULL ) ;
if ( ! V_105 )
return - V_17 ;
F_100 ( L_7 , V_106 ,
V_105 , & V_92 ) ;
F_100 ( L_8 , V_106 ,
V_105 , & V_93 ) ;
F_100 ( L_9 , V_106 ,
V_105 , & V_100 ) ;
F_100 ( L_10 , V_106 ,
V_105 , & V_94 ) ;
F_100 ( L_11 , V_106 ,
V_105 , & V_99 ) ;
F_100 ( L_12 , V_106 ,
V_105 , & V_86 ) ;
F_100 ( L_13 , V_106 ,
V_105 , & V_102 ) ;
F_100 ( L_14 , V_106 ,
V_105 , & V_39 ) ;
F_101 ( L_15 , V_106 ,
V_105 , & V_38 ) ;
return 0 ;
}
static void T_6 F_102 ( void )
{
F_103 ( V_105 ) ;
}
static int T_2 F_97 ( void )
{
return 0 ;
}
static void T_6 F_102 ( void ) { }
static int T_2 F_104 ( void )
{
T_3 V_20 = V_96 | V_97 ;
F_9 ( L_16 ) ;
V_36 = F_105 ( V_107 , L_6 , V_20 ,
& V_108 ) ;
if ( ! V_36 && strcmp ( V_107 , V_109 ) ) {
F_9 ( L_17 , V_107 ) ;
V_107 = V_109 ;
V_36 = F_105 ( V_107 , L_6 , V_20 ,
& V_108 ) ;
}
if ( ! V_36 ) {
F_41 ( L_17 , V_107 ) ;
F_41 ( L_18 ) ;
goto error;
}
F_9 ( L_19 , V_107 ) ;
if ( F_13 () ) {
F_41 ( L_20 ) ;
goto V_110;
}
if ( F_7 () ) {
F_41 ( L_21 ) ;
goto V_111;
}
if ( F_48 () ) {
F_41 ( L_22 ) ;
goto V_112;
}
F_106 ( & V_113 ) ;
if ( F_97 () )
F_107 ( L_23 ) ;
return 0 ;
V_112:
F_11 () ;
V_111:
F_15 () ;
V_110:
F_108 ( V_36 ) ;
error:
return - V_17 ;
}
