static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char V_5 [ V_6 ] ;
struct V_7 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_9 ;
V_9 = F_3 ( V_7 , V_10 , V_11 ,
V_12 , V_12 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_1 , V_9 ) ;
return V_9 ;
}
V_9 = F_5 ( V_7 , V_10 , V_13 ,
V_5 , V_6 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_2 , V_9 ) ;
return V_9 ;
}
V_4 -> V_14 = F_6 ( V_5 [ 0 ] ) ;
V_4 -> V_15 = F_6 ( V_5 [ 1 ] ) ;
V_4 -> V_16 = F_6 ( V_5 [ 2 ] ) ;
V_4 -> V_17 = F_6 ( V_5 [ 3 ] ) ;
V_4 -> V_18 = F_6 ( V_5 [ 4 ] ) - 1 ;
V_4 -> V_19 = F_6 ( V_5 [ 5 ] ) + 100 ;
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char V_5 [ V_6 ] ;
struct V_7 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_9 ;
V_5 [ 0 ] = F_8 ( V_4 -> V_14 ) ;
V_5 [ 1 ] = F_8 ( V_4 -> V_15 ) ;
V_5 [ 2 ] = F_8 ( V_4 -> V_16 ) ;
V_5 [ 3 ] = F_8 ( V_4 -> V_17 ) ;
V_5 [ 4 ] = F_8 ( V_4 -> V_18 + 1 ) ;
V_5 [ 5 ] = F_8 ( V_4 -> V_19 - 100 ) ;
V_9 = F_3 ( V_7 , V_10 , V_11 ,
V_20 , 0 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_3 , V_9 ) ;
return V_9 ;
}
V_9 = F_9 ( V_7 , V_10 , V_13 ,
V_5 , V_6 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_4 , V_9 ) ;
return V_9 ;
}
V_9 = F_3 ( V_7 , V_10 , V_11 ,
V_20 , V_20 ) ;
if ( V_9 < 0 )
F_4 ( V_2 , L_5 , V_9 ) ;
return V_9 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_21 )
{
struct V_7 * V_7 = F_2 ( V_2 -> V_8 ) ;
T_1 V_22 ;
V_22 = V_21 ? V_23 : 0 ;
return F_11 ( V_7 , V_10 ,
V_24 , V_22 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
unsigned char V_27 [ V_6 ] ;
T_2 V_28 ;
struct V_7 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_9 ;
V_9 = F_5 ( V_7 , V_10 ,
V_29 ,
V_27 , V_6 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_6 , V_9 ) ;
return V_9 ;
}
V_26 -> time . V_14 = F_6 ( V_27 [ 0 ] ) ;
V_26 -> time . V_15 = F_6 ( V_27 [ 1 ] ) ;
V_26 -> time . V_16 = F_6 ( V_27 [ 2 ] ) ;
V_26 -> time . V_17 = F_6 ( V_27 [ 3 ] ) ;
V_26 -> time . V_18 = F_6 ( V_27 [ 4 ] ) - 1 ;
V_26 -> time . V_19 = F_6 ( V_27 [ 5 ] ) + 100 ;
V_9 = F_13 ( V_7 , V_10 , V_24 ,
& V_28 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_7 , V_9 ) ;
return V_9 ;
}
if ( V_28 & V_23 )
V_26 -> V_21 = 1 ;
return V_9 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
unsigned char V_27 [ V_6 ] ;
struct V_7 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_9 ;
V_9 = F_10 ( V_2 , 0 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_8 ) ;
return V_9 ;
}
V_27 [ 0 ] = F_8 ( V_26 -> time . V_14 ) ;
V_27 [ 1 ] = F_8 ( V_26 -> time . V_15 ) ;
V_27 [ 2 ] = F_8 ( V_26 -> time . V_16 ) ;
V_27 [ 3 ] = F_8 ( V_26 -> time . V_17 ) ;
V_27 [ 4 ] = F_8 ( V_26 -> time . V_18 + 1 ) ;
V_27 [ 5 ] = F_8 ( V_26 -> time . V_19 - 100 ) ;
V_9 = F_9 ( V_7 , V_10 ,
V_29 , V_27 , V_6 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_9 , V_9 ) ;
return V_9 ;
}
if ( V_26 -> V_21 )
V_9 = F_10 ( V_2 , 1 ) ;
return V_9 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = F_2 ( V_2 -> V_8 ) ;
unsigned int V_30 ;
int V_9 ;
V_9 = F_13 ( V_7 , V_10 , V_31 ,
& V_30 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_10 , V_9 ) ;
return V_9 ;
}
V_9 = F_11 ( V_7 , V_10 , V_31 ,
V_30 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_11 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static T_3 F_16 ( int V_32 , void * V_33 )
{
struct V_34 * V_34 = V_33 ;
struct V_1 * V_2 = V_34 -> V_2 ;
int V_9 ;
V_9 = F_15 ( V_2 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_12 , V_9 ) ;
return V_35 ;
}
F_17 ( V_34 -> V_36 , 1 , V_37 | V_38 ) ;
return V_39 ;
}
static int F_18 ( struct V_40 * V_41 )
{
struct V_7 * V_7 = F_2 ( V_41 -> V_2 . V_8 ) ;
struct V_34 * V_34 = NULL ;
int V_9 ;
bool V_42 = false ;
bool V_43 ;
if ( V_41 -> V_2 . V_44 ) {
V_42 = F_19 ( V_41 -> V_2 . V_44 ,
L_13 ) ;
V_43 = F_19 ( V_41 -> V_2 . V_44 ,
L_14 ) ;
}
V_34 = F_20 ( & V_41 -> V_2 , sizeof( struct V_34 ) ,
V_45 ) ;
if ( ! V_34 )
return - V_46 ;
V_9 = F_15 ( & V_41 -> V_2 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_41 -> V_2 , L_15 , V_9 ) ;
return V_9 ;
}
V_34 -> V_2 = & V_41 -> V_2 ;
F_21 ( V_41 , V_34 ) ;
if ( V_42 ) {
unsigned V_47 = V_48 ;
if ( V_43 )
V_47 = 0 ;
V_9 = F_3 ( V_7 , V_49 ,
V_50 ,
V_48 , V_47 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_41 -> V_2 ,
L_16 , V_9 ) ;
return V_9 ;
}
V_9 = F_3 ( V_7 , V_49 ,
V_50 ,
V_51 ,
V_51 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_41 -> V_2 ,
L_16 , V_9 ) ;
return V_9 ;
}
}
V_9 = F_3 ( V_7 , V_10 , V_11 ,
V_20 ,
V_20 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_41 -> V_2 , L_17 , V_9 ) ;
return V_9 ;
}
V_34 -> V_32 = F_22 ( V_41 , 0 ) ;
F_23 ( & V_41 -> V_2 , 1 ) ;
V_34 -> V_36 = F_24 ( & V_41 -> V_2 , V_41 -> V_52 ,
& V_53 , V_54 ) ;
if ( F_25 ( V_34 -> V_36 ) ) {
V_9 = F_26 ( V_34 -> V_36 ) ;
F_4 ( & V_41 -> V_2 , L_18 , V_9 ) ;
return V_9 ;
}
V_9 = F_27 ( & V_41 -> V_2 , V_34 -> V_32 , NULL ,
F_16 ,
V_55 | V_56 |
V_57 ,
F_28 ( & V_41 -> V_2 ) , V_34 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_41 -> V_2 , L_19 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static int F_29 ( struct V_40 * V_41 )
{
F_10 ( & V_41 -> V_2 , 0 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_34 * V_34 = F_2 ( V_2 ) ;
if ( F_31 ( V_2 ) )
F_32 ( V_34 -> V_32 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_34 * V_34 = F_2 ( V_2 ) ;
if ( F_31 ( V_2 ) )
F_34 ( V_34 -> V_32 ) ;
return 0 ;
}
