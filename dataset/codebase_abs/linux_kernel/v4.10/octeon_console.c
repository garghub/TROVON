static int F_1 ( T_1 V_1 )
{
return ( V_2 >> ( V_1 ) ) & 0x1 ;
}
static inline T_2 F_2 ( struct V_3 * V_4 ,
T_2 V_5 ,
T_1 V_6 ,
T_1 V_7 )
{
V_5 = ( 1ull << 63 ) | ( V_5 + V_6 ) ;
switch ( V_7 ) {
case 4 :
return F_3 ( V_4 , V_5 ) ;
case 8 :
return F_4 ( V_4 , V_5 ) ;
default:
return 0 ;
}
}
static void F_5 ( struct V_3 * V_4 ,
T_2 V_8 ,
char * V_9 ,
T_1 V_10 )
{
V_8 += F_6 ( struct V_11 , V_12 ) ;
F_7 ( V_4 , V_8 , ( V_13 * ) V_9 , V_10 ) ;
V_9 [ V_10 ] = 0 ;
}
static int F_8 ( struct V_3 * V_4 ,
T_1 V_14 )
{
T_1 V_15 ;
T_1 V_16 ;
if ( ! V_4 -> V_17 )
V_4 -> V_17 =
F_4 ( V_4 ,
V_18 ) ;
V_15 = ( T_1 ) F_2 (
V_4 , V_4 -> V_17 ,
F_6 ( struct V_19 , V_15 ) ,
F_9 ( struct V_19 , V_15 ) ) ;
V_16 = ( T_1 ) F_2 (
V_4 , V_4 -> V_17 ,
F_6 ( struct V_19 , V_16 ) ,
F_9 ( struct V_19 , V_16 ) ) ;
F_10 ( & V_4 -> V_20 -> V_21 , L_1 , V_22 ,
V_15 ) ;
if ( ( V_15 > 3 ) ||
( V_14 && V_15 != V_14 ) ) {
F_11 ( & V_4 -> V_20 -> V_21 , L_2 ,
V_15 , V_16 ,
F_12 ( V_4 -> V_17 ) ) ;
return - 1 ;
} else {
return 0 ;
}
}
static const struct V_11
* F_13 ( struct V_3 * V_4 ,
const char * V_12 , T_1 V_23 )
{
struct V_11 * V_24 =
& V_4 -> V_25 ;
T_2 V_26 = F_14 ( V_4 , V_12 , V_23 ) ;
if ( V_26 ) {
V_24 -> V_27 = F_2 (
V_4 , V_26 ,
F_6 ( struct V_11 ,
V_27 ) ,
F_9 (
struct V_11 ,
V_27 ) ) ;
V_24 -> V_7 = F_2 ( V_4 , V_26 ,
F_6 ( struct V_11 ,
V_7 ) ,
F_9 (
struct V_11 ,
V_7 ) ) ;
strncpy ( V_24 -> V_12 , V_12 , sizeof( V_24 -> V_12 ) ) ;
V_24 -> V_12 [ sizeof( V_24 -> V_12 ) - 1 ] = 0 ;
return & V_4 -> V_25 ;
} else {
return NULL ;
}
}
static T_2 F_14 ( struct V_3 * V_4 ,
const char * V_12 ,
T_1 V_23 )
{
T_2 V_28 = 0 ;
if ( ! F_8 ( V_4 , 3 ) ) {
T_1 V_29 ;
T_2 V_30 = F_2 (
V_4 , V_4 -> V_17 ,
F_6 ( struct V_19 ,
V_30 ) ,
F_9 ( struct V_19 ,
V_30 ) ) ;
T_1 V_31 = ( T_1 ) F_2 (
V_4 , V_4 -> V_17 ,
F_6 ( struct V_19 ,
V_32 ) ,
F_9 ( struct V_19 ,
V_32 ) ) ;
T_1 V_33 = ( T_1 ) F_2 (
V_4 , V_4 -> V_17 ,
F_6 ( struct V_19 ,
V_34 ) ,
F_9 ( struct V_19 ,
V_34 ) ) ;
T_2 V_26 = V_30 ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
T_2 V_35 = F_2 (
V_4 , V_26 ,
F_6 (
struct V_11 ,
V_7 ) ,
F_9 (
struct V_11 ,
V_7 ) ) ;
if ( V_12 && V_35 ) {
char * V_36 =
F_15 ( V_33 + 1 , V_37 ) ;
if ( ! V_36 )
break;
F_5 ( V_4 , V_26 ,
V_36 ,
V_33 ) ;
if ( ! strncmp ( V_12 , V_36 , V_33 ) ) {
V_28 = V_26 ;
F_16 ( V_36 ) ;
break;
}
F_16 ( V_36 ) ;
} else if ( ! V_12 && ! V_35 ) {
V_28 = V_26 ;
break;
}
V_26 +=
sizeof( struct V_11 ) ;
}
}
return V_28 ;
}
static int F_17 ( struct V_3 * V_4 , const char * V_12 ,
T_2 * V_27 , T_2 * V_7 )
{
const struct V_11 * V_38 ;
F_18 () ;
V_38 = F_13 ( V_4 , V_12 , 0 ) ;
F_19 () ;
if ( V_38 ) {
* V_27 = V_38 -> V_27 ;
* V_7 = V_38 -> V_7 ;
return 0 ;
}
return 1 ;
}
static void F_18 ( void )
{
}
static void F_19 ( void )
{
}
int F_20 ( struct V_3 * V_4 , char * V_39 ,
T_1 V_40 )
{
T_1 V_10 = ( T_1 ) strlen ( V_39 ) ;
F_10 ( & V_4 -> V_20 -> V_21 , L_3 , V_39 ) ;
if ( V_10 > V_41 - 1 ) {
F_11 ( & V_4 -> V_20 -> V_21 , L_4 ,
V_41 - 1 ) ;
return - 1 ;
}
if ( F_21 ( V_4 , V_40 ) != 0 ) {
F_11 ( & V_4 -> V_20 -> V_21 , L_5 ) ;
return - 1 ;
}
F_18 () ;
F_22 ( V_4 , V_42 ,
( V_13 * ) V_39 , V_10 ) ;
F_23 ( V_4 , V_43 ,
V_10 ) ;
F_23 ( V_4 , V_44 ,
V_45 ) ;
if ( F_21 ( V_4 , 200 ) != 0 ) {
F_19 () ;
F_11 ( & V_4 -> V_20 -> V_21 , L_6 ) ;
return - 1 ;
}
F_19 () ;
return 0 ;
}
int F_21 ( struct V_3 * V_4 ,
T_1 V_46 )
{
F_10 ( & V_4 -> V_20 -> V_21 , L_7 ,
V_46 ) ;
if ( F_24 ( V_4 ) )
return - 1 ;
while ( V_46 > 0 &&
F_3 ( V_4 ,
V_44 )
!= V_47 ) {
if ( -- V_46 <= 0 )
return - 1 ;
F_25 ( V_48 / 100 ) ;
}
return 0 ;
}
static void F_26 ( struct V_3 * V_4 ,
T_3 V_49 )
{
struct V_50 * V_1 ;
V_1 = & V_4 -> V_1 [ V_49 ] ;
V_1 -> V_51 = 0 ;
}
static void F_27 ( struct V_3 * V_4 ,
struct V_50 * V_1 ,
T_3 V_49 ,
char * V_52 ,
T_4 V_53 )
{
char * line ;
T_4 V_29 ;
line = V_52 ;
for ( V_29 = 0 ; V_29 < V_53 ; V_29 ++ ) {
if ( V_52 [ V_29 ] == '\n' ) {
V_52 [ V_29 ] = '\0' ;
if ( V_1 -> V_54 [ 0 ] ) {
F_28 ( & V_4 -> V_20 -> V_21 , L_8 ,
V_49 , V_1 -> V_54 ,
line ) ;
V_1 -> V_54 [ 0 ] = '\0' ;
} else {
F_28 ( & V_4 -> V_20 -> V_21 , L_9 ,
V_49 , line ) ;
}
line = & V_52 [ V_29 + 1 ] ;
}
}
if ( line != & V_52 [ V_53 ] ) {
V_52 [ V_53 ] = '\0' ;
strcpy ( V_1 -> V_54 , line ) ;
}
}
static void F_29 ( struct V_55 * V_56 )
{
T_4 V_53 , V_57 , V_58 ;
struct V_50 * V_1 ;
struct V_59 * V_60 = (struct V_59 * ) V_56 ;
struct V_3 * V_4 = (struct V_3 * ) V_60 -> V_61 ;
T_1 V_49 = ( T_1 ) V_60 -> V_62 ;
T_1 V_63 ;
V_1 = & V_4 -> V_1 [ V_49 ] ;
V_57 = 0 ;
V_58 = 0 ;
do {
V_53 =
F_30 ( V_4 , V_49 , V_52 ,
sizeof( V_52 ) - 1 ) ;
if ( V_53 > 0 ) {
V_58 += V_53 ;
if ( V_1 -> V_51 )
F_26 ( V_4 , V_49 ) ;
if ( F_1 ( V_49 ) ) {
F_27 ( V_4 , V_1 , V_49 ,
V_52 , V_53 ) ;
}
} else if ( V_53 < 0 ) {
F_11 ( & V_4 -> V_20 -> V_21 , L_10 ,
V_49 , V_53 ) ;
}
V_57 ++ ;
} while ( ( V_53 > 0 ) && ( V_57 < 16 ) );
if ( F_1 ( V_49 ) &&
( V_58 == 0 ) && ( V_1 -> V_54 [ 0 ] ) ) {
F_28 ( & V_4 -> V_20 -> V_21 , L_11 ,
V_49 , V_1 -> V_54 ) ;
V_1 -> V_54 [ 0 ] = '\0' ;
}
V_63 = V_64 ;
F_31 ( & V_60 -> V_56 , F_32 ( V_63 ) ) ;
}
int F_33 ( struct V_3 * V_4 )
{
int V_65 = 0 ;
T_2 V_8 , V_7 ;
V_65 = F_24 ( V_4 ) ;
if ( V_65 ) {
F_11 ( & V_4 -> V_20 -> V_21 , L_12 ) ;
return V_65 ;
}
V_65 = F_17 ( V_4 , V_66 , & V_8 ,
& V_7 ) ;
if ( V_65 ) {
F_11 ( & V_4 -> V_20 -> V_21 , L_13 ,
V_66 ) ;
return V_65 ;
}
V_4 -> V_67 = F_3 ( V_4 ,
V_8 + F_6 ( struct V_68 ,
V_67 ) ) ;
V_4 -> V_69 = V_8 ;
F_10 ( & V_4 -> V_20 -> V_21 , L_14 ,
V_4 -> V_67 ) ;
return V_65 ;
}
int F_34 ( struct V_3 * V_4 , T_1 V_49 )
{
int V_65 = 0 ;
T_1 V_63 ;
T_2 V_70 ;
struct V_71 * V_56 ;
struct V_50 * V_1 ;
if ( V_49 >= V_4 -> V_67 ) {
F_11 ( & V_4 -> V_20 -> V_21 ,
L_15 ,
V_49 , V_4 -> V_67 ) ;
} else {
V_1 = & V_4 -> V_1 [ V_49 ] ;
V_1 -> V_51 = 0 ;
V_70 = V_4 -> V_69 + V_49 * 8 +
F_6 ( struct V_68 ,
V_72 ) ;
V_1 -> V_8 = F_4 ( V_4 , V_70 ) ;
V_70 = V_1 -> V_8 + F_6 ( struct V_73 ,
V_74 ) ;
V_1 -> V_75 = F_3 ( V_4 , V_70 ) ;
V_70 = V_1 -> V_8 + F_6 ( struct V_73 ,
V_76 ) ;
V_1 -> V_76 =
F_4 ( V_4 , V_70 ) ;
V_70 = V_1 -> V_8 + F_6 ( struct V_73 ,
V_77 ) ;
V_1 -> V_77 =
F_4 ( V_4 , V_70 ) ;
V_1 -> V_54 [ 0 ] = '\0' ;
V_56 = & V_4 -> V_78 [ V_49 ] . V_56 ;
F_35 ( V_56 , F_29 ) ;
V_4 -> V_78 [ V_49 ] . V_61 = ( void * ) V_4 ;
V_4 -> V_78 [ V_49 ] . V_62 = V_49 ;
V_63 = V_64 ;
F_31 ( V_56 , F_32 ( V_63 ) ) ;
if ( F_1 ( V_49 ) ) {
V_65 = F_20 ( V_4 ,
L_16 ,
2000 ) ;
}
V_1 -> V_79 = 1 ;
}
return V_65 ;
}
void F_36 ( struct V_3 * V_4 )
{
T_1 V_29 ;
struct V_50 * V_1 ;
for ( V_29 = 0 ; V_29 < V_4 -> V_67 ; V_29 ++ ) {
V_1 = & V_4 -> V_1 [ V_29 ] ;
if ( ! V_1 -> V_79 )
continue;
F_37 ( & V_4 -> V_78 [ V_29 ] .
V_56 ) ;
V_1 -> V_8 = 0 ;
V_1 -> V_75 = 0 ;
V_1 -> V_76 = 0 ;
V_1 -> V_77 = 0 ;
}
V_4 -> V_67 = 0 ;
}
static inline int F_38 ( T_1 V_75 ,
T_1 V_80 ,
T_1 V_81 )
{
if ( V_81 >= V_75 || V_80 >= V_75 )
return - 1 ;
return ( ( V_75 - 1 ) - ( V_80 - V_81 ) ) % V_75 ;
}
static inline int F_39 ( T_1 V_75 ,
T_1 V_80 ,
T_1 V_81 )
{
if ( V_81 >= V_75 || V_80 >= V_75 )
return - 1 ;
return V_75 - 1 -
F_38 ( V_75 , V_80 , V_81 ) ;
}
static int F_30 ( struct V_3 * V_4 , T_1 V_49 ,
char * V_82 , T_1 V_74 )
{
int V_83 ;
T_1 V_81 , V_80 ;
struct V_50 * V_1 ;
if ( V_49 >= V_4 -> V_67 ) {
F_11 ( & V_4 -> V_20 -> V_21 , L_17 ,
V_49 ) ;
return 0 ;
}
V_1 = & V_4 -> V_1 [ V_49 ] ;
V_81 = F_3 ( V_4 , V_1 -> V_8 +
F_6 ( struct V_73 , V_84 ) ) ;
V_80 = F_3 ( V_4 , V_1 -> V_8 +
F_6 ( struct V_73 , V_85 ) ) ;
V_83 = F_39 ( V_1 -> V_75 ,
V_80 , V_81 ) ;
if ( V_83 <= 0 )
return V_83 ;
V_83 = F_40 ( V_83 , ( T_4 ) V_74 ) ;
if ( V_81 + V_83 >= V_1 -> V_75 )
V_83 = V_1 -> V_75 - V_81 ;
F_7 ( V_4 , V_1 -> V_77 + V_81 ,
( V_13 * ) V_82 , V_83 ) ;
F_23 ( V_4 , V_1 -> V_8 +
F_6 ( struct V_73 ,
V_84 ) ,
( V_81 + V_83 ) %
V_1 -> V_75 ) ;
return V_83 ;
}
int F_41 ( struct V_3 * V_4 , const V_13 * V_86 ,
T_3 V_7 )
{
int V_65 = 0 ;
V_13 * V_87 = V_88 ;
T_1 V_89 ;
T_2 V_90 ;
T_1 V_91 ;
struct V_92 * V_93 ;
T_1 V_29 , V_94 ;
if ( V_7 < sizeof( struct V_92 ) ) {
F_11 ( & V_4 -> V_20 -> V_21 , L_18 ,
( T_1 ) V_7 ,
( T_1 ) sizeof( struct V_92 ) ) ;
return - V_95 ;
}
V_93 = (struct V_92 * ) V_86 ;
if ( F_42 ( V_93 -> V_96 ) != V_97 ) {
F_11 ( & V_4 -> V_20 -> V_21 , L_19 ) ;
return - V_95 ;
}
V_89 = F_43 ( ( unsigned int ) ~ 0 , V_86 ,
sizeof( struct V_92 ) -
sizeof( T_1 ) ) ^ ~ 0U ;
if ( V_89 != F_42 ( V_93 -> F_43 ) ) {
F_11 ( & V_4 -> V_20 -> V_21 , L_20 ,
V_89 , F_42 ( V_93 -> F_43 ) ) ;
return - V_95 ;
}
if ( strncmp ( V_98 , V_93 -> V_99 , strlen ( V_98 ) ) ) {
F_11 ( & V_4 -> V_20 -> V_21 , L_21 ,
V_98 , V_93 -> V_99 ) ;
return - V_95 ;
}
if ( memcmp ( V_100 , V_93 -> V_99 + strlen ( V_98 ) ,
strlen ( V_100 ) ) ) {
F_11 ( & V_4 -> V_20 -> V_21 , L_22 ,
V_100 ,
V_93 -> V_99 + strlen ( V_98 ) ) ;
return - V_95 ;
}
if ( F_42 ( V_93 -> V_101 ) > V_102 ) {
F_11 ( & V_4 -> V_20 -> V_21 , L_23 ,
F_42 ( V_93 -> V_101 ) ) ;
return - V_95 ;
}
F_28 ( & V_4 -> V_20 -> V_21 , L_24 , V_93 -> V_99 ) ;
snprintf ( V_4 -> V_103 . V_104 , 32 , L_25 ,
V_93 -> V_99 ) ;
V_86 += sizeof( struct V_92 ) ;
F_28 ( & V_4 -> V_20 -> V_21 , L_26 , V_22 ,
F_42 ( V_93 -> V_101 ) ) ;
for ( V_29 = 0 ; V_29 < F_42 ( V_93 -> V_101 ) ; V_29 ++ ) {
V_90 = F_44 ( V_93 -> V_24 [ V_29 ] . V_8 ) ;
V_91 = F_42 ( V_93 -> V_24 [ V_29 ] . V_10 ) ;
F_28 ( & V_4 -> V_20 -> V_21 , L_27 ,
V_91 , V_90 ) ;
V_94 = V_91 ;
while ( V_94 ) {
if ( V_94 < V_105 )
V_7 = V_94 ;
else
V_7 = V_105 ;
memcpy ( V_87 , V_86 , V_7 ) ;
F_22 ( V_4 , V_90 , V_87 , ( T_1 ) V_7 ) ;
V_86 += V_7 ;
V_94 -= ( T_1 ) V_7 ;
V_90 += V_7 ;
}
}
F_28 ( & V_4 -> V_20 -> V_21 , L_28 ,
V_93 -> V_106 ) ;
V_65 = F_20 ( V_4 , V_93 -> V_106 , 50 ) ;
return 0 ;
}
