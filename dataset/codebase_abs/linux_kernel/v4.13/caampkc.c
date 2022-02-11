static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_2 ( V_2 , V_6 -> V_7 , V_4 -> V_8 , V_9 ) ;
F_2 ( V_2 , V_6 -> V_10 , V_4 -> V_11 , V_12 ) ;
if ( V_4 -> V_13 )
F_3 ( V_2 , V_4 -> V_14 , V_4 -> V_13 ,
V_12 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_21 * V_22 = & V_4 -> V_22 . V_23 ;
F_3 ( V_2 , V_22 -> V_24 , V_20 -> V_25 , V_12 ) ;
F_3 ( V_2 , V_22 -> V_26 , V_20 -> V_27 , V_12 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_28 * V_22 = & V_4 -> V_22 . V_29 ;
F_3 ( V_2 , V_22 -> V_24 , V_20 -> V_25 , V_12 ) ;
F_3 ( V_2 , V_22 -> V_30 , V_20 -> V_31 , V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_32 * V_22 = & V_4 -> V_22 . V_33 ;
T_1 V_34 = V_20 -> V_34 ;
T_1 V_35 = V_20 -> V_34 ;
F_3 ( V_2 , V_22 -> V_30 , V_20 -> V_31 , V_12 ) ;
F_3 ( V_2 , V_22 -> V_36 , V_34 , V_12 ) ;
F_3 ( V_2 , V_22 -> V_37 , V_35 , V_12 ) ;
F_3 ( V_2 , V_22 -> V_38 , V_34 , V_12 ) ;
F_3 ( V_2 , V_22 -> V_39 , V_35 , V_12 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_40 * V_22 = & V_4 -> V_22 . V_41 ;
T_1 V_34 = V_20 -> V_34 ;
T_1 V_35 = V_20 -> V_34 ;
F_3 ( V_2 , V_22 -> V_36 , V_34 , V_12 ) ;
F_3 ( V_2 , V_22 -> V_37 , V_35 , V_12 ) ;
F_3 ( V_2 , V_22 -> V_42 , V_34 , V_12 ) ;
F_3 ( V_2 , V_22 -> V_43 , V_35 , V_12 ) ;
F_3 ( V_2 , V_22 -> V_44 , V_34 , V_12 ) ;
F_3 ( V_2 , V_22 -> V_38 , V_34 , V_12 ) ;
F_3 ( V_2 , V_22 -> V_39 , V_35 , V_12 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_2 * V_45 , T_2 V_46 , void * V_47 )
{
struct V_5 * V_6 = V_47 ;
struct V_3 * V_4 ;
if ( V_46 )
F_11 ( V_2 , V_46 ) ;
V_4 = F_12 ( V_45 , struct V_3 , V_48 [ 0 ] ) ;
F_4 ( V_2 , V_4 , V_6 ) ;
F_1 ( V_2 , V_4 , V_6 ) ;
F_13 ( V_4 ) ;
F_14 ( V_6 , V_46 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_2 * V_45 , T_2 V_46 ,
void * V_47 )
{
struct V_5 * V_6 = V_47 ;
struct V_3 * V_4 ;
if ( V_46 )
F_11 ( V_2 , V_46 ) ;
V_4 = F_12 ( V_45 , struct V_3 , V_48 [ 0 ] ) ;
F_7 ( V_2 , V_4 , V_6 ) ;
F_1 ( V_2 , V_4 , V_6 ) ;
F_13 ( V_4 ) ;
F_14 ( V_6 , V_46 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_2 * V_45 , T_2 V_46 ,
void * V_47 )
{
struct V_5 * V_6 = V_47 ;
struct V_3 * V_4 ;
if ( V_46 )
F_11 ( V_2 , V_46 ) ;
V_4 = F_12 ( V_45 , struct V_3 , V_48 [ 0 ] ) ;
F_8 ( V_2 , V_4 , V_6 ) ;
F_1 ( V_2 , V_4 , V_6 ) ;
F_13 ( V_4 ) ;
F_14 ( V_6 , V_46 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_2 * V_45 , T_2 V_46 ,
void * V_47 )
{
struct V_5 * V_6 = V_47 ;
struct V_3 * V_4 ;
if ( V_46 )
F_11 ( V_2 , V_46 ) ;
V_4 = F_12 ( V_45 , struct V_3 , V_48 [ 0 ] ) ;
F_9 ( V_2 , V_4 , V_6 ) ;
F_1 ( V_2 , V_4 , V_6 ) ;
F_13 ( V_4 ) ;
F_14 ( V_6 , V_46 ) ;
}
static struct V_3 * F_18 ( struct V_5 * V_6 ,
T_1 V_49 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_3 * V_4 ;
T_3 V_50 = ( V_6 -> V_51 . V_50 & V_52 ) ?
V_53 : V_54 ;
int V_55 ;
int V_56 , V_57 = 0 , V_13 ;
int V_11 , V_8 ;
V_11 = F_19 ( V_6 -> V_10 , V_6 -> V_58 ) ;
V_8 = F_19 ( V_6 -> V_7 , V_6 -> V_59 ) ;
if ( V_11 > 1 )
V_57 = V_11 ;
if ( V_8 > 1 )
V_57 += V_8 ;
V_13 = V_57 * sizeof( struct V_60 ) ;
V_4 = F_20 ( sizeof( * V_4 ) + V_49 + V_13 ,
V_61 | V_50 ) ;
if ( ! V_4 )
return F_21 ( - V_62 ) ;
V_55 = F_22 ( V_2 , V_6 -> V_10 , V_11 , V_12 ) ;
if ( F_23 ( ! V_55 ) ) {
F_24 ( V_2 , L_1 ) ;
goto V_63;
}
V_55 = F_22 ( V_2 , V_6 -> V_7 , V_8 , V_9 ) ;
if ( F_23 ( ! V_55 ) ) {
F_24 ( V_2 , L_2 ) ;
goto V_64;
}
V_4 -> V_65 = ( void * ) V_4 + sizeof( * V_4 ) + V_49 ;
V_56 = 0 ;
if ( V_11 > 1 ) {
F_25 ( V_6 -> V_10 , V_11 , V_4 -> V_65 , 0 ) ;
V_56 += V_11 ;
}
if ( V_8 > 1 )
F_25 ( V_6 -> V_7 , V_8 ,
V_4 -> V_65 + V_56 , 0 ) ;
V_4 -> V_11 = V_11 ;
V_4 -> V_8 = V_8 ;
if ( ! V_13 )
return V_4 ;
V_4 -> V_14 = F_26 ( V_2 , V_4 -> V_65 ,
V_13 , V_12 ) ;
if ( F_27 ( V_2 , V_4 -> V_14 ) ) {
F_24 ( V_2 , L_3 ) ;
goto V_66;
}
V_4 -> V_13 = V_13 ;
return V_4 ;
V_66:
F_2 ( V_2 , V_6 -> V_7 , V_8 , V_9 ) ;
V_64:
F_2 ( V_2 , V_6 -> V_10 , V_11 , V_12 ) ;
V_63:
F_13 ( V_4 ) ;
return F_21 ( - V_62 ) ;
}
static int F_28 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_21 * V_22 = & V_4 -> V_22 . V_23 ;
int V_56 = 0 ;
V_22 -> V_24 = F_26 ( V_2 , V_20 -> V_67 , V_20 -> V_25 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_24 ) ) {
F_24 ( V_2 , L_4 ) ;
return - V_62 ;
}
V_22 -> V_26 = F_26 ( V_2 , V_20 -> V_68 , V_20 -> V_27 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_26 ) ) {
F_24 ( V_2 , L_5 ) ;
F_3 ( V_2 , V_22 -> V_24 , V_20 -> V_25 , V_12 ) ;
return - V_62 ;
}
if ( V_4 -> V_11 > 1 ) {
V_22 -> V_69 |= V_70 ;
V_22 -> V_71 = V_4 -> V_14 ;
V_56 += V_4 -> V_11 ;
} else {
V_22 -> V_71 = F_29 ( V_6 -> V_10 ) ;
}
if ( V_4 -> V_8 > 1 ) {
V_22 -> V_69 |= V_72 ;
V_22 -> V_73 = V_4 -> V_14 +
V_56 * sizeof( struct V_60 ) ;
} else {
V_22 -> V_73 = F_29 ( V_6 -> V_7 ) ;
}
V_22 -> V_69 |= ( V_20 -> V_27 << V_74 ) | V_20 -> V_25 ;
V_22 -> V_75 = V_6 -> V_58 ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_28 * V_22 = & V_4 -> V_22 . V_29 ;
int V_56 = 0 ;
V_22 -> V_24 = F_26 ( V_2 , V_20 -> V_67 , V_20 -> V_25 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_24 ) ) {
F_24 ( V_2 , L_6 ) ;
return - V_62 ;
}
V_22 -> V_30 = F_26 ( V_2 , V_20 -> V_76 , V_20 -> V_31 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_30 ) ) {
F_24 ( V_2 , L_7 ) ;
F_3 ( V_2 , V_22 -> V_24 , V_20 -> V_25 , V_12 ) ;
return - V_62 ;
}
if ( V_4 -> V_11 > 1 ) {
V_22 -> V_69 |= V_77 ;
V_22 -> V_73 = V_4 -> V_14 ;
V_56 += V_4 -> V_11 ;
} else {
V_22 -> V_73 = F_29 ( V_6 -> V_10 ) ;
}
if ( V_4 -> V_8 > 1 ) {
V_22 -> V_69 |= V_78 ;
V_22 -> V_71 = V_4 -> V_14 +
V_56 * sizeof( struct V_60 ) ;
} else {
V_22 -> V_71 = F_29 ( V_6 -> V_7 ) ;
}
V_22 -> V_69 |= ( V_20 -> V_31 << V_79 ) | V_20 -> V_25 ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_32 * V_22 = & V_4 -> V_22 . V_33 ;
int V_56 = 0 ;
T_1 V_34 = V_20 -> V_34 ;
T_1 V_35 = V_20 -> V_34 ;
V_22 -> V_30 = F_26 ( V_2 , V_20 -> V_76 , V_20 -> V_31 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_30 ) ) {
F_24 ( V_2 , L_7 ) ;
return - V_62 ;
}
V_22 -> V_36 = F_26 ( V_2 , V_20 -> V_80 , V_34 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_36 ) ) {
F_24 ( V_2 , L_8 ) ;
goto V_81;
}
V_22 -> V_37 = F_26 ( V_2 , V_20 -> V_82 , V_35 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_37 ) ) {
F_24 ( V_2 , L_9 ) ;
goto V_83;
}
V_22 -> V_38 = F_26 ( V_2 , V_20 -> V_84 , V_34 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_38 ) ) {
F_24 ( V_2 , L_10 ) ;
goto V_85;
}
V_22 -> V_39 = F_26 ( V_2 , V_20 -> V_86 , V_35 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_39 ) ) {
F_24 ( V_2 , L_11 ) ;
goto V_87;
}
if ( V_4 -> V_11 > 1 ) {
V_22 -> V_69 |= V_77 ;
V_22 -> V_73 = V_4 -> V_14 ;
V_56 += V_4 -> V_11 ;
} else {
V_22 -> V_73 = F_29 ( V_6 -> V_10 ) ;
}
if ( V_4 -> V_8 > 1 ) {
V_22 -> V_69 |= V_78 ;
V_22 -> V_71 = V_4 -> V_14 +
V_56 * sizeof( struct V_60 ) ;
} else {
V_22 -> V_71 = F_29 ( V_6 -> V_7 ) ;
}
V_22 -> V_69 |= ( V_20 -> V_31 << V_79 ) | V_20 -> V_25 ;
V_22 -> V_88 = ( V_35 << V_89 ) | V_34 ;
return 0 ;
V_87:
F_3 ( V_2 , V_22 -> V_38 , V_34 , V_12 ) ;
V_85:
F_3 ( V_2 , V_22 -> V_37 , V_35 , V_12 ) ;
V_83:
F_3 ( V_2 , V_22 -> V_36 , V_34 , V_12 ) ;
V_81:
F_3 ( V_2 , V_22 -> V_30 , V_20 -> V_31 , V_12 ) ;
return - V_62 ;
}
static int F_32 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_40 * V_22 = & V_4 -> V_22 . V_41 ;
int V_56 = 0 ;
T_1 V_34 = V_20 -> V_34 ;
T_1 V_35 = V_20 -> V_34 ;
V_22 -> V_36 = F_26 ( V_2 , V_20 -> V_80 , V_34 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_36 ) ) {
F_24 ( V_2 , L_8 ) ;
return - V_62 ;
}
V_22 -> V_37 = F_26 ( V_2 , V_20 -> V_82 , V_35 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_37 ) ) {
F_24 ( V_2 , L_9 ) ;
goto V_83;
}
V_22 -> V_42 = F_26 ( V_2 , V_20 -> V_90 , V_34 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_42 ) ) {
F_24 ( V_2 , L_12 ) ;
goto V_85;
}
V_22 -> V_43 = F_26 ( V_2 , V_20 -> V_91 , V_35 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_43 ) ) {
F_24 ( V_2 , L_13 ) ;
goto V_92;
}
V_22 -> V_44 = F_26 ( V_2 , V_20 -> V_93 , V_34 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_44 ) ) {
F_24 ( V_2 , L_14 ) ;
goto V_94;
}
V_22 -> V_38 = F_26 ( V_2 , V_20 -> V_84 , V_34 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_38 ) ) {
F_24 ( V_2 , L_10 ) ;
goto V_95;
}
V_22 -> V_39 = F_26 ( V_2 , V_20 -> V_86 , V_35 , V_12 ) ;
if ( F_27 ( V_2 , V_22 -> V_39 ) ) {
F_24 ( V_2 , L_11 ) ;
goto V_87;
}
if ( V_4 -> V_11 > 1 ) {
V_22 -> V_69 |= V_77 ;
V_22 -> V_73 = V_4 -> V_14 ;
V_56 += V_4 -> V_11 ;
} else {
V_22 -> V_73 = F_29 ( V_6 -> V_10 ) ;
}
if ( V_4 -> V_8 > 1 ) {
V_22 -> V_69 |= V_78 ;
V_22 -> V_71 = V_4 -> V_14 +
V_56 * sizeof( struct V_60 ) ;
} else {
V_22 -> V_71 = F_29 ( V_6 -> V_7 ) ;
}
V_22 -> V_69 |= V_20 -> V_25 ;
V_22 -> V_88 = ( V_35 << V_89 ) | V_34 ;
return 0 ;
V_87:
F_3 ( V_2 , V_22 -> V_38 , V_34 , V_12 ) ;
V_95:
F_3 ( V_2 , V_22 -> V_44 , V_34 , V_12 ) ;
V_94:
F_3 ( V_2 , V_22 -> V_43 , V_35 , V_12 ) ;
V_92:
F_3 ( V_2 , V_22 -> V_42 , V_34 , V_12 ) ;
V_85:
F_3 ( V_2 , V_22 -> V_37 , V_35 , V_12 ) ;
V_83:
F_3 ( V_2 , V_22 -> V_36 , V_34 , V_12 ) ;
return - V_62 ;
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_1 * V_96 = V_18 -> V_2 ;
struct V_3 * V_4 ;
int V_97 ;
if ( F_23 ( ! V_20 -> V_67 || ! V_20 -> V_68 ) )
return - V_98 ;
if ( V_6 -> V_59 < V_20 -> V_25 ) {
V_6 -> V_59 = V_20 -> V_25 ;
F_24 ( V_96 , L_15 ) ;
return - V_99 ;
}
V_4 = F_18 ( V_6 , V_100 ) ;
if ( F_34 ( V_4 ) )
return F_35 ( V_4 ) ;
V_97 = F_28 ( V_6 , V_4 ) ;
if ( V_97 )
goto V_101;
F_36 ( V_4 -> V_48 , & V_4 -> V_22 . V_23 ) ;
V_97 = F_37 ( V_96 , V_4 -> V_48 , F_10 , V_6 ) ;
if ( ! V_97 )
return - V_102 ;
F_4 ( V_96 , V_4 , V_6 ) ;
V_101:
F_1 ( V_96 , V_4 , V_6 ) ;
F_13 ( V_4 ) ;
return V_97 ;
}
static int F_38 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_1 * V_96 = V_18 -> V_2 ;
struct V_3 * V_4 ;
int V_97 ;
V_4 = F_18 ( V_6 , V_103 ) ;
if ( F_34 ( V_4 ) )
return F_35 ( V_4 ) ;
V_97 = F_30 ( V_6 , V_4 ) ;
if ( V_97 )
goto V_101;
F_39 ( V_4 -> V_48 , & V_4 -> V_22 . V_29 ) ;
V_97 = F_37 ( V_96 , V_4 -> V_48 , F_15 , V_6 ) ;
if ( ! V_97 )
return - V_102 ;
F_7 ( V_96 , V_4 , V_6 ) ;
V_101:
F_1 ( V_96 , V_4 , V_6 ) ;
F_13 ( V_4 ) ;
return V_97 ;
}
static int F_40 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_1 * V_96 = V_18 -> V_2 ;
struct V_3 * V_4 ;
int V_97 ;
V_4 = F_18 ( V_6 , V_104 ) ;
if ( F_34 ( V_4 ) )
return F_35 ( V_4 ) ;
V_97 = F_31 ( V_6 , V_4 ) ;
if ( V_97 )
goto V_101;
F_41 ( V_4 -> V_48 , & V_4 -> V_22 . V_33 ) ;
V_97 = F_37 ( V_96 , V_4 -> V_48 , F_16 , V_6 ) ;
if ( ! V_97 )
return - V_102 ;
F_8 ( V_96 , V_4 , V_6 ) ;
V_101:
F_1 ( V_96 , V_4 , V_6 ) ;
F_13 ( V_4 ) ;
return V_97 ;
}
static int F_42 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_1 * V_96 = V_18 -> V_2 ;
struct V_3 * V_4 ;
int V_97 ;
V_4 = F_18 ( V_6 , V_105 ) ;
if ( F_34 ( V_4 ) )
return F_35 ( V_4 ) ;
V_97 = F_32 ( V_6 , V_4 ) ;
if ( V_97 )
goto V_101;
F_43 ( V_4 -> V_48 , & V_4 -> V_22 . V_41 ) ;
V_97 = F_37 ( V_96 , V_4 -> V_48 , F_17 , V_6 ) ;
if ( ! V_97 )
return - V_102 ;
F_9 ( V_96 , V_4 , V_6 ) ;
V_101:
F_1 ( V_96 , V_4 , V_6 ) ;
F_13 ( V_4 ) ;
return V_97 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
int V_97 ;
if ( F_23 ( ! V_20 -> V_67 || ! V_20 -> V_76 ) )
return - V_98 ;
if ( V_6 -> V_59 < V_20 -> V_25 ) {
V_6 -> V_59 = V_20 -> V_25 ;
F_24 ( V_18 -> V_2 , L_15 ) ;
return - V_99 ;
}
if ( V_20 -> V_106 == V_107 )
V_97 = F_42 ( V_6 ) ;
else if ( V_20 -> V_106 == V_108 )
V_97 = F_40 ( V_6 ) ;
else
V_97 = F_38 ( V_6 ) ;
return V_97 ;
}
static void F_45 ( struct V_19 * V_20 )
{
F_46 ( V_20 -> V_76 ) ;
F_46 ( V_20 -> V_80 ) ;
F_46 ( V_20 -> V_82 ) ;
F_46 ( V_20 -> V_90 ) ;
F_46 ( V_20 -> V_91 ) ;
F_46 ( V_20 -> V_93 ) ;
F_46 ( V_20 -> V_84 ) ;
F_46 ( V_20 -> V_86 ) ;
F_13 ( V_20 -> V_68 ) ;
F_13 ( V_20 -> V_67 ) ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
}
static void F_47 ( const T_4 * * V_109 , T_1 * V_110 )
{
while ( ! * * V_109 && * V_110 ) {
( * V_109 ) ++ ;
( * V_110 ) -- ;
}
}
static T_4 * F_48 ( const T_4 * V_109 , T_1 V_110 , T_1 V_111 )
{
T_4 * V_7 ;
F_47 ( & V_109 , & V_110 ) ;
if ( ! V_110 )
return NULL ;
V_7 = F_20 ( V_111 , V_61 | V_53 ) ;
if ( ! V_7 )
return NULL ;
memcpy ( V_7 + ( V_111 - V_110 ) , V_109 , V_110 ) ;
return V_7 ;
}
static inline T_4 * F_49 ( const T_4 * V_112 , T_1 * V_110 )
{
T_4 * V_113 ;
F_47 ( & V_112 , V_110 ) ;
if ( ! * V_110 )
return NULL ;
V_113 = F_20 ( * V_110 , V_61 | V_53 ) ;
if ( ! V_113 )
return NULL ;
memcpy ( V_113 , V_112 , * V_110 ) ;
return V_113 ;
}
static int F_50 ( unsigned int V_114 )
{
if ( V_114 > 4096 )
return - V_98 ;
return 0 ;
}
static int F_51 ( struct V_15 * V_16 , const void * V_20 ,
unsigned int V_115 )
{
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_116 V_117 = { NULL } ;
struct V_19 * V_116 = & V_18 -> V_20 ;
int V_97 ;
F_45 ( V_116 ) ;
V_97 = F_52 ( & V_117 , V_20 , V_115 ) ;
if ( V_97 )
return V_97 ;
V_116 -> V_68 = F_20 ( V_117 . V_27 , V_61 | V_53 ) ;
if ( ! V_116 -> V_68 )
goto V_46;
V_116 -> V_67 = F_49 ( V_117 . V_67 , & V_117 . V_25 ) ;
if ( ! V_116 -> V_67 )
goto V_46;
if ( F_50 ( V_117 . V_25 << 3 ) ) {
F_45 ( V_116 ) ;
return - V_98 ;
}
V_116 -> V_27 = V_117 . V_27 ;
V_116 -> V_25 = V_117 . V_25 ;
memcpy ( V_116 -> V_68 , V_117 . V_68 , V_117 . V_27 ) ;
return 0 ;
V_46:
F_45 ( V_116 ) ;
return - V_62 ;
}
static void F_53 ( struct V_17 * V_18 ,
struct V_116 * V_117 )
{
struct V_19 * V_116 = & V_18 -> V_20 ;
T_1 V_34 = V_117 -> V_34 ;
T_1 V_35 = V_117 -> V_35 ;
V_116 -> V_80 = F_49 ( V_117 -> V_80 , & V_34 ) ;
if ( ! V_116 -> V_80 )
return;
V_116 -> V_34 = V_34 ;
V_116 -> V_82 = F_49 ( V_117 -> V_82 , & V_35 ) ;
if ( ! V_116 -> V_82 )
goto V_118;
V_116 -> V_35 = V_35 ;
V_116 -> V_84 = F_20 ( V_117 -> V_34 , V_61 | V_53 ) ;
if ( ! V_116 -> V_84 )
goto V_119;
V_116 -> V_86 = F_20 ( V_117 -> V_35 , V_61 | V_53 ) ;
if ( ! V_116 -> V_86 )
goto V_120;
V_116 -> V_106 = V_108 ;
V_116 -> V_90 = F_48 ( V_117 -> V_90 , V_117 -> V_121 , V_34 ) ;
if ( ! V_116 -> V_90 )
goto V_122;
V_116 -> V_91 = F_48 ( V_117 -> V_91 , V_117 -> V_123 , V_35 ) ;
if ( ! V_116 -> V_91 )
goto V_124;
V_116 -> V_93 = F_48 ( V_117 -> V_93 , V_117 -> V_125 ,
V_35 ) ;
if ( ! V_116 -> V_93 )
goto V_126;
V_116 -> V_106 = V_107 ;
return;
V_126:
F_46 ( V_116 -> V_91 ) ;
V_124:
F_46 ( V_116 -> V_90 ) ;
V_122:
F_46 ( V_116 -> V_86 ) ;
V_120:
F_46 ( V_116 -> V_84 ) ;
V_119:
F_46 ( V_116 -> V_82 ) ;
V_118:
F_46 ( V_116 -> V_80 ) ;
}
static int F_54 ( struct V_15 * V_16 , const void * V_20 ,
unsigned int V_115 )
{
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_116 V_117 = { NULL } ;
struct V_19 * V_116 = & V_18 -> V_20 ;
int V_97 ;
F_45 ( V_116 ) ;
V_97 = F_55 ( & V_117 , V_20 , V_115 ) ;
if ( V_97 )
return V_97 ;
V_116 -> V_76 = F_20 ( V_117 . V_31 , V_61 | V_53 ) ;
if ( ! V_116 -> V_76 )
goto V_46;
V_116 -> V_68 = F_20 ( V_117 . V_27 , V_61 | V_53 ) ;
if ( ! V_116 -> V_68 )
goto V_46;
V_116 -> V_67 = F_49 ( V_117 . V_67 , & V_117 . V_25 ) ;
if ( ! V_116 -> V_67 )
goto V_46;
if ( F_50 ( V_117 . V_25 << 3 ) ) {
F_45 ( V_116 ) ;
return - V_98 ;
}
V_116 -> V_31 = V_117 . V_31 ;
V_116 -> V_27 = V_117 . V_27 ;
V_116 -> V_25 = V_117 . V_25 ;
memcpy ( V_116 -> V_76 , V_117 . V_76 , V_117 . V_31 ) ;
memcpy ( V_116 -> V_68 , V_117 . V_68 , V_117 . V_27 ) ;
F_53 ( V_18 , & V_117 ) ;
return 0 ;
V_46:
F_45 ( V_116 ) ;
return - V_62 ;
}
static unsigned int F_56 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_6 ( V_16 ) ;
return V_18 -> V_20 . V_25 ;
}
static int F_57 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_6 ( V_16 ) ;
V_18 -> V_2 = F_58 () ;
if ( F_34 ( V_18 -> V_2 ) ) {
F_59 ( L_16 ) ;
return F_35 ( V_18 -> V_2 ) ;
}
return 0 ;
}
static void F_60 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
F_45 ( V_20 ) ;
F_61 ( V_18 -> V_2 ) ;
}
static int T_5 F_62 ( void )
{
struct V_127 * V_128 ;
struct V_129 * V_130 ;
struct V_1 * V_131 ;
struct V_132 * V_133 ;
T_2 V_134 , V_135 ;
int V_46 ;
V_128 = F_63 ( NULL , NULL , L_17 ) ;
if ( ! V_128 ) {
V_128 = F_63 ( NULL , NULL , L_18 ) ;
if ( ! V_128 )
return - V_136 ;
}
V_130 = F_64 ( V_128 ) ;
if ( ! V_130 ) {
F_65 ( V_128 ) ;
return - V_136 ;
}
V_131 = & V_130 -> V_2 ;
V_133 = F_66 ( V_131 ) ;
F_65 ( V_128 ) ;
if ( ! V_133 )
return - V_136 ;
V_134 = F_67 ( & V_133 -> V_137 -> V_138 . V_139 ) ;
V_135 = ( V_134 & V_140 ) >> V_141 ;
if ( ! V_135 )
return - V_136 ;
V_46 = F_68 ( & V_142 ) ;
if ( V_46 )
F_69 ( V_131 , L_19 ,
V_142 . V_51 . V_143 ) ;
else
F_70 ( V_131 , L_20 ) ;
return V_46 ;
}
static void T_6 F_71 ( void )
{
F_72 ( & V_142 ) ;
}
