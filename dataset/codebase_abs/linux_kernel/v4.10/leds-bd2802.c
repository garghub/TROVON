static inline int F_1 ( struct V_1 * V_2 , enum V_3 V_4 ,
enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
return ! V_2 -> V_2 [ V_4 ] . V_8 ;
case V_9 :
return ! V_2 -> V_2 [ V_4 ] . V_10 ;
case V_11 :
return ! V_2 -> V_2 [ V_4 ] . V_12 ;
default:
F_2 ( & V_2 -> V_13 -> V_14 , L_1 , V_15 ) ;
return - V_16 ;
}
}
static inline int F_3 ( struct V_1 * V_2 , enum V_3 V_4 )
{
if ( V_2 -> V_2 [ V_4 ] . V_8 || V_2 -> V_2 [ V_4 ] . V_10 || V_2 -> V_2 [ V_4 ] . V_12 )
return 0 ;
return 1 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
if ( ! F_3 ( V_2 , V_17 ) )
return 0 ;
return 1 ;
}
static inline T_1 F_5 ( enum V_3 V_4 , enum V_5 V_6 )
{
return V_4 * V_19 + V_6 * V_20 ;
}
static inline T_1 F_6 ( enum V_3 V_4 , enum V_5 V_6 ,
T_1 V_21 )
{
return V_21 + F_5 ( V_4 , V_6 ) ;
}
static int F_7 ( struct V_22 * V_13 , T_1 V_23 , T_1 V_24 )
{
int V_25 = F_8 ( V_13 , V_23 , V_24 ) ;
if ( V_25 >= 0 )
return 0 ;
F_2 ( & V_13 -> V_14 , L_2 ,
V_15 , V_23 , V_24 , V_25 ) ;
return V_25 ;
}
static void F_9 ( struct V_1 * V_2 , enum V_3 V_4 ,
enum V_5 V_6 , enum V_26 V_27 )
{
int V_17 ;
T_1 V_28 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
if ( V_17 == V_4 ) {
switch ( V_6 ) {
case V_7 :
V_2 -> V_2 [ V_17 ] . V_8 = V_27 ;
break;
case V_9 :
V_2 -> V_2 [ V_17 ] . V_10 = V_27 ;
break;
case V_11 :
V_2 -> V_2 [ V_17 ] . V_12 = V_27 ;
break;
default:
F_2 ( & V_2 -> V_13 -> V_14 ,
L_1 , V_15 ) ;
return;
}
}
}
if ( V_27 == V_29 || V_27 == V_30 )
return;
if ( ! F_3 ( V_2 , V_4 ) )
return;
if ( F_4 ( V_2 ) && ! V_2 -> V_31 ) {
F_10 ( V_2 -> V_32 -> V_33 , 0 ) ;
return;
}
V_28 = ( V_4 == V_34 ) ? F_11 ( 1 , 0 ) : F_11 ( 0 , 1 ) ;
F_7 ( V_2 -> V_13 , V_35 , V_28 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_36 * V_32 = V_2 -> V_32 ;
T_1 V_23 ;
V_23 = F_6 ( V_34 , V_7 , V_37 ) ;
F_7 ( V_2 -> V_13 , V_23 , V_32 -> V_38 ) ;
V_23 = F_6 ( V_39 , V_7 , V_37 ) ;
F_7 ( V_2 -> V_13 , V_23 , V_32 -> V_38 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_32 -> V_33 , 1 ) ;
F_14 ( 100 ) ;
F_12 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 , enum V_3 V_4 )
{
enum V_3 V_40 = ( V_4 == V_34 ) ? V_39 : V_34 ;
T_1 V_28 , V_41 ;
V_41 = ! F_3 ( V_2 , V_40 ) ;
if ( V_4 == V_34 )
V_28 = F_11 ( V_41 , 1 ) ;
else
V_28 = F_11 ( 1 , V_41 ) ;
F_7 ( V_2 -> V_13 , V_35 , V_28 ) ;
}
static void F_16 ( struct V_1 * V_2 , enum V_3 V_4 ,
enum V_5 V_6 )
{
T_1 V_23 ;
if ( F_4 ( V_2 ) && ! V_2 -> V_31 )
F_13 ( V_2 ) ;
V_23 = F_6 ( V_4 , V_6 , V_42 ) ;
F_7 ( V_2 -> V_13 , V_23 , V_2 -> V_43 ) ;
V_23 = F_6 ( V_4 , V_6 , V_44 ) ;
F_7 ( V_2 -> V_13 , V_23 , V_45 ) ;
V_23 = F_6 ( V_4 , V_6 , V_46 ) ;
F_7 ( V_2 -> V_13 , V_23 , V_47 ) ;
F_15 ( V_2 , V_4 ) ;
F_9 ( V_2 , V_4 , V_6 , V_30 ) ;
}
static void F_17 ( struct V_1 * V_2 , enum V_3 V_4 ,
enum V_5 V_6 )
{
T_1 V_23 ;
if ( F_4 ( V_2 ) && ! V_2 -> V_31 )
F_13 ( V_2 ) ;
V_23 = F_6 ( V_4 , V_6 , V_42 ) ;
F_7 ( V_2 -> V_13 , V_23 , V_45 ) ;
V_23 = F_6 ( V_4 , V_6 , V_44 ) ;
F_7 ( V_2 -> V_13 , V_23 , V_2 -> V_43 ) ;
V_23 = F_6 ( V_4 , V_6 , V_46 ) ;
F_7 ( V_2 -> V_13 , V_23 , V_2 -> V_48 ) ;
F_15 ( V_2 , V_4 ) ;
F_9 ( V_2 , V_4 , V_6 , V_29 ) ;
}
static void F_18 ( struct V_1 * V_2 , enum V_3 V_4 ,
enum V_5 V_6 , enum V_26 V_27 )
{
if ( V_27 == V_49 ) {
F_2 ( & V_2 -> V_13 -> V_14 ,
L_3 ) ;
return;
}
if ( V_27 == V_29 )
F_17 ( V_2 , V_4 , V_6 ) ;
else
F_16 ( V_2 , V_4 , V_6 ) ;
}
static void F_19 ( struct V_1 * V_2 , enum V_3 V_4 ,
enum V_5 V_6 )
{
T_1 V_23 ;
if ( F_1 ( V_2 , V_4 , V_6 ) )
return;
V_23 = F_6 ( V_4 , V_6 , V_42 ) ;
F_7 ( V_2 -> V_13 , V_23 , V_45 ) ;
V_23 = F_6 ( V_4 , V_6 , V_44 ) ;
F_7 ( V_2 -> V_13 , V_23 , V_45 ) ;
F_9 ( V_2 , V_4 , V_6 , V_49 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
int V_17 , V_25 ;
for ( V_17 = 0 ; V_17 < F_21 ( V_50 ) ; V_17 ++ ) {
V_25 = F_22 ( & V_2 -> V_13 -> V_14 ,
V_50 [ V_17 ] ) ;
if ( V_25 ) {
F_2 ( & V_2 -> V_13 -> V_14 , L_4 ,
V_50 [ V_17 ] -> V_51 . V_52 ) ;
goto V_53;
}
}
if ( F_4 ( V_2 ) )
F_13 ( V_2 ) ;
V_2 -> V_31 = 1 ;
return;
V_53:
for ( V_17 -- ; V_17 >= 0 ; V_17 -- )
F_23 ( & V_2 -> V_13 -> V_14 ,
V_50 [ V_17 ] ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < F_21 ( V_50 ) ; V_17 ++ )
F_23 ( & V_2 -> V_13 -> V_14 ,
V_50 [ V_17 ] ) ;
if ( F_4 ( V_2 ) )
F_10 ( V_2 -> V_32 -> V_33 , 0 ) ;
V_2 -> V_31 = 0 ;
}
static T_2 F_25 ( struct V_54 * V_14 ,
struct V_55 * V_51 , char * V_56 )
{
struct V_1 * V_2 = F_26 ( F_27 ( V_14 ) ) ;
T_2 V_25 ;
F_28 ( & V_2 -> V_57 ) ;
if ( V_2 -> V_31 )
V_25 = sprintf ( V_56 , L_5 ) ;
else
V_25 = sprintf ( V_56 , L_6 ) ;
F_29 ( & V_2 -> V_57 ) ;
return V_25 ;
}
static T_2 F_30 ( struct V_54 * V_14 ,
struct V_55 * V_51 , const char * V_56 , T_3 V_58 )
{
struct V_1 * V_2 = F_26 ( F_27 ( V_14 ) ) ;
if ( ! V_58 )
return - V_16 ;
F_31 ( & V_2 -> V_57 ) ;
if ( ! V_2 -> V_31 && ! strncmp ( V_56 , L_7 , 2 ) )
F_20 ( V_2 ) ;
else if ( V_2 -> V_31 && ! strncmp ( V_56 , L_8 , 3 ) )
F_24 ( V_2 ) ;
F_32 ( & V_2 -> V_57 ) ;
return V_58 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_25 ;
V_2 -> V_59 . V_52 = L_9 ;
V_2 -> V_59 . V_60 = V_61 ;
V_2 -> V_59 . V_62 = V_63 ;
V_2 -> V_59 . V_64 = V_65 ;
V_25 = F_34 ( & V_2 -> V_13 -> V_14 , & V_2 -> V_59 ) ;
if ( V_25 < 0 ) {
F_2 ( & V_2 -> V_13 -> V_14 , L_10 ,
V_2 -> V_59 . V_52 ) ;
goto V_66;
}
V_2 -> V_67 . V_52 = L_11 ;
V_2 -> V_67 . V_60 = V_61 ;
V_2 -> V_67 . V_62 = V_68 ;
V_2 -> V_67 . V_64 = V_69 ;
V_25 = F_34 ( & V_2 -> V_13 -> V_14 , & V_2 -> V_67 ) ;
if ( V_25 < 0 ) {
F_2 ( & V_2 -> V_13 -> V_14 , L_10 ,
V_2 -> V_67 . V_52 ) ;
goto V_70;
}
V_2 -> V_71 . V_52 = L_12 ;
V_2 -> V_71 . V_60 = V_61 ;
V_2 -> V_71 . V_62 = V_72 ;
V_2 -> V_71 . V_64 = V_73 ;
V_25 = F_34 ( & V_2 -> V_13 -> V_14 , & V_2 -> V_71 ) ;
if ( V_25 < 0 ) {
F_2 ( & V_2 -> V_13 -> V_14 , L_10 ,
V_2 -> V_71 . V_52 ) ;
goto V_74;
}
V_2 -> V_75 . V_52 = L_13 ;
V_2 -> V_75 . V_60 = V_61 ;
V_2 -> V_75 . V_62 = V_76 ;
V_2 -> V_75 . V_64 = V_77 ;
V_25 = F_34 ( & V_2 -> V_13 -> V_14 , & V_2 -> V_75 ) ;
if ( V_25 < 0 ) {
F_2 ( & V_2 -> V_13 -> V_14 , L_10 ,
V_2 -> V_75 . V_52 ) ;
goto V_78;
}
V_2 -> V_79 . V_52 = L_14 ;
V_2 -> V_79 . V_60 = V_61 ;
V_2 -> V_79 . V_62 = V_80 ;
V_2 -> V_79 . V_64 = V_81 ;
V_25 = F_34 ( & V_2 -> V_13 -> V_14 , & V_2 -> V_79 ) ;
if ( V_25 < 0 ) {
F_2 ( & V_2 -> V_13 -> V_14 , L_10 ,
V_2 -> V_79 . V_52 ) ;
goto V_82;
}
V_2 -> V_83 . V_52 = L_15 ;
V_2 -> V_83 . V_60 = V_61 ;
V_2 -> V_83 . V_62 = V_84 ;
V_2 -> V_83 . V_64 = V_85 ;
V_2 -> V_83 . V_86 |= V_87 ;
V_25 = F_34 ( & V_2 -> V_13 -> V_14 , & V_2 -> V_83 ) ;
if ( V_25 < 0 ) {
F_2 ( & V_2 -> V_13 -> V_14 , L_10 ,
V_2 -> V_83 . V_52 ) ;
goto V_88;
}
return 0 ;
V_88:
F_35 ( & V_2 -> V_79 ) ;
V_82:
F_35 ( & V_2 -> V_75 ) ;
V_78:
F_35 ( & V_2 -> V_71 ) ;
V_74:
F_35 ( & V_2 -> V_67 ) ;
V_70:
F_35 ( & V_2 -> V_59 ) ;
V_66:
return V_25 ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_83 ) ;
F_35 ( & V_2 -> V_79 ) ;
F_35 ( & V_2 -> V_75 ) ;
F_35 ( & V_2 -> V_71 ) ;
F_35 ( & V_2 -> V_67 ) ;
F_35 ( & V_2 -> V_59 ) ;
}
static int F_37 ( struct V_22 * V_13 ,
const struct V_89 * V_4 )
{
struct V_1 * V_2 ;
struct V_36 * V_32 ;
int V_25 , V_17 ;
V_2 = F_38 ( & V_13 -> V_14 , sizeof( struct V_1 ) , V_90 ) ;
if ( ! V_2 )
return - V_91 ;
V_2 -> V_13 = V_13 ;
V_32 = V_2 -> V_32 = F_39 ( & V_13 -> V_14 ) ;
F_40 ( V_13 , V_2 ) ;
F_41 ( V_32 -> V_33 , V_92 , L_16 ) ;
F_14 ( 100 ) ;
V_25 = F_7 ( V_13 , V_93 , 0x00 ) ;
if ( V_25 < 0 ) {
F_2 ( & V_13 -> V_14 , L_17 ) ;
return V_25 ;
} else
F_42 ( & V_13 -> V_14 , L_18 , V_25 ) ;
F_10 ( V_2 -> V_32 -> V_33 , 0 ) ;
V_2 -> V_48 = V_94 ;
V_2 -> V_43 = V_95 ;
F_43 ( & V_2 -> V_57 ) ;
for ( V_17 = 0 ; V_17 < F_21 ( V_96 ) ; V_17 ++ ) {
V_25 = F_22 ( & V_2 -> V_13 -> V_14 ,
V_96 [ V_17 ] ) ;
if ( V_25 ) {
F_2 ( & V_2 -> V_13 -> V_14 , L_4 ,
V_96 [ V_17 ] -> V_51 . V_52 ) ;
goto V_97;
}
}
V_25 = F_33 ( V_2 ) ;
if ( V_25 < 0 )
goto V_97;
return 0 ;
V_97:
for ( V_17 -- ; V_17 >= 0 ; V_17 -- )
F_23 ( & V_2 -> V_13 -> V_14 , V_96 [ V_17 ] ) ;
return V_25 ;
}
static int F_44 ( struct V_22 * V_13 )
{
struct V_1 * V_2 = F_26 ( V_13 ) ;
int V_17 ;
F_10 ( V_2 -> V_32 -> V_33 , 0 ) ;
F_36 ( V_2 ) ;
if ( V_2 -> V_31 )
F_24 ( V_2 ) ;
for ( V_17 = 0 ; V_17 < F_21 ( V_96 ) ; V_17 ++ )
F_23 ( & V_2 -> V_13 -> V_14 , V_96 [ V_17 ] ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
if ( V_2 -> V_2 [ V_17 ] . V_8 )
F_18 ( V_2 , V_17 , V_7 , V_2 -> V_2 [ V_17 ] . V_8 ) ;
if ( V_2 -> V_2 [ V_17 ] . V_10 )
F_18 ( V_2 , V_17 , V_9 , V_2 -> V_2 [ V_17 ] . V_10 ) ;
if ( V_2 -> V_2 [ V_17 ] . V_12 )
F_18 ( V_2 , V_17 , V_11 , V_2 -> V_2 [ V_17 ] . V_12 ) ;
}
}
static int F_46 ( struct V_54 * V_14 )
{
struct V_22 * V_13 = F_27 ( V_14 ) ;
struct V_1 * V_2 = F_26 ( V_13 ) ;
F_10 ( V_2 -> V_32 -> V_33 , 0 ) ;
return 0 ;
}
static int F_47 ( struct V_54 * V_14 )
{
struct V_22 * V_13 = F_27 ( V_14 ) ;
struct V_1 * V_2 = F_26 ( V_13 ) ;
if ( ! F_4 ( V_2 ) || V_2 -> V_31 ) {
F_13 ( V_2 ) ;
F_45 ( V_2 ) ;
}
return 0 ;
}
