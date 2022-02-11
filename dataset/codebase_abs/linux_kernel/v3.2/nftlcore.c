static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
if ( V_4 -> type != V_8 || V_4 -> V_9 > V_10 )
return;
if ( memcmp ( V_4 -> V_11 , L_1 , 10 ) )
return;
if ( ! V_4 -> V_12 ) {
F_2 ( V_13
L_2
L_3 ) ;
return;
}
F_3 ( L_4 , V_4 -> V_11 ) ;
V_6 = F_4 ( sizeof( struct V_5 ) , V_14 ) ;
if ( ! V_6 )
return;
V_6 -> V_15 . V_4 = V_4 ;
V_6 -> V_15 . V_16 = - 1 ;
V_6 -> V_15 . V_2 = V_2 ;
if ( F_5 ( V_6 ) < 0 ) {
F_2 ( V_17 L_5 ) ;
F_6 ( V_6 ) ;
return;
}
V_6 -> V_18 = 1024 ;
V_6 -> V_19 = 16 ;
V_7 = V_6 -> V_18 * V_6 -> V_19 ;
V_6 -> V_20 = V_6 -> V_15 . V_9 / V_7 ;
if ( V_6 -> V_15 . V_9 % V_7 ) {
V_6 -> V_20 ++ ;
V_7 = V_6 -> V_18 * V_6 -> V_20 ;
V_6 -> V_19 = V_6 -> V_15 . V_9 / V_7 ;
if ( V_6 -> V_15 . V_9 % V_7 ) {
V_6 -> V_19 ++ ;
V_7 = V_6 -> V_19 * V_6 -> V_20 ;
V_6 -> V_18 = V_6 -> V_15 . V_9 / V_7 ;
}
}
if ( V_6 -> V_15 . V_9 != V_6 -> V_19 * V_6 -> V_18 * V_6 -> V_20 ) {
F_2 ( V_17 L_6
L_7 , V_6 -> V_15 . V_9 ) ;
F_2 ( V_17 L_8
L_9 ,
V_6 -> V_18 , V_6 -> V_19 , V_6 -> V_20 ,
( long ) V_6 -> V_18 * ( long ) V_6 -> V_19 *
( long ) V_6 -> V_20 ) ;
}
if ( F_7 ( & V_6 -> V_15 ) ) {
F_6 ( V_6 -> V_21 ) ;
F_6 ( V_6 -> V_22 ) ;
F_6 ( V_6 ) ;
return;
}
#ifdef F_8
F_2 ( V_23 L_10 , V_6 -> V_15 . V_16 + 'a' ) ;
#endif
}
static void F_9 ( struct V_24 * V_25 )
{
struct V_5 * V_6 = ( void * ) V_25 ;
F_3 ( L_11 , V_25 -> V_16 ) ;
F_10 ( V_25 ) ;
F_6 ( V_6 -> V_21 ) ;
F_6 ( V_6 -> V_22 ) ;
}
int F_11 ( struct V_3 * V_4 , T_1 V_26 , T_2 V_27 ,
T_2 * V_28 , T_3 * V_29 )
{
T_1 V_30 = V_4 -> V_31 - 1 ;
struct V_32 V_33 ;
int V_34 ;
V_33 . V_35 = V_36 ;
V_33 . V_37 = V_26 & V_30 ;
V_33 . V_38 = V_27 ;
V_33 . V_39 = V_29 ;
V_33 . V_40 = NULL ;
V_34 = V_4 -> V_41 ( V_4 , V_26 & ~ V_30 , & V_33 ) ;
* V_28 = V_33 . V_42 ;
return V_34 ;
}
int F_12 ( struct V_3 * V_4 , T_1 V_26 , T_2 V_27 ,
T_2 * V_28 , T_3 * V_29 )
{
T_1 V_30 = V_4 -> V_31 - 1 ;
struct V_32 V_33 ;
int V_34 ;
V_33 . V_35 = V_36 ;
V_33 . V_37 = V_26 & V_30 ;
V_33 . V_38 = V_27 ;
V_33 . V_39 = V_29 ;
V_33 . V_40 = NULL ;
V_34 = V_4 -> V_43 ( V_4 , V_26 & ~ V_30 , & V_33 ) ;
* V_28 = V_33 . V_42 ;
return V_34 ;
}
static int F_13 ( struct V_3 * V_4 , T_1 V_26 , T_2 V_27 ,
T_2 * V_28 , T_3 * V_29 , T_3 * V_44 )
{
T_1 V_30 = V_4 -> V_31 - 1 ;
struct V_32 V_33 ;
int V_34 ;
V_33 . V_35 = V_36 ;
V_33 . V_37 = V_26 & V_30 ;
V_33 . V_38 = V_4 -> V_45 ;
V_33 . V_39 = V_44 ;
V_33 . V_40 = V_29 ;
V_33 . V_27 = V_27 ;
V_34 = V_4 -> V_43 ( V_4 , V_26 & ~ V_30 , & V_33 ) ;
* V_28 = V_33 . V_28 ;
return V_34 ;
}
static T_4 F_14 ( struct V_5 * V_6 , int V_46 )
{
T_4 V_47 = V_6 -> V_48 ;
int V_49 = V_6 -> V_50 ;
if ( ! V_46 && V_6 -> V_51 < 2 ) {
F_3 ( L_12 ) ;
return V_52 ;
}
do {
if ( V_6 -> V_21 [ V_47 ] == V_53 ) {
V_6 -> V_48 = V_47 ;
V_6 -> V_51 -- ;
return V_47 ;
}
if ( ++ V_47 > V_6 -> V_54 )
V_47 = F_15 ( V_6 -> V_55 . V_56 ) ;
if ( ! V_49 -- ) {
F_2 ( L_13
L_14 , V_6 -> V_48 ,
F_15 ( V_6 -> V_55 . V_56 ) ) ;
return V_52 ;
}
} while ( V_47 != V_6 -> V_48 );
return V_52 ;
}
static T_4 F_16 ( struct V_5 * V_6 , unsigned V_57 , unsigned V_58 )
{
struct V_3 * V_4 = V_6 -> V_15 . V_4 ;
T_4 V_59 [ V_60 ] ;
unsigned char V_61 [ V_60 ] ;
unsigned char V_62 [ V_60 ] ;
unsigned int V_63 ;
int V_64 ;
int V_49 ;
unsigned int V_65 ;
struct V_66 V_44 ;
int V_67 = 1 ;
T_2 V_28 ;
memset ( V_59 , 0xff , sizeof( V_59 ) ) ;
memset ( V_62 , 0 , sizeof( V_62 ) ) ;
V_63 = V_6 -> V_22 [ V_57 ] ;
if ( V_63 == V_52 ) {
F_2 ( V_17 L_15
L_16 , V_57 ) ;
return V_52 ;
}
V_49 = V_68 ;
V_65 = V_52 ;
while ( V_63 <= V_6 -> V_54 ) {
unsigned int V_69 , V_70 ;
V_65 = V_63 ;
for ( V_64 = 0 ; V_64 < V_6 -> V_71 / 512 ; V_64 ++ ) {
F_11 ( V_4 , ( V_63 * V_6 -> V_71 ) +
( V_64 * 512 ) , 16 , & V_28 ,
( char * ) & V_44 ) ;
if ( V_64 == 2 ) {
V_70 = V_44 . V_72 . V_73 . V_74 | V_44 . V_72 . V_73 . V_75 ;
if ( V_70 == V_76 ) {
F_3 ( L_17 , V_63 ) ;
V_67 = 0 ;
} else {
V_67 = 1 ;
}
}
V_69 = V_44 . V_77 . V_78 | V_44 . V_77 . V_79 ;
V_61 [ V_64 ] = V_69 ;
switch( V_69 ) {
case V_80 :
V_62 [ V_64 ] = 1 ;
break;
case V_81 :
if ( ! V_62 [ V_64 ] )
V_59 [ V_64 ] = V_63 ;
else
F_2 ( V_17
L_18
L_19 ,
V_57 , V_64 ) ;
break;
case V_82 :
if ( ! V_62 [ V_64 ] )
V_59 [ V_64 ] = V_52 ;
else
F_2 ( V_17
L_20
L_19 ,
V_57 , V_64 ) ;
break;
case V_83 :
break;
default:
F_2 ( L_21 ,
V_64 , V_63 , V_69 ) ;
}
}
if ( ! V_49 -- ) {
F_2 ( V_17 L_22 ,
V_57 ) ;
return V_52 ;
}
V_63 = V_6 -> V_21 [ V_63 ] ;
}
if ( V_67 ) {
for ( V_64 = 0 ; V_64 < V_6 -> V_71 / 512 ; V_64 ++ ) {
if ( V_61 [ V_64 ] != V_80 &&
V_59 [ V_64 ] != V_52 &&
V_59 [ V_64 ] != V_65 ) {
F_3 ( L_23
L_24
L_25 ,
V_57 , V_64 , V_61 [ V_64 ] ,
V_59 [ V_64 ] ,
V_59 [ V_64 ] == V_65 ? L_26 : L_27 ,
V_65 ) ;
V_67 = 0 ;
break;
}
}
if ( V_58 >= ( V_57 * ( V_6 -> V_71 / 512 ) ) &&
V_58 < ( ( V_57 + 1 ) * ( V_6 -> V_71 / 512 ) ) &&
V_61 [ V_58 - ( V_57 * ( V_6 -> V_71 / 512 ) ) ] !=
V_80 ) {
F_3 ( L_28
L_29 , V_65 ) ;
V_67 = 0 ;
}
}
if ( ! V_67 ) {
F_3 ( L_30
L_31 , V_57 ) ;
V_65 = F_14 ( V_6 , 1 ) ;
if ( V_65 == V_52 ) {
F_2 ( V_17
L_32 ) ;
return V_52 ;
}
} else {
V_44 . V_72 . V_73 . V_74 = V_44 . V_72 . V_73 . V_75 = F_17 ( V_76 ) ;
V_44 . V_72 . V_73 . V_84 = 0xffffffff ;
F_12 ( V_4 , ( V_6 -> V_71 * V_65 ) + 2 * 512 + 8 ,
8 , & V_28 , ( char * ) & V_44 . V_72 ) ;
}
F_3 ( L_33 , V_57 , V_65 ) ;
for ( V_64 = 0 ; V_64 < V_6 -> V_71 / 512 ; V_64 ++ ) {
unsigned char V_85 [ 512 ] ;
int V_86 ;
if ( V_59 [ V_64 ] == V_65 ||
( V_58 == ( V_57 * ( V_6 -> V_71 / 512 ) + V_64 ) ) ) {
continue;
}
if ( V_59 [ V_64 ] == V_52 )
continue;
V_86 = V_4 -> V_87 ( V_4 , ( V_6 -> V_71 * V_59 [ V_64 ] ) + ( V_64 * 512 ) ,
512 , & V_28 , V_85 ) ;
if ( V_86 < 0 && ! F_18 ( V_86 ) ) {
V_86 = V_4 -> V_87 ( V_4 , ( V_6 -> V_71 * V_59 [ V_64 ] )
+ ( V_64 * 512 ) , 512 , & V_28 ,
V_85 ) ;
if ( V_86 != - V_88 )
F_2 ( L_34 ) ;
}
memset ( & V_44 , 0xff , sizeof( struct V_66 ) ) ;
V_44 . V_77 . V_78 = V_44 . V_77 . V_79 = V_81 ;
F_13 ( V_6 -> V_15 . V_4 , ( V_6 -> V_71 * V_65 ) +
( V_64 * 512 ) , 512 , & V_28 , V_85 , ( char * ) & V_44 ) ;
}
V_44 . V_72 . V_89 . V_90 = V_44 . V_72 . V_89 . V_91 = F_17 ( V_57 ) ;
V_44 . V_72 . V_89 . V_92 = V_44 . V_72 . V_89 . V_93 = V_52 ;
F_12 ( V_4 , ( V_6 -> V_71 * V_65 ) + 8 ,
8 , & V_28 , ( char * ) & V_44 . V_72 ) ;
V_63 = V_6 -> V_22 [ V_57 ] ;
F_3 ( L_35 ) ;
while ( V_63 <= V_6 -> V_54 && V_63 != V_65 ) {
unsigned int V_94 ;
V_94 = V_6 -> V_21 [ V_63 ] ;
if ( F_19 ( V_6 , V_63 ) < 0 ) {
V_6 -> V_21 [ V_63 ] = V_95 ;
} else {
V_6 -> V_21 [ V_63 ] = V_53 ;
V_6 -> V_51 ++ ;
}
V_63 = V_94 ;
}
V_6 -> V_21 [ V_65 ] = V_52 ;
V_6 -> V_22 [ V_57 ] = V_65 ;
return V_65 ;
}
static T_4 F_20 ( struct V_5 * V_6 , unsigned V_58 )
{
T_4 V_96 = 0 ;
T_4 V_97 = 0 , V_98 ;
T_4 V_99 , V_100 ;
for ( V_99 = 0 ; V_99 < F_21 ( V_6 -> V_55 . V_101 ) / V_6 -> V_71 ; V_99 ++ ) {
V_100 = V_6 -> V_22 [ V_99 ] ;
V_98 = 0 ;
while ( V_100 <= V_6 -> V_54 ) {
V_98 ++ ;
V_100 = V_6 -> V_21 [ V_100 ] & 0x7fff ;
if ( V_98 > 0xff00 ) {
F_2 ( L_36 ,
V_99 , V_100 ) ;
}
if ( V_98 > 0xff10 ) {
V_98 = 0 ;
break;
}
}
if ( V_98 > V_97 ) {
V_97 = V_98 ;
V_96 = V_99 ;
}
}
if ( V_97 < 2 ) {
F_2 ( V_17 L_37
L_38 ) ;
return V_52 ;
}
return F_16 ( V_6 , V_96 , V_58 ) ;
}
static inline T_4 F_22 ( struct V_5 * V_6 , unsigned V_64 )
{
T_4 V_54 ;
T_4 V_57 = V_64 / ( V_6 -> V_71 / 512 ) ;
struct V_3 * V_4 = V_6 -> V_15 . V_4 ;
unsigned int V_102 ;
unsigned long V_103 = ( V_64 * 512 ) & ( V_6 -> V_71 - 1 ) ;
T_2 V_28 ;
int V_49 , V_104 = 3 ;
struct V_66 V_44 ;
do {
V_54 = V_52 ;
V_102 = V_6 -> V_22 [ V_57 ] ;
V_49 = V_68 ;
while ( V_102 <= V_6 -> V_54 ) {
struct V_105 V_106 ;
T_2 V_28 ;
unsigned int V_69 ;
V_54 = V_102 ;
F_11 ( V_4 ,
( V_102 * V_6 -> V_71 ) + V_103 ,
8 , & V_28 , ( char * ) & V_106 ) ;
F_3 ( L_39 ,
V_64 , V_102 , F_15 ( V_106 . V_78 ) ) ;
V_69 = V_106 . V_78 | V_106 . V_79 ;
switch( V_69 ) {
case V_80 :
return V_102 ;
case V_82 :
case V_81 :
case V_83 :
break;
default:
break;
}
if ( ! V_49 -- ) {
F_2 ( V_17
L_22 ,
V_57 ) ;
return V_52 ;
}
V_102 = V_6 -> V_21 [ V_102 ] ;
}
V_102 = F_14 ( V_6 , 0 ) ;
if ( V_102 == V_52 ) {
V_102 = F_20 ( V_6 , V_52 ) ;
if ( V_102 == V_52 ) {
F_3 ( L_40 , V_57 ) ;
V_102 = F_14 ( V_6 , 1 ) ;
}
if ( V_102 == V_52 ) {
F_2 ( V_17 L_41 ) ;
return V_52 ;
}
V_54 = V_52 ;
continue;
}
if ( V_54 != V_52 ) {
V_57 |= 0x8000 ;
} else {
V_6 -> V_22 [ V_57 ] = V_102 ;
}
V_6 -> V_21 [ V_102 ] = V_52 ;
F_11 ( V_4 , V_102 * V_6 -> V_71 + 8 , 8 ,
& V_28 , ( char * ) & V_44 . V_72 ) ;
V_44 . V_72 . V_89 . V_90 = V_44 . V_72 . V_89 . V_91 = F_17 ( V_57 ) ;
F_12 ( V_4 , V_102 * V_6 -> V_71 + 8 , 8 ,
& V_28 , ( char * ) & V_44 . V_72 ) ;
if ( V_54 != V_52 ) {
V_6 -> V_21 [ V_54 ] = V_102 ;
F_11 ( V_4 , ( V_54 * V_6 -> V_71 ) + 8 ,
8 , & V_28 , ( char * ) & V_44 . V_72 ) ;
V_44 . V_72 . V_89 . V_92 = V_44 . V_72 . V_89 . V_93
= F_17 ( V_102 ) ;
F_12 ( V_4 , ( V_54 * V_6 -> V_71 ) + 8 ,
8 , & V_28 , ( char * ) & V_44 . V_72 ) ;
}
return V_102 ;
} while ( V_104 -- );
F_2 ( V_17 L_42 ,
V_57 ) ;
return V_52 ;
}
static int F_23 ( struct V_24 * V_15 , unsigned long V_64 ,
char * V_107 )
{
struct V_5 * V_6 = ( void * ) V_15 ;
T_4 V_102 ;
unsigned long V_103 = ( V_64 * 512 ) & ( V_6 -> V_71 - 1 ) ;
T_2 V_28 ;
struct V_66 V_44 ;
V_102 = F_22 ( V_6 , V_64 ) ;
if ( V_102 == V_52 ) {
F_2 ( V_17
L_43 ) ;
return 1 ;
}
memset ( & V_44 , 0xff , sizeof( struct V_66 ) ) ;
V_44 . V_77 . V_78 = V_44 . V_77 . V_79 = V_81 ;
F_13 ( V_6 -> V_15 . V_4 , ( V_102 * V_6 -> V_71 ) + V_103 ,
512 , & V_28 , ( char * ) V_107 , ( char * ) & V_44 ) ;
return 0 ;
}
static int F_24 ( struct V_24 * V_15 , unsigned long V_64 ,
char * V_107 )
{
struct V_5 * V_6 = ( void * ) V_15 ;
struct V_3 * V_4 = V_6 -> V_15 . V_4 ;
T_4 V_108 ;
T_4 V_63 = V_6 -> V_22 [ V_64 / ( V_6 -> V_71 / 512 ) ] ;
unsigned long V_103 = ( V_64 * 512 ) & ( V_6 -> V_71 - 1 ) ;
unsigned int V_69 ;
int V_49 = V_68 ;
T_2 V_28 ;
struct V_105 V_106 ;
V_108 = V_52 ;
if ( V_63 != V_52 ) {
while ( V_63 < V_6 -> V_50 ) {
if ( F_11 ( V_4 , ( V_63 * V_6 -> V_71 ) +
V_103 , 8 , & V_28 ,
( char * ) & V_106 ) < 0 )
V_69 = V_83 ;
else
V_69 = V_106 . V_78 | V_106 . V_79 ;
switch ( V_69 ) {
case V_80 :
goto V_109;
case V_82 :
V_108 = V_52 ;
break;
case V_81 :
V_108 = V_63 ;
break;
case V_83 :
break;
default:
F_2 ( L_44 ,
V_64 , V_63 , V_69 ) ;
break;
}
if ( ! V_49 -- ) {
F_2 ( V_17 L_45 ,
V_64 / ( V_6 -> V_71 / 512 ) ) ;
return 1 ;
}
V_63 = V_6 -> V_21 [ V_63 ] ;
}
}
V_109:
if ( V_108 == V_52 ) {
memset ( V_107 , 0 , 512 ) ;
} else {
T_1 V_110 = ( V_108 * V_6 -> V_71 ) + V_103 ;
T_2 V_28 ;
int V_34 = V_4 -> V_87 ( V_4 , V_110 , 512 , & V_28 , V_107 ) ;
if ( V_34 < 0 && ! F_18 ( V_34 ) )
return - V_88 ;
}
return 0 ;
}
static int F_25 ( struct V_24 * V_25 , struct V_111 * V_112 )
{
struct V_5 * V_6 = ( void * ) V_25 ;
V_112 -> V_19 = V_6 -> V_19 ;
V_112 -> V_20 = V_6 -> V_20 ;
V_112 -> V_18 = V_6 -> V_18 ;
return 0 ;
}
static int T_5 F_26 ( void )
{
return F_27 ( & V_113 ) ;
}
static void T_6 F_28 ( void )
{
F_29 ( & V_113 ) ;
}
