static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_4 [ 2 ] , V_5 [ 1 ] ;
int V_6 ;
V_4 [ 0 ] = V_2 -> V_7 | 0x01 ;
V_4 [ 1 ] = V_3 ;
V_6 = F_2 ( V_2 -> V_8 , V_4 , sizeof V_4 , V_5 , sizeof V_5 ) ;
return ( V_6 < 0 ) ? V_6 : V_5 [ 0 ] ;
}
static int F_3 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_9 )
{
T_1 V_4 [ 3 ] ;
V_4 [ 0 ] = V_2 -> V_7 ;
V_4 [ 1 ] = V_3 ;
V_4 [ 2 ] = V_9 ;
return F_2 ( V_2 -> V_8 , V_4 , sizeof V_4 , NULL , 0 ) ;
}
static int
F_4 ( struct V_1 * V_2 , unsigned V_3 , T_2 * V_10 , unsigned V_11 )
{
T_1 V_4 [ 2 ] , * V_12 ;
int V_6 ;
if ( ( V_11 + V_3 ) > sizeof V_2 -> V_13 )
return - V_14 ;
V_4 [ 0 ] = V_2 -> V_7 | 0x01 ;
V_4 [ 1 ] = V_3 ;
V_12 = ( T_1 * ) V_10 ;
V_6 = F_2 ( V_2 -> V_8 , V_4 , sizeof V_4 , V_12 , V_11 ) ;
if ( V_6 >= 0 ) {
while ( V_11 -- )
V_10 [ V_11 ] = V_12 [ V_11 ] ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_4 [ 2 ] , V_5 [ 2 ] ;
int V_6 ;
V_4 [ 0 ] = V_2 -> V_7 | 0x01 ;
V_4 [ 1 ] = V_3 << 1 ;
V_6 = F_2 ( V_2 -> V_8 , V_4 , sizeof V_4 , V_5 , sizeof V_5 ) ;
return ( V_6 < 0 ) ? V_6 : ( V_5 [ 0 ] | ( V_5 [ 1 ] << 8 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_9 )
{
T_1 V_4 [ 4 ] ;
V_4 [ 0 ] = V_2 -> V_7 ;
V_4 [ 1 ] = V_3 << 1 ;
V_4 [ 2 ] = V_9 ;
V_4 [ 3 ] = V_9 >> 8 ;
return F_2 ( V_2 -> V_8 , V_4 , sizeof V_4 , NULL , 0 ) ;
}
static int
F_7 ( struct V_1 * V_2 , unsigned V_3 , T_2 * V_10 , unsigned V_11 )
{
T_1 V_4 [ 2 ] ;
int V_6 ;
if ( ( V_11 + V_3 ) > sizeof V_2 -> V_13 )
return - V_14 ;
V_4 [ 0 ] = V_2 -> V_7 | 0x01 ;
V_4 [ 1 ] = V_3 << 1 ;
V_6 = F_2 ( V_2 -> V_8 , V_4 , sizeof V_4 ,
( T_1 * ) V_10 , V_11 * 2 ) ;
if ( V_6 >= 0 ) {
while ( V_11 -- )
V_10 [ V_11 ] = F_8 ( ( V_15 ) V_10 [ V_11 ] ) ;
}
return V_6 ;
}
static int F_9 ( struct V_16 * V_17 , unsigned V_18 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_17 ) ;
int V_6 ;
F_11 ( & V_2 -> V_19 ) ;
V_2 -> V_13 [ V_20 ] |= ( 1 << V_18 ) ;
V_6 = V_2 -> V_21 -> V_22 ( V_2 , V_20 , V_2 -> V_13 [ V_20 ] ) ;
F_12 ( & V_2 -> V_19 ) ;
return V_6 ;
}
static int F_13 ( struct V_16 * V_17 , unsigned V_18 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_17 ) ;
int V_6 ;
F_11 ( & V_2 -> V_19 ) ;
V_6 = V_2 -> V_21 -> V_23 ( V_2 , V_24 ) ;
if ( V_6 < 0 )
V_6 = 0 ;
else {
V_2 -> V_13 [ V_24 ] = V_6 ;
V_6 = ! ! ( V_6 & ( 1 << V_18 ) ) ;
}
F_12 ( & V_2 -> V_19 ) ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned V_25 , int V_26 )
{
unsigned V_27 = V_2 -> V_13 [ V_28 ] ;
if ( V_26 )
V_27 |= V_25 ;
else
V_27 &= ~ V_25 ;
V_2 -> V_13 [ V_28 ] = V_27 ;
return V_2 -> V_21 -> V_22 ( V_2 , V_28 , V_27 ) ;
}
static void F_15 ( struct V_16 * V_17 , unsigned V_18 , int V_26 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_17 ) ;
unsigned V_25 = 1 << V_18 ;
F_11 ( & V_2 -> V_19 ) ;
F_14 ( V_2 , V_25 , V_26 ) ;
F_12 ( & V_2 -> V_19 ) ;
}
static int
F_16 ( struct V_16 * V_17 , unsigned V_18 , int V_26 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_17 ) ;
unsigned V_25 = 1 << V_18 ;
int V_6 ;
F_11 ( & V_2 -> V_19 ) ;
V_6 = F_14 ( V_2 , V_25 , V_26 ) ;
if ( V_6 == 0 ) {
V_2 -> V_13 [ V_20 ] &= ~ V_25 ;
V_6 = V_2 -> V_21 -> V_22 ( V_2 , V_20 , V_2 -> V_13 [ V_20 ] ) ;
}
F_12 ( & V_2 -> V_19 ) ;
return V_6 ;
}
static void F_17 ( struct V_29 * V_30 , struct V_16 * V_17 )
{
struct V_1 * V_2 ;
char V_31 ;
int V_32 ;
unsigned V_25 ;
V_2 = F_10 ( V_17 , struct V_1 , V_17 ) ;
V_31 = '0' + ( ( V_2 -> V_7 >> 1 ) & 0x7 ) ;
F_11 ( & V_2 -> V_19 ) ;
V_32 = V_2 -> V_21 -> V_33 ( V_2 , 0 , V_2 -> V_13 , F_18 ( V_2 -> V_13 ) ) ;
if ( V_32 < 0 ) {
F_19 ( V_30 , L_1 , V_32 ) ;
goto V_34;
}
for ( V_32 = 0 , V_25 = 1 ; V_32 < V_17 -> V_35 ; V_32 ++ , V_25 <<= 1 ) {
const char * V_36 ;
V_36 = F_20 ( V_17 , V_32 ) ;
if ( ! V_36 )
continue;
F_19 ( V_30 , L_2 ,
V_17 -> V_37 + V_32 , V_31 , V_32 , V_36 ,
( V_2 -> V_13 [ V_20 ] & V_25 ) ? L_3 : L_4 ,
( V_2 -> V_13 [ V_24 ] & V_25 ) ? L_5 : L_6 ,
( V_2 -> V_13 [ V_38 ] & V_25 ) ? L_7 : L_8 ) ;
F_19 ( V_30 , L_9 ) ;
}
V_34:
F_12 ( & V_2 -> V_19 ) ;
}
static int F_21 ( struct V_39 * V_8 , unsigned V_7 ,
unsigned type , unsigned V_37 , unsigned V_40 )
{
struct V_41 * V_42 = F_22 ( V_8 ) ;
struct V_1 * V_2 = V_42 -> V_2 [ V_7 ] ;
int V_6 ;
F_23 ( & V_2 -> V_19 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_7 = 0x40 | ( V_7 << 1 ) ;
V_2 -> V_17 . V_43 = F_9 ;
V_2 -> V_17 . V_44 = F_13 ;
V_2 -> V_17 . V_45 = F_16 ;
V_2 -> V_17 . V_46 = F_15 ;
V_2 -> V_17 . V_47 = F_17 ;
if ( type == V_48 ) {
V_2 -> V_21 = & V_49 ;
V_2 -> V_17 . V_35 = 16 ;
V_2 -> V_17 . V_36 = L_10 ;
} else {
V_2 -> V_21 = & V_50 ;
V_2 -> V_17 . V_35 = 8 ;
V_2 -> V_17 . V_36 = L_11 ;
}
V_2 -> V_17 . V_37 = V_37 ;
V_2 -> V_17 . V_51 = 1 ;
V_2 -> V_17 . V_52 = & V_8 -> V_52 ;
V_2 -> V_17 . V_53 = V_54 ;
V_6 = V_2 -> V_21 -> V_23 ( V_2 , V_55 ) ;
if ( V_6 < 0 )
goto V_56;
if ( ( V_6 & V_57 ) || ! ( V_6 & V_58 ) ) {
V_6 &= ~ ( V_57 | ( V_57 << 8 ) ) ;
V_6 |= V_58 | ( V_58 << 8 ) ;
V_6 = V_2 -> V_21 -> V_22 ( V_2 , V_55 , V_6 ) ;
if ( V_6 < 0 )
goto V_56;
}
V_6 = V_2 -> V_21 -> V_22 ( V_2 , V_38 , V_40 ) ;
if ( V_6 < 0 )
goto V_56;
V_6 = V_2 -> V_21 -> V_33 ( V_2 , 0 , V_2 -> V_13 , F_18 ( V_2 -> V_13 ) ) ;
if ( V_6 < 0 )
goto V_56;
if ( V_2 -> V_13 [ V_59 ] != 0 ) {
V_2 -> V_13 [ V_59 ] = 0 ;
V_6 = V_2 -> V_21 -> V_22 ( V_2 , V_59 , 0 ) ;
if ( V_6 < 0 )
goto V_56;
}
if ( V_2 -> V_13 [ V_60 ] != 0 ) {
V_2 -> V_13 [ V_60 ] = 0 ;
V_6 = V_2 -> V_21 -> V_22 ( V_2 , V_60 , 0 ) ;
if ( V_6 < 0 )
goto V_56;
}
V_6 = F_24 ( & V_2 -> V_17 ) ;
V_56:
if ( V_6 < 0 )
F_25 ( & V_8 -> V_52 , L_12 ,
V_7 , V_6 ) ;
return V_6 ;
}
static int F_26 ( struct V_39 * V_8 )
{
struct V_61 * V_62 ;
unsigned V_7 ;
unsigned V_63 = 0 ;
struct V_41 * V_42 ;
int V_6 , type ;
unsigned V_37 ;
type = F_27 ( V_8 ) -> V_64 ;
V_62 = V_8 -> V_52 . V_65 ;
if ( ! V_62 || ! F_28 ( V_62 -> V_37 ) ) {
F_25 ( & V_8 -> V_52 , L_13 ) ;
return - V_14 ;
}
for ( V_7 = 0 ; V_7 < F_18 ( V_62 -> V_17 ) ; V_7 ++ ) {
if ( ! V_62 -> V_17 [ V_7 ] . V_66 )
continue;
V_63 ++ ;
if ( ( type == V_67 ) && ( V_7 > 3 ) ) {
F_29 ( & V_8 -> V_52 ,
L_14 ) ;
return - V_14 ;
}
}
if ( ! V_63 )
return - V_68 ;
V_42 = F_30 ( sizeof *V_42 + V_63 * sizeof( struct V_1 ) ,
V_69 ) ;
if ( ! V_42 )
return - V_70 ;
F_31 ( V_8 , V_42 ) ;
V_37 = V_62 -> V_37 ;
for ( V_7 = 0 ; V_7 < F_18 ( V_62 -> V_17 ) ; V_7 ++ ) {
if ( ! V_62 -> V_17 [ V_7 ] . V_66 )
continue;
V_63 -- ;
V_42 -> V_2 [ V_7 ] = & V_42 -> V_17 [ V_63 ] ;
V_6 = F_21 ( V_8 , V_7 , type , V_37 ,
V_62 -> V_17 [ V_7 ] . V_40 ) ;
if ( V_6 < 0 )
goto V_56;
V_37 += ( type == V_48 ) ? 16 : 8 ;
}
V_42 -> V_35 = V_37 - V_62 -> V_37 ;
if ( V_62 -> V_71 ) {
V_6 = V_62 -> V_71 ( V_8 ,
V_62 -> V_37 , V_42 -> V_35 ,
V_62 -> V_72 ) ;
if ( V_6 < 0 )
F_25 ( & V_8 -> V_52 , L_15 , V_6 ) ;
}
return 0 ;
V_56:
for ( V_7 = 0 ; V_7 < F_18 ( V_42 -> V_2 ) ; V_7 ++ ) {
int V_12 ;
if ( ! V_42 -> V_2 [ V_7 ] )
continue;
V_12 = F_32 ( & V_42 -> V_2 [ V_7 ] -> V_17 ) ;
if ( V_12 < 0 )
F_29 ( & V_8 -> V_52 , L_16 , L_17 , V_12 ) ;
}
F_33 ( V_42 ) ;
return V_6 ;
}
static int F_34 ( struct V_39 * V_8 )
{
struct V_41 * V_42 = F_22 ( V_8 ) ;
struct V_61 * V_62 = V_8 -> V_52 . V_65 ;
unsigned V_7 ;
int V_6 = 0 ;
if ( V_62 -> V_73 ) {
V_6 = V_62 -> V_73 ( V_8 ,
V_62 -> V_37 , V_42 -> V_35 ,
V_62 -> V_72 ) ;
if ( V_6 < 0 ) {
F_29 ( & V_8 -> V_52 , L_16 , L_18 , V_6 ) ;
return V_6 ;
}
}
for ( V_7 = 0 ; V_7 < F_18 ( V_42 -> V_2 ) ; V_7 ++ ) {
int V_12 ;
if ( ! V_42 -> V_2 [ V_7 ] )
continue;
V_12 = F_32 ( & V_42 -> V_2 [ V_7 ] -> V_17 ) ;
if ( V_12 < 0 ) {
F_29 ( & V_8 -> V_52 , L_16 , L_17 , V_12 ) ;
V_6 = V_12 ;
}
}
if ( V_6 == 0 )
F_33 ( V_42 ) ;
return V_6 ;
}
static int T_3 F_35 ( void )
{
return F_36 ( & V_74 ) ;
}
static void T_4 F_37 ( void )
{
F_38 ( & V_74 ) ;
}
