static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 V_6 ;
int V_7 , V_8 , V_9 ;
unsigned long V_10 ;
char V_11 = V_2 -> V_12 [ 0 ] ;
if ( ( V_11 != 't' ) && ( V_11 != 'T' ) && ( V_11 != 'r' ) && ( V_11 != 'R' ) )
return;
if ( V_11 & 0x20 )
V_8 = 4 ;
else
V_8 = 9 ;
if ( ! ( ( V_2 -> V_12 [ V_8 ] >= '0' ) && ( V_2 -> V_12 [ V_8 ] < '9' ) ) )
return;
V_6 . V_13 = V_2 -> V_12 [ V_8 ] - '0' ;
V_2 -> V_12 [ V_8 ] = 0 ;
if ( F_2 ( V_2 -> V_12 + 1 , 16 , & V_10 ) )
return;
V_6 . V_14 = V_10 ;
if ( ! ( V_11 & 0x20 ) )
V_6 . V_14 |= V_15 ;
if ( ( V_11 | 0x20 ) == 'r' )
V_6 . V_14 |= V_16 ;
* ( V_17 * ) ( & V_6 . V_18 ) = 0 ;
for ( V_7 = 0 , V_8 ++ ; V_7 < V_6 . V_13 ; V_7 ++ ) {
V_9 = F_3 ( V_2 -> V_12 [ V_8 ++ ] ) ;
if ( V_9 < 0 )
return;
V_6 . V_18 [ V_7 ] = ( V_9 << 4 ) ;
V_9 = F_3 ( V_2 -> V_12 [ V_8 ++ ] ) ;
if ( V_9 < 0 )
return;
V_6 . V_18 [ V_7 ] |= V_9 ;
}
V_4 = F_4 ( sizeof( struct V_5 ) ) ;
if ( ! V_4 )
return;
V_4 -> V_19 = V_2 -> V_19 ;
V_4 -> V_20 = F_5 ( V_21 ) ;
V_4 -> V_22 = V_23 ;
V_4 -> V_24 = V_25 ;
memcpy ( F_6 ( V_4 , sizeof( struct V_5 ) ) ,
& V_6 , sizeof( struct V_5 ) ) ;
F_7 ( V_4 ) ;
V_2 -> V_19 -> V_26 . V_27 ++ ;
V_2 -> V_19 -> V_26 . V_28 += V_6 . V_13 ;
}
static void F_8 ( struct V_1 * V_2 , unsigned char V_29 )
{
if ( ( V_29 == '\r' ) || ( V_29 == '\a' ) ) {
if ( ! F_9 ( V_30 , & V_2 -> V_31 ) &&
( V_2 -> V_32 > 4 ) ) {
F_1 ( V_2 ) ;
}
V_2 -> V_32 = 0 ;
} else {
if ( ! F_10 ( V_30 , & V_2 -> V_31 ) ) {
if ( V_2 -> V_32 < V_33 ) {
V_2 -> V_12 [ V_2 -> V_32 ++ ] = V_29 ;
return;
} else {
V_2 -> V_19 -> V_26 . V_34 ++ ;
F_11 ( V_30 , & V_2 -> V_31 ) ;
}
}
}
}
static void F_12 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_35 , V_36 , V_7 ;
char V_11 ;
if ( V_6 -> V_14 & V_16 )
V_11 = 'R' ;
else
V_11 = 'T' ;
if ( V_6 -> V_14 & V_15 )
sprintf ( V_2 -> V_37 , L_1 , V_11 ,
V_6 -> V_14 & V_38 , V_6 -> V_13 ) ;
else
sprintf ( V_2 -> V_37 , L_2 , V_11 | 0x20 ,
V_6 -> V_14 & V_39 , V_6 -> V_13 ) ;
V_36 = strlen ( V_2 -> V_37 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_13 ; V_7 ++ )
sprintf ( & V_2 -> V_37 [ V_36 + 2 * V_7 ] , L_3 , V_6 -> V_18 [ V_7 ] ) ;
strcat ( V_2 -> V_37 , L_4 ) ;
F_11 ( V_40 , & V_2 -> V_41 -> V_31 ) ;
V_35 = V_2 -> V_41 -> V_42 -> V_43 ( V_2 -> V_41 , V_2 -> V_37 , strlen ( V_2 -> V_37 ) ) ;
V_2 -> V_44 = strlen ( V_2 -> V_37 ) - V_35 ;
V_2 -> V_45 = V_2 -> V_37 + V_35 ;
V_2 -> V_19 -> V_26 . V_46 += V_6 -> V_13 ;
}
static void F_13 ( struct V_47 * V_41 )
{
int V_35 ;
struct V_1 * V_2 = (struct V_1 * ) V_41 -> V_48 ;
if ( ! V_2 || V_2 -> V_49 != V_50 || ! F_14 ( V_2 -> V_19 ) )
return;
if ( V_2 -> V_44 <= 0 ) {
V_2 -> V_19 -> V_26 . V_51 ++ ;
F_15 ( V_40 , & V_41 -> V_31 ) ;
F_16 ( V_2 -> V_19 ) ;
return;
}
V_35 = V_41 -> V_42 -> V_43 ( V_41 , V_2 -> V_45 , V_2 -> V_44 ) ;
V_2 -> V_44 -= V_35 ;
V_2 -> V_45 += V_35 ;
}
static T_1 F_17 ( struct V_3 * V_4 , struct V_52 * V_19 )
{
struct V_1 * V_2 = F_18 ( V_19 ) ;
if ( V_4 -> V_53 != sizeof( struct V_5 ) )
goto V_54;
F_19 ( & V_2 -> V_55 ) ;
if ( ! F_14 ( V_19 ) ) {
F_20 ( & V_2 -> V_55 ) ;
F_21 ( V_56 L_5 , V_19 -> V_57 ) ;
goto V_54;
}
if ( V_2 -> V_41 == NULL ) {
F_20 ( & V_2 -> V_55 ) ;
goto V_54;
}
F_22 ( V_2 -> V_19 ) ;
F_12 ( V_2 , (struct V_5 * ) V_4 -> V_18 ) ;
F_20 ( & V_2 -> V_55 ) ;
V_54:
F_23 ( V_4 ) ;
return V_58 ;
}
static int F_24 ( struct V_52 * V_19 )
{
struct V_1 * V_2 = F_18 ( V_19 ) ;
F_25 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_41 ) {
F_15 ( V_40 , & V_2 -> V_41 -> V_31 ) ;
}
F_22 ( V_19 ) ;
V_2 -> V_32 = 0 ;
V_2 -> V_44 = 0 ;
F_26 ( & V_2 -> V_55 ) ;
return 0 ;
}
static int F_27 ( struct V_52 * V_19 )
{
struct V_1 * V_2 = F_18 ( V_19 ) ;
if ( V_2 -> V_41 == NULL )
return - V_59 ;
V_2 -> V_31 &= ( 1 << V_60 ) ;
F_28 ( V_19 ) ;
return 0 ;
}
static void F_29 ( struct V_52 * V_19 )
{
int V_7 = V_19 -> V_61 ;
F_30 ( V_19 ) ;
V_62 [ V_7 ] = NULL ;
}
static void F_31 ( struct V_52 * V_19 )
{
V_19 -> V_63 = & V_64 ;
V_19 -> V_65 = F_29 ;
V_19 -> V_66 = 0 ;
V_19 -> V_67 = 0 ;
V_19 -> V_68 = 10 ;
V_19 -> V_69 = sizeof( struct V_5 ) ;
V_19 -> type = V_70 ;
V_19 -> V_31 = V_71 ;
V_19 -> V_72 = V_73 ;
}
static void F_32 ( struct V_47 * V_41 ,
const unsigned char * V_74 , char * V_75 , int V_76 )
{
struct V_1 * V_2 = (struct V_1 * ) V_41 -> V_48 ;
if ( ! V_2 || V_2 -> V_49 != V_50 || ! F_14 ( V_2 -> V_19 ) )
return;
while ( V_76 -- ) {
if ( V_75 && * V_75 ++ ) {
if ( ! F_33 ( V_30 , & V_2 -> V_31 ) )
V_2 -> V_19 -> V_26 . V_77 ++ ;
V_74 ++ ;
continue;
}
F_8 ( V_2 , * V_74 ++ ) ;
}
}
static void F_34 ( void )
{
int V_7 ;
struct V_52 * V_19 ;
struct V_1 * V_2 ;
for ( V_7 = 0 ; V_7 < V_78 ; V_7 ++ ) {
V_19 = V_62 [ V_7 ] ;
if ( V_19 == NULL )
break;
V_2 = F_18 ( V_19 ) ;
if ( V_2 -> V_41 )
continue;
if ( V_19 -> V_31 & V_79 )
F_35 ( V_19 ) ;
}
}
static struct V_1 * F_36 ( T_2 line )
{
int V_7 ;
char V_57 [ V_80 ] ;
struct V_52 * V_19 = NULL ;
struct V_1 * V_2 ;
for ( V_7 = 0 ; V_7 < V_78 ; V_7 ++ ) {
V_19 = V_62 [ V_7 ] ;
if ( V_19 == NULL )
break;
}
if ( V_7 >= V_78 )
return NULL ;
sprintf ( V_57 , L_6 , V_7 ) ;
V_19 = F_37 ( sizeof( * V_2 ) , V_57 , F_31 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_61 = V_7 ;
V_2 = F_18 ( V_19 ) ;
V_2 -> V_49 = V_50 ;
V_2 -> V_19 = V_19 ;
F_38 ( & V_2 -> V_55 ) ;
V_62 [ V_7 ] = V_19 ;
return V_2 ;
}
static int F_39 ( struct V_47 * V_41 )
{
struct V_1 * V_2 ;
int V_81 ;
if ( ! F_40 ( V_82 ) )
return - V_83 ;
if ( V_41 -> V_42 -> V_43 == NULL )
return - V_84 ;
F_41 () ;
F_34 () ;
V_2 = V_41 -> V_48 ;
V_81 = - V_85 ;
if ( V_2 && V_2 -> V_49 == V_50 )
goto V_86;
V_81 = - V_87 ;
V_2 = F_36 ( F_42 ( V_41 ) ) ;
if ( V_2 == NULL )
goto V_86;
V_2 -> V_41 = V_41 ;
V_41 -> V_48 = V_2 ;
if ( ! F_10 ( V_60 , & V_2 -> V_31 ) ) {
V_2 -> V_32 = 0 ;
V_2 -> V_44 = 0 ;
F_11 ( V_60 , & V_2 -> V_31 ) ;
V_81 = F_43 ( V_2 -> V_19 ) ;
if ( V_81 )
goto V_88;
}
F_44 () ;
V_41 -> V_89 = 65536 ;
return 0 ;
V_88:
V_2 -> V_41 = NULL ;
V_41 -> V_48 = NULL ;
F_15 ( V_60 , & V_2 -> V_31 ) ;
V_86:
F_44 () ;
return V_81 ;
}
static void F_45 ( struct V_47 * V_41 )
{
struct V_1 * V_2 = (struct V_1 * ) V_41 -> V_48 ;
if ( ! V_2 || V_2 -> V_49 != V_50 || V_2 -> V_41 != V_41 )
return;
V_41 -> V_48 = NULL ;
V_2 -> V_41 = NULL ;
F_46 ( V_2 -> V_19 ) ;
}
static int F_47 ( struct V_47 * V_41 )
{
F_45 ( V_41 ) ;
return 0 ;
}
static int F_48 ( struct V_47 * V_41 , struct V_90 * V_90 ,
unsigned int V_11 , unsigned long V_91 )
{
struct V_1 * V_2 = (struct V_1 * ) V_41 -> V_48 ;
unsigned int V_9 ;
if ( ! V_2 || V_2 -> V_49 != V_50 )
return - V_92 ;
switch ( V_11 ) {
case V_93 :
V_9 = strlen ( V_2 -> V_19 -> V_57 ) + 1 ;
if ( F_49 ( ( void V_94 * ) V_91 , V_2 -> V_19 -> V_57 , V_9 ) )
return - V_95 ;
return 0 ;
case V_96 :
return - V_92 ;
default:
return F_50 ( V_41 , V_90 , V_11 , V_91 ) ;
}
}
static int T_3 F_51 ( void )
{
int V_97 ;
if ( V_78 < 4 )
V_78 = 4 ;
F_21 ( V_98 ) ;
F_21 ( V_99 L_7 , V_78 ) ;
V_62 = F_52 ( sizeof( struct V_52 * ) * V_78 , V_100 ) ;
if ( ! V_62 ) {
F_21 ( V_101 L_8 ) ;
return - V_102 ;
}
V_97 = F_53 ( V_103 , & V_104 ) ;
if ( V_97 ) {
F_21 ( V_101 L_9 ) ;
F_54 ( V_62 ) ;
}
return V_97 ;
}
static void T_4 F_55 ( void )
{
int V_7 ;
struct V_52 * V_19 ;
struct V_1 * V_2 ;
unsigned long V_105 = V_106 + V_107 ;
int V_108 = 0 ;
if ( V_62 == NULL )
return;
do {
if ( V_108 )
F_56 ( 100 ) ;
V_108 = 0 ;
for ( V_7 = 0 ; V_7 < V_78 ; V_7 ++ ) {
V_19 = V_62 [ V_7 ] ;
if ( ! V_19 )
continue;
V_2 = F_18 ( V_19 ) ;
F_25 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_41 ) {
V_108 ++ ;
F_57 ( V_2 -> V_41 ) ;
}
F_26 ( & V_2 -> V_55 ) ;
}
} while ( V_108 && F_58 ( V_106 , V_105 ) );
for ( V_7 = 0 ; V_7 < V_78 ; V_7 ++ ) {
V_19 = V_62 [ V_7 ] ;
if ( ! V_19 )
continue;
V_62 [ V_7 ] = NULL ;
V_2 = F_18 ( V_19 ) ;
if ( V_2 -> V_41 ) {
F_21 ( V_101 L_10 ,
V_19 -> V_57 ) ;
V_19 -> V_65 = NULL ;
}
F_46 ( V_19 ) ;
}
F_54 ( V_62 ) ;
V_62 = NULL ;
V_7 = F_59 ( V_103 ) ;
if ( V_7 )
F_21 ( V_101 L_11 , V_7 ) ;
}
