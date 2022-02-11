struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 = F_2 ( V_4 , V_2 ) ;
if ( V_3 ) {
F_3 ( & V_3 -> V_5 ) ;
F_4 ( & V_3 -> V_6 ) ;
V_3 -> V_7 = V_8 ;
}
return V_3 ;
}
struct V_1 * F_5 ( T_1 V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( sizeof( * V_10 ) , V_2 ) ;
if ( ! V_3 || ! V_10 ) {
if ( V_3 )
F_7 ( V_4 , V_3 ) ;
F_8 ( V_10 ) ;
return NULL ;
}
V_3 -> V_11 = V_10 ;
F_9 ( & V_10 -> V_12 ) ;
F_10 ( & V_10 -> V_13 ) ;
return V_3 ;
}
void F_11 ( struct V_1 * V_3 )
{
if ( V_3 ) {
F_12 ( ! F_13 ( & V_3 -> V_5 ) ) ;
F_8 ( V_3 -> V_11 ) ;
F_7 ( V_4 , V_3 ) ;
}
}
void F_14 ( T_2 * V_14 , const T_2 * V_15 )
{
const T_3 V_16 = 0x00DB2777 ;
T_3 V_17 = 0 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
int V_19 ;
for ( V_19 = 7 ; V_19 >= 0 ; V_19 -- ) {
V_17 <<= 1 ;
if ( ( 1 << V_19 ) & V_15 [ V_18 ] ) {
if ( ! ( V_17 & 0x01000000 ) )
V_17 ^= V_16 ;
} else if ( V_17 & 0x01000000 )
V_17 ^= V_16 ;
}
}
V_14 [ 0 ] = ( V_17 >> 16 ) & 0xFF ;
V_14 [ 1 ] = ( V_17 >> 8 ) & 0xFF ;
V_14 [ 2 ] = V_17 & 0xFF ;
}
void F_15 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_16 ( V_21 ) ;
struct V_24 * V_25 = V_23 -> V_25 ;
F_17 ( V_26 , & V_25 -> V_27 ) ;
}
int F_18 ( struct V_24 * V_28 )
{
int error = 0 ;
F_19 ( & V_28 -> V_29 ) ;
F_4 ( & V_28 -> V_30 ) ;
F_14 ( V_28 -> V_31 , V_28 -> V_15 ) ;
if ( V_28 -> V_32 == 0 )
V_28 -> V_32 = 1 ;
else if ( V_28 -> V_32 == - 1 )
V_28 -> V_32 = 128 ;
F_20 ( V_33 , & V_28 -> V_34 ) ;
F_4 ( & V_28 -> V_35 ) ;
F_19 ( & V_28 -> V_36 ) ;
F_21 ( & V_28 -> V_37 ) ;
F_3 ( & V_28 -> V_38 ) ;
F_3 ( & V_28 -> V_39 ) ;
error = F_22 ( V_28 ) ;
if ( error ) {
F_23 ( V_40 L_1 , error ) ;
return error ;
}
error = F_24 ( V_28 ) ;
if ( error ) {
F_23 ( V_40 L_2 , error ) ;
goto V_41;
}
error = F_25 ( V_28 ) ;
if ( error ) {
F_23 ( V_40 L_3 , error ) ;
goto V_42;
}
if ( V_28 -> V_43 > 1 ) {
error = F_26 ( V_28 ) ;
if ( error ) {
F_23 ( V_40 L_4
L_5 , error ) ;
V_28 -> V_43 = 1 ;
}
}
F_3 ( & V_28 -> V_44 ) ;
F_3 ( & V_28 -> V_45 ) ;
return 0 ;
V_42:
F_27 ( V_28 ) ;
V_41:
return error ;
}
int F_28 ( struct V_24 * V_28 )
{
F_29 ( & V_28 -> V_36 ) ;
F_30 ( & V_28 -> V_35 ) ;
F_17 ( V_33 , & V_28 -> V_34 ) ;
F_31 ( & V_28 -> V_35 ) ;
F_32 ( V_28 ) ;
F_33 ( & V_28 -> V_36 ) ;
F_27 ( V_28 ) ;
F_29 ( & V_28 -> V_36 ) ;
F_32 ( V_28 ) ;
F_33 ( & V_28 -> V_36 ) ;
if ( V_28 -> V_43 > 1 ) {
F_34 ( V_28 ) ;
V_28 -> V_43 = 1 ;
}
return 0 ;
}
static int F_35 ( struct V_46 * V_47 )
{
if ( F_36 ( V_47 ) ) {
struct V_48 * V_49 = F_37 ( V_47 -> V_50 . V_51 ) ;
struct V_24 * V_28 = F_38 ( V_49 ) ;
struct V_52 * V_53 = V_28 -> V_46 [ V_47 -> V_54 ] ;
struct V_55 * V_18 =
F_39 ( V_28 -> V_56 . V_49 -> V_57 ) ;
return V_18 -> V_58 -> V_59 ( V_53 , V_60 , NULL ) ;
}
return F_40 ( V_47 ) ;
}
int F_41 ( struct V_52 * V_53 )
{
struct V_61 * V_50 = NULL ;
if ( V_53 -> V_62 )
V_50 = V_53 -> V_62 -> V_63 ;
if ( V_50 )
V_50 = F_42 ( V_50 -> V_64 ) ;
if ( V_50 && F_43 ( V_50 ) ) {
F_44 ( V_50 ) ;
F_45 ( V_50 ) ;
return 0 ;
}
return - V_65 ;
}
static int F_46 ( struct V_46 * V_47 , int V_66 )
{
enum V_67 V_68 ;
if ( V_66 )
V_68 = V_69 ;
else
V_68 = V_70 ;
if ( F_36 ( V_47 ) ) {
struct V_48 * V_49 = F_37 ( V_47 -> V_50 . V_51 ) ;
struct V_24 * V_28 = F_38 ( V_49 ) ;
struct V_52 * V_53 = V_28 -> V_46 [ V_47 -> V_54 ] ;
struct V_55 * V_18 =
F_39 ( V_28 -> V_56 . V_49 -> V_57 ) ;
if ( ! V_66 && F_41 ( V_53 ) == 0 )
return 0 ;
return V_18 -> V_58 -> V_59 ( V_53 , V_68 , NULL ) ;
} else {
struct V_71 * V_64 = F_47 ( V_47 -> V_50 . V_51 ) ;
struct V_61 * V_72 = F_42 ( V_64 ) ;
struct V_61 * V_73 = F_48 ( V_72 , V_47 -> V_54 ) ;
if ( V_73 && ! V_66 ) {
F_44 ( V_73 ) ;
F_45 ( V_73 ) ;
return 0 ;
} else
return F_49 ( V_72 , V_47 -> V_54 , V_68 , NULL ) ;
}
}
static int F_50 ( struct V_46 * V_47 , int V_74 )
{
int V_75 ;
enum V_67 V_76 ;
if ( V_74 )
V_76 = V_70 ;
else
V_76 = V_77 ;
if ( F_36 ( V_47 ) ) {
struct V_48 * V_49 = F_37 ( V_47 -> V_50 . V_51 ) ;
struct V_24 * V_28 = F_38 ( V_49 ) ;
struct V_52 * V_53 = V_28 -> V_46 [ V_47 -> V_54 ] ;
struct V_55 * V_18 =
F_39 ( V_28 -> V_56 . V_49 -> V_57 ) ;
if ( V_74 )
V_75 = F_46 ( V_47 , 0 ) ;
else
V_75 = V_18 -> V_58 -> V_59 ( V_53 , V_76 , NULL ) ;
} else {
struct V_71 * V_64 = F_47 ( V_47 -> V_50 . V_51 ) ;
struct V_61 * V_72 = F_42 ( V_64 ) ;
if ( V_74 )
V_75 = F_46 ( V_47 , 0 ) ;
else
V_75 = F_49 ( V_72 , V_47 -> V_54 , V_76 , NULL ) ;
}
return V_75 ;
}
int F_51 ( struct V_46 * V_47 , int V_66 )
{
int V_75 ;
enum V_67 V_68 ;
if ( ! V_47 -> V_78 )
return - V_65 ;
if ( V_66 )
V_68 = V_69 ;
else
V_68 = V_70 ;
if ( F_36 ( V_47 ) ) {
struct V_48 * V_49 = F_37 ( V_47 -> V_50 . V_51 ) ;
struct V_24 * V_28 = F_38 ( V_49 ) ;
struct V_52 * V_53 = V_28 -> V_46 [ V_47 -> V_54 ] ;
struct V_55 * V_18 =
F_39 ( V_28 -> V_56 . V_49 -> V_57 ) ;
V_75 = V_18 -> V_58 -> V_59 ( V_53 , V_68 , NULL ) ;
} else {
struct V_71 * V_64 = F_47 ( V_47 -> V_50 . V_51 ) ;
struct V_61 * V_72 = F_42 ( V_64 ) ;
V_75 = F_49 ( V_72 , V_47 -> V_54 , V_68 , NULL ) ;
}
return V_75 ;
}
int F_52 ( struct V_46 * V_47 ,
struct V_79 * V_80 )
{
int V_75 ;
if ( ( V_80 -> V_81 &&
V_80 -> V_81 > V_47 -> V_82 ) ||
( V_80 -> V_82 &&
V_80 -> V_82 < V_47 -> V_81 ) )
return - V_83 ;
if ( V_80 -> V_81 &&
V_80 -> V_81 < V_47 -> V_84 )
V_80 -> V_81 = V_47 -> V_84 ;
if ( V_80 -> V_82 &&
V_80 -> V_82 > V_47 -> V_85 )
V_80 -> V_82 = V_47 -> V_85 ;
if ( F_36 ( V_47 ) ) {
struct V_48 * V_49 = F_37 ( V_47 -> V_50 . V_51 ) ;
struct V_24 * V_28 = F_38 ( V_49 ) ;
struct V_52 * V_53 = V_28 -> V_46 [ V_47 -> V_54 ] ;
struct V_55 * V_18 =
F_39 ( V_28 -> V_56 . V_49 -> V_57 ) ;
V_75 = V_18 -> V_58 -> V_59 ( V_53 , V_86 ,
V_80 ) ;
} else {
struct V_71 * V_64 = F_47 ( V_47 -> V_50 . V_51 ) ;
struct V_61 * V_72 = F_42 ( V_64 ) ;
V_75 = F_49 ( V_72 , V_47 -> V_54 ,
V_70 , V_80 ) ;
}
return V_75 ;
}
static void F_53 ( struct V_46 * V_47 )
{
F_8 ( V_47 -> V_87 ) ;
V_47 -> V_87 = NULL ;
}
static void F_54 ( struct V_20 * V_21 )
{
struct V_88 * V_89 = F_55 ( V_21 , F_56 ( * V_89 ) , V_90 . V_21 ) ;
V_89 -> V_91 = F_46 ( V_89 -> V_47 , V_89 -> V_66 ) ;
}
static void F_57 ( struct V_20 * V_21 )
{
struct V_88 * V_89 = F_55 ( V_21 , F_56 ( * V_89 ) , V_92 . V_21 ) ;
V_89 -> V_93 = F_50 ( V_89 -> V_47 , V_89 -> V_74 ) ;
}
static int F_58 ( struct V_46 * V_47 )
{
struct V_88 * V_89 = F_59 ( sizeof( * V_89 ) , V_94 ) ;
if ( ! V_89 )
return - V_95 ;
F_19 ( & V_89 -> V_96 ) ;
F_60 ( & V_89 -> V_90 , F_54 ) ;
F_60 ( & V_89 -> V_92 , F_57 ) ;
V_89 -> V_47 = V_47 ;
V_47 -> V_87 = V_89 ;
return 0 ;
}
static int F_61 ( struct V_46 * V_47 , int V_66 )
{
struct V_48 * V_49 = F_37 ( V_47 -> V_50 . V_51 ) ;
struct V_24 * V_25 = F_38 ( V_49 ) ;
struct V_88 * V_89 = V_47 -> V_87 ;
int V_97 ;
if ( ! V_89 )
return - V_95 ;
F_29 ( & V_89 -> V_96 ) ;
V_89 -> V_91 = 0 ;
V_89 -> V_66 = V_66 ;
F_30 ( & V_25 -> V_35 ) ;
F_62 ( V_25 , & V_89 -> V_90 ) ;
F_31 ( & V_25 -> V_35 ) ;
V_97 = F_63 ( V_25 ) ;
if ( V_97 == 0 )
V_97 = V_89 -> V_91 ;
F_33 ( & V_89 -> V_96 ) ;
return V_97 ;
}
static int F_64 ( struct V_46 * V_47 , int V_74 )
{
struct V_48 * V_49 = F_37 ( V_47 -> V_50 . V_51 ) ;
struct V_24 * V_25 = F_38 ( V_49 ) ;
struct V_88 * V_89 = V_47 -> V_87 ;
int V_97 ;
if ( ! V_89 )
return - V_95 ;
F_29 ( & V_89 -> V_96 ) ;
V_89 -> V_93 = 0 ;
V_89 -> V_74 = V_74 ;
F_30 ( & V_25 -> V_35 ) ;
F_62 ( V_25 , & V_89 -> V_92 ) ;
F_31 ( & V_25 -> V_35 ) ;
V_97 = F_63 ( V_25 ) ;
if ( V_97 == 0 )
V_97 = V_89 -> V_93 ;
F_33 ( & V_89 -> V_96 ) ;
return V_97 ;
}
struct V_98 *
F_65 ( struct V_99 * V_58 )
{
struct V_98 * V_100 = F_66 ( & V_101 ) ;
struct V_55 * V_18 ;
if ( ! V_100 )
return V_100 ;
V_18 = F_39 ( V_100 ) ;
V_18 -> V_58 = V_58 ;
V_100 -> V_102 = 1 ;
V_100 -> V_103 = V_104 ;
V_100 -> V_105 = V_106 ;
return V_100 ;
}
void F_67 ( struct V_98 * V_100 )
{
F_68 ( V_100 ) ;
}
static int T_4 F_69 ( void )
{
V_4 = F_70 ( V_1 , V_107 ) ;
if ( ! V_4 )
return - V_95 ;
return 0 ;
}
static void T_5 F_71 ( void )
{
F_72 ( V_4 ) ;
}
