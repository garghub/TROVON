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
F_56 ( V_18 -> V_45 >= V_87 ) ;
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
static int F_61 ( struct V_21 * V_22 )
{
struct V_17 * V_18 = NULL ;
if ( ! V_22 || ! F_9 ( V_22 ) )
return - V_5 ;
V_18 = F_9 ( V_22 ) ;
if ( V_18 -> V_45 >= V_87 )
goto free;
if ( V_22 -> V_92 == V_93 ) {
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
F_63 ( F_64 ( V_18 -> V_45 ) ) ;
free:
F_59 ( V_18 -> V_48 . V_81 ) ;
F_60 ( V_18 ) ;
return 0 ;
}
static int F_65 ( T_6 V_38 )
{
T_2 V_23 ;
unsigned long long V_94 = 0 ;
V_23 = F_15 ( V_38 , L_30 , NULL , & V_94 ) ;
if ( F_20 ( V_23 ) && ( V_94 & V_95 ) )
return 1 ;
if ( V_23 == V_96 )
F_2 ( ( V_7 ,
L_31 ) ) ;
else
F_66 ( ( V_97 , V_23 ,
L_32 ) ) ;
return 0 ;
}
static void F_67 ( T_6 V_38 ,
T_3 V_53 , void * V_98 )
{
struct V_21 * V_22 = NULL ;
struct V_99 * V_100 = NULL ;
T_3 V_101 = V_102 ;
T_2 V_23 ;
int V_19 ;
F_68 () ;
switch ( V_53 ) {
case V_103 :
case V_104 :
F_2 ( ( V_7 ,
L_33 ,
( V_53 == V_103 ) ?
L_34 : L_35 ) ) ;
if ( ! F_65 ( V_38 ) )
break;
if ( ! F_69 ( V_38 , & V_22 ) )
break;
V_19 = F_70 ( V_38 ) ;
if ( V_19 ) {
F_71 ( V_38 , L_36 ) ;
break;
}
V_19 = F_69 ( V_38 , & V_22 ) ;
if ( V_19 ) {
F_71 ( V_38 , L_37 ) ;
break;
}
V_101 = V_105 ;
break;
case V_106 :
F_2 ( ( V_7 ,
L_38 ) ) ;
if ( F_69 ( V_38 , & V_22 ) ) {
F_71 ( V_38 ,
L_39 ) ;
break;
}
if ( ! F_9 ( V_22 ) ) {
F_71 ( V_38 ,
L_40 ) ;
break;
}
V_100 = F_72 ( sizeof( * V_100 ) , V_79 ) ;
if ( ! V_100 ) {
F_71 ( V_38 , L_41 ) ;
break;
}
F_73 ( & V_22 -> V_2 ) ;
V_100 -> V_22 = V_22 ;
V_100 -> V_53 = V_106 ;
V_23 = F_74 ( V_107 ,
V_100 ) ;
if ( F_13 ( V_23 ) ) {
F_75 ( & V_22 -> V_2 ) ;
F_60 ( V_100 ) ;
break;
}
goto V_108;
default:
F_2 ( ( V_7 ,
L_18 , V_53 ) ) ;
goto V_108;
}
( void ) F_76 ( V_38 , V_53 , V_101 , NULL ) ;
V_108:
F_77 () ;
}
static T_2 F_78 ( T_6 V_38 )
{
struct V_109 * V_110 ;
char * V_111 ;
T_2 V_23 ;
V_23 = F_79 ( V_38 , & V_110 ) ;
if ( F_13 ( V_23 ) )
return V_23 ;
if ( V_110 -> type == V_112 ) {
F_60 ( V_110 ) ;
return V_113 ;
}
if ( ! ( V_110 -> V_114 & V_115 ) ) {
F_60 ( V_110 ) ;
return V_116 ;
}
V_111 = V_110 -> V_117 . string ;
if ( ( V_111 == NULL ) || strcmp ( V_111 , V_118 ) ) {
F_60 ( V_110 ) ;
return V_116 ;
}
F_60 ( V_110 ) ;
return V_113 ;
}
static T_2
F_80 ( T_6 V_38 ,
T_3 V_119 , void * V_120 , void * * V_121 )
{
T_2 V_23 ;
int * V_63 = V_120 ;
V_23 = F_78 ( V_38 ) ;
if ( F_13 ( V_23 ) )
return V_113 ;
switch ( * V_63 ) {
case V_122 :
F_81 ( V_38 ,
V_123 ,
F_67 ,
NULL ) ;
break;
case V_124 :
F_82 ( V_38 ,
V_123 ,
F_67 ) ;
break;
default:
break;
}
return V_125 ;
}
static T_2 F_17 ( struct V_17 * V_18 )
{
T_6 V_38 = V_18 -> V_38 ;
if ( ! F_65 ( V_38 ) ) {
return V_116 ;
}
if ( F_83 ( V_38 , & V_18 -> V_45 ) )
return V_116 ;
if ( F_84 ( V_18 -> V_45 ) ) {
F_85 ( V_18 -> V_45 ) ;
return V_116 ;
}
F_31 ( L_42 , V_18 -> V_45 ) ;
V_18 -> V_35 . V_68 = 1 ;
return V_113 ;
}
static int F_62 ( struct V_17 * V_18 )
{
if ( F_86 ( V_18 -> V_45 ) )
F_87 ( V_18 -> V_45 ) ;
F_88 () ;
if ( F_89 ( F_86 ( V_18 -> V_45 ) ) ) {
F_90 () ;
F_91 ( L_43
L_44 , V_18 -> V_45 ) ;
return - V_126 ;
}
F_92 ( V_18 -> V_45 ) ;
F_85 ( V_18 -> V_45 ) ;
F_90 () ;
return ( 0 ) ;
}
static T_2 F_17 ( struct V_17 * V_18 )
{
return V_116 ;
}
static int F_62 ( struct V_17 * V_18 )
{
return ( - V_5 ) ;
}
static
void F_93 ( void )
{
#ifdef F_94
int V_63 = V_122 ;
F_95 ( V_127 ,
V_128 ,
V_129 ,
F_80 , NULL , & V_63 , NULL ) ;
#endif
F_96 ( & V_130 ) ;
}
static
void F_97 ( void )
{
#ifdef F_94
int V_63 = V_124 ;
F_95 ( V_127 ,
V_128 ,
V_129 ,
F_80 , NULL , & V_63 , NULL ) ;
#endif
F_98 ( & V_130 ) ;
}
static int T_7 F_99 ( void )
{
int V_19 = 0 ;
if ( V_131 )
return 0 ;
V_19 = F_100 ( & V_132 ) ;
if ( V_19 < 0 )
return V_19 ;
F_101 () ;
F_93 () ;
F_102 () ;
F_103 () ;
F_104 () ;
return 0 ;
}
static void T_8 F_105 ( void )
{
if ( V_131 )
return;
F_106 () ;
F_107 () ;
F_97 () ;
F_108 () ;
F_109 ( & V_132 ) ;
return;
}
