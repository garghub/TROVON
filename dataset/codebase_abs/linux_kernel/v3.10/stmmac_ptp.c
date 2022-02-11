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
F_5 ( & V_5 -> V_17 , V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_4 V_18 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_6 ) ;
unsigned long V_7 ;
T_2 V_19 , V_20 ;
T_2 V_21 , V_22 ;
int V_10 = 0 ;
if ( V_18 < 0 ) {
V_10 = 1 ;
V_18 = - V_18 ;
}
V_21 = F_7 ( V_18 , 1000000000ULL , & V_22 ) ;
V_19 = V_21 ;
V_20 = V_22 ;
F_4 ( & V_5 -> V_13 , V_7 ) ;
V_5 -> V_14 -> V_2 -> V_23 ( V_5 -> V_16 , V_19 , V_20 , V_10 ) ;
F_5 ( & V_5 -> V_17 , V_7 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_6 ) ;
unsigned long V_7 ;
T_3 V_26 ;
T_2 V_22 ;
F_4 ( & V_5 -> V_13 , V_7 ) ;
V_26 = V_5 -> V_14 -> V_2 -> V_27 ( V_5 -> V_16 ) ;
F_5 ( & V_5 -> V_13 , V_7 ) ;
V_25 -> V_28 = F_7 ( V_26 , 1000000000ULL , & V_22 ) ;
V_25 -> V_29 = V_22 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_6 ) ;
unsigned long V_7 ;
F_4 ( & V_5 -> V_13 , V_7 ) ;
V_5 -> V_14 -> V_2 -> V_30 ( V_5 -> V_16 , V_25 -> V_28 , V_25 -> V_29 ) ;
F_5 ( & V_5 -> V_13 , V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_31 * V_32 , int V_33 )
{
return - V_34 ;
}
int F_11 ( struct V_4 * V_5 )
{
F_12 ( & V_5 -> V_13 ) ;
V_5 -> V_6 = V_35 ;
V_5 -> V_36 = F_13 ( & V_5 -> V_6 ,
V_5 -> V_37 ) ;
if ( F_14 ( V_5 -> V_36 ) ) {
V_5 -> V_36 = NULL ;
F_15 ( L_1 , V_5 -> V_38 -> V_39 ) ;
} else
F_16 ( L_2 ,
V_5 -> V_38 -> V_39 ) ;
return 0 ;
}
void F_17 ( struct V_4 * V_5 )
{
if ( V_5 -> V_36 ) {
F_18 ( V_5 -> V_36 ) ;
F_16 ( L_3 ,
V_5 -> V_38 -> V_39 ) ;
}
}
