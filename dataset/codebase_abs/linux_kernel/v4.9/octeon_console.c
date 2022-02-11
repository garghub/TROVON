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
V_15 =
( T_1 ) F_9 ( V_4 , V_15 ) ;
V_16 =
( T_1 ) F_9 ( V_4 , V_16 ) ;
F_10 ( & V_4 -> V_19 -> V_20 , L_1 , V_21 ,
V_15 ) ;
if ( ( V_15 > 3 ) ||
( V_14 && V_15 != V_14 ) ) {
F_11 ( & V_4 -> V_19 -> V_20 , L_2 ,
V_15 , V_16 ,
F_12 ( V_4 -> V_17 ) ) ;
return - 1 ;
} else {
return 0 ;
}
}
static const struct V_11
* F_13 ( struct V_3 * V_4 ,
const char * V_12 , T_1 V_22 )
{
struct V_11 * V_23 =
& V_4 -> V_24 ;
T_2 V_25 = F_14 ( V_4 , V_12 , V_22 ) ;
if ( V_25 ) {
V_23 -> V_26 = F_15 ( V_4 , V_25 ,
V_26 ) ;
V_23 -> V_7 =
F_15 ( V_4 , V_25 , V_7 ) ;
strncpy ( V_23 -> V_12 , V_12 , sizeof( V_23 -> V_12 ) ) ;
V_23 -> V_12 [ sizeof( V_23 -> V_12 ) - 1 ] = 0 ;
return & V_4 -> V_24 ;
} else {
return NULL ;
}
}
static T_2 F_14 ( struct V_3 * V_4 ,
const char * V_12 ,
T_1 V_22 )
{
T_2 V_27 = 0 ;
F_16 ( V_22 ) ;
if ( ! F_8 ( V_4 , 3 ) ) {
T_1 V_28 ;
T_2 V_29 =
F_9 ( V_4 ,
V_29 ) ;
T_1 V_30 = ( T_1 )
F_9 ( V_4 , V_31 ) ;
T_1 V_32 = ( T_1 )
F_9 ( V_4 , V_33 ) ;
T_2 V_25 = V_29 ;
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
T_2 V_34 =
F_15 ( V_4 , V_25 ,
V_7 ) ;
if ( V_12 && V_34 ) {
char * V_35 =
F_17 ( V_32 + 1 , V_36 ) ;
if ( ! V_35 )
break;
F_5 ( V_4 , V_25 ,
V_35 ,
V_32 ) ;
if ( ! strncmp ( V_12 , V_35 , V_32 ) ) {
V_27 = V_25 ;
F_18 ( V_35 ) ;
break;
}
F_18 ( V_35 ) ;
} else if ( ! V_12 && ! V_34 ) {
V_27 = V_25 ;
break;
}
V_25 +=
sizeof( struct V_11 ) ;
}
}
F_19 ( V_22 ) ;
return V_27 ;
}
static int F_20 ( struct V_3 * V_4 , const char * V_12 ,
T_2 * V_26 , T_2 * V_7 )
{
const struct V_11 * V_37 ;
F_21 () ;
V_37 = F_13 ( V_4 , V_12 , 0 ) ;
F_22 () ;
if ( V_37 ) {
* V_26 = V_37 -> V_26 ;
* V_7 = V_37 -> V_7 ;
return 0 ;
}
return 1 ;
}
static void F_21 ( void )
{
}
static void F_22 ( void )
{
}
int F_23 ( struct V_3 * V_4 , char * V_38 ,
T_1 V_39 )
{
T_1 V_10 = ( T_1 ) strlen ( V_38 ) ;
F_10 ( & V_4 -> V_19 -> V_20 , L_3 , V_38 ) ;
if ( V_10 > V_40 - 1 ) {
F_11 ( & V_4 -> V_19 -> V_20 , L_4 ,
V_40 - 1 ) ;
return - 1 ;
}
if ( F_24 ( V_4 , V_39 ) != 0 ) {
F_11 ( & V_4 -> V_19 -> V_20 , L_5 ) ;
return - 1 ;
}
F_21 () ;
F_25 ( V_4 , V_41 ,
( V_13 * ) V_38 , V_10 ) ;
F_26 ( V_4 , V_42 ,
V_10 ) ;
F_26 ( V_4 , V_43 ,
V_44 ) ;
if ( F_24 ( V_4 , 200 ) != 0 ) {
F_22 () ;
F_11 ( & V_4 -> V_19 -> V_20 , L_6 ) ;
return - 1 ;
}
F_22 () ;
return 0 ;
}
int F_24 ( struct V_3 * V_4 ,
T_1 V_45 )
{
F_10 ( & V_4 -> V_19 -> V_20 , L_7 ,
V_45 ) ;
if ( F_27 ( V_4 ) )
return - 1 ;
while ( V_45 > 0 &&
F_3 ( V_4 ,
V_43 )
!= V_46 ) {
if ( -- V_45 <= 0 )
return - 1 ;
F_28 ( V_47 / 100 ) ;
}
return 0 ;
}
static void F_29 ( struct V_3 * V_4 ,
T_3 V_48 )
{
struct V_49 * V_1 ;
V_1 = & V_4 -> V_1 [ V_48 ] ;
V_1 -> V_50 = 0 ;
}
static void F_30 ( struct V_3 * V_4 ,
struct V_49 * V_1 ,
T_3 V_48 ,
char * V_51 ,
T_4 V_52 )
{
char * line ;
T_4 V_28 ;
line = V_51 ;
for ( V_28 = 0 ; V_28 < V_52 ; V_28 ++ ) {
if ( V_51 [ V_28 ] == '\n' ) {
V_51 [ V_28 ] = '\0' ;
if ( V_1 -> V_53 [ 0 ] ) {
F_31 ( & V_4 -> V_19 -> V_20 , L_8 ,
V_48 , V_1 -> V_53 ,
line ) ;
V_1 -> V_53 [ 0 ] = '\0' ;
} else {
F_31 ( & V_4 -> V_19 -> V_20 , L_9 ,
V_48 , line ) ;
}
line = & V_51 [ V_28 + 1 ] ;
}
}
if ( line != & V_51 [ V_52 ] ) {
V_51 [ V_52 ] = '\0' ;
strcpy ( V_1 -> V_53 , line ) ;
}
}
static void F_32 ( struct V_54 * V_55 )
{
T_4 V_52 , V_56 , V_57 ;
struct V_49 * V_1 ;
struct V_58 * V_59 = (struct V_58 * ) V_55 ;
struct V_3 * V_4 = (struct V_3 * ) V_59 -> V_60 ;
T_1 V_48 = ( T_1 ) V_59 -> V_61 ;
T_1 V_62 ;
V_1 = & V_4 -> V_1 [ V_48 ] ;
V_56 = 0 ;
V_57 = 0 ;
do {
V_52 =
F_33 ( V_4 , V_48 , V_51 ,
sizeof( V_51 ) - 1 ) ;
if ( V_52 > 0 ) {
V_57 += V_52 ;
if ( V_1 -> V_50 )
F_29 ( V_4 , V_48 ) ;
if ( F_1 ( V_48 ) ) {
F_30 ( V_4 , V_1 , V_48 ,
V_51 , V_52 ) ;
}
} else if ( V_52 < 0 ) {
F_11 ( & V_4 -> V_19 -> V_20 , L_10 ,
V_48 , V_52 ) ;
}
V_56 ++ ;
} while ( ( V_52 > 0 ) && ( V_56 < 16 ) );
if ( F_1 ( V_48 ) &&
( V_57 == 0 ) && ( V_1 -> V_53 [ 0 ] ) ) {
F_31 ( & V_4 -> V_19 -> V_20 , L_11 ,
V_48 , V_1 -> V_53 ) ;
V_1 -> V_53 [ 0 ] = '\0' ;
}
V_62 = V_63 ;
F_34 ( & V_59 -> V_55 , F_35 ( V_62 ) ) ;
}
int F_36 ( struct V_3 * V_4 )
{
int V_64 = 0 ;
T_2 V_8 , V_7 ;
V_64 = F_27 ( V_4 ) ;
if ( V_64 ) {
F_11 ( & V_4 -> V_19 -> V_20 , L_12 ) ;
return V_64 ;
}
V_64 = F_20 ( V_4 , V_65 , & V_8 ,
& V_7 ) ;
if ( V_64 ) {
F_11 ( & V_4 -> V_19 -> V_20 , L_13 ,
V_65 ) ;
return V_64 ;
}
V_4 -> V_66 = F_3 ( V_4 ,
V_8 + F_6 ( struct V_67 ,
V_66 ) ) ;
V_4 -> V_68 = V_8 ;
F_10 ( & V_4 -> V_19 -> V_20 , L_14 ,
V_4 -> V_66 ) ;
return V_64 ;
}
int F_37 ( struct V_3 * V_4 , T_1 V_48 )
{
int V_64 = 0 ;
T_1 V_62 ;
T_2 V_69 ;
struct V_70 * V_55 ;
struct V_49 * V_1 ;
if ( V_48 >= V_4 -> V_66 ) {
F_11 ( & V_4 -> V_19 -> V_20 ,
L_15 ,
V_48 , V_4 -> V_66 ) ;
} else {
V_1 = & V_4 -> V_1 [ V_48 ] ;
V_1 -> V_50 = 0 ;
V_69 = V_4 -> V_68 + V_48 * 8 +
F_6 ( struct V_67 ,
V_71 ) ;
V_1 -> V_8 = F_4 ( V_4 , V_69 ) ;
V_69 = V_1 -> V_8 + F_6 ( struct V_72 ,
V_73 ) ;
V_1 -> V_74 = F_3 ( V_4 , V_69 ) ;
V_69 = V_1 -> V_8 + F_6 ( struct V_72 ,
V_75 ) ;
V_1 -> V_75 =
F_4 ( V_4 , V_69 ) ;
V_69 = V_1 -> V_8 + F_6 ( struct V_72 ,
V_76 ) ;
V_1 -> V_76 =
F_4 ( V_4 , V_69 ) ;
V_1 -> V_53 [ 0 ] = '\0' ;
V_55 = & V_4 -> V_77 [ V_48 ] . V_55 ;
F_38 ( V_55 , F_32 ) ;
V_4 -> V_77 [ V_48 ] . V_60 = ( void * ) V_4 ;
V_4 -> V_77 [ V_48 ] . V_61 = V_48 ;
V_62 = V_63 ;
F_34 ( V_55 , F_35 ( V_62 ) ) ;
if ( F_1 ( V_48 ) ) {
V_64 = F_23 ( V_4 ,
L_16 ,
2000 ) ;
}
V_1 -> V_78 = 1 ;
}
return V_64 ;
}
void F_39 ( struct V_3 * V_4 )
{
T_1 V_28 ;
struct V_49 * V_1 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_66 ; V_28 ++ ) {
V_1 = & V_4 -> V_1 [ V_28 ] ;
if ( ! V_1 -> V_78 )
continue;
F_40 ( & V_4 -> V_77 [ V_28 ] .
V_55 ) ;
V_1 -> V_8 = 0 ;
V_1 -> V_74 = 0 ;
V_1 -> V_75 = 0 ;
V_1 -> V_76 = 0 ;
}
V_4 -> V_66 = 0 ;
}
static inline int F_41 ( T_1 V_74 ,
T_1 V_79 ,
T_1 V_80 )
{
if ( V_80 >= V_74 || V_79 >= V_74 )
return - 1 ;
return ( ( V_74 - 1 ) - ( V_79 - V_80 ) ) % V_74 ;
}
static inline int F_42 ( T_1 V_74 ,
T_1 V_79 ,
T_1 V_80 )
{
if ( V_80 >= V_74 || V_79 >= V_74 )
return - 1 ;
return V_74 - 1 -
F_41 ( V_74 , V_79 , V_80 ) ;
}
static int F_33 ( struct V_3 * V_4 , T_1 V_48 ,
char * V_81 , T_1 V_73 )
{
int V_82 ;
T_1 V_80 , V_79 ;
struct V_49 * V_1 ;
if ( V_48 >= V_4 -> V_66 ) {
F_11 ( & V_4 -> V_19 -> V_20 , L_17 ,
V_48 ) ;
return 0 ;
}
V_1 = & V_4 -> V_1 [ V_48 ] ;
V_80 = F_3 ( V_4 , V_1 -> V_8 +
F_6 ( struct V_72 , V_83 ) ) ;
V_79 = F_3 ( V_4 , V_1 -> V_8 +
F_6 ( struct V_72 , V_84 ) ) ;
V_82 = F_42 ( V_1 -> V_74 ,
V_79 , V_80 ) ;
if ( V_82 <= 0 )
return V_82 ;
V_82 = F_43 ( V_82 , ( T_4 ) V_73 ) ;
if ( V_80 + V_82 >= V_1 -> V_74 )
V_82 = V_1 -> V_74 - V_80 ;
F_7 ( V_4 , V_1 -> V_76 + V_80 ,
( V_13 * ) V_81 , V_82 ) ;
F_26 ( V_4 , V_1 -> V_8 +
F_6 ( struct V_72 ,
V_83 ) ,
( V_80 + V_82 ) %
V_1 -> V_74 ) ;
return V_82 ;
}
int F_44 ( struct V_3 * V_4 , const V_13 * V_85 ,
T_3 V_7 )
{
int V_64 = 0 ;
V_13 * V_86 = V_87 ;
T_1 V_88 ;
T_2 V_89 ;
T_1 V_90 ;
struct V_91 * V_92 ;
T_1 V_28 , V_93 ;
if ( V_7 < sizeof( struct V_91 ) ) {
F_11 ( & V_4 -> V_19 -> V_20 , L_18 ,
( T_1 ) V_7 ,
( T_1 ) sizeof( struct V_91 ) ) ;
return - V_94 ;
}
V_92 = (struct V_91 * ) V_85 ;
if ( F_45 ( V_92 -> V_95 ) != V_96 ) {
F_11 ( & V_4 -> V_19 -> V_20 , L_19 ) ;
return - V_94 ;
}
V_88 = F_46 ( ( unsigned int ) ~ 0 , V_85 ,
sizeof( struct V_91 ) -
sizeof( T_1 ) ) ^ ~ 0U ;
if ( V_88 != F_45 ( V_92 -> F_46 ) ) {
F_11 ( & V_4 -> V_19 -> V_20 , L_20 ,
V_88 , F_45 ( V_92 -> F_46 ) ) ;
return - V_94 ;
}
if ( strncmp ( V_97 , V_92 -> V_98 , strlen ( V_97 ) ) ) {
F_11 ( & V_4 -> V_19 -> V_20 , L_21 ,
V_97 , V_92 -> V_98 ) ;
return - V_94 ;
}
if ( memcmp ( V_99 , V_92 -> V_98 + strlen ( V_97 ) ,
strlen ( V_99 ) ) ) {
F_11 ( & V_4 -> V_19 -> V_20 , L_22 ,
V_99 ,
V_92 -> V_98 + strlen ( V_97 ) ) ;
return - V_94 ;
}
if ( F_45 ( V_92 -> V_100 ) > V_101 ) {
F_11 ( & V_4 -> V_19 -> V_20 , L_23 ,
F_45 ( V_92 -> V_100 ) ) ;
return - V_94 ;
}
F_31 ( & V_4 -> V_19 -> V_20 , L_24 , V_92 -> V_98 ) ;
snprintf ( V_4 -> V_102 . V_103 , 32 , L_25 ,
V_92 -> V_98 ) ;
V_85 += sizeof( struct V_91 ) ;
F_31 ( & V_4 -> V_19 -> V_20 , L_26 , V_21 ,
F_45 ( V_92 -> V_100 ) ) ;
for ( V_28 = 0 ; V_28 < F_45 ( V_92 -> V_100 ) ; V_28 ++ ) {
V_89 = F_47 ( V_92 -> V_23 [ V_28 ] . V_8 ) ;
V_90 = F_45 ( V_92 -> V_23 [ V_28 ] . V_10 ) ;
F_31 ( & V_4 -> V_19 -> V_20 , L_27 ,
V_90 , V_89 ) ;
V_93 = V_90 ;
while ( V_93 ) {
if ( V_93 < V_104 )
V_7 = V_93 ;
else
V_7 = V_104 ;
memcpy ( V_86 , V_85 , V_7 ) ;
F_25 ( V_4 , V_89 , V_86 , ( T_1 ) V_7 ) ;
V_85 += V_7 ;
V_93 -= ( T_1 ) V_7 ;
V_89 += V_7 ;
}
}
F_31 ( & V_4 -> V_19 -> V_20 , L_28 ,
V_92 -> V_105 ) ;
V_64 = F_23 ( V_4 , V_92 -> V_105 , 50 ) ;
return 0 ;
}
