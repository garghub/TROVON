static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
return F_2 ( & V_7 , V_2 , V_4 , V_5 , V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
return F_2 ( & V_8 , V_2 , V_4 , V_5 , V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
return F_5 ( F_6 ( V_9 ) , V_2 ,
V_4 , V_5 , V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
return F_8 ( & V_10 , V_2 , V_4 , V_5 ,
V_6 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
return F_10 ( & V_11 , V_2 , V_4 , V_5 , V_6 ) ;
}
static inline bool F_11 ( bool V_12 , unsigned int V_6 )
{
return F_12 ( V_13 ,
V_14 , NULL , V_12 ,
V_6 ) ;
}
static inline void F_13 ( bool V_12 )
{
F_14 ( V_12 ) ;
}
static int F_15 ( struct V_15 * V_16 , const T_1 * V_17 ,
unsigned int V_18 )
{
return F_16 ( F_17 ( V_16 ) , V_17 , V_18 ,
& V_16 -> V_19 ) ;
}
static void F_18 ( void * V_20 , T_1 * V_21 , unsigned int V_6 )
{
const unsigned int V_22 = V_13 ;
struct V_23 * V_24 = V_20 ;
int V_25 ;
V_24 -> V_12 = F_11 ( V_24 -> V_12 , V_6 ) ;
if ( V_6 >= V_26 * V_22 ) {
F_19 ( V_24 -> V_24 , V_21 , V_21 ) ;
V_21 += V_22 * V_26 ;
V_6 -= V_22 * V_26 ;
}
if ( V_6 >= V_14 * V_22 ) {
F_20 ( V_24 -> V_24 , V_21 , V_21 ) ;
V_21 += V_22 * V_14 ;
V_6 -= V_22 * V_14 ;
}
while ( V_6 >= V_27 * V_22 ) {
F_21 ( V_24 -> V_24 , V_21 , V_21 ) ;
V_21 += V_22 * V_27 ;
V_6 -= V_22 * V_27 ;
}
for ( V_25 = 0 ; V_25 < V_6 / V_22 ; V_25 ++ , V_21 += V_22 )
V_9 ( V_24 -> V_24 , V_21 , V_21 ) ;
}
static void F_22 ( void * V_20 , T_1 * V_21 , unsigned int V_6 )
{
const unsigned int V_22 = V_13 ;
struct V_23 * V_24 = V_20 ;
int V_25 ;
V_24 -> V_12 = F_11 ( V_24 -> V_12 , V_6 ) ;
if ( V_6 >= V_26 * V_22 ) {
F_23 ( V_24 -> V_24 , V_21 , V_21 ) ;
V_21 += V_22 * V_26 ;
V_6 -= V_22 * V_26 ;
}
if ( V_6 >= V_14 * V_22 ) {
F_24 ( V_24 -> V_24 , V_21 , V_21 ) ;
V_21 += V_22 * V_14 ;
V_6 -= V_22 * V_14 ;
}
while ( V_6 >= V_27 * V_22 ) {
F_25 ( V_24 -> V_24 , V_21 , V_21 ) ;
V_21 += V_22 * V_27 ;
V_6 -= V_22 * V_27 ;
}
for ( V_25 = 0 ; V_25 < V_6 / V_22 ; V_25 ++ , V_21 += V_22 )
F_26 ( V_24 -> V_24 , V_21 , V_21 ) ;
}
static int F_27 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
struct V_28 * V_24 = F_28 ( V_2 -> V_16 ) ;
T_2 V_29 [ V_26 ] ;
struct V_23 V_30 = {
. V_24 = & V_24 -> V_31 ,
. V_12 = false ,
} ;
struct V_32 V_33 = {
. V_34 = V_29 ,
. V_35 = sizeof( V_29 ) ,
. V_36 = & V_24 -> V_37 ,
. V_30 = & V_30 ,
. V_38 = F_18 ,
} ;
int V_39 ;
V_2 -> V_40 &= ~ V_41 ;
V_39 = F_29 ( V_2 , V_4 , V_5 , V_6 , & V_33 ) ;
F_13 ( V_30 . V_12 ) ;
return V_39 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
struct V_28 * V_24 = F_28 ( V_2 -> V_16 ) ;
T_2 V_29 [ V_26 ] ;
struct V_23 V_30 = {
. V_24 = & V_24 -> V_31 ,
. V_12 = false ,
} ;
struct V_32 V_33 = {
. V_34 = V_29 ,
. V_35 = sizeof( V_29 ) ,
. V_36 = & V_24 -> V_37 ,
. V_30 = & V_30 ,
. V_38 = F_22 ,
} ;
int V_39 ;
V_2 -> V_40 &= ~ V_41 ;
V_39 = F_29 ( V_2 , V_4 , V_5 , V_6 , & V_33 ) ;
F_13 ( V_30 . V_12 ) ;
return V_39 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
struct V_42 * V_24 = F_28 ( V_2 -> V_16 ) ;
return F_32 ( & V_43 , V_2 , V_4 , V_5 , V_6 ,
F_33 ( V_9 ) ,
& V_24 -> V_44 , & V_24 -> V_30 ) ;
}
static int F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
struct V_42 * V_24 = F_28 ( V_2 -> V_16 ) ;
return F_32 ( & V_45 , V_2 , V_4 , V_5 , V_6 ,
F_33 ( V_9 ) ,
& V_24 -> V_44 , & V_24 -> V_30 ) ;
}
static int T_3 F_35 ( void )
{
const char * V_46 ;
if ( ! V_47 || ! V_48 || ! V_49 || ! V_50 ) {
F_36 ( L_1 ) ;
return - V_51 ;
}
if ( ! F_37 ( V_52 | V_53 , & V_46 ) ) {
F_36 ( L_2 , V_46 ) ;
return - V_51 ;
}
return F_38 ( V_54 , F_39 ( V_54 ) ) ;
}
static void T_4 F_40 ( void )
{
F_41 ( V_54 , F_39 ( V_54 ) ) ;
}
