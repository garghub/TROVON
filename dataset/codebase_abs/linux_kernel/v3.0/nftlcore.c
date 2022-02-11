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
F_3 ( V_14 , L_4 , V_4 -> V_11 ) ;
V_6 = F_4 ( sizeof( struct V_5 ) , V_15 ) ;
if ( ! V_6 ) {
F_2 ( V_16 L_5 ) ;
return;
}
V_6 -> V_17 . V_4 = V_4 ;
V_6 -> V_17 . V_18 = - 1 ;
V_6 -> V_17 . V_2 = V_2 ;
if ( F_5 ( V_6 ) < 0 ) {
F_2 ( V_16 L_6 ) ;
F_6 ( V_6 ) ;
return;
}
V_6 -> V_19 = 1024 ;
V_6 -> V_20 = 16 ;
V_7 = V_6 -> V_19 * V_6 -> V_20 ;
V_6 -> V_21 = V_6 -> V_17 . V_9 / V_7 ;
if ( V_6 -> V_17 . V_9 % V_7 ) {
V_6 -> V_21 ++ ;
V_7 = V_6 -> V_19 * V_6 -> V_21 ;
V_6 -> V_20 = V_6 -> V_17 . V_9 / V_7 ;
if ( V_6 -> V_17 . V_9 % V_7 ) {
V_6 -> V_20 ++ ;
V_7 = V_6 -> V_20 * V_6 -> V_21 ;
V_6 -> V_19 = V_6 -> V_17 . V_9 / V_7 ;
}
}
if ( V_6 -> V_17 . V_9 != V_6 -> V_20 * V_6 -> V_19 * V_6 -> V_21 ) {
F_2 ( V_16 L_7
L_8 , V_6 -> V_17 . V_9 ) ;
F_2 ( V_16 L_9
L_10 ,
V_6 -> V_19 , V_6 -> V_20 , V_6 -> V_21 ,
( long ) V_6 -> V_19 * ( long ) V_6 -> V_20 *
( long ) V_6 -> V_21 ) ;
}
if ( F_7 ( & V_6 -> V_17 ) ) {
F_6 ( V_6 -> V_22 ) ;
F_6 ( V_6 -> V_23 ) ;
F_6 ( V_6 ) ;
return;
}
#ifdef F_8
F_2 ( V_24 L_11 , V_6 -> V_17 . V_18 + 'a' ) ;
#endif
}
static void F_9 ( struct V_25 * V_26 )
{
struct V_5 * V_6 = ( void * ) V_26 ;
F_3 ( V_14 , L_12 , V_26 -> V_18 ) ;
F_10 ( V_26 ) ;
F_6 ( V_6 -> V_22 ) ;
F_6 ( V_6 -> V_23 ) ;
}
int F_11 ( struct V_3 * V_4 , T_1 V_27 , T_2 V_28 ,
T_2 * V_29 , T_3 * V_30 )
{
T_1 V_31 = V_4 -> V_32 - 1 ;
struct V_33 V_34 ;
int V_35 ;
V_34 . V_36 = V_37 ;
V_34 . V_38 = V_27 & V_31 ;
V_34 . V_39 = V_28 ;
V_34 . V_40 = V_30 ;
V_34 . V_41 = NULL ;
V_35 = V_4 -> V_42 ( V_4 , V_27 & ~ V_31 , & V_34 ) ;
* V_29 = V_34 . V_43 ;
return V_35 ;
}
int F_12 ( struct V_3 * V_4 , T_1 V_27 , T_2 V_28 ,
T_2 * V_29 , T_3 * V_30 )
{
T_1 V_31 = V_4 -> V_32 - 1 ;
struct V_33 V_34 ;
int V_35 ;
V_34 . V_36 = V_37 ;
V_34 . V_38 = V_27 & V_31 ;
V_34 . V_39 = V_28 ;
V_34 . V_40 = V_30 ;
V_34 . V_41 = NULL ;
V_35 = V_4 -> V_44 ( V_4 , V_27 & ~ V_31 , & V_34 ) ;
* V_29 = V_34 . V_43 ;
return V_35 ;
}
static int F_13 ( struct V_3 * V_4 , T_1 V_27 , T_2 V_28 ,
T_2 * V_29 , T_3 * V_30 , T_3 * V_45 )
{
T_1 V_31 = V_4 -> V_32 - 1 ;
struct V_33 V_34 ;
int V_35 ;
V_34 . V_36 = V_37 ;
V_34 . V_38 = V_27 & V_31 ;
V_34 . V_39 = V_4 -> V_46 ;
V_34 . V_40 = V_45 ;
V_34 . V_41 = V_30 ;
V_34 . V_28 = V_28 ;
V_35 = V_4 -> V_44 ( V_4 , V_27 & ~ V_31 , & V_34 ) ;
* V_29 = V_34 . V_29 ;
return V_35 ;
}
static T_4 F_14 ( struct V_5 * V_6 , int V_47 )
{
T_4 V_48 = V_6 -> V_49 ;
int V_50 = V_6 -> V_51 ;
if ( ! V_47 && V_6 -> V_52 < 2 ) {
F_3 ( V_14 , L_13 ) ;
return V_53 ;
}
do {
if ( V_6 -> V_22 [ V_48 ] == V_54 ) {
V_6 -> V_49 = V_48 ;
V_6 -> V_52 -- ;
return V_48 ;
}
if ( ++ V_48 > V_6 -> V_55 )
V_48 = F_15 ( V_6 -> V_56 . V_57 ) ;
if ( ! V_50 -- ) {
F_2 ( L_14
L_15 , V_6 -> V_49 ,
F_15 ( V_6 -> V_56 . V_57 ) ) ;
return V_53 ;
}
} while ( V_48 != V_6 -> V_49 );
return V_53 ;
}
static T_4 F_16 ( struct V_5 * V_6 , unsigned V_58 , unsigned V_59 )
{
struct V_3 * V_4 = V_6 -> V_17 . V_4 ;
T_4 V_60 [ V_61 ] ;
unsigned char V_62 [ V_61 ] ;
unsigned char V_63 [ V_61 ] ;
unsigned int V_64 ;
int V_65 ;
int V_50 ;
unsigned int V_66 ;
struct V_67 V_45 ;
int V_68 = 1 ;
T_2 V_29 ;
memset ( V_60 , 0xff , sizeof( V_60 ) ) ;
memset ( V_63 , 0 , sizeof( V_63 ) ) ;
V_64 = V_6 -> V_23 [ V_58 ] ;
if ( V_64 == V_53 ) {
F_2 ( V_16 L_16
L_17 , V_58 ) ;
return V_53 ;
}
V_50 = V_69 ;
V_66 = V_53 ;
while ( V_64 <= V_6 -> V_55 ) {
unsigned int V_70 , V_71 ;
V_66 = V_64 ;
for ( V_65 = 0 ; V_65 < V_6 -> V_72 / 512 ; V_65 ++ ) {
F_11 ( V_4 , ( V_64 * V_6 -> V_72 ) +
( V_65 * 512 ) , 16 , & V_29 ,
( char * ) & V_45 ) ;
if ( V_65 == 2 ) {
V_71 = V_45 . V_73 . V_74 . V_75 | V_45 . V_73 . V_74 . V_76 ;
if ( V_71 == V_77 ) {
F_3 ( V_14 ,
L_18 , V_64 ) ;
V_68 = 0 ;
} else {
V_68 = 1 ;
}
}
V_70 = V_45 . V_78 . V_79 | V_45 . V_78 . V_80 ;
V_62 [ V_65 ] = V_70 ;
switch( V_70 ) {
case V_81 :
V_63 [ V_65 ] = 1 ;
break;
case V_82 :
if ( ! V_63 [ V_65 ] )
V_60 [ V_65 ] = V_64 ;
else
F_2 ( V_16
L_19
L_20 ,
V_58 , V_65 ) ;
break;
case V_83 :
if ( ! V_63 [ V_65 ] )
V_60 [ V_65 ] = V_53 ;
else
F_2 ( V_16
L_21
L_20 ,
V_58 , V_65 ) ;
break;
case V_84 :
break;
default:
F_2 ( L_22 ,
V_65 , V_64 , V_70 ) ;
}
}
if ( ! V_50 -- ) {
F_2 ( V_16 L_23 ,
V_58 ) ;
return V_53 ;
}
V_64 = V_6 -> V_22 [ V_64 ] ;
}
if ( V_68 ) {
for ( V_65 = 0 ; V_65 < V_6 -> V_72 / 512 ; V_65 ++ ) {
if ( V_62 [ V_65 ] != V_81 &&
V_60 [ V_65 ] != V_53 &&
V_60 [ V_65 ] != V_66 ) {
F_3 ( V_14 , L_24
L_25
L_26 ,
V_58 , V_65 , V_62 [ V_65 ] ,
V_60 [ V_65 ] ,
V_60 [ V_65 ] == V_66 ? L_27 : L_28 ,
V_66 ) ;
V_68 = 0 ;
break;
}
}
if ( V_59 >= ( V_58 * ( V_6 -> V_72 / 512 ) ) &&
V_59 < ( ( V_58 + 1 ) * ( V_6 -> V_72 / 512 ) ) &&
V_62 [ V_59 - ( V_58 * ( V_6 -> V_72 / 512 ) ) ] !=
V_81 ) {
F_3 ( V_14 , L_29
L_30 , V_66 ) ;
V_68 = 0 ;
}
}
if ( ! V_68 ) {
F_3 ( V_14 , L_31
L_32 , V_58 ) ;
V_66 = F_14 ( V_6 , 1 ) ;
if ( V_66 == V_53 ) {
F_2 ( V_16
L_33 ) ;
return V_53 ;
}
} else {
V_45 . V_73 . V_74 . V_75 = V_45 . V_73 . V_74 . V_76 = F_17 ( V_77 ) ;
V_45 . V_73 . V_74 . V_85 = 0xffffffff ;
F_12 ( V_4 , ( V_6 -> V_72 * V_66 ) + 2 * 512 + 8 ,
8 , & V_29 , ( char * ) & V_45 . V_73 ) ;
}
F_3 ( V_14 , L_34 , V_58 , V_66 ) ;
for ( V_65 = 0 ; V_65 < V_6 -> V_72 / 512 ; V_65 ++ ) {
unsigned char V_86 [ 512 ] ;
int V_87 ;
if ( V_60 [ V_65 ] == V_66 ||
( V_59 == ( V_58 * ( V_6 -> V_72 / 512 ) + V_65 ) ) ) {
continue;
}
if ( V_60 [ V_65 ] == V_53 )
continue;
V_87 = V_4 -> V_88 ( V_4 , ( V_6 -> V_72 * V_60 [ V_65 ] ) + ( V_65 * 512 ) ,
512 , & V_29 , V_86 ) ;
if ( V_87 < 0 && V_87 != - V_89 ) {
V_87 = V_4 -> V_88 ( V_4 , ( V_6 -> V_72 * V_60 [ V_65 ] )
+ ( V_65 * 512 ) , 512 , & V_29 ,
V_86 ) ;
if ( V_87 != - V_90 )
F_2 ( L_35 ) ;
}
memset ( & V_45 , 0xff , sizeof( struct V_67 ) ) ;
V_45 . V_78 . V_79 = V_45 . V_78 . V_80 = V_82 ;
F_13 ( V_6 -> V_17 . V_4 , ( V_6 -> V_72 * V_66 ) +
( V_65 * 512 ) , 512 , & V_29 , V_86 , ( char * ) & V_45 ) ;
}
V_45 . V_73 . V_91 . V_92 = V_45 . V_73 . V_91 . V_93 = F_17 ( V_58 ) ;
V_45 . V_73 . V_91 . V_94 = V_45 . V_73 . V_91 . V_95 = V_53 ;
F_12 ( V_4 , ( V_6 -> V_72 * V_66 ) + 8 ,
8 , & V_29 , ( char * ) & V_45 . V_73 ) ;
V_64 = V_6 -> V_23 [ V_58 ] ;
F_3 ( V_14 , L_36 ) ;
while ( V_64 <= V_6 -> V_55 && V_64 != V_66 ) {
unsigned int V_96 ;
V_96 = V_6 -> V_22 [ V_64 ] ;
if ( F_18 ( V_6 , V_64 ) < 0 ) {
V_6 -> V_22 [ V_64 ] = V_97 ;
} else {
V_6 -> V_22 [ V_64 ] = V_54 ;
V_6 -> V_52 ++ ;
}
V_64 = V_96 ;
}
V_6 -> V_22 [ V_66 ] = V_53 ;
V_6 -> V_23 [ V_58 ] = V_66 ;
return V_66 ;
}
static T_4 F_19 ( struct V_5 * V_6 , unsigned V_59 )
{
T_4 V_98 = 0 ;
T_4 V_99 = 0 , V_100 ;
T_4 V_101 , V_102 ;
for ( V_101 = 0 ; V_101 < F_20 ( V_6 -> V_56 . V_103 ) / V_6 -> V_72 ; V_101 ++ ) {
V_102 = V_6 -> V_23 [ V_101 ] ;
V_100 = 0 ;
while ( V_102 <= V_6 -> V_55 ) {
V_100 ++ ;
V_102 = V_6 -> V_22 [ V_102 ] & 0x7fff ;
if ( V_100 > 0xff00 ) {
F_2 ( L_37 ,
V_101 , V_102 ) ;
}
if ( V_100 > 0xff10 ) {
V_100 = 0 ;
break;
}
}
if ( V_100 > V_99 ) {
V_99 = V_100 ;
V_98 = V_101 ;
}
}
if ( V_99 < 2 ) {
F_2 ( V_16 L_38
L_39 ) ;
return V_53 ;
}
return F_16 ( V_6 , V_98 , V_59 ) ;
}
static inline T_4 F_21 ( struct V_5 * V_6 , unsigned V_65 )
{
T_4 V_55 ;
T_4 V_58 = V_65 / ( V_6 -> V_72 / 512 ) ;
struct V_3 * V_4 = V_6 -> V_17 . V_4 ;
unsigned int V_104 ;
unsigned long V_105 = ( V_65 * 512 ) & ( V_6 -> V_72 - 1 ) ;
T_2 V_29 ;
int V_50 , V_106 = 3 ;
struct V_67 V_45 ;
do {
V_55 = V_53 ;
V_104 = V_6 -> V_23 [ V_58 ] ;
V_50 = V_69 ;
while ( V_104 <= V_6 -> V_55 ) {
struct V_107 V_108 ;
T_2 V_29 ;
unsigned int V_70 ;
V_55 = V_104 ;
F_11 ( V_4 ,
( V_104 * V_6 -> V_72 ) + V_105 ,
8 , & V_29 , ( char * ) & V_108 ) ;
F_3 ( V_109 , L_40 ,
V_65 , V_104 , F_15 ( V_108 . V_79 ) ) ;
V_70 = V_108 . V_79 | V_108 . V_80 ;
switch( V_70 ) {
case V_81 :
return V_104 ;
case V_83 :
case V_82 :
case V_84 :
break;
default:
break;
}
if ( ! V_50 -- ) {
F_2 ( V_16
L_23 ,
V_58 ) ;
return V_53 ;
}
V_104 = V_6 -> V_22 [ V_104 ] ;
}
V_104 = F_14 ( V_6 , 0 ) ;
if ( V_104 == V_53 ) {
V_104 = F_19 ( V_6 , V_53 ) ;
if ( V_104 == V_53 ) {
F_3 ( V_14 , L_41 , V_58 ) ;
V_104 = F_14 ( V_6 , 1 ) ;
}
if ( V_104 == V_53 ) {
F_2 ( V_16 L_42 ) ;
return V_53 ;
}
V_55 = V_53 ;
continue;
}
if ( V_55 != V_53 ) {
V_58 |= 0x8000 ;
} else {
V_6 -> V_23 [ V_58 ] = V_104 ;
}
V_6 -> V_22 [ V_104 ] = V_53 ;
F_11 ( V_4 , V_104 * V_6 -> V_72 + 8 , 8 ,
& V_29 , ( char * ) & V_45 . V_73 ) ;
V_45 . V_73 . V_91 . V_92 = V_45 . V_73 . V_91 . V_93 = F_17 ( V_58 ) ;
F_12 ( V_4 , V_104 * V_6 -> V_72 + 8 , 8 ,
& V_29 , ( char * ) & V_45 . V_73 ) ;
if ( V_55 != V_53 ) {
V_6 -> V_22 [ V_55 ] = V_104 ;
F_11 ( V_4 , ( V_55 * V_6 -> V_72 ) + 8 ,
8 , & V_29 , ( char * ) & V_45 . V_73 ) ;
V_45 . V_73 . V_91 . V_94 = V_45 . V_73 . V_91 . V_95
= F_17 ( V_104 ) ;
F_12 ( V_4 , ( V_55 * V_6 -> V_72 ) + 8 ,
8 , & V_29 , ( char * ) & V_45 . V_73 ) ;
}
return V_104 ;
} while ( V_106 -- );
F_2 ( V_16 L_43 ,
V_58 ) ;
return V_53 ;
}
static int F_22 ( struct V_25 * V_17 , unsigned long V_65 ,
char * V_110 )
{
struct V_5 * V_6 = ( void * ) V_17 ;
T_4 V_104 ;
unsigned long V_105 = ( V_65 * 512 ) & ( V_6 -> V_72 - 1 ) ;
T_2 V_29 ;
struct V_67 V_45 ;
V_104 = F_21 ( V_6 , V_65 ) ;
if ( V_104 == V_53 ) {
F_2 ( V_16
L_44 ) ;
return 1 ;
}
memset ( & V_45 , 0xff , sizeof( struct V_67 ) ) ;
V_45 . V_78 . V_79 = V_45 . V_78 . V_80 = V_82 ;
F_13 ( V_6 -> V_17 . V_4 , ( V_104 * V_6 -> V_72 ) + V_105 ,
512 , & V_29 , ( char * ) V_110 , ( char * ) & V_45 ) ;
return 0 ;
}
static int F_23 ( struct V_25 * V_17 , unsigned long V_65 ,
char * V_110 )
{
struct V_5 * V_6 = ( void * ) V_17 ;
struct V_3 * V_4 = V_6 -> V_17 . V_4 ;
T_4 V_111 ;
T_4 V_64 = V_6 -> V_23 [ V_65 / ( V_6 -> V_72 / 512 ) ] ;
unsigned long V_105 = ( V_65 * 512 ) & ( V_6 -> V_72 - 1 ) ;
unsigned int V_70 ;
int V_50 = V_69 ;
T_2 V_29 ;
struct V_107 V_108 ;
V_111 = V_53 ;
if ( V_64 != V_53 ) {
while ( V_64 < V_6 -> V_51 ) {
if ( F_11 ( V_4 , ( V_64 * V_6 -> V_72 ) +
V_105 , 8 , & V_29 ,
( char * ) & V_108 ) < 0 )
V_70 = V_84 ;
else
V_70 = V_108 . V_79 | V_108 . V_80 ;
switch ( V_70 ) {
case V_81 :
goto V_112;
case V_83 :
V_111 = V_53 ;
break;
case V_82 :
V_111 = V_64 ;
break;
case V_84 :
break;
default:
F_2 ( L_45 ,
V_65 , V_64 , V_70 ) ;
break;
}
if ( ! V_50 -- ) {
F_2 ( V_16 L_46 ,
V_65 / ( V_6 -> V_72 / 512 ) ) ;
return 1 ;
}
V_64 = V_6 -> V_22 [ V_64 ] ;
}
}
V_112:
if ( V_111 == V_53 ) {
memset ( V_110 , 0 , 512 ) ;
} else {
T_1 V_113 = ( V_111 * V_6 -> V_72 ) + V_105 ;
T_2 V_29 ;
int V_35 = V_4 -> V_88 ( V_4 , V_113 , 512 , & V_29 , V_110 ) ;
if ( V_35 < 0 && V_35 != - V_89 )
return - V_90 ;
}
return 0 ;
}
static int F_24 ( struct V_25 * V_26 , struct V_114 * V_115 )
{
struct V_5 * V_6 = ( void * ) V_26 ;
V_115 -> V_20 = V_6 -> V_20 ;
V_115 -> V_21 = V_6 -> V_21 ;
V_115 -> V_19 = V_6 -> V_19 ;
return 0 ;
}
static int T_5 F_25 ( void )
{
return F_26 ( & V_116 ) ;
}
static void T_6 F_27 ( void )
{
F_28 ( & V_116 ) ;
}
