static int F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
int V_5 ;
if ( V_2 -> V_6 )
return - V_7 ;
switch ( V_4 ) {
case V_8 :
V_5 = F_2 ( V_2 -> V_9 , V_10 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_9 -> V_11 , L_1 ) ;
break;
default:
V_5 = F_4 ( V_2 -> V_9 ,
V_12 + V_4 * 2 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_9 -> V_11 ,
L_2 ,
'x' + V_4 ) ;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_14 , T_1 V_15 )
{
int V_5 = F_2 ( V_2 -> V_9 , V_13 ) ;
T_1 V_16 = ( V_5 & ~ V_14 ) | ( V_15 << ( F_6 ( V_14 ) - 1 ) ) ;
if ( V_5 < 0 )
return V_5 ;
return F_7 ( V_2 -> V_9 , V_13 , V_16 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_5 = F_5 ( V_2 , V_2 -> V_17 -> V_18 ,
V_2 -> V_17 -> V_19 , 1 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_9 -> V_11 , L_3 ) ;
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 , bool V_20 )
{
int V_5 = F_5 ( V_2 , V_2 -> V_17 -> V_21 ,
V_2 -> V_17 -> V_22 , V_20 ) ;
if ( V_5 )
goto V_23;
V_5 = F_8 ( V_2 ) ;
if ( V_5 )
goto V_23;
return 0 ;
V_23:
F_3 ( & V_2 -> V_9 -> V_11 ,
L_4 , V_20 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 , bool V_20 )
{
int V_5 = F_5 ( V_2 , V_2 -> V_17 -> V_24 ,
V_2 -> V_17 -> V_25 , V_20 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_9 -> V_11 ,
L_5 , V_20 ) ;
return V_5 ;
}
V_2 -> V_6 = V_20 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , bool V_20 )
{
int V_5 = F_5 ( V_2 , V_26 , V_27 , V_20 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_9 -> V_11 ,
L_6 , V_20 ) ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 , int V_15 )
{
int V_5 , V_28 ;
if ( V_2 -> V_6 )
return - V_7 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_17 -> V_29 ; ++ V_28 ) {
if ( V_2 -> V_17 -> V_30 [ V_28 ] == V_15 ) {
V_5 = F_5 ( V_2 , V_2 -> V_17 -> V_31 ,
V_2 -> V_17 -> V_32 , V_28 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_9 -> V_11 ,
L_7 ) ;
return V_5 ;
}
V_2 -> V_33 = V_15 ;
return 0 ;
}
}
return - V_34 ;
}
static int F_13 ( struct V_1 * V_2 , int V_15 )
{
int V_5 , V_28 ;
if ( V_2 -> V_6 )
return - V_7 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_17 -> V_35 ; ++ V_28 )
if ( V_2 -> V_17 -> V_36 [ V_28 ] == V_15 ) {
V_5 = F_5 ( V_2 , V_2 -> V_17 -> V_37 ,
V_2 -> V_17 -> V_38 , V_28 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_9 -> V_11 ,
L_8 ) ;
return V_5 ;
}
V_2 -> V_39 = V_15 ;
return 0 ;
}
return - V_34 ;
}
static int F_14 ( struct V_1 * V_2 , bool V_40 )
{
T_1 V_16 = V_40 ? V_2 -> V_17 -> V_41 : 0 ;
int V_5 = F_5 ( V_2 , V_2 -> V_17 -> V_42 ,
V_2 -> V_17 -> V_43 , V_16 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_9 -> V_11 , L_9 ) ;
return V_5 ;
}
V_2 -> V_44 = V_40 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_5 = F_7 ( V_2 -> V_9 ,
V_2 -> V_17 -> V_45 , V_46 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_9 -> V_11 , L_10 ) ;
return V_5 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_5 = F_2 ( V_2 -> V_9 , V_47 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != V_48 )
return - V_49 ;
V_5 = F_15 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_17 ( 20 ) ;
V_5 = F_9 ( V_2 , false ) ;
if ( V_5 )
return V_5 ;
return F_14 ( V_2 , false ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_5 = F_16 ( V_2 ) ;
if ( V_5 )
goto V_23;
V_5 = F_5 ( V_2 , V_26 , V_50 , 1 ) ;
if ( V_5 )
goto V_23;
V_5 = F_11 ( V_2 , true ) ;
if ( V_5 )
goto V_23;
V_5 = F_5 ( V_2 , V_51 , V_52 , 1 ) ;
if ( V_5 )
goto V_23;
V_5 = F_12 ( V_2 , 20 ) ;
if ( V_5 )
goto V_23;
V_5 = F_13 ( V_2 , 2452 ) ;
if ( V_5 )
goto V_23;
return 0 ;
V_23:
F_3 ( & V_2 -> V_9 -> V_11 , L_11 ) ;
return V_5 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_5 = F_16 ( V_2 ) ;
if ( V_5 )
goto V_23;
V_5 = F_12 ( V_2 , 16 ) ;
if ( V_5 )
goto V_23;
V_5 = F_13 ( V_2 , 38344 ) ;
if ( V_5 )
goto V_23;
V_5 = F_5 ( V_2 , V_53 ,
V_54 , 1 ) ;
if ( V_5 )
goto V_23;
return 0 ;
V_23:
F_3 ( & V_2 -> V_9 -> V_11 , L_11 ) ;
return V_5 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 , false ) )
goto V_23;
if ( F_11 ( V_2 , false ) )
goto V_23;
if ( F_10 ( V_2 , true ) )
goto V_23;
return;
V_23:
F_3 ( & V_2 -> V_9 -> V_11 , L_12 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 , false ) )
goto V_23;
if ( F_10 ( V_2 , true ) )
goto V_23;
return;
V_23:
F_3 ( & V_2 -> V_9 -> V_11 , L_12 ) ;
}
static T_2 F_22 ( char * V_55 , const int * V_56 , unsigned V_57 ,
bool V_58 )
{
T_3 V_59 = 0 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_57 ; V_28 ++ ) {
if ( ! V_56 [ V_28 ] )
continue;
V_59 += F_23 ( V_55 + V_59 , V_60 - V_59 ,
V_58 ? L_13 : L_14 , V_56 [ V_28 ] ) ;
}
V_55 [ V_59 - 1 ] = '\n' ;
return V_59 ;
}
static T_2 F_24 ( struct V_61 * V_11 ,
struct V_62 * V_63 , char * V_55 )
{
struct V_1 * V_2 = F_25 ( F_26 ( V_11 ) ) ;
return F_22 ( V_55 , V_2 -> V_17 -> V_30 ,
V_2 -> V_17 -> V_29 , false ) ;
}
static T_2 F_27 ( struct V_61 * V_11 ,
struct V_62 * V_63 , char * V_55 )
{
struct V_1 * V_2 = F_25 ( F_26 ( V_11 ) ) ;
return F_22 ( V_55 , V_2 -> V_17 -> V_36 ,
V_2 -> V_17 -> V_35 , true ) ;
}
static int F_28 ( struct V_64 * V_65 ,
struct V_66 const * V_4 , int * V_15 , int * V_67 ,
long V_14 )
{
struct V_1 * V_2 = F_25 ( V_65 ) ;
int V_5 ;
switch ( V_14 ) {
case V_68 :
F_29 ( & V_2 -> V_69 ) ;
if ( F_30 ( V_65 ) ) {
F_31 ( & V_2 -> V_69 ) ;
return - V_7 ;
}
V_5 = F_1 ( V_2 , V_4 -> V_70 ) ;
F_31 ( & V_2 -> V_69 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_15 = F_32 ( V_5 >> V_4 -> V_71 . V_72 ,
V_4 -> V_71 . V_73 - 1 ) ;
return V_74 ;
case V_75 :
* V_15 = V_2 -> V_33 ;
return V_74 ;
case V_76 :
switch ( V_4 -> type ) {
case V_77 :
* V_15 = 0 ;
* V_67 = V_2 -> V_39 ;
return V_78 ;
case V_79 :
* V_15 = 500 ;
return V_74 ;
default:
return - V_34 ;
}
case V_80 :
* V_15 = 48 ;
return V_74 ;
default:
return - V_34 ;
}
}
static int F_33 ( struct V_64 * V_65 ,
struct V_66 const * V_4 , int V_15 , int V_67 , long V_14 )
{
struct V_1 * V_2 = F_25 ( V_65 ) ;
int V_5 ;
switch ( V_14 ) {
case V_76 :
if ( V_15 )
return - V_34 ;
F_29 ( & V_2 -> V_69 ) ;
V_5 = F_13 ( V_2 , V_67 ) ;
F_31 ( & V_2 -> V_69 ) ;
return V_5 ;
case V_75 :
if ( V_67 )
return - V_34 ;
F_29 ( & V_2 -> V_69 ) ;
V_5 = F_12 ( V_2 , V_15 ) ;
F_31 ( & V_2 -> V_69 ) ;
return V_5 ;
default:
return - V_34 ;
}
}
static int F_34 ( struct V_64 * V_65 ,
const struct V_66 * V_4 )
{
struct V_1 * V_2 = F_25 ( V_65 ) ;
return V_2 -> V_44 ;
}
static int F_35 ( struct V_64 * V_65 ,
const struct V_66 * V_4 , unsigned int V_40 )
{
struct V_1 * V_2 = F_25 ( V_65 ) ;
int V_5 ;
F_29 ( & V_2 -> V_69 ) ;
V_5 = F_14 ( V_2 , V_40 ) ;
F_31 ( & V_2 -> V_69 ) ;
return V_5 ;
}
static T_4 F_36 ( int V_81 , void * V_82 )
{
struct V_83 * V_84 = V_82 ;
struct V_64 * V_65 = V_84 -> V_65 ;
struct V_1 * V_2 = F_25 ( V_65 ) ;
T_5 V_85 = F_37 () ;
int V_86 , V_5 , V_28 = 0 ;
F_29 ( & V_2 -> V_69 ) ;
F_38 (bit, indio_dev->buffer->scan_mask,
indio_dev->masklength) {
V_5 = F_1 ( V_2 , V_86 ) ;
if ( V_5 < 0 ) {
F_31 ( & V_2 -> V_69 ) ;
goto V_23;
}
( ( V_87 * ) V_2 -> V_88 ) [ V_28 ++ ] = V_5 ;
}
F_31 ( & V_2 -> V_69 ) ;
F_39 ( V_65 , V_2 -> V_88 , V_85 ) ;
V_23:
F_40 ( V_65 -> V_89 ) ;
return V_90 ;
}
static int F_41 ( struct V_91 * V_89 ,
bool V_20 )
{
struct V_64 * V_65 = F_42 ( V_89 ) ;
struct V_1 * V_2 = F_25 ( V_65 ) ;
return F_9 ( V_2 , V_20 ) ;
}
static int F_43 ( struct V_91 * V_89 )
{
struct V_64 * V_65 = F_42 ( V_89 ) ;
struct V_1 * V_2 = F_25 ( V_65 ) ;
return F_8 ( V_2 ) ;
}
static int F_44 ( struct V_92 * V_9 ,
const struct V_93 * V_94 )
{
struct V_1 * V_2 ;
struct V_64 * V_65 ;
int V_5 ;
V_65 = F_45 ( & V_9 -> V_11 , sizeof( * V_2 ) ) ;
if ( ! V_65 )
return - V_95 ;
V_2 = F_25 ( V_65 ) ;
F_46 ( V_9 , V_65 ) ;
V_2 -> V_9 = V_9 ;
V_2 -> V_17 = & V_96 [ V_94 -> V_97 ] ;
V_5 = V_2 -> V_17 -> V_98 ( V_2 ) ;
if ( V_5 < 0 )
goto V_99;
F_47 ( & V_2 -> V_69 ) ;
V_65 -> V_11 . V_100 = & V_9 -> V_11 ;
V_65 -> V_101 = V_2 -> V_17 -> V_101 ;
V_65 -> V_102 = V_2 -> V_17 -> V_102 ;
V_65 -> V_103 = V_94 -> V_103 ;
V_65 -> V_104 = V_105 ;
V_65 -> V_106 = & V_107 ;
if ( V_9 -> V_81 > 0 ) {
V_2 -> V_89 = F_48 ( L_15 , V_65 -> V_103 ,
V_65 -> V_94 ) ;
if ( ! V_2 -> V_89 ) {
V_5 = - V_95 ;
goto V_99;
}
V_5 = F_49 ( & V_9 -> V_11 , V_9 -> V_81 ,
V_108 , V_109 ,
L_16 , V_2 -> V_89 ) ;
if ( V_5 ) {
F_3 ( & V_9 -> V_11 , L_17 ) ;
goto V_110;
}
V_2 -> V_89 -> V_11 . V_100 = & V_9 -> V_11 ;
V_2 -> V_89 -> V_111 = & V_112 ;
F_50 ( V_2 -> V_89 , V_65 ) ;
V_65 -> V_89 = F_51 ( V_2 -> V_89 ) ;
V_5 = F_52 ( V_2 -> V_89 ) ;
if ( V_5 )
goto V_110;
}
V_5 = F_53 ( V_65 , NULL ,
F_36 , NULL ) ;
if ( V_5 < 0 ) {
F_3 ( & V_9 -> V_11 , L_18 ) ;
goto V_113;
}
V_5 = F_54 ( V_65 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_9 -> V_11 , L_19 ) ;
goto V_114;
}
return 0 ;
V_114:
F_55 ( V_65 ) ;
V_113:
if ( V_2 -> V_89 )
F_56 ( V_2 -> V_89 ) ;
V_110:
F_57 ( V_2 -> V_89 ) ;
V_99:
V_2 -> V_17 -> V_115 ( V_2 ) ;
return V_5 ;
}
static int F_58 ( struct V_92 * V_9 )
{
struct V_64 * V_65 = F_59 ( V_9 ) ;
struct V_1 * V_2 = F_25 ( V_65 ) ;
F_60 ( V_65 ) ;
F_55 ( V_65 ) ;
if ( V_2 -> V_89 ) {
F_56 ( V_2 -> V_89 ) ;
F_57 ( V_2 -> V_89 ) ;
}
F_29 ( & V_2 -> V_69 ) ;
V_2 -> V_17 -> V_115 ( V_2 ) ;
F_31 ( & V_2 -> V_69 ) ;
return 0 ;
}
static int F_61 ( struct V_61 * V_11 )
{
struct V_64 * V_65 = F_59 ( F_62 ( V_11 ) ) ;
struct V_1 * V_2 = F_25 ( V_65 ) ;
int V_5 ;
F_29 ( & V_2 -> V_69 ) ;
V_5 = F_10 ( V_2 , true ) ;
F_31 ( & V_2 -> V_69 ) ;
return V_5 ;
}
static int F_63 ( struct V_61 * V_11 )
{
struct V_64 * V_65 = F_59 ( F_62 ( V_11 ) ) ;
struct V_1 * V_2 = F_25 ( V_65 ) ;
int V_5 ;
F_29 ( & V_2 -> V_69 ) ;
V_5 = F_10 ( V_2 , false ) ;
F_31 ( & V_2 -> V_69 ) ;
return V_5 ;
}
