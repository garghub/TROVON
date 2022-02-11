static int F_1 ( struct V_1 * V_2 , int * V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
( * V_3 ) ++ ;
if ( * V_3 != 1 )
return 0 ;
return F_2 ( V_2 -> V_6 , V_4 , V_5 , V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 , int * V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
( * V_3 ) -- ;
if ( * V_3 != 0 )
return 0 ;
return F_2 ( V_2 -> V_6 , V_4 , V_5 , 0 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_7 )
{
return F_1 ( V_2 , & V_2 -> V_8 [ V_7 ] ,
V_9 , F_5 ( V_7 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_7 )
{
return F_3 ( V_2 , & V_2 -> V_8 [ V_7 ] ,
V_9 , F_5 ( V_7 ) ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , & V_2 -> V_10 ,
V_11 , V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , & V_2 -> V_10 ,
V_11 , V_12 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , & V_2 -> V_13 ,
V_11 ,
V_14 | V_15 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , & V_2 -> V_13 ,
V_11 ,
V_14 | V_15 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
const struct V_16 * V_7 ,
int * V_17 )
{
int V_18 ;
T_1 V_19 ;
V_18 = F_12 ( V_2 -> V_6 , V_20 , V_7 -> V_21 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_13 ( V_2 -> V_6 , V_22 , & V_19 , 2 ) ;
if ( V_18 < 0 )
return V_18 ;
* V_17 = F_14 ( V_19 ) ;
return V_23 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_18 ;
unsigned int V_17 ;
V_18 = F_16 ( V_2 -> V_6 , V_9 , & V_17 ) ;
if ( V_18 < 0 )
return V_18 ;
V_17 = ( V_17 & V_24 ) >> V_25 ;
F_17 ( V_26 [ V_17 ] ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_16 * V_7 ,
int * V_17 )
{
int V_18 ;
F_19 ( & V_2 -> V_27 ) ;
V_18 = F_4 ( V_2 , V_7 -> V_21 ) ;
if ( V_18 < 0 )
goto V_28;
V_18 = F_7 ( V_2 ) ;
if ( V_18 < 0 )
goto V_29;
F_20 ( & V_2 -> V_27 ) ;
if ( V_2 -> V_30 -> V_31 > 0 )
V_18 = F_21 ( & V_2 -> V_32 ) ;
else
V_18 = F_15 ( V_2 ) ;
F_19 ( & V_2 -> V_27 ) ;
if ( V_18 < 0 )
goto V_33;
V_18 = F_11 ( V_2 , V_7 , V_17 ) ;
if ( V_18 < 0 )
goto V_33;
V_18 = F_8 ( V_2 ) ;
if ( V_18 < 0 )
goto V_29;
V_18 = F_6 ( V_2 , V_7 -> V_21 ) ;
if ( V_18 < 0 )
goto V_28;
V_18 = V_23 ;
goto V_28;
V_33:
F_8 ( V_2 ) ;
V_29:
F_6 ( V_2 , V_7 -> V_21 ) ;
V_28:
F_20 ( & V_2 -> V_27 ) ;
F_22 ( & V_2 -> V_32 ) ;
return V_18 ;
}
static int F_23 ( struct V_1 * V_2 ,
int * V_17 , int * V_34 )
{
int V_18 ;
unsigned int V_19 ;
F_19 ( & V_2 -> V_27 ) ;
V_18 = F_16 ( V_2 -> V_6 , V_9 , & V_19 ) ;
F_20 ( & V_2 -> V_27 ) ;
if ( V_18 < 0 )
return V_18 ;
V_19 = ( V_19 & V_24 ) >> V_25 ;
* V_17 = V_35 [ V_19 ] . V_17 ;
* V_34 = V_35 [ V_19 ] . V_34 ;
return V_36 ;
}
static int F_24 ( struct V_37 * V_38 ,
const struct V_16 * V_7 ,
int * V_17 , int * V_34 , long V_39 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 ;
switch ( V_7 -> type ) {
case V_40 :
switch ( V_39 ) {
case V_41 :
V_18 = F_26 ( V_38 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_18 ( V_2 , V_7 , V_17 ) ;
F_27 ( V_38 ) ;
return V_18 ;
case V_42 :
return F_23 ( V_2 , V_17 , V_34 ) ;
default:
return - V_43 ;
}
default:
return - V_43 ;
}
}
static int F_28 ( struct V_1 * V_2 ,
int V_17 , int V_34 )
{
int V_44 , V_18 ;
for ( V_44 = 0 ; V_44 < F_29 ( V_35 ) ; V_44 ++ )
if ( V_17 == V_35 [ V_44 ] . V_17 &&
V_34 == V_35 [ V_44 ] . V_34 )
break;
if ( V_44 == F_29 ( V_35 ) )
return - V_43 ;
F_19 ( & V_2 -> V_27 ) ;
V_18 = F_2 ( V_2 -> V_6 , V_9 ,
V_24 ,
V_44 << V_25 ) ;
F_20 ( & V_2 -> V_27 ) ;
return V_18 ;
}
static int F_30 ( struct V_37 * V_38 ,
const struct V_16 * V_7 ,
int V_17 , int V_34 , long V_39 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
switch ( V_7 -> type ) {
case V_40 :
switch ( V_39 ) {
case V_42 :
return F_28 ( V_2 , V_17 , V_34 ) ;
default:
return - V_43 ;
}
default:
return - V_43 ;
}
}
static T_2 F_31 ( int V_31 , void * V_45 )
{
struct V_37 * V_38 = V_45 ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
if ( V_2 -> V_46 )
F_32 ( V_2 -> V_47 ) ;
return V_48 ;
}
static void F_33 ( struct V_37 * V_38 )
{
int V_18 ;
unsigned int V_17 , V_7 ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
V_18 = F_16 ( V_2 -> V_6 , V_49 , & V_17 ) ;
if ( V_18 < 0 ) {
F_34 ( & V_2 -> V_30 -> V_50 , L_1 ) ;
return;
}
V_17 >>= V_51 ;
for ( V_7 = 0 ; V_7 < V_52 ; V_7 ++ ) {
int V_53 ;
T_3 V_54 ;
bool V_55 = V_17 & F_5 ( V_7 ) ;
if ( ! V_2 -> V_56 [ V_7 ] )
continue;
if ( V_55 == V_2 -> V_57 [ V_7 ] )
continue;
V_53 = V_55 ? V_58 : V_59 ;
V_54 = F_35 ( V_40 , V_7 ,
V_60 , V_53 ) ;
F_36 ( V_38 , V_54 , F_37 ( V_38 ) ) ;
V_2 -> V_57 [ V_7 ] = V_55 ;
}
}
static T_2 F_38 ( int V_31 , void * V_45 )
{
struct V_37 * V_38 = V_45 ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 ;
unsigned int V_17 ;
F_19 ( & V_2 -> V_27 ) ;
V_18 = F_16 ( V_2 -> V_6 , V_61 , & V_17 ) ;
if ( V_18 < 0 ) {
F_34 ( & V_2 -> V_30 -> V_50 , L_1 ) ;
goto V_28;
}
if ( V_17 & ( V_14 | V_15 ) )
F_33 ( V_38 ) ;
if ( V_17 & V_12 )
F_39 ( & V_2 -> V_32 ) ;
V_28:
F_20 ( & V_2 -> V_27 ) ;
return V_62 ;
}
static int F_40 ( struct V_37 * V_38 ,
const struct V_16 * V_7 ,
enum V_63 type ,
enum V_64 V_53 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
if ( V_7 -> type != V_40 || type != V_60 ||
V_53 != V_65 )
return - V_43 ;
return V_2 -> V_56 [ V_7 -> V_21 ] ;
}
static int F_41 ( struct V_37 * V_38 ,
const struct V_16 * V_7 ,
enum V_63 type ,
enum V_64 V_53 ,
int V_66 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 ;
if ( V_7 -> type != V_40 || type != V_60 ||
V_53 != V_65 )
return - V_43 ;
F_19 ( & V_2 -> V_27 ) ;
if ( V_66 == 1 ) {
V_18 = F_4 ( V_2 , V_7 -> V_21 ) ;
if ( V_18 < 0 )
goto V_67;
V_18 = F_9 ( V_2 ) ;
if ( V_18 < 0 )
goto V_68;
} else {
V_18 = F_6 ( V_2 , V_7 -> V_21 ) ;
if ( V_18 < 0 )
goto V_67;
V_18 = F_10 ( V_2 ) ;
if ( V_18 < 0 )
goto V_68;
}
V_2 -> V_56 [ V_7 -> V_21 ] = V_66 ;
goto V_67;
V_68:
if ( V_66 == 1 )
F_6 ( V_2 , V_7 -> V_21 ) ;
else
F_4 ( V_2 , V_7 -> V_21 ) ;
V_67:
F_20 ( & V_2 -> V_27 ) ;
return V_18 ;
}
static int F_42 ( struct V_37 * V_38 ,
const unsigned long * V_69 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
F_19 ( & V_2 -> V_27 ) ;
F_43 ( V_2 -> V_70 ) ;
V_2 -> V_70 = F_44 ( V_38 -> V_71 , V_72 ) ;
F_20 ( & V_2 -> V_27 ) ;
if ( V_2 -> V_70 == NULL )
return - V_73 ;
return 0 ;
}
static int F_45 ( struct V_74 * V_47 ,
bool V_66 )
{
struct V_37 * V_38 = F_46 ( V_47 ) ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 ;
F_19 ( & V_2 -> V_27 ) ;
if ( V_66 )
V_18 = F_7 ( V_2 ) ;
else
V_18 = F_8 ( V_2 ) ;
if ( V_18 < 0 )
goto V_28;
V_2 -> V_46 = V_66 ;
V_28:
F_20 ( & V_2 -> V_27 ) ;
return V_18 ;
}
static T_2 F_47 ( int V_31 , void * V_45 )
{
struct V_75 * V_76 = V_45 ;
struct V_37 * V_38 = V_76 -> V_38 ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_17 , V_77 , V_18 , V_44 = 0 ;
F_19 ( & V_2 -> V_27 ) ;
F_48 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_18 = F_11 ( V_2 , & V_38 -> V_78 [ V_77 ] ,
& V_17 ) ;
if ( V_18 < 0 )
goto V_28;
V_2 -> V_70 [ V_44 ++ ] = V_17 ;
}
F_49 ( V_38 , V_2 -> V_70 ,
F_37 ( V_38 ) ) ;
V_28:
F_20 ( & V_2 -> V_27 ) ;
F_50 ( V_38 -> V_47 ) ;
return V_62 ;
}
static int F_51 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 = 0 , V_44 ;
F_19 ( & V_2 -> V_27 ) ;
for ( V_44 = 0 ; V_44 < V_52 ; V_44 ++ )
if ( F_52 ( V_44 , V_38 -> V_79 ) ) {
V_18 = F_4 ( V_2 , V_44 ) ;
if ( V_18 )
break;
}
if ( V_18 )
for ( V_44 = V_44 - 1 ; V_44 >= 0 ; V_44 -- )
if ( F_52 ( V_44 , V_38 -> V_79 ) )
F_6 ( V_2 , V_44 ) ;
F_20 ( & V_2 -> V_27 ) ;
return V_18 ;
}
static int F_53 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 = 0 , V_44 ;
F_54 ( V_38 ) ;
F_19 ( & V_2 -> V_27 ) ;
for ( V_44 = 0 ; V_44 < V_52 ; V_44 ++ )
if ( F_52 ( V_44 , V_38 -> V_79 ) ) {
V_18 = F_6 ( V_2 , V_44 ) ;
if ( V_18 )
break;
}
if ( V_18 )
for ( V_44 = V_44 - 1 ; V_44 >= 0 ; V_44 -- )
if ( F_52 ( V_44 , V_38 -> V_79 ) )
F_4 ( V_2 , V_44 ) ;
F_20 ( & V_2 -> V_27 ) ;
return V_18 ;
}
static int F_55 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_44 , V_18 ;
unsigned int V_17 ;
V_18 = F_2 ( V_2 -> V_6 , V_9 ,
V_80 , V_80 ) ;
if ( V_18 < 0 )
return V_18 ;
for ( V_44 = 10 ; V_44 >= 0 ; V_44 -- ) {
F_56 ( 10000 , 20000 ) ;
V_18 = F_16 ( V_2 -> V_6 , V_49 , & V_17 ) ;
if ( V_18 < 0 )
goto V_28;
if ( ! ( V_17 & V_81 ) )
break;
}
if ( V_44 < 0 ) {
F_34 ( & V_2 -> V_30 -> V_50 , L_2 ) ;
V_18 = - V_82 ;
}
V_28:
F_2 ( V_2 -> V_6 , V_9 ,
V_80 , 0 ) ;
return V_18 ;
}
static int F_57 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 , V_44 ;
unsigned int V_17 ;
if ( V_2 -> V_83 ) {
F_58 ( V_2 -> V_83 , 0 ) ;
F_56 ( 1000 , 2000 ) ;
F_58 ( V_2 -> V_83 , 1 ) ;
F_56 ( 1000 , 2000 ) ;
}
V_18 = F_12 ( V_2 -> V_6 , V_11 , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_12 ( V_2 -> V_6 , V_84 ,
V_85 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_16 ( V_2 -> V_6 , V_61 , & V_17 ) ;
if ( V_18 < 0 )
return V_18 ;
for ( V_44 = 0 ; V_44 < F_29 ( V_86 ) ; V_44 ++ ) {
V_18 = F_12 ( V_2 -> V_6 ,
V_86 [ V_44 ] . V_4 ,
V_86 [ V_44 ] . V_87 ) ;
if ( V_18 < 0 )
return V_18 ;
}
return F_55 ( V_38 ) ;
}
static void F_59 ( struct V_88 * V_30 ,
struct V_1 * V_2 )
{
struct V_89 * V_50 ;
if ( ! V_30 )
return;
V_50 = & V_30 -> V_50 ;
V_2 -> V_83 = F_60 ( V_50 , V_90 ,
0 , V_91 ) ;
if ( F_61 ( V_2 -> V_83 ) ) {
F_62 ( V_50 , L_3 ) ;
V_2 -> V_83 = NULL ;
}
}
static int F_63 ( struct V_88 * V_30 ,
const struct V_92 * V_93 )
{
int V_18 ;
struct V_37 * V_38 ;
struct V_1 * V_2 ;
V_38 = F_64 ( & V_30 -> V_50 , sizeof( * V_2 ) ) ;
if ( V_38 == NULL )
return - V_73 ;
V_2 = F_25 ( V_38 ) ;
V_2 -> V_30 = V_30 ;
F_65 ( & V_2 -> V_27 ) ;
F_66 ( & V_2 -> V_32 ) ;
V_2 -> V_46 = false ;
V_2 -> V_6 = F_67 ( V_30 , & V_94 ) ;
if ( F_61 ( V_2 -> V_6 ) )
return F_68 ( V_2 -> V_6 ) ;
V_38 -> V_50 . V_95 = & V_30 -> V_50 ;
V_38 -> V_96 = V_97 ;
V_38 -> V_78 = V_98 ;
V_38 -> V_99 = F_29 ( V_98 ) ;
V_38 -> V_100 = & V_101 ;
V_38 -> V_102 = V_103 ;
F_69 ( V_30 , V_38 ) ;
F_59 ( V_30 , V_2 ) ;
V_18 = F_57 ( V_38 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_30 -> V_31 <= 0 )
F_62 ( & V_30 -> V_50 , L_4 ) ;
else {
V_18 = F_70 ( & V_30 -> V_50 , V_30 -> V_31 ,
F_31 , F_38 ,
V_104 | V_105 ,
V_106 , V_38 ) ;
if ( V_18 < 0 )
return V_18 ;
V_2 -> V_47 = F_71 ( & V_30 -> V_50 ,
L_5 , V_38 -> V_96 , V_38 -> V_93 ) ;
if ( ! V_2 -> V_47 )
return - V_73 ;
V_2 -> V_47 -> V_50 . V_95 = & V_30 -> V_50 ;
V_2 -> V_47 -> V_107 = & V_108 ;
F_72 ( V_2 -> V_47 , V_38 ) ;
V_18 = F_73 ( V_2 -> V_47 ) ;
if ( V_18 )
return V_18 ;
}
V_18 = F_74 ( V_38 , NULL ,
F_47 ,
& V_109 ) ;
if ( V_18 < 0 )
goto V_110;
V_18 = F_75 ( V_38 ) ;
if ( V_18 < 0 )
goto V_111;
return 0 ;
V_111:
F_76 ( V_38 ) ;
V_110:
if ( V_30 -> V_31 > 0 )
F_77 ( V_2 -> V_47 ) ;
return V_18 ;
}
static int F_78 ( struct V_88 * V_30 )
{
struct V_37 * V_38 = F_79 ( V_30 ) ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
F_80 ( V_38 ) ;
F_76 ( V_38 ) ;
if ( V_30 -> V_31 > 0 )
F_77 ( V_2 -> V_47 ) ;
F_43 ( V_2 -> V_70 ) ;
return 0 ;
}
static int F_81 ( struct V_89 * V_50 )
{
struct V_37 * V_38 = F_79 ( F_82 ( V_50 ) ) ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 ;
F_19 ( & V_2 -> V_27 ) ;
V_18 = F_16 ( V_2 -> V_6 , V_9 ,
& V_2 -> V_112 ) ;
if ( V_18 < 0 )
goto V_28;
V_18 = F_12 ( V_2 -> V_6 , V_9 , 0 ) ;
V_28:
F_20 ( & V_2 -> V_27 ) ;
return V_18 ;
}
static int F_83 ( struct V_89 * V_50 )
{
struct V_37 * V_38 = F_79 ( F_82 ( V_50 ) ) ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 ;
F_19 ( & V_2 -> V_27 ) ;
V_18 = F_12 ( V_2 -> V_6 , V_9 ,
V_2 -> V_112 ) ;
F_20 ( & V_2 -> V_27 ) ;
return V_18 ;
}
