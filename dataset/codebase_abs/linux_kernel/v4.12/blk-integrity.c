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
struct V_23 * V_24 = & V_21 -> V_25 -> V_26 ;
struct V_23 * V_27 = & V_22 -> V_25 -> V_26 ;
if ( ! V_24 -> V_28 && ! V_27 -> V_28 )
return 0 ;
if ( ! V_24 -> V_28 || ! V_27 -> V_28 )
return - 1 ;
if ( V_24 -> V_29 != V_27 -> V_29 ) {
F_12 ( L_1 ,
V_30 , V_21 -> V_31 , V_22 -> V_31 ,
1 << V_24 -> V_29 , 1 << V_27 -> V_29 ) ;
return - 1 ;
}
if ( V_24 -> V_32 != V_27 -> V_32 ) {
F_12 ( L_2 , V_30 ,
V_21 -> V_31 , V_22 -> V_31 ,
V_24 -> V_32 , V_27 -> V_32 ) ;
return - 1 ;
}
if ( V_24 -> V_33 && V_27 -> V_33 && ( V_24 -> V_33 != V_27 -> V_33 ) ) {
F_12 ( L_3 , V_30 ,
V_21 -> V_31 , V_22 -> V_31 ,
V_24 -> V_33 , V_27 -> V_33 ) ;
return - 1 ;
}
if ( V_24 -> V_28 != V_27 -> V_28 ) {
F_12 ( L_4 , V_30 ,
V_21 -> V_31 , V_22 -> V_31 ,
V_24 -> V_28 -> V_34 , V_27 -> V_28 -> V_34 ) ;
return - 1 ;
}
return 0 ;
}
bool F_13 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_35 * V_37 )
{
if ( F_14 ( V_36 ) == 0 && F_14 ( V_37 ) == 0 )
return true ;
if ( F_14 ( V_36 ) == 0 || F_14 ( V_37 ) == 0 )
return false ;
if ( F_15 ( V_36 -> V_3 ) -> V_38 !=
F_15 ( V_37 -> V_3 ) -> V_38 )
return false ;
if ( V_36 -> V_39 + V_37 -> V_39 >
V_2 -> V_40 . V_41 )
return false ;
if ( F_16 ( V_36 , V_37 -> V_3 ) )
return false ;
return true ;
}
bool F_17 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_3 * V_3 )
{
int V_42 ;
struct V_3 * V_37 = V_3 -> V_43 ;
if ( F_14 ( V_36 ) == 0 && F_15 ( V_3 ) == NULL )
return true ;
if ( F_14 ( V_36 ) == 0 || F_15 ( V_3 ) == NULL )
return false ;
if ( F_15 ( V_36 -> V_3 ) -> V_38 != F_15 ( V_3 ) -> V_38 )
return false ;
V_3 -> V_43 = NULL ;
V_42 = F_1 ( V_2 , V_3 ) ;
V_3 -> V_43 = V_37 ;
if ( V_36 -> V_39 + V_42 >
V_2 -> V_40 . V_41 )
return false ;
V_36 -> V_39 += V_42 ;
return true ;
}
static T_1 F_18 ( struct V_44 * V_45 , struct V_46 * V_47 ,
char * V_48 )
{
struct V_20 * V_49 = F_19 ( V_45 , struct V_20 , V_50 ) ;
struct V_23 * V_51 = & V_49 -> V_25 -> V_26 ;
struct V_52 * V_53 =
F_19 ( V_47 , struct V_52 , V_47 ) ;
return V_53 -> V_54 ( V_51 , V_48 ) ;
}
static T_1 F_20 ( struct V_44 * V_45 ,
struct V_46 * V_47 , const char * V_48 ,
T_2 V_55 )
{
struct V_20 * V_49 = F_19 ( V_45 , struct V_20 , V_50 ) ;
struct V_23 * V_51 = & V_49 -> V_25 -> V_26 ;
struct V_52 * V_53 =
F_19 ( V_47 , struct V_52 , V_47 ) ;
T_1 V_56 = 0 ;
if ( V_53 -> V_57 )
V_56 = V_53 -> V_57 ( V_51 , V_48 , V_55 ) ;
return V_56 ;
}
static T_1 F_21 ( struct V_23 * V_51 , char * V_48 )
{
if ( V_51 -> V_28 && V_51 -> V_28 -> V_34 )
return sprintf ( V_48 , L_5 , V_51 -> V_28 -> V_34 ) ;
else
return sprintf ( V_48 , L_6 ) ;
}
static T_1 F_22 ( struct V_23 * V_51 , char * V_48 )
{
return sprintf ( V_48 , L_7 , V_51 -> V_33 ) ;
}
static T_1 F_23 ( struct V_23 * V_51 , char * V_48 )
{
return sprintf ( V_48 , L_7 ,
V_51 -> V_29 ? 1 << V_51 -> V_29 : 0 ) ;
}
static T_1 F_24 ( struct V_23 * V_51 ,
const char * V_48 , T_2 V_55 )
{
char * V_58 = ( char * ) V_48 ;
unsigned long V_59 = F_25 ( V_58 , & V_58 , 10 ) ;
if ( V_59 )
V_51 -> V_60 |= V_61 ;
else
V_51 -> V_60 &= ~ V_61 ;
return V_55 ;
}
static T_1 F_26 ( struct V_23 * V_51 , char * V_48 )
{
return sprintf ( V_48 , L_8 , ( V_51 -> V_60 & V_61 ) != 0 ) ;
}
static T_1 F_27 ( struct V_23 * V_51 ,
const char * V_48 , T_2 V_55 )
{
char * V_58 = ( char * ) V_48 ;
unsigned long V_59 = F_25 ( V_58 , & V_58 , 10 ) ;
if ( V_59 )
V_51 -> V_60 |= V_62 ;
else
V_51 -> V_60 &= ~ V_62 ;
return V_55 ;
}
static T_1 F_28 ( struct V_23 * V_51 , char * V_48 )
{
return sprintf ( V_48 , L_8 , ( V_51 -> V_60 & V_62 ) != 0 ) ;
}
static T_1 F_29 ( struct V_23 * V_51 , char * V_48 )
{
return sprintf ( V_48 , L_7 ,
( V_51 -> V_60 & V_63 ) != 0 ) ;
}
static int F_30 ( struct V_64 * V_10 )
{
return 0 ;
}
void F_31 ( struct V_20 * V_49 , struct V_23 * V_65 )
{
struct V_23 * V_51 = & V_49 -> V_25 -> V_26 ;
V_51 -> V_60 = V_61 | V_62 |
V_65 -> V_60 ;
V_51 -> V_29 = V_65 -> V_29 ? :
F_32 ( F_33 ( V_49 -> V_25 ) ) ;
V_51 -> V_28 = V_65 -> V_28 ? V_65 -> V_28 : & V_66 ;
V_51 -> V_32 = V_65 -> V_32 ;
V_51 -> V_33 = V_65 -> V_33 ;
V_49 -> V_25 -> V_67 -> V_68 |= V_69 ;
}
void F_34 ( struct V_20 * V_49 )
{
V_49 -> V_25 -> V_67 -> V_68 &= ~ V_69 ;
memset ( & V_49 -> V_25 -> V_26 , 0 , sizeof( struct V_23 ) ) ;
}
void F_35 ( struct V_20 * V_49 )
{
if ( F_36 ( & V_49 -> V_50 , & V_70 ,
& F_37 ( V_49 ) -> V_45 , L_9 , L_10 ) )
return;
F_38 ( & V_49 -> V_50 , V_71 ) ;
}
void F_39 ( struct V_20 * V_49 )
{
F_38 ( & V_49 -> V_50 , V_72 ) ;
F_40 ( & V_49 -> V_50 ) ;
F_41 ( & V_49 -> V_50 ) ;
}
