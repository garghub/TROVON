static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
return 1 ;
default:
return 0 ;
}
}
static void F_2 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_9 = 0 ;
F_3 ( V_2 -> V_10 , L_1 ) ;
do {
V_9 ++ ;
F_4 ( 1 ) ;
V_3 = F_5 ( V_2 , V_6 ) ;
F_3 ( V_2 -> V_10 , L_2 , V_3 ) ;
} while ( ( V_3 & V_11 )
!= V_11 && V_9 < 1000 );
if ( ( V_3 & V_11 )
!= V_11 )
F_6 ( V_2 -> V_10 , L_3 ) ;
}
static int F_7 ( struct V_12 * V_13 ,
struct V_14 * V_15 , int V_16 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned int V_3 = F_5 ( V_2 , V_17 ) ;
switch ( V_16 ) {
case V_18 :
F_8 ( V_2 , V_19 ,
V_20 , V_20 ) ;
F_4 ( 5 ) ;
F_8 ( V_2 , V_21 ,
V_22 | V_23 ,
V_22 | V_23 ) ;
V_3 |= V_24 | V_25 ;
F_9 ( V_2 , V_17 , V_3 ) ;
F_9 ( V_2 , V_5 ,
V_26 |
V_27 |
V_28 |
V_29 ) ;
F_2 ( V_2 ) ;
V_3 |= V_30 | V_31 |
V_32 | V_33 ;
F_9 ( V_2 , V_17 , V_3 ) ;
break;
case V_34 :
V_3 &= ~ ( V_33 |
V_24 |
V_32 |
V_31 |
V_25 |
V_30 ) ;
F_9 ( V_2 , V_17 , V_3 ) ;
F_9 ( V_2 , V_5 , 0 ) ;
F_8 ( V_2 , V_21 ,
V_22 | V_23 ,
0 ) ;
F_8 ( V_2 , V_19 ,
V_20 , 0 ) ;
break;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_11 ( V_2 ) ;
struct V_37 * V_38 = & V_2 -> V_38 ;
int V_39 ;
F_12 ( V_38 , V_40 ,
F_13 ( V_40 ) ) ;
F_14 ( V_38 , V_41 , F_13 ( V_41 ) ) ;
F_15 ( V_2 , V_42 ,
F_13 ( V_42 ) ) ;
if ( V_36 -> V_43 . V_44 ) {
F_14 ( V_38 , V_45 ,
F_13 ( V_45 ) ) ;
} else {
F_14 ( V_38 , V_46 ,
F_13 ( V_46 ) ) ;
F_15 ( V_2 , V_47 ,
F_13 ( V_47 ) ) ;
}
if ( V_36 -> V_43 . V_48 ) {
F_14 ( V_38 , V_49 ,
F_13 ( V_49 ) ) ;
} else {
F_14 ( V_38 , V_50 ,
F_13 ( V_50 ) ) ;
F_15 ( V_2 , V_51 ,
F_13 ( V_51 ) ) ;
}
if ( V_36 -> V_43 . V_52 ) {
for ( V_39 = 0 ; V_39 < F_13 ( V_36 -> V_43 . V_53 ) ; V_39 ++ )
F_9 ( V_2 , V_54 + V_39 ,
V_36 -> V_43 . V_53 [ V_39 ] ) ;
F_8 ( V_2 , V_55 ,
V_56 , V_56 ) ;
} else {
F_8 ( V_2 , V_55 ,
V_56 , 0 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
enum V_57 V_58 )
{
T_1 * V_59 = V_2 -> V_59 ;
int V_39 , V_60 ;
switch ( V_58 ) {
case V_61 :
break;
case V_62 :
F_8 ( V_2 , V_63 , V_64 ,
V_64 ) ;
F_8 ( V_2 , V_21 ,
V_65 |
V_66 ,
V_65 |
1 << V_67 ) ;
F_4 ( 1 ) ;
break;
case V_68 :
if ( V_2 -> V_38 . V_69 == V_70 ) {
F_17 ( V_2 ) ;
}
F_8 ( V_2 , V_21 ,
V_65 | V_66 , 0 ) ;
F_8 ( V_2 , V_63 ,
V_64 , 0 ) ;
break;
case V_70 :
break;
}
V_2 -> V_38 . V_69 = V_58 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_60 ;
V_60 = F_19 ( V_2 , 8 , 16 , V_71 ) ;
if ( V_60 != 0 ) {
F_6 ( V_2 -> V_10 , L_4 , V_60 ) ;
return V_60 ;
}
V_60 = F_5 ( V_2 , V_4 ) ;
if ( V_60 < 0 )
return V_60 ;
if ( V_60 != V_72 [ V_4 ] ) {
F_6 ( V_2 -> V_10 , L_5 , V_60 ) ;
return - V_73 ;
}
V_60 = F_9 ( V_2 , V_4 , 0 ) ;
if ( V_60 < 0 )
return V_60 ;
F_8 ( V_2 , V_74 ,
V_75 | V_76 ,
V_75 | V_76 ) ;
F_8 ( V_2 , V_77 ,
V_75 | V_78 ,
V_75 | V_78 ) ;
F_8 ( V_2 , V_79 ,
V_80 | V_81 ,
V_80 | V_81 ) ;
F_8 ( V_2 , V_82 ,
V_80 | V_83 ,
V_80 | V_83 ) ;
F_8 ( V_2 , V_84 ,
V_85 | V_86 ,
V_85 | V_86 ) ;
F_8 ( V_2 , V_87 ,
V_88 | V_89 ,
V_88 | V_89 ) ;
F_8 ( V_2 , V_90 ,
V_88 | V_91 ,
V_88 | V_91 ) ;
F_8 ( V_2 , V_92 ,
V_93 , V_93 ) ;
F_16 ( V_2 , V_68 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_70 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_68 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_70 ) ;
return 0 ;
}
static int F_23 ( struct V_94 * V_95 ,
const struct V_96 * V_97 )
{
struct V_35 * V_36 ;
int V_60 ;
V_36 = F_24 ( & V_95 -> V_10 , sizeof( * V_36 ) , V_98 ) ;
if ( V_36 == NULL ) {
F_6 ( & V_95 -> V_10 , L_6 ) ;
return - V_99 ;
}
if ( V_95 -> V_10 . V_100 )
memcpy ( & V_36 -> V_43 , V_95 -> V_10 . V_100 ,
sizeof( V_36 -> V_43 ) ) ;
F_25 ( V_95 , V_36 ) ;
V_60 = F_26 ( & V_95 -> V_10 ,
& V_101 , NULL , 0 ) ;
return V_60 ;
}
static int T_2 F_27 ( struct V_94 * V_95 )
{
struct V_35 * V_36 = F_28 ( V_95 ) ;
F_29 ( & V_95 -> V_10 ) ;
return 0 ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_102 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_102 ) ;
}
