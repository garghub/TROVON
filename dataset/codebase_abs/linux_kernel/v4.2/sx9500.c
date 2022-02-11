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
switch ( V_7 -> type ) {
case V_40 :
switch ( V_39 ) {
case V_41 :
if ( F_26 ( V_38 ) )
return - V_42 ;
return F_18 ( V_2 , V_7 , V_17 ) ;
case V_43 :
return F_23 ( V_2 , V_17 , V_34 ) ;
default:
return - V_44 ;
}
default:
return - V_44 ;
}
}
static int F_27 ( struct V_1 * V_2 ,
int V_17 , int V_34 )
{
int V_45 , V_18 ;
for ( V_45 = 0 ; V_45 < F_28 ( V_35 ) ; V_45 ++ )
if ( V_17 == V_35 [ V_45 ] . V_17 &&
V_34 == V_35 [ V_45 ] . V_34 )
break;
if ( V_45 == F_28 ( V_35 ) )
return - V_44 ;
F_19 ( & V_2 -> V_27 ) ;
V_18 = F_2 ( V_2 -> V_6 , V_9 ,
V_24 ,
V_45 << V_25 ) ;
F_20 ( & V_2 -> V_27 ) ;
return V_18 ;
}
static int F_29 ( struct V_37 * V_38 ,
const struct V_16 * V_7 ,
int V_17 , int V_34 , long V_39 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
switch ( V_7 -> type ) {
case V_40 :
switch ( V_39 ) {
case V_43 :
return F_27 ( V_2 , V_17 , V_34 ) ;
default:
return - V_44 ;
}
default:
return - V_44 ;
}
}
static T_2 F_30 ( int V_31 , void * V_46 )
{
struct V_37 * V_38 = V_46 ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
if ( V_2 -> V_47 )
F_31 ( V_2 -> V_48 ) ;
return V_49 ;
}
static void F_32 ( struct V_37 * V_38 )
{
int V_18 ;
unsigned int V_17 , V_7 ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
V_18 = F_16 ( V_2 -> V_6 , V_50 , & V_17 ) ;
if ( V_18 < 0 ) {
F_33 ( & V_2 -> V_30 -> V_51 , L_1 ) ;
return;
}
V_17 >>= V_52 ;
for ( V_7 = 0 ; V_7 < V_53 ; V_7 ++ ) {
int V_54 ;
T_3 V_55 ;
bool V_56 = V_17 & F_5 ( V_7 ) ;
if ( ! V_2 -> V_57 [ V_7 ] )
continue;
if ( V_56 == V_2 -> V_58 [ V_7 ] )
continue;
V_54 = V_56 ? V_59 : V_60 ;
V_55 = F_34 ( V_40 , V_7 ,
V_61 , V_54 ) ;
F_35 ( V_38 , V_55 , F_36 () ) ;
V_2 -> V_58 [ V_7 ] = V_56 ;
}
}
static T_2 F_37 ( int V_31 , void * V_46 )
{
struct V_37 * V_38 = V_46 ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 ;
unsigned int V_17 ;
F_19 ( & V_2 -> V_27 ) ;
V_18 = F_16 ( V_2 -> V_6 , V_62 , & V_17 ) ;
if ( V_18 < 0 ) {
F_33 ( & V_2 -> V_30 -> V_51 , L_1 ) ;
goto V_28;
}
if ( V_17 & ( V_14 | V_15 ) )
F_32 ( V_38 ) ;
if ( V_17 & V_12 )
F_38 ( & V_2 -> V_32 ) ;
V_28:
F_20 ( & V_2 -> V_27 ) ;
return V_63 ;
}
static int F_39 ( struct V_37 * V_38 ,
const struct V_16 * V_7 ,
enum V_64 type ,
enum V_65 V_54 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
if ( V_7 -> type != V_40 || type != V_61 ||
V_54 != V_66 )
return - V_44 ;
return V_2 -> V_57 [ V_7 -> V_21 ] ;
}
static int F_40 ( struct V_37 * V_38 ,
const struct V_16 * V_7 ,
enum V_64 type ,
enum V_65 V_54 ,
int V_67 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 ;
if ( V_7 -> type != V_40 || type != V_61 ||
V_54 != V_66 )
return - V_44 ;
F_19 ( & V_2 -> V_27 ) ;
if ( V_67 == 1 ) {
V_18 = F_4 ( V_2 , V_7 -> V_21 ) ;
if ( V_18 < 0 )
goto V_68;
V_18 = F_9 ( V_2 ) ;
if ( V_18 < 0 )
goto V_69;
} else {
V_18 = F_6 ( V_2 , V_7 -> V_21 ) ;
if ( V_18 < 0 )
goto V_68;
V_18 = F_10 ( V_2 ) ;
if ( V_18 < 0 )
goto V_69;
}
V_2 -> V_57 [ V_7 -> V_21 ] = V_67 ;
goto V_68;
V_69:
if ( V_67 == 1 )
F_6 ( V_2 , V_7 -> V_21 ) ;
else
F_4 ( V_2 , V_7 -> V_21 ) ;
V_68:
F_20 ( & V_2 -> V_27 ) ;
return V_18 ;
}
static int F_41 ( struct V_37 * V_38 ,
const unsigned long * V_70 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
F_19 ( & V_2 -> V_27 ) ;
F_42 ( V_2 -> V_71 ) ;
V_2 -> V_71 = F_43 ( V_38 -> V_72 , V_73 ) ;
F_20 ( & V_2 -> V_27 ) ;
if ( V_2 -> V_71 == NULL )
return - V_74 ;
return 0 ;
}
static int F_44 ( struct V_75 * V_48 ,
bool V_67 )
{
struct V_37 * V_38 = F_45 ( V_48 ) ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 ;
F_19 ( & V_2 -> V_27 ) ;
if ( V_67 )
V_18 = F_7 ( V_2 ) ;
else
V_18 = F_8 ( V_2 ) ;
if ( V_18 < 0 )
goto V_28;
V_2 -> V_47 = V_67 ;
V_28:
F_20 ( & V_2 -> V_27 ) ;
return V_18 ;
}
static T_2 F_46 ( int V_31 , void * V_46 )
{
struct V_76 * V_77 = V_46 ;
struct V_37 * V_38 = V_77 -> V_38 ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_17 , V_78 , V_18 , V_45 = 0 ;
F_19 ( & V_2 -> V_27 ) ;
F_47 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_18 = F_11 ( V_2 , & V_38 -> V_79 [ V_78 ] ,
& V_17 ) ;
if ( V_18 < 0 )
goto V_28;
V_2 -> V_71 [ V_45 ++ ] = V_17 ;
}
F_48 ( V_38 , V_2 -> V_71 ,
F_36 () ) ;
V_28:
F_20 ( & V_2 -> V_27 ) ;
F_49 ( V_38 -> V_48 ) ;
return V_63 ;
}
static int F_50 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 = 0 , V_45 ;
F_19 ( & V_2 -> V_27 ) ;
for ( V_45 = 0 ; V_45 < V_53 ; V_45 ++ )
if ( F_51 ( V_45 , V_38 -> V_80 ) ) {
V_18 = F_4 ( V_2 , V_45 ) ;
if ( V_18 )
break;
}
if ( V_18 )
for ( V_45 = V_45 - 1 ; V_45 >= 0 ; V_45 -- )
if ( F_51 ( V_45 , V_38 -> V_80 ) )
F_6 ( V_2 , V_45 ) ;
F_20 ( & V_2 -> V_27 ) ;
return V_18 ;
}
static int F_52 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 = 0 , V_45 ;
F_53 ( V_38 ) ;
F_19 ( & V_2 -> V_27 ) ;
for ( V_45 = 0 ; V_45 < V_53 ; V_45 ++ )
if ( F_51 ( V_45 , V_38 -> V_80 ) ) {
V_18 = F_6 ( V_2 , V_45 ) ;
if ( V_18 )
break;
}
if ( V_18 )
for ( V_45 = V_45 - 1 ; V_45 >= 0 ; V_45 -- )
if ( F_51 ( V_45 , V_38 -> V_80 ) )
F_4 ( V_2 , V_45 ) ;
F_20 ( & V_2 -> V_27 ) ;
return V_18 ;
}
static int F_54 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_45 , V_18 ;
unsigned int V_17 ;
V_18 = F_2 ( V_2 -> V_6 , V_9 ,
V_81 , V_81 ) ;
if ( V_18 < 0 )
return V_18 ;
for ( V_45 = 10 ; V_45 >= 0 ; V_45 -- ) {
F_55 ( 10000 , 20000 ) ;
V_18 = F_16 ( V_2 -> V_6 , V_50 , & V_17 ) ;
if ( V_18 < 0 )
goto V_28;
if ( ! ( V_17 & V_82 ) )
break;
}
if ( V_45 < 0 ) {
F_33 ( & V_2 -> V_30 -> V_51 , L_2 ) ;
V_18 = - V_83 ;
}
V_28:
F_2 ( V_2 -> V_6 , V_9 ,
V_81 , 0 ) ;
return V_18 ;
}
static int F_56 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 , V_45 ;
unsigned int V_17 ;
if ( V_2 -> V_84 ) {
F_57 ( V_2 -> V_84 , 0 ) ;
F_55 ( 1000 , 2000 ) ;
F_57 ( V_2 -> V_84 , 1 ) ;
F_55 ( 1000 , 2000 ) ;
}
V_18 = F_12 ( V_2 -> V_6 , V_11 , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_12 ( V_2 -> V_6 , V_85 ,
V_86 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_16 ( V_2 -> V_6 , V_62 , & V_17 ) ;
if ( V_18 < 0 )
return V_18 ;
for ( V_45 = 0 ; V_45 < F_28 ( V_87 ) ; V_45 ++ ) {
V_18 = F_12 ( V_2 -> V_6 ,
V_87 [ V_45 ] . V_4 ,
V_87 [ V_45 ] . V_88 ) ;
if ( V_18 < 0 )
return V_18 ;
}
return F_54 ( V_38 ) ;
}
static void F_58 ( struct V_89 * V_30 ,
struct V_1 * V_2 )
{
struct V_90 * V_51 ;
struct V_91 * V_92 ;
if ( ! V_30 )
return;
V_51 = & V_30 -> V_51 ;
if ( V_30 -> V_31 <= 0 ) {
V_92 = F_59 ( V_51 , V_93 , 0 , V_94 ) ;
if ( F_60 ( V_92 ) )
F_33 ( V_51 , L_3 ) ;
else
V_30 -> V_31 = F_61 ( V_92 ) ;
}
V_2 -> V_84 = F_59 ( V_51 , V_95 ,
0 , V_96 ) ;
if ( F_60 ( V_2 -> V_84 ) ) {
F_62 ( V_51 , L_4 ) ;
V_2 -> V_84 = NULL ;
}
}
static int F_63 ( struct V_89 * V_30 ,
const struct V_97 * V_98 )
{
int V_18 ;
struct V_37 * V_38 ;
struct V_1 * V_2 ;
V_38 = F_64 ( & V_30 -> V_51 , sizeof( * V_2 ) ) ;
if ( V_38 == NULL )
return - V_74 ;
V_2 = F_25 ( V_38 ) ;
V_2 -> V_30 = V_30 ;
F_65 ( & V_2 -> V_27 ) ;
F_66 ( & V_2 -> V_32 ) ;
V_2 -> V_47 = false ;
V_2 -> V_6 = F_67 ( V_30 , & V_99 ) ;
if ( F_60 ( V_2 -> V_6 ) )
return F_68 ( V_2 -> V_6 ) ;
V_38 -> V_51 . V_100 = & V_30 -> V_51 ;
V_38 -> V_101 = V_102 ;
V_38 -> V_79 = V_103 ;
V_38 -> V_104 = F_28 ( V_103 ) ;
V_38 -> V_105 = & V_106 ;
V_38 -> V_107 = V_108 ;
F_69 ( V_30 , V_38 ) ;
F_58 ( V_30 , V_2 ) ;
V_18 = F_56 ( V_38 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_30 -> V_31 <= 0 )
F_62 ( & V_30 -> V_51 , L_5 ) ;
else {
V_18 = F_70 ( & V_30 -> V_51 , V_30 -> V_31 ,
F_30 , F_37 ,
V_109 | V_110 ,
V_111 , V_38 ) ;
if ( V_18 < 0 )
return V_18 ;
V_2 -> V_48 = F_71 ( & V_30 -> V_51 ,
L_6 , V_38 -> V_101 , V_38 -> V_98 ) ;
if ( ! V_2 -> V_48 )
return - V_74 ;
V_2 -> V_48 -> V_51 . V_100 = & V_30 -> V_51 ;
V_2 -> V_48 -> V_112 = & V_113 ;
F_72 ( V_2 -> V_48 , V_38 ) ;
V_18 = F_73 ( V_2 -> V_48 ) ;
if ( V_18 )
return V_18 ;
}
V_18 = F_74 ( V_38 , NULL ,
F_46 ,
& V_114 ) ;
if ( V_18 < 0 )
goto V_115;
V_18 = F_75 ( V_38 ) ;
if ( V_18 < 0 )
goto V_116;
return 0 ;
V_116:
F_76 ( V_38 ) ;
V_115:
if ( V_30 -> V_31 > 0 )
F_77 ( V_2 -> V_48 ) ;
return V_18 ;
}
static int F_78 ( struct V_89 * V_30 )
{
struct V_37 * V_38 = F_79 ( V_30 ) ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
F_80 ( V_38 ) ;
F_76 ( V_38 ) ;
if ( V_30 -> V_31 > 0 )
F_77 ( V_2 -> V_48 ) ;
F_42 ( V_2 -> V_71 ) ;
return 0 ;
}
static int F_81 ( struct V_90 * V_51 )
{
struct V_37 * V_38 = F_79 ( F_82 ( V_51 ) ) ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 ;
F_19 ( & V_2 -> V_27 ) ;
V_18 = F_16 ( V_2 -> V_6 , V_9 ,
& V_2 -> V_117 ) ;
if ( V_18 < 0 )
goto V_28;
V_18 = F_12 ( V_2 -> V_6 , V_9 , 0 ) ;
V_28:
F_20 ( & V_2 -> V_27 ) ;
return V_18 ;
}
static int F_83 ( struct V_90 * V_51 )
{
struct V_37 * V_38 = F_79 ( F_82 ( V_51 ) ) ;
struct V_1 * V_2 = F_25 ( V_38 ) ;
int V_18 ;
F_19 ( & V_2 -> V_27 ) ;
V_18 = F_12 ( V_2 -> V_6 , V_9 ,
V_2 -> V_117 ) ;
F_20 ( & V_2 -> V_27 ) ;
return V_18 ;
}
