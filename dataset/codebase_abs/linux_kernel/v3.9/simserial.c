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
F_1 ( & V_10 -> V_2 ) ;
return V_11 ;
}
static int F_9 ( struct V_12 * V_13 , unsigned char V_3 )
{
struct V_9 * V_10 = V_13 -> V_14 ;
unsigned long V_15 ;
if ( ! V_10 -> V_16 . V_17 )
return 0 ;
F_10 ( V_15 ) ;
if ( F_11 ( V_10 -> V_16 . V_18 , V_10 -> V_16 . V_19 , V_20 ) == 0 ) {
F_12 ( V_15 ) ;
return 0 ;
}
V_10 -> V_16 . V_17 [ V_10 -> V_16 . V_18 ] = V_3 ;
V_10 -> V_16 . V_18 = ( V_10 -> V_16 . V_18 + 1 ) & ( V_20 - 1 ) ;
F_12 ( V_15 ) ;
return 1 ;
}
static void F_13 ( struct V_12 * V_13 , struct V_9 * V_10 ,
int * V_21 )
{
int V_22 ;
unsigned long V_15 ;
F_10 ( V_15 ) ;
if ( V_10 -> V_23 ) {
char V_24 = V_10 -> V_23 ;
V_25 -> V_26 ( V_25 , & V_24 , 1 ) ;
V_10 -> V_23 = 0 ;
goto V_27;
}
if ( V_10 -> V_16 . V_18 == V_10 -> V_16 . V_19 || V_13 -> V_28 ||
V_13 -> V_29 ) {
#ifdef F_14
F_15 ( L_1 ,
V_10 -> V_16 . V_18 , V_10 -> V_16 . V_19 , V_13 -> V_28 ) ;
#endif
goto V_27;
}
V_22 = F_16 ( F_17 ( V_10 -> V_16 . V_18 , V_10 -> V_16 . V_19 , V_20 ) ,
V_20 - V_10 -> V_16 . V_19 ) ;
V_25 -> V_26 ( V_25 , V_10 -> V_16 . V_17 + V_10 -> V_16 . V_19 , V_22 ) ;
V_10 -> V_16 . V_19 = ( V_10 -> V_16 . V_19 + V_22 ) & ( V_20 - 1 ) ;
V_22 = F_17 ( V_10 -> V_16 . V_18 , V_10 -> V_16 . V_19 , V_20 ) ;
if ( V_22 ) {
V_25 -> V_26 ( V_25 , V_10 -> V_16 . V_17 , V_22 ) ;
V_10 -> V_16 . V_19 += V_22 ;
}
V_27:
F_12 ( V_15 ) ;
}
static void F_18 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_14 ;
if ( V_10 -> V_16 . V_18 == V_10 -> V_16 . V_19 || V_13 -> V_28 ||
V_13 -> V_29 || ! V_10 -> V_16 . V_17 )
return;
F_13 ( V_13 , V_10 , NULL ) ;
}
static int F_19 ( struct V_12 * V_13 ,
const unsigned char * V_17 , int V_22 )
{
struct V_9 * V_10 = V_13 -> V_14 ;
int V_24 , V_30 = 0 ;
unsigned long V_15 ;
if ( ! V_10 -> V_16 . V_17 )
return 0 ;
F_10 ( V_15 ) ;
while ( 1 ) {
V_24 = F_20 ( V_10 -> V_16 . V_18 , V_10 -> V_16 . V_19 , V_20 ) ;
if ( V_22 < V_24 )
V_24 = V_22 ;
if ( V_24 <= 0 ) {
break;
}
memcpy ( V_10 -> V_16 . V_17 + V_10 -> V_16 . V_18 , V_17 , V_24 ) ;
V_10 -> V_16 . V_18 = ( ( V_10 -> V_16 . V_18 + V_24 ) &
( V_20 - 1 ) ) ;
V_17 += V_24 ;
V_22 -= V_24 ;
V_30 += V_24 ;
}
F_12 ( V_15 ) ;
if ( F_17 ( V_10 -> V_16 . V_18 , V_10 -> V_16 . V_19 , V_20 ) &&
! V_13 -> V_28 && ! V_13 -> V_29 )
F_13 ( V_13 , V_10 , NULL ) ;
return V_30 ;
}
static int F_21 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_14 ;
return F_11 ( V_10 -> V_16 . V_18 , V_10 -> V_16 . V_19 , V_20 ) ;
}
static int F_22 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_14 ;
return F_17 ( V_10 -> V_16 . V_18 , V_10 -> V_16 . V_19 , V_20 ) ;
}
static void F_23 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_14 ;
unsigned long V_15 ;
F_10 ( V_15 ) ;
V_10 -> V_16 . V_18 = V_10 -> V_16 . V_19 = 0 ;
F_12 ( V_15 ) ;
F_24 ( V_13 ) ;
}
static void F_25 ( struct V_12 * V_13 , char V_3 )
{
struct V_9 * V_10 = V_13 -> V_14 ;
V_10 -> V_23 = V_3 ;
if ( V_3 ) {
F_13 ( V_13 , V_10 , NULL ) ;
}
}
static void F_26 ( struct V_12 * V_13 )
{
if ( F_27 ( V_13 ) )
F_25 ( V_13 , F_28 ( V_13 ) ) ;
F_15 ( V_31 L_2 ) ;
}
static void F_29 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_14 ;
if ( F_27 ( V_13 ) ) {
if ( V_10 -> V_23 )
V_10 -> V_23 = 0 ;
else
F_25 ( V_13 , F_30 ( V_13 ) ) ;
}
F_15 ( V_31 L_3 ) ;
}
static int F_31 ( struct V_12 * V_13 , unsigned int V_32 , unsigned long V_33 )
{
if ( ( V_32 != V_34 ) && ( V_32 != V_35 ) &&
( V_32 != V_36 ) && ( V_32 != V_37 ) &&
( V_32 != V_38 ) ) {
if ( V_13 -> V_15 & ( 1 << V_39 ) )
return - V_40 ;
}
switch ( V_32 ) {
case V_34 :
case V_35 :
case V_37 :
case V_38 :
return 0 ;
case V_36 :
case V_41 :
return - V_42 ;
case V_43 :
case V_44 :
F_15 ( V_31 L_4 ) ;
return 0 ;
}
return - V_45 ;
}
static void F_32 ( struct V_12 * V_13 , struct V_46 * V_47 )
{
if ( ( V_47 -> V_48 & V_49 ) &&
! ( V_13 -> V_50 . V_48 & V_49 ) ) {
V_13 -> V_29 = 0 ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_34 ( V_2 , struct V_9 ,
V_2 ) ;
unsigned long V_15 ;
F_10 ( V_15 ) ;
if ( V_10 -> V_7 )
F_35 ( V_10 -> V_7 , V_10 ) ;
if ( V_10 -> V_16 . V_17 ) {
F_36 ( ( unsigned long ) V_10 -> V_16 . V_17 ) ;
V_10 -> V_16 . V_17 = NULL ;
}
F_12 ( V_15 ) ;
}
static void F_37 ( struct V_12 * V_13 , struct V_51 * V_52 )
{
struct V_9 * V_10 = V_13 -> V_14 ;
F_38 ( & V_10 -> V_2 , V_13 , V_52 ) ;
}
static void F_39 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_14 ;
F_23 ( V_13 ) ;
F_40 ( & V_10 -> V_2 ) ;
}
static int F_41 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_9 * V_53 = F_34 ( V_2 , struct V_9 ,
V_2 ) ;
unsigned long V_15 , V_54 ;
int V_55 = 0 ;
V_54 = F_42 ( V_56 ) ;
if ( ! V_54 )
return - V_57 ;
F_10 ( V_15 ) ;
if ( V_53 -> V_16 . V_17 )
F_36 ( V_54 ) ;
else
V_53 -> V_16 . V_17 = ( unsigned char * ) V_54 ;
if ( V_53 -> V_7 ) {
V_55 = F_43 ( V_53 -> V_7 , F_8 , 0 ,
L_5 , V_53 ) ;
if ( V_55 )
goto V_58;
}
V_53 -> V_16 . V_18 = V_53 -> V_16 . V_19 = 0 ;
if ( ( V_2 -> V_15 & V_59 ) == V_60 )
V_13 -> V_61 = 57600 ;
if ( ( V_2 -> V_15 & V_59 ) == V_62 )
V_13 -> V_61 = 115200 ;
if ( ( V_2 -> V_15 & V_59 ) == V_63 )
V_13 -> V_61 = 230400 ;
if ( ( V_2 -> V_15 & V_59 ) == V_64 )
V_13 -> V_61 = 460800 ;
V_58:
F_12 ( V_15 ) ;
return V_55 ;
}
static int F_44 ( struct V_12 * V_13 , struct V_51 * V_52 )
{
struct V_9 * V_10 = V_65 + V_13 -> V_66 ;
struct V_1 * V_2 = & V_10 -> V_2 ;
V_13 -> V_14 = V_10 ;
V_2 -> V_67 = ( V_2 -> V_15 & V_68 ) ? 1 : 0 ;
V_25 = V_69 ;
while ( V_25 ) {
if ( ( V_25 -> V_15 & V_70 ) && V_25 -> V_26 ) break;
V_25 = V_25 -> V_71 ;
}
return F_45 ( V_2 , V_13 , V_52 ) ;
}
static int F_46 ( struct V_72 * V_73 , void * V_74 )
{
int V_75 ;
F_47 ( V_73 , L_6 ) ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ )
F_47 ( V_73 , L_7 ,
V_75 , V_65 [ V_75 ] . V_7 ) ;
return 0 ;
}
static int F_48 ( struct V_77 * V_77 , struct V_51 * V_51 )
{
return F_49 ( V_51 , F_46 , NULL ) ;
}
static int T_2 F_50 ( void )
{
struct V_9 * V_53 ;
int V_55 ;
if ( ! F_51 ( L_8 ) )
return - V_78 ;
V_79 = F_52 ( V_76 ) ;
if ( ! V_79 )
return - V_57 ;
F_15 ( V_31 L_9 ) ;
V_79 -> V_80 = L_5 ;
V_79 -> V_81 = L_10 ;
V_79 -> V_82 = V_83 ;
V_79 -> V_84 = 64 ;
V_79 -> type = V_85 ;
V_79 -> V_86 = V_87 ;
V_79 -> V_88 = V_89 ;
V_79 -> V_88 . V_48 =
V_90 | V_91 | V_92 | V_93 | V_94 ;
V_79 -> V_15 = V_95 ;
F_53 ( V_79 , & V_96 ) ;
V_53 = V_65 ;
F_54 ( & V_53 -> V_2 ) ;
V_53 -> V_2 . V_97 = & V_98 ;
V_53 -> V_2 . V_99 = 0 ;
V_55 = F_55 ( V_100 ) ;
if ( V_55 < 0 ) {
F_15 ( V_101 L_11 ,
V_102 ) ;
goto V_103;
}
V_53 -> V_7 = V_55 ;
F_15 ( V_31 L_12 , V_53 -> V_7 ) ;
F_56 ( & V_53 -> V_2 , V_79 , 0 ) ;
V_55 = F_57 ( V_79 ) ;
if ( V_55 ) {
F_15 ( V_101 L_13 ) ;
goto V_103;
}
return 0 ;
V_103:
F_58 ( V_79 ) ;
F_59 ( & V_53 -> V_2 ) ;
return V_55 ;
}
