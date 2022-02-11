static int F_1 ( enum V_1 V_2 )
{
return V_2 == V_3 || V_2 == V_4 ;
}
static int F_2 ( struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_13 ;
V_12 = V_6 -> V_14 [ V_8 -> V_15 ] ;
if ( V_8 -> V_2 == V_16 ) {
if ( F_3 ( & V_10 -> V_17 ) )
V_13 = ( V_12 -> V_18 - 1 ) * 2 ;
else
V_13 = ( V_12 -> V_18 - 1 ) * 2 + 1 ;
} else {
V_13 = V_12 -> V_18 + V_6 -> V_19 - 1 ;
}
return V_13 ;
}
static void F_4 ( struct V_7 * V_8 ,
struct V_20 * V_21 , struct V_22 * V_23 )
{
T_1 V_24 ;
T_1 V_25 ;
T_1 V_26 ;
T_1 V_27 ;
T_1 V_28 ;
T_1 V_29 ;
V_24 = F_5 ( F_6 ( V_21 -> V_30 ) ) ;
V_25 = F_7 ( F_6 ( V_21 -> V_31 ) ) ;
V_26 = F_8 ( F_6 ( V_21 -> V_30 ) ) ;
V_27 = F_9 ( F_6 ( V_21 -> V_30 ) ) ;
V_28 = F_10 ( F_6 ( V_21 -> V_31 ) ) ;
V_23 -> V_32 = 1 << V_25 ;
V_23 -> V_33 = 0 ;
V_23 -> V_34 = 0 ;
if ( V_8 -> V_2 == V_35 ) {
V_23 -> V_36 = 0 ;
V_23 -> V_37 = 1 ;
V_23 -> V_38 = 0 ;
V_23 -> V_39 = V_27 + 1 ;
V_23 -> V_40 = V_26 * V_23 -> V_39 ;
} else if ( V_8 -> V_2 == V_16 ) {
V_23 -> V_36 = 0 ;
V_29 = ( V_28 + 1 ) * ( V_27 + 1 ) ;
if ( V_24 == V_41 || V_24 == V_42 ) {
V_23 -> V_39 = V_29 ;
V_23 -> V_37 = 1 ;
V_23 -> V_38 = 0 ;
}
if ( V_24 == V_43 || V_24 == V_44 ) {
if ( V_29 <= V_23 -> V_32 )
V_23 -> V_39 = 1 ;
else
V_23 -> V_39 = F_11 ( V_29 )
/ V_23 -> V_32 ;
V_23 -> V_37 =
F_12 ( V_29 , V_23 -> V_39 ) ;
if ( V_23 -> V_37 > 1 )
V_23 -> V_38 = 1 ;
else
V_23 -> V_38 = 0 ;
}
V_23 -> V_40 = V_26 * V_23 -> V_39 ;
} else if ( F_1 ( V_8 -> V_2 ) ) {
V_23 -> V_38 = 0 ;
V_23 -> V_39 = 1 ;
if ( V_24 == V_41 || V_24 == V_42 ) {
V_23 -> V_36 = 3 ;
V_23 -> V_37 = V_23 -> V_36 + 2 ;
V_23 -> V_40 = V_26 ;
}
if ( V_24 == V_44 ) {
V_23 -> V_37 = F_12 (
V_26 , V_45 ) ;
V_23 -> V_40 = V_45 ;
V_23 -> V_36 = V_23 -> V_37 ;
}
if ( V_24 == V_43 ) {
V_23 -> V_36 = F_12 (
V_26 , V_45 ) + 2 ;
V_23 -> V_37 = V_23 -> V_36 + 2 ;
V_23 -> V_40 = V_45 ;
}
}
}
static T_1 F_13 ( struct V_46 * V_47 ,
struct V_22 * V_23 , T_1 V_33 )
{
T_1 V_48 ;
T_1 V_49 = 0 ;
int V_50 ;
int V_51 ;
V_48 = V_52 / V_23 -> V_32 ;
for ( V_50 = 0 ; V_50 < V_48 ; V_50 ++ ) {
T_1 V_53 = V_33 + V_50 * V_23 -> V_32 ;
for ( V_51 = 0 ; V_51 < V_23 -> V_37 ; V_51 ++ ) {
if ( V_47 -> V_54 [ V_53 + V_51 ] > V_49 )
V_49 = V_47 -> V_54 [ V_53 + V_51 ] ;
}
}
return V_49 ;
}
static void F_14 ( struct V_46 * V_47 ,
struct V_22 * V_23 , int V_55 )
{
T_1 V_48 ;
T_1 V_53 ;
int V_50 ;
int V_51 ;
V_48 = V_52 / V_23 -> V_32 ;
for ( V_50 = 0 ; V_50 < V_48 ; V_50 ++ ) {
V_53 = V_23 -> V_33 + V_50 * V_23 -> V_32 ;
for ( V_51 = 0 ; V_51 < V_23 -> V_37 ; V_51 ++ )
V_47 -> V_54 [ V_53 + V_51 ] += V_55 ;
}
}
static int F_15 ( struct V_7 * V_8 ,
struct V_46 * V_47 , struct V_22 * V_23 )
{
T_1 V_33 ;
T_1 V_32 ;
T_1 V_37 ;
T_1 V_56 ;
T_1 V_57 ;
T_1 V_58 ;
T_1 V_59 ;
if ( V_23 -> V_32 > V_52 )
V_23 -> V_32 = V_52 ;
V_32 = V_23 -> V_32 ;
V_37 = V_23 -> V_37 ;
V_56 = ~ 0 ;
V_57 = 0 ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ ) {
if ( ( V_33 + V_37 ) > V_23 -> V_32 )
break;
if ( F_1 ( V_8 -> V_2 ) && ( V_33 % 8 == 6 ) )
continue;
V_58 = F_13 ( V_47 , V_23 , V_33 ) ;
if ( V_56 > V_58 ) {
V_56 = V_58 ;
V_57 = V_33 ;
}
if ( V_56 == 0 )
break;
}
V_23 -> V_33 = V_57 ;
V_59 = ( V_8 -> V_2 == V_16 )
? V_60 : V_61 ;
if ( V_56 + V_23 -> V_40 > V_59 )
return - V_62 ;
F_14 ( V_47 , V_23 , V_23 -> V_40 ) ;
return 0 ;
}
static bool F_16 ( struct V_9 * V_10 ,
enum V_1 V_2 , int V_63 )
{
if ( F_17 ( & V_10 -> V_17 )
|| F_18 ( & V_10 -> V_17 ) )
return false ;
if ( F_1 ( V_2 ) && ! V_63 )
return false ;
return true ;
}
int F_19 ( struct V_64 * V_65 )
{
struct V_46 * V_66 ;
int V_67 ;
int V_50 ;
V_67 = V_65 -> V_68 * 2 + V_65 -> V_69 ;
V_66 = F_20 ( V_67 , sizeof( * V_66 ) , V_70 ) ;
if ( V_66 == NULL )
return - V_71 ;
for ( V_50 = 0 ; V_50 < V_67 ; V_50 ++ )
F_21 ( & V_66 [ V_50 ] . V_72 ) ;
V_65 -> V_66 = V_66 ;
return 0 ;
}
void F_22 ( struct V_64 * V_65 )
{
F_23 ( V_65 -> V_66 ) ;
}
int F_24 ( struct V_73 * V_74 , struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_64 * V_65 = F_25 ( V_74 ) ;
struct V_5 * V_6 ;
struct V_20 * V_21 ;
struct V_75 * V_76 ;
struct V_11 * V_12 ;
struct V_46 * V_47 ;
struct V_22 * V_23 ;
struct V_46 * V_66 ;
unsigned int V_77 ;
int V_13 ;
int V_78 = 0 ;
V_6 = F_26 ( V_74 ) ;
V_12 = V_6 -> V_14 [ V_8 -> V_15 ] ;
V_77 = F_27 ( & V_10 -> V_17 ) ;
V_76 = F_28 ( V_6 , V_12 -> V_79 ) ;
V_21 = F_29 ( V_6 , V_12 -> V_79 , V_77 ) ;
V_66 = V_65 -> V_66 ;
F_30 ( V_6 , L_1 ,
V_80 , F_31 ( & V_10 -> V_17 ) , V_8 -> V_2 ,
F_32 ( F_33 ( & V_10 -> V_17 ) ) ,
F_34 ( & V_10 -> V_17 ) , V_10 ) ;
if ( ! F_16 ( V_10 , V_8 -> V_2 , V_76 -> V_81 & V_82 ) ) {
if ( F_35 ( & V_10 -> V_17 )
|| F_36 ( & V_10 -> V_17 ) )
V_21 -> V_83 [ 0 ] |= F_37 ( F_38 ( 1 ) ) ;
return 0 ;
}
V_13 = F_2 ( V_6 , V_8 , V_10 ) ;
V_47 = & V_66 [ V_13 ] ;
V_23 = F_39 ( sizeof( struct V_22 ) , V_84 ) ;
if ( ! V_23 )
return - V_71 ;
F_4 ( V_8 , V_21 , V_23 ) ;
V_78 = F_15 ( V_8 , V_47 , V_23 ) ;
if ( V_78 ) {
F_40 ( V_6 , L_2 ) ;
F_23 ( V_23 ) ;
return - V_85 ;
}
F_41 ( & V_23 -> V_86 , & V_47 -> V_72 ) ;
V_23 -> V_10 = V_10 ;
V_21 -> V_83 [ 0 ] |= F_37 ( F_38 ( V_23 -> V_39 )
| F_42 ( V_23 -> V_36 ) | F_43 ( V_23 -> V_34 ) ) ;
V_21 -> V_83 [ 1 ] |= F_37 ( F_44 ( V_23 -> V_33 )
| F_45 ( V_23 -> V_38 ) ) ;
F_30 ( V_6 , L_3 ,
V_23 -> V_39 , V_23 -> V_36 , V_23 -> V_34 ,
V_23 -> V_33 , V_23 -> V_38 ) ;
return 0 ;
}
void F_46 ( struct V_73 * V_74 , struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_64 * V_65 = F_25 ( V_74 ) ;
struct V_5 * V_6 ;
struct V_75 * V_76 ;
struct V_11 * V_12 ;
struct V_46 * V_66 ;
struct V_46 * V_47 ;
struct V_22 * V_23 ;
int V_13 ;
V_6 = F_26 ( V_74 ) ;
V_12 = V_6 -> V_14 [ V_8 -> V_15 ] ;
V_76 = F_28 ( V_6 , V_12 -> V_79 ) ;
V_66 = V_65 -> V_66 ;
F_30 ( V_6 , L_4 ,
V_80 , F_31 ( & V_10 -> V_17 ) , V_8 -> V_2 ,
F_32 ( F_33 ( & V_10 -> V_17 ) ) ,
F_34 ( & V_10 -> V_17 ) , V_10 ) ;
if ( ! F_16 ( V_10 , V_8 -> V_2 , V_76 -> V_81 & V_82 ) )
return;
V_13 = F_2 ( V_6 , V_8 , V_10 ) ;
V_47 = & V_66 [ V_13 ] ;
F_47 (sch_ep, &sch_bw->bw_ep_list, endpoint) {
if ( V_23 -> V_10 == V_10 ) {
F_14 ( V_47 , V_23 ,
- V_23 -> V_40 ) ;
F_48 ( & V_23 -> V_86 ) ;
F_23 ( V_23 ) ;
break;
}
}
}
