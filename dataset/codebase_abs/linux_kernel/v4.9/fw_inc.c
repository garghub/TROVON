static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
const struct V_5 * V_6 = ( const void * ) V_3 ;
struct V_7 V_8 ;
const struct V_7 * V_9 ;
T_3 V_10 ;
T_3 V_11 ;
if ( V_4 % 4 ) {
F_2 ( V_2 , L_1 , V_4 ) ;
return - V_12 ;
}
if ( V_4 < sizeof( * V_6 ) + sizeof( V_8 ) ) {
F_2 ( V_2 , L_2 , V_4 ) ;
return - V_12 ;
}
if ( F_3 ( V_6 -> type ) != V_13 ) {
F_2 ( V_2 , L_3 ) ;
return - V_12 ;
}
V_9 = (struct V_7 * ) & V_6 [ 1 ] ;
V_11 = F_4 ( V_9 -> V_14 ) ;
if ( V_11 % 4 ) {
F_2 ( V_2 , L_4 , ( V_15 ) V_11 ) ;
return - V_12 ;
}
if ( V_4 < V_11 ) {
F_2 ( V_2 , L_5 ,
V_4 , ( V_15 ) V_11 ) ;
return - V_12 ;
}
if ( V_11 < sizeof( * V_6 ) + sizeof( V_8 ) ) {
F_2 ( V_2 , L_6 , ( V_15 ) V_11 ) ;
return - V_12 ;
}
if ( F_4 ( V_9 -> V_16 ) != V_17 ) {
F_2 ( V_2 , L_7 ,
F_4 ( V_9 -> V_16 ) ) ;
return - V_12 ;
}
if ( F_4 ( V_9 -> V_18 ) > V_19 ) {
F_2 ( V_2 , L_8 ,
F_4 ( V_9 -> V_18 ) ) ;
return - V_12 ;
}
V_8 = * V_9 ;
V_8 . V_10 = 0 ;
V_10 = F_5 ( ~ 0 , ( unsigned char const * ) V_6 , sizeof( * V_6 ) ) ;
V_10 = F_5 ( V_10 , ( unsigned char const * ) & V_8 , sizeof( V_8 ) ) ;
V_10 = F_5 ( V_10 , ( unsigned char const * ) & V_9 [ 1 ] ,
V_11 - sizeof( * V_6 ) - sizeof( V_8 ) ) ;
V_10 = ~ V_10 ;
if ( V_10 != F_4 ( V_9 -> V_10 ) ) {
F_2 ( V_2 , L_9
L_10 ,
( V_15 ) V_11 , V_10 , F_4 ( V_9 -> V_10 ) ) ;
return - V_12 ;
}
return ( int ) V_11 ;
}
static int F_6 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 )
{
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 )
{
F_8 ( L_11 , V_20 , 16 , 1 , V_3 , V_4 , true ) ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 )
{
const struct V_21 * V_22 = V_3 ;
T_2 V_23 ;
if ( V_4 < sizeof( * V_22 ) ||
F_4 ( V_22 -> V_24 ) != V_25 )
return 0 ;
V_23 = V_4 - F_10 ( struct V_21 ,
V_26 ) ;
F_11 ( V_2 -> V_27 , V_28 ) ;
memcpy ( V_2 -> V_27 , V_22 -> V_26 ,
F_12 ( sizeof( V_2 -> V_27 ) , V_23 ) ) ;
F_8 ( L_12 , V_20 , 16 , 1 ,
V_22 -> V_26 , V_23 , false ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 )
{
const struct V_29 * V_30 = V_3 ;
void T_4 * V_31 ;
T_2 V_32 = V_4 - sizeof( * V_30 ) ;
if ( V_4 < sizeof( * V_30 ) + sizeof( T_3 ) ) {
F_2 ( V_2 , L_13 , V_4 ) ;
return - V_12 ;
}
F_14 ( V_31 , V_30 -> V_33 , L_14 ) ;
F_15 ( V_2 , L_15 , F_4 ( V_30 -> V_33 ) ,
V_32 ) ;
F_16 ( V_31 , V_30 -> V_3 , V_32 ) ;
F_17 () ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 )
{
const struct V_34 * V_30 = V_3 ;
void T_4 * V_31 ;
T_3 V_35 ;
T_2 V_32 = ( T_2 ) F_4 ( V_30 -> V_4 ) ;
if ( V_4 != sizeof( * V_30 ) ) {
F_2 ( V_2 , L_16 , V_4 ) ;
return - V_12 ;
}
if ( V_32 < sizeof( T_3 ) ) {
F_2 ( V_2 , L_17 , V_32 ) ;
return - V_12 ;
}
if ( V_32 % sizeof( T_3 ) ) {
F_2 ( V_2 , L_18 , V_32 ) ;
return - V_12 ;
}
F_14 ( V_31 , V_30 -> V_33 , L_14 ) ;
V_35 = F_4 ( V_30 -> V_36 ) ;
F_15 ( V_2 , L_19 ,
F_4 ( V_30 -> V_33 ) , V_35 , V_32 ) ;
F_19 ( V_31 , V_35 , V_32 ) ;
F_17 () ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 )
{
const struct V_7 * V_30 = V_3 ;
if ( V_4 != sizeof( * V_30 ) ) {
F_2 ( V_2 , L_20 , V_4 ) ;
return - V_12 ;
}
F_15 ( V_2 , L_21 ,
V_30 -> V_18 , V_30 -> V_14 ) ;
F_8 ( L_11 , V_20 , 16 , 1 , V_30 -> V_37 ,
sizeof( V_30 -> V_37 ) , true ) ;
if ( ! memcmp ( V_30 -> V_37 , V_38 ,
V_39 ) )
memcpy ( V_2 -> V_40 ,
V_30 -> V_37 + V_39 ,
F_12 ( sizeof( V_30 -> V_37 ) - V_39 ,
sizeof( V_2 -> V_40 ) - 1 ) ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 )
{
const struct V_41 * V_30 = V_3 ;
const struct V_42 * V_43 = V_30 -> V_3 ;
int V_44 , V_45 ;
if ( V_4 % sizeof( * V_43 ) ) {
F_2 ( V_2 , L_22 ,
sizeof( * V_43 ) , V_4 ) ;
return - V_12 ;
}
V_44 = V_4 / sizeof( * V_43 ) ;
for ( V_45 = 0 ; V_45 < V_44 ; V_45 ++ ) {
void T_4 * V_31 ;
T_3 V_46 = F_4 ( V_43 [ V_45 ] . V_47 ) ;
T_3 V_35 = F_4 ( V_43 [ V_45 ] . V_36 ) ;
T_3 V_48 , V_49 ;
F_14 ( V_31 , V_43 [ V_45 ] . V_33 , L_14 ) ;
V_48 = F_22 ( V_31 ) ;
V_49 = ( V_48 & V_46 ) | ( V_35 & ~ V_46 ) ;
F_15 ( V_2 , L_23
L_24 ,
F_4 ( V_43 [ V_45 ] . V_33 ) , V_49 , V_48 , V_35 , V_46 ) ;
F_23 ( V_49 , V_31 ) ;
F_17 () ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , void T_4 * V_50 ,
void T_4 * V_51 , void T_4 * V_52 , T_3 V_53 ,
T_3 V_54 )
{
unsigned V_55 = 0 ;
F_23 ( V_54 , V_50 ) ;
F_23 ( V_53 , V_51 ) ;
F_17 () ;
F_23 ( V_56 , V_52 ) ;
do {
F_25 ( 1 ) ;
if ( V_55 ++ > 100 ) {
F_2 ( V_2 , L_25 ) ;
return - V_12 ;
}
} while ( F_22 ( V_52 ) & V_57 );
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 )
{
const struct V_58 * V_30 = V_3 ;
const struct V_59 * V_43 = V_30 -> V_3 ;
void T_4 * V_50 ;
void T_4 * V_60 ;
void T_4 * V_51 ;
void T_4 * V_52 ;
T_3 V_53 ;
int V_44 , V_45 ;
if ( V_4 < sizeof( * V_30 ) + sizeof( * V_43 ) ) {
F_2 ( V_2 , L_26 , V_4 ) ;
return - V_12 ;
}
if ( ( V_4 - sizeof( * V_30 ) ) % sizeof( * V_43 ) ) {
F_2 ( V_2 , L_27
L_28 ,
sizeof( * V_43 ) , V_4 - sizeof( * V_30 ) ) ;
return - V_12 ;
}
V_44 = ( V_4 - sizeof( * V_30 ) ) / sizeof( * V_43 ) ;
V_53 = F_4 ( V_30 -> V_61 ) ;
F_15 ( V_2 , L_29 ,
V_44 , V_53 ) ;
F_14 ( V_50 , V_30 -> V_62 , L_30 ) ;
F_14 ( V_60 , V_30 -> V_63 , L_31 ) ;
F_14 ( V_51 , V_30 -> V_64 , L_32 ) ;
F_14 ( V_52 , V_30 -> V_65 , L_33 ) ;
F_15 ( V_2 , L_34
L_35 ,
F_4 ( V_30 -> V_62 ) ,
F_4 ( V_30 -> V_63 ) ,
F_4 ( V_30 -> V_64 ) ,
F_4 ( V_30 -> V_65 ) ) ;
for ( V_45 = 0 ; V_45 < V_44 ; V_45 ++ ) {
int V_66 ;
T_3 V_54 = F_4 ( V_43 [ V_45 ] . V_33 ) ;
T_3 V_35 = F_4 ( V_43 [ V_45 ] . V_36 ) ;
F_15 ( V_2 , L_36 ,
V_45 , V_54 , V_35 ) ;
F_23 ( V_35 , V_60 ) ;
V_66 = F_24 ( V_2 , V_50 , V_51 , V_52 , V_53 , V_54 ) ;
if ( V_66 )
return V_66 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 )
{
const struct V_67 * V_30 = V_3 ;
const struct V_68 * V_43 = V_30 -> V_3 ;
void T_4 * V_50 ;
void T_4 * V_60 [ F_28 ( V_43 -> V_36 ) ] ;
void T_4 * V_51 ;
void T_4 * V_52 ;
T_3 V_53 ;
int V_44 , V_45 , V_69 ;
if ( V_4 < sizeof( * V_30 ) + sizeof( * V_43 ) ) {
F_2 ( V_2 , L_37 , V_4 ) ;
return - V_12 ;
}
if ( ( V_4 - sizeof( * V_30 ) ) % sizeof( * V_43 ) ) {
F_2 ( V_2 , L_38
L_28 ,
sizeof( * V_43 ) , V_4 - sizeof( * V_30 ) ) ;
return - V_12 ;
}
V_44 = ( V_4 - sizeof( * V_30 ) ) / sizeof( * V_43 ) ;
V_53 = F_4 ( V_30 -> V_61 ) ;
F_15 ( V_2 , L_39 ,
V_44 , V_53 ) ;
F_14 ( V_50 , V_30 -> V_62 , L_30 ) ;
for ( V_69 = 0 ; V_69 < F_28 ( V_43 -> V_36 ) ; V_69 ++ )
F_14 ( V_60 [ V_69 ] , V_30 -> V_63 [ V_69 ] ,
L_31 ) ;
F_14 ( V_51 , V_30 -> V_64 , L_32 ) ;
F_14 ( V_52 , V_30 -> V_65 , L_33 ) ;
F_15 ( V_2 , L_40 ,
F_4 ( V_30 -> V_62 ) ,
F_4 ( V_30 -> V_64 ) ,
F_4 ( V_30 -> V_65 ) ) ;
F_8 ( L_41 , V_70 , 16 , 4 ,
V_30 -> V_63 , sizeof( V_30 -> V_63 ) ,
false ) ;
for ( V_45 = 0 ; V_45 < V_44 ; V_45 ++ ) {
int V_66 ;
T_3 V_54 = F_4 ( V_43 [ V_45 ] . V_33 ) ;
T_3 V_35 [ F_28 ( V_43 -> V_36 ) ] ;
for ( V_69 = 0 ; V_69 < F_28 ( V_43 -> V_36 ) ; V_69 ++ )
V_35 [ V_69 ] = F_4 ( V_43 [ V_45 ] . V_36 [ V_69 ] ) ;
F_15 ( V_2 , L_42 , V_45 , V_54 ) ;
F_8 ( L_43 , V_70 , 16 , 4 , V_35 ,
sizeof( V_35 ) , false ) ;
for ( V_69 = 0 ; V_69 < F_28 ( V_43 -> V_36 ) ; V_69 ++ )
F_23 ( V_35 [ V_69 ] , V_60 [ V_69 ] ) ;
V_66 = F_24 ( V_2 , V_50 , V_51 , V_52 , V_53 , V_54 ) ;
if ( V_66 )
return V_66 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , int type ,
const void * V_3 , T_2 V_4 , bool V_71 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < F_28 ( V_72 ) ; V_45 ++ )
if ( V_72 [ V_45 ] . type == type )
return V_71 ?
V_72 [ V_45 ] . F_30 (
V_2 , V_3 , V_4 ) :
V_72 [ V_45 ] . F_31 (
V_2 , V_3 , V_4 ) ;
F_2 ( V_2 , L_44 , type ) ;
return - V_12 ;
}
static int F_32 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 , bool V_71 )
{
int V_66 = 0 ;
const struct V_5 * V_6 ;
T_2 V_32 , V_73 ;
for ( V_6 = V_3 ; ; V_6 = ( const void * ) V_6 + V_32 , V_4 -= V_32 ) {
if ( V_4 < sizeof( * V_6 ) )
break;
V_73 = F_4 ( V_6 -> V_4 ) ;
V_32 = sizeof( * V_6 ) + V_73 ;
if ( V_32 > V_4 )
break;
if ( V_73 % 4 ) {
F_2 ( V_2 , L_45 ,
V_73 ) ;
return - V_12 ;
}
V_66 = F_29 ( V_2 , F_3 ( V_6 -> type ) ,
& V_6 [ 1 ] , V_73 , V_71 ) ;
if ( V_66 )
return V_66 ;
}
if ( V_4 ) {
F_2 ( V_2 , L_46 , V_4 ) ;
if ( V_4 >= sizeof( * V_6 ) ) {
F_2 ( V_2 , L_47
L_48 ,
( long ) ( ( const void * ) V_6 - V_3 ) ,
F_3 ( V_6 -> type ) , V_73 ) ;
}
return - V_12 ;
}
return V_66 ;
}
int F_33 ( struct V_1 * V_2 , const char * V_74 ,
bool V_71 )
{
int V_66 , V_75 ;
const struct V_76 * V_77 ;
T_2 V_78 ;
const void * V_30 ;
V_66 = F_34 ( & V_77 , V_74 , F_35 ( V_2 ) ) ;
if ( V_66 ) {
F_2 ( V_2 , L_49 , V_74 ) ;
return V_66 ;
}
F_15 ( V_2 , L_50 , V_74 , V_77 -> V_4 ) ;
for ( V_78 = V_77 -> V_4 , V_30 = V_77 -> V_3 ; V_78 ; V_78 -= V_75 , V_30 += V_75 ) {
V_75 = F_1 ( V_2 , V_30 , V_78 ) ;
if ( V_75 < 0 ) {
V_66 = V_75 ;
goto V_79;
}
V_66 = F_32 ( V_2 , V_30 , V_75 , V_71 ) ;
if ( V_66 < 0 )
goto V_79;
}
V_79:
F_36 ( V_77 ) ;
return V_66 ;
}
