static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 == V_4 || V_3 == V_5 )
return true ;
return false ;
}
static int F_2 ( struct V_6 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 ;
V_10 = F_3 ( V_2 , V_8 -> V_11 ) ;
if ( V_10 < 0 )
F_4 ( V_2 -> V_2 , L_1 ) ;
F_5 ( V_8 -> V_12 , V_4 , 0 ) ;
F_5 ( V_8 -> V_12 , V_13 , ~ 0 ) ;
return V_10 ;
}
static int F_6 ( struct V_6 * V_2 , unsigned long V_14 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 ;
V_10 = F_7 ( V_8 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 -> V_2 , L_2 ) ;
return V_10 ;
}
V_10 = F_8 ( V_2 , V_2 -> V_15 . V_16 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 -> V_2 , L_3 ) ;
goto V_17;
}
V_10 = F_2 ( V_2 ) ;
if ( V_10 < 0 )
goto V_17;
V_2 -> V_18 = true ;
if ( V_19 != 16 && V_19 != 24 &&
V_19 != 32 ) {
F_9 ( V_2 -> V_2 ,
L_4 ) ;
V_19 = 24 ;
}
V_8 -> V_20 = F_10 ( V_2 , V_19 , 1 , 1 ) ;
if ( F_11 ( V_8 -> V_20 ) ) {
V_10 = F_12 ( V_8 -> V_20 ) ;
V_8 -> V_20 = NULL ;
goto V_17;
}
return 0 ;
V_17:
F_13 ( V_2 ) ;
if ( V_8 -> V_20 )
F_14 ( V_8 -> V_20 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
V_2 -> V_9 = NULL ;
return V_10 ;
}
static int F_18 ( struct V_6 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_19 ( V_2 ) ;
F_13 ( V_2 ) ;
if ( V_8 -> V_20 )
F_14 ( V_8 -> V_20 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
V_2 -> V_9 = NULL ;
return 0 ;
}
static T_1 F_20 ( int V_11 , void * V_21 )
{
struct V_6 * V_2 = V_21 ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_22 ;
int V_10 ;
V_10 = F_21 ( V_8 -> V_12 , V_4 , & V_22 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_2 , L_5 ) ;
return V_23 ;
}
if ( V_22 & V_24 )
F_22 ( V_2 , 0 ) ;
F_5 ( V_8 -> V_12 , V_4 , V_22 ) ;
return V_25 ;
}
static int F_23 ( struct V_6 * V_2 , unsigned int V_26 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_27 ;
F_21 ( V_8 -> V_12 , V_13 , & V_27 ) ;
V_27 &= ~ V_28 ;
F_5 ( V_8 -> V_12 , V_13 , V_27 ) ;
return 0 ;
}
static void F_24 ( struct V_6 * V_2 ,
unsigned int V_26 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_27 ;
F_21 ( V_8 -> V_12 , V_13 , & V_27 ) ;
V_27 |= V_28 ;
F_5 ( V_8 -> V_12 , V_13 , V_27 ) ;
}
static void F_25 ( struct V_6 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_26 ( V_8 -> V_20 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_28 ( V_2 ) ;
if ( ! V_8 )
return 0 ;
F_29 ( V_8 -> V_11 ) ;
F_30 ( V_8 -> V_29 ) ;
F_31 () ;
F_32 ( V_8 -> V_20 , 1 ) ;
F_33 () ;
V_8 -> V_30 = F_34 ( V_8 -> V_29 ) ;
if ( F_11 ( V_8 -> V_30 ) ) {
F_31 () ;
F_32 ( V_8 -> V_20 , 0 ) ;
F_33 () ;
F_35 ( V_8 -> V_29 ) ;
F_36 ( V_8 -> V_11 ) ;
return F_12 ( V_8 -> V_30 ) ;
}
F_37 ( V_8 -> V_31 ) ;
F_37 ( V_8 -> V_32 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_28 ( V_2 ) ;
int V_10 ;
if ( ! V_8 )
return 0 ;
V_10 = F_39 ( V_8 -> V_32 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_6 ) ;
return V_10 ;
}
if ( V_8 -> V_33 )
F_40 ( V_8 -> V_33 ) ;
F_41 ( V_8 -> V_29 ) ;
F_42 ( V_8 -> V_29 , V_8 -> V_30 ) ;
F_31 () ;
F_32 ( V_8 -> V_20 , 0 ) ;
F_33 () ;
F_35 ( V_8 -> V_29 ) ;
F_36 ( V_8 -> V_11 ) ;
return 0 ;
}
static int F_43 ( struct V_34 * V_35 )
{
struct V_7 * V_8 ;
struct V_6 * V_29 ;
struct V_1 * V_2 = & V_35 -> V_2 ;
struct V_36 * V_37 ;
void T_2 * V_38 ;
struct V_39 * V_40 = & V_41 ;
struct V_32 * V_42 ;
char V_43 [ 32 ] ;
const char * V_44 ;
const struct V_45 * V_46 ;
int V_10 ;
T_3 V_47 = 0 ;
V_8 = F_44 ( V_2 , sizeof( * V_8 ) , V_48 ) ;
if ( ! V_8 )
return - V_49 ;
V_46 = F_45 ( V_50 , V_35 -> V_2 . V_51 ) ;
if ( ! V_46 )
return - V_52 ;
V_8 -> V_53 = V_46 -> V_54 ;
V_37 = F_46 ( V_35 , V_55 , 0 ) ;
V_38 = F_47 ( V_2 , V_37 ) ;
if ( F_11 ( V_38 ) ) {
V_10 = F_12 ( V_38 ) ;
return V_10 ;
}
V_8 -> V_11 = F_48 ( V_35 , 0 ) ;
if ( V_8 -> V_11 < 0 ) {
F_4 ( V_2 , L_7 ) ;
return V_8 -> V_11 ;
}
V_8 -> V_12 = F_49 ( V_2 , V_38 ,
& V_56 ) ;
if ( F_11 ( V_8 -> V_12 ) ) {
F_4 ( V_2 , L_8 ) ;
return F_12 ( V_8 -> V_12 ) ;
}
V_8 -> V_32 = F_50 ( V_2 , L_9 ) ;
if ( F_11 ( V_8 -> V_32 ) ) {
F_4 ( V_2 , L_10 ) ;
return F_12 ( V_8 -> V_32 ) ;
}
V_10 = F_39 ( V_8 -> V_32 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_6 ) ;
return V_10 ;
}
V_42 = F_50 ( V_2 , L_11 ) ;
if ( F_11 ( V_42 ) ) {
V_42 = V_8 -> V_32 ;
}
if ( F_51 ( V_2 -> V_51 , L_12 ) )
V_47 = 24 ;
V_44 = F_52 ( V_42 ) ;
snprintf ( V_43 , sizeof( V_43 ) , L_13 , V_44 ) ;
V_8 -> V_31 = F_53 ( V_2 , V_43 ,
V_44 , 0 , V_38 + V_57 ,
V_47 , 8 , V_58 , NULL ) ;
if ( F_11 ( V_8 -> V_31 ) ) {
F_4 ( V_2 , L_14 ) ;
V_10 = F_12 ( V_8 -> V_31 ) ;
goto V_59;
}
V_8 -> V_33 = F_54 ( V_2 ) ;
V_29 = F_55 ( V_40 , V_2 ) ;
if ( F_11 ( V_29 ) ) {
V_10 = F_12 ( V_29 ) ;
goto V_60;
}
V_8 -> V_2 = V_2 ;
V_8 -> V_29 = V_29 ;
V_8 -> V_61 = V_2 -> V_51 ;
V_29 -> V_9 = V_8 ;
F_56 ( V_2 , V_8 ) ;
V_10 = F_57 ( V_29 , 0 ) ;
if ( V_10 < 0 )
goto V_62;
F_58 ( L_15 , V_40 -> V_63 ,
V_40 -> V_64 , V_40 -> V_65 , V_40 -> V_66 ,
V_40 -> V_67 , V_29 -> V_68 -> V_69 ) ;
return 0 ;
V_62:
F_59 ( V_29 ) ;
V_60:
F_60 ( V_8 -> V_31 ) ;
V_59:
F_37 ( V_8 -> V_32 ) ;
return V_10 ;
}
static int F_61 ( struct V_34 * V_35 )
{
struct V_7 * V_8 = F_62 ( V_35 ) ;
F_63 ( V_8 -> V_29 ) ;
F_37 ( V_8 -> V_32 ) ;
F_60 ( V_8 -> V_31 ) ;
return 0 ;
}
