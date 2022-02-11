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
if ( V_10 -> V_16 . V_18 == V_10 -> V_16 . V_19 || V_13 -> V_28 ) {
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
! V_10 -> V_16 . V_17 )
return;
F_13 ( V_13 , V_10 , NULL ) ;
}
static int F_19 ( struct V_12 * V_13 ,
const unsigned char * V_17 , int V_22 )
{
struct V_9 * V_10 = V_13 -> V_14 ;
int V_24 , V_29 = 0 ;
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
V_29 += V_24 ;
}
F_12 ( V_15 ) ;
if ( F_17 ( V_10 -> V_16 . V_18 , V_10 -> V_16 . V_19 , V_20 ) &&
! V_13 -> V_28 )
F_13 ( V_13 , V_10 , NULL ) ;
return V_29 ;
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
F_15 ( V_30 L_2 ) ;
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
F_15 ( V_30 L_3 ) ;
}
static int F_31 ( struct V_12 * V_13 , unsigned int V_31 , unsigned long V_32 )
{
if ( ( V_31 != V_33 ) && ( V_31 != V_34 ) &&
( V_31 != V_35 ) && ( V_31 != V_36 ) &&
( V_31 != V_37 ) ) {
if ( V_13 -> V_15 & ( 1 << V_38 ) )
return - V_39 ;
}
switch ( V_31 ) {
case V_33 :
case V_34 :
case V_36 :
case V_37 :
return 0 ;
case V_35 :
case V_40 :
return - V_41 ;
case V_42 :
case V_43 :
F_15 ( V_30 L_4 ) ;
return 0 ;
}
return - V_44 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_33 ( V_2 , struct V_9 ,
V_2 ) ;
unsigned long V_15 ;
F_10 ( V_15 ) ;
if ( V_10 -> V_7 )
F_34 ( V_10 -> V_7 , V_10 ) ;
if ( V_10 -> V_16 . V_17 ) {
F_35 ( ( unsigned long ) V_10 -> V_16 . V_17 ) ;
V_10 -> V_16 . V_17 = NULL ;
}
F_12 ( V_15 ) ;
}
static void F_36 ( struct V_12 * V_13 , struct V_45 * V_46 )
{
struct V_9 * V_10 = V_13 -> V_14 ;
F_37 ( & V_10 -> V_2 , V_13 , V_46 ) ;
}
static void F_38 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_14 ;
F_23 ( V_13 ) ;
F_39 ( & V_10 -> V_2 ) ;
}
static int F_40 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_9 * V_47 = F_33 ( V_2 , struct V_9 ,
V_2 ) ;
unsigned long V_15 , V_48 ;
int V_49 = 0 ;
V_48 = F_41 ( V_50 ) ;
if ( ! V_48 )
return - V_51 ;
F_10 ( V_15 ) ;
if ( V_47 -> V_16 . V_17 )
F_35 ( V_48 ) ;
else
V_47 -> V_16 . V_17 = ( unsigned char * ) V_48 ;
if ( V_47 -> V_7 ) {
V_49 = F_42 ( V_47 -> V_7 , F_8 , 0 ,
L_5 , V_47 ) ;
if ( V_49 )
goto V_52;
}
V_47 -> V_16 . V_18 = V_47 -> V_16 . V_19 = 0 ;
if ( ( V_2 -> V_15 & V_53 ) == V_54 )
V_13 -> V_55 = 57600 ;
if ( ( V_2 -> V_15 & V_53 ) == V_56 )
V_13 -> V_55 = 115200 ;
if ( ( V_2 -> V_15 & V_53 ) == V_57 )
V_13 -> V_55 = 230400 ;
if ( ( V_2 -> V_15 & V_53 ) == V_58 )
V_13 -> V_55 = 460800 ;
V_52:
F_12 ( V_15 ) ;
return V_49 ;
}
static int F_43 ( struct V_12 * V_13 , struct V_45 * V_46 )
{
struct V_9 * V_10 = V_59 + V_13 -> V_60 ;
struct V_1 * V_2 = & V_10 -> V_2 ;
V_13 -> V_14 = V_10 ;
V_2 -> V_61 = ( V_2 -> V_15 & V_62 ) ? 1 : 0 ;
V_25 = V_63 ;
while ( V_25 ) {
if ( ( V_25 -> V_15 & V_64 ) && V_25 -> V_26 ) break;
V_25 = V_25 -> V_65 ;
}
return F_44 ( V_2 , V_13 , V_46 ) ;
}
static int F_45 ( struct V_66 * V_67 , void * V_68 )
{
int V_69 ;
F_46 ( V_67 , L_6 ) ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ )
F_46 ( V_67 , L_7 ,
V_69 , V_59 [ V_69 ] . V_7 ) ;
return 0 ;
}
static int F_47 ( struct V_71 * V_71 , struct V_45 * V_45 )
{
return F_48 ( V_45 , F_45 , NULL ) ;
}
static int T_2 F_49 ( void )
{
struct V_9 * V_47 ;
int V_49 ;
if ( ! F_50 ( L_8 ) )
return - V_72 ;
V_73 = F_51 ( V_70 ) ;
if ( ! V_73 )
return - V_51 ;
F_15 ( V_30 L_9 ) ;
V_73 -> V_74 = L_5 ;
V_73 -> V_75 = L_10 ;
V_73 -> V_76 = V_77 ;
V_73 -> V_78 = 64 ;
V_73 -> type = V_79 ;
V_73 -> V_80 = V_81 ;
V_73 -> V_82 = V_83 ;
V_73 -> V_82 . V_84 =
V_85 | V_86 | V_87 | V_88 | V_89 ;
V_73 -> V_15 = V_90 ;
F_52 ( V_73 , & V_91 ) ;
V_47 = V_59 ;
F_53 ( & V_47 -> V_2 ) ;
V_47 -> V_2 . V_92 = & V_93 ;
V_47 -> V_2 . V_94 = 0 ;
V_49 = F_54 ( V_95 ) ;
if ( V_49 < 0 ) {
F_15 ( V_96 L_11 ,
V_97 ) ;
goto V_98;
}
V_47 -> V_7 = V_49 ;
F_15 ( V_30 L_12 , V_47 -> V_7 ) ;
F_55 ( & V_47 -> V_2 , V_73 , 0 ) ;
V_49 = F_56 ( V_73 ) ;
if ( V_49 ) {
F_15 ( V_96 L_13 ) ;
goto V_98;
}
return 0 ;
V_98:
F_57 ( V_73 ) ;
F_58 ( & V_47 -> V_2 ) ;
return V_49 ;
}
