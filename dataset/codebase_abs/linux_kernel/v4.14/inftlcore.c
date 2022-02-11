static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
if ( ! F_2 ( V_4 ) || V_4 -> V_8 > V_9 )
return;
if ( memcmp ( V_4 -> V_10 , L_1 , 10 ) )
return;
if ( ! V_4 -> V_11 ) {
F_3 ( V_12
L_2
L_3 ) ;
return;
}
F_4 ( L_4 , V_4 -> V_10 ) ;
V_6 = F_5 ( sizeof( * V_6 ) , V_13 ) ;
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
V_6 -> V_19 = V_6 -> V_14 . V_8 / V_7 ;
if ( V_6 -> V_14 . V_8 % V_7 ) {
V_6 -> V_19 ++ ;
V_7 = V_6 -> V_17 * V_6 -> V_19 ;
V_6 -> V_18 = V_6 -> V_14 . V_8 / V_7 ;
if ( V_6 -> V_14 . V_8 % V_7 ) {
V_6 -> V_18 ++ ;
V_7 = V_6 -> V_18 * V_6 -> V_19 ;
V_6 -> V_17 = V_6 -> V_14 . V_8 / V_7 ;
}
}
if ( V_6 -> V_14 . V_8 != V_6 -> V_18 * V_6 -> V_17 * V_6 -> V_19 ) {
F_3 ( V_16 L_6
L_7 , V_6 -> V_14 . V_8 ) ;
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
return;
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
struct V_29 V_30 ;
int V_31 ;
V_30 . V_32 = V_33 ;
V_30 . V_34 = V_25 & ( V_4 -> V_35 - 1 ) ;
V_30 . V_36 = V_26 ;
V_30 . V_37 = V_28 ;
V_30 . V_38 = NULL ;
V_31 = F_13 ( V_4 , V_25 & ~ ( V_4 -> V_35 - 1 ) , & V_30 ) ;
* V_27 = V_30 . V_39 ;
return V_31 ;
}
int F_14 ( struct V_3 * V_4 , T_1 V_25 , T_2 V_26 ,
T_2 * V_27 , T_3 * V_28 )
{
struct V_29 V_30 ;
int V_31 ;
V_30 . V_32 = V_33 ;
V_30 . V_34 = V_25 & ( V_4 -> V_35 - 1 ) ;
V_30 . V_36 = V_26 ;
V_30 . V_37 = V_28 ;
V_30 . V_38 = NULL ;
V_31 = F_15 ( V_4 , V_25 & ~ ( V_4 -> V_35 - 1 ) , & V_30 ) ;
* V_27 = V_30 . V_39 ;
return V_31 ;
}
static int F_16 ( struct V_3 * V_4 , T_1 V_25 , T_2 V_26 ,
T_2 * V_27 , T_3 * V_28 , T_3 * V_40 )
{
struct V_29 V_30 ;
int V_31 ;
V_30 . V_32 = V_33 ;
V_30 . V_34 = V_25 ;
V_30 . V_36 = V_4 -> V_41 ;
V_30 . V_37 = V_40 ;
V_30 . V_38 = V_28 ;
V_30 . V_26 = V_26 ;
V_31 = F_15 ( V_4 , V_25 & ~ ( V_4 -> V_35 - 1 ) , & V_30 ) ;
* V_27 = V_30 . V_27 ;
return V_31 ;
}
static T_4 F_17 ( struct V_5 * V_6 , int V_42 )
{
T_4 V_43 = V_6 -> V_44 ;
int V_45 = V_6 -> V_46 ;
F_4 ( L_12 ,
V_6 , V_42 ) ;
if ( ! V_42 && V_6 -> V_47 < 2 ) {
F_4 ( L_13 ,
V_6 -> V_47 ) ;
return V_48 ;
}
do {
if ( V_6 -> V_20 [ V_43 ] == V_49 ) {
V_6 -> V_44 = V_43 ;
return V_43 ;
}
if ( ++ V_43 > V_6 -> V_50 )
V_43 = 0 ;
if ( ! V_45 -- ) {
F_3 ( V_16 L_14
L_15 , 0 , V_6 -> V_44 ) ;
return V_48 ;
}
} while ( V_43 != V_6 -> V_44 );
return V_48 ;
}
static T_4 F_18 ( struct V_5 * V_6 , unsigned V_51 , unsigned V_52 )
{
T_4 V_53 [ V_54 ] ;
unsigned char V_55 [ V_54 ] ;
unsigned int V_56 , V_57 , V_58 ;
struct V_3 * V_4 = V_6 -> V_14 . V_4 ;
int V_59 , V_45 ;
unsigned int V_60 ;
struct V_61 V_40 ;
T_2 V_27 ;
F_4 ( L_16 ,
V_6 , V_51 , V_52 ) ;
memset ( V_53 , 0xff , sizeof( V_53 ) ) ;
memset ( V_55 , 0 , sizeof( V_55 ) ) ;
V_56 = V_60 = V_6 -> V_21 [ V_51 ] ;
if ( V_56 == V_48 ) {
F_3 ( V_16 L_17
L_18 , V_51 ) ;
return V_48 ;
}
V_45 = V_62 ;
while ( V_56 < V_6 -> V_46 ) {
for ( V_59 = 0 ; V_59 < V_6 -> V_63 / V_64 ; V_59 ++ ) {
if ( ( V_53 [ V_59 ] != V_48 ) ||
V_55 [ V_59 ] )
continue;
if ( F_12 ( V_4 , ( V_56 * V_6 -> V_63 )
+ ( V_59 * V_64 ) , 16 , & V_27 ,
( char * ) & V_40 ) < 0 )
V_58 = V_65 ;
else
V_58 = V_40 . V_66 . V_67 | V_40 . V_66 . V_68 ;
switch( V_58 ) {
case V_69 :
case V_65 :
break;
case V_70 :
V_53 [ V_59 ] = V_56 ;
continue;
case V_71 :
V_55 [ V_59 ] = 1 ;
continue;
default:
F_3 ( V_16 L_19
L_20 ,
V_59 , V_56 , V_58 ) ;
break;
}
}
if ( ! V_45 -- ) {
F_3 ( V_16 L_21
L_22 , V_51 ) ;
return V_48 ;
}
V_56 = V_6 -> V_20 [ V_56 ] ;
}
F_4 ( L_23 , V_51 , V_60 ) ;
for ( V_59 = 0 ; V_59 < V_6 -> V_63 / V_64 ; V_59 ++ ) {
unsigned char V_72 [ V_64 ] ;
int V_73 ;
if ( V_53 [ V_59 ] == V_60 || ( V_52 ==
( V_51 * ( V_6 -> V_63 / V_64 ) + V_59 ) ) ) {
continue;
}
if ( V_53 [ V_59 ] == V_48 )
continue;
V_73 = F_19 ( V_4 ,
( V_6 -> V_63 * V_53 [ V_59 ] ) + ( V_59 * V_64 ) ,
V_64 ,
& V_27 ,
V_72 ) ;
if ( V_73 < 0 && ! F_20 ( V_73 ) ) {
V_73 = F_19 ( V_4 ,
( V_6 -> V_63 * V_53 [ V_59 ] ) + ( V_59 * V_64 ) ,
V_64 ,
& V_27 ,
V_72 ) ;
if ( V_73 != - V_74 )
F_4 ( L_24 ) ;
}
memset ( & V_40 , 0xff , sizeof( struct V_61 ) ) ;
V_40 . V_66 . V_67 = V_40 . V_66 . V_68 = V_70 ;
F_16 ( V_6 -> V_14 . V_4 , ( V_6 -> V_63 * V_60 ) +
( V_59 * V_64 ) , V_64 , & V_27 ,
V_72 , ( char * ) & V_40 ) ;
}
F_4 ( L_25 , V_51 ) ;
for (; ; ) {
V_56 = V_6 -> V_21 [ V_51 ] ;
V_57 = V_48 ;
while ( V_6 -> V_20 [ V_56 ] != V_48 ) {
V_57 = V_56 ;
V_56 = V_6 -> V_20 [ V_56 ] ;
}
if ( V_56 == V_60 )
break;
V_6 -> V_20 [ V_57 ] = V_48 ;
if ( F_21 ( V_6 , V_56 ) < 0 ) {
V_6 -> V_20 [ V_56 ] = V_75 ;
} else {
V_6 -> V_20 [ V_56 ] = V_49 ;
V_6 -> V_47 ++ ;
}
}
return V_60 ;
}
static T_4 F_22 ( struct V_5 * V_6 , unsigned V_52 )
{
T_4 V_76 = 0 ;
T_4 V_77 = 0 , V_78 ;
T_4 V_79 , V_80 ;
F_4 ( L_26
L_27 , V_6 , V_52 ) ;
for ( V_79 = 0 ; V_79 < V_6 -> V_46 ; V_79 ++ ) {
V_80 = V_6 -> V_21 [ V_79 ] ;
V_78 = 0 ;
while ( V_80 <= V_6 -> V_50 ) {
V_78 ++ ;
V_80 = V_6 -> V_20 [ V_80 ] ;
if ( V_78 > 0xff00 ) {
F_3 ( V_16 L_28
L_29 ,
V_79 , V_80 ) ;
V_78 = 0 ;
break;
}
}
if ( V_78 > V_77 ) {
V_77 = V_78 ;
V_76 = V_79 ;
}
}
if ( V_77 < 2 ) {
F_3 ( V_16 L_30
L_31 ) ;
return V_48 ;
}
return F_18 ( V_6 , V_76 , V_52 ) ;
}
static int F_23 ( unsigned int V_81 , int V_82 )
{
int V_83 , V_84 = 0 ;
for ( V_83 = 0 ; ( V_83 < V_82 ) ; V_83 ++ )
V_84 += ( ( ( 0x1 << V_83 ) & V_81 ) ? 1 : 0 ) ;
return V_84 ;
}
static inline T_4 F_24 ( struct V_5 * V_6 , unsigned V_59 )
{
unsigned int V_51 = V_59 / ( V_6 -> V_63 / V_64 ) ;
unsigned int V_56 , V_85 , V_86 , V_58 ;
unsigned long V_87 = ( V_59 * V_64 ) & ( V_6 -> V_63 - 1 ) ;
struct V_3 * V_4 = V_6 -> V_14 . V_4 ;
struct V_61 V_40 ;
struct V_88 V_89 ;
unsigned char V_90 , V_91 , V_92 ;
T_2 V_27 ;
int V_45 , V_93 = 3 ;
F_4 ( L_32 ,
V_6 , V_59 ) ;
do {
V_85 = V_48 ;
V_56 = V_6 -> V_21 [ V_51 ] ;
V_45 = V_62 ;
while ( V_56 <= V_6 -> V_50 ) {
F_12 ( V_4 , ( V_56 * V_6 -> V_63 ) +
V_87 , 8 , & V_27 , ( char * ) & V_89 ) ;
V_58 = V_89 . V_67 | V_89 . V_68 ;
F_4 ( L_33 ,
V_59 , V_85 , V_58 ) ;
switch( V_58 ) {
case V_69 :
V_85 = V_56 ;
break;
case V_71 :
case V_70 :
goto V_94;
case V_65 :
break;
default:
break;
}
if ( ! V_45 -- ) {
F_3 ( V_16 L_34
L_35 , V_51 ) ;
return V_48 ;
}
V_56 = V_6 -> V_20 [ V_56 ] ;
}
V_94:
if ( V_85 != V_48 )
return V_85 ;
V_85 = F_17 ( V_6 , 0 ) ;
if ( V_85 == V_48 ) {
V_56 = F_22 ( V_6 , V_59 ) ;
F_4 ( L_36
L_37 ,
V_51 ) ;
V_85 = F_17 ( V_6 , 1 ) ;
if ( V_85 == V_48 ) {
F_3 ( V_16 L_38
L_39 ) ;
#ifdef F_25
F_26 ( V_6 ) ;
F_27 ( V_6 ) ;
#endif
return V_48 ;
}
}
V_90 = 0 ;
V_91 = 0 ;
V_56 = V_6 -> V_21 [ V_51 ] ;
if ( V_56 != V_48 ) {
F_12 ( V_4 , V_56 * V_6 -> V_63
+ 8 , 8 , & V_27 , ( char * ) & V_40 . V_95 ) ;
V_90 = V_40 . V_95 . V_96 . V_97 + 1 ;
V_91 = V_40 . V_95 . V_96 . V_98 + 1 ;
}
V_86 = V_6 -> V_21 [ V_51 ] ;
if ( V_86 < V_6 -> V_46 )
V_86 -= V_6 -> V_99 ;
V_92 = ( F_23 ( V_51 , 16 ) & 0x1 ) ? 0x1 : 0 ;
V_92 |= ( F_23 ( V_86 , 16 ) & 0x1 ) ? 0x2 : 0 ;
V_92 |= ( F_23 ( V_90 , 8 ) & 0x1 ) ? 0x4 : 0 ;
V_92 |= ( F_23 ( V_91 , 8 ) & 0x1 ) ? 0x8 : 0 ;
V_40 . V_95 . V_96 . V_100 = F_28 ( V_51 ) ;
V_40 . V_95 . V_96 . V_101 = F_28 ( V_86 ) ;
V_40 . V_95 . V_96 . V_97 = V_90 ;
V_40 . V_95 . V_96 . V_98 = V_91 ;
V_40 . V_95 . V_96 . V_102 = V_92 ;
V_40 . V_95 . V_96 . V_103 = 0xaa ;
F_14 ( V_4 , V_85 * V_6 -> V_63 + 8 , 8 ,
& V_27 , ( char * ) & V_40 . V_95 ) ;
V_40 . V_95 . V_66 . V_100 = F_28 ( V_51 ) ;
V_40 . V_95 . V_66 . V_101 = F_28 ( V_86 ) ;
V_40 . V_95 . V_66 . V_97 = V_90 ;
V_40 . V_95 . V_66 . V_98 = V_91 ;
V_40 . V_95 . V_66 . V_102 = V_92 ;
V_40 . V_95 . V_66 . V_103 = 0xaa ;
F_14 ( V_4 , V_85 * V_6 -> V_63 +
V_64 * 4 + 8 , 8 , & V_27 , ( char * ) & V_40 . V_95 ) ;
V_6 -> V_20 [ V_85 ] = V_6 -> V_21 [ V_51 ] ;
V_6 -> V_21 [ V_51 ] = V_85 ;
V_6 -> V_47 -- ;
return V_85 ;
} while ( V_93 -- );
F_3 ( V_16 L_40
L_22 , V_51 ) ;
return V_48 ;
}
static void F_29 ( struct V_5 * V_6 , unsigned V_51 )
{
struct V_3 * V_4 = V_6 -> V_14 . V_4 ;
unsigned char V_104 [ V_54 ] ;
unsigned char V_55 [ V_54 ] ;
unsigned int V_56 , V_58 ;
int V_59 , V_45 ;
struct V_88 V_89 ;
T_2 V_27 ;
F_4 ( L_41
L_42 , V_6 , V_51 ) ;
memset ( V_104 , 0 , sizeof( V_104 ) ) ;
memset ( V_55 , 0 , sizeof( V_55 ) ) ;
V_56 = V_6 -> V_21 [ V_51 ] ;
if ( V_56 == V_48 ) {
F_3 ( V_16 L_43
L_18 , V_51 ) ;
return;
}
V_45 = V_62 ;
while ( V_56 < V_6 -> V_46 ) {
for ( V_59 = 0 ; V_59 < V_6 -> V_63 / V_64 ; V_59 ++ ) {
if ( V_104 [ V_59 ] || V_55 [ V_59 ] )
continue;
if ( F_12 ( V_4 , ( V_56 * V_6 -> V_63 )
+ ( V_59 * V_64 ) , 8 , & V_27 ,
( char * ) & V_89 ) < 0 )
V_58 = V_65 ;
else
V_58 = V_89 . V_67 | V_89 . V_68 ;
switch( V_58 ) {
case V_69 :
case V_65 :
break;
case V_70 :
V_104 [ V_59 ] = 1 ;
continue;
case V_71 :
V_55 [ V_59 ] = 1 ;
continue;
default:
F_3 ( V_16 L_19
L_44 ,
V_59 , V_56 , V_58 ) ;
}
}
if ( ! V_45 -- ) {
F_3 ( V_16 L_21
L_22 , V_51 ) ;
return;
}
V_56 = V_6 -> V_20 [ V_56 ] ;
}
for ( V_59 = 0 ; V_59 < V_6 -> V_63 / V_64 ; V_59 ++ )
if ( V_104 [ V_59 ] )
return;
F_4 ( L_45 , V_51 ) ;
for (; ; ) {
T_4 * V_57 = & V_6 -> V_21 [ V_51 ] ;
V_56 = * V_57 ;
if ( V_56 == V_48 ) {
F_4 ( L_46 , V_56 ) ;
return;
}
while ( V_6 -> V_20 [ V_56 ] != V_48 ) {
F_30 ( V_56 >= V_6 -> V_46 ) ;
V_57 = & V_6 -> V_20 [ V_56 ] ;
V_56 = * V_57 ;
}
F_4 ( L_47 ,
V_56 , V_51 ) ;
if ( F_21 ( V_6 , V_56 ) < 0 ) {
V_6 -> V_20 [ V_56 ] = V_75 ;
} else {
V_6 -> V_20 [ V_56 ] = V_49 ;
V_6 -> V_47 ++ ;
}
* V_57 = V_48 ;
F_31 () ;
}
V_6 -> V_21 [ V_51 ] = V_48 ;
}
static int F_32 ( struct V_5 * V_6 , unsigned V_59 )
{
unsigned int V_56 = V_6 -> V_21 [ V_59 / ( V_6 -> V_63 / V_64 ) ] ;
unsigned long V_87 = ( V_59 * V_64 ) & ( V_6 -> V_63 - 1 ) ;
struct V_3 * V_4 = V_6 -> V_14 . V_4 ;
unsigned int V_58 ;
int V_45 = V_62 ;
T_2 V_27 ;
struct V_88 V_89 ;
F_4 ( L_48
L_49 , V_6 , V_59 ) ;
while ( V_56 < V_6 -> V_46 ) {
if ( F_12 ( V_4 , ( V_56 * V_6 -> V_63 ) +
V_87 , 8 , & V_27 , ( char * ) & V_89 ) < 0 )
V_58 = V_65 ;
else
V_58 = V_89 . V_67 | V_89 . V_68 ;
switch ( V_58 ) {
case V_69 :
case V_65 :
break;
case V_71 :
V_56 = V_48 ;
goto V_105;
case V_70 :
goto V_105;
default:
F_3 ( V_16 L_50
L_51 ,
V_59 , V_56 , V_58 ) ;
break;
}
if ( ! V_45 -- ) {
F_3 ( V_16 L_21
L_22 ,
V_59 / ( V_6 -> V_63 / V_64 ) ) ;
return 1 ;
}
V_56 = V_6 -> V_20 [ V_56 ] ;
}
V_105:
if ( V_56 != V_48 ) {
T_1 V_106 = ( V_56 * V_6 -> V_63 ) + V_87 ;
if ( F_12 ( V_4 , V_106 , 8 , & V_27 , ( char * ) & V_89 ) < 0 )
return - V_74 ;
V_89 . V_67 = V_89 . V_68 = V_71 ;
if ( F_14 ( V_4 , V_106 , 8 , & V_27 , ( char * ) & V_89 ) < 0 )
return - V_74 ;
F_29 ( V_6 , V_59 / ( V_6 -> V_63 / V_64 ) ) ;
}
return 0 ;
}
static int F_33 ( struct V_23 * V_14 , unsigned long V_59 ,
char * V_107 )
{
struct V_5 * V_6 = ( void * ) V_14 ;
unsigned int V_85 ;
unsigned long V_87 = ( V_59 * V_64 ) & ( V_6 -> V_63 - 1 ) ;
T_2 V_27 ;
struct V_61 V_40 ;
char * V_108 , * V_109 ;
F_4 ( L_52
L_53 , V_6 , V_59 , V_107 ) ;
V_109 = V_107 + V_64 ;
for ( V_108 = V_107 ; V_108 < V_109 && ! * V_108 ; V_108 ++ )
;
if ( V_108 < V_109 ) {
V_85 = F_24 ( V_6 , V_59 ) ;
if ( V_85 == V_48 ) {
F_3 ( V_16 L_54
L_55 ) ;
return 1 ;
}
memset ( & V_40 , 0xff , sizeof( struct V_61 ) ) ;
V_40 . V_66 . V_67 = V_40 . V_66 . V_68 = V_70 ;
F_16 ( V_6 -> V_14 . V_4 , ( V_85 * V_6 -> V_63 ) +
V_87 , V_64 , & V_27 , ( char * ) V_107 ,
( char * ) & V_40 ) ;
} else {
F_32 ( V_6 , V_59 ) ;
}
return 0 ;
}
static int F_34 ( struct V_23 * V_14 , unsigned long V_59 ,
char * V_107 )
{
struct V_5 * V_6 = ( void * ) V_14 ;
unsigned int V_56 = V_6 -> V_21 [ V_59 / ( V_6 -> V_63 / V_64 ) ] ;
unsigned long V_87 = ( V_59 * V_64 ) & ( V_6 -> V_63 - 1 ) ;
struct V_3 * V_4 = V_6 -> V_14 . V_4 ;
unsigned int V_58 ;
int V_45 = V_62 ;
struct V_88 V_89 ;
T_2 V_27 ;
F_4 ( L_56
L_53 , V_6 , V_59 , V_107 ) ;
while ( V_56 < V_6 -> V_46 ) {
if ( F_12 ( V_4 , ( V_56 * V_6 -> V_63 ) +
V_87 , 8 , & V_27 , ( char * ) & V_89 ) < 0 )
V_58 = V_65 ;
else
V_58 = V_89 . V_67 | V_89 . V_68 ;
switch ( V_58 ) {
case V_71 :
V_56 = V_48 ;
goto V_105;
case V_70 :
goto V_105;
case V_69 :
case V_65 :
break;
default:
F_3 ( V_16 L_50
L_57 ,
V_59 , V_56 , V_58 ) ;
break;
}
if ( ! V_45 -- ) {
F_3 ( V_16 L_34
L_58 ,
V_59 / ( V_6 -> V_63 / V_64 ) ) ;
return 1 ;
}
V_56 = V_6 -> V_20 [ V_56 ] ;
}
V_105:
if ( V_56 == V_48 ) {
memset ( V_107 , 0 , V_64 ) ;
} else {
T_2 V_27 ;
T_1 V_106 = ( V_56 * V_6 -> V_63 ) + V_87 ;
int V_73 = F_19 ( V_4 , V_106 , V_64 , & V_27 , V_107 ) ;
if ( V_73 < 0 && ! F_20 ( V_73 ) )
return - V_74 ;
}
return 0 ;
}
static int F_35 ( struct V_23 * V_24 , struct V_110 * V_111 )
{
struct V_5 * V_6 = ( void * ) V_24 ;
V_111 -> V_18 = V_6 -> V_18 ;
V_111 -> V_19 = V_6 -> V_19 ;
V_111 -> V_17 = V_6 -> V_17 ;
return 0 ;
}
static int T_5 F_36 ( void )
{
return F_37 ( & V_112 ) ;
}
static void T_6 F_38 ( void )
{
F_39 ( & V_112 ) ;
}
