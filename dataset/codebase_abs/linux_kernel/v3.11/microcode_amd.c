static T_1 F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 = V_2 + V_1 ;
return F_2 ( V_4 , V_3 -> V_5 . V_6 ) ;
}
static T_2 F_3 ( T_1 V_7 )
{
int V_8 = 0 ;
F_4 ( ! V_4 ) ;
while ( V_4 [ V_8 ] . V_7 != 0 ) {
if ( V_7 == V_4 [ V_8 ] . V_7 )
return V_4 [ V_8 ] . V_9 ;
V_8 ++ ;
}
return 0 ;
}
static struct V_10 * F_5 ( T_1 V_7 )
{
struct V_10 * V_11 ;
F_6 (p, &pcache, plist)
if ( V_11 -> V_7 == V_7 )
return V_11 ;
return NULL ;
}
static void F_7 ( struct V_10 * V_12 )
{
struct V_10 * V_11 ;
F_6 (p, &pcache, plist) {
if ( V_11 -> V_7 == V_12 -> V_7 ) {
if ( V_11 -> V_13 >= V_12 -> V_13 )
return;
F_8 ( & V_11 -> V_14 , & V_12 -> V_14 ) ;
F_9 ( V_11 -> V_15 ) ;
F_9 ( V_11 ) ;
return;
}
}
F_10 ( & V_12 -> V_14 , & V_16 ) ;
}
static void F_11 ( void )
{
struct V_10 * V_11 , * V_17 ;
F_12 (p, tmp, &pcache, plist) {
F_13 ( V_11 -> V_14 . V_18 , V_11 -> V_14 . V_19 ) ;
F_9 ( V_11 -> V_15 ) ;
F_9 ( V_11 ) ;
}
}
static struct V_10 * F_14 ( unsigned int V_1 )
{
T_1 V_20 ;
V_20 = F_1 ( V_1 ) ;
if ( ! V_20 )
return NULL ;
return F_5 ( V_20 ) ;
}
static int F_15 ( int V_1 , struct V_21 * V_22 )
{
struct V_23 * V_24 = & F_16 ( V_1 ) ;
struct V_2 * V_3 = V_2 + V_1 ;
struct V_10 * V_11 ;
V_22 -> V_6 = F_17 ( 0x00000001 ) ;
V_22 -> V_25 = V_24 -> V_26 ;
V_11 = F_14 ( V_1 ) ;
if ( V_11 && ( V_11 -> V_13 == V_22 -> V_25 ) )
V_3 -> V_27 = V_11 -> V_15 ;
F_18 ( L_1 , V_1 , V_22 -> V_25 ) ;
return 0 ;
}
static unsigned int F_19 ( T_3 V_28 , T_2 V_29 ,
unsigned int V_30 )
{
T_2 V_31 ;
#define F_20 2048
#define F_21 1824
#define F_22 4096
#define F_23 3458
switch ( V_28 ) {
case 0x14 :
V_31 = F_21 ;
break;
case 0x15 :
V_31 = F_22 ;
break;
case 0x16 :
V_31 = F_23 ;
break;
default:
V_31 = F_20 ;
break;
}
if ( V_29 > F_24 ( T_2 , V_30 , V_31 ) ) {
F_25 ( L_2 ) ;
return 0 ;
}
return V_29 ;
}
int F_26 ( struct V_32 * V_33 )
{
T_2 V_25 , V_34 ;
F_27 ( V_35 , ( V_36 ) ( long ) & V_33 -> V_37 . V_38 ) ;
F_28 ( V_39 , V_25 , V_34 ) ;
if ( V_25 != V_33 -> V_37 . V_13 )
return - 1 ;
return 0 ;
}
int F_29 ( int V_1 )
{
struct V_23 * V_24 = & F_16 ( V_1 ) ;
struct V_32 * V_33 ;
struct V_2 * V_3 ;
struct V_10 * V_11 ;
T_2 V_25 , V_34 ;
F_4 ( F_30 () != V_1 ) ;
V_3 = V_2 + V_1 ;
V_11 = F_14 ( V_1 ) ;
if ( ! V_11 )
return 0 ;
V_33 = V_11 -> V_15 ;
V_3 -> V_27 = V_11 -> V_15 ;
F_28 ( V_39 , V_25 , V_34 ) ;
if ( V_25 >= V_33 -> V_37 . V_13 ) {
V_24 -> V_26 = V_25 ;
return 0 ;
}
if ( F_26 ( V_33 ) ) {
F_25 ( L_3 ,
V_1 , V_33 -> V_37 . V_13 ) ;
return - 1 ;
}
F_18 ( L_4 , V_1 ,
V_33 -> V_37 . V_13 ) ;
V_3 -> V_5 . V_25 = V_33 -> V_37 . V_13 ;
V_24 -> V_26 = V_33 -> V_37 . V_13 ;
return 0 ;
}
static int F_31 ( const T_3 * V_40 )
{
unsigned int * V_41 = ( unsigned int * ) V_40 ;
unsigned int type = V_41 [ 1 ] ;
unsigned int V_30 = V_41 [ 2 ] ;
if ( type != V_42 || ! V_30 ) {
F_25 ( L_5
L_6 ) ;
return - V_43 ;
}
V_4 = F_32 ( V_30 ) ;
if ( ! V_4 ) {
F_25 ( L_7 ) ;
return - V_44 ;
}
memcpy ( V_4 , V_40 + V_45 , V_30 ) ;
return V_30 + V_45 ;
}
static void F_33 ( void )
{
F_34 ( V_4 ) ;
V_4 = NULL ;
}
static void F_35 ( void )
{
F_33 () ;
F_11 () ;
}
static int F_36 ( T_3 V_28 , T_3 * V_46 , unsigned int V_47 )
{
struct V_48 * V_49 ;
struct V_10 * V_50 ;
unsigned int V_29 , V_51 , V_52 ;
T_2 V_53 ;
T_1 V_54 ;
V_29 = * ( T_2 * ) ( V_46 + 4 ) ;
V_51 = V_29 + V_55 ;
V_49 = (struct V_48 * ) ( V_46 + V_55 ) ;
V_54 = V_49 -> V_56 ;
V_53 = F_3 ( V_54 ) ;
if ( ! V_53 ) {
F_25 ( L_8 , V_54 ) ;
return V_51 ;
}
V_53 = ( ( V_53 >> 8 ) & 0xf ) + ( ( V_53 >> 20 ) & 0xff ) ;
if ( V_53 != V_28 )
return V_51 ;
if ( V_49 -> V_57 || V_49 -> V_58 ) {
F_25 ( L_9 ,
V_49 -> V_13 ) ;
return V_51 ;
}
V_52 = F_19 ( V_28 , V_29 , V_47 ) ;
if ( ! V_52 ) {
F_25 ( L_10 , V_49 -> V_13 ) ;
return V_51 ;
}
V_50 = F_37 ( sizeof( * V_50 ) , V_59 ) ;
if ( ! V_50 ) {
F_25 ( L_11 ) ;
return - V_43 ;
}
V_50 -> V_15 = F_37 ( V_29 , V_59 ) ;
if ( ! V_50 -> V_15 ) {
F_25 ( L_12 ) ;
F_9 ( V_50 ) ;
return - V_43 ;
}
memcpy ( V_50 -> V_15 , V_46 + V_55 , V_29 ) ;
F_38 ( & V_50 -> V_14 ) ;
V_50 -> V_13 = V_49 -> V_13 ;
V_50 -> V_7 = V_54 ;
F_7 ( V_50 ) ;
return V_51 ;
}
static enum V_60 F_39 ( T_3 V_28 , const T_3 * V_15 ,
T_4 V_30 )
{
enum V_60 V_52 = V_61 ;
unsigned int V_47 ;
T_3 * V_46 = ( T_3 * ) V_15 ;
int V_51 = 0 ;
int V_62 ;
V_62 = F_31 ( V_15 ) ;
if ( V_62 < 0 ) {
F_25 ( L_13 ) ;
return V_52 ;
}
V_46 += V_62 ;
V_47 = V_30 - V_62 ;
if ( * ( T_2 * ) V_46 != V_63 ) {
F_25 ( L_6 ) ;
F_33 () ;
return V_52 ;
}
while ( V_47 ) {
V_51 = F_36 ( V_28 , V_46 , V_47 ) ;
if ( V_51 < 0 )
return V_52 ;
V_46 += V_51 ;
V_47 -= V_51 ;
}
return V_64 ;
}
enum V_60 F_40 ( T_3 V_28 , const T_3 * V_15 , T_4 V_30 )
{
enum V_60 V_52 ;
F_33 () ;
V_52 = F_39 ( V_28 , V_15 , V_30 ) ;
if ( V_52 != V_64 )
F_35 () ;
#if F_41 ( V_65 ) && F_41 ( V_66 )
if ( F_16 ( F_42 () ) . V_67 == V_68 . V_67 ) {
struct V_10 * V_11 = F_14 ( F_42 () ) ;
if ( V_11 ) {
memset ( V_69 , 0 , V_70 ) ;
memcpy ( V_69 , V_11 -> V_15 , F_24 ( T_2 , F_43 ( V_11 -> V_15 ) ,
V_70 ) ) ;
}
}
#endif
return V_52 ;
}
static enum V_60 F_44 ( int V_1 , struct V_71 * V_71 ,
bool V_72 )
{
char V_73 [ 36 ] = L_14 ;
struct V_23 * V_24 = & F_16 ( V_1 ) ;
enum V_60 V_52 = V_74 ;
const struct V_75 * V_46 ;
if ( ! V_72 || V_24 -> V_67 != V_68 . V_67 )
return V_64 ;
if ( V_24 -> V_76 >= 0x15 )
snprintf ( V_73 , sizeof( V_73 ) , L_15 , V_24 -> V_76 ) ;
if ( F_45 ( & V_46 , ( const char * ) V_73 , V_71 ) ) {
F_25 ( L_16 , V_73 ) ;
goto V_77;
}
V_52 = V_61 ;
if ( * ( T_2 * ) V_46 -> V_15 != V_78 ) {
F_25 ( L_17 , * ( T_2 * ) V_46 -> V_15 ) ;
goto V_79;
}
V_52 = F_40 ( V_24 -> V_76 , V_46 -> V_15 , V_46 -> V_30 ) ;
V_79:
F_46 ( V_46 ) ;
V_77:
return V_52 ;
}
static enum V_60
F_47 ( int V_1 , const void T_5 * V_40 , T_4 V_30 )
{
return V_61 ;
}
static void F_48 ( int V_1 )
{
struct V_2 * V_3 = V_2 + V_1 ;
V_3 -> V_27 = NULL ;
}
struct V_80 * T_6 F_49 ( void )
{
struct V_23 * V_24 = & F_16 ( 0 ) ;
if ( V_24 -> V_81 != V_82 || V_24 -> V_76 < 0x10 ) {
F_50 ( L_18 , V_24 -> V_76 ) ;
return NULL ;
}
return & V_83 ;
}
void T_7 F_51 ( void )
{
F_35 () ;
}
