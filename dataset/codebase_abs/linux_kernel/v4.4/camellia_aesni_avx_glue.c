void F_1 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
F_2 ( V_1 , V_2 , V_3 , V_4 ,
F_3 ( V_5 ) ) ;
}
void F_4 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
F_2 ( V_1 , V_2 , V_3 , V_4 ,
F_3 ( V_6 ) ) ;
}
static int F_5 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
return F_6 ( & V_11 , V_8 , V_2 , V_3 , V_10 ) ;
}
static int F_7 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
return F_6 ( & V_12 , V_8 , V_2 , V_3 , V_10 ) ;
}
static int F_8 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
return F_9 ( F_3 ( V_5 ) , V_8 ,
V_2 , V_3 , V_10 ) ;
}
static int F_10 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
return F_11 ( & V_13 , V_8 , V_2 , V_3 ,
V_10 ) ;
}
static int F_12 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
return F_13 ( & V_14 , V_8 , V_2 , V_3 , V_10 ) ;
}
static inline bool F_14 ( bool V_15 , unsigned int V_10 )
{
return F_15 ( V_16 ,
V_17 , NULL , V_15 ,
V_10 ) ;
}
static inline void F_16 ( bool V_15 )
{
F_17 ( V_15 ) ;
}
static int F_18 ( struct V_18 * V_19 , const T_3 * V_20 ,
unsigned int V_21 )
{
return F_19 ( F_20 ( V_19 ) , V_20 , V_21 ,
& V_19 -> V_22 ) ;
}
static void F_21 ( void * V_23 , T_3 * V_24 , unsigned int V_10 )
{
const unsigned int V_25 = V_16 ;
struct V_26 * V_1 = V_23 ;
int V_27 ;
V_1 -> V_15 = F_14 ( V_1 -> V_15 , V_10 ) ;
if ( V_10 >= V_17 * V_25 ) {
F_22 ( V_1 -> V_1 , V_24 , V_24 ) ;
V_24 += V_25 * V_17 ;
V_10 -= V_25 * V_17 ;
}
while ( V_10 >= V_28 * V_25 ) {
F_23 ( V_1 -> V_1 , V_24 , V_24 ) ;
V_24 += V_25 * V_28 ;
V_10 -= V_25 * V_28 ;
}
for ( V_27 = 0 ; V_27 < V_10 / V_25 ; V_27 ++ , V_24 += V_25 )
V_5 ( V_1 -> V_1 , V_24 , V_24 ) ;
}
static void F_24 ( void * V_23 , T_3 * V_24 , unsigned int V_10 )
{
const unsigned int V_25 = V_16 ;
struct V_26 * V_1 = V_23 ;
int V_27 ;
V_1 -> V_15 = F_14 ( V_1 -> V_15 , V_10 ) ;
if ( V_10 >= V_17 * V_25 ) {
F_25 ( V_1 -> V_1 , V_24 , V_24 ) ;
V_24 += V_25 * V_17 ;
V_10 -= V_25 * V_17 ;
}
while ( V_10 >= V_28 * V_25 ) {
F_26 ( V_1 -> V_1 , V_24 , V_24 ) ;
V_24 += V_25 * V_28 ;
V_10 -= V_25 * V_28 ;
}
for ( V_27 = 0 ; V_27 < V_10 / V_25 ; V_27 ++ , V_24 += V_25 )
V_6 ( V_1 -> V_1 , V_24 , V_24 ) ;
}
static int F_27 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
struct V_29 * V_1 = F_28 ( V_8 -> V_19 ) ;
T_4 V_30 [ V_17 ] ;
struct V_26 V_31 = {
. V_1 = & V_1 -> V_32 ,
. V_15 = false ,
} ;
struct V_33 V_34 = {
. V_35 = V_30 ,
. V_36 = sizeof( V_30 ) ,
. V_37 = & V_1 -> V_38 ,
. V_31 = & V_31 ,
. V_39 = F_21 ,
} ;
int V_40 ;
V_8 -> V_41 &= ~ V_42 ;
V_40 = F_29 ( V_8 , V_2 , V_3 , V_10 , & V_34 ) ;
F_16 ( V_31 . V_15 ) ;
return V_40 ;
}
static int F_30 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
struct V_29 * V_1 = F_28 ( V_8 -> V_19 ) ;
T_4 V_30 [ V_17 ] ;
struct V_26 V_31 = {
. V_1 = & V_1 -> V_32 ,
. V_15 = false ,
} ;
struct V_33 V_34 = {
. V_35 = V_30 ,
. V_36 = sizeof( V_30 ) ,
. V_37 = & V_1 -> V_38 ,
. V_31 = & V_31 ,
. V_39 = F_24 ,
} ;
int V_40 ;
V_8 -> V_41 &= ~ V_42 ;
V_40 = F_29 ( V_8 , V_2 , V_3 , V_10 , & V_34 ) ;
F_16 ( V_31 . V_15 ) ;
return V_40 ;
}
static int F_31 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
struct V_43 * V_1 = F_28 ( V_8 -> V_19 ) ;
return F_32 ( & V_44 , V_8 , V_2 , V_3 , V_10 ,
F_33 ( V_5 ) ,
& V_1 -> V_45 , & V_1 -> V_31 ) ;
}
static int F_34 ( struct V_7 * V_8 , struct V_9 * V_2 ,
struct V_9 * V_3 , unsigned int V_10 )
{
struct V_43 * V_1 = F_28 ( V_8 -> V_19 ) ;
return F_32 ( & V_46 , V_8 , V_2 , V_3 , V_10 ,
F_33 ( V_5 ) ,
& V_1 -> V_45 , & V_1 -> V_31 ) ;
}
static int T_5 F_35 ( void )
{
const char * V_47 ;
if ( ! V_48 || ! V_49 || ! V_50 ) {
F_36 ( L_1 ) ;
return - V_51 ;
}
if ( ! F_37 ( V_52 | V_53 ,
& V_47 ) ) {
F_36 ( L_2 , V_47 ) ;
return - V_51 ;
}
return F_38 ( V_54 , F_39 ( V_54 ) ) ;
}
static void T_6 F_40 ( void )
{
F_41 ( V_54 , F_39 ( V_54 ) ) ;
}
