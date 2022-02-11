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
inline T_1 F_3 ( void * V_10 )
{
return V_1 ( V_10 ) -> V_4 ;
}
static unsigned long F_4 ( void )
{
T_1 V_11 ;
F_5 ( & V_11 ) ;
F_6 ( V_11 , & V_11 ) ;
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
static const unsigned long V_29 = V_30 | 3 ;
V_1 ( V_2 ) -> V_8 = F_13 ( V_1 ( V_2 ) -> V_19 ,
sizeof( struct V_31 ) ,
V_29 ) ;
if ( ! V_1 ( V_2 ) -> V_8 ) {
F_2 ( L_7 , V_20 , __LINE__ ) ;
goto V_32;
}
V_2 -> V_24 = ( V_21 void * ) F_14 ( V_2 -> V_15 ,
V_33 , V_30 ) ;
if ( ! V_2 -> V_24 ) {
F_2 ( L_8 ,
V_20 , __LINE__ ) ;
goto V_32;
}
V_2 -> V_6 = F_15 ( V_2 -> V_14 ,
sizeof( struct V_34 ) ) ;
if ( ! V_2 -> V_6 ) {
F_2 ( L_9 , V_20 , __LINE__ ) ;
goto V_32;
}
V_2 -> V_5 = F_15 ( V_1 ( V_2 ) -> V_18 ,
sizeof( struct V_35 ) ) ;
if ( ! V_2 -> V_5 ) {
F_2 ( L_10 , V_20 , __LINE__ ) ;
goto V_32;
}
F_16 ( V_1 ( V_2 ) -> V_4 , V_1 ( V_2 ) -> V_18 ,
V_2 -> V_14 , V_2 -> V_15 ,
V_1 ( V_2 ) -> V_19 ) ;
F_16 ( V_1 ( V_2 ) -> V_4 , ( unsigned long ) V_2 -> V_5 ,
( unsigned long ) V_2 -> V_6 , ( unsigned long ) V_2 -> V_24 ,
( unsigned long ) V_1 ( V_2 ) -> V_8 ) ;
return 0 ;
V_32:
F_10 ( V_2 ) ;
return - V_36 ;
}
static int T_2 F_17 ( struct V_2 * V_2 )
{
int V_12 ;
V_12 = F_18 ( V_37 , V_1 ( V_2 ) -> V_4 ,
0 , & V_2 -> V_38 [ 0 ] ) ;
if ( V_12 )
goto V_39;
V_12 = F_18 ( V_37 , V_1 ( V_2 ) -> V_4 ,
1 , & V_2 -> V_38 [ 1 ] ) ;
if ( V_12 )
goto V_40;
V_12 = F_18 ( V_37 , V_1 ( V_2 ) -> V_4 ,
2 , & V_2 -> V_38 [ 2 ] ) ;
if ( V_12 )
goto V_41;
return V_12 ;
V_41:
F_19 ( V_2 -> V_38 [ 1 ] ) ;
V_40:
F_19 ( V_2 -> V_38 [ 0 ] ) ;
V_39:
V_2 -> V_38 [ 0 ] = V_2 -> V_38 [ 1 ] = V_2 -> V_38 [ 2 ] = V_42 ;
return V_12 ;
}
static int T_2 F_20 ( struct V_2 * V_2 )
{
int V_12 ;
V_12 = F_21 ( V_1 ( V_2 ) -> V_4 ,
V_1 ( V_2 ) -> V_43 ) ;
if ( V_12 ) {
F_2 ( L_11 ,
V_20 , __LINE__ , F_9 ( V_12 ) ) ;
goto V_44;
}
V_12 = F_12 ( V_2 ) ;
if ( V_12 )
goto V_45;
V_12 = F_17 ( V_2 ) ;
if ( V_12 )
goto V_46;
return 0 ;
V_46:
F_10 ( V_2 ) ;
V_45:
F_22 ( V_1 ( V_2 ) -> V_4 , 0 ) ;
V_44:
return V_12 ;
}
static int F_23 ( struct V_2 * V_2 )
{
int V_12 ;
F_2 ( L_12 , V_20 , __LINE__ , V_2 -> V_47 ) ;
V_12 = F_22 ( V_1 ( V_2 ) -> V_4 , 0 ) ;
F_24 ( V_12 ) ;
F_19 ( V_2 -> V_38 [ 2 ] ) ;
F_19 ( V_2 -> V_38 [ 1 ] ) ;
F_19 ( V_2 -> V_38 [ 0 ] ) ;
V_2 -> V_38 [ 0 ] = V_2 -> V_38 [ 1 ] = V_2 -> V_38 [ 2 ] = V_42 ;
F_10 ( V_2 ) ;
V_12 = F_25 ( V_1 ( V_2 ) -> V_4 ) ;
F_24 ( V_12 ) ;
F_26 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return 0 ;
}
static int T_2 F_27 ( struct V_2 * V_2 , void * V_48 )
{
int V_12 ;
F_2 ( L_12 , V_20 , __LINE__ , V_2 -> V_47 ) ;
V_2 -> V_3 = F_28 ( sizeof( struct V_1 ) ,
V_49 ) ;
if ( ! V_2 -> V_3 ) {
V_12 = - V_36 ;
goto V_50;
}
V_1 ( V_2 ) -> V_43 = ( unsigned long ) V_48 ;
V_1 ( V_2 ) -> V_51 . V_52 = 0x33 ;
V_12 = F_7 ( V_2 ) ;
if ( V_12 )
goto V_53;
V_12 = F_20 ( V_2 ) ;
if ( V_12 )
goto V_44;
while ( F_29 ( & V_1 ( V_2 ) -> V_8 -> V_54 )
!= V_55 )
( void ) 0 ;
return V_12 ;
V_44:
V_53:
F_23 ( V_2 ) ;
V_50:
return V_12 ;
}
static int T_2 F_30 ( int (* F_31)( void * V_48 ) )
{
int V_12 ;
unsigned int V_56 ;
unsigned int V_57 ;
V_12 = F_32 ( & V_56 ) ;
F_2 ( L_13 , V_20 , __LINE__ ,
V_56 ) ;
for ( V_57 = 0 ; V_57 < V_56 ; V_57 ++ ) {
enum V_58 V_59 ;
unsigned int V_43 ;
V_12 = F_33 ( V_57 ,
& V_59 , & V_43 ) ;
if ( V_12 )
break;
if ( V_59 == V_60 ) {
V_12 = F_31 ( ( void * ) ( unsigned long ) V_43 ) ;
if ( V_12 )
break;
}
}
if ( V_12 ) {
F_34 ( V_61 L_14 ,
V_20 , __LINE__ ) ;
return V_12 ;
}
return V_56 ;
}
static int F_35 ( void )
{
return 0 ;
}
static void F_36 ( struct V_62 * V_63 )
{
}
static void F_37 ( struct V_62 * V_63 )
{
V_63 -> V_64 -> V_65 ( V_63 ) ;
}
static void F_38 ( struct V_2 * V_2 , int V_66 , T_1 V_67 )
{
T_1 V_68 ;
V_68 = F_39 ( V_2 , V_66 ) ;
F_40 ( V_2 , V_66 , V_68 & V_67 ) ;
}
static void F_41 ( struct V_2 * V_2 , int V_66 , T_1 V_67 )
{
T_1 V_68 ;
V_68 = F_39 ( V_2 , V_66 ) ;
F_40 ( V_2 , V_66 , V_68 | V_67 ) ;
}
static void F_42 ( struct V_2 * V_2 , int V_66 , T_1 V_67 )
{
V_1 ( V_2 ) -> V_51 . V_69 [ V_66 ] = V_67 ;
F_43 ( V_1 ( V_2 ) -> V_4 , V_66 ,
V_1 ( V_2 ) -> V_51 . V_69 [ V_66 ] ) ;
}
static T_1 F_44 ( struct V_2 * V_2 , int V_66 )
{
return V_1 ( V_2 ) -> V_51 . V_69 [ V_66 ] ;
}
static void F_45 ( struct V_2 * V_2 , int V_66 , T_1 V_70 )
{
F_46 ( V_1 ( V_2 ) -> V_4 , V_66 ,
V_70 , 0 ) ;
}
static T_1 F_47 ( struct V_2 * V_2 , int V_66 )
{
T_1 V_70 ;
F_48 ( V_1 ( V_2 ) -> V_4 , V_66 , & V_70 ) ;
return V_70 ;
}
static void F_49 ( struct V_2 * V_2 , int V_71 )
{
}
static T_1 F_50 ( struct V_2 * V_2 )
{
return F_29 ( & V_1 ( V_2 ) -> V_8 -> V_72 ) ;
}
static void F_51 ( struct V_2 * V_2 , T_1 V_73 )
{
}
static T_1 F_52 ( struct V_2 * V_2 )
{
return F_29 ( & V_1 ( V_2 ) -> V_8 -> V_74 ) ;
}
static void F_53 ( struct V_2 * V_2 )
{
}
static void F_54 ( struct V_2 * V_2 , T_1 V_52 )
{
static const T_1 V_75 = ~ ( V_76
| V_77 ) ;
F_24 ( ( V_52 & V_75 ) != ( V_1 ( V_2 ) -> V_51 . V_52 & V_75 ) ) ;
V_1 ( V_2 ) -> V_51 . V_52 = V_52 ;
F_55 (
V_1 ( V_2 ) -> V_4 ,
F_56 ( struct V_78 , V_79 ) ,
V_1 ( V_2 ) -> V_51 . V_52 ) ;
}
static T_1 F_57 ( struct V_2 * V_2 )
{
return V_1 ( V_2 ) -> V_51 . V_52 ;
}
static void F_58 ( struct V_2 * V_2 , T_1 V_80 )
{
V_1 ( V_2 ) -> V_51 . V_80 = V_80 ;
F_55 (
V_1 ( V_2 ) -> V_4 ,
F_56 ( struct V_78 , V_81 ) ,
V_1 ( V_2 ) -> V_51 . V_80 ) ;
}
static T_1 F_59 ( struct V_2 * V_2 )
{
return V_1 ( V_2 ) -> V_51 . V_80 ;
}
static void F_60 ( struct V_2 * V_2 )
{
}
static void F_61 ( struct V_2 * V_2 , T_1 V_11 )
{
}
static T_1 F_62 ( struct V_2 * V_2 )
{
return 0 ;
}
static void F_63 ( struct V_2 * V_2 , T_1 V_82 )
{
}
static T_1 F_64 ( struct V_2 * V_2 )
{
return 0 ;
}
void F_65 ( void )
{
V_83 = & V_84 ;
V_85 = & V_86 ;
}
