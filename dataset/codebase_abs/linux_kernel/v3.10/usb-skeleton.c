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
V_3 -> V_30 = 0 ;
V_3 -> V_38 = 0 ;
V_35 = F_31 ( V_3 -> V_4 , V_39 ) ;
if ( V_35 < 0 ) {
F_24 ( & V_3 -> V_10 -> V_3 ,
L_3 ,
V_14 , V_35 ) ;
V_35 = ( V_35 == - V_40 ) ? V_35 : - V_23 ;
F_20 ( & V_3 -> V_20 ) ;
V_3 -> V_32 = 0 ;
F_21 ( & V_3 -> V_20 ) ;
}
return V_35 ;
}
static T_3 F_32 ( struct V_8 * V_8 , char * V_41 , T_2 V_34 ,
T_4 * V_42 )
{
struct V_2 * V_3 ;
int V_35 ;
bool V_43 ;
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
V_44:
F_20 ( & V_3 -> V_20 ) ;
V_43 = V_3 -> V_32 ;
F_21 ( & V_3 -> V_20 ) ;
if ( V_43 ) {
if ( V_8 -> V_45 & V_46 ) {
V_35 = - V_47 ;
goto exit;
}
V_35 = F_34 ( V_3 -> V_33 , ( ! V_3 -> V_32 ) ) ;
if ( V_35 < 0 )
goto exit;
}
V_35 = V_3 -> V_21 ;
if ( V_35 < 0 ) {
V_3 -> V_21 = 0 ;
V_35 = ( V_35 == - V_22 ) ? V_35 : - V_23 ;
goto exit;
}
if ( V_3 -> V_30 ) {
T_2 V_48 = V_3 -> V_30 - V_3 -> V_38 ;
T_2 V_49 = F_30 ( V_48 , V_34 ) ;
if ( ! V_48 ) {
V_35 = F_27 ( V_3 , V_34 ) ;
if ( V_35 < 0 )
goto exit;
else
goto V_44;
}
if ( F_35 ( V_41 ,
V_3 -> V_6 + V_3 -> V_38 ,
V_49 ) )
V_35 = - V_50 ;
else
V_35 = V_49 ;
V_3 -> V_38 += V_49 ;
if ( V_48 < V_34 )
F_27 ( V_3 , V_34 - V_49 ) ;
} else {
V_35 = F_27 ( V_3 , V_34 ) ;
if ( V_35 < 0 )
goto exit;
else if ( ! ( V_8 -> V_45 & V_46 ) )
goto V_44;
V_35 = - V_47 ;
}
exit:
F_16 ( & V_3 -> V_17 ) ;
return V_35 ;
}
static void F_36 ( struct V_24 * V_24 )
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
F_37 ( V_24 -> V_3 , V_24 -> V_51 ,
V_24 -> V_52 , V_24 -> V_53 ) ;
F_38 ( & V_3 -> V_54 ) ;
}
static T_3 F_39 ( struct V_8 * V_8 , const char * V_55 ,
T_2 V_34 , T_4 * V_42 )
{
struct V_2 * V_3 ;
int V_12 = 0 ;
struct V_24 * V_24 = NULL ;
char * V_56 = NULL ;
T_2 V_57 = F_30 ( V_34 , ( T_2 ) V_58 ) ;
V_3 = V_8 -> V_16 ;
if ( V_34 == 0 )
goto exit;
if ( ! ( V_8 -> V_45 & V_46 ) ) {
if ( F_40 ( & V_3 -> V_54 ) ) {
V_12 = - V_59 ;
goto exit;
}
} else {
if ( F_41 ( & V_3 -> V_54 ) ) {
V_12 = - V_47 ;
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
V_24 = F_42 ( 0 , V_39 ) ;
if ( ! V_24 ) {
V_12 = - V_40 ;
goto error;
}
V_56 = F_43 ( V_3 -> V_5 , V_57 , V_39 ,
& V_24 -> V_53 ) ;
if ( ! V_56 ) {
V_12 = - V_40 ;
goto error;
}
if ( F_44 ( V_56 , V_55 , V_57 ) ) {
V_12 = - V_50 ;
goto error;
}
F_14 ( & V_3 -> V_17 ) ;
if ( ! V_3 -> V_10 ) {
F_16 ( & V_3 -> V_17 ) ;
V_12 = - V_15 ;
goto error;
}
F_28 ( V_24 , V_3 -> V_5 ,
F_45 ( V_3 -> V_5 , V_3 -> V_60 ) ,
V_56 , V_57 , F_36 , V_3 ) ;
V_24 -> V_61 |= V_62 ;
F_46 ( V_24 , & V_3 -> V_63 ) ;
V_12 = F_31 ( V_24 , V_39 ) ;
F_16 ( & V_3 -> V_17 ) ;
if ( V_12 ) {
F_24 ( & V_3 -> V_10 -> V_3 ,
L_4 ,
V_14 , V_12 ) ;
goto V_64;
}
F_3 ( V_24 ) ;
return V_57 ;
V_64:
F_47 ( V_24 ) ;
error:
if ( V_24 ) {
F_37 ( V_3 -> V_5 , V_57 , V_56 , V_24 -> V_53 ) ;
F_3 ( V_24 ) ;
}
F_38 ( & V_3 -> V_54 ) ;
exit:
return V_12 ;
}
static int F_48 ( struct V_9 * V_10 ,
const struct V_65 * V_18 )
{
struct V_2 * V_3 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
T_2 V_70 ;
int V_71 ;
int V_12 = - V_40 ;
V_3 = F_49 ( sizeof( * V_3 ) , V_39 ) ;
if ( ! V_3 ) {
F_24 ( & V_10 -> V_3 , L_5 ) ;
goto error;
}
F_50 ( & V_3 -> V_1 ) ;
F_51 ( & V_3 -> V_54 , V_72 ) ;
F_52 ( & V_3 -> V_17 ) ;
F_53 ( & V_3 -> V_20 ) ;
F_54 ( & V_3 -> V_63 ) ;
F_55 ( & V_3 -> V_33 ) ;
V_3 -> V_5 = F_56 ( F_57 ( V_10 ) ) ;
V_3 -> V_10 = V_10 ;
V_67 = V_10 -> V_73 ;
for ( V_71 = 0 ; V_71 < V_67 -> V_74 . V_75 ; ++ V_71 ) {
V_69 = & V_67 -> V_69 [ V_71 ] . V_74 ;
if ( ! V_3 -> V_36 &&
F_58 ( V_69 ) ) {
V_70 = F_59 ( V_69 ) ;
V_3 -> V_37 = V_70 ;
V_3 -> V_36 = V_69 -> V_76 ;
V_3 -> V_6 = F_60 ( V_70 , V_39 ) ;
if ( ! V_3 -> V_6 ) {
F_24 ( & V_10 -> V_3 ,
L_6 ) ;
goto error;
}
V_3 -> V_4 = F_42 ( 0 , V_39 ) ;
if ( ! V_3 -> V_4 ) {
F_24 ( & V_10 -> V_3 ,
L_7 ) ;
goto error;
}
}
if ( ! V_3 -> V_60 &&
F_61 ( V_69 ) ) {
V_3 -> V_60 = V_69 -> V_76 ;
}
}
if ( ! ( V_3 -> V_36 && V_3 -> V_60 ) ) {
F_24 ( & V_10 -> V_3 ,
L_8 ) ;
goto error;
}
F_62 ( V_10 , V_3 ) ;
V_12 = F_63 ( V_10 , & V_77 ) ;
if ( V_12 ) {
F_24 ( & V_10 -> V_3 ,
L_9 ) ;
F_62 ( V_10 , NULL ) ;
goto error;
}
F_64 ( & V_10 -> V_3 ,
L_10 ,
V_10 -> V_78 ) ;
return 0 ;
error:
if ( V_3 )
F_17 ( & V_3 -> V_1 , F_1 ) ;
return V_12 ;
}
static void F_65 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
int V_78 = V_10 -> V_78 ;
V_3 = F_10 ( V_10 ) ;
F_62 ( V_10 , NULL ) ;
F_66 ( V_10 , & V_77 ) ;
F_14 ( & V_3 -> V_17 ) ;
V_3 -> V_10 = NULL ;
F_16 ( & V_3 -> V_17 ) ;
F_67 ( & V_3 -> V_63 ) ;
F_17 ( & V_3 -> V_1 , F_1 ) ;
F_64 ( & V_10 -> V_3 , L_11 , V_78 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
int time ;
time = F_68 ( & V_3 -> V_63 , 1000 ) ;
if ( ! time )
F_67 ( & V_3 -> V_63 ) ;
F_69 ( V_3 -> V_4 ) ;
}
static int F_70 ( struct V_9 * V_79 , T_5 V_80 )
{
struct V_2 * V_3 = F_10 ( V_79 ) ;
if ( ! V_3 )
return 0 ;
F_19 ( V_3 ) ;
return 0 ;
}
static int F_71 ( struct V_9 * V_79 )
{
return 0 ;
}
static int F_72 ( struct V_9 * V_79 )
{
struct V_2 * V_3 = F_10 ( V_79 ) ;
F_14 ( & V_3 -> V_17 ) ;
F_19 ( V_3 ) ;
return 0 ;
}
static int F_73 ( struct V_9 * V_79 )
{
struct V_2 * V_3 = F_10 ( V_79 ) ;
V_3 -> V_21 = - V_22 ;
F_16 ( & V_3 -> V_17 ) ;
return 0 ;
}
