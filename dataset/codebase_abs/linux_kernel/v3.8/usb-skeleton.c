static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_3 ( V_3 -> V_4 ) ;
F_4 ( V_3 -> V_5 ) ;
F_5 ( V_3 -> V_6 ) ;
F_5 ( V_3 ) ;
}
static int F_6 ( struct V_7 * V_7 , struct V_8 * V_8 )
{
struct V_2 * V_3 ;
struct V_9 * V_10 ;
int V_11 ;
int V_12 = 0 ;
V_11 = F_7 ( V_7 ) ;
V_10 = F_8 ( & V_13 , V_11 ) ;
if ( ! V_10 ) {
F_9 ( L_1 ,
V_14 , V_11 ) ;
V_12 = - V_15 ;
goto exit;
}
V_3 = F_10 ( V_10 ) ;
if ( ! V_3 ) {
V_12 = - V_15 ;
goto exit;
}
V_12 = F_11 ( V_10 ) ;
if ( V_12 )
goto exit;
F_12 ( & V_3 -> V_1 ) ;
V_8 -> V_16 = V_3 ;
exit:
return V_12 ;
}
static int F_13 ( struct V_7 * V_7 , struct V_8 * V_8 )
{
struct V_2 * V_3 ;
V_3 = V_8 -> V_16 ;
if ( V_3 == NULL )
return - V_15 ;
F_14 ( & V_3 -> V_17 ) ;
if ( V_3 -> V_10 )
F_15 ( V_3 -> V_10 ) ;
F_16 ( & V_3 -> V_17 ) ;
F_17 ( & V_3 -> V_1 , F_1 ) ;
return 0 ;
}
static int F_18 ( struct V_8 * V_8 , T_1 V_18 )
{
struct V_2 * V_3 ;
int V_19 ;
V_3 = V_8 -> V_16 ;
if ( V_3 == NULL )
return - V_15 ;
F_14 ( & V_3 -> V_17 ) ;
F_19 ( V_3 ) ;
F_20 ( & V_3 -> V_20 ) ;
V_19 = V_3 -> V_21 ? ( V_3 -> V_21 == - V_22 ? - V_22 : - V_23 ) : 0 ;
V_3 -> V_21 = 0 ;
F_21 ( & V_3 -> V_20 ) ;
F_16 ( & V_3 -> V_17 ) ;
return V_19 ;
}
static void F_22 ( struct V_24 * V_24 )
{
struct V_2 * V_3 ;
V_3 = V_24 -> V_25 ;
F_23 ( & V_3 -> V_20 ) ;
if ( V_24 -> V_26 ) {
if ( ! ( V_24 -> V_26 == - V_27 ||
V_24 -> V_26 == - V_28 ||
V_24 -> V_26 == - V_29 ) )
F_24 ( & V_3 -> V_10 -> V_3 ,
L_2 ,
V_14 , V_24 -> V_26 ) ;
V_3 -> V_21 = V_24 -> V_26 ;
} else {
V_3 -> V_30 = V_24 -> V_31 ;
}
V_3 -> V_32 = 0 ;
F_25 ( & V_3 -> V_20 ) ;
F_26 ( & V_3 -> V_33 ) ;
}
static int F_27 ( struct V_2 * V_3 , T_2 V_34 )
{
int V_35 ;
F_28 ( V_3 -> V_4 ,
V_3 -> V_5 ,
F_29 ( V_3 -> V_5 ,
V_3 -> V_36 ) ,
V_3 -> V_6 ,
F_30 ( V_3 -> V_37 , V_34 ) ,
F_22 ,
V_3 ) ;
F_20 ( & V_3 -> V_20 ) ;
V_3 -> V_32 = 1 ;
F_21 ( & V_3 -> V_20 ) ;
V_35 = F_31 ( V_3 -> V_4 , V_38 ) ;
if ( V_35 < 0 ) {
F_24 ( & V_3 -> V_10 -> V_3 ,
L_3 ,
V_14 , V_35 ) ;
V_3 -> V_30 = 0 ;
V_35 = ( V_35 == - V_39 ) ? V_35 : - V_23 ;
F_20 ( & V_3 -> V_20 ) ;
V_3 -> V_32 = 0 ;
F_21 ( & V_3 -> V_20 ) ;
}
return V_35 ;
}
static T_3 F_32 ( struct V_8 * V_8 , char * V_40 , T_2 V_34 ,
T_4 * V_41 )
{
struct V_2 * V_3 ;
int V_35 ;
bool V_42 ;
V_3 = V_8 -> V_16 ;
if ( ! V_3 -> V_4 || ! V_34 )
return 0 ;
V_35 = F_33 ( & V_3 -> V_17 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( ! V_3 -> V_10 ) {
V_35 = - V_15 ;
goto exit;
}
V_43:
F_20 ( & V_3 -> V_20 ) ;
V_42 = V_3 -> V_32 ;
F_21 ( & V_3 -> V_20 ) ;
if ( V_42 ) {
if ( V_8 -> V_44 & V_45 ) {
V_35 = - V_46 ;
goto exit;
}
V_35 = F_34 ( & V_3 -> V_33 ) ;
if ( V_35 < 0 )
goto exit;
V_3 -> V_47 = 0 ;
V_3 -> V_48 = 1 ;
}
if ( ! V_3 -> V_48 ) {
F_35 ( & V_3 -> V_33 ) ;
V_3 -> V_47 = 0 ;
V_3 -> V_48 = 1 ;
}
V_35 = V_3 -> V_21 ;
if ( V_35 < 0 ) {
V_3 -> V_21 = 0 ;
V_35 = ( V_35 == - V_22 ) ? V_35 : - V_23 ;
V_3 -> V_30 = 0 ;
goto exit;
}
if ( V_3 -> V_30 ) {
T_2 V_49 = V_3 -> V_30 - V_3 -> V_47 ;
T_2 V_50 = F_30 ( V_49 , V_34 ) ;
if ( ! V_49 ) {
V_35 = F_27 ( V_3 , V_34 ) ;
if ( V_35 < 0 )
goto exit;
else
goto V_43;
}
if ( F_36 ( V_40 ,
V_3 -> V_6 + V_3 -> V_47 ,
V_50 ) )
V_35 = - V_51 ;
else
V_35 = V_50 ;
V_3 -> V_47 += V_50 ;
if ( V_49 < V_34 )
F_27 ( V_3 , V_34 - V_50 ) ;
} else {
V_35 = F_27 ( V_3 , V_34 ) ;
if ( V_35 < 0 )
goto exit;
else if ( ! ( V_8 -> V_44 & V_45 ) )
goto V_43;
V_35 = - V_46 ;
}
exit:
F_16 ( & V_3 -> V_17 ) ;
return V_35 ;
}
static void F_37 ( struct V_24 * V_24 )
{
struct V_2 * V_3 ;
V_3 = V_24 -> V_25 ;
if ( V_24 -> V_26 ) {
if ( ! ( V_24 -> V_26 == - V_27 ||
V_24 -> V_26 == - V_28 ||
V_24 -> V_26 == - V_29 ) )
F_24 ( & V_3 -> V_10 -> V_3 ,
L_2 ,
V_14 , V_24 -> V_26 ) ;
F_23 ( & V_3 -> V_20 ) ;
V_3 -> V_21 = V_24 -> V_26 ;
F_25 ( & V_3 -> V_20 ) ;
}
F_38 ( V_24 -> V_3 , V_24 -> V_52 ,
V_24 -> V_53 , V_24 -> V_54 ) ;
F_39 ( & V_3 -> V_55 ) ;
}
static T_3 F_40 ( struct V_8 * V_8 , const char * V_56 ,
T_2 V_34 , T_4 * V_41 )
{
struct V_2 * V_3 ;
int V_12 = 0 ;
struct V_24 * V_24 = NULL ;
char * V_57 = NULL ;
T_2 V_58 = F_30 ( V_34 , ( T_2 ) V_59 ) ;
V_3 = V_8 -> V_16 ;
if ( V_34 == 0 )
goto exit;
if ( ! ( V_8 -> V_44 & V_45 ) ) {
if ( F_41 ( & V_3 -> V_55 ) ) {
V_12 = - V_60 ;
goto exit;
}
} else {
if ( F_42 ( & V_3 -> V_55 ) ) {
V_12 = - V_46 ;
goto exit;
}
}
F_20 ( & V_3 -> V_20 ) ;
V_12 = V_3 -> V_21 ;
if ( V_12 < 0 ) {
V_3 -> V_21 = 0 ;
V_12 = ( V_12 == - V_22 ) ? V_12 : - V_23 ;
}
F_21 ( & V_3 -> V_20 ) ;
if ( V_12 < 0 )
goto error;
V_24 = F_43 ( 0 , V_38 ) ;
if ( ! V_24 ) {
V_12 = - V_39 ;
goto error;
}
V_57 = F_44 ( V_3 -> V_5 , V_58 , V_38 ,
& V_24 -> V_54 ) ;
if ( ! V_57 ) {
V_12 = - V_39 ;
goto error;
}
if ( F_45 ( V_57 , V_56 , V_58 ) ) {
V_12 = - V_51 ;
goto error;
}
F_14 ( & V_3 -> V_17 ) ;
if ( ! V_3 -> V_10 ) {
F_16 ( & V_3 -> V_17 ) ;
V_12 = - V_15 ;
goto error;
}
F_28 ( V_24 , V_3 -> V_5 ,
F_46 ( V_3 -> V_5 , V_3 -> V_61 ) ,
V_57 , V_58 , F_37 , V_3 ) ;
V_24 -> V_62 |= V_63 ;
F_47 ( V_24 , & V_3 -> V_64 ) ;
V_12 = F_31 ( V_24 , V_38 ) ;
F_16 ( & V_3 -> V_17 ) ;
if ( V_12 ) {
F_24 ( & V_3 -> V_10 -> V_3 ,
L_4 ,
V_14 , V_12 ) ;
goto V_65;
}
F_3 ( V_24 ) ;
return V_58 ;
V_65:
F_48 ( V_24 ) ;
error:
if ( V_24 ) {
F_38 ( V_3 -> V_5 , V_58 , V_57 , V_24 -> V_54 ) ;
F_3 ( V_24 ) ;
}
F_39 ( & V_3 -> V_55 ) ;
exit:
return V_12 ;
}
static int F_49 ( struct V_9 * V_10 ,
const struct V_66 * V_18 )
{
struct V_2 * V_3 ;
struct V_67 * V_68 ;
struct V_69 * V_70 ;
T_2 V_71 ;
int V_72 ;
int V_12 = - V_39 ;
V_3 = F_50 ( sizeof( * V_3 ) , V_38 ) ;
if ( ! V_3 ) {
F_24 ( & V_10 -> V_3 , L_5 ) ;
goto error;
}
F_51 ( & V_3 -> V_1 ) ;
F_52 ( & V_3 -> V_55 , V_73 ) ;
F_53 ( & V_3 -> V_17 ) ;
F_54 ( & V_3 -> V_20 ) ;
F_55 ( & V_3 -> V_64 ) ;
F_56 ( & V_3 -> V_33 ) ;
V_3 -> V_5 = F_57 ( F_58 ( V_10 ) ) ;
V_3 -> V_10 = V_10 ;
V_68 = V_10 -> V_74 ;
for ( V_72 = 0 ; V_72 < V_68 -> V_75 . V_76 ; ++ V_72 ) {
V_70 = & V_68 -> V_70 [ V_72 ] . V_75 ;
if ( ! V_3 -> V_36 &&
F_59 ( V_70 ) ) {
V_71 = F_60 ( V_70 ) ;
V_3 -> V_37 = V_71 ;
V_3 -> V_36 = V_70 -> V_77 ;
V_3 -> V_6 = F_61 ( V_71 , V_38 ) ;
if ( ! V_3 -> V_6 ) {
F_24 ( & V_10 -> V_3 ,
L_6 ) ;
goto error;
}
V_3 -> V_4 = F_43 ( 0 , V_38 ) ;
if ( ! V_3 -> V_4 ) {
F_24 ( & V_10 -> V_3 ,
L_7 ) ;
goto error;
}
}
if ( ! V_3 -> V_61 &&
F_62 ( V_70 ) ) {
V_3 -> V_61 = V_70 -> V_77 ;
}
}
if ( ! ( V_3 -> V_36 && V_3 -> V_61 ) ) {
F_24 ( & V_10 -> V_3 ,
L_8 ) ;
goto error;
}
F_63 ( V_10 , V_3 ) ;
V_12 = F_64 ( V_10 , & V_78 ) ;
if ( V_12 ) {
F_24 ( & V_10 -> V_3 ,
L_9 ) ;
F_63 ( V_10 , NULL ) ;
goto error;
}
F_65 ( & V_10 -> V_3 ,
L_10 ,
V_10 -> V_79 ) ;
return 0 ;
error:
if ( V_3 )
F_17 ( & V_3 -> V_1 , F_1 ) ;
return V_12 ;
}
static void F_66 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
int V_79 = V_10 -> V_79 ;
V_3 = F_10 ( V_10 ) ;
F_63 ( V_10 , NULL ) ;
F_67 ( V_10 , & V_78 ) ;
F_14 ( & V_3 -> V_17 ) ;
V_3 -> V_10 = NULL ;
F_16 ( & V_3 -> V_17 ) ;
F_68 ( & V_3 -> V_64 ) ;
F_17 ( & V_3 -> V_1 , F_1 ) ;
F_65 ( & V_10 -> V_3 , L_11 , V_79 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
int time ;
time = F_69 ( & V_3 -> V_64 , 1000 ) ;
if ( ! time )
F_68 ( & V_3 -> V_64 ) ;
F_70 ( V_3 -> V_4 ) ;
}
static int F_71 ( struct V_9 * V_80 , T_5 V_81 )
{
struct V_2 * V_3 = F_10 ( V_80 ) ;
if ( ! V_3 )
return 0 ;
F_19 ( V_3 ) ;
return 0 ;
}
static int F_72 ( struct V_9 * V_80 )
{
return 0 ;
}
static int F_73 ( struct V_9 * V_80 )
{
struct V_2 * V_3 = F_10 ( V_80 ) ;
F_14 ( & V_3 -> V_17 ) ;
F_19 ( V_3 ) ;
return 0 ;
}
static int F_74 ( struct V_9 * V_80 )
{
struct V_2 * V_3 = F_10 ( V_80 ) ;
V_3 -> V_21 = - V_22 ;
F_16 ( & V_3 -> V_17 ) ;
return 0 ;
}
