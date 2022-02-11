static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
int * V_5 )
{
int V_6 ;
T_1 V_7 ;
V_6 = F_2 ( V_2 -> V_8 , V_9 , V_4 -> V_10 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 -> V_8 , V_11 , & V_7 , 2 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_5 = 32767 - ( V_12 ) F_4 ( V_7 ) ;
return V_13 ;
}
static int F_5 ( struct V_1 * V_2 ,
int * V_5 , int * V_14 )
{
int V_6 ;
unsigned int V_7 ;
F_6 ( & V_2 -> V_15 ) ;
V_6 = F_7 ( V_2 -> V_8 , V_16 , & V_7 ) ;
F_8 ( & V_2 -> V_15 ) ;
if ( V_6 < 0 )
return V_6 ;
V_7 = ( V_7 & V_17 ) >> V_18 ;
* V_5 = V_19 [ V_7 ] . V_5 ;
* V_14 = V_19 [ V_7 ] . V_14 ;
return V_20 ;
}
static int F_9 ( struct V_21 * V_22 ,
const struct V_3 * V_4 ,
int * V_5 , int * V_14 , long V_23 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
int V_6 ;
switch ( V_4 -> type ) {
case V_24 :
switch ( V_23 ) {
case V_25 :
if ( F_11 ( V_22 ) )
return - V_26 ;
F_6 ( & V_2 -> V_15 ) ;
V_6 = F_1 ( V_2 , V_4 , V_5 ) ;
F_8 ( & V_2 -> V_15 ) ;
return V_6 ;
case V_27 :
return F_5 ( V_2 , V_5 , V_14 ) ;
default:
return - V_28 ;
}
default:
return - V_28 ;
}
}
static int F_12 ( struct V_1 * V_2 ,
int V_5 , int V_14 )
{
int V_29 , V_6 ;
for ( V_29 = 0 ; V_29 < F_13 ( V_19 ) ; V_29 ++ )
if ( V_5 == V_19 [ V_29 ] . V_5 &&
V_14 == V_19 [ V_29 ] . V_14 )
break;
if ( V_29 == F_13 ( V_19 ) )
return - V_28 ;
F_6 ( & V_2 -> V_15 ) ;
V_6 = F_14 ( V_2 -> V_8 , V_16 ,
V_17 ,
V_29 << V_18 ) ;
F_8 ( & V_2 -> V_15 ) ;
return V_6 ;
}
static int F_15 ( struct V_21 * V_22 ,
const struct V_3 * V_4 ,
int V_5 , int V_14 , long V_23 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
switch ( V_4 -> type ) {
case V_24 :
switch ( V_23 ) {
case V_27 :
return F_12 ( V_2 , V_5 , V_14 ) ;
default:
return - V_28 ;
}
default:
return - V_28 ;
}
}
static T_2 F_16 ( int V_30 , void * V_31 )
{
struct V_21 * V_22 = V_31 ;
struct V_1 * V_2 = F_10 ( V_22 ) ;
if ( V_2 -> V_32 )
F_17 ( V_2 -> V_33 ) ;
return V_34 ;
}
static T_2 F_18 ( int V_30 , void * V_31 )
{
struct V_21 * V_22 = V_31 ;
struct V_1 * V_2 = F_10 ( V_22 ) ;
int V_6 ;
unsigned int V_5 , V_4 ;
F_6 ( & V_2 -> V_15 ) ;
V_6 = F_7 ( V_2 -> V_8 , V_35 , & V_5 ) ;
if ( V_6 < 0 ) {
F_19 ( & V_2 -> V_36 -> V_37 , L_1 ) ;
goto V_38;
}
if ( ! ( V_5 & ( V_39 | V_40 ) ) )
goto V_38;
V_6 = F_7 ( V_2 -> V_8 , V_41 , & V_5 ) ;
if ( V_6 < 0 ) {
F_19 ( & V_2 -> V_36 -> V_37 , L_1 ) ;
goto V_38;
}
V_5 >>= V_42 ;
for ( V_4 = 0 ; V_4 < V_43 ; V_4 ++ ) {
int V_44 ;
T_3 V_45 ;
bool V_46 = V_5 & F_20 ( V_4 ) ;
if ( ! V_2 -> V_47 [ V_4 ] )
continue;
if ( V_46 == V_2 -> V_48 [ V_4 ] )
continue;
V_44 = V_46 ? V_49 :
V_50 ;
V_45 = F_21 ( V_24 ,
V_4 ,
V_51 ,
V_44 ) ;
F_22 ( V_22 , V_45 , F_23 () ) ;
V_2 -> V_48 [ V_4 ] = V_46 ;
}
V_38:
F_8 ( & V_2 -> V_15 ) ;
return V_52 ;
}
static int F_24 ( struct V_21 * V_22 ,
const struct V_3 * V_4 ,
enum V_53 type ,
enum V_54 V_44 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
if ( V_4 -> type != V_24 || type != V_51 ||
V_44 != V_55 )
return - V_28 ;
return V_2 -> V_47 [ V_4 -> V_10 ] ;
}
static int F_25 ( struct V_21 * V_22 ,
const struct V_3 * V_4 ,
enum V_53 type ,
enum V_54 V_44 ,
int V_56 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
int V_6 , V_29 ;
bool V_57 = false ;
unsigned int V_58 ;
if ( V_4 -> type != V_24 || type != V_51 ||
V_44 != V_55 )
return - V_28 ;
F_6 ( & V_2 -> V_15 ) ;
V_2 -> V_47 [ V_4 -> V_10 ] = V_56 ;
for ( V_29 = 0 ; V_29 < V_43 ; V_29 ++ )
if ( V_2 -> V_47 [ V_29 ] ) {
V_57 = true ;
break;
}
V_58 = V_39 | V_40 ;
if ( V_57 )
V_6 = F_14 ( V_2 -> V_8 , V_59 ,
V_58 , V_58 ) ;
else
V_6 = F_14 ( V_2 -> V_8 , V_59 ,
V_58 , 0 ) ;
F_8 ( & V_2 -> V_15 ) ;
return V_6 ;
}
static int F_26 ( struct V_21 * V_22 ,
const unsigned long * V_60 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
F_6 ( & V_2 -> V_15 ) ;
F_27 ( V_2 -> V_61 ) ;
V_2 -> V_61 = F_28 ( V_22 -> V_62 , V_63 ) ;
F_8 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_61 == NULL )
return - V_64 ;
return 0 ;
}
static int F_29 ( struct V_65 * V_33 ,
bool V_56 )
{
struct V_21 * V_22 = F_30 ( V_33 ) ;
struct V_1 * V_2 = F_10 ( V_22 ) ;
int V_6 ;
F_6 ( & V_2 -> V_15 ) ;
V_6 = F_14 ( V_2 -> V_8 , V_59 ,
V_66 ,
V_56 ? V_66 : 0 ) ;
if ( V_6 == 0 )
V_2 -> V_32 = V_56 ;
F_8 ( & V_2 -> V_15 ) ;
return V_6 ;
}
static T_2 F_31 ( int V_30 , void * V_31 )
{
struct V_67 * V_68 = V_31 ;
struct V_21 * V_22 = V_68 -> V_22 ;
struct V_1 * V_2 = F_10 ( V_22 ) ;
int V_5 , V_69 , V_6 , V_29 = 0 ;
F_6 ( & V_2 -> V_15 ) ;
F_32 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_6 = F_1 ( V_2 , & V_22 -> V_70 [ V_69 ] ,
& V_5 ) ;
if ( V_6 < 0 )
goto V_38;
V_2 -> V_61 [ V_29 ++ ] = V_5 ;
}
F_33 ( V_22 , V_2 -> V_61 ,
F_23 () ) ;
V_38:
F_8 ( & V_2 -> V_15 ) ;
F_34 ( V_22 -> V_33 ) ;
return V_52 ;
}
static int F_35 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
int V_6 , V_29 ;
unsigned int V_5 ;
V_6 = F_2 ( V_2 -> V_8 , V_59 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_2 ( V_2 -> V_8 , V_71 ,
V_72 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_7 ( V_2 -> V_8 , V_35 , & V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
for ( V_29 = 0 ; V_29 < F_13 ( V_73 ) ; V_29 ++ ) {
V_6 = F_2 ( V_2 -> V_8 ,
V_73 [ V_29 ] . V_74 ,
V_73 [ V_29 ] . V_75 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_36 ( struct V_76 * V_36 ,
struct V_1 * V_2 )
{
struct V_77 * V_37 ;
struct V_78 * V_79 ;
int V_6 ;
if ( ! V_36 )
return - V_28 ;
V_37 = & V_36 -> V_37 ;
V_79 = F_37 ( V_37 , V_80 , 0 , V_81 ) ;
if ( F_38 ( V_79 ) ) {
F_19 ( V_37 , L_2 ) ;
return F_39 ( V_79 ) ;
}
V_6 = F_40 ( V_79 ) ;
F_41 ( V_37 , L_3 , F_42 ( V_79 ) , V_6 ) ;
return V_6 ;
}
static int F_43 ( struct V_76 * V_36 ,
const struct V_82 * V_83 )
{
int V_6 ;
struct V_21 * V_22 ;
struct V_1 * V_2 ;
V_22 = F_44 ( & V_36 -> V_37 , sizeof( * V_2 ) ) ;
if ( V_22 == NULL )
return - V_64 ;
V_2 = F_10 ( V_22 ) ;
V_2 -> V_36 = V_36 ;
F_45 ( & V_2 -> V_15 ) ;
V_2 -> V_32 = false ;
V_2 -> V_8 = F_46 ( V_36 , & V_84 ) ;
if ( F_38 ( V_2 -> V_8 ) )
return F_39 ( V_2 -> V_8 ) ;
F_35 ( V_22 ) ;
V_22 -> V_37 . V_85 = & V_36 -> V_37 ;
V_22 -> V_86 = V_87 ;
V_22 -> V_70 = V_88 ;
V_22 -> V_89 = F_13 ( V_88 ) ;
V_22 -> V_90 = & V_91 ;
V_22 -> V_92 = V_93 ;
F_47 ( V_36 , V_22 ) ;
if ( V_36 -> V_30 <= 0 )
V_36 -> V_30 = F_36 ( V_36 , V_2 ) ;
if ( V_36 -> V_30 > 0 ) {
V_6 = F_48 ( & V_36 -> V_37 , V_36 -> V_30 ,
F_16 , F_18 ,
V_94 | V_95 ,
V_96 , V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
V_2 -> V_33 = F_49 ( & V_36 -> V_37 ,
L_4 , V_22 -> V_86 , V_22 -> V_83 ) ;
if ( ! V_2 -> V_33 )
return - V_64 ;
V_2 -> V_33 -> V_37 . V_85 = & V_36 -> V_37 ;
V_2 -> V_33 -> V_97 = & V_98 ;
F_50 ( V_2 -> V_33 , V_22 ) ;
V_6 = F_51 ( V_2 -> V_33 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_52 ( V_22 , NULL ,
F_31 , NULL ) ;
if ( V_6 < 0 )
goto V_99;
V_6 = F_53 ( V_22 ) ;
if ( V_6 < 0 )
goto V_100;
return 0 ;
V_100:
F_54 ( V_22 ) ;
V_99:
if ( V_36 -> V_30 > 0 )
F_55 ( V_2 -> V_33 ) ;
return V_6 ;
}
static int F_56 ( struct V_76 * V_36 )
{
struct V_21 * V_22 = F_57 ( V_36 ) ;
struct V_1 * V_2 = F_10 ( V_22 ) ;
F_58 ( V_22 ) ;
F_54 ( V_22 ) ;
if ( V_36 -> V_30 > 0 )
F_55 ( V_2 -> V_33 ) ;
F_27 ( V_2 -> V_61 ) ;
return 0 ;
}
