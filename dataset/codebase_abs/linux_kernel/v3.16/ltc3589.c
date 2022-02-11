static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 ;
if ( F_3 ( V_3 <= 0 ) )
return - V_7 ;
V_6 = F_4 ( V_2 -> V_8 -> V_9 ) - 1 ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
if ( ( 880 << V_5 ) >= V_3 ) {
return F_5 ( V_4 -> V_10 ,
V_11 ,
0x3 << V_6 , V_5 << V_6 ) ;
}
}
return - V_7 ;
}
static int F_6 ( struct V_1 * V_2 , int V_12 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_7 ( V_2 , V_12 , V_12 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_5 ( V_4 -> V_10 , V_2 -> V_8 -> V_13 + 1 ,
V_2 -> V_8 -> V_14 , V_5 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_15 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
int V_16 , V_17 = 0 ;
V_16 = V_2 -> V_8 -> V_9 << 1 ;
if ( V_15 == V_18 )
V_17 = V_16 ;
V_16 |= V_2 -> V_8 -> V_9 ;
V_17 |= V_2 -> V_8 -> V_9 ;
return F_5 ( V_4 -> V_10 , V_19 , V_16 , V_17 ) ;
}
static int F_9 ( struct V_4 * V_4 )
{
struct V_20 * V_21 = V_4 -> V_21 ;
struct V_22 * V_23 ;
int V_24 , V_25 ;
V_23 = F_10 ( V_21 -> V_26 , L_1 ) ;
if ( ! V_23 ) {
F_11 ( V_21 , L_2 ) ;
return - V_7 ;
}
V_25 = F_12 ( V_21 , V_23 , V_27 ,
F_13 ( V_27 ) ) ;
F_14 ( V_23 ) ;
if ( V_25 < 0 ) {
F_11 ( V_21 , L_3 , V_25 ) ;
return V_25 ;
}
if ( V_25 != V_28 ) {
F_11 ( V_21 , L_4 ,
V_25 ) ;
return - V_7 ;
}
for ( V_24 = 0 ; V_24 < V_29 ; V_24 ++ ) {
struct V_30 * V_8 = & V_4 -> V_31 [ V_24 ] ;
struct V_22 * V_32 = V_27 [ V_24 ] . V_26 ;
T_1 V_33 [ 2 ] ;
V_25 = F_15 ( V_32 , L_5 ,
V_33 , 2 ) ;
if ( V_25 ) {
F_11 ( V_21 , L_6 ,
V_25 ) ;
return V_25 ;
}
V_8 -> V_34 = V_33 [ 0 ] ;
V_8 -> V_35 = V_33 [ 1 ] ;
}
return 0 ;
}
static inline struct V_36 * F_16 ( int V_37 )
{
return V_27 [ V_37 ] . V_38 ;
}
static inline struct V_22 * F_17 ( int V_37 )
{
return V_27 [ V_37 ] . V_26 ;
}
static inline int F_9 ( struct V_4 * V_4 )
{
return 0 ;
}
static inline struct V_36 * F_16 ( int V_37 )
{
return NULL ;
}
static inline struct V_22 * F_17 ( int V_37 )
{
return NULL ;
}
static bool F_18 ( struct V_20 * V_21 , unsigned int V_39 )
{
switch ( V_39 ) {
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_19 :
case V_44 :
case V_45 :
case V_46 :
case V_11 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
return true ;
}
return false ;
}
static bool F_19 ( struct V_20 * V_21 , unsigned int V_39 )
{
switch ( V_39 ) {
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_53 :
case V_19 :
case V_45 :
case V_46 :
case V_11 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
return true ;
}
return false ;
}
static bool F_20 ( struct V_20 * V_21 , unsigned int V_39 )
{
switch ( V_39 ) {
case V_40 :
case V_53 :
return true ;
}
return false ;
}
static T_2 F_21 ( int V_54 , void * V_55 )
{
struct V_4 * V_4 = V_55 ;
unsigned int V_24 , V_56 , V_57 ;
F_22 ( V_4 -> V_10 , V_40 , & V_56 ) ;
if ( V_56 & V_58 ) {
V_57 = V_59 ;
for ( V_24 = 0 ; V_24 < V_28 ; V_24 ++ )
F_23 ( V_4 -> V_60 [ V_24 ] ,
V_57 , NULL ) ;
}
if ( V_56 & V_61 ) {
V_57 = V_62 ;
for ( V_24 = 0 ; V_24 < V_28 ; V_24 ++ )
F_23 ( V_4 -> V_60 [ V_24 ] ,
V_57 , NULL ) ;
}
F_24 ( V_4 -> V_10 , V_44 , 0 ) ;
return V_63 ;
}
static inline unsigned int F_25 ( unsigned int V_12 , T_1 V_34 , T_1 V_35 )
{
T_3 V_64 ;
if ( V_12 == 0 )
return 0 ;
V_64 = ( T_3 ) V_12 * V_34 ;
F_26 ( V_64 , V_35 ) ;
return V_12 + ( unsigned int ) V_64 ;
}
static void F_27 ( struct V_30 * V_65 )
{
struct V_66 * V_8 = & V_65 -> V_8 ;
if ( ! V_65 -> V_34 || ! V_65 -> V_35 )
return;
V_8 -> V_67 = F_25 ( V_8 -> V_67 , V_65 -> V_34 , V_65 -> V_35 ) ;
V_8 -> V_68 = F_25 ( V_8 -> V_68 , V_65 -> V_34 , V_65 -> V_35 ) ;
V_8 -> V_69 = F_25 ( V_8 -> V_69 , V_65 -> V_34 , V_65 -> V_35 ) ;
}
static int F_28 ( struct V_70 * V_71 ,
const struct V_72 * V_73 )
{
struct V_20 * V_21 = & V_71 -> V_21 ;
struct V_30 * V_74 ;
struct V_4 * V_4 ;
int V_24 , V_25 ;
V_4 = F_29 ( V_21 , sizeof( * V_4 ) , V_75 ) ;
if ( ! V_4 )
return - V_76 ;
F_30 ( V_71 , V_4 ) ;
V_4 -> V_77 = V_73 -> V_78 ;
V_4 -> V_21 = V_21 ;
V_74 = V_4 -> V_31 ;
memcpy ( V_74 , V_79 , sizeof( V_79 ) ) ;
if ( V_4 -> V_77 == V_80 ) {
V_74 [ V_29 ] . V_8 . V_69 = 1800000 ;
V_74 [ V_81 ] . V_8 . V_82 = V_83 ;
} else {
V_74 [ V_29 ] . V_8 . V_69 = 2800000 ;
V_74 [ V_81 ] . V_8 . V_82 = V_84 ;
}
V_4 -> V_10 = F_31 ( V_71 , & V_85 ) ;
if ( F_32 ( V_4 -> V_10 ) ) {
V_25 = F_33 ( V_4 -> V_10 ) ;
F_11 ( V_21 , L_7 , V_25 ) ;
return V_25 ;
}
V_25 = F_9 ( V_4 ) ;
if ( V_25 )
return V_25 ;
for ( V_24 = 0 ; V_24 < V_28 ; V_24 ++ ) {
struct V_30 * V_65 = & V_4 -> V_31 [ V_24 ] ;
struct V_66 * V_8 = & V_65 -> V_8 ;
struct V_36 * V_38 ;
struct V_86 V_87 = { } ;
V_38 = F_16 ( V_24 ) ;
if ( V_24 < V_29 )
F_27 ( V_65 ) ;
V_87 . V_21 = V_21 ;
V_87 . V_38 = V_38 ;
V_87 . V_78 = V_4 ;
V_87 . V_26 = F_17 ( V_24 ) ;
V_4 -> V_60 [ V_24 ] = F_34 ( V_21 , V_8 ,
& V_87 ) ;
if ( F_32 ( V_4 -> V_60 [ V_24 ] ) ) {
V_25 = F_33 ( V_4 -> V_60 [ V_24 ] ) ;
F_11 ( V_21 , L_8 ,
V_8 -> V_88 , V_25 ) ;
return V_25 ;
}
}
V_25 = F_35 ( V_21 , V_71 -> V_54 , NULL , F_21 ,
V_89 | V_90 ,
V_71 -> V_88 , V_4 ) ;
if ( V_25 ) {
F_11 ( V_21 , L_9 , V_25 ) ;
return V_25 ;
}
return 0 ;
}
