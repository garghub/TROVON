static T_1 F_1 ( char * V_1 , T_2 V_2 , T_3 * V_3 )
{
unsigned int V_4 ;
unsigned long V_5 ;
int V_6 ;
unsigned long V_7 ;
char * V_8 = V_1 ;
if ( V_9 == 0 || V_10 == V_11 )
return - V_12 ;
if ( * V_3 >= V_9 )
return 0 ;
V_4 = * V_3 ;
if ( V_4 + V_2 > V_9 )
V_2 = V_9 - V_4 ;
F_2 ( & V_13 , V_7 ) ;
for (; V_2 != 0 ; V_2 -= V_5 ) {
V_5 = V_2 ;
if ( V_5 > V_14 )
V_5 = V_14 ;
if ( ( F_3 ( V_10 , 3 , 2 , & V_6 , V_4 , F_4 ( V_15 ) ,
V_5 ) != 0 ) || V_5 != V_6 ) {
F_5 ( & V_13 , V_7 ) ;
return - V_16 ;
}
memcpy ( V_8 , V_15 , V_5 ) ;
V_8 += V_5 ;
V_4 += V_5 ;
}
F_5 ( & V_13 , V_7 ) ;
* V_3 = V_4 ;
return V_8 - V_1 ;
}
static T_1 F_6 ( char * V_1 , T_2 V_2 , T_3 * V_3 )
{
unsigned int V_4 ;
unsigned long V_5 ;
int V_6 ;
unsigned long V_7 ;
const char * V_8 = V_1 ;
if ( V_9 == 0 || V_17 == V_11 )
return - V_12 ;
if ( * V_3 >= V_9 )
return 0 ;
V_4 = * V_3 ;
if ( V_4 + V_2 > V_9 )
V_2 = V_9 - V_4 ;
F_2 ( & V_13 , V_7 ) ;
for (; V_2 != 0 ; V_2 -= V_5 ) {
V_5 = V_2 ;
if ( V_5 > V_14 )
V_5 = V_14 ;
memcpy ( V_15 , V_8 , V_5 ) ;
if ( ( F_3 ( V_17 , 3 , 2 , & V_6 , V_4 , F_4 ( V_15 ) ,
V_5 ) != 0 ) || V_5 != V_6 ) {
F_5 ( & V_13 , V_7 ) ;
return - V_16 ;
}
V_8 += V_5 ;
V_4 += V_5 ;
}
F_5 ( & V_13 , V_7 ) ;
* V_3 = V_4 ;
return V_8 - V_1 ;
}
static T_1 F_7 ( void )
{
return V_9 ? V_9 : - V_12 ;
}
int F_8 ( struct V_18 * V_19 , char * V_20 ,
int V_21 , unsigned int V_22 , unsigned int V_23 )
{
int V_24 ;
T_3 V_25 ;
struct V_26 V_27 ;
if ( V_19 -> V_3 == - 1 ) {
return - V_28 ;
}
if ( V_21 > V_19 -> V_29 ) {
V_21 = V_19 -> V_29 ;
}
V_27 . V_30 = V_22 ;
V_27 . V_31 = V_23 ;
V_25 = V_19 -> V_3 ;
V_24 = V_32 . V_33 ( ( char * ) & V_27 , sizeof( struct V_26 ) , & V_25 ) ;
if ( V_24 <= 0 ) {
F_9 ( L_1 , V_34 , V_24 ) ;
return V_24 ;
}
V_24 = V_32 . V_33 ( V_20 , V_21 , & V_25 ) ;
if ( V_24 <= 0 ) {
F_9 ( L_1 , V_34 , V_24 ) ;
return V_24 ;
}
return 0 ;
}
int F_10 ( char * V_20 , int V_21 ,
unsigned int V_22 , unsigned int V_23 )
{
int V_24 = F_8 ( & V_35 , V_20 , V_21 ,
V_22 , V_23 ) ;
if ( ! V_24 )
V_36 = F_11 () ;
return V_24 ;
}
int F_12 ( char * V_20 , int V_21 ,
unsigned int * V_22 , unsigned int * V_23 )
{
int V_24 ;
T_3 V_25 ;
struct V_26 V_27 ;
if ( V_35 . V_3 == - 1 )
return - 1 ;
if ( V_21 > V_35 . V_29 )
V_21 = V_35 . V_29 ;
V_25 = V_35 . V_3 ;
V_24 = V_32 . V_37 ( ( char * ) & V_27 , sizeof( struct V_26 ) , & V_25 ) ;
if ( V_24 <= 0 ) {
F_13 ( V_38 L_2 , V_24 ) ;
return V_24 ;
}
V_24 = V_32 . V_37 ( V_20 , V_21 , & V_25 ) ;
if ( V_24 <= 0 ) {
F_13 ( V_38 L_2 , V_24 ) ;
return V_24 ;
}
* V_23 = V_27 . V_31 ;
* V_22 = V_27 . V_30 ;
return 0 ;
}
int F_14 ( void )
{
T_3 V_25 ;
int V_39 = V_40 ;
int V_24 ;
if ( V_35 . V_3 == - 1 )
return - 1 ;
V_25 = V_35 . V_3 ;
V_24 = V_32 . V_33 ( ( char * ) & V_39 , sizeof( int ) , & V_25 ) ;
if ( V_24 <= 0 ) {
F_13 ( V_38 L_3 , V_24 ) ;
return V_24 ;
}
V_36 = 0 ;
return 0 ;
}
static int T_4 F_15 ( struct V_18
* V_19 )
{
T_3 V_8 ;
int V_29 ;
F_16 () ;
V_8 = F_17 ( V_19 -> V_41 , V_42 , & V_29 ) ;
if ( V_8 && V_29 < V_19 -> V_43 ) {
F_18 ( L_4
L_5 , V_19 -> V_41 ) ;
F_19 ( V_19 -> V_41 , V_42 , NULL ) ;
V_8 = 0 ;
}
if ( ! V_8 ) {
V_8 = F_20 ( V_19 -> V_41 , V_42 ,
V_19 -> V_44 , V_19 -> V_43 ) ;
if ( V_8 == - V_45 ) {
F_18 ( L_6
L_7 ,
V_19 -> V_41 ) ;
F_19 ( NULL , V_42 ,
V_46 ) ;
V_8 = F_20 ( V_19 -> V_41 , V_42 ,
V_19 -> V_44 , V_19 -> V_43 ) ;
}
}
if ( V_8 <= 0 ) {
F_9 ( L_8
L_9 , V_19 -> V_41 , ( int ) V_8 ) ;
return - 1 ;
}
V_19 -> V_3 = V_8 ;
V_19 -> V_29 = F_21 ( V_8 ) - sizeof( struct V_26 ) ;
return 0 ;
}
static void T_4 F_22 ( int V_47 )
{
int V_24 ;
V_24 = F_15 ( & V_48 ) ;
if ( V_24 != 0 ) {
if ( ! V_47 )
return;
F_23 ( L_10
L_11 ,
V_35 . V_41 ) ;
memcpy ( & V_48 , & V_35 ,
sizeof( V_35 ) ) ;
}
V_49 = F_24 ( V_48 . V_29 , V_50 ) ;
if ( ! V_49 ) {
F_9 ( L_12 ,
V_48 . V_41 ) ;
return;
}
V_51 = ( V_52 * ) V_49 ;
V_53 = V_49 + sizeof( V_52 ) ;
V_54 = V_48 . V_29 - sizeof( V_52 ) ;
V_55 = ( V_54 * 100 ) / 45 ;
V_56 = F_24 ( V_55 , V_50 ) ;
if ( V_56 ) {
V_57 . V_58 = F_24 ( F_25 (
V_59 , V_60 ) , V_50 ) ;
if ( ! V_57 . V_58 ) {
F_9 ( L_13
L_14 ,
V_48 . V_41 ) ;
F_26 ( V_56 ) ;
V_56 = NULL ;
}
} else {
F_9 ( L_15
L_16 , V_48 . V_41 ) ;
V_57 . V_58 = NULL ;
}
V_24 = F_27 ( & V_61 ) ;
if ( V_24 != 0 ) {
F_9 ( L_17 , V_24 ) ;
F_26 ( V_49 ) ;
F_26 ( V_56 ) ;
F_26 ( V_57 . V_58 ) ;
}
}
static int T_4 F_28 ( void )
{
int V_24 ;
V_24 = F_15 ( & V_35 ) ;
F_22 ( V_24 == 0 ) ;
return 0 ;
}
int T_4 F_29 ( void )
{
struct V_62 * V_63 ;
const unsigned int * V_64 ;
unsigned int V_65 ;
V_63 = F_30 ( NULL , L_18 ) ;
if ( V_63 == NULL )
return - V_12 ;
V_64 = F_31 ( V_63 , L_19 , & V_65 ) ;
if ( V_64 == NULL || V_65 != sizeof( unsigned int ) ) {
F_32 ( V_63 ) ;
return - V_16 ;
}
V_9 = * V_64 ;
V_10 = F_33 ( L_20 ) ;
V_17 = F_33 ( L_21 ) ;
F_13 ( V_66 L_22 , V_9 ) ;
F_32 ( V_63 ) ;
V_32 . V_37 = F_1 ;
V_32 . V_33 = F_6 ;
V_32 . V_9 = F_7 ;
return 0 ;
}
static T_2 F_34 ( const char * V_67 , T_2 V_68 ,
const char * V_69 , T_2 V_70 ,
char * V_71 , T_2 V_72 )
{
if ( V_70 >= V_72 ) {
memcpy ( V_71 , V_69 + ( V_70 - V_72 ) ,
V_72 ) ;
return V_72 ;
} else {
T_2 V_73 = F_35 ( V_68 , V_72 - V_70 ) ;
memcpy ( V_71 , V_67 + ( V_68 - V_73 ) ,
V_73 ) ;
memcpy ( V_71 + V_73 , V_69 , V_70 ) ;
return V_73 + V_70 ;
}
}
static int F_36 ( void )
{
return ( V_48 . V_3 == V_35 . V_3
&& V_36
&& F_11 () - V_36 <=
V_74 ) ;
}
static T_2 F_37 ( char * V_1 , T_2 V_5 )
{
char * V_75 , * V_76 , * V_77 = V_1 + V_5 ;
int V_78 = 1 ;
V_75 = V_76 = V_1 ;
while ( V_75 < V_77 ) {
if ( V_78 && V_75 + 3 <= V_77 &&
* V_75 == '<' && isdigit ( V_75 [ 1 ] ) && V_75 [ 2 ] == '>' ) {
V_75 += 3 ;
V_78 = 0 ;
} else {
V_78 = ( * V_75 == '\n' ) ;
* V_76 ++ = * V_75 ++ ;
}
}
return V_76 - V_1 ;
}
static int F_38 ( const void * V_75 , void * V_76 , T_2 V_79 ,
T_2 V_80 )
{
int V_81 , V_82 ;
V_82 = - V_16 ;
V_81 = F_39 ( & V_57 , V_83 , V_84 , V_59 ,
V_60 , V_85 ) ;
if ( V_81 != V_86 )
goto error;
V_57 . V_87 = V_75 ;
V_57 . V_88 = V_79 ;
V_57 . V_89 = 0 ;
V_57 . V_90 = V_76 ;
V_57 . V_91 = V_80 ;
V_57 . V_92 = 0 ;
V_81 = F_40 ( & V_57 , V_93 ) ;
if ( V_81 != V_94 )
goto error;
V_81 = F_41 ( & V_57 ) ;
if ( V_81 != V_86 )
goto error;
if ( V_57 . V_92 >= V_57 . V_89 )
goto error;
V_82 = V_57 . V_92 ;
error:
return V_82 ;
}
static int F_42 ( T_2 V_95 )
{
int V_96 = F_38 ( V_56 , V_53 , V_95 ,
V_54 ) ;
if ( V_96 < 0 ) {
F_9 ( L_23 , V_96 ) ;
F_9 ( L_24 ) ;
return - 1 ;
}
* V_51 = ( V_52 ) V_96 ;
return 0 ;
}
static void F_43 ( struct V_97 * V_98 ,
enum V_99 V_100 ,
const char * V_67 , unsigned long V_68 ,
const char * V_69 , unsigned long V_70 )
{
static unsigned int V_101 = 0 ;
static bool V_102 = false ;
static F_44 ( V_103 ) ;
unsigned long V_7 ;
T_2 V_95 ;
unsigned int V_22 = V_104 ;
int V_24 = - 1 ;
switch ( V_100 ) {
case V_105 :
case V_106 :
case V_107 :
return;
case V_108 :
break;
case V_109 :
V_102 = true ;
break;
case V_110 :
if ( V_102 )
return;
break;
default:
F_9 ( L_25 ,
V_34 , ( int ) V_100 ) ;
return;
}
if ( F_36 () )
return;
if ( ! F_45 ( & V_103 , V_7 ) )
return;
if ( V_56 ) {
V_95 = F_34 ( V_67 , V_68 ,
V_69 , V_70 , V_56 , V_55 ) ;
V_95 = F_37 ( V_56 , V_95 ) ;
V_24 = F_42 ( V_95 ) ;
}
if ( V_24 != 0 ) {
V_95 = F_34 ( V_67 , V_68 ,
V_69 , V_70 , V_53 , V_54 ) ;
V_22 = V_111 ;
* V_51 = ( V_52 ) V_95 ;
}
( void ) F_8 ( & V_48 , V_49 ,
( int ) ( sizeof( * V_51 ) + * V_51 ) , V_22 , ++ V_101 ) ;
F_5 ( & V_103 , V_7 ) ;
}
