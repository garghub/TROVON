static void * F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 * V_4 = ( T_1 * ) V_2 ;
int V_5 = 0 ;
T_2 V_6 , V_7 ;
T_1 V_8 ;
V_5 += V_2 -> V_9 ;
V_6 = V_2 -> V_10 ;
while ( V_5 < V_6 ) {
V_8 = * ( V_4 + V_5 ) ;
V_5 ++ ;
V_7 = * ( ( T_2 * ) ( V_4 + V_5 ) ) ;
V_5 += 2 ;
if ( V_8 == V_3 )
return V_4 + V_5 ;
V_5 += V_7 ;
}
return NULL ;
}
static void F_2 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
V_12 -> V_15 = ( V_14 -> V_16 << 8 ) |
V_14 -> V_17 ;
V_12 -> V_18 = V_12 -> V_15 +
( ( V_14 -> V_19 << 8 ) | V_14 -> V_20 ) ;
V_12 -> V_21 = V_12 -> V_18 +
V_14 -> V_22 ;
V_12 -> V_23 = V_12 -> V_15 +
( ( V_14 -> V_24 << 8 ) | V_14 -> V_25 ) ;
V_12 -> V_26 = ( V_14 -> V_27 << 8 ) |
V_14 -> V_28 ;
V_12 -> V_29 = V_12 -> V_26 +
V_14 -> V_30 ;
V_12 -> V_31 = V_12 -> V_29 +
V_14 -> V_32 ;
V_12 -> V_33 = V_12 -> V_26 +
( ( V_14 -> V_34 << 8 ) | V_14 -> V_35 ) ;
V_12 -> clock = V_14 -> clock * 10 ;
V_12 -> type = V_36 ;
if ( V_12 -> V_21 > V_12 -> V_23 )
V_12 -> V_23 = V_12 -> V_21 + 1 ;
if ( V_12 -> V_31 > V_12 -> V_33 )
V_12 -> V_33 = V_12 -> V_31 + 1 ;
F_3 ( V_12 ) ;
}
static void F_4 ( struct V_37 * V_38 ,
struct V_1 * V_2 )
{
struct V_39 * V_40 = NULL ;
struct V_39 * V_41 ;
T_1 V_42 = 0 ;
void * V_43 = NULL ;
struct V_44 * V_45
= F_1 ( V_2 , V_46 ) ;
V_38 -> V_41 = NULL ;
if ( V_45 ) {
F_5 ( L_1 , V_45 ) ;
V_42 = V_45 -> V_47 ;
} else {
F_5 ( L_2 ) ;
return;
}
V_43 = F_1 ( V_2 , V_48 ) ;
V_40 = (struct V_39 * ) ( V_43 + 1 ) + V_42 ;
V_41 = F_6 ( sizeof( * V_40 ) , V_49 ) ;
if ( ! V_41 ) {
F_5 ( L_3 ) ;
return;
}
memcpy ( V_41 , V_40 , sizeof( * V_40 ) ) ;
V_38 -> V_41 = V_41 ;
}
static void F_7 ( struct V_37 * V_38 ,
struct V_1 * V_2 )
{
struct V_44 * V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
V_38 -> V_55 = 0 ;
V_38 -> V_56 = 0 ;
V_50 = F_1 ( V_2 , V_46 ) ;
if ( ! V_50 )
return;
V_38 -> V_55 = V_50 -> V_57 ;
if ( V_50 -> V_47 == 0xff )
return;
V_52 = F_1 ( V_2 , V_58 ) ;
if ( ! V_52 )
return;
V_38 -> V_56 = 1 ;
V_54 = & V_52 -> V_59 [ V_50 -> V_47 ] ;
V_14 = & V_54 -> V_14 ;
V_12 = F_6 ( sizeof( * V_12 ) ,
V_49 ) ;
F_2 ( V_12 , V_14 ) ;
if ( V_12 -> V_23 > 0 && V_12 -> V_33 > 0 ) {
V_38 -> V_60 = V_12 ;
F_5 ( L_4 ) ;
F_8 ( V_12 ) ;
} else {
F_5 ( L_5 ) ;
V_38 -> V_56 = 0 ;
F_9 ( V_12 ) ;
}
return;
}
static void F_10 ( struct V_37 * V_38 ,
struct V_1 * V_2 )
{
struct V_61 * V_62 ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
V_38 -> V_63 = NULL ;
V_62 = F_1 ( V_2 , V_64 ) ;
if ( ! V_62 )
return;
V_14 = F_1 ( V_2 , V_65 ) ;
if ( ! V_14 )
return;
V_12 = F_6 ( sizeof( * V_12 ) , V_49 ) ;
if ( ! V_12 )
return;
F_2 ( V_12 ,
V_14 + V_62 -> V_47 ) ;
V_38 -> V_63 = V_12 ;
return;
}
static void F_11 ( struct V_37 * V_38 ,
struct V_1 * V_2 )
{
struct V_66 * V_67 ;
V_38 -> V_68 = 1 ;
V_38 -> V_69 = 1 ;
V_67 = F_1 ( V_2 , V_70 ) ;
if ( V_67 ) {
V_38 -> V_68 = V_67 -> V_68 ;
V_38 -> V_69 = V_67 -> V_69 ;
V_38 -> V_71 = V_67 -> V_72 ;
if ( V_38 -> V_71 ) {
V_38 -> V_73
= V_67 -> V_74 ? 100 : 96 ;
}
}
}
bool F_12 ( struct V_75 * V_76 )
{
struct V_37 * V_38 = V_76 -> V_77 ;
struct V_78 * V_79 = V_76 -> V_79 ;
struct V_80 * V_81 = NULL ;
struct V_1 * V_2 ;
T_1 T_3 * V_82 ;
T_4 V_83 ;
int V_84 ;
V_82 = F_13 ( V_79 , & V_83 ) ;
if ( ! V_82 )
return - 1 ;
for ( V_84 = 0 ; V_84 + 4 < V_83 ; V_84 ++ ) {
if ( ! memcmp ( V_82 + V_84 , L_6 , 4 ) ) {
V_81 = (struct V_80 * ) ( V_82 + V_84 ) ;
break;
}
}
if ( ! V_81 ) {
F_14 ( L_7 ) ;
F_15 ( V_79 , V_82 ) ;
return - 1 ;
}
V_2 = (struct V_1 * ) ( V_82 + V_84 + V_81 -> V_85 ) ;
F_11 ( V_38 , V_2 ) ;
F_7 ( V_38 , V_2 ) ;
F_10 ( V_38 , V_2 ) ;
F_4 ( V_38 , V_2 ) ;
F_15 ( V_79 , V_82 ) ;
return 0 ;
}
void F_16 ( struct V_75 * V_76 )
{
struct V_37 * V_38 = V_76 -> V_77 ;
struct V_11 * V_63 =
V_38 -> V_63 ;
struct V_11 * V_60 =
V_38 -> V_60 ;
struct V_39 * V_41 =
V_38 -> V_41 ;
if ( V_63 ) {
V_38 -> V_63 = NULL ;
F_9 ( V_63 ) ;
}
if ( V_60 ) {
V_38 -> V_60 = NULL ;
F_9 ( V_60 ) ;
}
if ( V_41 ) {
V_38 -> V_41 = NULL ;
F_9 ( V_41 ) ;
}
}
