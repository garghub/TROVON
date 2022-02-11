static void
F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_3 ; V_4 ++ )
F_1 ( & V_2 -> V_5 [ V_4 ] ) ;
F_2 ( V_2 -> V_5 ) ;
} else {
if ( V_2 -> V_6 ) {
const struct V_7 * V_8 =
V_2 -> V_9 -> V_10 -> V_11 -> V_7 ;
int error ;
error = V_8 -> V_12 ( V_2 -> V_9 , V_2 -> V_13 , 0 ,
false ) ;
if ( error )
F_3 ( L_1 ) ;
}
if ( V_2 -> V_9 )
F_4 ( V_2 -> V_9 , V_14 | V_15 ) ;
}
}
void
F_5 ( struct V_16 * V_17 )
{
struct V_1 * V_2 =
F_6 ( V_17 , struct V_1 , V_18 ) ;
F_1 ( V_2 ) ;
F_7 ( V_2 , V_18 . V_19 ) ;
}
static int
F_8 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
T_1 * V_24 ;
int V_4 ;
V_24 = F_9 ( V_21 , 4 ) ;
if ( ! V_24 )
return - V_25 ;
V_23 -> type = F_10 ( V_24 ++ ) ;
switch ( V_23 -> type ) {
case V_26 :
V_24 = F_9 ( V_21 , 4 ) ;
if ( ! V_24 )
return - V_25 ;
V_23 -> V_27 . V_28 = F_10 ( V_24 ++ ) ;
if ( ! V_23 -> V_27 . V_28 || V_23 -> V_27 . V_28 > V_29 ) {
F_11 ( L_2 , V_23 -> V_27 . V_28 ) ;
return - V_25 ;
}
V_23 -> V_27 . V_30 = 4 + 4 ;
for ( V_4 = 0 ; V_4 < V_23 -> V_27 . V_28 ; V_4 ++ ) {
V_24 = F_9 ( V_21 , 8 + 4 ) ;
if ( ! V_24 )
return - V_25 ;
V_24 = F_12 ( V_24 , & V_23 -> V_27 . V_31 [ V_4 ] . V_32 ) ;
V_23 -> V_27 . V_31 [ V_4 ] . V_33 = F_10 ( V_24 ++ ) ;
if ( V_23 -> V_27 . V_31 [ V_4 ] . V_33 > V_34 ) {
F_13 ( L_3 ,
V_23 -> V_27 . V_31 [ V_4 ] . V_33 ) ;
return - V_25 ;
}
V_24 = F_9 ( V_21 , V_23 -> V_27 . V_31 [ V_4 ] . V_33 ) ;
if ( ! V_24 )
return - V_25 ;
memcpy ( & V_23 -> V_27 . V_31 [ V_4 ] . V_35 , V_24 ,
V_23 -> V_27 . V_31 [ V_4 ] . V_33 ) ;
V_23 -> V_27 . V_30 += 8 + 4 + \
( F_14 ( V_23 -> V_27 . V_31 [ V_4 ] . V_33 ) << 2 ) ;
}
break;
case V_36 :
V_24 = F_9 ( V_21 , 8 + 8 + 4 ) ;
if ( ! V_24 )
return - V_25 ;
V_24 = F_12 ( V_24 , & V_23 -> V_37 . V_38 ) ;
V_24 = F_12 ( V_24 , & V_23 -> V_37 . V_30 ) ;
V_23 -> V_37 . V_39 = F_10 ( V_24 ++ ) ;
break;
case V_40 :
V_24 = F_9 ( V_21 , 4 ) ;
if ( ! V_24 )
return - V_25 ;
V_23 -> V_41 . V_42 = F_10 ( V_24 ++ ) ;
if ( V_23 -> V_41 . V_42 > V_43 ) {
F_11 ( L_4 , V_23 -> V_41 . V_42 ) ;
return - V_25 ;
}
V_24 = F_9 ( V_21 , V_23 -> V_41 . V_42 * 4 ) ;
if ( ! V_24 )
return - V_25 ;
for ( V_4 = 0 ; V_4 < V_23 -> V_41 . V_42 ; V_4 ++ )
V_23 -> V_41 . V_44 [ V_4 ] = F_10 ( V_24 ++ ) ;
break;
case V_45 :
V_24 = F_9 ( V_21 , 8 + 4 ) ;
if ( ! V_24 )
return - V_25 ;
V_24 = F_12 ( V_24 , & V_23 -> V_46 . V_47 ) ;
V_23 -> V_46 . V_42 = F_10 ( V_24 ++ ) ;
if ( V_23 -> V_46 . V_42 > V_43 ) {
F_11 ( L_4 , V_23 -> V_46 . V_42 ) ;
return - V_25 ;
}
V_24 = F_9 ( V_21 , V_23 -> V_46 . V_42 * 4 ) ;
if ( ! V_24 )
return - V_25 ;
for ( V_4 = 0 ; V_4 < V_23 -> V_46 . V_42 ; V_4 ++ )
V_23 -> V_46 . V_44 [ V_4 ] = F_10 ( V_24 ++ ) ;
break;
case V_48 :
V_24 = F_9 ( V_21 , 4 + 4 + 4 ) ;
if ( ! V_24 )
return - V_25 ;
V_23 -> V_49 . V_50 = F_10 ( V_24 ++ ) ;
V_23 -> V_49 . V_51 = F_10 ( V_24 ++ ) ;
V_23 -> V_49 . V_52 = F_10 ( V_24 ++ ) ;
V_24 = F_9 ( V_21 , V_23 -> V_49 . V_52 ) ;
if ( ! V_24 )
return - V_25 ;
if ( V_23 -> V_49 . V_52 > 256 )
return - V_25 ;
memcpy ( & V_23 -> V_49 . V_53 , V_24 , V_23 -> V_49 . V_52 ) ;
V_24 = F_9 ( V_21 , 8 ) ;
if ( ! V_24 )
return - V_25 ;
V_24 = F_12 ( V_24 , & V_23 -> V_49 . V_13 ) ;
break;
default:
F_11 ( L_5 ) ;
return - V_25 ;
}
return 0 ;
}
static bool F_15 ( struct V_1 * V_2 , T_2 V_32 ,
struct V_54 * V_55 )
{
V_55 -> V_38 = V_2 -> V_38 ;
V_55 -> V_30 = V_2 -> V_30 ;
V_55 -> V_56 = V_2 -> V_56 ;
V_55 -> V_9 = V_2 -> V_9 ;
return true ;
}
static bool F_16 ( struct V_1 * V_2 , T_2 V_32 ,
struct V_54 * V_55 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_3 ; V_4 ++ ) {
struct V_1 * V_57 = & V_2 -> V_5 [ V_4 ] ;
if ( V_57 -> V_38 > V_32 ||
V_57 -> V_38 + V_57 -> V_30 <= V_32 )
continue;
V_57 -> V_55 ( V_57 , V_32 - V_57 -> V_38 , V_55 ) ;
return true ;
}
F_11 ( L_6 , V_58 ) ;
return false ;
}
static bool F_17 ( struct V_1 * V_2 , T_2 V_32 ,
struct V_54 * V_55 )
{
struct V_1 * V_57 ;
T_2 V_59 ;
T_3 V_60 ;
T_2 V_56 ;
V_59 = F_18 ( V_32 , V_2 -> V_47 ) ;
F_19 ( V_59 , V_2 -> V_3 , & V_60 ) ;
if ( V_60 > V_2 -> V_3 ) {
F_11 ( L_7 ,
V_58 , V_60 , V_32 , V_2 -> V_47 ) ;
return false ;
}
V_32 = V_59 * V_2 -> V_47 ;
V_56 = F_18 ( V_32 , V_2 -> V_3 ) ;
V_57 = & V_2 -> V_5 [ V_60 ] ;
V_57 -> V_55 ( V_57 , V_56 , V_55 ) ;
V_55 -> V_38 += V_32 ;
V_55 -> V_56 += V_56 ;
V_55 -> V_30 = V_2 -> V_47 ;
return true ;
}
static int
F_20 ( struct V_61 * V_62 , struct V_1 * V_17 ,
struct V_22 * V_44 , int V_63 , T_4 V_64 )
{
struct V_22 * V_65 = & V_44 [ V_63 ] ;
struct V_66 * V_9 ;
T_5 V_2 ;
V_2 = F_21 ( V_62 , V_65 , V_64 ) ;
if ( ! V_2 )
return - V_25 ;
V_9 = F_22 ( V_2 , V_14 | V_15 , NULL ) ;
if ( F_23 ( V_9 ) ) {
F_24 ( V_67 L_8 ,
F_25 ( V_2 ) , F_26 ( V_2 ) , F_27 ( V_9 ) ) ;
return F_27 ( V_9 ) ;
}
V_17 -> V_9 = V_9 ;
V_17 -> V_30 = F_28 ( V_17 -> V_9 -> V_68 ) ;
V_17 -> V_55 = F_15 ;
F_24 ( V_69 L_9 ,
V_17 -> V_9 -> V_10 -> V_70 ) ;
return 0 ;
}
static bool
F_29 ( struct V_22 * V_65 )
{
switch ( V_65 -> V_49 . V_51 ) {
case V_71 :
if ( V_65 -> V_49 . V_50 != V_72 )
return false ;
if ( V_65 -> V_49 . V_52 != 8 &&
V_65 -> V_49 . V_52 != 10 &&
V_65 -> V_49 . V_52 != 16 )
return false ;
return true ;
case V_73 :
if ( V_65 -> V_49 . V_50 != V_72 )
return false ;
if ( V_65 -> V_49 . V_52 != 8 &&
V_65 -> V_49 . V_52 != 16 )
return false ;
return true ;
case V_74 :
case V_75 :
F_3 ( L_10
L_11 ,
V_65 -> V_49 . V_50 ,
V_65 -> V_49 . V_51 ,
V_65 -> V_49 . V_52 ) ;
return false ;
default:
F_3 ( L_12
L_11 ,
V_65 -> V_49 . V_50 ,
V_65 -> V_49 . V_51 ,
V_65 -> V_49 . V_52 ) ;
return false ;
}
}
static struct V_66 *
F_30 ( struct V_22 * V_65 )
{
struct V_66 * V_9 ;
const char * V_76 ;
V_76 = F_31 ( V_77 , L_13 ,
V_65 -> V_49 . V_52 , V_65 -> V_49 . V_53 ) ;
if ( ! V_76 )
return F_32 ( - V_78 ) ;
V_9 = F_33 ( V_76 , V_14 | V_15 , NULL ) ;
if ( F_23 ( V_9 ) ) {
F_34 ( L_14 ,
V_76 , F_27 ( V_9 ) ) ;
}
F_2 ( V_76 ) ;
return V_9 ;
}
static struct V_66 *
F_35 ( struct V_22 * V_65 )
{
struct V_66 * V_9 ;
const char * V_76 ;
V_76 = F_31 ( V_77 ,
L_15 ,
V_65 -> V_49 . V_51 ,
V_65 -> V_49 . V_52 , V_65 -> V_49 . V_53 ) ;
if ( ! V_76 )
return F_32 ( - V_78 ) ;
V_9 = F_33 ( V_76 , V_14 | V_15 , NULL ) ;
F_2 ( V_76 ) ;
return V_9 ;
}
static int
F_36 ( struct V_61 * V_62 , struct V_1 * V_17 ,
struct V_22 * V_44 , int V_63 , T_4 V_64 )
{
struct V_22 * V_65 = & V_44 [ V_63 ] ;
struct V_66 * V_9 ;
const struct V_7 * V_8 ;
int error ;
if ( ! F_29 ( V_65 ) )
return - V_79 ;
V_9 = F_35 ( V_65 ) ;
if ( F_23 ( V_9 ) )
V_9 = F_30 ( V_65 ) ;
if ( F_23 ( V_9 ) )
return F_27 ( V_9 ) ;
V_17 -> V_9 = V_9 ;
V_17 -> V_30 = F_28 ( V_17 -> V_9 -> V_68 ) ;
V_17 -> V_55 = F_15 ;
V_17 -> V_13 = V_65 -> V_49 . V_13 ;
F_13 ( L_16 ,
V_17 -> V_9 -> V_10 -> V_70 , V_17 -> V_13 ) ;
V_8 = V_17 -> V_9 -> V_10 -> V_11 -> V_7 ;
if ( ! V_8 ) {
F_3 ( L_17 ,
V_17 -> V_9 -> V_10 -> V_70 ) ;
error = - V_79 ;
goto V_80;
}
error = V_8 -> V_12 ( V_17 -> V_9 , 0 , V_17 -> V_13 , true ) ;
if ( error ) {
F_3 ( L_18 ,
V_17 -> V_9 -> V_10 -> V_70 ) ;
goto V_80;
}
V_17 -> V_6 = true ;
return 0 ;
V_80:
F_4 ( V_17 -> V_9 , V_14 | V_15 ) ;
return error ;
}
static int
F_37 ( struct V_61 * V_62 , struct V_1 * V_17 ,
struct V_22 * V_44 , int V_63 , T_4 V_64 )
{
struct V_22 * V_65 = & V_44 [ V_63 ] ;
int V_81 ;
V_81 = F_38 ( V_62 , V_17 , V_44 , V_65 -> V_37 . V_39 , V_64 ) ;
if ( V_81 )
return V_81 ;
V_17 -> V_56 = V_65 -> V_37 . V_38 ;
V_17 -> V_30 = V_65 -> V_37 . V_30 ;
return 0 ;
}
static int
F_39 ( struct V_61 * V_62 , struct V_1 * V_17 ,
struct V_22 * V_44 , int V_63 , T_4 V_64 )
{
struct V_22 * V_65 = & V_44 [ V_63 ] ;
T_2 V_30 = 0 ;
int V_81 , V_4 ;
V_17 -> V_5 = F_40 ( V_65 -> V_41 . V_42 ,
sizeof( struct V_1 ) , V_77 ) ;
if ( ! V_17 -> V_5 )
return - V_78 ;
for ( V_4 = 0 ; V_4 < V_65 -> V_41 . V_42 ; V_4 ++ ) {
V_81 = F_38 ( V_62 , & V_17 -> V_5 [ V_4 ] ,
V_44 , V_65 -> V_41 . V_44 [ V_4 ] , V_64 ) ;
if ( V_81 )
return V_81 ;
V_17 -> V_3 ++ ;
V_17 -> V_5 [ V_4 ] . V_38 += V_30 ;
V_30 += V_17 -> V_5 [ V_4 ] . V_30 ;
}
V_17 -> V_30 = V_30 ;
V_17 -> V_55 = F_16 ;
return 0 ;
}
static int
F_41 ( struct V_61 * V_62 , struct V_1 * V_17 ,
struct V_22 * V_44 , int V_63 , T_4 V_64 )
{
struct V_22 * V_65 = & V_44 [ V_63 ] ;
T_2 V_30 = 0 ;
int V_81 , V_4 ;
V_17 -> V_5 = F_40 ( V_65 -> V_46 . V_42 ,
sizeof( struct V_1 ) , V_77 ) ;
if ( ! V_17 -> V_5 )
return - V_78 ;
for ( V_4 = 0 ; V_4 < V_65 -> V_46 . V_42 ; V_4 ++ ) {
V_81 = F_38 ( V_62 , & V_17 -> V_5 [ V_4 ] ,
V_44 , V_65 -> V_46 . V_44 [ V_4 ] , V_64 ) ;
if ( V_81 )
return V_81 ;
V_17 -> V_3 ++ ;
V_30 += V_17 -> V_5 [ V_4 ] . V_30 ;
}
V_17 -> V_30 = V_30 ;
V_17 -> V_47 = V_65 -> V_46 . V_47 ;
V_17 -> V_55 = F_17 ;
return 0 ;
}
static int
F_38 ( struct V_61 * V_62 , struct V_1 * V_17 ,
struct V_22 * V_44 , int V_63 , T_4 V_64 )
{
switch ( V_44 [ V_63 ] . type ) {
case V_26 :
return F_20 ( V_62 , V_17 , V_44 , V_63 , V_64 ) ;
case V_36 :
return F_37 ( V_62 , V_17 , V_44 , V_63 , V_64 ) ;
case V_40 :
return F_39 ( V_62 , V_17 , V_44 , V_63 , V_64 ) ;
case V_45 :
return F_41 ( V_62 , V_17 , V_44 , V_63 , V_64 ) ;
case V_48 :
return F_36 ( V_62 , V_17 , V_44 , V_63 , V_64 ) ;
default:
F_11 ( L_19 , V_44 [ V_63 ] . type ) ;
return - V_25 ;
}
}
struct V_16 *
F_42 ( struct V_61 * V_62 , struct V_82 * V_83 ,
T_4 V_64 )
{
struct V_16 * V_18 = NULL ;
struct V_22 * V_44 ;
struct V_1 * V_84 ;
struct V_20 V_21 ;
struct V_85 V_86 ;
struct V_87 * V_88 ;
int V_89 , V_81 , V_4 ;
T_1 * V_24 ;
V_88 = F_43 ( V_64 ) ;
if ( ! V_88 )
goto V_90;
F_44 ( & V_21 , & V_86 , V_83 -> V_91 , V_83 -> V_92 ) ;
F_45 ( & V_21 , F_46 ( V_88 ) , V_93 ) ;
V_24 = F_9 ( & V_21 , sizeof( T_1 ) ) ;
if ( ! V_24 )
goto V_94;
V_89 = F_10 ( V_24 ++ ) ;
V_44 = F_40 ( V_89 , sizeof( struct V_22 ) ,
V_64 ) ;
if ( ! V_44 )
goto V_94;
for ( V_4 = 0 ; V_4 < V_89 ; V_4 ++ ) {
V_81 = F_8 ( & V_21 , & V_44 [ V_4 ] ) ;
if ( V_81 < 0 )
goto V_95;
}
V_84 = F_47 ( sizeof( * V_84 ) , V_64 ) ;
if ( ! V_84 )
goto V_95;
V_81 = F_38 ( V_62 , V_84 , V_44 , V_89 - 1 , V_64 ) ;
if ( V_81 ) {
F_1 ( V_84 ) ;
F_2 ( V_84 ) ;
goto V_95;
}
V_18 = & V_84 -> V_18 ;
F_48 ( V_18 , V_62 , & V_83 -> V_96 ) ;
V_95:
F_2 ( V_44 ) ;
V_94:
F_49 ( V_88 ) ;
V_90:
return V_18 ;
}
