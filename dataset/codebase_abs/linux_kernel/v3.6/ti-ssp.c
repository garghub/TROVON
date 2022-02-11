static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static inline int F_3 ( struct V_2 * V_3 )
{
return F_4 ( V_3 ) -> V_5 ;
}
static inline T_1 F_5 ( struct V_1 * V_6 , int V_7 )
{
return F_6 ( V_6 -> V_8 + V_7 ) ;
}
static inline void F_7 ( struct V_1 * V_6 , int V_7 , T_1 V_9 )
{
F_8 ( V_9 , V_6 -> V_8 + V_7 ) ;
}
static inline void F_9 ( struct V_1 * V_6 , int V_7 , T_1 V_10 , T_1 V_11 )
{
F_7 ( V_6 , V_7 , ( F_5 ( V_6 , V_7 ) & ~ V_10 ) | V_11 ) ;
}
static inline T_1 F_10 ( struct V_1 * V_6 , int V_12 , int V_7 )
{
return F_5 ( V_6 , V_13 [ V_12 ] + V_7 ) ;
}
static inline void F_11 ( struct V_1 * V_6 , int V_12 , int V_7 ,
T_1 V_9 )
{
F_7 ( V_6 , V_13 [ V_12 ] + V_7 , V_9 ) ;
}
static inline void F_12 ( struct V_1 * V_6 , int V_12 , int V_7 ,
T_1 V_10 , T_1 V_11 )
{
F_9 ( V_6 , V_13 [ V_12 ] + V_7 , V_10 , V_11 ) ;
}
static inline void F_13 ( struct V_1 * V_6 , int V_12 , int V_7 ,
T_1 V_11 )
{
F_12 ( V_6 , V_12 , V_7 , V_11 , 0 ) ;
}
static inline void F_14 ( struct V_1 * V_6 , int V_12 , int V_7 ,
T_1 V_11 )
{
F_12 ( V_6 , V_12 , V_7 , 0 , V_11 ) ;
}
static int F_15 ( struct V_1 * V_6 , int V_12 , int V_14 )
{
V_14 &= V_15 ;
F_12 ( V_6 , V_12 , V_16 , V_15 , V_14 ) ;
return 0 ;
}
int F_16 ( struct V_2 * V_3 , int V_14 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_12 = F_3 ( V_3 ) ;
int V_17 ;
F_17 ( & V_6 -> V_18 ) ;
V_17 = F_15 ( V_6 , V_12 , V_14 ) ;
F_18 ( & V_6 -> V_18 ) ;
return V_17 ;
}
static void F_19 ( struct V_1 * V_6 , T_1 V_10 , T_1 V_9 )
{
V_6 -> V_19 = ( V_6 -> V_19 & ~ V_10 ) | V_9 ;
F_7 ( V_6 , V_20 , V_6 -> V_19 ) ;
}
static void F_20 ( struct V_1 * V_6 , int V_12 , T_1 V_21 )
{
unsigned V_9 , V_22 = V_12 ? 16 : 0 ;
V_9 = F_5 ( V_6 , V_23 ) ;
V_9 &= 0xffff << ( V_12 ? 0 : 16 ) ;
V_9 |= ( V_21 & 0xffff ) << ( V_12 ? 16 : 0 ) ;
F_7 ( V_6 , V_23 , V_9 ) ;
V_9 = ( V_21 >> 16 ) & 0x7 ;
F_19 ( V_6 , 0x7 << V_22 , V_9 << V_22 ) ;
}
int F_21 ( struct V_2 * V_3 , T_1 V_21 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_12 = F_3 ( V_3 ) ;
F_17 ( & V_6 -> V_18 ) ;
F_20 ( V_6 , V_12 , V_21 ) ;
F_18 ( & V_6 -> V_18 ) ;
return 0 ;
}
int F_22 ( struct V_2 * V_3 , int V_24 , T_1 * V_25 , int V_26 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_12 = F_3 ( V_3 ) ;
int V_27 ;
if ( V_26 > V_28 )
return - V_29 ;
F_17 ( & V_6 -> V_18 ) ;
F_14 ( V_6 , V_12 , V_30 , V_31 ) ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
F_8 ( V_25 [ V_27 ] , V_6 -> V_8 + V_24 + 4 * V_27 +
V_32 [ V_12 ] ) ;
}
F_13 ( V_6 , V_12 , V_30 , V_31 ) ;
F_18 ( & V_6 -> V_18 ) ;
return 0 ;
}
int F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_12 = F_3 ( V_3 ) ;
int V_22 = V_12 ? 27 : 11 ;
return ( F_5 ( V_6 , V_20 ) >> V_22 ) & 0xf ;
}
int F_24 ( struct V_2 * V_3 , T_1 V_9 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_12 = F_3 ( V_3 ) , V_22 ;
F_17 ( & V_6 -> V_18 ) ;
V_22 = V_12 ? 22 : 6 ;
V_9 &= 0xf ;
F_19 ( V_6 , 0xf << V_22 , V_9 << V_22 ) ;
F_18 ( & V_6 -> V_18 ) ;
return 0 ;
}
static inline int F_25 ( struct V_1 * V_6 , int V_12 )
{
return ! ( F_10 ( V_6 , V_12 , V_16 ) & V_33 ) ;
}
int F_26 ( struct V_2 * V_3 , T_1 V_34 , T_1 V_35 , T_1 * V_36 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_12 = F_3 ( V_3 ) ;
int V_17 ;
if ( V_34 & ~ ( 0x3f ) )
return - V_37 ;
F_17 ( & V_6 -> V_18 ) ;
F_11 ( V_6 , V_12 , V_38 , V_35 >> 16 ) ;
F_11 ( V_6 , V_12 , V_39 , V_35 & 0xffff ) ;
F_12 ( V_6 , V_12 , V_16 , 0x3f , V_34 ) ;
F_27 ( & V_6 -> V_40 . V_18 ) ;
F_14 ( V_6 , V_12 , V_16 , V_41 ) ;
F_18 ( & V_6 -> V_18 ) ;
V_17 = F_28 ( V_6 -> V_40 ,
F_25 ( V_6 , V_12 ) ) ;
F_29 ( & V_6 -> V_40 . V_18 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_36 ) {
* V_36 = ( F_10 ( V_6 , V_12 , V_38 ) << 16 ) |
( F_10 ( V_6 , V_12 , V_39 ) & 0xffff ) ;
}
V_17 = F_10 ( V_6 , V_12 , V_42 ) & 0x3f ;
return V_17 ;
}
static T_2 F_30 ( int V_43 , void * V_44 )
{
struct V_1 * V_6 = V_44 ;
F_17 ( & V_6 -> V_40 . V_18 ) ;
F_7 ( V_6 , V_45 , 0x3 ) ;
F_31 ( & V_6 -> V_40 ) ;
F_18 ( & V_6 -> V_40 . V_18 ) ;
return V_46 ;
}
static int T_3 F_32 ( struct V_47 * V_48 )
{
static struct V_1 * V_6 ;
const struct V_49 * V_50 = V_48 -> V_3 . V_51 ;
int error = 0 , V_52 = 0xff , V_5 ;
unsigned long V_53 ;
struct V_2 * V_3 = & V_48 -> V_3 ;
struct V_54 V_55 [ 2 ] ;
V_6 = F_33 ( sizeof( * V_6 ) , V_56 ) ;
if ( ! V_6 ) {
F_34 ( V_3 , L_1 ) ;
return - V_57 ;
}
V_6 -> V_3 = V_3 ;
F_35 ( V_3 , V_6 ) ;
V_6 -> V_58 = F_36 ( V_48 , V_59 , 0 ) ;
if ( ! V_6 -> V_58 ) {
error = - V_60 ;
F_34 ( V_3 , L_2 ) ;
goto V_61;
}
if ( ! F_37 ( V_6 -> V_58 -> V_62 , F_38 ( V_6 -> V_58 ) ,
V_48 -> V_63 ) ) {
error = - V_57 ;
F_34 ( V_3 , L_3 ) ;
goto V_61;
}
V_6 -> V_8 = F_39 ( V_6 -> V_58 -> V_62 , F_38 ( V_6 -> V_58 ) ) ;
if ( ! V_6 -> V_8 ) {
error = - V_57 ;
F_34 ( V_3 , L_4 ) ;
goto V_64;
}
V_6 -> V_65 = F_40 ( V_3 , NULL ) ;
if ( F_41 ( V_6 -> V_65 ) ) {
error = F_42 ( V_6 -> V_65 ) ;
F_34 ( V_3 , L_5 ) ;
goto V_66;
}
V_6 -> V_43 = F_43 ( V_48 , 0 ) ;
if ( V_6 -> V_43 < 0 ) {
error = - V_60 ;
F_34 ( V_3 , L_6 ) ;
goto V_67;
}
error = F_44 ( V_6 -> V_43 , NULL , F_30 , 0 ,
F_45 ( V_3 ) , V_6 ) ;
if ( error < 0 ) {
F_34 ( V_3 , L_7 ) ;
goto V_67;
}
F_46 ( & V_6 -> V_18 ) ;
F_47 ( & V_6 -> V_40 ) ;
error = F_48 ( V_6 -> V_65 ) ;
if ( error ) {
F_34 ( V_3 , L_8 ) ;
goto V_68;
}
F_7 ( V_6 , V_23 , 0 ) ;
F_7 ( V_6 , V_20 , 0 ) ;
F_7 ( V_6 , V_69 , 0x3 ) ;
F_7 ( V_6 , V_45 , 0x3 ) ;
F_7 ( V_6 , V_70 , 0 ) ;
F_11 ( V_6 , 0 , V_16 , V_71 ) ;
F_11 ( V_6 , 1 , V_16 , V_71 ) ;
F_11 ( V_6 , 0 , V_30 , V_72 ) ;
F_11 ( V_6 , 1 , V_30 , V_72 ) ;
V_53 = F_49 ( V_6 -> V_65 ) ;
if ( V_50 && V_50 -> V_73 )
V_52 = ( V_53 / V_50 -> V_73 ) - 1 ;
V_52 = F_50 ( V_52 , 0 , 0xff ) ;
F_9 ( V_6 , V_74 , 0xff , V_52 ) ;
memset ( V_55 , 0 , sizeof( V_55 ) ) ;
for ( V_5 = 0 ; V_5 < 2 ; V_5 ++ ) {
const struct V_75 * V_76 = & V_50 -> V_44 [ V_5 ] ;
V_55 [ V_5 ] . V_5 = V_5 ;
V_55 [ V_5 ] . V_63 = V_76 -> F_45 ;
V_55 [ V_5 ] . V_51 = V_76 -> V_50 ;
V_55 [ V_5 ] . V_77 = V_76 -> V_78 ;
}
error = F_51 ( V_3 , 0 , V_55 , 2 , NULL , 0 , NULL ) ;
if ( error < 0 ) {
F_34 ( V_3 , L_9 ) ;
goto V_68;
}
return 0 ;
V_68:
F_52 ( V_6 -> V_43 , V_6 ) ;
V_67:
F_53 ( V_6 -> V_65 ) ;
V_66:
F_54 ( V_6 -> V_8 ) ;
V_64:
F_55 ( V_6 -> V_58 -> V_62 , F_38 ( V_6 -> V_58 ) ) ;
V_61:
F_56 ( V_6 ) ;
return error ;
}
static int T_4 F_57 ( struct V_47 * V_48 )
{
struct V_2 * V_3 = & V_48 -> V_3 ;
struct V_1 * V_6 = F_2 ( V_3 ) ;
F_58 ( V_3 ) ;
F_59 ( V_6 -> V_65 ) ;
F_52 ( V_6 -> V_43 , V_6 ) ;
F_53 ( V_6 -> V_65 ) ;
F_54 ( V_6 -> V_8 ) ;
F_55 ( V_6 -> V_58 -> V_62 , F_38 ( V_6 -> V_58 ) ) ;
F_56 ( V_6 ) ;
F_35 ( V_3 , NULL ) ;
return 0 ;
}
