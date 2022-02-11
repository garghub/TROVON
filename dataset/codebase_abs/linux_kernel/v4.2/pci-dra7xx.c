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
static int F_7 ( struct V_6 * V_7 )
{
struct V_1 * V_8 = F_6 ( V_7 ) ;
T_1 V_9 ;
unsigned int V_12 ;
if ( F_8 ( V_7 ) ) {
F_9 ( V_7 -> V_13 , L_1 ) ;
return 0 ;
}
V_9 = F_1 ( V_8 , V_14 ) ;
V_9 |= V_15 ;
F_3 ( V_8 , V_14 , V_9 ) ;
for ( V_12 = 0 ; V_12 < 1000 ; V_12 ++ ) {
if ( F_8 ( V_7 ) )
return 0 ;
F_10 ( 10 , 20 ) ;
}
F_9 ( V_7 -> V_13 , L_2 ) ;
return - V_16 ;
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_8 = F_6 ( V_7 ) ;
F_3 ( V_8 , V_17 ,
~ V_18 ) ;
F_3 ( V_8 ,
V_19 , V_18 ) ;
F_3 ( V_8 , V_20 ,
~ V_21 & ~ V_22 ) ;
if ( F_12 ( V_23 ) )
F_3 ( V_8 ,
V_24 , V_22 ) ;
else
F_3 ( V_8 ,
V_24 ,
V_21 ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
F_14 ( V_7 ) ;
F_7 ( V_7 ) ;
if ( F_12 ( V_23 ) )
F_15 ( V_7 ) ;
F_11 ( V_7 ) ;
}
static int F_16 ( struct V_25 * V_26 , unsigned int V_27 ,
T_2 V_28 )
{
F_17 ( V_27 , & V_29 , V_30 ) ;
F_18 ( V_27 , V_26 -> V_31 ) ;
F_19 ( V_27 , V_32 ) ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_33 * V_13 = V_7 -> V_13 ;
struct V_34 * V_35 = V_13 -> V_36 ;
struct V_34 * V_37 = F_21 ( V_35 , NULL ) ;
if ( ! V_37 ) {
F_9 ( V_13 , L_3 ) ;
return F_22 ( V_37 ) ;
}
V_7 -> V_25 = F_23 ( V_37 , 4 ,
& V_38 , V_7 ) ;
if ( ! V_7 -> V_25 ) {
F_9 ( V_13 , L_4 ) ;
return F_22 ( V_7 -> V_25 ) ;
}
return 0 ;
}
static T_3 F_24 ( int V_27 , void * V_39 )
{
struct V_6 * V_7 = V_39 ;
struct V_1 * V_8 = F_6 ( V_7 ) ;
T_1 V_9 ;
V_9 = F_1 ( V_8 , V_20 ) ;
switch ( V_9 ) {
case V_22 :
F_25 ( V_7 ) ;
break;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
F_26 ( F_27 ( V_7 -> V_25 , F_28 ( V_9 ) ) ) ;
break;
}
F_3 ( V_8 , V_20 , V_9 ) ;
return V_44 ;
}
static T_3 F_29 ( int V_27 , void * V_39 )
{
struct V_1 * V_8 = V_39 ;
T_1 V_9 ;
V_9 = F_1 ( V_8 , V_17 ) ;
if ( V_9 & V_45 )
F_30 ( V_8 -> V_13 , L_5 ) ;
if ( V_9 & V_46 )
F_30 ( V_8 -> V_13 , L_6 ) ;
if ( V_9 & V_47 )
F_30 ( V_8 -> V_13 , L_7 ) ;
if ( V_9 & V_48 )
F_30 ( V_8 -> V_13 , L_8 ) ;
if ( V_9 & V_49 )
F_30 ( V_8 -> V_13 , L_9 ) ;
if ( V_9 & V_50 )
F_30 ( V_8 -> V_13 , L_10 ) ;
if ( V_9 & V_51 )
F_30 ( V_8 -> V_13 ,
L_11 ) ;
if ( V_9 & V_52 )
F_30 ( V_8 -> V_13 ,
L_12 ) ;
if ( V_9 & V_53 )
F_30 ( V_8 -> V_13 ,
L_13 ) ;
if ( V_9 & V_54 )
F_30 ( V_8 -> V_13 , L_14 ) ;
if ( V_9 & V_55 )
F_30 ( V_8 -> V_13 , L_15 ) ;
if ( V_9 & V_56 )
F_30 ( V_8 -> V_13 , L_16 ) ;
if ( V_9 & V_57 )
F_30 ( V_8 -> V_13 , L_17 ) ;
F_3 ( V_8 , V_17 , V_9 ) ;
return V_44 ;
}
static int T_4 F_31 ( struct V_1 * V_8 ,
struct V_58 * V_59 )
{
int V_60 ;
struct V_6 * V_7 ;
struct V_61 * V_62 ;
struct V_33 * V_13 = & V_59 -> V_13 ;
V_7 = & V_8 -> V_7 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_63 = & V_64 ;
V_7 -> V_27 = F_32 ( V_59 , 1 ) ;
if ( V_7 -> V_27 < 0 ) {
F_9 ( V_13 , L_18 ) ;
return - V_16 ;
}
V_60 = F_33 ( & V_59 -> V_13 , V_7 -> V_27 ,
F_24 , V_65 ,
L_19 , V_7 ) ;
if ( V_60 ) {
F_9 ( & V_59 -> V_13 , L_20 ) ;
return V_60 ;
}
if ( ! F_12 ( V_23 ) ) {
V_60 = F_20 ( V_7 ) ;
if ( V_60 < 0 )
return V_60 ;
}
V_62 = F_34 ( V_59 , V_66 , L_21 ) ;
V_7 -> V_67 = F_35 ( V_13 , V_62 -> V_68 , F_36 ( V_62 ) ) ;
if ( ! V_7 -> V_67 )
return - V_69 ;
V_60 = F_37 ( V_7 ) ;
if ( V_60 ) {
F_9 ( V_8 -> V_13 , L_22 ) ;
return V_60 ;
}
return 0 ;
}
static int T_4 F_38 ( struct V_58 * V_59 )
{
T_1 V_9 ;
int V_60 ;
int V_27 ;
int V_70 ;
int V_71 ;
struct V_72 * * V_72 ;
void T_5 * V_4 ;
struct V_61 * V_62 ;
struct V_1 * V_8 ;
struct V_33 * V_13 = & V_59 -> V_13 ;
struct V_34 * V_73 = V_13 -> V_36 ;
char V_74 [ 10 ] ;
V_8 = F_39 ( V_13 , sizeof( * V_8 ) , V_75 ) ;
if ( ! V_8 )
return - V_69 ;
V_27 = F_32 ( V_59 , 0 ) ;
if ( V_27 < 0 ) {
F_9 ( V_13 , L_18 ) ;
return - V_16 ;
}
V_60 = F_33 ( V_13 , V_27 , F_29 ,
V_65 , L_23 , V_8 ) ;
if ( V_60 ) {
F_9 ( V_13 , L_20 ) ;
return V_60 ;
}
V_62 = F_34 ( V_59 , V_66 , L_24 ) ;
V_4 = F_40 ( V_13 , V_62 -> V_68 , F_36 ( V_62 ) ) ;
if ( ! V_4 )
return - V_69 ;
V_71 = F_41 ( V_73 , L_25 ) ;
if ( V_71 < 0 ) {
F_9 ( V_13 , L_26 ) ;
return V_71 ;
}
V_72 = F_39 ( V_13 , sizeof( * V_72 ) * V_71 , V_75 ) ;
if ( ! V_72 )
return - V_69 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
snprintf ( V_74 , sizeof( V_74 ) , L_27 , V_70 ) ;
V_72 [ V_70 ] = F_42 ( V_13 , V_74 ) ;
if ( F_43 ( V_72 [ V_70 ] ) )
return F_22 ( V_72 [ V_70 ] ) ;
V_60 = F_44 ( V_72 [ V_70 ] ) ;
if ( V_60 < 0 )
goto V_76;
V_60 = F_45 ( V_72 [ V_70 ] ) ;
if ( V_60 < 0 ) {
F_46 ( V_72 [ V_70 ] ) ;
goto V_76;
}
}
V_8 -> V_4 = V_4 ;
V_8 -> V_72 = V_72 ;
V_8 -> V_13 = V_13 ;
V_8 -> V_71 = V_71 ;
F_47 ( V_13 ) ;
V_60 = F_48 ( V_13 ) ;
if ( F_49 ( V_60 ) ) {
F_9 ( V_13 , L_28 ) ;
goto V_76;
}
V_9 = F_1 ( V_8 , V_14 ) ;
V_9 &= ~ V_15 ;
F_3 ( V_8 , V_14 , V_9 ) ;
F_50 ( V_59 , V_8 ) ;
V_60 = F_31 ( V_8 , V_59 ) ;
if ( V_60 < 0 )
goto V_77;
return 0 ;
V_77:
F_51 ( V_13 ) ;
F_52 ( V_13 ) ;
V_76:
while ( -- V_70 >= 0 ) {
F_53 ( V_72 [ V_70 ] ) ;
F_46 ( V_72 [ V_70 ] ) ;
}
return V_60 ;
}
static int T_6 F_54 ( struct V_58 * V_59 )
{
struct V_1 * V_8 = F_55 ( V_59 ) ;
struct V_6 * V_7 = & V_8 -> V_7 ;
struct V_33 * V_13 = & V_59 -> V_13 ;
int V_78 = V_8 -> V_71 ;
if ( V_7 -> V_25 )
F_56 ( V_7 -> V_25 ) ;
F_51 ( V_13 ) ;
F_52 ( V_13 ) ;
while ( V_78 -- ) {
F_53 ( V_8 -> V_72 [ V_78 ] ) ;
F_46 ( V_8 -> V_72 [ V_78 ] ) ;
}
return 0 ;
}
