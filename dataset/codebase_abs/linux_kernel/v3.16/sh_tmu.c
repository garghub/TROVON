static inline unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 ;
if ( V_3 == V_5 ) {
switch ( V_2 -> V_6 -> V_7 ) {
case V_8 :
return F_2 ( V_2 -> V_6 -> V_9 ) ;
case V_10 :
return F_2 ( V_2 -> V_6 -> V_9 + 2 ) ;
case V_11 :
return F_2 ( V_2 -> V_6 -> V_9 + 4 ) ;
}
}
V_4 = V_3 << 2 ;
if ( V_3 == V_12 )
return F_3 ( V_2 -> V_13 + V_4 ) ;
else
return F_4 ( V_2 -> V_13 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_14 )
{
unsigned long V_4 ;
if ( V_3 == V_5 ) {
switch ( V_2 -> V_6 -> V_7 ) {
case V_8 :
return F_6 ( V_14 , V_2 -> V_6 -> V_9 ) ;
case V_10 :
return F_6 ( V_14 , V_2 -> V_6 -> V_9 + 2 ) ;
case V_11 :
return F_6 ( V_14 , V_2 -> V_6 -> V_9 + 4 ) ;
}
}
V_4 = V_3 << 2 ;
if ( V_3 == V_12 )
F_7 ( V_14 , V_2 -> V_13 + V_4 ) ;
else
F_8 ( V_14 , V_2 -> V_13 + V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_15 )
{
unsigned long V_16 , V_14 ;
F_10 ( & V_17 , V_16 ) ;
V_14 = F_1 ( V_2 , V_5 ) ;
if ( V_15 )
V_14 |= 1 << V_2 -> V_18 ;
else
V_14 &= ~ ( 1 << V_2 -> V_18 ) ;
F_5 ( V_2 , V_5 , V_14 ) ;
F_11 ( & V_17 , V_16 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_13 ( V_2 -> V_6 -> V_20 ) ;
if ( V_19 ) {
F_14 ( & V_2 -> V_6 -> V_21 -> V_22 , L_1 ,
V_2 -> V_18 ) ;
return V_19 ;
}
F_9 ( V_2 , 0 ) ;
F_5 ( V_2 , V_23 , 0xffffffff ) ;
F_5 ( V_2 , V_24 , 0xffffffff ) ;
V_2 -> V_25 = F_15 ( V_2 -> V_6 -> V_20 ) / 4 ;
F_5 ( V_2 , V_12 , V_26 ) ;
F_9 ( V_2 , 1 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 ++ > 0 )
return 0 ;
F_17 ( & V_2 -> V_6 -> V_21 -> V_22 ) ;
F_18 ( & V_2 -> V_6 -> V_21 -> V_22 , true ) ;
return F_12 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0 ) ;
F_5 ( V_2 , V_12 , V_26 ) ;
F_20 ( V_2 -> V_6 -> V_20 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( F_22 ( V_2 -> V_27 == 0 ) )
return;
if ( -- V_2 -> V_27 > 0 )
return;
F_19 ( V_2 ) ;
F_18 ( & V_2 -> V_6 -> V_21 -> V_22 , false ) ;
F_23 ( & V_2 -> V_6 -> V_21 -> V_22 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned long V_28 ,
int V_29 )
{
F_9 ( V_2 , 0 ) ;
F_1 ( V_2 , V_12 ) ;
F_5 ( V_2 , V_12 , V_30 | V_26 ) ;
if ( V_29 )
F_5 ( V_2 , V_23 , V_28 ) ;
else
F_5 ( V_2 , V_23 , 0xffffffff ) ;
F_5 ( V_2 , V_24 , V_28 ) ;
F_9 ( V_2 , 1 ) ;
}
static T_1 F_25 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
if ( V_2 -> V_33 . V_34 == V_35 )
F_5 ( V_2 , V_12 , V_26 ) ;
else
F_5 ( V_2 , V_12 , V_30 | V_26 ) ;
V_2 -> V_33 . V_36 ( & V_2 -> V_33 ) ;
return V_37 ;
}
static struct V_1 * F_26 ( struct V_38 * V_39 )
{
return F_27 ( V_39 , struct V_1 , V_39 ) ;
}
static T_2 F_28 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
return F_1 ( V_2 , V_24 ) ^ 0xffffffff ;
}
static int F_29 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
int V_19 ;
if ( F_22 ( V_2 -> V_40 ) )
return 0 ;
V_19 = F_16 ( V_2 ) ;
if ( ! V_19 ) {
F_30 ( V_39 , V_2 -> V_25 ) ;
V_2 -> V_40 = true ;
}
return V_19 ;
}
static void F_31 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
if ( F_22 ( ! V_2 -> V_40 ) )
return;
F_21 ( V_2 ) ;
V_2 -> V_40 = false ;
}
static void F_32 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
if ( ! V_2 -> V_40 )
return;
if ( -- V_2 -> V_27 == 0 ) {
F_19 ( V_2 ) ;
F_33 ( & V_2 -> V_6 -> V_21 -> V_22 ) ;
}
}
static void F_34 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
if ( ! V_2 -> V_40 )
return;
if ( V_2 -> V_27 ++ == 0 ) {
F_35 ( & V_2 -> V_6 -> V_21 -> V_22 ) ;
F_12 ( V_2 ) ;
}
}
static int F_36 ( struct V_1 * V_2 ,
const char * V_41 )
{
struct V_38 * V_39 = & V_2 -> V_39 ;
V_39 -> V_41 = V_41 ;
V_39 -> V_42 = 200 ;
V_39 -> V_43 = F_28 ;
V_39 -> V_44 = F_29 ;
V_39 -> V_45 = F_31 ;
V_39 -> V_46 = F_32 ;
V_39 -> V_47 = F_34 ;
V_39 -> V_48 = F_37 ( 32 ) ;
V_39 -> V_16 = V_49 ;
F_38 ( & V_2 -> V_6 -> V_21 -> V_22 , L_2 ,
V_2 -> V_18 ) ;
F_39 ( V_39 , 1 ) ;
return 0 ;
}
static struct V_1 * F_40 ( struct V_50 * V_33 )
{
return F_27 ( V_33 , struct V_1 , V_33 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_29 )
{
struct V_50 * V_33 = & V_2 -> V_33 ;
F_16 ( V_2 ) ;
F_42 ( V_33 , V_2 -> V_25 ) ;
if ( V_29 ) {
V_2 -> V_29 = ( V_2 -> V_25 + V_51 / 2 ) / V_51 ;
F_24 ( V_2 , V_2 -> V_29 , 1 ) ;
}
}
static void F_43 ( enum V_52 V_34 ,
struct V_50 * V_33 )
{
struct V_1 * V_2 = F_40 ( V_33 ) ;
int V_53 = 0 ;
switch ( V_33 -> V_34 ) {
case V_54 :
case V_35 :
F_21 ( V_2 ) ;
V_53 = 1 ;
break;
default:
break;
}
switch ( V_34 ) {
case V_54 :
F_38 ( & V_2 -> V_6 -> V_21 -> V_22 ,
L_3 , V_2 -> V_18 ) ;
F_41 ( V_2 , 1 ) ;
break;
case V_35 :
F_38 ( & V_2 -> V_6 -> V_21 -> V_22 ,
L_4 , V_2 -> V_18 ) ;
F_41 ( V_2 , 0 ) ;
break;
case V_55 :
if ( ! V_53 )
F_21 ( V_2 ) ;
break;
case V_56 :
default:
break;
}
}
static int F_44 ( unsigned long V_28 ,
struct V_50 * V_33 )
{
struct V_1 * V_2 = F_40 ( V_33 ) ;
F_45 ( V_33 -> V_34 != V_35 ) ;
F_24 ( V_2 , V_28 , 0 ) ;
return 0 ;
}
static void F_46 ( struct V_50 * V_33 )
{
F_33 ( & F_40 ( V_33 ) -> V_6 -> V_21 -> V_22 ) ;
}
static void F_47 ( struct V_50 * V_33 )
{
F_35 ( & F_40 ( V_33 ) -> V_6 -> V_21 -> V_22 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
const char * V_41 )
{
struct V_50 * V_33 = & V_2 -> V_33 ;
int V_19 ;
V_33 -> V_41 = V_41 ;
V_33 -> V_57 = V_58 ;
V_33 -> V_57 |= V_59 ;
V_33 -> V_42 = 200 ;
V_33 -> V_60 = F_49 ( 0 ) ;
V_33 -> V_61 = F_44 ;
V_33 -> V_62 = F_43 ;
V_33 -> V_46 = F_46 ;
V_33 -> V_47 = F_47 ;
F_38 ( & V_2 -> V_6 -> V_21 -> V_22 , L_5 ,
V_2 -> V_18 ) ;
F_50 ( V_33 , 1 , 0x300 , 0xffffffff ) ;
V_19 = F_51 ( V_2 -> V_31 , F_25 ,
V_63 | V_64 | V_65 ,
F_52 ( & V_2 -> V_6 -> V_21 -> V_22 ) , V_2 ) ;
if ( V_19 ) {
F_14 ( & V_2 -> V_6 -> V_21 -> V_22 , L_6 ,
V_2 -> V_18 , V_2 -> V_31 ) ;
return;
}
}
static int F_53 ( struct V_1 * V_2 , const char * V_41 ,
bool V_66 , bool V_38 )
{
if ( V_66 ) {
V_2 -> V_6 -> V_67 = true ;
F_48 ( V_2 , V_41 ) ;
} else if ( V_38 ) {
V_2 -> V_6 -> V_68 = true ;
F_36 ( V_2 , V_41 ) ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , unsigned int V_18 ,
bool V_66 , bool V_38 ,
struct V_69 * V_6 )
{
if ( ! V_66 && ! V_38 )
return 0 ;
V_2 -> V_6 = V_6 ;
if ( V_6 -> V_7 == V_8 ) {
struct V_70 * V_71 = V_6 -> V_21 -> V_22 . V_72 ;
V_2 -> V_18 = V_71 -> V_73 / 12 ;
V_2 -> V_13 = V_6 -> V_9 + V_71 -> V_73 ;
} else {
V_2 -> V_18 = V_18 ;
if ( V_6 -> V_7 == V_10 )
V_2 -> V_13 = V_6 -> V_9 + 4 + V_2 -> V_18 * 12 ;
else
V_2 -> V_13 = V_6 -> V_9 + 8 + V_2 -> V_18 * 12 ;
}
V_2 -> V_31 = F_55 ( V_6 -> V_21 , V_18 ) ;
if ( V_2 -> V_31 < 0 ) {
F_14 ( & V_6 -> V_21 -> V_22 , L_7 ,
V_2 -> V_18 ) ;
return V_2 -> V_31 ;
}
V_2 -> V_40 = false ;
V_2 -> V_27 = 0 ;
return F_53 ( V_2 , F_52 ( & V_6 -> V_21 -> V_22 ) ,
V_66 , V_38 ) ;
}
static int F_56 ( struct V_69 * V_6 )
{
struct V_74 * V_75 ;
V_75 = F_57 ( V_6 -> V_21 , V_76 , 0 ) ;
if ( ! V_75 ) {
F_14 ( & V_6 -> V_21 -> V_22 , L_8 ) ;
return - V_77 ;
}
V_6 -> V_9 = F_58 ( V_75 -> V_15 , F_59 ( V_75 ) ) ;
if ( V_6 -> V_9 == NULL )
return - V_77 ;
if ( V_6 -> V_7 == V_8 ) {
struct V_70 * V_71 = V_6 -> V_21 -> V_22 . V_72 ;
V_6 -> V_9 -= V_71 -> V_73 ;
}
return 0 ;
}
static void F_60 ( struct V_69 * V_6 )
{
if ( V_6 -> V_7 == V_8 ) {
struct V_70 * V_71 = V_6 -> V_21 -> V_22 . V_72 ;
V_6 -> V_9 += V_71 -> V_73 ;
}
F_61 ( V_6 -> V_9 ) ;
}
static int F_62 ( struct V_69 * V_6 , struct V_78 * V_21 )
{
struct V_70 * V_71 = V_21 -> V_22 . V_72 ;
const struct V_79 * V_80 = V_21 -> V_81 ;
unsigned int V_82 ;
int V_19 ;
if ( ! V_71 ) {
F_14 ( & V_6 -> V_21 -> V_22 , L_9 ) ;
return - V_77 ;
}
V_6 -> V_21 = V_21 ;
V_6 -> V_7 = V_80 -> V_83 ;
V_6 -> V_20 = F_63 ( & V_6 -> V_21 -> V_22 ,
V_6 -> V_7 == V_8 ? L_10 : L_11 ) ;
if ( F_64 ( V_6 -> V_20 ) ) {
F_14 ( & V_6 -> V_21 -> V_22 , L_12 ) ;
return F_65 ( V_6 -> V_20 ) ;
}
V_19 = F_66 ( V_6 -> V_20 ) ;
if ( V_19 < 0 )
goto V_84;
V_19 = F_56 ( V_6 ) ;
if ( V_19 < 0 ) {
F_14 ( & V_6 -> V_21 -> V_22 , L_13 ) ;
goto V_85;
}
if ( V_6 -> V_7 == V_8 )
V_6 -> V_86 = 1 ;
else
V_6 -> V_86 = F_67 ( V_71 -> V_87 ) ;
V_6 -> V_88 = F_68 ( sizeof( * V_6 -> V_88 ) * V_6 -> V_86 ,
V_89 ) ;
if ( V_6 -> V_88 == NULL ) {
V_19 = - V_90 ;
goto V_91;
}
if ( V_6 -> V_7 == V_8 ) {
V_19 = F_54 ( & V_6 -> V_88 [ 0 ] , 0 ,
V_71 -> V_92 != 0 ,
V_71 -> V_93 != 0 , V_6 ) ;
if ( V_19 < 0 )
goto V_91;
} else {
for ( V_82 = 0 ; V_82 < V_6 -> V_86 ; ++ V_82 ) {
V_19 = F_54 ( & V_6 -> V_88 [ V_82 ] , V_82 ,
V_82 == 0 , V_82 == 1 , V_6 ) ;
if ( V_19 < 0 )
goto V_91;
}
}
F_69 ( V_21 , V_6 ) ;
return 0 ;
V_91:
F_70 ( V_6 -> V_88 ) ;
F_60 ( V_6 ) ;
V_85:
F_71 ( V_6 -> V_20 ) ;
V_84:
F_72 ( V_6 -> V_20 ) ;
return V_19 ;
}
static int F_73 ( struct V_78 * V_21 )
{
struct V_69 * V_6 = F_74 ( V_21 ) ;
int V_19 ;
if ( ! F_75 ( V_21 ) ) {
F_76 ( & V_21 -> V_22 ) ;
F_77 ( & V_21 -> V_22 ) ;
}
if ( V_6 ) {
F_38 ( & V_21 -> V_22 , L_14 ) ;
goto V_94;
}
V_6 = F_68 ( sizeof( * V_6 ) , V_89 ) ;
if ( V_6 == NULL )
return - V_90 ;
V_19 = F_62 ( V_6 , V_21 ) ;
if ( V_19 ) {
F_70 ( V_6 ) ;
F_78 ( & V_21 -> V_22 ) ;
return V_19 ;
}
if ( F_75 ( V_21 ) )
return 0 ;
V_94:
if ( V_6 -> V_67 || V_6 -> V_68 )
F_79 ( & V_21 -> V_22 ) ;
else
F_78 ( & V_21 -> V_22 ) ;
return 0 ;
}
static int F_80 ( struct V_78 * V_21 )
{
return - V_95 ;
}
static int T_3 F_81 ( void )
{
return F_82 ( & V_96 ) ;
}
static void T_4 F_83 ( void )
{
F_84 ( & V_96 ) ;
}
