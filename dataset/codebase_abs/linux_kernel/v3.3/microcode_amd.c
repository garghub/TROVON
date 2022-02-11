static int F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = & F_2 ( V_1 ) ;
if ( V_5 -> V_6 != V_7 || V_5 -> V_8 < 0x10 ) {
F_3 ( L_1 , V_1 , V_5 -> V_8 ) ;
return - 1 ;
}
V_3 -> V_9 = V_5 -> V_10 ;
F_4 ( L_2 , V_1 , V_3 -> V_9 ) ;
return 0 ;
}
static unsigned int F_5 ( int V_1 , T_1 V_11 ,
unsigned int V_12 )
{
struct V_4 * V_5 = & F_2 ( V_1 ) ;
T_1 V_13 ;
#define F_6 2048
#define F_7 1824
#define F_8 4096
switch ( V_5 -> V_8 ) {
case 0x14 :
V_13 = F_7 ;
break;
case 0x15 :
V_13 = F_8 ;
break;
default:
V_13 = F_6 ;
break;
}
if ( V_11 > F_9 ( T_1 , V_12 , V_13 ) ) {
F_10 ( L_3 ) ;
return 0 ;
}
return V_11 ;
}
static T_2 F_11 ( void )
{
unsigned int V_14 , V_15 = 0 ;
F_12 ( V_16 == NULL ) ;
V_14 = F_13 ( 0x00000001 ) ;
while ( V_16 [ V_15 ] . V_17 != 0 ) {
if ( V_14 == V_16 [ V_15 ] . V_17 )
return V_16 [ V_15 ] . V_18 ;
V_15 ++ ;
}
return 0 ;
}
static int F_14 ( int V_1 , const T_3 * V_19 ,
unsigned int V_20 , int V_9 ,
unsigned int * V_21 )
{
struct V_22 * V_23 ;
unsigned int V_24 ;
T_2 V_25 ;
* V_21 = * ( T_1 * ) ( V_19 + 4 ) + V_26 ;
V_25 = F_11 () ;
if ( ! V_25 )
return 0 ;
V_23 = (struct V_22 * ) ( V_19 + V_26 ) ;
if ( V_23 -> V_27 != V_25 )
return 0 ;
if ( V_23 -> V_28 || V_23 -> V_29 ) {
F_10 ( L_4 ,
V_1 ) ;
return 0 ;
}
if ( V_23 -> V_30 <= V_9 )
return 0 ;
V_24 = F_5 ( V_1 , * V_21 , V_20 ) ;
if ( ! V_24 )
return 0 ;
memset ( V_31 , 0 , V_32 ) ;
F_15 ( V_31 , V_19 + V_26 , V_24 ) ;
return V_24 ;
}
static int F_16 ( int V_1 )
{
T_1 V_9 , V_33 ;
int V_34 = F_17 () ;
struct V_35 * V_36 = V_35 + V_34 ;
struct V_37 * V_38 = V_36 -> V_39 ;
struct V_4 * V_5 = & F_2 ( V_1 ) ;
F_12 ( V_34 != V_1 ) ;
if ( V_38 == NULL )
return 0 ;
F_18 ( V_40 , ( V_41 ) ( long ) & V_38 -> V_42 . V_43 ) ;
F_19 ( V_44 , V_9 , V_33 ) ;
if ( V_9 != V_38 -> V_42 . V_30 ) {
F_10 ( L_5 ,
V_1 , V_38 -> V_42 . V_30 ) ;
return - 1 ;
}
F_4 ( L_6 , V_1 , V_9 ) ;
V_36 -> V_45 . V_9 = V_9 ;
V_5 -> V_10 = V_9 ;
return 0 ;
}
static int F_20 ( const T_3 * V_46 )
{
unsigned int * V_47 = ( unsigned int * ) V_46 ;
unsigned int type = V_47 [ 1 ] ;
unsigned int V_12 = V_47 [ 2 ] ;
if ( type != V_48 || ! V_12 ) {
F_10 ( L_7
L_8 ) ;
return - V_49 ;
}
V_16 = F_21 ( V_12 ) ;
if ( ! V_16 ) {
F_10 ( L_9 ) ;
return - V_50 ;
}
F_15 ( V_16 , V_46 + V_51 , V_12 ) ;
return V_12 + V_51 ;
}
static void F_22 ( void )
{
F_23 ( V_16 ) ;
V_16 = NULL ;
}
static enum V_52
F_24 ( int V_1 , const T_3 * V_53 , T_4 V_12 )
{
struct V_35 * V_36 = V_35 + V_1 ;
struct V_22 * V_23 = NULL ;
unsigned int V_54 , V_55 , V_21 = 0 ;
int V_56 ;
const T_3 * V_19 = V_53 ;
void * V_57 = NULL ;
unsigned int V_58 = V_36 -> V_45 . V_9 ;
enum V_52 V_59 = V_60 ;
V_56 = F_20 ( V_19 ) ;
if ( V_56 < 0 ) {
F_10 ( L_10 ) ;
goto V_61;
}
V_19 += V_56 ;
V_55 = V_12 - V_56 ;
if ( * ( T_1 * ) V_19 != V_62 ) {
F_10 ( L_8 ) ;
goto V_63;
}
while ( V_55 ) {
V_54 = F_14 ( V_1 , V_19 , V_55 ,
V_58 , & V_21 ) ;
if ( V_54 ) {
V_23 = V_31 ;
V_57 = V_31 ;
V_58 = V_23 -> V_30 ;
goto V_64;
}
V_19 += V_21 ;
V_55 -= V_21 ;
}
if ( ! V_57 ) {
V_59 = V_65 ;
goto V_63;
}
V_64:
V_36 -> V_39 = V_57 ;
V_59 = V_66 ;
F_25 ( L_11 ,
V_1 , V_36 -> V_45 . V_9 , V_58 ) ;
V_63:
F_22 () ;
V_61:
return V_59 ;
}
static enum V_52 F_26 ( int V_1 , struct V_67 * V_67 )
{
char V_68 [ 36 ] = L_12 ;
const struct V_69 * V_70 ;
enum V_52 V_71 = V_65 ;
struct V_4 * V_5 = & F_2 ( V_1 ) ;
if ( V_5 -> V_8 >= 0x15 )
snprintf ( V_68 , sizeof( V_68 ) , L_13 , V_5 -> V_8 ) ;
if ( F_27 ( & V_70 , ( const char * ) V_68 , V_67 ) ) {
F_10 ( L_14 , V_68 ) ;
goto V_61;
}
V_71 = V_60 ;
if ( * ( T_1 * ) V_70 -> V_53 != V_72 ) {
F_10 ( L_15 , * ( T_1 * ) V_70 -> V_53 ) ;
goto V_73;
}
V_71 = F_24 ( V_1 , V_70 -> V_53 , V_70 -> V_12 ) ;
V_73:
F_28 ( V_70 ) ;
V_61:
return V_71 ;
}
static enum V_52
F_29 ( int V_1 , const void T_5 * V_46 , T_4 V_12 )
{
return V_60 ;
}
static void F_30 ( int V_1 )
{
struct V_35 * V_36 = V_35 + V_1 ;
V_36 -> V_39 = NULL ;
}
struct V_74 * T_6 F_31 ( void )
{
V_31 = ( void * ) F_32 ( V_75 ) ;
if ( ! V_31 )
return NULL ;
return & V_76 ;
}
void T_7 F_33 ( void )
{
F_34 ( ( unsigned long ) V_31 ) ;
}
