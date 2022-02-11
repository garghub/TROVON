static inline unsigned int F_1 ( T_1 V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( T_2 V_3 , T_1 V_1 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
T_2 V_6 ;
F_6 ( V_5 -> V_7 -> V_8 ) ;
F_7 ( V_5 -> V_7 -> V_8 ) ;
V_6 = F_1 ( V_9 ) ;
F_8 ( L_1 , ( V_6 & 0xf0 ) >> 4 , ( V_6 & 0x0f ) ) ;
return 0 ;
}
static void F_9 ( struct V_4 * V_5 )
{
F_10 ( V_5 -> V_7 -> V_8 ) ;
F_11 ( V_5 -> V_7 -> V_8 ) ;
}
static T_3 F_12 ( struct V_4 * V_5 )
{
struct V_10 * V_11 =
& ( (struct V_12 * ) V_5 -> V_13 ) -> V_14 ;
return ( T_3 ) F_1 ( V_11 -> V_15 ) ;
}
static void F_13 ( struct V_4 * V_5 , T_3 V_15 )
{
struct V_10 * V_11 =
& ( (struct V_12 * ) V_5 -> V_13 ) -> V_16 ;
F_3 ( V_15 , V_11 -> V_15 ) ;
}
static int F_14 ( struct V_4 * V_5 )
{
struct V_10 * V_11 =
& ( (struct V_12 * ) V_5 -> V_13 ) -> V_14 ;
return ( F_1 ( V_11 -> V_17 ) == 0 ) ;
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_10 * V_11 =
& ( (struct V_12 * ) V_5 -> V_13 ) -> V_16 ;
return F_1 ( V_11 -> V_18 ) ;
}
static void F_16 ( struct V_4 * V_5 , T_4 V_19 )
{
struct V_12 * V_20 = V_5 -> V_13 ;
T_2 V_6 , V_21 = ( V_19 == V_22 ) ? V_20 -> V_23 : V_20 -> V_24 ;
V_6 = F_1 ( V_20 -> V_25 ) ;
V_6 |= V_21 ;
F_3 ( V_6 , V_20 -> V_25 ) ;
}
static void F_17 ( struct V_4 * V_5 , T_4 V_19 )
{
struct V_12 * V_20 = V_5 -> V_13 ;
T_2 V_21 = ( V_19 == V_22 ) ? V_20 -> V_23 : V_20 -> V_24 ;
if ( ! V_20 -> V_26 )
V_21 = F_1 ( V_20 -> V_27 ) & ~ V_21 ;
F_3 ( V_21 , V_20 -> V_27 ) ;
}
static void F_18 ( struct V_4 * V_5 , T_4 V_19 )
{
struct V_12 * V_20 = V_5 -> V_13 ;
T_2 V_21 = ( V_19 == V_22 ) ? V_20 -> V_23 : V_20 -> V_24 ;
F_3 ( V_21 , V_20 -> V_28 ) ;
F_1 ( V_20 -> V_28 ) ;
}
static int F_19 ( struct V_4 * V_5 , T_4 V_19 )
{
struct V_12 * V_20 = V_5 -> V_13 ;
T_2 V_21 = ( V_19 == V_22 ) ? V_20 -> V_23 : V_20 -> V_24 ;
T_2 V_29 = F_1 ( V_20 -> V_25 ) ;
T_2 V_30 = F_1 ( V_20 -> V_28 ) ;
return ( int ) ( V_29 & V_30 & V_21 ) ;
}
static void F_20 ( struct V_4 * V_5 )
{
int V_31 ;
struct V_12 * V_20 = V_5 -> V_13 ;
int V_32 ;
if ( V_20 -> V_26 )
V_32 = V_33 ;
else
V_32 = V_34 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
V_20 -> V_35 [ V_31 ] = F_1 ( V_31 * sizeof( T_2 ) ) ;
F_21 ( V_5 -> V_7 , L_2 , V_36 ,
V_31 , V_20 -> V_35 [ V_31 ] ) ;
}
}
static void F_22 ( struct V_4 * V_5 )
{
int V_31 ;
struct V_12 * V_20 = V_5 -> V_13 ;
int V_32 ;
if ( V_20 -> V_26 )
V_32 = V_33 ;
else
V_32 = V_34 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
F_3 ( V_20 -> V_35 [ V_31 ] , V_31 * sizeof( T_2 ) ) ;
F_21 ( V_5 -> V_7 , L_2 , V_36 ,
V_31 , V_20 -> V_35 [ V_31 ] ) ;
}
}
static int F_23 ( struct V_37 * V_38 )
{
struct V_39 * V_40 ;
int V_41 ;
struct V_4 * * V_42 , * V_5 , * V_43 ;
struct V_12 * V_13 , * V_44 ;
struct V_45 * V_46 = V_38 -> V_7 . V_47 ;
struct V_48 * V_49 ;
int V_31 ;
if ( ! V_46 || ! V_46 -> V_50 || ! V_46 -> V_49 ) {
F_24 ( L_3 , V_36 ) ;
return - V_51 ;
}
V_42 = F_25 ( ( V_46 -> V_50 + 1 ) * sizeof( * V_42 ) , V_52 ) ;
if ( ! V_42 )
return - V_53 ;
V_43 = V_5 = F_25 ( V_46 -> V_50 * sizeof( * V_5 ) , V_52 ) ;
if ( ! V_43 ) {
V_41 = - V_53 ;
goto V_54;
}
V_44 = V_13 = F_25 ( V_46 -> V_50 * sizeof( * V_13 ) , V_52 ) ;
if ( ! V_44 ) {
V_41 = - V_53 ;
goto V_55;
}
V_49 = V_46 -> V_49 ;
for ( V_31 = 0 ; V_31 < V_46 -> V_50 ; V_31 ++ , V_49 ++ , V_13 ++ ) {
V_13 -> V_16 . V_15 = F_26 ( V_49 -> V_56 ) ;
V_13 -> V_16 . V_18 = F_27 ( V_49 -> V_56 ) ;
V_13 -> V_14 . V_15 = F_26 ( V_49 -> V_57 ) ;
V_13 -> V_14 . V_17 = F_28 ( V_49 -> V_57 ) ;
V_13 -> V_23 = F_29 ( V_49 -> V_56 ) ;
V_13 -> V_24 = F_30 ( V_49 -> V_57 ) ;
if ( V_46 -> V_26 ) {
V_13 -> V_25 = F_31 ( V_49 -> V_58 ) ;
V_13 -> V_28 = F_32 ( V_49 -> V_58 ) ;
V_13 -> V_27 =
F_33 ( V_49 -> V_58 ) ;
} else {
V_13 -> V_25 = F_34 ( V_49 -> V_58 ) ;
V_13 -> V_28 = F_35 ( V_49 -> V_58 ) ;
V_13 -> V_27 = F_34 ( V_49 -> V_58 ) ;
}
V_13 -> V_26 = V_46 -> V_26 ;
V_5 -> V_13 = V_13 ;
V_5 -> V_59 = V_49 -> V_59 ;
V_5 -> V_60 = & V_61 ;
V_5 -> V_19 = F_36 ( V_38 , V_49 -> V_62 ) ;
if ( V_5 -> V_19 < 0 ) {
V_41 = V_5 -> V_19 ;
goto V_63;
}
V_42 [ V_31 ] = V_5 ++ ;
}
V_40 = F_37 ( V_38 , V_64 , 0 ) ;
if ( ! V_40 ) {
V_41 = - V_65 ;
goto V_63;
}
V_2 = F_38 ( V_40 -> V_66 , F_39 ( V_40 ) ) ;
if ( ! V_2 ) {
V_41 = - V_53 ;
goto V_63;
}
V_41 = F_40 ( & V_38 -> V_7 , V_42 ) ;
if ( V_41 )
goto V_67;
F_41 ( V_38 , V_42 ) ;
return 0 ;
V_67:
F_42 ( V_2 ) ;
V_63:
F_43 ( V_44 ) ;
V_55:
F_43 ( V_43 ) ;
V_54:
F_43 ( V_42 ) ;
return V_41 ;
}
static int F_44 ( struct V_37 * V_38 )
{
struct V_12 * V_44 ;
struct V_4 * * V_42 = F_45 ( V_38 ) ;
struct V_4 * V_43 = V_42 [ 0 ] ;
V_44 = V_43 -> V_13 ;
F_46 () ;
F_42 ( V_2 ) ;
F_43 ( V_44 ) ;
F_43 ( V_43 ) ;
F_43 ( V_42 ) ;
F_41 ( V_38 , NULL ) ;
return 0 ;
}
static int T_5 F_47 ( void )
{
return F_48 ( & V_68 ) ;
}
static void T_6 F_49 ( void )
{
F_50 ( & V_68 ) ;
}
