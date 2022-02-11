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
F_5 ( L_1 , __LINE__ , V_27 ) ;
V_25 = F_6 ( V_11 ) ;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
struct V_28 * V_29 = F_7 ( V_11 , V_26 ) ;
if ( ! V_29 ) {
F_8 ( L_2 ) ;
return - V_30 ;
}
V_22 -> V_31 [ V_26 ] = V_29 -> V_31 ;
V_22 -> V_32 [ V_26 ] = V_29 -> V_33 ;
F_5 ( L_3 ,
V_26 , ( unsigned long ) V_22 -> V_32 [ V_26 ] ,
( unsigned long ) V_22 -> V_31 [ V_26 ] ) ;
}
V_23 = F_1 ( V_12 , V_14 , V_9 -> V_34 . V_35 ) ;
V_24 = F_1 ( V_13 , V_15 , V_9 -> V_34 . V_36 ) ;
if ( V_12 < 0 ) {
if ( V_23 )
V_16 -= V_12 ;
else
V_16 += V_14 ;
V_12 = 0 ;
}
if ( V_13 < 0 ) {
if ( V_24 )
V_17 -= V_13 ;
else
V_17 += V_15 ;
V_13 = 0 ;
}
V_22 -> V_37 = V_16 ;
V_22 -> V_38 = V_17 ;
V_22 -> V_39 = V_11 -> V_40 ;
V_22 -> V_41 = V_11 -> V_42 ;
V_22 -> V_43 = V_18 ;
V_22 -> V_44 = V_19 ;
V_22 -> V_45 = V_11 -> V_46 ;
V_22 -> V_47 = V_11 -> V_48 [ 0 ] ;
V_22 -> V_49 = V_11 -> V_49 ;
V_22 -> V_12 = V_12 ;
V_22 -> V_13 = V_13 ;
V_22 -> V_50 = V_23 ;
V_22 -> V_51 = V_24 ;
V_22 -> V_52 = V_9 -> V_34 . V_35 ;
V_22 -> V_53 = V_9 -> V_34 . V_36 ;
V_22 -> V_54 = V_9 -> V_34 . V_55 ;
V_22 -> V_56 = V_9 -> V_34 . V_57 ;
F_5 ( L_4 ,
V_22 -> V_12 , V_22 -> V_13 ,
V_22 -> V_50 , V_22 -> V_51 ) ;
F_9 ( V_9 , V_22 , V_58 ) ;
return 0 ;
}
void F_10 ( struct V_6 * V_7 )
{
struct V_20 * V_20 = F_4 ( V_7 ) ;
struct V_21 * V_22 = & V_20 -> V_22 ;
F_9 ( V_7 -> V_9 , & V_22 -> V_59 ,
V_60 ) ;
}
void F_11 ( struct V_6 * V_7 , int V_34 )
{
struct V_20 * V_20 = F_4 ( V_7 ) ;
struct V_21 * V_22 = & V_20 -> V_22 ;
F_5 ( L_1 , __LINE__ , V_27 ) ;
if ( V_34 == V_61 ) {
if ( V_20 -> V_62 )
return;
F_9 ( V_7 -> V_9 , & V_22 -> V_59 ,
V_63 ) ;
V_20 -> V_62 = true ;
} else {
if ( ! V_20 -> V_62 )
return;
F_9 ( V_7 -> V_9 , & V_22 -> V_59 ,
V_64 ) ;
V_20 -> V_62 = false ;
}
}
static int
F_12 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_10 * V_11 , int V_12 , int V_13 ,
unsigned int V_14 , unsigned int V_15 ,
T_1 V_16 , T_1 V_17 ,
T_1 V_18 , T_1 V_19 )
{
int V_65 ;
F_5 ( L_1 , __LINE__ , V_27 ) ;
V_65 = F_3 ( V_7 , V_9 , V_11 , V_12 , V_13 ,
V_14 , V_15 , V_16 >> 16 , V_17 >> 16 ,
V_18 >> 16 , V_19 >> 16 ) ;
if ( V_65 < 0 )
return V_65 ;
V_7 -> V_9 = V_9 ;
F_10 ( V_7 ) ;
F_11 ( V_7 , V_61 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 )
{
F_5 ( L_1 , __LINE__ , V_27 ) ;
F_11 ( V_7 , V_66 ) ;
return 0 ;
}
static void F_14 ( struct V_6 * V_7 )
{
struct V_20 * V_20 = F_4 ( V_7 ) ;
F_5 ( L_1 , __LINE__ , V_27 ) ;
F_13 ( V_7 ) ;
F_15 ( V_7 ) ;
F_16 ( V_20 ) ;
}
static int F_17 ( struct V_6 * V_7 ,
struct V_67 * V_68 ,
T_2 V_69 )
{
struct V_70 * V_71 = V_7 -> V_71 ;
struct V_20 * V_20 = F_4 ( V_7 ) ;
struct V_72 * V_73 = V_71 -> V_74 ;
F_5 ( L_1 , __LINE__ , V_27 ) ;
if ( V_68 == V_73 -> V_75 ) {
V_20 -> V_22 . V_59 = V_69 ;
return 0 ;
}
return - V_76 ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_70 * V_71 = V_7 -> V_71 ;
struct V_72 * V_73 = V_71 -> V_74 ;
struct V_67 * V_77 ;
F_5 ( L_1 , __LINE__ , V_27 ) ;
V_77 = V_73 -> V_75 ;
if ( ! V_77 ) {
V_77 = F_19 ( V_71 , 0 , L_5 , 0 ,
V_78 - 1 ) ;
if ( ! V_77 )
return;
V_73 -> V_75 = V_77 ;
}
F_20 ( & V_7 -> V_79 , V_77 , 0 ) ;
}
struct V_6 * F_21 ( struct V_70 * V_71 ,
unsigned int V_80 , bool V_81 )
{
struct V_20 * V_20 ;
int V_82 ;
F_5 ( L_1 , __LINE__ , V_27 ) ;
V_20 = F_22 ( sizeof( struct V_20 ) , V_83 ) ;
if ( ! V_20 ) {
F_23 ( L_6 ) ;
return NULL ;
}
V_82 = F_24 ( V_71 , & V_20 -> V_79 , V_80 ,
& V_84 , V_85 , F_25 ( V_85 ) ,
V_81 ) ;
if ( V_82 ) {
F_23 ( L_7 ) ;
F_16 ( V_20 ) ;
return NULL ;
}
if ( V_81 )
V_20 -> V_22 . V_59 = V_86 ;
else
F_18 ( & V_20 -> V_79 ) ;
return & V_20 -> V_79 ;
}
