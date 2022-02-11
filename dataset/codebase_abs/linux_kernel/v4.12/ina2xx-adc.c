static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ( V_3 == V_4 ) || ( V_3 > V_5 ) ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ( V_3 != V_4 ) ;
}
static inline bool F_3 ( unsigned int V_3 )
{
return ( V_3 == V_6 ) || ( V_3 == V_5 ) ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 const * V_10 ,
int * V_11 , int * V_12 , long V_13 )
{
int V_14 ;
struct V_15 * V_16 = F_5 ( V_8 ) ;
unsigned int V_17 ;
switch ( V_13 ) {
case V_18 :
V_14 = F_6 ( V_16 -> V_19 , V_10 -> V_20 , & V_17 ) ;
if ( V_14 )
return V_14 ;
if ( F_3 ( V_10 -> V_20 ) )
* V_11 = ( V_21 ) V_17 ;
else
* V_11 = V_17 ;
return V_22 ;
case V_23 :
* V_11 = V_16 -> V_24 ;
return V_22 ;
case V_25 :
* V_11 = 0 ;
if ( V_10 -> V_20 == V_6 )
* V_12 = V_16 -> V_26 ;
else
* V_12 = V_16 -> V_27 ;
return V_28 ;
case V_29 :
* V_11 = F_7 ( 1000000 , F_8 ( V_16 ) ) ;
return V_22 ;
case V_30 :
switch ( V_10 -> V_20 ) {
case V_6 :
* V_12 = V_16 -> V_31 -> V_32 ;
* V_11 = 1 ;
return V_33 ;
case V_34 :
* V_11 = V_16 -> V_31 -> V_35 ;
* V_12 = 1000 << V_16 -> V_31 -> V_36 ;
return V_33 ;
case V_37 :
* V_11 = V_16 -> V_31 -> V_38 ;
* V_12 = 1000 ;
return V_33 ;
case V_5 :
* V_11 = 1 ;
return V_22 ;
}
}
return - V_39 ;
}
static int F_9 ( struct V_15 * V_16 , unsigned int V_11 ,
unsigned int * V_31 )
{
int V_40 ;
if ( V_11 > 1024 || V_11 < 1 )
return - V_39 ;
V_40 = F_10 ( V_11 , V_41 ,
F_11 ( V_41 ) ) ;
V_16 -> V_24 = V_41 [ V_40 ] ;
* V_31 &= ~ V_42 ;
* V_31 |= F_12 ( V_40 ) & V_42 ;
return 0 ;
}
static int F_13 ( struct V_15 * V_16 ,
unsigned int V_43 , unsigned int * V_31 )
{
int V_40 ;
if ( V_43 > 8244 || V_43 < 140 )
return - V_39 ;
V_40 = F_10 ( V_43 , V_44 ,
F_11 ( V_44 ) ) ;
V_16 -> V_27 = V_44 [ V_40 ] ;
* V_31 &= ~ V_45 ;
* V_31 |= F_14 ( V_40 ) & V_45 ;
return 0 ;
}
static int F_15 ( struct V_15 * V_16 ,
unsigned int V_43 , unsigned int * V_31 )
{
int V_40 ;
if ( V_43 > 8244 || V_43 < 140 )
return - V_39 ;
V_40 = F_10 ( V_43 , V_44 ,
F_11 ( V_44 ) ) ;
V_16 -> V_26 = V_44 [ V_40 ] ;
* V_31 &= ~ V_46 ;
* V_31 |= F_16 ( V_40 ) & V_46 ;
return 0 ;
}
static int F_17 ( struct V_7 * V_8 ,
struct V_9 const * V_10 ,
int V_11 , int V_12 , long V_13 )
{
struct V_15 * V_16 = F_5 ( V_8 ) ;
unsigned int V_31 , V_47 ;
int V_14 ;
if ( F_18 ( V_8 ) )
return - V_48 ;
F_19 ( & V_16 -> V_49 ) ;
V_14 = F_6 ( V_16 -> V_19 , V_4 , & V_31 ) ;
if ( V_14 )
goto V_50;
V_47 = V_31 ;
switch ( V_13 ) {
case V_23 :
V_14 = F_9 ( V_16 , V_11 , & V_47 ) ;
break;
case V_25 :
if ( V_10 -> V_20 == V_6 )
V_14 = F_15 ( V_16 , V_12 , & V_47 ) ;
else
V_14 = F_13 ( V_16 , V_12 , & V_47 ) ;
break;
default:
V_14 = - V_39 ;
}
if ( ! V_14 && ( V_47 != V_31 ) )
V_14 = F_20 ( V_16 -> V_19 , V_4 , V_47 ) ;
V_50:
F_21 ( & V_16 -> V_49 ) ;
return V_14 ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_51 * V_52 ,
char * V_53 )
{
struct V_15 * V_16 = F_5 ( F_23 ( V_2 ) ) ;
return sprintf ( V_53 , L_1 , V_16 -> V_54 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_51 * V_52 ,
const char * V_53 , T_2 V_55 )
{
struct V_15 * V_16 = F_5 ( F_23 ( V_2 ) ) ;
bool V_11 ;
int V_14 ;
V_14 = F_25 ( ( const char * ) V_53 , & V_11 ) ;
if ( V_14 )
return V_14 ;
V_16 -> V_54 = V_11 ;
return V_55 ;
}
static int F_26 ( struct V_15 * V_16 )
{
T_3 V_17 = F_7 ( V_16 -> V_31 -> V_56 ,
V_16 -> V_57 ) ;
return F_20 ( V_16 -> V_19 , V_58 , V_17 ) ;
}
static int F_27 ( struct V_15 * V_16 , unsigned int V_11 )
{
if ( V_11 <= 0 || V_11 > V_16 -> V_31 -> V_56 )
return - V_39 ;
V_16 -> V_57 = V_11 ;
return 0 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_51 * V_52 ,
char * V_53 )
{
struct V_15 * V_16 = F_5 ( F_23 ( V_2 ) ) ;
return sprintf ( V_53 , L_1 , V_16 -> V_57 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_51 * V_52 ,
const char * V_53 , T_2 V_55 )
{
struct V_15 * V_16 = F_5 ( F_23 ( V_2 ) ) ;
unsigned long V_11 ;
int V_14 ;
V_14 = F_30 ( ( const char * ) V_53 , 10 , & V_11 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_27 ( V_16 , V_11 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_26 ( V_16 ) ;
if ( V_14 )
return V_14 ;
return V_55 ;
}
static int F_31 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = F_5 ( V_8 ) ;
unsigned short V_59 [ 8 ] ;
int V_60 , V_14 , V_61 = 0 ;
T_4 V_62 , V_63 ;
unsigned int V_64 ;
V_62 = F_32 ( V_8 ) ;
if ( ! V_16 -> V_54 )
do {
V_14 = F_6 ( V_16 -> V_19 , V_65 ,
& V_64 ) ;
if ( V_14 < 0 )
return V_14 ;
V_64 &= V_66 ;
} while ( ! V_64 );
F_33 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
unsigned int V_11 ;
V_14 = F_6 ( V_16 -> V_19 ,
V_6 + V_60 , & V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
V_59 [ V_61 ++ ] = V_11 ;
}
V_63 = F_32 ( V_8 ) ;
F_34 ( V_8 ,
( unsigned int * ) V_59 , V_62 ) ;
return ( unsigned long ) ( V_63 - V_62 ) / 1000 ;
}
static int F_35 ( void * V_59 )
{
struct V_7 * V_8 = V_59 ;
struct V_15 * V_16 = F_5 ( V_8 ) ;
unsigned int V_67 = F_8 ( V_16 ) ;
int V_68 ;
if ( ! V_16 -> V_54 )
V_67 -= 200 ;
do {
V_68 = F_31 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( V_67 > V_68 )
F_36 ( V_67 - V_68 ) ;
} while ( ! F_37 () );
return 0 ;
}
static int F_38 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = F_5 ( V_8 ) ;
unsigned int V_67 = F_8 ( V_16 ) ;
F_39 ( & V_8 -> V_2 , L_2 ,
( unsigned int ) ( * V_8 -> V_69 ) ,
1000000 / V_67 , V_16 -> V_24 ) ;
F_39 ( & V_8 -> V_2 , L_3 , V_67 ) ;
F_39 ( & V_8 -> V_2 , L_4 ,
V_16 -> V_54 ) ;
V_16 -> V_70 = F_40 ( F_35 , ( void * ) V_8 ,
L_5 , V_8 -> V_71 , V_8 -> V_72 ,
V_67 ) ;
return F_41 ( V_16 -> V_70 ) ;
}
static int F_42 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = F_5 ( V_8 ) ;
if ( V_16 -> V_70 ) {
F_43 ( V_16 -> V_70 ) ;
V_16 -> V_70 = NULL ;
}
return 0 ;
}
static int F_44 ( struct V_7 * V_8 ,
unsigned V_3 , unsigned V_73 , unsigned * V_74 )
{
struct V_15 * V_16 = F_5 ( V_8 ) ;
if ( ! V_74 )
return F_20 ( V_16 -> V_19 , V_3 , V_73 ) ;
return F_6 ( V_16 -> V_19 , V_3 , V_74 ) ;
}
static int F_45 ( struct V_15 * V_16 , unsigned int V_31 )
{
int V_14 = F_20 ( V_16 -> V_19 , V_4 , V_31 ) ;
if ( V_14 )
return V_14 ;
return F_26 ( V_16 ) ;
}
static int F_46 ( struct V_75 * V_76 ,
const struct V_77 * V_72 )
{
struct V_15 * V_16 ;
struct V_7 * V_8 ;
struct V_78 * V_79 ;
unsigned int V_11 ;
enum V_80 type ;
int V_14 ;
V_8 = F_47 ( & V_76 -> V_2 , sizeof( * V_16 ) ) ;
if ( ! V_8 )
return - V_81 ;
V_16 = F_5 ( V_8 ) ;
F_48 ( V_76 , V_8 ) ;
V_16 -> V_19 = F_49 ( V_76 , & V_82 ) ;
if ( F_50 ( V_16 -> V_19 ) ) {
F_51 ( & V_76 -> V_2 , L_6 ) ;
return F_52 ( V_16 -> V_19 ) ;
}
if ( V_76 -> V_2 . V_83 )
type = (enum V_80 ) F_53 ( & V_76 -> V_2 ) ;
else
type = V_72 -> V_84 ;
V_16 -> V_31 = & V_85 [ type ] ;
F_54 ( & V_16 -> V_49 ) ;
if ( F_55 ( V_76 -> V_2 . V_83 ,
L_7 , & V_11 ) < 0 ) {
struct V_86 * V_87 =
F_56 ( & V_76 -> V_2 ) ;
if ( V_87 )
V_11 = V_87 -> V_88 ;
else
V_11 = V_89 ;
}
V_14 = F_27 ( V_16 , V_11 ) ;
if ( V_14 )
return V_14 ;
V_11 = V_16 -> V_31 -> V_90 ;
if ( V_72 -> V_84 == V_91 ) {
F_9 ( V_16 , V_92 , & V_11 ) ;
F_13 ( V_16 , V_93 , & V_11 ) ;
F_15 ( V_16 , V_93 , & V_11 ) ;
}
V_14 = F_45 ( V_16 , V_11 ) ;
if ( V_14 ) {
F_51 ( & V_76 -> V_2 , L_8 ) ;
return V_14 ;
}
V_8 -> V_94 = V_95 | V_96 ;
V_8 -> V_2 . V_97 = & V_76 -> V_2 ;
V_8 -> V_2 . V_83 = V_76 -> V_2 . V_83 ;
V_8 -> V_98 = V_99 ;
V_8 -> V_100 = F_11 ( V_99 ) ;
V_8 -> V_71 = V_72 -> V_71 ;
V_8 -> V_101 = & V_102 ;
V_8 -> V_103 = & V_104 ;
V_79 = F_57 ( & V_8 -> V_2 ) ;
if ( ! V_79 )
return - V_81 ;
F_58 ( V_8 , V_79 ) ;
return F_59 ( V_8 ) ;
}
static int F_60 ( struct V_75 * V_76 )
{
struct V_7 * V_8 = F_61 ( V_76 ) ;
struct V_15 * V_16 = F_5 ( V_8 ) ;
F_62 ( V_8 ) ;
return F_63 ( V_16 -> V_19 , V_4 ,
V_105 , 0 ) ;
}
