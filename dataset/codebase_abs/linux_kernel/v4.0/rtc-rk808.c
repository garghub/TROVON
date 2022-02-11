static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
T_1 V_7 [ V_8 ] ;
int V_9 ;
V_9 = F_3 ( V_6 -> V_10 , V_11 ,
V_12 ,
V_12 ) ;
if ( V_9 ) {
F_4 ( V_2 , L_1 , V_9 ) ;
return V_9 ;
}
V_9 = F_3 ( V_6 -> V_10 , V_11 ,
V_12 ,
0 ) ;
if ( V_9 ) {
F_4 ( V_2 , L_1 , V_9 ) ;
return V_9 ;
}
V_9 = F_5 ( V_6 -> V_10 , V_13 ,
V_7 , V_8 ) ;
if ( V_9 ) {
F_4 ( V_2 , L_2 , V_9 ) ;
return V_9 ;
}
V_4 -> V_14 = F_6 ( V_7 [ 0 ] & V_15 ) ;
V_4 -> V_16 = F_6 ( V_7 [ 1 ] & V_17 ) ;
V_4 -> V_18 = F_6 ( V_7 [ 2 ] & V_19 ) ;
V_4 -> V_20 = F_6 ( V_7 [ 3 ] & V_21 ) ;
V_4 -> V_22 = ( F_6 ( V_7 [ 4 ] & V_23 ) ) - 1 ;
V_4 -> V_24 = ( F_6 ( V_7 [ 5 ] & V_25 ) ) + 100 ;
V_4 -> V_26 = F_6 ( V_7 [ 6 ] & V_27 ) ;
F_7 ( V_2 , L_3 ,
1900 + V_4 -> V_24 , V_4 -> V_22 + 1 , V_4 -> V_20 ,
V_4 -> V_26 , V_4 -> V_18 , V_4 -> V_16 , V_4 -> V_14 ) ;
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
T_1 V_7 [ V_8 ] ;
int V_9 ;
V_7 [ 0 ] = F_9 ( V_4 -> V_14 ) ;
V_7 [ 1 ] = F_9 ( V_4 -> V_16 ) ;
V_7 [ 2 ] = F_9 ( V_4 -> V_18 ) ;
V_7 [ 3 ] = F_9 ( V_4 -> V_20 ) ;
V_7 [ 4 ] = F_9 ( V_4 -> V_22 + 1 ) ;
V_7 [ 5 ] = F_9 ( V_4 -> V_24 - 100 ) ;
V_7 [ 6 ] = F_9 ( V_4 -> V_26 ) ;
F_7 ( V_2 , L_4 ,
1900 + V_4 -> V_24 , V_4 -> V_22 + 1 , V_4 -> V_20 ,
V_4 -> V_26 , V_4 -> V_18 , V_4 -> V_16 , V_4 -> V_14 ) ;
V_9 = F_3 ( V_6 -> V_10 , V_11 ,
V_28 ,
V_28 ) ;
if ( V_9 ) {
F_4 ( V_2 , L_5 , V_9 ) ;
return V_9 ;
}
V_9 = F_10 ( V_6 -> V_10 , V_13 ,
V_7 , V_8 ) ;
if ( V_9 ) {
F_4 ( V_2 , L_6 , V_9 ) ;
return V_9 ;
}
V_9 = F_3 ( V_6 -> V_10 , V_11 ,
V_28 , 0 ) ;
if ( V_9 ) {
F_4 ( V_2 , L_5 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
T_1 V_31 [ V_32 ] ;
T_2 V_33 ;
int V_9 ;
V_9 = F_5 ( V_6 -> V_10 , V_34 ,
V_31 , V_32 ) ;
V_30 -> time . V_14 = F_6 ( V_31 [ 0 ] & V_15 ) ;
V_30 -> time . V_16 = F_6 ( V_31 [ 1 ] & V_17 ) ;
V_30 -> time . V_18 = F_6 ( V_31 [ 2 ] & V_19 ) ;
V_30 -> time . V_20 = F_6 ( V_31 [ 3 ] & V_21 ) ;
V_30 -> time . V_22 = ( F_6 ( V_31 [ 4 ] & V_23 ) ) - 1 ;
V_30 -> time . V_24 = ( F_6 ( V_31 [ 5 ] & V_25 ) ) + 100 ;
V_9 = F_12 ( V_6 -> V_10 , V_35 , & V_33 ) ;
if ( V_9 ) {
F_4 ( V_2 , L_7 , V_9 ) ;
return V_9 ;
}
F_7 ( V_2 , L_8 ,
1900 + V_30 -> time . V_24 , V_30 -> time . V_22 + 1 ,
V_30 -> time . V_20 , V_30 -> time . V_26 , V_30 -> time . V_18 ,
V_30 -> time . V_16 , V_30 -> time . V_14 ) ;
V_30 -> V_36 = ( V_33 & V_37 ) ? 1 : 0 ;
return 0 ;
}
static int F_13 ( struct V_5 * V_5 )
{
struct V_6 * V_6 = V_5 -> V_6 ;
int V_9 ;
V_9 = F_3 ( V_6 -> V_10 , V_35 ,
V_37 , 0 ) ;
return V_9 ;
}
static int F_14 ( struct V_5 * V_5 )
{
struct V_6 * V_6 = V_5 -> V_6 ;
int V_9 ;
V_9 = F_3 ( V_6 -> V_10 , V_35 ,
V_37 ,
V_37 ) ;
return V_9 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
T_1 V_31 [ V_32 ] ;
int V_9 ;
V_9 = F_13 ( V_5 ) ;
if ( V_9 ) {
F_4 ( V_2 , L_9 , V_9 ) ;
return V_9 ;
}
F_7 ( V_2 , L_10 ,
1900 + V_30 -> time . V_24 , V_30 -> time . V_22 + 1 ,
V_30 -> time . V_20 , V_30 -> time . V_26 , V_30 -> time . V_18 ,
V_30 -> time . V_16 , V_30 -> time . V_14 ) ;
V_31 [ 0 ] = F_9 ( V_30 -> time . V_14 ) ;
V_31 [ 1 ] = F_9 ( V_30 -> time . V_16 ) ;
V_31 [ 2 ] = F_9 ( V_30 -> time . V_18 ) ;
V_31 [ 3 ] = F_9 ( V_30 -> time . V_20 ) ;
V_31 [ 4 ] = F_9 ( V_30 -> time . V_22 + 1 ) ;
V_31 [ 5 ] = F_9 ( V_30 -> time . V_24 - 100 ) ;
V_9 = F_10 ( V_6 -> V_10 , V_34 ,
V_31 , V_32 ) ;
if ( V_9 ) {
F_4 ( V_2 , L_11 , V_9 ) ;
return V_9 ;
}
if ( V_30 -> V_36 ) {
V_9 = F_14 ( V_5 ) ;
if ( V_9 ) {
F_4 ( V_2 , L_12 , V_9 ) ;
return V_9 ;
}
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned int V_36 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
if ( V_36 )
return F_14 ( V_5 ) ;
return F_13 ( V_5 ) ;
}
static T_3 F_17 ( int V_38 , void * V_39 )
{
struct V_5 * V_5 = V_39 ;
struct V_6 * V_6 = V_5 -> V_6 ;
struct V_40 * V_41 = V_6 -> V_42 ;
int V_9 ;
V_9 = F_18 ( V_6 -> V_10 , V_43 ,
V_44 ) ;
if ( V_9 ) {
F_4 ( & V_41 -> V_2 ,
L_13 , V_45 , V_9 ) ;
return V_9 ;
}
F_19 ( V_5 -> V_46 , 1 , V_47 | V_48 ) ;
F_7 ( & V_41 -> V_2 ,
L_14 , V_45 , V_38 ) ;
return V_49 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_21 ( V_2 ) ;
struct V_5 * V_5 = F_2 ( & V_51 -> V_2 ) ;
if ( F_22 ( V_2 ) )
F_23 ( V_5 -> V_38 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_21 ( V_2 ) ;
struct V_5 * V_5 = F_2 ( & V_51 -> V_2 ) ;
if ( F_22 ( V_2 ) )
F_25 ( V_5 -> V_38 ) ;
return 0 ;
}
static int F_26 ( struct V_50 * V_51 )
{
struct V_6 * V_6 = F_2 ( V_51 -> V_2 . V_52 ) ;
struct V_5 * V_5 ;
struct V_3 V_4 ;
int V_9 ;
V_5 = F_27 ( & V_51 -> V_2 , sizeof( * V_5 ) , V_53 ) ;
if ( V_5 == NULL )
return - V_54 ;
F_28 ( V_51 , V_5 ) ;
V_5 -> V_6 = V_6 ;
V_9 = F_3 ( V_6 -> V_10 , V_11 ,
V_28 |
V_55 ,
V_55 ) ;
if ( V_9 ) {
F_4 ( & V_51 -> V_2 ,
L_5 , V_9 ) ;
return V_9 ;
}
V_9 = F_18 ( V_6 -> V_10 , V_43 ,
V_44 ) ;
if ( V_9 ) {
F_4 ( & V_51 -> V_2 ,
L_15 , V_9 ) ;
return V_9 ;
}
V_9 = F_1 ( & V_51 -> V_2 , & V_4 ) ;
if ( V_9 ) {
F_4 ( & V_51 -> V_2 , L_16 ) ;
return V_9 ;
}
V_9 = F_29 ( & V_4 ) ;
if ( V_9 )
F_30 ( & V_51 -> V_2 , L_17 ) ;
F_31 ( & V_51 -> V_2 , 1 ) ;
V_5 -> V_46 = F_32 ( & V_51 -> V_2 , L_18 ,
& V_56 , V_57 ) ;
if ( F_33 ( V_5 -> V_46 ) ) {
V_9 = F_34 ( V_5 -> V_46 ) ;
return V_9 ;
}
V_5 -> V_38 = F_35 ( V_51 , 0 ) ;
if ( V_5 -> V_38 < 0 ) {
if ( V_5 -> V_38 != - V_58 )
F_4 ( & V_51 -> V_2 , L_19 ,
V_5 -> V_38 ) ;
return V_5 -> V_38 ;
}
V_9 = F_36 ( & V_51 -> V_2 , V_5 -> V_38 , NULL ,
F_17 , 0 ,
L_20 , V_5 ) ;
if ( V_9 ) {
F_4 ( & V_51 -> V_2 , L_21 ,
V_5 -> V_38 , V_9 ) ;
}
return V_9 ;
}
