static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
int V_9 ;
T_2 V_10 ;
switch ( V_8 -> V_11 ) {
case V_12 :
case V_13 :
case V_14 :
V_10 = V_8 -> V_15 |
( * V_6 -> V_16 << V_17 ) ;
break;
case V_18 :
case V_19 :
case V_20 :
V_10 = ( * V_6 -> V_16 << V_17 ) |
V_21 ;
break;
case V_22 :
case V_23 :
V_10 = V_24 | V_21 ;
break;
default:
V_10 = 0 ;
}
V_9 = F_3 ( V_8 -> V_25 ,
V_10 , V_8 -> V_26 , V_8 -> V_27 ) ;
if ( V_9 < 0 )
goto V_28;
F_4 ( V_6 , V_8 -> V_27 ,
F_5 () ) ;
V_28:
F_6 ( V_6 -> V_29 ) ;
return V_30 ;
}
static int F_7 ( struct V_7 * V_8 , T_2 V_31 , T_3 * V_32 )
{
struct V_33 * V_25 = V_8 -> V_25 ;
int V_34 = 0 ;
V_34 = F_8 ( V_25 , V_31 ) ;
if ( V_34 < 0 ) {
F_9 ( & V_25 -> V_35 , L_1 ) ;
return V_34 ;
}
* V_32 = ( T_3 ) V_34 ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 , T_2 V_31 , T_2 * V_32 )
{
struct V_33 * V_25 = V_8 -> V_25 ;
int V_34 = 0 ;
V_34 = F_11 ( V_25 , V_31 ) ;
if ( V_34 < 0 ) {
F_9 ( & V_25 -> V_35 , L_1 ) ;
return V_34 ;
}
* V_32 = ( T_2 ) V_34 ;
return 0 ;
}
static int F_12 ( struct V_7 * V_8 , T_2 V_31 , T_3 V_32 )
{
struct V_33 * V_25 = V_8 -> V_25 ;
int V_34 = 0 ;
V_34 = F_13 ( V_25 , V_31 , V_32 ) ;
if ( V_34 < 0 )
F_9 ( & V_25 -> V_35 , L_2 ) ;
return V_34 ;
}
static int F_14 ( struct V_7 * V_8 , T_2 V_31 , T_2 V_32 )
{
struct V_33 * V_25 = V_8 -> V_25 ;
int V_34 = 0 ;
V_34 = F_15 ( V_25 , V_31 , V_32 ) ;
if ( V_34 < 0 )
F_9 ( & V_25 -> V_35 , L_2 ) ;
return V_34 ;
}
static int F_16 ( struct V_5 * V_6 ,
const unsigned long * V_36 )
{
struct V_7 * V_8 = F_2 ( V_6 ) ;
F_17 ( V_8 -> V_27 ) ;
V_8 -> V_27 = F_18 ( V_6 -> V_37 , V_38 ) ;
if ( ! V_8 -> V_27 )
return - V_39 ;
V_8 -> V_26 = F_19 ( V_36 , V_6 -> V_40 ) * 2 ;
switch ( V_8 -> V_11 ) {
case V_22 :
case V_23 :
return F_12 ( V_8 , V_41 ,
V_8 -> V_15 | ( * V_36 << V_17 ) ) ;
default:
break;
}
return 0 ;
}
static int F_20 ( struct V_7 * V_8 , unsigned V_42 )
{
T_3 V_43 ;
T_2 V_10 ;
int V_34 ;
switch ( V_8 -> V_11 ) {
case V_12 :
case V_13 :
case V_14 :
V_10 = V_8 -> V_15 | ( ( 1 << V_42 ) << V_17 ) ;
break;
case V_18 :
case V_19 :
case V_20 :
V_10 = ( 1 << V_42 ) << V_17 ;
break;
case V_22 :
case V_23 :
V_10 = ( V_42 << V_17 ) | V_44 ;
break;
default:
return - V_45 ;
}
V_34 = F_7 ( V_8 , V_10 , & V_43 ) ;
if ( V_34 < 0 )
return V_34 ;
return V_43 ;
}
static int F_21 ( struct V_5 * V_6 ,
struct V_46 const * V_47 ,
int * V_48 ,
int * V_49 ,
long V_50 )
{
int V_34 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
switch ( V_50 ) {
case V_51 :
F_22 ( & V_6 -> V_52 ) ;
if ( F_23 ( V_6 ) )
V_34 = - V_53 ;
else
V_34 = F_20 ( V_8 , V_47 -> V_54 ) ;
F_24 ( & V_6 -> V_52 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_48 = ( V_34 >> V_47 -> V_55 . V_56 ) &
F_25 ( V_47 -> V_55 . V_57 ) ;
return V_58 ;
case V_59 :
V_34 = F_26 ( V_8 -> V_60 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_48 = V_34 / 1000 ;
* V_49 = V_47 -> V_55 . V_57 ;
return V_61 ;
}
return - V_45 ;
}
static T_4 F_27 ( struct V_62 * V_35 ,
struct V_63 * V_64 ,
char * V_65 )
{
struct V_5 * V_6 = F_28 ( V_35 ) ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
int V_34 ;
T_2 V_48 ;
V_34 = F_10 ( V_8 , V_66 , & V_48 ) ;
if ( V_34 )
return V_34 ;
V_48 &= V_67 ;
return sprintf ( V_65 , L_3 , V_68 [ V_48 ] ) ;
}
static T_4 F_29 ( struct V_62 * V_35 ,
struct V_63 * V_64 ,
const char * V_65 ,
T_5 V_69 )
{
struct V_5 * V_6 = F_28 ( V_35 ) ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
long V_48 ;
int V_34 , V_70 ;
T_2 V_71 ;
V_34 = F_30 ( V_65 , 10 , & V_48 ) ;
if ( V_34 )
return V_34 ;
F_22 ( & V_6 -> V_52 ) ;
V_34 = F_10 ( V_8 , V_66 , & V_71 ) ;
if ( V_34 )
goto V_72;
V_71 &= ~ V_67 ;
for ( V_70 = 0 ; V_70 < F_31 ( V_68 ) ; V_70 ++ )
if ( V_48 == V_68 [ V_70 ] )
break;
if ( V_70 == F_31 ( V_68 ) ) {
V_34 = - V_45 ;
goto V_72;
}
V_71 |= V_70 ;
V_34 = F_14 ( V_8 , V_66 , V_71 ) ;
V_72:
F_24 ( & V_6 -> V_52 ) ;
return V_34 ? V_34 : V_69 ;
}
static int F_32 ( struct V_5 * V_6 ,
const struct V_46 * V_47 ,
enum V_73 type ,
enum V_74 V_75 )
{
return 1 ;
}
static unsigned int F_33 ( const struct V_46 * V_47 ,
enum V_74 V_75 ,
enum V_76 V_77 )
{
switch ( V_77 ) {
case V_78 :
if ( V_75 == V_79 )
return F_34 ( V_47 -> V_80 ) ;
else
return F_35 ( V_47 -> V_80 ) ;
case V_81 :
return F_36 ( V_47 -> V_80 ) ;
default:
return - V_45 ;
}
return 0 ;
}
static int F_37 ( struct V_5 * V_6 ,
const struct V_46 * V_47 ,
enum V_73 type ,
enum V_74 V_75 ,
enum V_76 V_77 ,
int V_48 , int V_49 )
{
int V_34 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
if ( V_48 < 0 || V_48 > F_25 ( V_47 -> V_55 . V_57 ) )
return - V_45 ;
F_22 ( & V_6 -> V_52 ) ;
V_34 = F_12 ( V_8 , F_33 ( V_47 , V_75 , V_77 ) ,
V_48 << V_47 -> V_55 . V_56 ) ;
F_24 ( & V_6 -> V_52 ) ;
return V_34 ;
}
static int F_38 ( struct V_5 * V_6 ,
const struct V_46 * V_47 ,
enum V_73 type ,
enum V_74 V_75 ,
enum V_76 V_77 ,
int * V_48 , int * V_49 )
{
int V_34 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
T_3 V_82 ;
F_22 ( & V_6 -> V_52 ) ;
V_34 = F_7 ( V_8 , F_33 ( V_47 , V_75 , V_77 ) ,
& V_82 ) ;
F_24 ( & V_6 -> V_52 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_48 = ( V_82 >> V_47 -> V_55 . V_56 ) &
F_25 ( V_47 -> V_55 . V_57 ) ;
return V_58 ;
}
static T_1 F_39 ( int V_1 , void * V_83 )
{
struct V_5 * V_6 = V_83 ;
struct V_7 * V_8 = F_2 ( V_83 ) ;
T_2 V_84 ;
int V_70 , V_34 ;
V_34 = F_10 ( V_8 , V_85 , & V_84 ) ;
if ( V_34 )
goto V_86;
if ( ! V_84 )
goto V_86;
F_14 ( V_8 , V_85 , V_87 ) ;
for ( V_70 = 0 ; V_70 < 8 ; V_70 ++ ) {
if ( V_84 & ( 1 << V_70 ) )
F_40 ( V_6 ,
V_70 & 0x1 ?
F_41 ( V_88 ,
( V_70 >> 1 ) ,
V_89 ,
V_90 ) :
F_41 ( V_88 ,
( V_70 >> 1 ) ,
V_89 ,
V_79 ) ,
F_5 () ) ;
}
V_86:
return V_30 ;
}
static int F_42 ( struct V_33 * V_25 ,
const struct V_91 * V_11 )
{
int V_34 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
V_6 = F_43 ( & V_25 -> V_35 , sizeof( * V_8 ) ) ;
if ( V_6 == NULL )
return - V_39 ;
V_8 = F_2 ( V_6 ) ;
F_44 ( V_25 , V_6 ) ;
V_8 -> V_11 = V_11 -> V_92 ;
V_8 -> V_93 = & V_94 [ V_8 -> V_11 ] ;
V_8 -> V_15 = V_8 -> V_93 -> V_95 ;
V_8 -> V_31 = F_45 ( & V_25 -> V_35 , L_4 ) ;
if ( F_46 ( V_8 -> V_31 ) )
return F_47 ( V_8 -> V_31 ) ;
V_34 = F_48 ( V_8 -> V_31 ) ;
if ( V_34 )
return V_34 ;
V_8 -> V_60 = F_45 ( & V_25 -> V_35 , L_5 ) ;
if ( F_46 ( V_8 -> V_60 ) ) {
V_34 = F_47 ( V_8 -> V_60 ) ;
goto V_96;
}
V_34 = F_48 ( V_8 -> V_60 ) ;
if ( V_34 )
goto V_96;
V_8 -> V_25 = V_25 ;
V_6 -> V_35 . V_97 = & V_25 -> V_35 ;
V_6 -> V_98 = V_11 -> V_98 ;
V_6 -> V_77 = V_8 -> V_93 -> V_77 ;
V_6 -> V_99 = V_100 ;
V_6 -> V_101 = V_8 -> V_93 -> V_80 ;
V_6 -> V_102 = V_8 -> V_93 -> V_102 ;
V_34 = F_49 ( V_6 , NULL ,
& F_1 , NULL ) ;
if ( V_34 )
goto V_103;
if ( V_25 -> V_1 > 0 ) {
V_34 = F_50 ( & V_25 -> V_35 ,
V_25 -> V_1 ,
NULL ,
F_39 ,
V_104 |
V_105 ,
V_25 -> V_98 ,
V_6 ) ;
if ( V_34 )
goto V_106;
}
V_34 = F_51 ( V_6 ) ;
if ( V_34 )
goto V_106;
return 0 ;
V_106:
F_52 ( V_6 ) ;
V_103:
F_53 ( V_8 -> V_60 ) ;
V_96:
F_53 ( V_8 -> V_31 ) ;
return V_34 ;
}
static int F_54 ( struct V_33 * V_25 )
{
struct V_5 * V_6 = F_55 ( V_25 ) ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
F_56 ( V_6 ) ;
F_52 ( V_6 ) ;
F_53 ( V_8 -> V_60 ) ;
F_53 ( V_8 -> V_31 ) ;
F_17 ( V_8 -> V_27 ) ;
return 0 ;
}
