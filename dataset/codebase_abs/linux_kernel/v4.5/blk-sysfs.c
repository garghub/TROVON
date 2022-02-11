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
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_21 . V_26 << 9 ) ;
}
static T_1 F_29 ( struct V_8 * V_9 ,
const char * V_2 , T_2 V_3 )
{
unsigned long V_27 ;
T_1 V_12 = F_2 ( & V_27 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_27 & ( V_9 -> V_21 . V_24 - 1 ) )
return - V_7 ;
V_27 >>= 9 ;
if ( V_27 > V_6 )
return - V_7 ;
if ( V_27 > V_9 -> V_21 . V_25 )
V_27 = V_9 -> V_21 . V_25 ;
V_9 -> V_21 . V_26 = V_27 ;
return V_12 ;
}
static T_1 F_30 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_31 ( V_9 ) , V_2 ) ;
}
static T_1 F_32 ( struct V_8 * V_9 , char * V_2 )
{
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_21 . V_28 << 9 ) ;
}
static T_1
F_33 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
unsigned long V_20 ,
V_29 = F_34 ( V_9 ) >> 1 ,
V_30 = 1 << ( V_19 - 10 ) ;
T_1 V_12 = F_2 ( & V_20 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_29 = F_35 ( V_29 , ( unsigned long )
V_9 -> V_21 . V_31 >> 1 ) ;
if ( V_20 > V_29 || V_20 < V_30 )
return - V_7 ;
F_36 ( V_9 -> V_32 ) ;
V_9 -> V_21 . V_33 = V_20 << 1 ;
F_37 ( V_9 -> V_32 ) ;
return V_12 ;
}
static T_1 F_38 ( struct V_8 * V_9 , char * V_2 )
{
int V_29 = F_34 ( V_9 ) >> 1 ;
return F_1 ( V_29 , ( V_2 ) ) ;
}
static T_1 F_39 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( ( F_40 ( V_9 ) << 1 ) |
F_41 ( V_9 ) , V_2 ) ;
}
static T_1 F_42 ( struct V_8 * V_9 , const char * V_2 ,
T_2 V_3 )
{
unsigned long V_34 ;
T_1 V_12 = F_2 ( & V_34 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_36 ( V_9 -> V_32 ) ;
F_43 ( V_35 , V_9 ) ;
F_43 ( V_36 , V_9 ) ;
if ( V_34 == 2 )
F_44 ( V_35 , V_9 ) ;
else if ( V_34 )
F_44 ( V_36 , V_9 ) ;
F_37 ( V_9 -> V_32 ) ;
return V_12 ;
}
static T_1 F_45 ( struct V_8 * V_9 , char * V_2 )
{
bool V_37 = F_46 ( V_38 , & V_9 -> V_39 ) ;
bool V_40 = F_46 ( V_41 , & V_9 -> V_39 ) ;
return F_1 ( V_37 << V_40 , V_2 ) ;
}
static T_1
F_47 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
T_1 V_12 = - V_7 ;
#ifdef F_48
unsigned long V_42 ;
V_12 = F_2 ( & V_42 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_36 ( V_9 -> V_32 ) ;
if ( V_42 == 2 ) {
F_44 ( V_38 , V_9 ) ;
F_44 ( V_41 , V_9 ) ;
} else if ( V_42 == 1 ) {
F_44 ( V_38 , V_9 ) ;
F_43 ( V_41 , V_9 ) ;
} else if ( V_42 == 0 ) {
F_43 ( V_38 , V_9 ) ;
F_43 ( V_41 , V_9 ) ;
}
F_37 ( V_9 -> V_32 ) ;
#endif
return V_12 ;
}
static T_1 F_49 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_46 ( V_43 , & V_9 -> V_39 ) , V_2 ) ;
}
static T_1 F_50 ( struct V_8 * V_9 , const char * V_2 ,
T_2 V_3 )
{
unsigned long V_44 ;
T_1 V_12 ;
if ( ! V_9 -> V_14 || ! V_9 -> V_14 -> V_45 )
return - V_7 ;
V_12 = F_2 ( & V_44 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_36 ( V_9 -> V_32 ) ;
if ( V_44 )
F_44 ( V_43 , V_9 ) ;
else
F_43 ( V_43 , V_9 ) ;
F_37 ( V_9 -> V_32 ) ;
return V_12 ;
}
static T_1
F_51 ( struct V_46 * V_47 , struct V_48 * V_49 , char * V_2 )
{
struct V_50 * V_51 = F_52 ( V_49 ) ;
struct V_8 * V_9 =
F_53 ( V_47 , struct V_8 , V_47 ) ;
T_1 V_52 ;
if ( ! V_51 -> V_53 )
return - V_54 ;
F_54 ( & V_9 -> V_55 ) ;
if ( F_55 ( V_9 ) ) {
F_56 ( & V_9 -> V_55 ) ;
return - V_56 ;
}
V_52 = V_51 -> V_53 ( V_9 , V_2 ) ;
F_56 ( & V_9 -> V_55 ) ;
return V_52 ;
}
static T_1
F_57 ( struct V_46 * V_47 , struct V_48 * V_49 ,
const char * V_2 , T_2 V_57 )
{
struct V_50 * V_51 = F_52 ( V_49 ) ;
struct V_8 * V_9 ;
T_1 V_52 ;
if ( ! V_51 -> V_58 )
return - V_54 ;
V_9 = F_53 ( V_47 , struct V_8 , V_47 ) ;
F_54 ( & V_9 -> V_55 ) ;
if ( F_55 ( V_9 ) ) {
F_56 ( & V_9 -> V_55 ) ;
return - V_56 ;
}
V_52 = V_51 -> V_58 ( V_9 , V_2 , V_57 ) ;
F_56 ( & V_9 -> V_55 ) ;
return V_52 ;
}
static void F_58 ( struct V_59 * V_59 )
{
struct V_8 * V_9 = F_53 ( V_59 , struct V_8 ,
V_59 ) ;
F_59 ( V_60 , V_9 ) ;
}
static void F_60 ( struct V_46 * V_47 )
{
struct V_8 * V_9 =
F_53 ( V_47 , struct V_8 , V_47 ) ;
F_61 ( & V_9 -> V_17 ) ;
F_62 ( V_9 ) ;
if ( V_9 -> V_61 ) {
F_36 ( V_9 -> V_32 ) ;
F_63 ( V_9 ) ;
F_37 ( V_9 -> V_32 ) ;
F_64 ( V_9 -> V_61 ) ;
}
F_65 ( & V_9 -> V_62 ) ;
if ( V_9 -> V_63 )
F_66 ( V_9 ) ;
if ( ! V_9 -> V_14 )
F_67 ( V_9 -> V_64 ) ;
else
F_68 ( V_9 ) ;
F_69 ( V_9 ) ;
if ( V_9 -> V_65 )
F_70 ( V_9 -> V_65 ) ;
F_71 ( & V_66 , V_9 -> V_67 ) ;
F_72 ( & V_9 -> V_59 , F_58 ) ;
}
int F_73 ( struct V_68 * V_69 )
{
int V_12 ;
struct V_70 * V_71 = F_74 ( V_69 ) ;
struct V_8 * V_9 = V_69 -> V_72 ;
if ( F_75 ( ! V_9 ) )
return - V_73 ;
if ( ! F_76 ( V_9 ) ) {
F_77 ( V_74 , V_9 ) ;
F_78 ( & V_9 -> V_75 ) ;
F_79 ( V_9 ) ;
}
V_12 = F_80 ( V_71 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_81 ( & V_9 -> V_47 , F_82 ( & V_71 -> V_47 ) , L_3 , L_4 ) ;
if ( V_12 < 0 ) {
F_83 ( V_71 ) ;
return V_12 ;
}
F_84 ( & V_9 -> V_47 , V_76 ) ;
if ( V_9 -> V_14 )
F_85 ( V_69 ) ;
if ( ! V_9 -> V_13 )
return 0 ;
V_12 = F_86 ( V_9 ) ;
if ( V_12 ) {
F_84 ( & V_9 -> V_47 , V_77 ) ;
F_87 ( & V_9 -> V_47 ) ;
F_83 ( V_71 ) ;
F_88 ( & V_71 -> V_47 ) ;
return V_12 ;
}
return 0 ;
}
void F_89 ( struct V_68 * V_69 )
{
struct V_8 * V_9 = V_69 -> V_72 ;
if ( F_75 ( ! V_9 ) )
return;
if ( V_9 -> V_14 )
F_90 ( V_69 ) ;
if ( V_9 -> V_13 )
F_91 ( V_9 ) ;
F_84 ( & V_9 -> V_47 , V_77 ) ;
F_87 ( & V_9 -> V_47 ) ;
F_83 ( F_74 ( V_69 ) ) ;
F_88 ( & F_74 ( V_69 ) -> V_47 ) ;
}
