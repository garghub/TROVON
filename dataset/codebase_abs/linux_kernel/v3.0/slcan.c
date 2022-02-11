static int F_1 ( char V_1 )
{
if ( ( V_1 >= '0' ) && ( V_1 <= '9' ) )
return V_1 - '0' ;
if ( ( V_1 >= 'A' ) && ( V_1 <= 'F' ) )
return V_1 - 'A' + 10 ;
if ( ( V_1 >= 'a' ) && ( V_1 <= 'f' ) )
return V_1 - 'a' + 10 ;
return 16 ;
}
static void F_2 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 V_7 ;
int V_8 , V_9 , V_10 ;
unsigned long V_11 ;
char V_12 = V_3 -> V_13 [ 0 ] ;
if ( ( V_12 != 't' ) && ( V_12 != 'T' ) && ( V_12 != 'r' ) && ( V_12 != 'R' ) )
return;
if ( V_12 & 0x20 )
V_9 = 4 ;
else
V_9 = 9 ;
if ( ! ( ( V_3 -> V_13 [ V_9 ] >= '0' ) && ( V_3 -> V_13 [ V_9 ] < '9' ) ) )
return;
V_7 . V_14 = V_3 -> V_13 [ V_9 ] - '0' ;
V_3 -> V_13 [ V_9 ] = 0 ;
if ( F_3 ( V_3 -> V_13 + 1 , 16 , & V_11 ) )
return;
V_7 . V_15 = V_11 ;
if ( ! ( V_12 & 0x20 ) )
V_7 . V_15 |= V_16 ;
if ( ( V_12 | 0x20 ) == 'r' )
V_7 . V_15 |= V_17 ;
* ( V_18 * ) ( & V_7 . V_19 ) = 0 ;
for ( V_8 = 0 , V_9 ++ ; V_8 < V_7 . V_14 ; V_8 ++ ) {
V_10 = F_1 ( V_3 -> V_13 [ V_9 ++ ] ) ;
if ( V_10 > 0x0F )
return;
V_7 . V_19 [ V_8 ] = ( V_10 << 4 ) ;
V_10 = F_1 ( V_3 -> V_13 [ V_9 ++ ] ) ;
if ( V_10 > 0x0F )
return;
V_7 . V_19 [ V_8 ] |= V_10 ;
}
V_5 = F_4 ( sizeof( struct V_6 ) ) ;
if ( ! V_5 )
return;
V_5 -> V_20 = V_3 -> V_20 ;
V_5 -> V_21 = F_5 ( V_22 ) ;
V_5 -> V_23 = V_24 ;
V_5 -> V_25 = V_26 ;
memcpy ( F_6 ( V_5 , sizeof( struct V_6 ) ) ,
& V_7 , sizeof( struct V_6 ) ) ;
F_7 ( V_5 ) ;
V_3 -> V_20 -> V_27 . V_28 ++ ;
V_3 -> V_20 -> V_27 . V_29 += V_7 . V_14 ;
}
static void F_8 ( struct V_2 * V_3 , unsigned char V_30 )
{
if ( ( V_30 == '\r' ) || ( V_30 == '\a' ) ) {
if ( ! F_9 ( V_31 , & V_3 -> V_32 ) &&
( V_3 -> V_33 > 4 ) ) {
F_2 ( V_3 ) ;
}
V_3 -> V_33 = 0 ;
} else {
if ( ! F_10 ( V_31 , & V_3 -> V_32 ) ) {
if ( V_3 -> V_33 < V_34 ) {
V_3 -> V_13 [ V_3 -> V_33 ++ ] = V_30 ;
return;
} else {
V_3 -> V_20 -> V_27 . V_35 ++ ;
F_11 ( V_31 , & V_3 -> V_32 ) ;
}
}
}
}
static void F_12 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
int V_36 , V_37 , V_8 ;
char V_12 ;
if ( V_7 -> V_15 & V_17 )
V_12 = 'R' ;
else
V_12 = 'T' ;
if ( V_7 -> V_15 & V_16 )
sprintf ( V_3 -> V_38 , L_1 , V_12 ,
V_7 -> V_15 & V_39 , V_7 -> V_14 ) ;
else
sprintf ( V_3 -> V_38 , L_2 , V_12 | 0x20 ,
V_7 -> V_15 & V_40 , V_7 -> V_14 ) ;
V_37 = strlen ( V_3 -> V_38 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_14 ; V_8 ++ )
sprintf ( & V_3 -> V_38 [ V_37 + 2 * V_8 ] , L_3 , V_7 -> V_19 [ V_8 ] ) ;
strcat ( V_3 -> V_38 , L_4 ) ;
F_11 ( V_41 , & V_3 -> V_42 -> V_32 ) ;
V_36 = V_3 -> V_42 -> V_43 -> V_44 ( V_3 -> V_42 , V_3 -> V_38 , strlen ( V_3 -> V_38 ) ) ;
V_3 -> V_45 = strlen ( V_3 -> V_38 ) - V_36 ;
V_3 -> V_46 = V_3 -> V_38 + V_36 ;
V_3 -> V_20 -> V_27 . V_47 += V_7 -> V_14 ;
}
static void F_13 ( struct V_48 * V_42 )
{
int V_36 ;
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_49 ;
if ( ! V_3 || V_3 -> V_50 != V_51 || ! F_14 ( V_3 -> V_20 ) )
return;
if ( V_3 -> V_45 <= 0 ) {
V_3 -> V_20 -> V_27 . V_52 ++ ;
F_15 ( V_41 , & V_42 -> V_32 ) ;
F_16 ( V_3 -> V_20 ) ;
return;
}
V_36 = V_42 -> V_43 -> V_44 ( V_42 , V_3 -> V_46 , V_3 -> V_45 ) ;
V_3 -> V_45 -= V_36 ;
V_3 -> V_46 += V_36 ;
}
static T_1 F_17 ( struct V_4 * V_5 , struct V_53 * V_20 )
{
struct V_2 * V_3 = F_18 ( V_20 ) ;
if ( V_5 -> V_54 != sizeof( struct V_6 ) )
goto V_55;
F_19 ( & V_3 -> V_56 ) ;
if ( ! F_14 ( V_20 ) ) {
F_20 ( & V_3 -> V_56 ) ;
F_21 ( V_57 L_5 , V_20 -> V_58 ) ;
goto V_55;
}
if ( V_3 -> V_42 == NULL ) {
F_20 ( & V_3 -> V_56 ) ;
goto V_55;
}
F_22 ( V_3 -> V_20 ) ;
F_12 ( V_3 , (struct V_6 * ) V_5 -> V_19 ) ;
F_20 ( & V_3 -> V_56 ) ;
V_55:
F_23 ( V_5 ) ;
return V_59 ;
}
static int F_24 ( struct V_53 * V_20 )
{
struct V_2 * V_3 = F_18 ( V_20 ) ;
F_25 ( & V_3 -> V_56 ) ;
if ( V_3 -> V_42 ) {
F_15 ( V_41 , & V_3 -> V_42 -> V_32 ) ;
}
F_22 ( V_20 ) ;
V_3 -> V_33 = 0 ;
V_3 -> V_45 = 0 ;
F_26 ( & V_3 -> V_56 ) ;
return 0 ;
}
static int F_27 ( struct V_53 * V_20 )
{
struct V_2 * V_3 = F_18 ( V_20 ) ;
if ( V_3 -> V_42 == NULL )
return - V_60 ;
V_3 -> V_32 &= ( 1 << V_61 ) ;
F_28 ( V_20 ) ;
return 0 ;
}
static void F_29 ( struct V_53 * V_20 )
{
int V_8 = V_20 -> V_62 ;
F_30 ( V_20 ) ;
V_63 [ V_8 ] = NULL ;
}
static void F_31 ( struct V_53 * V_20 )
{
V_20 -> V_64 = & V_65 ;
V_20 -> V_66 = F_29 ;
V_20 -> V_67 = 0 ;
V_20 -> V_68 = 0 ;
V_20 -> V_69 = 10 ;
V_20 -> V_70 = sizeof( struct V_6 ) ;
V_20 -> type = V_71 ;
V_20 -> V_32 = V_72 ;
V_20 -> V_73 = V_74 ;
}
static void F_32 ( struct V_48 * V_42 ,
const unsigned char * V_75 , char * V_76 , int V_77 )
{
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_49 ;
if ( ! V_3 || V_3 -> V_50 != V_51 || ! F_14 ( V_3 -> V_20 ) )
return;
while ( V_77 -- ) {
if ( V_76 && * V_76 ++ ) {
if ( ! F_33 ( V_31 , & V_3 -> V_32 ) )
V_3 -> V_20 -> V_27 . V_78 ++ ;
V_75 ++ ;
continue;
}
F_8 ( V_3 , * V_75 ++ ) ;
}
}
static void F_34 ( void )
{
int V_8 ;
struct V_53 * V_20 ;
struct V_2 * V_3 ;
for ( V_8 = 0 ; V_8 < V_79 ; V_8 ++ ) {
V_20 = V_63 [ V_8 ] ;
if ( V_20 == NULL )
break;
V_3 = F_18 ( V_20 ) ;
if ( V_3 -> V_42 || V_3 -> V_80 )
continue;
if ( V_20 -> V_32 & V_81 )
F_35 ( V_20 ) ;
}
}
static struct V_2 * F_36 ( T_2 line )
{
int V_8 ;
struct V_53 * V_20 = NULL ;
struct V_2 * V_3 ;
if ( V_63 == NULL )
return NULL ;
for ( V_8 = 0 ; V_8 < V_79 ; V_8 ++ ) {
V_20 = V_63 [ V_8 ] ;
if ( V_20 == NULL )
break;
}
if ( V_8 >= V_79 )
return NULL ;
if ( V_20 ) {
V_3 = F_18 ( V_20 ) ;
if ( F_10 ( V_61 , & V_3 -> V_32 ) ) {
F_37 ( V_20 ) ;
V_20 = NULL ;
V_63 [ V_8 ] = NULL ;
}
}
if ( ! V_20 ) {
char V_58 [ V_82 ] ;
sprintf ( V_58 , L_6 , V_8 ) ;
V_20 = F_38 ( sizeof( * V_3 ) , V_58 , F_31 ) ;
if ( ! V_20 )
return NULL ;
V_20 -> V_62 = V_8 ;
}
V_3 = F_18 ( V_20 ) ;
V_3 -> V_50 = V_51 ;
V_3 -> V_20 = V_20 ;
F_39 ( & V_3 -> V_56 ) ;
V_63 [ V_8 ] = V_20 ;
return V_3 ;
}
static int F_40 ( struct V_48 * V_42 )
{
struct V_2 * V_3 ;
int V_83 ;
if ( ! F_41 ( V_84 ) )
return - V_85 ;
if ( V_42 -> V_43 -> V_44 == NULL )
return - V_86 ;
F_42 () ;
F_34 () ;
V_3 = V_42 -> V_49 ;
V_83 = - V_87 ;
if ( V_3 && V_3 -> V_50 == V_51 )
goto V_88;
V_83 = - V_89 ;
V_3 = F_36 ( F_43 ( V_42 ) ) ;
if ( V_3 == NULL )
goto V_88;
V_3 -> V_42 = V_42 ;
V_42 -> V_49 = V_3 ;
V_3 -> line = F_43 ( V_42 ) ;
V_3 -> V_90 = V_91 -> V_90 ;
if ( ! F_10 ( V_61 , & V_3 -> V_32 ) ) {
V_3 -> V_33 = 0 ;
V_3 -> V_45 = 0 ;
F_11 ( V_61 , & V_3 -> V_32 ) ;
V_83 = F_44 ( V_3 -> V_20 ) ;
if ( V_83 )
goto V_92;
}
F_45 () ;
V_42 -> V_93 = 65536 ;
return 0 ;
V_92:
V_3 -> V_42 = NULL ;
V_42 -> V_49 = NULL ;
F_15 ( V_61 , & V_3 -> V_32 ) ;
V_88:
F_45 () ;
return V_83 ;
}
static void F_46 ( struct V_48 * V_42 )
{
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_49 ;
if ( ! V_3 || V_3 -> V_50 != V_51 || V_3 -> V_42 != V_42 )
return;
V_42 -> V_49 = NULL ;
V_3 -> V_42 = NULL ;
if ( ! V_3 -> V_80 )
V_3 -> line = 0 ;
F_47 ( V_3 -> V_20 ) ;
}
static int F_48 ( struct V_48 * V_42 )
{
F_46 ( V_42 ) ;
return 0 ;
}
static int F_49 ( struct V_48 * V_42 , struct V_94 * V_94 ,
unsigned int V_12 , unsigned long V_95 )
{
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_49 ;
unsigned int V_10 ;
if ( ! V_3 || V_3 -> V_50 != V_51 )
return - V_96 ;
switch ( V_12 ) {
case V_97 :
V_10 = strlen ( V_3 -> V_20 -> V_58 ) + 1 ;
if ( F_50 ( ( void V_98 * ) V_95 , V_3 -> V_20 -> V_58 , V_10 ) )
return - V_99 ;
return 0 ;
case V_100 :
return - V_96 ;
default:
return F_51 ( V_42 , V_94 , V_12 , V_95 ) ;
}
}
static int T_3 F_52 ( void )
{
int V_101 ;
if ( V_79 < 4 )
V_79 = 4 ;
F_21 ( V_102 ) ;
F_21 ( V_103 L_7 , V_79 ) ;
V_63 = F_53 ( sizeof( struct V_53 * ) * V_79 , V_104 ) ;
if ( ! V_63 ) {
F_21 ( V_105 L_8 ) ;
return - V_106 ;
}
V_101 = F_54 ( V_107 , & V_108 ) ;
if ( V_101 ) {
F_21 ( V_105 L_9 ) ;
F_55 ( V_63 ) ;
}
return V_101 ;
}
static void T_4 F_56 ( void )
{
int V_8 ;
struct V_53 * V_20 ;
struct V_2 * V_3 ;
unsigned long V_109 = V_110 + V_111 ;
int V_112 = 0 ;
if ( V_63 == NULL )
return;
do {
if ( V_112 )
F_57 ( 100 ) ;
V_112 = 0 ;
for ( V_8 = 0 ; V_8 < V_79 ; V_8 ++ ) {
V_20 = V_63 [ V_8 ] ;
if ( ! V_20 )
continue;
V_3 = F_18 ( V_20 ) ;
F_25 ( & V_3 -> V_56 ) ;
if ( V_3 -> V_42 ) {
V_112 ++ ;
F_58 ( V_3 -> V_42 ) ;
}
F_26 ( & V_3 -> V_56 ) ;
}
} while ( V_112 && F_59 ( V_110 , V_109 ) );
for ( V_8 = 0 ; V_8 < V_79 ; V_8 ++ ) {
V_20 = V_63 [ V_8 ] ;
if ( ! V_20 )
continue;
V_63 [ V_8 ] = NULL ;
V_3 = F_18 ( V_20 ) ;
if ( V_3 -> V_42 ) {
F_21 ( V_105 L_10 ,
V_20 -> V_58 ) ;
V_20 -> V_66 = NULL ;
}
F_47 ( V_20 ) ;
}
F_55 ( V_63 ) ;
V_63 = NULL ;
V_8 = F_60 ( V_107 ) ;
if ( V_8 )
F_21 ( V_105 L_11 , V_8 ) ;
}
