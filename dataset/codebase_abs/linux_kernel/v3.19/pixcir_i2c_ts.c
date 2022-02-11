static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 [ 2 + V_6 * 5 ] ;
T_1 V_7 [ 1 ] = { 0 } ;
T_1 * V_8 ;
T_1 V_9 ;
int V_10 , V_11 ;
int V_12 ;
const struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_11 = V_14 -> V_16 ? 1 : 0 ;
V_12 = 2 + V_2 -> V_17 * ( 4 + V_11 ) ;
if ( V_12 > sizeof( V_5 ) )
V_12 = sizeof( V_5 ) ;
V_10 = F_2 ( V_2 -> V_18 , V_7 , sizeof( V_7 ) ) ;
if ( V_10 != sizeof( V_7 ) ) {
F_3 ( & V_2 -> V_18 -> V_19 ,
L_1 ,
V_20 , V_10 ) ;
return;
}
V_10 = F_4 ( V_2 -> V_18 , V_5 , V_12 ) ;
if ( V_10 != sizeof( V_5 ) ) {
F_3 ( & V_2 -> V_18 -> V_19 ,
L_2 ,
V_20 , V_10 ) ;
return;
}
V_9 = V_5 [ 0 ] & 0x7 ;
if ( V_9 > V_2 -> V_17 )
V_9 = V_2 -> V_17 ;
V_4 -> V_21 = V_9 ;
V_8 = & V_5 [ 2 ] ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
V_4 -> V_22 [ V_11 ] . V_23 = ( V_8 [ 1 ] << 8 ) | V_8 [ 0 ] ;
V_4 -> V_22 [ V_11 ] . V_24 = ( V_8 [ 3 ] << 8 ) | V_8 [ 2 ] ;
if ( V_14 -> V_16 ) {
V_4 -> V_22 [ V_11 ] . V_25 = V_8 [ 4 ] ;
V_8 = V_8 + 5 ;
} else {
V_8 = V_8 + 4 ;
}
}
}
static void F_5 ( struct V_1 * V_26 ,
struct V_3 * V_4 )
{
struct V_27 V_28 [ V_6 ] ;
int V_29 [ V_6 ] ;
struct V_30 * V_9 ;
int V_31 , V_11 , V_32 ;
struct V_33 * V_19 = & V_26 -> V_18 -> V_19 ;
const struct V_13 * V_14 = & V_26 -> V_15 -> V_14 ;
V_31 = V_4 -> V_21 ;
if ( V_31 > V_6 )
V_31 = V_6 ;
if ( ! V_14 -> V_16 ) {
for ( V_11 = 0 ; V_11 < V_31 ; V_11 ++ ) {
V_9 = & V_4 -> V_22 [ V_11 ] ;
V_28 [ V_11 ] . V_23 = V_9 -> V_23 ;
V_28 [ V_11 ] . V_24 = V_9 -> V_24 ;
}
F_6 ( V_26 -> V_34 , V_29 , V_28 , V_31 ) ;
}
for ( V_11 = 0 ; V_11 < V_31 ; V_11 ++ ) {
V_9 = & V_4 -> V_22 [ V_11 ] ;
if ( V_14 -> V_16 ) {
V_32 = F_7 ( V_26 -> V_34 , V_9 -> V_25 ) ;
if ( V_32 < 0 ) {
F_8 ( V_19 , L_3 ,
V_9 -> V_25 ) ;
continue;
}
} else {
V_32 = V_29 [ V_11 ] ;
}
F_9 ( V_26 -> V_34 , V_32 ) ;
F_10 ( V_26 -> V_34 ,
V_35 , true ) ;
F_11 ( V_26 -> V_34 , V_36 , V_37 , V_9 -> V_23 ) ;
F_11 ( V_26 -> V_34 , V_36 , V_38 , V_9 -> V_24 ) ;
F_8 ( V_19 , L_4 ,
V_11 , V_32 , V_9 -> V_23 , V_9 -> V_24 ) ;
}
F_12 ( V_26 -> V_34 ) ;
F_13 ( V_26 -> V_34 ) ;
}
static T_2 F_14 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
const struct V_41 * V_15 = V_2 -> V_15 ;
struct V_3 V_4 ;
while ( V_2 -> V_42 ) {
F_1 ( V_2 , & V_4 ) ;
F_5 ( V_2 , & V_4 ) ;
if ( F_15 ( V_15 -> V_43 ) ) {
if ( V_4 . V_21 ) {
F_12 ( V_2 -> V_34 ) ;
F_13 ( V_2 -> V_34 ) ;
}
break;
}
F_16 ( 20 ) ;
}
return V_44 ;
}
static int F_17 ( struct V_1 * V_26 ,
enum V_45 V_46 )
{
struct V_33 * V_19 = & V_26 -> V_18 -> V_19 ;
int V_10 ;
V_10 = F_18 ( V_26 -> V_18 , V_47 ) ;
if ( V_10 < 0 ) {
F_3 ( V_19 , L_5 ,
V_20 , V_47 , V_10 ) ;
return V_10 ;
}
V_10 &= ~ V_48 ;
V_10 |= V_46 ;
V_10 |= V_49 ;
V_10 = F_19 ( V_26 -> V_18 , V_47 , V_10 ) ;
if ( V_10 < 0 ) {
F_3 ( V_19 , L_6 ,
V_20 , V_47 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_26 ,
enum V_50 V_46 , bool V_51 )
{
struct V_33 * V_19 = & V_26 -> V_18 -> V_19 ;
int V_10 ;
V_10 = F_18 ( V_26 -> V_18 , V_52 ) ;
if ( V_10 < 0 ) {
F_3 ( V_19 , L_5 ,
V_20 , V_52 , V_10 ) ;
return V_10 ;
}
V_10 &= ~ V_53 ;
V_10 |= V_46 ;
if ( V_51 )
V_10 |= V_54 ;
else
V_10 &= ~ V_54 ;
V_10 = F_19 ( V_26 -> V_18 , V_52 , V_10 ) ;
if ( V_10 < 0 ) {
F_3 ( V_19 , L_6 ,
V_20 , V_52 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_26 , bool V_55 )
{
struct V_33 * V_19 = & V_26 -> V_18 -> V_19 ;
int V_10 ;
V_10 = F_18 ( V_26 -> V_18 , V_52 ) ;
if ( V_10 < 0 ) {
F_3 ( V_19 , L_5 ,
V_20 , V_52 , V_10 ) ;
return V_10 ;
}
if ( V_55 )
V_10 |= V_56 ;
else
V_10 &= ~ V_56 ;
V_10 = F_19 ( V_26 -> V_18 , V_52 , V_10 ) ;
if ( V_10 < 0 ) {
F_3 ( V_19 , L_6 ,
V_20 , V_52 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_26 )
{
struct V_33 * V_19 = & V_26 -> V_18 -> V_19 ;
int error ;
error = F_20 ( V_26 , V_57 , 0 ) ;
if ( error ) {
F_3 ( V_19 , L_7 , error ) ;
return error ;
}
V_26 -> V_42 = true ;
F_23 () ;
error = F_21 ( V_26 , true ) ;
if ( error ) {
F_3 ( V_19 , L_8 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_26 )
{
int error ;
error = F_21 ( V_26 , false ) ;
if ( error ) {
F_3 ( & V_26 -> V_18 -> V_19 ,
L_9 ,
error ) ;
return error ;
}
V_26 -> V_42 = false ;
F_23 () ;
F_25 ( V_26 -> V_18 -> V_39 ) ;
return 0 ;
}
static int F_26 ( struct V_58 * V_19 )
{
struct V_1 * V_26 = F_27 ( V_19 ) ;
return F_22 ( V_26 ) ;
}
static void F_28 ( struct V_58 * V_19 )
{
struct V_1 * V_26 = F_27 ( V_19 ) ;
F_24 ( V_26 ) ;
}
static int T_3 F_29 ( struct V_33 * V_19 )
{
struct V_59 * V_18 = F_30 ( V_19 ) ;
struct V_1 * V_26 = F_31 ( V_18 ) ;
struct V_58 * V_34 = V_26 -> V_34 ;
int V_10 = 0 ;
F_32 ( & V_34 -> V_60 ) ;
if ( F_33 ( & V_18 -> V_19 ) ) {
if ( ! V_34 -> V_61 ) {
V_10 = F_22 ( V_26 ) ;
if ( V_10 ) {
F_3 ( V_19 , L_10 ) ;
goto V_62;
}
}
F_34 ( V_18 -> V_39 ) ;
} else if ( V_34 -> V_61 ) {
V_10 = F_24 ( V_26 ) ;
}
V_62:
F_35 ( & V_34 -> V_60 ) ;
return V_10 ;
}
static int T_3 F_36 ( struct V_33 * V_19 )
{
struct V_59 * V_18 = F_30 ( V_19 ) ;
struct V_1 * V_26 = F_31 ( V_18 ) ;
struct V_58 * V_34 = V_26 -> V_34 ;
int V_10 = 0 ;
F_32 ( & V_34 -> V_60 ) ;
if ( F_33 ( & V_18 -> V_19 ) ) {
F_37 ( V_18 -> V_39 ) ;
if ( ! V_34 -> V_61 ) {
V_10 = F_24 ( V_26 ) ;
if ( V_10 ) {
F_3 ( V_19 , L_11 ) ;
goto V_62;
}
}
} else if ( V_34 -> V_61 ) {
V_10 = F_22 ( V_26 ) ;
}
V_62:
F_35 ( & V_34 -> V_60 ) ;
return V_10 ;
}
static struct V_41 * F_38 ( struct V_33 * V_19 )
{
struct V_41 * V_15 ;
struct V_63 * V_64 = V_19 -> V_65 ;
const struct V_66 * V_67 ;
V_67 = F_39 ( F_40 ( V_68 ) , V_19 ) ;
if ( ! V_67 )
return F_41 ( - V_69 ) ;
V_15 = F_42 ( V_19 , sizeof( * V_15 ) , V_70 ) ;
if ( ! V_15 )
return F_41 ( - V_71 ) ;
V_15 -> V_14 = * ( const struct V_13 * ) V_67 -> V_72 ;
V_15 -> V_43 = F_43 ( V_64 , L_12 , 0 ) ;
if ( F_44 ( V_64 , L_13 , & V_15 -> V_73 ) ) {
F_3 ( V_19 , L_14 ) ;
return F_41 ( - V_69 ) ;
}
V_15 -> V_73 -= 1 ;
if ( F_44 ( V_64 , L_15 , & V_15 -> V_74 ) ) {
F_3 ( V_19 , L_16 ) ;
return F_41 ( - V_69 ) ;
}
V_15 -> V_74 -= 1 ;
F_8 ( V_19 , L_17 , V_20 ,
V_15 -> V_73 + 1 , V_15 -> V_74 + 1 , V_15 -> V_43 ) ;
return V_15 ;
}
static struct V_41 * F_38 ( struct V_33 * V_19 )
{
return F_41 ( - V_69 ) ;
}
static int F_45 ( struct V_59 * V_18 ,
const struct V_75 * V_25 )
{
const struct V_41 * V_15 =
F_46 ( & V_18 -> V_19 ) ;
struct V_33 * V_19 = & V_18 -> V_19 ;
struct V_63 * V_64 = V_19 -> V_65 ;
struct V_1 * V_2 ;
struct V_58 * V_34 ;
int error ;
if ( V_64 && ! V_15 ) {
V_15 = F_38 ( V_19 ) ;
if ( F_47 ( V_15 ) )
return F_48 ( V_15 ) ;
}
if ( ! V_15 ) {
F_3 ( & V_18 -> V_19 , L_18 ) ;
return - V_69 ;
}
if ( ! F_49 ( V_15 -> V_43 ) ) {
F_3 ( V_19 , L_19 ) ;
return - V_69 ;
}
if ( ! V_15 -> V_14 . V_17 ) {
F_3 ( V_19 , L_20 ) ;
return - V_69 ;
}
V_2 = F_42 ( V_19 , sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 )
return - V_71 ;
V_34 = F_50 ( V_19 ) ;
if ( ! V_34 ) {
F_3 ( V_19 , L_21 ) ;
return - V_71 ;
}
V_2 -> V_18 = V_18 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_15 = V_15 ;
V_34 -> V_76 = V_18 -> V_76 ;
V_34 -> V_25 . V_77 = V_78 ;
V_34 -> V_79 = F_26 ;
V_34 -> V_80 = F_28 ;
V_34 -> V_19 . V_81 = & V_18 -> V_19 ;
F_51 ( V_82 , V_34 -> V_83 ) ;
F_51 ( V_36 , V_34 -> V_83 ) ;
F_51 ( V_84 , V_34 -> V_85 ) ;
F_52 ( V_34 , V_86 , 0 , V_15 -> V_73 , 0 , 0 ) ;
F_52 ( V_34 , V_87 , 0 , V_15 -> V_74 , 0 , 0 ) ;
F_52 ( V_34 , V_37 , 0 , V_15 -> V_73 , 0 , 0 ) ;
F_52 ( V_34 , V_38 , 0 , V_15 -> V_74 , 0 , 0 ) ;
V_2 -> V_17 = V_2 -> V_15 -> V_14 . V_17 ;
if ( V_2 -> V_17 > V_6 ) {
V_2 -> V_17 = V_6 ;
F_53 ( V_19 , L_22 ,
V_2 -> V_17 ) ;
}
error = F_54 ( V_34 , V_2 -> V_17 ,
V_88 | V_89 ) ;
if ( error ) {
F_3 ( V_19 , L_23 ) ;
return error ;
}
F_55 ( V_34 , V_2 ) ;
error = F_56 ( V_19 , V_15 -> V_43 ,
V_90 , L_24 ) ;
if ( error ) {
F_3 ( V_19 , L_25 ) ;
return error ;
}
error = F_57 ( V_19 , V_18 -> V_39 , NULL , F_14 ,
V_91 | V_92 ,
V_18 -> V_76 , V_2 ) ;
if ( error ) {
F_3 ( V_19 , L_26 , V_18 -> V_39 ) ;
return error ;
}
error = F_17 ( V_2 , V_93 ) ;
if ( error ) {
F_3 ( V_19 , L_27 ) ;
return error ;
}
error = F_24 ( V_2 ) ;
if ( error )
return error ;
error = F_58 ( V_34 ) ;
if ( error )
return error ;
F_59 ( V_18 , V_2 ) ;
F_60 ( & V_18 -> V_19 , 1 ) ;
return 0 ;
}
static int F_61 ( struct V_59 * V_18 )
{
F_60 ( & V_18 -> V_19 , 0 ) ;
return 0 ;
}
