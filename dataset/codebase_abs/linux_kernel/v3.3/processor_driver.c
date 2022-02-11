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
struct V_69 * V_70 =
F_31 () ;
F_14 ( V_71 L_19
L_20 , V_18 -> V_45 ) ;
F_32 ( F_33 ( V_18 ) , L_21
L_22 , V_18 -> V_45 ) ;
V_18 -> V_35 . V_68 = 0 ;
if ( V_70 && ! strcmp ( V_70 -> V_72 ,
L_23 ) ) {
F_34 ( V_18 -> V_45 ) ;
}
} else {
F_23 ( V_18 , 0 ) ;
F_27 ( V_18 ) ;
F_35 ( V_18 , V_63 ) ;
F_28 ( V_18 ) ;
}
}
if ( V_63 == V_73 && V_18 ) {
F_35 ( V_18 , V_63 ) ;
}
return V_74 ;
}
static T_4 int F_33 ( struct V_17 * V_18 )
{
struct V_21 * V_22 = F_30 ( V_75 , V_18 -> V_45 ) ;
int V_19 = 0 ;
#ifdef F_36
F_23 ( V_18 , 0 ) ;
#endif
F_37 ( V_18 ) ;
F_38 ( V_18 ) ;
if ( ! F_31 () || F_31 () == & V_76 )
F_39 ( V_18 , V_22 ) ;
V_18 -> V_77 = F_40 ( L_24 , V_22 ,
& V_78 ) ;
if ( F_41 ( V_18 -> V_77 ) ) {
V_19 = F_42 ( V_18 -> V_77 ) ;
goto V_79;
}
F_43 ( & V_22 -> V_2 , L_25 ,
V_18 -> V_77 -> V_45 ) ;
V_19 = F_44 ( & V_22 -> V_2 . V_80 ,
& V_18 -> V_77 -> V_22 . V_80 ,
L_26 ) ;
if ( V_19 ) {
F_14 (KERN_ERR PREFIX L_27 ) ;
goto V_81;
}
V_19 = F_44 ( & V_18 -> V_77 -> V_22 . V_80 ,
& V_22 -> V_2 . V_80 ,
L_28 ) ;
if ( V_19 ) {
F_14 (KERN_ERR PREFIX L_27 ) ;
goto V_82;
}
return 0 ;
V_82:
F_45 ( & V_22 -> V_2 . V_80 , L_26 ) ;
V_81:
F_46 ( V_18 -> V_77 ) ;
V_79:
F_47 ( V_18 , V_22 ) ;
return V_19 ;
}
static int T_5 F_48 ( struct V_21 * V_22 )
{
struct V_17 * V_18 = NULL ;
int V_19 = 0 ;
struct V_22 * V_2 ;
V_18 = F_49 ( sizeof( struct V_17 ) , V_83 ) ;
if ( ! V_18 )
return - V_84 ;
if ( ! F_50 ( & V_18 -> V_48 . V_85 , V_83 ) ) {
F_51 ( V_18 ) ;
return - V_84 ;
}
V_18 -> V_38 = V_22 -> V_38 ;
strcpy ( F_52 ( V_22 ) , V_86 ) ;
strcpy ( F_53 ( V_22 ) , V_87 ) ;
V_22 -> V_88 = V_18 ;
V_19 = F_8 ( V_22 ) ;
if ( V_19 ) {
return 0 ;
}
#ifdef F_54
if ( V_18 -> V_45 >= V_89 && V_18 -> V_45 != 0 )
return 0 ;
#endif
F_55 ( ( V_18 -> V_45 >= V_90 ) || ( V_18 -> V_45 < 0 ) ) ;
if ( F_30 ( V_75 , V_18 -> V_45 ) != NULL &&
F_30 ( V_75 , V_18 -> V_45 ) != V_22 ) {
F_14 ( V_91 L_29
L_30 ) ;
V_19 = - V_39 ;
goto V_92;
}
F_30 ( V_75 , V_18 -> V_45 ) = V_22 ;
F_30 ( V_66 , V_18 -> V_45 ) = V_18 ;
V_2 = F_56 ( V_18 -> V_45 ) ;
if ( F_44 ( & V_22 -> V_2 . V_80 , & V_2 -> V_80 , L_31 ) ) {
V_19 = - V_93 ;
goto V_92;
}
if ( V_18 -> V_35 . V_68 )
return 0 ;
V_19 = F_33 ( V_18 ) ;
if ( V_19 )
goto V_94;
return 0 ;
V_94:
F_45 ( & V_22 -> V_2 . V_80 , L_31 ) ;
V_92:
F_57 ( V_18 -> V_48 . V_85 ) ;
return V_19 ;
}
static int F_58 ( struct V_21 * V_22 , int type )
{
struct V_17 * V_18 = NULL ;
if ( ! V_22 || ! F_9 ( V_22 ) )
return - V_5 ;
V_18 = F_9 ( V_22 ) ;
if ( V_18 -> V_45 >= V_90 )
goto free;
if ( type == V_95 ) {
if ( F_59 ( V_18 ) )
return - V_5 ;
}
F_47 ( V_18 , V_22 ) ;
F_45 ( & V_22 -> V_2 . V_80 , L_31 ) ;
if ( V_18 -> V_77 ) {
F_45 ( & V_22 -> V_2 . V_80 , L_26 ) ;
F_45 ( & V_18 -> V_77 -> V_22 . V_80 , L_28 ) ;
F_46 ( V_18 -> V_77 ) ;
V_18 -> V_77 = NULL ;
}
F_30 ( V_66 , V_18 -> V_45 ) = NULL ;
F_30 ( V_75 , V_18 -> V_45 ) = NULL ;
free:
F_57 ( V_18 -> V_48 . V_85 ) ;
F_51 ( V_18 ) ;
return 0 ;
}
static int F_60 ( T_6 V_38 )
{
T_2 V_23 ;
unsigned long long V_96 = 0 ;
V_23 = F_15 ( V_38 , L_32 , NULL , & V_96 ) ;
if ( F_20 ( V_23 ) && ( V_96 & V_97 ) )
return 1 ;
if ( V_23 == V_98 )
F_2 ( ( V_7 ,
L_33 ) ) ;
else
F_61 ( ( V_99 , V_23 ,
L_34 ) ) ;
return 0 ;
}
static
int F_62 ( T_6 V_38 , struct V_21 * * V_22 )
{
T_6 V_100 ;
struct V_21 * V_101 ;
if ( F_63 ( V_38 , & V_100 ) ) {
return - V_39 ;
}
if ( F_64 ( V_100 , & V_101 ) ) {
return - V_39 ;
}
if ( F_65 ( V_22 , V_101 , V_38 , V_102 ) ) {
return - V_39 ;
}
return 0 ;
}
static void F_66 ( T_6 V_38 ,
T_3 V_53 , void * V_103 )
{
struct V_17 * V_18 ;
struct V_21 * V_22 = NULL ;
int V_19 ;
switch ( V_53 ) {
case V_104 :
case V_105 :
F_2 ( ( V_7 ,
L_35 ,
( V_53 == V_104 ) ?
L_36 : L_37 ) ) ;
if ( ! F_60 ( V_38 ) )
break;
if ( F_64 ( V_38 , & V_22 ) ) {
V_19 = F_62 ( V_38 , & V_22 ) ;
if ( V_19 )
F_14 (KERN_ERR PREFIX
L_38 ) ;
break;
}
break;
case V_106 :
F_2 ( ( V_7 ,
L_39 ) ) ;
if ( F_64 ( V_38 , & V_22 ) ) {
F_14 (KERN_ERR PREFIX
L_40 ) ;
break;
}
V_18 = F_9 ( V_22 ) ;
if ( ! V_18 ) {
F_14 (KERN_ERR PREFIX
L_41 ) ;
return;
}
break;
default:
F_2 ( ( V_7 ,
L_18 , V_53 ) ) ;
break;
}
return;
}
static T_2
F_67 ( T_6 V_38 ,
T_3 V_107 , void * V_108 , void * * V_109 )
{
T_2 V_23 ;
int * V_63 = V_108 ;
T_7 type = 0 ;
V_23 = F_68 ( V_38 , & type ) ;
if ( F_13 ( V_23 ) )
return ( V_110 ) ;
if ( type != V_111 )
return ( V_110 ) ;
switch ( * V_63 ) {
case V_112 :
F_69 ( V_38 ,
V_113 ,
F_66 ,
NULL ) ;
break;
case V_114 :
F_70 ( V_38 ,
V_113 ,
F_66 ) ;
break;
default:
break;
}
return ( V_110 ) ;
}
static T_2 F_17 ( struct V_17 * V_18 )
{
T_6 V_38 = V_18 -> V_38 ;
if ( ! F_60 ( V_38 ) ) {
return V_115 ;
}
if ( F_71 ( V_38 , & V_18 -> V_45 ) )
return V_115 ;
if ( F_72 ( V_18 -> V_45 ) ) {
F_73 ( V_18 -> V_45 ) ;
return V_115 ;
}
F_14 ( V_71 L_42 , V_18 -> V_45 ) ;
V_18 -> V_35 . V_68 = 1 ;
return V_110 ;
}
static int F_59 ( struct V_17 * V_18 )
{
if ( F_74 ( V_18 -> V_45 ) )
F_75 ( V_18 -> V_45 ) ;
F_76 ( V_18 -> V_45 ) ;
F_73 ( V_18 -> V_45 ) ;
return ( 0 ) ;
}
static T_2 F_17 ( struct V_17 * V_18 )
{
return V_115 ;
}
static int F_59 ( struct V_17 * V_18 )
{
return ( - V_5 ) ;
}
static
void F_77 ( void )
{
#ifdef F_78
int V_63 = V_112 ;
F_79 ( V_111 ,
V_116 ,
V_117 ,
F_67 , NULL , & V_63 , NULL ) ;
#endif
F_80 ( & V_118 ) ;
}
static
void F_81 ( void )
{
#ifdef F_78
int V_63 = V_114 ;
F_79 ( V_111 ,
V_116 ,
V_117 ,
F_67 , NULL , & V_63 , NULL ) ;
#endif
F_82 ( & V_118 ) ;
}
static int T_8 F_83 ( void )
{
int V_19 = 0 ;
if ( V_119 )
return 0 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_19 = F_84 ( & V_120 ) ;
if ( V_19 < 0 )
return V_19 ;
F_77 () ;
F_85 () ;
F_86 () ;
F_87 () ;
return 0 ;
}
static void T_9 F_88 ( void )
{
if ( V_119 )
return;
F_89 () ;
F_90 () ;
F_81 () ;
F_91 ( & V_120 ) ;
return;
}
