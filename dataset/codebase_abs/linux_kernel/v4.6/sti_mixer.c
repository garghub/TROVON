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
struct V_29 * V_30 = V_25 -> V_31 -> V_30 ;
int V_32 ;
V_32 = F_12 ( & V_30 -> V_33 ) ;
if ( V_32 )
return V_32 ;
F_8 ( V_10 , L_19 ,
F_1 ( V_2 ) , V_2 -> V_7 ) ;
F_13 ( V_34 ) ;
F_6 ( V_10 , F_2 ( V_2 , V_34 ) ) ;
F_13 ( V_35 ) ;
F_13 ( V_36 ) ;
F_13 ( V_37 ) ;
F_13 ( V_38 ) ;
F_13 ( V_39 ) ;
F_13 ( V_40 ) ;
F_9 ( V_10 , F_2 ( V_2 , V_40 ) ) ;
F_13 ( V_41 ) ;
F_13 ( V_42 ) ;
F_13 ( V_43 ) ;
F_10 ( V_10 , V_2 -> V_7 + V_43 ) ;
F_7 ( V_10 , L_20 ) ;
F_14 ( & V_30 -> V_33 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_44 * V_31 )
{
unsigned int V_11 ;
struct V_45 * V_46 ;
int V_47 ;
switch ( V_2 -> V_3 ) {
case V_4 :
V_46 = V_48 ;
V_47 = F_16 ( V_48 ) ;
break;
case V_5 :
V_46 = V_49 ;
V_47 = F_16 ( V_49 ) ;
break;
default:
return - V_50 ;
}
for ( V_11 = 0 ; V_11 < V_47 ; V_11 ++ )
V_46 [ V_11 ] . V_28 = V_2 ;
return F_17 ( V_46 ,
V_47 ,
V_31 -> V_51 , V_31 ) ;
}
void F_18 ( struct V_1 * V_2 , bool V_52 )
{
T_1 V_8 = F_2 ( V_2 , V_34 ) ;
V_8 &= ~ V_53 ;
V_8 |= V_52 ;
F_4 ( V_2 , V_34 , V_8 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
unsigned int V_54 )
{
F_4 ( V_2 , V_35 , V_54 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
T_1 V_57 , V_58 , V_59 , V_60 ;
V_57 = F_21 ( * V_56 , 0 ) ;
V_59 = F_21 ( * V_56 , V_56 -> V_61 - 1 ) ;
V_58 = F_22 ( * V_56 , 0 ) ;
V_60 = F_22 ( * V_56 , V_56 -> V_62 - 1 ) ;
F_4 ( V_2 , V_36 , V_57 << 16 | V_58 ) ;
F_4 ( V_2 , V_37 , V_59 << 16 | V_60 ) ;
}
int F_23 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
int V_65 , V_66 = V_64 -> V_67 ;
unsigned int V_11 ;
T_1 V_68 , V_8 ;
if ( ( V_66 < 1 ) || ( V_66 > V_14 ) )
return 1 ;
switch ( V_64 -> V_69 ) {
case V_70 :
V_65 = V_18 ;
break;
case V_71 :
V_65 = V_19 ;
break;
case V_72 :
V_65 = V_20 ;
break;
case V_73 :
V_65 = V_21 ;
break;
case V_74 :
V_65 = V_16 ;
break;
case V_75 :
return 0 ;
default:
F_24 ( L_21 , V_64 -> V_69 ) ;
return 1 ;
}
V_8 = F_2 ( V_2 , V_40 ) ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ ) {
V_68 = V_15 << ( 3 * V_11 ) ;
if ( ( V_8 & V_68 ) == V_65 << ( 3 * V_11 ) )
break;
}
V_68 |= V_15 << ( 3 * ( V_66 - 1 ) ) ;
V_65 = V_65 << ( 3 * ( V_66 - 1 ) ) ;
F_25 ( L_22 , F_1 ( V_2 ) ,
F_26 ( V_64 ) , V_66 ) ;
F_27 ( V_2 -> V_30 , L_23 ,
V_65 , V_68 ) ;
V_8 &= ~ V_68 ;
V_8 |= V_65 ;
F_4 ( V_2 , V_40 , V_8 ) ;
F_27 ( V_2 -> V_30 , L_24 ,
F_2 ( V_2 , V_40 ) ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
T_1 V_57 , V_58 , V_59 , V_60 ;
V_57 = F_21 ( * V_56 , 0 ) ;
V_59 = F_21 ( * V_56 , V_56 -> V_61 - 1 ) ;
V_58 = F_22 ( * V_56 , 0 ) ;
V_60 = F_22 ( * V_56 , V_56 -> V_62 - 1 ) ;
F_25 ( L_25 ,
F_1 ( V_2 ) , V_58 , V_57 , V_60 , V_59 ) ;
F_4 ( V_2 , V_38 , V_57 << 16 | V_58 ) ;
F_4 ( V_2 , V_39 , V_59 << 16 | V_60 ) ;
F_19 ( V_2 , V_76 ) ;
F_20 ( V_2 , V_56 ) ;
F_18 ( V_2 , true ) ;
return 0 ;
}
static T_1 F_29 ( struct V_63 * V_64 )
{
switch ( V_64 -> V_69 ) {
case V_77 :
return V_53 ;
case V_70 :
return V_78 ;
case V_71 :
return V_79 ;
case V_72 :
return V_80 ;
case V_73 :
return V_81 ;
case V_74 :
return V_82 ;
case V_75 :
return V_83 ;
default:
return 0 ;
}
}
int F_30 ( struct V_1 * V_2 ,
struct V_63 * V_64 , bool V_84 )
{
T_1 V_68 , V_8 ;
F_25 ( L_26 , V_84 ? L_27 : L_28 ,
F_1 ( V_2 ) , F_26 ( V_64 ) ) ;
V_68 = F_29 ( V_64 ) ;
if ( ! V_68 ) {
F_24 ( L_29 ) ;
return - V_50 ;
}
V_8 = F_2 ( V_2 , V_34 ) ;
V_8 &= ~ V_68 ;
V_8 |= V_84 ? V_68 : 0 ;
F_4 ( V_2 , V_34 , V_8 ) ;
return 0 ;
}
void F_31 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < F_16 ( V_85 ) ; V_11 ++ )
F_4 ( V_2 , V_43 + ( V_11 * 4 ) ,
V_85 [ V_11 ] ) ;
}
struct V_1 * F_32 ( struct V_86 * V_30 ,
struct V_29 * V_87 ,
int V_3 ,
void T_2 * V_88 )
{
struct V_1 * V_2 = F_33 ( V_30 , sizeof( * V_2 ) , V_89 ) ;
struct V_90 * V_91 = V_30 -> V_92 ;
F_27 ( V_30 , L_30 , V_93 ) ;
if ( ! V_2 ) {
F_24 ( L_31 ) ;
return NULL ;
}
V_2 -> V_7 = V_88 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_3 = V_3 ;
if ( F_34 ( V_91 , L_32 ) )
F_31 ( V_2 ) ;
F_25 ( L_33 ,
F_1 ( V_2 ) , V_2 -> V_7 ) ;
if ( F_15 ( V_2 , V_87 -> V_94 ) )
F_24 ( L_34 ) ;
return V_2 ;
}
