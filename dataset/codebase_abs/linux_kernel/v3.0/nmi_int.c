T_1 F_1 ( struct V_1 const * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = 0 ;
T_2 V_6 = ( T_2 ) V_4 -> V_6 ;
V_5 |= V_7 ;
V_5 |= V_4 -> V_8 ? V_9 : 0 ;
V_5 |= V_4 -> V_10 ? V_11 : 0 ;
V_5 |= ( V_4 -> V_12 & 0xFF ) << 8 ;
V_4 -> V_13 &= ( V_14 |
V_15 |
V_16 ) ;
V_5 |= V_4 -> V_13 ;
V_6 &= V_2 -> V_17 ? V_2 -> V_17 : 0xFF ;
V_5 |= V_6 & 0xFF ;
V_5 |= ( V_6 & 0x0F00 ) << 24 ;
return V_5 ;
}
static int F_2 ( struct V_18 * V_19 ,
unsigned long V_5 , void * V_20 )
{
struct V_21 * args = (struct V_21 * ) V_20 ;
int V_22 = V_23 ;
switch ( V_5 ) {
case V_24 :
if ( V_25 )
V_2 -> V_26 ( args -> V_27 , & F_3 ( V_28 ) ) ;
else if ( ! V_29 )
break;
else
V_2 -> V_30 ( & F_3 ( V_28 ) ) ;
V_22 = V_31 ;
break;
default:
break;
}
return V_22 ;
}
static void F_4 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_35 ;
struct V_34 * V_36 = V_33 -> V_36 ;
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_38 ; ++ V_37 ) {
if ( V_35 [ V_37 ] . V_39 )
F_5 ( V_35 [ V_37 ] . V_39 , V_35 [ V_37 ] . V_40 ) ;
}
for ( V_37 = 0 ; V_37 < V_2 -> V_41 ; ++ V_37 ) {
if ( V_36 [ V_37 ] . V_39 )
F_5 ( V_36 [ V_37 ] . V_39 , V_36 [ V_37 ] . V_40 ) ;
}
}
static void F_6 ( void * V_42 )
{
struct V_32 const * V_33 = & F_3 ( V_28 ) ;
if ( ! V_33 -> V_36 )
F_7 ( 1 ) ;
else
V_2 -> V_43 ( V_33 ) ;
}
static int F_8 ( void )
{
F_9 () ;
V_25 = 1 ;
F_10 () ;
F_11 ( F_6 , NULL , 1 ) ;
F_12 () ;
return 0 ;
}
static void F_13 ( void * V_42 )
{
struct V_32 const * V_33 = & F_3 ( V_28 ) ;
if ( ! V_33 -> V_36 )
F_7 ( 1 ) ;
else
V_2 -> V_30 ( V_33 ) ;
}
static void F_14 ( void )
{
F_9 () ;
F_11 ( F_13 , NULL , 1 ) ;
V_25 = 0 ;
F_12 () ;
}
static inline int F_15 ( void )
{
return ! ! V_2 -> V_44 ;
}
inline int F_16 ( int V_45 )
{
return F_17 ( V_46 ) + V_45 ;
}
inline int F_18 ( int V_47 )
{
return V_47 % V_2 -> V_38 ;
}
static void F_19 ( void )
{
int V_37 ;
if ( ! F_15 () )
return;
F_20 (i) {
F_21 ( F_22 ( V_28 , V_37 ) . V_48 ) ;
F_22 ( V_28 , V_37 ) . V_48 = NULL ;
F_22 ( V_46 , V_37 ) = 0 ;
}
}
static int F_23 ( void )
{
T_3 V_49 =
sizeof( struct V_34 ) * V_2 -> V_50 ;
int V_37 ;
if ( ! F_15 () )
return 1 ;
F_20 (i) {
F_22 ( V_28 , V_37 ) . V_48 =
F_24 ( V_49 , V_51 ) ;
if ( ! F_22 ( V_28 , V_37 ) . V_48 )
return 0 ;
}
return 1 ;
}
static void F_25 ( int V_52 , struct V_32 const * const V_33 )
{
int V_37 ;
struct V_34 * V_48 = V_33 -> V_48 ;
if ( ! F_15 () )
return;
for ( V_37 = 0 ; V_37 < V_2 -> V_50 ; ++ V_37 ) {
if ( V_4 [ V_37 ] . V_53 ) {
V_48 [ V_37 ] . V_40 = - ( T_1 ) V_4 [ V_37 ] . V_54 ;
} else {
V_48 [ V_37 ] . V_40 = 0 ;
}
}
F_22 ( V_46 , V_52 ) = 0 ;
}
static void F_26 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_35 ;
struct V_34 * V_48 = V_33 -> V_48 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_38 ; ++ V_37 ) {
int V_47 = F_16 ( V_37 ) ;
if ( V_35 [ V_37 ] . V_39 )
F_5 ( V_35 [ V_37 ] . V_39 , V_48 [ V_47 ] . V_40 ) ;
}
}
static void F_27 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_35 ;
struct V_34 * V_48 = V_33 -> V_48 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_38 ; ++ V_37 ) {
int V_47 = F_16 ( V_37 ) ;
if ( V_35 [ V_37 ] . V_39 )
F_28 ( V_35 [ V_37 ] . V_39 , V_48 [ V_47 ] . V_40 ) ;
}
}
static void F_29 ( void * V_42 )
{
int V_52 = F_30 () ;
int V_55 = F_22 ( V_46 , V_52 ) ;
struct V_32 * V_33 = & F_22 ( V_28 , V_52 ) ;
F_13 ( NULL ) ;
F_26 ( V_33 ) ;
V_55 += V_2 -> V_38 ;
if ( ( V_55 >= V_2 -> V_50 ) || ( V_4 [ V_55 ] . V_54 == 0 ) )
F_22 ( V_46 , V_52 ) = 0 ;
else
F_22 ( V_46 , V_52 ) = V_55 ;
V_2 -> V_44 ( V_2 , V_33 ) ;
F_27 ( V_33 ) ;
F_6 ( NULL ) ;
}
static int F_31 ( void )
{
return V_4 [ V_2 -> V_38 ] . V_54 ? 0 : - V_56 ;
}
static int F_32 ( void )
{
if ( ! F_15 () )
return - V_57 ;
if ( F_31 () < 0 )
return - V_56 ;
F_9 () ;
if ( V_25 )
F_11 ( F_29 , NULL , 1 ) ;
F_12 () ;
return 0 ;
}
static inline void F_33 ( struct V_58 * V_59 )
{
if ( F_15 () )
V_59 -> V_60 = F_32 ;
}
static void F_34 ( int V_52 )
{
if ( ! F_15 () )
return;
memcpy ( F_22 ( V_28 , V_52 ) . V_48 ,
F_22 ( V_28 , 0 ) . V_48 ,
sizeof( struct V_34 ) * V_2 -> V_50 ) ;
}
inline int F_16 ( int V_45 ) { return V_45 ; }
inline int F_18 ( int V_47 ) { return V_47 ; }
static inline void F_19 ( void ) { }
static inline int F_23 ( void ) { return 1 ; }
static inline void
F_25 ( int V_52 , struct V_32 const * const V_33 ) { }
static inline void F_33 ( struct V_58 * V_59 ) { }
static void F_34 ( int V_52 ) { }
static void F_35 ( void )
{
int V_37 ;
F_20 (i) {
F_21 ( F_22 ( V_28 , V_37 ) . V_35 ) ;
F_22 ( V_28 , V_37 ) . V_35 = NULL ;
F_21 ( F_22 ( V_28 , V_37 ) . V_36 ) ;
F_22 ( V_28 , V_37 ) . V_36 = NULL ;
}
F_19 () ;
}
static int F_36 ( void )
{
T_3 V_61 = sizeof( struct V_34 ) * V_2 -> V_41 ;
T_3 V_62 = sizeof( struct V_34 ) * V_2 -> V_38 ;
int V_37 ;
F_20 (i) {
F_22 ( V_28 , V_37 ) . V_35 = F_24 ( V_62 ,
V_51 ) ;
if ( ! F_22 ( V_28 , V_37 ) . V_35 )
goto V_63;
F_22 ( V_28 , V_37 ) . V_36 = F_24 ( V_61 ,
V_51 ) ;
if ( ! F_22 ( V_28 , V_37 ) . V_36 )
goto V_63;
}
if ( ! F_23 () )
goto V_63;
return 1 ;
V_63:
F_35 () ;
return 0 ;
}
static void F_37 ( void * V_42 )
{
int V_52 = F_30 () ;
struct V_32 * V_33 = & F_22 ( V_28 , V_52 ) ;
F_4 ( V_33 ) ;
F_38 ( & V_64 ) ;
V_2 -> V_65 ( V_2 , V_33 ) ;
F_25 ( V_52 , V_33 ) ;
F_39 ( & V_64 ) ;
F_22 ( V_66 , V_52 ) = F_40 ( V_67 ) ;
F_41 ( V_67 , V_68 ) ;
}
static void F_42 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_35 ;
struct V_34 * V_36 = V_33 -> V_36 ;
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_41 ; ++ V_37 ) {
if ( V_36 [ V_37 ] . V_39 )
F_28 ( V_36 [ V_37 ] . V_39 , V_36 [ V_37 ] . V_40 ) ;
}
for ( V_37 = 0 ; V_37 < V_2 -> V_38 ; ++ V_37 ) {
if ( V_35 [ V_37 ] . V_39 )
F_28 ( V_35 [ V_37 ] . V_39 , V_35 [ V_37 ] . V_40 ) ;
}
}
static void F_43 ( void * V_42 )
{
unsigned int V_69 ;
int V_52 = F_30 () ;
struct V_32 * V_33 = & F_22 ( V_28 , V_52 ) ;
V_69 = F_40 ( V_70 ) ;
F_41 ( V_70 , V_69 | V_71 ) ;
F_41 ( V_67 , F_22 ( V_66 , V_52 ) ) ;
F_41 ( V_70 , V_69 ) ;
F_42 ( V_33 ) ;
if ( V_2 -> V_72 )
V_2 -> V_72 () ;
}
static void F_44 ( void * V_42 )
{
if ( V_29 )
F_37 ( V_42 ) ;
if ( V_25 )
F_6 ( V_42 ) ;
}
static void F_45 ( void * V_42 )
{
if ( V_25 )
F_13 ( V_42 ) ;
if ( V_29 )
F_43 ( V_42 ) ;
}
static int F_46 ( struct V_73 * V_74 , struct V_75 * V_76 )
{
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_50 ; ++ V_37 ) {
struct V_75 * V_77 ;
char V_78 [ 4 ] ;
if ( ! F_47 ( F_18 ( V_37 ) ) )
continue;
snprintf ( V_78 , sizeof( V_78 ) , L_1 , V_37 ) ;
V_77 = F_48 ( V_74 , V_76 , V_78 ) ;
F_49 ( V_74 , V_77 , L_2 , & V_4 [ V_37 ] . V_53 ) ;
F_49 ( V_74 , V_77 , L_3 , & V_4 [ V_37 ] . V_6 ) ;
F_49 ( V_74 , V_77 , L_4 , & V_4 [ V_37 ] . V_54 ) ;
F_49 ( V_74 , V_77 , L_5 , & V_4 [ V_37 ] . V_12 ) ;
F_49 ( V_74 , V_77 , L_6 , & V_4 [ V_37 ] . V_10 ) ;
F_49 ( V_74 , V_77 , L_7 , & V_4 [ V_37 ] . V_8 ) ;
F_49 ( V_74 , V_77 , L_8 , & V_4 [ V_37 ] . V_13 ) ;
}
return 0 ;
}
static int F_50 ( struct V_18 * V_79 , unsigned long V_80 ,
void * V_20 )
{
int V_52 = ( unsigned long ) V_20 ;
switch ( V_80 ) {
case V_81 :
case V_82 :
F_51 ( V_52 , F_44 , NULL , 0 ) ;
break;
case V_83 :
F_51 ( V_52 , F_45 , NULL , 1 ) ;
break;
}
return V_23 ;
}
static int F_52 ( void )
{
int V_84 = 0 ;
int V_52 ;
if ( ! F_36 () )
return - V_85 ;
V_84 = V_2 -> V_86 ( & F_22 ( V_28 , 0 ) ) ;
if ( V_84 )
goto V_63;
F_20 (cpu) {
if ( ! V_52 )
continue;
memcpy ( F_22 ( V_28 , V_52 ) . V_35 ,
F_22 ( V_28 , 0 ) . V_35 ,
sizeof( struct V_34 ) * V_2 -> V_38 ) ;
memcpy ( F_22 ( V_28 , V_52 ) . V_36 ,
F_22 ( V_28 , 0 ) . V_36 ,
sizeof( struct V_34 ) * V_2 -> V_41 ) ;
F_34 ( V_52 ) ;
}
V_29 = 0 ;
V_25 = 0 ;
F_10 () ;
V_84 = F_53 ( & V_87 ) ;
if ( V_84 )
goto V_63;
F_9 () ;
F_54 ( & V_88 ) ;
V_29 = 1 ;
F_10 () ;
F_11 ( F_37 , NULL , 1 ) ;
F_12 () ;
return 0 ;
V_63:
F_35 () ;
return V_84 ;
}
static void F_55 ( void )
{
struct V_32 * V_33 ;
F_9 () ;
F_56 ( & V_88 ) ;
F_11 ( F_43 , NULL , 1 ) ;
V_29 = 0 ;
V_25 = 0 ;
F_12 () ;
F_10 () ;
F_57 ( & V_87 ) ;
V_33 = & F_58 ( V_28 ) ;
V_2 -> V_89 ( V_33 ) ;
F_35 () ;
F_59 ( V_28 ) ;
}
static int F_60 ( void )
{
if ( V_29 == 1 )
F_13 ( NULL ) ;
return 0 ;
}
static void F_61 ( void )
{
if ( V_29 == 1 )
F_6 ( NULL ) ;
}
static void T_4 F_62 ( void )
{
F_63 ( & V_90 ) ;
}
static void F_64 ( void )
{
F_65 ( & V_90 ) ;
}
static inline void F_62 ( void ) { }
static inline void F_64 ( void ) { }
static int T_4 F_66 ( char * * V_91 )
{
T_5 V_92 = V_93 . V_94 ;
if ( V_92 > 6 || V_92 == 5 )
return 0 ;
#ifndef F_67
* V_91 = L_9 ;
V_2 = & V_95 ;
return 1 ;
#else
switch ( V_96 ) {
case 1 :
* V_91 = L_9 ;
V_2 = & V_95 ;
return 1 ;
case 2 :
* V_91 = L_10 ;
V_2 = & V_97 ;
return 1 ;
}
#endif
F_68 ( V_98 L_11 ) ;
F_68 ( V_98 L_12 ) ;
return 0 ;
}
static int F_69 ( const char * V_99 , struct V_100 * V_101 )
{
if ( ! strcmp ( V_99 , L_13 ) ) {
V_102 = 1 ;
F_68 ( V_98 L_14 ) ;
}
return 0 ;
}
static int T_4 F_70 ( char * * V_91 )
{
T_5 V_92 = V_93 . V_94 ;
struct V_1 * V_103 = & V_104 ;
if ( V_102 && V_105 )
return 0 ;
switch ( V_92 ) {
case 0 ... 2 :
* V_91 = L_15 ;
break;
case 3 ... 5 :
* V_91 = L_16 ;
break;
case 6 ... 8 :
case 10 ... 11 :
* V_91 = L_17 ;
break;
case 9 :
case 13 :
* V_91 = L_18 ;
break;
case 14 :
* V_91 = L_19 ;
break;
case 0x0f :
case 0x16 :
case 0x17 :
case 0x1d :
* V_91 = L_20 ;
break;
case 0x1a :
case 0x1e :
case 0x2e :
V_103 = & V_106 ;
* V_91 = L_21 ;
break;
case 0x1c :
* V_91 = L_22 ;
break;
default:
return 0 ;
}
V_2 = V_103 ;
return 1 ;
}
int T_4 F_71 ( struct V_58 * V_59 )
{
T_5 V_107 = V_93 . V_108 ;
T_5 V_109 = V_93 . V_110 ;
char * V_91 = NULL ;
int V_22 = 0 ;
if ( ! V_111 )
return - V_112 ;
switch ( V_107 ) {
case V_113 :
switch ( V_109 ) {
case 6 :
V_91 = L_23 ;
break;
case 0xf :
V_91 = L_24 ;
break;
case 0x10 :
V_91 = L_25 ;
break;
case 0x11 :
V_91 = L_26 ;
break;
case 0x12 :
V_91 = L_27 ;
break;
case 0x14 :
V_91 = L_28 ;
break;
case 0x15 :
V_91 = L_29 ;
break;
default:
return - V_112 ;
}
V_2 = & V_114 ;
break;
case V_115 :
switch ( V_109 ) {
case 0xf :
F_66 ( & V_91 ) ;
break;
case 6 :
F_70 ( & V_91 ) ;
break;
default:
break;
}
if ( V_91 )
break;
if ( ! V_105 )
return - V_112 ;
V_91 = L_30 ;
V_2 = & V_106 ;
break;
default:
return - V_112 ;
}
V_59 -> V_116 = F_46 ;
V_59 -> V_117 = F_52 ;
V_59 -> V_89 = F_55 ;
V_59 -> V_43 = F_8 ;
V_59 -> V_30 = F_14 ;
V_59 -> V_91 = V_91 ;
if ( V_2 -> V_118 )
V_22 = V_2 -> V_118 ( V_59 ) ;
if ( V_22 )
return V_22 ;
if ( ! V_2 -> V_50 )
V_2 -> V_50 = V_2 -> V_38 ;
F_33 ( V_59 ) ;
F_62 () ;
F_68 ( V_98 L_31 ) ;
return 0 ;
}
void F_72 ( void )
{
F_64 () ;
}
