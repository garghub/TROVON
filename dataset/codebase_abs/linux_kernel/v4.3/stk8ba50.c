static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_4 = F_2 ( V_6 , V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_6 -> V_7 , L_1 ) ;
return V_4 ;
}
return V_4 ;
}
static int F_4 ( struct V_8 * V_9 ,
bool V_10 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
int V_4 ;
if ( V_10 )
V_4 = F_7 ( V_2 -> V_6 ,
V_13 , V_14 ) ;
else
V_4 = F_7 ( V_2 -> V_6 ,
V_13 , 0x00 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_6 -> V_7 , L_2 ) ;
else
V_2 -> V_15 = V_10 ;
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 , bool V_16 )
{
int V_4 ;
T_1 V_17 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_4 = F_9 ( V_6 , V_18 ) ;
if ( V_4 < 0 )
goto V_19;
if ( V_16 )
V_17 = V_4 | V_20 ;
else
V_17 = V_4 & ( ~ V_20 ) ;
V_4 = F_7 ( V_6 , V_18 ,
V_17 ) ;
if ( V_4 < 0 )
goto V_19;
return V_4 ;
V_19:
F_3 ( & V_6 -> V_7 , L_3 ) ;
return V_4 ;
}
static int F_10 ( struct V_11 * V_12 ,
struct V_21 const * V_22 ,
int * V_23 , int * V_24 , long V_25 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
int V_4 ;
switch ( V_25 ) {
case V_26 :
if ( F_11 ( V_12 ) )
return - V_27 ;
F_12 ( & V_2 -> V_28 ) ;
V_4 = F_8 ( V_2 , V_29 ) ;
if ( V_4 < 0 ) {
F_13 ( & V_2 -> V_28 ) ;
return - V_30 ;
}
V_4 = F_1 ( V_2 , V_22 -> V_31 ) ;
if ( V_4 < 0 ) {
F_8 ( V_2 , V_32 ) ;
F_13 ( & V_2 -> V_28 ) ;
return - V_30 ;
}
* V_23 = F_14 ( V_4 >> V_33 , 9 ) ;
F_8 ( V_2 , V_32 ) ;
F_13 ( & V_2 -> V_28 ) ;
return V_34 ;
case V_35 :
* V_23 = 0 ;
* V_24 = V_36 [ V_2 -> V_37 ] . V_38 ;
return V_39 ;
case V_40 :
* V_23 = V_41
[ V_2 -> V_42 ] . V_43 ;
* V_24 = 0 ;
return V_34 ;
}
return - V_30 ;
}
static int F_15 ( struct V_11 * V_12 ,
struct V_21 const * V_22 ,
int V_23 , int V_24 , long V_25 )
{
int V_4 ;
int V_44 ;
int V_45 = - 1 ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
switch ( V_25 ) {
case V_35 :
if ( V_23 != 0 )
return - V_30 ;
for ( V_44 = 0 ; V_44 < F_16 ( V_36 ) ; V_44 ++ )
if ( V_24 == V_36 [ V_44 ] . V_38 ) {
V_45 = V_44 ;
break;
}
if ( V_45 < 0 )
return - V_30 ;
V_4 = F_7 ( V_2 -> V_6 ,
V_46 ,
V_36 [ V_45 ] . V_47 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_6 -> V_7 ,
L_4 ) ;
else
V_2 -> V_37 = V_45 ;
return V_4 ;
case V_40 :
for ( V_44 = 0 ; V_44 < F_16 ( V_41 ) ; V_44 ++ )
if ( V_23 == V_41 [ V_44 ] . V_43 ) {
V_45 = V_44 ;
break;
}
if ( V_45 < 0 )
return - V_30 ;
V_4 = F_7 ( V_2 -> V_6 ,
V_48 ,
V_41 [ V_45 ] . V_47 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_6 -> V_7 ,
L_5 ) ;
else
V_2 -> V_42 = V_45 ;
return V_4 ;
}
return - V_30 ;
}
static T_2 F_17 ( int V_49 , void * V_50 )
{
struct V_51 * V_52 = V_50 ;
struct V_11 * V_12 = V_52 -> V_12 ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
int V_53 , V_4 , V_44 = 0 ;
F_12 ( & V_2 -> V_28 ) ;
if ( * ( V_12 -> V_54 ) == V_55 ) {
V_4 = F_18 ( V_2 -> V_6 ,
V_56 ,
V_57 ,
( T_1 * ) V_2 -> V_58 ) ;
if ( V_4 < V_57 ) {
F_3 ( & V_2 -> V_6 -> V_7 , L_1 ) ;
goto V_59;
}
} else {
F_19 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_4 = F_1 ( V_2 ,
V_60 [ V_53 ] ) ;
if ( V_4 < 0 )
goto V_59;
V_2 -> V_58 [ V_44 ++ ] = V_4 ;
}
}
F_20 ( V_12 , V_2 -> V_58 ,
V_52 -> V_61 ) ;
V_59:
F_13 ( & V_2 -> V_28 ) ;
F_21 ( V_12 -> V_9 ) ;
return V_62 ;
}
static T_2 F_22 ( int V_49 , void * V_63 )
{
struct V_11 * V_12 = V_63 ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
if ( V_2 -> V_15 )
F_23 ( V_2 -> V_64 ) ;
return V_62 ;
}
static int F_24 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
return F_8 ( V_2 , V_29 ) ;
}
static int F_25 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
return F_8 ( V_2 , V_32 ) ;
}
static int F_26 ( struct V_5 * V_6 )
{
struct V_65 * V_7 ;
struct V_66 * V_67 ;
int V_4 ;
if ( ! V_6 )
return - V_30 ;
V_7 = & V_6 -> V_7 ;
V_67 = F_27 ( V_7 , V_68 , 0 , V_69 ) ;
if ( F_28 ( V_67 ) ) {
F_3 ( V_7 , L_6 ) ;
return F_29 ( V_67 ) ;
}
V_4 = F_30 ( V_67 ) ;
F_31 ( V_7 , L_7 , F_32 ( V_67 ) , V_4 ) ;
return V_4 ;
}
static int F_33 ( struct V_5 * V_6 ,
const struct V_70 * V_71 )
{
int V_4 ;
struct V_11 * V_12 ;
struct V_1 * V_2 ;
V_12 = F_34 ( & V_6 -> V_7 , sizeof( * V_2 ) ) ;
if ( ! V_12 ) {
F_3 ( & V_6 -> V_7 , L_8 ) ;
return - V_72 ;
}
V_2 = F_6 ( V_12 ) ;
V_2 -> V_6 = V_6 ;
F_35 ( V_6 , V_12 ) ;
F_36 ( & V_2 -> V_28 ) ;
V_12 -> V_7 . V_73 = & V_6 -> V_7 ;
V_12 -> V_74 = & V_75 ;
V_12 -> V_76 = V_77 ;
V_12 -> V_78 = V_79 ;
V_12 -> V_80 = V_81 ;
V_12 -> V_82 = F_16 ( V_81 ) ;
V_4 = F_7 ( V_6 ,
V_83 , V_84 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_6 -> V_7 , L_9 ) ;
goto V_85;
}
V_2 -> V_37 = 0 ;
V_2 -> V_42 = V_86 ;
V_4 = F_7 ( V_6 ,
V_13 , V_14 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_6 -> V_7 , L_10 ) ;
goto V_85;
}
V_4 = F_7 ( V_6 ,
V_87 , V_88 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_6 -> V_7 , L_10 ) ;
goto V_85;
}
if ( V_6 -> V_49 < 0 )
V_6 -> V_49 = F_26 ( V_6 ) ;
if ( V_6 -> V_49 >= 0 ) {
V_4 = F_37 ( & V_6 -> V_7 , V_6 -> V_49 ,
F_22 ,
NULL ,
V_89 |
V_90 ,
V_91 ,
V_12 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_6 -> V_7 , L_11 ,
V_6 -> V_49 ) ;
goto V_85;
}
V_2 -> V_64 = F_38 ( & V_6 -> V_7 ,
L_12 ,
V_12 -> V_76 ,
V_12 -> V_71 ) ;
if ( ! V_2 -> V_64 ) {
V_4 = - V_72 ;
goto V_85;
}
V_2 -> V_64 -> V_7 . V_73 = & V_6 -> V_7 ;
V_2 -> V_64 -> V_92 = & V_93 ;
F_39 ( V_2 -> V_64 , V_12 ) ;
V_4 = F_40 ( V_2 -> V_64 ) ;
if ( V_4 ) {
F_3 ( & V_6 -> V_7 , L_13 ) ;
goto V_85;
}
}
V_4 = F_41 ( V_12 ,
V_94 ,
F_17 ,
& V_95 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_6 -> V_7 , L_14 ) ;
goto V_96;
}
V_4 = F_42 ( V_12 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_6 -> V_7 , L_15 ) ;
goto V_97;
}
return V_4 ;
V_97:
F_43 ( V_12 ) ;
V_96:
if ( V_2 -> V_64 )
F_44 ( V_2 -> V_64 ) ;
V_85:
F_8 ( V_2 , V_32 ) ;
return V_4 ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = F_46 ( V_6 ) ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
F_47 ( V_12 ) ;
F_43 ( V_12 ) ;
if ( V_2 -> V_64 )
F_44 ( V_2 -> V_64 ) ;
return F_8 ( V_2 , V_32 ) ;
}
static int F_48 ( struct V_65 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( F_46 ( F_49 ( V_7 ) ) ) ;
return F_8 ( V_2 , V_32 ) ;
}
static int F_50 ( struct V_65 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( F_46 ( F_49 ( V_7 ) ) ) ;
return F_8 ( V_2 , V_29 ) ;
}
