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
int V_16 ;
char * V_17 ;
T_1 V_8 , V_18 ;
int V_19 = 0 ;
int V_20 = 0 ;
V_15 = (struct V_14 * ) V_21 ;
V_16 = F_8 ( V_21 ) ;
for ( V_20 = 0 ; V_20 < V_16 ; V_20 ++ ) {
if ( V_15 [ V_20 ] . V_22 & V_12 )
break;
}
if ( V_20 == V_16 ) {
F_9 ( 1 , V_23 , V_3 ,
L_1 ,
( unsigned long long ) V_12 ) ;
return - V_24 ;
}
V_18 = V_13 -> V_25 & ( ~ ( V_26 ) ) ;
V_18 |= V_15 [ V_20 ] . V_27 ;
V_19 = F_4 ( V_3 , V_28 , V_18 ) ;
if ( V_19 < 0 )
goto V_29;
V_13 -> V_25 = V_18 ;
V_18 = V_13 -> V_30 & ( ~ ( ( T_1 ) V_31 ) ) ;
V_18 |= V_32 ;
V_19 = F_4 ( V_3 , V_33 , V_18 ) ;
if ( V_19 < 0 )
goto V_29;
V_13 -> V_30 = V_18 ;
V_17 = ( unsigned char * ) & V_15 [ V_20 ] . V_34 ;
V_8 = V_35 ;
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ , V_8 ++ , V_17 ++ ) {
V_19 = F_4 ( V_3 , V_8 , * V_17 ) ;
if ( V_19 < 0 )
goto V_29;
}
V_18 = V_13 -> V_25 ;
if ( V_12 & ( V_36 | V_37 ) )
V_18 &= 0x03 ;
else if ( V_12 & ~ V_38 )
V_18 |= 0x04 ;
V_19 = F_4 ( V_3 , V_28 , V_18 ) ;
if ( V_19 < 0 )
goto V_29;
V_13 -> V_25 = V_18 ;
V_29:
if ( V_19 != 0 )
F_10 ( V_3 , L_2 ) ;
return V_19 ;
}
static int F_11 ( struct V_2 * V_3 , T_3 V_39 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
unsigned char V_18 ;
int V_19 = 0 ;
if ( V_39 > V_40 ) {
F_9 ( 1 , V_23 , V_3 ,
L_3 ,
V_39 ) ;
return - V_24 ;
}
V_18 = V_13 -> V_41 & 0x03 ;
if ( V_39 == V_42 )
V_18 |= V_43 ;
else if ( V_39 == V_44 )
V_18 |= V_45 ;
else
V_18 |= V_46 ;
V_19 = F_4 ( V_3 , V_47 , V_18 ) ;
if ( V_19 < 0 )
goto V_48;
V_13 -> V_41 = V_18 ;
V_18 = V_13 -> V_49 | V_50 ;
V_19 = F_4 ( V_3 , V_51 , V_18 ) ;
if ( V_19 < 0 )
goto V_48;
V_13 -> V_49 = V_18 ;
V_18 = V_13 -> V_52 & ( V_53 & V_54 ) ;
V_19 = F_4 ( V_3 , V_55 , V_18 ) ;
if ( V_19 < 0 )
goto V_48;
V_13 -> V_52 = V_18 ;
V_18 = V_13 -> V_56 & ( V_57 & V_58 ) ;
V_19 = F_4 ( V_3 , V_59 , V_18 ) ;
if ( V_19 < 0 )
goto V_48;
V_13 -> V_56 = V_18 ;
V_48:
if ( V_19 != 0 )
F_10 ( V_3 , L_4 ) ;
return V_19 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_13 ( V_3 , L_5 , ( unsigned long long ) V_13 -> V_12 ) ;
F_13 ( V_3 , L_6 , ( V_13 -> V_60 == 0 ) ? L_7 :
( ( V_13 -> V_60 == 1 ) ? L_8 : L_9 ) ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_61 ) {
case V_62 :
return F_4 ( V_3 , V_63 ,
V_5 -> V_18 ) ;
case V_64 :
return F_4 ( V_3 , V_65 , V_5 -> V_18 ) ;
case V_66 :
return F_4 ( V_3 , V_67 , V_5 -> V_18 ) ;
}
return - V_24 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_68 * V_69 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_16 ( V_11 , V_69 , V_70 , 0 ) ;
}
static int F_17 ( struct V_2 * V_3 , T_2 V_12 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
int V_19 = 0 ;
if ( V_13 -> V_12 == V_12 )
return 0 ;
V_19 = F_7 ( V_3 , V_12 ) ;
if ( ! V_19 )
V_13 -> V_12 = V_12 ;
return V_19 ;
}
static int F_18 ( struct V_2 * V_3 ,
T_3 V_71 , T_3 V_60 , T_3 V_72 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
int V_19 = 0 ;
if ( V_13 -> V_60 == V_60 )
return 0 ;
V_19 = F_11 ( V_3 , V_60 ) ;
if ( ! V_19 )
V_13 -> V_60 = V_60 ;
return V_19 ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
int V_19 = 0 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < F_8 ( V_73 ) ; V_20 += 2 ) {
V_19 = F_4 ( V_3 , V_73 [ V_20 ] ,
V_73 [ V_20 + 1 ] ) ;
if ( V_19 ) {
F_10 ( V_3 , L_10 ) ;
return V_19 ;
}
}
V_19 = F_11 ( V_3 , V_13 -> V_60 ) ;
if ( V_19 < 0 ) {
F_10 ( V_3 , L_11 ) ;
return - V_24 ;
}
V_19 = F_7 ( V_3 , V_13 -> V_12 ) ;
if ( V_19 < 0 ) {
F_10 ( V_3 , L_12 ) ;
return - V_24 ;
}
return V_19 ;
}
static int F_20 ( struct V_10 * V_11 ,
const struct V_74 * V_61 )
{
struct V_1 * V_13 ;
int V_19 ;
if ( ! F_21 ( V_11 -> V_75 , V_76 ) )
return - V_77 ;
F_22 ( V_11 , L_13 ,
V_11 -> V_78 << 1 , V_11 -> V_75 -> V_79 ) ;
V_13 = F_23 ( sizeof( struct V_1 ) , V_80 ) ;
if ( V_13 == NULL )
return - V_81 ;
V_13 -> V_41 = 0x80 ;
V_13 -> V_30 = 0x00 ;
V_13 -> V_49 = 0x20 ;
V_13 -> V_56 = 0x00 ;
V_13 -> V_25 = V_82 ;
V_13 -> V_52 = V_83 ;
V_13 -> V_60 = V_42 ;
V_13 -> V_12 = V_36 ;
F_24 ( & V_13 -> V_3 , V_11 , & V_84 ) ;
F_25 ( & V_13 -> V_7 , 2 ) ;
F_26 ( & V_13 -> V_7 , & V_85 ,
V_62 , V_86 ,
V_87 , 1 ,
V_88 ) ;
F_26 ( & V_13 -> V_7 , & V_85 ,
V_64 , V_89 ,
V_90 , 1 ,
V_91 ) ;
F_26 ( & V_13 -> V_7 , & V_85 ,
V_66 , V_92 ,
V_93 , 1 ,
V_94 ) ;
V_13 -> V_3 . V_95 = & V_13 -> V_7 ;
if ( V_13 -> V_7 . error ) {
int V_19 = V_13 -> V_7 . error ;
F_27 ( & V_13 -> V_7 ) ;
F_28 ( V_13 ) ;
return V_19 ;
}
F_29 ( & V_13 -> V_7 ) ;
V_19 = F_19 ( & V_13 -> V_3 ) ;
if ( V_19 ) {
F_27 ( & V_13 -> V_7 ) ;
F_28 ( V_13 ) ;
}
return V_19 ;
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
