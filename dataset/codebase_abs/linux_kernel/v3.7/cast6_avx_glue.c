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
static inline void F_4 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
F_5 ( V_2 , V_3 , V_4 ) ;
}
static void F_6 ( void * V_2 , T_2 * V_3 , const T_2 * V_4 )
{
T_2 V_5 [ V_6 - 1 ] ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 - 1 ; V_7 ++ )
V_5 [ V_7 ] = V_4 [ V_7 ] ;
F_4 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_4 ) ;
for ( V_7 = 0 ; V_7 < V_6 - 1 ; V_7 ++ )
F_7 ( V_3 + ( V_7 + 1 ) , V_3 + ( V_7 + 1 ) , V_5 + V_7 ) ;
}
static void F_8 ( void * V_2 , T_2 * V_3 , const T_2 * V_4 , T_2 * V_8 )
{
T_3 V_9 ;
F_9 ( & V_9 , V_8 ) ;
F_10 ( V_8 ) ;
F_11 ( V_2 , ( T_1 * ) & V_9 , ( T_1 * ) & V_9 ) ;
F_7 ( V_3 , V_4 , ( T_2 * ) & V_9 ) ;
}
static void F_12 ( void * V_2 , T_2 * V_3 , const T_2 * V_4 ,
T_2 * V_8 )
{
T_3 V_10 [ V_6 ] ;
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_6 ; V_11 ++ ) {
if ( V_3 != V_4 )
V_3 [ V_11 ] = V_4 [ V_11 ] ;
F_9 ( & V_10 [ V_11 ] , V_8 ) ;
F_10 ( V_8 ) ;
}
F_3 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_10 ) ;
}
static int F_13 ( struct V_12 * V_13 , struct V_14 * V_3 ,
struct V_14 * V_4 , unsigned int V_15 )
{
return F_14 ( & V_16 , V_13 , V_3 , V_4 , V_15 ) ;
}
static int F_15 ( struct V_12 * V_13 , struct V_14 * V_3 ,
struct V_14 * V_4 , unsigned int V_15 )
{
return F_14 ( & V_17 , V_13 , V_3 , V_4 , V_15 ) ;
}
static int F_16 ( struct V_12 * V_13 , struct V_14 * V_3 ,
struct V_14 * V_4 , unsigned int V_15 )
{
return F_17 ( F_18 ( F_11 ) , V_13 ,
V_3 , V_4 , V_15 ) ;
}
static int F_19 ( struct V_12 * V_13 , struct V_14 * V_3 ,
struct V_14 * V_4 , unsigned int V_15 )
{
return F_20 ( & V_18 , V_13 , V_3 , V_4 ,
V_15 ) ;
}
static int F_21 ( struct V_12 * V_13 , struct V_14 * V_3 ,
struct V_14 * V_4 , unsigned int V_15 )
{
return F_22 ( & V_19 , V_13 , V_3 , V_4 , V_15 ) ;
}
static inline bool F_23 ( bool V_20 , unsigned int V_15 )
{
return F_24 ( V_21 , V_6 ,
NULL , V_20 , V_15 ) ;
}
static inline void F_25 ( bool V_20 )
{
F_26 ( V_20 ) ;
}
static void F_27 ( void * V_22 , T_1 * V_23 , unsigned int V_15 )
{
const unsigned int V_24 = V_21 ;
struct V_25 * V_2 = V_22 ;
int V_11 ;
V_2 -> V_20 = F_23 ( V_2 -> V_20 , V_15 ) ;
if ( V_15 == V_24 * V_6 ) {
F_1 ( V_2 -> V_2 , V_23 , V_23 ) ;
return;
}
for ( V_11 = 0 ; V_11 < V_15 / V_24 ; V_11 ++ , V_23 += V_24 )
F_11 ( V_2 -> V_2 , V_23 , V_23 ) ;
}
static void F_28 ( void * V_22 , T_1 * V_23 , unsigned int V_15 )
{
const unsigned int V_24 = V_21 ;
struct V_25 * V_2 = V_22 ;
int V_11 ;
V_2 -> V_20 = F_23 ( V_2 -> V_20 , V_15 ) ;
if ( V_15 == V_24 * V_6 ) {
F_4 ( V_2 -> V_2 , V_23 , V_23 ) ;
return;
}
for ( V_11 = 0 ; V_11 < V_15 / V_24 ; V_11 ++ , V_23 += V_24 )
F_29 ( V_2 -> V_2 , V_23 , V_23 ) ;
}
static int F_30 ( struct V_26 * V_27 , const T_1 * V_28 ,
unsigned int V_29 )
{
struct V_30 * V_2 = F_31 ( V_27 ) ;
int V_31 ;
V_31 = F_32 ( & V_2 -> V_1 , V_28 , V_29 - V_21 ,
& V_27 -> V_32 ) ;
if ( V_31 )
return V_31 ;
return F_33 ( & V_2 -> V_33 , V_28 + V_29 - V_21 ) ;
}
static int F_34 ( struct V_12 * V_13 , struct V_14 * V_3 ,
struct V_14 * V_4 , unsigned int V_15 )
{
struct V_30 * V_2 = F_35 ( V_13 -> V_27 ) ;
T_3 V_34 [ V_6 ] ;
struct V_25 V_35 = {
. V_2 = & V_2 -> V_1 ,
. V_20 = false ,
} ;
struct V_36 V_37 = {
. V_38 = V_34 ,
. V_39 = sizeof( V_34 ) ,
. V_40 = & V_2 -> V_33 ,
. V_35 = & V_35 ,
. V_41 = F_27 ,
} ;
int V_42 ;
V_13 -> V_43 &= ~ V_44 ;
V_42 = F_36 ( V_13 , V_3 , V_4 , V_15 , & V_37 ) ;
F_25 ( V_35 . V_20 ) ;
return V_42 ;
}
static int F_37 ( struct V_12 * V_13 , struct V_14 * V_3 ,
struct V_14 * V_4 , unsigned int V_15 )
{
struct V_30 * V_2 = F_35 ( V_13 -> V_27 ) ;
T_3 V_34 [ V_6 ] ;
struct V_25 V_35 = {
. V_2 = & V_2 -> V_1 ,
. V_20 = false ,
} ;
struct V_36 V_37 = {
. V_38 = V_34 ,
. V_39 = sizeof( V_34 ) ,
. V_40 = & V_2 -> V_33 ,
. V_35 = & V_35 ,
. V_41 = F_28 ,
} ;
int V_42 ;
V_13 -> V_43 &= ~ V_44 ;
V_42 = F_36 ( V_13 , V_3 , V_4 , V_15 , & V_37 ) ;
F_25 ( V_35 . V_20 ) ;
return V_42 ;
}
static void F_38 ( struct V_26 * V_27 )
{
struct V_30 * V_2 = F_31 ( V_27 ) ;
F_39 ( & V_2 -> V_33 ) ;
}
static int F_40 ( struct V_26 * V_27 , const T_1 * V_28 ,
unsigned int V_29 )
{
struct V_45 * V_2 = F_31 ( V_27 ) ;
T_4 * V_43 = & V_27 -> V_32 ;
int V_31 ;
if ( V_29 % 2 ) {
* V_43 |= V_46 ;
return - V_47 ;
}
V_31 = F_32 ( & V_2 -> V_35 , V_28 , V_29 / 2 , V_43 ) ;
if ( V_31 )
return V_31 ;
return F_32 ( & V_2 -> V_48 , V_28 + V_29 / 2 , V_29 / 2 ,
V_43 ) ;
}
static int F_41 ( struct V_12 * V_13 , struct V_14 * V_3 ,
struct V_14 * V_4 , unsigned int V_15 )
{
struct V_45 * V_2 = F_35 ( V_13 -> V_27 ) ;
T_3 V_34 [ V_6 ] ;
struct V_25 V_35 = {
. V_2 = & V_2 -> V_35 ,
. V_20 = false ,
} ;
struct V_49 V_37 = {
. V_38 = V_34 ,
. V_39 = sizeof( V_34 ) ,
. V_48 = & V_2 -> V_48 ,
. V_50 = F_42 ( F_11 ) ,
. V_35 = & V_35 ,
. V_41 = F_27 ,
} ;
int V_42 ;
V_13 -> V_43 &= ~ V_44 ;
V_42 = F_43 ( V_13 , V_3 , V_4 , V_15 , & V_37 ) ;
F_25 ( V_35 . V_20 ) ;
return V_42 ;
}
static int F_44 ( struct V_12 * V_13 , struct V_14 * V_3 ,
struct V_14 * V_4 , unsigned int V_15 )
{
struct V_45 * V_2 = F_35 ( V_13 -> V_27 ) ;
T_3 V_34 [ V_6 ] ;
struct V_25 V_35 = {
. V_2 = & V_2 -> V_35 ,
. V_20 = false ,
} ;
struct V_49 V_37 = {
. V_38 = V_34 ,
. V_39 = sizeof( V_34 ) ,
. V_48 = & V_2 -> V_48 ,
. V_50 = F_42 ( F_11 ) ,
. V_35 = & V_35 ,
. V_41 = F_28 ,
} ;
int V_42 ;
V_13 -> V_43 &= ~ V_44 ;
V_42 = F_43 ( V_13 , V_3 , V_4 , V_15 , & V_37 ) ;
F_25 ( V_35 . V_20 ) ;
return V_42 ;
}
static int T_5 F_45 ( void )
{
T_6 V_51 ;
if ( ! V_52 || ! V_53 ) {
F_46 ( L_1 ) ;
return - V_54 ;
}
V_51 = F_47 ( V_55 ) ;
if ( ( V_51 & ( V_56 | V_57 ) ) != ( V_56 | V_57 ) ) {
F_46 ( L_2 ) ;
return - V_54 ;
}
return F_48 ( V_58 , F_49 ( V_58 ) ) ;
}
static void T_7 F_50 ( void )
{
F_51 ( V_58 , F_49 ( V_58 ) ) ;
}
