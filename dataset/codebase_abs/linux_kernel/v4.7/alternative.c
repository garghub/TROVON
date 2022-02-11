static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 1 ;
}
static int T_1 F_2 ( char * V_1 )
{
V_3 = 1 ;
return 1 ;
}
static int T_1 F_3 ( char * V_1 )
{
V_4 = 1 ;
return 1 ;
}
void T_1 F_4 ( void )
{
switch ( V_5 . V_6 ) {
case V_7 :
if ( V_5 . V_8 == 6 &&
V_5 . V_9 >= 0x0f &&
V_5 . V_9 != 0x1c &&
V_5 . V_9 != 0x26 &&
V_5 . V_9 != 0x27 &&
V_5 . V_9 < 0x30 ) {
V_10 = V_11 ;
} else if ( F_5 ( V_12 ) ) {
V_10 = V_13 ;
} else {
#ifdef F_6
V_10 = V_11 ;
#else
V_10 = V_14 ;
#endif
}
break;
case V_15 :
if ( V_5 . V_8 > 0xf ) {
V_10 = V_13 ;
return;
}
default:
#ifdef F_6
V_10 = V_11 ;
#else
if ( F_5 ( V_16 ) )
V_10 = V_11 ;
else if ( F_5 ( V_17 ) )
V_10 = V_18 ;
else
V_10 = V_14 ;
#endif
}
}
static void T_2 F_7 ( void * V_19 , unsigned int V_20 )
{
while ( V_20 > 0 ) {
unsigned int V_21 = V_20 ;
if ( V_21 > V_22 )
V_21 = V_22 ;
memcpy ( V_19 , V_10 [ V_21 ] , V_21 ) ;
V_19 += V_21 ;
V_20 -= V_21 ;
}
}
static inline bool F_8 ( const T_3 V_23 )
{
return V_23 == 0xeb || V_23 == 0xe9 ;
}
static void T_2
F_9 ( struct V_24 * V_25 , T_3 * V_26 , T_3 * V_27 , T_3 * V_28 )
{
T_3 * V_29 , * V_30 ;
T_4 V_31 , V_32 ;
int V_33 ;
if ( V_25 -> V_34 != 5 )
return;
V_32 = * ( T_4 * ) ( V_28 + 1 ) ;
V_29 = V_27 + V_25 -> V_34 ;
V_30 = V_29 + V_32 ;
V_31 = V_30 - V_26 ;
F_10 ( L_1 , V_30 , V_31 ) ;
if ( V_30 - V_26 >= 0 ) {
if ( V_31 - 2 <= 127 )
goto V_35;
else
goto V_36;
} else {
if ( ( ( V_31 - 2 ) & 0xff ) == ( V_31 - 2 ) )
goto V_35;
else
goto V_36;
}
V_35:
V_31 -= 2 ;
V_28 [ 0 ] = 0xeb ;
V_28 [ 1 ] = ( V_37 ) V_31 ;
F_7 ( V_28 + 2 , 3 ) ;
V_33 = 2 ;
goto V_38;
V_36:
V_31 -= 5 ;
V_28 [ 0 ] = 0xe9 ;
* ( T_4 * ) & V_28 [ 1 ] = V_31 ;
V_33 = 5 ;
V_38:
F_10 ( L_2 ,
V_31 , ( unsigned long ) V_26 + V_31 + V_33 ) ;
}
static void T_2 F_11 ( struct V_24 * V_25 , T_3 * V_39 )
{
unsigned long V_40 ;
if ( V_39 [ 0 ] != 0x90 )
return;
F_12 ( V_40 ) ;
F_7 ( V_39 + ( V_25 -> V_41 - V_25 -> V_42 ) , V_25 -> V_42 ) ;
F_13 () ;
F_14 ( V_40 ) ;
F_15 ( V_39 , V_25 -> V_41 , L_3 ,
V_39 , V_25 -> V_41 - V_25 -> V_42 , V_25 -> V_42 ) ;
}
void T_2 F_16 ( struct V_24 * V_43 ,
struct V_24 * V_44 )
{
struct V_24 * V_25 ;
T_3 * V_39 , * V_45 ;
T_3 V_28 [ V_46 ] ;
F_10 ( L_4 , V_43 , V_44 ) ;
for ( V_25 = V_43 ; V_25 < V_44 ; V_25 ++ ) {
int V_47 = 0 ;
V_39 = ( T_3 * ) & V_25 -> V_48 + V_25 -> V_48 ;
V_45 = ( T_3 * ) & V_25 -> V_49 + V_25 -> V_49 ;
F_17 ( V_25 -> V_41 > sizeof( V_28 ) ) ;
F_17 ( V_25 -> V_50 >= ( V_51 + V_52 ) * 32 ) ;
if ( ! F_5 ( V_25 -> V_50 ) ) {
if ( V_25 -> V_42 > 1 )
F_11 ( V_25 , V_39 ) ;
continue;
}
F_10 ( L_5 ,
V_25 -> V_50 >> 5 ,
V_25 -> V_50 & 0x1f ,
V_39 , V_25 -> V_41 ,
V_45 , V_25 -> V_34 , V_25 -> V_42 ) ;
F_15 ( V_39 , V_25 -> V_41 , L_6 , V_39 ) ;
F_15 ( V_45 , V_25 -> V_34 , L_7 , V_45 ) ;
memcpy ( V_28 , V_45 , V_25 -> V_34 ) ;
V_47 = V_25 -> V_34 ;
if ( * V_28 == 0xe8 && V_25 -> V_34 == 5 ) {
* ( T_4 * ) ( V_28 + 1 ) += V_45 - V_39 ;
F_10 ( L_8 ,
* ( T_4 * ) ( V_28 + 1 ) ,
( unsigned long ) V_39 + * ( T_4 * ) ( V_28 + 1 ) + 5 ) ;
}
if ( V_25 -> V_34 && F_8 ( V_45 [ 0 ] ) )
F_9 ( V_25 , V_39 , V_45 , V_28 ) ;
if ( V_25 -> V_41 > V_25 -> V_34 ) {
F_7 ( V_28 + V_25 -> V_34 ,
V_25 -> V_41 - V_25 -> V_34 ) ;
V_47 += V_25 -> V_41 - V_25 -> V_34 ;
}
F_15 ( V_28 , V_47 , L_9 , V_39 ) ;
F_18 ( V_39 , V_28 , V_47 ) ;
}
}
static void F_19 ( const T_4 * V_43 , const T_4 * V_44 ,
T_3 * V_53 , T_3 * V_54 )
{
const T_4 * V_55 ;
F_20 ( & V_56 ) ;
for ( V_55 = V_43 ; V_55 < V_44 ; V_55 ++ ) {
T_3 * V_57 = ( T_3 * ) V_55 + * V_55 ;
if ( ! * V_55 || V_57 < V_53 || V_57 >= V_54 )
continue;
if ( * V_57 == 0x3e )
F_21 (ptr, ((unsigned char []){0xf0}), 1 ) ;
}
F_22 ( & V_56 ) ;
}
static void F_23 ( const T_4 * V_43 , const T_4 * V_44 ,
T_3 * V_53 , T_3 * V_54 )
{
const T_4 * V_55 ;
F_20 ( & V_56 ) ;
for ( V_55 = V_43 ; V_55 < V_44 ; V_55 ++ ) {
T_3 * V_57 = ( T_3 * ) V_55 + * V_55 ;
if ( ! * V_55 || V_57 < V_53 || V_57 >= V_54 )
continue;
if ( * V_57 == 0xf0 )
F_21 (ptr, ((unsigned char []){0x3E}), 1 ) ;
}
F_22 ( & V_56 ) ;
}
void T_2 F_24 ( struct V_58 * V_59 ,
char * V_60 ,
void * V_61 , void * V_62 ,
void * V_53 , void * V_54 )
{
struct V_63 * V_64 ;
F_20 ( & V_65 ) ;
if ( ! V_66 )
goto V_67;
if ( F_25 () == 1 )
goto V_68;
V_64 = F_26 ( sizeof( * V_64 ) , V_69 ) ;
if ( NULL == V_64 )
goto V_67;
V_64 -> V_59 = V_59 ;
V_64 -> V_60 = V_60 ;
V_64 -> V_61 = V_61 ;
V_64 -> V_62 = V_62 ;
V_64 -> V_53 = V_53 ;
V_64 -> V_54 = V_54 ;
F_10 ( L_10 ,
V_64 -> V_61 , V_64 -> V_62 ,
V_64 -> V_53 , V_64 -> V_54 , V_64 -> V_60 ) ;
F_27 ( & V_64 -> V_70 , & V_71 ) ;
V_68:
F_23 ( V_61 , V_62 , V_53 , V_54 ) ;
V_67:
F_22 ( & V_65 ) ;
}
void T_2 F_28 ( struct V_58 * V_59 )
{
struct V_63 * V_72 ;
F_20 ( & V_65 ) ;
F_29 (item, &smp_alt_modules, next) {
if ( V_59 != V_72 -> V_59 )
continue;
F_30 ( & V_72 -> V_70 ) ;
F_31 ( V_72 ) ;
break;
}
F_22 ( & V_65 ) ;
}
void F_32 ( void )
{
struct V_63 * V_59 ;
F_17 ( F_25 () == 1 ) ;
F_20 ( & V_65 ) ;
if ( V_66 ) {
F_33 ( L_11 ) ;
F_17 ( F_34 () != 1 ) ;
F_35 ( & V_5 , V_73 ) ;
F_35 ( & F_36 ( 0 ) , V_73 ) ;
F_29 (mod, &smp_alt_modules, next)
F_19 ( V_59 -> V_61 , V_59 -> V_62 ,
V_59 -> V_53 , V_59 -> V_54 ) ;
V_66 = false ;
}
F_22 ( & V_65 ) ;
}
int F_37 ( void * V_43 , void * V_44 )
{
struct V_63 * V_59 ;
const T_4 * V_55 ;
T_3 * V_74 = V_43 ;
T_3 * V_54 = V_44 ;
F_29 (mod, &smp_alt_modules, next) {
if ( V_59 -> V_53 > V_54 || V_59 -> V_54 < V_74 )
continue;
for ( V_55 = V_59 -> V_61 ; V_55 < V_59 -> V_62 ; V_55 ++ ) {
const T_3 * V_57 = ( const T_3 * ) V_55 + * V_55 ;
if ( V_74 <= V_57 && V_54 > V_57 )
return 1 ;
}
}
return 0 ;
}
void T_2 F_38 ( struct V_75 * V_43 ,
struct V_75 * V_44 )
{
struct V_75 * V_76 ;
char V_28 [ V_46 ] ;
if ( V_4 )
return;
for ( V_76 = V_43 ; V_76 < V_44 ; V_76 ++ ) {
unsigned int V_77 ;
F_17 ( V_76 -> V_20 > V_46 ) ;
memcpy ( V_28 , V_76 -> V_39 , V_76 -> V_20 ) ;
V_77 = V_78 . V_79 ( V_76 -> V_80 , V_76 -> V_81 , V_28 ,
( unsigned long ) V_76 -> V_39 , V_76 -> V_20 ) ;
F_17 ( V_77 > V_76 -> V_20 ) ;
F_7 ( V_28 + V_77 , V_76 -> V_20 - V_77 ) ;
F_18 ( V_76 -> V_39 , V_28 , V_76 -> V_20 ) ;
}
}
void T_1 F_39 ( void )
{
F_40 () ;
F_16 ( V_82 , V_83 ) ;
#ifdef F_41
if ( ! V_3 && ( F_42 () == 1 || V_84 <= 1 ) ) {
V_66 = true ;
F_24 ( NULL , L_12 ,
V_85 , V_86 ,
V_87 , V_88 ) ;
}
if ( ! V_66 || F_25 () == 1 )
F_43 ( L_13 ,
( unsigned long ) V_85 ,
( unsigned long ) V_86 ) ;
#endif
F_38 ( V_89 , V_90 ) ;
F_44 () ;
V_91 = 1 ;
}
void * T_2 F_18 ( void * V_92 , const void * V_23 ,
T_5 V_20 )
{
unsigned long V_40 ;
F_12 ( V_40 ) ;
memcpy ( V_92 , V_23 , V_20 ) ;
F_13 () ;
F_14 ( V_40 ) ;
return V_92 ;
}
void * F_21 ( void * V_92 , const void * V_23 , T_5 V_20 )
{
unsigned long V_40 ;
char * V_93 ;
struct V_94 * V_95 [ 2 ] ;
int V_96 ;
if ( ! F_45 ( ( unsigned long ) V_92 ) ) {
V_95 [ 0 ] = F_46 ( V_92 ) ;
V_95 [ 1 ] = F_46 ( V_92 + V_97 ) ;
} else {
V_95 [ 0 ] = F_47 ( V_92 ) ;
F_48 ( ! F_49 ( V_95 [ 0 ] ) ) ;
V_95 [ 1 ] = F_47 ( V_92 + V_97 ) ;
}
F_17 ( ! V_95 [ 0 ] ) ;
F_12 ( V_40 ) ;
F_50 ( V_98 , F_51 ( V_95 [ 0 ] ) ) ;
if ( V_95 [ 1 ] )
F_50 ( V_99 , F_51 ( V_95 [ 1 ] ) ) ;
V_93 = ( char * ) F_52 ( V_98 ) ;
memcpy ( & V_93 [ ( unsigned long ) V_92 & ~ V_100 ] , V_23 , V_20 ) ;
F_53 ( V_98 ) ;
if ( V_95 [ 1 ] )
F_53 ( V_99 ) ;
F_54 () ;
F_13 () ;
for ( V_96 = 0 ; V_96 < V_20 ; V_96 ++ )
F_17 ( ( ( char * ) V_92 ) [ V_96 ] != ( ( char * ) V_23 ) [ V_96 ] ) ;
F_14 ( V_40 ) ;
return V_92 ;
}
static void F_55 ( void * V_101 )
{
F_13 () ;
}
int F_56 ( struct V_102 * V_103 )
{
F_57 () ;
if ( F_58 ( ! V_104 ) )
return 0 ;
if ( F_59 ( V_103 ) || V_103 -> V_105 != ( unsigned long ) V_106 )
return 0 ;
V_103 -> V_105 = ( unsigned long ) V_107 ;
return 1 ;
}
void * F_60 ( void * V_92 , const void * V_23 , T_5 V_20 , void * V_108 )
{
unsigned char V_109 = 0xcc ;
V_107 = V_108 ;
V_106 = ( T_3 * ) V_92 + sizeof( V_109 ) ;
V_104 = true ;
F_61 () ;
F_21 ( V_92 , & V_109 , sizeof( V_109 ) ) ;
F_62 ( F_55 , NULL , 1 ) ;
if ( V_20 - sizeof( V_109 ) > 0 ) {
F_21 ( ( char * ) V_92 + sizeof( V_109 ) ,
( const char * ) V_23 + sizeof( V_109 ) ,
V_20 - sizeof( V_109 ) ) ;
F_62 ( F_55 , NULL , 1 ) ;
}
F_21 ( V_92 , V_23 , sizeof( V_109 ) ) ;
F_62 ( F_55 , NULL , 1 ) ;
V_104 = false ;
F_61 () ;
return V_92 ;
}
