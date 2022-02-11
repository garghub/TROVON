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
} else {
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
static int F_13 ( struct V_30 * V_23 )
{
return F_11 ( F_14 ( V_23 ) , V_31 ) ;
}
static int F_15 ( struct V_30 * V_23 )
{
return F_11 ( F_14 ( V_23 ) , V_32 ) ;
}
static int F_16 ( struct V_30 * V_23 )
{
return F_11 ( F_14 ( V_23 ) , V_33 ) ;
}
static int F_17 ( struct V_22 * V_23 )
{
V_25 = 0 ;
F_5 ( & V_17 ) ;
F_8 () ;
return 0 ;
}
static int F_18 ( struct V_30 * V_23 )
{
return F_17 ( F_14 ( V_23 ) ) ;
}
static int T_2 F_19 ( void )
{
struct V_34 * V_35 ;
int V_1 ;
#ifdef F_20
if ( ! F_21 ( V_36 ) && ! F_21 ( V_37 ) )
return 0 ;
#endif
#ifdef F_22
if ( ! V_38 )
return 0 ;
#endif
if ( V_39 )
return 0 ;
V_39 = 1 ;
V_26 = NULL ;
V_1 = 0 ;
while ( ( V_35 = V_40 [ V_1 ++ ] ) != NULL ) {
if ( ! V_35 -> V_41 () ) {
V_26 = V_35 ;
break;
}
}
if ( V_26 != NULL && V_26 -> V_42 &&
V_26 -> V_42 () )
V_26 = NULL ;
if ( V_26 == NULL ) {
F_2 ( V_43 L_7 ) ;
} else {
#ifdef F_23
if ( F_24 ( L_8 ) ||
F_24 ( L_9 ) )
V_44 = 1 ;
#endif
F_25 () ;
F_8 () ;
}
return 0 ;
}
static int
F_4 ( void )
{
int V_45 ;
if ( V_26 == NULL )
return - V_46 ;
if ( V_26 -> V_27 )
V_26 -> V_27 ( 0 ) ;
F_12 ( & V_28 ,
V_47 , NULL ) ;
if ( V_44 ) {
F_26 ( 500 ) ;
}
F_27 ( & V_48 ) ;
F_28 ( & V_49 ) ;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
F_29 ( & V_49 ) ;
if ( V_26 -> V_50 )
V_45 = V_26 -> V_50 () ;
else
V_45 = 0 ;
if ( V_44 ) {
F_26 ( 1500 ) ;
}
if ( ! V_45 ) {
V_51 = F_1 () ;
if ( V_26 -> V_27 )
V_26 -> V_27 ( V_51 ) ;
}
F_30 ( & V_48 ) ;
F_12 ( & V_28 ,
V_52 , NULL ) ;
return V_45 ;
}
void
F_31 ( void )
{
if ( ( V_26 == NULL ) || ( V_26 -> V_53 == NULL ) )
return;
V_26 -> V_53 () ;
}
static void F_32 ( struct V_5 * V_6 )
{
struct V_54 * V_55 = V_6 -> V_56 ;
F_33 ( V_55 ) ;
}
int
V_5 ( struct V_5 * V_6 , void (* F_34)( struct V_5 * ) ,
int V_57 , int V_58 , ... )
{
T_3 V_59 ;
int V_1 ;
int V_60 ;
struct V_54 V_55 ;
if ( ( V_26 == NULL ) || ( V_26 -> V_61 == NULL ) )
return - V_46 ;
if ( V_58 < 1 )
return - V_62 ;
V_6 -> V_58 = V_58 + 1 ;
V_6 -> F_34 = F_34 ;
V_6 -> V_63 = V_57 & V_8 ;
V_6 -> V_64 [ 0 ] = V_65 ;
va_start ( V_59 , V_58 ) ;
for ( V_1 = 0 ; V_1 < V_58 ; ++ V_1 )
V_6 -> V_64 [ V_1 + 1 ] = va_arg ( V_59 , int ) ;
va_end ( V_59 ) ;
if ( V_57 & V_66 )
return 0 ;
if ( V_57 & V_7 ) {
F_35 ( F_34 ) ;
V_6 -> F_34 = F_32 ;
V_6 -> V_56 = & V_55 ;
F_36 ( & V_55 ) ;
}
V_60 = V_26 -> V_61 ( V_6 , 0 ) ;
if ( ( V_57 & V_7 ) && ! V_60 && ! V_6 -> F_33 )
F_37 ( & V_55 ) ;
return V_60 ;
}
int
F_38 ( int V_67 , int V_13 , struct V_68 * V_69 ,
void (* F_39)( unsigned char * , int , int ) )
{
int V_1 ;
F_27 ( & V_48 ) ;
V_69 -> V_70 = 0 ;
for ( V_1 = 1 ; V_1 < 16 ; V_1 ++ ) {
if ( ( V_10 [ V_1 ] . V_11 == V_67 ) &&
( ! V_13 || ( V_13 == V_10 [ V_1 ] . V_13 ) ||
F_40 ( V_1 , V_13 ) ) ) {
if ( V_10 [ V_1 ] . F_39 != 0 ) {
F_2 ( V_71
L_10 ,
V_67 ) ;
continue;
}
F_28 ( & V_49 ) ;
V_10 [ V_1 ] . F_39 = F_39 ;
F_29 ( & V_49 ) ;
V_69 -> V_72 [ V_69 -> V_70 ++ ] = V_1 ;
}
}
F_30 ( & V_48 ) ;
return V_69 -> V_70 ;
}
int
F_41 ( int V_73 )
{
int V_45 = - V_74 ;
F_27 ( & V_48 ) ;
F_28 ( & V_49 ) ;
if ( V_10 [ V_73 ] . F_39 ) {
while( V_10 [ V_73 ] . V_75 ) {
F_29 ( & V_49 ) ;
F_42 () ;
F_28 ( & V_49 ) ;
}
V_45 = 0 ;
V_10 [ V_73 ] . F_39 = NULL ;
}
F_29 ( & V_49 ) ;
F_30 ( & V_48 ) ;
return V_45 ;
}
void
F_43 ( unsigned char * V_76 , int V_77 , int V_27 )
{
int V_1 , V_72 ;
static int V_78 ;
unsigned long V_57 ;
void (* F_39)( unsigned char * , int , int );
if ( V_25 )
return;
V_72 = V_76 [ 0 ] >> 4 ;
if ( V_78 ) {
F_2 ( V_16 L_11 ) ;
for ( V_1 = 0 ; V_1 < V_77 ; ++ V_1 )
F_2 ( L_12 , V_76 [ V_1 ] ) ;
F_2 ( L_13 , V_72 ) ;
}
F_44 ( & V_49 , V_57 ) ;
F_39 = V_10 [ V_72 ] . F_39 ;
if ( F_39 != NULL )
V_10 [ V_72 ] . V_75 = 1 ;
F_45 ( & V_49 , V_57 ) ;
if ( F_39 != NULL ) {
(* F_39)( V_76 , V_77 , V_27 ) ;
F_46 () ;
V_10 [ V_72 ] . V_75 = 0 ;
}
}
static int F_40 ( int V_79 , int V_80 )
{
struct V_5 V_6 ;
if ( V_10 [ V_79 ] . V_13 == V_80 )
return 1 ;
V_5 ( & V_6 , NULL , V_7 , 3 ,
F_47 ( V_79 , 3 ) , V_79 | 0x20 , V_80 ) ;
V_5 ( & V_6 , NULL , V_7 | V_8 , 1 ,
F_48 ( V_79 , 3 ) ) ;
if ( V_6 . V_9 < 2 )
return 0 ;
if ( V_6 . V_14 [ 2 ] != V_80 )
return 0 ;
V_10 [ V_79 ] . V_13 = V_6 . V_14 [ 2 ] ;
return 1 ;
}
int
F_49 ( int V_79 , int V_80 )
{
int V_45 ;
F_27 ( & V_48 ) ;
V_45 = F_40 ( V_79 , V_80 ) ;
F_30 ( & V_48 ) ;
return V_45 ;
}
int
F_50 ( int V_79 , int * V_11 , int * V_13 )
{
F_27 ( & V_48 ) ;
* V_11 = V_10 [ V_79 ] . V_11 ;
* V_13 = V_10 [ V_79 ] . V_13 ;
F_30 ( & V_48 ) ;
return ( * V_11 != 0 ) ;
}
static void F_51 ( struct V_5 * V_6 )
{
struct V_81 * V_24 = (struct V_81 * ) V_6 -> V_56 ;
unsigned long V_57 ;
if ( ! V_6 -> F_33 ) {
V_6 -> V_9 = 0 ;
V_6 -> F_33 = 1 ;
}
F_52 ( & V_24 -> V_82 , V_57 ) ;
F_53 ( & V_24 -> V_83 ) ;
if ( ! V_24 -> V_84 ) {
F_54 ( V_6 ) ;
if ( F_55 ( & V_24 -> V_83 ) == 0 ) {
F_56 ( & V_24 -> V_82 , V_57 ) ;
F_54 ( V_24 ) ;
return;
}
} else {
struct V_5 * * V_85 = & V_24 -> V_86 ;
while ( * V_85 != NULL )
V_85 = & ( * V_85 ) -> V_87 ;
V_6 -> V_87 = NULL ;
* V_85 = V_6 ;
F_57 ( & V_24 -> V_88 ) ;
}
F_56 ( & V_24 -> V_82 , V_57 ) ;
}
static int
F_58 ( struct V_5 * V_6 )
{
int V_45 = - V_62 ;
switch( V_6 -> V_64 [ 1 ] ) {
case V_89 :
if ( V_6 -> V_58 < 3 )
break;
F_27 ( & V_48 ) ;
V_6 -> V_14 [ 0 ] = V_10 [ V_6 -> V_64 [ 2 ] ] . V_11 ;
V_6 -> V_14 [ 1 ] = V_10 [ V_6 -> V_64 [ 2 ] ] . V_13 ;
F_30 ( & V_48 ) ;
V_6 -> F_33 = 1 ;
V_6 -> V_9 = 2 ;
F_51 ( V_6 ) ;
V_45 = 0 ;
break;
}
return V_45 ;
}
static int F_59 ( struct V_90 * V_90 , struct V_91 * V_91 )
{
struct V_81 * V_24 ;
int V_45 = 0 ;
F_27 ( & V_92 ) ;
if ( F_60 ( V_90 ) > 0 || V_26 == NULL ) {
V_45 = - V_46 ;
goto V_93;
}
V_24 = F_61 ( sizeof( struct V_81 ) , V_94 ) ;
if ( V_24 == 0 ) {
V_45 = - V_95 ;
goto V_93;
}
V_91 -> V_96 = V_24 ;
F_62 ( & V_24 -> V_82 ) ;
F_63 ( & V_24 -> V_83 , 0 ) ;
V_24 -> V_86 = NULL ;
F_64 ( & V_24 -> V_88 ) ;
V_24 -> V_84 = 1 ;
V_93:
F_30 ( & V_92 ) ;
return V_45 ;
}
static int F_65 ( struct V_90 * V_90 , struct V_91 * V_91 )
{
struct V_81 * V_24 = V_91 -> V_96 ;
unsigned long V_57 ;
F_27 ( & V_92 ) ;
if ( V_24 ) {
V_91 -> V_96 = NULL ;
F_52 ( & V_24 -> V_82 , V_57 ) ;
if ( F_55 ( & V_24 -> V_83 ) == 0
&& V_24 -> V_86 == NULL ) {
F_56 ( & V_24 -> V_82 , V_57 ) ;
F_54 ( V_24 ) ;
} else {
V_24 -> V_84 = 0 ;
F_56 ( & V_24 -> V_82 , V_57 ) ;
}
}
F_30 ( & V_92 ) ;
return 0 ;
}
static T_4 F_66 ( struct V_91 * V_91 , char T_5 * V_76 ,
T_6 V_97 , T_7 * V_98 )
{
int V_45 = 0 ;
struct V_81 * V_24 = V_91 -> V_96 ;
struct V_5 * V_6 ;
F_67 ( V_99 , V_100 ) ;
unsigned long V_57 ;
if ( V_97 < 2 )
return - V_62 ;
if ( V_97 > sizeof( V_6 -> V_14 ) )
V_97 = sizeof( V_6 -> V_14 ) ;
V_6 = NULL ;
F_52 ( & V_24 -> V_82 , V_57 ) ;
F_68 ( & V_24 -> V_88 , & V_99 ) ;
F_69 ( V_101 ) ;
for (; ; ) {
V_6 = V_24 -> V_86 ;
if ( V_6 != NULL )
V_24 -> V_86 = V_6 -> V_87 ;
else if ( F_55 ( & V_24 -> V_83 ) == 0 )
V_45 = - V_102 ;
if ( V_6 != NULL || V_45 != 0 )
break;
if ( V_91 -> V_103 & V_104 ) {
V_45 = - V_105 ;
break;
}
if ( F_70 ( V_100 ) ) {
V_45 = - V_106 ;
break;
}
F_56 ( & V_24 -> V_82 , V_57 ) ;
F_71 () ;
F_52 ( & V_24 -> V_82 , V_57 ) ;
}
F_69 ( V_107 ) ;
F_72 ( & V_24 -> V_88 , & V_99 ) ;
F_56 ( & V_24 -> V_82 , V_57 ) ;
if ( V_45 )
return V_45 ;
V_45 = V_6 -> V_9 ;
if ( V_45 > V_97 )
V_45 = V_97 ;
if ( V_45 > 0 && F_73 ( V_76 , V_6 -> V_14 , V_45 ) )
V_45 = - V_108 ;
F_54 ( V_6 ) ;
return V_45 ;
}
static T_4 F_74 ( struct V_91 * V_91 , const char T_5 * V_76 ,
T_6 V_97 , T_7 * V_98 )
{
int V_45 ;
struct V_81 * V_24 = V_91 -> V_96 ;
struct V_5 * V_6 ;
if ( V_97 < 2 || V_97 > sizeof( V_6 -> V_64 ) )
return - V_62 ;
if ( V_26 == NULL )
return - V_46 ;
V_6 = F_61 ( sizeof( struct V_5 ) ,
V_94 ) ;
if ( V_6 == NULL )
return - V_95 ;
V_6 -> V_58 = V_97 ;
V_6 -> F_34 = F_51 ;
V_6 -> V_56 = ( void * ) V_24 ;
V_6 -> F_33 = 0 ;
V_45 = - V_108 ;
if ( F_75 ( V_6 -> V_64 , V_76 , V_97 ) )
goto V_93;
F_76 ( & V_24 -> V_83 ) ;
F_9 ( & V_17 ) ;
if ( V_6 -> V_64 [ 0 ] == V_109 ) {
if ( V_97 > 1 )
V_45 = F_58 ( V_6 ) ;
else
V_45 = - V_62 ;
F_5 ( & V_17 ) ;
}
else if ( ( V_6 -> V_64 [ 0 ] == V_65 ) && ( V_97 > 1 )
&& ( V_6 -> V_64 [ 1 ] == V_110 ) ) {
V_45 = F_4 () ;
F_5 ( & V_17 ) ;
F_53 ( & V_24 -> V_83 ) ;
if ( V_45 == 0 )
V_45 = V_97 ;
goto V_93;
} else {
V_6 -> V_63 = ( ( V_6 -> V_64 [ 1 ] & 0xc ) == 0xc ) ;
if ( V_26 && V_26 -> V_61 )
V_45 = V_26 -> V_61 ( V_6 , 0 ) ;
else
V_45 = - V_46 ;
F_5 ( & V_17 ) ;
}
if ( V_45 != 0 ) {
F_53 ( & V_24 -> V_83 ) ;
goto V_93;
}
return V_97 ;
V_93:
F_54 ( V_6 ) ;
return V_45 ;
}
static int T_2
F_77 ( struct V_22 * V_23 )
{
if ( V_23 == & V_111 )
return 0 ;
return - V_74 ;
}
static void T_2
F_25 ( void )
{
if ( F_78 ( V_112 , L_14 , & V_113 ) ) {
F_2 ( V_71 L_15 , V_112 ) ;
return;
}
V_114 = F_79 ( V_115 , L_14 ) ;
if ( F_80 ( V_114 ) )
return;
F_81 ( V_114 , NULL , F_82 ( V_112 , 0 ) , NULL , L_14 ) ;
F_83 ( & V_111 ) ;
F_84 ( & V_116 , F_77 ) ;
}
