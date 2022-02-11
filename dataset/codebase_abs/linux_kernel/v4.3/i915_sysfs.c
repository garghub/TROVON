static T_1 F_1 ( struct V_1 * V_2 , const T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_7 ;
T_2 V_8 = 128ULL , div = 100000ULL , V_9 = 100ULL ;
T_1 V_10 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
F_3 ( V_5 ) ;
if ( F_4 ( V_2 ) ) {
T_1 V_11 , V_12 ;
if ( F_5 ( V_2 ) )
V_11 = V_13 ;
else
V_11 = V_14 ;
V_12 = F_6 ( V_11 ) >> V_15 ;
if ( ! V_12 ) {
F_7 ( ! V_12 , L_1 ) ;
V_10 = 0 ;
goto V_16;
}
if ( F_5 ( V_2 ) && V_12 == 1 ) {
div = 10000000ULL ;
V_8 = 3125ULL ;
} else {
V_12 += 1 ;
div = 1000000ULL ;
V_8 = F_8 ( 30ULL * V_9 , V_12 ) ;
}
if ( F_6 ( V_17 ) & V_18 )
V_8 <<= 8 ;
div = div * V_9 ;
}
V_7 = F_6 ( V_3 ) * V_8 ;
V_10 = F_8 ( V_7 , div ) ;
V_16:
F_9 ( V_5 ) ;
return V_10 ;
}
static T_3
F_10 ( struct V_19 * V_20 , struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
return snprintf ( V_23 , V_26 , L_2 , F_2 ( V_25 -> V_2 ) ) ;
}
static T_3
F_12 ( struct V_19 * V_20 , struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_25 = F_13 ( V_20 ) ;
T_1 V_27 = F_1 ( V_25 -> V_2 , V_28 ) ;
return snprintf ( V_23 , V_26 , L_3 , V_27 ) ;
}
static T_3
F_14 ( struct V_19 * V_20 , struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
T_1 V_29 = F_1 ( V_25 -> V_2 , V_30 ) ;
return snprintf ( V_23 , V_26 , L_3 , V_29 ) ;
}
static T_3
F_15 ( struct V_19 * V_20 , struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
T_1 V_31 = F_1 ( V_25 -> V_2 , V_32 ) ;
return snprintf ( V_23 , V_26 , L_3 , V_31 ) ;
}
static T_3
F_16 ( struct V_19 * V_20 , struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_25 = F_13 ( V_20 ) ;
T_1 V_27 = F_1 ( V_25 -> V_2 , V_33 ) ;
return snprintf ( V_23 , V_26 , L_3 , V_27 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_4 V_34 )
{
if ( ! F_18 ( V_2 ) )
return - V_35 ;
if ( V_34 % 4 != 0 )
return - V_36 ;
if ( V_34 >= V_37 )
return - V_38 ;
return 0 ;
}
static T_3
F_19 ( struct V_39 * V_40 , struct V_41 * V_42 ,
struct V_43 * V_22 , char * V_23 ,
T_4 V_34 , T_5 V_44 )
{
struct V_19 * V_2 = F_20 ( V_42 , struct V_19 , V_42 ) ;
struct V_24 * V_25 = F_11 ( V_2 ) ;
struct V_1 * V_45 = V_25 -> V_2 ;
struct V_4 * V_5 = V_45 -> V_6 ;
int V_46 = ( int ) ( V_47 ) V_22 -> V_48 ;
int V_10 ;
V_44 = F_21 ( V_44 , 4 ) ;
V_10 = F_17 ( V_45 , V_34 ) ;
if ( V_10 )
return V_10 ;
V_44 = F_22 ( T_5 , V_37 - V_34 , V_44 ) ;
V_10 = F_23 ( V_45 ) ;
if ( V_10 )
return V_10 ;
if ( V_5 -> V_49 . V_50 [ V_46 ] )
memcpy ( V_23 ,
V_5 -> V_49 . V_50 [ V_46 ] + ( V_34 / 4 ) ,
V_44 ) ;
else
memset ( V_23 , 0 , V_44 ) ;
F_24 ( & V_45 -> V_51 ) ;
return V_44 ;
}
static T_3
F_25 ( struct V_39 * V_40 , struct V_41 * V_42 ,
struct V_43 * V_22 , char * V_23 ,
T_4 V_34 , T_5 V_44 )
{
struct V_19 * V_2 = F_20 ( V_42 , struct V_19 , V_42 ) ;
struct V_24 * V_25 = F_11 ( V_2 ) ;
struct V_1 * V_45 = V_25 -> V_2 ;
struct V_4 * V_5 = V_45 -> V_6 ;
struct V_52 * V_53 ;
T_1 * V_54 = NULL ;
int V_46 = ( int ) ( V_47 ) V_22 -> V_48 ;
int V_10 ;
if ( ! F_26 ( V_45 ) )
return - V_38 ;
V_10 = F_17 ( V_45 , V_34 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_23 ( V_45 ) ;
if ( V_10 )
return V_10 ;
if ( ! V_5 -> V_49 . V_50 [ V_46 ] ) {
V_54 = F_27 ( V_37 , V_55 ) ;
if ( ! V_54 ) {
F_24 ( & V_45 -> V_51 ) ;
return - V_56 ;
}
}
V_10 = F_28 ( V_45 ) ;
if ( V_10 ) {
F_29 ( V_54 ) ;
F_24 ( & V_45 -> V_51 ) ;
return V_10 ;
}
if ( V_54 )
V_5 -> V_49 . V_50 [ V_46 ] = V_54 ;
memcpy ( V_5 -> V_49 . V_50 [ V_46 ] + ( V_34 / 4 ) , V_23 , V_44 ) ;
F_30 (ctx, &dev_priv->context_list, link)
V_53 -> V_57 |= ( 1 << V_46 ) ;
F_24 ( & V_45 -> V_51 ) ;
return V_44 ;
}
static T_3 F_31 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_58 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 ;
F_32 ( & V_5 -> V_59 . V_60 ) ;
F_3 ( V_5 ) ;
F_33 ( & V_5 -> V_59 . V_61 ) ;
if ( F_4 ( V_5 -> V_2 ) ) {
T_1 V_62 ;
V_62 = F_34 ( V_5 , V_63 ) ;
V_10 = F_35 ( V_5 , ( V_62 >> 8 ) & 0xff ) ;
} else {
T_1 V_64 = F_6 ( V_65 ) ;
if ( F_36 ( V_5 ) )
V_10 = ( V_64 & V_66 ) >> V_67 ;
else if ( F_37 ( V_5 ) || F_38 ( V_5 ) )
V_10 = ( V_64 & V_68 ) >> V_69 ;
else
V_10 = ( V_64 & V_70 ) >> V_71 ;
V_10 = F_35 ( V_5 , V_10 ) ;
}
F_24 ( & V_5 -> V_59 . V_61 ) ;
F_9 ( V_5 ) ;
return snprintf ( V_23 , V_26 , L_4 , V_10 ) ;
}
static T_3 F_39 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_58 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 ;
F_32 ( & V_5 -> V_59 . V_60 ) ;
F_3 ( V_5 ) ;
F_33 ( & V_5 -> V_59 . V_61 ) ;
V_10 = F_35 ( V_5 , V_5 -> V_59 . V_72 ) ;
F_24 ( & V_5 -> V_59 . V_61 ) ;
F_9 ( V_5 ) ;
return snprintf ( V_23 , V_26 , L_4 , V_10 ) ;
}
static T_3 F_40 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_58 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
return snprintf ( V_23 , V_26 ,
L_4 ,
F_35 ( V_5 , V_5 -> V_59 . V_73 ) ) ;
}
static T_3 F_41 ( struct V_19 * V_20 , struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_58 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 ;
F_32 ( & V_5 -> V_59 . V_60 ) ;
F_33 ( & V_5 -> V_59 . V_61 ) ;
V_10 = F_35 ( V_5 , V_5 -> V_59 . V_74 ) ;
F_24 ( & V_5 -> V_59 . V_61 ) ;
return snprintf ( V_23 , V_26 , L_4 , V_10 ) ;
}
static T_3 F_42 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
const char * V_23 , T_5 V_44 )
{
struct V_24 * V_58 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_75 ;
T_3 V_10 ;
V_10 = F_43 ( V_23 , 0 , & V_75 ) ;
if ( V_10 )
return V_10 ;
F_32 ( & V_5 -> V_59 . V_60 ) ;
F_33 ( & V_5 -> V_59 . V_61 ) ;
V_75 = F_44 ( V_5 , V_75 ) ;
if ( V_75 < V_5 -> V_59 . V_76 ||
V_75 > V_5 -> V_59 . V_77 ||
V_75 < V_5 -> V_59 . V_78 ) {
F_24 ( & V_5 -> V_59 . V_61 ) ;
return - V_36 ;
}
if ( V_75 > V_5 -> V_59 . V_79 )
F_45 ( L_5 ,
F_35 ( V_5 , V_75 ) ) ;
V_5 -> V_59 . V_74 = V_75 ;
V_75 = F_46 ( int , V_5 -> V_59 . V_72 ,
V_5 -> V_59 . V_78 ,
V_5 -> V_59 . V_74 ) ;
F_47 ( V_2 , V_75 ) ;
F_24 ( & V_5 -> V_59 . V_61 ) ;
return V_44 ;
}
static T_3 F_48 ( struct V_19 * V_20 , struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_58 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 ;
F_32 ( & V_5 -> V_59 . V_60 ) ;
F_33 ( & V_5 -> V_59 . V_61 ) ;
V_10 = F_35 ( V_5 , V_5 -> V_59 . V_78 ) ;
F_24 ( & V_5 -> V_59 . V_61 ) ;
return snprintf ( V_23 , V_26 , L_4 , V_10 ) ;
}
static T_3 F_49 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
const char * V_23 , T_5 V_44 )
{
struct V_24 * V_58 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_75 ;
T_3 V_10 ;
V_10 = F_43 ( V_23 , 0 , & V_75 ) ;
if ( V_10 )
return V_10 ;
F_32 ( & V_5 -> V_59 . V_60 ) ;
F_33 ( & V_5 -> V_59 . V_61 ) ;
V_75 = F_44 ( V_5 , V_75 ) ;
if ( V_75 < V_5 -> V_59 . V_76 ||
V_75 > V_5 -> V_59 . V_77 ||
V_75 > V_5 -> V_59 . V_74 ) {
F_24 ( & V_5 -> V_59 . V_61 ) ;
return - V_36 ;
}
V_5 -> V_59 . V_78 = V_75 ;
V_75 = F_46 ( int , V_5 -> V_59 . V_72 ,
V_5 -> V_59 . V_78 ,
V_5 -> V_59 . V_74 ) ;
F_47 ( V_2 , V_75 ) ;
F_24 ( & V_5 -> V_59 . V_61 ) ;
return V_44 ;
}
static T_3 F_50 ( struct V_19 * V_20 , struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_58 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_75 ;
if ( V_22 == & V_80 )
V_75 = F_35 ( V_5 , V_5 -> V_59 . V_79 ) ;
else if ( V_22 == & V_81 )
V_75 = F_35 ( V_5 , V_5 -> V_59 . V_82 ) ;
else if ( V_22 == & V_83 )
V_75 = F_35 ( V_5 , V_5 -> V_59 . V_76 ) ;
else
F_51 () ;
return snprintf ( V_23 , V_26 , L_4 , V_75 ) ;
}
static T_3 F_52 ( struct V_39 * V_40 , struct V_41 * V_42 ,
struct V_43 * V_22 , char * V_23 ,
T_4 V_84 , T_5 V_44 )
{
struct V_19 * V_20 = F_20 ( V_42 , struct V_19 , V_42 ) ;
struct V_24 * V_58 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_85 V_86 ;
struct V_87 V_88 ;
T_3 V_89 = 0 ;
int V_10 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_10 = F_53 ( & V_88 , F_54 ( V_2 ) , V_44 , V_84 ) ;
if ( V_10 )
return V_10 ;
V_86 . V_2 = V_2 ;
F_55 ( V_2 , & V_86 ) ;
V_10 = F_56 ( & V_88 , & V_86 ) ;
if ( V_10 )
goto V_16;
V_89 = V_44 < V_88 . V_90 ? V_44 : V_88 . V_90 ;
memcpy ( V_23 , V_88 . V_23 , V_89 ) ;
V_16:
F_57 ( & V_86 ) ;
F_58 ( & V_88 ) ;
return V_10 ? : V_89 ;
}
static T_3 F_59 ( struct V_39 * V_39 , struct V_41 * V_42 ,
struct V_43 * V_22 , char * V_23 ,
T_4 V_84 , T_5 V_44 )
{
struct V_19 * V_20 = F_20 ( V_42 , struct V_19 , V_42 ) ;
struct V_24 * V_58 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
int V_10 ;
F_60 ( L_6 ) ;
V_10 = F_61 ( & V_2 -> V_51 ) ;
if ( V_10 )
return V_10 ;
F_62 ( V_2 ) ;
F_24 ( & V_2 -> V_51 ) ;
return V_44 ;
}
void F_63 ( struct V_1 * V_2 )
{
int V_10 ;
#ifdef F_64
if ( F_65 ( V_2 ) ) {
V_10 = F_66 ( & V_2 -> V_91 -> V_20 -> V_42 ,
& V_92 ) ;
if ( V_10 )
F_67 ( L_7 ) ;
}
if ( F_68 ( V_2 ) ) {
V_10 = F_66 ( & V_2 -> V_91 -> V_20 -> V_42 ,
& V_93 ) ;
if ( V_10 )
F_67 ( L_8 ) ;
}
if ( F_4 ( V_2 ) ) {
V_10 = F_66 ( & V_2 -> V_91 -> V_20 -> V_42 ,
& V_94 ) ;
if ( V_10 )
F_67 ( L_9 ) ;
}
#endif
if ( F_18 ( V_2 ) ) {
V_10 = F_69 ( V_2 -> V_91 -> V_20 , & V_95 ) ;
if ( V_10 )
F_67 ( L_10 ) ;
if ( F_70 ( V_2 ) > 1 ) {
V_10 = F_69 ( V_2 -> V_91 -> V_20 ,
& V_96 ) ;
if ( V_10 )
F_67 ( L_11 ) ;
}
}
V_10 = 0 ;
if ( F_4 ( V_2 ) )
V_10 = F_71 ( & V_2 -> V_91 -> V_20 -> V_42 , V_97 ) ;
else if ( F_72 ( V_2 ) -> V_98 >= 6 )
V_10 = F_71 ( & V_2 -> V_91 -> V_20 -> V_42 , V_99 ) ;
if ( V_10 )
F_67 ( L_12 ) ;
V_10 = F_73 ( & V_2 -> V_91 -> V_20 -> V_42 ,
& V_100 ) ;
if ( V_10 )
F_67 ( L_13 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
F_75 ( & V_2 -> V_91 -> V_20 -> V_42 , & V_100 ) ;
if ( F_4 ( V_2 ) )
F_76 ( & V_2 -> V_91 -> V_20 -> V_42 , V_97 ) ;
else
F_76 ( & V_2 -> V_91 -> V_20 -> V_42 , V_99 ) ;
F_77 ( V_2 -> V_91 -> V_20 , & V_96 ) ;
F_77 ( V_2 -> V_91 -> V_20 , & V_95 ) ;
#ifdef F_64
F_78 ( & V_2 -> V_91 -> V_20 -> V_42 , & V_92 ) ;
F_78 ( & V_2 -> V_91 -> V_20 -> V_42 , & V_93 ) ;
#endif
}
