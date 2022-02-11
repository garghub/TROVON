static void F_1 ( T_1 * V_1 , struct V_2 * V_3 )
{
V_1 [ 0 ] = F_2 ( V_3 -> V_4 ) ;
V_1 [ 1 ] = F_2 ( V_3 -> V_5 ) ;
V_1 [ 2 ] = F_2 ( V_3 -> V_6 ) ;
V_1 [ 3 ] = F_2 ( V_3 -> V_7 ) ;
V_1 [ 4 ] = F_2 ( V_3 -> V_8 ) ;
V_1 [ 5 ] = F_2 ( V_3 -> V_9 - ( V_10 - 1900 ) ) ;
}
static void F_3 ( T_1 * V_1 , struct V_2 * V_3 )
{
V_3 -> V_4 = F_4 ( V_1 [ 0 ] & 0x7F ) ;
V_3 -> V_5 = F_4 ( V_1 [ 1 ] & 0x7F ) ;
V_3 -> V_6 = F_4 ( V_1 [ 2 ] & 0x3F ) ;
V_3 -> V_7 = F_4 ( V_1 [ 3 ] & 0x3F ) ;
V_3 -> V_8 = F_4 ( V_1 [ 4 ] & 0x1F ) ;
V_3 -> V_9 = ( V_10 - 1900 ) + F_4 ( V_1 [ 5 ] & 0x7F ) ;
return;
}
static int F_5 ( struct V_11 * V_12 , struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_12 ) ;
struct V_14 * V_14 = V_13 -> V_14 ;
T_1 V_15 [ 6 ] ;
int V_16 ;
V_16 = F_7 ( V_14 , V_17 ,
6 , V_15 ) ;
if ( V_16 < 0 ) {
F_8 ( V_12 , L_1 , V_16 ) ;
return V_16 ;
}
F_3 ( V_15 , V_3 ) ;
return 0 ;
}
static int F_9 ( struct V_11 * V_12 , struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_12 ) ;
struct V_14 * V_14 = V_13 -> V_14 ;
T_1 V_15 [ 6 ] ;
int V_16 ;
if ( V_3 -> V_9 < ( V_10 - 1900 ) )
return - V_18 ;
F_1 ( V_15 , V_3 ) ;
V_16 = F_10 ( V_14 , V_17 , 6 ,
V_15 ) ;
if ( V_16 < 0 )
F_8 ( V_12 , L_2 , V_16 ) ;
return V_16 ;
}
static int F_11 ( struct V_11 * V_12 ,
unsigned int V_19 )
{
struct V_13 * V_13 = F_6 ( V_12 ) ;
if ( V_19 && ! V_13 -> V_20 ) {
F_12 ( V_13 -> V_21 ) ;
V_13 -> V_20 = true ;
} else if ( ! V_19 && V_13 -> V_20 ) {
F_13 ( V_13 -> V_21 ) ;
V_13 -> V_20 = false ;
}
return 0 ;
}
static int F_14 ( struct V_11 * V_12 , struct V_22 * V_23 )
{
struct V_13 * V_13 = F_6 ( V_12 ) ;
struct V_14 * V_14 = V_13 -> V_14 ;
T_1 V_15 [ 6 ] ;
int V_16 ;
V_16 = F_7 ( V_14 , V_24 , 6 ,
V_15 ) ;
if ( V_16 < 0 ) {
F_8 ( V_12 , L_3 , V_16 ) ;
return V_16 ;
}
F_3 ( V_15 , & V_23 -> time ) ;
return 0 ;
}
static int F_15 ( struct V_11 * V_12 , struct V_22 * V_23 )
{
struct V_13 * V_13 = F_6 ( V_12 ) ;
struct V_14 * V_14 = V_13 -> V_14 ;
T_1 V_15 [ 6 ] ;
int V_16 ;
if ( V_23 -> time . V_9 < ( V_10 - 1900 ) )
return - V_18 ;
V_16 = F_11 ( V_12 , 0 ) ;
if ( V_16 < 0 ) {
F_8 ( V_12 , L_4 ) ;
return V_16 ;
}
F_1 ( V_15 , & V_23 -> time ) ;
V_16 = F_10 ( V_14 , V_24 , 6 ,
V_15 ) ;
if ( V_16 < 0 ) {
F_8 ( V_12 , L_5 , V_16 ) ;
return V_16 ;
}
if ( V_23 -> V_19 )
V_16 = F_11 ( V_12 , V_23 -> V_19 ) ;
return V_16 ;
}
static T_2 F_16 ( int V_25 , void * V_26 )
{
struct V_13 * V_13 = V_26 ;
F_17 ( V_13 -> V_27 , 1 , V_28 | V_29 ) ;
return V_30 ;
}
static int F_18 ( struct V_31 * V_32 )
{
struct V_14 * V_14 = F_6 ( V_32 -> V_12 . V_33 ) ;
struct V_13 * V_13 ;
int V_16 ;
V_13 = F_19 ( & V_32 -> V_12 , sizeof( * V_13 ) , V_34 ) ;
if ( ! V_13 )
return - V_35 ;
V_13 -> V_14 = V_14 ;
V_13 -> V_12 = & V_32 -> V_12 ;
F_20 ( V_32 , V_13 ) ;
V_16 = F_21 ( V_14 , V_36 ,
V_37 | V_38 ,
V_37 | V_38 ) ;
if ( V_16 < 0 ) {
F_8 ( & V_32 -> V_12 , L_6 , V_16 ) ;
return V_16 ;
}
F_22 ( & V_32 -> V_12 , 1 ) ;
V_13 -> V_27 = F_23 ( & V_32 -> V_12 , L_7 ,
& V_39 , V_40 ) ;
if ( F_24 ( V_13 -> V_27 ) ) {
V_16 = F_25 ( V_13 -> V_27 ) ;
F_8 ( & V_32 -> V_12 , L_8 , V_16 ) ;
return V_16 ;
}
V_13 -> V_21 = F_26 ( V_32 , 0 ) ;
F_27 ( & V_32 -> V_12 , L_9 , V_13 -> V_21 ) ;
V_16 = F_28 ( & V_32 -> V_12 , V_13 -> V_21 , NULL ,
F_16 , V_41 | V_42 ,
L_10 , V_13 ) ;
if ( V_16 < 0 ) {
F_8 ( & V_32 -> V_12 , L_11 ,
V_13 -> V_21 , V_16 ) ;
return V_16 ;
}
F_13 ( V_13 -> V_21 ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_12 )
{
struct V_13 * V_13 = F_6 ( V_12 ) ;
if ( F_30 ( V_12 ) )
F_31 ( V_13 -> V_21 ) ;
return 0 ;
}
static int F_32 ( struct V_11 * V_12 )
{
struct V_13 * V_13 = F_6 ( V_12 ) ;
if ( F_30 ( V_12 ) )
F_33 ( V_13 -> V_21 ) ;
return 0 ;
}
