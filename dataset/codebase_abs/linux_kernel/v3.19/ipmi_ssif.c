static unsigned long * F_1 ( struct V_1 * V_1 ,
unsigned long * V_2 )
{
F_2 ( & V_1 -> V_3 , * V_2 ) ;
return V_2 ;
}
static void F_3 ( struct V_1 * V_1 ,
unsigned long * V_2 )
{
F_4 ( & V_1 -> V_3 , * V_2 ) ;
}
static void F_5 ( struct V_1 * V_1 ,
struct V_4 * V_5 )
{
T_1 V_6 = V_1 -> V_6 ;
if ( ! V_6 ) {
F_6 ( V_5 ) ;
} else if ( V_5 -> V_7 < 0 ) {
F_7 ( V_1 , V_5 ) ;
F_8 ( V_8
L_1 ,
V_5 -> V_7 ) ;
} else {
F_9 ( V_6 , V_5 ) ;
}
}
static void F_7 ( struct V_1 * V_1 ,
struct V_4 * V_5 )
{
F_10 ( V_1 , V_9 ) ;
V_5 -> V_10 [ 0 ] = V_5 -> V_11 [ 0 ] | 4 ;
V_5 -> V_10 [ 1 ] = V_5 -> V_11 [ 1 ] ;
V_5 -> V_10 [ 2 ] = 0xFF ;
V_5 -> V_7 = 3 ;
F_5 ( V_1 , V_5 ) ;
}
static void F_11 ( struct V_1 * V_1 , unsigned long * V_2 )
{
unsigned char V_5 [ 3 ] ;
V_1 -> V_12 &= ~ V_13 ;
V_1 -> V_14 = V_15 ;
F_3 ( V_1 , V_2 ) ;
V_5 [ 0 ] = ( V_16 << 2 ) ;
V_5 [ 1 ] = V_17 ;
V_5 [ 2 ] = V_13 ;
if ( F_12 ( V_1 , V_5 , 3 ) != 0 ) {
V_1 -> V_14 = V_18 ;
}
}
static void F_13 ( struct V_1 * V_1 , unsigned long * V_2 )
{
unsigned char V_19 [ 2 ] ;
V_1 -> V_20 = false ;
V_1 -> V_14 = V_21 ;
F_3 ( V_1 , V_2 ) ;
V_19 [ 0 ] = ( V_16 << 2 ) ;
V_19 [ 1 ] = V_22 ;
if ( F_12 ( V_1 , V_19 , 2 ) != 0 )
V_1 -> V_14 = V_18 ;
}
static void F_14 ( struct V_1 * V_1 , unsigned long * V_2 ,
struct V_4 * V_5 )
{
if ( F_12 ( V_1 , V_5 -> V_11 , V_5 -> V_23 ) != 0 ) {
unsigned long V_24 ;
V_2 = F_1 ( V_1 , & V_24 ) ;
V_1 -> V_25 = NULL ;
V_1 -> V_14 = V_18 ;
F_3 ( V_1 , V_2 ) ;
F_6 ( V_5 ) ;
}
}
static void F_15 ( struct V_1 * V_1 , unsigned long * V_2 )
{
struct V_4 * V_5 ;
V_1 -> V_26 = false ;
V_5 = F_16 () ;
if ( ! V_5 ) {
V_1 -> V_14 = V_18 ;
return;
}
V_1 -> V_25 = V_5 ;
V_1 -> V_14 = V_27 ;
F_3 ( V_1 , V_2 ) ;
V_5 -> V_11 [ 0 ] = ( V_16 << 2 ) ;
V_5 -> V_11 [ 1 ] = V_28 ;
V_5 -> V_23 = 2 ;
F_14 ( V_1 , V_2 , V_5 ) ;
}
static void F_17 ( struct V_1 * V_1 ,
unsigned long * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_16 () ;
if ( ! V_5 ) {
V_1 -> V_14 = V_18 ;
return;
}
V_1 -> V_25 = V_5 ;
V_1 -> V_14 = V_29 ;
F_3 ( V_1 , V_2 ) ;
V_5 -> V_11 [ 0 ] = ( V_16 << 2 ) ;
V_5 -> V_11 [ 1 ] = V_30 ;
V_5 -> V_23 = 2 ;
F_14 ( V_1 , V_2 , V_5 ) ;
}
static void F_18 ( struct V_1 * V_1 , unsigned long * V_2 )
{
if ( V_1 -> V_12 & V_13 ) {
T_1 V_6 = V_1 -> V_6 ;
F_10 ( V_1 , V_31 ) ;
F_11 ( V_1 , V_2 ) ;
if ( V_6 )
F_19 ( V_6 ) ;
} else if ( V_1 -> V_12 & V_32 )
F_17 ( V_1 , V_2 ) ;
else if ( V_1 -> V_12 & V_33 )
F_15 ( V_1 , V_2 ) ;
else {
V_1 -> V_14 = V_18 ;
F_3 ( V_1 , V_2 ) ;
}
}
static int F_20 ( void * V_11 )
{
struct V_1 * V_1 = V_11 ;
while ( ! F_21 () ) {
int V_34 ;
F_22 ( & V_1 -> V_35 ) ;
F_23 ( & V_1 -> V_35 ) ;
if ( V_1 -> V_36 )
break;
if ( V_1 -> V_37 == V_38 ) {
V_34 = F_24 (
V_1 -> V_39 , V_40 ,
V_1 -> V_41 [ 0 ] ,
V_1 -> V_41 + 1 ) ;
V_1 -> V_42 ( V_1 , V_34 , NULL , 0 ) ;
} else {
V_34 = F_25 (
V_1 -> V_39 , V_43 ,
V_1 -> V_41 ) ;
if ( V_34 < 0 )
V_1 -> V_42 ( V_1 , V_34 ,
NULL , 0 ) ;
else
V_1 -> V_42 ( V_1 , 0 ,
V_1 -> V_41 ,
V_34 ) ;
}
}
return 0 ;
}
static int F_26 ( struct V_1 * V_1 ,
T_2 V_44 ,
int V_45 , int V_46 ,
unsigned char * V_11 , unsigned int V_47 )
{
V_1 -> V_42 = V_44 ;
V_1 -> V_37 = V_45 ;
V_1 -> V_48 = V_46 ;
V_1 -> V_41 = V_11 ;
V_1 -> V_49 = V_47 ;
F_27 ( & V_1 -> V_35 ) ;
return 0 ;
}
static void F_28 ( unsigned long V_11 )
{
struct V_1 * V_1 = ( void * ) V_11 ;
int V_50 ;
if ( V_1 -> V_36 )
return;
V_1 -> V_51 = 0 ;
V_50 = F_26 ( V_1 , V_52 , V_53 ,
V_43 ,
V_1 -> V_54 , V_55 ) ;
if ( V_50 < 0 ) {
if ( V_1 -> V_56 & V_57 )
F_29 ( L_2 ) ;
V_52 ( V_1 , - V_58 , NULL , 0 ) ;
}
}
static void V_52 ( struct V_1 * V_1 , int V_34 ,
unsigned char * V_11 , unsigned int V_59 )
{
struct V_4 * V_5 ;
unsigned long V_24 , * V_2 ;
int V_50 ;
if ( V_34 < 0 ) {
V_1 -> V_60 -- ;
if ( V_1 -> V_60 > 0 ) {
F_10 ( V_1 , V_61 ) ;
F_30 ( & V_1 -> V_62 ,
V_63 + V_64 ) ;
V_1 -> V_51 = V_65 ;
return;
}
F_10 ( V_1 , V_66 ) ;
if ( V_1 -> V_56 & V_57 )
F_29 ( L_3 , V_34 ) ;
V_59 = 0 ;
goto V_67;
}
if ( ( V_59 > 1 ) && ( V_1 -> V_68 == 0 )
&& ( V_11 [ 0 ] == 0x00 ) && ( V_11 [ 1 ] == 0x01 ) ) {
int V_69 ;
F_10 ( V_1 , V_70 ) ;
for ( V_69 = 0 ; V_69 < ( V_59 - 2 ) ; V_69 ++ )
V_1 -> V_11 [ V_69 ] = V_11 [ V_69 + 2 ] ;
V_59 -= 2 ;
V_1 -> V_71 = V_59 ;
V_1 -> V_68 = 1 ;
V_50 = F_26 ( V_1 , V_52 , V_53 ,
V_72 ,
V_1 -> V_54 , V_55 ) ;
if ( V_50 < 0 ) {
if ( V_1 -> V_56 & V_57 )
F_29 ( L_4 ) ;
V_34 = - V_58 ;
} else
return;
} else if ( V_1 -> V_68 ) {
int V_69 ;
unsigned char V_73 ;
if ( V_59 == 0 ) {
V_34 = - V_58 ;
if ( V_1 -> V_56 & V_57 )
F_29 ( V_8 L_5 ) ;
goto V_67;
}
V_73 = V_11 [ V_1 -> V_71 ] ;
if ( V_1 -> V_71 + V_59 - 1 > V_74 ) {
V_34 = - V_75 ;
if ( V_1 -> V_56 & V_57 )
F_29 ( L_6 ) ;
goto V_67;
}
for ( V_69 = 0 ; V_69 < ( V_59 - 1 ) ; V_69 ++ )
V_1 -> V_11 [ V_69 + V_1 -> V_71 ] = V_11 [ V_69 + 1 ] ;
V_59 -- ;
V_1 -> V_71 += V_59 ;
if ( V_73 == 0xff ) {
V_59 = V_1 -> V_71 ;
V_11 = V_1 -> V_11 ;
} else if ( ( V_73 + 1 ) != V_1 -> V_68 ) {
V_34 = - V_58 ;
} else {
F_10 ( V_1 , V_70 ) ;
V_1 -> V_68 ++ ;
V_50 = F_26 ( V_1 , V_52 ,
V_53 ,
V_72 ,
V_1 -> V_54 ,
V_55 ) ;
if ( V_50 < 0 ) {
if ( V_1 -> V_56 & V_57 )
F_29 ( V_8
L_7 ) ;
V_34 = - V_58 ;
} else
return;
}
}
if ( V_34 < 0 ) {
F_10 ( V_1 , V_66 ) ;
} else {
F_10 ( V_1 , V_76 ) ;
F_10 ( V_1 , V_70 ) ;
}
V_67:
if ( V_1 -> V_56 & V_77 )
F_29 ( V_8 L_8 ,
V_1 -> V_14 , V_34 ) ;
V_2 = F_1 ( V_1 , & V_24 ) ;
V_5 = V_1 -> V_25 ;
if ( V_5 ) {
V_5 -> V_7 = V_59 ;
if ( V_5 -> V_7 > V_74 )
V_5 -> V_7 = V_74 ;
memcpy ( V_5 -> V_10 , V_11 , V_5 -> V_7 ) ;
V_1 -> V_25 = NULL ;
}
switch ( V_1 -> V_14 ) {
case V_18 :
F_3 ( V_1 , V_2 ) ;
if ( ! V_5 )
break;
if ( V_34 < 0 )
F_7 ( V_1 , V_5 ) ;
else
F_5 ( V_1 , V_5 ) ;
break;
case V_21 :
if ( ( V_34 < 0 ) || ( V_59 < 4 ) || ( V_11 [ 2 ] != 0 ) ) {
V_1 -> V_14 = V_18 ;
F_3 ( V_1 , V_2 ) ;
F_31 ( V_8 L_9 ,
V_34 , V_59 , V_11 [ 2 ] ) ;
} else if ( V_11 [ 0 ] != ( V_16 | 1 ) << 2
|| V_11 [ 1 ] != V_22 ) {
F_31 ( V_8 L_10 ,
V_11 [ 0 ] , V_11 [ 1 ] ) ;
} else {
F_10 ( V_1 , V_78 ) ;
V_1 -> V_12 = V_11 [ 3 ] ;
F_18 ( V_1 , V_2 ) ;
}
break;
case V_15 :
if ( ( V_34 < 0 ) || ( V_59 < 3 ) || ( V_11 [ 2 ] != 0 ) ) {
F_31 ( V_8 L_11 ,
V_34 , V_59 , V_11 [ 2 ] ) ;
} else if ( V_11 [ 0 ] != ( V_16 | 1 ) << 2
|| V_11 [ 1 ] != V_17 ) {
F_31 ( V_8 L_12 ,
V_11 [ 0 ] , V_11 [ 1 ] ) ;
}
V_1 -> V_14 = V_18 ;
F_3 ( V_1 , V_2 ) ;
break;
case V_27 :
if ( ( V_34 < 0 ) || ( V_59 < 3 ) || ( V_5 -> V_10 [ 2 ] != 0 ) ) {
V_5 -> V_79 ( V_5 ) ;
V_1 -> V_12 &= ~ V_33 ;
F_18 ( V_1 , V_2 ) ;
} else if ( V_5 -> V_10 [ 0 ] != ( V_16 | 1 ) << 2
|| V_5 -> V_10 [ 1 ] != V_28 ) {
F_31 ( V_8 L_13 ,
V_5 -> V_10 [ 0 ] , V_5 -> V_10 [ 1 ] ) ;
V_5 -> V_79 ( V_5 ) ;
V_1 -> V_12 &= ~ V_33 ;
F_18 ( V_1 , V_2 ) ;
} else {
F_18 ( V_1 , V_2 ) ;
F_10 ( V_1 , V_80 ) ;
F_5 ( V_1 , V_5 ) ;
}
break;
case V_29 :
if ( ( V_34 < 0 ) || ( V_59 < 3 ) || ( V_5 -> V_10 [ 2 ] != 0 ) ) {
V_5 -> V_79 ( V_5 ) ;
V_1 -> V_12 &= ~ V_32 ;
F_18 ( V_1 , V_2 ) ;
} else if ( V_5 -> V_10 [ 0 ] != ( V_16 | 1 ) << 2
|| V_5 -> V_10 [ 1 ] != V_30 ) {
F_31 ( V_8 L_12 ,
V_5 -> V_10 [ 0 ] , V_5 -> V_10 [ 1 ] ) ;
V_5 -> V_79 ( V_5 ) ;
V_1 -> V_12 &= ~ V_32 ;
F_18 ( V_1 , V_2 ) ;
} else {
F_10 ( V_1 , V_81 ) ;
F_18 ( V_1 , V_2 ) ;
F_5 ( V_1 , V_5 ) ;
}
break;
}
V_2 = F_1 ( V_1 , & V_24 ) ;
if ( F_32 ( V_1 ) && ! V_1 -> V_36 ) {
if ( V_1 -> V_26 )
F_15 ( V_1 , V_2 ) ;
else if ( V_1 -> V_20 )
F_13 ( V_1 , V_2 ) ;
else
F_33 ( V_1 , V_2 ) ;
} else
F_3 ( V_1 , V_2 ) ;
if ( V_1 -> V_56 & V_77 )
F_29 ( V_8 L_14 , V_1 -> V_14 ) ;
}
static void F_34 ( struct V_1 * V_1 , int V_34 ,
unsigned char * V_11 , unsigned int V_59 )
{
int V_50 ;
if ( V_34 < 0 ) {
V_1 -> V_60 -- ;
if ( V_1 -> V_60 > 0 ) {
if ( ! F_35 ( V_1 ) ) {
F_10 ( V_1 , V_82 ) ;
return;
}
F_10 ( V_1 , V_83 ) ;
if ( V_1 -> V_56 & V_57 )
F_29 ( V_8
L_15 ) ;
V_52 ( V_1 , - V_58 , NULL , 0 ) ;
return;
}
F_10 ( V_1 , V_83 ) ;
if ( V_1 -> V_56 & V_57 )
F_29 ( L_16 , V_34 ) ;
V_52 ( V_1 , V_34 , NULL , 0 ) ;
return;
}
if ( V_1 -> V_84 ) {
int V_85 ;
F_10 ( V_1 , V_86 ) ;
V_85 = V_1 -> V_71 - V_1 -> V_68 ;
if ( V_85 > 32 )
V_85 = 32 ;
V_1 -> V_84 [ V_1 -> V_68 ] = V_85 ;
V_1 -> V_68 += V_85 ;
if ( V_85 < 32 )
V_1 -> V_84 = NULL ;
V_50 = F_26 ( V_1 , F_34 ,
V_38 ,
V_87 ,
V_1 -> V_84 + V_1 -> V_68 ,
V_55 ) ;
if ( V_50 < 0 ) {
F_10 ( V_1 , V_83 ) ;
if ( V_1 -> V_56 & V_57 )
F_29 ( L_17 ) ;
V_52 ( V_1 , - V_58 , NULL , 0 ) ;
}
} else {
F_10 ( V_1 , V_88 ) ;
F_10 ( V_1 , V_86 ) ;
V_1 -> V_60 = V_89 ;
V_1 -> V_51 = V_90 ;
F_30 ( & V_1 -> V_62 ,
V_63 + V_91 ) ;
return;
}
}
static int F_35 ( struct V_1 * V_1 )
{
int V_50 ;
int V_46 ;
if ( V_1 -> V_92 > 32 ) {
V_46 = V_93 ;
V_1 -> V_84 = V_1 -> V_11 ;
V_1 -> V_71 = V_1 -> V_92 ;
V_1 -> V_68 = 32 ;
V_1 -> V_11 [ 0 ] = 32 ;
} else {
V_1 -> V_84 = NULL ;
V_46 = V_40 ;
V_1 -> V_11 [ 0 ] = V_1 -> V_92 ;
}
V_50 = F_26 ( V_1 , F_34 , V_38 ,
V_46 , V_1 -> V_11 , V_55 ) ;
if ( V_50 && ( V_1 -> V_56 & V_57 ) )
F_29 ( L_18 ) ;
return V_50 ;
}
static int F_12 ( struct V_1 * V_1 ,
unsigned char * V_11 ,
unsigned int V_59 )
{
if ( V_59 > V_74 )
return - V_75 ;
if ( V_59 > V_1 -> V_94 )
return - V_75 ;
V_1 -> V_60 = V_95 ;
memcpy ( V_1 -> V_11 + 1 , V_11 , V_59 ) ;
V_1 -> V_92 = V_59 ;
return F_35 ( V_1 ) ;
}
static void F_33 ( struct V_1 * V_1 , unsigned long * V_2 )
{
struct V_4 * V_5 ;
unsigned long V_24 ;
V_96:
if ( ! F_32 ( V_1 ) ) {
F_3 ( V_1 , V_2 ) ;
return;
}
if ( ! V_1 -> V_97 ) {
V_1 -> V_25 = NULL ;
F_3 ( V_1 , V_2 ) ;
} else {
int V_50 ;
V_1 -> V_25 = V_1 -> V_97 ;
V_1 -> V_97 = NULL ;
F_3 ( V_1 , V_2 ) ;
V_50 = F_12 ( V_1 ,
V_1 -> V_25 -> V_11 ,
V_1 -> V_25 -> V_23 ) ;
if ( V_50 ) {
V_5 = V_1 -> V_25 ;
V_1 -> V_25 = NULL ;
F_7 ( V_1 , V_5 ) ;
V_2 = F_1 ( V_1 , & V_24 ) ;
goto V_96;
}
}
}
static void F_36 ( void * V_98 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = (struct V_1 * ) V_98 ;
unsigned long V_24 , * V_2 ;
F_37 ( V_1 -> V_97 ) ;
V_1 -> V_97 = V_5 ;
V_2 = F_1 ( V_1 , & V_24 ) ;
F_33 ( V_1 , V_2 ) ;
if ( V_1 -> V_56 & V_99 ) {
struct V_100 V_101 ;
F_38 ( & V_101 ) ;
F_29 ( L_19 ,
V_5 -> V_11 [ 0 ] , V_5 -> V_11 [ 1 ] ,
( long ) V_101 . V_102 , ( long ) V_101 . V_103 ) ;
}
}
static int F_39 ( void * V_98 , struct V_104 * V_11 )
{
struct V_1 * V_1 = V_98 ;
V_11 -> V_105 = V_1 -> V_106 ;
V_11 -> V_107 = & V_1 -> V_39 -> V_107 ;
V_11 -> V_108 = V_1 -> V_108 ;
F_40 ( V_11 -> V_107 ) ;
return 0 ;
}
static void F_41 ( void * V_98 )
{
struct V_1 * V_1 = (struct V_1 * ) V_98 ;
unsigned long V_24 , * V_2 ;
if ( ! V_1 -> V_109 )
return;
V_2 = F_1 ( V_1 , & V_24 ) ;
V_1 -> V_26 = true ;
if ( F_32 ( V_1 ) )
F_13 ( V_1 , V_2 ) ;
else {
V_1 -> V_20 = true ;
F_3 ( V_1 , V_2 ) ;
}
}
static int F_42 ( void * V_98 )
{
struct V_1 * V_1 = V_98 ;
if ( ! F_43 ( V_1 -> V_39 -> V_110 -> V_111 ) )
return - V_112 ;
F_44 ( V_1 -> V_39 ) ;
return 0 ;
}
static void F_45 ( void * V_98 )
{
struct V_1 * V_1 = V_98 ;
F_46 ( V_1 -> V_39 ) ;
F_47 ( V_1 -> V_39 -> V_110 ) ;
}
static int F_48 ( void * V_98 ,
T_1 V_6 )
{
struct V_1 * V_1 = V_98 ;
V_1 -> V_6 = V_6 ;
return 0 ;
}
static int F_49 ( struct V_113 * V_39 )
{
struct V_1 * V_1 = F_50 ( V_39 ) ;
int V_50 ;
if ( ! V_1 )
return 0 ;
F_51 ( V_39 , NULL ) ;
V_50 = F_52 ( V_1 -> V_6 ) ;
if ( V_50 ) {
F_8 ( V_8 L_20 , V_50 ) ;
return V_50 ;
}
V_1 -> V_6 = NULL ;
while ( V_1 -> V_14 != V_18 )
F_53 ( 1 ) ;
V_1 -> V_36 = true ;
F_54 ( & V_1 -> V_62 ) ;
if ( V_1 -> V_114 ) {
F_27 ( & V_1 -> V_35 ) ;
F_55 ( V_1 -> V_114 ) ;
}
F_56 ( V_1 ) ;
return 0 ;
}
static int F_57 ( struct V_113 * V_39 , int V_59 , unsigned char * V_5 ,
int * V_115 , unsigned char * V_116 )
{
int V_117 ;
int V_118 ;
V_117 = V_95 ;
V_119:
V_118 = F_24 ( V_39 , V_40 , V_59 , V_5 ) ;
if ( V_118 ) {
V_117 -- ;
if ( V_117 > 0 )
goto V_119;
return - V_112 ;
}
V_118 = - V_112 ;
V_117 = V_89 ;
while ( V_117 > 0 ) {
V_118 = F_25 ( V_39 , V_43 ,
V_116 ) ;
if ( V_118 > 0 )
break;
F_58 ( V_120 ) ;
V_117 -- ;
if ( V_117 <= 0 )
break;
}
if ( V_118 > 0 ) {
if ( V_118 < 3 ||
( V_116 [ 0 ] != ( V_5 [ 0 ] | ( 1 << 2 ) ) ) ||
( V_116 [ 1 ] != V_5 [ 1 ] ) )
V_118 = - V_121 ;
else {
* V_115 = V_118 ;
V_118 = 0 ;
}
}
return V_118 ;
}
static int F_59 ( struct V_113 * V_39 , struct V_122 * V_123 )
{
unsigned char * V_116 ;
unsigned char V_5 [ 3 ] ;
int V_50 ;
int V_59 ;
V_116 = F_60 ( V_74 , V_124 ) ;
if ( ! V_116 )
return - V_125 ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_126 ;
V_50 = F_57 ( V_39 , 2 , V_5 , & V_59 , V_116 ) ;
if ( V_50 )
V_50 = - V_112 ;
else
F_61 ( V_123 -> type , V_127 , V_128 ) ;
F_56 ( V_116 ) ;
return V_50 ;
}
static int F_62 ( struct V_129 * V_130 , void * V_131 )
{
return F_63 ( V_130 , L_21 ) ;
}
static int F_64 ( struct V_132 * V_132 , struct V_133 * V_133 )
{
return F_65 ( V_133 , F_62 , V_132 -> V_134 ) ;
}
static int F_66 ( struct V_129 * V_130 , void * V_131 )
{
struct V_1 * V_1 = V_130 -> V_135 ;
F_67 ( V_130 , L_22 ,
F_68 ( V_1 , V_88 ) ) ;
F_67 ( V_130 , L_23 ,
F_68 ( V_1 , V_86 ) ) ;
F_67 ( V_130 , L_24 ,
F_68 ( V_1 , V_82 ) ) ;
F_67 ( V_130 , L_25 ,
F_68 ( V_1 , V_83 ) ) ;
F_67 ( V_130 , L_26 ,
F_68 ( V_1 , V_76 ) ) ;
F_67 ( V_130 , L_27 ,
F_68 ( V_1 , V_70 ) ) ;
F_67 ( V_130 , L_28 ,
F_68 ( V_1 , V_61 ) ) ;
F_67 ( V_130 , L_29 ,
F_68 ( V_1 , V_66 ) ) ;
F_67 ( V_130 , L_30 ,
F_68 ( V_1 , V_78 ) ) ;
F_67 ( V_130 , L_31 ,
F_68 ( V_1 , V_9 ) ) ;
F_67 ( V_130 , L_32 ,
F_68 ( V_1 , V_80 ) ) ;
F_67 ( V_130 , L_33 ,
F_68 ( V_1 , V_31 ) ) ;
return 0 ;
}
static int F_69 ( struct V_132 * V_132 , struct V_133 * V_133 )
{
return F_65 ( V_133 , F_66 , F_70 ( V_132 ) ) ;
}
static struct V_136 * F_71 ( unsigned short V_137 ,
char * V_138 ,
bool V_139 )
{
struct V_136 * V_123 , * V_140 = NULL ;
V_96:
F_72 (info, &ssif_infos, link) {
if ( V_123 -> V_141 . V_137 == V_137 ) {
if ( V_123 -> V_138 || V_138 ) {
if ( ! V_123 -> V_138 != ! V_138 ) {
continue;
}
if ( strcmp ( V_123 -> V_138 , V_138 ) )
continue;
}
V_140 = V_123 ;
break;
}
}
if ( ! V_140 && V_139 ) {
V_138 = NULL ;
V_139 = false ;
goto V_96;
}
return V_140 ;
}
static bool F_73 ( struct V_1 * V_1 , struct V_142 * V_107 )
{
#ifdef F_74
T_3 T_3 ;
T_3 = F_75 ( V_107 ) ;
if ( T_3 ) {
V_1 -> V_106 = V_143 ;
V_1 -> V_108 . V_144 . T_3 = T_3 ;
return true ;
}
#endif
return false ;
}
static int F_76 ( struct V_113 * V_39 , const struct V_145 * V_146 )
{
unsigned char V_5 [ 3 ] ;
unsigned char * V_116 ;
struct V_1 * V_1 ;
int V_50 = 0 ;
int V_59 ;
int V_69 ;
T_4 V_147 = 0 ;
struct V_136 * V_108 = NULL ;
V_116 = F_60 ( V_74 , V_124 ) ;
if ( ! V_116 )
return - V_125 ;
V_1 = F_77 ( sizeof( * V_1 ) , V_124 ) ;
if ( ! V_1 ) {
F_56 ( V_116 ) ;
return - V_125 ;
}
if ( ! F_73 ( V_1 , & V_39 -> V_107 ) ) {
V_108 = F_71 ( V_39 -> V_137 , V_39 -> V_110 -> V_148 ,
true ) ;
if ( ! V_108 ) {
V_1 -> V_106 = V_149 ;
} else {
V_1 -> V_106 = V_108 -> V_105 ;
V_1 -> V_56 = V_108 -> V_150 ;
V_1 -> V_108 = V_108 -> V_108 ;
V_147 = V_108 -> V_147 ;
}
}
F_29 ( V_8 L_34 ,
F_78 ( V_1 -> V_106 ) ,
V_39 -> V_137 , V_39 -> V_110 -> V_148 , V_147 ) ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_126 ;
V_50 = F_57 ( V_39 , 2 , V_5 , & V_59 , V_116 ) ;
if ( V_50 )
goto V_151;
V_50 = F_79 ( V_116 , V_59 , & V_1 -> V_152 ) ;
if ( V_50 )
goto V_151;
V_1 -> V_39 = V_39 ;
F_51 ( V_39 , V_1 ) ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_153 ;
V_5 [ 2 ] = 0 ;
V_50 = F_57 ( V_39 , 3 , V_5 , & V_59 , V_116 ) ;
if ( ! V_50 && ( V_59 >= 3 ) && ( V_116 [ 2 ] == 0 ) ) {
if ( V_59 < 7 ) {
if ( V_154 )
F_29 ( V_8 L_35 , V_59 ) ;
goto V_155;
}
V_1 -> V_94 = V_116 [ 5 ] ;
V_1 -> V_156 = V_116 [ 6 ] ;
V_1 -> V_157 = ( V_116 [ 4 ] >> 6 ) & 0x3 ;
V_1 -> V_158 = ( V_116 [ 4 ] >> 3 ) & 0x1 ;
switch ( V_1 -> V_157 ) {
case V_159 :
if ( V_1 -> V_94 > 32 )
V_1 -> V_94 = 32 ;
if ( V_1 -> V_156 > 32 )
V_1 -> V_156 = 32 ;
break;
case V_160 :
if ( V_1 -> V_94 > 64 )
V_1 -> V_94 = 64 ;
if ( V_1 -> V_156 > 62 )
V_1 -> V_156 = 62 ;
break;
case V_161 :
break;
default:
goto V_155;
}
} else {
V_155:
F_29 ( V_8 L_36 ,
V_50 , V_59 , V_116 [ 2 ] ) ;
V_1 -> V_94 = 32 ;
V_1 -> V_156 = 32 ;
V_1 -> V_157 = V_159 ;
V_1 -> V_158 = 0 ;
}
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_17 ;
V_5 [ 2 ] = V_13 ;
V_50 = F_57 ( V_39 , 3 , V_5 , & V_59 , V_116 ) ;
if ( V_50 || ( V_59 < 3 ) || ( V_116 [ 2 ] != 0 ) )
F_31 ( V_8 L_37 ,
V_50 , V_59 , V_116 [ 2 ] ) ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_162 ;
V_50 = F_57 ( V_39 , 2 , V_5 , & V_59 , V_116 ) ;
if ( V_50 || ( V_59 < 4 ) || ( V_116 [ 2 ] != 0 ) ) {
F_31 ( V_8 L_38 ,
V_50 , V_59 , V_116 [ 2 ] ) ;
V_50 = 0 ;
goto V_140;
}
if ( V_116 [ 3 ] & V_163 ) {
V_1 -> V_109 = true ;
goto V_140;
}
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_164 ;
V_5 [ 2 ] = V_116 [ 3 ] | V_163 ;
V_50 = F_57 ( V_39 , 3 , V_5 , & V_59 , V_116 ) ;
if ( V_50 || ( V_59 < 2 ) ) {
F_31 ( V_8 L_38 ,
V_50 , V_59 , V_116 [ 2 ] ) ;
V_50 = 0 ;
goto V_140;
}
if ( V_116 [ 2 ] == 0 )
V_1 -> V_109 = true ;
V_140:
V_1 -> V_165 = F_80 ( & V_166 ) ;
if ( V_154 ) {
F_29 ( L_39 ,
V_39 -> V_137 ) ;
}
F_81 ( & V_1 -> V_3 ) ;
V_1 -> V_14 = V_18 ;
F_82 ( & V_1 -> V_62 ) ;
V_1 -> V_62 . V_11 = ( unsigned long ) V_1 ;
V_1 -> V_62 . V_167 = F_28 ;
for ( V_69 = 0 ; V_69 < V_168 ; V_69 ++ )
F_83 ( & V_1 -> V_169 [ V_69 ] , 0 ) ;
if ( V_1 -> V_158 )
V_1 -> V_39 -> V_2 |= V_170 ;
V_1 -> V_171 . V_172 = V_173 ;
V_1 -> V_171 . V_174 = F_48 ;
V_1 -> V_171 . F_39 = F_39 ;
V_1 -> V_171 . F_36 = F_36 ;
V_1 -> V_171 . F_41 = F_41 ;
V_1 -> V_171 . F_42 = F_42 ;
V_1 -> V_171 . F_45 = F_45 ;
{
unsigned int V_175 ;
V_175 = ( ( V_1 -> V_39 -> V_110 -> V_111 << 8 ) |
V_1 -> V_39 -> V_137 ) ;
F_23 ( & V_1 -> V_35 ) ;
V_1 -> V_114 = F_84 ( F_20 , V_1 ,
L_40 , V_175 ) ;
if ( F_85 ( V_1 -> V_114 ) ) {
V_50 = F_86 ( V_1 -> V_114 ) ;
F_87 ( & V_1 -> V_39 -> V_107 ,
L_41 ,
V_50 ) ;
goto V_151;
}
}
V_50 = F_88 ( & V_1 -> V_171 ,
V_1 ,
& V_1 -> V_152 ,
& V_1 -> V_39 -> V_107 ,
V_147 ) ;
if ( V_50 ) {
F_8 ( V_8 L_42 , V_50 ) ;
goto V_151;
}
V_50 = F_89 ( V_1 -> V_6 , L_43 ,
& V_176 ,
V_1 ) ;
if ( V_50 ) {
F_8 ( V_8 L_44 , V_50 ) ;
goto V_177;
}
V_50 = F_89 ( V_1 -> V_6 , L_45 ,
& V_178 ,
V_1 ) ;
if ( V_50 ) {
F_8 ( V_8 L_44 , V_50 ) ;
goto V_177;
}
V_151:
if ( V_50 )
F_56 ( V_1 ) ;
F_56 ( V_116 ) ;
return V_50 ;
V_177:
F_52 ( V_1 -> V_6 ) ;
goto V_151;
}
static int F_90 ( struct V_142 * V_179 , void * V_180 )
{
struct V_136 * V_108 = V_180 ;
if ( V_179 -> type != & V_181 )
return 0 ;
F_91 ( F_92 ( V_179 ) , & V_108 -> V_141 ) ;
if ( ! V_108 -> V_138 )
return 1 ;
return 0 ;
}
static int F_93 ( int V_137 , char * V_138 ,
int V_150 , int V_147 ,
enum V_182 V_105 )
{
struct V_136 * V_108 ;
int V_50 = 0 ;
F_94 ( & V_183 ) ;
if ( F_71 ( V_137 , V_138 , false ) ) {
V_50 = - V_184 ;
goto V_185;
}
V_108 = F_77 ( sizeof( * V_108 ) , V_124 ) ;
if ( ! V_108 ) {
V_50 = - V_125 ;
goto V_185;
}
if ( V_138 ) {
V_108 -> V_138 = F_95 ( V_138 , V_124 ) ;
if ( ! V_108 -> V_138 ) {
F_56 ( V_108 ) ;
V_50 = - V_125 ;
goto V_185;
}
}
strncpy ( V_108 -> V_141 . type , V_127 ,
sizeof( V_108 -> V_141 . type ) ) ;
V_108 -> V_141 . V_137 = V_137 ;
V_108 -> V_141 . V_186 = V_108 ;
V_108 -> V_150 = V_150 ;
V_108 -> V_147 = V_147 ;
V_108 -> V_105 = V_105 ;
F_96 ( & V_108 -> V_187 , & V_188 ) ;
if ( V_189 )
F_97 ( V_108 , F_90 ) ;
V_185:
F_98 ( & V_183 ) ;
return V_50 ;
}
static void F_99 ( void )
{
struct V_136 * V_123 , * V_190 ;
F_94 ( & V_183 ) ;
F_100 (info, tmp, &ssif_infos, link) {
F_101 ( & V_123 -> V_187 ) ;
F_56 ( V_123 -> V_138 ) ;
F_56 ( V_123 ) ;
}
F_98 ( & V_183 ) ;
}
static unsigned short * F_102 ( void )
{
struct V_136 * V_123 ;
unsigned int V_191 = 0 , V_69 ;
unsigned short * V_192 ;
F_72 (info, &ssif_infos, link)
V_191 ++ ;
V_192 = F_77 ( sizeof( * V_192 ) * ( V_191 + 1 ) , V_124 ) ;
if ( ! V_192 )
return NULL ;
V_69 = 0 ;
F_72 (info, &ssif_infos, link) {
unsigned short V_137 = V_123 -> V_141 . V_137 ;
int V_193 ;
for ( V_193 = 0 ; V_193 < V_69 ; V_193 ++ ) {
if ( V_192 [ V_193 ] == V_137 )
goto V_194;
}
V_192 [ V_69 ] = V_137 ;
V_194:
V_69 ++ ;
}
V_192 [ V_69 ] = V_195 ;
return V_192 ;
}
static int F_103 ( struct V_196 * V_197 )
{
unsigned short V_198 ;
if ( V_199 >= V_200 )
return - 1 ;
if ( V_197 -> V_201 != 1 ) {
F_31 ( L_46 , V_197 -> V_201 ) ;
return - V_112 ;
}
if ( V_197 -> V_202 != 4 )
return - V_112 ;
if ( V_197 -> V_137 . V_203 != V_204 ) {
F_31 ( V_8 L_47 ,
V_197 -> V_137 . V_203 ) ;
return - V_58 ;
}
V_198 = V_197 -> V_137 . V_205 >> 1 ;
return F_93 ( V_198 , NULL , 0 , 0 , V_206 ) ;
}
static void F_104 ( void )
{
T_5 V_207 ;
struct V_196 * V_197 ;
int V_69 ;
if ( V_208 )
return;
if ( V_209 )
return;
for ( V_69 = 0 ; ; V_69 ++ ) {
V_207 = F_105 ( V_210 , V_69 + 1 ,
(struct V_211 * * ) & V_197 ) ;
if ( V_207 != V_212 )
return;
F_103 ( V_197 ) ;
}
}
static void F_104 ( void ) { }
static int F_106 ( const struct V_213 * V_214 )
{
struct V_215 * V_216 = V_214 -> V_217 ;
T_4 * V_11 = ( T_4 * ) V_216 ;
T_4 V_59 = V_216 -> V_218 ;
unsigned short V_198 ;
int V_147 ;
if ( V_199 >= V_200 )
return - 1 ;
if ( V_59 < 9 )
return - 1 ;
if ( V_11 [ 0x04 ] != 4 )
return - 1 ;
if ( ( V_11 [ 8 ] >> 1 ) == 0 ) {
V_198 = V_11 [ 6 ] >> 1 ;
V_147 = 0 ;
} else {
V_198 = V_11 [ 8 ] >> 1 ;
V_147 = V_11 [ 6 ] ;
}
return F_93 ( V_198 , NULL , 0 , 0 , V_219 ) ;
}
static void F_107 ( void )
{
const struct V_213 * V_107 = NULL ;
while ( ( V_107 = F_108 ( V_220 , NULL , V_107 ) ) )
F_106 ( V_107 ) ;
}
static void F_107 ( void ) { }
static int F_109 ( void )
{
int V_69 ;
int V_50 ;
if ( V_189 )
return 0 ;
F_29 ( L_48 ) ;
for ( V_69 = 0 ; V_69 < V_199 ; V_69 ++ ) {
V_50 = F_93 ( V_137 [ V_69 ] , V_138 [ V_69 ] ,
V_221 [ V_69 ] , V_222 [ V_69 ] ,
V_223 ) ;
if ( ! V_50 )
F_8 ( V_8
L_49 ,
V_137 [ V_69 ] ) ;
}
if ( V_224 )
V_225 . V_226 . V_227 =
F_110 ( V_228 ) ;
if ( V_229 )
F_107 () ;
if ( V_224 )
F_104 () ;
V_225 . V_192 = F_102 () ;
V_50 = F_111 ( & V_225 ) ;
if ( ! V_50 )
V_189 = true ;
return V_50 ;
}
static void F_112 ( void )
{
if ( ! V_189 )
return;
V_189 = false ;
F_113 ( & V_225 ) ;
F_99 () ;
}
