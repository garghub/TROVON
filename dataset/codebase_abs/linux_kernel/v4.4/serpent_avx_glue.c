void F_1 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
T_3 V_5 ;
F_2 ( & V_5 , V_4 ) ;
F_3 ( V_4 ) ;
F_4 ( V_1 , ( V_6 * ) & V_5 , ( V_6 * ) & V_5 ) ;
F_5 ( V_2 , V_3 , ( T_1 * ) & V_5 ) ;
}
void F_6 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
F_7 ( V_1 , V_2 , V_3 , V_4 ,
F_8 ( F_4 ) ) ;
}
void F_9 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
F_7 ( V_1 , V_2 , V_3 , V_4 ,
F_8 ( V_7 ) ) ;
}
static int F_10 ( struct V_8 * V_9 , struct V_10 * V_2 ,
struct V_10 * V_3 , unsigned int V_11 )
{
return F_11 ( & V_12 , V_9 , V_2 , V_3 , V_11 ) ;
}
static int F_12 ( struct V_8 * V_9 , struct V_10 * V_2 ,
struct V_10 * V_3 , unsigned int V_11 )
{
return F_11 ( & V_13 , V_9 , V_2 , V_3 , V_11 ) ;
}
static int F_13 ( struct V_8 * V_9 , struct V_10 * V_2 ,
struct V_10 * V_3 , unsigned int V_11 )
{
return F_14 ( F_8 ( F_4 ) , V_9 ,
V_2 , V_3 , V_11 ) ;
}
static int F_15 ( struct V_8 * V_9 , struct V_10 * V_2 ,
struct V_10 * V_3 , unsigned int V_11 )
{
return F_16 ( & V_14 , V_9 , V_2 , V_3 ,
V_11 ) ;
}
static int F_17 ( struct V_8 * V_9 , struct V_10 * V_2 ,
struct V_10 * V_3 , unsigned int V_11 )
{
return F_18 ( & V_15 , V_9 , V_2 , V_3 , V_11 ) ;
}
static inline bool F_19 ( bool V_16 , unsigned int V_11 )
{
return F_20 ( V_17 , V_18 ,
NULL , V_16 , V_11 ) ;
}
static inline void F_21 ( bool V_16 )
{
F_22 ( V_16 ) ;
}
static void F_23 ( void * V_19 , V_6 * V_20 , unsigned int V_11 )
{
const unsigned int V_21 = V_17 ;
struct V_22 * V_1 = V_19 ;
int V_23 ;
V_1 -> V_16 = F_19 ( V_1 -> V_16 , V_11 ) ;
if ( V_11 == V_21 * V_18 ) {
F_24 ( V_1 -> V_1 , V_20 , V_20 ) ;
return;
}
for ( V_23 = 0 ; V_23 < V_11 / V_21 ; V_23 ++ , V_20 += V_21 )
F_4 ( V_1 -> V_1 , V_20 , V_20 ) ;
}
static void F_25 ( void * V_19 , V_6 * V_20 , unsigned int V_11 )
{
const unsigned int V_21 = V_17 ;
struct V_22 * V_1 = V_19 ;
int V_23 ;
V_1 -> V_16 = F_19 ( V_1 -> V_16 , V_11 ) ;
if ( V_11 == V_21 * V_18 ) {
F_26 ( V_1 -> V_1 , V_20 , V_20 ) ;
return;
}
for ( V_23 = 0 ; V_23 < V_11 / V_21 ; V_23 ++ , V_20 += V_21 )
V_7 ( V_1 -> V_1 , V_20 , V_20 ) ;
}
int F_27 ( struct V_24 * V_25 , const V_6 * V_26 ,
unsigned int V_27 )
{
struct V_28 * V_1 = F_28 ( V_25 ) ;
int V_29 ;
V_29 = F_29 ( & V_1 -> V_30 , V_26 , V_27 -
V_17 ) ;
if ( V_29 )
return V_29 ;
return F_30 ( & V_1 -> V_31 , V_26 + V_27 -
V_17 ) ;
}
static int F_31 ( struct V_8 * V_9 , struct V_10 * V_2 ,
struct V_10 * V_3 , unsigned int V_11 )
{
struct V_28 * V_1 = F_32 ( V_9 -> V_25 ) ;
T_3 V_32 [ V_18 ] ;
struct V_22 V_33 = {
. V_1 = & V_1 -> V_30 ,
. V_16 = false ,
} ;
struct V_34 V_35 = {
. V_36 = V_32 ,
. V_37 = sizeof( V_32 ) ,
. V_38 = & V_1 -> V_31 ,
. V_33 = & V_33 ,
. V_39 = F_23 ,
} ;
int V_40 ;
V_9 -> V_41 &= ~ V_42 ;
V_40 = F_33 ( V_9 , V_2 , V_3 , V_11 , & V_35 ) ;
F_21 ( V_33 . V_16 ) ;
return V_40 ;
}
static int F_34 ( struct V_8 * V_9 , struct V_10 * V_2 ,
struct V_10 * V_3 , unsigned int V_11 )
{
struct V_28 * V_1 = F_32 ( V_9 -> V_25 ) ;
T_3 V_32 [ V_18 ] ;
struct V_22 V_33 = {
. V_1 = & V_1 -> V_30 ,
. V_16 = false ,
} ;
struct V_34 V_35 = {
. V_36 = V_32 ,
. V_37 = sizeof( V_32 ) ,
. V_38 = & V_1 -> V_31 ,
. V_33 = & V_33 ,
. V_39 = F_25 ,
} ;
int V_40 ;
V_9 -> V_41 &= ~ V_42 ;
V_40 = F_33 ( V_9 , V_2 , V_3 , V_11 , & V_35 ) ;
F_21 ( V_33 . V_16 ) ;
return V_40 ;
}
void F_35 ( struct V_24 * V_25 )
{
struct V_28 * V_1 = F_28 ( V_25 ) ;
F_36 ( & V_1 -> V_31 ) ;
}
int F_37 ( struct V_24 * V_25 , const V_6 * V_26 ,
unsigned int V_27 )
{
struct V_43 * V_1 = F_28 ( V_25 ) ;
T_4 * V_41 = & V_25 -> V_44 ;
int V_29 ;
if ( V_27 % 2 ) {
* V_41 |= V_45 ;
return - V_46 ;
}
V_29 = F_29 ( & V_1 -> V_33 , V_26 , V_27 / 2 ) ;
if ( V_29 )
return V_29 ;
return F_29 ( & V_1 -> V_47 , V_26 + V_27 / 2 , V_27 / 2 ) ;
}
static int F_38 ( struct V_8 * V_9 , struct V_10 * V_2 ,
struct V_10 * V_3 , unsigned int V_11 )
{
struct V_43 * V_1 = F_32 ( V_9 -> V_25 ) ;
return F_39 ( & V_48 , V_9 , V_2 , V_3 , V_11 ,
F_40 ( F_4 ) ,
& V_1 -> V_47 , & V_1 -> V_33 ) ;
}
static int F_41 ( struct V_8 * V_9 , struct V_10 * V_2 ,
struct V_10 * V_3 , unsigned int V_11 )
{
struct V_43 * V_1 = F_32 ( V_9 -> V_25 ) ;
return F_39 ( & V_49 , V_9 , V_2 , V_3 , V_11 ,
F_40 ( F_4 ) ,
& V_1 -> V_47 , & V_1 -> V_33 ) ;
}
static int T_5 F_42 ( void )
{
const char * V_50 ;
if ( ! F_43 ( V_51 | V_52 ,
& V_50 ) ) {
F_44 ( L_1 , V_50 ) ;
return - V_53 ;
}
return F_45 ( V_54 , F_46 ( V_54 ) ) ;
}
static void T_6 F_47 ( void )
{
F_48 ( V_54 , F_46 ( V_54 ) ) ;
}
