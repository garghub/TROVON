static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = & V_4 -> V_7 ;
F_2 ( 0x0 , V_6 -> V_8 + V_9 ) ;
if ( ! V_4 -> V_10 )
return V_11 ;
F_3 ( V_4 -> V_10 , V_6 ) ;
return V_12 ;
}
static void F_4 ( struct V_5 * V_13 , unsigned int V_14 ,
unsigned int V_15 , unsigned int V_16 )
{
unsigned int V_17 = F_5 ( V_13 -> V_8 + V_14 ) ;
V_17 = ( V_17 & ~ V_15 ) | ( V_16 & V_15 ) ;
F_2 ( V_17 , V_13 -> V_8 + V_14 ) ;
}
static void F_6 ( struct V_5 * V_13 ,
struct V_18 * V_10 )
{
struct V_3 * V_4 = F_7 ( V_13 , struct V_3 ,
V_7 ) ;
V_4 -> V_10 = V_10 ;
F_4 ( V_13 , V_19 , V_20 ,
V_20 ) ;
}
static void F_8 ( struct V_5 * V_13 )
{
struct V_3 * V_4 = F_7 ( V_13 , struct V_3 ,
V_7 ) ;
V_4 -> V_10 = NULL ;
F_4 ( V_13 , V_19 , V_20 , 0 ) ;
}
static void F_9 ( struct V_5 * V_13 )
{
F_4 ( V_13 , V_21 , V_22 ,
V_22 ) ;
}
static void F_10 ( struct V_5 * V_13 )
{
F_4 ( V_13 , V_21 , V_22 , 0 ) ;
}
static void F_11 ( struct V_5 * V_13 , unsigned int V_23 ,
unsigned int V_24 , unsigned int V_25 ,
unsigned int V_26 )
{
unsigned int V_27 ;
unsigned int V_14 ;
F_4 ( V_13 , V_28 , 0xfff , V_23 ) ;
F_4 ( V_13 , V_29 , 0xfffff , V_24 ) ;
V_27 = V_23 * V_24 * V_25 * 4 * 7 / 1000000 ;
V_14 = V_30 |
F_12 ( V_31 ) |
F_13 ( V_27 ) ;
F_2 ( V_14 , V_13 -> V_8 + V_32 ) ;
}
static int F_14 ( struct V_33 * V_34 , struct V_33 * V_35 ,
void * V_36 )
{
struct V_3 * V_4 = F_15 ( V_34 ) ;
struct V_37 * V_38 = V_36 ;
int V_39 ;
V_39 = F_16 ( V_38 , & V_4 -> V_7 ) ;
if ( V_39 < 0 ) {
F_17 ( V_34 , L_1 ,
V_34 -> V_40 -> V_41 , V_39 ) ;
return V_39 ;
}
return 0 ;
}
static void F_18 ( struct V_33 * V_34 , struct V_33 * V_35 ,
void * V_36 )
{
struct V_3 * V_4 = F_15 ( V_34 ) ;
struct V_37 * V_38 = V_36 ;
F_19 ( V_38 , & V_4 -> V_7 ) ;
}
static int F_20 ( struct V_42 * V_43 )
{
struct V_33 * V_34 = & V_43 -> V_34 ;
struct V_3 * V_4 ;
int V_44 ;
int V_1 ;
int V_39 ;
V_4 = F_21 ( V_34 , sizeof( * V_4 ) , V_45 ) ;
if ( ! V_4 )
return - V_46 ;
V_1 = F_22 ( V_43 , 0 ) ;
if ( V_1 < 0 )
return V_1 ;
V_44 = F_23 ( V_34 -> V_40 , V_47 ) ;
if ( V_44 < 0 ) {
F_17 ( V_34 , L_2 , V_44 ) ;
return V_44 ;
}
V_39 = F_24 ( V_34 , V_34 -> V_40 , & V_4 -> V_7 , V_44 ,
& V_48 ) ;
if ( V_39 ) {
F_17 ( V_34 , L_3 , V_39 ) ;
return V_39 ;
}
F_2 ( 0x0 , V_4 -> V_7 . V_8 + V_19 ) ;
F_2 ( 0x0 , V_4 -> V_7 . V_8 + V_9 ) ;
V_39 = F_25 ( V_34 , V_1 , F_1 ,
V_49 , F_26 ( V_34 ) , V_4 ) ;
if ( V_39 < 0 ) {
F_17 ( V_34 , L_4 , V_1 , V_39 ) ;
return V_39 ;
}
F_27 ( V_43 , V_4 ) ;
V_39 = F_28 ( V_34 , & V_50 ) ;
if ( V_39 )
F_17 ( V_34 , L_5 , V_39 ) ;
return V_39 ;
}
static int F_29 ( struct V_42 * V_43 )
{
F_30 ( & V_43 -> V_34 , & V_50 ) ;
return 0 ;
}
