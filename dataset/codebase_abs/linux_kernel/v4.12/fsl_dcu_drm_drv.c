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
V_8 -> V_20 = F_10 ( V_2 , V_19 , 1 ) ;
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
static void F_18 ( struct V_6 * V_2 )
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
static void F_23 ( struct V_6 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_24 ( V_8 -> V_20 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_26 ( V_2 ) ;
if ( ! V_8 )
return 0 ;
F_27 ( V_8 -> V_11 ) ;
F_28 ( V_8 -> V_26 ) ;
F_29 () ;
F_30 ( V_8 -> V_20 , 1 ) ;
F_31 () ;
V_8 -> V_27 = F_32 ( V_8 -> V_26 ) ;
if ( F_11 ( V_8 -> V_27 ) ) {
F_29 () ;
F_30 ( V_8 -> V_20 , 0 ) ;
F_31 () ;
F_33 ( V_8 -> V_26 ) ;
F_34 ( V_8 -> V_11 ) ;
return F_12 ( V_8 -> V_27 ) ;
}
F_35 ( V_8 -> V_28 ) ;
F_35 ( V_8 -> V_29 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_26 ( V_2 ) ;
int V_10 ;
if ( ! V_8 )
return 0 ;
V_10 = F_37 ( V_8 -> V_29 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_6 ) ;
return V_10 ;
}
if ( V_8 -> V_30 )
F_38 ( V_8 -> V_30 ) ;
F_39 ( V_8 -> V_26 ) ;
F_40 ( V_8 -> V_26 , V_8 -> V_27 ) ;
F_29 () ;
F_30 ( V_8 -> V_20 , 0 ) ;
F_31 () ;
F_33 ( V_8 -> V_26 ) ;
F_34 ( V_8 -> V_11 ) ;
return 0 ;
}
static int F_41 ( struct V_31 * V_32 )
{
struct V_7 * V_8 ;
struct V_6 * V_26 ;
struct V_1 * V_2 = & V_32 -> V_2 ;
struct V_33 * V_34 ;
void T_2 * V_35 ;
struct V_36 * V_37 = & V_38 ;
struct V_29 * V_39 ;
char V_40 [ 32 ] ;
const char * V_41 ;
const struct V_42 * V_43 ;
int V_10 ;
T_3 V_44 = 0 ;
V_8 = F_42 ( V_2 , sizeof( * V_8 ) , V_45 ) ;
if ( ! V_8 )
return - V_46 ;
V_43 = F_43 ( V_47 , V_32 -> V_2 . V_48 ) ;
if ( ! V_43 )
return - V_49 ;
V_8 -> V_50 = V_43 -> V_51 ;
V_34 = F_44 ( V_32 , V_52 , 0 ) ;
V_35 = F_45 ( V_2 , V_34 ) ;
if ( F_11 ( V_35 ) ) {
V_10 = F_12 ( V_35 ) ;
return V_10 ;
}
V_8 -> V_11 = F_46 ( V_32 , 0 ) ;
if ( V_8 -> V_11 < 0 ) {
F_4 ( V_2 , L_7 ) ;
return V_8 -> V_11 ;
}
V_8 -> V_12 = F_47 ( V_2 , V_35 ,
& V_53 ) ;
if ( F_11 ( V_8 -> V_12 ) ) {
F_4 ( V_2 , L_8 ) ;
return F_12 ( V_8 -> V_12 ) ;
}
V_8 -> V_29 = F_48 ( V_2 , L_9 ) ;
if ( F_11 ( V_8 -> V_29 ) ) {
F_4 ( V_2 , L_10 ) ;
return F_12 ( V_8 -> V_29 ) ;
}
V_10 = F_37 ( V_8 -> V_29 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_6 ) ;
return V_10 ;
}
V_39 = F_48 ( V_2 , L_11 ) ;
if ( F_11 ( V_39 ) ) {
V_39 = V_8 -> V_29 ;
}
if ( F_49 ( V_2 -> V_48 , L_12 ) )
V_44 = 24 ;
V_41 = F_50 ( V_39 ) ;
snprintf ( V_40 , sizeof( V_40 ) , L_13 , V_41 ) ;
V_8 -> V_28 = F_51 ( V_2 , V_40 ,
V_41 , 0 , V_35 + V_54 ,
V_44 , 8 , V_55 , NULL ) ;
if ( F_11 ( V_8 -> V_28 ) ) {
F_4 ( V_2 , L_14 ) ;
V_10 = F_12 ( V_8 -> V_28 ) ;
goto V_56;
}
V_8 -> V_30 = F_52 ( V_2 ) ;
V_26 = F_53 ( V_37 , V_2 ) ;
if ( F_11 ( V_26 ) ) {
V_10 = F_12 ( V_26 ) ;
goto V_57;
}
V_8 -> V_2 = V_2 ;
V_8 -> V_26 = V_26 ;
V_8 -> V_58 = V_2 -> V_48 ;
V_26 -> V_9 = V_8 ;
F_54 ( V_2 , V_8 ) ;
V_10 = F_55 ( V_26 , 0 ) ;
if ( V_10 < 0 )
goto V_59;
return 0 ;
V_59:
F_56 ( V_26 ) ;
V_57:
F_57 ( V_8 -> V_28 ) ;
V_56:
F_35 ( V_8 -> V_29 ) ;
return V_10 ;
}
static int F_58 ( struct V_31 * V_32 )
{
struct V_7 * V_8 = F_59 ( V_32 ) ;
F_60 ( V_8 -> V_26 ) ;
F_56 ( V_8 -> V_26 ) ;
F_35 ( V_8 -> V_29 ) ;
F_57 ( V_8 -> V_28 ) ;
return 0 ;
}
