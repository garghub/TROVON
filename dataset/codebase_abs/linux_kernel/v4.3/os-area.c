void F_1 ( const struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
V_4 = V_2 ;
F_3 ( & V_3 ) ;
}
static T_1 F_4 ( void * V_5 , T_2 V_6 , T_3 V_7 )
{
T_1 V_8 = - V_9 ;
F_2 ( & V_3 ) ;
if ( V_4 )
V_8 = V_4 -> V_10 ( V_5 , V_6 , V_7 ) ;
F_3 ( & V_3 ) ;
return V_8 ;
}
static T_1 F_5 ( const void * V_5 , T_2 V_6 , T_3 V_7 )
{
T_1 V_8 = - V_9 ;
F_2 ( & V_3 ) ;
if ( V_4 )
V_8 = V_4 -> V_11 ( V_5 , V_6 , V_7 ) ;
F_3 ( & V_3 ) ;
return V_8 ;
}
static void F_6 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
int V_16 ;
struct V_14 * V_17 = F_7 ( V_13 , V_15 -> V_18 , NULL ) ;
if ( V_17 ) {
F_8 ( L_1 , V_19 , __LINE__ , V_15 -> V_18 ) ;
F_9 ( V_13 , V_17 ) ;
}
V_16 = F_10 ( V_13 , V_15 ) ;
if ( V_16 )
F_8 ( L_2 , V_19 ,
__LINE__ ) ;
}
static void T_4 F_11 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
const struct V_14 * V_17 = F_7 ( V_13 , V_15 -> V_18 , NULL ) ;
if ( V_17 ) {
F_12 ( V_15 -> V_20 != V_17 -> V_20 ) ;
memcpy ( V_15 -> V_21 , V_17 -> V_21 , V_15 -> V_20 ) ;
} else
F_8 ( L_3 , V_19 , __LINE__ ,
V_15 -> V_18 ) ;
}
static void F_13 ( char * V_22 , const T_5 * V_23 , int V_24 )
{
#if F_14 ( V_25 )
int V_26 ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ )
V_22 [ V_26 ] = isprint ( V_23 [ V_26 ] ) ? V_23 [ V_26 ] : '.' ;
V_22 [ V_26 ] = 0 ;
#endif
}
static void F_15 ( const struct V_27 * V_28 , const char * V_29 ,
int line )
{
char V_30 [ sizeof( V_28 -> V_31 ) + 1 ] ;
F_13 ( V_30 , V_28 -> V_31 , sizeof( V_28 -> V_31 ) ) ;
F_8 ( L_4 , V_29 , line ,
V_30 ) ;
F_8 ( L_5 , V_29 , line ,
V_28 -> V_32 ) ;
F_8 ( L_6 , V_29 , line ,
V_28 -> V_33 ) ;
F_8 ( L_7 , V_29 , line ,
V_28 -> V_34 ) ;
F_8 ( L_8 , V_29 , line ,
V_28 -> V_35 ) ;
F_8 ( L_9 , V_29 , line ,
V_28 -> V_36 ) ;
}
static void F_16 ( const struct V_37 * V_38 , const char * V_29 ,
int line )
{
F_8 ( L_10 , V_29 , line , V_38 -> V_39 ) ;
F_8 ( L_11 , V_29 , line , V_38 -> V_40 ) ;
F_8 ( L_12 , V_29 , line , V_38 -> V_41 ) ;
F_8 ( L_13 , V_29 , line , V_38 -> V_42 ) ;
F_8 ( L_14 , V_29 , line , V_38 -> V_43 ) ;
F_8 ( L_15 , V_29 , line ,
V_38 -> V_44 [ 0 ] , V_38 -> V_44 [ 1 ] ,
V_38 -> V_44 [ 2 ] , V_38 -> V_44 [ 3 ] ) ;
F_8 ( L_16 , V_29 , line ,
V_38 -> V_45 [ 0 ] , V_38 -> V_45 [ 1 ] ,
V_38 -> V_45 [ 2 ] , V_38 -> V_45 [ 3 ] ) ;
F_8 ( L_17 , V_29 , line ,
V_38 -> V_46 [ 0 ] , V_38 -> V_46 [ 1 ] ,
V_38 -> V_46 [ 2 ] , V_38 -> V_46 [ 3 ] ) ;
F_8 ( L_18 , V_29 , line ,
V_38 -> V_47 [ 0 ] , V_38 -> V_47 [ 1 ] ,
V_38 -> V_47 [ 2 ] , V_38 -> V_47 [ 3 ] ) ;
F_8 ( L_19 , V_29 , line ,
V_38 -> V_48 [ 0 ] , V_38 -> V_48 [ 1 ] ,
V_38 -> V_48 [ 2 ] , V_38 -> V_48 [ 3 ] ) ;
}
static int F_17 ( const struct V_27 * V_49 )
{
if ( memcmp ( V_49 -> V_31 , V_50 ,
sizeof( V_49 -> V_31 ) ) ) {
F_8 ( L_20 , V_19 , __LINE__ ) ;
return - 1 ;
}
if ( V_49 -> V_32 < 1 ) {
F_8 ( L_21 , V_19 , __LINE__ ) ;
return - 1 ;
}
if ( V_49 -> V_33 > V_49 -> V_34 ) {
F_8 ( L_22 , V_19 , __LINE__ ) ;
return - 1 ;
}
return 0 ;
}
static int F_18 ( const struct V_51 * V_52 )
{
if ( memcmp ( V_52 -> V_31 , V_53 ,
sizeof( V_52 -> V_31 ) ) ) {
F_8 ( L_20 , V_19 , __LINE__ ) ;
return - V_54 ;
}
if ( V_52 -> V_55 != 1 ) {
F_8 ( L_23 , V_19 , __LINE__ ) ;
return - V_54 ;
}
return 0 ;
}
static unsigned int F_19 ( unsigned int V_56 , unsigned int V_57 )
{
return ( V_56 + ( V_57 - 1 ) ) & ( ~ ( V_57 - 1 ) ) ;
}
static int F_20 ( const struct V_51 * V_52 ,
const struct V_58 * V_59 , struct V_60 * V_26 )
{
V_61:
if ( ! V_26 -> V_52 ) {
V_26 -> V_52 = V_52 ;
V_26 -> V_59 = V_59 ? * V_59 : V_62 ;
V_26 -> V_63 = ( void * ) V_52 + V_52 -> V_64 ;
V_26 -> V_65 = V_26 -> V_63 + V_52 -> V_66 ;
V_26 -> V_67 = ( void * ) V_52 + V_52 -> V_64
+ F_19 ( V_52 -> V_66 , 8 ) ;
} else {
V_26 -> V_63 ++ ;
V_26 -> V_67 ++ ;
}
if ( V_26 -> V_63 >= V_26 -> V_65 ) {
F_8 ( L_24 , V_19 , __LINE__ ) ;
return 0 ;
}
if ( V_26 -> V_59 . V_68 != V_69
&& V_26 -> V_59 . V_68 != ( int ) V_26 -> V_63 -> V_68 )
goto V_61;
if ( V_26 -> V_59 . V_70 != V_71
&& V_26 -> V_59 . V_70 != ( int ) V_26 -> V_63 -> V_70 )
goto V_61;
return 1 ;
}
static int F_21 ( struct V_51 * V_52 , const struct V_58 * V_72 )
{
struct V_60 V_26 ;
for ( V_26 . V_52 = NULL ; F_20 ( V_52 , V_72 , & V_26 ) ; ) {
F_8 ( L_25 , V_19 , __LINE__ ,
V_26 . V_63 -> V_68 , V_26 . V_63 -> V_70 ,
( unsigned long long ) * V_26 . V_67 ) ;
V_26 . V_63 -> V_68 = 0 ;
V_26 . V_63 -> V_70 = 0 ;
* V_26 . V_67 = 0 ;
}
return 0 ;
}
static int F_22 ( struct V_51 * V_52 , const struct V_58 * V_72 ,
T_6 V_21 )
{
struct V_60 V_26 ;
F_8 ( L_26 , V_19 , __LINE__ ,
V_72 -> V_68 , V_72 -> V_70 , ( unsigned long long ) V_21 ) ;
if ( ! V_72 -> V_68 || V_72 -> V_68 == V_69
|| V_72 -> V_70 == V_71 ) {
F_8 ( L_27 , V_19 ,
__LINE__ , V_72 -> V_68 , V_72 -> V_70 ) ;
return - 1 ;
}
F_21 ( V_52 , V_72 ) ;
V_26 . V_52 = NULL ;
if ( F_20 ( V_52 , & V_73 , & V_26 ) ) {
F_8 ( L_25 , V_19 , __LINE__ ,
V_26 . V_63 -> V_68 , V_26 . V_63 -> V_70 ,
( unsigned long long ) * V_26 . V_67 ) ;
V_26 . V_63 -> V_68 = V_72 -> V_68 ;
V_26 . V_63 -> V_70 = V_72 -> V_70 ;
* V_26 . V_67 = V_21 ;
F_8 ( L_28 , V_19 , __LINE__ ,
V_26 . V_63 -> V_68 , V_26 . V_63 -> V_70 ,
( unsigned long long ) * V_26 . V_67 ) ;
return 0 ;
}
F_8 ( L_29 ,
V_19 , __LINE__ ) ;
return - 1 ;
}
static int F_23 ( const struct V_51 * V_52 ,
const struct V_58 * V_72 , T_6 * V_21 )
{
struct V_60 V_26 ;
V_26 . V_52 = NULL ;
if ( F_20 ( V_52 , V_72 , & V_26 ) ) {
* V_21 = * V_26 . V_67 ;
F_8 ( L_30 , V_19 , __LINE__ ,
( long long int ) * V_26 . V_67 ) ;
return 0 ;
}
F_8 ( L_31 , V_19 , __LINE__ ) ;
return - 1 ;
}
static int F_24 ( const struct V_51 * V_52 , T_7 * V_41 )
{
return F_23 ( V_52 , & V_74 , ( T_6 * ) V_41 ) ;
}
static void F_25 ( const struct V_51 * V_52 , const char * V_29 ,
int line )
{
char V_30 [ sizeof( V_52 -> V_31 ) + 1 ] ;
F_13 ( V_30 , V_52 -> V_31 , sizeof( V_52 -> V_31 ) ) ;
F_8 ( L_32 , V_29 , line ,
V_30 ) ;
F_8 ( L_33 , V_29 , line ,
V_52 -> V_55 ) ;
F_8 ( L_34 , V_29 , line ,
V_52 -> V_64 ) ;
F_8 ( L_35 , V_29 , line ,
V_52 -> V_66 ) ;
F_8 ( L_36 , V_29 , line ,
V_52 -> V_75 ) ;
F_8 ( L_37 , V_29 , line ,
V_52 -> V_76 ) ;
F_8 ( L_38 , V_29 , line ,
V_52 -> V_77 ) ;
F_8 ( L_39 , V_29 , line ,
V_52 -> V_78 ) ;
}
static void F_26 ( struct V_51 * V_52 )
{
enum {
V_79 = F_27 ( struct V_51 , V_80 ) ,
V_81 = 64 ,
V_82 = 57 ,
V_83 = 64 ,
V_84 = 57 ,
V_85 = 64 ,
V_86 = 57 ,
};
memset ( V_52 , 0 , sizeof( struct V_51 ) ) ;
memcpy ( V_52 -> V_31 , V_53 , sizeof( V_52 -> V_31 ) ) ;
V_52 -> V_55 = 1 ;
V_52 -> V_64 = V_79 ;
V_52 -> V_66 = V_82 ;
V_52 -> V_75 = V_79
+ V_81 * sizeof( struct V_87 )
+ V_82 * sizeof( V_88 ) ;
V_52 -> V_76 = V_84 ;
V_52 -> V_77 = V_79
+ V_81 * sizeof( struct V_87 )
+ V_82 * sizeof( V_88 )
+ V_83 * sizeof( struct V_87 )
+ V_84 * sizeof( V_89 ) ;
V_52 -> V_78 = V_86 ;
F_28 ( sizeof( struct V_87 ) != 1 ) ;
F_28 ( sizeof( struct V_51 ) != 2 * V_90 ) ;
F_28 ( V_81 & 0x7 ) ;
F_28 ( V_82 > V_81 ) ;
F_28 ( V_83 & 0x7 ) ;
F_28 ( V_84 > V_83 ) ;
F_28 ( V_85 & 0x7 ) ;
F_28 ( V_86 > V_85 ) ;
F_28 ( V_79
+ V_81 * sizeof( struct V_87 )
+ V_82 * sizeof( V_88 )
+ V_83 * sizeof( struct V_87 )
+ V_84 * sizeof( V_89 )
+ V_85 * sizeof( struct V_87 )
+ V_86 * sizeof( V_91 )
> sizeof( struct V_51 ) ) ;
}
static int F_29 ( void )
{
const unsigned int V_92 = 8 * V_90 ;
struct V_27 * V_49 ;
T_1 V_6 ;
int error ;
T_3 V_7 ;
struct V_51 * V_52 ;
V_49 = F_30 ( V_92 , V_93 ) ;
if ( ! V_49 ) {
F_8 ( L_40 , V_19 ) ;
return - V_94 ;
}
V_6 = F_4 ( V_49 , V_92 , 0 ) ;
if ( V_6 < 0 ) {
F_8 ( L_41 , V_19 ,
V_6 ) ;
error = V_6 ;
goto V_95;
}
V_7 = V_49 -> V_33 * V_90 ;
if ( V_6 < V_90 || F_17 ( V_49 ) ||
V_6 < V_7 ) {
F_8 ( L_42 , V_19 ) ;
F_31 ( V_49 ) ;
error = - V_54 ;
goto V_95;
}
V_52 = ( void * ) V_49 + V_7 ;
error = F_18 ( V_52 ) ;
if ( error ) {
F_32 ( L_43 ,
V_19 ) ;
F_33 ( V_52 ) ;
F_26 ( V_52 ) ;
}
F_22 ( V_52 , & V_74 , V_96 . V_41 ) ;
V_6 = F_5 ( V_52 , sizeof( struct V_51 ) , V_7 ) ;
if ( V_6 < sizeof( struct V_51 ) ) {
F_8 ( L_44 , V_19 ,
V_6 ) ;
error = V_6 < 0 ? V_6 : - V_97 ;
}
V_95:
F_34 ( V_49 ) ;
return error ;
}
static void F_35 ( struct V_98 * V_99 )
{
struct V_12 * V_13 ;
int error ;
F_8 ( L_45 , V_19 , __LINE__ ) ;
V_13 = F_36 ( L_46 ) ;
if ( V_13 ) {
F_6 ( V_13 , & V_100 ) ;
F_37 ( V_13 ) ;
} else
F_8 ( L_47 ,
V_19 , __LINE__ ) ;
error = F_29 () ;
if ( error )
F_38 ( L_48 , V_19 ) ;
F_8 ( L_49 , V_19 , __LINE__ ) ;
}
static void F_39 ( void )
{
static F_40 ( V_101 , F_35 ) ;
F_41 () ;
F_42 ( & V_101 ) ;
}
void T_4 F_43 ( void )
{
int V_16 ;
V_88 V_102 ;
unsigned int V_57 ;
struct V_27 * V_49 ;
struct V_37 * V_103 ;
struct V_51 * V_52 ;
F_8 ( L_45 , V_19 , __LINE__ ) ;
V_16 = F_44 ( & V_102 , & V_57 ) ;
if ( V_16 ) {
F_8 ( L_50 ,
V_19 , __LINE__ ) ;
return;
}
V_49 = (struct V_27 * ) F_45 ( V_102 ) ;
V_103 = (struct V_37 * ) F_45 ( V_102
+ V_90 ) ;
V_16 = F_17 ( V_49 ) ;
if ( V_16 ) {
F_8 ( L_51 , V_19 , __LINE__ ) ;
F_31 ( V_49 ) ;
return;
}
V_52 = (struct V_51 * ) F_45 ( V_102
+ V_49 -> V_33 * V_90 ) ;
F_31 ( V_49 ) ;
F_46 ( V_103 ) ;
F_33 ( V_52 ) ;
V_16 = F_18 ( V_52 ) || F_24 ( V_52 , & V_96 . V_41 ) ;
if ( V_16 )
V_96 . V_41 = V_103 -> V_41 ? V_103 -> V_41
: V_104 ;
V_96 . V_42 = V_103 -> V_42 ;
V_96 . V_105 = 1 ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
F_8 ( L_49 , V_19 , __LINE__ ) ;
}
void T_4 F_47 ( void )
{
struct V_12 * V_13 ;
F_8 ( L_45 , V_19 , __LINE__ ) ;
V_13 = F_36 ( L_46 ) ;
if ( ! V_96 . V_105 && V_13 ) {
F_11 ( V_13 , & V_100 ) ;
F_11 ( V_13 , & V_106 ) ;
}
if( ! V_96 . V_41 )
V_96 . V_41 = V_104 ;
if ( V_13 ) {
F_6 ( V_13 , & V_100 ) ;
F_6 ( V_13 , & V_106 ) ;
F_37 ( V_13 ) ;
} else
F_8 ( L_47 ,
V_19 , __LINE__ ) ;
F_8 ( L_49 , V_19 , __LINE__ ) ;
}
V_88 F_48 ( void )
{
return V_96 . V_41 ;
}
void F_49 ( V_88 V_41 )
{
if ( V_96 . V_41 != V_41 ) {
V_96 . V_41 = V_41 ;
F_39 () ;
}
}
enum V_107 F_50 ( void )
{
return V_96 . V_42 ;
}
