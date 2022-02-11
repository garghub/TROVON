static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
const struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_9 [ 8 ] ;
T_1 V_10 [ 4 ] ;
int V_11 , V_12 ;
V_12 = F_2 ( V_6 , V_13 ,
8 , V_9 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_6 -> V_14 , L_1 , V_12 ) ;
return V_12 ;
}
V_12 = F_2 ( V_6 , V_15 ,
4 , V_10 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_6 -> V_14 , L_2 , V_12 ) ;
return V_12 ;
}
for ( V_11 = 0 ; V_11 < V_16 ; V_11 ++ ) {
V_4 [ V_11 ] . V_17 =
V_9 [ 4 * V_11 + 1 ] << 8 | V_9 [ 4 * V_11 ] ;
V_4 [ V_11 ] . V_18 =
V_9 [ 4 * V_11 + 3 ] << 8 | V_9 [ 4 * V_11 + 2 ] ;
if ( V_4 [ V_11 ] . V_17 > V_8 -> V_19 ||
V_4 [ V_11 ] . V_18 > V_8 -> V_20 ) {
F_4 ( & V_6 -> V_14 , L_3 ,
V_4 [ V_11 ] . V_17 , V_4 [ V_11 ] . V_18 ) ;
V_4 [ V_11 ] . V_17 = V_4 [ V_11 ] . V_18 = 0 ;
}
V_4 [ V_11 ] . V_21 = F_5 ( V_10 [ 2 * V_11 ] , V_10 [ 2 * V_11 + 1 ] ) ;
V_4 [ V_11 ] . V_22 = F_6 ( V_10 [ 2 * V_11 ] , V_10 [ 2 * V_11 + 1 ] ) ;
V_4 [ V_11 ] . V_23 = V_10 [ 2 * V_11 ] > V_10 [ 2 * V_11 + 1 ] ;
}
return 0 ;
}
static T_2 F_7 ( int V_24 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
const struct V_7 * V_8 = V_2 -> V_8 ;
struct V_3 V_4 [ V_16 ] ;
int V_11 ;
int V_12 ;
int V_26 = 0 ;
int abs = - 1 ;
while ( ! V_2 -> V_27 ) {
if ( V_2 -> V_28 ) {
if ( F_8 ( V_8 -> V_29 ) == 0 ) {
F_9 ( V_2 -> V_30 ) ;
F_10 ( V_2 -> V_30 , V_31 , 0 ) ;
F_11 ( V_2 -> V_30 ) ;
break;
}
}
V_12 = F_1 ( V_2 , V_4 ) ;
if ( V_12 < 0 ) {
if ( ! V_2 -> V_28 )
break;
F_12 ( V_2 -> V_32 , V_2 -> V_27 ,
F_13 ( V_33 ) ) ;
continue;
}
for ( V_11 = 0 ; V_11 < V_16 ; V_11 ++ ) {
if ( V_4 [ V_11 ] . V_17 > 0 || V_4 [ V_11 ] . V_18 > 0 ) {
F_14 ( V_2 -> V_30 , V_34 ,
V_4 [ V_11 ] . V_17 ) ;
F_14 ( V_2 -> V_30 , V_35 ,
V_4 [ V_11 ] . V_18 ) ;
F_14 ( V_2 -> V_30 , V_36 ,
V_4 [ V_11 ] . V_21 ) ;
F_14 ( V_2 -> V_30 , V_37 ,
V_4 [ V_11 ] . V_22 ) ;
F_14 ( V_2 -> V_30 , V_38 ,
V_4 [ V_11 ] . V_23 ) ;
F_9 ( V_2 -> V_30 ) ;
if ( V_26 == 0 )
abs = V_11 ;
V_26 ++ ;
}
}
F_10 ( V_2 -> V_30 , V_31 , V_26 > 0 ) ;
if ( abs > - 1 ) {
F_14 ( V_2 -> V_30 , V_39 , V_4 [ abs ] . V_17 ) ;
F_14 ( V_2 -> V_30 , V_40 , V_4 [ abs ] . V_18 ) ;
}
F_11 ( V_2 -> V_30 ) ;
if ( ! V_2 -> V_28 )
break;
F_12 ( V_2 -> V_32 , V_2 -> V_27 ,
F_13 ( V_33 ) ) ;
}
return V_41 ;
}
static int F_15 ( struct V_1 * V_2 , int V_42 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_12 ;
V_12 = F_16 ( V_6 , V_43 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_6 -> V_14 , L_4 ,
V_43 , V_12 ) ;
return V_12 ;
}
V_12 &= ~ V_44 ;
V_12 |= V_42 ;
V_12 = F_17 ( V_6 , V_43 , V_12 ) ;
if ( V_12 ) {
F_3 ( & V_6 -> V_14 , L_5 ,
V_43 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
int V_45 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
const struct V_7 * V_8 = V_2 -> V_8 ;
int V_12 ;
V_12 = F_16 ( V_6 , V_46 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_6 -> V_14 , L_4 ,
V_46 , V_12 ) ;
return V_12 ;
}
V_12 &= ~ V_47 ;
V_12 |= V_45 ;
V_12 |= V_48 ;
V_12 = F_17 ( V_6 , V_46 ,
V_12 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_6 -> V_14 , L_5 ,
V_46 , V_12 ) ;
return V_12 ;
}
V_2 -> V_28 = V_8 -> V_45 == V_49 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , bool V_50 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_12 ;
V_12 = F_16 ( V_6 , V_46 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_6 -> V_14 , L_4 ,
V_46 , V_12 ) ;
return V_12 ;
}
if ( V_50 )
V_12 |= V_51 ;
else
V_12 &= ~ V_51 ;
V_12 = F_17 ( V_6 , V_46 ,
V_12 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_6 -> V_14 , L_5 ,
V_46 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_12 ;
V_12 = F_15 ( V_2 , V_52 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_6 -> V_14 , L_6 ,
V_12 ) ;
return V_12 ;
}
V_2 -> V_27 = false ;
F_21 () ;
F_22 ( V_6 -> V_24 ) ;
V_12 = F_19 ( V_2 , 1 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_6 -> V_14 , L_7 ,
V_12 ) ;
F_23 ( V_6 -> V_24 ) ;
return V_12 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_12 ;
V_12 = F_19 ( V_2 , 0 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_6 -> V_14 , L_8 ,
V_12 ) ;
return V_12 ;
}
F_23 ( V_6 -> V_24 ) ;
V_2 -> V_27 = true ;
F_21 () ;
F_25 ( & V_2 -> V_32 ) ;
return F_15 ( V_2 , V_53 ) ;
}
static int F_26 ( struct V_54 * V_14 )
{
struct V_1 * V_2 = F_27 ( V_14 ) ;
return F_20 ( V_2 ) ;
}
static void F_28 ( struct V_54 * V_14 )
{
struct V_1 * V_2 = F_27 ( V_14 ) ;
F_24 ( V_2 ) ;
return;
}
static int T_3 F_29 ( struct V_55 * V_14 )
{
struct V_5 * V_6 = F_30 ( V_14 ) ;
struct V_1 * V_2 = F_31 ( V_6 ) ;
struct V_54 * V_30 = V_2 -> V_30 ;
int V_12 = 0 ;
F_32 ( & V_30 -> V_56 ) ;
if ( F_33 ( & V_6 -> V_14 ) ) {
if ( ! V_30 -> V_57 ) {
V_12 = F_20 ( V_2 ) ;
if ( V_12 )
goto V_58;
}
F_34 ( V_6 -> V_24 ) ;
V_12 = F_15 ( V_2 , V_59 ) ;
} else if ( V_30 -> V_57 ) {
V_12 = F_24 ( V_2 ) ;
}
V_58:
F_35 ( & V_30 -> V_56 ) ;
return V_12 ;
}
static int T_3 F_36 ( struct V_55 * V_14 )
{
struct V_5 * V_6 = F_30 ( V_14 ) ;
struct V_1 * V_2 = F_31 ( V_6 ) ;
struct V_54 * V_30 = V_2 -> V_30 ;
int V_12 = 0 ;
F_32 ( & V_30 -> V_56 ) ;
if ( F_33 ( & V_6 -> V_14 ) ) {
F_37 ( V_6 -> V_24 ) ;
if ( ! V_30 -> V_57 ) {
V_12 = F_24 ( V_2 ) ;
if ( V_12 )
goto V_58;
}
} else if ( V_30 -> V_57 ) {
V_12 = F_20 ( V_2 ) ;
}
V_58:
F_35 ( & V_30 -> V_56 ) ;
return V_12 ;
}
static struct V_7 * F_38 ( struct V_55 * V_14 )
{
struct V_7 * V_8 ;
struct V_60 * V_61 = V_14 -> V_62 ;
if ( ! V_61 )
return F_39 ( - V_63 ) ;
V_8 = F_40 ( V_14 , sizeof( * V_8 ) , V_64 ) ;
if ( ! V_8 ) {
F_3 ( V_14 , L_9 ) ;
return F_39 ( - V_65 ) ;
}
V_8 -> V_29 = F_41 ( V_61 , 0 ) ;
if ( ! F_42 ( V_8 -> V_29 ) ) {
F_3 ( V_14 , L_10 ) ;
return F_39 ( - V_66 ) ;
}
V_8 -> V_67 = F_41 ( V_61 , 1 ) ;
if ( ! F_42 ( V_8 -> V_67 ) ) {
F_3 ( V_14 , L_11 ) ;
return F_39 ( - V_66 ) ;
}
if ( F_43 ( V_61 , L_12 , & V_8 -> V_19 ) ) {
F_3 ( V_14 , L_13 ) ;
return F_39 ( - V_66 ) ;
}
if ( F_43 ( V_61 , L_14 , & V_8 -> V_20 ) ) {
F_3 ( V_14 , L_15 ) ;
return F_39 ( - V_66 ) ;
}
V_8 -> V_45 = V_49 ;
return V_8 ;
}
static struct V_7 * F_38 ( struct V_55 * V_14 )
{
return F_39 ( - V_66 ) ;
}
static void F_44 ( void * V_68 )
{
struct V_1 * V_2 = V_68 ;
F_45 ( V_2 -> V_8 -> V_67 , 0 ) ;
}
static int F_46 ( struct V_5 * V_6 ,
const struct V_69 * V_70 )
{
const struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_54 * V_54 ;
int V_71 ;
int error ;
V_8 = F_47 ( & V_6 -> V_14 ) ;
if ( ! V_8 ) {
V_8 = F_38 ( & V_6 -> V_14 ) ;
if ( F_48 ( V_8 ) )
return F_49 ( V_8 ) ;
}
V_2 = F_40 ( & V_6 -> V_14 ,
sizeof( struct V_1 ) , V_64 ) ;
if ( ! V_2 )
return - V_65 ;
V_54 = F_50 ( & V_6 -> V_14 ) ;
if ( ! V_54 ) {
F_3 ( & V_6 -> V_14 , L_16 ) ;
return - V_65 ;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_30 = V_54 ;
V_2 -> V_28 = 0 ;
V_2 -> V_27 = true ;
F_51 ( & V_2 -> V_32 ) ;
snprintf ( V_2 -> V_72 , sizeof( V_2 -> V_72 ) ,
L_17 , F_52 ( & V_6 -> V_14 ) ) ;
V_54 -> V_73 = L_18 ;
V_54 -> V_72 = V_2 -> V_72 ;
V_54 -> V_70 . V_74 = V_75 ;
V_54 -> V_76 = F_26 ;
V_54 -> V_77 = F_28 ;
F_53 ( V_78 , V_54 -> V_79 ) ;
F_53 ( V_80 , V_54 -> V_79 ) ;
F_53 ( V_31 , V_54 -> V_81 ) ;
F_54 ( V_54 , V_39 , 0 , V_8 -> V_19 , 0 , 0 ) ;
F_54 ( V_54 , V_40 , 0 , V_8 -> V_20 , 0 , 0 ) ;
F_54 ( V_54 , V_34 , 0 ,
V_8 -> V_19 , 0 , 0 ) ;
F_54 ( V_54 , V_35 , 0 ,
V_8 -> V_20 , 0 , 0 ) ;
F_54 ( V_54 , V_36 , 0 ,
V_82 , 0 , 0 ) ;
F_54 ( V_54 , V_37 , 0 ,
V_82 , 0 , 0 ) ;
F_54 ( V_54 , V_38 , 0 , 1 , 0 , 0 ) ;
F_55 ( V_2 -> V_30 , V_2 ) ;
error = F_56 ( & V_6 -> V_14 , V_8 -> V_29 ,
V_83 , L_19 ) ;
if ( error ) {
F_3 ( & V_6 -> V_14 , L_20 ,
V_8 -> V_29 , error ) ;
return error ;
}
error = F_56 ( & V_6 -> V_14 , V_8 -> V_67 ,
V_84 | V_85 ,
L_21 ) ;
if ( error ) {
F_3 ( & V_6 -> V_14 , L_20 ,
V_8 -> V_67 , error ) ;
return error ;
}
error = F_57 ( & V_6 -> V_14 , F_44 , V_2 ) ;
if ( error ) {
F_44 ( V_2 ) ;
F_3 ( & V_6 -> V_14 , L_22 ,
error ) ;
return error ;
}
F_58 ( 200 ) ;
V_71 = F_16 ( V_6 , V_86 ) ;
if ( V_71 < 0 ) {
error = V_71 ;
return error ;
}
F_59 ( & V_6 -> V_14 , L_23 , V_71 ) ;
error = F_18 ( V_2 , V_8 -> V_45 ) ;
if ( error )
return error ;
error = F_60 ( & V_6 -> V_14 , V_6 -> V_24 ,
NULL , F_7 ,
V_87 | V_88 ,
V_54 -> V_73 , V_2 ) ;
if ( error ) {
F_3 ( & V_6 -> V_14 , L_24 ,
V_6 -> V_24 , error ) ;
return error ;
}
error = F_24 ( V_2 ) ;
if ( error )
return error ;
error = F_61 ( V_54 ) ;
if ( error ) {
F_3 ( & V_6 -> V_14 , L_25 ,
error ) ;
return error ;
}
F_62 ( V_6 , V_2 ) ;
return 0 ;
}
