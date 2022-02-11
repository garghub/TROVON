static struct V_1 * V_1 ( struct V_2 * V_2 )
{
return V_2 -> V_3 ;
}
static void F_1 ( unsigned int V_4 , unsigned long V_5 ,
unsigned long V_6 , unsigned long V_7 , unsigned long V_8 ,
const char * V_9 , int line )
{
F_2 ( L_1 , V_9 , line , V_4 , V_4 ) ;
F_2 ( L_2 , V_9 , line , V_5 ) ;
F_2 ( L_3 , V_9 , line , V_6 ) ;
F_2 ( L_4 , V_9 , line , V_7 ) ;
F_2 ( L_5 , V_9 , line , V_8 ) ;
}
T_1 F_3 ( void * V_10 )
{
return V_1 ( V_10 ) -> V_4 ;
}
static unsigned long F_4 ( void )
{
T_1 V_11 ;
F_5 ( & V_11 ) ;
F_6 ( & V_11 ) ;
return V_11 ;
}
static int T_2 F_7 ( struct V_2 * V_2 )
{
int V_12 ;
T_1 V_13 ;
T_1 V_14 ;
T_1 V_15 ;
V_12 = F_8 ( V_16 , V_16 , V_16 ,
V_16 , V_16 , F_4 () , V_17 ,
& V_1 ( V_2 ) -> V_18 , & V_14 ,
& V_15 , & V_13 ,
& V_1 ( V_2 ) -> V_19 ,
& V_1 ( V_2 ) -> V_4 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_15 = V_15 ;
if ( V_12 ) {
F_2 ( L_6 ,
V_20 , __LINE__ , F_9 ( V_12 ) ) ;
return V_12 ;
}
return V_12 ;
}
static void F_10 ( struct V_2 * V_2 )
{
F_11 ( V_2 -> V_5 ) ;
F_11 ( V_2 -> V_6 ) ;
F_11 ( ( V_21 V_22 V_23 * ) V_2 -> V_24 ) ;
F_11 ( V_1 ( V_2 ) -> V_8 ) ;
}
static int T_2 F_12 ( struct V_2 * V_2 )
{
struct V_25 { char * V_26 ; unsigned long V_27 ; unsigned long V_28 ;};
unsigned long V_29 = F_13 ( F_14 ( V_30 ) ) ;
V_1 ( V_2 ) -> V_8 = F_15 ( V_1 ( V_2 ) -> V_19 ,
sizeof( struct V_31 ) ,
V_29 ) ;
if ( ! V_1 ( V_2 ) -> V_8 ) {
F_2 ( L_7 , V_20 , __LINE__ ) ;
goto V_32;
}
V_2 -> V_24 = ( V_21 void * ) F_16 ( V_2 -> V_15 ,
V_33 , F_13 ( F_14 ( F_17 ( 0 ) ) ) ) ;
if ( ! V_2 -> V_24 ) {
F_2 ( L_8 ,
V_20 , __LINE__ ) ;
goto V_32;
}
V_2 -> V_6 = F_18 ( V_2 -> V_14 ,
sizeof( struct V_34 ) ) ;
if ( ! V_2 -> V_6 ) {
F_2 ( L_9 , V_20 , __LINE__ ) ;
goto V_32;
}
V_2 -> V_5 = F_18 ( V_1 ( V_2 ) -> V_18 ,
sizeof( struct V_35 ) ) ;
if ( ! V_2 -> V_5 ) {
F_2 ( L_10 , V_20 , __LINE__ ) ;
goto V_32;
}
F_19 ( V_1 ( V_2 ) -> V_4 , V_1 ( V_2 ) -> V_18 ,
V_2 -> V_14 , V_2 -> V_15 ,
V_1 ( V_2 ) -> V_19 ) ;
F_19 ( V_1 ( V_2 ) -> V_4 , ( unsigned long ) V_2 -> V_5 ,
( unsigned long ) V_2 -> V_6 , ( unsigned long ) V_2 -> V_24 ,
( unsigned long ) V_1 ( V_2 ) -> V_8 ) ;
return 0 ;
V_32:
F_10 ( V_2 ) ;
return - V_36 ;
}
static int T_2 F_20 ( struct V_2 * V_2 )
{
int V_12 ;
V_12 = F_21 ( V_37 , V_1 ( V_2 ) -> V_4 ,
0 , & V_2 -> V_38 [ 0 ] ) ;
if ( V_12 )
goto V_39;
V_12 = F_21 ( V_37 , V_1 ( V_2 ) -> V_4 ,
1 , & V_2 -> V_38 [ 1 ] ) ;
if ( V_12 )
goto V_40;
V_12 = F_21 ( V_37 , V_1 ( V_2 ) -> V_4 ,
2 , & V_2 -> V_38 [ 2 ] ) ;
if ( V_12 )
goto V_41;
return V_12 ;
V_41:
F_22 ( V_2 -> V_38 [ 1 ] ) ;
V_40:
F_22 ( V_2 -> V_38 [ 0 ] ) ;
V_39:
V_2 -> V_38 [ 0 ] = V_2 -> V_38 [ 1 ] = V_2 -> V_38 [ 2 ] = 0 ;
return V_12 ;
}
static int T_2 F_23 ( struct V_2 * V_2 )
{
int V_12 ;
V_12 = F_24 ( V_1 ( V_2 ) -> V_4 ,
V_1 ( V_2 ) -> V_42 ) ;
if ( V_12 ) {
F_2 ( L_11 ,
V_20 , __LINE__ , F_9 ( V_12 ) ) ;
goto V_43;
}
V_12 = F_12 ( V_2 ) ;
if ( V_12 )
goto V_44;
V_12 = F_20 ( V_2 ) ;
if ( V_12 )
goto V_45;
return 0 ;
V_45:
F_10 ( V_2 ) ;
V_44:
F_25 ( V_1 ( V_2 ) -> V_4 , 0 ) ;
V_43:
return V_12 ;
}
static int F_26 ( struct V_2 * V_2 )
{
int V_12 ;
F_2 ( L_12 , V_20 , __LINE__ , V_2 -> V_46 ) ;
V_12 = F_25 ( V_1 ( V_2 ) -> V_4 , 0 ) ;
F_27 ( V_12 ) ;
F_22 ( V_2 -> V_38 [ 2 ] ) ;
F_22 ( V_2 -> V_38 [ 1 ] ) ;
F_22 ( V_2 -> V_38 [ 0 ] ) ;
V_2 -> V_38 [ 0 ] = V_2 -> V_38 [ 1 ] = V_2 -> V_38 [ 2 ] = 0 ;
F_10 ( V_2 ) ;
V_12 = F_28 ( V_1 ( V_2 ) -> V_4 ) ;
F_27 ( V_12 ) ;
F_29 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return 0 ;
}
static int T_2 F_30 ( struct V_2 * V_2 , void * V_47 )
{
int V_12 ;
F_2 ( L_12 , V_20 , __LINE__ , V_2 -> V_46 ) ;
V_2 -> V_3 = F_31 ( sizeof( struct V_1 ) ,
V_48 ) ;
if ( ! V_2 -> V_3 ) {
V_12 = - V_36 ;
goto V_49;
}
V_1 ( V_2 ) -> V_42 = ( unsigned long ) V_47 ;
V_1 ( V_2 ) -> V_50 . V_51 = 0x33 ;
V_12 = F_7 ( V_2 ) ;
if ( V_12 )
goto V_52;
V_12 = F_23 ( V_2 ) ;
if ( V_12 )
goto V_43;
while ( F_32 ( & V_1 ( V_2 ) -> V_8 -> V_53 )
!= V_54 )
( void ) 0 ;
return V_12 ;
V_43:
V_52:
F_26 ( V_2 ) ;
V_49:
return V_12 ;
}
static int T_2 F_33 ( int (* F_34)( void * V_47 ) )
{
int V_12 ;
unsigned int V_55 ;
unsigned int V_56 ;
V_12 = F_35 ( & V_55 ) ;
F_2 ( L_13 , V_20 , __LINE__ ,
V_55 ) ;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
enum V_57 V_58 ;
unsigned int V_42 ;
V_12 = F_36 ( V_56 ,
& V_58 , & V_42 ) ;
if ( V_12 )
break;
if ( V_58 == V_59 ) {
V_12 = F_34 ( ( void * ) ( unsigned long ) V_42 ) ;
if ( V_12 )
break;
}
}
if ( V_12 ) {
F_37 ( V_60 L_14 ,
V_20 , __LINE__ ) ;
return V_12 ;
}
return V_55 ;
}
static int F_38 ( void )
{
return 0 ;
}
static void F_39 ( struct V_61 * V_62 )
{
}
static void F_40 ( struct V_61 * V_62 )
{
V_62 -> V_63 -> V_64 ( V_62 ) ;
}
static void F_41 ( struct V_2 * V_2 , int V_65 , T_1 V_66 )
{
T_1 V_67 ;
V_67 = F_42 ( V_2 , V_65 ) ;
F_43 ( V_2 , V_65 , V_67 & V_66 ) ;
}
static void F_44 ( struct V_2 * V_2 , int V_65 , T_1 V_66 )
{
T_1 V_67 ;
V_67 = F_42 ( V_2 , V_65 ) ;
F_43 ( V_2 , V_65 , V_67 | V_66 ) ;
}
static void F_45 ( struct V_2 * V_2 , int V_65 , T_1 V_66 )
{
V_1 ( V_2 ) -> V_50 . V_68 [ V_65 ] = V_66 ;
F_46 ( V_1 ( V_2 ) -> V_4 , V_65 ,
V_1 ( V_2 ) -> V_50 . V_68 [ V_65 ] ) ;
}
static T_1 F_47 ( struct V_2 * V_2 , int V_65 )
{
return V_1 ( V_2 ) -> V_50 . V_68 [ V_65 ] ;
}
static void F_48 ( struct V_2 * V_2 , int V_65 , T_1 V_69 )
{
F_49 ( V_1 ( V_2 ) -> V_4 , V_65 ,
V_69 , 0 ) ;
}
static T_1 F_50 ( struct V_2 * V_2 , int V_65 )
{
T_1 V_69 ;
F_51 ( V_1 ( V_2 ) -> V_4 , V_65 , & V_69 ) ;
return V_69 ;
}
static void F_52 ( struct V_2 * V_2 , int V_70 )
{
}
static T_1 F_53 ( struct V_2 * V_2 )
{
return F_32 ( & V_1 ( V_2 ) -> V_8 -> V_71 ) ;
}
static void F_54 ( struct V_2 * V_2 , T_1 V_72 )
{
}
static T_1 F_55 ( struct V_2 * V_2 )
{
return F_32 ( & V_1 ( V_2 ) -> V_8 -> V_73 ) ;
}
static void F_56 ( struct V_2 * V_2 )
{
}
static void F_57 ( struct V_2 * V_2 , T_1 V_51 )
{
static const T_1 V_74 = ~ ( V_75
| V_76 ) ;
F_27 ( ( V_51 & V_74 ) != ( V_1 ( V_2 ) -> V_50 . V_51 & V_74 ) ) ;
V_1 ( V_2 ) -> V_50 . V_51 = V_51 ;
F_58 (
V_1 ( V_2 ) -> V_4 ,
F_59 ( struct V_77 , V_78 ) ,
V_1 ( V_2 ) -> V_50 . V_51 ) ;
}
static T_1 F_60 ( struct V_2 * V_2 )
{
return V_1 ( V_2 ) -> V_50 . V_51 ;
}
static void F_61 ( struct V_2 * V_2 , T_1 V_79 )
{
V_1 ( V_2 ) -> V_50 . V_79 = V_79 ;
F_58 (
V_1 ( V_2 ) -> V_4 ,
F_59 ( struct V_77 , V_80 ) ,
V_1 ( V_2 ) -> V_50 . V_79 ) ;
}
static T_1 F_62 ( struct V_2 * V_2 )
{
return V_1 ( V_2 ) -> V_50 . V_79 ;
}
static void F_63 ( struct V_2 * V_2 )
{
}
static void F_64 ( struct V_2 * V_2 , T_1 V_11 )
{
}
static T_1 F_65 ( struct V_2 * V_2 )
{
return 0 ;
}
static void F_66 ( struct V_2 * V_2 , T_1 V_81 )
{
}
static T_1 F_67 ( struct V_2 * V_2 )
{
return 0 ;
}
void F_68 ( void )
{
V_82 = & V_83 ;
V_84 = & V_85 ;
}
