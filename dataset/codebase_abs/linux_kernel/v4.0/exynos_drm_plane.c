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
int F_3 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
int V_12 ;
int V_13 ;
V_12 = F_5 ( V_9 ) ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
struct V_14 * V_15 = F_6 ( V_9 , V_13 ) ;
if ( ! V_15 ) {
F_7 ( L_1 ) ;
return - V_16 ;
}
V_11 -> V_17 [ V_13 ] = V_15 -> V_17 ;
F_7 ( L_2 ,
V_13 , ( unsigned long ) V_11 -> V_17 [ V_13 ] ) ;
}
return 0 ;
}
void F_8 ( struct V_6 * V_7 , struct V_18 * V_19 ,
struct V_8 * V_9 , int V_20 , int V_21 ,
unsigned int V_22 , unsigned int V_23 ,
T_1 V_24 , T_1 V_25 ,
T_1 V_26 , T_1 V_27 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_28 * V_29 = F_9 ( V_19 ) ;
unsigned int V_30 ;
unsigned int V_31 ;
V_30 = F_1 ( V_20 , V_22 , V_19 -> V_32 . V_33 ) ;
V_31 = F_1 ( V_21 , V_23 , V_19 -> V_32 . V_34 ) ;
if ( V_20 < 0 ) {
if ( V_30 )
V_24 -= V_20 ;
V_20 = 0 ;
}
if ( V_21 < 0 ) {
if ( V_31 )
V_25 -= V_21 ;
V_21 = 0 ;
}
V_11 -> V_35 = V_24 ;
V_11 -> V_36 = V_25 ;
V_11 -> V_37 = V_9 -> V_38 ;
V_11 -> V_39 = V_9 -> V_40 ;
V_11 -> V_41 = V_26 ;
V_11 -> V_42 = V_27 ;
V_11 -> V_43 = V_9 -> V_44 ;
V_11 -> V_45 = V_9 -> V_46 [ 0 ] ;
V_11 -> V_47 = V_9 -> V_47 ;
V_11 -> V_20 = V_20 ;
V_11 -> V_21 = V_21 ;
V_11 -> V_48 = V_30 ;
V_11 -> V_49 = V_31 ;
V_11 -> V_50 = V_19 -> V_32 . V_33 ;
V_11 -> V_51 = V_19 -> V_32 . V_34 ;
V_11 -> V_52 = V_19 -> V_32 . V_53 ;
V_11 -> V_54 = V_19 -> V_32 . V_55 ;
F_7 ( L_3 ,
V_11 -> V_20 , V_11 -> V_21 ,
V_11 -> V_48 , V_11 -> V_49 ) ;
V_7 -> V_19 = V_19 ;
if ( V_29 -> V_56 -> V_57 )
V_29 -> V_56 -> V_57 ( V_29 , V_11 ) ;
}
int
F_10 ( struct V_6 * V_7 , struct V_18 * V_19 ,
struct V_8 * V_9 , int V_20 , int V_21 ,
unsigned int V_22 , unsigned int V_23 ,
T_1 V_24 , T_1 V_25 ,
T_1 V_26 , T_1 V_27 )
{
struct V_28 * V_29 = F_9 ( V_19 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
int V_58 ;
V_58 = F_3 ( V_7 , V_9 ) ;
if ( V_58 < 0 )
return V_58 ;
F_8 ( V_7 , V_19 , V_9 , V_20 , V_21 ,
V_22 , V_23 , V_24 >> 16 , V_25 >> 16 ,
V_26 >> 16 , V_27 >> 16 ) ;
if ( V_29 -> V_56 -> V_59 )
V_29 -> V_56 -> V_59 ( V_29 , V_11 -> V_60 ) ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_28 * V_29 = F_9 ( V_7 -> V_19 ) ;
if ( V_29 && V_29 -> V_56 -> V_61 )
V_29 -> V_56 -> V_61 ( V_29 ,
V_11 -> V_60 ) ;
return 0 ;
}
static void F_12 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
F_11 ( V_7 ) ;
F_13 ( V_7 ) ;
F_14 ( V_11 ) ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_62 * V_63 ,
T_2 V_64 )
{
struct V_65 * V_66 = V_7 -> V_66 ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_67 * V_68 = V_66 -> V_69 ;
if ( V_63 == V_68 -> V_70 ) {
V_11 -> V_60 = V_64 ;
return 0 ;
}
return - V_71 ;
}
static void F_16 ( struct V_6 * V_7 )
{
struct V_65 * V_66 = V_7 -> V_66 ;
struct V_67 * V_68 = V_66 -> V_69 ;
struct V_62 * V_72 ;
V_72 = V_68 -> V_70 ;
if ( ! V_72 ) {
V_72 = F_17 ( V_66 , 0 , L_4 , 0 ,
V_73 - 1 ) ;
if ( ! V_72 )
return;
V_68 -> V_70 = V_72 ;
}
F_18 ( & V_7 -> V_74 , V_72 , 0 ) ;
}
struct V_6 * F_19 ( struct V_65 * V_66 ,
unsigned long V_75 ,
enum V_76 type )
{
struct V_10 * V_11 ;
int V_77 ;
V_11 = F_20 ( sizeof( struct V_10 ) , V_78 ) ;
if ( ! V_11 )
return F_21 ( - V_79 ) ;
V_77 = F_22 ( V_66 , & V_11 -> V_74 , V_75 ,
& V_80 , V_81 ,
F_23 ( V_81 ) , type ) ;
if ( V_77 ) {
F_24 ( L_5 ) ;
F_14 ( V_11 ) ;
return F_21 ( V_77 ) ;
}
if ( type == V_82 )
V_11 -> V_60 = V_83 ;
else
F_16 ( & V_11 -> V_74 ) ;
return & V_11 -> V_74 ;
}
