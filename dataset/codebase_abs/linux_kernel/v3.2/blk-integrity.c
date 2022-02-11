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
V_14 -> V_16 &= ~ 0x02 ;
V_14 = F_7 ( V_14 ) ;
}
F_8 ( V_14 , V_5 -> V_17 , V_5 -> V_11 , V_5 -> V_18 ) ;
V_7 ++ ;
}
V_6 = V_5 ;
}
if ( V_14 )
F_9 ( V_14 ) ;
return V_7 ;
}
int F_10 ( struct V_19 * V_20 , struct V_19 * V_21 )
{
struct V_22 * V_23 = V_20 -> V_24 ;
struct V_22 * V_25 = V_21 -> V_24 ;
if ( ! V_23 && ! V_25 )
return 0 ;
if ( ! V_23 || ! V_25 )
return - 1 ;
if ( V_23 -> V_26 != V_25 -> V_26 ) {
F_11 ( V_27 L_1 , V_28 ,
V_20 -> V_29 , V_21 -> V_29 ,
V_23 -> V_26 , V_25 -> V_26 ) ;
return - 1 ;
}
if ( V_23 -> V_30 != V_25 -> V_30 ) {
F_11 ( V_27 L_2 , V_28 ,
V_20 -> V_29 , V_21 -> V_29 ,
V_23 -> V_30 , V_25 -> V_30 ) ;
return - 1 ;
}
if ( V_23 -> V_31 && V_25 -> V_31 && ( V_23 -> V_31 != V_25 -> V_31 ) ) {
F_11 ( V_27 L_3 , V_28 ,
V_20 -> V_29 , V_21 -> V_29 ,
V_23 -> V_31 , V_25 -> V_31 ) ;
return - 1 ;
}
if ( strcmp ( V_23 -> V_32 , V_25 -> V_32 ) ) {
F_11 ( V_27 L_4 , V_28 ,
V_20 -> V_29 , V_21 -> V_29 ,
V_23 -> V_32 , V_25 -> V_32 ) ;
return - 1 ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_33 * V_34 ,
struct V_33 * V_35 )
{
if ( F_13 ( V_34 ) != F_13 ( V_35 ) )
return - 1 ;
if ( V_34 -> V_36 + V_35 -> V_36 >
V_2 -> V_37 . V_38 )
return - 1 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , struct V_33 * V_34 ,
struct V_3 * V_3 )
{
int V_39 ;
struct V_3 * V_35 = V_3 -> V_40 ;
V_3 -> V_40 = NULL ;
V_39 = F_1 ( V_2 , V_3 ) ;
V_3 -> V_40 = V_35 ;
if ( V_34 -> V_36 + V_39 >
V_2 -> V_37 . V_38 )
return - 1 ;
V_34 -> V_36 += V_39 ;
return 0 ;
}
static T_1 F_15 ( struct V_41 * V_42 , struct V_43 * V_44 ,
char * V_45 )
{
struct V_22 * V_46 =
F_16 ( V_42 , struct V_22 , V_42 ) ;
struct V_47 * V_48 =
F_16 ( V_44 , struct V_47 , V_44 ) ;
return V_48 -> V_49 ( V_46 , V_45 ) ;
}
static T_1 F_17 ( struct V_41 * V_42 ,
struct V_43 * V_44 , const char * V_45 ,
T_2 V_50 )
{
struct V_22 * V_46 =
F_16 ( V_42 , struct V_22 , V_42 ) ;
struct V_47 * V_48 =
F_16 ( V_44 , struct V_47 , V_44 ) ;
T_1 V_51 = 0 ;
if ( V_48 -> V_52 )
V_51 = V_48 -> V_52 ( V_46 , V_45 , V_50 ) ;
return V_51 ;
}
static T_1 F_18 ( struct V_22 * V_46 , char * V_45 )
{
if ( V_46 != NULL && V_46 -> V_32 != NULL )
return sprintf ( V_45 , L_5 , V_46 -> V_32 ) ;
else
return sprintf ( V_45 , L_6 ) ;
}
static T_1 F_19 ( struct V_22 * V_46 , char * V_45 )
{
if ( V_46 != NULL )
return sprintf ( V_45 , L_7 , V_46 -> V_31 ) ;
else
return sprintf ( V_45 , L_8 ) ;
}
static T_1 F_20 ( struct V_22 * V_46 ,
const char * V_45 , T_2 V_50 )
{
char * V_53 = ( char * ) V_45 ;
unsigned long V_54 = F_21 ( V_53 , & V_53 , 10 ) ;
if ( V_54 )
V_46 -> V_55 |= V_56 ;
else
V_46 -> V_55 &= ~ V_56 ;
return V_50 ;
}
static T_1 F_22 ( struct V_22 * V_46 , char * V_45 )
{
return sprintf ( V_45 , L_9 , ( V_46 -> V_55 & V_56 ) != 0 ) ;
}
static T_1 F_23 ( struct V_22 * V_46 ,
const char * V_45 , T_2 V_50 )
{
char * V_53 = ( char * ) V_45 ;
unsigned long V_54 = F_21 ( V_53 , & V_53 , 10 ) ;
if ( V_54 )
V_46 -> V_55 |= V_57 ;
else
V_46 -> V_55 &= ~ V_57 ;
return V_50 ;
}
static T_1 F_24 ( struct V_22 * V_46 , char * V_45 )
{
return sprintf ( V_45 , L_9 , ( V_46 -> V_55 & V_57 ) != 0 ) ;
}
static int T_3 F_25 ( void )
{
V_58 = F_26 ( L_10 ,
sizeof( struct V_22 ) ,
0 , V_59 , NULL ) ;
return 0 ;
}
static void F_27 ( struct V_41 * V_42 )
{
struct V_22 * V_46 =
F_16 ( V_42 , struct V_22 , V_42 ) ;
F_28 ( V_58 , V_46 ) ;
}
bool F_29 ( struct V_19 * V_60 )
{
struct V_22 * V_46 = F_30 ( V_60 ) ;
return ( V_46 && V_46 -> V_32 && strcmp ( V_46 -> V_32 , V_61 ) != 0 ) ;
}
int F_31 ( struct V_19 * V_60 , struct V_22 * V_62 )
{
struct V_22 * V_46 ;
F_32 ( V_60 == NULL ) ;
if ( V_60 -> V_24 == NULL ) {
V_46 = F_33 ( V_58 ,
V_63 | V_64 ) ;
if ( ! V_46 )
return - 1 ;
if ( F_34 ( & V_46 -> V_42 , & V_65 ,
& F_35 ( V_60 ) -> V_42 ,
L_11 , L_12 ) ) {
F_28 ( V_58 , V_46 ) ;
return - 1 ;
}
F_36 ( & V_46 -> V_42 , V_66 ) ;
V_46 -> V_55 |= V_56 | V_57 ;
V_46 -> V_26 = F_37 ( V_60 -> V_67 ) ;
V_60 -> V_24 = V_46 ;
} else
V_46 = V_60 -> V_24 ;
if ( V_62 != NULL ) {
V_46 -> V_32 = V_62 -> V_32 ;
V_46 -> V_68 = V_62 -> V_68 ;
V_46 -> V_69 = V_62 -> V_69 ;
V_46 -> V_30 = V_62 -> V_30 ;
V_46 -> V_70 = V_62 -> V_70 ;
V_46 -> V_71 = V_62 -> V_71 ;
V_46 -> V_31 = V_62 -> V_31 ;
} else
V_46 -> V_32 = V_61 ;
return 0 ;
}
void F_38 ( struct V_19 * V_60 )
{
struct V_22 * V_46 ;
if ( ! V_60 || ! V_60 -> V_24 )
return;
V_46 = V_60 -> V_24 ;
F_36 ( & V_46 -> V_42 , V_72 ) ;
F_39 ( & V_46 -> V_42 ) ;
F_40 ( & V_46 -> V_42 ) ;
V_60 -> V_24 = NULL ;
}
