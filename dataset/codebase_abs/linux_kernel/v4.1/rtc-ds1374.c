static int F_1 ( struct V_1 * V_2 , T_1 * time ,
int V_3 , int V_4 )
{
T_2 V_5 [ 4 ] ;
int V_6 ;
int V_7 ;
if ( V_4 > 4 ) {
F_2 ( 1 ) ;
return - V_8 ;
}
V_6 = F_3 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 < V_4 )
return - V_9 ;
for ( V_7 = V_4 - 1 , * time = 0 ; V_7 >= 0 ; V_7 -- )
* time = ( * time << 8 ) | V_5 [ V_7 ] ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 time ,
int V_3 , int V_4 )
{
T_2 V_5 [ 4 ] ;
int V_7 ;
if ( V_4 > 4 ) {
F_2 ( 1 ) ;
return - V_8 ;
}
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ ) {
V_5 [ V_7 ] = time & 0xff ;
time >>= 8 ;
}
return F_5 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
int V_10 , V_11 ;
V_11 = F_7 ( V_2 , V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_11 & V_13 )
F_8 ( & V_2 -> V_14 ,
L_1 ) ;
V_11 &= ~ ( V_13 | V_15 ) ;
V_6 = F_9 ( V_2 , V_12 , V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
V_10 = F_7 ( V_2 , V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ~ ( V_17 | V_18 ) ;
return F_9 ( V_2 , V_16 , V_10 ) ;
}
static int F_10 ( struct V_19 * V_14 , struct V_20 * time )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
T_1 V_21 ;
int V_6 ;
V_6 = F_1 ( V_2 , & V_21 , V_22 , 4 ) ;
if ( ! V_6 )
F_12 ( V_21 , time ) ;
return V_6 ;
}
static int F_13 ( struct V_19 * V_14 , struct V_20 * time )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
unsigned long V_21 ;
F_14 ( time , & V_21 ) ;
return F_4 ( V_2 , V_21 , V_22 , 4 ) ;
}
static int F_15 ( struct V_19 * V_14 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
struct V_25 * V_25 = F_16 ( V_2 ) ;
T_1 V_26 , V_27 ;
int V_28 , V_29 ;
int V_6 = 0 ;
if ( V_2 -> V_30 <= 0 )
return - V_8 ;
F_17 ( & V_25 -> V_31 ) ;
V_28 = V_6 = F_7 ( V_2 , V_16 ) ;
if ( V_6 < 0 )
goto V_32;
V_29 = V_6 = F_7 ( V_2 , V_12 ) ;
if ( V_6 < 0 )
goto V_32;
V_6 = F_1 ( V_2 , & V_26 , V_22 , 4 ) ;
if ( V_6 )
goto V_32;
V_6 = F_1 ( V_2 , & V_27 , V_33 , 3 ) ;
if ( V_6 )
goto V_32;
F_12 ( V_26 + V_27 , & V_24 -> time ) ;
V_24 -> V_34 = ! ! ( V_28 & V_17 ) ;
V_24 -> V_35 = ! ! ( V_29 & V_15 ) ;
V_32:
F_18 ( & V_25 -> V_31 ) ;
return V_6 ;
}
static int F_19 ( struct V_19 * V_14 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
struct V_25 * V_25 = F_16 ( V_2 ) ;
struct V_20 V_26 ;
unsigned long V_36 , V_21 ;
int V_28 ;
int V_6 = 0 ;
if ( V_2 -> V_30 <= 0 )
return - V_8 ;
V_6 = F_10 ( V_14 , & V_26 ) ;
if ( V_6 < 0 )
return V_6 ;
F_14 ( & V_24 -> time , & V_36 ) ;
F_14 ( & V_26 , & V_21 ) ;
if ( F_20 ( V_36 , V_21 ) )
V_36 = 1 ;
else
V_36 -= V_21 ;
F_17 ( & V_25 -> V_31 ) ;
V_6 = V_28 = F_7 ( V_2 , V_16 ) ;
if ( V_6 < 0 )
goto V_32;
V_28 &= ~ V_17 ;
V_6 = F_9 ( V_2 , V_16 , V_28 ) ;
if ( V_6 < 0 )
goto V_32;
V_6 = F_4 ( V_2 , V_36 , V_33 , 3 ) ;
if ( V_6 )
goto V_32;
if ( V_24 -> V_34 ) {
V_28 |= V_17 | V_18 ;
V_28 &= ~ V_37 ;
V_6 = F_9 ( V_2 , V_16 , V_28 ) ;
}
V_32:
F_18 ( & V_25 -> V_31 ) ;
return V_6 ;
}
static T_3 F_21 ( int V_30 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
struct V_25 * V_25 = F_16 ( V_2 ) ;
F_22 ( V_30 ) ;
F_23 ( & V_25 -> V_39 ) ;
return V_40 ;
}
static void F_24 ( struct V_41 * V_39 )
{
struct V_25 * V_25 = F_25 ( V_39 , struct V_25 , V_39 ) ;
struct V_1 * V_2 = V_25 -> V_2 ;
int V_11 , V_10 ;
F_17 ( & V_25 -> V_31 ) ;
V_11 = F_7 ( V_2 , V_12 ) ;
if ( V_11 < 0 )
goto V_42;
if ( V_11 & V_15 ) {
V_11 &= ~ V_15 ;
F_9 ( V_2 , V_12 , V_11 ) ;
V_10 = F_7 ( V_2 , V_16 ) ;
if ( V_10 < 0 )
goto V_32;
V_10 &= ~ ( V_17 | V_18 ) ;
F_9 ( V_2 , V_16 , V_10 ) ;
F_26 ( V_25 -> V_43 , 1 , V_44 | V_45 ) ;
}
V_32:
if ( ! V_25 -> V_46 )
F_27 ( V_2 -> V_30 ) ;
V_42:
F_18 ( & V_25 -> V_31 ) ;
}
static int F_28 ( struct V_19 * V_14 , unsigned int V_34 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
struct V_25 * V_25 = F_16 ( V_2 ) ;
int V_6 ;
F_17 ( & V_25 -> V_31 ) ;
V_6 = F_7 ( V_2 , V_16 ) ;
if ( V_6 < 0 )
goto V_32;
if ( V_34 ) {
V_6 |= V_17 | V_18 ;
V_6 &= ~ V_37 ;
} else {
V_6 &= ~ V_17 ;
}
V_6 = F_9 ( V_2 , V_16 , V_6 ) ;
V_32:
F_18 ( & V_25 -> V_31 ) ;
return V_6 ;
}
static int F_29 ( unsigned int V_47 )
{
int V_6 = - V_48 ;
int V_28 ;
V_6 = V_28 = F_7 ( V_49 , V_16 ) ;
if ( V_6 < 0 )
goto V_32;
V_28 &= ~ V_17 ;
V_6 = F_9 ( V_49 , V_16 , V_28 ) ;
if ( V_6 < 0 )
goto V_32;
V_6 = F_4 ( V_49 , V_47 , V_33 , 3 ) ;
if ( V_6 ) {
F_30 ( L_2 ) ;
goto V_32;
}
V_28 |= V_17 | V_37 ;
V_28 &= ~ V_18 ;
V_6 = F_9 ( V_49 , V_16 , V_28 ) ;
if ( V_6 < 0 )
goto V_32;
return 0 ;
V_32:
return V_6 ;
}
static void F_31 ( void )
{
T_1 V_50 ;
int V_6 = 0 ;
V_6 = F_1 ( V_49 , & V_50 , V_33 , 3 ) ;
if ( V_6 )
F_30 ( L_3 , V_6 ) ;
}
static void F_32 ( void )
{
int V_6 = - V_48 ;
int V_28 ;
V_28 = F_7 ( V_49 , V_16 ) ;
V_28 &= ~ V_17 ;
V_6 = F_9 ( V_49 , V_16 , V_28 ) ;
}
static int F_33 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
struct V_25 * V_25 = F_16 ( V_49 ) ;
if ( F_34 ( V_51 -> V_53 ) == V_54 ) {
F_17 ( & V_25 -> V_31 ) ;
if ( F_35 ( 0 , & V_55 ) ) {
F_18 ( & V_25 -> V_31 ) ;
return - V_56 ;
}
V_55 = 1 ;
F_18 ( & V_25 -> V_31 ) ;
return F_36 ( V_51 , V_52 ) ;
}
return - V_57 ;
}
static int F_37 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
if ( F_34 ( V_51 -> V_53 ) == V_54 )
F_38 ( 0 , & V_55 ) ;
return 0 ;
}
static T_4 F_39 ( struct V_52 * V_52 , const char T_5 * V_58 ,
T_6 V_59 , T_7 * V_60 )
{
if ( V_59 ) {
F_31 () ;
return 1 ;
}
return 0 ;
}
static T_4 F_40 ( struct V_52 * V_52 , char T_5 * V_58 ,
T_6 V_59 , T_7 * V_60 )
{
return 0 ;
}
static long F_41 ( struct V_52 * V_52 , unsigned int V_61 ,
unsigned long V_62 )
{
int V_63 , V_64 ;
switch ( V_61 ) {
case V_65 :
return F_42 ( (struct V_66 T_5 * ) V_62 ,
& V_67 , sizeof( V_67 ) ) ? - V_68 : 0 ;
case V_69 :
case V_70 :
return F_43 ( 0 , ( int T_5 * ) V_62 ) ;
case V_71 :
F_31 () ;
return 0 ;
case V_72 :
if ( F_44 ( V_63 , ( int T_5 * ) V_62 ) )
return - V_68 ;
if ( V_63 < 1 || V_63 > 16777216 )
return - V_8 ;
V_73 = V_63 ;
F_29 ( V_63 ) ;
F_31 () ;
case V_74 :
return F_43 ( V_73 , ( int T_5 * ) V_62 ) ;
case V_75 :
if ( F_45 ( & V_64 , ( int T_5 * ) V_62 , sizeof( int ) ) )
return - V_68 ;
if ( V_64 & V_76 ) {
F_30 ( L_4 ) ;
F_32 () ;
}
if ( V_64 & V_77 ) {
F_30 ( L_5 ) ;
F_29 ( V_73 ) ;
F_31 () ;
}
return - V_8 ;
}
return - V_78 ;
}
static long F_46 ( struct V_52 * V_52 , unsigned int V_61 ,
unsigned long V_62 )
{
int V_6 ;
struct V_25 * V_25 = F_16 ( V_49 ) ;
F_17 ( & V_25 -> V_31 ) ;
V_6 = F_41 ( V_52 , V_61 , V_62 ) ;
F_18 ( & V_25 -> V_31 ) ;
return V_6 ;
}
static int F_47 ( struct V_79 * V_80 ,
unsigned long V_81 , void * V_82 )
{
if ( V_81 == V_83 || V_81 == V_84 )
F_32 () ;
return V_85 ;
}
static int F_48 ( struct V_1 * V_2 ,
const struct V_86 * V_87 )
{
struct V_25 * V_25 ;
int V_6 ;
V_25 = F_49 ( & V_2 -> V_14 , sizeof( struct V_25 ) , V_88 ) ;
if ( ! V_25 )
return - V_89 ;
V_25 -> V_2 = V_2 ;
F_50 ( V_2 , V_25 ) ;
F_51 ( & V_25 -> V_39 , F_24 ) ;
F_52 ( & V_25 -> V_31 ) ;
V_6 = F_6 ( V_2 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_30 > 0 ) {
V_6 = F_53 ( & V_2 -> V_14 , V_2 -> V_30 , F_21 , 0 ,
L_6 , V_2 ) ;
if ( V_6 ) {
F_54 ( & V_2 -> V_14 , L_7 ) ;
return V_6 ;
}
F_55 ( & V_2 -> V_14 , 1 ) ;
}
V_25 -> V_43 = F_56 ( & V_2 -> V_14 , V_2 -> V_90 ,
& V_91 , V_92 ) ;
if ( F_57 ( V_25 -> V_43 ) ) {
F_54 ( & V_2 -> V_14 , L_8 ) ;
return F_58 ( V_25 -> V_43 ) ;
}
#ifdef F_59
V_49 = V_2 ;
V_6 = F_60 ( & V_93 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_61 ( & V_94 ) ;
if ( V_6 ) {
F_62 ( & V_93 ) ;
return V_6 ;
}
F_29 ( 131072 ) ;
#endif
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_25 * V_25 = F_16 ( V_2 ) ;
#ifdef F_59
int V_95 ;
V_95 = F_62 ( & V_93 ) ;
if ( ! V_95 )
V_93 . V_96 = NULL ;
F_64 ( & V_94 ) ;
#endif
if ( V_2 -> V_30 > 0 ) {
F_17 ( & V_25 -> V_31 ) ;
V_25 -> V_46 = 1 ;
F_18 ( & V_25 -> V_31 ) ;
F_65 ( & V_2 -> V_14 , V_2 -> V_30 , V_2 ) ;
F_66 ( & V_25 -> V_39 ) ;
}
return 0 ;
}
static int F_67 ( struct V_19 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
if ( V_2 -> V_30 >= 0 && F_68 ( & V_2 -> V_14 ) )
F_69 ( V_2 -> V_30 ) ;
return 0 ;
}
static int F_70 ( struct V_19 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
if ( V_2 -> V_30 >= 0 && F_68 ( & V_2 -> V_14 ) )
F_71 ( V_2 -> V_30 ) ;
return 0 ;
}
