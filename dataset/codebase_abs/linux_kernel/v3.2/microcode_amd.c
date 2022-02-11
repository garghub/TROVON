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
static int F_5 ( int V_1 , struct V_11 * V_12 ,
int V_9 )
{
unsigned int V_13 ;
T_1 V_14 = 0 ;
unsigned int V_15 = 0 ;
F_6 ( V_16 == NULL ) ;
V_13 = F_7 ( 0x00000001 ) ;
while ( V_16 [ V_15 ] . V_17 != 0 ) {
if ( V_13 == V_16 [ V_15 ] . V_17 ) {
V_14 = V_16 [ V_15 ] . V_18 ;
break;
}
V_15 ++ ;
}
if ( ! V_14 )
return 0 ;
if ( V_12 -> V_19 != V_14 )
return 0 ;
if ( V_12 -> V_20 || V_12 -> V_21 ) {
F_8 ( L_3 ,
V_1 ) ;
return 0 ;
}
if ( V_12 -> V_22 <= V_9 )
return 0 ;
return 1 ;
}
static int F_9 ( int V_1 )
{
T_2 V_9 , V_23 ;
int V_24 = F_10 () ;
struct V_25 * V_26 = V_25 + V_24 ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_4 * V_5 = & F_2 ( V_1 ) ;
F_6 ( V_24 != V_1 ) ;
if ( V_28 == NULL )
return 0 ;
F_11 ( V_30 , ( V_31 ) ( long ) & V_28 -> V_32 . V_33 ) ;
F_12 ( V_34 , V_9 , V_23 ) ;
if ( V_9 != V_28 -> V_32 . V_22 ) {
F_8 ( L_4 ,
V_1 , V_28 -> V_32 . V_22 ) ;
return - 1 ;
}
F_4 ( L_5 , V_1 , V_9 ) ;
V_26 -> V_35 . V_9 = V_9 ;
V_5 -> V_10 = V_9 ;
return 0 ;
}
static unsigned int F_13 ( int V_1 , const T_3 * V_36 , unsigned int V_37 )
{
struct V_4 * V_5 = & F_2 ( V_1 ) ;
T_2 V_38 , V_39 ;
#define F_14 2048
#define F_15 1824
#define F_16 4096
switch ( V_5 -> V_8 ) {
case 0x14 :
V_38 = F_15 ;
break;
case 0x15 :
V_38 = F_16 ;
break;
default:
V_38 = F_14 ;
break;
}
V_39 = * ( T_2 * ) ( V_36 + 4 ) ;
if ( V_39 + V_40 > V_37 || V_39 > V_38 ) {
F_8 ( L_6 ) ;
return 0 ;
}
return V_39 ;
}
static struct V_11 *
F_17 ( int V_1 , const T_3 * V_36 , unsigned int V_37 , unsigned int * V_41 )
{
struct V_11 * V_29 = NULL ;
unsigned int V_39 = 0 ;
if ( * ( T_2 * ) V_36 != V_42 ) {
F_8 ( L_7 ) ;
goto V_43;
}
V_39 = F_13 ( V_1 , V_36 , V_37 ) ;
if ( ! V_39 )
goto V_43;
V_29 = F_18 ( V_39 ) ;
if ( ! V_29 )
goto V_43;
F_19 ( V_29 , V_36 + V_40 , V_39 ) ;
* V_41 = V_39 + V_40 ;
V_43:
return V_29 ;
}
static int F_20 ( const T_3 * V_36 )
{
unsigned int * V_44 = ( unsigned int * ) V_36 ;
unsigned int type = V_44 [ 1 ] ;
unsigned int V_37 = V_44 [ 2 ] ;
if ( type != V_45 || ! V_37 ) {
F_8 ( L_8
L_7 ) ;
return - V_46 ;
}
V_16 = F_21 ( V_37 ) ;
if ( ! V_16 ) {
F_8 ( L_9 ) ;
return - V_47 ;
}
F_19 ( V_16 , V_36 + V_48 , V_37 ) ;
return V_37 + V_48 ;
}
static void F_22 ( void )
{
F_23 ( V_16 ) ;
V_16 = NULL ;
}
static enum V_49
F_24 ( int V_1 , const T_3 * V_50 , T_4 V_37 )
{
struct V_25 * V_26 = V_25 + V_1 ;
struct V_11 * V_12 = NULL ;
unsigned int V_41 , V_51 ;
int V_52 ;
const T_3 * V_53 = V_50 ;
void * V_54 = NULL ;
unsigned int V_55 = V_26 -> V_35 . V_9 ;
enum V_49 V_56 = V_57 ;
V_52 = F_20 ( V_53 ) ;
if ( V_52 < 0 ) {
F_8 ( L_10 ) ;
return V_58 ;
}
V_53 += V_52 ;
V_51 = V_37 - V_52 ;
while ( V_51 ) {
V_12 = F_17 ( V_1 , V_53 , V_51 , & V_41 ) ;
if ( ! V_12 )
break;
if ( F_5 ( V_1 , V_12 , V_55 ) ) {
F_23 ( V_54 ) ;
V_55 = V_12 -> V_22 ;
V_54 = V_12 ;
} else
F_23 ( V_12 ) ;
V_53 += V_41 ;
V_51 -= V_41 ;
}
if ( ! V_54 ) {
V_56 = V_59 ;
goto V_60;
}
if ( ! V_51 ) {
F_23 ( V_26 -> V_29 ) ;
V_26 -> V_29 = V_54 ;
F_25 ( L_11 ,
V_1 , V_26 -> V_35 . V_9 , V_55 ) ;
} else {
F_23 ( V_54 ) ;
V_56 = V_58 ;
}
V_60:
F_22 () ;
return V_56 ;
}
static enum V_49 F_26 ( int V_1 , struct V_61 * V_61 )
{
const char * V_62 = L_12 ;
const struct V_63 * V_64 ;
enum V_49 V_65 = V_59 ;
if ( F_27 ( & V_64 , V_62 , V_61 ) ) {
F_8 ( L_13 , V_62 ) ;
goto V_43;
}
V_65 = V_58 ;
if ( * ( T_2 * ) V_64 -> V_50 != V_66 ) {
F_8 ( L_14 , * ( T_2 * ) V_64 -> V_50 ) ;
goto V_67;
}
V_65 = F_24 ( V_1 , V_64 -> V_50 , V_64 -> V_37 ) ;
V_67:
F_28 ( V_64 ) ;
V_43:
return V_65 ;
}
static enum V_49
F_29 ( int V_1 , const void T_5 * V_36 , T_4 V_37 )
{
F_4 ( L_15 ) ;
return V_58 ;
}
static void F_30 ( int V_1 )
{
struct V_25 * V_26 = V_25 + V_1 ;
F_23 ( V_26 -> V_29 ) ;
V_26 -> V_29 = NULL ;
}
struct V_68 * T_6 F_31 ( void )
{
return & V_69 ;
}
