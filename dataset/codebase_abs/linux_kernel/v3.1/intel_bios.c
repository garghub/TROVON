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
if ( V_45 )
V_42 = V_45 -> V_47 ;
else
return;
V_43 = F_1 ( V_2 , V_48 ) ;
V_40 = (struct V_39 * ) ( V_43 + 1 ) + V_42 ;
V_41 = F_5 ( sizeof( * V_40 ) , V_49 ) ;
if ( ! V_41 ) {
F_6 ( V_38 -> V_50 -> V_50 , L_1 ) ;
return;
}
memcpy ( V_41 , V_40 , sizeof( * V_40 ) ) ;
V_38 -> V_41 = V_41 ;
}
static void F_7 ( struct V_37 * V_38 ,
struct V_1 * V_2 )
{
struct V_44 * V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
V_38 -> V_56 = 0 ;
V_38 -> V_57 = 0 ;
V_51 = F_1 ( V_2 , V_46 ) ;
if ( ! V_51 )
return;
V_38 -> V_56 = V_51 -> V_58 ;
if ( V_51 -> V_47 == 0xff )
return;
V_53 = F_1 ( V_2 , V_59 ) ;
if ( ! V_53 )
return;
V_55 = & V_53 -> V_60 [ V_51 -> V_47 ] ;
V_14 = & V_55 -> V_14 ;
V_12 = F_5 ( sizeof( * V_12 ) ,
V_49 ) ;
if ( V_12 == NULL ) {
F_6 ( V_38 -> V_50 -> V_50 , L_2 ) ;
return;
}
V_38 -> V_57 = 1 ;
F_2 ( V_12 , V_14 ) ;
if ( V_12 -> V_23 > 0 && V_12 -> V_33 > 0 ) {
V_38 -> V_61 = V_12 ;
F_8 ( V_12 ) ;
} else {
F_9 ( V_38 -> V_50 -> V_50 , L_3 ) ;
V_38 -> V_57 = 0 ;
F_10 ( V_12 ) ;
}
return;
}
static void F_11 ( struct V_37 * V_38 ,
struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
V_38 -> V_64 = NULL ;
V_63 = F_1 ( V_2 , V_65 ) ;
if ( ! V_63 )
return;
V_14 = F_1 ( V_2 , V_66 ) ;
if ( ! V_14 )
return;
V_12 = F_5 ( sizeof( * V_12 ) , V_49 ) ;
if ( ! V_12 )
return;
F_2 ( V_12 ,
V_14 + V_63 -> V_47 ) ;
V_38 -> V_64 = V_12 ;
return;
}
static void F_12 ( struct V_37 * V_38 ,
struct V_1 * V_2 )
{
struct V_67 * V_68 ;
V_38 -> V_69 = 1 ;
V_38 -> V_70 = 1 ;
V_68 = F_1 ( V_2 , V_71 ) ;
if ( V_68 ) {
V_38 -> V_69 = V_68 -> V_69 ;
V_38 -> V_70 = V_68 -> V_70 ;
V_38 -> V_72 = V_68 -> V_73 ;
if ( V_38 -> V_72 ) {
V_38 -> V_74
= V_68 -> V_75 ? 100 : 96 ;
}
}
}
bool F_13 ( struct V_76 * V_50 )
{
struct V_37 * V_38 = V_50 -> V_77 ;
struct V_78 * V_79 = V_50 -> V_79 ;
struct V_80 * V_81 = NULL ;
struct V_1 * V_2 ;
T_1 T_3 * V_82 ;
T_4 V_83 ;
int V_84 ;
V_82 = F_14 ( V_79 , & V_83 ) ;
if ( ! V_82 )
return - 1 ;
for ( V_84 = 0 ; V_84 + 4 < V_83 ; V_84 ++ ) {
if ( ! memcmp ( V_82 + V_84 , L_4 , 4 ) ) {
V_81 = (struct V_80 * ) ( V_82 + V_84 ) ;
break;
}
}
if ( ! V_81 ) {
F_6 ( V_50 -> V_50 , L_5 ) ;
F_15 ( V_79 , V_82 ) ;
return - 1 ;
}
V_2 = (struct V_1 * ) ( V_82 + V_84 + V_81 -> V_85 ) ;
F_12 ( V_38 , V_2 ) ;
F_7 ( V_38 , V_2 ) ;
F_11 ( V_38 , V_2 ) ;
F_4 ( V_38 , V_2 ) ;
F_15 ( V_79 , V_82 ) ;
return 0 ;
}
void F_16 ( struct V_76 * V_50 )
{
struct V_37 * V_38 = V_50 -> V_77 ;
struct V_11 * V_64 =
V_38 -> V_64 ;
struct V_11 * V_61 =
V_38 -> V_61 ;
struct V_39 * V_41 =
V_38 -> V_41 ;
if ( V_64 ) {
V_38 -> V_64 = NULL ;
F_10 ( V_64 ) ;
}
if ( V_61 ) {
V_38 -> V_61 = NULL ;
F_10 ( V_61 ) ;
}
if ( V_41 ) {
V_38 -> V_41 = NULL ;
F_10 ( V_41 ) ;
}
}
