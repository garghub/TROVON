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
F_5 ( L_2 ) ;
return;
}
#ifdef F_2
V_1 = F_6 ( & V_10 ) ;
if ( V_1 == V_12 ) {
V_13 = V_15 ;
F_5 ( L_3 ) ;
V_16 = V_10 . V_17 ;
V_18 = V_10 . V_19 ;
F_7 ( L_4 ,
V_16 , V_18 ) ;
return;
}
#endif
V_1 = F_8 ( & V_8 ) ;
V_2 = ( V_8 . V_20 >> ( 4 + 7 ) ) & 0x1f ;
switch ( V_2 ) {
case 0x4 :
case 0x6 :
case 0x7 :
case 0x8 :
case 0xA :
case 0xC :
V_13 = V_21 ;
F_5 ( L_5 ) ;
return;
default:
F_5 ( L_6 ) ;
F_9 ( L_7 ) ;
}
}
static void T_1
F_10 ( T_2 * V_22 , unsigned long V_23 ,
unsigned long V_24 )
{
if ( F_11 ( ( ( V_23 & ( V_25 - 1 ) ) != 0 )
|| ( ( V_24 & ( ( 1UL << V_26 ) - 1 ) ) != 0 ) ) ) {
F_9 ( L_8 ) ;
}
V_22 -> V_27 = ( V_23 >> V_28 ) ;
V_22 -> V_29 = ( V_24 >> V_26 ) ;
}
static void T_1 F_12 ( void )
{
unsigned long V_30 ;
V_30 = ( F_13 ( V_31 -> V_32 ) >> V_28 ) ;
F_10 ( V_33 , 0UL , V_30 ) ;
V_34 = 1 ;
}
static int T_1
F_14 ( T_3 V_35 , T_3 V_36 )
{
T_4 * V_37 ;
unsigned long V_38 ;
unsigned long V_39 ;
long V_1 ;
struct V_40 * V_41 ;
V_37 = F_15 ( sizeof ( * V_37 ) , V_42 ) ;
if ( ! V_37 )
F_9 ( L_9 ) ;
V_1 = F_16 ( & V_38 , V_35 , V_36 ,
V_43 , V_37 ) ;
if ( V_1 != V_12 ) {
F_17 ( V_37 ) ;
return V_1 ;
}
V_39 = V_37 -> V_44 ;
V_41 = F_18 ( F_19 ( V_39 ) , & ( V_37 -> V_45 ) ) ;
if ( ! V_41 ) {
F_17 ( V_37 ) ;
return V_12 ;
}
V_41 -> V_35 = V_35 ;
V_41 -> V_36 = V_36 ;
V_41 -> V_46 = V_37 -> V_46 ;
V_41 -> V_47 = V_37 -> V_48 ;
V_41 -> V_49 = V_37 -> V_50 [ 0 ] ;
F_20 ( V_41 ) ;
#ifdef F_21
switch ( F_22 ( V_41 -> V_46 ) ) {
T_4 V_51 ;
unsigned long V_52 ;
case V_53 :
F_3 ( V_54 L_10 ,
V_37 -> V_50 [ 0 ] ) ;
break;
case V_55 :
F_3 ( V_54
L_11 ,
V_37 -> V_50 [ 0 ] , V_37 -> V_50 [ 1 ] ,
V_37 -> V_50 [ 2 ] ) ;
break;
case V_56 :
F_3 ( V_54 L_12 , V_35 ) ;
break;
case V_57 :
F_3 ( V_54 L_13 ) ;
goto V_58;
case V_59 :
F_3 ( V_54 L_14 ) ;
goto V_58;
case V_60 :
F_3 ( V_54 L_15 ) ;
V_58:
F_16 ( & V_38 , V_35 , V_36 ,
V_61 , & V_51 ) ;
F_3 ( V_54 L_16 , V_37 -> V_50 [ 1 ] ) ;
for ( V_52 = 0 ; V_52 < V_37 -> V_50 [ 1 ] ; V_52 ++ ) {
F_3 ( V_54
L_17 ,
V_52 , V_37 -> V_50 [ 2 + V_52 * 3 ] ,
V_37 -> V_50 [ 3 + V_52 * 3 ] ,
V_37 -> V_50 [ 4 + V_52 * 3 ] ) ;
F_3 ( V_54
L_18 ,
V_52 , V_51 . V_50 [ 2 + V_52 * 3 ] ,
V_51 . V_50 [ 3 + V_52 * 3 ] ,
V_51 . V_50 [ 4 + V_52 * 3 ] ) ;
}
F_3 ( V_54 L_19 ) ;
break;
}
#endif
F_17 ( V_37 ) ;
return V_12 ;
}
static void T_1 F_23 ( void )
{
unsigned long V_62 ;
struct V_63 V_64 [ V_65 + 1 ] ;
struct V_63 * V_66 ;
T_2 * V_22 ;
long V_1 ;
int V_67 ;
unsigned long V_68 ;
int V_52 ;
V_68 = ( V_65 + 1 ) * sizeof( struct V_63 ) ;
V_1 = F_24 ( & V_62 , V_64 , V_68 , 0L ) ;
if ( ( V_1 != V_12 )
|| ( ( V_62 % sizeof( struct V_63 ) ) != 0 ) ) {
F_3 ( L_20 ) ;
F_3 ( V_69 L_21
L_22 ) ;
F_12 () ;
return;
}
V_67 = V_62 / sizeof( struct V_63 ) ;
if ( V_67 > V_65 ) {
F_3 ( V_69 L_23 ) ;
F_3 ( V_69 L_24 ) ;
}
V_34 = 0 ;
V_66 = V_64 ;
V_22 = V_33 ;
for ( V_52 = 0 ; V_52 < V_67 ; V_52 ++ , V_66 ++ ) {
if ( ( V_66 -> V_70 != V_71 )
|| ( V_66 -> V_72 != V_73 )
|| ( V_66 -> V_29 == 0 )
|| ( ( V_66 -> V_74 != V_75 )
&& ( V_66 -> V_74 != V_76 )
&& ( V_66 -> V_74 != V_77 ) ) ) {
continue;
}
if ( V_34 == V_78 ) {
F_3 ( V_69 L_23 ) ;
F_3 ( V_69 L_25 ) ;
break;
}
F_10 ( V_22 ++ , V_66 -> V_79 , V_66 -> V_29 ) ;
V_34 ++ ;
}
}
static int T_1 F_25 ( void )
{
int V_1 ;
T_3 V_36 = 0 ;
struct V_9 V_10 ;
V_1 = F_6 ( & V_10 ) ;
if ( V_1 != V_12 ) {
return 0 ;
}
#ifdef F_21
F_3 ( V_54 L_26 , V_10 . V_17 ,
V_10 . V_19 ) ;
#endif
while ( V_12 == F_14 ( V_10 . V_19 , V_36 ) ) {
V_36 ++ ;
}
return V_36 ;
}
static void T_1 F_26 ( void )
{
struct V_80 V_81 ;
struct V_82 V_64 [ V_78 ] ;
struct V_82 * V_66 ;
T_2 * V_22 ;
long V_1 ;
int V_67 ;
int V_52 ;
V_1 = F_27 ( & V_81 , V_64 ,
( unsigned long ) V_78 ) ;
if ( V_1 != V_12 ) {
F_12 () ;
return;
}
if ( V_81 . V_83 > V_78 ) {
F_3 ( V_69 L_23 ) ;
F_3 ( V_69 L_25 ) ;
}
V_67 = ( int ) V_81 . V_84 ;
V_34 = 0 ;
V_66 = V_64 ;
V_22 = V_33 ;
for ( V_52 = 0 ; V_52 < V_67 ; V_52 ++ , V_66 ++ ) {
F_10 ( V_22 ++ , V_66 -> V_79 , V_66 -> V_29 ) ;
V_34 ++ ;
}
}
static struct V_40 * T_1
F_28 ( struct V_85 * V_81 ,
struct V_5 * V_6 )
{
struct V_40 * V_41 ;
int V_1 = F_29 ( V_81 , V_6 ) ;
if ( V_1 != V_12 )
return NULL ;
V_41 = F_18 ( V_81 -> V_86 , & V_6 -> V_87 ) ;
if ( V_41 == NULL )
return NULL ;
F_20 ( V_41 ) ;
return V_41 ;
}
static void T_1 F_30 ( void )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < 16 ; V_50 ++ ) {
struct V_40 * V_41 ;
struct V_5 V_6 ;
struct V_85 V_81 ;
unsigned int V_88 ;
memset ( V_6 . V_87 . V_89 , 0xff , 6 ) ;
V_6 . V_87 . V_50 = V_50 ;
V_41 = F_28 ( & V_81 , & V_6 ) ;
if ( ( ! V_41 ) || ( V_41 -> V_90 . V_91 != V_92 ) )
continue;
memset ( V_6 . V_87 . V_89 , 0xff , 4 ) ;
V_6 . V_87 . V_89 [ 4 ] = V_50 ;
for ( V_88 = 0 ; V_88 < 16 ; V_88 ++ ) {
V_6 . V_87 . V_89 [ 5 ] = 0 ;
V_6 . V_87 . V_50 = V_88 ;
F_28 ( & V_81 , & V_6 ) ;
}
}
}
static void T_1
F_31 ( struct V_40 * V_41 , int V_93 ,
int V_94 )
{
int V_52 ;
long V_1 ;
struct V_95 V_96 ;
V_41 -> V_97 = F_32 ( V_93 , sizeof( * V_41 -> V_97 ) , V_42 ) ;
if( ! V_41 -> V_97 ) {
F_3 ( V_98 L_27 ,
__FILE__ , V_99 ) ;
return;
}
for( V_52 = 1 ; V_52 <= V_93 ; ++ V_52 ) {
V_1 = F_33 ( & V_96 ,
V_94 , V_52 ) ;
if( V_12 == V_1 ) {
V_41 -> V_97 [ V_41 -> V_93 ] = ( unsigned long ) V_96 . V_100 ;
V_41 -> V_93 ++ ;
} else {
F_3 ( V_69
L_28 ,
V_1 , V_52 ) ;
}
}
}
static void T_1 F_34 ( void )
{
int V_52 ;
long V_1 = V_12 ;
for ( V_52 = 0 ; V_52 < 256 ; V_52 ++ ) {
struct V_40 * V_41 ;
struct V_3 V_4 ;
struct V_5 V_6 ;
V_1 = F_4 ( & V_4 ,
& V_6 , V_52 ) ;
if ( ( V_1 == V_101 ) || ( V_1 == V_102 ) )
break;
if ( V_1 != V_12 )
continue;
V_41 = F_18 ( V_4 . V_100 , & V_6 . V_87 ) ;
if ( ! V_41 )
continue;
F_20 ( V_41 ) ;
if ( ! V_4 . V_103 )
continue;
F_31 ( V_41 , V_4 . V_103 , V_52 ) ;
}
F_35 () ;
return;
}
void T_1 F_36 ( void )
{
switch ( V_13 ) {
case V_15 :
F_23 () ;
break;
case V_14 :
F_26 () ;
break;
case V_21 :
F_12 () ;
return;
default:
F_9 ( L_29 ) ;
}
if ( V_34 == 0 || V_33 [ 0 ] . V_27 != 0 ) {
F_3 ( V_69 L_30 ) ;
F_3 ( V_69 L_24 ) ;
F_12 () ;
}
}
void T_1 F_37 ( void )
{
F_3 ( V_11 L_31 ) ;
F_38 () ;
switch ( V_13 ) {
case V_15 :
F_25 () ;
break;
case V_14 :
F_34 () ;
break;
case V_21 :
F_30 () ;
break;
default:
F_9 ( L_29 ) ;
}
F_3 ( V_11 L_32 ) ;
F_39 () ;
}
