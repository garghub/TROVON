static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , int V_4 )
{
struct V_5 V_5 ;
struct V_6 V_6 ;
F_2 ( & V_5 ) ;
V_5 . V_7 = 1 ;
V_5 . V_8 = & V_6 ;
V_6 . V_9 = V_1 ;
V_6 . V_10 = V_11 ;
V_6 . V_12 = 0 ;
V_5 . V_13 = 1 ;
V_5 . V_14 = V_3 ;
V_5 . V_15 . V_16 = V_1 -> V_17 * ( V_11 >> 9 ) ;
V_5 . V_15 . V_18 = V_11 ;
return F_3 ( V_4 , & V_5 ) ;
}
static int F_4 ( void * V_19 , struct V_1 * V_1 )
{
struct V_20 * V_21 = V_19 ;
struct V_2 * V_3 = F_5 ( V_21 ) -> V_22 ;
int V_23 ;
V_23 = F_1 ( V_1 , V_3 , V_24 ) ;
if ( V_23 ) {
F_6 ( V_1 ) ;
F_7 ( V_1 ) ;
} else {
F_8 ( V_1 ) ;
F_9 ( V_1 ) ;
}
F_10 ( V_1 ) ;
return V_23 ;
}
static void F_11 ( struct V_5 * V_5 )
{
struct V_6 * V_25 ;
int V_26 ;
struct V_20 * V_21 = V_5 -> V_27 ;
struct F_5 * V_28 = F_5 ( V_21 ) ;
F_12 ( V_5 -> V_29 ) ;
F_13 (bvec, bio, i) {
F_14 ( V_25 -> V_9 ) ;
F_15 ( V_25 -> V_9 ) ;
}
F_16 ( V_5 ) ;
if ( F_17 ( & V_28 -> V_30 ) )
F_18 ( & V_31 ) ;
}
static int F_19 ( struct V_20 * V_21 , T_1 V_32 , T_2 V_17 ,
T_3 V_33 )
{
struct F_5 * V_28 = F_5 ( V_21 ) ;
struct V_34 * V_35 = V_28 -> V_36 -> V_37 ;
struct V_5 * V_5 ;
struct V_1 * V_1 ;
unsigned int V_38 ;
int V_26 ;
V_38 = F_20 ( T_3 , V_33 , V_39 ) ;
V_5 = F_21 ( V_40 , V_38 ) ;
F_12 ( ! V_5 ) ;
for ( V_26 = 0 ; V_26 < V_33 ; V_26 ++ ) {
if ( V_26 >= V_38 ) {
V_5 -> V_13 = V_26 ;
V_5 -> V_15 . V_18 = V_26 * V_11 ;
V_5 -> V_14 = V_28 -> V_22 ;
V_5 -> V_15 . V_16 = V_32 >> 9 ;
V_5 -> V_27 = V_21 ;
V_5 -> V_41 = F_11 ;
F_22 ( & V_28 -> V_30 ) ;
F_23 ( V_42 , V_5 ) ;
V_32 += V_26 * V_11 ;
V_17 += V_26 ;
V_33 -= V_26 ;
V_26 = 0 ;
V_5 = F_21 ( V_40 , V_38 ) ;
F_12 ( ! V_5 ) ;
}
V_1 = F_24 ( V_35 , V_17 + V_26 ) ;
F_12 ( ! V_1 ) ;
V_5 -> V_8 [ V_26 ] . V_9 = V_1 ;
V_5 -> V_8 [ V_26 ] . V_10 = V_11 ;
V_5 -> V_8 [ V_26 ] . V_12 = 0 ;
F_12 ( F_25 ( V_1 ) ) ;
F_26 ( V_1 ) ;
F_10 ( V_1 ) ;
}
V_5 -> V_13 = V_33 ;
V_5 -> V_15 . V_18 = V_33 * V_11 ;
V_5 -> V_14 = V_28 -> V_22 ;
V_5 -> V_15 . V_16 = V_32 >> 9 ;
V_5 -> V_27 = V_21 ;
V_5 -> V_41 = F_11 ;
F_22 ( & V_28 -> V_30 ) ;
F_23 ( V_42 , V_5 ) ;
return 0 ;
}
static void F_27 ( struct V_20 * V_21 , T_1 V_32 , T_3 V_43 )
{
struct F_5 * V_28 = F_5 ( V_21 ) ;
int V_44 ;
F_12 ( V_28 -> V_45 & V_46 ) ;
if ( V_43 == 0 ) {
return;
}
V_44 = V_32 & ( V_11 - 1 ) ;
if ( V_44 ) {
V_32 -= V_44 ;
V_43 += V_44 ;
}
V_43 = F_28 ( V_43 ) ;
F_19 ( V_21 , V_32 , V_32 >> V_47 , V_43 >> V_47 ) ;
}
static void F_29 ( struct V_5 * V_5 )
{
struct V_20 * V_21 = V_5 -> V_27 ;
struct F_5 * V_28 = F_5 ( V_21 ) ;
F_12 ( V_5 -> V_29 ) ;
F_12 ( V_5 -> V_13 == 0 ) ;
F_16 ( V_5 ) ;
if ( F_17 ( & V_28 -> V_30 ) )
F_18 ( & V_31 ) ;
}
static int F_30 ( struct V_20 * V_21 , T_1 V_32 , T_2 V_17 ,
T_3 V_33 )
{
struct F_5 * V_28 = F_5 ( V_21 ) ;
struct V_5 * V_5 ;
unsigned int V_38 ;
int V_26 ;
V_38 = F_20 ( T_3 , V_33 , V_39 ) ;
V_5 = F_21 ( V_40 , V_38 ) ;
F_12 ( ! V_5 ) ;
for ( V_26 = 0 ; V_26 < V_33 ; V_26 ++ ) {
if ( V_26 >= V_38 ) {
V_5 -> V_13 = V_26 ;
V_5 -> V_15 . V_18 = V_26 * V_11 ;
V_5 -> V_14 = V_28 -> V_22 ;
V_5 -> V_15 . V_16 = V_32 >> 9 ;
V_5 -> V_27 = V_21 ;
V_5 -> V_41 = F_29 ;
F_22 ( & V_28 -> V_30 ) ;
F_23 ( V_42 , V_5 ) ;
V_32 += V_26 * V_11 ;
V_17 += V_26 ;
V_33 -= V_26 ;
V_26 = 0 ;
V_5 = F_21 ( V_40 , V_38 ) ;
F_12 ( ! V_5 ) ;
}
V_5 -> V_8 [ V_26 ] . V_9 = V_28 -> V_48 ;
V_5 -> V_8 [ V_26 ] . V_10 = V_11 ;
V_5 -> V_8 [ V_26 ] . V_12 = 0 ;
}
V_5 -> V_13 = V_33 ;
V_5 -> V_15 . V_18 = V_33 * V_11 ;
V_5 -> V_14 = V_28 -> V_22 ;
V_5 -> V_15 . V_16 = V_32 >> 9 ;
V_5 -> V_27 = V_21 ;
V_5 -> V_41 = F_29 ;
F_22 ( & V_28 -> V_30 ) ;
F_23 ( V_42 , V_5 ) ;
return 0 ;
}
static int F_31 ( struct V_20 * V_21 , T_4 V_49 , T_3 V_43 ,
int V_50 )
{
struct F_5 * V_28 = F_5 ( V_21 ) ;
F_12 ( V_49 & ( V_11 - 1 ) ) ;
F_12 ( V_43 & ( V_11 - 1 ) ) ;
if ( V_28 -> V_45 & V_46 )
return - V_51 ;
if ( V_50 ) {
F_30 ( V_21 , V_49 , V_49 >> V_47 , V_43 >> V_47 ) ;
}
return 0 ;
}
static void F_32 ( struct V_20 * V_21 )
{
struct F_5 * V_28 = F_5 ( V_21 ) ;
F_33 ( V_31 , F_34 ( & V_28 -> V_30 ) == 0 ) ;
}
static struct V_1 * F_35 ( struct V_20 * V_21 , T_1 * V_32 )
{
struct F_5 * V_28 = F_5 ( V_21 ) ;
struct V_34 * V_35 = V_28 -> V_36 -> V_37 ;
T_5 * V_52 = F_4 ;
* V_32 = 0 ;
return F_36 ( V_35 , 0 , V_52 , V_21 ) ;
}
static struct V_1 * F_37 ( struct V_20 * V_21 , T_1 * V_32 )
{
struct F_5 * V_28 = F_5 ( V_21 ) ;
struct V_34 * V_35 = V_28 -> V_36 -> V_37 ;
T_5 * V_52 = F_4 ;
T_1 V_53 = ( V_28 -> V_22 -> V_54 -> V_55 & ~ 0xfffULL ) - 0x1000 ;
T_2 V_17 = V_53 >> V_47 ;
* V_32 = V_53 ;
return F_36 ( V_35 , V_17 , V_52 , V_21 ) ;
}
static int F_38 ( struct V_20 * V_21 , struct V_1 * V_1 )
{
struct V_2 * V_3 = F_5 ( V_21 ) -> V_22 ;
return F_1 ( V_1 , V_3 , V_42 ) ;
}
static void F_39 ( struct F_5 * V_56 )
{
F_40 ( V_56 -> V_22 , V_57 | V_58 | V_59 ) ;
}
static int F_41 ( struct V_20 * V_21 , T_1 V_32 )
{
return 0 ;
}
int F_42 ( struct F_5 * V_60 , struct V_61 * type ,
const char * V_62 )
{
struct V_2 * V_3 ;
V_3 = F_43 ( V_62 , V_57 | V_58 | V_59 ,
type ) ;
if ( F_44 ( V_3 ) )
return F_45 ( V_3 ) ;
if ( F_46 ( V_3 -> V_63 ) == V_64 ) {
int V_65 = F_47 ( V_3 -> V_63 ) ;
F_40 ( V_3 , V_57 | V_58 | V_59 ) ;
return F_48 ( V_60 , V_65 ) ;
}
V_60 -> V_22 = V_3 ;
V_60 -> V_66 = NULL ;
V_60 -> V_67 = & V_68 ;
return 0 ;
}
