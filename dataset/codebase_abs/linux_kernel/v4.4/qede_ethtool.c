static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 , V_5 , V_6 ;
for ( V_4 = 0 , V_5 = 0 ; V_4 < V_7 ; V_4 ++ ) {
strcpy ( V_3 + V_5 * V_8 ,
V_9 [ V_4 ] . string ) ;
V_5 ++ ;
}
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ , V_5 ++ )
strcpy ( V_3 + V_5 * V_8 ,
V_11 [ V_6 ] . string ) ;
}
static void F_2 ( struct V_12 * V_13 , T_2 V_14 , T_1 * V_3 )
{
struct V_1 * V_2 = F_3 ( V_13 ) ;
switch ( V_14 ) {
case V_15 :
F_1 ( V_2 , V_3 ) ;
break;
default:
F_4 ( V_2 , V_16 ,
L_1 , V_14 ) ;
}
}
static void F_5 ( struct V_12 * V_13 ,
struct V_17 * V_18 , T_3 * V_3 )
{
struct V_1 * V_2 = F_3 ( V_13 ) ;
int V_19 , V_20 = 0 ;
int V_21 ;
F_6 ( V_2 ) ;
F_7 ( & V_2 -> V_22 ) ;
for ( V_19 = 0 ; V_19 < V_7 ; V_19 ++ )
V_3 [ V_20 ++ ] = F_8 ( V_2 , V_19 ) ;
for ( V_19 = 0 ; V_19 < V_10 ; V_19 ++ ) {
V_3 [ V_20 ] = 0 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_23 ; V_21 ++ )
V_3 [ V_20 ] += F_9 ( V_2 , V_19 , V_21 ) ;
V_20 ++ ;
}
F_10 ( & V_2 -> V_22 ) ;
}
static int F_11 ( struct V_12 * V_13 , int V_14 )
{
struct V_1 * V_2 = F_3 ( V_13 ) ;
int V_24 = V_7 ;
switch ( V_14 ) {
case V_15 :
return V_24 + V_10 ;
default:
F_4 ( V_2 , V_16 ,
L_1 , V_14 ) ;
return - V_25 ;
}
}
static int F_12 ( struct V_12 * V_13 , struct V_26 * V_27 )
{
struct V_1 * V_2 = F_3 ( V_13 ) ;
struct V_28 V_29 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_2 -> V_30 -> V_31 -> V_32 ( V_2 -> V_33 , & V_29 ) ;
V_27 -> V_34 = V_29 . V_35 ;
V_27 -> V_36 = V_29 . V_37 ;
if ( ( V_2 -> V_38 == V_39 ) && ( V_29 . V_40 ) ) {
F_13 ( V_27 , V_29 . V_41 ) ;
V_27 -> V_42 = V_29 . V_42 ;
} else {
V_27 -> V_42 = V_43 ;
F_13 ( V_27 , V_44 ) ;
}
V_27 -> V_45 = V_29 . V_45 ;
V_27 -> V_46 = ( V_29 . V_46 ) ? V_47 :
V_48 ;
V_27 -> V_49 = V_29 . V_50 ;
return 0 ;
}
static int F_14 ( struct V_12 * V_13 , struct V_26 * V_27 )
{
struct V_1 * V_2 = F_3 ( V_13 ) ;
struct V_28 V_29 ;
struct V_51 V_52 ;
T_2 V_41 ;
if ( V_2 -> V_53 . V_31 . V_54 ) {
F_15 ( V_2 ,
L_2 ) ;
return - V_55 ;
}
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_2 -> V_30 -> V_31 -> V_32 ( V_2 -> V_33 , & V_29 ) ;
V_41 = F_16 ( V_27 ) ;
V_52 . V_56 |= V_57 ;
V_52 . V_56 |= V_58 ;
if ( V_27 -> V_46 == V_47 ) {
V_52 . V_46 = true ;
V_52 . V_59 = 0 ;
V_52 . V_60 = V_27 -> V_36 ;
} else {
V_52 . V_56 |= V_61 ;
V_52 . V_46 = false ;
V_52 . V_59 = V_41 ;
switch ( V_41 ) {
case V_62 :
if ( ! ( V_29 . V_35 &
V_63 ) ) {
F_15 ( V_2 , L_3 ) ;
return - V_25 ;
}
V_52 . V_60 = V_63 ;
break;
case V_64 :
if ( ! ( V_29 . V_35 &
V_65 ) ) {
F_15 ( V_2 , L_4 ) ;
return - V_25 ;
}
V_52 . V_60 = V_65 ;
break;
default:
F_15 ( V_2 , L_5 , V_41 ) ;
return - V_25 ;
}
}
V_52 . V_40 = true ;
V_2 -> V_30 -> V_31 -> V_66 ( V_2 -> V_33 , & V_52 ) ;
return 0 ;
}
static void F_17 ( struct V_12 * V_67 ,
struct V_68 * V_69 )
{
char V_70 [ V_71 ] , V_72 [ V_71 ] ;
struct V_1 * V_2 = F_3 ( V_67 ) ;
F_18 ( V_69 -> V_73 , L_6 , sizeof( V_69 -> V_73 ) ) ;
F_18 ( V_69 -> V_74 , V_75 , sizeof( V_69 -> V_74 ) ) ;
snprintf ( V_72 , V_71 , L_7 ,
V_2 -> V_53 . V_31 . V_76 ,
V_2 -> V_53 . V_31 . V_77 ,
V_2 -> V_53 . V_31 . V_78 ,
V_2 -> V_53 . V_31 . V_79 ) ;
snprintf ( V_70 , V_71 , L_7 ,
( V_2 -> V_53 . V_31 . V_80 >> 24 ) & 0xFF ,
( V_2 -> V_53 . V_31 . V_80 >> 16 ) & 0xFF ,
( V_2 -> V_53 . V_31 . V_80 >> 8 ) & 0xFF ,
V_2 -> V_53 . V_31 . V_80 & 0xFF ) ;
if ( ( strlen ( V_72 ) + strlen ( V_70 ) + strlen ( L_8 ) ) <
sizeof( V_69 -> V_81 ) ) {
snprintf ( V_69 -> V_81 , sizeof( V_69 -> V_81 ) ,
L_9 , V_70 , V_72 ) ;
} else {
snprintf ( V_69 -> V_81 , sizeof( V_69 -> V_81 ) ,
L_10 , V_70 , V_72 ) ;
}
F_18 ( V_69 -> V_82 , F_19 ( V_2 -> V_83 ) , sizeof( V_69 -> V_82 ) ) ;
}
static T_2 F_20 ( struct V_12 * V_67 )
{
struct V_1 * V_2 = F_3 ( V_67 ) ;
return ( ( T_2 ) V_2 -> V_84 << V_85 ) |
V_2 -> V_86 ;
}
static void F_21 ( struct V_12 * V_67 , T_2 V_87 )
{
struct V_1 * V_2 = F_3 ( V_67 ) ;
T_2 V_86 = 0 ;
T_1 V_84 = 0 ;
F_22 ( V_87 , & V_86 , & V_84 ) ;
V_2 -> V_84 = V_84 ;
V_2 -> V_86 = V_86 ;
V_2 -> V_30 -> V_31 -> V_88 ( V_2 -> V_33 ,
V_86 , V_84 ) ;
}
static T_2 F_23 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_3 ( V_13 ) ;
struct V_28 V_29 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_2 -> V_30 -> V_31 -> V_32 ( V_2 -> V_33 , & V_29 ) ;
return V_29 . V_40 ;
}
static void F_24 ( struct V_1 * V_2 , union V_89 * args )
{
V_2 -> V_67 -> V_90 = args -> V_90 ;
}
int F_25 ( struct V_12 * V_67 , int V_91 )
{
struct V_1 * V_2 = F_3 ( V_67 ) ;
union V_89 args ;
if ( ( V_91 > V_92 ) ||
( ( V_91 + V_93 ) < V_94 ) ) {
F_26 ( V_2 , L_11 ) ;
return - V_25 ;
}
F_4 ( V_2 , ( V_95 | V_96 ) ,
L_12 , V_91 ) ;
args . V_90 = V_91 ;
if ( F_27 ( V_2 -> V_67 ) )
F_28 ( V_2 , & F_24 , & args ) ;
F_24 ( V_2 , & args ) ;
return 0 ;
}
void F_29 ( struct V_12 * V_13 )
{
V_13 -> V_97 = & V_98 ;
}
