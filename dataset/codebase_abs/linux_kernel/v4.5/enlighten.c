int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
T_1 * V_4 , int V_5 ,
int * V_6 , T_2 V_7 ,
unsigned V_8 ,
struct V_9 * * V_10 )
{
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , V_10 ) ;
}
int F_3 ( struct V_1 * V_2 ,
unsigned long V_3 ,
T_1 V_4 , int V_5 ,
T_2 V_7 , unsigned V_8 ,
struct V_9 * * V_10 )
{
return - V_11 ;
}
int F_4 ( struct V_1 * V_2 ,
int V_5 , struct V_9 * * V_10 )
{
return F_5 ( V_2 , V_5 , V_10 ) ;
}
static unsigned long long F_6 ( int V_12 )
{
struct V_13 V_14 ;
F_7 ( V_12 != F_8 () ) ;
F_9 ( & V_14 ) ;
F_10 ( V_14 . V_14 != V_15 ) ;
return V_14 . time [ V_16 ] + V_14 . time [ V_17 ] ;
}
static void F_11 ( struct V_18 * V_19 )
{
T_3 V_20 ;
struct V_18 V_21 , V_22 ;
struct V_23 * V_24 = V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
do {
V_20 = V_27 -> V_20 ;
F_12 () ;
V_21 . V_29 = ( ( V_30 ) V_27 -> V_31 << 32 ) | V_27 -> V_32 ;
V_21 . V_33 = V_27 -> V_34 ;
F_12 () ;
} while ( ( V_27 -> V_20 & 1 ) || ( V_20 != V_27 -> V_20 ) );
F_13 ( & V_22 ) ;
* V_19 = F_14 ( V_21 , V_22 ) ;
}
static int F_15 ( struct V_35 * V_36 ,
unsigned long V_37 , void * V_38 )
{
static struct V_18 V_39 ;
struct V_40 V_41 ;
struct V_18 V_21 , V_42 ;
struct V_43 * V_44 = V_38 ;
V_21 . V_29 = V_44 -> V_45 ;
V_21 . V_33 = ( long ) ( V_44 -> V_46 . V_47 >> V_44 -> V_46 . V_48 ) ;
V_42 = F_14 ( V_21 , V_44 -> V_49 ) ;
if ( ! V_37 && F_16 ( & V_21 , & V_39 ) < 0 )
return V_50 ;
V_41 . V_51 = V_52 ;
V_41 . V_53 . V_54 . V_55 = 0 ;
V_41 . V_53 . V_54 . V_56 = V_21 . V_29 ;
V_41 . V_53 . V_54 . V_57 = V_21 . V_33 ;
V_41 . V_53 . V_54 . V_42 = F_17 ( & V_42 ) ;
( void ) F_18 ( & V_41 ) ;
V_39 = V_21 ;
V_39 . V_29 += 11 * 60 ;
return V_50 ;
}
static void F_19 ( void )
{
struct V_58 V_59 ;
struct V_60 * V_61 ;
int V_62 ;
int V_12 = F_20 () ;
if ( F_21 ( V_63 , V_12 ) != NULL )
goto V_64;
F_22 ( L_1 , V_12 ) ;
V_61 = F_23 ( V_65 , V_12 ) ;
V_59 . V_66 = F_24 ( V_61 ) ;
V_59 . V_67 = F_25 ( V_61 ) ;
V_62 = F_26 ( V_68 , V_12 , & V_59 ) ;
F_7 ( V_62 ) ;
F_21 ( V_63 , V_12 ) = V_61 ;
F_27 ( V_12 ) ;
V_64:
F_28 ( V_69 , 0 ) ;
F_29 () ;
}
static void F_30 ( enum V_70 V_70 , const char * V_51 )
{
struct V_71 V_72 = { . V_73 = V_74 } ;
int V_75 ;
V_75 = F_31 ( V_76 , & V_72 ) ;
F_7 ( V_75 ) ;
}
static void F_32 ( void )
{
struct V_71 V_72 = { . V_73 = V_77 } ;
int V_75 ;
V_75 = F_31 ( V_76 , & V_72 ) ;
F_7 ( V_75 ) ;
}
static int F_33 ( struct V_35 * V_78 ,
unsigned long V_79 ,
void * V_80 )
{
switch ( V_79 ) {
case V_81 :
F_19 () ;
break;
case V_82 :
F_34 ( V_69 ) ;
break;
default:
break;
}
return V_50 ;
}
static T_4 F_35 ( int V_83 , void * V_84 )
{
F_36 () ;
return V_85 ;
}
void T_5 F_37 ( void )
{
int V_86 ;
const char * V_24 = NULL ;
const char * V_20 = NULL ;
const char * V_87 = L_2 ;
V_88 = F_38 ( NULL , NULL , L_3 ) ;
if ( ! V_88 ) {
F_39 ( L_4 ) ;
return;
}
V_24 = F_40 ( V_88 , L_5 , & V_86 ) ;
if ( strlen ( V_87 ) + 3 < V_86 &&
! strncmp ( V_87 , V_24 , strlen ( V_87 ) ) )
V_20 = V_24 + strlen ( V_87 ) ;
if ( V_20 == NULL ) {
F_39 ( L_6 ) ;
return;
}
F_22 ( L_7 , V_20 ) ;
V_89 = V_90 ;
F_41 () ;
if ( F_42 ( V_91 ) )
V_92 -> V_93 |= V_94 | V_95 ;
else
V_92 -> V_93 &= ~ ( V_94 | V_95 ) ;
if ( ! V_96 && ! F_43 () )
F_44 ( L_8 , 0 , NULL ) ;
}
static int T_5 F_45 ( void )
{
struct V_97 V_98 ;
struct V_23 * V_99 = NULL ;
struct V_100 V_101 ;
T_6 V_102 ;
if ( ! F_46 () )
return 0 ;
if ( F_47 ( V_88 , V_103 , & V_101 ) ) {
F_48 ( L_9 ) ;
return - V_104 ;
}
V_102 = V_101 . V_105 ;
V_69 = F_49 ( V_88 , 0 ) ;
if ( ! V_69 ) {
F_48 ( L_10 ) ;
return - V_104 ;
}
V_99 = (struct V_23 * ) F_50 ( V_106 ) ;
if ( ! V_99 ) {
F_48 ( L_11 ) ;
return - V_107 ;
}
V_98 . V_8 = V_108 ;
V_98 . V_109 = 0 ;
V_98 . V_110 = V_111 ;
V_98 . V_112 = F_24 ( V_99 ) ;
if ( F_51 ( V_113 , & V_98 ) )
F_52 () ;
V_25 = (struct V_23 * ) V_99 ;
V_65 = F_53 ( sizeof( struct V_60 ) ,
sizeof( struct V_60 ) ) ;
if ( V_65 == NULL )
return - V_107 ;
if ( F_54 ( V_102 ) ) {
F_55 ( V_65 ) ;
return - V_107 ;
}
F_56 () ;
if ( ! F_43 () )
F_57 ( NULL ) ;
F_58 () ;
F_59 () ;
F_60 () ;
if ( F_61 ( V_69 , F_35 ,
L_12 , & V_63 ) ) {
F_48 ( L_13 , V_69 ) ;
return - V_114 ;
}
F_19 () ;
F_62 ( & V_115 ) ;
V_116 . V_117 = F_6 ;
F_63 ( & V_118 ) ;
if ( F_43 () )
F_64 ( & V_119 ) ;
return 0 ;
}
static int T_5 F_65 ( void )
{
if ( ! F_46 () )
return - V_104 ;
V_120 = F_32 ;
V_121 = F_30 ;
if ( ! F_43 () ) {
struct V_18 V_19 ;
F_11 ( & V_19 ) ;
F_66 ( & V_19 ) ;
}
return 0 ;
}
void F_67 ( void ) { }
void F_68 ( int V_122 ) { }
void F_69 ( void ) { }
void F_70 ( void ) { }
void F_71 ( void ) { }
