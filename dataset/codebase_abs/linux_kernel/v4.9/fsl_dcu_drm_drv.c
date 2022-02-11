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
F_9 ( V_2 ) ;
return 0 ;
V_17:
F_10 ( V_2 ) ;
if ( V_8 -> V_19 )
F_11 ( V_8 -> V_19 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
V_2 -> V_9 = NULL ;
return V_10 ;
}
static int F_15 ( struct V_6 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_10 ( V_2 ) ;
if ( V_8 -> V_19 )
F_11 ( V_8 -> V_19 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
V_2 -> V_9 = NULL ;
return 0 ;
}
static T_1 F_16 ( int V_11 , void * V_20 )
{
struct V_6 * V_2 = V_20 ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_21 ;
int V_10 ;
V_10 = F_17 ( V_8 -> V_12 , V_4 , & V_21 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_2 , L_4 ) ;
return V_22 ;
}
if ( V_21 & V_23 )
F_18 ( V_2 , 0 ) ;
F_5 ( V_8 -> V_12 , V_4 , V_21 ) ;
return V_24 ;
}
static int F_19 ( struct V_6 * V_2 , unsigned int V_25 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_26 ;
F_17 ( V_8 -> V_12 , V_13 , & V_26 ) ;
V_26 &= ~ V_27 ;
F_5 ( V_8 -> V_12 , V_13 , V_26 ) ;
return 0 ;
}
static void F_20 ( struct V_6 * V_2 ,
unsigned int V_25 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_26 ;
F_17 ( V_8 -> V_12 , V_13 , & V_26 ) ;
V_26 |= V_27 ;
F_5 ( V_8 -> V_12 , V_13 , V_26 ) ;
}
static void F_21 ( struct V_6 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_22 ( V_8 -> V_19 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_24 ( V_2 ) ;
if ( ! V_8 )
return 0 ;
F_25 ( V_8 -> V_11 ) ;
F_26 ( V_8 -> V_28 ) ;
F_27 () ;
F_28 ( V_8 -> V_19 , 1 ) ;
F_29 () ;
V_8 -> V_29 = F_30 ( V_8 -> V_28 ) ;
if ( F_31 ( V_8 -> V_29 ) ) {
F_27 () ;
F_28 ( V_8 -> V_19 , 0 ) ;
F_29 () ;
F_32 ( V_8 -> V_28 ) ;
F_33 ( V_8 -> V_11 ) ;
return F_34 ( V_8 -> V_29 ) ;
}
F_35 ( V_8 -> V_30 ) ;
F_35 ( V_8 -> V_31 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_24 ( V_2 ) ;
int V_10 ;
if ( ! V_8 )
return 0 ;
V_10 = F_37 ( V_8 -> V_31 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_5 ) ;
return V_10 ;
}
if ( V_8 -> V_32 )
F_38 ( V_8 -> V_32 ) ;
F_39 ( V_8 -> V_28 ) ;
F_40 ( V_8 -> V_28 , V_8 -> V_29 ) ;
F_27 () ;
F_28 ( V_8 -> V_19 , 0 ) ;
F_29 () ;
F_32 ( V_8 -> V_28 ) ;
F_33 ( V_8 -> V_11 ) ;
return 0 ;
}
static int F_41 ( struct V_33 * V_34 )
{
struct V_7 * V_8 ;
struct V_6 * V_28 ;
struct V_1 * V_2 = & V_34 -> V_2 ;
struct V_35 * V_36 ;
void T_2 * V_37 ;
struct V_38 * V_39 = & V_40 ;
struct V_31 * V_41 ;
char V_42 [ 32 ] ;
const char * V_43 ;
const struct V_44 * V_45 ;
int V_10 ;
T_3 V_46 = 0 ;
V_8 = F_42 ( V_2 , sizeof( * V_8 ) , V_47 ) ;
if ( ! V_8 )
return - V_48 ;
V_45 = F_43 ( V_49 , V_34 -> V_2 . V_50 ) ;
if ( ! V_45 )
return - V_51 ;
V_8 -> V_52 = V_45 -> V_53 ;
V_36 = F_44 ( V_34 , V_54 , 0 ) ;
if ( ! V_36 ) {
F_4 ( V_2 , L_6 ) ;
return - V_51 ;
}
V_37 = F_45 ( V_2 , V_36 ) ;
if ( F_31 ( V_37 ) ) {
V_10 = F_34 ( V_37 ) ;
return V_10 ;
}
V_8 -> V_11 = F_46 ( V_34 , 0 ) ;
if ( V_8 -> V_11 < 0 ) {
F_4 ( V_2 , L_7 ) ;
return - V_55 ;
}
V_8 -> V_12 = F_47 ( V_2 , V_37 ,
& V_56 ) ;
if ( F_31 ( V_8 -> V_12 ) ) {
F_4 ( V_2 , L_8 ) ;
return F_34 ( V_8 -> V_12 ) ;
}
V_8 -> V_31 = F_48 ( V_2 , L_9 ) ;
if ( F_31 ( V_8 -> V_31 ) ) {
F_4 ( V_2 , L_10 ) ;
return F_34 ( V_8 -> V_31 ) ;
}
V_10 = F_37 ( V_8 -> V_31 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_5 ) ;
return V_10 ;
}
V_41 = F_48 ( V_2 , L_11 ) ;
if ( F_31 ( V_41 ) ) {
V_41 = V_8 -> V_31 ;
}
if ( F_49 ( V_2 -> V_50 , L_12 ) )
V_46 = 24 ;
V_43 = F_50 ( V_41 ) ;
snprintf ( V_42 , sizeof( V_42 ) , L_13 , V_43 ) ;
V_8 -> V_30 = F_51 ( V_2 , V_42 ,
V_43 , 0 , V_37 + V_57 ,
V_46 , 8 , V_58 , NULL ) ;
if ( F_31 ( V_8 -> V_30 ) ) {
F_4 ( V_2 , L_14 ) ;
V_10 = F_34 ( V_8 -> V_30 ) ;
goto V_59;
}
V_8 -> V_32 = F_52 ( V_2 ) ;
V_28 = F_53 ( V_39 , V_2 ) ;
if ( F_31 ( V_28 ) ) {
V_10 = F_34 ( V_28 ) ;
goto V_60;
}
V_8 -> V_2 = V_2 ;
V_8 -> V_28 = V_28 ;
V_8 -> V_61 = V_2 -> V_50 ;
V_28 -> V_9 = V_8 ;
F_54 ( V_2 , V_8 ) ;
V_10 = F_55 ( V_28 , 0 ) ;
if ( V_10 < 0 )
goto V_62;
F_56 ( L_15 , V_39 -> V_63 ,
V_39 -> V_64 , V_39 -> V_65 , V_39 -> V_66 ,
V_39 -> V_67 , V_28 -> V_68 -> V_69 ) ;
return 0 ;
V_62:
F_57 ( V_28 ) ;
V_60:
F_58 ( V_8 -> V_30 ) ;
V_59:
F_35 ( V_8 -> V_31 ) ;
return V_10 ;
}
static int F_59 ( struct V_33 * V_34 )
{
struct V_7 * V_8 = F_60 ( V_34 ) ;
F_35 ( V_8 -> V_31 ) ;
F_58 ( V_8 -> V_30 ) ;
F_61 ( V_8 -> V_28 ) ;
return 0 ;
}
