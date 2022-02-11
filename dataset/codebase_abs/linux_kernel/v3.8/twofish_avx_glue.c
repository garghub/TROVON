static inline void F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
F_2 ( V_2 , V_3 , V_4 , false ) ;
}
static int F_3 ( struct V_5 * V_6 , struct V_7 * V_3 ,
struct V_7 * V_4 , unsigned int V_8 )
{
return F_4 ( & V_9 , V_6 , V_3 , V_4 , V_8 ) ;
}
static int F_5 ( struct V_5 * V_6 , struct V_7 * V_3 ,
struct V_7 * V_4 , unsigned int V_8 )
{
return F_4 ( & V_10 , V_6 , V_3 , V_4 , V_8 ) ;
}
static int F_6 ( struct V_5 * V_6 , struct V_7 * V_3 ,
struct V_7 * V_4 , unsigned int V_8 )
{
return F_7 ( F_8 ( V_11 ) , V_6 ,
V_3 , V_4 , V_8 ) ;
}
static int F_9 ( struct V_5 * V_6 , struct V_7 * V_3 ,
struct V_7 * V_4 , unsigned int V_8 )
{
return F_10 ( & V_12 , V_6 , V_3 , V_4 ,
V_8 ) ;
}
static int F_11 ( struct V_5 * V_6 , struct V_7 * V_3 ,
struct V_7 * V_4 , unsigned int V_8 )
{
return F_12 ( & V_13 , V_6 , V_3 , V_4 , V_8 ) ;
}
static inline bool F_13 ( bool V_14 , unsigned int V_8 )
{
return F_14 ( V_15 , V_16 , NULL ,
V_14 , V_8 ) ;
}
static inline void F_15 ( bool V_14 )
{
F_16 ( V_14 ) ;
}
static void F_17 ( void * V_17 , T_1 * V_18 , unsigned int V_8 )
{
const unsigned int V_19 = V_15 ;
struct V_20 * V_2 = V_17 ;
int V_21 ;
V_2 -> V_14 = F_13 ( V_2 -> V_14 , V_8 ) ;
if ( V_8 == V_19 * V_16 ) {
F_18 ( V_2 -> V_2 , V_18 , V_18 ) ;
return;
}
for ( V_21 = 0 ; V_21 < V_8 / ( V_19 * 3 ) ; V_21 ++ , V_18 += V_19 * 3 )
F_1 ( V_2 -> V_2 , V_18 , V_18 ) ;
V_8 %= V_19 * 3 ;
for ( V_21 = 0 ; V_21 < V_8 / V_19 ; V_21 ++ , V_18 += V_19 )
V_11 ( V_2 -> V_2 , V_18 , V_18 ) ;
}
static void F_19 ( void * V_17 , T_1 * V_18 , unsigned int V_8 )
{
const unsigned int V_19 = V_15 ;
struct V_20 * V_2 = V_17 ;
int V_21 ;
V_2 -> V_14 = F_13 ( V_2 -> V_14 , V_8 ) ;
if ( V_8 == V_19 * V_16 ) {
F_20 ( V_2 -> V_2 , V_18 , V_18 ) ;
return;
}
for ( V_21 = 0 ; V_21 < V_8 / ( V_19 * 3 ) ; V_21 ++ , V_18 += V_19 * 3 )
F_21 ( V_2 -> V_2 , V_18 , V_18 ) ;
V_8 %= V_19 * 3 ;
for ( V_21 = 0 ; V_21 < V_8 / V_19 ; V_21 ++ , V_18 += V_19 )
F_22 ( V_2 -> V_2 , V_18 , V_18 ) ;
}
static int F_23 ( struct V_5 * V_6 , struct V_7 * V_3 ,
struct V_7 * V_4 , unsigned int V_8 )
{
struct V_22 * V_2 = F_24 ( V_6 -> V_23 ) ;
T_2 V_24 [ V_16 ] ;
struct V_20 V_25 = {
. V_2 = & V_2 -> V_1 ,
. V_14 = false ,
} ;
struct V_26 V_27 = {
. V_28 = V_24 ,
. V_29 = sizeof( V_24 ) ,
. V_30 = & V_2 -> V_31 ,
. V_25 = & V_25 ,
. V_32 = F_17 ,
} ;
int V_33 ;
V_6 -> V_34 &= ~ V_35 ;
V_33 = F_25 ( V_6 , V_3 , V_4 , V_8 , & V_27 ) ;
F_15 ( V_25 . V_14 ) ;
return V_33 ;
}
static int F_26 ( struct V_5 * V_6 , struct V_7 * V_3 ,
struct V_7 * V_4 , unsigned int V_8 )
{
struct V_22 * V_2 = F_24 ( V_6 -> V_23 ) ;
T_2 V_24 [ V_16 ] ;
struct V_20 V_25 = {
. V_2 = & V_2 -> V_1 ,
. V_14 = false ,
} ;
struct V_26 V_27 = {
. V_28 = V_24 ,
. V_29 = sizeof( V_24 ) ,
. V_30 = & V_2 -> V_31 ,
. V_25 = & V_25 ,
. V_32 = F_19 ,
} ;
int V_33 ;
V_6 -> V_34 &= ~ V_35 ;
V_33 = F_25 ( V_6 , V_3 , V_4 , V_8 , & V_27 ) ;
F_15 ( V_25 . V_14 ) ;
return V_33 ;
}
static int F_27 ( struct V_5 * V_6 , struct V_7 * V_3 ,
struct V_7 * V_4 , unsigned int V_8 )
{
struct V_36 * V_2 = F_24 ( V_6 -> V_23 ) ;
T_2 V_24 [ V_16 ] ;
struct V_20 V_25 = {
. V_2 = & V_2 -> V_25 ,
. V_14 = false ,
} ;
struct V_37 V_27 = {
. V_28 = V_24 ,
. V_29 = sizeof( V_24 ) ,
. V_38 = & V_2 -> V_38 ,
. V_39 = F_28 ( V_11 ) ,
. V_25 = & V_25 ,
. V_32 = F_17 ,
} ;
int V_33 ;
V_6 -> V_34 &= ~ V_35 ;
V_33 = F_29 ( V_6 , V_3 , V_4 , V_8 , & V_27 ) ;
F_15 ( V_25 . V_14 ) ;
return V_33 ;
}
static int F_30 ( struct V_5 * V_6 , struct V_7 * V_3 ,
struct V_7 * V_4 , unsigned int V_8 )
{
struct V_36 * V_2 = F_24 ( V_6 -> V_23 ) ;
T_2 V_24 [ V_16 ] ;
struct V_20 V_25 = {
. V_2 = & V_2 -> V_25 ,
. V_14 = false ,
} ;
struct V_37 V_27 = {
. V_28 = V_24 ,
. V_29 = sizeof( V_24 ) ,
. V_38 = & V_2 -> V_38 ,
. V_39 = F_28 ( V_11 ) ,
. V_25 = & V_25 ,
. V_32 = F_19 ,
} ;
int V_33 ;
V_6 -> V_34 &= ~ V_35 ;
V_33 = F_29 ( V_6 , V_3 , V_4 , V_8 , & V_27 ) ;
F_15 ( V_25 . V_14 ) ;
return V_33 ;
}
static int T_3 F_31 ( void )
{
T_4 V_40 ;
if ( ! V_41 || ! V_42 ) {
F_32 ( V_43 L_1 ) ;
return - V_44 ;
}
V_40 = F_33 ( V_45 ) ;
if ( ( V_40 & ( V_46 | V_47 ) ) != ( V_46 | V_47 ) ) {
F_32 ( V_43 L_2 ) ;
return - V_44 ;
}
return F_34 ( V_48 , F_35 ( V_48 ) ) ;
}
static void T_5 F_36 ( void )
{
F_37 ( V_48 , F_35 ( V_48 ) ) ;
}
