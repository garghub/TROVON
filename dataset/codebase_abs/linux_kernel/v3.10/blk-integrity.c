int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_4 * V_5 , * V_6 = NULL ;
unsigned int V_7 = 0 ;
unsigned int V_8 = 0 ;
unsigned int V_9 = 0 ;
F_2 (iv, bio, i) {
if ( V_6 ) {
if ( ! F_3 ( V_6 , V_5 ) )
goto V_10;
if ( ! F_4 ( V_2 , V_6 , V_5 ) )
goto V_10;
if ( V_8 + V_5 -> V_11 > F_5 ( V_2 ) )
goto V_10;
V_8 += V_5 -> V_11 ;
} else {
V_10:
V_7 ++ ;
V_8 = V_5 -> V_11 ;
}
V_6 = V_5 ;
}
return V_7 ;
}
int F_6 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_12 * V_13 )
{
struct V_4 * V_5 , * V_6 = NULL ;
struct V_12 * V_14 = NULL ;
unsigned int V_7 = 0 ;
unsigned int V_9 = 0 ;
F_2 (iv, bio, i) {
if ( V_6 ) {
if ( ! F_3 ( V_6 , V_5 ) )
goto V_10;
if ( ! F_4 ( V_2 , V_6 , V_5 ) )
goto V_10;
if ( V_14 -> V_15 + V_5 -> V_11 > F_5 ( V_2 ) )
goto V_10;
V_14 -> V_15 += V_5 -> V_11 ;
} else {
V_10:
if ( ! V_14 )
V_14 = V_13 ;
else {
F_7 ( V_14 ) ;
V_14 = F_8 ( V_14 ) ;
}
F_9 ( V_14 , V_5 -> V_16 , V_5 -> V_11 , V_5 -> V_17 ) ;
V_7 ++ ;
}
V_6 = V_5 ;
}
if ( V_14 )
F_10 ( V_14 ) ;
return V_7 ;
}
int F_11 ( struct V_18 * V_19 , struct V_18 * V_20 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
struct V_21 * V_24 = V_20 -> V_23 ;
if ( ! V_22 && ! V_24 )
return 0 ;
if ( ! V_22 || ! V_24 )
return - 1 ;
if ( V_22 -> V_25 != V_24 -> V_25 ) {
F_12 ( V_26 L_1 , V_27 ,
V_19 -> V_28 , V_20 -> V_28 ,
V_22 -> V_25 , V_24 -> V_25 ) ;
return - 1 ;
}
if ( V_22 -> V_29 != V_24 -> V_29 ) {
F_12 ( V_26 L_2 , V_27 ,
V_19 -> V_28 , V_20 -> V_28 ,
V_22 -> V_29 , V_24 -> V_29 ) ;
return - 1 ;
}
if ( V_22 -> V_30 && V_24 -> V_30 && ( V_22 -> V_30 != V_24 -> V_30 ) ) {
F_12 ( V_26 L_3 , V_27 ,
V_19 -> V_28 , V_20 -> V_28 ,
V_22 -> V_30 , V_24 -> V_30 ) ;
return - 1 ;
}
if ( strcmp ( V_22 -> V_31 , V_24 -> V_31 ) ) {
F_12 ( V_26 L_4 , V_27 ,
V_19 -> V_28 , V_20 -> V_28 ,
V_22 -> V_31 , V_24 -> V_31 ) ;
return - 1 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 , struct V_32 * V_33 ,
struct V_32 * V_34 )
{
if ( F_14 ( V_33 ) != F_14 ( V_34 ) )
return - 1 ;
if ( V_33 -> V_35 + V_34 -> V_35 >
V_2 -> V_36 . V_37 )
return - 1 ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , struct V_32 * V_33 ,
struct V_3 * V_3 )
{
int V_38 ;
struct V_3 * V_34 = V_3 -> V_39 ;
V_3 -> V_39 = NULL ;
V_38 = F_1 ( V_2 , V_3 ) ;
V_3 -> V_39 = V_34 ;
if ( V_33 -> V_35 + V_38 >
V_2 -> V_36 . V_37 )
return - 1 ;
V_33 -> V_35 += V_38 ;
return 0 ;
}
static T_1 F_16 ( struct V_40 * V_41 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_21 * V_45 =
F_17 ( V_41 , struct V_21 , V_41 ) ;
struct V_46 * V_47 =
F_17 ( V_43 , struct V_46 , V_43 ) ;
return V_47 -> V_48 ( V_45 , V_44 ) ;
}
static T_1 F_18 ( struct V_40 * V_41 ,
struct V_42 * V_43 , const char * V_44 ,
T_2 V_49 )
{
struct V_21 * V_45 =
F_17 ( V_41 , struct V_21 , V_41 ) ;
struct V_46 * V_47 =
F_17 ( V_43 , struct V_46 , V_43 ) ;
T_1 V_50 = 0 ;
if ( V_47 -> V_51 )
V_50 = V_47 -> V_51 ( V_45 , V_44 , V_49 ) ;
return V_50 ;
}
static T_1 F_19 ( struct V_21 * V_45 , char * V_44 )
{
if ( V_45 != NULL && V_45 -> V_31 != NULL )
return sprintf ( V_44 , L_5 , V_45 -> V_31 ) ;
else
return sprintf ( V_44 , L_6 ) ;
}
static T_1 F_20 ( struct V_21 * V_45 , char * V_44 )
{
if ( V_45 != NULL )
return sprintf ( V_44 , L_7 , V_45 -> V_30 ) ;
else
return sprintf ( V_44 , L_8 ) ;
}
static T_1 F_21 ( struct V_21 * V_45 ,
const char * V_44 , T_2 V_49 )
{
char * V_52 = ( char * ) V_44 ;
unsigned long V_53 = F_22 ( V_52 , & V_52 , 10 ) ;
if ( V_53 )
V_45 -> V_54 |= V_55 ;
else
V_45 -> V_54 &= ~ V_55 ;
return V_49 ;
}
static T_1 F_23 ( struct V_21 * V_45 , char * V_44 )
{
return sprintf ( V_44 , L_9 , ( V_45 -> V_54 & V_55 ) != 0 ) ;
}
static T_1 F_24 ( struct V_21 * V_45 ,
const char * V_44 , T_2 V_49 )
{
char * V_52 = ( char * ) V_44 ;
unsigned long V_53 = F_22 ( V_52 , & V_52 , 10 ) ;
if ( V_53 )
V_45 -> V_54 |= V_56 ;
else
V_45 -> V_54 &= ~ V_56 ;
return V_49 ;
}
static T_1 F_25 ( struct V_21 * V_45 , char * V_44 )
{
return sprintf ( V_44 , L_9 , ( V_45 -> V_54 & V_56 ) != 0 ) ;
}
static int T_3 F_26 ( void )
{
V_57 = F_27 ( L_10 ,
sizeof( struct V_21 ) ,
0 , V_58 , NULL ) ;
return 0 ;
}
static void F_28 ( struct V_40 * V_41 )
{
struct V_21 * V_45 =
F_17 ( V_41 , struct V_21 , V_41 ) ;
F_29 ( V_57 , V_45 ) ;
}
bool F_30 ( struct V_18 * V_59 )
{
struct V_21 * V_45 = F_31 ( V_59 ) ;
return ( V_45 && V_45 -> V_31 && strcmp ( V_45 -> V_31 , V_60 ) != 0 ) ;
}
int F_32 ( struct V_18 * V_59 , struct V_21 * V_61 )
{
struct V_21 * V_45 ;
F_33 ( V_59 == NULL ) ;
if ( V_59 -> V_23 == NULL ) {
V_45 = F_34 ( V_57 ,
V_62 | V_63 ) ;
if ( ! V_45 )
return - 1 ;
if ( F_35 ( & V_45 -> V_41 , & V_64 ,
& F_36 ( V_59 ) -> V_41 ,
L_11 , L_12 ) ) {
F_29 ( V_57 , V_45 ) ;
return - 1 ;
}
F_37 ( & V_45 -> V_41 , V_65 ) ;
V_45 -> V_54 |= V_55 | V_56 ;
V_45 -> V_25 = F_38 ( V_59 -> V_66 ) ;
V_59 -> V_23 = V_45 ;
} else
V_45 = V_59 -> V_23 ;
if ( V_61 != NULL ) {
V_45 -> V_31 = V_61 -> V_31 ;
V_45 -> V_67 = V_61 -> V_67 ;
V_45 -> V_68 = V_61 -> V_68 ;
V_45 -> V_29 = V_61 -> V_29 ;
V_45 -> V_69 = V_61 -> V_69 ;
V_45 -> V_70 = V_61 -> V_70 ;
V_45 -> V_30 = V_61 -> V_30 ;
} else
V_45 -> V_31 = V_60 ;
V_59 -> V_66 -> V_71 . V_72 |= V_73 ;
return 0 ;
}
void F_39 ( struct V_18 * V_59 )
{
struct V_21 * V_45 ;
if ( ! V_59 || ! V_59 -> V_23 )
return;
V_59 -> V_66 -> V_71 . V_72 &= ~ V_73 ;
V_45 = V_59 -> V_23 ;
F_37 ( & V_45 -> V_41 , V_74 ) ;
F_40 ( & V_45 -> V_41 ) ;
F_41 ( & V_45 -> V_41 ) ;
V_59 -> V_23 = NULL ;
}
