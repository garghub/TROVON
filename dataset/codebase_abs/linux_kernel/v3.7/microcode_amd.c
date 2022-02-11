static T_1 F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 = V_2 + V_1 ;
int V_4 = 0 ;
if ( ! V_5 )
return 0 ;
while ( V_5 [ V_4 ] . V_6 != 0 ) {
if ( V_3 -> V_7 . V_8 == V_5 [ V_4 ] . V_6 )
return V_5 [ V_4 ] . V_9 ;
V_4 ++ ;
}
return 0 ;
}
static T_2 F_2 ( T_1 V_9 )
{
int V_4 = 0 ;
F_3 ( ! V_5 ) ;
while ( V_5 [ V_4 ] . V_9 != 0 ) {
if ( V_9 == V_5 [ V_4 ] . V_9 )
return V_5 [ V_4 ] . V_6 ;
V_4 ++ ;
}
return 0 ;
}
static struct V_10 * F_4 ( T_1 V_9 )
{
struct V_10 * V_11 ;
F_5 (p, &pcache, plist)
if ( V_11 -> V_9 == V_9 )
return V_11 ;
return NULL ;
}
static void F_6 ( struct V_10 * V_12 )
{
struct V_10 * V_11 ;
F_5 (p, &pcache, plist) {
if ( V_11 -> V_9 == V_12 -> V_9 ) {
if ( V_11 -> V_13 >= V_12 -> V_13 )
return;
F_7 ( & V_11 -> V_14 , & V_12 -> V_14 ) ;
F_8 ( V_11 -> V_15 ) ;
F_8 ( V_11 ) ;
return;
}
}
F_9 ( & V_12 -> V_14 , & V_16 ) ;
}
static void F_10 ( void )
{
struct V_10 * V_11 , * V_17 ;
F_11 (p, tmp, &pcache, plist) {
F_12 ( V_11 -> V_14 . V_18 , V_11 -> V_14 . V_19 ) ;
F_8 ( V_11 -> V_15 ) ;
F_8 ( V_11 ) ;
}
}
static struct V_10 * F_13 ( unsigned int V_1 )
{
T_1 V_20 ;
V_20 = F_1 ( V_1 ) ;
if ( ! V_20 )
return NULL ;
return F_4 ( V_20 ) ;
}
static int F_14 ( int V_1 , struct V_21 * V_22 )
{
struct V_23 * V_24 = & F_15 ( V_1 ) ;
V_22 -> V_8 = F_16 ( 0x00000001 ) ;
V_22 -> V_25 = V_24 -> V_26 ;
F_17 ( L_1 , V_1 , V_22 -> V_25 ) ;
return 0 ;
}
static unsigned int F_18 ( int V_1 , T_2 V_27 ,
unsigned int V_28 )
{
struct V_23 * V_24 = & F_15 ( V_1 ) ;
T_2 V_29 ;
#define F_19 2048
#define F_20 1824
#define F_21 4096
#define F_22 3458
switch ( V_24 -> V_30 ) {
case 0x14 :
V_29 = F_20 ;
break;
case 0x15 :
V_29 = F_21 ;
break;
case 0x16 :
V_29 = F_22 ;
break;
default:
V_29 = F_19 ;
break;
}
if ( V_27 > F_23 ( T_2 , V_28 , V_29 ) ) {
F_24 ( L_2 ) ;
return 0 ;
}
return V_27 ;
}
static int F_25 ( int V_1 )
{
struct V_23 * V_24 = & F_15 ( V_1 ) ;
struct V_31 * V_32 ;
struct V_2 * V_3 ;
struct V_10 * V_11 ;
T_2 V_25 , V_33 ;
F_3 ( F_26 () != V_1 ) ;
V_3 = V_2 + V_1 ;
V_11 = F_13 ( V_1 ) ;
if ( ! V_11 )
return 0 ;
V_32 = V_11 -> V_15 ;
V_3 -> V_34 = V_11 -> V_15 ;
F_27 ( V_35 , V_25 , V_33 ) ;
if ( V_25 >= V_32 -> V_36 . V_13 ) {
V_24 -> V_26 = V_25 ;
return 0 ;
}
F_28 ( V_37 , ( V_38 ) ( long ) & V_32 -> V_36 . V_39 ) ;
F_27 ( V_35 , V_25 , V_33 ) ;
if ( V_25 != V_32 -> V_36 . V_13 ) {
F_24 ( L_3 ,
V_1 , V_32 -> V_36 . V_13 ) ;
return - 1 ;
}
F_17 ( L_4 , V_1 , V_25 ) ;
V_3 -> V_7 . V_25 = V_25 ;
V_24 -> V_26 = V_25 ;
return 0 ;
}
static int F_29 ( const T_3 * V_40 )
{
unsigned int * V_41 = ( unsigned int * ) V_40 ;
unsigned int type = V_41 [ 1 ] ;
unsigned int V_28 = V_41 [ 2 ] ;
if ( type != V_42 || ! V_28 ) {
F_24 ( L_5
L_6 ) ;
return - V_43 ;
}
V_5 = F_30 ( V_28 ) ;
if ( ! V_5 ) {
F_24 ( L_7 ) ;
return - V_44 ;
}
memcpy ( V_5 , V_40 + V_45 , V_28 ) ;
return V_28 + V_45 ;
}
static void F_31 ( void )
{
F_32 ( V_5 ) ;
V_5 = NULL ;
}
static void F_33 ( void )
{
F_31 () ;
F_10 () ;
}
static int F_34 ( unsigned int V_1 , T_3 * V_46 , unsigned int V_47 )
{
struct V_23 * V_24 = & F_15 ( V_1 ) ;
struct V_48 * V_49 ;
struct V_10 * V_50 ;
unsigned int V_27 , V_51 , V_52 ;
T_2 V_53 ;
T_1 V_54 ;
V_27 = * ( T_2 * ) ( V_46 + 4 ) ;
V_51 = V_27 + V_55 ;
V_49 = (struct V_48 * ) ( V_46 + V_55 ) ;
V_54 = V_49 -> V_56 ;
V_53 = F_2 ( V_54 ) ;
if ( ! V_53 ) {
F_24 ( L_8 , V_54 ) ;
return V_51 ;
}
V_53 = ( ( V_53 >> 8 ) & 0xf ) + ( ( V_53 >> 20 ) & 0xff ) ;
if ( V_53 != V_24 -> V_30 )
return V_51 ;
if ( V_49 -> V_57 || V_49 -> V_58 ) {
F_24 ( L_9 ,
V_49 -> V_13 ) ;
return V_51 ;
}
V_52 = F_18 ( V_1 , V_27 , V_47 ) ;
if ( ! V_52 ) {
F_24 ( L_10 , V_49 -> V_13 ) ;
return V_51 ;
}
V_50 = F_35 ( sizeof( * V_50 ) , V_59 ) ;
if ( ! V_50 ) {
F_24 ( L_11 ) ;
return - V_43 ;
}
V_50 -> V_15 = F_35 ( V_27 , V_59 ) ;
if ( ! V_50 -> V_15 ) {
F_24 ( L_12 ) ;
F_8 ( V_50 ) ;
return - V_43 ;
}
memcpy ( V_50 -> V_15 , V_46 + V_55 , V_27 ) ;
F_36 ( & V_50 -> V_14 ) ;
V_50 -> V_13 = V_49 -> V_13 ;
V_50 -> V_9 = V_54 ;
F_6 ( V_50 ) ;
return V_51 ;
}
static enum V_60 F_37 ( int V_1 , const T_3 * V_15 , T_4 V_28 )
{
enum V_60 V_52 = V_61 ;
unsigned int V_47 ;
T_3 * V_46 = ( T_3 * ) V_15 ;
int V_51 = 0 ;
int V_62 ;
V_62 = F_29 ( V_15 ) ;
if ( V_62 < 0 ) {
F_24 ( L_13 ) ;
return V_52 ;
}
V_46 += V_62 ;
V_47 = V_28 - V_62 ;
if ( * ( T_2 * ) V_46 != V_63 ) {
F_24 ( L_6 ) ;
F_31 () ;
return V_52 ;
}
while ( V_47 ) {
V_51 = F_34 ( V_1 , V_46 , V_47 ) ;
if ( V_51 < 0 )
return V_52 ;
V_46 += V_51 ;
V_47 -= V_51 ;
}
return V_64 ;
}
static enum V_60 F_38 ( int V_1 , struct V_65 * V_65 ,
bool V_66 )
{
char V_67 [ 36 ] = L_14 ;
struct V_23 * V_24 = & F_15 ( V_1 ) ;
enum V_60 V_52 = V_68 ;
const struct V_69 * V_46 ;
if ( ! V_66 || V_24 -> V_70 != V_71 . V_70 )
return V_64 ;
if ( V_24 -> V_30 >= 0x15 )
snprintf ( V_67 , sizeof( V_67 ) , L_15 , V_24 -> V_30 ) ;
if ( F_39 ( & V_46 , ( const char * ) V_67 , V_65 ) ) {
F_24 ( L_16 , V_67 ) ;
goto V_72;
}
V_52 = V_61 ;
if ( * ( T_2 * ) V_46 -> V_15 != V_73 ) {
F_24 ( L_17 , * ( T_2 * ) V_46 -> V_15 ) ;
goto V_74;
}
F_31 () ;
V_52 = F_37 ( V_1 , V_46 -> V_15 , V_46 -> V_28 ) ;
if ( V_52 != V_64 )
F_33 () ;
V_74:
F_40 ( V_46 ) ;
V_72:
return V_52 ;
}
static enum V_60
F_41 ( int V_1 , const void T_5 * V_40 , T_4 V_28 )
{
return V_61 ;
}
static void F_42 ( int V_1 )
{
struct V_2 * V_3 = V_2 + V_1 ;
V_3 -> V_34 = NULL ;
}
struct V_75 * T_6 F_43 ( void )
{
struct V_23 * V_24 = & F_15 ( 0 ) ;
if ( V_24 -> V_76 != V_77 || V_24 -> V_30 < 0x10 ) {
F_44 ( L_18 , V_24 -> V_30 ) ;
return NULL ;
}
return & V_78 ;
}
void T_7 F_45 ( void )
{
F_33 () ;
}
