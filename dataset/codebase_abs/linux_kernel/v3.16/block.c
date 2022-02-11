static int T_1 F_1 ( const char * V_1 ,
const struct V_2 * V_3 )
{
int V_4 , V_5 ;
T_2 V_6 ;
struct V_7 * V_8 ;
char V_9 [ V_10 ] ;
char * V_11 = & V_9 [ 0 ] ;
char * V_12 [ V_13 ] ;
if ( ! V_1 )
return - V_14 ;
V_6 = F_2 ( V_1 , V_10 ) ;
if ( V_6 == 0 ) {
F_3 ( L_1 ) ;
return 0 ;
}
if ( V_6 == V_10 ) {
F_4 ( L_2 ,
V_1 , V_10 ) ;
return - V_14 ;
}
strcpy ( V_9 , V_1 ) ;
if ( V_9 [ V_6 - 1 ] == '\n' )
V_9 [ V_6 - 1 ] = '\0' ;
for ( V_4 = 0 ; V_4 < V_13 ; V_4 ++ )
V_12 [ V_4 ] = F_5 ( & V_11 , L_3 ) ;
V_8 = & V_7 [ V_15 ] ;
if ( V_12 [ 1 ] ) {
V_5 = F_6 ( V_12 [ 0 ] , 10 , & V_8 -> V_16 ) ;
if ( V_5 < 0 )
return - V_14 ;
V_5 = F_6 ( V_12 [ 1 ] , 10 , & V_8 -> V_17 ) ;
if ( V_5 < 0 ) {
V_8 -> V_17 = - 1 ;
strcpy ( V_8 -> V_18 , V_12 [ 1 ] ) ;
}
} else {
strcpy ( V_8 -> V_18 , V_12 [ 0 ] ) ;
V_8 -> V_16 = - 1 ;
V_8 -> V_17 = - 1 ;
}
V_15 ++ ;
return 0 ;
}
static struct V_19 * F_7 ( int V_16 , int V_17 )
{
struct V_19 * V_20 ;
F_8 (dev, &ubiblock_devices, list)
if ( V_20 -> V_16 == V_16 && V_20 -> V_17 == V_17 )
return V_20 ;
return NULL ;
}
static int F_9 ( struct V_19 * V_20 , char * V_21 ,
int V_22 , int V_23 , int V_6 )
{
int V_5 ;
V_5 = F_10 ( V_20 -> V_24 , V_22 , V_21 , V_23 , V_6 ) ;
if ( V_5 ) {
F_4 ( L_4 ,
V_20 -> V_25 -> V_26 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
static int F_11 ( struct V_19 * V_20 , char * V_21 ,
T_3 V_27 , int V_6 )
{
int V_5 , V_22 , V_23 ;
int V_28 = V_6 ;
int V_29 = V_6 ;
T_4 V_30 = V_27 << 9 ;
V_23 = F_12 ( V_30 , V_20 -> V_31 ) ;
V_22 = V_30 ;
while ( V_28 ) {
if ( V_23 + V_29 > V_20 -> V_31 )
V_29 = V_20 -> V_31 - V_23 ;
V_5 = F_9 ( V_20 , V_21 , V_22 , V_23 , V_29 ) ;
if ( V_5 )
return V_5 ;
V_21 += V_29 ;
V_28 -= V_29 ;
V_29 = V_28 ;
V_22 += 1 ;
V_23 = 0 ;
}
return 0 ;
}
static int F_13 ( struct V_19 * V_20 , struct V_32 * V_33 )
{
int V_6 , V_5 ;
T_3 V_27 ;
if ( V_33 -> V_34 != V_35 )
return - V_36 ;
if ( F_14 ( V_33 ) + F_15 ( V_33 ) >
F_16 ( V_33 -> V_37 ) )
return - V_36 ;
if ( F_17 ( V_33 ) != V_38 )
return - V_39 ;
V_27 = F_14 ( V_33 ) ;
V_6 = F_18 ( V_33 ) ;
F_19 ( & V_20 -> V_40 ) ;
V_5 = F_11 ( V_20 , F_20 ( V_33 -> V_41 ) , V_27 , V_6 ) ;
F_21 ( & V_20 -> V_40 ) ;
return V_5 ;
}
static void F_22 ( struct V_42 * V_43 )
{
struct V_19 * V_20 =
F_23 ( V_43 , struct V_19 , V_43 ) ;
struct V_44 * V_45 = V_20 -> V_45 ;
struct V_32 * V_33 ;
int V_46 ;
F_24 ( V_45 -> V_47 ) ;
V_33 = F_25 ( V_45 ) ;
while ( V_33 ) {
F_26 ( V_45 -> V_47 ) ;
V_46 = F_13 ( V_20 , V_33 ) ;
F_24 ( V_45 -> V_47 ) ;
if ( ! F_27 ( V_33 , V_46 ) )
V_33 = F_25 ( V_45 ) ;
}
F_26 ( V_45 -> V_47 ) ;
}
static void F_28 ( struct V_44 * V_45 )
{
struct V_19 * V_20 ;
struct V_32 * V_33 ;
V_20 = V_45 -> V_48 ;
if ( ! V_20 )
while ( ( V_33 = F_25 ( V_45 ) ) != NULL )
F_29 ( V_33 , - V_49 ) ;
else
F_30 ( V_20 -> V_50 , & V_20 -> V_43 ) ;
}
static int F_31 ( struct V_51 * V_52 , T_5 V_53 )
{
struct V_19 * V_20 = V_52 -> V_54 -> V_55 ;
int V_5 ;
F_19 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_56 > 0 ) {
goto V_57;
}
if ( V_53 & V_58 ) {
V_5 = - V_59 ;
goto V_60;
}
V_20 -> V_24 = F_32 ( V_20 -> V_16 , V_20 -> V_17 , V_61 ) ;
if ( F_33 ( V_20 -> V_24 ) ) {
F_4 ( L_5 ,
V_20 -> V_25 -> V_26 , V_20 -> V_16 , V_20 -> V_17 ) ;
V_5 = F_34 ( V_20 -> V_24 ) ;
V_20 -> V_24 = NULL ;
goto V_60;
}
V_57:
V_20 -> V_56 ++ ;
F_21 ( & V_20 -> V_40 ) ;
return 0 ;
V_60:
F_21 ( & V_20 -> V_40 ) ;
return V_5 ;
}
static void F_35 ( struct V_62 * V_25 , T_5 V_53 )
{
struct V_19 * V_20 = V_25 -> V_55 ;
F_19 ( & V_20 -> V_40 ) ;
V_20 -> V_56 -- ;
if ( V_20 -> V_56 == 0 ) {
F_36 ( V_20 -> V_24 ) ;
V_20 -> V_24 = NULL ;
}
F_21 ( & V_20 -> V_40 ) ;
}
static int F_37 ( struct V_51 * V_52 , struct V_63 * V_64 )
{
V_64 -> V_65 = 1 ;
V_64 -> V_66 = 1 ;
V_64 -> V_67 = F_16 ( V_52 -> V_54 ) ;
V_64 -> V_68 = 0 ;
return 0 ;
}
int F_38 ( struct V_69 * V_70 )
{
struct V_19 * V_20 ;
struct V_62 * V_25 ;
int V_71 ;
int V_5 ;
F_19 ( & V_72 ) ;
if ( F_7 ( V_70 -> V_16 , V_70 -> V_17 ) ) {
F_21 ( & V_72 ) ;
return - V_73 ;
}
F_21 ( & V_72 ) ;
V_20 = F_39 ( sizeof( struct V_19 ) , V_74 ) ;
if ( ! V_20 )
return - V_75 ;
F_40 ( & V_20 -> V_40 ) ;
V_20 -> V_16 = V_70 -> V_16 ;
V_20 -> V_17 = V_70 -> V_17 ;
V_20 -> V_31 = V_70 -> V_76 ;
V_25 = F_41 ( 1 ) ;
if ( ! V_25 ) {
F_4 ( L_6 ) ;
V_5 = - V_49 ;
goto V_77;
}
V_25 -> V_78 = & V_79 ;
V_25 -> V_80 = V_81 ;
V_25 -> V_82 = V_20 -> V_16 * V_83 + V_20 -> V_17 ;
V_25 -> V_55 = V_20 ;
sprintf ( V_25 -> V_26 , L_7 , V_20 -> V_16 , V_20 -> V_17 ) ;
V_71 = ( V_70 -> V_84 * V_70 -> V_76 ) >> 9 ;
F_42 ( V_25 , V_71 ) ;
V_20 -> V_25 = V_25 ;
F_43 ( & V_20 -> V_47 ) ;
V_20 -> V_45 = F_44 ( F_28 , & V_20 -> V_47 ) ;
if ( ! V_20 -> V_45 ) {
F_4 ( L_8 ) ;
V_5 = - V_49 ;
goto V_85;
}
V_20 -> V_45 -> V_48 = V_20 ;
V_20 -> V_25 -> V_86 = V_20 -> V_45 ;
V_20 -> V_50 = F_45 ( L_9 , 0 , 0 , V_25 -> V_26 ) ;
if ( ! V_20 -> V_50 ) {
V_5 = - V_75 ;
goto V_87;
}
F_46 ( & V_20 -> V_43 , F_22 ) ;
F_19 ( & V_72 ) ;
F_47 ( & V_20 -> V_88 , & V_89 ) ;
F_21 ( & V_72 ) ;
F_48 ( V_20 -> V_25 ) ;
F_49 ( L_10 ,
V_20 -> V_25 -> V_26 , V_20 -> V_16 , V_20 -> V_17 , V_70 -> V_18 ) ;
return 0 ;
V_87:
F_50 ( V_20 -> V_45 ) ;
V_85:
F_51 ( V_20 -> V_25 ) ;
V_77:
F_52 ( V_20 ) ;
return V_5 ;
}
static void F_53 ( struct V_19 * V_20 )
{
F_54 ( V_20 -> V_25 ) ;
F_50 ( V_20 -> V_45 ) ;
F_49 ( L_11 , V_20 -> V_25 -> V_26 ) ;
F_51 ( V_20 -> V_25 ) ;
}
int F_55 ( struct V_69 * V_70 )
{
struct V_19 * V_20 ;
F_19 ( & V_72 ) ;
V_20 = F_7 ( V_70 -> V_16 , V_70 -> V_17 ) ;
if ( ! V_20 ) {
F_21 ( & V_72 ) ;
return - V_49 ;
}
F_19 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_56 > 0 ) {
F_21 ( & V_20 -> V_40 ) ;
F_21 ( & V_72 ) ;
return - V_90 ;
}
F_56 ( & V_20 -> V_88 ) ;
F_21 ( & V_72 ) ;
F_57 ( V_20 -> V_50 ) ;
F_53 ( V_20 ) ;
F_21 ( & V_20 -> V_40 ) ;
F_52 ( V_20 ) ;
return 0 ;
}
static void F_58 ( struct V_69 * V_70 )
{
struct V_19 * V_20 ;
int V_71 ;
F_19 ( & V_72 ) ;
V_20 = F_7 ( V_70 -> V_16 , V_70 -> V_17 ) ;
if ( ! V_20 ) {
F_21 ( & V_72 ) ;
return;
}
F_19 ( & V_20 -> V_40 ) ;
V_71 = ( V_70 -> V_84 * V_70 -> V_76 ) >> 9 ;
F_42 ( V_20 -> V_25 , V_71 ) ;
F_49 ( L_12 , V_20 -> V_25 -> V_26 , V_70 -> V_84 ) ;
F_21 ( & V_20 -> V_40 ) ;
F_21 ( & V_72 ) ;
}
static int F_59 ( struct V_91 * V_92 ,
unsigned long V_93 , void * V_94 )
{
struct V_95 * V_96 = V_94 ;
switch ( V_93 ) {
case V_97 :
break;
case V_98 :
F_55 ( & V_96 -> V_70 ) ;
break;
case V_99 :
F_58 ( & V_96 -> V_70 ) ;
break;
default:
break;
}
return V_100 ;
}
static struct V_101 * T_1
F_60 ( const char * V_18 , int V_16 , int V_17 )
{
if ( V_16 == - 1 )
return F_61 ( V_18 , V_61 ) ;
else if ( V_17 == - 1 )
return F_62 ( V_16 , V_18 , V_61 ) ;
else
return F_32 ( V_16 , V_17 , V_61 ) ;
}
static int T_1 F_63 ( void )
{
int V_4 , V_5 ;
struct V_7 * V_102 ;
struct V_101 * V_24 ;
struct V_69 V_70 ;
for ( V_4 = 0 ; V_4 < V_15 ; V_4 ++ ) {
V_102 = & V_7 [ V_4 ] ;
V_24 = F_60 ( V_102 -> V_18 , V_102 -> V_16 , V_102 -> V_17 ) ;
if ( F_33 ( V_24 ) ) {
F_4 ( L_13 ,
F_34 ( V_24 ) ) ;
V_5 = F_34 ( V_24 ) ;
break;
}
F_64 ( V_24 , & V_70 ) ;
F_36 ( V_24 ) ;
V_5 = F_38 ( & V_70 ) ;
if ( V_5 ) {
F_4 ( L_14 ,
V_70 . V_18 , V_5 ) ;
break;
}
}
return V_5 ;
}
static void F_65 ( void )
{
struct V_19 * V_103 ;
struct V_19 * V_20 ;
F_66 (dev, next, &ubiblock_devices, list) {
F_57 ( V_20 -> V_50 ) ;
F_67 ( V_20 -> V_24 ) ;
F_56 ( & V_20 -> V_88 ) ;
F_53 ( V_20 ) ;
F_52 ( V_20 ) ;
}
}
int T_1 F_68 ( void )
{
int V_5 ;
V_81 = F_69 ( 0 , L_15 ) ;
if ( V_81 < 0 )
return V_81 ;
V_5 = F_63 () ;
if ( V_5 )
goto V_104;
V_5 = F_70 ( & V_105 , 1 ) ;
if ( V_5 )
goto V_106;
return 0 ;
V_106:
F_71 ( V_81 , L_15 ) ;
V_104:
F_65 () ;
return V_5 ;
}
void T_6 F_72 ( void )
{
F_73 ( & V_105 ) ;
F_65 () ;
F_71 ( V_81 , L_15 ) ;
}
