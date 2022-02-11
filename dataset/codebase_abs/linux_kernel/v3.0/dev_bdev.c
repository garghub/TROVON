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
V_1 . V_10 = & V_9 ;
V_9 . V_11 = V_5 ;
V_9 . V_12 = V_13 ;
V_9 . V_14 = 0 ;
V_1 . V_15 = 1 ;
V_1 . V_16 = 0 ;
V_1 . V_17 = V_13 ;
V_1 . V_18 = V_7 ;
V_1 . V_19 = V_5 -> V_20 * ( V_13 >> 9 ) ;
F_5 ( & F_2 ) ;
V_1 . V_4 = & F_2 ;
V_1 . V_21 = F_1 ;
F_6 ( V_8 , & V_1 ) ;
F_7 ( & F_2 ) ;
return F_8 ( V_22 , & V_1 . V_23 ) ? 0 : - V_24 ;
}
static int F_9 ( void * V_25 , struct V_5 * V_5 )
{
struct V_26 * V_27 = V_25 ;
struct V_6 * V_7 = F_10 ( V_27 ) -> V_28 ;
int V_2 ;
V_2 = F_3 ( V_5 , V_7 , V_29 ) ;
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
const int V_30 = F_8 ( V_22 , & V_1 -> V_23 ) ;
struct V_9 * V_31 = V_1 -> V_10 + V_1 -> V_15 - 1 ;
struct V_26 * V_27 = V_1 -> V_4 ;
struct F_10 * V_32 = F_10 ( V_27 ) ;
struct V_5 * V_5 ;
F_17 ( ! V_30 ) ;
F_17 ( V_2 ) ;
F_17 ( V_1 -> V_15 == 0 ) ;
do {
V_5 = V_31 -> V_11 ;
if ( -- V_31 >= V_1 -> V_10 )
F_18 ( & V_31 -> V_11 -> V_33 ) ;
F_19 ( V_5 ) ;
F_20 ( V_5 ) ;
} while ( V_31 >= V_1 -> V_10 );
F_21 ( V_1 ) ;
if ( F_22 ( & V_32 -> V_34 ) )
F_23 ( & V_35 ) ;
}
static int F_24 ( struct V_26 * V_27 , T_1 V_36 , T_2 V_20 ,
T_3 V_37 )
{
struct F_10 * V_32 = F_10 ( V_27 ) ;
struct V_38 * V_39 = V_32 -> V_40 -> V_41 ;
struct V_1 * V_1 ;
struct V_5 * V_5 ;
struct V_42 * V_43 = F_25 ( V_27 -> V_28 ) ;
unsigned int V_44 = F_26 ( V_43 ) >> ( V_45 - 9 ) ;
int V_46 ;
if ( V_44 > V_47 )
V_44 = V_47 ;
V_1 = F_27 ( V_48 , V_44 ) ;
F_17 ( ! V_1 ) ;
for ( V_46 = 0 ; V_46 < V_37 ; V_46 ++ ) {
if ( V_46 >= V_44 ) {
V_1 -> V_15 = V_46 ;
V_1 -> V_16 = 0 ;
V_1 -> V_17 = V_46 * V_13 ;
V_1 -> V_18 = V_32 -> V_28 ;
V_1 -> V_19 = V_36 >> 9 ;
V_1 -> V_4 = V_27 ;
V_1 -> V_21 = F_16 ;
F_28 ( & V_32 -> V_34 ) ;
F_6 ( V_49 , V_1 ) ;
V_36 += V_46 * V_13 ;
V_20 += V_46 ;
V_37 -= V_46 ;
V_46 = 0 ;
V_1 = F_27 ( V_48 , V_44 ) ;
F_17 ( ! V_1 ) ;
}
V_5 = F_29 ( V_39 , V_20 + V_46 ) ;
F_17 ( ! V_5 ) ;
V_1 -> V_10 [ V_46 ] . V_11 = V_5 ;
V_1 -> V_10 [ V_46 ] . V_12 = V_13 ;
V_1 -> V_10 [ V_46 ] . V_14 = 0 ;
F_17 ( F_30 ( V_5 ) ) ;
F_31 ( V_5 ) ;
F_15 ( V_5 ) ;
}
V_1 -> V_15 = V_37 ;
V_1 -> V_16 = 0 ;
V_1 -> V_17 = V_37 * V_13 ;
V_1 -> V_18 = V_32 -> V_28 ;
V_1 -> V_19 = V_36 >> 9 ;
V_1 -> V_4 = V_27 ;
V_1 -> V_21 = F_16 ;
F_28 ( & V_32 -> V_34 ) ;
F_6 ( V_49 , V_1 ) ;
return 0 ;
}
static void F_32 ( struct V_26 * V_27 , T_1 V_36 , T_3 V_50 )
{
struct F_10 * V_32 = F_10 ( V_27 ) ;
int V_51 ;
F_17 ( V_32 -> V_52 & V_53 ) ;
if ( V_50 == 0 ) {
return;
}
V_51 = V_36 & ( V_13 - 1 ) ;
if ( V_51 ) {
V_36 -= V_51 ;
V_50 += V_51 ;
}
V_50 = F_33 ( V_50 ) ;
F_24 ( V_27 , V_36 , V_36 >> V_45 , V_50 >> V_45 ) ;
}
static void F_34 ( struct V_1 * V_1 , int V_2 )
{
const int V_30 = F_8 ( V_22 , & V_1 -> V_23 ) ;
struct V_26 * V_27 = V_1 -> V_4 ;
struct F_10 * V_32 = F_10 ( V_27 ) ;
F_17 ( ! V_30 ) ;
F_17 ( V_2 ) ;
F_17 ( V_1 -> V_15 == 0 ) ;
F_21 ( V_1 ) ;
if ( F_22 ( & V_32 -> V_34 ) )
F_23 ( & V_35 ) ;
}
static int F_35 ( struct V_26 * V_27 , T_1 V_36 , T_2 V_20 ,
T_3 V_37 )
{
struct F_10 * V_32 = F_10 ( V_27 ) ;
struct V_1 * V_1 ;
struct V_42 * V_43 = F_25 ( V_27 -> V_28 ) ;
unsigned int V_44 = F_26 ( V_43 ) >> ( V_45 - 9 ) ;
int V_46 ;
if ( V_44 > V_47 )
V_44 = V_47 ;
V_1 = F_27 ( V_48 , V_44 ) ;
F_17 ( ! V_1 ) ;
for ( V_46 = 0 ; V_46 < V_37 ; V_46 ++ ) {
if ( V_46 >= V_44 ) {
V_1 -> V_15 = V_46 ;
V_1 -> V_16 = 0 ;
V_1 -> V_17 = V_46 * V_13 ;
V_1 -> V_18 = V_32 -> V_28 ;
V_1 -> V_19 = V_36 >> 9 ;
V_1 -> V_4 = V_27 ;
V_1 -> V_21 = F_34 ;
F_28 ( & V_32 -> V_34 ) ;
F_6 ( V_49 , V_1 ) ;
V_36 += V_46 * V_13 ;
V_20 += V_46 ;
V_37 -= V_46 ;
V_46 = 0 ;
V_1 = F_27 ( V_48 , V_44 ) ;
F_17 ( ! V_1 ) ;
}
V_1 -> V_10 [ V_46 ] . V_11 = V_32 -> V_54 ;
V_1 -> V_10 [ V_46 ] . V_12 = V_13 ;
V_1 -> V_10 [ V_46 ] . V_14 = 0 ;
}
V_1 -> V_15 = V_37 ;
V_1 -> V_16 = 0 ;
V_1 -> V_17 = V_37 * V_13 ;
V_1 -> V_18 = V_32 -> V_28 ;
V_1 -> V_19 = V_36 >> 9 ;
V_1 -> V_4 = V_27 ;
V_1 -> V_21 = F_34 ;
F_28 ( & V_32 -> V_34 ) ;
F_6 ( V_49 , V_1 ) ;
return 0 ;
}
static int F_36 ( struct V_26 * V_27 , T_4 V_55 , T_3 V_50 ,
int V_56 )
{
struct F_10 * V_32 = F_10 ( V_27 ) ;
F_17 ( V_55 & ( V_13 - 1 ) ) ;
F_17 ( V_50 & ( V_13 - 1 ) ) ;
if ( V_32 -> V_52 & V_53 )
return - V_57 ;
if ( V_56 ) {
F_35 ( V_27 , V_55 , V_55 >> V_45 , V_50 >> V_45 ) ;
}
return 0 ;
}
static void F_37 ( struct V_26 * V_27 )
{
struct F_10 * V_32 = F_10 ( V_27 ) ;
F_38 ( V_35 , F_39 ( & V_32 -> V_34 ) == 0 ) ;
}
static struct V_5 * F_40 ( struct V_26 * V_27 , T_1 * V_36 )
{
struct F_10 * V_32 = F_10 ( V_27 ) ;
struct V_38 * V_39 = V_32 -> V_40 -> V_41 ;
T_5 * V_58 = F_9 ;
* V_36 = 0 ;
return F_41 ( V_39 , 0 , V_58 , V_27 ) ;
}
static struct V_5 * F_42 ( struct V_26 * V_27 , T_1 * V_36 )
{
struct F_10 * V_32 = F_10 ( V_27 ) ;
struct V_38 * V_39 = V_32 -> V_40 -> V_41 ;
T_5 * V_58 = F_9 ;
T_1 V_59 = ( V_32 -> V_28 -> V_60 -> V_61 & ~ 0xfffULL ) - 0x1000 ;
T_2 V_20 = V_59 >> V_45 ;
* V_36 = V_59 ;
return F_41 ( V_39 , V_20 , V_58 , V_27 ) ;
}
static int F_43 ( struct V_26 * V_27 , struct V_5 * V_5 )
{
struct V_6 * V_7 = F_10 ( V_27 ) -> V_28 ;
return F_3 ( V_5 , V_7 , V_49 ) ;
}
static void F_44 ( struct F_10 * V_62 )
{
F_45 ( V_62 -> V_28 , V_63 | V_64 | V_65 ) ;
}
static int F_46 ( struct V_26 * V_27 , T_1 V_36 )
{
return 0 ;
}
int F_47 ( struct F_10 * V_66 , struct V_67 * type ,
const char * V_68 )
{
struct V_6 * V_7 ;
V_7 = F_48 ( V_68 , V_63 | V_64 | V_65 ,
type ) ;
if ( F_49 ( V_7 ) )
return F_50 ( V_7 ) ;
if ( F_51 ( V_7 -> V_69 ) == V_70 ) {
int V_71 = F_52 ( V_7 -> V_69 ) ;
F_45 ( V_7 , V_63 | V_64 | V_65 ) ;
return F_53 ( V_66 , V_71 ) ;
}
V_66 -> V_28 = V_7 ;
V_66 -> V_72 = NULL ;
V_66 -> V_73 = & V_74 ;
return 0 ;
}
