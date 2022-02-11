static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
if ( V_4 -> type != V_8 || V_4 -> V_9 > V_10 )
return;
if ( memcmp ( V_4 -> V_11 , L_1 , 10 ) )
return;
if ( ! F_2 ( V_4 ) ) {
F_3 ( V_12
L_2
L_3 ) ;
return;
}
F_4 ( L_4 , V_4 -> V_11 ) ;
V_6 = F_5 ( sizeof( struct V_5 ) , V_13 ) ;
if ( ! V_6 )
return;
V_6 -> V_14 . V_4 = V_4 ;
V_6 -> V_14 . V_15 = - 1 ;
V_6 -> V_14 . V_2 = V_2 ;
if ( F_6 ( V_6 ) < 0 ) {
F_3 ( V_16 L_5 ) ;
F_7 ( V_6 ) ;
return;
}
V_6 -> V_17 = 1024 ;
V_6 -> V_18 = 16 ;
V_7 = V_6 -> V_17 * V_6 -> V_18 ;
V_6 -> V_19 = V_6 -> V_14 . V_9 / V_7 ;
if ( V_6 -> V_14 . V_9 % V_7 ) {
V_6 -> V_19 ++ ;
V_7 = V_6 -> V_17 * V_6 -> V_19 ;
V_6 -> V_18 = V_6 -> V_14 . V_9 / V_7 ;
if ( V_6 -> V_14 . V_9 % V_7 ) {
V_6 -> V_18 ++ ;
V_7 = V_6 -> V_18 * V_6 -> V_19 ;
V_6 -> V_17 = V_6 -> V_14 . V_9 / V_7 ;
}
}
if ( V_6 -> V_14 . V_9 != V_6 -> V_18 * V_6 -> V_17 * V_6 -> V_19 ) {
F_3 ( V_16 L_6
L_7 , V_6 -> V_14 . V_9 ) ;
F_3 ( V_16 L_8
L_9 ,
V_6 -> V_17 , V_6 -> V_18 , V_6 -> V_19 ,
( long ) V_6 -> V_17 * ( long ) V_6 -> V_18 *
( long ) V_6 -> V_19 ) ;
}
if ( F_8 ( & V_6 -> V_14 ) ) {
F_7 ( V_6 -> V_20 ) ;
F_7 ( V_6 -> V_21 ) ;
F_7 ( V_6 ) ;
return;
}
#ifdef F_9
F_3 ( V_22 L_10 , V_6 -> V_14 . V_15 + 'a' ) ;
#endif
}
static void F_10 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = ( void * ) V_24 ;
F_4 ( L_11 , V_24 -> V_15 ) ;
F_11 ( V_24 ) ;
F_7 ( V_6 -> V_20 ) ;
F_7 ( V_6 -> V_21 ) ;
}
int F_12 ( struct V_3 * V_4 , T_1 V_25 , T_2 V_26 ,
T_2 * V_27 , T_3 * V_28 )
{
T_1 V_29 = V_4 -> V_30 - 1 ;
struct V_31 V_32 ;
int V_33 ;
V_32 . V_34 = V_35 ;
V_32 . V_36 = V_25 & V_29 ;
V_32 . V_37 = V_26 ;
V_32 . V_38 = V_28 ;
V_32 . V_39 = NULL ;
V_33 = F_13 ( V_4 , V_25 & ~ V_29 , & V_32 ) ;
* V_27 = V_32 . V_40 ;
return V_33 ;
}
int F_14 ( struct V_3 * V_4 , T_1 V_25 , T_2 V_26 ,
T_2 * V_27 , T_3 * V_28 )
{
T_1 V_29 = V_4 -> V_30 - 1 ;
struct V_31 V_32 ;
int V_33 ;
V_32 . V_34 = V_35 ;
V_32 . V_36 = V_25 & V_29 ;
V_32 . V_37 = V_26 ;
V_32 . V_38 = V_28 ;
V_32 . V_39 = NULL ;
V_33 = F_15 ( V_4 , V_25 & ~ V_29 , & V_32 ) ;
* V_27 = V_32 . V_40 ;
return V_33 ;
}
static int F_16 ( struct V_3 * V_4 , T_1 V_25 , T_2 V_26 ,
T_2 * V_27 , T_3 * V_28 , T_3 * V_41 )
{
T_1 V_29 = V_4 -> V_30 - 1 ;
struct V_31 V_32 ;
int V_33 ;
V_32 . V_34 = V_35 ;
V_32 . V_36 = V_25 & V_29 ;
V_32 . V_37 = V_4 -> V_42 ;
V_32 . V_38 = V_41 ;
V_32 . V_39 = V_28 ;
V_32 . V_26 = V_26 ;
V_33 = F_15 ( V_4 , V_25 & ~ V_29 , & V_32 ) ;
* V_27 = V_32 . V_27 ;
return V_33 ;
}
static T_4 F_17 ( struct V_5 * V_6 , int V_43 )
{
T_4 V_44 = V_6 -> V_45 ;
int V_46 = V_6 -> V_47 ;
if ( ! V_43 && V_6 -> V_48 < 2 ) {
F_4 ( L_12 ) ;
return V_49 ;
}
do {
if ( V_6 -> V_20 [ V_44 ] == V_50 ) {
V_6 -> V_45 = V_44 ;
V_6 -> V_48 -- ;
return V_44 ;
}
if ( ++ V_44 > V_6 -> V_51 )
V_44 = F_18 ( V_6 -> V_52 . V_53 ) ;
if ( ! V_46 -- ) {
F_3 ( L_13
L_14 , V_6 -> V_45 ,
F_18 ( V_6 -> V_52 . V_53 ) ) ;
return V_49 ;
}
} while ( V_44 != V_6 -> V_45 );
return V_49 ;
}
static T_4 F_19 ( struct V_5 * V_6 , unsigned V_54 , unsigned V_55 )
{
struct V_3 * V_4 = V_6 -> V_14 . V_4 ;
T_4 V_56 [ V_57 ] ;
unsigned char V_58 [ V_57 ] ;
unsigned char V_59 [ V_57 ] ;
unsigned int V_60 ;
int V_61 ;
int V_46 ;
unsigned int V_62 ;
struct V_63 V_41 ;
int V_64 = 1 ;
T_2 V_27 ;
memset ( V_56 , 0xff , sizeof( V_56 ) ) ;
memset ( V_59 , 0 , sizeof( V_59 ) ) ;
V_60 = V_6 -> V_21 [ V_54 ] ;
if ( V_60 == V_49 ) {
F_3 ( V_16 L_15
L_16 , V_54 ) ;
return V_49 ;
}
V_46 = V_65 ;
V_62 = V_49 ;
while ( V_60 <= V_6 -> V_51 ) {
unsigned int V_66 , V_67 ;
V_62 = V_60 ;
for ( V_61 = 0 ; V_61 < V_6 -> V_68 / 512 ; V_61 ++ ) {
F_12 ( V_4 , ( V_60 * V_6 -> V_68 ) +
( V_61 * 512 ) , 16 , & V_27 ,
( char * ) & V_41 ) ;
if ( V_61 == 2 ) {
V_67 = V_41 . V_69 . V_70 . V_71 | V_41 . V_69 . V_70 . V_72 ;
if ( V_67 == V_73 ) {
F_4 ( L_17 , V_60 ) ;
V_64 = 0 ;
} else {
V_64 = 1 ;
}
}
V_66 = V_41 . V_74 . V_75 | V_41 . V_74 . V_76 ;
V_58 [ V_61 ] = V_66 ;
switch( V_66 ) {
case V_77 :
V_59 [ V_61 ] = 1 ;
break;
case V_78 :
if ( ! V_59 [ V_61 ] )
V_56 [ V_61 ] = V_60 ;
else
F_3 ( V_16
L_18
L_19 ,
V_54 , V_61 ) ;
break;
case V_79 :
if ( ! V_59 [ V_61 ] )
V_56 [ V_61 ] = V_49 ;
else
F_3 ( V_16
L_20
L_19 ,
V_54 , V_61 ) ;
break;
case V_80 :
break;
default:
F_3 ( L_21 ,
V_61 , V_60 , V_66 ) ;
}
}
if ( ! V_46 -- ) {
F_3 ( V_16 L_22 ,
V_54 ) ;
return V_49 ;
}
V_60 = V_6 -> V_20 [ V_60 ] ;
}
if ( V_64 ) {
for ( V_61 = 0 ; V_61 < V_6 -> V_68 / 512 ; V_61 ++ ) {
if ( V_58 [ V_61 ] != V_77 &&
V_56 [ V_61 ] != V_49 &&
V_56 [ V_61 ] != V_62 ) {
F_4 ( L_23
L_24
L_25 ,
V_54 , V_61 , V_58 [ V_61 ] ,
V_56 [ V_61 ] ,
V_56 [ V_61 ] == V_62 ? L_26 : L_27 ,
V_62 ) ;
V_64 = 0 ;
break;
}
}
if ( V_55 >= ( V_54 * ( V_6 -> V_68 / 512 ) ) &&
V_55 < ( ( V_54 + 1 ) * ( V_6 -> V_68 / 512 ) ) &&
V_58 [ V_55 - ( V_54 * ( V_6 -> V_68 / 512 ) ) ] !=
V_77 ) {
F_4 ( L_28
L_29 , V_62 ) ;
V_64 = 0 ;
}
}
if ( ! V_64 ) {
F_4 ( L_30
L_31 , V_54 ) ;
V_62 = F_17 ( V_6 , 1 ) ;
if ( V_62 == V_49 ) {
F_3 ( V_16
L_32 ) ;
return V_49 ;
}
} else {
V_41 . V_69 . V_70 . V_71 = V_41 . V_69 . V_70 . V_72 = F_20 ( V_73 ) ;
V_41 . V_69 . V_70 . V_81 = 0xffffffff ;
F_14 ( V_4 , ( V_6 -> V_68 * V_62 ) + 2 * 512 + 8 ,
8 , & V_27 , ( char * ) & V_41 . V_69 ) ;
}
F_4 ( L_33 , V_54 , V_62 ) ;
for ( V_61 = 0 ; V_61 < V_6 -> V_68 / 512 ; V_61 ++ ) {
unsigned char V_82 [ 512 ] ;
int V_83 ;
if ( V_56 [ V_61 ] == V_62 ||
( V_55 == ( V_54 * ( V_6 -> V_68 / 512 ) + V_61 ) ) ) {
continue;
}
if ( V_56 [ V_61 ] == V_49 )
continue;
V_83 = F_21 ( V_4 ,
( V_6 -> V_68 * V_56 [ V_61 ] ) + ( V_61 * 512 ) ,
512 ,
& V_27 ,
V_82 ) ;
if ( V_83 < 0 && ! F_22 ( V_83 ) ) {
V_83 = F_21 ( V_4 ,
( V_6 -> V_68 * V_56 [ V_61 ] ) + ( V_61 * 512 ) ,
512 ,
& V_27 ,
V_82 ) ;
if ( V_83 != - V_84 )
F_3 ( L_34 ) ;
}
memset ( & V_41 , 0xff , sizeof( struct V_63 ) ) ;
V_41 . V_74 . V_75 = V_41 . V_74 . V_76 = V_78 ;
F_16 ( V_6 -> V_14 . V_4 , ( V_6 -> V_68 * V_62 ) +
( V_61 * 512 ) , 512 , & V_27 , V_82 , ( char * ) & V_41 ) ;
}
V_41 . V_69 . V_85 . V_86 = V_41 . V_69 . V_85 . V_87 = F_20 ( V_54 ) ;
V_41 . V_69 . V_85 . V_88 = V_41 . V_69 . V_85 . V_89 = V_49 ;
F_14 ( V_4 , ( V_6 -> V_68 * V_62 ) + 8 ,
8 , & V_27 , ( char * ) & V_41 . V_69 ) ;
V_60 = V_6 -> V_21 [ V_54 ] ;
F_4 ( L_35 ) ;
while ( V_60 <= V_6 -> V_51 && V_60 != V_62 ) {
unsigned int V_90 ;
V_90 = V_6 -> V_20 [ V_60 ] ;
if ( F_23 ( V_6 , V_60 ) < 0 ) {
V_6 -> V_20 [ V_60 ] = V_91 ;
} else {
V_6 -> V_20 [ V_60 ] = V_50 ;
V_6 -> V_48 ++ ;
}
V_60 = V_90 ;
}
V_6 -> V_20 [ V_62 ] = V_49 ;
V_6 -> V_21 [ V_54 ] = V_62 ;
return V_62 ;
}
static T_4 F_24 ( struct V_5 * V_6 , unsigned V_55 )
{
T_4 V_92 = 0 ;
T_4 V_93 = 0 , V_94 ;
T_4 V_95 , V_96 ;
for ( V_95 = 0 ; V_95 < F_25 ( V_6 -> V_52 . V_97 ) / V_6 -> V_68 ; V_95 ++ ) {
V_96 = V_6 -> V_21 [ V_95 ] ;
V_94 = 0 ;
while ( V_96 <= V_6 -> V_51 ) {
V_94 ++ ;
V_96 = V_6 -> V_20 [ V_96 ] & 0x7fff ;
if ( V_94 > 0xff00 ) {
F_3 ( L_36 ,
V_95 , V_96 ) ;
}
if ( V_94 > 0xff10 ) {
V_94 = 0 ;
break;
}
}
if ( V_94 > V_93 ) {
V_93 = V_94 ;
V_92 = V_95 ;
}
}
if ( V_93 < 2 ) {
F_3 ( V_16 L_37
L_38 ) ;
return V_49 ;
}
return F_19 ( V_6 , V_92 , V_55 ) ;
}
static inline T_4 F_26 ( struct V_5 * V_6 , unsigned V_61 )
{
T_4 V_51 ;
T_4 V_54 = V_61 / ( V_6 -> V_68 / 512 ) ;
struct V_3 * V_4 = V_6 -> V_14 . V_4 ;
unsigned int V_98 ;
unsigned long V_99 = ( V_61 * 512 ) & ( V_6 -> V_68 - 1 ) ;
T_2 V_27 ;
int V_46 , V_100 = 3 ;
struct V_63 V_41 ;
do {
V_51 = V_49 ;
V_98 = V_6 -> V_21 [ V_54 ] ;
V_46 = V_65 ;
while ( V_98 <= V_6 -> V_51 ) {
struct V_101 V_102 ;
T_2 V_27 ;
unsigned int V_66 ;
V_51 = V_98 ;
F_12 ( V_4 ,
( V_98 * V_6 -> V_68 ) + V_99 ,
8 , & V_27 , ( char * ) & V_102 ) ;
F_4 ( L_39 ,
V_61 , V_98 , F_18 ( V_102 . V_75 ) ) ;
V_66 = V_102 . V_75 | V_102 . V_76 ;
switch( V_66 ) {
case V_77 :
return V_98 ;
case V_79 :
case V_78 :
case V_80 :
break;
default:
break;
}
if ( ! V_46 -- ) {
F_3 ( V_16
L_22 ,
V_54 ) ;
return V_49 ;
}
V_98 = V_6 -> V_20 [ V_98 ] ;
}
V_98 = F_17 ( V_6 , 0 ) ;
if ( V_98 == V_49 ) {
V_98 = F_24 ( V_6 , V_49 ) ;
if ( V_98 == V_49 ) {
F_4 ( L_40 , V_54 ) ;
V_98 = F_17 ( V_6 , 1 ) ;
}
if ( V_98 == V_49 ) {
F_3 ( V_16 L_41 ) ;
return V_49 ;
}
V_51 = V_49 ;
continue;
}
if ( V_51 != V_49 ) {
V_54 |= 0x8000 ;
} else {
V_6 -> V_21 [ V_54 ] = V_98 ;
}
V_6 -> V_20 [ V_98 ] = V_49 ;
F_12 ( V_4 , V_98 * V_6 -> V_68 + 8 , 8 ,
& V_27 , ( char * ) & V_41 . V_69 ) ;
V_41 . V_69 . V_85 . V_86 = V_41 . V_69 . V_85 . V_87 = F_20 ( V_54 ) ;
F_14 ( V_4 , V_98 * V_6 -> V_68 + 8 , 8 ,
& V_27 , ( char * ) & V_41 . V_69 ) ;
if ( V_51 != V_49 ) {
V_6 -> V_20 [ V_51 ] = V_98 ;
F_12 ( V_4 , ( V_51 * V_6 -> V_68 ) + 8 ,
8 , & V_27 , ( char * ) & V_41 . V_69 ) ;
V_41 . V_69 . V_85 . V_88 = V_41 . V_69 . V_85 . V_89
= F_20 ( V_98 ) ;
F_14 ( V_4 , ( V_51 * V_6 -> V_68 ) + 8 ,
8 , & V_27 , ( char * ) & V_41 . V_69 ) ;
}
return V_98 ;
} while ( V_100 -- );
F_3 ( V_16 L_42 ,
V_54 ) ;
return V_49 ;
}
static int F_27 ( struct V_23 * V_14 , unsigned long V_61 ,
char * V_103 )
{
struct V_5 * V_6 = ( void * ) V_14 ;
T_4 V_98 ;
unsigned long V_99 = ( V_61 * 512 ) & ( V_6 -> V_68 - 1 ) ;
T_2 V_27 ;
struct V_63 V_41 ;
V_98 = F_26 ( V_6 , V_61 ) ;
if ( V_98 == V_49 ) {
F_3 ( V_16
L_43 ) ;
return 1 ;
}
memset ( & V_41 , 0xff , sizeof( struct V_63 ) ) ;
V_41 . V_74 . V_75 = V_41 . V_74 . V_76 = V_78 ;
F_16 ( V_6 -> V_14 . V_4 , ( V_98 * V_6 -> V_68 ) + V_99 ,
512 , & V_27 , ( char * ) V_103 , ( char * ) & V_41 ) ;
return 0 ;
}
static int F_28 ( struct V_23 * V_14 , unsigned long V_61 ,
char * V_103 )
{
struct V_5 * V_6 = ( void * ) V_14 ;
struct V_3 * V_4 = V_6 -> V_14 . V_4 ;
T_4 V_104 ;
T_4 V_60 = V_6 -> V_21 [ V_61 / ( V_6 -> V_68 / 512 ) ] ;
unsigned long V_99 = ( V_61 * 512 ) & ( V_6 -> V_68 - 1 ) ;
unsigned int V_66 ;
int V_46 = V_65 ;
T_2 V_27 ;
struct V_101 V_102 ;
V_104 = V_49 ;
if ( V_60 != V_49 ) {
while ( V_60 < V_6 -> V_47 ) {
if ( F_12 ( V_4 , ( V_60 * V_6 -> V_68 ) +
V_99 , 8 , & V_27 ,
( char * ) & V_102 ) < 0 )
V_66 = V_80 ;
else
V_66 = V_102 . V_75 | V_102 . V_76 ;
switch ( V_66 ) {
case V_77 :
goto V_105;
case V_79 :
V_104 = V_49 ;
break;
case V_78 :
V_104 = V_60 ;
break;
case V_80 :
break;
default:
F_3 ( L_44 ,
V_61 , V_60 , V_66 ) ;
break;
}
if ( ! V_46 -- ) {
F_3 ( V_16 L_45 ,
V_61 / ( V_6 -> V_68 / 512 ) ) ;
return 1 ;
}
V_60 = V_6 -> V_20 [ V_60 ] ;
}
}
V_105:
if ( V_104 == V_49 ) {
memset ( V_103 , 0 , 512 ) ;
} else {
T_1 V_106 = ( V_104 * V_6 -> V_68 ) + V_99 ;
T_2 V_27 ;
int V_33 = F_21 ( V_4 , V_106 , 512 , & V_27 , V_103 ) ;
if ( V_33 < 0 && ! F_22 ( V_33 ) )
return - V_84 ;
}
return 0 ;
}
static int F_29 ( struct V_23 * V_24 , struct V_107 * V_108 )
{
struct V_5 * V_6 = ( void * ) V_24 ;
V_108 -> V_18 = V_6 -> V_18 ;
V_108 -> V_19 = V_6 -> V_19 ;
V_108 -> V_17 = V_6 -> V_17 ;
return 0 ;
}
static int T_5 F_30 ( void )
{
return F_31 ( & V_109 ) ;
}
static void T_6 F_32 ( void )
{
F_33 ( & V_109 ) ;
}
