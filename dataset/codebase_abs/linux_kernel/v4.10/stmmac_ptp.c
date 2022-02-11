static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_6 ) ;
unsigned long V_7 ;
T_2 V_8 , V_9 ;
int V_10 = 0 ;
T_3 V_11 ;
if ( V_3 < 0 ) {
V_10 = 1 ;
V_3 = - V_3 ;
}
V_9 = V_5 -> V_12 ;
V_11 = V_9 ;
V_11 *= V_3 ;
V_8 = F_3 ( V_11 , 1000000000ULL ) ;
V_9 = V_10 ? ( V_9 - V_8 ) : ( V_9 + V_8 ) ;
F_4 ( & V_5 -> V_13 , V_7 ) ;
V_5 -> V_14 -> V_2 -> V_15 ( V_5 -> V_16 , V_9 ) ;
F_5 ( & V_5 -> V_13 , V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_4 V_17 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_6 ) ;
unsigned long V_7 ;
T_2 V_18 , V_19 ;
T_2 V_20 , V_21 ;
int V_10 = 0 ;
if ( V_17 < 0 ) {
V_10 = 1 ;
V_17 = - V_17 ;
}
V_20 = F_7 ( V_17 , 1000000000ULL , & V_21 ) ;
V_18 = V_20 ;
V_19 = V_21 ;
F_4 ( & V_5 -> V_13 , V_7 ) ;
V_5 -> V_14 -> V_2 -> V_22 ( V_5 -> V_16 , V_18 , V_19 , V_10 ,
V_5 -> V_23 -> V_24 ) ;
F_5 ( & V_5 -> V_13 , V_7 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_6 ) ;
unsigned long V_7 ;
T_3 V_27 ;
F_4 ( & V_5 -> V_13 , V_7 ) ;
V_27 = V_5 -> V_14 -> V_2 -> V_28 ( V_5 -> V_16 ) ;
F_5 ( & V_5 -> V_13 , V_7 ) ;
* V_26 = F_9 ( V_27 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_25 * V_26 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_6 ) ;
unsigned long V_7 ;
F_4 ( & V_5 -> V_13 , V_7 ) ;
V_5 -> V_14 -> V_2 -> V_29 ( V_5 -> V_16 , V_26 -> V_30 , V_26 -> V_31 ) ;
F_5 ( & V_5 -> V_13 , V_7 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_32 * V_33 , int V_34 )
{
return - V_35 ;
}
void F_12 ( struct V_4 * V_5 )
{
F_13 ( & V_5 -> V_13 ) ;
V_5 -> V_6 = V_36 ;
V_5 -> V_37 = F_14 ( & V_5 -> V_6 ,
V_5 -> V_38 ) ;
if ( F_15 ( V_5 -> V_37 ) ) {
F_16 ( V_5 -> V_39 , L_1 ) ;
V_5 -> V_37 = NULL ;
} else if ( V_5 -> V_37 )
F_17 ( V_5 -> V_39 , L_2 ) ;
}
void F_18 ( struct V_4 * V_5 )
{
if ( V_5 -> V_37 ) {
F_19 ( V_5 -> V_37 ) ;
V_5 -> V_37 = NULL ;
F_20 ( L_3 ,
V_5 -> V_39 -> V_40 ) ;
}
}
