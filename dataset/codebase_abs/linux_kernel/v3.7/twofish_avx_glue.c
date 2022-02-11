static inline void F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
F_2 ( V_2 , V_3 , V_4 , false ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
F_4 ( V_2 , V_3 , V_4 , false ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
F_4 ( V_2 , V_3 , V_4 , true ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
F_7 ( V_2 , V_3 , V_4 ) ;
}
static void F_8 ( void * V_2 , T_2 * V_3 , const T_2 * V_4 )
{
T_2 V_5 [ V_6 - 1 ] ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 - 1 ; V_7 ++ )
V_5 [ V_7 ] = V_4 [ V_7 ] ;
F_6 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_4 ) ;
for ( V_7 = 0 ; V_7 < V_6 - 1 ; V_7 ++ )
F_9 ( V_3 + ( V_7 + 1 ) , V_3 + ( V_7 + 1 ) , V_5 + V_7 ) ;
}
static void F_10 ( void * V_2 , T_2 * V_3 , const T_2 * V_4 ,
T_2 * V_8 )
{
T_3 V_9 [ V_6 ] ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_6 ; V_10 ++ ) {
if ( V_3 != V_4 )
V_3 [ V_10 ] = V_4 [ V_10 ] ;
F_11 ( & V_9 [ V_10 ] , V_8 ) ;
F_12 ( V_8 ) ;
}
F_5 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_9 ) ;
}
static int F_13 ( struct V_11 * V_12 , struct V_13 * V_3 ,
struct V_13 * V_4 , unsigned int V_14 )
{
return F_14 ( & V_15 , V_12 , V_3 , V_4 , V_14 ) ;
}
static int F_15 ( struct V_11 * V_12 , struct V_13 * V_3 ,
struct V_13 * V_4 , unsigned int V_14 )
{
return F_14 ( & V_16 , V_12 , V_3 , V_4 , V_14 ) ;
}
static int F_16 ( struct V_11 * V_12 , struct V_13 * V_3 ,
struct V_13 * V_4 , unsigned int V_14 )
{
return F_17 ( F_18 ( V_17 ) , V_12 ,
V_3 , V_4 , V_14 ) ;
}
static int F_19 ( struct V_11 * V_12 , struct V_13 * V_3 ,
struct V_13 * V_4 , unsigned int V_14 )
{
return F_20 ( & V_18 , V_12 , V_3 , V_4 ,
V_14 ) ;
}
static int F_21 ( struct V_11 * V_12 , struct V_13 * V_3 ,
struct V_13 * V_4 , unsigned int V_14 )
{
return F_22 ( & V_19 , V_12 , V_3 , V_4 , V_14 ) ;
}
static inline bool F_23 ( bool V_20 , unsigned int V_14 )
{
return F_24 ( V_21 , V_6 , NULL ,
V_20 , V_14 ) ;
}
static inline void F_25 ( bool V_20 )
{
F_26 ( V_20 ) ;
}
static void F_27 ( void * V_22 , T_1 * V_23 , unsigned int V_14 )
{
const unsigned int V_24 = V_21 ;
struct V_25 * V_2 = V_22 ;
int V_10 ;
V_2 -> V_20 = F_23 ( V_2 -> V_20 , V_14 ) ;
if ( V_14 == V_24 * V_6 ) {
F_3 ( V_2 -> V_2 , V_23 , V_23 ) ;
return;
}
for ( V_10 = 0 ; V_10 < V_14 / ( V_24 * 3 ) ; V_10 ++ , V_23 += V_24 * 3 )
F_1 ( V_2 -> V_2 , V_23 , V_23 ) ;
V_14 %= V_24 * 3 ;
for ( V_10 = 0 ; V_10 < V_14 / V_24 ; V_10 ++ , V_23 += V_24 )
V_17 ( V_2 -> V_2 , V_23 , V_23 ) ;
}
static void F_28 ( void * V_22 , T_1 * V_23 , unsigned int V_14 )
{
const unsigned int V_24 = V_21 ;
struct V_25 * V_2 = V_22 ;
int V_10 ;
V_2 -> V_20 = F_23 ( V_2 -> V_20 , V_14 ) ;
if ( V_14 == V_24 * V_6 ) {
F_6 ( V_2 -> V_2 , V_23 , V_23 ) ;
return;
}
for ( V_10 = 0 ; V_10 < V_14 / ( V_24 * 3 ) ; V_10 ++ , V_23 += V_24 * 3 )
F_29 ( V_2 -> V_2 , V_23 , V_23 ) ;
V_14 %= V_24 * 3 ;
for ( V_10 = 0 ; V_10 < V_14 / V_24 ; V_10 ++ , V_23 += V_24 )
F_30 ( V_2 -> V_2 , V_23 , V_23 ) ;
}
static int F_31 ( struct V_11 * V_12 , struct V_13 * V_3 ,
struct V_13 * V_4 , unsigned int V_14 )
{
struct V_26 * V_2 = F_32 ( V_12 -> V_27 ) ;
T_3 V_28 [ V_6 ] ;
struct V_25 V_29 = {
. V_2 = & V_2 -> V_1 ,
. V_20 = false ,
} ;
struct V_30 V_31 = {
. V_32 = V_28 ,
. V_33 = sizeof( V_28 ) ,
. V_34 = & V_2 -> V_35 ,
. V_29 = & V_29 ,
. V_36 = F_27 ,
} ;
int V_37 ;
V_12 -> V_38 &= ~ V_39 ;
V_37 = F_33 ( V_12 , V_3 , V_4 , V_14 , & V_31 ) ;
F_25 ( V_29 . V_20 ) ;
return V_37 ;
}
static int F_34 ( struct V_11 * V_12 , struct V_13 * V_3 ,
struct V_13 * V_4 , unsigned int V_14 )
{
struct V_26 * V_2 = F_32 ( V_12 -> V_27 ) ;
T_3 V_28 [ V_6 ] ;
struct V_25 V_29 = {
. V_2 = & V_2 -> V_1 ,
. V_20 = false ,
} ;
struct V_30 V_31 = {
. V_32 = V_28 ,
. V_33 = sizeof( V_28 ) ,
. V_34 = & V_2 -> V_35 ,
. V_29 = & V_29 ,
. V_36 = F_28 ,
} ;
int V_37 ;
V_12 -> V_38 &= ~ V_39 ;
V_37 = F_33 ( V_12 , V_3 , V_4 , V_14 , & V_31 ) ;
F_25 ( V_29 . V_20 ) ;
return V_37 ;
}
static int F_35 ( struct V_11 * V_12 , struct V_13 * V_3 ,
struct V_13 * V_4 , unsigned int V_14 )
{
struct V_40 * V_2 = F_32 ( V_12 -> V_27 ) ;
T_3 V_28 [ V_6 ] ;
struct V_25 V_29 = {
. V_2 = & V_2 -> V_29 ,
. V_20 = false ,
} ;
struct V_41 V_31 = {
. V_32 = V_28 ,
. V_33 = sizeof( V_28 ) ,
. V_42 = & V_2 -> V_42 ,
. V_43 = F_36 ( V_17 ) ,
. V_29 = & V_29 ,
. V_36 = F_27 ,
} ;
int V_37 ;
V_12 -> V_38 &= ~ V_39 ;
V_37 = F_37 ( V_12 , V_3 , V_4 , V_14 , & V_31 ) ;
F_25 ( V_29 . V_20 ) ;
return V_37 ;
}
static int F_38 ( struct V_11 * V_12 , struct V_13 * V_3 ,
struct V_13 * V_4 , unsigned int V_14 )
{
struct V_40 * V_2 = F_32 ( V_12 -> V_27 ) ;
T_3 V_28 [ V_6 ] ;
struct V_25 V_29 = {
. V_2 = & V_2 -> V_29 ,
. V_20 = false ,
} ;
struct V_41 V_31 = {
. V_32 = V_28 ,
. V_33 = sizeof( V_28 ) ,
. V_42 = & V_2 -> V_42 ,
. V_43 = F_36 ( V_17 ) ,
. V_29 = & V_29 ,
. V_36 = F_28 ,
} ;
int V_37 ;
V_12 -> V_38 &= ~ V_39 ;
V_37 = F_37 ( V_12 , V_3 , V_4 , V_14 , & V_31 ) ;
F_25 ( V_29 . V_20 ) ;
return V_37 ;
}
static int T_4 F_39 ( void )
{
T_5 V_44 ;
if ( ! V_45 || ! V_46 ) {
F_40 ( V_47 L_1 ) ;
return - V_48 ;
}
V_44 = F_41 ( V_49 ) ;
if ( ( V_44 & ( V_50 | V_51 ) ) != ( V_50 | V_51 ) ) {
F_40 ( V_47 L_2 ) ;
return - V_48 ;
}
return F_42 ( V_52 , F_43 ( V_52 ) ) ;
}
static void T_6 F_44 ( void )
{
F_45 ( V_52 , F_43 ( V_52 ) ) ;
}
