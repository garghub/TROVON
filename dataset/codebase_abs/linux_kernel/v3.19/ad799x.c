static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
switch ( V_2 -> V_4 ) {
case V_5 :
case V_6 :
return F_2 ( V_2 -> V_7 , V_8 ,
V_3 ) ;
case V_9 :
case V_10 :
case V_11 :
return F_3 ( V_2 -> V_7 , V_8 ,
V_3 ) ;
default:
V_2 -> V_12 = V_3 ;
return 0 ;
}
}
static int F_4 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_4 ) {
case V_5 :
case V_6 :
return F_5 ( V_2 -> V_7 , V_8 ) ;
case V_9 :
case V_10 :
case V_11 :
return F_6 ( V_2 -> V_7 , V_8 ) ;
default:
return V_2 -> V_12 ;
}
}
static T_2 F_7 ( int V_13 , void * V_14 )
{
struct V_15 * V_16 = V_14 ;
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_1 * V_2 = F_8 ( V_18 ) ;
int V_19 ;
T_3 V_20 ;
switch ( V_2 -> V_4 ) {
case V_21 :
case V_22 :
case V_23 :
V_20 = V_2 -> V_12 |
( * V_18 -> V_24 << V_25 ) ;
break;
case V_9 :
case V_10 :
case V_11 :
V_20 = ( * V_18 -> V_24 << V_25 ) |
V_26 ;
break;
case V_5 :
case V_6 :
V_20 = V_27 | V_26 ;
break;
default:
V_20 = 0 ;
}
V_19 = F_9 ( V_2 -> V_7 ,
V_20 , V_2 -> V_28 , V_2 -> V_29 ) ;
if ( V_19 < 0 )
goto V_30;
F_10 ( V_18 , V_2 -> V_29 ,
F_11 () ) ;
V_30:
F_12 ( V_18 -> V_31 ) ;
return V_32 ;
}
static int F_13 ( struct V_17 * V_18 ,
const unsigned long * V_33 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
F_14 ( V_2 -> V_29 ) ;
V_2 -> V_29 = F_15 ( V_18 -> V_34 , V_35 ) ;
if ( ! V_2 -> V_29 )
return - V_36 ;
V_2 -> V_28 = F_16 ( V_33 , V_18 -> V_37 ) * 2 ;
switch ( V_2 -> V_4 ) {
case V_9 :
case V_10 :
case V_11 :
case V_5 :
case V_6 :
V_2 -> V_12 &= ~ ( F_17 ( 7 , 0 ) << V_25 ) ;
V_2 -> V_12 |= ( * V_33 << V_25 ) ;
return F_1 ( V_2 , V_2 -> V_12 ) ;
default:
return 0 ;
}
}
static int F_18 ( struct V_1 * V_2 , unsigned V_38 )
{
T_3 V_20 ;
switch ( V_2 -> V_4 ) {
case V_21 :
case V_22 :
case V_23 :
V_20 = V_2 -> V_12 | ( F_19 ( V_38 ) << V_25 ) ;
break;
case V_9 :
case V_10 :
case V_11 :
V_20 = F_19 ( V_38 ) << V_25 ;
break;
case V_5 :
case V_6 :
V_20 = ( V_38 << V_25 ) | V_39 ;
break;
default:
return - V_40 ;
}
return F_5 ( V_2 -> V_7 , V_20 ) ;
}
static int F_20 ( struct V_17 * V_18 ,
struct V_41 const * V_42 ,
int * V_3 ,
int * V_43 ,
long V_44 )
{
int V_45 ;
struct V_1 * V_2 = F_8 ( V_18 ) ;
switch ( V_44 ) {
case V_46 :
F_21 ( & V_18 -> V_47 ) ;
if ( F_22 ( V_18 ) )
V_45 = - V_48 ;
else
V_45 = F_18 ( V_2 , V_42 -> V_49 ) ;
F_23 ( & V_18 -> V_47 ) ;
if ( V_45 < 0 )
return V_45 ;
* V_3 = ( V_45 >> V_42 -> V_50 . V_51 ) &
F_17 ( V_42 -> V_50 . V_52 - 1 , 0 ) ;
return V_53 ;
case V_54 :
V_45 = F_24 ( V_2 -> V_55 ) ;
if ( V_45 < 0 )
return V_45 ;
* V_3 = V_45 / 1000 ;
* V_43 = V_42 -> V_50 . V_52 ;
return V_56 ;
}
return - V_40 ;
}
static T_4 F_25 ( struct V_57 * V_58 ,
struct V_59 * V_60 ,
char * V_61 )
{
struct V_17 * V_18 = F_26 ( V_58 ) ;
struct V_1 * V_2 = F_8 ( V_18 ) ;
int V_45 = F_6 ( V_2 -> V_7 , V_62 ) ;
if ( V_45 < 0 )
return V_45 ;
return sprintf ( V_61 , L_1 , V_63 [ V_45 & V_64 ] ) ;
}
static T_4 F_27 ( struct V_57 * V_58 ,
struct V_59 * V_60 ,
const char * V_61 ,
T_5 V_65 )
{
struct V_17 * V_18 = F_26 ( V_58 ) ;
struct V_1 * V_2 = F_8 ( V_18 ) ;
long V_3 ;
int V_45 , V_66 ;
V_45 = F_28 ( V_61 , 10 , & V_3 ) ;
if ( V_45 )
return V_45 ;
F_21 ( & V_18 -> V_47 ) ;
V_45 = F_6 ( V_2 -> V_7 , V_62 ) ;
if ( V_45 < 0 )
goto V_67;
V_45 &= ~ V_64 ;
for ( V_66 = 0 ; V_66 < F_29 ( V_63 ) ; V_66 ++ )
if ( V_3 == V_63 [ V_66 ] )
break;
if ( V_66 == F_29 ( V_63 ) ) {
V_45 = - V_40 ;
goto V_67;
}
V_45 = F_3 ( V_2 -> V_7 , V_62 ,
V_45 | V_66 ) ;
if ( V_45 < 0 )
goto V_67;
V_45 = V_65 ;
V_67:
F_23 ( & V_18 -> V_47 ) ;
return V_45 ;
}
static int F_30 ( struct V_17 * V_18 ,
const struct V_41 * V_42 ,
enum V_68 type ,
enum V_69 V_70 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
if ( ! ( V_2 -> V_12 & V_71 ) )
return 0 ;
if ( ( V_2 -> V_12 >> V_25 ) & F_19 ( V_42 -> V_49 ) )
return 1 ;
return 0 ;
}
static int F_31 ( struct V_17 * V_18 ,
const struct V_41 * V_42 ,
enum V_68 type ,
enum V_69 V_70 ,
int V_72 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
int V_45 ;
F_21 ( & V_18 -> V_47 ) ;
if ( F_22 ( V_18 ) ) {
V_45 = - V_48 ;
goto V_73;
}
if ( V_72 )
V_2 -> V_12 |= F_19 ( V_42 -> V_49 ) << V_25 ;
else
V_2 -> V_12 &= ~ ( F_19 ( V_42 -> V_49 ) << V_25 ) ;
if ( V_2 -> V_12 >> V_25 )
V_2 -> V_12 |= V_71 ;
else
V_2 -> V_12 &= ~ V_71 ;
V_45 = F_1 ( V_2 , V_2 -> V_12 ) ;
V_73:
F_23 ( & V_18 -> V_47 ) ;
return V_45 ;
}
static unsigned int F_32 ( const struct V_41 * V_42 ,
enum V_69 V_70 ,
enum V_74 V_75 )
{
switch ( V_75 ) {
case V_76 :
if ( V_70 == V_77 )
return F_33 ( V_42 -> V_78 ) ;
else
return F_34 ( V_42 -> V_78 ) ;
case V_79 :
return F_35 ( V_42 -> V_78 ) ;
default:
return - V_40 ;
}
return 0 ;
}
static int F_36 ( struct V_17 * V_18 ,
const struct V_41 * V_42 ,
enum V_68 type ,
enum V_69 V_70 ,
enum V_74 V_75 ,
int V_3 , int V_43 )
{
int V_45 ;
struct V_1 * V_2 = F_8 ( V_18 ) ;
if ( V_3 < 0 || V_3 > F_17 ( V_42 -> V_50 . V_52 - 1 , 0 ) )
return - V_40 ;
F_21 ( & V_18 -> V_47 ) ;
V_45 = F_2 ( V_2 -> V_7 ,
F_32 ( V_42 , V_70 , V_75 ) ,
V_3 << V_42 -> V_50 . V_51 ) ;
F_23 ( & V_18 -> V_47 ) ;
return V_45 ;
}
static int F_37 ( struct V_17 * V_18 ,
const struct V_41 * V_42 ,
enum V_68 type ,
enum V_69 V_70 ,
enum V_74 V_75 ,
int * V_3 , int * V_43 )
{
int V_45 ;
struct V_1 * V_2 = F_8 ( V_18 ) ;
F_21 ( & V_18 -> V_47 ) ;
V_45 = F_5 ( V_2 -> V_7 ,
F_32 ( V_42 , V_70 , V_75 ) ) ;
F_23 ( & V_18 -> V_47 ) ;
if ( V_45 < 0 )
return V_45 ;
* V_3 = ( V_45 >> V_42 -> V_50 . V_51 ) &
F_17 ( V_42 -> V_50 . V_52 - 1 , 0 ) ;
return V_53 ;
}
static T_2 F_38 ( int V_13 , void * V_80 )
{
struct V_17 * V_18 = V_80 ;
struct V_1 * V_2 = F_8 ( V_80 ) ;
int V_66 , V_45 ;
V_45 = F_6 ( V_2 -> V_7 , V_81 ) ;
if ( V_45 <= 0 )
goto V_73;
if ( F_3 ( V_2 -> V_7 , V_81 ,
V_82 ) < 0 )
goto V_73;
for ( V_66 = 0 ; V_66 < 8 ; V_66 ++ ) {
if ( V_45 & F_19 ( V_66 ) )
F_39 ( V_18 ,
V_66 & 0x1 ?
F_40 ( V_83 ,
( V_66 >> 1 ) ,
V_84 ,
V_85 ) :
F_40 ( V_83 ,
( V_66 >> 1 ) ,
V_84 ,
V_77 ) ,
F_11 () ) ;
}
V_73:
return V_32 ;
}
static int F_41 ( struct V_86 * V_7 ,
const struct V_87 * V_4 )
{
int V_45 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
const struct V_88 * V_89 =
& V_90 [ V_4 -> V_91 ] ;
V_18 = F_42 ( & V_7 -> V_58 , sizeof( * V_2 ) ) ;
if ( V_18 == NULL )
return - V_36 ;
V_2 = F_8 ( V_18 ) ;
F_43 ( V_7 , V_18 ) ;
V_2 -> V_4 = V_4 -> V_91 ;
if ( V_7 -> V_13 > 0 && V_89 -> V_92 . V_75 )
V_2 -> V_93 = & V_89 -> V_92 ;
else
V_2 -> V_93 = & V_89 -> V_94 ;
V_2 -> V_95 = F_44 ( & V_7 -> V_58 , L_2 ) ;
if ( F_45 ( V_2 -> V_95 ) )
return F_46 ( V_2 -> V_95 ) ;
V_45 = F_47 ( V_2 -> V_95 ) ;
if ( V_45 )
return V_45 ;
V_2 -> V_55 = F_44 ( & V_7 -> V_58 , L_3 ) ;
if ( F_45 ( V_2 -> V_55 ) ) {
V_45 = F_46 ( V_2 -> V_55 ) ;
goto V_96;
}
V_45 = F_47 ( V_2 -> V_55 ) ;
if ( V_45 )
goto V_96;
V_2 -> V_7 = V_7 ;
V_18 -> V_58 . V_97 = & V_7 -> V_58 ;
V_18 -> V_98 = V_4 -> V_98 ;
V_18 -> V_75 = V_2 -> V_93 -> V_75 ;
V_18 -> V_99 = V_100 ;
V_18 -> V_101 = V_2 -> V_93 -> V_78 ;
V_18 -> V_102 = V_89 -> V_102 ;
V_45 = F_1 ( V_2 , V_2 -> V_93 -> V_103 ) ;
if ( V_45 < 0 )
goto V_96;
V_45 = F_4 ( V_2 ) ;
if ( V_45 < 0 )
goto V_96;
V_2 -> V_12 = V_45 ;
V_45 = F_48 ( V_18 , NULL ,
& F_7 , NULL ) ;
if ( V_45 )
goto V_104;
if ( V_7 -> V_13 > 0 ) {
V_45 = F_49 ( & V_7 -> V_58 ,
V_7 -> V_13 ,
NULL ,
F_38 ,
V_105 |
V_106 ,
V_7 -> V_98 ,
V_18 ) ;
if ( V_45 )
goto V_107;
}
V_45 = F_50 ( V_18 ) ;
if ( V_45 )
goto V_107;
return 0 ;
V_107:
F_51 ( V_18 ) ;
V_104:
F_52 ( V_2 -> V_55 ) ;
V_96:
F_52 ( V_2 -> V_95 ) ;
return V_45 ;
}
static int F_53 ( struct V_86 * V_7 )
{
struct V_17 * V_18 = F_54 ( V_7 ) ;
struct V_1 * V_2 = F_8 ( V_18 ) ;
F_55 ( V_18 ) ;
F_51 ( V_18 ) ;
F_52 ( V_2 -> V_55 ) ;
F_52 ( V_2 -> V_95 ) ;
F_14 ( V_2 -> V_29 ) ;
return 0 ;
}
