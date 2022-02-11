static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static inline int F_4 ( struct V_1 * V_8 ,
struct V_9 * V_10 , unsigned int V_11 )
{
T_1 V_12 = V_11 >> 8 & 0xFF ;
int V_13 = 0 ;
if ( V_8 -> V_14 != V_12 && ( V_11 & 0xFF ) != 0x03 ) {
V_13 = F_5 ( V_10 , V_15 , V_12 ) ;
if ( ! V_13 )
V_8 -> V_14 = V_12 ;
}
return V_13 ;
}
static int F_6 ( struct V_2 * V_3 , T_1 V_16 )
{
struct V_9 * V_10 = F_7 ( V_3 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_13 = F_4 ( V_8 , V_10 , V_16 ) ;
if ( V_13 )
return V_13 ;
return F_8 ( V_10 , V_16 & 0xFF ) ;
}
static int F_9 ( struct V_2 * V_3 , T_1 V_16 , T_1 V_17 )
{
struct V_9 * V_10 = F_7 ( V_3 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_13 = F_4 ( V_8 , V_10 , V_16 ) ;
if ( V_13 )
return V_13 ;
return F_5 ( V_10 , V_16 & 0xFF , V_17 ) ;
}
static inline int F_10 ( struct V_2 * V_3 ,
const struct V_18 * V_19 )
{
while ( V_19 -> V_20 != V_21 ) {
int V_13 = F_9 ( V_3 , V_19 -> V_20 , V_19 -> V_17 ) ;
if ( V_13 )
return V_13 ;
V_19 ++ ;
}
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , bool V_22 , bool V_23 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_2 V_11 = V_23 ? 0xF1 : 0xF0 ;
int V_13 = 0 ;
if ( V_22 )
V_13 = F_9 ( V_3 , V_24 , V_11 | 0x02 ) ;
if ( ! V_13 ) {
V_13 = F_9 ( V_3 , V_24 , V_11 ) ;
if ( V_22 && ! V_13 )
V_8 -> V_14 = - 1 ;
}
return V_13 ;
}
static int F_12 ( struct V_2 * V_3 , int V_25 )
{
int V_13 ;
V_13 = F_9 ( V_3 , F_13 ( 1 ) , V_25 ? 0x2E : 0x2F ) ;
if ( ! V_13 )
V_13 = F_9 ( V_3 , F_13 ( 0 ) , V_25 ? 0xFB : 0x7B ) ;
return V_13 ;
}
static int F_14 ( struct V_2 * V_3 , int V_26 , int V_27 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_11 , V_13 ;
V_11 = F_6 ( V_3 , F_15 ( 1 ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 &= 0x7C ;
if ( V_26 )
V_11 |= 0x01 ;
if ( V_27 )
V_11 |= 0x02 ;
V_13 = F_9 ( V_3 , F_15 ( 1 ) , V_11 | 0x80 ) ;
if ( ! V_13 ) {
V_8 -> V_26 = V_26 ;
V_8 -> V_27 = V_27 ;
}
return V_13 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_13 ;
if ( ! V_8 -> V_28 )
return - V_29 ;
V_13 = F_9 ( V_3 , F_15 ( 0 ) , V_8 -> V_28 -> V_30 ) ;
if ( ! V_13 && V_8 -> V_31 )
V_13 = F_9 ( V_3 , F_17 ( 0 ) ,
V_8 -> V_31 -> V_32 ) ;
return V_13 ;
}
static int F_18 ( struct V_33 * V_34 )
{
unsigned int V_35 = ~ 0 ;
int V_36 = F_19 ( V_37 ) ;
const struct V_38 * V_39 = & V_37 [ 0 ] ,
* V_40 = NULL ;
while ( V_36 -- ) {
int V_41 = abs ( V_39 -> V_42 - V_34 -> V_42 )
+ abs ( V_39 -> V_43 - V_34 -> V_43 ) ;
if ( V_41 < V_35 ) {
V_35 = V_41 ;
V_40 = V_39 ;
}
V_39 ++ ;
}
if ( V_40 ) {
V_34 -> V_42 = V_40 -> V_42 ;
V_34 -> V_43 = V_40 -> V_43 ;
return 0 ;
}
return - V_29 ;
}
static int F_20 ( struct V_1 * V_8 )
{
int V_13 ;
if ( V_8 -> V_44 ) {
F_21 ( & V_8 -> V_3 , L_1 , V_45 ) ;
return 0 ;
}
if ( F_22 ( V_8 -> V_46 ) )
F_23 ( V_8 -> V_46 , 0 ) ;
if ( F_22 ( V_8 -> V_47 ) )
F_23 ( V_8 -> V_47 , 0 ) ;
V_13 = F_24 ( V_48 , V_8 -> V_49 ) ;
if ( V_13 )
return V_13 ;
if ( F_22 ( V_8 -> V_47 ) ) {
F_25 ( 50 ) ;
F_23 ( V_8 -> V_47 , 1 ) ;
}
if ( F_22 ( V_8 -> V_46 ) ) {
F_26 ( 1000 ) ;
F_23 ( V_8 -> V_46 , 1 ) ;
}
if ( F_22 ( V_8 -> V_47 ) ) {
F_26 ( 1000 ) ;
F_23 ( V_8 -> V_47 , 0 ) ;
F_25 ( 100 ) ;
F_23 ( V_8 -> V_47 , 1 ) ;
F_25 ( 20 ) ;
}
V_8 -> V_44 = 1 ;
F_27 ( 1 , V_50 , & V_8 -> V_3 , L_2 , V_45 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_8 )
{
int V_13 ;
if ( ! V_8 -> V_44 ) {
F_21 ( & V_8 -> V_3 , L_3 , V_45 ) ;
return 0 ;
}
V_13 = F_29 ( V_48 , V_8 -> V_49 ) ;
if ( V_13 )
return V_13 ;
if ( F_22 ( V_8 -> V_46 ) )
F_23 ( V_8 -> V_46 , 0 ) ;
if ( F_22 ( V_8 -> V_47 ) )
F_23 ( V_8 -> V_47 , 0 ) ;
V_8 -> V_44 = 0 ;
F_27 ( 1 , V_50 , & V_8 -> V_3 , L_4 , V_45 ) ;
return 0 ;
}
static int F_30 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
F_27 ( 1 , V_50 , V_3 , L_5 ,
V_45 , V_5 -> V_51 , V_5 -> V_17 ) ;
switch ( V_5 -> V_51 ) {
case V_52 :
return F_12 ( V_3 , V_5 -> V_17 ) ;
case V_53 :
return F_9 ( V_3 , V_54 , V_5 -> V_17 ) ;
case V_55 :
return F_9 ( V_3 , V_56 , V_5 -> V_17 ) ;
default:
return - V_29 ;
}
}
static int F_31 ( struct V_2 * V_3 , unsigned int V_57 ,
enum V_58 * V_59 )
{
if ( ! V_59 || V_57 >= F_19 ( V_60 ) )
return - V_29 ;
* V_59 = V_60 [ V_57 ] . V_59 ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , struct V_33 * V_34 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_13 ;
if ( ! V_34 )
return - V_29 ;
if ( ! V_8 -> V_28 || ! V_8 -> V_31 ) {
V_13 = F_16 ( V_3 ) ;
if ( V_13 )
return V_13 ;
}
V_34 -> V_42 = V_8 -> V_28 -> V_42 ;
V_34 -> V_43 = V_8 -> V_28 -> V_43 ;
V_34 -> V_59 = V_8 -> V_31 -> V_59 ;
V_34 -> V_61 = V_8 -> V_31 -> V_61 ;
V_34 -> V_62 = V_63 ;
return 0 ;
}
static const struct V_64 * F_33 ( struct V_2 * V_3 ,
struct V_33 * V_34 )
{
int V_36 = F_19 ( V_60 ) ;
F_18 ( V_34 ) ;
while ( V_36 -- )
if ( V_34 -> V_59 == V_60 [ V_36 ] . V_59 )
break;
V_34 -> V_59 = V_60 [ V_36 ] . V_59 ;
return & V_60 [ V_36 ] ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_33 * V_34 )
{
if ( ! V_3 || ! V_34 )
return - V_29 ;
F_33 ( V_3 , V_34 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_33 * V_34 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( ! V_3 || ! V_34 )
return - V_29 ;
V_8 -> V_31 = F_33 ( V_3 , V_34 ) ;
return F_16 ( V_3 ) ;
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_13 ;
V_13 = F_10 ( V_3 , V_65 ) ;
if ( ! V_13 ) {
V_8 -> V_31 = & V_60 [ 0 ] ;
V_8 -> V_28 = & V_37 [ 0 ] ;
V_13 = F_16 ( V_3 ) ;
}
if ( ! V_13 )
V_13 = F_14 ( V_3 , 1 , 0 ) ;
if ( ! V_13 )
V_13 = F_11 ( V_3 , false , false ) ;
F_37 ( & F_1 ( V_3 ) -> V_7 ) ;
return V_13 ;
}
static int F_38 ( struct V_2 * V_3 , int V_25 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
const struct V_66 * V_67 = V_8 -> V_67 ;
int V_13 = 0 ;
if ( F_39 ( V_67 == NULL , L_6 ) )
return - V_68 ;
if ( V_25 ) {
V_13 = F_20 ( V_8 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_36 ( V_3 ) ;
} else {
F_11 ( V_3 , false , true ) ;
V_13 = F_28 ( V_8 ) ;
V_8 -> V_28 = NULL ;
V_8 -> V_31 = NULL ;
}
return V_13 ;
}
static int F_40 ( struct V_2 * V_3 ,
struct V_69 * V_70 )
{
struct V_9 * V_10 = F_7 ( V_3 ) ;
return F_41 ( V_10 , V_70 ,
V_71 , 0 ) ;
}
static int F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_43 ( & V_8 -> V_7 , V_3 -> V_72 ) ;
return 0 ;
}
static int F_44 ( struct V_9 * V_10 , struct V_1 * V_8 )
{
int V_13 ;
V_13 = F_20 ( V_8 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_8 ( V_10 , V_73 ) ;
if ( V_13 < 0 )
F_45 ( & V_10 -> V_74 , L_7 , V_13 ) ;
F_28 ( V_8 ) ;
return V_13 == V_75 ? 0 : - V_76 ;
}
static int F_46 ( struct V_9 * V_10 ,
const struct V_77 * V_51 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
const struct V_66 * V_67
= V_10 -> V_74 . V_78 ;
int V_13 ;
int V_36 ;
if ( ! V_67 ) {
F_45 ( & V_10 -> V_74 , L_6 ) ;
return - V_79 ;
}
V_8 = F_47 ( sizeof( * V_8 ) , V_80 ) ;
if ( ! V_8 )
return - V_68 ;
V_3 = & V_8 -> V_3 ;
F_48 ( V_3 -> V_72 , V_81 , sizeof( V_3 -> V_72 ) ) ;
F_49 ( V_3 , V_10 , & V_82 ) ;
F_50 ( & V_8 -> V_7 , 3 ) ;
F_51 ( & V_8 -> V_7 , & V_83 ,
V_52 , 0 , 1 , 1 , 1 ) ;
F_51 ( & V_8 -> V_7 , & V_83 ,
V_55 , 0 , 127 , 1 , 64 ) ;
F_51 ( & V_8 -> V_7 , & V_83 ,
V_53 , 0 , 127 , 1 , 64 ) ;
V_3 -> V_84 = & V_8 -> V_7 ;
V_13 = V_8 -> V_7 . error ;
if ( V_13 )
goto V_85;
V_8 -> V_67 = V_10 -> V_74 . V_78 ;
V_8 -> V_14 = - 1 ;
V_8 -> V_47 = - V_29 ;
V_8 -> V_46 = - V_29 ;
if ( F_22 ( V_67 -> V_47 ) ) {
V_13 = F_52 ( V_67 -> V_47 , L_8 ) ;
if ( V_13 ) {
F_45 ( & V_10 -> V_74 , L_9 , V_13 ) ;
goto V_85;
}
V_8 -> V_47 = V_67 -> V_47 ;
F_53 ( V_8 -> V_47 , 0 ) ;
F_54 ( V_8 -> V_47 , 0 ) ;
}
if ( F_22 ( V_67 -> V_46 ) ) {
V_13 = F_52 ( V_67 -> V_46 , L_10 ) ;
if ( V_13 ) {
F_45 ( & V_10 -> V_74 , L_9 , V_13 ) ;
goto V_86;
}
V_8 -> V_46 = V_67 -> V_46 ;
F_53 ( V_8 -> V_46 , 0 ) ;
F_54 ( V_8 -> V_46 , 0 ) ;
}
for ( V_36 = 0 ; V_36 < V_48 ; V_36 ++ )
V_8 -> V_49 [ V_36 ] . V_49 = V_87 [ V_36 ] ;
V_13 = F_55 ( & V_10 -> V_74 , V_48 ,
V_8 -> V_49 ) ;
if ( V_13 )
goto V_88;
V_13 = F_44 ( V_10 , V_8 ) ;
if ( ! V_13 )
return 0 ;
F_56 ( V_48 , V_8 -> V_49 ) ;
V_88:
if ( F_22 ( V_8 -> V_46 ) )
F_57 ( V_8 -> V_46 ) ;
V_86:
if ( F_22 ( V_8 -> V_47 ) )
F_57 ( V_8 -> V_47 ) ;
V_85:
F_58 ( & V_8 -> V_7 ) ;
F_59 ( V_3 ) ;
F_60 ( V_8 ) ;
return V_13 ;
}
static int F_61 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_62 ( V_10 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_59 ( V_3 ) ;
F_58 ( & V_8 -> V_7 ) ;
F_56 ( V_48 , V_8 -> V_49 ) ;
if ( F_22 ( V_8 -> V_47 ) )
F_57 ( V_8 -> V_47 ) ;
if ( F_22 ( V_8 -> V_46 ) )
F_57 ( V_8 -> V_46 ) ;
F_60 ( V_8 ) ;
return 0 ;
}
static int T_3 F_63 ( void )
{
return F_64 ( & V_89 ) ;
}
static void T_4 F_65 ( void )
{
F_66 ( & V_89 ) ;
}
