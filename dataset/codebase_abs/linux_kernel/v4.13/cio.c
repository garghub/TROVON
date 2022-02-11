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
F_5 ( V_1 ) ;
F_5 ( V_4 ) ;
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
int F_26 ( struct V_7 * V_8 , int * V_53 )
{
int V_54 ;
if ( F_10 ( V_8 ) )
return - V_24 ;
if ( ! V_8 -> V_26 . V_55 . V_56 )
return 0 ;
if ( ! ( F_27 ( & V_8 -> V_26 . V_44 ) & V_51 ) &&
! ( F_27 ( & V_8 -> V_26 . V_44 ) & V_52 ) ) {
if ( ! F_28 ( & V_8 -> V_26 . V_44 ) ) {
V_54 = F_24 ( V_8 ) ;
if ( V_54 != - V_50 )
return V_54 ;
}
* V_53 = 3 ;
}
if ( ! ( F_27 ( & V_8 -> V_26 . V_44 ) & V_52 ) ) {
if ( * V_53 ) {
* V_53 -= 1 ;
V_54 = F_20 ( V_8 ) ;
if ( V_54 != - V_47 )
return ( V_54 == 0 ) ? - V_47 : V_54 ;
}
* V_53 = 255 ;
}
if ( * V_53 ) {
* V_53 -= 1 ;
V_54 = F_22 ( V_8 ) ;
return ( V_54 == 0 ) ? - V_47 : V_54 ;
}
return - V_57 ;
}
static void F_29 ( struct V_7 * V_8 , struct V_26 * V_26 )
{
V_26 -> V_55 . V_34 = V_8 -> V_58 . V_34 ;
V_26 -> V_55 . V_59 = V_8 -> V_58 . V_59 ;
V_26 -> V_55 . V_60 = V_8 -> V_58 . V_60 ;
V_26 -> V_55 . V_56 = V_8 -> V_58 . V_56 ;
V_26 -> V_55 . V_61 = V_8 -> V_58 . V_61 ;
V_26 -> V_55 . V_62 = V_8 -> V_58 . V_62 ;
V_26 -> V_55 . V_63 = V_8 -> V_58 . V_63 ;
V_26 -> V_55 . V_64 = V_8 -> V_58 . V_64 ;
if ( V_8 -> V_58 . V_64 )
V_26 -> V_65 = V_8 -> V_58 . V_65 ;
}
static int F_30 ( struct V_7 * V_8 , struct V_26 * V_26 )
{
return ( V_26 -> V_55 . V_34 == V_8 -> V_58 . V_34 ) &&
( V_26 -> V_55 . V_59 == V_8 -> V_58 . V_59 ) &&
( V_26 -> V_55 . V_60 == V_8 -> V_58 . V_60 ) &&
( V_26 -> V_55 . V_56 == V_8 -> V_58 . V_56 ) &&
( V_26 -> V_55 . V_61 == V_8 -> V_58 . V_61 ) &&
( V_26 -> V_55 . V_62 == V_8 -> V_58 . V_62 ) &&
( V_26 -> V_55 . V_63 == V_8 -> V_58 . V_63 ) &&
( V_26 -> V_55 . V_64 == V_8 -> V_58 . V_64 ) &&
( ! V_8 -> V_58 . V_64 || ( V_26 -> V_65 == V_8 -> V_58 . V_65 ) ) ;
}
int F_31 ( struct V_7 * V_8 )
{
int V_32 , V_66 , V_54 = 0 ;
struct V_26 V_26 ;
struct V_67 V_67 ;
if ( F_32 ( V_8 -> V_21 , & V_26 ) || ! F_33 ( & V_26 ) )
return - V_24 ;
for ( V_66 = 0 ; V_66 < 5 ; V_66 ++ ) {
F_29 ( V_8 , & V_26 ) ;
V_32 = F_34 ( V_8 -> V_21 , & V_26 ) ;
if ( V_32 < 0 )
return V_32 ;
switch ( V_32 ) {
case 0 :
if ( F_32 ( V_8 -> V_21 , & V_26 ) ||
! F_33 ( & V_26 ) )
return - V_24 ;
if ( F_30 ( V_8 , & V_26 ) ) {
memcpy ( & V_8 -> V_26 , & V_26 , sizeof( V_26 ) ) ;
return 0 ;
}
V_54 = - V_68 ;
break;
case 1 :
V_54 = - V_47 ;
if ( F_35 ( V_8 -> V_21 , & V_67 ) )
return V_54 ;
break;
case 2 :
F_36 ( 100 ) ;
V_54 = - V_47 ;
break;
case 3 :
return - V_24 ;
}
}
return V_54 ;
}
int F_10 ( struct V_7 * V_8 )
{
struct V_26 V_26 ;
if ( F_32 ( V_8 -> V_21 , & V_26 ) || ! F_33 ( & V_26 ) )
return - V_24 ;
memcpy ( & V_8 -> V_26 , & V_26 , sizeof( V_26 ) ) ;
return 0 ;
}
int F_37 ( struct V_7 * V_8 , V_35 V_34 )
{
int V_54 ;
F_12 ( 2 , L_12 ) ;
F_12 ( 2 , F_11 ( & V_8 -> V_25 ) ) ;
if ( F_38 ( V_8 ) )
return - V_50 ;
if ( F_10 ( V_8 ) )
return - V_24 ;
V_8 -> V_58 . V_56 = 1 ;
V_8 -> V_58 . V_60 = V_8 -> V_60 ;
V_8 -> V_58 . V_34 = V_34 ;
V_54 = F_31 ( V_8 ) ;
if ( V_54 == - V_57 ) {
V_8 -> V_58 . V_63 = 0 ;
V_54 = F_31 ( V_8 ) ;
}
F_13 ( 2 , & V_54 , sizeof( V_54 ) ) ;
return V_54 ;
}
int F_39 ( struct V_7 * V_8 )
{
int V_54 ;
F_12 ( 2 , L_13 ) ;
F_12 ( 2 , F_11 ( & V_8 -> V_25 ) ) ;
if ( F_38 ( V_8 ) )
return 0 ;
if ( F_10 ( V_8 ) )
return - V_24 ;
V_8 -> V_58 . V_56 = 0 ;
V_54 = F_31 ( V_8 ) ;
F_13 ( 2 , & V_54 , sizeof( V_54 ) ) ;
return V_54 ;
}
static int F_40 ( struct V_7 * V_8 )
{
if ( F_41 ( V_8 -> V_21 . V_22 , V_8 -> V_26 . V_55 . V_25 ) ) {
F_9 ( 6 , L_14
L_15 ,
V_8 -> V_26 . V_55 . V_25 , V_8 -> V_21 . V_22 ) ;
return - V_24 ;
}
return 0 ;
}
int F_42 ( struct V_7 * V_8 , struct V_69 V_21 )
{
char V_70 [ 15 ] ;
int V_32 ;
int V_71 ;
sprintf ( V_70 , L_16 , V_21 . V_23 ) ;
F_12 ( 4 , V_70 ) ;
V_32 = F_32 ( V_21 , & V_8 -> V_26 ) ;
if ( V_32 ) {
V_71 = ( V_32 == 3 ) ? - V_72 : V_32 ;
goto V_73;
}
V_8 -> V_74 = V_8 -> V_26 . V_55 . V_74 ;
V_8 -> V_21 = V_21 ;
switch ( V_8 -> V_74 ) {
case V_75 :
case V_76 :
if ( ! F_33 ( & V_8 -> V_26 ) )
V_71 = - V_24 ;
else
V_71 = F_40 ( V_8 ) ;
break;
default:
V_71 = 0 ;
}
if ( V_71 )
goto V_73;
F_9 ( 4 , L_17 ,
V_8 -> V_21 . V_22 , V_8 -> V_21 . V_23 , V_8 -> V_74 ) ;
V_73:
return V_71 ;
}
static T_3 F_43 ( int V_77 , void * V_78 )
{
struct V_79 * V_79 ;
struct V_7 * V_8 ;
struct V_67 * V_67 ;
F_44 ( V_80 ) ;
V_79 = (struct V_79 * ) & F_45 () -> V_81 ;
F_46 ( V_79 ) ;
V_67 = F_47 ( & V_82 ) ;
V_8 = (struct V_7 * ) ( unsigned long ) V_79 -> V_34 ;
if ( ! V_8 ) {
F_48 ( V_83 ) ;
F_35 ( V_79 -> V_21 , V_67 ) ;
return V_84 ;
}
F_49 ( V_8 -> V_85 ) ;
if ( F_35 ( V_79 -> V_21 , V_67 ) == 0 ) {
memcpy ( & V_8 -> V_26 . V_44 , & V_67 -> V_44 , sizeof ( V_67 -> V_44 ) ) ;
if ( V_8 -> V_86 && V_8 -> V_86 -> V_77 )
V_8 -> V_86 -> V_77 ( V_8 ) ;
else
F_48 ( V_83 ) ;
} else
F_48 ( V_83 ) ;
F_50 ( V_8 -> V_85 ) ;
return V_84 ;
}
void T_1 F_51 ( void )
{
F_52 ( V_87 ,
& V_88 , V_89 ) ;
F_53 ( V_87 , & V_90 ) ;
}
void F_54 ( struct V_7 * V_8 )
{
struct V_67 * V_67 ;
int V_91 ;
V_67 = F_47 ( & V_82 ) ;
if ( F_35 ( V_8 -> V_21 , V_67 ) != 0 )
return;
memcpy ( & V_8 -> V_26 . V_44 , & V_67 -> V_44 , sizeof( union V_44 ) ) ;
V_91 = F_55 () ;
if ( ! V_91 ) {
F_56 () ;
F_57 () ;
}
F_58 ( V_87 ) ;
if ( V_8 -> V_86 && V_8 -> V_86 -> V_77 )
V_8 -> V_86 -> V_77 ( V_8 ) ;
else
F_48 ( V_83 ) ;
if ( ! V_91 ) {
F_59 () ;
F_60 () ;
}
}
static int F_61 ( struct V_69 V_21 , void * V_92 )
{
struct V_26 V_26 ;
if ( F_32 ( V_21 , & V_26 ) != 0 )
return - V_72 ;
if ( ( V_26 . V_55 . V_74 == V_75 ) && V_26 . V_55 . V_93 &&
( V_26 . V_55 . V_25 == V_94 ) ) {
V_95 = V_21 . V_23 ;
return 1 ;
}
return 0 ;
}
static int F_62 ( void )
{
struct V_69 V_21 ;
struct V_26 V_26 ;
F_63 ( & V_21 ) ;
if ( V_95 != - 1 ) {
V_21 . V_23 = V_95 ;
if ( F_32 ( V_21 , & V_26 ) != 0 ||
( V_26 . V_55 . V_74 != V_75 ) || ! V_26 . V_55 . V_93 )
return - 1 ;
V_94 = V_26 . V_55 . V_25 ;
} else if ( V_94 != - 1 ) {
F_64 ( F_61 , NULL ) ;
}
return V_95 ;
}
struct V_7 * F_65 ( void )
{
struct V_69 V_21 ;
struct V_7 * V_8 ;
int V_23 , V_54 ;
V_23 = F_62 () ;
if ( V_23 == - 1 ) {
F_66 ( L_18 ) ;
return F_67 ( - V_24 ) ;
}
F_63 ( & V_21 ) ;
V_21 . V_23 = V_23 ;
V_8 = F_68 ( V_21 ) ;
if ( F_69 ( V_8 ) )
return V_8 ;
F_70 ( V_8 -> V_85 , & V_96 ) ;
F_71 ( V_97 ) ;
V_8 -> V_58 . V_60 = V_97 ;
V_8 -> V_58 . V_34 = ( V_35 ) ( V_36 ) V_8 ;
V_54 = F_31 ( V_8 ) ;
if ( V_54 ) {
F_72 ( V_97 ) ;
F_73 ( & V_8 -> V_25 ) ;
return F_67 ( V_54 ) ;
}
V_98 = V_8 ;
return V_8 ;
}
int F_74 ( struct V_69 V_21 )
{
if ( ! V_98 )
return 0 ;
return F_75 ( & V_21 , & V_98 -> V_21 ) ;
}
void F_76 ( void )
{
int V_54 ;
if ( ! V_98 )
return;
V_54 = F_77 ( V_98 ) ;
if ( V_54 )
F_73 ( & V_98 -> V_25 ) ;
}
static int
F_78 ( struct V_69 V_21 , struct V_26 * V_26 )
{
int V_66 , V_99 ;
V_99 = 0 ;
for ( V_66 = 0 ; V_66 < 3 ; V_66 ++ ) {
V_26 -> V_55 . V_56 = 0 ;
V_99 = F_34 ( V_21 , V_26 ) ;
if ( V_99 )
return ( V_99 == 3 ? - V_24 : - V_47 ) ;
if ( F_32 ( V_21 , V_26 ) || ! F_33 ( V_26 ) )
return - V_24 ;
if ( ! V_26 -> V_55 . V_56 )
return 0 ;
}
return - V_47 ;
}
static int
F_79 ( struct V_69 V_21 )
{
int V_66 ;
if ( F_23 ( V_21 ) )
return - V_24 ;
for ( V_66 = 0 ; V_66 < 20 ; V_66 ++ ) {
struct V_79 V_100 ;
if ( F_80 ( & V_100 ) ) {
F_35 ( V_100 . V_21 , F_47 ( & V_82 ) ) ;
if ( F_75 ( & V_100 . V_21 , & V_21 ) )
return 0 ;
}
F_81 ( 100 ) ;
}
return - V_47 ;
}
static void F_82 ( void )
{
F_81 ( 100 ) ;
}
static void F_83 ( void )
{
V_101 = 1 ;
}
static int F_84 ( struct V_69 V_21 , struct V_26 * V_102 )
{
int V_103 ;
V_101 = 0 ;
V_104 = F_83 ;
V_103 = F_32 ( V_21 , V_102 ) ;
V_104 = NULL ;
F_85 () ;
if ( V_101 )
return - V_57 ;
else
return V_103 ;
}
static int F_86 ( struct V_69 V_21 , void * V_92 )
{
struct V_26 V_26 ;
if ( F_84 ( V_21 , & V_26 ) )
return - V_72 ;
if ( ! V_26 . V_55 . V_56 )
return 0 ;
switch( F_78 ( V_21 , & V_26 ) ) {
case 0 :
case - V_24 :
break;
default:
switch ( V_26 . V_55 . V_74 ) {
case V_75 :
if ( F_79 ( V_21 ) )
goto V_73;
break;
case V_105 :
F_82 () ;
break;
default:
break;
}
F_32 ( V_21 , & V_26 ) ;
F_78 ( V_21 , & V_26 ) ;
}
V_73:
return 0 ;
}
static void F_87 ( void )
{
struct V_106 V_106 ;
union V_107 V_107 ;
V_107 . V_108 = V_109 . V_110 ;
if ( ! V_107 . V_111 )
return;
while ( F_88 ( & V_106 ) == 0 ) {
if ( V_106 . V_112 && V_106 . V_113 == V_114 )
F_89 ( & V_115 ) ;
}
}
static void F_90 ( void )
{
int V_116 , V_54 ;
unsigned long long V_117 ;
struct V_118 V_119 ;
F_64 ( F_86 , NULL ) ;
V_120 = F_87 ;
F_91 ( 14 , 28 ) ;
F_92 () ;
F_93 ( & V_119 ) ;
for ( V_116 = 0 ; V_116 <= V_121 ; V_116 ++ ) {
V_119 . V_122 = V_116 ;
V_54 = F_94 ( V_119 ) ;
if ( ( V_54 == 0 ) || ( V_54 == 2 ) )
F_95 ( & V_115 ) ;
}
V_117 = F_96 () + ( V_123 << 12 ) ;
while ( F_97 ( & V_115 ) != 0 ) {
if ( F_96 () > V_117 )
break;
F_98 () ;
}
F_99 () ;
F_100 ( 14 , 28 ) ;
V_120 = NULL ;
}
static int T_1 F_101 ( void )
{
F_102 ( & V_115 , 0 ) ;
F_103 ( & V_124 ) ;
return 0 ;
}
static int F_104 ( struct V_69 V_21 , void * V_92 )
{
struct V_26 V_26 ;
struct V_125 * V_126 = V_92 ;
if ( F_84 ( V_21 , & V_26 ) )
return - V_72 ;
if ( ( V_26 . V_55 . V_74 == V_75 ) && V_26 . V_55 . V_93 &&
( V_26 . V_55 . V_25 == V_126 -> V_127 . V_128 ) &&
( V_21 . V_22 == V_126 -> V_127 . V_22 ) ) {
V_126 -> V_21 = V_21 ;
V_126 -> V_103 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_105 ( struct V_129 * V_127 ,
struct V_69 * V_21 )
{
struct V_125 V_126 ;
V_126 . V_127 = * V_127 ;
V_126 . V_103 = - V_24 ;
F_64 ( F_104 , & V_126 ) ;
if ( V_126 . V_103 == 0 )
* V_21 = V_126 . V_21 ;
return V_126 . V_103 ;
}
void F_106 ( struct V_129 * V_127 )
{
struct V_69 V_130 ( V_21 ) ;
F_107 () ;
if ( F_105 ( V_127 , & V_21 ) != 0 )
F_108 ( L_19 ) ;
F_109 ( * ( ( V_43 * ) & V_21 ) ) ;
}
int T_1 F_110 ( struct V_131 * V_132 )
{
static struct V_133 T_4 V_134 ;
struct V_69 V_21 ;
struct V_26 V_26 ;
V_21 = * (struct V_69 * ) & V_109 . V_69 ;
if ( ! V_21 . V_135 )
return - V_24 ;
if ( V_21 . V_22 ) {
memset ( & T_4 , 0 , sizeof( T_4 ) ) ;
if ( F_111 ( & T_4 , V_136 ) )
return - V_24 ;
}
if ( F_32 ( V_21 , & V_26 ) )
return - V_24 ;
if ( V_26 . V_55 . V_74 != V_75 )
return - V_24 ;
if ( ! V_26 . V_55 . V_93 )
return - V_24 ;
V_132 -> V_22 = V_21 . V_22 ;
V_132 -> V_128 = V_26 . V_55 . V_25 ;
V_132 -> V_137 = V_26 . V_55 . V_138 ;
return 0 ;
}
int F_112 ( struct V_7 * V_8 , struct V_139 * V_139 , T_5 V_19 , T_5 V_30 )
{
int V_99 ;
union V_31 * V_31 = & F_7 ( V_8 ) -> V_31 ;
memset ( V_31 , 0 , sizeof( union V_31 ) ) ;
V_31 -> V_140 . V_34 = ( V_35 ) ( V_36 ) V_8 ;
V_31 -> V_140 . V_30 = V_30 >> 4 ;
V_31 -> V_140 . V_141 = 1 ;
V_31 -> V_140 . V_19 = V_19 ? V_19 : V_8 -> V_19 ;
V_31 -> V_140 . V_139 = ( V_35 ) ( V_36 ) V_139 ;
V_99 = F_16 ( V_8 -> V_21 , V_31 ) ;
switch ( V_99 ) {
case 0 :
return 0 ;
case 1 :
case 2 :
return - V_47 ;
default:
return F_8 ( V_8 , V_19 ) ;
}
}
int F_113 ( struct V_7 * V_8 )
{
int V_99 ;
if ( ! F_7 ( V_8 ) -> V_31 . V_140 . V_141 )
return - V_50 ;
V_99 = F_25 ( V_8 -> V_21 ) ;
switch ( V_99 ) {
case 0 :
case 2 :
return 0 ;
case 1 :
return - V_47 ;
default:
return - V_24 ;
}
}
