static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ?
& V_2 -> V_9 [ V_2 -> V_8 - 1 ] : NULL ;
if ( V_7 && V_7 -> V_10 + V_7 -> V_5 == V_3 &&
V_7 -> V_11 + V_7 -> V_5 == V_4 ) {
V_7 -> V_5 += V_5 ;
} else if ( V_2 -> V_8 < V_12 ) {
V_7 = & V_2 -> V_9 [ V_2 -> V_8 ++ ] ;
V_7 -> V_10 = V_3 ;
V_7 -> V_11 = V_4 ;
V_7 -> V_5 = V_5 ;
}
}
static void F_2 ( struct V_1 * V_2 )
{
int V_13 = - 1 , V_14 ;
unsigned int V_3 = 0 , V_4 = 0 ;
struct V_15 * V_16 = F_3 ( V_2 -> V_17 ) ;
V_2 -> V_8 = 0 ;
if ( V_16 -> V_18 &&
( * V_16 -> V_19 & 0xff ) == 0xff ) {
F_1 ( V_2 , 0 , 0 , 16 ) ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
return;
}
F_4 (out_ind,
indio_dev->active_scan_mask,
indio_dev->masklength) {
if ( V_14 == V_12 )
break;
for ( ++ V_13 ; V_13 != V_14 ; ++ V_13 )
V_3 += 2 ;
F_1 ( V_2 , V_3 , V_4 , 2 ) ;
V_4 += 2 ;
V_3 += 2 ;
}
if ( V_16 -> V_22 ) {
T_1 V_23 = V_16 -> V_24 / sizeof( V_25 ) - 1 ;
V_2 -> V_20 = V_4 ;
V_2 -> V_21 = V_23 * sizeof( V_25 ) - V_4 ;
} else {
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
}
}
static int F_5 ( struct V_1 * V_2 )
{
int V_26 ;
T_2 V_27 = V_2 -> V_27 ;
T_2 V_28 ;
int V_29 = sizeof( V_28 ) ;
V_26 = F_6 ( V_2 -> V_17 , V_30 ,
& V_27 , sizeof( V_27 ) , & V_28 , & V_29 ) ;
if ( V_26 < 0 ) {
F_7 ( & V_2 -> V_17 -> V_31 , L_1 , V_32 ) ;
return V_26 ;
}
if ( V_29 < sizeof( V_28 ) )
return - V_33 ;
return V_28 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_34 V_35 = {
. V_27 = V_2 -> V_27 ,
. V_36 = V_37 ,
} ;
V_26 = F_9 ( V_2 -> V_17 , V_38 ,
& V_35 , sizeof( V_35 ) ) ;
if ( V_26 < 0 )
F_7 ( & V_2 -> V_17 -> V_31 , L_1 , V_32 ) ;
return V_26 ;
}
static int F_10 ( struct V_1 * V_2 ,
int V_39 , bool V_40 )
{
int V_26 ;
struct V_34 V_35 = {
. V_27 = V_2 -> V_27 ,
. V_36 = V_39 ,
} ;
T_3 V_41 = V_40 ? V_42 : V_43 ;
V_26 = F_9 ( V_2 -> V_17 , V_41 , & V_35 , sizeof( V_35 ) ) ;
if ( V_26 < 0 )
F_7 ( & V_2 -> V_17 -> V_31 , L_1 , V_32 ) ;
return V_26 ;
}
static int F_11 ( struct V_1 * V_2 , bool V_40 ,
T_3 * V_44 )
{
int V_26 ;
T_2 V_27 = V_2 -> V_27 ;
T_4 V_45 ;
int V_29 = sizeof( V_45 ) ;
T_3 V_41 = V_40 ? V_46 : V_47 ;
if ( V_44 )
* V_44 = 0 ;
V_26 = F_6 ( V_2 -> V_17 , V_41 , & V_27 , sizeof( V_27 ) ,
& V_45 , & V_29 ) ;
if ( V_26 < 0 ) {
F_7 ( & V_2 -> V_17 -> V_31 , L_2 ,
V_32 , ( int ) V_40 ) ;
if ( V_44 && V_40 && V_29 >= sizeof( V_45 ) )
* V_44 = F_12 ( V_45 ) ;
return V_26 ;
}
if ( V_40 && V_29 < sizeof( V_45 ) )
return - V_33 ;
return V_26 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned int V_39 , unsigned int V_48 )
{
int V_26 ;
struct {
struct V_34 V_35 ;
T_5 type ;
T_4 V_48 ;
T_4 V_49 ;
T_4 V_50 ;
} V_51 V_52 = {
. V_35 . V_27 = V_2 -> V_27 ,
. V_35 . V_36 = V_39 ,
. type = V_48 ? V_53 : V_54 ,
. V_48 = F_14 (period)
} ;
V_26 = F_9 ( V_2 -> V_17 , V_55 ,
& V_52 , sizeof( V_52 ) ) ;
if ( V_26 < 0 )
F_7 ( & V_2 -> V_17 -> V_31 , L_1 , V_32 ) ;
return V_26 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_39 )
{
int V_26 , V_56 ;
struct V_15 * V_16 = F_3 ( V_2 -> V_17 ) ;
T_3 V_45 ;
T_4 V_57 ;
int V_29 = sizeof( V_57 ) ;
struct V_34 V_35 = {
. V_27 = V_2 -> V_27 ,
. V_36 = V_39 ,
} ;
V_26 = F_16 ( V_16 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_10 ( V_2 , V_39 , true ) ;
if ( V_26 < 0 )
goto V_58;
V_26 = F_11 ( V_2 , true , & V_45 ) ;
if ( V_26 < 0 ) {
if ( V_45 ) {
F_17 ( & V_2 -> V_17 -> V_31 ,
L_3 ,
( int ) V_45 ) ;
V_26 = - V_59 ;
}
goto V_60;
}
for ( V_56 = 0 ; V_56 < 2 ; ++ V_56 ) {
V_26 = F_6 ( V_2 -> V_17 , V_61 ,
& V_35 , sizeof( V_35 ) ,
& V_57 , & V_29 ) ;
if ( V_26 < 0 ) {
F_7 ( & V_2 -> V_17 -> V_31 , L_1 , V_32 ) ;
goto V_62;
}
if ( V_29 < sizeof( V_57 ) ) {
V_26 = - V_33 ;
goto V_62;
}
}
V_26 = F_12 ( V_57 ) ;
V_62:
F_11 ( V_2 , false , NULL ) ;
V_60:
F_10 ( V_2 , V_39 , false ) ;
V_58:
F_18 ( V_16 ) ;
return V_26 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
int V_26 ;
T_5 V_27 = V_2 -> V_27 ;
int V_29 = sizeof( * V_64 ) ;
V_26 = F_6 ( V_2 -> V_17 , V_65 ,
& V_27 , sizeof( V_27 ) , V_64 , & V_29 ) ;
if ( V_26 < 0 ) {
F_7 ( & V_2 -> V_17 -> V_31 , L_1 , V_32 ) ;
return V_26 ;
}
if ( V_29 < sizeof( * V_64 ) )
return - V_33 ;
return V_26 ;
}
static int F_20 ( struct V_15 * V_16 ,
struct V_66 const * V_36 ,
int * V_67 ,
int * V_68 ,
long V_69 )
{
int V_26 ;
unsigned int V_70 ;
struct V_1 * V_2 = F_21 ( V_16 ) ;
switch ( V_69 ) {
case V_71 :
F_22 ( & V_2 -> V_72 ) ;
V_26 = F_15 ( V_2 , V_36 -> V_39 ) ;
F_23 ( & V_2 -> V_72 ) ;
if ( V_26 < 0 )
return V_26 ;
* V_67 = V_26 ;
return V_73 ;
case V_74 :
* V_67 = 0 ;
* V_68 = 3222656 ;
return V_75 ;
case V_76 :
if ( V_2 -> V_77 ) {
V_70 = 1000000000 / V_2 -> V_77 ;
* V_67 = V_70 / 1000000 ;
* V_68 = V_70 % 1000000 ;
} else {
* V_67 = 0 ;
* V_68 = 0 ;
}
return V_78 ;
default:
return - V_79 ;
}
}
static int F_24 ( struct V_15 * V_16 ,
struct V_66 const * V_36 ,
int V_67 ,
int V_68 ,
long V_69 )
{
int V_26 ;
unsigned int V_70 ;
struct V_1 * V_2 = F_21 ( V_16 ) ;
switch ( V_69 ) {
case V_76 :
V_70 = 1000000 * V_67 + V_68 ;
F_22 ( & V_2 -> V_72 ) ;
V_2 -> V_77 =
V_70 ? 1000000000 / V_70 : V_80 ;
if ( V_2 -> V_77 > 65535 ) {
V_2 -> V_77 = 65535 ;
F_25 ( & V_2 -> V_17 -> V_31 ,
L_4 ) ;
}
if ( V_2 -> V_81 != - 1 )
V_26 = F_13 ( V_2 ,
V_2 -> V_81 , V_2 -> V_77 ) ;
else
V_26 = 0 ;
F_23 ( & V_2 -> V_72 ) ;
return V_26 ;
default:
return - V_79 ;
}
}
static int F_26 ( struct V_15 * V_16 ,
const unsigned long * V_82 )
{
struct V_1 * V_2 = F_21 ( V_16 ) ;
int V_83 = V_16 -> V_84 - 1 ;
int V_26 , V_56 , V_85 ;
F_22 ( & V_2 -> V_72 ) ;
for ( V_56 = 0 ; V_56 < V_83 ; ++ V_56 ) {
V_26 = F_10 ( V_2 , V_56 ,
F_27 ( V_56 , V_82 ) ) ;
if ( V_26 < 0 ) {
for ( V_85 = 0 ; V_85 < V_56 ; ++ V_85 )
F_10 ( V_2 , V_85 , false ) ;
F_23 ( & V_2 -> V_72 ) ;
F_17 ( & V_2 -> V_17 -> V_31 ,
L_5 , V_56 ) ;
return - V_59 ;
}
}
F_2 ( V_2 ) ;
F_23 ( & V_2 -> V_72 ) ;
return 0 ;
}
static T_6 F_28 ( int V_86 , void * V_7 )
{
struct V_87 * V_88 = V_7 ;
struct V_15 * V_16 = V_88 -> V_16 ;
struct {
T_4 V_89 [ V_12 ] ;
V_25 V_90 ;
} V_91 ;
struct V_63 V_92 ;
struct V_1 * V_2 = F_21 ( V_16 ) ;
const struct V_6 * V_93 ;
int V_26 , V_56 ;
F_22 ( & V_2 -> V_72 ) ;
V_26 = F_19 ( V_2 , & V_92 ) ;
F_23 ( & V_2 -> V_72 ) ;
if ( V_26 < 0 )
goto V_94;
for ( V_56 = 0 ; V_56 < V_2 -> V_8 ; ++ V_56 ) {
V_93 = & V_2 -> V_9 [ V_56 ] ;
memcpy ( ( void * ) V_91 . V_89 + V_93 -> V_11 ,
( void * ) V_92 . V_89 + V_93 -> V_10 , V_93 -> V_5 ) ;
}
if ( V_2 -> V_21 )
memset ( ( void * ) V_91 . V_89 + V_2 -> V_20 ,
0 , V_2 -> V_21 ) ;
F_29 ( V_16 , & V_91 ,
F_30 ( V_16 ) ) ;
V_94:
F_31 ( V_16 -> V_95 ) ;
return V_96 ;
}
static int F_32 ( struct V_15 * V_16 )
{
int V_26 ;
struct V_1 * V_2 = F_21 ( V_16 ) ;
T_3 V_45 ;
unsigned int V_81 ;
F_22 ( & V_2 -> V_72 ) ;
V_26 = F_11 ( V_2 , true , & V_45 ) ;
if ( V_26 < 0 ) {
F_23 ( & V_2 -> V_72 ) ;
F_7 ( & V_2 -> V_17 -> V_31 , L_1 , V_32 ) ;
if ( V_45 ) {
F_17 ( & V_2 -> V_17 -> V_31 ,
L_3 ,
( int ) V_45 ) ;
V_26 = - V_59 ;
}
return V_26 ;
}
V_81 = F_33 ( V_16 -> V_19 ,
V_16 -> V_18 ) ;
if ( V_81 < V_12 ) {
V_2 -> V_81 = V_81 ;
V_26 = F_13 ( V_2 , V_2 -> V_81 ,
V_2 -> V_77 ) ;
F_23 ( & V_2 -> V_72 ) ;
if ( V_26 < 0 ) {
F_7 ( & V_2 -> V_17 -> V_31 , L_1 , V_32 ) ;
return V_26 ;
}
} else {
V_2 -> V_81 = - 1 ;
F_23 ( & V_2 -> V_72 ) ;
}
return F_34 ( V_16 ) ;
}
static int F_35 ( struct V_15 * V_16 )
{
int V_26 ;
struct V_1 * V_2 = F_21 ( V_16 ) ;
F_22 ( & V_2 -> V_72 ) ;
if ( V_2 -> V_81 != - 1 ) {
F_13 ( V_2 , V_2 -> V_81 , 0 ) ;
V_2 -> V_81 = - 1 ;
}
V_26 = F_11 ( V_2 , false , NULL ) ;
F_23 ( & V_2 -> V_72 ) ;
if ( V_26 < 0 ) {
F_7 ( & V_2 -> V_17 -> V_31 , L_1 , V_32 ) ;
return V_26 ;
}
return F_36 ( V_16 ) ;
}
static void F_37 ( struct V_97 * V_17 , T_3 V_98 ,
const void * V_91 , int V_99 )
{
struct V_15 * V_16 = F_3 ( V_17 ) ;
struct V_1 * V_2 = F_21 ( V_16 ) ;
F_38 ( V_2 -> V_95 ) ;
}
static int F_39 ( struct V_97 * V_17 )
{
struct V_100 * V_31 = & V_17 -> V_31 ;
struct V_1 * V_2 ;
struct V_101 * V_102 = F_40 ( & V_17 -> V_31 ) ;
struct V_15 * V_16 ;
int V_56 , V_26 , V_103 ;
V_16 = F_41 ( V_31 , sizeof( * V_2 ) ) ;
if ( ! V_16 ) {
F_17 ( V_31 , L_6 ) ;
return - V_104 ;
}
V_2 = F_21 ( V_16 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_27 = V_102 -> V_27 ;
V_2 -> V_81 = - 1 ;
F_42 ( & V_2 -> V_72 ) ;
F_43 ( V_17 , V_16 ) ;
V_26 = F_8 ( V_2 ) ;
if ( V_26 < 0 ) {
F_17 ( V_31 , L_7 ) ;
return V_26 ;
}
V_103 = F_5 ( V_2 ) ;
if ( V_103 < 0 ) {
F_17 ( V_31 , L_8 , V_103 ) ;
return V_103 ;
}
if ( V_103 > V_12 ) {
V_103 = V_12 ;
F_25 ( V_31 , L_9 ,
V_12 ) ;
}
for ( V_56 = 0 ; V_56 < V_103 ; ++ V_56 )
F_44 (dln2->iio_channels[i], i)
F_45 ( V_2 -> V_105 [ V_56 ] , V_56 ) ;
V_16 -> V_106 = V_107 ;
V_16 -> V_31 . V_108 = V_31 ;
V_16 -> V_109 = & V_110 ;
V_16 -> V_111 = V_112 ;
V_16 -> V_113 = V_2 -> V_105 ;
V_16 -> V_84 = V_103 + 1 ;
V_16 -> V_114 = & V_115 ;
V_2 -> V_95 = F_46 ( V_31 , L_10 ,
V_16 -> V_106 , V_16 -> V_116 ) ;
if ( ! V_2 -> V_95 ) {
F_17 ( V_31 , L_11 ) ;
return - V_104 ;
}
V_2 -> V_95 -> V_117 = & V_118 ;
F_47 ( V_2 -> V_95 , V_2 ) ;
F_48 ( V_31 , V_2 -> V_95 ) ;
F_49 ( V_16 , V_2 -> V_95 ) ;
V_26 = F_50 ( V_31 , V_16 , NULL ,
F_28 ,
& V_115 ) ;
if ( V_26 ) {
F_17 ( V_31 , L_12 , V_26 ) ;
return V_26 ;
}
V_26 = F_51 ( V_17 , V_119 ,
F_37 ) ;
if ( V_26 ) {
F_17 ( V_31 , L_13 , V_26 ) ;
return V_26 ;
}
V_26 = F_52 ( V_16 ) ;
if ( V_26 ) {
F_17 ( V_31 , L_14 , V_26 ) ;
goto V_120;
}
return V_26 ;
V_120:
F_53 ( V_17 , V_119 ) ;
return V_26 ;
}
static int F_54 ( struct V_97 * V_17 )
{
struct V_15 * V_16 = F_3 ( V_17 ) ;
F_55 ( V_16 ) ;
F_53 ( V_17 , V_119 ) ;
return 0 ;
}
