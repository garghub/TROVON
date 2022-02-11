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
static T_1 F_51 ( struct V_8 * V_9 , char * V_2 )
{
if ( F_46 ( V_46 , & V_9 -> V_39 ) )
return sprintf ( V_2 , L_3 ) ;
return sprintf ( V_2 , L_4 ) ;
}
static T_1 F_52 ( struct V_8 * V_9 , const char * V_2 ,
T_2 V_3 )
{
int V_37 = - 1 ;
if ( ! strncmp ( V_2 , L_5 , 10 ) )
V_37 = 1 ;
else if ( ! strncmp ( V_2 , L_6 , 13 ) ||
! strncmp ( V_2 , L_7 , 4 ) )
V_37 = 0 ;
if ( V_37 == - 1 )
return - V_7 ;
F_36 ( V_9 -> V_32 ) ;
if ( V_37 )
F_44 ( V_46 , V_9 ) ;
else
F_43 ( V_46 , V_9 ) ;
F_37 ( V_9 -> V_32 ) ;
return V_3 ;
}
static T_1 F_53 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_54 ( V_9 ) , V_2 ) ;
}
static T_1
F_55 ( struct V_47 * V_48 , struct V_49 * V_50 , char * V_2 )
{
struct V_51 * V_52 = F_56 ( V_50 ) ;
struct V_8 * V_9 =
F_57 ( V_48 , struct V_8 , V_48 ) ;
T_1 V_53 ;
if ( ! V_52 -> V_54 )
return - V_55 ;
F_58 ( & V_9 -> V_56 ) ;
if ( F_59 ( V_9 ) ) {
F_60 ( & V_9 -> V_56 ) ;
return - V_57 ;
}
V_53 = V_52 -> V_54 ( V_9 , V_2 ) ;
F_60 ( & V_9 -> V_56 ) ;
return V_53 ;
}
static T_1
F_61 ( struct V_47 * V_48 , struct V_49 * V_50 ,
const char * V_2 , T_2 V_58 )
{
struct V_51 * V_52 = F_56 ( V_50 ) ;
struct V_8 * V_9 ;
T_1 V_53 ;
if ( ! V_52 -> V_59 )
return - V_55 ;
V_9 = F_57 ( V_48 , struct V_8 , V_48 ) ;
F_58 ( & V_9 -> V_56 ) ;
if ( F_59 ( V_9 ) ) {
F_60 ( & V_9 -> V_56 ) ;
return - V_57 ;
}
V_53 = V_52 -> V_59 ( V_9 , V_2 , V_58 ) ;
F_60 ( & V_9 -> V_56 ) ;
return V_53 ;
}
static void F_62 ( struct V_60 * V_60 )
{
struct V_8 * V_9 = F_57 ( V_60 , struct V_8 ,
V_60 ) ;
F_63 ( V_61 , V_9 ) ;
}
static void F_64 ( struct V_47 * V_48 )
{
struct V_8 * V_9 =
F_57 ( V_48 , struct V_8 , V_48 ) ;
F_65 ( & V_9 -> V_17 ) ;
F_66 ( V_9 ) ;
if ( V_9 -> V_62 ) {
F_36 ( V_9 -> V_32 ) ;
F_67 ( V_9 ) ;
F_37 ( V_9 -> V_32 ) ;
F_68 ( V_9 -> V_62 ) ;
}
F_69 ( & V_9 -> V_63 ) ;
if ( V_9 -> V_64 )
F_70 ( V_9 ) ;
if ( ! V_9 -> V_14 )
F_71 ( V_9 -> V_65 ) ;
else
F_72 ( V_9 ) ;
F_73 ( V_9 ) ;
if ( V_9 -> V_66 )
F_74 ( V_9 -> V_66 ) ;
F_75 ( & V_67 , V_9 -> V_68 ) ;
F_76 ( & V_9 -> V_60 , F_62 ) ;
}
int F_77 ( struct V_69 * V_70 )
{
int V_12 ;
struct V_71 * V_72 = F_78 ( V_70 ) ;
struct V_8 * V_9 = V_70 -> V_73 ;
if ( F_79 ( ! V_9 ) )
return - V_74 ;
if ( ! F_80 ( V_9 ) ) {
F_81 ( V_75 , V_9 ) ;
F_82 ( & V_9 -> V_76 ) ;
F_83 ( V_9 ) ;
}
V_12 = F_84 ( V_72 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_85 ( & V_9 -> V_48 , F_86 ( & V_72 -> V_48 ) , L_8 , L_9 ) ;
if ( V_12 < 0 ) {
F_87 ( V_72 ) ;
return V_12 ;
}
F_88 ( & V_9 -> V_48 , V_77 ) ;
if ( V_9 -> V_14 )
F_89 ( V_70 ) ;
if ( ! V_9 -> V_13 )
return 0 ;
V_12 = F_90 ( V_9 ) ;
if ( V_12 ) {
F_88 ( & V_9 -> V_48 , V_78 ) ;
F_91 ( & V_9 -> V_48 ) ;
F_87 ( V_72 ) ;
F_92 ( & V_72 -> V_48 ) ;
return V_12 ;
}
return 0 ;
}
void F_93 ( struct V_69 * V_70 )
{
struct V_8 * V_9 = V_70 -> V_73 ;
if ( F_79 ( ! V_9 ) )
return;
if ( V_9 -> V_14 )
F_94 ( V_70 ) ;
if ( V_9 -> V_13 )
F_95 ( V_9 ) ;
F_88 ( & V_9 -> V_48 , V_78 ) ;
F_91 ( & V_9 -> V_48 ) ;
F_87 ( F_78 ( V_70 ) ) ;
F_92 ( & F_78 ( V_70 ) -> V_48 ) ;
}
