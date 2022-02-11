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
int F_3 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_10 * V_11 , int V_12 , int V_13 ,
unsigned int V_14 , unsigned int V_15 ,
T_1 V_16 , T_1 V_17 ,
T_1 V_18 , T_1 V_19 )
{
struct V_20 * V_20 = F_4 ( V_7 ) ;
struct V_21 * V_22 = & V_20 -> V_22 ;
unsigned int V_23 ;
unsigned int V_24 ;
int V_25 ;
int V_26 ;
V_25 = F_5 ( V_11 ) ;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
struct V_27 * V_28 = F_6 ( V_11 , V_26 ) ;
if ( ! V_28 ) {
F_7 ( L_1 ) ;
return - V_29 ;
}
V_22 -> V_30 [ V_26 ] = V_28 -> V_30 ;
F_8 ( L_2 ,
V_26 , ( unsigned long ) V_22 -> V_30 [ V_26 ] ) ;
}
V_23 = F_1 ( V_12 , V_14 , V_9 -> V_31 . V_32 ) ;
V_24 = F_1 ( V_13 , V_15 , V_9 -> V_31 . V_33 ) ;
if ( V_12 < 0 ) {
if ( V_23 )
V_16 -= V_12 ;
V_12 = 0 ;
}
if ( V_13 < 0 ) {
if ( V_24 )
V_17 -= V_13 ;
V_13 = 0 ;
}
V_22 -> V_34 = V_16 ;
V_22 -> V_35 = V_17 ;
V_22 -> V_36 = V_11 -> V_37 ;
V_22 -> V_38 = V_11 -> V_39 ;
V_22 -> V_40 = V_18 ;
V_22 -> V_41 = V_19 ;
V_22 -> V_42 = V_11 -> V_43 ;
V_22 -> V_44 = V_11 -> V_45 [ 0 ] ;
V_22 -> V_46 = V_11 -> V_46 ;
V_22 -> V_12 = V_12 ;
V_22 -> V_13 = V_13 ;
V_22 -> V_47 = V_23 ;
V_22 -> V_48 = V_24 ;
V_22 -> V_49 = V_9 -> V_31 . V_32 ;
V_22 -> V_50 = V_9 -> V_31 . V_33 ;
V_22 -> V_51 = V_9 -> V_31 . V_52 ;
V_22 -> V_53 = V_9 -> V_31 . V_54 ;
F_8 ( L_3 ,
V_22 -> V_12 , V_22 -> V_13 ,
V_22 -> V_47 , V_22 -> V_48 ) ;
F_9 ( V_9 , V_22 , V_55 ) ;
return 0 ;
}
void F_10 ( struct V_6 * V_7 )
{
struct V_20 * V_20 = F_4 ( V_7 ) ;
struct V_21 * V_22 = & V_20 -> V_22 ;
F_9 ( V_7 -> V_9 , & V_22 -> V_56 ,
V_57 ) ;
}
void F_11 ( struct V_6 * V_7 , int V_31 )
{
struct V_20 * V_20 = F_4 ( V_7 ) ;
struct V_21 * V_22 = & V_20 -> V_22 ;
if ( V_31 == V_58 ) {
if ( V_20 -> V_59 )
return;
F_9 ( V_7 -> V_9 , & V_22 -> V_56 ,
V_60 ) ;
V_20 -> V_59 = true ;
} else {
if ( ! V_20 -> V_59 )
return;
F_9 ( V_7 -> V_9 , & V_22 -> V_56 ,
V_61 ) ;
V_20 -> V_59 = false ;
}
}
static int
F_12 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_10 * V_11 , int V_12 , int V_13 ,
unsigned int V_14 , unsigned int V_15 ,
T_1 V_16 , T_1 V_17 ,
T_1 V_18 , T_1 V_19 )
{
int V_62 ;
V_62 = F_3 ( V_7 , V_9 , V_11 , V_12 , V_13 ,
V_14 , V_15 , V_16 >> 16 , V_17 >> 16 ,
V_18 >> 16 , V_19 >> 16 ) ;
if ( V_62 < 0 )
return V_62 ;
V_7 -> V_9 = V_9 ;
F_10 ( V_7 ) ;
F_11 ( V_7 , V_58 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 )
{
F_11 ( V_7 , V_63 ) ;
return 0 ;
}
static void F_14 ( struct V_6 * V_7 )
{
struct V_20 * V_20 = F_4 ( V_7 ) ;
F_13 ( V_7 ) ;
F_15 ( V_7 ) ;
F_16 ( V_20 ) ;
}
static int F_17 ( struct V_6 * V_7 ,
struct V_64 * V_65 ,
T_2 V_66 )
{
struct V_67 * V_68 = V_7 -> V_68 ;
struct V_20 * V_20 = F_4 ( V_7 ) ;
struct V_69 * V_70 = V_68 -> V_71 ;
if ( V_65 == V_70 -> V_72 ) {
V_20 -> V_22 . V_56 = V_66 ;
return 0 ;
}
return - V_73 ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_67 * V_68 = V_7 -> V_68 ;
struct V_69 * V_70 = V_68 -> V_71 ;
struct V_64 * V_74 ;
V_74 = V_70 -> V_72 ;
if ( ! V_74 ) {
V_74 = F_19 ( V_68 , 0 , L_4 , 0 ,
V_75 - 1 ) ;
if ( ! V_74 )
return;
V_70 -> V_72 = V_74 ;
}
F_20 ( & V_7 -> V_76 , V_74 , 0 ) ;
}
struct V_6 * F_21 ( struct V_67 * V_68 ,
unsigned int V_77 , bool V_78 )
{
struct V_20 * V_20 ;
int V_79 ;
V_20 = F_22 ( sizeof( struct V_20 ) , V_80 ) ;
if ( ! V_20 )
return NULL ;
V_79 = F_23 ( V_68 , & V_20 -> V_76 , V_77 ,
& V_81 , V_82 , F_24 ( V_82 ) ,
V_78 ) ;
if ( V_79 ) {
F_25 ( L_5 ) ;
F_16 ( V_20 ) ;
return NULL ;
}
if ( V_78 )
V_20 -> V_22 . V_56 = V_83 ;
else
F_18 ( & V_20 -> V_76 ) ;
return & V_20 -> V_76 ;
}
