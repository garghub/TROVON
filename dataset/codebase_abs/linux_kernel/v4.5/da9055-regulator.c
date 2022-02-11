static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 , V_8 = 0 ;
V_7 = F_3 ( V_4 -> V_9 , V_6 -> V_8 . V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( ( V_7 & V_6 -> V_8 . V_11 ) >> V_6 -> V_8 . V_12 ) {
case V_13 :
V_8 = V_14 ;
break;
case V_15 :
V_8 = V_16 ;
break;
case V_17 :
V_8 = V_18 ;
break;
}
return V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_19 = 0 ;
switch ( V_8 ) {
case V_14 :
V_19 = V_13 << V_6 -> V_8 . V_12 ;
break;
case V_16 :
V_19 = V_15 << V_6 -> V_8 . V_12 ;
break;
case V_18 :
V_19 = V_17 << V_6 -> V_8 . V_12 ;
break;
}
return F_5 ( V_4 -> V_9 , V_6 -> V_8 . V_10 ,
V_6 -> V_8 . V_11 , V_19 ) ;
}
static unsigned int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 ;
V_7 = F_3 ( V_4 -> V_9 , V_6 -> V_20 . V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 >> V_6 -> V_20 . V_22 )
return V_18 ;
else
return V_16 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_23 V_20 = V_6 -> V_20 ;
int V_19 = 0 ;
switch ( V_8 ) {
case V_16 :
case V_14 :
V_19 = V_24 ;
break;
case V_18 :
V_19 = V_25 ;
break;
}
return F_5 ( V_4 -> V_9 , V_20 . V_21 ,
1 << V_20 . V_22 ,
V_19 << V_20 . V_22 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 ;
V_7 = F_3 ( V_4 -> V_9 , V_26 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 &= V_6 -> V_8 . V_11 ;
return V_27 [ V_7 >> V_6 -> V_8 . V_12 ] ;
}
static int F_9 ( struct V_1 * V_2 , int V_28 ,
int V_29 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_30 ;
for ( V_30 = F_10 ( V_27 ) - 1 ; V_30 >= 0 ; V_30 -- ) {
if ( ( V_28 <= V_27 [ V_30 ] ) &&
( V_27 [ V_30 ] <= V_29 ) )
return F_5 ( V_4 -> V_9 ,
V_26 ,
V_6 -> V_8 . V_11 ,
V_30 << V_6 -> V_8 . V_12 ) ;
}
return - V_31 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_23 V_20 = V_6 -> V_20 ;
int V_7 , V_32 ;
V_7 = F_3 ( V_4 -> V_9 , V_6 -> V_33 . V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 &= V_6 -> V_33 . V_34 ;
if ( V_7 == V_35 )
V_7 = F_3 ( V_4 -> V_9 , V_20 . V_36 ) ;
else
V_7 = F_3 ( V_4 -> V_9 , V_20 . V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_32 = ( V_7 & V_20 . V_37 ) ;
return V_32 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 ;
if ( V_4 -> V_39 == V_40 ) {
V_7 = F_5 ( V_4 -> V_9 , V_6 -> V_33 . V_10 ,
V_6 -> V_33 . V_34 , V_41 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_5 ( V_4 -> V_9 , V_6 -> V_20 . V_36 ,
V_6 -> V_20 . V_37 , V_38 ) ;
}
V_7 = F_3 ( V_4 -> V_9 , V_6 -> V_33 . V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 &= V_6 -> V_33 . V_34 ;
if ( V_7 == V_35 )
return F_5 ( V_4 -> V_9 , V_6 -> V_20 . V_36 ,
V_6 -> V_20 . V_37 , V_38 ) ;
else
return F_5 ( V_4 -> V_9 , V_6 -> V_20 . V_21 ,
V_6 -> V_20 . V_37 , V_38 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_42 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 ;
if ( V_4 -> V_39 == V_40 ) {
V_7 = F_5 ( V_4 -> V_9 , V_6 -> V_33 . V_10 ,
V_6 -> V_33 . V_34 , V_43 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_14 ( V_2 , V_42 , V_42 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_5 ( V_4 -> V_9 , V_6 -> V_20 . V_21 ,
V_6 -> V_20 . V_37 , V_7 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_4 -> V_39 == V_40 )
return F_5 ( V_4 -> V_9 , V_6 -> V_33 . V_10 ,
V_6 -> V_33 . V_34 , V_43 ) ;
else
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_4 -> V_39 == V_40 )
return F_5 ( V_4 -> V_9 , V_6 -> V_33 . V_10 ,
V_6 -> V_33 . V_34 , V_41 ) ;
else
return 0 ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_44 * V_45 ,
struct V_46 * V_47 , int V_48 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = 0 ;
if ( ! V_47 )
return 0 ;
if ( V_47 -> V_49 && V_47 -> V_49 [ V_48 ] ) {
char V_50 [ 18 ] ;
int V_51 = V_47 -> V_49 [ V_48 ] ;
V_45 -> V_52 = V_47 -> V_52 [ V_48 ] ;
V_45 -> V_53 = V_54 ;
V_45 -> V_55 = 1 ;
sprintf ( V_50 , L_1 , V_51 ) ;
V_7 = F_18 ( V_45 -> V_56 , V_51 , V_57 ,
V_50 ) ;
if ( V_7 < 0 )
goto V_58;
V_7 = F_5 ( V_4 -> V_9 , V_6 -> V_33 . V_10 ,
V_59 ,
V_47 -> V_60 [ V_48 ]
<< V_61 ) ;
if ( V_7 < 0 )
goto V_58;
}
if ( V_47 -> V_62 && V_47 -> V_62 [ V_48 ] ) {
char V_50 [ 18 ] ;
int V_51 = V_47 -> V_62 [ V_48 ] ;
V_4 -> V_39 = V_47 -> V_63 [ V_48 ] ;
sprintf ( V_50 , L_1 , V_51 ) ;
V_7 = F_18 ( V_45 -> V_56 , V_51 , V_57 ,
V_50 ) ;
if ( V_7 < 0 )
goto V_58;
V_7 = F_5 ( V_4 -> V_9 , V_6 -> V_33 . V_10 ,
V_64 ,
V_47 -> V_63 [ V_48 ]
<< V_65 ) ;
}
V_58:
return V_7 ;
}
static T_1 F_19 ( int V_66 , void * V_67 )
{
struct V_3 * V_4 = V_67 ;
F_20 ( V_4 -> V_2 ,
V_68 , NULL ) ;
return V_69 ;
}
static inline struct V_5 * F_21 ( int V_48 )
{
struct V_5 * V_6 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < F_10 ( V_5 ) ; V_30 ++ ) {
V_6 = & V_5 [ V_30 ] ;
if ( V_6 -> V_70 . V_48 == V_48 )
return V_6 ;
}
return NULL ;
}
static int F_22 ( struct V_71 * V_72 ,
struct V_3 * V_4 ,
struct V_44 * V_45 ,
int V_73 )
{
struct V_74 * V_75 , * V_76 ;
int V_7 ;
V_75 = F_23 ( V_72 -> V_56 . V_77 -> V_78 ) ;
if ( ! V_75 )
return - V_79 ;
V_76 = F_24 ( V_75 , L_2 ) ;
if ( ! V_76 )
return - V_79 ;
V_7 = F_25 ( & V_72 -> V_56 , V_76 , & V_80 [ V_73 ] , 1 ) ;
F_26 ( V_75 ) ;
if ( V_7 < 0 ) {
F_27 ( & V_72 -> V_56 , L_3 , V_7 ) ;
return V_7 ;
}
V_45 -> V_81 = V_80 [ V_73 ] . V_81 ;
V_45 -> V_78 = V_80 [ V_73 ] . V_78 ;
if ( ! V_45 -> V_78 )
return - V_79 ;
return 0 ;
}
static inline int F_22 ( struct V_71 * V_72 ,
struct V_3 * V_4 ,
struct V_44 * V_45 ,
int V_73 )
{
return - V_79 ;
}
static int F_28 ( struct V_71 * V_72 )
{
struct V_44 V_45 = { } ;
struct V_3 * V_4 ;
struct V_9 * V_9 = F_29 ( V_72 -> V_56 . V_77 ) ;
struct V_46 * V_47 = F_30 ( V_9 -> V_56 ) ;
int V_7 , V_66 ;
V_4 = F_31 ( & V_72 -> V_56 , sizeof( struct V_3 ) ,
V_82 ) ;
if ( ! V_4 )
return - V_83 ;
V_4 -> V_6 = F_21 ( V_72 -> V_48 ) ;
if ( V_4 -> V_6 == NULL ) {
F_27 ( & V_72 -> V_56 , L_4 ) ;
return - V_31 ;
}
V_4 -> V_9 = V_9 ;
V_45 . V_56 = & V_72 -> V_56 ;
V_45 . V_84 = V_4 ;
V_45 . V_85 = V_9 -> V_85 ;
if ( V_47 && V_47 -> V_86 ) {
V_45 . V_81 = V_47 -> V_86 [ V_72 -> V_48 ] ;
} else {
V_7 = F_22 ( V_72 , V_4 , & V_45 ,
V_72 -> V_48 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_17 ( V_4 , & V_45 , V_47 , V_72 -> V_48 ) ;
if ( V_7 < 0 )
return V_7 ;
V_4 -> V_2 = F_32 ( & V_72 -> V_56 ,
& V_4 -> V_6 -> V_70 ,
& V_45 ) ;
if ( F_33 ( V_4 -> V_2 ) ) {
F_27 ( & V_72 -> V_56 , L_5 ,
V_4 -> V_6 -> V_70 . V_50 ) ;
return F_34 ( V_4 -> V_2 ) ;
}
if ( V_72 -> V_48 == V_87 || V_72 -> V_48 == V_88 ) {
V_66 = F_35 ( V_72 , L_6 ) ;
if ( V_66 < 0 )
return V_66 ;
V_7 = F_36 ( & V_72 -> V_56 , V_66 , NULL ,
F_19 ,
V_89 |
V_90 |
V_91 ,
V_72 -> V_50 , V_4 ) ;
if ( V_7 != 0 ) {
if ( V_7 != - V_92 ) {
F_27 ( & V_72 -> V_56 ,
L_7 ,
V_66 , V_7 ) ;
return V_7 ;
}
}
}
F_37 ( V_72 , V_4 ) ;
return 0 ;
}
static int T_2 F_38 ( void )
{
return F_39 ( & V_93 ) ;
}
static void T_3 F_40 ( void )
{
F_41 ( & V_93 ) ;
}
