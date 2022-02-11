static void F_1 ( struct V_1 * V_2 )
{
const unsigned int V_3 = 147 ;
unsigned int V_4 ;
V_4 = F_2 ( F_3 () , V_2 -> V_5 ) ;
if ( V_4 < V_3 )
F_4 ( V_3 - V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , int * V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_9 = 0 ;
int V_10 ;
F_1 ( V_2 ) ;
V_10 = F_6 ( V_8 , ( char * ) & V_9 , 4 ) ;
if ( V_10 < 0 ) {
F_7 ( & V_8 -> V_11 , L_1 ) ;
return V_10 ;
}
V_2 -> V_5 = F_3 () ;
* V_6 = F_8 ( F_9 ( V_9 ) >> 6 , 24 ) ;
return V_10 ;
}
static int F_10 ( struct V_12 * V_13 ,
struct V_14 const * V_15 ,
int * V_6 , int * V_16 , long V_17 )
{
struct V_1 * V_2 = F_11 ( V_13 ) ;
int V_10 ;
if ( V_17 == V_18 ) {
V_10 = F_5 ( V_2 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_19 ;
} else if ( V_17 == V_20 ) {
* V_6 = 5000 ;
* V_16 = 25 ;
return V_21 ;
} else {
return - V_22 ;
}
}
static int F_12 ( struct V_7 * V_8 ,
const struct V_23 * V_24 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_10 ;
if ( ! F_13 ( V_8 -> V_25 , V_26 |
V_27 ) )
return - V_28 ;
V_13 = F_14 ( & V_8 -> V_11 , sizeof( * V_2 ) ) ;
if ( ! V_13 )
return - V_29 ;
V_2 = F_11 ( V_13 ) ;
F_15 ( V_8 , V_13 ) ;
V_2 -> V_8 = V_8 ;
V_13 -> V_11 . V_30 = & V_8 -> V_11 ;
V_13 -> V_31 = V_24 -> V_31 ;
V_13 -> V_32 = & V_33 ;
V_13 -> V_34 = V_35 ;
V_13 -> V_36 = V_37 ;
V_13 -> V_38 = F_16 ( V_37 ) ;
V_10 = F_17 ( V_2 -> V_8 , V_39 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_5 = F_3 () ;
return F_18 ( & V_8 -> V_11 , V_13 ) ;
}
