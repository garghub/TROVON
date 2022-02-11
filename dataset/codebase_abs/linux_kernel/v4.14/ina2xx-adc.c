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
static int F_17 ( unsigned int * V_43 , int * V_40 )
{
if ( * V_43 > 68100 || * V_43 < 84 )
return - V_39 ;
if ( * V_43 <= 532 ) {
* V_40 = F_10 ( * V_43 , V_47 ,
F_11 ( V_47 ) ) ;
* V_43 = V_47 [ * V_40 ] ;
} else {
* V_40 = F_10 ( * V_43 , V_48 ,
F_11 ( V_48 ) ) ;
* V_43 = V_48 [ * V_40 ] ;
* V_40 |= 0x8 ;
}
return 0 ;
}
static int F_18 ( struct V_15 * V_16 ,
unsigned int V_43 , unsigned int * V_31 )
{
int V_40 , V_14 ;
unsigned int V_49 = V_43 ;
V_14 = F_17 ( & V_49 , & V_40 ) ;
if ( V_14 )
return V_14 ;
V_16 -> V_27 = V_49 ;
* V_31 &= ~ V_50 ;
* V_31 |= F_19 ( V_40 ) & V_50 ;
return 0 ;
}
static int F_20 ( struct V_15 * V_16 ,
unsigned int V_43 , unsigned int * V_31 )
{
int V_40 , V_14 ;
unsigned int V_49 = V_43 ;
V_14 = F_17 ( & V_49 , & V_40 ) ;
if ( V_14 )
return V_14 ;
V_16 -> V_26 = V_49 ;
* V_31 &= ~ V_51 ;
* V_31 |= F_21 ( V_40 ) & V_51 ;
return 0 ;
}
static int F_22 ( struct V_7 * V_8 ,
struct V_9 const * V_10 ,
int V_11 , int V_12 , long V_13 )
{
struct V_15 * V_16 = F_5 ( V_8 ) ;
unsigned int V_31 , V_52 ;
int V_14 ;
if ( F_23 ( V_8 ) )
return - V_53 ;
F_24 ( & V_16 -> V_54 ) ;
V_14 = F_6 ( V_16 -> V_19 , V_4 , & V_31 ) ;
if ( V_14 )
goto V_55;
V_52 = V_31 ;
switch ( V_13 ) {
case V_23 :
V_14 = F_9 ( V_16 , V_11 , & V_52 ) ;
break;
case V_25 :
if ( V_16 -> V_31 -> V_56 == V_57 ) {
if ( V_10 -> V_20 == V_6 )
V_14 = F_15 ( V_16 , V_12 ,
& V_52 ) ;
else
V_14 = F_13 ( V_16 , V_12 ,
& V_52 ) ;
} else {
if ( V_10 -> V_20 == V_6 )
V_14 = F_20 ( V_16 , V_12 ,
& V_52 ) ;
else
V_14 = F_18 ( V_16 , V_12 ,
& V_52 ) ;
}
break;
default:
V_14 = - V_39 ;
}
if ( ! V_14 && ( V_52 != V_31 ) )
V_14 = F_25 ( V_16 -> V_19 , V_4 , V_52 ) ;
V_55:
F_26 ( & V_16 -> V_54 ) ;
return V_14 ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
char * V_60 )
{
struct V_15 * V_16 = F_5 ( F_28 ( V_2 ) ) ;
return sprintf ( V_60 , L_1 , V_16 -> V_61 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
const char * V_60 , T_2 V_62 )
{
struct V_15 * V_16 = F_5 ( F_28 ( V_2 ) ) ;
bool V_11 ;
int V_14 ;
V_14 = F_30 ( ( const char * ) V_60 , & V_11 ) ;
if ( V_14 )
return V_14 ;
V_16 -> V_61 = V_11 ;
return V_62 ;
}
static int F_31 ( struct V_15 * V_16 )
{
T_3 V_17 = F_7 ( V_16 -> V_31 -> V_63 ,
V_16 -> V_64 ) ;
return F_25 ( V_16 -> V_19 , V_65 , V_17 ) ;
}
static int F_32 ( struct V_15 * V_16 , unsigned int V_11 )
{
if ( V_11 <= 0 || V_11 > V_16 -> V_31 -> V_63 )
return - V_39 ;
V_16 -> V_64 = V_11 ;
return 0 ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
char * V_60 )
{
struct V_15 * V_16 = F_5 ( F_28 ( V_2 ) ) ;
return sprintf ( V_60 , L_1 , V_16 -> V_64 ) ;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
const char * V_60 , T_2 V_62 )
{
struct V_15 * V_16 = F_5 ( F_28 ( V_2 ) ) ;
unsigned long V_11 ;
int V_14 ;
V_14 = F_35 ( ( const char * ) V_60 , 10 , & V_11 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_32 ( V_16 , V_11 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_31 ( V_16 ) ;
if ( V_14 )
return V_14 ;
return V_62 ;
}
static int F_36 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = F_5 ( V_8 ) ;
unsigned short V_66 [ 8 ] ;
int V_67 , V_14 , V_68 = 0 ;
T_4 V_69 , V_70 ;
unsigned int V_71 ;
int V_72 = 0 ;
V_69 = F_37 ( V_8 ) ;
if ( ! V_16 -> V_61 )
do {
if ( V_16 -> V_31 -> V_56 == V_57 ) {
V_14 = F_6 ( V_16 -> V_19 ,
V_73 , & V_71 ) ;
V_71 &= V_74 ;
} else {
V_14 = F_6 ( V_16 -> V_19 ,
V_34 , & V_71 ) ;
V_71 &= V_75 ;
V_72 = V_71 ;
}
if ( V_14 < 0 )
return V_14 ;
} while ( ! V_71 );
F_38 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
unsigned int V_11 ;
V_14 = F_6 ( V_16 -> V_19 ,
V_6 + V_67 , & V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
V_66 [ V_68 ++ ] = V_11 ;
if ( V_6 + V_67 == V_37 )
V_72 = 0 ;
}
if ( V_72 && V_16 -> V_31 -> V_56 == V_76 ) {
unsigned int V_11 ;
V_14 = F_6 ( V_16 -> V_19 , V_37 , & V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
}
V_70 = F_37 ( V_8 ) ;
F_39 ( V_8 ,
( unsigned int * ) V_66 , V_69 ) ;
return ( unsigned long ) ( V_70 - V_69 ) / 1000 ;
}
static int F_40 ( void * V_66 )
{
struct V_7 * V_8 = V_66 ;
struct V_15 * V_16 = F_5 ( V_8 ) ;
int V_77 = F_8 ( V_16 ) ;
int V_78 ;
if ( ! V_16 -> V_61 )
V_77 -= 200 ;
do {
V_78 = F_36 ( V_8 ) ;
if ( V_78 < 0 )
return V_78 ;
if ( V_77 > V_78 )
F_41 ( V_77 - V_78 ) ;
} while ( ! F_42 () );
return 0 ;
}
static int F_43 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = F_5 ( V_8 ) ;
unsigned int V_77 = F_8 ( V_16 ) ;
F_44 ( & V_8 -> V_2 , L_2 ,
( unsigned int ) ( * V_8 -> V_79 ) ,
1000000 / V_77 , V_16 -> V_24 ) ;
F_44 ( & V_8 -> V_2 , L_3 , V_77 ) ;
F_44 ( & V_8 -> V_2 , L_4 ,
V_16 -> V_61 ) ;
V_16 -> V_80 = F_45 ( F_40 , ( void * ) V_8 ,
L_5 , V_8 -> V_81 , V_8 -> V_82 ,
V_77 ) ;
return F_46 ( V_16 -> V_80 ) ;
}
static int F_47 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = F_5 ( V_8 ) ;
if ( V_16 -> V_80 ) {
F_48 ( V_16 -> V_80 ) ;
V_16 -> V_80 = NULL ;
}
return 0 ;
}
static int F_49 ( struct V_7 * V_8 ,
unsigned V_3 , unsigned V_83 , unsigned * V_84 )
{
struct V_15 * V_16 = F_5 ( V_8 ) ;
if ( ! V_84 )
return F_25 ( V_16 -> V_19 , V_3 , V_83 ) ;
return F_6 ( V_16 -> V_19 , V_3 , V_84 ) ;
}
static int F_50 ( struct V_15 * V_16 , unsigned int V_31 )
{
int V_14 = F_25 ( V_16 -> V_19 , V_4 , V_31 ) ;
if ( V_14 )
return V_14 ;
return F_31 ( V_16 ) ;
}
static int F_51 ( struct V_85 * V_86 ,
const struct V_87 * V_82 )
{
struct V_15 * V_16 ;
struct V_7 * V_8 ;
struct V_88 * V_89 ;
unsigned int V_11 ;
enum V_90 type ;
int V_14 ;
V_8 = F_52 ( & V_86 -> V_2 , sizeof( * V_16 ) ) ;
if ( ! V_8 )
return - V_91 ;
V_16 = F_5 ( V_8 ) ;
F_53 ( V_86 , V_8 ) ;
V_16 -> V_19 = F_54 ( V_86 , & V_92 ) ;
if ( F_55 ( V_16 -> V_19 ) ) {
F_56 ( & V_86 -> V_2 , L_6 ) ;
return F_57 ( V_16 -> V_19 ) ;
}
if ( V_86 -> V_2 . V_93 )
type = (enum V_90 ) F_58 ( & V_86 -> V_2 ) ;
else
type = V_82 -> V_94 ;
V_16 -> V_31 = & V_95 [ type ] ;
F_59 ( & V_16 -> V_54 ) ;
if ( F_60 ( V_86 -> V_2 . V_93 ,
L_7 , & V_11 ) < 0 ) {
struct V_96 * V_97 =
F_61 ( & V_86 -> V_2 ) ;
if ( V_97 )
V_11 = V_97 -> V_98 ;
else
V_11 = V_99 ;
}
V_14 = F_32 ( V_16 , V_11 ) ;
if ( V_14 )
return V_14 ;
V_11 = V_16 -> V_31 -> V_100 ;
if ( V_82 -> V_94 == V_57 ) {
F_9 ( V_16 , V_101 , & V_11 ) ;
F_13 ( V_16 , V_102 , & V_11 ) ;
F_15 ( V_16 , V_102 , & V_11 ) ;
} else {
V_16 -> V_24 = 1 ;
F_18 ( V_16 , V_103 , & V_11 ) ;
F_20 ( V_16 , V_103 , & V_11 ) ;
}
V_14 = F_50 ( V_16 , V_11 ) ;
if ( V_14 ) {
F_56 ( & V_86 -> V_2 , L_8 ) ;
return V_14 ;
}
V_8 -> V_104 = V_105 | V_106 ;
V_8 -> V_2 . V_107 = & V_86 -> V_2 ;
V_8 -> V_2 . V_93 = V_86 -> V_2 . V_93 ;
if ( V_82 -> V_94 == V_57 ) {
V_8 -> V_108 = V_109 ;
V_8 -> V_110 = F_11 ( V_109 ) ;
V_8 -> V_111 = & V_112 ;
} else {
V_8 -> V_108 = V_113 ;
V_8 -> V_110 = F_11 ( V_113 ) ;
V_8 -> V_111 = & V_114 ;
}
V_8 -> V_81 = V_82 -> V_81 ;
V_8 -> V_115 = & V_116 ;
V_89 = F_62 ( & V_8 -> V_2 ) ;
if ( ! V_89 )
return - V_91 ;
F_63 ( V_8 , V_89 ) ;
return F_64 ( V_8 ) ;
}
static int F_65 ( struct V_85 * V_86 )
{
struct V_7 * V_8 = F_66 ( V_86 ) ;
struct V_15 * V_16 = F_5 ( V_8 ) ;
F_67 ( V_8 ) ;
return F_68 ( V_16 -> V_19 , V_4 ,
V_117 , 0 ) ;
}
