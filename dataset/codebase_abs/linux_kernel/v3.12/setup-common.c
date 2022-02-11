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
const T_4 * V_53 ;
T_4 V_54 ;
int V_55 , V_56 ;
F_40 ( L_29 , V_50 -> V_57 ) ;
V_53 = F_16 ( V_50 , L_30 ,
& V_56 ) ;
if ( V_53 ) {
V_52 = V_56 / sizeof( int ) ;
F_40 ( L_31 ,
V_52 ) ;
} else {
F_40 ( L_32 ) ;
V_53 = F_16 ( V_50 , L_33 , NULL ) ;
if ( ! V_53 ) {
V_54 = F_49 ( V_51 ) ;
V_53 = & V_54 ;
}
}
for ( V_55 = 0 ; V_55 < V_52 && V_51 < V_38 ; V_55 ++ ) {
F_40 ( L_34 ,
V_55 , V_51 , F_50 ( V_53 [ V_55 ] ) ) ;
F_51 ( V_51 , true ) ;
F_52 ( V_51 , F_50 ( V_53 [ V_55 ] ) ) ;
F_53 ( V_51 , true ) ;
V_51 ++ ;
}
}
if ( ! F_24 ( V_58 ) ) {
F_40 ( L_35 ) ;
V_52 = 1 ;
}
#ifdef F_54
if ( F_55 ( V_59 ) && F_56 ( V_60 ) &&
( V_50 = F_15 ( L_36 ) ) ) {
int V_61 , V_62 , V_63 ;
const unsigned int * V_64 ;
V_61 = F_57 ( V_50 ) ;
V_62 = F_58 ( V_50 ) ;
V_64 = F_16 ( V_50 , L_37 , NULL ) ;
if ( ! V_64 )
goto V_65;
V_63 = V_64 [ V_61 + V_62 ] ;
if ( F_24 ( V_58 ) )
V_63 *= V_52 ;
if ( V_63 > V_38 ) {
F_7 ( V_66
L_38
L_39 ,
V_63 , V_38 ) ;
V_63 = V_38 ;
} else
F_7 ( V_48 L_40 ,
V_63 ) ;
for ( V_51 = 0 ; V_51 < V_63 ; V_51 ++ )
F_53 ( V_51 , true ) ;
V_65:
F_17 ( V_50 ) ;
}
V_67 -> V_68 = F_59 () ;
#endif
F_42 ( V_52 ) ;
F_60 () ;
F_61 () ;
}
static T_3 int F_62 ( void )
{
struct V_9 * V_69 ;
struct V_70 * V_71 ;
int V_72 ;
V_69 = F_63 ( NULL , NULL , L_41 ) ;
F_17 ( V_69 ) ;
if ( ! V_69 )
return - V_73 ;
V_71 = F_64 ( L_42 , - 1 ) ;
if ( ! V_71 )
return - V_74 ;
V_72 = F_65 ( V_71 ) ;
if ( V_72 )
F_66 ( V_71 ) ;
return V_72 ;
}
void F_67 ( void )
{
extern struct V_75 V_76 ;
extern struct V_75 V_77 ;
F_40 ( L_43 ) ;
for ( V_78 = & V_76 ;
V_78 < & V_77 ;
V_78 ++ ) {
F_40 ( L_44 , V_78 -> V_18 ) ;
memcpy ( & V_1 , V_78 , sizeof( struct V_75 ) ) ;
if ( V_1 . V_79 () ) {
F_40 ( L_45 ) ;
break;
}
F_40 ( L_14 ) ;
}
if ( V_78 >= & V_77 ) {
F_40 ( L_46 ) ;
for (; ; ) ;
}
F_7 ( V_48 L_47 , V_1 . V_18 ) ;
}
int F_68 ( unsigned long V_80 )
{
struct V_9 * V_81 , * V_69 = NULL ;
int V_72 = - V_73 ;
switch( V_80 ) {
case V_82 :
if ( ! ( V_69 = F_63 ( NULL , NULL , L_48 ) ) )
V_69 = F_63 ( NULL , NULL , L_49 ) ;
if ( V_69 ) {
V_81 = F_69 ( V_69 ) ;
V_83 = F_70 ( V_81 , 0 ) ;
if ( ! V_83 )
V_83 = 1 ;
V_84 = F_70 ( V_81 , 1 ) ;
if ( ! V_84 )
V_84 = 12 ;
F_17 ( V_69 ) ;
V_69 = V_81 ;
break;
}
V_69 = F_48 ( NULL , L_50 ) ;
if ( ! V_69 )
V_69 = F_71 ( NULL , L_50 ) ;
if ( V_69 ) {
V_83 = 1 ;
V_84 = 12 ;
}
break;
case V_85 :
V_69 = F_48 ( NULL , L_51 ) ;
break;
default:
break;
}
if ( ! V_69 )
return V_72 ;
V_81 = F_69 ( V_69 ) ;
if ( V_81 ) {
if ( strcmp ( V_81 -> type , L_52 ) == 0 )
V_72 = 0 ;
F_17 ( V_81 ) ;
}
F_17 ( V_69 ) ;
return V_72 ;
}
static int F_72 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_89 )
{
F_73 ( NULL , V_89 ) ;
V_1 . V_90 ( V_89 ) ;
return V_91 ;
}
void T_3 F_74 ( void )
{
F_75 ( & V_92 , & V_93 ) ;
}
static int T_3 F_76 ( void )
{
struct V_9 * V_69 ;
const void * V_94 ;
int V_95 ;
V_69 = F_15 ( L_5 ) ;
V_94 = F_16 ( V_69 , L_53 , NULL ) ;
F_17 ( V_69 ) ;
V_95 = V_94 ? 0 : 1 ;
if ( V_95 != V_96 ) {
F_7 ( V_97
L_54 ,
V_96 ? L_55 : L_56 ,
V_95 ? L_55 : L_56 ) ;
F_77 () ;
}
return 0 ;
}
static int F_78 ( void )
{
V_98 = F_79 ( L_57 , NULL ) ;
return V_98 == NULL ;
}
T_5 int T_3 F_80 ( char * V_99 )
{
if ( V_99 && strncmp ( V_99 , L_58 , 1 ) != 0 )
V_100 = 1 ;
return 0 ;
}
int T_3 F_81 ( char * V_99 )
{
unsigned long V_72 ;
if ( V_99 ) {
if ( ! F_82 ( V_99 , 0 , & V_72 ) )
V_101 = V_72 ;
}
return 0 ;
}
void F_83 ( char * V_102 , unsigned short V_103 )
{
F_84 ( L_59 , V_102 ) ;
}
void F_85 ( struct V_70 * V_104 )
{
V_104 -> V_105 . V_106 = F_86 ( 32 ) ;
V_104 -> V_107 . V_106 = & V_104 -> V_105 . V_106 ;
F_87 ( & V_104 -> V_107 , & V_108 ) ;
}
