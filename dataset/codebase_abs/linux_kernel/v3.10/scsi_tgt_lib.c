struct V_1 * F_1 ( struct V_2 * V_3 ,
enum V_4 V_5 ,
T_1 V_6 )
{
int V_7 = ( V_5 == V_8 ) ;
struct V_9 * V_10 ;
struct V_1 * V_11 ;
struct V_12 * V_13 ;
if ( ! F_2 ( & V_3 -> V_14 ) )
return NULL ;
V_13 = F_3 ( V_15 , V_16 ) ;
if ( ! V_13 )
goto V_17;
V_10 = F_4 ( V_3 -> V_18 , ! V_7 , V_6 ) ;
if ( ! V_10 )
goto V_19;
V_11 = F_5 ( V_3 , V_6 ) ;
if ( ! V_11 )
goto V_20;
V_11 -> V_21 = V_5 ;
V_11 -> V_22 = V_23 ;
V_11 -> V_9 = V_10 ;
V_11 -> V_24 = V_10 -> V_11 ;
V_10 -> V_25 = V_11 ;
V_10 -> V_26 = V_27 ;
V_10 -> V_28 |= V_29 ;
V_10 -> V_30 = V_13 ;
V_13 -> V_10 = V_10 ;
return V_11 ;
V_20:
F_6 ( V_10 ) ;
V_19:
F_7 ( V_15 , V_13 ) ;
V_17:
F_8 ( & V_3 -> V_14 ) ;
return NULL ;
}
void F_9 ( struct V_2 * V_3 , struct V_1 * V_11 )
{
struct V_31 * V_32 = V_3 -> V_18 ;
struct V_9 * V_10 = V_11 -> V_9 ;
struct V_12 * V_13 = V_10 -> V_30 ;
unsigned long V_33 ;
F_7 ( V_15 , V_13 ) ;
F_10 ( V_32 -> V_34 , V_33 ) ;
F_11 ( V_32 , V_10 ) ;
F_12 ( V_32 -> V_34 , V_33 ) ;
F_13 ( V_3 , V_11 , & V_3 -> V_14 ) ;
}
static void F_14 ( struct V_1 * V_11 )
{
struct V_31 * V_32 = V_11 -> V_9 -> V_32 ;
struct V_35 * V_36 = V_32 -> V_37 ;
unsigned long V_33 ;
struct V_12 * V_13 = V_11 -> V_9 -> V_30 ;
F_10 ( & V_36 -> V_38 , V_33 ) ;
F_15 ( & V_13 -> V_39 ) ;
F_12 ( & V_36 -> V_38 , V_33 ) ;
}
static void F_16 ( struct V_12 * V_13 )
{
F_17 ( V_13 -> V_40 ) ;
}
static void F_18 ( struct V_41 * V_42 )
{
struct V_12 * V_13 =
F_19 ( V_42 , struct V_12 , V_42 ) ;
struct V_1 * V_11 = V_13 -> V_10 -> V_25 ;
F_20 ( L_1 , V_11 , V_11 -> V_21 ,
F_21 ( V_11 -> V_9 ) ) ;
F_16 ( V_13 ) ;
V_13 -> V_10 -> V_40 = NULL ;
F_9 ( F_22 ( V_11 ) , V_11 ) ;
}
static void F_23 ( struct V_9 * V_10 , struct V_12 * V_13 ,
T_2 V_43 , T_2 V_44 )
{
struct V_35 * V_36 = V_10 -> V_32 -> V_37 ;
unsigned long V_33 ;
struct V_45 * V_46 ;
V_13 -> V_43 = V_43 ;
V_13 -> V_44 = V_44 ;
V_13 -> V_40 = NULL ;
F_24 ( & V_13 -> V_42 , F_18 ) ;
F_10 ( & V_36 -> V_38 , V_33 ) ;
V_46 = & V_36 -> V_47 [ F_25 ( V_44 ) ] ;
F_26 ( & V_13 -> V_39 , V_46 ) ;
F_12 ( & V_36 -> V_38 , V_33 ) ;
}
int F_27 ( struct V_2 * V_3 )
{
struct V_35 * V_37 ;
struct V_31 * V_32 ;
int V_48 , V_49 ;
V_32 = F_28 ( V_3 , NULL ) ;
if ( ! V_32 )
return - V_50 ;
V_37 = F_29 ( sizeof( * V_37 ) , V_51 ) ;
if ( ! V_37 ) {
V_48 = - V_50 ;
goto V_52;
}
V_37 -> V_3 = V_3 ;
V_32 -> V_37 = V_37 ;
V_32 -> V_53 = V_3 -> V_54 ;
F_30 ( V_32 , 0 ) ;
V_3 -> V_18 = V_32 ;
for ( V_49 = 0 ; V_49 < F_31 ( V_37 -> V_47 ) ; V_49 ++ )
F_32 ( & V_37 -> V_47 [ V_49 ] ) ;
F_33 ( & V_37 -> V_38 ) ;
return 0 ;
V_52:
F_34 ( V_32 ) ;
return V_48 ;
}
void F_35 ( struct V_2 * V_3 )
{
int V_49 ;
unsigned long V_33 ;
struct V_31 * V_32 = V_3 -> V_18 ;
struct V_1 * V_11 ;
struct V_35 * V_36 = V_32 -> V_37 ;
struct V_12 * V_13 , * V_55 ;
F_36 ( V_56 ) ;
F_10 ( & V_36 -> V_38 , V_33 ) ;
for ( V_49 = 0 ; V_49 < F_31 ( V_36 -> V_47 ) ; V_49 ++ ) {
F_37 (tcmd, n, &qdata->cmd_hash[i],
hash_list)
F_38 ( & V_13 -> V_39 , & V_56 ) ;
}
F_12 ( & V_36 -> V_38 , V_33 ) ;
while ( ! F_39 ( & V_56 ) ) {
V_13 = F_40 ( V_56 . V_57 , struct V_12 , V_39 ) ;
F_15 ( & V_13 -> V_39 ) ;
V_11 = V_13 -> V_10 -> V_25 ;
V_3 -> V_58 -> V_59 ( V_11 ) ;
F_18 ( & V_13 -> V_42 ) ;
}
}
struct V_2 * F_22 ( struct V_1 * V_11 )
{
struct V_35 * V_60 = V_11 -> V_9 -> V_32 -> V_37 ;
return V_60 -> V_3 ;
}
int F_41 ( struct V_1 * V_11 , T_2 V_43 ,
struct V_61 * V_62 , T_2 V_44 )
{
struct V_12 * V_13 = V_11 -> V_9 -> V_30 ;
int V_48 ;
F_23 ( V_11 -> V_9 , V_13 , V_43 , V_44 ) ;
V_48 = F_42 ( V_11 , V_43 , V_62 , V_44 ) ;
if ( V_48 )
F_14 ( V_11 ) ;
return V_48 ;
}
static void F_43 ( struct V_1 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_9 -> V_30 ;
F_20 ( L_2 , V_11 , F_21 ( V_11 -> V_9 ) ) ;
F_44 ( V_11 , V_13 -> V_43 , V_13 -> V_44 ) ;
F_45 ( V_11 ) ;
F_46 ( V_63 , & V_13 -> V_42 ) ;
}
static int F_47 ( struct V_1 * V_11 )
{
struct V_2 * V_3 = F_22 ( V_11 ) ;
int V_48 ;
F_20 ( L_2 , V_11 , F_21 ( V_11 -> V_9 ) ) ;
V_48 = V_3 -> V_58 -> V_64 ( V_11 , F_43 ) ;
switch ( V_48 ) {
case V_65 :
case V_66 :
return - V_67 ;
}
return 0 ;
}
static int F_48 ( struct V_12 * V_13 , struct V_1 * V_11 ,
unsigned long V_68 , unsigned int V_69 , int V_70 )
{
struct V_31 * V_32 = V_11 -> V_9 -> V_32 ;
struct V_9 * V_10 = V_11 -> V_9 ;
int V_48 ;
F_20 ( L_3 , V_68 , V_69 ) ;
V_48 = F_49 ( V_32 , V_10 , NULL , ( void * ) V_68 , V_69 , V_51 ) ;
if ( V_48 ) {
F_50 ( L_4 , V_69 ) ;
return V_48 ;
}
V_13 -> V_40 = V_10 -> V_40 ;
V_48 = F_51 ( V_11 , V_51 ) ;
if ( V_48 ) {
F_45 ( V_11 ) ;
goto V_71;
}
V_11 -> V_72 . V_73 = F_52 ( V_10 ) ;
return 0 ;
V_71:
F_16 ( V_13 ) ;
return V_48 ;
}
static int F_53 ( struct V_1 * V_11 , unsigned long V_68 ,
unsigned V_69 )
{
char T_3 * V_74 = ( char T_3 * ) V_68 ;
if ( F_54 ( V_11 -> V_75 , V_74 ,
F_55 ( unsigned , V_76 , V_69 ) ) ) {
F_56 ( V_77 L_5 ) ;
return - V_78 ;
}
return 0 ;
}
static int F_57 ( struct V_2 * V_3 , struct V_1 * V_11 )
{
struct V_12 * V_13 ;
int V_48 ;
V_48 = V_3 -> V_58 -> V_59 ( V_11 ) ;
if ( V_48 )
F_50 ( L_6 , V_11 ) ;
V_13 = V_11 -> V_9 -> V_30 ;
F_18 ( & V_13 -> V_42 ) ;
return V_48 ;
}
static struct V_9 * F_58 ( struct V_31 * V_32 , T_2 V_44 )
{
struct V_35 * V_36 = V_32 -> V_37 ;
struct V_9 * V_10 = NULL ;
struct V_45 * V_46 ;
struct V_12 * V_13 ;
unsigned long V_33 ;
V_46 = & V_36 -> V_47 [ F_25 ( V_44 ) ] ;
F_10 ( & V_36 -> V_38 , V_33 ) ;
F_59 (tcmd, head, hash_list) {
if ( V_13 -> V_44 == V_44 ) {
V_10 = V_13 -> V_10 ;
F_15 ( & V_13 -> V_39 ) ;
break;
}
}
F_12 ( & V_36 -> V_38 , V_33 ) ;
return V_10 ;
}
int F_60 ( int V_79 , T_2 V_43 , int V_80 , T_2 V_44 ,
unsigned long V_68 , T_4 V_69 , unsigned long V_81 ,
T_4 V_82 , T_5 V_70 )
{
struct V_2 * V_3 ;
struct V_1 * V_11 ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
int V_48 = 0 ;
F_20 ( L_7 , V_79 , ( unsigned long long ) V_44 ,
V_80 , V_69 , V_68 , V_70 ) ;
V_3 = F_61 ( V_79 ) ;
if ( ! V_3 ) {
F_56 ( V_77 L_8 , V_79 ) ;
return - V_83 ;
}
if ( ! V_3 -> V_18 ) {
F_56 ( V_77 L_9 , V_79 ) ;
goto V_84;
}
V_10 = F_58 ( V_3 -> V_18 , V_44 ) ;
if ( ! V_10 ) {
F_56 ( V_77 L_10 ,
( unsigned long long ) V_44 ) ;
V_48 = - V_83 ;
goto V_84;
}
V_11 = V_10 -> V_25 ;
F_20 ( L_11 ,
V_11 , V_11 -> V_24 [ 0 ] , V_80 , V_69 , F_62 ( V_11 ) ,
F_21 ( V_10 ) , V_11 -> V_24 [ 0 ] ) ;
if ( V_80 == V_85 ) {
F_57 ( V_3 , V_11 ) ;
goto V_84;
}
V_13 = V_11 -> V_9 -> V_30 ;
V_11 -> V_80 = V_80 ;
if ( V_11 -> V_80 == V_86 )
F_53 ( V_11 , V_81 , V_82 ) ;
if ( V_69 ) {
V_48 = F_48 ( V_10 -> V_30 , V_11 , V_68 , V_69 , V_70 ) ;
if ( V_48 ) {
struct V_35 * V_36 ;
struct V_45 * V_46 ;
unsigned long V_33 ;
F_50 ( L_12 ,
V_11 , V_48 , V_68 , V_69 , V_70 ) ;
V_36 = V_3 -> V_18 -> V_37 ;
V_46 = & V_36 -> V_47 [ F_25 ( V_13 -> V_44 ) ] ;
F_10 ( & V_36 -> V_38 , V_33 ) ;
F_26 ( & V_13 -> V_39 , V_46 ) ;
F_12 ( & V_36 -> V_38 , V_33 ) ;
goto V_84;
}
}
V_48 = F_47 ( V_11 ) ;
V_84:
F_63 ( V_3 ) ;
return V_48 ;
}
int F_64 ( struct V_2 * V_3 , T_2 V_43 ,
int V_87 , T_2 V_44 , struct V_61 * V_62 ,
void * V_88 )
{
int V_48 ;
V_48 = F_65 ( V_3 -> V_79 , V_43 ,
V_87 , V_44 , V_62 , V_88 ) ;
if ( V_48 < 0 )
F_50 ( L_13 ) ;
return V_48 ;
}
int F_66 ( int V_79 , T_2 V_43 , T_2 V_89 , int V_80 )
{
struct V_2 * V_3 ;
int V_48 = - V_83 ;
F_20 ( L_14 , V_79 , V_80 , ( unsigned long long ) V_89 ) ;
V_3 = F_61 ( V_79 ) ;
if ( ! V_3 ) {
F_56 ( V_77 L_8 , V_79 ) ;
return V_48 ;
}
if ( ! V_3 -> V_18 ) {
F_56 ( V_77 L_9 , V_79 ) ;
goto V_84;
}
V_48 = V_3 -> V_90 -> V_91 ( V_3 , V_43 , V_89 , V_80 ) ;
V_84:
F_63 ( V_3 ) ;
return V_48 ;
}
int F_67 ( struct V_2 * V_3 , T_2 V_43 ,
char * V_92 )
{
int V_48 ;
V_48 = F_68 ( V_3 -> V_79 , V_43 , 0 ,
V_92 ) ;
if ( V_48 < 0 )
F_50 ( L_15 ,
V_3 -> V_79 , ( unsigned long long ) V_43 ) ;
return V_48 ;
}
int F_69 ( struct V_2 * V_3 , T_2 V_43 )
{
int V_48 ;
V_48 = F_68 ( V_3 -> V_79 ,
V_43 , 1 , NULL ) ;
if ( V_48 < 0 )
F_50 ( L_15 ,
V_3 -> V_79 , ( unsigned long long ) V_43 ) ;
return V_48 ;
}
int F_70 ( int V_79 , T_2 V_43 , int V_80 )
{
struct V_2 * V_3 ;
int V_48 = - V_83 ;
F_20 ( L_16 , V_79 , V_80 , ( unsigned long long ) V_43 ) ;
V_3 = F_61 ( V_79 ) ;
if ( ! V_3 ) {
F_56 ( V_77 L_8 , V_79 ) ;
return V_48 ;
}
if ( ! V_3 -> V_18 ) {
F_56 ( V_77 L_9 , V_79 ) ;
goto V_84;
}
V_48 = V_3 -> V_90 -> V_93 ( V_3 , V_43 , V_80 ) ;
V_84:
F_63 ( V_3 ) ;
return V_48 ;
}
static int T_6 F_71 ( void )
{
int V_48 ;
V_15 = F_72 ( V_12 , 0 ) ;
if ( ! V_15 )
return - V_50 ;
V_63 = F_73 ( L_17 , 0 , 1 ) ;
if ( ! V_63 ) {
V_48 = - V_50 ;
goto V_94;
}
V_48 = F_74 () ;
if ( V_48 )
goto V_95;
return 0 ;
V_95:
F_75 ( V_63 ) ;
V_94:
F_76 ( V_15 ) ;
return V_48 ;
}
static void T_7 F_77 ( void )
{
F_75 ( V_63 ) ;
F_78 () ;
F_76 ( V_15 ) ;
}
