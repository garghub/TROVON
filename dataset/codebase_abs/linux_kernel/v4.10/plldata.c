static void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
V_4 -> V_8 = V_9 | V_10 ;
V_7 [ 2 ] . V_8 |= V_11 ;
V_7 [ 2 ] . div = 3 ;
V_7 [ 3 ] . V_8 |= V_11 ;
V_7 [ 3 ] . div = 6 ;
V_7 [ 4 ] . div = V_12 ;
V_7 [ 5 ] . div = V_13 ;
V_14 . V_15 = & V_7 [ 0 ] ;
V_16 . V_15 = & V_7 [ 3 ] ;
V_17 . V_15 = & V_7 [ 3 ] ;
V_18 . V_15 = & V_7 [ 3 ] ;
F_2 ( V_19 ) ;
}
static void T_1 F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
V_4 -> V_8 = V_10 | V_20 ;
V_7 [ 1 ] . V_8 |= V_11 ;
V_7 [ 1 ] . div = 1 ;
V_7 [ 2 ] . V_8 |= V_11 ;
V_7 [ 2 ] . div = 3 ;
V_7 [ 3 ] . V_8 |= V_11 ;
V_7 [ 3 ] . div = 6 ;
V_7 [ 4 ] . div = V_12 ;
V_7 [ 5 ] . div = V_13 ;
V_14 . V_15 = & V_7 [ 1 ] ;
V_16 . V_15 = & V_7 [ 3 ] ;
V_17 . V_15 = & V_7 [ 5 ] ;
V_18 . V_15 = & V_7 [ 5 ] ;
F_2 ( V_21 ) ;
}
static void T_1 F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_22 ;
V_4 -> V_8 = V_10 ;
for ( V_22 = 1 ; V_22 <= 6 ; V_22 ++ ) {
V_7 [ V_22 ] . V_8 |= V_11 ;
V_7 [ V_22 ] . div = 1 ;
}
V_7 [ 7 ] . V_8 |= V_11 ;
V_7 [ 7 ] . div = 3 ;
V_7 [ 8 ] . V_8 |= V_11 ;
V_7 [ 8 ] . div = 6 ;
V_7 [ 9 ] . V_8 |= V_11 ;
V_7 [ 9 ] . div = 2 ;
V_7 [ 10 ] . div = V_23 ;
V_14 . V_15 = & V_7 [ F_5 () + 1 ] ;
V_16 . V_15 = & V_7 [ 8 ] ;
V_17 . V_15 = & V_7 [ 8 ] ;
V_18 . V_15 = & V_7 [ 5 ] ;
F_2 ( V_24 ) ;
}
static void T_1 F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
V_4 -> V_8 = V_10 ;
V_7 [ 7 ] . V_8 |= V_11 ;
V_7 [ 7 ] . div = 1 ;
V_7 [ 9 ] . V_8 |= V_11 ;
V_7 [ 9 ] . div = 3 ;
V_7 [ 10 ] . V_8 |= V_11 ;
V_7 [ 10 ] . div = 6 ;
V_7 [ 11 ] . div = V_25 ;
V_7 [ 12 ] . V_8 |= V_11 ;
V_7 [ 12 ] . div = 2 ;
V_7 [ 13 ] . div = V_26 ;
V_14 . V_15 = & V_7 [ 7 ] ;
V_16 . V_15 = & V_7 [ 10 ] ;
V_17 . V_15 = & V_7 [ 10 ] ;
V_27 . V_15 = & V_7 [ 10 ] ;
V_28 . V_15 = & V_7 [ 10 ] ;
F_2 ( V_29 ) ;
}
static void T_1 F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
V_4 -> V_8 = V_10 ;
V_7 [ 1 ] . V_8 |= V_11 ;
V_7 [ 1 ] . div = 1 ;
V_7 [ 2 ] . div = V_30 ;
V_7 [ 3 ] . V_8 |= V_11 ;
V_7 [ 3 ] . div = 2 ;
V_7 [ 4 ] . V_8 |= V_11 ;
V_7 [ 4 ] . div = 3 ;
V_7 [ 5 ] . div = V_13 ;
V_7 [ 6 ] . V_8 |= V_11 ;
V_7 [ 6 ] . div = 64 ;
V_7 [ 7 ] . V_8 |= V_11 ;
V_7 [ 7 ] . div = 6 ;
V_7 [ 8 ] . div = V_31 ;
V_7 [ 9 ] . V_8 |= V_11 ;
V_7 [ 9 ] . div = 12 ;
V_7 [ 10 ] . V_8 |= V_11 ;
V_7 [ 10 ] . div = 3 ;
V_7 [ 11 ] . V_8 |= V_11 ;
V_7 [ 11 ] . div = 6 ;
V_14 . V_15 = & V_7 [ 0 ] ;
V_16 . V_15 = & V_7 [ 7 ] ;
F_2 ( V_32 ) ;
}
void T_1 F_8 ( void )
{
void (* F_9)( struct V_1 * V_33 );
struct V_3 * V_4 = & V_5 ;
struct V_1 * V_2 ;
const struct V_34 * V_35 ;
int V_36 ;
T_2 V_37 ;
V_2 = F_10 ( NULL , V_38 ) ;
if ( ! V_2 )
return;
V_4 -> V_39 = F_11 ( V_2 , 0 ) ;
if ( ! V_4 -> V_39 )
goto V_40;
V_36 = F_12 ( V_2 , L_1 , & V_37 ) ;
if ( V_36 || V_37 == 0 ) {
F_13 ( L_2 ,
V_2 -> V_41 , ( int ) V_37 / 1000000 ) ;
V_37 = 25000000 ;
}
V_42 . V_43 = V_37 ;
V_36 = F_12 ( V_2 , L_3 , & V_37 ) ;
if ( V_36 )
V_37 = 5000 ;
V_4 -> V_44 = V_37 ;
V_36 = F_12 ( V_2 , L_4 , & V_37 ) ;
if ( V_36 )
V_37 = 30000 ;
V_4 -> V_45 = V_37 ;
V_36 = F_12 ( V_2 , L_5 , & V_37 ) ;
if ( V_36 )
V_37 = 30000 ;
V_4 -> V_46 = V_37 ;
V_35 = F_14 ( V_38 , V_2 ) ;
if ( V_35 && V_35 -> V_47 ) {
F_9 = V_35 -> V_47 ;
F_9 ( V_2 ) ;
}
V_40:
F_15 ( V_2 ) ;
}
