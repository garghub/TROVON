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
T_1 V_11 ;
T_2 V_12 ;
bool V_13 ;
int V_14 ;
V_14 = F_5 ( V_15 , V_9 -> V_16 , V_9 -> V_17 ) ;
if ( V_14 ) {
F_6 ( & V_7 -> V_18 , L_1 ) ;
return V_14 ;
}
V_14 = F_7 ( V_9 , & V_11 , & V_12 , & V_13 ) ;
if ( V_14 ) {
F_6 ( & V_7 -> V_18 , L_2 ) ;
return V_14 ;
}
if ( V_13 ) {
V_2 -> V_19 = V_11 ;
V_14 = F_8 ( V_15 , V_2 -> V_20 , V_12 ) ;
if ( V_14 ) {
F_6 ( & V_7 -> V_18 , L_3 ) ;
return V_14 ;
}
}
return F_9 ( V_7 , V_9 , V_7 -> V_8 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_3 V_21 ;
V_21 = F_11 ( V_2 -> V_22 ) ;
V_21 |= V_23 ;
F_12 ( V_21 , V_2 -> V_22 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_3 V_21 ;
F_12 ( 0 , V_2 -> V_24 ) ;
V_21 = V_25 | V_26 ;
F_12 ( V_21 , V_2 -> V_24 ) ;
V_21 &= ~ V_27 ;
if ( V_2 -> V_5 )
V_21 |= V_28 << 1 ;
else
V_21 |= V_29 << 1 ;
F_12 ( V_21 , V_2 -> V_24 ) ;
V_21 |= V_30 ;
F_12 ( V_21 , V_2 -> V_24 ) ;
while ( F_11 ( V_2 -> V_24 ) & V_31 )
F_14 () ;
V_21 &= ~ V_30 ;
F_12 ( V_21 , V_2 -> V_24 ) ;
V_21 |= V_32 ;
F_12 ( V_21 , V_2 -> V_24 ) ;
while ( F_11 ( V_2 -> V_24 ) & V_33 )
F_14 () ;
V_21 &= ~ V_25 ;
V_21 &= ~ V_32 ;
F_12 ( V_21 , V_2 -> V_24 ) ;
F_15 ( 20 ) ;
}
static int F_16 ( struct V_7 * V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 -> V_10 ;
int V_14 ;
F_2 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_4 ) {
F_6 ( V_2 -> V_18 , L_4 ) ;
V_14 = - V_34 ;
goto V_35;
}
V_14 = F_17 ( V_2 -> V_36 , V_2 -> V_37 ) ;
if ( V_14 )
goto V_35;
V_14 = F_18 ( V_2 -> V_4 ) ;
if ( V_14 )
goto V_38;
F_10 ( V_2 ) ;
F_13 ( V_2 ) ;
V_14 = F_19 ( V_15 ) ;
if ( V_14 ) {
F_6 ( V_2 -> V_18 ,
L_5 ) ;
goto V_39;
}
V_14 = F_20 ( & V_2 -> V_40 ,
F_21 ( 5000 ) ) ;
if ( V_2 -> V_41 > 0 && V_14 == 0 ) {
F_6 ( V_2 -> V_18 , L_6 ) ;
F_22 ( V_15 ) ;
V_14 = - V_42 ;
goto V_39;
}
V_14 = 0 ;
V_39:
F_23 ( V_2 -> V_4 ) ;
V_38:
F_24 ( V_2 -> V_36 , V_2 -> V_37 ) ;
V_35:
F_3 ( & V_2 -> V_6 ) ;
return V_14 ;
}
static int F_25 ( struct V_7 * V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 -> V_10 ;
int V_14 ;
if ( V_2 -> V_43 ) {
F_26 ( V_2 -> V_43 ,
F_27 ( V_2 -> V_44 ) ,
F_27 ( V_2 -> V_44 ) ) ;
V_14 = F_20 ( & V_2 -> V_45 ,
F_21 ( 5000 ) ) ;
if ( V_14 == 0 )
F_6 ( V_2 -> V_18 , L_7 ) ;
F_26 ( V_2 -> V_43 ,
F_27 ( V_2 -> V_44 ) ,
0 ) ;
}
V_14 = F_22 ( V_15 ) ;
if ( V_14 )
F_6 ( V_2 -> V_18 , L_8 , V_14 ) ;
return V_14 ;
}
static void * F_28 ( struct V_7 * V_7 , T_4 V_46 , int V_47 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 -> V_10 ;
int V_48 ;
V_48 = V_46 - V_2 -> V_19 ;
if ( V_48 < 0 || V_48 + V_47 > V_2 -> V_49 )
return NULL ;
return V_2 -> V_50 + V_48 ;
}
static T_5 F_29 ( int V_51 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
F_30 ( V_2 -> V_7 , V_52 ) ;
return V_53 ;
}
static T_5 F_31 ( int V_51 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
T_2 V_47 ;
char * V_54 ;
V_54 = F_32 ( V_55 , V_56 , & V_47 ) ;
if ( ! F_33 ( V_54 ) && V_47 > 0 && V_54 [ 0 ] )
F_6 ( V_2 -> V_18 , L_9 , V_54 ) ;
F_30 ( V_2 -> V_7 , V_57 ) ;
if ( ! F_33 ( V_54 ) )
V_54 [ 0 ] = '\0' ;
return V_53 ;
}
static T_5 F_34 ( int V_51 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
F_35 ( & V_2 -> V_40 ) ;
return V_53 ;
}
static T_5 F_36 ( int V_51 , void * V_18 )
{
return V_53 ;
}
static T_5 F_37 ( int V_51 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
F_35 ( & V_2 -> V_45 ) ;
return V_53 ;
}
static int F_38 ( struct V_1 * V_2 ,
const struct V_58 * V_59 ,
int V_36 )
{
struct V_60 * V_61 ;
int V_14 ;
int V_62 ;
V_61 = F_39 ( V_2 -> V_18 ,
V_36 , sizeof( struct V_60 ) ,
V_63 ) ;
if ( ! V_61 )
return - V_64 ;
for ( V_62 = 0 ; V_62 < V_36 ; V_62 ++ )
V_61 [ V_62 ] . V_65 = V_59 [ V_62 ] . V_66 ;
V_14 = F_40 ( V_2 -> V_18 , V_36 , V_61 ) ;
if ( V_14 )
return V_14 ;
for ( V_62 = 0 ; V_62 < V_36 ; V_62 ++ ) {
if ( V_59 [ V_62 ] . V_67 )
F_41 ( V_61 [ V_62 ] . V_68 ,
V_59 [ V_62 ] . V_69 ,
V_59 [ V_62 ] . V_67 ) ;
if ( V_59 [ V_62 ] . V_70 )
F_42 ( V_61 [ V_62 ] . V_68 , V_59 [ V_62 ] . V_70 ) ;
}
V_2 -> V_37 = V_61 ;
V_2 -> V_36 = V_36 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_71 * V_72 ,
const char * V_66 ,
bool V_73 ,
T_6 V_74 )
{
int V_14 ;
V_14 = F_44 ( V_72 , V_66 ) ;
if ( V_14 < 0 && V_73 ) {
F_45 ( & V_72 -> V_18 , L_10 , V_66 ) ;
return 0 ;
} else if ( V_14 < 0 ) {
F_6 ( & V_72 -> V_18 , L_11 , V_66 ) ;
return V_14 ;
}
V_14 = F_46 ( & V_72 -> V_18 , V_14 ,
NULL , V_74 ,
V_75 | V_76 ,
L_12 , V_2 ) ;
if ( V_14 )
F_6 ( & V_72 -> V_18 , L_13 , V_66 ) ;
return V_14 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_77 * V_78 ;
struct V_79 V_80 ;
int V_14 ;
V_78 = F_48 ( V_2 -> V_18 -> V_81 , L_14 , 0 ) ;
if ( ! V_78 ) {
F_6 ( V_2 -> V_18 , L_15 ) ;
return - V_34 ;
}
V_14 = F_49 ( V_78 , 0 , & V_80 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_20 = V_2 -> V_19 = V_80 . V_82 ;
V_2 -> V_49 = F_50 ( & V_80 ) ;
V_2 -> V_50 = F_51 ( V_2 -> V_18 , V_2 -> V_20 , V_2 -> V_49 ) ;
if ( ! V_2 -> V_50 ) {
F_6 ( V_2 -> V_18 , L_16 ,
& V_80 . V_82 , V_2 -> V_49 ) ;
return - V_83 ;
}
return 0 ;
}
static int F_52 ( struct V_71 * V_72 )
{
const struct V_84 * V_16 ;
struct V_1 * V_2 ;
struct V_79 * V_85 ;
struct V_7 * V_7 ;
void T_7 * V_86 ;
int V_14 ;
V_16 = F_53 ( & V_72 -> V_18 ) ;
if ( ! F_54 () )
return - V_87 ;
if ( ! F_55 ( V_15 ) ) {
F_6 ( & V_72 -> V_18 , L_17 ) ;
return - V_88 ;
}
V_7 = F_56 ( & V_72 -> V_18 , V_72 -> V_66 , & V_89 ,
V_90 , sizeof( * V_2 ) ) ;
if ( ! V_7 ) {
F_6 ( & V_72 -> V_18 , L_18 ) ;
return - V_64 ;
}
V_7 -> V_91 = & V_92 ;
V_2 = (struct V_1 * ) V_7 -> V_10 ;
V_2 -> V_18 = & V_72 -> V_18 ;
V_2 -> V_7 = V_7 ;
F_57 ( V_72 , V_2 ) ;
F_58 ( & V_2 -> V_40 ) ;
F_58 ( & V_2 -> V_45 ) ;
F_59 ( & V_2 -> V_6 ) ;
V_85 = F_60 ( V_72 , V_93 , L_19 ) ;
V_86 = F_61 ( & V_72 -> V_18 , V_85 ) ;
if ( F_33 ( V_86 ) ) {
V_14 = F_62 ( V_86 ) ;
goto V_94;
} ;
V_14 = F_47 ( V_2 ) ;
if ( V_14 )
goto V_94;
V_2 -> V_24 = V_86 + V_16 -> V_95 ;
V_2 -> V_22 = V_86 + V_16 -> V_96 ;
V_14 = F_38 ( V_2 , V_16 -> V_37 , V_16 -> V_36 ) ;
if ( V_14 )
goto V_94;
V_14 = F_43 ( V_2 , V_72 , L_20 , false , F_29 ) ;
if ( V_14 < 0 )
goto V_94;
V_2 -> V_97 = V_14 ;
V_14 = F_43 ( V_2 , V_72 , L_21 , false , F_31 ) ;
if ( V_14 < 0 )
goto V_94;
V_2 -> V_98 = V_14 ;
V_14 = F_43 ( V_2 , V_72 , L_22 , true , F_34 ) ;
if ( V_14 < 0 )
goto V_94;
V_2 -> V_41 = V_14 ;
V_14 = F_43 ( V_2 , V_72 , L_23 , true , F_36 ) ;
if ( V_14 < 0 )
goto V_94;
V_2 -> V_99 = V_14 ;
V_14 = F_43 ( V_2 , V_72 , L_24 , true , F_37 ) ;
if ( V_14 < 0 )
goto V_94;
V_2 -> V_100 = V_14 ;
if ( V_2 -> V_100 ) {
V_2 -> V_43 = F_63 ( & V_72 -> V_18 , L_25 ,
& V_2 -> V_44 ) ;
if ( F_33 ( V_2 -> V_43 ) ) {
V_14 = F_62 ( V_2 -> V_43 ) ;
goto V_94;
}
}
V_14 = F_64 ( V_7 ) ;
if ( V_14 )
goto V_94;
return F_65 ( V_72 -> V_18 . V_81 , NULL , NULL , & V_72 -> V_18 ) ;
V_94:
F_66 ( V_7 ) ;
return V_14 ;
}
static int F_67 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_68 ( V_72 ) ;
F_69 ( & V_72 -> V_18 ) ;
F_70 ( V_2 -> V_43 ) ;
F_71 ( V_2 -> V_7 ) ;
F_66 ( V_2 -> V_7 ) ;
return 0 ;
}
