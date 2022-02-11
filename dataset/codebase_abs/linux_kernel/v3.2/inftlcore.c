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
V_6 = F_4 ( sizeof( * V_6 ) , V_14 ) ;
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
return;
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
struct V_30 V_31 ;
int V_32 ;
V_31 . V_33 = V_34 ;
V_31 . V_35 = V_26 & ( V_4 -> V_36 - 1 ) ;
V_31 . V_37 = V_27 ;
V_31 . V_38 = V_29 ;
V_31 . V_39 = NULL ;
V_32 = V_4 -> V_40 ( V_4 , V_26 & ~ ( V_4 -> V_36 - 1 ) , & V_31 ) ;
* V_28 = V_31 . V_41 ;
return V_32 ;
}
int F_12 ( struct V_3 * V_4 , T_1 V_26 , T_2 V_27 ,
T_2 * V_28 , T_3 * V_29 )
{
struct V_30 V_31 ;
int V_32 ;
V_31 . V_33 = V_34 ;
V_31 . V_35 = V_26 & ( V_4 -> V_36 - 1 ) ;
V_31 . V_37 = V_27 ;
V_31 . V_38 = V_29 ;
V_31 . V_39 = NULL ;
V_32 = V_4 -> V_42 ( V_4 , V_26 & ~ ( V_4 -> V_36 - 1 ) , & V_31 ) ;
* V_28 = V_31 . V_41 ;
return V_32 ;
}
static int F_13 ( struct V_3 * V_4 , T_1 V_26 , T_2 V_27 ,
T_2 * V_28 , T_3 * V_29 , T_3 * V_43 )
{
struct V_30 V_31 ;
int V_32 ;
V_31 . V_33 = V_34 ;
V_31 . V_35 = V_26 ;
V_31 . V_37 = V_4 -> V_44 ;
V_31 . V_38 = V_43 ;
V_31 . V_39 = V_29 ;
V_31 . V_27 = V_27 ;
V_32 = V_4 -> V_42 ( V_4 , V_26 & ~ ( V_4 -> V_36 - 1 ) , & V_31 ) ;
* V_28 = V_31 . V_28 ;
return V_32 ;
}
static T_4 F_14 ( struct V_5 * V_6 , int V_45 )
{
T_4 V_46 = V_6 -> V_47 ;
int V_48 = V_6 -> V_49 ;
F_3 ( L_12 ,
V_6 , V_45 ) ;
if ( ! V_45 && V_6 -> V_50 < 2 ) {
F_3 ( L_13 ,
V_6 -> V_50 ) ;
return V_51 ;
}
do {
if ( V_6 -> V_21 [ V_46 ] == V_52 ) {
V_6 -> V_47 = V_46 ;
return V_46 ;
}
if ( ++ V_46 > V_6 -> V_53 )
V_46 = 0 ;
if ( ! V_48 -- ) {
F_2 ( V_17 L_14
L_15 , 0 , V_6 -> V_47 ) ;
return V_51 ;
}
} while ( V_46 != V_6 -> V_47 );
return V_51 ;
}
static T_4 F_15 ( struct V_5 * V_6 , unsigned V_54 , unsigned V_55 )
{
T_4 V_56 [ V_57 ] ;
unsigned char V_58 [ V_57 ] ;
unsigned int V_59 , V_60 , V_61 ;
struct V_3 * V_4 = V_6 -> V_15 . V_4 ;
int V_62 , V_48 ;
unsigned int V_63 ;
struct V_64 V_43 ;
T_2 V_28 ;
F_3 ( L_16 ,
V_6 , V_54 , V_55 ) ;
memset ( V_56 , 0xff , sizeof( V_56 ) ) ;
memset ( V_58 , 0 , sizeof( V_58 ) ) ;
V_59 = V_63 = V_6 -> V_22 [ V_54 ] ;
if ( V_59 == V_51 ) {
F_2 ( V_17 L_17
L_18 , V_54 ) ;
return V_51 ;
}
V_48 = V_65 ;
while ( V_59 < V_6 -> V_49 ) {
for ( V_62 = 0 ; V_62 < V_6 -> V_66 / V_67 ; V_62 ++ ) {
if ( ( V_56 [ V_62 ] != V_51 ) ||
V_58 [ V_62 ] )
continue;
if ( F_11 ( V_4 , ( V_59 * V_6 -> V_66 )
+ ( V_62 * V_67 ) , 16 , & V_28 ,
( char * ) & V_43 ) < 0 )
V_61 = V_68 ;
else
V_61 = V_43 . V_69 . V_70 | V_43 . V_69 . V_71 ;
switch( V_61 ) {
case V_72 :
case V_68 :
break;
case V_73 :
V_56 [ V_62 ] = V_59 ;
continue;
case V_74 :
V_58 [ V_62 ] = 1 ;
continue;
default:
F_2 ( V_17 L_19
L_20 ,
V_62 , V_59 , V_61 ) ;
break;
}
}
if ( ! V_48 -- ) {
F_2 ( V_17 L_21
L_22 , V_54 ) ;
return V_51 ;
}
V_59 = V_6 -> V_21 [ V_59 ] ;
}
F_3 ( L_23 , V_54 , V_63 ) ;
for ( V_62 = 0 ; V_62 < V_6 -> V_66 / V_67 ; V_62 ++ ) {
unsigned char V_75 [ V_67 ] ;
int V_76 ;
if ( V_56 [ V_62 ] == V_63 || ( V_55 ==
( V_54 * ( V_6 -> V_66 / V_67 ) + V_62 ) ) ) {
continue;
}
if ( V_56 [ V_62 ] == V_51 )
continue;
V_76 = V_4 -> V_77 ( V_4 , ( V_6 -> V_66 * V_56 [ V_62 ] ) +
( V_62 * V_67 ) , V_67 , & V_28 ,
V_75 ) ;
if ( V_76 < 0 && ! F_16 ( V_76 ) ) {
V_76 = V_4 -> V_77 ( V_4 ,
( V_6 -> V_66 * V_56 [ V_62 ] ) +
( V_62 * V_67 ) , V_67 ,
& V_28 , V_75 ) ;
if ( V_76 != - V_78 )
F_3 ( L_24 ) ;
}
memset ( & V_43 , 0xff , sizeof( struct V_64 ) ) ;
V_43 . V_69 . V_70 = V_43 . V_69 . V_71 = V_73 ;
F_13 ( V_6 -> V_15 . V_4 , ( V_6 -> V_66 * V_63 ) +
( V_62 * V_67 ) , V_67 , & V_28 ,
V_75 , ( char * ) & V_43 ) ;
}
F_3 ( L_25 , V_54 ) ;
for (; ; ) {
V_59 = V_6 -> V_22 [ V_54 ] ;
V_60 = V_51 ;
while ( V_6 -> V_21 [ V_59 ] != V_51 ) {
V_60 = V_59 ;
V_59 = V_6 -> V_21 [ V_59 ] ;
}
if ( V_59 == V_63 )
break;
V_6 -> V_21 [ V_60 ] = V_51 ;
if ( F_17 ( V_6 , V_59 ) < 0 ) {
V_6 -> V_21 [ V_59 ] = V_79 ;
} else {
V_6 -> V_21 [ V_59 ] = V_52 ;
V_6 -> V_50 ++ ;
}
}
return V_63 ;
}
static T_4 F_18 ( struct V_5 * V_6 , unsigned V_55 )
{
T_4 V_80 = 0 ;
T_4 V_81 = 0 , V_82 ;
T_4 V_83 , V_84 ;
F_3 ( L_26
L_27 , V_6 , V_55 ) ;
for ( V_83 = 0 ; V_83 < V_6 -> V_49 ; V_83 ++ ) {
V_84 = V_6 -> V_22 [ V_83 ] ;
V_82 = 0 ;
while ( V_84 <= V_6 -> V_53 ) {
V_82 ++ ;
V_84 = V_6 -> V_21 [ V_84 ] ;
if ( V_82 > 0xff00 ) {
F_2 ( V_17 L_28
L_29 ,
V_83 , V_84 ) ;
V_82 = 0 ;
break;
}
}
if ( V_82 > V_81 ) {
V_81 = V_82 ;
V_80 = V_83 ;
}
}
if ( V_81 < 2 ) {
F_2 ( V_17 L_30
L_31 ) ;
return V_51 ;
}
return F_15 ( V_6 , V_80 , V_55 ) ;
}
static int F_19 ( unsigned int V_85 , int V_86 )
{
int V_87 , V_88 = 0 ;
for ( V_87 = 0 ; ( V_87 < V_86 ) ; V_87 ++ )
V_88 += ( ( ( 0x1 << V_87 ) & V_85 ) ? 1 : 0 ) ;
return V_88 ;
}
static inline T_4 F_20 ( struct V_5 * V_6 , unsigned V_62 )
{
unsigned int V_54 = V_62 / ( V_6 -> V_66 / V_67 ) ;
unsigned int V_59 , V_89 , V_90 , V_61 ;
unsigned long V_91 = ( V_62 * V_67 ) & ( V_6 -> V_66 - 1 ) ;
struct V_3 * V_4 = V_6 -> V_15 . V_4 ;
struct V_64 V_43 ;
struct V_92 V_93 ;
unsigned char V_94 , V_95 , V_96 ;
T_2 V_28 ;
int V_48 , V_97 = 3 ;
F_3 ( L_32 ,
V_6 , V_62 ) ;
do {
V_89 = V_51 ;
V_59 = V_6 -> V_22 [ V_54 ] ;
V_48 = V_65 ;
while ( V_59 <= V_6 -> V_53 ) {
F_11 ( V_4 , ( V_59 * V_6 -> V_66 ) +
V_91 , 8 , & V_28 , ( char * ) & V_93 ) ;
V_61 = V_93 . V_70 | V_93 . V_71 ;
F_3 ( L_33 ,
V_62 , V_89 , V_61 ) ;
switch( V_61 ) {
case V_72 :
V_89 = V_59 ;
break;
case V_74 :
case V_73 :
goto V_98;
case V_68 :
break;
default:
break;
}
if ( ! V_48 -- ) {
F_2 ( V_17 L_34
L_35 , V_54 ) ;
return V_51 ;
}
V_59 = V_6 -> V_21 [ V_59 ] ;
}
V_98:
if ( V_89 != V_51 )
return V_89 ;
V_89 = F_14 ( V_6 , 0 ) ;
if ( V_89 == V_51 ) {
V_59 = F_18 ( V_6 , V_62 ) ;
F_3 ( L_36
L_37 ,
V_54 ) ;
V_89 = F_14 ( V_6 , 1 ) ;
if ( V_89 == V_51 ) {
F_2 ( V_17 L_38
L_39 ) ;
#ifdef F_21
F_22 ( V_6 ) ;
F_23 ( V_6 ) ;
#endif
return V_51 ;
}
}
V_94 = 0 ;
V_95 = 0 ;
V_59 = V_6 -> V_22 [ V_54 ] ;
if ( V_59 != V_51 ) {
F_11 ( V_4 , V_59 * V_6 -> V_66
+ 8 , 8 , & V_28 , ( char * ) & V_43 . V_99 ) ;
V_94 = V_43 . V_99 . V_100 . V_101 + 1 ;
V_95 = V_43 . V_99 . V_100 . V_102 + 1 ;
}
V_90 = V_6 -> V_22 [ V_54 ] ;
if ( V_90 < V_6 -> V_49 )
V_90 -= V_6 -> V_103 ;
V_96 = ( F_19 ( V_54 , 16 ) & 0x1 ) ? 0x1 : 0 ;
V_96 |= ( F_19 ( V_90 , 16 ) & 0x1 ) ? 0x2 : 0 ;
V_96 |= ( F_19 ( V_94 , 8 ) & 0x1 ) ? 0x4 : 0 ;
V_96 |= ( F_19 ( V_95 , 8 ) & 0x1 ) ? 0x8 : 0 ;
V_43 . V_99 . V_100 . V_104 = F_24 ( V_54 ) ;
V_43 . V_99 . V_100 . V_105 = F_24 ( V_90 ) ;
V_43 . V_99 . V_100 . V_101 = V_94 ;
V_43 . V_99 . V_100 . V_102 = V_95 ;
V_43 . V_99 . V_100 . V_106 = V_96 ;
V_43 . V_99 . V_100 . V_107 = 0xaa ;
F_12 ( V_4 , V_89 * V_6 -> V_66 + 8 , 8 ,
& V_28 , ( char * ) & V_43 . V_99 ) ;
V_43 . V_99 . V_69 . V_104 = F_24 ( V_54 ) ;
V_43 . V_99 . V_69 . V_105 = F_24 ( V_90 ) ;
V_43 . V_99 . V_69 . V_101 = V_94 ;
V_43 . V_99 . V_69 . V_102 = V_95 ;
V_43 . V_99 . V_69 . V_106 = V_96 ;
V_43 . V_99 . V_69 . V_107 = 0xaa ;
F_12 ( V_4 , V_89 * V_6 -> V_66 +
V_67 * 4 + 8 , 8 , & V_28 , ( char * ) & V_43 . V_99 ) ;
V_6 -> V_21 [ V_89 ] = V_6 -> V_22 [ V_54 ] ;
V_6 -> V_22 [ V_54 ] = V_89 ;
V_6 -> V_50 -- ;
return V_89 ;
} while ( V_97 -- );
F_2 ( V_17 L_40
L_22 , V_54 ) ;
return V_51 ;
}
static void F_25 ( struct V_5 * V_6 , unsigned V_54 )
{
struct V_3 * V_4 = V_6 -> V_15 . V_4 ;
unsigned char V_108 [ V_57 ] ;
unsigned char V_58 [ V_57 ] ;
unsigned int V_59 , V_61 ;
int V_62 , V_48 ;
struct V_92 V_93 ;
T_2 V_28 ;
F_3 ( L_41
L_42 , V_6 , V_54 ) ;
memset ( V_108 , 0 , sizeof( V_108 ) ) ;
memset ( V_58 , 0 , sizeof( V_58 ) ) ;
V_59 = V_6 -> V_22 [ V_54 ] ;
if ( V_59 == V_51 ) {
F_2 ( V_17 L_43
L_18 , V_54 ) ;
return;
}
V_48 = V_65 ;
while ( V_59 < V_6 -> V_49 ) {
for ( V_62 = 0 ; V_62 < V_6 -> V_66 / V_67 ; V_62 ++ ) {
if ( V_108 [ V_62 ] || V_58 [ V_62 ] )
continue;
if ( F_11 ( V_4 , ( V_59 * V_6 -> V_66 )
+ ( V_62 * V_67 ) , 8 , & V_28 ,
( char * ) & V_93 ) < 0 )
V_61 = V_68 ;
else
V_61 = V_93 . V_70 | V_93 . V_71 ;
switch( V_61 ) {
case V_72 :
case V_68 :
break;
case V_73 :
V_108 [ V_62 ] = 1 ;
continue;
case V_74 :
V_58 [ V_62 ] = 1 ;
continue;
default:
F_2 ( V_17 L_19
L_44 ,
V_62 , V_59 , V_61 ) ;
}
}
if ( ! V_48 -- ) {
F_2 ( V_17 L_21
L_22 , V_54 ) ;
return;
}
V_59 = V_6 -> V_21 [ V_59 ] ;
}
for ( V_62 = 0 ; V_62 < V_6 -> V_66 / V_67 ; V_62 ++ )
if ( V_108 [ V_62 ] )
return;
F_3 ( L_45 , V_54 ) ;
for (; ; ) {
T_4 * V_60 = & V_6 -> V_22 [ V_54 ] ;
V_59 = * V_60 ;
if ( V_59 == V_51 ) {
F_3 ( L_46 , V_59 ) ;
return;
}
while ( V_6 -> V_21 [ V_59 ] != V_51 ) {
F_26 ( V_59 >= V_6 -> V_49 ) ;
V_60 = & V_6 -> V_21 [ V_59 ] ;
V_59 = * V_60 ;
}
F_3 ( L_47 ,
V_59 , V_54 ) ;
if ( F_17 ( V_6 , V_59 ) < 0 ) {
V_6 -> V_21 [ V_59 ] = V_79 ;
} else {
V_6 -> V_21 [ V_59 ] = V_52 ;
V_6 -> V_50 ++ ;
}
* V_60 = V_51 ;
F_27 () ;
}
V_6 -> V_22 [ V_54 ] = V_51 ;
}
static int F_28 ( struct V_5 * V_6 , unsigned V_62 )
{
unsigned int V_59 = V_6 -> V_22 [ V_62 / ( V_6 -> V_66 / V_67 ) ] ;
unsigned long V_91 = ( V_62 * V_67 ) & ( V_6 -> V_66 - 1 ) ;
struct V_3 * V_4 = V_6 -> V_15 . V_4 ;
unsigned int V_61 ;
int V_48 = V_65 ;
T_2 V_28 ;
struct V_92 V_93 ;
F_3 ( L_48
L_49 , V_6 , V_62 ) ;
while ( V_59 < V_6 -> V_49 ) {
if ( F_11 ( V_4 , ( V_59 * V_6 -> V_66 ) +
V_91 , 8 , & V_28 , ( char * ) & V_93 ) < 0 )
V_61 = V_68 ;
else
V_61 = V_93 . V_70 | V_93 . V_71 ;
switch ( V_61 ) {
case V_72 :
case V_68 :
break;
case V_74 :
V_59 = V_51 ;
goto V_109;
case V_73 :
goto V_109;
default:
F_2 ( V_17 L_50
L_51 ,
V_62 , V_59 , V_61 ) ;
break;
}
if ( ! V_48 -- ) {
F_2 ( V_17 L_21
L_22 ,
V_62 / ( V_6 -> V_66 / V_67 ) ) ;
return 1 ;
}
V_59 = V_6 -> V_21 [ V_59 ] ;
}
V_109:
if ( V_59 != V_51 ) {
T_1 V_110 = ( V_59 * V_6 -> V_66 ) + V_91 ;
if ( F_11 ( V_4 , V_110 , 8 , & V_28 , ( char * ) & V_93 ) < 0 )
return - V_78 ;
V_93 . V_70 = V_93 . V_71 = V_74 ;
if ( F_12 ( V_4 , V_110 , 8 , & V_28 , ( char * ) & V_93 ) < 0 )
return - V_78 ;
F_25 ( V_6 , V_62 / ( V_6 -> V_66 / V_67 ) ) ;
}
return 0 ;
}
static int F_29 ( struct V_24 * V_15 , unsigned long V_62 ,
char * V_111 )
{
struct V_5 * V_6 = ( void * ) V_15 ;
unsigned int V_89 ;
unsigned long V_91 = ( V_62 * V_67 ) & ( V_6 -> V_66 - 1 ) ;
T_2 V_28 ;
struct V_64 V_43 ;
char * V_112 , * V_113 ;
F_3 ( L_52
L_53 , V_6 , V_62 , V_111 ) ;
V_113 = V_111 + V_67 ;
for ( V_112 = V_111 ; V_112 < V_113 && ! * V_112 ; V_112 ++ )
;
if ( V_112 < V_113 ) {
V_89 = F_20 ( V_6 , V_62 ) ;
if ( V_89 == V_51 ) {
F_2 ( V_17 L_54
L_55 ) ;
return 1 ;
}
memset ( & V_43 , 0xff , sizeof( struct V_64 ) ) ;
V_43 . V_69 . V_70 = V_43 . V_69 . V_71 = V_73 ;
F_13 ( V_6 -> V_15 . V_4 , ( V_89 * V_6 -> V_66 ) +
V_91 , V_67 , & V_28 , ( char * ) V_111 ,
( char * ) & V_43 ) ;
} else {
F_28 ( V_6 , V_62 ) ;
}
return 0 ;
}
static int F_30 ( struct V_24 * V_15 , unsigned long V_62 ,
char * V_111 )
{
struct V_5 * V_6 = ( void * ) V_15 ;
unsigned int V_59 = V_6 -> V_22 [ V_62 / ( V_6 -> V_66 / V_67 ) ] ;
unsigned long V_91 = ( V_62 * V_67 ) & ( V_6 -> V_66 - 1 ) ;
struct V_3 * V_4 = V_6 -> V_15 . V_4 ;
unsigned int V_61 ;
int V_48 = V_65 ;
struct V_92 V_93 ;
T_2 V_28 ;
F_3 ( L_56
L_53 , V_6 , V_62 , V_111 ) ;
while ( V_59 < V_6 -> V_49 ) {
if ( F_11 ( V_4 , ( V_59 * V_6 -> V_66 ) +
V_91 , 8 , & V_28 , ( char * ) & V_93 ) < 0 )
V_61 = V_68 ;
else
V_61 = V_93 . V_70 | V_93 . V_71 ;
switch ( V_61 ) {
case V_74 :
V_59 = V_51 ;
goto V_109;
case V_73 :
goto V_109;
case V_72 :
case V_68 :
break;
default:
F_2 ( V_17 L_50
L_57 ,
V_62 , V_59 , V_61 ) ;
break;
}
if ( ! V_48 -- ) {
F_2 ( V_17 L_34
L_58 ,
V_62 / ( V_6 -> V_66 / V_67 ) ) ;
return 1 ;
}
V_59 = V_6 -> V_21 [ V_59 ] ;
}
V_109:
if ( V_59 == V_51 ) {
memset ( V_111 , 0 , V_67 ) ;
} else {
T_2 V_28 ;
T_1 V_110 = ( V_59 * V_6 -> V_66 ) + V_91 ;
int V_76 = V_4 -> V_77 ( V_4 , V_110 , V_67 , & V_28 , V_111 ) ;
if ( V_76 < 0 && ! F_16 ( V_76 ) )
return - V_78 ;
}
return 0 ;
}
static int F_31 ( struct V_24 * V_25 , struct V_114 * V_115 )
{
struct V_5 * V_6 = ( void * ) V_25 ;
V_115 -> V_19 = V_6 -> V_19 ;
V_115 -> V_20 = V_6 -> V_20 ;
V_115 -> V_18 = V_6 -> V_18 ;
return 0 ;
}
static int T_5 F_32 ( void )
{
return F_33 ( & V_116 ) ;
}
static void T_6 F_34 ( void )
{
F_35 ( & V_116 ) ;
}
