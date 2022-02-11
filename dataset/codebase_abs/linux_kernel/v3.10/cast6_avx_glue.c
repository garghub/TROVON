static void F_1 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
F_2 ( V_1 , V_2 , V_3 , V_4 ,
F_3 ( V_5 ) ) ;
}
static void F_4 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
F_2 ( V_1 , V_2 , V_3 , V_4 ,
F_3 ( V_6 ) ) ;
}
static void F_5 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
T_3 V_7 ;
F_6 ( & V_7 , V_4 ) ;
F_7 ( V_4 ) ;
V_5 ( V_1 , ( V_8 * ) & V_7 , ( V_8 * ) & V_7 ) ;
F_8 ( V_2 , V_3 , ( T_1 * ) & V_7 ) ;
}
static int F_9 ( struct V_9 * V_10 , struct V_11 * V_2 ,
struct V_11 * V_3 , unsigned int V_12 )
{
return F_10 ( & V_13 , V_10 , V_2 , V_3 , V_12 ) ;
}
static int F_11 ( struct V_9 * V_10 , struct V_11 * V_2 ,
struct V_11 * V_3 , unsigned int V_12 )
{
return F_10 ( & V_14 , V_10 , V_2 , V_3 , V_12 ) ;
}
static int F_12 ( struct V_9 * V_10 , struct V_11 * V_2 ,
struct V_11 * V_3 , unsigned int V_12 )
{
return F_13 ( F_3 ( V_5 ) , V_10 ,
V_2 , V_3 , V_12 ) ;
}
static int F_14 ( struct V_9 * V_10 , struct V_11 * V_2 ,
struct V_11 * V_3 , unsigned int V_12 )
{
return F_15 ( & V_15 , V_10 , V_2 , V_3 ,
V_12 ) ;
}
static int F_16 ( struct V_9 * V_10 , struct V_11 * V_2 ,
struct V_11 * V_3 , unsigned int V_12 )
{
return F_17 ( & V_16 , V_10 , V_2 , V_3 , V_12 ) ;
}
static inline bool F_18 ( bool V_17 , unsigned int V_12 )
{
return F_19 ( V_18 , V_19 ,
NULL , V_17 , V_12 ) ;
}
static inline void F_20 ( bool V_17 )
{
F_21 ( V_17 ) ;
}
static void F_22 ( void * V_20 , V_8 * V_21 , unsigned int V_12 )
{
const unsigned int V_22 = V_18 ;
struct V_23 * V_1 = V_20 ;
int V_24 ;
V_1 -> V_17 = F_18 ( V_1 -> V_17 , V_12 ) ;
if ( V_12 == V_22 * V_19 ) {
F_23 ( V_1 -> V_1 , V_21 , V_21 ) ;
return;
}
for ( V_24 = 0 ; V_24 < V_12 / V_22 ; V_24 ++ , V_21 += V_22 )
V_5 ( V_1 -> V_1 , V_21 , V_21 ) ;
}
static void F_24 ( void * V_20 , V_8 * V_21 , unsigned int V_12 )
{
const unsigned int V_22 = V_18 ;
struct V_23 * V_1 = V_20 ;
int V_24 ;
V_1 -> V_17 = F_18 ( V_1 -> V_17 , V_12 ) ;
if ( V_12 == V_22 * V_19 ) {
F_25 ( V_1 -> V_1 , V_21 , V_21 ) ;
return;
}
for ( V_24 = 0 ; V_24 < V_12 / V_22 ; V_24 ++ , V_21 += V_22 )
V_6 ( V_1 -> V_1 , V_21 , V_21 ) ;
}
static int F_26 ( struct V_25 * V_26 , const V_8 * V_27 ,
unsigned int V_28 )
{
struct V_29 * V_1 = F_27 ( V_26 ) ;
int V_30 ;
V_30 = F_28 ( & V_1 -> V_31 , V_27 , V_28 - V_18 ,
& V_26 -> V_32 ) ;
if ( V_30 )
return V_30 ;
return F_29 ( & V_1 -> V_33 , V_27 + V_28 - V_18 ) ;
}
static int F_30 ( struct V_9 * V_10 , struct V_11 * V_2 ,
struct V_11 * V_3 , unsigned int V_12 )
{
struct V_29 * V_1 = F_31 ( V_10 -> V_26 ) ;
T_3 V_34 [ V_19 ] ;
struct V_23 V_35 = {
. V_1 = & V_1 -> V_31 ,
. V_17 = false ,
} ;
struct V_36 V_37 = {
. V_38 = V_34 ,
. V_39 = sizeof( V_34 ) ,
. V_40 = & V_1 -> V_33 ,
. V_35 = & V_35 ,
. V_41 = F_22 ,
} ;
int V_42 ;
V_10 -> V_43 &= ~ V_44 ;
V_42 = F_32 ( V_10 , V_2 , V_3 , V_12 , & V_37 ) ;
F_20 ( V_35 . V_17 ) ;
return V_42 ;
}
static int F_33 ( struct V_9 * V_10 , struct V_11 * V_2 ,
struct V_11 * V_3 , unsigned int V_12 )
{
struct V_29 * V_1 = F_31 ( V_10 -> V_26 ) ;
T_3 V_34 [ V_19 ] ;
struct V_23 V_35 = {
. V_1 = & V_1 -> V_31 ,
. V_17 = false ,
} ;
struct V_36 V_37 = {
. V_38 = V_34 ,
. V_39 = sizeof( V_34 ) ,
. V_40 = & V_1 -> V_33 ,
. V_35 = & V_35 ,
. V_41 = F_24 ,
} ;
int V_42 ;
V_10 -> V_43 &= ~ V_44 ;
V_42 = F_32 ( V_10 , V_2 , V_3 , V_12 , & V_37 ) ;
F_20 ( V_35 . V_17 ) ;
return V_42 ;
}
static void F_34 ( struct V_25 * V_26 )
{
struct V_29 * V_1 = F_27 ( V_26 ) ;
F_35 ( & V_1 -> V_33 ) ;
}
static int F_36 ( struct V_25 * V_26 , const V_8 * V_27 ,
unsigned int V_28 )
{
struct V_45 * V_1 = F_27 ( V_26 ) ;
T_4 * V_43 = & V_26 -> V_32 ;
int V_30 ;
if ( V_28 % 2 ) {
* V_43 |= V_46 ;
return - V_47 ;
}
V_30 = F_28 ( & V_1 -> V_35 , V_27 , V_28 / 2 , V_43 ) ;
if ( V_30 )
return V_30 ;
return F_28 ( & V_1 -> V_48 , V_27 + V_28 / 2 , V_28 / 2 ,
V_43 ) ;
}
static int F_37 ( struct V_9 * V_10 , struct V_11 * V_2 ,
struct V_11 * V_3 , unsigned int V_12 )
{
struct V_45 * V_1 = F_31 ( V_10 -> V_26 ) ;
return F_38 ( & V_49 , V_10 , V_2 , V_3 , V_12 ,
F_39 ( V_5 ) ,
& V_1 -> V_48 , & V_1 -> V_35 ) ;
}
static int F_40 ( struct V_9 * V_10 , struct V_11 * V_2 ,
struct V_11 * V_3 , unsigned int V_12 )
{
struct V_45 * V_1 = F_31 ( V_10 -> V_26 ) ;
return F_38 ( & V_50 , V_10 , V_2 , V_3 , V_12 ,
F_39 ( V_5 ) ,
& V_1 -> V_48 , & V_1 -> V_35 ) ;
}
static int T_5 F_41 ( void )
{
T_6 V_51 ;
if ( ! V_52 || ! V_53 ) {
F_42 ( L_1 ) ;
return - V_54 ;
}
V_51 = F_43 ( V_55 ) ;
if ( ( V_51 & ( V_56 | V_57 ) ) != ( V_56 | V_57 ) ) {
F_42 ( L_2 ) ;
return - V_54 ;
}
return F_44 ( V_58 , F_45 ( V_58 ) ) ;
}
static void T_7 F_46 ( void )
{
F_47 ( V_58 , F_45 ( V_58 ) ) ;
}
