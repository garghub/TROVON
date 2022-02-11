static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 -> V_6 ) ;
}
static T_1 F_4 ( struct V_1 * V_7 ,
T_2 V_8 )
{
return F_5 ( F_6 ( V_7 , V_8 ) ,
1000 ) ;
}
static T_3
F_7 ( struct V_2 * V_3 , struct V_9 * V_10 , char * V_11 )
{
return snprintf ( V_11 , V_12 , L_1 , F_8 () ) ;
}
static T_3
F_9 ( struct V_2 * V_3 , struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_13 = F_4 ( V_7 , V_14 ) ;
return snprintf ( V_11 , V_12 , L_2 , V_13 ) ;
}
static T_3
F_10 ( struct V_2 * V_3 , struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_15 = F_4 ( V_7 , V_16 ) ;
return snprintf ( V_11 , V_12 , L_2 , V_15 ) ;
}
static T_3
F_11 ( struct V_2 * V_3 , struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_17 = F_4 ( V_7 , V_18 ) ;
return snprintf ( V_11 , V_12 , L_2 , V_17 ) ;
}
static T_3
F_12 ( struct V_2 * V_3 , struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_13 = F_4 ( V_7 , V_19 ) ;
return snprintf ( V_11 , V_12 , L_2 , V_13 ) ;
}
static int F_13 ( struct V_1 * V_7 , T_4 V_20 )
{
if ( ! F_14 ( V_7 ) )
return - V_21 ;
if ( V_20 % 4 != 0 )
return - V_22 ;
if ( V_20 >= V_23 )
return - V_24 ;
return 0 ;
}
static T_3
F_15 ( struct V_25 * V_26 , struct V_27 * V_28 ,
struct V_29 * V_10 , char * V_11 ,
T_4 V_20 , T_5 V_30 )
{
struct V_2 * V_3 = F_16 ( V_28 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_31 * V_6 = & V_7 -> V_32 ;
int V_33 = ( int ) ( V_34 ) V_10 -> V_35 ;
int V_36 ;
V_30 = F_17 ( V_30 , 4 ) ;
V_36 = F_13 ( V_7 , V_20 ) ;
if ( V_36 )
return V_36 ;
V_30 = F_18 ( T_5 , V_23 - V_20 , V_30 ) ;
V_36 = F_19 ( V_6 ) ;
if ( V_36 )
return V_36 ;
if ( V_7 -> V_37 . V_38 [ V_33 ] )
memcpy ( V_11 ,
V_7 -> V_37 . V_38 [ V_33 ] + ( V_20 / 4 ) ,
V_30 ) ;
else
memset ( V_11 , 0 , V_30 ) ;
F_20 ( & V_6 -> V_39 ) ;
return V_30 ;
}
static T_3
F_21 ( struct V_25 * V_26 , struct V_27 * V_28 ,
struct V_29 * V_10 , char * V_11 ,
T_4 V_20 , T_5 V_30 )
{
struct V_2 * V_3 = F_16 ( V_28 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_31 * V_6 = & V_7 -> V_32 ;
struct V_40 * V_41 ;
int V_33 = ( int ) ( V_34 ) V_10 -> V_35 ;
T_1 * * V_38 ;
int V_36 ;
V_36 = F_13 ( V_7 , V_20 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_19 ( V_6 ) ;
if ( V_36 )
return V_36 ;
V_38 = & V_7 -> V_37 . V_38 [ V_33 ] ;
if ( ! * V_38 ) {
* V_38 = F_22 ( V_23 , V_42 ) ;
if ( ! * V_38 ) {
V_36 = - V_43 ;
goto V_44;
}
}
memcpy ( * V_38 + ( V_20 / 4 ) , V_11 , V_30 ) ;
F_23 (ctx, &dev_priv->contexts.list, link)
V_41 -> V_45 |= ( 1 << V_33 ) ;
V_36 = V_30 ;
V_44:
F_20 ( & V_6 -> V_39 ) ;
return V_36 ;
}
static T_3 F_24 ( struct V_2 * V_3 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_36 ;
F_25 ( V_7 ) ;
F_26 ( & V_7 -> V_46 . V_47 ) ;
if ( F_27 ( V_7 ) || F_28 ( V_7 ) ) {
T_1 V_48 ;
V_48 = F_29 ( V_7 , V_49 ) ;
V_36 = F_30 ( V_7 , ( V_48 >> 8 ) & 0xff ) ;
} else {
T_1 V_50 = F_31 ( V_51 ) ;
if ( F_32 ( V_7 ) >= 9 )
V_36 = ( V_50 & V_52 ) >> V_53 ;
else if ( F_33 ( V_7 ) || F_34 ( V_7 ) )
V_36 = ( V_50 & V_54 ) >> V_55 ;
else
V_36 = ( V_50 & V_56 ) >> V_57 ;
V_36 = F_30 ( V_7 , V_36 ) ;
}
F_20 ( & V_7 -> V_46 . V_47 ) ;
F_35 ( V_7 ) ;
return snprintf ( V_11 , V_12 , L_3 , V_36 ) ;
}
static T_3 F_36 ( struct V_2 * V_3 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return snprintf ( V_11 , V_12 , L_3 ,
F_30 ( V_7 ,
V_7 -> V_46 . V_58 ) ) ;
}
static T_3 F_37 ( struct V_2 * V_3 , struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return snprintf ( V_11 , V_12 , L_3 ,
F_30 ( V_7 ,
V_7 -> V_46 . V_59 ) ) ;
}
static T_3 F_38 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
const char * V_11 , T_5 V_30 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_60 ;
T_3 V_36 ;
V_36 = F_39 ( V_11 , 0 , & V_60 ) ;
if ( V_36 )
return V_36 ;
V_60 = F_40 ( V_7 , V_60 ) ;
if ( V_60 < V_7 -> V_46 . V_61 || V_60 > V_7 -> V_46 . V_62 )
return - V_22 ;
F_26 ( & V_7 -> V_46 . V_47 ) ;
V_7 -> V_46 . V_59 = V_60 ;
F_20 ( & V_7 -> V_46 . V_47 ) ;
return V_30 ;
}
static T_3 F_41 ( struct V_2 * V_3 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return snprintf ( V_11 , V_12 , L_3 ,
F_30 ( V_7 ,
V_7 -> V_46 . V_63 ) ) ;
}
static T_3 F_42 ( struct V_2 * V_3 , struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return snprintf ( V_11 , V_12 , L_3 ,
F_30 ( V_7 ,
V_7 -> V_46 . V_64 ) ) ;
}
static T_3 F_43 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
const char * V_11 , T_5 V_30 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_60 ;
T_3 V_36 ;
V_36 = F_39 ( V_11 , 0 , & V_60 ) ;
if ( V_36 )
return V_36 ;
F_25 ( V_7 ) ;
F_26 ( & V_7 -> V_46 . V_47 ) ;
V_60 = F_40 ( V_7 , V_60 ) ;
if ( V_60 < V_7 -> V_46 . V_61 ||
V_60 > V_7 -> V_46 . V_62 ||
V_60 < V_7 -> V_46 . V_65 ) {
F_20 ( & V_7 -> V_46 . V_47 ) ;
F_35 ( V_7 ) ;
return - V_22 ;
}
if ( V_60 > V_7 -> V_46 . V_66 )
F_44 ( L_4 ,
F_30 ( V_7 , V_60 ) ) ;
V_7 -> V_46 . V_64 = V_60 ;
V_60 = F_45 ( int , V_7 -> V_46 . V_58 ,
V_7 -> V_46 . V_65 ,
V_7 -> V_46 . V_64 ) ;
V_36 = F_46 ( V_7 , V_60 ) ;
F_20 ( & V_7 -> V_46 . V_47 ) ;
F_35 ( V_7 ) ;
return V_36 ? : V_30 ;
}
static T_3 F_47 ( struct V_2 * V_3 , struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return snprintf ( V_11 , V_12 , L_3 ,
F_30 ( V_7 ,
V_7 -> V_46 . V_65 ) ) ;
}
static T_3 F_48 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
const char * V_11 , T_5 V_30 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_60 ;
T_3 V_36 ;
V_36 = F_39 ( V_11 , 0 , & V_60 ) ;
if ( V_36 )
return V_36 ;
F_25 ( V_7 ) ;
F_26 ( & V_7 -> V_46 . V_47 ) ;
V_60 = F_40 ( V_7 , V_60 ) ;
if ( V_60 < V_7 -> V_46 . V_61 ||
V_60 > V_7 -> V_46 . V_62 ||
V_60 > V_7 -> V_46 . V_64 ) {
F_20 ( & V_7 -> V_46 . V_47 ) ;
F_35 ( V_7 ) ;
return - V_22 ;
}
V_7 -> V_46 . V_65 = V_60 ;
V_60 = F_45 ( int , V_7 -> V_46 . V_58 ,
V_7 -> V_46 . V_65 ,
V_7 -> V_46 . V_64 ) ;
V_36 = F_46 ( V_7 , V_60 ) ;
F_20 ( & V_7 -> V_46 . V_47 ) ;
F_35 ( V_7 ) ;
return V_36 ? : V_30 ;
}
static T_3 F_49 ( struct V_2 * V_3 , struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_60 ;
if ( V_10 == & V_67 )
V_60 = F_30 ( V_7 , V_7 -> V_46 . V_66 ) ;
else if ( V_10 == & V_68 )
V_60 = F_30 ( V_7 , V_7 -> V_46 . V_69 ) ;
else if ( V_10 == & V_70 )
V_60 = F_30 ( V_7 , V_7 -> V_46 . V_61 ) ;
else
F_50 () ;
return snprintf ( V_11 , V_12 , L_3 , V_60 ) ;
}
static T_3 F_51 ( struct V_25 * V_26 , struct V_27 * V_28 ,
struct V_29 * V_10 , char * V_11 ,
T_4 V_71 , T_5 V_30 )
{
struct V_2 * V_3 = F_16 ( V_28 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_72 V_73 ;
struct V_74 * V_75 ;
T_3 V_36 ;
V_36 = F_52 ( & V_73 , V_7 , V_30 , V_71 ) ;
if ( V_36 )
return V_36 ;
V_75 = F_53 ( V_7 ) ;
V_36 = F_54 ( & V_73 , V_75 ) ;
if ( V_36 )
goto V_44;
V_36 = V_30 < V_73 . V_76 ? V_30 : V_73 . V_76 ;
memcpy ( V_11 , V_73 . V_11 , V_36 ) ;
V_44:
F_55 ( V_75 ) ;
F_56 ( & V_73 ) ;
return V_36 ;
}
static T_3 F_57 ( struct V_25 * V_25 , struct V_27 * V_28 ,
struct V_29 * V_10 , char * V_11 ,
T_4 V_71 , T_5 V_30 )
{
struct V_2 * V_3 = F_16 ( V_28 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_58 ( L_5 ) ;
F_59 ( V_7 ) ;
return V_30 ;
}
static void F_60 ( struct V_2 * V_3 )
{
if ( F_61 ( & V_3 -> V_28 , & V_77 ) )
F_62 ( L_6 ) ;
}
static void F_63 ( struct V_2 * V_3 )
{
F_64 ( & V_3 -> V_28 , & V_77 ) ;
}
static void F_60 ( struct V_2 * V_3 ) {}
static void F_63 ( struct V_2 * V_3 ) {}
void F_65 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_32 . V_78 -> V_3 ;
int V_36 ;
#ifdef F_66
if ( F_67 ( V_7 ) ) {
V_36 = F_68 ( & V_3 -> V_28 ,
& V_79 ) ;
if ( V_36 )
F_62 ( L_7 ) ;
}
if ( F_69 ( V_7 ) ) {
V_36 = F_68 ( & V_3 -> V_28 ,
& V_80 ) ;
if ( V_36 )
F_62 ( L_8 ) ;
}
if ( F_27 ( V_7 ) || F_28 ( V_7 ) ) {
V_36 = F_68 ( & V_3 -> V_28 ,
& V_81 ) ;
if ( V_36 )
F_62 ( L_9 ) ;
}
#endif
if ( F_14 ( V_7 ) ) {
V_36 = F_70 ( V_3 , & V_82 ) ;
if ( V_36 )
F_62 ( L_10 ) ;
if ( F_71 ( V_7 ) > 1 ) {
V_36 = F_70 ( V_3 ,
& V_83 ) ;
if ( V_36 )
F_62 ( L_11 ) ;
}
}
V_36 = 0 ;
if ( F_27 ( V_7 ) || F_28 ( V_7 ) )
V_36 = F_72 ( & V_3 -> V_28 , V_84 ) ;
else if ( F_32 ( V_7 ) >= 6 )
V_36 = F_72 ( & V_3 -> V_28 , V_85 ) ;
if ( V_36 )
F_62 ( L_12 ) ;
F_60 ( V_3 ) ;
}
void F_73 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_32 . V_78 -> V_3 ;
F_63 ( V_3 ) ;
if ( F_27 ( V_7 ) || F_28 ( V_7 ) )
F_74 ( & V_3 -> V_28 , V_84 ) ;
else
F_74 ( & V_3 -> V_28 , V_85 ) ;
F_75 ( V_3 , & V_83 ) ;
F_75 ( V_3 , & V_82 ) ;
#ifdef F_66
F_76 ( & V_3 -> V_28 , & V_79 ) ;
F_76 ( & V_3 -> V_28 , & V_80 ) ;
#endif
}
