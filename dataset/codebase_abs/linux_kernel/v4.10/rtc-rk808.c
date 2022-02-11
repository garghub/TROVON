static T_1 F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 + 1900 ) - 2016 + ( V_2 -> V_4 + 1 > 11 ? 1 : 0 ) ;
}
static void F_2 ( struct V_1 * V_2 )
{
T_1 time = F_3 ( V_2 ) ;
F_4 ( time + F_1 ( V_2 ) * 86400 , V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_5 = F_1 ( V_2 ) ;
T_1 time = F_3 ( V_2 ) ;
F_4 ( time - V_5 * 86400 , V_2 ) ;
if ( F_1 ( V_2 ) < V_5 ) {
if ( V_2 -> V_4 + 1 == 11 )
V_2 -> V_6 ++ ;
else
F_4 ( time - ( V_5 - 1 ) * 86400 , V_2 ) ;
}
}
static int F_6 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_9 * V_9 = F_7 ( V_8 ) ;
struct V_10 * V_10 = V_9 -> V_10 ;
T_2 V_11 [ V_12 ] ;
int V_13 ;
V_13 = F_8 ( V_10 -> V_14 , V_15 ,
V_16 ,
V_16 ) ;
if ( V_13 ) {
F_9 ( V_8 , L_1 , V_13 ) ;
return V_13 ;
}
V_13 = F_8 ( V_10 -> V_14 , V_15 ,
V_16 ,
0 ) ;
if ( V_13 ) {
F_9 ( V_8 , L_1 , V_13 ) ;
return V_13 ;
}
V_13 = F_10 ( V_10 -> V_14 , V_17 ,
V_11 , V_12 ) ;
if ( V_13 ) {
F_9 ( V_8 , L_2 , V_13 ) ;
return V_13 ;
}
V_2 -> V_18 = F_11 ( V_11 [ 0 ] & V_19 ) ;
V_2 -> V_20 = F_11 ( V_11 [ 1 ] & V_21 ) ;
V_2 -> V_22 = F_11 ( V_11 [ 2 ] & V_23 ) ;
V_2 -> V_6 = F_11 ( V_11 [ 3 ] & V_24 ) ;
V_2 -> V_4 = ( F_11 ( V_11 [ 4 ] & V_25 ) ) - 1 ;
V_2 -> V_3 = ( F_11 ( V_11 [ 5 ] & V_26 ) ) + 100 ;
V_2 -> V_27 = F_11 ( V_11 [ 6 ] & V_28 ) ;
F_2 ( V_2 ) ;
F_12 ( V_8 , L_3 ,
1900 + V_2 -> V_3 , V_2 -> V_4 + 1 , V_2 -> V_6 ,
V_2 -> V_27 , V_2 -> V_22 , V_2 -> V_20 , V_2 -> V_18 ) ;
return V_13 ;
}
static int F_13 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_9 * V_9 = F_7 ( V_8 ) ;
struct V_10 * V_10 = V_9 -> V_10 ;
T_2 V_11 [ V_12 ] ;
int V_13 ;
F_12 ( V_8 , L_4 ,
1900 + V_2 -> V_3 , V_2 -> V_4 + 1 , V_2 -> V_6 ,
V_2 -> V_27 , V_2 -> V_22 , V_2 -> V_20 , V_2 -> V_18 ) ;
F_5 ( V_2 ) ;
V_11 [ 0 ] = F_14 ( V_2 -> V_18 ) ;
V_11 [ 1 ] = F_14 ( V_2 -> V_20 ) ;
V_11 [ 2 ] = F_14 ( V_2 -> V_22 ) ;
V_11 [ 3 ] = F_14 ( V_2 -> V_6 ) ;
V_11 [ 4 ] = F_14 ( V_2 -> V_4 + 1 ) ;
V_11 [ 5 ] = F_14 ( V_2 -> V_3 - 100 ) ;
V_11 [ 6 ] = F_14 ( V_2 -> V_27 ) ;
V_13 = F_8 ( V_10 -> V_14 , V_15 ,
V_29 ,
V_29 ) ;
if ( V_13 ) {
F_9 ( V_8 , L_5 , V_13 ) ;
return V_13 ;
}
V_13 = F_15 ( V_10 -> V_14 , V_17 ,
V_11 , V_12 ) ;
if ( V_13 ) {
F_9 ( V_8 , L_6 , V_13 ) ;
return V_13 ;
}
V_13 = F_8 ( V_10 -> V_14 , V_15 ,
V_29 , 0 ) ;
if ( V_13 ) {
F_9 ( V_8 , L_5 , V_13 ) ;
return V_13 ;
}
return 0 ;
}
static int F_16 ( struct V_7 * V_8 , struct V_30 * V_31 )
{
struct V_9 * V_9 = F_7 ( V_8 ) ;
struct V_10 * V_10 = V_9 -> V_10 ;
T_2 V_32 [ V_33 ] ;
T_3 V_34 ;
int V_13 ;
V_13 = F_10 ( V_10 -> V_14 , V_35 ,
V_32 , V_33 ) ;
V_31 -> time . V_18 = F_11 ( V_32 [ 0 ] & V_19 ) ;
V_31 -> time . V_20 = F_11 ( V_32 [ 1 ] & V_21 ) ;
V_31 -> time . V_22 = F_11 ( V_32 [ 2 ] & V_23 ) ;
V_31 -> time . V_6 = F_11 ( V_32 [ 3 ] & V_24 ) ;
V_31 -> time . V_4 = ( F_11 ( V_32 [ 4 ] & V_25 ) ) - 1 ;
V_31 -> time . V_3 = ( F_11 ( V_32 [ 5 ] & V_26 ) ) + 100 ;
F_2 ( & V_31 -> time ) ;
V_13 = F_17 ( V_10 -> V_14 , V_36 , & V_34 ) ;
if ( V_13 ) {
F_9 ( V_8 , L_7 , V_13 ) ;
return V_13 ;
}
F_12 ( V_8 , L_8 ,
1900 + V_31 -> time . V_3 , V_31 -> time . V_4 + 1 ,
V_31 -> time . V_6 , V_31 -> time . V_27 , V_31 -> time . V_22 ,
V_31 -> time . V_20 , V_31 -> time . V_18 ) ;
V_31 -> V_37 = ( V_34 & V_38 ) ? 1 : 0 ;
return 0 ;
}
static int F_18 ( struct V_9 * V_9 )
{
struct V_10 * V_10 = V_9 -> V_10 ;
int V_13 ;
V_13 = F_8 ( V_10 -> V_14 , V_36 ,
V_38 , 0 ) ;
return V_13 ;
}
static int F_19 ( struct V_9 * V_9 )
{
struct V_10 * V_10 = V_9 -> V_10 ;
int V_13 ;
V_13 = F_8 ( V_10 -> V_14 , V_36 ,
V_38 ,
V_38 ) ;
return V_13 ;
}
static int F_20 ( struct V_7 * V_8 , struct V_30 * V_31 )
{
struct V_9 * V_9 = F_7 ( V_8 ) ;
struct V_10 * V_10 = V_9 -> V_10 ;
T_2 V_32 [ V_33 ] ;
int V_13 ;
V_13 = F_18 ( V_9 ) ;
if ( V_13 ) {
F_9 ( V_8 , L_9 , V_13 ) ;
return V_13 ;
}
F_12 ( V_8 , L_10 ,
1900 + V_31 -> time . V_3 , V_31 -> time . V_4 + 1 ,
V_31 -> time . V_6 , V_31 -> time . V_27 , V_31 -> time . V_22 ,
V_31 -> time . V_20 , V_31 -> time . V_18 ) ;
F_5 ( & V_31 -> time ) ;
V_32 [ 0 ] = F_14 ( V_31 -> time . V_18 ) ;
V_32 [ 1 ] = F_14 ( V_31 -> time . V_20 ) ;
V_32 [ 2 ] = F_14 ( V_31 -> time . V_22 ) ;
V_32 [ 3 ] = F_14 ( V_31 -> time . V_6 ) ;
V_32 [ 4 ] = F_14 ( V_31 -> time . V_4 + 1 ) ;
V_32 [ 5 ] = F_14 ( V_31 -> time . V_3 - 100 ) ;
V_13 = F_15 ( V_10 -> V_14 , V_35 ,
V_32 , V_33 ) ;
if ( V_13 ) {
F_9 ( V_8 , L_11 , V_13 ) ;
return V_13 ;
}
if ( V_31 -> V_37 ) {
V_13 = F_19 ( V_9 ) ;
if ( V_13 ) {
F_9 ( V_8 , L_12 , V_13 ) ;
return V_13 ;
}
}
return 0 ;
}
static int F_21 ( struct V_7 * V_8 ,
unsigned int V_37 )
{
struct V_9 * V_9 = F_7 ( V_8 ) ;
if ( V_37 )
return F_19 ( V_9 ) ;
return F_18 ( V_9 ) ;
}
static T_4 F_22 ( int V_39 , void * V_40 )
{
struct V_9 * V_9 = V_40 ;
struct V_10 * V_10 = V_9 -> V_10 ;
struct V_41 * V_42 = V_10 -> V_43 ;
int V_13 ;
V_13 = F_23 ( V_10 -> V_14 , V_44 ,
V_45 ) ;
if ( V_13 ) {
F_9 ( & V_42 -> V_8 ,
L_13 , V_46 , V_13 ) ;
return V_13 ;
}
F_24 ( V_9 -> V_47 , 1 , V_48 | V_49 ) ;
F_12 ( & V_42 -> V_8 ,
L_14 , V_46 , V_39 ) ;
return V_50 ;
}
static int F_25 ( struct V_7 * V_8 )
{
struct V_51 * V_52 = F_26 ( V_8 ) ;
struct V_9 * V_9 = F_7 ( & V_52 -> V_8 ) ;
if ( F_27 ( V_8 ) )
F_28 ( V_9 -> V_39 ) ;
return 0 ;
}
static int F_29 ( struct V_7 * V_8 )
{
struct V_51 * V_52 = F_26 ( V_8 ) ;
struct V_9 * V_9 = F_7 ( & V_52 -> V_8 ) ;
if ( F_27 ( V_8 ) )
F_30 ( V_9 -> V_39 ) ;
return 0 ;
}
static int F_31 ( struct V_51 * V_52 )
{
struct V_10 * V_10 = F_7 ( V_52 -> V_8 . V_53 ) ;
struct V_9 * V_9 ;
struct V_1 V_2 ;
int V_13 ;
V_9 = F_32 ( & V_52 -> V_8 , sizeof( * V_9 ) , V_54 ) ;
if ( V_9 == NULL )
return - V_55 ;
F_33 ( V_52 , V_9 ) ;
V_9 -> V_10 = V_10 ;
V_13 = F_8 ( V_10 -> V_14 , V_15 ,
V_29 |
V_56 ,
V_56 ) ;
if ( V_13 ) {
F_9 ( & V_52 -> V_8 ,
L_5 , V_13 ) ;
return V_13 ;
}
V_13 = F_23 ( V_10 -> V_14 , V_44 ,
V_45 ) ;
if ( V_13 ) {
F_9 ( & V_52 -> V_8 ,
L_15 , V_13 ) ;
return V_13 ;
}
V_13 = F_6 ( & V_52 -> V_8 , & V_2 ) ;
if ( V_13 ) {
F_9 ( & V_52 -> V_8 , L_16 ) ;
return V_13 ;
}
V_13 = F_34 ( & V_2 ) ;
if ( V_13 )
F_35 ( & V_52 -> V_8 , L_17 ) ;
F_36 ( & V_52 -> V_8 , 1 ) ;
V_9 -> V_47 = F_37 ( & V_52 -> V_8 , L_18 ,
& V_57 , V_58 ) ;
if ( F_38 ( V_9 -> V_47 ) ) {
V_13 = F_39 ( V_9 -> V_47 ) ;
return V_13 ;
}
V_9 -> V_39 = F_40 ( V_52 , 0 ) ;
if ( V_9 -> V_39 < 0 ) {
if ( V_9 -> V_39 != - V_59 )
F_9 ( & V_52 -> V_8 , L_19 ,
V_9 -> V_39 ) ;
return V_9 -> V_39 ;
}
V_13 = F_41 ( & V_52 -> V_8 , V_9 -> V_39 , NULL ,
F_22 , 0 ,
L_20 , V_9 ) ;
if ( V_13 ) {
F_9 ( & V_52 -> V_8 , L_21 ,
V_9 -> V_39 , V_13 ) ;
}
return V_13 ;
}
