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
T_3 V_27 [ V_28 ] ;
F_10 ( L_1 , V_29 , V_24 , V_25 ) ;
for ( V_26 = V_24 ; V_26 < V_25 ; V_26 ++ ) {
T_3 * V_30 = V_26 -> V_30 ;
F_11 ( V_26 -> V_31 > V_26 -> V_32 ) ;
F_11 ( V_26 -> V_32 > sizeof( V_27 ) ) ;
F_11 ( V_26 -> V_33 >= V_34 * 32 ) ;
if ( ! F_6 ( V_26 -> V_33 ) )
continue;
#ifdef F_7
if ( V_30 >= ( T_3 * ) V_35 && V_30 < ( T_3 * ) V_36 ) {
V_30 = F_12 ( V_30 - ( T_3 * ) V_35 + ( T_3 * ) F_13 ( & V_37 ) ) ;
F_10 ( L_2 ,
V_29 , V_26 -> V_30 , V_30 ) ;
}
#endif
memcpy ( V_27 , V_26 -> V_38 , V_26 -> V_31 ) ;
if ( * V_27 == 0xe8 && V_26 -> V_31 == 5 )
* ( V_39 * ) ( V_27 + 1 ) += V_26 -> V_38 - V_26 -> V_30 ;
F_8 ( V_27 + V_26 -> V_31 ,
V_26 -> V_32 - V_26 -> V_31 ) ;
F_14 ( V_30 , V_27 , V_26 -> V_32 ) ;
}
}
static void F_15 ( const V_39 * V_24 , const V_39 * V_25 ,
T_3 * V_40 , T_3 * V_41 )
{
const V_39 * V_42 ;
F_16 ( & V_43 ) ;
for ( V_42 = V_24 ; V_42 < V_25 ; V_42 ++ ) {
T_3 * V_44 = ( T_3 * ) V_42 + * V_42 ;
if ( ! * V_42 || V_44 < V_40 || V_44 >= V_41 )
continue;
if ( * V_44 == 0x3e )
F_17 (ptr, ((unsigned char []){0xf0}), 1 ) ;
} ;
F_18 ( & V_43 ) ;
}
static void F_19 ( const V_39 * V_24 , const V_39 * V_25 ,
T_3 * V_40 , T_3 * V_41 )
{
const V_39 * V_42 ;
if ( V_4 )
return;
F_16 ( & V_43 ) ;
for ( V_42 = V_24 ; V_42 < V_25 ; V_42 ++ ) {
T_3 * V_44 = ( T_3 * ) V_42 + * V_42 ;
if ( ! * V_42 || V_44 < V_40 || V_44 >= V_41 )
continue;
if ( * V_44 == 0xf0 )
F_17 (ptr, ((unsigned char []){0x3E}), 1 ) ;
} ;
F_18 ( & V_43 ) ;
}
void T_2 F_20 ( struct V_45 * V_46 ,
char * V_47 ,
void * V_48 , void * V_49 ,
void * V_40 , void * V_41 )
{
struct V_50 * V_51 ;
if ( V_4 )
return;
if ( V_2 ) {
if ( F_6 ( V_52 ) )
F_19 ( V_48 , V_49 ,
V_40 , V_41 ) ;
return;
}
V_51 = F_21 ( sizeof( * V_51 ) , V_53 ) ;
if ( NULL == V_51 )
return;
V_51 -> V_46 = V_46 ;
V_51 -> V_47 = V_47 ;
V_51 -> V_48 = V_48 ;
V_51 -> V_49 = V_49 ;
V_51 -> V_40 = V_40 ;
V_51 -> V_41 = V_41 ;
F_10 ( L_3 ,
V_29 , V_51 -> V_48 , V_51 -> V_49 ,
V_51 -> V_40 , V_51 -> V_41 , V_51 -> V_47 ) ;
F_16 ( & V_54 ) ;
F_22 ( & V_51 -> V_55 , & V_56 ) ;
if ( F_6 ( V_52 ) )
F_19 ( V_51 -> V_48 , V_51 -> V_49 ,
V_51 -> V_40 , V_51 -> V_41 ) ;
F_18 ( & V_54 ) ;
}
void T_2 F_23 ( struct V_45 * V_46 )
{
struct V_50 * V_57 ;
if ( V_2 || V_4 )
return;
F_16 ( & V_54 ) ;
F_24 (item, &smp_alt_modules, next) {
if ( V_46 != V_57 -> V_46 )
continue;
F_25 ( & V_57 -> V_55 ) ;
F_18 ( & V_54 ) ;
F_10 ( L_4 , V_29 , V_57 -> V_47 ) ;
F_26 ( V_57 ) ;
return;
}
F_18 ( & V_54 ) ;
}
void F_27 ( int V_51 )
{
struct V_50 * V_46 ;
#ifdef F_28
F_29 ( L_5 ) ;
#endif
if ( V_4 || V_2 || V_58 )
return;
F_11 ( ! V_51 && ( F_30 () > 1 ) ) ;
F_16 ( & V_54 ) ;
if ( V_51 == V_59 ) {
} else if ( V_51 ) {
F_29 ( V_60 L_6 ) ;
F_31 ( & V_6 , V_52 ) ;
F_31 ( & F_32 ( 0 ) , V_52 ) ;
F_24 (mod, &smp_alt_modules, next)
F_15 ( V_46 -> V_48 , V_46 -> V_49 ,
V_46 -> V_40 , V_46 -> V_41 ) ;
} else {
F_29 ( V_60 L_7 ) ;
F_33 ( & V_6 , V_52 ) ;
F_33 ( & F_32 ( 0 ) , V_52 ) ;
F_24 (mod, &smp_alt_modules, next)
F_19 ( V_46 -> V_48 , V_46 -> V_49 ,
V_46 -> V_40 , V_46 -> V_41 ) ;
}
V_59 = V_51 ;
F_18 ( & V_54 ) ;
}
int F_34 ( void * V_24 , void * V_25 )
{
struct V_50 * V_46 ;
const V_39 * V_42 ;
T_3 * V_61 = V_24 ;
T_3 * V_41 = V_25 ;
F_24 (mod, &smp_alt_modules, next) {
if ( V_46 -> V_40 > V_41 || V_46 -> V_41 < V_61 )
continue;
for ( V_42 = V_46 -> V_48 ; V_42 < V_46 -> V_49 ; V_42 ++ ) {
const T_3 * V_44 = ( const T_3 * ) V_42 + * V_42 ;
if ( V_61 <= V_44 && V_41 > V_44 )
return 1 ;
}
}
return 0 ;
}
void T_2 F_35 ( struct V_62 * V_24 ,
struct V_62 * V_25 )
{
struct V_62 * V_63 ;
char V_27 [ V_28 ] ;
if ( V_5 )
return;
for ( V_63 = V_24 ; V_63 < V_25 ; V_63 ++ ) {
unsigned int V_64 ;
F_11 ( V_63 -> V_20 > V_28 ) ;
memcpy ( V_27 , V_63 -> V_30 , V_63 -> V_20 ) ;
V_64 = V_65 . V_66 ( V_63 -> V_67 , V_63 -> V_68 , V_27 ,
( unsigned long ) V_63 -> V_30 , V_63 -> V_20 ) ;
F_11 ( V_64 > V_63 -> V_20 ) ;
F_8 ( V_27 + V_64 , V_63 -> V_20 - V_64 ) ;
F_14 ( V_63 -> V_30 , V_27 , V_63 -> V_20 ) ;
}
}
void T_1 F_36 ( void )
{
F_37 () ;
F_9 ( V_69 , V_70 ) ;
#ifdef F_38
if ( F_39 () < 2 )
V_2 = 1 ;
#endif
#ifdef F_40
if ( V_2 ) {
if ( 1 == F_39 () ) {
F_29 ( V_60 L_7 ) ;
F_33 ( & V_6 , V_52 ) ;
F_33 ( & F_32 ( 0 ) , V_52 ) ;
F_19 ( V_71 , V_72 ,
V_73 , V_74 ) ;
}
} else {
F_20 ( NULL , L_8 ,
V_71 , V_72 ,
V_73 , V_74 ) ;
if ( F_41 () == 1 || V_75 <= 1 )
F_27 ( 0 ) ;
}
#endif
F_35 ( V_76 , V_77 ) ;
if ( V_2 )
F_42 ( L_9 ,
( unsigned long ) V_71 ,
( unsigned long ) V_72 ) ;
F_43 () ;
}
void * T_2 F_14 ( void * V_78 , const void * V_79 ,
T_4 V_20 )
{
unsigned long V_80 ;
F_44 ( V_80 ) ;
memcpy ( V_78 , V_79 , V_20 ) ;
F_45 () ;
F_46 ( V_80 ) ;
return V_78 ;
}
void * T_5 F_17 ( void * V_78 , const void * V_79 , T_4 V_20 )
{
unsigned long V_80 ;
char * V_81 ;
struct V_82 * V_83 [ 2 ] ;
int V_84 ;
if ( ! F_47 ( ( unsigned long ) V_78 ) ) {
V_83 [ 0 ] = F_48 ( V_78 ) ;
V_83 [ 1 ] = F_48 ( V_78 + V_85 ) ;
} else {
V_83 [ 0 ] = F_49 ( V_78 ) ;
F_50 ( ! F_51 ( V_83 [ 0 ] ) ) ;
V_83 [ 1 ] = F_49 ( V_78 + V_85 ) ;
}
F_11 ( ! V_83 [ 0 ] ) ;
F_44 ( V_80 ) ;
F_52 ( V_86 , F_53 ( V_83 [ 0 ] ) ) ;
if ( V_83 [ 1 ] )
F_52 ( V_87 , F_53 ( V_83 [ 1 ] ) ) ;
V_81 = ( char * ) F_54 ( V_86 ) ;
memcpy ( & V_81 [ ( unsigned long ) V_78 & ~ V_88 ] , V_79 , V_20 ) ;
F_55 ( V_86 ) ;
if ( V_83 [ 1 ] )
F_55 ( V_87 ) ;
F_56 () ;
F_45 () ;
for ( V_84 = 0 ; V_84 < V_20 ; V_84 ++ )
F_11 ( ( ( char * ) V_78 ) [ V_84 ] != ( ( char * ) V_79 ) [ V_84 ] ) ;
F_46 ( V_80 ) ;
return V_78 ;
}
static int T_5 F_57 ( void * V_89 )
{
struct V_90 * V_91 = V_89 ;
struct V_92 * V_63 ;
int V_84 ;
if ( F_58 ( & V_93 ) ) {
for ( V_84 = 0 ; V_84 < V_91 -> V_94 ; V_84 ++ ) {
V_63 = & V_91 -> V_95 [ V_84 ] ;
F_17 ( V_63 -> V_78 , V_63 -> V_79 , V_63 -> V_20 ) ;
}
F_59 () ;
V_96 = 1 ;
} else {
while ( ! V_96 )
F_60 () ;
F_61 () ;
}
for ( V_84 = 0 ; V_84 < V_91 -> V_94 ; V_84 ++ ) {
V_63 = & V_91 -> V_95 [ V_84 ] ;
F_62 ( ( unsigned long ) V_63 -> V_78 ,
( unsigned long ) V_63 -> V_78 + V_63 -> V_20 ) ;
}
F_45 () ;
return 0 ;
}
void * T_5 F_63 ( void * V_78 , const void * V_79 , T_4 V_20 )
{
struct V_90 V_91 ;
struct V_92 V_63 ;
V_63 . V_78 = V_78 ;
V_63 . V_79 = V_79 ;
V_63 . V_20 = V_20 ;
V_91 . V_95 = & V_63 ;
V_91 . V_94 = 1 ;
F_64 ( & V_93 , 1 ) ;
V_96 = 0 ;
F_65 ( F_57 , ( void * ) & V_91 , V_97 ) ;
return V_78 ;
}
void T_5 F_66 ( struct V_92 * V_95 , int V_98 )
{
struct V_90 V_91 = { . V_95 = V_95 , . V_94 = V_98 } ;
F_64 ( & V_93 , 1 ) ;
V_96 = 0 ;
F_65 ( F_57 , ( void * ) & V_91 , NULL ) ;
}
