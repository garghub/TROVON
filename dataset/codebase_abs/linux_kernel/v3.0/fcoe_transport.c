T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
unsigned char * V_7 ;
unsigned long V_8 , V_9 , V_10 ;
T_1 V_11 ;
unsigned V_12 ;
V_11 = F_3 ( ~ 0 , V_4 -> V_7 , F_4 ( V_4 ) ) ;
for ( V_12 = 0 ; V_12 < F_5 ( V_4 ) -> V_13 ; V_12 ++ ) {
V_6 = & F_5 ( V_4 ) -> V_14 [ V_12 ] ;
V_8 = V_6 -> V_15 ;
V_9 = V_6 -> V_16 ;
while ( V_9 > 0 ) {
V_10 = F_6 ( V_9 , V_17 - ( V_8 & ~ V_18 ) ) ;
V_7 = F_7 ( V_6 -> V_19 + ( V_8 >> V_20 ) ,
V_21 ) ;
V_11 = F_3 ( V_11 , V_7 + ( V_8 & ~ V_18 ) , V_10 ) ;
F_8 ( V_7 , V_21 ) ;
V_8 += V_10 ;
V_9 -= V_10 ;
}
}
return V_11 ;
}
int F_9 ( struct V_3 * V_4 )
{
struct V_3 * V_22 ;
int V_23 ;
V_22 = F_10 ( V_4 , V_24 ) ;
if ( ! V_22 )
return - V_25 ;
V_23 = F_11 ( V_22 ) ;
if ( V_23 != 0 )
return V_23 ;
F_12 ( V_4 ) ;
return 0 ;
}
void F_13 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_3 * V_4 ;
F_15 ( & V_29 -> V_30 . V_31 ) ;
while ( ( V_4 = F_16 ( & V_29 -> V_30 ) ) != NULL ) {
F_17 ( & V_29 -> V_30 . V_31 ) ;
F_12 ( V_4 ) ;
F_15 ( & V_29 -> V_30 . V_31 ) ;
}
F_17 ( & V_29 -> V_30 . V_31 ) ;
}
void F_18 ( struct V_26 * V_27 , struct V_3 * V_4 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
int V_23 ;
F_15 ( & V_29 -> V_30 . V_31 ) ;
if ( V_4 )
F_19 ( & V_29 -> V_30 , V_4 ) ;
if ( V_29 -> V_32 )
goto V_33;
V_29 -> V_32 = 1 ;
while ( V_29 -> V_30 . V_34 ) {
V_29 -> V_30 . V_34 ++ ;
V_4 = F_16 ( & V_29 -> V_30 ) ;
F_17 ( & V_29 -> V_30 . V_31 ) ;
V_23 = F_9 ( V_4 ) ;
F_15 ( & V_29 -> V_30 . V_31 ) ;
if ( V_23 ) {
F_20 ( & V_29 -> V_30 , V_4 ) ;
V_29 -> V_30 . V_34 -- ;
break;
}
V_29 -> V_30 . V_34 -- ;
}
if ( V_29 -> V_30 . V_34 < V_29 -> V_35 )
V_27 -> V_36 = 0 ;
if ( V_29 -> V_30 . V_34 && ! F_21 ( & V_29 -> V_37 ) )
F_22 ( & V_29 -> V_37 , V_38 + 2 ) ;
V_29 -> V_32 = 0 ;
V_33:
if ( V_29 -> V_30 . V_34 > V_29 -> V_39 )
V_27 -> V_36 = 1 ;
F_17 ( & V_29 -> V_30 . V_31 ) ;
}
void F_23 ( T_2 V_27 )
{
F_18 ( (struct V_26 * ) V_27 , NULL ) ;
}
int F_24 ( struct V_3 * V_4 , int V_40 ,
struct V_41 * V_42 )
{
struct V_19 * V_19 ;
V_19 = V_42 -> V_43 ;
if ( ! V_19 ) {
V_19 = F_25 ( V_24 ) ;
if ( ! V_19 )
return - V_25 ;
V_42 -> V_43 = V_19 ;
V_42 -> V_44 = 0 ;
}
F_26 ( V_19 ) ;
F_27 ( V_4 , F_5 ( V_4 ) -> V_13 , V_19 ,
V_42 -> V_44 , V_40 ) ;
V_4 -> V_9 += V_40 ;
V_4 -> V_45 += V_40 ;
V_4 -> V_46 += V_40 ;
V_42 -> V_44 += sizeof( struct V_47 ) ;
if ( V_42 -> V_44 >= V_17 ) {
V_42 -> V_43 = NULL ;
V_42 -> V_44 = 0 ;
F_28 ( V_19 ) ;
}
return 0 ;
}
static struct V_48 * F_29 ( struct V_49 * V_50 )
{
struct V_48 * V_51 = NULL ;
F_30 (ft, &fcoe_transports, list)
if ( V_51 -> V_52 && V_51 -> V_52 ( V_50 ) )
return V_51 ;
return NULL ;
}
int F_31 ( struct V_48 * V_51 )
{
int V_23 = 0 ;
F_32 ( & V_53 ) ;
if ( V_51 -> V_54 ) {
F_33 ( L_1 ,
V_51 -> V_55 ) ;
V_23 = - V_56 ;
goto V_57;
}
if ( strcmp ( V_51 -> V_55 , V_58 ) )
F_34 ( & V_51 -> V_59 , & V_60 ) ;
else
F_35 ( & V_51 -> V_59 , & V_60 ) ;
V_51 -> V_54 = true ;
F_33 ( L_2 , V_51 -> V_55 ) ;
V_57:
F_36 ( & V_53 ) ;
return V_23 ;
}
int F_37 ( struct V_48 * V_51 )
{
int V_23 = 0 ;
struct V_61 * V_62 = NULL , * V_63 ;
F_32 ( & V_53 ) ;
if ( ! V_51 -> V_54 ) {
F_33 ( L_3 ,
V_51 -> V_55 ) ;
V_23 = - V_64 ;
goto V_57;
}
F_32 ( & V_65 ) ;
F_38 (nm, tmp, &fcoe_netdevs, list) {
if ( V_62 -> V_51 == V_51 ) {
F_33 ( L_4
L_5 ,
V_51 -> V_55 , V_62 -> V_50 -> V_55 ) ;
F_39 ( & V_62 -> V_59 ) ;
F_40 ( V_62 ) ;
}
}
F_36 ( & V_65 ) ;
F_39 ( & V_51 -> V_59 ) ;
V_51 -> V_54 = false ;
F_33 ( L_6 , V_51 -> V_55 ) ;
V_57:
F_36 ( & V_53 ) ;
return V_23 ;
}
static int F_41 ( char * V_66 , const struct V_67 * V_68 )
{
int V_12 , V_69 ;
struct V_48 * V_51 = NULL ;
V_12 = V_69 = sprintf ( V_66 , L_7 ) ;
F_32 ( & V_53 ) ;
F_30 (ft, &fcoe_transports, list) {
if ( V_12 >= V_17 - V_70 )
break;
V_12 += snprintf ( & V_66 [ V_12 ] , V_70 , L_8 , V_51 -> V_55 ) ;
}
F_36 ( & V_53 ) ;
if ( V_12 == V_69 )
V_12 += snprintf ( & V_66 [ V_12 ] , V_70 , L_9 ) ;
return V_12 ;
}
static int T_3 F_42 ( void )
{
F_43 ( & V_71 ) ;
return 0 ;
}
static int T_4 F_44 ( void )
{
struct V_48 * V_51 ;
F_45 ( & V_71 ) ;
F_32 ( & V_53 ) ;
F_30 (ft, &fcoe_transports, list)
F_46 ( V_72 L_10 ,
V_51 -> V_55 ) ;
F_36 ( & V_53 ) ;
return 0 ;
}
static int F_47 ( struct V_49 * V_50 ,
struct V_48 * V_51 )
{
struct V_61 * V_62 ;
V_62 = F_48 ( sizeof( * V_62 ) , V_73 ) ;
if ( ! V_62 ) {
F_46 ( V_72 L_11 ) ;
return - V_25 ;
}
V_62 -> V_50 = V_50 ;
V_62 -> V_51 = V_51 ;
F_32 ( & V_65 ) ;
F_34 ( & V_62 -> V_59 , & V_74 ) ;
F_36 ( & V_65 ) ;
return 0 ;
}
static void F_49 ( struct V_49 * V_50 )
{
struct V_61 * V_62 = NULL , * V_63 ;
F_32 ( & V_65 ) ;
F_38 (nm, tmp, &fcoe_netdevs, list) {
if ( V_62 -> V_50 == V_50 ) {
F_39 ( & V_62 -> V_59 ) ;
F_40 ( V_62 ) ;
F_36 ( & V_65 ) ;
return;
}
}
F_36 ( & V_65 ) ;
}
static struct V_48 * F_50 ( struct V_49 * V_50 )
{
struct V_48 * V_51 = NULL ;
struct V_61 * V_62 ;
F_32 ( & V_65 ) ;
F_30 (nm, &fcoe_netdevs, list) {
if ( V_50 == V_62 -> V_50 ) {
V_51 = V_62 -> V_51 ;
F_36 ( & V_65 ) ;
return V_51 ;
}
}
F_36 ( & V_65 ) ;
return NULL ;
}
static struct V_49 * F_51 ( const char * V_66 )
{
char * V_75 ;
char V_76 [ V_70 + 2 ] ;
if ( V_66 ) {
F_52 ( V_76 , V_66 , V_70 ) ;
V_75 = V_76 + strlen ( V_76 ) ;
while ( -- V_75 >= V_76 && * V_75 == '\n' )
* V_75 = '\0' ;
return F_53 ( & V_77 , V_76 ) ;
}
return NULL ;
}
static int F_54 ( struct V_78 * V_79 ,
T_2 V_80 , void * V_81 )
{
struct V_49 * V_50 = V_81 ;
switch ( V_80 ) {
case V_82 :
F_46 ( V_72 L_12 ,
V_50 -> V_55 ) ;
F_49 ( V_50 ) ;
break;
}
return V_83 ;
}
static int F_55 ( const char * V_66 , struct V_67 * V_68 )
{
int V_23 = - V_64 ;
struct V_49 * V_50 = NULL ;
struct V_48 * V_51 = NULL ;
enum V_84 V_85 = (enum V_84 ) ( long ) V_68 -> V_86 ;
F_32 ( & V_53 ) ;
V_50 = F_51 ( V_66 ) ;
if ( ! V_50 ) {
F_33 ( L_13 , V_66 ) ;
goto V_87;
}
V_51 = F_50 ( V_50 ) ;
if ( V_51 ) {
F_33 ( L_14
L_15 ,
V_51 -> V_55 , V_50 -> V_55 ) ;
V_23 = - V_56 ;
goto V_88;
}
V_51 = F_29 ( V_50 ) ;
if ( ! V_51 ) {
F_33 ( L_16 ,
V_50 -> V_55 ) ;
goto V_88;
}
V_23 = F_47 ( V_50 , V_51 ) ;
if ( V_23 ) {
F_33 ( L_17
L_18 ,
V_51 -> V_55 , V_50 -> V_55 ) ;
goto V_88;
}
V_23 = V_51 -> V_89 ? V_51 -> V_89 ( V_50 , V_85 ) : - V_64 ;
if ( V_23 )
F_49 ( V_50 ) ;
F_33 ( L_19 ,
V_51 -> V_55 , ( V_23 ) ? L_20 : L_21 ,
V_50 -> V_55 ) ;
V_88:
F_56 ( V_50 ) ;
V_87:
F_36 ( & V_53 ) ;
return V_23 ;
}
static int F_57 ( const char * V_66 , struct V_67 * V_68 )
{
int V_23 = - V_64 ;
struct V_49 * V_50 = NULL ;
struct V_48 * V_51 = NULL ;
F_32 ( & V_53 ) ;
V_50 = F_51 ( V_66 ) ;
if ( ! V_50 ) {
F_33 ( L_22 , V_66 ) ;
goto V_87;
}
V_51 = F_50 ( V_50 ) ;
if ( ! V_51 ) {
F_33 ( L_16 ,
V_50 -> V_55 ) ;
goto V_88;
}
V_23 = V_51 -> V_90 ? V_51 -> V_90 ( V_50 ) : - V_64 ;
F_49 ( V_50 ) ;
F_33 ( L_23 ,
V_51 -> V_55 , ( V_23 ) ? L_20 : L_21 ,
V_50 -> V_55 ) ;
V_88:
F_56 ( V_50 ) ;
V_87:
F_36 ( & V_53 ) ;
return V_23 ;
}
static int F_58 ( const char * V_66 , struct V_67 * V_68 )
{
int V_23 = - V_64 ;
struct V_49 * V_50 = NULL ;
struct V_48 * V_51 = NULL ;
F_32 ( & V_53 ) ;
V_50 = F_51 ( V_66 ) ;
if ( ! V_50 )
goto V_87;
V_51 = F_50 ( V_50 ) ;
if ( ! V_51 )
goto V_88;
V_23 = V_51 -> V_91 ? V_51 -> V_91 ( V_50 ) : - V_64 ;
V_88:
F_56 ( V_50 ) ;
V_87:
F_36 ( & V_53 ) ;
if ( V_23 == - V_92 )
return F_59 () ;
else
return V_23 ;
}
static int F_60 ( const char * V_66 , struct V_67 * V_68 )
{
int V_23 = - V_64 ;
struct V_49 * V_50 = NULL ;
struct V_48 * V_51 = NULL ;
F_32 ( & V_53 ) ;
V_50 = F_51 ( V_66 ) ;
if ( ! V_50 )
goto V_87;
V_51 = F_50 ( V_50 ) ;
if ( ! V_51 )
goto V_88;
V_23 = V_51 -> V_93 ? V_51 -> V_93 ( V_50 ) : - V_64 ;
V_88:
F_56 ( V_50 ) ;
V_87:
F_36 ( & V_53 ) ;
return V_23 ;
}
static int T_3 F_61 ( void )
{
F_42 () ;
return 0 ;
}
static void T_4 F_62 ( void )
{
F_44 () ;
}
