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
return F_12 ( V_13 , 8 , NULL , V_12 , V_6 ) ;
}
static inline void F_13 ( bool V_12 )
{
F_14 ( V_12 ) ;
}
static void F_15 ( void * V_14 , T_1 * V_15 , unsigned int V_6 )
{
const unsigned int V_16 = V_13 ;
struct V_17 * V_18 = V_14 ;
int V_19 ;
V_18 -> V_12 = F_11 ( V_18 -> V_12 , V_6 ) ;
if ( V_6 >= V_20 * V_16 ) {
F_16 ( V_18 -> V_18 , V_15 , V_15 ) ;
V_15 += V_16 * V_20 ;
V_6 -= V_16 * V_20 ;
}
while ( V_6 >= V_21 * V_16 ) {
F_17 ( V_18 -> V_18 , V_15 , V_15 ) ;
V_15 += V_16 * V_21 ;
V_6 -= V_16 * V_21 ;
}
for ( V_19 = 0 ; V_19 < V_6 / V_16 ; V_19 ++ , V_15 += V_16 )
V_9 ( V_18 -> V_18 , V_15 , V_15 ) ;
}
static void F_18 ( void * V_14 , T_1 * V_15 , unsigned int V_6 )
{
const unsigned int V_16 = V_13 ;
struct V_17 * V_18 = V_14 ;
int V_19 ;
V_18 -> V_12 = F_11 ( V_18 -> V_12 , V_6 ) ;
if ( V_6 >= V_20 * V_16 ) {
F_19 ( V_18 -> V_18 , V_15 , V_15 ) ;
V_15 += V_16 * V_20 ;
V_6 -= V_16 * V_20 ;
}
while ( V_6 >= V_21 * V_16 ) {
F_20 ( V_18 -> V_18 , V_15 , V_15 ) ;
V_15 += V_16 * V_21 ;
V_6 -= V_16 * V_21 ;
}
for ( V_19 = 0 ; V_19 < V_6 / V_16 ; V_19 ++ , V_15 += V_16 )
F_21 ( V_18 -> V_18 , V_15 , V_15 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
struct V_22 * V_18 = F_23 ( V_2 -> V_23 ) ;
T_2 V_24 [ V_20 ] ;
struct V_17 V_25 = {
. V_18 = & V_18 -> V_26 ,
. V_12 = false ,
} ;
struct V_27 V_28 = {
. V_29 = V_24 ,
. V_30 = sizeof( V_24 ) ,
. V_31 = & V_18 -> V_32 ,
. V_25 = & V_25 ,
. V_33 = F_15 ,
} ;
int V_34 ;
V_2 -> V_35 &= ~ V_36 ;
V_34 = F_24 ( V_2 , V_4 , V_5 , V_6 , & V_28 ) ;
F_13 ( V_25 . V_12 ) ;
return V_34 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
struct V_22 * V_18 = F_23 ( V_2 -> V_23 ) ;
T_2 V_24 [ V_20 ] ;
struct V_17 V_25 = {
. V_18 = & V_18 -> V_26 ,
. V_12 = false ,
} ;
struct V_27 V_28 = {
. V_29 = V_24 ,
. V_30 = sizeof( V_24 ) ,
. V_31 = & V_18 -> V_32 ,
. V_25 = & V_25 ,
. V_33 = F_18 ,
} ;
int V_34 ;
V_2 -> V_35 &= ~ V_36 ;
V_34 = F_24 ( V_2 , V_4 , V_5 , V_6 , & V_28 ) ;
F_13 ( V_25 . V_12 ) ;
return V_34 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
struct V_37 * V_18 = F_23 ( V_2 -> V_23 ) ;
return F_27 ( & V_38 , V_2 , V_4 , V_5 , V_6 ,
F_28 ( V_9 ) ,
& V_18 -> V_39 , & V_18 -> V_25 ) ;
}
static int F_29 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
struct V_37 * V_18 = F_23 ( V_2 -> V_23 ) ;
return F_27 ( & V_40 , V_2 , V_4 , V_5 , V_6 ,
F_28 ( V_9 ) ,
& V_18 -> V_39 , & V_18 -> V_25 ) ;
}
static int T_3 F_30 ( void )
{
const char * V_41 ;
if ( ! F_31 ( V_42 ) || ! F_31 ( V_43 ) ) {
F_32 ( L_1 ) ;
return - V_44 ;
}
if ( ! F_33 ( V_45 | V_46 ,
& V_41 ) ) {
F_32 ( L_2 , V_41 ) ;
return - V_44 ;
}
return F_34 ( V_47 , F_35 ( V_47 ) ) ;
}
static void T_4 F_36 ( void )
{
F_37 ( V_47 , F_35 ( V_47 ) ) ;
}
