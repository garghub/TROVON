static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 -> V_4 ;
struct V_7 * V_8 = & V_2 -> V_8 [ 0 ] ;
struct V_9 * V_10 = V_8 -> V_11 ;
int V_12 = - V_13 ;
if ( ! V_4 || ! V_4 -> V_14 || ! V_10 )
return - V_15 ;
if ( ! V_10 -> V_16 ) {
F_2 ( V_10 ) ;
V_8 -> V_11 = NULL ;
return - V_15 ;
}
F_3 ( V_17 , & V_4 -> V_18 ) ;
if ( V_4 -> V_19 -> V_20 )
V_12 = V_4 -> V_19 -> V_20 ( V_4 , V_10 -> V_21 , V_10 -> V_16 ) ;
F_4 ( V_22 , L_1 , V_12 ) ;
if ( V_12 < 0 ) {
F_5 ( V_2 ) ;
return V_12 ;
}
F_6 ( V_10 , V_12 ) ;
if ( ! V_10 -> V_16 ) {
F_7 ( V_8 , V_10 ) ;
F_4 ( V_23 , L_2 ,
( unsigned long ) V_10 ) ;
F_2 ( V_10 ) ;
V_8 -> V_11 = NULL ;
}
return V_12 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 -> V_4 ;
struct V_24 * V_25 , * V_26 ;
unsigned long V_18 ;
int V_12 = 0 ;
if ( ! V_4 || ! V_4 -> V_14 )
return - V_27 ;
V_25 = V_2 -> V_28 ;
if ( ! V_25 )
return 0 ;
if ( V_25 -> V_16 ) {
F_3 ( V_17 , & V_4 -> V_18 ) ;
V_12 = V_4 -> V_19 -> V_20 ( V_4 , V_25 -> V_29 + V_25 -> V_30 , V_25 -> V_16 ) ;
if ( V_12 < 0 ) {
F_4 ( V_22 , L_3 , V_12 ) ;
F_5 ( V_2 ) ;
return V_12 ;
}
V_25 -> V_30 += V_12 ;
V_25 -> V_16 -= V_12 ;
F_4 ( V_22 , L_4 ,
V_12 , V_25 -> V_16 , V_2 -> V_31 ) ;
}
while ( V_25 && ! V_25 -> V_16 ) {
F_9 ( & V_2 -> V_32 , V_18 ) ;
V_2 -> V_31 -= V_2 -> V_33 ;
V_26 = V_25 ;
V_2 -> V_28 = V_25 = V_25 -> V_34 ;
if ( V_25 ) {
V_25 -> V_35 = NULL ;
V_2 -> V_33 = V_25 -> V_16 ;
} else {
V_2 -> V_36 = NULL ;
V_2 -> V_33 = 0 ;
}
F_10 ( & V_2 -> V_32 , V_18 ) ;
if ( V_26 -> V_37 )
F_11 ( V_26 -> V_37 ) ;
F_12 ( V_26 ) ;
}
return V_12 ;
}
static void F_13 ( unsigned long V_21 )
{
struct V_1 * V_2 = (struct V_1 * ) V_21 ;
struct V_7 * V_8 ;
struct V_9 * V_38 ;
int V_12 = 0 ;
if ( ! V_2 ) {
F_4 ( V_22 , L_5 , V_39 ) ;
return;
}
V_8 = V_2 -> V_8 ;
if ( ! V_8 ) {
F_4 ( V_22 , L_5 , V_39 ) ;
return;
}
if ( ! V_8 -> V_11 ) {
V_12 = F_8 ( V_2 ) ;
F_4 ( V_22 , L_6 , V_39 , V_12 ) ;
if ( V_12 )
return;
V_38 = F_14 ( & V_8 -> V_40 ) ;
if ( ! V_38 )
return;
V_8 -> V_11 = V_38 ;
F_4 ( V_23 , L_7 ,
( unsigned long ) V_8 -> V_11 ) ;
}
F_4 ( V_22 , L_8 , V_39 ) ;
if ( F_1 ( V_2 ) < 0 )
F_4 ( V_22 , L_9 , V_39 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_24 * V_25 ;
unsigned long V_18 ;
F_9 ( & V_2 -> V_32 , V_18 ) ;
while ( ( V_25 = V_2 -> V_28 ) != NULL ) {
V_2 -> V_28 = V_25 -> V_34 ;
if ( V_25 -> V_37 )
F_11 ( V_25 -> V_37 ) ;
F_12 ( V_25 ) ;
}
V_2 -> V_28 = V_2 -> V_36 = NULL ;
V_2 -> V_31 = V_2 -> V_33 = 0 ;
F_10 ( & V_2 -> V_32 , V_18 ) ;
if ( V_2 -> V_8 -> V_11 )
F_2 ( V_2 -> V_8 -> V_11 ) ;
while ( ( V_10 = F_14 ( & V_2 -> V_8 -> V_40 ) ) != NULL )
F_2 ( V_10 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
unsigned long V_18 ;
F_16 ( V_2 -> V_41 != V_42 ?
V_43 : V_44 ,
L_10 , V_25 -> V_16 , V_25 -> V_29 ) ;
F_9 ( & V_2 -> V_32 , V_18 ) ;
V_25 -> V_35 = V_2 -> V_36 ;
if ( V_2 -> V_36 )
V_2 -> V_36 -> V_34 = V_25 ;
else {
V_2 -> V_28 = V_25 ;
V_2 -> V_33 = V_25 -> V_16 ;
}
V_2 -> V_31 += V_25 -> V_16 ;
V_2 -> V_36 = V_25 ;
F_10 ( & V_2 -> V_32 , V_18 ) ;
F_9 ( & V_2 -> V_45 , V_18 ) ;
if ( V_2 -> V_46 )
F_11 ( & V_2 -> V_47 ) ;
F_10 ( & V_2 -> V_45 , V_18 ) ;
return V_25 -> V_16 ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned V_48 ;
V_48 = V_2 -> V_31 ;
return V_48 < V_49 ? V_49 - V_48 : 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return V_2 -> V_31 ;
}
static int F_19 ( struct V_1 * V_2 , const unsigned char V_29 [ 6 ] )
{
return - V_15 ;
}
static int F_20 ( struct V_7 * V_8 )
{
F_21 ( V_8 ) ;
return 0 ;
}
static int F_22 ( struct V_7 * V_8 )
{
F_23 ( V_8 ) ;
return 0 ;
}
static int F_24 ( struct V_7 * V_8 )
{
V_8 -> V_5 . V_6 = NULL ;
return 1 ;
}
static int F_25 ( struct V_7 * V_8 )
{
return 1 ;
}
static void F_26 ( struct V_7 * V_8 )
{
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_47 ) ;
if ( ! V_2 -> V_5 . V_6 )
return;
F_29 ( & V_2 -> V_5 . V_6 -> V_50 . V_50 , NULL ) ;
F_30 ( & V_2 -> V_5 . V_6 -> V_50 ) ;
F_12 ( V_2 -> V_5 . V_6 ) ;
V_2 -> V_5 . V_6 = NULL ;
}
static void F_31 ( struct V_51 * V_50 )
{
struct V_52 * V_53 = F_32 ( V_50 ) ;
F_12 ( V_50 -> V_54 ) ;
F_12 ( V_53 -> V_55 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_56 ;
struct V_57 * V_58 ;
V_58 = F_34 ( sizeof( struct V_57 ) , V_59 ) ;
if ( ! V_58 ) {
F_35 ( L_11 ) ;
return 0 ;
}
V_2 -> V_5 . V_6 = V_58 ;
V_2 -> V_5 . V_6 -> V_50 . V_60 = V_61 ;
V_2 -> V_5 . V_6 -> V_50 . V_62 = V_2 -> V_63 ;
V_2 -> V_5 . V_6 -> V_50 . V_50 . V_64 = F_31 ;
V_56 = F_36 ( & V_2 -> V_5 . V_6 -> V_50 ) ;
if ( V_56 != 0 ) {
F_35 ( L_12 , V_56 ) ;
F_12 ( V_2 -> V_5 . V_6 ) ;
V_2 -> V_5 . V_6 = NULL ;
return 0 ;
}
F_29 ( & V_2 -> V_5 . V_6 -> V_50 . V_50 , V_2 ) ;
F_37 ( & V_2 -> V_47 ,
F_13 , ( unsigned long ) V_2 ) ;
return 1 ;
}
static int F_38 ( struct V_1 * V_2 , unsigned V_65 ,
unsigned V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 -> V_4 ;
unsigned int V_67 , V_68 ;
if ( ! V_4 || ! V_4 -> V_14 || ! V_4 -> V_19 -> V_69 )
return - V_15 ;
V_67 = V_66 & ~ V_65 ;
V_68 = V_65 & ~ V_66 ;
if ( ! V_67 && ! V_68 )
return 0 ;
F_4 ( V_70 , L_13 , V_67 , V_68 ) ;
return V_4 -> V_19 -> V_69 ( V_4 , V_67 , V_68 ) ;
}
static int F_39 ( struct V_1 * V_2 , unsigned V_71 )
{
return - V_15 ;
}
static int F_40 ( struct V_1 * V_2 , unsigned V_71 )
{
return - V_15 ;
}
static struct V_1 * F_41 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_72 ;
if ( ! V_2 || ! V_2 -> V_5 . V_6 ) {
F_4 ( V_73 , L_5 , V_39 ) ;
return NULL ;
}
F_42 ( & V_2 -> V_5 . V_6 -> V_74 ) ;
return V_2 ;
}
static void F_43 ( struct V_1 * V_2 )
{
if ( F_44 ( & V_2 -> V_5 . V_6 -> V_74 ) )
F_45 ( & V_2 -> V_5 . V_6 -> V_75 ) ;
}
static int
F_46 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_4 ( V_76 , L_14 ) ;
F_47 ( V_77 L_15 ) ;
if ( ! V_14 ) {
F_35 ( L_16 , V_39 ) ;
return - V_78 ;
}
V_2 = F_48 ( V_14 , 1 , 1 , 0 , V_79 , V_61 ) ;
if ( ! V_2 )
goto error;
V_2 -> V_50 = & V_2 -> V_5 . V_6 -> V_50 . V_50 ;
V_2 -> V_5 . V_6 -> V_4 = V_4 ;
F_49 ( & V_2 -> V_5 . V_6 -> V_74 , 1 ) ;
F_50 ( & V_2 -> V_5 . V_6 -> V_75 ) ;
V_4 -> V_72 = V_2 ;
if ( V_80 == V_81 )
V_2 -> V_41 = V_42 ;
if ( ! F_51 ( V_2 ) ) {
F_28 ( & V_2 -> V_47 ) ;
goto error;
}
F_4 ( V_76 , L_17 ) ;
return 0 ;
error:
F_4 ( V_76 , L_18 ) ;
V_4 -> V_72 = NULL ;
F_52 ( V_2 ) ;
return - V_78 ;
}
static void
F_53 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_72 ;
F_4 ( V_76 , L_19 ) ;
if ( ! V_2 ) {
F_4 ( V_76 , L_5 , V_39 ) ;
return;
}
V_4 -> V_72 = NULL ;
if ( ! V_2 -> V_5 . V_6 )
F_35 ( L_20 , V_39 ) ;
else {
if ( ! F_44 ( & V_2 -> V_5 . V_6 -> V_74 ) )
F_54 ( & V_2 -> V_5 . V_6 -> V_75 ) ;
}
F_55 ( V_2 ) ;
F_28 ( & V_2 -> V_47 ) ;
F_5 ( V_2 ) ;
V_2 -> V_50 = NULL ;
F_52 ( V_2 ) ;
F_4 ( V_76 , L_21 ) ;
}
static int F_56 ( struct V_3 * V_4 )
{
F_53 ( V_4 ) ;
return 0 ;
}
static T_1
F_57 ( struct V_3 * V_4 , struct V_82 * V_82 ,
unsigned char T_2 * V_29 , T_3 V_83 )
{
return - V_84 ;
}
static T_1
F_58 ( struct V_3 * V_4 , struct V_82 * V_82 ,
const unsigned char * V_29 , T_3 V_83 )
{
return - V_84 ;
}
static int
F_59 ( struct V_3 * V_4 , struct V_82 * V_82 ,
unsigned int V_85 , unsigned long V_86 )
{
struct V_1 * V_2 = F_41 ( V_4 ) ;
int V_56 , V_87 ;
int T_2 * V_88 = ( int T_2 * ) V_86 ;
if ( ! V_2 )
return - V_89 ;
switch ( V_85 ) {
case V_90 :
V_87 = 0 ;
V_56 = F_60 ( V_87 , V_88 ) ;
break;
case V_91 :
switch ( V_86 ) {
case V_92 :
break;
case V_93 :
case V_94 :
F_5 ( V_2 ) ;
break;
}
default:
V_56 = F_61 ( V_4 , V_82 , V_85 , V_86 ) ;
break;
}
F_43 ( V_2 ) ;
return V_56 ;
}
static void
F_62 ( struct V_3 * V_4 , const unsigned char * V_29 ,
char * V_95 , int V_83 )
{
struct V_1 * V_2 = F_41 ( V_4 ) ;
unsigned V_96 , V_97 , V_98 ;
struct V_99 * V_100 ;
if ( ! V_2 )
return;
V_100 = V_2 -> V_100 ;
if ( ! V_100 ) {
F_63 ( V_2 -> V_50 , L_22 , V_39 ) ;
F_43 ( V_2 ) ;
return;
}
V_96 = V_100 -> V_96 ;
V_97 = V_100 -> V_97 ;
F_4 ( V_23 , L_23 ,
V_97 , V_96 , V_83 ) ;
if ( V_97 <= V_96 ) {
V_98 = F_64 ( unsigned , V_83 , V_101 - V_96 ) ;
memcpy ( V_100 -> V_21 + V_96 , V_29 , V_98 ) ;
V_96 = ( V_96 + V_98 ) % V_101 ;
V_29 += V_98 ;
V_83 -= V_98 ;
}
if ( V_83 > 0 ) {
V_98 = V_97 - V_96 - 1 ;
if ( V_83 > V_98 ) {
F_63 ( V_2 -> V_50 ,
L_24 ,
V_83 - V_98 ) ;
V_83 = V_98 ;
}
memcpy ( V_100 -> V_21 + V_96 , V_29 , V_83 ) ;
V_96 += V_83 ;
}
F_4 ( V_23 , L_25 , V_96 ) ;
V_100 -> V_96 = V_96 ;
F_4 ( V_23 , L_26 , V_39 ) ;
F_65 ( V_2 ) ;
F_43 ( V_2 ) ;
}
static void
F_66 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_41 ( V_4 ) ;
F_67 ( V_17 , & V_4 -> V_18 ) ;
if ( ! V_2 )
return;
F_11 ( & V_2 -> V_47 ) ;
F_43 ( V_2 ) ;
}
static int T_4 F_68 ( void )
{
int V_56 ;
F_4 ( V_76 , L_27 , V_39 ) ;
V_56 = F_69 ( & V_102 ) ;
if ( V_56 != 0 ) {
F_35 ( L_28 , V_56 ) ;
return V_56 ;
}
V_14 = F_70 ( V_103 , V_104 ,
V_61 , V_105 ,
& V_19 , V_106 ) ;
if ( ! V_14 )
goto error;
V_56 = F_71 ( V_107 , & V_108 ) ;
if ( V_56 != 0 ) {
F_35 ( L_29 , V_56 ) ;
goto error;
}
return 0 ;
error:
if ( V_14 ) {
F_72 ( V_14 ) ;
V_14 = NULL ;
}
F_73 ( & V_102 ) ;
return V_56 ;
}
static void T_5 F_74 ( void )
{
int V_56 ;
F_4 ( V_76 , L_27 , V_39 ) ;
if ( V_14 ) {
F_72 ( V_14 ) ;
V_14 = NULL ;
}
V_56 = F_75 ( V_107 ) ;
if ( V_56 != 0 )
F_35 ( L_30 , V_56 ) ;
F_73 ( & V_102 ) ;
}
