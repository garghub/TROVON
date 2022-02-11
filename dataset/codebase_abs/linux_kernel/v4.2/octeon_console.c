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
F_6 ( V_2 , V_6 , V_7 , V_8 ) ;
V_7 [ V_8 ] = 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_2 V_11 )
{
T_2 V_12 ;
T_2 V_13 ;
if ( ! V_2 -> V_14 )
V_2 -> V_14 =
F_3 ( V_2 ,
V_15 ) ;
V_12 =
( T_2 ) F_8 ( V_2 , V_12 ) ;
V_13 =
( T_2 ) F_8 ( V_2 , V_13 ) ;
F_9 ( & V_2 -> V_16 -> V_17 , L_1 , V_18 ,
V_12 ) ;
if ( ( V_12 > 3 ) ||
( V_11 && V_12 != V_11 ) ) {
F_10 ( & V_2 -> V_16 -> V_17 , L_2 ,
V_12 , V_13 ,
F_11 ( V_2 -> V_14 ) ) ;
return - 1 ;
} else {
return 0 ;
}
}
static const struct V_9
* F_12 ( struct V_1 * V_2 ,
const char * V_10 , T_2 V_19 )
{
struct V_9 * V_20 =
& V_2 -> V_21 ;
T_1 V_22 = F_13 ( V_2 , V_10 , V_19 ) ;
if ( V_22 ) {
V_20 -> V_23 = F_14 ( V_2 , V_22 ,
V_23 ) ;
V_20 -> V_5 =
F_14 ( V_2 , V_22 , V_5 ) ;
strncpy ( V_20 -> V_10 , V_10 , sizeof( V_20 -> V_10 ) ) ;
V_20 -> V_10 [ sizeof( V_20 -> V_10 ) - 1 ] = 0 ;
return & V_2 -> V_21 ;
} else {
return NULL ;
}
}
static T_1 F_13 ( struct V_1 * V_2 ,
const char * V_10 ,
T_2 V_19 )
{
T_1 V_24 = 0 ;
F_15 ( V_19 ) ;
if ( ! F_7 ( V_2 , 3 ) ) {
T_2 V_25 ;
T_1 V_26 =
F_8 ( V_2 ,
V_26 ) ;
T_2 V_27 = ( T_2 )
F_8 ( V_2 , V_28 ) ;
T_2 V_29 = ( T_2 )
F_8 ( V_2 , V_30 ) ;
T_1 V_22 = V_26 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
T_1 V_31 =
F_14 ( V_2 , V_22 ,
V_5 ) ;
if ( V_10 && V_31 ) {
char * V_32 =
F_16 ( V_29 + 1 , V_33 ) ;
F_4 ( V_2 , V_22 ,
V_32 ,
V_29 ) ;
if ( ! strncmp ( V_10 , V_32 , V_29 ) ) {
V_24 = V_22 ;
F_17 ( V_32 ) ;
break;
}
F_17 ( V_32 ) ;
} else if ( ! V_10 && ! V_31 ) {
V_24 = V_22 ;
break;
}
V_22 +=
sizeof( struct V_9 ) ;
}
}
F_18 ( V_19 ) ;
return V_24 ;
}
static int F_19 ( struct V_1 * V_2 , const char * V_10 ,
T_1 * V_23 , T_1 * V_5 )
{
const struct V_9 * V_34 ;
F_20 () ;
V_34 = F_12 ( V_2 , V_10 , 0 ) ;
F_21 () ;
if ( V_34 ) {
* V_23 = V_34 -> V_23 ;
* V_5 = V_34 -> V_5 ;
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
int F_22 ( struct V_1 * V_2 , char * V_35 ,
T_2 V_36 )
{
T_2 V_8 = strlen ( V_35 ) ;
F_9 ( & V_2 -> V_16 -> V_17 , L_3 , V_35 ) ;
if ( V_8 > V_37 - 1 ) {
F_10 ( & V_2 -> V_16 -> V_17 , L_4 ,
V_37 - 1 ) ;
return - 1 ;
}
if ( F_23 ( V_2 , V_36 ) != 0 ) {
F_10 ( & V_2 -> V_16 -> V_17 , L_5 ) ;
return - 1 ;
}
F_20 () ;
F_24 ( V_2 , V_38 ,
( V_39 * ) V_35 , V_8 ) ;
F_25 ( V_2 , V_40 ,
V_8 ) ;
F_25 ( V_2 , V_41 ,
V_42 ) ;
if ( F_23 ( V_2 , 200 ) != 0 ) {
F_21 () ;
F_10 ( & V_2 -> V_16 -> V_17 , L_6 ) ;
return - 1 ;
}
F_21 () ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 ,
T_2 V_43 )
{
F_9 ( & V_2 -> V_16 -> V_17 , L_7 ,
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
T_3 V_46 ,
char * V_47 , T_4 V_48 )
{
struct V_49 * V_50 ;
V_50 = & V_2 -> V_50 [ V_46 ] ;
V_50 -> V_51 = 0 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
T_3 V_46 ,
char * V_52 ,
T_4 V_48 )
{
char * line ;
T_4 V_25 ;
line = V_52 ;
for ( V_25 = 0 ; V_25 < V_48 ; V_25 ++ ) {
if ( V_52 [ V_25 ] == '\n' ) {
V_52 [ V_25 ] = '\0' ;
if ( V_50 -> V_53 [ 0 ] ) {
F_30 ( & V_2 -> V_16 -> V_17 , L_8 ,
V_46 , V_50 -> V_53 ,
line ) ;
V_50 -> V_53 [ 0 ] = '\0' ;
} else {
F_30 ( & V_2 -> V_16 -> V_17 , L_9 ,
V_46 , line ) ;
}
line = & V_52 [ V_25 + 1 ] ;
}
}
if ( line != & V_52 [ V_48 ] ) {
V_52 [ V_48 ] = '\0' ;
strcpy ( V_50 -> V_53 , line ) ;
}
}
static void F_31 ( struct V_54 * V_55 )
{
T_4 V_48 , V_56 , V_57 ;
struct V_49 * V_50 ;
struct V_58 * V_59 = (struct V_58 * ) V_55 ;
struct V_1 * V_2 = (struct V_1 * ) V_59 -> V_60 ;
T_3 V_46 = V_59 -> V_61 ;
T_2 V_62 ;
V_50 = & V_2 -> V_50 [ V_46 ] ;
V_56 = 0 ;
V_57 = 0 ;
do {
V_48 =
F_32 ( V_2 , V_46 , V_52 ,
sizeof( V_52 ) - 1 , 0 ) ;
if ( V_48 > 0 ) {
V_57 += V_48 ;
if ( V_50 -> V_51 ) {
F_28 ( V_2 , V_46 ,
V_52 ,
V_48 ) ;
}
if ( F_33 ( V_46 ) ) {
F_29 ( V_2 , V_50 , V_46 ,
V_52 , V_48 ) ;
}
} else if ( V_48 < 0 ) {
F_10 ( & V_2 -> V_16 -> V_17 , L_10 ,
V_46 , V_48 ) ;
}
V_56 ++ ;
} while ( ( V_48 > 0 ) && ( V_56 < 16 ) );
if ( F_33 ( V_46 ) &&
( V_57 == 0 ) && ( V_50 -> V_53 [ 0 ] ) ) {
F_30 ( & V_2 -> V_16 -> V_17 , L_9 ,
V_46 , V_50 -> V_53 ) ;
V_50 -> V_53 [ 0 ] = '\0' ;
}
V_62 = V_63 ;
F_34 ( & V_59 -> V_55 , F_35 ( V_62 ) ) ;
}
int F_36 ( struct V_1 * V_2 )
{
int V_64 = 0 ;
T_1 V_6 , V_5 ;
V_64 = F_26 ( V_2 ) ;
if ( V_64 ) {
F_10 ( & V_2 -> V_16 -> V_17 , L_11 ) ;
return V_64 ;
}
V_64 = F_19 ( V_2 , V_65 , & V_6 ,
& V_5 ) ;
if ( V_64 ) {
F_10 ( & V_2 -> V_16 -> V_17 , L_12 ,
V_65 ) ;
return V_64 ;
}
V_2 -> V_66 = F_2 ( V_2 ,
V_6 + F_5 ( struct V_67 ,
V_66 ) ) ;
V_2 -> V_68 = V_6 ;
F_9 ( & V_2 -> V_16 -> V_17 , L_13 ,
V_2 -> V_66 ) ;
return V_64 ;
}
int F_37 ( struct V_1 * V_2 , T_2 V_46 )
{
int V_64 = 0 ;
T_2 V_62 ;
T_1 V_69 ;
struct V_70 * V_55 ;
struct V_49 * V_50 ;
if ( V_46 >= V_2 -> V_66 ) {
F_10 ( & V_2 -> V_16 -> V_17 ,
L_14 ,
V_46 , V_2 -> V_66 ) ;
} else {
V_50 = & V_2 -> V_50 [ V_46 ] ;
V_50 -> V_51 = 0 ;
V_69 = V_2 -> V_68 + V_46 * 8 +
F_5 ( struct V_67 ,
V_71 ) ;
V_50 -> V_6 = F_3 ( V_2 , V_69 ) ;
V_69 = V_50 -> V_6 + F_5 ( struct V_72 ,
V_73 ) ;
V_50 -> V_74 = F_2 ( V_2 , V_69 ) ;
V_69 = V_50 -> V_6 + F_5 ( struct V_72 ,
V_75 ) ;
V_50 -> V_75 =
F_3 ( V_2 , V_69 ) ;
V_69 = V_50 -> V_6 + F_5 ( struct V_72 ,
V_76 ) ;
V_50 -> V_76 =
F_3 ( V_2 , V_69 ) ;
V_50 -> V_53 [ 0 ] = '\0' ;
V_55 = & V_2 -> V_77 [ V_46 ] . V_55 ;
F_38 ( V_55 , F_31 ) ;
V_2 -> V_77 [ V_46 ] . V_60 = ( void * ) V_2 ;
V_2 -> V_77 [ V_46 ] . V_61 = V_46 ;
V_62 = V_63 ;
F_34 ( V_55 , F_35 ( V_62 ) ) ;
if ( F_33 ( V_46 ) ) {
V_64 = F_22 ( V_2 ,
L_15 ,
2000 ) ;
}
V_50 -> V_78 = 1 ;
}
return V_64 ;
}
void F_39 ( struct V_1 * V_2 )
{
T_2 V_25 ;
struct V_49 * V_50 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_66 ; V_25 ++ ) {
V_50 = & V_2 -> V_50 [ V_25 ] ;
if ( ! V_50 -> V_78 )
continue;
F_40 ( & V_2 -> V_77 [ V_25 ] .
V_55 ) ;
V_50 -> V_6 = 0 ;
V_50 -> V_74 = 0 ;
V_50 -> V_75 = 0 ;
V_50 -> V_76 = 0 ;
}
V_2 -> V_66 = 0 ;
}
static inline int F_41 ( T_2 V_74 ,
T_2 V_79 ,
T_2 V_80 )
{
if ( V_80 >= V_74 || V_79 >= V_74 )
return - 1 ;
return ( ( V_74 - 1 ) - ( V_79 - V_80 ) ) % V_74 ;
}
static inline int F_42 ( T_2 V_74 ,
T_2 V_79 ,
T_2 V_80 )
{
if ( V_80 >= V_74 || V_79 >= V_74 )
return - 1 ;
return V_74 - 1 -
F_41 ( V_74 , V_79 , V_80 ) ;
}
int F_32 ( struct V_1 * V_2 , T_2 V_46 ,
char * V_47 , T_2 V_73 , T_2 V_19 )
{
int V_81 ;
T_2 V_80 , V_79 ;
struct V_49 * V_50 ;
if ( V_46 >= V_2 -> V_66 ) {
F_10 ( & V_2 -> V_16 -> V_17 , L_16 ,
V_46 ) ;
return 0 ;
}
V_50 = & V_2 -> V_50 [ V_46 ] ;
V_80 = F_2 ( V_2 , V_50 -> V_6 +
F_5 ( struct V_72 , V_82 ) ) ;
V_79 = F_2 ( V_2 , V_50 -> V_6 +
F_5 ( struct V_72 , V_83 ) ) ;
V_81 = F_42 ( V_50 -> V_74 ,
V_79 , V_80 ) ;
if ( V_81 <= 0 )
return V_81 ;
V_81 = F_43 ( V_81 , ( T_4 ) V_73 ) ;
if ( V_80 + V_81 >= V_50 -> V_74 )
V_81 = V_50 -> V_74 - V_80 ;
F_6 ( V_2 , V_50 -> V_76 + V_80 ,
V_47 , V_81 ) ;
F_25 ( V_2 , V_50 -> V_6 +
F_5 ( struct V_72 ,
V_82 ) ,
( V_80 + V_81 ) %
V_50 -> V_74 ) ;
return V_81 ;
}
