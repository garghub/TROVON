static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_5 = 0 ;
if ( V_3 == NULL ) {
F_2 ( L_1 ) ;
return NULL ;
}
F_3 (tpci200, &tpci200_list, list) {
if ( V_4 -> V_6 == V_3 -> V_7 ) {
V_5 = 1 ;
break;
}
}
if ( ! V_5 ) {
F_4 ( L_2 ) ;
return NULL ;
}
if ( V_3 -> V_8 >= V_9 ) {
F_2 ( L_3 ,
V_3 -> V_7 , V_3 -> V_8 , V_9 - 1 ) ;
return NULL ;
}
F_5 ( V_4 -> V_10 == NULL ) ;
if ( V_4 -> V_10 [ V_3 -> V_8 ] . V_3 == NULL ) {
F_2 ( L_4 , V_3 -> V_7 ,
V_3 -> V_8 ) ;
return NULL ;
}
return V_4 ;
}
static inline unsigned char F_6 ( void T_1 * V_11 ,
unsigned long V_12 )
{
return F_7 ( V_11 + ( V_12 ^ 1 ) ) ;
}
static inline unsigned short F_8 ( void T_1 * V_11 ,
unsigned long V_12 )
{
return F_9 ( V_11 + V_12 ) ;
}
static inline unsigned int F_10 ( void T_1 * V_11 ,
unsigned long V_12 )
{
return F_11 ( F_12 ( V_11 + V_12 ) ) ;
}
static inline void F_13 ( unsigned char V_13 ,
void T_1 * V_11 , unsigned long V_12 )
{
F_14 ( V_13 , V_11 + ( V_12 ^ 1 ) ) ;
}
static inline void F_15 ( unsigned short V_13 ,
void T_1 * V_11 ,
unsigned long V_12 )
{
F_16 ( V_13 , V_11 + V_12 ) ;
}
static inline void F_17 ( unsigned int V_13 ,
void T_1 * V_11 ,
unsigned long V_12 )
{
F_18 ( F_11 ( V_13 ) , V_11 + V_12 ) ;
}
static struct V_14 * F_19 ( struct V_2 * V_3 ,
int V_15 )
{
struct V_14 * V_16 ;
switch ( V_15 ) {
case V_17 :
V_16 = & V_3 -> V_18 ;
break;
case V_19 :
V_16 = & V_3 -> V_20 ;
break;
case V_21 :
V_16 = & V_3 -> V_22 ;
break;
default:
F_4 ( L_5 ,
V_3 -> V_7 , V_3 -> V_8 , V_15 ) ;
return NULL ;
break;
}
if ( ( V_16 -> V_23 == 0 ) || ( V_16 -> V_11 == NULL ) ) {
F_4 ( L_6 ) ;
return NULL ;
}
return V_16 ;
}
static int F_20 ( struct V_2 * V_3 , int V_15 ,
unsigned long V_12 , unsigned char * V_13 )
{
struct V_14 * V_16 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_24 ;
V_16 = F_19 ( V_3 , V_15 ) ;
if ( V_16 == NULL )
return - V_24 ;
if ( V_12 >= V_16 -> V_23 ) {
F_4 ( L_7 ) ;
return - V_25 ;
}
* V_13 = F_6 ( V_16 -> V_11 , V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , int V_15 ,
unsigned long V_12 , unsigned short * V_13 )
{
struct V_14 * V_16 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_24 ;
V_16 = F_19 ( V_3 , V_15 ) ;
if ( V_16 == NULL )
return - V_24 ;
if ( ( V_12 + 2 ) >= V_16 -> V_23 ) {
F_4 ( L_7 ) ;
return - V_25 ;
}
* V_13 = F_8 ( V_16 -> V_11 , V_12 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , int V_15 ,
unsigned long V_12 , unsigned int * V_13 )
{
struct V_14 * V_16 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_24 ;
V_16 = F_19 ( V_3 , V_15 ) ;
if ( V_16 == NULL )
return - V_24 ;
if ( ( V_12 + 4 ) >= V_16 -> V_23 ) {
F_4 ( L_7 ) ;
return - V_25 ;
}
* V_13 = F_10 ( V_16 -> V_11 , V_12 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , int V_15 ,
unsigned long V_12 , unsigned char V_13 )
{
struct V_14 * V_16 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_24 ;
V_16 = F_19 ( V_3 , V_15 ) ;
if ( V_16 == NULL )
return - V_24 ;
if ( V_12 >= V_16 -> V_23 ) {
F_4 ( L_7 ) ;
return - V_25 ;
}
F_13 ( V_13 , V_16 -> V_11 , V_12 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , int V_15 ,
unsigned long V_12 , unsigned short V_13 )
{
struct V_14 * V_16 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_24 ;
V_16 = F_19 ( V_3 , V_15 ) ;
if ( V_16 == NULL )
return - V_24 ;
if ( ( V_12 + 2 ) >= V_16 -> V_23 ) {
F_4 ( L_7 ) ;
return - V_25 ;
}
F_15 ( V_13 , V_16 -> V_11 , V_12 ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , int V_15 ,
unsigned long V_12 , unsigned int V_13 )
{
struct V_14 * V_16 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_24 ;
V_16 = F_19 ( V_3 , V_15 ) ;
if ( V_16 == NULL )
return - V_24 ;
if ( ( V_12 + 4 ) >= V_16 -> V_23 ) {
F_4 ( L_7 ) ;
return - V_25 ;
}
F_17 ( V_13 , V_16 -> V_11 , V_12 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_4 )
{
int V_26 ;
F_27 ( V_4 -> V_27 -> V_28 -> V_29 , ( void * ) V_4 ) ;
F_28 ( V_4 -> V_27 -> V_28 , V_4 -> V_27 -> V_30 ) ;
F_28 ( V_4 -> V_27 -> V_28 , V_4 -> V_27 -> V_31 ) ;
F_28 ( V_4 -> V_27 -> V_28 , V_4 -> V_27 -> V_32 ) ;
F_29 ( V_4 -> V_27 -> V_28 , V_33 ) ;
F_29 ( V_4 -> V_27 -> V_28 , V_34 ) ;
F_29 ( V_4 -> V_27 -> V_28 , V_35 ) ;
F_30 ( V_4 -> V_27 -> V_28 ) ;
F_31 ( V_4 -> V_27 -> V_28 ) ;
F_32 ( V_4 -> V_27 ) ;
for ( V_26 = 0 ; V_26 < V_9 ; V_26 ++ ) {
V_4 -> V_10 [ V_26 ] . V_36 . V_11 = NULL ;
V_4 -> V_10 [ V_26 ] . V_36 . V_23 = 0 ;
V_4 -> V_10 [ V_26 ] . V_37 . V_11 = NULL ;
V_4 -> V_10 [ V_26 ] . V_37 . V_23 = 0 ;
V_4 -> V_10 [ V_26 ] . V_38 . V_11 = NULL ;
V_4 -> V_10 [ V_26 ] . V_38 . V_23 = 0 ;
}
}
static T_2 F_33 ( int V_29 , void * V_39 )
{
struct V_1 * V_4 = (struct V_1 * ) V_39 ;
int V_26 ;
unsigned long V_40 ;
unsigned short V_41 , V_42 ;
unsigned short V_43 = 0 ;
T_2 V_44 = V_45 ;
F_34 ( & V_4 -> V_27 -> V_46 , V_40 ) ;
V_41 = F_35 ( V_4 -> V_27 -> V_30 +
V_47 ) ;
if ( V_41 & V_48 ) {
V_43 = V_41 & V_48 ;
for ( V_26 = 0 ; V_26 < V_9 ; V_26 ++ ) {
if ( ( V_4 -> V_10 [ V_26 ] . V_29 != NULL ) &&
( V_41 & ( ( V_49 | V_50 ) << ( 2 * V_26 ) ) ) ) {
V_44 = V_4 -> V_10 [ V_26 ] . V_29 -> V_51 ( V_4 -> V_10 [ V_26 ] . V_29 -> V_52 ) ;
F_35 ( V_4 -> V_10 [ V_26 ] . V_3 -> V_18 . V_11 +
0xC0 ) ;
F_35 ( V_4 -> V_10 [ V_26 ] . V_3 -> V_18 . V_11 +
0xC2 ) ;
V_43 &= ~ ( ( ( V_49 | V_50 ) << ( 2 * V_26 ) ) ) ;
}
}
}
if ( V_43 ) {
for ( V_26 = 0 ; V_26 < V_9 ; V_26 ++ ) {
if ( V_43 & ( ( V_53 | V_54 ) << ( 2 * V_26 ) ) ) {
F_2 ( L_8 ,
V_4 -> V_6 , V_26 ) ;
V_42 = F_35 (
V_4 -> V_27 -> V_30 +
V_55 [ V_26 ] ) ;
V_42 &=
~ ( V_53 | V_54 ) ;
F_36 ( V_42 ,
( V_4 -> V_27 -> V_30 +
V_55 [ V_26 ] ) ) ;
}
}
}
F_37 ( & V_4 -> V_27 -> V_46 , V_40 ) ;
return V_44 ;
}
static struct V_2 * F_38 ( unsigned int V_56 ,
unsigned int V_57 )
{
int V_5 = 0 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
F_3 (tpci200, &tpci200_list, list) {
if ( V_4 -> V_6 == V_56 ) {
V_5 = 1 ;
break;
}
}
if ( ! V_5 ) {
F_4 ( L_9 ) ;
return NULL ;
}
if ( V_57 >= V_9 ) {
F_2 ( L_10 , V_56 ,
V_57 ) ;
return NULL ;
}
if ( F_39 ( & V_4 -> V_58 ) )
return NULL ;
if ( V_4 -> V_10 [ V_57 ] . V_3 != NULL ) {
F_4 ( L_11 , V_56 ,
V_57 ) ;
goto V_59;
}
V_3 = F_40 ( V_4 -> V_27 -> V_60 ,
V_57 , V_57 ) ;
if ( V_3 == NULL ) {
F_2 ( L_12 ,
V_56 , V_57 ) ;
goto V_59;
}
V_4 -> V_10 [ V_57 ] . V_3 = V_3 ;
F_41 ( & V_4 -> V_58 ) ;
return V_3 ;
V_59:
F_41 ( & V_4 -> V_58 ) ;
return NULL ;
}
static T_3 F_42 ( struct V_61 * V_28 , const char * V_62 ,
T_4 V_63 , int V_8 )
{
struct V_1 * V_64 = F_43 ( V_28 ) ;
struct V_2 * V_3 = V_64 -> V_10 [ V_8 ] . V_3 ;
if ( V_3 != NULL )
return - V_65 ;
V_3 = F_38 ( V_64 -> V_6 , V_8 ) ;
if ( V_3 == NULL )
return - V_66 ;
return V_63 ;
}
static T_3 F_44 ( struct V_61 * V_28 , char * V_62 , int V_8 )
{
struct V_1 * V_64 = F_43 ( V_28 ) ;
struct V_2 * V_3 = V_64 -> V_10 [ V_8 ] . V_3 ;
if ( V_3 != NULL )
return snprintf ( V_62 , V_67 , L_13 , F_45 ( & V_3 -> V_3 ) ) ;
else
return snprintf ( V_62 , V_67 , L_14 ) ;
}
static T_3 F_46 ( struct V_61 * V_28 ,
struct V_68 * V_69 ,
char * V_62 )
{
return snprintf ( V_62 , V_67 ,
L_15 ) ;
}
static T_3 F_47 ( struct V_61 * V_28 ,
struct V_68 * V_69 ,
char * V_62 )
{
return F_44 ( V_28 , V_62 , 0 ) ;
}
static T_3 F_48 ( struct V_61 * V_28 ,
struct V_68 * V_69 ,
const char * V_62 , T_4 V_63 )
{
return F_42 ( V_28 , V_62 , V_63 , 0 ) ;
}
static T_3 F_49 ( struct V_61 * V_28 ,
struct V_68 * V_69 ,
char * V_62 )
{
return F_44 ( V_28 , V_62 , 1 ) ;
}
static T_3 F_50 ( struct V_61 * V_28 ,
struct V_68 * V_69 ,
const char * V_62 , T_4 V_63 )
{
return F_42 ( V_28 , V_62 , V_63 , 1 ) ;
}
static T_3 F_51 ( struct V_61 * V_28 ,
struct V_68 * V_69 ,
char * V_62 )
{
return F_44 ( V_28 , V_62 , 2 ) ;
}
static T_3 F_52 ( struct V_61 * V_28 ,
struct V_68 * V_69 ,
const char * V_62 , T_4 V_63 )
{
return F_42 ( V_28 , V_62 , V_63 , 2 ) ;
}
static T_3 F_53 ( struct V_61 * V_28 ,
struct V_68 * V_69 ,
char * V_62 )
{
return F_44 ( V_28 , V_62 , 3 ) ;
}
static T_3 F_54 ( struct V_61 * V_28 ,
struct V_68 * V_69 ,
const char * V_62 , T_4 V_63 )
{
return F_42 ( V_28 , V_62 , V_63 , 3 ) ;
}
static int F_55 ( struct V_1 * V_64 )
{
return F_56 ( & V_64 -> V_27 -> V_28 -> V_3 . V_70 ,
& V_71 ) ;
}
static void F_57 ( struct V_1 * V_64 )
{
F_58 ( & V_64 -> V_27 -> V_28 -> V_3 . V_70 , & V_71 ) ;
}
static int F_55 ( struct V_1 * V_64 )
{
return 0 ;
}
static void F_57 ( struct V_1 * V_64 )
{
}
static int F_59 ( struct V_1 * V_4 )
{
int V_26 ;
int V_72 ;
unsigned long V_73 ;
unsigned long V_74 ;
unsigned short V_75 ;
if ( F_60 ( V_4 -> V_27 -> V_28 ) < 0 )
return - V_66 ;
if ( F_55 ( V_4 ) < 0 ) {
F_4 ( L_16 ) ;
V_72 = - V_25 ;
goto V_76;
}
V_72 = F_61 ( V_4 -> V_27 -> V_28 , V_33 ,
L_17 ) ;
if ( V_72 ) {
F_4 ( L_18 ,
V_4 -> V_27 -> V_28 -> V_77 -> V_6 ,
V_4 -> V_27 -> V_28 -> V_78 ) ;
goto V_79;
}
V_72 = F_61 ( V_4 -> V_27 -> V_28 ,
V_34 ,
L_19 ) ;
if ( V_72 ) {
F_4 ( L_20 ,
V_4 -> V_27 -> V_28 -> V_77 -> V_6 ,
V_4 -> V_27 -> V_28 -> V_78 ) ;
goto V_80;
}
V_72 = F_61 ( V_4 -> V_27 -> V_28 , V_35 ,
L_21 ) ;
if ( V_72 ) {
F_4 ( L_22 ,
V_4 -> V_27 -> V_28 -> V_77 -> V_6 ,
V_4 -> V_27 -> V_28 -> V_78 ) ;
goto V_81;
}
V_4 -> V_27 -> V_30 =
F_62 ( F_63 ( V_4 -> V_27 -> V_28 ,
V_33 ) ,
V_82 ) ;
V_4 -> V_27 -> V_31 =
F_62 ( F_63 ( V_4 -> V_27 -> V_28 ,
V_34 ) ,
V_83 ) ;
V_4 -> V_27 -> V_32 =
F_62 ( F_63 ( V_4 -> V_27 -> V_28 ,
V_35 ) ,
V_84 ) ;
F_64 ( & V_4 -> V_27 -> V_46 ) ;
V_73 = F_63 ( V_4 -> V_27 -> V_28 ,
V_34 ) ;
V_74 = F_63 ( V_4 -> V_27 -> V_28 ,
V_35 ) ;
V_75 = 0 ;
for ( V_26 = 0 ; V_26 < V_9 ; V_26 ++ ) {
V_4 -> V_10 [ V_26 ] . V_36 . V_11 =
( void T_1 * ) V_73 +
V_85 + V_86 * V_26 ;
V_4 -> V_10 [ V_26 ] . V_36 . V_23 = V_87 ;
V_4 -> V_10 [ V_26 ] . V_37 . V_11 =
( void T_1 * ) V_73 +
V_88 + V_89 * V_26 ;
V_4 -> V_10 [ V_26 ] . V_37 . V_23 = V_90 ;
V_4 -> V_10 [ V_26 ] . V_38 . V_11 =
( void T_1 * ) V_74 + V_91 * V_26 ;
V_4 -> V_10 [ V_26 ] . V_38 . V_23 = V_84 ;
F_36 ( V_75 , ( V_4 -> V_27 -> V_30 +
V_55 [ V_26 ] ) ) ;
}
V_72 = F_65 ( V_4 -> V_27 -> V_28 -> V_29 ,
F_33 , V_92 ,
V_93 , ( void * ) V_4 ) ;
if ( V_72 ) {
F_4 ( L_23 ,
V_4 -> V_27 -> V_28 -> V_77 -> V_6 ,
V_4 -> V_27 -> V_28 -> V_78 ) ;
F_26 ( V_4 ) ;
goto V_94;
}
return 0 ;
V_81:
F_29 ( V_4 -> V_27 -> V_28 , V_34 ) ;
V_80:
F_29 ( V_4 -> V_27 -> V_28 , V_33 ) ;
V_79:
F_57 ( V_4 ) ;
V_76:
F_30 ( V_4 -> V_27 -> V_28 ) ;
V_94:
return V_72 ;
}
static int F_66 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
unsigned short V_75 ;
V_75 = V_53 | V_54 ;
F_36 ( V_75 , ( V_4 -> V_27 -> V_30 +
V_55 [ V_3 -> V_8 ] ) ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
unsigned short V_75 ;
V_75 = 0 ;
F_36 ( V_75 , ( V_4 -> V_27 -> V_30 +
V_55 [ V_3 -> V_8 ] ) ) ;
}
static int F_68 ( struct V_2 * V_3 )
{
int V_72 ;
struct V_95 * V_95 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL ) {
V_72 = - V_24 ;
goto V_96;
}
if ( F_39 ( & V_4 -> V_58 ) ) {
V_72 = - V_97 ;
goto V_96;
}
if ( V_4 -> V_10 [ V_3 -> V_8 ] . V_29 == NULL ) {
V_72 = - V_24 ;
goto V_98;
}
F_67 ( V_4 , V_3 ) ;
V_95 = V_4 -> V_10 [ V_3 -> V_8 ] . V_29 ;
V_4 -> V_10 [ V_3 -> V_8 ] . V_29 = NULL ;
F_32 ( V_95 ) ;
V_98:
F_41 ( & V_4 -> V_58 ) ;
V_96:
return V_72 ;
}
static int F_69 ( struct V_2 * V_3 , int V_15 )
{
int V_72 ;
struct V_14 * V_99 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL ) {
V_72 = - V_24 ;
goto V_96;
}
if ( F_39 ( & V_4 -> V_58 ) ) {
V_72 = - V_97 ;
goto V_96;
}
switch ( V_15 ) {
case V_17 :
if ( V_3 -> V_18 . V_11 == NULL ) {
F_2 ( L_24 ,
V_3 -> V_7 , V_3 -> V_8 ) ;
goto V_98;
}
V_99 = & V_3 -> V_18 ;
break;
case V_19 :
if ( V_3 -> V_20 . V_11 == NULL ) {
F_2 ( L_25 ,
V_3 -> V_7 , V_3 -> V_8 ) ;
goto V_98;
}
V_99 = & V_3 -> V_20 ;
break;
case V_21 :
if ( V_3 -> V_22 . V_11 == NULL ) {
F_2 ( L_26 ,
V_3 -> V_7 , V_3 -> V_8 ) ;
goto V_98;
}
V_99 = & V_3 -> V_22 ;
break;
default:
F_4 ( L_5 ,
V_3 -> V_7 , V_3 -> V_8 , V_15 ) ;
V_72 = - V_24 ;
goto V_98;
break;
}
F_70 ( V_99 -> V_11 ) ;
V_99 -> V_11 = NULL ;
V_99 -> V_23 = 0 ;
V_98:
F_41 ( & V_4 -> V_58 ) ;
V_96:
return V_72 ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( V_3 == NULL )
return - V_66 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_24 ;
F_68 ( V_3 ) ;
if ( F_39 ( & V_4 -> V_58 ) )
return - V_97 ;
F_72 ( V_3 ) ;
V_4 -> V_10 [ V_3 -> V_8 ] . V_3 = NULL ;
F_41 ( & V_4 -> V_58 ) ;
return 0 ;
}
static int F_73 ( struct V_2 * V_3 ,
unsigned int V_100 , int V_15 )
{
int V_72 ;
unsigned int V_101 ;
void T_1 * V_102 ;
struct V_14 * V_99 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL ) {
V_72 = - V_24 ;
goto V_96;
}
if ( F_39 ( & V_4 -> V_58 ) ) {
V_72 = - V_97 ;
goto V_96;
}
switch ( V_15 ) {
case V_17 :
if ( V_3 -> V_18 . V_11 != NULL ) {
F_4 ( L_27 ,
V_4 -> V_6 , V_3 -> V_8 ) ;
V_72 = - V_24 ;
goto V_98;
}
V_99 = & V_3 -> V_18 ;
V_102 = V_4 -> V_10 [ V_3 -> V_8 ] . V_36 . V_11 ;
V_101 = V_4 -> V_10 [ V_3 -> V_8 ] . V_36 . V_23 ;
break;
case V_19 :
if ( V_3 -> V_20 . V_11 != NULL ) {
F_4 ( L_28 ,
V_4 -> V_6 , V_3 -> V_8 ) ;
V_72 = - V_24 ;
goto V_98;
}
V_99 = & V_3 -> V_20 ;
V_102 = V_4 -> V_10 [ V_3 -> V_8 ] . V_37 . V_11 ;
V_101 = V_4 -> V_10 [ V_3 -> V_8 ] . V_37 . V_23 ;
break;
case V_21 :
if ( V_3 -> V_22 . V_11 != NULL ) {
F_4 ( L_29 ,
V_4 -> V_6 , V_3 -> V_8 ) ;
V_72 = - V_24 ;
goto V_98;
}
V_99 = & V_3 -> V_22 ;
if ( V_100 > V_4 -> V_10 [ V_3 -> V_8 ] . V_38 . V_23 ) {
F_4 ( L_30 ,
V_3 -> V_7 , V_3 -> V_8 , V_100 ,
V_4 -> V_10 [ V_3 -> V_8 ] . V_38 . V_23 ) ;
V_72 = - V_24 ;
goto V_98;
}
V_102 = V_4 -> V_10 [ V_3 -> V_8 ] . V_38 . V_11 ;
V_101 = V_100 ;
break;
default:
F_4 ( L_31 ,
V_4 -> V_6 , V_3 -> V_8 , V_15 ) ;
V_72 = - V_24 ;
goto V_98;
break;
}
V_99 -> V_23 = V_101 ;
V_99 -> V_11 =
F_62 ( ( unsigned long ) V_102 , V_101 ) ;
V_98:
F_41 ( & V_4 -> V_58 ) ;
V_96:
return V_72 ;
}
static int F_74 ( struct V_2 * V_3 , int V_103 ,
int (* V_51)( void * ) , void * V_52 )
{
int V_72 ;
struct V_95 * V_95 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL ) {
V_72 = - V_24 ;
goto V_96;
}
if ( F_39 ( & V_4 -> V_58 ) ) {
V_72 = - V_97 ;
goto V_96;
}
if ( V_4 -> V_10 [ V_3 -> V_8 ] . V_29 != NULL ) {
F_4 ( L_32 , V_3 -> V_7 ,
V_3 -> V_8 ) ;
V_72 = - V_24 ;
goto V_98;
}
V_95 = F_75 ( sizeof( struct V_95 ) , V_104 ) ;
if ( V_95 == NULL ) {
F_4 ( L_33 ,
V_3 -> V_7 , V_3 -> V_8 ) ;
V_72 = - V_105 ;
goto V_98;
}
V_95 -> V_103 = V_103 ;
V_95 -> V_51 = V_51 ;
V_95 -> V_52 = V_52 ;
V_95 -> V_106 = F_45 ( & V_3 -> V_3 ) ;
V_4 -> V_10 [ V_3 -> V_8 ] . V_29 = V_95 ;
V_72 = F_66 ( V_4 , V_3 ) ;
V_98:
F_41 ( & V_4 -> V_58 ) ;
V_96:
return V_72 ;
}
static void F_76 ( struct V_107 * V_8 )
{
if ( ( V_8 -> V_3 == NULL ) ||
( V_8 -> V_3 -> V_108 -> V_109 -> remove == NULL ) )
return;
V_8 -> V_3 -> V_108 -> V_109 -> remove ( V_8 -> V_3 ) ;
}
static void F_77 ( struct V_1 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_9 ; V_26 ++ )
F_76 ( & V_4 -> V_10 [ V_26 ] ) ;
F_26 ( V_4 ) ;
F_32 ( V_4 -> V_10 ) ;
}
static int F_78 ( struct V_1 * V_4 )
{
int V_72 ;
V_4 -> V_10 = F_75 (
V_9 * sizeof( struct V_107 ) , V_104 ) ;
if ( V_4 -> V_10 == NULL ) {
V_72 = - V_105 ;
goto V_94;
}
V_72 = F_59 ( V_4 ) ;
if ( V_72 )
goto V_110;
F_79 ( & V_4 -> V_58 ) ;
return 0 ;
V_110:
F_32 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
V_94:
return V_72 ;
}
static int F_80 ( struct V_111 * V_28 ,
const struct V_112 * V_113 )
{
int V_44 ;
struct V_1 * V_4 ;
V_4 = F_75 ( sizeof( struct V_1 ) , V_104 ) ;
if ( ! V_4 )
return - V_105 ;
V_4 -> V_27 = F_75 ( sizeof( struct V_114 ) , V_104 ) ;
if ( ! V_4 -> V_27 ) {
F_32 ( V_4 ) ;
return - V_105 ;
}
V_4 -> V_27 -> V_28 = V_28 ;
V_4 -> V_27 -> V_115 = (struct V_112 * ) V_113 ;
V_44 = F_78 ( V_4 ) ;
if ( V_44 ) {
F_4 ( L_34 ) ;
F_32 ( V_4 -> V_27 ) ;
F_32 ( V_4 ) ;
return - V_66 ;
}
V_4 -> V_27 -> V_60 = F_81 ( & V_28 -> V_3 ,
V_9 ,
& V_116 ) ;
if ( ! V_4 -> V_27 -> V_60 ) {
F_4 ( L_35 ) ;
F_77 ( V_4 ) ;
F_32 ( V_4 -> V_27 ) ;
F_32 ( V_4 ) ;
return - V_25 ;
}
V_4 -> V_6 = V_4 -> V_27 -> V_60 -> V_7 ;
F_82 ( & V_28 -> V_3 , V_4 ) ;
F_83 ( & V_4 -> V_117 , & V_118 ) ;
return V_44 ;
}
static void F_84 ( struct V_1 * V_4 )
{
F_77 ( V_4 ) ;
F_57 ( V_4 ) ;
F_85 ( & V_4 -> V_117 ) ;
F_86 ( V_4 -> V_27 -> V_60 ) ;
F_32 ( V_4 -> V_27 ) ;
F_32 ( V_4 ) ;
}
static void T_5 F_87 ( struct V_111 * V_3 )
{
struct V_1 * V_4 , * V_119 ;
F_88 (tpci200, next, &tpci200_list, list) {
if ( V_4 -> V_27 -> V_28 == V_3 ) {
F_84 ( V_4 ) ;
break;
}
}
}
static int T_6 F_89 ( void )
{
return F_90 ( & V_120 ) ;
}
static void T_7 F_91 ( void )
{
struct V_1 * V_4 , * V_119 ;
F_88 (tpci200, next, &tpci200_list, list)
F_84 ( V_4 ) ;
F_92 ( & V_120 ) ;
}
