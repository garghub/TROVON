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
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_21 . V_25 << 9 ) ;
}
static T_1 F_28 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_29 ( V_9 ) , V_2 ) ;
}
static T_1 F_30 ( struct V_8 * V_9 , char * V_2 )
{
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_21 . V_26 << 9 ) ;
}
static T_1
F_31 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
unsigned long V_20 ,
V_27 = F_32 ( V_9 ) >> 1 ,
V_28 = 1 << ( V_19 - 10 ) ;
T_1 V_12 = F_2 ( & V_20 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_20 > V_27 || V_20 < V_28 )
return - V_7 ;
F_33 ( V_9 -> V_29 ) ;
V_9 -> V_21 . V_30 = V_20 << 1 ;
F_34 ( V_9 -> V_29 ) ;
return V_12 ;
}
static T_1 F_35 ( struct V_8 * V_9 , char * V_2 )
{
int V_27 = F_32 ( V_9 ) >> 1 ;
return F_1 ( V_27 , ( V_2 ) ) ;
}
static T_1 F_36 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( ( F_37 ( V_9 ) << 1 ) |
F_38 ( V_9 ) , V_2 ) ;
}
static T_1 F_39 ( struct V_8 * V_9 , const char * V_2 ,
T_2 V_3 )
{
unsigned long V_31 ;
T_1 V_12 = F_2 ( & V_31 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_33 ( V_9 -> V_29 ) ;
F_40 ( V_32 , V_9 ) ;
F_40 ( V_33 , V_9 ) ;
if ( V_31 == 2 )
F_41 ( V_32 , V_9 ) ;
else if ( V_31 )
F_41 ( V_33 , V_9 ) ;
F_34 ( V_9 -> V_29 ) ;
return V_12 ;
}
static T_1 F_42 ( struct V_8 * V_9 , char * V_2 )
{
bool V_34 = F_43 ( V_35 , & V_9 -> V_36 ) ;
bool V_37 = F_43 ( V_38 , & V_9 -> V_36 ) ;
return F_1 ( V_34 << V_37 , V_2 ) ;
}
static T_1
F_44 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
T_1 V_12 = - V_7 ;
#ifdef F_45
unsigned long V_39 ;
V_12 = F_2 ( & V_39 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_33 ( V_9 -> V_29 ) ;
if ( V_39 == 2 ) {
F_41 ( V_35 , V_9 ) ;
F_41 ( V_38 , V_9 ) ;
} else if ( V_39 == 1 ) {
F_41 ( V_35 , V_9 ) ;
F_40 ( V_38 , V_9 ) ;
} else if ( V_39 == 0 ) {
F_40 ( V_35 , V_9 ) ;
F_40 ( V_38 , V_9 ) ;
}
F_34 ( V_9 -> V_29 ) ;
#endif
return V_12 ;
}
static T_1
F_46 ( struct V_40 * V_41 , struct V_42 * V_43 , char * V_2 )
{
struct V_44 * V_45 = F_47 ( V_43 ) ;
struct V_8 * V_9 =
F_48 ( V_41 , struct V_8 , V_41 ) ;
T_1 V_46 ;
if ( ! V_45 -> V_47 )
return - V_48 ;
F_49 ( & V_9 -> V_49 ) ;
if ( F_50 ( V_9 ) ) {
F_51 ( & V_9 -> V_49 ) ;
return - V_50 ;
}
V_46 = V_45 -> V_47 ( V_9 , V_2 ) ;
F_51 ( & V_9 -> V_49 ) ;
return V_46 ;
}
static T_1
F_52 ( struct V_40 * V_41 , struct V_42 * V_43 ,
const char * V_2 , T_2 V_51 )
{
struct V_44 * V_45 = F_47 ( V_43 ) ;
struct V_8 * V_9 ;
T_1 V_46 ;
if ( ! V_45 -> V_52 )
return - V_48 ;
V_9 = F_48 ( V_41 , struct V_8 , V_41 ) ;
F_49 ( & V_9 -> V_49 ) ;
if ( F_50 ( V_9 ) ) {
F_51 ( & V_9 -> V_49 ) ;
return - V_50 ;
}
V_46 = V_45 -> V_52 ( V_9 , V_2 , V_51 ) ;
F_51 ( & V_9 -> V_49 ) ;
return V_46 ;
}
static void F_53 ( struct V_53 * V_53 )
{
struct V_8 * V_9 = F_48 ( V_53 , struct V_8 ,
V_53 ) ;
F_54 ( V_54 , V_9 ) ;
}
static void F_55 ( struct V_40 * V_41 )
{
struct V_8 * V_9 =
F_48 ( V_41 , struct V_8 , V_41 ) ;
F_56 ( V_9 ) ;
if ( V_9 -> V_55 ) {
F_33 ( V_9 -> V_29 ) ;
F_57 ( V_9 ) ;
F_34 ( V_9 -> V_29 ) ;
F_58 ( V_9 -> V_55 ) ;
}
F_59 ( & V_9 -> V_56 ) ;
if ( V_9 -> V_57 )
F_60 ( V_9 ) ;
if ( ! V_9 -> V_14 )
F_61 ( V_9 -> V_58 ) ;
else
F_62 ( V_9 ) ;
F_63 ( V_9 ) ;
F_64 ( & V_59 , V_9 -> V_60 ) ;
F_65 ( & V_9 -> V_53 , F_53 ) ;
}
int F_66 ( struct V_61 * V_62 )
{
int V_12 ;
struct V_63 * V_64 = F_67 ( V_62 ) ;
struct V_8 * V_9 = V_62 -> V_65 ;
if ( F_68 ( ! V_9 ) )
return - V_66 ;
if ( ! F_69 ( V_9 ) ) {
F_70 ( V_67 , V_9 ) ;
F_71 ( V_9 ) ;
if ( V_9 -> V_14 )
F_72 ( V_9 ) ;
}
V_12 = F_73 ( V_64 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_74 ( & V_9 -> V_41 , F_75 ( & V_64 -> V_41 ) , L_3 , L_4 ) ;
if ( V_12 < 0 ) {
F_76 ( V_64 ) ;
return V_12 ;
}
F_77 ( & V_9 -> V_41 , V_68 ) ;
if ( V_9 -> V_14 )
F_78 ( V_62 ) ;
if ( ! V_9 -> V_13 )
return 0 ;
V_12 = F_79 ( V_9 ) ;
if ( V_12 ) {
F_77 ( & V_9 -> V_41 , V_69 ) ;
F_80 ( & V_9 -> V_41 ) ;
F_76 ( V_64 ) ;
F_81 ( & V_64 -> V_41 ) ;
return V_12 ;
}
return 0 ;
}
void F_82 ( struct V_61 * V_62 )
{
struct V_8 * V_9 = V_62 -> V_65 ;
if ( F_68 ( ! V_9 ) )
return;
if ( V_9 -> V_14 )
F_83 ( V_62 ) ;
if ( V_9 -> V_13 )
F_84 ( V_9 ) ;
F_77 ( & V_9 -> V_41 , V_69 ) ;
F_80 ( & V_9 -> V_41 ) ;
F_76 ( F_67 ( V_62 ) ) ;
F_81 ( & F_67 ( V_62 ) -> V_41 ) ;
}
