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
static int F_34 ( void )
{
return ( V_48 . V_3 == V_35 . V_3
&& V_36
&& F_11 () - V_36 <=
V_67 ) ;
}
static int F_35 ( const void * V_68 , void * V_69 , T_2 V_70 ,
T_2 V_71 )
{
int V_72 , V_73 ;
V_73 = - V_16 ;
V_72 = F_36 ( & V_57 , V_74 , V_75 , V_59 ,
V_60 , V_76 ) ;
if ( V_72 != V_77 )
goto error;
V_57 . V_78 = V_68 ;
V_57 . V_79 = V_70 ;
V_57 . V_80 = 0 ;
V_57 . V_81 = V_69 ;
V_57 . V_82 = V_71 ;
V_57 . V_83 = 0 ;
V_72 = F_37 ( & V_57 , V_84 ) ;
if ( V_72 != V_85 )
goto error;
V_72 = F_38 ( & V_57 ) ;
if ( V_72 != V_77 )
goto error;
if ( V_57 . V_83 >= V_57 . V_80 )
goto error;
V_73 = V_57 . V_83 ;
error:
return V_73 ;
}
static int F_39 ( T_2 V_86 )
{
int V_87 = F_35 ( V_56 , V_53 , V_86 ,
V_54 ) ;
if ( V_87 < 0 ) {
F_9 ( L_23 , V_87 ) ;
F_9 ( L_24 ) ;
return - 1 ;
}
* V_51 = ( V_52 ) V_87 ;
return 0 ;
}
static void F_40 ( struct V_88 * V_89 ,
enum V_90 V_91 )
{
static unsigned int V_92 = 0 ;
static bool V_93 = false ;
static F_41 ( V_94 ) ;
unsigned long V_7 ;
T_2 V_86 ;
unsigned int V_22 = V_95 ;
int V_24 = - 1 ;
switch ( V_91 ) {
case V_96 :
case V_97 :
case V_98 :
return;
case V_99 :
break;
case V_100 :
V_93 = true ;
break;
case V_101 :
if ( V_93 )
return;
break;
default:
F_9 ( L_25 ,
V_34 , ( int ) V_91 ) ;
return;
}
if ( F_34 () )
return;
if ( ! F_42 ( & V_94 , V_7 ) )
return;
if ( V_56 ) {
F_43 ( V_89 , false ,
V_56 , V_55 , & V_86 ) ;
V_24 = F_39 ( V_86 ) ;
}
if ( V_24 != 0 ) {
F_44 ( V_89 ) ;
F_43 ( V_89 , true ,
V_53 , V_54 , & V_86 ) ;
V_22 = V_102 ;
* V_51 = ( V_52 ) V_86 ;
}
( void ) F_8 ( & V_48 , V_49 ,
( int ) ( sizeof( * V_51 ) + * V_51 ) , V_22 , ++ V_92 ) ;
F_5 ( & V_94 , V_7 ) ;
}
