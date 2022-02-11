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
F_7 ( L_11 , V_20 , 16 , 1 , V_3 , V_4 , true ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 )
{
const struct V_21 * V_22 = V_3 ;
void T_4 * V_23 ;
T_2 V_24 = V_4 - sizeof( * V_22 ) ;
if ( V_4 < sizeof( * V_22 ) + sizeof( T_3 ) ) {
F_2 ( V_2 , L_12 , V_4 ) ;
return - V_12 ;
}
F_9 ( V_23 , V_22 -> V_25 , L_13 ) ;
F_10 ( V_2 , L_14 , F_4 ( V_22 -> V_25 ) ,
V_24 ) ;
F_11 ( V_23 , V_22 -> V_3 , V_24 ) ;
F_12 () ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 )
{
const struct V_26 * V_22 = V_3 ;
void T_4 * V_23 ;
T_3 V_27 ;
T_2 V_24 = ( T_2 ) F_4 ( V_22 -> V_4 ) ;
if ( V_4 != sizeof( * V_22 ) ) {
F_2 ( V_2 , L_15 , V_4 ) ;
return - V_12 ;
}
if ( V_24 < sizeof( T_3 ) ) {
F_2 ( V_2 , L_16 , V_24 ) ;
return - V_12 ;
}
if ( V_24 % sizeof( T_3 ) ) {
F_2 ( V_2 , L_17 , V_24 ) ;
return - V_12 ;
}
F_9 ( V_23 , V_22 -> V_25 , L_13 ) ;
V_27 = F_4 ( V_22 -> V_28 ) ;
F_10 ( V_2 , L_18 ,
F_4 ( V_22 -> V_25 ) , V_27 , V_24 ) ;
F_14 ( V_23 , V_27 , V_24 ) ;
F_12 () ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 )
{
const struct V_7 * V_22 = V_3 ;
if ( V_4 != sizeof( * V_22 ) ) {
F_2 ( V_2 , L_19 , V_4 ) ;
return - V_12 ;
}
F_10 ( V_2 , L_20 ,
V_22 -> V_18 , V_22 -> V_14 ) ;
F_7 ( L_11 , V_20 , 16 , 1 , V_22 -> V_29 ,
sizeof( V_22 -> V_29 ) , true ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 )
{
const struct V_30 * V_22 = V_3 ;
const struct V_31 * V_32 = V_22 -> V_3 ;
int V_33 , V_34 ;
if ( V_4 % sizeof( * V_32 ) ) {
F_2 ( V_2 , L_21 ,
sizeof( * V_32 ) , V_4 ) ;
return - V_12 ;
}
V_33 = V_4 / sizeof( * V_32 ) ;
for ( V_34 = 0 ; V_34 < V_33 ; V_34 ++ ) {
void T_4 * V_23 ;
T_3 V_35 = F_4 ( V_32 [ V_34 ] . V_36 ) ;
T_3 V_27 = F_4 ( V_32 [ V_34 ] . V_28 ) ;
T_3 V_37 , V_38 ;
F_9 ( V_23 , V_32 [ V_34 ] . V_25 , L_13 ) ;
V_37 = F_17 ( V_23 ) ;
V_38 = ( V_37 & V_35 ) | ( V_27 & ~ V_35 ) ;
F_10 ( V_2 , L_22
L_23 ,
F_4 ( V_32 [ V_34 ] . V_25 ) , V_38 , V_37 , V_27 , V_35 ) ;
F_18 ( V_38 , V_23 ) ;
F_12 () ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , void T_4 * V_39 ,
void T_4 * V_40 , void T_4 * V_41 , T_3 V_42 ,
T_3 V_43 )
{
unsigned V_44 = 0 ;
F_18 ( V_43 , V_39 ) ;
F_18 ( V_42 , V_40 ) ;
F_12 () ;
F_18 ( V_45 , V_41 ) ;
do {
F_20 ( 1 ) ;
if ( V_44 ++ > 100 ) {
F_2 ( V_2 , L_24 ) ;
return - V_12 ;
}
} while ( F_17 ( V_41 ) & V_46 );
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 )
{
const struct V_47 * V_22 = V_3 ;
const struct V_48 * V_32 = V_22 -> V_3 ;
void T_4 * V_39 ;
void T_4 * V_49 ;
void T_4 * V_40 ;
void T_4 * V_41 ;
T_3 V_42 ;
int V_33 , V_34 ;
if ( V_4 < sizeof( * V_22 ) + sizeof( * V_32 ) ) {
F_2 ( V_2 , L_25 , V_4 ) ;
return - V_12 ;
}
if ( ( V_4 - sizeof( * V_22 ) ) % sizeof( * V_32 ) ) {
F_2 ( V_2 , L_26
L_27 ,
sizeof( * V_32 ) , V_4 - sizeof( * V_22 ) ) ;
return - V_12 ;
}
V_33 = ( V_4 - sizeof( * V_22 ) ) / sizeof( * V_32 ) ;
V_42 = F_4 ( V_22 -> V_50 ) ;
F_10 ( V_2 , L_28 ,
V_33 , V_42 ) ;
F_9 ( V_39 , V_22 -> V_51 , L_29 ) ;
F_9 ( V_49 , V_22 -> V_52 , L_30 ) ;
F_9 ( V_40 , V_22 -> V_53 , L_31 ) ;
F_9 ( V_41 , V_22 -> V_54 , L_32 ) ;
F_10 ( V_2 , L_33
L_34 ,
F_4 ( V_22 -> V_51 ) ,
F_4 ( V_22 -> V_52 ) ,
F_4 ( V_22 -> V_53 ) ,
F_4 ( V_22 -> V_54 ) ) ;
for ( V_34 = 0 ; V_34 < V_33 ; V_34 ++ ) {
int V_55 ;
T_3 V_43 = F_4 ( V_32 [ V_34 ] . V_25 ) ;
T_3 V_27 = F_4 ( V_32 [ V_34 ] . V_28 ) ;
F_10 ( V_2 , L_35 ,
V_34 , V_43 , V_27 ) ;
F_18 ( V_27 , V_49 ) ;
V_55 = F_19 ( V_2 , V_39 , V_40 , V_41 , V_42 , V_43 ) ;
if ( V_55 )
return V_55 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , const void * V_3 ,
T_2 V_4 )
{
const struct V_56 * V_22 = V_3 ;
const struct V_57 * V_32 = V_22 -> V_3 ;
void T_4 * V_39 ;
void T_4 * V_49 [ F_23 ( V_32 -> V_28 ) ] ;
void T_4 * V_40 ;
void T_4 * V_41 ;
T_3 V_42 ;
int V_33 , V_34 , V_58 ;
if ( V_4 < sizeof( * V_22 ) + sizeof( * V_32 ) ) {
F_2 ( V_2 , L_36 , V_4 ) ;
return - V_12 ;
}
if ( ( V_4 - sizeof( * V_22 ) ) % sizeof( * V_32 ) ) {
F_2 ( V_2 , L_37
L_27 ,
sizeof( * V_32 ) , V_4 - sizeof( * V_22 ) ) ;
return - V_12 ;
}
V_33 = ( V_4 - sizeof( * V_22 ) ) / sizeof( * V_32 ) ;
V_42 = F_4 ( V_22 -> V_50 ) ;
F_10 ( V_2 , L_38 ,
V_33 , V_42 ) ;
F_9 ( V_39 , V_22 -> V_51 , L_29 ) ;
for ( V_58 = 0 ; V_58 < F_23 ( V_32 -> V_28 ) ; V_58 ++ )
F_9 ( V_49 [ V_58 ] , V_22 -> V_52 [ V_58 ] ,
L_30 ) ;
F_9 ( V_40 , V_22 -> V_53 , L_31 ) ;
F_9 ( V_41 , V_22 -> V_54 , L_32 ) ;
F_10 ( V_2 , L_39 ,
F_4 ( V_22 -> V_51 ) ,
F_4 ( V_22 -> V_53 ) ,
F_4 ( V_22 -> V_54 ) ) ;
F_7 ( L_40 , V_59 , 16 , 4 ,
V_22 -> V_52 , sizeof( V_22 -> V_52 ) ,
false ) ;
for ( V_34 = 0 ; V_34 < V_33 ; V_34 ++ ) {
int V_55 ;
T_3 V_43 = F_4 ( V_32 [ V_34 ] . V_25 ) ;
T_3 V_27 [ F_23 ( V_32 -> V_28 ) ] ;
for ( V_58 = 0 ; V_58 < F_23 ( V_32 -> V_28 ) ; V_58 ++ )
V_27 [ V_58 ] = F_4 ( V_32 [ V_34 ] . V_28 [ V_58 ] ) ;
F_10 ( V_2 , L_41 , V_34 , V_43 ) ;
F_7 ( L_42 , V_59 , 16 , 4 , V_27 ,
sizeof( V_27 ) , false ) ;
for ( V_58 = 0 ; V_58 < F_23 ( V_32 -> V_28 ) ; V_58 ++ )
F_18 ( V_27 [ V_58 ] , V_49 [ V_58 ] ) ;
V_55 = F_19 ( V_2 , V_39 , V_40 , V_41 , V_42 , V_43 ) ;
if ( V_55 )
return V_55 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int type ,
const void * V_3 , T_2 V_4 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < F_23 ( V_60 ) ; V_34 ++ ) {
if ( V_60 [ V_34 ] . type == type )
return V_60 [ V_34 ] . F_25 ( V_2 , V_3 , V_4 ) ;
}
F_2 ( V_2 , L_43 , type ) ;
return - V_12 ;
}
static int F_26 ( struct V_1 * V_2 , const void * V_3 , T_2 V_4 )
{
int V_55 = 0 ;
const struct V_5 * V_6 ;
T_2 V_24 , V_61 ;
for ( V_6 = V_3 ; ; V_6 = ( const void * ) V_6 + V_24 , V_4 -= V_24 ) {
if ( V_4 < sizeof( * V_6 ) )
break;
V_61 = F_4 ( V_6 -> V_4 ) ;
V_24 = sizeof( * V_6 ) + V_61 ;
if ( V_24 > V_4 )
break;
if ( V_61 % 4 ) {
F_2 ( V_2 , L_44 ,
V_61 ) ;
return - V_12 ;
}
V_55 = F_24 ( V_2 , F_3 ( V_6 -> type ) ,
& V_6 [ 1 ] , V_61 ) ;
if ( V_55 )
return V_55 ;
}
if ( V_4 ) {
F_2 ( V_2 , L_45 , V_4 ) ;
if ( V_4 >= sizeof( * V_6 ) ) {
F_2 ( V_2 , L_46
L_47 ,
( long ) ( ( const void * ) V_6 - V_3 ) ,
F_3 ( V_6 -> type ) , V_61 ) ;
}
return - V_12 ;
}
F_27 ( V_62 , 1 ) ;
return V_55 ;
}
int F_28 ( struct V_1 * V_2 , const char * V_63 )
{
int V_55 , V_64 ;
const struct V_65 * V_66 ;
T_2 V_67 ;
const void * V_22 ;
V_55 = F_29 ( & V_66 , V_63 , F_30 ( V_2 ) ) ;
if ( V_55 ) {
F_2 ( V_2 , L_48 , V_63 ) ;
return V_55 ;
}
F_10 ( V_2 , L_49 , V_63 , V_66 -> V_4 ) ;
for ( V_67 = V_66 -> V_4 , V_22 = V_66 -> V_3 ; V_67 ; V_67 -= V_64 , V_22 += V_64 ) {
V_64 = F_1 ( V_2 , V_22 , V_67 ) ;
if ( V_64 < 0 ) {
V_55 = V_64 ;
goto V_68;
}
V_55 = F_26 ( V_2 , V_22 , V_64 ) ;
if ( V_55 < 0 )
goto V_68;
}
V_68:
F_31 ( V_66 ) ;
return V_55 ;
}
