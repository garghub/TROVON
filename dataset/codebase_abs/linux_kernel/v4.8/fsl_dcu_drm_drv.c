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
F_25 ( V_8 -> V_11 ) ;
F_26 ( V_8 -> V_29 ) ;
F_27 () ;
F_28 ( V_8 -> V_20 , 1 ) ;
F_29 () ;
V_8 -> V_30 = F_30 ( V_8 -> V_29 ) ;
if ( F_31 ( V_8 -> V_30 ) ) {
F_27 () ;
F_28 ( V_8 -> V_20 , 0 ) ;
F_29 () ;
F_32 ( V_8 -> V_29 ) ;
F_33 ( V_8 -> V_11 ) ;
return F_34 ( V_8 -> V_30 ) ;
}
F_35 ( V_8 -> V_31 ) ;
F_35 ( V_8 -> V_32 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_24 ( V_2 ) ;
int V_10 ;
if ( ! V_8 )
return 0 ;
V_10 = F_37 ( V_8 -> V_32 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_5 ) ;
return V_10 ;
}
V_10 = F_37 ( V_8 -> V_31 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_6 ) ;
return V_10 ;
}
F_38 ( V_8 -> V_29 ) ;
F_39 ( V_8 -> V_29 , V_8 -> V_30 ) ;
F_27 () ;
F_28 ( V_8 -> V_20 , 0 ) ;
F_29 () ;
F_32 ( V_8 -> V_29 ) ;
F_33 ( V_8 -> V_11 ) ;
return 0 ;
}
static int F_40 ( struct V_33 * V_34 )
{
struct V_7 * V_8 ;
struct V_6 * V_29 ;
struct V_1 * V_2 = & V_34 -> V_2 ;
struct V_35 * V_36 ;
void T_2 * V_37 ;
struct V_38 * V_39 = & V_40 ;
struct V_32 * V_41 ;
char V_42 [ 32 ] ;
const char * V_43 ;
const struct V_44 * V_45 ;
int V_10 ;
V_8 = F_41 ( V_2 , sizeof( * V_8 ) , V_46 ) ;
if ( ! V_8 )
return - V_47 ;
V_45 = F_42 ( V_48 , V_34 -> V_2 . V_49 ) ;
if ( ! V_45 )
return - V_50 ;
V_8 -> V_51 = V_45 -> V_52 ;
V_36 = F_43 ( V_34 , V_53 , 0 ) ;
if ( ! V_36 ) {
F_4 ( V_2 , L_7 ) ;
return - V_50 ;
}
V_37 = F_44 ( V_2 , V_36 ) ;
if ( F_31 ( V_37 ) ) {
V_10 = F_34 ( V_37 ) ;
return V_10 ;
}
V_8 -> V_11 = F_45 ( V_34 , 0 ) ;
if ( V_8 -> V_11 < 0 ) {
F_4 ( V_2 , L_8 ) ;
return - V_54 ;
}
V_8 -> V_12 = F_46 ( V_2 , V_37 ,
& V_55 ) ;
if ( F_31 ( V_8 -> V_12 ) ) {
F_4 ( V_2 , L_9 ) ;
return F_34 ( V_8 -> V_12 ) ;
}
V_8 -> V_32 = F_47 ( V_2 , L_10 ) ;
if ( F_31 ( V_8 -> V_32 ) ) {
F_4 ( V_2 , L_11 ) ;
return F_34 ( V_8 -> V_32 ) ;
}
V_10 = F_37 ( V_8 -> V_32 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_5 ) ;
return V_10 ;
}
V_41 = F_47 ( V_2 , L_12 ) ;
if ( F_31 ( V_41 ) ) {
V_41 = V_8 -> V_32 ;
}
V_43 = F_48 ( V_41 ) ;
snprintf ( V_42 , sizeof( V_42 ) , L_13 , V_43 ) ;
V_8 -> V_31 = F_49 ( V_2 , V_42 ,
V_43 , 0 , V_37 + V_56 ,
0 , 8 , V_57 , NULL ) ;
if ( F_31 ( V_8 -> V_31 ) ) {
F_4 ( V_2 , L_14 ) ;
V_10 = F_34 ( V_8 -> V_31 ) ;
goto V_58;
}
V_10 = F_37 ( V_8 -> V_31 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_6 ) ;
goto V_59;
}
V_8 -> V_60 = F_50 ( V_2 ) ;
V_29 = F_51 ( V_39 , V_2 ) ;
if ( ! V_29 ) {
V_10 = - V_47 ;
goto V_61;
}
V_8 -> V_2 = V_2 ;
V_8 -> V_29 = V_29 ;
V_8 -> V_62 = V_2 -> V_49 ;
V_29 -> V_9 = V_8 ;
F_52 ( V_2 , V_8 ) ;
V_10 = F_53 ( V_29 , 0 ) ;
if ( V_10 < 0 )
goto V_63;
F_54 ( L_15 , V_39 -> V_64 ,
V_39 -> V_65 , V_39 -> V_66 , V_39 -> V_67 ,
V_39 -> V_68 , V_29 -> V_69 -> V_70 ) ;
return 0 ;
V_63:
F_55 ( V_29 ) ;
V_61:
F_35 ( V_8 -> V_31 ) ;
V_59:
F_56 ( V_8 -> V_31 ) ;
V_58:
F_35 ( V_8 -> V_32 ) ;
return V_10 ;
}
static int F_57 ( struct V_33 * V_34 )
{
struct V_7 * V_8 = F_58 ( V_34 ) ;
F_35 ( V_8 -> V_32 ) ;
F_35 ( V_8 -> V_31 ) ;
F_56 ( V_8 -> V_31 ) ;
F_59 ( V_8 -> V_29 ) ;
return 0 ;
}
