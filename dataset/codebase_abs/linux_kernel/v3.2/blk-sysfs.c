static T_1
F_1 ( unsigned long V_1 , char * V_2 )
{
return sprintf ( V_2 , L_1 , V_1 ) ;
}
static T_1
F_2 ( unsigned long * V_1 , const char * V_2 , T_2 V_3 )
{
char * V_4 = ( char * ) V_2 ;
* V_1 = F_3 ( V_4 , & V_4 , 10 ) ;
return V_3 ;
}
static T_1 F_4 ( struct V_5 * V_6 , char * V_2 )
{
return F_1 ( V_6 -> V_7 , ( V_2 ) ) ;
}
static T_1
F_5 ( struct V_5 * V_6 , const char * V_2 , T_2 V_3 )
{
struct V_8 * V_9 = & V_6 -> V_10 ;
unsigned long V_11 ;
int V_12 ;
if ( ! V_6 -> V_13 )
return - V_14 ;
V_12 = F_2 ( & V_11 , V_2 , V_3 ) ;
if ( V_11 < V_15 )
V_11 = V_15 ;
F_6 ( V_6 -> V_16 ) ;
V_6 -> V_7 = V_11 ;
F_7 ( V_6 ) ;
if ( V_9 -> V_3 [ V_17 ] >= F_8 ( V_6 ) )
F_9 ( V_6 , V_17 ) ;
else if ( V_9 -> V_3 [ V_17 ] < F_10 ( V_6 ) )
F_11 ( V_6 , V_17 ) ;
if ( V_9 -> V_3 [ V_18 ] >= F_8 ( V_6 ) )
F_9 ( V_6 , V_18 ) ;
else if ( V_9 -> V_3 [ V_18 ] < F_10 ( V_6 ) )
F_11 ( V_6 , V_18 ) ;
if ( V_9 -> V_3 [ V_17 ] >= V_6 -> V_7 ) {
F_12 ( V_6 , V_17 ) ;
} else {
F_13 ( V_6 , V_17 ) ;
F_14 ( & V_9 -> V_19 [ V_17 ] ) ;
}
if ( V_9 -> V_3 [ V_18 ] >= V_6 -> V_7 ) {
F_12 ( V_6 , V_18 ) ;
} else {
F_13 ( V_6 , V_18 ) ;
F_14 ( & V_9 -> V_19 [ V_18 ] ) ;
}
F_15 ( V_6 -> V_16 ) ;
return V_12 ;
}
static T_1 F_16 ( struct V_5 * V_6 , char * V_2 )
{
unsigned long V_20 = V_6 -> V_21 . V_22 <<
( V_23 - 10 ) ;
return F_1 ( V_20 , ( V_2 ) ) ;
}
static T_1
F_17 ( struct V_5 * V_6 , const char * V_2 , T_2 V_3 )
{
unsigned long V_20 ;
T_1 V_12 = F_2 ( & V_20 , V_2 , V_3 ) ;
V_6 -> V_21 . V_22 = V_20 >> ( V_23 - 10 ) ;
return V_12 ;
}
static T_1 F_18 ( struct V_5 * V_6 , char * V_2 )
{
int V_24 = F_19 ( V_6 ) >> 1 ;
return F_1 ( V_24 , ( V_2 ) ) ;
}
static T_1 F_20 ( struct V_5 * V_6 , char * V_2 )
{
return F_1 ( F_21 ( V_6 ) , ( V_2 ) ) ;
}
static T_1 F_22 ( struct V_5 * V_6 , char * V_2 )
{
return F_1 ( V_6 -> V_25 . V_26 , ( V_2 ) ) ;
}
static T_1 F_23 ( struct V_5 * V_6 , char * V_2 )
{
if ( F_24 ( V_6 ) )
return F_1 ( F_25 ( V_6 ) , ( V_2 ) ) ;
return F_1 ( V_27 , ( V_2 ) ) ;
}
static T_1 F_26 ( struct V_5 * V_6 , char * V_2 )
{
return F_1 ( F_27 ( V_6 ) , V_2 ) ;
}
static T_1 F_28 ( struct V_5 * V_6 , char * V_2 )
{
return F_1 ( F_29 ( V_6 ) , V_2 ) ;
}
static T_1 F_30 ( struct V_5 * V_6 , char * V_2 )
{
return F_1 ( F_31 ( V_6 ) , V_2 ) ;
}
static T_1 F_32 ( struct V_5 * V_6 , char * V_2 )
{
return F_1 ( F_33 ( V_6 ) , V_2 ) ;
}
static T_1 F_34 ( struct V_5 * V_6 , char * V_2 )
{
return F_1 ( V_6 -> V_25 . V_28 , V_2 ) ;
}
static T_1 F_35 ( struct V_5 * V_6 , char * V_2 )
{
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_6 -> V_25 . V_29 << 9 ) ;
}
static T_1 F_36 ( struct V_5 * V_6 , char * V_2 )
{
return F_1 ( F_37 ( V_6 ) , V_2 ) ;
}
static T_1
F_38 ( struct V_5 * V_6 , const char * V_2 , T_2 V_3 )
{
unsigned long V_24 ,
V_30 = F_39 ( V_6 ) >> 1 ,
V_31 = 1 << ( V_23 - 10 ) ;
T_1 V_12 = F_2 ( & V_24 , V_2 , V_3 ) ;
if ( V_24 > V_30 || V_24 < V_31 )
return - V_14 ;
F_6 ( V_6 -> V_16 ) ;
V_6 -> V_25 . V_32 = V_24 << 1 ;
F_15 ( V_6 -> V_16 ) ;
return V_12 ;
}
static T_1 F_40 ( struct V_5 * V_6 , char * V_2 )
{
int V_30 = F_39 ( V_6 ) >> 1 ;
return F_1 ( V_30 , ( V_2 ) ) ;
}
static T_1 F_41 ( struct V_5 * V_6 , char * V_2 )
{
return F_1 ( ( F_42 ( V_6 ) << 1 ) |
F_43 ( V_6 ) , V_2 ) ;
}
static T_1 F_44 ( struct V_5 * V_6 , const char * V_2 ,
T_2 V_3 )
{
unsigned long V_33 ;
T_1 V_12 = F_2 ( & V_33 , V_2 , V_3 ) ;
F_6 ( V_6 -> V_16 ) ;
F_45 ( V_34 , V_6 ) ;
F_45 ( V_35 , V_6 ) ;
if ( V_33 == 2 )
F_46 ( V_34 , V_6 ) ;
else if ( V_33 )
F_46 ( V_35 , V_6 ) ;
F_15 ( V_6 -> V_16 ) ;
return V_12 ;
}
static T_1 F_47 ( struct V_5 * V_6 , char * V_2 )
{
bool V_36 = F_48 ( V_37 , & V_6 -> V_38 ) ;
bool V_39 = F_48 ( V_40 , & V_6 -> V_38 ) ;
return F_1 ( V_36 << V_39 , V_2 ) ;
}
static T_1
F_49 ( struct V_5 * V_6 , const char * V_2 , T_2 V_3 )
{
T_1 V_12 = - V_14 ;
#if F_50 ( V_41 )
unsigned long V_42 ;
V_12 = F_2 ( & V_42 , V_2 , V_3 ) ;
F_6 ( V_6 -> V_16 ) ;
if ( V_42 == 2 ) {
F_46 ( V_37 , V_6 ) ;
F_46 ( V_40 , V_6 ) ;
} else if ( V_42 == 1 ) {
F_46 ( V_37 , V_6 ) ;
F_45 ( V_40 , V_6 ) ;
} else if ( V_42 == 0 ) {
F_45 ( V_37 , V_6 ) ;
F_45 ( V_40 , V_6 ) ;
}
F_15 ( V_6 -> V_16 ) ;
#endif
return V_12 ;
}
static T_1
F_51 ( struct V_43 * V_44 , struct V_45 * V_46 , char * V_2 )
{
struct V_47 * V_48 = F_52 ( V_46 ) ;
struct V_5 * V_6 =
F_53 ( V_44 , struct V_5 , V_44 ) ;
T_1 V_49 ;
if ( ! V_48 -> V_50 )
return - V_51 ;
F_54 ( & V_6 -> V_52 ) ;
if ( F_48 ( V_53 , & V_6 -> V_38 ) ) {
F_55 ( & V_6 -> V_52 ) ;
return - V_54 ;
}
V_49 = V_48 -> V_50 ( V_6 , V_2 ) ;
F_55 ( & V_6 -> V_52 ) ;
return V_49 ;
}
static T_1
F_56 ( struct V_43 * V_44 , struct V_45 * V_46 ,
const char * V_2 , T_2 V_55 )
{
struct V_47 * V_48 = F_52 ( V_46 ) ;
struct V_5 * V_6 ;
T_1 V_49 ;
if ( ! V_48 -> V_56 )
return - V_51 ;
V_6 = F_53 ( V_44 , struct V_5 , V_44 ) ;
F_54 ( & V_6 -> V_52 ) ;
if ( F_48 ( V_53 , & V_6 -> V_38 ) ) {
F_55 ( & V_6 -> V_52 ) ;
return - V_54 ;
}
V_49 = V_48 -> V_56 ( V_6 , V_2 , V_55 ) ;
F_55 ( & V_6 -> V_52 ) ;
return V_49 ;
}
static void F_57 ( struct V_43 * V_44 )
{
struct V_5 * V_6 =
F_53 ( V_44 , struct V_5 , V_44 ) ;
struct V_8 * V_9 = & V_6 -> V_10 ;
F_58 ( V_6 ) ;
if ( V_6 -> V_57 )
F_59 ( V_6 -> V_57 ) ;
F_60 ( V_6 ) ;
if ( V_9 -> V_58 )
F_61 ( V_9 -> V_58 ) ;
if ( V_6 -> V_59 )
F_62 ( V_6 ) ;
F_63 ( V_6 ) ;
F_64 ( V_6 ) ;
F_65 ( & V_6 -> V_21 ) ;
F_66 ( V_60 , V_6 ) ;
}
int F_67 ( struct V_61 * V_62 )
{
int V_12 ;
struct V_63 * V_64 = F_68 ( V_62 ) ;
struct V_5 * V_6 = V_62 -> V_65 ;
if ( F_69 ( ! V_6 ) )
return - V_66 ;
V_12 = F_70 ( V_64 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_71 ( & V_6 -> V_44 , F_72 ( & V_64 -> V_44 ) , L_3 , L_4 ) ;
if ( V_12 < 0 ) {
F_73 ( V_64 ) ;
return V_12 ;
}
F_74 ( & V_6 -> V_44 , V_67 ) ;
if ( ! V_6 -> V_13 )
return 0 ;
V_12 = F_75 ( V_6 ) ;
if ( V_12 ) {
F_74 ( & V_6 -> V_44 , V_68 ) ;
F_76 ( & V_6 -> V_44 ) ;
F_73 ( V_64 ) ;
F_77 ( & V_64 -> V_44 ) ;
return V_12 ;
}
return 0 ;
}
void F_78 ( struct V_61 * V_62 )
{
struct V_5 * V_6 = V_62 -> V_65 ;
if ( F_69 ( ! V_6 ) )
return;
if ( V_6 -> V_13 )
F_79 ( V_6 ) ;
F_74 ( & V_6 -> V_44 , V_68 ) ;
F_76 ( & V_6 -> V_44 ) ;
F_73 ( F_68 ( V_62 ) ) ;
F_77 ( & F_68 ( V_62 ) -> V_44 ) ;
}
