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
F_5 ( V_2 , V_11 , V_24 ) ;
F_9 ( V_2 , 1 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 ++ > 0 )
return 0 ;
F_16 ( & V_2 -> V_6 -> V_20 -> V_21 ) ;
F_17 ( & V_2 -> V_6 -> V_20 -> V_21 , true ) ;
return F_12 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0 ) ;
F_5 ( V_2 , V_11 , V_24 ) ;
F_19 ( V_2 -> V_6 -> V_19 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( F_21 ( V_2 -> V_25 == 0 ) )
return;
if ( -- V_2 -> V_25 > 0 )
return;
F_18 ( V_2 ) ;
F_17 ( & V_2 -> V_6 -> V_20 -> V_21 , false ) ;
F_22 ( & V_2 -> V_6 -> V_20 -> V_21 ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned long V_26 ,
int V_27 )
{
F_9 ( V_2 , 0 ) ;
F_1 ( V_2 , V_11 ) ;
F_5 ( V_2 , V_11 , V_28 | V_24 ) ;
if ( V_27 )
F_5 ( V_2 , V_22 , V_26 ) ;
else
F_5 ( V_2 , V_22 , 0xffffffff ) ;
F_5 ( V_2 , V_23 , V_26 ) ;
F_9 ( V_2 , 1 ) ;
}
static T_1 F_24 ( int V_29 , void * V_30 )
{
struct V_1 * V_2 = V_30 ;
if ( F_25 ( & V_2 -> V_31 ) )
F_5 ( V_2 , V_11 , V_24 ) ;
else
F_5 ( V_2 , V_11 , V_28 | V_24 ) ;
V_2 -> V_31 . V_32 ( & V_2 -> V_31 ) ;
return V_33 ;
}
static struct V_1 * F_26 ( struct V_34 * V_35 )
{
return F_27 ( V_35 , struct V_1 , V_35 ) ;
}
static T_2 F_28 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_26 ( V_35 ) ;
return F_1 ( V_2 , V_23 ) ^ 0xffffffff ;
}
static int F_29 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_26 ( V_35 ) ;
int V_18 ;
if ( F_21 ( V_2 -> V_36 ) )
return 0 ;
V_18 = F_15 ( V_2 ) ;
if ( ! V_18 )
V_2 -> V_36 = true ;
return V_18 ;
}
static void F_30 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_26 ( V_35 ) ;
if ( F_21 ( ! V_2 -> V_36 ) )
return;
F_20 ( V_2 ) ;
V_2 -> V_36 = false ;
}
static void F_31 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_26 ( V_35 ) ;
if ( ! V_2 -> V_36 )
return;
if ( -- V_2 -> V_25 == 0 ) {
F_18 ( V_2 ) ;
F_32 ( & V_2 -> V_6 -> V_20 -> V_21 ) ;
}
}
static void F_33 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_26 ( V_35 ) ;
if ( ! V_2 -> V_36 )
return;
if ( V_2 -> V_25 ++ == 0 ) {
F_34 ( & V_2 -> V_6 -> V_20 -> V_21 ) ;
F_12 ( V_2 ) ;
}
}
static int F_35 ( struct V_1 * V_2 ,
const char * V_37 )
{
struct V_34 * V_35 = & V_2 -> V_35 ;
V_35 -> V_37 = V_37 ;
V_35 -> V_38 = 200 ;
V_35 -> V_39 = F_28 ;
V_35 -> V_40 = F_29 ;
V_35 -> V_41 = F_30 ;
V_35 -> V_42 = F_31 ;
V_35 -> V_43 = F_33 ;
V_35 -> V_44 = F_36 ( 32 ) ;
V_35 -> V_15 = V_45 ;
F_37 ( & V_2 -> V_6 -> V_20 -> V_21 , L_2 ,
V_2 -> V_17 ) ;
F_38 ( V_35 , V_2 -> V_6 -> V_46 ) ;
return 0 ;
}
static struct V_1 * F_39 ( struct V_47 * V_31 )
{
return F_27 ( V_31 , struct V_1 , V_31 ) ;
}
static void F_40 ( struct V_1 * V_2 , int V_27 )
{
F_15 ( V_2 ) ;
if ( V_27 ) {
V_2 -> V_27 = ( V_2 -> V_6 -> V_46 + V_48 / 2 ) / V_48 ;
F_23 ( V_2 , V_2 -> V_27 , 1 ) ;
}
}
static int F_41 ( struct V_47 * V_31 )
{
struct V_1 * V_2 = F_39 ( V_31 ) ;
if ( F_25 ( V_31 ) || F_42 ( V_31 ) )
F_20 ( V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_47 * V_31 ,
int V_27 )
{
struct V_1 * V_2 = F_39 ( V_31 ) ;
if ( F_25 ( V_31 ) || F_42 ( V_31 ) )
F_20 ( V_2 ) ;
F_37 ( & V_2 -> V_6 -> V_20 -> V_21 , L_3 ,
V_2 -> V_17 , V_27 ? L_4 : L_5 ) ;
F_40 ( V_2 , V_27 ) ;
return 0 ;
}
static int F_44 ( struct V_47 * V_31 )
{
return F_43 ( V_31 , 0 ) ;
}
static int F_45 ( struct V_47 * V_31 )
{
return F_43 ( V_31 , 1 ) ;
}
static int F_46 ( unsigned long V_26 ,
struct V_47 * V_31 )
{
struct V_1 * V_2 = F_39 ( V_31 ) ;
F_47 ( ! F_25 ( V_31 ) ) ;
F_23 ( V_2 , V_26 , 0 ) ;
return 0 ;
}
static void F_48 ( struct V_47 * V_31 )
{
F_32 ( & F_39 ( V_31 ) -> V_6 -> V_20 -> V_21 ) ;
}
static void F_49 ( struct V_47 * V_31 )
{
F_34 ( & F_39 ( V_31 ) -> V_6 -> V_20 -> V_21 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
const char * V_37 )
{
struct V_47 * V_31 = & V_2 -> V_31 ;
int V_18 ;
V_31 -> V_37 = V_37 ;
V_31 -> V_49 = V_50 ;
V_31 -> V_49 |= V_51 ;
V_31 -> V_38 = 200 ;
V_31 -> V_52 = V_53 ;
V_31 -> V_54 = F_46 ;
V_31 -> V_55 = F_41 ;
V_31 -> V_56 = F_45 ;
V_31 -> V_57 = F_44 ;
V_31 -> V_42 = F_48 ;
V_31 -> V_43 = F_49 ;
F_37 ( & V_2 -> V_6 -> V_20 -> V_21 , L_6 ,
V_2 -> V_17 ) ;
F_51 ( V_31 , V_2 -> V_6 -> V_46 , 0x300 , 0xffffffff ) ;
V_18 = F_52 ( V_2 -> V_29 , F_24 ,
V_58 | V_59 | V_60 ,
F_53 ( & V_2 -> V_6 -> V_20 -> V_21 ) , V_2 ) ;
if ( V_18 ) {
F_14 ( & V_2 -> V_6 -> V_20 -> V_21 , L_7 ,
V_2 -> V_17 , V_2 -> V_29 ) ;
return;
}
}
static int F_54 ( struct V_1 * V_2 , const char * V_37 ,
bool V_61 , bool V_34 )
{
if ( V_61 ) {
V_2 -> V_6 -> V_62 = true ;
F_50 ( V_2 , V_37 ) ;
} else if ( V_34 ) {
V_2 -> V_6 -> V_63 = true ;
F_35 ( V_2 , V_37 ) ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , unsigned int V_17 ,
bool V_61 , bool V_34 ,
struct V_64 * V_6 )
{
if ( ! V_61 && ! V_34 )
return 0 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_17 = V_17 ;
if ( V_6 -> V_7 == V_8 )
V_2 -> V_12 = V_6 -> V_9 + 4 + V_2 -> V_17 * 12 ;
else
V_2 -> V_12 = V_6 -> V_9 + 8 + V_2 -> V_17 * 12 ;
V_2 -> V_29 = F_56 ( V_6 -> V_20 , V_17 ) ;
if ( V_2 -> V_29 < 0 ) {
F_14 ( & V_6 -> V_20 -> V_21 , L_8 ,
V_2 -> V_17 ) ;
return V_2 -> V_29 ;
}
V_2 -> V_36 = false ;
V_2 -> V_25 = 0 ;
return F_54 ( V_2 , F_53 ( & V_6 -> V_20 -> V_21 ) ,
V_61 , V_34 ) ;
}
static int F_57 ( struct V_64 * V_6 )
{
struct V_65 * V_66 ;
V_66 = F_58 ( V_6 -> V_20 , V_67 , 0 ) ;
if ( ! V_66 ) {
F_14 ( & V_6 -> V_20 -> V_21 , L_9 ) ;
return - V_68 ;
}
V_6 -> V_9 = F_59 ( V_66 -> V_14 , F_60 ( V_66 ) ) ;
if ( V_6 -> V_9 == NULL )
return - V_68 ;
return 0 ;
}
static int F_61 ( struct V_64 * V_6 )
{
struct V_69 * V_70 = V_6 -> V_20 -> V_21 . V_71 ;
V_6 -> V_7 = V_10 ;
V_6 -> V_72 = 3 ;
F_62 ( V_70 , L_10 , & V_6 -> V_72 ) ;
if ( V_6 -> V_72 != 2 && V_6 -> V_72 != 3 ) {
F_14 ( & V_6 -> V_20 -> V_21 , L_11 ,
V_6 -> V_72 ) ;
return - V_73 ;
}
return 0 ;
}
static int F_63 ( struct V_64 * V_6 , struct V_74 * V_20 )
{
unsigned int V_75 ;
int V_18 ;
V_6 -> V_20 = V_20 ;
F_64 ( & V_6 -> V_16 ) ;
if ( F_65 ( V_76 ) && V_20 -> V_21 . V_71 ) {
V_18 = F_61 ( V_6 ) ;
if ( V_18 < 0 )
return V_18 ;
} else if ( V_20 -> V_21 . V_77 ) {
const struct V_78 * V_79 = V_20 -> V_80 ;
struct V_81 * V_82 = V_20 -> V_21 . V_77 ;
V_6 -> V_7 = V_79 -> V_83 ;
V_6 -> V_72 = F_66 ( V_82 -> V_84 ) ;
} else {
F_14 ( & V_6 -> V_20 -> V_21 , L_12 ) ;
return - V_68 ;
}
V_6 -> V_19 = F_67 ( & V_6 -> V_20 -> V_21 , L_13 ) ;
if ( F_68 ( V_6 -> V_19 ) ) {
F_14 ( & V_6 -> V_20 -> V_21 , L_14 ) ;
return F_69 ( V_6 -> V_19 ) ;
}
V_18 = F_70 ( V_6 -> V_19 ) ;
if ( V_18 < 0 )
goto V_85;
V_18 = F_13 ( V_6 -> V_19 ) ;
if ( V_18 < 0 )
goto V_86;
V_6 -> V_46 = F_71 ( V_6 -> V_19 ) / 4 ;
F_19 ( V_6 -> V_19 ) ;
V_18 = F_57 ( V_6 ) ;
if ( V_18 < 0 ) {
F_14 ( & V_6 -> V_20 -> V_21 , L_15 ) ;
goto V_86;
}
V_6 -> V_87 = F_72 ( sizeof( * V_6 -> V_87 ) * V_6 -> V_72 ,
V_88 ) ;
if ( V_6 -> V_87 == NULL ) {
V_18 = - V_89 ;
goto V_90;
}
for ( V_75 = 0 ; V_75 < V_6 -> V_72 ; ++ V_75 ) {
V_18 = F_55 ( & V_6 -> V_87 [ V_75 ] , V_75 ,
V_75 == 0 , V_75 == 1 , V_6 ) ;
if ( V_18 < 0 )
goto V_90;
}
F_73 ( V_20 , V_6 ) ;
return 0 ;
V_90:
F_74 ( V_6 -> V_87 ) ;
F_75 ( V_6 -> V_9 ) ;
V_86:
F_76 ( V_6 -> V_19 ) ;
V_85:
F_77 ( V_6 -> V_19 ) ;
return V_18 ;
}
static int F_78 ( struct V_74 * V_20 )
{
struct V_64 * V_6 = F_79 ( V_20 ) ;
int V_18 ;
if ( ! F_80 ( V_20 ) ) {
F_81 ( & V_20 -> V_21 ) ;
F_82 ( & V_20 -> V_21 ) ;
}
if ( V_6 ) {
F_37 ( & V_20 -> V_21 , L_16 ) ;
goto V_91;
}
V_6 = F_72 ( sizeof( * V_6 ) , V_88 ) ;
if ( V_6 == NULL )
return - V_89 ;
V_18 = F_63 ( V_6 , V_20 ) ;
if ( V_18 ) {
F_74 ( V_6 ) ;
F_83 ( & V_20 -> V_21 ) ;
return V_18 ;
}
if ( F_80 ( V_20 ) )
return 0 ;
V_91:
if ( V_6 -> V_62 || V_6 -> V_63 )
F_84 ( & V_20 -> V_21 ) ;
else
F_83 ( & V_20 -> V_21 ) ;
return 0 ;
}
static int F_85 ( struct V_74 * V_20 )
{
return - V_92 ;
}
static int T_3 F_86 ( void )
{
return F_87 ( & V_93 ) ;
}
static void T_4 F_88 ( void )
{
F_89 ( & V_93 ) ;
}
