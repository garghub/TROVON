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
static void F_16 ( struct V_54 * V_48 )
{
int V_39 ;
struct V_1 * V_2 = (struct V_1 * ) V_48 -> V_55 ;
if ( ! V_2 || V_2 -> V_56 != V_57 || ! F_17 ( V_2 -> V_22 ) )
return;
F_18 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_51 <= 0 ) {
V_2 -> V_22 -> V_30 . V_59 ++ ;
F_19 ( V_47 , & V_48 -> V_35 ) ;
F_20 ( & V_2 -> V_58 ) ;
F_21 ( V_2 -> V_22 ) ;
return;
}
V_39 = V_48 -> V_49 -> V_50 ( V_48 , V_2 -> V_52 , V_2 -> V_51 ) ;
V_2 -> V_51 -= V_39 ;
V_2 -> V_52 += V_39 ;
F_20 ( & V_2 -> V_58 ) ;
}
static T_3 F_22 ( struct V_3 * V_4 , struct V_60 * V_22 )
{
struct V_1 * V_2 = F_23 ( V_22 ) ;
if ( V_4 -> V_61 != sizeof( struct V_5 ) )
goto V_62;
F_18 ( & V_2 -> V_58 ) ;
if ( ! F_17 ( V_22 ) ) {
F_20 ( & V_2 -> V_58 ) ;
F_24 ( V_63 L_1 , V_22 -> V_64 ) ;
goto V_62;
}
if ( V_2 -> V_48 == NULL ) {
F_20 ( & V_2 -> V_58 ) ;
goto V_62;
}
F_25 ( V_2 -> V_22 ) ;
F_14 ( V_2 , (struct V_5 * ) V_4 -> V_20 ) ;
F_20 ( & V_2 -> V_58 ) ;
V_62:
F_26 ( V_4 ) ;
return V_65 ;
}
static int F_27 ( struct V_60 * V_22 )
{
struct V_1 * V_2 = F_23 ( V_22 ) ;
F_28 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_48 ) {
F_19 ( V_47 , & V_2 -> V_48 -> V_35 ) ;
}
F_25 ( V_22 ) ;
V_2 -> V_36 = 0 ;
V_2 -> V_51 = 0 ;
F_29 ( & V_2 -> V_58 ) ;
return 0 ;
}
static int F_30 ( struct V_60 * V_22 )
{
struct V_1 * V_2 = F_23 ( V_22 ) ;
if ( V_2 -> V_48 == NULL )
return - V_66 ;
V_2 -> V_35 &= ( 1 << V_67 ) ;
F_31 ( V_22 ) ;
return 0 ;
}
static void F_32 ( struct V_60 * V_22 )
{
int V_7 = V_22 -> V_68 ;
F_33 ( V_22 ) ;
V_69 [ V_7 ] = NULL ;
}
static void F_34 ( struct V_60 * V_22 )
{
V_22 -> V_70 = & V_71 ;
V_22 -> V_72 = F_32 ;
V_22 -> V_73 = 0 ;
V_22 -> V_74 = 0 ;
V_22 -> V_75 = 10 ;
V_22 -> V_76 = sizeof( struct V_5 ) ;
V_22 -> type = V_77 ;
V_22 -> V_35 = V_78 ;
V_22 -> V_79 = V_80 ;
}
static void F_35 ( struct V_54 * V_48 ,
const unsigned char * V_81 , char * V_82 , int V_83 )
{
struct V_1 * V_2 = (struct V_1 * ) V_48 -> V_55 ;
if ( ! V_2 || V_2 -> V_56 != V_57 || ! F_17 ( V_2 -> V_22 ) )
return;
while ( V_83 -- ) {
if ( V_82 && * V_82 ++ ) {
if ( ! F_36 ( V_34 , & V_2 -> V_35 ) )
V_2 -> V_22 -> V_30 . V_84 ++ ;
V_81 ++ ;
continue;
}
F_10 ( V_2 , * V_81 ++ ) ;
}
}
static void F_37 ( void )
{
int V_7 ;
struct V_60 * V_22 ;
struct V_1 * V_2 ;
for ( V_7 = 0 ; V_7 < V_85 ; V_7 ++ ) {
V_22 = V_69 [ V_7 ] ;
if ( V_22 == NULL )
break;
V_2 = F_23 ( V_22 ) ;
if ( V_2 -> V_48 )
continue;
if ( V_22 -> V_35 & V_86 )
F_38 ( V_22 ) ;
}
}
static struct V_1 * F_39 ( T_4 line )
{
int V_7 ;
char V_64 [ V_87 ] ;
struct V_60 * V_22 = NULL ;
struct V_1 * V_2 ;
for ( V_7 = 0 ; V_7 < V_85 ; V_7 ++ ) {
V_22 = V_69 [ V_7 ] ;
if ( V_22 == NULL )
break;
}
if ( V_7 >= V_85 )
return NULL ;
sprintf ( V_64 , L_2 , V_7 ) ;
V_22 = F_40 ( sizeof( * V_2 ) , V_64 , F_34 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_68 = V_7 ;
V_2 = F_23 ( V_22 ) ;
V_2 -> V_56 = V_57 ;
V_2 -> V_22 = V_22 ;
F_41 ( & V_2 -> V_58 ) ;
V_69 [ V_7 ] = V_22 ;
return V_2 ;
}
static int F_42 ( struct V_54 * V_48 )
{
struct V_1 * V_2 ;
int V_88 ;
if ( ! F_43 ( V_89 ) )
return - V_90 ;
if ( V_48 -> V_49 -> V_50 == NULL )
return - V_91 ;
F_44 () ;
F_37 () ;
V_2 = V_48 -> V_55 ;
V_88 = - V_92 ;
if ( V_2 && V_2 -> V_56 == V_57 )
goto V_93;
V_88 = - V_94 ;
V_2 = F_39 ( F_45 ( V_48 ) ) ;
if ( V_2 == NULL )
goto V_93;
V_2 -> V_48 = V_48 ;
V_48 -> V_55 = V_2 ;
if ( ! F_12 ( V_67 , & V_2 -> V_35 ) ) {
V_2 -> V_36 = 0 ;
V_2 -> V_51 = 0 ;
F_13 ( V_67 , & V_2 -> V_35 ) ;
V_88 = F_46 ( V_2 -> V_22 ) ;
if ( V_88 )
goto V_95;
}
F_47 () ;
V_48 -> V_96 = 65536 ;
return 0 ;
V_95:
V_2 -> V_48 = NULL ;
V_48 -> V_55 = NULL ;
F_19 ( V_67 , & V_2 -> V_35 ) ;
V_93:
F_47 () ;
return V_88 ;
}
static void F_48 ( struct V_54 * V_48 )
{
struct V_1 * V_2 = (struct V_1 * ) V_48 -> V_55 ;
if ( ! V_2 || V_2 -> V_56 != V_57 || V_2 -> V_48 != V_48 )
return;
V_48 -> V_55 = NULL ;
V_2 -> V_48 = NULL ;
F_49 ( V_2 -> V_22 ) ;
}
static int F_50 ( struct V_54 * V_48 )
{
F_48 ( V_48 ) ;
return 0 ;
}
static int F_51 ( struct V_54 * V_48 , struct V_97 * V_97 ,
unsigned int V_10 , unsigned long V_98 )
{
struct V_1 * V_2 = (struct V_1 * ) V_48 -> V_55 ;
unsigned int V_8 ;
if ( ! V_2 || V_2 -> V_56 != V_57 )
return - V_99 ;
switch ( V_10 ) {
case V_100 :
V_8 = strlen ( V_2 -> V_22 -> V_64 ) + 1 ;
if ( F_52 ( ( void V_101 * ) V_98 , V_2 -> V_22 -> V_64 , V_8 ) )
return - V_102 ;
return 0 ;
case V_103 :
return - V_99 ;
default:
return F_53 ( V_48 , V_97 , V_10 , V_98 ) ;
}
}
static int T_5 F_54 ( void )
{
int V_104 ;
if ( V_85 < 4 )
V_85 = 4 ;
F_24 ( V_105 ) ;
F_24 ( V_106 L_3 , V_85 ) ;
V_69 = F_55 ( sizeof( struct V_60 * ) * V_85 , V_107 ) ;
if ( ! V_69 )
return - V_108 ;
V_104 = F_56 ( V_109 , & V_110 ) ;
if ( V_104 ) {
F_24 ( V_111 L_4 ) ;
F_57 ( V_69 ) ;
}
return V_104 ;
}
static void T_6 F_58 ( void )
{
int V_7 ;
struct V_60 * V_22 ;
struct V_1 * V_2 ;
unsigned long V_112 = V_113 + V_114 ;
int V_115 = 0 ;
if ( V_69 == NULL )
return;
do {
if ( V_115 )
F_59 ( 100 ) ;
V_115 = 0 ;
for ( V_7 = 0 ; V_7 < V_85 ; V_7 ++ ) {
V_22 = V_69 [ V_7 ] ;
if ( ! V_22 )
continue;
V_2 = F_23 ( V_22 ) ;
F_28 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_48 ) {
V_115 ++ ;
F_60 ( V_2 -> V_48 ) ;
}
F_29 ( & V_2 -> V_58 ) ;
}
} while ( V_115 && F_61 ( V_113 , V_112 ) );
for ( V_7 = 0 ; V_7 < V_85 ; V_7 ++ ) {
V_22 = V_69 [ V_7 ] ;
if ( ! V_22 )
continue;
V_69 [ V_7 ] = NULL ;
V_2 = F_23 ( V_22 ) ;
if ( V_2 -> V_48 ) {
F_24 ( V_111 L_5 ,
V_22 -> V_64 ) ;
V_22 -> V_72 = NULL ;
}
F_49 ( V_22 ) ;
}
F_57 ( V_69 ) ;
V_69 = NULL ;
V_7 = F_62 ( V_109 ) ;
if ( V_7 )
F_24 ( V_111 L_6 , V_7 ) ;
}
