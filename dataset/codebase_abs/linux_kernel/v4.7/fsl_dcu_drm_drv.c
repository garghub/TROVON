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
F_5 ( V_8 -> V_12 , V_5 ,
V_14 ) ;
return V_10 ;
}
static int F_6 ( struct V_6 * V_2 , unsigned long V_15 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 ;
V_10 = F_7 ( V_8 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 -> V_2 , L_2 ) ;
return V_10 ;
}
V_10 = F_8 ( V_2 , V_2 -> V_16 . V_17 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 -> V_2 , L_3 ) ;
goto V_18;
}
V_10 = F_2 ( V_2 ) ;
if ( V_10 < 0 )
goto V_18;
V_2 -> V_19 = true ;
F_9 ( V_2 ) ;
return 0 ;
V_18:
F_10 ( V_2 ) ;
if ( V_8 -> V_20 )
F_11 ( V_8 -> V_20 ) ;
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
if ( V_8 -> V_20 )
F_11 ( V_8 -> V_20 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
V_2 -> V_9 = NULL ;
return 0 ;
}
static T_1 F_16 ( int V_11 , void * V_21 )
{
struct V_6 * V_2 = V_21 ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_22 ;
int V_10 ;
V_10 = F_17 ( V_8 -> V_12 , V_4 , & V_22 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_2 , L_4 ) ;
return V_23 ;
}
if ( V_22 & V_24 )
F_18 ( V_2 , 0 ) ;
F_5 ( V_8 -> V_12 , V_4 , V_22 ) ;
F_5 ( V_8 -> V_12 , V_5 ,
V_14 ) ;
return V_25 ;
}
static int F_19 ( struct V_6 * V_2 , unsigned int V_26 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_27 ;
F_17 ( V_8 -> V_12 , V_13 , & V_27 ) ;
V_27 &= ~ V_28 ;
F_5 ( V_8 -> V_12 , V_13 , V_27 ) ;
return 0 ;
}
static void F_20 ( struct V_6 * V_2 ,
unsigned int V_26 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_27 ;
F_17 ( V_8 -> V_12 , V_13 , & V_27 ) ;
V_27 |= V_28 ;
F_5 ( V_8 -> V_12 , V_13 , V_27 ) ;
}
static void F_21 ( struct V_6 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_22 ( V_8 -> V_20 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_24 ( V_2 ) ;
if ( ! V_8 )
return 0 ;
F_25 ( V_8 -> V_29 ) ;
F_26 ( V_8 -> V_12 , true ) ;
F_27 ( V_8 -> V_12 ) ;
F_28 ( V_8 -> V_30 ) ;
F_29 ( V_8 -> V_30 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_24 ( V_2 ) ;
int V_10 ;
if ( ! V_8 )
return 0 ;
V_10 = F_31 ( V_8 -> V_30 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_5 ) ;
F_29 ( V_8 -> V_30 ) ;
return V_10 ;
}
V_10 = F_32 ( V_8 -> V_30 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_6 ) ;
return V_10 ;
}
F_33 ( V_8 -> V_29 ) ;
F_26 ( V_8 -> V_12 , false ) ;
F_34 ( V_8 -> V_12 ) ;
return 0 ;
}
static int F_35 ( struct V_31 * V_32 )
{
struct V_7 * V_8 ;
struct V_6 * V_29 ;
struct V_1 * V_2 = & V_32 -> V_2 ;
struct V_33 * V_34 ;
void T_2 * V_35 ;
struct V_36 * V_37 = & V_38 ;
struct V_30 * V_39 ;
char V_40 [ 32 ] ;
const char * V_41 ;
const struct V_42 * V_43 ;
int V_10 ;
V_8 = F_36 ( V_2 , sizeof( * V_8 ) , V_44 ) ;
if ( ! V_8 )
return - V_45 ;
V_43 = F_37 ( V_46 , V_32 -> V_2 . V_47 ) ;
if ( ! V_43 )
return - V_48 ;
V_8 -> V_49 = V_43 -> V_50 ;
V_34 = F_38 ( V_32 , V_51 , 0 ) ;
if ( ! V_34 ) {
F_4 ( V_2 , L_7 ) ;
return - V_48 ;
}
V_35 = F_39 ( V_2 , V_34 ) ;
if ( F_40 ( V_35 ) ) {
V_10 = F_41 ( V_35 ) ;
return V_10 ;
}
V_8 -> V_11 = F_42 ( V_32 , 0 ) ;
if ( V_8 -> V_11 < 0 ) {
F_4 ( V_2 , L_8 ) ;
return - V_52 ;
}
V_8 -> V_12 = F_43 ( V_2 , V_35 ,
& V_53 ) ;
if ( F_40 ( V_8 -> V_12 ) ) {
F_4 ( V_2 , L_9 ) ;
return F_41 ( V_8 -> V_12 ) ;
}
V_8 -> V_30 = F_44 ( V_2 , L_10 ) ;
if ( F_40 ( V_8 -> V_30 ) ) {
F_4 ( V_2 , L_11 ) ;
return F_41 ( V_8 -> V_30 ) ;
}
V_10 = F_45 ( V_8 -> V_30 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_5 ) ;
return V_10 ;
}
V_39 = F_44 ( V_2 , L_12 ) ;
if ( F_40 ( V_39 ) ) {
V_39 = V_8 -> V_30 ;
}
V_41 = F_46 ( V_39 ) ;
snprintf ( V_40 , sizeof( V_40 ) , L_13 , V_41 ) ;
V_8 -> V_54 = F_47 ( V_2 , V_40 ,
V_41 , 0 , V_35 + V_55 ,
0 , 8 , V_56 , NULL ) ;
if ( F_40 ( V_8 -> V_54 ) ) {
F_4 ( V_2 , L_14 ) ;
V_10 = F_41 ( V_8 -> V_54 ) ;
goto V_57;
}
V_10 = F_45 ( V_8 -> V_54 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_15 ) ;
goto V_58;
}
V_8 -> V_59 = F_48 ( V_2 ) ;
V_29 = F_49 ( V_37 , V_2 ) ;
if ( ! V_29 ) {
V_10 = - V_45 ;
goto V_60;
}
V_8 -> V_2 = V_2 ;
V_8 -> V_29 = V_29 ;
V_8 -> V_61 = V_2 -> V_47 ;
V_29 -> V_9 = V_8 ;
F_50 ( V_2 , V_8 ) ;
V_10 = F_51 ( V_29 , 0 ) ;
if ( V_10 < 0 )
goto V_62;
F_52 ( L_16 , V_37 -> V_63 ,
V_37 -> V_64 , V_37 -> V_65 , V_37 -> V_66 ,
V_37 -> V_67 , V_29 -> V_68 -> V_69 ) ;
return 0 ;
V_62:
F_53 ( V_29 ) ;
V_60:
F_54 ( V_8 -> V_54 ) ;
V_58:
F_55 ( V_8 -> V_54 ) ;
V_57:
F_54 ( V_8 -> V_30 ) ;
return V_10 ;
}
static int F_56 ( struct V_31 * V_32 )
{
struct V_7 * V_8 = F_57 ( V_32 ) ;
F_54 ( V_8 -> V_30 ) ;
F_54 ( V_8 -> V_54 ) ;
F_55 ( V_8 -> V_54 ) ;
F_58 ( V_8 -> V_29 ) ;
return 0 ;
}
