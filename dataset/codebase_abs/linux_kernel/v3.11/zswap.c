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
struct V_63 * V_64 = & V_65 [ F_48 ( V_21 ) ] ;
int V_66 ;
* V_60 = NULL ;
do {
V_61 = F_49 ( V_64 , V_21 . V_67 ) ;
if ( V_61 )
break;
if ( ! V_62 ) {
V_62 = F_50 ( V_41 ) ;
if ( ! V_62 )
break;
}
V_66 = F_51 ( V_41 ) ;
if ( V_66 )
break;
V_66 = F_52 ( V_21 ) ;
if ( V_66 == - V_35 ) {
F_53 () ;
continue;
}
if ( V_66 ) {
F_53 () ;
break;
}
F_54 ( V_62 ) ;
F_55 ( V_62 ) ;
V_66 = F_56 ( V_62 , V_21 ) ;
if ( F_57 ( ! V_66 ) ) {
F_53 () ;
F_58 ( V_62 ) ;
* V_60 = V_62 ;
return V_68 ;
}
F_53 () ;
F_59 ( V_62 ) ;
F_60 ( V_62 ) ;
F_61 ( V_21 , NULL ) ;
} while ( V_66 != - V_17 );
if ( V_62 )
F_62 ( V_62 ) ;
if ( ! V_61 )
return V_69 ;
* V_60 = V_61 ;
return V_70 ;
}
static int F_63 ( struct V_71 * V_56 , unsigned long V_57 )
{
struct V_72 * V_73 ;
T_5 V_74 ;
struct V_54 * V_55 ;
T_4 V_25 ;
struct V_19 * V_21 ;
struct V_59 * V_59 ;
T_1 * V_3 , * V_5 ;
unsigned int V_6 ;
int V_9 , V_22 ;
struct V_75 V_76 = {
. V_77 = V_78 ,
} ;
V_73 = F_64 ( V_56 , V_57 ) ;
V_74 = V_73 -> V_74 ;
F_65 ( V_56 , V_57 ) ;
V_55 = V_79 [ F_48 ( V_74 ) ] ;
V_25 = F_66 ( V_74 ) ;
F_67 ( V_56 != V_55 -> V_56 ) ;
F_68 ( & V_55 -> V_80 ) ;
V_21 = F_23 ( & V_55 -> V_81 , V_25 ) ;
if ( ! V_21 ) {
F_69 ( & V_55 -> V_80 ) ;
return 0 ;
}
F_21 ( V_21 ) ;
F_69 ( & V_55 -> V_80 ) ;
F_67 ( V_25 != V_21 -> V_25 ) ;
switch ( F_47 ( V_74 , & V_59 ) ) {
case V_69 :
V_9 = - V_17 ;
goto V_82;
case V_70 :
F_62 ( V_59 ) ;
V_9 = - V_35 ;
goto V_82;
case V_68 :
V_6 = V_40 ;
V_3 = ( T_1 * ) F_64 ( V_55 -> V_56 , V_21 -> V_57 ) +
sizeof( struct V_72 ) ;
V_5 = F_70 ( V_59 ) ;
V_9 = F_1 ( V_12 , V_3 ,
V_21 -> V_83 , V_5 , & V_6 ) ;
F_71 ( V_5 ) ;
F_65 ( V_55 -> V_56 , V_21 -> V_57 ) ;
F_67 ( V_9 ) ;
F_67 ( V_6 != V_40 ) ;
F_72 ( V_59 ) ;
}
F_73 ( V_59 , & V_76 , V_84 ) ;
F_62 ( V_59 ) ;
V_85 ++ ;
F_68 ( & V_55 -> V_80 ) ;
F_22 ( V_21 ) ;
V_22 = F_22 ( V_21 ) ;
if ( V_22 >= 0 ) {
F_74 ( & V_21 -> V_28 , & V_55 -> V_81 ) ;
}
F_69 ( & V_55 -> V_80 ) ;
if ( V_22 <= 0 ) {
F_43 ( V_55 , V_21 ) ;
return 0 ;
}
return - V_86 ;
V_82:
F_68 ( & V_55 -> V_80 ) ;
F_22 ( V_21 ) ;
F_69 ( & V_55 -> V_80 ) ;
return V_9 ;
}
static int F_75 ( unsigned type , T_4 V_25 ,
struct V_59 * V_59 )
{
struct V_54 * V_55 = V_79 [ type ] ;
struct V_19 * V_21 , * V_31 ;
int V_9 ;
unsigned int V_6 = V_40 , V_87 ;
unsigned long V_57 ;
char * V_88 ;
T_1 * V_3 , * V_5 ;
struct V_72 * V_73 ;
if ( ! V_55 ) {
V_9 = - V_16 ;
goto V_89;
}
if ( F_42 () ) {
V_90 ++ ;
if ( F_76 ( V_55 -> V_56 , 8 ) ) {
V_91 ++ ;
V_9 = - V_17 ;
goto V_89;
}
}
V_21 = F_17 ( V_41 ) ;
if ( ! V_21 ) {
V_92 ++ ;
V_9 = - V_17 ;
goto V_89;
}
V_5 = F_77 ( V_42 ) ;
V_3 = F_70 ( V_59 ) ;
V_9 = F_1 ( V_11 , V_3 , V_40 , V_5 , & V_6 ) ;
F_71 ( V_3 ) ;
if ( V_9 ) {
V_9 = - V_13 ;
goto V_93;
}
V_87 = V_6 + sizeof( struct V_72 ) ;
V_9 = F_78 ( V_55 -> V_56 , V_87 , V_94 | V_95 ,
& V_57 ) ;
if ( V_9 == - V_96 ) {
V_97 ++ ;
goto V_93;
}
if ( V_9 ) {
V_98 ++ ;
goto V_93;
}
V_73 = F_64 ( V_55 -> V_56 , V_57 ) ;
V_73 -> V_74 = F_79 ( type , V_25 ) ;
V_88 = ( T_1 * ) ( V_73 + 1 ) ;
memcpy ( V_88 , V_5 , V_6 ) ;
F_65 ( V_55 -> V_56 , V_57 ) ;
F_80 ( V_42 ) ;
V_21 -> V_25 = V_25 ;
V_21 -> V_57 = V_57 ;
V_21 -> V_83 = V_6 ;
F_68 ( & V_55 -> V_80 ) ;
do {
V_9 = F_25 ( & V_55 -> V_81 , V_21 , & V_31 ) ;
if ( V_9 == - V_35 ) {
V_99 ++ ;
F_74 ( & V_31 -> V_28 , & V_55 -> V_81 ) ;
if ( ! F_22 ( V_31 ) ) {
F_43 ( V_55 , V_31 ) ;
}
}
} while ( V_9 == - V_35 );
F_69 ( & V_55 -> V_80 ) ;
F_81 ( & V_58 ) ;
V_53 = F_46 ( V_55 -> V_56 ) ;
return 0 ;
V_93:
F_80 ( V_42 ) ;
F_19 ( V_21 ) ;
V_89:
return V_9 ;
}
static int F_82 ( unsigned type , T_4 V_25 ,
struct V_59 * V_59 )
{
struct V_54 * V_55 = V_79 [ type ] ;
struct V_19 * V_21 ;
T_1 * V_3 , * V_5 ;
unsigned int V_6 ;
int V_22 , V_9 ;
F_68 ( & V_55 -> V_80 ) ;
V_21 = F_23 ( & V_55 -> V_81 , V_25 ) ;
if ( ! V_21 ) {
F_69 ( & V_55 -> V_80 ) ;
return - 1 ;
}
F_21 ( V_21 ) ;
F_69 ( & V_55 -> V_80 ) ;
V_6 = V_40 ;
V_3 = ( T_1 * ) F_64 ( V_55 -> V_56 , V_21 -> V_57 ) +
sizeof( struct V_72 ) ;
V_5 = F_70 ( V_59 ) ;
V_9 = F_1 ( V_12 , V_3 , V_21 -> V_83 ,
V_5 , & V_6 ) ;
F_71 ( V_5 ) ;
F_65 ( V_55 -> V_56 , V_21 -> V_57 ) ;
F_67 ( V_9 ) ;
F_68 ( & V_55 -> V_80 ) ;
V_22 = F_22 ( V_21 ) ;
if ( F_57 ( V_22 ) ) {
F_69 ( & V_55 -> V_80 ) ;
return 0 ;
}
F_69 ( & V_55 -> V_80 ) ;
F_43 ( V_55 , V_21 ) ;
return 0 ;
}
static void F_83 ( unsigned type , T_4 V_25 )
{
struct V_54 * V_55 = V_79 [ type ] ;
struct V_19 * V_21 ;
int V_22 ;
F_68 ( & V_55 -> V_80 ) ;
V_21 = F_23 ( & V_55 -> V_81 , V_25 ) ;
if ( ! V_21 ) {
F_69 ( & V_55 -> V_80 ) ;
return;
}
F_74 ( & V_21 -> V_28 , & V_55 -> V_81 ) ;
V_22 = F_22 ( V_21 ) ;
F_69 ( & V_55 -> V_80 ) ;
if ( V_22 ) {
return;
}
F_43 ( V_55 , V_21 ) ;
}
static void F_84 ( unsigned type )
{
struct V_54 * V_55 = V_79 [ type ] ;
struct V_26 * V_27 ;
struct V_19 * V_21 ;
if ( ! V_55 )
return;
F_68 ( & V_55 -> V_80 ) ;
while ( ( V_27 = F_85 ( & V_55 -> V_81 ) ) ) {
V_21 = F_24 ( V_27 , struct V_19 , V_28 ) ;
F_74 ( & V_21 -> V_28 , & V_55 -> V_81 ) ;
F_44 ( V_55 -> V_56 , V_21 -> V_57 ) ;
F_19 ( V_21 ) ;
F_45 ( & V_58 ) ;
}
V_55 -> V_81 = V_100 ;
F_69 ( & V_55 -> V_80 ) ;
}
static void F_86 ( unsigned type )
{
struct V_54 * V_55 ;
V_55 = F_87 ( sizeof( struct V_54 ) , V_41 ) ;
if ( ! V_55 )
goto V_66;
V_55 -> V_56 = F_88 ( V_41 , & V_101 ) ;
if ( ! V_55 -> V_56 )
goto V_102;
V_55 -> V_81 = V_100 ;
F_89 ( & V_55 -> V_80 ) ;
V_79 [ type ] = V_55 ;
return;
V_102:
F_35 ( V_55 ) ;
V_66:
F_31 ( L_5 , type ) ;
}
static int T_2 F_90 ( void )
{
if ( ! F_91 () )
return - V_16 ;
V_103 = F_92 ( L_6 , NULL ) ;
if ( ! V_103 )
return - V_17 ;
F_93 ( L_7 , V_104 ,
V_103 , & V_90 ) ;
F_93 ( L_8 , V_104 ,
V_103 , & V_91 ) ;
F_93 ( L_9 , V_104 ,
V_103 , & V_98 ) ;
F_93 ( L_10 , V_104 ,
V_103 , & V_92 ) ;
F_93 ( L_11 , V_104 ,
V_103 , & V_97 ) ;
F_93 ( L_12 , V_104 ,
V_103 , & V_85 ) ;
F_93 ( L_13 , V_104 ,
V_103 , & V_99 ) ;
F_93 ( L_14 , V_104 ,
V_103 , & V_53 ) ;
F_94 ( L_15 , V_104 ,
V_103 , & V_58 ) ;
return 0 ;
}
static void T_6 F_95 ( void )
{
F_96 ( V_103 ) ;
}
static int T_2 F_90 ( void )
{
return 0 ;
}
static void T_6 F_95 ( void ) { }
static int T_2 F_97 ( void )
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
F_98 ( & V_108 ) ;
if ( F_90 () )
F_99 ( L_20 ) ;
return 0 ;
V_107:
F_11 () ;
V_106:
F_15 () ;
error:
return - V_17 ;
}
