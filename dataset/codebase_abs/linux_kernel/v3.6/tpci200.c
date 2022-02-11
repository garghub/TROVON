static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_5 = 0 ;
if ( V_3 == NULL )
return NULL ;
F_2 (tpci200, &tpci200_list, list) {
if ( V_4 -> V_6 == V_3 -> V_7 ) {
V_5 = 1 ;
break;
}
}
if ( ! V_5 ) {
F_3 ( & V_3 -> V_3 , L_1 ) ;
return NULL ;
}
if ( V_3 -> V_8 >= V_9 ) {
F_4 ( & V_3 -> V_3 ,
L_2 ,
V_3 -> V_7 , V_3 -> V_8 , V_9 - 1 ) ;
return NULL ;
}
return V_4 ;
}
static inline unsigned char F_5 ( void T_1 * V_10 ,
unsigned long V_11 )
{
return F_6 ( V_10 + ( V_11 ^ 1 ) ) ;
}
static inline unsigned short F_7 ( void T_1 * V_10 ,
unsigned long V_11 )
{
return F_8 ( V_10 + V_11 ) ;
}
static inline unsigned int F_9 ( void T_1 * V_10 ,
unsigned long V_11 )
{
return F_10 ( F_11 ( V_10 + V_11 ) ) ;
}
static inline void F_12 ( unsigned char V_12 ,
void T_1 * V_10 , unsigned long V_11 )
{
F_13 ( V_12 , V_10 + ( V_11 ^ 1 ) ) ;
}
static inline void F_14 ( unsigned short V_12 ,
void T_1 * V_10 ,
unsigned long V_11 )
{
F_15 ( V_12 , V_10 + V_11 ) ;
}
static inline void F_16 ( unsigned int V_12 ,
void T_1 * V_10 ,
unsigned long V_11 )
{
F_17 ( F_10 ( V_12 ) , V_10 + V_11 ) ;
}
static struct V_13 * F_18 ( struct V_2 * V_3 ,
int V_14 )
{
struct V_13 * V_15 ;
switch ( V_14 ) {
case V_16 :
V_15 = & V_3 -> V_17 ;
break;
case V_18 :
V_15 = & V_3 -> V_19 ;
break;
case V_20 :
V_15 = & V_3 -> V_21 ;
break;
default:
F_3 ( & V_3 -> V_3 ,
L_3 ,
V_3 -> V_7 , V_3 -> V_8 , V_14 ) ;
return NULL ;
break;
}
if ( ( V_15 -> V_22 == 0 ) || ( V_15 -> V_10 == NULL ) ) {
F_3 ( & V_3 -> V_3 , L_4 ) ;
return NULL ;
}
return V_15 ;
}
static int F_19 ( struct V_2 * V_3 , int V_14 ,
unsigned long V_11 , unsigned char * V_12 )
{
struct V_13 * V_15 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_23 ;
V_15 = F_18 ( V_3 , V_14 ) ;
if ( V_15 == NULL )
return - V_23 ;
if ( V_11 >= V_15 -> V_22 ) {
F_3 ( & V_3 -> V_3 , L_5 ) ;
return - V_24 ;
}
* V_12 = F_5 ( V_15 -> V_10 , V_11 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , int V_14 ,
unsigned long V_11 , unsigned short * V_12 )
{
struct V_13 * V_15 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_23 ;
V_15 = F_18 ( V_3 , V_14 ) ;
if ( V_15 == NULL )
return - V_23 ;
if ( ( V_11 + 2 ) >= V_15 -> V_22 ) {
F_3 ( & V_3 -> V_3 , L_5 ) ;
return - V_24 ;
}
* V_12 = F_7 ( V_15 -> V_10 , V_11 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , int V_14 ,
unsigned long V_11 , unsigned int * V_12 )
{
struct V_13 * V_15 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_23 ;
V_15 = F_18 ( V_3 , V_14 ) ;
if ( V_15 == NULL )
return - V_23 ;
if ( ( V_11 + 4 ) >= V_15 -> V_22 ) {
F_3 ( & V_3 -> V_3 , L_5 ) ;
return - V_24 ;
}
* V_12 = F_9 ( V_15 -> V_10 , V_11 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , int V_14 ,
unsigned long V_11 , unsigned char V_12 )
{
struct V_13 * V_15 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_23 ;
V_15 = F_18 ( V_3 , V_14 ) ;
if ( V_15 == NULL )
return - V_23 ;
if ( V_11 >= V_15 -> V_22 ) {
F_3 ( & V_3 -> V_3 , L_5 ) ;
return - V_24 ;
}
F_12 ( V_12 , V_15 -> V_10 , V_11 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , int V_14 ,
unsigned long V_11 , unsigned short V_12 )
{
struct V_13 * V_15 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_23 ;
V_15 = F_18 ( V_3 , V_14 ) ;
if ( V_15 == NULL )
return - V_23 ;
if ( ( V_11 + 2 ) >= V_15 -> V_22 ) {
F_3 ( & V_3 -> V_3 , L_5 ) ;
return - V_24 ;
}
F_14 ( V_12 , V_15 -> V_10 , V_11 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , int V_14 ,
unsigned long V_11 , unsigned int V_12 )
{
struct V_13 * V_15 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_23 ;
V_15 = F_18 ( V_3 , V_14 ) ;
if ( V_15 == NULL )
return - V_23 ;
if ( ( V_11 + 4 ) >= V_15 -> V_22 ) {
F_3 ( & V_3 -> V_3 , L_5 ) ;
return - V_24 ;
}
F_16 ( V_12 , V_15 -> V_10 , V_11 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_4 )
{
int V_25 ;
F_26 ( V_4 -> V_26 -> V_27 -> V_28 , ( void * ) V_4 ) ;
F_27 ( V_4 -> V_26 -> V_27 , V_4 -> V_26 -> V_29 ) ;
F_27 ( V_4 -> V_26 -> V_27 , V_4 -> V_26 -> V_30 ) ;
F_27 ( V_4 -> V_26 -> V_27 , V_4 -> V_26 -> V_31 ) ;
F_28 ( V_4 -> V_26 -> V_27 , V_32 ) ;
F_28 ( V_4 -> V_26 -> V_27 , V_33 ) ;
F_28 ( V_4 -> V_26 -> V_27 , V_34 ) ;
F_29 ( V_4 -> V_26 -> V_27 ) ;
F_30 ( V_4 -> V_26 -> V_27 ) ;
for ( V_25 = 0 ; V_25 < V_9 ; V_25 ++ ) {
V_4 -> V_35 [ V_25 ] . V_36 . V_10 = NULL ;
V_4 -> V_35 [ V_25 ] . V_36 . V_22 = 0 ;
V_4 -> V_35 [ V_25 ] . V_37 . V_10 = NULL ;
V_4 -> V_35 [ V_25 ] . V_37 . V_22 = 0 ;
V_4 -> V_35 [ V_25 ] . V_38 . V_10 = NULL ;
V_4 -> V_35 [ V_25 ] . V_38 . V_22 = 0 ;
}
}
static T_2 F_31 ( int V_28 , void * V_39 )
{
struct V_1 * V_4 = (struct V_1 * ) V_39 ;
int V_25 ;
unsigned short V_40 , V_41 ;
unsigned short V_42 = 0 ;
T_2 V_43 = V_44 ;
V_40 = F_32 ( V_4 -> V_26 -> V_29 +
V_45 ) ;
if ( V_40 & V_46 ) {
V_42 = V_40 & V_46 ;
for ( V_25 = 0 ; V_25 < V_9 ; V_25 ++ ) {
if ( ( V_4 -> V_35 [ V_25 ] . V_28 != NULL ) &&
( V_40 & ( ( V_47 | V_48 ) << ( 2 * V_25 ) ) ) ) {
V_43 = V_4 -> V_35 [ V_25 ] . V_28 -> V_49 ( V_4 -> V_35 [ V_25 ] . V_28 -> V_50 ) ;
F_32 ( V_4 -> V_35 [ V_25 ] . V_3 -> V_17 . V_10 +
0xC0 ) ;
F_32 ( V_4 -> V_35 [ V_25 ] . V_3 -> V_17 . V_10 +
0xC2 ) ;
V_42 &= ~ ( ( ( V_47 | V_48 ) << ( 2 * V_25 ) ) ) ;
}
}
}
if ( V_42 ) {
for ( V_25 = 0 ; V_25 < V_9 ; V_25 ++ ) {
if ( V_42 & ( ( V_51 | V_52 ) << ( 2 * V_25 ) ) ) {
F_4 ( & V_4 -> V_35 [ V_25 ] . V_3 -> V_3 ,
L_6 ,
V_4 -> V_6 , V_25 ) ;
V_41 = F_32 (
V_4 -> V_26 -> V_29 +
V_53 [ V_25 ] ) ;
V_41 &=
~ ( V_51 | V_52 ) ;
F_33 ( V_41 ,
( V_4 -> V_26 -> V_29 +
V_53 [ V_25 ] ) ) ;
}
}
}
return V_43 ;
}
static int F_34 ( struct V_1 * V_4 )
{
int V_25 ;
int V_54 ;
unsigned long V_55 ;
unsigned long V_56 ;
unsigned short V_57 ;
if ( F_35 ( V_4 -> V_26 -> V_27 ) < 0 )
return - V_58 ;
V_54 = F_36 ( V_4 -> V_26 -> V_27 , V_32 ,
L_7 ) ;
if ( V_54 ) {
F_3 ( & V_4 -> V_26 -> V_27 -> V_3 ,
L_8 ,
V_4 -> V_26 -> V_27 -> V_59 -> V_6 ,
V_4 -> V_26 -> V_27 -> V_60 ) ;
goto V_61;
}
V_54 = F_36 ( V_4 -> V_26 -> V_27 ,
V_33 ,
L_9 ) ;
if ( V_54 ) {
F_3 ( & V_4 -> V_26 -> V_27 -> V_3 ,
L_10 ,
V_4 -> V_26 -> V_27 -> V_59 -> V_6 ,
V_4 -> V_26 -> V_27 -> V_60 ) ;
goto V_62;
}
V_54 = F_36 ( V_4 -> V_26 -> V_27 , V_34 ,
L_11 ) ;
if ( V_54 ) {
F_3 ( & V_4 -> V_26 -> V_27 -> V_3 ,
L_12 ,
V_4 -> V_26 -> V_27 -> V_59 -> V_6 ,
V_4 -> V_26 -> V_27 -> V_60 ) ;
goto V_63;
}
V_4 -> V_26 -> V_29 =
F_37 ( F_38 ( V_4 -> V_26 -> V_27 ,
V_32 ) ,
V_64 ) ;
V_4 -> V_26 -> V_30 =
F_37 ( F_38 ( V_4 -> V_26 -> V_27 ,
V_33 ) ,
V_65 ) ;
V_4 -> V_26 -> V_31 =
F_37 ( F_38 ( V_4 -> V_26 -> V_27 ,
V_34 ) ,
V_66 ) ;
V_55 = F_38 ( V_4 -> V_26 -> V_27 ,
V_33 ) ;
V_56 = F_38 ( V_4 -> V_26 -> V_27 ,
V_34 ) ;
V_57 = 0 ;
for ( V_25 = 0 ; V_25 < V_9 ; V_25 ++ ) {
V_4 -> V_35 [ V_25 ] . V_36 . V_10 =
( void T_1 * ) V_55 +
V_67 + V_68 * V_25 ;
V_4 -> V_35 [ V_25 ] . V_36 . V_22 = V_69 ;
V_4 -> V_35 [ V_25 ] . V_37 . V_10 =
( void T_1 * ) V_55 +
V_70 + V_71 * V_25 ;
V_4 -> V_35 [ V_25 ] . V_37 . V_22 = V_72 ;
V_4 -> V_35 [ V_25 ] . V_38 . V_10 =
( void T_1 * ) V_56 + V_73 * V_25 ;
V_4 -> V_35 [ V_25 ] . V_38 . V_22 = V_66 ;
F_33 ( V_57 , ( V_4 -> V_26 -> V_29 +
V_53 [ V_25 ] ) ) ;
}
V_54 = F_39 ( V_4 -> V_26 -> V_27 -> V_28 ,
F_31 , V_74 ,
V_75 , ( void * ) V_4 ) ;
if ( V_54 ) {
F_3 ( & V_4 -> V_26 -> V_27 -> V_3 ,
L_13 ,
V_4 -> V_26 -> V_27 -> V_59 -> V_6 ,
V_4 -> V_26 -> V_27 -> V_60 ) ;
goto V_63;
}
return 0 ;
V_63:
F_28 ( V_4 -> V_26 -> V_27 , V_33 ) ;
V_62:
F_28 ( V_4 -> V_26 -> V_27 , V_32 ) ;
V_61:
F_29 ( V_4 -> V_26 -> V_27 ) ;
return V_54 ;
}
static int F_40 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
unsigned short V_57 ;
V_57 = V_51 | V_52 ;
F_33 ( V_57 , ( V_4 -> V_26 -> V_29 +
V_53 [ V_3 -> V_8 ] ) ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
unsigned short V_57 ;
V_57 = 0 ;
F_33 ( V_57 , ( V_4 -> V_26 -> V_29 +
V_53 [ V_3 -> V_8 ] ) ) ;
}
static int F_42 ( struct V_2 * V_3 )
{
struct V_76 * V_76 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_23 ;
if ( F_43 ( & V_4 -> V_77 ) )
return - V_78 ;
if ( V_4 -> V_35 [ V_3 -> V_8 ] . V_28 == NULL ) {
F_44 ( & V_4 -> V_77 ) ;
return - V_23 ;
}
F_41 ( V_4 , V_3 ) ;
V_76 = V_4 -> V_35 [ V_3 -> V_8 ] . V_28 ;
V_4 -> V_35 [ V_3 -> V_8 ] . V_28 = NULL ;
F_45 ( V_76 ) ;
F_44 ( & V_4 -> V_77 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 , int V_14 )
{
struct V_13 * V_79 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_23 ;
if ( F_43 ( & V_4 -> V_77 ) )
return - V_78 ;
switch ( V_14 ) {
case V_16 :
if ( V_3 -> V_17 . V_10 == NULL ) {
F_4 ( & V_3 -> V_3 ,
L_14 ,
V_3 -> V_7 , V_3 -> V_8 ) ;
goto V_80;
}
V_79 = & V_3 -> V_17 ;
break;
case V_18 :
if ( V_3 -> V_19 . V_10 == NULL ) {
F_4 ( & V_3 -> V_3 ,
L_15 ,
V_3 -> V_7 , V_3 -> V_8 ) ;
goto V_80;
}
V_79 = & V_3 -> V_19 ;
break;
case V_20 :
if ( V_3 -> V_21 . V_10 == NULL ) {
F_4 ( & V_3 -> V_3 ,
L_16 ,
V_3 -> V_7 , V_3 -> V_8 ) ;
goto V_80;
}
V_79 = & V_3 -> V_21 ;
break;
default:
F_3 ( & V_3 -> V_3 ,
L_3 ,
V_3 -> V_7 , V_3 -> V_8 , V_14 ) ;
F_44 ( & V_4 -> V_77 ) ;
return - V_23 ;
}
F_47 ( V_79 -> V_10 ) ;
V_79 -> V_10 = NULL ;
V_79 -> V_22 = 0 ;
V_80:
F_44 ( & V_4 -> V_77 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( V_3 == NULL )
return - V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_23 ;
F_42 ( V_3 ) ;
if ( F_43 ( & V_4 -> V_77 ) )
return - V_78 ;
F_49 ( V_3 ) ;
V_4 -> V_35 [ V_3 -> V_8 ] . V_3 = NULL ;
F_44 ( & V_4 -> V_77 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_3 ,
unsigned int V_81 , int V_14 )
{
int V_54 = 0 ;
unsigned int V_82 ;
void T_1 * V_83 ;
struct V_13 * V_79 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_23 ;
if ( F_43 ( & V_4 -> V_77 ) )
return - V_78 ;
switch ( V_14 ) {
case V_16 :
if ( V_3 -> V_17 . V_10 != NULL ) {
F_3 ( & V_3 -> V_3 ,
L_17 ,
V_4 -> V_6 , V_3 -> V_8 ) ;
V_54 = - V_23 ;
goto V_80;
}
V_79 = & V_3 -> V_17 ;
V_83 = V_4 -> V_35 [ V_3 -> V_8 ] . V_36 . V_10 ;
V_82 = V_4 -> V_35 [ V_3 -> V_8 ] . V_36 . V_22 ;
break;
case V_18 :
if ( V_3 -> V_19 . V_10 != NULL ) {
F_3 ( & V_3 -> V_3 ,
L_18 ,
V_4 -> V_6 , V_3 -> V_8 ) ;
V_54 = - V_23 ;
goto V_80;
}
V_79 = & V_3 -> V_19 ;
V_83 = V_4 -> V_35 [ V_3 -> V_8 ] . V_37 . V_10 ;
V_82 = V_4 -> V_35 [ V_3 -> V_8 ] . V_37 . V_22 ;
break;
case V_20 :
if ( V_3 -> V_21 . V_10 != NULL ) {
F_3 ( & V_3 -> V_3 ,
L_19 ,
V_4 -> V_6 , V_3 -> V_8 ) ;
V_54 = - V_23 ;
goto V_80;
}
V_79 = & V_3 -> V_21 ;
if ( V_81 > V_4 -> V_35 [ V_3 -> V_8 ] . V_38 . V_22 ) {
F_3 ( & V_3 -> V_3 ,
L_20 ,
V_3 -> V_7 , V_3 -> V_8 , V_81 ,
V_4 -> V_35 [ V_3 -> V_8 ] . V_38 . V_22 ) ;
V_54 = - V_23 ;
goto V_80;
}
V_83 = V_4 -> V_35 [ V_3 -> V_8 ] . V_38 . V_10 ;
V_82 = V_81 ;
break;
default:
F_3 ( & V_3 -> V_3 , L_21 ,
V_4 -> V_6 , V_3 -> V_8 , V_14 ) ;
V_54 = - V_23 ;
goto V_80;
}
V_79 -> V_22 = V_82 ;
V_79 -> V_10 =
F_37 ( ( unsigned long ) V_83 , V_82 ) ;
V_80:
F_44 ( & V_4 -> V_77 ) ;
return V_54 ;
}
static int F_51 ( struct V_2 * V_3 , int V_84 ,
int (* V_49)( void * ) , void * V_50 )
{
int V_54 ;
struct V_76 * V_76 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_23 ;
if ( F_43 ( & V_4 -> V_77 ) )
return - V_78 ;
if ( V_4 -> V_35 [ V_3 -> V_8 ] . V_28 != NULL ) {
F_3 ( & V_3 -> V_3 ,
L_22 , V_3 -> V_7 ,
V_3 -> V_8 ) ;
V_54 = - V_23 ;
goto V_80;
}
V_76 = F_52 ( sizeof( struct V_76 ) , V_85 ) ;
if ( V_76 == NULL ) {
F_3 ( & V_3 -> V_3 ,
L_23 ,
V_3 -> V_7 , V_3 -> V_8 ) ;
V_54 = - V_86 ;
goto V_80;
}
V_76 -> V_84 = V_84 ;
V_76 -> V_49 = V_49 ;
V_76 -> V_50 = V_50 ;
V_4 -> V_35 [ V_3 -> V_8 ] . V_28 = V_76 ;
V_54 = F_40 ( V_4 , V_3 ) ;
V_80:
F_44 ( & V_4 -> V_77 ) ;
return V_54 ;
}
static void F_53 ( struct V_1 * V_4 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_9 ; V_25 ++ )
F_48 ( V_4 -> V_35 [ V_25 ] . V_3 ) ;
F_25 ( V_4 ) ;
F_45 ( V_4 -> V_35 ) ;
}
static int F_54 ( struct V_1 * V_4 )
{
int V_54 ;
V_4 -> V_35 = F_52 (
V_9 * sizeof( struct V_87 ) , V_85 ) ;
if ( V_4 -> V_35 == NULL )
return - V_86 ;
V_54 = F_34 ( V_4 ) ;
if ( V_54 ) {
F_45 ( V_4 -> V_35 ) ;
V_4 -> V_35 = NULL ;
return V_54 ;
}
F_55 ( & V_4 -> V_77 ) ;
return 0 ;
}
static int F_56 ( struct V_88 * V_27 ,
const struct V_89 * V_90 )
{
int V_43 , V_25 ;
struct V_1 * V_4 ;
V_4 = F_52 ( sizeof( struct V_1 ) , V_85 ) ;
if ( ! V_4 )
return - V_86 ;
V_4 -> V_26 = F_52 ( sizeof( struct V_91 ) , V_85 ) ;
if ( ! V_4 -> V_26 ) {
F_45 ( V_4 ) ;
return - V_86 ;
}
V_4 -> V_26 -> V_27 = V_27 ;
V_4 -> V_26 -> V_92 = (struct V_89 * ) V_90 ;
V_43 = F_54 ( V_4 ) ;
if ( V_43 ) {
F_3 ( & V_27 -> V_3 , L_24 ) ;
F_45 ( V_4 -> V_26 ) ;
F_45 ( V_4 ) ;
return - V_58 ;
}
V_4 -> V_26 -> V_93 = F_57 ( & V_27 -> V_3 ,
V_9 ,
& V_94 ) ;
if ( ! V_4 -> V_26 -> V_93 ) {
F_3 ( & V_27 -> V_3 ,
L_25 ) ;
F_53 ( V_4 ) ;
F_45 ( V_4 -> V_26 ) ;
F_45 ( V_4 ) ;
return - V_24 ;
}
V_4 -> V_6 = V_4 -> V_26 -> V_93 -> V_7 ;
F_58 ( & V_27 -> V_3 , V_4 ) ;
F_59 ( & V_4 -> V_95 , & V_96 ) ;
for ( V_25 = 0 ; V_25 < V_9 ; V_25 ++ )
V_4 -> V_35 [ V_25 ] . V_3 =
F_60 ( V_4 -> V_26 -> V_93 , V_25 , V_25 ) ;
return V_43 ;
}
static void F_61 ( struct V_1 * V_4 )
{
F_53 ( V_4 ) ;
F_62 ( & V_4 -> V_95 ) ;
F_63 ( V_4 -> V_26 -> V_93 ) ;
F_45 ( V_4 -> V_26 ) ;
F_45 ( V_4 ) ;
}
static void T_3 F_64 ( struct V_88 * V_3 )
{
struct V_1 * V_4 , * V_97 ;
F_65 (tpci200, next, &tpci200_list, list) {
if ( V_4 -> V_26 -> V_27 == V_3 ) {
F_61 ( V_4 ) ;
break;
}
}
}
static int T_4 F_66 ( void )
{
return F_67 ( & V_98 ) ;
}
static void T_5 F_68 ( void )
{
struct V_1 * V_4 , * V_97 ;
F_65 (tpci200, next, &tpci200_list, list)
F_61 ( V_4 ) ;
F_69 ( & V_98 ) ;
}
