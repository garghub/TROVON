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
F_3 ( & V_5 , V_4 , 0 ) ;
return F_4 ( & V_5 ) ;
}
static int F_5 ( void * V_19 , struct V_1 * V_1 )
{
struct V_20 * V_21 = V_19 ;
struct V_2 * V_3 = F_6 ( V_21 ) -> V_22 ;
int V_23 ;
V_23 = F_1 ( V_1 , V_3 , V_24 ) ;
if ( V_23 ) {
F_7 ( V_1 ) ;
F_8 ( V_1 ) ;
} else {
F_9 ( V_1 ) ;
F_10 ( V_1 ) ;
}
F_11 ( V_1 ) ;
return V_23 ;
}
static void F_12 ( struct V_5 * V_5 )
{
struct V_6 * V_25 ;
int V_26 ;
struct V_20 * V_21 = V_5 -> V_27 ;
struct F_6 * V_28 = F_6 ( V_21 ) ;
F_13 ( V_5 -> V_29 ) ;
F_14 (bvec, bio, i) {
F_15 ( V_25 -> V_9 ) ;
F_16 ( V_25 -> V_9 ) ;
}
F_17 ( V_5 ) ;
if ( F_18 ( & V_28 -> V_30 ) )
F_19 ( & V_31 ) ;
}
static int F_20 ( struct V_20 * V_21 , T_1 V_32 , T_2 V_17 ,
T_3 V_33 )
{
struct F_6 * V_28 = F_6 ( V_21 ) ;
struct V_34 * V_35 = V_28 -> V_36 -> V_37 ;
struct V_5 * V_5 ;
struct V_1 * V_1 ;
unsigned int V_38 ;
int V_26 ;
V_38 = F_21 ( T_3 , V_33 , V_39 ) ;
V_5 = F_22 ( V_40 , V_38 ) ;
F_13 ( ! V_5 ) ;
for ( V_26 = 0 ; V_26 < V_33 ; V_26 ++ ) {
if ( V_26 >= V_38 ) {
V_5 -> V_13 = V_26 ;
V_5 -> V_15 . V_18 = V_26 * V_11 ;
V_5 -> V_14 = V_28 -> V_22 ;
V_5 -> V_15 . V_16 = V_32 >> 9 ;
V_5 -> V_27 = V_21 ;
V_5 -> V_41 = F_12 ;
F_3 ( V_5 , V_42 , 0 ) ;
F_23 ( & V_28 -> V_30 ) ;
F_24 ( V_5 ) ;
V_32 += V_26 * V_11 ;
V_17 += V_26 ;
V_33 -= V_26 ;
V_26 = 0 ;
V_5 = F_22 ( V_40 , V_38 ) ;
F_13 ( ! V_5 ) ;
}
V_1 = F_25 ( V_35 , V_17 + V_26 ) ;
F_13 ( ! V_1 ) ;
V_5 -> V_8 [ V_26 ] . V_9 = V_1 ;
V_5 -> V_8 [ V_26 ] . V_10 = V_11 ;
V_5 -> V_8 [ V_26 ] . V_12 = 0 ;
F_13 ( F_26 ( V_1 ) ) ;
F_27 ( V_1 ) ;
F_11 ( V_1 ) ;
}
V_5 -> V_13 = V_33 ;
V_5 -> V_15 . V_18 = V_33 * V_11 ;
V_5 -> V_14 = V_28 -> V_22 ;
V_5 -> V_15 . V_16 = V_32 >> 9 ;
V_5 -> V_27 = V_21 ;
V_5 -> V_41 = F_12 ;
F_3 ( V_5 , V_42 , 0 ) ;
F_23 ( & V_28 -> V_30 ) ;
F_24 ( V_5 ) ;
return 0 ;
}
static void F_28 ( struct V_20 * V_21 , T_1 V_32 , T_3 V_43 )
{
struct F_6 * V_28 = F_6 ( V_21 ) ;
int V_44 ;
F_13 ( V_28 -> V_45 & V_46 ) ;
if ( V_43 == 0 ) {
return;
}
V_44 = V_32 & ( V_11 - 1 ) ;
if ( V_44 ) {
V_32 -= V_44 ;
V_43 += V_44 ;
}
V_43 = F_29 ( V_43 ) ;
F_20 ( V_21 , V_32 , V_32 >> V_47 , V_43 >> V_47 ) ;
}
static void F_30 ( struct V_5 * V_5 )
{
struct V_20 * V_21 = V_5 -> V_27 ;
struct F_6 * V_28 = F_6 ( V_21 ) ;
F_13 ( V_5 -> V_29 ) ;
F_13 ( V_5 -> V_13 == 0 ) ;
F_17 ( V_5 ) ;
if ( F_18 ( & V_28 -> V_30 ) )
F_19 ( & V_31 ) ;
}
static int F_31 ( struct V_20 * V_21 , T_1 V_32 , T_2 V_17 ,
T_3 V_33 )
{
struct F_6 * V_28 = F_6 ( V_21 ) ;
struct V_5 * V_5 ;
unsigned int V_38 ;
int V_26 ;
V_38 = F_21 ( T_3 , V_33 , V_39 ) ;
V_5 = F_22 ( V_40 , V_38 ) ;
F_13 ( ! V_5 ) ;
for ( V_26 = 0 ; V_26 < V_33 ; V_26 ++ ) {
if ( V_26 >= V_38 ) {
V_5 -> V_13 = V_26 ;
V_5 -> V_15 . V_18 = V_26 * V_11 ;
V_5 -> V_14 = V_28 -> V_22 ;
V_5 -> V_15 . V_16 = V_32 >> 9 ;
V_5 -> V_27 = V_21 ;
V_5 -> V_41 = F_30 ;
F_3 ( V_5 , V_42 , 0 ) ;
F_23 ( & V_28 -> V_30 ) ;
F_24 ( V_5 ) ;
V_32 += V_26 * V_11 ;
V_17 += V_26 ;
V_33 -= V_26 ;
V_26 = 0 ;
V_5 = F_22 ( V_40 , V_38 ) ;
F_13 ( ! V_5 ) ;
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
V_5 -> V_41 = F_30 ;
F_3 ( V_5 , V_42 , 0 ) ;
F_23 ( & V_28 -> V_30 ) ;
F_24 ( V_5 ) ;
return 0 ;
}
static int F_32 ( struct V_20 * V_21 , T_4 V_49 , T_3 V_43 ,
int V_50 )
{
struct F_6 * V_28 = F_6 ( V_21 ) ;
F_13 ( V_49 & ( V_11 - 1 ) ) ;
F_13 ( V_43 & ( V_11 - 1 ) ) ;
if ( V_28 -> V_45 & V_46 )
return - V_51 ;
if ( V_50 ) {
F_31 ( V_21 , V_49 , V_49 >> V_47 , V_43 >> V_47 ) ;
}
return 0 ;
}
static void F_33 ( struct V_20 * V_21 )
{
struct F_6 * V_28 = F_6 ( V_21 ) ;
F_34 ( V_31 , F_35 ( & V_28 -> V_30 ) == 0 ) ;
}
static struct V_1 * F_36 ( struct V_20 * V_21 , T_1 * V_32 )
{
struct F_6 * V_28 = F_6 ( V_21 ) ;
struct V_34 * V_35 = V_28 -> V_36 -> V_37 ;
T_5 * V_52 = F_5 ;
* V_32 = 0 ;
return F_37 ( V_35 , 0 , V_52 , V_21 ) ;
}
static struct V_1 * F_38 ( struct V_20 * V_21 , T_1 * V_32 )
{
struct F_6 * V_28 = F_6 ( V_21 ) ;
struct V_34 * V_35 = V_28 -> V_36 -> V_37 ;
T_5 * V_52 = F_5 ;
T_1 V_53 = ( V_28 -> V_22 -> V_54 -> V_55 & ~ 0xfffULL ) - 0x1000 ;
T_2 V_17 = V_53 >> V_47 ;
* V_32 = V_53 ;
return F_37 ( V_35 , V_17 , V_52 , V_21 ) ;
}
static int F_39 ( struct V_20 * V_21 , struct V_1 * V_1 )
{
struct V_2 * V_3 = F_6 ( V_21 ) -> V_22 ;
return F_1 ( V_1 , V_3 , V_56 ) ;
}
static void F_40 ( struct F_6 * V_57 )
{
F_41 ( V_57 -> V_22 , V_58 | V_59 | V_60 ) ;
}
static int F_42 ( struct V_20 * V_21 , T_1 V_32 )
{
return 0 ;
}
int F_43 ( struct F_6 * V_61 , struct V_62 * type ,
const char * V_63 )
{
struct V_2 * V_3 ;
V_3 = F_44 ( V_63 , V_58 | V_59 | V_60 ,
type ) ;
if ( F_45 ( V_3 ) )
return F_46 ( V_3 ) ;
if ( F_47 ( V_3 -> V_64 ) == V_65 ) {
int V_66 = F_48 ( V_3 -> V_64 ) ;
F_41 ( V_3 , V_58 | V_59 | V_60 ) ;
return F_49 ( V_61 , V_66 ) ;
}
V_61 -> V_22 = V_3 ;
V_61 -> V_67 = NULL ;
V_61 -> V_68 = & V_69 ;
return 0 ;
}
