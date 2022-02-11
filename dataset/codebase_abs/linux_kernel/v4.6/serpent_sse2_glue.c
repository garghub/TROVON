static void F_1 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 )
{
T_1 V_4 [ V_5 - 1 ] ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 - 1 ; V_6 ++ )
V_4 [ V_6 ] = V_3 [ V_6 ] ;
F_2 ( V_1 , ( V_7 * ) V_2 , ( V_7 * ) V_3 ) ;
for ( V_6 = 0 ; V_6 < V_5 - 1 ; V_6 ++ )
F_3 ( V_2 + ( V_6 + 1 ) , V_2 + ( V_6 + 1 ) , V_4 + V_6 ) ;
}
static void F_4 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 , T_2 * V_8 )
{
T_3 V_9 ;
F_5 ( & V_9 , V_8 ) ;
F_6 ( V_8 ) ;
F_7 ( V_1 , ( V_7 * ) & V_9 , ( V_7 * ) & V_9 ) ;
F_3 ( V_2 , V_3 , ( T_1 * ) & V_9 ) ;
}
static void F_8 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 ,
T_2 * V_8 )
{
T_3 V_10 [ V_5 ] ;
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_5 ; V_11 ++ ) {
if ( V_2 != V_3 )
V_2 [ V_11 ] = V_3 [ V_11 ] ;
F_5 ( & V_10 [ V_11 ] , V_8 ) ;
F_6 ( V_8 ) ;
}
F_9 ( V_1 , ( V_7 * ) V_2 , ( V_7 * ) V_10 ) ;
}
static int F_10 ( struct V_12 * V_13 , struct V_14 * V_2 ,
struct V_14 * V_3 , unsigned int V_15 )
{
return F_11 ( & V_16 , V_13 , V_2 , V_3 , V_15 ) ;
}
static int F_12 ( struct V_12 * V_13 , struct V_14 * V_2 ,
struct V_14 * V_3 , unsigned int V_15 )
{
return F_11 ( & V_17 , V_13 , V_2 , V_3 , V_15 ) ;
}
static int F_13 ( struct V_12 * V_13 , struct V_14 * V_2 ,
struct V_14 * V_3 , unsigned int V_15 )
{
return F_14 ( F_15 ( F_7 ) , V_13 ,
V_2 , V_3 , V_15 ) ;
}
static int F_16 ( struct V_12 * V_13 , struct V_14 * V_2 ,
struct V_14 * V_3 , unsigned int V_15 )
{
return F_17 ( & V_18 , V_13 , V_2 , V_3 ,
V_15 ) ;
}
static int F_18 ( struct V_12 * V_13 , struct V_14 * V_2 ,
struct V_14 * V_3 , unsigned int V_15 )
{
return F_19 ( & V_19 , V_13 , V_2 , V_3 , V_15 ) ;
}
static inline bool F_20 ( bool V_20 , unsigned int V_15 )
{
return F_21 ( V_21 , V_5 ,
NULL , V_20 , V_15 ) ;
}
static inline void F_22 ( bool V_20 )
{
F_23 ( V_20 ) ;
}
static void F_24 ( void * V_22 , V_7 * V_23 , unsigned int V_15 )
{
const unsigned int V_24 = V_21 ;
struct V_25 * V_1 = V_22 ;
int V_11 ;
V_1 -> V_20 = F_20 ( V_1 -> V_20 , V_15 ) ;
if ( V_15 == V_24 * V_5 ) {
F_25 ( V_1 -> V_1 , V_23 , V_23 ) ;
return;
}
for ( V_11 = 0 ; V_11 < V_15 / V_24 ; V_11 ++ , V_23 += V_24 )
F_7 ( V_1 -> V_1 , V_23 , V_23 ) ;
}
static void F_26 ( void * V_22 , V_7 * V_23 , unsigned int V_15 )
{
const unsigned int V_24 = V_21 ;
struct V_25 * V_1 = V_22 ;
int V_11 ;
V_1 -> V_20 = F_20 ( V_1 -> V_20 , V_15 ) ;
if ( V_15 == V_24 * V_5 ) {
F_2 ( V_1 -> V_1 , V_23 , V_23 ) ;
return;
}
for ( V_11 = 0 ; V_11 < V_15 / V_24 ; V_11 ++ , V_23 += V_24 )
F_27 ( V_1 -> V_1 , V_23 , V_23 ) ;
}
static int F_28 ( struct V_26 * V_27 , const V_7 * V_28 ,
unsigned int V_29 )
{
struct V_30 * V_1 = F_29 ( V_27 ) ;
int V_31 ;
V_31 = F_30 ( & V_1 -> V_32 , V_28 , V_29 -
V_21 ) ;
if ( V_31 )
return V_31 ;
return F_31 ( & V_1 -> V_33 , V_28 + V_29 -
V_21 ) ;
}
static int F_32 ( struct V_12 * V_13 , struct V_14 * V_2 ,
struct V_14 * V_3 , unsigned int V_15 )
{
struct V_30 * V_1 = F_33 ( V_13 -> V_27 ) ;
T_3 V_34 [ V_5 ] ;
struct V_25 V_35 = {
. V_1 = & V_1 -> V_32 ,
. V_20 = false ,
} ;
struct V_36 V_37 = {
. V_38 = V_34 ,
. V_39 = sizeof( V_34 ) ,
. V_40 = & V_1 -> V_33 ,
. V_35 = & V_35 ,
. V_41 = F_24 ,
} ;
int V_42 ;
V_13 -> V_43 &= ~ V_44 ;
V_42 = F_34 ( V_13 , V_2 , V_3 , V_15 , & V_37 ) ;
F_22 ( V_35 . V_20 ) ;
return V_42 ;
}
static int F_35 ( struct V_12 * V_13 , struct V_14 * V_2 ,
struct V_14 * V_3 , unsigned int V_15 )
{
struct V_30 * V_1 = F_33 ( V_13 -> V_27 ) ;
T_3 V_34 [ V_5 ] ;
struct V_25 V_35 = {
. V_1 = & V_1 -> V_32 ,
. V_20 = false ,
} ;
struct V_36 V_37 = {
. V_38 = V_34 ,
. V_39 = sizeof( V_34 ) ,
. V_40 = & V_1 -> V_33 ,
. V_35 = & V_35 ,
. V_41 = F_26 ,
} ;
int V_42 ;
V_13 -> V_43 &= ~ V_44 ;
V_42 = F_34 ( V_13 , V_2 , V_3 , V_15 , & V_37 ) ;
F_22 ( V_35 . V_20 ) ;
return V_42 ;
}
static void F_36 ( struct V_26 * V_27 )
{
struct V_30 * V_1 = F_29 ( V_27 ) ;
F_37 ( & V_1 -> V_33 ) ;
}
static int F_38 ( struct V_26 * V_27 , const V_7 * V_28 ,
unsigned int V_29 )
{
struct V_45 * V_1 = F_29 ( V_27 ) ;
int V_31 ;
V_31 = F_39 ( V_27 , V_28 , V_29 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_30 ( & V_1 -> V_35 , V_28 , V_29 / 2 ) ;
if ( V_31 )
return V_31 ;
return F_30 ( & V_1 -> V_46 , V_28 + V_29 / 2 , V_29 / 2 ) ;
}
static int F_40 ( struct V_12 * V_13 , struct V_14 * V_2 ,
struct V_14 * V_3 , unsigned int V_15 )
{
struct V_45 * V_1 = F_33 ( V_13 -> V_27 ) ;
T_3 V_34 [ V_5 ] ;
struct V_25 V_35 = {
. V_1 = & V_1 -> V_35 ,
. V_20 = false ,
} ;
struct V_47 V_37 = {
. V_38 = V_34 ,
. V_39 = sizeof( V_34 ) ,
. V_46 = & V_1 -> V_46 ,
. V_48 = F_41 ( F_7 ) ,
. V_35 = & V_35 ,
. V_41 = F_24 ,
} ;
int V_42 ;
V_13 -> V_43 &= ~ V_44 ;
V_42 = F_42 ( V_13 , V_2 , V_3 , V_15 , & V_37 ) ;
F_22 ( V_35 . V_20 ) ;
return V_42 ;
}
static int F_43 ( struct V_12 * V_13 , struct V_14 * V_2 ,
struct V_14 * V_3 , unsigned int V_15 )
{
struct V_45 * V_1 = F_33 ( V_13 -> V_27 ) ;
T_3 V_34 [ V_5 ] ;
struct V_25 V_35 = {
. V_1 = & V_1 -> V_35 ,
. V_20 = false ,
} ;
struct V_47 V_37 = {
. V_38 = V_34 ,
. V_39 = sizeof( V_34 ) ,
. V_46 = & V_1 -> V_46 ,
. V_48 = F_41 ( F_7 ) ,
. V_35 = & V_35 ,
. V_41 = F_26 ,
} ;
int V_42 ;
V_13 -> V_43 &= ~ V_44 ;
V_42 = F_42 ( V_13 , V_2 , V_3 , V_15 , & V_37 ) ;
F_22 ( V_35 . V_20 ) ;
return V_42 ;
}
static int T_4 F_44 ( void )
{
if ( ! V_49 ) {
F_45 ( V_50 L_1 ) ;
return - V_51 ;
}
return F_46 ( V_52 , F_47 ( V_52 ) ) ;
}
static void T_5 F_48 ( void )
{
F_49 ( V_52 , F_47 ( V_52 ) ) ;
}
