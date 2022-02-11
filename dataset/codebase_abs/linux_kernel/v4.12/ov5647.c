static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , T_1 V_4 , T_2 V_5 )
{
int V_6 ;
unsigned char V_7 [ 3 ] = { V_4 >> 8 , V_4 & 0xff , V_5 } ;
struct V_8 * V_9 = F_4 ( V_3 ) ;
V_6 = F_5 ( V_9 , V_7 , 3 ) ;
if ( V_6 < 0 )
F_6 ( & V_9 -> V_10 , L_1 ,
V_11 , V_4 ) ;
return V_6 ;
}
static int F_7 ( struct V_2 * V_3 , T_1 V_4 , T_2 * V_5 )
{
int V_6 ;
unsigned char V_12 [ 2 ] = { V_4 >> 8 , V_4 & 0xff } ;
struct V_8 * V_9 = F_4 ( V_3 ) ;
V_6 = F_5 ( V_9 , V_12 , 2 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_9 -> V_10 , L_1 ,
V_11 , V_4 ) ;
return V_6 ;
}
V_6 = F_8 ( V_9 , V_5 , 1 ) ;
if ( V_6 < 0 )
F_6 ( & V_9 -> V_10 , L_2 ,
V_11 , V_4 ) ;
return V_6 ;
}
static int F_9 ( struct V_2 * V_3 ,
struct V_13 * V_14 , int V_15 )
{
int V_16 , V_6 ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ ) {
V_6 = F_3 ( V_3 , V_14 [ V_16 ] . V_17 , V_14 [ V_16 ] . V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , int V_18 )
{
T_2 V_19 ;
int V_6 ;
V_6 = F_7 ( V_3 , 0x4814 , & V_19 ) ;
if ( V_6 < 0 )
return V_6 ;
V_19 &= ~ ( 3 << 6 ) ;
return F_3 ( V_3 , 0x4814 , V_19 | ( V_18 << 6 ) ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
int V_6 ;
V_6 = F_3 ( V_3 , 0x4202 , 0x00 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_3 ( V_3 , 0x300D , 0x00 ) ;
}
static int F_12 ( struct V_2 * V_3 )
{
int V_6 ;
V_6 = F_3 ( V_3 , 0x4202 , 0x0f ) ;
if ( V_6 < 0 )
return V_6 ;
return F_3 ( V_3 , 0x300D , 0x01 ) ;
}
static int F_13 ( struct V_2 * V_3 , bool V_20 )
{
int V_6 ;
T_2 V_21 ;
V_6 = F_7 ( V_3 , 0x0100 , & V_21 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_20 )
V_21 &= ~ 0x01 ;
else
V_21 |= 0x01 ;
return F_3 ( V_3 , 0x0100 , V_21 ) ;
}
static int F_14 ( struct V_2 * V_3 )
{
int V_6 ;
T_2 V_22 , V_21 ;
struct V_8 * V_9 = F_4 ( V_3 ) ;
V_6 = F_7 ( V_3 , 0x0100 , & V_21 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_9 ( V_3 , V_23 ,
F_15 ( V_23 ) ) ;
if ( V_6 < 0 ) {
F_16 ( & V_9 -> V_10 , L_3 ) ;
return V_6 ;
}
V_6 = F_10 ( V_3 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_7 ( V_3 , 0x0100 , & V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! ( V_22 & 0x01 ) ) {
F_16 ( & V_9 -> V_10 , L_4 ) ;
V_6 = F_3 ( V_3 , 0x0100 , 0x01 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return F_3 ( V_3 , 0x4800 , 0x04 ) ;
}
static int F_17 ( struct V_2 * V_3 , int V_24 )
{
int V_6 = 0 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_8 * V_9 = F_4 ( V_3 ) ;
F_18 ( & V_1 -> V_25 ) ;
if ( V_24 && ! V_1 -> V_26 ) {
F_6 ( & V_9 -> V_10 , L_5 ) ;
V_6 = F_19 ( V_1 -> V_27 ) ;
if ( V_6 < 0 ) {
F_16 ( & V_9 -> V_10 , L_6 ) ;
goto V_28;
}
V_6 = F_9 ( V_3 , V_29 ,
F_15 ( V_29 ) ) ;
if ( V_6 < 0 ) {
F_20 ( V_1 -> V_27 ) ;
F_16 ( & V_9 -> V_10 ,
L_7 ) ;
goto V_28;
}
V_6 = F_14 ( V_3 ) ;
if ( V_6 < 0 ) {
F_20 ( V_1 -> V_27 ) ;
F_16 ( & V_9 -> V_10 ,
L_8 ) ;
goto V_28;
}
} else if ( ! V_24 && V_1 -> V_26 == 1 ) {
F_6 ( & V_9 -> V_10 , L_9 ) ;
V_6 = F_9 ( V_3 , V_30 ,
F_15 ( V_30 ) ) ;
if ( V_6 < 0 )
F_6 ( & V_9 -> V_10 , L_10 ) ;
V_6 = F_13 ( V_3 , true ) ;
if ( V_6 < 0 )
F_6 ( & V_9 -> V_10 , L_11 ) ;
F_20 ( V_1 -> V_27 ) ;
}
V_1 -> V_26 += V_24 ? 1 : - 1 ;
F_21 ( V_1 -> V_26 < 0 ) ;
V_28:
F_22 ( & V_1 -> V_25 ) ;
return V_6 ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_31 * V_4 )
{
T_2 V_5 ;
int V_6 ;
V_6 = F_7 ( V_3 , V_4 -> V_4 & 0xff , & V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_32 = 1 ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 ,
const struct V_31 * V_4 )
{
return F_3 ( V_3 , V_4 -> V_4 & 0xff , V_4 -> V_5 & 0xff ) ;
}
static int F_25 ( struct V_2 * V_3 , int V_33 )
{
if ( V_33 )
return F_11 ( V_3 ) ;
else
return F_12 ( V_3 ) ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_34 * V_35 ,
struct V_36 * V_37 )
{
if ( V_37 -> V_38 > 0 )
return - V_39 ;
V_37 -> V_37 = V_40 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 )
{
T_2 V_41 ;
int V_6 ;
struct V_8 * V_9 = F_4 ( V_3 ) ;
V_6 = F_3 ( V_3 , V_42 , 0x01 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_7 ( V_3 , V_43 , & V_41 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_41 != 0x56 ) {
F_16 ( & V_9 -> V_10 , L_12 , V_41 ) ;
return - V_44 ;
}
V_6 = F_7 ( V_3 , V_45 , & V_41 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_41 != 0x47 ) {
F_16 ( & V_9 -> V_10 , L_13 , V_41 ) ;
return - V_44 ;
}
return F_3 ( V_3 , V_42 , 0x00 ) ;
}
static int F_28 ( struct V_2 * V_3 , struct V_46 * V_47 )
{
struct V_48 * V_49 =
F_29 ( V_3 , V_47 -> V_50 , 0 ) ;
struct V_51 * V_52 =
F_30 ( V_3 , V_47 -> V_50 , 0 ) ;
V_52 -> V_53 = V_54 ;
V_52 -> V_55 = V_56 ;
V_52 -> V_57 = V_58 ;
V_52 -> V_59 = V_60 ;
V_49 -> V_37 = V_40 ;
V_49 -> V_57 = V_58 ;
V_49 -> V_59 = V_60 ;
V_49 -> V_61 = V_62 ;
V_49 -> V_63 = V_64 ;
return 0 ;
}
static int F_31 ( struct V_65 * V_66 )
{
struct V_67 V_68 ;
struct V_65 * V_69 ;
int V_6 ;
V_69 = F_32 ( V_66 , NULL ) ;
if ( ! V_69 )
return - V_39 ;
V_6 = F_33 ( V_69 , & V_68 ) ;
F_34 ( V_69 ) ;
return V_6 ;
}
static int F_35 ( struct V_8 * V_9 ,
const struct V_70 * V_71 )
{
struct V_72 * V_10 = & V_9 -> V_10 ;
struct V_1 * V_73 ;
int V_6 ;
struct V_2 * V_3 ;
struct V_65 * V_66 = V_9 -> V_10 . V_74 ;
T_3 V_75 ;
V_73 = F_36 ( V_10 , sizeof( * V_73 ) , V_76 ) ;
if ( ! V_73 )
return - V_77 ;
if ( F_37 ( V_78 ) && V_66 ) {
V_6 = F_31 ( V_66 ) ;
if ( V_6 ) {
F_16 ( V_10 , L_14 , V_6 ) ;
return V_6 ;
}
}
V_73 -> V_27 = F_38 ( V_10 , NULL ) ;
if ( F_39 ( V_73 -> V_27 ) ) {
F_16 ( V_10 , L_15 ) ;
return F_40 ( V_73 -> V_27 ) ;
}
V_75 = F_41 ( V_73 -> V_27 ) ;
if ( V_75 != 25000000 ) {
F_16 ( V_10 , L_16 , V_75 ) ;
return - V_39 ;
}
F_42 ( & V_73 -> V_25 ) ;
V_3 = & V_73 -> V_3 ;
F_43 ( V_3 , V_9 , & V_79 ) ;
V_73 -> V_3 . V_80 = & V_81 ;
V_73 -> V_3 . V_82 |= V_83 ;
V_73 -> V_50 . V_82 = V_84 ;
V_3 -> V_85 . V_86 = V_87 ;
V_6 = F_44 ( & V_3 -> V_85 , 1 , & V_73 -> V_50 ) ;
if ( V_6 < 0 )
goto V_88;
V_6 = F_27 ( V_3 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_45 ( V_3 ) ;
if ( V_6 < 0 )
goto error;
F_6 ( V_10 , L_17 ) ;
return 0 ;
error:
F_46 ( & V_3 -> V_85 ) ;
V_88:
F_47 ( & V_73 -> V_25 ) ;
return V_6 ;
}
static int F_48 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_49 ( V_9 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_50 ( & V_1 -> V_3 ) ;
F_46 ( & V_1 -> V_3 . V_85 ) ;
F_51 ( V_3 ) ;
F_47 ( & V_1 -> V_25 ) ;
return 0 ;
}
