static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_4 = F_2 ( V_2 -> V_5 , L_1 , & V_3 ) ;
if ( ! V_3 )
return F_3 ( V_2 -> V_6 , V_2 -> V_4 ) ;
V_2 -> V_4 = ~ 0 ;
F_3 ( V_2 -> V_6 , 0 ) ;
if ( V_3 == - V_7 )
return 0 ;
F_4 ( V_2 -> V_8 , L_2 , V_3 ) ;
return V_3 ;
}
static int F_5 ( struct V_9 * V_6 , int V_10 )
{
#ifdef F_6
struct V_1 * V_2 = F_7 ( V_6 ) ;
int V_3 ;
if ( V_10 > V_2 -> V_4 ) {
F_8 ( V_2 -> V_8 , L_3 ,
V_2 -> V_4 ) ;
return - V_11 ;
}
V_3 = F_9 ( V_6 , V_10 ) ;
if ( V_3 ) {
F_10 ( & V_6 -> V_12 , L_4 , V_3 ) ;
return V_3 ;
}
F_11 ( & V_2 -> V_13 ) ;
V_3 = F_12 ( V_2 -> V_14 , V_10 ) ;
if ( V_3 ) {
F_10 ( & V_6 -> V_12 ,
L_5 ,
V_3 ) ;
goto V_15;
}
V_2 -> V_10 = V_10 ;
F_13 ( & V_6 -> V_12 , L_6 , V_2 -> V_10 ) ;
F_14 ( & V_2 -> V_13 ) ;
return V_10 ;
V_15:
F_14 ( & V_2 -> V_13 ) ;
F_15 ( V_6 ) ;
return V_3 ;
#endif
return 0 ;
}
static int F_16 ( struct V_9 * V_6 )
{
#ifdef F_6
struct V_1 * V_2 = F_7 ( V_6 ) ;
F_11 ( & V_2 -> V_13 ) ;
if ( F_17 ( V_6 ) ) {
F_10 ( & V_6 -> V_12 , L_7 ) ;
F_14 ( & V_2 -> V_13 ) ;
return - V_16 ;
}
F_18 ( V_2 -> V_14 ) ;
V_2 -> V_10 = 0 ;
F_14 ( & V_2 -> V_13 ) ;
F_15 ( V_6 ) ;
F_13 ( & V_6 -> V_12 , L_8 ) ;
#endif
return 0 ;
}
static int F_19 ( struct V_9 * V_6 , int V_10 )
{
if ( V_10 == 0 )
return F_16 ( V_6 ) ;
else
return F_5 ( V_6 , V_10 ) ;
}
static const struct V_17 *
F_20 ( struct V_9 * V_6 , struct V_1 * V_2 )
{
const struct V_17 * V_18 = NULL ;
struct V_19 * V_20 ;
const char * V_21 ;
char V_22 [ 256 ] ;
int V_23 , V_3 = 0 ;
int V_24 , V_25 ;
if ( ! V_2 -> V_26 ) {
F_21 ( & V_6 -> V_12 , L_9 ) ;
return NULL ;
}
V_21 = F_22 ( V_2 -> V_27 , L_10 ) ;
if ( ! V_21 ) {
F_21 ( & V_6 -> V_12 , L_11 ) ;
return NULL ;
}
V_23 = F_23 ( V_22 ) ;
V_23 -= snprintf ( V_22 , V_23 , L_12 , V_21 ) ;
for ( V_24 = 0 ; V_23 > 0 && V_24 < V_2 -> V_26 -> V_28 ; V_24 += V_25 ) {
V_20 = & V_2 -> V_26 -> V_29 [ V_24 ] ;
V_25 = 1 ;
while ( V_24 + V_25 < V_2 -> V_26 -> V_28 &&
V_20 -> V_30 == V_20 [ V_25 ] . V_30 )
V_25 ++ ;
V_23 -= snprintf ( & V_22 [ F_23 ( V_22 ) - V_23 ] , V_23 ,
L_13 , V_25 , V_20 -> V_30 / 1000 ) ;
}
if ( V_23 <= 0 )
return NULL ;
V_23 -= snprintf ( & V_22 [ F_23 ( V_22 ) - V_23 ] , V_23 , L_14 ) ;
if ( V_23 <= 0 )
return NULL ;
V_3 = F_24 ( & V_18 , V_22 , & V_6 -> V_12 ) ;
if ( V_3 )
return NULL ;
F_25 ( & V_6 -> V_12 , L_15 , V_22 ) ;
return V_18 ;
}
static int
F_26 ( struct V_9 * V_6 , struct V_1 * V_2 , struct V_31 * V_32 )
{
const struct V_17 * V_18 ;
T_1 V_33 ;
int V_3 ;
V_33 = F_27 ( V_2 -> V_8 ) ;
if ( F_28 ( V_33 ) != 0 ) {
F_25 ( & V_6 -> V_12 , L_16 ) ;
return 0 ;
}
V_18 = F_20 ( V_6 , V_2 ) ;
if ( ! V_18 )
return 0 ;
F_25 ( & V_6 -> V_12 , L_17 ) ;
V_3 = F_29 ( V_32 ) ;
if ( V_3 < 0 ) {
F_21 ( & V_6 -> V_12 , L_18 ,
V_3 ) ;
goto V_34;
}
V_3 = F_30 ( V_32 , V_18 ) ;
if ( V_3 < 0 ) {
F_21 ( & V_6 -> V_12 , L_19 , V_3 ) ;
goto V_34;
}
F_25 ( & V_6 -> V_12 , L_20 ) ;
V_34:
F_31 ( V_18 ) ;
return V_3 < 0 ? V_3 : 1 ;
}
static int F_32 ( struct V_9 * V_6 , struct V_1 * V_2 )
{
struct V_31 * V_32 ;
int V_3 ;
V_32 = F_33 ( V_2 -> V_8 ) ;
if ( F_34 ( V_32 ) ) {
V_3 = F_35 ( V_32 ) ;
F_21 ( & V_6 -> V_12 , L_21 , V_3 ) ;
return V_3 ;
}
V_3 = F_36 ( V_32 ) ;
if ( V_3 < 0 )
goto V_35;
V_2 -> V_26 = F_37 ( V_2 -> V_8 , V_32 ) ;
V_2 -> V_36 = F_38 ( V_32 ) ;
if ( V_2 -> V_36 )
F_25 ( & V_6 -> V_12 , L_22 , V_2 -> V_36 -> V_37 ) ;
V_3 = F_26 ( V_6 , V_2 , V_32 ) ;
if ( V_3 < 0 ) {
F_39 ( V_2 -> V_36 ) ;
F_39 ( V_2 -> V_26 ) ;
F_21 ( & V_6 -> V_12 , L_23 ) ;
goto V_35;
}
V_2 -> V_38 = ! ! V_3 ;
V_3 = 0 ;
V_35:
F_40 ( V_32 ) ;
return V_3 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
int V_3 ;
V_32 = F_33 ( V_2 -> V_8 ) ;
if ( F_34 ( V_32 ) ) {
F_42 ( V_2 -> V_8 , L_24 ) ;
return;
}
V_3 = F_29 ( V_32 ) ;
if ( V_3 < 0 )
F_10 ( & V_2 -> V_6 -> V_12 , L_25 , V_3 ) ;
else
F_25 ( & V_2 -> V_6 -> V_12 , L_26 ) ;
F_40 ( V_32 ) ;
}
static int F_43 ( struct V_9 * V_6 ,
const struct V_39 * V_40 )
{
struct V_41 * V_41 ;
struct V_1 * V_2 ;
int V_3 ;
V_3 = F_44 ( V_6 ) ;
if ( V_3 < 0 )
return V_3 ;
F_45 ( V_6 ) ;
V_3 = F_46 ( & V_6 -> V_12 ,
F_47 ( V_42 ) ) ;
if ( V_3 )
goto V_43;
V_3 = F_48 ( V_6 , V_44 ) ;
if ( V_3 < 0 ) {
F_21 ( & V_6 -> V_12 , L_27 ) ;
goto V_43;
}
V_41 = F_49 ( & V_45 , sizeof( * V_2 ) ) ;
if ( ! V_41 ) {
V_3 = - V_46 ;
goto V_47;
}
V_2 = F_50 ( V_41 ) ;
F_51 ( & V_2 -> V_48 ) ;
F_51 ( & V_2 -> V_29 ) ;
F_52 ( & V_2 -> V_13 ) ;
F_53 ( V_6 , V_2 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_49 = F_54 ( L_28 , 0 , 2 , F_55 ( V_6 ) ) ;
if ( ! V_2 -> V_49 ) {
V_3 = - V_46 ;
goto V_50;
}
V_2 -> V_8 = F_56 ( V_6 ) ;
if ( F_57 ( V_2 -> V_8 ) ) {
V_3 = F_35 ( V_2 -> V_8 ) ;
if ( V_3 >= 0 )
V_3 = - V_46 ;
goto V_51;
}
V_2 -> V_27 = F_58 ( V_2 -> V_8 ) ;
F_25 ( & V_6 -> V_12 , L_29 ,
F_22 ( V_2 -> V_27 , L_30 ) ,
F_22 ( V_2 -> V_27 , L_10 ) ,
F_22 ( V_2 -> V_27 , L_31 ) ,
F_22 ( V_2 -> V_27 , L_32 ) ,
F_22 ( V_2 -> V_27 , L_33 ) ) ;
V_3 = F_59 ( V_41 , & V_6 -> V_12 ) ;
if ( V_3 )
goto V_52;
V_3 = F_32 ( V_6 , V_2 ) ;
if ( V_3 )
goto V_53;
V_2 -> V_54 = F_60 ( V_2 -> V_8 ) ;
V_2 -> V_5 = F_61 ( V_2 -> V_8 , V_2 -> V_54 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_55;
V_2 -> V_10 = F_62 ( V_6 ) ;
if ( V_2 -> V_10 > V_2 -> V_4 ) {
F_21 ( & V_6 -> V_12 ,
L_34 ,
V_2 -> V_10 , V_2 -> V_4 ) ;
goto V_55;
}
V_3 = F_63 ( V_2 ) ;
if ( V_3 )
goto V_56;
V_3 = F_64 ( V_2 ) ;
if ( V_3 ) {
F_21 ( & V_6 -> V_12 , L_35 ) ;
goto V_57;
}
return 0 ;
V_57:
F_65 ( V_2 ) ;
V_56:
F_3 ( V_2 -> V_6 , 0 ) ;
V_55:
F_39 ( V_2 -> V_5 ) ;
F_66 ( V_2 -> V_54 ) ;
if ( V_2 -> V_38 )
F_41 ( V_2 ) ;
F_39 ( V_2 -> V_26 ) ;
F_39 ( V_2 -> V_36 ) ;
V_53:
F_67 ( V_41 ) ;
V_52:
F_39 ( V_2 -> V_27 ) ;
F_68 ( V_2 -> V_8 ) ;
V_51:
F_69 ( V_2 -> V_49 ) ;
V_50:
F_53 ( V_6 , NULL ) ;
F_70 ( & V_2 -> V_13 ) ;
F_71 ( V_41 ) ;
V_47:
F_72 ( V_6 ) ;
V_43:
F_73 ( V_6 ) ;
return V_3 ;
}
static void F_74 ( struct V_9 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
struct V_41 * V_41 ;
F_75 ( V_2 ) ;
V_41 = F_76 ( V_2 ) ;
F_65 ( V_2 ) ;
F_16 ( V_6 ) ;
F_3 ( V_2 -> V_6 , 0 ) ;
F_67 ( V_41 ) ;
F_39 ( V_2 -> V_5 ) ;
F_66 ( V_2 -> V_54 ) ;
if ( V_2 -> V_38 )
F_41 ( V_2 ) ;
F_69 ( V_2 -> V_49 ) ;
F_53 ( V_6 , NULL ) ;
F_39 ( V_2 -> V_27 ) ;
F_68 ( V_2 -> V_8 ) ;
F_39 ( V_2 -> V_26 ) ;
F_39 ( V_2 -> V_36 ) ;
F_70 ( & V_2 -> V_13 ) ;
F_71 ( V_41 ) ;
F_72 ( V_6 ) ;
F_73 ( V_6 ) ;
}
static int T_2 F_77 ( void )
{
int V_3 ;
F_78 ( L_36 ,
V_44 ) ;
F_79 () ;
V_3 = F_80 ( & V_58 ) ;
if ( V_3 < 0 )
goto V_59;
V_3 = F_80 ( & V_60 ) ;
if ( V_3 )
goto V_61;
return V_3 ;
V_61:
F_81 ( & V_58 ) ;
V_59:
F_82 () ;
return V_3 ;
}
static void T_3 F_83 ( void )
{
F_81 ( & V_60 ) ;
F_81 ( & V_58 ) ;
F_82 () ;
}
