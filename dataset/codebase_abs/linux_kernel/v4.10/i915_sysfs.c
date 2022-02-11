static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 -> V_6 ) ;
}
static T_1 F_4 ( struct V_1 * V_7 ,
T_2 V_8 )
{
T_3 V_9 ;
T_3 V_10 = 128ULL , div = 100000ULL ;
T_1 V_11 ;
if ( ! F_5 () )
return 0 ;
F_6 ( V_7 ) ;
if ( F_7 ( V_7 ) || F_8 ( V_7 ) ) {
V_10 = 1 ;
div = V_7 -> V_12 ;
if ( F_9 ( V_13 ) & V_14 )
V_10 <<= 8 ;
} else if ( F_10 ( V_7 ) ) {
V_10 = 1 ;
div = 1200 ;
}
V_9 = F_9 ( V_8 ) * V_10 ;
V_11 = F_11 ( V_9 , div ) ;
F_12 ( V_7 ) ;
return V_11 ;
}
static T_4
F_13 ( struct V_2 * V_3 , struct V_15 * V_16 , char * V_17 )
{
return snprintf ( V_17 , V_18 , L_1 , F_5 () ) ;
}
static T_4
F_14 ( struct V_2 * V_3 , struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_19 = F_4 ( V_7 , V_20 ) ;
return snprintf ( V_17 , V_18 , L_2 , V_19 ) ;
}
static T_4
F_15 ( struct V_2 * V_3 , struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_21 = F_4 ( V_7 , V_22 ) ;
return snprintf ( V_17 , V_18 , L_2 , V_21 ) ;
}
static T_4
F_16 ( struct V_2 * V_3 , struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_23 = F_4 ( V_7 , V_24 ) ;
return snprintf ( V_17 , V_18 , L_2 , V_23 ) ;
}
static T_4
F_17 ( struct V_2 * V_3 , struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_19 = F_4 ( V_7 , V_25 ) ;
return snprintf ( V_17 , V_18 , L_2 , V_19 ) ;
}
static int F_18 ( struct V_1 * V_7 , T_5 V_26 )
{
if ( ! F_19 ( V_7 ) )
return - V_27 ;
if ( V_26 % 4 != 0 )
return - V_28 ;
if ( V_26 >= V_29 )
return - V_30 ;
return 0 ;
}
static T_4
F_20 ( struct V_31 * V_32 , struct V_33 * V_34 ,
struct V_35 * V_16 , char * V_17 ,
T_5 V_26 , T_6 V_36 )
{
struct V_2 * V_3 = F_21 ( V_34 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_37 * V_6 = & V_7 -> V_38 ;
int V_39 = ( int ) ( V_40 ) V_16 -> V_41 ;
int V_11 ;
V_36 = F_22 ( V_36 , 4 ) ;
V_11 = F_18 ( V_7 , V_26 ) ;
if ( V_11 )
return V_11 ;
V_36 = F_23 ( T_6 , V_29 - V_26 , V_36 ) ;
V_11 = F_24 ( V_6 ) ;
if ( V_11 )
return V_11 ;
if ( V_7 -> V_42 . V_43 [ V_39 ] )
memcpy ( V_17 ,
V_7 -> V_42 . V_43 [ V_39 ] + ( V_26 / 4 ) ,
V_36 ) ;
else
memset ( V_17 , 0 , V_36 ) ;
F_25 ( & V_6 -> V_44 ) ;
return V_36 ;
}
static T_4
F_26 ( struct V_31 * V_32 , struct V_33 * V_34 ,
struct V_35 * V_16 , char * V_17 ,
T_5 V_26 , T_6 V_36 )
{
struct V_2 * V_3 = F_21 ( V_34 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_37 * V_6 = & V_7 -> V_38 ;
struct V_45 * V_46 ;
T_1 * V_47 = NULL ;
int V_39 = ( int ) ( V_40 ) V_16 -> V_41 ;
int V_11 ;
if ( ! F_27 ( V_7 ) )
return - V_30 ;
V_11 = F_18 ( V_7 , V_26 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_24 ( V_6 ) ;
if ( V_11 )
return V_11 ;
if ( ! V_7 -> V_42 . V_43 [ V_39 ] ) {
V_47 = F_28 ( V_29 , V_48 ) ;
if ( ! V_47 ) {
F_25 ( & V_6 -> V_44 ) ;
return - V_49 ;
}
}
if ( V_47 )
V_7 -> V_42 . V_43 [ V_39 ] = V_47 ;
memcpy ( V_7 -> V_42 . V_43 [ V_39 ] + ( V_26 / 4 ) , V_17 , V_36 ) ;
F_29 (ctx, &dev_priv->context_list, link)
V_46 -> V_50 |= ( 1 << V_39 ) ;
F_25 ( & V_6 -> V_44 ) ;
return V_36 ;
}
static T_4 F_30 ( struct V_2 * V_3 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_11 ;
F_6 ( V_7 ) ;
F_31 ( & V_7 -> V_51 . V_52 ) ;
if ( F_7 ( V_7 ) || F_8 ( V_7 ) ) {
T_1 V_53 ;
V_53 = F_32 ( V_7 , V_54 ) ;
V_11 = F_33 ( V_7 , ( V_53 >> 8 ) & 0xff ) ;
} else {
T_1 V_55 = F_9 ( V_56 ) ;
if ( F_34 ( V_7 ) )
V_11 = ( V_55 & V_57 ) >> V_58 ;
else if ( F_35 ( V_7 ) || F_36 ( V_7 ) )
V_11 = ( V_55 & V_59 ) >> V_60 ;
else
V_11 = ( V_55 & V_61 ) >> V_62 ;
V_11 = F_33 ( V_7 , V_11 ) ;
}
F_25 ( & V_7 -> V_51 . V_52 ) ;
F_12 ( V_7 ) ;
return snprintf ( V_17 , V_18 , L_3 , V_11 ) ;
}
static T_4 F_37 ( struct V_2 * V_3 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return snprintf ( V_17 , V_18 , L_3 ,
F_33 ( V_7 ,
V_7 -> V_51 . V_63 ) ) ;
}
static T_4 F_38 ( struct V_2 * V_3 , struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return snprintf ( V_17 , V_18 , L_3 ,
F_33 ( V_7 ,
V_7 -> V_51 . V_64 ) ) ;
}
static T_4 F_39 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
const char * V_17 , T_6 V_36 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_65 ;
T_4 V_11 ;
V_11 = F_40 ( V_17 , 0 , & V_65 ) ;
if ( V_11 )
return V_11 ;
V_65 = F_41 ( V_7 , V_65 ) ;
if ( V_65 < V_7 -> V_51 . V_66 || V_65 > V_7 -> V_51 . V_67 )
return - V_28 ;
F_31 ( & V_7 -> V_51 . V_52 ) ;
V_7 -> V_51 . V_64 = V_65 ;
F_25 ( & V_7 -> V_51 . V_52 ) ;
return V_36 ;
}
static T_4 F_42 ( struct V_2 * V_3 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return snprintf ( V_17 , V_18 , L_3 ,
F_33 ( V_7 ,
V_7 -> V_51 . V_68 ) ) ;
}
static T_4 F_43 ( struct V_2 * V_3 , struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return snprintf ( V_17 , V_18 , L_3 ,
F_33 ( V_7 ,
V_7 -> V_51 . V_69 ) ) ;
}
static T_4 F_44 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
const char * V_17 , T_6 V_36 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_65 ;
T_4 V_11 ;
V_11 = F_40 ( V_17 , 0 , & V_65 ) ;
if ( V_11 )
return V_11 ;
F_6 ( V_7 ) ;
F_31 ( & V_7 -> V_51 . V_52 ) ;
V_65 = F_41 ( V_7 , V_65 ) ;
if ( V_65 < V_7 -> V_51 . V_66 ||
V_65 > V_7 -> V_51 . V_67 ||
V_65 < V_7 -> V_51 . V_70 ) {
F_25 ( & V_7 -> V_51 . V_52 ) ;
F_12 ( V_7 ) ;
return - V_28 ;
}
if ( V_65 > V_7 -> V_51 . V_71 )
F_45 ( L_4 ,
F_33 ( V_7 , V_65 ) ) ;
V_7 -> V_51 . V_69 = V_65 ;
V_65 = F_46 ( int , V_7 -> V_51 . V_63 ,
V_7 -> V_51 . V_70 ,
V_7 -> V_51 . V_69 ) ;
F_47 ( V_7 , V_65 ) ;
F_25 ( & V_7 -> V_51 . V_52 ) ;
F_12 ( V_7 ) ;
return V_36 ;
}
static T_4 F_48 ( struct V_2 * V_3 , struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return snprintf ( V_17 , V_18 , L_3 ,
F_33 ( V_7 ,
V_7 -> V_51 . V_70 ) ) ;
}
static T_4 F_49 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
const char * V_17 , T_6 V_36 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_65 ;
T_4 V_11 ;
V_11 = F_40 ( V_17 , 0 , & V_65 ) ;
if ( V_11 )
return V_11 ;
F_6 ( V_7 ) ;
F_31 ( & V_7 -> V_51 . V_52 ) ;
V_65 = F_41 ( V_7 , V_65 ) ;
if ( V_65 < V_7 -> V_51 . V_66 ||
V_65 > V_7 -> V_51 . V_67 ||
V_65 > V_7 -> V_51 . V_69 ) {
F_25 ( & V_7 -> V_51 . V_52 ) ;
F_12 ( V_7 ) ;
return - V_28 ;
}
V_7 -> V_51 . V_70 = V_65 ;
V_65 = F_46 ( int , V_7 -> V_51 . V_63 ,
V_7 -> V_51 . V_70 ,
V_7 -> V_51 . V_69 ) ;
F_47 ( V_7 , V_65 ) ;
F_25 ( & V_7 -> V_51 . V_52 ) ;
F_12 ( V_7 ) ;
return V_36 ;
}
static T_4 F_50 ( struct V_2 * V_3 , struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_65 ;
if ( V_16 == & V_72 )
V_65 = F_33 ( V_7 , V_7 -> V_51 . V_71 ) ;
else if ( V_16 == & V_73 )
V_65 = F_33 ( V_7 , V_7 -> V_51 . V_74 ) ;
else if ( V_16 == & V_75 )
V_65 = F_33 ( V_7 , V_7 -> V_51 . V_66 ) ;
else
F_51 () ;
return snprintf ( V_17 , V_18 , L_3 , V_65 ) ;
}
static T_4 F_52 ( struct V_31 * V_32 , struct V_33 * V_34 ,
struct V_35 * V_16 , char * V_17 ,
T_5 V_76 , T_6 V_36 )
{
struct V_2 * V_3 = F_21 ( V_34 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_37 * V_6 = & V_7 -> V_38 ;
struct V_77 V_78 ;
struct V_79 V_80 ;
T_4 V_81 = 0 ;
int V_11 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_11 = F_53 ( & V_80 , F_3 ( V_6 ) , V_36 , V_76 ) ;
if ( V_11 )
return V_11 ;
V_78 . V_6 = V_6 ;
F_54 ( V_6 , & V_78 ) ;
V_11 = F_55 ( & V_80 , & V_78 ) ;
if ( V_11 )
goto V_82;
V_81 = V_36 < V_80 . V_83 ? V_36 : V_80 . V_83 ;
memcpy ( V_17 , V_80 . V_17 , V_81 ) ;
V_82:
F_56 ( & V_78 ) ;
F_57 ( & V_80 ) ;
return V_11 ? : V_81 ;
}
static T_4 F_58 ( struct V_31 * V_31 , struct V_33 * V_34 ,
struct V_35 * V_16 , char * V_17 ,
T_5 V_76 , T_6 V_36 )
{
struct V_2 * V_3 = F_21 ( V_34 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_59 ( L_5 ) ;
F_60 ( & V_7 -> V_38 ) ;
return V_36 ;
}
static void F_61 ( struct V_2 * V_3 )
{
if ( F_62 ( & V_3 -> V_34 , & V_84 ) )
F_63 ( L_6 ) ;
}
static void F_64 ( struct V_2 * V_3 )
{
F_65 ( & V_3 -> V_34 , & V_84 ) ;
}
static void F_61 ( struct V_2 * V_3 ) {}
static void F_64 ( struct V_2 * V_3 ) {}
void F_66 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_38 . V_85 -> V_3 ;
int V_11 ;
#ifdef F_67
if ( F_68 ( V_7 ) ) {
V_11 = F_69 ( & V_3 -> V_34 ,
& V_86 ) ;
if ( V_11 )
F_63 ( L_7 ) ;
}
if ( F_70 ( V_7 ) ) {
V_11 = F_69 ( & V_3 -> V_34 ,
& V_87 ) ;
if ( V_11 )
F_63 ( L_8 ) ;
}
if ( F_7 ( V_7 ) || F_8 ( V_7 ) ) {
V_11 = F_69 ( & V_3 -> V_34 ,
& V_88 ) ;
if ( V_11 )
F_63 ( L_9 ) ;
}
#endif
if ( F_19 ( V_7 ) ) {
V_11 = F_71 ( V_3 , & V_89 ) ;
if ( V_11 )
F_63 ( L_10 ) ;
if ( F_72 ( V_7 ) > 1 ) {
V_11 = F_71 ( V_3 ,
& V_90 ) ;
if ( V_11 )
F_63 ( L_11 ) ;
}
}
V_11 = 0 ;
if ( F_7 ( V_7 ) || F_8 ( V_7 ) )
V_11 = F_73 ( & V_3 -> V_34 , V_91 ) ;
else if ( F_74 ( V_7 ) >= 6 )
V_11 = F_73 ( & V_3 -> V_34 , V_92 ) ;
if ( V_11 )
F_63 ( L_12 ) ;
F_61 ( V_3 ) ;
}
void F_75 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_38 . V_85 -> V_3 ;
F_64 ( V_3 ) ;
if ( F_7 ( V_7 ) || F_8 ( V_7 ) )
F_76 ( & V_3 -> V_34 , V_91 ) ;
else
F_76 ( & V_3 -> V_34 , V_92 ) ;
F_77 ( V_3 , & V_90 ) ;
F_77 ( V_3 , & V_89 ) ;
#ifdef F_67
F_78 ( & V_3 -> V_34 , & V_86 ) ;
F_78 ( & V_3 -> V_34 , & V_87 ) ;
#endif
}
