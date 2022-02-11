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
V_1 -> V_40 , V_1 -> V_41 ,
V_1 -> V_42 [ 0 ] ,
V_1 -> V_42 + 1 ) ;
V_1 -> V_43 ( V_1 , V_34 , NULL , 0 ) ;
} else {
V_34 = F_25 (
V_1 -> V_40 , V_1 -> V_41 ,
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
T_2 V_44 ,
int V_45 , int V_46 ,
unsigned char * V_11 , unsigned int V_47 )
{
V_1 -> V_43 = V_44 ;
V_1 -> V_38 = V_45 ;
V_1 -> V_41 = V_46 ;
V_1 -> V_42 = V_11 ;
V_1 -> V_48 = V_47 ;
F_27 ( & V_1 -> V_35 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_1 )
{
int V_49 ;
V_1 -> V_50 = 0 ;
V_1 -> V_51 = 0 ;
V_49 = F_26 ( V_1 , V_52 , V_53 ,
V_54 ,
V_1 -> V_55 , V_56 ) ;
if ( V_49 < 0 ) {
if ( V_1 -> V_57 & V_58 )
F_29 ( L_2 ) ;
V_52 ( V_1 , - V_59 , NULL , 0 ) ;
}
}
static void F_30 ( unsigned long V_11 )
{
struct V_1 * V_1 = ( void * ) V_11 ;
unsigned long V_24 , * V_2 ;
bool V_60 ;
if ( V_1 -> V_36 )
return;
V_2 = F_1 ( V_1 , & V_24 ) ;
V_60 = V_1 -> V_61 ;
V_1 -> V_61 = false ;
F_3 ( V_1 , V_2 ) ;
if ( V_60 )
F_28 ( V_1 ) ;
}
static void F_31 ( struct V_62 * V_40 , enum V_63 type ,
unsigned int V_11 )
{
struct V_1 * V_1 = F_32 ( V_40 ) ;
unsigned long V_24 , * V_2 ;
bool V_64 = false ;
if ( type != V_65 )
return;
F_10 ( V_1 , V_66 ) ;
V_2 = F_1 ( V_1 , & V_24 ) ;
if ( V_1 -> V_61 ) {
V_1 -> V_61 = false ;
F_33 ( & V_1 -> V_67 ) ;
V_64 = true ;
} else if ( V_1 -> V_25 ) {
V_1 -> V_68 = true ;
}
F_3 ( V_1 , V_2 ) ;
if ( V_64 )
F_28 ( V_1 ) ;
}
static void V_52 ( struct V_1 * V_1 , int V_34 ,
unsigned char * V_11 , unsigned int V_69 )
{
struct V_4 * V_5 ;
unsigned long V_24 , * V_2 ;
int V_49 ;
if ( V_34 < 0 ) {
V_1 -> V_70 -- ;
if ( V_1 -> V_70 > 0 ) {
F_10 ( V_1 , V_71 ) ;
V_2 = F_1 ( V_1 , & V_24 ) ;
V_1 -> V_61 = true ;
V_1 -> V_50 = V_72 ;
F_34 ( & V_1 -> V_67 ,
V_73 + V_74 ) ;
F_3 ( V_1 , V_2 ) ;
return;
}
F_10 ( V_1 , V_75 ) ;
if ( V_1 -> V_57 & V_58 )
F_29 ( L_3 , V_34 ) ;
V_69 = 0 ;
goto V_76;
}
if ( ( V_69 > 1 ) && ( V_1 -> V_51 == 0 )
&& ( V_11 [ 0 ] == 0x00 ) && ( V_11 [ 1 ] == 0x01 ) ) {
int V_77 ;
F_10 ( V_1 , V_78 ) ;
V_69 -= 2 ;
for ( V_77 = 0 ; V_77 < V_69 ; V_77 ++ )
V_1 -> V_11 [ V_77 ] = V_11 [ V_77 + 2 ] ;
V_1 -> V_79 = V_69 ;
V_1 -> V_51 = 1 ;
V_49 = F_26 ( V_1 , V_52 , V_53 ,
V_80 ,
V_1 -> V_55 , V_56 ) ;
if ( V_49 < 0 ) {
if ( V_1 -> V_57 & V_58 )
F_29 ( L_4 ) ;
V_34 = - V_59 ;
} else
return;
} else if ( V_1 -> V_51 ) {
int V_77 ;
unsigned char V_81 ;
if ( V_69 == 0 ) {
V_34 = - V_59 ;
if ( V_1 -> V_57 & V_58 )
F_29 ( V_8 L_5 ) ;
goto V_76;
}
V_81 = V_11 [ 0 ] ;
if ( V_1 -> V_79 + V_69 - 1 > V_82 ) {
V_34 = - V_83 ;
if ( V_1 -> V_57 & V_58 )
F_29 ( L_6 ) ;
goto V_76;
}
V_69 -- ;
for ( V_77 = 0 ; V_77 < V_69 ; V_77 ++ )
V_1 -> V_11 [ V_77 + V_1 -> V_79 ] = V_11 [ V_77 + 1 ] ;
V_1 -> V_79 += V_69 ;
if ( V_81 == 0xff ) {
V_69 = V_1 -> V_79 ;
V_11 = V_1 -> V_11 ;
} else if ( V_81 + 1 != V_1 -> V_51 ) {
V_34 = - V_59 ;
} else {
F_10 ( V_1 , V_78 ) ;
V_1 -> V_51 ++ ;
V_49 = F_26 ( V_1 , V_52 ,
V_53 ,
V_80 ,
V_1 -> V_55 ,
V_56 ) ;
if ( V_49 < 0 ) {
if ( V_1 -> V_57 & V_58 )
F_29 ( V_8
L_7 ) ;
V_34 = - V_59 ;
} else
return;
}
}
if ( V_34 < 0 ) {
F_10 ( V_1 , V_75 ) ;
} else {
F_10 ( V_1 , V_84 ) ;
F_10 ( V_1 , V_78 ) ;
}
V_76:
if ( V_1 -> V_57 & V_85 )
F_29 ( V_8 L_8 ,
V_1 -> V_14 , V_34 ) ;
V_2 = F_1 ( V_1 , & V_24 ) ;
V_5 = V_1 -> V_25 ;
if ( V_5 ) {
V_5 -> V_7 = V_69 ;
if ( V_5 -> V_7 > V_82 )
V_5 -> V_7 = V_82 ;
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
if ( ( V_34 < 0 ) || ( V_69 < 4 ) || ( V_11 [ 2 ] != 0 ) ) {
V_1 -> V_14 = V_18 ;
F_3 ( V_1 , V_2 ) ;
F_35 ( V_8 L_9 ,
V_34 , V_69 , V_11 [ 2 ] ) ;
} else if ( V_11 [ 0 ] != ( V_16 | 1 ) << 2
|| V_11 [ 1 ] != V_22 ) {
F_35 ( V_8 L_10 ,
V_11 [ 0 ] , V_11 [ 1 ] ) ;
} else {
F_10 ( V_1 , V_86 ) ;
V_1 -> V_12 = V_11 [ 3 ] ;
F_18 ( V_1 , V_2 ) ;
}
break;
case V_15 :
if ( ( V_34 < 0 ) || ( V_69 < 3 ) || ( V_11 [ 2 ] != 0 ) ) {
F_35 ( V_8 L_11 ,
V_34 , V_69 , V_11 [ 2 ] ) ;
} else if ( V_11 [ 0 ] != ( V_16 | 1 ) << 2
|| V_11 [ 1 ] != V_17 ) {
F_35 ( V_8 L_12 ,
V_11 [ 0 ] , V_11 [ 1 ] ) ;
}
V_1 -> V_14 = V_18 ;
F_3 ( V_1 , V_2 ) ;
break;
case V_27 :
if ( ( V_34 < 0 ) || ( V_69 < 3 ) || ( V_5 -> V_10 [ 2 ] != 0 ) ) {
V_5 -> V_87 ( V_5 ) ;
V_1 -> V_12 &= ~ V_33 ;
F_18 ( V_1 , V_2 ) ;
} else if ( V_5 -> V_10 [ 0 ] != ( V_16 | 1 ) << 2
|| V_5 -> V_10 [ 1 ] != V_28 ) {
F_35 ( V_8 L_13 ,
V_5 -> V_10 [ 0 ] , V_5 -> V_10 [ 1 ] ) ;
V_5 -> V_87 ( V_5 ) ;
V_1 -> V_12 &= ~ V_33 ;
F_18 ( V_1 , V_2 ) ;
} else {
F_18 ( V_1 , V_2 ) ;
F_10 ( V_1 , V_88 ) ;
F_5 ( V_1 , V_5 ) ;
}
break;
case V_29 :
if ( ( V_34 < 0 ) || ( V_69 < 3 ) || ( V_5 -> V_10 [ 2 ] != 0 ) ) {
V_5 -> V_87 ( V_5 ) ;
V_1 -> V_12 &= ~ V_32 ;
F_18 ( V_1 , V_2 ) ;
} else if ( V_5 -> V_10 [ 0 ] != ( V_16 | 1 ) << 2
|| V_5 -> V_10 [ 1 ] != V_30 ) {
F_35 ( V_8 L_12 ,
V_5 -> V_10 [ 0 ] , V_5 -> V_10 [ 1 ] ) ;
V_5 -> V_87 ( V_5 ) ;
V_1 -> V_12 &= ~ V_32 ;
F_18 ( V_1 , V_2 ) ;
} else {
F_10 ( V_1 , V_89 ) ;
F_18 ( V_1 , V_2 ) ;
F_5 ( V_1 , V_5 ) ;
}
break;
}
V_2 = F_1 ( V_1 , & V_24 ) ;
if ( F_36 ( V_1 ) && ! V_1 -> V_36 ) {
if ( V_1 -> V_26 )
F_15 ( V_1 , V_2 ) ;
else if ( V_1 -> V_20 )
F_13 ( V_1 , V_2 ) ;
else
F_37 ( V_1 , V_2 ) ;
} else
F_3 ( V_1 , V_2 ) ;
if ( V_1 -> V_57 & V_85 )
F_29 ( V_8 L_14 , V_1 -> V_14 ) ;
}
static void F_38 ( struct V_1 * V_1 , int V_34 ,
unsigned char * V_11 , unsigned int V_69 )
{
int V_49 ;
if ( V_34 < 0 ) {
V_1 -> V_70 -- ;
if ( V_1 -> V_70 > 0 ) {
if ( ! F_39 ( V_1 ) ) {
F_10 ( V_1 , V_90 ) ;
return;
}
F_10 ( V_1 , V_91 ) ;
if ( V_1 -> V_57 & V_58 )
F_29 ( V_8
L_15 ) ;
V_52 ( V_1 , - V_59 , NULL , 0 ) ;
return;
}
F_10 ( V_1 , V_91 ) ;
if ( V_1 -> V_57 & V_58 )
F_29 ( L_16 , V_34 ) ;
V_52 ( V_1 , V_34 , NULL , 0 ) ;
return;
}
if ( V_1 -> V_92 ) {
int V_93 ;
unsigned char * V_94 ;
F_10 ( V_1 , V_95 ) ;
V_93 = V_1 -> V_79 - V_1 -> V_51 ;
if ( V_93 > 32 )
V_93 = 32 ;
V_1 -> V_92 [ V_1 -> V_51 ] = V_93 ;
V_94 = V_1 -> V_92 + V_1 -> V_51 ;
V_1 -> V_51 += V_93 ;
if ( V_93 < 32 )
V_1 -> V_92 = NULL ;
V_49 = F_26 ( V_1 , F_38 ,
V_39 ,
V_96 ,
V_94 ,
V_56 ) ;
if ( V_49 < 0 ) {
F_10 ( V_1 , V_91 ) ;
if ( V_1 -> V_57 & V_58 )
F_29 ( L_17 ) ;
V_52 ( V_1 , - V_59 , NULL , 0 ) ;
}
} else {
unsigned long V_24 , * V_2 ;
F_10 ( V_1 , V_97 ) ;
F_10 ( V_1 , V_95 ) ;
V_2 = F_1 ( V_1 , & V_24 ) ;
if ( V_1 -> V_68 ) {
V_1 -> V_68 = false ;
F_3 ( V_1 , V_2 ) ;
F_28 ( V_1 ) ;
} else {
V_1 -> V_61 = true ;
V_1 -> V_70 = V_98 ;
V_1 -> V_50 = V_99 ;
F_34 ( & V_1 -> V_67 ,
V_73 + V_100 ) ;
F_3 ( V_1 , V_2 ) ;
}
}
}
static int F_39 ( struct V_1 * V_1 )
{
int V_49 ;
int V_46 ;
V_1 -> V_68 = false ;
if ( V_1 -> V_101 > 32 ) {
V_46 = V_102 ;
V_1 -> V_92 = V_1 -> V_11 ;
V_1 -> V_79 = V_1 -> V_101 ;
V_1 -> V_51 = 32 ;
V_1 -> V_11 [ 0 ] = 32 ;
} else {
V_1 -> V_92 = NULL ;
V_46 = V_103 ;
V_1 -> V_11 [ 0 ] = V_1 -> V_101 ;
}
V_49 = F_26 ( V_1 , F_38 , V_39 ,
V_46 , V_1 -> V_11 , V_56 ) ;
if ( V_49 && ( V_1 -> V_57 & V_58 ) )
F_29 ( L_18 ) ;
return V_49 ;
}
static int F_12 ( struct V_1 * V_1 ,
unsigned char * V_11 ,
unsigned int V_69 )
{
if ( V_69 > V_82 )
return - V_83 ;
if ( V_69 > V_1 -> V_104 )
return - V_83 ;
V_1 -> V_70 = V_105 ;
memcpy ( V_1 -> V_11 + 1 , V_11 , V_69 ) ;
V_1 -> V_101 = V_69 ;
return F_39 ( V_1 ) ;
}
static void F_37 ( struct V_1 * V_1 , unsigned long * V_2 )
{
struct V_4 * V_5 ;
unsigned long V_24 ;
V_106:
if ( ! F_36 ( V_1 ) ) {
F_3 ( V_1 , V_2 ) ;
return;
}
if ( ! V_1 -> V_107 ) {
V_1 -> V_25 = NULL ;
F_3 ( V_1 , V_2 ) ;
} else {
int V_49 ;
V_1 -> V_25 = V_1 -> V_107 ;
V_1 -> V_107 = NULL ;
F_3 ( V_1 , V_2 ) ;
V_49 = F_12 ( V_1 ,
V_1 -> V_25 -> V_11 ,
V_1 -> V_25 -> V_23 ) ;
if ( V_49 ) {
V_5 = V_1 -> V_25 ;
V_1 -> V_25 = NULL ;
F_7 ( V_1 , V_5 ) ;
V_2 = F_1 ( V_1 , & V_24 ) ;
goto V_106;
}
}
}
static void F_40 ( void * V_108 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = (struct V_1 * ) V_108 ;
unsigned long V_24 , * V_2 ;
F_41 ( V_1 -> V_107 ) ;
V_1 -> V_107 = V_5 ;
V_2 = F_1 ( V_1 , & V_24 ) ;
F_37 ( V_1 , V_2 ) ;
if ( V_1 -> V_57 & V_109 ) {
struct V_110 V_111 ;
F_42 ( & V_111 ) ;
F_29 ( L_19 ,
V_5 -> V_11 [ 0 ] , V_5 -> V_11 [ 1 ] ,
( long long ) V_111 . V_112 , ( long ) V_111 . V_113 / V_114 ) ;
}
}
static int F_43 ( void * V_108 , struct V_115 * V_11 )
{
struct V_1 * V_1 = V_108 ;
V_11 -> V_116 = V_1 -> V_117 ;
V_11 -> V_118 = & V_1 -> V_40 -> V_118 ;
V_11 -> V_119 = V_1 -> V_119 ;
F_44 ( V_11 -> V_118 ) ;
return 0 ;
}
static void F_45 ( void * V_108 )
{
struct V_1 * V_1 = (struct V_1 * ) V_108 ;
unsigned long V_24 , * V_2 ;
if ( ! V_1 -> V_120 )
return;
V_2 = F_1 ( V_1 , & V_24 ) ;
V_1 -> V_26 = true ;
if ( F_36 ( V_1 ) )
F_13 ( V_1 , V_2 ) ;
else {
V_1 -> V_20 = true ;
F_3 ( V_1 , V_2 ) ;
}
}
static int F_46 ( void * V_108 )
{
struct V_1 * V_1 = V_108 ;
if ( ! F_47 ( V_1 -> V_40 -> V_121 -> V_122 ) )
return - V_123 ;
F_48 ( V_1 -> V_40 ) ;
return 0 ;
}
static void F_49 ( void * V_108 )
{
struct V_1 * V_1 = V_108 ;
F_50 ( V_1 -> V_40 ) ;
F_51 ( V_1 -> V_40 -> V_121 ) ;
}
static int F_52 ( void * V_108 ,
T_1 V_6 )
{
struct V_1 * V_1 = V_108 ;
V_1 -> V_6 = V_6 ;
return 0 ;
}
static int F_53 ( struct V_62 * V_40 )
{
struct V_1 * V_1 = F_32 ( V_40 ) ;
int V_49 ;
if ( ! V_1 )
return 0 ;
V_49 = F_54 ( V_1 -> V_6 ) ;
if ( V_49 ) {
F_8 ( V_8 L_20 , V_49 ) ;
return V_49 ;
}
V_1 -> V_6 = NULL ;
while ( V_1 -> V_14 != V_18 )
F_55 ( 1 ) ;
V_1 -> V_36 = true ;
F_56 ( & V_1 -> V_67 ) ;
if ( V_1 -> V_124 ) {
F_27 ( & V_1 -> V_35 ) ;
F_57 ( V_1 -> V_124 ) ;
}
F_58 ( V_1 ) ;
return 0 ;
}
static int F_59 ( struct V_62 * V_40 , int V_69 , unsigned char * V_5 ,
int * V_125 , unsigned char * V_126 )
{
int V_127 ;
int V_128 ;
V_127 = V_105 ;
V_129:
V_128 = F_24 ( V_40 , V_103 , V_69 , V_5 ) ;
if ( V_128 ) {
V_127 -- ;
if ( V_127 > 0 )
goto V_129;
return - V_123 ;
}
V_128 = - V_123 ;
V_127 = V_98 ;
while ( V_127 > 0 ) {
V_128 = F_25 ( V_40 , V_54 ,
V_126 ) ;
if ( V_128 > 0 )
break;
F_60 ( V_130 ) ;
V_127 -- ;
if ( V_127 <= 0 )
break;
}
if ( V_128 > 0 ) {
if ( V_128 < 3 ||
( V_126 [ 0 ] != ( V_5 [ 0 ] | ( 1 << 2 ) ) ) ||
( V_126 [ 1 ] != V_5 [ 1 ] ) )
V_128 = - V_131 ;
else {
* V_125 = V_128 ;
V_128 = 0 ;
}
}
return V_128 ;
}
static int F_61 ( struct V_62 * V_40 , struct V_132 * V_133 )
{
unsigned char * V_126 ;
unsigned char V_5 [ 3 ] ;
int V_49 ;
int V_69 ;
V_126 = F_62 ( V_82 , V_134 ) ;
if ( ! V_126 )
return - V_135 ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_136 ;
V_49 = F_59 ( V_40 , 2 , V_5 , & V_69 , V_126 ) ;
if ( V_49 )
V_49 = - V_123 ;
else
F_63 ( V_133 -> type , V_137 , V_138 ) ;
F_58 ( V_126 ) ;
return V_49 ;
}
static int F_64 ( struct V_139 * V_140 , void * V_141 )
{
F_65 ( V_140 , L_21 ) ;
return 0 ;
}
static int F_66 ( struct V_142 * V_142 , struct V_143 * V_143 )
{
return F_67 ( V_143 , F_64 , V_142 -> V_144 ) ;
}
static int F_68 ( struct V_139 * V_140 , void * V_141 )
{
struct V_1 * V_1 = V_140 -> V_145 ;
F_69 ( V_140 , L_22 ,
F_70 ( V_1 , V_97 ) ) ;
F_69 ( V_140 , L_23 ,
F_70 ( V_1 , V_95 ) ) ;
F_69 ( V_140 , L_24 ,
F_70 ( V_1 , V_90 ) ) ;
F_69 ( V_140 , L_25 ,
F_70 ( V_1 , V_91 ) ) ;
F_69 ( V_140 , L_26 ,
F_70 ( V_1 , V_84 ) ) ;
F_69 ( V_140 , L_27 ,
F_70 ( V_1 , V_78 ) ) ;
F_69 ( V_140 , L_28 ,
F_70 ( V_1 , V_71 ) ) ;
F_69 ( V_140 , L_29 ,
F_70 ( V_1 , V_75 ) ) ;
F_69 ( V_140 , L_30 ,
F_70 ( V_1 , V_86 ) ) ;
F_69 ( V_140 , L_31 ,
F_70 ( V_1 , V_9 ) ) ;
F_69 ( V_140 , L_32 ,
F_70 ( V_1 , V_88 ) ) ;
F_69 ( V_140 , L_33 ,
F_70 ( V_1 , V_31 ) ) ;
F_69 ( V_140 , L_34 ,
F_70 ( V_1 , V_66 ) ) ;
return 0 ;
}
static int F_71 ( struct V_142 * V_142 , struct V_143 * V_143 )
{
return F_67 ( V_143 , F_68 , F_72 ( V_142 ) ) ;
}
static int F_73 ( char * V_146 , char * V_147 )
{
while ( * V_146 && * V_147 ) {
while ( isspace ( * V_146 ) )
V_146 ++ ;
while ( isspace ( * V_147 ) )
V_147 ++ ;
if ( * V_146 > * V_147 )
return 1 ;
if ( * V_146 < * V_147 )
return - 1 ;
V_146 ++ ;
V_147 ++ ;
}
return 0 ;
}
static struct V_148 * F_74 ( unsigned short V_149 ,
char * V_150 ,
bool V_151 )
{
struct V_148 * V_133 , * V_152 = NULL ;
V_106:
F_75 (info, &ssif_infos, link) {
if ( V_133 -> V_153 . V_149 == V_149 ) {
if ( V_133 -> V_150 || V_150 ) {
if ( ! V_133 -> V_150 != ! V_150 ) {
continue;
}
if ( V_150 &&
F_73 ( V_133 -> V_150 ,
V_150 ) )
continue;
}
V_152 = V_133 ;
break;
}
}
if ( ! V_152 && V_151 ) {
V_150 = NULL ;
V_151 = false ;
goto V_106;
}
return V_152 ;
}
static bool F_76 ( struct V_1 * V_1 , struct V_154 * V_118 )
{
#ifdef F_77
T_3 T_3 ;
T_3 = F_78 ( V_118 ) ;
if ( T_3 ) {
V_1 -> V_117 = V_155 ;
V_1 -> V_119 . V_156 . T_3 = T_3 ;
return true ;
}
#endif
return false ;
}
static int F_79 ( struct V_62 * V_40 , int V_157 )
{
struct V_148 * V_133 ;
if ( V_157 )
return V_157 ;
F_75 (info, &ssif_infos, link) {
if ( V_133 -> V_153 . V_149 != V_40 -> V_149 )
continue;
if ( V_133 -> V_150 && V_40 -> V_121 -> V_158 &&
F_73 ( V_133 -> V_150 ,
V_40 -> V_121 -> V_158 ) )
continue;
if ( V_133 -> V_157 ) {
V_157 = V_133 -> V_157 ;
break;
}
}
return V_157 ;
}
static int F_80 ( struct V_62 * V_40 , const struct V_159 * V_160 )
{
unsigned char V_5 [ 3 ] ;
unsigned char * V_126 ;
struct V_1 * V_1 ;
int V_49 = 0 ;
int V_69 ;
int V_77 ;
T_4 V_157 = 0 ;
struct V_148 * V_119 = NULL ;
V_126 = F_62 ( V_82 , V_134 ) ;
if ( ! V_126 )
return - V_135 ;
V_1 = F_81 ( sizeof( * V_1 ) , V_134 ) ;
if ( ! V_1 ) {
F_58 ( V_126 ) ;
return - V_135 ;
}
if ( ! F_76 ( V_1 , & V_40 -> V_118 ) ) {
V_119 = F_74 ( V_40 -> V_149 , V_40 -> V_121 -> V_158 ,
true ) ;
if ( ! V_119 ) {
V_1 -> V_117 = V_161 ;
} else {
V_1 -> V_117 = V_119 -> V_116 ;
V_1 -> V_57 = V_119 -> V_162 ;
V_1 -> V_119 = V_119 -> V_119 ;
V_157 = V_119 -> V_157 ;
}
}
V_157 = F_79 ( V_40 , V_157 ) ;
F_29 ( V_8 L_35 ,
F_82 ( V_1 -> V_117 ) ,
V_40 -> V_149 , V_40 -> V_121 -> V_158 , V_157 ) ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_136 ;
V_49 = F_59 ( V_40 , 2 , V_5 , & V_69 , V_126 ) ;
if ( V_49 )
goto V_163;
V_49 = F_83 ( V_126 , V_69 , & V_1 -> V_164 ) ;
if ( V_49 )
goto V_163;
V_1 -> V_40 = V_40 ;
F_84 ( V_40 , V_1 ) ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_165 ;
V_5 [ 2 ] = 0 ;
V_49 = F_59 ( V_40 , 3 , V_5 , & V_69 , V_126 ) ;
if ( ! V_49 && ( V_69 >= 3 ) && ( V_126 [ 2 ] == 0 ) ) {
if ( V_69 < 7 ) {
if ( V_166 )
F_29 ( V_8 L_36 , V_69 ) ;
goto V_167;
}
V_1 -> V_104 = V_126 [ 5 ] ;
V_1 -> V_168 = V_126 [ 6 ] ;
V_1 -> V_169 = ( V_126 [ 4 ] >> 6 ) & 0x3 ;
V_1 -> V_170 = ( V_126 [ 4 ] >> 3 ) & 0x1 ;
switch ( V_1 -> V_169 ) {
case V_171 :
if ( V_1 -> V_104 > 32 )
V_1 -> V_104 = 32 ;
if ( V_1 -> V_168 > 32 )
V_1 -> V_168 = 32 ;
break;
case V_172 :
if ( V_1 -> V_104 > 63 )
V_1 -> V_104 = 63 ;
if ( V_1 -> V_168 > 62 )
V_1 -> V_168 = 62 ;
break;
case V_173 :
if ( V_1 -> V_104 > 63 )
V_1 -> V_104 = 63 ;
break;
default:
goto V_167;
}
} else {
V_167:
F_29 ( V_8 L_37 ,
V_49 , V_69 , V_126 [ 2 ] ) ;
V_1 -> V_104 = 32 ;
V_1 -> V_168 = 32 ;
V_1 -> V_169 = V_171 ;
V_1 -> V_170 = 0 ;
}
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_17 ;
V_5 [ 2 ] = V_13 ;
V_49 = F_59 ( V_40 , 3 , V_5 , & V_69 , V_126 ) ;
if ( V_49 || ( V_69 < 3 ) || ( V_126 [ 2 ] != 0 ) )
F_35 ( V_8 L_38 ,
V_49 , V_69 , V_126 [ 2 ] ) ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_174 ;
V_49 = F_59 ( V_40 , 2 , V_5 , & V_69 , V_126 ) ;
if ( V_49 || ( V_69 < 4 ) || ( V_126 [ 2 ] != 0 ) ) {
F_35 ( V_8 L_39 ,
V_49 , V_69 , V_126 [ 2 ] ) ;
V_49 = 0 ;
goto V_152;
}
V_1 -> V_175 = V_126 [ 3 ] ;
if ( V_126 [ 3 ] & V_176 ) {
V_1 -> V_120 = true ;
goto V_152;
}
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_177 ;
V_5 [ 2 ] = V_1 -> V_175 | V_176 ;
V_49 = F_59 ( V_40 , 3 , V_5 , & V_69 , V_126 ) ;
if ( V_49 || ( V_69 < 2 ) ) {
F_35 ( V_8 L_40 ,
V_49 , V_69 , V_126 [ 2 ] ) ;
V_49 = 0 ;
goto V_152;
}
if ( V_126 [ 2 ] == 0 ) {
V_1 -> V_120 = true ;
V_1 -> V_175 |= V_176 ;
}
if ( V_178 )
goto V_152;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_177 ;
V_5 [ 2 ] = V_1 -> V_175 | V_179 ;
V_49 = F_59 ( V_40 , 3 , V_5 , & V_69 , V_126 ) ;
if ( V_49 || ( V_69 < 2 ) ) {
F_35 ( V_8 L_40 ,
V_49 , V_69 , V_126 [ 2 ] ) ;
V_49 = 0 ;
goto V_152;
}
if ( V_126 [ 2 ] == 0 ) {
V_1 -> V_180 = true ;
V_1 -> V_175 |= V_179 ;
}
V_152:
V_1 -> V_181 = F_85 ( & V_182 ) ;
if ( V_166 ) {
F_29 ( L_41 ,
V_40 -> V_149 ) ;
}
F_86 ( & V_1 -> V_3 ) ;
V_1 -> V_14 = V_18 ;
F_87 ( & V_1 -> V_67 , F_30 ,
( unsigned long ) V_1 ) ;
for ( V_77 = 0 ; V_77 < V_183 ; V_77 ++ )
F_88 ( & V_1 -> V_184 [ V_77 ] , 0 ) ;
if ( V_1 -> V_170 )
V_1 -> V_40 -> V_2 |= V_185 ;
V_1 -> V_186 . V_187 = V_188 ;
V_1 -> V_186 . V_189 = F_52 ;
V_1 -> V_186 . F_43 = F_43 ;
V_1 -> V_186 . F_40 = F_40 ;
V_1 -> V_186 . F_45 = F_45 ;
V_1 -> V_186 . F_46 = F_46 ;
V_1 -> V_186 . F_49 = F_49 ;
{
unsigned int V_190 ;
V_190 = ( ( V_1 -> V_40 -> V_121 -> V_122 << 8 ) |
V_1 -> V_40 -> V_149 ) ;
F_23 ( & V_1 -> V_35 ) ;
V_1 -> V_124 = F_89 ( F_20 , V_1 ,
L_42 , V_190 ) ;
if ( F_90 ( V_1 -> V_124 ) ) {
V_49 = F_91 ( V_1 -> V_124 ) ;
F_92 ( & V_1 -> V_40 -> V_118 ,
L_43 ,
V_49 ) ;
goto V_163;
}
}
V_49 = F_93 ( & V_1 -> V_186 ,
V_1 ,
& V_1 -> V_164 ,
& V_1 -> V_40 -> V_118 ,
V_157 ) ;
if ( V_49 ) {
F_8 ( V_8 L_44 , V_49 ) ;
goto V_163;
}
V_49 = F_94 ( V_1 -> V_6 , L_45 ,
& V_191 ,
V_1 ) ;
if ( V_49 ) {
F_8 ( V_8 L_46 , V_49 ) ;
goto V_192;
}
V_49 = F_94 ( V_1 -> V_6 , L_47 ,
& V_193 ,
V_1 ) ;
if ( V_49 ) {
F_8 ( V_8 L_46 , V_49 ) ;
goto V_192;
}
V_163:
if ( V_49 )
F_58 ( V_1 ) ;
F_58 ( V_126 ) ;
return V_49 ;
V_192:
F_54 ( V_1 -> V_6 ) ;
goto V_163;
}
static int F_95 ( struct V_154 * V_194 , void * V_195 )
{
struct V_148 * V_119 = V_195 ;
if ( V_194 -> type != & V_196 )
return 0 ;
F_96 ( F_97 ( V_194 ) , & V_119 -> V_153 ) ;
if ( ! V_119 -> V_150 )
return 1 ;
return 0 ;
}
static int F_98 ( int V_149 , char * V_150 ,
int V_162 , int V_157 ,
enum V_197 V_116 )
{
struct V_148 * V_119 ;
int V_49 = 0 ;
F_99 ( & V_198 ) ;
if ( F_74 ( V_149 , V_150 , false ) ) {
V_49 = - V_199 ;
goto V_200;
}
V_119 = F_81 ( sizeof( * V_119 ) , V_134 ) ;
if ( ! V_119 ) {
V_49 = - V_135 ;
goto V_200;
}
if ( V_150 ) {
V_119 -> V_150 = F_100 ( V_150 , V_134 ) ;
if ( ! V_119 -> V_150 ) {
F_58 ( V_119 ) ;
V_49 = - V_135 ;
goto V_200;
}
}
strncpy ( V_119 -> V_153 . type , V_137 ,
sizeof( V_119 -> V_153 . type ) ) ;
V_119 -> V_153 . V_149 = V_149 ;
V_119 -> V_153 . V_201 = V_119 ;
V_119 -> V_162 = V_162 ;
V_119 -> V_157 = V_157 ;
V_119 -> V_116 = V_116 ;
F_101 ( & V_119 -> V_202 , & V_203 ) ;
if ( V_204 )
F_102 ( V_119 , F_95 ) ;
V_200:
F_103 ( & V_198 ) ;
return V_49 ;
}
static void F_104 ( void )
{
struct V_148 * V_133 , * V_205 ;
F_99 ( & V_198 ) ;
F_105 (info, tmp, &ssif_infos, link) {
F_106 ( & V_133 -> V_202 ) ;
F_58 ( V_133 -> V_150 ) ;
F_58 ( V_133 ) ;
}
F_103 ( & V_198 ) ;
}
static unsigned short * F_107 ( void )
{
struct V_148 * V_133 ;
unsigned int V_206 = 0 , V_77 ;
unsigned short * V_207 ;
F_75 (info, &ssif_infos, link)
V_206 ++ ;
V_207 = F_81 ( sizeof( * V_207 ) * ( V_206 + 1 ) , V_134 ) ;
if ( ! V_207 )
return NULL ;
V_77 = 0 ;
F_75 (info, &ssif_infos, link) {
unsigned short V_149 = V_133 -> V_153 . V_149 ;
int V_208 ;
for ( V_208 = 0 ; V_208 < V_77 ; V_208 ++ ) {
if ( V_207 [ V_208 ] == V_149 )
goto V_209;
}
V_207 [ V_77 ] = V_149 ;
V_209:
V_77 ++ ;
}
V_207 [ V_77 ] = V_210 ;
return V_207 ;
}
static int F_108 ( struct V_211 * V_212 )
{
unsigned short V_213 ;
if ( V_214 >= V_215 )
return - 1 ;
if ( V_212 -> V_216 != 1 ) {
F_35 ( L_48 , V_212 -> V_216 ) ;
return - V_123 ;
}
if ( V_212 -> V_217 != 4 )
return - V_123 ;
if ( V_212 -> V_149 . V_218 != V_219 ) {
F_35 ( V_8 L_49 ,
V_212 -> V_149 . V_218 ) ;
return - V_59 ;
}
V_213 = V_212 -> V_149 . V_220 & 0x7f ;
return F_98 ( V_213 , NULL , 0 , 0 , V_221 ) ;
}
static void F_109 ( void )
{
T_5 V_222 ;
struct V_211 * V_212 ;
int V_77 ;
if ( V_223 )
return;
if ( V_224 )
return;
for ( V_77 = 0 ; ; V_77 ++ ) {
V_222 = F_110 ( V_225 , V_77 + 1 ,
(struct V_226 * * ) & V_212 ) ;
if ( V_222 != V_227 )
return;
F_108 ( V_212 ) ;
}
}
static void F_109 ( void ) { }
static int F_111 ( const struct V_228 * V_229 )
{
struct V_230 * V_231 = V_229 -> V_232 ;
T_4 * V_11 = ( T_4 * ) V_231 ;
T_4 V_69 = V_231 -> V_233 ;
unsigned short V_213 ;
int V_157 ;
if ( V_214 >= V_215 )
return - 1 ;
if ( V_69 < 9 )
return - 1 ;
if ( V_11 [ 0x04 ] != 4 )
return - 1 ;
if ( ( V_11 [ 8 ] >> 1 ) == 0 ) {
V_213 = V_11 [ 6 ] >> 1 ;
V_157 = 0 ;
} else {
V_213 = V_11 [ 8 ] >> 1 ;
V_157 = V_11 [ 6 ] ;
}
return F_98 ( V_213 , NULL , 0 , V_157 , V_234 ) ;
}
static void F_112 ( void )
{
const struct V_228 * V_118 = NULL ;
while ( ( V_118 = F_113 ( V_235 , NULL , V_118 ) ) )
F_111 ( V_118 ) ;
}
static void F_112 ( void ) { }
static int F_114 ( void )
{
int V_77 ;
int V_49 ;
if ( V_204 )
return 0 ;
F_29 ( L_50 ) ;
for ( V_77 = 0 ; V_77 < V_214 ; V_77 ++ ) {
V_49 = F_98 ( V_149 [ V_77 ] , V_150 [ V_77 ] ,
V_236 [ V_77 ] , V_237 [ V_77 ] ,
V_238 ) ;
if ( V_49 )
F_8 ( V_8
L_51 ,
V_149 [ V_77 ] ) ;
}
if ( V_239 )
V_240 . V_241 . V_242 =
F_115 ( V_243 ) ;
if ( V_244 )
F_112 () ;
if ( V_239 )
F_109 () ;
V_240 . V_207 = F_107 () ;
V_49 = F_116 ( & V_240 ) ;
if ( ! V_49 )
V_204 = true ;
return V_49 ;
}
static void F_117 ( void )
{
if ( ! V_204 )
return;
V_204 = false ;
F_118 ( & V_240 ) ;
F_104 () ;
}
