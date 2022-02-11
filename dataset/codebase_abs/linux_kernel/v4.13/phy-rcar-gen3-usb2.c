static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_2 ) ;
if ( V_4 -> V_5 ) {
F_3 ( V_4 -> V_6 , V_7 , true ) ;
F_3 ( V_4 -> V_6 , V_8 , false ) ;
} else {
F_3 ( V_4 -> V_6 , V_7 , false ) ;
F_3 ( V_4 -> V_6 , V_8 , true ) ;
}
}
static void F_4 ( struct V_3 * V_4 , int V_9 )
{
void T_1 * V_10 = V_4 -> V_11 ;
T_2 V_12 = F_5 ( V_10 + V_13 ) ;
F_6 ( & V_4 -> V_14 -> V_15 , L_1 , V_16 , V_12 , V_9 ) ;
if ( V_9 )
V_12 &= ~ V_17 ;
else
V_12 |= V_17 ;
F_7 ( V_12 , V_10 + V_13 ) ;
}
static void F_8 ( struct V_3 * V_4 , int V_18 , int V_19 )
{
void T_1 * V_10 = V_4 -> V_11 ;
T_2 V_12 = F_5 ( V_10 + V_20 ) ;
F_6 ( & V_4 -> V_14 -> V_15 , L_2 , V_16 , V_12 , V_18 , V_19 ) ;
V_12 &= ~ ( V_21 | V_22 ) ;
if ( V_18 )
V_12 |= V_21 ;
if ( V_19 )
V_12 |= V_22 ;
F_7 ( V_12 , V_10 + V_20 ) ;
}
static void F_9 ( struct V_3 * V_4 , int V_23 )
{
void T_1 * V_10 = V_4 -> V_11 ;
T_2 V_12 = F_5 ( V_10 + V_24 ) ;
F_6 ( & V_4 -> V_14 -> V_15 , L_1 , V_16 , V_12 , V_23 ) ;
if ( V_23 )
V_12 |= V_25 ;
else
V_12 &= ~ V_25 ;
F_7 ( V_12 , V_10 + V_24 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
F_8 ( V_4 , 1 , 1 ) ;
F_4 ( V_4 , 1 ) ;
F_9 ( V_4 , 1 ) ;
V_4 -> V_5 = true ;
F_11 ( & V_4 -> V_2 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
F_8 ( V_4 , 0 , 1 ) ;
F_4 ( V_4 , 0 ) ;
F_9 ( V_4 , 0 ) ;
V_4 -> V_5 = false ;
F_11 ( & V_4 -> V_2 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
void T_1 * V_10 = V_4 -> V_11 ;
T_2 V_12 ;
V_12 = F_5 ( V_10 + V_20 ) ;
F_7 ( V_12 | V_26 , V_10 + V_20 ) ;
F_8 ( V_4 , 1 , 1 ) ;
F_4 ( V_4 , 1 ) ;
F_9 ( V_4 , 0 ) ;
V_12 = F_5 ( V_10 + V_20 ) ;
F_7 ( V_12 & ~ V_26 , V_10 + V_20 ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
F_8 ( V_4 , 0 , 1 ) ;
F_4 ( V_4 , 0 ) ;
F_9 ( V_4 , 1 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
void T_1 * V_10 = V_4 -> V_11 ;
T_2 V_12 ;
V_12 = F_5 ( V_10 + V_27 ) ;
F_7 ( V_12 & ~ V_28 , V_10 + V_27 ) ;
F_9 ( V_4 , 0 ) ;
F_10 ( V_4 ) ;
F_7 ( V_12 | V_28 , V_10 + V_27 ) ;
}
static bool F_16 ( struct V_3 * V_4 )
{
return ! ! ( F_5 ( V_4 -> V_11 + V_24 ) & V_29 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
if ( ! F_16 ( V_4 ) )
F_10 ( V_4 ) ;
else
F_12 ( V_4 ) ;
}
static bool F_18 ( struct V_3 * V_4 )
{
return ! ( F_5 ( V_4 -> V_11 + V_13 ) & V_17 ) ;
}
static T_3 F_19 ( struct V_30 * V_15 , struct V_31 * V_32 ,
const char * V_33 , T_4 V_34 )
{
struct V_3 * V_4 = F_20 ( V_15 ) ;
bool V_35 , V_36 , V_37 ;
if ( ! V_4 -> V_38 || ! V_4 -> V_14 -> V_39 )
return - V_40 ;
V_35 = F_16 ( V_4 ) ;
V_36 = F_18 ( V_4 ) ;
if ( ! strncmp ( V_33 , L_3 , strlen ( L_3 ) ) )
V_37 = true ;
else if ( ! strncmp ( V_33 , L_4 , strlen ( L_4 ) ) )
V_37 = false ;
else
return - V_41 ;
if ( V_36 == V_37 )
return - V_41 ;
if ( V_37 ) {
if ( ! V_35 )
F_15 ( V_4 ) ;
else
F_13 ( V_4 ) ;
} else {
if ( ! V_35 )
F_14 ( V_4 ) ;
else
F_12 ( V_4 ) ;
}
return V_34 ;
}
static T_3 F_21 ( struct V_30 * V_15 , struct V_31 * V_32 ,
char * V_33 )
{
struct V_3 * V_4 = F_20 ( V_15 ) ;
if ( ! V_4 -> V_38 || ! V_4 -> V_14 -> V_39 )
return - V_40 ;
return sprintf ( V_33 , L_5 , F_18 ( V_4 ) ? L_3 :
L_4 ) ;
}
static void F_22 ( struct V_3 * V_4 )
{
void T_1 * V_10 = V_4 -> V_11 ;
T_2 V_12 ;
V_12 = F_5 ( V_10 + V_42 ) ;
F_7 ( V_12 | V_43 , V_10 + V_42 ) ;
F_7 ( V_28 , V_10 + V_44 ) ;
V_12 = F_5 ( V_10 + V_27 ) ;
F_7 ( V_12 | V_28 , V_10 + V_27 ) ;
V_12 = F_5 ( V_10 + V_24 ) ;
F_7 ( V_12 | V_45 , V_10 + V_24 ) ;
V_12 = F_5 ( V_10 + V_20 ) ;
F_8 ( V_4 , 0 , 0 ) ;
F_7 ( V_12 | V_46 | V_47 ,
V_10 + V_20 ) ;
F_17 ( V_4 ) ;
}
static int F_23 ( struct V_14 * V_48 )
{
struct V_3 * V_49 = F_24 ( V_48 ) ;
void T_1 * V_10 = V_49 -> V_11 ;
F_7 ( V_50 , V_10 + V_51 ) ;
F_7 ( V_52 , V_10 + V_53 ) ;
F_7 ( V_54 , V_10 + V_55 ) ;
if ( V_49 -> V_38 )
F_22 ( V_49 ) ;
return 0 ;
}
static int F_25 ( struct V_14 * V_48 )
{
struct V_3 * V_49 = F_24 ( V_48 ) ;
F_7 ( 0 , V_49 -> V_11 + V_51 ) ;
return 0 ;
}
static int F_26 ( struct V_14 * V_48 )
{
struct V_3 * V_49 = F_24 ( V_48 ) ;
void T_1 * V_10 = V_49 -> V_11 ;
T_2 V_12 ;
int V_56 ;
if ( V_49 -> V_23 ) {
V_56 = F_27 ( V_49 -> V_23 ) ;
if ( V_56 )
return V_56 ;
}
V_12 = F_5 ( V_10 + V_57 ) ;
V_12 |= V_58 ;
F_7 ( V_12 , V_10 + V_57 ) ;
V_12 &= ~ V_58 ;
F_7 ( V_12 , V_10 + V_57 ) ;
return 0 ;
}
static int F_28 ( struct V_14 * V_48 )
{
struct V_3 * V_49 = F_24 ( V_48 ) ;
int V_56 = 0 ;
if ( V_49 -> V_23 )
V_56 = F_29 ( V_49 -> V_23 ) ;
return V_56 ;
}
static T_5 F_30 ( int V_59 , void * V_60 )
{
struct V_3 * V_4 = V_60 ;
void T_1 * V_10 = V_4 -> V_11 ;
T_2 V_61 = F_5 ( V_10 + V_44 ) ;
T_5 V_56 = V_62 ;
if ( V_61 & V_28 ) {
F_6 ( & V_4 -> V_14 -> V_15 , L_6 , V_16 , V_61 ) ;
F_7 ( V_28 , V_10 + V_44 ) ;
F_17 ( V_4 ) ;
V_56 = V_63 ;
}
return V_56 ;
}
static int F_31 ( struct V_64 * V_65 )
{
struct V_30 * V_15 = & V_65 -> V_15 ;
struct V_3 * V_49 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
int V_59 , V_56 = 0 ;
if ( ! V_15 -> V_70 ) {
F_32 ( V_15 , L_7 ) ;
return - V_41 ;
}
V_49 = F_33 ( V_15 , sizeof( * V_49 ) , V_71 ) ;
if ( ! V_49 )
return - V_72 ;
V_69 = F_34 ( V_65 , V_73 , 0 ) ;
V_49 -> V_11 = F_35 ( V_15 , V_69 ) ;
if ( F_36 ( V_49 -> V_11 ) )
return F_37 ( V_49 -> V_11 ) ;
V_59 = F_38 ( V_65 , 0 ) ;
if ( V_59 >= 0 ) {
int V_56 ;
F_39 ( & V_49 -> V_2 , F_1 ) ;
V_59 = F_40 ( V_15 , V_59 , F_30 ,
V_74 , F_41 ( V_15 ) , V_49 ) ;
if ( V_59 < 0 )
F_32 ( V_15 , L_8 , V_59 ) ;
V_49 -> V_38 = true ;
V_49 -> V_6 = F_42 ( V_15 ,
V_75 ) ;
if ( F_36 ( V_49 -> V_6 ) )
return F_37 ( V_49 -> V_6 ) ;
V_56 = F_43 ( V_15 , V_49 -> V_6 ) ;
if ( V_56 < 0 ) {
F_32 ( V_15 , L_9 ) ;
return V_56 ;
}
}
F_44 ( V_15 ) ;
V_49 -> V_14 = F_45 ( V_15 , NULL , & V_76 ) ;
if ( F_36 ( V_49 -> V_14 ) ) {
F_32 ( V_15 , L_10 ) ;
V_56 = F_37 ( V_49 -> V_14 ) ;
goto error;
}
V_49 -> V_23 = F_46 ( V_15 , L_11 ) ;
if ( F_36 ( V_49 -> V_23 ) ) {
if ( F_37 ( V_49 -> V_23 ) == - V_77 ) {
V_56 = F_37 ( V_49 -> V_23 ) ;
goto error;
}
V_49 -> V_23 = NULL ;
}
F_47 ( V_65 , V_49 ) ;
F_48 ( V_49 -> V_14 , V_49 ) ;
V_67 = F_49 ( V_15 , V_78 ) ;
if ( F_36 ( V_67 ) ) {
F_32 ( V_15 , L_12 ) ;
V_56 = F_37 ( V_67 ) ;
goto error;
} else if ( V_49 -> V_38 ) {
int V_56 ;
V_56 = F_50 ( V_15 , & V_79 ) ;
if ( V_56 < 0 )
goto error;
}
return 0 ;
error:
F_51 ( V_15 ) ;
return V_56 ;
}
static int F_52 ( struct V_64 * V_65 )
{
struct V_3 * V_49 = F_53 ( V_65 ) ;
if ( V_49 -> V_38 )
F_54 ( & V_65 -> V_15 , & V_79 ) ;
F_51 ( & V_65 -> V_15 ) ;
return 0 ;
}
