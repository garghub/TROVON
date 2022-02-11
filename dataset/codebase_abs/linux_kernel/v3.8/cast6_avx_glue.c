static void F_1 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
T_3 V_5 ;
F_2 ( & V_5 , V_4 ) ;
F_3 ( V_4 ) ;
F_4 ( V_1 , ( V_6 * ) & V_5 , ( V_6 * ) & V_5 ) ;
F_5 ( V_2 , V_3 , ( T_1 * ) & V_5 ) ;
}
static int F_6 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
return F_7 ( & V_11 , V_8 , V_2 , V_3 , V_10 ) ;
}
static int F_8 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
return F_7 ( & V_12 , V_8 , V_2 , V_3 , V_10 ) ;
}
static int F_9 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
return F_10 ( F_11 ( F_4 ) , V_8 ,
V_2 , V_3 , V_10 ) ;
}
static int F_12 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
return F_13 ( & V_13 , V_8 , V_2 , V_3 ,
V_10 ) ;
}
static int F_14 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
return F_15 ( & V_14 , V_8 , V_2 , V_3 , V_10 ) ;
}
static inline bool F_16 ( bool V_15 , unsigned int V_10 )
{
return F_17 ( V_16 , V_17 ,
NULL , V_15 , V_10 ) ;
}
static inline void F_18 ( bool V_15 )
{
F_19 ( V_15 ) ;
}
static void F_20 ( void * V_18 , V_6 * V_19 , unsigned int V_10 )
{
const unsigned int V_20 = V_16 ;
struct V_21 * V_1 = V_18 ;
int V_22 ;
V_1 -> V_15 = F_16 ( V_1 -> V_15 , V_10 ) ;
if ( V_10 == V_20 * V_17 ) {
F_21 ( V_1 -> V_1 , V_19 , V_19 ) ;
return;
}
for ( V_22 = 0 ; V_22 < V_10 / V_20 ; V_22 ++ , V_19 += V_20 )
F_4 ( V_1 -> V_1 , V_19 , V_19 ) ;
}
static void F_22 ( void * V_18 , V_6 * V_19 , unsigned int V_10 )
{
const unsigned int V_20 = V_16 ;
struct V_21 * V_1 = V_18 ;
int V_22 ;
V_1 -> V_15 = F_16 ( V_1 -> V_15 , V_10 ) ;
if ( V_10 == V_20 * V_17 ) {
F_23 ( V_1 -> V_1 , V_19 , V_19 ) ;
return;
}
for ( V_22 = 0 ; V_22 < V_10 / V_20 ; V_22 ++ , V_19 += V_20 )
F_24 ( V_1 -> V_1 , V_19 , V_19 ) ;
}
static int F_25 ( struct V_23 * V_24 , const V_6 * V_25 ,
unsigned int V_26 )
{
struct V_27 * V_1 = F_26 ( V_24 ) ;
int V_28 ;
V_28 = F_27 ( & V_1 -> V_29 , V_25 , V_26 - V_16 ,
& V_24 -> V_30 ) ;
if ( V_28 )
return V_28 ;
return F_28 ( & V_1 -> V_31 , V_25 + V_26 - V_16 ) ;
}
static int F_29 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
struct V_27 * V_1 = F_30 ( V_8 -> V_24 ) ;
T_3 V_32 [ V_17 ] ;
struct V_21 V_33 = {
. V_1 = & V_1 -> V_29 ,
. V_15 = false ,
} ;
struct V_34 V_35 = {
. V_36 = V_32 ,
. V_37 = sizeof( V_32 ) ,
. V_38 = & V_1 -> V_31 ,
. V_33 = & V_33 ,
. V_39 = F_20 ,
} ;
int V_40 ;
V_8 -> V_41 &= ~ V_42 ;
V_40 = F_31 ( V_8 , V_2 , V_3 , V_10 , & V_35 ) ;
F_18 ( V_33 . V_15 ) ;
return V_40 ;
}
static int F_32 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
struct V_27 * V_1 = F_30 ( V_8 -> V_24 ) ;
T_3 V_32 [ V_17 ] ;
struct V_21 V_33 = {
. V_1 = & V_1 -> V_29 ,
. V_15 = false ,
} ;
struct V_34 V_35 = {
. V_36 = V_32 ,
. V_37 = sizeof( V_32 ) ,
. V_38 = & V_1 -> V_31 ,
. V_33 = & V_33 ,
. V_39 = F_22 ,
} ;
int V_40 ;
V_8 -> V_41 &= ~ V_42 ;
V_40 = F_31 ( V_8 , V_2 , V_3 , V_10 , & V_35 ) ;
F_18 ( V_33 . V_15 ) ;
return V_40 ;
}
static void F_33 ( struct V_23 * V_24 )
{
struct V_27 * V_1 = F_26 ( V_24 ) ;
F_34 ( & V_1 -> V_31 ) ;
}
static int F_35 ( struct V_23 * V_24 , const V_6 * V_25 ,
unsigned int V_26 )
{
struct V_43 * V_1 = F_26 ( V_24 ) ;
T_4 * V_41 = & V_24 -> V_30 ;
int V_28 ;
if ( V_26 % 2 ) {
* V_41 |= V_44 ;
return - V_45 ;
}
V_28 = F_27 ( & V_1 -> V_33 , V_25 , V_26 / 2 , V_41 ) ;
if ( V_28 )
return V_28 ;
return F_27 ( & V_1 -> V_46 , V_25 + V_26 / 2 , V_26 / 2 ,
V_41 ) ;
}
static int F_36 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
struct V_43 * V_1 = F_30 ( V_8 -> V_24 ) ;
T_3 V_32 [ V_17 ] ;
struct V_21 V_33 = {
. V_1 = & V_1 -> V_33 ,
. V_15 = false ,
} ;
struct V_47 V_35 = {
. V_36 = V_32 ,
. V_37 = sizeof( V_32 ) ,
. V_46 = & V_1 -> V_46 ,
. V_48 = F_37 ( F_4 ) ,
. V_33 = & V_33 ,
. V_39 = F_20 ,
} ;
int V_40 ;
V_8 -> V_41 &= ~ V_42 ;
V_40 = F_38 ( V_8 , V_2 , V_3 , V_10 , & V_35 ) ;
F_18 ( V_33 . V_15 ) ;
return V_40 ;
}
static int F_39 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
struct V_43 * V_1 = F_30 ( V_8 -> V_24 ) ;
T_3 V_32 [ V_17 ] ;
struct V_21 V_33 = {
. V_1 = & V_1 -> V_33 ,
. V_15 = false ,
} ;
struct V_47 V_35 = {
. V_36 = V_32 ,
. V_37 = sizeof( V_32 ) ,
. V_46 = & V_1 -> V_46 ,
. V_48 = F_37 ( F_4 ) ,
. V_33 = & V_33 ,
. V_39 = F_22 ,
} ;
int V_40 ;
V_8 -> V_41 &= ~ V_42 ;
V_40 = F_38 ( V_8 , V_2 , V_3 , V_10 , & V_35 ) ;
F_18 ( V_33 . V_15 ) ;
return V_40 ;
}
static int T_5 F_40 ( void )
{
T_6 V_49 ;
if ( ! V_50 || ! V_51 ) {
F_41 ( L_1 ) ;
return - V_52 ;
}
V_49 = F_42 ( V_53 ) ;
if ( ( V_49 & ( V_54 | V_55 ) ) != ( V_54 | V_55 ) ) {
F_41 ( L_2 ) ;
return - V_52 ;
}
return F_43 ( V_56 , F_44 ( V_56 ) ) ;
}
static void T_7 F_45 ( void )
{
F_46 ( V_56 , F_44 ( V_56 ) ) ;
}
