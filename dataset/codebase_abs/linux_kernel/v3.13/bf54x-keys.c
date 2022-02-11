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
struct V_25 * V_26 = V_15 -> V_27 . V_28 ;
struct V_2 * V_3 ;
int V_5 , error ;
if ( ! V_26 -> V_29 || ! V_26 -> V_30 || ! V_26 -> V_31 ) {
F_20 ( & V_15 -> V_27 , L_1 ) ;
return - V_32 ;
}
if ( ! V_26 -> V_9 ||
V_26 -> V_9 > ( V_26 -> V_29 * V_26 -> V_30 ) ) {
F_20 ( & V_15 -> V_27 , L_2 ) ;
return - V_32 ;
}
V_1 = F_21 ( sizeof( struct V_1 ) , V_33 ) ;
if ( ! V_1 )
return - V_34 ;
F_22 ( V_15 , V_1 ) ;
V_1 -> V_7 = F_23 ( V_26 -> V_9 *
sizeof( unsigned short ) * 2 , V_33 ) ;
if ( ! V_1 -> V_7 ) {
error = - V_34 ;
goto V_35;
}
if ( ! V_26 -> V_36 || V_26 -> V_36 > V_37 ||
! V_26 -> V_38 || V_26 -> V_38 > V_37 ) {
F_24 ( & V_15 -> V_27 ,
L_3 ) ;
F_25 ( 0xFF0 ) ;
} else {
F_25 (
( ( V_26 -> V_36 / V_39 )
& V_40 ) |
( ( ( V_26 -> V_38 / V_39 ) << 8 )
& V_41 ) ) ;
}
if ( ! V_26 -> V_42 )
V_1 -> V_18 = F_26 ( 50 ) ;
else
V_1 -> V_18 =
F_26 ( V_26 -> V_42 ) ;
if ( F_27 ( ( T_1 * ) & V_43 [ V_44 - V_26 -> V_29 ] ,
V_45 ) ) {
F_20 ( & V_15 -> V_27 , L_4 ) ;
error = - V_46 ;
goto V_47;
}
if ( F_27 ( ( T_1 * ) & V_48 [ V_44 - V_26 -> V_30 ] ,
V_45 ) ) {
F_20 ( & V_15 -> V_27 , L_4 ) ;
error = - V_46 ;
goto V_49;
}
V_1 -> V_20 = F_28 ( V_15 , 0 ) ;
if ( V_1 -> V_20 < 0 ) {
error = - V_50 ;
goto V_51;
}
error = F_29 ( V_1 -> V_20 , F_16 ,
0 , V_45 , V_15 ) ;
if ( error ) {
F_20 ( & V_15 -> V_27 , L_5 ,
V_1 -> V_20 ) ;
goto V_51;
}
V_3 = F_30 () ;
if ( ! V_3 ) {
error = - V_34 ;
goto V_52;
}
V_1 -> V_3 = V_3 ;
V_3 -> V_53 = V_15 -> V_53 ;
V_3 -> V_54 = L_6 ;
V_3 -> V_27 . V_55 = & V_15 -> V_27 ;
F_31 ( V_3 , V_1 ) ;
V_3 -> V_56 . V_57 = V_58 ;
V_3 -> V_56 . V_59 = 0x0001 ;
V_3 -> V_56 . V_60 = 0x0001 ;
V_3 -> V_56 . V_61 = 0x0100 ;
V_3 -> V_62 = sizeof( unsigned short ) ;
V_3 -> V_6 = V_26 -> V_9 ;
V_3 -> V_7 = V_1 -> V_7 ;
F_2 ( V_1 -> V_7 , V_26 -> V_31 , V_26 -> V_9 ) ;
F_32 ( V_63 , V_3 -> V_64 ) ;
if ( V_26 -> V_65 )
F_32 ( V_66 , V_3 -> V_64 ) ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ )
if ( V_1 -> V_7 [ V_5 ] <= V_67 )
F_32 ( V_1 -> V_7 [ V_5 ] , V_3 -> V_68 ) ;
F_33 ( V_69 , V_3 -> V_68 ) ;
error = F_34 ( V_3 ) ;
if ( error ) {
F_20 ( & V_15 -> V_27 , L_7 ) ;
goto V_70;
}
F_35 ( & V_1 -> V_16 , F_10 , ( unsigned long ) V_15 ) ;
F_36 ( F_3 ( V_39 ) ) ;
F_37 ( ( ( ( V_26 -> V_30 - 1 ) << 13 ) & V_71 ) |
( ( ( V_26 -> V_29 - 1 ) << 10 ) & V_72 ) |
( 2 & V_73 ) ) ;
F_37 ( F_38 () | V_74 ) ;
F_39 ( & V_15 -> V_27 , 1 ) ;
return 0 ;
V_70:
F_40 ( V_3 ) ;
V_52:
F_41 ( V_1 -> V_20 , V_15 ) ;
V_51:
F_42 ( ( T_1 * ) & V_48 [ V_44 - V_26 -> V_30 ] ) ;
V_49:
F_42 ( ( T_1 * ) & V_43 [ V_44 - V_26 -> V_29 ] ) ;
V_47:
F_43 ( V_1 -> V_7 ) ;
V_35:
F_43 ( V_1 ) ;
return error ;
}
static int F_44 ( struct V_14 * V_15 )
{
struct V_25 * V_26 = V_15 -> V_27 . V_28 ;
struct V_1 * V_1 = F_11 ( V_15 ) ;
F_45 ( & V_1 -> V_16 ) ;
F_41 ( V_1 -> V_20 , V_15 ) ;
F_46 ( V_1 -> V_3 ) ;
F_42 ( ( T_1 * ) & V_43 [ V_44 - V_26 -> V_29 ] ) ;
F_42 ( ( T_1 * ) & V_48 [ V_44 - V_26 -> V_30 ] ) ;
F_43 ( V_1 -> V_7 ) ;
F_43 ( V_1 ) ;
return 0 ;
}
static int F_47 ( struct V_14 * V_15 , T_4 V_75 )
{
struct V_1 * V_1 = F_11 ( V_15 ) ;
V_1 -> V_76 = F_48 () ;
V_1 -> V_77 = F_49 () ;
V_1 -> V_78 = F_38 () ;
if ( F_50 ( & V_15 -> V_27 ) )
F_51 ( V_1 -> V_20 ) ;
return 0 ;
}
static int F_52 ( struct V_14 * V_15 )
{
struct V_1 * V_1 = F_11 ( V_15 ) ;
F_25 ( V_1 -> V_76 ) ;
F_36 ( V_1 -> V_77 ) ;
F_37 ( V_1 -> V_78 ) ;
if ( F_50 ( & V_15 -> V_27 ) )
F_53 ( V_1 -> V_20 ) ;
return 0 ;
}
