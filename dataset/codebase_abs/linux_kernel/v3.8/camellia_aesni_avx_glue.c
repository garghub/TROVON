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
if ( V_6 >= V_14 * V_22 ) {
F_19 ( V_24 -> V_24 , V_21 , V_21 ) ;
V_21 += V_22 * V_14 ;
V_6 -= V_22 * V_14 ;
}
while ( V_6 >= V_26 * V_22 ) {
F_20 ( V_24 -> V_24 , V_21 , V_21 ) ;
V_21 += V_22 * V_26 ;
V_6 -= V_22 * V_26 ;
}
for ( V_25 = 0 ; V_25 < V_6 / V_22 ; V_25 ++ , V_21 += V_22 )
V_9 ( V_24 -> V_24 , V_21 , V_21 ) ;
}
static void F_21 ( void * V_20 , T_1 * V_21 , unsigned int V_6 )
{
const unsigned int V_22 = V_13 ;
struct V_23 * V_24 = V_20 ;
int V_25 ;
V_24 -> V_12 = F_11 ( V_24 -> V_12 , V_6 ) ;
if ( V_6 >= V_14 * V_22 ) {
F_22 ( V_24 -> V_24 , V_21 , V_21 ) ;
V_21 += V_22 * V_14 ;
V_6 -= V_22 * V_14 ;
}
while ( V_6 >= V_26 * V_22 ) {
F_23 ( V_24 -> V_24 , V_21 , V_21 ) ;
V_21 += V_22 * V_26 ;
V_6 -= V_22 * V_26 ;
}
for ( V_25 = 0 ; V_25 < V_6 / V_22 ; V_25 ++ , V_21 += V_22 )
F_24 ( V_24 -> V_24 , V_21 , V_21 ) ;
}
static int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
struct V_27 * V_24 = F_26 ( V_2 -> V_16 ) ;
T_2 V_28 [ V_14 ] ;
struct V_23 V_29 = {
. V_24 = & V_24 -> V_30 ,
. V_12 = false ,
} ;
struct V_31 V_32 = {
. V_33 = V_28 ,
. V_34 = sizeof( V_28 ) ,
. V_35 = & V_24 -> V_36 ,
. V_29 = & V_29 ,
. V_37 = F_18 ,
} ;
int V_38 ;
V_2 -> V_39 &= ~ V_40 ;
V_38 = F_27 ( V_2 , V_4 , V_5 , V_6 , & V_32 ) ;
F_13 ( V_29 . V_12 ) ;
return V_38 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
struct V_27 * V_24 = F_26 ( V_2 -> V_16 ) ;
T_2 V_28 [ V_14 ] ;
struct V_23 V_29 = {
. V_24 = & V_24 -> V_30 ,
. V_12 = false ,
} ;
struct V_31 V_32 = {
. V_33 = V_28 ,
. V_34 = sizeof( V_28 ) ,
. V_35 = & V_24 -> V_36 ,
. V_29 = & V_29 ,
. V_37 = F_21 ,
} ;
int V_38 ;
V_2 -> V_39 &= ~ V_40 ;
V_38 = F_27 ( V_2 , V_4 , V_5 , V_6 , & V_32 ) ;
F_13 ( V_29 . V_12 ) ;
return V_38 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
struct V_41 * V_24 = F_26 ( V_2 -> V_16 ) ;
T_2 V_28 [ V_14 ] ;
struct V_23 V_29 = {
. V_24 = & V_24 -> V_29 ,
. V_12 = false ,
} ;
struct V_42 V_32 = {
. V_33 = V_28 ,
. V_34 = sizeof( V_28 ) ,
. V_43 = & V_24 -> V_43 ,
. V_44 = F_30 ( V_9 ) ,
. V_29 = & V_29 ,
. V_37 = F_18 ,
} ;
int V_38 ;
V_2 -> V_39 &= ~ V_40 ;
V_38 = F_31 ( V_2 , V_4 , V_5 , V_6 , & V_32 ) ;
F_13 ( V_29 . V_12 ) ;
return V_38 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , unsigned int V_6 )
{
struct V_41 * V_24 = F_26 ( V_2 -> V_16 ) ;
T_2 V_28 [ V_14 ] ;
struct V_23 V_29 = {
. V_24 = & V_24 -> V_29 ,
. V_12 = false ,
} ;
struct V_42 V_32 = {
. V_33 = V_28 ,
. V_34 = sizeof( V_28 ) ,
. V_43 = & V_24 -> V_43 ,
. V_44 = F_30 ( V_9 ) ,
. V_29 = & V_29 ,
. V_37 = F_21 ,
} ;
int V_38 ;
V_2 -> V_39 &= ~ V_40 ;
V_38 = F_31 ( V_2 , V_4 , V_5 , V_6 , & V_32 ) ;
F_13 ( V_29 . V_12 ) ;
return V_38 ;
}
static int T_3 F_33 ( void )
{
T_4 V_45 ;
if ( ! V_46 || ! V_47 || ! V_48 ) {
F_34 ( L_1 ) ;
return - V_49 ;
}
V_45 = F_35 ( V_50 ) ;
if ( ( V_45 & ( V_51 | V_52 ) ) != ( V_51 | V_52 ) ) {
F_34 ( L_2 ) ;
return - V_49 ;
}
return F_36 ( V_53 , F_37 ( V_53 ) ) ;
}
static void T_5 F_38 ( void )
{
F_39 ( V_53 , F_37 ( V_53 ) ) ;
}
