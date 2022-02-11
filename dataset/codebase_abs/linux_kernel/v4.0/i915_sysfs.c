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
V_8 = 0 ;
div = 1000000ULL ;
if ( F_5 ( V_2 ) ) {
if ( V_12 == 1 ) {
div = 10000000ULL ;
V_8 = 3125ULL ;
} else {
V_12 += 1 ;
}
}
if ( V_8 == 0 )
V_8 = F_8 ( 30ULL * V_9 ,
( T_2 ) V_12 ) ;
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
static int F_16 ( struct V_1 * V_2 , T_4 V_33 )
{
if ( ! F_17 ( V_2 ) )
return - V_34 ;
if ( V_33 % 4 != 0 )
return - V_35 ;
if ( V_33 >= V_36 )
return - V_37 ;
return 0 ;
}
static T_3
F_18 ( struct V_38 * V_39 , struct V_40 * V_41 ,
struct V_42 * V_22 , char * V_23 ,
T_4 V_33 , T_5 V_43 )
{
struct V_19 * V_2 = F_19 ( V_41 , struct V_19 , V_41 ) ;
struct V_24 * V_25 = F_11 ( V_2 ) ;
struct V_1 * V_44 = V_25 -> V_2 ;
struct V_4 * V_5 = V_44 -> V_6 ;
int V_45 = ( int ) ( V_46 ) V_22 -> V_47 ;
int V_10 ;
V_43 = F_20 ( V_43 , 4 ) ;
V_10 = F_16 ( V_44 , V_33 ) ;
if ( V_10 )
return V_10 ;
V_43 = F_21 ( T_5 , V_36 - V_33 , V_43 ) ;
V_10 = F_22 ( V_44 ) ;
if ( V_10 )
return V_10 ;
if ( V_5 -> V_48 . V_49 [ V_45 ] )
memcpy ( V_23 ,
V_5 -> V_48 . V_49 [ V_45 ] + ( V_33 / 4 ) ,
V_43 ) ;
else
memset ( V_23 , 0 , V_43 ) ;
F_23 ( & V_44 -> V_50 ) ;
return V_43 ;
}
static T_3
F_24 ( struct V_38 * V_39 , struct V_40 * V_41 ,
struct V_42 * V_22 , char * V_23 ,
T_4 V_33 , T_5 V_43 )
{
struct V_19 * V_2 = F_19 ( V_41 , struct V_19 , V_41 ) ;
struct V_24 * V_25 = F_11 ( V_2 ) ;
struct V_1 * V_44 = V_25 -> V_2 ;
struct V_4 * V_5 = V_44 -> V_6 ;
struct V_51 * V_52 ;
T_1 * V_53 = NULL ;
int V_45 = ( int ) ( V_46 ) V_22 -> V_47 ;
int V_10 ;
if ( ! F_25 ( V_44 ) )
return - V_37 ;
V_10 = F_16 ( V_44 , V_33 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_22 ( V_44 ) ;
if ( V_10 )
return V_10 ;
if ( ! V_5 -> V_48 . V_49 [ V_45 ] ) {
V_53 = F_26 ( V_36 , V_54 ) ;
if ( ! V_53 ) {
F_23 ( & V_44 -> V_50 ) ;
return - V_55 ;
}
}
V_10 = F_27 ( V_44 ) ;
if ( V_10 ) {
F_28 ( V_53 ) ;
F_23 ( & V_44 -> V_50 ) ;
return V_10 ;
}
if ( V_53 )
V_5 -> V_48 . V_49 [ V_45 ] = V_53 ;
memcpy ( V_5 -> V_48 . V_49 [ V_45 ] + ( V_33 / 4 ) , V_23 , V_43 ) ;
F_29 (ctx, &dev_priv->context_list, link)
V_52 -> V_56 |= ( 1 << V_45 ) ;
F_23 ( & V_44 -> V_50 ) ;
return V_43 ;
}
static T_3 F_30 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_57 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 ;
F_31 ( & V_5 -> V_58 . V_59 ) ;
F_3 ( V_5 ) ;
F_32 ( & V_5 -> V_58 . V_60 ) ;
if ( F_4 ( V_5 -> V_2 ) ) {
T_1 V_61 ;
V_61 = F_33 ( V_5 , V_62 ) ;
V_10 = F_34 ( V_5 , ( V_61 >> 8 ) & 0xff ) ;
} else {
T_1 V_63 = F_6 ( V_64 ) ;
if ( F_35 ( V_5 ) || F_36 ( V_5 ) )
V_10 = ( V_63 & V_65 ) >> V_66 ;
else
V_10 = ( V_63 & V_67 ) >> V_68 ;
V_10 = F_34 ( V_5 , V_10 ) ;
}
F_23 ( & V_5 -> V_58 . V_60 ) ;
F_9 ( V_5 ) ;
return snprintf ( V_23 , V_26 , L_4 , V_10 ) ;
}
static T_3 F_37 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_57 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 ;
F_31 ( & V_5 -> V_58 . V_59 ) ;
F_3 ( V_5 ) ;
F_32 ( & V_5 -> V_58 . V_60 ) ;
V_10 = F_34 ( V_5 , V_5 -> V_58 . V_69 ) ;
F_23 ( & V_5 -> V_58 . V_60 ) ;
F_9 ( V_5 ) ;
return snprintf ( V_23 , V_26 , L_4 , V_10 ) ;
}
static T_3 F_38 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_57 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
return snprintf ( V_23 , V_26 ,
L_4 ,
F_34 ( V_5 , V_5 -> V_58 . V_70 ) ) ;
}
static T_3 F_39 ( struct V_19 * V_20 , struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_57 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 ;
F_31 ( & V_5 -> V_58 . V_59 ) ;
F_32 ( & V_5 -> V_58 . V_60 ) ;
V_10 = F_34 ( V_5 , V_5 -> V_58 . V_71 ) ;
F_23 ( & V_5 -> V_58 . V_60 ) ;
return snprintf ( V_23 , V_26 , L_4 , V_10 ) ;
}
static T_3 F_40 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
const char * V_23 , T_5 V_43 )
{
struct V_24 * V_57 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_72 ;
T_3 V_10 ;
V_10 = F_41 ( V_23 , 0 , & V_72 ) ;
if ( V_10 )
return V_10 ;
F_31 ( & V_5 -> V_58 . V_59 ) ;
F_32 ( & V_5 -> V_58 . V_60 ) ;
V_72 = F_42 ( V_5 , V_72 ) ;
if ( V_72 < V_5 -> V_58 . V_73 ||
V_72 > V_5 -> V_58 . V_74 ||
V_72 < V_5 -> V_58 . V_75 ) {
F_23 ( & V_5 -> V_58 . V_60 ) ;
return - V_35 ;
}
if ( V_72 > V_5 -> V_58 . V_76 )
F_43 ( L_5 ,
F_34 ( V_5 , V_72 ) ) ;
V_5 -> V_58 . V_71 = V_72 ;
V_72 = F_44 ( int , V_5 -> V_58 . V_69 ,
V_5 -> V_58 . V_75 ,
V_5 -> V_58 . V_71 ) ;
if ( F_4 ( V_2 ) )
F_45 ( V_2 , V_72 ) ;
else
F_46 ( V_2 , V_72 ) ;
F_23 ( & V_5 -> V_58 . V_60 ) ;
return V_43 ;
}
static T_3 F_47 ( struct V_19 * V_20 , struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_57 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 ;
F_31 ( & V_5 -> V_58 . V_59 ) ;
F_32 ( & V_5 -> V_58 . V_60 ) ;
V_10 = F_34 ( V_5 , V_5 -> V_58 . V_75 ) ;
F_23 ( & V_5 -> V_58 . V_60 ) ;
return snprintf ( V_23 , V_26 , L_4 , V_10 ) ;
}
static T_3 F_48 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
const char * V_23 , T_5 V_43 )
{
struct V_24 * V_57 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_72 ;
T_3 V_10 ;
V_10 = F_41 ( V_23 , 0 , & V_72 ) ;
if ( V_10 )
return V_10 ;
F_31 ( & V_5 -> V_58 . V_59 ) ;
F_32 ( & V_5 -> V_58 . V_60 ) ;
V_72 = F_42 ( V_5 , V_72 ) ;
if ( V_72 < V_5 -> V_58 . V_73 ||
V_72 > V_5 -> V_58 . V_74 ||
V_72 > V_5 -> V_58 . V_71 ) {
F_23 ( & V_5 -> V_58 . V_60 ) ;
return - V_35 ;
}
V_5 -> V_58 . V_75 = V_72 ;
V_72 = F_44 ( int , V_5 -> V_58 . V_69 ,
V_5 -> V_58 . V_75 ,
V_5 -> V_58 . V_71 ) ;
if ( F_4 ( V_2 ) )
F_45 ( V_2 , V_72 ) ;
else
F_46 ( V_2 , V_72 ) ;
F_23 ( & V_5 -> V_58 . V_60 ) ;
return V_43 ;
}
static T_3 F_49 ( struct V_19 * V_20 , struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_57 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_72 , V_77 ;
T_3 V_10 ;
V_10 = F_50 ( & V_2 -> V_50 ) ;
if ( V_10 )
return V_10 ;
F_3 ( V_5 ) ;
V_77 = F_6 ( V_78 ) ;
F_9 ( V_5 ) ;
F_23 ( & V_2 -> V_50 ) ;
if ( V_22 == & V_79 ) {
if ( F_4 ( V_2 ) )
V_72 = F_34 ( V_5 , V_5 -> V_58 . V_76 ) ;
else
V_72 = F_34 ( V_5 ,
( ( V_77 & 0x0000ff ) >> 0 ) ) ;
} else if ( V_22 == & V_80 ) {
if ( F_4 ( V_2 ) )
V_72 = F_34 ( V_5 , V_5 -> V_58 . V_81 ) ;
else
V_72 = F_34 ( V_5 ,
( ( V_77 & 0x00ff00 ) >> 8 ) ) ;
} else if ( V_22 == & V_82 ) {
if ( F_4 ( V_2 ) )
V_72 = F_34 ( V_5 , V_5 -> V_58 . V_73 ) ;
else
V_72 = F_34 ( V_5 ,
( ( V_77 & 0xff0000 ) >> 16 ) ) ;
} else {
F_51 () ;
}
return snprintf ( V_23 , V_26 , L_4 , V_72 ) ;
}
static T_3 F_52 ( struct V_38 * V_39 , struct V_40 * V_41 ,
struct V_42 * V_22 , char * V_23 ,
T_4 V_83 , T_5 V_43 )
{
struct V_19 * V_20 = F_19 ( V_41 , struct V_19 , V_41 ) ;
struct V_24 * V_57 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_84 V_85 ;
struct V_86 V_87 ;
T_3 V_88 = 0 ;
int V_10 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_10 = F_53 ( & V_87 , F_54 ( V_2 ) , V_43 , V_83 ) ;
if ( V_10 )
return V_10 ;
V_85 . V_2 = V_2 ;
F_55 ( V_2 , & V_85 ) ;
V_10 = F_56 ( & V_87 , & V_85 ) ;
if ( V_10 )
goto V_16;
V_88 = V_43 < V_87 . V_89 ? V_43 : V_87 . V_89 ;
memcpy ( V_23 , V_87 . V_23 , V_88 ) ;
V_16:
F_57 ( & V_85 ) ;
F_58 ( & V_87 ) ;
return V_10 ? : V_88 ;
}
static T_3 F_59 ( struct V_38 * V_38 , struct V_40 * V_41 ,
struct V_42 * V_22 , char * V_23 ,
T_4 V_83 , T_5 V_43 )
{
struct V_19 * V_20 = F_19 ( V_41 , struct V_19 , V_41 ) ;
struct V_24 * V_57 = F_11 ( V_20 ) ;
struct V_1 * V_2 = V_57 -> V_2 ;
int V_10 ;
F_60 ( L_6 ) ;
V_10 = F_50 ( & V_2 -> V_50 ) ;
if ( V_10 )
return V_10 ;
F_61 ( V_2 ) ;
F_23 ( & V_2 -> V_50 ) ;
return V_43 ;
}
void F_62 ( struct V_1 * V_2 )
{
int V_10 ;
#ifdef F_63
if ( F_64 ( V_2 ) ) {
V_10 = F_65 ( & V_2 -> V_90 -> V_20 -> V_41 ,
& V_91 ) ;
if ( V_10 )
F_66 ( L_7 ) ;
}
if ( F_67 ( V_2 ) ) {
V_10 = F_65 ( & V_2 -> V_90 -> V_20 -> V_41 ,
& V_92 ) ;
if ( V_10 )
F_66 ( L_8 ) ;
}
#endif
if ( F_17 ( V_2 ) ) {
V_10 = F_68 ( V_2 -> V_90 -> V_20 , & V_93 ) ;
if ( V_10 )
F_66 ( L_9 ) ;
if ( F_69 ( V_2 ) > 1 ) {
V_10 = F_68 ( V_2 -> V_90 -> V_20 ,
& V_94 ) ;
if ( V_10 )
F_66 ( L_10 ) ;
}
}
V_10 = 0 ;
if ( F_4 ( V_2 ) )
V_10 = F_70 ( & V_2 -> V_90 -> V_20 -> V_41 , V_95 ) ;
else if ( F_71 ( V_2 ) -> V_96 >= 6 )
V_10 = F_70 ( & V_2 -> V_90 -> V_20 -> V_41 , V_97 ) ;
if ( V_10 )
F_66 ( L_11 ) ;
V_10 = F_72 ( & V_2 -> V_90 -> V_20 -> V_41 ,
& V_98 ) ;
if ( V_10 )
F_66 ( L_12 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
F_74 ( & V_2 -> V_90 -> V_20 -> V_41 , & V_98 ) ;
if ( F_4 ( V_2 ) )
F_75 ( & V_2 -> V_90 -> V_20 -> V_41 , V_95 ) ;
else
F_75 ( & V_2 -> V_90 -> V_20 -> V_41 , V_97 ) ;
F_76 ( V_2 -> V_90 -> V_20 , & V_94 ) ;
F_76 ( V_2 -> V_90 -> V_20 , & V_93 ) ;
#ifdef F_63
F_77 ( & V_2 -> V_90 -> V_20 -> V_41 , & V_91 ) ;
F_77 ( & V_2 -> V_90 -> V_20 -> V_41 , & V_92 ) ;
#endif
}
