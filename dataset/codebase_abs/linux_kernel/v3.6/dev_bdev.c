static void F_1 ( struct V_1 * V_1 , int V_2 )
{
F_2 ( (struct V_3 * ) V_1 -> V_4 ) ;
}
static int F_3 ( struct V_5 * V_5 , struct V_6 * V_7 , int V_8 )
{
struct V_1 V_1 ;
struct V_9 V_9 ;
struct V_3 F_2 ;
F_4 ( & V_1 ) ;
V_1 . V_10 = 1 ;
V_1 . V_11 = & V_9 ;
V_9 . V_12 = V_5 ;
V_9 . V_13 = V_14 ;
V_9 . V_15 = 0 ;
V_1 . V_16 = 1 ;
V_1 . V_17 = 0 ;
V_1 . V_18 = V_14 ;
V_1 . V_19 = V_7 ;
V_1 . V_20 = V_5 -> V_21 * ( V_14 >> 9 ) ;
F_5 ( & F_2 ) ;
V_1 . V_4 = & F_2 ;
V_1 . V_22 = F_1 ;
F_6 ( V_8 , & V_1 ) ;
F_7 ( & F_2 ) ;
return F_8 ( V_23 , & V_1 . V_24 ) ? 0 : - V_25 ;
}
static int F_9 ( void * V_26 , struct V_5 * V_5 )
{
struct V_27 * V_28 = V_26 ;
struct V_6 * V_7 = F_10 ( V_28 ) -> V_29 ;
int V_2 ;
V_2 = F_3 ( V_5 , V_7 , V_30 ) ;
if ( V_2 ) {
F_11 ( V_5 ) ;
F_12 ( V_5 ) ;
} else {
F_13 ( V_5 ) ;
F_14 ( V_5 ) ;
}
F_15 ( V_5 ) ;
return V_2 ;
}
static void F_16 ( struct V_1 * V_1 , int V_2 )
{
const int V_31 = F_8 ( V_23 , & V_1 -> V_24 ) ;
struct V_9 * V_32 = V_1 -> V_11 + V_1 -> V_16 - 1 ;
struct V_27 * V_28 = V_1 -> V_4 ;
struct F_10 * V_33 = F_10 ( V_28 ) ;
struct V_5 * V_5 ;
F_17 ( ! V_31 ) ;
F_17 ( V_2 ) ;
F_17 ( V_1 -> V_16 == 0 ) ;
do {
V_5 = V_32 -> V_12 ;
if ( -- V_32 >= V_1 -> V_11 )
F_18 ( & V_32 -> V_12 -> V_34 ) ;
F_19 ( V_5 ) ;
F_20 ( V_5 ) ;
} while ( V_32 >= V_1 -> V_11 );
F_21 ( V_1 ) ;
if ( F_22 ( & V_33 -> V_35 ) )
F_23 ( & V_36 ) ;
}
static int F_24 ( struct V_27 * V_28 , T_1 V_37 , T_2 V_21 ,
T_3 V_38 )
{
struct F_10 * V_33 = F_10 ( V_28 ) ;
struct V_39 * V_40 = V_33 -> V_41 -> V_42 ;
struct V_1 * V_1 ;
struct V_5 * V_5 ;
unsigned int V_43 ;
int V_44 ;
V_43 = F_25 ( V_38 , ( T_3 ) F_26 ( V_33 -> V_29 ) ) ;
V_1 = F_27 ( V_45 , V_43 ) ;
F_17 ( ! V_1 ) ;
for ( V_44 = 0 ; V_44 < V_38 ; V_44 ++ ) {
if ( V_44 >= V_43 ) {
V_1 -> V_16 = V_44 ;
V_1 -> V_17 = 0 ;
V_1 -> V_18 = V_44 * V_14 ;
V_1 -> V_19 = V_33 -> V_29 ;
V_1 -> V_20 = V_37 >> 9 ;
V_1 -> V_4 = V_28 ;
V_1 -> V_22 = F_16 ;
F_28 ( & V_33 -> V_35 ) ;
F_6 ( V_46 , V_1 ) ;
V_37 += V_44 * V_14 ;
V_21 += V_44 ;
V_38 -= V_44 ;
V_44 = 0 ;
V_1 = F_27 ( V_45 , V_43 ) ;
F_17 ( ! V_1 ) ;
}
V_5 = F_29 ( V_40 , V_21 + V_44 ) ;
F_17 ( ! V_5 ) ;
V_1 -> V_11 [ V_44 ] . V_12 = V_5 ;
V_1 -> V_11 [ V_44 ] . V_13 = V_14 ;
V_1 -> V_11 [ V_44 ] . V_15 = 0 ;
F_17 ( F_30 ( V_5 ) ) ;
F_31 ( V_5 ) ;
F_15 ( V_5 ) ;
}
V_1 -> V_16 = V_38 ;
V_1 -> V_17 = 0 ;
V_1 -> V_18 = V_38 * V_14 ;
V_1 -> V_19 = V_33 -> V_29 ;
V_1 -> V_20 = V_37 >> 9 ;
V_1 -> V_4 = V_28 ;
V_1 -> V_22 = F_16 ;
F_28 ( & V_33 -> V_35 ) ;
F_6 ( V_46 , V_1 ) ;
return 0 ;
}
static void F_32 ( struct V_27 * V_28 , T_1 V_37 , T_3 V_47 )
{
struct F_10 * V_33 = F_10 ( V_28 ) ;
int V_48 ;
F_17 ( V_33 -> V_49 & V_50 ) ;
if ( V_47 == 0 ) {
return;
}
V_48 = V_37 & ( V_14 - 1 ) ;
if ( V_48 ) {
V_37 -= V_48 ;
V_47 += V_48 ;
}
V_47 = F_33 ( V_47 ) ;
F_24 ( V_28 , V_37 , V_37 >> V_51 , V_47 >> V_51 ) ;
}
static void F_34 ( struct V_1 * V_1 , int V_2 )
{
const int V_31 = F_8 ( V_23 , & V_1 -> V_24 ) ;
struct V_27 * V_28 = V_1 -> V_4 ;
struct F_10 * V_33 = F_10 ( V_28 ) ;
F_17 ( ! V_31 ) ;
F_17 ( V_2 ) ;
F_17 ( V_1 -> V_16 == 0 ) ;
F_21 ( V_1 ) ;
if ( F_22 ( & V_33 -> V_35 ) )
F_23 ( & V_36 ) ;
}
static int F_35 ( struct V_27 * V_28 , T_1 V_37 , T_2 V_21 ,
T_3 V_38 )
{
struct F_10 * V_33 = F_10 ( V_28 ) ;
struct V_1 * V_1 ;
unsigned int V_43 ;
int V_44 ;
V_43 = F_25 ( V_38 , ( T_3 ) F_26 ( V_33 -> V_29 ) ) ;
V_1 = F_27 ( V_45 , V_43 ) ;
F_17 ( ! V_1 ) ;
for ( V_44 = 0 ; V_44 < V_38 ; V_44 ++ ) {
if ( V_44 >= V_43 ) {
V_1 -> V_16 = V_44 ;
V_1 -> V_17 = 0 ;
V_1 -> V_18 = V_44 * V_14 ;
V_1 -> V_19 = V_33 -> V_29 ;
V_1 -> V_20 = V_37 >> 9 ;
V_1 -> V_4 = V_28 ;
V_1 -> V_22 = F_34 ;
F_28 ( & V_33 -> V_35 ) ;
F_6 ( V_46 , V_1 ) ;
V_37 += V_44 * V_14 ;
V_21 += V_44 ;
V_38 -= V_44 ;
V_44 = 0 ;
V_1 = F_27 ( V_45 , V_43 ) ;
F_17 ( ! V_1 ) ;
}
V_1 -> V_11 [ V_44 ] . V_12 = V_33 -> V_52 ;
V_1 -> V_11 [ V_44 ] . V_13 = V_14 ;
V_1 -> V_11 [ V_44 ] . V_15 = 0 ;
}
V_1 -> V_16 = V_38 ;
V_1 -> V_17 = 0 ;
V_1 -> V_18 = V_38 * V_14 ;
V_1 -> V_19 = V_33 -> V_29 ;
V_1 -> V_20 = V_37 >> 9 ;
V_1 -> V_4 = V_28 ;
V_1 -> V_22 = F_34 ;
F_28 ( & V_33 -> V_35 ) ;
F_6 ( V_46 , V_1 ) ;
return 0 ;
}
static int F_36 ( struct V_27 * V_28 , T_4 V_53 , T_3 V_47 ,
int V_54 )
{
struct F_10 * V_33 = F_10 ( V_28 ) ;
F_17 ( V_53 & ( V_14 - 1 ) ) ;
F_17 ( V_47 & ( V_14 - 1 ) ) ;
if ( V_33 -> V_49 & V_50 )
return - V_55 ;
if ( V_54 ) {
F_35 ( V_28 , V_53 , V_53 >> V_51 , V_47 >> V_51 ) ;
}
return 0 ;
}
static void F_37 ( struct V_27 * V_28 )
{
struct F_10 * V_33 = F_10 ( V_28 ) ;
F_38 ( V_36 , F_39 ( & V_33 -> V_35 ) == 0 ) ;
}
static struct V_5 * F_40 ( struct V_27 * V_28 , T_1 * V_37 )
{
struct F_10 * V_33 = F_10 ( V_28 ) ;
struct V_39 * V_40 = V_33 -> V_41 -> V_42 ;
T_5 * V_56 = F_9 ;
* V_37 = 0 ;
return F_41 ( V_40 , 0 , V_56 , V_28 ) ;
}
static struct V_5 * F_42 ( struct V_27 * V_28 , T_1 * V_37 )
{
struct F_10 * V_33 = F_10 ( V_28 ) ;
struct V_39 * V_40 = V_33 -> V_41 -> V_42 ;
T_5 * V_56 = F_9 ;
T_1 V_57 = ( V_33 -> V_29 -> V_58 -> V_59 & ~ 0xfffULL ) - 0x1000 ;
T_2 V_21 = V_57 >> V_51 ;
* V_37 = V_57 ;
return F_41 ( V_40 , V_21 , V_56 , V_28 ) ;
}
static int F_43 ( struct V_27 * V_28 , struct V_5 * V_5 )
{
struct V_6 * V_7 = F_10 ( V_28 ) -> V_29 ;
return F_3 ( V_5 , V_7 , V_46 ) ;
}
static void F_44 ( struct F_10 * V_60 )
{
F_45 ( V_60 -> V_29 , V_61 | V_62 | V_63 ) ;
}
static int F_46 ( struct V_27 * V_28 , T_1 V_37 )
{
return 0 ;
}
int F_47 ( struct F_10 * V_64 , struct V_65 * type ,
const char * V_66 )
{
struct V_6 * V_7 ;
V_7 = F_48 ( V_66 , V_61 | V_62 | V_63 ,
type ) ;
if ( F_49 ( V_7 ) )
return F_50 ( V_7 ) ;
if ( F_51 ( V_7 -> V_67 ) == V_68 ) {
int V_69 = F_52 ( V_7 -> V_67 ) ;
F_45 ( V_7 , V_61 | V_62 | V_63 ) ;
return F_53 ( V_64 , V_69 ) ;
}
V_64 -> V_29 = V_7 ;
V_64 -> V_70 = NULL ;
V_64 -> V_71 = & V_72 ;
return 0 ;
}
