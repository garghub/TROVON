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
F_5 ( & V_4 -> V_21 [ V_11 ] , & V_2 -> V_22 ,
F_6 ( V_8 ) ,
F_6 ( V_8 + 2 ) ) ;
if ( V_14 -> V_15 ) {
V_4 -> V_23 [ V_11 ] = V_8 [ 4 ] ;
V_8 = V_8 + 5 ;
} else {
V_8 = V_8 + 4 ;
}
}
}
static void F_7 ( struct V_1 * V_24 ,
struct V_3 * V_4 )
{
int V_25 [ V_6 ] ;
int V_26 , V_11 , V_27 ;
struct V_28 * V_18 = & V_24 -> V_17 -> V_18 ;
const struct V_13 * V_14 = V_24 -> V_14 ;
V_26 = V_4 -> V_20 ;
if ( V_26 > V_6 )
V_26 = V_6 ;
if ( ! V_24 -> V_14 -> V_15 )
F_8 ( V_24 -> V_29 , V_25 , V_4 -> V_21 , V_26 , 0 ) ;
for ( V_11 = 0 ; V_11 < V_26 ; V_11 ++ ) {
if ( V_14 -> V_15 ) {
V_27 = F_9 ( V_24 -> V_29 ,
V_4 -> V_23 [ V_11 ] ) ;
if ( V_27 < 0 ) {
F_10 ( V_18 , L_3 ,
V_4 -> V_23 [ V_11 ] ) ;
continue;
}
} else {
V_27 = V_25 [ V_11 ] ;
}
F_11 ( V_24 -> V_29 , V_27 ) ;
F_12 ( V_24 -> V_29 , V_30 , true ) ;
F_13 ( V_24 -> V_29 , V_31 ,
V_4 -> V_21 [ V_11 ] . V_32 ) ;
F_13 ( V_24 -> V_29 , V_33 ,
V_4 -> V_21 [ V_11 ] . V_34 ) ;
F_10 ( V_18 , L_4 ,
V_11 , V_27 , V_4 -> V_21 [ V_11 ] . V_32 , V_4 -> V_21 [ V_11 ] . V_34 ) ;
}
F_14 ( V_24 -> V_29 ) ;
F_15 ( V_24 -> V_29 ) ;
}
static T_2 F_16 ( int V_35 , void * V_36 )
{
struct V_1 * V_2 = V_36 ;
struct V_3 V_4 ;
while ( V_2 -> V_37 ) {
F_1 ( V_2 , & V_4 ) ;
F_7 ( V_2 , & V_4 ) ;
if ( F_17 ( V_2 -> V_38 ) ) {
if ( V_4 . V_20 ) {
F_14 ( V_2 -> V_29 ) ;
F_15 ( V_2 -> V_29 ) ;
}
break;
}
F_18 ( 20 ) ;
}
return V_39 ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( ! F_20 ( V_2 -> V_40 ) ) {
F_21 ( V_2 -> V_40 , 1 ) ;
F_22 ( 100 ) ;
F_21 ( V_2 -> V_40 , 0 ) ;
F_18 ( 100 ) ;
}
}
static int F_23 ( struct V_1 * V_24 ,
enum V_41 V_42 )
{
struct V_28 * V_18 = & V_24 -> V_17 -> V_18 ;
int V_10 ;
if ( V_42 == V_43 || V_42 == V_44 ) {
if ( V_24 -> V_45 )
F_21 ( V_24 -> V_45 , 1 ) ;
}
V_10 = F_24 ( V_24 -> V_17 , V_46 ) ;
if ( V_10 < 0 ) {
F_3 ( V_18 , L_5 ,
V_19 , V_46 , V_10 ) ;
return V_10 ;
}
V_10 &= ~ V_47 ;
V_10 |= V_42 ;
V_10 |= V_48 ;
V_10 = F_25 ( V_24 -> V_17 , V_46 , V_10 ) ;
if ( V_10 < 0 ) {
F_3 ( V_18 , L_6 ,
V_19 , V_46 , V_10 ) ;
return V_10 ;
}
if ( V_42 == V_49 ) {
if ( V_24 -> V_45 )
F_21 ( V_24 -> V_45 , 0 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_24 ,
enum V_50 V_42 , bool V_51 )
{
struct V_28 * V_18 = & V_24 -> V_17 -> V_18 ;
int V_10 ;
V_10 = F_24 ( V_24 -> V_17 , V_52 ) ;
if ( V_10 < 0 ) {
F_3 ( V_18 , L_5 ,
V_19 , V_52 , V_10 ) ;
return V_10 ;
}
V_10 &= ~ V_53 ;
V_10 |= V_42 ;
if ( V_51 )
V_10 |= V_54 ;
else
V_10 &= ~ V_54 ;
V_10 = F_25 ( V_24 -> V_17 , V_52 , V_10 ) ;
if ( V_10 < 0 ) {
F_3 ( V_18 , L_6 ,
V_19 , V_52 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_24 , bool V_55 )
{
struct V_28 * V_18 = & V_24 -> V_17 -> V_18 ;
int V_10 ;
V_10 = F_24 ( V_24 -> V_17 , V_52 ) ;
if ( V_10 < 0 ) {
F_3 ( V_18 , L_5 ,
V_19 , V_52 , V_10 ) ;
return V_10 ;
}
if ( V_55 )
V_10 |= V_56 ;
else
V_10 &= ~ V_56 ;
V_10 = F_25 ( V_24 -> V_17 , V_52 , V_10 ) ;
if ( V_10 < 0 ) {
F_3 ( V_18 , L_6 ,
V_19 , V_52 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_24 )
{
struct V_28 * V_18 = & V_24 -> V_17 -> V_18 ;
int error ;
if ( V_24 -> V_57 ) {
F_21 ( V_24 -> V_57 , 1 ) ;
F_18 ( 100 ) ;
}
error = F_26 ( V_24 , V_58 , 0 ) ;
if ( error ) {
F_3 ( V_18 , L_7 , error ) ;
return error ;
}
V_24 -> V_37 = true ;
F_29 () ;
error = F_27 ( V_24 , true ) ;
if ( error ) {
F_3 ( V_18 , L_8 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_24 )
{
int error ;
error = F_27 ( V_24 , false ) ;
if ( error ) {
F_3 ( & V_24 -> V_17 -> V_18 ,
L_9 ,
error ) ;
return error ;
}
V_24 -> V_37 = false ;
F_29 () ;
F_31 ( V_24 -> V_17 -> V_35 ) ;
if ( V_24 -> V_57 )
F_21 ( V_24 -> V_57 , 0 ) ;
return 0 ;
}
static int F_32 ( struct V_59 * V_18 )
{
struct V_1 * V_24 = F_33 ( V_18 ) ;
return F_28 ( V_24 ) ;
}
static void F_34 ( struct V_59 * V_18 )
{
struct V_1 * V_24 = F_33 ( V_18 ) ;
F_30 ( V_24 ) ;
}
static int T_3 F_35 ( struct V_28 * V_18 )
{
struct V_60 * V_17 = F_36 ( V_18 ) ;
struct V_1 * V_24 = F_37 ( V_17 ) ;
struct V_59 * V_29 = V_24 -> V_29 ;
int V_10 = 0 ;
F_38 ( & V_29 -> V_61 ) ;
if ( F_39 ( & V_17 -> V_18 ) ) {
if ( ! V_29 -> V_62 ) {
V_10 = F_28 ( V_24 ) ;
if ( V_10 ) {
F_3 ( V_18 , L_10 ) ;
goto V_63;
}
}
} else if ( V_29 -> V_62 ) {
V_10 = F_30 ( V_24 ) ;
}
V_63:
F_40 ( & V_29 -> V_61 ) ;
return V_10 ;
}
static int T_3 F_41 ( struct V_28 * V_18 )
{
struct V_60 * V_17 = F_36 ( V_18 ) ;
struct V_1 * V_24 = F_37 ( V_17 ) ;
struct V_59 * V_29 = V_24 -> V_29 ;
int V_10 = 0 ;
F_38 ( & V_29 -> V_61 ) ;
if ( F_39 ( & V_17 -> V_18 ) ) {
if ( ! V_29 -> V_62 ) {
V_10 = F_30 ( V_24 ) ;
if ( V_10 ) {
F_3 ( V_18 , L_11 ) ;
goto V_63;
}
}
} else if ( V_29 -> V_62 ) {
V_10 = F_28 ( V_24 ) ;
}
V_63:
F_40 ( & V_29 -> V_61 ) ;
return V_10 ;
}
static int F_42 ( struct V_28 * V_18 ,
struct V_1 * V_2 )
{
V_2 -> V_14 = F_43 ( V_18 ) ;
if ( ! V_2 -> V_14 )
return - V_64 ;
return 0 ;
}
static int F_42 ( struct V_28 * V_18 ,
struct V_1 * V_2 )
{
return - V_64 ;
}
static int F_44 ( struct V_60 * V_17 ,
const struct V_65 * V_66 )
{
const struct V_67 * V_68 =
F_45 ( & V_17 -> V_18 ) ;
struct V_28 * V_18 = & V_17 -> V_18 ;
struct V_1 * V_2 ;
struct V_59 * V_29 ;
int error ;
V_2 = F_46 ( V_18 , sizeof( * V_2 ) , V_69 ) ;
if ( ! V_2 )
return - V_70 ;
if ( V_68 ) {
V_2 -> V_14 = & V_68 -> V_14 ;
} else if ( V_18 -> V_71 ) {
error = F_42 ( V_18 , V_2 ) ;
if ( error )
return error ;
} else {
F_3 ( & V_17 -> V_18 , L_12 ) ;
return - V_64 ;
}
if ( ! V_2 -> V_14 -> V_16 ) {
F_3 ( V_18 , L_13 ) ;
return - V_64 ;
}
V_29 = F_47 ( V_18 ) ;
if ( ! V_29 ) {
F_3 ( V_18 , L_14 ) ;
return - V_70 ;
}
V_2 -> V_17 = V_17 ;
V_2 -> V_29 = V_29 ;
V_29 -> V_72 = V_17 -> V_72 ;
V_29 -> V_66 . V_73 = V_74 ;
V_29 -> V_75 = F_32 ;
V_29 -> V_76 = F_34 ;
V_29 -> V_18 . V_77 = & V_17 -> V_18 ;
if ( V_68 ) {
F_48 ( V_29 , V_31 , 0 , V_68 -> V_78 , 0 , 0 ) ;
F_48 ( V_29 , V_33 , 0 , V_68 -> V_79 , 0 , 0 ) ;
} else {
F_49 ( V_29 , V_80 , V_31 ) ;
F_49 ( V_29 , V_80 , V_33 ) ;
F_50 ( V_29 , true , & V_2 -> V_22 ) ;
if ( ! F_51 ( V_29 , V_31 ) ||
! F_51 ( V_29 , V_33 ) ) {
F_3 ( V_18 , L_15 ) ;
return - V_64 ;
}
}
V_2 -> V_16 = V_2 -> V_14 -> V_16 ;
if ( V_2 -> V_16 > V_6 ) {
V_2 -> V_16 = V_6 ;
F_52 ( V_18 , L_16 ,
V_2 -> V_16 ) ;
}
error = F_53 ( V_29 , V_2 -> V_16 ,
V_81 | V_82 ) ;
if ( error ) {
F_3 ( V_18 , L_17 ) ;
return error ;
}
F_54 ( V_29 , V_2 ) ;
V_2 -> V_38 = F_55 ( V_18 , L_18 , V_83 ) ;
if ( F_56 ( V_2 -> V_38 ) ) {
error = F_57 ( V_2 -> V_38 ) ;
F_3 ( V_18 , L_19 , error ) ;
return error ;
}
V_2 -> V_40 = F_58 ( V_18 , L_20 ,
V_84 ) ;
if ( F_56 ( V_2 -> V_40 ) ) {
error = F_57 ( V_2 -> V_40 ) ;
F_3 ( V_18 , L_21 , error ) ;
return error ;
}
V_2 -> V_45 = F_58 ( V_18 , L_22 ,
V_85 ) ;
if ( F_56 ( V_2 -> V_45 ) ) {
error = F_57 ( V_2 -> V_45 ) ;
if ( error != - V_86 )
F_3 ( V_18 , L_23 , error ) ;
return error ;
}
V_2 -> V_57 = F_58 ( V_18 , L_24 ,
V_85 ) ;
if ( F_56 ( V_2 -> V_57 ) ) {
error = F_57 ( V_2 -> V_57 ) ;
if ( error != - V_86 )
F_3 ( V_18 , L_25 , error ) ;
return error ;
}
if ( V_2 -> V_57 )
F_18 ( 100 ) ;
error = F_59 ( V_18 , V_17 -> V_35 , NULL , F_16 ,
V_87 | V_88 ,
V_17 -> V_72 , V_2 ) ;
if ( error ) {
F_3 ( V_18 , L_26 , V_17 -> V_35 ) ;
return error ;
}
F_19 ( V_2 ) ;
error = F_23 ( V_2 , V_44 ) ;
if ( error ) {
F_3 ( V_18 , L_27 ) ;
return error ;
}
error = F_30 ( V_2 ) ;
if ( error )
return error ;
error = F_60 ( V_29 ) ;
if ( error )
return error ;
F_61 ( V_17 , V_2 ) ;
return 0 ;
}
