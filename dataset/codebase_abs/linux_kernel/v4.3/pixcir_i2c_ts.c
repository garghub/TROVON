static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 [ 2 + V_6 * 5 ] ;
T_1 V_7 [ 1 ] = { 0 } ;
T_1 * V_8 ;
T_1 V_9 ;
int V_10 , V_11 ;
int V_12 ;
const struct V_13 * V_14 = V_2 -> V_14 ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_11 = V_14 -> V_15 ? 1 : 0 ;
V_12 = 2 + V_2 -> V_16 * ( 4 + V_11 ) ;
if ( V_12 > sizeof( V_5 ) )
V_12 = sizeof( V_5 ) ;
V_10 = F_2 ( V_2 -> V_17 , V_7 , sizeof( V_7 ) ) ;
if ( V_10 != sizeof( V_7 ) ) {
F_3 ( & V_2 -> V_17 -> V_18 ,
L_1 ,
V_19 , V_10 ) ;
return;
}
V_10 = F_4 ( V_2 -> V_17 , V_5 , V_12 ) ;
if ( V_10 != V_12 ) {
F_3 ( & V_2 -> V_17 -> V_18 ,
L_2 ,
V_19 , V_10 ) ;
return;
}
V_9 = V_5 [ 0 ] & 0x7 ;
if ( V_9 > V_2 -> V_16 )
V_9 = V_2 -> V_16 ;
V_4 -> V_20 = V_9 ;
V_8 = & V_5 [ 2 ] ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
V_4 -> V_21 [ V_11 ] . V_22 = ( V_8 [ 1 ] << 8 ) | V_8 [ 0 ] ;
V_4 -> V_21 [ V_11 ] . V_23 = ( V_8 [ 3 ] << 8 ) | V_8 [ 2 ] ;
if ( V_14 -> V_15 ) {
V_4 -> V_21 [ V_11 ] . V_24 = V_8 [ 4 ] ;
V_8 = V_8 + 5 ;
} else {
V_8 = V_8 + 4 ;
}
}
}
static void F_5 ( struct V_1 * V_25 ,
struct V_3 * V_4 )
{
struct V_26 V_27 [ V_6 ] ;
int V_28 [ V_6 ] ;
struct V_29 * V_9 ;
int V_30 , V_11 , V_31 ;
struct V_32 * V_18 = & V_25 -> V_17 -> V_18 ;
const struct V_13 * V_14 = V_25 -> V_14 ;
V_30 = V_4 -> V_20 ;
if ( V_30 > V_6 )
V_30 = V_6 ;
if ( ! V_25 -> V_14 -> V_15 ) {
for ( V_11 = 0 ; V_11 < V_30 ; V_11 ++ ) {
V_9 = & V_4 -> V_21 [ V_11 ] ;
V_27 [ V_11 ] . V_22 = V_9 -> V_22 ;
V_27 [ V_11 ] . V_23 = V_9 -> V_23 ;
}
F_6 ( V_25 -> V_33 , V_28 , V_27 , V_30 , 0 ) ;
}
for ( V_11 = 0 ; V_11 < V_30 ; V_11 ++ ) {
V_9 = & V_4 -> V_21 [ V_11 ] ;
if ( V_14 -> V_15 ) {
V_31 = F_7 ( V_25 -> V_33 , V_9 -> V_24 ) ;
if ( V_31 < 0 ) {
F_8 ( V_18 , L_3 ,
V_9 -> V_24 ) ;
continue;
}
} else {
V_31 = V_28 [ V_11 ] ;
}
F_9 ( V_25 -> V_33 , V_31 ) ;
F_10 ( V_25 -> V_33 ,
V_34 , true ) ;
F_11 ( V_25 -> V_33 , V_35 , V_36 , V_9 -> V_22 ) ;
F_11 ( V_25 -> V_33 , V_35 , V_37 , V_9 -> V_23 ) ;
F_8 ( V_18 , L_4 ,
V_11 , V_31 , V_9 -> V_22 , V_9 -> V_23 ) ;
}
F_12 ( V_25 -> V_33 ) ;
F_13 ( V_25 -> V_33 ) ;
}
static T_2 F_14 ( int V_38 , void * V_39 )
{
struct V_1 * V_2 = V_39 ;
struct V_3 V_4 ;
while ( V_2 -> V_40 ) {
F_1 ( V_2 , & V_4 ) ;
F_5 ( V_2 , & V_4 ) ;
if ( F_15 ( V_2 -> V_41 ) ) {
if ( V_4 . V_20 ) {
F_12 ( V_2 -> V_33 ) ;
F_13 ( V_2 -> V_33 ) ;
}
break;
}
F_16 ( 20 ) ;
}
return V_42 ;
}
static void F_17 ( struct V_1 * V_2 )
{
if ( ! F_18 ( V_2 -> V_43 ) ) {
F_19 ( V_2 -> V_43 , 1 ) ;
F_20 ( 100 ) ;
F_19 ( V_2 -> V_43 , 0 ) ;
F_16 ( 100 ) ;
}
}
static int F_21 ( struct V_1 * V_25 ,
enum V_44 V_45 )
{
struct V_32 * V_18 = & V_25 -> V_17 -> V_18 ;
int V_10 ;
V_10 = F_22 ( V_25 -> V_17 , V_46 ) ;
if ( V_10 < 0 ) {
F_3 ( V_18 , L_5 ,
V_19 , V_46 , V_10 ) ;
return V_10 ;
}
V_10 &= ~ V_47 ;
V_10 |= V_45 ;
V_10 |= V_48 ;
V_10 = F_23 ( V_25 -> V_17 , V_46 , V_10 ) ;
if ( V_10 < 0 ) {
F_3 ( V_18 , L_6 ,
V_19 , V_46 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_25 ,
enum V_49 V_45 , bool V_50 )
{
struct V_32 * V_18 = & V_25 -> V_17 -> V_18 ;
int V_10 ;
V_10 = F_22 ( V_25 -> V_17 , V_51 ) ;
if ( V_10 < 0 ) {
F_3 ( V_18 , L_5 ,
V_19 , V_51 , V_10 ) ;
return V_10 ;
}
V_10 &= ~ V_52 ;
V_10 |= V_45 ;
if ( V_50 )
V_10 |= V_53 ;
else
V_10 &= ~ V_53 ;
V_10 = F_23 ( V_25 -> V_17 , V_51 , V_10 ) ;
if ( V_10 < 0 ) {
F_3 ( V_18 , L_6 ,
V_19 , V_51 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_25 , bool V_54 )
{
struct V_32 * V_18 = & V_25 -> V_17 -> V_18 ;
int V_10 ;
V_10 = F_22 ( V_25 -> V_17 , V_51 ) ;
if ( V_10 < 0 ) {
F_3 ( V_18 , L_5 ,
V_19 , V_51 , V_10 ) ;
return V_10 ;
}
if ( V_54 )
V_10 |= V_55 ;
else
V_10 &= ~ V_55 ;
V_10 = F_23 ( V_25 -> V_17 , V_51 , V_10 ) ;
if ( V_10 < 0 ) {
F_3 ( V_18 , L_6 ,
V_19 , V_51 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_25 )
{
struct V_32 * V_18 = & V_25 -> V_17 -> V_18 ;
int error ;
error = F_24 ( V_25 , V_56 , 0 ) ;
if ( error ) {
F_3 ( V_18 , L_7 , error ) ;
return error ;
}
V_25 -> V_40 = true ;
F_27 () ;
error = F_25 ( V_25 , true ) ;
if ( error ) {
F_3 ( V_18 , L_8 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_25 )
{
int error ;
error = F_25 ( V_25 , false ) ;
if ( error ) {
F_3 ( & V_25 -> V_17 -> V_18 ,
L_9 ,
error ) ;
return error ;
}
V_25 -> V_40 = false ;
F_27 () ;
F_29 ( V_25 -> V_17 -> V_38 ) ;
return 0 ;
}
static int F_30 ( struct V_57 * V_18 )
{
struct V_1 * V_25 = F_31 ( V_18 ) ;
return F_26 ( V_25 ) ;
}
static void F_32 ( struct V_57 * V_18 )
{
struct V_1 * V_25 = F_31 ( V_18 ) ;
F_28 ( V_25 ) ;
}
static int T_3 F_33 ( struct V_32 * V_18 )
{
struct V_58 * V_17 = F_34 ( V_18 ) ;
struct V_1 * V_25 = F_35 ( V_17 ) ;
struct V_57 * V_33 = V_25 -> V_33 ;
int V_10 = 0 ;
F_36 ( & V_33 -> V_59 ) ;
if ( F_37 ( & V_17 -> V_18 ) ) {
if ( ! V_33 -> V_60 ) {
V_10 = F_26 ( V_25 ) ;
if ( V_10 ) {
F_3 ( V_18 , L_10 ) ;
goto V_61;
}
}
F_38 ( V_17 -> V_38 ) ;
} else if ( V_33 -> V_60 ) {
V_10 = F_28 ( V_25 ) ;
}
V_61:
F_39 ( & V_33 -> V_59 ) ;
return V_10 ;
}
static int T_3 F_40 ( struct V_32 * V_18 )
{
struct V_58 * V_17 = F_34 ( V_18 ) ;
struct V_1 * V_25 = F_35 ( V_17 ) ;
struct V_57 * V_33 = V_25 -> V_33 ;
int V_10 = 0 ;
F_36 ( & V_33 -> V_59 ) ;
if ( F_37 ( & V_17 -> V_18 ) ) {
F_41 ( V_17 -> V_38 ) ;
if ( ! V_33 -> V_60 ) {
V_10 = F_28 ( V_25 ) ;
if ( V_10 ) {
F_3 ( V_18 , L_11 ) ;
goto V_61;
}
}
} else if ( V_33 -> V_60 ) {
V_10 = F_26 ( V_25 ) ;
}
V_61:
F_39 ( & V_33 -> V_59 ) ;
return V_10 ;
}
static int F_42 ( struct V_32 * V_18 ,
struct V_1 * V_2 )
{
const struct V_62 * V_63 ;
V_63 = F_43 ( F_44 ( V_64 ) , V_18 ) ;
if ( ! V_63 )
return - V_65 ;
V_2 -> V_14 = ( const struct V_13 * ) V_63 -> V_66 ;
if ( ! V_2 -> V_14 )
return - V_65 ;
return 0 ;
}
static int F_42 ( struct V_32 * V_18 ,
struct V_1 * V_2 )
{
return - V_65 ;
}
static int F_45 ( struct V_58 * V_17 ,
const struct V_67 * V_24 )
{
const struct V_68 * V_69 =
F_46 ( & V_17 -> V_18 ) ;
struct V_32 * V_18 = & V_17 -> V_18 ;
struct V_1 * V_2 ;
struct V_57 * V_33 ;
int error ;
V_2 = F_47 ( V_18 , sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 )
return - V_71 ;
if ( V_69 ) {
V_2 -> V_14 = & V_69 -> V_14 ;
} else if ( V_18 -> V_72 ) {
error = F_42 ( V_18 , V_2 ) ;
if ( error )
return error ;
} else {
F_3 ( & V_17 -> V_18 , L_12 ) ;
return - V_65 ;
}
if ( ! V_2 -> V_14 -> V_16 ) {
F_3 ( V_18 , L_13 ) ;
return - V_65 ;
}
V_33 = F_48 ( V_18 ) ;
if ( ! V_33 ) {
F_3 ( V_18 , L_14 ) ;
return - V_71 ;
}
V_2 -> V_17 = V_17 ;
V_2 -> V_33 = V_33 ;
V_33 -> V_73 = V_17 -> V_73 ;
V_33 -> V_24 . V_74 = V_75 ;
V_33 -> V_76 = F_30 ;
V_33 -> V_77 = F_32 ;
V_33 -> V_18 . V_78 = & V_17 -> V_18 ;
if ( V_69 ) {
F_49 ( V_33 , V_36 , 0 , V_69 -> V_79 , 0 , 0 ) ;
F_49 ( V_33 , V_37 , 0 , V_69 -> V_80 , 0 , 0 ) ;
} else {
F_50 ( V_33 , V_35 , V_36 ) ;
F_50 ( V_33 , V_35 , V_37 ) ;
F_51 ( V_33 , true ) ;
if ( ! F_52 ( V_33 , V_36 ) ||
! F_52 ( V_33 , V_37 ) ) {
F_3 ( V_18 , L_15 ) ;
return - V_65 ;
}
}
V_2 -> V_16 = V_2 -> V_14 -> V_16 ;
if ( V_2 -> V_16 > V_6 ) {
V_2 -> V_16 = V_6 ;
F_53 ( V_18 , L_16 ,
V_2 -> V_16 ) ;
}
error = F_54 ( V_33 , V_2 -> V_16 ,
V_81 | V_82 ) ;
if ( error ) {
F_3 ( V_18 , L_17 ) ;
return error ;
}
F_55 ( V_33 , V_2 ) ;
V_2 -> V_41 = F_56 ( V_18 , L_18 , V_83 ) ;
if ( F_57 ( V_2 -> V_41 ) ) {
error = F_58 ( V_2 -> V_41 ) ;
F_3 ( V_18 , L_19 , error ) ;
return error ;
}
V_2 -> V_43 = F_59 ( V_18 , L_20 ,
V_84 ) ;
if ( F_57 ( V_2 -> V_43 ) ) {
error = F_58 ( V_2 -> V_43 ) ;
F_3 ( V_18 , L_21 , error ) ;
return error ;
}
error = F_60 ( V_18 , V_17 -> V_38 , NULL , F_14 ,
V_85 | V_86 ,
V_17 -> V_73 , V_2 ) ;
if ( error ) {
F_3 ( V_18 , L_22 , V_17 -> V_38 ) ;
return error ;
}
F_17 ( V_2 ) ;
error = F_21 ( V_2 , V_87 ) ;
if ( error ) {
F_3 ( V_18 , L_23 ) ;
return error ;
}
error = F_28 ( V_2 ) ;
if ( error )
return error ;
error = F_61 ( V_33 ) ;
if ( error )
return error ;
F_62 ( V_17 , V_2 ) ;
F_63 ( & V_17 -> V_18 , 1 ) ;
return 0 ;
}
static int F_64 ( struct V_58 * V_17 )
{
F_63 ( & V_17 -> V_18 , 0 ) ;
return 0 ;
}
