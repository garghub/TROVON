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
struct V_11 * V_12 ;
unsigned long V_13 ;
int V_14 ;
if ( ! V_9 -> V_15 )
return - V_7 ;
V_14 = F_2 ( & V_13 , V_2 , V_3 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_13 < V_16 )
V_13 = V_16 ;
F_6 ( V_9 -> V_17 ) ;
V_9 -> V_10 = V_13 ;
F_7 ( V_9 ) ;
V_12 = & V_9 -> V_18 ;
if ( V_12 -> V_3 [ V_19 ] >= F_8 ( V_9 ) )
F_9 ( V_9 , V_19 ) ;
else if ( V_12 -> V_3 [ V_19 ] < F_10 ( V_9 ) )
F_11 ( V_9 , V_19 ) ;
if ( V_12 -> V_3 [ V_20 ] >= F_8 ( V_9 ) )
F_9 ( V_9 , V_20 ) ;
else if ( V_12 -> V_3 [ V_20 ] < F_10 ( V_9 ) )
F_11 ( V_9 , V_20 ) ;
F_12 (rl, q) {
if ( V_12 -> V_3 [ V_19 ] >= V_9 -> V_10 ) {
F_13 ( V_12 , V_19 ) ;
} else {
F_14 ( V_12 , V_19 ) ;
F_15 ( & V_12 -> V_21 [ V_19 ] ) ;
}
if ( V_12 -> V_3 [ V_20 ] >= V_9 -> V_10 ) {
F_13 ( V_12 , V_20 ) ;
} else {
F_14 ( V_12 , V_20 ) ;
F_15 ( & V_12 -> V_21 [ V_20 ] ) ;
}
}
F_16 ( V_9 -> V_17 ) ;
return V_14 ;
}
static T_1 F_17 ( struct V_8 * V_9 , char * V_2 )
{
unsigned long V_22 = V_9 -> V_23 . V_24 <<
( V_25 - 10 ) ;
return F_1 ( V_22 , ( V_2 ) ) ;
}
static T_1
F_18 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
unsigned long V_22 ;
T_1 V_14 = F_2 ( & V_22 , V_2 , V_3 ) ;
if ( V_14 < 0 )
return V_14 ;
V_9 -> V_23 . V_24 = V_22 >> ( V_25 - 10 ) ;
return V_14 ;
}
static T_1 F_19 ( struct V_8 * V_9 , char * V_2 )
{
int V_26 = F_20 ( V_9 ) >> 1 ;
return F_1 ( V_26 , ( V_2 ) ) ;
}
static T_1 F_21 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_22 ( V_9 ) , ( V_2 ) ) ;
}
static T_1 F_23 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( V_9 -> V_27 . V_28 , ( V_2 ) ) ;
}
static T_1 F_24 ( struct V_8 * V_9 , char * V_2 )
{
if ( F_25 ( V_9 ) )
return F_1 ( F_26 ( V_9 ) , ( V_2 ) ) ;
return F_1 ( V_29 , ( V_2 ) ) ;
}
static T_1 F_27 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_28 ( V_9 ) , V_2 ) ;
}
static T_1 F_29 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_30 ( V_9 ) , V_2 ) ;
}
static T_1 F_31 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_32 ( V_9 ) , V_2 ) ;
}
static T_1 F_33 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_34 ( V_9 ) , V_2 ) ;
}
static T_1 F_35 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( V_9 -> V_27 . V_30 , V_2 ) ;
}
static T_1 F_36 ( struct V_8 * V_9 , char * V_2 )
{
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_27 . V_31 << 9 ) ;
}
static T_1 F_37 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_38 ( V_9 ) , V_2 ) ;
}
static T_1 F_39 ( struct V_8 * V_9 , char * V_2 )
{
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_27 . V_32 << 9 ) ;
}
static T_1
F_40 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
unsigned long V_26 ,
V_33 = F_41 ( V_9 ) >> 1 ,
V_34 = 1 << ( V_25 - 10 ) ;
T_1 V_14 = F_2 ( & V_26 , V_2 , V_3 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_26 > V_33 || V_26 < V_34 )
return - V_7 ;
F_6 ( V_9 -> V_17 ) ;
V_9 -> V_27 . V_35 = V_26 << 1 ;
F_16 ( V_9 -> V_17 ) ;
return V_14 ;
}
static T_1 F_42 ( struct V_8 * V_9 , char * V_2 )
{
int V_33 = F_41 ( V_9 ) >> 1 ;
return F_1 ( V_33 , ( V_2 ) ) ;
}
static T_1 F_43 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( ( F_44 ( V_9 ) << 1 ) |
F_45 ( V_9 ) , V_2 ) ;
}
static T_1 F_46 ( struct V_8 * V_9 , const char * V_2 ,
T_2 V_3 )
{
unsigned long V_36 ;
T_1 V_14 = F_2 ( & V_36 , V_2 , V_3 ) ;
if ( V_14 < 0 )
return V_14 ;
F_6 ( V_9 -> V_17 ) ;
F_47 ( V_37 , V_9 ) ;
F_47 ( V_38 , V_9 ) ;
if ( V_36 == 2 )
F_48 ( V_37 , V_9 ) ;
else if ( V_36 )
F_48 ( V_38 , V_9 ) ;
F_16 ( V_9 -> V_17 ) ;
return V_14 ;
}
static T_1 F_49 ( struct V_8 * V_9 , char * V_2 )
{
bool V_39 = F_50 ( V_40 , & V_9 -> V_41 ) ;
bool V_42 = F_50 ( V_43 , & V_9 -> V_41 ) ;
return F_1 ( V_39 << V_42 , V_2 ) ;
}
static T_1
F_51 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
T_1 V_14 = - V_7 ;
#if F_52 ( V_44 )
unsigned long V_45 ;
V_14 = F_2 ( & V_45 , V_2 , V_3 ) ;
if ( V_14 < 0 )
return V_14 ;
F_6 ( V_9 -> V_17 ) ;
if ( V_45 == 2 ) {
F_48 ( V_40 , V_9 ) ;
F_48 ( V_43 , V_9 ) ;
} else if ( V_45 == 1 ) {
F_48 ( V_40 , V_9 ) ;
F_47 ( V_43 , V_9 ) ;
} else if ( V_45 == 0 ) {
F_47 ( V_40 , V_9 ) ;
F_47 ( V_43 , V_9 ) ;
}
F_16 ( V_9 -> V_17 ) ;
#endif
return V_14 ;
}
static T_1
F_53 ( struct V_46 * V_47 , struct V_48 * V_49 , char * V_2 )
{
struct V_50 * V_51 = F_54 ( V_49 ) ;
struct V_8 * V_9 =
F_55 ( V_47 , struct V_8 , V_47 ) ;
T_1 V_52 ;
if ( ! V_51 -> V_53 )
return - V_54 ;
F_56 ( & V_9 -> V_55 ) ;
if ( F_57 ( V_9 ) ) {
F_58 ( & V_9 -> V_55 ) ;
return - V_56 ;
}
V_52 = V_51 -> V_53 ( V_9 , V_2 ) ;
F_58 ( & V_9 -> V_55 ) ;
return V_52 ;
}
static T_1
F_59 ( struct V_46 * V_47 , struct V_48 * V_49 ,
const char * V_2 , T_2 V_57 )
{
struct V_50 * V_51 = F_54 ( V_49 ) ;
struct V_8 * V_9 ;
T_1 V_52 ;
if ( ! V_51 -> V_58 )
return - V_54 ;
V_9 = F_55 ( V_47 , struct V_8 , V_47 ) ;
F_56 ( & V_9 -> V_55 ) ;
if ( F_57 ( V_9 ) ) {
F_58 ( & V_9 -> V_55 ) ;
return - V_56 ;
}
V_52 = V_51 -> V_58 ( V_9 , V_2 , V_57 ) ;
F_58 ( & V_9 -> V_55 ) ;
return V_52 ;
}
static void F_60 ( struct V_59 * V_59 )
{
struct V_8 * V_9 = F_55 ( V_59 , struct V_8 ,
V_59 ) ;
F_61 ( V_60 , V_9 ) ;
}
static void F_62 ( struct V_46 * V_47 )
{
struct V_8 * V_9 =
F_55 ( V_47 , struct V_8 , V_47 ) ;
F_63 ( V_9 ) ;
F_64 ( V_9 ) ;
if ( V_9 -> V_61 ) {
F_6 ( V_9 -> V_17 ) ;
F_65 ( V_9 ) ;
F_16 ( V_9 -> V_17 ) ;
F_66 ( V_9 -> V_61 ) ;
}
F_67 ( & V_9 -> V_18 ) ;
if ( V_9 -> V_62 )
F_68 ( V_9 ) ;
F_69 ( V_9 ) ;
F_70 ( & V_9 -> V_23 ) ;
F_71 ( & V_63 , V_9 -> V_64 ) ;
F_72 ( & V_9 -> V_59 , F_60 ) ;
}
int F_73 ( struct V_65 * V_66 )
{
int V_14 ;
struct V_67 * V_68 = F_74 ( V_66 ) ;
struct V_8 * V_9 = V_66 -> V_69 ;
if ( F_75 ( ! V_9 ) )
return - V_70 ;
F_76 ( V_9 ) ;
V_14 = F_77 ( V_68 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_78 ( & V_9 -> V_47 , F_79 ( & V_68 -> V_47 ) , L_3 , L_4 ) ;
if ( V_14 < 0 ) {
F_80 ( V_68 ) ;
return V_14 ;
}
F_81 ( & V_9 -> V_47 , V_71 ) ;
if ( ! V_9 -> V_15 )
return 0 ;
V_14 = F_82 ( V_9 ) ;
if ( V_14 ) {
F_81 ( & V_9 -> V_47 , V_72 ) ;
F_83 ( & V_9 -> V_47 ) ;
F_80 ( V_68 ) ;
F_84 ( & V_68 -> V_47 ) ;
return V_14 ;
}
return 0 ;
}
void F_85 ( struct V_65 * V_66 )
{
struct V_8 * V_9 = V_66 -> V_69 ;
if ( F_75 ( ! V_9 ) )
return;
if ( V_9 -> V_15 )
F_86 ( V_9 ) ;
F_81 ( & V_9 -> V_47 , V_72 ) ;
F_83 ( & V_9 -> V_47 ) ;
F_80 ( F_74 ( V_66 ) ) ;
F_84 ( & F_74 ( V_66 ) -> V_47 ) ;
}
