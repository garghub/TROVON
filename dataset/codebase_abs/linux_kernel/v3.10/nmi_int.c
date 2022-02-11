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
V_5 |= ( T_1 ) ( V_6 & 0x0F00 ) << 24 ;
return V_5 ;
}
static int F_2 ( unsigned int V_5 , struct V_18 * V_19 )
{
if ( V_20 )
V_2 -> V_21 ( V_19 , & F_3 ( V_22 ) ) ;
else if ( ! V_23 )
return V_24 ;
else
V_2 -> V_25 ( & F_3 ( V_22 ) ) ;
return V_26 ;
}
static void F_4 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_30 ;
struct V_29 * V_31 = V_28 -> V_31 ;
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_33 ; ++ V_32 ) {
if ( V_30 [ V_32 ] . V_34 )
F_5 ( V_30 [ V_32 ] . V_34 , V_30 [ V_32 ] . V_35 ) ;
}
for ( V_32 = 0 ; V_32 < V_2 -> V_36 ; ++ V_32 ) {
if ( V_31 [ V_32 ] . V_34 )
F_5 ( V_31 [ V_32 ] . V_34 , V_31 [ V_32 ] . V_35 ) ;
}
}
static void F_6 ( void * V_37 )
{
struct V_27 const * V_28 = & F_3 ( V_22 ) ;
if ( ! V_28 -> V_31 )
F_7 ( 1 ) ;
else
V_2 -> V_38 ( V_28 ) ;
}
static int F_8 ( void )
{
F_9 () ;
V_20 = 1 ;
F_10 () ;
F_11 ( F_6 , NULL , 1 ) ;
F_12 () ;
return 0 ;
}
static void F_13 ( void * V_37 )
{
struct V_27 const * V_28 = & F_3 ( V_22 ) ;
if ( ! V_28 -> V_31 )
F_7 ( 1 ) ;
else
V_2 -> V_25 ( V_28 ) ;
}
static void F_14 ( void )
{
F_9 () ;
F_11 ( F_13 , NULL , 1 ) ;
V_20 = 0 ;
F_12 () ;
}
static inline int F_15 ( void )
{
return ! ! V_2 -> V_39 ;
}
inline int F_16 ( int V_40 )
{
return F_17 ( V_41 ) + V_40 ;
}
inline int F_18 ( int V_42 )
{
return V_42 % V_2 -> V_33 ;
}
static void F_19 ( void )
{
int V_32 ;
if ( ! F_15 () )
return;
F_20 (i) {
F_21 ( F_22 ( V_22 , V_32 ) . V_43 ) ;
F_22 ( V_22 , V_32 ) . V_43 = NULL ;
F_22 ( V_41 , V_32 ) = 0 ;
}
}
static int F_23 ( void )
{
T_3 V_44 =
sizeof( struct V_29 ) * V_2 -> V_45 ;
int V_32 ;
if ( ! F_15 () )
return 1 ;
F_20 (i) {
F_22 ( V_22 , V_32 ) . V_43 =
F_24 ( V_44 , V_46 ) ;
if ( ! F_22 ( V_22 , V_32 ) . V_43 )
return 0 ;
}
return 1 ;
}
static void F_25 ( int V_47 , struct V_27 const * const V_28 )
{
int V_32 ;
struct V_29 * V_43 = V_28 -> V_43 ;
if ( ! F_15 () )
return;
for ( V_32 = 0 ; V_32 < V_2 -> V_45 ; ++ V_32 ) {
if ( V_4 [ V_32 ] . V_48 ) {
V_43 [ V_32 ] . V_35 = - ( T_1 ) V_4 [ V_32 ] . V_49 ;
} else {
V_43 [ V_32 ] . V_35 = 0 ;
}
}
F_22 ( V_41 , V_47 ) = 0 ;
}
static void F_26 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_30 ;
struct V_29 * V_43 = V_28 -> V_43 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_33 ; ++ V_32 ) {
int V_42 = F_16 ( V_32 ) ;
if ( V_30 [ V_32 ] . V_34 )
F_5 ( V_30 [ V_32 ] . V_34 , V_43 [ V_42 ] . V_35 ) ;
}
}
static void F_27 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_30 ;
struct V_29 * V_43 = V_28 -> V_43 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_33 ; ++ V_32 ) {
int V_42 = F_16 ( V_32 ) ;
if ( V_30 [ V_32 ] . V_34 )
F_28 ( V_30 [ V_32 ] . V_34 , V_43 [ V_42 ] . V_35 ) ;
}
}
static void F_29 ( void * V_37 )
{
int V_47 = F_30 () ;
int V_50 = F_22 ( V_41 , V_47 ) ;
struct V_27 * V_28 = & F_22 ( V_22 , V_47 ) ;
F_13 ( NULL ) ;
F_26 ( V_28 ) ;
V_50 += V_2 -> V_33 ;
if ( ( V_50 >= V_2 -> V_45 ) || ( V_4 [ V_50 ] . V_49 == 0 ) )
F_22 ( V_41 , V_47 ) = 0 ;
else
F_22 ( V_41 , V_47 ) = V_50 ;
V_2 -> V_39 ( V_2 , V_28 ) ;
F_27 ( V_28 ) ;
F_6 ( NULL ) ;
}
static int F_31 ( void )
{
return V_4 [ V_2 -> V_33 ] . V_49 ? 0 : - V_51 ;
}
static int F_32 ( void )
{
if ( ! F_15 () )
return - V_52 ;
if ( F_31 () < 0 )
return - V_51 ;
F_9 () ;
if ( V_20 )
F_11 ( F_29 , NULL , 1 ) ;
F_12 () ;
return 0 ;
}
static inline void F_33 ( struct V_53 * V_54 )
{
if ( F_15 () )
V_54 -> V_55 = F_32 ;
}
static void F_34 ( int V_47 )
{
if ( ! F_15 () )
return;
memcpy ( F_22 ( V_22 , V_47 ) . V_43 ,
F_22 ( V_22 , 0 ) . V_43 ,
sizeof( struct V_29 ) * V_2 -> V_45 ) ;
}
inline int F_16 ( int V_40 ) { return V_40 ; }
inline int F_18 ( int V_42 ) { return V_42 ; }
static inline void F_19 ( void ) { }
static inline int F_23 ( void ) { return 1 ; }
static inline void
F_25 ( int V_47 , struct V_27 const * const V_28 ) { }
static inline void F_33 ( struct V_53 * V_54 ) { }
static void F_34 ( int V_47 ) { }
static void F_35 ( void )
{
int V_32 ;
F_20 (i) {
F_21 ( F_22 ( V_22 , V_32 ) . V_30 ) ;
F_22 ( V_22 , V_32 ) . V_30 = NULL ;
F_21 ( F_22 ( V_22 , V_32 ) . V_31 ) ;
F_22 ( V_22 , V_32 ) . V_31 = NULL ;
}
F_19 () ;
}
static int F_36 ( void )
{
T_3 V_56 = sizeof( struct V_29 ) * V_2 -> V_36 ;
T_3 V_57 = sizeof( struct V_29 ) * V_2 -> V_33 ;
int V_32 ;
F_20 (i) {
F_22 ( V_22 , V_32 ) . V_30 = F_24 ( V_57 ,
V_46 ) ;
if ( ! F_22 ( V_22 , V_32 ) . V_30 )
goto V_58;
F_22 ( V_22 , V_32 ) . V_31 = F_24 ( V_56 ,
V_46 ) ;
if ( ! F_22 ( V_22 , V_32 ) . V_31 )
goto V_58;
}
if ( ! F_23 () )
goto V_58;
return 1 ;
V_58:
F_35 () ;
return 0 ;
}
static void F_37 ( void * V_37 )
{
int V_47 = F_30 () ;
struct V_27 * V_28 = & F_22 ( V_22 , V_47 ) ;
F_4 ( V_28 ) ;
F_38 ( & V_59 ) ;
V_2 -> V_60 ( V_2 , V_28 ) ;
F_25 ( V_47 , V_28 ) ;
F_39 ( & V_59 ) ;
F_22 ( V_61 , V_47 ) = F_40 ( V_62 ) ;
F_41 ( V_62 , V_63 ) ;
}
static void F_42 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_30 ;
struct V_29 * V_31 = V_28 -> V_31 ;
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_36 ; ++ V_32 ) {
if ( V_31 [ V_32 ] . V_34 )
F_28 ( V_31 [ V_32 ] . V_34 , V_31 [ V_32 ] . V_35 ) ;
}
for ( V_32 = 0 ; V_32 < V_2 -> V_33 ; ++ V_32 ) {
if ( V_30 [ V_32 ] . V_34 )
F_28 ( V_30 [ V_32 ] . V_34 , V_30 [ V_32 ] . V_35 ) ;
}
}
static void F_43 ( void * V_37 )
{
unsigned int V_64 ;
int V_47 = F_30 () ;
struct V_27 * V_28 = & F_22 ( V_22 , V_47 ) ;
V_64 = F_40 ( V_65 ) ;
F_41 ( V_65 , V_64 | V_66 ) ;
F_41 ( V_62 , F_22 ( V_61 , V_47 ) ) ;
F_41 ( V_65 , V_64 ) ;
F_42 ( V_28 ) ;
}
static void F_44 ( void * V_37 )
{
if ( V_23 )
F_37 ( V_37 ) ;
if ( V_20 )
F_6 ( V_37 ) ;
}
static void F_45 ( void * V_37 )
{
if ( V_20 )
F_13 ( V_37 ) ;
if ( V_23 )
F_43 ( V_37 ) ;
}
static int F_46 ( struct V_67 * V_68 , struct V_69 * V_70 )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_45 ; ++ V_32 ) {
struct V_69 * V_71 ;
char V_72 [ 4 ] ;
if ( ! F_47 ( F_18 ( V_32 ) ) )
continue;
snprintf ( V_72 , sizeof( V_72 ) , L_1 , V_32 ) ;
V_71 = F_48 ( V_68 , V_70 , V_72 ) ;
F_49 ( V_68 , V_71 , L_2 , & V_4 [ V_32 ] . V_48 ) ;
F_49 ( V_68 , V_71 , L_3 , & V_4 [ V_32 ] . V_6 ) ;
F_49 ( V_68 , V_71 , L_4 , & V_4 [ V_32 ] . V_49 ) ;
F_49 ( V_68 , V_71 , L_5 , & V_4 [ V_32 ] . V_12 ) ;
F_49 ( V_68 , V_71 , L_6 , & V_4 [ V_32 ] . V_10 ) ;
F_49 ( V_68 , V_71 , L_7 , & V_4 [ V_32 ] . V_8 ) ;
F_49 ( V_68 , V_71 , L_8 , & V_4 [ V_32 ] . V_13 ) ;
}
return 0 ;
}
static int F_50 ( struct V_73 * V_74 , unsigned long V_75 ,
void * V_76 )
{
int V_47 = ( unsigned long ) V_76 ;
switch ( V_75 ) {
case V_77 :
case V_78 :
F_51 ( V_47 , F_44 , NULL , 0 ) ;
break;
case V_79 :
F_51 ( V_47 , F_45 , NULL , 1 ) ;
break;
}
return V_80 ;
}
static int F_52 ( void )
{
int V_81 = 0 ;
int V_47 ;
if ( ! F_36 () )
return - V_82 ;
V_81 = V_2 -> V_83 ( & F_22 ( V_22 , 0 ) ) ;
if ( V_81 )
goto V_58;
F_20 (cpu) {
if ( ! V_47 )
continue;
memcpy ( F_22 ( V_22 , V_47 ) . V_30 ,
F_22 ( V_22 , 0 ) . V_30 ,
sizeof( struct V_29 ) * V_2 -> V_33 ) ;
memcpy ( F_22 ( V_22 , V_47 ) . V_31 ,
F_22 ( V_22 , 0 ) . V_31 ,
sizeof( struct V_29 ) * V_2 -> V_36 ) ;
F_34 ( V_47 ) ;
}
V_23 = 0 ;
V_20 = 0 ;
F_10 () ;
V_81 = F_53 ( V_84 , F_2 ,
0 , L_9 ) ;
if ( V_81 )
goto V_58;
F_9 () ;
F_54 ( & V_85 ) ;
V_23 = 1 ;
F_10 () ;
F_11 ( F_37 , NULL , 1 ) ;
F_12 () ;
return 0 ;
V_58:
F_35 () ;
return V_81 ;
}
static void F_55 ( void )
{
struct V_27 * V_28 ;
F_9 () ;
F_56 ( & V_85 ) ;
F_11 ( F_43 , NULL , 1 ) ;
V_23 = 0 ;
V_20 = 0 ;
F_12 () ;
F_10 () ;
F_57 ( V_84 , L_9 ) ;
V_28 = & F_58 ( V_22 ) ;
V_2 -> V_86 ( V_28 ) ;
F_35 () ;
F_59 ( V_22 ) ;
}
static int F_60 ( void )
{
if ( V_23 == 1 )
F_13 ( NULL ) ;
return 0 ;
}
static void F_61 ( void )
{
if ( V_23 == 1 )
F_6 ( NULL ) ;
}
static void T_4 F_62 ( void )
{
F_63 ( & V_87 ) ;
}
static void F_64 ( void )
{
F_65 ( & V_87 ) ;
}
static inline void F_62 ( void ) { }
static inline void F_64 ( void ) { }
static int T_4 F_66 ( char * * V_88 )
{
T_5 V_89 = V_90 . V_91 ;
if ( V_89 > 6 || V_89 == 5 )
return 0 ;
#ifndef F_67
* V_88 = L_10 ;
V_2 = & V_92 ;
return 1 ;
#else
switch ( V_93 ) {
case 1 :
* V_88 = L_10 ;
V_2 = & V_92 ;
return 1 ;
case 2 :
* V_88 = L_11 ;
V_2 = & V_94 ;
return 1 ;
}
#endif
F_68 ( V_95 L_12 ) ;
F_68 ( V_95 L_13 ) ;
return 0 ;
}
static int F_69 ( const char * V_96 , struct V_97 * V_98 )
{
if ( ! strcmp ( V_96 , L_14 ) ) {
V_99 = V_100 ;
F_68 ( V_95 L_15 ) ;
} else if ( ! strcmp ( V_96 , L_16 ) ) {
V_99 = V_101 ;
F_68 ( V_95 L_17 ) ;
} else {
V_99 = 0 ;
}
return 0 ;
}
static int T_4 F_70 ( char * * V_88 )
{
T_5 V_89 = V_90 . V_91 ;
struct V_1 * V_102 = & V_103 ;
if ( V_99 == V_101 && V_104 )
return 0 ;
switch ( V_89 ) {
case 0 ... 2 :
* V_88 = L_18 ;
break;
case 3 ... 5 :
* V_88 = L_19 ;
break;
case 6 ... 8 :
case 10 ... 11 :
* V_88 = L_20 ;
break;
case 9 :
case 13 :
* V_88 = L_21 ;
break;
case 14 :
* V_88 = L_22 ;
break;
case 0x0f :
case 0x16 :
case 0x17 :
case 0x1d :
* V_88 = L_23 ;
break;
case 0x1a :
case 0x1e :
case 0x2e :
V_102 = & V_105 ;
* V_88 = L_24 ;
break;
case 0x1c :
* V_88 = L_25 ;
break;
default:
return 0 ;
}
V_2 = V_102 ;
return 1 ;
}
int T_4 F_71 ( struct V_53 * V_54 )
{
T_5 V_106 = V_90 . V_107 ;
T_5 V_108 = V_90 . V_109 ;
char * V_88 = NULL ;
int V_110 = 0 ;
if ( ! V_111 )
return - V_112 ;
if ( V_99 == V_100 )
return - V_112 ;
switch ( V_106 ) {
case V_113 :
switch ( V_108 ) {
case 6 :
V_88 = L_26 ;
break;
case 0xf :
V_88 = L_27 ;
break;
case 0x10 :
V_88 = L_28 ;
break;
case 0x11 :
V_88 = L_29 ;
break;
case 0x12 :
V_88 = L_30 ;
break;
case 0x14 :
V_88 = L_31 ;
break;
case 0x15 :
V_88 = L_32 ;
break;
default:
return - V_112 ;
}
V_2 = & V_114 ;
break;
case V_115 :
switch ( V_108 ) {
case 0xf :
F_66 ( & V_88 ) ;
break;
case 6 :
F_70 ( & V_88 ) ;
break;
default:
break;
}
if ( V_88 )
break;
if ( ! V_104 )
return - V_112 ;
V_88 = L_33 ;
V_2 = & V_105 ;
break;
default:
return - V_112 ;
}
V_54 -> V_116 = F_46 ;
V_54 -> V_117 = F_52 ;
V_54 -> V_86 = F_55 ;
V_54 -> V_38 = F_8 ;
V_54 -> V_25 = F_14 ;
V_54 -> V_88 = V_88 ;
if ( V_2 -> V_118 )
V_110 = V_2 -> V_118 ( V_54 ) ;
if ( V_110 )
return V_110 ;
if ( ! V_2 -> V_45 )
V_2 -> V_45 = V_2 -> V_33 ;
F_33 ( V_54 ) ;
F_62 () ;
F_68 ( V_95 L_34 ) ;
return 0 ;
}
void F_72 ( void )
{
F_64 () ;
}
