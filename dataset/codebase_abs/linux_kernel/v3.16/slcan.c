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
memcpy ( F_8 ( V_4 , sizeof( struct V_5 ) ) ,
& V_6 , sizeof( struct V_5 ) ) ;
F_9 ( V_4 ) ;
V_2 -> V_22 -> V_30 . V_31 ++ ;
V_2 -> V_22 -> V_30 . V_32 += V_6 . V_14 ;
}
static void F_10 ( struct V_1 * V_2 , unsigned char V_33 )
{
if ( ( V_33 == '\r' ) || ( V_33 == '\a' ) ) {
if ( ! F_11 ( V_34 , & V_2 -> V_35 ) &&
( V_2 -> V_36 > 4 ) ) {
F_1 ( V_2 ) ;
}
V_2 -> V_36 = 0 ;
} else {
if ( ! F_12 ( V_34 , & V_2 -> V_35 ) ) {
if ( V_2 -> V_36 < V_37 ) {
V_2 -> V_11 [ V_2 -> V_36 ++ ] = V_33 ;
return;
} else {
V_2 -> V_22 -> V_30 . V_38 ++ ;
F_13 ( V_34 , & V_2 -> V_35 ) ;
}
}
}
}
static void F_14 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_39 , V_7 ;
unsigned char * V_40 ;
unsigned char * V_41 ;
T_2 V_42 = V_6 -> V_12 ;
V_40 = V_2 -> V_43 ;
if ( V_6 -> V_12 & V_13 )
* V_40 = 'R' ;
else
* V_40 = 'T' ;
if ( V_6 -> V_12 & V_17 ) {
V_42 &= V_44 ;
V_41 = V_40 + V_18 ;
} else {
* V_40 |= 0x20 ;
V_42 &= V_45 ;
V_41 = V_40 + V_16 ;
}
V_40 ++ ;
while ( V_41 >= V_40 ) {
* V_41 -- = V_46 [ V_42 & 0xf ] ;
V_42 >>= 4 ;
}
V_40 += ( V_6 -> V_12 & V_17 ) ? V_18 : V_16 ;
* V_40 ++ = V_6 -> V_14 + '0' ;
if ( ! ( V_6 -> V_12 & V_13 ) ) {
for ( V_7 = 0 ; V_7 < V_6 -> V_14 ; V_7 ++ )
V_40 = F_15 ( V_40 , V_6 -> V_20 [ V_7 ] ) ;
}
* V_40 ++ = '\r' ;
F_13 ( V_47 , & V_2 -> V_48 -> V_35 ) ;
V_39 = V_2 -> V_48 -> V_49 -> V_50 ( V_2 -> V_48 , V_2 -> V_43 , V_40 - V_2 -> V_43 ) ;
V_2 -> V_51 = ( V_40 - V_2 -> V_43 ) - V_39 ;
V_2 -> V_52 = V_2 -> V_43 + V_39 ;
V_2 -> V_22 -> V_30 . V_53 += V_6 -> V_14 ;
}
static void F_16 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_17 ( V_55 , struct V_1 , V_56 ) ;
int V_39 ;
F_18 ( & V_2 -> V_57 ) ;
if ( ! V_2 -> V_48 || V_2 -> V_58 != V_59 || ! F_19 ( V_2 -> V_22 ) ) {
F_20 ( & V_2 -> V_57 ) ;
return;
}
if ( V_2 -> V_51 <= 0 ) {
V_2 -> V_22 -> V_30 . V_60 ++ ;
F_21 ( V_47 , & V_2 -> V_48 -> V_35 ) ;
F_20 ( & V_2 -> V_57 ) ;
F_22 ( V_2 -> V_22 ) ;
return;
}
V_39 = V_2 -> V_48 -> V_49 -> V_50 ( V_2 -> V_48 , V_2 -> V_52 , V_2 -> V_51 ) ;
V_2 -> V_51 -= V_39 ;
V_2 -> V_52 += V_39 ;
F_20 ( & V_2 -> V_57 ) ;
}
static void F_23 ( struct V_61 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_62 ;
F_24 ( & V_2 -> V_56 ) ;
}
static T_3 F_25 ( struct V_3 * V_4 , struct V_63 * V_22 )
{
struct V_1 * V_2 = F_26 ( V_22 ) ;
if ( V_4 -> V_64 != sizeof( struct V_5 ) )
goto V_65;
F_27 ( & V_2 -> V_57 ) ;
if ( ! F_19 ( V_22 ) ) {
F_28 ( & V_2 -> V_57 ) ;
F_29 ( V_66 L_1 , V_22 -> V_67 ) ;
goto V_65;
}
if ( V_2 -> V_48 == NULL ) {
F_28 ( & V_2 -> V_57 ) ;
goto V_65;
}
F_30 ( V_2 -> V_22 ) ;
F_14 ( V_2 , (struct V_5 * ) V_4 -> V_20 ) ;
F_28 ( & V_2 -> V_57 ) ;
V_65:
F_31 ( V_4 ) ;
return V_68 ;
}
static int F_32 ( struct V_63 * V_22 )
{
struct V_1 * V_2 = F_26 ( V_22 ) ;
F_18 ( & V_2 -> V_57 ) ;
if ( V_2 -> V_48 ) {
F_21 ( V_47 , & V_2 -> V_48 -> V_35 ) ;
}
F_30 ( V_22 ) ;
V_2 -> V_36 = 0 ;
V_2 -> V_51 = 0 ;
F_20 ( & V_2 -> V_57 ) ;
return 0 ;
}
static int F_33 ( struct V_63 * V_22 )
{
struct V_1 * V_2 = F_26 ( V_22 ) ;
if ( V_2 -> V_48 == NULL )
return - V_69 ;
V_2 -> V_35 &= ( 1 << V_70 ) ;
F_34 ( V_22 ) ;
return 0 ;
}
static void F_35 ( struct V_63 * V_22 )
{
int V_7 = V_22 -> V_71 ;
F_36 ( V_22 ) ;
V_72 [ V_7 ] = NULL ;
}
static int F_37 ( struct V_63 * V_22 , int V_73 )
{
return - V_74 ;
}
static void F_38 ( struct V_63 * V_22 )
{
V_22 -> V_75 = & V_76 ;
V_22 -> V_77 = F_35 ;
V_22 -> V_78 = 0 ;
V_22 -> V_79 = 0 ;
V_22 -> V_80 = 10 ;
V_22 -> V_81 = sizeof( struct V_5 ) ;
V_22 -> type = V_82 ;
V_22 -> V_35 = V_83 ;
V_22 -> V_84 = V_85 ;
}
static void F_39 ( struct V_61 * V_48 ,
const unsigned char * V_86 , char * V_87 , int V_88 )
{
struct V_1 * V_2 = (struct V_1 * ) V_48 -> V_62 ;
if ( ! V_2 || V_2 -> V_58 != V_59 || ! F_19 ( V_2 -> V_22 ) )
return;
while ( V_88 -- ) {
if ( V_87 && * V_87 ++ ) {
if ( ! F_40 ( V_34 , & V_2 -> V_35 ) )
V_2 -> V_22 -> V_30 . V_89 ++ ;
V_86 ++ ;
continue;
}
F_10 ( V_2 , * V_86 ++ ) ;
}
}
static void F_41 ( void )
{
int V_7 ;
struct V_63 * V_22 ;
struct V_1 * V_2 ;
for ( V_7 = 0 ; V_7 < V_90 ; V_7 ++ ) {
V_22 = V_72 [ V_7 ] ;
if ( V_22 == NULL )
break;
V_2 = F_26 ( V_22 ) ;
if ( V_2 -> V_48 )
continue;
if ( V_22 -> V_35 & V_91 )
F_42 ( V_22 ) ;
}
}
static struct V_1 * F_43 ( T_4 line )
{
int V_7 ;
char V_67 [ V_92 ] ;
struct V_63 * V_22 = NULL ;
struct V_1 * V_2 ;
for ( V_7 = 0 ; V_7 < V_90 ; V_7 ++ ) {
V_22 = V_72 [ V_7 ] ;
if ( V_22 == NULL )
break;
}
if ( V_7 >= V_90 )
return NULL ;
sprintf ( V_67 , L_2 , V_7 ) ;
V_22 = F_44 ( sizeof( * V_2 ) , V_67 , F_38 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_71 = V_7 ;
V_2 = F_26 ( V_22 ) ;
V_2 -> V_58 = V_59 ;
V_2 -> V_22 = V_22 ;
F_45 ( & V_2 -> V_57 ) ;
F_46 ( & V_2 -> V_56 , F_16 ) ;
V_72 [ V_7 ] = V_22 ;
return V_2 ;
}
static int F_47 ( struct V_61 * V_48 )
{
struct V_1 * V_2 ;
int V_93 ;
if ( ! F_48 ( V_94 ) )
return - V_95 ;
if ( V_48 -> V_49 -> V_50 == NULL )
return - V_96 ;
F_49 () ;
F_41 () ;
V_2 = V_48 -> V_62 ;
V_93 = - V_97 ;
if ( V_2 && V_2 -> V_58 == V_59 )
goto V_98;
V_93 = - V_99 ;
V_2 = F_43 ( F_50 ( V_48 ) ) ;
if ( V_2 == NULL )
goto V_98;
V_2 -> V_48 = V_48 ;
V_48 -> V_62 = V_2 ;
if ( ! F_12 ( V_70 , & V_2 -> V_35 ) ) {
V_2 -> V_36 = 0 ;
V_2 -> V_51 = 0 ;
F_13 ( V_70 , & V_2 -> V_35 ) ;
V_93 = F_51 ( V_2 -> V_22 ) ;
if ( V_93 )
goto V_100;
}
F_52 () ;
V_48 -> V_101 = 65536 ;
return 0 ;
V_100:
V_2 -> V_48 = NULL ;
V_48 -> V_62 = NULL ;
F_21 ( V_70 , & V_2 -> V_35 ) ;
V_98:
F_52 () ;
return V_93 ;
}
static void F_53 ( struct V_61 * V_48 )
{
struct V_1 * V_2 = (struct V_1 * ) V_48 -> V_62 ;
if ( ! V_2 || V_2 -> V_58 != V_59 || V_2 -> V_48 != V_48 )
return;
F_18 ( & V_2 -> V_57 ) ;
V_48 -> V_62 = NULL ;
V_2 -> V_48 = NULL ;
F_20 ( & V_2 -> V_57 ) ;
F_54 ( & V_2 -> V_56 ) ;
F_55 ( V_2 -> V_22 ) ;
}
static int F_56 ( struct V_61 * V_48 )
{
F_53 ( V_48 ) ;
return 0 ;
}
static int F_57 ( struct V_61 * V_48 , struct V_102 * V_102 ,
unsigned int V_10 , unsigned long V_103 )
{
struct V_1 * V_2 = (struct V_1 * ) V_48 -> V_62 ;
unsigned int V_8 ;
if ( ! V_2 || V_2 -> V_58 != V_59 )
return - V_74 ;
switch ( V_10 ) {
case V_104 :
V_8 = strlen ( V_2 -> V_22 -> V_67 ) + 1 ;
if ( F_58 ( ( void V_105 * ) V_103 , V_2 -> V_22 -> V_67 , V_8 ) )
return - V_106 ;
return 0 ;
case V_107 :
return - V_74 ;
default:
return F_59 ( V_48 , V_102 , V_10 , V_103 ) ;
}
}
static int T_5 F_60 ( void )
{
int V_108 ;
if ( V_90 < 4 )
V_90 = 4 ;
F_29 ( V_109 ) ;
F_29 ( V_110 L_3 , V_90 ) ;
V_72 = F_61 ( sizeof( struct V_63 * ) * V_90 , V_111 ) ;
if ( ! V_72 )
return - V_112 ;
V_108 = F_62 ( V_113 , & V_114 ) ;
if ( V_108 ) {
F_29 ( V_115 L_4 ) ;
F_63 ( V_72 ) ;
}
return V_108 ;
}
static void T_6 F_64 ( void )
{
int V_7 ;
struct V_63 * V_22 ;
struct V_1 * V_2 ;
unsigned long V_116 = V_117 + V_118 ;
int V_119 = 0 ;
if ( V_72 == NULL )
return;
do {
if ( V_119 )
F_65 ( 100 ) ;
V_119 = 0 ;
for ( V_7 = 0 ; V_7 < V_90 ; V_7 ++ ) {
V_22 = V_72 [ V_7 ] ;
if ( ! V_22 )
continue;
V_2 = F_26 ( V_22 ) ;
F_18 ( & V_2 -> V_57 ) ;
if ( V_2 -> V_48 ) {
V_119 ++ ;
F_66 ( V_2 -> V_48 ) ;
}
F_20 ( & V_2 -> V_57 ) ;
}
} while ( V_119 && F_67 ( V_117 , V_116 ) );
for ( V_7 = 0 ; V_7 < V_90 ; V_7 ++ ) {
V_22 = V_72 [ V_7 ] ;
if ( ! V_22 )
continue;
V_72 [ V_7 ] = NULL ;
V_2 = F_26 ( V_22 ) ;
if ( V_2 -> V_48 ) {
F_29 ( V_115 L_5 ,
V_22 -> V_67 ) ;
V_22 -> V_77 = NULL ;
}
F_55 ( V_22 ) ;
}
F_63 ( V_72 ) ;
V_72 = NULL ;
V_7 = F_68 ( V_113 ) ;
if ( V_7 )
F_29 ( V_115 L_6 , V_7 ) ;
}
