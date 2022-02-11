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
V_32 = F_12 ( V_4 , V_26 & ~ ( V_4 -> V_36 - 1 ) , & V_31 ) ;
* V_28 = V_31 . V_40 ;
return V_32 ;
}
int F_13 ( struct V_3 * V_4 , T_1 V_26 , T_2 V_27 ,
T_2 * V_28 , T_3 * V_29 )
{
struct V_30 V_31 ;
int V_32 ;
V_31 . V_33 = V_34 ;
V_31 . V_35 = V_26 & ( V_4 -> V_36 - 1 ) ;
V_31 . V_37 = V_27 ;
V_31 . V_38 = V_29 ;
V_31 . V_39 = NULL ;
V_32 = F_14 ( V_4 , V_26 & ~ ( V_4 -> V_36 - 1 ) , & V_31 ) ;
* V_28 = V_31 . V_40 ;
return V_32 ;
}
static int F_15 ( struct V_3 * V_4 , T_1 V_26 , T_2 V_27 ,
T_2 * V_28 , T_3 * V_29 , T_3 * V_41 )
{
struct V_30 V_31 ;
int V_32 ;
V_31 . V_33 = V_34 ;
V_31 . V_35 = V_26 ;
V_31 . V_37 = V_4 -> V_42 ;
V_31 . V_38 = V_41 ;
V_31 . V_39 = V_29 ;
V_31 . V_27 = V_27 ;
V_32 = F_14 ( V_4 , V_26 & ~ ( V_4 -> V_36 - 1 ) , & V_31 ) ;
* V_28 = V_31 . V_28 ;
return V_32 ;
}
static T_4 F_16 ( struct V_5 * V_6 , int V_43 )
{
T_4 V_44 = V_6 -> V_45 ;
int V_46 = V_6 -> V_47 ;
F_3 ( L_12 ,
V_6 , V_43 ) ;
if ( ! V_43 && V_6 -> V_48 < 2 ) {
F_3 ( L_13 ,
V_6 -> V_48 ) ;
return V_49 ;
}
do {
if ( V_6 -> V_21 [ V_44 ] == V_50 ) {
V_6 -> V_45 = V_44 ;
return V_44 ;
}
if ( ++ V_44 > V_6 -> V_51 )
V_44 = 0 ;
if ( ! V_46 -- ) {
F_2 ( V_17 L_14
L_15 , 0 , V_6 -> V_45 ) ;
return V_49 ;
}
} while ( V_44 != V_6 -> V_45 );
return V_49 ;
}
static T_4 F_17 ( struct V_5 * V_6 , unsigned V_52 , unsigned V_53 )
{
T_4 V_54 [ V_55 ] ;
unsigned char V_56 [ V_55 ] ;
unsigned int V_57 , V_58 , V_59 ;
struct V_3 * V_4 = V_6 -> V_15 . V_4 ;
int V_60 , V_46 ;
unsigned int V_61 ;
struct V_62 V_41 ;
T_2 V_28 ;
F_3 ( L_16 ,
V_6 , V_52 , V_53 ) ;
memset ( V_54 , 0xff , sizeof( V_54 ) ) ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
V_57 = V_61 = V_6 -> V_22 [ V_52 ] ;
if ( V_57 == V_49 ) {
F_2 ( V_17 L_17
L_18 , V_52 ) ;
return V_49 ;
}
V_46 = V_63 ;
while ( V_57 < V_6 -> V_47 ) {
for ( V_60 = 0 ; V_60 < V_6 -> V_64 / V_65 ; V_60 ++ ) {
if ( ( V_54 [ V_60 ] != V_49 ) ||
V_56 [ V_60 ] )
continue;
if ( F_11 ( V_4 , ( V_57 * V_6 -> V_64 )
+ ( V_60 * V_65 ) , 16 , & V_28 ,
( char * ) & V_41 ) < 0 )
V_59 = V_66 ;
else
V_59 = V_41 . V_67 . V_68 | V_41 . V_67 . V_69 ;
switch( V_59 ) {
case V_70 :
case V_66 :
break;
case V_71 :
V_54 [ V_60 ] = V_57 ;
continue;
case V_72 :
V_56 [ V_60 ] = 1 ;
continue;
default:
F_2 ( V_17 L_19
L_20 ,
V_60 , V_57 , V_59 ) ;
break;
}
}
if ( ! V_46 -- ) {
F_2 ( V_17 L_21
L_22 , V_52 ) ;
return V_49 ;
}
V_57 = V_6 -> V_21 [ V_57 ] ;
}
F_3 ( L_23 , V_52 , V_61 ) ;
for ( V_60 = 0 ; V_60 < V_6 -> V_64 / V_65 ; V_60 ++ ) {
unsigned char V_73 [ V_65 ] ;
int V_74 ;
if ( V_54 [ V_60 ] == V_61 || ( V_53 ==
( V_52 * ( V_6 -> V_64 / V_65 ) + V_60 ) ) ) {
continue;
}
if ( V_54 [ V_60 ] == V_49 )
continue;
V_74 = F_18 ( V_4 ,
( V_6 -> V_64 * V_54 [ V_60 ] ) + ( V_60 * V_65 ) ,
V_65 ,
& V_28 ,
V_73 ) ;
if ( V_74 < 0 && ! F_19 ( V_74 ) ) {
V_74 = F_18 ( V_4 ,
( V_6 -> V_64 * V_54 [ V_60 ] ) + ( V_60 * V_65 ) ,
V_65 ,
& V_28 ,
V_73 ) ;
if ( V_74 != - V_75 )
F_3 ( L_24 ) ;
}
memset ( & V_41 , 0xff , sizeof( struct V_62 ) ) ;
V_41 . V_67 . V_68 = V_41 . V_67 . V_69 = V_71 ;
F_15 ( V_6 -> V_15 . V_4 , ( V_6 -> V_64 * V_61 ) +
( V_60 * V_65 ) , V_65 , & V_28 ,
V_73 , ( char * ) & V_41 ) ;
}
F_3 ( L_25 , V_52 ) ;
for (; ; ) {
V_57 = V_6 -> V_22 [ V_52 ] ;
V_58 = V_49 ;
while ( V_6 -> V_21 [ V_57 ] != V_49 ) {
V_58 = V_57 ;
V_57 = V_6 -> V_21 [ V_57 ] ;
}
if ( V_57 == V_61 )
break;
V_6 -> V_21 [ V_58 ] = V_49 ;
if ( F_20 ( V_6 , V_57 ) < 0 ) {
V_6 -> V_21 [ V_57 ] = V_76 ;
} else {
V_6 -> V_21 [ V_57 ] = V_50 ;
V_6 -> V_48 ++ ;
}
}
return V_61 ;
}
static T_4 F_21 ( struct V_5 * V_6 , unsigned V_53 )
{
T_4 V_77 = 0 ;
T_4 V_78 = 0 , V_79 ;
T_4 V_80 , V_81 ;
F_3 ( L_26
L_27 , V_6 , V_53 ) ;
for ( V_80 = 0 ; V_80 < V_6 -> V_47 ; V_80 ++ ) {
V_81 = V_6 -> V_22 [ V_80 ] ;
V_79 = 0 ;
while ( V_81 <= V_6 -> V_51 ) {
V_79 ++ ;
V_81 = V_6 -> V_21 [ V_81 ] ;
if ( V_79 > 0xff00 ) {
F_2 ( V_17 L_28
L_29 ,
V_80 , V_81 ) ;
V_79 = 0 ;
break;
}
}
if ( V_79 > V_78 ) {
V_78 = V_79 ;
V_77 = V_80 ;
}
}
if ( V_78 < 2 ) {
F_2 ( V_17 L_30
L_31 ) ;
return V_49 ;
}
return F_17 ( V_6 , V_77 , V_53 ) ;
}
static int F_22 ( unsigned int V_82 , int V_83 )
{
int V_84 , V_85 = 0 ;
for ( V_84 = 0 ; ( V_84 < V_83 ) ; V_84 ++ )
V_85 += ( ( ( 0x1 << V_84 ) & V_82 ) ? 1 : 0 ) ;
return V_85 ;
}
static inline T_4 F_23 ( struct V_5 * V_6 , unsigned V_60 )
{
unsigned int V_52 = V_60 / ( V_6 -> V_64 / V_65 ) ;
unsigned int V_57 , V_86 , V_87 , V_59 ;
unsigned long V_88 = ( V_60 * V_65 ) & ( V_6 -> V_64 - 1 ) ;
struct V_3 * V_4 = V_6 -> V_15 . V_4 ;
struct V_62 V_41 ;
struct V_89 V_90 ;
unsigned char V_91 , V_92 , V_93 ;
T_2 V_28 ;
int V_46 , V_94 = 3 ;
F_3 ( L_32 ,
V_6 , V_60 ) ;
do {
V_86 = V_49 ;
V_57 = V_6 -> V_22 [ V_52 ] ;
V_46 = V_63 ;
while ( V_57 <= V_6 -> V_51 ) {
F_11 ( V_4 , ( V_57 * V_6 -> V_64 ) +
V_88 , 8 , & V_28 , ( char * ) & V_90 ) ;
V_59 = V_90 . V_68 | V_90 . V_69 ;
F_3 ( L_33 ,
V_60 , V_86 , V_59 ) ;
switch( V_59 ) {
case V_70 :
V_86 = V_57 ;
break;
case V_72 :
case V_71 :
goto V_95;
case V_66 :
break;
default:
break;
}
if ( ! V_46 -- ) {
F_2 ( V_17 L_34
L_35 , V_52 ) ;
return V_49 ;
}
V_57 = V_6 -> V_21 [ V_57 ] ;
}
V_95:
if ( V_86 != V_49 )
return V_86 ;
V_86 = F_16 ( V_6 , 0 ) ;
if ( V_86 == V_49 ) {
V_57 = F_21 ( V_6 , V_60 ) ;
F_3 ( L_36
L_37 ,
V_52 ) ;
V_86 = F_16 ( V_6 , 1 ) ;
if ( V_86 == V_49 ) {
F_2 ( V_17 L_38
L_39 ) ;
#ifdef F_24
F_25 ( V_6 ) ;
F_26 ( V_6 ) ;
#endif
return V_49 ;
}
}
V_91 = 0 ;
V_92 = 0 ;
V_57 = V_6 -> V_22 [ V_52 ] ;
if ( V_57 != V_49 ) {
F_11 ( V_4 , V_57 * V_6 -> V_64
+ 8 , 8 , & V_28 , ( char * ) & V_41 . V_96 ) ;
V_91 = V_41 . V_96 . V_97 . V_98 + 1 ;
V_92 = V_41 . V_96 . V_97 . V_99 + 1 ;
}
V_87 = V_6 -> V_22 [ V_52 ] ;
if ( V_87 < V_6 -> V_47 )
V_87 -= V_6 -> V_100 ;
V_93 = ( F_22 ( V_52 , 16 ) & 0x1 ) ? 0x1 : 0 ;
V_93 |= ( F_22 ( V_87 , 16 ) & 0x1 ) ? 0x2 : 0 ;
V_93 |= ( F_22 ( V_91 , 8 ) & 0x1 ) ? 0x4 : 0 ;
V_93 |= ( F_22 ( V_92 , 8 ) & 0x1 ) ? 0x8 : 0 ;
V_41 . V_96 . V_97 . V_101 = F_27 ( V_52 ) ;
V_41 . V_96 . V_97 . V_102 = F_27 ( V_87 ) ;
V_41 . V_96 . V_97 . V_98 = V_91 ;
V_41 . V_96 . V_97 . V_99 = V_92 ;
V_41 . V_96 . V_97 . V_103 = V_93 ;
V_41 . V_96 . V_97 . V_104 = 0xaa ;
F_13 ( V_4 , V_86 * V_6 -> V_64 + 8 , 8 ,
& V_28 , ( char * ) & V_41 . V_96 ) ;
V_41 . V_96 . V_67 . V_101 = F_27 ( V_52 ) ;
V_41 . V_96 . V_67 . V_102 = F_27 ( V_87 ) ;
V_41 . V_96 . V_67 . V_98 = V_91 ;
V_41 . V_96 . V_67 . V_99 = V_92 ;
V_41 . V_96 . V_67 . V_103 = V_93 ;
V_41 . V_96 . V_67 . V_104 = 0xaa ;
F_13 ( V_4 , V_86 * V_6 -> V_64 +
V_65 * 4 + 8 , 8 , & V_28 , ( char * ) & V_41 . V_96 ) ;
V_6 -> V_21 [ V_86 ] = V_6 -> V_22 [ V_52 ] ;
V_6 -> V_22 [ V_52 ] = V_86 ;
V_6 -> V_48 -- ;
return V_86 ;
} while ( V_94 -- );
F_2 ( V_17 L_40
L_22 , V_52 ) ;
return V_49 ;
}
static void F_28 ( struct V_5 * V_6 , unsigned V_52 )
{
struct V_3 * V_4 = V_6 -> V_15 . V_4 ;
unsigned char V_105 [ V_55 ] ;
unsigned char V_56 [ V_55 ] ;
unsigned int V_57 , V_59 ;
int V_60 , V_46 ;
struct V_89 V_90 ;
T_2 V_28 ;
F_3 ( L_41
L_42 , V_6 , V_52 ) ;
memset ( V_105 , 0 , sizeof( V_105 ) ) ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
V_57 = V_6 -> V_22 [ V_52 ] ;
if ( V_57 == V_49 ) {
F_2 ( V_17 L_43
L_18 , V_52 ) ;
return;
}
V_46 = V_63 ;
while ( V_57 < V_6 -> V_47 ) {
for ( V_60 = 0 ; V_60 < V_6 -> V_64 / V_65 ; V_60 ++ ) {
if ( V_105 [ V_60 ] || V_56 [ V_60 ] )
continue;
if ( F_11 ( V_4 , ( V_57 * V_6 -> V_64 )
+ ( V_60 * V_65 ) , 8 , & V_28 ,
( char * ) & V_90 ) < 0 )
V_59 = V_66 ;
else
V_59 = V_90 . V_68 | V_90 . V_69 ;
switch( V_59 ) {
case V_70 :
case V_66 :
break;
case V_71 :
V_105 [ V_60 ] = 1 ;
continue;
case V_72 :
V_56 [ V_60 ] = 1 ;
continue;
default:
F_2 ( V_17 L_19
L_44 ,
V_60 , V_57 , V_59 ) ;
}
}
if ( ! V_46 -- ) {
F_2 ( V_17 L_21
L_22 , V_52 ) ;
return;
}
V_57 = V_6 -> V_21 [ V_57 ] ;
}
for ( V_60 = 0 ; V_60 < V_6 -> V_64 / V_65 ; V_60 ++ )
if ( V_105 [ V_60 ] )
return;
F_3 ( L_45 , V_52 ) ;
for (; ; ) {
T_4 * V_58 = & V_6 -> V_22 [ V_52 ] ;
V_57 = * V_58 ;
if ( V_57 == V_49 ) {
F_3 ( L_46 , V_57 ) ;
return;
}
while ( V_6 -> V_21 [ V_57 ] != V_49 ) {
F_29 ( V_57 >= V_6 -> V_47 ) ;
V_58 = & V_6 -> V_21 [ V_57 ] ;
V_57 = * V_58 ;
}
F_3 ( L_47 ,
V_57 , V_52 ) ;
if ( F_20 ( V_6 , V_57 ) < 0 ) {
V_6 -> V_21 [ V_57 ] = V_76 ;
} else {
V_6 -> V_21 [ V_57 ] = V_50 ;
V_6 -> V_48 ++ ;
}
* V_58 = V_49 ;
F_30 () ;
}
V_6 -> V_22 [ V_52 ] = V_49 ;
}
static int F_31 ( struct V_5 * V_6 , unsigned V_60 )
{
unsigned int V_57 = V_6 -> V_22 [ V_60 / ( V_6 -> V_64 / V_65 ) ] ;
unsigned long V_88 = ( V_60 * V_65 ) & ( V_6 -> V_64 - 1 ) ;
struct V_3 * V_4 = V_6 -> V_15 . V_4 ;
unsigned int V_59 ;
int V_46 = V_63 ;
T_2 V_28 ;
struct V_89 V_90 ;
F_3 ( L_48
L_49 , V_6 , V_60 ) ;
while ( V_57 < V_6 -> V_47 ) {
if ( F_11 ( V_4 , ( V_57 * V_6 -> V_64 ) +
V_88 , 8 , & V_28 , ( char * ) & V_90 ) < 0 )
V_59 = V_66 ;
else
V_59 = V_90 . V_68 | V_90 . V_69 ;
switch ( V_59 ) {
case V_70 :
case V_66 :
break;
case V_72 :
V_57 = V_49 ;
goto V_106;
case V_71 :
goto V_106;
default:
F_2 ( V_17 L_50
L_51 ,
V_60 , V_57 , V_59 ) ;
break;
}
if ( ! V_46 -- ) {
F_2 ( V_17 L_21
L_22 ,
V_60 / ( V_6 -> V_64 / V_65 ) ) ;
return 1 ;
}
V_57 = V_6 -> V_21 [ V_57 ] ;
}
V_106:
if ( V_57 != V_49 ) {
T_1 V_107 = ( V_57 * V_6 -> V_64 ) + V_88 ;
if ( F_11 ( V_4 , V_107 , 8 , & V_28 , ( char * ) & V_90 ) < 0 )
return - V_75 ;
V_90 . V_68 = V_90 . V_69 = V_72 ;
if ( F_13 ( V_4 , V_107 , 8 , & V_28 , ( char * ) & V_90 ) < 0 )
return - V_75 ;
F_28 ( V_6 , V_60 / ( V_6 -> V_64 / V_65 ) ) ;
}
return 0 ;
}
static int F_32 ( struct V_24 * V_15 , unsigned long V_60 ,
char * V_108 )
{
struct V_5 * V_6 = ( void * ) V_15 ;
unsigned int V_86 ;
unsigned long V_88 = ( V_60 * V_65 ) & ( V_6 -> V_64 - 1 ) ;
T_2 V_28 ;
struct V_62 V_41 ;
char * V_109 , * V_110 ;
F_3 ( L_52
L_53 , V_6 , V_60 , V_108 ) ;
V_110 = V_108 + V_65 ;
for ( V_109 = V_108 ; V_109 < V_110 && ! * V_109 ; V_109 ++ )
;
if ( V_109 < V_110 ) {
V_86 = F_23 ( V_6 , V_60 ) ;
if ( V_86 == V_49 ) {
F_2 ( V_17 L_54
L_55 ) ;
return 1 ;
}
memset ( & V_41 , 0xff , sizeof( struct V_62 ) ) ;
V_41 . V_67 . V_68 = V_41 . V_67 . V_69 = V_71 ;
F_15 ( V_6 -> V_15 . V_4 , ( V_86 * V_6 -> V_64 ) +
V_88 , V_65 , & V_28 , ( char * ) V_108 ,
( char * ) & V_41 ) ;
} else {
F_31 ( V_6 , V_60 ) ;
}
return 0 ;
}
static int F_33 ( struct V_24 * V_15 , unsigned long V_60 ,
char * V_108 )
{
struct V_5 * V_6 = ( void * ) V_15 ;
unsigned int V_57 = V_6 -> V_22 [ V_60 / ( V_6 -> V_64 / V_65 ) ] ;
unsigned long V_88 = ( V_60 * V_65 ) & ( V_6 -> V_64 - 1 ) ;
struct V_3 * V_4 = V_6 -> V_15 . V_4 ;
unsigned int V_59 ;
int V_46 = V_63 ;
struct V_89 V_90 ;
T_2 V_28 ;
F_3 ( L_56
L_53 , V_6 , V_60 , V_108 ) ;
while ( V_57 < V_6 -> V_47 ) {
if ( F_11 ( V_4 , ( V_57 * V_6 -> V_64 ) +
V_88 , 8 , & V_28 , ( char * ) & V_90 ) < 0 )
V_59 = V_66 ;
else
V_59 = V_90 . V_68 | V_90 . V_69 ;
switch ( V_59 ) {
case V_72 :
V_57 = V_49 ;
goto V_106;
case V_71 :
goto V_106;
case V_70 :
case V_66 :
break;
default:
F_2 ( V_17 L_50
L_57 ,
V_60 , V_57 , V_59 ) ;
break;
}
if ( ! V_46 -- ) {
F_2 ( V_17 L_34
L_58 ,
V_60 / ( V_6 -> V_64 / V_65 ) ) ;
return 1 ;
}
V_57 = V_6 -> V_21 [ V_57 ] ;
}
V_106:
if ( V_57 == V_49 ) {
memset ( V_108 , 0 , V_65 ) ;
} else {
T_2 V_28 ;
T_1 V_107 = ( V_57 * V_6 -> V_64 ) + V_88 ;
int V_74 = F_18 ( V_4 , V_107 , V_65 , & V_28 , V_108 ) ;
if ( V_74 < 0 && ! F_19 ( V_74 ) )
return - V_75 ;
}
return 0 ;
}
static int F_34 ( struct V_24 * V_25 , struct V_111 * V_112 )
{
struct V_5 * V_6 = ( void * ) V_25 ;
V_112 -> V_19 = V_6 -> V_19 ;
V_112 -> V_20 = V_6 -> V_20 ;
V_112 -> V_18 = V_6 -> V_18 ;
return 0 ;
}
static int T_5 F_35 ( void )
{
return F_36 ( & V_113 ) ;
}
static void T_6 F_37 ( void )
{
F_38 ( & V_113 ) ;
}
