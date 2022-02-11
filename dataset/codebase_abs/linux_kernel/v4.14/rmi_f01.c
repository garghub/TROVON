static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
struct V_4 * V_5 )
{
T_2 V_6 [ V_7 ] ;
int V_8 ;
int V_9 = V_3 ;
bool V_10 = false ;
bool V_11 = false ;
bool V_12 = false ;
bool V_13 = false ;
bool V_14 = false ;
T_1 V_15 ;
T_2 V_16 ;
V_8 = F_2 ( V_2 , V_9 ,
V_6 , V_7 ) ;
if ( V_8 ) {
F_3 ( & V_2 -> V_17 ,
L_1 , V_8 ) ;
return V_8 ;
}
V_15 = V_9 + 17 ;
V_9 += V_7 ;
V_5 -> V_18 = V_6 [ 0 ] ;
V_5 -> V_19 = V_6 [ 1 ] & V_20 ;
V_5 -> V_21 =
V_6 [ 1 ] & V_22 ;
V_5 -> V_23 =
V_6 [ 1 ] & V_24 ;
V_11 = V_6 [ 1 ] & V_25 ;
V_12 = V_6 [ 1 ] & V_26 ;
snprintf ( V_5 -> V_27 , sizeof( V_5 -> V_27 ) , L_2 ,
V_6 [ 5 ] & V_28 ,
V_6 [ 6 ] & V_29 ,
V_6 [ 7 ] & V_30 ) ;
memcpy ( V_5 -> V_31 , & V_6 [ 11 ] ,
V_32 ) ;
V_5 -> V_31 [ V_32 ] = '\0' ;
V_5 -> V_33 =
( ( V_6 [ 2 ] & V_34 ) << 7 ) |
( V_6 [ 3 ] & V_34 ) ;
if ( V_12 )
V_9 ++ ;
if ( V_11 ) {
V_8 = F_4 ( V_2 , V_9 , V_6 ) ;
if ( V_8 ) {
F_3 ( & V_2 -> V_17 ,
L_3 , V_8 ) ;
return V_8 ;
}
V_10 = ! ! ( V_6 [ 0 ] & F_5 ( 0 ) ) ;
V_9 ++ ;
}
if ( V_10 ) {
V_8 = F_4 ( V_2 , V_9 , & V_16 ) ;
if ( V_8 ) {
F_3 ( & V_2 -> V_17 ,
L_4 , V_8 ) ;
return V_8 ;
}
V_9 ++ ;
if ( V_16 > 0 ) {
V_8 = F_4 ( V_2 , V_9 , V_6 ) ;
if ( V_8 ) {
F_3 ( & V_2 -> V_17 ,
L_5 ,
V_8 ) ;
return V_8 ;
}
V_13 = ! ! ( V_6 [ 0 ] & F_5 ( 0 ) ) ;
V_14 = ! ! ( V_6 [ 0 ] & F_5 ( 1 ) ) ;
}
if ( V_13 ) {
V_8 = F_2 ( V_2 , V_15 ,
V_6 , sizeof( V_35 ) ) ;
if ( V_8 ) {
F_3 ( & V_2 -> V_17 ,
L_6 ,
V_8 ) ;
return V_8 ;
}
V_5 -> V_36 = F_6 ( V_6 ) ;
V_15 ++ ;
}
if ( V_14 ) {
V_8 = F_2 ( V_2 , V_15 , V_6 ,
3 ) ;
if ( V_8 ) {
F_3 ( & V_2 -> V_17 ,
L_7 ,
V_8 ) ;
return V_8 ;
}
V_5 -> V_37 = V_6 [ 1 ] << 8 | V_6 [ 0 ] ;
V_5 -> V_37 += V_6 [ 2 ] * 65536 ;
}
}
return 0 ;
}
const char * F_7 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_8 ( & V_39 -> V_17 ) ;
return V_41 -> V_42 . V_31 ;
}
static T_3 F_9 ( struct V_43 * V_17 ,
struct V_44 * V_45 ,
char * V_46 )
{
struct V_47 * V_48 = F_8 ( V_17 ) ;
struct V_40 * V_41 = F_8 ( & V_48 -> V_49 -> V_17 ) ;
return F_10 ( V_46 , V_50 , L_8 ,
V_41 -> V_42 . V_18 ) ;
}
static T_3 F_11 ( struct V_43 * V_17 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_47 * V_48 = F_8 ( V_17 ) ;
struct V_40 * V_41 = F_8 ( & V_48 -> V_49 -> V_17 ) ;
return F_10 ( V_46 , V_50 , L_9 , V_41 -> V_42 . V_27 ) ;
}
static T_3 F_12 ( struct V_43 * V_17 ,
struct V_44 * V_45 ,
char * V_46 )
{
struct V_47 * V_48 = F_8 ( V_17 ) ;
struct V_40 * V_41 = F_8 ( & V_48 -> V_49 -> V_17 ) ;
return F_10 ( V_46 , V_50 , L_9 , V_41 -> V_42 . V_31 ) ;
}
static T_3 F_13 ( struct V_43 * V_17 ,
struct V_44 * V_45 ,
char * V_46 )
{
struct V_47 * V_48 = F_8 ( V_17 ) ;
struct V_40 * V_41 = F_8 ( & V_48 -> V_49 -> V_17 ) ;
return F_10 ( V_46 , V_50 , L_8 , V_41 -> V_42 . V_37 ) ;
}
static T_3 F_14 ( struct V_43 * V_17 ,
struct V_44 * V_45 ,
char * V_46 )
{
struct V_47 * V_48 = F_8 ( V_17 ) ;
struct V_40 * V_41 = F_8 ( & V_48 -> V_49 -> V_17 ) ;
T_4 V_36 = V_41 -> V_42 . V_36 ;
return F_10 ( V_46 , V_50 , L_10 ,
V_36 & 0xffff , ( V_36 >> 16 ) & 0xffff ) ;
}
static int F_15 ( struct V_43 * V_17 ,
struct V_51 * V_52 )
{
int V_53 ;
T_4 V_54 ;
V_53 = F_16 ( V_17 ,
( T_4 * ) & V_52 -> V_55 . V_56 ,
L_11 , 1 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_16 ( V_17 , & V_54 ,
L_12 , 1 ) ;
if ( V_53 )
return V_53 ;
V_52 -> V_55 . V_57 = V_54 ;
V_53 = F_16 ( V_17 , & V_54 ,
L_13 , 1 ) ;
if ( V_53 )
return V_53 ;
V_52 -> V_55 . V_58 = V_54 * 100 ;
V_53 = F_16 ( V_17 , & V_54 ,
L_14 , 1 ) ;
if ( V_53 )
return V_53 ;
V_52 -> V_55 . V_59 = V_54 / 10 ;
return 0 ;
}
static inline int F_15 ( struct V_43 * V_17 ,
struct V_51 * V_52 )
{
return - V_60 ;
}
static int F_17 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_47 * V_61 = F_8 ( & V_2 -> V_17 ) ;
struct V_51 * V_52 = F_18 ( V_2 ) ;
struct V_40 * V_41 ;
int error ;
T_1 V_62 = V_39 -> V_63 . V_64 ;
T_2 V_65 ;
T_2 V_66 ;
if ( V_39 -> V_17 . V_67 ) {
error = F_15 ( & V_39 -> V_17 , V_52 ) ;
if ( error )
return error ;
}
V_41 = F_19 ( & V_39 -> V_17 , sizeof( struct V_40 ) , V_68 ) ;
if ( ! V_41 )
return - V_69 ;
V_41 -> V_70 = V_61 -> V_70 ;
error = F_4 ( V_2 , V_39 -> V_63 . V_64 ,
& V_41 -> V_71 . V_72 ) ;
if ( error ) {
F_3 ( & V_39 -> V_17 , L_15 , error ) ;
return error ;
}
switch ( V_52 -> V_55 . V_56 ) {
case V_73 :
break;
case V_74 :
V_41 -> V_71 . V_72 &= ~ V_75 ;
break;
case V_76 :
V_41 -> V_71 . V_72 |= V_75 ;
break;
}
if ( ( V_41 -> V_71 . V_72 & V_77 ) !=
V_78 ) {
F_20 ( & V_39 -> V_17 ,
L_16 ) ;
V_41 -> V_71 . V_72 &= ~ V_77 ;
}
V_41 -> V_71 . V_72 |= V_79 ;
error = F_21 ( V_2 , V_39 -> V_63 . V_64 ,
V_41 -> V_71 . V_72 ) ;
if ( error ) {
F_3 ( & V_39 -> V_17 , L_17 , error ) ;
return error ;
}
error = F_4 ( V_2 , V_39 -> V_63 . V_80 + 1 , & V_66 ) ;
if ( error < 0 ) {
F_3 ( & V_39 -> V_17 , L_18 ) ;
return error ;
}
error = F_1 ( V_2 , V_39 -> V_63 . V_3 ,
& V_41 -> V_42 ) ;
if ( error < 0 ) {
F_3 ( & V_39 -> V_17 , L_19 ) ;
return error ;
}
F_22 ( & V_39 -> V_17 , L_20 ,
V_41 -> V_42 . V_18 == 1 ? L_21 : L_22 ,
V_41 -> V_42 . V_31 , V_41 -> V_42 . V_37 ) ;
V_62 ++ ;
V_62 += V_41 -> V_70 ;
if ( V_41 -> V_42 . V_21 ) {
V_41 -> V_81 = V_62 ;
V_62 ++ ;
if ( V_52 -> V_55 . V_59 ) {
V_41 -> V_71 . V_59 =
V_52 -> V_55 . V_59 ;
error = F_21 ( V_2 , V_41 -> V_81 ,
V_41 -> V_71 . V_59 ) ;
if ( error ) {
F_3 ( & V_39 -> V_17 ,
L_23 ,
error ) ;
return error ;
}
} else {
error = F_4 ( V_2 , V_41 -> V_81 ,
& V_41 -> V_71 . V_59 ) ;
if ( error ) {
F_3 ( & V_39 -> V_17 ,
L_24 ,
error ) ;
return error ;
}
}
V_41 -> V_82 = V_62 ;
V_62 ++ ;
if ( V_52 -> V_55 . V_57 ) {
V_41 -> V_71 . V_57 =
V_52 -> V_55 . V_57 ;
error = F_21 ( V_2 , V_41 -> V_82 ,
V_41 -> V_71 . V_57 ) ;
if ( error ) {
F_3 ( & V_39 -> V_17 ,
L_25 ,
error ) ;
return error ;
}
} else {
error = F_4 ( V_2 , V_41 -> V_82 ,
& V_41 -> V_71 . V_57 ) ;
if ( error < 0 ) {
F_3 ( & V_39 -> V_17 ,
L_26 ,
error ) ;
return error ;
}
}
}
if ( V_41 -> V_42 . V_19 )
V_62 ++ ;
if ( V_41 -> V_42 . V_23 ) {
V_41 -> V_83 = V_62 ;
V_62 ++ ;
if ( V_52 -> V_55 . V_58 ) {
V_41 -> V_71 . V_58 =
V_52 -> V_55 . V_58 ;
error = F_21 ( V_2 , V_41 -> V_83 ,
V_41 -> V_71 . V_58 ) ;
if ( error ) {
F_3 ( & V_39 -> V_17 ,
L_27 ,
error ) ;
return error ;
}
} else {
error = F_4 ( V_2 , V_41 -> V_83 ,
& V_41 -> V_71 . V_58 ) ;
if ( error ) {
F_3 ( & V_39 -> V_17 ,
L_28 ,
error ) ;
return error ;
}
}
}
error = F_4 ( V_2 , V_39 -> V_63 . V_80 , & V_65 ) ;
if ( error < 0 ) {
F_3 ( & V_39 -> V_17 ,
L_29 , error ) ;
return error ;
}
if ( F_23 ( V_65 ) ) {
F_3 ( & V_39 -> V_17 ,
L_30 ,
F_24 ( V_65 ) ) ;
return - V_84 ;
}
F_25 ( & V_39 -> V_17 , V_41 ) ;
error = F_26 ( & V_39 -> V_2 -> V_17 , & V_85 ) ;
if ( error )
F_20 ( & V_39 -> V_17 ,
L_31 , error ) ;
return 0 ;
}
static int F_27 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_8 ( & V_39 -> V_17 ) ;
int error ;
error = F_21 ( V_39 -> V_2 , V_39 -> V_63 . V_64 ,
V_41 -> V_71 . V_72 ) ;
if ( error ) {
F_3 ( & V_39 -> V_17 ,
L_32 , error ) ;
return error ;
}
if ( V_41 -> V_42 . V_21 ) {
error = F_21 ( V_39 -> V_2 , V_41 -> V_81 ,
V_41 -> V_71 . V_59 ) ;
if ( error ) {
F_3 ( & V_39 -> V_17 ,
L_33 , error ) ;
return error ;
}
error = F_28 ( V_39 -> V_2 ,
V_41 -> V_82 ,
& V_41 -> V_71 . V_57 ,
sizeof( T_2 ) ) ;
if ( error ) {
F_3 ( & V_39 -> V_17 ,
L_34 ,
error ) ;
return error ;
}
}
if ( V_41 -> V_42 . V_23 ) {
error = F_21 ( V_39 -> V_2 , V_41 -> V_83 ,
V_41 -> V_71 . V_58 ) ;
if ( error ) {
F_3 ( & V_39 -> V_17 ,
L_35 , error ) ;
return error ;
}
}
return 0 ;
}
static int F_29 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_8 ( & V_39 -> V_17 ) ;
int error ;
V_41 -> V_86 =
V_41 -> V_71 . V_72 & V_75 ;
V_41 -> V_71 . V_72 &= ~ V_75 ;
V_41 -> V_71 . V_72 &= ~ V_77 ;
if ( F_30 ( V_39 -> V_2 -> V_87 -> V_17 ) )
V_41 -> V_71 . V_72 |= V_88 ;
else
V_41 -> V_71 . V_72 |= V_89 ;
error = F_21 ( V_39 -> V_2 , V_39 -> V_63 . V_64 ,
V_41 -> V_71 . V_72 ) ;
if ( error ) {
F_3 ( & V_39 -> V_17 , L_36 , error ) ;
if ( V_41 -> V_86 )
V_41 -> V_71 . V_72 |= V_75 ;
V_41 -> V_71 . V_72 &= ~ V_77 ;
V_41 -> V_71 . V_72 |= V_78 ;
return error ;
}
return 0 ;
}
static int F_31 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_8 ( & V_39 -> V_17 ) ;
int error ;
if ( V_41 -> V_86 )
V_41 -> V_71 . V_72 |= V_75 ;
V_41 -> V_71 . V_72 &= ~ V_77 ;
V_41 -> V_71 . V_72 |= V_78 ;
error = F_21 ( V_39 -> V_2 , V_39 -> V_63 . V_64 ,
V_41 -> V_71 . V_72 ) ;
if ( error ) {
F_3 ( & V_39 -> V_17 ,
L_37 , error ) ;
return error ;
}
return 0 ;
}
static int F_32 ( struct V_38 * V_39 ,
unsigned long * V_90 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
int error ;
T_2 V_65 ;
error = F_4 ( V_2 , V_39 -> V_63 . V_80 , & V_65 ) ;
if ( error ) {
F_3 ( & V_39 -> V_17 ,
L_38 , error ) ;
return error ;
}
if ( F_33 ( V_65 ) )
F_20 ( & V_39 -> V_17 ,
L_39 ) ;
if ( F_23 ( V_65 ) ) {
F_20 ( & V_39 -> V_17 , L_40 ) ;
error = V_2 -> V_91 -> V_92 ( V_2 ) ;
if ( error ) {
F_3 ( & V_39 -> V_17 , L_41 , error ) ;
return error ;
}
}
return 0 ;
}
