static int F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = & F_2 ( V_1 ) ;
T_1 V_6 ;
if ( V_5 -> V_7 != V_8 || V_5 -> V_9 < 0x10 ) {
F_3 ( L_1 , V_1 , V_5 -> V_9 ) ;
return - 1 ;
}
F_4 ( V_10 , V_3 -> V_11 , V_6 ) ;
F_5 ( L_2 , V_1 , V_3 -> V_11 ) ;
return 0 ;
}
static int F_6 ( int V_1 , struct V_12 * V_13 ,
int V_11 )
{
unsigned int V_14 ;
T_2 V_15 = 0 ;
unsigned int V_16 = 0 ;
F_7 ( V_17 == NULL ) ;
V_14 = F_8 ( 0x00000001 ) ;
while ( V_17 [ V_16 ] . V_18 != 0 ) {
if ( V_14 == V_17 [ V_16 ] . V_18 ) {
V_15 = V_17 [ V_16 ] . V_19 ;
break;
}
V_16 ++ ;
}
if ( ! V_15 )
return 0 ;
if ( V_13 -> V_20 != V_15 )
return 0 ;
if ( V_13 -> V_21 || V_13 -> V_22 ) {
F_9 ( L_3 ,
V_1 ) ;
return 0 ;
}
if ( V_13 -> V_23 <= V_11 )
return 0 ;
return 1 ;
}
static int F_10 ( int V_1 )
{
T_1 V_11 , V_6 ;
int V_24 = F_11 () ;
struct V_25 * V_26 = V_25 + V_24 ;
struct V_27 * V_28 = V_26 -> V_29 ;
F_7 ( V_24 != V_1 ) ;
if ( V_28 == NULL )
return 0 ;
F_12 ( V_30 , ( V_31 ) ( long ) & V_28 -> V_32 . V_33 ) ;
F_4 ( V_10 , V_11 , V_6 ) ;
if ( V_11 != V_28 -> V_32 . V_23 ) {
F_9 ( L_4 ,
V_1 , V_28 -> V_32 . V_23 ) ;
return - 1 ;
}
F_5 ( L_5 , V_1 , V_11 ) ;
V_26 -> V_34 . V_11 = V_11 ;
return 0 ;
}
static unsigned int F_13 ( int V_1 , const T_3 * V_35 , unsigned int V_36 )
{
struct V_4 * V_5 = & F_2 ( V_1 ) ;
unsigned int V_37 , V_38 ;
#define F_14 2048
#define F_15 1824
#define F_16 4096
switch ( V_5 -> V_9 ) {
case 0x14 :
V_37 = F_15 ;
break;
case 0x15 :
V_37 = F_16 ;
break;
default:
V_37 = F_14 ;
break;
}
V_38 = V_35 [ 4 ] + ( V_35 [ 5 ] << 8 ) ;
if ( V_38 > V_36 || V_38 > V_37 ) {
F_9 ( L_6 ) ;
return 0 ;
}
return V_38 ;
}
static struct V_12 *
F_17 ( int V_1 , const T_3 * V_35 , unsigned int V_36 , unsigned int * V_39 )
{
struct V_12 * V_29 = NULL ;
unsigned int V_38 = 0 ;
if ( V_35 [ 0 ] != V_40 ) {
F_9 ( L_7 ) ;
goto V_41;
}
V_38 = F_13 ( V_1 , V_35 , V_36 ) ;
if ( ! V_38 )
goto V_41;
V_29 = F_18 ( V_38 ) ;
if ( ! V_29 )
goto V_41;
F_19 ( V_29 , V_35 + V_42 , V_38 ) ;
* V_39 = V_38 + V_42 ;
V_41:
return V_29 ;
}
static int F_20 ( const T_3 * V_35 )
{
unsigned int * V_43 = ( unsigned int * ) V_35 ;
unsigned int type = V_43 [ 1 ] ;
unsigned int V_36 = V_43 [ 2 ] ;
if ( type != V_44 || ! V_36 ) {
F_9 ( L_8
L_7 ) ;
return - V_45 ;
}
V_17 = F_21 ( V_36 ) ;
if ( ! V_17 ) {
F_9 ( L_9 ) ;
return - V_46 ;
}
F_19 ( V_17 , V_35 + V_47 , V_36 ) ;
return V_36 + V_47 ;
}
static void F_22 ( void )
{
F_23 ( V_17 ) ;
V_17 = NULL ;
}
static enum V_48
F_24 ( int V_1 , const T_3 * V_49 , T_4 V_36 )
{
struct V_25 * V_26 = V_25 + V_1 ;
struct V_12 * V_13 = NULL ;
unsigned int V_39 , V_50 ;
int V_51 ;
const T_3 * V_52 = V_49 ;
void * V_53 = NULL ;
unsigned int V_54 = V_26 -> V_34 . V_11 ;
enum V_48 V_55 = V_56 ;
V_51 = F_20 ( V_52 ) ;
if ( V_51 < 0 ) {
F_9 ( L_10 ) ;
return V_57 ;
}
V_52 += V_51 ;
V_50 = V_36 - V_51 ;
while ( V_50 ) {
V_13 = F_17 ( V_1 , V_52 , V_50 , & V_39 ) ;
if ( ! V_13 )
break;
if ( F_6 ( V_1 , V_13 , V_54 ) ) {
F_23 ( V_53 ) ;
V_54 = V_13 -> V_23 ;
V_53 = V_13 ;
} else
F_23 ( V_13 ) ;
V_52 += V_39 ;
V_50 -= V_39 ;
}
if ( ! V_53 ) {
V_55 = V_58 ;
goto V_59;
}
if ( ! V_50 ) {
F_23 ( V_26 -> V_29 ) ;
V_26 -> V_29 = V_53 ;
F_25 ( L_11 ,
V_1 , V_26 -> V_34 . V_11 , V_54 ) ;
} else {
F_23 ( V_53 ) ;
V_55 = V_57 ;
}
V_59:
F_22 () ;
return V_55 ;
}
static enum V_48 F_26 ( int V_1 , struct V_60 * V_60 )
{
const char * V_61 = L_12 ;
const struct V_62 * V_63 ;
enum V_48 V_64 = V_58 ;
if ( F_27 ( & V_63 , V_61 , V_60 ) ) {
F_9 ( L_13 , V_61 ) ;
goto V_41;
}
V_64 = V_57 ;
if ( * ( T_1 * ) V_63 -> V_49 != V_65 ) {
F_9 ( L_14 , * ( T_1 * ) V_63 -> V_49 ) ;
goto V_66;
}
V_64 = F_24 ( V_1 , V_63 -> V_49 , V_63 -> V_36 ) ;
V_66:
F_28 ( V_63 ) ;
V_41:
return V_64 ;
}
static enum V_48
F_29 ( int V_1 , const void T_5 * V_35 , T_4 V_36 )
{
F_5 ( L_15 ) ;
return V_57 ;
}
static void F_30 ( int V_1 )
{
struct V_25 * V_26 = V_25 + V_1 ;
F_23 ( V_26 -> V_29 ) ;
V_26 -> V_29 = NULL ;
}
struct V_67 * T_6 F_31 ( void )
{
return & V_68 ;
}
