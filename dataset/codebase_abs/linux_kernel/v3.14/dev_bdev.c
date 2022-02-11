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
static void F_11 ( struct V_5 * V_5 , int V_23 )
{
const int V_25 = F_12 ( V_26 , & V_5 -> V_27 ) ;
struct V_6 * V_28 ;
int V_29 ;
struct V_20 * V_21 = V_5 -> V_30 ;
struct F_5 * V_31 = F_5 ( V_21 ) ;
F_13 ( ! V_25 ) ;
F_13 ( V_23 ) ;
F_14 (bvec, bio, i) {
F_15 ( V_28 -> V_9 ) ;
F_16 ( V_28 -> V_9 ) ;
}
F_17 ( V_5 ) ;
if ( F_18 ( & V_31 -> V_32 ) )
F_19 ( & V_33 ) ;
}
static int F_20 ( struct V_20 * V_21 , T_1 V_34 , T_2 V_17 ,
T_3 V_35 )
{
struct F_5 * V_31 = F_5 ( V_21 ) ;
struct V_36 * V_37 = V_31 -> V_38 -> V_39 ;
struct V_5 * V_5 ;
struct V_1 * V_1 ;
unsigned int V_40 ;
int V_29 ;
V_40 = F_21 ( V_35 , ( T_3 ) F_22 ( V_31 -> V_22 ) ) ;
V_5 = F_23 ( V_41 , V_40 ) ;
F_13 ( ! V_5 ) ;
for ( V_29 = 0 ; V_29 < V_35 ; V_29 ++ ) {
if ( V_29 >= V_40 ) {
V_5 -> V_13 = V_29 ;
V_5 -> V_15 . V_18 = V_29 * V_11 ;
V_5 -> V_14 = V_31 -> V_22 ;
V_5 -> V_15 . V_16 = V_34 >> 9 ;
V_5 -> V_30 = V_21 ;
V_5 -> V_42 = F_11 ;
F_24 ( & V_31 -> V_32 ) ;
F_25 ( V_43 , V_5 ) ;
V_34 += V_29 * V_11 ;
V_17 += V_29 ;
V_35 -= V_29 ;
V_29 = 0 ;
V_5 = F_23 ( V_41 , V_40 ) ;
F_13 ( ! V_5 ) ;
}
V_1 = F_26 ( V_37 , V_17 + V_29 ) ;
F_13 ( ! V_1 ) ;
V_5 -> V_8 [ V_29 ] . V_9 = V_1 ;
V_5 -> V_8 [ V_29 ] . V_10 = V_11 ;
V_5 -> V_8 [ V_29 ] . V_12 = 0 ;
F_13 ( F_27 ( V_1 ) ) ;
F_28 ( V_1 ) ;
F_10 ( V_1 ) ;
}
V_5 -> V_13 = V_35 ;
V_5 -> V_15 . V_18 = V_35 * V_11 ;
V_5 -> V_14 = V_31 -> V_22 ;
V_5 -> V_15 . V_16 = V_34 >> 9 ;
V_5 -> V_30 = V_21 ;
V_5 -> V_42 = F_11 ;
F_24 ( & V_31 -> V_32 ) ;
F_25 ( V_43 , V_5 ) ;
return 0 ;
}
static void F_29 ( struct V_20 * V_21 , T_1 V_34 , T_3 V_44 )
{
struct F_5 * V_31 = F_5 ( V_21 ) ;
int V_45 ;
F_13 ( V_31 -> V_46 & V_47 ) ;
if ( V_44 == 0 ) {
return;
}
V_45 = V_34 & ( V_11 - 1 ) ;
if ( V_45 ) {
V_34 -= V_45 ;
V_44 += V_45 ;
}
V_44 = F_30 ( V_44 ) ;
F_20 ( V_21 , V_34 , V_34 >> V_48 , V_44 >> V_48 ) ;
}
static void F_31 ( struct V_5 * V_5 , int V_23 )
{
const int V_25 = F_12 ( V_26 , & V_5 -> V_27 ) ;
struct V_20 * V_21 = V_5 -> V_30 ;
struct F_5 * V_31 = F_5 ( V_21 ) ;
F_13 ( ! V_25 ) ;
F_13 ( V_23 ) ;
F_13 ( V_5 -> V_13 == 0 ) ;
F_17 ( V_5 ) ;
if ( F_18 ( & V_31 -> V_32 ) )
F_19 ( & V_33 ) ;
}
static int F_32 ( struct V_20 * V_21 , T_1 V_34 , T_2 V_17 ,
T_3 V_35 )
{
struct F_5 * V_31 = F_5 ( V_21 ) ;
struct V_5 * V_5 ;
unsigned int V_40 ;
int V_29 ;
V_40 = F_21 ( V_35 , ( T_3 ) F_22 ( V_31 -> V_22 ) ) ;
V_5 = F_23 ( V_41 , V_40 ) ;
F_13 ( ! V_5 ) ;
for ( V_29 = 0 ; V_29 < V_35 ; V_29 ++ ) {
if ( V_29 >= V_40 ) {
V_5 -> V_13 = V_29 ;
V_5 -> V_15 . V_18 = V_29 * V_11 ;
V_5 -> V_14 = V_31 -> V_22 ;
V_5 -> V_15 . V_16 = V_34 >> 9 ;
V_5 -> V_30 = V_21 ;
V_5 -> V_42 = F_31 ;
F_24 ( & V_31 -> V_32 ) ;
F_25 ( V_43 , V_5 ) ;
V_34 += V_29 * V_11 ;
V_17 += V_29 ;
V_35 -= V_29 ;
V_29 = 0 ;
V_5 = F_23 ( V_41 , V_40 ) ;
F_13 ( ! V_5 ) ;
}
V_5 -> V_8 [ V_29 ] . V_9 = V_31 -> V_49 ;
V_5 -> V_8 [ V_29 ] . V_10 = V_11 ;
V_5 -> V_8 [ V_29 ] . V_12 = 0 ;
}
V_5 -> V_13 = V_35 ;
V_5 -> V_15 . V_18 = V_35 * V_11 ;
V_5 -> V_14 = V_31 -> V_22 ;
V_5 -> V_15 . V_16 = V_34 >> 9 ;
V_5 -> V_30 = V_21 ;
V_5 -> V_42 = F_31 ;
F_24 ( & V_31 -> V_32 ) ;
F_25 ( V_43 , V_5 ) ;
return 0 ;
}
static int F_33 ( struct V_20 * V_21 , T_4 V_50 , T_3 V_44 ,
int V_51 )
{
struct F_5 * V_31 = F_5 ( V_21 ) ;
F_13 ( V_50 & ( V_11 - 1 ) ) ;
F_13 ( V_44 & ( V_11 - 1 ) ) ;
if ( V_31 -> V_46 & V_47 )
return - V_52 ;
if ( V_51 ) {
F_32 ( V_21 , V_50 , V_50 >> V_48 , V_44 >> V_48 ) ;
}
return 0 ;
}
static void F_34 ( struct V_20 * V_21 )
{
struct F_5 * V_31 = F_5 ( V_21 ) ;
F_35 ( V_33 , F_36 ( & V_31 -> V_32 ) == 0 ) ;
}
static struct V_1 * F_37 ( struct V_20 * V_21 , T_1 * V_34 )
{
struct F_5 * V_31 = F_5 ( V_21 ) ;
struct V_36 * V_37 = V_31 -> V_38 -> V_39 ;
T_5 * V_53 = F_4 ;
* V_34 = 0 ;
return F_38 ( V_37 , 0 , V_53 , V_21 ) ;
}
static struct V_1 * F_39 ( struct V_20 * V_21 , T_1 * V_34 )
{
struct F_5 * V_31 = F_5 ( V_21 ) ;
struct V_36 * V_37 = V_31 -> V_38 -> V_39 ;
T_5 * V_53 = F_4 ;
T_1 V_54 = ( V_31 -> V_22 -> V_55 -> V_56 & ~ 0xfffULL ) - 0x1000 ;
T_2 V_17 = V_54 >> V_48 ;
* V_34 = V_54 ;
return F_38 ( V_37 , V_17 , V_53 , V_21 ) ;
}
static int F_40 ( struct V_20 * V_21 , struct V_1 * V_1 )
{
struct V_2 * V_3 = F_5 ( V_21 ) -> V_22 ;
return F_1 ( V_1 , V_3 , V_43 ) ;
}
static void F_41 ( struct F_5 * V_57 )
{
F_42 ( V_57 -> V_22 , V_58 | V_59 | V_60 ) ;
}
static int F_43 ( struct V_20 * V_21 , T_1 V_34 )
{
return 0 ;
}
int F_44 ( struct F_5 * V_61 , struct V_62 * type ,
const char * V_63 )
{
struct V_2 * V_3 ;
V_3 = F_45 ( V_63 , V_58 | V_59 | V_60 ,
type ) ;
if ( F_46 ( V_3 ) )
return F_47 ( V_3 ) ;
if ( F_48 ( V_3 -> V_64 ) == V_65 ) {
int V_66 = F_49 ( V_3 -> V_64 ) ;
F_42 ( V_3 , V_58 | V_59 | V_60 ) ;
return F_50 ( V_61 , V_66 ) ;
}
V_61 -> V_22 = V_3 ;
V_61 -> V_67 = NULL ;
V_61 -> V_68 = & V_69 ;
return 0 ;
}
