void F_1 ( void )
{
#ifdef F_2
F_3 () ;
#endif
if ( V_1 . F_1 )
V_1 . F_1 () ;
}
void F_4 ( char * V_2 )
{
F_1 () ;
if ( V_1 . V_3 )
V_1 . V_3 ( V_2 ) ;
#ifdef F_5
F_6 () ;
#endif
F_7 ( V_4 L_1 ) ;
F_8 () ;
while ( 1 ) ;
}
void F_9 ( void )
{
F_1 () ;
if ( V_1 . V_5 )
V_1 . V_5 () ;
#ifdef F_5
F_6 () ;
#endif
F_7 ( V_4 L_1 ) ;
F_8 () ;
while ( 1 ) ;
}
void F_10 ( void )
{
F_1 () ;
if ( V_1 . V_6 )
V_1 . V_6 () ;
#ifdef F_5
F_6 () ;
#endif
F_7 ( V_4 L_1 ) ;
F_8 () ;
while ( 1 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
const char * V_11 = NULL ;
#if F_12 ( F_5 ) && F_12 ( V_12 )
unsigned long V_13 = 0 ;
int V_14 ;
F_13 (i)
V_13 += V_15 ;
F_14 ( V_8 , L_2 ,
V_13 / ( 500000 / V_16 ) , V_13 / ( 5000 / V_16 ) % 100 ) ;
#endif
F_14 ( V_8 , L_3 , V_17 ) ;
if ( V_1 . V_18 )
F_14 ( V_8 , L_4 , V_1 . V_18 ) ;
V_10 = F_15 ( L_5 ) ;
if ( V_10 )
V_11 = F_16 ( V_10 , L_6 , NULL ) ;
if ( V_11 )
F_14 ( V_8 , L_7 , V_11 ) ;
F_17 ( V_10 ) ;
if ( V_1 . V_19 != NULL )
V_1 . V_19 ( V_8 ) ;
#ifdef V_12
F_14 ( V_8 , L_8 ,
( unsigned int ) ( V_20 / ( 1024 * 1024 ) ) ) ;
#endif
}
static int V_19 ( struct V_7 * V_8 , void * V_21 )
{
unsigned long V_22 = ( unsigned long ) V_21 - 1 ;
unsigned int V_23 ;
unsigned short V_24 ;
unsigned short V_25 ;
F_18 () ;
if ( ! F_19 ( V_22 ) ) {
F_20 () ;
return 0 ;
}
#ifdef F_5
V_23 = F_21 ( V_26 , V_22 ) ;
#else
V_23 = F_22 ( V_27 ) ;
#endif
V_24 = ( V_23 >> 8 ) & 0xFF ;
V_25 = V_23 & 0xFF ;
F_14 ( V_8 , L_9 , V_22 ) ;
F_14 ( V_8 , L_10 ) ;
if ( V_28 -> V_29 )
F_14 ( V_8 , L_11 , V_28 -> V_30 ) ;
else
F_14 ( V_8 , L_12 , V_23 ) ;
#ifdef F_23
if ( F_24 ( V_31 ) )
F_14 ( V_8 , L_13 ) ;
#endif
F_14 ( V_8 , L_14 ) ;
#ifdef F_25
if ( V_28 -> V_32 & V_33 ) {
#ifdef F_26
F_14 ( V_8 , L_15 ,
F_27 ( V_22 ) ) ;
#else
T_1 V_34 ;
V_34 = F_28 ( V_22 ) ;
F_14 ( V_8 , L_16 ,
V_34 & 0xff , V_34 >> 16 ) ;
#endif
}
#endif
if ( V_35 )
F_14 ( V_8 , L_17 ,
V_35 / 1000000 , V_35 % 1000000 ) ;
if ( V_1 . V_36 != NULL )
V_1 . V_36 ( V_8 , V_22 ) ;
if ( F_29 ( V_23 ) & 0x8000 ) {
switch ( F_29 ( V_23 ) ) {
case 0x8000 :
case 0x8001 :
case 0x8002 :
case 0x8003 :
case 0x8004 :
case 0x800c :
V_24 = ( ( V_23 >> 8 ) & 0xF ) ;
V_25 = F_30 ( V_23 ) ;
break;
default:
V_24 = F_31 ( V_23 ) ;
V_25 = F_30 ( V_23 ) ;
break;
}
} else {
switch ( F_29 ( V_23 ) ) {
case 0x0020 :
V_24 = F_31 ( V_23 ) + 1 ;
V_25 = F_30 ( V_23 ) ;
break;
case 0x1008 :
V_24 = ( ( V_23 >> 8 ) & 0xFF ) - 1 ;
V_25 = V_23 & 0xFF ;
break;
default:
V_24 = ( V_23 >> 8 ) & 0xFF ;
V_25 = V_23 & 0xFF ;
break;
}
}
F_14 ( V_8 , L_18 ,
V_24 , V_25 , F_29 ( V_23 ) , F_32 ( V_23 ) ) ;
#ifdef V_12
F_14 ( V_8 , L_19 ,
V_15 / ( 500000 / V_16 ) ,
( V_15 / ( 5000 / V_16 ) ) % 100 ) ;
#endif
#ifdef F_5
F_14 ( V_8 , L_14 ) ;
#endif
F_20 () ;
if ( F_33 ( V_22 , V_37 ) >= V_38 )
F_11 ( V_8 ) ;
return 0 ;
}
static void * F_34 ( struct V_7 * V_8 , T_2 * V_39 )
{
if ( * V_39 == 0 )
* V_39 = F_35 ( V_37 ) ;
else
* V_39 = F_33 ( * V_39 - 1 , V_37 ) ;
if ( ( * V_39 ) < V_38 )
return ( void * ) ( unsigned long ) ( * V_39 + 1 ) ;
return NULL ;
}
static void * F_36 ( struct V_7 * V_8 , void * V_21 , T_2 * V_39 )
{
( * V_39 ) ++ ;
return F_34 ( V_8 , V_39 ) ;
}
static void F_37 ( struct V_7 * V_8 , void * V_21 )
{
}
void T_3 F_38 ( void )
{
#ifdef F_39
F_40 ( L_20 ,
V_40 , V_41 ) ;
if ( F_41 ( V_40 ) && F_41 ( V_41 ) &&
V_41 > V_40 )
V_42 = V_43 ;
else
V_40 = V_41 = 0 ;
if ( V_40 )
F_7 ( L_21 , V_40 , V_41 ) ;
F_40 ( L_22 ) ;
#endif
}
static void T_3 F_42 ( int V_44 )
{
int V_14 ;
V_45 = V_44 ;
F_43 ( & V_46 ) ;
V_47 = F_44 ( V_44 ) ;
F_45 ( V_44 != ( 1 << V_47 ) ) ;
for ( V_14 = 0 ; V_14 < V_44 ; V_14 ++ )
F_46 ( V_14 , & V_46 ) ;
F_7 ( V_48 L_23 ,
V_44 , V_44 > 1 ? L_24 : L_25 ) ;
F_7 ( V_49 L_26 , V_47 ) ;
}
void T_3 F_47 ( void )
{
struct V_9 * V_50 = NULL ;
int V_51 = 0 ;
int V_52 = 1 ;
F_40 ( L_27 ) ;
while ( ( V_50 = F_48 ( V_50 , L_28 ) ) && V_51 < V_38 ) {
const int * V_53 ;
int V_54 , V_55 ;
F_40 ( L_29 , V_50 -> V_56 ) ;
V_53 = F_16 ( V_50 , L_30 ,
& V_55 ) ;
if ( V_53 ) {
V_52 = V_55 / sizeof( int ) ;
F_40 ( L_31 ,
V_52 ) ;
} else {
F_40 ( L_32 ) ;
V_53 = F_16 ( V_50 , L_33 , NULL ) ;
if ( ! V_53 )
V_53 = & V_51 ;
}
for ( V_54 = 0 ; V_54 < V_52 && V_51 < V_38 ; V_54 ++ ) {
F_40 ( L_34 ,
V_54 , V_51 , V_53 [ V_54 ] ) ;
F_49 ( V_51 , true ) ;
F_50 ( V_51 , V_53 [ V_54 ] ) ;
F_51 ( V_51 , true ) ;
V_51 ++ ;
}
}
if ( ! F_24 ( V_57 ) ) {
F_40 ( L_35 ) ;
V_52 = 1 ;
}
#ifdef F_52
if ( F_53 ( V_58 ) && F_54 ( V_59 ) &&
( V_50 = F_15 ( L_36 ) ) ) {
int V_60 , V_61 , V_62 ;
const unsigned int * V_63 ;
V_60 = F_55 ( V_50 ) ;
V_61 = F_56 ( V_50 ) ;
V_63 = F_16 ( V_50 , L_37 , NULL ) ;
if ( ! V_63 )
goto V_64;
V_62 = V_63 [ V_60 + V_61 ] ;
if ( F_24 ( V_57 ) )
V_62 *= V_52 ;
if ( V_62 > V_38 ) {
F_7 ( V_65
L_38
L_39 ,
V_62 , V_38 ) ;
V_62 = V_38 ;
} else
F_7 ( V_48 L_40 ,
V_62 ) ;
for ( V_51 = 0 ; V_51 < V_62 ; V_51 ++ )
F_51 ( V_51 , true ) ;
V_64:
F_17 ( V_50 ) ;
}
V_66 -> V_67 = F_57 () ;
#endif
F_42 ( V_52 ) ;
F_58 () ;
F_59 () ;
}
static T_3 int F_60 ( void )
{
struct V_9 * V_68 ;
struct V_69 * V_70 ;
int V_71 ;
V_68 = F_61 ( NULL , NULL , L_41 ) ;
F_17 ( V_68 ) ;
if ( ! V_68 )
return - V_72 ;
V_70 = F_62 ( L_42 , - 1 ) ;
if ( ! V_70 )
return - V_73 ;
V_71 = F_63 ( V_70 ) ;
if ( V_71 )
F_64 ( V_70 ) ;
return V_71 ;
}
void F_65 ( void )
{
extern struct V_74 V_75 ;
extern struct V_74 V_76 ;
F_40 ( L_43 ) ;
for ( V_77 = & V_75 ;
V_77 < & V_76 ;
V_77 ++ ) {
F_40 ( L_44 , V_77 -> V_18 ) ;
memcpy ( & V_1 , V_77 , sizeof( struct V_74 ) ) ;
if ( V_1 . V_78 () ) {
F_40 ( L_45 ) ;
break;
}
F_40 ( L_14 ) ;
}
if ( V_77 >= & V_76 ) {
F_40 ( L_46 ) ;
for (; ; ) ;
}
F_7 ( V_48 L_47 , V_1 . V_18 ) ;
}
int F_66 ( unsigned long V_79 )
{
struct V_9 * V_80 , * V_68 = NULL ;
int V_71 = - V_72 ;
switch( V_79 ) {
case V_81 :
if ( ! ( V_68 = F_61 ( NULL , NULL , L_48 ) ) )
V_68 = F_61 ( NULL , NULL , L_49 ) ;
if ( V_68 ) {
V_80 = F_67 ( V_68 ) ;
V_82 = F_68 ( V_80 , 0 ) ;
if ( ! V_82 )
V_82 = 1 ;
V_83 = F_68 ( V_80 , 1 ) ;
if ( ! V_83 )
V_83 = 12 ;
F_17 ( V_68 ) ;
V_68 = V_80 ;
break;
}
V_68 = F_48 ( NULL , L_50 ) ;
if ( ! V_68 )
V_68 = F_69 ( NULL , L_50 ) ;
if ( V_68 ) {
V_82 = 1 ;
V_83 = 12 ;
}
break;
case V_84 :
V_68 = F_48 ( NULL , L_51 ) ;
break;
#ifdef F_70
case V_85 :
case V_86 :
case V_87 :
#endif
default:
break;
}
if ( ! V_68 )
return V_71 ;
V_80 = F_67 ( V_68 ) ;
if ( V_80 ) {
if ( strcmp ( V_80 -> type , L_52 ) == 0 )
V_71 = 0 ;
F_17 ( V_80 ) ;
}
F_17 ( V_68 ) ;
return V_71 ;
}
static int F_71 ( struct V_88 * V_89 ,
unsigned long V_90 , void * V_91 )
{
F_72 ( NULL , V_91 ) ;
V_1 . V_92 ( V_91 ) ;
return V_93 ;
}
void T_3 F_73 ( void )
{
F_74 ( & V_94 , & V_95 ) ;
}
static int T_3 F_75 ( void )
{
struct V_9 * V_68 ;
const void * V_96 ;
int V_97 ;
V_68 = F_15 ( L_5 ) ;
V_96 = F_16 ( V_68 , L_53 , NULL ) ;
F_17 ( V_68 ) ;
V_97 = V_96 ? 0 : 1 ;
if ( V_97 != V_98 ) {
F_7 ( V_99
L_54 ,
V_98 ? L_55 : L_56 ,
V_97 ? L_55 : L_56 ) ;
F_76 () ;
}
return 0 ;
}
static int F_77 ( void )
{
V_100 = F_78 ( L_57 , NULL ) ;
return V_100 == NULL ;
}
void F_79 ( char * V_101 , unsigned short V_102 )
{
F_80 ( L_58 , V_101 ) ;
}
void F_81 ( struct V_69 * V_103 )
{
V_103 -> V_104 . V_105 = F_82 ( 32 ) ;
V_103 -> V_106 . V_105 = & V_103 -> V_104 . V_105 ;
F_83 ( & V_103 -> V_106 , & V_107 ) ;
}
