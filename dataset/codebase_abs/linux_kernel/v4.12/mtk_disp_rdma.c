static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static T_1 F_3 ( int V_5 , void * V_6 )
{
struct V_1 * V_7 = V_6 ;
struct V_2 * V_8 = & V_7 -> V_4 ;
F_4 ( 0x0 , V_8 -> V_9 + V_10 ) ;
if ( ! V_7 -> V_11 )
return V_12 ;
F_5 ( V_7 -> V_11 , V_8 ) ;
return V_13 ;
}
static void F_6 ( struct V_2 * V_3 , unsigned int V_14 ,
unsigned int V_15 , unsigned int V_16 )
{
unsigned int V_17 = F_7 ( V_3 -> V_9 + V_14 ) ;
V_17 = ( V_17 & ~ V_15 ) | ( V_16 & V_15 ) ;
F_4 ( V_17 , V_3 -> V_9 + V_14 ) ;
}
static void F_8 ( struct V_2 * V_3 ,
struct V_18 * V_11 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_8 -> V_11 = V_11 ;
F_6 ( V_3 , V_19 , V_20 ,
V_20 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_8 -> V_11 = NULL ;
F_6 ( V_3 , V_19 , V_20 , 0 ) ;
}
static void F_10 ( struct V_2 * V_3 )
{
F_6 ( V_3 , V_21 , V_22 ,
V_22 ) ;
}
static void F_11 ( struct V_2 * V_3 )
{
F_6 ( V_3 , V_21 , V_22 , 0 ) ;
}
static void F_12 ( struct V_2 * V_3 , unsigned int V_23 ,
unsigned int V_24 , unsigned int V_25 ,
unsigned int V_26 )
{
unsigned int V_27 ;
unsigned int V_14 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_6 ( V_3 , V_28 , 0xfff , V_23 ) ;
F_6 ( V_3 , V_29 , 0xfffff , V_24 ) ;
V_27 = V_23 * V_24 * V_25 * 4 * 7 / 1000000 ;
V_14 = V_30 |
F_13 ( F_14 ( V_8 ) ) |
F_15 ( V_27 ) ;
F_4 ( V_14 , V_3 -> V_9 + V_31 ) ;
}
static int F_16 ( struct V_32 * V_33 , struct V_32 * V_34 ,
void * V_35 )
{
struct V_1 * V_7 = F_17 ( V_33 ) ;
struct V_36 * V_37 = V_35 ;
int V_38 ;
V_38 = F_18 ( V_37 , & V_7 -> V_4 ) ;
if ( V_38 < 0 ) {
F_19 ( V_33 , L_1 ,
V_33 -> V_39 -> V_40 , V_38 ) ;
return V_38 ;
}
return 0 ;
}
static void F_20 ( struct V_32 * V_33 , struct V_32 * V_34 ,
void * V_35 )
{
struct V_1 * V_7 = F_17 ( V_33 ) ;
struct V_36 * V_37 = V_35 ;
F_21 ( V_37 , & V_7 -> V_4 ) ;
}
static int F_22 ( struct V_41 * V_42 )
{
struct V_32 * V_33 = & V_42 -> V_33 ;
struct V_1 * V_7 ;
int V_43 ;
int V_5 ;
int V_38 ;
V_7 = F_23 ( V_33 , sizeof( * V_7 ) , V_44 ) ;
if ( ! V_7 )
return - V_45 ;
V_5 = F_24 ( V_42 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_43 = F_25 ( V_33 -> V_39 , V_46 ) ;
if ( V_43 < 0 ) {
F_19 ( V_33 , L_2 , V_43 ) ;
return V_43 ;
}
V_38 = F_26 ( V_33 , V_33 -> V_39 , & V_7 -> V_4 , V_43 ,
& V_47 ) ;
if ( V_38 ) {
F_19 ( V_33 , L_3 , V_38 ) ;
return V_38 ;
}
F_4 ( 0x0 , V_7 -> V_4 . V_9 + V_19 ) ;
F_4 ( 0x0 , V_7 -> V_4 . V_9 + V_10 ) ;
V_38 = F_27 ( V_33 , V_5 , F_3 ,
V_48 , F_28 ( V_33 ) , V_7 ) ;
if ( V_38 < 0 ) {
F_19 ( V_33 , L_4 , V_5 , V_38 ) ;
return V_38 ;
}
V_7 -> V_35 = F_29 ( V_33 ) ;
F_30 ( V_42 , V_7 ) ;
V_38 = F_31 ( V_33 , & V_49 ) ;
if ( V_38 )
F_19 ( V_33 , L_5 , V_38 ) ;
return V_38 ;
}
static int F_32 ( struct V_41 * V_42 )
{
F_33 ( & V_42 -> V_33 , & V_49 ) ;
return 0 ;
}
