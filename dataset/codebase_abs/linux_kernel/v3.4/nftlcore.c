static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
if ( V_4 -> type != V_8 || V_4 -> V_9 > V_10 )
return;
if ( memcmp ( V_4 -> V_11 , L_1 , 10 ) )
return;
F_2 ( L_2 , V_4 -> V_11 ) ;
V_6 = F_3 ( sizeof( struct V_5 ) , V_12 ) ;
if ( ! V_6 )
return;
V_6 -> V_13 . V_4 = V_4 ;
V_6 -> V_13 . V_14 = - 1 ;
V_6 -> V_13 . V_2 = V_2 ;
if ( F_4 ( V_6 ) < 0 ) {
F_5 ( V_15 L_3 ) ;
F_6 ( V_6 ) ;
return;
}
V_6 -> V_16 = 1024 ;
V_6 -> V_17 = 16 ;
V_7 = V_6 -> V_16 * V_6 -> V_17 ;
V_6 -> V_18 = V_6 -> V_13 . V_9 / V_7 ;
if ( V_6 -> V_13 . V_9 % V_7 ) {
V_6 -> V_18 ++ ;
V_7 = V_6 -> V_16 * V_6 -> V_18 ;
V_6 -> V_17 = V_6 -> V_13 . V_9 / V_7 ;
if ( V_6 -> V_13 . V_9 % V_7 ) {
V_6 -> V_17 ++ ;
V_7 = V_6 -> V_17 * V_6 -> V_18 ;
V_6 -> V_16 = V_6 -> V_13 . V_9 / V_7 ;
}
}
if ( V_6 -> V_13 . V_9 != V_6 -> V_17 * V_6 -> V_16 * V_6 -> V_18 ) {
F_5 ( V_15 L_4
L_5 , V_6 -> V_13 . V_9 ) ;
F_5 ( V_15 L_6
L_7 ,
V_6 -> V_16 , V_6 -> V_17 , V_6 -> V_18 ,
( long ) V_6 -> V_16 * ( long ) V_6 -> V_17 *
( long ) V_6 -> V_18 ) ;
}
if ( F_7 ( & V_6 -> V_13 ) ) {
F_6 ( V_6 -> V_19 ) ;
F_6 ( V_6 -> V_20 ) ;
F_6 ( V_6 ) ;
return;
}
#ifdef F_8
F_5 ( V_21 L_8 , V_6 -> V_13 . V_14 + 'a' ) ;
#endif
}
static void F_9 ( struct V_22 * V_23 )
{
struct V_5 * V_6 = ( void * ) V_23 ;
F_2 ( L_9 , V_23 -> V_14 ) ;
F_10 ( V_23 ) ;
F_6 ( V_6 -> V_19 ) ;
F_6 ( V_6 -> V_20 ) ;
}
int F_11 ( struct V_3 * V_4 , T_1 V_24 , T_2 V_25 ,
T_2 * V_26 , T_3 * V_27 )
{
T_1 V_28 = V_4 -> V_29 - 1 ;
struct V_30 V_31 ;
int V_32 ;
V_31 . V_33 = V_34 ;
V_31 . V_35 = V_24 & V_28 ;
V_31 . V_36 = V_25 ;
V_31 . V_37 = V_27 ;
V_31 . V_38 = NULL ;
V_32 = F_12 ( V_4 , V_24 & ~ V_28 , & V_31 ) ;
* V_26 = V_31 . V_39 ;
return V_32 ;
}
int F_13 ( struct V_3 * V_4 , T_1 V_24 , T_2 V_25 ,
T_2 * V_26 , T_3 * V_27 )
{
T_1 V_28 = V_4 -> V_29 - 1 ;
struct V_30 V_31 ;
int V_32 ;
V_31 . V_33 = V_34 ;
V_31 . V_35 = V_24 & V_28 ;
V_31 . V_36 = V_25 ;
V_31 . V_37 = V_27 ;
V_31 . V_38 = NULL ;
V_32 = F_14 ( V_4 , V_24 & ~ V_28 , & V_31 ) ;
* V_26 = V_31 . V_39 ;
return V_32 ;
}
static int F_15 ( struct V_3 * V_4 , T_1 V_24 , T_2 V_25 ,
T_2 * V_26 , T_3 * V_27 , T_3 * V_40 )
{
T_1 V_28 = V_4 -> V_29 - 1 ;
struct V_30 V_31 ;
int V_32 ;
V_31 . V_33 = V_34 ;
V_31 . V_35 = V_24 & V_28 ;
V_31 . V_36 = V_4 -> V_41 ;
V_31 . V_37 = V_40 ;
V_31 . V_38 = V_27 ;
V_31 . V_25 = V_25 ;
V_32 = F_14 ( V_4 , V_24 & ~ V_28 , & V_31 ) ;
* V_26 = V_31 . V_26 ;
return V_32 ;
}
static T_4 F_16 ( struct V_5 * V_6 , int V_42 )
{
T_4 V_43 = V_6 -> V_44 ;
int V_45 = V_6 -> V_46 ;
if ( ! V_42 && V_6 -> V_47 < 2 ) {
F_2 ( L_10 ) ;
return V_48 ;
}
do {
if ( V_6 -> V_19 [ V_43 ] == V_49 ) {
V_6 -> V_44 = V_43 ;
V_6 -> V_47 -- ;
return V_43 ;
}
if ( ++ V_43 > V_6 -> V_50 )
V_43 = F_17 ( V_6 -> V_51 . V_52 ) ;
if ( ! V_45 -- ) {
F_5 ( L_11
L_12 , V_6 -> V_44 ,
F_17 ( V_6 -> V_51 . V_52 ) ) ;
return V_48 ;
}
} while ( V_43 != V_6 -> V_44 );
return V_48 ;
}
static T_4 F_18 ( struct V_5 * V_6 , unsigned V_53 , unsigned V_54 )
{
struct V_3 * V_4 = V_6 -> V_13 . V_4 ;
T_4 V_55 [ V_56 ] ;
unsigned char V_57 [ V_56 ] ;
unsigned char V_58 [ V_56 ] ;
unsigned int V_59 ;
int V_60 ;
int V_45 ;
unsigned int V_61 ;
struct V_62 V_40 ;
int V_63 = 1 ;
T_2 V_26 ;
memset ( V_55 , 0xff , sizeof( V_55 ) ) ;
memset ( V_58 , 0 , sizeof( V_58 ) ) ;
V_59 = V_6 -> V_20 [ V_53 ] ;
if ( V_59 == V_48 ) {
F_5 ( V_15 L_13
L_14 , V_53 ) ;
return V_48 ;
}
V_45 = V_64 ;
V_61 = V_48 ;
while ( V_59 <= V_6 -> V_50 ) {
unsigned int V_65 , V_66 ;
V_61 = V_59 ;
for ( V_60 = 0 ; V_60 < V_6 -> V_67 / 512 ; V_60 ++ ) {
F_11 ( V_4 , ( V_59 * V_6 -> V_67 ) +
( V_60 * 512 ) , 16 , & V_26 ,
( char * ) & V_40 ) ;
if ( V_60 == 2 ) {
V_66 = V_40 . V_68 . V_69 . V_70 | V_40 . V_68 . V_69 . V_71 ;
if ( V_66 == V_72 ) {
F_2 ( L_15 , V_59 ) ;
V_63 = 0 ;
} else {
V_63 = 1 ;
}
}
V_65 = V_40 . V_73 . V_74 | V_40 . V_73 . V_75 ;
V_57 [ V_60 ] = V_65 ;
switch( V_65 ) {
case V_76 :
V_58 [ V_60 ] = 1 ;
break;
case V_77 :
if ( ! V_58 [ V_60 ] )
V_55 [ V_60 ] = V_59 ;
else
F_5 ( V_15
L_16
L_17 ,
V_53 , V_60 ) ;
break;
case V_78 :
if ( ! V_58 [ V_60 ] )
V_55 [ V_60 ] = V_48 ;
else
F_5 ( V_15
L_18
L_17 ,
V_53 , V_60 ) ;
break;
case V_79 :
break;
default:
F_5 ( L_19 ,
V_60 , V_59 , V_65 ) ;
}
}
if ( ! V_45 -- ) {
F_5 ( V_15 L_20 ,
V_53 ) ;
return V_48 ;
}
V_59 = V_6 -> V_19 [ V_59 ] ;
}
if ( V_63 ) {
for ( V_60 = 0 ; V_60 < V_6 -> V_67 / 512 ; V_60 ++ ) {
if ( V_57 [ V_60 ] != V_76 &&
V_55 [ V_60 ] != V_48 &&
V_55 [ V_60 ] != V_61 ) {
F_2 ( L_21
L_22
L_23 ,
V_53 , V_60 , V_57 [ V_60 ] ,
V_55 [ V_60 ] ,
V_55 [ V_60 ] == V_61 ? L_24 : L_25 ,
V_61 ) ;
V_63 = 0 ;
break;
}
}
if ( V_54 >= ( V_53 * ( V_6 -> V_67 / 512 ) ) &&
V_54 < ( ( V_53 + 1 ) * ( V_6 -> V_67 / 512 ) ) &&
V_57 [ V_54 - ( V_53 * ( V_6 -> V_67 / 512 ) ) ] !=
V_76 ) {
F_2 ( L_26
L_27 , V_61 ) ;
V_63 = 0 ;
}
}
if ( ! V_63 ) {
F_2 ( L_28
L_29 , V_53 ) ;
V_61 = F_16 ( V_6 , 1 ) ;
if ( V_61 == V_48 ) {
F_5 ( V_15
L_30 ) ;
return V_48 ;
}
} else {
V_40 . V_68 . V_69 . V_70 = V_40 . V_68 . V_69 . V_71 = F_19 ( V_72 ) ;
V_40 . V_68 . V_69 . V_80 = 0xffffffff ;
F_13 ( V_4 , ( V_6 -> V_67 * V_61 ) + 2 * 512 + 8 ,
8 , & V_26 , ( char * ) & V_40 . V_68 ) ;
}
F_2 ( L_31 , V_53 , V_61 ) ;
for ( V_60 = 0 ; V_60 < V_6 -> V_67 / 512 ; V_60 ++ ) {
unsigned char V_81 [ 512 ] ;
int V_82 ;
if ( V_55 [ V_60 ] == V_61 ||
( V_54 == ( V_53 * ( V_6 -> V_67 / 512 ) + V_60 ) ) ) {
continue;
}
if ( V_55 [ V_60 ] == V_48 )
continue;
V_82 = F_20 ( V_4 ,
( V_6 -> V_67 * V_55 [ V_60 ] ) + ( V_60 * 512 ) ,
512 ,
& V_26 ,
V_81 ) ;
if ( V_82 < 0 && ! F_21 ( V_82 ) ) {
V_82 = F_20 ( V_4 ,
( V_6 -> V_67 * V_55 [ V_60 ] ) + ( V_60 * 512 ) ,
512 ,
& V_26 ,
V_81 ) ;
if ( V_82 != - V_83 )
F_5 ( L_32 ) ;
}
memset ( & V_40 , 0xff , sizeof( struct V_62 ) ) ;
V_40 . V_73 . V_74 = V_40 . V_73 . V_75 = V_77 ;
F_15 ( V_6 -> V_13 . V_4 , ( V_6 -> V_67 * V_61 ) +
( V_60 * 512 ) , 512 , & V_26 , V_81 , ( char * ) & V_40 ) ;
}
V_40 . V_68 . V_84 . V_85 = V_40 . V_68 . V_84 . V_86 = F_19 ( V_53 ) ;
V_40 . V_68 . V_84 . V_87 = V_40 . V_68 . V_84 . V_88 = V_48 ;
F_13 ( V_4 , ( V_6 -> V_67 * V_61 ) + 8 ,
8 , & V_26 , ( char * ) & V_40 . V_68 ) ;
V_59 = V_6 -> V_20 [ V_53 ] ;
F_2 ( L_33 ) ;
while ( V_59 <= V_6 -> V_50 && V_59 != V_61 ) {
unsigned int V_89 ;
V_89 = V_6 -> V_19 [ V_59 ] ;
if ( F_22 ( V_6 , V_59 ) < 0 ) {
V_6 -> V_19 [ V_59 ] = V_90 ;
} else {
V_6 -> V_19 [ V_59 ] = V_49 ;
V_6 -> V_47 ++ ;
}
V_59 = V_89 ;
}
V_6 -> V_19 [ V_61 ] = V_48 ;
V_6 -> V_20 [ V_53 ] = V_61 ;
return V_61 ;
}
static T_4 F_23 ( struct V_5 * V_6 , unsigned V_54 )
{
T_4 V_91 = 0 ;
T_4 V_92 = 0 , V_93 ;
T_4 V_94 , V_95 ;
for ( V_94 = 0 ; V_94 < F_24 ( V_6 -> V_51 . V_96 ) / V_6 -> V_67 ; V_94 ++ ) {
V_95 = V_6 -> V_20 [ V_94 ] ;
V_93 = 0 ;
while ( V_95 <= V_6 -> V_50 ) {
V_93 ++ ;
V_95 = V_6 -> V_19 [ V_95 ] & 0x7fff ;
if ( V_93 > 0xff00 ) {
F_5 ( L_34 ,
V_94 , V_95 ) ;
}
if ( V_93 > 0xff10 ) {
V_93 = 0 ;
break;
}
}
if ( V_93 > V_92 ) {
V_92 = V_93 ;
V_91 = V_94 ;
}
}
if ( V_92 < 2 ) {
F_5 ( V_15 L_35
L_36 ) ;
return V_48 ;
}
return F_18 ( V_6 , V_91 , V_54 ) ;
}
static inline T_4 F_25 ( struct V_5 * V_6 , unsigned V_60 )
{
T_4 V_50 ;
T_4 V_53 = V_60 / ( V_6 -> V_67 / 512 ) ;
struct V_3 * V_4 = V_6 -> V_13 . V_4 ;
unsigned int V_97 ;
unsigned long V_98 = ( V_60 * 512 ) & ( V_6 -> V_67 - 1 ) ;
T_2 V_26 ;
int V_45 , V_99 = 3 ;
struct V_62 V_40 ;
do {
V_50 = V_48 ;
V_97 = V_6 -> V_20 [ V_53 ] ;
V_45 = V_64 ;
while ( V_97 <= V_6 -> V_50 ) {
struct V_100 V_101 ;
T_2 V_26 ;
unsigned int V_65 ;
V_50 = V_97 ;
F_11 ( V_4 ,
( V_97 * V_6 -> V_67 ) + V_98 ,
8 , & V_26 , ( char * ) & V_101 ) ;
F_2 ( L_37 ,
V_60 , V_97 , F_17 ( V_101 . V_74 ) ) ;
V_65 = V_101 . V_74 | V_101 . V_75 ;
switch( V_65 ) {
case V_76 :
return V_97 ;
case V_78 :
case V_77 :
case V_79 :
break;
default:
break;
}
if ( ! V_45 -- ) {
F_5 ( V_15
L_20 ,
V_53 ) ;
return V_48 ;
}
V_97 = V_6 -> V_19 [ V_97 ] ;
}
V_97 = F_16 ( V_6 , 0 ) ;
if ( V_97 == V_48 ) {
V_97 = F_23 ( V_6 , V_48 ) ;
if ( V_97 == V_48 ) {
F_2 ( L_38 , V_53 ) ;
V_97 = F_16 ( V_6 , 1 ) ;
}
if ( V_97 == V_48 ) {
F_5 ( V_15 L_39 ) ;
return V_48 ;
}
V_50 = V_48 ;
continue;
}
if ( V_50 != V_48 ) {
V_53 |= 0x8000 ;
} else {
V_6 -> V_20 [ V_53 ] = V_97 ;
}
V_6 -> V_19 [ V_97 ] = V_48 ;
F_11 ( V_4 , V_97 * V_6 -> V_67 + 8 , 8 ,
& V_26 , ( char * ) & V_40 . V_68 ) ;
V_40 . V_68 . V_84 . V_85 = V_40 . V_68 . V_84 . V_86 = F_19 ( V_53 ) ;
F_13 ( V_4 , V_97 * V_6 -> V_67 + 8 , 8 ,
& V_26 , ( char * ) & V_40 . V_68 ) ;
if ( V_50 != V_48 ) {
V_6 -> V_19 [ V_50 ] = V_97 ;
F_11 ( V_4 , ( V_50 * V_6 -> V_67 ) + 8 ,
8 , & V_26 , ( char * ) & V_40 . V_68 ) ;
V_40 . V_68 . V_84 . V_87 = V_40 . V_68 . V_84 . V_88
= F_19 ( V_97 ) ;
F_13 ( V_4 , ( V_50 * V_6 -> V_67 ) + 8 ,
8 , & V_26 , ( char * ) & V_40 . V_68 ) ;
}
return V_97 ;
} while ( V_99 -- );
F_5 ( V_15 L_40 ,
V_53 ) ;
return V_48 ;
}
static int F_26 ( struct V_22 * V_13 , unsigned long V_60 ,
char * V_102 )
{
struct V_5 * V_6 = ( void * ) V_13 ;
T_4 V_97 ;
unsigned long V_98 = ( V_60 * 512 ) & ( V_6 -> V_67 - 1 ) ;
T_2 V_26 ;
struct V_62 V_40 ;
V_97 = F_25 ( V_6 , V_60 ) ;
if ( V_97 == V_48 ) {
F_5 ( V_15
L_41 ) ;
return 1 ;
}
memset ( & V_40 , 0xff , sizeof( struct V_62 ) ) ;
V_40 . V_73 . V_74 = V_40 . V_73 . V_75 = V_77 ;
F_15 ( V_6 -> V_13 . V_4 , ( V_97 * V_6 -> V_67 ) + V_98 ,
512 , & V_26 , ( char * ) V_102 , ( char * ) & V_40 ) ;
return 0 ;
}
static int F_27 ( struct V_22 * V_13 , unsigned long V_60 ,
char * V_102 )
{
struct V_5 * V_6 = ( void * ) V_13 ;
struct V_3 * V_4 = V_6 -> V_13 . V_4 ;
T_4 V_103 ;
T_4 V_59 = V_6 -> V_20 [ V_60 / ( V_6 -> V_67 / 512 ) ] ;
unsigned long V_98 = ( V_60 * 512 ) & ( V_6 -> V_67 - 1 ) ;
unsigned int V_65 ;
int V_45 = V_64 ;
T_2 V_26 ;
struct V_100 V_101 ;
V_103 = V_48 ;
if ( V_59 != V_48 ) {
while ( V_59 < V_6 -> V_46 ) {
if ( F_11 ( V_4 , ( V_59 * V_6 -> V_67 ) +
V_98 , 8 , & V_26 ,
( char * ) & V_101 ) < 0 )
V_65 = V_79 ;
else
V_65 = V_101 . V_74 | V_101 . V_75 ;
switch ( V_65 ) {
case V_76 :
goto V_104;
case V_78 :
V_103 = V_48 ;
break;
case V_77 :
V_103 = V_59 ;
break;
case V_79 :
break;
default:
F_5 ( L_42 ,
V_60 , V_59 , V_65 ) ;
break;
}
if ( ! V_45 -- ) {
F_5 ( V_15 L_43 ,
V_60 / ( V_6 -> V_67 / 512 ) ) ;
return 1 ;
}
V_59 = V_6 -> V_19 [ V_59 ] ;
}
}
V_104:
if ( V_103 == V_48 ) {
memset ( V_102 , 0 , 512 ) ;
} else {
T_1 V_105 = ( V_103 * V_6 -> V_67 ) + V_98 ;
T_2 V_26 ;
int V_32 = F_20 ( V_4 , V_105 , 512 , & V_26 , V_102 ) ;
if ( V_32 < 0 && ! F_21 ( V_32 ) )
return - V_83 ;
}
return 0 ;
}
static int F_28 ( struct V_22 * V_23 , struct V_106 * V_107 )
{
struct V_5 * V_6 = ( void * ) V_23 ;
V_107 -> V_17 = V_6 -> V_17 ;
V_107 -> V_18 = V_6 -> V_18 ;
V_107 -> V_16 = V_6 -> V_16 ;
return 0 ;
}
static int T_5 F_29 ( void )
{
return F_30 ( & V_108 ) ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_108 ) ;
}
