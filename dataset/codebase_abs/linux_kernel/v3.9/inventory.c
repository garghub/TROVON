void T_1 F_1 ( void )
{
long V_1 ;
unsigned int V_2 ;
struct V_3 V_4 ;
struct V_5 V_6 ;
struct V_7 V_8 ;
#ifdef F_2
struct V_9 V_10 ;
#endif
F_3 ( V_11 L_1 ) ;
V_1 = F_4 ( & V_4 , & V_6 , 0 ) ;
if ( V_1 == V_12 ) {
V_13 = V_14 ;
F_3 ( L_2 ) ;
return;
}
#ifdef F_2
V_1 = F_5 ( & V_10 ) ;
if ( V_1 == V_12 ) {
V_13 = V_15 ;
F_3 ( L_3 ) ;
return;
}
#endif
V_1 = F_6 ( & V_8 ) ;
V_2 = ( V_8 . V_16 >> ( 4 + 7 ) ) & 0x1f ;
switch ( V_2 ) {
case 0x4 :
case 0x6 :
case 0x7 :
case 0x8 :
case 0xA :
case 0xC :
V_13 = V_17 ;
F_3 ( L_4 ) ;
return;
default:
F_3 ( L_5 ) ;
F_7 ( L_6 ) ;
}
}
static void T_1
F_8 ( T_2 * V_18 , unsigned long V_19 ,
unsigned long V_20 )
{
if ( F_9 ( ( ( V_19 & ( V_21 - 1 ) ) != 0 )
|| ( ( V_20 & ( ( 1UL << V_22 ) - 1 ) ) != 0 ) ) ) {
F_7 ( L_7 ) ;
}
V_18 -> V_23 = ( V_19 >> V_24 ) ;
V_18 -> V_25 = ( V_20 >> V_22 ) ;
}
static void T_1 F_10 ( void )
{
unsigned long V_26 ;
V_26 = ( F_11 ( V_27 -> V_28 ) >> V_24 ) ;
F_8 ( V_29 , 0UL , V_26 ) ;
V_30 = 1 ;
}
static int T_1
F_12 ( T_3 V_31 , T_3 V_32 )
{
T_4 * V_33 ;
unsigned long V_34 ;
unsigned long V_35 ;
long V_1 ;
struct V_36 * V_37 ;
V_33 = F_13 ( sizeof ( * V_33 ) , V_38 ) ;
if ( ! V_33 )
F_7 ( L_8 ) ;
V_1 = F_14 ( & V_34 , V_31 , V_32 ,
V_39 , V_33 ) ;
if ( V_1 != V_12 ) {
F_15 ( V_33 ) ;
return V_1 ;
}
V_35 = V_33 -> V_40 ;
V_37 = F_16 ( F_17 ( V_35 ) , & ( V_33 -> V_41 ) ) ;
if ( ! V_37 ) {
F_15 ( V_33 ) ;
return V_12 ;
}
V_37 -> V_31 = V_31 ;
V_37 -> V_32 = V_32 ;
V_37 -> V_42 = V_33 -> V_42 ;
V_37 -> V_43 = V_33 -> V_44 ;
F_18 ( V_37 ) ;
#ifdef F_19
T_4 V_45 ;
switch ( F_20 ( V_37 -> V_42 ) ) {
unsigned long V_46 ;
case V_47 :
F_3 ( V_48 L_9 ,
V_33 -> V_49 [ 0 ] ) ;
break;
case V_50 :
F_3 ( V_48
L_10 ,
V_33 -> V_49 [ 0 ] , V_33 -> V_49 [ 1 ] ,
V_33 -> V_49 [ 2 ] ) ;
break;
case V_51 :
F_3 ( V_48 L_11 , V_31 ) ;
break;
case V_52 :
F_3 ( V_48 L_12 ) ;
goto V_53;
case V_54 :
F_3 ( V_48 L_13 ) ;
goto V_53;
case V_55 :
F_3 ( V_48 L_14 ) ;
V_53:
F_14 ( & V_34 , V_31 , V_32 ,
V_56 , & V_45 ) ;
F_3 ( V_48 L_15 , V_33 -> V_49 [ 1 ] ) ;
for ( V_46 = 0 ; V_46 < V_33 -> V_49 [ 1 ] ; V_46 ++ ) {
F_3 ( V_48
L_16 ,
V_46 , V_33 -> V_49 [ 2 + V_46 * 3 ] ,
V_33 -> V_49 [ 3 + V_46 * 3 ] ,
V_33 -> V_49 [ 4 + V_46 * 3 ] ) ;
F_3 ( V_48
L_17 ,
V_46 , V_45 -> V_49 [ 2 + V_46 * 3 ] ,
V_45 -> V_49 [ 3 + V_46 * 3 ] ,
V_45 -> V_49 [ 4 + V_46 * 3 ] ) ;
}
F_3 ( V_48 L_18 ) ;
break;
}
#endif
F_15 ( V_33 ) ;
return V_12 ;
}
static void T_1 F_21 ( void )
{
unsigned long V_57 ;
struct V_58 V_59 [ V_60 + 1 ] ;
struct V_58 * V_61 ;
T_2 * V_18 ;
long V_1 ;
int V_62 ;
unsigned long V_63 ;
int V_46 ;
V_63 = ( V_60 + 1 ) * sizeof( struct V_58 ) ;
V_1 = F_22 ( & V_57 , V_59 , V_63 , 0L ) ;
if ( ( V_1 != V_12 )
|| ( ( V_57 % sizeof( struct V_58 ) ) != 0 ) ) {
F_3 ( L_19 ) ;
F_3 ( V_64 L_20
L_21 ) ;
F_10 () ;
return;
}
V_62 = V_57 / sizeof( struct V_58 ) ;
if ( V_62 > V_60 ) {
F_3 ( V_64 L_22 ) ;
F_3 ( V_64 L_23 ) ;
}
V_30 = 0 ;
V_61 = V_59 ;
V_18 = V_29 ;
for ( V_46 = 0 ; V_46 < V_62 ; V_46 ++ , V_61 ++ ) {
if ( ( V_61 -> V_65 != V_66 )
|| ( V_61 -> V_67 != V_68 )
|| ( V_61 -> V_25 == 0 )
|| ( ( V_61 -> V_69 != V_70 )
&& ( V_61 -> V_69 != V_71 )
&& ( V_61 -> V_69 != V_72 ) ) ) {
continue;
}
if ( V_30 == V_73 ) {
F_3 ( V_64 L_22 ) ;
F_3 ( V_64 L_24 ) ;
break;
}
F_8 ( V_18 ++ , V_61 -> V_74 , V_61 -> V_25 ) ;
V_30 ++ ;
}
}
static int T_1 F_23 ( void )
{
int V_1 ;
T_3 V_32 = 0 ;
struct V_9 V_10 ;
V_1 = F_5 ( & V_10 ) ;
if ( V_1 != V_12 ) {
return 0 ;
}
#ifdef F_19
F_3 ( V_48 L_25 , V_10 . V_75 ,
V_10 . V_76 ) ;
#endif
while ( V_12 == F_12 ( V_10 . V_76 , V_32 ) ) {
V_32 ++ ;
}
return V_32 ;
}
static void T_1 F_24 ( void )
{
struct V_77 V_78 ;
struct V_79 V_59 [ V_73 ] ;
struct V_79 * V_61 ;
T_2 * V_18 ;
long V_1 ;
int V_62 ;
int V_46 ;
V_1 = F_25 ( & V_78 , V_59 ,
( unsigned long ) V_73 ) ;
if ( V_1 != V_12 ) {
F_10 () ;
return;
}
if ( V_78 . V_80 > V_73 ) {
F_3 ( V_64 L_22 ) ;
F_3 ( V_64 L_24 ) ;
}
V_62 = ( int ) V_78 . V_81 ;
V_30 = 0 ;
V_61 = V_59 ;
V_18 = V_29 ;
for ( V_46 = 0 ; V_46 < V_62 ; V_46 ++ , V_61 ++ ) {
F_8 ( V_18 ++ , V_61 -> V_74 , V_61 -> V_25 ) ;
V_30 ++ ;
}
}
static struct V_36 * T_1
F_26 ( struct V_82 * V_78 ,
struct V_5 * V_6 )
{
struct V_36 * V_37 ;
int V_1 = F_27 ( V_78 , V_6 ) ;
if ( V_1 != V_12 )
return NULL ;
V_37 = F_16 ( V_78 -> V_83 , & V_6 -> V_84 ) ;
if ( V_37 == NULL )
return NULL ;
F_18 ( V_37 ) ;
return V_37 ;
}
static void T_1 F_28 ( void )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ ) {
struct V_36 * V_37 ;
struct V_5 V_6 ;
struct V_82 V_78 ;
unsigned int V_85 ;
memset ( V_6 . V_84 . V_86 , 0xff , 6 ) ;
V_6 . V_84 . V_49 = V_49 ;
V_37 = F_26 ( & V_78 , & V_6 ) ;
if ( ( ! V_37 ) || ( V_37 -> V_87 . V_88 != V_89 ) )
continue;
memset ( V_6 . V_84 . V_86 , 0xff , 4 ) ;
V_6 . V_84 . V_86 [ 4 ] = V_49 ;
for ( V_85 = 0 ; V_85 < 16 ; V_85 ++ ) {
V_6 . V_84 . V_86 [ 5 ] = 0 ;
V_6 . V_84 . V_49 = V_85 ;
F_26 ( & V_78 , & V_6 ) ;
}
}
}
static void T_1
F_29 ( struct V_36 * V_37 , int V_90 ,
int V_91 )
{
int V_46 ;
long V_1 ;
struct V_92 V_93 ;
V_37 -> V_94 = F_13 ( V_90 * sizeof( unsigned long ) , V_38 ) ;
if( ! V_37 -> V_94 ) {
F_3 ( V_95 L_26 ,
__FILE__ , V_96 ) ;
return;
}
for( V_46 = 1 ; V_46 <= V_90 ; ++ V_46 ) {
V_1 = F_30 ( & V_93 ,
V_91 , V_46 ) ;
if( V_12 == V_1 ) {
V_37 -> V_94 [ V_37 -> V_90 ] = ( unsigned long ) V_93 . V_97 ;
V_37 -> V_90 ++ ;
} else {
F_3 ( V_64
L_27 ,
V_1 , V_46 ) ;
}
}
}
static void T_1 F_31 ( void )
{
int V_46 ;
long V_1 = V_12 ;
for ( V_46 = 0 ; V_46 < 256 ; V_46 ++ ) {
struct V_36 * V_37 ;
struct V_3 V_4 ;
struct V_5 V_6 ;
V_1 = F_4 ( & V_4 ,
& V_6 , V_46 ) ;
if ( ( V_1 == V_98 ) || ( V_1 == V_99 ) )
break;
if ( V_1 != V_12 )
continue;
V_37 = F_16 ( V_4 . V_97 , & V_6 . V_84 ) ;
if ( ! V_37 )
continue;
F_18 ( V_37 ) ;
if ( ! V_4 . V_100 )
continue;
F_29 ( V_37 , V_4 . V_100 , V_46 ) ;
}
F_32 () ;
return;
}
void T_1 F_33 ( void )
{
switch ( V_13 ) {
case V_15 :
F_21 () ;
break;
case V_14 :
F_24 () ;
break;
case V_17 :
F_10 () ;
return;
default:
F_7 ( L_28 ) ;
}
if ( V_30 == 0 || V_29 [ 0 ] . V_23 != 0 ) {
F_3 ( V_64 L_29 ) ;
F_3 ( V_64 L_23 ) ;
F_10 () ;
}
}
void T_1 F_34 ( void )
{
F_3 ( V_11 L_30 ) ;
F_35 () ;
switch ( V_13 ) {
case V_15 :
F_23 () ;
break;
case V_14 :
F_31 () ;
break;
case V_17 :
F_28 () ;
break;
default:
F_7 ( L_28 ) ;
}
F_3 ( V_11 L_31 ) ;
F_36 () ;
}
