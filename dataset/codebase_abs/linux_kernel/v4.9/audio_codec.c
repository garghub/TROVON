static struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
F_2 (data, &module->data_list, list) {
if ( V_4 == V_5 -> V_4 )
return V_5 ;
}
return NULL ;
}
static struct V_6 *
F_3 ( struct V_7 * V_8 , int V_4 , int V_9 )
{
struct V_10 * V_11 ;
F_2 (dai, &codec->dai_list, list) {
if ( V_11 -> V_4 == V_4 )
return & V_11 -> V_12 [ V_9 ] ;
}
return NULL ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_2 * V_3 , int V_4 )
{
int V_13 , V_14 = 0 ;
T_1 V_15 , V_16 , V_17 ;
T_2 V_18 , V_19 ;
T_3 V_20 , V_21 ;
struct V_1 * V_5 ;
struct V_6 * V_12 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_5 ( V_3 -> V_22 , L_1 , V_4 ) ;
return - V_23 ;
}
V_13 = V_5 -> V_24 [ V_25 ] ;
V_12 = F_3 ( V_8 , V_4 , V_25 ) ;
if ( ! V_12 ) {
F_5 ( V_8 -> V_22 , L_2 ) ;
return - V_26 ;
}
if ( V_13 < V_27 ) {
V_16 = 0 ;
V_17 = V_5 -> V_28 -> V_29 ;
V_14 = F_6 ( V_5 -> V_28 ,
V_16 , V_17 ,
V_30 ) ;
if ( V_14 ) {
F_7 ( V_3 -> V_22 ,
L_3 , V_14 ) ;
return V_14 ;
}
V_5 -> V_24 [ V_25 ] =
V_27 ;
F_8 ( V_3 -> V_22 , L_4 , V_17 ) ;
}
if ( V_13 < V_31 ) {
V_20 = V_12 -> V_20 ;
V_19 = V_12 -> V_19 ;
V_21 = V_12 -> V_21 ;
V_18 = V_12 -> V_18 ;
V_15 = V_5 -> V_28 -> V_32 ;
V_14 = F_9 ( V_3 -> V_33 , V_15 ,
V_20 , V_21 , V_19 , V_18 ) ;
if ( V_14 ) {
F_7 ( V_3 -> V_22 , L_5 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_24 [ V_25 ] =
V_31 ;
F_8 ( V_3 -> V_22 , L_6 , V_15 ) ;
}
if ( V_13 < V_34 ) {
V_15 = V_5 -> V_28 -> V_32 ;
V_14 = F_10 ( V_3 -> V_33 ,
V_15 , 192 ) ;
if ( V_14 ) {
F_7 ( V_3 -> V_22 ,
L_7 ,
V_14 ) ;
return V_14 ;
}
V_14 = F_11 ( V_3 -> V_33 ,
V_15 ) ;
if ( V_14 ) {
F_7 ( V_3 -> V_22 ,
L_8 , V_14 ) ;
return V_14 ;
}
V_5 -> V_24 [ V_25 ] =
V_34 ;
F_8 ( V_3 -> V_22 , L_9 , V_15 ) ;
}
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , int V_4 )
{
int V_14 ;
T_1 V_15 , V_17 , V_16 ;
int V_13 ;
struct V_1 * V_5 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_5 ( V_3 -> V_22 , L_1 , V_4 ) ;
return - V_23 ;
}
V_13 = V_5 -> V_24 [ V_25 ] ;
if ( V_13 > V_31 ) {
V_15 = V_5 -> V_28 -> V_32 ;
V_14 = F_13 ( V_3 -> V_33 ,
V_15 ) ;
if ( V_14 ) {
F_7 ( V_3 -> V_22 ,
L_10 , V_14 ) ;
return V_14 ;
}
F_8 ( V_3 -> V_22 , L_11 , V_15 ) ;
V_5 -> V_24 [ V_25 ] =
V_31 ;
}
if ( V_13 > V_35 ) {
V_16 = 0 ;
V_17 = V_5 -> V_28 -> V_29 ;
V_14 = F_14 ( V_5 -> V_28 ,
V_16 , V_17 ,
V_30 ) ;
if ( V_14 ) {
F_7 ( V_3 -> V_22 ,
L_12 ,
V_14 ) ;
return V_14 ;
}
F_8 ( V_3 -> V_22 , L_13 , V_17 ) ;
V_5 -> V_24 [ V_25 ] =
V_35 ;
}
return 0 ;
}
static int F_15 ( struct V_7 * V_8 ,
struct V_2 * V_3 , int V_4 )
{
int V_13 , V_14 = 0 ;
T_1 V_15 , V_16 , V_17 ;
T_2 V_18 , V_19 ;
T_3 V_20 , V_21 ;
struct V_1 * V_5 ;
struct V_6 * V_12 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_5 ( V_3 -> V_22 , L_1 , V_4 ) ;
return - V_23 ;
}
V_13 = V_5 -> V_24 [ V_36 ] ;
V_12 = F_3 ( V_8 , V_4 , V_36 ) ;
if ( ! V_12 ) {
F_5 ( V_8 -> V_22 , L_2 ) ;
return - V_26 ;
}
if ( V_13 < V_27 ) {
V_16 = 0 ;
V_17 = V_5 -> V_28 -> V_29 ;
V_14 = F_6 ( V_5 -> V_28 ,
V_16 , V_17 ,
V_37 ) ;
if ( V_14 ) {
F_7 ( V_3 -> V_22 ,
L_3 , V_14 ) ;
return V_14 ;
}
V_5 -> V_24 [ V_36 ] =
V_27 ;
F_8 ( V_3 -> V_22 , L_4 , V_17 ) ;
}
if ( V_13 < V_31 ) {
V_20 = V_12 -> V_20 ;
V_19 = V_12 -> V_19 ;
V_21 = V_12 -> V_21 ;
V_18 = V_12 -> V_18 ;
V_15 = V_5 -> V_28 -> V_32 ;
V_14 = F_9 ( V_3 -> V_33 , V_15 ,
V_20 , V_21 , V_19 , V_18 ) ;
if ( V_14 ) {
F_7 ( V_3 -> V_22 , L_5 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_24 [ V_36 ] =
V_31 ;
F_8 ( V_3 -> V_22 , L_6 , V_15 ) ;
}
if ( V_13 < V_34 ) {
V_15 = V_5 -> V_28 -> V_32 ;
V_14 = F_16 ( V_3 -> V_33 ,
V_15 , 192 ) ;
if ( V_14 ) {
F_7 ( V_3 -> V_22 ,
L_14 ,
V_14 ) ;
return V_14 ;
}
V_14 = F_17 ( V_3 -> V_33 ,
V_15 ) ;
if ( V_14 ) {
F_7 ( V_3 -> V_22 ,
L_15 , V_14 ) ;
return V_14 ;
}
V_5 -> V_24 [ V_36 ] =
V_34 ;
F_8 ( V_3 -> V_22 , L_9 , V_15 ) ;
}
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , int V_4 )
{
int V_14 ;
T_1 V_15 , V_17 , V_16 ;
int V_13 ;
struct V_1 * V_5 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_5 ( V_3 -> V_22 , L_1 , V_4 ) ;
return - V_23 ;
}
V_13 = V_5 -> V_24 [ V_36 ] ;
if ( V_13 > V_31 ) {
V_15 = V_5 -> V_28 -> V_32 ;
V_14 = F_19 ( V_3 -> V_33 ,
V_15 ) ;
if ( V_14 ) {
F_7 ( V_3 -> V_22 ,
L_16 , V_14 ) ;
return V_14 ;
}
F_8 ( V_3 -> V_22 , L_11 , V_15 ) ;
V_5 -> V_24 [ V_36 ] =
V_31 ;
}
if ( V_13 > V_35 ) {
V_16 = 0 ;
V_17 = V_5 -> V_28 -> V_29 ;
V_14 = F_14 ( V_5 -> V_28 ,
V_16 , V_17 ,
V_37 ) ;
if ( V_14 ) {
F_7 ( V_3 -> V_22 ,
L_12 ,
V_14 ) ;
return V_14 ;
}
F_8 ( V_3 -> V_22 , L_13 , V_17 ) ;
V_5 -> V_24 [ V_36 ] =
V_35 ;
}
return 0 ;
}
int F_20 ( struct V_7 * V_8 ,
struct V_38 * V_39 ,
struct V_2 * V_3 , int V_40 )
{
int V_41 , V_14 ;
char V_42 [ V_43 ] , V_44 [ V_43 ] ;
F_8 ( V_3 -> V_22 , L_17 , V_39 -> V_45 ,
V_40 ? L_18 : L_19 ) ;
if ( ( V_39 -> V_4 != V_46 ) && ( V_39 -> V_4 != V_47 ) ) {
F_8 ( V_8 -> V_22 , L_20 , V_39 -> V_45 ) ;
return 0 ;
}
V_14 = sscanf ( V_39 -> V_48 , L_21 , V_42 , & V_41 , V_44 ) ;
if ( V_14 < 3 ) {
F_5 ( V_8 -> V_22 , L_22 ,
V_39 -> V_45 ) ;
return - V_26 ;
}
F_21 ( & V_8 -> V_49 ) ;
if ( V_39 -> V_4 == V_46 ) {
if ( V_40 )
V_14 = F_4 ( V_8 , V_3 , V_41 ) ;
else
V_14 = F_12 ( V_3 , V_41 ) ;
} else if ( V_39 -> V_4 == V_47 ) {
if ( V_40 )
V_14 = F_15 ( V_8 , V_3 , V_41 ) ;
else
V_14 = F_18 ( V_3 , V_41 ) ;
}
F_22 ( & V_8 -> V_49 ) ;
return V_14 ;
}
static int F_23 ( struct V_50 * V_51 ,
struct V_52 * V_11 )
{
struct V_7 * V_8 = F_24 ( V_11 -> V_22 ) ;
struct V_6 * V_12 ;
F_21 ( & V_8 -> V_49 ) ;
if ( F_25 ( & V_8 -> V_53 ) ) {
F_5 ( V_8 -> V_22 , L_23 ) ;
F_22 ( & V_8 -> V_49 ) ;
return - V_23 ;
}
V_12 = F_3 ( V_8 , V_11 -> V_4 , V_51 -> V_9 ) ;
if ( ! V_12 ) {
F_5 ( V_8 -> V_22 , L_2 ) ;
F_22 ( & V_8 -> V_49 ) ;
return - V_26 ;
}
V_12 -> V_24 = V_27 ;
F_22 ( & V_8 -> V_49 ) ;
F_26 ( V_11 -> V_22 ) ;
return 0 ;
}
static void F_27 ( struct V_50 * V_51 ,
struct V_52 * V_11 )
{
struct V_7 * V_8 = F_24 ( V_11 -> V_22 ) ;
struct V_6 * V_12 ;
F_21 ( & V_8 -> V_49 ) ;
if ( F_25 ( & V_8 -> V_53 ) )
F_28 ( V_8 -> V_22 , L_24 ) ;
V_12 = F_3 ( V_8 , V_11 -> V_4 , V_51 -> V_9 ) ;
if ( ! V_12 ) {
F_5 ( V_8 -> V_22 , L_2 ) ;
F_22 ( & V_8 -> V_49 ) ;
return;
}
V_12 -> V_24 = V_35 ;
F_22 ( & V_8 -> V_49 ) ;
F_29 ( V_11 -> V_22 ) ;
return;
}
static int F_30 ( struct V_50 * V_51 ,
struct V_54 * V_55 ,
struct V_52 * V_11 )
{
int V_14 ;
T_2 V_18 , V_19 ;
T_3 V_20 , V_21 ;
struct V_2 * V_3 ;
struct V_1 * V_5 ;
struct V_56 * V_57 ;
struct V_7 * V_8 = F_24 ( V_11 -> V_22 ) ;
struct V_6 * V_12 ;
F_21 ( & V_8 -> V_49 ) ;
if ( F_25 ( & V_8 -> V_53 ) ) {
F_5 ( V_8 -> V_22 , L_23 ) ;
F_22 ( & V_8 -> V_49 ) ;
return - V_23 ;
}
if ( F_31 ( V_55 ) != 2 ) {
F_5 ( V_11 -> V_22 , L_25 ,
F_31 ( V_55 ) ) ;
F_22 ( & V_8 -> V_49 ) ;
return - V_26 ;
}
V_19 = F_31 ( V_55 ) ;
if ( F_32 ( V_55 ) != 48000 ) {
F_5 ( V_11 -> V_22 , L_26 ,
F_32 ( V_55 ) ) ;
F_22 ( & V_8 -> V_49 ) ;
return - V_26 ;
}
V_21 = V_58 ;
if ( F_33 ( V_55 ) != V_59 ) {
F_5 ( V_11 -> V_22 , L_27 ,
F_33 ( V_55 ) ) ;
F_22 ( & V_8 -> V_49 ) ;
return - V_26 ;
}
V_20 = V_60 ;
F_2 (module, &codec->module_list, list) {
V_5 = F_1 ( V_3 , V_11 -> V_4 ) ;
if ( V_5 )
break;
}
if ( ! V_5 ) {
F_5 ( V_11 -> V_22 , L_28 ) ;
F_22 ( & V_8 -> V_49 ) ;
return - V_26 ;
}
V_12 = F_3 ( V_8 , V_11 -> V_4 , V_51 -> V_9 ) ;
if ( ! V_12 ) {
F_5 ( V_8 -> V_22 , L_2 ) ;
F_22 ( & V_8 -> V_49 ) ;
return - V_26 ;
}
V_57 = F_34 ( V_3 -> V_22 ) ;
V_14 = F_35 ( V_57 ) ;
if ( V_14 ) {
F_22 ( & V_8 -> V_49 ) ;
return V_14 ;
}
V_14 = F_36 ( V_5 -> V_28 , 0 ,
V_61 ,
V_62 ,
6144000 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_22 , L_29 ,
V_14 ) ;
F_22 ( & V_8 -> V_49 ) ;
return V_14 ;
}
F_37 ( V_57 ) ;
V_12 -> V_24 = V_31 ;
V_12 -> V_20 = V_20 ;
V_12 -> V_21 = V_21 ;
V_12 -> V_19 = V_19 ;
V_12 -> V_18 = V_18 ;
F_22 ( & V_8 -> V_49 ) ;
return 0 ;
}
static int F_38 ( struct V_50 * V_51 ,
struct V_52 * V_11 )
{
int V_14 ;
struct V_2 * V_3 ;
struct V_1 * V_5 ;
struct V_56 * V_57 ;
struct V_7 * V_8 = F_24 ( V_11 -> V_22 ) ;
struct V_6 * V_12 ;
F_21 ( & V_8 -> V_49 ) ;
if ( F_25 ( & V_8 -> V_53 ) ) {
F_5 ( V_8 -> V_22 , L_23 ) ;
F_22 ( & V_8 -> V_49 ) ;
return - V_23 ;
}
F_2 (module, &codec->module_list, list) {
V_5 = F_1 ( V_3 , V_11 -> V_4 ) ;
if ( V_5 )
break;
}
if ( ! V_5 ) {
F_5 ( V_11 -> V_22 , L_28 ) ;
F_22 ( & V_8 -> V_49 ) ;
return - V_23 ;
}
V_12 = F_3 ( V_8 , V_11 -> V_4 , V_51 -> V_9 ) ;
if ( ! V_12 ) {
F_5 ( V_8 -> V_22 , L_2 ) ;
F_22 ( & V_8 -> V_49 ) ;
return - V_26 ;
}
V_57 = F_34 ( V_3 -> V_22 ) ;
V_14 = F_35 ( V_57 ) ;
if ( V_14 ) {
F_22 ( & V_8 -> V_49 ) ;
return V_14 ;
}
switch ( V_51 -> V_9 ) {
case V_25 :
V_14 = F_39 ( V_5 -> V_28 , 0 ,
192 ) ;
break;
case V_36 :
V_14 = F_40 ( V_5 -> V_28 , 0 ,
192 ) ;
break;
}
if ( V_14 ) {
F_22 ( & V_8 -> V_49 ) ;
F_7 ( V_11 -> V_22 , L_30 ,
V_14 ) ;
return V_14 ;
}
F_37 ( V_57 ) ;
V_12 -> V_24 = V_34 ;
F_22 ( & V_8 -> V_49 ) ;
return 0 ;
}
static int F_41 ( struct V_52 * V_11 , int V_63 , int V_9 )
{
int V_14 ;
struct V_1 * V_5 ;
struct V_2 * V_3 ;
struct V_56 * V_57 ;
struct V_7 * V_8 = F_24 ( V_11 -> V_22 ) ;
struct V_6 * V_12 ;
F_8 ( V_11 -> V_22 , L_31 , V_63 ,
V_9 ? L_32 : L_33 ) ;
F_21 ( & V_8 -> V_49 ) ;
V_12 = F_3 ( V_8 , V_11 -> V_4 , V_9 ) ;
if ( ! V_12 ) {
F_5 ( V_8 -> V_22 , L_2 ) ;
F_22 ( & V_8 -> V_49 ) ;
return - V_26 ;
}
if ( F_25 ( & V_8 -> V_53 ) ) {
F_5 ( V_8 -> V_22 , L_23 ) ;
if ( V_63 ) {
V_12 -> V_24 = V_64 ;
V_14 = 0 ;
} else {
V_14 = - V_23 ;
}
F_22 ( & V_8 -> V_49 ) ;
return V_14 ;
}
F_2 (module, &codec->module_list, list) {
V_5 = F_1 ( V_3 , V_11 -> V_4 ) ;
if ( V_5 )
break;
}
if ( ! V_5 ) {
F_5 ( V_11 -> V_22 , L_34 ,
V_11 -> V_45 , V_3 -> V_45 ) ;
F_22 ( & V_8 -> V_49 ) ;
return - V_23 ;
}
V_57 = F_34 ( V_3 -> V_22 ) ;
V_14 = F_35 ( V_57 ) ;
if ( V_14 ) {
F_22 ( & V_8 -> V_49 ) ;
return V_14 ;
}
if ( ! V_63 && ! V_9 ) {
V_14 = F_42 ( V_5 -> V_28 ,
0 ) ;
if ( ! V_14 )
V_14 = F_43 ( V_5 -> V_28 ,
0 , 0 ) ;
V_12 -> V_24 = V_65 ;
} else if ( ! V_63 && V_9 ) {
V_14 = F_44 ( V_5 -> V_28 ,
0 ) ;
if ( ! V_14 )
V_14 = F_45 ( V_5 -> V_28 ,
0 ) ;
V_12 -> V_24 = V_65 ;
} else if ( V_63 && ! V_9 ) {
V_14 = F_46 ( V_5 -> V_28 , 0 ) ;
if ( ! V_14 )
V_14 = F_47 ( V_5 -> V_28 ,
0 ) ;
V_12 -> V_24 = V_64 ;
} else if ( V_63 && V_9 ) {
V_14 = F_48 ( V_5 -> V_28 , 0 ) ;
if ( ! V_14 )
V_14 = F_49 ( V_5 -> V_28 ,
0 ) ;
V_12 -> V_24 = V_64 ;
} else
V_14 = - V_26 ;
if ( V_14 )
F_7 ( V_11 -> V_22 ,
L_35 ,
V_3 -> V_45 , V_63 ? L_36 : L_37 ,
V_9 ? L_38 : L_39 , V_14 ) ;
F_37 ( V_57 ) ;
F_22 ( & V_8 -> V_49 ) ;
return V_14 ;
}
static int F_50 ( struct V_2 * V_3 ,
struct V_66 * V_8 )
{
int V_14 ;
if ( ! V_3 -> V_67 )
return 0 ;
snprintf ( V_3 -> V_68 , V_43 , L_40 ,
V_3 -> V_69 ) ;
V_14 = F_51 ( V_8 , V_3 -> V_68 , V_3 -> V_67 ,
& V_3 -> V_70 ) ;
if ( V_14 ) {
F_5 ( V_3 -> V_22 , L_41 ) ;
return V_14 ;
}
if ( ! V_3 -> V_71 )
return 0 ;
snprintf ( V_3 -> V_72 , V_43 , L_42 ,
V_3 -> V_69 ) ;
V_14 = F_51 ( V_8 , V_3 -> V_72 , V_3 -> V_71 ,
& V_3 -> V_73 ) ;
if ( V_14 ) {
F_5 ( V_3 -> V_22 , L_43 ) ;
return V_14 ;
}
if ( V_3 -> V_71 & V_74 ) {
V_14 = F_52 ( V_3 -> V_73 . V_75 , V_74 ,
V_76 ) ;
if ( V_14 ) {
F_5 ( V_3 -> V_22 , L_44 ) ;
return V_14 ;
}
}
if ( V_3 -> V_71 & V_77 ) {
V_14 = F_52 ( V_3 -> V_73 . V_75 , V_77 ,
V_78 ) ;
if ( V_14 ) {
F_5 ( V_3 -> V_22 , L_45 ) ;
return V_14 ;
}
}
if ( V_3 -> V_71 & V_79 ) {
V_14 = F_52 ( V_3 -> V_73 . V_75 , V_79 ,
V_80 ) ;
if ( V_14 ) {
F_5 ( V_3 -> V_22 , L_46 ) ;
return V_14 ;
}
}
if ( V_3 -> V_71 & V_81 ) {
V_14 = F_52 ( V_3 -> V_73 . V_75 , V_81 ,
V_82 ) ;
if ( V_14 ) {
F_5 ( V_3 -> V_22 , L_44 ) ;
return V_14 ;
}
}
return 0 ;
}
int F_53 ( struct V_2 * V_3 )
{
int V_14 ;
struct V_66 * V_8 ;
struct V_83 * V_84 ;
struct V_85 * V_75 = NULL ;
if ( ! V_86 ) {
F_5 ( V_3 -> V_22 , L_47 ) ;
return - V_87 ;
}
V_8 = V_86 -> V_8 ;
V_84 = V_8 -> V_84 -> V_83 ;
F_54 ( & V_84 -> V_88 ) ;
if ( V_3 -> V_89 ) {
F_5 ( V_86 -> V_22 ,
L_48 ,
V_3 -> V_89 ) ;
F_55 ( & V_84 -> V_88 ) ;
return - V_26 ;
}
V_14 = F_50 ( V_3 , V_8 ) ;
if ( V_14 ) {
F_55 ( & V_84 -> V_88 ) ;
return V_14 ;
}
if ( V_3 -> V_90 )
F_56 ( & V_8 -> V_91 , V_3 -> V_90 ,
V_3 -> V_92 ) ;
if ( V_3 -> V_93 )
F_57 ( V_8 , V_3 -> V_93 ,
V_3 -> V_94 ) ;
if ( V_3 -> V_95 )
F_58 ( & V_8 -> V_91 , V_3 -> V_95 ,
V_3 -> V_96 ) ;
if ( V_8 -> V_84 -> V_97 ) {
F_59 ( V_8 -> V_84 ,
& V_8 -> V_91 ) ;
#ifdef F_60
F_2 (jack, &codec->jack_list, list) {
if ( ( V_75 == & V_3 -> V_70 )
|| ( V_75 == & V_3 -> V_73 ) )
F_61 ( V_8 -> V_84 -> V_83 ,
V_75 -> V_75 ) ;
}
#endif
}
F_21 ( & V_86 -> V_49 ) ;
F_62 ( & V_3 -> V_98 , & V_86 -> V_53 ) ;
F_22 ( & V_86 -> V_49 ) ;
if ( V_8 -> V_84 -> V_97 )
V_14 = F_63 ( & V_8 -> V_91 ) ;
F_8 ( V_8 -> V_22 , L_49 , V_3 -> V_45 ) ;
F_55 ( & V_84 -> V_88 ) ;
return V_14 ;
}
static void F_64 ( struct V_1 * V_5 )
{
T_1 V_16 , V_17 ;
int V_14 ;
if ( F_65 ( & V_86 -> V_53 ) ) {
V_14 = F_46 ( V_5 -> V_28 , 0 ) ;
if ( V_14 )
return;
V_14 = F_47 ( V_5 -> V_28 ,
0 ) ;
if ( V_14 )
return;
}
V_16 = 0 ;
V_17 = V_5 -> V_28 -> V_29 ;
V_14 = F_14 ( V_5 -> V_28 ,
V_16 , V_17 ,
V_30 ) ;
V_5 -> V_24 [ 0 ] = V_35 ;
}
static void F_66 ( struct V_1 * V_5 )
{
T_1 V_16 , V_17 ;
int V_14 ;
if ( F_65 ( & V_86 -> V_53 ) ) {
V_14 = F_48 ( V_5 -> V_28 , 0 ) ;
if ( V_14 )
return;
V_14 = F_49 ( V_5 -> V_28 ,
0 ) ;
if ( V_14 )
return;
}
V_16 = 0 ;
V_17 = V_5 -> V_28 -> V_29 ;
V_14 = F_14 ( V_5 -> V_28 ,
V_16 , V_17 ,
V_37 ) ;
V_5 -> V_24 [ 1 ] = V_35 ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
int V_99 , V_100 ;
F_8 ( V_86 -> V_22 , L_50 , V_3 -> V_45 ) ;
F_2 (data, &module->data_list, list) {
V_99 = V_5 -> V_24 [ 0 ] ;
V_100 = V_5 -> V_24 [ 1 ] ;
if ( V_99 > V_35 )
F_64 ( V_5 ) ;
if ( V_100 > V_35 )
F_66 ( V_5 ) ;
}
}
void F_68 ( struct V_2 * V_3 )
{
struct V_66 * V_8 = V_86 -> V_8 ;
struct V_83 * V_84 = V_8 -> V_84 -> V_83 ;
struct V_85 * V_75 , * V_101 ;
int V_102 ;
F_8 ( V_8 -> V_22 , L_51 , V_3 -> V_45 ) ;
F_54 ( & V_84 -> V_88 ) ;
F_21 ( & V_86 -> V_49 ) ;
F_67 ( V_3 ) ;
F_69 ( & V_3 -> V_98 ) ;
F_8 ( V_8 -> V_22 , L_52 , V_3 -> V_45 ) ;
F_22 ( & V_86 -> V_49 ) ;
#ifdef F_60
F_70 (jack, next_j, &codec->jack_list, list) {
if ( V_75 == & V_3 -> V_70 )
V_102 = V_103 ;
else if ( V_75 == & V_3 -> V_73 )
V_102 = V_104 ;
else
V_102 = 0 ;
if ( V_102 ) {
F_8 ( V_3 -> V_22 , L_53 ,
V_75 -> V_75 -> V_4 ) ;
F_71 ( V_75 , 0 , V_102 ) ;
F_72 ( V_8 -> V_84 -> V_83 , V_75 -> V_75 ) ;
F_69 ( & V_75 -> V_98 ) ;
}
}
#endif
if ( V_3 -> V_95 ) {
F_8 ( V_8 -> V_22 , L_54 ,
V_3 -> V_96 ) ;
F_73 ( & V_8 -> V_91 , V_3 -> V_95 ,
V_3 -> V_96 ) ;
}
if ( V_3 -> V_93 ) {
F_8 ( V_8 -> V_22 , L_55 ,
V_3 -> V_94 ) ;
F_74 ( V_8 , V_3 -> V_93 ,
V_3 -> V_94 ) ;
}
if ( V_3 -> V_90 ) {
F_8 ( V_8 -> V_22 , L_56 ,
V_3 -> V_92 ) ;
F_75 ( & V_8 -> V_91 , V_3 -> V_90 ,
V_3 -> V_92 ) ;
}
F_8 ( V_8 -> V_22 , L_57 , V_3 -> V_45 ) ;
F_55 ( & V_84 -> V_88 ) ;
}
static int F_76 ( struct V_66 * V_8 )
{
int V_105 ;
struct V_7 * V_106 ;
struct V_10 * V_11 ;
V_106 = F_77 ( V_8 -> V_22 , sizeof( * V_106 ) , V_107 ) ;
if ( ! V_106 )
return - V_108 ;
V_106 -> V_22 = V_8 -> V_22 ;
F_78 ( & V_106 -> V_53 ) ;
F_79 ( & V_106 -> V_49 ) ;
F_78 ( & V_106 -> V_109 ) ;
for ( V_105 = 0 ; V_105 < F_80 ( V_110 ) ; V_105 ++ ) {
V_11 = F_77 ( V_8 -> V_22 , sizeof( * V_11 ) , V_107 ) ;
if ( ! V_11 )
return - V_108 ;
V_11 -> V_4 = V_110 [ V_105 ] . V_4 ;
F_62 ( & V_11 -> V_98 , & V_106 -> V_109 ) ;
}
V_106 -> V_8 = V_8 ;
F_81 ( V_8 , V_106 ) ;
V_86 = V_106 ;
F_82 ( V_8 -> V_22 , 1 ) ;
return 0 ;
}
static int F_83 ( struct V_66 * V_8 )
{
return 0 ;
}
static int F_84 ( struct V_66 * V_8 , unsigned int V_111 ,
unsigned int V_112 )
{
int V_14 = 0 ;
if ( V_111 == V_113 )
return 0 ;
F_85 ( V_111 >= V_114 ) ;
V_115 [ V_111 ] = V_112 ;
F_8 ( V_8 -> V_22 , L_58 , V_111 , V_112 ) ;
return V_14 ;
}
static unsigned int F_86 ( struct V_66 * V_8 ,
unsigned int V_111 )
{
unsigned int V_116 = 0 ;
if ( V_111 == V_113 )
return 0 ;
F_85 ( V_111 >= V_114 ) ;
V_116 = V_115 [ V_111 ] ;
F_8 ( V_8 -> V_22 , L_58 , V_111 , V_116 ) ;
return V_116 ;
}
static int F_87 ( struct V_117 * V_22 )
{
F_8 ( V_22 , L_59 , V_118 ) ;
return 0 ;
}
static int F_88 ( struct V_117 * V_22 )
{
F_8 ( V_22 , L_60 , V_118 ) ;
return 0 ;
}
static int F_89 ( struct V_119 * V_120 )
{
return F_90 ( & V_120 -> V_22 , & V_121 ,
V_110 , F_80 ( V_110 ) ) ;
}
static int F_91 ( struct V_119 * V_120 )
{
F_92 ( & V_120 -> V_22 ) ;
return 0 ;
}
