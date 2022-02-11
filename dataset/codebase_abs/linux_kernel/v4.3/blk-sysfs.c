static T_1
F_1 ( unsigned long V_1 , char * V_2 )
{
return sprintf ( V_2 , L_1 , V_1 ) ;
}
static T_1
F_2 ( unsigned long * V_1 , const char * V_2 , T_2 V_3 )
{
int V_4 ;
unsigned long V_5 ;
V_4 = F_3 ( V_2 , 10 , & V_5 ) ;
if ( V_4 || V_5 > V_6 )
return - V_7 ;
* V_1 = V_5 ;
return V_3 ;
}
static T_1 F_4 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( V_9 -> V_10 , ( V_2 ) ) ;
}
static T_1
F_5 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
unsigned long V_11 ;
int V_12 , V_4 ;
if ( ! V_9 -> V_13 && ! V_9 -> V_14 )
return - V_7 ;
V_12 = F_2 ( & V_11 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_11 < V_15 )
V_11 = V_15 ;
if ( V_9 -> V_13 )
V_4 = F_6 ( V_9 , V_11 ) ;
else
V_4 = F_7 ( V_9 , V_11 ) ;
if ( V_4 )
return V_4 ;
return V_12 ;
}
static T_1 F_8 ( struct V_8 * V_9 , char * V_2 )
{
unsigned long V_16 = V_9 -> V_17 . V_18 <<
( V_19 - 10 ) ;
return F_1 ( V_16 , ( V_2 ) ) ;
}
static T_1
F_9 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
unsigned long V_16 ;
T_1 V_12 = F_2 ( & V_16 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_9 -> V_17 . V_18 = V_16 >> ( V_19 - 10 ) ;
return V_12 ;
}
static T_1 F_10 ( struct V_8 * V_9 , char * V_2 )
{
int V_20 = F_11 ( V_9 ) >> 1 ;
return F_1 ( V_20 , ( V_2 ) ) ;
}
static T_1 F_12 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_13 ( V_9 ) , ( V_2 ) ) ;
}
static T_1 F_14 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( V_9 -> V_21 . V_22 , ( V_2 ) ) ;
}
static T_1 F_15 ( struct V_8 * V_9 , char * V_2 )
{
if ( F_16 ( V_9 ) )
return F_1 ( F_17 ( V_9 ) , ( V_2 ) ) ;
return F_1 ( V_23 , ( V_2 ) ) ;
}
static T_1 F_18 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_19 ( V_9 ) , V_2 ) ;
}
static T_1 F_20 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_21 ( V_9 ) , V_2 ) ;
}
static T_1 F_22 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_23 ( V_9 ) , V_2 ) ;
}
static T_1 F_24 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_25 ( V_9 ) , V_2 ) ;
}
static T_1 F_26 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( V_9 -> V_21 . V_24 , V_2 ) ;
}
static T_1 F_27 ( struct V_8 * V_9 , char * V_2 )
{
unsigned long long V_25 ;
V_25 = V_9 -> V_21 . V_26 << 9 ;
return sprintf ( V_2 , L_2 , V_25 ) ;
}
static T_1 F_28 ( struct V_8 * V_9 , char * V_2 )
{
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_21 . V_27 << 9 ) ;
}
static T_1 F_29 ( struct V_8 * V_9 ,
const char * V_2 , T_2 V_3 )
{
unsigned long V_28 ;
T_1 V_12 = F_2 ( & V_28 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_28 & ( V_9 -> V_21 . V_24 - 1 ) )
return - V_7 ;
V_28 >>= 9 ;
if ( V_28 > V_6 )
return - V_7 ;
if ( V_28 > V_9 -> V_21 . V_26 )
V_28 = V_9 -> V_21 . V_26 ;
V_9 -> V_21 . V_27 = V_28 ;
return V_12 ;
}
static T_1 F_30 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_31 ( V_9 ) , V_2 ) ;
}
static T_1 F_32 ( struct V_8 * V_9 , char * V_2 )
{
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_21 . V_29 << 9 ) ;
}
static T_1
F_33 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
unsigned long V_20 ,
V_30 = F_34 ( V_9 ) >> 1 ,
V_31 = 1 << ( V_19 - 10 ) ;
T_1 V_12 = F_2 ( & V_20 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_20 > V_30 || V_20 < V_31 )
return - V_7 ;
F_35 ( V_9 -> V_32 ) ;
V_9 -> V_21 . V_33 = V_20 << 1 ;
F_36 ( V_9 -> V_32 ) ;
return V_12 ;
}
static T_1 F_37 ( struct V_8 * V_9 , char * V_2 )
{
int V_30 = F_34 ( V_9 ) >> 1 ;
return F_1 ( V_30 , ( V_2 ) ) ;
}
static T_1 F_38 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( ( F_39 ( V_9 ) << 1 ) |
F_40 ( V_9 ) , V_2 ) ;
}
static T_1 F_41 ( struct V_8 * V_9 , const char * V_2 ,
T_2 V_3 )
{
unsigned long V_34 ;
T_1 V_12 = F_2 ( & V_34 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_35 ( V_9 -> V_32 ) ;
F_42 ( V_35 , V_9 ) ;
F_42 ( V_36 , V_9 ) ;
if ( V_34 == 2 )
F_43 ( V_35 , V_9 ) ;
else if ( V_34 )
F_43 ( V_36 , V_9 ) ;
F_36 ( V_9 -> V_32 ) ;
return V_12 ;
}
static T_1 F_44 ( struct V_8 * V_9 , char * V_2 )
{
bool V_37 = F_45 ( V_38 , & V_9 -> V_39 ) ;
bool V_40 = F_45 ( V_41 , & V_9 -> V_39 ) ;
return F_1 ( V_37 << V_40 , V_2 ) ;
}
static T_1
F_46 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
T_1 V_12 = - V_7 ;
#ifdef F_47
unsigned long V_25 ;
V_12 = F_2 ( & V_25 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_35 ( V_9 -> V_32 ) ;
if ( V_25 == 2 ) {
F_43 ( V_38 , V_9 ) ;
F_43 ( V_41 , V_9 ) ;
} else if ( V_25 == 1 ) {
F_43 ( V_38 , V_9 ) ;
F_42 ( V_41 , V_9 ) ;
} else if ( V_25 == 0 ) {
F_42 ( V_38 , V_9 ) ;
F_42 ( V_41 , V_9 ) ;
}
F_36 ( V_9 -> V_32 ) ;
#endif
return V_12 ;
}
static T_1
F_48 ( struct V_42 * V_43 , struct V_44 * V_45 , char * V_2 )
{
struct V_46 * V_47 = F_49 ( V_45 ) ;
struct V_8 * V_9 =
F_50 ( V_43 , struct V_8 , V_43 ) ;
T_1 V_48 ;
if ( ! V_47 -> V_49 )
return - V_50 ;
F_51 ( & V_9 -> V_51 ) ;
if ( F_52 ( V_9 ) ) {
F_53 ( & V_9 -> V_51 ) ;
return - V_52 ;
}
V_48 = V_47 -> V_49 ( V_9 , V_2 ) ;
F_53 ( & V_9 -> V_51 ) ;
return V_48 ;
}
static T_1
F_54 ( struct V_42 * V_43 , struct V_44 * V_45 ,
const char * V_2 , T_2 V_53 )
{
struct V_46 * V_47 = F_49 ( V_45 ) ;
struct V_8 * V_9 ;
T_1 V_48 ;
if ( ! V_47 -> V_54 )
return - V_50 ;
V_9 = F_50 ( V_43 , struct V_8 , V_43 ) ;
F_51 ( & V_9 -> V_51 ) ;
if ( F_52 ( V_9 ) ) {
F_53 ( & V_9 -> V_51 ) ;
return - V_52 ;
}
V_48 = V_47 -> V_54 ( V_9 , V_2 , V_53 ) ;
F_53 ( & V_9 -> V_51 ) ;
return V_48 ;
}
static void F_55 ( struct V_55 * V_55 )
{
struct V_8 * V_9 = F_50 ( V_55 , struct V_8 ,
V_55 ) ;
F_56 ( V_56 , V_9 ) ;
}
static void F_57 ( struct V_42 * V_43 )
{
struct V_8 * V_9 =
F_50 ( V_43 , struct V_8 , V_43 ) ;
F_58 ( & V_9 -> V_17 ) ;
F_59 ( V_9 ) ;
if ( V_9 -> V_57 ) {
F_35 ( V_9 -> V_32 ) ;
F_60 ( V_9 ) ;
F_36 ( V_9 -> V_32 ) ;
F_61 ( V_9 -> V_57 ) ;
}
F_62 ( & V_9 -> V_58 ) ;
if ( V_9 -> V_59 )
F_63 ( V_9 ) ;
if ( ! V_9 -> V_14 )
F_64 ( V_9 -> V_60 ) ;
else
F_65 ( V_9 ) ;
F_66 ( V_9 ) ;
if ( V_9 -> V_61 )
F_67 ( V_9 -> V_61 ) ;
F_68 ( & V_62 , V_9 -> V_63 ) ;
F_69 ( & V_9 -> V_55 , F_55 ) ;
}
int F_70 ( struct V_64 * V_65 )
{
int V_12 ;
struct V_66 * V_67 = F_71 ( V_65 ) ;
struct V_8 * V_9 = V_65 -> V_68 ;
if ( F_72 ( ! V_9 ) )
return - V_69 ;
if ( ! F_73 ( V_9 ) ) {
F_74 ( V_70 , V_9 ) ;
F_75 ( V_9 ) ;
if ( V_9 -> V_14 )
F_76 ( V_9 ) ;
}
V_12 = F_77 ( V_67 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_78 ( & V_9 -> V_43 , F_79 ( & V_67 -> V_43 ) , L_3 , L_4 ) ;
if ( V_12 < 0 ) {
F_80 ( V_67 ) ;
return V_12 ;
}
F_81 ( & V_9 -> V_43 , V_71 ) ;
if ( V_9 -> V_14 )
F_82 ( V_65 ) ;
if ( ! V_9 -> V_13 )
return 0 ;
V_12 = F_83 ( V_9 ) ;
if ( V_12 ) {
F_81 ( & V_9 -> V_43 , V_72 ) ;
F_84 ( & V_9 -> V_43 ) ;
F_80 ( V_67 ) ;
F_85 ( & V_67 -> V_43 ) ;
return V_12 ;
}
return 0 ;
}
void F_86 ( struct V_64 * V_65 )
{
struct V_8 * V_9 = V_65 -> V_68 ;
if ( F_72 ( ! V_9 ) )
return;
if ( V_9 -> V_14 )
F_87 ( V_65 ) ;
if ( V_9 -> V_13 )
F_88 ( V_9 ) ;
F_81 ( & V_9 -> V_43 , V_72 ) ;
F_84 ( & V_9 -> V_43 ) ;
F_80 ( F_71 ( V_65 ) ) ;
F_85 ( & F_71 ( V_65 ) -> V_43 ) ;
}
