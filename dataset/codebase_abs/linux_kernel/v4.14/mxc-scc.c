static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_9 ;
void T_2 * V_10 ;
if ( V_2 -> V_11 & V_12 )
V_10 = V_8 -> V_13 ;
else
V_10 = V_8 -> V_14 ;
F_3 ( V_8 -> V_15 , L_1 , V_10 ,
V_2 -> V_16 * 8 ) ;
V_9 = F_4 ( V_6 -> V_17 , V_2 -> V_16 ,
V_10 , V_2 -> V_18 , V_2 -> V_19 ) ;
if ( ! V_9 ) {
F_5 ( V_8 -> V_15 , L_2 , V_10 , V_9 ) ;
return - V_20 ;
}
#ifdef F_6
F_7 ( V_21 ,
L_3 F_8 ( __LINE__ ) L_4 ,
V_22 , 16 , 4 ,
V_8 -> V_13 , V_2 -> V_18 , 1 ) ;
F_7 ( V_21 ,
L_5 F_8 ( __LINE__ ) L_4 ,
V_22 , 16 , 4 ,
V_8 -> V_14 , V_2 -> V_18 , 1 ) ;
#endif
V_2 -> V_19 += V_9 ;
if ( V_2 -> V_19 < V_6 -> V_23 )
return - V_24 ;
return 0 ;
}
static int F_9 ( struct V_5 * V_4 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
int V_25 ;
V_25 = F_10 ( V_4 -> V_26 , V_4 -> V_23 ) ;
if ( V_25 < 0 ) {
F_5 ( V_8 -> V_15 , L_6 ) ;
return V_25 ;
}
V_2 -> V_27 = V_25 ;
V_25 = F_10 ( V_4 -> V_17 , V_4 -> V_23 ) ;
if ( V_25 < 0 ) {
F_5 ( V_8 -> V_15 , L_7 ) ;
return V_25 ;
}
V_2 -> V_16 = V_25 ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_28 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
V_8 -> V_4 = NULL ;
V_8 -> V_29 = V_8 -> V_30 ;
if ( V_2 -> V_11 & V_31 )
memcpy ( V_6 -> V_32 , V_8 -> V_33 + V_34 ,
V_8 -> V_35 ) ;
V_4 -> V_36 ( V_4 , V_28 ) ;
V_8 -> V_37 = false ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_5 * V_4 )
{
T_3 V_38 [ sizeof( V_39 ) + sizeof( V_40 ) ] ;
T_1 V_9 = F_13 ( T_1 , V_4 -> V_23 - V_2 -> V_19 ,
V_2 -> V_8 -> V_29 ) ;
unsigned int V_41 = 0 ;
struct V_7 * V_8 = V_2 -> V_8 ;
void T_2 * V_42 ;
if ( V_2 -> V_11 & V_12 )
V_42 = V_8 -> V_14 ;
else
V_42 = V_8 -> V_13 ;
if ( V_2 -> V_11 & V_31 && V_4 -> V_32 )
memcpy ( V_8 -> V_33 + V_34 , V_4 -> V_32 ,
V_8 -> V_35 ) ;
V_9 = F_14 ( V_4 -> V_26 , V_2 -> V_27 ,
V_42 , V_9 , V_2 -> V_19 ) ;
if ( ! V_9 ) {
F_5 ( V_8 -> V_15 , L_8 , V_42 , V_9 ) ;
return - V_20 ;
}
V_2 -> V_18 = V_9 ;
#ifdef F_6
F_3 ( V_8 -> V_15 , L_9 , V_9 , V_42 ) ;
F_7 ( V_21 ,
L_10 F_8 ( __LINE__ ) L_4 ,
V_22 , 16 , 4 ,
V_8 -> V_33 + V_34 , V_8 -> V_35 ,
1 ) ;
F_7 ( V_21 ,
L_3 F_8 ( __LINE__ ) L_4 ,
V_22 , 16 , 4 ,
V_8 -> V_13 , V_2 -> V_18 , 1 ) ;
F_7 ( V_21 ,
L_5 F_8 ( __LINE__ ) L_4 ,
V_22 , 16 , 4 ,
V_8 -> V_14 , V_2 -> V_18 , 1 ) ;
#endif
V_8 -> V_29 -= V_9 ;
V_41 = V_9 % V_8 -> V_35 ;
if ( V_41 ) {
memcpy ( V_38 , V_40 , V_41 ) ;
memcpy ( V_42 + V_9 , V_38 , V_41 ) ;
V_2 -> V_18 += V_41 ;
}
#ifdef F_6
F_7 ( V_21 ,
L_11 F_8 ( __LINE__ ) L_4 ,
V_22 , 16 , 4 ,
V_42 , V_2 -> V_18 , 1 ) ;
#endif
return 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
int V_43 ;
F_3 ( V_8 -> V_15 , L_12 ,
V_6 -> V_23 , V_6 -> V_26 , V_6 -> V_17 ) ;
F_16 ( 0 , V_8 -> V_33 + V_44 ) ;
V_43 = F_12 ( V_2 , V_6 ) ;
if ( V_43 ) {
F_11 ( V_4 , V_2 , V_43 ) ;
return;
}
F_3 ( V_8 -> V_15 , L_13 ,
( void * ) F_17 ( V_8 -> V_33 + V_45 ) ,
( void * ) F_17 ( V_8 -> V_33 + V_46 ) ) ;
F_16 ( V_47 ,
V_8 -> V_33 + V_48 ) ;
F_16 ( ( V_2 -> V_18 / V_2 -> V_8 -> V_35 ) - 1 ,
V_8 -> V_33 + V_49 ) ;
F_3 ( V_8 -> V_15 , L_14 ,
V_2 -> V_18 / V_2 -> V_8 -> V_35 ,
( V_2 -> V_11 & V_12 ) ? V_8 -> V_14 :
V_8 -> V_13 ) ;
F_16 ( V_2 -> V_11 , V_8 -> V_33 + V_50 ) ;
}
static T_4 F_18 ( int V_51 , void * V_52 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_7 * V_8 = V_52 ;
int V_53 ;
int V_54 ;
V_53 = F_17 ( V_8 -> V_33 + V_55 ) ;
F_16 ( V_47 , V_8 -> V_33 + V_48 ) ;
if ( V_53 & V_56 )
return V_57 ;
V_4 = V_8 -> V_4 ;
if ( V_4 ) {
V_2 = F_19 ( V_4 -> V_58 ) ;
V_54 = F_1 ( V_2 , V_4 ) ;
if ( V_54 != - V_24 )
F_11 ( V_4 , V_2 , V_54 ) ;
else
F_15 ( V_2 , V_4 ) ;
}
return V_59 ;
}
static int F_20 ( struct V_60 * V_58 )
{
struct V_1 * V_2 = F_19 ( V_58 ) ;
struct V_61 * V_62 = V_58 -> V_63 ;
struct V_64 * V_65 ;
V_65 = F_21 ( V_62 , struct V_64 , V_62 ) ;
V_2 -> V_8 = V_65 -> V_8 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_66 ;
if ( V_2 -> V_8 -> V_37 )
return;
F_23 ( & V_2 -> V_8 -> V_67 ) ;
V_66 = F_24 ( & V_2 -> V_8 -> V_68 ) ;
V_4 = F_25 ( & V_2 -> V_8 -> V_68 ) ;
V_2 -> V_8 -> V_4 = V_4 ;
V_2 -> V_8 -> V_37 = true ;
F_26 ( & V_2 -> V_8 -> V_67 ) ;
if ( ! V_4 )
return;
if ( V_66 )
V_66 -> V_36 ( V_66 , - V_24 ) ;
F_15 ( V_2 , V_4 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_54 ;
F_23 ( & V_2 -> V_8 -> V_67 ) ;
V_54 = F_28 ( & V_2 -> V_8 -> V_68 , V_4 ) ;
F_26 ( & V_2 -> V_8 -> V_67 ) ;
if ( V_54 != - V_24 )
return V_54 ;
F_22 ( V_2 ) ;
return - V_24 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_5 * V_4 )
{
int V_43 ;
V_43 = F_9 ( V_4 , V_2 ) ;
if ( V_43 )
return V_43 ;
return F_27 ( V_2 , & V_4 -> V_33 ) ;
}
static int F_30 ( struct V_5 * V_4 )
{
struct V_69 * V_70 = F_31 ( V_4 ) ;
struct V_1 * V_2 = F_32 ( V_70 ) ;
V_2 -> V_11 = V_71 ;
return F_29 ( V_2 , V_4 ) ;
}
static int F_33 ( struct V_5 * V_4 )
{
struct V_69 * V_70 = F_31 ( V_4 ) ;
struct V_1 * V_2 = F_32 ( V_70 ) ;
V_2 -> V_11 = V_71 ;
V_2 -> V_11 |= V_12 ;
return F_29 ( V_2 , V_4 ) ;
}
static int F_34 ( struct V_5 * V_4 )
{
struct V_69 * V_70 = F_31 ( V_4 ) ;
struct V_1 * V_2 = F_32 ( V_70 ) ;
V_2 -> V_11 = V_71 ;
V_2 -> V_11 |= V_31 ;
return F_29 ( V_2 , V_4 ) ;
}
static int F_35 ( struct V_5 * V_4 )
{
struct V_69 * V_70 = F_31 ( V_4 ) ;
struct V_1 * V_2 = F_32 ( V_70 ) ;
V_2 -> V_11 = V_71 ;
V_2 -> V_11 |= V_31 ;
V_2 -> V_11 |= V_12 ;
return F_29 ( V_2 , V_4 ) ;
}
static void F_36 ( struct V_7 * V_8 )
{
int V_19 ;
V_19 = V_72 / V_8 -> V_35 ;
F_16 ( V_19 , V_8 -> V_33 + V_45 ) ;
F_16 ( V_19 , V_8 -> V_33 + V_46 ) ;
V_8 -> V_13 = V_8 -> V_33 + V_73 +
V_72 ;
V_8 -> V_14 = V_8 -> V_33 + V_74 +
V_72 ;
V_8 -> V_29 = V_8 -> V_30 ;
}
static int F_37 ( struct V_7 * V_8 )
{
int V_75 ;
V_75 = F_17 ( V_8 -> V_33 + V_76 ) ;
V_8 -> V_35 = V_75 & V_77 ;
V_8 -> V_78 = V_75 & V_79 ;
V_8 -> V_30 = ( V_8 -> V_35 *
V_8 -> V_78 ) -
V_72 ;
return 0 ;
}
static enum V_80 F_38 ( struct V_7 * V_8 )
{
enum V_80 V_81 ;
int V_53 ;
V_53 = F_17 ( V_8 -> V_33 + V_82 ) &
V_83 ;
if ( V_53 & V_84 ) {
F_16 ( 0xaaaa , V_8 -> V_33 + V_85 ) ;
F_16 ( 0x5555 , V_8 -> V_33 + V_86 ) ;
F_16 ( 0x5555 , V_8 -> V_33 + V_87 ) ;
V_53 = F_17 ( V_8 -> V_33 + V_82 ) &
V_83 ;
}
switch ( V_53 ) {
case V_88 :
case V_89 :
V_81 = V_90 ;
break;
case V_91 :
V_81 = V_92 ;
break;
default:
V_81 = V_93 ;
break;
}
return V_81 ;
}
static int F_39 ( struct V_7 * V_8 )
{
int V_94 ;
int V_43 = 0 ;
for ( V_94 = 0 ; V_94 < F_40 ( V_95 ) ; V_94 ++ ) {
V_95 [ V_94 ] -> V_8 = V_8 ;
V_43 = F_41 ( & V_95 [ V_94 ] -> V_62 ) ;
if ( V_43 )
goto V_96;
}
return 0 ;
V_96:
while ( -- V_94 >= 0 )
F_42 ( & V_95 [ V_94 ] -> V_62 ) ;
return V_43 ;
}
static void F_43 ( void )
{
unsigned int V_94 ;
for ( V_94 = 0 ; V_94 < F_40 ( V_95 ) ; V_94 ++ )
F_42 ( & V_95 [ V_94 ] -> V_62 ) ;
}
static int F_44 ( struct V_97 * V_98 )
{
struct V_99 * V_15 = & V_98 -> V_15 ;
struct V_100 * V_101 ;
struct V_7 * V_8 ;
enum V_80 V_81 ;
int V_51 ;
int V_54 ;
int V_94 ;
V_8 = F_45 ( V_15 , sizeof( * V_8 ) , V_102 ) ;
if ( ! V_8 )
return - V_103 ;
V_101 = F_46 ( V_98 , V_104 , 0 ) ;
V_8 -> V_33 = F_47 ( V_15 , V_101 ) ;
if ( F_48 ( V_8 -> V_33 ) )
return F_49 ( V_8 -> V_33 ) ;
V_8 -> V_105 = F_50 ( & V_98 -> V_15 , L_15 ) ;
if ( F_48 ( V_8 -> V_105 ) ) {
F_5 ( V_15 , L_16 ) ;
return F_49 ( V_8 -> V_105 ) ;
}
V_54 = F_51 ( V_8 -> V_105 ) ;
if ( V_54 )
return V_54 ;
F_16 ( 0x0 , V_8 -> V_33 + V_44 ) ;
F_16 ( V_47 |
V_106 ,
V_8 -> V_33 + V_48 ) ;
F_16 ( V_107 |
V_108 ,
V_8 -> V_33 + V_109 ) ;
V_8 -> V_15 = V_15 ;
F_52 ( V_98 , V_8 ) ;
V_54 = F_37 ( V_8 ) ;
if ( V_54 )
goto V_96;
V_81 = F_38 ( V_8 ) ;
if ( V_81 != V_90 ) {
F_5 ( V_15 , L_17 , V_81 ) ;
V_54 = - V_20 ;
goto V_96;
}
F_36 ( V_8 ) ;
F_53 ( & V_8 -> V_67 ) ;
F_54 ( & V_8 -> V_68 , 50 ) ;
for ( V_94 = 0 ; V_94 < 2 ; V_94 ++ ) {
V_51 = F_55 ( V_98 , V_94 ) ;
if ( V_51 < 0 ) {
F_5 ( V_15 , L_18 , V_51 ) ;
V_54 = V_51 ;
goto V_96;
}
V_54 = F_56 ( V_15 , V_51 , NULL , F_18 ,
V_110 , F_57 ( V_15 ) , V_8 ) ;
if ( V_54 )
goto V_96;
}
V_54 = F_39 ( V_8 ) ;
if ( V_54 ) {
F_5 ( V_15 , L_19 ) ;
goto V_96;
}
F_58 ( V_15 , L_20 ) ;
return 0 ;
V_96:
F_59 ( V_8 -> V_105 ) ;
return V_54 ;
}
static int F_60 ( struct V_97 * V_98 )
{
struct V_7 * V_8 = F_61 ( V_98 ) ;
F_43 () ;
F_59 ( V_8 -> V_105 ) ;
return 0 ;
}
