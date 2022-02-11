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
unsigned int V_24 , unsigned int V_25 )
{
unsigned int V_26 ;
unsigned int V_14 ;
F_4 ( V_13 , V_27 , 0xfff , V_23 ) ;
F_4 ( V_13 , V_28 , 0xfffff , V_24 ) ;
V_26 = V_23 * V_24 * V_25 * 4 * 7 / 1000000 ;
V_14 = V_29 |
F_12 ( V_30 ) |
F_13 ( V_26 ) ;
F_2 ( V_14 , V_13 -> V_8 + V_31 ) ;
}
static int F_14 ( struct V_32 * V_33 , struct V_32 * V_34 ,
void * V_35 )
{
struct V_3 * V_4 = F_15 ( V_33 ) ;
struct V_36 * V_37 = V_35 ;
int V_38 ;
V_38 = F_16 ( V_37 , & V_4 -> V_7 ) ;
if ( V_38 < 0 ) {
F_17 ( V_33 , L_1 ,
V_33 -> V_39 -> V_40 , V_38 ) ;
return V_38 ;
}
return 0 ;
}
static void F_18 ( struct V_32 * V_33 , struct V_32 * V_34 ,
void * V_35 )
{
struct V_3 * V_4 = F_15 ( V_33 ) ;
struct V_36 * V_37 = V_35 ;
F_19 ( V_37 , & V_4 -> V_7 ) ;
}
static int F_20 ( struct V_41 * V_42 )
{
struct V_32 * V_33 = & V_42 -> V_33 ;
struct V_3 * V_4 ;
int V_43 ;
int V_1 ;
int V_38 ;
V_4 = F_21 ( V_33 , sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return - V_45 ;
V_1 = F_22 ( V_42 , 0 ) ;
if ( V_1 < 0 )
return V_1 ;
V_43 = F_23 ( V_33 -> V_39 , V_46 ) ;
if ( V_43 < 0 ) {
F_17 ( V_33 , L_2 , V_43 ) ;
return V_43 ;
}
V_38 = F_24 ( V_33 , V_33 -> V_39 , & V_4 -> V_7 , V_43 ,
& V_47 ) ;
if ( V_38 ) {
F_17 ( V_33 , L_3 , V_38 ) ;
return V_38 ;
}
F_2 ( 0x0 , V_4 -> V_7 . V_8 + V_19 ) ;
F_2 ( 0x0 , V_4 -> V_7 . V_8 + V_9 ) ;
V_38 = F_25 ( V_33 , V_1 , F_1 ,
V_48 , F_26 ( V_33 ) , V_4 ) ;
if ( V_38 < 0 ) {
F_17 ( V_33 , L_4 , V_1 , V_38 ) ;
return V_38 ;
}
F_27 ( V_42 , V_4 ) ;
V_38 = F_28 ( V_33 , & V_49 ) ;
if ( V_38 )
F_17 ( V_33 , L_5 , V_38 ) ;
return V_38 ;
}
static int F_29 ( struct V_41 * V_42 )
{
F_30 ( & V_42 -> V_33 , & V_49 ) ;
return 0 ;
}
