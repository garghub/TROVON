static inline T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
T_2 V_5 )
{
V_3 = ( 1ull << 63 ) | ( V_3 + V_4 ) ;
switch ( V_5 ) {
case 4 :
return F_2 ( V_2 , V_3 ) ;
case 8 :
return F_3 ( V_2 , V_3 ) ;
default:
return 0 ;
}
}
static void F_4 ( struct V_1 * V_2 ,
T_1 V_6 ,
char * V_7 ,
T_2 V_8 )
{
V_6 += F_5 ( struct V_9 , V_10 ) ;
F_6 ( V_2 , V_6 , ( V_11 * ) V_7 , V_8 ) ;
V_7 [ V_8 ] = 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_2 V_12 )
{
T_2 V_13 ;
T_2 V_14 ;
if ( ! V_2 -> V_15 )
V_2 -> V_15 =
F_3 ( V_2 ,
V_16 ) ;
V_13 = ( T_2 ) F_1 (
V_2 , V_2 -> V_15 ,
F_5 ( struct V_17 , V_13 ) ,
F_8 ( struct V_17 , V_13 ) ) ;
V_14 = ( T_2 ) F_1 (
V_2 , V_2 -> V_15 ,
F_5 ( struct V_17 , V_14 ) ,
F_8 ( struct V_17 , V_14 ) ) ;
F_9 ( & V_2 -> V_18 -> V_19 , L_1 , V_20 ,
V_13 ) ;
if ( ( V_13 > 3 ) ||
( V_12 && V_13 != V_12 ) ) {
F_10 ( & V_2 -> V_18 -> V_19 , L_2 ,
V_13 , V_14 ,
( long long ) V_2 -> V_15 ) ;
return - 1 ;
} else {
return 0 ;
}
}
static const struct V_9
* F_11 ( struct V_1 * V_2 ,
const char * V_10 , T_2 V_21 )
{
struct V_9 * V_22 =
& V_2 -> V_23 ;
T_1 V_24 = F_12 ( V_2 , V_10 , V_21 ) ;
if ( V_24 ) {
V_22 -> V_25 = F_1 (
V_2 , V_24 ,
F_5 ( struct V_9 ,
V_25 ) ,
F_8 (
struct V_9 ,
V_25 ) ) ;
V_22 -> V_5 = F_1 ( V_2 , V_24 ,
F_5 ( struct V_9 ,
V_5 ) ,
F_8 (
struct V_9 ,
V_5 ) ) ;
strncpy ( V_22 -> V_10 , V_10 , sizeof( V_22 -> V_10 ) ) ;
V_22 -> V_10 [ sizeof( V_22 -> V_10 ) - 1 ] = 0 ;
return & V_2 -> V_23 ;
} else {
return NULL ;
}
}
static T_1 F_12 ( struct V_1 * V_2 ,
const char * V_10 ,
T_2 V_21 )
{
T_1 V_26 = 0 ;
if ( ! F_7 ( V_2 , 3 ) ) {
T_2 V_27 ;
T_1 V_28 = F_1 (
V_2 , V_2 -> V_15 ,
F_5 ( struct V_17 ,
V_28 ) ,
F_8 ( struct V_17 ,
V_28 ) ) ;
T_2 V_29 = ( T_2 ) F_1 (
V_2 , V_2 -> V_15 ,
F_5 ( struct V_17 ,
V_30 ) ,
F_8 ( struct V_17 ,
V_30 ) ) ;
T_2 V_31 = ( T_2 ) F_1 (
V_2 , V_2 -> V_15 ,
F_5 ( struct V_17 ,
V_32 ) ,
F_8 ( struct V_17 ,
V_32 ) ) ;
T_1 V_24 = V_28 ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
T_1 V_33 = F_1 (
V_2 , V_24 ,
F_5 (
struct V_9 ,
V_5 ) ,
F_8 (
struct V_9 ,
V_5 ) ) ;
if ( V_10 && V_33 ) {
char * V_34 =
F_13 ( V_31 + 1 , V_35 ) ;
if ( ! V_34 )
break;
F_4 ( V_2 , V_24 ,
V_34 ,
V_31 ) ;
if ( ! strncmp ( V_10 , V_34 , V_31 ) ) {
V_26 = V_24 ;
F_14 ( V_34 ) ;
break;
}
F_14 ( V_34 ) ;
} else if ( ! V_10 && ! V_33 ) {
V_26 = V_24 ;
break;
}
V_24 +=
sizeof( struct V_9 ) ;
}
}
return V_26 ;
}
static int F_15 ( struct V_1 * V_2 , const char * V_10 ,
T_1 * V_25 , T_1 * V_5 )
{
const struct V_9 * V_36 ;
F_16 () ;
V_36 = F_11 ( V_2 , V_10 , 0 ) ;
F_17 () ;
if ( V_36 ) {
* V_25 = V_36 -> V_25 ;
* V_5 = V_36 -> V_5 ;
return 0 ;
}
return 1 ;
}
static void F_16 ( void )
{
}
static void F_17 ( void )
{
}
int F_18 ( struct V_1 * V_2 , char * V_37 ,
T_2 V_38 )
{
T_2 V_8 = ( T_2 ) strlen ( V_37 ) ;
F_9 ( & V_2 -> V_18 -> V_19 , L_3 , V_37 ) ;
if ( V_8 > V_39 - 1 ) {
F_10 ( & V_2 -> V_18 -> V_19 , L_4 ,
V_39 - 1 ) ;
return - 1 ;
}
if ( F_19 ( V_2 , V_38 ) != 0 ) {
F_10 ( & V_2 -> V_18 -> V_19 , L_5 ) ;
return - 1 ;
}
F_16 () ;
F_20 ( V_2 , V_40 ,
( V_11 * ) V_37 , V_8 ) ;
F_21 ( V_2 , V_41 ,
V_8 ) ;
F_21 ( V_2 , V_42 ,
V_43 ) ;
if ( F_19 ( V_2 , 200 ) != 0 ) {
F_17 () ;
F_10 ( & V_2 -> V_18 -> V_19 , L_6 ) ;
return - 1 ;
}
F_17 () ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 ,
T_2 V_44 )
{
F_9 ( & V_2 -> V_18 -> V_19 , L_7 ,
V_44 ) ;
if ( F_22 ( V_2 ) )
return - 1 ;
while ( V_44 > 0 &&
F_2 ( V_2 ,
V_42 )
!= V_45 ) {
if ( -- V_44 <= 0 )
return - 1 ;
F_23 ( V_46 / 100 ) ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
T_3 V_47 )
{
struct V_48 * V_49 ;
V_49 = & V_2 -> V_49 [ V_47 ] ;
V_49 -> V_50 = 0 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
T_3 V_47 ,
char * V_51 ,
T_4 V_52 )
{
char * line ;
T_4 V_27 ;
T_3 V_8 ;
line = V_51 ;
for ( V_27 = 0 ; V_27 < V_52 ; V_27 ++ ) {
if ( V_51 [ V_27 ] == '\n' ) {
V_51 [ V_27 ] = '\0' ;
if ( V_49 -> V_53 [ 0 ] &&
( line != V_49 -> V_53 ) ) {
if ( V_49 -> V_54 )
(* V_49 -> V_54 )( V_2 , ( T_2 ) V_47 ,
V_49 -> V_53 ,
line ) ;
V_49 -> V_53 [ 0 ] = '\0' ;
} else {
if ( V_49 -> V_54 )
(* V_49 -> V_54 )( V_2 , ( T_2 ) V_47 ,
line , NULL ) ;
}
line = & V_51 [ V_27 + 1 ] ;
}
}
if ( line != & V_51 [ V_52 ] ) {
V_51 [ V_52 ] = '\0' ;
V_8 = strlen ( V_49 -> V_53 ) ;
strncpy ( & V_49 -> V_53 [ V_8 ] , line ,
sizeof( V_49 -> V_53 ) - V_8 ) ;
}
}
static void F_26 ( struct V_55 * V_56 )
{
T_4 V_52 , V_57 , V_58 ;
T_3 V_8 ;
struct V_48 * V_49 ;
struct V_59 * V_60 = (struct V_59 * ) V_56 ;
struct V_1 * V_2 = (struct V_1 * ) V_60 -> V_61 ;
T_2 V_47 = ( T_2 ) V_60 -> V_62 ;
T_2 V_63 ;
V_49 = & V_2 -> V_49 [ V_47 ] ;
V_57 = 0 ;
V_58 = 0 ;
do {
V_52 =
F_27 ( V_2 , V_47 , V_51 ,
sizeof( V_51 ) - 1 ) ;
if ( V_52 > 0 ) {
V_58 += V_52 ;
if ( V_49 -> V_50 )
F_24 ( V_2 , V_47 ) ;
if ( V_49 -> V_54 ) {
F_25 ( V_2 , V_49 , V_47 ,
V_51 , V_52 ) ;
}
} else if ( V_52 < 0 ) {
F_10 ( & V_2 -> V_18 -> V_19 , L_8 ,
V_47 , V_52 ) ;
}
V_57 ++ ;
} while ( ( V_52 > 0 ) && ( V_57 < 16 ) );
if ( V_49 -> V_54 && ( V_58 == 0 ) &&
( V_49 -> V_53 [ 0 ] ) ) {
V_8 = strlen ( V_49 -> V_53 ) ;
V_49 -> V_53 [ V_8 ] = '\n' ;
F_25 ( V_2 , V_49 , V_47 ,
V_49 -> V_53 , ( T_4 ) ( V_8 + 1 ) ) ;
V_49 -> V_53 [ 0 ] = '\0' ;
}
V_63 = V_64 ;
F_28 ( & V_60 -> V_56 , F_29 ( V_63 ) ) ;
}
int F_30 ( struct V_1 * V_2 )
{
int V_65 = 0 ;
T_1 V_6 , V_5 ;
V_65 = F_22 ( V_2 ) ;
if ( V_65 ) {
F_10 ( & V_2 -> V_18 -> V_19 , L_9 ) ;
return V_65 ;
}
V_65 = F_15 ( V_2 , V_66 , & V_6 ,
& V_5 ) ;
if ( V_65 ) {
F_10 ( & V_2 -> V_18 -> V_19 , L_10 ,
V_66 ) ;
return V_65 ;
}
V_2 -> V_67 . V_68 = V_69 ;
V_2 -> V_70 . V_71 ( V_2 , V_6 , V_2 -> V_67 . V_68 ,
true ) ;
V_2 -> V_67 . V_72 = V_6
& ~ ( V_73 - 1ULL ) ;
V_2 -> V_74 = F_2 ( V_2 ,
V_6 + F_5 ( struct V_75 ,
V_74 ) ) ;
V_2 -> V_76 = V_6 ;
F_9 ( & V_2 -> V_18 -> V_19 , L_11 ,
V_2 -> V_74 ) ;
return V_65 ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_4 V_52 , V_57 , V_58 ;
struct V_48 * V_49 ;
T_2 V_47 = 0 ;
char * V_77 ;
char * V_78 ;
char * V_79 ;
#define F_32 512
V_78 = F_13 ( F_32 , V_35 ) ;
if ( ! V_78 )
return;
if ( F_18 ( V_2 , L_12 , 50 ) ) {
F_14 ( V_78 ) ;
return;
}
if ( F_18 ( V_2 , L_13 , 1 ) ) {
F_14 ( V_78 ) ;
return;
}
V_49 = & V_2 -> V_49 [ V_47 ] ;
V_57 = 0 ;
V_58 = 0 ;
do {
V_52 =
F_27 ( V_2 ,
V_47 , V_78 + V_58 ,
F_32 - 1 -
V_58 ) ;
if ( V_52 > 0 ) {
V_78 [ V_52 ] = '\0' ;
V_58 += V_52 ;
if ( V_49 -> V_50 )
F_24 ( V_2 , V_47 ) ;
} else if ( V_52 < 0 ) {
F_10 ( & V_2 -> V_18 -> V_19 , L_8 ,
V_47 , V_52 ) ;
}
V_57 ++ ;
} while ( ( V_52 > 0 ) && ( V_57 < 16 ) );
if ( ( V_58 == 0 ) && ( V_49 -> V_53 [ 0 ] ) ) {
F_9 ( & V_2 -> V_18 -> V_19 , L_14 ,
V_47 , V_49 -> V_53 ) ;
V_49 -> V_53 [ 0 ] = '\0' ;
}
V_78 [ F_32 - 1 ] = '\0' ;
V_77 = strstr ( V_78 , L_15 ) ;
if ( V_77 ) {
V_79 = strstr ( V_77 , L_16 ) ;
if ( V_79 ) {
V_79 -- ;
* V_79 = '\0' ;
F_33 ( & V_2 -> V_18 -> V_19 , L_17 , V_77 ) ;
}
}
F_14 ( V_78 ) ;
F_18 ( V_2 , L_18 , 50 ) ;
}
int F_34 ( struct V_1 * V_2 , T_2 V_47 ,
char * V_80 )
{
int V_65 = 0 ;
T_2 V_63 ;
T_1 V_81 ;
struct V_82 * V_56 ;
struct V_48 * V_49 ;
if ( V_47 >= V_2 -> V_74 ) {
F_10 ( & V_2 -> V_18 -> V_19 ,
L_19 ,
V_47 , V_2 -> V_74 ) ;
} else {
V_49 = & V_2 -> V_49 [ V_47 ] ;
V_49 -> V_50 = 0 ;
V_81 = V_2 -> V_76 + V_47 * 8 +
F_5 ( struct V_75 ,
V_83 ) ;
V_49 -> V_6 = F_3 ( V_2 , V_81 ) ;
V_81 = V_49 -> V_6 + F_5 ( struct V_84 ,
V_85 ) ;
V_49 -> V_86 = F_2 ( V_2 , V_81 ) ;
V_81 = V_49 -> V_6 + F_5 ( struct V_84 ,
V_87 ) ;
V_49 -> V_87 =
F_3 ( V_2 , V_81 ) ;
V_81 = V_49 -> V_6 + F_5 ( struct V_84 ,
V_88 ) ;
V_49 -> V_88 =
F_3 ( V_2 , V_81 ) ;
V_49 -> V_53 [ 0 ] = '\0' ;
V_56 = & V_2 -> V_89 [ V_47 ] . V_56 ;
F_31 ( V_2 ) ;
F_35 ( V_56 , F_26 ) ;
V_2 -> V_89 [ V_47 ] . V_61 = ( void * ) V_2 ;
V_2 -> V_89 [ V_47 ] . V_62 = V_47 ;
V_63 = V_64 ;
F_28 ( V_56 , F_29 ( V_63 ) ) ;
if ( V_80 && ! V_80 [ 0 ] )
V_80 = L_20 ;
if ( V_80 )
V_65 = F_18 ( V_2 , V_80 , 2000 ) ;
V_49 -> V_90 = 1 ;
}
return V_65 ;
}
void F_36 ( struct V_1 * V_2 )
{
T_2 V_27 ;
struct V_48 * V_49 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_74 ; V_27 ++ ) {
V_49 = & V_2 -> V_49 [ V_27 ] ;
if ( ! V_49 -> V_90 )
continue;
F_37 ( & V_2 -> V_89 [ V_27 ] .
V_56 ) ;
V_49 -> V_6 = 0 ;
V_49 -> V_86 = 0 ;
V_49 -> V_87 = 0 ;
V_49 -> V_88 = 0 ;
}
V_2 -> V_74 = 0 ;
}
static inline int F_38 ( T_2 V_86 ,
T_2 V_91 ,
T_2 V_92 )
{
if ( V_92 >= V_86 || V_91 >= V_86 )
return - 1 ;
return ( ( V_86 - 1 ) - ( V_91 - V_92 ) ) % V_86 ;
}
static inline int F_39 ( T_2 V_86 ,
T_2 V_91 ,
T_2 V_92 )
{
if ( V_92 >= V_86 || V_91 >= V_86 )
return - 1 ;
return V_86 - 1 -
F_38 ( V_86 , V_91 , V_92 ) ;
}
static int F_27 ( struct V_1 * V_2 , T_2 V_47 ,
char * V_93 , T_2 V_85 )
{
int V_94 ;
T_2 V_92 , V_91 ;
struct V_48 * V_49 ;
if ( V_47 >= V_2 -> V_74 ) {
F_10 ( & V_2 -> V_18 -> V_19 , L_21 ,
V_47 ) ;
return 0 ;
}
V_49 = & V_2 -> V_49 [ V_47 ] ;
V_92 = F_2 ( V_2 , V_49 -> V_6 +
F_5 ( struct V_84 , V_95 ) ) ;
V_91 = F_2 ( V_2 , V_49 -> V_6 +
F_5 ( struct V_84 , V_96 ) ) ;
V_94 = F_39 ( V_49 -> V_86 ,
V_91 , V_92 ) ;
if ( V_94 <= 0 )
return V_94 ;
V_94 = F_40 ( T_4 , V_94 , V_85 ) ;
if ( V_92 + V_94 >= V_49 -> V_86 )
V_94 = V_49 -> V_86 - V_92 ;
F_6 ( V_2 , V_49 -> V_88 + V_92 ,
( V_11 * ) V_93 , V_94 ) ;
F_21 ( V_2 , V_49 -> V_6 +
F_5 ( struct V_84 ,
V_95 ) ,
( V_92 + V_94 ) %
V_49 -> V_86 ) ;
return V_94 ;
}
int F_41 ( struct V_1 * V_2 , const V_11 * V_97 ,
T_3 V_5 )
{
int V_65 = 0 ;
T_2 V_98 ;
T_1 V_99 ;
T_2 V_100 ;
struct V_101 * V_102 ;
T_2 V_27 , V_103 ;
if ( V_5 < sizeof( struct V_101 ) ) {
F_10 ( & V_2 -> V_18 -> V_19 , L_22 ,
( T_2 ) V_5 ,
( T_2 ) sizeof( struct V_101 ) ) ;
return - V_104 ;
}
V_102 = (struct V_101 * ) V_97 ;
if ( F_42 ( V_102 -> V_105 ) != V_106 ) {
F_10 ( & V_2 -> V_18 -> V_19 , L_23 ) ;
return - V_104 ;
}
V_98 = F_43 ( ( unsigned int ) ~ 0 , V_97 ,
sizeof( struct V_101 ) -
sizeof( T_2 ) ) ^ ~ 0U ;
if ( V_98 != F_42 ( V_102 -> F_43 ) ) {
F_10 ( & V_2 -> V_18 -> V_19 , L_24 ,
V_98 , F_42 ( V_102 -> F_43 ) ) ;
return - V_104 ;
}
if ( strncmp ( V_107 , V_102 -> V_108 , strlen ( V_107 ) ) ) {
F_10 ( & V_2 -> V_18 -> V_19 , L_25 ,
V_107 , V_102 -> V_108 ) ;
return - V_104 ;
}
if ( memcmp ( V_109 , V_102 -> V_108 + strlen ( V_107 ) ,
strlen ( V_109 ) ) ) {
F_10 ( & V_2 -> V_18 -> V_19 , L_26 ,
V_109 ,
V_102 -> V_108 + strlen ( V_107 ) ) ;
return - V_104 ;
}
if ( F_42 ( V_102 -> V_110 ) > V_111 ) {
F_10 ( & V_2 -> V_18 -> V_19 , L_27 ,
F_42 ( V_102 -> V_110 ) ) ;
return - V_104 ;
}
F_33 ( & V_2 -> V_18 -> V_19 , L_28 , V_102 -> V_108 ) ;
snprintf ( V_2 -> V_112 . V_113 , 32 , L_29 ,
V_102 -> V_108 ) ;
V_97 += sizeof( struct V_101 ) ;
F_33 ( & V_2 -> V_18 -> V_19 , L_30 , V_20 ,
F_42 ( V_102 -> V_110 ) ) ;
for ( V_27 = 0 ; V_27 < F_42 ( V_102 -> V_110 ) ; V_27 ++ ) {
V_99 = F_44 ( V_102 -> V_22 [ V_27 ] . V_6 ) ;
V_100 = F_42 ( V_102 -> V_22 [ V_27 ] . V_8 ) ;
F_33 ( & V_2 -> V_18 -> V_19 , L_31 ,
V_100 , V_99 ) ;
V_103 = V_100 ;
while ( V_103 ) {
if ( V_103 < V_114 )
V_5 = V_103 ;
else
V_5 = V_114 ;
F_20 ( V_2 , V_99 , V_97 , ( T_2 ) V_5 ) ;
V_97 += V_5 ;
V_103 -= ( T_2 ) V_5 ;
V_99 += V_5 ;
}
}
F_33 ( & V_2 -> V_18 -> V_19 , L_32 ,
V_102 -> V_115 ) ;
V_65 = F_18 ( V_2 , V_102 -> V_115 , 50 ) ;
return 0 ;
}
