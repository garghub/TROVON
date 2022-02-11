static inline int F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 , T_1 V_4 )
{
T_1 V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ )
if ( V_1 -> V_7 [ V_5 + V_3 -> V_6 ] == V_4 )
return V_1 -> V_7 [ V_5 ] ;
return - 1 ;
}
static inline void F_2 ( unsigned short * V_7 ,
const unsigned int * V_8 ,
unsigned short V_9 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_9 ; V_5 ++ ) {
V_7 [ V_5 ] = V_8 [ V_5 ] & 0xffff ;
V_7 [ V_5 + V_9 ] = V_8 [ V_5 ] >> 16 ;
}
}
static inline T_1 F_3 ( T_2 V_10 )
{
T_2 V_11 = F_4 () ;
return ( ( ( ( V_11 / 1000 ) * V_10 ) / 1024 ) - 1 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_1 )
{
return ( F_6 () & V_12 ) ;
}
static inline void F_7 ( void )
{
F_8 ( 0xFFFF ) ;
F_9 ( 0xFFFF ) ;
}
static void F_10 ( unsigned long V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 ;
struct V_1 * V_1 = F_11 ( V_15 ) ;
if ( F_5 ( V_1 ) ) {
F_12 ( & V_1 -> V_16 ,
V_17 + V_1 -> V_18 ) ;
return;
}
F_13 ( V_1 -> V_3 , V_1 -> V_19 , 0 ) ;
F_14 ( V_1 -> V_3 ) ;
F_7 () ;
F_15 ( V_1 -> V_20 ) ;
}
static T_3 F_16 ( int V_20 , void * V_21 )
{
struct V_14 * V_15 = V_21 ;
struct V_1 * V_1 = F_11 ( V_15 ) ;
struct V_2 * V_3 = V_1 -> V_3 ;
int V_22 ;
T_1 V_23 = F_17 () ;
V_22 = F_1 ( V_1 , V_3 , V_23 ) ;
F_13 ( V_3 , V_22 , 1 ) ;
F_14 ( V_3 ) ;
if ( F_5 ( V_1 ) ) {
F_18 ( V_1 -> V_20 ) ;
V_1 -> V_19 = V_22 ;
F_12 ( & V_1 -> V_16 ,
V_17 + V_1 -> V_18 ) ;
} else {
F_13 ( V_3 , V_22 , 0 ) ;
F_14 ( V_3 ) ;
F_7 () ;
}
return V_24 ;
}
static int F_19 ( struct V_14 * V_15 )
{
struct V_1 * V_1 ;
struct V_25 * V_26 = F_20 ( & V_15 -> V_27 ) ;
struct V_2 * V_3 ;
int V_5 , error ;
if ( ! V_26 -> V_28 || ! V_26 -> V_29 || ! V_26 -> V_30 ) {
F_21 ( & V_15 -> V_27 , L_1 ) ;
return - V_31 ;
}
if ( ! V_26 -> V_9 ||
V_26 -> V_9 > ( V_26 -> V_28 * V_26 -> V_29 ) ) {
F_21 ( & V_15 -> V_27 , L_2 ) ;
return - V_31 ;
}
V_1 = F_22 ( sizeof( struct V_1 ) , V_32 ) ;
if ( ! V_1 )
return - V_33 ;
F_23 ( V_15 , V_1 ) ;
V_1 -> V_7 = F_24 ( V_26 -> V_9 *
sizeof( unsigned short ) * 2 , V_32 ) ;
if ( ! V_1 -> V_7 ) {
error = - V_33 ;
goto V_34;
}
if ( ! V_26 -> V_35 || V_26 -> V_35 > V_36 ||
! V_26 -> V_37 || V_26 -> V_37 > V_36 ) {
F_25 ( & V_15 -> V_27 ,
L_3 ) ;
F_26 ( 0xFF0 ) ;
} else {
F_26 (
( ( V_26 -> V_35 / V_38 )
& V_39 ) |
( ( ( V_26 -> V_37 / V_38 ) << 8 )
& V_40 ) ) ;
}
if ( ! V_26 -> V_41 )
V_1 -> V_18 = F_27 ( 50 ) ;
else
V_1 -> V_18 =
F_27 ( V_26 -> V_41 ) ;
if ( F_28 ( ( T_1 * ) & V_42 [ V_43 - V_26 -> V_28 ] ,
V_44 ) ) {
F_21 ( & V_15 -> V_27 , L_4 ) ;
error = - V_45 ;
goto V_46;
}
if ( F_28 ( ( T_1 * ) & V_47 [ V_43 - V_26 -> V_29 ] ,
V_44 ) ) {
F_21 ( & V_15 -> V_27 , L_4 ) ;
error = - V_45 ;
goto V_48;
}
V_1 -> V_20 = F_29 ( V_15 , 0 ) ;
if ( V_1 -> V_20 < 0 ) {
error = - V_49 ;
goto V_50;
}
error = F_30 ( V_1 -> V_20 , F_16 ,
0 , V_44 , V_15 ) ;
if ( error ) {
F_21 ( & V_15 -> V_27 , L_5 ,
V_1 -> V_20 ) ;
goto V_50;
}
V_3 = F_31 () ;
if ( ! V_3 ) {
error = - V_33 ;
goto V_51;
}
V_1 -> V_3 = V_3 ;
V_3 -> V_52 = V_15 -> V_52 ;
V_3 -> V_53 = L_6 ;
V_3 -> V_27 . V_54 = & V_15 -> V_27 ;
F_32 ( V_3 , V_1 ) ;
V_3 -> V_55 . V_56 = V_57 ;
V_3 -> V_55 . V_58 = 0x0001 ;
V_3 -> V_55 . V_59 = 0x0001 ;
V_3 -> V_55 . V_60 = 0x0100 ;
V_3 -> V_61 = sizeof( unsigned short ) ;
V_3 -> V_6 = V_26 -> V_9 ;
V_3 -> V_7 = V_1 -> V_7 ;
F_2 ( V_1 -> V_7 , V_26 -> V_30 , V_26 -> V_9 ) ;
F_33 ( V_62 , V_3 -> V_63 ) ;
if ( V_26 -> V_64 )
F_33 ( V_65 , V_3 -> V_63 ) ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ )
if ( V_1 -> V_7 [ V_5 ] <= V_66 )
F_33 ( V_1 -> V_7 [ V_5 ] , V_3 -> V_67 ) ;
F_34 ( V_68 , V_3 -> V_67 ) ;
error = F_35 ( V_3 ) ;
if ( error ) {
F_21 ( & V_15 -> V_27 , L_7 ) ;
goto V_69;
}
F_36 ( & V_1 -> V_16 , F_10 , ( unsigned long ) V_15 ) ;
F_37 ( F_3 ( V_38 ) ) ;
F_38 ( ( ( ( V_26 -> V_29 - 1 ) << 13 ) & V_70 ) |
( ( ( V_26 -> V_28 - 1 ) << 10 ) & V_71 ) |
( 2 & V_72 ) ) ;
F_38 ( F_39 () | V_73 ) ;
F_40 ( & V_15 -> V_27 , 1 ) ;
return 0 ;
V_69:
F_41 ( V_3 ) ;
V_51:
F_42 ( V_1 -> V_20 , V_15 ) ;
V_50:
F_43 ( ( T_1 * ) & V_47 [ V_43 - V_26 -> V_29 ] ) ;
V_48:
F_43 ( ( T_1 * ) & V_42 [ V_43 - V_26 -> V_28 ] ) ;
V_46:
F_44 ( V_1 -> V_7 ) ;
V_34:
F_44 ( V_1 ) ;
return error ;
}
static int F_45 ( struct V_14 * V_15 )
{
struct V_25 * V_26 = F_20 ( & V_15 -> V_27 ) ;
struct V_1 * V_1 = F_11 ( V_15 ) ;
F_46 ( & V_1 -> V_16 ) ;
F_42 ( V_1 -> V_20 , V_15 ) ;
F_47 ( V_1 -> V_3 ) ;
F_43 ( ( T_1 * ) & V_42 [ V_43 - V_26 -> V_28 ] ) ;
F_43 ( ( T_1 * ) & V_47 [ V_43 - V_26 -> V_29 ] ) ;
F_44 ( V_1 -> V_7 ) ;
F_44 ( V_1 ) ;
return 0 ;
}
static int F_48 ( struct V_14 * V_15 , T_4 V_74 )
{
struct V_1 * V_1 = F_11 ( V_15 ) ;
V_1 -> V_75 = F_49 () ;
V_1 -> V_76 = F_50 () ;
V_1 -> V_77 = F_39 () ;
if ( F_51 ( & V_15 -> V_27 ) )
F_52 ( V_1 -> V_20 ) ;
return 0 ;
}
static int F_53 ( struct V_14 * V_15 )
{
struct V_1 * V_1 = F_11 ( V_15 ) ;
F_26 ( V_1 -> V_75 ) ;
F_37 ( V_1 -> V_76 ) ;
F_38 ( V_1 -> V_77 ) ;
if ( F_51 ( & V_15 -> V_27 ) )
F_54 ( V_1 -> V_20 ) ;
return 0 ;
}
