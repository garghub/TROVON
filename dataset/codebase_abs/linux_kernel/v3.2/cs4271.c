static int F_1 ( struct V_1 * V_2 ,
int V_3 , unsigned int V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
V_9 -> V_10 = V_4 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
unsigned int V_12 = 0 ;
int V_13 ;
switch ( V_11 & V_14 ) {
case V_15 :
V_9 -> V_16 = 0 ;
break;
case V_17 :
V_9 -> V_16 = 1 ;
V_12 |= V_18 ;
break;
default:
F_4 ( V_7 -> V_19 , L_1 ) ;
return - V_20 ;
}
switch ( V_11 & V_21 ) {
case V_22 :
V_12 |= V_23 ;
V_13 = F_5 ( V_7 , V_24 ,
V_25 , V_26 ) ;
if ( V_13 < 0 )
return V_13 ;
break;
case V_27 :
V_12 |= V_28 ;
V_13 = F_5 ( V_7 , V_24 ,
V_25 , V_29 ) ;
if ( V_13 < 0 )
return V_13 ;
break;
default:
F_4 ( V_7 -> V_19 , L_1 ) ;
return - V_20 ;
}
V_13 = F_5 ( V_7 , V_30 ,
V_31 | V_18 , V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_32 , V_13 ;
int V_12 = V_33 ;
if ( V_9 -> V_34 ) {
V_12 = 1 ;
for ( V_32 = 2 ; V_32 < F_7 ( V_35 ) ; V_32 ++ )
if ( abs ( V_35 [ V_32 ] - V_9 -> V_36 ) <
abs ( V_35 [ V_12 ] - V_9 -> V_36 ) )
V_12 = V_32 ;
V_12 <<= 4 ;
}
V_13 = F_5 ( V_7 , V_37 ,
V_38 , V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_8 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_6 * V_7 = F_9 ( V_40 ) ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
V_42 -> V_43 . V_44 . V_45 [ 0 ] = V_9 -> V_34 ;
return 0 ;
}
static int F_10 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_6 * V_7 = F_9 ( V_40 ) ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
V_9 -> V_34 = V_42 -> V_43 . V_44 . V_45 [ 0 ] ;
return F_6 ( V_7 ) ;
}
static int F_11 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
struct V_1 * V_50 )
{
struct V_51 * V_52 = V_47 -> V_53 ;
struct V_6 * V_7 = V_52 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_32 , V_13 ;
unsigned int V_54 , V_12 ;
V_9 -> V_36 = F_12 ( V_49 ) ;
if ( V_9 -> V_36 < 50000 )
V_12 = V_55 ;
else if ( V_9 -> V_36 < 100000 )
V_12 = V_56 ;
else
V_12 = V_57 ;
V_54 = V_9 -> V_10 / V_9 -> V_36 ;
for ( V_32 = 0 ; V_32 < V_58 ; V_32 ++ )
if ( ( V_59 [ V_32 ] . V_16 == V_9 -> V_16 ) &&
( V_59 [ V_32 ] . V_60 == V_12 ) &&
( V_59 [ V_32 ] . V_54 == V_54 ) )
break;
if ( V_32 == V_58 ) {
F_4 ( V_7 -> V_19 , L_2 ) ;
return - V_20 ;
}
V_12 |= V_59 [ V_32 ] . V_61 ;
V_13 = F_5 ( V_7 , V_30 ,
V_62 | V_63 , V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_6 ( V_7 ) ;
}
static int F_13 ( struct V_1 * V_50 , int V_64 )
{
struct V_6 * V_7 = V_50 -> V_7 ;
int V_13 ;
int V_65 = 0 ;
int V_66 = 0 ;
if ( V_64 ) {
V_65 = V_67 ;
V_66 = V_68 ;
}
V_13 = F_5 ( V_7 , V_69 , V_67 , V_65 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_7 , V_70 , V_68 , V_66 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 , T_1 V_71 )
{
int V_13 ;
V_13 = F_5 ( V_7 , V_72 , V_73 ,
V_73 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 )
{
int V_13 ;
V_13 = F_16 ( V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_7 , V_72 , V_73 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_74 * V_75 = V_7 -> V_19 -> V_76 ;
int V_13 ;
int V_77 = - V_20 ;
if ( V_75 && F_18 ( V_75 -> V_77 ) )
V_77 = V_75 -> V_77 ;
if ( V_77 >= 0 )
if ( F_19 ( V_77 , L_3 ) )
V_77 = - V_20 ;
if ( V_77 >= 0 ) {
F_20 ( V_77 , 0 ) ;
F_21 ( 1 ) ;
F_22 ( V_77 , 1 ) ;
F_21 ( 1 ) ;
}
V_9 -> V_77 = V_77 ;
if ( V_9 -> V_78 == V_79 )
V_13 = F_23 ( V_7 , 16 , 8 ,
V_9 -> V_78 ) ;
else
V_13 = F_23 ( V_7 , 8 , 8 ,
V_9 -> V_78 ) ;
if ( V_13 ) {
F_4 ( V_7 -> V_19 , L_4 , V_13 ) ;
return V_13 ;
}
V_13 = F_5 ( V_7 , V_72 ,
V_73 | V_80 ,
V_73 | V_80 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_7 , V_72 , V_73 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
F_21 ( 85 ) ;
return F_24 ( V_7 , V_81 ,
F_7 ( V_81 ) ) ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_77 ;
V_77 = V_9 -> V_77 ;
if ( F_18 ( V_77 ) ) {
F_22 ( V_77 , 0 ) ;
F_26 ( V_77 ) ;
}
return 0 ;
}
static int T_2 F_27 ( struct V_82 * V_83 )
{
struct V_8 * V_9 ;
V_9 = F_28 ( & V_83 -> V_19 , sizeof( * V_9 ) , V_84 ) ;
if ( ! V_9 )
return - V_85 ;
F_29 ( V_83 , V_9 ) ;
V_9 -> V_78 = V_79 ;
return F_30 ( & V_83 -> V_19 , & V_86 ,
& V_87 , 1 ) ;
}
static int T_3 F_31 ( struct V_82 * V_83 )
{
F_32 ( & V_83 -> V_19 ) ;
return 0 ;
}
static int T_2 F_33 ( struct V_88 * V_89 ,
const struct V_90 * V_91 )
{
struct V_8 * V_9 ;
V_9 = F_28 ( & V_89 -> V_19 , sizeof( * V_9 ) , V_84 ) ;
if ( ! V_9 )
return - V_85 ;
F_34 ( V_89 , V_9 ) ;
V_9 -> V_78 = V_92 ;
return F_30 ( & V_89 -> V_19 , & V_86 ,
& V_87 , 1 ) ;
}
static int T_3 F_35 ( struct V_88 * V_89 )
{
F_32 ( & V_89 -> V_19 ) ;
return 0 ;
}
static int T_4 F_36 ( void )
{
int V_13 ;
#if F_37 ( V_93 ) || F_37 ( V_94 )
V_13 = F_38 ( & V_95 ) ;
if ( V_13 ) {
F_39 ( L_5 , V_13 ) ;
return V_13 ;
}
#endif
#if F_37 ( V_96 )
V_13 = F_40 ( & V_97 ) ;
if ( V_13 ) {
F_39 ( L_6 , V_13 ) ;
return V_13 ;
}
#endif
return 0 ;
}
static void T_5 F_41 ( void )
{
#if F_37 ( V_96 )
F_42 ( & V_97 ) ;
#endif
#if F_37 ( V_93 ) || F_37 ( V_94 )
F_43 ( & V_95 ) ;
#endif
}
