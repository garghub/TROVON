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
V_13 =
( T_2 ) F_8 ( V_2 , V_13 ) ;
V_14 =
( T_2 ) F_8 ( V_2 , V_14 ) ;
F_9 ( & V_2 -> V_17 -> V_18 , L_1 , V_19 ,
V_13 ) ;
if ( ( V_13 > 3 ) ||
( V_12 && V_13 != V_12 ) ) {
F_10 ( & V_2 -> V_17 -> V_18 , L_2 ,
V_13 , V_14 ,
F_11 ( V_2 -> V_15 ) ) ;
return - 1 ;
} else {
return 0 ;
}
}
static const struct V_9
* F_12 ( struct V_1 * V_2 ,
const char * V_10 , T_2 V_20 )
{
struct V_9 * V_21 =
& V_2 -> V_22 ;
T_1 V_23 = F_13 ( V_2 , V_10 , V_20 ) ;
if ( V_23 ) {
V_21 -> V_24 = F_14 ( V_2 , V_23 ,
V_24 ) ;
V_21 -> V_5 =
F_14 ( V_2 , V_23 , V_5 ) ;
strncpy ( V_21 -> V_10 , V_10 , sizeof( V_21 -> V_10 ) ) ;
V_21 -> V_10 [ sizeof( V_21 -> V_10 ) - 1 ] = 0 ;
return & V_2 -> V_22 ;
} else {
return NULL ;
}
}
static T_1 F_13 ( struct V_1 * V_2 ,
const char * V_10 ,
T_2 V_20 )
{
T_1 V_25 = 0 ;
F_15 ( V_20 ) ;
if ( ! F_7 ( V_2 , 3 ) ) {
T_2 V_26 ;
T_1 V_27 =
F_8 ( V_2 ,
V_27 ) ;
T_2 V_28 = ( T_2 )
F_8 ( V_2 , V_29 ) ;
T_2 V_30 = ( T_2 )
F_8 ( V_2 , V_31 ) ;
T_1 V_23 = V_27 ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
T_1 V_32 =
F_14 ( V_2 , V_23 ,
V_5 ) ;
if ( V_10 && V_32 ) {
char * V_33 =
F_16 ( V_30 + 1 , V_34 ) ;
if ( ! V_33 )
break;
F_4 ( V_2 , V_23 ,
V_33 ,
V_30 ) ;
if ( ! strncmp ( V_10 , V_33 , V_30 ) ) {
V_25 = V_23 ;
F_17 ( V_33 ) ;
break;
}
F_17 ( V_33 ) ;
} else if ( ! V_10 && ! V_32 ) {
V_25 = V_23 ;
break;
}
V_23 +=
sizeof( struct V_9 ) ;
}
}
F_18 ( V_20 ) ;
return V_25 ;
}
static int F_19 ( struct V_1 * V_2 , const char * V_10 ,
T_1 * V_24 , T_1 * V_5 )
{
const struct V_9 * V_35 ;
F_20 () ;
V_35 = F_12 ( V_2 , V_10 , 0 ) ;
F_21 () ;
if ( V_35 ) {
* V_24 = V_35 -> V_24 ;
* V_5 = V_35 -> V_5 ;
return 0 ;
}
return 1 ;
}
static void F_20 ( void )
{
}
static void F_21 ( void )
{
}
int F_22 ( struct V_1 * V_2 , char * V_36 ,
T_2 V_37 )
{
T_2 V_8 = ( T_2 ) strlen ( V_36 ) ;
F_9 ( & V_2 -> V_17 -> V_18 , L_3 , V_36 ) ;
if ( V_8 > V_38 - 1 ) {
F_10 ( & V_2 -> V_17 -> V_18 , L_4 ,
V_38 - 1 ) ;
return - 1 ;
}
if ( F_23 ( V_2 , V_37 ) != 0 ) {
F_10 ( & V_2 -> V_17 -> V_18 , L_5 ) ;
return - 1 ;
}
F_20 () ;
F_24 ( V_2 , V_39 ,
( V_11 * ) V_36 , V_8 ) ;
F_25 ( V_2 , V_40 ,
V_8 ) ;
F_25 ( V_2 , V_41 ,
V_42 ) ;
if ( F_23 ( V_2 , 200 ) != 0 ) {
F_21 () ;
F_10 ( & V_2 -> V_17 -> V_18 , L_6 ) ;
return - 1 ;
}
F_21 () ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 ,
T_2 V_43 )
{
F_9 ( & V_2 -> V_17 -> V_18 , L_7 ,
V_43 ) ;
if ( F_26 ( V_2 ) )
return - 1 ;
while ( V_43 > 0 &&
F_2 ( V_2 ,
V_41 )
!= V_44 ) {
if ( -- V_43 <= 0 )
return - 1 ;
F_27 ( V_45 / 100 ) ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 ,
T_3 V_46 )
{
struct V_47 * V_48 ;
V_48 = & V_2 -> V_48 [ V_46 ] ;
V_48 -> V_49 = 0 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
T_3 V_46 ,
char * V_50 ,
T_4 V_51 )
{
char * line ;
T_4 V_26 ;
line = V_50 ;
for ( V_26 = 0 ; V_26 < V_51 ; V_26 ++ ) {
if ( V_50 [ V_26 ] == '\n' ) {
V_50 [ V_26 ] = '\0' ;
if ( V_48 -> V_52 [ 0 ] ) {
F_30 ( & V_2 -> V_17 -> V_18 , L_8 ,
V_46 , V_48 -> V_52 ,
line ) ;
V_48 -> V_52 [ 0 ] = '\0' ;
} else {
F_30 ( & V_2 -> V_17 -> V_18 , L_9 ,
V_46 , line ) ;
}
line = & V_50 [ V_26 + 1 ] ;
}
}
if ( line != & V_50 [ V_51 ] ) {
V_50 [ V_51 ] = '\0' ;
strcpy ( V_48 -> V_52 , line ) ;
}
}
static void F_31 ( struct V_53 * V_54 )
{
T_4 V_51 , V_55 , V_56 ;
struct V_47 * V_48 ;
struct V_57 * V_58 = (struct V_57 * ) V_54 ;
struct V_1 * V_2 = (struct V_1 * ) V_58 -> V_59 ;
T_2 V_46 = ( T_2 ) V_58 -> V_60 ;
T_2 V_61 ;
V_48 = & V_2 -> V_48 [ V_46 ] ;
V_55 = 0 ;
V_56 = 0 ;
do {
V_51 =
F_32 ( V_2 , V_46 , V_50 ,
sizeof( V_50 ) - 1 ) ;
if ( V_51 > 0 ) {
V_56 += V_51 ;
if ( V_48 -> V_49 )
F_28 ( V_2 , V_46 ) ;
if ( F_33 ( V_46 ) ) {
F_29 ( V_2 , V_48 , V_46 ,
V_50 , V_51 ) ;
}
} else if ( V_51 < 0 ) {
F_10 ( & V_2 -> V_17 -> V_18 , L_10 ,
V_46 , V_51 ) ;
}
V_55 ++ ;
} while ( ( V_51 > 0 ) && ( V_55 < 16 ) );
if ( F_33 ( V_46 ) &&
( V_56 == 0 ) && ( V_48 -> V_52 [ 0 ] ) ) {
F_30 ( & V_2 -> V_17 -> V_18 , L_11 ,
V_46 , V_48 -> V_52 ) ;
V_48 -> V_52 [ 0 ] = '\0' ;
}
V_61 = V_62 ;
F_34 ( & V_58 -> V_54 , F_35 ( V_61 ) ) ;
}
int F_36 ( struct V_1 * V_2 )
{
int V_63 = 0 ;
T_1 V_6 , V_5 ;
V_63 = F_26 ( V_2 ) ;
if ( V_63 ) {
F_10 ( & V_2 -> V_17 -> V_18 , L_12 ) ;
return V_63 ;
}
V_63 = F_19 ( V_2 , V_64 , & V_6 ,
& V_5 ) ;
if ( V_63 ) {
F_10 ( & V_2 -> V_17 -> V_18 , L_13 ,
V_64 ) ;
return V_63 ;
}
V_2 -> V_65 = F_2 ( V_2 ,
V_6 + F_5 ( struct V_66 ,
V_65 ) ) ;
V_2 -> V_67 = V_6 ;
F_9 ( & V_2 -> V_17 -> V_18 , L_14 ,
V_2 -> V_65 ) ;
return V_63 ;
}
int F_37 ( struct V_1 * V_2 , T_2 V_46 )
{
int V_63 = 0 ;
T_2 V_61 ;
T_1 V_68 ;
struct V_69 * V_54 ;
struct V_47 * V_48 ;
if ( V_46 >= V_2 -> V_65 ) {
F_10 ( & V_2 -> V_17 -> V_18 ,
L_15 ,
V_46 , V_2 -> V_65 ) ;
} else {
V_48 = & V_2 -> V_48 [ V_46 ] ;
V_48 -> V_49 = 0 ;
V_68 = V_2 -> V_67 + V_46 * 8 +
F_5 ( struct V_66 ,
V_70 ) ;
V_48 -> V_6 = F_3 ( V_2 , V_68 ) ;
V_68 = V_48 -> V_6 + F_5 ( struct V_71 ,
V_72 ) ;
V_48 -> V_73 = F_2 ( V_2 , V_68 ) ;
V_68 = V_48 -> V_6 + F_5 ( struct V_71 ,
V_74 ) ;
V_48 -> V_74 =
F_3 ( V_2 , V_68 ) ;
V_68 = V_48 -> V_6 + F_5 ( struct V_71 ,
V_75 ) ;
V_48 -> V_75 =
F_3 ( V_2 , V_68 ) ;
V_48 -> V_52 [ 0 ] = '\0' ;
V_54 = & V_2 -> V_76 [ V_46 ] . V_54 ;
F_38 ( V_54 , F_31 ) ;
V_2 -> V_76 [ V_46 ] . V_59 = ( void * ) V_2 ;
V_2 -> V_76 [ V_46 ] . V_60 = V_46 ;
V_61 = V_62 ;
F_34 ( V_54 , F_35 ( V_61 ) ) ;
if ( F_33 ( V_46 ) ) {
V_63 = F_22 ( V_2 ,
L_16 ,
2000 ) ;
}
V_48 -> V_77 = 1 ;
}
return V_63 ;
}
void F_39 ( struct V_1 * V_2 )
{
T_2 V_26 ;
struct V_47 * V_48 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_65 ; V_26 ++ ) {
V_48 = & V_2 -> V_48 [ V_26 ] ;
if ( ! V_48 -> V_77 )
continue;
F_40 ( & V_2 -> V_76 [ V_26 ] .
V_54 ) ;
V_48 -> V_6 = 0 ;
V_48 -> V_73 = 0 ;
V_48 -> V_74 = 0 ;
V_48 -> V_75 = 0 ;
}
V_2 -> V_65 = 0 ;
}
static inline int F_41 ( T_2 V_73 ,
T_2 V_78 ,
T_2 V_79 )
{
if ( V_79 >= V_73 || V_78 >= V_73 )
return - 1 ;
return ( ( V_73 - 1 ) - ( V_78 - V_79 ) ) % V_73 ;
}
static inline int F_42 ( T_2 V_73 ,
T_2 V_78 ,
T_2 V_79 )
{
if ( V_79 >= V_73 || V_78 >= V_73 )
return - 1 ;
return V_73 - 1 -
F_41 ( V_73 , V_78 , V_79 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_2 V_46 ,
char * V_80 , T_2 V_72 )
{
int V_81 ;
T_2 V_79 , V_78 ;
struct V_47 * V_48 ;
if ( V_46 >= V_2 -> V_65 ) {
F_10 ( & V_2 -> V_17 -> V_18 , L_17 ,
V_46 ) ;
return 0 ;
}
V_48 = & V_2 -> V_48 [ V_46 ] ;
V_79 = F_2 ( V_2 , V_48 -> V_6 +
F_5 ( struct V_71 , V_82 ) ) ;
V_78 = F_2 ( V_2 , V_48 -> V_6 +
F_5 ( struct V_71 , V_83 ) ) ;
V_81 = F_42 ( V_48 -> V_73 ,
V_78 , V_79 ) ;
if ( V_81 <= 0 )
return V_81 ;
V_81 = F_43 ( V_81 , ( T_4 ) V_72 ) ;
if ( V_79 + V_81 >= V_48 -> V_73 )
V_81 = V_48 -> V_73 - V_79 ;
F_6 ( V_2 , V_48 -> V_75 + V_79 ,
( V_11 * ) V_80 , V_81 ) ;
F_25 ( V_2 , V_48 -> V_6 +
F_5 ( struct V_71 ,
V_82 ) ,
( V_79 + V_81 ) %
V_48 -> V_73 ) ;
return V_81 ;
}
