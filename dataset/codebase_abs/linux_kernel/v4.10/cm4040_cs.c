static inline void F_1 ( unsigned char V_1 , unsigned short V_2 )
{
F_2 ( L_1 , V_1 , V_2 ) ;
F_3 ( V_1 , V_2 ) ;
}
static inline unsigned char F_4 ( unsigned short V_2 )
{
unsigned char V_1 ;
V_1 = F_5 ( V_2 ) ;
F_2 ( L_2 , V_1 , V_2 ) ;
return V_1 ;
}
static void F_6 ( unsigned long V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 ;
unsigned int V_6 = F_4 ( V_5 -> V_7 -> V_8 [ 0 ] -> V_9
+ V_10 ) ;
if ( ( V_6 & V_11 ) ) {
F_7 ( V_12 , & V_5 -> V_13 ) ;
F_8 ( 4 , V_5 , L_3 ) ;
F_9 ( & V_5 -> V_14 ) ;
} else
F_10 ( V_12 , & V_5 -> V_13 ) ;
if ( ! ( V_6 & V_15 ) ) {
F_7 ( V_16 , & V_5 -> V_13 ) ;
F_8 ( 4 , V_5 , L_4 ) ;
F_9 ( & V_5 -> V_17 ) ;
} else
F_10 ( V_16 , & V_5 -> V_13 ) ;
if ( V_5 -> V_13 )
F_9 ( & V_5 -> V_18 ) ;
F_11 ( & V_5 -> V_19 , V_20 + V_21 ) ;
}
static void F_12 ( struct V_4 * V_5 )
{
F_13 ( & V_5 -> V_19 ) ;
}
static int F_14 ( struct V_4 * V_5 )
{
int V_22 , V_23 ;
int V_24 = V_5 -> V_7 -> V_8 [ 0 ] -> V_9 ;
for ( V_22 = 0 ; V_22 < V_25 ; V_22 ++ ) {
if ( ( F_4 ( V_24 + V_10 )
& V_15 ) == 0 ) {
F_8 ( 4 , V_5 , L_5 , V_22 ) ;
return 1 ;
}
}
F_8 ( 4 , V_5 , L_6 ,
V_5 -> V_26 ) ;
V_23 = F_15 ( V_5 -> V_17 ,
F_16 ( V_16 ,
& V_5 -> V_13 ) ,
V_5 -> V_26 ) ;
if ( V_23 > 0 )
F_8 ( 4 , V_5 , L_7 ) ;
else if ( V_23 == 0 )
F_8 ( 4 , V_5 , L_8 ) ;
else if ( V_23 < 0 )
F_8 ( 4 , V_5 , L_9 ) ;
return V_23 ;
}
static int F_17 ( unsigned char V_1 , struct V_4 * V_5 )
{
int V_24 = V_5 -> V_7 -> V_8 [ 0 ] -> V_9 ;
int V_23 ;
V_23 = F_14 ( V_5 ) ;
if ( V_23 <= 0 )
return V_23 ;
F_1 ( V_1 , V_24 + V_27 ) ;
V_23 = F_14 ( V_5 ) ;
if ( V_23 <= 0 )
return V_23 ;
return 1 ;
}
static int F_18 ( struct V_4 * V_5 )
{
int V_22 , V_23 ;
int V_24 = V_5 -> V_7 -> V_8 [ 0 ] -> V_9 ;
for ( V_22 = 0 ; V_22 < V_25 ; V_22 ++ ) {
if ( ( F_4 ( V_24 + V_10 )
& V_11 ) == V_11 ) {
F_8 ( 3 , V_5 , L_10 , V_22 ) ;
return 1 ;
}
}
F_8 ( 4 , V_5 , L_6 ,
V_5 -> V_26 ) ;
V_23 = F_15 ( V_5 -> V_14 ,
F_16 ( V_12 ,
& V_5 -> V_13 ) ,
V_5 -> V_26 ) ;
if ( V_23 > 0 )
F_8 ( 4 , V_5 , L_11 ) ;
else if ( V_23 == 0 )
F_8 ( 4 , V_5 , L_12 ) ;
else if ( V_23 < 0 )
F_8 ( 4 , V_5 , L_9 ) ;
return V_23 ;
}
static T_1 F_19 ( struct V_28 * V_29 , char T_2 * V_30 ,
T_3 V_31 , T_4 * V_32 )
{
struct V_4 * V_5 = V_29 -> V_33 ;
int V_24 = V_5 -> V_7 -> V_8 [ 0 ] -> V_9 ;
T_3 V_34 ;
unsigned long V_22 ;
T_3 V_35 ;
int V_23 ;
unsigned char V_36 ;
F_8 ( 2 , V_5 , L_13 , V_37 -> V_38 , V_37 -> V_39 ) ;
if ( V_31 == 0 )
return 0 ;
if ( V_31 < 10 )
return - V_40 ;
if ( V_29 -> V_41 & V_42 ) {
F_8 ( 4 , V_5 , L_14 ) ;
F_8 ( 2 , V_5 , L_15 ) ;
return - V_43 ;
}
if ( ! F_20 ( V_5 -> V_7 ) )
return - V_44 ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ ) {
V_23 = F_18 ( V_5 ) ;
if ( V_23 <= 0 ) {
F_8 ( 5 , V_5 , L_16 , V_23 ) ;
F_8 ( 2 , V_5 , L_17 ) ;
if ( V_23 == - V_45 )
return V_23 ;
return - V_46 ;
}
V_5 -> V_47 [ V_22 ] = F_4 ( V_24 + V_48 ) ;
#ifdef F_21
F_2 ( L_18 , V_22 , V_5 -> V_47 [ V_22 ] ) ;
}
F_2 ( L_19 ) ;
#else
}
T_1 F_22 ( struct V_28 * V_29 , const char T_2 * V_30 ,
T_3 V_31 , T_4 * V_32 )
{
struct V_4 * V_5 = V_29 -> V_33 ;
int V_24 = V_5 -> V_7 -> V_8 [ 0 ] -> V_9 ;
T_1 V_23 ;
int V_22 ;
unsigned int V_49 ;
F_8 ( 2 , V_5 , L_20 , V_37 -> V_38 , V_37 -> V_39 ) ;
if ( V_31 == 0 ) {
F_8 ( 2 , V_5 , L_21 ) ;
return 0 ;
}
if ( ( V_31 < 5 ) || ( V_31 > V_50 ) ) {
F_8 ( 2 , V_5 , L_22 , V_31 ) ;
return - V_46 ;
}
if ( V_29 -> V_41 & V_42 ) {
F_8 ( 4 , V_5 , L_14 ) ;
F_8 ( 4 , V_5 , L_23 ) ;
return - V_43 ;
}
if ( ! F_20 ( V_5 -> V_7 ) )
return - V_44 ;
V_49 = V_31 ;
if ( F_23 ( V_5 -> V_51 , V_30 , V_49 ) )
return - V_40 ;
switch ( V_5 -> V_51 [ 0 ] ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
V_5 -> V_26 = V_56 ;
break;
case V_57 :
V_5 -> V_26 = V_58 ;
break;
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
default:
V_5 -> V_26 = V_66 ;
break;
}
V_23 = F_17 ( V_67 , V_5 ) ;
if ( V_23 <= 0 ) {
F_8 ( 5 , V_5 , L_24 , V_23 ) ;
F_8 ( 2 , V_5 , L_25 ) ;
if ( V_23 == - V_45 )
return V_23 ;
else
return - V_46 ;
}
F_8 ( 4 , V_5 , L_26 ) ;
for ( V_22 = 0 ; V_22 < V_49 ; V_22 ++ ) {
V_23 = F_14 ( V_5 ) ;
if ( V_23 <= 0 ) {
F_8 ( 5 , V_5 , L_27 ,
V_23 ) ;
F_8 ( 2 , V_5 , L_25 ) ;
if ( V_23 == - V_45 )
return V_23 ;
else
return - V_46 ;
}
F_1 ( V_5 -> V_51 [ V_22 ] , V_24 + V_68 ) ;
}
F_8 ( 4 , V_5 , L_28 ) ;
V_23 = F_17 ( V_69 , V_5 ) ;
if ( V_23 <= 0 ) {
F_8 ( 5 , V_5 , L_24 , V_23 ) ;
F_8 ( 2 , V_5 , L_25 ) ;
if ( V_23 == - V_45 )
return V_23 ;
else
return - V_46 ;
}
F_8 ( 2 , V_5 , L_29 ) ;
return V_31 ;
}
static unsigned int F_24 ( struct V_28 * V_29 , T_5 * V_70 )
{
struct V_4 * V_5 = V_29 -> V_33 ;
unsigned int V_71 = 0 ;
V_18 ( V_29 , & V_5 -> V_18 , V_70 ) ;
if ( F_16 ( V_12 , & V_5 -> V_13 ) )
V_71 |= V_72 | V_73 ;
if ( F_16 ( V_16 , & V_5 -> V_13 ) )
V_71 |= V_74 | V_75 ;
F_8 ( 2 , V_5 , L_30 , V_71 ) ;
return V_71 ;
}
static int F_25 ( struct V_76 * V_76 , struct V_28 * V_29 )
{
struct V_4 * V_5 ;
struct V_77 * V_78 ;
int V_79 = F_26 ( V_76 ) ;
int V_80 ;
if ( V_79 >= V_81 )
return - V_44 ;
F_27 ( & V_82 ) ;
V_78 = V_83 [ V_79 ] ;
if ( V_78 == NULL || ! F_20 ( V_78 ) ) {
V_80 = - V_44 ;
goto V_84;
}
if ( V_78 -> V_85 ) {
V_80 = - V_86 ;
goto V_84;
}
V_5 = V_78 -> V_87 ;
V_29 -> V_33 = V_5 ;
if ( V_29 -> V_41 & V_42 ) {
F_8 ( 4 , V_5 , L_14 ) ;
V_80 = - V_43 ;
goto V_84;
}
V_78 -> V_85 = 1 ;
V_5 -> V_19 . V_88 = ( unsigned long ) V_5 ;
F_11 ( & V_5 -> V_19 , V_20 + V_21 ) ;
F_8 ( 2 , V_5 , L_31 ) ;
V_80 = F_28 ( V_76 , V_29 ) ;
V_84:
F_29 ( & V_82 ) ;
return V_80 ;
}
static int F_30 ( struct V_76 * V_76 , struct V_28 * V_29 )
{
struct V_4 * V_5 = V_29 -> V_33 ;
struct V_77 * V_78 ;
int V_79 = F_26 ( V_76 ) ;
F_8 ( 2 , V_5 , L_32 , F_31 ( V_76 ) ,
F_26 ( V_76 ) ) ;
if ( V_79 >= V_81 )
return - V_44 ;
V_78 = V_83 [ V_79 ] ;
if ( V_78 == NULL )
return - V_44 ;
F_12 ( V_5 ) ;
V_78 -> V_85 = 0 ;
F_32 ( & V_5 -> V_89 ) ;
F_8 ( 2 , V_5 , L_33 ) ;
return 0 ;
}
static void F_33 ( struct V_77 * V_78 )
{
struct V_4 * V_5 = V_78 -> V_87 ;
F_8 ( 3 , V_5 , L_34 ) ;
while ( V_78 -> V_85 ) {
F_8 ( 3 , dev, KERN_INFO MODULE_NAME L_35
L_36 ) ;
F_34 ( V_5 -> V_89 , ( V_78 -> V_85 == 0 ) ) ;
}
F_8 ( 3 , V_5 , L_37 ) ;
return;
}
static int F_35 ( struct V_77 * V_7 , void * V_90 )
{
return F_36 ( V_7 ) ;
}
static int F_37 ( struct V_77 * V_78 , int V_91 )
{
struct V_4 * V_5 ;
int V_92 ;
V_78 -> V_93 |= V_94 ;
if ( F_38 ( V_78 , F_35 , NULL ) )
goto V_95;
V_92 = F_39 ( V_78 ) ;
if ( V_92 != 0 ) {
F_40 ( & V_78 -> V_5 , L_38 ,
V_92 ) ;
goto V_95;
}
V_5 = V_78 -> V_87 ;
F_8 ( 2 , V_5 , L_39 V_96 L_40 , V_91 ,
V_78 -> V_8 [ 0 ] ) ;
F_8 ( 2 , V_5 , L_41 ) ;
return 0 ;
V_95:
F_41 ( V_78 ) ;
return - V_44 ;
}
static void F_41 ( struct V_77 * V_78 )
{
F_33 ( V_78 ) ;
F_42 ( V_78 ) ;
}
static int F_43 ( struct V_77 * V_78 )
{
struct V_4 * V_5 ;
int V_22 , V_80 ;
for ( V_22 = 0 ; V_22 < V_81 ; V_22 ++ ) {
if ( V_83 [ V_22 ] == NULL )
break;
}
if ( V_22 == V_81 )
return - V_44 ;
V_5 = F_44 ( sizeof( struct V_4 ) , V_97 ) ;
if ( V_5 == NULL )
return - V_98 ;
V_5 -> V_26 = V_66 ;
V_5 -> V_13 = 0 ;
V_78 -> V_87 = V_5 ;
V_5 -> V_7 = V_78 ;
V_83 [ V_22 ] = V_78 ;
F_45 ( & V_5 -> V_89 ) ;
F_45 ( & V_5 -> V_18 ) ;
F_45 ( & V_5 -> V_14 ) ;
F_45 ( & V_5 -> V_17 ) ;
F_46 ( & V_5 -> V_19 , F_6 , 0 ) ;
V_80 = F_37 ( V_78 , V_22 ) ;
if ( V_80 ) {
V_83 [ V_22 ] = NULL ;
F_47 ( V_5 ) ;
return V_80 ;
}
F_48 ( V_99 , NULL , F_49 ( V_100 , V_22 ) , NULL , L_42 , V_22 ) ;
return 0 ;
}
static void F_50 ( struct V_77 * V_78 )
{
struct V_4 * V_5 = V_78 -> V_87 ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_81 ; V_91 ++ ) {
if ( V_83 [ V_91 ] == V_78 )
break;
}
if ( V_91 == V_81 )
return;
F_41 ( V_78 ) ;
V_83 [ V_91 ] = NULL ;
F_47 ( V_5 ) ;
F_51 ( V_99 , F_49 ( V_100 , V_91 ) ) ;
return;
}
static int T_6 F_52 ( void )
{
int V_23 ;
V_99 = F_53 ( V_101 , L_43 ) ;
if ( F_54 ( V_99 ) )
return F_55 ( V_99 ) ;
V_100 = F_56 ( 0 , V_96 , & V_102 ) ;
if ( V_100 < 0 ) {
F_57 (KERN_WARNING MODULE_NAME
L_44 ) ;
F_58 ( V_99 ) ;
return V_100 ;
}
V_23 = F_59 ( & V_103 ) ;
if ( V_23 < 0 ) {
F_60 ( V_100 , V_96 ) ;
F_58 ( V_99 ) ;
return V_23 ;
}
return 0 ;
}
static void T_7 F_61 ( void )
{
F_62 ( & V_103 ) ;
F_60 ( V_100 , V_96 ) ;
F_58 ( V_99 ) ;
}
