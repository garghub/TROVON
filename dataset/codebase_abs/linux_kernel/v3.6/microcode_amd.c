static int F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = & F_2 ( V_1 ) ;
V_3 -> V_6 = V_5 -> V_7 ;
F_3 ( L_1 , V_1 , V_3 -> V_6 ) ;
return 0 ;
}
static unsigned int F_4 ( int V_1 , T_1 V_8 ,
unsigned int V_9 )
{
struct V_4 * V_5 = & F_2 ( V_1 ) ;
T_1 V_10 ;
#define F_5 2048
#define F_6 1824
#define F_7 4096
switch ( V_5 -> V_11 ) {
case 0x14 :
V_10 = F_6 ;
break;
case 0x15 :
V_10 = F_7 ;
break;
default:
V_10 = F_5 ;
break;
}
if ( V_8 > F_8 ( T_1 , V_9 , V_10 ) ) {
F_9 ( L_2 ) ;
return 0 ;
}
return V_8 ;
}
static T_2 F_10 ( void )
{
unsigned int V_12 , V_13 = 0 ;
F_11 ( V_14 == NULL ) ;
V_12 = F_12 ( 0x00000001 ) ;
while ( V_14 [ V_13 ] . V_15 != 0 ) {
if ( V_12 == V_14 [ V_13 ] . V_15 )
return V_14 [ V_13 ] . V_16 ;
V_13 ++ ;
}
return 0 ;
}
static int F_13 ( int V_1 , const T_3 * V_17 ,
unsigned int V_18 , int V_6 ,
unsigned int * V_19 )
{
struct V_20 * V_21 ;
unsigned int V_22 , V_8 ;
T_2 V_23 ;
V_8 = * ( T_1 * ) ( V_17 + 4 ) ;
* V_19 = V_8 + V_24 ;
V_23 = F_10 () ;
if ( ! V_23 )
return 0 ;
V_21 = (struct V_20 * ) ( V_17 + V_24 ) ;
if ( V_21 -> V_25 != V_23 )
return 0 ;
if ( V_21 -> V_26 || V_21 -> V_27 ) {
F_9 ( L_3 ,
V_1 ) ;
return 0 ;
}
if ( V_21 -> V_28 <= V_6 )
return 0 ;
V_22 = F_4 ( V_1 , V_8 , V_18 ) ;
if ( ! V_22 )
return 0 ;
memset ( V_29 , 0 , V_30 ) ;
F_14 ( V_29 , V_17 + V_24 , V_22 ) ;
return V_22 ;
}
static int F_15 ( int V_1 )
{
T_1 V_6 , V_31 ;
int V_32 = F_16 () ;
struct V_33 * V_34 = V_33 + V_32 ;
struct V_35 * V_36 = V_34 -> V_37 ;
struct V_4 * V_5 = & F_2 ( V_1 ) ;
F_11 ( V_32 != V_1 ) ;
if ( V_36 == NULL )
return 0 ;
F_17 ( V_38 , ( V_39 ) ( long ) & V_36 -> V_40 . V_41 ) ;
F_18 ( V_42 , V_6 , V_31 ) ;
if ( V_6 != V_36 -> V_40 . V_28 ) {
F_9 ( L_4 ,
V_1 , V_36 -> V_40 . V_28 ) ;
return - 1 ;
}
F_3 ( L_5 , V_1 , V_6 ) ;
V_34 -> V_43 . V_6 = V_6 ;
V_5 -> V_7 = V_6 ;
return 0 ;
}
static int F_19 ( const T_3 * V_44 )
{
unsigned int * V_45 = ( unsigned int * ) V_44 ;
unsigned int type = V_45 [ 1 ] ;
unsigned int V_9 = V_45 [ 2 ] ;
if ( type != V_46 || ! V_9 ) {
F_9 ( L_6
L_7 ) ;
return - V_47 ;
}
V_14 = F_20 ( V_9 ) ;
if ( ! V_14 ) {
F_9 ( L_8 ) ;
return - V_48 ;
}
F_14 ( V_14 , V_44 + V_49 , V_9 ) ;
return V_9 + V_49 ;
}
static void F_21 ( void )
{
F_22 ( V_14 ) ;
V_14 = NULL ;
}
static enum V_50
F_23 ( int V_1 , const T_3 * V_51 , T_4 V_9 )
{
struct V_33 * V_34 = V_33 + V_1 ;
struct V_20 * V_21 = NULL ;
unsigned int V_52 , V_53 , V_19 = 0 ;
int V_54 ;
const T_3 * V_17 = V_51 ;
void * V_55 = NULL ;
unsigned int V_56 = V_34 -> V_43 . V_6 ;
enum V_50 V_57 = V_58 ;
V_54 = F_19 ( V_17 ) ;
if ( V_54 < 0 ) {
F_9 ( L_9 ) ;
goto V_59;
}
V_17 += V_54 ;
V_53 = V_9 - V_54 ;
if ( * ( T_1 * ) V_17 != V_60 ) {
F_9 ( L_7 ) ;
goto V_61;
}
while ( V_53 ) {
V_52 = F_13 ( V_1 , V_17 , V_53 ,
V_56 , & V_19 ) ;
if ( V_52 ) {
V_21 = V_29 ;
V_55 = V_29 ;
V_56 = V_21 -> V_28 ;
goto V_62;
}
V_17 += V_19 ;
V_53 -= V_19 ;
}
if ( ! V_55 ) {
V_57 = V_63 ;
goto V_61;
}
V_62:
V_34 -> V_37 = V_55 ;
V_57 = V_64 ;
F_24 ( L_10 ,
V_1 , V_34 -> V_43 . V_6 , V_56 ) ;
V_61:
F_21 () ;
V_59:
return V_57 ;
}
static enum V_50 F_25 ( int V_1 , struct V_65 * V_65 )
{
char V_66 [ 36 ] = L_11 ;
const struct V_67 * V_68 ;
enum V_50 V_69 = V_63 ;
struct V_4 * V_5 = & F_2 ( V_1 ) ;
if ( V_5 -> V_11 >= 0x15 )
snprintf ( V_66 , sizeof( V_66 ) , L_12 , V_5 -> V_11 ) ;
if ( F_26 ( & V_68 , ( const char * ) V_66 , V_65 ) ) {
F_9 ( L_13 , V_66 ) ;
goto V_59;
}
V_69 = V_58 ;
if ( * ( T_1 * ) V_68 -> V_51 != V_70 ) {
F_9 ( L_14 , * ( T_1 * ) V_68 -> V_51 ) ;
goto V_71;
}
V_69 = F_23 ( V_1 , V_68 -> V_51 , V_68 -> V_9 ) ;
V_71:
F_27 ( V_68 ) ;
V_59:
return V_69 ;
}
static enum V_50
F_28 ( int V_1 , const void T_5 * V_44 , T_4 V_9 )
{
return V_58 ;
}
static void F_29 ( int V_1 )
{
struct V_33 * V_34 = V_33 + V_1 ;
V_34 -> V_37 = NULL ;
}
struct V_72 * T_6 F_30 ( void )
{
struct V_4 * V_5 = & F_2 ( 0 ) ;
if ( V_5 -> V_73 != V_74 || V_5 -> V_11 < 0x10 ) {
F_31 ( L_15 , V_5 -> V_11 ) ;
return NULL ;
}
V_29 = ( void * ) F_32 ( V_75 ) ;
if ( ! V_29 )
return NULL ;
return & V_76 ;
}
void T_7 F_33 ( void )
{
F_34 ( ( unsigned long ) V_29 ) ;
}
