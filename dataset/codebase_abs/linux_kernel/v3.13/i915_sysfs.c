static T_1 F_1 ( struct V_1 * V_2 , const T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_7 ;
T_2 V_8 = 128ULL , div = 100000ULL , V_9 = 100ULL ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( F_3 ( V_2 ) ) {
T_1 V_10 ;
V_10 = F_4 ( V_11 ) >>
V_12 ;
if ( ! V_10 ) {
F_5 ( ! V_10 , L_1 ) ;
return 0 ;
}
V_8 = F_6 ( 30ULL * V_9 , ( T_2 ) V_10 ) ;
if ( F_4 ( V_13 ) & V_14 )
V_8 <<= 8 ;
div = 1000000ULL * V_9 ;
}
V_7 = F_4 ( V_3 ) * V_8 ;
return F_6 ( V_7 , div ) ;
}
static T_3
F_7 ( struct V_15 * V_16 , struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_21 = F_8 ( V_16 ) ;
return snprintf ( V_19 , V_22 , L_2 , F_2 ( V_21 -> V_2 ) ) ;
}
static T_3
F_9 ( struct V_15 * V_16 , struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_21 = F_10 ( V_16 ) ;
T_1 V_23 = F_1 ( V_21 -> V_2 , V_24 ) ;
return snprintf ( V_19 , V_22 , L_3 , V_23 ) ;
}
static T_3
F_11 ( struct V_15 * V_16 , struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_21 = F_8 ( V_16 ) ;
T_1 V_25 = F_1 ( V_21 -> V_2 , V_26 ) ;
if ( F_3 ( V_21 -> V_2 ) )
V_25 = 0 ;
return snprintf ( V_19 , V_22 , L_3 , V_25 ) ;
}
static T_3
F_12 ( struct V_15 * V_16 , struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_21 = F_8 ( V_16 ) ;
T_1 V_27 = F_1 ( V_21 -> V_2 , V_28 ) ;
if ( F_3 ( V_21 -> V_2 ) )
V_27 = 0 ;
return snprintf ( V_19 , V_22 , L_3 , V_27 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_4 V_29 )
{
if ( ! F_14 ( V_2 ) )
return - V_30 ;
if ( V_29 % 4 != 0 )
return - V_31 ;
if ( V_29 >= V_32 )
return - V_33 ;
return 0 ;
}
static T_3
F_15 ( struct V_34 * V_35 , struct V_36 * V_37 ,
struct V_38 * V_18 , char * V_19 ,
T_4 V_29 , T_5 V_39 )
{
struct V_15 * V_2 = F_16 ( V_37 , struct V_15 , V_37 ) ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_1 * V_40 = V_21 -> V_2 ;
struct V_4 * V_5 = V_40 -> V_6 ;
int V_41 = ( int ) ( V_42 ) V_18 -> V_43 ;
int V_44 ;
V_39 = F_17 ( V_39 , 4 ) ;
V_44 = F_13 ( V_40 , V_29 ) ;
if ( V_44 )
return V_44 ;
V_39 = F_18 ( T_5 , V_32 - V_29 , V_39 ) ;
V_44 = F_19 ( V_40 ) ;
if ( V_44 )
return V_44 ;
if ( V_5 -> V_45 . V_46 [ V_41 ] )
memcpy ( V_19 ,
V_5 -> V_45 . V_46 [ V_41 ] + ( V_29 / 4 ) ,
V_39 ) ;
else
memset ( V_19 , 0 , V_39 ) ;
F_20 ( & V_40 -> V_47 ) ;
return V_39 ;
}
static T_3
F_21 ( struct V_34 * V_35 , struct V_36 * V_37 ,
struct V_38 * V_18 , char * V_19 ,
T_4 V_29 , T_5 V_39 )
{
struct V_15 * V_2 = F_16 ( V_37 , struct V_15 , V_37 ) ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_1 * V_40 = V_21 -> V_2 ;
struct V_4 * V_5 = V_40 -> V_6 ;
struct V_48 * V_49 ;
T_1 * V_50 = NULL ;
int V_41 = ( int ) ( V_42 ) V_18 -> V_43 ;
int V_44 ;
V_44 = F_13 ( V_40 , V_29 ) ;
if ( V_44 )
return V_44 ;
if ( V_5 -> V_51 )
return - V_33 ;
V_44 = F_19 ( V_40 ) ;
if ( V_44 )
return V_44 ;
if ( ! V_5 -> V_45 . V_46 [ V_41 ] ) {
V_50 = F_22 ( V_32 , V_52 ) ;
if ( ! V_50 ) {
F_20 ( & V_40 -> V_47 ) ;
return - V_53 ;
}
}
V_44 = F_23 ( V_40 ) ;
if ( V_44 ) {
F_24 ( V_50 ) ;
F_20 ( & V_40 -> V_47 ) ;
return V_44 ;
}
if ( V_50 )
V_5 -> V_45 . V_46 [ V_41 ] = V_50 ;
memcpy ( V_5 -> V_45 . V_46 [ V_41 ] + ( V_29 / 4 ) , V_19 , V_39 ) ;
F_25 (ctx, &dev_priv->context_list, link)
V_49 -> V_54 |= ( 1 << V_41 ) ;
F_20 ( & V_40 -> V_47 ) ;
return V_39 ;
}
static T_3 F_26 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_55 = F_8 ( V_16 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_27 ( & V_5 -> V_56 . V_57 ) ;
F_28 ( & V_5 -> V_56 . V_58 ) ;
if ( F_3 ( V_5 -> V_2 ) ) {
T_1 V_59 ;
V_59 = F_29 ( V_5 , V_60 ) ;
V_44 = F_30 ( V_5 -> V_61 , ( V_59 >> 8 ) & 0xff ) ;
} else {
V_44 = V_5 -> V_56 . V_62 * V_63 ;
}
F_20 ( & V_5 -> V_56 . V_58 ) ;
return snprintf ( V_19 , V_22 , L_4 , V_44 ) ;
}
static T_3 F_31 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_55 = F_8 ( V_16 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
return snprintf ( V_19 , V_22 , L_4 ,
F_30 ( V_5 -> V_61 ,
V_5 -> V_56 . V_64 ) ) ;
}
static T_3 F_32 ( struct V_15 * V_16 , struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_55 = F_8 ( V_16 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_27 ( & V_5 -> V_56 . V_57 ) ;
F_28 ( & V_5 -> V_56 . V_58 ) ;
if ( F_3 ( V_5 -> V_2 ) )
V_44 = F_30 ( V_5 -> V_61 , V_5 -> V_56 . V_65 ) ;
else
V_44 = V_5 -> V_56 . V_65 * V_63 ;
F_20 ( & V_5 -> V_56 . V_58 ) ;
return snprintf ( V_19 , V_22 , L_4 , V_44 ) ;
}
static T_3 F_33 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_5 V_39 )
{
struct V_20 * V_55 = F_8 ( V_16 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_66 , V_67 , V_68 , V_69 , V_70 ;
T_3 V_44 ;
V_44 = F_34 ( V_19 , 0 , & V_66 ) ;
if ( V_44 )
return V_44 ;
F_27 ( & V_5 -> V_56 . V_57 ) ;
F_28 ( & V_5 -> V_56 . V_58 ) ;
if ( F_3 ( V_5 -> V_2 ) ) {
V_66 = F_35 ( V_5 -> V_61 , V_66 ) ;
V_68 = F_36 ( V_5 ) ;
V_69 = F_37 ( V_5 ) ;
V_70 = V_68 ;
} else {
V_66 /= V_63 ;
V_67 = F_4 ( V_71 ) ;
V_68 = V_5 -> V_56 . V_68 ;
V_70 = ( V_67 & 0xff ) ;
V_69 = ( ( V_67 & 0xff0000 ) >> 16 ) ;
}
if ( V_66 < V_69 || V_66 > V_68 ||
V_66 < V_5 -> V_56 . V_72 ) {
F_20 ( & V_5 -> V_56 . V_58 ) ;
return - V_31 ;
}
if ( V_66 > V_70 )
F_38 ( L_5 ,
V_66 * V_63 ) ;
if ( V_5 -> V_56 . V_62 > V_66 ) {
if ( F_3 ( V_5 -> V_2 ) )
F_39 ( V_5 -> V_2 , V_66 ) ;
else
F_40 ( V_5 -> V_2 , V_66 ) ;
}
V_5 -> V_56 . V_65 = V_66 ;
F_20 ( & V_5 -> V_56 . V_58 ) ;
return V_39 ;
}
static T_3 F_41 ( struct V_15 * V_16 , struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_55 = F_8 ( V_16 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_27 ( & V_5 -> V_56 . V_57 ) ;
F_28 ( & V_5 -> V_56 . V_58 ) ;
if ( F_3 ( V_5 -> V_2 ) )
V_44 = F_30 ( V_5 -> V_61 , V_5 -> V_56 . V_72 ) ;
else
V_44 = V_5 -> V_56 . V_72 * V_63 ;
F_20 ( & V_5 -> V_56 . V_58 ) ;
return snprintf ( V_19 , V_22 , L_4 , V_44 ) ;
}
static T_3 F_42 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_5 V_39 )
{
struct V_20 * V_55 = F_8 ( V_16 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_66 , V_67 , V_68 , V_69 ;
T_3 V_44 ;
V_44 = F_34 ( V_19 , 0 , & V_66 ) ;
if ( V_44 )
return V_44 ;
F_27 ( & V_5 -> V_56 . V_57 ) ;
F_28 ( & V_5 -> V_56 . V_58 ) ;
if ( F_3 ( V_2 ) ) {
V_66 = F_35 ( V_5 -> V_61 , V_66 ) ;
V_68 = F_36 ( V_5 ) ;
V_69 = F_37 ( V_5 ) ;
} else {
V_66 /= V_63 ;
V_67 = F_4 ( V_71 ) ;
V_68 = V_5 -> V_56 . V_68 ;
V_69 = ( ( V_67 & 0xff0000 ) >> 16 ) ;
}
if ( V_66 < V_69 || V_66 > V_68 || V_66 > V_5 -> V_56 . V_65 ) {
F_20 ( & V_5 -> V_56 . V_58 ) ;
return - V_31 ;
}
if ( V_5 -> V_56 . V_62 < V_66 ) {
if ( F_3 ( V_2 ) )
F_39 ( V_2 , V_66 ) ;
else
F_40 ( V_5 -> V_2 , V_66 ) ;
}
V_5 -> V_56 . V_72 = V_66 ;
F_20 ( & V_5 -> V_56 . V_58 ) ;
return V_39 ;
}
static T_3 F_43 ( struct V_15 * V_16 , struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_55 = F_8 ( V_16 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_66 , V_67 ;
T_3 V_44 ;
V_44 = F_44 ( & V_2 -> V_47 ) ;
if ( V_44 )
return V_44 ;
V_67 = F_4 ( V_71 ) ;
F_20 ( & V_2 -> V_47 ) ;
if ( V_18 == & V_73 ) {
V_66 = ( ( V_67 & 0x0000ff ) >> 0 ) * V_63 ;
} else if ( V_18 == & V_74 ) {
V_66 = ( ( V_67 & 0x00ff00 ) >> 8 ) * V_63 ;
} else if ( V_18 == & V_75 ) {
V_66 = ( ( V_67 & 0xff0000 ) >> 16 ) * V_63 ;
} else {
F_45 () ;
}
return snprintf ( V_19 , V_22 , L_4 , V_66 ) ;
}
static T_3 F_46 ( struct V_34 * V_35 , struct V_36 * V_37 ,
struct V_38 * V_18 , char * V_19 ,
T_4 V_76 , T_5 V_39 )
{
struct V_15 * V_16 = F_16 ( V_37 , struct V_15 , V_37 ) ;
struct V_20 * V_55 = F_8 ( V_16 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_77 V_78 ;
struct V_79 V_80 ;
T_3 V_81 = 0 ;
int V_44 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_44 = F_47 ( & V_80 , V_39 , V_76 ) ;
if ( V_44 )
return V_44 ;
V_78 . V_2 = V_2 ;
F_48 ( V_2 , & V_78 ) ;
V_44 = F_49 ( & V_80 , & V_78 ) ;
if ( V_44 )
goto V_82;
V_81 = V_39 < V_80 . V_83 ? V_39 : V_80 . V_83 ;
memcpy ( V_19 , V_80 . V_19 , V_81 ) ;
V_82:
F_50 ( & V_78 ) ;
F_51 ( & V_80 ) ;
return V_44 ? : V_81 ;
}
static T_3 F_52 ( struct V_34 * V_34 , struct V_36 * V_37 ,
struct V_38 * V_18 , char * V_19 ,
T_4 V_76 , T_5 V_39 )
{
struct V_15 * V_16 = F_16 ( V_37 , struct V_15 , V_37 ) ;
struct V_20 * V_55 = F_8 ( V_16 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
int V_44 ;
F_53 ( L_6 ) ;
V_44 = F_44 ( & V_2 -> V_47 ) ;
if ( V_44 )
return V_44 ;
F_54 ( V_2 ) ;
F_20 ( & V_2 -> V_47 ) ;
return V_39 ;
}
void F_55 ( struct V_1 * V_2 )
{
int V_44 ;
#ifdef F_56
if ( F_57 ( V_2 ) -> V_84 >= 6 ) {
V_44 = F_58 ( & V_2 -> V_85 -> V_16 -> V_37 ,
& V_86 ) ;
if ( V_44 )
F_59 ( L_7 ) ;
}
#endif
if ( F_14 ( V_2 ) ) {
V_44 = F_60 ( V_2 -> V_85 -> V_16 , & V_87 ) ;
if ( V_44 )
F_59 ( L_8 ) ;
if ( F_61 ( V_2 ) > 1 ) {
V_44 = F_60 ( V_2 -> V_85 -> V_16 ,
& V_88 ) ;
if ( V_44 )
F_59 ( L_9 ) ;
}
}
V_44 = 0 ;
if ( F_3 ( V_2 ) )
V_44 = F_62 ( & V_2 -> V_85 -> V_16 -> V_37 , V_89 ) ;
else if ( F_57 ( V_2 ) -> V_84 >= 6 )
V_44 = F_62 ( & V_2 -> V_85 -> V_16 -> V_37 , V_90 ) ;
if ( V_44 )
F_59 ( L_10 ) ;
V_44 = F_63 ( & V_2 -> V_85 -> V_16 -> V_37 ,
& V_91 ) ;
if ( V_44 )
F_59 ( L_11 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
F_65 ( & V_2 -> V_85 -> V_16 -> V_37 , & V_91 ) ;
if ( F_3 ( V_2 ) )
F_66 ( & V_2 -> V_85 -> V_16 -> V_37 , V_89 ) ;
else
F_66 ( & V_2 -> V_85 -> V_16 -> V_37 , V_90 ) ;
F_67 ( V_2 -> V_85 -> V_16 , & V_88 ) ;
F_67 ( V_2 -> V_85 -> V_16 , & V_87 ) ;
#ifdef F_56
F_68 ( & V_2 -> V_85 -> V_16 -> V_37 , & V_86 ) ;
#endif
}
