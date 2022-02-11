static inline void F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
F_2 ( V_2 , V_3 , V_4 , false ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
F_2 ( V_2 , V_3 , V_4 , true ) ;
}
void F_4 ( void * V_2 , T_2 * V_3 , const T_2 * V_4 )
{
T_2 V_5 [ 2 ] ;
V_5 [ 0 ] = V_4 [ 0 ] ;
V_5 [ 1 ] = V_4 [ 1 ] ;
F_5 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_4 ) ;
F_6 ( & V_3 [ 1 ] , & V_3 [ 1 ] , & V_5 [ 0 ] ) ;
F_6 ( & V_3 [ 2 ] , & V_3 [ 2 ] , & V_5 [ 1 ] ) ;
}
void F_7 ( void * V_2 , T_2 * V_3 , const T_2 * V_4 , T_3 * V_6 )
{
T_4 V_7 ;
if ( V_3 != V_4 )
* V_3 = * V_4 ;
F_8 ( & V_7 , V_6 ) ;
F_9 ( V_6 ) ;
F_10 ( V_2 , ( T_1 * ) & V_7 , ( T_1 * ) & V_7 ) ;
F_6 ( V_3 , V_3 , ( T_2 * ) & V_7 ) ;
}
void F_11 ( void * V_2 , T_2 * V_3 , const T_2 * V_4 ,
T_3 * V_6 )
{
T_4 V_8 [ 3 ] ;
if ( V_3 != V_4 ) {
V_3 [ 0 ] = V_4 [ 0 ] ;
V_3 [ 1 ] = V_4 [ 1 ] ;
V_3 [ 2 ] = V_4 [ 2 ] ;
}
F_8 ( & V_8 [ 0 ] , V_6 ) ;
F_9 ( V_6 ) ;
F_8 ( & V_8 [ 1 ] , V_6 ) ;
F_9 ( V_6 ) ;
F_8 ( & V_8 [ 2 ] , V_6 ) ;
F_9 ( V_6 ) ;
F_3 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_8 ) ;
}
static int F_12 ( struct V_9 * V_10 , struct V_11 * V_3 ,
struct V_11 * V_4 , unsigned int V_12 )
{
return F_13 ( & V_13 , V_10 , V_3 , V_4 , V_12 ) ;
}
static int F_14 ( struct V_9 * V_10 , struct V_11 * V_3 ,
struct V_11 * V_4 , unsigned int V_12 )
{
return F_13 ( & V_14 , V_10 , V_3 , V_4 , V_12 ) ;
}
static int F_15 ( struct V_9 * V_10 , struct V_11 * V_3 ,
struct V_11 * V_4 , unsigned int V_12 )
{
return F_16 ( F_17 ( F_10 ) , V_10 ,
V_3 , V_4 , V_12 ) ;
}
static int F_18 ( struct V_9 * V_10 , struct V_11 * V_3 ,
struct V_11 * V_4 , unsigned int V_12 )
{
return F_19 ( & V_15 , V_10 , V_3 , V_4 ,
V_12 ) ;
}
static int F_20 ( struct V_9 * V_10 , struct V_11 * V_3 ,
struct V_11 * V_4 , unsigned int V_12 )
{
return F_21 ( & V_16 , V_10 , V_3 , V_4 , V_12 ) ;
}
static void F_22 ( void * V_17 , T_1 * V_18 , unsigned int V_12 )
{
const unsigned int V_19 = V_20 ;
struct V_1 * V_2 = V_17 ;
int V_21 ;
if ( V_12 == 3 * V_19 ) {
F_1 ( V_2 , V_18 , V_18 ) ;
return;
}
for ( V_21 = 0 ; V_21 < V_12 / V_19 ; V_21 ++ , V_18 += V_19 )
F_10 ( V_2 , V_18 , V_18 ) ;
}
static void F_23 ( void * V_17 , T_1 * V_18 , unsigned int V_12 )
{
const unsigned int V_19 = V_20 ;
struct V_1 * V_2 = V_17 ;
int V_21 ;
if ( V_12 == 3 * V_19 ) {
F_5 ( V_2 , V_18 , V_18 ) ;
return;
}
for ( V_21 = 0 ; V_21 < V_12 / V_19 ; V_21 ++ , V_18 += V_19 )
F_24 ( V_2 , V_18 , V_18 ) ;
}
int F_25 ( struct V_22 * V_23 , const T_1 * V_24 ,
unsigned int V_25 )
{
struct V_26 * V_2 = F_26 ( V_23 ) ;
int V_27 ;
V_27 = F_27 ( & V_2 -> V_1 , V_24 , V_25 - V_20 ,
& V_23 -> V_28 ) ;
if ( V_27 )
return V_27 ;
return F_28 ( & V_2 -> V_29 , V_24 + V_25 - V_20 ) ;
}
static int F_29 ( struct V_9 * V_10 , struct V_11 * V_3 ,
struct V_11 * V_4 , unsigned int V_12 )
{
struct V_26 * V_2 = F_30 ( V_10 -> V_23 ) ;
T_4 V_30 [ 3 ] ;
struct V_31 V_32 = {
. V_33 = V_30 ,
. V_34 = sizeof( V_30 ) ,
. V_35 = & V_2 -> V_29 ,
. V_36 = & V_2 -> V_1 ,
. V_37 = F_22 ,
} ;
return F_31 ( V_10 , V_3 , V_4 , V_12 , & V_32 ) ;
}
static int F_32 ( struct V_9 * V_10 , struct V_11 * V_3 ,
struct V_11 * V_4 , unsigned int V_12 )
{
struct V_26 * V_2 = F_30 ( V_10 -> V_23 ) ;
T_4 V_30 [ 3 ] ;
struct V_31 V_32 = {
. V_33 = V_30 ,
. V_34 = sizeof( V_30 ) ,
. V_35 = & V_2 -> V_29 ,
. V_36 = & V_2 -> V_1 ,
. V_37 = F_23 ,
} ;
return F_31 ( V_10 , V_3 , V_4 , V_12 , & V_32 ) ;
}
void F_33 ( struct V_22 * V_23 )
{
struct V_26 * V_2 = F_26 ( V_23 ) ;
F_34 ( & V_2 -> V_29 ) ;
}
int F_35 ( struct V_22 * V_23 , const T_1 * V_24 ,
unsigned int V_25 )
{
struct V_38 * V_2 = F_26 ( V_23 ) ;
T_5 * V_39 = & V_23 -> V_28 ;
int V_27 ;
if ( V_25 % 2 ) {
* V_39 |= V_40 ;
return - V_41 ;
}
V_27 = F_27 ( & V_2 -> V_36 , V_24 , V_25 / 2 , V_39 ) ;
if ( V_27 )
return V_27 ;
return F_27 ( & V_2 -> V_42 , V_24 + V_25 / 2 , V_25 / 2 ,
V_39 ) ;
}
static int F_36 ( struct V_9 * V_10 , struct V_11 * V_3 ,
struct V_11 * V_4 , unsigned int V_12 )
{
struct V_38 * V_2 = F_30 ( V_10 -> V_23 ) ;
T_4 V_30 [ 3 ] ;
struct V_43 V_32 = {
. V_33 = V_30 ,
. V_34 = sizeof( V_30 ) ,
. V_42 = & V_2 -> V_42 ,
. V_44 = F_37 ( F_10 ) ,
. V_36 = & V_2 -> V_36 ,
. V_37 = F_22 ,
} ;
return F_38 ( V_10 , V_3 , V_4 , V_12 , & V_32 ) ;
}
static int F_39 ( struct V_9 * V_10 , struct V_11 * V_3 ,
struct V_11 * V_4 , unsigned int V_12 )
{
struct V_38 * V_2 = F_30 ( V_10 -> V_23 ) ;
T_4 V_30 [ 3 ] ;
struct V_43 V_32 = {
. V_33 = V_30 ,
. V_34 = sizeof( V_30 ) ,
. V_42 = & V_2 -> V_42 ,
. V_44 = F_37 ( F_10 ) ,
. V_36 = & V_2 -> V_36 ,
. V_37 = F_23 ,
} ;
return F_38 ( V_10 , V_3 , V_4 , V_12 , & V_32 ) ;
}
static bool F_40 ( void )
{
if ( V_45 . V_46 != V_47 )
return false ;
if ( V_45 . V_48 == 0x06 &&
( V_45 . V_49 == 0x1c ||
V_45 . V_49 == 0x26 ||
V_45 . V_49 == 0x36 ) ) {
return true ;
}
if ( V_45 . V_48 == 0x0f ) {
return true ;
}
return false ;
}
static int T_6 F_41 ( void )
{
if ( ! V_50 && F_40 () ) {
F_42 ( V_51
L_1
L_2
L_3 ) ;
return - V_52 ;
}
return F_43 ( V_53 , F_44 ( V_53 ) ) ;
}
static void T_7 F_45 ( void )
{
F_46 ( V_53 , F_44 ( V_53 ) ) ;
}
