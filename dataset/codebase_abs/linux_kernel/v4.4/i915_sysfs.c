static T_1 F_1 ( struct V_1 * V_2 , const T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_7 ;
T_2 V_8 = 128ULL , div = 100000ULL ;
T_1 V_9 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
F_3 ( V_5 ) ;
if ( F_4 ( V_2 ) ) {
V_8 = 1 ;
div = V_5 -> V_10 ;
if ( F_5 ( V_11 ) & V_12 )
V_8 <<= 8 ;
} else if ( F_6 ( V_2 ) ) {
V_8 = 1 ;
div = 1200 ;
}
V_7 = F_5 ( V_3 ) * V_8 ;
V_9 = F_7 ( V_7 , div ) ;
F_8 ( V_5 ) ;
return V_9 ;
}
static T_3
F_9 ( struct V_13 * V_14 , struct V_15 * V_16 , char * V_17 )
{
struct V_18 * V_19 = F_10 ( V_14 ) ;
return snprintf ( V_17 , V_20 , L_1 , F_2 ( V_19 -> V_2 ) ) ;
}
static T_3
F_11 ( struct V_13 * V_14 , struct V_15 * V_16 , char * V_17 )
{
struct V_18 * V_19 = F_12 ( V_14 ) ;
T_1 V_21 = F_1 ( V_19 -> V_2 , V_22 ) ;
return snprintf ( V_17 , V_20 , L_2 , V_21 ) ;
}
static T_3
F_13 ( struct V_13 * V_14 , struct V_15 * V_16 , char * V_17 )
{
struct V_18 * V_19 = F_10 ( V_14 ) ;
T_1 V_23 = F_1 ( V_19 -> V_2 , V_24 ) ;
return snprintf ( V_17 , V_20 , L_2 , V_23 ) ;
}
static T_3
F_14 ( struct V_13 * V_14 , struct V_15 * V_16 , char * V_17 )
{
struct V_18 * V_19 = F_10 ( V_14 ) ;
T_1 V_25 = F_1 ( V_19 -> V_2 , V_26 ) ;
return snprintf ( V_17 , V_20 , L_2 , V_25 ) ;
}
static T_3
F_15 ( struct V_13 * V_14 , struct V_15 * V_16 , char * V_17 )
{
struct V_18 * V_19 = F_12 ( V_14 ) ;
T_1 V_21 = F_1 ( V_19 -> V_2 , V_27 ) ;
return snprintf ( V_17 , V_20 , L_2 , V_21 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_4 V_28 )
{
if ( ! F_17 ( V_2 ) )
return - V_29 ;
if ( V_28 % 4 != 0 )
return - V_30 ;
if ( V_28 >= V_31 )
return - V_32 ;
return 0 ;
}
static T_3
F_18 ( struct V_33 * V_34 , struct V_35 * V_36 ,
struct V_37 * V_16 , char * V_17 ,
T_4 V_28 , T_5 V_38 )
{
struct V_13 * V_2 = F_19 ( V_36 , struct V_13 , V_36 ) ;
struct V_18 * V_19 = F_10 ( V_2 ) ;
struct V_1 * V_39 = V_19 -> V_2 ;
struct V_4 * V_5 = V_39 -> V_6 ;
int V_40 = ( int ) ( V_41 ) V_16 -> V_42 ;
int V_9 ;
V_38 = F_20 ( V_38 , 4 ) ;
V_9 = F_16 ( V_39 , V_28 ) ;
if ( V_9 )
return V_9 ;
V_38 = F_21 ( T_5 , V_31 - V_28 , V_38 ) ;
V_9 = F_22 ( V_39 ) ;
if ( V_9 )
return V_9 ;
if ( V_5 -> V_43 . V_44 [ V_40 ] )
memcpy ( V_17 ,
V_5 -> V_43 . V_44 [ V_40 ] + ( V_28 / 4 ) ,
V_38 ) ;
else
memset ( V_17 , 0 , V_38 ) ;
F_23 ( & V_39 -> V_45 ) ;
return V_38 ;
}
static T_3
F_24 ( struct V_33 * V_34 , struct V_35 * V_36 ,
struct V_37 * V_16 , char * V_17 ,
T_4 V_28 , T_5 V_38 )
{
struct V_13 * V_2 = F_19 ( V_36 , struct V_13 , V_36 ) ;
struct V_18 * V_19 = F_10 ( V_2 ) ;
struct V_1 * V_39 = V_19 -> V_2 ;
struct V_4 * V_5 = V_39 -> V_6 ;
struct V_46 * V_47 ;
T_1 * V_48 = NULL ;
int V_40 = ( int ) ( V_41 ) V_16 -> V_42 ;
int V_9 ;
if ( ! F_25 ( V_39 ) )
return - V_32 ;
V_9 = F_16 ( V_39 , V_28 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_22 ( V_39 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_5 -> V_43 . V_44 [ V_40 ] ) {
V_48 = F_26 ( V_31 , V_49 ) ;
if ( ! V_48 ) {
F_23 ( & V_39 -> V_45 ) ;
return - V_50 ;
}
}
V_9 = F_27 ( V_39 ) ;
if ( V_9 ) {
F_28 ( V_48 ) ;
F_23 ( & V_39 -> V_45 ) ;
return V_9 ;
}
if ( V_48 )
V_5 -> V_43 . V_44 [ V_40 ] = V_48 ;
memcpy ( V_5 -> V_43 . V_44 [ V_40 ] + ( V_28 / 4 ) , V_17 , V_38 ) ;
F_29 (ctx, &dev_priv->context_list, link)
V_47 -> V_51 |= ( 1 << V_40 ) ;
F_23 ( & V_39 -> V_45 ) ;
return V_38 ;
}
static T_3 F_30 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_18 * V_52 = F_10 ( V_14 ) ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_9 ;
F_31 ( & V_5 -> V_53 . V_54 ) ;
F_3 ( V_5 ) ;
F_32 ( & V_5 -> V_53 . V_55 ) ;
if ( F_4 ( V_5 -> V_2 ) ) {
T_1 V_56 ;
V_56 = F_33 ( V_5 , V_57 ) ;
V_9 = F_34 ( V_5 , ( V_56 >> 8 ) & 0xff ) ;
} else {
T_1 V_58 = F_5 ( V_59 ) ;
if ( F_35 ( V_5 ) )
V_9 = ( V_58 & V_60 ) >> V_61 ;
else if ( F_36 ( V_5 ) || F_37 ( V_5 ) )
V_9 = ( V_58 & V_62 ) >> V_63 ;
else
V_9 = ( V_58 & V_64 ) >> V_65 ;
V_9 = F_34 ( V_5 , V_9 ) ;
}
F_23 ( & V_5 -> V_53 . V_55 ) ;
F_8 ( V_5 ) ;
return snprintf ( V_17 , V_20 , L_3 , V_9 ) ;
}
static T_3 F_38 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_18 * V_52 = F_10 ( V_14 ) ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_9 ;
F_31 ( & V_5 -> V_53 . V_54 ) ;
F_3 ( V_5 ) ;
F_32 ( & V_5 -> V_53 . V_55 ) ;
V_9 = F_34 ( V_5 , V_5 -> V_53 . V_66 ) ;
F_23 ( & V_5 -> V_53 . V_55 ) ;
F_8 ( V_5 ) ;
return snprintf ( V_17 , V_20 , L_3 , V_9 ) ;
}
static T_3 F_39 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_18 * V_52 = F_10 ( V_14 ) ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
return snprintf ( V_17 , V_20 ,
L_3 ,
F_34 ( V_5 , V_5 -> V_53 . V_67 ) ) ;
}
static T_3 F_40 ( struct V_13 * V_14 , struct V_15 * V_16 , char * V_17 )
{
struct V_18 * V_52 = F_10 ( V_14 ) ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_9 ;
F_31 ( & V_5 -> V_53 . V_54 ) ;
F_32 ( & V_5 -> V_53 . V_55 ) ;
V_9 = F_34 ( V_5 , V_5 -> V_53 . V_68 ) ;
F_23 ( & V_5 -> V_53 . V_55 ) ;
return snprintf ( V_17 , V_20 , L_3 , V_9 ) ;
}
static T_3 F_41 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
const char * V_17 , T_5 V_38 )
{
struct V_18 * V_52 = F_10 ( V_14 ) ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_69 ;
T_3 V_9 ;
V_9 = F_42 ( V_17 , 0 , & V_69 ) ;
if ( V_9 )
return V_9 ;
F_31 ( & V_5 -> V_53 . V_54 ) ;
F_32 ( & V_5 -> V_53 . V_55 ) ;
V_69 = F_43 ( V_5 , V_69 ) ;
if ( V_69 < V_5 -> V_53 . V_70 ||
V_69 > V_5 -> V_53 . V_71 ||
V_69 < V_5 -> V_53 . V_72 ) {
F_23 ( & V_5 -> V_53 . V_55 ) ;
return - V_30 ;
}
if ( V_69 > V_5 -> V_53 . V_73 )
F_44 ( L_4 ,
F_34 ( V_5 , V_69 ) ) ;
V_5 -> V_53 . V_68 = V_69 ;
V_69 = F_45 ( int , V_5 -> V_53 . V_66 ,
V_5 -> V_53 . V_72 ,
V_5 -> V_53 . V_68 ) ;
F_46 ( V_2 , V_69 ) ;
F_23 ( & V_5 -> V_53 . V_55 ) ;
return V_38 ;
}
static T_3 F_47 ( struct V_13 * V_14 , struct V_15 * V_16 , char * V_17 )
{
struct V_18 * V_52 = F_10 ( V_14 ) ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_9 ;
F_31 ( & V_5 -> V_53 . V_54 ) ;
F_32 ( & V_5 -> V_53 . V_55 ) ;
V_9 = F_34 ( V_5 , V_5 -> V_53 . V_72 ) ;
F_23 ( & V_5 -> V_53 . V_55 ) ;
return snprintf ( V_17 , V_20 , L_3 , V_9 ) ;
}
static T_3 F_48 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
const char * V_17 , T_5 V_38 )
{
struct V_18 * V_52 = F_10 ( V_14 ) ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_69 ;
T_3 V_9 ;
V_9 = F_42 ( V_17 , 0 , & V_69 ) ;
if ( V_9 )
return V_9 ;
F_31 ( & V_5 -> V_53 . V_54 ) ;
F_32 ( & V_5 -> V_53 . V_55 ) ;
V_69 = F_43 ( V_5 , V_69 ) ;
if ( V_69 < V_5 -> V_53 . V_70 ||
V_69 > V_5 -> V_53 . V_71 ||
V_69 > V_5 -> V_53 . V_68 ) {
F_23 ( & V_5 -> V_53 . V_55 ) ;
return - V_30 ;
}
V_5 -> V_53 . V_72 = V_69 ;
V_69 = F_45 ( int , V_5 -> V_53 . V_66 ,
V_5 -> V_53 . V_72 ,
V_5 -> V_53 . V_68 ) ;
F_46 ( V_2 , V_69 ) ;
F_23 ( & V_5 -> V_53 . V_55 ) ;
return V_38 ;
}
static T_3 F_49 ( struct V_13 * V_14 , struct V_15 * V_16 , char * V_17 )
{
struct V_18 * V_52 = F_10 ( V_14 ) ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_69 ;
if ( V_16 == & V_74 )
V_69 = F_34 ( V_5 , V_5 -> V_53 . V_73 ) ;
else if ( V_16 == & V_75 )
V_69 = F_34 ( V_5 , V_5 -> V_53 . V_76 ) ;
else if ( V_16 == & V_77 )
V_69 = F_34 ( V_5 , V_5 -> V_53 . V_70 ) ;
else
F_50 () ;
return snprintf ( V_17 , V_20 , L_3 , V_69 ) ;
}
static T_3 F_51 ( struct V_33 * V_34 , struct V_35 * V_36 ,
struct V_37 * V_16 , char * V_17 ,
T_4 V_78 , T_5 V_38 )
{
struct V_13 * V_14 = F_19 ( V_36 , struct V_13 , V_36 ) ;
struct V_18 * V_52 = F_10 ( V_14 ) ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_79 V_80 ;
struct V_81 V_82 ;
T_3 V_83 = 0 ;
int V_9 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_9 = F_52 ( & V_82 , F_53 ( V_2 ) , V_38 , V_78 ) ;
if ( V_9 )
return V_9 ;
V_80 . V_2 = V_2 ;
F_54 ( V_2 , & V_80 ) ;
V_9 = F_55 ( & V_82 , & V_80 ) ;
if ( V_9 )
goto V_84;
V_83 = V_38 < V_82 . V_85 ? V_38 : V_82 . V_85 ;
memcpy ( V_17 , V_82 . V_17 , V_83 ) ;
V_84:
F_56 ( & V_80 ) ;
F_57 ( & V_82 ) ;
return V_9 ? : V_83 ;
}
static T_3 F_58 ( struct V_33 * V_33 , struct V_35 * V_36 ,
struct V_37 * V_16 , char * V_17 ,
T_4 V_78 , T_5 V_38 )
{
struct V_13 * V_14 = F_19 ( V_36 , struct V_13 , V_36 ) ;
struct V_18 * V_52 = F_10 ( V_14 ) ;
struct V_1 * V_2 = V_52 -> V_2 ;
int V_9 ;
F_59 ( L_5 ) ;
V_9 = F_60 ( & V_2 -> V_45 ) ;
if ( V_9 )
return V_9 ;
F_61 ( V_2 ) ;
F_23 ( & V_2 -> V_45 ) ;
return V_38 ;
}
void F_62 ( struct V_1 * V_2 )
{
int V_9 ;
#ifdef F_63
if ( F_64 ( V_2 ) ) {
V_9 = F_65 ( & V_2 -> V_86 -> V_14 -> V_36 ,
& V_87 ) ;
if ( V_9 )
F_66 ( L_6 ) ;
}
if ( F_67 ( V_2 ) ) {
V_9 = F_65 ( & V_2 -> V_86 -> V_14 -> V_36 ,
& V_88 ) ;
if ( V_9 )
F_66 ( L_7 ) ;
}
if ( F_4 ( V_2 ) ) {
V_9 = F_65 ( & V_2 -> V_86 -> V_14 -> V_36 ,
& V_89 ) ;
if ( V_9 )
F_66 ( L_8 ) ;
}
#endif
if ( F_17 ( V_2 ) ) {
V_9 = F_68 ( V_2 -> V_86 -> V_14 , & V_90 ) ;
if ( V_9 )
F_66 ( L_9 ) ;
if ( F_69 ( V_2 ) > 1 ) {
V_9 = F_68 ( V_2 -> V_86 -> V_14 ,
& V_91 ) ;
if ( V_9 )
F_66 ( L_10 ) ;
}
}
V_9 = 0 ;
if ( F_4 ( V_2 ) )
V_9 = F_70 ( & V_2 -> V_86 -> V_14 -> V_36 , V_92 ) ;
else if ( F_71 ( V_2 ) -> V_93 >= 6 )
V_9 = F_70 ( & V_2 -> V_86 -> V_14 -> V_36 , V_94 ) ;
if ( V_9 )
F_66 ( L_11 ) ;
V_9 = F_72 ( & V_2 -> V_86 -> V_14 -> V_36 ,
& V_95 ) ;
if ( V_9 )
F_66 ( L_12 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
F_74 ( & V_2 -> V_86 -> V_14 -> V_36 , & V_95 ) ;
if ( F_4 ( V_2 ) )
F_75 ( & V_2 -> V_86 -> V_14 -> V_36 , V_92 ) ;
else
F_75 ( & V_2 -> V_86 -> V_14 -> V_36 , V_94 ) ;
F_76 ( V_2 -> V_86 -> V_14 , & V_91 ) ;
F_76 ( V_2 -> V_86 -> V_14 , & V_90 ) ;
#ifdef F_63
F_77 ( & V_2 -> V_86 -> V_14 -> V_36 , & V_87 ) ;
F_77 ( & V_2 -> V_86 -> V_14 -> V_36 , & V_88 ) ;
#endif
}
