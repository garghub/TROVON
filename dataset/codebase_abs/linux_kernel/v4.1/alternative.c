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
default:
#ifdef F_6
V_10 = V_11 ;
#else
if ( F_5 ( V_15 ) )
V_10 = V_11 ;
else if ( F_5 ( V_16 ) )
V_10 = V_17 ;
else
V_10 = V_14 ;
#endif
}
}
static void T_2 F_7 ( void * V_18 , unsigned int V_19 )
{
while ( V_19 > 0 ) {
unsigned int V_20 = V_19 ;
if ( V_20 > V_21 )
V_20 = V_21 ;
memcpy ( V_18 , V_10 [ V_20 ] , V_20 ) ;
V_18 += V_20 ;
V_19 -= V_20 ;
}
}
static inline bool F_8 ( const T_3 V_22 )
{
return V_22 == 0xeb || V_22 == 0xe9 ;
}
static void T_2
F_9 ( struct V_23 * V_24 , T_3 * V_25 , T_3 * V_26 , T_3 * V_27 )
{
T_3 * V_28 , * V_29 ;
T_4 V_30 , V_31 ;
int V_32 ;
if ( V_24 -> V_33 != 5 )
return;
V_31 = * ( T_4 * ) ( V_27 + 1 ) ;
V_28 = V_26 + V_24 -> V_33 ;
V_29 = V_28 + V_31 ;
V_30 = V_29 - V_25 ;
F_10 ( L_1 , V_29 , V_30 ) ;
if ( V_29 - V_25 >= 0 ) {
if ( V_30 - 2 <= 127 )
goto V_34;
else
goto V_35;
} else {
if ( ( ( V_30 - 2 ) & 0xff ) == ( V_30 - 2 ) )
goto V_34;
else
goto V_35;
}
V_34:
V_30 -= 2 ;
V_27 [ 0 ] = 0xeb ;
V_27 [ 1 ] = ( V_36 ) V_30 ;
F_7 ( V_27 + 2 , 3 ) ;
V_32 = 2 ;
goto V_37;
V_35:
V_30 -= 5 ;
V_27 [ 0 ] = 0xe9 ;
* ( T_4 * ) & V_27 [ 1 ] = V_30 ;
V_32 = 5 ;
V_37:
F_10 ( L_2 ,
V_30 , ( unsigned long ) V_25 + V_30 + V_32 ) ;
}
static void T_2 F_11 ( struct V_23 * V_24 , T_3 * V_38 )
{
if ( V_38 [ 0 ] != 0x90 )
return;
F_7 ( V_38 + ( V_24 -> V_39 - V_24 -> V_40 ) , V_24 -> V_40 ) ;
F_12 ( V_38 , V_24 -> V_39 , L_3 ,
V_38 , V_24 -> V_39 - V_24 -> V_40 , V_24 -> V_40 ) ;
}
void T_2 F_13 ( struct V_23 * V_41 ,
struct V_23 * V_42 )
{
struct V_23 * V_24 ;
T_3 * V_38 , * V_43 ;
T_3 V_27 [ V_44 ] ;
F_10 ( L_4 , V_41 , V_42 ) ;
for ( V_24 = V_41 ; V_24 < V_42 ; V_24 ++ ) {
int V_45 = 0 ;
V_38 = ( T_3 * ) & V_24 -> V_46 + V_24 -> V_46 ;
V_43 = ( T_3 * ) & V_24 -> V_47 + V_24 -> V_47 ;
F_14 ( V_24 -> V_39 > sizeof( V_27 ) ) ;
F_14 ( V_24 -> V_48 >= ( V_49 + V_50 ) * 32 ) ;
if ( ! F_5 ( V_24 -> V_48 ) ) {
if ( V_24 -> V_40 > 1 )
F_11 ( V_24 , V_38 ) ;
continue;
}
F_10 ( L_5 ,
V_24 -> V_48 >> 5 ,
V_24 -> V_48 & 0x1f ,
V_38 , V_24 -> V_39 ,
V_43 , V_24 -> V_33 , V_24 -> V_40 ) ;
F_12 ( V_38 , V_24 -> V_39 , L_6 , V_38 ) ;
F_12 ( V_43 , V_24 -> V_33 , L_7 , V_43 ) ;
memcpy ( V_27 , V_43 , V_24 -> V_33 ) ;
V_45 = V_24 -> V_33 ;
if ( * V_27 == 0xe8 && V_24 -> V_33 == 5 ) {
* ( T_4 * ) ( V_27 + 1 ) += V_43 - V_38 ;
F_10 ( L_8 ,
* ( T_4 * ) ( V_27 + 1 ) ,
( unsigned long ) V_38 + * ( T_4 * ) ( V_27 + 1 ) + 5 ) ;
}
if ( V_24 -> V_33 && F_8 ( V_43 [ 0 ] ) )
F_9 ( V_24 , V_38 , V_43 , V_27 ) ;
if ( V_24 -> V_39 > V_24 -> V_33 ) {
F_7 ( V_27 + V_24 -> V_33 ,
V_24 -> V_39 - V_24 -> V_33 ) ;
V_45 += V_24 -> V_39 - V_24 -> V_33 ;
}
F_12 ( V_27 , V_45 , L_9 , V_38 ) ;
F_15 ( V_38 , V_27 , V_45 ) ;
}
}
static void F_16 ( const T_4 * V_41 , const T_4 * V_42 ,
T_3 * V_51 , T_3 * V_52 )
{
const T_4 * V_53 ;
F_17 ( & V_54 ) ;
for ( V_53 = V_41 ; V_53 < V_42 ; V_53 ++ ) {
T_3 * V_55 = ( T_3 * ) V_53 + * V_53 ;
if ( ! * V_53 || V_55 < V_51 || V_55 >= V_52 )
continue;
if ( * V_55 == 0x3e )
F_18 (ptr, ((unsigned char []){0xf0}), 1 ) ;
}
F_19 ( & V_54 ) ;
}
static void F_20 ( const T_4 * V_41 , const T_4 * V_42 ,
T_3 * V_51 , T_3 * V_52 )
{
const T_4 * V_53 ;
F_17 ( & V_54 ) ;
for ( V_53 = V_41 ; V_53 < V_42 ; V_53 ++ ) {
T_3 * V_55 = ( T_3 * ) V_53 + * V_53 ;
if ( ! * V_53 || V_55 < V_51 || V_55 >= V_52 )
continue;
if ( * V_55 == 0xf0 )
F_18 (ptr, ((unsigned char []){0x3E}), 1 ) ;
}
F_19 ( & V_54 ) ;
}
void T_2 F_21 ( struct V_56 * V_57 ,
char * V_58 ,
void * V_59 , void * V_60 ,
void * V_51 , void * V_52 )
{
struct V_61 * V_62 ;
F_17 ( & V_63 ) ;
if ( ! V_64 )
goto V_65;
if ( F_22 () == 1 )
goto V_66;
V_62 = F_23 ( sizeof( * V_62 ) , V_67 ) ;
if ( NULL == V_62 )
goto V_65;
V_62 -> V_57 = V_57 ;
V_62 -> V_58 = V_58 ;
V_62 -> V_59 = V_59 ;
V_62 -> V_60 = V_60 ;
V_62 -> V_51 = V_51 ;
V_62 -> V_52 = V_52 ;
F_10 ( L_10 ,
V_62 -> V_59 , V_62 -> V_60 ,
V_62 -> V_51 , V_62 -> V_52 , V_62 -> V_58 ) ;
F_24 ( & V_62 -> V_68 , & V_69 ) ;
V_66:
F_20 ( V_59 , V_60 , V_51 , V_52 ) ;
V_65:
F_19 ( & V_63 ) ;
}
void T_2 F_25 ( struct V_56 * V_57 )
{
struct V_61 * V_70 ;
F_17 ( & V_63 ) ;
F_26 (item, &smp_alt_modules, next) {
if ( V_57 != V_70 -> V_57 )
continue;
F_27 ( & V_70 -> V_68 ) ;
F_28 ( V_70 ) ;
break;
}
F_19 ( & V_63 ) ;
}
void F_29 ( void )
{
struct V_61 * V_57 ;
F_14 ( F_22 () == 1 ) ;
F_17 ( & V_63 ) ;
if ( V_64 ) {
F_30 ( L_11 ) ;
F_14 ( F_31 () != 1 ) ;
F_32 ( & V_5 , V_71 ) ;
F_32 ( & F_33 ( 0 ) , V_71 ) ;
F_26 (mod, &smp_alt_modules, next)
F_16 ( V_57 -> V_59 , V_57 -> V_60 ,
V_57 -> V_51 , V_57 -> V_52 ) ;
V_64 = false ;
}
F_19 ( & V_63 ) ;
}
int F_34 ( void * V_41 , void * V_42 )
{
struct V_61 * V_57 ;
const T_4 * V_53 ;
T_3 * V_72 = V_41 ;
T_3 * V_52 = V_42 ;
F_26 (mod, &smp_alt_modules, next) {
if ( V_57 -> V_51 > V_52 || V_57 -> V_52 < V_72 )
continue;
for ( V_53 = V_57 -> V_59 ; V_53 < V_57 -> V_60 ; V_53 ++ ) {
const T_3 * V_55 = ( const T_3 * ) V_53 + * V_53 ;
if ( V_72 <= V_55 && V_52 > V_55 )
return 1 ;
}
}
return 0 ;
}
void T_2 F_35 ( struct V_73 * V_41 ,
struct V_73 * V_42 )
{
struct V_73 * V_74 ;
char V_27 [ V_44 ] ;
if ( V_4 )
return;
for ( V_74 = V_41 ; V_74 < V_42 ; V_74 ++ ) {
unsigned int V_75 ;
F_14 ( V_74 -> V_19 > V_44 ) ;
memcpy ( V_27 , V_74 -> V_38 , V_74 -> V_19 ) ;
V_75 = V_76 . V_77 ( V_74 -> V_78 , V_74 -> V_79 , V_27 ,
( unsigned long ) V_74 -> V_38 , V_74 -> V_19 ) ;
F_14 ( V_75 > V_74 -> V_19 ) ;
F_7 ( V_27 + V_75 , V_74 -> V_19 - V_75 ) ;
F_15 ( V_74 -> V_38 , V_27 , V_74 -> V_19 ) ;
}
}
void T_1 F_36 ( void )
{
F_37 () ;
F_13 ( V_80 , V_81 ) ;
#ifdef F_38
if ( ! V_3 && ( F_39 () == 1 || V_82 <= 1 ) ) {
V_64 = true ;
F_21 ( NULL , L_12 ,
V_83 , V_84 ,
V_85 , V_86 ) ;
}
if ( ! V_64 || F_22 () == 1 )
F_40 ( L_13 ,
( unsigned long ) V_83 ,
( unsigned long ) V_84 ) ;
#endif
F_35 ( V_87 , V_88 ) ;
F_41 () ;
}
void * T_2 F_15 ( void * V_89 , const void * V_22 ,
T_5 V_19 )
{
unsigned long V_90 ;
F_42 ( V_90 ) ;
memcpy ( V_89 , V_22 , V_19 ) ;
F_43 () ;
F_44 ( V_90 ) ;
return V_89 ;
}
void * F_18 ( void * V_89 , const void * V_22 , T_5 V_19 )
{
unsigned long V_90 ;
char * V_91 ;
struct V_92 * V_93 [ 2 ] ;
int V_94 ;
if ( ! F_45 ( ( unsigned long ) V_89 ) ) {
V_93 [ 0 ] = F_46 ( V_89 ) ;
V_93 [ 1 ] = F_46 ( V_89 + V_95 ) ;
} else {
V_93 [ 0 ] = F_47 ( V_89 ) ;
F_48 ( ! F_49 ( V_93 [ 0 ] ) ) ;
V_93 [ 1 ] = F_47 ( V_89 + V_95 ) ;
}
F_14 ( ! V_93 [ 0 ] ) ;
F_42 ( V_90 ) ;
F_50 ( V_96 , F_51 ( V_93 [ 0 ] ) ) ;
if ( V_93 [ 1 ] )
F_50 ( V_97 , F_51 ( V_93 [ 1 ] ) ) ;
V_91 = ( char * ) F_52 ( V_96 ) ;
memcpy ( & V_91 [ ( unsigned long ) V_89 & ~ V_98 ] , V_22 , V_19 ) ;
F_53 ( V_96 ) ;
if ( V_93 [ 1 ] )
F_53 ( V_97 ) ;
F_54 () ;
F_43 () ;
for ( V_94 = 0 ; V_94 < V_19 ; V_94 ++ )
F_14 ( ( ( char * ) V_89 ) [ V_94 ] != ( ( char * ) V_22 ) [ V_94 ] ) ;
F_44 ( V_90 ) ;
return V_89 ;
}
static void F_55 ( void * V_99 )
{
F_43 () ;
}
int F_56 ( struct V_100 * V_101 )
{
F_57 () ;
if ( F_58 ( ! V_102 ) )
return 0 ;
if ( F_59 ( V_101 ) || V_101 -> V_103 != ( unsigned long ) V_104 )
return 0 ;
V_101 -> V_103 = ( unsigned long ) V_105 ;
return 1 ;
}
void * F_60 ( void * V_89 , const void * V_22 , T_5 V_19 , void * V_106 )
{
unsigned char V_107 = 0xcc ;
V_105 = V_106 ;
V_104 = ( T_3 * ) V_89 + sizeof( V_107 ) ;
V_102 = true ;
F_61 () ;
F_18 ( V_89 , & V_107 , sizeof( V_107 ) ) ;
F_62 ( F_55 , NULL , 1 ) ;
if ( V_19 - sizeof( V_107 ) > 0 ) {
F_18 ( ( char * ) V_89 + sizeof( V_107 ) ,
( const char * ) V_22 + sizeof( V_107 ) ,
V_19 - sizeof( V_107 ) ) ;
F_62 ( F_55 , NULL , 1 ) ;
}
F_18 ( V_89 , V_22 , sizeof( V_107 ) ) ;
F_62 ( F_55 , NULL , 1 ) ;
V_102 = false ;
F_61 () ;
return V_89 ;
}
