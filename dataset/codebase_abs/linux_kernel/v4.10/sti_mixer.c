const char * F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
return L_1 ;
case V_5 :
return L_2 ;
default:
return L_3 ;
}
}
static inline T_1 F_2 ( struct V_1 * V_2 , T_1 V_6 )
{
return F_3 ( V_2 -> V_7 + V_6 ) ;
}
static inline void F_4 ( struct V_1 * V_2 ,
T_1 V_6 , T_1 V_8 )
{
F_5 ( V_8 , V_2 -> V_7 + V_6 ) ;
}
static void F_6 ( struct V_9 * V_10 , int V_8 )
{
unsigned int V_11 ;
int V_12 = 0 ;
char * const V_13 [] = { L_4 , L_5 , L_6 , L_7 ,
L_8 , L_9 , L_10 } ;
F_7 ( V_10 , L_11 ) ;
for ( V_11 = 0 ; V_11 < 7 ; V_11 ++ ) {
if ( V_8 & 1 ) {
F_8 ( V_10 , L_12 , V_13 [ V_11 ] ) ;
V_12 ++ ;
}
V_8 = V_8 >> 1 ;
}
V_8 = V_8 >> 2 ;
if ( V_8 & 1 ) {
F_7 ( V_10 , L_13 ) ;
V_12 ++ ;
}
if ( ! V_12 )
F_7 ( V_10 , L_14 ) ;
}
static void F_9 ( struct V_9 * V_10 , int V_8 )
{
int V_11 ;
F_7 ( V_10 , L_15 ) ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ ) {
switch ( V_8 & V_15 ) {
case V_16 :
F_7 ( V_10 , L_5 ) ;
break;
case V_17 :
F_7 ( V_10 , L_6 ) ;
break;
case V_18 :
F_7 ( V_10 , L_7 ) ;
break;
case V_19 :
F_7 ( V_10 , L_8 ) ;
break;
case V_20 :
F_7 ( V_10 , L_9 ) ;
break;
case V_21 :
F_7 ( V_10 , L_10 ) ;
break;
default:
F_7 ( V_10 , L_16 ) ;
}
if ( V_11 < V_14 - 1 )
F_7 ( V_10 , L_17 ) ;
V_8 = V_8 >> 3 ;
}
}
static void F_10 ( struct V_9 * V_10 , void * V_22 )
{
int V_11 ;
for ( V_11 = 1 ; V_11 < 8 ; V_11 ++ )
F_8 ( V_10 , L_18 , ( int ) F_3 ( V_22 + V_11 * 4 ) ) ;
}
static int F_11 ( struct V_9 * V_10 , void * V_23 )
{
struct V_24 * V_25 = V_10 -> V_26 ;
struct V_1 * V_2 = (struct V_1 * ) V_25 -> V_27 -> V_28 ;
F_8 ( V_10 , L_19 ,
F_1 ( V_2 ) , V_2 -> V_7 ) ;
F_12 ( V_29 ) ;
F_6 ( V_10 , F_2 ( V_2 , V_29 ) ) ;
F_12 ( V_30 ) ;
F_12 ( V_31 ) ;
F_12 ( V_32 ) ;
F_12 ( V_33 ) ;
F_12 ( V_34 ) ;
F_12 ( V_35 ) ;
F_9 ( V_10 , F_2 ( V_2 , V_35 ) ) ;
F_12 ( V_36 ) ;
F_12 ( V_37 ) ;
F_12 ( V_38 ) ;
F_10 ( V_10 , V_2 -> V_7 + V_38 ) ;
F_7 ( V_10 , L_20 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
unsigned int V_11 ;
struct V_41 * V_42 ;
int V_43 ;
switch ( V_2 -> V_3 ) {
case V_4 :
V_42 = V_44 ;
V_43 = F_14 ( V_44 ) ;
break;
case V_5 :
V_42 = V_45 ;
V_43 = F_14 ( V_45 ) ;
break;
default:
return - V_46 ;
}
for ( V_11 = 0 ; V_11 < V_43 ; V_11 ++ )
V_42 [ V_11 ] . V_28 = V_2 ;
return F_15 ( V_42 ,
V_43 ,
V_40 -> V_47 , V_40 ) ;
}
void F_16 ( struct V_1 * V_2 , bool V_48 )
{
T_1 V_8 = F_2 ( V_2 , V_29 ) ;
V_8 &= ~ V_49 ;
V_8 |= V_48 ;
F_4 ( V_2 , V_29 , V_8 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned int V_50 )
{
F_4 ( V_2 , V_30 , V_50 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
T_1 V_53 , V_54 , V_55 , V_56 ;
V_53 = F_19 ( * V_52 , 0 ) ;
V_55 = F_19 ( * V_52 , V_52 -> V_57 - 1 ) ;
V_54 = F_20 ( * V_52 , 0 ) ;
V_56 = F_20 ( * V_52 , V_52 -> V_58 - 1 ) ;
F_4 ( V_2 , V_31 , V_53 << 16 | V_54 ) ;
F_4 ( V_2 , V_32 , V_55 << 16 | V_56 ) ;
}
int F_21 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
int V_61 , V_62 = V_60 -> V_63 . V_64 -> V_65 ;
unsigned int V_11 ;
T_1 V_66 , V_8 ;
switch ( V_60 -> V_67 ) {
case V_68 :
V_61 = V_18 ;
break;
case V_69 :
V_61 = V_19 ;
break;
case V_70 :
V_61 = V_20 ;
break;
case V_71 :
V_61 = V_21 ;
break;
case V_72 :
V_61 = V_16 ;
break;
case V_73 :
return 0 ;
default:
F_22 ( L_21 , V_60 -> V_67 ) ;
return 1 ;
}
V_8 = F_2 ( V_2 , V_35 ) ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ ) {
V_66 = V_15 << ( 3 * V_11 ) ;
if ( ( V_8 & V_66 ) == V_61 << ( 3 * V_11 ) )
break;
}
V_66 |= V_15 << ( 3 * V_62 ) ;
V_61 = V_61 << ( 3 * V_62 ) ;
F_23 ( L_22 , F_1 ( V_2 ) ,
F_24 ( V_60 ) , V_62 ) ;
F_25 ( V_2 -> V_74 , L_23 ,
V_61 , V_66 ) ;
V_8 &= ~ V_66 ;
V_8 |= V_61 ;
F_4 ( V_2 , V_35 , V_8 ) ;
F_25 ( V_2 -> V_74 , L_24 ,
F_2 ( V_2 , V_35 ) ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
T_1 V_53 , V_54 , V_55 , V_56 ;
V_53 = F_19 ( * V_52 , 0 ) ;
V_55 = F_19 ( * V_52 , V_52 -> V_57 - 1 ) ;
V_54 = F_20 ( * V_52 , 0 ) ;
V_56 = F_20 ( * V_52 , V_52 -> V_58 - 1 ) ;
F_23 ( L_25 ,
F_1 ( V_2 ) , V_54 , V_53 , V_56 , V_55 ) ;
F_4 ( V_2 , V_33 , V_53 << 16 | V_54 ) ;
F_4 ( V_2 , V_34 , V_55 << 16 | V_56 ) ;
F_17 ( V_2 , V_75 ) ;
F_18 ( V_2 , V_52 ) ;
F_16 ( V_2 , true ) ;
return 0 ;
}
static T_1 F_27 ( struct V_59 * V_60 )
{
switch ( V_60 -> V_67 ) {
case V_76 :
return V_49 ;
case V_68 :
return V_77 ;
case V_69 :
return V_78 ;
case V_70 :
return V_79 ;
case V_71 :
return V_80 ;
case V_72 :
return V_81 ;
case V_73 :
return V_82 ;
default:
return 0 ;
}
}
int F_28 ( struct V_1 * V_2 ,
struct V_59 * V_60 , bool V_83 )
{
T_1 V_66 , V_8 ;
F_23 ( L_26 , V_83 ? L_27 : L_28 ,
F_1 ( V_2 ) , F_24 ( V_60 ) ) ;
V_66 = F_27 ( V_60 ) ;
if ( ! V_66 ) {
F_22 ( L_29 ) ;
return - V_46 ;
}
V_8 = F_2 ( V_2 , V_29 ) ;
V_8 &= ~ V_66 ;
V_8 |= V_83 ? V_66 : 0 ;
F_4 ( V_2 , V_29 , V_8 ) ;
return 0 ;
}
struct V_1 * F_29 ( struct V_84 * V_74 ,
struct V_85 * V_86 ,
int V_3 ,
void T_2 * V_87 )
{
struct V_1 * V_2 = F_30 ( V_74 , sizeof( * V_2 ) , V_88 ) ;
F_25 ( V_74 , L_30 , V_89 ) ;
if ( ! V_2 ) {
F_22 ( L_31 ) ;
return NULL ;
}
V_2 -> V_7 = V_87 ;
V_2 -> V_74 = V_74 ;
V_2 -> V_3 = V_3 ;
F_23 ( L_32 ,
F_1 ( V_2 ) , V_2 -> V_7 ) ;
return V_2 ;
}
