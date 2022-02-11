static void F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
static unsigned char V_4 = 0 ;
while ( ( V_3 = F_2 ( 0 , 0 , 0 , 0 , V_5 ) ) ) {
if ( V_3 == 27 && V_4 == 0 ) {
V_4 = 1 ;
continue;
} else if ( V_4 == 1 && V_3 == 'O' ) {
V_4 = 2 ;
continue;
} else if ( V_4 == 2 ) {
if ( V_3 == 'P' )
F_3 () ;
#ifdef F_4
if ( V_3 == 'S' ) {
do {
V_3 = F_2 ( 0 , 0 , 0 , 0 , V_5 ) ;
} while ( ! V_3 );
F_5 ( V_3 ) ;
}
#endif
V_4 = 0 ;
continue;
}
V_4 = 0 ;
if ( F_6 ( V_2 , V_3 , V_6 ) == 0 )
break;
}
F_7 ( V_2 ) ;
}
static T_1 F_8 ( int V_7 , void * V_8 )
{
struct V_9 * V_10 = V_8 ;
struct V_1 * V_2 = F_9 ( & V_10 -> V_11 ) ;
if ( ! V_2 ) {
F_10 ( V_12 L_1 , V_13 ) ;
return V_14 ;
}
F_1 ( V_2 ) ;
F_11 ( V_2 ) ;
return V_15 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned char V_3 )
{
struct V_9 * V_10 = V_2 -> V_16 ;
unsigned long V_17 ;
if ( ! V_10 -> V_18 . V_19 )
return 0 ;
F_13 ( V_17 ) ;
if ( F_14 ( V_10 -> V_18 . V_20 , V_10 -> V_18 . V_21 , V_22 ) == 0 ) {
F_15 ( V_17 ) ;
return 0 ;
}
V_10 -> V_18 . V_19 [ V_10 -> V_18 . V_20 ] = V_3 ;
V_10 -> V_18 . V_20 = ( V_10 -> V_18 . V_20 + 1 ) & ( V_22 - 1 ) ;
F_15 ( V_17 ) ;
return 1 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_9 * V_10 ,
int * V_23 )
{
int V_24 ;
unsigned long V_17 ;
F_13 ( V_17 ) ;
if ( V_10 -> V_25 ) {
char V_26 = V_10 -> V_25 ;
V_27 -> V_28 ( V_27 , & V_26 , 1 ) ;
V_10 -> V_25 = 0 ;
goto V_29;
}
if ( V_10 -> V_18 . V_20 == V_10 -> V_18 . V_21 || V_2 -> V_30 ||
V_2 -> V_31 ) {
#ifdef F_17
F_10 ( L_2 ,
V_10 -> V_18 . V_20 , V_10 -> V_18 . V_21 , V_2 -> V_30 ) ;
#endif
goto V_29;
}
V_24 = F_18 ( F_19 ( V_10 -> V_18 . V_20 , V_10 -> V_18 . V_21 , V_22 ) ,
V_22 - V_10 -> V_18 . V_21 ) ;
V_27 -> V_28 ( V_27 , V_10 -> V_18 . V_19 + V_10 -> V_18 . V_21 , V_24 ) ;
V_10 -> V_18 . V_21 = ( V_10 -> V_18 . V_21 + V_24 ) & ( V_22 - 1 ) ;
V_24 = F_19 ( V_10 -> V_18 . V_20 , V_10 -> V_18 . V_21 , V_22 ) ;
if ( V_24 ) {
V_27 -> V_28 ( V_27 , V_10 -> V_18 . V_19 , V_24 ) ;
V_10 -> V_18 . V_21 += V_24 ;
}
V_29:
F_15 ( V_17 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_16 ;
if ( V_10 -> V_18 . V_20 == V_10 -> V_18 . V_21 || V_2 -> V_30 ||
V_2 -> V_31 || ! V_10 -> V_18 . V_19 )
return;
F_16 ( V_2 , V_10 , NULL ) ;
}
static int F_21 ( struct V_1 * V_2 ,
const unsigned char * V_19 , int V_24 )
{
struct V_9 * V_10 = V_2 -> V_16 ;
int V_26 , V_32 = 0 ;
unsigned long V_17 ;
if ( ! V_10 -> V_18 . V_19 )
return 0 ;
F_13 ( V_17 ) ;
while ( 1 ) {
V_26 = F_22 ( V_10 -> V_18 . V_20 , V_10 -> V_18 . V_21 , V_22 ) ;
if ( V_24 < V_26 )
V_26 = V_24 ;
if ( V_26 <= 0 ) {
break;
}
memcpy ( V_10 -> V_18 . V_19 + V_10 -> V_18 . V_20 , V_19 , V_26 ) ;
V_10 -> V_18 . V_20 = ( ( V_10 -> V_18 . V_20 + V_26 ) &
( V_22 - 1 ) ) ;
V_19 += V_26 ;
V_24 -= V_26 ;
V_32 += V_26 ;
}
F_15 ( V_17 ) ;
if ( F_19 ( V_10 -> V_18 . V_20 , V_10 -> V_18 . V_21 , V_22 ) &&
! V_2 -> V_30 && ! V_2 -> V_31 )
F_16 ( V_2 , V_10 , NULL ) ;
return V_32 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_16 ;
return F_14 ( V_10 -> V_18 . V_20 , V_10 -> V_18 . V_21 , V_22 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_16 ;
return F_19 ( V_10 -> V_18 . V_20 , V_10 -> V_18 . V_21 , V_22 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_16 ;
unsigned long V_17 ;
F_13 ( V_17 ) ;
V_10 -> V_18 . V_20 = V_10 -> V_18 . V_21 = 0 ;
F_15 ( V_17 ) ;
F_26 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 , char V_3 )
{
struct V_9 * V_10 = V_2 -> V_16 ;
V_10 -> V_25 = V_3 ;
if ( V_3 ) {
F_16 ( V_2 , V_10 , NULL ) ;
}
}
static void F_28 ( struct V_1 * V_2 )
{
if ( F_29 ( V_2 ) )
F_27 ( V_2 , F_30 ( V_2 ) ) ;
F_10 ( V_12 L_3 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_16 ;
if ( F_29 ( V_2 ) ) {
if ( V_10 -> V_25 )
V_10 -> V_25 = 0 ;
else
F_27 ( V_2 , F_32 ( V_2 ) ) ;
}
F_10 ( V_12 L_4 ) ;
}
static int F_33 ( struct V_1 * V_2 , unsigned int V_33 , unsigned long V_34 )
{
if ( ( V_33 != V_35 ) && ( V_33 != V_36 ) &&
( V_33 != V_37 ) && ( V_33 != V_38 ) &&
( V_33 != V_39 ) ) {
if ( V_2 -> V_17 & ( 1 << V_40 ) )
return - V_41 ;
}
switch ( V_33 ) {
case V_35 :
case V_36 :
case V_38 :
case V_39 :
return 0 ;
case V_37 :
case V_42 :
return - V_43 ;
case V_44 :
case V_45 :
F_10 ( V_12 L_5 ) ;
return 0 ;
}
return - V_46 ;
}
static void F_34 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
if ( ( V_48 -> V_49 & V_50 ) &&
! ( V_2 -> V_51 -> V_49 & V_50 ) ) {
V_2 -> V_31 = 0 ;
}
}
static void F_35 ( struct V_52 * V_11 )
{
struct V_9 * V_10 = F_36 ( V_11 , struct V_9 ,
V_11 ) ;
unsigned long V_17 ;
F_13 ( V_17 ) ;
if ( V_10 -> V_7 )
F_37 ( V_10 -> V_7 , V_10 ) ;
if ( V_10 -> V_18 . V_19 ) {
F_38 ( ( unsigned long ) V_10 -> V_18 . V_19 ) ;
V_10 -> V_18 . V_19 = NULL ;
}
F_15 ( V_17 ) ;
}
static void F_39 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_9 * V_10 = V_2 -> V_16 ;
F_40 ( & V_10 -> V_11 , V_2 , V_54 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_16 ;
F_25 ( V_2 ) ;
F_42 ( & V_10 -> V_11 ) ;
}
static int F_43 ( struct V_52 * V_11 , struct V_1 * V_2 )
{
struct V_9 * V_55 = F_36 ( V_11 , struct V_9 ,
V_11 ) ;
unsigned long V_17 , V_56 ;
int V_57 = 0 ;
V_56 = F_44 ( V_58 ) ;
if ( ! V_56 )
return - V_59 ;
F_13 ( V_17 ) ;
if ( V_55 -> V_18 . V_19 )
F_38 ( V_56 ) ;
else
V_55 -> V_18 . V_19 = ( unsigned char * ) V_56 ;
if ( V_55 -> V_7 ) {
V_57 = F_45 ( V_55 -> V_7 , F_8 , 0 ,
L_6 , V_55 ) ;
if ( V_57 )
goto V_60;
}
V_55 -> V_18 . V_20 = V_55 -> V_18 . V_21 = 0 ;
if ( ( V_11 -> V_17 & V_61 ) == V_62 )
V_2 -> V_63 = 57600 ;
if ( ( V_11 -> V_17 & V_61 ) == V_64 )
V_2 -> V_63 = 115200 ;
if ( ( V_11 -> V_17 & V_61 ) == V_65 )
V_2 -> V_63 = 230400 ;
if ( ( V_11 -> V_17 & V_61 ) == V_66 )
V_2 -> V_63 = 460800 ;
V_60:
F_15 ( V_17 ) ;
return V_57 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_9 * V_10 = V_67 + V_2 -> V_68 ;
struct V_52 * V_11 = & V_10 -> V_11 ;
V_2 -> V_16 = V_10 ;
V_2 -> V_69 = ( V_11 -> V_17 & V_70 ) ? 1 : 0 ;
V_27 = V_71 ;
while ( V_27 ) {
if ( ( V_27 -> V_17 & V_72 ) && V_27 -> V_28 ) break;
V_27 = V_27 -> V_73 ;
}
return F_47 ( V_11 , V_2 , V_54 ) ;
}
static int F_48 ( struct V_74 * V_75 , void * V_76 )
{
int V_77 ;
F_49 ( V_75 , L_7 ) ;
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ )
F_49 ( V_75 , L_8 ,
V_77 , V_67 [ V_77 ] . V_7 ) ;
return 0 ;
}
static int F_50 ( struct V_79 * V_79 , struct V_53 * V_53 )
{
return F_51 ( V_53 , F_48 , NULL ) ;
}
static int T_2 F_52 ( void )
{
struct V_9 * V_55 ;
int V_57 ;
if ( ! F_53 ( L_9 ) )
return - V_80 ;
V_81 = F_54 ( V_78 ) ;
if ( ! V_81 )
return - V_59 ;
F_10 ( V_12 L_10 ) ;
V_81 -> V_82 = L_6 ;
V_81 -> V_83 = L_11 ;
V_81 -> V_84 = V_85 ;
V_81 -> V_86 = 64 ;
V_81 -> type = V_87 ;
V_81 -> V_88 = V_89 ;
V_81 -> V_90 = V_91 ;
V_81 -> V_90 . V_49 =
V_92 | V_93 | V_94 | V_95 | V_96 ;
V_81 -> V_17 = V_97 ;
F_55 ( V_81 , & V_98 ) ;
V_55 = V_67 ;
F_56 ( & V_55 -> V_11 ) ;
V_55 -> V_11 . V_99 = & V_100 ;
V_55 -> V_11 . V_101 = 0 ;
V_57 = F_57 ( V_102 ) ;
if ( V_57 < 0 ) {
F_10 ( V_103 L_12 ,
V_13 ) ;
goto V_104;
}
V_55 -> V_7 = V_57 ;
F_10 ( V_12 L_13 , V_55 -> V_7 ) ;
V_57 = F_58 ( V_81 ) ;
if ( V_57 ) {
F_10 ( V_103 L_14 ) ;
goto V_104;
}
return 0 ;
V_104:
F_59 ( V_81 ) ;
return V_57 ;
}
