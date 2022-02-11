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
V_5 -> V_14 -> V_2 -> V_22 ( V_5 -> V_16 , V_18 , V_19 , V_10 ) ;
F_5 ( & V_5 -> V_13 , V_7 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_6 ) ;
unsigned long V_7 ;
T_3 V_25 ;
F_4 ( & V_5 -> V_13 , V_7 ) ;
V_25 = V_5 -> V_14 -> V_2 -> V_26 ( V_5 -> V_16 ) ;
F_5 ( & V_5 -> V_13 , V_7 ) ;
* V_24 = F_9 ( V_25 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_6 ) ;
unsigned long V_7 ;
F_4 ( & V_5 -> V_13 , V_7 ) ;
V_5 -> V_14 -> V_2 -> V_27 ( V_5 -> V_16 , V_24 -> V_28 , V_24 -> V_29 ) ;
F_5 ( & V_5 -> V_13 , V_7 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_30 * V_31 , int V_32 )
{
return - V_33 ;
}
int F_12 ( struct V_4 * V_5 )
{
F_13 ( & V_5 -> V_13 ) ;
V_5 -> V_6 = V_34 ;
V_5 -> V_35 = F_14 ( & V_5 -> V_6 ,
V_5 -> V_36 ) ;
if ( F_15 ( V_5 -> V_35 ) ) {
V_5 -> V_35 = NULL ;
F_16 ( L_1 , V_5 -> V_37 -> V_38 ) ;
} else
F_17 ( L_2 ,
V_5 -> V_37 -> V_38 ) ;
return 0 ;
}
void F_18 ( struct V_4 * V_5 )
{
if ( V_5 -> V_35 ) {
F_19 ( V_5 -> V_35 ) ;
V_5 -> V_35 = NULL ;
F_17 ( L_3 ,
V_5 -> V_37 -> V_38 ) ;
}
}
