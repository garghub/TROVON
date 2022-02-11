void F_1 ( T_1 * V_1 , const T_1 * V_2 )
{
const T_2 V_3 = 0x00DB2777 ;
T_2 V_4 = 0 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
int V_6 ;
for ( V_6 = 7 ; V_6 >= 0 ; V_6 -- ) {
V_4 <<= 1 ;
if ( ( 1 << V_6 ) & V_2 [ V_5 ] ) {
if ( ! ( V_4 & 0x01000000 ) )
V_4 ^= V_3 ;
} else if ( V_4 & 0x01000000 )
V_4 ^= V_3 ;
}
}
V_1 [ 0 ] = ( V_4 >> 16 ) & 0xFF ;
V_1 [ 1 ] = ( V_4 >> 8 ) & 0xFF ;
V_1 [ 2 ] = V_4 & 0xFF ;
}
void F_2 ( struct V_7 * V_8 )
{
struct V_9 * V_10 =
F_3 ( V_8 , struct V_9 , V_8 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
F_4 ( V_13 , & V_12 -> V_14 ,
& V_12 -> V_15 ) ;
}
int F_5 ( struct V_11 * V_16 )
{
int error = 0 ;
F_6 ( & V_16 -> V_17 ) ;
F_1 ( V_16 -> V_18 , V_16 -> V_2 ) ;
if ( V_16 -> V_19 == 0 )
V_16 -> V_19 = 1 ;
else if ( V_16 -> V_19 == - 1 )
V_16 -> V_19 = 128 ;
V_16 -> V_20 = V_21 ;
F_6 ( & V_16 -> V_22 ) ;
error = F_7 ( V_16 ) ;
if ( error ) {
F_8 ( V_23 L_1 , error ) ;
return error ;
}
error = F_9 ( V_16 ) ;
if ( error ) {
F_8 ( V_23 L_2 , error ) ;
goto V_24;
}
error = F_10 ( V_16 ) ;
if ( error ) {
F_8 ( V_23 L_3 , error ) ;
goto V_25;
}
if ( V_16 -> V_26 > 1 ) {
error = F_11 ( V_16 ) ;
if ( error ) {
F_8 ( V_23 L_4
L_5 , error ) ;
V_16 -> V_26 = 1 ;
}
}
F_12 ( & V_16 -> V_27 ) ;
return 0 ;
V_25:
F_13 ( V_16 ) ;
V_24:
return error ;
}
int F_14 ( struct V_11 * V_16 )
{
unsigned long V_28 ;
F_15 ( & V_16 -> V_22 , V_28 ) ;
V_16 -> V_20 = V_29 ;
F_16 ( & V_16 -> V_22 , V_28 ) ;
F_17 ( V_16 -> V_30 . V_31 ) ;
F_13 ( V_16 ) ;
if ( V_16 -> V_26 > 1 ) {
F_18 ( V_16 ) ;
V_16 -> V_26 = 1 ;
}
return 0 ;
}
static int F_19 ( struct V_32 * V_33 )
{
if ( F_20 ( V_33 ) )
return - V_34 ;
return F_21 ( V_33 ) ;
}
int F_22 ( struct V_32 * V_33 , int V_35 )
{
int V_36 ;
enum V_37 V_38 ;
if ( V_35 )
V_38 = V_39 ;
else
V_38 = V_40 ;
if ( F_20 ( V_33 ) ) {
struct V_41 * V_31 = F_23 ( V_33 -> V_42 . V_43 ) ;
struct V_11 * V_16 = F_24 ( V_31 ) ;
struct V_44 * V_45 = V_16 -> V_32 [ V_33 -> V_46 ] ;
struct V_47 * V_5 =
F_25 ( V_16 -> V_30 . V_31 -> V_48 ) ;
if ( ! V_35 ) {
F_26 ( V_45 ) ;
V_16 -> V_49 ( V_45 , V_50 ) ;
}
V_36 = V_5 -> V_51 -> V_52 ( V_45 , V_38 , NULL ) ;
} else {
struct V_53 * V_54 = F_27 ( V_33 -> V_42 . V_43 ) ;
struct V_55 * V_56 = F_28 ( V_54 ) ;
V_36 = F_29 ( V_56 , V_33 -> V_46 , V_38 , NULL ) ;
}
return V_36 ;
}
int F_30 ( struct V_32 * V_33 , int V_57 )
{
int V_36 ;
enum V_37 V_58 ;
if ( V_57 )
V_58 = V_59 ;
else
V_58 = V_39 ;
if ( F_20 ( V_33 ) ) {
struct V_41 * V_31 = F_23 ( V_33 -> V_42 . V_43 ) ;
struct V_11 * V_16 = F_24 ( V_31 ) ;
struct V_44 * V_45 = V_16 -> V_32 [ V_33 -> V_46 ] ;
struct V_47 * V_5 =
F_25 ( V_16 -> V_30 . V_31 -> V_48 ) ;
V_36 = V_5 -> V_51 -> V_52 ( V_45 , V_58 , NULL ) ;
} else {
struct V_53 * V_54 = F_27 ( V_33 -> V_42 . V_43 ) ;
struct V_55 * V_56 = F_28 ( V_54 ) ;
V_36 = F_29 ( V_56 , V_33 -> V_46 , V_58 , NULL ) ;
}
return V_36 ;
}
int F_31 ( struct V_32 * V_33 ,
struct V_60 * V_61 )
{
int V_36 ;
if ( ( V_61 -> V_62 &&
V_61 -> V_62 > V_33 -> V_63 ) ||
( V_61 -> V_63 &&
V_61 -> V_63 < V_33 -> V_62 ) )
return - V_34 ;
if ( V_61 -> V_62 &&
V_61 -> V_62 < V_33 -> V_64 )
V_61 -> V_62 = V_33 -> V_64 ;
if ( V_61 -> V_63 &&
V_61 -> V_63 > V_33 -> V_65 )
V_61 -> V_63 = V_33 -> V_65 ;
if ( F_20 ( V_33 ) ) {
struct V_41 * V_31 = F_23 ( V_33 -> V_42 . V_43 ) ;
struct V_11 * V_16 = F_24 ( V_31 ) ;
struct V_44 * V_45 = V_16 -> V_32 [ V_33 -> V_46 ] ;
struct V_47 * V_5 =
F_25 ( V_16 -> V_30 . V_31 -> V_48 ) ;
V_36 = V_5 -> V_51 -> V_52 ( V_45 , V_66 ,
V_61 ) ;
} else {
struct V_53 * V_54 = F_27 ( V_33 -> V_42 . V_43 ) ;
struct V_55 * V_56 = F_28 ( V_54 ) ;
V_36 = F_29 ( V_56 , V_33 -> V_46 ,
V_39 , V_61 ) ;
}
return V_36 ;
}
struct V_67 *
F_32 ( struct V_68 * V_51 )
{
struct V_67 * V_69 = F_33 ( & V_70 ) ;
struct V_47 * V_5 ;
if ( ! V_69 )
return V_69 ;
V_5 = F_25 ( V_69 ) ;
V_5 -> V_51 = V_51 ;
V_69 -> V_71 = 1 ;
V_69 -> V_72 = V_73 ;
V_69 -> V_74 = V_75 ;
return V_69 ;
}
void F_34 ( struct V_67 * V_69 )
{
F_35 ( V_69 ) ;
}
static int T_3 F_36 ( void )
{
V_76 = F_37 ( L_6 , sizeof( struct V_77 ) ,
0 , V_78 , NULL ) ;
if ( ! V_76 )
return - V_79 ;
return 0 ;
}
static void T_4 F_38 ( void )
{
F_39 ( V_76 ) ;
}
