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
T_1 V_3 , V_11 ;
if ( F_5 ( V_2 ) )
V_3 = V_12 ;
else
V_3 = V_13 ;
V_11 = F_6 ( V_3 ) >> V_14 ;
if ( ! V_11 ) {
F_7 ( ! V_11 , L_1 ) ;
V_10 = 0 ;
goto V_15;
}
V_8 = 0 ;
div = 1000000ULL ;
if ( F_5 ( V_2 ) ) {
if ( V_11 == 1 ) {
div = 10000000ULL ;
V_8 = 3125ULL ;
} else {
V_11 += 1 ;
}
}
if ( V_8 == 0 )
V_8 = F_8 ( 30ULL * V_9 ,
( T_2 ) V_11 ) ;
if ( F_6 ( V_16 ) & V_17 )
V_8 <<= 8 ;
div = div * V_9 ;
}
V_7 = F_6 ( V_3 ) * V_8 ;
V_10 = F_8 ( V_7 , div ) ;
V_15:
F_9 ( V_5 ) ;
return V_10 ;
}
static T_3
F_10 ( struct V_18 * V_19 , struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_24 = F_11 ( V_19 ) ;
return snprintf ( V_22 , V_25 , L_2 , F_2 ( V_24 -> V_2 ) ) ;
}
static T_3
F_12 ( struct V_18 * V_19 , struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_24 = F_13 ( V_19 ) ;
T_1 V_26 = F_1 ( V_24 -> V_2 , V_27 ) ;
return snprintf ( V_22 , V_25 , L_3 , V_26 ) ;
}
static T_3
F_14 ( struct V_18 * V_19 , struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_24 = F_11 ( V_19 ) ;
T_1 V_28 = F_1 ( V_24 -> V_2 , V_29 ) ;
if ( F_4 ( V_24 -> V_2 ) )
V_28 = 0 ;
return snprintf ( V_22 , V_25 , L_3 , V_28 ) ;
}
static T_3
F_15 ( struct V_18 * V_19 , struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_24 = F_11 ( V_19 ) ;
T_1 V_30 = F_1 ( V_24 -> V_2 , V_31 ) ;
if ( F_4 ( V_24 -> V_2 ) )
V_30 = 0 ;
return snprintf ( V_22 , V_25 , L_3 , V_30 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_4 V_32 )
{
if ( ! F_17 ( V_2 ) )
return - V_33 ;
if ( V_32 % 4 != 0 )
return - V_34 ;
if ( V_32 >= V_35 )
return - V_36 ;
return 0 ;
}
static T_3
F_18 ( struct V_37 * V_38 , struct V_39 * V_40 ,
struct V_41 * V_21 , char * V_22 ,
T_4 V_32 , T_5 V_42 )
{
struct V_18 * V_2 = F_19 ( V_40 , struct V_18 , V_40 ) ;
struct V_23 * V_24 = F_11 ( V_2 ) ;
struct V_1 * V_43 = V_24 -> V_2 ;
struct V_4 * V_5 = V_43 -> V_6 ;
int V_44 = ( int ) ( V_45 ) V_21 -> V_46 ;
int V_10 ;
V_42 = F_20 ( V_42 , 4 ) ;
V_10 = F_16 ( V_43 , V_32 ) ;
if ( V_10 )
return V_10 ;
V_42 = F_21 ( T_5 , V_35 - V_32 , V_42 ) ;
V_10 = F_22 ( V_43 ) ;
if ( V_10 )
return V_10 ;
if ( V_5 -> V_47 . V_48 [ V_44 ] )
memcpy ( V_22 ,
V_5 -> V_47 . V_48 [ V_44 ] + ( V_32 / 4 ) ,
V_42 ) ;
else
memset ( V_22 , 0 , V_42 ) ;
F_23 ( & V_43 -> V_49 ) ;
return V_42 ;
}
static T_3
F_24 ( struct V_37 * V_38 , struct V_39 * V_40 ,
struct V_41 * V_21 , char * V_22 ,
T_4 V_32 , T_5 V_42 )
{
struct V_18 * V_2 = F_19 ( V_40 , struct V_18 , V_40 ) ;
struct V_23 * V_24 = F_11 ( V_2 ) ;
struct V_1 * V_43 = V_24 -> V_2 ;
struct V_4 * V_5 = V_43 -> V_6 ;
struct V_50 * V_51 ;
T_1 * V_52 = NULL ;
int V_44 = ( int ) ( V_45 ) V_21 -> V_46 ;
int V_10 ;
if ( ! F_25 ( V_43 ) )
return - V_36 ;
V_10 = F_16 ( V_43 , V_32 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_22 ( V_43 ) ;
if ( V_10 )
return V_10 ;
if ( ! V_5 -> V_47 . V_48 [ V_44 ] ) {
V_52 = F_26 ( V_35 , V_53 ) ;
if ( ! V_52 ) {
F_23 ( & V_43 -> V_49 ) ;
return - V_54 ;
}
}
V_10 = F_27 ( V_43 ) ;
if ( V_10 ) {
F_28 ( V_52 ) ;
F_23 ( & V_43 -> V_49 ) ;
return V_10 ;
}
if ( V_52 )
V_5 -> V_47 . V_48 [ V_44 ] = V_52 ;
memcpy ( V_5 -> V_47 . V_48 [ V_44 ] + ( V_32 / 4 ) , V_22 , V_42 ) ;
F_29 (ctx, &dev_priv->context_list, link)
V_51 -> V_55 |= ( 1 << V_44 ) ;
F_23 ( & V_43 -> V_49 ) ;
return V_42 ;
}
static T_3 F_30 ( struct V_18 * V_19 ,
struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_56 = F_11 ( V_19 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 ;
F_31 ( & V_5 -> V_57 . V_58 ) ;
F_3 ( V_5 ) ;
F_32 ( & V_5 -> V_57 . V_59 ) ;
if ( F_4 ( V_5 -> V_2 ) ) {
T_1 V_60 ;
V_60 = F_33 ( V_5 , V_61 ) ;
V_10 = F_34 ( V_5 , ( V_60 >> 8 ) & 0xff ) ;
} else {
V_10 = V_5 -> V_57 . V_62 * V_63 ;
}
F_23 ( & V_5 -> V_57 . V_59 ) ;
F_9 ( V_5 ) ;
return snprintf ( V_22 , V_25 , L_4 , V_10 ) ;
}
static T_3 F_35 ( struct V_18 * V_19 ,
struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_56 = F_11 ( V_19 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
return snprintf ( V_22 , V_25 , L_4 ,
F_34 ( V_5 , V_5 -> V_57 . V_64 ) ) ;
}
static T_3 F_36 ( struct V_18 * V_19 , struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_56 = F_11 ( V_19 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 ;
F_31 ( & V_5 -> V_57 . V_58 ) ;
F_32 ( & V_5 -> V_57 . V_59 ) ;
if ( F_4 ( V_5 -> V_2 ) )
V_10 = F_34 ( V_5 , V_5 -> V_57 . V_65 ) ;
else
V_10 = V_5 -> V_57 . V_65 * V_63 ;
F_23 ( & V_5 -> V_57 . V_59 ) ;
return snprintf ( V_22 , V_25 , L_4 , V_10 ) ;
}
static T_3 F_37 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
const char * V_22 , T_5 V_42 )
{
struct V_23 * V_56 = F_11 ( V_19 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_66 ;
T_3 V_10 ;
V_10 = F_38 ( V_22 , 0 , & V_66 ) ;
if ( V_10 )
return V_10 ;
F_31 ( & V_5 -> V_57 . V_58 ) ;
F_32 ( & V_5 -> V_57 . V_59 ) ;
if ( F_4 ( V_5 -> V_2 ) )
V_66 = F_39 ( V_5 , V_66 ) ;
else
V_66 /= V_63 ;
if ( V_66 < V_5 -> V_57 . V_67 ||
V_66 > V_5 -> V_57 . V_68 ||
V_66 < V_5 -> V_57 . V_69 ) {
F_23 ( & V_5 -> V_57 . V_59 ) ;
return - V_34 ;
}
if ( V_66 > V_5 -> V_57 . V_70 )
F_40 ( L_5 ,
V_66 * V_63 ) ;
V_5 -> V_57 . V_65 = V_66 ;
if ( V_5 -> V_57 . V_62 > V_66 ) {
if ( F_4 ( V_2 ) )
F_41 ( V_2 , V_66 ) ;
else
F_42 ( V_2 , V_66 ) ;
} else if ( ! F_4 ( V_2 ) ) {
F_42 ( V_2 , V_5 -> V_57 . V_62 ) ;
}
F_23 ( & V_5 -> V_57 . V_59 ) ;
return V_42 ;
}
static T_3 F_43 ( struct V_18 * V_19 , struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_56 = F_11 ( V_19 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 ;
F_31 ( & V_5 -> V_57 . V_58 ) ;
F_32 ( & V_5 -> V_57 . V_59 ) ;
if ( F_4 ( V_5 -> V_2 ) )
V_10 = F_34 ( V_5 , V_5 -> V_57 . V_69 ) ;
else
V_10 = V_5 -> V_57 . V_69 * V_63 ;
F_23 ( & V_5 -> V_57 . V_59 ) ;
return snprintf ( V_22 , V_25 , L_4 , V_10 ) ;
}
static T_3 F_44 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
const char * V_22 , T_5 V_42 )
{
struct V_23 * V_56 = F_11 ( V_19 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_66 ;
T_3 V_10 ;
V_10 = F_38 ( V_22 , 0 , & V_66 ) ;
if ( V_10 )
return V_10 ;
F_31 ( & V_5 -> V_57 . V_58 ) ;
F_32 ( & V_5 -> V_57 . V_59 ) ;
if ( F_4 ( V_2 ) )
V_66 = F_39 ( V_5 , V_66 ) ;
else
V_66 /= V_63 ;
if ( V_66 < V_5 -> V_57 . V_67 ||
V_66 > V_5 -> V_57 . V_68 ||
V_66 > V_5 -> V_57 . V_65 ) {
F_23 ( & V_5 -> V_57 . V_59 ) ;
return - V_34 ;
}
V_5 -> V_57 . V_69 = V_66 ;
if ( V_5 -> V_57 . V_62 < V_66 ) {
if ( F_4 ( V_2 ) )
F_41 ( V_2 , V_66 ) ;
else
F_42 ( V_2 , V_66 ) ;
} else if ( ! F_4 ( V_2 ) ) {
F_42 ( V_2 , V_5 -> V_57 . V_62 ) ;
}
F_23 ( & V_5 -> V_57 . V_59 ) ;
return V_42 ;
}
static T_3 F_45 ( struct V_18 * V_19 , struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_56 = F_11 ( V_19 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_66 , V_71 ;
T_3 V_10 ;
V_10 = F_46 ( & V_2 -> V_49 ) ;
if ( V_10 )
return V_10 ;
F_3 ( V_5 ) ;
V_71 = F_6 ( V_72 ) ;
F_9 ( V_5 ) ;
F_23 ( & V_2 -> V_49 ) ;
if ( V_21 == & V_73 ) {
if ( F_4 ( V_2 ) )
V_66 = F_34 ( V_5 , V_5 -> V_57 . V_70 ) ;
else
V_66 = ( ( V_71 & 0x0000ff ) >> 0 ) * V_63 ;
} else if ( V_21 == & V_74 ) {
if ( F_4 ( V_2 ) )
V_66 = F_34 ( V_5 , V_5 -> V_57 . V_75 ) ;
else
V_66 = ( ( V_71 & 0x00ff00 ) >> 8 ) * V_63 ;
} else if ( V_21 == & V_76 ) {
if ( F_4 ( V_2 ) )
V_66 = F_34 ( V_5 , V_5 -> V_57 . V_67 ) ;
else
V_66 = ( ( V_71 & 0xff0000 ) >> 16 ) * V_63 ;
} else {
F_47 () ;
}
return snprintf ( V_22 , V_25 , L_4 , V_66 ) ;
}
static T_3 F_48 ( struct V_37 * V_38 , struct V_39 * V_40 ,
struct V_41 * V_21 , char * V_22 ,
T_4 V_77 , T_5 V_42 )
{
struct V_18 * V_19 = F_19 ( V_40 , struct V_18 , V_40 ) ;
struct V_23 * V_56 = F_11 ( V_19 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
T_3 V_82 = 0 ;
int V_10 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_10 = F_49 ( & V_81 , V_42 , V_77 ) ;
if ( V_10 )
return V_10 ;
V_79 . V_2 = V_2 ;
F_50 ( V_2 , & V_79 ) ;
V_10 = F_51 ( & V_81 , & V_79 ) ;
if ( V_10 )
goto V_15;
V_82 = V_42 < V_81 . V_83 ? V_42 : V_81 . V_83 ;
memcpy ( V_22 , V_81 . V_22 , V_82 ) ;
V_15:
F_52 ( & V_79 ) ;
F_53 ( & V_81 ) ;
return V_10 ? : V_82 ;
}
static T_3 F_54 ( struct V_37 * V_37 , struct V_39 * V_40 ,
struct V_41 * V_21 , char * V_22 ,
T_4 V_77 , T_5 V_42 )
{
struct V_18 * V_19 = F_19 ( V_40 , struct V_18 , V_40 ) ;
struct V_23 * V_56 = F_11 ( V_19 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
int V_10 ;
F_55 ( L_6 ) ;
V_10 = F_46 ( & V_2 -> V_49 ) ;
if ( V_10 )
return V_10 ;
F_56 ( V_2 ) ;
F_23 ( & V_2 -> V_49 ) ;
return V_42 ;
}
void F_57 ( struct V_1 * V_2 )
{
int V_10 ;
#ifdef F_58
if ( F_59 ( V_2 ) -> V_84 >= 6 ) {
V_10 = F_60 ( & V_2 -> V_85 -> V_19 -> V_40 ,
& V_86 ) ;
if ( V_10 )
F_61 ( L_7 ) ;
}
#endif
if ( F_17 ( V_2 ) ) {
V_10 = F_62 ( V_2 -> V_85 -> V_19 , & V_87 ) ;
if ( V_10 )
F_61 ( L_8 ) ;
if ( F_63 ( V_2 ) > 1 ) {
V_10 = F_62 ( V_2 -> V_85 -> V_19 ,
& V_88 ) ;
if ( V_10 )
F_61 ( L_9 ) ;
}
}
V_10 = 0 ;
if ( F_4 ( V_2 ) )
V_10 = F_64 ( & V_2 -> V_85 -> V_19 -> V_40 , V_89 ) ;
else if ( F_59 ( V_2 ) -> V_84 >= 6 )
V_10 = F_64 ( & V_2 -> V_85 -> V_19 -> V_40 , V_90 ) ;
if ( V_10 )
F_61 ( L_10 ) ;
V_10 = F_65 ( & V_2 -> V_85 -> V_19 -> V_40 ,
& V_91 ) ;
if ( V_10 )
F_61 ( L_11 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
F_67 ( & V_2 -> V_85 -> V_19 -> V_40 , & V_91 ) ;
if ( F_4 ( V_2 ) )
F_68 ( & V_2 -> V_85 -> V_19 -> V_40 , V_89 ) ;
else
F_68 ( & V_2 -> V_85 -> V_19 -> V_40 , V_90 ) ;
F_69 ( V_2 -> V_85 -> V_19 , & V_88 ) ;
F_69 ( V_2 -> V_85 -> V_19 , & V_87 ) ;
#ifdef F_58
F_70 ( & V_2 -> V_85 -> V_19 -> V_40 , & V_86 ) ;
#endif
}
