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
F_6 ( V_19 , V_8 -> V_20 , V_13 , V_21 , 0 , 0 ) ;
if ( V_12 )
V_18 = F_7 ( V_8 -> V_20 , V_11 , V_15 ) ;
else
V_18 = F_8 ( V_8 -> V_20 , V_11 , V_15 ) ;
if ( V_18 == - 1 ) {
F_9 ( L_4 , V_22 ) ;
break;
}
V_11 += V_18 ;
V_13 += V_18 ;
V_15 -= V_18 ;
}
F_10 ( & V_8 -> V_17 ) ;
}
static int F_11 ( struct V_7 * V_8 , struct V_23 * V_23 )
{
int V_24 ;
struct V_25 * V_26 ;
T_1 V_9 = V_23 -> V_27 ;
F_12 (bvec, bio, i) {
char * V_11 = F_13 ( V_23 , V_24 , V_28 ) ;
unsigned V_29 = V_26 -> V_30 >> V_14 ;
F_3 ( V_8 , V_9 , V_29 , V_11 ,
F_14 ( V_23 ) == V_31 ) ;
V_9 += V_29 ;
F_15 ( V_23 , V_28 ) ;
}
return 0 ;
}
static void F_16 ( struct V_32 * V_33 , struct V_23 * V_23 )
{
struct V_7 * V_8 = V_33 -> V_34 ;
int V_35 = F_11 ( V_8 , V_23 ) ;
F_17 ( V_23 , V_35 ) ;
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
static int F_20 ( struct V_42 * V_43 , T_2 V_38 )
{
struct V_7 * V_8 = V_43 -> V_40 ;
F_5 ( & V_8 -> V_17 ) ;
-- V_8 -> V_41 ;
F_10 ( & V_8 -> V_17 ) ;
return 0 ;
}
static int F_21 ( struct V_7 * V_8 , const char * V_5 )
{
int V_44 = 0 ;
V_5 = F_22 ( V_5 , V_45 ) ;
if ( V_5 == NULL )
return - V_46 ;
F_5 ( & V_8 -> V_17 ) ;
if ( V_8 -> V_20 != - 1 ) {
V_44 = - V_47 ;
goto V_48;
}
V_8 -> V_20 = F_23 ( V_5 , V_49 , 0 ) ;
if ( V_8 -> V_20 == - 1 ) {
F_9 ( L_5 , V_5 , V_22 ) ;
V_44 = - V_50 ;
goto V_48;
}
V_8 -> V_16 = F_6 ( V_19 , V_8 -> V_20 , 0 , V_51 , 0 , 0 ) ;
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
} else if ( V_8 -> V_20 != - 1 ) {
if ( F_28 ( V_8 -> V_20 ) ) {
F_9 ( L_7 ,
V_8 -> V_5 , V_22 ) ;
V_44 = - V_54 ;
} else {
F_25 ( L_8 ,
V_8 -> V_52 -> V_53 , V_8 -> V_5 ) ;
V_8 -> V_20 = - 1 ;
F_26 ( V_8 -> V_5 ) ;
V_8 -> V_5 = NULL ;
}
}
F_10 ( & V_8 -> V_17 ) ;
return V_44 ;
}
static int F_29 ( char * V_55 , char * * V_56 , T_3 V_57 ,
int V_58 , int * V_59 , void * V_60 )
{
int V_29 ;
struct V_7 * V_8 = (struct V_7 * ) V_60 ;
V_29 = sprintf ( V_55 , L_9 , V_8 -> V_5 ? V_8 -> V_5 : L_10 ) ;
return V_29 ;
}
static int F_30 ( struct V_61 * V_61 , const char * V_11 ,
unsigned long V_58 , void * V_60 )
{
char * V_62 = F_31 ( V_58 + 1 , V_45 ) ;
struct V_7 * V_8 = (struct V_7 * ) V_60 ;
int V_44 ;
if ( V_62 == NULL )
return - V_46 ;
if ( F_32 ( V_62 , V_11 , V_58 ) ) {
V_44 = - V_63 ;
goto V_64;
}
V_44 = F_27 ( V_8 ) ;
if ( V_44 != 0 )
goto V_64;
if ( V_58 > 0 && V_62 [ V_58 - 1 ] == '\n' )
V_62 [ V_58 - 1 ] = 0 ;
else
V_62 [ V_58 ] = 0 ;
if ( V_62 [ 0 ] )
V_44 = F_21 ( V_8 , V_62 ) ;
if ( V_44 == 0 )
V_44 = V_58 ;
V_64:
F_26 ( V_62 ) ;
return V_44 ;
}
static int T_4 F_33 ( struct V_7 * V_8 , int V_65 ,
struct V_66 * V_67 )
{
char V_62 [ 2 ] = { '0' + V_65 , 0 } ;
V_8 -> V_20 = - 1 ;
V_8 -> V_5 = NULL ;
F_34 ( & V_8 -> V_17 ) ;
V_8 -> V_41 = 0 ;
V_8 -> V_68 = F_35 ( V_45 ) ;
if ( V_8 -> V_68 == NULL ) {
F_9 ( L_11 ) ;
goto V_69;
}
F_36 ( V_8 -> V_68 , F_16 ) ;
V_8 -> V_68 -> V_34 = V_8 ;
V_8 -> V_52 = F_37 ( V_70 ) ;
if ( V_8 -> V_52 == NULL ) {
F_9 ( L_12 ) ;
goto V_71;
}
V_8 -> V_52 -> V_72 = V_73 ;
V_8 -> V_52 -> V_74 = V_65 ;
V_8 -> V_52 -> V_75 = & V_76 ;
V_8 -> V_52 -> V_68 = V_8 -> V_68 ;
V_8 -> V_52 -> V_40 = V_8 ;
snprintf ( V_8 -> V_52 -> V_53 , 32 , L_13 , V_65 ) ;
F_24 ( V_8 -> V_52 , 0 ) ;
F_38 ( V_8 -> V_52 ) ;
V_8 -> V_77 = F_39 ( V_62 , 0644 , V_67 ) ;
V_8 -> V_77 -> V_60 = V_8 ;
V_8 -> V_77 -> V_78 = F_29 ;
V_8 -> V_77 -> V_79 = F_30 ;
return 0 ;
V_71:
F_40 ( V_8 -> V_68 ) ;
V_8 -> V_68 = NULL ;
V_69:
F_28 ( V_8 -> V_20 ) ;
return - V_54 ;
}
static int T_4 F_41 ( void )
{
int V_24 ;
if ( F_42 ( V_73 , L_14 ) < 0 ) {
F_9 ( L_15 , V_73 ) ;
return - V_54 ;
}
F_25 ( L_16 , V_73 ) ;
if ( V_4 > V_80 )
V_80 = V_4 ;
if ( V_80 > V_81 )
V_80 = V_81 ;
V_82 = F_31 ( V_80 * sizeof( struct V_7 ) ,
V_45 ) ;
if ( V_82 == NULL )
goto V_83;
V_84 = F_43 ( L_14 , 0 ) ;
if ( V_84 == NULL )
goto V_85;
for ( V_24 = 0 ; V_24 < V_80 ; ++ V_24 ) {
if ( F_33 ( V_82 + V_24 , V_24 , V_84 ) == 0 ) {
if ( V_5 [ V_24 ] != NULL && V_5 [ V_24 ] [ 0 ] != 0 &&
( V_4 == 0 || V_24 < V_4 ) )
F_21 ( V_82 + V_24 , V_5 [ V_24 ] ) ;
}
}
return 0 ;
V_85:
F_26 ( V_82 ) ;
V_83:
F_44 ( V_73 , L_14 ) ;
return - V_46 ;
}
static void F_45 ( struct V_7 * V_8 , int V_65 ,
struct V_66 * V_67 )
{
char V_62 [ 2 ] = { '0' + V_65 , 0 } ;
F_27 ( V_8 ) ;
if ( V_8 -> V_52 )
F_46 ( V_8 -> V_52 ) ;
if ( V_8 -> V_68 )
F_40 ( V_8 -> V_68 ) ;
F_47 ( V_62 , V_67 ) ;
}
static void T_5 F_48 ( void )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_80 ; ++ V_24 )
F_45 ( V_82 + V_24 , V_24 , V_84 ) ;
F_47 ( L_14 , 0 ) ;
F_26 ( V_82 ) ;
F_44 ( V_73 , L_14 ) ;
}
