static bool F_1 ( struct V_1 * V_2 ,
int V_3 , int * V_4 )
{
int V_5 ;
bool V_6 = false ;
int V_7 = V_2 -> V_8 [ 3 ] ;
int V_9 = 3 ;
for ( V_5 = 0 ; V_5 < 4 ; ++ V_5 ) {
if ( V_2 -> V_10 [ V_2 -> V_8 [ V_5 ] ] == V_3 ) {
V_7 = V_2 -> V_8 [ V_5 ] ;
V_9 = V_5 ;
V_6 = true ;
goto V_11;
}
}
V_11:
for ( V_5 = V_9 ; V_5 > 0 ; V_5 -- )
V_2 -> V_8 [ V_5 ] = V_2 -> V_8 [ V_5 - 1 ] ;
V_2 -> V_8 [ 0 ] = V_7 ;
* V_4 = V_7 ;
return V_6 ;
}
static int F_2 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_3 ( V_13 ) ;
int V_14 ;
unsigned int V_15 ;
int V_16 ;
V_16 = F_4 ( V_2 -> V_17 , V_18 + V_2 -> V_19 , & V_15 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 , L_1 ,
V_20 , V_18 + V_2 -> V_19 ) ;
return V_16 ;
}
V_14 = ( int ) V_15 & V_2 -> V_21 ;
return ( V_2 -> V_22 + V_14 * 10 ) * 1000 ;
}
static int F_6 ( struct V_12 * V_13 ,
int V_23 , int V_24 , unsigned * V_25 )
{
struct V_1 * V_2 = F_3 ( V_13 ) ;
int V_14 ;
int V_16 ;
bool V_6 = false ;
int V_26 = V_2 -> V_19 ;
if ( V_24 < V_23 )
return - V_27 ;
if ( V_23 >
( ( V_2 -> V_22 + ( V_2 -> V_28 . V_29 - 1 ) * 10 ) * 1000 ) )
return - V_27 ;
if ( V_24 < V_2 -> V_22 * 1000 )
return - V_27 ;
V_14 = F_7 ( V_23 - ( V_2 -> V_22 * 1000 ) , 10000 ) ;
if ( V_25 )
* V_25 = ( V_14 & V_2 -> V_21 ) ;
if ( V_2 -> V_30 )
V_6 = F_1 ( V_2 , V_14 , & V_26 ) ;
if ( ! V_6 ) {
V_16 = F_8 ( V_2 -> V_17 , V_18 + V_26 ,
V_2 -> V_21 , V_14 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 , L_2 ,
V_20 , V_18 + V_26 ) ;
return V_16 ;
}
V_2 -> V_19 = V_26 ;
V_2 -> V_10 [ V_26 ] = V_14 ;
}
if ( V_2 -> V_30 ) {
F_9 ( V_2 -> V_31 ,
V_26 & 0x1 ) ;
F_9 ( V_2 -> V_32 ,
( V_26 >> 1 ) & 0x1 ) ;
}
return 0 ;
}
static int F_10 ( struct V_12 * V_13 ,
unsigned V_25 )
{
struct V_1 * V_2 = F_3 ( V_13 ) ;
if ( V_25 >= V_2 -> V_28 . V_29 )
return - V_27 ;
return ( V_2 -> V_22 + V_25 * 10 ) * 1000 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
int V_35 )
{
unsigned int V_15 ;
int V_16 ;
V_16 = F_4 ( V_2 -> V_17 , V_18 + V_35 , & V_15 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 , L_3 ,
V_20 , V_18 + V_35 ) ;
return V_16 ;
}
V_2 -> V_10 [ V_35 ] = V_15 & V_2 -> V_21 ;
if ( V_34 -> V_36 )
V_15 |= F_12 ( 7 ) ;
else
V_15 &= ~ F_12 ( 7 ) ;
V_16 = F_13 ( V_2 -> V_17 , V_18 + V_35 , V_15 ) ;
if ( V_16 < 0 )
F_5 ( V_2 -> V_13 , L_3 ,
V_20 , V_18 + V_35 ) ;
return V_16 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_16 ;
int V_5 ;
if ( V_2 -> V_37 )
V_16 = F_13 ( V_2 -> V_17 , V_38 , 0xE0 ) ;
else
V_16 = F_13 ( V_2 -> V_17 , V_38 , 0x0 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 , L_3 ,
V_20 , V_38 ) ;
return V_16 ;
}
if ( V_2 -> V_30 ) {
for ( V_5 = 0 ; V_5 < 4 ; ++ V_5 ) {
V_16 = F_11 ( V_2 , V_34 , V_5 ) ;
if ( V_16 < 0 )
return V_16 ;
}
} else {
V_16 = F_11 ( V_2 , V_34 , V_2 -> V_19 ) ;
if ( V_16 < 0 )
return V_16 ;
}
V_16 = F_8 ( V_2 -> V_17 , V_39 , F_12 ( 2 ) , 0 ) ;
if ( V_16 < 0 )
F_5 ( V_2 -> V_13 , L_4 ,
V_20 , V_39 ) ;
return V_16 ;
}
static int T_1 F_15 ( struct V_40 * V_41 ,
const struct V_42 * V_43 )
{
struct V_33 * V_34 ;
struct V_12 * V_44 ;
struct V_1 * V_2 ;
int V_16 ;
int V_5 ;
V_34 = V_41 -> V_13 . V_45 ;
if ( ! V_34 ) {
F_5 ( & V_41 -> V_13 , L_5 ,
V_20 ) ;
return - V_46 ;
}
V_2 = F_16 ( & V_41 -> V_13 , sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 ) {
F_5 ( & V_41 -> V_13 , L_6 ,
V_20 ) ;
return - V_48 ;
}
V_2 -> V_36 = V_34 -> V_36 ;
V_2 -> V_49 = V_34 -> V_49 ;
V_2 -> V_37 = V_34 -> V_37 ;
V_2 -> V_31 = V_34 -> V_31 ;
V_2 -> V_32 = V_34 -> V_32 ;
V_2 -> V_41 = V_41 ;
V_2 -> V_13 = & V_41 -> V_13 ;
V_2 -> V_50 = V_43 -> V_50 ;
V_2 -> V_22 = ( V_43 -> V_51 == V_52 ) ?
V_53 : V_54 ;
V_2 -> V_21 = ( V_43 -> V_51 == V_52 ) ? 0x3F : 0x7F ;
V_2 -> V_28 . V_50 = V_43 -> V_50 ;
V_2 -> V_28 . V_43 = 0 ;
V_2 -> V_28 . V_29 = ( V_43 -> V_51 == V_52 ) ?
V_55 : V_56 ;
V_2 -> V_28 . V_57 = & V_58 ;
V_2 -> V_28 . type = V_59 ;
V_2 -> V_28 . V_60 = V_61 ;
V_2 -> V_17 = F_17 ( V_41 , & V_62 ) ;
if ( F_18 ( V_2 -> V_17 ) ) {
V_16 = F_19 ( V_2 -> V_17 ) ;
F_5 ( & V_41 -> V_13 , L_7
L_8 , V_20 , V_16 ) ;
return V_16 ;
}
F_20 ( V_41 , V_2 ) ;
V_2 -> V_19 = ( V_34 -> V_63 & 1 ) * 2 +
( V_34 -> V_64 & 1 ) ;
V_2 -> V_8 [ 0 ] = V_2 -> V_19 ;
V_2 -> V_30 = false ;
if ( F_21 ( V_2 -> V_31 ) && F_21 ( V_2 -> V_32 ) ) {
V_16 = F_22 ( V_2 -> V_31 , L_9 ) ;
if ( V_16 ) {
F_5 ( & V_41 -> V_13 ,
L_10 ,
V_2 -> V_31 , V_16 ) ;
goto V_65;
}
V_16 = F_23 ( V_2 -> V_31 ,
V_34 -> V_64 ) ;
if ( V_16 ) {
F_5 ( & V_41 -> V_13 , L_11
L_12 , V_2 -> V_31 , V_16 ) ;
F_24 ( V_2 -> V_31 ) ;
goto V_65;
}
V_16 = F_22 ( V_2 -> V_32 , L_13 ) ;
if ( V_16 ) {
F_5 ( & V_41 -> V_13 ,
L_14 ,
V_2 -> V_32 , V_16 ) ;
goto V_66;
}
V_16 = F_23 ( V_2 -> V_32 ,
V_34 -> V_63 ) ;
if ( V_16 ) {
F_5 ( & V_41 -> V_13 , L_11
L_15 , V_2 -> V_32 , V_16 ) ;
F_24 ( V_2 -> V_32 ) ;
goto V_66;
}
V_2 -> V_30 = true ;
for ( V_5 = 0 ; V_5 < 4 ; ++ V_5 )
V_2 -> V_8 [ V_5 ] = V_5 ;
V_2 -> V_8 [ 0 ] = V_2 -> V_19 ;
V_2 -> V_8 [ V_2 -> V_19 ] = 0 ;
}
V_16 = F_14 ( V_2 , V_34 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 , L_16 ,
V_20 , V_16 ) ;
goto V_67;
}
V_44 = F_25 ( & V_2 -> V_28 , & V_41 -> V_13 ,
& V_34 -> V_68 , V_2 , NULL ) ;
if ( F_18 ( V_44 ) ) {
F_5 ( V_2 -> V_13 , L_17 ,
V_20 , V_43 -> V_50 ) ;
V_16 = F_19 ( V_44 ) ;
goto V_67;
}
V_2 -> V_44 = V_44 ;
return 0 ;
V_67:
if ( F_21 ( V_2 -> V_32 ) )
F_24 ( V_2 -> V_32 ) ;
V_66:
if ( F_21 ( V_2 -> V_31 ) )
F_24 ( V_2 -> V_31 ) ;
V_65:
F_26 ( V_2 -> V_17 ) ;
return V_16 ;
}
static int T_2 F_27 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_28 ( V_41 ) ;
if ( F_21 ( V_2 -> V_32 ) )
F_24 ( V_2 -> V_32 ) ;
if ( F_21 ( V_2 -> V_31 ) )
F_24 ( V_2 -> V_31 ) ;
F_29 ( V_2 -> V_44 ) ;
F_26 ( V_2 -> V_17 ) ;
return 0 ;
}
static void F_30 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_28 ( V_41 ) ;
int V_69 ;
if ( ! V_2 -> V_49 )
return;
V_69 = F_8 ( V_2 -> V_17 , V_39 , F_12 ( 2 ) , F_12 ( 2 ) ) ;
if ( V_69 < 0 )
F_5 ( V_2 -> V_13 , L_4 ,
V_20 , V_39 ) ;
}
static int T_3 F_31 ( void )
{
return F_32 ( & V_70 ) ;
}
static void T_4 F_33 ( void )
{
F_34 ( & V_70 ) ;
}
