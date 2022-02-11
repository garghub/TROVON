static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 . V_5 ) ;
}
static T_1
F_3 ( struct V_6 * V_4 , struct V_7 * V_7 ,
unsigned long V_8 , T_2 V_9 , enum V_10 V_11 ,
struct V_12 * V_13 )
{
void * V_14 = F_4 ( F_5 ( V_7 ) ) + V_8 ;
struct V_1 * V_15 = F_2 ( V_4 -> V_5 ) ;
return F_6 ( V_15 , V_14 , V_9 ) ;
}
static void
F_7 ( struct V_6 * V_4 , T_1 V_16 ,
T_2 V_9 , enum V_10 V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_15 = F_2 ( V_4 -> V_5 ) ;
F_8 ( V_15 , V_16 , V_9 ) ;
}
static struct V_17 *
F_9 ( struct V_2 * V_3 ,
T_3 V_18 , T_3 V_19 ,
const char * V_20 , void * V_21 , int V_22 )
{
return F_10 ( F_1 ( V_3 ) , V_18 ,
V_19 , V_20 , V_21 ,
V_22 , V_23 ) ;
}
static void F_11 ( struct V_2 * V_3 ,
struct V_17 * V_24 , void * V_21 )
{
return F_12 ( F_1 ( V_3 ) , V_24 , V_21 ) ;
}
static void F_13 ( struct V_2 * V_3 , int V_25 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
V_15 -> V_26 -> V_27 ( V_15 ) ;
}
static void F_14 ( struct V_1 * V_15 )
{
int V_28 ;
#define F_15 (45)
F_16 ( & V_15 -> V_29 ) ;
V_15 -> V_26 -> V_30 ( V_15 ) ;
V_15 -> V_26 -> V_31 ( V_15 ) ;
for ( V_28 = 0 ; V_28 < F_15 ; V_28 ++ ) {
if ( V_15 -> V_26 -> V_32 ( V_15 ) )
goto V_33;
F_17 ( 1000 ) ;
}
F_18 ( V_15 , V_34 ) ;
V_33:
F_19 ( & V_15 -> V_29 ) ;
}
void F_20 ( struct V_1 * V_15 )
{
struct V_35 * V_36 = V_15 -> V_37 ;
V_36 -> V_38 = F_21 ( V_39 ) ;
V_36 -> V_40 = V_15 -> V_41 ;
V_36 -> V_42 = - 1 ;
V_36 -> V_43 = - 1 ;
V_36 -> V_44 = 0 ;
V_36 -> V_45 = 0 ;
}
int F_22 ( struct V_1 * V_15 , const char * V_46 )
{
int V_47 ;
F_23 ( & V_15 -> V_48 ) ;
V_49:
if ( V_50 != V_15 -> V_51 ) {
V_47 = - V_52 ;
goto V_53;
}
if ( ! V_15 -> V_26 -> V_32 ( V_15 ) ) {
F_14 ( V_15 ) ;
goto V_49;
}
V_15 -> V_54 = F_24 ( V_15 -> V_55 -> V_5 ,
V_56 , & V_57 ,
& V_58 , V_15 -> V_59 . V_14 ) ;
if ( F_25 ( V_15 -> V_54 ) ) {
V_47 = F_26 ( V_15 -> V_54 ) ;
goto V_53;
}
V_15 -> V_60 = F_27 ( V_15 ) ;
if ( ! V_15 -> V_60 ) {
V_47 = - V_61 ;
goto V_62;
}
V_47 = V_15 -> V_26 -> V_63 ( V_15 , V_46 ) ;
if ( V_47 )
goto V_64;
F_28 ( V_15 ) ;
F_29 ( V_15 ) ;
V_15 -> V_65 -> V_66 ( V_15 ) ;
V_15 -> V_26 -> V_67 ( V_15 , V_68 , V_15 -> V_69 ) ;
V_15 -> V_26 -> V_67 ( V_15 , V_70 , V_15 -> V_69 >> 32 ) ;
V_15 -> V_26 -> V_71 ( V_15 ) ;
F_18 ( V_15 , V_72 ) ;
goto V_53;
V_64:
F_30 ( V_15 -> V_60 ) ;
V_62:
F_31 ( V_15 -> V_54 ) ;
V_53:
F_32 ( & V_15 -> V_48 ) ;
return V_47 ;
}
void F_33 ( struct V_1 * V_15 , bool V_73 )
{
F_23 ( & V_15 -> V_48 ) ;
if ( V_50 != V_15 -> V_51 || V_73 ) {
F_34 ( V_15 ) ;
if ( V_15 -> V_60 ) {
F_30 ( V_15 -> V_60 ) ;
V_15 -> V_60 = NULL ;
}
F_31 ( V_15 -> V_54 ) ;
F_20 ( V_15 ) ;
F_14 ( V_15 ) ;
if ( V_34 == V_15 -> V_51 )
goto V_74;
F_35 ( V_15 , V_75 ) ;
if ( V_76 != V_15 -> V_51 )
F_18 ( V_15 , V_50 ) ;
}
V_74:
F_32 ( & V_15 -> V_48 ) ;
}
void F_36 ( struct V_1 * V_15 )
{
struct V_35 * V_36 = V_15 -> V_37 ;
T_4 V_77 = V_36 -> V_42 ;
F_23 ( & V_15 -> V_48 ) ;
if ( V_72 == V_15 -> V_51 && V_77 != - 1 ) {
V_36 -> V_45 = 1 ;
V_15 -> V_26 -> V_78 ( V_15 , V_77 ) ;
F_18 ( V_15 , V_79 ) ;
}
F_32 ( & V_15 -> V_48 ) ;
}
void F_37 ( struct V_80 * V_81 )
{
struct V_1 * V_15 = F_38 ( V_81 , struct V_1 ,
V_82 ) ;
struct V_35 * V_36 = V_15 -> V_37 ;
F_23 ( & V_15 -> V_48 ) ;
F_35 ( V_15 , V_36 -> V_44 ) ;
V_36 -> V_44 = 0 ;
if ( V_79 != V_15 -> V_51 &&
V_76 != V_15 -> V_51 )
F_18 ( V_15 , V_79 ) ;
F_32 ( & V_15 -> V_48 ) ;
}
void F_39 ( struct V_80 * V_81 )
{
struct V_1 * V_15 = F_38 ( V_81 , struct V_1 ,
V_83 ) ;
F_33 ( V_15 , false ) ;
}
void F_40 ( struct V_1 * V_15 )
{
if ( V_15 -> V_51 != V_76 ) {
F_41 ( V_15 -> V_55 -> V_5 , L_1 ,
V_15 -> V_51 , V_76 ) ;
return;
}
if ( ! V_15 -> V_26 -> V_32 ( V_15 ) )
F_33 ( V_15 , true ) ;
F_23 ( & V_15 -> V_48 ) ;
F_18 ( V_15 , V_50 ) ;
F_32 ( & V_15 -> V_48 ) ;
}
void F_42 ( struct V_1 * V_15 )
{
unsigned long V_84 ;
#define F_43 (60 * HZ)
F_23 ( & V_15 -> V_48 ) ;
switch ( V_15 -> V_51 ) {
case V_50 :
F_18 ( V_15 , V_76 ) ;
F_32 ( & V_15 -> V_48 ) ;
break;
case V_72 :
F_18 ( V_15 , V_85 ) ;
F_32 ( & V_15 -> V_48 ) ;
V_84 = F_44 ( & V_15 -> V_29 ,
F_43 ) ;
if ( ! V_84 ) {
F_23 ( & V_15 -> V_48 ) ;
F_18 ( V_15 , V_76 ) ;
F_32 ( & V_15 -> V_48 ) ;
F_33 ( V_15 , true ) ;
}
break;
case V_79 :
F_18 ( V_15 , V_76 ) ;
F_32 ( & V_15 -> V_48 ) ;
V_84 = F_44 ( & V_15 -> V_29 ,
F_43 ) ;
if ( ! V_84 )
F_33 ( V_15 , true ) ;
break;
default:
F_32 ( & V_15 -> V_48 ) ;
break;
}
}
void F_45 ( struct V_1 * V_15 )
{
struct V_35 * V_36 = V_15 -> V_37 ;
T_4 V_77 = V_36 -> V_42 ;
F_23 ( & V_15 -> V_48 ) ;
if ( V_85 == V_15 -> V_51 && V_77 != - 1 ) {
V_36 -> V_45 = 1 ;
V_15 -> V_26 -> V_78 ( V_15 , V_77 ) ;
F_18 ( V_15 , V_76 ) ;
}
F_32 ( & V_15 -> V_48 ) ;
}
