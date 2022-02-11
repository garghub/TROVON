static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = 10 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_3 = F_2 ( V_6 , V_7 , 0x70 ) ;
if ( V_3 < 0 )
goto V_8;
V_3 = F_2 ( V_6 , V_9 , 0x02 ) ;
if ( V_3 < 0 )
goto V_8;
do {
F_3 ( 1000 , 5000 ) ;
V_3 = F_4 ( V_6 , V_9 ) ;
if ( V_3 < 0 )
goto V_8;
V_4 -- ;
} while ( ! ( V_3 & F_5 ( 7 ) ) && V_4 > 0 );
if ( V_4 == 0 ) {
V_3 = - V_10 ;
goto V_8;
}
V_3 = F_4 ( V_6 , V_11 ) ;
if ( V_3 == 0 )
V_3 = - V_12 ;
if ( V_3 < 0 )
goto V_8;
V_3 = F_2 ( V_2 -> V_6 , V_13 , V_3 ) ;
if ( V_3 < 0 )
goto V_8;
F_6 ( 150 ) ;
return 0 ;
V_8:
F_7 ( & V_6 -> V_14 , L_1 ) ;
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_15 )
{
int V_3 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_15 == V_2 -> V_15 )
return 0 ;
V_3 = F_2 ( V_6 , V_16 , V_15 ) ;
if ( V_3 < 0 ) {
F_7 ( & V_6 -> V_14 , L_2 ) ;
return V_3 ;
}
V_2 -> V_15 = V_15 ;
if ( V_15 & V_17 ) {
F_3 ( 1000 , 5000 ) ;
V_3 = F_1 ( V_2 ) ;
}
return V_3 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_18 )
{
int V_3 ;
T_1 V_15 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_15 = V_2 -> V_15 ;
V_3 = F_8 ( V_2 , V_19 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_6 , V_20 , V_18 ) ;
if ( V_3 < 0 ) {
F_7 ( & V_6 -> V_14 , L_3 ) ;
F_8 ( V_2 , V_15 ) ;
return V_3 ;
}
return F_8 ( V_2 , V_15 ) ;
}
static int F_10 ( struct V_21 * V_22 ,
bool V_23 )
{
struct V_24 * V_25 = F_11 ( V_22 ) ;
struct V_1 * V_2 = F_12 ( V_25 ) ;
int V_3 ;
if ( V_23 )
V_3 = F_9 ( V_2 , V_26 ) ;
else
V_3 = F_9 ( V_2 , 0x00 ) ;
if ( V_3 < 0 ) {
F_7 ( & V_2 -> V_6 -> V_14 , L_4 ) ;
return V_3 ;
}
V_2 -> V_27 = V_23 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_28 )
{
int V_3 ;
T_1 V_29 ;
T_1 V_15 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_28 == V_2 -> V_30 )
return 0 ;
V_15 = V_2 -> V_15 ;
V_3 = F_8 ( V_2 , V_19 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_6 , V_31 ) ;
if ( V_3 < 0 )
goto V_32;
V_29 = ( V_3 & ( ~ V_33 ) ) | V_28 ;
V_3 = F_2 ( V_6 , V_31 , V_29 ) ;
if ( V_3 < 0 )
goto V_32;
V_2 -> V_30 = V_28 ;
return F_8 ( V_2 , V_15 ) ;
V_32:
F_7 ( & V_6 -> V_14 , L_5 ) ;
F_8 ( V_2 , V_15 ) ;
return V_3 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_34 )
{
int V_3 ;
T_1 V_29 ;
T_1 V_15 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_34 != 1 && V_34 != 2 )
return - V_12 ;
else if ( V_34 == V_2 -> V_34 )
return 0 ;
V_15 = V_2 -> V_15 ;
V_3 = F_8 ( V_2 , V_19 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_6 , V_35 ) ;
if ( V_3 < 0 )
goto V_32;
V_29 = V_3 & ( ~ V_36 ) ;
V_29 |= V_34 << V_37 ;
V_3 = F_2 ( V_6 , V_35 , V_29 ) ;
if ( V_3 < 0 )
goto V_32;
V_2 -> V_34 = V_34 ;
return F_8 ( V_2 , V_15 ) ;
V_32:
F_7 ( & V_6 -> V_14 , L_6 ) ;
F_8 ( V_2 , V_15 ) ;
return V_3 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_38 )
{
int V_3 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_38 > 2 )
return - V_12 ;
V_3 = F_4 ( V_6 , V_38 ) ;
if ( V_3 < 0 )
F_7 ( & V_6 -> V_14 , L_7 ) ;
return V_3 ;
}
static int F_16 ( struct V_24 * V_25 ,
struct V_39 const * V_40 ,
int * V_41 , int * V_42 , long V_43 )
{
struct V_1 * V_2 = F_12 ( V_25 ) ;
int V_3 ;
switch ( V_43 ) {
case V_44 :
if ( F_17 ( V_25 ) )
return - V_45 ;
F_18 ( & V_2 -> V_46 ) ;
V_3 = F_8 ( V_2 , V_2 -> V_15 | V_17 ) ;
if ( V_3 < 0 ) {
F_19 ( & V_2 -> V_46 ) ;
return V_3 ;
}
V_3 = F_15 ( V_2 , V_40 -> V_38 ) ;
if ( V_3 < 0 ) {
F_8 ( V_2 ,
V_2 -> V_15 & ( ~ V_17 ) ) ;
F_19 ( & V_2 -> V_46 ) ;
return V_3 ;
}
* V_41 = F_20 ( V_3 , 7 ) ;
V_3 = F_8 ( V_2 ,
V_2 -> V_15 & ( ~ V_17 ) ) ;
F_19 ( & V_2 -> V_46 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_47 ;
case V_48 :
* V_41 = V_49 [ V_2 -> V_34 - 1 ] [ 0 ] ;
* V_42 = V_49 [ V_2 -> V_34 - 1 ] [ 1 ] ;
return V_50 ;
case V_51 :
* V_41 = V_52 [ V_2 -> V_30 ] . V_41 ;
* V_42 = V_52 [ V_2 -> V_30 ] . V_42 ;
return V_50 ;
}
return - V_12 ;
}
static int F_21 ( struct V_24 * V_25 ,
struct V_39 const * V_40 ,
int V_41 , int V_42 , long V_43 )
{
int V_53 ;
int V_54 = - 1 ;
int V_3 ;
struct V_1 * V_2 = F_12 ( V_25 ) ;
switch ( V_43 ) {
case V_48 :
for ( V_53 = 0 ; V_53 < F_22 ( V_49 ) ; V_53 ++ )
if ( V_41 == V_49 [ V_53 ] [ 0 ] &&
V_42 == V_49 [ V_53 ] [ 1 ] ) {
V_54 = V_53 + 1 ;
break;
}
if ( V_54 < 0 )
return - V_12 ;
F_18 ( & V_2 -> V_46 ) ;
V_3 = F_14 ( V_2 , V_54 ) ;
F_19 ( & V_2 -> V_46 ) ;
return V_3 ;
case V_51 :
for ( V_53 = 0 ; V_53 < F_22 ( V_52 ) ; V_53 ++ )
if ( V_41 == V_52 [ V_53 ] . V_41 &&
V_42 == V_52 [ V_53 ] . V_42 ) {
V_54 = V_53 ;
break;
}
if ( V_54 < 0 )
return - V_12 ;
F_18 ( & V_2 -> V_46 ) ;
V_3 = F_13 ( V_2 , V_54 ) ;
F_19 ( & V_2 -> V_46 ) ;
return V_3 ;
}
return - V_12 ;
}
static T_2 F_23 ( int V_55 , void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_24 * V_25 = V_58 -> V_25 ;
struct V_1 * V_2 = F_12 ( V_25 ) ;
int V_59 , V_3 , V_53 = 0 ;
F_18 ( & V_2 -> V_46 ) ;
if ( * ( V_25 -> V_60 ) == V_61 ) {
V_3 = F_24 ( V_2 -> V_6 ,
V_62 ,
V_63 ,
V_2 -> V_64 ) ;
if ( V_3 < V_63 ) {
F_7 ( & V_2 -> V_6 -> V_14 , L_7 ) ;
F_19 ( & V_2 -> V_46 ) ;
goto V_65;
}
} else {
F_25 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_3 = F_15 ( V_2 , V_59 ) ;
if ( V_3 < 0 ) {
F_19 ( & V_2 -> V_46 ) ;
goto V_65;
}
V_2 -> V_64 [ V_53 ++ ] = V_3 ;
}
}
F_19 ( & V_2 -> V_46 ) ;
F_26 ( V_25 , V_2 -> V_64 ,
V_58 -> V_66 ) ;
V_65:
F_27 ( V_25 -> V_22 ) ;
return V_67 ;
}
static T_2 F_28 ( int V_55 , void * V_68 )
{
struct V_24 * V_25 = V_68 ;
struct V_1 * V_2 = F_12 ( V_25 ) ;
if ( V_2 -> V_27 )
F_29 ( V_2 -> V_69 ) ;
return V_67 ;
}
static int F_30 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_12 ( V_25 ) ;
return F_8 ( V_2 , V_2 -> V_15 | V_17 ) ;
}
static int F_31 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_12 ( V_25 ) ;
return F_8 ( V_2 , V_2 -> V_15 & ( ~ V_17 ) ) ;
}
static int F_32 ( struct V_5 * V_6 ,
const struct V_70 * V_71 )
{
int V_3 ;
struct V_24 * V_25 ;
struct V_1 * V_2 ;
V_25 = F_33 ( & V_6 -> V_14 , sizeof( * V_2 ) ) ;
if ( ! V_25 ) {
F_7 ( & V_6 -> V_14 , L_8 ) ;
return - V_72 ;
}
V_2 = F_12 ( V_25 ) ;
V_2 -> V_6 = V_6 ;
F_34 ( V_6 , V_25 ) ;
F_35 ( & V_2 -> V_46 ) ;
V_25 -> V_14 . V_73 = & V_6 -> V_14 ;
V_25 -> V_74 = & V_75 ;
V_25 -> V_76 = V_77 ;
V_25 -> V_78 = V_79 ;
V_25 -> V_80 = V_81 ;
V_25 -> V_82 = F_22 ( V_81 ) ;
V_3 = F_2 ( V_2 -> V_6 , V_83 , 0x00 ) ;
if ( V_3 < 0 ) {
F_7 ( & V_6 -> V_14 , L_9 ) ;
return V_3 ;
}
V_2 -> V_30 = V_84 ;
V_3 = F_14 ( V_2 , V_85 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_8 ( V_2 ,
V_86 | V_17 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_6 -> V_55 > 0 ) {
V_3 = F_36 ( & V_6 -> V_14 , V_6 -> V_55 ,
F_28 ,
NULL ,
V_87 |
V_88 ,
V_89 ,
V_25 ) ;
if ( V_3 < 0 ) {
F_7 ( & V_6 -> V_14 , L_10 ,
V_6 -> V_55 ) ;
goto V_90;
}
V_2 -> V_69 = F_37 ( & V_6 -> V_14 ,
L_11 ,
V_25 -> V_76 ,
V_25 -> V_71 ) ;
if ( ! V_2 -> V_69 ) {
V_3 = - V_72 ;
goto V_90;
}
V_2 -> V_69 -> V_14 . V_73 = & V_6 -> V_14 ;
V_2 -> V_69 -> V_91 = & V_92 ;
F_38 ( V_2 -> V_69 , V_25 ) ;
V_3 = F_39 ( V_2 -> V_69 ) ;
if ( V_3 ) {
F_7 ( & V_6 -> V_14 , L_12 ) ;
goto V_90;
}
}
V_3 = F_40 ( V_25 ,
V_93 ,
F_23 ,
& V_94 ) ;
if ( V_3 < 0 ) {
F_7 ( & V_6 -> V_14 , L_13 ) ;
goto V_95;
}
V_3 = F_41 ( V_25 ) ;
if ( V_3 < 0 ) {
F_7 ( & V_6 -> V_14 , L_14 ) ;
goto V_96;
}
return 0 ;
V_96:
F_42 ( V_25 ) ;
V_95:
if ( V_2 -> V_69 )
F_43 ( V_2 -> V_69 ) ;
V_90:
F_8 ( V_2 , V_19 ) ;
return V_3 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_24 * V_25 = F_45 ( V_6 ) ;
struct V_1 * V_2 = F_12 ( V_25 ) ;
F_46 ( V_25 ) ;
F_42 ( V_25 ) ;
if ( V_2 -> V_69 )
F_43 ( V_2 -> V_69 ) ;
return F_8 ( V_2 , V_19 ) ;
}
static int F_47 ( struct V_97 * V_14 )
{
struct V_1 * V_2 ;
V_2 = F_12 ( F_45 ( F_48 ( V_14 ) ) ) ;
return F_8 ( V_2 , V_2 -> V_15 & ( ~ V_17 ) ) ;
}
static int F_49 ( struct V_97 * V_14 )
{
struct V_1 * V_2 ;
V_2 = F_12 ( F_45 ( F_48 ( V_14 ) ) ) ;
return F_8 ( V_2 , V_2 -> V_15 | V_17 ) ;
}
