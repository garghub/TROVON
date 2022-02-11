static bool F_1 ( struct V_1 * V_2 )
{
const char * V_3 ;
long V_4 ;
int V_5 ;
V_3 = F_2 ( V_2 -> V_6 , L_1 ) ;
if ( ! V_3 )
return false ;
V_5 = F_3 ( V_3 , 0 , & V_4 ) ;
if ( V_5 < 0 )
return false ;
return V_4 == 15 ;
}
static int F_4 ( struct V_1 * V_2 )
{
const unsigned long V_7 = V_8 + 10 * V_9 ;
while ( ! F_1 ( V_2 ) ) {
if ( F_5 ( V_7 ) ) {
F_6 ( V_2 -> V_10 , L_2 ) ;
return - V_11 ;
}
F_7 ( V_2 -> V_10 , L_3 ) ;
if ( F_8 ( 500 ) )
return - V_12 ;
F_9 ( V_2 -> V_6 ) ;
V_2 -> V_6 = F_10 ( V_2 -> V_10 ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_5 ;
V_2 -> V_13 = F_12 ( V_2 -> V_14 , L_4 , & V_5 ) ;
if ( ! V_5 )
return F_13 ( V_2 -> V_15 , V_2 -> V_13 ) ;
V_2 -> V_13 = ~ 0 ;
F_13 ( V_2 -> V_15 , 0 ) ;
if ( V_5 == - V_16 )
return 0 ;
F_14 ( V_2 -> V_10 , L_5 , V_5 ) ;
return V_5 ;
}
static int F_15 ( struct V_17 * V_15 , int V_18 )
{
#ifdef F_16
struct V_1 * V_2 = F_17 ( V_15 ) ;
int V_5 ;
if ( V_18 > V_2 -> V_13 ) {
F_7 ( V_2 -> V_10 , L_6 ,
V_2 -> V_13 ) ;
return - V_11 ;
}
V_5 = F_18 ( V_15 , V_18 ) ;
if ( V_5 ) {
F_19 ( & V_15 -> V_19 , L_7 , V_5 ) ;
return V_5 ;
}
F_20 ( & V_2 -> V_20 ) ;
V_5 = F_21 ( V_2 -> V_21 , V_18 ) ;
if ( V_5 ) {
F_19 ( & V_15 -> V_19 ,
L_8 ,
V_5 ) ;
goto V_22;
}
V_2 -> V_18 = V_18 ;
F_22 ( & V_15 -> V_19 , L_9 , V_2 -> V_18 ) ;
F_23 ( & V_2 -> V_20 ) ;
return V_18 ;
V_22:
F_23 ( & V_2 -> V_20 ) ;
F_24 ( V_15 ) ;
return V_5 ;
#endif
return 0 ;
}
static int F_25 ( struct V_17 * V_15 )
{
#ifdef F_16
struct V_1 * V_2 = F_17 ( V_15 ) ;
F_20 ( & V_2 -> V_20 ) ;
if ( F_26 ( V_15 ) ) {
F_19 ( & V_15 -> V_19 , L_10 ) ;
F_23 ( & V_2 -> V_20 ) ;
return - V_23 ;
}
F_27 ( V_2 -> V_21 ) ;
V_2 -> V_18 = 0 ;
F_23 ( & V_2 -> V_20 ) ;
F_24 ( V_15 ) ;
F_22 ( & V_15 -> V_19 , L_11 ) ;
#endif
return 0 ;
}
static int F_28 ( struct V_17 * V_15 , int V_18 )
{
if ( V_18 == 0 )
return F_25 ( V_15 ) ;
else
return F_15 ( V_15 , V_18 ) ;
}
static const struct V_24 *
F_29 ( struct V_17 * V_15 , struct V_1 * V_2 , const char * V_25 )
{
const struct V_24 * V_26 = NULL ;
int V_5 ;
V_5 = F_30 ( & V_26 , V_25 , & V_15 -> V_19 ) ;
F_7 ( V_2 -> V_10 , L_12 ,
V_25 , V_5 ? L_13 : L_14 ) ;
if ( V_5 )
return NULL ;
return V_26 ;
}
static const struct V_24 *
F_31 ( struct V_17 * V_15 , struct V_1 * V_2 )
{
struct V_27 * V_28 ;
const struct V_24 * V_26 ;
const char * V_29 ;
char V_30 [ 256 ] ;
const T_1 * V_31 ;
T_2 V_32 ;
int V_33 , V_34 , V_35 ;
F_7 ( V_2 -> V_10 , L_15 ) ;
V_32 = F_32 ( V_2 -> V_10 ) ;
F_33 ( V_2 -> V_10 , & V_31 ) ;
sprintf ( V_30 , L_16 ,
V_31 , V_32 >> 8 , V_32 & 0xff ) ;
V_26 = F_29 ( V_15 , V_2 , V_30 ) ;
if ( V_26 )
return V_26 ;
sprintf ( V_30 , L_17 , F_34 ( V_15 ) ) ;
V_26 = F_29 ( V_15 , V_2 , V_30 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_2 -> V_36 ) {
F_35 ( & V_15 -> V_19 , L_18 ) ;
return NULL ;
}
V_29 = F_2 ( V_2 -> V_6 , L_19 ) ;
if ( ! V_29 ) {
F_35 ( & V_15 -> V_19 , L_20 ) ;
return NULL ;
}
V_33 = F_36 ( V_30 ) ;
V_33 -= snprintf ( V_30 , V_33 , L_21 , V_29 ) ;
for ( V_34 = 0 ; V_33 > 0 && V_34 < V_2 -> V_36 -> V_37 ; V_34 += V_35 ) {
V_28 = & V_2 -> V_36 -> V_38 [ V_34 ] ;
V_35 = 1 ;
while ( V_34 + V_35 < V_2 -> V_36 -> V_37 &&
V_28 -> V_39 == V_28 [ V_35 ] . V_39 )
V_35 ++ ;
V_33 -= snprintf ( & V_30 [ F_36 ( V_30 ) - V_33 ] , V_33 ,
L_22 , V_35 , V_28 -> V_39 / 1000 ) ;
}
if ( V_33 <= 0 )
return NULL ;
V_33 -= snprintf ( & V_30 [ F_36 ( V_30 ) - V_33 ] , V_33 , L_23 ) ;
if ( V_33 <= 0 )
return NULL ;
return F_29 ( V_15 , V_2 , V_30 ) ;
}
static int
F_37 ( struct V_17 * V_15 , struct V_1 * V_2 , struct V_40 * V_41 )
{
const struct V_24 * V_26 ;
T_2 V_32 ;
int V_5 ;
V_32 = F_32 ( V_2 -> V_10 ) ;
if ( F_38 ( V_32 ) != 0 ) {
F_39 ( & V_15 -> V_19 , L_24 ) ;
return 0 ;
}
V_26 = F_31 ( V_15 , V_2 ) ;
if ( ! V_26 )
return 0 ;
F_39 ( & V_15 -> V_19 , L_25 ) ;
V_5 = F_40 ( V_41 ) ;
if ( V_5 < 0 ) {
F_35 ( & V_15 -> V_19 , L_26 ,
V_5 ) ;
goto V_42;
}
V_5 = F_41 ( V_41 , V_26 ) ;
if ( V_5 < 0 ) {
F_35 ( & V_15 -> V_19 , L_27 , V_5 ) ;
goto V_42;
}
F_39 ( & V_15 -> V_19 , L_28 ) ;
V_42:
F_42 ( V_26 ) ;
return V_5 < 0 ? V_5 : 1 ;
}
static int F_43 ( struct V_17 * V_15 , struct V_1 * V_2 )
{
struct V_40 * V_41 ;
int V_5 ;
V_5 = F_44 ( V_2 -> V_10 , V_43 , 30 ) ;
if ( V_5 )
return V_5 ;
V_41 = F_45 ( V_2 -> V_10 ) ;
if ( F_46 ( V_41 ) ) {
V_5 = F_47 ( V_41 ) ;
F_35 ( & V_15 -> V_19 , L_29 , V_5 ) ;
return V_5 ;
}
V_5 = F_48 ( V_41 ) ;
if ( V_5 < 0 )
goto V_44;
V_2 -> V_36 = F_49 ( V_2 -> V_10 , V_41 ) ;
V_2 -> V_45 = F_50 ( V_41 ) ;
if ( V_2 -> V_45 )
F_39 ( & V_15 -> V_19 , L_30 , V_2 -> V_45 -> V_46 ) ;
V_5 = F_37 ( V_15 , V_2 , V_41 ) ;
if ( V_5 < 0 ) {
F_9 ( V_2 -> V_45 ) ;
F_9 ( V_2 -> V_36 ) ;
F_35 ( & V_15 -> V_19 , L_31 ) ;
goto V_44;
}
V_2 -> V_47 = ! ! V_5 ;
V_5 = 0 ;
V_44:
F_51 ( V_41 ) ;
return V_5 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_40 * V_41 ;
int V_5 ;
V_41 = F_45 ( V_2 -> V_10 ) ;
if ( F_46 ( V_41 ) ) {
F_6 ( V_2 -> V_10 , L_32 ) ;
return;
}
V_5 = F_40 ( V_41 ) ;
if ( V_5 < 0 )
F_19 ( & V_2 -> V_15 -> V_19 , L_33 , V_5 ) ;
else
F_39 ( & V_2 -> V_15 -> V_19 , L_34 ) ;
F_51 ( V_41 ) ;
}
static int F_53 ( struct V_17 * V_15 ,
const struct V_48 * V_49 )
{
struct V_50 * V_50 ;
struct V_1 * V_2 ;
int V_5 ;
V_5 = F_54 ( V_15 ) ;
if ( V_5 < 0 )
return V_5 ;
F_55 ( V_15 ) ;
V_5 = F_56 ( & V_15 -> V_19 ,
F_57 ( V_51 ) ) ;
if ( V_5 )
goto V_52;
V_5 = F_58 ( V_15 , V_53 ) ;
if ( V_5 < 0 ) {
F_35 ( & V_15 -> V_19 , L_35 ) ;
goto V_52;
}
V_50 = F_59 ( & V_54 , sizeof( * V_2 ) ) ;
if ( ! V_50 ) {
V_5 = - V_55 ;
goto V_56;
}
V_2 = F_60 ( V_50 ) ;
F_61 ( & V_2 -> V_57 ) ;
F_61 ( & V_2 -> V_38 ) ;
F_62 ( & V_2 -> V_20 ) ;
F_63 ( V_15 , V_2 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_58 = F_64 ( L_36 , 0 , 2 , F_34 ( V_15 ) ) ;
if ( ! V_2 -> V_58 ) {
V_5 = - V_55 ;
goto V_59;
}
V_2 -> V_10 = F_65 ( V_15 ) ;
if ( F_66 ( V_2 -> V_10 ) ) {
V_5 = F_47 ( V_2 -> V_10 ) ;
if ( V_5 >= 0 )
V_5 = - V_55 ;
goto V_60;
}
V_2 -> V_6 = F_10 ( V_2 -> V_10 ) ;
F_39 ( & V_15 -> V_19 , L_37 ,
F_2 ( V_2 -> V_6 , L_38 ) ,
F_2 ( V_2 -> V_6 , L_19 ) ,
F_2 ( V_2 -> V_6 , L_39 ) ,
F_2 ( V_2 -> V_6 , L_40 ) ,
F_2 ( V_2 -> V_6 , L_41 ) ) ;
V_5 = F_4 ( V_2 ) ;
if ( V_5 )
goto V_61;
V_5 = F_67 ( V_50 , & V_15 -> V_19 ) ;
if ( V_5 )
goto V_61;
V_5 = F_43 ( V_15 , V_2 ) ;
if ( V_5 )
goto V_62;
V_2 -> V_63 = F_68 ( V_2 -> V_10 ) ;
V_2 -> V_14 = F_69 ( V_2 -> V_10 , V_2 -> V_63 ) ;
V_5 = F_11 ( V_2 ) ;
if ( V_5 )
goto V_64;
V_2 -> V_18 = F_70 ( V_15 ) ;
if ( V_2 -> V_18 > V_2 -> V_13 ) {
F_35 ( & V_15 -> V_19 ,
L_42 ,
V_2 -> V_18 , V_2 -> V_13 ) ;
goto V_64;
}
V_5 = F_71 ( V_2 ) ;
if ( V_5 )
goto V_65;
V_5 = F_72 ( V_2 ) ;
if ( V_5 ) {
F_35 ( & V_15 -> V_19 , L_43 ) ;
goto V_66;
}
return 0 ;
V_66:
F_73 ( V_2 ) ;
V_65:
F_13 ( V_2 -> V_15 , 0 ) ;
V_64:
F_9 ( V_2 -> V_14 ) ;
F_74 ( V_2 -> V_63 ) ;
if ( V_2 -> V_47 )
F_52 ( V_2 ) ;
F_9 ( V_2 -> V_36 ) ;
F_9 ( V_2 -> V_45 ) ;
V_62:
F_75 ( V_50 ) ;
V_61:
F_9 ( V_2 -> V_6 ) ;
F_76 ( V_2 -> V_10 ) ;
V_60:
F_77 ( V_2 -> V_58 ) ;
V_59:
F_63 ( V_15 , NULL ) ;
F_78 ( & V_2 -> V_20 ) ;
F_79 ( V_50 ) ;
V_56:
F_80 ( V_15 ) ;
V_52:
F_81 ( V_15 ) ;
return V_5 ;
}
static void F_82 ( struct V_17 * V_15 )
{
struct V_1 * V_2 = F_17 ( V_15 ) ;
struct V_50 * V_50 ;
F_83 ( V_2 ) ;
V_50 = F_84 ( V_2 ) ;
F_73 ( V_2 ) ;
F_25 ( V_15 ) ;
F_13 ( V_2 -> V_15 , 0 ) ;
F_75 ( V_50 ) ;
F_9 ( V_2 -> V_14 ) ;
F_74 ( V_2 -> V_63 ) ;
if ( V_2 -> V_47 )
F_52 ( V_2 ) ;
F_77 ( V_2 -> V_58 ) ;
F_63 ( V_15 , NULL ) ;
F_9 ( V_2 -> V_6 ) ;
F_76 ( V_2 -> V_10 ) ;
F_9 ( V_2 -> V_36 ) ;
F_9 ( V_2 -> V_45 ) ;
F_78 ( & V_2 -> V_20 ) ;
F_79 ( V_50 ) ;
F_80 ( V_15 ) ;
F_81 ( V_15 ) ;
}
static int T_3 F_85 ( void )
{
int V_5 ;
F_86 ( L_44 ,
V_53 ) ;
F_87 () ;
V_5 = F_88 ( & V_67 ) ;
if ( V_5 < 0 )
goto V_68;
V_5 = F_88 ( & V_69 ) ;
if ( V_5 )
goto V_70;
return V_5 ;
V_70:
F_89 ( & V_67 ) ;
V_68:
F_90 () ;
return V_5 ;
}
static void T_4 F_91 ( void )
{
F_89 ( & V_69 ) ;
F_89 ( & V_67 ) ;
F_90 () ;
}
