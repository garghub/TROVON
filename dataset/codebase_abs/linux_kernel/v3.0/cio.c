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
F_52 ( V_82 , V_85 . V_86 ,
V_85 . V_87 ) ;
F_53 () ;
F_54 ( V_88 . V_89 , 1 ) ;
if ( V_85 . V_86 >= V_85 . V_90 )
F_55 () ;
V_83 = (struct V_83 * ) & V_85 . V_72 ;
V_67 = (struct V_67 * ) & V_85 . V_67 ;
do {
F_56 ( F_57 () ) . V_91 [ V_92 ] ++ ;
if ( V_83 -> V_93 ) {
F_58 ( V_83 -> V_56 ) ;
continue;
}
V_8 = (struct V_7 * ) ( unsigned long ) V_83 -> V_34 ;
if ( ! V_8 ) {
F_36 ( V_83 -> V_21 , V_67 ) ;
continue;
}
F_59 ( V_8 -> V_68 ) ;
if ( F_36 ( V_83 -> V_21 , V_67 ) == 0 ) {
memcpy ( & V_8 -> V_26 . V_44 , & V_67 -> V_44 ,
sizeof ( V_67 -> V_44 ) ) ;
if ( V_8 -> V_94 && V_8 -> V_94 -> V_95 )
V_8 -> V_94 -> V_95 ( V_8 ) ;
}
F_60 ( V_8 -> V_68 ) ;
} while ( V_96 && F_61 ( NULL ) != 0 );
F_62 () ;
F_51 ( V_84 ) ;
}
static int F_63 ( void )
{
struct V_83 * V_83 ;
struct V_7 * V_8 ;
struct V_67 * V_67 ;
int V_97 ;
V_83 = (struct V_83 * ) & V_85 . V_72 ;
if ( F_61 ( NULL ) != 1 )
return 0 ;
V_67 = (struct V_67 * ) & V_85 . V_67 ;
if ( F_36 ( V_83 -> V_21 , V_67 ) != 0 )
return 1 ;
V_8 = (struct V_7 * ) ( unsigned long ) V_83 -> V_34 ;
if ( ! V_8 )
return 1 ;
V_97 = F_64 () ;
if ( ! V_97 )
F_65 () ;
F_53 () ;
F_59 ( V_8 -> V_68 ) ;
memcpy ( & V_8 -> V_26 . V_44 , & V_67 -> V_44 , sizeof( union V_44 ) ) ;
if ( V_8 -> V_94 && V_8 -> V_94 -> V_95 )
V_8 -> V_94 -> V_95 ( V_8 ) ;
F_60 ( V_8 -> V_68 ) ;
F_62 () ;
if ( ! V_97 )
F_66 () ;
return 1 ;
}
void * F_67 ( void )
{
return & V_98 ;
}
void F_68 ( void )
__releases( V_99 . V_68 )
__acquires( V_99 . V_68 )
{
unsigned long T_4 V_100 ( ( F_69 ( 8 ) ) ) ;
unsigned long T_5 V_100 ( ( F_69 ( 8 ) ) ) ;
if ( ! V_101 )
return;
F_70 ( T_5 , 6 , 6 ) ;
T_4 = 1UL << ( 31 - V_102 ) ;
F_71 ( T_4 , 6 , 6 ) ;
do {
F_60 ( V_99 . V_68 ) ;
if ( ! F_63 () )
F_72 () ;
F_59 ( V_99 . V_68 ) ;
} while ( V_99 . V_26 . V_44 . V_33 . V_45 != 0 );
F_71 ( T_5 , 6 , 6 ) ;
}
static int
F_73 ( struct V_72 V_21 , void * V_103 )
{
if ( F_30 ( V_21 , & V_99 . V_26 ) != 0 )
return - V_77 ;
if ( ( V_99 . V_26 . V_53 . V_78 == V_79 ) &&
V_99 . V_26 . V_53 . V_104 &&
( V_99 . V_26 . V_53 . V_25 == V_105 ) ) {
V_106 = V_21 . V_23 ;
return 1 ;
}
return 0 ;
}
static int
F_74 ( void )
{
struct V_72 V_21 ;
F_75 ( & V_21 ) ;
if ( V_106 != - 1 ) {
V_21 . V_23 = V_106 ;
if ( F_30 ( V_21 , & V_99 . V_26 ) != 0 ||
( V_99 . V_26 . V_53 . V_78 != V_79 ) ||
! V_99 . V_26 . V_53 . V_104 )
return - 1 ;
V_105 = V_99 . V_26 . V_53 . V_25 ;
} else if ( V_105 != - 1 ) {
F_76 ( F_73 , NULL ) ;
if ( V_106 == - 1 )
return - 1 ;
} else {
return - 1 ;
}
return V_106 ;
}
struct V_7 *
F_77 ( void )
{
int V_23 , V_64 ;
struct V_72 V_21 ;
if ( F_78 ( & V_101 , 1 ) != 0 )
return F_79 ( - V_47 ) ;
V_23 = F_74 () ;
if ( V_23 == - 1 ) {
V_101 = 0 ;
F_80 ( L_18 ) ;
return F_79 ( - V_24 ) ;
}
memset ( & V_99 , 0 , sizeof( struct V_7 ) ) ;
F_75 ( & V_21 ) ;
V_21 . V_23 = V_23 ;
V_64 = F_45 ( & V_99 , V_21 ) ;
if ( V_64 ) {
V_101 = 0 ;
return F_79 ( - V_24 ) ;
}
F_81 ( V_102 ) ;
V_99 . V_54 . V_56 = V_102 ;
V_99 . V_54 . V_34 = ( V_35 ) ( V_36 ) & V_99 ;
V_64 = F_29 ( & V_99 ) ;
if ( V_64 ) {
F_82 ( V_102 ) ;
V_101 = 0 ;
return F_79 ( V_64 ) ;
}
return & V_99 ;
}
void
F_83 ( void )
{
V_99 . V_54 . V_34 = 0 ;
F_29 ( & V_99 ) ;
F_82 ( V_102 ) ;
V_101 = 0 ;
}
int
F_46 ( struct V_72 V_21 )
{
if ( ! V_101 )
return 0 ;
return F_84 ( & V_21 , & V_99 . V_21 ) ;
}
struct V_7 *
F_85 ( void )
{
if ( ! V_101 )
return NULL ;
return & V_99 ;
}
static int
F_86 ( struct V_72 V_21 , struct V_26 * V_26 )
{
int V_63 , V_107 ;
V_107 = 0 ;
for ( V_63 = 0 ; V_63 < 3 ; V_63 ++ ) {
V_26 -> V_53 . V_57 = 0 ;
V_107 = F_32 ( V_21 , V_26 ) ;
if ( V_107 )
return ( V_107 == 3 ? - V_24 : - V_47 ) ;
if ( F_30 ( V_21 , V_26 ) || ! F_31 ( V_26 ) )
return - V_24 ;
if ( ! V_26 -> V_53 . V_57 )
return 0 ;
}
return - V_47 ;
}
static int
F_87 ( struct V_72 V_21 )
{
int V_63 ;
if ( F_24 ( V_21 ) )
return - V_24 ;
for ( V_63 = 0 ; V_63 < 20 ; V_63 ++ ) {
struct V_83 V_108 ;
if ( F_61 ( & V_108 ) ) {
F_36 ( V_108 . V_21 , (struct V_67 * ) & V_85 . V_67 ) ;
if ( F_84 ( & V_108 . V_21 , & V_21 ) )
return 0 ;
}
F_88 ( 100 ) ;
}
return - V_47 ;
}
static void F_89 ( void )
{
F_88 ( 100 ) ;
}
static void F_90 ( void )
{
V_109 = 1 ;
}
static int F_91 ( struct V_72 V_21 , struct V_26 * V_110 )
{
int V_111 ;
V_109 = 0 ;
V_112 = F_90 ;
V_111 = F_30 ( V_21 , V_110 ) ;
V_112 = NULL ;
F_92 () ;
if ( V_109 )
return - V_66 ;
else
return V_111 ;
}
static int F_93 ( struct V_72 V_21 , void * V_103 )
{
struct V_26 V_26 ;
if ( F_91 ( V_21 , & V_26 ) )
return - V_77 ;
if ( ! V_26 . V_53 . V_57 )
return 0 ;
switch( F_86 ( V_21 , & V_26 ) ) {
case 0 :
case - V_24 :
break;
default:
switch ( V_26 . V_53 . V_78 ) {
case V_79 :
if ( F_87 ( V_21 ) )
goto V_75;
break;
case V_113 :
F_89 () ;
break;
default:
break;
}
F_30 ( V_21 , & V_26 ) ;
F_86 ( V_21 , & V_26 ) ;
}
V_75:
return 0 ;
}
static void F_94 ( void )
{
struct V_114 V_114 ;
struct V_115 * V_115 ;
V_115 = (struct V_115 * ) & V_85 . V_116 ;
if ( ! V_115 -> V_117 )
return;
while ( F_95 ( & V_114 ) == 0 ) {
if ( V_114 . V_118 && V_114 . V_119 == V_120 )
F_96 ( & V_121 ) ;
}
}
static void F_97 ( void )
{
int V_122 , V_64 ;
unsigned long long V_123 ;
struct V_124 V_125 ;
F_76 ( F_93 , NULL ) ;
V_126 = F_94 ;
F_98 ( 14 , 28 ) ;
F_99 () ;
F_100 ( & V_125 ) ;
for ( V_122 = 0 ; V_122 <= V_127 ; V_122 ++ ) {
V_125 . V_128 = V_122 ;
V_64 = F_101 ( V_125 ) ;
if ( ( V_64 == 0 ) || ( V_64 == 2 ) )
F_102 ( & V_121 ) ;
}
V_123 = F_103 () + ( V_129 << 12 ) ;
while ( F_104 ( & V_121 ) != 0 ) {
if ( F_103 () > V_123 )
break;
F_72 () ;
}
F_105 () ;
F_106 ( 14 , 28 ) ;
V_126 = NULL ;
}
static int T_1 F_107 ( void )
{
F_108 ( & V_121 , 0 ) ;
F_109 ( & V_130 ) ;
return 0 ;
}
static int F_110 ( struct V_72 V_21 , void * V_103 )
{
struct V_26 V_26 ;
struct V_131 * V_132 = V_103 ;
if ( F_91 ( V_21 , & V_26 ) )
return - V_77 ;
if ( ( V_26 . V_53 . V_78 == V_79 ) && V_26 . V_53 . V_104 &&
( V_26 . V_53 . V_25 == V_132 -> V_133 . V_134 ) &&
( V_21 . V_22 == V_132 -> V_133 . V_22 ) ) {
V_132 -> V_21 = V_21 ;
V_132 -> V_111 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_111 ( struct V_135 * V_133 ,
struct V_72 * V_21 )
{
struct V_131 V_132 ;
V_132 . V_133 = * V_133 ;
V_132 . V_111 = - V_24 ;
F_76 ( F_110 , & V_132 ) ;
if ( V_132 . V_111 == 0 )
* V_21 = V_132 . V_21 ;
return V_132 . V_111 ;
}
void F_112 ( struct V_135 * V_133 )
{
struct V_72 V_21 ;
F_113 () ;
if ( F_111 ( V_133 , & V_21 ) != 0 )
F_114 ( L_19 ) ;
F_115 ( * ( ( V_43 * ) & V_21 ) ) ;
}
int T_1 F_116 ( struct V_136 * V_137 )
{
struct V_72 V_21 ;
struct V_26 V_26 ;
V_21 = * (struct V_72 * ) & V_85 . V_72 ;
if ( ! V_21 . V_138 )
return - V_24 ;
if ( F_30 ( V_21 , & V_26 ) )
return - V_24 ;
if ( V_26 . V_53 . V_78 != V_79 )
return - V_24 ;
if ( ! V_26 . V_53 . V_104 )
return - V_24 ;
V_137 -> V_134 = V_26 . V_53 . V_25 ;
V_137 -> V_139 = V_26 . V_53 . V_140 ;
return 0 ;
}
int F_117 ( struct V_7 * V_8 , struct V_141 * V_141 , T_6 V_19 , T_6 V_30 )
{
int V_107 ;
union V_31 * V_31 = & F_7 ( V_8 ) -> V_31 ;
memset ( V_31 , 0 , sizeof( union V_31 ) ) ;
V_31 -> V_142 . V_34 = ( V_35 ) ( V_36 ) V_8 ;
V_31 -> V_142 . V_30 = V_30 >> 4 ;
V_31 -> V_142 . V_143 = 1 ;
V_31 -> V_142 . V_19 = V_19 ? V_19 : V_8 -> V_19 ;
V_31 -> V_142 . V_141 = ( V_35 ) ( V_36 ) V_141 ;
V_107 = F_17 ( V_8 -> V_21 , V_31 ) ;
switch ( V_107 ) {
case 0 :
return 0 ;
case 1 :
case 2 :
return - V_47 ;
default:
return F_8 ( V_8 , V_19 ) ;
}
}
int F_118 ( struct V_7 * V_8 )
{
int V_107 ;
if ( ! F_7 ( V_8 ) -> V_31 . V_142 . V_143 )
return - V_50 ;
V_107 = F_26 ( V_8 -> V_21 ) ;
switch ( V_107 ) {
case 0 :
case 2 :
return 0 ;
case 1 :
return - V_47 ;
default:
return - V_24 ;
}
}
