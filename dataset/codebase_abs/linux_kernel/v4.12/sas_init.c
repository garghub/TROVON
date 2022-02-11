struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 = F_2 ( V_4 , V_2 ) ;
if ( V_3 ) {
F_3 ( & V_3 -> V_5 ) ;
V_3 -> V_6 = V_7 ;
}
return V_3 ;
}
struct V_1 * F_4 ( T_1 V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_8 * V_9 = F_5 ( sizeof( * V_9 ) , V_2 ) ;
if ( ! V_3 || ! V_9 ) {
if ( V_3 )
F_6 ( V_4 , V_3 ) ;
F_7 ( V_9 ) ;
return NULL ;
}
V_3 -> V_10 = V_9 ;
F_8 ( & V_9 -> V_11 ) ;
F_9 ( & V_9 -> V_12 ) ;
return V_3 ;
}
void F_10 ( struct V_1 * V_3 )
{
if ( V_3 ) {
F_7 ( V_3 -> V_10 ) ;
F_6 ( V_4 , V_3 ) ;
}
}
void F_11 ( T_2 * V_13 , const T_2 * V_14 )
{
const T_3 V_15 = 0x00DB2777 ;
T_3 V_16 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
int V_18 ;
for ( V_18 = 7 ; V_18 >= 0 ; V_18 -- ) {
V_16 <<= 1 ;
if ( ( 1 << V_18 ) & V_14 [ V_17 ] ) {
if ( ! ( V_16 & 0x01000000 ) )
V_16 ^= V_15 ;
} else if ( V_16 & 0x01000000 )
V_16 ^= V_15 ;
}
}
V_13 [ 0 ] = ( V_16 >> 16 ) & 0xFF ;
V_13 [ 1 ] = ( V_16 >> 8 ) & 0xFF ;
V_13 [ 2 ] = V_16 & 0xFF ;
}
void F_12 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_13 ( V_20 ) ;
struct V_23 * V_24 = V_22 -> V_24 ;
F_14 ( V_25 , & V_24 -> V_26 ) ;
}
int F_15 ( struct V_23 * V_27 )
{
int error = 0 ;
F_16 ( & V_27 -> V_28 ) ;
F_3 ( & V_27 -> V_29 ) ;
F_11 ( V_27 -> V_30 , V_27 -> V_14 ) ;
F_17 ( V_31 , & V_27 -> V_32 ) ;
F_3 ( & V_27 -> V_33 ) ;
F_16 ( & V_27 -> V_34 ) ;
F_18 ( & V_27 -> V_35 ) ;
F_19 ( & V_27 -> V_36 ) ;
F_19 ( & V_27 -> V_37 ) ;
error = F_20 ( V_27 ) ;
if ( error ) {
F_21 ( V_38 L_1 , error ) ;
return error ;
}
error = F_22 ( V_27 ) ;
if ( error ) {
F_21 ( V_38 L_2 , error ) ;
goto V_39;
}
error = F_23 ( V_27 ) ;
if ( error ) {
F_21 ( V_38 L_3 , error ) ;
goto V_40;
}
F_19 ( & V_27 -> V_41 ) ;
F_19 ( & V_27 -> V_42 ) ;
return 0 ;
V_40:
F_24 ( V_27 ) ;
V_39:
return error ;
}
static void F_25 ( struct V_23 * V_27 )
{
F_26 ( & V_27 -> V_34 ) ;
F_27 ( & V_27 -> V_33 ) ;
F_14 ( V_31 , & V_27 -> V_32 ) ;
F_28 ( & V_27 -> V_33 ) ;
F_29 ( V_27 ) ;
F_30 ( & V_27 -> V_34 ) ;
}
int F_31 ( struct V_23 * V_27 )
{
F_25 ( V_27 ) ;
F_24 ( V_27 ) ;
F_26 ( & V_27 -> V_34 ) ;
F_29 ( V_27 ) ;
F_30 ( & V_27 -> V_34 ) ;
return 0 ;
}
static int F_32 ( struct V_43 * V_44 )
{
if ( F_33 ( V_44 ) ) {
struct V_45 * V_46 = F_34 ( V_44 -> V_47 . V_48 ) ;
struct V_23 * V_27 = F_35 ( V_46 ) ;
struct V_49 * V_50 = V_27 -> V_43 [ V_44 -> V_51 ] ;
struct V_52 * V_17 =
F_36 ( V_27 -> V_53 . V_46 -> V_54 ) ;
return V_17 -> V_55 -> V_56 ( V_50 , V_57 , NULL ) ;
}
return F_37 ( V_44 ) ;
}
int F_38 ( struct V_49 * V_50 )
{
struct V_58 * V_47 = NULL ;
if ( V_50 -> V_59 )
V_47 = V_50 -> V_59 -> V_60 ;
if ( V_47 )
V_47 = F_39 ( V_47 -> V_61 ) ;
if ( V_47 && F_40 ( V_47 ) ) {
F_41 ( V_47 ) ;
F_42 ( V_47 ) ;
return 0 ;
}
return - V_62 ;
}
static int F_43 ( struct V_43 * V_44 , int V_63 )
{
enum V_64 V_65 ;
if ( V_63 )
V_65 = V_66 ;
else
V_65 = V_67 ;
if ( F_33 ( V_44 ) ) {
struct V_45 * V_46 = F_34 ( V_44 -> V_47 . V_48 ) ;
struct V_23 * V_27 = F_35 ( V_46 ) ;
struct V_49 * V_50 = V_27 -> V_43 [ V_44 -> V_51 ] ;
struct V_52 * V_17 =
F_36 ( V_27 -> V_53 . V_46 -> V_54 ) ;
if ( ! V_63 && F_38 ( V_50 ) == 0 )
return 0 ;
return V_17 -> V_55 -> V_56 ( V_50 , V_65 , NULL ) ;
} else {
struct V_68 * V_61 = F_44 ( V_44 -> V_47 . V_48 ) ;
struct V_58 * V_69 = F_39 ( V_61 ) ;
struct V_58 * V_70 = F_45 ( V_69 , V_44 -> V_51 ) ;
if ( V_70 && ! V_63 ) {
F_41 ( V_70 ) ;
F_42 ( V_70 ) ;
return 0 ;
} else
return F_46 ( V_69 , V_44 -> V_51 , V_65 , NULL ) ;
}
}
static int F_47 ( struct V_43 * V_44 , int V_71 )
{
int V_72 ;
enum V_64 V_73 ;
if ( V_71 )
V_73 = V_67 ;
else
V_73 = V_74 ;
if ( F_33 ( V_44 ) ) {
struct V_45 * V_46 = F_34 ( V_44 -> V_47 . V_48 ) ;
struct V_23 * V_27 = F_35 ( V_46 ) ;
struct V_49 * V_50 = V_27 -> V_43 [ V_44 -> V_51 ] ;
struct V_52 * V_17 =
F_36 ( V_27 -> V_53 . V_46 -> V_54 ) ;
if ( V_71 )
V_72 = F_43 ( V_44 , 0 ) ;
else
V_72 = V_17 -> V_55 -> V_56 ( V_50 , V_73 , NULL ) ;
} else {
struct V_68 * V_61 = F_44 ( V_44 -> V_47 . V_48 ) ;
struct V_58 * V_69 = F_39 ( V_61 ) ;
if ( V_71 )
V_72 = F_43 ( V_44 , 0 ) ;
else
V_72 = F_46 ( V_69 , V_44 -> V_51 , V_73 , NULL ) ;
}
return V_72 ;
}
int F_48 ( struct V_43 * V_44 , int V_63 )
{
int V_72 ;
enum V_64 V_65 ;
if ( ! V_44 -> V_75 )
return - V_62 ;
if ( V_63 )
V_65 = V_66 ;
else
V_65 = V_67 ;
if ( F_33 ( V_44 ) ) {
struct V_45 * V_46 = F_34 ( V_44 -> V_47 . V_48 ) ;
struct V_23 * V_27 = F_35 ( V_46 ) ;
struct V_49 * V_50 = V_27 -> V_43 [ V_44 -> V_51 ] ;
struct V_52 * V_17 =
F_36 ( V_27 -> V_53 . V_46 -> V_54 ) ;
V_72 = V_17 -> V_55 -> V_56 ( V_50 , V_65 , NULL ) ;
} else {
struct V_68 * V_61 = F_44 ( V_44 -> V_47 . V_48 ) ;
struct V_58 * V_69 = F_39 ( V_61 ) ;
V_72 = F_46 ( V_69 , V_44 -> V_51 , V_65 , NULL ) ;
}
return V_72 ;
}
int F_49 ( struct V_43 * V_44 ,
struct V_76 * V_77 )
{
int V_72 ;
if ( ( V_77 -> V_78 &&
V_77 -> V_78 > V_44 -> V_79 ) ||
( V_77 -> V_79 &&
V_77 -> V_79 < V_44 -> V_78 ) )
return - V_80 ;
if ( V_77 -> V_78 &&
V_77 -> V_78 < V_44 -> V_81 )
V_77 -> V_78 = V_44 -> V_81 ;
if ( V_77 -> V_79 &&
V_77 -> V_79 > V_44 -> V_82 )
V_77 -> V_79 = V_44 -> V_82 ;
if ( F_33 ( V_44 ) ) {
struct V_45 * V_46 = F_34 ( V_44 -> V_47 . V_48 ) ;
struct V_23 * V_27 = F_35 ( V_46 ) ;
struct V_49 * V_50 = V_27 -> V_43 [ V_44 -> V_51 ] ;
struct V_52 * V_17 =
F_36 ( V_27 -> V_53 . V_46 -> V_54 ) ;
V_72 = V_17 -> V_55 -> V_56 ( V_50 , V_83 ,
V_77 ) ;
} else {
struct V_68 * V_61 = F_44 ( V_44 -> V_47 . V_48 ) ;
struct V_58 * V_69 = F_39 ( V_61 ) ;
V_72 = F_46 ( V_69 , V_44 -> V_51 ,
V_67 , V_77 ) ;
}
return V_72 ;
}
void F_50 ( struct V_23 * V_24 )
{
int V_17 ;
F_17 ( V_31 , & V_24 -> V_32 ) ;
for ( V_17 = 0 ; V_17 < V_24 -> V_84 ; V_17 ++ ) {
struct V_49 * V_44 = V_24 -> V_43 [ V_17 ] ;
memset ( V_44 -> V_85 , 0 , V_86 ) ;
V_44 -> V_87 = 0 ;
V_44 -> V_88 = 0 ;
V_44 -> V_89 = 0 ;
}
}
static int F_51 ( struct V_23 * V_24 )
{
int V_17 , V_90 = 0 ;
for ( V_17 = 0 ; V_17 < V_24 -> V_84 ; V_17 ++ ) {
struct V_49 * V_44 = V_24 -> V_43 [ V_17 ] ;
if ( V_44 -> V_91 )
V_90 ++ ;
}
return V_90 ;
}
void F_52 ( struct V_23 * V_24 )
{
const unsigned long V_92 = F_53 ( 25000 ) ;
int V_17 ;
V_17 = F_51 ( V_24 ) ;
if ( V_17 )
F_54 ( V_24 -> V_47 , L_4 ,
V_17 , V_17 > 1 ? L_5 : L_6 ) ;
F_55 ( V_24 -> V_35 , F_51 ( V_24 ) == 0 , V_92 ) ;
for ( V_17 = 0 ; V_17 < V_24 -> V_84 ; V_17 ++ ) {
struct V_49 * V_44 = V_24 -> V_43 [ V_17 ] ;
if ( V_44 -> V_91 ) {
F_56 ( & V_44 -> V_44 -> V_47 , L_7 ) ;
F_57 ( V_44 , V_93 ) ;
}
}
F_58 ( V_24 -> V_53 . V_46 ) ;
F_59 ( V_24 ) ;
}
void F_60 ( struct V_23 * V_24 )
{
int V_17 ;
F_25 ( V_24 ) ;
F_61 ( V_24 -> V_53 . V_46 ) ;
for ( V_17 = 0 ; V_17 < V_24 -> V_84 ; V_17 ++ ) {
struct V_94 * V_59 = V_24 -> V_95 [ V_17 ] ;
F_62 ( V_59 , V_96 ) ;
}
F_26 ( & V_24 -> V_34 ) ;
F_29 ( V_24 ) ;
F_30 ( & V_24 -> V_34 ) ;
}
static void F_63 ( struct V_43 * V_44 )
{
F_7 ( V_44 -> V_97 ) ;
V_44 -> V_97 = NULL ;
}
static void F_64 ( struct V_19 * V_20 )
{
struct V_98 * V_99 = F_65 ( V_20 , F_66 ( * V_99 ) , V_100 . V_20 ) ;
V_99 -> V_101 = F_43 ( V_99 -> V_44 , V_99 -> V_63 ) ;
}
static void F_67 ( struct V_19 * V_20 )
{
struct V_98 * V_99 = F_65 ( V_20 , F_66 ( * V_99 ) , V_102 . V_20 ) ;
V_99 -> V_103 = F_47 ( V_99 -> V_44 , V_99 -> V_71 ) ;
}
static int F_68 ( struct V_43 * V_44 )
{
struct V_98 * V_99 = F_69 ( sizeof( * V_99 ) , V_104 ) ;
if ( ! V_99 )
return - V_105 ;
F_16 ( & V_99 -> V_106 ) ;
F_70 ( & V_99 -> V_100 , F_64 ) ;
F_70 ( & V_99 -> V_102 , F_67 ) ;
V_99 -> V_44 = V_44 ;
V_44 -> V_97 = V_99 ;
return 0 ;
}
static int F_71 ( struct V_43 * V_44 , int V_63 )
{
struct V_45 * V_46 = F_34 ( V_44 -> V_47 . V_48 ) ;
struct V_23 * V_24 = F_35 ( V_46 ) ;
struct V_98 * V_99 = V_44 -> V_97 ;
int V_90 ;
if ( ! V_99 )
return - V_105 ;
F_26 ( & V_99 -> V_106 ) ;
V_99 -> V_101 = 0 ;
V_99 -> V_63 = V_63 ;
F_27 ( & V_24 -> V_33 ) ;
F_72 ( V_24 , & V_99 -> V_100 ) ;
F_28 ( & V_24 -> V_33 ) ;
V_90 = F_59 ( V_24 ) ;
if ( V_90 == 0 )
V_90 = V_99 -> V_101 ;
F_30 ( & V_99 -> V_106 ) ;
return V_90 ;
}
static int F_73 ( struct V_43 * V_44 , int V_71 )
{
struct V_45 * V_46 = F_34 ( V_44 -> V_47 . V_48 ) ;
struct V_23 * V_24 = F_35 ( V_46 ) ;
struct V_98 * V_99 = V_44 -> V_97 ;
int V_90 ;
if ( ! V_99 )
return - V_105 ;
F_26 ( & V_99 -> V_106 ) ;
V_99 -> V_103 = 0 ;
V_99 -> V_71 = V_71 ;
F_27 ( & V_24 -> V_33 ) ;
F_72 ( V_24 , & V_99 -> V_102 ) ;
F_28 ( & V_24 -> V_33 ) ;
V_90 = F_59 ( V_24 ) ;
if ( V_90 == 0 )
V_90 = V_99 -> V_103 ;
F_30 ( & V_99 -> V_106 ) ;
return V_90 ;
}
struct V_107 *
F_74 ( struct V_108 * V_55 )
{
struct V_107 * V_109 = F_75 ( & V_110 ) ;
struct V_52 * V_17 ;
if ( ! V_109 )
return V_109 ;
V_17 = F_36 ( V_109 ) ;
V_17 -> V_55 = V_55 ;
V_109 -> V_111 = 1 ;
V_109 -> V_112 = V_113 ;
return V_109 ;
}
static int T_4 F_76 ( void )
{
V_4 = F_77 ( V_1 , V_114 ) ;
if ( ! V_4 )
return - V_105 ;
return 0 ;
}
static void T_5 F_78 ( void )
{
F_79 ( V_4 ) ;
}
