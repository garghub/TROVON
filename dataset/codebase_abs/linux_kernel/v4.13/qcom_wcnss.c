void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_5 )
{
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
F_3 ( & V_2 -> V_6 ) ;
}
static int F_4 ( struct V_7 * V_7 , const struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 -> V_10 ;
return F_5 ( V_2 -> V_11 , V_9 , V_7 -> V_8 , V_12 ,
V_2 -> V_13 , V_2 -> V_14 , V_2 -> V_15 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_16 ;
V_16 = F_7 ( V_2 -> V_17 ) ;
V_16 |= V_18 ;
F_8 ( V_16 , V_2 -> V_17 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_16 ;
F_8 ( 0 , V_2 -> V_19 ) ;
V_16 = V_20 | V_21 ;
F_8 ( V_16 , V_2 -> V_19 ) ;
V_16 &= ~ V_22 ;
if ( V_2 -> V_5 )
V_16 |= V_23 << 1 ;
else
V_16 |= V_24 << 1 ;
F_8 ( V_16 , V_2 -> V_19 ) ;
V_16 |= V_25 ;
F_8 ( V_16 , V_2 -> V_19 ) ;
while ( F_7 ( V_2 -> V_19 ) & V_26 )
F_10 () ;
V_16 &= ~ V_25 ;
F_8 ( V_16 , V_2 -> V_19 ) ;
V_16 |= V_27 ;
F_8 ( V_16 , V_2 -> V_19 ) ;
while ( F_7 ( V_2 -> V_19 ) & V_28 )
F_10 () ;
V_16 &= ~ V_20 ;
V_16 &= ~ V_27 ;
F_8 ( V_16 , V_2 -> V_19 ) ;
F_11 ( 20 ) ;
}
static int F_12 ( struct V_7 * V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 -> V_10 ;
int V_29 ;
F_2 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_4 ) {
F_13 ( V_2 -> V_11 , L_1 ) ;
V_29 = - V_30 ;
goto V_31;
}
V_29 = F_14 ( V_2 -> V_32 , V_2 -> V_33 ) ;
if ( V_29 )
goto V_31;
V_29 = F_15 ( V_2 -> V_4 ) ;
if ( V_29 )
goto V_34;
F_6 ( V_2 ) ;
F_9 ( V_2 ) ;
V_29 = F_16 ( V_12 ) ;
if ( V_29 ) {
F_13 ( V_2 -> V_11 ,
L_2 ) ;
goto V_35;
}
V_29 = F_17 ( & V_2 -> V_36 ,
F_18 ( 5000 ) ) ;
if ( V_2 -> V_37 > 0 && V_29 == 0 ) {
F_13 ( V_2 -> V_11 , L_3 ) ;
F_19 ( V_12 ) ;
V_29 = - V_38 ;
goto V_35;
}
V_29 = 0 ;
V_35:
F_20 ( V_2 -> V_4 ) ;
V_34:
F_21 ( V_2 -> V_32 , V_2 -> V_33 ) ;
V_31:
F_3 ( & V_2 -> V_6 ) ;
return V_29 ;
}
static int F_22 ( struct V_7 * V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 -> V_10 ;
int V_29 ;
if ( V_2 -> V_39 ) {
F_23 ( V_2 -> V_39 ,
F_24 ( V_2 -> V_40 ) ,
F_24 ( V_2 -> V_40 ) ) ;
V_29 = F_17 ( & V_2 -> V_41 ,
F_18 ( 5000 ) ) ;
if ( V_29 == 0 )
F_13 ( V_2 -> V_11 , L_4 ) ;
F_23 ( V_2 -> V_39 ,
F_24 ( V_2 -> V_40 ) ,
0 ) ;
}
V_29 = F_19 ( V_12 ) ;
if ( V_29 )
F_13 ( V_2 -> V_11 , L_5 , V_29 ) ;
return V_29 ;
}
static void * F_25 ( struct V_7 * V_7 , T_2 V_42 , int V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 -> V_10 ;
int V_44 ;
V_44 = V_42 - V_2 -> V_45 ;
if ( V_44 < 0 || V_44 + V_43 > V_2 -> V_15 )
return NULL ;
return V_2 -> V_13 + V_44 ;
}
static T_3 F_26 ( int V_46 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
F_27 ( V_2 -> V_7 , V_47 ) ;
return V_48 ;
}
static T_3 F_28 ( int V_46 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
T_4 V_43 ;
char * V_49 ;
V_49 = F_29 ( V_50 , V_51 , & V_43 ) ;
if ( ! F_30 ( V_49 ) && V_43 > 0 && V_49 [ 0 ] )
F_13 ( V_2 -> V_11 , L_6 , V_49 ) ;
F_27 ( V_2 -> V_7 , V_52 ) ;
if ( ! F_30 ( V_49 ) )
V_49 [ 0 ] = '\0' ;
return V_48 ;
}
static T_3 F_31 ( int V_46 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
F_32 ( & V_2 -> V_36 ) ;
return V_48 ;
}
static T_3 F_33 ( int V_46 , void * V_11 )
{
return V_48 ;
}
static T_3 F_34 ( int V_46 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
F_32 ( & V_2 -> V_41 ) ;
return V_48 ;
}
static int F_35 ( struct V_1 * V_2 ,
const struct V_53 * V_54 ,
int V_32 )
{
struct V_55 * V_56 ;
int V_29 ;
int V_57 ;
V_56 = F_36 ( V_2 -> V_11 ,
V_32 , sizeof( struct V_55 ) ,
V_58 ) ;
if ( ! V_56 )
return - V_59 ;
for ( V_57 = 0 ; V_57 < V_32 ; V_57 ++ )
V_56 [ V_57 ] . V_60 = V_54 [ V_57 ] . V_61 ;
V_29 = F_37 ( V_2 -> V_11 , V_32 , V_56 ) ;
if ( V_29 )
return V_29 ;
for ( V_57 = 0 ; V_57 < V_32 ; V_57 ++ ) {
if ( V_54 [ V_57 ] . V_62 )
F_38 ( V_56 [ V_57 ] . V_63 ,
V_54 [ V_57 ] . V_64 ,
V_54 [ V_57 ] . V_62 ) ;
if ( V_54 [ V_57 ] . V_65 )
F_39 ( V_56 [ V_57 ] . V_63 , V_54 [ V_57 ] . V_65 ) ;
}
V_2 -> V_33 = V_56 ;
V_2 -> V_32 = V_32 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
const char * V_61 ,
bool V_68 ,
T_5 V_69 )
{
int V_29 ;
V_29 = F_41 ( V_67 , V_61 ) ;
if ( V_29 < 0 && V_68 ) {
F_42 ( & V_67 -> V_11 , L_7 , V_61 ) ;
return 0 ;
} else if ( V_29 < 0 ) {
F_13 ( & V_67 -> V_11 , L_8 , V_61 ) ;
return V_29 ;
}
V_29 = F_43 ( & V_67 -> V_11 , V_29 ,
NULL , V_69 ,
V_70 | V_71 ,
L_9 , V_2 ) ;
if ( V_29 )
F_13 ( & V_67 -> V_11 , L_10 , V_61 ) ;
return V_29 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_72 * V_73 ;
struct V_74 V_75 ;
int V_29 ;
V_73 = F_45 ( V_2 -> V_11 -> V_76 , L_11 , 0 ) ;
if ( ! V_73 ) {
F_13 ( V_2 -> V_11 , L_12 ) ;
return - V_30 ;
}
V_29 = F_46 ( V_73 , 0 , & V_75 ) ;
if ( V_29 )
return V_29 ;
V_2 -> V_14 = V_2 -> V_45 = V_75 . V_77 ;
V_2 -> V_15 = F_47 ( & V_75 ) ;
V_2 -> V_13 = F_48 ( V_2 -> V_11 , V_2 -> V_14 , V_2 -> V_15 ) ;
if ( ! V_2 -> V_13 ) {
F_13 ( V_2 -> V_11 , L_13 ,
& V_75 . V_77 , V_2 -> V_15 ) ;
return - V_78 ;
}
return 0 ;
}
static int F_49 ( struct V_66 * V_67 )
{
const struct V_79 * V_80 ;
struct V_1 * V_2 ;
struct V_74 * V_81 ;
struct V_7 * V_7 ;
void T_6 * V_82 ;
int V_29 ;
V_80 = F_50 ( & V_67 -> V_11 ) ;
if ( ! F_51 () )
return - V_83 ;
if ( ! F_52 ( V_12 ) ) {
F_13 ( & V_67 -> V_11 , L_14 ) ;
return - V_84 ;
}
V_7 = F_53 ( & V_67 -> V_11 , V_67 -> V_61 , & V_85 ,
V_86 , sizeof( * V_2 ) ) ;
if ( ! V_7 ) {
F_13 ( & V_67 -> V_11 , L_15 ) ;
return - V_59 ;
}
V_7 -> V_87 = & V_88 ;
V_2 = (struct V_1 * ) V_7 -> V_10 ;
V_2 -> V_11 = & V_67 -> V_11 ;
V_2 -> V_7 = V_7 ;
F_54 ( V_67 , V_2 ) ;
F_55 ( & V_2 -> V_36 ) ;
F_55 ( & V_2 -> V_41 ) ;
F_56 ( & V_2 -> V_6 ) ;
V_81 = F_57 ( V_67 , V_89 , L_16 ) ;
V_82 = F_58 ( & V_67 -> V_11 , V_81 ) ;
if ( F_30 ( V_82 ) ) {
V_29 = F_59 ( V_82 ) ;
goto V_90;
} ;
V_29 = F_44 ( V_2 ) ;
if ( V_29 )
goto V_90;
V_2 -> V_19 = V_82 + V_80 -> V_91 ;
V_2 -> V_17 = V_82 + V_80 -> V_92 ;
V_29 = F_35 ( V_2 , V_80 -> V_33 , V_80 -> V_32 ) ;
if ( V_29 )
goto V_90;
V_29 = F_40 ( V_2 , V_67 , L_17 , false , F_26 ) ;
if ( V_29 < 0 )
goto V_90;
V_2 -> V_93 = V_29 ;
V_29 = F_40 ( V_2 , V_67 , L_18 , false , F_28 ) ;
if ( V_29 < 0 )
goto V_90;
V_2 -> V_94 = V_29 ;
V_29 = F_40 ( V_2 , V_67 , L_19 , true , F_31 ) ;
if ( V_29 < 0 )
goto V_90;
V_2 -> V_37 = V_29 ;
V_29 = F_40 ( V_2 , V_67 , L_20 , true , F_33 ) ;
if ( V_29 < 0 )
goto V_90;
V_2 -> V_95 = V_29 ;
V_29 = F_40 ( V_2 , V_67 , L_21 , true , F_34 ) ;
if ( V_29 < 0 )
goto V_90;
V_2 -> V_96 = V_29 ;
if ( V_2 -> V_96 ) {
V_2 -> V_39 = F_60 ( & V_67 -> V_11 , L_22 ,
& V_2 -> V_40 ) ;
if ( F_30 ( V_2 -> V_39 ) ) {
V_29 = F_59 ( V_2 -> V_39 ) ;
goto V_90;
}
}
F_61 ( V_7 , & V_2 -> V_97 ) ;
V_29 = F_62 ( V_7 ) ;
if ( V_29 )
goto V_90;
return F_63 ( V_67 -> V_11 . V_76 , NULL , NULL , & V_67 -> V_11 ) ;
V_90:
F_64 ( V_7 ) ;
return V_29 ;
}
static int F_65 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_66 ( V_67 ) ;
F_67 ( & V_67 -> V_11 ) ;
F_68 ( V_2 -> V_39 ) ;
F_69 ( V_2 -> V_7 ) ;
F_70 ( V_2 -> V_7 , & V_2 -> V_97 ) ;
F_64 ( V_2 -> V_7 ) ;
return 0 ;
}
static int T_7 F_71 ( void )
{
int V_29 ;
V_29 = F_72 ( & V_98 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_72 ( & V_99 ) ;
if ( V_29 )
F_73 ( & V_98 ) ;
return V_29 ;
}
static void T_8 F_74 ( void )
{
F_73 ( & V_99 ) ;
F_73 ( & V_98 ) ;
}
