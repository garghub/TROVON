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
V_34 = F_22 (
& V_1 -> V_35 ) ;
if ( V_1 -> V_36 )
break;
if ( V_34 == - V_37 )
continue;
F_23 ( & V_1 -> V_35 ) ;
if ( V_1 -> V_38 == V_39 ) {
V_34 = F_24 (
V_1 -> V_40 , V_41 ,
V_1 -> V_42 [ 0 ] ,
V_1 -> V_42 + 1 ) ;
V_1 -> V_43 ( V_1 , V_34 , NULL , 0 ) ;
} else {
V_34 = F_25 (
V_1 -> V_40 , V_44 ,
V_1 -> V_42 ) ;
if ( V_34 < 0 )
V_1 -> V_43 ( V_1 , V_34 ,
NULL , 0 ) ;
else
V_1 -> V_43 ( V_1 , 0 ,
V_1 -> V_42 ,
V_34 ) ;
}
}
return 0 ;
}
static int F_26 ( struct V_1 * V_1 ,
T_2 V_45 ,
int V_46 , int V_47 ,
unsigned char * V_11 , unsigned int V_48 )
{
V_1 -> V_43 = V_45 ;
V_1 -> V_38 = V_46 ;
V_1 -> V_49 = V_47 ;
V_1 -> V_42 = V_11 ;
V_1 -> V_50 = V_48 ;
F_27 ( & V_1 -> V_35 ) ;
return 0 ;
}
static void F_28 ( unsigned long V_11 )
{
struct V_1 * V_1 = ( void * ) V_11 ;
int V_51 ;
if ( V_1 -> V_36 )
return;
V_1 -> V_52 = 0 ;
V_51 = F_26 ( V_1 , V_53 , V_54 ,
V_44 ,
V_1 -> V_55 , V_56 ) ;
if ( V_51 < 0 ) {
if ( V_1 -> V_57 & V_58 )
F_29 ( L_2 ) ;
V_53 ( V_1 , - V_59 , NULL , 0 ) ;
}
}
static void V_53 ( struct V_1 * V_1 , int V_34 ,
unsigned char * V_11 , unsigned int V_60 )
{
struct V_4 * V_5 ;
unsigned long V_24 , * V_2 ;
int V_51 ;
if ( V_34 < 0 ) {
V_1 -> V_61 -- ;
if ( V_1 -> V_61 > 0 ) {
F_10 ( V_1 , V_62 ) ;
F_30 ( & V_1 -> V_63 ,
V_64 + V_65 ) ;
V_1 -> V_52 = V_66 ;
return;
}
F_10 ( V_1 , V_67 ) ;
if ( V_1 -> V_57 & V_58 )
F_29 ( L_3 , V_34 ) ;
V_60 = 0 ;
goto V_68;
}
if ( ( V_60 > 1 ) && ( V_1 -> V_69 == 0 )
&& ( V_11 [ 0 ] == 0x00 ) && ( V_11 [ 1 ] == 0x01 ) ) {
int V_70 ;
F_10 ( V_1 , V_71 ) ;
for ( V_70 = 0 ; V_70 < ( V_60 - 2 ) ; V_70 ++ )
V_1 -> V_11 [ V_70 ] = V_11 [ V_70 + 2 ] ;
V_60 -= 2 ;
V_1 -> V_72 = V_60 ;
V_1 -> V_69 = 1 ;
V_51 = F_26 ( V_1 , V_53 , V_54 ,
V_73 ,
V_1 -> V_55 , V_56 ) ;
if ( V_51 < 0 ) {
if ( V_1 -> V_57 & V_58 )
F_29 ( L_4 ) ;
V_34 = - V_59 ;
} else
return;
} else if ( V_1 -> V_69 ) {
int V_70 ;
unsigned char V_74 ;
if ( V_60 == 0 ) {
V_34 = - V_59 ;
if ( V_1 -> V_57 & V_58 )
F_29 ( V_8 L_5 ) ;
goto V_68;
}
V_74 = V_11 [ V_1 -> V_72 ] ;
if ( V_1 -> V_72 + V_60 - 1 > V_75 ) {
V_34 = - V_76 ;
if ( V_1 -> V_57 & V_58 )
F_29 ( L_6 ) ;
goto V_68;
}
for ( V_70 = 0 ; V_70 < ( V_60 - 1 ) ; V_70 ++ )
V_1 -> V_11 [ V_70 + V_1 -> V_72 ] = V_11 [ V_70 + 1 ] ;
V_60 -- ;
V_1 -> V_72 += V_60 ;
if ( V_74 == 0xff ) {
V_60 = V_1 -> V_72 ;
V_11 = V_1 -> V_11 ;
} else if ( ( V_74 + 1 ) != V_1 -> V_69 ) {
V_34 = - V_59 ;
} else {
F_10 ( V_1 , V_71 ) ;
V_1 -> V_69 ++ ;
V_51 = F_26 ( V_1 , V_53 ,
V_54 ,
V_73 ,
V_1 -> V_55 ,
V_56 ) ;
if ( V_51 < 0 ) {
if ( V_1 -> V_57 & V_58 )
F_29 ( V_8
L_7 ) ;
V_34 = - V_59 ;
} else
return;
}
}
if ( V_34 < 0 ) {
F_10 ( V_1 , V_67 ) ;
} else {
F_10 ( V_1 , V_77 ) ;
F_10 ( V_1 , V_71 ) ;
}
V_68:
if ( V_1 -> V_57 & V_78 )
F_29 ( V_8 L_8 ,
V_1 -> V_14 , V_34 ) ;
V_2 = F_1 ( V_1 , & V_24 ) ;
V_5 = V_1 -> V_25 ;
if ( V_5 ) {
V_5 -> V_7 = V_60 ;
if ( V_5 -> V_7 > V_75 )
V_5 -> V_7 = V_75 ;
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
if ( ( V_34 < 0 ) || ( V_60 < 4 ) || ( V_11 [ 2 ] != 0 ) ) {
V_1 -> V_14 = V_18 ;
F_3 ( V_1 , V_2 ) ;
F_31 ( V_8 L_9 ,
V_34 , V_60 , V_11 [ 2 ] ) ;
} else if ( V_11 [ 0 ] != ( V_16 | 1 ) << 2
|| V_11 [ 1 ] != V_22 ) {
F_31 ( V_8 L_10 ,
V_11 [ 0 ] , V_11 [ 1 ] ) ;
} else {
F_10 ( V_1 , V_79 ) ;
V_1 -> V_12 = V_11 [ 3 ] ;
F_18 ( V_1 , V_2 ) ;
}
break;
case V_15 :
if ( ( V_34 < 0 ) || ( V_60 < 3 ) || ( V_11 [ 2 ] != 0 ) ) {
F_31 ( V_8 L_11 ,
V_34 , V_60 , V_11 [ 2 ] ) ;
} else if ( V_11 [ 0 ] != ( V_16 | 1 ) << 2
|| V_11 [ 1 ] != V_17 ) {
F_31 ( V_8 L_12 ,
V_11 [ 0 ] , V_11 [ 1 ] ) ;
}
V_1 -> V_14 = V_18 ;
F_3 ( V_1 , V_2 ) ;
break;
case V_27 :
if ( ( V_34 < 0 ) || ( V_60 < 3 ) || ( V_5 -> V_10 [ 2 ] != 0 ) ) {
V_5 -> V_80 ( V_5 ) ;
V_1 -> V_12 &= ~ V_33 ;
F_18 ( V_1 , V_2 ) ;
} else if ( V_5 -> V_10 [ 0 ] != ( V_16 | 1 ) << 2
|| V_5 -> V_10 [ 1 ] != V_28 ) {
F_31 ( V_8 L_13 ,
V_5 -> V_10 [ 0 ] , V_5 -> V_10 [ 1 ] ) ;
V_5 -> V_80 ( V_5 ) ;
V_1 -> V_12 &= ~ V_33 ;
F_18 ( V_1 , V_2 ) ;
} else {
F_18 ( V_1 , V_2 ) ;
F_10 ( V_1 , V_81 ) ;
F_5 ( V_1 , V_5 ) ;
}
break;
case V_29 :
if ( ( V_34 < 0 ) || ( V_60 < 3 ) || ( V_5 -> V_10 [ 2 ] != 0 ) ) {
V_5 -> V_80 ( V_5 ) ;
V_1 -> V_12 &= ~ V_32 ;
F_18 ( V_1 , V_2 ) ;
} else if ( V_5 -> V_10 [ 0 ] != ( V_16 | 1 ) << 2
|| V_5 -> V_10 [ 1 ] != V_30 ) {
F_31 ( V_8 L_12 ,
V_5 -> V_10 [ 0 ] , V_5 -> V_10 [ 1 ] ) ;
V_5 -> V_80 ( V_5 ) ;
V_1 -> V_12 &= ~ V_32 ;
F_18 ( V_1 , V_2 ) ;
} else {
F_10 ( V_1 , V_82 ) ;
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
if ( V_1 -> V_57 & V_78 )
F_29 ( V_8 L_14 , V_1 -> V_14 ) ;
}
static void F_34 ( struct V_1 * V_1 , int V_34 ,
unsigned char * V_11 , unsigned int V_60 )
{
int V_51 ;
if ( V_34 < 0 ) {
V_1 -> V_61 -- ;
if ( V_1 -> V_61 > 0 ) {
if ( ! F_35 ( V_1 ) ) {
F_10 ( V_1 , V_83 ) ;
return;
}
F_10 ( V_1 , V_84 ) ;
if ( V_1 -> V_57 & V_58 )
F_29 ( V_8
L_15 ) ;
V_53 ( V_1 , - V_59 , NULL , 0 ) ;
return;
}
F_10 ( V_1 , V_84 ) ;
if ( V_1 -> V_57 & V_58 )
F_29 ( L_16 , V_34 ) ;
V_53 ( V_1 , V_34 , NULL , 0 ) ;
return;
}
if ( V_1 -> V_85 ) {
int V_86 ;
F_10 ( V_1 , V_87 ) ;
V_86 = V_1 -> V_72 - V_1 -> V_69 ;
if ( V_86 > 32 )
V_86 = 32 ;
V_1 -> V_85 [ V_1 -> V_69 ] = V_86 ;
V_1 -> V_69 += V_86 ;
if ( V_86 < 32 )
V_1 -> V_85 = NULL ;
V_51 = F_26 ( V_1 , F_34 ,
V_39 ,
V_88 ,
V_1 -> V_85 + V_1 -> V_69 ,
V_56 ) ;
if ( V_51 < 0 ) {
F_10 ( V_1 , V_84 ) ;
if ( V_1 -> V_57 & V_58 )
F_29 ( L_17 ) ;
V_53 ( V_1 , - V_59 , NULL , 0 ) ;
}
} else {
F_10 ( V_1 , V_89 ) ;
F_10 ( V_1 , V_87 ) ;
V_1 -> V_61 = V_90 ;
V_1 -> V_52 = V_91 ;
F_30 ( & V_1 -> V_63 ,
V_64 + V_92 ) ;
return;
}
}
static int F_35 ( struct V_1 * V_1 )
{
int V_51 ;
int V_47 ;
if ( V_1 -> V_93 > 32 ) {
V_47 = V_94 ;
V_1 -> V_85 = V_1 -> V_11 ;
V_1 -> V_72 = V_1 -> V_93 ;
V_1 -> V_69 = 32 ;
V_1 -> V_11 [ 0 ] = 32 ;
} else {
V_1 -> V_85 = NULL ;
V_47 = V_41 ;
V_1 -> V_11 [ 0 ] = V_1 -> V_93 ;
}
V_51 = F_26 ( V_1 , F_34 , V_39 ,
V_47 , V_1 -> V_11 , V_56 ) ;
if ( V_51 && ( V_1 -> V_57 & V_58 ) )
F_29 ( L_18 ) ;
return V_51 ;
}
static int F_12 ( struct V_1 * V_1 ,
unsigned char * V_11 ,
unsigned int V_60 )
{
if ( V_60 > V_75 )
return - V_76 ;
if ( V_60 > V_1 -> V_95 )
return - V_76 ;
V_1 -> V_61 = V_96 ;
memcpy ( V_1 -> V_11 + 1 , V_11 , V_60 ) ;
V_1 -> V_93 = V_60 ;
return F_35 ( V_1 ) ;
}
static void F_33 ( struct V_1 * V_1 , unsigned long * V_2 )
{
struct V_4 * V_5 ;
unsigned long V_24 ;
V_97:
if ( ! F_32 ( V_1 ) ) {
F_3 ( V_1 , V_2 ) ;
return;
}
if ( ! V_1 -> V_98 ) {
V_1 -> V_25 = NULL ;
F_3 ( V_1 , V_2 ) ;
} else {
int V_51 ;
V_1 -> V_25 = V_1 -> V_98 ;
V_1 -> V_98 = NULL ;
F_3 ( V_1 , V_2 ) ;
V_51 = F_12 ( V_1 ,
V_1 -> V_25 -> V_11 ,
V_1 -> V_25 -> V_23 ) ;
if ( V_51 ) {
V_5 = V_1 -> V_25 ;
V_1 -> V_25 = NULL ;
F_7 ( V_1 , V_5 ) ;
V_2 = F_1 ( V_1 , & V_24 ) ;
goto V_97;
}
}
}
static void F_36 ( void * V_99 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = (struct V_1 * ) V_99 ;
unsigned long V_24 , * V_2 ;
F_37 ( V_1 -> V_98 ) ;
V_1 -> V_98 = V_5 ;
V_2 = F_1 ( V_1 , & V_24 ) ;
F_33 ( V_1 , V_2 ) ;
if ( V_1 -> V_57 & V_100 ) {
struct V_101 V_102 ;
F_38 ( & V_102 ) ;
F_29 ( L_19 ,
V_5 -> V_11 [ 0 ] , V_5 -> V_11 [ 1 ] ,
( long ) V_102 . V_103 , ( long ) V_102 . V_104 ) ;
}
}
static int F_39 ( void * V_99 , struct V_105 * V_11 )
{
struct V_1 * V_1 = V_99 ;
V_11 -> V_106 = V_1 -> V_107 ;
V_11 -> V_108 = & V_1 -> V_40 -> V_108 ;
V_11 -> V_109 = V_1 -> V_109 ;
F_40 ( V_11 -> V_108 ) ;
return 0 ;
}
static void F_41 ( void * V_99 )
{
struct V_1 * V_1 = (struct V_1 * ) V_99 ;
unsigned long V_24 , * V_2 ;
if ( ! V_1 -> V_110 )
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
static int F_42 ( void * V_99 )
{
struct V_1 * V_1 = V_99 ;
if ( ! F_43 ( V_1 -> V_40 -> V_111 -> V_112 ) )
return - V_113 ;
F_44 ( V_1 -> V_40 ) ;
return 0 ;
}
static void F_45 ( void * V_99 )
{
struct V_1 * V_1 = V_99 ;
F_46 ( V_1 -> V_40 ) ;
F_47 ( V_1 -> V_40 -> V_111 ) ;
}
static int F_48 ( void * V_99 ,
T_1 V_6 )
{
struct V_1 * V_1 = V_99 ;
V_1 -> V_6 = V_6 ;
return 0 ;
}
static int F_49 ( struct V_114 * V_40 )
{
struct V_1 * V_1 = F_50 ( V_40 ) ;
int V_51 ;
if ( ! V_1 )
return 0 ;
V_51 = F_51 ( V_1 -> V_6 ) ;
if ( V_51 ) {
F_8 ( V_8 L_20 , V_51 ) ;
return V_51 ;
}
V_1 -> V_6 = NULL ;
while ( V_1 -> V_14 != V_18 )
F_52 ( 1 ) ;
V_1 -> V_36 = true ;
F_53 ( & V_1 -> V_63 ) ;
if ( V_1 -> V_115 ) {
F_27 ( & V_1 -> V_35 ) ;
F_54 ( V_1 -> V_115 ) ;
}
F_55 ( V_1 ) ;
return 0 ;
}
static int F_56 ( struct V_114 * V_40 , int V_60 , unsigned char * V_5 ,
int * V_116 , unsigned char * V_117 )
{
int V_118 ;
int V_119 ;
V_118 = V_96 ;
V_120:
V_119 = F_24 ( V_40 , V_41 , V_60 , V_5 ) ;
if ( V_119 ) {
V_118 -- ;
if ( V_118 > 0 )
goto V_120;
return - V_113 ;
}
V_119 = - V_113 ;
V_118 = V_90 ;
while ( V_118 > 0 ) {
V_119 = F_25 ( V_40 , V_44 ,
V_117 ) ;
if ( V_119 > 0 )
break;
F_57 ( V_121 ) ;
V_118 -- ;
if ( V_118 <= 0 )
break;
}
if ( V_119 > 0 ) {
if ( V_119 < 3 ||
( V_117 [ 0 ] != ( V_5 [ 0 ] | ( 1 << 2 ) ) ) ||
( V_117 [ 1 ] != V_5 [ 1 ] ) )
V_119 = - V_122 ;
else {
* V_116 = V_119 ;
V_119 = 0 ;
}
}
return V_119 ;
}
static int F_58 ( struct V_114 * V_40 , struct V_123 * V_124 )
{
unsigned char * V_117 ;
unsigned char V_5 [ 3 ] ;
int V_51 ;
int V_60 ;
V_117 = F_59 ( V_75 , V_125 ) ;
if ( ! V_117 )
return - V_126 ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_127 ;
V_51 = F_56 ( V_40 , 2 , V_5 , & V_60 , V_117 ) ;
if ( V_51 )
V_51 = - V_113 ;
else
F_60 ( V_124 -> type , V_128 , V_129 ) ;
F_55 ( V_117 ) ;
return V_51 ;
}
static int F_61 ( struct V_130 * V_131 , void * V_132 )
{
F_62 ( V_131 , L_21 ) ;
return F_63 ( V_131 ) ;
}
static int F_64 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
return F_65 ( V_134 , F_61 , V_133 -> V_135 ) ;
}
static int F_66 ( struct V_130 * V_131 , void * V_132 )
{
struct V_1 * V_1 = V_131 -> V_136 ;
F_67 ( V_131 , L_22 ,
F_68 ( V_1 , V_89 ) ) ;
F_67 ( V_131 , L_23 ,
F_68 ( V_1 , V_87 ) ) ;
F_67 ( V_131 , L_24 ,
F_68 ( V_1 , V_83 ) ) ;
F_67 ( V_131 , L_25 ,
F_68 ( V_1 , V_84 ) ) ;
F_67 ( V_131 , L_26 ,
F_68 ( V_1 , V_77 ) ) ;
F_67 ( V_131 , L_27 ,
F_68 ( V_1 , V_71 ) ) ;
F_67 ( V_131 , L_28 ,
F_68 ( V_1 , V_62 ) ) ;
F_67 ( V_131 , L_29 ,
F_68 ( V_1 , V_67 ) ) ;
F_67 ( V_131 , L_30 ,
F_68 ( V_1 , V_79 ) ) ;
F_67 ( V_131 , L_31 ,
F_68 ( V_1 , V_9 ) ) ;
F_67 ( V_131 , L_32 ,
F_68 ( V_1 , V_81 ) ) ;
F_67 ( V_131 , L_33 ,
F_68 ( V_1 , V_31 ) ) ;
return 0 ;
}
static int F_69 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
return F_65 ( V_134 , F_66 , F_70 ( V_133 ) ) ;
}
static struct V_137 * F_71 ( unsigned short V_138 ,
char * V_139 ,
bool V_140 )
{
struct V_137 * V_124 , * V_141 = NULL ;
V_97:
F_72 (info, &ssif_infos, link) {
if ( V_124 -> V_142 . V_138 == V_138 ) {
if ( V_124 -> V_139 || V_139 ) {
if ( ! V_124 -> V_139 != ! V_139 ) {
continue;
}
if ( strcmp ( V_124 -> V_139 , V_139 ) )
continue;
}
V_141 = V_124 ;
break;
}
}
if ( ! V_141 && V_140 ) {
V_139 = NULL ;
V_140 = false ;
goto V_97;
}
return V_141 ;
}
static bool F_73 ( struct V_1 * V_1 , struct V_143 * V_108 )
{
#ifdef F_74
T_3 T_3 ;
T_3 = F_75 ( V_108 ) ;
if ( T_3 ) {
V_1 -> V_107 = V_144 ;
V_1 -> V_109 . V_145 . T_3 = T_3 ;
return true ;
}
#endif
return false ;
}
static int F_76 ( struct V_114 * V_40 , const struct V_146 * V_147 )
{
unsigned char V_5 [ 3 ] ;
unsigned char * V_117 ;
struct V_1 * V_1 ;
int V_51 = 0 ;
int V_60 ;
int V_70 ;
T_4 V_148 = 0 ;
struct V_137 * V_109 = NULL ;
V_117 = F_59 ( V_75 , V_125 ) ;
if ( ! V_117 )
return - V_126 ;
V_1 = F_77 ( sizeof( * V_1 ) , V_125 ) ;
if ( ! V_1 ) {
F_55 ( V_117 ) ;
return - V_126 ;
}
if ( ! F_73 ( V_1 , & V_40 -> V_108 ) ) {
V_109 = F_71 ( V_40 -> V_138 , V_40 -> V_111 -> V_149 ,
true ) ;
if ( ! V_109 ) {
V_1 -> V_107 = V_150 ;
} else {
V_1 -> V_107 = V_109 -> V_106 ;
V_1 -> V_57 = V_109 -> V_151 ;
V_1 -> V_109 = V_109 -> V_109 ;
V_148 = V_109 -> V_148 ;
}
}
F_29 ( V_8 L_34 ,
F_78 ( V_1 -> V_107 ) ,
V_40 -> V_138 , V_40 -> V_111 -> V_149 , V_148 ) ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_127 ;
V_51 = F_56 ( V_40 , 2 , V_5 , & V_60 , V_117 ) ;
if ( V_51 )
goto V_152;
V_51 = F_79 ( V_117 , V_60 , & V_1 -> V_153 ) ;
if ( V_51 )
goto V_152;
V_1 -> V_40 = V_40 ;
F_80 ( V_40 , V_1 ) ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_154 ;
V_5 [ 2 ] = 0 ;
V_51 = F_56 ( V_40 , 3 , V_5 , & V_60 , V_117 ) ;
if ( ! V_51 && ( V_60 >= 3 ) && ( V_117 [ 2 ] == 0 ) ) {
if ( V_60 < 7 ) {
if ( V_155 )
F_29 ( V_8 L_35 , V_60 ) ;
goto V_156;
}
V_1 -> V_95 = V_117 [ 5 ] ;
V_1 -> V_157 = V_117 [ 6 ] ;
V_1 -> V_158 = ( V_117 [ 4 ] >> 6 ) & 0x3 ;
V_1 -> V_159 = ( V_117 [ 4 ] >> 3 ) & 0x1 ;
switch ( V_1 -> V_158 ) {
case V_160 :
if ( V_1 -> V_95 > 32 )
V_1 -> V_95 = 32 ;
if ( V_1 -> V_157 > 32 )
V_1 -> V_157 = 32 ;
break;
case V_161 :
if ( V_1 -> V_95 > 64 )
V_1 -> V_95 = 64 ;
if ( V_1 -> V_157 > 62 )
V_1 -> V_157 = 62 ;
break;
case V_162 :
break;
default:
goto V_156;
}
} else {
V_156:
F_29 ( V_8 L_36 ,
V_51 , V_60 , V_117 [ 2 ] ) ;
V_1 -> V_95 = 32 ;
V_1 -> V_157 = 32 ;
V_1 -> V_158 = V_160 ;
V_1 -> V_159 = 0 ;
}
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_17 ;
V_5 [ 2 ] = V_13 ;
V_51 = F_56 ( V_40 , 3 , V_5 , & V_60 , V_117 ) ;
if ( V_51 || ( V_60 < 3 ) || ( V_117 [ 2 ] != 0 ) )
F_31 ( V_8 L_37 ,
V_51 , V_60 , V_117 [ 2 ] ) ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_163 ;
V_51 = F_56 ( V_40 , 2 , V_5 , & V_60 , V_117 ) ;
if ( V_51 || ( V_60 < 4 ) || ( V_117 [ 2 ] != 0 ) ) {
F_31 ( V_8 L_38 ,
V_51 , V_60 , V_117 [ 2 ] ) ;
V_51 = 0 ;
goto V_141;
}
if ( V_117 [ 3 ] & V_164 ) {
V_1 -> V_110 = true ;
goto V_141;
}
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_165 ;
V_5 [ 2 ] = V_117 [ 3 ] | V_164 ;
V_51 = F_56 ( V_40 , 3 , V_5 , & V_60 , V_117 ) ;
if ( V_51 || ( V_60 < 2 ) ) {
F_31 ( V_8 L_38 ,
V_51 , V_60 , V_117 [ 2 ] ) ;
V_51 = 0 ;
goto V_141;
}
if ( V_117 [ 2 ] == 0 )
V_1 -> V_110 = true ;
V_141:
V_1 -> V_166 = F_81 ( & V_167 ) ;
if ( V_155 ) {
F_29 ( L_39 ,
V_40 -> V_138 ) ;
}
F_82 ( & V_1 -> V_3 ) ;
V_1 -> V_14 = V_18 ;
F_83 ( & V_1 -> V_63 ) ;
V_1 -> V_63 . V_11 = ( unsigned long ) V_1 ;
V_1 -> V_63 . V_168 = F_28 ;
for ( V_70 = 0 ; V_70 < V_169 ; V_70 ++ )
F_84 ( & V_1 -> V_170 [ V_70 ] , 0 ) ;
if ( V_1 -> V_159 )
V_1 -> V_40 -> V_2 |= V_171 ;
V_1 -> V_172 . V_173 = V_174 ;
V_1 -> V_172 . V_175 = F_48 ;
V_1 -> V_172 . F_39 = F_39 ;
V_1 -> V_172 . F_36 = F_36 ;
V_1 -> V_172 . F_41 = F_41 ;
V_1 -> V_172 . F_42 = F_42 ;
V_1 -> V_172 . F_45 = F_45 ;
{
unsigned int V_176 ;
V_176 = ( ( V_1 -> V_40 -> V_111 -> V_112 << 8 ) |
V_1 -> V_40 -> V_138 ) ;
F_23 ( & V_1 -> V_35 ) ;
V_1 -> V_115 = F_85 ( F_20 , V_1 ,
L_40 , V_176 ) ;
if ( F_86 ( V_1 -> V_115 ) ) {
V_51 = F_87 ( V_1 -> V_115 ) ;
F_88 ( & V_1 -> V_40 -> V_108 ,
L_41 ,
V_51 ) ;
goto V_152;
}
}
V_51 = F_89 ( & V_1 -> V_172 ,
V_1 ,
& V_1 -> V_153 ,
& V_1 -> V_40 -> V_108 ,
V_148 ) ;
if ( V_51 ) {
F_8 ( V_8 L_42 , V_51 ) ;
goto V_152;
}
V_51 = F_90 ( V_1 -> V_6 , L_43 ,
& V_177 ,
V_1 ) ;
if ( V_51 ) {
F_8 ( V_8 L_44 , V_51 ) ;
goto V_178;
}
V_51 = F_90 ( V_1 -> V_6 , L_45 ,
& V_179 ,
V_1 ) ;
if ( V_51 ) {
F_8 ( V_8 L_44 , V_51 ) ;
goto V_178;
}
V_152:
if ( V_51 )
F_55 ( V_1 ) ;
F_55 ( V_117 ) ;
return V_51 ;
V_178:
F_51 ( V_1 -> V_6 ) ;
goto V_152;
}
static int F_91 ( struct V_143 * V_180 , void * V_181 )
{
struct V_137 * V_109 = V_181 ;
if ( V_180 -> type != & V_182 )
return 0 ;
F_92 ( F_93 ( V_180 ) , & V_109 -> V_142 ) ;
if ( ! V_109 -> V_139 )
return 1 ;
return 0 ;
}
static int F_94 ( int V_138 , char * V_139 ,
int V_151 , int V_148 ,
enum V_183 V_106 )
{
struct V_137 * V_109 ;
int V_51 = 0 ;
F_95 ( & V_184 ) ;
if ( F_71 ( V_138 , V_139 , false ) ) {
V_51 = - V_185 ;
goto V_186;
}
V_109 = F_77 ( sizeof( * V_109 ) , V_125 ) ;
if ( ! V_109 ) {
V_51 = - V_126 ;
goto V_186;
}
if ( V_139 ) {
V_109 -> V_139 = F_96 ( V_139 , V_125 ) ;
if ( ! V_109 -> V_139 ) {
F_55 ( V_109 ) ;
V_51 = - V_126 ;
goto V_186;
}
}
strncpy ( V_109 -> V_142 . type , V_128 ,
sizeof( V_109 -> V_142 . type ) ) ;
V_109 -> V_142 . V_138 = V_138 ;
V_109 -> V_142 . V_187 = V_109 ;
V_109 -> V_151 = V_151 ;
V_109 -> V_148 = V_148 ;
V_109 -> V_106 = V_106 ;
F_97 ( & V_109 -> V_188 , & V_189 ) ;
if ( V_190 )
F_98 ( V_109 , F_91 ) ;
V_186:
F_99 ( & V_184 ) ;
return V_51 ;
}
static void F_100 ( void )
{
struct V_137 * V_124 , * V_191 ;
F_95 ( & V_184 ) ;
F_101 (info, tmp, &ssif_infos, link) {
F_102 ( & V_124 -> V_188 ) ;
F_55 ( V_124 -> V_139 ) ;
F_55 ( V_124 ) ;
}
F_99 ( & V_184 ) ;
}
static unsigned short * F_103 ( void )
{
struct V_137 * V_124 ;
unsigned int V_192 = 0 , V_70 ;
unsigned short * V_193 ;
F_72 (info, &ssif_infos, link)
V_192 ++ ;
V_193 = F_77 ( sizeof( * V_193 ) * ( V_192 + 1 ) , V_125 ) ;
if ( ! V_193 )
return NULL ;
V_70 = 0 ;
F_72 (info, &ssif_infos, link) {
unsigned short V_138 = V_124 -> V_142 . V_138 ;
int V_194 ;
for ( V_194 = 0 ; V_194 < V_70 ; V_194 ++ ) {
if ( V_193 [ V_194 ] == V_138 )
goto V_195;
}
V_193 [ V_70 ] = V_138 ;
V_195:
V_70 ++ ;
}
V_193 [ V_70 ] = V_196 ;
return V_193 ;
}
static int F_104 ( struct V_197 * V_198 )
{
unsigned short V_199 ;
if ( V_200 >= V_201 )
return - 1 ;
if ( V_198 -> V_202 != 1 ) {
F_31 ( L_46 , V_198 -> V_202 ) ;
return - V_113 ;
}
if ( V_198 -> V_203 != 4 )
return - V_113 ;
if ( V_198 -> V_138 . V_204 != V_205 ) {
F_31 ( V_8 L_47 ,
V_198 -> V_138 . V_204 ) ;
return - V_59 ;
}
V_199 = V_198 -> V_138 . V_206 >> 1 ;
return F_94 ( V_199 , NULL , 0 , 0 , V_207 ) ;
}
static void F_105 ( void )
{
T_5 V_208 ;
struct V_197 * V_198 ;
int V_70 ;
if ( V_209 )
return;
if ( V_210 )
return;
for ( V_70 = 0 ; ; V_70 ++ ) {
V_208 = F_106 ( V_211 , V_70 + 1 ,
(struct V_212 * * ) & V_198 ) ;
if ( V_208 != V_213 )
return;
F_104 ( V_198 ) ;
}
}
static void F_105 ( void ) { }
static int F_107 ( const struct V_214 * V_215 )
{
struct V_216 * V_217 = V_215 -> V_218 ;
T_4 * V_11 = ( T_4 * ) V_217 ;
T_4 V_60 = V_217 -> V_219 ;
unsigned short V_199 ;
int V_148 ;
if ( V_200 >= V_201 )
return - 1 ;
if ( V_60 < 9 )
return - 1 ;
if ( V_11 [ 0x04 ] != 4 )
return - 1 ;
if ( ( V_11 [ 8 ] >> 1 ) == 0 ) {
V_199 = V_11 [ 6 ] >> 1 ;
V_148 = 0 ;
} else {
V_199 = V_11 [ 8 ] >> 1 ;
V_148 = V_11 [ 6 ] ;
}
return F_94 ( V_199 , NULL , 0 , 0 , V_220 ) ;
}
static void F_108 ( void )
{
const struct V_214 * V_108 = NULL ;
while ( ( V_108 = F_109 ( V_221 , NULL , V_108 ) ) )
F_107 ( V_108 ) ;
}
static void F_108 ( void ) { }
static int F_110 ( void )
{
int V_70 ;
int V_51 ;
if ( V_190 )
return 0 ;
F_29 ( L_48 ) ;
for ( V_70 = 0 ; V_70 < V_200 ; V_70 ++ ) {
V_51 = F_94 ( V_138 [ V_70 ] , V_139 [ V_70 ] ,
V_222 [ V_70 ] , V_223 [ V_70 ] ,
V_224 ) ;
if ( ! V_51 )
F_8 ( V_8
L_49 ,
V_138 [ V_70 ] ) ;
}
if ( V_225 )
V_226 . V_227 . V_228 =
F_111 ( V_229 ) ;
if ( V_230 )
F_108 () ;
if ( V_225 )
F_105 () ;
V_226 . V_193 = F_103 () ;
V_51 = F_112 ( & V_226 ) ;
if ( ! V_51 )
V_190 = true ;
return V_51 ;
}
static void F_113 ( void )
{
if ( ! V_190 )
return;
V_190 = false ;
F_114 ( & V_226 ) ;
F_100 () ;
}
