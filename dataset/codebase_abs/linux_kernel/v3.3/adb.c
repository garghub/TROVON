static int F_1 ( void )
{
int V_1 , V_2 = 0 , V_3 ;
int V_4 = 0 ;
struct V_5 V_6 ;
for ( V_1 = 1 ; V_1 < 16 ; V_1 ++ ) {
V_5 ( & V_6 , NULL , V_7 | V_8 , 1 ,
( V_1 << 4 ) | 0xf ) ;
if ( V_6 . V_9 > 1 )
V_10 [ V_1 ] . V_11 = V_1 ;
else if ( V_1 > V_2 )
V_2 = V_1 ;
}
for ( V_3 = 1 ; V_3 < 2 && V_2 > 0 ; V_3 ++ ) {
for ( V_1 = 1 ; V_1 < 16 ; V_1 ++ ) {
if ( V_10 [ V_1 ] . V_11 == 0 )
continue;
V_5 ( & V_6 , NULL , V_7 | V_8 , 1 ,
( V_1 << 4 ) | 0xf ) ;
V_5 ( & V_6 , NULL , V_7 , 3 ,
( V_1 << 4 ) | 0xb , ( V_2 | 0x60 ) , 0xfe ) ;
V_5 ( & V_6 , NULL , V_7 | V_8 , 1 ,
( V_2 << 4 ) | 0xf ) ;
if ( V_6 . V_9 <= 1 ) continue;
V_5 ( & V_6 , NULL , V_7 | V_8 , 1 ,
( V_1 << 4 ) | 0xf ) ;
if ( V_6 . V_9 > 1 ) {
V_10 [ V_2 ] . V_11 =
V_10 [ V_1 ] . V_11 ;
while ( V_2 > 0 &&
V_10 [ V_2 ] . V_11 )
V_2 -- ;
if ( V_2 <= 0 )
break;
V_3 = 0 ;
}
else {
V_5 ( & V_6 , NULL , V_7 , 3 ,
( V_2 << 4 ) | 0xb ,
( V_1 | 0x60 ) , 0xfe ) ;
}
}
}
F_2 ( V_12 L_1 ) ;
for ( V_1 = 1 ; V_1 < 16 ; V_1 ++ ) {
if ( V_10 [ V_1 ] . V_11 == 0 )
continue;
V_5 ( & V_6 , NULL , V_7 | V_8 , 1 ,
( V_1 << 4 ) | 0xf ) ;
V_10 [ V_1 ] . V_13 = V_6 . V_14 [ 2 ] ;
F_2 ( L_2 , V_1 , V_10 [ V_1 ] . V_11 ,
V_10 [ V_1 ] . V_13 ) ;
V_4 |= 1 << V_1 ;
}
F_2 ( L_3 ) ;
return V_4 ;
}
static int
F_3 ( void * V_15 )
{
F_2 ( V_16 L_4 ) ;
F_4 () ;
F_2 ( V_16 L_5 ) ;
F_5 ( & V_17 ) ;
return 0 ;
}
static void
F_6 ( struct V_18 * V_19 )
{
F_7 ( F_3 , NULL , L_6 ) ;
}
int
F_8 ( void )
{
if ( V_20 ) {
F_4 () ;
return 0 ;
}
F_9 ( & V_17 ) ;
F_10 ( & V_21 ) ;
return 0 ;
}
static int F_11 ( struct V_22 * V_23 , T_1 V_24 )
{
V_25 = 1 ;
F_9 ( & V_17 ) ;
if ( V_26 -> V_27 )
V_26 -> V_27 ( 0 ) ;
F_12 ( & V_28 , V_29 , NULL ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 )
{
V_25 = 0 ;
F_5 ( & V_17 ) ;
F_8 () ;
return 0 ;
}
static int T_2 F_14 ( void )
{
struct V_30 * V_31 ;
int V_1 ;
#ifdef F_15
if ( ! F_16 ( V_32 ) && ! F_16 ( V_33 ) )
return 0 ;
#endif
#ifdef F_17
if ( ! V_34 )
return 0 ;
#endif
if ( V_35 )
return 0 ;
V_35 = 1 ;
V_26 = NULL ;
V_1 = 0 ;
while ( ( V_31 = V_36 [ V_1 ++ ] ) != NULL ) {
if ( ! V_31 -> V_37 () ) {
V_26 = V_31 ;
break;
}
}
if ( V_26 != NULL && V_26 -> V_38 &&
V_26 -> V_38 () )
V_26 = NULL ;
if ( V_26 == NULL ) {
F_2 ( V_39 L_7 ) ;
} else {
#ifdef F_18
if ( F_19 ( L_8 ) ||
F_19 ( L_9 ) )
V_40 = 1 ;
#endif
F_20 () ;
F_8 () ;
}
return 0 ;
}
static int
F_4 ( void )
{
int V_41 ;
if ( V_26 == NULL )
return - V_42 ;
if ( V_26 -> V_27 )
V_26 -> V_27 ( 0 ) ;
F_12 ( & V_28 ,
V_43 , NULL ) ;
if ( V_40 ) {
F_21 ( 500 ) ;
}
F_22 ( & V_44 ) ;
F_23 ( & V_45 ) ;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
F_24 ( & V_45 ) ;
if ( V_26 -> V_46 )
V_41 = V_26 -> V_46 () ;
else
V_41 = 0 ;
if ( V_40 ) {
F_21 ( 1500 ) ;
}
if ( ! V_41 ) {
V_47 = F_1 () ;
if ( V_26 -> V_27 )
V_26 -> V_27 ( V_47 ) ;
}
F_25 ( & V_44 ) ;
F_12 ( & V_28 ,
V_48 , NULL ) ;
return V_41 ;
}
void
F_26 ( void )
{
if ( ( V_26 == NULL ) || ( V_26 -> V_49 == NULL ) )
return;
V_26 -> V_49 () ;
}
static void F_27 ( struct V_5 * V_6 )
{
struct V_50 * V_51 = V_6 -> V_52 ;
F_28 ( V_51 ) ;
}
int
V_5 ( struct V_5 * V_6 , void (* F_29)( struct V_5 * ) ,
int V_53 , int V_54 , ... )
{
T_3 V_55 ;
int V_1 ;
int V_56 ;
struct V_50 V_51 ;
if ( ( V_26 == NULL ) || ( V_26 -> V_57 == NULL ) )
return - V_42 ;
if ( V_54 < 1 )
return - V_58 ;
V_6 -> V_54 = V_54 + 1 ;
V_6 -> F_29 = F_29 ;
V_6 -> V_59 = V_53 & V_8 ;
V_6 -> V_60 [ 0 ] = V_61 ;
va_start ( V_55 , V_54 ) ;
for ( V_1 = 0 ; V_1 < V_54 ; ++ V_1 )
V_6 -> V_60 [ V_1 + 1 ] = va_arg ( V_55 , int ) ;
va_end ( V_55 ) ;
if ( V_53 & V_62 )
return 0 ;
if ( V_53 & V_7 ) {
F_30 ( F_29 ) ;
V_6 -> F_29 = F_27 ;
V_6 -> V_52 = & V_51 ;
F_31 ( & V_51 ) ;
}
V_56 = V_26 -> V_57 ( V_6 , 0 ) ;
if ( ( V_53 & V_7 ) && ! V_56 && ! V_6 -> F_28 )
F_32 ( & V_51 ) ;
return V_56 ;
}
int
F_33 ( int V_63 , int V_13 , struct V_64 * V_65 ,
void (* F_34)( unsigned char * , int , int ) )
{
int V_1 ;
F_22 ( & V_44 ) ;
V_65 -> V_66 = 0 ;
for ( V_1 = 1 ; V_1 < 16 ; V_1 ++ ) {
if ( ( V_10 [ V_1 ] . V_11 == V_63 ) &&
( ! V_13 || ( V_13 == V_10 [ V_1 ] . V_13 ) ||
F_35 ( V_1 , V_13 ) ) ) {
if ( V_10 [ V_1 ] . F_34 != 0 ) {
F_2 ( V_67
L_10 ,
V_63 ) ;
continue;
}
F_23 ( & V_45 ) ;
V_10 [ V_1 ] . F_34 = F_34 ;
F_24 ( & V_45 ) ;
V_65 -> V_68 [ V_65 -> V_66 ++ ] = V_1 ;
}
}
F_25 ( & V_44 ) ;
return V_65 -> V_66 ;
}
int
F_36 ( int V_69 )
{
int V_41 = - V_70 ;
F_22 ( & V_44 ) ;
F_23 ( & V_45 ) ;
if ( V_10 [ V_69 ] . F_34 ) {
while( V_10 [ V_69 ] . V_71 ) {
F_24 ( & V_45 ) ;
F_37 () ;
F_23 ( & V_45 ) ;
}
V_41 = 0 ;
V_10 [ V_69 ] . F_34 = NULL ;
}
F_24 ( & V_45 ) ;
F_25 ( & V_44 ) ;
return V_41 ;
}
void
F_38 ( unsigned char * V_72 , int V_73 , int V_27 )
{
int V_1 , V_68 ;
static int V_74 = 0 ;
unsigned long V_53 ;
void (* F_34)( unsigned char * , int , int );
if ( V_25 )
return;
V_68 = V_72 [ 0 ] >> 4 ;
if ( V_74 ) {
F_2 ( V_16 L_11 ) ;
for ( V_1 = 0 ; V_1 < V_73 ; ++ V_1 )
F_2 ( L_12 , V_72 [ V_1 ] ) ;
F_2 ( L_13 , V_68 ) ;
}
F_39 ( & V_45 , V_53 ) ;
F_34 = V_10 [ V_68 ] . F_34 ;
if ( F_34 != NULL )
V_10 [ V_68 ] . V_71 = 1 ;
F_40 ( & V_45 , V_53 ) ;
if ( F_34 != NULL ) {
(* F_34)( V_72 , V_73 , V_27 ) ;
F_41 () ;
V_10 [ V_68 ] . V_71 = 0 ;
}
}
static int F_35 ( int V_75 , int V_76 )
{
struct V_5 V_6 ;
if ( V_10 [ V_75 ] . V_13 == V_76 )
return 1 ;
V_5 ( & V_6 , NULL , V_7 , 3 ,
F_42 ( V_75 , 3 ) , V_75 | 0x20 , V_76 ) ;
V_5 ( & V_6 , NULL , V_7 | V_8 , 1 ,
F_43 ( V_75 , 3 ) ) ;
if ( V_6 . V_9 < 2 )
return 0 ;
if ( V_6 . V_14 [ 2 ] != V_76 )
return 0 ;
V_10 [ V_75 ] . V_13 = V_6 . V_14 [ 2 ] ;
return 1 ;
}
int
F_44 ( int V_75 , int V_76 )
{
int V_41 ;
F_22 ( & V_44 ) ;
V_41 = F_35 ( V_75 , V_76 ) ;
F_25 ( & V_44 ) ;
return V_41 ;
}
int
F_45 ( int V_75 , int * V_11 , int * V_13 )
{
F_22 ( & V_44 ) ;
* V_11 = V_10 [ V_75 ] . V_11 ;
* V_13 = V_10 [ V_75 ] . V_13 ;
F_25 ( & V_44 ) ;
return ( * V_11 != 0 ) ;
}
static void F_46 ( struct V_5 * V_6 )
{
struct V_77 * V_24 = (struct V_77 * ) V_6 -> V_52 ;
unsigned long V_53 ;
if ( ! V_6 -> F_28 ) {
V_6 -> V_9 = 0 ;
V_6 -> F_28 = 1 ;
}
F_47 ( & V_24 -> V_78 , V_53 ) ;
F_48 ( & V_24 -> V_79 ) ;
if ( ! V_24 -> V_80 ) {
F_49 ( V_6 ) ;
if ( F_50 ( & V_24 -> V_79 ) == 0 ) {
F_51 ( & V_24 -> V_78 , V_53 ) ;
F_49 ( V_24 ) ;
return;
}
} else {
struct V_5 * * V_81 = & V_24 -> V_82 ;
while ( * V_81 != NULL )
V_81 = & ( * V_81 ) -> V_83 ;
V_6 -> V_83 = NULL ;
* V_81 = V_6 ;
F_52 ( & V_24 -> V_84 ) ;
}
F_51 ( & V_24 -> V_78 , V_53 ) ;
}
static int
F_53 ( struct V_5 * V_6 )
{
int V_41 = - V_58 ;
switch( V_6 -> V_60 [ 1 ] )
{
case V_85 :
if ( V_6 -> V_54 < 3 )
break;
F_22 ( & V_44 ) ;
V_6 -> V_14 [ 0 ] = V_10 [ V_6 -> V_60 [ 2 ] ] . V_11 ;
V_6 -> V_14 [ 1 ] = V_10 [ V_6 -> V_60 [ 2 ] ] . V_13 ;
F_25 ( & V_44 ) ;
V_6 -> F_28 = 1 ;
V_6 -> V_9 = 2 ;
F_46 ( V_6 ) ;
V_41 = 0 ;
break;
}
return V_41 ;
}
static int F_54 ( struct V_86 * V_86 , struct V_87 * V_87 )
{
struct V_77 * V_24 ;
int V_41 = 0 ;
F_22 ( & V_88 ) ;
if ( F_55 ( V_86 ) > 0 || V_26 == NULL ) {
V_41 = - V_42 ;
goto V_89;
}
V_24 = F_56 ( sizeof( struct V_77 ) , V_90 ) ;
if ( V_24 == 0 ) {
V_41 = - V_91 ;
goto V_89;
}
V_87 -> V_92 = V_24 ;
F_57 ( & V_24 -> V_78 ) ;
F_58 ( & V_24 -> V_79 , 0 ) ;
V_24 -> V_82 = NULL ;
F_59 ( & V_24 -> V_84 ) ;
V_24 -> V_80 = 1 ;
V_89:
F_25 ( & V_88 ) ;
return V_41 ;
}
static int F_60 ( struct V_86 * V_86 , struct V_87 * V_87 )
{
struct V_77 * V_24 = V_87 -> V_92 ;
unsigned long V_53 ;
F_22 ( & V_88 ) ;
if ( V_24 ) {
V_87 -> V_92 = NULL ;
F_47 ( & V_24 -> V_78 , V_53 ) ;
if ( F_50 ( & V_24 -> V_79 ) == 0
&& V_24 -> V_82 == NULL ) {
F_51 ( & V_24 -> V_78 , V_53 ) ;
F_49 ( V_24 ) ;
} else {
V_24 -> V_80 = 0 ;
F_51 ( & V_24 -> V_78 , V_53 ) ;
}
}
F_25 ( & V_88 ) ;
return 0 ;
}
static T_4 F_61 ( struct V_87 * V_87 , char T_5 * V_72 ,
T_6 V_93 , T_7 * V_94 )
{
int V_41 = 0 ;
struct V_77 * V_24 = V_87 -> V_92 ;
struct V_5 * V_6 ;
T_8 V_95 = F_62 ( V_95 , V_96 ) ;
unsigned long V_53 ;
if ( V_93 < 2 )
return - V_58 ;
if ( V_93 > sizeof( V_6 -> V_14 ) )
V_93 = sizeof( V_6 -> V_14 ) ;
if ( ! F_63 ( V_97 , V_72 , V_93 ) )
return - V_98 ;
V_6 = NULL ;
F_47 ( & V_24 -> V_78 , V_53 ) ;
F_64 ( & V_24 -> V_84 , & V_95 ) ;
F_65 ( V_99 ) ;
for (; ; ) {
V_6 = V_24 -> V_82 ;
if ( V_6 != NULL )
V_24 -> V_82 = V_6 -> V_83 ;
else if ( F_50 ( & V_24 -> V_79 ) == 0 )
V_41 = - V_100 ;
if ( V_6 != NULL || V_41 != 0 )
break;
if ( V_87 -> V_101 & V_102 ) {
V_41 = - V_103 ;
break;
}
if ( F_66 ( V_96 ) ) {
V_41 = - V_104 ;
break;
}
F_51 ( & V_24 -> V_78 , V_53 ) ;
F_67 () ;
F_47 ( & V_24 -> V_78 , V_53 ) ;
}
F_65 ( V_105 ) ;
F_68 ( & V_24 -> V_84 , & V_95 ) ;
F_51 ( & V_24 -> V_78 , V_53 ) ;
if ( V_41 )
return V_41 ;
V_41 = V_6 -> V_9 ;
if ( V_41 > V_93 )
V_41 = V_93 ;
if ( V_41 > 0 && F_69 ( V_72 , V_6 -> V_14 , V_41 ) )
V_41 = - V_98 ;
F_49 ( V_6 ) ;
return V_41 ;
}
static T_4 F_70 ( struct V_87 * V_87 , const char T_5 * V_72 ,
T_6 V_93 , T_7 * V_94 )
{
int V_41 ;
struct V_77 * V_24 = V_87 -> V_92 ;
struct V_5 * V_6 ;
if ( V_93 < 2 || V_93 > sizeof( V_6 -> V_60 ) )
return - V_58 ;
if ( V_26 == NULL )
return - V_42 ;
if ( ! F_63 ( V_106 , V_72 , V_93 ) )
return - V_98 ;
V_6 = F_56 ( sizeof( struct V_5 ) ,
V_90 ) ;
if ( V_6 == NULL )
return - V_91 ;
V_6 -> V_54 = V_93 ;
V_6 -> F_29 = F_46 ;
V_6 -> V_52 = ( void * ) V_24 ;
V_6 -> F_28 = 0 ;
V_41 = - V_98 ;
if ( F_71 ( V_6 -> V_60 , V_72 , V_93 ) )
goto V_89;
F_72 ( & V_24 -> V_79 ) ;
F_9 ( & V_17 ) ;
if ( V_6 -> V_60 [ 0 ] == V_107 ) {
if ( V_93 > 1 )
V_41 = F_53 ( V_6 ) ;
else
V_41 = - V_58 ;
F_5 ( & V_17 ) ;
}
else if ( ( V_6 -> V_60 [ 0 ] == V_61 ) && ( V_93 > 1 )
&& ( V_6 -> V_60 [ 1 ] == V_108 ) ) {
V_41 = F_4 () ;
F_5 ( & V_17 ) ;
F_48 ( & V_24 -> V_79 ) ;
if ( V_41 == 0 )
V_41 = V_93 ;
goto V_89;
} else {
V_6 -> V_59 = ( ( V_6 -> V_60 [ 1 ] & 0xc ) == 0xc ) ;
if ( V_26 && V_26 -> V_57 )
V_41 = V_26 -> V_57 ( V_6 , 0 ) ;
else
V_41 = - V_42 ;
F_5 ( & V_17 ) ;
}
if ( V_41 != 0 ) {
F_48 ( & V_24 -> V_79 ) ;
goto V_89;
}
return V_93 ;
V_89:
F_49 ( V_6 ) ;
return V_41 ;
}
static int T_2
F_73 ( struct V_22 * V_23 )
{
if ( V_23 == & V_109 )
return 0 ;
return - V_70 ;
}
static void T_2
F_20 ( void )
{
if ( F_74 ( V_110 , L_14 , & V_111 ) ) {
F_2 ( V_67 L_15 , V_110 ) ;
return;
}
V_112 = F_75 ( V_113 , L_14 ) ;
if ( F_76 ( V_112 ) )
return;
F_77 ( V_112 , NULL , F_78 ( V_110 , 0 ) , NULL , L_14 ) ;
F_79 ( & V_109 ) ;
F_80 ( & V_114 , F_73 ) ;
}
