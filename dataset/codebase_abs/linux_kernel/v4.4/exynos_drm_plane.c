static int F_1 ( int V_1 , unsigned V_2 , unsigned V_3 )
{
int V_4 = V_1 + V_2 ;
int V_5 = 0 ;
if ( V_1 <= 0 ) {
if ( V_4 > 0 )
V_5 = F_2 ( unsigned , V_4 , V_3 ) ;
} else if ( V_1 <= V_3 ) {
V_5 = F_2 ( unsigned , V_3 - V_1 , V_2 ) ;
}
return V_5 ;
}
static void F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
int V_12 , int V_13 ,
unsigned int V_14 , unsigned int V_15 ,
T_1 V_16 , T_1 V_17 ,
T_1 V_18 , T_1 V_19 )
{
struct V_20 * V_21 = F_4 ( V_7 ) ;
struct V_22 * V_23 = & V_9 -> V_24 -> V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
V_26 = F_1 ( V_12 , V_14 , V_23 -> V_28 ) ;
V_27 = F_1 ( V_13 , V_15 , V_23 -> V_29 ) ;
if ( V_12 < 0 ) {
if ( V_26 )
V_16 -= V_12 ;
V_12 = 0 ;
}
if ( V_13 < 0 ) {
if ( V_27 )
V_17 -= V_13 ;
V_13 = 0 ;
}
V_21 -> V_30 = ( V_18 << 16 ) / V_14 ;
V_21 -> V_31 = ( V_19 << 16 ) / V_15 ;
V_21 -> V_16 = V_16 ;
V_21 -> V_17 = V_17 ;
V_21 -> V_18 = ( V_26 * V_21 -> V_30 ) >> 16 ;
V_21 -> V_19 = ( V_27 * V_21 -> V_31 ) >> 16 ;
V_21 -> V_12 = V_12 ;
V_21 -> V_13 = V_13 ;
V_21 -> V_14 = V_26 ;
V_21 -> V_15 = V_27 ;
F_5 ( L_1 ,
V_21 -> V_12 , V_21 -> V_13 ,
V_21 -> V_14 , V_21 -> V_15 ) ;
V_7 -> V_9 = V_9 ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_32 * V_24 )
{
struct V_20 * V_21 = F_4 ( V_7 ) ;
int V_33 ;
int V_34 ;
if ( ! V_24 -> V_11 )
return 0 ;
V_33 = F_7 ( V_24 -> V_11 -> V_35 ) ;
for ( V_34 = 0 ; V_34 < V_33 ; V_34 ++ ) {
struct V_36 * V_37 =
F_8 ( V_24 -> V_11 , V_34 ) ;
if ( ! V_37 ) {
F_5 ( L_2 ) ;
return - V_38 ;
}
V_21 -> V_39 [ V_34 ] = V_37 -> V_39 +
V_24 -> V_11 -> V_40 [ V_34 ] ;
F_5 ( L_3 ,
V_34 , ( unsigned long ) V_21 -> V_39 [ V_34 ] ) ;
}
return 0 ;
}
static void F_9 ( struct V_6 * V_7 ,
struct V_32 * V_41 )
{
struct V_32 * V_24 = V_7 -> V_24 ;
struct V_42 * V_43 = F_10 ( V_24 -> V_9 ) ;
struct V_20 * V_21 = F_4 ( V_7 ) ;
if ( ! V_24 -> V_9 )
return;
F_3 ( V_7 , V_24 -> V_9 , V_24 -> V_11 ,
V_24 -> V_12 , V_24 -> V_13 ,
V_24 -> V_14 , V_24 -> V_15 ,
V_24 -> V_16 >> 16 , V_24 -> V_17 >> 16 ,
V_24 -> V_18 >> 16 , V_24 -> V_19 >> 16 ) ;
V_21 -> V_44 = V_24 -> V_11 ;
if ( V_43 -> V_45 -> V_46 )
V_43 -> V_45 -> V_46 ( V_43 , V_21 ) ;
}
static void F_11 ( struct V_6 * V_7 ,
struct V_32 * V_41 )
{
struct V_20 * V_21 = F_4 ( V_7 ) ;
struct V_42 * V_43 = F_10 ( V_41 -> V_9 ) ;
if ( ! V_41 -> V_9 )
return;
if ( V_43 -> V_45 -> V_47 )
V_43 -> V_45 -> V_47 ( V_43 ,
V_21 ) ;
}
static void F_12 ( struct V_6 * V_7 ,
unsigned int V_48 )
{
struct V_49 * V_50 = V_7 -> V_50 ;
struct V_51 * V_52 = V_50 -> V_53 ;
struct V_54 * V_55 ;
V_55 = V_52 -> V_56 ;
if ( ! V_55 ) {
V_55 = F_13 ( V_50 , V_57 ,
L_4 , 0 , V_58 - 1 ) ;
if ( ! V_55 )
return;
V_52 -> V_56 = V_55 ;
}
F_14 ( & V_7 -> V_59 , V_55 , V_48 ) ;
}
enum V_60 F_15 ( unsigned int V_48 ,
unsigned int V_61 )
{
if ( V_48 == V_62 )
return V_63 ;
else if ( V_48 == V_61 )
return V_64 ;
else
return V_65 ;
}
int F_16 ( struct V_49 * V_50 ,
struct V_20 * V_21 ,
unsigned long V_66 , enum V_60 type ,
const T_1 * V_67 , unsigned int V_68 ,
unsigned int V_48 )
{
int V_69 ;
V_69 = F_17 ( V_50 , & V_21 -> V_59 , V_66 ,
& V_70 , V_67 , V_68 ,
type ) ;
if ( V_69 ) {
F_18 ( L_5 ) ;
return V_69 ;
}
F_19 ( & V_21 -> V_59 , & V_71 ) ;
V_21 -> V_48 = V_48 ;
if ( type == V_65 )
F_12 ( & V_21 -> V_59 , V_48 ) ;
return 0 ;
}
