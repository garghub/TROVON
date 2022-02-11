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
static void F_11 ( struct V_22 * V_23 , struct V_24 * V_24 )
{
struct V_7 * V_8 = V_23 -> V_25 ;
struct V_26 V_27 ;
struct V_28 V_29 ;
T_1 V_9 = V_24 -> V_30 . V_31 ;
F_12 (bvec, bio, iter) {
char * V_11 = F_13 ( V_24 , V_29 ) ;
unsigned V_32 = V_27 . V_33 >> V_14 ;
F_3 ( V_8 , V_9 , V_32 , V_11 ,
F_14 ( V_24 ) == V_34 ) ;
V_9 += V_32 ;
F_15 ( V_11 ) ;
}
F_16 ( V_24 ) ;
}
static int F_17 ( struct V_35 * V_36 , T_2 V_37 )
{
struct V_7 * V_8 = V_36 -> V_38 -> V_39 ;
F_5 ( & V_8 -> V_17 ) ;
if ( ! V_8 -> V_40 )
F_18 ( V_36 ) ;
++ V_8 -> V_40 ;
F_10 ( & V_8 -> V_17 ) ;
return 0 ;
}
static void F_19 ( struct V_41 * V_42 , T_2 V_37 )
{
struct V_7 * V_8 = V_42 -> V_39 ;
F_5 ( & V_8 -> V_17 ) ;
-- V_8 -> V_40 ;
F_10 ( & V_8 -> V_17 ) ;
}
static int F_20 ( struct V_7 * V_8 , const char * V_5 )
{
int V_43 = 0 ;
V_5 = F_21 ( V_5 , V_44 ) ;
if ( V_5 == NULL )
return - V_45 ;
F_5 ( & V_8 -> V_17 ) ;
if ( V_8 -> V_19 != - 1 ) {
V_43 = - V_46 ;
goto V_47;
}
V_8 -> V_19 = F_22 ( V_5 , V_48 , 0 ) ;
if ( V_8 -> V_19 == - 1 ) {
F_9 ( L_5 , V_5 , V_21 ) ;
V_43 = - V_49 ;
goto V_47;
}
V_8 -> V_16 = F_6 ( V_8 -> V_19 , 0 , V_50 ) ;
F_23 ( V_8 -> V_51 , V_8 -> V_16 >> V_14 ) ;
V_8 -> V_5 = V_5 ;
F_24 ( L_6 , V_8 -> V_51 -> V_52 , V_8 -> V_5 ) ;
V_47:
if ( V_43 )
F_25 ( V_5 ) ;
F_10 ( & V_8 -> V_17 ) ;
return V_43 ;
}
static int F_26 ( struct V_7 * V_8 )
{
int V_43 = 0 ;
F_5 ( & V_8 -> V_17 ) ;
if ( V_8 -> V_40 != 0 ) {
V_43 = - V_46 ;
} else if ( V_8 -> V_19 != - 1 ) {
if ( F_27 ( V_8 -> V_19 ) ) {
F_9 ( L_7 ,
V_8 -> V_5 , V_21 ) ;
V_43 = - V_53 ;
} else {
F_24 ( L_8 ,
V_8 -> V_51 -> V_52 , V_8 -> V_5 ) ;
V_8 -> V_19 = - 1 ;
F_25 ( V_8 -> V_5 ) ;
V_8 -> V_5 = NULL ;
}
}
F_10 ( & V_8 -> V_17 ) ;
return V_43 ;
}
static T_3 F_28 ( struct V_54 * V_54 , char T_4 * V_55 ,
T_5 V_16 , T_6 * V_56 )
{
struct V_7 * V_8 = F_29 ( F_30 ( V_54 ) ) ;
const char * V_57 = V_8 -> V_5 ;
if ( V_57 ) {
T_3 V_58 = F_31 ( V_55 , V_16 , V_56 ,
V_57 , strlen ( V_57 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_55 += V_58 ;
V_16 -= V_58 ;
}
return F_31 ( V_55 , V_16 , V_56 , L_9 , 1 ) ;
}
static T_3 F_32 ( struct V_54 * V_54 , const char T_4 * V_55 ,
T_5 V_59 , T_6 * V_56 )
{
char * V_60 = F_33 ( V_59 + 1 , V_44 ) ;
struct V_7 * V_8 = F_29 ( F_30 ( V_54 ) ) ;
int V_43 ;
if ( V_60 == NULL )
return - V_45 ;
if ( F_34 ( V_60 , V_55 , V_59 ) ) {
V_43 = - V_61 ;
goto V_62;
}
V_43 = F_26 ( V_8 ) ;
if ( V_43 != 0 )
goto V_62;
if ( V_59 > 0 && V_60 [ V_59 - 1 ] == '\n' )
V_60 [ V_59 - 1 ] = 0 ;
else
V_60 [ V_59 ] = 0 ;
if ( V_60 [ 0 ] )
V_43 = F_20 ( V_8 , V_60 ) ;
if ( V_43 == 0 )
V_43 = V_59 ;
V_62:
F_25 ( V_60 ) ;
return V_43 ;
}
static int T_7 F_35 ( struct V_7 * V_8 , int V_63 ,
struct V_64 * V_65 )
{
char V_60 [ 2 ] = { '0' + V_63 , 0 } ;
V_8 -> V_19 = - 1 ;
V_8 -> V_5 = NULL ;
F_36 ( & V_8 -> V_17 ) ;
V_8 -> V_40 = 0 ;
V_8 -> V_66 = F_37 ( V_44 ) ;
if ( V_8 -> V_66 == NULL ) {
F_9 ( L_10 ) ;
goto V_67;
}
F_38 ( V_8 -> V_66 , F_11 ) ;
V_8 -> V_66 -> V_25 = V_8 ;
V_8 -> V_51 = F_39 ( V_68 ) ;
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
F_23 ( V_8 -> V_51 , 0 ) ;
F_40 ( V_8 -> V_51 ) ;
V_8 -> V_75 = F_41 ( V_60 , 0644 , V_65 , & V_73 , V_8 ) ;
return 0 ;
V_69:
F_42 ( V_8 -> V_66 ) ;
V_8 -> V_66 = NULL ;
V_67:
F_27 ( V_8 -> V_19 ) ;
return - V_53 ;
}
static int T_7 F_43 ( void )
{
int V_76 ;
if ( F_44 ( V_71 , L_13 ) < 0 ) {
F_9 ( L_14 , V_71 ) ;
return - V_53 ;
}
F_24 ( L_15 , V_71 ) ;
if ( V_4 > V_77 )
V_77 = V_4 ;
if ( V_77 > V_78 )
V_77 = V_78 ;
V_79 = F_33 ( V_77 * sizeof( struct V_7 ) ,
V_44 ) ;
if ( V_79 == NULL )
goto V_80;
V_81 = F_45 ( L_13 , 0 ) ;
if ( V_81 == NULL )
goto V_82;
for ( V_76 = 0 ; V_76 < V_77 ; ++ V_76 ) {
if ( F_35 ( V_79 + V_76 , V_76 , V_81 ) == 0 ) {
if ( V_5 [ V_76 ] != NULL && V_5 [ V_76 ] [ 0 ] != 0 &&
( V_4 == 0 || V_76 < V_4 ) )
F_20 ( V_79 + V_76 , V_5 [ V_76 ] ) ;
}
}
return 0 ;
V_82:
F_25 ( V_79 ) ;
V_80:
F_46 ( V_71 , L_13 ) ;
return - V_45 ;
}
static void F_47 ( struct V_7 * V_8 , int V_63 ,
struct V_64 * V_65 )
{
char V_60 [ 2 ] = { '0' + V_63 , 0 } ;
F_26 ( V_8 ) ;
if ( V_8 -> V_51 )
F_48 ( V_8 -> V_51 ) ;
if ( V_8 -> V_66 )
F_42 ( V_8 -> V_66 ) ;
F_49 ( V_60 , V_65 ) ;
}
static void T_8 F_50 ( void )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_77 ; ++ V_76 )
F_47 ( V_79 + V_76 , V_76 , V_81 ) ;
F_49 ( L_13 , 0 ) ;
F_25 ( V_79 ) ;
F_46 ( V_71 , L_13 ) ;
}
