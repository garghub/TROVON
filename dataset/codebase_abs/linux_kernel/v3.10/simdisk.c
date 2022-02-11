static int F_1 ( const char * V_1 ,
const struct V_2 * V_3 )
{
if ( V_4 < F_2 ( V_5 ) )
V_5 [ V_4 ++ ] = V_1 ;
else
return - V_6 ;
return 0 ;
}
static void F_3 ( struct V_7 * V_8 , unsigned long V_9 ,
unsigned long V_10 , char * V_11 , int V_12 )
{
unsigned long V_13 = V_9 << V_14 ;
unsigned long V_15 = V_10 << V_14 ;
if ( V_13 > V_8 -> V_16 || V_8 -> V_16 - V_13 < V_15 ) {
F_4 ( L_1 ,
V_12 ? L_2 : L_3 , V_13 , V_15 ) ;
return;
}
F_5 ( & V_8 -> V_17 ) ;
while ( V_15 > 0 ) {
unsigned long V_18 ;
F_6 ( V_8 -> V_19 , V_13 , V_20 ) ;
if ( V_12 )
V_18 = F_7 ( V_8 -> V_19 , V_11 , V_15 ) ;
else
V_18 = F_8 ( V_8 -> V_19 , V_11 , V_15 ) ;
if ( V_18 == - 1 ) {
F_9 ( L_4 , V_21 ) ;
break;
}
V_11 += V_18 ;
V_13 += V_18 ;
V_15 -= V_18 ;
}
F_10 ( & V_8 -> V_17 ) ;
}
static int F_11 ( struct V_7 * V_8 , struct V_22 * V_22 )
{
int V_23 ;
struct V_24 * V_25 ;
T_1 V_9 = V_22 -> V_26 ;
F_12 (bvec, bio, i) {
char * V_11 = F_13 ( V_22 , V_23 , V_27 ) ;
unsigned V_28 = V_25 -> V_29 >> V_14 ;
F_3 ( V_8 , V_9 , V_28 , V_11 ,
F_14 ( V_22 ) == V_30 ) ;
V_9 += V_28 ;
F_15 ( V_22 , V_27 ) ;
}
return 0 ;
}
static void F_16 ( struct V_31 * V_32 , struct V_22 * V_22 )
{
struct V_7 * V_8 = V_32 -> V_33 ;
int V_34 = F_11 ( V_8 , V_22 ) ;
F_17 ( V_22 , V_34 ) ;
}
static int F_18 ( struct V_35 * V_36 , T_2 V_37 )
{
struct V_7 * V_8 = V_36 -> V_38 -> V_39 ;
F_5 ( & V_8 -> V_17 ) ;
if ( ! V_8 -> V_40 )
F_19 ( V_36 ) ;
++ V_8 -> V_40 ;
F_10 ( & V_8 -> V_17 ) ;
return 0 ;
}
static void F_20 ( struct V_41 * V_42 , T_2 V_37 )
{
struct V_7 * V_8 = V_42 -> V_39 ;
F_5 ( & V_8 -> V_17 ) ;
-- V_8 -> V_40 ;
F_10 ( & V_8 -> V_17 ) ;
}
static int F_21 ( struct V_7 * V_8 , const char * V_5 )
{
int V_43 = 0 ;
V_5 = F_22 ( V_5 , V_44 ) ;
if ( V_5 == NULL )
return - V_45 ;
F_5 ( & V_8 -> V_17 ) ;
if ( V_8 -> V_19 != - 1 ) {
V_43 = - V_46 ;
goto V_47;
}
V_8 -> V_19 = F_23 ( V_5 , V_48 , 0 ) ;
if ( V_8 -> V_19 == - 1 ) {
F_9 ( L_5 , V_5 , V_21 ) ;
V_43 = - V_49 ;
goto V_47;
}
V_8 -> V_16 = F_6 ( V_8 -> V_19 , 0 , V_50 ) ;
F_24 ( V_8 -> V_51 , V_8 -> V_16 >> V_14 ) ;
V_8 -> V_5 = V_5 ;
F_25 ( L_6 , V_8 -> V_51 -> V_52 , V_8 -> V_5 ) ;
V_47:
if ( V_43 )
F_26 ( V_5 ) ;
F_10 ( & V_8 -> V_17 ) ;
return V_43 ;
}
static int F_27 ( struct V_7 * V_8 )
{
int V_43 = 0 ;
F_5 ( & V_8 -> V_17 ) ;
if ( V_8 -> V_40 != 0 ) {
V_43 = - V_46 ;
} else if ( V_8 -> V_19 != - 1 ) {
if ( F_28 ( V_8 -> V_19 ) ) {
F_9 ( L_7 ,
V_8 -> V_5 , V_21 ) ;
V_43 = - V_53 ;
} else {
F_25 ( L_8 ,
V_8 -> V_51 -> V_52 , V_8 -> V_5 ) ;
V_8 -> V_19 = - 1 ;
F_26 ( V_8 -> V_5 ) ;
V_8 -> V_5 = NULL ;
}
}
F_10 ( & V_8 -> V_17 ) ;
return V_43 ;
}
static T_3 F_29 ( struct V_54 * V_54 , char T_4 * V_55 ,
T_5 V_16 , T_6 * V_56 )
{
struct V_7 * V_8 = F_30 ( F_31 ( V_54 ) ) ;
const char * V_57 = V_8 -> V_5 ;
if ( V_57 ) {
T_3 V_58 = F_32 ( V_55 , V_16 , V_56 ,
V_57 , strlen ( V_57 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_55 += V_58 ;
V_16 -= V_58 ;
}
return F_32 ( V_55 , V_16 , V_56 , L_9 , 1 ) ;
}
static T_3 F_33 ( struct V_54 * V_54 , const char T_4 * V_55 ,
T_5 V_59 , T_6 * V_56 )
{
char * V_60 = F_34 ( V_59 + 1 , V_44 ) ;
struct V_7 * V_8 = F_30 ( F_31 ( V_54 ) ) ;
int V_43 ;
if ( V_60 == NULL )
return - V_45 ;
if ( F_35 ( V_60 , V_55 , V_59 ) ) {
V_43 = - V_61 ;
goto V_62;
}
V_43 = F_27 ( V_8 ) ;
if ( V_43 != 0 )
goto V_62;
if ( V_59 > 0 && V_60 [ V_59 - 1 ] == '\n' )
V_60 [ V_59 - 1 ] = 0 ;
else
V_60 [ V_59 ] = 0 ;
if ( V_60 [ 0 ] )
V_43 = F_21 ( V_8 , V_60 ) ;
if ( V_43 == 0 )
V_43 = V_59 ;
V_62:
F_26 ( V_60 ) ;
return V_43 ;
}
static int T_7 F_36 ( struct V_7 * V_8 , int V_63 ,
struct V_64 * V_65 )
{
char V_60 [ 2 ] = { '0' + V_63 , 0 } ;
V_8 -> V_19 = - 1 ;
V_8 -> V_5 = NULL ;
F_37 ( & V_8 -> V_17 ) ;
V_8 -> V_40 = 0 ;
V_8 -> V_66 = F_38 ( V_44 ) ;
if ( V_8 -> V_66 == NULL ) {
F_9 ( L_10 ) ;
goto V_67;
}
F_39 ( V_8 -> V_66 , F_16 ) ;
V_8 -> V_66 -> V_33 = V_8 ;
V_8 -> V_51 = F_40 ( V_68 ) ;
if ( V_8 -> V_51 == NULL ) {
F_9 ( L_11 ) ;
goto V_69;
}
V_8 -> V_51 -> V_70 = V_71 ;
V_8 -> V_51 -> V_72 = V_63 ;
V_8 -> V_51 -> V_73 = & V_74 ;
V_8 -> V_51 -> V_66 = V_8 -> V_66 ;
V_8 -> V_51 -> V_39 = V_8 ;
snprintf ( V_8 -> V_51 -> V_52 , 32 , L_12 , V_63 ) ;
F_24 ( V_8 -> V_51 , 0 ) ;
F_41 ( V_8 -> V_51 ) ;
V_8 -> V_75 = F_42 ( V_60 , 0644 , V_65 , & V_73 , V_8 ) ;
return 0 ;
V_69:
F_43 ( V_8 -> V_66 ) ;
V_8 -> V_66 = NULL ;
V_67:
F_28 ( V_8 -> V_19 ) ;
return - V_53 ;
}
static int T_7 F_44 ( void )
{
int V_23 ;
if ( F_45 ( V_71 , L_13 ) < 0 ) {
F_9 ( L_14 , V_71 ) ;
return - V_53 ;
}
F_25 ( L_15 , V_71 ) ;
if ( V_4 > V_76 )
V_76 = V_4 ;
if ( V_76 > V_77 )
V_76 = V_77 ;
V_78 = F_34 ( V_76 * sizeof( struct V_7 ) ,
V_44 ) ;
if ( V_78 == NULL )
goto V_79;
V_80 = F_46 ( L_13 , 0 ) ;
if ( V_80 == NULL )
goto V_81;
for ( V_23 = 0 ; V_23 < V_76 ; ++ V_23 ) {
if ( F_36 ( V_78 + V_23 , V_23 , V_80 ) == 0 ) {
if ( V_5 [ V_23 ] != NULL && V_5 [ V_23 ] [ 0 ] != 0 &&
( V_4 == 0 || V_23 < V_4 ) )
F_21 ( V_78 + V_23 , V_5 [ V_23 ] ) ;
}
}
return 0 ;
V_81:
F_26 ( V_78 ) ;
V_79:
F_47 ( V_71 , L_13 ) ;
return - V_45 ;
}
static void F_48 ( struct V_7 * V_8 , int V_63 ,
struct V_64 * V_65 )
{
char V_60 [ 2 ] = { '0' + V_63 , 0 } ;
F_27 ( V_8 ) ;
if ( V_8 -> V_51 )
F_49 ( V_8 -> V_51 ) ;
if ( V_8 -> V_66 )
F_43 ( V_8 -> V_66 ) ;
F_50 ( V_60 , V_65 ) ;
}
static void T_8 F_51 ( void )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_76 ; ++ V_23 )
F_48 ( V_78 + V_23 , V_23 , V_80 ) ;
F_50 ( L_13 , 0 ) ;
F_26 ( V_78 ) ;
F_47 ( V_71 , L_13 ) ;
}
