static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
T_1 V_6 ;
V_6 = V_3 ? V_7 : 0 ;
return F_3 ( V_4 -> V_8 , V_9 , V_7 ,
V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
T_1 V_12 [ V_13 ] ;
int V_14 ;
V_14 = F_5 ( V_4 -> V_8 , V_15 , V_12 ,
V_13 ) ;
if ( V_14 < 0 ) {
F_6 ( V_2 , L_1 , V_14 ) ;
return V_14 ;
}
V_11 -> V_16 = F_7 ( V_12 [ 0 ] ) ;
V_11 -> V_17 = F_7 ( V_12 [ 1 ] ) ;
V_11 -> V_18 = F_7 ( V_12 [ 2 ] ) ;
V_11 -> V_19 = F_7 ( V_12 [ 3 ] ) ;
V_11 -> V_20 = F_7 ( V_12 [ 4 ] ) ;
V_11 -> V_21 = F_7 ( V_12 [ 5 ] ) - 1 ;
V_11 -> V_22 = F_7 ( V_12 [ 6 ] ) + 100 ;
return V_14 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned char V_12 [ V_13 ] ;
int V_14 ;
V_12 [ 0 ] = F_9 ( V_11 -> V_16 ) ;
V_12 [ 1 ] = F_9 ( V_11 -> V_17 ) ;
V_12 [ 2 ] = F_9 ( V_11 -> V_18 ) ;
V_12 [ 3 ] = F_9 ( V_11 -> V_19 ) ;
V_12 [ 4 ] = F_9 ( V_11 -> V_20 ) ;
V_12 [ 5 ] = F_9 ( V_11 -> V_21 + 1 ) ;
V_12 [ 6 ] = F_9 ( V_11 -> V_22 - 100 ) ;
V_14 = F_10 ( V_4 -> V_8 , V_15 , V_12 ,
V_13 ) ;
if ( V_14 < 0 ) {
F_6 ( V_2 , L_2 , V_14 ) ;
return V_14 ;
}
return V_14 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned char V_25 [ V_26 ] ;
T_2 V_27 ;
int V_14 ;
V_14 = F_5 ( V_4 -> V_8 , V_28 , V_25 ,
V_26 ) ;
if ( V_14 < 0 ) {
F_6 ( V_2 , L_3 , V_14 ) ;
return V_14 ;
}
V_24 -> time . V_17 = F_7 ( V_25 [ 0 ] ) ;
V_24 -> time . V_18 = F_7 ( V_25 [ 1 ] ) ;
V_24 -> time . V_20 = F_7 ( V_25 [ 2 ] ) ;
V_24 -> time . V_21 = F_7 ( V_25 [ 3 ] ) - 1 ;
V_24 -> time . V_22 = F_7 ( V_25 [ 4 ] ) + 100 ;
V_14 = F_12 ( V_4 -> V_8 , V_9 , & V_27 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_27 & V_7 )
V_24 -> V_3 = 1 ;
return V_14 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned char V_25 [ V_26 ] ;
int V_14 ;
V_14 = F_1 ( V_2 , 0 ) ;
if ( V_14 )
return V_14 ;
V_25 [ 0 ] = F_9 ( V_24 -> time . V_17 ) ;
V_25 [ 1 ] = F_9 ( V_24 -> time . V_18 ) ;
V_25 [ 2 ] = F_9 ( V_24 -> time . V_20 ) ;
V_25 [ 3 ] = F_9 ( V_24 -> time . V_21 + 1 ) ;
V_25 [ 4 ] = F_9 ( V_24 -> time . V_22 - 100 ) ;
V_14 = F_10 ( V_4 -> V_8 , V_28 , V_25 ,
V_26 ) ;
if ( V_14 ) {
F_6 ( V_2 , L_4 , V_14 ) ;
return V_14 ;
}
if ( V_24 -> V_3 )
V_14 = F_1 ( V_2 , 1 ) ;
return V_14 ;
}
static T_3 F_14 ( int V_29 , void * V_30 )
{
struct V_1 * V_2 = V_30 ;
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_31 * V_31 = F_2 ( V_2 ) ;
unsigned long V_32 = 0 ;
int V_14 ;
T_2 V_33 ;
V_14 = F_12 ( V_4 -> V_8 , V_34 , & V_33 ) ;
if ( V_14 < 0 )
return V_35 ;
if ( V_33 & V_36 ) {
V_32 = V_37 | V_38 ;
V_33 &= ~ V_36 ;
}
V_14 = F_15 ( V_4 -> V_8 , V_34 , V_33 ) ;
if ( V_14 )
return V_35 ;
F_16 ( V_31 -> V_30 , 1 , V_32 ) ;
return V_39 ;
}
static int T_4 F_17 ( struct V_40 * V_41 )
{
struct V_4 * V_4 = F_2 ( V_41 -> V_2 . V_5 ) ;
struct V_31 * V_42 ;
struct V_43 * V_44 ;
int V_14 ;
int V_29 ;
V_42 = F_18 ( & V_41 -> V_2 , sizeof( struct V_31 ) ,
V_45 ) ;
if ( ! V_42 )
return - V_46 ;
F_19 ( V_41 , V_42 ) ;
V_14 = F_15 ( V_4 -> V_8 , V_34 , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_15 ( V_4 -> V_8 , V_47 , 0 ) ;
if ( V_14 < 0 ) {
F_6 ( & V_41 -> V_2 , L_5 ) ;
return - V_48 ;
}
V_44 = F_20 ( V_4 -> V_2 ) ;
V_29 = V_44 -> V_49 ;
if ( V_29 <= 0 ) {
F_21 ( & V_41 -> V_2 , L_6 ,
V_29 ) ;
return V_14 ;
}
V_29 += V_50 ;
V_14 = F_22 ( & V_41 -> V_2 , V_29 , NULL ,
F_14 , V_51 ,
L_7 , & V_41 -> V_2 ) ;
if ( V_14 < 0 ) {
F_6 ( & V_41 -> V_2 , L_8 ) ;
return V_14 ;
}
F_23 ( & V_41 -> V_2 , 1 ) ;
V_42 -> V_30 = F_24 ( V_41 -> V_52 , & V_41 -> V_2 ,
& V_53 , V_54 ) ;
if ( F_25 ( V_42 -> V_30 ) ) {
V_14 = F_26 ( V_42 -> V_30 ) ;
F_6 ( & V_41 -> V_2 , L_9 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int T_5 F_27 ( struct V_40 * V_41 )
{
struct V_31 * V_31 = F_2 ( & V_41 -> V_2 ) ;
F_1 ( & V_31 -> V_30 -> V_2 , 0 ) ;
F_28 ( V_31 -> V_30 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_31 * V_31 = F_2 ( V_2 ) ;
int V_14 ;
V_14 = F_12 ( V_4 -> V_8 , V_9 ,
& V_31 -> V_55 ) ;
return V_14 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_31 * V_31 = F_2 ( V_2 ) ;
return F_15 ( V_4 -> V_8 , V_9 ,
V_31 -> V_55 ) ;
}
