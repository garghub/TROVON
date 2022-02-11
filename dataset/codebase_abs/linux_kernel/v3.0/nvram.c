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
V_24 = F_25 ( & V_51 ) ;
if ( V_24 != 0 ) {
F_9 ( L_12 , V_24 ) ;
F_26 ( V_49 ) ;
return;
}
}
static int T_4 F_27 ( void )
{
int V_24 ;
V_24 = F_15 ( & V_35 ) ;
F_22 ( V_24 == 0 ) ;
return 0 ;
}
int T_4 F_28 ( void )
{
struct V_52 * V_53 ;
const unsigned int * V_54 ;
unsigned int V_55 ;
V_53 = F_29 ( NULL , L_13 ) ;
if ( V_53 == NULL )
return - V_12 ;
V_54 = F_30 ( V_53 , L_14 , & V_55 ) ;
if ( V_54 == NULL || V_55 != sizeof( unsigned int ) ) {
F_31 ( V_53 ) ;
return - V_16 ;
}
V_9 = * V_54 ;
V_10 = F_32 ( L_15 ) ;
V_17 = F_32 ( L_16 ) ;
F_13 ( V_56 L_17 , V_9 ) ;
F_31 ( V_53 ) ;
V_32 . V_37 = F_1 ;
V_32 . V_33 = F_6 ;
V_32 . V_9 = F_7 ;
return 0 ;
}
static T_2 F_33 ( const char * V_57 , T_2 V_58 ,
const char * V_59 , T_2 V_60 ,
char * V_61 , T_2 V_62 )
{
if ( V_60 >= V_62 ) {
memcpy ( V_61 , V_59 + ( V_60 - V_62 ) ,
V_62 ) ;
return V_62 ;
} else {
T_2 V_63 = F_34 ( V_58 , V_62 - V_60 ) ;
memcpy ( V_61 , V_57 + ( V_58 - V_63 ) ,
V_63 ) ;
memcpy ( V_61 + V_63 , V_59 , V_60 ) ;
return V_63 + V_60 ;
}
}
static int F_35 ( void )
{
return ( V_48 . V_3 == V_35 . V_3
&& V_36
&& F_11 () - V_36 <=
V_64 ) ;
}
static void F_36 ( struct V_65 * V_66 ,
enum V_67 V_68 ,
const char * V_57 , unsigned long V_58 ,
const char * V_59 , unsigned long V_60 )
{
static unsigned int V_69 = 0 ;
static bool V_70 = false ;
T_2 V_71 ;
switch ( V_68 ) {
case V_72 :
case V_73 :
case V_74 :
return;
case V_75 :
case V_76 :
break;
case V_77 :
V_70 = true ;
break;
case V_78 :
if ( V_70 )
return;
break;
default:
F_9 ( L_18 ,
V_34 , ( int ) V_68 ) ;
return;
}
if ( F_35 () )
return;
V_71 = F_33 ( V_57 , V_58 , V_59 , V_60 ,
V_49 , V_48 . V_29 ) ;
( void ) F_8 ( & V_48 , V_49 ,
( int ) V_71 , V_79 , ++ V_69 ) ;
}
