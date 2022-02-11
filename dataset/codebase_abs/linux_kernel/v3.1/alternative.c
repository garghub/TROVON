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
static int T_1 F_4 ( char * V_1 )
{
V_5 = 1 ;
return 1 ;
}
void T_1 F_5 ( void )
{
switch ( V_6 . V_7 ) {
case V_8 :
if ( V_6 . V_9 == 6 &&
V_6 . V_10 >= 0x0f &&
V_6 . V_10 != 0x1c &&
V_6 . V_10 != 0x26 &&
V_6 . V_10 != 0x27 &&
V_6 . V_10 < 0x30 ) {
V_11 = V_12 ;
} else if ( F_6 ( V_13 ) ) {
V_11 = V_14 ;
} else {
#ifdef F_7
V_11 = V_12 ;
#else
V_11 = V_15 ;
#endif
}
default:
#ifdef F_7
V_11 = V_12 ;
#else
if ( F_6 ( V_16 ) )
V_11 = V_12 ;
else if ( F_6 ( V_17 ) )
V_11 = V_18 ;
else
V_11 = V_15 ;
#endif
}
}
static void T_2 F_8 ( void * V_19 , unsigned int V_20 )
{
while ( V_20 > 0 ) {
unsigned int V_21 = V_20 ;
if ( V_21 > V_22 )
V_21 = V_22 ;
memcpy ( V_19 , V_11 [ V_21 ] , V_21 ) ;
V_19 += V_21 ;
V_20 -= V_21 ;
}
}
void T_2 F_9 ( struct V_23 * V_24 ,
struct V_23 * V_25 )
{
struct V_23 * V_26 ;
T_3 * V_27 , * V_28 ;
T_3 V_29 [ V_30 ] ;
F_10 ( L_1 , V_31 , V_24 , V_25 ) ;
for ( V_26 = V_24 ; V_26 < V_25 ; V_26 ++ ) {
V_27 = ( T_3 * ) & V_26 -> V_32 + V_26 -> V_32 ;
V_28 = ( T_3 * ) & V_26 -> V_33 + V_26 -> V_33 ;
F_11 ( V_26 -> V_34 > V_26 -> V_35 ) ;
F_11 ( V_26 -> V_35 > sizeof( V_29 ) ) ;
F_11 ( V_26 -> V_36 >= V_37 * 32 ) ;
if ( ! F_6 ( V_26 -> V_36 ) )
continue;
memcpy ( V_29 , V_28 , V_26 -> V_34 ) ;
if ( * V_29 == 0xe8 && V_26 -> V_34 == 5 )
* ( V_38 * ) ( V_29 + 1 ) += V_28 - V_27 ;
F_8 ( V_29 + V_26 -> V_34 ,
V_26 -> V_35 - V_26 -> V_34 ) ;
F_12 ( V_27 , V_29 , V_26 -> V_35 ) ;
}
}
static void F_13 ( const V_38 * V_24 , const V_38 * V_25 ,
T_3 * V_39 , T_3 * V_40 )
{
const V_38 * V_41 ;
F_14 ( & V_42 ) ;
for ( V_41 = V_24 ; V_41 < V_25 ; V_41 ++ ) {
T_3 * V_43 = ( T_3 * ) V_41 + * V_41 ;
if ( ! * V_41 || V_43 < V_39 || V_43 >= V_40 )
continue;
if ( * V_43 == 0x3e )
F_15 (ptr, ((unsigned char []){0xf0}), 1 ) ;
} ;
F_16 ( & V_42 ) ;
}
static void F_17 ( const V_38 * V_24 , const V_38 * V_25 ,
T_3 * V_39 , T_3 * V_40 )
{
const V_38 * V_41 ;
if ( V_4 )
return;
F_14 ( & V_42 ) ;
for ( V_41 = V_24 ; V_41 < V_25 ; V_41 ++ ) {
T_3 * V_43 = ( T_3 * ) V_41 + * V_41 ;
if ( ! * V_41 || V_43 < V_39 || V_43 >= V_40 )
continue;
if ( * V_43 == 0xf0 )
F_15 (ptr, ((unsigned char []){0x3E}), 1 ) ;
} ;
F_16 ( & V_42 ) ;
}
void T_2 F_18 ( struct V_44 * V_45 ,
char * V_46 ,
void * V_47 , void * V_48 ,
void * V_39 , void * V_40 )
{
struct V_49 * V_50 ;
if ( V_4 )
return;
if ( V_2 ) {
if ( F_6 ( V_51 ) )
F_17 ( V_47 , V_48 ,
V_39 , V_40 ) ;
return;
}
V_50 = F_19 ( sizeof( * V_50 ) , V_52 ) ;
if ( NULL == V_50 )
return;
V_50 -> V_45 = V_45 ;
V_50 -> V_46 = V_46 ;
V_50 -> V_47 = V_47 ;
V_50 -> V_48 = V_48 ;
V_50 -> V_39 = V_39 ;
V_50 -> V_40 = V_40 ;
F_10 ( L_2 ,
V_31 , V_50 -> V_47 , V_50 -> V_48 ,
V_50 -> V_39 , V_50 -> V_40 , V_50 -> V_46 ) ;
F_14 ( & V_53 ) ;
F_20 ( & V_50 -> V_54 , & V_55 ) ;
if ( F_6 ( V_51 ) )
F_17 ( V_50 -> V_47 , V_50 -> V_48 ,
V_50 -> V_39 , V_50 -> V_40 ) ;
F_16 ( & V_53 ) ;
}
void T_2 F_21 ( struct V_44 * V_45 )
{
struct V_49 * V_56 ;
if ( V_2 || V_4 )
return;
F_14 ( & V_53 ) ;
F_22 (item, &smp_alt_modules, next) {
if ( V_45 != V_56 -> V_45 )
continue;
F_23 ( & V_56 -> V_54 ) ;
F_16 ( & V_53 ) ;
F_10 ( L_3 , V_31 , V_56 -> V_46 ) ;
F_24 ( V_56 ) ;
return;
}
F_16 ( & V_53 ) ;
}
void F_25 ( int V_50 )
{
struct V_49 * V_45 ;
#ifdef F_26
F_27 ( L_4 ) ;
#endif
if ( V_4 || V_2 || V_57 )
return;
F_11 ( ! V_50 && ( F_28 () > 1 ) ) ;
F_14 ( & V_53 ) ;
if ( V_50 == V_58 ) {
} else if ( V_50 ) {
F_27 ( V_59 L_5 ) ;
F_29 ( & V_6 , V_51 ) ;
F_29 ( & F_30 ( 0 ) , V_51 ) ;
F_22 (mod, &smp_alt_modules, next)
F_13 ( V_45 -> V_47 , V_45 -> V_48 ,
V_45 -> V_39 , V_45 -> V_40 ) ;
} else {
F_27 ( V_59 L_6 ) ;
F_31 ( & V_6 , V_51 ) ;
F_31 ( & F_30 ( 0 ) , V_51 ) ;
F_22 (mod, &smp_alt_modules, next)
F_17 ( V_45 -> V_47 , V_45 -> V_48 ,
V_45 -> V_39 , V_45 -> V_40 ) ;
}
V_58 = V_50 ;
F_16 ( & V_53 ) ;
}
int F_32 ( void * V_24 , void * V_25 )
{
struct V_49 * V_45 ;
const V_38 * V_41 ;
T_3 * V_60 = V_24 ;
T_3 * V_40 = V_25 ;
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
void T_2 F_33 ( struct V_61 * V_24 ,
struct V_61 * V_25 )
{
struct V_61 * V_62 ;
char V_29 [ V_30 ] ;
if ( V_5 )
return;
for ( V_62 = V_24 ; V_62 < V_25 ; V_62 ++ ) {
unsigned int V_63 ;
F_11 ( V_62 -> V_20 > V_30 ) ;
memcpy ( V_29 , V_62 -> V_27 , V_62 -> V_20 ) ;
V_63 = V_64 . V_65 ( V_62 -> V_66 , V_62 -> V_67 , V_29 ,
( unsigned long ) V_62 -> V_27 , V_62 -> V_20 ) ;
F_11 ( V_63 > V_62 -> V_20 ) ;
F_8 ( V_29 + V_63 , V_62 -> V_20 - V_63 ) ;
F_12 ( V_62 -> V_27 , V_29 , V_62 -> V_20 ) ;
}
}
void T_1 F_34 ( void )
{
F_35 () ;
F_9 ( V_68 , V_69 ) ;
#ifdef F_36
if ( F_37 () < 2 )
V_2 = 1 ;
#endif
#ifdef F_38
if ( V_2 ) {
if ( 1 == F_37 () ) {
F_27 ( V_59 L_6 ) ;
F_31 ( & V_6 , V_51 ) ;
F_31 ( & F_30 ( 0 ) , V_51 ) ;
F_17 ( V_70 , V_71 ,
V_72 , V_73 ) ;
}
} else {
F_18 ( NULL , L_7 ,
V_70 , V_71 ,
V_72 , V_73 ) ;
if ( F_39 () == 1 || V_74 <= 1 )
F_25 ( 0 ) ;
}
#endif
F_33 ( V_75 , V_76 ) ;
if ( V_2 )
F_40 ( L_8 ,
( unsigned long ) V_70 ,
( unsigned long ) V_71 ) ;
F_41 () ;
}
void * T_2 F_12 ( void * V_77 , const void * V_78 ,
T_4 V_20 )
{
unsigned long V_79 ;
F_42 ( V_79 ) ;
memcpy ( V_77 , V_78 , V_20 ) ;
F_43 () ;
F_44 ( V_79 ) ;
return V_77 ;
}
void * T_5 F_15 ( void * V_77 , const void * V_78 , T_4 V_20 )
{
unsigned long V_79 ;
char * V_80 ;
struct V_81 * V_82 [ 2 ] ;
int V_83 ;
if ( ! F_45 ( ( unsigned long ) V_77 ) ) {
V_82 [ 0 ] = F_46 ( V_77 ) ;
V_82 [ 1 ] = F_46 ( V_77 + V_84 ) ;
} else {
V_82 [ 0 ] = F_47 ( V_77 ) ;
F_48 ( ! F_49 ( V_82 [ 0 ] ) ) ;
V_82 [ 1 ] = F_47 ( V_77 + V_84 ) ;
}
F_11 ( ! V_82 [ 0 ] ) ;
F_42 ( V_79 ) ;
F_50 ( V_85 , F_51 ( V_82 [ 0 ] ) ) ;
if ( V_82 [ 1 ] )
F_50 ( V_86 , F_51 ( V_82 [ 1 ] ) ) ;
V_80 = ( char * ) F_52 ( V_85 ) ;
memcpy ( & V_80 [ ( unsigned long ) V_77 & ~ V_87 ] , V_78 , V_20 ) ;
F_53 ( V_85 ) ;
if ( V_82 [ 1 ] )
F_53 ( V_86 ) ;
F_54 () ;
F_43 () ;
for ( V_83 = 0 ; V_83 < V_20 ; V_83 ++ )
F_11 ( ( ( char * ) V_77 ) [ V_83 ] != ( ( char * ) V_78 ) [ V_83 ] ) ;
F_44 ( V_79 ) ;
return V_77 ;
}
static int T_5 F_55 ( void * V_88 )
{
struct V_89 * V_90 = V_88 ;
struct V_91 * V_62 ;
int V_83 ;
if ( F_56 ( & V_92 ) ) {
for ( V_83 = 0 ; V_83 < V_90 -> V_93 ; V_83 ++ ) {
V_62 = & V_90 -> V_94 [ V_83 ] ;
F_15 ( V_62 -> V_77 , V_62 -> V_78 , V_62 -> V_20 ) ;
}
F_57 () ;
V_95 = 1 ;
} else {
while ( ! V_95 )
F_58 () ;
F_59 () ;
}
for ( V_83 = 0 ; V_83 < V_90 -> V_93 ; V_83 ++ ) {
V_62 = & V_90 -> V_94 [ V_83 ] ;
F_60 ( ( unsigned long ) V_62 -> V_77 ,
( unsigned long ) V_62 -> V_77 + V_62 -> V_20 ) ;
}
F_43 () ;
return 0 ;
}
void * T_5 F_61 ( void * V_77 , const void * V_78 , T_4 V_20 )
{
struct V_89 V_90 ;
struct V_91 V_62 ;
V_62 . V_77 = V_77 ;
V_62 . V_78 = V_78 ;
V_62 . V_20 = V_20 ;
V_90 . V_94 = & V_62 ;
V_90 . V_93 = 1 ;
F_62 ( & V_92 , 1 ) ;
V_95 = 0 ;
F_63 ( F_55 , ( void * ) & V_90 , V_96 ) ;
return V_77 ;
}
void T_5 F_64 ( struct V_91 * V_94 , int V_97 )
{
struct V_89 V_90 = { . V_94 = V_94 , . V_93 = V_97 } ;
F_62 ( & V_92 , 1 ) ;
V_95 = 0 ;
F_63 ( F_55 , ( void * ) & V_90 , NULL ) ;
}
