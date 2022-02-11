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
V_11 -> V_17 [ V_13 ] = V_15 -> V_17 + V_9 -> V_18 [ V_13 ] ;
F_7 ( L_2 ,
V_13 , ( unsigned long ) V_11 -> V_17 [ V_13 ] ) ;
}
return 0 ;
}
void F_8 ( struct V_6 * V_7 , struct V_19 * V_20 ,
struct V_8 * V_9 , int V_21 , int V_22 ,
unsigned int V_23 , unsigned int V_24 ,
T_1 V_25 , T_1 V_26 ,
T_1 V_27 , T_1 V_28 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
unsigned int V_29 ;
unsigned int V_30 ;
V_29 = F_1 ( V_21 , V_23 , V_20 -> V_31 . V_32 ) ;
V_30 = F_1 ( V_22 , V_24 , V_20 -> V_31 . V_33 ) ;
if ( V_21 < 0 ) {
if ( V_29 )
V_25 -= V_21 ;
V_21 = 0 ;
}
if ( V_22 < 0 ) {
if ( V_30 )
V_26 -= V_22 ;
V_22 = 0 ;
}
V_11 -> V_34 = ( V_27 << 16 ) / V_23 ;
V_11 -> V_35 = ( V_28 << 16 ) / V_24 ;
V_11 -> V_25 = V_25 ;
V_11 -> V_26 = V_26 ;
V_11 -> V_36 = ( V_29 * V_11 -> V_34 ) >> 16 ;
V_11 -> V_37 = ( V_30 * V_11 -> V_35 ) >> 16 ;
V_11 -> V_38 = V_9 -> V_39 ;
V_11 -> V_40 = V_9 -> V_41 ;
V_11 -> V_42 = V_9 -> V_43 ;
V_11 -> V_44 = V_9 -> V_45 [ 0 ] ;
V_11 -> V_46 = V_9 -> V_46 ;
V_11 -> V_21 = V_21 ;
V_11 -> V_22 = V_22 ;
V_11 -> V_47 = V_29 ;
V_11 -> V_48 = V_30 ;
V_11 -> V_49 = V_20 -> V_31 . V_32 ;
V_11 -> V_50 = V_20 -> V_31 . V_33 ;
V_11 -> V_51 = V_20 -> V_31 . V_52 ;
V_11 -> V_53 = V_20 -> V_31 . V_54 ;
F_7 ( L_3 ,
V_11 -> V_21 , V_11 -> V_22 ,
V_11 -> V_47 , V_11 -> V_48 ) ;
V_7 -> V_20 = V_20 ;
}
int
F_9 ( struct V_6 * V_7 , struct V_19 * V_20 ,
struct V_8 * V_9 , int V_21 , int V_22 ,
unsigned int V_23 , unsigned int V_24 ,
T_1 V_25 , T_1 V_26 ,
T_1 V_27 , T_1 V_28 )
{
struct V_55 * V_56 = F_10 ( V_20 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
int V_57 ;
V_57 = F_3 ( V_7 , V_9 ) ;
if ( V_57 < 0 )
return V_57 ;
F_8 ( V_7 , V_20 , V_9 , V_21 , V_22 ,
V_23 , V_24 , V_25 >> 16 , V_26 >> 16 ,
V_27 >> 16 , V_28 >> 16 ) ;
if ( V_56 -> V_58 -> V_59 )
V_56 -> V_58 -> V_59 ( V_56 , V_11 -> V_60 ) ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_55 * V_56 = F_10 ( V_7 -> V_20 ) ;
if ( V_56 && V_56 -> V_58 -> V_61 )
V_56 -> V_58 -> V_61 ( V_56 ,
V_11 -> V_60 ) ;
return 0 ;
}
static void F_12 ( struct V_6 * V_7 ,
unsigned int V_60 )
{
struct V_62 * V_63 = V_7 -> V_63 ;
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_67 * V_68 ;
V_68 = V_65 -> V_69 ;
if ( ! V_68 ) {
V_68 = F_13 ( V_63 , V_70 ,
L_4 , 0 , V_71 - 1 ) ;
if ( ! V_68 )
return;
V_65 -> V_69 = V_68 ;
}
F_14 ( & V_7 -> V_72 , V_68 , V_60 ) ;
}
int F_15 ( struct V_62 * V_63 ,
struct V_10 * V_11 ,
unsigned long V_73 , enum V_74 type ,
unsigned int V_60 )
{
int V_75 ;
V_75 = F_16 ( V_63 , & V_11 -> V_72 , V_73 ,
& V_76 , V_77 ,
F_17 ( V_77 ) , type ) ;
if ( V_75 ) {
F_18 ( L_5 ) ;
return V_75 ;
}
V_11 -> V_60 = V_60 ;
if ( type == V_78 )
F_12 ( & V_11 -> V_72 , V_60 ) ;
return 0 ;
}
