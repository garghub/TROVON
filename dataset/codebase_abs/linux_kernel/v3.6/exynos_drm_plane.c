int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_15 = F_2 ( V_2 ) ;
struct V_16 * V_17 = & V_15 -> V_17 ;
unsigned int V_18 ;
unsigned int V_19 ;
int V_20 ;
int V_21 ;
F_3 ( L_1 , __LINE__ , V_22 ) ;
V_20 = F_4 ( V_6 -> V_23 ) ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
struct V_24 * V_25 = F_5 ( V_6 , V_21 ) ;
if ( ! V_25 ) {
F_6 ( L_2 ) ;
return - V_26 ;
}
V_17 -> V_27 [ V_21 ] = V_25 -> V_27 ;
V_17 -> V_28 [ V_21 ] = V_25 -> V_29 ;
F_3 ( L_3 ,
V_21 , ( unsigned long ) V_17 -> V_28 [ V_21 ] ,
( unsigned long ) V_17 -> V_27 [ V_21 ] ) ;
}
V_18 = F_7 ( ( unsigned ) ( V_4 -> V_30 . V_31 - V_7 ) , V_9 ) ;
V_19 = F_7 ( ( unsigned ) ( V_4 -> V_30 . V_32 - V_8 ) , V_10 ) ;
V_17 -> V_33 = V_11 ;
V_17 -> V_34 = V_12 ;
V_17 -> V_35 = V_6 -> V_36 ;
V_17 -> V_37 = V_6 -> V_38 ;
V_17 -> V_39 = V_13 ;
V_17 -> V_40 = V_14 ;
V_17 -> V_41 = V_6 -> V_42 ;
V_17 -> V_43 = V_6 -> V_44 [ 0 ] ;
V_17 -> V_23 = V_6 -> V_23 ;
V_17 -> V_7 = V_7 ;
V_17 -> V_8 = V_8 ;
V_17 -> V_45 = V_18 ;
V_17 -> V_46 = V_19 ;
V_17 -> V_47 = V_4 -> V_30 . V_31 ;
V_17 -> V_48 = V_4 -> V_30 . V_32 ;
V_17 -> V_49 = V_4 -> V_30 . V_50 ;
V_17 -> V_51 = V_4 -> V_30 . V_52 ;
F_3 ( L_4 ,
V_17 -> V_7 , V_17 -> V_8 ,
V_17 -> V_45 , V_17 -> V_46 ) ;
F_8 ( V_4 , V_17 , V_53 ) ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_2 ( V_2 ) ;
struct V_16 * V_17 = & V_15 -> V_17 ;
F_8 ( V_2 -> V_4 , & V_17 -> V_54 ,
V_55 ) ;
}
void F_10 ( struct V_1 * V_2 , int V_30 )
{
struct V_15 * V_15 = F_2 ( V_2 ) ;
struct V_16 * V_17 = & V_15 -> V_17 ;
F_3 ( L_1 , __LINE__ , V_22 ) ;
if ( V_30 == V_56 ) {
if ( V_15 -> V_57 )
return;
F_8 ( V_2 -> V_4 , & V_17 -> V_54 ,
V_58 ) ;
V_15 -> V_57 = true ;
} else {
if ( ! V_15 -> V_57 )
return;
F_8 ( V_2 -> V_4 , & V_17 -> V_54 ,
V_59 ) ;
V_15 -> V_57 = false ;
}
}
static int
F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
int V_60 ;
F_3 ( L_1 , __LINE__ , V_22 ) ;
V_60 = F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ,
V_9 , V_10 , V_11 >> 16 , V_12 >> 16 ,
V_13 >> 16 , V_14 >> 16 ) ;
if ( V_60 < 0 )
return V_60 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = V_4 -> V_6 ;
F_9 ( V_2 ) ;
F_10 ( V_2 , V_56 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_3 ( L_1 , __LINE__ , V_22 ) ;
F_10 ( V_2 , V_61 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_2 ( V_2 ) ;
F_3 ( L_1 , __LINE__ , V_22 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 ) ;
F_15 ( V_15 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_62 * V_63 ,
T_2 V_64 )
{
struct V_65 * V_66 = V_2 -> V_66 ;
struct V_15 * V_15 = F_2 ( V_2 ) ;
struct V_67 * V_68 = V_66 -> V_69 ;
F_3 ( L_1 , __LINE__ , V_22 ) ;
if ( V_63 == V_68 -> V_70 ) {
V_15 -> V_17 . V_54 = V_64 ;
return 0 ;
}
return - V_71 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = V_2 -> V_66 ;
struct V_67 * V_68 = V_66 -> V_69 ;
struct V_62 * V_72 ;
F_3 ( L_1 , __LINE__ , V_22 ) ;
V_72 = V_68 -> V_70 ;
if ( ! V_72 ) {
V_72 = F_18 ( V_66 , 0 , L_5 , 0 ,
V_73 - 1 ) ;
if ( ! V_72 )
return;
V_68 -> V_70 = V_72 ;
}
F_19 ( & V_2 -> V_74 , V_72 , 0 ) ;
}
struct V_1 * F_20 ( struct V_65 * V_66 ,
unsigned int V_75 , bool V_76 )
{
struct V_15 * V_15 ;
int V_77 ;
F_3 ( L_1 , __LINE__ , V_22 ) ;
V_15 = F_21 ( sizeof( struct V_15 ) , V_78 ) ;
if ( ! V_15 ) {
F_22 ( L_6 ) ;
return NULL ;
}
V_77 = F_23 ( V_66 , & V_15 -> V_74 , V_75 ,
& V_79 , V_80 , F_24 ( V_80 ) ,
V_76 ) ;
if ( V_77 ) {
F_22 ( L_7 ) ;
F_15 ( V_15 ) ;
return NULL ;
}
if ( V_76 )
V_15 -> V_17 . V_54 = V_81 ;
else
F_17 ( & V_15 -> V_74 ) ;
return & V_15 -> V_74 ;
}
