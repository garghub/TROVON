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
void T_2 F_8 ( struct V_22 * V_23 ,
struct V_22 * V_24 )
{
struct V_22 * V_25 ;
T_3 * V_26 , * V_27 ;
T_3 V_28 [ V_29 ] ;
F_9 ( L_1 , V_30 , V_23 , V_24 ) ;
for ( V_25 = V_23 ; V_25 < V_24 ; V_25 ++ ) {
V_26 = ( T_3 * ) & V_25 -> V_31 + V_25 -> V_31 ;
V_27 = ( T_3 * ) & V_25 -> V_32 + V_25 -> V_32 ;
F_10 ( V_25 -> V_33 > V_25 -> V_34 ) ;
F_10 ( V_25 -> V_34 > sizeof( V_28 ) ) ;
F_10 ( V_25 -> V_35 >= ( V_36 + V_37 ) * 32 ) ;
if ( ! F_5 ( V_25 -> V_35 ) )
continue;
memcpy ( V_28 , V_27 , V_25 -> V_33 ) ;
if ( * V_28 == 0xe8 && V_25 -> V_33 == 5 )
* ( V_38 * ) ( V_28 + 1 ) += V_27 - V_26 ;
F_7 ( V_28 + V_25 -> V_33 ,
V_25 -> V_34 - V_25 -> V_33 ) ;
F_11 ( V_26 , V_28 , V_25 -> V_34 ) ;
}
}
static void F_12 ( const V_38 * V_23 , const V_38 * V_24 ,
T_3 * V_39 , T_3 * V_40 )
{
const V_38 * V_41 ;
F_13 ( & V_42 ) ;
for ( V_41 = V_23 ; V_41 < V_24 ; V_41 ++ ) {
T_3 * V_43 = ( T_3 * ) V_41 + * V_41 ;
if ( ! * V_41 || V_43 < V_39 || V_43 >= V_40 )
continue;
if ( * V_43 == 0x3e )
F_14 (ptr, ((unsigned char []){0xf0}), 1 ) ;
}
F_15 ( & V_42 ) ;
}
static void F_16 ( const V_38 * V_23 , const V_38 * V_24 ,
T_3 * V_39 , T_3 * V_40 )
{
const V_38 * V_41 ;
F_13 ( & V_42 ) ;
for ( V_41 = V_23 ; V_41 < V_24 ; V_41 ++ ) {
T_3 * V_43 = ( T_3 * ) V_41 + * V_41 ;
if ( ! * V_41 || V_43 < V_39 || V_43 >= V_40 )
continue;
if ( * V_43 == 0xf0 )
F_14 (ptr, ((unsigned char []){0x3E}), 1 ) ;
}
F_15 ( & V_42 ) ;
}
void T_2 F_17 ( struct V_44 * V_45 ,
char * V_46 ,
void * V_47 , void * V_48 ,
void * V_39 , void * V_40 )
{
struct V_49 * V_50 ;
F_13 ( & V_51 ) ;
if ( ! V_52 )
goto V_53;
if ( F_18 () == 1 )
goto V_54;
V_50 = F_19 ( sizeof( * V_50 ) , V_55 ) ;
if ( NULL == V_50 )
goto V_53;
V_50 -> V_45 = V_45 ;
V_50 -> V_46 = V_46 ;
V_50 -> V_47 = V_47 ;
V_50 -> V_48 = V_48 ;
V_50 -> V_39 = V_39 ;
V_50 -> V_40 = V_40 ;
F_9 ( L_2 ,
V_30 , V_50 -> V_47 , V_50 -> V_48 ,
V_50 -> V_39 , V_50 -> V_40 , V_50 -> V_46 ) ;
F_20 ( & V_50 -> V_56 , & V_57 ) ;
V_54:
F_16 ( V_47 , V_48 , V_39 , V_40 ) ;
V_53:
F_15 ( & V_51 ) ;
}
void T_2 F_21 ( struct V_44 * V_45 )
{
struct V_49 * V_58 ;
F_13 ( & V_51 ) ;
F_22 (item, &smp_alt_modules, next) {
if ( V_45 != V_58 -> V_45 )
continue;
F_23 ( & V_58 -> V_56 ) ;
F_24 ( V_58 ) ;
break;
}
F_15 ( & V_51 ) ;
}
void F_25 ( void )
{
struct V_49 * V_45 ;
#ifdef F_26
F_27 ( L_3 ) ;
#endif
F_10 ( F_18 () == 1 ) ;
F_13 ( & V_51 ) ;
if ( V_52 ) {
F_27 ( L_4 ) ;
F_10 ( F_28 () != 1 ) ;
F_29 ( & V_5 , V_59 ) ;
F_29 ( & F_30 ( 0 ) , V_59 ) ;
F_22 (mod, &smp_alt_modules, next)
F_12 ( V_45 -> V_47 , V_45 -> V_48 ,
V_45 -> V_39 , V_45 -> V_40 ) ;
V_52 = false ;
}
F_15 ( & V_51 ) ;
}
int F_31 ( void * V_23 , void * V_24 )
{
struct V_49 * V_45 ;
const V_38 * V_41 ;
T_3 * V_60 = V_23 ;
T_3 * V_40 = V_24 ;
F_22 (mod, &smp_alt_modules, next) {
if ( V_45 -> V_39 > V_40 || V_45 -> V_40 < V_60 )
continue;
for ( V_41 = V_45 -> V_47 ; V_41 < V_45 -> V_48 ; V_41 ++ ) {
const T_3 * V_43 = ( const T_3 * ) V_41 + * V_41 ;
if ( V_60 <= V_43 && V_40 > V_43 )
return 1 ;
}
}
return 0 ;
}
void T_2 F_32 ( struct V_61 * V_23 ,
struct V_61 * V_24 )
{
struct V_61 * V_62 ;
char V_28 [ V_29 ] ;
if ( V_4 )
return;
for ( V_62 = V_23 ; V_62 < V_24 ; V_62 ++ ) {
unsigned int V_63 ;
F_10 ( V_62 -> V_19 > V_29 ) ;
memcpy ( V_28 , V_62 -> V_26 , V_62 -> V_19 ) ;
V_63 = V_64 . V_65 ( V_62 -> V_66 , V_62 -> V_67 , V_28 ,
( unsigned long ) V_62 -> V_26 , V_62 -> V_19 ) ;
F_10 ( V_63 > V_62 -> V_19 ) ;
F_7 ( V_28 + V_63 , V_62 -> V_19 - V_63 ) ;
F_11 ( V_62 -> V_26 , V_28 , V_62 -> V_19 ) ;
}
}
void T_1 F_33 ( void )
{
F_34 () ;
F_8 ( V_68 , V_69 ) ;
#ifdef F_35
if ( ! V_3 && ( F_36 () == 1 || V_70 <= 1 ) ) {
V_52 = true ;
F_17 ( NULL , L_5 ,
V_71 , V_72 ,
V_73 , V_74 ) ;
}
if ( ! V_52 || F_18 () == 1 )
F_37 ( L_6 ,
( unsigned long ) V_71 ,
( unsigned long ) V_72 ) ;
#endif
F_32 ( V_75 , V_76 ) ;
F_38 () ;
}
void * T_2 F_11 ( void * V_77 , const void * V_78 ,
T_4 V_19 )
{
unsigned long V_79 ;
F_39 ( V_79 ) ;
memcpy ( V_77 , V_78 , V_19 ) ;
F_40 () ;
F_41 ( V_79 ) ;
return V_77 ;
}
void * T_5 F_14 ( void * V_77 , const void * V_78 , T_4 V_19 )
{
unsigned long V_79 ;
char * V_80 ;
struct V_81 * V_82 [ 2 ] ;
int V_83 ;
if ( ! F_42 ( ( unsigned long ) V_77 ) ) {
V_82 [ 0 ] = F_43 ( V_77 ) ;
V_82 [ 1 ] = F_43 ( V_77 + V_84 ) ;
} else {
V_82 [ 0 ] = F_44 ( V_77 ) ;
F_45 ( ! F_46 ( V_82 [ 0 ] ) ) ;
V_82 [ 1 ] = F_44 ( V_77 + V_84 ) ;
}
F_10 ( ! V_82 [ 0 ] ) ;
F_39 ( V_79 ) ;
F_47 ( V_85 , F_48 ( V_82 [ 0 ] ) ) ;
if ( V_82 [ 1 ] )
F_47 ( V_86 , F_48 ( V_82 [ 1 ] ) ) ;
V_80 = ( char * ) F_49 ( V_85 ) ;
memcpy ( & V_80 [ ( unsigned long ) V_77 & ~ V_87 ] , V_78 , V_19 ) ;
F_50 ( V_85 ) ;
if ( V_82 [ 1 ] )
F_50 ( V_86 ) ;
F_51 () ;
F_40 () ;
for ( V_83 = 0 ; V_83 < V_19 ; V_83 ++ )
F_10 ( ( ( char * ) V_77 ) [ V_83 ] != ( ( char * ) V_78 ) [ V_83 ] ) ;
F_41 ( V_79 ) ;
return V_77 ;
}
static void F_52 ( void * V_88 )
{
F_40 () ;
}
int F_53 ( struct V_89 * V_90 )
{
F_54 () ;
if ( F_55 ( ! V_91 ) )
return 0 ;
if ( F_56 ( V_90 ) || V_90 -> V_92 != ( unsigned long ) V_93 )
return 0 ;
V_90 -> V_92 = ( unsigned long ) V_94 ;
return 1 ;
}
void * F_57 ( void * V_77 , const void * V_78 , T_4 V_19 , void * V_95 )
{
unsigned char V_96 = 0xcc ;
V_94 = V_95 ;
V_93 = ( T_3 * ) V_77 + sizeof( V_96 ) ;
V_91 = true ;
F_58 () ;
F_14 ( V_77 , & V_96 , sizeof( V_96 ) ) ;
F_59 ( F_52 , NULL , 1 ) ;
if ( V_19 - sizeof( V_96 ) > 0 ) {
F_14 ( ( char * ) V_77 + sizeof( V_96 ) ,
( const char * ) V_78 + sizeof( V_96 ) ,
V_19 - sizeof( V_96 ) ) ;
F_59 ( F_52 , NULL , 1 ) ;
}
F_14 ( V_77 , V_78 , sizeof( V_96 ) ) ;
F_59 ( F_52 , NULL , 1 ) ;
V_91 = false ;
F_58 () ;
return V_77 ;
}
