static int T_1 F_1 ( void )
{
V_1 = F_2 ( L_1 , 16 , 1 , 16 * sizeof( long ) ) ;
if ( ! V_1 )
goto V_2;
F_3 ( V_1 , & V_3 ) ;
F_4 ( V_1 , 2 ) ;
V_4 = F_2 ( L_2 , 16 , 1 , 16 ) ;
if ( ! V_4 )
goto V_2;
F_3 ( V_4 , & V_5 ) ;
F_4 ( V_4 , 2 ) ;
V_6 = F_2 ( L_3 , 16 , 1 , 16 * sizeof( long ) ) ;
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
struct V_26 V_26 ;
int V_32 , V_63 , V_64 = 0 ;
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
V_64 = - V_65 ;
break;
case 1 :
return - V_47 ;
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
if ( F_30 ( V_8 -> V_21 , & V_26 ) || ! F_31 ( & V_26 ) )
return - V_24 ;
memcpy ( & V_8 -> V_26 , & V_26 , sizeof( V_26 ) ) ;
return 0 ;
}
int F_34 ( struct V_7 * V_8 , V_35 V_34 )
{
int V_63 ;
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
for ( V_63 = 0 ; V_63 < 3 ; V_63 ++ ) {
V_64 = F_29 ( V_8 ) ;
if ( V_64 == - V_66 ) {
V_8 -> V_54 . V_60 = 0 ;
} else if ( V_64 == - V_47 ) {
struct V_67 V_67 ;
if ( F_36 ( V_8 -> V_21 , & V_67 ) != 0 )
break;
} else
break;
}
F_13 ( 2 , & V_64 , sizeof( V_64 ) ) ;
return V_64 ;
}
int F_37 ( struct V_7 * V_8 )
{
int V_63 ;
int V_64 ;
F_12 ( 2 , L_13 ) ;
F_12 ( 2 , F_11 ( & V_8 -> V_25 ) ) ;
if ( F_35 ( V_8 ) )
return 0 ;
if ( F_10 ( V_8 ) )
return - V_24 ;
V_8 -> V_54 . V_57 = 0 ;
for ( V_63 = 0 ; V_63 < 3 ; V_63 ++ ) {
V_64 = F_29 ( V_8 ) ;
if ( V_64 == - V_47 ) {
struct V_67 V_67 ;
if ( F_36 ( V_8 -> V_21 , & V_67 ) != 0 )
break;
} else
break;
}
F_13 ( 2 , & V_64 , sizeof( V_64 ) ) ;
return V_64 ;
}
int F_38 ( struct V_7 * V_8 )
{
V_8 -> V_68 = F_39 ( sizeof( V_69 ) , V_70 ) ;
if ( ! V_8 -> V_68 )
return - V_71 ;
F_40 ( V_8 -> V_68 ) ;
return 0 ;
}
static int F_41 ( struct V_7 * V_8 )
{
if ( F_42 ( V_8 -> V_21 . V_22 , V_8 -> V_26 . V_53 . V_25 ) ) {
F_9 ( 6 , L_14
L_15 ,
V_8 -> V_26 . V_53 . V_25 , V_8 -> V_21 . V_22 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_43 ( struct V_7 * V_8 )
{
if ( ! F_31 ( & V_8 -> V_26 ) )
return - V_24 ;
return F_41 ( V_8 ) ;
}
static int F_44 ( struct V_7 * V_8 )
{
if ( ! F_31 ( & V_8 -> V_26 ) )
return - V_24 ;
return F_41 ( V_8 ) ;
}
int F_45 ( struct V_7 * V_8 , struct V_72 V_21 )
{
char V_73 [ 15 ] ;
int V_32 ;
int V_74 ;
sprintf ( V_73 , L_16 , V_21 . V_23 ) ;
F_12 ( 4 , V_73 ) ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_21 = V_21 ;
if ( F_46 ( V_21 ) ) {
V_8 -> V_68 = F_47 () ;
} else {
V_74 = F_38 ( V_8 ) ;
if ( V_74 )
goto V_75;
}
F_48 ( & V_8 -> V_76 ) ;
V_32 = F_30 ( V_21 , & V_8 -> V_26 ) ;
if ( V_32 ) {
V_74 = ( V_32 == 3 ) ? - V_77 : V_32 ;
goto V_75;
}
V_8 -> V_78 = V_8 -> V_26 . V_53 . V_78 ;
switch ( V_8 -> V_78 ) {
case V_79 :
V_74 = F_43 ( V_8 ) ;
break;
case V_80 :
V_74 = F_44 ( V_8 ) ;
break;
default:
V_74 = 0 ;
}
if ( V_74 )
goto V_75;
F_9 ( 4 , L_17 ,
V_8 -> V_21 . V_22 , V_8 -> V_21 . V_23 , V_8 -> V_78 ) ;
return 0 ;
V_75:
if ( ! F_46 ( V_21 ) )
F_49 ( V_8 -> V_68 ) ;
V_8 -> V_68 = NULL ;
return V_74 ;
}
void T_3 F_50 ( struct V_81 * V_82 )
{
struct V_83 * V_83 ;
struct V_7 * V_8 ;
struct V_67 * V_67 ;
struct V_81 * V_84 ;
V_84 = F_51 ( V_82 ) ;
F_52 () ;
F_53 ( V_85 . V_86 , 1 ) ;
if ( V_87 . V_88 >= V_87 . V_89 )
F_54 () ;
V_83 = (struct V_83 * ) & V_87 . V_72 ;
V_67 = (struct V_67 * ) & V_87 . V_67 ;
do {
F_55 ( V_90 , NULL ) ;
if ( V_83 -> V_91 ) {
F_56 ( V_83 -> V_56 ) ;
continue;
}
V_8 = (struct V_7 * ) ( unsigned long ) V_83 -> V_34 ;
if ( ! V_8 ) {
F_57 ( V_92 ) ;
F_36 ( V_83 -> V_21 , V_67 ) ;
continue;
}
F_58 ( V_8 -> V_68 ) ;
if ( F_36 ( V_83 -> V_21 , V_67 ) == 0 ) {
memcpy ( & V_8 -> V_26 . V_44 , & V_67 -> V_44 ,
sizeof ( V_67 -> V_44 ) ) ;
if ( V_8 -> V_93 && V_8 -> V_93 -> V_94 )
V_8 -> V_93 -> V_94 ( V_8 ) ;
else
F_57 ( V_92 ) ;
} else
F_57 ( V_92 ) ;
F_59 ( V_8 -> V_68 ) ;
} while ( V_95 && F_60 ( NULL ) != 0 );
F_61 () ;
F_51 ( V_84 ) ;
}
static void F_62 ( struct V_7 * V_8 )
{
struct V_67 * V_67 ;
int V_96 ;
V_67 = (struct V_67 * ) & V_87 . V_67 ;
if ( F_36 ( V_8 -> V_21 , V_67 ) != 0 )
return;
memcpy ( & V_8 -> V_26 . V_44 , & V_67 -> V_44 , sizeof( union V_44 ) ) ;
V_96 = F_63 () ;
if ( ! V_96 ) {
F_64 () ;
F_52 () ;
}
if ( V_8 -> V_93 && V_8 -> V_93 -> V_94 )
V_8 -> V_93 -> V_94 ( V_8 ) ;
else
F_57 ( V_92 ) ;
if ( ! V_96 ) {
F_61 () ;
F_65 () ;
}
}
void * F_66 ( void )
{
return & V_97 ;
}
void F_67 ( void )
{
if ( ! V_98 )
return;
while ( 1 ) {
F_62 ( & V_99 ) ;
if ( V_99 . V_26 . V_44 . V_33 . V_45 == 0 )
break;
F_68 ( 100 ) ;
}
}
static int
F_69 ( struct V_72 V_21 , void * V_100 )
{
if ( F_30 ( V_21 , & V_99 . V_26 ) != 0 )
return - V_77 ;
if ( ( V_99 . V_26 . V_53 . V_78 == V_79 ) &&
V_99 . V_26 . V_53 . V_101 &&
( V_99 . V_26 . V_53 . V_25 == V_102 ) ) {
V_103 = V_21 . V_23 ;
return 1 ;
}
return 0 ;
}
static int
F_70 ( void )
{
struct V_72 V_21 ;
F_71 ( & V_21 ) ;
if ( V_103 != - 1 ) {
V_21 . V_23 = V_103 ;
if ( F_30 ( V_21 , & V_99 . V_26 ) != 0 ||
( V_99 . V_26 . V_53 . V_78 != V_79 ) ||
! V_99 . V_26 . V_53 . V_101 )
return - 1 ;
V_102 = V_99 . V_26 . V_53 . V_25 ;
} else if ( V_102 != - 1 ) {
F_72 ( F_69 , NULL ) ;
if ( V_103 == - 1 )
return - 1 ;
} else {
return - 1 ;
}
return V_103 ;
}
struct V_7 *
F_73 ( void )
{
int V_23 , V_64 ;
struct V_72 V_21 ;
if ( F_74 ( & V_98 , 1 ) != 0 )
return F_75 ( - V_47 ) ;
V_23 = F_70 () ;
if ( V_23 == - 1 ) {
V_98 = 0 ;
F_76 ( L_18 ) ;
return F_75 ( - V_24 ) ;
}
memset ( & V_99 , 0 , sizeof( struct V_7 ) ) ;
F_71 ( & V_21 ) ;
V_21 . V_23 = V_23 ;
V_64 = F_45 ( & V_99 , V_21 ) ;
if ( V_64 ) {
V_98 = 0 ;
return F_75 ( - V_24 ) ;
}
F_77 ( V_104 ) ;
V_99 . V_54 . V_56 = V_104 ;
V_99 . V_54 . V_34 = ( V_35 ) ( V_36 ) & V_99 ;
V_64 = F_29 ( & V_99 ) ;
if ( V_64 ) {
F_78 ( V_104 ) ;
V_98 = 0 ;
return F_75 ( V_64 ) ;
}
return & V_99 ;
}
void
F_79 ( void )
{
V_99 . V_54 . V_34 = 0 ;
F_29 ( & V_99 ) ;
F_78 ( V_104 ) ;
V_98 = 0 ;
}
int
F_46 ( struct V_72 V_21 )
{
if ( ! V_98 )
return 0 ;
return F_80 ( & V_21 , & V_99 . V_21 ) ;
}
struct V_7 *
F_81 ( void )
{
if ( ! V_98 )
return NULL ;
return & V_99 ;
}
static int
F_82 ( struct V_72 V_21 , struct V_26 * V_26 )
{
int V_63 , V_105 ;
V_105 = 0 ;
for ( V_63 = 0 ; V_63 < 3 ; V_63 ++ ) {
V_26 -> V_53 . V_57 = 0 ;
V_105 = F_32 ( V_21 , V_26 ) ;
if ( V_105 )
return ( V_105 == 3 ? - V_24 : - V_47 ) ;
if ( F_30 ( V_21 , V_26 ) || ! F_31 ( V_26 ) )
return - V_24 ;
if ( ! V_26 -> V_53 . V_57 )
return 0 ;
}
return - V_47 ;
}
static int
F_83 ( struct V_72 V_21 )
{
int V_63 ;
if ( F_24 ( V_21 ) )
return - V_24 ;
for ( V_63 = 0 ; V_63 < 20 ; V_63 ++ ) {
struct V_83 V_106 ;
if ( F_60 ( & V_106 ) ) {
F_36 ( V_106 . V_21 , (struct V_67 * ) & V_87 . V_67 ) ;
if ( F_80 ( & V_106 . V_21 , & V_21 ) )
return 0 ;
}
F_68 ( 100 ) ;
}
return - V_47 ;
}
static void F_84 ( void )
{
F_68 ( 100 ) ;
}
static void F_85 ( void )
{
V_107 = 1 ;
}
static int F_86 ( struct V_72 V_21 , struct V_26 * V_108 )
{
int V_109 ;
V_107 = 0 ;
V_110 = F_85 ;
V_109 = F_30 ( V_21 , V_108 ) ;
V_110 = NULL ;
F_87 () ;
if ( V_107 )
return - V_66 ;
else
return V_109 ;
}
static int F_88 ( struct V_72 V_21 , void * V_100 )
{
struct V_26 V_26 ;
if ( F_86 ( V_21 , & V_26 ) )
return - V_77 ;
if ( ! V_26 . V_53 . V_57 )
return 0 ;
switch( F_82 ( V_21 , & V_26 ) ) {
case 0 :
case - V_24 :
break;
default:
switch ( V_26 . V_53 . V_78 ) {
case V_79 :
if ( F_83 ( V_21 ) )
goto V_75;
break;
case V_111 :
F_84 () ;
break;
default:
break;
}
F_30 ( V_21 , & V_26 ) ;
F_82 ( V_21 , & V_26 ) ;
}
V_75:
return 0 ;
}
static void F_89 ( void )
{
struct V_112 V_112 ;
struct V_113 * V_113 ;
V_113 = (struct V_113 * ) & V_87 . V_114 ;
if ( ! V_113 -> V_115 )
return;
while ( F_90 ( & V_112 ) == 0 ) {
if ( V_112 . V_116 && V_112 . V_117 == V_118 )
F_91 ( & V_119 ) ;
}
}
static void F_92 ( void )
{
int V_120 , V_64 ;
unsigned long long V_121 ;
struct V_122 V_123 ;
F_72 ( F_88 , NULL ) ;
V_124 = F_89 ;
F_93 ( 14 , 28 ) ;
F_94 () ;
F_95 ( & V_123 ) ;
for ( V_120 = 0 ; V_120 <= V_125 ; V_120 ++ ) {
V_123 . V_126 = V_120 ;
V_64 = F_96 ( V_123 ) ;
if ( ( V_64 == 0 ) || ( V_64 == 2 ) )
F_97 ( & V_119 ) ;
}
V_121 = F_98 () + ( V_127 << 12 ) ;
while ( F_99 ( & V_119 ) != 0 ) {
if ( F_98 () > V_121 )
break;
F_100 () ;
}
F_101 () ;
F_102 ( 14 , 28 ) ;
V_124 = NULL ;
}
static int T_1 F_103 ( void )
{
F_104 ( & V_119 , 0 ) ;
F_105 ( & V_128 ) ;
return 0 ;
}
static int F_106 ( struct V_72 V_21 , void * V_100 )
{
struct V_26 V_26 ;
struct V_129 * V_130 = V_100 ;
if ( F_86 ( V_21 , & V_26 ) )
return - V_77 ;
if ( ( V_26 . V_53 . V_78 == V_79 ) && V_26 . V_53 . V_101 &&
( V_26 . V_53 . V_25 == V_130 -> V_131 . V_132 ) &&
( V_21 . V_22 == V_130 -> V_131 . V_22 ) ) {
V_130 -> V_21 = V_21 ;
V_130 -> V_109 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_107 ( struct V_133 * V_131 ,
struct V_72 * V_21 )
{
struct V_129 V_130 ;
V_130 . V_131 = * V_131 ;
V_130 . V_109 = - V_24 ;
F_72 ( F_106 , & V_130 ) ;
if ( V_130 . V_109 == 0 )
* V_21 = V_130 . V_21 ;
return V_130 . V_109 ;
}
void F_108 ( struct V_133 * V_131 )
{
struct V_72 V_134 ( V_21 ) ;
F_109 ( NULL , NULL ) ;
if ( F_107 ( V_131 , & V_21 ) != 0 )
F_110 ( L_19 ) ;
F_111 ( * ( ( V_43 * ) & V_21 ) ) ;
}
int T_1 F_112 ( struct V_135 * V_136 )
{
struct V_72 V_21 ;
struct V_26 V_26 ;
V_21 = * (struct V_72 * ) & V_87 . V_72 ;
if ( ! V_21 . V_137 )
return - V_24 ;
if ( F_30 ( V_21 , & V_26 ) )
return - V_24 ;
if ( V_26 . V_53 . V_78 != V_79 )
return - V_24 ;
if ( ! V_26 . V_53 . V_101 )
return - V_24 ;
V_136 -> V_132 = V_26 . V_53 . V_25 ;
V_136 -> V_138 = V_26 . V_53 . V_139 ;
return 0 ;
}
int F_113 ( struct V_7 * V_8 , struct V_140 * V_140 , T_4 V_19 , T_4 V_30 )
{
int V_105 ;
union V_31 * V_31 = & F_7 ( V_8 ) -> V_31 ;
memset ( V_31 , 0 , sizeof( union V_31 ) ) ;
V_31 -> V_141 . V_34 = ( V_35 ) ( V_36 ) V_8 ;
V_31 -> V_141 . V_30 = V_30 >> 4 ;
V_31 -> V_141 . V_142 = 1 ;
V_31 -> V_141 . V_19 = V_19 ? V_19 : V_8 -> V_19 ;
V_31 -> V_141 . V_140 = ( V_35 ) ( V_36 ) V_140 ;
V_105 = F_17 ( V_8 -> V_21 , V_31 ) ;
switch ( V_105 ) {
case 0 :
return 0 ;
case 1 :
case 2 :
return - V_47 ;
default:
return F_8 ( V_8 , V_19 ) ;
}
}
int F_114 ( struct V_7 * V_8 )
{
int V_105 ;
if ( ! F_7 ( V_8 ) -> V_31 . V_141 . V_142 )
return - V_50 ;
V_105 = F_26 ( V_8 -> V_21 ) ;
switch ( V_105 ) {
case 0 :
case 2 :
return 0 ;
case 1 :
return - V_47 ;
default:
return - V_24 ;
}
}
