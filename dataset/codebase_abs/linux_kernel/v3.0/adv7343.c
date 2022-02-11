static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static inline int F_4 ( struct V_2 * V_3 , T_1 V_8 , T_1 V_9 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_6 ( V_11 , V_8 , V_9 ) ;
}
static int F_7 ( struct V_2 * V_3 , T_2 V_12 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_14 * V_15 ;
int V_16 , V_17 ;
char * V_18 ;
T_1 V_8 , V_19 ;
int V_20 = 0 ;
int V_21 = 0 ;
V_16 = V_13 -> V_22 ;
V_15 = (struct V_14 * ) V_23 ;
V_17 = F_8 ( V_23 ) ;
for ( V_21 = 0 ; V_21 < V_17 ; V_21 ++ ) {
if ( V_15 [ V_21 ] . V_24 & V_12 )
break;
}
if ( V_21 == V_17 ) {
F_9 ( 1 , V_25 , V_3 ,
L_1 ,
( unsigned long long ) V_12 ) ;
return - V_26 ;
}
V_19 = V_13 -> V_27 & ( ~ ( V_28 ) ) ;
V_19 |= V_15 [ V_21 ] . V_29 ;
V_20 = F_4 ( V_3 , V_30 , V_19 ) ;
if ( V_20 < 0 )
goto V_31;
V_13 -> V_27 = V_19 ;
V_19 = V_13 -> V_32 & ( ~ ( ( T_1 ) V_33 ) ) ;
V_19 |= V_34 ;
V_20 = F_4 ( V_3 , V_35 , V_19 ) ;
if ( V_20 < 0 )
goto V_31;
V_13 -> V_32 = V_19 ;
V_18 = ( unsigned char * ) & V_15 [ V_21 ] . V_36 ;
V_8 = V_37 ;
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ , V_8 ++ , V_18 ++ ) {
V_20 = F_4 ( V_3 , V_8 , * V_18 ) ;
if ( V_20 < 0 )
goto V_31;
}
V_19 = V_13 -> V_27 ;
if ( V_12 & ( V_38 | V_39 ) )
V_19 &= 0x03 ;
else if ( V_12 & ~ V_40 )
V_19 |= 0x04 ;
V_20 = F_4 ( V_3 , V_30 , V_19 ) ;
if ( V_20 < 0 )
goto V_31;
V_13 -> V_27 = V_19 ;
V_31:
if ( V_20 != 0 )
F_10 ( V_3 , L_2 ) ;
return V_20 ;
}
static int F_11 ( struct V_2 * V_3 , T_3 V_41 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
unsigned char V_19 ;
int V_20 = 0 ;
if ( V_41 > V_42 ) {
F_9 ( 1 , V_25 , V_3 ,
L_3 ,
V_41 ) ;
return - V_26 ;
}
V_19 = V_13 -> V_43 & 0x03 ;
if ( V_41 == V_44 )
V_19 |= V_45 ;
else if ( V_41 == V_46 )
V_19 |= V_47 ;
else
V_19 |= V_48 ;
V_20 = F_4 ( V_3 , V_49 , V_19 ) ;
if ( V_20 < 0 )
goto V_50;
V_13 -> V_43 = V_19 ;
V_19 = V_13 -> V_51 | V_52 ;
V_20 = F_4 ( V_3 , V_53 , V_19 ) ;
if ( V_20 < 0 )
goto V_50;
V_13 -> V_51 = V_19 ;
V_19 = V_13 -> V_54 & ( V_55 & V_56 ) ;
V_20 = F_4 ( V_3 , V_57 , V_19 ) ;
if ( V_20 < 0 )
goto V_50;
V_13 -> V_54 = V_19 ;
V_19 = V_13 -> V_58 & ( V_59 & V_60 ) ;
V_20 = F_4 ( V_3 , V_61 , V_19 ) ;
if ( V_20 < 0 )
goto V_50;
V_13 -> V_58 = V_19 ;
V_50:
if ( V_20 != 0 )
F_10 ( V_3 , L_4 ) ;
return V_20 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_13 ( V_3 , L_5 , ( unsigned long long ) V_13 -> V_12 ) ;
F_13 ( V_3 , L_6 , ( V_13 -> V_22 == 0 ) ? L_7 :
( ( V_13 -> V_22 == 1 ) ? L_8 : L_9 ) ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_62 ) {
case V_63 :
return F_4 ( V_3 , V_64 ,
V_5 -> V_19 ) ;
case V_65 :
return F_4 ( V_3 , V_66 , V_5 -> V_19 ) ;
case V_67 :
return F_4 ( V_3 , V_68 , V_5 -> V_19 ) ;
}
return - V_26 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_69 * V_70 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_16 ( V_11 , V_70 , V_71 , 0 ) ;
}
static int F_17 ( struct V_2 * V_3 , T_2 V_12 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
int V_20 = 0 ;
if ( V_13 -> V_12 == V_12 )
return 0 ;
V_20 = F_7 ( V_3 , V_12 ) ;
if ( ! V_20 )
V_13 -> V_12 = V_12 ;
return V_20 ;
}
static int F_18 ( struct V_2 * V_3 ,
T_3 V_72 , T_3 V_22 , T_3 V_73 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
int V_20 = 0 ;
if ( V_13 -> V_22 == V_22 )
return 0 ;
V_20 = F_11 ( V_3 , V_22 ) ;
if ( ! V_20 )
V_13 -> V_22 = V_22 ;
return V_20 ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
int V_20 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_8 ( V_74 ) ; V_21 += 2 ) {
V_20 = F_4 ( V_3 , V_74 [ V_21 ] ,
V_74 [ V_21 + 1 ] ) ;
if ( V_20 ) {
F_10 ( V_3 , L_10 ) ;
return V_20 ;
}
}
V_20 = F_11 ( V_3 , V_13 -> V_22 ) ;
if ( V_20 < 0 ) {
F_10 ( V_3 , L_11 ) ;
return - V_26 ;
}
V_20 = F_7 ( V_3 , V_13 -> V_12 ) ;
if ( V_20 < 0 ) {
F_10 ( V_3 , L_12 ) ;
return - V_26 ;
}
return V_20 ;
}
static int F_20 ( struct V_10 * V_11 ,
const struct V_75 * V_62 )
{
struct V_1 * V_13 ;
int V_20 ;
if ( ! F_21 ( V_11 -> V_76 , V_77 ) )
return - V_78 ;
F_22 ( V_11 , L_13 ,
V_11 -> V_79 << 1 , V_11 -> V_76 -> V_80 ) ;
V_13 = F_23 ( sizeof( struct V_1 ) , V_81 ) ;
if ( V_13 == NULL )
return - V_82 ;
V_13 -> V_43 = 0x80 ;
V_13 -> V_32 = 0x00 ;
V_13 -> V_51 = 0x20 ;
V_13 -> V_58 = 0x00 ;
V_13 -> V_27 = V_83 ;
V_13 -> V_54 = V_84 ;
V_13 -> V_22 = V_44 ;
V_13 -> V_12 = V_38 ;
F_24 ( & V_13 -> V_3 , V_11 , & V_85 ) ;
F_25 ( & V_13 -> V_7 , 2 ) ;
F_26 ( & V_13 -> V_7 , & V_86 ,
V_63 , V_87 ,
V_88 , 1 ,
V_89 ) ;
F_26 ( & V_13 -> V_7 , & V_86 ,
V_65 , V_90 ,
V_91 , 1 ,
V_92 ) ;
F_26 ( & V_13 -> V_7 , & V_86 ,
V_67 , V_93 ,
V_94 , 1 ,
V_95 ) ;
V_13 -> V_3 . V_96 = & V_13 -> V_7 ;
if ( V_13 -> V_7 . error ) {
int V_20 = V_13 -> V_7 . error ;
F_27 ( & V_13 -> V_7 ) ;
F_28 ( V_13 ) ;
return V_20 ;
}
F_29 ( & V_13 -> V_7 ) ;
V_20 = F_19 ( & V_13 -> V_3 ) ;
if ( V_20 ) {
F_27 ( & V_13 -> V_7 ) ;
F_28 ( V_13 ) ;
}
return V_20 ;
}
static int F_30 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_31 ( V_11 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_32 ( V_3 ) ;
F_27 ( & V_13 -> V_7 ) ;
F_28 ( V_13 ) ;
return 0 ;
}
static T_4 int F_33 ( void )
{
return F_34 ( & V_97 ) ;
}
static T_5 void F_35 ( void )
{
F_36 ( & V_97 ) ;
}
