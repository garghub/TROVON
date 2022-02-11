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
struct V_19 * V_20 =
F_13 ( V_18 , struct V_19 , V_18 ) ;
struct V_21 * V_22 = V_20 -> V_22 ;
F_14 ( V_23 , & V_22 -> V_24 ,
& V_22 -> V_25 ) ;
}
int F_15 ( struct V_21 * V_26 )
{
int error = 0 ;
F_4 ( & V_26 -> V_27 ) ;
F_11 ( V_26 -> V_28 , V_26 -> V_12 ) ;
if ( V_26 -> V_29 == 0 )
V_26 -> V_29 = 1 ;
else if ( V_26 -> V_29 == - 1 )
V_26 -> V_29 = 128 ;
V_26 -> V_30 = V_31 ;
F_4 ( & V_26 -> V_32 ) ;
error = F_16 ( V_26 ) ;
if ( error ) {
F_17 ( V_33 L_1 , error ) ;
return error ;
}
error = F_18 ( V_26 ) ;
if ( error ) {
F_17 ( V_33 L_2 , error ) ;
goto V_34;
}
error = F_19 ( V_26 ) ;
if ( error ) {
F_17 ( V_33 L_3 , error ) ;
goto V_35;
}
if ( V_26 -> V_36 > 1 ) {
error = F_20 ( V_26 ) ;
if ( error ) {
F_17 ( V_33 L_4
L_5 , error ) ;
V_26 -> V_36 = 1 ;
}
}
F_3 ( & V_26 -> V_37 ) ;
return 0 ;
V_35:
F_21 ( V_26 ) ;
V_34:
return error ;
}
int F_22 ( struct V_21 * V_26 )
{
unsigned long V_2 ;
F_23 ( & V_26 -> V_32 , V_2 ) ;
V_26 -> V_30 = V_38 ;
F_24 ( & V_26 -> V_32 , V_2 ) ;
F_25 ( V_26 -> V_39 . V_40 ) ;
F_21 ( V_26 ) ;
if ( V_26 -> V_36 > 1 ) {
F_26 ( V_26 ) ;
V_26 -> V_36 = 1 ;
}
return 0 ;
}
static int F_27 ( struct V_41 * V_42 )
{
if ( F_28 ( V_42 ) ) {
struct V_43 * V_40 = F_29 ( V_42 -> V_44 . V_45 ) ;
struct V_21 * V_26 = F_30 ( V_40 ) ;
struct V_46 * V_47 = V_26 -> V_41 [ V_42 -> V_48 ] ;
struct V_49 * V_15 =
F_31 ( V_26 -> V_39 . V_40 -> V_50 ) ;
return V_15 -> V_51 -> V_52 ( V_47 , V_53 , NULL ) ;
}
return F_32 ( V_42 ) ;
}
int F_33 ( struct V_41 * V_42 , int V_54 )
{
int V_55 ;
enum V_56 V_57 ;
if ( V_54 )
V_57 = V_58 ;
else
V_57 = V_59 ;
if ( F_28 ( V_42 ) ) {
struct V_43 * V_40 = F_29 ( V_42 -> V_44 . V_45 ) ;
struct V_21 * V_26 = F_30 ( V_40 ) ;
struct V_46 * V_47 = V_26 -> V_41 [ V_42 -> V_48 ] ;
struct V_49 * V_15 =
F_31 ( V_26 -> V_39 . V_40 -> V_50 ) ;
if ( ! V_54 ) {
F_34 ( V_47 ) ;
V_26 -> V_60 ( V_47 , V_61 ) ;
}
V_55 = V_15 -> V_51 -> V_52 ( V_47 , V_57 , NULL ) ;
} else {
struct V_62 * V_63 = F_35 ( V_42 -> V_44 . V_45 ) ;
struct V_64 * V_65 = F_36 ( V_63 ) ;
V_55 = F_37 ( V_65 , V_42 -> V_48 , V_57 , NULL ) ;
}
return V_55 ;
}
int F_38 ( struct V_41 * V_42 , int V_66 )
{
int V_55 ;
enum V_56 V_67 ;
if ( V_66 )
V_67 = V_68 ;
else
V_67 = V_58 ;
if ( F_28 ( V_42 ) ) {
struct V_43 * V_40 = F_29 ( V_42 -> V_44 . V_45 ) ;
struct V_21 * V_26 = F_30 ( V_40 ) ;
struct V_46 * V_47 = V_26 -> V_41 [ V_42 -> V_48 ] ;
struct V_49 * V_15 =
F_31 ( V_26 -> V_39 . V_40 -> V_50 ) ;
V_55 = V_15 -> V_51 -> V_52 ( V_47 , V_67 , NULL ) ;
} else {
struct V_62 * V_63 = F_35 ( V_42 -> V_44 . V_45 ) ;
struct V_64 * V_65 = F_36 ( V_63 ) ;
V_55 = F_37 ( V_65 , V_42 -> V_48 , V_67 , NULL ) ;
}
return V_55 ;
}
int F_39 ( struct V_41 * V_42 ,
struct V_69 * V_70 )
{
int V_55 ;
if ( ( V_70 -> V_71 &&
V_70 -> V_71 > V_42 -> V_72 ) ||
( V_70 -> V_72 &&
V_70 -> V_72 < V_42 -> V_71 ) )
return - V_73 ;
if ( V_70 -> V_71 &&
V_70 -> V_71 < V_42 -> V_74 )
V_70 -> V_71 = V_42 -> V_74 ;
if ( V_70 -> V_72 &&
V_70 -> V_72 > V_42 -> V_75 )
V_70 -> V_72 = V_42 -> V_75 ;
if ( F_28 ( V_42 ) ) {
struct V_43 * V_40 = F_29 ( V_42 -> V_44 . V_45 ) ;
struct V_21 * V_26 = F_30 ( V_40 ) ;
struct V_46 * V_47 = V_26 -> V_41 [ V_42 -> V_48 ] ;
struct V_49 * V_15 =
F_31 ( V_26 -> V_39 . V_40 -> V_50 ) ;
V_55 = V_15 -> V_51 -> V_52 ( V_47 , V_76 ,
V_70 ) ;
} else {
struct V_62 * V_63 = F_35 ( V_42 -> V_44 . V_45 ) ;
struct V_64 * V_65 = F_36 ( V_63 ) ;
V_55 = F_37 ( V_65 , V_42 -> V_48 ,
V_58 , V_70 ) ;
}
return V_55 ;
}
struct V_77 *
F_40 ( struct V_78 * V_51 )
{
struct V_77 * V_79 = F_41 ( & V_80 ) ;
struct V_49 * V_15 ;
if ( ! V_79 )
return V_79 ;
V_15 = F_31 ( V_79 ) ;
V_15 -> V_51 = V_51 ;
V_79 -> V_81 = 1 ;
V_79 -> V_82 = V_83 ;
V_79 -> V_84 = V_85 ;
return V_79 ;
}
void F_42 ( struct V_77 * V_79 )
{
F_43 ( V_79 ) ;
}
static int T_4 F_44 ( void )
{
V_4 = F_45 ( V_1 , V_86 ) ;
if ( ! V_4 )
return - V_87 ;
return 0 ;
}
static void T_5 F_46 ( void )
{
F_47 ( V_4 ) ;
}
