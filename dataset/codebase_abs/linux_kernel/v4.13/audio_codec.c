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
if ( V_51 -> V_9 == V_25 )
V_18 = V_11 -> V_63 -> V_64 . V_18 ;
else
V_18 = V_11 -> V_63 -> V_65 . V_18 ;
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
static int F_41 ( struct V_52 * V_11 , int V_66 , int V_9 )
{
int V_14 ;
struct V_1 * V_5 ;
struct V_2 * V_3 ;
struct V_56 * V_57 ;
struct V_7 * V_8 = F_24 ( V_11 -> V_22 ) ;
struct V_6 * V_12 ;
F_8 ( V_11 -> V_22 , L_31 , V_66 ,
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
if ( V_66 ) {
V_12 -> V_24 = V_67 ;
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
if ( ! V_66 && ! V_9 ) {
V_14 = F_42 ( V_5 -> V_28 ,
0 ) ;
if ( ! V_14 )
V_14 = F_43 ( V_5 -> V_28 ,
0 , 0 ) ;
V_12 -> V_24 = V_68 ;
} else if ( ! V_66 && V_9 ) {
V_14 = F_44 ( V_5 -> V_28 ,
0 ) ;
if ( ! V_14 )
V_14 = F_45 ( V_5 -> V_28 ,
0 ) ;
V_12 -> V_24 = V_68 ;
} else if ( V_66 && ! V_9 ) {
V_14 = F_46 ( V_5 -> V_28 , 0 ) ;
if ( ! V_14 )
V_14 = F_47 ( V_5 -> V_28 ,
0 ) ;
V_12 -> V_24 = V_67 ;
} else if ( V_66 && V_9 ) {
V_14 = F_48 ( V_5 -> V_28 , 0 ) ;
if ( ! V_14 )
V_14 = F_49 ( V_5 -> V_28 ,
0 ) ;
V_12 -> V_24 = V_67 ;
} else {
V_14 = - V_26 ;
}
if ( V_14 )
F_7 ( V_11 -> V_22 ,
L_35 ,
V_3 -> V_45 , V_66 ? L_36 : L_37 ,
V_9 ? L_38 : L_39 , V_14 ) ;
F_37 ( V_57 ) ;
F_22 ( & V_8 -> V_49 ) ;
return V_14 ;
}
static int F_50 ( struct V_2 * V_3 ,
struct V_69 * V_8 )
{
int V_14 ;
if ( ! V_3 -> V_70 )
return 0 ;
snprintf ( V_3 -> V_71 , V_43 , L_40 ,
V_3 -> V_72 ) ;
V_14 = F_51 ( V_8 , V_3 -> V_71 , V_3 -> V_70 ,
& V_3 -> V_73 ) ;
if ( V_14 ) {
F_5 ( V_3 -> V_22 , L_41 ) ;
return V_14 ;
}
if ( ! V_3 -> V_74 )
return 0 ;
snprintf ( V_3 -> V_75 , V_43 , L_42 ,
V_3 -> V_72 ) ;
V_14 = F_51 ( V_8 , V_3 -> V_75 , V_3 -> V_74 ,
& V_3 -> V_76 ) ;
if ( V_14 ) {
F_5 ( V_3 -> V_22 , L_43 ) ;
return V_14 ;
}
if ( V_3 -> V_74 & V_77 ) {
V_14 = F_52 ( V_3 -> V_76 . V_78 , V_77 ,
V_79 ) ;
if ( V_14 ) {
F_5 ( V_3 -> V_22 , L_44 ) ;
return V_14 ;
}
}
if ( V_3 -> V_74 & V_80 ) {
V_14 = F_52 ( V_3 -> V_76 . V_78 , V_80 ,
V_81 ) ;
if ( V_14 ) {
F_5 ( V_3 -> V_22 , L_45 ) ;
return V_14 ;
}
}
if ( V_3 -> V_74 & V_82 ) {
V_14 = F_52 ( V_3 -> V_76 . V_78 , V_82 ,
V_83 ) ;
if ( V_14 ) {
F_5 ( V_3 -> V_22 , L_46 ) ;
return V_14 ;
}
}
if ( V_3 -> V_74 & V_84 ) {
V_14 = F_52 ( V_3 -> V_76 . V_78 , V_84 ,
V_85 ) ;
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
struct V_69 * V_8 ;
struct V_86 * V_87 ;
struct V_88 * V_78 = NULL ;
if ( ! V_89 ) {
F_5 ( V_3 -> V_22 , L_47 ) ;
return - V_90 ;
}
V_8 = V_89 -> V_8 ;
V_87 = V_8 -> V_87 -> V_86 ;
F_54 ( & V_87 -> V_91 ) ;
if ( V_3 -> V_92 ) {
F_5 ( V_89 -> V_22 ,
L_48 ,
V_3 -> V_92 ) ;
F_55 ( & V_87 -> V_91 ) ;
return - V_26 ;
}
V_14 = F_50 ( V_3 , V_8 ) ;
if ( V_14 ) {
F_55 ( & V_87 -> V_91 ) ;
return V_14 ;
}
if ( V_3 -> V_93 )
F_56 ( & V_8 -> V_94 , V_3 -> V_93 ,
V_3 -> V_95 ) ;
if ( V_3 -> V_96 )
F_57 ( V_8 , V_3 -> V_96 ,
V_3 -> V_97 ) ;
if ( V_3 -> V_98 )
F_58 ( & V_8 -> V_94 , V_3 -> V_98 ,
V_3 -> V_99 ) ;
if ( V_8 -> V_87 -> V_100 ) {
F_59 ( V_8 -> V_87 ,
& V_8 -> V_94 ) ;
#ifdef F_60
F_2 (jack, &codec->jack_list, list) {
if ( ( V_78 == & V_3 -> V_73 )
|| ( V_78 == & V_3 -> V_76 ) )
F_61 ( V_8 -> V_87 -> V_86 ,
V_78 -> V_78 ) ;
}
#endif
}
F_21 ( & V_89 -> V_49 ) ;
F_62 ( & V_3 -> V_101 , & V_89 -> V_53 ) ;
F_22 ( & V_89 -> V_49 ) ;
if ( V_8 -> V_87 -> V_100 )
V_14 = F_63 ( & V_8 -> V_94 ) ;
F_8 ( V_8 -> V_22 , L_49 , V_3 -> V_45 ) ;
F_55 ( & V_87 -> V_91 ) ;
return V_14 ;
}
static void F_64 ( struct V_1 * V_5 )
{
T_1 V_16 , V_17 ;
int V_14 ;
if ( F_65 ( & V_89 -> V_53 ) ) {
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
if ( F_65 ( & V_89 -> V_53 ) ) {
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
int V_102 , V_103 ;
F_8 ( V_89 -> V_22 , L_50 , V_3 -> V_45 ) ;
F_2 (data, &module->data_list, list) {
V_102 = V_5 -> V_24 [ 0 ] ;
V_103 = V_5 -> V_24 [ 1 ] ;
if ( V_102 > V_35 )
F_64 ( V_5 ) ;
if ( V_103 > V_35 )
F_66 ( V_5 ) ;
}
}
void F_68 ( struct V_2 * V_3 )
{
struct V_69 * V_8 = V_89 -> V_8 ;
struct V_86 * V_87 = V_8 -> V_87 -> V_86 ;
struct V_88 * V_78 , * V_104 ;
int V_105 ;
F_8 ( V_8 -> V_22 , L_51 , V_3 -> V_45 ) ;
F_54 ( & V_87 -> V_91 ) ;
F_21 ( & V_89 -> V_49 ) ;
F_67 ( V_3 ) ;
F_69 ( & V_3 -> V_101 ) ;
F_8 ( V_8 -> V_22 , L_52 , V_3 -> V_45 ) ;
F_22 ( & V_89 -> V_49 ) ;
#ifdef F_60
F_70 (jack, next_j, &codec->jack_list, list) {
if ( V_78 == & V_3 -> V_73 )
V_105 = V_106 ;
else if ( V_78 == & V_3 -> V_76 )
V_105 = V_107 ;
else
V_105 = 0 ;
if ( V_105 ) {
F_8 ( V_3 -> V_22 , L_53 ,
V_78 -> V_78 -> V_4 ) ;
F_71 ( V_78 , 0 , V_105 ) ;
F_72 ( V_8 -> V_87 -> V_86 , V_78 -> V_78 ) ;
F_69 ( & V_78 -> V_101 ) ;
}
}
#endif
if ( V_3 -> V_98 ) {
F_8 ( V_8 -> V_22 , L_54 ,
V_3 -> V_99 ) ;
F_73 ( & V_8 -> V_94 , V_3 -> V_98 ,
V_3 -> V_99 ) ;
}
if ( V_3 -> V_96 ) {
F_8 ( V_8 -> V_22 , L_55 ,
V_3 -> V_97 ) ;
F_74 ( V_8 , V_3 -> V_96 ,
V_3 -> V_97 ) ;
}
if ( V_3 -> V_93 ) {
F_8 ( V_8 -> V_22 , L_56 ,
V_3 -> V_95 ) ;
F_75 ( & V_8 -> V_94 , V_3 -> V_93 ,
V_3 -> V_95 ) ;
}
F_8 ( V_8 -> V_22 , L_57 , V_3 -> V_45 ) ;
F_55 ( & V_87 -> V_91 ) ;
}
static int F_76 ( struct V_69 * V_8 )
{
int V_108 ;
struct V_7 * V_109 ;
struct V_10 * V_11 ;
V_109 = F_77 ( V_8 -> V_22 , sizeof( * V_109 ) , V_110 ) ;
if ( ! V_109 )
return - V_111 ;
V_109 -> V_22 = V_8 -> V_22 ;
F_78 ( & V_109 -> V_53 ) ;
F_79 ( & V_109 -> V_49 ) ;
F_78 ( & V_109 -> V_112 ) ;
for ( V_108 = 0 ; V_108 < F_80 ( V_113 ) ; V_108 ++ ) {
V_11 = F_77 ( V_8 -> V_22 , sizeof( * V_11 ) , V_110 ) ;
if ( ! V_11 )
return - V_111 ;
V_11 -> V_4 = V_113 [ V_108 ] . V_4 ;
F_62 ( & V_11 -> V_101 , & V_109 -> V_112 ) ;
}
V_109 -> V_8 = V_8 ;
F_81 ( V_8 , V_109 ) ;
V_89 = V_109 ;
F_82 ( V_8 -> V_22 , 1 ) ;
return 0 ;
}
static int F_83 ( struct V_69 * V_8 )
{
return 0 ;
}
static int F_84 ( struct V_69 * V_8 , unsigned int V_114 ,
unsigned int V_115 )
{
return 0 ;
}
static unsigned int F_85 ( struct V_69 * V_8 ,
unsigned int V_114 )
{
return 0 ;
}
static int F_86 ( struct V_116 * V_22 )
{
F_8 ( V_22 , L_58 , V_117 ) ;
return 0 ;
}
static int F_87 ( struct V_116 * V_22 )
{
F_8 ( V_22 , L_59 , V_117 ) ;
return 0 ;
}
static int F_88 ( struct V_118 * V_119 )
{
return F_89 ( & V_119 -> V_22 , & V_120 ,
V_113 , F_80 ( V_113 ) ) ;
}
static int F_90 ( struct V_118 * V_119 )
{
F_91 ( & V_119 -> V_22 ) ;
return 0 ;
}
