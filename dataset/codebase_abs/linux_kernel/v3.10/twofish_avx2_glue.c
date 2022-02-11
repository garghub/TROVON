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
return F_14 ( V_15 , 8 , NULL , V_14 , V_8 ) ;
}
static inline void F_15 ( bool V_14 )
{
F_16 ( V_14 ) ;
}
static void F_17 ( void * V_16 , T_1 * V_17 , unsigned int V_8 )
{
const unsigned int V_18 = V_15 ;
struct V_19 * V_2 = V_16 ;
int V_20 ;
V_2 -> V_14 = F_13 ( V_2 -> V_14 , V_8 ) ;
while ( V_8 >= V_21 * V_18 ) {
F_18 ( V_2 -> V_2 , V_17 , V_17 ) ;
V_17 += V_18 * V_21 ;
V_8 -= V_18 * V_21 ;
}
while ( V_8 >= 8 * V_18 ) {
F_19 ( V_2 -> V_2 , V_17 , V_17 ) ;
V_17 += V_18 * 8 ;
V_8 -= V_18 * 8 ;
}
while ( V_8 >= 3 * V_18 ) {
F_1 ( V_2 -> V_2 , V_17 , V_17 ) ;
V_17 += V_18 * 3 ;
V_8 -= V_18 * 3 ;
}
for ( V_20 = 0 ; V_20 < V_8 / V_18 ; V_20 ++ , V_17 += V_18 )
V_11 ( V_2 -> V_2 , V_17 , V_17 ) ;
}
static void F_20 ( void * V_16 , T_1 * V_17 , unsigned int V_8 )
{
const unsigned int V_18 = V_15 ;
struct V_19 * V_2 = V_16 ;
int V_20 ;
V_2 -> V_14 = F_13 ( V_2 -> V_14 , V_8 ) ;
while ( V_8 >= V_21 * V_18 ) {
F_21 ( V_2 -> V_2 , V_17 , V_17 ) ;
V_17 += V_18 * V_21 ;
V_8 -= V_18 * V_21 ;
}
while ( V_8 >= 8 * V_18 ) {
F_22 ( V_2 -> V_2 , V_17 , V_17 ) ;
V_17 += V_18 * 8 ;
V_8 -= V_18 * 8 ;
}
while ( V_8 >= 3 * V_18 ) {
F_23 ( V_2 -> V_2 , V_17 , V_17 ) ;
V_17 += V_18 * 3 ;
V_8 -= V_18 * 3 ;
}
for ( V_20 = 0 ; V_20 < V_8 / V_18 ; V_20 ++ , V_17 += V_18 )
F_24 ( V_2 -> V_2 , V_17 , V_17 ) ;
}
static int F_25 ( struct V_5 * V_6 , struct V_7 * V_3 ,
struct V_7 * V_4 , unsigned int V_8 )
{
struct V_22 * V_2 = F_26 ( V_6 -> V_23 ) ;
T_2 V_24 [ V_21 ] ;
struct V_19 V_25 = {
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
V_33 = F_27 ( V_6 , V_3 , V_4 , V_8 , & V_27 ) ;
F_15 ( V_25 . V_14 ) ;
return V_33 ;
}
static int F_28 ( struct V_5 * V_6 , struct V_7 * V_3 ,
struct V_7 * V_4 , unsigned int V_8 )
{
struct V_22 * V_2 = F_26 ( V_6 -> V_23 ) ;
T_2 V_24 [ V_21 ] ;
struct V_19 V_25 = {
. V_2 = & V_2 -> V_1 ,
. V_14 = false ,
} ;
struct V_26 V_27 = {
. V_28 = V_24 ,
. V_29 = sizeof( V_24 ) ,
. V_30 = & V_2 -> V_31 ,
. V_25 = & V_25 ,
. V_32 = F_20 ,
} ;
int V_33 ;
V_6 -> V_34 &= ~ V_35 ;
V_33 = F_27 ( V_6 , V_3 , V_4 , V_8 , & V_27 ) ;
F_15 ( V_25 . V_14 ) ;
return V_33 ;
}
static int F_29 ( struct V_5 * V_6 , struct V_7 * V_3 ,
struct V_7 * V_4 , unsigned int V_8 )
{
struct V_36 * V_2 = F_26 ( V_6 -> V_23 ) ;
return F_30 ( & V_37 , V_6 , V_3 , V_4 , V_8 ,
F_31 ( V_11 ) ,
& V_2 -> V_38 , & V_2 -> V_25 ) ;
}
static int F_32 ( struct V_5 * V_6 , struct V_7 * V_3 ,
struct V_7 * V_4 , unsigned int V_8 )
{
struct V_36 * V_2 = F_26 ( V_6 -> V_23 ) ;
return F_30 ( & V_39 , V_6 , V_3 , V_4 , V_8 ,
F_31 ( V_11 ) ,
& V_2 -> V_38 , & V_2 -> V_25 ) ;
}
static int T_3 F_33 ( void )
{
T_4 V_40 ;
if ( ! V_41 || ! V_42 ) {
F_34 ( L_1 ) ;
return - V_43 ;
}
V_40 = F_35 ( V_44 ) ;
if ( ( V_40 & ( V_45 | V_46 ) ) != ( V_45 | V_46 ) ) {
F_34 ( L_2 ) ;
return - V_43 ;
}
return F_36 ( V_47 , F_37 ( V_47 ) ) ;
}
static void T_5 F_38 ( void )
{
F_39 ( V_47 , F_37 ( V_47 ) ) ;
}
