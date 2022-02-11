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
F_11 ( V_18 ) ) ;
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
V_45 = F_21 ( V_18 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_18 ( V_2 , V_42 -> V_47 ) ;
F_22 ( V_18 ) ;
if ( V_45 < 0 )
return V_45 ;
* V_3 = ( V_45 >> V_42 -> V_48 . V_49 ) &
F_17 ( V_42 -> V_48 . V_50 - 1 , 0 ) ;
return V_51 ;
case V_52 :
V_45 = F_23 ( V_2 -> V_53 ) ;
if ( V_45 < 0 )
return V_45 ;
* V_3 = V_45 / 1000 ;
* V_43 = V_42 -> V_48 . V_50 ;
return V_54 ;
}
return - V_40 ;
}
static T_4 F_24 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
char * V_59 )
{
struct V_17 * V_18 = F_25 ( V_56 ) ;
struct V_1 * V_2 = F_8 ( V_18 ) ;
int V_45 = F_6 ( V_2 -> V_7 , V_60 ) ;
if ( V_45 < 0 )
return V_45 ;
return sprintf ( V_59 , L_1 , V_61 [ V_45 & V_62 ] ) ;
}
static T_4 F_26 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
const char * V_59 ,
T_5 V_63 )
{
struct V_17 * V_18 = F_25 ( V_56 ) ;
struct V_1 * V_2 = F_8 ( V_18 ) ;
long V_3 ;
int V_45 , V_64 ;
V_45 = F_27 ( V_59 , 10 , & V_3 ) ;
if ( V_45 )
return V_45 ;
F_28 ( & V_18 -> V_65 ) ;
V_45 = F_6 ( V_2 -> V_7 , V_60 ) ;
if ( V_45 < 0 )
goto V_66;
V_45 &= ~ V_62 ;
for ( V_64 = 0 ; V_64 < F_29 ( V_61 ) ; V_64 ++ )
if ( V_3 == V_61 [ V_64 ] )
break;
if ( V_64 == F_29 ( V_61 ) ) {
V_45 = - V_40 ;
goto V_66;
}
V_45 = F_3 ( V_2 -> V_7 , V_60 ,
V_45 | V_64 ) ;
if ( V_45 < 0 )
goto V_66;
V_45 = V_63 ;
V_66:
F_30 ( & V_18 -> V_65 ) ;
return V_45 ;
}
static int F_31 ( struct V_17 * V_18 ,
const struct V_41 * V_42 ,
enum V_67 type ,
enum V_68 V_69 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
if ( ! ( V_2 -> V_12 & V_70 ) )
return 0 ;
if ( ( V_2 -> V_12 >> V_25 ) & F_19 ( V_42 -> V_47 ) )
return 1 ;
return 0 ;
}
static int F_32 ( struct V_17 * V_18 ,
const struct V_41 * V_42 ,
enum V_67 type ,
enum V_68 V_69 ,
int V_71 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
int V_45 ;
V_45 = F_21 ( V_18 ) ;
if ( V_45 )
return V_45 ;
if ( V_71 )
V_2 -> V_12 |= F_19 ( V_42 -> V_47 ) << V_25 ;
else
V_2 -> V_12 &= ~ ( F_19 ( V_42 -> V_47 ) << V_25 ) ;
if ( V_2 -> V_12 >> V_25 )
V_2 -> V_12 |= V_70 ;
else
V_2 -> V_12 &= ~ V_70 ;
V_45 = F_1 ( V_2 , V_2 -> V_12 ) ;
F_22 ( V_18 ) ;
return V_45 ;
}
static unsigned int F_33 ( const struct V_41 * V_42 ,
enum V_68 V_69 ,
enum V_72 V_73 )
{
switch ( V_73 ) {
case V_74 :
if ( V_69 == V_75 )
return F_34 ( V_42 -> V_76 ) ;
else
return F_35 ( V_42 -> V_76 ) ;
case V_77 :
return F_36 ( V_42 -> V_76 ) ;
default:
return - V_40 ;
}
return 0 ;
}
static int F_37 ( struct V_17 * V_18 ,
const struct V_41 * V_42 ,
enum V_67 type ,
enum V_68 V_69 ,
enum V_72 V_73 ,
int V_3 , int V_43 )
{
int V_45 ;
struct V_1 * V_2 = F_8 ( V_18 ) ;
if ( V_3 < 0 || V_3 > F_17 ( V_42 -> V_48 . V_50 - 1 , 0 ) )
return - V_40 ;
F_28 ( & V_18 -> V_65 ) ;
V_45 = F_2 ( V_2 -> V_7 ,
F_33 ( V_42 , V_69 , V_73 ) ,
V_3 << V_42 -> V_48 . V_49 ) ;
F_30 ( & V_18 -> V_65 ) ;
return V_45 ;
}
static int F_38 ( struct V_17 * V_18 ,
const struct V_41 * V_42 ,
enum V_67 type ,
enum V_68 V_69 ,
enum V_72 V_73 ,
int * V_3 , int * V_43 )
{
int V_45 ;
struct V_1 * V_2 = F_8 ( V_18 ) ;
F_28 ( & V_18 -> V_65 ) ;
V_45 = F_5 ( V_2 -> V_7 ,
F_33 ( V_42 , V_69 , V_73 ) ) ;
F_30 ( & V_18 -> V_65 ) ;
if ( V_45 < 0 )
return V_45 ;
* V_3 = ( V_45 >> V_42 -> V_48 . V_49 ) &
F_17 ( V_42 -> V_48 . V_50 - 1 , 0 ) ;
return V_51 ;
}
static T_2 F_39 ( int V_13 , void * V_78 )
{
struct V_17 * V_18 = V_78 ;
struct V_1 * V_2 = F_8 ( V_78 ) ;
int V_64 , V_45 ;
V_45 = F_6 ( V_2 -> V_7 , V_79 ) ;
if ( V_45 <= 0 )
goto V_80;
if ( F_3 ( V_2 -> V_7 , V_79 ,
V_81 ) < 0 )
goto V_80;
for ( V_64 = 0 ; V_64 < 8 ; V_64 ++ ) {
if ( V_45 & F_19 ( V_64 ) )
F_40 ( V_18 ,
V_64 & 0x1 ?
F_41 ( V_82 ,
( V_64 >> 1 ) ,
V_83 ,
V_84 ) :
F_41 ( V_82 ,
( V_64 >> 1 ) ,
V_83 ,
V_75 ) ,
F_11 ( V_18 ) ) ;
}
V_80:
return V_32 ;
}
static int F_42 ( struct V_85 * V_7 ,
const struct V_86 * V_4 )
{
int V_45 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
const struct V_87 * V_88 =
& V_89 [ V_4 -> V_90 ] ;
V_18 = F_43 ( & V_7 -> V_56 , sizeof( * V_2 ) ) ;
if ( V_18 == NULL )
return - V_36 ;
V_2 = F_8 ( V_18 ) ;
F_44 ( V_7 , V_18 ) ;
V_2 -> V_4 = V_4 -> V_90 ;
if ( V_7 -> V_13 > 0 && V_88 -> V_91 . V_73 )
V_2 -> V_92 = & V_88 -> V_91 ;
else
V_2 -> V_92 = & V_88 -> V_93 ;
V_2 -> V_94 = F_45 ( & V_7 -> V_56 , L_2 ) ;
if ( F_46 ( V_2 -> V_94 ) )
return F_47 ( V_2 -> V_94 ) ;
V_45 = F_48 ( V_2 -> V_94 ) ;
if ( V_45 )
return V_45 ;
V_2 -> V_53 = F_45 ( & V_7 -> V_56 , L_3 ) ;
if ( F_46 ( V_2 -> V_53 ) ) {
V_45 = F_47 ( V_2 -> V_53 ) ;
goto V_95;
}
V_45 = F_48 ( V_2 -> V_53 ) ;
if ( V_45 )
goto V_95;
V_2 -> V_7 = V_7 ;
V_18 -> V_56 . V_96 = & V_7 -> V_56 ;
V_18 -> V_56 . V_97 = V_7 -> V_56 . V_97 ;
V_18 -> V_98 = V_4 -> V_98 ;
V_18 -> V_73 = V_2 -> V_92 -> V_73 ;
V_18 -> V_99 = V_100 ;
V_18 -> V_101 = V_2 -> V_92 -> V_76 ;
V_18 -> V_102 = V_88 -> V_102 ;
V_45 = F_1 ( V_2 , V_2 -> V_92 -> V_103 ) ;
if ( V_45 < 0 )
goto V_95;
V_45 = F_4 ( V_2 ) ;
if ( V_45 < 0 )
goto V_95;
V_2 -> V_12 = V_45 ;
V_45 = F_49 ( V_18 , NULL ,
& F_7 , NULL ) ;
if ( V_45 )
goto V_104;
if ( V_7 -> V_13 > 0 ) {
V_45 = F_50 ( & V_7 -> V_56 ,
V_7 -> V_13 ,
NULL ,
F_39 ,
V_105 |
V_106 ,
V_7 -> V_98 ,
V_18 ) ;
if ( V_45 )
goto V_107;
}
V_45 = F_51 ( V_18 ) ;
if ( V_45 )
goto V_107;
return 0 ;
V_107:
F_52 ( V_18 ) ;
V_104:
F_53 ( V_2 -> V_53 ) ;
V_95:
F_53 ( V_2 -> V_94 ) ;
return V_45 ;
}
static int F_54 ( struct V_85 * V_7 )
{
struct V_17 * V_18 = F_55 ( V_7 ) ;
struct V_1 * V_2 = F_8 ( V_18 ) ;
F_56 ( V_18 ) ;
F_52 ( V_18 ) ;
F_53 ( V_2 -> V_53 ) ;
F_53 ( V_2 -> V_94 ) ;
F_14 ( V_2 -> V_29 ) ;
return 0 ;
}
