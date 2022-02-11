static T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_6 ;
T_3 V_7 = 128ULL , div = 100000ULL ;
T_1 V_8 ;
if ( ! F_3 () )
return 0 ;
F_4 ( V_5 ) ;
if ( F_5 ( V_2 ) || F_6 ( V_2 ) ) {
V_7 = 1 ;
div = V_5 -> V_9 ;
if ( F_7 ( V_10 ) & V_11 )
V_7 <<= 8 ;
} else if ( F_8 ( V_2 ) ) {
V_7 = 1 ;
div = 1200 ;
}
V_6 = F_7 ( V_3 ) * V_7 ;
V_8 = F_9 ( V_6 , div ) ;
F_10 ( V_5 ) ;
return V_8 ;
}
static T_4
F_11 ( struct V_12 * V_13 , struct V_14 * V_15 , char * V_16 )
{
return snprintf ( V_16 , V_17 , L_1 , F_3 () ) ;
}
static T_4
F_12 ( struct V_12 * V_13 , struct V_14 * V_15 , char * V_16 )
{
struct V_18 * V_19 = F_13 ( V_13 ) ;
T_1 V_20 = F_1 ( V_19 -> V_2 , V_21 ) ;
return snprintf ( V_16 , V_17 , L_2 , V_20 ) ;
}
static T_4
F_14 ( struct V_12 * V_13 , struct V_14 * V_15 , char * V_16 )
{
struct V_18 * V_19 = F_15 ( V_13 ) ;
T_1 V_22 = F_1 ( V_19 -> V_2 , V_23 ) ;
return snprintf ( V_16 , V_17 , L_2 , V_22 ) ;
}
static T_4
F_16 ( struct V_12 * V_13 , struct V_14 * V_15 , char * V_16 )
{
struct V_18 * V_19 = F_15 ( V_13 ) ;
T_1 V_24 = F_1 ( V_19 -> V_2 , V_25 ) ;
return snprintf ( V_16 , V_17 , L_2 , V_24 ) ;
}
static T_4
F_17 ( struct V_12 * V_13 , struct V_14 * V_15 , char * V_16 )
{
struct V_18 * V_19 = F_13 ( V_13 ) ;
T_1 V_20 = F_1 ( V_19 -> V_2 , V_26 ) ;
return snprintf ( V_16 , V_17 , L_2 , V_20 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_5 V_27 )
{
if ( ! F_19 ( V_2 ) )
return - V_28 ;
if ( V_27 % 4 != 0 )
return - V_29 ;
if ( V_27 >= V_30 )
return - V_31 ;
return 0 ;
}
static T_4
F_20 ( struct V_32 * V_33 , struct V_34 * V_35 ,
struct V_36 * V_15 , char * V_16 ,
T_5 V_27 , T_6 V_37 )
{
struct V_12 * V_2 = F_21 ( V_35 ) ;
struct V_18 * V_19 = F_15 ( V_2 ) ;
struct V_1 * V_38 = V_19 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_38 ) ;
int V_39 = ( int ) ( V_40 ) V_15 -> V_41 ;
int V_8 ;
V_37 = F_22 ( V_37 , 4 ) ;
V_8 = F_18 ( V_38 , V_27 ) ;
if ( V_8 )
return V_8 ;
V_37 = F_23 ( T_6 , V_30 - V_27 , V_37 ) ;
V_8 = F_24 ( V_38 ) ;
if ( V_8 )
return V_8 ;
if ( V_5 -> V_42 . V_43 [ V_39 ] )
memcpy ( V_16 ,
V_5 -> V_42 . V_43 [ V_39 ] + ( V_27 / 4 ) ,
V_37 ) ;
else
memset ( V_16 , 0 , V_37 ) ;
F_25 ( & V_38 -> V_44 ) ;
return V_37 ;
}
static T_4
F_26 ( struct V_32 * V_33 , struct V_34 * V_35 ,
struct V_36 * V_15 , char * V_16 ,
T_5 V_27 , T_6 V_37 )
{
struct V_12 * V_2 = F_21 ( V_35 ) ;
struct V_18 * V_19 = F_15 ( V_2 ) ;
struct V_1 * V_38 = V_19 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_38 ) ;
struct V_45 * V_46 ;
T_1 * V_47 = NULL ;
int V_39 = ( int ) ( V_40 ) V_15 -> V_41 ;
int V_8 ;
if ( ! F_27 ( V_38 ) )
return - V_31 ;
V_8 = F_18 ( V_38 , V_27 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_24 ( V_38 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_5 -> V_42 . V_43 [ V_39 ] ) {
V_47 = F_28 ( V_30 , V_48 ) ;
if ( ! V_47 ) {
F_25 ( & V_38 -> V_44 ) ;
return - V_49 ;
}
}
if ( V_47 )
V_5 -> V_42 . V_43 [ V_39 ] = V_47 ;
memcpy ( V_5 -> V_42 . V_43 [ V_39 ] + ( V_27 / 4 ) , V_16 , V_37 ) ;
F_29 (ctx, &dev_priv->context_list, link)
V_46 -> V_50 |= ( 1 << V_39 ) ;
F_25 ( & V_38 -> V_44 ) ;
return V_37 ;
}
static T_4 F_30 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_18 * V_51 = F_15 ( V_13 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_8 ;
F_31 ( & V_5 -> V_52 . V_53 ) ;
F_4 ( V_5 ) ;
F_32 ( & V_5 -> V_52 . V_54 ) ;
if ( F_5 ( V_5 ) || F_6 ( V_5 ) ) {
T_1 V_55 ;
V_55 = F_33 ( V_5 , V_56 ) ;
V_8 = F_34 ( V_5 , ( V_55 >> 8 ) & 0xff ) ;
} else {
T_1 V_57 = F_7 ( V_58 ) ;
if ( F_35 ( V_5 ) )
V_8 = ( V_57 & V_59 ) >> V_60 ;
else if ( F_36 ( V_5 ) || F_37 ( V_5 ) )
V_8 = ( V_57 & V_61 ) >> V_62 ;
else
V_8 = ( V_57 & V_63 ) >> V_64 ;
V_8 = F_34 ( V_5 , V_8 ) ;
}
F_25 ( & V_5 -> V_52 . V_54 ) ;
F_10 ( V_5 ) ;
return snprintf ( V_16 , V_17 , L_3 , V_8 ) ;
}
static T_4 F_38 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_18 * V_51 = F_15 ( V_13 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_8 ;
F_31 ( & V_5 -> V_52 . V_53 ) ;
F_4 ( V_5 ) ;
F_32 ( & V_5 -> V_52 . V_54 ) ;
V_8 = F_34 ( V_5 , V_5 -> V_52 . V_65 ) ;
F_25 ( & V_5 -> V_52 . V_54 ) ;
F_10 ( V_5 ) ;
return snprintf ( V_16 , V_17 , L_3 , V_8 ) ;
}
static T_4 F_39 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_18 * V_51 = F_15 ( V_13 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
return snprintf ( V_16 , V_17 ,
L_3 ,
F_34 ( V_5 , V_5 -> V_52 . V_66 ) ) ;
}
static T_4 F_40 ( struct V_12 * V_13 , struct V_14 * V_15 , char * V_16 )
{
struct V_18 * V_51 = F_15 ( V_13 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_8 ;
F_31 ( & V_5 -> V_52 . V_53 ) ;
F_32 ( & V_5 -> V_52 . V_54 ) ;
V_8 = F_34 ( V_5 , V_5 -> V_52 . V_67 ) ;
F_25 ( & V_5 -> V_52 . V_54 ) ;
return snprintf ( V_16 , V_17 , L_3 , V_8 ) ;
}
static T_4 F_41 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 , T_6 V_37 )
{
struct V_18 * V_51 = F_15 ( V_13 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_68 ;
T_4 V_8 ;
V_8 = F_42 ( V_16 , 0 , & V_68 ) ;
if ( V_8 )
return V_8 ;
F_31 ( & V_5 -> V_52 . V_53 ) ;
F_4 ( V_5 ) ;
F_32 ( & V_5 -> V_52 . V_54 ) ;
V_68 = F_43 ( V_5 , V_68 ) ;
if ( V_68 < V_5 -> V_52 . V_69 ||
V_68 > V_5 -> V_52 . V_70 ||
V_68 < V_5 -> V_52 . V_71 ) {
F_25 ( & V_5 -> V_52 . V_54 ) ;
F_10 ( V_5 ) ;
return - V_29 ;
}
if ( V_68 > V_5 -> V_52 . V_72 )
F_44 ( L_4 ,
F_34 ( V_5 , V_68 ) ) ;
V_5 -> V_52 . V_67 = V_68 ;
V_68 = F_45 ( int , V_5 -> V_52 . V_65 ,
V_5 -> V_52 . V_71 ,
V_5 -> V_52 . V_67 ) ;
F_46 ( V_5 , V_68 ) ;
F_25 ( & V_5 -> V_52 . V_54 ) ;
F_10 ( V_5 ) ;
return V_37 ;
}
static T_4 F_47 ( struct V_12 * V_13 , struct V_14 * V_15 , char * V_16 )
{
struct V_18 * V_51 = F_15 ( V_13 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_8 ;
F_31 ( & V_5 -> V_52 . V_53 ) ;
F_32 ( & V_5 -> V_52 . V_54 ) ;
V_8 = F_34 ( V_5 , V_5 -> V_52 . V_71 ) ;
F_25 ( & V_5 -> V_52 . V_54 ) ;
return snprintf ( V_16 , V_17 , L_3 , V_8 ) ;
}
static T_4 F_48 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 , T_6 V_37 )
{
struct V_18 * V_51 = F_15 ( V_13 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_68 ;
T_4 V_8 ;
V_8 = F_42 ( V_16 , 0 , & V_68 ) ;
if ( V_8 )
return V_8 ;
F_31 ( & V_5 -> V_52 . V_53 ) ;
F_4 ( V_5 ) ;
F_32 ( & V_5 -> V_52 . V_54 ) ;
V_68 = F_43 ( V_5 , V_68 ) ;
if ( V_68 < V_5 -> V_52 . V_69 ||
V_68 > V_5 -> V_52 . V_70 ||
V_68 > V_5 -> V_52 . V_67 ) {
F_25 ( & V_5 -> V_52 . V_54 ) ;
F_10 ( V_5 ) ;
return - V_29 ;
}
V_5 -> V_52 . V_71 = V_68 ;
V_68 = F_45 ( int , V_5 -> V_52 . V_65 ,
V_5 -> V_52 . V_71 ,
V_5 -> V_52 . V_67 ) ;
F_46 ( V_5 , V_68 ) ;
F_25 ( & V_5 -> V_52 . V_54 ) ;
F_10 ( V_5 ) ;
return V_37 ;
}
static T_4 F_49 ( struct V_12 * V_13 , struct V_14 * V_15 , char * V_16 )
{
struct V_18 * V_51 = F_15 ( V_13 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_68 ;
if ( V_15 == & V_73 )
V_68 = F_34 ( V_5 , V_5 -> V_52 . V_72 ) ;
else if ( V_15 == & V_74 )
V_68 = F_34 ( V_5 , V_5 -> V_52 . V_75 ) ;
else if ( V_15 == & V_76 )
V_68 = F_34 ( V_5 , V_5 -> V_52 . V_69 ) ;
else
F_50 () ;
return snprintf ( V_16 , V_17 , L_3 , V_68 ) ;
}
static T_4 F_51 ( struct V_32 * V_33 , struct V_34 * V_35 ,
struct V_36 * V_15 , char * V_16 ,
T_5 V_77 , T_6 V_37 )
{
struct V_12 * V_13 = F_21 ( V_35 ) ;
struct V_18 * V_51 = F_15 ( V_13 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
T_4 V_82 = 0 ;
int V_8 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_8 = F_52 ( & V_81 , F_2 ( V_2 ) , V_37 , V_77 ) ;
if ( V_8 )
return V_8 ;
V_79 . V_2 = V_2 ;
F_53 ( V_2 , & V_79 ) ;
V_8 = F_54 ( & V_81 , & V_79 ) ;
if ( V_8 )
goto V_83;
V_82 = V_37 < V_81 . V_84 ? V_37 : V_81 . V_84 ;
memcpy ( V_16 , V_81 . V_16 , V_82 ) ;
V_83:
F_55 ( & V_79 ) ;
F_56 ( & V_81 ) ;
return V_8 ? : V_82 ;
}
static T_4 F_57 ( struct V_32 * V_32 , struct V_34 * V_35 ,
struct V_36 * V_15 , char * V_16 ,
T_5 V_77 , T_6 V_37 )
{
struct V_12 * V_13 = F_21 ( V_35 ) ;
struct V_18 * V_51 = F_15 ( V_13 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
int V_8 ;
F_58 ( L_5 ) ;
V_8 = F_59 ( & V_2 -> V_44 ) ;
if ( V_8 )
return V_8 ;
F_60 ( V_2 ) ;
F_25 ( & V_2 -> V_44 ) ;
return V_37 ;
}
void F_61 ( struct V_1 * V_2 )
{
int V_8 ;
#ifdef F_62
if ( F_63 ( V_2 ) ) {
V_8 = F_64 ( & V_2 -> V_85 -> V_13 -> V_35 ,
& V_86 ) ;
if ( V_8 )
F_65 ( L_6 ) ;
}
if ( F_66 ( V_2 ) ) {
V_8 = F_64 ( & V_2 -> V_85 -> V_13 -> V_35 ,
& V_87 ) ;
if ( V_8 )
F_65 ( L_7 ) ;
}
if ( F_5 ( V_2 ) || F_6 ( V_2 ) ) {
V_8 = F_64 ( & V_2 -> V_85 -> V_13 -> V_35 ,
& V_88 ) ;
if ( V_8 )
F_65 ( L_8 ) ;
}
#endif
if ( F_19 ( V_2 ) ) {
V_8 = F_67 ( V_2 -> V_85 -> V_13 , & V_89 ) ;
if ( V_8 )
F_65 ( L_9 ) ;
if ( F_68 ( V_2 ) > 1 ) {
V_8 = F_67 ( V_2 -> V_85 -> V_13 ,
& V_90 ) ;
if ( V_8 )
F_65 ( L_10 ) ;
}
}
V_8 = 0 ;
if ( F_5 ( V_2 ) || F_6 ( V_2 ) )
V_8 = F_69 ( & V_2 -> V_85 -> V_13 -> V_35 , V_91 ) ;
else if ( F_70 ( V_2 ) -> V_92 >= 6 )
V_8 = F_69 ( & V_2 -> V_85 -> V_13 -> V_35 , V_93 ) ;
if ( V_8 )
F_65 ( L_11 ) ;
V_8 = F_71 ( & V_2 -> V_85 -> V_13 -> V_35 ,
& V_94 ) ;
if ( V_8 )
F_65 ( L_12 ) ;
}
void F_72 ( struct V_1 * V_2 )
{
F_73 ( & V_2 -> V_85 -> V_13 -> V_35 , & V_94 ) ;
if ( F_5 ( V_2 ) || F_6 ( V_2 ) )
F_74 ( & V_2 -> V_85 -> V_13 -> V_35 , V_91 ) ;
else
F_74 ( & V_2 -> V_85 -> V_13 -> V_35 , V_93 ) ;
F_75 ( V_2 -> V_85 -> V_13 , & V_90 ) ;
F_75 ( V_2 -> V_85 -> V_13 , & V_89 ) ;
#ifdef F_62
F_76 ( & V_2 -> V_85 -> V_13 -> V_35 , & V_86 ) ;
F_76 ( & V_2 -> V_85 -> V_13 -> V_35 , & V_87 ) ;
#endif
}
