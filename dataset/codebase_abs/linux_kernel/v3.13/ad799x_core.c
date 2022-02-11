static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_2 ( V_6 , V_3 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_8 , L_1 ) ;
return V_7 ;
}
* V_4 = ( T_2 ) V_7 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_5 ( V_6 , V_3 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_8 , L_1 ) ;
return V_7 ;
}
* V_4 = ( T_1 ) V_7 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_7 ( V_6 , V_3 , V_4 ) ;
if ( V_7 < 0 )
F_3 ( & V_6 -> V_8 , L_2 ) ;
return V_7 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_9 ( V_6 , V_3 , V_4 ) ;
if ( V_7 < 0 )
F_3 ( & V_6 -> V_8 , L_2 ) ;
return V_7 ;
}
static int F_10 ( struct V_9 * V_10 ,
const unsigned long * V_11 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_12 ( V_2 -> V_12 ) ;
V_2 -> V_12 = F_13 ( V_10 -> V_13 , V_14 ) ;
if ( ! V_2 -> V_12 )
return - V_15 ;
V_2 -> V_16 = F_14 ( V_11 , V_10 -> V_17 ) * 2 ;
switch ( V_2 -> V_18 ) {
case V_19 :
case V_20 :
return F_6 ( V_2 , V_21 ,
V_2 -> V_22 | ( * V_11 << V_23 ) ) ;
default:
break;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_24 )
{
T_2 V_25 ;
T_1 V_26 ;
int V_7 ;
switch ( V_2 -> V_18 ) {
case V_27 :
case V_28 :
case V_29 :
V_26 = V_2 -> V_22 | ( ( 1 << V_24 ) << V_23 ) ;
break;
case V_30 :
case V_31 :
case V_32 :
V_26 = ( 1 << V_24 ) << V_23 ;
break;
case V_19 :
case V_20 :
V_26 = ( V_24 << V_23 ) | V_33 ;
break;
default:
return - V_34 ;
}
V_7 = F_1 ( V_2 , V_26 , & V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_25 ;
}
static int F_16 ( struct V_9 * V_10 ,
struct V_35 const * V_36 ,
int * V_37 ,
int * V_38 ,
long V_39 )
{
int V_7 ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
switch ( V_39 ) {
case V_40 :
F_17 ( & V_10 -> V_41 ) ;
if ( F_18 ( V_10 ) )
V_7 = - V_42 ;
else
V_7 = F_15 ( V_2 , V_36 -> V_43 ) ;
F_19 ( & V_10 -> V_41 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_37 = ( V_7 >> V_36 -> V_44 . V_45 ) &
F_20 ( V_36 -> V_44 . V_46 ) ;
return V_47 ;
case V_48 :
* V_37 = V_2 -> V_49 ;
* V_38 = V_36 -> V_44 . V_46 ;
return V_50 ;
}
return - V_34 ;
}
static T_3 F_21 ( struct V_51 * V_8 ,
struct V_52 * V_53 ,
char * V_54 )
{
struct V_9 * V_10 = F_22 ( V_8 ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
int V_7 ;
T_1 V_37 ;
V_7 = F_4 ( V_2 , V_55 , & V_37 ) ;
if ( V_7 )
return V_7 ;
V_37 &= V_56 ;
return sprintf ( V_54 , L_3 , V_57 [ V_37 ] ) ;
}
static T_3 F_23 ( struct V_51 * V_8 ,
struct V_52 * V_53 ,
const char * V_54 ,
T_4 V_58 )
{
struct V_9 * V_10 = F_22 ( V_8 ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
long V_37 ;
int V_7 , V_59 ;
T_1 V_60 ;
V_7 = F_24 ( V_54 , 10 , & V_37 ) ;
if ( V_7 )
return V_7 ;
F_17 ( & V_10 -> V_41 ) ;
V_7 = F_4 ( V_2 , V_55 , & V_60 ) ;
if ( V_7 )
goto V_61;
V_60 &= ~ V_56 ;
for ( V_59 = 0 ; V_59 < F_25 ( V_57 ) ; V_59 ++ )
if ( V_37 == V_57 [ V_59 ] )
break;
if ( V_59 == F_25 ( V_57 ) ) {
V_7 = - V_34 ;
goto V_61;
}
V_60 |= V_59 ;
V_7 = F_8 ( V_2 , V_55 , V_60 ) ;
V_61:
F_19 ( & V_10 -> V_41 ) ;
return V_7 ? V_7 : V_58 ;
}
static int F_26 ( struct V_9 * V_10 ,
const struct V_35 * V_36 ,
enum V_62 type ,
enum V_63 V_64 )
{
return 1 ;
}
static unsigned int F_27 ( const struct V_35 * V_36 ,
enum V_63 V_64 ,
enum V_65 V_66 )
{
switch ( V_66 ) {
case V_67 :
if ( V_64 == V_68 )
return F_28 ( V_36 -> V_69 ) ;
else
return F_29 ( V_36 -> V_69 ) ;
case V_70 :
return F_30 ( V_36 -> V_69 ) ;
default:
return - V_34 ;
}
return 0 ;
}
static int F_31 ( struct V_9 * V_10 ,
const struct V_35 * V_36 ,
enum V_62 type ,
enum V_63 V_64 ,
enum V_65 V_66 ,
int V_37 , int V_38 )
{
int V_7 ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_17 ( & V_10 -> V_41 ) ;
V_7 = F_6 ( V_2 , F_27 ( V_36 , V_64 , V_66 ) ,
V_37 ) ;
F_19 ( & V_10 -> V_41 ) ;
return V_7 ;
}
static int F_32 ( struct V_9 * V_10 ,
const struct V_35 * V_36 ,
enum V_62 type ,
enum V_63 V_64 ,
enum V_65 V_66 ,
int * V_37 , int * V_38 )
{
int V_7 ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
T_2 V_71 ;
F_17 ( & V_10 -> V_41 ) ;
V_7 = F_1 ( V_2 , F_27 ( V_36 , V_64 , V_66 ) ,
& V_71 ) ;
F_19 ( & V_10 -> V_41 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_37 = V_71 ;
return V_47 ;
}
static T_5 F_33 ( int V_72 , void * V_73 )
{
struct V_9 * V_10 = V_73 ;
struct V_1 * V_2 = F_11 ( V_73 ) ;
T_1 V_74 ;
int V_59 , V_7 ;
V_7 = F_4 ( V_2 , V_75 , & V_74 ) ;
if ( V_7 )
goto V_76;
if ( ! V_74 )
goto V_76;
F_8 ( V_2 , V_75 , V_77 ) ;
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
if ( V_74 & ( 1 << V_59 ) )
F_34 ( V_10 ,
V_59 & 0x1 ?
F_35 ( V_78 ,
( V_59 >> 1 ) ,
V_79 ,
V_80 ) :
F_35 ( V_78 ,
( V_59 >> 1 ) ,
V_79 ,
V_68 ) ,
F_36 () ) ;
}
V_76:
return V_81 ;
}
static int F_37 ( struct V_5 * V_6 ,
const struct V_82 * V_18 )
{
int V_7 ;
struct V_83 * V_84 = V_6 -> V_8 . V_85 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
V_10 = F_38 ( & V_6 -> V_8 , sizeof( * V_2 ) ) ;
if ( V_10 == NULL )
return - V_15 ;
V_2 = F_11 ( V_10 ) ;
F_39 ( V_6 , V_10 ) ;
V_2 -> V_18 = V_18 -> V_86 ;
V_2 -> V_87 = & V_88 [ V_2 -> V_18 ] ;
V_2 -> V_22 = V_2 -> V_87 -> V_89 ;
if ( ! V_84 )
return - V_34 ;
V_2 -> V_49 = V_84 -> V_90 ;
V_2 -> V_3 = F_40 ( & V_6 -> V_8 , L_4 ) ;
if ( ! F_41 ( V_2 -> V_3 ) ) {
V_7 = F_42 ( V_2 -> V_3 ) ;
if ( V_7 )
return V_7 ;
}
V_2 -> V_6 = V_6 ;
V_10 -> V_8 . V_91 = & V_6 -> V_8 ;
V_10 -> V_92 = V_18 -> V_92 ;
V_10 -> V_66 = V_2 -> V_87 -> V_66 ;
V_10 -> V_93 = V_94 ;
V_10 -> V_95 = V_2 -> V_87 -> V_69 ;
V_10 -> V_96 = V_2 -> V_87 -> V_96 ;
V_7 = F_43 ( V_10 ) ;
if ( V_7 )
goto V_97;
if ( V_6 -> V_72 > 0 ) {
V_7 = F_44 ( V_6 -> V_72 ,
NULL ,
F_33 ,
V_98 |
V_99 ,
V_6 -> V_92 ,
V_10 ) ;
if ( V_7 )
goto V_100;
}
V_7 = F_45 ( V_10 ) ;
if ( V_7 )
goto V_101;
return 0 ;
V_101:
F_46 ( V_6 -> V_72 , V_10 ) ;
V_100:
F_47 ( V_10 ) ;
V_97:
if ( ! F_41 ( V_2 -> V_3 ) )
F_48 ( V_2 -> V_3 ) ;
return V_7 ;
}
static int F_49 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_50 ( V_6 ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_51 ( V_10 ) ;
if ( V_6 -> V_72 > 0 )
F_46 ( V_6 -> V_72 , V_10 ) ;
F_47 ( V_10 ) ;
if ( ! F_41 ( V_2 -> V_3 ) )
F_48 ( V_2 -> V_3 ) ;
F_12 ( V_2 -> V_12 ) ;
return 0 ;
}
