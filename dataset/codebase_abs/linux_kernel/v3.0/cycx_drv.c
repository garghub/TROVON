static int T_1 F_1 ( void )
{
F_2 ( V_1 L_1 , V_2 , V_3 , V_4 ,
V_5 ) ;
return 0 ;
}
static void F_3 ( void )
{
}
int F_4 ( struct V_6 * V_7 , void * V_8 , T_2 V_9 , unsigned long V_10 )
{
int V_11 ;
if ( ! F_5 ( V_12 , V_7 -> V_13 ) ) {
F_2 ( V_14 L_2 , V_15 , V_7 -> V_13 ) ;
return - V_16 ;
}
if ( ! V_10 ) {
F_2 ( V_14 L_3 ,
V_15 ) ;
return - V_16 ;
} else if ( ! F_5 ( V_17 , V_10 ) ) {
F_2 ( V_14 L_4 ,
V_15 , V_10 ) ;
return - V_16 ;
}
V_7 -> V_10 = F_6 ( V_10 , V_18 ) ;
V_7 -> V_19 = V_18 ;
if ( ! F_7 ( V_7 -> V_10 ) ) {
F_2 ( V_14 L_5
L_6 , V_15 , V_10 ) ;
return - V_16 ;
}
F_2 ( V_1 L_7 ,
V_15 , V_10 ) ;
V_11 = F_8 ( V_7 , V_8 , V_9 ) ;
if ( V_11 )
F_9 ( V_7 ) ;
return V_11 ;
}
int F_9 ( struct V_6 * V_7 )
{
F_10 ( V_7 -> V_10 ) ;
return 0 ;
}
static void F_11 ( struct V_6 * V_7 )
{
F_12 ( 0 , V_7 -> V_10 ) ;
}
void F_13 ( struct V_6 * V_7 )
{
F_14 ( 0 , V_7 -> V_10 + V_20 ) ;
}
int F_15 ( void T_3 * V_21 )
{
T_4 V_22 = 0 ;
while ( F_16 ( V_21 ) ) {
F_17 ( 1000 ) ;
if ( ++ V_22 > 50 )
return - 1 ;
}
return 0 ;
}
int F_18 ( struct V_6 * V_7 , T_2 V_21 , void * V_23 , T_2 V_9 )
{
if ( V_9 == 1 )
* ( V_24 * ) V_23 = F_19 ( V_7 -> V_10 + V_21 ) ;
else
F_20 ( V_23 , V_7 -> V_10 + V_21 , V_9 ) ;
return 0 ;
}
int F_21 ( struct V_6 * V_7 , T_2 V_21 , void * V_23 , T_2 V_9 )
{
if ( V_9 == 1 )
F_12 ( * ( V_24 * ) V_23 , V_7 -> V_10 + V_21 ) ;
else
F_22 ( V_7 -> V_10 + V_21 , V_23 , V_9 ) ;
return 0 ;
}
static int F_23 ( void T_3 * V_21 )
{
int V_25 = 0 ;
for (; V_25 < 3 ; V_25 ++ ) {
F_14 ( V_26 , V_21 + 0x10 ) ;
if ( F_16 ( V_21 + 0x10 ) == V_26 )
if ( F_16 ( V_21 + 0x10 ) == V_26 )
return 1 ;
F_24 ( 1 * 1000 ) ;
}
return 0 ;
}
static void F_25 ( void T_3 * V_21 , V_24 * V_27 , T_2 V_28 )
{
void T_3 * V_29 = V_21 + V_30 ;
T_4 V_22 ;
for ( V_22 = 0 ; V_22 < V_28 ; V_22 ++ ) {
F_12 ( * V_27 ++ , V_29 ++ ) ;
}
}
static int F_26 ( void T_3 * V_21 , V_24 * V_27 , T_2 V_28 )
{
F_22 ( V_21 + V_31 , V_27 , V_28 ) ;
F_14 ( V_32 , V_21 + V_33 ) ;
return F_27 ( V_21 ) ;
}
static void F_28 ( void T_3 * V_21 )
{
F_12 ( 0xea , V_21 + 0x30 ) ;
F_12 ( 0x00 , V_21 + 0x31 ) ;
F_12 ( 0xc4 , V_21 + 0x32 ) ;
F_12 ( 0x00 , V_21 + 0x33 ) ;
F_12 ( 0x00 , V_21 + 0x34 ) ;
F_14 ( V_34 , V_21 + V_33 ) ;
}
static void F_29 ( void T_3 * V_21 , V_24 * V_35 , T_2 V_9 )
{
void T_3 * V_36 = V_21 + V_37 ;
F_12 ( 0xea , V_36 ++ ) ;
F_12 ( 0x00 , V_36 ++ ) ;
F_12 ( 0xfc , V_36 ++ ) ;
F_12 ( 0x00 , V_36 ++ ) ;
F_12 ( 0xf0 , V_36 ) ;
F_25 ( V_21 , V_35 , V_9 ) ;
F_12 ( 0 , V_21 + V_38 ) ;
F_24 ( 1 * 1000 ) ;
}
static int F_30 ( void T_3 * V_21 , V_24 * V_35 , T_2 V_9 )
{
void T_3 * V_39 = V_21 + V_33 ;
T_2 V_22 ;
F_14 ( V_40 , V_39 + sizeof( T_4 ) ) ;
F_14 ( V_41 , V_39 ) ;
if ( F_27 ( V_21 ) < 0 )
return - 1 ;
F_14 ( 0 , V_39 + sizeof( T_4 ) ) ;
F_14 ( 0x4000 , V_39 + 2 * sizeof( T_4 ) ) ;
F_14 ( V_42 , V_39 ) ;
if ( F_27 ( V_21 ) < 0 )
return - 1 ;
for ( V_22 = 0 ; V_22 < V_9 ; V_22 += V_40 )
if ( F_26 ( V_21 , V_35 + V_22 ,
F_31 ( T_2 , V_40 , ( V_9 - V_22 ) ) ) < 0 ) {
F_2 ( V_14 L_8 , V_15 ) ;
return - 1 ;
}
return 0 ;
}
static int F_32 ( void T_3 * V_21 , V_24 * V_35 , T_2 V_9 )
{
void T_3 * V_39 = V_21 + V_33 ;
T_2 V_22 ;
F_14 ( V_40 , V_39 + sizeof( T_4 ) ) ;
F_14 ( V_41 , V_39 ) ;
if ( F_27 ( V_21 ) < 0 )
return - 1 ;
F_14 ( 0x0000 , V_39 + sizeof( T_4 ) ) ;
F_14 ( 0xc400 , V_39 + 2 * sizeof( T_4 ) ) ;
F_14 ( V_42 , V_39 ) ;
if ( F_27 ( V_21 ) < 0 )
return - 1 ;
for ( V_22 = 0 ; V_22 < V_9 ; V_22 += V_40 )
if ( F_26 ( V_21 , V_35 + V_22 ,
F_31 ( T_2 , V_40 , ( V_9 - V_22 ) ) ) ) {
F_2 ( V_14 L_8 , V_15 ) ;
return - 1 ;
}
return 0 ;
}
static int F_8 ( struct V_6 * V_7 , struct V_43 * V_8 , T_2 V_9 )
{
int V_22 , V_44 ;
struct V_45 * V_46 ;
V_24 * V_47 ,
* V_48 ,
* V_49 ;
void T_3 * V_50 = V_7 -> V_10 + 0x400 ;
T_4 V_51 ;
F_2 ( V_1 L_9 , V_15 ,
V_8 -> V_52 ) ;
if ( strcmp ( V_8 -> V_52 , V_53 ) ) {
F_2 ( V_14 L_10 ,
V_15 ) ;
return - V_16 ;
}
F_2 ( V_1 L_11 , V_15 , V_8 -> V_54 ) ;
if ( V_8 -> V_54 != V_55 ) {
F_2 ( V_14 L_12
L_13 ,
V_15 , V_56 , V_8 -> V_54 , V_55 ) ;
return - V_16 ;
}
V_51 = F_33 ( ( V_24 * ) & V_8 -> V_57 , sizeof( struct V_58 ) +
V_8 -> V_57 . V_59 ) ;
if ( V_51 != V_8 -> F_33 ) {
F_2 ( V_14 L_14 ,
V_15 , V_56 ) ;
F_2 ( V_14 L_15 ,
V_9 - ( int ) sizeof( struct V_43 ) - 1 ,
V_8 -> V_57 . V_59 ) ;
F_2 ( V_14 L_16 ,
V_51 , V_8 -> F_33 ) ;
return - V_16 ;
}
V_46 = (struct V_45 * ) & V_8 -> V_60 ;
#ifdef F_34
F_2 ( V_1 L_17 , V_56 , V_15 ) ;
F_2 ( V_1 L_18 , V_46 -> V_61 ) ;
F_2 ( V_1 L_19 , V_46 -> V_62 ) ;
F_2 ( V_1 L_20 , V_46 -> V_63 ) ;
#endif
V_47 = ( ( V_24 * ) V_46 ) + sizeof( struct V_45 ) ;
V_48 = V_47 + V_46 -> V_61 ;
V_49 = V_48 + V_46 -> V_62 ;
F_2 ( V_1 L_21 , V_15 ,
V_8 -> V_64 [ 0 ] ? V_8 -> V_64 : L_22 ,
V_8 -> V_57 . V_65 ) ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ ) {
if ( ! F_35 ( V_7 -> V_10 ) ) {
F_2 ( V_14 L_23 ,
V_15 ) ;
return - V_16 ;
}
F_29 ( V_7 -> V_10 , V_47 , V_46 -> V_61 ) ;
F_14 ( V_66 , V_50 ) ;
F_24 ( 1 * 1000 ) ;
for ( V_44 = 0 ; V_44 < 3 ; V_44 ++ )
if ( ! F_16 ( V_50 ) )
goto V_67;
else
F_24 ( 1 * 1000 ) ;
}
F_2 ( V_14 L_24 , V_15 ) ;
return - V_16 ;
V_67:
if ( F_30 ( V_7 -> V_10 , V_48 , V_46 -> V_62 ) ) {
F_2 ( V_14 L_25 , V_15 ) ;
return - V_16 ;
}
if ( F_32 ( V_7 -> V_10 , V_49 , V_46 -> V_63 ) ) {
F_2 ( V_14 L_26 , V_15 ) ;
return - V_16 ;
}
F_36 ( V_7 ) ;
F_28 ( V_7 -> V_10 ) ;
F_24 ( 7 * 1000 ) ;
F_2 ( V_1 L_27 , V_15 ) ;
F_11 ( V_7 ) ;
return 0 ;
}
static void F_36 ( struct V_6 * V_7 )
{
F_12 ( V_68 , V_7 -> V_10 + V_69 ) ;
}
static int F_7 ( void T_3 * V_21 )
{
F_35 ( V_21 ) ;
return F_23 ( V_21 ) ;
}
static int F_5 ( const long * V_70 , long V_71 )
{
int V_22 = 1 ;
for (; V_22 <= V_70 [ 0 ] ; ++ V_22 )
if ( V_70 [ V_22 ] == V_71 )
return V_22 ;
return 0 ;
}
static int F_35 ( void T_3 * V_21 )
{
F_12 ( 0 , V_21 + V_72 ) ;
F_24 ( 2 * 1000 ) ;
F_12 ( 0 , V_21 + V_73 ) ;
F_24 ( 2 * 1000 ) ;
return F_23 ( V_21 ) ;
}
static T_4 F_33 ( V_24 * V_23 , T_2 V_9 )
{
T_4 V_74 = 0 ;
T_4 V_75 , V_76 ;
for (; V_9 ; -- V_9 , ++ V_23 )
for ( V_75 = 0x80 ; V_75 ; V_75 >>= 1 ) {
V_76 = ( V_74 & 0x8000 ) ;
V_74 <<= 1 ;
V_74 |= ( ( * V_23 & V_75 ) ? 1 : 0 ) ;
if ( V_76 )
V_74 ^= 0x1021 ;
}
return V_74 ;
}
