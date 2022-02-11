struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 = F_2 ( V_4 , V_2 ) ;
if ( V_3 ) {
F_3 ( & V_3 -> V_5 ) ;
F_4 ( & V_3 -> V_6 ) ;
V_3 -> V_7 = V_8 ;
F_5 ( & V_3 -> V_9 ) ;
F_6 ( & V_3 -> V_10 ) ;
}
return V_3 ;
}
void F_7 ( struct V_1 * V_3 )
{
if ( V_3 ) {
F_8 ( ! F_9 ( & V_3 -> V_5 ) ) ;
F_10 ( V_4 , V_3 ) ;
}
}
void F_11 ( T_2 * V_11 , const T_2 * V_12 )
{
const T_3 V_13 = 0x00DB2777 ;
T_3 V_14 = 0 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < 8 ; V_15 ++ ) {
int V_16 ;
for ( V_16 = 7 ; V_16 >= 0 ; V_16 -- ) {
V_14 <<= 1 ;
if ( ( 1 << V_16 ) & V_12 [ V_15 ] ) {
if ( ! ( V_14 & 0x01000000 ) )
V_14 ^= V_13 ;
} else if ( V_14 & 0x01000000 )
V_14 ^= V_13 ;
}
}
V_11 [ 0 ] = ( V_14 >> 16 ) & 0xFF ;
V_11 [ 1 ] = ( V_14 >> 8 ) & 0xFF ;
V_11 [ 2 ] = V_14 & 0xFF ;
}
void F_12 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_13 ( V_18 ) ;
struct V_21 * V_22 = V_20 -> V_22 ;
F_14 ( V_23 , & V_22 -> V_24 ) ;
}
int F_15 ( struct V_21 * V_25 )
{
int error = 0 ;
F_16 ( & V_25 -> V_26 ) ;
F_4 ( & V_25 -> V_27 ) ;
F_11 ( V_25 -> V_28 , V_25 -> V_12 ) ;
if ( V_25 -> V_29 == 0 )
V_25 -> V_29 = 1 ;
else if ( V_25 -> V_29 == - 1 )
V_25 -> V_29 = 128 ;
F_17 ( V_30 , & V_25 -> V_31 ) ;
F_4 ( & V_25 -> V_32 ) ;
F_16 ( & V_25 -> V_33 ) ;
F_3 ( & V_25 -> V_34 ) ;
error = F_18 ( V_25 ) ;
if ( error ) {
F_19 ( V_35 L_1 , error ) ;
return error ;
}
error = F_20 ( V_25 ) ;
if ( error ) {
F_19 ( V_35 L_2 , error ) ;
goto V_36;
}
error = F_21 ( V_25 ) ;
if ( error ) {
F_19 ( V_35 L_3 , error ) ;
goto V_37;
}
if ( V_25 -> V_38 > 1 ) {
error = F_22 ( V_25 ) ;
if ( error ) {
F_19 ( V_35 L_4
L_5 , error ) ;
V_25 -> V_38 = 1 ;
}
}
F_3 ( & V_25 -> V_39 ) ;
F_3 ( & V_25 -> V_40 ) ;
return 0 ;
V_37:
F_23 ( V_25 ) ;
V_36:
return error ;
}
int F_24 ( struct V_21 * V_25 )
{
F_25 ( & V_25 -> V_33 ) ;
F_26 ( & V_25 -> V_32 ) ;
F_14 ( V_30 , & V_25 -> V_31 ) ;
F_27 ( & V_25 -> V_32 ) ;
F_28 ( V_25 ) ;
F_29 ( & V_25 -> V_33 ) ;
F_23 ( V_25 ) ;
F_25 ( & V_25 -> V_33 ) ;
F_28 ( V_25 ) ;
F_29 ( & V_25 -> V_33 ) ;
if ( V_25 -> V_38 > 1 ) {
F_30 ( V_25 ) ;
V_25 -> V_38 = 1 ;
}
return 0 ;
}
static int F_31 ( struct V_41 * V_42 )
{
if ( F_32 ( V_42 ) ) {
struct V_43 * V_44 = F_33 ( V_42 -> V_45 . V_46 ) ;
struct V_21 * V_25 = F_34 ( V_44 ) ;
struct V_47 * V_48 = V_25 -> V_41 [ V_42 -> V_49 ] ;
struct V_50 * V_15 =
F_35 ( V_25 -> V_51 . V_44 -> V_52 ) ;
return V_15 -> V_53 -> V_54 ( V_48 , V_55 , NULL ) ;
}
return F_36 ( V_42 ) ;
}
int F_37 ( struct V_47 * V_48 )
{
struct V_56 * V_45 = NULL ;
if ( V_48 -> V_57 )
V_45 = V_48 -> V_57 -> V_58 ;
if ( V_45 )
V_45 = F_38 ( V_45 -> V_59 ) ;
if ( V_45 && F_39 ( V_45 ) ) {
F_40 ( V_45 ) ;
F_41 ( V_45 ) ;
return 0 ;
}
return - V_60 ;
}
static int F_42 ( struct V_41 * V_42 , int V_61 )
{
enum V_62 V_63 ;
if ( V_61 )
V_63 = V_64 ;
else
V_63 = V_65 ;
if ( F_32 ( V_42 ) ) {
struct V_43 * V_44 = F_33 ( V_42 -> V_45 . V_46 ) ;
struct V_21 * V_25 = F_34 ( V_44 ) ;
struct V_47 * V_48 = V_25 -> V_41 [ V_42 -> V_49 ] ;
struct V_50 * V_15 =
F_35 ( V_25 -> V_51 . V_44 -> V_52 ) ;
if ( ! V_61 && F_37 ( V_48 ) == 0 )
return 0 ;
return V_15 -> V_53 -> V_54 ( V_48 , V_63 , NULL ) ;
} else {
struct V_66 * V_59 = F_43 ( V_42 -> V_45 . V_46 ) ;
struct V_56 * V_67 = F_38 ( V_59 ) ;
struct V_56 * V_68 = F_44 ( V_67 , V_42 -> V_49 ) ;
if ( V_68 && ! V_61 ) {
F_40 ( V_68 ) ;
F_41 ( V_68 ) ;
return 0 ;
} else
return F_45 ( V_67 , V_42 -> V_49 , V_63 , NULL ) ;
}
}
static int F_46 ( struct V_41 * V_42 , int V_69 )
{
int V_70 ;
enum V_62 V_71 ;
if ( V_69 )
V_71 = V_65 ;
else
V_71 = V_72 ;
if ( F_32 ( V_42 ) ) {
struct V_43 * V_44 = F_33 ( V_42 -> V_45 . V_46 ) ;
struct V_21 * V_25 = F_34 ( V_44 ) ;
struct V_47 * V_48 = V_25 -> V_41 [ V_42 -> V_49 ] ;
struct V_50 * V_15 =
F_35 ( V_25 -> V_51 . V_44 -> V_52 ) ;
if ( V_69 )
V_70 = F_42 ( V_42 , 0 ) ;
else
V_70 = V_15 -> V_53 -> V_54 ( V_48 , V_71 , NULL ) ;
} else {
struct V_66 * V_59 = F_43 ( V_42 -> V_45 . V_46 ) ;
struct V_56 * V_67 = F_38 ( V_59 ) ;
if ( V_69 )
V_70 = F_42 ( V_42 , 0 ) ;
else
V_70 = F_45 ( V_67 , V_42 -> V_49 , V_71 , NULL ) ;
}
return V_70 ;
}
int F_47 ( struct V_41 * V_42 , int V_61 )
{
int V_70 ;
enum V_62 V_63 ;
if ( ! V_42 -> V_73 )
return - V_60 ;
if ( V_61 )
V_63 = V_64 ;
else
V_63 = V_65 ;
if ( F_32 ( V_42 ) ) {
struct V_43 * V_44 = F_33 ( V_42 -> V_45 . V_46 ) ;
struct V_21 * V_25 = F_34 ( V_44 ) ;
struct V_47 * V_48 = V_25 -> V_41 [ V_42 -> V_49 ] ;
struct V_50 * V_15 =
F_35 ( V_25 -> V_51 . V_44 -> V_52 ) ;
V_70 = V_15 -> V_53 -> V_54 ( V_48 , V_63 , NULL ) ;
} else {
struct V_66 * V_59 = F_43 ( V_42 -> V_45 . V_46 ) ;
struct V_56 * V_67 = F_38 ( V_59 ) ;
V_70 = F_45 ( V_67 , V_42 -> V_49 , V_63 , NULL ) ;
}
return V_70 ;
}
int F_48 ( struct V_41 * V_42 ,
struct V_74 * V_75 )
{
int V_70 ;
if ( ( V_75 -> V_76 &&
V_75 -> V_76 > V_42 -> V_77 ) ||
( V_75 -> V_77 &&
V_75 -> V_77 < V_42 -> V_76 ) )
return - V_78 ;
if ( V_75 -> V_76 &&
V_75 -> V_76 < V_42 -> V_79 )
V_75 -> V_76 = V_42 -> V_79 ;
if ( V_75 -> V_77 &&
V_75 -> V_77 > V_42 -> V_80 )
V_75 -> V_77 = V_42 -> V_80 ;
if ( F_32 ( V_42 ) ) {
struct V_43 * V_44 = F_33 ( V_42 -> V_45 . V_46 ) ;
struct V_21 * V_25 = F_34 ( V_44 ) ;
struct V_47 * V_48 = V_25 -> V_41 [ V_42 -> V_49 ] ;
struct V_50 * V_15 =
F_35 ( V_25 -> V_51 . V_44 -> V_52 ) ;
V_70 = V_15 -> V_53 -> V_54 ( V_48 , V_81 ,
V_75 ) ;
} else {
struct V_66 * V_59 = F_43 ( V_42 -> V_45 . V_46 ) ;
struct V_56 * V_67 = F_38 ( V_59 ) ;
V_70 = F_45 ( V_67 , V_42 -> V_49 ,
V_65 , V_75 ) ;
}
return V_70 ;
}
static void F_49 ( struct V_41 * V_42 )
{
F_50 ( V_42 -> V_82 ) ;
V_42 -> V_82 = NULL ;
}
static void F_51 ( struct V_17 * V_18 )
{
struct V_83 * V_84 = F_52 ( V_18 , F_53 ( * V_84 ) , V_85 . V_18 ) ;
V_84 -> V_86 = F_42 ( V_84 -> V_42 , V_84 -> V_61 ) ;
}
static void F_54 ( struct V_17 * V_18 )
{
struct V_83 * V_84 = F_52 ( V_18 , F_53 ( * V_84 ) , V_87 . V_18 ) ;
V_84 -> V_88 = F_46 ( V_84 -> V_42 , V_84 -> V_69 ) ;
}
static int F_55 ( struct V_41 * V_42 )
{
struct V_83 * V_84 = F_56 ( sizeof( * V_84 ) , V_89 ) ;
if ( ! V_84 )
return - V_90 ;
F_16 ( & V_84 -> V_91 ) ;
F_57 ( & V_84 -> V_85 , F_51 ) ;
F_57 ( & V_84 -> V_87 , F_54 ) ;
V_84 -> V_42 = V_42 ;
V_42 -> V_82 = V_84 ;
return 0 ;
}
static int F_58 ( struct V_41 * V_42 , int V_61 )
{
struct V_43 * V_44 = F_33 ( V_42 -> V_45 . V_46 ) ;
struct V_21 * V_22 = F_34 ( V_44 ) ;
struct V_83 * V_84 = V_42 -> V_82 ;
int V_92 ;
if ( ! V_84 )
return - V_90 ;
F_25 ( & V_84 -> V_91 ) ;
V_84 -> V_86 = 0 ;
V_84 -> V_61 = V_61 ;
F_26 ( & V_22 -> V_32 ) ;
F_59 ( V_22 , & V_84 -> V_85 ) ;
F_27 ( & V_22 -> V_32 ) ;
V_92 = F_60 ( V_22 ) ;
if ( V_92 == 0 )
V_92 = V_84 -> V_86 ;
F_29 ( & V_84 -> V_91 ) ;
return V_92 ;
}
static int F_61 ( struct V_41 * V_42 , int V_69 )
{
struct V_43 * V_44 = F_33 ( V_42 -> V_45 . V_46 ) ;
struct V_21 * V_22 = F_34 ( V_44 ) ;
struct V_83 * V_84 = V_42 -> V_82 ;
int V_92 ;
if ( ! V_84 )
return - V_90 ;
F_25 ( & V_84 -> V_91 ) ;
V_84 -> V_88 = 0 ;
V_84 -> V_69 = V_69 ;
F_26 ( & V_22 -> V_32 ) ;
F_59 ( V_22 , & V_84 -> V_87 ) ;
F_27 ( & V_22 -> V_32 ) ;
V_92 = F_60 ( V_22 ) ;
if ( V_92 == 0 )
V_92 = V_84 -> V_88 ;
F_29 ( & V_84 -> V_91 ) ;
return V_92 ;
}
struct V_93 *
F_62 ( struct V_94 * V_53 )
{
struct V_93 * V_95 = F_63 ( & V_96 ) ;
struct V_50 * V_15 ;
if ( ! V_95 )
return V_95 ;
V_15 = F_35 ( V_95 ) ;
V_15 -> V_53 = V_53 ;
V_95 -> V_97 = 1 ;
V_95 -> V_98 = V_99 ;
V_95 -> V_100 = V_101 ;
return V_95 ;
}
void F_64 ( struct V_93 * V_95 )
{
F_65 ( V_95 ) ;
}
static int T_4 F_66 ( void )
{
V_4 = F_67 ( V_1 , V_102 ) ;
if ( ! V_4 )
return - V_90 ;
return 0 ;
}
static void T_5 F_68 ( void )
{
F_69 ( V_4 ) ;
}
