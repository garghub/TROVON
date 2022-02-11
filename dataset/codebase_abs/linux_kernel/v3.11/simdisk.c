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
char * V_11 = F_13 ( V_22 , V_23 ) ;
unsigned V_27 = V_25 -> V_28 >> V_14 ;
F_3 ( V_8 , V_9 , V_27 , V_11 ,
F_14 ( V_22 ) == V_29 ) ;
V_9 += V_27 ;
F_15 ( V_22 ) ;
}
return 0 ;
}
static void F_16 ( struct V_30 * V_31 , struct V_22 * V_22 )
{
struct V_7 * V_8 = V_31 -> V_32 ;
int V_33 = F_11 ( V_8 , V_22 ) ;
F_17 ( V_22 , V_33 ) ;
}
static int F_18 ( struct V_34 * V_35 , T_2 V_36 )
{
struct V_7 * V_8 = V_35 -> V_37 -> V_38 ;
F_5 ( & V_8 -> V_17 ) ;
if ( ! V_8 -> V_39 )
F_19 ( V_35 ) ;
++ V_8 -> V_39 ;
F_10 ( & V_8 -> V_17 ) ;
return 0 ;
}
static void F_20 ( struct V_40 * V_41 , T_2 V_36 )
{
struct V_7 * V_8 = V_41 -> V_38 ;
F_5 ( & V_8 -> V_17 ) ;
-- V_8 -> V_39 ;
F_10 ( & V_8 -> V_17 ) ;
}
static int F_21 ( struct V_7 * V_8 , const char * V_5 )
{
int V_42 = 0 ;
V_5 = F_22 ( V_5 , V_43 ) ;
if ( V_5 == NULL )
return - V_44 ;
F_5 ( & V_8 -> V_17 ) ;
if ( V_8 -> V_19 != - 1 ) {
V_42 = - V_45 ;
goto V_46;
}
V_8 -> V_19 = F_23 ( V_5 , V_47 , 0 ) ;
if ( V_8 -> V_19 == - 1 ) {
F_9 ( L_5 , V_5 , V_21 ) ;
V_42 = - V_48 ;
goto V_46;
}
V_8 -> V_16 = F_6 ( V_8 -> V_19 , 0 , V_49 ) ;
F_24 ( V_8 -> V_50 , V_8 -> V_16 >> V_14 ) ;
V_8 -> V_5 = V_5 ;
F_25 ( L_6 , V_8 -> V_50 -> V_51 , V_8 -> V_5 ) ;
V_46:
if ( V_42 )
F_26 ( V_5 ) ;
F_10 ( & V_8 -> V_17 ) ;
return V_42 ;
}
static int F_27 ( struct V_7 * V_8 )
{
int V_42 = 0 ;
F_5 ( & V_8 -> V_17 ) ;
if ( V_8 -> V_39 != 0 ) {
V_42 = - V_45 ;
} else if ( V_8 -> V_19 != - 1 ) {
if ( F_28 ( V_8 -> V_19 ) ) {
F_9 ( L_7 ,
V_8 -> V_5 , V_21 ) ;
V_42 = - V_52 ;
} else {
F_25 ( L_8 ,
V_8 -> V_50 -> V_51 , V_8 -> V_5 ) ;
V_8 -> V_19 = - 1 ;
F_26 ( V_8 -> V_5 ) ;
V_8 -> V_5 = NULL ;
}
}
F_10 ( & V_8 -> V_17 ) ;
return V_42 ;
}
static T_3 F_29 ( struct V_53 * V_53 , char T_4 * V_54 ,
T_5 V_16 , T_6 * V_55 )
{
struct V_7 * V_8 = F_30 ( F_31 ( V_53 ) ) ;
const char * V_56 = V_8 -> V_5 ;
if ( V_56 ) {
T_3 V_57 = F_32 ( V_54 , V_16 , V_55 ,
V_56 , strlen ( V_56 ) ) ;
if ( V_57 < 0 )
return V_57 ;
V_54 += V_57 ;
V_16 -= V_57 ;
}
return F_32 ( V_54 , V_16 , V_55 , L_9 , 1 ) ;
}
static T_3 F_33 ( struct V_53 * V_53 , const char T_4 * V_54 ,
T_5 V_58 , T_6 * V_55 )
{
char * V_59 = F_34 ( V_58 + 1 , V_43 ) ;
struct V_7 * V_8 = F_30 ( F_31 ( V_53 ) ) ;
int V_42 ;
if ( V_59 == NULL )
return - V_44 ;
if ( F_35 ( V_59 , V_54 , V_58 ) ) {
V_42 = - V_60 ;
goto V_61;
}
V_42 = F_27 ( V_8 ) ;
if ( V_42 != 0 )
goto V_61;
if ( V_58 > 0 && V_59 [ V_58 - 1 ] == '\n' )
V_59 [ V_58 - 1 ] = 0 ;
else
V_59 [ V_58 ] = 0 ;
if ( V_59 [ 0 ] )
V_42 = F_21 ( V_8 , V_59 ) ;
if ( V_42 == 0 )
V_42 = V_58 ;
V_61:
F_26 ( V_59 ) ;
return V_42 ;
}
static int T_7 F_36 ( struct V_7 * V_8 , int V_62 ,
struct V_63 * V_64 )
{
char V_59 [ 2 ] = { '0' + V_62 , 0 } ;
V_8 -> V_19 = - 1 ;
V_8 -> V_5 = NULL ;
F_37 ( & V_8 -> V_17 ) ;
V_8 -> V_39 = 0 ;
V_8 -> V_65 = F_38 ( V_43 ) ;
if ( V_8 -> V_65 == NULL ) {
F_9 ( L_10 ) ;
goto V_66;
}
F_39 ( V_8 -> V_65 , F_16 ) ;
V_8 -> V_65 -> V_32 = V_8 ;
V_8 -> V_50 = F_40 ( V_67 ) ;
if ( V_8 -> V_50 == NULL ) {
F_9 ( L_11 ) ;
goto V_68;
}
V_8 -> V_50 -> V_69 = V_70 ;
V_8 -> V_50 -> V_71 = V_62 ;
V_8 -> V_50 -> V_72 = & V_73 ;
V_8 -> V_50 -> V_65 = V_8 -> V_65 ;
V_8 -> V_50 -> V_38 = V_8 ;
snprintf ( V_8 -> V_50 -> V_51 , 32 , L_12 , V_62 ) ;
F_24 ( V_8 -> V_50 , 0 ) ;
F_41 ( V_8 -> V_50 ) ;
V_8 -> V_74 = F_42 ( V_59 , 0644 , V_64 , & V_72 , V_8 ) ;
return 0 ;
V_68:
F_43 ( V_8 -> V_65 ) ;
V_8 -> V_65 = NULL ;
V_66:
F_28 ( V_8 -> V_19 ) ;
return - V_52 ;
}
static int T_7 F_44 ( void )
{
int V_23 ;
if ( F_45 ( V_70 , L_13 ) < 0 ) {
F_9 ( L_14 , V_70 ) ;
return - V_52 ;
}
F_25 ( L_15 , V_70 ) ;
if ( V_4 > V_75 )
V_75 = V_4 ;
if ( V_75 > V_76 )
V_75 = V_76 ;
V_77 = F_34 ( V_75 * sizeof( struct V_7 ) ,
V_43 ) ;
if ( V_77 == NULL )
goto V_78;
V_79 = F_46 ( L_13 , 0 ) ;
if ( V_79 == NULL )
goto V_80;
for ( V_23 = 0 ; V_23 < V_75 ; ++ V_23 ) {
if ( F_36 ( V_77 + V_23 , V_23 , V_79 ) == 0 ) {
if ( V_5 [ V_23 ] != NULL && V_5 [ V_23 ] [ 0 ] != 0 &&
( V_4 == 0 || V_23 < V_4 ) )
F_21 ( V_77 + V_23 , V_5 [ V_23 ] ) ;
}
}
return 0 ;
V_80:
F_26 ( V_77 ) ;
V_78:
F_47 ( V_70 , L_13 ) ;
return - V_44 ;
}
static void F_48 ( struct V_7 * V_8 , int V_62 ,
struct V_63 * V_64 )
{
char V_59 [ 2 ] = { '0' + V_62 , 0 } ;
F_27 ( V_8 ) ;
if ( V_8 -> V_50 )
F_49 ( V_8 -> V_50 ) ;
if ( V_8 -> V_65 )
F_43 ( V_8 -> V_65 ) ;
F_50 ( V_59 , V_64 ) ;
}
static void T_8 F_51 ( void )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_75 ; ++ V_23 )
F_48 ( V_77 + V_23 , V_23 , V_79 ) ;
F_50 ( L_13 , 0 ) ;
F_26 ( V_77 ) ;
F_47 ( V_70 , L_13 ) ;
}
