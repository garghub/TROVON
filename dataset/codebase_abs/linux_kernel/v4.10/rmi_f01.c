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
if ( V_13 )
V_15 ++ ;
if ( V_14 ) {
V_8 = F_2 ( V_2 , V_15 , V_6 ,
3 ) ;
if ( V_8 ) {
F_3 ( & V_2 -> V_17 ,
L_6 ,
V_8 ) ;
return V_8 ;
}
V_5 -> V_35 = V_6 [ 1 ] << 8 | V_6 [ 0 ] ;
V_5 -> V_35 += V_6 [ 2 ] * 65536 ;
}
}
return 0 ;
}
char * F_6 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = F_7 ( & V_37 -> V_17 ) ;
return V_39 -> V_40 . V_31 ;
}
static int F_8 ( struct V_41 * V_17 ,
struct V_42 * V_43 )
{
int V_44 ;
T_3 V_45 ;
V_44 = F_9 ( V_17 ,
( T_3 * ) & V_43 -> V_46 . V_47 ,
L_7 , 1 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_9 ( V_17 , & V_45 ,
L_8 , 1 ) ;
if ( V_44 )
return V_44 ;
V_43 -> V_46 . V_48 = V_45 ;
V_44 = F_9 ( V_17 , & V_45 ,
L_9 , 1 ) ;
if ( V_44 )
return V_44 ;
V_43 -> V_46 . V_49 = V_45 * 100 ;
V_44 = F_9 ( V_17 , & V_45 ,
L_10 , 1 ) ;
if ( V_44 )
return V_44 ;
V_43 -> V_46 . V_50 = V_45 / 10 ;
return 0 ;
}
static inline int F_8 ( struct V_41 * V_17 ,
struct V_42 * V_43 )
{
return - V_51 ;
}
static int F_10 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_52 * V_53 = F_7 ( & V_2 -> V_17 ) ;
struct V_42 * V_43 = F_11 ( V_2 ) ;
struct V_38 * V_39 ;
int error ;
T_1 V_54 = V_37 -> V_55 . V_56 ;
T_2 V_57 ;
T_2 V_58 ;
if ( V_37 -> V_17 . V_59 ) {
error = F_8 ( & V_37 -> V_17 , V_43 ) ;
if ( error )
return error ;
}
V_39 = F_12 ( & V_37 -> V_17 , sizeof( struct V_38 ) , V_60 ) ;
if ( ! V_39 )
return - V_61 ;
V_39 -> V_62 = V_53 -> V_62 ;
error = F_4 ( V_2 , V_37 -> V_55 . V_56 ,
& V_39 -> V_63 . V_64 ) ;
if ( error ) {
F_3 ( & V_37 -> V_17 , L_11 , error ) ;
return error ;
}
switch ( V_43 -> V_46 . V_47 ) {
case V_65 :
break;
case V_66 :
V_39 -> V_63 . V_64 &= ~ V_67 ;
break;
case V_68 :
V_39 -> V_63 . V_64 |= V_67 ;
break;
}
if ( ( V_39 -> V_63 . V_64 & V_69 ) !=
V_70 ) {
F_13 ( & V_37 -> V_17 ,
L_12 ) ;
V_39 -> V_63 . V_64 &= ~ V_69 ;
}
V_39 -> V_63 . V_64 |= V_71 ;
error = F_14 ( V_2 , V_37 -> V_55 . V_56 ,
V_39 -> V_63 . V_64 ) ;
if ( error ) {
F_3 ( & V_37 -> V_17 , L_13 , error ) ;
return error ;
}
error = F_4 ( V_2 , V_37 -> V_55 . V_72 + 1 , & V_58 ) ;
if ( error < 0 ) {
F_3 ( & V_37 -> V_17 , L_14 ) ;
return error ;
}
error = F_1 ( V_2 , V_37 -> V_55 . V_3 ,
& V_39 -> V_40 ) ;
if ( error < 0 ) {
F_3 ( & V_37 -> V_17 , L_15 ) ;
return error ;
}
F_15 ( & V_37 -> V_17 , L_16 ,
V_39 -> V_40 . V_18 == 1 ? L_17 : L_18 ,
V_39 -> V_40 . V_31 , V_39 -> V_40 . V_35 ) ;
V_54 ++ ;
V_54 += V_39 -> V_62 ;
if ( V_39 -> V_40 . V_21 ) {
V_39 -> V_73 = V_54 ;
V_54 ++ ;
if ( V_43 -> V_46 . V_50 ) {
V_39 -> V_63 . V_50 =
V_43 -> V_46 . V_50 ;
error = F_14 ( V_2 , V_39 -> V_73 ,
V_39 -> V_63 . V_50 ) ;
if ( error ) {
F_3 ( & V_37 -> V_17 ,
L_19 ,
error ) ;
return error ;
}
} else {
error = F_4 ( V_2 , V_39 -> V_73 ,
& V_39 -> V_63 . V_50 ) ;
if ( error ) {
F_3 ( & V_37 -> V_17 ,
L_20 ,
error ) ;
return error ;
}
}
V_39 -> V_74 = V_54 ;
V_54 ++ ;
if ( V_43 -> V_46 . V_48 ) {
V_39 -> V_63 . V_48 =
V_43 -> V_46 . V_48 ;
error = F_14 ( V_2 , V_39 -> V_74 ,
V_39 -> V_63 . V_48 ) ;
if ( error ) {
F_3 ( & V_37 -> V_17 ,
L_21 ,
error ) ;
return error ;
}
} else {
error = F_4 ( V_2 , V_39 -> V_74 ,
& V_39 -> V_63 . V_48 ) ;
if ( error < 0 ) {
F_3 ( & V_37 -> V_17 ,
L_22 ,
error ) ;
return error ;
}
}
}
if ( V_39 -> V_40 . V_19 )
V_54 ++ ;
if ( V_39 -> V_40 . V_23 ) {
V_39 -> V_75 = V_54 ;
V_54 ++ ;
if ( V_43 -> V_46 . V_49 ) {
V_39 -> V_63 . V_49 =
V_43 -> V_46 . V_49 ;
error = F_14 ( V_2 , V_39 -> V_75 ,
V_39 -> V_63 . V_49 ) ;
if ( error ) {
F_3 ( & V_37 -> V_17 ,
L_23 ,
error ) ;
return error ;
}
} else {
error = F_4 ( V_2 , V_39 -> V_75 ,
& V_39 -> V_63 . V_49 ) ;
if ( error ) {
F_3 ( & V_37 -> V_17 ,
L_24 ,
error ) ;
return error ;
}
}
}
error = F_4 ( V_2 , V_37 -> V_55 . V_72 , & V_57 ) ;
if ( error < 0 ) {
F_3 ( & V_37 -> V_17 ,
L_25 , error ) ;
return error ;
}
if ( F_16 ( V_57 ) ) {
F_3 ( & V_37 -> V_17 ,
L_26 ,
F_17 ( V_57 ) ) ;
return - V_76 ;
}
F_18 ( & V_37 -> V_17 , V_39 ) ;
return 0 ;
}
static int F_19 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = F_7 ( & V_37 -> V_17 ) ;
int error ;
error = F_14 ( V_37 -> V_2 , V_37 -> V_55 . V_56 ,
V_39 -> V_63 . V_64 ) ;
if ( error ) {
F_3 ( & V_37 -> V_17 ,
L_27 , error ) ;
return error ;
}
if ( V_39 -> V_40 . V_21 ) {
error = F_14 ( V_37 -> V_2 , V_39 -> V_73 ,
V_39 -> V_63 . V_50 ) ;
if ( error ) {
F_3 ( & V_37 -> V_17 ,
L_28 , error ) ;
return error ;
}
error = F_20 ( V_37 -> V_2 ,
V_39 -> V_74 ,
& V_39 -> V_63 . V_48 ,
sizeof( T_2 ) ) ;
if ( error ) {
F_3 ( & V_37 -> V_17 ,
L_29 ,
error ) ;
return error ;
}
}
if ( V_39 -> V_40 . V_23 ) {
error = F_14 ( V_37 -> V_2 , V_39 -> V_75 ,
V_39 -> V_63 . V_49 ) ;
if ( error ) {
F_3 ( & V_37 -> V_17 ,
L_30 , error ) ;
return error ;
}
}
return 0 ;
}
static int F_21 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = F_7 ( & V_37 -> V_17 ) ;
int error ;
V_39 -> V_77 =
V_39 -> V_63 . V_64 & V_67 ;
V_39 -> V_63 . V_64 &= ~ V_67 ;
V_39 -> V_63 . V_64 &= ~ V_69 ;
if ( F_22 ( V_37 -> V_2 -> V_78 -> V_17 ) )
V_39 -> V_63 . V_64 |= V_79 ;
else
V_39 -> V_63 . V_64 |= V_80 ;
error = F_14 ( V_37 -> V_2 , V_37 -> V_55 . V_56 ,
V_39 -> V_63 . V_64 ) ;
if ( error ) {
F_3 ( & V_37 -> V_17 , L_31 , error ) ;
if ( V_39 -> V_77 )
V_39 -> V_63 . V_64 |= V_67 ;
V_39 -> V_63 . V_64 &= ~ V_69 ;
V_39 -> V_63 . V_64 |= V_70 ;
return error ;
}
return 0 ;
}
static int F_23 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = F_7 ( & V_37 -> V_17 ) ;
int error ;
if ( V_39 -> V_77 )
V_39 -> V_63 . V_64 |= V_67 ;
V_39 -> V_63 . V_64 &= ~ V_69 ;
V_39 -> V_63 . V_64 |= V_70 ;
error = F_14 ( V_37 -> V_2 , V_37 -> V_55 . V_56 ,
V_39 -> V_63 . V_64 ) ;
if ( error ) {
F_3 ( & V_37 -> V_17 ,
L_32 , error ) ;
return error ;
}
return 0 ;
}
static int F_24 ( struct V_36 * V_37 ,
unsigned long * V_81 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
int error ;
T_2 V_57 ;
error = F_4 ( V_2 , V_37 -> V_55 . V_72 , & V_57 ) ;
if ( error ) {
F_3 ( & V_37 -> V_17 ,
L_33 , error ) ;
return error ;
}
if ( F_25 ( V_57 ) )
F_13 ( & V_37 -> V_17 ,
L_34 ) ;
if ( F_16 ( V_57 ) ) {
F_13 ( & V_37 -> V_17 , L_35 ) ;
error = V_2 -> V_82 -> V_83 ( V_2 ) ;
if ( error ) {
F_3 ( & V_37 -> V_17 , L_36 , error ) ;
return error ;
}
}
return 0 ;
}
