static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_1 F_5 ( struct V_6 * V_7 , T_1 V_3 )
{
return F_2 ( V_7 -> V_8 + V_3 ) ;
}
static inline void F_6 ( struct V_6 * V_7 , T_1 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_7 -> V_8 + V_3 ) ;
}
static int F_7 ( struct V_6 * V_7 )
{
struct V_1 * V_9 = F_8 ( V_7 ) ;
T_1 V_10 = F_1 ( V_9 , V_11 ) ;
return ! ! ( V_10 & V_12 ) ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_9 = F_8 ( V_7 ) ;
T_1 V_10 ;
if ( F_10 ( V_7 ) ) {
F_11 ( V_7 -> V_13 , L_1 ) ;
return 0 ;
}
V_10 = F_1 ( V_9 , V_14 ) ;
V_10 |= V_15 ;
F_3 ( V_9 , V_14 , V_10 ) ;
return F_12 ( V_7 ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_9 = F_8 ( V_7 ) ;
F_3 ( V_9 , V_16 ,
~ V_17 ) ;
F_3 ( V_9 ,
V_18 , V_17 ) ;
F_3 ( V_9 , V_19 ,
~ V_20 & ~ V_21 ) ;
if ( F_14 ( V_22 ) )
F_3 ( V_9 ,
V_23 , V_21 ) ;
else
F_3 ( V_9 ,
V_23 ,
V_20 ) ;
}
static void F_15 ( struct V_6 * V_7 )
{
F_16 ( V_7 ) ;
V_7 -> V_24 &= V_25 ;
V_7 -> V_26 &= V_25 ;
V_7 -> V_27 &= V_25 ;
V_7 -> V_28 &= V_25 ;
F_9 ( V_7 ) ;
if ( F_14 ( V_22 ) )
F_17 ( V_7 ) ;
F_13 ( V_7 ) ;
}
static int F_18 ( struct V_29 * V_30 , unsigned int V_31 ,
T_2 V_32 )
{
F_19 ( V_31 , & V_33 , V_34 ) ;
F_20 ( V_31 , V_30 -> V_35 ) ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 )
{
struct V_36 * V_13 = V_7 -> V_13 ;
struct V_37 * V_38 = V_13 -> V_39 ;
struct V_37 * V_40 = F_22 ( V_38 , NULL ) ;
if ( ! V_40 ) {
F_11 ( V_13 , L_2 ) ;
return F_23 ( V_40 ) ;
}
V_7 -> V_29 = F_24 ( V_40 , 4 ,
& V_41 , V_7 ) ;
if ( ! V_7 -> V_29 ) {
F_11 ( V_13 , L_3 ) ;
return F_23 ( V_7 -> V_29 ) ;
}
return 0 ;
}
static T_3 F_25 ( int V_31 , void * V_42 )
{
struct V_6 * V_7 = V_42 ;
struct V_1 * V_9 = F_8 ( V_7 ) ;
T_1 V_10 ;
V_10 = F_1 ( V_9 , V_19 ) ;
switch ( V_10 ) {
case V_21 :
F_26 ( V_7 ) ;
break;
case V_43 :
case V_44 :
case V_45 :
case V_46 :
F_27 ( F_28 ( V_7 -> V_29 , F_29 ( V_10 ) ) ) ;
break;
}
F_3 ( V_9 , V_19 , V_10 ) ;
return V_47 ;
}
static T_3 F_30 ( int V_31 , void * V_42 )
{
struct V_1 * V_9 = V_42 ;
T_1 V_10 ;
V_10 = F_1 ( V_9 , V_16 ) ;
if ( V_10 & V_48 )
F_31 ( V_9 -> V_13 , L_4 ) ;
if ( V_10 & V_49 )
F_31 ( V_9 -> V_13 , L_5 ) ;
if ( V_10 & V_50 )
F_31 ( V_9 -> V_13 , L_6 ) ;
if ( V_10 & V_51 )
F_31 ( V_9 -> V_13 , L_7 ) ;
if ( V_10 & V_52 )
F_31 ( V_9 -> V_13 , L_8 ) ;
if ( V_10 & V_53 )
F_31 ( V_9 -> V_13 , L_9 ) ;
if ( V_10 & V_54 )
F_31 ( V_9 -> V_13 ,
L_10 ) ;
if ( V_10 & V_55 )
F_31 ( V_9 -> V_13 ,
L_11 ) ;
if ( V_10 & V_56 )
F_31 ( V_9 -> V_13 ,
L_12 ) ;
if ( V_10 & V_57 )
F_31 ( V_9 -> V_13 , L_13 ) ;
if ( V_10 & V_58 )
F_31 ( V_9 -> V_13 , L_14 ) ;
if ( V_10 & V_59 )
F_31 ( V_9 -> V_13 , L_15 ) ;
if ( V_10 & V_60 )
F_31 ( V_9 -> V_13 , L_16 ) ;
F_3 ( V_9 , V_16 , V_10 ) ;
return V_47 ;
}
static int T_4 F_32 ( struct V_1 * V_9 ,
struct V_61 * V_62 )
{
int V_63 ;
struct V_6 * V_7 ;
struct V_64 * V_65 ;
struct V_36 * V_13 = & V_62 -> V_13 ;
V_7 = & V_9 -> V_7 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_66 = & V_67 ;
V_7 -> V_31 = F_33 ( V_62 , 1 ) ;
if ( V_7 -> V_31 < 0 ) {
F_11 ( V_13 , L_17 ) ;
return - V_68 ;
}
V_63 = F_34 ( & V_62 -> V_13 , V_7 -> V_31 ,
F_25 ,
V_69 | V_70 ,
L_18 , V_7 ) ;
if ( V_63 ) {
F_11 ( & V_62 -> V_13 , L_19 ) ;
return V_63 ;
}
if ( ! F_14 ( V_22 ) ) {
V_63 = F_21 ( V_7 ) ;
if ( V_63 < 0 )
return V_63 ;
}
V_65 = F_35 ( V_62 , V_71 , L_20 ) ;
V_7 -> V_8 = F_36 ( V_13 , V_65 -> V_72 , F_37 ( V_65 ) ) ;
if ( ! V_7 -> V_8 )
return - V_73 ;
V_63 = F_38 ( V_7 ) ;
if ( V_63 ) {
F_11 ( V_9 -> V_13 , L_21 ) ;
return V_63 ;
}
return 0 ;
}
static int T_4 F_39 ( struct V_61 * V_62 )
{
T_1 V_10 ;
int V_63 ;
int V_31 ;
int V_74 ;
int V_75 ;
struct V_76 * * V_76 ;
void T_5 * V_4 ;
struct V_64 * V_65 ;
struct V_1 * V_9 ;
struct V_36 * V_13 = & V_62 -> V_13 ;
struct V_37 * V_77 = V_13 -> V_39 ;
char V_78 [ 10 ] ;
int V_79 ;
enum V_80 V_81 ;
unsigned long V_82 ;
V_9 = F_40 ( V_13 , sizeof( * V_9 ) , V_83 ) ;
if ( ! V_9 )
return - V_73 ;
V_31 = F_33 ( V_62 , 0 ) ;
if ( V_31 < 0 ) {
F_11 ( V_13 , L_17 ) ;
return - V_68 ;
}
V_63 = F_34 ( V_13 , V_31 , F_30 ,
V_69 , L_22 , V_9 ) ;
if ( V_63 ) {
F_11 ( V_13 , L_19 ) ;
return V_63 ;
}
V_65 = F_35 ( V_62 , V_71 , L_23 ) ;
V_4 = F_41 ( V_13 , V_65 -> V_72 , F_37 ( V_65 ) ) ;
if ( ! V_4 )
return - V_73 ;
V_75 = F_42 ( V_77 , L_24 ) ;
if ( V_75 < 0 ) {
F_11 ( V_13 , L_25 ) ;
return V_75 ;
}
V_76 = F_40 ( V_13 , sizeof( * V_76 ) * V_75 , V_83 ) ;
if ( ! V_76 )
return - V_73 ;
for ( V_74 = 0 ; V_74 < V_75 ; V_74 ++ ) {
snprintf ( V_78 , sizeof( V_78 ) , L_26 , V_74 ) ;
V_76 [ V_74 ] = F_43 ( V_13 , V_78 ) ;
if ( F_44 ( V_76 [ V_74 ] ) )
return F_23 ( V_76 [ V_74 ] ) ;
V_63 = F_45 ( V_76 [ V_74 ] ) ;
if ( V_63 < 0 )
goto V_84;
V_63 = F_46 ( V_76 [ V_74 ] ) ;
if ( V_63 < 0 ) {
F_47 ( V_76 [ V_74 ] ) ;
goto V_84;
}
}
V_9 -> V_4 = V_4 ;
V_9 -> V_76 = V_76 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_75 = V_75 ;
F_48 ( V_13 ) ;
V_63 = F_49 ( V_13 ) ;
if ( V_63 < 0 ) {
F_11 ( V_13 , L_27 ) ;
goto V_85;
}
V_79 = F_50 ( V_13 -> V_39 , 0 , & V_81 ) ;
if ( F_51 ( V_79 ) ) {
V_82 = ( V_81 & V_86 ) ?
V_87 : V_88 ;
V_63 = F_52 ( V_13 , V_79 , V_82 ,
L_28 ) ;
if ( V_63 ) {
F_11 ( & V_62 -> V_13 , L_29 ,
V_79 , V_63 ) ;
goto V_89;
}
} else if ( V_79 == - V_90 ) {
V_63 = - V_90 ;
goto V_89;
}
V_10 = F_1 ( V_9 , V_14 ) ;
V_10 &= ~ V_15 ;
F_3 ( V_9 , V_14 , V_10 ) ;
F_53 ( V_62 , V_9 ) ;
V_63 = F_32 ( V_9 , V_62 ) ;
if ( V_63 < 0 )
goto V_89;
return 0 ;
V_89:
F_54 ( V_13 ) ;
V_85:
F_55 ( V_13 ) ;
V_84:
while ( -- V_74 >= 0 ) {
F_56 ( V_76 [ V_74 ] ) ;
F_47 ( V_76 [ V_74 ] ) ;
}
return V_63 ;
}
static int T_6 F_57 ( struct V_61 * V_62 )
{
struct V_1 * V_9 = F_58 ( V_62 ) ;
struct V_6 * V_7 = & V_9 -> V_7 ;
struct V_36 * V_13 = & V_62 -> V_13 ;
int V_91 = V_9 -> V_75 ;
if ( V_7 -> V_29 )
F_59 ( V_7 -> V_29 ) ;
F_54 ( V_13 ) ;
F_55 ( V_13 ) ;
while ( V_91 -- ) {
F_56 ( V_9 -> V_76 [ V_91 ] ) ;
F_47 ( V_9 -> V_76 [ V_91 ] ) ;
}
return 0 ;
}
static int F_60 ( struct V_36 * V_13 )
{
struct V_1 * V_9 = F_61 ( V_13 ) ;
struct V_6 * V_7 = & V_9 -> V_7 ;
T_1 V_92 ;
V_92 = F_5 ( V_7 , V_93 ) ;
V_92 &= ~ V_94 ;
F_6 ( V_7 , V_93 , V_92 ) ;
return 0 ;
}
static int F_62 ( struct V_36 * V_13 )
{
struct V_1 * V_9 = F_61 ( V_13 ) ;
struct V_6 * V_7 = & V_9 -> V_7 ;
T_1 V_92 ;
V_92 = F_5 ( V_7 , V_93 ) ;
V_92 |= V_94 ;
F_6 ( V_7 , V_93 , V_92 ) ;
return 0 ;
}
static int F_63 ( struct V_36 * V_13 )
{
struct V_1 * V_9 = F_61 ( V_13 ) ;
int V_91 = V_9 -> V_75 ;
while ( V_91 -- ) {
F_56 ( V_9 -> V_76 [ V_91 ] ) ;
F_47 ( V_9 -> V_76 [ V_91 ] ) ;
}
return 0 ;
}
static int F_64 ( struct V_36 * V_13 )
{
struct V_1 * V_9 = F_61 ( V_13 ) ;
int V_75 = V_9 -> V_75 ;
int V_63 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_75 ; V_74 ++ ) {
V_63 = F_45 ( V_9 -> V_76 [ V_74 ] ) ;
if ( V_63 < 0 )
goto V_84;
V_63 = F_46 ( V_9 -> V_76 [ V_74 ] ) ;
if ( V_63 < 0 ) {
F_47 ( V_9 -> V_76 [ V_74 ] ) ;
goto V_84;
}
}
return 0 ;
V_84:
while ( -- V_74 >= 0 ) {
F_56 ( V_9 -> V_76 [ V_74 ] ) ;
F_47 ( V_9 -> V_76 [ V_74 ] ) ;
}
return V_63 ;
}
