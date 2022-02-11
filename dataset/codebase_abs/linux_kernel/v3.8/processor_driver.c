static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
T_1 V_4 = 0 ;
if ( ! V_2 )
return - V_5 ;
switch ( V_2 -> V_6 ) {
case 0 :
F_2 ( ( V_7 , L_1 ) ) ;
break;
case 1 :
F_2 ( ( V_7 , L_2 ) ) ;
break;
case 2 :
F_2 ( ( V_7 , L_3 ) ) ;
break;
case 3 :
F_2 ( ( V_7 , L_4 ) ) ;
break;
default:
F_2 ( ( V_7 , L_5 ) ) ;
break;
}
switch ( V_2 -> V_6 ) {
case 0 :
case 1 :
V_8 . V_9 . V_10 = 1 ;
case 2 :
case 3 :
V_2 = F_3 ( V_11 ,
V_12 ,
V_13 , V_13 , NULL ) ;
if ( V_2 ) {
V_8 . V_9 . V_14 = F_4 ( V_2 , 4 ) ;
F_5 ( V_2 ) ;
}
V_2 = F_3 ( V_11 ,
V_15 ,
V_13 , V_13 , NULL ) ;
if ( V_2 ) {
F_6 ( V_2 , 0x76 , & V_3 ) ;
F_6 ( V_2 , 0x77 , & V_4 ) ;
if ( ( V_3 & 0x80 ) || ( V_4 & 0x80 ) )
V_8 . V_9 . V_16 = 1 ;
F_5 ( V_2 ) ;
}
break;
}
if ( V_8 . V_9 . V_14 )
F_2 ( ( V_7 ,
L_6 ) ) ;
if ( V_8 . V_9 . V_16 )
F_2 ( ( V_7 ,
L_7 ) ) ;
return 0 ;
}
static int F_7 ( struct V_17 * V_18 )
{
int V_19 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_18 )
return - V_5 ;
V_2 = F_3 ( V_11 ,
V_20 , V_13 ,
V_13 , NULL ) ;
if ( V_2 ) {
V_19 = F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
}
return V_19 ;
}
static int F_8 ( struct V_21 * V_22 )
{
T_2 V_23 = 0 ;
union V_24 V_25 = { 0 } ;
struct V_26 V_27 = { sizeof( union V_24 ) , & V_25 } ;
struct V_17 * V_18 ;
int V_28 , V_29 = 0 ;
static int V_30 ;
V_18 = F_9 ( V_22 ) ;
if ( ! V_18 )
return - V_5 ;
if ( F_10 () > 1 )
V_8 . V_31 = TRUE ;
F_7 ( V_18 ) ;
if ( V_32 . V_33 && V_32 . V_34 ) {
V_18 -> V_35 . V_36 = 1 ;
F_2 ( ( V_7 ,
L_8 ) ) ;
} else
F_2 ( ( V_7 ,
L_9 ) ) ;
if ( ! strcmp ( F_11 ( V_22 ) , V_37 ) ) {
V_23 = F_12 ( V_18 -> V_38 , NULL , NULL , & V_27 ) ;
if ( F_13 ( V_23 ) ) {
F_14 ( & V_22 -> V_2 ,
L_10 ,
V_23 ) ;
return - V_39 ;
}
V_18 -> V_40 = V_25 . V_41 . V_42 ;
} else {
unsigned long long V_43 ;
V_23 = F_15 ( V_18 -> V_38 , V_44 ,
NULL , & V_43 ) ;
if ( F_13 ( V_23 ) ) {
F_14 ( & V_22 -> V_2 ,
L_11 ,
V_23 ) ;
return - V_39 ;
}
V_29 = 1 ;
V_18 -> V_40 = V_43 ;
}
V_28 = F_16 ( V_18 -> V_38 , V_29 , V_18 -> V_40 ) ;
if ( ! V_30 && ( V_28 == - 1 ) &&
( F_10 () == 1 ) ) {
V_28 = 0 ;
}
V_30 = 1 ;
V_18 -> V_45 = V_28 ;
if ( V_18 -> V_45 == - 1 ) {
if ( F_13 ( F_17 ( V_18 ) ) )
return - V_39 ;
}
sprintf ( F_18 ( V_22 ) , L_12 , V_18 -> V_45 ) ;
F_2 ( ( V_7 , L_13 , V_18 -> V_45 ,
V_18 -> V_40 ) ) ;
if ( ! V_25 . V_41 . V_46 )
F_2 ( ( V_7 , L_14 ) ) ;
else if ( V_25 . V_41 . V_47 != 6 )
F_14 ( & V_22 -> V_2 , L_15 ,
V_25 . V_41 . V_47 ) ;
else {
V_18 -> V_48 . V_49 = V_25 . V_41 . V_46 ;
V_18 -> V_48 . V_50 = V_32 . V_50 ;
V_18 -> V_48 . V_51 = V_32 . V_51 ;
V_18 -> V_52 = V_25 . V_41 . V_46 ;
F_19 ( V_18 -> V_48 . V_49 , 6 , L_16 ) ;
}
V_23 = F_12 ( V_18 -> V_38 , L_17 , NULL , & V_27 ) ;
if ( F_20 ( V_23 ) )
F_21 ( V_18 -> V_45 , V_25 . integer . V_43 ) ;
return 0 ;
}
static void F_22 ( struct V_21 * V_22 , T_3 V_53 )
{
struct V_17 * V_18 = F_9 ( V_22 ) ;
int V_54 ;
if ( ! V_18 )
return;
switch ( V_53 ) {
case V_55 :
V_54 = V_18 -> V_56 ;
F_23 ( V_18 , 1 ) ;
if ( V_54 == V_18 -> V_56 )
break;
F_24 ( V_22 , V_53 ,
V_18 -> V_56 ) ;
F_25 ( V_22 -> V_57 . V_58 ,
F_26 ( & V_22 -> V_2 ) , V_53 ,
V_18 -> V_56 ) ;
break;
case V_59 :
F_27 ( V_18 ) ;
F_24 ( V_22 , V_53 , 0 ) ;
F_25 ( V_22 -> V_57 . V_58 ,
F_26 ( & V_22 -> V_2 ) , V_53 , 0 ) ;
break;
case V_60 :
F_28 ( V_18 ) ;
F_24 ( V_22 , V_53 , 0 ) ;
F_25 ( V_22 -> V_57 . V_58 ,
F_26 ( & V_22 -> V_2 ) , V_53 , 0 ) ;
break;
default:
F_2 ( ( V_7 ,
L_18 , V_53 ) ) ;
break;
}
return;
}
static int F_29 ( struct V_61 * V_62 ,
unsigned long V_63 , void * V_64 )
{
unsigned int V_65 = ( unsigned long ) V_64 ;
struct V_17 * V_18 = F_30 ( V_66 , V_65 ) ;
if ( V_63 == V_67 && V_18 ) {
if ( V_18 -> V_35 . V_68 ) {
F_31 ( L_19 ,
V_18 -> V_45 ) ;
F_32 ( F_33 ( V_18 ) , L_20
L_21 , V_18 -> V_45 ) ;
V_18 -> V_35 . V_68 = 0 ;
} else {
F_23 ( V_18 , 0 ) ;
F_34 ( V_18 ) ;
F_35 ( V_18 , V_63 ) ;
F_28 ( V_18 ) ;
}
}
if ( V_63 == V_69 && V_18 ) {
F_35 ( V_18 , V_63 ) ;
}
return V_70 ;
}
static T_4 int F_33 ( struct V_17 * V_18 )
{
struct V_21 * V_22 = F_30 ( V_71 , V_18 -> V_45 ) ;
int V_19 = 0 ;
#ifdef F_36
F_23 ( V_18 , 0 ) ;
F_37 ( V_18 ) ;
#endif
F_38 ( V_18 ) ;
F_39 ( V_18 ) ;
if ( ! F_40 () || F_40 () == & V_72 )
F_41 ( V_18 ) ;
V_18 -> V_73 = F_42 ( L_22 , V_22 ,
& V_74 ) ;
if ( F_43 ( V_18 -> V_73 ) ) {
V_19 = F_44 ( V_18 -> V_73 ) ;
goto V_75;
}
F_45 ( & V_22 -> V_2 , L_23 ,
V_18 -> V_73 -> V_45 ) ;
V_19 = F_46 ( & V_22 -> V_2 . V_76 ,
& V_18 -> V_73 -> V_22 . V_76 ,
L_24 ) ;
if ( V_19 ) {
F_14 ( & V_22 -> V_2 ,
L_25 ) ;
goto V_77;
}
V_19 = F_46 ( & V_18 -> V_73 -> V_22 . V_76 ,
& V_22 -> V_2 . V_76 ,
L_26 ) ;
if ( V_19 ) {
F_14 ( & V_18 -> V_73 -> V_22 ,
L_27 ) ;
goto V_78;
}
return 0 ;
V_78:
F_47 ( & V_22 -> V_2 . V_76 , L_24 ) ;
V_77:
F_48 ( V_18 -> V_73 ) ;
V_75:
F_49 ( V_18 ) ;
return V_19 ;
}
static int T_5 F_50 ( struct V_21 * V_22 )
{
struct V_17 * V_18 = NULL ;
int V_19 = 0 ;
struct V_22 * V_2 ;
V_18 = F_51 ( sizeof( struct V_17 ) , V_79 ) ;
if ( ! V_18 )
return - V_80 ;
if ( ! F_52 ( & V_18 -> V_48 . V_81 , V_79 ) ) {
V_19 = - V_80 ;
goto V_82;
}
V_18 -> V_38 = V_22 -> V_38 ;
strcpy ( F_53 ( V_22 ) , V_83 ) ;
strcpy ( F_54 ( V_22 ) , V_84 ) ;
V_22 -> V_85 = V_18 ;
V_19 = F_8 ( V_22 ) ;
if ( V_19 ) {
return 0 ;
}
#ifdef F_55
if ( V_18 -> V_45 >= V_86 && V_18 -> V_45 != 0 )
return 0 ;
#endif
F_56 ( ( V_18 -> V_45 >= V_87 ) || ( V_18 -> V_45 < 0 ) ) ;
if ( F_30 ( V_71 , V_18 -> V_45 ) != NULL &&
F_30 ( V_71 , V_18 -> V_45 ) != V_22 ) {
F_57 ( & V_22 -> V_2 ,
L_28 ,
V_18 -> V_45 ) ;
V_19 = - V_39 ;
goto V_88;
}
F_30 ( V_71 , V_18 -> V_45 ) = V_22 ;
F_30 ( V_66 , V_18 -> V_45 ) = V_18 ;
V_2 = F_58 ( V_18 -> V_45 ) ;
if ( F_46 ( & V_22 -> V_2 . V_76 , & V_2 -> V_76 , L_29 ) ) {
V_19 = - V_89 ;
goto V_90;
}
if ( V_18 -> V_35 . V_68 )
return 0 ;
V_19 = F_33 ( V_18 ) ;
if ( V_19 )
goto V_91;
return 0 ;
V_91:
F_47 ( & V_22 -> V_2 . V_76 , L_29 ) ;
V_90:
F_30 ( V_66 , V_18 -> V_45 ) = NULL ;
V_88:
F_59 ( V_18 -> V_48 . V_81 ) ;
V_82:
F_60 ( V_18 ) ;
return V_19 ;
}
static int F_61 ( struct V_21 * V_22 , int type )
{
struct V_17 * V_18 = NULL ;
if ( ! V_22 || ! F_9 ( V_22 ) )
return - V_5 ;
V_18 = F_9 ( V_22 ) ;
if ( V_18 -> V_45 >= V_87 )
goto free;
if ( type == V_92 ) {
if ( F_62 ( V_18 ) )
return - V_5 ;
}
F_49 ( V_18 ) ;
F_47 ( & V_22 -> V_2 . V_76 , L_29 ) ;
if ( V_18 -> V_73 ) {
F_47 ( & V_22 -> V_2 . V_76 , L_24 ) ;
F_47 ( & V_18 -> V_73 -> V_22 . V_76 , L_26 ) ;
F_48 ( V_18 -> V_73 ) ;
V_18 -> V_73 = NULL ;
}
F_30 ( V_66 , V_18 -> V_45 ) = NULL ;
F_30 ( V_71 , V_18 -> V_45 ) = NULL ;
free:
F_59 ( V_18 -> V_48 . V_81 ) ;
F_60 ( V_18 ) ;
return 0 ;
}
static int F_63 ( T_6 V_38 )
{
T_2 V_23 ;
unsigned long long V_93 = 0 ;
V_23 = F_15 ( V_38 , L_30 , NULL , & V_93 ) ;
if ( F_20 ( V_23 ) && ( V_93 & V_94 ) )
return 1 ;
if ( V_23 == V_95 )
F_2 ( ( V_7 ,
L_31 ) ) ;
else
F_64 ( ( V_96 , V_23 ,
L_32 ) ) ;
return 0 ;
}
static
int F_65 ( T_6 V_38 , struct V_21 * * V_22 )
{
T_6 V_97 ;
struct V_21 * V_98 ;
if ( F_66 ( V_38 , & V_97 ) ) {
return - V_39 ;
}
if ( F_67 ( V_97 , & V_98 ) ) {
return - V_39 ;
}
if ( F_68 ( V_22 , V_98 , V_38 , V_99 ) ) {
return - V_39 ;
}
return 0 ;
}
static void F_69 ( T_6 V_38 ,
T_3 V_53 , void * V_100 )
{
struct V_21 * V_22 = NULL ;
struct V_101 * V_102 = NULL ;
T_3 V_103 = V_104 ;
int V_19 ;
switch ( V_53 ) {
case V_105 :
case V_106 :
F_2 ( ( V_7 ,
L_33 ,
( V_53 == V_105 ) ?
L_34 : L_35 ) ) ;
if ( ! F_63 ( V_38 ) )
break;
if ( ! F_67 ( V_38 , & V_22 ) )
break;
V_19 = F_65 ( V_38 , & V_22 ) ;
if ( V_19 ) {
F_70 ( V_38 , L_36 ) ;
break;
}
V_103 = V_107 ;
break;
case V_108 :
F_2 ( ( V_7 ,
L_37 ) ) ;
if ( F_67 ( V_38 , & V_22 ) ) {
F_70 ( V_38 ,
L_38 ) ;
break;
}
if ( ! F_9 ( V_22 ) ) {
F_70 ( V_38 ,
L_39 ) ;
break;
}
V_102 = F_71 ( sizeof( * V_102 ) , V_79 ) ;
if ( ! V_102 ) {
F_70 ( V_38 , L_40 ) ;
break;
}
V_102 -> V_38 = V_38 ;
V_102 -> V_53 = V_108 ;
F_72 ( V_109 ,
( void * ) V_102 ) ;
return;
default:
F_2 ( ( V_7 ,
L_18 , V_53 ) ) ;
return;
}
( void ) F_73 ( V_38 , V_53 , V_103 , NULL ) ;
return;
}
static T_2 F_74 ( T_6 V_38 )
{
struct V_110 * V_111 ;
char * V_112 ;
T_2 V_23 ;
V_23 = F_75 ( V_38 , & V_111 ) ;
if ( F_13 ( V_23 ) )
return V_23 ;
if ( V_111 -> type == V_113 ) {
F_60 ( V_111 ) ;
return V_114 ;
}
if ( ! ( V_111 -> V_115 & V_116 ) ) {
F_60 ( V_111 ) ;
return V_117 ;
}
V_112 = V_111 -> V_118 . string ;
if ( ( V_112 == NULL ) || strcmp ( V_112 , V_119 ) ) {
F_60 ( V_111 ) ;
return V_117 ;
}
F_60 ( V_111 ) ;
return V_114 ;
}
static T_2
F_76 ( T_6 V_38 ,
T_3 V_120 , void * V_121 , void * * V_122 )
{
T_2 V_23 ;
int * V_63 = V_121 ;
V_23 = F_74 ( V_38 ) ;
if ( F_13 ( V_23 ) )
return V_114 ;
switch ( * V_63 ) {
case V_123 :
F_77 ( V_38 ,
V_124 ,
F_69 ,
NULL ) ;
break;
case V_125 :
F_78 ( V_38 ,
V_124 ,
F_69 ) ;
break;
default:
break;
}
return V_126 ;
}
static T_2 F_17 ( struct V_17 * V_18 )
{
T_6 V_38 = V_18 -> V_38 ;
if ( ! F_63 ( V_38 ) ) {
return V_117 ;
}
if ( F_79 ( V_38 , & V_18 -> V_45 ) )
return V_117 ;
if ( F_80 ( V_18 -> V_45 ) ) {
F_81 ( V_18 -> V_45 ) ;
return V_117 ;
}
F_31 ( L_41 , V_18 -> V_45 ) ;
V_18 -> V_35 . V_68 = 1 ;
return V_114 ;
}
static int F_62 ( struct V_17 * V_18 )
{
if ( F_82 ( V_18 -> V_45 ) )
F_83 ( V_18 -> V_45 ) ;
F_84 () ;
if ( F_85 ( F_82 ( V_18 -> V_45 ) ) ) {
F_86 () ;
F_87 ( L_42
L_43 , V_18 -> V_45 ) ;
return - V_127 ;
}
F_88 ( V_18 -> V_45 ) ;
F_81 ( V_18 -> V_45 ) ;
F_86 () ;
return ( 0 ) ;
}
static T_2 F_17 ( struct V_17 * V_18 )
{
return V_117 ;
}
static int F_62 ( struct V_17 * V_18 )
{
return ( - V_5 ) ;
}
static
void F_89 ( void )
{
#ifdef F_90
int V_63 = V_123 ;
F_91 ( V_128 ,
V_129 ,
V_130 ,
F_76 , NULL , & V_63 , NULL ) ;
#endif
F_92 ( & V_131 ) ;
}
static
void F_93 ( void )
{
#ifdef F_90
int V_63 = V_125 ;
F_91 ( V_128 ,
V_129 ,
V_130 ,
F_76 , NULL , & V_63 , NULL ) ;
#endif
F_94 ( & V_131 ) ;
}
static int T_7 F_95 ( void )
{
int V_19 = 0 ;
if ( V_132 )
return 0 ;
V_19 = F_96 ( & V_133 ) ;
if ( V_19 < 0 )
return V_19 ;
F_89 () ;
F_97 () ;
F_98 () ;
F_99 () ;
return 0 ;
}
static void T_8 F_100 ( void )
{
if ( V_132 )
return;
F_101 () ;
F_102 () ;
F_93 () ;
F_103 ( & V_133 ) ;
return;
}
