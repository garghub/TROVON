int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_4 V_5 , V_6 = { NULL } ;
unsigned int V_7 = 0 ;
unsigned int V_8 = 0 ;
struct V_9 V_10 ;
int V_11 = 0 ;
F_2 (iv, bio, iter) {
if ( V_11 ) {
if ( ! F_3 ( & V_6 , & V_5 ) )
goto V_12;
if ( ! F_4 ( V_2 , & V_6 , & V_5 ) )
goto V_12;
if ( V_8 + V_5 . V_13 > F_5 ( V_2 ) )
goto V_12;
V_8 += V_5 . V_13 ;
} else {
V_12:
V_7 ++ ;
V_8 = V_5 . V_13 ;
}
V_11 = 1 ;
V_6 = V_5 ;
}
return V_7 ;
}
int F_6 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_14 * V_15 )
{
struct V_4 V_5 , V_6 = { NULL } ;
struct V_14 * V_16 = NULL ;
unsigned int V_7 = 0 ;
struct V_9 V_10 ;
int V_11 = 0 ;
F_2 (iv, bio, iter) {
if ( V_11 ) {
if ( ! F_3 ( & V_6 , & V_5 ) )
goto V_12;
if ( ! F_4 ( V_2 , & V_6 , & V_5 ) )
goto V_12;
if ( V_16 -> V_17 + V_5 . V_13 > F_5 ( V_2 ) )
goto V_12;
V_16 -> V_17 += V_5 . V_13 ;
} else {
V_12:
if ( ! V_16 )
V_16 = V_15 ;
else {
F_7 ( V_16 ) ;
V_16 = F_8 ( V_16 ) ;
}
F_9 ( V_16 , V_5 . V_18 , V_5 . V_13 , V_5 . V_19 ) ;
V_7 ++ ;
}
V_11 = 1 ;
V_6 = V_5 ;
}
if ( V_16 )
F_10 ( V_16 ) ;
return V_7 ;
}
int F_11 ( struct V_20 * V_21 , struct V_20 * V_22 )
{
struct V_23 * V_24 = V_21 -> V_25 ;
struct V_23 * V_26 = V_22 -> V_25 ;
if ( ! V_24 && ! V_26 )
return 0 ;
if ( ! V_24 || ! V_26 )
return - 1 ;
if ( V_24 -> V_27 != V_26 -> V_27 ) {
F_12 ( V_28 L_1 , V_29 ,
V_21 -> V_30 , V_22 -> V_30 ,
V_24 -> V_27 , V_26 -> V_27 ) ;
return - 1 ;
}
if ( V_24 -> V_31 != V_26 -> V_31 ) {
F_12 ( V_28 L_2 , V_29 ,
V_21 -> V_30 , V_22 -> V_30 ,
V_24 -> V_31 , V_26 -> V_31 ) ;
return - 1 ;
}
if ( V_24 -> V_32 && V_26 -> V_32 && ( V_24 -> V_32 != V_26 -> V_32 ) ) {
F_12 ( V_28 L_3 , V_29 ,
V_21 -> V_30 , V_22 -> V_30 ,
V_24 -> V_32 , V_26 -> V_32 ) ;
return - 1 ;
}
if ( strcmp ( V_24 -> V_33 , V_26 -> V_33 ) ) {
F_12 ( V_28 L_4 , V_29 ,
V_21 -> V_30 , V_22 -> V_30 ,
V_24 -> V_33 , V_26 -> V_33 ) ;
return - 1 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 , struct V_34 * V_35 ,
struct V_34 * V_36 )
{
if ( F_14 ( V_35 ) != F_14 ( V_36 ) )
return - 1 ;
if ( V_35 -> V_37 + V_36 -> V_37 >
V_2 -> V_38 . V_39 )
return - 1 ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , struct V_34 * V_35 ,
struct V_3 * V_3 )
{
int V_40 ;
struct V_3 * V_36 = V_3 -> V_41 ;
V_3 -> V_41 = NULL ;
V_40 = F_1 ( V_2 , V_3 ) ;
V_3 -> V_41 = V_36 ;
if ( V_35 -> V_37 + V_40 >
V_2 -> V_38 . V_39 )
return - 1 ;
V_35 -> V_37 += V_40 ;
return 0 ;
}
static T_1 F_16 ( struct V_42 * V_43 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_23 * V_47 =
F_17 ( V_43 , struct V_23 , V_43 ) ;
struct V_48 * V_49 =
F_17 ( V_45 , struct V_48 , V_45 ) ;
return V_49 -> V_50 ( V_47 , V_46 ) ;
}
static T_1 F_18 ( struct V_42 * V_43 ,
struct V_44 * V_45 , const char * V_46 ,
T_2 V_51 )
{
struct V_23 * V_47 =
F_17 ( V_43 , struct V_23 , V_43 ) ;
struct V_48 * V_49 =
F_17 ( V_45 , struct V_48 , V_45 ) ;
T_1 V_52 = 0 ;
if ( V_49 -> V_53 )
V_52 = V_49 -> V_53 ( V_47 , V_46 , V_51 ) ;
return V_52 ;
}
static T_1 F_19 ( struct V_23 * V_47 , char * V_46 )
{
if ( V_47 != NULL && V_47 -> V_33 != NULL )
return sprintf ( V_46 , L_5 , V_47 -> V_33 ) ;
else
return sprintf ( V_46 , L_6 ) ;
}
static T_1 F_20 ( struct V_23 * V_47 , char * V_46 )
{
if ( V_47 != NULL )
return sprintf ( V_46 , L_7 , V_47 -> V_32 ) ;
else
return sprintf ( V_46 , L_8 ) ;
}
static T_1 F_21 ( struct V_23 * V_47 ,
const char * V_46 , T_2 V_51 )
{
char * V_54 = ( char * ) V_46 ;
unsigned long V_55 = F_22 ( V_54 , & V_54 , 10 ) ;
if ( V_55 )
V_47 -> V_56 |= V_57 ;
else
V_47 -> V_56 &= ~ V_57 ;
return V_51 ;
}
static T_1 F_23 ( struct V_23 * V_47 , char * V_46 )
{
return sprintf ( V_46 , L_9 , ( V_47 -> V_56 & V_57 ) != 0 ) ;
}
static T_1 F_24 ( struct V_23 * V_47 ,
const char * V_46 , T_2 V_51 )
{
char * V_54 = ( char * ) V_46 ;
unsigned long V_55 = F_22 ( V_54 , & V_54 , 10 ) ;
if ( V_55 )
V_47 -> V_56 |= V_58 ;
else
V_47 -> V_56 &= ~ V_58 ;
return V_51 ;
}
static T_1 F_25 ( struct V_23 * V_47 , char * V_46 )
{
return sprintf ( V_46 , L_9 , ( V_47 -> V_56 & V_58 ) != 0 ) ;
}
static int T_3 F_26 ( void )
{
V_59 = F_27 ( L_10 ,
sizeof( struct V_23 ) ,
0 , V_60 , NULL ) ;
return 0 ;
}
static void F_28 ( struct V_42 * V_43 )
{
struct V_23 * V_47 =
F_17 ( V_43 , struct V_23 , V_43 ) ;
F_29 ( V_59 , V_47 ) ;
}
bool F_30 ( struct V_20 * V_61 )
{
struct V_23 * V_47 = F_31 ( V_61 ) ;
return ( V_47 && V_47 -> V_33 && strcmp ( V_47 -> V_33 , V_62 ) != 0 ) ;
}
int F_32 ( struct V_20 * V_61 , struct V_23 * V_63 )
{
struct V_23 * V_47 ;
F_33 ( V_61 == NULL ) ;
if ( V_61 -> V_25 == NULL ) {
V_47 = F_34 ( V_59 ,
V_64 | V_65 ) ;
if ( ! V_47 )
return - 1 ;
if ( F_35 ( & V_47 -> V_43 , & V_66 ,
& F_36 ( V_61 ) -> V_43 ,
L_11 , L_12 ) ) {
F_29 ( V_59 , V_47 ) ;
return - 1 ;
}
F_37 ( & V_47 -> V_43 , V_67 ) ;
V_47 -> V_56 |= V_57 | V_58 ;
V_47 -> V_27 = F_38 ( V_61 -> V_68 ) ;
V_61 -> V_25 = V_47 ;
} else
V_47 = V_61 -> V_25 ;
if ( V_63 != NULL ) {
V_47 -> V_33 = V_63 -> V_33 ;
V_47 -> V_69 = V_63 -> V_69 ;
V_47 -> V_70 = V_63 -> V_70 ;
V_47 -> V_31 = V_63 -> V_31 ;
V_47 -> V_71 = V_63 -> V_71 ;
V_47 -> V_72 = V_63 -> V_72 ;
V_47 -> V_32 = V_63 -> V_32 ;
} else
V_47 -> V_33 = V_62 ;
V_61 -> V_68 -> V_73 . V_74 |= V_75 ;
return 0 ;
}
void F_39 ( struct V_20 * V_61 )
{
struct V_23 * V_47 ;
if ( ! V_61 || ! V_61 -> V_25 )
return;
V_61 -> V_68 -> V_73 . V_74 &= ~ V_75 ;
V_47 = V_61 -> V_25 ;
F_37 ( & V_47 -> V_43 , V_76 ) ;
F_40 ( & V_47 -> V_43 ) ;
F_41 ( & V_47 -> V_43 ) ;
V_61 -> V_25 = NULL ;
}
