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
F_11 ( & V_3 -> V_1 ) ;
F_12 ( & V_3 -> V_16 ) ;
if ( ! V_3 -> V_17 ++ ) {
V_12 = F_13 ( V_10 ) ;
if ( V_12 ) {
V_3 -> V_17 -- ;
F_14 ( & V_3 -> V_16 ) ;
F_15 ( & V_3 -> V_1 , F_1 ) ;
goto exit;
}
}
V_8 -> V_18 = V_3 ;
F_14 ( & V_3 -> V_16 ) ;
exit:
return V_12 ;
}
static int F_16 ( struct V_7 * V_7 , struct V_8 * V_8 )
{
struct V_2 * V_3 ;
V_3 = V_8 -> V_18 ;
if ( V_3 == NULL )
return - V_15 ;
F_12 ( & V_3 -> V_16 ) ;
if ( ! -- V_3 -> V_17 && V_3 -> V_10 )
F_17 ( V_3 -> V_10 ) ;
F_14 ( & V_3 -> V_16 ) ;
F_15 ( & V_3 -> V_1 , F_1 ) ;
return 0 ;
}
static int F_18 ( struct V_8 * V_8 , T_1 V_19 )
{
struct V_2 * V_3 ;
int V_20 ;
V_3 = V_8 -> V_18 ;
if ( V_3 == NULL )
return - V_15 ;
F_12 ( & V_3 -> V_16 ) ;
F_19 ( V_3 ) ;
F_20 ( & V_3 -> V_21 ) ;
V_20 = V_3 -> V_22 ? ( V_3 -> V_22 == - V_23 ? - V_23 : - V_24 ) : 0 ;
V_3 -> V_22 = 0 ;
F_21 ( & V_3 -> V_21 ) ;
F_14 ( & V_3 -> V_16 ) ;
return V_20 ;
}
static void F_22 ( struct V_25 * V_25 )
{
struct V_2 * V_3 ;
V_3 = V_25 -> V_26 ;
F_23 ( & V_3 -> V_21 ) ;
if ( V_25 -> V_27 ) {
if ( ! ( V_25 -> V_27 == - V_28 ||
V_25 -> V_27 == - V_29 ||
V_25 -> V_27 == - V_30 ) )
F_9 ( L_2 ,
V_14 , V_25 -> V_27 ) ;
V_3 -> V_22 = V_25 -> V_27 ;
} else {
V_3 -> V_31 = V_25 -> V_32 ;
}
V_3 -> V_33 = 0 ;
F_24 ( & V_3 -> V_21 ) ;
F_25 ( & V_3 -> V_34 ) ;
}
static int F_26 ( struct V_2 * V_3 , T_2 V_35 )
{
int V_36 ;
F_27 ( V_3 -> V_4 ,
V_3 -> V_5 ,
F_28 ( V_3 -> V_5 ,
V_3 -> V_37 ) ,
V_3 -> V_6 ,
F_29 ( V_3 -> V_38 , V_35 ) ,
F_22 ,
V_3 ) ;
F_20 ( & V_3 -> V_21 ) ;
V_3 -> V_33 = 1 ;
F_21 ( & V_3 -> V_21 ) ;
V_36 = F_30 ( V_3 -> V_4 , V_39 ) ;
if ( V_36 < 0 ) {
F_9 ( L_3 ,
V_14 , V_36 ) ;
V_3 -> V_31 = 0 ;
V_36 = ( V_36 == - V_40 ) ? V_36 : - V_24 ;
F_20 ( & V_3 -> V_21 ) ;
V_3 -> V_33 = 0 ;
F_21 ( & V_3 -> V_21 ) ;
}
return V_36 ;
}
static T_3 F_31 ( struct V_8 * V_8 , char * V_41 , T_2 V_35 ,
T_4 * V_42 )
{
struct V_2 * V_3 ;
int V_36 ;
bool V_43 ;
V_3 = V_8 -> V_18 ;
if ( ! V_3 -> V_4 || ! V_35 )
return 0 ;
V_36 = F_32 ( & V_3 -> V_16 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( ! V_3 -> V_10 ) {
V_36 = - V_15 ;
goto exit;
}
V_44:
F_20 ( & V_3 -> V_21 ) ;
V_43 = V_3 -> V_33 ;
F_21 ( & V_3 -> V_21 ) ;
if ( V_43 ) {
if ( V_8 -> V_45 & V_46 ) {
V_36 = - V_47 ;
goto exit;
}
V_36 = F_33 ( & V_3 -> V_34 ) ;
if ( V_36 < 0 )
goto exit;
V_3 -> V_48 = 0 ;
V_3 -> V_49 = 1 ;
}
if ( ! V_3 -> V_49 ) {
F_34 ( & V_3 -> V_34 ) ;
V_3 -> V_48 = 0 ;
V_3 -> V_49 = 1 ;
}
V_36 = V_3 -> V_22 ;
if ( V_36 < 0 ) {
V_3 -> V_22 = 0 ;
V_36 = ( V_36 == - V_23 ) ? V_36 : - V_24 ;
V_3 -> V_31 = 0 ;
goto exit;
}
if ( V_3 -> V_31 ) {
T_2 V_50 = V_3 -> V_31 - V_3 -> V_48 ;
T_2 V_51 = F_29 ( V_50 , V_35 ) ;
if ( ! V_50 ) {
V_36 = F_26 ( V_3 , V_35 ) ;
if ( V_36 < 0 )
goto exit;
else
goto V_44;
}
if ( F_35 ( V_41 ,
V_3 -> V_6 + V_3 -> V_48 ,
V_51 ) )
V_36 = - V_52 ;
else
V_36 = V_51 ;
V_3 -> V_48 += V_51 ;
if ( V_50 < V_35 )
F_26 ( V_3 , V_35 - V_51 ) ;
} else {
V_36 = F_26 ( V_3 , V_35 ) ;
if ( V_36 < 0 )
goto exit;
else if ( ! ( V_8 -> V_45 & V_46 ) )
goto V_44;
V_36 = - V_47 ;
}
exit:
F_14 ( & V_3 -> V_16 ) ;
return V_36 ;
}
static void F_36 ( struct V_25 * V_25 )
{
struct V_2 * V_3 ;
V_3 = V_25 -> V_26 ;
if ( V_25 -> V_27 ) {
if ( ! ( V_25 -> V_27 == - V_28 ||
V_25 -> V_27 == - V_29 ||
V_25 -> V_27 == - V_30 ) )
F_9 ( L_2 ,
V_14 , V_25 -> V_27 ) ;
F_23 ( & V_3 -> V_21 ) ;
V_3 -> V_22 = V_25 -> V_27 ;
F_24 ( & V_3 -> V_21 ) ;
}
F_37 ( V_25 -> V_3 , V_25 -> V_53 ,
V_25 -> V_54 , V_25 -> V_55 ) ;
F_38 ( & V_3 -> V_56 ) ;
}
static T_3 F_39 ( struct V_8 * V_8 , const char * V_57 ,
T_2 V_35 , T_4 * V_42 )
{
struct V_2 * V_3 ;
int V_12 = 0 ;
struct V_25 * V_25 = NULL ;
char * V_58 = NULL ;
T_2 V_59 = F_29 ( V_35 , ( T_2 ) V_60 ) ;
V_3 = V_8 -> V_18 ;
if ( V_35 == 0 )
goto exit;
if ( ! ( V_8 -> V_45 & V_46 ) ) {
if ( F_40 ( & V_3 -> V_56 ) ) {
V_12 = - V_61 ;
goto exit;
}
} else {
if ( F_41 ( & V_3 -> V_56 ) ) {
V_12 = - V_47 ;
goto exit;
}
}
F_20 ( & V_3 -> V_21 ) ;
V_12 = V_3 -> V_22 ;
if ( V_12 < 0 ) {
V_3 -> V_22 = 0 ;
V_12 = ( V_12 == - V_23 ) ? V_12 : - V_24 ;
}
F_21 ( & V_3 -> V_21 ) ;
if ( V_12 < 0 )
goto error;
V_25 = F_42 ( 0 , V_39 ) ;
if ( ! V_25 ) {
V_12 = - V_40 ;
goto error;
}
V_58 = F_43 ( V_3 -> V_5 , V_59 , V_39 ,
& V_25 -> V_55 ) ;
if ( ! V_58 ) {
V_12 = - V_40 ;
goto error;
}
if ( F_44 ( V_58 , V_57 , V_59 ) ) {
V_12 = - V_52 ;
goto error;
}
F_12 ( & V_3 -> V_16 ) ;
if ( ! V_3 -> V_10 ) {
F_14 ( & V_3 -> V_16 ) ;
V_12 = - V_15 ;
goto error;
}
F_27 ( V_25 , V_3 -> V_5 ,
F_45 ( V_3 -> V_5 , V_3 -> V_62 ) ,
V_58 , V_59 , F_36 , V_3 ) ;
V_25 -> V_63 |= V_64 ;
F_46 ( V_25 , & V_3 -> V_65 ) ;
V_12 = F_30 ( V_25 , V_39 ) ;
F_14 ( & V_3 -> V_16 ) ;
if ( V_12 ) {
F_9 ( L_4 , V_14 ,
V_12 ) ;
goto V_66;
}
F_3 ( V_25 ) ;
return V_59 ;
V_66:
F_47 ( V_25 ) ;
error:
if ( V_25 ) {
F_37 ( V_3 -> V_5 , V_59 , V_58 , V_25 -> V_55 ) ;
F_3 ( V_25 ) ;
}
F_38 ( & V_3 -> V_56 ) ;
exit:
return V_12 ;
}
static int F_48 ( struct V_9 * V_10 ,
const struct V_67 * V_19 )
{
struct V_2 * V_3 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
T_2 V_72 ;
int V_73 ;
int V_12 = - V_40 ;
V_3 = F_49 ( sizeof( * V_3 ) , V_39 ) ;
if ( ! V_3 ) {
F_9 ( L_5 ) ;
goto error;
}
F_50 ( & V_3 -> V_1 ) ;
F_51 ( & V_3 -> V_56 , V_74 ) ;
F_52 ( & V_3 -> V_16 ) ;
F_53 ( & V_3 -> V_21 ) ;
F_54 ( & V_3 -> V_65 ) ;
F_55 ( & V_3 -> V_34 ) ;
V_3 -> V_5 = F_56 ( F_57 ( V_10 ) ) ;
V_3 -> V_10 = V_10 ;
V_69 = V_10 -> V_75 ;
for ( V_73 = 0 ; V_73 < V_69 -> V_76 . V_77 ; ++ V_73 ) {
V_71 = & V_69 -> V_71 [ V_73 ] . V_76 ;
if ( ! V_3 -> V_37 &&
F_58 ( V_71 ) ) {
V_72 = F_59 ( V_71 -> V_78 ) ;
V_3 -> V_38 = V_72 ;
V_3 -> V_37 = V_71 -> V_79 ;
V_3 -> V_6 = F_60 ( V_72 , V_39 ) ;
if ( ! V_3 -> V_6 ) {
F_9 ( L_6 ) ;
goto error;
}
V_3 -> V_4 = F_42 ( 0 , V_39 ) ;
if ( ! V_3 -> V_4 ) {
F_9 ( L_7 ) ;
goto error;
}
}
if ( ! V_3 -> V_62 &&
F_61 ( V_71 ) ) {
V_3 -> V_62 = V_71 -> V_79 ;
}
}
if ( ! ( V_3 -> V_37 && V_3 -> V_62 ) ) {
F_9 ( L_8 ) ;
goto error;
}
F_62 ( V_10 , V_3 ) ;
V_12 = F_63 ( V_10 , & V_80 ) ;
if ( V_12 ) {
F_9 ( L_9 ) ;
F_62 ( V_10 , NULL ) ;
goto error;
}
F_64 ( & V_10 -> V_3 ,
L_10 ,
V_10 -> V_81 ) ;
return 0 ;
error:
if ( V_3 )
F_15 ( & V_3 -> V_1 , F_1 ) ;
return V_12 ;
}
static void F_65 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
int V_81 = V_10 -> V_81 ;
V_3 = F_10 ( V_10 ) ;
F_62 ( V_10 , NULL ) ;
F_66 ( V_10 , & V_80 ) ;
F_12 ( & V_3 -> V_16 ) ;
V_3 -> V_10 = NULL ;
F_14 ( & V_3 -> V_16 ) ;
F_67 ( & V_3 -> V_65 ) ;
F_15 ( & V_3 -> V_1 , F_1 ) ;
F_64 ( & V_10 -> V_3 , L_11 , V_81 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
int time ;
time = F_68 ( & V_3 -> V_65 , 1000 ) ;
if ( ! time )
F_67 ( & V_3 -> V_65 ) ;
F_69 ( V_3 -> V_4 ) ;
}
static int F_70 ( struct V_9 * V_82 , T_5 V_83 )
{
struct V_2 * V_3 = F_10 ( V_82 ) ;
if ( ! V_3 )
return 0 ;
F_19 ( V_3 ) ;
return 0 ;
}
static int F_71 ( struct V_9 * V_82 )
{
return 0 ;
}
static int F_72 ( struct V_9 * V_82 )
{
struct V_2 * V_3 = F_10 ( V_82 ) ;
F_12 ( & V_3 -> V_16 ) ;
F_19 ( V_3 ) ;
return 0 ;
}
static int F_73 ( struct V_9 * V_82 )
{
struct V_2 * V_3 = F_10 ( V_82 ) ;
V_3 -> V_22 = - V_23 ;
F_14 ( & V_3 -> V_16 ) ;
return 0 ;
}
static int T_6 F_74 ( void )
{
int V_84 ;
V_84 = F_75 ( & V_13 ) ;
if ( V_84 )
F_9 ( L_12 , V_84 ) ;
return V_84 ;
}
static void T_7 F_76 ( void )
{
F_77 ( & V_13 ) ;
}
