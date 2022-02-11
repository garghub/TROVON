static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_7 = & V_6 -> V_4 ;
if ( ! V_7 )
return - V_8 ;
V_4 -> V_9 = V_10 ;
V_4 -> V_11 = V_7 -> V_11 ;
memcpy ( V_4 -> V_12 , V_7 -> V_12 , sizeof( V_4 -> V_12 ) ) ;
memcpy ( V_4 -> V_13 , V_7 -> V_13 , sizeof( V_4 -> V_13 ) ) ;
memcpy ( V_4 -> V_14 , V_7 -> V_14 , sizeof( V_4 -> V_14 ) ) ;
return 0 ;
}
static int F_3 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
int V_15 ;
int V_16 = 0 ;
int V_17 = 0 ;
for ( V_15 = 0 ; V_15 < V_10 ; V_15 ++ ) {
if ( V_4 -> V_14 [ V_15 ] >= V_18 ) {
F_4 ( V_6 , L_1 ,
V_15 , V_4 -> V_14 [ V_15 ] ) ;
return - V_8 ;
}
switch ( V_4 -> V_13 [ V_15 ] ) {
case V_19 :
break;
case V_20 :
V_17 = 1 ;
V_16 += V_4 -> V_12 [ V_15 ] ;
break;
default:
F_4 ( V_6 , L_2 ,
V_15 , V_4 -> V_13 [ V_15 ] ) ;
return - V_21 ;
}
}
if ( V_17 && V_16 != V_22 ) {
F_4 ( V_6 , L_3 ,
V_16 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_5 ( struct V_5 * V_6 ,
struct V_3 * V_4 , T_1 * V_23 )
{
struct V_24 * V_25 = V_6 -> V_25 ;
int V_26 = 0 ;
int V_15 ;
T_2 V_12 [ V_10 ] = { 0 } ;
T_2 V_27 [ V_10 ] = { 0 } ;
V_4 = V_4 ? : & V_6 -> V_4 ;
V_23 = V_23 ? : V_6 -> V_28 ;
for ( V_15 = V_10 - 1 ; V_15 >= 0 ; V_15 -- ) {
switch ( V_4 -> V_13 [ V_15 ] ) {
case V_19 :
V_27 [ V_15 ] = V_26 ++ ;
V_12 [ V_15 ] = V_22 ;
break;
case V_20 :
V_27 [ V_15 ] = V_29 ;
V_12 [ V_15 ] = V_4 -> V_12 [ V_15 ] ? : V_30 ;
break;
}
}
return F_6 ( V_25 -> V_2 , V_6 -> V_31 , V_12 , V_27 ,
V_23 ) ;
}
static int
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_24 * V_25 = V_6 -> V_25 ;
int V_32 ;
V_32 = F_3 ( V_6 , V_4 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_8 ( V_25 -> V_2 , V_6 -> V_31 , V_4 -> V_14 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_5 ( V_6 , V_4 , NULL ) ;
if ( V_32 )
return V_32 ;
memcpy ( & V_6 -> V_4 , V_4 , sizeof( V_6 -> V_4 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_34 -> V_35 = V_10 ;
V_34 -> V_36 = V_6 -> V_37 -> V_38 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_39 * V_37 = V_6 -> V_37 ;
struct V_24 * V_25 = V_6 -> V_25 ;
int V_32 ;
F_11 ( V_40 , V_6 , L_4 ,
V_34 -> V_35 ,
V_34 -> V_36 ,
V_34 -> V_41 ,
V_34 -> V_42 ) ;
V_37 -> V_43 = ! V_34 -> V_36 ;
V_37 -> V_44 = ! V_34 -> V_36 ;
V_37 -> V_45 = V_34 -> V_36 ;
V_37 -> V_38 = V_34 -> V_36 ;
V_32 = F_12 ( V_25 -> V_2 , V_6 -> V_31 ,
V_6 -> V_46 + V_47 ,
V_37 -> V_44 ,
V_37 -> V_38 ,
V_37 -> V_43 ,
V_37 -> V_45 ) ;
if ( V_32 )
F_4 ( V_6 , L_5 ) ;
else
F_13 ( V_25 -> V_2 , & V_6 -> V_48 ,
V_37 -> V_45 , V_37 -> V_43 ,
V_37 -> V_38 , V_37 -> V_44 ) ;
return V_32 ;
}
static T_3 F_14 ( struct V_1 * V_2 )
{
return V_49 | V_50 ;
}
static T_3 F_15 ( struct V_1 * V_2 , T_3 V_51 )
{
if ( ( V_51 & V_52 ) ||
( V_51 & V_53 ) ||
! ( V_51 & V_50 ) ||
! ( V_51 & V_49 ) )
return 1 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_54 * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_10 ; V_15 ++ )
V_28 -> V_55 [ V_15 ] =
V_6 -> V_28 [ V_15 ] * V_56 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_54 * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_57 [ V_10 ] ;
int V_15 , V_32 ;
for ( V_15 = 0 ; V_15 < V_10 ; V_15 ++ ) {
V_57 [ V_15 ] = F_18 ( V_28 -> V_55 [ V_15 ] +
V_56 - 1 ,
V_56 ) ;
}
V_32 = F_5 ( V_6 , NULL , V_57 ) ;
if ( V_32 )
return V_32 ;
memcpy ( V_6 -> V_28 , V_57 , sizeof( V_6 -> V_28 ) ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_60 * V_61 ;
struct V_62 * V_63 = NULL ;
T_4 V_64 = 0 ;
T_5 V_65 = 0 ;
int V_15 , V_32 ;
if ( ! ( V_6 -> V_25 -> V_2 -> V_66 . V_67 & V_68 ) )
return - V_69 ;
V_63 = F_20 ( V_6 -> V_25 -> V_2 ) ;
if ( F_21 ( V_63 ) )
return - V_70 ;
V_61 =
(struct V_60 * )
V_63 -> V_71 ;
for ( V_15 = 0 ; V_15 < V_10 ; V_15 ++ ) {
V_65 = V_6 -> V_31 | ( ( 1 << V_15 ) << 8 ) |
( V_72 << 16 ) ;
V_32 = F_22 ( V_6 -> V_25 -> V_2 , V_64 ,
V_63 -> V_73 ,
V_65 , V_74 ,
V_75 ,
V_76 ,
V_77 ) ;
if ( V_32 ) {
F_23 ( V_6 -> V_25 -> V_2 , V_63 ) ;
return V_32 ;
}
V_59 -> V_78 [ V_15 ] =
F_24 ( V_61 -> V_79 ) >> V_80 ;
V_59 -> V_81 [ V_15 ] =
F_24 ( V_61 -> V_81 ) ;
V_59 -> V_82 [ V_15 ] =
F_24 ( V_61 -> V_82 ) ;
V_59 -> V_83 [ V_15 ] =
F_24 ( V_61 -> V_83 ) ;
V_59 -> V_84 [ V_15 ] =
F_24 ( V_61 -> V_84 ) ;
V_59 -> V_85 [ V_15 ] =
F_24 ( V_61 -> V_85 ) ;
V_59 -> V_86 [ V_15 ] =
F_24 ( V_61 -> V_86 ) ;
V_59 -> V_87 [ V_15 ] =
F_24 ( V_61 -> V_87 ) ;
V_59 -> V_88 [ V_15 ] =
F_24 ( V_61 -> V_88 ) ;
V_59 -> V_89 [ V_15 ] =
F_24 ( V_61 -> V_89 ) ;
V_59 -> V_90 [ V_15 ] =
F_24 ( V_61 -> V_90 ) ;
V_59 -> V_91 [ V_15 ] =
V_6 -> V_92 [ V_15 ] ;
}
F_23 ( V_6 -> V_25 -> V_2 , V_63 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_60 * V_61 ;
struct V_62 * V_93 = NULL ;
T_4 V_64 = 0 ;
T_5 V_65 = 0 ;
int V_15 , V_32 ;
#define F_26 0xc0000000
#define F_27 0xffc00000
if ( ! ( V_6 -> V_25 -> V_2 -> V_66 . V_67 & V_68 ) )
return - V_69 ;
V_93 = F_20 ( V_6 -> V_25 -> V_2 ) ;
if ( F_21 ( V_93 ) )
return - V_70 ;
V_64 = V_93 -> V_73 ;
V_61 =
(struct V_60 * ) V_93 -> V_71 ;
for ( V_15 = 0 ; V_15 < V_10 ; V_15 ++ ) {
V_65 = V_6 -> V_31 | ( ( 1 << V_15 ) << 8 ) |
( V_72 << 16 ) ;
V_61 -> V_94 = F_28 (
F_26 ) ;
V_61 -> V_95 = F_28 ( F_27 ) ;
V_61 -> V_79 = F_28 ( V_59 -> V_78 [ V_15 ] << V_80 ) ;
V_61 -> V_81 = F_28 ( V_59 -> V_81 [ V_15 ] ) ;
V_61 -> V_82 = F_28 ( V_59 -> V_82 [ V_15 ] ) ;
V_61 -> V_83 = F_28 ( V_59 -> V_83 [ V_15 ] ) ;
V_61 -> V_84 = F_28 ( V_59 -> V_84 [ V_15 ] ) ;
V_61 -> V_85 = F_28 ( V_59 -> V_85 [ V_15 ] ) ;
V_61 -> V_86 = F_28 ( V_59 -> V_86 [ V_15 ] ) ;
V_61 -> V_87 = F_28 ( V_59 -> V_87 [ V_15 ] ) ;
V_61 -> V_88 = F_28 ( V_59 -> V_88 [ V_15 ] ) ;
V_61 -> V_89 = F_28 ( V_59 -> V_89 [ V_15 ] ) ;
V_61 -> V_90 = F_28 ( V_59 -> V_90 [ V_15 ] ) ;
V_6 -> V_92 [ V_15 ] = V_59 -> V_91 [ V_15 ] ;
if ( V_59 -> V_91 [ V_15 ] == V_96 )
V_61 -> V_79 |= F_28 ( 1 << V_97 ) ;
V_32 = F_29 ( V_6 -> V_25 -> V_2 , V_64 , V_65 ,
V_98 ,
V_75 ,
V_76 ,
V_77 ) ;
if ( V_32 ) {
F_23 ( V_6 -> V_25 -> V_2 , V_93 ) ;
return V_32 ;
}
}
F_23 ( V_6 -> V_25 -> V_2 , V_93 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_99 * V_100 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_101 * V_102 ;
struct V_62 * V_63 = NULL ;
T_4 V_64 = 0 ;
T_5 V_65 = 0 ;
int V_15 , V_32 ;
if ( ! ( V_6 -> V_25 -> V_2 -> V_66 . V_67 & V_68 ) )
return - V_69 ;
V_63 = F_20 ( V_6 -> V_25 -> V_2 ) ;
if ( F_21 ( V_63 ) )
return - V_70 ;
V_102 =
(struct V_101 * )
V_63 -> V_71 ;
for ( V_15 = 0 ; V_15 < V_10 ; V_15 ++ ) {
V_65 = V_6 -> V_31 | ( ( 1 << V_15 ) << 8 ) |
( V_72 << 16 ) ;
V_32 = F_22 ( V_6 -> V_25 -> V_2 , V_64 ,
V_63 -> V_73 , V_65 ,
V_103 ,
V_75 ,
V_76 ,
V_77 ) ;
if ( V_32 ) {
F_23 ( V_6 -> V_25 -> V_2 , V_63 ) ;
return V_32 ;
}
V_100 -> V_104 [ V_15 ] =
F_31 ( V_102 -> V_104 ) ;
V_100 -> V_105 [ V_15 ] =
F_24 ( V_102 -> V_105 ) ;
}
F_23 ( V_6 -> V_25 -> V_2 , V_63 ) ;
return 0 ;
}
