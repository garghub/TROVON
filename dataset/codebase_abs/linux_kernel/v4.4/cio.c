static int T_1 F_1 ( void )
{
V_1 = F_2 ( L_1 , 16 , 1 , 11 * sizeof( long ) ) ;
if ( ! V_1 )
goto V_2;
F_3 ( V_1 , & V_3 ) ;
F_4 ( V_1 , 2 ) ;
V_4 = F_2 ( L_2 , 16 , 1 , 16 ) ;
if ( ! V_4 )
goto V_2;
F_3 ( V_4 , & V_5 ) ;
F_4 ( V_4 , 2 ) ;
V_6 = F_2 ( L_3 , 8 , 1 , 8 * sizeof( long ) ) ;
if ( ! V_6 )
goto V_2;
F_3 ( V_6 , & V_3 ) ;
F_4 ( V_6 , 4 ) ;
return 0 ;
V_2:
if ( V_1 )
F_5 ( V_1 ) ;
if ( V_4 )
F_5 ( V_4 ) ;
if ( V_6 )
F_5 ( V_6 ) ;
return - 1 ;
}
int F_6 ( struct V_7 * V_8 , int V_9 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
V_11 -> V_12 . V_13 = ( V_9 & V_14 ) != 0 ;
V_11 -> V_12 . V_15 = ( V_9 & V_16 ) != 0 ;
V_11 -> V_12 . V_17 = ( V_9 & V_18 ) != 0 ;
return 0 ;
}
static int
F_8 ( struct V_7 * V_8 , T_2 V_19 )
{
char V_20 [ 15 ] ;
if ( V_19 != 0 )
V_8 -> V_19 &= ~ V_19 ;
else
V_8 -> V_19 = 0 ;
F_9 ( 2 , L_4
L_5 , V_8 -> V_21 . V_22 ,
V_8 -> V_21 . V_23 ) ;
if ( F_10 ( V_8 ) )
return - V_24 ;
sprintf ( V_20 , L_6 , F_11 ( & V_8 -> V_25 ) ) ;
F_12 ( 0 , V_20 ) ;
F_13 ( 0 , & V_8 -> V_26 , sizeof ( struct V_26 ) ) ;
return ( V_8 -> V_19 ? - V_27 : - V_24 ) ;
}
int
F_14 ( struct V_7 * V_8 ,
struct V_28 * V_29 ,
T_2 V_19 ,
T_2 V_30 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
union V_31 * V_31 = & V_11 -> V_31 ;
int V_32 ;
F_12 ( 5 , L_7 ) ;
F_12 ( 5 , F_11 ( & V_8 -> V_25 ) ) ;
memset ( V_31 , 0 , sizeof( union V_31 ) ) ;
V_31 -> V_33 . V_34 = ( V_35 ) ( V_36 ) V_8 ;
V_31 -> V_33 . V_37 = 1 ;
V_31 -> V_33 . V_38 = V_11 -> V_12 . V_15 == 0 ;
V_31 -> V_33 . V_39 = V_11 -> V_12 . V_13 ;
V_31 -> V_33 . V_40 = V_11 -> V_12 . V_13 && V_11 -> V_12 . V_17 ;
V_31 -> V_33 . V_19 = ( V_19 != 0 ) ? V_19 : V_8 -> V_19 ;
V_31 -> V_33 . V_41 = 1 ;
V_31 -> V_33 . V_42 = 0 ;
V_31 -> V_33 . V_30 = V_30 >> 4 ;
V_31 -> V_33 . V_29 = ( V_43 ) F_15 ( V_29 ) ;
V_32 = F_16 ( V_8 -> V_21 , V_31 ) ;
F_13 ( 5 , & V_32 , sizeof( V_32 ) ) ;
switch ( V_32 ) {
case 0 :
V_8 -> V_26 . V_44 . V_33 . V_45 |= V_46 ;
return 0 ;
case 1 :
case 2 :
return - V_47 ;
case 3 :
return F_8 ( V_8 , V_19 ) ;
default:
return V_32 ;
}
}
int
F_17 ( struct V_7 * V_8 , struct V_28 * V_29 , T_2 V_19 )
{
return F_14 ( V_8 , V_29 , V_19 , V_48 ) ;
}
int
F_18 ( struct V_7 * V_8 )
{
int V_32 ;
F_12 ( 4 , L_8 ) ;
F_12 ( 4 , F_11 ( & V_8 -> V_25 ) ) ;
V_32 = F_19 ( V_8 -> V_21 ) ;
F_13 ( 4 , & V_32 , sizeof( V_32 ) ) ;
switch ( V_32 ) {
case 0 :
V_8 -> V_26 . V_44 . V_33 . V_45 |= V_49 ;
return 0 ;
case 1 :
return - V_47 ;
case 2 :
return - V_50 ;
default:
return - V_24 ;
}
}
int
F_20 ( struct V_7 * V_8 )
{
int V_32 ;
if ( ! V_8 )
return - V_24 ;
F_12 ( 2 , L_9 ) ;
F_12 ( 2 , F_11 ( & V_8 -> V_25 ) ) ;
V_32 = F_21 ( V_8 -> V_21 ) ;
F_13 ( 2 , & V_32 , sizeof( V_32 ) ) ;
switch ( V_32 ) {
case 0 :
V_8 -> V_26 . V_44 . V_33 . V_45 |= V_51 ;
return 0 ;
case 1 :
case 2 :
return - V_47 ;
default:
return - V_24 ;
}
}
int
F_22 ( struct V_7 * V_8 )
{
int V_32 ;
if ( ! V_8 )
return - V_24 ;
F_12 ( 2 , L_10 ) ;
F_12 ( 2 , F_11 ( & V_8 -> V_25 ) ) ;
V_32 = F_23 ( V_8 -> V_21 ) ;
F_13 ( 2 , & V_32 , sizeof( V_32 ) ) ;
switch ( V_32 ) {
case 0 :
V_8 -> V_26 . V_44 . V_33 . V_45 |= V_52 ;
return 0 ;
default:
return - V_24 ;
}
}
int
F_24 ( struct V_7 * V_8 )
{
int V_32 ;
if ( ! V_8 )
return - V_24 ;
F_12 ( 2 , L_11 ) ;
F_12 ( 2 , F_11 ( & V_8 -> V_25 ) ) ;
V_32 = F_25 ( V_8 -> V_21 ) ;
F_13 ( 2 , & V_32 , sizeof( V_32 ) ) ;
switch ( V_32 ) {
case 0 :
if ( F_10 ( V_8 ) )
return - V_24 ;
return 0 ;
case 1 :
return - V_47 ;
case 2 :
return - V_50 ;
default:
return - V_24 ;
}
}
static void F_26 ( struct V_7 * V_8 , struct V_26 * V_26 )
{
V_26 -> V_53 . V_34 = V_8 -> V_54 . V_34 ;
V_26 -> V_53 . V_55 = V_8 -> V_54 . V_55 ;
V_26 -> V_53 . V_56 = V_8 -> V_54 . V_56 ;
V_26 -> V_53 . V_57 = V_8 -> V_54 . V_57 ;
V_26 -> V_53 . V_58 = V_8 -> V_54 . V_58 ;
V_26 -> V_53 . V_59 = V_8 -> V_54 . V_59 ;
V_26 -> V_53 . V_60 = V_8 -> V_54 . V_60 ;
V_26 -> V_53 . V_61 = V_8 -> V_54 . V_61 ;
if ( V_8 -> V_54 . V_61 )
V_26 -> V_62 = V_8 -> V_54 . V_62 ;
}
static int F_27 ( struct V_7 * V_8 , struct V_26 * V_26 )
{
return ( V_26 -> V_53 . V_34 == V_8 -> V_54 . V_34 ) &&
( V_26 -> V_53 . V_55 == V_8 -> V_54 . V_55 ) &&
( V_26 -> V_53 . V_56 == V_8 -> V_54 . V_56 ) &&
( V_26 -> V_53 . V_57 == V_8 -> V_54 . V_57 ) &&
( V_26 -> V_53 . V_58 == V_8 -> V_54 . V_58 ) &&
( V_26 -> V_53 . V_59 == V_8 -> V_54 . V_59 ) &&
( V_26 -> V_53 . V_60 == V_8 -> V_54 . V_60 ) &&
( V_26 -> V_53 . V_61 == V_8 -> V_54 . V_61 ) &&
( ! V_8 -> V_54 . V_61 || ( V_26 -> V_62 == V_8 -> V_54 . V_62 ) ) ;
}
int F_28 ( struct V_7 * V_8 )
{
int V_32 , V_63 , V_64 = 0 ;
struct V_26 V_26 ;
struct V_65 V_65 ;
if ( F_29 ( V_8 -> V_21 , & V_26 ) || ! F_30 ( & V_26 ) )
return - V_24 ;
for ( V_63 = 0 ; V_63 < 5 ; V_63 ++ ) {
F_26 ( V_8 , & V_26 ) ;
V_32 = F_31 ( V_8 -> V_21 , & V_26 ) ;
if ( V_32 < 0 )
return V_32 ;
switch ( V_32 ) {
case 0 :
if ( F_29 ( V_8 -> V_21 , & V_26 ) ||
! F_30 ( & V_26 ) )
return - V_24 ;
if ( F_27 ( V_8 , & V_26 ) ) {
memcpy ( & V_8 -> V_26 , & V_26 , sizeof( V_26 ) ) ;
return 0 ;
}
V_64 = - V_66 ;
break;
case 1 :
V_64 = - V_47 ;
if ( F_32 ( V_8 -> V_21 , & V_65 ) )
return V_64 ;
break;
case 2 :
F_33 ( 100 ) ;
V_64 = - V_47 ;
break;
case 3 :
return - V_24 ;
}
}
return V_64 ;
}
int F_10 ( struct V_7 * V_8 )
{
struct V_26 V_26 ;
if ( F_29 ( V_8 -> V_21 , & V_26 ) || ! F_30 ( & V_26 ) )
return - V_24 ;
memcpy ( & V_8 -> V_26 , & V_26 , sizeof( V_26 ) ) ;
return 0 ;
}
int F_34 ( struct V_7 * V_8 , V_35 V_34 )
{
int V_64 ;
F_12 ( 2 , L_12 ) ;
F_12 ( 2 , F_11 ( & V_8 -> V_25 ) ) ;
if ( F_35 ( V_8 ) )
return - V_50 ;
if ( F_10 ( V_8 ) )
return - V_24 ;
V_8 -> V_54 . V_57 = 1 ;
V_8 -> V_54 . V_56 = V_8 -> V_56 ;
V_8 -> V_54 . V_34 = V_34 ;
V_64 = F_28 ( V_8 ) ;
if ( V_64 == - V_67 ) {
V_8 -> V_54 . V_60 = 0 ;
V_64 = F_28 ( V_8 ) ;
}
F_13 ( 2 , & V_64 , sizeof( V_64 ) ) ;
return V_64 ;
}
int F_36 ( struct V_7 * V_8 )
{
int V_64 ;
F_12 ( 2 , L_13 ) ;
F_12 ( 2 , F_11 ( & V_8 -> V_25 ) ) ;
if ( F_35 ( V_8 ) )
return 0 ;
if ( F_10 ( V_8 ) )
return - V_24 ;
V_8 -> V_54 . V_57 = 0 ;
V_64 = F_28 ( V_8 ) ;
F_13 ( 2 , & V_64 , sizeof( V_64 ) ) ;
return V_64 ;
}
static int F_37 ( struct V_7 * V_8 )
{
if ( F_38 ( V_8 -> V_21 . V_22 , V_8 -> V_26 . V_53 . V_25 ) ) {
F_9 ( 6 , L_14
L_15 ,
V_8 -> V_26 . V_53 . V_25 , V_8 -> V_21 . V_22 ) ;
return - V_24 ;
}
return 0 ;
}
int F_39 ( struct V_7 * V_8 , struct V_68 V_21 )
{
char V_69 [ 15 ] ;
int V_32 ;
int V_70 ;
sprintf ( V_69 , L_16 , V_21 . V_23 ) ;
F_12 ( 4 , V_69 ) ;
V_32 = F_29 ( V_21 , & V_8 -> V_26 ) ;
if ( V_32 ) {
V_70 = ( V_32 == 3 ) ? - V_71 : V_32 ;
goto V_72;
}
V_8 -> V_73 = V_8 -> V_26 . V_53 . V_73 ;
V_8 -> V_21 = V_21 ;
switch ( V_8 -> V_73 ) {
case V_74 :
case V_75 :
if ( ! F_30 ( & V_8 -> V_26 ) )
V_70 = - V_24 ;
else
V_70 = F_37 ( V_8 ) ;
break;
default:
V_70 = 0 ;
}
if ( V_70 )
goto V_72;
F_9 ( 4 , L_17 ,
V_8 -> V_21 . V_22 , V_8 -> V_21 . V_23 , V_8 -> V_73 ) ;
V_72:
return V_70 ;
}
static T_3 F_40 ( int V_76 , void * V_77 )
{
struct V_78 * V_78 ;
struct V_7 * V_8 ;
struct V_65 * V_65 ;
F_41 ( V_79 ) ;
V_78 = (struct V_78 * ) & F_42 () -> V_80 ;
V_65 = F_43 ( & V_81 ) ;
V_8 = (struct V_7 * ) ( unsigned long ) V_78 -> V_34 ;
if ( ! V_8 ) {
F_44 ( V_82 ) ;
F_32 ( V_78 -> V_21 , V_65 ) ;
return V_83 ;
}
F_45 ( V_8 -> V_84 ) ;
if ( F_32 ( V_78 -> V_21 , V_65 ) == 0 ) {
memcpy ( & V_8 -> V_26 . V_44 , & V_65 -> V_44 , sizeof ( V_65 -> V_44 ) ) ;
if ( V_8 -> V_85 && V_8 -> V_85 -> V_76 )
V_8 -> V_85 -> V_76 ( V_8 ) ;
else
F_44 ( V_82 ) ;
} else
F_44 ( V_82 ) ;
F_46 ( V_8 -> V_84 ) ;
return V_83 ;
}
void T_1 F_47 ( void )
{
F_48 ( V_86 ,
& V_87 , V_88 ) ;
F_49 ( V_86 , & V_89 ) ;
}
void F_50 ( struct V_7 * V_8 )
{
struct V_65 * V_65 ;
int V_90 ;
V_65 = F_43 ( & V_81 ) ;
if ( F_32 ( V_8 -> V_21 , V_65 ) != 0 )
return;
memcpy ( & V_8 -> V_26 . V_44 , & V_65 -> V_44 , sizeof( union V_44 ) ) ;
V_90 = F_51 () ;
if ( ! V_90 ) {
F_52 () ;
F_53 () ;
}
F_54 ( V_86 ) ;
if ( V_8 -> V_85 && V_8 -> V_85 -> V_76 )
V_8 -> V_85 -> V_76 ( V_8 ) ;
else
F_44 ( V_82 ) ;
if ( ! V_90 ) {
F_55 () ;
F_56 () ;
}
}
static int F_57 ( struct V_68 V_21 , void * V_91 )
{
struct V_26 V_26 ;
if ( F_29 ( V_21 , & V_26 ) != 0 )
return - V_71 ;
if ( ( V_26 . V_53 . V_73 == V_74 ) && V_26 . V_53 . V_92 &&
( V_26 . V_53 . V_25 == V_93 ) ) {
V_94 = V_21 . V_23 ;
return 1 ;
}
return 0 ;
}
static int F_58 ( void )
{
struct V_68 V_21 ;
struct V_26 V_26 ;
F_59 ( & V_21 ) ;
if ( V_94 != - 1 ) {
V_21 . V_23 = V_94 ;
if ( F_29 ( V_21 , & V_26 ) != 0 ||
( V_26 . V_53 . V_73 != V_74 ) || ! V_26 . V_53 . V_92 )
return - 1 ;
V_93 = V_26 . V_53 . V_25 ;
} else if ( V_93 != - 1 ) {
F_60 ( F_57 , NULL ) ;
}
return V_94 ;
}
struct V_7 * F_61 ( void )
{
struct V_68 V_21 ;
struct V_7 * V_8 ;
int V_23 , V_64 ;
V_23 = F_58 () ;
if ( V_23 == - 1 ) {
F_62 ( L_18 ) ;
return F_63 ( - V_24 ) ;
}
F_59 ( & V_21 ) ;
V_21 . V_23 = V_23 ;
V_8 = F_64 ( V_21 ) ;
if ( F_65 ( V_8 ) )
return V_8 ;
F_66 ( V_8 -> V_84 , & V_95 ) ;
F_67 ( V_96 ) ;
V_8 -> V_54 . V_56 = V_96 ;
V_8 -> V_54 . V_34 = ( V_35 ) ( V_36 ) V_8 ;
V_64 = F_28 ( V_8 ) ;
if ( V_64 ) {
F_68 ( V_96 ) ;
F_69 ( & V_8 -> V_25 ) ;
return F_63 ( V_64 ) ;
}
V_97 = V_8 ;
return V_8 ;
}
int F_70 ( struct V_68 V_21 )
{
if ( ! V_97 )
return 0 ;
return F_71 ( & V_21 , & V_97 -> V_21 ) ;
}
void F_72 ( void )
{
int V_64 ;
if ( ! V_97 )
return;
V_64 = F_73 ( V_97 ) ;
if ( V_64 )
F_69 ( & V_97 -> V_25 ) ;
}
static int
F_74 ( struct V_68 V_21 , struct V_26 * V_26 )
{
int V_63 , V_98 ;
V_98 = 0 ;
for ( V_63 = 0 ; V_63 < 3 ; V_63 ++ ) {
V_26 -> V_53 . V_57 = 0 ;
V_98 = F_31 ( V_21 , V_26 ) ;
if ( V_98 )
return ( V_98 == 3 ? - V_24 : - V_47 ) ;
if ( F_29 ( V_21 , V_26 ) || ! F_30 ( V_26 ) )
return - V_24 ;
if ( ! V_26 -> V_53 . V_57 )
return 0 ;
}
return - V_47 ;
}
static int
F_75 ( struct V_68 V_21 )
{
int V_63 ;
if ( F_23 ( V_21 ) )
return - V_24 ;
for ( V_63 = 0 ; V_63 < 20 ; V_63 ++ ) {
struct V_78 V_99 ;
if ( F_76 ( & V_99 ) ) {
F_32 ( V_99 . V_21 , F_43 ( & V_81 ) ) ;
if ( F_71 ( & V_99 . V_21 , & V_21 ) )
return 0 ;
}
F_77 ( 100 ) ;
}
return - V_47 ;
}
static void F_78 ( void )
{
F_77 ( 100 ) ;
}
static void F_79 ( void )
{
V_100 = 1 ;
}
static int F_80 ( struct V_68 V_21 , struct V_26 * V_101 )
{
int V_102 ;
V_100 = 0 ;
V_103 = F_79 ;
V_102 = F_29 ( V_21 , V_101 ) ;
V_103 = NULL ;
F_81 () ;
if ( V_100 )
return - V_67 ;
else
return V_102 ;
}
static int F_82 ( struct V_68 V_21 , void * V_91 )
{
struct V_26 V_26 ;
if ( F_80 ( V_21 , & V_26 ) )
return - V_71 ;
if ( ! V_26 . V_53 . V_57 )
return 0 ;
switch( F_74 ( V_21 , & V_26 ) ) {
case 0 :
case - V_24 :
break;
default:
switch ( V_26 . V_53 . V_73 ) {
case V_74 :
if ( F_75 ( V_21 ) )
goto V_72;
break;
case V_104 :
F_78 () ;
break;
default:
break;
}
F_29 ( V_21 , & V_26 ) ;
F_74 ( V_21 , & V_26 ) ;
}
V_72:
return 0 ;
}
static void F_83 ( void )
{
struct V_105 V_105 ;
union V_106 V_106 ;
V_106 . V_107 = V_108 . V_109 ;
if ( ! V_106 . V_110 )
return;
while ( F_84 ( & V_105 ) == 0 ) {
if ( V_105 . V_111 && V_105 . V_112 == V_113 )
F_85 ( & V_114 ) ;
}
}
static void F_86 ( void )
{
int V_115 , V_64 ;
unsigned long long V_116 ;
struct V_117 V_118 ;
F_60 ( F_82 , NULL ) ;
V_119 = F_83 ;
F_87 ( 14 , 28 ) ;
F_88 () ;
F_89 ( & V_118 ) ;
for ( V_115 = 0 ; V_115 <= V_120 ; V_115 ++ ) {
V_118 . V_121 = V_115 ;
V_64 = F_90 ( V_118 ) ;
if ( ( V_64 == 0 ) || ( V_64 == 2 ) )
F_91 ( & V_114 ) ;
}
V_116 = F_92 () + ( V_122 << 12 ) ;
while ( F_93 ( & V_114 ) != 0 ) {
if ( F_92 () > V_116 )
break;
F_94 () ;
}
F_95 () ;
F_96 ( 14 , 28 ) ;
V_119 = NULL ;
}
static int T_1 F_97 ( void )
{
F_98 ( & V_114 , 0 ) ;
F_99 ( & V_123 ) ;
return 0 ;
}
static int F_100 ( struct V_68 V_21 , void * V_91 )
{
struct V_26 V_26 ;
struct V_124 * V_125 = V_91 ;
if ( F_80 ( V_21 , & V_26 ) )
return - V_71 ;
if ( ( V_26 . V_53 . V_73 == V_74 ) && V_26 . V_53 . V_92 &&
( V_26 . V_53 . V_25 == V_125 -> V_126 . V_127 ) &&
( V_21 . V_22 == V_125 -> V_126 . V_22 ) ) {
V_125 -> V_21 = V_21 ;
V_125 -> V_102 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_101 ( struct V_128 * V_126 ,
struct V_68 * V_21 )
{
struct V_124 V_125 ;
V_125 . V_126 = * V_126 ;
V_125 . V_102 = - V_24 ;
F_60 ( F_100 , & V_125 ) ;
if ( V_125 . V_102 == 0 )
* V_21 = V_125 . V_21 ;
return V_125 . V_102 ;
}
void F_102 ( struct V_128 * V_126 )
{
struct V_68 V_129 ( V_21 ) ;
F_103 ( NULL , NULL , NULL ) ;
if ( F_101 ( V_126 , & V_21 ) != 0 )
F_104 ( L_19 ) ;
F_105 ( * ( ( V_43 * ) & V_21 ) ) ;
}
int T_1 F_106 ( struct V_130 * V_131 )
{
static struct V_132 T_4 V_133 ;
struct V_68 V_21 ;
struct V_26 V_26 ;
V_21 = * (struct V_68 * ) & V_108 . V_68 ;
if ( ! V_21 . V_134 )
return - V_24 ;
if ( V_21 . V_22 ) {
memset ( & T_4 , 0 , sizeof( T_4 ) ) ;
if ( F_107 ( & T_4 , V_135 ) )
return - V_24 ;
}
if ( F_29 ( V_21 , & V_26 ) )
return - V_24 ;
if ( V_26 . V_53 . V_73 != V_74 )
return - V_24 ;
if ( ! V_26 . V_53 . V_92 )
return - V_24 ;
V_131 -> V_22 = V_21 . V_22 ;
V_131 -> V_127 = V_26 . V_53 . V_25 ;
V_131 -> V_136 = V_26 . V_53 . V_137 ;
return 0 ;
}
int F_108 ( struct V_7 * V_8 , struct V_138 * V_138 , T_5 V_19 , T_5 V_30 )
{
int V_98 ;
union V_31 * V_31 = & F_7 ( V_8 ) -> V_31 ;
memset ( V_31 , 0 , sizeof( union V_31 ) ) ;
V_31 -> V_139 . V_34 = ( V_35 ) ( V_36 ) V_8 ;
V_31 -> V_139 . V_30 = V_30 >> 4 ;
V_31 -> V_139 . V_140 = 1 ;
V_31 -> V_139 . V_19 = V_19 ? V_19 : V_8 -> V_19 ;
V_31 -> V_139 . V_138 = ( V_35 ) ( V_36 ) V_138 ;
V_98 = F_16 ( V_8 -> V_21 , V_31 ) ;
switch ( V_98 ) {
case 0 :
return 0 ;
case 1 :
case 2 :
return - V_47 ;
default:
return F_8 ( V_8 , V_19 ) ;
}
}
int F_109 ( struct V_7 * V_8 )
{
int V_98 ;
if ( ! F_7 ( V_8 ) -> V_31 . V_139 . V_140 )
return - V_50 ;
V_98 = F_25 ( V_8 -> V_21 ) ;
switch ( V_98 ) {
case 0 :
case 2 :
return 0 ;
case 1 :
return - V_47 ;
default:
return - V_24 ;
}
}
