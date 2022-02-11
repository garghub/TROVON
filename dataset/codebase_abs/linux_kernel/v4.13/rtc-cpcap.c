static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long int V_5 ;
unsigned long int time ;
V_5 = ( V_4 -> V_6 & V_7 ) | ( ( V_4 -> V_8 & V_9 ) << 8 ) ;
time = V_5 + ( ( V_4 -> V_10 & V_11 ) * V_12 ) ;
F_2 ( time , V_2 ) ;
}
static void F_3 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned long time ;
F_4 ( V_2 , & time ) ;
V_4 -> V_10 = time / V_12 ;
time %= V_12 ;
V_4 -> V_8 = ( time >> 8 ) & V_9 ;
V_4 -> V_6 = time & V_7 ;
}
static int F_5 ( struct V_13 * V_14 , unsigned int V_15 )
{
struct V_16 * V_2 = F_6 ( V_14 ) ;
if ( V_2 -> V_17 == V_15 )
return 0 ;
if ( V_15 )
F_7 ( V_2 -> V_18 ) ;
else
F_8 ( V_2 -> V_18 ) ;
V_2 -> V_17 = ! ! V_15 ;
return 0 ;
}
static int F_9 ( struct V_13 * V_14 , struct V_1 * V_19 )
{
struct V_16 * V_2 ;
struct V_3 V_20 ;
int V_21 ;
int V_22 ;
V_2 = F_6 ( V_14 ) ;
V_22 = F_10 ( V_2 -> V_23 , V_24 , & V_21 ) ;
V_22 |= F_10 ( V_2 -> V_23 , V_25 , & V_20 . V_10 ) ;
V_22 |= F_10 ( V_2 -> V_23 , V_26 , & V_20 . V_6 ) ;
V_22 |= F_10 ( V_2 -> V_23 , V_24 , & V_20 . V_8 ) ;
if ( V_21 > V_20 . V_8 )
V_22 |= F_10 ( V_2 -> V_23 , V_25 , & V_20 . V_10 ) ;
if ( V_22 ) {
F_11 ( V_14 , L_1 ) ;
return - V_27 ;
}
F_1 ( V_19 , & V_20 ) ;
return F_12 ( V_19 ) ;
}
static int F_13 ( struct V_13 * V_14 , struct V_1 * V_19 )
{
struct V_16 * V_2 ;
struct V_3 V_20 ;
int V_22 = 0 ;
V_2 = F_6 ( V_14 ) ;
F_3 ( & V_20 , V_19 ) ;
if ( V_2 -> V_17 )
F_8 ( V_2 -> V_18 ) ;
if ( V_2 -> V_28 )
F_8 ( V_2 -> V_29 ) ;
if ( V_2 -> V_30 == V_31 ) {
V_22 |= F_14 ( V_2 -> V_23 , V_26 ,
V_7 , V_20 . V_6 ) ;
V_22 |= F_14 ( V_2 -> V_23 , V_24 ,
V_9 , V_20 . V_8 ) ;
V_22 |= F_14 ( V_2 -> V_23 , V_25 ,
V_11 , V_20 . V_10 ) ;
} else {
V_22 |= F_14 ( V_2 -> V_23 , V_26 ,
V_7 , 0 ) ;
V_22 |= F_14 ( V_2 -> V_23 , V_25 ,
V_11 , V_20 . V_10 ) ;
V_22 |= F_14 ( V_2 -> V_23 , V_24 ,
V_9 , V_20 . V_8 ) ;
V_22 |= F_14 ( V_2 -> V_23 , V_26 ,
V_7 , V_20 . V_6 ) ;
}
if ( V_2 -> V_28 )
F_7 ( V_2 -> V_29 ) ;
if ( V_2 -> V_17 )
F_7 ( V_2 -> V_18 ) ;
return V_22 ;
}
static int F_15 ( struct V_13 * V_14 , struct V_32 * V_33 )
{
struct V_16 * V_2 ;
struct V_3 V_20 ;
int V_22 ;
V_2 = F_6 ( V_14 ) ;
V_33 -> V_15 = V_2 -> V_17 ;
V_22 = F_10 ( V_2 -> V_23 , V_34 , & V_20 . V_10 ) ;
V_22 |= F_10 ( V_2 -> V_23 , V_35 , & V_20 . V_8 ) ;
V_22 |= F_10 ( V_2 -> V_23 , V_36 , & V_20 . V_6 ) ;
if ( V_22 ) {
F_11 ( V_14 , L_1 ) ;
return - V_27 ;
}
F_1 ( & V_33 -> time , & V_20 ) ;
return F_12 ( & V_33 -> time ) ;
}
static int F_16 ( struct V_13 * V_14 , struct V_32 * V_33 )
{
struct V_16 * V_2 ;
struct V_3 V_20 ;
int V_22 ;
V_2 = F_6 ( V_14 ) ;
F_3 ( & V_20 , & V_33 -> time ) ;
if ( V_2 -> V_17 )
F_8 ( V_2 -> V_18 ) ;
V_22 = F_14 ( V_2 -> V_23 , V_34 , V_11 ,
V_20 . V_10 ) ;
V_22 |= F_14 ( V_2 -> V_23 , V_35 , V_9 ,
V_20 . V_8 ) ;
V_22 |= F_14 ( V_2 -> V_23 , V_36 , V_7 ,
V_20 . V_6 ) ;
if ( ! V_22 ) {
F_7 ( V_2 -> V_18 ) ;
V_2 -> V_17 = true ;
}
return V_22 ;
}
static T_1 F_17 ( int V_37 , void * V_38 )
{
struct V_16 * V_2 = V_38 ;
F_18 ( V_2 -> V_39 , 1 , V_40 | V_41 ) ;
return V_42 ;
}
static T_1 F_19 ( int V_37 , void * V_38 )
{
struct V_16 * V_2 = V_38 ;
F_18 ( V_2 -> V_39 , 1 , V_43 | V_41 ) ;
return V_42 ;
}
static int F_20 ( struct V_44 * V_45 )
{
struct V_13 * V_14 = & V_45 -> V_14 ;
struct V_16 * V_2 ;
int V_46 ;
V_2 = F_21 ( V_14 , sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 )
return - V_48 ;
V_2 -> V_23 = F_22 ( V_14 -> V_49 , NULL ) ;
if ( ! V_2 -> V_23 )
return - V_50 ;
F_23 ( V_45 , V_2 ) ;
V_2 -> V_39 = F_24 ( V_14 , L_2 ,
& V_51 , V_52 ) ;
if ( F_25 ( V_2 -> V_39 ) )
return F_26 ( V_2 -> V_39 ) ;
V_46 = F_27 ( V_14 , V_2 -> V_23 , & V_2 -> V_30 ) ;
if ( V_46 )
return V_46 ;
V_2 -> V_18 = F_28 ( V_45 , 0 ) ;
V_46 = F_29 ( V_14 , V_2 -> V_18 , NULL ,
F_17 , V_53 ,
L_3 , V_2 ) ;
if ( V_46 ) {
F_11 ( V_14 , L_4 , V_46 ) ;
return V_46 ;
}
F_8 ( V_2 -> V_18 ) ;
V_2 -> V_29 = F_28 ( V_45 , 1 ) ;
V_46 = F_29 ( V_14 , V_2 -> V_29 , NULL ,
F_19 , V_53 ,
L_5 , V_2 ) ;
if ( V_46 ) {
F_11 ( V_14 , L_6 , V_46 ) ;
return V_46 ;
}
F_8 ( V_2 -> V_29 ) ;
V_46 = F_30 ( V_14 , 1 ) ;
if ( V_46 ) {
F_11 ( V_14 , L_7 , V_46 ) ;
}
return 0 ;
}
