static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 [ V_6 ] ;
int V_7 ;
V_7 = F_2 ( V_2 -> V_8 , V_9 ,
V_10 , V_6 , V_5 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 , L_1 , V_7 ) ;
return V_7 ;
}
V_4 -> V_11 = F_4 ( V_5 [ 0 ] ) ;
V_4 -> V_12 = F_4 ( V_5 [ 1 ] ) ;
V_4 -> V_13 = F_4 ( V_5 [ 2 ] ) ;
V_4 -> V_14 = F_4 ( V_5 [ 3 ] ) ;
V_4 -> V_15 = F_4 ( V_5 [ 4 ] ) - 1 ;
V_4 -> V_16 = F_4 ( V_5 [ 5 ] ) + V_17 ;
V_4 -> V_18 = F_4 ( V_5 [ 6 ] ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 [ 7 ] ;
int V_7 ;
V_5 [ 0 ] = F_6 ( V_4 -> V_11 ) ;
V_5 [ 1 ] = F_6 ( V_4 -> V_12 ) ;
V_5 [ 2 ] = F_6 ( V_4 -> V_13 ) ;
V_5 [ 3 ] = F_6 ( V_4 -> V_14 ) ;
V_5 [ 4 ] = F_6 ( V_4 -> V_15 + 1 ) ;
V_5 [ 5 ] = F_6 ( V_4 -> V_16 % V_17 ) ;
V_5 [ 6 ] = F_6 ( V_4 -> V_18 ) ;
V_7 = F_7 ( V_2 -> V_8 , V_9 ,
V_19 , V_20 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_8 , L_2 , V_7 ) ;
return V_7 ;
}
V_7 = F_8 ( V_2 -> V_8 , V_9 ,
V_10 ,
V_6 , V_5 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 , L_3 , V_7 ) ;
return V_7 ;
}
V_7 = F_9 ( V_2 -> V_8 , V_9 ,
V_19 , V_20 ) ;
if ( V_7 < 0 )
F_3 ( V_2 -> V_8 , L_4 , V_7 ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
int V_7 ;
if ( V_21 )
V_7 = F_9 ( V_2 -> V_8 , V_9 ,
V_22 , V_23 ) ;
else
V_7 = F_7 ( V_2 -> V_8 , V_9 ,
V_22 , V_23 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 , L_5 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
T_1 V_5 [ V_26 ] ;
int V_7 ;
V_5 [ 0 ] = F_6 ( V_25 -> time . V_11 ) ;
V_5 [ 1 ] = F_6 ( V_25 -> time . V_12 ) ;
V_5 [ 2 ] = F_6 ( V_25 -> time . V_13 ) ;
V_5 [ 3 ] = F_6 ( V_25 -> time . V_14 ) ;
V_5 [ 4 ] = F_6 ( V_25 -> time . V_15 + 1 ) ;
V_5 [ 5 ] = F_6 ( V_25 -> time . V_16 % V_17 ) ;
V_7 = F_8 ( V_2 -> V_8 , V_9 ,
V_27 ,
V_26 , V_5 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 , L_6 , V_7 ) ;
return V_7 ;
}
return F_10 ( V_2 , V_25 -> V_28 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
T_1 V_5 [ 6 ] ;
int V_7 ;
V_7 = F_2 ( V_2 -> V_8 , V_9 ,
V_27 ,
V_26 , V_5 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_8 ,
L_7 , V_7 ) ;
return V_7 ;
}
V_25 -> time . V_11 = F_4 ( V_5 [ 0 ] ) ;
V_25 -> time . V_12 = F_4 ( V_5 [ 1 ] ) ;
V_25 -> time . V_13 = F_4 ( V_5 [ 2 ] ) ;
V_25 -> time . V_14 = F_4 ( V_5 [ 3 ] ) ;
V_25 -> time . V_15 = F_4 ( V_5 [ 4 ] ) - 1 ;
V_25 -> time . V_16 = F_4 ( V_5 [ 5 ] ) + V_17 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
int V_7 ;
T_1 V_31 ;
V_7 = F_14 ( V_2 -> V_8 , V_9 ,
V_32 , & V_31 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 , L_8 , V_7 ) ;
return V_7 ;
}
V_7 = F_9 ( V_2 -> V_8 , V_9 ,
V_32 , V_33 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 , L_9 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static T_2 F_15 ( int V_34 , void * V_35 )
{
struct V_1 * V_2 = V_35 ;
struct V_29 * V_30 = F_16 ( V_2 ) ;
int V_7 ;
V_7 = F_13 ( V_2 , V_30 ) ;
if ( V_7 < 0 )
return V_7 ;
F_17 ( V_30 -> V_30 , 1 , V_36 | V_37 ) ;
return V_38 ;
}
static int F_18 ( struct V_39 * V_40 )
{
struct V_29 * V_30 ;
struct V_3 V_4 ;
int V_7 ;
V_30 = F_19 ( & V_40 -> V_2 , sizeof( * V_30 ) , V_41 ) ;
if ( ! V_30 )
return - V_42 ;
V_30 -> V_34 = F_20 ( V_40 , 0 ) ;
F_21 ( V_40 , V_30 ) ;
V_7 = F_9 ( V_40 -> V_2 . V_8 , V_9 ,
V_19 , V_20 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_40 -> V_2 , L_10 , V_7 ) ;
return V_7 ;
}
F_1 ( & V_40 -> V_2 , & V_4 ) ;
if ( ( V_4 . V_16 == V_17 + V_43 ) &&
( V_4 . V_15 == ( V_44 - 1 ) ) &&
( V_4 . V_14 == V_45 ) ) {
V_4 . V_16 = 2000 ;
V_4 . V_14 = 1 ;
V_4 . V_15 = 1 ;
V_7 = F_5 ( & V_40 -> V_2 , & V_4 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_40 -> V_2 ,
L_11 , V_7 ) ;
return V_7 ;
}
}
V_7 = F_13 ( & V_40 -> V_2 , V_30 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_40 -> V_2 , L_12 , V_7 ) ;
return V_7 ;
}
V_30 -> V_30 = F_22 ( & V_40 -> V_2 , V_40 -> V_46 ,
& V_47 , V_48 ) ;
if ( F_23 ( V_30 -> V_30 ) ) {
V_7 = F_24 ( V_30 -> V_30 ) ;
F_3 ( & V_40 -> V_2 , L_13 , V_7 ) ;
return V_7 ;
}
V_7 = F_25 ( & V_40 -> V_2 , V_30 -> V_34 , NULL ,
F_15 ,
V_49 ,
F_26 ( & V_40 -> V_2 ) , V_30 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_40 -> V_2 , L_14 ,
V_30 -> V_34 , V_7 ) ;
return V_7 ;
}
F_27 ( & V_40 -> V_2 , 1 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_16 ( V_2 ) ;
if ( F_29 ( V_2 ) )
F_30 ( V_30 -> V_34 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_16 ( V_2 ) ;
if ( F_29 ( V_2 ) )
F_32 ( V_30 -> V_34 ) ;
return 0 ;
}
