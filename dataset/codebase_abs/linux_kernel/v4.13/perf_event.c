const char * F_1 ( void )
{
if ( ! V_1 )
return NULL ;
return V_1 -> V_2 ;
}
int F_2 ( void )
{
if ( V_1 )
return V_1 -> V_3 ;
return 0 ;
}
static inline int F_3 ( void )
{
return ! ! V_1 ;
}
static void F_4 ( void )
{
int V_4 ;
unsigned int V_5 = ( V_1 -> V_5 &
( V_6 | V_7 ) ) >>
V_8 ;
if ( V_5 < 0x0104 )
return;
V_4 = F_5 ( 17 ) ;
if ( V_4 >= 0 )
F_6 ( V_4 , ( void * ) 1 ) ;
V_4 = F_5 ( 16 ) ;
if ( V_4 >= 0 )
F_6 ( V_4 , ( void * ) 0 ) ;
}
static int F_7 ( void )
{
int V_9 = 0 , V_4 [ 2 ] ;
unsigned int V_5 = ( V_1 -> V_5 &
( V_6 | V_7 ) ) >>
V_8 ;
if ( V_5 < 0x0104 )
goto V_10;
V_4 [ 0 ] = F_5 ( 16 ) ;
if ( V_4 [ 0 ] < 0 ) {
F_8 ( L_1 , 16 ) ;
goto V_10;
}
V_9 = F_9 ( V_4 [ 0 ] , V_1 -> V_11 , V_12 ,
L_2 , ( void * ) 0 ) ;
if ( V_9 ) {
F_8 ( L_3 ,
V_4 [ 0 ] ) ;
goto V_10;
}
V_4 [ 1 ] = F_5 ( 17 ) ;
if ( V_4 [ 1 ] < 0 ) {
F_8 ( L_1 , 17 ) ;
goto V_13;
}
V_9 = F_9 ( V_4 [ 1 ] , V_1 -> V_11 , V_12 ,
L_4 , ( void * ) 1 ) ;
if ( V_9 ) {
F_8 ( L_3 ,
V_4 [ 1 ] ) ;
goto V_13;
}
return 0 ;
V_13:
F_6 ( V_4 [ 0 ] , ( void * ) 0 ) ;
V_10:
return V_9 ;
}
static void F_10 ( struct V_14 * V_14 )
{
}
static void F_11 ( struct V_14 * V_14 )
{
}
static int F_12 ( struct V_15 * V_16 )
{
int V_9 = 0 ;
T_1 * V_17 = & V_1 -> V_17 ;
if ( ! F_3 () ) {
V_9 = - V_18 ;
goto V_10;
}
if ( F_13 ( V_16 ) )
return - V_19 ;
V_16 -> V_20 = V_21 ;
if ( ! F_14 ( V_17 ) ) {
F_15 ( & V_1 -> V_22 ) ;
if ( F_16 ( V_17 ) == 0 )
V_9 = F_7 () ;
if ( ! V_9 )
F_17 ( V_17 ) ;
F_18 ( & V_1 -> V_22 ) ;
}
switch ( V_16 -> V_23 . type ) {
case V_24 :
case V_25 :
case V_26 :
V_9 = F_19 ( V_16 ) ;
break;
default:
return - V_27 ;
}
if ( V_9 )
V_16 -> V_20 ( V_16 ) ;
V_10:
return V_9 ;
}
void F_20 ( struct V_15 * V_16 ,
struct V_28 * V_29 , int V_30 )
{
T_2 V_31 , V_32 ;
T_3 V_33 ;
V_34:
V_31 = F_21 ( & V_29 -> V_35 ) ;
V_32 = V_1 -> V_36 ( V_30 ) ;
if ( F_22 ( & V_29 -> V_35 , V_31 ,
V_32 ) != V_31 )
goto V_34;
V_33 = ( V_32 - V_31 ) & V_37 ;
F_23 ( V_33 , & V_16 -> V_38 ) ;
F_24 ( V_33 , & V_29 -> V_39 ) ;
}
int F_25 ( struct V_15 * V_16 ,
struct V_28 * V_29 , int V_30 )
{
T_3 V_40 = F_21 ( & V_29 -> V_39 ) ;
T_3 V_41 = V_29 -> V_42 ;
int V_43 = 0 ;
if ( F_26 ( V_41 != V_29 -> V_44 ) )
V_40 += V_41 - V_29 -> V_44 ;
if ( F_26 ( V_40 <= - V_41 ) ) {
V_40 = V_41 ;
F_27 ( & V_29 -> V_39 , V_40 ) ;
V_29 -> V_44 = V_41 ;
V_43 = 1 ;
}
if ( F_26 ( V_40 <= 0 ) ) {
V_40 += V_41 ;
F_27 ( & V_29 -> V_39 , V_40 ) ;
V_29 -> V_44 = V_41 ;
V_43 = 1 ;
}
if ( V_40 > ( T_3 ) V_1 -> V_45 )
V_40 = V_1 -> V_45 ;
if ( V_1 -> V_46 ) {
F_27 ( & V_29 -> V_35 , - ( V_47 ) V_40 ) ;
V_1 -> V_46 ( V_30 , - V_40 & V_37 ) ;
}
F_28 ( V_16 ) ;
return V_43 ;
}
static void F_29 ( struct V_15 * V_16 , int V_48 )
{
struct V_49 * V_50 = F_30 ( & V_49 ) ;
struct V_28 * V_29 = & V_16 -> V_51 ;
int V_30 = V_29 -> V_30 ;
if ( F_31 ( V_30 == - 1 ) )
return;
if ( V_48 & V_52 )
F_31 ( ! ( V_29 -> V_53 & V_54 ) ) ;
V_29 -> V_53 = 0 ;
if ( V_1 -> V_45 )
F_25 ( V_16 , V_29 , V_29 -> V_30 ) ;
V_50 -> V_55 [ V_30 ] = V_16 ;
V_1 -> V_56 ( V_29 , V_30 ) ;
}
static void F_32 ( struct V_15 * V_16 , int V_48 )
{
struct V_28 * V_29 = & V_16 -> V_51 ;
if ( ! ( V_29 -> V_53 & V_57 ) ) {
F_20 ( V_16 , V_29 , V_29 -> V_30 ) ;
V_1 -> V_58 ( V_29 , V_29 -> V_30 ) ;
V_29 -> V_53 |= V_57 | V_54 ;
}
}
static int F_33 ( struct V_15 * V_16 , int V_48 )
{
struct V_49 * V_50 = F_30 ( & V_49 ) ;
struct V_28 * V_29 = & V_16 -> V_51 ;
int V_30 = 0 , V_43 = 0 ;
F_34 ( V_16 -> V_14 ) ;
if ( V_29 -> V_59 == 0x100 ) {
if ( F_35 ( V_60 ,
V_50 -> V_61 ) ) {
V_43 = - V_62 ;
goto V_10;
}
V_30 = V_60 ;
} else {
V_30 = F_36 ( V_50 -> V_61 ,
F_16 ( & V_1 -> V_17 ) ) ;
if ( V_30 >= V_60 ) {
V_43 = - V_62 ;
goto V_10;
}
F_37 ( V_30 , V_50 -> V_61 ) ;
}
V_29 -> V_30 = V_30 ;
V_1 -> V_58 ( V_29 , V_30 ) ;
V_29 -> V_53 = V_57 | V_54 ;
if ( V_48 & V_63 )
F_29 ( V_16 , V_52 ) ;
F_28 ( V_16 ) ;
V_10:
F_38 ( V_16 -> V_14 ) ;
return V_43 ;
}
static void F_39 ( struct V_15 * V_16 , int V_48 )
{
struct V_49 * V_50 = F_30 ( & V_49 ) ;
struct V_28 * V_29 = & V_16 -> V_51 ;
int V_30 = V_29 -> V_30 ;
F_40 ( V_30 < 0 ) ;
F_32 ( V_16 , V_64 ) ;
V_50 -> V_55 [ V_30 ] = NULL ;
F_41 ( V_30 , V_50 -> V_61 ) ;
F_28 ( V_16 ) ;
}
static void F_42 ( struct V_15 * V_16 )
{
struct V_28 * V_29 = & V_16 -> V_51 ;
if ( V_29 -> V_30 < 0 )
return;
F_20 ( V_16 , V_29 , V_29 -> V_30 ) ;
}
static void V_21 ( struct V_15 * V_16 )
{
T_1 * V_17 = & V_1 -> V_17 ;
struct V_65 * V_66 = & V_1 -> V_22 ;
if ( F_43 ( V_17 , V_66 ) ) {
F_4 () ;
F_18 ( V_66 ) ;
}
}
static int F_44 ( int V_59 , int * V_67 )
{
unsigned long type , V_68 , V_69 ;
int V_70 ;
if ( ! V_1 -> V_71 )
return - V_72 ;
type = V_59 & 0xff ;
V_68 = ( V_59 >> 8 ) & 0xff ;
V_69 = ( V_59 >> 16 ) & 0xff ;
if ( type >= V_73 ||
V_68 >= V_74 ||
V_69 >= V_75 )
return - V_72 ;
V_70 = ( * V_1 -> V_71 ) [ type ] [ V_68 ] [ V_69 ] ;
if ( V_70 == 0 )
return - V_19 ;
if ( V_70 == - 1 )
return - V_72 ;
* V_67 = V_70 ;
return 0 ;
}
static int F_19 ( struct V_15 * V_16 )
{
struct V_76 * V_23 = & V_16 -> V_23 ;
struct V_28 * V_29 = & V_16 -> V_51 ;
int V_77 = 0 , V_9 ;
switch ( V_23 -> type ) {
case V_24 :
if ( V_23 -> V_59 >= V_78 )
return - V_72 ;
V_77 = V_1 -> V_79 ( V_23 -> V_59 ) ;
break;
case V_25 :
V_9 = F_44 ( V_23 -> V_59 , & V_77 ) ;
if ( V_9 )
return V_9 ;
break;
case V_26 :
V_77 = V_23 -> V_59 ;
break;
}
if ( V_77 == - 1 )
return - V_72 ;
V_29 -> V_30 = - 1 ;
V_29 -> V_59 |= ( unsigned long ) V_77 ;
if ( V_1 -> V_45 ) {
if ( ! V_29 -> V_42 ) {
V_29 -> V_42 = V_1 -> V_45 >> 1 ;
V_29 -> V_44 = V_29 -> V_42 ;
F_27 ( & V_29 -> V_39 , V_29 -> V_42 ) ;
}
}
return 0 ;
}
static void F_45 ( struct V_28 * V_16 , int V_30 )
{
struct V_49 * V_55 = F_30 ( & V_49 ) ;
unsigned int V_59 = V_16 -> V_59 ;
unsigned int V_80 = V_59 & 0xf0 ;
unsigned long V_48 ;
F_46 ( & V_55 -> V_81 , V_48 ) ;
if ( V_60 == V_30 ) {
F_47 ( ( V_59 != 0x100 ) ,
L_5 ,
V_59 , V_30 ) ;
F_27 ( & V_16 -> V_35 , F_48 ( V_82 ) ) ;
goto V_83;
}
if ( V_80 ) {
#ifdef F_49
void * V_84 ;
switch ( V_80 ) {
case 0xd0 :
V_84 = ( void * ) F_50 ( V_30 ) ;
break;
case 0xf0 :
V_84 = ( void * ) F_51 ( V_30 ) ;
break;
default:
V_84 = NULL ;
break;
}
if ( V_84 )
F_52 ( ( V_59 & 0x0f ) , V_84 ) ;
#endif
V_59 = V_80 >> 4 ;
}
V_80 = ( ( V_59 & 0xf ) << 28 ) |
( ( 1 << 24 ) << F_53 () ) ;
if ( V_1 -> V_45 )
V_80 |= F_54 ( F_55 ( V_30 ) ) & 0x00ffffff ;
else
F_27 ( & V_16 -> V_35 , 0 ) ;
F_52 ( V_80 , F_55 ( V_30 ) ) ;
V_83:
F_56 ( & V_55 -> V_81 , V_48 ) ;
}
static void F_57 ( struct V_28 * V_16 , int V_30 )
{
struct V_49 * V_55 = F_30 ( & V_49 ) ;
unsigned int V_80 = 0 ;
unsigned long V_48 ;
if ( V_60 == V_30 )
return;
F_46 ( & V_55 -> V_81 , V_48 ) ;
V_80 = F_54 ( F_55 ( V_30 ) ) ;
V_80 &= 0x00ffffff ;
F_52 ( V_80 , F_55 ( V_30 ) ) ;
F_56 ( & V_55 -> V_81 , V_48 ) ;
}
static T_2 F_58 ( int V_30 )
{
T_4 V_80 = 0 ;
if ( V_60 == V_30 ) {
V_80 = F_48 ( V_82 ) ;
goto V_10;
}
V_80 = F_54 ( F_55 ( V_30 ) ) & 0x00ffffff ;
V_10:
return V_80 ;
}
static void F_59 ( int V_30 , T_4 V_85 )
{
struct V_49 * V_55 = F_30 ( & V_49 ) ;
T_4 V_80 = 0 ;
unsigned long V_48 ;
if ( V_60 == V_30 )
return;
F_46 ( & V_55 -> V_81 , V_48 ) ;
V_85 &= 0x00ffffff ;
V_80 = F_54 ( F_55 ( V_30 ) ) & 0xff000000 ;
V_85 |= V_80 ;
F_52 ( V_85 , F_55 ( V_30 ) ) ;
F_56 ( & V_55 -> V_81 , V_48 ) ;
}
static int F_60 ( int V_30 )
{
return V_86 [ V_30 ] ;
}
static T_5 F_61 ( int V_4 , void * V_87 )
{
int V_30 = ( int ) V_87 ;
struct V_49 * V_88 = F_30 ( & V_49 ) ;
struct V_15 * V_16 = V_88 -> V_55 [ V_30 ] ;
struct V_28 * V_29 = & V_16 -> V_51 ;
struct V_89 * V_90 = F_62 () ;
struct V_91 V_92 ;
unsigned long V_48 ;
T_4 V_93 = 0 ;
F_63 ( V_48 ) ;
V_93 = F_54 ( F_55 ( V_30 ) ) ;
F_52 ( ( V_93 & 0x00ffffff ) , F_55 ( V_30 ) ) ;
F_64 ( V_48 ) ;
F_20 ( V_16 , V_29 , V_30 ) ;
F_65 ( & V_92 , 0 , V_29 -> V_44 ) ;
F_25 ( V_16 , V_29 , V_30 ) ;
if ( ! F_66 ( V_16 , & V_92 , V_90 ) ) {
F_63 ( V_48 ) ;
V_93 = ( V_93 & 0xff000000 ) |
( F_54 ( F_55 ( V_30 ) ) & 0x00ffffff ) ;
F_52 ( V_93 , F_55 ( V_30 ) ) ;
F_64 ( V_48 ) ;
}
return V_94 ;
}
static int F_67 ( unsigned int V_95 )
{
struct V_49 * V_50 = & F_68 ( V_49 , V_95 ) ;
memset ( V_50 , 0 , sizeof( struct V_49 ) ) ;
F_69 ( & V_50 -> V_81 ) ;
return 0 ;
}
static int T_6 F_70 ( void )
{
int V_43 = 0 , V_95 ;
T_4 V_5 = * ( T_4 * ) V_96 ;
int V_97 = ( V_5 & V_98 ) >> V_99 ;
int V_100 = ( V_5 & ( V_6 | V_7 ) )
>> V_8 ;
if ( 0x02 > V_97 ) {
F_71 ( L_6 ) ;
goto V_10;
} else if ( 0x02 == V_97 ) {
V_1 = & V_101 ;
if ( V_100 < 0x0104 ) {
V_1 -> V_11 = NULL ;
V_1 -> V_46 = NULL ;
V_1 -> V_45 = 0 ;
}
V_1 -> V_2 = L_7 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_14 = V_14 ;
}
F_71 ( L_8 ,
V_1 -> V_2 , V_1 -> V_3 ) ;
if ( V_1 -> V_45 == 0 ) {
V_1 -> V_14 . V_102 |= V_103 ;
}
F_72 ( & V_1 -> V_17 , 0 ) ;
F_73 ( & V_1 -> V_22 ) ;
F_52 ( 0 , F_55 ( 0 ) ) ;
F_52 ( 0 , F_55 ( 1 ) ) ;
F_74 ( V_104 ,
L_9 , F_67 ,
NULL ) ;
V_43 = F_75 ( & V_14 , V_1 -> V_2 , V_26 ) ;
if ( V_43 )
F_76 ( V_104 ) ;
return V_43 ;
}
