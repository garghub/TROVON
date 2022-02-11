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
F_12 ( L_1 ,
V_28 , V_21 -> V_29 , V_22 -> V_29 ,
V_24 -> V_27 , V_26 -> V_27 ) ;
return - 1 ;
}
if ( V_24 -> V_30 != V_26 -> V_30 ) {
F_13 ( V_31 L_2 , V_28 ,
V_21 -> V_29 , V_22 -> V_29 ,
V_24 -> V_30 , V_26 -> V_30 ) ;
return - 1 ;
}
if ( V_24 -> V_32 && V_26 -> V_32 && ( V_24 -> V_32 != V_26 -> V_32 ) ) {
F_13 ( V_31 L_3 , V_28 ,
V_21 -> V_29 , V_22 -> V_29 ,
V_24 -> V_32 , V_26 -> V_32 ) ;
return - 1 ;
}
if ( strcmp ( V_24 -> V_33 , V_26 -> V_33 ) ) {
F_13 ( V_31 L_4 , V_28 ,
V_21 -> V_29 , V_22 -> V_29 ,
V_24 -> V_33 , V_26 -> V_33 ) ;
return - 1 ;
}
return 0 ;
}
bool F_14 ( struct V_1 * V_2 , struct V_34 * V_35 ,
struct V_34 * V_36 )
{
if ( F_15 ( V_35 ) == 0 && F_15 ( V_36 ) == 0 )
return true ;
if ( F_15 ( V_35 ) == 0 || F_15 ( V_36 ) == 0 )
return false ;
if ( F_16 ( V_35 -> V_3 ) -> V_37 !=
F_16 ( V_36 -> V_3 ) -> V_37 )
return false ;
if ( V_35 -> V_38 + V_36 -> V_38 >
V_2 -> V_39 . V_40 )
return false ;
return true ;
}
bool F_17 ( struct V_1 * V_2 , struct V_34 * V_35 ,
struct V_3 * V_3 )
{
int V_41 ;
struct V_3 * V_36 = V_3 -> V_42 ;
if ( F_15 ( V_35 ) == 0 && F_16 ( V_3 ) == NULL )
return true ;
if ( F_15 ( V_35 ) == 0 || F_16 ( V_3 ) == NULL )
return false ;
if ( F_16 ( V_35 -> V_3 ) -> V_37 != F_16 ( V_3 ) -> V_37 )
return false ;
V_3 -> V_42 = NULL ;
V_41 = F_1 ( V_2 , V_3 ) ;
V_3 -> V_42 = V_36 ;
if ( V_35 -> V_38 + V_41 >
V_2 -> V_39 . V_40 )
return false ;
V_35 -> V_38 += V_41 ;
return true ;
}
static T_1 F_18 ( struct V_43 * V_44 , struct V_45 * V_46 ,
char * V_47 )
{
struct V_23 * V_48 =
F_19 ( V_44 , struct V_23 , V_44 ) ;
struct V_49 * V_50 =
F_19 ( V_46 , struct V_49 , V_46 ) ;
return V_50 -> V_51 ( V_48 , V_47 ) ;
}
static T_1 F_20 ( struct V_43 * V_44 ,
struct V_45 * V_46 , const char * V_47 ,
T_2 V_52 )
{
struct V_23 * V_48 =
F_19 ( V_44 , struct V_23 , V_44 ) ;
struct V_49 * V_50 =
F_19 ( V_46 , struct V_49 , V_46 ) ;
T_1 V_53 = 0 ;
if ( V_50 -> V_54 )
V_53 = V_50 -> V_54 ( V_48 , V_47 , V_52 ) ;
return V_53 ;
}
static T_1 F_21 ( struct V_23 * V_48 , char * V_47 )
{
if ( V_48 != NULL && V_48 -> V_33 != NULL )
return sprintf ( V_47 , L_5 , V_48 -> V_33 ) ;
else
return sprintf ( V_47 , L_6 ) ;
}
static T_1 F_22 ( struct V_23 * V_48 , char * V_47 )
{
if ( V_48 != NULL )
return sprintf ( V_47 , L_7 , V_48 -> V_32 ) ;
else
return sprintf ( V_47 , L_8 ) ;
}
static T_1 F_23 ( struct V_23 * V_48 ,
const char * V_47 , T_2 V_52 )
{
char * V_55 = ( char * ) V_47 ;
unsigned long V_56 = F_24 ( V_55 , & V_55 , 10 ) ;
if ( V_56 )
V_48 -> V_57 |= V_58 ;
else
V_48 -> V_57 &= ~ V_58 ;
return V_52 ;
}
static T_1 F_25 ( struct V_23 * V_48 , char * V_47 )
{
return sprintf ( V_47 , L_9 , ( V_48 -> V_57 & V_58 ) != 0 ) ;
}
static T_1 F_26 ( struct V_23 * V_48 ,
const char * V_47 , T_2 V_52 )
{
char * V_55 = ( char * ) V_47 ;
unsigned long V_56 = F_24 ( V_55 , & V_55 , 10 ) ;
if ( V_56 )
V_48 -> V_57 |= V_59 ;
else
V_48 -> V_57 &= ~ V_59 ;
return V_52 ;
}
static T_1 F_27 ( struct V_23 * V_48 , char * V_47 )
{
return sprintf ( V_47 , L_9 , ( V_48 -> V_57 & V_59 ) != 0 ) ;
}
static T_1 F_28 ( struct V_23 * V_48 , char * V_47 )
{
return sprintf ( V_47 , L_7 ,
( V_48 -> V_57 & V_60 ) != 0 ) ;
}
static int T_3 F_29 ( void )
{
V_61 = F_30 ( L_10 ,
sizeof( struct V_23 ) ,
0 , V_62 , NULL ) ;
return 0 ;
}
static void F_31 ( struct V_43 * V_44 )
{
struct V_23 * V_48 =
F_19 ( V_44 , struct V_23 , V_44 ) ;
F_32 ( V_61 , V_48 ) ;
}
bool F_33 ( struct V_20 * V_63 )
{
struct V_23 * V_48 = F_34 ( V_63 ) ;
return ( V_48 && V_48 -> V_33 && strcmp ( V_48 -> V_33 , V_64 ) != 0 ) ;
}
int F_35 ( struct V_20 * V_63 , struct V_23 * V_65 )
{
struct V_23 * V_48 ;
F_36 ( V_63 == NULL ) ;
if ( V_63 -> V_25 == NULL ) {
V_48 = F_37 ( V_61 ,
V_66 | V_67 ) ;
if ( ! V_48 )
return - 1 ;
if ( F_38 ( & V_48 -> V_44 , & V_68 ,
& F_39 ( V_63 ) -> V_44 ,
L_11 , L_12 ) ) {
F_32 ( V_61 , V_48 ) ;
return - 1 ;
}
F_40 ( & V_48 -> V_44 , V_69 ) ;
V_48 -> V_57 |= V_58 | V_59 ;
V_48 -> V_27 = F_41 ( V_63 -> V_70 ) ;
V_63 -> V_25 = V_48 ;
} else
V_48 = V_63 -> V_25 ;
if ( V_65 != NULL ) {
V_48 -> V_33 = V_65 -> V_33 ;
V_48 -> V_71 = V_65 -> V_71 ;
V_48 -> V_72 = V_65 -> V_72 ;
V_48 -> V_30 = V_65 -> V_30 ;
V_48 -> V_32 = V_65 -> V_32 ;
V_48 -> V_57 |= V_65 -> V_57 ;
} else
V_48 -> V_33 = V_64 ;
V_63 -> V_70 -> V_73 . V_74 |= V_75 ;
return 0 ;
}
void F_42 ( struct V_20 * V_63 )
{
struct V_23 * V_48 ;
if ( ! V_63 || ! V_63 -> V_25 )
return;
V_63 -> V_70 -> V_73 . V_74 &= ~ V_75 ;
V_48 = V_63 -> V_25 ;
F_40 ( & V_48 -> V_44 , V_76 ) ;
F_43 ( & V_48 -> V_44 ) ;
F_44 ( & V_48 -> V_44 ) ;
V_63 -> V_25 = NULL ;
}
