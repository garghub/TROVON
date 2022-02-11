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
unsigned int V_13 ;
if ( F_10 ( V_7 ) ) {
F_11 ( V_7 -> V_14 , L_1 ) ;
return 0 ;
}
V_10 = F_1 ( V_9 , V_15 ) ;
V_10 |= V_16 ;
F_3 ( V_9 , V_15 , V_10 ) ;
for ( V_13 = 0 ; V_13 < 1000 ; V_13 ++ ) {
if ( F_10 ( V_7 ) )
return 0 ;
F_12 ( 10 , 20 ) ;
}
F_11 ( V_7 -> V_14 , L_2 ) ;
return - V_17 ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_9 = F_8 ( V_7 ) ;
F_3 ( V_9 , V_18 ,
~ V_19 ) ;
F_3 ( V_9 ,
V_20 , V_19 ) ;
F_3 ( V_9 , V_21 ,
~ V_22 & ~ V_23 ) ;
if ( F_14 ( V_24 ) )
F_3 ( V_9 ,
V_25 , V_23 ) ;
else
F_3 ( V_9 ,
V_25 ,
V_22 ) ;
}
static void F_15 ( struct V_6 * V_7 )
{
F_16 ( V_7 ) ;
F_9 ( V_7 ) ;
if ( F_14 ( V_24 ) )
F_17 ( V_7 ) ;
F_13 ( V_7 ) ;
}
static int F_18 ( struct V_26 * V_27 , unsigned int V_28 ,
T_2 V_29 )
{
F_19 ( V_28 , & V_30 , V_31 ) ;
F_20 ( V_28 , V_27 -> V_32 ) ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 )
{
struct V_33 * V_14 = V_7 -> V_14 ;
struct V_34 * V_35 = V_14 -> V_36 ;
struct V_34 * V_37 = F_22 ( V_35 , NULL ) ;
if ( ! V_37 ) {
F_11 ( V_14 , L_3 ) ;
return F_23 ( V_37 ) ;
}
V_7 -> V_26 = F_24 ( V_37 , 4 ,
& V_38 , V_7 ) ;
if ( ! V_7 -> V_26 ) {
F_11 ( V_14 , L_4 ) ;
return F_23 ( V_7 -> V_26 ) ;
}
return 0 ;
}
static T_3 F_25 ( int V_28 , void * V_39 )
{
struct V_6 * V_7 = V_39 ;
struct V_1 * V_9 = F_8 ( V_7 ) ;
T_1 V_10 ;
V_10 = F_1 ( V_9 , V_21 ) ;
switch ( V_10 ) {
case V_23 :
F_26 ( V_7 ) ;
break;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
F_27 ( F_28 ( V_7 -> V_26 , F_29 ( V_10 ) ) ) ;
break;
}
F_3 ( V_9 , V_21 , V_10 ) ;
return V_44 ;
}
static T_3 F_30 ( int V_28 , void * V_39 )
{
struct V_1 * V_9 = V_39 ;
T_1 V_10 ;
V_10 = F_1 ( V_9 , V_18 ) ;
if ( V_10 & V_45 )
F_31 ( V_9 -> V_14 , L_5 ) ;
if ( V_10 & V_46 )
F_31 ( V_9 -> V_14 , L_6 ) ;
if ( V_10 & V_47 )
F_31 ( V_9 -> V_14 , L_7 ) ;
if ( V_10 & V_48 )
F_31 ( V_9 -> V_14 , L_8 ) ;
if ( V_10 & V_49 )
F_31 ( V_9 -> V_14 , L_9 ) ;
if ( V_10 & V_50 )
F_31 ( V_9 -> V_14 , L_10 ) ;
if ( V_10 & V_51 )
F_31 ( V_9 -> V_14 ,
L_11 ) ;
if ( V_10 & V_52 )
F_31 ( V_9 -> V_14 ,
L_12 ) ;
if ( V_10 & V_53 )
F_31 ( V_9 -> V_14 ,
L_13 ) ;
if ( V_10 & V_54 )
F_31 ( V_9 -> V_14 , L_14 ) ;
if ( V_10 & V_55 )
F_31 ( V_9 -> V_14 , L_15 ) ;
if ( V_10 & V_56 )
F_31 ( V_9 -> V_14 , L_16 ) ;
if ( V_10 & V_57 )
F_31 ( V_9 -> V_14 , L_17 ) ;
F_3 ( V_9 , V_18 , V_10 ) ;
return V_44 ;
}
static int T_4 F_32 ( struct V_1 * V_9 ,
struct V_58 * V_59 )
{
int V_60 ;
struct V_6 * V_7 ;
struct V_61 * V_62 ;
struct V_33 * V_14 = & V_59 -> V_14 ;
V_7 = & V_9 -> V_7 ;
V_7 -> V_14 = V_14 ;
V_7 -> V_63 = & V_64 ;
V_7 -> V_28 = F_33 ( V_59 , 1 ) ;
if ( V_7 -> V_28 < 0 ) {
F_11 ( V_14 , L_18 ) ;
return - V_17 ;
}
V_60 = F_34 ( & V_59 -> V_14 , V_7 -> V_28 ,
F_25 , V_65 ,
L_19 , V_7 ) ;
if ( V_60 ) {
F_11 ( & V_59 -> V_14 , L_20 ) ;
return V_60 ;
}
if ( ! F_14 ( V_24 ) ) {
V_60 = F_21 ( V_7 ) ;
if ( V_60 < 0 )
return V_60 ;
}
V_62 = F_35 ( V_59 , V_66 , L_21 ) ;
V_7 -> V_8 = F_36 ( V_14 , V_62 -> V_67 , F_37 ( V_62 ) ) ;
if ( ! V_7 -> V_8 )
return - V_68 ;
V_60 = F_38 ( V_7 ) ;
if ( V_60 ) {
F_11 ( V_9 -> V_14 , L_22 ) ;
return V_60 ;
}
return 0 ;
}
static int T_4 F_39 ( struct V_58 * V_59 )
{
T_1 V_10 ;
int V_60 ;
int V_28 ;
int V_69 ;
int V_70 ;
struct V_71 * * V_71 ;
void T_5 * V_4 ;
struct V_61 * V_62 ;
struct V_1 * V_9 ;
struct V_33 * V_14 = & V_59 -> V_14 ;
struct V_34 * V_72 = V_14 -> V_36 ;
char V_73 [ 10 ] ;
int V_74 ;
enum V_75 V_76 ;
unsigned long V_77 ;
V_9 = F_40 ( V_14 , sizeof( * V_9 ) , V_78 ) ;
if ( ! V_9 )
return - V_68 ;
V_28 = F_33 ( V_59 , 0 ) ;
if ( V_28 < 0 ) {
F_11 ( V_14 , L_18 ) ;
return - V_17 ;
}
V_60 = F_34 ( V_14 , V_28 , F_30 ,
V_65 , L_23 , V_9 ) ;
if ( V_60 ) {
F_11 ( V_14 , L_20 ) ;
return V_60 ;
}
V_62 = F_35 ( V_59 , V_66 , L_24 ) ;
V_4 = F_41 ( V_14 , V_62 -> V_67 , F_37 ( V_62 ) ) ;
if ( ! V_4 )
return - V_68 ;
V_70 = F_42 ( V_72 , L_25 ) ;
if ( V_70 < 0 ) {
F_11 ( V_14 , L_26 ) ;
return V_70 ;
}
V_71 = F_40 ( V_14 , sizeof( * V_71 ) * V_70 , V_78 ) ;
if ( ! V_71 )
return - V_68 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
snprintf ( V_73 , sizeof( V_73 ) , L_27 , V_69 ) ;
V_71 [ V_69 ] = F_43 ( V_14 , V_73 ) ;
if ( F_44 ( V_71 [ V_69 ] ) )
return F_23 ( V_71 [ V_69 ] ) ;
V_60 = F_45 ( V_71 [ V_69 ] ) ;
if ( V_60 < 0 )
goto V_79;
V_60 = F_46 ( V_71 [ V_69 ] ) ;
if ( V_60 < 0 ) {
F_47 ( V_71 [ V_69 ] ) ;
goto V_79;
}
}
V_9 -> V_4 = V_4 ;
V_9 -> V_71 = V_71 ;
V_9 -> V_14 = V_14 ;
V_9 -> V_70 = V_70 ;
F_48 ( V_14 ) ;
V_60 = F_49 ( V_14 ) ;
if ( V_60 < 0 ) {
F_11 ( V_14 , L_28 ) ;
goto V_80;
}
V_74 = F_50 ( V_14 -> V_36 , 0 , & V_76 ) ;
if ( F_51 ( V_74 ) ) {
V_77 = ( V_76 & V_81 ) ?
V_82 : V_83 ;
V_60 = F_52 ( V_14 , V_74 , V_77 ,
L_29 ) ;
if ( V_60 ) {
F_11 ( & V_59 -> V_14 , L_30 ,
V_74 , V_60 ) ;
goto V_84;
}
} else if ( V_74 == - V_85 ) {
V_60 = - V_85 ;
goto V_84;
}
V_10 = F_1 ( V_9 , V_15 ) ;
V_10 &= ~ V_16 ;
F_3 ( V_9 , V_15 , V_10 ) ;
F_53 ( V_59 , V_9 ) ;
V_60 = F_32 ( V_9 , V_59 ) ;
if ( V_60 < 0 )
goto V_84;
return 0 ;
V_84:
F_54 ( V_14 ) ;
V_80:
F_55 ( V_14 ) ;
V_79:
while ( -- V_69 >= 0 ) {
F_56 ( V_71 [ V_69 ] ) ;
F_47 ( V_71 [ V_69 ] ) ;
}
return V_60 ;
}
static int T_6 F_57 ( struct V_58 * V_59 )
{
struct V_1 * V_9 = F_58 ( V_59 ) ;
struct V_6 * V_7 = & V_9 -> V_7 ;
struct V_33 * V_14 = & V_59 -> V_14 ;
int V_86 = V_9 -> V_70 ;
if ( V_7 -> V_26 )
F_59 ( V_7 -> V_26 ) ;
F_54 ( V_14 ) ;
F_55 ( V_14 ) ;
while ( V_86 -- ) {
F_56 ( V_9 -> V_71 [ V_86 ] ) ;
F_47 ( V_9 -> V_71 [ V_86 ] ) ;
}
return 0 ;
}
static int F_60 ( struct V_33 * V_14 )
{
struct V_1 * V_9 = F_61 ( V_14 ) ;
struct V_6 * V_7 = & V_9 -> V_7 ;
T_1 V_87 ;
V_87 = F_5 ( V_7 , V_88 ) ;
V_87 &= ~ V_89 ;
F_6 ( V_7 , V_88 , V_87 ) ;
return 0 ;
}
static int F_62 ( struct V_33 * V_14 )
{
struct V_1 * V_9 = F_61 ( V_14 ) ;
struct V_6 * V_7 = & V_9 -> V_7 ;
T_1 V_87 ;
V_87 = F_5 ( V_7 , V_88 ) ;
V_87 |= V_89 ;
F_6 ( V_7 , V_88 , V_87 ) ;
return 0 ;
}
static int F_63 ( struct V_33 * V_14 )
{
struct V_1 * V_9 = F_61 ( V_14 ) ;
int V_86 = V_9 -> V_70 ;
while ( V_86 -- ) {
F_56 ( V_9 -> V_71 [ V_86 ] ) ;
F_47 ( V_9 -> V_71 [ V_86 ] ) ;
}
return 0 ;
}
static int F_64 ( struct V_33 * V_14 )
{
struct V_1 * V_9 = F_61 ( V_14 ) ;
int V_70 = V_9 -> V_70 ;
int V_60 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
V_60 = F_45 ( V_9 -> V_71 [ V_69 ] ) ;
if ( V_60 < 0 )
goto V_79;
V_60 = F_46 ( V_9 -> V_71 [ V_69 ] ) ;
if ( V_60 < 0 ) {
F_47 ( V_9 -> V_71 [ V_69 ] ) ;
goto V_79;
}
}
return 0 ;
V_79:
while ( -- V_69 >= 0 ) {
F_56 ( V_9 -> V_71 [ V_69 ] ) ;
F_47 ( V_9 -> V_71 [ V_69 ] ) ;
}
return V_60 ;
}
