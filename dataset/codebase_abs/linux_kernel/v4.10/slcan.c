static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 V_6 ;
int V_7 , V_8 ;
T_1 V_9 ;
char * V_10 = V_2 -> V_11 ;
V_6 . V_12 = 0 ;
switch ( * V_10 ) {
case 'r' :
V_6 . V_12 = V_13 ;
case 't' :
V_6 . V_14 = V_2 -> V_11 [ V_15 + V_16 ] ;
V_2 -> V_11 [ V_15 + V_16 ] = 0 ;
V_10 += V_15 + V_16 + 1 ;
break;
case 'R' :
V_6 . V_12 = V_13 ;
case 'T' :
V_6 . V_12 |= V_17 ;
V_6 . V_14 = V_2 -> V_11 [ V_15 + V_18 ] ;
V_2 -> V_11 [ V_15 + V_18 ] = 0 ;
V_10 += V_15 + V_18 + 1 ;
break;
default:
return;
}
if ( F_2 ( V_2 -> V_11 + V_15 , 16 , & V_9 ) )
return;
V_6 . V_12 |= V_9 ;
if ( V_6 . V_14 >= '0' && V_6 . V_14 < '9' )
V_6 . V_14 -= '0' ;
else
return;
* ( V_19 * ) ( & V_6 . V_20 ) = 0 ;
if ( ! ( V_6 . V_12 & V_13 ) ) {
for ( V_7 = 0 ; V_7 < V_6 . V_14 ; V_7 ++ ) {
V_8 = F_3 ( * V_10 ++ ) ;
if ( V_8 < 0 )
return;
V_6 . V_20 [ V_7 ] = ( V_8 << 4 ) ;
V_8 = F_3 ( * V_10 ++ ) ;
if ( V_8 < 0 )
return;
V_6 . V_20 [ V_7 ] |= V_8 ;
}
}
V_4 = F_4 ( sizeof( struct V_5 ) +
sizeof( struct V_21 ) ) ;
if ( ! V_4 )
return;
V_4 -> V_22 = V_2 -> V_22 ;
V_4 -> V_23 = F_5 ( V_24 ) ;
V_4 -> V_25 = V_26 ;
V_4 -> V_27 = V_28 ;
F_6 ( V_4 ) ;
F_7 ( V_4 ) -> V_29 = V_2 -> V_22 -> V_29 ;
F_7 ( V_4 ) -> V_30 = 0 ;
memcpy ( F_8 ( V_4 , sizeof( struct V_5 ) ) ,
& V_6 , sizeof( struct V_5 ) ) ;
V_2 -> V_22 -> V_31 . V_32 ++ ;
V_2 -> V_22 -> V_31 . V_33 += V_6 . V_14 ;
F_9 ( V_4 ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned char V_34 )
{
if ( ( V_34 == '\r' ) || ( V_34 == '\a' ) ) {
if ( ! F_11 ( V_35 , & V_2 -> V_36 ) &&
( V_2 -> V_37 > 4 ) ) {
F_1 ( V_2 ) ;
}
V_2 -> V_37 = 0 ;
} else {
if ( ! F_12 ( V_35 , & V_2 -> V_36 ) ) {
if ( V_2 -> V_37 < V_38 ) {
V_2 -> V_11 [ V_2 -> V_37 ++ ] = V_34 ;
return;
} else {
V_2 -> V_22 -> V_31 . V_39 ++ ;
F_13 ( V_35 , & V_2 -> V_36 ) ;
}
}
}
}
static void F_14 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_40 , V_7 ;
unsigned char * V_41 ;
unsigned char * V_42 ;
T_2 V_43 = V_6 -> V_12 ;
V_41 = V_2 -> V_44 ;
if ( V_6 -> V_12 & V_13 )
* V_41 = 'R' ;
else
* V_41 = 'T' ;
if ( V_6 -> V_12 & V_17 ) {
V_43 &= V_45 ;
V_42 = V_41 + V_18 ;
} else {
* V_41 |= 0x20 ;
V_43 &= V_46 ;
V_42 = V_41 + V_16 ;
}
V_41 ++ ;
while ( V_42 >= V_41 ) {
* V_42 -- = V_47 [ V_43 & 0xf ] ;
V_43 >>= 4 ;
}
V_41 += ( V_6 -> V_12 & V_17 ) ? V_18 : V_16 ;
* V_41 ++ = V_6 -> V_14 + '0' ;
if ( ! ( V_6 -> V_12 & V_13 ) ) {
for ( V_7 = 0 ; V_7 < V_6 -> V_14 ; V_7 ++ )
V_41 = F_15 ( V_41 , V_6 -> V_20 [ V_7 ] ) ;
}
* V_41 ++ = '\r' ;
F_13 ( V_48 , & V_2 -> V_49 -> V_36 ) ;
V_40 = V_2 -> V_49 -> V_50 -> V_51 ( V_2 -> V_49 , V_2 -> V_44 , V_41 - V_2 -> V_44 ) ;
V_2 -> V_52 = ( V_41 - V_2 -> V_44 ) - V_40 ;
V_2 -> V_53 = V_2 -> V_44 + V_40 ;
V_2 -> V_22 -> V_31 . V_54 += V_6 -> V_14 ;
}
static void F_16 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_17 ( V_56 , struct V_1 , V_57 ) ;
int V_40 ;
F_18 ( & V_2 -> V_58 ) ;
if ( ! V_2 -> V_49 || V_2 -> V_59 != V_60 || ! F_19 ( V_2 -> V_22 ) ) {
F_20 ( & V_2 -> V_58 ) ;
return;
}
if ( V_2 -> V_52 <= 0 ) {
V_2 -> V_22 -> V_31 . V_61 ++ ;
F_21 ( V_48 , & V_2 -> V_49 -> V_36 ) ;
F_20 ( & V_2 -> V_58 ) ;
F_22 ( V_2 -> V_22 ) ;
return;
}
V_40 = V_2 -> V_49 -> V_50 -> V_51 ( V_2 -> V_49 , V_2 -> V_53 , V_2 -> V_52 ) ;
V_2 -> V_52 -= V_40 ;
V_2 -> V_53 += V_40 ;
F_20 ( & V_2 -> V_58 ) ;
}
static void F_23 ( struct V_62 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_63 ;
F_24 ( & V_2 -> V_57 ) ;
}
static T_3 F_25 ( struct V_3 * V_4 , struct V_64 * V_22 )
{
struct V_1 * V_2 = F_26 ( V_22 ) ;
if ( V_4 -> V_65 != V_66 )
goto V_67;
F_27 ( & V_2 -> V_58 ) ;
if ( ! F_19 ( V_22 ) ) {
F_28 ( & V_2 -> V_58 ) ;
F_29 ( V_68 L_1 , V_22 -> V_69 ) ;
goto V_67;
}
if ( V_2 -> V_49 == NULL ) {
F_28 ( & V_2 -> V_58 ) ;
goto V_67;
}
F_30 ( V_2 -> V_22 ) ;
F_14 ( V_2 , (struct V_5 * ) V_4 -> V_20 ) ;
F_28 ( & V_2 -> V_58 ) ;
V_67:
F_31 ( V_4 ) ;
return V_70 ;
}
static int F_32 ( struct V_64 * V_22 )
{
struct V_1 * V_2 = F_26 ( V_22 ) ;
F_18 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_49 ) {
F_21 ( V_48 , & V_2 -> V_49 -> V_36 ) ;
}
F_30 ( V_22 ) ;
V_2 -> V_37 = 0 ;
V_2 -> V_52 = 0 ;
F_20 ( & V_2 -> V_58 ) ;
return 0 ;
}
static int F_33 ( struct V_64 * V_22 )
{
struct V_1 * V_2 = F_26 ( V_22 ) ;
if ( V_2 -> V_49 == NULL )
return - V_71 ;
V_2 -> V_36 &= ( 1 << V_72 ) ;
F_34 ( V_22 ) ;
return 0 ;
}
static void F_35 ( struct V_64 * V_22 )
{
int V_7 = V_22 -> V_73 ;
F_36 ( V_22 ) ;
V_74 [ V_7 ] = NULL ;
}
static int F_37 ( struct V_64 * V_22 , int V_75 )
{
return - V_76 ;
}
static void F_38 ( struct V_64 * V_22 )
{
V_22 -> V_77 = & V_78 ;
V_22 -> V_79 = F_35 ;
V_22 -> V_80 = 0 ;
V_22 -> V_81 = 0 ;
V_22 -> V_82 = 10 ;
V_22 -> V_83 = V_66 ;
V_22 -> type = V_84 ;
V_22 -> V_36 = V_85 ;
V_22 -> V_86 = V_87 ;
}
static void F_39 ( struct V_62 * V_49 ,
const unsigned char * V_88 , char * V_89 , int V_90 )
{
struct V_1 * V_2 = (struct V_1 * ) V_49 -> V_63 ;
if ( ! V_2 || V_2 -> V_59 != V_60 || ! F_19 ( V_2 -> V_22 ) )
return;
while ( V_90 -- ) {
if ( V_89 && * V_89 ++ ) {
if ( ! F_40 ( V_35 , & V_2 -> V_36 ) )
V_2 -> V_22 -> V_31 . V_91 ++ ;
V_88 ++ ;
continue;
}
F_10 ( V_2 , * V_88 ++ ) ;
}
}
static void F_41 ( void )
{
int V_7 ;
struct V_64 * V_22 ;
struct V_1 * V_2 ;
for ( V_7 = 0 ; V_7 < V_92 ; V_7 ++ ) {
V_22 = V_74 [ V_7 ] ;
if ( V_22 == NULL )
break;
V_2 = F_26 ( V_22 ) ;
if ( V_2 -> V_49 )
continue;
if ( V_22 -> V_36 & V_93 )
F_42 ( V_22 ) ;
}
}
static struct V_1 * F_43 ( T_4 line )
{
int V_7 ;
char V_69 [ V_94 ] ;
struct V_64 * V_22 = NULL ;
struct V_1 * V_2 ;
for ( V_7 = 0 ; V_7 < V_92 ; V_7 ++ ) {
V_22 = V_74 [ V_7 ] ;
if ( V_22 == NULL )
break;
}
if ( V_7 >= V_92 )
return NULL ;
sprintf ( V_69 , L_2 , V_7 ) ;
V_22 = F_44 ( sizeof( * V_2 ) , V_69 , V_95 , F_38 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_73 = V_7 ;
V_2 = F_26 ( V_22 ) ;
V_2 -> V_59 = V_60 ;
V_2 -> V_22 = V_22 ;
F_45 ( & V_2 -> V_58 ) ;
F_46 ( & V_2 -> V_57 , F_16 ) ;
V_74 [ V_7 ] = V_22 ;
return V_2 ;
}
static int F_47 ( struct V_62 * V_49 )
{
struct V_1 * V_2 ;
int V_96 ;
if ( ! F_48 ( V_97 ) )
return - V_98 ;
if ( V_49 -> V_50 -> V_51 == NULL )
return - V_99 ;
F_49 () ;
F_41 () ;
V_2 = V_49 -> V_63 ;
V_96 = - V_100 ;
if ( V_2 && V_2 -> V_59 == V_60 )
goto V_101;
V_96 = - V_102 ;
V_2 = F_43 ( F_50 ( V_49 ) ) ;
if ( V_2 == NULL )
goto V_101;
V_2 -> V_49 = V_49 ;
V_49 -> V_63 = V_2 ;
if ( ! F_12 ( V_72 , & V_2 -> V_36 ) ) {
V_2 -> V_37 = 0 ;
V_2 -> V_52 = 0 ;
F_13 ( V_72 , & V_2 -> V_36 ) ;
V_96 = F_51 ( V_2 -> V_22 ) ;
if ( V_96 )
goto V_103;
}
F_52 () ;
V_49 -> V_104 = 65536 ;
return 0 ;
V_103:
V_2 -> V_49 = NULL ;
V_49 -> V_63 = NULL ;
F_21 ( V_72 , & V_2 -> V_36 ) ;
V_101:
F_52 () ;
return V_96 ;
}
static void F_53 ( struct V_62 * V_49 )
{
struct V_1 * V_2 = (struct V_1 * ) V_49 -> V_63 ;
if ( ! V_2 || V_2 -> V_59 != V_60 || V_2 -> V_49 != V_49 )
return;
F_18 ( & V_2 -> V_58 ) ;
V_49 -> V_63 = NULL ;
V_2 -> V_49 = NULL ;
F_20 ( & V_2 -> V_58 ) ;
F_54 ( & V_2 -> V_57 ) ;
F_55 ( V_2 -> V_22 ) ;
}
static int F_56 ( struct V_62 * V_49 )
{
F_53 ( V_49 ) ;
return 0 ;
}
static int F_57 ( struct V_62 * V_49 , struct V_105 * V_105 ,
unsigned int V_10 , unsigned long V_106 )
{
struct V_1 * V_2 = (struct V_1 * ) V_49 -> V_63 ;
unsigned int V_8 ;
if ( ! V_2 || V_2 -> V_59 != V_60 )
return - V_76 ;
switch ( V_10 ) {
case V_107 :
V_8 = strlen ( V_2 -> V_22 -> V_69 ) + 1 ;
if ( F_58 ( ( void V_108 * ) V_106 , V_2 -> V_22 -> V_69 , V_8 ) )
return - V_109 ;
return 0 ;
case V_110 :
return - V_76 ;
default:
return F_59 ( V_49 , V_105 , V_10 , V_106 ) ;
}
}
static int T_5 F_60 ( void )
{
int V_111 ;
if ( V_92 < 4 )
V_92 = 4 ;
F_61 ( L_3 ) ;
F_61 ( L_4 , V_92 ) ;
V_74 = F_62 ( sizeof( struct V_64 * ) * V_92 , V_112 ) ;
if ( ! V_74 )
return - V_113 ;
V_111 = F_63 ( V_114 , & V_115 ) ;
if ( V_111 ) {
F_29 ( V_116 L_5 ) ;
F_64 ( V_74 ) ;
}
return V_111 ;
}
static void T_6 F_65 ( void )
{
int V_7 ;
struct V_64 * V_22 ;
struct V_1 * V_2 ;
unsigned long V_117 = V_118 + V_119 ;
int V_120 = 0 ;
if ( V_74 == NULL )
return;
do {
if ( V_120 )
F_66 ( 100 ) ;
V_120 = 0 ;
for ( V_7 = 0 ; V_7 < V_92 ; V_7 ++ ) {
V_22 = V_74 [ V_7 ] ;
if ( ! V_22 )
continue;
V_2 = F_26 ( V_22 ) ;
F_18 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_49 ) {
V_120 ++ ;
F_67 ( V_2 -> V_49 ) ;
}
F_20 ( & V_2 -> V_58 ) ;
}
} while ( V_120 && F_68 ( V_118 , V_117 ) );
for ( V_7 = 0 ; V_7 < V_92 ; V_7 ++ ) {
V_22 = V_74 [ V_7 ] ;
if ( ! V_22 )
continue;
V_74 [ V_7 ] = NULL ;
V_2 = F_26 ( V_22 ) ;
if ( V_2 -> V_49 ) {
F_29 ( V_116 L_6 ,
V_22 -> V_69 ) ;
V_22 -> V_79 = NULL ;
}
F_55 ( V_22 ) ;
}
F_64 ( V_74 ) ;
V_74 = NULL ;
V_7 = F_69 ( V_114 ) ;
if ( V_7 )
F_29 ( V_116 L_7 , V_7 ) ;
}
