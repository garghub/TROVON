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
struct V_23 V_24 ;
struct V_25 V_26 ;
T_1 V_9 = V_22 -> V_27 . V_28 ;
F_12 (bvec, bio, iter) {
char * V_11 = F_13 ( V_22 , V_26 ) ;
unsigned V_29 = V_24 . V_30 >> V_14 ;
F_3 ( V_8 , V_9 , V_29 , V_11 ,
F_14 ( V_22 ) == V_31 ) ;
V_9 += V_29 ;
F_15 ( V_11 ) ;
}
return 0 ;
}
static void F_16 ( struct V_32 * V_33 , struct V_22 * V_22 )
{
struct V_7 * V_8 = V_33 -> V_34 ;
int V_35 = F_11 ( V_8 , V_22 ) ;
F_17 ( V_22 , V_35 ) ;
}
static int F_18 ( struct V_36 * V_37 , T_2 V_38 )
{
struct V_7 * V_8 = V_37 -> V_39 -> V_40 ;
F_5 ( & V_8 -> V_17 ) ;
if ( ! V_8 -> V_41 )
F_19 ( V_37 ) ;
++ V_8 -> V_41 ;
F_10 ( & V_8 -> V_17 ) ;
return 0 ;
}
static void F_20 ( struct V_42 * V_43 , T_2 V_38 )
{
struct V_7 * V_8 = V_43 -> V_40 ;
F_5 ( & V_8 -> V_17 ) ;
-- V_8 -> V_41 ;
F_10 ( & V_8 -> V_17 ) ;
}
static int F_21 ( struct V_7 * V_8 , const char * V_5 )
{
int V_44 = 0 ;
V_5 = F_22 ( V_5 , V_45 ) ;
if ( V_5 == NULL )
return - V_46 ;
F_5 ( & V_8 -> V_17 ) ;
if ( V_8 -> V_19 != - 1 ) {
V_44 = - V_47 ;
goto V_48;
}
V_8 -> V_19 = F_23 ( V_5 , V_49 , 0 ) ;
if ( V_8 -> V_19 == - 1 ) {
F_9 ( L_5 , V_5 , V_21 ) ;
V_44 = - V_50 ;
goto V_48;
}
V_8 -> V_16 = F_6 ( V_8 -> V_19 , 0 , V_51 ) ;
F_24 ( V_8 -> V_52 , V_8 -> V_16 >> V_14 ) ;
V_8 -> V_5 = V_5 ;
F_25 ( L_6 , V_8 -> V_52 -> V_53 , V_8 -> V_5 ) ;
V_48:
if ( V_44 )
F_26 ( V_5 ) ;
F_10 ( & V_8 -> V_17 ) ;
return V_44 ;
}
static int F_27 ( struct V_7 * V_8 )
{
int V_44 = 0 ;
F_5 ( & V_8 -> V_17 ) ;
if ( V_8 -> V_41 != 0 ) {
V_44 = - V_47 ;
} else if ( V_8 -> V_19 != - 1 ) {
if ( F_28 ( V_8 -> V_19 ) ) {
F_9 ( L_7 ,
V_8 -> V_5 , V_21 ) ;
V_44 = - V_54 ;
} else {
F_25 ( L_8 ,
V_8 -> V_52 -> V_53 , V_8 -> V_5 ) ;
V_8 -> V_19 = - 1 ;
F_26 ( V_8 -> V_5 ) ;
V_8 -> V_5 = NULL ;
}
}
F_10 ( & V_8 -> V_17 ) ;
return V_44 ;
}
static T_3 F_29 ( struct V_55 * V_55 , char T_4 * V_56 ,
T_5 V_16 , T_6 * V_57 )
{
struct V_7 * V_8 = F_30 ( F_31 ( V_55 ) ) ;
const char * V_58 = V_8 -> V_5 ;
if ( V_58 ) {
T_3 V_59 = F_32 ( V_56 , V_16 , V_57 ,
V_58 , strlen ( V_58 ) ) ;
if ( V_59 < 0 )
return V_59 ;
V_56 += V_59 ;
V_16 -= V_59 ;
}
return F_32 ( V_56 , V_16 , V_57 , L_9 , 1 ) ;
}
static T_3 F_33 ( struct V_55 * V_55 , const char T_4 * V_56 ,
T_5 V_60 , T_6 * V_57 )
{
char * V_61 = F_34 ( V_60 + 1 , V_45 ) ;
struct V_7 * V_8 = F_30 ( F_31 ( V_55 ) ) ;
int V_44 ;
if ( V_61 == NULL )
return - V_46 ;
if ( F_35 ( V_61 , V_56 , V_60 ) ) {
V_44 = - V_62 ;
goto V_63;
}
V_44 = F_27 ( V_8 ) ;
if ( V_44 != 0 )
goto V_63;
if ( V_60 > 0 && V_61 [ V_60 - 1 ] == '\n' )
V_61 [ V_60 - 1 ] = 0 ;
else
V_61 [ V_60 ] = 0 ;
if ( V_61 [ 0 ] )
V_44 = F_21 ( V_8 , V_61 ) ;
if ( V_44 == 0 )
V_44 = V_60 ;
V_63:
F_26 ( V_61 ) ;
return V_44 ;
}
static int T_7 F_36 ( struct V_7 * V_8 , int V_64 ,
struct V_65 * V_66 )
{
char V_61 [ 2 ] = { '0' + V_64 , 0 } ;
V_8 -> V_19 = - 1 ;
V_8 -> V_5 = NULL ;
F_37 ( & V_8 -> V_17 ) ;
V_8 -> V_41 = 0 ;
V_8 -> V_67 = F_38 ( V_45 ) ;
if ( V_8 -> V_67 == NULL ) {
F_9 ( L_10 ) ;
goto V_68;
}
F_39 ( V_8 -> V_67 , F_16 ) ;
V_8 -> V_67 -> V_34 = V_8 ;
V_8 -> V_52 = F_40 ( V_69 ) ;
if ( V_8 -> V_52 == NULL ) {
F_9 ( L_11 ) ;
goto V_70;
}
V_8 -> V_52 -> V_71 = V_72 ;
V_8 -> V_52 -> V_73 = V_64 ;
V_8 -> V_52 -> V_74 = & V_75 ;
V_8 -> V_52 -> V_67 = V_8 -> V_67 ;
V_8 -> V_52 -> V_40 = V_8 ;
snprintf ( V_8 -> V_52 -> V_53 , 32 , L_12 , V_64 ) ;
F_24 ( V_8 -> V_52 , 0 ) ;
F_41 ( V_8 -> V_52 ) ;
V_8 -> V_76 = F_42 ( V_61 , 0644 , V_66 , & V_74 , V_8 ) ;
return 0 ;
V_70:
F_43 ( V_8 -> V_67 ) ;
V_8 -> V_67 = NULL ;
V_68:
F_28 ( V_8 -> V_19 ) ;
return - V_54 ;
}
static int T_7 F_44 ( void )
{
int V_77 ;
if ( F_45 ( V_72 , L_13 ) < 0 ) {
F_9 ( L_14 , V_72 ) ;
return - V_54 ;
}
F_25 ( L_15 , V_72 ) ;
if ( V_4 > V_78 )
V_78 = V_4 ;
if ( V_78 > V_79 )
V_78 = V_79 ;
V_80 = F_34 ( V_78 * sizeof( struct V_7 ) ,
V_45 ) ;
if ( V_80 == NULL )
goto V_81;
V_82 = F_46 ( L_13 , 0 ) ;
if ( V_82 == NULL )
goto V_83;
for ( V_77 = 0 ; V_77 < V_78 ; ++ V_77 ) {
if ( F_36 ( V_80 + V_77 , V_77 , V_82 ) == 0 ) {
if ( V_5 [ V_77 ] != NULL && V_5 [ V_77 ] [ 0 ] != 0 &&
( V_4 == 0 || V_77 < V_4 ) )
F_21 ( V_80 + V_77 , V_5 [ V_77 ] ) ;
}
}
return 0 ;
V_83:
F_26 ( V_80 ) ;
V_81:
F_47 ( V_72 , L_13 ) ;
return - V_46 ;
}
static void F_48 ( struct V_7 * V_8 , int V_64 ,
struct V_65 * V_66 )
{
char V_61 [ 2 ] = { '0' + V_64 , 0 } ;
F_27 ( V_8 ) ;
if ( V_8 -> V_52 )
F_49 ( V_8 -> V_52 ) ;
if ( V_8 -> V_67 )
F_43 ( V_8 -> V_67 ) ;
F_50 ( V_61 , V_66 ) ;
}
static void T_8 F_51 ( void )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_78 ; ++ V_77 )
F_48 ( V_80 + V_77 , V_77 , V_82 ) ;
F_50 ( L_13 , 0 ) ;
F_26 ( V_80 ) ;
F_47 ( V_72 , L_13 ) ;
}
