static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
T_1 V_7 = 0 ;
if ( V_3 )
V_7 = V_8 ;
return F_3 ( V_5 -> V_9 , V_10 , V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
unsigned char V_13 [ V_14 ] ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_15 ;
V_15 = F_5 ( V_5 -> V_9 , V_16 ,
V_17 , V_17 ) ;
if ( V_15 < 0 ) {
F_6 ( V_2 , L_1 , V_15 ) ;
return V_15 ;
}
V_15 = F_7 ( V_5 -> V_9 , V_18 , V_13 ,
V_14 ) ;
if ( V_15 < 0 ) {
F_6 ( V_2 , L_2 , V_15 ) ;
return V_15 ;
}
V_12 -> V_19 = F_8 ( V_13 [ 0 ] ) ;
V_12 -> V_20 = F_8 ( V_13 [ 1 ] ) ;
V_12 -> V_21 = F_8 ( V_13 [ 2 ] ) ;
V_12 -> V_22 = F_8 ( V_13 [ 3 ] ) ;
V_12 -> V_23 = F_8 ( V_13 [ 4 ] ) - 1 ;
V_12 -> V_24 = F_8 ( V_13 [ 5 ] ) + 100 ;
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
unsigned char V_13 [ V_14 ] ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_15 ;
V_13 [ 0 ] = F_10 ( V_12 -> V_19 ) ;
V_13 [ 1 ] = F_10 ( V_12 -> V_20 ) ;
V_13 [ 2 ] = F_10 ( V_12 -> V_21 ) ;
V_13 [ 3 ] = F_10 ( V_12 -> V_22 ) ;
V_13 [ 4 ] = F_10 ( V_12 -> V_23 + 1 ) ;
V_13 [ 5 ] = F_10 ( V_12 -> V_24 - 100 ) ;
V_15 = F_5 ( V_5 -> V_9 , V_16 ,
V_25 , 0 ) ;
if ( V_15 < 0 ) {
F_6 ( V_2 , L_3 , V_15 ) ;
return V_15 ;
}
V_15 = F_11 ( V_5 -> V_9 , V_18 , V_13 ,
V_14 ) ;
if ( V_15 < 0 ) {
F_6 ( V_2 , L_4 , V_15 ) ;
return V_15 ;
}
V_15 = F_5 ( V_5 -> V_9 , V_16 ,
V_25 , 1 ) ;
if ( V_15 < 0 )
F_6 ( V_2 , L_5 , V_15 ) ;
return V_15 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
unsigned char V_28 [ V_14 ] ;
T_2 V_29 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_15 ;
V_15 = F_7 ( V_5 -> V_9 , V_18 , V_28 ,
V_14 ) ;
if ( V_15 < 0 ) {
F_6 ( V_2 , L_6 , V_15 ) ;
return V_15 ;
}
V_27 -> time . V_19 = F_8 ( V_28 [ 0 ] ) ;
V_27 -> time . V_20 = F_8 ( V_28 [ 1 ] ) ;
V_27 -> time . V_21 = F_8 ( V_28 [ 2 ] ) ;
V_27 -> time . V_22 = F_8 ( V_28 [ 3 ] ) ;
V_27 -> time . V_23 = F_8 ( V_28 [ 4 ] ) - 1 ;
V_27 -> time . V_24 = F_8 ( V_28 [ 5 ] ) + 100 ;
V_15 = F_13 ( V_5 -> V_9 , V_10 , & V_29 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_29 & V_8 )
V_27 -> V_3 = 1 ;
return V_15 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
unsigned char V_28 [ V_14 ] ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_15 ;
V_15 = F_1 ( V_2 , 0 ) ;
if ( V_15 )
return V_15 ;
V_28 [ 0 ] = F_10 ( V_27 -> time . V_19 ) ;
V_28 [ 1 ] = F_10 ( V_27 -> time . V_20 ) ;
V_28 [ 2 ] = F_10 ( V_27 -> time . V_21 ) ;
V_28 [ 3 ] = F_10 ( V_27 -> time . V_22 ) ;
V_28 [ 4 ] = F_10 ( V_27 -> time . V_23 + 1 ) ;
V_28 [ 5 ] = F_10 ( V_27 -> time . V_24 - 100 ) ;
V_15 = F_11 ( V_5 -> V_9 , V_30 ,
V_28 , V_14 ) ;
if ( V_15 ) {
F_6 ( V_2 , L_7 , V_15 ) ;
return V_15 ;
}
if ( V_27 -> V_3 )
V_15 = F_1 ( V_2 , 1 ) ;
return V_15 ;
}
static T_3 F_15 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
unsigned long V_33 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_34 * V_35 = F_2 ( V_2 ) ;
int V_15 ;
T_2 V_36 ;
V_15 = F_13 ( V_5 -> V_9 , V_37 , & V_36 ) ;
if ( V_15 )
return V_38 ;
if ( V_36 & V_39 )
V_33 = V_40 | V_41 ;
V_15 = F_3 ( V_5 -> V_9 , V_37 , V_36 ) ;
if ( V_15 )
return V_38 ;
F_16 ( V_35 -> V_32 , 1 , V_33 ) ;
return V_42 ;
}
static int F_17 ( struct V_43 * V_44 )
{
struct V_4 * V_4 = NULL ;
struct V_34 * V_35 = NULL ;
int V_15 ;
int V_31 ;
T_2 V_36 ;
V_4 = F_2 ( V_44 -> V_2 . V_6 ) ;
V_35 = F_18 ( & V_44 -> V_2 , sizeof( struct V_34 ) ,
V_45 ) ;
if ( ! V_35 )
return - V_46 ;
V_15 = F_13 ( V_4 -> V_9 , V_37 , & V_36 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_3 ( V_4 -> V_9 , V_37 , V_36 ) ;
if ( V_15 < 0 )
return V_15 ;
F_19 ( & V_44 -> V_2 , L_8 ) ;
V_15 = F_5 ( V_4 -> V_9 , V_47 ,
V_48 , 0 << V_49 ) ;
if ( V_15 < 0 )
return V_15 ;
V_36 = V_25 ;
V_15 = F_3 ( V_4 -> V_9 , V_16 , V_36 ) ;
if ( V_15 < 0 )
return V_15 ;
F_20 ( V_44 , V_35 ) ;
V_31 = F_21 ( V_44 , 0 ) ;
if ( V_31 <= 0 ) {
F_22 ( & V_44 -> V_2 , L_9 ,
V_31 ) ;
return - V_50 ;
}
V_15 = F_23 ( & V_44 -> V_2 , V_31 , NULL ,
F_15 , V_51 | V_52 ,
F_24 ( & V_44 -> V_2 ) , & V_44 -> V_2 ) ;
if ( V_15 < 0 ) {
F_6 ( & V_44 -> V_2 , L_10 ) ;
return V_15 ;
}
V_35 -> V_31 = V_31 ;
F_25 ( & V_44 -> V_2 , 1 ) ;
V_35 -> V_32 = F_26 ( & V_44 -> V_2 , V_44 -> V_53 ,
& V_54 , V_55 ) ;
if ( F_27 ( V_35 -> V_32 ) ) {
V_15 = F_28 ( V_35 -> V_32 ) ;
F_6 ( & V_44 -> V_2 , L_11 , V_15 ) ;
return V_15 ;
}
return 0 ;
}
static int F_29 ( struct V_43 * V_44 )
{
F_1 ( & V_44 -> V_2 , 0 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_2 ( V_2 ) ;
if ( F_31 ( V_2 ) )
F_32 ( V_35 -> V_31 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_2 ( V_2 ) ;
if ( F_31 ( V_2 ) )
F_34 ( V_35 -> V_31 ) ;
return 0 ;
}
