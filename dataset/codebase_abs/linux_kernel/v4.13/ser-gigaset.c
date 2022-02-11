static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 -> V_4 ;
struct V_7 * V_8 = & V_2 -> V_8 [ 0 ] ;
struct V_9 * V_10 = V_8 -> V_11 ;
int V_12 = - V_13 ;
F_2 ( ! V_4 || ! V_4 -> V_14 || ! V_10 ) ;
if ( ! V_10 -> V_15 ) {
F_3 ( V_10 ) ;
V_8 -> V_11 = NULL ;
return - V_16 ;
}
F_4 ( V_17 , & V_4 -> V_18 ) ;
if ( V_4 -> V_14 -> V_19 )
V_12 = V_4 -> V_14 -> V_19 ( V_4 , V_10 -> V_20 , V_10 -> V_15 ) ;
F_5 ( V_21 , L_1 , V_12 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 ) ;
return V_12 ;
}
F_7 ( V_10 , V_12 ) ;
if ( ! V_10 -> V_15 ) {
F_8 ( V_8 , V_10 ) ;
F_5 ( V_22 , L_2 ,
( unsigned long ) V_10 ) ;
F_3 ( V_10 ) ;
V_8 -> V_11 = NULL ;
}
return V_12 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 -> V_4 ;
struct V_23 * V_24 , * V_25 ;
unsigned long V_18 ;
int V_12 = 0 ;
F_2 ( ! V_4 || ! V_4 -> V_14 ) ;
V_24 = V_2 -> V_26 ;
if ( ! V_24 )
return 0 ;
if ( V_24 -> V_15 ) {
F_4 ( V_17 , & V_4 -> V_18 ) ;
V_12 = V_4 -> V_14 -> V_19 ( V_4 , V_24 -> V_27 + V_24 -> V_28 , V_24 -> V_15 ) ;
if ( V_12 < 0 ) {
F_5 ( V_21 , L_3 , V_12 ) ;
F_6 ( V_2 ) ;
return V_12 ;
}
V_24 -> V_28 += V_12 ;
V_24 -> V_15 -= V_12 ;
F_5 ( V_21 , L_4 ,
V_12 , V_24 -> V_15 , V_2 -> V_29 ) ;
}
while ( V_24 && ! V_24 -> V_15 ) {
F_10 ( & V_2 -> V_30 , V_18 ) ;
V_2 -> V_29 -= V_2 -> V_31 ;
V_25 = V_24 ;
V_2 -> V_26 = V_24 = V_24 -> V_32 ;
if ( V_24 ) {
V_24 -> V_33 = NULL ;
V_2 -> V_31 = V_24 -> V_15 ;
} else {
V_2 -> V_34 = NULL ;
V_2 -> V_31 = 0 ;
}
F_11 ( & V_2 -> V_30 , V_18 ) ;
if ( V_25 -> V_35 )
F_12 ( V_25 -> V_35 ) ;
F_13 ( V_25 ) ;
}
return V_12 ;
}
static void F_14 ( unsigned long V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
struct V_7 * V_8 ;
struct V_9 * V_36 ;
int V_12 = 0 ;
if ( ! V_2 ) {
F_5 ( V_21 , L_5 , V_37 ) ;
return;
}
V_8 = V_2 -> V_8 ;
if ( ! V_8 ) {
F_5 ( V_21 , L_5 , V_37 ) ;
return;
}
if ( ! V_8 -> V_11 ) {
V_12 = F_9 ( V_2 ) ;
F_5 ( V_21 , L_6 , V_37 , V_12 ) ;
if ( V_12 )
return;
V_36 = F_15 ( & V_8 -> V_38 ) ;
if ( ! V_36 )
return;
V_8 -> V_11 = V_36 ;
F_5 ( V_22 , L_7 ,
( unsigned long ) V_8 -> V_11 ) ;
}
F_5 ( V_21 , L_8 , V_37 ) ;
if ( F_1 ( V_2 ) < 0 )
F_5 ( V_21 , L_9 , V_37 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_23 * V_24 ;
unsigned long V_18 ;
F_10 ( & V_2 -> V_30 , V_18 ) ;
while ( ( V_24 = V_2 -> V_26 ) != NULL ) {
V_2 -> V_26 = V_24 -> V_32 ;
if ( V_24 -> V_35 )
F_12 ( V_24 -> V_35 ) ;
F_13 ( V_24 ) ;
}
V_2 -> V_26 = V_2 -> V_34 = NULL ;
V_2 -> V_29 = V_2 -> V_31 = 0 ;
F_11 ( & V_2 -> V_30 , V_18 ) ;
if ( V_2 -> V_8 -> V_11 )
F_3 ( V_2 -> V_8 -> V_11 ) ;
while ( ( V_10 = F_15 ( & V_2 -> V_8 -> V_38 ) ) != NULL )
F_3 ( V_10 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
unsigned long V_18 ;
F_17 ( V_2 -> V_39 != V_40 ?
V_41 : V_42 ,
L_10 , V_24 -> V_15 , V_24 -> V_27 ) ;
F_10 ( & V_2 -> V_30 , V_18 ) ;
V_24 -> V_33 = V_2 -> V_34 ;
if ( V_2 -> V_34 )
V_2 -> V_34 -> V_32 = V_24 ;
else {
V_2 -> V_26 = V_24 ;
V_2 -> V_31 = V_24 -> V_15 ;
}
V_2 -> V_29 += V_24 -> V_15 ;
V_2 -> V_34 = V_24 ;
F_11 ( & V_2 -> V_30 , V_18 ) ;
F_10 ( & V_2 -> V_43 , V_18 ) ;
if ( V_2 -> V_44 )
F_12 ( & V_2 -> V_45 ) ;
F_11 ( & V_2 -> V_43 , V_18 ) ;
return V_24 -> V_15 ;
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned V_46 ;
V_46 = V_2 -> V_29 ;
return V_46 < V_47 ? V_47 - V_46 : 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
return V_2 -> V_29 ;
}
static int F_20 ( struct V_1 * V_2 , const unsigned char V_27 [ 6 ] )
{
return - V_16 ;
}
static int F_21 ( struct V_7 * V_8 )
{
F_22 ( V_8 ) ;
return 0 ;
}
static int F_23 ( struct V_7 * V_8 )
{
F_24 ( V_8 ) ;
return 0 ;
}
static int F_25 ( struct V_7 * V_8 )
{
V_8 -> V_5 . V_6 = NULL ;
return 0 ;
}
static void F_26 ( struct V_7 * V_8 )
{
}
static void F_27 ( struct V_7 * V_8 )
{
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_45 ) ;
if ( ! V_2 -> V_5 . V_6 )
return;
F_30 ( & V_2 -> V_5 . V_6 -> V_48 ) ;
}
static void F_31 ( struct V_49 * V_48 )
{
F_13 ( F_32 ( V_48 , struct V_50 , V_48 . V_48 ) ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_51 ;
struct V_50 * V_52 ;
V_52 = F_34 ( sizeof( struct V_50 ) , V_53 ) ;
if ( ! V_52 ) {
F_35 ( L_11 ) ;
return - V_54 ;
}
V_2 -> V_5 . V_6 = V_52 ;
V_2 -> V_5 . V_6 -> V_48 . V_55 = V_56 ;
V_2 -> V_5 . V_6 -> V_48 . V_57 = V_2 -> V_58 ;
V_2 -> V_5 . V_6 -> V_48 . V_48 . V_59 = F_31 ;
V_51 = F_36 ( & V_2 -> V_5 . V_6 -> V_48 ) ;
if ( V_51 != 0 ) {
F_35 ( L_12 , V_51 ) ;
F_13 ( V_2 -> V_5 . V_6 ) ;
V_2 -> V_5 . V_6 = NULL ;
return V_51 ;
}
F_37 ( & V_2 -> V_45 ,
F_14 , ( unsigned long ) V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , unsigned V_60 ,
unsigned V_61 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 -> V_4 ;
unsigned int V_62 , V_63 ;
F_2 ( ! V_4 || ! V_4 -> V_14 ) ;
if ( ! V_4 -> V_14 -> V_64 )
return - V_16 ;
V_62 = V_61 & ~ V_60 ;
V_63 = V_60 & ~ V_61 ;
if ( ! V_62 && ! V_63 )
return 0 ;
F_5 ( V_65 , L_13 , V_62 , V_63 ) ;
return V_4 -> V_14 -> V_64 ( V_4 , V_62 , V_63 ) ;
}
static int F_39 ( struct V_1 * V_2 , unsigned V_66 )
{
return - V_16 ;
}
static int F_40 ( struct V_1 * V_2 , unsigned V_66 )
{
return - V_16 ;
}
static struct V_1 * F_41 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_67 ;
if ( ! V_2 || ! V_2 -> V_5 . V_6 ) {
F_5 ( V_68 , L_5 , V_37 ) ;
return NULL ;
}
F_42 ( & V_2 -> V_5 . V_6 -> V_69 ) ;
return V_2 ;
}
static void F_43 ( struct V_1 * V_2 )
{
if ( F_44 ( & V_2 -> V_5 . V_6 -> V_69 ) )
F_45 ( & V_2 -> V_5 . V_6 -> V_70 ) ;
}
static int
F_46 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_51 ;
F_5 ( V_71 , L_14 ) ;
F_47 ( V_72 L_15 ) ;
if ( ! V_73 ) {
F_35 ( L_16 , V_37 ) ;
return - V_74 ;
}
V_2 = F_48 ( V_73 , 1 , 1 , 0 , V_75 , V_56 ) ;
if ( ! V_2 ) {
V_51 = - V_74 ;
goto error;
}
V_2 -> V_48 = & V_2 -> V_5 . V_6 -> V_48 . V_48 ;
V_2 -> V_5 . V_6 -> V_4 = V_4 ;
F_49 ( & V_2 -> V_5 . V_6 -> V_69 , 1 ) ;
F_50 ( & V_2 -> V_5 . V_6 -> V_70 ) ;
V_4 -> V_67 = V_2 ;
V_4 -> V_76 = V_77 / 2 ;
if ( V_78 == V_79 )
V_2 -> V_39 = V_40 ;
V_51 = F_51 ( V_2 ) ;
if ( V_51 < 0 ) {
F_29 ( & V_2 -> V_45 ) ;
goto error;
}
F_5 ( V_71 , L_17 ) ;
return 0 ;
error:
F_5 ( V_71 , L_18 ) ;
V_4 -> V_67 = NULL ;
F_52 ( V_2 ) ;
return V_51 ;
}
static void
F_53 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_67 ;
F_5 ( V_71 , L_19 ) ;
if ( ! V_2 ) {
F_5 ( V_71 , L_5 , V_37 ) ;
return;
}
V_4 -> V_67 = NULL ;
if ( ! V_2 -> V_5 . V_6 )
F_35 ( L_20 , V_37 ) ;
else {
if ( ! F_44 ( & V_2 -> V_5 . V_6 -> V_69 ) )
F_54 ( & V_2 -> V_5 . V_6 -> V_70 ) ;
}
F_55 ( V_2 ) ;
F_29 ( & V_2 -> V_45 ) ;
F_6 ( V_2 ) ;
V_2 -> V_48 = NULL ;
F_52 ( V_2 ) ;
F_5 ( V_71 , L_21 ) ;
}
static int F_56 ( struct V_3 * V_4 )
{
F_53 ( V_4 ) ;
return 0 ;
}
static int
F_57 ( struct V_3 * V_4 , struct V_80 * V_80 ,
unsigned int V_81 , unsigned long V_82 )
{
struct V_1 * V_2 = F_41 ( V_4 ) ;
int V_51 , V_83 ;
int T_1 * V_84 = ( int T_1 * ) V_82 ;
if ( ! V_2 )
return - V_85 ;
switch ( V_81 ) {
case V_86 :
V_83 = 0 ;
V_51 = F_58 ( V_83 , V_84 ) ;
break;
case V_87 :
switch ( V_82 ) {
case V_88 :
break;
case V_89 :
case V_90 :
F_6 ( V_2 ) ;
break;
}
default:
V_51 = F_59 ( V_4 , V_80 , V_81 , V_82 ) ;
break;
}
F_43 ( V_2 ) ;
return V_51 ;
}
static void
F_60 ( struct V_3 * V_4 , const unsigned char * V_27 ,
char * V_91 , int V_92 )
{
struct V_1 * V_2 = F_41 ( V_4 ) ;
unsigned V_93 , V_94 , V_95 ;
struct V_96 * V_97 ;
if ( ! V_2 )
return;
V_97 = V_2 -> V_97 ;
if ( ! V_97 ) {
F_61 ( V_2 -> V_48 , L_22 , V_37 ) ;
F_43 ( V_2 ) ;
return;
}
V_93 = V_97 -> V_93 ;
V_94 = V_97 -> V_94 ;
F_5 ( V_22 , L_23 ,
V_94 , V_93 , V_92 ) ;
if ( V_94 <= V_93 ) {
V_95 = F_62 ( unsigned , V_92 , V_77 - V_93 ) ;
memcpy ( V_97 -> V_20 + V_93 , V_27 , V_95 ) ;
V_93 = ( V_93 + V_95 ) % V_77 ;
V_27 += V_95 ;
V_92 -= V_95 ;
}
if ( V_92 > 0 ) {
V_95 = V_94 - V_93 - 1 ;
if ( V_92 > V_95 ) {
F_61 ( V_2 -> V_48 ,
L_24 ,
V_92 - V_95 ) ;
V_92 = V_95 ;
}
memcpy ( V_97 -> V_20 + V_93 , V_27 , V_92 ) ;
V_93 += V_92 ;
}
F_5 ( V_22 , L_25 , V_93 ) ;
V_97 -> V_93 = V_93 ;
F_5 ( V_22 , L_26 , V_37 ) ;
F_63 ( V_2 ) ;
F_43 ( V_2 ) ;
}
static void
F_64 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_41 ( V_4 ) ;
F_65 ( V_17 , & V_4 -> V_18 ) ;
if ( ! V_2 )
return;
F_12 ( & V_2 -> V_45 ) ;
F_43 ( V_2 ) ;
}
static int T_2 F_66 ( void )
{
int V_51 ;
F_5 ( V_71 , L_27 , V_37 ) ;
V_51 = F_67 ( & V_98 ) ;
if ( V_51 != 0 ) {
F_35 ( L_28 , V_51 ) ;
return V_51 ;
}
V_73 = F_68 ( V_99 , V_100 ,
V_56 , V_101 ,
& V_14 , V_102 ) ;
if ( ! V_73 ) {
V_51 = - V_54 ;
goto error;
}
V_51 = F_69 ( V_103 , & V_104 ) ;
if ( V_51 != 0 ) {
F_35 ( L_29 , V_51 ) ;
goto error;
}
return 0 ;
error:
if ( V_73 ) {
F_70 ( V_73 ) ;
V_73 = NULL ;
}
F_71 ( & V_98 ) ;
return V_51 ;
}
static void T_3 F_72 ( void )
{
int V_51 ;
F_5 ( V_71 , L_27 , V_37 ) ;
if ( V_73 ) {
F_70 ( V_73 ) ;
V_73 = NULL ;
}
V_51 = F_73 ( V_103 ) ;
if ( V_51 != 0 )
F_35 ( L_30 , V_51 ) ;
F_71 ( & V_98 ) ;
}
