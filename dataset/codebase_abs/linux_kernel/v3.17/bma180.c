static int F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
T_1 V_5 = V_6 + V_4 * 2 ;
int V_7 ;
if ( V_2 -> V_8 )
return - V_9 ;
V_7 = F_2 ( V_2 -> V_10 , V_5 ) ;
if ( V_7 < 0 )
F_3 ( & V_2 -> V_10 -> V_11 ,
L_1 , 'x' + V_4 ) ;
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_12 , T_1 V_13 )
{
int V_7 = F_5 ( V_2 -> V_10 , V_5 ) ;
T_1 V_14 = ( V_7 & ~ V_12 ) | ( V_13 << ( F_6 ( V_12 ) - 1 ) ) ;
if ( V_7 < 0 )
return V_7 ;
return F_7 ( V_2 -> V_10 , V_5 , V_14 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_7 = F_4 ( V_2 , V_15 , V_16 , 1 ) ;
if ( V_7 )
F_3 ( & V_2 -> V_10 -> V_11 , L_2 ) ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 , int V_17 )
{
T_1 V_14 = V_17 ? V_18 : 0x00 ;
int V_7 = F_7 ( V_2 -> V_10 , V_19 ,
V_14 ) ;
if ( V_7 )
goto V_20;
V_7 = F_8 ( V_2 ) ;
if ( V_7 )
goto V_20;
return 0 ;
V_20:
F_3 ( & V_2 -> V_10 -> V_11 ,
L_3 , V_17 ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 , int V_17 )
{
int V_7 = F_4 ( V_2 , V_15 , V_21 , V_17 ) ;
if ( V_7 ) {
F_3 ( & V_2 -> V_10 -> V_11 ,
L_4 , V_17 ) ;
return V_7 ;
}
V_2 -> V_8 = V_17 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_17 )
{
int V_7 = F_4 ( V_2 , V_15 , V_22 , V_17 ) ;
if ( V_7 )
F_3 ( & V_2 -> V_10 -> V_11 ,
L_5 , V_17 ) ;
return V_7 ;
}
static int F_12 ( struct V_1 * V_2 , int V_13 )
{
int V_7 , V_23 ;
if ( V_2 -> V_8 )
return - V_9 ;
for ( V_23 = 0 ; V_23 < F_13 ( V_24 ) ; ++ V_23 ) {
if ( V_24 [ V_23 ] == V_13 ) {
V_7 = F_4 ( V_2 ,
V_25 , V_26 , V_23 ) ;
if ( V_7 ) {
F_3 ( & V_2 -> V_10 -> V_11 ,
L_6 ) ;
return V_7 ;
}
V_2 -> V_27 = V_13 ;
return 0 ;
}
}
return - V_28 ;
}
static int F_14 ( struct V_1 * V_2 , int V_13 )
{
int V_7 , V_23 ;
if ( V_2 -> V_8 )
return - V_9 ;
for ( V_23 = 0 ; V_23 < F_13 ( V_29 ) ; ++ V_23 )
if ( V_29 [ V_23 ] == V_13 ) {
V_7 = F_4 ( V_2 ,
V_30 , V_31 , V_23 ) ;
if ( V_7 ) {
F_3 ( & V_2 -> V_10 -> V_11 ,
L_7 ) ;
return V_7 ;
}
V_2 -> V_32 = V_13 ;
return 0 ;
}
return - V_28 ;
}
static int F_15 ( struct V_1 * V_2 , int V_33 )
{
T_1 V_14 = V_33 ? V_34 : V_35 ;
int V_7 = F_4 ( V_2 , V_36 , V_37 ,
V_14 ) ;
if ( V_7 ) {
F_3 ( & V_2 -> V_10 -> V_11 , L_8 ) ;
return V_7 ;
}
V_2 -> V_38 = V_33 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_7 = F_7 ( V_2 -> V_10 ,
V_39 , V_40 ) ;
if ( V_7 )
F_3 ( & V_2 -> V_10 -> V_11 , L_9 ) ;
return V_7 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_7 = F_5 ( V_2 -> V_10 , V_41 ) ;
if ( V_7 < 0 )
goto V_20;
if ( V_7 != V_42 ) {
V_7 = - V_43 ;
goto V_20;
}
V_7 = F_16 ( V_2 ) ;
if ( V_7 )
goto V_20;
F_18 ( 20 ) ;
V_7 = F_4 ( V_2 , V_15 , V_44 , 1 ) ;
if ( V_7 )
goto V_20;
V_7 = F_11 ( V_2 , 1 ) ;
if ( V_7 )
goto V_20;
V_7 = F_9 ( V_2 , 0 ) ;
if ( V_7 )
goto V_20;
V_7 = F_4 ( V_2 , V_30 , V_45 , 1 ) ;
if ( V_7 )
goto V_20;
V_7 = F_15 ( V_2 , V_46 ) ;
if ( V_7 )
goto V_20;
V_7 = F_12 ( V_2 , V_47 ) ;
if ( V_7 )
goto V_20;
V_7 = F_14 ( V_2 , V_48 ) ;
if ( V_7 )
goto V_20;
return 0 ;
V_20:
F_3 ( & V_2 -> V_10 -> V_11 , L_10 ) ;
return V_7 ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 , 0 ) )
goto V_20;
if ( F_11 ( V_2 , 0 ) )
goto V_20;
if ( F_10 ( V_2 , 1 ) )
goto V_20;
return;
V_20:
F_3 ( & V_2 -> V_10 -> V_11 , L_11 ) ;
}
static int F_20 ( struct V_49 * V_50 ,
struct V_51 const * V_52 , int * V_13 , int * V_53 ,
long V_12 )
{
struct V_1 * V_2 = F_21 ( V_50 ) ;
int V_7 ;
switch ( V_12 ) {
case V_54 :
F_22 ( & V_2 -> V_55 ) ;
if ( F_23 ( V_50 ) )
V_7 = - V_9 ;
else
V_7 = F_1 ( V_2 , V_52 -> V_56 ) ;
F_24 ( & V_2 -> V_55 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_13 = ( V_57 ) V_7 >> V_52 -> V_58 . V_59 ;
return V_60 ;
case V_61 :
* V_13 = V_2 -> V_27 ;
return V_60 ;
case V_62 :
* V_13 = 0 ;
* V_53 = V_2 -> V_32 ;
return V_63 ;
default:
return - V_28 ;
}
}
static int F_25 ( struct V_49 * V_50 ,
struct V_51 const * V_52 , int V_13 , int V_53 , long V_12 )
{
struct V_1 * V_2 = F_21 ( V_50 ) ;
int V_7 ;
switch ( V_12 ) {
case V_62 :
if ( V_13 )
return - V_28 ;
F_22 ( & V_2 -> V_55 ) ;
V_7 = F_14 ( V_2 , V_53 ) ;
F_24 ( & V_2 -> V_55 ) ;
return V_7 ;
case V_61 :
if ( V_53 )
return - V_28 ;
F_22 ( & V_2 -> V_55 ) ;
V_7 = F_12 ( V_2 , V_13 ) ;
F_24 ( & V_2 -> V_55 ) ;
return V_7 ;
default:
return - V_28 ;
}
}
static int F_26 ( struct V_49 * V_50 ,
const unsigned long * V_64 )
{
struct V_1 * V_2 = F_21 ( V_50 ) ;
if ( V_2 -> V_65 )
F_27 ( & V_50 -> V_11 , V_2 -> V_65 ) ;
V_2 -> V_65 = F_28 ( & V_50 -> V_11 ,
V_50 -> V_66 , V_67 ) ;
if ( ! V_2 -> V_65 )
return - V_68 ;
return 0 ;
}
static int F_29 ( struct V_49 * V_50 ,
const struct V_51 * V_52 )
{
struct V_1 * V_2 = F_21 ( V_50 ) ;
return V_2 -> V_38 ;
}
static int F_30 ( struct V_49 * V_50 ,
const struct V_51 * V_52 , unsigned int V_33 )
{
struct V_1 * V_2 = F_21 ( V_50 ) ;
int V_7 ;
F_22 ( & V_2 -> V_55 ) ;
V_7 = F_15 ( V_2 , V_33 ) ;
F_24 ( & V_2 -> V_55 ) ;
return V_7 ;
}
static T_2 F_31 ( int V_69 , void * V_70 )
{
struct V_71 * V_72 = V_70 ;
struct V_49 * V_50 = V_72 -> V_50 ;
struct V_1 * V_2 = F_21 ( V_50 ) ;
T_3 V_73 = F_32 () ;
int V_74 , V_7 , V_23 = 0 ;
F_22 ( & V_2 -> V_55 ) ;
F_33 (bit, indio_dev->buffer->scan_mask,
indio_dev->masklength) {
V_7 = F_1 ( V_2 , V_74 ) ;
if ( V_7 < 0 ) {
F_24 ( & V_2 -> V_55 ) ;
goto V_20;
}
( ( V_57 * ) V_2 -> V_65 ) [ V_23 ++ ] = V_7 ;
}
F_24 ( & V_2 -> V_55 ) ;
F_34 ( V_50 , V_2 -> V_65 , V_73 ) ;
V_20:
F_35 ( V_50 -> V_75 ) ;
return V_76 ;
}
static int F_36 ( struct V_77 * V_75 ,
bool V_17 )
{
struct V_49 * V_50 = F_37 ( V_75 ) ;
struct V_1 * V_2 = F_21 ( V_50 ) ;
return F_9 ( V_2 , V_17 ) ;
}
static int F_38 ( struct V_77 * V_75 )
{
struct V_49 * V_50 = F_37 ( V_75 ) ;
struct V_1 * V_2 = F_21 ( V_50 ) ;
return F_8 ( V_2 ) ;
}
static int F_39 ( struct V_78 * V_10 ,
const struct V_79 * V_80 )
{
struct V_1 * V_2 ;
struct V_49 * V_50 ;
struct V_77 * V_75 ;
int V_7 ;
V_50 = F_40 ( & V_10 -> V_11 , sizeof( * V_2 ) ) ;
if ( ! V_50 )
return - V_68 ;
V_2 = F_21 ( V_50 ) ;
F_41 ( V_10 , V_50 ) ;
V_2 -> V_10 = V_10 ;
V_7 = F_17 ( V_2 ) ;
if ( V_7 < 0 )
goto V_81;
F_42 ( & V_2 -> V_55 ) ;
V_50 -> V_11 . V_82 = & V_10 -> V_11 ;
V_50 -> V_83 = V_84 ;
V_50 -> V_85 = F_13 ( V_84 ) ;
V_50 -> V_86 = V_87 ;
V_50 -> V_88 = V_89 ;
V_50 -> V_90 = & V_91 ;
V_75 = F_43 ( L_12 , V_50 -> V_86 , V_50 -> V_80 ) ;
if ( ! V_75 ) {
V_7 = - V_68 ;
goto V_81;
}
V_7 = F_44 ( & V_10 -> V_11 , V_10 -> V_69 ,
V_92 ,
V_93 , V_94 , V_75 ) ;
if ( V_7 ) {
F_3 ( & V_10 -> V_11 , L_13 ) ;
goto V_95;
}
V_75 -> V_11 . V_82 = & V_10 -> V_11 ;
V_75 -> V_96 = & V_97 ;
F_45 ( V_75 , V_50 ) ;
V_2 -> V_75 = V_75 ;
V_50 -> V_75 = F_46 ( V_75 ) ;
V_7 = F_47 ( V_75 ) ;
if ( V_7 )
goto V_95;
V_7 = F_48 ( V_50 , NULL ,
F_31 , NULL ) ;
if ( V_7 < 0 ) {
F_3 ( & V_10 -> V_11 , L_14 ) ;
goto V_98;
}
V_7 = F_49 ( V_50 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_10 -> V_11 , L_15 ) ;
goto V_99;
}
return 0 ;
V_99:
F_50 ( V_50 ) ;
V_98:
F_51 ( V_75 ) ;
V_95:
F_52 ( V_75 ) ;
V_81:
F_19 ( V_2 ) ;
return V_7 ;
}
static int F_53 ( struct V_78 * V_10 )
{
struct V_49 * V_50 = F_54 ( V_10 ) ;
struct V_1 * V_2 = F_21 ( V_50 ) ;
F_55 ( V_50 ) ;
F_50 ( V_50 ) ;
F_51 ( V_2 -> V_75 ) ;
F_52 ( V_2 -> V_75 ) ;
F_22 ( & V_2 -> V_55 ) ;
F_19 ( V_2 ) ;
F_24 ( & V_2 -> V_55 ) ;
return 0 ;
}
static int F_56 ( struct V_100 * V_11 )
{
struct V_49 * V_50 = F_54 ( F_57 ( V_11 ) ) ;
struct V_1 * V_2 = F_21 ( V_50 ) ;
int V_7 ;
F_22 ( & V_2 -> V_55 ) ;
V_7 = F_10 ( V_2 , 1 ) ;
F_24 ( & V_2 -> V_55 ) ;
return V_7 ;
}
static int F_58 ( struct V_100 * V_11 )
{
struct V_49 * V_50 = F_54 ( F_57 ( V_11 ) ) ;
struct V_1 * V_2 = F_21 ( V_50 ) ;
int V_7 ;
F_22 ( & V_2 -> V_55 ) ;
V_7 = F_10 ( V_2 , 0 ) ;
F_24 ( & V_2 -> V_55 ) ;
return V_7 ;
}
