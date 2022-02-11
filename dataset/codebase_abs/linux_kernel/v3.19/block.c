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
F_11 ( F_12 ( V_20 -> V_25 ) , L_4 ,
V_5 , V_22 , V_23 , V_6 ) ;
return V_5 ;
}
return 0 ;
}
static int F_13 ( struct V_19 * V_20 , char * V_21 ,
T_3 V_26 , int V_6 )
{
int V_5 , V_22 , V_23 ;
int V_27 = V_6 ;
int V_28 = V_6 ;
T_4 V_29 = V_26 << 9 ;
V_23 = F_14 ( V_29 , V_20 -> V_30 ) ;
V_22 = V_29 ;
while ( V_27 ) {
if ( V_23 + V_28 > V_20 -> V_30 )
V_28 = V_20 -> V_30 - V_23 ;
V_5 = F_9 ( V_20 , V_21 , V_22 , V_23 , V_28 ) ;
if ( V_5 )
return V_5 ;
V_21 += V_28 ;
V_27 -= V_28 ;
V_28 = V_27 ;
V_22 += 1 ;
V_23 = 0 ;
}
return 0 ;
}
static int F_15 ( struct V_19 * V_20 , struct V_31 * V_32 )
{
int V_6 , V_5 ;
T_3 V_26 ;
if ( V_32 -> V_33 != V_34 )
return - V_35 ;
if ( F_16 ( V_32 ) + F_17 ( V_32 ) >
F_18 ( V_32 -> V_36 ) )
return - V_35 ;
if ( F_19 ( V_32 ) != V_37 )
return - V_38 ;
V_26 = F_16 ( V_32 ) ;
V_6 = F_20 ( V_32 ) ;
F_21 ( & V_20 -> V_39 ) ;
V_5 = F_13 ( V_20 , F_22 ( V_32 -> V_40 ) , V_26 , V_6 ) ;
F_23 ( & V_20 -> V_39 ) ;
return V_5 ;
}
static void F_24 ( struct V_41 * V_42 )
{
struct V_19 * V_20 =
F_25 ( V_42 , struct V_19 , V_42 ) ;
struct V_43 * V_44 = V_20 -> V_44 ;
struct V_31 * V_32 ;
int V_45 ;
F_26 ( V_44 -> V_46 ) ;
V_32 = F_27 ( V_44 ) ;
while ( V_32 ) {
F_28 ( V_44 -> V_46 ) ;
V_45 = F_15 ( V_20 , V_32 ) ;
F_26 ( V_44 -> V_46 ) ;
if ( ! F_29 ( V_32 , V_45 ) )
V_32 = F_27 ( V_44 ) ;
}
F_28 ( V_44 -> V_46 ) ;
}
static void F_30 ( struct V_43 * V_44 )
{
struct V_19 * V_20 ;
struct V_31 * V_32 ;
V_20 = V_44 -> V_47 ;
if ( ! V_20 )
while ( ( V_32 = F_27 ( V_44 ) ) != NULL )
F_31 ( V_32 , - V_48 ) ;
else
F_32 ( V_20 -> V_49 , & V_20 -> V_42 ) ;
}
static int F_33 ( struct V_50 * V_51 , T_5 V_52 )
{
struct V_19 * V_20 = V_51 -> V_53 -> V_54 ;
int V_5 ;
F_21 ( & V_20 -> V_39 ) ;
if ( V_20 -> V_55 > 0 ) {
goto V_56;
}
if ( V_52 & V_57 ) {
V_5 = - V_58 ;
goto V_59;
}
V_20 -> V_24 = F_34 ( V_20 -> V_16 , V_20 -> V_17 , V_60 ) ;
if ( F_35 ( V_20 -> V_24 ) ) {
F_11 ( F_12 ( V_20 -> V_25 ) , L_5 ,
V_20 -> V_16 , V_20 -> V_17 ) ;
V_5 = F_36 ( V_20 -> V_24 ) ;
V_20 -> V_24 = NULL ;
goto V_59;
}
V_56:
V_20 -> V_55 ++ ;
F_23 ( & V_20 -> V_39 ) ;
return 0 ;
V_59:
F_23 ( & V_20 -> V_39 ) ;
return V_5 ;
}
static void F_37 ( struct V_61 * V_25 , T_5 V_52 )
{
struct V_19 * V_20 = V_25 -> V_54 ;
F_21 ( & V_20 -> V_39 ) ;
V_20 -> V_55 -- ;
if ( V_20 -> V_55 == 0 ) {
F_38 ( V_20 -> V_24 ) ;
V_20 -> V_24 = NULL ;
}
F_23 ( & V_20 -> V_39 ) ;
}
static int F_39 ( struct V_50 * V_51 , struct V_62 * V_63 )
{
V_63 -> V_64 = 1 ;
V_63 -> V_65 = 1 ;
V_63 -> V_66 = F_18 ( V_51 -> V_53 ) ;
V_63 -> V_67 = 0 ;
return 0 ;
}
int F_40 ( struct V_68 * V_69 )
{
struct V_19 * V_20 ;
struct V_61 * V_25 ;
T_4 V_70 = V_69 -> V_71 >> 9 ;
int V_5 ;
if ( ( T_3 ) V_70 != V_70 )
return - V_72 ;
F_21 ( & V_73 ) ;
if ( F_7 ( V_69 -> V_16 , V_69 -> V_17 ) ) {
F_23 ( & V_73 ) ;
return - V_74 ;
}
F_23 ( & V_73 ) ;
V_20 = F_41 ( sizeof( struct V_19 ) , V_75 ) ;
if ( ! V_20 )
return - V_76 ;
F_42 ( & V_20 -> V_39 ) ;
V_20 -> V_16 = V_69 -> V_16 ;
V_20 -> V_17 = V_69 -> V_17 ;
V_20 -> V_30 = V_69 -> V_77 ;
V_25 = F_43 ( 1 ) ;
if ( ! V_25 ) {
F_4 ( L_6 ) ;
V_5 = - V_48 ;
goto V_78;
}
V_25 -> V_79 = & V_80 ;
V_25 -> V_81 = V_82 ;
V_25 -> V_83 = V_20 -> V_16 * V_84 + V_20 -> V_17 ;
V_25 -> V_54 = V_20 ;
sprintf ( V_25 -> V_85 , L_7 , V_20 -> V_16 , V_20 -> V_17 ) ;
F_44 ( V_25 , V_70 ) ;
V_20 -> V_25 = V_25 ;
F_45 ( & V_20 -> V_46 ) ;
V_20 -> V_44 = F_46 ( F_30 , & V_20 -> V_46 ) ;
if ( ! V_20 -> V_44 ) {
F_11 ( F_12 ( V_25 ) , L_8 ) ;
V_5 = - V_48 ;
goto V_86;
}
V_20 -> V_44 -> V_47 = V_20 ;
V_20 -> V_25 -> V_87 = V_20 -> V_44 ;
V_20 -> V_49 = F_47 ( L_9 , 0 , 0 , V_25 -> V_85 ) ;
if ( ! V_20 -> V_49 ) {
V_5 = - V_76 ;
goto V_88;
}
F_48 ( & V_20 -> V_42 , F_24 ) ;
F_21 ( & V_73 ) ;
F_49 ( & V_20 -> V_89 , & V_90 ) ;
F_23 ( & V_73 ) ;
F_50 ( V_20 -> V_25 ) ;
F_51 ( F_12 ( V_20 -> V_25 ) , L_10 ,
V_20 -> V_16 , V_20 -> V_17 , V_69 -> V_18 ) ;
return 0 ;
V_88:
F_52 ( V_20 -> V_44 ) ;
V_86:
F_53 ( V_20 -> V_25 ) ;
V_78:
F_54 ( V_20 ) ;
return V_5 ;
}
static void F_55 ( struct V_19 * V_20 )
{
F_56 ( V_20 -> V_25 ) ;
F_52 ( V_20 -> V_44 ) ;
F_51 ( F_12 ( V_20 -> V_25 ) , L_11 ) ;
F_53 ( V_20 -> V_25 ) ;
}
int F_57 ( struct V_68 * V_69 )
{
struct V_19 * V_20 ;
F_21 ( & V_73 ) ;
V_20 = F_7 ( V_69 -> V_16 , V_69 -> V_17 ) ;
if ( ! V_20 ) {
F_23 ( & V_73 ) ;
return - V_48 ;
}
F_21 ( & V_20 -> V_39 ) ;
if ( V_20 -> V_55 > 0 ) {
F_23 ( & V_20 -> V_39 ) ;
F_23 ( & V_73 ) ;
return - V_91 ;
}
F_58 ( & V_20 -> V_89 ) ;
F_23 ( & V_73 ) ;
F_59 ( V_20 -> V_49 ) ;
F_55 ( V_20 ) ;
F_23 ( & V_20 -> V_39 ) ;
F_54 ( V_20 ) ;
return 0 ;
}
static int F_60 ( struct V_68 * V_69 )
{
struct V_19 * V_20 ;
T_4 V_70 = V_69 -> V_71 >> 9 ;
F_21 ( & V_73 ) ;
V_20 = F_7 ( V_69 -> V_16 , V_69 -> V_17 ) ;
if ( ! V_20 ) {
F_23 ( & V_73 ) ;
return - V_48 ;
}
if ( ( T_3 ) V_70 != V_70 ) {
F_23 ( & V_73 ) ;
F_61 ( F_12 ( V_20 -> V_25 ) , L_12 ,
V_69 -> V_92 ) ;
return - V_72 ;
}
F_21 ( & V_20 -> V_39 ) ;
if ( F_18 ( V_20 -> V_25 ) != V_70 ) {
F_44 ( V_20 -> V_25 , V_70 ) ;
F_51 ( F_12 ( V_20 -> V_25 ) , L_13 ,
V_69 -> V_71 ) ;
}
F_23 ( & V_20 -> V_39 ) ;
F_23 ( & V_73 ) ;
return 0 ;
}
static int F_62 ( struct V_93 * V_94 ,
unsigned long V_95 , void * V_96 )
{
struct V_97 * V_98 = V_96 ;
switch ( V_95 ) {
case V_99 :
break;
case V_100 :
F_57 ( & V_98 -> V_69 ) ;
break;
case V_101 :
F_60 ( & V_98 -> V_69 ) ;
break;
case V_102 :
if ( V_98 -> V_69 . V_103 == V_104 )
F_60 ( & V_98 -> V_69 ) ;
break;
default:
break;
}
return V_105 ;
}
static struct V_106 * T_1
F_63 ( const char * V_18 , int V_16 , int V_17 )
{
if ( V_16 == - 1 )
return F_64 ( V_18 , V_60 ) ;
else if ( V_17 == - 1 )
return F_65 ( V_16 , V_18 , V_60 ) ;
else
return F_34 ( V_16 , V_17 , V_60 ) ;
}
static int T_1 F_66 ( void )
{
int V_4 , V_5 ;
struct V_7 * V_107 ;
struct V_106 * V_24 ;
struct V_68 V_69 ;
for ( V_4 = 0 ; V_4 < V_15 ; V_4 ++ ) {
V_107 = & V_7 [ V_4 ] ;
V_24 = F_63 ( V_107 -> V_18 , V_107 -> V_16 , V_107 -> V_17 ) ;
if ( F_35 ( V_24 ) ) {
F_4 ( L_14 ,
F_36 ( V_24 ) ) ;
V_5 = F_36 ( V_24 ) ;
break;
}
F_67 ( V_24 , & V_69 ) ;
F_38 ( V_24 ) ;
V_5 = F_40 ( & V_69 ) ;
if ( V_5 ) {
F_4 ( L_15 ,
V_69 . V_18 , V_5 ) ;
break;
}
}
return V_5 ;
}
static void F_68 ( void )
{
struct V_19 * V_108 ;
struct V_19 * V_20 ;
F_69 (dev, next, &ubiblock_devices, list) {
F_59 ( V_20 -> V_49 ) ;
F_70 ( V_20 -> V_24 ) ;
F_58 ( & V_20 -> V_89 ) ;
F_55 ( V_20 ) ;
F_54 ( V_20 ) ;
}
}
int T_1 F_71 ( void )
{
int V_5 ;
V_82 = F_72 ( 0 , L_16 ) ;
if ( V_82 < 0 )
return V_82 ;
V_5 = F_66 () ;
if ( V_5 )
goto V_109;
V_5 = F_73 ( & V_110 , 1 ) ;
if ( V_5 )
goto V_111;
return 0 ;
V_111:
F_74 ( V_82 , L_16 ) ;
V_109:
F_68 () ;
return V_5 ;
}
void T_6 F_75 ( void )
{
F_76 ( & V_110 ) ;
F_68 () ;
F_74 ( V_82 , L_16 ) ;
}
