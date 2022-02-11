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
static void F_28 ( struct V_24 * V_28 )
{
F_29 ( & V_28 -> V_36 ) ;
F_30 ( & V_28 -> V_35 ) ;
F_17 ( V_33 , & V_28 -> V_34 ) ;
F_31 ( & V_28 -> V_35 ) ;
F_32 ( V_28 ) ;
F_33 ( & V_28 -> V_36 ) ;
}
int F_34 ( struct V_24 * V_28 )
{
F_28 ( V_28 ) ;
F_27 ( V_28 ) ;
F_29 ( & V_28 -> V_36 ) ;
F_32 ( V_28 ) ;
F_33 ( & V_28 -> V_36 ) ;
if ( V_28 -> V_43 > 1 ) {
F_35 ( V_28 ) ;
V_28 -> V_43 = 1 ;
}
return 0 ;
}
static int F_36 ( struct V_46 * V_47 )
{
if ( F_37 ( V_47 ) ) {
struct V_48 * V_49 = F_38 ( V_47 -> V_50 . V_51 ) ;
struct V_24 * V_28 = F_39 ( V_49 ) ;
struct V_52 * V_53 = V_28 -> V_46 [ V_47 -> V_54 ] ;
struct V_55 * V_18 =
F_40 ( V_28 -> V_56 . V_49 -> V_57 ) ;
return V_18 -> V_58 -> V_59 ( V_53 , V_60 , NULL ) ;
}
return F_41 ( V_47 ) ;
}
int F_42 ( struct V_52 * V_53 )
{
struct V_61 * V_50 = NULL ;
if ( V_53 -> V_62 )
V_50 = V_53 -> V_62 -> V_63 ;
if ( V_50 )
V_50 = F_43 ( V_50 -> V_64 ) ;
if ( V_50 && F_44 ( V_50 ) ) {
F_45 ( V_50 ) ;
F_46 ( V_50 ) ;
return 0 ;
}
return - V_65 ;
}
static int F_47 ( struct V_46 * V_47 , int V_66 )
{
enum V_67 V_68 ;
if ( V_66 )
V_68 = V_69 ;
else
V_68 = V_70 ;
if ( F_37 ( V_47 ) ) {
struct V_48 * V_49 = F_38 ( V_47 -> V_50 . V_51 ) ;
struct V_24 * V_28 = F_39 ( V_49 ) ;
struct V_52 * V_53 = V_28 -> V_46 [ V_47 -> V_54 ] ;
struct V_55 * V_18 =
F_40 ( V_28 -> V_56 . V_49 -> V_57 ) ;
if ( ! V_66 && F_42 ( V_53 ) == 0 )
return 0 ;
return V_18 -> V_58 -> V_59 ( V_53 , V_68 , NULL ) ;
} else {
struct V_71 * V_64 = F_48 ( V_47 -> V_50 . V_51 ) ;
struct V_61 * V_72 = F_43 ( V_64 ) ;
struct V_61 * V_73 = F_49 ( V_72 , V_47 -> V_54 ) ;
if ( V_73 && ! V_66 ) {
F_45 ( V_73 ) ;
F_46 ( V_73 ) ;
return 0 ;
} else
return F_50 ( V_72 , V_47 -> V_54 , V_68 , NULL ) ;
}
}
static int F_51 ( struct V_46 * V_47 , int V_74 )
{
int V_75 ;
enum V_67 V_76 ;
if ( V_74 )
V_76 = V_70 ;
else
V_76 = V_77 ;
if ( F_37 ( V_47 ) ) {
struct V_48 * V_49 = F_38 ( V_47 -> V_50 . V_51 ) ;
struct V_24 * V_28 = F_39 ( V_49 ) ;
struct V_52 * V_53 = V_28 -> V_46 [ V_47 -> V_54 ] ;
struct V_55 * V_18 =
F_40 ( V_28 -> V_56 . V_49 -> V_57 ) ;
if ( V_74 )
V_75 = F_47 ( V_47 , 0 ) ;
else
V_75 = V_18 -> V_58 -> V_59 ( V_53 , V_76 , NULL ) ;
} else {
struct V_71 * V_64 = F_48 ( V_47 -> V_50 . V_51 ) ;
struct V_61 * V_72 = F_43 ( V_64 ) ;
if ( V_74 )
V_75 = F_47 ( V_47 , 0 ) ;
else
V_75 = F_50 ( V_72 , V_47 -> V_54 , V_76 , NULL ) ;
}
return V_75 ;
}
int F_52 ( struct V_46 * V_47 , int V_66 )
{
int V_75 ;
enum V_67 V_68 ;
if ( ! V_47 -> V_78 )
return - V_65 ;
if ( V_66 )
V_68 = V_69 ;
else
V_68 = V_70 ;
if ( F_37 ( V_47 ) ) {
struct V_48 * V_49 = F_38 ( V_47 -> V_50 . V_51 ) ;
struct V_24 * V_28 = F_39 ( V_49 ) ;
struct V_52 * V_53 = V_28 -> V_46 [ V_47 -> V_54 ] ;
struct V_55 * V_18 =
F_40 ( V_28 -> V_56 . V_49 -> V_57 ) ;
V_75 = V_18 -> V_58 -> V_59 ( V_53 , V_68 , NULL ) ;
} else {
struct V_71 * V_64 = F_48 ( V_47 -> V_50 . V_51 ) ;
struct V_61 * V_72 = F_43 ( V_64 ) ;
V_75 = F_50 ( V_72 , V_47 -> V_54 , V_68 , NULL ) ;
}
return V_75 ;
}
int F_53 ( struct V_46 * V_47 ,
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
if ( F_37 ( V_47 ) ) {
struct V_48 * V_49 = F_38 ( V_47 -> V_50 . V_51 ) ;
struct V_24 * V_28 = F_39 ( V_49 ) ;
struct V_52 * V_53 = V_28 -> V_46 [ V_47 -> V_54 ] ;
struct V_55 * V_18 =
F_40 ( V_28 -> V_56 . V_49 -> V_57 ) ;
V_75 = V_18 -> V_58 -> V_59 ( V_53 , V_86 ,
V_80 ) ;
} else {
struct V_71 * V_64 = F_48 ( V_47 -> V_50 . V_51 ) ;
struct V_61 * V_72 = F_43 ( V_64 ) ;
V_75 = F_50 ( V_72 , V_47 -> V_54 ,
V_70 , V_80 ) ;
}
return V_75 ;
}
void F_54 ( struct V_24 * V_25 )
{
int V_18 ;
F_20 ( V_33 , & V_25 -> V_34 ) ;
for ( V_18 = 0 ; V_18 < V_25 -> V_87 ; V_18 ++ ) {
struct V_52 * V_47 = V_25 -> V_46 [ V_18 ] ;
memset ( V_47 -> V_88 , 0 , V_89 ) ;
V_47 -> V_90 = 0 ;
V_47 -> V_91 = 0 ;
V_47 -> V_92 = 0 ;
}
}
static int F_55 ( struct V_24 * V_25 )
{
int V_18 , V_93 = 0 ;
for ( V_18 = 0 ; V_18 < V_25 -> V_87 ; V_18 ++ ) {
struct V_52 * V_47 = V_25 -> V_46 [ V_18 ] ;
if ( V_47 -> V_94 )
V_93 ++ ;
}
return V_93 ;
}
void F_56 ( struct V_24 * V_25 )
{
const unsigned long V_95 = F_57 ( 25000 ) ;
int V_18 ;
V_18 = F_55 ( V_25 ) ;
if ( V_18 )
F_58 ( V_25 -> V_50 , L_6 ,
V_18 , V_18 > 1 ? L_7 : L_8 ) ;
F_59 ( V_25 -> V_37 , F_55 ( V_25 ) == 0 , V_95 ) ;
for ( V_18 = 0 ; V_18 < V_25 -> V_87 ; V_18 ++ ) {
struct V_52 * V_47 = V_25 -> V_46 [ V_18 ] ;
if ( V_47 -> V_94 ) {
F_60 ( & V_47 -> V_47 -> V_50 , L_9 ) ;
F_61 ( V_47 , V_96 ) ;
}
}
F_62 ( V_25 -> V_56 . V_49 ) ;
F_63 ( V_25 ) ;
}
void F_64 ( struct V_24 * V_25 )
{
int V_18 ;
F_28 ( V_25 ) ;
F_65 ( V_25 -> V_56 . V_49 ) ;
for ( V_18 = 0 ; V_18 < V_25 -> V_87 ; V_18 ++ ) {
struct V_97 * V_62 = V_25 -> V_98 [ V_18 ] ;
F_66 ( V_62 , V_99 ) ;
}
F_29 ( & V_25 -> V_36 ) ;
F_32 ( V_25 ) ;
F_33 ( & V_25 -> V_36 ) ;
}
static void F_67 ( struct V_46 * V_47 )
{
F_8 ( V_47 -> V_100 ) ;
V_47 -> V_100 = NULL ;
}
static void F_68 ( struct V_20 * V_21 )
{
struct V_101 * V_102 = F_69 ( V_21 , F_70 ( * V_102 ) , V_103 . V_21 ) ;
V_102 -> V_104 = F_47 ( V_102 -> V_47 , V_102 -> V_66 ) ;
}
static void F_71 ( struct V_20 * V_21 )
{
struct V_101 * V_102 = F_69 ( V_21 , F_70 ( * V_102 ) , V_105 . V_21 ) ;
V_102 -> V_106 = F_51 ( V_102 -> V_47 , V_102 -> V_74 ) ;
}
static int F_72 ( struct V_46 * V_47 )
{
struct V_101 * V_102 = F_73 ( sizeof( * V_102 ) , V_107 ) ;
if ( ! V_102 )
return - V_108 ;
F_19 ( & V_102 -> V_109 ) ;
F_74 ( & V_102 -> V_103 , F_68 ) ;
F_74 ( & V_102 -> V_105 , F_71 ) ;
V_102 -> V_47 = V_47 ;
V_47 -> V_100 = V_102 ;
return 0 ;
}
static int F_75 ( struct V_46 * V_47 , int V_66 )
{
struct V_48 * V_49 = F_38 ( V_47 -> V_50 . V_51 ) ;
struct V_24 * V_25 = F_39 ( V_49 ) ;
struct V_101 * V_102 = V_47 -> V_100 ;
int V_93 ;
if ( ! V_102 )
return - V_108 ;
F_29 ( & V_102 -> V_109 ) ;
V_102 -> V_104 = 0 ;
V_102 -> V_66 = V_66 ;
F_30 ( & V_25 -> V_35 ) ;
F_76 ( V_25 , & V_102 -> V_103 ) ;
F_31 ( & V_25 -> V_35 ) ;
V_93 = F_63 ( V_25 ) ;
if ( V_93 == 0 )
V_93 = V_102 -> V_104 ;
F_33 ( & V_102 -> V_109 ) ;
return V_93 ;
}
static int F_77 ( struct V_46 * V_47 , int V_74 )
{
struct V_48 * V_49 = F_38 ( V_47 -> V_50 . V_51 ) ;
struct V_24 * V_25 = F_39 ( V_49 ) ;
struct V_101 * V_102 = V_47 -> V_100 ;
int V_93 ;
if ( ! V_102 )
return - V_108 ;
F_29 ( & V_102 -> V_109 ) ;
V_102 -> V_106 = 0 ;
V_102 -> V_74 = V_74 ;
F_30 ( & V_25 -> V_35 ) ;
F_76 ( V_25 , & V_102 -> V_105 ) ;
F_31 ( & V_25 -> V_35 ) ;
V_93 = F_63 ( V_25 ) ;
if ( V_93 == 0 )
V_93 = V_102 -> V_106 ;
F_33 ( & V_102 -> V_109 ) ;
return V_93 ;
}
struct V_110 *
F_78 ( struct V_111 * V_58 )
{
struct V_110 * V_112 = F_79 ( & V_113 ) ;
struct V_55 * V_18 ;
if ( ! V_112 )
return V_112 ;
V_18 = F_40 ( V_112 ) ;
V_18 -> V_58 = V_58 ;
V_112 -> V_114 = 1 ;
V_112 -> V_115 = V_116 ;
V_112 -> V_117 = V_118 ;
return V_112 ;
}
void F_80 ( struct V_110 * V_112 )
{
F_81 ( V_112 ) ;
}
static int T_4 F_82 ( void )
{
V_4 = F_83 ( V_1 , V_119 ) ;
if ( ! V_4 )
return - V_108 ;
return 0 ;
}
static void T_5 F_84 ( void )
{
F_85 ( V_4 ) ;
}
