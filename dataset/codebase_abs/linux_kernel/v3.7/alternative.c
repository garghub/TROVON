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
F_10 ( V_25 -> V_35 >= V_36 * 32 ) ;
if ( ! F_5 ( V_25 -> V_35 ) )
continue;
memcpy ( V_28 , V_27 , V_25 -> V_33 ) ;
if ( * V_28 == 0xe8 && V_25 -> V_33 == 5 )
* ( V_37 * ) ( V_28 + 1 ) += V_27 - V_26 ;
F_7 ( V_28 + V_25 -> V_33 ,
V_25 -> V_34 - V_25 -> V_33 ) ;
F_11 ( V_26 , V_28 , V_25 -> V_34 ) ;
}
}
static void F_12 ( const V_37 * V_23 , const V_37 * V_24 ,
T_3 * V_38 , T_3 * V_39 )
{
const V_37 * V_40 ;
F_13 ( & V_41 ) ;
for ( V_40 = V_23 ; V_40 < V_24 ; V_40 ++ ) {
T_3 * V_42 = ( T_3 * ) V_40 + * V_40 ;
if ( ! * V_40 || V_42 < V_38 || V_42 >= V_39 )
continue;
if ( * V_42 == 0x3e )
F_14 (ptr, ((unsigned char []){0xf0}), 1 ) ;
}
F_15 ( & V_41 ) ;
}
static void F_16 ( const V_37 * V_23 , const V_37 * V_24 ,
T_3 * V_38 , T_3 * V_39 )
{
const V_37 * V_40 ;
F_13 ( & V_41 ) ;
for ( V_40 = V_23 ; V_40 < V_24 ; V_40 ++ ) {
T_3 * V_42 = ( T_3 * ) V_40 + * V_40 ;
if ( ! * V_40 || V_42 < V_38 || V_42 >= V_39 )
continue;
if ( * V_42 == 0xf0 )
F_14 (ptr, ((unsigned char []){0x3E}), 1 ) ;
}
F_15 ( & V_41 ) ;
}
void T_2 F_17 ( struct V_43 * V_44 ,
char * V_45 ,
void * V_46 , void * V_47 ,
void * V_38 , void * V_39 )
{
struct V_48 * V_49 ;
F_13 ( & V_50 ) ;
if ( ! V_51 )
goto V_52;
if ( F_18 () == 1 )
goto V_53;
V_49 = F_19 ( sizeof( * V_49 ) , V_54 ) ;
if ( NULL == V_49 )
goto V_52;
V_49 -> V_44 = V_44 ;
V_49 -> V_45 = V_45 ;
V_49 -> V_46 = V_46 ;
V_49 -> V_47 = V_47 ;
V_49 -> V_38 = V_38 ;
V_49 -> V_39 = V_39 ;
F_9 ( L_2 ,
V_30 , V_49 -> V_46 , V_49 -> V_47 ,
V_49 -> V_38 , V_49 -> V_39 , V_49 -> V_45 ) ;
F_20 ( & V_49 -> V_55 , & V_56 ) ;
V_53:
F_16 ( V_46 , V_47 , V_38 , V_39 ) ;
V_52:
F_15 ( & V_50 ) ;
}
void T_2 F_21 ( struct V_43 * V_44 )
{
struct V_48 * V_57 ;
F_13 ( & V_50 ) ;
F_22 (item, &smp_alt_modules, next) {
if ( V_44 != V_57 -> V_44 )
continue;
F_23 ( & V_57 -> V_55 ) ;
F_24 ( V_57 ) ;
break;
}
F_15 ( & V_50 ) ;
}
void F_25 ( void )
{
struct V_48 * V_44 ;
#ifdef F_26
F_27 ( L_3 ) ;
#endif
F_10 ( F_18 () == 1 ) ;
F_13 ( & V_50 ) ;
if ( V_51 ) {
F_27 ( L_4 ) ;
F_10 ( F_28 () != 1 ) ;
F_29 ( & V_5 , V_58 ) ;
F_29 ( & F_30 ( 0 ) , V_58 ) ;
F_22 (mod, &smp_alt_modules, next)
F_12 ( V_44 -> V_46 , V_44 -> V_47 ,
V_44 -> V_38 , V_44 -> V_39 ) ;
V_51 = false ;
}
F_15 ( & V_50 ) ;
}
int F_31 ( void * V_23 , void * V_24 )
{
struct V_48 * V_44 ;
const V_37 * V_40 ;
T_3 * V_59 = V_23 ;
T_3 * V_39 = V_24 ;
F_22 (mod, &smp_alt_modules, next) {
if ( V_44 -> V_38 > V_39 || V_44 -> V_39 < V_59 )
continue;
for ( V_40 = V_44 -> V_46 ; V_40 < V_44 -> V_47 ; V_40 ++ ) {
const T_3 * V_42 = ( const T_3 * ) V_40 + * V_40 ;
if ( V_59 <= V_42 && V_39 > V_42 )
return 1 ;
}
}
return 0 ;
}
void T_2 F_32 ( struct V_60 * V_23 ,
struct V_60 * V_24 )
{
struct V_60 * V_61 ;
char V_28 [ V_29 ] ;
if ( V_4 )
return;
for ( V_61 = V_23 ; V_61 < V_24 ; V_61 ++ ) {
unsigned int V_62 ;
F_10 ( V_61 -> V_19 > V_29 ) ;
memcpy ( V_28 , V_61 -> V_26 , V_61 -> V_19 ) ;
V_62 = V_63 . V_64 ( V_61 -> V_65 , V_61 -> V_66 , V_28 ,
( unsigned long ) V_61 -> V_26 , V_61 -> V_19 ) ;
F_10 ( V_62 > V_61 -> V_19 ) ;
F_7 ( V_28 + V_62 , V_61 -> V_19 - V_62 ) ;
F_11 ( V_61 -> V_26 , V_28 , V_61 -> V_19 ) ;
}
}
void T_1 F_33 ( void )
{
F_34 () ;
F_8 ( V_67 , V_68 ) ;
#ifdef F_35
if ( ! V_3 && ( F_36 () == 1 || V_69 <= 1 ) ) {
V_51 = true ;
F_17 ( NULL , L_5 ,
V_70 , V_71 ,
V_72 , V_73 ) ;
}
if ( ! V_51 || F_18 () == 1 )
F_37 ( L_6 ,
( unsigned long ) V_70 ,
( unsigned long ) V_71 ) ;
#endif
F_32 ( V_74 , V_75 ) ;
F_38 () ;
}
void * T_2 F_11 ( void * V_76 , const void * V_77 ,
T_4 V_19 )
{
unsigned long V_78 ;
F_39 ( V_78 ) ;
memcpy ( V_76 , V_77 , V_19 ) ;
F_40 () ;
F_41 ( V_78 ) ;
return V_76 ;
}
void * T_5 F_14 ( void * V_76 , const void * V_77 , T_4 V_19 )
{
unsigned long V_78 ;
char * V_79 ;
struct V_80 * V_81 [ 2 ] ;
int V_82 ;
if ( ! F_42 ( ( unsigned long ) V_76 ) ) {
V_81 [ 0 ] = F_43 ( V_76 ) ;
V_81 [ 1 ] = F_43 ( V_76 + V_83 ) ;
} else {
V_81 [ 0 ] = F_44 ( V_76 ) ;
F_45 ( ! F_46 ( V_81 [ 0 ] ) ) ;
V_81 [ 1 ] = F_44 ( V_76 + V_83 ) ;
}
F_10 ( ! V_81 [ 0 ] ) ;
F_39 ( V_78 ) ;
F_47 ( V_84 , F_48 ( V_81 [ 0 ] ) ) ;
if ( V_81 [ 1 ] )
F_47 ( V_85 , F_48 ( V_81 [ 1 ] ) ) ;
V_79 = ( char * ) F_49 ( V_84 ) ;
memcpy ( & V_79 [ ( unsigned long ) V_76 & ~ V_86 ] , V_77 , V_19 ) ;
F_50 ( V_84 ) ;
if ( V_81 [ 1 ] )
F_50 ( V_85 ) ;
F_51 () ;
F_40 () ;
for ( V_82 = 0 ; V_82 < V_19 ; V_82 ++ )
F_10 ( ( ( char * ) V_76 ) [ V_82 ] != ( ( char * ) V_77 ) [ V_82 ] ) ;
F_41 ( V_78 ) ;
return V_76 ;
}
static int T_5 F_52 ( void * V_87 )
{
struct V_88 * V_89 = V_87 ;
struct V_90 * V_61 ;
int V_82 ;
if ( F_53 ( & V_91 , 0 ) ) {
for ( V_82 = 0 ; V_82 < V_89 -> V_92 ; V_82 ++ ) {
V_61 = & V_89 -> V_93 [ V_82 ] ;
F_14 ( V_61 -> V_76 , V_61 -> V_77 , V_61 -> V_19 ) ;
}
F_54 () ;
V_94 = 1 ;
} else {
while ( ! V_94 )
F_55 () ;
F_56 () ;
}
for ( V_82 = 0 ; V_82 < V_89 -> V_92 ; V_82 ++ ) {
V_61 = & V_89 -> V_93 [ V_82 ] ;
F_57 ( ( unsigned long ) V_61 -> V_76 ,
( unsigned long ) V_61 -> V_76 + V_61 -> V_19 ) ;
}
F_40 () ;
return 0 ;
}
void * T_5 F_58 ( void * V_76 , const void * V_77 , T_4 V_19 )
{
struct V_88 V_89 ;
struct V_90 V_61 ;
V_61 . V_76 = V_76 ;
V_61 . V_77 = V_77 ;
V_61 . V_19 = V_19 ;
V_89 . V_93 = & V_61 ;
V_89 . V_92 = 1 ;
F_59 ( & V_91 , 1 ) ;
V_94 = 0 ;
F_60 ( F_52 , ( void * ) & V_89 , V_95 ) ;
return V_76 ;
}
void T_5 F_61 ( struct V_90 * V_93 , int V_96 )
{
struct V_88 V_89 = { . V_93 = V_93 , . V_92 = V_96 } ;
F_59 ( & V_91 , 1 ) ;
V_94 = 0 ;
F_60 ( F_52 , ( void * ) & V_89 , V_95 ) ;
}
