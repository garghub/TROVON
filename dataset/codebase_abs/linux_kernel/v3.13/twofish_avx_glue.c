static inline void F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
F_2 ( V_2 , V_3 , V_4 , false ) ;
}
static void F_3 ( void * V_2 , T_2 * V_3 , const T_2 * V_4 , T_3 * V_5 )
{
F_4 ( V_2 , V_3 , V_4 , V_5 ,
F_5 ( V_6 ) ) ;
}
static void F_6 ( void * V_2 , T_2 * V_3 , const T_2 * V_4 , T_3 * V_5 )
{
F_4 ( V_2 , V_3 , V_4 , V_5 ,
F_5 ( V_7 ) ) ;
}
static int F_7 ( struct V_8 * V_9 , struct V_10 * V_3 ,
struct V_10 * V_4 , unsigned int V_11 )
{
return F_8 ( & V_12 , V_9 , V_3 , V_4 , V_11 ) ;
}
static int F_9 ( struct V_8 * V_9 , struct V_10 * V_3 ,
struct V_10 * V_4 , unsigned int V_11 )
{
return F_8 ( & V_13 , V_9 , V_3 , V_4 , V_11 ) ;
}
static int F_10 ( struct V_8 * V_9 , struct V_10 * V_3 ,
struct V_10 * V_4 , unsigned int V_11 )
{
return F_11 ( F_5 ( V_6 ) , V_9 ,
V_3 , V_4 , V_11 ) ;
}
static int F_12 ( struct V_8 * V_9 , struct V_10 * V_3 ,
struct V_10 * V_4 , unsigned int V_11 )
{
return F_13 ( & V_14 , V_9 , V_3 , V_4 ,
V_11 ) ;
}
static int F_14 ( struct V_8 * V_9 , struct V_10 * V_3 ,
struct V_10 * V_4 , unsigned int V_11 )
{
return F_15 ( & V_15 , V_9 , V_3 , V_4 , V_11 ) ;
}
static inline bool F_16 ( bool V_16 , unsigned int V_11 )
{
return F_17 ( V_17 , V_18 , NULL ,
V_16 , V_11 ) ;
}
static inline void F_18 ( bool V_16 )
{
F_19 ( V_16 ) ;
}
static void F_20 ( void * V_19 , T_1 * V_20 , unsigned int V_11 )
{
const unsigned int V_21 = V_17 ;
struct V_22 * V_2 = V_19 ;
int V_23 ;
V_2 -> V_16 = F_16 ( V_2 -> V_16 , V_11 ) ;
if ( V_11 == V_21 * V_18 ) {
F_21 ( V_2 -> V_2 , V_20 , V_20 ) ;
return;
}
for ( V_23 = 0 ; V_23 < V_11 / ( V_21 * 3 ) ; V_23 ++ , V_20 += V_21 * 3 )
F_1 ( V_2 -> V_2 , V_20 , V_20 ) ;
V_11 %= V_21 * 3 ;
for ( V_23 = 0 ; V_23 < V_11 / V_21 ; V_23 ++ , V_20 += V_21 )
V_6 ( V_2 -> V_2 , V_20 , V_20 ) ;
}
static void F_22 ( void * V_19 , T_1 * V_20 , unsigned int V_11 )
{
const unsigned int V_21 = V_17 ;
struct V_22 * V_2 = V_19 ;
int V_23 ;
V_2 -> V_16 = F_16 ( V_2 -> V_16 , V_11 ) ;
if ( V_11 == V_21 * V_18 ) {
F_23 ( V_2 -> V_2 , V_20 , V_20 ) ;
return;
}
for ( V_23 = 0 ; V_23 < V_11 / ( V_21 * 3 ) ; V_23 ++ , V_20 += V_21 * 3 )
F_24 ( V_2 -> V_2 , V_20 , V_20 ) ;
V_11 %= V_21 * 3 ;
for ( V_23 = 0 ; V_23 < V_11 / V_21 ; V_23 ++ , V_20 += V_21 )
V_7 ( V_2 -> V_2 , V_20 , V_20 ) ;
}
static int F_25 ( struct V_8 * V_9 , struct V_10 * V_3 ,
struct V_10 * V_4 , unsigned int V_11 )
{
struct V_24 * V_2 = F_26 ( V_9 -> V_25 ) ;
T_4 V_26 [ V_18 ] ;
struct V_22 V_27 = {
. V_2 = & V_2 -> V_1 ,
. V_16 = false ,
} ;
struct V_28 V_29 = {
. V_30 = V_26 ,
. V_31 = sizeof( V_26 ) ,
. V_32 = & V_2 -> V_33 ,
. V_27 = & V_27 ,
. V_34 = F_20 ,
} ;
int V_35 ;
V_9 -> V_36 &= ~ V_37 ;
V_35 = F_27 ( V_9 , V_3 , V_4 , V_11 , & V_29 ) ;
F_18 ( V_27 . V_16 ) ;
return V_35 ;
}
static int F_28 ( struct V_8 * V_9 , struct V_10 * V_3 ,
struct V_10 * V_4 , unsigned int V_11 )
{
struct V_24 * V_2 = F_26 ( V_9 -> V_25 ) ;
T_4 V_26 [ V_18 ] ;
struct V_22 V_27 = {
. V_2 = & V_2 -> V_1 ,
. V_16 = false ,
} ;
struct V_28 V_29 = {
. V_30 = V_26 ,
. V_31 = sizeof( V_26 ) ,
. V_32 = & V_2 -> V_33 ,
. V_27 = & V_27 ,
. V_34 = F_22 ,
} ;
int V_35 ;
V_9 -> V_36 &= ~ V_37 ;
V_35 = F_27 ( V_9 , V_3 , V_4 , V_11 , & V_29 ) ;
F_18 ( V_27 . V_16 ) ;
return V_35 ;
}
static int F_29 ( struct V_8 * V_9 , struct V_10 * V_3 ,
struct V_10 * V_4 , unsigned int V_11 )
{
struct V_38 * V_2 = F_26 ( V_9 -> V_25 ) ;
return F_30 ( & V_39 , V_9 , V_3 , V_4 , V_11 ,
F_31 ( V_6 ) ,
& V_2 -> V_40 , & V_2 -> V_27 ) ;
}
static int F_32 ( struct V_8 * V_9 , struct V_10 * V_3 ,
struct V_10 * V_4 , unsigned int V_11 )
{
struct V_38 * V_2 = F_26 ( V_9 -> V_25 ) ;
return F_30 ( & V_41 , V_9 , V_3 , V_4 , V_11 ,
F_31 ( V_6 ) ,
& V_2 -> V_40 , & V_2 -> V_27 ) ;
}
static int T_5 F_33 ( void )
{
T_6 V_42 ;
if ( ! V_43 || ! V_44 ) {
F_34 ( V_45 L_1 ) ;
return - V_46 ;
}
V_42 = F_35 ( V_47 ) ;
if ( ( V_42 & ( V_48 | V_49 ) ) != ( V_48 | V_49 ) ) {
F_34 ( V_45 L_2 ) ;
return - V_46 ;
}
return F_36 ( V_50 , F_37 ( V_50 ) ) ;
}
static void T_7 F_38 ( void )
{
F_39 ( V_50 , F_37 ( V_50 ) ) ;
}
