static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_8 = F_6 ( V_7 ) ;
T_1 V_9 = F_1 ( V_8 , V_10 ) ;
return ! ! ( V_9 & V_11 ) ;
}
static int F_7 ( struct V_1 * V_8 )
{
struct V_6 * V_7 = & V_8 -> V_7 ;
struct V_12 * V_13 = V_7 -> V_13 ;
T_1 V_9 ;
if ( F_8 ( V_7 ) ) {
F_9 ( V_13 , L_1 ) ;
return 0 ;
}
V_9 = F_1 ( V_8 , V_14 ) ;
V_9 |= V_15 ;
F_3 ( V_8 , V_14 , V_9 ) ;
return F_10 ( V_7 ) ;
}
static void F_11 ( struct V_1 * V_8 )
{
F_3 ( V_8 , V_16 ,
~ V_17 ) ;
F_3 ( V_8 ,
V_18 , V_17 ) ;
F_3 ( V_8 , V_19 ,
~ V_20 & ~ V_21 ) ;
if ( F_12 ( V_22 ) )
F_3 ( V_8 ,
V_23 , V_21 ) ;
else
F_3 ( V_8 ,
V_23 ,
V_20 ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_8 = F_6 ( V_7 ) ;
V_7 -> V_24 &= V_25 ;
V_7 -> V_26 &= V_25 ;
V_7 -> V_27 &= V_25 ;
V_7 -> V_28 &= V_25 ;
F_14 ( V_7 ) ;
F_7 ( V_8 ) ;
if ( F_12 ( V_22 ) )
F_15 ( V_7 ) ;
F_11 ( V_8 ) ;
}
static int F_16 ( struct V_29 * V_30 , unsigned int V_31 ,
T_2 V_32 )
{
F_17 ( V_31 , & V_33 , V_34 ) ;
F_18 ( V_31 , V_30 -> V_35 ) ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_36 * V_37 = V_13 -> V_38 ;
struct V_36 * V_39 = F_20 ( V_37 , NULL ) ;
if ( ! V_39 ) {
F_9 ( V_13 , L_2 ) ;
return - V_40 ;
}
V_7 -> V_29 = F_21 ( V_39 , 4 ,
& V_41 , V_7 ) ;
if ( ! V_7 -> V_29 ) {
F_9 ( V_13 , L_3 ) ;
return - V_40 ;
}
return 0 ;
}
static T_3 F_22 ( int V_31 , void * V_42 )
{
struct V_1 * V_8 = V_42 ;
struct V_6 * V_7 = & V_8 -> V_7 ;
T_1 V_9 ;
V_9 = F_1 ( V_8 , V_19 ) ;
switch ( V_9 ) {
case V_21 :
F_23 ( V_7 ) ;
break;
case V_43 :
case V_44 :
case V_45 :
case V_46 :
F_24 ( F_25 ( V_7 -> V_29 , F_26 ( V_9 ) ) ) ;
break;
}
F_3 ( V_8 , V_19 , V_9 ) ;
return V_47 ;
}
static T_3 F_27 ( int V_31 , void * V_42 )
{
struct V_1 * V_8 = V_42 ;
struct V_12 * V_13 = V_8 -> V_7 . V_13 ;
T_1 V_9 ;
V_9 = F_1 ( V_8 , V_16 ) ;
if ( V_9 & V_48 )
F_28 ( V_13 , L_4 ) ;
if ( V_9 & V_49 )
F_28 ( V_13 , L_5 ) ;
if ( V_9 & V_50 )
F_28 ( V_13 , L_6 ) ;
if ( V_9 & V_51 )
F_28 ( V_13 , L_7 ) ;
if ( V_9 & V_52 )
F_28 ( V_13 , L_8 ) ;
if ( V_9 & V_53 )
F_28 ( V_13 , L_9 ) ;
if ( V_9 & V_54 )
F_28 ( V_13 ,
L_10 ) ;
if ( V_9 & V_55 )
F_28 ( V_13 ,
L_11 ) ;
if ( V_9 & V_56 )
F_28 ( V_13 , L_12 ) ;
if ( V_9 & V_57 )
F_28 ( V_13 , L_13 ) ;
if ( V_9 & V_58 )
F_28 ( V_13 , L_14 ) ;
if ( V_9 & V_59 )
F_28 ( V_13 , L_15 ) ;
if ( V_9 & V_60 )
F_28 ( V_13 , L_16 ) ;
F_3 ( V_8 , V_16 , V_9 ) ;
return V_47 ;
}
static int T_4 F_29 ( struct V_1 * V_8 ,
struct V_61 * V_62 )
{
int V_63 ;
struct V_6 * V_7 = & V_8 -> V_7 ;
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_64 * V_65 ;
V_7 -> V_31 = F_30 ( V_62 , 1 ) ;
if ( V_7 -> V_31 < 0 ) {
F_9 ( V_13 , L_17 ) ;
return - V_66 ;
}
V_63 = F_31 ( V_13 , V_7 -> V_31 , F_22 ,
V_67 | V_68 ,
L_18 , V_8 ) ;
if ( V_63 ) {
F_9 ( V_13 , L_19 ) ;
return V_63 ;
}
if ( ! F_12 ( V_22 ) ) {
V_63 = F_19 ( V_7 ) ;
if ( V_63 < 0 )
return V_63 ;
}
V_65 = F_32 ( V_62 , V_69 , L_20 ) ;
V_7 -> V_70 = F_33 ( V_13 , V_65 -> V_71 , F_34 ( V_65 ) ) ;
if ( ! V_7 -> V_70 )
return - V_72 ;
V_63 = F_35 ( V_7 ) ;
if ( V_63 ) {
F_9 ( V_13 , L_21 ) ;
return V_63 ;
}
return 0 ;
}
static int T_4 F_36 ( struct V_61 * V_62 )
{
T_1 V_9 ;
int V_63 ;
int V_31 ;
int V_73 ;
int V_74 ;
struct V_75 * * V_75 ;
void T_5 * V_4 ;
struct V_64 * V_65 ;
struct V_1 * V_8 ;
struct V_6 * V_7 ;
struct V_12 * V_13 = & V_62 -> V_13 ;
struct V_36 * V_76 = V_13 -> V_38 ;
char V_77 [ 10 ] ;
int V_78 ;
enum V_79 V_80 ;
unsigned long V_81 ;
V_8 = F_37 ( V_13 , sizeof( * V_8 ) , V_82 ) ;
if ( ! V_8 )
return - V_72 ;
V_7 = & V_8 -> V_7 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_83 = & V_84 ;
V_31 = F_30 ( V_62 , 0 ) ;
if ( V_31 < 0 ) {
F_9 ( V_13 , L_17 ) ;
return - V_66 ;
}
V_63 = F_31 ( V_13 , V_31 , F_27 ,
V_67 , L_22 , V_8 ) ;
if ( V_63 ) {
F_9 ( V_13 , L_19 ) ;
return V_63 ;
}
V_65 = F_32 ( V_62 , V_69 , L_23 ) ;
V_4 = F_38 ( V_13 , V_65 -> V_71 , F_34 ( V_65 ) ) ;
if ( ! V_4 )
return - V_72 ;
V_74 = F_39 ( V_76 , L_24 ) ;
if ( V_74 < 0 ) {
F_9 ( V_13 , L_25 ) ;
return V_74 ;
}
V_75 = F_37 ( V_13 , sizeof( * V_75 ) * V_74 , V_82 ) ;
if ( ! V_75 )
return - V_72 ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ ) {
snprintf ( V_77 , sizeof( V_77 ) , L_26 , V_73 ) ;
V_75 [ V_73 ] = F_40 ( V_13 , V_77 ) ;
if ( F_41 ( V_75 [ V_73 ] ) )
return F_42 ( V_75 [ V_73 ] ) ;
V_63 = F_43 ( V_75 [ V_73 ] ) ;
if ( V_63 < 0 )
goto V_85;
V_63 = F_44 ( V_75 [ V_73 ] ) ;
if ( V_63 < 0 ) {
F_45 ( V_75 [ V_73 ] ) ;
goto V_85;
}
}
V_8 -> V_4 = V_4 ;
V_8 -> V_75 = V_75 ;
V_8 -> V_74 = V_74 ;
F_46 ( V_13 ) ;
V_63 = F_47 ( V_13 ) ;
if ( V_63 < 0 ) {
F_9 ( V_13 , L_27 ) ;
goto V_86;
}
V_78 = F_48 ( V_13 -> V_38 , 0 , & V_80 ) ;
if ( F_49 ( V_78 ) ) {
V_81 = ( V_80 & V_87 ) ?
V_88 : V_89 ;
V_63 = F_50 ( V_13 , V_78 , V_81 ,
L_28 ) ;
if ( V_63 ) {
F_9 ( V_13 , L_29 ,
V_78 , V_63 ) ;
goto V_90;
}
} else if ( V_78 == - V_91 ) {
V_63 = - V_91 ;
goto V_90;
}
V_9 = F_1 ( V_8 , V_14 ) ;
V_9 &= ~ V_15 ;
F_3 ( V_8 , V_14 , V_9 ) ;
V_63 = F_29 ( V_8 , V_62 ) ;
if ( V_63 < 0 )
goto V_90;
F_51 ( V_62 , V_8 ) ;
return 0 ;
V_90:
F_52 ( V_13 ) ;
V_86:
F_53 ( V_13 ) ;
V_85:
while ( -- V_73 >= 0 ) {
F_54 ( V_75 [ V_73 ] ) ;
F_45 ( V_75 [ V_73 ] ) ;
}
return V_63 ;
}
static int F_55 ( struct V_12 * V_13 )
{
struct V_1 * V_8 = F_56 ( V_13 ) ;
struct V_6 * V_7 = & V_8 -> V_7 ;
T_1 V_92 ;
V_92 = F_57 ( V_7 , V_93 ) ;
V_92 &= ~ V_94 ;
F_58 ( V_7 , V_93 , V_92 ) ;
return 0 ;
}
static int F_59 ( struct V_12 * V_13 )
{
struct V_1 * V_8 = F_56 ( V_13 ) ;
struct V_6 * V_7 = & V_8 -> V_7 ;
T_1 V_92 ;
V_92 = F_57 ( V_7 , V_93 ) ;
V_92 |= V_94 ;
F_58 ( V_7 , V_93 , V_92 ) ;
return 0 ;
}
static int F_60 ( struct V_12 * V_13 )
{
struct V_1 * V_8 = F_56 ( V_13 ) ;
int V_95 = V_8 -> V_74 ;
while ( V_95 -- ) {
F_54 ( V_8 -> V_75 [ V_95 ] ) ;
F_45 ( V_8 -> V_75 [ V_95 ] ) ;
}
return 0 ;
}
static int F_61 ( struct V_12 * V_13 )
{
struct V_1 * V_8 = F_56 ( V_13 ) ;
int V_74 = V_8 -> V_74 ;
int V_63 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ ) {
V_63 = F_43 ( V_8 -> V_75 [ V_73 ] ) ;
if ( V_63 < 0 )
goto V_85;
V_63 = F_44 ( V_8 -> V_75 [ V_73 ] ) ;
if ( V_63 < 0 ) {
F_45 ( V_8 -> V_75 [ V_73 ] ) ;
goto V_85;
}
}
return 0 ;
V_85:
while ( -- V_73 >= 0 ) {
F_54 ( V_8 -> V_75 [ V_73 ] ) ;
F_45 ( V_8 -> V_75 [ V_73 ] ) ;
}
return V_63 ;
}
