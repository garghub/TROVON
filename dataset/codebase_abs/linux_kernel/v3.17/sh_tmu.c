static inline unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 ;
if ( V_3 == V_5 ) {
switch ( V_2 -> V_6 -> V_7 ) {
case V_8 :
return F_2 ( V_2 -> V_6 -> V_9 + 2 ) ;
case V_10 :
return F_2 ( V_2 -> V_6 -> V_9 + 4 ) ;
}
}
V_4 = V_3 << 2 ;
if ( V_3 == V_11 )
return F_3 ( V_2 -> V_12 + V_4 ) ;
else
return F_4 ( V_2 -> V_12 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_13 )
{
unsigned long V_4 ;
if ( V_3 == V_5 ) {
switch ( V_2 -> V_6 -> V_7 ) {
case V_8 :
return F_6 ( V_13 , V_2 -> V_6 -> V_9 + 2 ) ;
case V_10 :
return F_6 ( V_13 , V_2 -> V_6 -> V_9 + 4 ) ;
}
}
V_4 = V_3 << 2 ;
if ( V_3 == V_11 )
F_7 ( V_13 , V_2 -> V_12 + V_4 ) ;
else
F_8 ( V_13 , V_2 -> V_12 + V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_14 )
{
unsigned long V_15 , V_13 ;
F_10 ( & V_2 -> V_6 -> V_16 , V_15 ) ;
V_13 = F_1 ( V_2 , V_5 ) ;
if ( V_14 )
V_13 |= 1 << V_2 -> V_17 ;
else
V_13 &= ~ ( 1 << V_2 -> V_17 ) ;
F_5 ( V_2 , V_5 , V_13 ) ;
F_11 ( & V_2 -> V_6 -> V_16 , V_15 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_18 ;
V_18 = F_13 ( V_2 -> V_6 -> V_19 ) ;
if ( V_18 ) {
F_14 ( & V_2 -> V_6 -> V_20 -> V_21 , L_1 ,
V_2 -> V_17 ) ;
return V_18 ;
}
F_9 ( V_2 , 0 ) ;
F_5 ( V_2 , V_22 , 0xffffffff ) ;
F_5 ( V_2 , V_23 , 0xffffffff ) ;
V_2 -> V_24 = F_15 ( V_2 -> V_6 -> V_19 ) / 4 ;
F_5 ( V_2 , V_11 , V_25 ) ;
F_9 ( V_2 , 1 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 ++ > 0 )
return 0 ;
F_17 ( & V_2 -> V_6 -> V_20 -> V_21 ) ;
F_18 ( & V_2 -> V_6 -> V_20 -> V_21 , true ) ;
return F_12 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0 ) ;
F_5 ( V_2 , V_11 , V_25 ) ;
F_20 ( V_2 -> V_6 -> V_19 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( F_22 ( V_2 -> V_26 == 0 ) )
return;
if ( -- V_2 -> V_26 > 0 )
return;
F_19 ( V_2 ) ;
F_18 ( & V_2 -> V_6 -> V_20 -> V_21 , false ) ;
F_23 ( & V_2 -> V_6 -> V_20 -> V_21 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned long V_27 ,
int V_28 )
{
F_9 ( V_2 , 0 ) ;
F_1 ( V_2 , V_11 ) ;
F_5 ( V_2 , V_11 , V_29 | V_25 ) ;
if ( V_28 )
F_5 ( V_2 , V_22 , V_27 ) ;
else
F_5 ( V_2 , V_22 , 0xffffffff ) ;
F_5 ( V_2 , V_23 , V_27 ) ;
F_9 ( V_2 , 1 ) ;
}
static T_1 F_25 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
if ( V_2 -> V_32 . V_33 == V_34 )
F_5 ( V_2 , V_11 , V_25 ) ;
else
F_5 ( V_2 , V_11 , V_29 | V_25 ) ;
V_2 -> V_32 . V_35 ( & V_2 -> V_32 ) ;
return V_36 ;
}
static struct V_1 * F_26 ( struct V_37 * V_38 )
{
return F_27 ( V_38 , struct V_1 , V_38 ) ;
}
static T_2 F_28 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
return F_1 ( V_2 , V_23 ) ^ 0xffffffff ;
}
static int F_29 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
int V_18 ;
if ( F_22 ( V_2 -> V_39 ) )
return 0 ;
V_18 = F_16 ( V_2 ) ;
if ( ! V_18 ) {
F_30 ( V_38 , V_2 -> V_24 ) ;
V_2 -> V_39 = true ;
}
return V_18 ;
}
static void F_31 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
if ( F_22 ( ! V_2 -> V_39 ) )
return;
F_21 ( V_2 ) ;
V_2 -> V_39 = false ;
}
static void F_32 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
if ( ! V_2 -> V_39 )
return;
if ( -- V_2 -> V_26 == 0 ) {
F_19 ( V_2 ) ;
F_33 ( & V_2 -> V_6 -> V_20 -> V_21 ) ;
}
}
static void F_34 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
if ( ! V_2 -> V_39 )
return;
if ( V_2 -> V_26 ++ == 0 ) {
F_35 ( & V_2 -> V_6 -> V_20 -> V_21 ) ;
F_12 ( V_2 ) ;
}
}
static int F_36 ( struct V_1 * V_2 ,
const char * V_40 )
{
struct V_37 * V_38 = & V_2 -> V_38 ;
V_38 -> V_40 = V_40 ;
V_38 -> V_41 = 200 ;
V_38 -> V_42 = F_28 ;
V_38 -> V_43 = F_29 ;
V_38 -> V_44 = F_31 ;
V_38 -> V_45 = F_32 ;
V_38 -> V_46 = F_34 ;
V_38 -> V_47 = F_37 ( 32 ) ;
V_38 -> V_15 = V_48 ;
F_38 ( & V_2 -> V_6 -> V_20 -> V_21 , L_2 ,
V_2 -> V_17 ) ;
F_39 ( V_38 , 1 ) ;
return 0 ;
}
static struct V_1 * F_40 ( struct V_49 * V_32 )
{
return F_27 ( V_32 , struct V_1 , V_32 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_28 )
{
struct V_49 * V_32 = & V_2 -> V_32 ;
F_16 ( V_2 ) ;
F_42 ( V_32 , V_2 -> V_24 ) ;
if ( V_28 ) {
V_2 -> V_28 = ( V_2 -> V_24 + V_50 / 2 ) / V_50 ;
F_24 ( V_2 , V_2 -> V_28 , 1 ) ;
}
}
static void F_43 ( enum V_51 V_33 ,
struct V_49 * V_32 )
{
struct V_1 * V_2 = F_40 ( V_32 ) ;
int V_52 = 0 ;
switch ( V_32 -> V_33 ) {
case V_53 :
case V_34 :
F_21 ( V_2 ) ;
V_52 = 1 ;
break;
default:
break;
}
switch ( V_33 ) {
case V_53 :
F_38 ( & V_2 -> V_6 -> V_20 -> V_21 ,
L_3 , V_2 -> V_17 ) ;
F_41 ( V_2 , 1 ) ;
break;
case V_34 :
F_38 ( & V_2 -> V_6 -> V_20 -> V_21 ,
L_4 , V_2 -> V_17 ) ;
F_41 ( V_2 , 0 ) ;
break;
case V_54 :
if ( ! V_52 )
F_21 ( V_2 ) ;
break;
case V_55 :
default:
break;
}
}
static int F_44 ( unsigned long V_27 ,
struct V_49 * V_32 )
{
struct V_1 * V_2 = F_40 ( V_32 ) ;
F_45 ( V_32 -> V_33 != V_34 ) ;
F_24 ( V_2 , V_27 , 0 ) ;
return 0 ;
}
static void F_46 ( struct V_49 * V_32 )
{
F_33 ( & F_40 ( V_32 ) -> V_6 -> V_20 -> V_21 ) ;
}
static void F_47 ( struct V_49 * V_32 )
{
F_35 ( & F_40 ( V_32 ) -> V_6 -> V_20 -> V_21 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
const char * V_40 )
{
struct V_49 * V_32 = & V_2 -> V_32 ;
int V_18 ;
V_32 -> V_40 = V_40 ;
V_32 -> V_56 = V_57 ;
V_32 -> V_56 |= V_58 ;
V_32 -> V_41 = 200 ;
V_32 -> V_59 = F_49 ( 0 ) ;
V_32 -> V_60 = F_44 ;
V_32 -> V_61 = F_43 ;
V_32 -> V_45 = F_46 ;
V_32 -> V_46 = F_47 ;
F_38 ( & V_2 -> V_6 -> V_20 -> V_21 , L_5 ,
V_2 -> V_17 ) ;
F_50 ( V_32 , 1 , 0x300 , 0xffffffff ) ;
V_18 = F_51 ( V_2 -> V_30 , F_25 ,
V_62 | V_63 | V_64 ,
F_52 ( & V_2 -> V_6 -> V_20 -> V_21 ) , V_2 ) ;
if ( V_18 ) {
F_14 ( & V_2 -> V_6 -> V_20 -> V_21 , L_6 ,
V_2 -> V_17 , V_2 -> V_30 ) ;
return;
}
}
static int F_53 ( struct V_1 * V_2 , const char * V_40 ,
bool V_65 , bool V_37 )
{
if ( V_65 ) {
V_2 -> V_6 -> V_66 = true ;
F_48 ( V_2 , V_40 ) ;
} else if ( V_37 ) {
V_2 -> V_6 -> V_67 = true ;
F_36 ( V_2 , V_40 ) ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , unsigned int V_17 ,
bool V_65 , bool V_37 ,
struct V_68 * V_6 )
{
if ( ! V_65 && ! V_37 )
return 0 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_17 = V_17 ;
if ( V_6 -> V_7 == V_8 )
V_2 -> V_12 = V_6 -> V_9 + 4 + V_2 -> V_17 * 12 ;
else
V_2 -> V_12 = V_6 -> V_9 + 8 + V_2 -> V_17 * 12 ;
V_2 -> V_30 = F_55 ( V_6 -> V_20 , V_17 ) ;
if ( V_2 -> V_30 < 0 ) {
F_14 ( & V_6 -> V_20 -> V_21 , L_7 ,
V_2 -> V_17 ) ;
return V_2 -> V_30 ;
}
V_2 -> V_39 = false ;
V_2 -> V_26 = 0 ;
return F_53 ( V_2 , F_52 ( & V_6 -> V_20 -> V_21 ) ,
V_65 , V_37 ) ;
}
static int F_56 ( struct V_68 * V_6 )
{
struct V_69 * V_70 ;
V_70 = F_57 ( V_6 -> V_20 , V_71 , 0 ) ;
if ( ! V_70 ) {
F_14 ( & V_6 -> V_20 -> V_21 , L_8 ) ;
return - V_72 ;
}
V_6 -> V_9 = F_58 ( V_70 -> V_14 , F_59 ( V_70 ) ) ;
if ( V_6 -> V_9 == NULL )
return - V_72 ;
return 0 ;
}
static int F_60 ( struct V_68 * V_6 )
{
struct V_73 * V_74 = V_6 -> V_20 -> V_21 . V_75 ;
V_6 -> V_7 = V_10 ;
V_6 -> V_76 = 3 ;
F_61 ( V_74 , L_9 , & V_6 -> V_76 ) ;
if ( V_6 -> V_76 != 2 && V_6 -> V_76 != 3 ) {
F_14 ( & V_6 -> V_20 -> V_21 , L_10 ,
V_6 -> V_76 ) ;
return - V_77 ;
}
return 0 ;
}
static int F_62 ( struct V_68 * V_6 , struct V_78 * V_20 )
{
unsigned int V_79 ;
int V_18 ;
V_6 -> V_20 = V_20 ;
F_63 ( & V_6 -> V_16 ) ;
if ( F_64 ( V_80 ) && V_20 -> V_21 . V_75 ) {
V_18 = F_60 ( V_6 ) ;
if ( V_18 < 0 )
return V_18 ;
} else if ( V_20 -> V_21 . V_81 ) {
const struct V_82 * V_83 = V_20 -> V_84 ;
struct V_85 * V_86 = V_20 -> V_21 . V_81 ;
V_6 -> V_7 = V_83 -> V_87 ;
V_6 -> V_76 = F_65 ( V_86 -> V_88 ) ;
} else {
F_14 ( & V_6 -> V_20 -> V_21 , L_11 ) ;
return - V_72 ;
}
V_6 -> V_19 = F_66 ( & V_6 -> V_20 -> V_21 , L_12 ) ;
if ( F_67 ( V_6 -> V_19 ) ) {
F_14 ( & V_6 -> V_20 -> V_21 , L_13 ) ;
return F_68 ( V_6 -> V_19 ) ;
}
V_18 = F_69 ( V_6 -> V_19 ) ;
if ( V_18 < 0 )
goto V_89;
V_18 = F_56 ( V_6 ) ;
if ( V_18 < 0 ) {
F_14 ( & V_6 -> V_20 -> V_21 , L_14 ) ;
goto V_90;
}
V_6 -> V_91 = F_70 ( sizeof( * V_6 -> V_91 ) * V_6 -> V_76 ,
V_92 ) ;
if ( V_6 -> V_91 == NULL ) {
V_18 = - V_93 ;
goto V_94;
}
for ( V_79 = 0 ; V_79 < V_6 -> V_76 ; ++ V_79 ) {
V_18 = F_54 ( & V_6 -> V_91 [ V_79 ] , V_79 ,
V_79 == 0 , V_79 == 1 , V_6 ) ;
if ( V_18 < 0 )
goto V_94;
}
F_71 ( V_20 , V_6 ) ;
return 0 ;
V_94:
F_72 ( V_6 -> V_91 ) ;
F_73 ( V_6 -> V_9 ) ;
V_90:
F_74 ( V_6 -> V_19 ) ;
V_89:
F_75 ( V_6 -> V_19 ) ;
return V_18 ;
}
static int F_76 ( struct V_78 * V_20 )
{
struct V_68 * V_6 = F_77 ( V_20 ) ;
int V_18 ;
if ( ! F_78 ( V_20 ) ) {
F_79 ( & V_20 -> V_21 ) ;
F_80 ( & V_20 -> V_21 ) ;
}
if ( V_6 ) {
F_38 ( & V_20 -> V_21 , L_15 ) ;
goto V_95;
}
V_6 = F_70 ( sizeof( * V_6 ) , V_92 ) ;
if ( V_6 == NULL )
return - V_93 ;
V_18 = F_62 ( V_6 , V_20 ) ;
if ( V_18 ) {
F_72 ( V_6 ) ;
F_81 ( & V_20 -> V_21 ) ;
return V_18 ;
}
if ( F_78 ( V_20 ) )
return 0 ;
V_95:
if ( V_6 -> V_66 || V_6 -> V_67 )
F_82 ( & V_20 -> V_21 ) ;
else
F_81 ( & V_20 -> V_21 ) ;
return 0 ;
}
static int F_83 ( struct V_78 * V_20 )
{
return - V_96 ;
}
static int T_3 F_84 ( void )
{
return F_85 ( & V_97 ) ;
}
static void T_4 F_86 ( void )
{
F_87 ( & V_97 ) ;
}
