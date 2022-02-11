static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
if ( ! F_2 ( V_4 ) || V_4 -> V_8 > V_9 )
return;
if ( memcmp ( V_4 -> V_10 , L_1 , 10 ) )
return;
F_3 ( L_2 , V_4 -> V_10 ) ;
V_6 = F_4 ( sizeof( struct V_5 ) , V_11 ) ;
if ( ! V_6 )
return;
V_6 -> V_12 . V_4 = V_4 ;
V_6 -> V_12 . V_13 = - 1 ;
V_6 -> V_12 . V_2 = V_2 ;
if ( F_5 ( V_6 ) < 0 ) {
F_6 ( V_14 L_3 ) ;
F_7 ( V_6 ) ;
return;
}
V_6 -> V_15 = 1024 ;
V_6 -> V_16 = 16 ;
V_7 = V_6 -> V_15 * V_6 -> V_16 ;
V_6 -> V_17 = V_6 -> V_12 . V_8 / V_7 ;
if ( V_6 -> V_12 . V_8 % V_7 ) {
V_6 -> V_17 ++ ;
V_7 = V_6 -> V_15 * V_6 -> V_17 ;
V_6 -> V_16 = V_6 -> V_12 . V_8 / V_7 ;
if ( V_6 -> V_12 . V_8 % V_7 ) {
V_6 -> V_16 ++ ;
V_7 = V_6 -> V_16 * V_6 -> V_17 ;
V_6 -> V_15 = V_6 -> V_12 . V_8 / V_7 ;
}
}
if ( V_6 -> V_12 . V_8 != V_6 -> V_16 * V_6 -> V_15 * V_6 -> V_17 ) {
F_6 ( V_14 L_4
L_5 , V_6 -> V_12 . V_8 ) ;
F_6 ( V_14 L_6
L_7 ,
V_6 -> V_15 , V_6 -> V_16 , V_6 -> V_17 ,
( long ) V_6 -> V_15 * ( long ) V_6 -> V_16 *
( long ) V_6 -> V_17 ) ;
}
if ( F_8 ( & V_6 -> V_12 ) ) {
F_7 ( V_6 -> V_18 ) ;
F_7 ( V_6 -> V_19 ) ;
F_7 ( V_6 ) ;
return;
}
#ifdef F_9
F_6 ( V_20 L_8 , V_6 -> V_12 . V_13 + 'a' ) ;
#endif
}
static void F_10 ( struct V_21 * V_22 )
{
struct V_5 * V_6 = ( void * ) V_22 ;
F_3 ( L_9 , V_22 -> V_13 ) ;
F_11 ( V_22 ) ;
F_7 ( V_6 -> V_18 ) ;
F_7 ( V_6 -> V_19 ) ;
}
int F_12 ( struct V_3 * V_4 , T_1 V_23 , T_2 V_24 ,
T_2 * V_25 , T_3 * V_26 )
{
T_1 V_27 = V_4 -> V_28 - 1 ;
struct V_29 V_30 ;
int V_31 ;
V_30 . V_32 = V_33 ;
V_30 . V_34 = V_23 & V_27 ;
V_30 . V_35 = V_24 ;
V_30 . V_36 = V_26 ;
V_30 . V_37 = NULL ;
V_31 = F_13 ( V_4 , V_23 & ~ V_27 , & V_30 ) ;
* V_25 = V_30 . V_38 ;
return V_31 ;
}
int F_14 ( struct V_3 * V_4 , T_1 V_23 , T_2 V_24 ,
T_2 * V_25 , T_3 * V_26 )
{
T_1 V_27 = V_4 -> V_28 - 1 ;
struct V_29 V_30 ;
int V_31 ;
V_30 . V_32 = V_33 ;
V_30 . V_34 = V_23 & V_27 ;
V_30 . V_35 = V_24 ;
V_30 . V_36 = V_26 ;
V_30 . V_37 = NULL ;
V_31 = F_15 ( V_4 , V_23 & ~ V_27 , & V_30 ) ;
* V_25 = V_30 . V_38 ;
return V_31 ;
}
static int F_16 ( struct V_3 * V_4 , T_1 V_23 , T_2 V_24 ,
T_2 * V_25 , T_3 * V_26 , T_3 * V_39 )
{
T_1 V_27 = V_4 -> V_28 - 1 ;
struct V_29 V_30 ;
int V_31 ;
V_30 . V_32 = V_33 ;
V_30 . V_34 = V_23 & V_27 ;
V_30 . V_35 = V_4 -> V_40 ;
V_30 . V_36 = V_39 ;
V_30 . V_37 = V_26 ;
V_30 . V_24 = V_24 ;
V_31 = F_15 ( V_4 , V_23 & ~ V_27 , & V_30 ) ;
* V_25 = V_30 . V_25 ;
return V_31 ;
}
static T_4 F_17 ( struct V_5 * V_6 , int V_41 )
{
T_4 V_42 = V_6 -> V_43 ;
int V_44 = V_6 -> V_45 ;
if ( ! V_41 && V_6 -> V_46 < 2 ) {
F_3 ( L_10 ) ;
return V_47 ;
}
do {
if ( V_6 -> V_18 [ V_42 ] == V_48 ) {
V_6 -> V_43 = V_42 ;
V_6 -> V_46 -- ;
return V_42 ;
}
if ( ++ V_42 > V_6 -> V_49 )
V_42 = F_18 ( V_6 -> V_50 . V_51 ) ;
if ( ! V_44 -- ) {
F_6 ( L_11
L_12 , V_6 -> V_43 ,
F_18 ( V_6 -> V_50 . V_51 ) ) ;
return V_47 ;
}
} while ( V_42 != V_6 -> V_43 );
return V_47 ;
}
static T_4 F_19 ( struct V_5 * V_6 , unsigned V_52 , unsigned V_53 )
{
struct V_3 * V_4 = V_6 -> V_12 . V_4 ;
T_4 V_54 [ V_55 ] ;
unsigned char V_56 [ V_55 ] ;
unsigned char V_57 [ V_55 ] ;
unsigned int V_58 ;
int V_59 ;
int V_44 ;
unsigned int V_60 ;
struct V_61 V_39 ;
int V_62 = 1 ;
T_2 V_25 ;
memset ( V_54 , 0xff , sizeof( V_54 ) ) ;
memset ( V_57 , 0 , sizeof( V_57 ) ) ;
V_58 = V_6 -> V_19 [ V_52 ] ;
if ( V_58 == V_47 ) {
F_6 ( V_14 L_13
L_14 , V_52 ) ;
return V_47 ;
}
V_44 = V_63 ;
V_60 = V_47 ;
while ( V_58 <= V_6 -> V_49 ) {
unsigned int V_64 , V_65 ;
V_60 = V_58 ;
for ( V_59 = 0 ; V_59 < V_6 -> V_66 / 512 ; V_59 ++ ) {
F_12 ( V_4 , ( V_58 * V_6 -> V_66 ) +
( V_59 * 512 ) , 16 , & V_25 ,
( char * ) & V_39 ) ;
if ( V_59 == 2 ) {
V_65 = V_39 . V_67 . V_68 . V_69 | V_39 . V_67 . V_68 . V_70 ;
if ( V_65 == V_71 ) {
F_3 ( L_15 , V_58 ) ;
V_62 = 0 ;
} else {
V_62 = 1 ;
}
}
V_64 = V_39 . V_72 . V_73 | V_39 . V_72 . V_74 ;
V_56 [ V_59 ] = V_64 ;
switch( V_64 ) {
case V_75 :
V_57 [ V_59 ] = 1 ;
break;
case V_76 :
if ( ! V_57 [ V_59 ] )
V_54 [ V_59 ] = V_58 ;
else
F_6 ( V_14
L_16
L_17 ,
V_52 , V_59 ) ;
break;
case V_77 :
if ( ! V_57 [ V_59 ] )
V_54 [ V_59 ] = V_47 ;
else
F_6 ( V_14
L_18
L_17 ,
V_52 , V_59 ) ;
break;
case V_78 :
break;
default:
F_6 ( L_19 ,
V_59 , V_58 , V_64 ) ;
}
}
if ( ! V_44 -- ) {
F_6 ( V_14 L_20 ,
V_52 ) ;
return V_47 ;
}
V_58 = V_6 -> V_18 [ V_58 ] ;
}
if ( V_62 ) {
for ( V_59 = 0 ; V_59 < V_6 -> V_66 / 512 ; V_59 ++ ) {
if ( V_56 [ V_59 ] != V_75 &&
V_54 [ V_59 ] != V_47 &&
V_54 [ V_59 ] != V_60 ) {
F_3 ( L_21
L_22
L_23 ,
V_52 , V_59 , V_56 [ V_59 ] ,
V_54 [ V_59 ] ,
V_54 [ V_59 ] == V_60 ? L_24 : L_25 ,
V_60 ) ;
V_62 = 0 ;
break;
}
}
if ( V_53 >= ( V_52 * ( V_6 -> V_66 / 512 ) ) &&
V_53 < ( ( V_52 + 1 ) * ( V_6 -> V_66 / 512 ) ) &&
V_56 [ V_53 - ( V_52 * ( V_6 -> V_66 / 512 ) ) ] !=
V_75 ) {
F_3 ( L_26
L_27 , V_60 ) ;
V_62 = 0 ;
}
}
if ( ! V_62 ) {
F_3 ( L_28
L_29 , V_52 ) ;
V_60 = F_17 ( V_6 , 1 ) ;
if ( V_60 == V_47 ) {
F_6 ( V_14
L_30 ) ;
return V_47 ;
}
} else {
V_39 . V_67 . V_68 . V_69 = V_39 . V_67 . V_68 . V_70 = F_20 ( V_71 ) ;
V_39 . V_67 . V_68 . V_79 = 0xffffffff ;
F_14 ( V_4 , ( V_6 -> V_66 * V_60 ) + 2 * 512 + 8 ,
8 , & V_25 , ( char * ) & V_39 . V_67 ) ;
}
F_3 ( L_31 , V_52 , V_60 ) ;
for ( V_59 = 0 ; V_59 < V_6 -> V_66 / 512 ; V_59 ++ ) {
unsigned char V_80 [ 512 ] ;
int V_81 ;
if ( V_54 [ V_59 ] == V_60 ||
( V_53 == ( V_52 * ( V_6 -> V_66 / 512 ) + V_59 ) ) ) {
continue;
}
if ( V_54 [ V_59 ] == V_47 )
continue;
V_81 = F_21 ( V_4 ,
( V_6 -> V_66 * V_54 [ V_59 ] ) + ( V_59 * 512 ) ,
512 ,
& V_25 ,
V_80 ) ;
if ( V_81 < 0 && ! F_22 ( V_81 ) ) {
V_81 = F_21 ( V_4 ,
( V_6 -> V_66 * V_54 [ V_59 ] ) + ( V_59 * 512 ) ,
512 ,
& V_25 ,
V_80 ) ;
if ( V_81 != - V_82 )
F_6 ( L_32 ) ;
}
memset ( & V_39 , 0xff , sizeof( struct V_61 ) ) ;
V_39 . V_72 . V_73 = V_39 . V_72 . V_74 = V_76 ;
F_16 ( V_6 -> V_12 . V_4 , ( V_6 -> V_66 * V_60 ) +
( V_59 * 512 ) , 512 , & V_25 , V_80 , ( char * ) & V_39 ) ;
}
V_39 . V_67 . V_83 . V_84 = V_39 . V_67 . V_83 . V_85 = F_20 ( V_52 ) ;
V_39 . V_67 . V_83 . V_86 = V_39 . V_67 . V_83 . V_87 = V_47 ;
F_14 ( V_4 , ( V_6 -> V_66 * V_60 ) + 8 ,
8 , & V_25 , ( char * ) & V_39 . V_67 ) ;
V_58 = V_6 -> V_19 [ V_52 ] ;
F_3 ( L_33 ) ;
while ( V_58 <= V_6 -> V_49 && V_58 != V_60 ) {
unsigned int V_88 ;
V_88 = V_6 -> V_18 [ V_58 ] ;
if ( F_23 ( V_6 , V_58 ) < 0 ) {
V_6 -> V_18 [ V_58 ] = V_89 ;
} else {
V_6 -> V_18 [ V_58 ] = V_48 ;
V_6 -> V_46 ++ ;
}
V_58 = V_88 ;
}
V_6 -> V_18 [ V_60 ] = V_47 ;
V_6 -> V_19 [ V_52 ] = V_60 ;
return V_60 ;
}
static T_4 F_24 ( struct V_5 * V_6 , unsigned V_53 )
{
T_4 V_90 = 0 ;
T_4 V_91 = 0 , V_92 ;
T_4 V_93 , V_94 ;
for ( V_93 = 0 ; V_93 < F_25 ( V_6 -> V_50 . V_95 ) / V_6 -> V_66 ; V_93 ++ ) {
V_94 = V_6 -> V_19 [ V_93 ] ;
V_92 = 0 ;
while ( V_94 <= V_6 -> V_49 ) {
V_92 ++ ;
V_94 = V_6 -> V_18 [ V_94 ] & 0x7fff ;
if ( V_92 > 0xff00 ) {
F_6 ( L_34 ,
V_93 , V_94 ) ;
}
if ( V_92 > 0xff10 ) {
V_92 = 0 ;
break;
}
}
if ( V_92 > V_91 ) {
V_91 = V_92 ;
V_90 = V_93 ;
}
}
if ( V_91 < 2 ) {
F_6 ( V_14 L_35
L_36 ) ;
return V_47 ;
}
return F_19 ( V_6 , V_90 , V_53 ) ;
}
static inline T_4 F_26 ( struct V_5 * V_6 , unsigned V_59 )
{
T_4 V_49 ;
T_4 V_52 = V_59 / ( V_6 -> V_66 / 512 ) ;
struct V_3 * V_4 = V_6 -> V_12 . V_4 ;
unsigned int V_96 ;
unsigned long V_97 = ( V_59 * 512 ) & ( V_6 -> V_66 - 1 ) ;
T_2 V_25 ;
int V_44 , V_98 = 3 ;
struct V_61 V_39 ;
do {
V_49 = V_47 ;
V_96 = V_6 -> V_19 [ V_52 ] ;
V_44 = V_63 ;
while ( V_96 <= V_6 -> V_49 ) {
struct V_99 V_100 ;
T_2 V_25 ;
unsigned int V_64 ;
V_49 = V_96 ;
F_12 ( V_4 ,
( V_96 * V_6 -> V_66 ) + V_97 ,
8 , & V_25 , ( char * ) & V_100 ) ;
F_3 ( L_37 ,
V_59 , V_96 , F_18 ( V_100 . V_73 ) ) ;
V_64 = V_100 . V_73 | V_100 . V_74 ;
switch( V_64 ) {
case V_75 :
return V_96 ;
case V_77 :
case V_76 :
case V_78 :
break;
default:
break;
}
if ( ! V_44 -- ) {
F_6 ( V_14
L_20 ,
V_52 ) ;
return V_47 ;
}
V_96 = V_6 -> V_18 [ V_96 ] ;
}
V_96 = F_17 ( V_6 , 0 ) ;
if ( V_96 == V_47 ) {
V_96 = F_24 ( V_6 , V_47 ) ;
if ( V_96 == V_47 ) {
F_3 ( L_38 , V_52 ) ;
V_96 = F_17 ( V_6 , 1 ) ;
}
if ( V_96 == V_47 ) {
F_6 ( V_14 L_39 ) ;
return V_47 ;
}
V_49 = V_47 ;
continue;
}
if ( V_49 != V_47 ) {
V_52 |= 0x8000 ;
} else {
V_6 -> V_19 [ V_52 ] = V_96 ;
}
V_6 -> V_18 [ V_96 ] = V_47 ;
F_12 ( V_4 , V_96 * V_6 -> V_66 + 8 , 8 ,
& V_25 , ( char * ) & V_39 . V_67 ) ;
V_39 . V_67 . V_83 . V_84 = V_39 . V_67 . V_83 . V_85 = F_20 ( V_52 ) ;
F_14 ( V_4 , V_96 * V_6 -> V_66 + 8 , 8 ,
& V_25 , ( char * ) & V_39 . V_67 ) ;
if ( V_49 != V_47 ) {
V_6 -> V_18 [ V_49 ] = V_96 ;
F_12 ( V_4 , ( V_49 * V_6 -> V_66 ) + 8 ,
8 , & V_25 , ( char * ) & V_39 . V_67 ) ;
V_39 . V_67 . V_83 . V_86 = V_39 . V_67 . V_83 . V_87
= F_20 ( V_96 ) ;
F_14 ( V_4 , ( V_49 * V_6 -> V_66 ) + 8 ,
8 , & V_25 , ( char * ) & V_39 . V_67 ) ;
}
return V_96 ;
} while ( V_98 -- );
F_6 ( V_14 L_40 ,
V_52 ) ;
return V_47 ;
}
static int F_27 ( struct V_21 * V_12 , unsigned long V_59 ,
char * V_101 )
{
struct V_5 * V_6 = ( void * ) V_12 ;
T_4 V_96 ;
unsigned long V_97 = ( V_59 * 512 ) & ( V_6 -> V_66 - 1 ) ;
T_2 V_25 ;
struct V_61 V_39 ;
V_96 = F_26 ( V_6 , V_59 ) ;
if ( V_96 == V_47 ) {
F_6 ( V_14
L_41 ) ;
return 1 ;
}
memset ( & V_39 , 0xff , sizeof( struct V_61 ) ) ;
V_39 . V_72 . V_73 = V_39 . V_72 . V_74 = V_76 ;
F_16 ( V_6 -> V_12 . V_4 , ( V_96 * V_6 -> V_66 ) + V_97 ,
512 , & V_25 , ( char * ) V_101 , ( char * ) & V_39 ) ;
return 0 ;
}
static int F_28 ( struct V_21 * V_12 , unsigned long V_59 ,
char * V_101 )
{
struct V_5 * V_6 = ( void * ) V_12 ;
struct V_3 * V_4 = V_6 -> V_12 . V_4 ;
T_4 V_102 ;
T_4 V_58 = V_6 -> V_19 [ V_59 / ( V_6 -> V_66 / 512 ) ] ;
unsigned long V_97 = ( V_59 * 512 ) & ( V_6 -> V_66 - 1 ) ;
unsigned int V_64 ;
int V_44 = V_63 ;
T_2 V_25 ;
struct V_99 V_100 ;
V_102 = V_47 ;
if ( V_58 != V_47 ) {
while ( V_58 < V_6 -> V_45 ) {
if ( F_12 ( V_4 , ( V_58 * V_6 -> V_66 ) +
V_97 , 8 , & V_25 ,
( char * ) & V_100 ) < 0 )
V_64 = V_78 ;
else
V_64 = V_100 . V_73 | V_100 . V_74 ;
switch ( V_64 ) {
case V_75 :
goto V_103;
case V_77 :
V_102 = V_47 ;
break;
case V_76 :
V_102 = V_58 ;
break;
case V_78 :
break;
default:
F_6 ( L_42 ,
V_59 , V_58 , V_64 ) ;
break;
}
if ( ! V_44 -- ) {
F_6 ( V_14 L_43 ,
V_59 / ( V_6 -> V_66 / 512 ) ) ;
return 1 ;
}
V_58 = V_6 -> V_18 [ V_58 ] ;
}
}
V_103:
if ( V_102 == V_47 ) {
memset ( V_101 , 0 , 512 ) ;
} else {
T_1 V_104 = ( V_102 * V_6 -> V_66 ) + V_97 ;
T_2 V_25 ;
int V_31 = F_21 ( V_4 , V_104 , 512 , & V_25 , V_101 ) ;
if ( V_31 < 0 && ! F_22 ( V_31 ) )
return - V_82 ;
}
return 0 ;
}
static int F_29 ( struct V_21 * V_22 , struct V_105 * V_106 )
{
struct V_5 * V_6 = ( void * ) V_22 ;
V_106 -> V_16 = V_6 -> V_16 ;
V_106 -> V_17 = V_6 -> V_17 ;
V_106 -> V_15 = V_6 -> V_15 ;
return 0 ;
}
static int T_5 F_30 ( void )
{
return F_31 ( & V_107 ) ;
}
static void T_6 F_32 ( void )
{
F_33 ( & V_107 ) ;
}
