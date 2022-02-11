static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
int V_8 = 0 ;
T_1 V_9 ;
F_2 ( V_6 , L_1 , V_3 ) ;
F_2 ( V_6 , L_2 , V_4 ) ;
F_3 ( & V_2 -> V_10 ) ;
V_9 = V_2 -> V_11 & ~ V_12 & ~ V_13 ;
switch ( V_3 ) {
case 48000 :
V_9 |= V_14 ;
break;
case 44100 :
V_9 |= V_15 ;
break;
case 32000 :
V_9 |= V_16 ;
break;
case 22050 :
V_9 |= V_17 ;
break;
case 16000 :
V_9 |= V_18 ;
break;
case 12000 :
V_9 |= V_19 ;
break;
case 11025 :
V_9 |= V_20 ;
break;
case 8000 :
V_9 |= V_21 ;
break;
default:
F_4 ( V_6 , L_3 , V_3 ) ;
V_8 = - V_22 ;
goto V_23;
}
switch ( V_4 ) {
case 16 :
V_9 |= V_24 ;
break;
case 20 :
V_9 |= V_25 ;
break;
case 24 :
V_9 |= V_26 ;
break;
case 25 :
V_9 |= V_27 ;
break;
case 30 :
V_9 |= V_28 ;
break;
case 32 :
V_9 |= V_29 ;
break;
case 40 :
V_9 |= V_30 ;
break;
case 48 :
V_9 |= V_31 ;
break;
case 64 :
V_9 |= V_32 ;
break;
default:
F_4 ( V_6 , L_4 , V_4 ) ;
V_8 = - V_22 ;
goto V_23;
}
F_2 ( V_6 , L_5 , V_33 ) ;
F_2 ( V_6 , L_6 , V_2 -> V_11 ) ;
F_2 ( V_6 , L_7 , V_9 ) ;
if ( V_2 -> V_11 != V_9 ) {
V_8 = V_2 -> V_34 ( V_2 , V_35 , V_9 ) ;
if ( V_8 )
goto V_23;
V_2 -> V_11 = V_9 ;
V_8 = V_2 -> V_34 ( V_2 , V_36 ,
V_37 ) ;
if ( V_8 )
goto V_23;
}
V_23:
F_5 ( & V_2 -> V_10 ) ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_38 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
int V_8 = 0 ;
F_2 ( V_6 , L_8 , V_39 ) ;
F_3 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_38 == V_38 )
goto V_23;
if ( V_38 == 1 && V_2 -> V_9 == V_40 )
V_8 = V_2 -> V_34 ( V_2 , V_41 , V_42 ) ;
else if ( V_38 == 1 && V_2 -> V_9 == V_43 )
V_8 = V_2 -> V_34 ( V_2 , V_44 , V_45 ) ;
else if ( V_38 == 2 && V_2 -> V_9 == V_40 )
V_8 = V_2 -> V_34 ( V_2 , V_41 , V_46 ) ;
else if ( V_38 == 2 && V_2 -> V_9 == V_43 )
V_8 = V_2 -> V_34 ( V_2 , V_44 , V_47 ) ;
else
V_8 = - V_22 ;
V_23:
F_5 ( & V_2 -> V_10 ) ;
return V_8 ;
}
static int F_7 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 = F_8 ( V_49 ) ;
struct V_54 * V_55 = F_9 ( V_53 ) ;
V_51 -> V_56 . integer . V_56 [ 0 ] = V_55 -> V_9 ;
return 0 ;
}
static int F_10 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 = F_8 ( V_49 ) ;
struct V_54 * V_55 = F_9 ( V_53 ) ;
if ( V_55 -> V_9 == V_51 -> V_56 . integer . V_56 [ 0 ] )
return 0 ;
if ( V_53 -> V_57 )
return - V_58 ;
if ( V_51 -> V_56 . integer . V_56 [ 0 ] < 0 ||
V_51 -> V_56 . integer . V_56 [ 0 ] >= F_11 ( V_59 ) )
return - V_22 ;
V_55 -> V_9 = V_51 -> V_56 . integer . V_56 [ 0 ] ;
return 1 ;
}
static int F_12 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 = F_8 ( V_49 ) ;
struct V_54 * V_55 = F_9 ( V_53 ) ;
F_2 ( V_53 -> V_6 , L_9 , V_39 ) ;
V_51 -> V_56 . integer . V_56 [ 0 ] = V_55 -> V_2 -> V_60 ;
return 0 ;
}
static int F_13 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 = F_8 ( V_49 ) ;
struct V_54 * V_55 = F_9 ( V_53 ) ;
int V_61 , V_8 = 0 ;
F_2 ( V_53 -> V_6 , L_9 , V_39 ) ;
V_61 = V_51 -> V_56 . integer . V_56 [ 0 ] ;
if ( V_55 -> V_2 -> V_60 == V_61 )
return 0 ;
V_8 = V_55 -> V_2 -> V_62 ( V_55 -> V_2 , V_61 ) ;
if ( V_8 < 0 )
return V_8 ;
return 1 ;
}
static int F_14 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 = F_8 ( V_49 ) ;
struct V_54 * V_55 = F_9 ( V_53 ) ;
F_2 ( V_53 -> V_6 , L_9 , V_39 ) ;
V_51 -> V_56 . integer . V_56 [ 0 ] = V_55 -> V_2 -> V_63 ;
return 0 ;
}
static int F_15 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 = F_8 ( V_49 ) ;
struct V_54 * V_55 = F_9 ( V_53 ) ;
int V_8 ;
F_2 ( V_53 -> V_6 , L_9 , V_39 ) ;
V_8 = V_55 -> V_2 -> V_64 ( V_55 -> V_2 ,
V_51 -> V_56 . integer . V_56 [ 0 ] ) ;
if ( V_8 )
return V_8 ;
return 1 ;
}
static int F_16 ( struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_69 * V_70 = V_66 -> V_71 ;
struct V_52 * V_53 = V_70 -> V_53 ;
struct V_54 * V_55 = F_9 ( V_53 ) ;
switch ( V_55 -> V_9 ) {
case V_72 :
F_17 ( V_66 -> V_73 ,
V_74 ,
8000 , 8000 ) ;
F_17 ( V_66 -> V_73 ,
V_75 , 1 , 1 ) ;
break;
case V_76 :
if ( V_66 -> V_77 == V_78 ) {
F_18 ( L_10 ) ;
return - V_22 ;
}
break;
case V_79 :
if ( V_66 -> V_77 == V_80 ) {
F_18 ( L_11 ) ;
return - V_22 ;
}
break;
default:
return - V_22 ;
break;
}
return 0 ;
}
static int F_19 ( struct V_65 * V_66 ,
struct V_81 * V_82 ,
struct V_67 * V_68 )
{
struct V_69 * V_70 = V_66 -> V_71 ;
struct V_54 * V_55 = F_9 ( V_70 -> V_53 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
unsigned int V_3 , V_4 , V_8 ;
if ( F_20 ( V_82 ) != V_83 ) {
F_18 ( L_12 ) ;
return - V_22 ;
}
V_3 = F_21 ( V_82 ) ;
V_4 = F_22 ( V_82 , V_84 ) -> V_85 ;
if ( V_55 -> V_9 == V_72 ) {
if ( V_3 != 8000 ) {
F_18 ( L_13 , F_21 ( V_82 ) ) ;
return - V_22 ;
}
if ( F_23 ( V_82 ) != 1 ) {
F_18 ( L_14 ) ;
return - V_22 ;
}
return 0 ;
}
if ( V_55 -> V_9 == V_79 &&
V_66 -> V_77 == V_80 ) {
F_18 ( L_15 ) ;
return - V_22 ;
}
if ( V_55 -> V_9 == V_76 &&
V_66 -> V_77 == V_78 ) {
F_18 ( L_16 ) ;
return - V_22 ;
}
if ( V_55 -> V_9 != V_76 &&
V_55 -> V_9 != V_79 ) {
F_18 ( L_17 , V_55 -> V_9 ) ;
return - V_22 ;
}
V_8 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_8 )
return V_8 ;
V_55 -> V_86 = F_23 ( V_82 ) ;
V_8 = F_6 ( V_2 , V_55 -> V_86 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
int F_24 ( struct V_52 * V_53 , unsigned int * V_87 )
{
struct V_54 * V_55 ;
if ( V_53 == NULL || V_87 == NULL )
return - V_22 ;
V_55 = F_9 ( V_53 ) ;
switch ( V_55 -> V_9 ) {
case V_76 :
case V_79 :
* V_87 = V_88 |
V_89 |
V_90 ;
break;
case V_72 :
* V_87 = V_91 |
V_92 |
V_90 ;
break;
default:
return - V_22 ;
}
return 0 ;
}
static int F_25 ( struct V_52 * V_53 )
{
struct V_1 * * V_2 = V_53 -> V_6 -> V_93 ;
struct V_54 * V_55 ;
int V_8 ;
F_2 ( V_53 -> V_6 , L_18 , V_39 ) ;
if ( ! V_2 ) {
F_4 ( V_53 -> V_6 , L_19 ) ;
return - V_22 ;
}
V_55 = F_26 ( sizeof( struct V_54 ) , V_94 ) ;
if ( V_55 == NULL ) {
F_4 ( V_53 -> V_6 , L_20 ) ;
return - V_95 ;
}
V_55 -> V_9 = V_72 ;
V_55 -> V_2 = * V_2 ;
F_27 ( V_53 , V_55 ) ;
V_8 = F_28 ( V_53 , V_96 ,
F_11 ( V_96 ) ) ;
if ( V_8 )
F_29 ( V_55 ) ;
return V_8 ;
}
static int F_30 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_9 ( V_53 ) ;
F_2 ( V_53 -> V_6 , L_8 , V_39 ) ;
F_29 ( V_55 ) ;
return 0 ;
}
static int T_2 F_31 ( struct V_97 * V_98 )
{
return F_32 ( & V_98 -> V_6 , & V_99 ,
& V_100 , 1 ) ;
}
static int T_3 F_33 ( struct V_97 * V_98 )
{
F_34 ( & V_98 -> V_6 ) ;
return 0 ;
}
