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
return V_18 == NULL ;
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
static int F_48 ( void )
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
V_39 ;
}
static int F_54 ( T_5 V_21 ,
struct V_60 * * V_61 )
{
struct V_60 * V_62 , * V_63 = NULL ;
struct V_64 * V_65 = F_55 ( V_21 ) ;
int V_66 ;
* V_61 = NULL ;
do {
V_62 = F_56 ( V_65 , V_21 . V_67 ) ;
if ( V_62 )
break;
if ( ! V_63 ) {
V_63 = F_57 ( V_48 ) ;
if ( ! V_63 )
break;
}
V_66 = F_58 ( V_48 ) ;
if ( V_66 )
break;
V_66 = F_59 ( V_21 ) ;
if ( V_66 == - V_35 ) {
F_60 () ;
continue;
}
if ( V_66 ) {
F_60 () ;
break;
}
F_61 ( V_63 ) ;
F_62 ( V_63 ) ;
V_66 = F_63 ( V_63 , V_21 ) ;
if ( F_64 ( ! V_66 ) ) {
F_60 () ;
F_65 ( V_63 ) ;
* V_61 = V_63 ;
return V_68 ;
}
F_60 () ;
F_66 ( V_63 ) ;
F_67 ( V_63 ) ;
F_68 ( V_21 , NULL ) ;
} while ( V_66 != - V_17 );
if ( V_63 )
F_69 ( V_63 ) ;
if ( ! V_62 )
return V_69 ;
* V_61 = V_62 ;
return V_70 ;
}
static int F_70 ( struct V_71 * V_72 , unsigned long V_37 )
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
V_74 = F_71 ( V_72 , V_37 ) ;
V_75 = V_74 -> V_75 ;
F_72 ( V_72 , V_37 ) ;
V_41 = V_80 [ F_73 ( V_75 ) ] ;
V_26 = F_74 ( V_75 ) ;
F_75 ( & V_41 -> V_81 ) ;
V_21 = F_37 ( & V_41 -> V_42 , V_26 ) ;
if ( ! V_21 ) {
F_76 ( & V_41 -> V_81 ) ;
return 0 ;
}
F_76 ( & V_41 -> V_81 ) ;
F_36 ( V_26 != V_21 -> V_26 ) ;
switch ( F_54 ( V_75 , & V_60 ) ) {
case V_69 :
V_9 = - V_17 ;
goto V_82;
case V_70 :
F_69 ( V_60 ) ;
V_9 = - V_35 ;
goto V_82;
case V_68 :
V_6 = V_47 ;
V_3 = ( T_1 * ) F_71 ( V_36 , V_21 -> V_37 ) +
sizeof( struct V_73 ) ;
V_5 = F_77 ( V_60 ) ;
V_9 = F_1 ( V_12 , V_3 ,
V_21 -> V_83 , V_5 , & V_6 ) ;
F_78 ( V_5 ) ;
F_72 ( V_36 , V_21 -> V_37 ) ;
F_36 ( V_9 ) ;
F_36 ( V_6 != V_47 ) ;
F_79 ( V_60 ) ;
}
F_80 ( V_60 ) ;
F_81 ( V_60 , & V_77 , V_84 ) ;
F_69 ( V_60 ) ;
V_85 ++ ;
F_75 ( & V_41 -> V_81 ) ;
F_35 ( V_41 , V_21 ) ;
if ( V_21 == F_22 ( & V_41 -> V_42 , V_26 ) )
F_35 ( V_41 , V_21 ) ;
F_76 ( & V_41 -> V_81 ) ;
goto V_86;
V_82:
F_75 ( & V_41 -> V_81 ) ;
F_35 ( V_41 , V_21 ) ;
F_76 ( & V_41 -> V_81 ) ;
V_86:
return V_9 ;
}
static int F_82 ( unsigned type , T_4 V_26 ,
struct V_60 * V_60 )
{
struct V_40 * V_41 = V_80 [ type ] ;
struct V_19 * V_21 , * V_31 ;
int V_9 ;
unsigned int V_6 = V_47 , V_87 ;
unsigned long V_37 ;
char * V_88 ;
T_1 * V_3 , * V_5 ;
struct V_73 * V_74 ;
if ( ! V_41 ) {
V_9 = - V_16 ;
goto V_89;
}
if ( F_53 () ) {
V_90 ++ ;
if ( F_83 ( V_36 , 8 ) ) {
V_91 ++ ;
V_9 = - V_17 ;
goto V_89;
}
}
V_21 = F_17 ( V_48 ) ;
if ( ! V_21 ) {
V_92 ++ ;
V_9 = - V_17 ;
goto V_89;
}
V_5 = F_84 ( V_49 ) ;
V_3 = F_77 ( V_60 ) ;
V_9 = F_1 ( V_11 , V_3 , V_47 , V_5 , & V_6 ) ;
F_78 ( V_3 ) ;
if ( V_9 ) {
V_9 = - V_13 ;
goto V_93;
}
V_87 = V_6 + sizeof( struct V_73 ) ;
V_9 = F_85 ( V_36 , V_87 , V_94 | V_95 ,
& V_37 ) ;
if ( V_9 == - V_96 ) {
V_97 ++ ;
goto V_93;
}
if ( V_9 ) {
V_98 ++ ;
goto V_93;
}
V_74 = F_71 ( V_36 , V_37 ) ;
V_74 -> V_75 = F_86 ( type , V_26 ) ;
V_88 = ( T_1 * ) ( V_74 + 1 ) ;
memcpy ( V_88 , V_5 , V_6 ) ;
F_72 ( V_36 , V_37 ) ;
F_87 ( V_49 ) ;
V_21 -> V_26 = V_26 ;
V_21 -> V_37 = V_37 ;
V_21 -> V_83 = V_6 ;
F_75 ( & V_41 -> V_81 ) ;
do {
V_9 = F_24 ( & V_41 -> V_42 , V_21 , & V_31 ) ;
if ( V_9 == - V_35 ) {
V_99 ++ ;
F_27 ( & V_41 -> V_42 , V_31 ) ;
F_35 ( V_41 , V_31 ) ;
}
} while ( V_9 == - V_35 );
F_76 ( & V_41 -> V_81 ) ;
F_88 ( & V_38 ) ;
V_39 = F_33 ( V_36 ) ;
return 0 ;
V_93:
F_87 ( V_49 ) ;
F_20 ( V_21 ) ;
V_89:
return V_9 ;
}
static int F_89 ( unsigned type , T_4 V_26 ,
struct V_60 * V_60 )
{
struct V_40 * V_41 = V_80 [ type ] ;
struct V_19 * V_21 ;
T_1 * V_3 , * V_5 ;
unsigned int V_6 ;
int V_9 ;
F_75 ( & V_41 -> V_81 ) ;
V_21 = F_37 ( & V_41 -> V_42 , V_26 ) ;
if ( ! V_21 ) {
F_76 ( & V_41 -> V_81 ) ;
return - 1 ;
}
F_76 ( & V_41 -> V_81 ) ;
V_6 = V_47 ;
V_3 = ( T_1 * ) F_71 ( V_36 , V_21 -> V_37 ) +
sizeof( struct V_73 ) ;
V_5 = F_77 ( V_60 ) ;
V_9 = F_1 ( V_12 , V_3 , V_21 -> V_83 ,
V_5 , & V_6 ) ;
F_78 ( V_5 ) ;
F_72 ( V_36 , V_21 -> V_37 ) ;
F_36 ( V_9 ) ;
F_75 ( & V_41 -> V_81 ) ;
F_35 ( V_41 , V_21 ) ;
F_76 ( & V_41 -> V_81 ) ;
return 0 ;
}
static void F_90 ( unsigned type , T_4 V_26 )
{
struct V_40 * V_41 = V_80 [ type ] ;
struct V_19 * V_21 ;
F_75 ( & V_41 -> V_81 ) ;
V_21 = F_22 ( & V_41 -> V_42 , V_26 ) ;
if ( ! V_21 ) {
F_76 ( & V_41 -> V_81 ) ;
return;
}
F_27 ( & V_41 -> V_42 , V_21 ) ;
F_35 ( V_41 , V_21 ) ;
F_76 ( & V_41 -> V_81 ) ;
}
static void F_91 ( unsigned type )
{
struct V_40 * V_41 = V_80 [ type ] ;
struct V_19 * V_21 , * V_100 ;
if ( ! V_41 )
return;
F_75 ( & V_41 -> V_81 ) ;
F_92 (entry, n, &tree->rbroot, rbnode)
F_30 ( V_21 ) ;
V_41 -> V_42 = V_101 ;
F_76 ( & V_41 -> V_81 ) ;
F_46 ( V_41 ) ;
V_80 [ type ] = NULL ;
}
static void F_93 ( unsigned type )
{
struct V_40 * V_41 ;
V_41 = F_94 ( sizeof( struct V_40 ) , V_48 ) ;
if ( ! V_41 ) {
F_41 ( L_5 , type ) ;
return;
}
V_41 -> V_42 = V_101 ;
F_95 ( & V_41 -> V_81 ) ;
V_80 [ type ] = V_41 ;
}
static int T_2 F_96 ( void )
{
if ( ! F_97 () )
return - V_16 ;
V_102 = F_98 ( L_6 , NULL ) ;
if ( ! V_102 )
return - V_17 ;
F_99 ( L_7 , V_103 ,
V_102 , & V_90 ) ;
F_99 ( L_8 , V_103 ,
V_102 , & V_91 ) ;
F_99 ( L_9 , V_103 ,
V_102 , & V_98 ) ;
F_99 ( L_10 , V_103 ,
V_102 , & V_92 ) ;
F_99 ( L_11 , V_103 ,
V_102 , & V_97 ) ;
F_99 ( L_12 , V_103 ,
V_102 , & V_85 ) ;
F_99 ( L_13 , V_103 ,
V_102 , & V_99 ) ;
F_99 ( L_14 , V_103 ,
V_102 , & V_39 ) ;
F_100 ( L_15 , V_103 ,
V_102 , & V_38 ) ;
return 0 ;
}
static void T_6 F_101 ( void )
{
F_102 ( V_102 ) ;
}
static int T_2 F_96 ( void )
{
return 0 ;
}
static void T_6 F_101 ( void ) { }
static int T_2 F_103 ( void )
{
if ( ! V_104 )
return 0 ;
F_9 ( L_16 ) ;
V_36 = F_104 ( V_48 , & V_105 ) ;
if ( ! V_36 ) {
F_41 ( L_17 ) ;
goto error;
}
if ( F_13 () ) {
F_41 ( L_18 ) ;
goto V_106;
}
if ( F_7 () ) {
F_41 ( L_19 ) ;
goto V_107;
}
if ( F_48 () ) {
F_41 ( L_20 ) ;
goto V_108;
}
F_105 ( & V_109 ) ;
if ( F_96 () )
F_106 ( L_21 ) ;
return 0 ;
V_108:
F_11 () ;
V_107:
F_15 () ;
V_106:
F_107 ( V_36 ) ;
error:
return - V_17 ;
}
