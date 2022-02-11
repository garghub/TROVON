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
#ifdef F_15
V_31 -> V_33 . V_41 = 1 ;
V_31 -> V_33 . V_42 = 0 ;
#endif
V_31 -> V_33 . V_30 = V_30 >> 4 ;
V_31 -> V_33 . V_29 = ( V_43 ) F_16 ( V_29 ) ;
V_32 = F_17 ( V_8 -> V_21 , V_31 ) ;
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
F_18 ( struct V_7 * V_8 , struct V_28 * V_29 , T_2 V_19 )
{
return F_14 ( V_8 , V_29 , V_19 , V_48 ) ;
}
int
F_19 ( struct V_7 * V_8 )
{
int V_32 ;
F_12 ( 4 , L_8 ) ;
F_12 ( 4 , F_11 ( & V_8 -> V_25 ) ) ;
V_32 = F_20 ( V_8 -> V_21 ) ;
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
F_21 ( struct V_7 * V_8 )
{
int V_32 ;
if ( ! V_8 )
return - V_24 ;
F_12 ( 2 , L_9 ) ;
F_12 ( 2 , F_11 ( & V_8 -> V_25 ) ) ;
V_32 = F_22 ( V_8 -> V_21 ) ;
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
F_23 ( struct V_7 * V_8 )
{
int V_32 ;
if ( ! V_8 )
return - V_24 ;
F_12 ( 2 , L_10 ) ;
F_12 ( 2 , F_11 ( & V_8 -> V_25 ) ) ;
V_32 = F_24 ( V_8 -> V_21 ) ;
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
F_25 ( struct V_7 * V_8 )
{
int V_32 ;
if ( ! V_8 )
return - V_24 ;
F_12 ( 2 , L_11 ) ;
F_12 ( 2 , F_11 ( & V_8 -> V_25 ) ) ;
V_32 = F_26 ( V_8 -> V_21 ) ;
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
static void F_27 ( struct V_7 * V_8 , struct V_26 * V_26 )
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
static int F_28 ( struct V_7 * V_8 , struct V_26 * V_26 )
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
int F_29 ( struct V_7 * V_8 )
{
int V_32 , V_63 , V_64 = 0 ;
struct V_26 V_26 ;
struct V_65 V_65 ;
if ( F_30 ( V_8 -> V_21 , & V_26 ) || ! F_31 ( & V_26 ) )
return - V_24 ;
for ( V_63 = 0 ; V_63 < 5 ; V_63 ++ ) {
F_27 ( V_8 , & V_26 ) ;
V_32 = F_32 ( V_8 -> V_21 , & V_26 ) ;
if ( V_32 < 0 )
return V_32 ;
switch ( V_32 ) {
case 0 :
if ( F_30 ( V_8 -> V_21 , & V_26 ) ||
! F_31 ( & V_26 ) )
return - V_24 ;
if ( F_28 ( V_8 , & V_26 ) ) {
memcpy ( & V_8 -> V_26 , & V_26 , sizeof( V_26 ) ) ;
return 0 ;
}
V_64 = - V_66 ;
break;
case 1 :
V_64 = - V_47 ;
if ( F_33 ( V_8 -> V_21 , & V_65 ) )
return V_64 ;
break;
case 2 :
F_34 ( 100 ) ;
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
if ( F_30 ( V_8 -> V_21 , & V_26 ) || ! F_31 ( & V_26 ) )
return - V_24 ;
memcpy ( & V_8 -> V_26 , & V_26 , sizeof( V_26 ) ) ;
return 0 ;
}
int F_35 ( struct V_7 * V_8 , V_35 V_34 )
{
int V_64 ;
F_12 ( 2 , L_12 ) ;
F_12 ( 2 , F_11 ( & V_8 -> V_25 ) ) ;
if ( F_36 ( V_8 ) )
return - V_50 ;
if ( F_10 ( V_8 ) )
return - V_24 ;
V_8 -> V_54 . V_57 = 1 ;
V_8 -> V_54 . V_56 = V_8 -> V_56 ;
V_8 -> V_54 . V_34 = V_34 ;
V_64 = F_29 ( V_8 ) ;
if ( V_64 == - V_67 ) {
V_8 -> V_54 . V_60 = 0 ;
V_64 = F_29 ( V_8 ) ;
}
F_13 ( 2 , & V_64 , sizeof( V_64 ) ) ;
return V_64 ;
}
int F_37 ( struct V_7 * V_8 )
{
int V_64 ;
F_12 ( 2 , L_13 ) ;
F_12 ( 2 , F_11 ( & V_8 -> V_25 ) ) ;
if ( F_36 ( V_8 ) )
return 0 ;
if ( F_10 ( V_8 ) )
return - V_24 ;
V_8 -> V_54 . V_57 = 0 ;
V_64 = F_29 ( V_8 ) ;
F_13 ( 2 , & V_64 , sizeof( V_64 ) ) ;
return V_64 ;
}
static int F_38 ( struct V_7 * V_8 )
{
if ( F_39 ( V_8 -> V_21 . V_22 , V_8 -> V_26 . V_53 . V_25 ) ) {
F_9 ( 6 , L_14
L_15 ,
V_8 -> V_26 . V_53 . V_25 , V_8 -> V_21 . V_22 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_40 ( struct V_7 * V_8 )
{
if ( ! F_31 ( & V_8 -> V_26 ) )
return - V_24 ;
return F_38 ( V_8 ) ;
}
static int F_41 ( struct V_7 * V_8 )
{
if ( ! F_31 ( & V_8 -> V_26 ) )
return - V_24 ;
return F_38 ( V_8 ) ;
}
int F_42 ( struct V_7 * V_8 , struct V_68 V_21 )
{
char V_69 [ 15 ] ;
int V_32 ;
int V_70 ;
sprintf ( V_69 , L_16 , V_21 . V_23 ) ;
F_12 ( 4 , V_69 ) ;
V_32 = F_30 ( V_21 , & V_8 -> V_26 ) ;
if ( V_32 ) {
V_70 = ( V_32 == 3 ) ? - V_71 : V_32 ;
goto V_72;
}
V_8 -> V_73 = V_8 -> V_26 . V_53 . V_73 ;
V_8 -> V_21 = V_21 ;
switch ( V_8 -> V_73 ) {
case V_74 :
V_70 = F_40 ( V_8 ) ;
break;
case V_75 :
V_70 = F_41 ( V_8 ) ;
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
static T_3 F_43 ( int V_76 , void * V_77 )
{
struct V_78 * V_78 ;
struct V_7 * V_8 ;
struct V_65 * V_65 ;
F_44 ( V_79 . V_80 , 1 ) ;
V_78 = (struct V_78 * ) & F_45 () -> V_81 ;
V_65 = (struct V_65 * ) & V_82 . V_65 ;
V_8 = (struct V_7 * ) ( unsigned long ) V_78 -> V_34 ;
if ( ! V_8 ) {
F_46 ( V_83 ) ;
F_33 ( V_78 -> V_21 , V_65 ) ;
return V_84 ;
}
F_47 ( V_8 -> V_85 ) ;
if ( F_33 ( V_78 -> V_21 , V_65 ) == 0 ) {
memcpy ( & V_8 -> V_26 . V_44 , & V_65 -> V_44 , sizeof ( V_65 -> V_44 ) ) ;
if ( V_8 -> V_86 && V_8 -> V_86 -> V_76 )
V_8 -> V_86 -> V_76 ( V_8 ) ;
else
F_46 ( V_83 ) ;
} else
F_46 ( V_83 ) ;
F_48 ( V_8 -> V_85 ) ;
return V_84 ;
}
void T_1 F_49 ( void )
{
F_50 ( V_87 ,
& V_88 , V_89 ) ;
F_51 ( V_87 , & V_90 ) ;
}
void F_52 ( struct V_7 * V_8 )
{
struct V_65 * V_65 ;
int V_91 ;
V_65 = (struct V_65 * ) & V_82 . V_65 ;
if ( F_33 ( V_8 -> V_21 , V_65 ) != 0 )
return;
memcpy ( & V_8 -> V_26 . V_44 , & V_65 -> V_44 , sizeof( union V_44 ) ) ;
V_91 = F_53 () ;
if ( ! V_91 ) {
F_54 () ;
F_55 () ;
}
F_56 ( V_87 ) ;
if ( V_8 -> V_86 && V_8 -> V_86 -> V_76 )
V_8 -> V_86 -> V_76 ( V_8 ) ;
else
F_46 ( V_83 ) ;
if ( ! V_91 ) {
F_57 () ;
F_58 () ;
}
}
static int F_59 ( struct V_68 V_21 , void * V_92 )
{
struct V_26 V_26 ;
if ( F_30 ( V_21 , & V_26 ) != 0 )
return - V_71 ;
if ( ( V_26 . V_53 . V_73 == V_74 ) && V_26 . V_53 . V_93 &&
( V_26 . V_53 . V_25 == V_94 ) ) {
V_95 = V_21 . V_23 ;
return 1 ;
}
return 0 ;
}
static int F_60 ( void )
{
struct V_68 V_21 ;
struct V_26 V_26 ;
F_61 ( & V_21 ) ;
if ( V_95 != - 1 ) {
V_21 . V_23 = V_95 ;
if ( F_30 ( V_21 , & V_26 ) != 0 ||
( V_26 . V_53 . V_73 != V_74 ) || ! V_26 . V_53 . V_93 )
return - 1 ;
V_94 = V_26 . V_53 . V_25 ;
} else if ( V_94 != - 1 ) {
F_62 ( F_59 , NULL ) ;
}
return V_95 ;
}
struct V_7 * F_63 ( void )
{
struct V_68 V_21 ;
struct V_7 * V_8 ;
int V_23 , V_64 ;
V_23 = F_60 () ;
if ( V_23 == - 1 ) {
F_64 ( L_18 ) ;
return F_65 ( - V_24 ) ;
}
F_61 ( & V_21 ) ;
V_21 . V_23 = V_23 ;
V_8 = F_66 ( V_21 ) ;
if ( F_67 ( V_8 ) )
return V_8 ;
F_68 ( V_96 ) ;
V_8 -> V_54 . V_56 = V_96 ;
V_8 -> V_54 . V_34 = ( V_35 ) ( V_36 ) V_8 ;
V_64 = F_29 ( V_8 ) ;
if ( V_64 ) {
F_69 ( V_96 ) ;
F_70 ( & V_8 -> V_25 ) ;
return F_65 ( V_64 ) ;
}
V_97 = V_8 ;
return V_8 ;
}
int F_71 ( struct V_68 V_21 )
{
if ( ! V_97 )
return 0 ;
return F_72 ( & V_21 , & V_97 -> V_21 ) ;
}
void F_73 ( void )
{
int V_64 ;
if ( ! V_97 )
return;
V_64 = F_74 ( V_97 ) ;
if ( V_64 )
F_70 ( & V_97 -> V_25 ) ;
}
static int
F_75 ( struct V_68 V_21 , struct V_26 * V_26 )
{
int V_63 , V_98 ;
V_98 = 0 ;
for ( V_63 = 0 ; V_63 < 3 ; V_63 ++ ) {
V_26 -> V_53 . V_57 = 0 ;
V_98 = F_32 ( V_21 , V_26 ) ;
if ( V_98 )
return ( V_98 == 3 ? - V_24 : - V_47 ) ;
if ( F_30 ( V_21 , V_26 ) || ! F_31 ( V_26 ) )
return - V_24 ;
if ( ! V_26 -> V_53 . V_57 )
return 0 ;
}
return - V_47 ;
}
static int
F_76 ( struct V_68 V_21 )
{
int V_63 ;
if ( F_24 ( V_21 ) )
return - V_24 ;
for ( V_63 = 0 ; V_63 < 20 ; V_63 ++ ) {
struct V_78 V_99 ;
if ( F_77 ( & V_99 ) ) {
F_33 ( V_99 . V_21 , (struct V_65 * ) & V_82 . V_65 ) ;
if ( F_72 ( & V_99 . V_21 , & V_21 ) )
return 0 ;
}
F_78 ( 100 ) ;
}
return - V_47 ;
}
static void F_79 ( void )
{
F_78 ( 100 ) ;
}
static void F_80 ( void )
{
V_100 = 1 ;
}
static int F_81 ( struct V_68 V_21 , struct V_26 * V_101 )
{
int V_102 ;
V_100 = 0 ;
V_103 = F_80 ;
V_102 = F_30 ( V_21 , V_101 ) ;
V_103 = NULL ;
F_82 () ;
if ( V_100 )
return - V_67 ;
else
return V_102 ;
}
static int F_83 ( struct V_68 V_21 , void * V_92 )
{
struct V_26 V_26 ;
if ( F_81 ( V_21 , & V_26 ) )
return - V_71 ;
if ( ! V_26 . V_53 . V_57 )
return 0 ;
switch( F_75 ( V_21 , & V_26 ) ) {
case 0 :
case - V_24 :
break;
default:
switch ( V_26 . V_53 . V_73 ) {
case V_74 :
if ( F_76 ( V_21 ) )
goto V_72;
break;
case V_104 :
F_79 () ;
break;
default:
break;
}
F_30 ( V_21 , & V_26 ) ;
F_75 ( V_21 , & V_26 ) ;
}
V_72:
return 0 ;
}
static void F_84 ( void )
{
struct V_105 V_105 ;
struct V_106 * V_106 ;
V_106 = (struct V_106 * ) & V_82 . V_107 ;
if ( ! V_106 -> V_108 )
return;
while ( F_85 ( & V_105 ) == 0 ) {
if ( V_105 . V_109 && V_105 . V_110 == V_111 )
F_86 ( & V_112 ) ;
}
}
static void F_87 ( void )
{
int V_113 , V_64 ;
unsigned long long V_114 ;
struct V_115 V_116 ;
F_62 ( F_83 , NULL ) ;
V_117 = F_84 ;
F_88 ( 14 , 28 ) ;
F_89 () ;
F_90 ( & V_116 ) ;
for ( V_113 = 0 ; V_113 <= V_118 ; V_113 ++ ) {
V_116 . V_119 = V_113 ;
V_64 = F_91 ( V_116 ) ;
if ( ( V_64 == 0 ) || ( V_64 == 2 ) )
F_92 ( & V_112 ) ;
}
V_114 = F_93 () + ( V_120 << 12 ) ;
while ( F_94 ( & V_112 ) != 0 ) {
if ( F_93 () > V_114 )
break;
F_95 () ;
}
F_96 () ;
F_97 ( 14 , 28 ) ;
V_117 = NULL ;
}
static int T_1 F_98 ( void )
{
F_99 ( & V_112 , 0 ) ;
F_100 ( & V_121 ) ;
return 0 ;
}
static int F_101 ( struct V_68 V_21 , void * V_92 )
{
struct V_26 V_26 ;
struct V_122 * V_123 = V_92 ;
if ( F_81 ( V_21 , & V_26 ) )
return - V_71 ;
if ( ( V_26 . V_53 . V_73 == V_74 ) && V_26 . V_53 . V_93 &&
( V_26 . V_53 . V_25 == V_123 -> V_124 . V_125 ) &&
( V_21 . V_22 == V_123 -> V_124 . V_22 ) ) {
V_123 -> V_21 = V_21 ;
V_123 -> V_102 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_102 ( struct V_126 * V_124 ,
struct V_68 * V_21 )
{
struct V_122 V_123 ;
V_123 . V_124 = * V_124 ;
V_123 . V_102 = - V_24 ;
F_62 ( F_101 , & V_123 ) ;
if ( V_123 . V_102 == 0 )
* V_21 = V_123 . V_21 ;
return V_123 . V_102 ;
}
void F_103 ( struct V_126 * V_124 )
{
struct V_68 V_127 ( V_21 ) ;
F_104 ( NULL , NULL ) ;
if ( F_102 ( V_124 , & V_21 ) != 0 )
F_105 ( L_19 ) ;
F_106 ( * ( ( V_43 * ) & V_21 ) ) ;
}
int T_1 F_107 ( struct V_128 * V_129 )
{
struct V_68 V_21 ;
struct V_26 V_26 ;
V_21 = * (struct V_68 * ) & V_82 . V_68 ;
if ( ! V_21 . V_130 )
return - V_24 ;
if ( F_30 ( V_21 , & V_26 ) )
return - V_24 ;
if ( V_26 . V_53 . V_73 != V_74 )
return - V_24 ;
if ( ! V_26 . V_53 . V_93 )
return - V_24 ;
V_129 -> V_125 = V_26 . V_53 . V_25 ;
V_129 -> V_131 = V_26 . V_53 . V_132 ;
return 0 ;
}
int F_108 ( struct V_7 * V_8 , struct V_133 * V_133 , T_4 V_19 , T_4 V_30 )
{
int V_98 ;
union V_31 * V_31 = & F_7 ( V_8 ) -> V_31 ;
memset ( V_31 , 0 , sizeof( union V_31 ) ) ;
V_31 -> V_134 . V_34 = ( V_35 ) ( V_36 ) V_8 ;
V_31 -> V_134 . V_30 = V_30 >> 4 ;
V_31 -> V_134 . V_135 = 1 ;
V_31 -> V_134 . V_19 = V_19 ? V_19 : V_8 -> V_19 ;
V_31 -> V_134 . V_133 = ( V_35 ) ( V_36 ) V_133 ;
V_98 = F_17 ( V_8 -> V_21 , V_31 ) ;
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
if ( ! F_7 ( V_8 ) -> V_31 . V_134 . V_135 )
return - V_50 ;
V_98 = F_26 ( V_8 -> V_21 ) ;
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
