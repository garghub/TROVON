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
unsigned long V_24 ;
unsigned short V_25 ;
unsigned short V_26 ;
F_18 () ;
if ( ! F_19 ( V_22 ) ) {
F_20 () ;
return 0 ;
}
#ifdef F_5
V_23 = F_21 ( V_27 , V_22 ) ;
#else
V_23 = F_22 ( V_28 ) ;
#endif
V_25 = ( V_23 >> 8 ) & 0xFF ;
V_26 = V_23 & 0xFF ;
F_14 ( V_8 , L_9 , V_22 ) ;
F_14 ( V_8 , L_10 ) ;
if ( V_29 -> V_30 )
F_14 ( V_8 , L_11 , V_29 -> V_31 ) ;
else
F_14 ( V_8 , L_12 , V_23 ) ;
#ifdef F_23
if ( F_24 ( V_32 ) )
F_14 ( V_8 , L_13 ) ;
#endif
F_14 ( V_8 , L_14 ) ;
#ifdef F_25
if ( V_29 -> V_33 & V_34 ) {
#ifdef F_26
F_14 ( V_8 , L_15 ,
F_27 ( V_22 ) ) ;
#else
T_1 V_35 ;
V_35 = F_28 ( V_22 ) ;
F_14 ( V_8 , L_16 ,
V_35 & 0xff , V_35 >> 16 ) ;
#endif
}
#endif
if ( V_1 . V_36 )
V_24 = V_1 . V_36 ( V_22 ) ;
else
V_24 = V_37 ;
if ( V_24 )
F_14 ( V_8 , L_17 ,
V_24 / 1000000 , V_24 % 1000000 ) ;
if ( V_1 . V_38 != NULL )
V_1 . V_38 ( V_8 , V_22 ) ;
if ( F_29 ( V_23 ) & 0x8000 ) {
switch ( F_29 ( V_23 ) ) {
case 0x8000 :
case 0x8001 :
case 0x8002 :
case 0x8003 :
case 0x8004 :
case 0x800c :
V_25 = ( ( V_23 >> 8 ) & 0xF ) ;
V_26 = F_30 ( V_23 ) ;
break;
default:
V_25 = F_31 ( V_23 ) ;
V_26 = F_30 ( V_23 ) ;
break;
}
} else {
switch ( F_29 ( V_23 ) ) {
case 0x0020 :
V_25 = F_31 ( V_23 ) + 1 ;
V_26 = F_30 ( V_23 ) ;
break;
case 0x1008 :
V_25 = ( ( V_23 >> 8 ) & 0xFF ) - 1 ;
V_26 = V_23 & 0xFF ;
break;
default:
V_25 = ( V_23 >> 8 ) & 0xFF ;
V_26 = V_23 & 0xFF ;
break;
}
}
F_14 ( V_8 , L_18 ,
V_25 , V_26 , F_29 ( V_23 ) , F_32 ( V_23 ) ) ;
#ifdef V_12
F_14 ( V_8 , L_19 ,
V_15 / ( 500000 / V_16 ) ,
( V_15 / ( 5000 / V_16 ) ) % 100 ) ;
#endif
#ifdef F_5
F_14 ( V_8 , L_14 ) ;
#endif
F_20 () ;
if ( F_33 ( V_22 , V_39 ) >= V_40 )
F_11 ( V_8 ) ;
return 0 ;
}
static void * F_34 ( struct V_7 * V_8 , T_2 * V_41 )
{
if ( * V_41 == 0 )
* V_41 = F_35 ( V_39 ) ;
else
* V_41 = F_33 ( * V_41 - 1 , V_39 ) ;
if ( ( * V_41 ) < V_40 )
return ( void * ) ( unsigned long ) ( * V_41 + 1 ) ;
return NULL ;
}
static void * F_36 ( struct V_7 * V_8 , void * V_21 , T_2 * V_41 )
{
( * V_41 ) ++ ;
return F_34 ( V_8 , V_41 ) ;
}
static void F_37 ( struct V_7 * V_8 , void * V_21 )
{
}
void T_3 F_38 ( void )
{
#ifdef F_39
F_40 ( L_20 ,
V_42 , V_43 ) ;
if ( F_41 ( V_42 ) && F_41 ( V_43 ) &&
V_43 > V_42 )
V_44 = V_45 ;
else
V_42 = V_43 = 0 ;
if ( V_42 )
F_42 ( L_21 , V_42 , V_43 ) ;
F_40 ( L_22 ) ;
#endif
}
static void T_3 F_43 ( int V_46 )
{
int V_14 ;
V_47 = V_46 ;
V_48 = V_46 ;
F_44 ( & V_49 ) ;
V_50 = F_45 ( V_46 ) ;
F_46 ( V_46 != ( 1 << V_50 ) ) ;
for ( V_14 = 0 ; V_14 < V_46 ; V_14 ++ )
F_47 ( V_14 , & V_49 ) ;
F_7 ( V_51 L_23 ,
V_46 , V_46 > 1 ? L_24 : L_25 ) ;
F_7 ( V_52 L_26 , V_50 ) ;
}
void T_3 F_48 ( void )
{
struct V_9 * V_53 = NULL ;
int V_54 = 0 ;
int V_55 = 1 ;
F_40 ( L_27 ) ;
while ( ( V_53 = F_49 ( V_53 , L_28 ) ) && V_54 < V_40 ) {
const T_4 * V_56 ;
T_4 V_57 ;
int V_58 , V_59 ;
F_40 ( L_29 , V_53 -> V_60 ) ;
V_56 = F_16 ( V_53 , L_30 ,
& V_59 ) ;
if ( V_56 ) {
F_40 ( L_31 ,
V_55 ) ;
} else {
F_40 ( L_32 ) ;
V_56 = F_16 ( V_53 , L_33 , & V_59 ) ;
if ( ! V_56 ) {
V_57 = F_50 ( V_54 ) ;
V_56 = & V_57 ;
V_59 = 4 ;
}
}
V_55 = V_59 / sizeof( int ) ;
for ( V_58 = 0 ; V_58 < V_55 && V_54 < V_40 ; V_58 ++ ) {
bool V_61 ;
F_40 ( L_34 ,
V_58 , V_54 , F_51 ( V_56 [ V_58 ] ) ) ;
V_61 = F_52 ( V_53 ) ;
if ( ! V_61 )
V_61 = ! F_53 ( V_53 ,
L_35 , L_36 ) ;
F_54 ( V_54 , V_61 ) ;
F_55 ( V_54 , F_51 ( V_56 [ V_58 ] ) ) ;
F_56 ( V_54 , true ) ;
V_54 ++ ;
}
}
if ( ! F_24 ( V_62 ) ) {
F_40 ( L_37 ) ;
V_55 = 1 ;
}
#ifdef F_57
if ( F_58 ( V_63 ) && F_59 ( V_64 ) &&
( V_53 = F_15 ( L_38 ) ) ) {
int V_65 , V_66 , V_67 ;
const T_4 * V_68 ;
V_65 = F_60 ( V_53 ) ;
V_66 = F_61 ( V_53 ) ;
V_68 = F_16 ( V_53 , L_39 , NULL ) ;
if ( ! V_68 )
goto V_69;
V_67 = F_62 ( V_68 + V_65 + V_66 ) ;
if ( F_24 ( V_62 ) )
V_67 *= V_55 ;
if ( V_67 > V_40 ) {
F_7 ( V_70
L_40
L_41 ,
V_67 , V_40 ) ;
V_67 = V_40 ;
} else
F_7 ( V_51 L_42 ,
V_67 ) ;
for ( V_54 = 0 ; V_54 < V_67 ; V_54 ++ )
F_56 ( V_54 , true ) ;
V_69:
F_17 ( V_53 ) ;
}
V_71 -> V_72 = F_63 () ;
#endif
F_43 ( V_55 ) ;
F_64 () ;
F_65 () ;
}
static T_3 int F_66 ( void )
{
struct V_9 * V_73 ;
struct V_74 * V_75 ;
int V_76 ;
V_73 = F_67 ( NULL , NULL , L_43 ) ;
F_17 ( V_73 ) ;
if ( ! V_73 )
return - V_77 ;
V_75 = F_68 ( L_44 , - 1 ) ;
if ( ! V_75 )
return - V_78 ;
V_76 = F_69 ( V_75 ) ;
if ( V_76 )
F_70 ( V_75 ) ;
return V_76 ;
}
void F_71 ( void )
{
extern struct V_79 V_80 ;
extern struct V_79 V_81 ;
F_40 ( L_45 ) ;
for ( V_82 = & V_80 ;
V_82 < & V_81 ;
V_82 ++ ) {
F_40 ( L_46 , V_82 -> V_18 ) ;
memcpy ( & V_1 , V_82 , sizeof( struct V_79 ) ) ;
if ( V_1 . V_83 () ) {
F_40 ( L_47 ) ;
break;
}
F_40 ( L_14 ) ;
}
if ( V_82 >= & V_81 ) {
F_40 ( L_48 ) ;
for (; ; ) ;
}
F_7 ( V_51 L_49 , V_1 . V_18 ) ;
}
int F_72 ( unsigned long V_84 )
{
struct V_9 * V_85 , * V_73 = NULL ;
int V_76 = - V_77 ;
switch( V_84 ) {
case V_86 :
if ( ! ( V_73 = F_67 ( NULL , NULL , L_50 ) ) )
V_73 = F_67 ( NULL , NULL , L_51 ) ;
if ( V_73 ) {
V_85 = F_73 ( V_73 ) ;
V_87 = F_74 ( V_85 , 0 ) ;
if ( ! V_87 )
V_87 = 1 ;
V_88 = F_74 ( V_85 , 1 ) ;
if ( ! V_88 )
V_88 = 12 ;
F_17 ( V_73 ) ;
V_73 = V_85 ;
break;
}
V_73 = F_49 ( NULL , L_52 ) ;
if ( ! V_73 )
V_73 = F_75 ( NULL , L_52 ) ;
if ( V_73 ) {
V_87 = 1 ;
V_88 = 12 ;
}
break;
case V_89 :
V_73 = F_49 ( NULL , L_53 ) ;
break;
default:
break;
}
if ( ! V_73 )
return V_76 ;
V_85 = F_73 ( V_73 ) ;
if ( V_85 ) {
if ( strcmp ( V_85 -> type , L_54 ) == 0 )
V_76 = 0 ;
F_17 ( V_85 ) ;
}
F_17 ( V_73 ) ;
return V_76 ;
}
static int F_76 ( struct V_90 * V_91 ,
unsigned long V_92 , void * V_93 )
{
F_77 ( NULL , V_93 ) ;
V_1 . V_94 ( V_93 ) ;
return V_95 ;
}
void T_3 F_78 ( void )
{
F_79 ( & V_96 , & V_97 ) ;
}
static int T_3 F_80 ( void )
{
struct V_9 * V_73 ;
const void * V_98 ;
int V_99 ;
V_73 = F_15 ( L_5 ) ;
V_98 = F_16 ( V_73 , L_55 , NULL ) ;
F_17 ( V_73 ) ;
V_99 = V_98 ? 0 : 1 ;
if ( V_99 != V_100 ) {
F_7 ( V_101
L_56 ,
V_100 ? L_57 : L_58 ,
V_99 ? L_57 : L_58 ) ;
F_81 () ;
}
return 0 ;
}
static int F_82 ( void )
{
V_102 = F_83 ( L_59 , NULL ) ;
return V_102 == NULL ;
}
void F_84 ( char * V_103 , unsigned short V_104 )
{
F_42 ( L_60 , V_103 ) ;
}
void F_85 ( struct V_74 * V_105 )
{
V_105 -> V_106 . V_107 = F_86 ( 32 ) ;
V_105 -> V_108 . V_107 = & V_105 -> V_106 . V_107 ;
F_87 ( & V_105 -> V_108 , & V_109 ) ;
}
