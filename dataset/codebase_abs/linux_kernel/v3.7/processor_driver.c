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
F_14 (KERN_ERR PREFIX L_10 ) ;
return - V_39 ;
}
V_18 -> V_40 = V_25 . V_41 . V_42 ;
} else {
unsigned long long V_43 ;
V_23 = F_15 ( V_18 -> V_38 , V_44 ,
NULL , & V_43 ) ;
if ( F_13 ( V_23 ) ) {
F_14 (KERN_ERR PREFIX
L_11 , status) ;
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
F_14 (KERN_ERR PREFIX L_15 ,
object.processor.pblk_length) ;
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
F_14 ( V_69 L_19
L_20 , V_18 -> V_45 ) ;
F_31 ( F_32 ( V_18 ) , L_21
L_22 , V_18 -> V_45 ) ;
V_18 -> V_35 . V_68 = 0 ;
} else {
F_23 ( V_18 , 0 ) ;
F_33 ( V_18 ) ;
F_34 ( V_18 , V_63 ) ;
F_28 ( V_18 ) ;
}
}
if ( V_63 == V_70 && V_18 ) {
F_34 ( V_18 , V_63 ) ;
}
return V_71 ;
}
static T_4 int F_32 ( struct V_17 * V_18 )
{
struct V_21 * V_22 = F_30 ( V_72 , V_18 -> V_45 ) ;
int V_19 = 0 ;
#ifdef F_35
F_23 ( V_18 , 0 ) ;
F_36 ( V_18 ) ;
#endif
F_37 ( V_18 ) ;
F_38 ( V_18 ) ;
if ( ! F_39 () || F_39 () == & V_73 )
F_40 ( V_18 ) ;
V_18 -> V_74 = F_41 ( L_23 , V_22 ,
& V_75 ) ;
if ( F_42 ( V_18 -> V_74 ) ) {
V_19 = F_43 ( V_18 -> V_74 ) ;
goto V_76;
}
F_44 ( & V_22 -> V_2 , L_24 ,
V_18 -> V_74 -> V_45 ) ;
V_19 = F_45 ( & V_22 -> V_2 . V_77 ,
& V_18 -> V_74 -> V_22 . V_77 ,
L_25 ) ;
if ( V_19 ) {
F_14 (KERN_ERR PREFIX L_26 ) ;
goto V_78;
}
V_19 = F_45 ( & V_18 -> V_74 -> V_22 . V_77 ,
& V_22 -> V_2 . V_77 ,
L_27 ) ;
if ( V_19 ) {
F_14 (KERN_ERR PREFIX L_26 ) ;
goto V_79;
}
return 0 ;
V_79:
F_46 ( & V_22 -> V_2 . V_77 , L_25 ) ;
V_78:
F_47 ( V_18 -> V_74 ) ;
V_76:
F_48 ( V_18 ) ;
return V_19 ;
}
static int T_5 F_49 ( struct V_21 * V_22 )
{
struct V_17 * V_18 = NULL ;
int V_19 = 0 ;
struct V_22 * V_2 ;
V_18 = F_50 ( sizeof( struct V_17 ) , V_80 ) ;
if ( ! V_18 )
return - V_81 ;
if ( ! F_51 ( & V_18 -> V_48 . V_82 , V_80 ) ) {
V_19 = - V_81 ;
goto V_83;
}
V_18 -> V_38 = V_22 -> V_38 ;
strcpy ( F_52 ( V_22 ) , V_84 ) ;
strcpy ( F_53 ( V_22 ) , V_85 ) ;
V_22 -> V_86 = V_18 ;
V_19 = F_8 ( V_22 ) ;
if ( V_19 ) {
return 0 ;
}
#ifdef F_54
if ( V_18 -> V_45 >= V_87 && V_18 -> V_45 != 0 )
return 0 ;
#endif
F_55 ( ( V_18 -> V_45 >= V_88 ) || ( V_18 -> V_45 < 0 ) ) ;
if ( F_30 ( V_72 , V_18 -> V_45 ) != NULL &&
F_30 ( V_72 , V_18 -> V_45 ) != V_22 ) {
F_14 ( V_89 L_28
L_29 ) ;
V_19 = - V_39 ;
goto V_90;
}
F_30 ( V_72 , V_18 -> V_45 ) = V_22 ;
F_30 ( V_66 , V_18 -> V_45 ) = V_18 ;
V_2 = F_56 ( V_18 -> V_45 ) ;
if ( F_45 ( & V_22 -> V_2 . V_77 , & V_2 -> V_77 , L_30 ) ) {
V_19 = - V_91 ;
goto V_92;
}
if ( V_18 -> V_35 . V_68 )
return 0 ;
V_19 = F_32 ( V_18 ) ;
if ( V_19 )
goto V_93;
return 0 ;
V_93:
F_46 ( & V_22 -> V_2 . V_77 , L_30 ) ;
V_92:
F_30 ( V_66 , V_18 -> V_45 ) = NULL ;
V_90:
F_57 ( V_18 -> V_48 . V_82 ) ;
V_83:
F_58 ( V_18 ) ;
return V_19 ;
}
static int F_59 ( struct V_21 * V_22 , int type )
{
struct V_17 * V_18 = NULL ;
if ( ! V_22 || ! F_9 ( V_22 ) )
return - V_5 ;
V_18 = F_9 ( V_22 ) ;
if ( V_18 -> V_45 >= V_88 )
goto free;
if ( type == V_94 ) {
if ( F_60 ( V_18 ) )
return - V_5 ;
}
F_48 ( V_18 ) ;
F_46 ( & V_22 -> V_2 . V_77 , L_30 ) ;
if ( V_18 -> V_74 ) {
F_46 ( & V_22 -> V_2 . V_77 , L_25 ) ;
F_46 ( & V_18 -> V_74 -> V_22 . V_77 , L_27 ) ;
F_47 ( V_18 -> V_74 ) ;
V_18 -> V_74 = NULL ;
}
F_30 ( V_66 , V_18 -> V_45 ) = NULL ;
F_30 ( V_72 , V_18 -> V_45 ) = NULL ;
free:
F_57 ( V_18 -> V_48 . V_82 ) ;
F_58 ( V_18 ) ;
return 0 ;
}
static int F_61 ( T_6 V_38 )
{
T_2 V_23 ;
unsigned long long V_95 = 0 ;
V_23 = F_15 ( V_38 , L_31 , NULL , & V_95 ) ;
if ( F_20 ( V_23 ) && ( V_95 & V_96 ) )
return 1 ;
if ( V_23 == V_97 )
F_2 ( ( V_7 ,
L_32 ) ) ;
else
F_62 ( ( V_98 , V_23 ,
L_33 ) ) ;
return 0 ;
}
static
int F_63 ( T_6 V_38 , struct V_21 * * V_22 )
{
T_6 V_99 ;
struct V_21 * V_100 ;
if ( F_64 ( V_38 , & V_99 ) ) {
return - V_39 ;
}
if ( F_65 ( V_99 , & V_100 ) ) {
return - V_39 ;
}
if ( F_66 ( V_22 , V_100 , V_38 , V_101 ) ) {
return - V_39 ;
}
return 0 ;
}
static void F_67 ( T_6 V_38 ,
T_3 V_53 , void * V_102 )
{
struct V_17 * V_18 ;
struct V_21 * V_22 = NULL ;
T_3 V_103 = V_104 ;
int V_19 ;
switch ( V_53 ) {
case V_105 :
case V_106 :
F_2 ( ( V_7 ,
L_34 ,
( V_53 == V_105 ) ?
L_35 : L_36 ) ) ;
if ( ! F_61 ( V_38 ) )
break;
if ( ! F_65 ( V_38 , & V_22 ) )
break;
V_19 = F_63 ( V_38 , & V_22 ) ;
if ( V_19 ) {
F_14 (KERN_ERR PREFIX L_37 ) ;
break;
}
V_103 = V_107 ;
break;
case V_108 :
F_2 ( ( V_7 ,
L_38 ) ) ;
if ( F_65 ( V_38 , & V_22 ) ) {
F_14 (KERN_ERR PREFIX
L_39 ) ;
break;
}
V_18 = F_9 ( V_22 ) ;
if ( ! V_18 ) {
F_14 (KERN_ERR PREFIX
L_40 ) ;
break;
}
V_103 = V_109 ;
break;
default:
F_2 ( ( V_7 ,
L_18 , V_53 ) ) ;
return;
}
( void ) F_68 ( V_38 , V_53 , V_103 , NULL ) ;
return;
}
static T_2 F_69 ( T_6 V_38 )
{
struct V_110 * V_111 ;
char * V_112 ;
T_2 V_23 ;
V_23 = F_70 ( V_38 , & V_111 ) ;
if ( F_13 ( V_23 ) )
return V_23 ;
if ( V_111 -> type == V_113 ) {
F_58 ( V_111 ) ;
return V_114 ;
}
if ( ! ( V_111 -> V_115 & V_116 ) ) {
F_58 ( V_111 ) ;
return V_117 ;
}
V_112 = V_111 -> V_118 . string ;
if ( ( V_112 == NULL ) || strcmp ( V_112 , V_119 ) ) {
F_58 ( V_111 ) ;
return V_117 ;
}
F_58 ( V_111 ) ;
return V_114 ;
}
static T_2
F_71 ( T_6 V_38 ,
T_3 V_120 , void * V_121 , void * * V_122 )
{
T_2 V_23 ;
int * V_63 = V_121 ;
V_23 = F_69 ( V_38 ) ;
if ( F_13 ( V_23 ) )
return V_114 ;
switch ( * V_63 ) {
case V_123 :
F_72 ( V_38 ,
V_124 ,
F_67 ,
NULL ) ;
break;
case V_125 :
F_73 ( V_38 ,
V_124 ,
F_67 ) ;
break;
default:
break;
}
return V_126 ;
}
static T_2 F_17 ( struct V_17 * V_18 )
{
T_6 V_38 = V_18 -> V_38 ;
if ( ! F_61 ( V_38 ) ) {
return V_117 ;
}
if ( F_74 ( V_38 , & V_18 -> V_45 ) )
return V_117 ;
if ( F_75 ( V_18 -> V_45 ) ) {
F_76 ( V_18 -> V_45 ) ;
return V_117 ;
}
F_14 ( V_69 L_41 , V_18 -> V_45 ) ;
V_18 -> V_35 . V_68 = 1 ;
return V_114 ;
}
static int F_60 ( struct V_17 * V_18 )
{
if ( F_77 ( V_18 -> V_45 ) )
F_78 ( V_18 -> V_45 ) ;
F_79 ( V_18 -> V_45 ) ;
F_76 ( V_18 -> V_45 ) ;
return ( 0 ) ;
}
static T_2 F_17 ( struct V_17 * V_18 )
{
return V_117 ;
}
static int F_60 ( struct V_17 * V_18 )
{
return ( - V_5 ) ;
}
static
void F_80 ( void )
{
#ifdef F_81
int V_63 = V_123 ;
F_82 ( V_127 ,
V_128 ,
V_129 ,
F_71 , NULL , & V_63 , NULL ) ;
#endif
F_83 ( & V_130 ) ;
}
static
void F_84 ( void )
{
#ifdef F_81
int V_63 = V_125 ;
F_82 ( V_127 ,
V_128 ,
V_129 ,
F_71 , NULL , & V_63 , NULL ) ;
#endif
F_85 ( & V_130 ) ;
}
static int T_7 F_86 ( void )
{
int V_19 = 0 ;
if ( V_131 )
return 0 ;
V_19 = F_87 ( & V_132 ) ;
if ( V_19 < 0 )
return V_19 ;
F_80 () ;
F_88 () ;
F_89 () ;
F_90 () ;
return 0 ;
}
static void T_8 F_91 ( void )
{
if ( V_131 )
return;
F_92 () ;
F_93 () ;
F_84 () ;
F_94 ( & V_132 ) ;
return;
}
