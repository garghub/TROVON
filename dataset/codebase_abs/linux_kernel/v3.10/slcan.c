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
V_4 = F_4 ( sizeof( struct V_5 ) +
sizeof( struct V_19 ) ) ;
if ( ! V_4 )
return;
V_4 -> V_20 = V_2 -> V_20 ;
V_4 -> V_21 = F_5 ( V_22 ) ;
V_4 -> V_23 = V_24 ;
V_4 -> V_25 = V_26 ;
F_6 ( V_4 ) ;
F_7 ( V_4 ) -> V_27 = V_2 -> V_20 -> V_27 ;
memcpy ( F_8 ( V_4 , sizeof( struct V_5 ) ) ,
& V_6 , sizeof( struct V_5 ) ) ;
F_9 ( V_4 ) ;
V_2 -> V_20 -> V_28 . V_29 ++ ;
V_2 -> V_20 -> V_28 . V_30 += V_6 . V_13 ;
}
static void F_10 ( struct V_1 * V_2 , unsigned char V_31 )
{
if ( ( V_31 == '\r' ) || ( V_31 == '\a' ) ) {
if ( ! F_11 ( V_32 , & V_2 -> V_33 ) &&
( V_2 -> V_34 > 4 ) ) {
F_1 ( V_2 ) ;
}
V_2 -> V_34 = 0 ;
} else {
if ( ! F_12 ( V_32 , & V_2 -> V_33 ) ) {
if ( V_2 -> V_34 < V_35 ) {
V_2 -> V_12 [ V_2 -> V_34 ++ ] = V_31 ;
return;
} else {
V_2 -> V_20 -> V_28 . V_36 ++ ;
F_13 ( V_32 , & V_2 -> V_33 ) ;
}
}
}
}
static void F_14 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_37 , V_38 , V_7 ;
char V_11 ;
if ( V_6 -> V_14 & V_16 )
V_11 = 'R' ;
else
V_11 = 'T' ;
if ( V_6 -> V_14 & V_15 )
sprintf ( V_2 -> V_39 , L_1 , V_11 ,
V_6 -> V_14 & V_40 , V_6 -> V_13 ) ;
else
sprintf ( V_2 -> V_39 , L_2 , V_11 | 0x20 ,
V_6 -> V_14 & V_41 , V_6 -> V_13 ) ;
V_38 = strlen ( V_2 -> V_39 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_13 ; V_7 ++ )
sprintf ( & V_2 -> V_39 [ V_38 + 2 * V_7 ] , L_3 , V_6 -> V_18 [ V_7 ] ) ;
strcat ( V_2 -> V_39 , L_4 ) ;
F_13 ( V_42 , & V_2 -> V_43 -> V_33 ) ;
V_37 = V_2 -> V_43 -> V_44 -> V_45 ( V_2 -> V_43 , V_2 -> V_39 , strlen ( V_2 -> V_39 ) ) ;
V_2 -> V_46 = strlen ( V_2 -> V_39 ) - V_37 ;
V_2 -> V_47 = V_2 -> V_39 + V_37 ;
V_2 -> V_20 -> V_28 . V_48 += V_6 -> V_13 ;
}
static void F_15 ( struct V_49 * V_43 )
{
int V_37 ;
struct V_1 * V_2 = (struct V_1 * ) V_43 -> V_50 ;
if ( ! V_2 || V_2 -> V_51 != V_52 || ! F_16 ( V_2 -> V_20 ) )
return;
if ( V_2 -> V_46 <= 0 ) {
V_2 -> V_20 -> V_28 . V_53 ++ ;
F_17 ( V_42 , & V_43 -> V_33 ) ;
F_18 ( V_2 -> V_20 ) ;
return;
}
V_37 = V_43 -> V_44 -> V_45 ( V_43 , V_2 -> V_47 , V_2 -> V_46 ) ;
V_2 -> V_46 -= V_37 ;
V_2 -> V_47 += V_37 ;
}
static T_1 F_19 ( struct V_3 * V_4 , struct V_54 * V_20 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
if ( V_4 -> V_55 != sizeof( struct V_5 ) )
goto V_56;
F_21 ( & V_2 -> V_57 ) ;
if ( ! F_16 ( V_20 ) ) {
F_22 ( & V_2 -> V_57 ) ;
F_23 ( V_58 L_5 , V_20 -> V_59 ) ;
goto V_56;
}
if ( V_2 -> V_43 == NULL ) {
F_22 ( & V_2 -> V_57 ) ;
goto V_56;
}
F_24 ( V_2 -> V_20 ) ;
F_14 ( V_2 , (struct V_5 * ) V_4 -> V_18 ) ;
F_22 ( & V_2 -> V_57 ) ;
V_56:
F_25 ( V_4 ) ;
return V_60 ;
}
static int F_26 ( struct V_54 * V_20 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
F_27 ( & V_2 -> V_57 ) ;
if ( V_2 -> V_43 ) {
F_17 ( V_42 , & V_2 -> V_43 -> V_33 ) ;
}
F_24 ( V_20 ) ;
V_2 -> V_34 = 0 ;
V_2 -> V_46 = 0 ;
F_28 ( & V_2 -> V_57 ) ;
return 0 ;
}
static int F_29 ( struct V_54 * V_20 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
if ( V_2 -> V_43 == NULL )
return - V_61 ;
V_2 -> V_33 &= ( 1 << V_62 ) ;
F_30 ( V_20 ) ;
return 0 ;
}
static void F_31 ( struct V_54 * V_20 )
{
int V_7 = V_20 -> V_63 ;
F_32 ( V_20 ) ;
V_64 [ V_7 ] = NULL ;
}
static void F_33 ( struct V_54 * V_20 )
{
V_20 -> V_65 = & V_66 ;
V_20 -> V_67 = F_31 ;
V_20 -> V_68 = 0 ;
V_20 -> V_69 = 0 ;
V_20 -> V_70 = 10 ;
V_20 -> V_71 = sizeof( struct V_5 ) ;
V_20 -> type = V_72 ;
V_20 -> V_33 = V_73 ;
V_20 -> V_74 = V_75 ;
}
static void F_34 ( struct V_49 * V_43 ,
const unsigned char * V_76 , char * V_77 , int V_78 )
{
struct V_1 * V_2 = (struct V_1 * ) V_43 -> V_50 ;
if ( ! V_2 || V_2 -> V_51 != V_52 || ! F_16 ( V_2 -> V_20 ) )
return;
while ( V_78 -- ) {
if ( V_77 && * V_77 ++ ) {
if ( ! F_35 ( V_32 , & V_2 -> V_33 ) )
V_2 -> V_20 -> V_28 . V_79 ++ ;
V_76 ++ ;
continue;
}
F_10 ( V_2 , * V_76 ++ ) ;
}
}
static void F_36 ( void )
{
int V_7 ;
struct V_54 * V_20 ;
struct V_1 * V_2 ;
for ( V_7 = 0 ; V_7 < V_80 ; V_7 ++ ) {
V_20 = V_64 [ V_7 ] ;
if ( V_20 == NULL )
break;
V_2 = F_20 ( V_20 ) ;
if ( V_2 -> V_43 )
continue;
if ( V_20 -> V_33 & V_81 )
F_37 ( V_20 ) ;
}
}
static struct V_1 * F_38 ( T_2 line )
{
int V_7 ;
char V_59 [ V_82 ] ;
struct V_54 * V_20 = NULL ;
struct V_1 * V_2 ;
for ( V_7 = 0 ; V_7 < V_80 ; V_7 ++ ) {
V_20 = V_64 [ V_7 ] ;
if ( V_20 == NULL )
break;
}
if ( V_7 >= V_80 )
return NULL ;
sprintf ( V_59 , L_6 , V_7 ) ;
V_20 = F_39 ( sizeof( * V_2 ) , V_59 , F_33 ) ;
if ( ! V_20 )
return NULL ;
V_20 -> V_63 = V_7 ;
V_2 = F_20 ( V_20 ) ;
V_2 -> V_51 = V_52 ;
V_2 -> V_20 = V_20 ;
F_40 ( & V_2 -> V_57 ) ;
V_64 [ V_7 ] = V_20 ;
return V_2 ;
}
static int F_41 ( struct V_49 * V_43 )
{
struct V_1 * V_2 ;
int V_83 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( V_43 -> V_44 -> V_45 == NULL )
return - V_86 ;
F_43 () ;
F_36 () ;
V_2 = V_43 -> V_50 ;
V_83 = - V_87 ;
if ( V_2 && V_2 -> V_51 == V_52 )
goto V_88;
V_83 = - V_89 ;
V_2 = F_38 ( F_44 ( V_43 ) ) ;
if ( V_2 == NULL )
goto V_88;
V_2 -> V_43 = V_43 ;
V_43 -> V_50 = V_2 ;
if ( ! F_12 ( V_62 , & V_2 -> V_33 ) ) {
V_2 -> V_34 = 0 ;
V_2 -> V_46 = 0 ;
F_13 ( V_62 , & V_2 -> V_33 ) ;
V_83 = F_45 ( V_2 -> V_20 ) ;
if ( V_83 )
goto V_90;
}
F_46 () ;
V_43 -> V_91 = 65536 ;
return 0 ;
V_90:
V_2 -> V_43 = NULL ;
V_43 -> V_50 = NULL ;
F_17 ( V_62 , & V_2 -> V_33 ) ;
V_88:
F_46 () ;
return V_83 ;
}
static void F_47 ( struct V_49 * V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_43 -> V_50 ;
if ( ! V_2 || V_2 -> V_51 != V_52 || V_2 -> V_43 != V_43 )
return;
V_43 -> V_50 = NULL ;
V_2 -> V_43 = NULL ;
F_48 ( V_2 -> V_20 ) ;
}
static int F_49 ( struct V_49 * V_43 )
{
F_47 ( V_43 ) ;
return 0 ;
}
static int F_50 ( struct V_49 * V_43 , struct V_92 * V_92 ,
unsigned int V_11 , unsigned long V_93 )
{
struct V_1 * V_2 = (struct V_1 * ) V_43 -> V_50 ;
unsigned int V_9 ;
if ( ! V_2 || V_2 -> V_51 != V_52 )
return - V_94 ;
switch ( V_11 ) {
case V_95 :
V_9 = strlen ( V_2 -> V_20 -> V_59 ) + 1 ;
if ( F_51 ( ( void V_96 * ) V_93 , V_2 -> V_20 -> V_59 , V_9 ) )
return - V_97 ;
return 0 ;
case V_98 :
return - V_94 ;
default:
return F_52 ( V_43 , V_92 , V_11 , V_93 ) ;
}
}
static int T_3 F_53 ( void )
{
int V_99 ;
if ( V_80 < 4 )
V_80 = 4 ;
F_23 ( V_100 ) ;
F_23 ( V_101 L_7 , V_80 ) ;
V_64 = F_54 ( sizeof( struct V_54 * ) * V_80 , V_102 ) ;
if ( ! V_64 )
return - V_103 ;
V_99 = F_55 ( V_104 , & V_105 ) ;
if ( V_99 ) {
F_23 ( V_106 L_8 ) ;
F_56 ( V_64 ) ;
}
return V_99 ;
}
static void T_4 F_57 ( void )
{
int V_7 ;
struct V_54 * V_20 ;
struct V_1 * V_2 ;
unsigned long V_107 = V_108 + V_109 ;
int V_110 = 0 ;
if ( V_64 == NULL )
return;
do {
if ( V_110 )
F_58 ( 100 ) ;
V_110 = 0 ;
for ( V_7 = 0 ; V_7 < V_80 ; V_7 ++ ) {
V_20 = V_64 [ V_7 ] ;
if ( ! V_20 )
continue;
V_2 = F_20 ( V_20 ) ;
F_27 ( & V_2 -> V_57 ) ;
if ( V_2 -> V_43 ) {
V_110 ++ ;
F_59 ( V_2 -> V_43 ) ;
}
F_28 ( & V_2 -> V_57 ) ;
}
} while ( V_110 && F_60 ( V_108 , V_107 ) );
for ( V_7 = 0 ; V_7 < V_80 ; V_7 ++ ) {
V_20 = V_64 [ V_7 ] ;
if ( ! V_20 )
continue;
V_64 [ V_7 ] = NULL ;
V_2 = F_20 ( V_20 ) ;
if ( V_2 -> V_43 ) {
F_23 ( V_106 L_9 ,
V_20 -> V_59 ) ;
V_20 -> V_67 = NULL ;
}
F_48 ( V_20 ) ;
}
F_56 ( V_64 ) ;
V_64 = NULL ;
V_7 = F_61 ( V_104 ) ;
if ( V_7 )
F_23 ( V_106 L_10 , V_7 ) ;
}
