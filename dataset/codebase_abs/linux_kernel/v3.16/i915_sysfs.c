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
T_1 V_11 ;
V_11 = F_5 ( V_12 ) >>
V_13 ;
if ( ! V_11 ) {
F_6 ( ! V_11 , L_1 ) ;
V_10 = 0 ;
goto V_14;
}
V_8 = F_7 ( 30ULL * V_9 , ( T_2 ) V_11 ) ;
if ( F_5 ( V_15 ) & V_16 )
V_8 <<= 8 ;
div = 1000000ULL * V_9 ;
}
V_7 = F_5 ( V_3 ) * V_8 ;
V_10 = F_7 ( V_7 , div ) ;
V_14:
F_8 ( V_5 ) ;
return V_10 ;
}
static T_3
F_9 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
struct V_22 * V_23 = F_10 ( V_18 ) ;
return snprintf ( V_21 , V_24 , L_2 , F_2 ( V_23 -> V_2 ) ) ;
}
static T_3
F_11 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
struct V_22 * V_23 = F_12 ( V_18 ) ;
T_1 V_25 = F_1 ( V_23 -> V_2 , V_26 ) ;
return snprintf ( V_21 , V_24 , L_3 , V_25 ) ;
}
static T_3
F_13 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
struct V_22 * V_23 = F_10 ( V_18 ) ;
T_1 V_27 = F_1 ( V_23 -> V_2 , V_28 ) ;
if ( F_4 ( V_23 -> V_2 ) )
V_27 = 0 ;
return snprintf ( V_21 , V_24 , L_3 , V_27 ) ;
}
static T_3
F_14 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
struct V_22 * V_23 = F_10 ( V_18 ) ;
T_1 V_29 = F_1 ( V_23 -> V_2 , V_30 ) ;
if ( F_4 ( V_23 -> V_2 ) )
V_29 = 0 ;
return snprintf ( V_21 , V_24 , L_3 , V_29 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_4 V_31 )
{
if ( ! F_16 ( V_2 ) )
return - V_32 ;
if ( V_31 % 4 != 0 )
return - V_33 ;
if ( V_31 >= V_34 )
return - V_35 ;
return 0 ;
}
static T_3
F_17 ( struct V_36 * V_37 , struct V_38 * V_39 ,
struct V_40 * V_20 , char * V_21 ,
T_4 V_31 , T_5 V_41 )
{
struct V_17 * V_2 = F_18 ( V_39 , struct V_17 , V_39 ) ;
struct V_22 * V_23 = F_10 ( V_2 ) ;
struct V_1 * V_42 = V_23 -> V_2 ;
struct V_4 * V_5 = V_42 -> V_6 ;
int V_43 = ( int ) ( V_44 ) V_20 -> V_45 ;
int V_10 ;
V_41 = F_19 ( V_41 , 4 ) ;
V_10 = F_15 ( V_42 , V_31 ) ;
if ( V_10 )
return V_10 ;
V_41 = F_20 ( T_5 , V_34 - V_31 , V_41 ) ;
V_10 = F_21 ( V_42 ) ;
if ( V_10 )
return V_10 ;
if ( V_5 -> V_46 . V_47 [ V_43 ] )
memcpy ( V_21 ,
V_5 -> V_46 . V_47 [ V_43 ] + ( V_31 / 4 ) ,
V_41 ) ;
else
memset ( V_21 , 0 , V_41 ) ;
F_22 ( & V_42 -> V_48 ) ;
return V_41 ;
}
static T_3
F_23 ( struct V_36 * V_37 , struct V_38 * V_39 ,
struct V_40 * V_20 , char * V_21 ,
T_4 V_31 , T_5 V_41 )
{
struct V_17 * V_2 = F_18 ( V_39 , struct V_17 , V_39 ) ;
struct V_22 * V_23 = F_10 ( V_2 ) ;
struct V_1 * V_42 = V_23 -> V_2 ;
struct V_4 * V_5 = V_42 -> V_6 ;
struct V_49 * V_50 ;
T_1 * V_51 = NULL ;
int V_43 = ( int ) ( V_44 ) V_20 -> V_45 ;
int V_10 ;
if ( ! F_24 ( V_42 ) )
return - V_35 ;
V_10 = F_15 ( V_42 , V_31 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_21 ( V_42 ) ;
if ( V_10 )
return V_10 ;
if ( ! V_5 -> V_46 . V_47 [ V_43 ] ) {
V_51 = F_25 ( V_34 , V_52 ) ;
if ( ! V_51 ) {
F_22 ( & V_42 -> V_48 ) ;
return - V_53 ;
}
}
V_10 = F_26 ( V_42 ) ;
if ( V_10 ) {
F_27 ( V_51 ) ;
F_22 ( & V_42 -> V_48 ) ;
return V_10 ;
}
if ( V_51 )
V_5 -> V_46 . V_47 [ V_43 ] = V_51 ;
memcpy ( V_5 -> V_46 . V_47 [ V_43 ] + ( V_31 / 4 ) , V_21 , V_41 ) ;
F_28 (ctx, &dev_priv->context_list, link)
V_50 -> V_54 |= ( 1 << V_43 ) ;
F_22 ( & V_42 -> V_48 ) ;
return V_41 ;
}
static T_3 F_29 ( struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_22 * V_55 = F_10 ( V_18 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 ;
F_30 ( & V_5 -> V_56 . V_57 ) ;
F_3 ( V_5 ) ;
F_31 ( & V_5 -> V_56 . V_58 ) ;
if ( F_4 ( V_5 -> V_2 ) ) {
T_1 V_59 ;
V_59 = F_32 ( V_5 , V_60 ) ;
V_10 = F_33 ( V_5 , ( V_59 >> 8 ) & 0xff ) ;
} else {
V_10 = V_5 -> V_56 . V_61 * V_62 ;
}
F_22 ( & V_5 -> V_56 . V_58 ) ;
F_8 ( V_5 ) ;
return snprintf ( V_21 , V_24 , L_4 , V_10 ) ;
}
static T_3 F_34 ( struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_22 * V_55 = F_10 ( V_18 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
return snprintf ( V_21 , V_24 , L_4 ,
F_33 ( V_5 , V_5 -> V_56 . V_63 ) ) ;
}
static T_3 F_35 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
struct V_22 * V_55 = F_10 ( V_18 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 ;
F_30 ( & V_5 -> V_56 . V_57 ) ;
F_31 ( & V_5 -> V_56 . V_58 ) ;
if ( F_4 ( V_5 -> V_2 ) )
V_10 = F_33 ( V_5 , V_5 -> V_56 . V_64 ) ;
else
V_10 = V_5 -> V_56 . V_64 * V_62 ;
F_22 ( & V_5 -> V_56 . V_58 ) ;
return snprintf ( V_21 , V_24 , L_4 , V_10 ) ;
}
static T_3 F_36 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
const char * V_21 , T_5 V_41 )
{
struct V_22 * V_55 = F_10 ( V_18 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_65 ;
T_3 V_10 ;
V_10 = F_37 ( V_21 , 0 , & V_65 ) ;
if ( V_10 )
return V_10 ;
F_30 ( & V_5 -> V_56 . V_57 ) ;
F_31 ( & V_5 -> V_56 . V_58 ) ;
if ( F_4 ( V_5 -> V_2 ) )
V_65 = F_38 ( V_5 , V_65 ) ;
else
V_65 /= V_62 ;
if ( V_65 < V_5 -> V_56 . V_66 ||
V_65 > V_5 -> V_56 . V_67 ||
V_65 < V_5 -> V_56 . V_68 ) {
F_22 ( & V_5 -> V_56 . V_58 ) ;
return - V_33 ;
}
if ( V_65 > V_5 -> V_56 . V_69 )
F_39 ( L_5 ,
V_65 * V_62 ) ;
V_5 -> V_56 . V_64 = V_65 ;
if ( V_5 -> V_56 . V_61 > V_65 ) {
if ( F_4 ( V_2 ) )
F_40 ( V_2 , V_65 ) ;
else
F_41 ( V_2 , V_65 ) ;
} else if ( ! F_4 ( V_2 ) ) {
F_41 ( V_2 , V_5 -> V_56 . V_61 ) ;
}
F_22 ( & V_5 -> V_56 . V_58 ) ;
return V_41 ;
}
static T_3 F_42 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
struct V_22 * V_55 = F_10 ( V_18 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 ;
F_30 ( & V_5 -> V_56 . V_57 ) ;
F_31 ( & V_5 -> V_56 . V_58 ) ;
if ( F_4 ( V_5 -> V_2 ) )
V_10 = F_33 ( V_5 , V_5 -> V_56 . V_68 ) ;
else
V_10 = V_5 -> V_56 . V_68 * V_62 ;
F_22 ( & V_5 -> V_56 . V_58 ) ;
return snprintf ( V_21 , V_24 , L_4 , V_10 ) ;
}
static T_3 F_43 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
const char * V_21 , T_5 V_41 )
{
struct V_22 * V_55 = F_10 ( V_18 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_65 ;
T_3 V_10 ;
V_10 = F_37 ( V_21 , 0 , & V_65 ) ;
if ( V_10 )
return V_10 ;
F_30 ( & V_5 -> V_56 . V_57 ) ;
F_31 ( & V_5 -> V_56 . V_58 ) ;
if ( F_4 ( V_2 ) )
V_65 = F_38 ( V_5 , V_65 ) ;
else
V_65 /= V_62 ;
if ( V_65 < V_5 -> V_56 . V_66 ||
V_65 > V_5 -> V_56 . V_67 ||
V_65 > V_5 -> V_56 . V_64 ) {
F_22 ( & V_5 -> V_56 . V_58 ) ;
return - V_33 ;
}
V_5 -> V_56 . V_68 = V_65 ;
if ( V_5 -> V_56 . V_61 < V_65 ) {
if ( F_4 ( V_2 ) )
F_40 ( V_2 , V_65 ) ;
else
F_41 ( V_2 , V_65 ) ;
} else if ( ! F_4 ( V_2 ) ) {
F_41 ( V_2 , V_5 -> V_56 . V_61 ) ;
}
F_22 ( & V_5 -> V_56 . V_58 ) ;
return V_41 ;
}
static T_3 F_44 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
struct V_22 * V_55 = F_10 ( V_18 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_65 , V_70 ;
T_3 V_10 ;
V_10 = F_45 ( & V_2 -> V_48 ) ;
if ( V_10 )
return V_10 ;
F_3 ( V_5 ) ;
V_70 = F_5 ( V_71 ) ;
F_8 ( V_5 ) ;
F_22 ( & V_2 -> V_48 ) ;
if ( V_20 == & V_72 ) {
V_65 = ( ( V_70 & 0x0000ff ) >> 0 ) * V_62 ;
} else if ( V_20 == & V_73 ) {
V_65 = ( ( V_70 & 0x00ff00 ) >> 8 ) * V_62 ;
} else if ( V_20 == & V_74 ) {
V_65 = ( ( V_70 & 0xff0000 ) >> 16 ) * V_62 ;
} else {
F_46 () ;
}
return snprintf ( V_21 , V_24 , L_4 , V_65 ) ;
}
static T_3 F_47 ( struct V_36 * V_37 , struct V_38 * V_39 ,
struct V_40 * V_20 , char * V_21 ,
T_4 V_75 , T_5 V_41 )
{
struct V_17 * V_18 = F_18 ( V_39 , struct V_17 , V_39 ) ;
struct V_22 * V_55 = F_10 ( V_18 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_76 V_77 ;
struct V_78 V_79 ;
T_3 V_80 = 0 ;
int V_10 ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
V_10 = F_48 ( & V_79 , V_41 , V_75 ) ;
if ( V_10 )
return V_10 ;
V_77 . V_2 = V_2 ;
F_49 ( V_2 , & V_77 ) ;
V_10 = F_50 ( & V_79 , & V_77 ) ;
if ( V_10 )
goto V_14;
V_80 = V_41 < V_79 . V_81 ? V_41 : V_79 . V_81 ;
memcpy ( V_21 , V_79 . V_21 , V_80 ) ;
V_14:
F_51 ( & V_77 ) ;
F_52 ( & V_79 ) ;
return V_10 ? : V_80 ;
}
static T_3 F_53 ( struct V_36 * V_36 , struct V_38 * V_39 ,
struct V_40 * V_20 , char * V_21 ,
T_4 V_75 , T_5 V_41 )
{
struct V_17 * V_18 = F_18 ( V_39 , struct V_17 , V_39 ) ;
struct V_22 * V_55 = F_10 ( V_18 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
int V_10 ;
F_54 ( L_6 ) ;
V_10 = F_45 ( & V_2 -> V_48 ) ;
if ( V_10 )
return V_10 ;
F_55 ( V_2 ) ;
F_22 ( & V_2 -> V_48 ) ;
return V_41 ;
}
void F_56 ( struct V_1 * V_2 )
{
int V_10 ;
#ifdef F_57
if ( F_58 ( V_2 ) -> V_82 >= 6 ) {
V_10 = F_59 ( & V_2 -> V_83 -> V_18 -> V_39 ,
& V_84 ) ;
if ( V_10 )
F_60 ( L_7 ) ;
}
#endif
if ( F_16 ( V_2 ) ) {
V_10 = F_61 ( V_2 -> V_83 -> V_18 , & V_85 ) ;
if ( V_10 )
F_60 ( L_8 ) ;
if ( F_62 ( V_2 ) > 1 ) {
V_10 = F_61 ( V_2 -> V_83 -> V_18 ,
& V_86 ) ;
if ( V_10 )
F_60 ( L_9 ) ;
}
}
V_10 = 0 ;
if ( F_4 ( V_2 ) )
V_10 = F_63 ( & V_2 -> V_83 -> V_18 -> V_39 , V_87 ) ;
else if ( F_58 ( V_2 ) -> V_82 >= 6 )
V_10 = F_63 ( & V_2 -> V_83 -> V_18 -> V_39 , V_88 ) ;
if ( V_10 )
F_60 ( L_10 ) ;
V_10 = F_64 ( & V_2 -> V_83 -> V_18 -> V_39 ,
& V_89 ) ;
if ( V_10 )
F_60 ( L_11 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
F_66 ( & V_2 -> V_83 -> V_18 -> V_39 , & V_89 ) ;
if ( F_4 ( V_2 ) )
F_67 ( & V_2 -> V_83 -> V_18 -> V_39 , V_87 ) ;
else
F_67 ( & V_2 -> V_83 -> V_18 -> V_39 , V_88 ) ;
F_68 ( V_2 -> V_83 -> V_18 , & V_86 ) ;
F_68 ( V_2 -> V_83 -> V_18 , & V_85 ) ;
#ifdef F_57
F_69 ( & V_2 -> V_83 -> V_18 -> V_39 , & V_84 ) ;
#endif
}
