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
static void F_31 ( struct V_62 * V_40 , unsigned int V_11 )
{
struct V_1 * V_1 = F_32 ( V_40 ) ;
unsigned long V_24 , * V_2 ;
bool V_63 = false ;
F_10 ( V_1 , V_64 ) ;
V_2 = F_1 ( V_1 , & V_24 ) ;
if ( V_1 -> V_61 ) {
V_1 -> V_61 = false ;
F_33 ( & V_1 -> V_65 ) ;
V_63 = true ;
} else if ( V_1 -> V_25 ) {
V_1 -> V_66 = true ;
}
F_3 ( V_1 , V_2 ) ;
if ( V_63 )
F_28 ( V_1 ) ;
}
static void V_52 ( struct V_1 * V_1 , int V_34 ,
unsigned char * V_11 , unsigned int V_67 )
{
struct V_4 * V_5 ;
unsigned long V_24 , * V_2 ;
int V_49 ;
if ( V_34 < 0 ) {
V_1 -> V_68 -- ;
if ( V_1 -> V_68 > 0 ) {
F_10 ( V_1 , V_69 ) ;
V_2 = F_1 ( V_1 , & V_24 ) ;
V_1 -> V_61 = true ;
V_1 -> V_50 = V_70 ;
F_34 ( & V_1 -> V_65 ,
V_71 + V_72 ) ;
F_3 ( V_1 , V_2 ) ;
return;
}
F_10 ( V_1 , V_73 ) ;
if ( V_1 -> V_57 & V_58 )
F_29 ( L_3 , V_34 ) ;
V_67 = 0 ;
goto V_74;
}
if ( ( V_67 > 1 ) && ( V_1 -> V_51 == 0 )
&& ( V_11 [ 0 ] == 0x00 ) && ( V_11 [ 1 ] == 0x01 ) ) {
int V_75 ;
F_10 ( V_1 , V_76 ) ;
V_67 -= 2 ;
for ( V_75 = 0 ; V_75 < V_67 ; V_75 ++ )
V_1 -> V_11 [ V_75 ] = V_11 [ V_75 + 2 ] ;
V_1 -> V_77 = V_67 ;
V_1 -> V_51 = 1 ;
V_49 = F_26 ( V_1 , V_52 , V_53 ,
V_78 ,
V_1 -> V_55 , V_56 ) ;
if ( V_49 < 0 ) {
if ( V_1 -> V_57 & V_58 )
F_29 ( L_4 ) ;
V_34 = - V_59 ;
} else
return;
} else if ( V_1 -> V_51 ) {
int V_75 ;
unsigned char V_79 ;
if ( V_67 == 0 ) {
V_34 = - V_59 ;
if ( V_1 -> V_57 & V_58 )
F_29 ( V_8 L_5 ) ;
goto V_74;
}
V_79 = V_11 [ 0 ] ;
if ( V_1 -> V_77 + V_67 - 1 > V_80 ) {
V_34 = - V_81 ;
if ( V_1 -> V_57 & V_58 )
F_29 ( L_6 ) ;
goto V_74;
}
V_67 -- ;
for ( V_75 = 0 ; V_75 < V_67 ; V_75 ++ )
V_1 -> V_11 [ V_75 + V_1 -> V_77 ] = V_11 [ V_75 + 1 ] ;
V_1 -> V_77 += V_67 ;
if ( V_79 == 0xff ) {
V_67 = V_1 -> V_77 ;
V_11 = V_1 -> V_11 ;
} else if ( V_79 + 1 != V_1 -> V_51 ) {
V_34 = - V_59 ;
} else {
F_10 ( V_1 , V_76 ) ;
V_1 -> V_51 ++ ;
V_49 = F_26 ( V_1 , V_52 ,
V_53 ,
V_78 ,
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
F_10 ( V_1 , V_73 ) ;
} else {
F_10 ( V_1 , V_82 ) ;
F_10 ( V_1 , V_76 ) ;
}
V_74:
if ( V_1 -> V_57 & V_83 )
F_29 ( V_8 L_8 ,
V_1 -> V_14 , V_34 ) ;
V_2 = F_1 ( V_1 , & V_24 ) ;
V_5 = V_1 -> V_25 ;
if ( V_5 ) {
V_5 -> V_7 = V_67 ;
if ( V_5 -> V_7 > V_80 )
V_5 -> V_7 = V_80 ;
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
if ( ( V_34 < 0 ) || ( V_67 < 4 ) || ( V_11 [ 2 ] != 0 ) ) {
V_1 -> V_14 = V_18 ;
F_3 ( V_1 , V_2 ) ;
F_35 ( V_8 L_9 ,
V_34 , V_67 , V_11 [ 2 ] ) ;
} else if ( V_11 [ 0 ] != ( V_16 | 1 ) << 2
|| V_11 [ 1 ] != V_22 ) {
F_35 ( V_8 L_10 ,
V_11 [ 0 ] , V_11 [ 1 ] ) ;
} else {
F_10 ( V_1 , V_84 ) ;
V_1 -> V_12 = V_11 [ 3 ] ;
F_18 ( V_1 , V_2 ) ;
}
break;
case V_15 :
if ( ( V_34 < 0 ) || ( V_67 < 3 ) || ( V_11 [ 2 ] != 0 ) ) {
F_35 ( V_8 L_11 ,
V_34 , V_67 , V_11 [ 2 ] ) ;
} else if ( V_11 [ 0 ] != ( V_16 | 1 ) << 2
|| V_11 [ 1 ] != V_17 ) {
F_35 ( V_8 L_12 ,
V_11 [ 0 ] , V_11 [ 1 ] ) ;
}
V_1 -> V_14 = V_18 ;
F_3 ( V_1 , V_2 ) ;
break;
case V_27 :
if ( ( V_34 < 0 ) || ( V_67 < 3 ) || ( V_5 -> V_10 [ 2 ] != 0 ) ) {
V_5 -> V_85 ( V_5 ) ;
V_1 -> V_12 &= ~ V_33 ;
F_18 ( V_1 , V_2 ) ;
} else if ( V_5 -> V_10 [ 0 ] != ( V_16 | 1 ) << 2
|| V_5 -> V_10 [ 1 ] != V_28 ) {
F_35 ( V_8 L_13 ,
V_5 -> V_10 [ 0 ] , V_5 -> V_10 [ 1 ] ) ;
V_5 -> V_85 ( V_5 ) ;
V_1 -> V_12 &= ~ V_33 ;
F_18 ( V_1 , V_2 ) ;
} else {
F_18 ( V_1 , V_2 ) ;
F_10 ( V_1 , V_86 ) ;
F_5 ( V_1 , V_5 ) ;
}
break;
case V_29 :
if ( ( V_34 < 0 ) || ( V_67 < 3 ) || ( V_5 -> V_10 [ 2 ] != 0 ) ) {
V_5 -> V_85 ( V_5 ) ;
V_1 -> V_12 &= ~ V_32 ;
F_18 ( V_1 , V_2 ) ;
} else if ( V_5 -> V_10 [ 0 ] != ( V_16 | 1 ) << 2
|| V_5 -> V_10 [ 1 ] != V_30 ) {
F_35 ( V_8 L_12 ,
V_5 -> V_10 [ 0 ] , V_5 -> V_10 [ 1 ] ) ;
V_5 -> V_85 ( V_5 ) ;
V_1 -> V_12 &= ~ V_32 ;
F_18 ( V_1 , V_2 ) ;
} else {
F_10 ( V_1 , V_87 ) ;
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
if ( V_1 -> V_57 & V_83 )
F_29 ( V_8 L_14 , V_1 -> V_14 ) ;
}
static void F_38 ( struct V_1 * V_1 , int V_34 ,
unsigned char * V_11 , unsigned int V_67 )
{
int V_49 ;
if ( V_34 < 0 ) {
V_1 -> V_68 -- ;
if ( V_1 -> V_68 > 0 ) {
if ( ! F_39 ( V_1 ) ) {
F_10 ( V_1 , V_88 ) ;
return;
}
F_10 ( V_1 , V_89 ) ;
if ( V_1 -> V_57 & V_58 )
F_29 ( V_8
L_15 ) ;
V_52 ( V_1 , - V_59 , NULL , 0 ) ;
return;
}
F_10 ( V_1 , V_89 ) ;
if ( V_1 -> V_57 & V_58 )
F_29 ( L_16 , V_34 ) ;
V_52 ( V_1 , V_34 , NULL , 0 ) ;
return;
}
if ( V_1 -> V_90 ) {
int V_91 ;
F_10 ( V_1 , V_92 ) ;
V_91 = V_1 -> V_77 - V_1 -> V_51 ;
if ( V_91 > 32 )
V_91 = 32 ;
V_1 -> V_90 [ V_1 -> V_51 ] = V_91 ;
V_1 -> V_51 += V_91 ;
if ( V_91 < 32 )
V_1 -> V_90 = NULL ;
V_49 = F_26 ( V_1 , F_38 ,
V_39 ,
V_93 ,
V_1 -> V_90 + V_1 -> V_51 ,
V_56 ) ;
if ( V_49 < 0 ) {
F_10 ( V_1 , V_89 ) ;
if ( V_1 -> V_57 & V_58 )
F_29 ( L_17 ) ;
V_52 ( V_1 , - V_59 , NULL , 0 ) ;
}
} else {
unsigned long V_24 , * V_2 ;
bool V_66 ;
F_10 ( V_1 , V_94 ) ;
F_10 ( V_1 , V_92 ) ;
V_2 = F_1 ( V_1 , & V_24 ) ;
V_66 = V_1 -> V_66 ;
if ( V_66 ) {
V_1 -> V_66 = false ;
V_1 -> V_61 = false ;
}
if ( V_66 ) {
F_3 ( V_1 , V_2 ) ;
F_30 ( ( unsigned long ) V_1 ) ;
} else {
V_1 -> V_61 = true ;
V_1 -> V_68 = V_95 ;
V_1 -> V_50 = V_96 ;
F_34 ( & V_1 -> V_65 ,
V_71 + V_97 ) ;
F_3 ( V_1 , V_2 ) ;
}
}
}
static int F_39 ( struct V_1 * V_1 )
{
int V_49 ;
int V_46 ;
V_1 -> V_66 = false ;
if ( V_1 -> V_98 > 32 ) {
V_46 = V_99 ;
V_1 -> V_90 = V_1 -> V_11 ;
V_1 -> V_77 = V_1 -> V_98 ;
V_1 -> V_51 = 32 ;
V_1 -> V_11 [ 0 ] = 32 ;
} else {
V_1 -> V_90 = NULL ;
V_46 = V_100 ;
V_1 -> V_11 [ 0 ] = V_1 -> V_98 ;
}
V_49 = F_26 ( V_1 , F_38 , V_39 ,
V_46 , V_1 -> V_11 , V_56 ) ;
if ( V_49 && ( V_1 -> V_57 & V_58 ) )
F_29 ( L_18 ) ;
return V_49 ;
}
static int F_12 ( struct V_1 * V_1 ,
unsigned char * V_11 ,
unsigned int V_67 )
{
if ( V_67 > V_80 )
return - V_81 ;
if ( V_67 > V_1 -> V_101 )
return - V_81 ;
V_1 -> V_68 = V_102 ;
memcpy ( V_1 -> V_11 + 1 , V_11 , V_67 ) ;
V_1 -> V_98 = V_67 ;
return F_39 ( V_1 ) ;
}
static void F_37 ( struct V_1 * V_1 , unsigned long * V_2 )
{
struct V_4 * V_5 ;
unsigned long V_24 ;
V_103:
if ( ! F_36 ( V_1 ) ) {
F_3 ( V_1 , V_2 ) ;
return;
}
if ( ! V_1 -> V_104 ) {
V_1 -> V_25 = NULL ;
F_3 ( V_1 , V_2 ) ;
} else {
int V_49 ;
V_1 -> V_25 = V_1 -> V_104 ;
V_1 -> V_104 = NULL ;
F_3 ( V_1 , V_2 ) ;
V_49 = F_12 ( V_1 ,
V_1 -> V_25 -> V_11 ,
V_1 -> V_25 -> V_23 ) ;
if ( V_49 ) {
V_5 = V_1 -> V_25 ;
V_1 -> V_25 = NULL ;
F_7 ( V_1 , V_5 ) ;
V_2 = F_1 ( V_1 , & V_24 ) ;
goto V_103;
}
}
}
static void F_40 ( void * V_105 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = (struct V_1 * ) V_105 ;
unsigned long V_24 , * V_2 ;
F_41 ( V_1 -> V_104 ) ;
V_1 -> V_104 = V_5 ;
V_2 = F_1 ( V_1 , & V_24 ) ;
F_37 ( V_1 , V_2 ) ;
if ( V_1 -> V_57 & V_106 ) {
struct V_107 V_108 ;
F_42 ( & V_108 ) ;
F_29 ( L_19 ,
V_5 -> V_11 [ 0 ] , V_5 -> V_11 [ 1 ] ,
( long long ) V_108 . V_109 , ( long ) V_108 . V_110 / V_111 ) ;
}
}
static int F_43 ( void * V_105 , struct V_112 * V_11 )
{
struct V_1 * V_1 = V_105 ;
V_11 -> V_113 = V_1 -> V_114 ;
V_11 -> V_115 = & V_1 -> V_40 -> V_115 ;
V_11 -> V_116 = V_1 -> V_116 ;
F_44 ( V_11 -> V_115 ) ;
return 0 ;
}
static void F_45 ( void * V_105 )
{
struct V_1 * V_1 = (struct V_1 * ) V_105 ;
unsigned long V_24 , * V_2 ;
if ( ! V_1 -> V_117 )
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
static int F_46 ( void * V_105 )
{
struct V_1 * V_1 = V_105 ;
if ( ! F_47 ( V_1 -> V_40 -> V_118 -> V_119 ) )
return - V_120 ;
F_48 ( V_1 -> V_40 ) ;
return 0 ;
}
static void F_49 ( void * V_105 )
{
struct V_1 * V_1 = V_105 ;
F_50 ( V_1 -> V_40 ) ;
F_51 ( V_1 -> V_40 -> V_118 ) ;
}
static int F_52 ( void * V_105 ,
T_1 V_6 )
{
struct V_1 * V_1 = V_105 ;
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
F_56 ( & V_1 -> V_65 ) ;
if ( V_1 -> V_121 ) {
F_27 ( & V_1 -> V_35 ) ;
F_57 ( V_1 -> V_121 ) ;
}
F_58 ( V_1 ) ;
return 0 ;
}
static int F_59 ( struct V_62 * V_40 , int V_67 , unsigned char * V_5 ,
int * V_122 , unsigned char * V_123 )
{
int V_124 ;
int V_125 ;
V_124 = V_102 ;
V_126:
V_125 = F_24 ( V_40 , V_100 , V_67 , V_5 ) ;
if ( V_125 ) {
V_124 -- ;
if ( V_124 > 0 )
goto V_126;
return - V_120 ;
}
V_125 = - V_120 ;
V_124 = V_95 ;
while ( V_124 > 0 ) {
V_125 = F_25 ( V_40 , V_54 ,
V_123 ) ;
if ( V_125 > 0 )
break;
F_60 ( V_127 ) ;
V_124 -- ;
if ( V_124 <= 0 )
break;
}
if ( V_125 > 0 ) {
if ( V_125 < 3 ||
( V_123 [ 0 ] != ( V_5 [ 0 ] | ( 1 << 2 ) ) ) ||
( V_123 [ 1 ] != V_5 [ 1 ] ) )
V_125 = - V_128 ;
else {
* V_122 = V_125 ;
V_125 = 0 ;
}
}
return V_125 ;
}
static int F_61 ( struct V_62 * V_40 , struct V_129 * V_130 )
{
unsigned char * V_123 ;
unsigned char V_5 [ 3 ] ;
int V_49 ;
int V_67 ;
V_123 = F_62 ( V_80 , V_131 ) ;
if ( ! V_123 )
return - V_132 ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_133 ;
V_49 = F_59 ( V_40 , 2 , V_5 , & V_67 , V_123 ) ;
if ( V_49 )
V_49 = - V_120 ;
else
F_63 ( V_130 -> type , V_134 , V_135 ) ;
F_58 ( V_123 ) ;
return V_49 ;
}
static int F_64 ( struct V_136 * V_137 , void * V_138 )
{
F_65 ( V_137 , L_21 ) ;
return 0 ;
}
static int F_66 ( struct V_139 * V_139 , struct V_140 * V_140 )
{
return F_67 ( V_140 , F_64 , V_139 -> V_141 ) ;
}
static int F_68 ( struct V_136 * V_137 , void * V_138 )
{
struct V_1 * V_1 = V_137 -> V_142 ;
F_69 ( V_137 , L_22 ,
F_70 ( V_1 , V_94 ) ) ;
F_69 ( V_137 , L_23 ,
F_70 ( V_1 , V_92 ) ) ;
F_69 ( V_137 , L_24 ,
F_70 ( V_1 , V_88 ) ) ;
F_69 ( V_137 , L_25 ,
F_70 ( V_1 , V_89 ) ) ;
F_69 ( V_137 , L_26 ,
F_70 ( V_1 , V_82 ) ) ;
F_69 ( V_137 , L_27 ,
F_70 ( V_1 , V_76 ) ) ;
F_69 ( V_137 , L_28 ,
F_70 ( V_1 , V_69 ) ) ;
F_69 ( V_137 , L_29 ,
F_70 ( V_1 , V_73 ) ) ;
F_69 ( V_137 , L_30 ,
F_70 ( V_1 , V_84 ) ) ;
F_69 ( V_137 , L_31 ,
F_70 ( V_1 , V_9 ) ) ;
F_69 ( V_137 , L_32 ,
F_70 ( V_1 , V_86 ) ) ;
F_69 ( V_137 , L_33 ,
F_70 ( V_1 , V_31 ) ) ;
F_69 ( V_137 , L_34 ,
F_70 ( V_1 , V_64 ) ) ;
return 0 ;
}
static int F_71 ( struct V_139 * V_139 , struct V_140 * V_140 )
{
return F_67 ( V_140 , F_68 , F_72 ( V_139 ) ) ;
}
static int F_73 ( char * V_143 , char * V_144 )
{
while ( * V_143 && * V_144 ) {
while ( isspace ( * V_143 ) )
V_143 ++ ;
while ( isspace ( * V_144 ) )
V_144 ++ ;
if ( * V_143 > * V_144 )
return 1 ;
if ( * V_143 < * V_144 )
return - 1 ;
V_143 ++ ;
V_144 ++ ;
}
return 0 ;
}
static struct V_145 * F_74 ( unsigned short V_146 ,
char * V_147 ,
bool V_148 )
{
struct V_145 * V_130 , * V_149 = NULL ;
V_103:
F_75 (info, &ssif_infos, link) {
if ( V_130 -> V_150 . V_146 == V_146 ) {
if ( V_130 -> V_147 || V_147 ) {
if ( ! V_130 -> V_147 != ! V_147 ) {
continue;
}
if ( V_147 &&
F_73 ( V_130 -> V_147 ,
V_147 ) )
continue;
}
V_149 = V_130 ;
break;
}
}
if ( ! V_149 && V_148 ) {
V_147 = NULL ;
V_148 = false ;
goto V_103;
}
return V_149 ;
}
static bool F_76 ( struct V_1 * V_1 , struct V_151 * V_115 )
{
#ifdef F_77
T_3 T_3 ;
T_3 = F_78 ( V_115 ) ;
if ( T_3 ) {
V_1 -> V_114 = V_152 ;
V_1 -> V_116 . V_153 . T_3 = T_3 ;
return true ;
}
#endif
return false ;
}
static int F_79 ( struct V_62 * V_40 , const struct V_154 * V_155 )
{
unsigned char V_5 [ 3 ] ;
unsigned char * V_123 ;
struct V_1 * V_1 ;
int V_49 = 0 ;
int V_67 ;
int V_75 ;
T_4 V_156 = 0 ;
struct V_145 * V_116 = NULL ;
V_123 = F_62 ( V_80 , V_131 ) ;
if ( ! V_123 )
return - V_132 ;
V_1 = F_80 ( sizeof( * V_1 ) , V_131 ) ;
if ( ! V_1 ) {
F_58 ( V_123 ) ;
return - V_132 ;
}
if ( ! F_76 ( V_1 , & V_40 -> V_115 ) ) {
V_116 = F_74 ( V_40 -> V_146 , V_40 -> V_118 -> V_157 ,
true ) ;
if ( ! V_116 ) {
V_1 -> V_114 = V_158 ;
} else {
V_1 -> V_114 = V_116 -> V_113 ;
V_1 -> V_57 = V_116 -> V_159 ;
V_1 -> V_116 = V_116 -> V_116 ;
V_156 = V_116 -> V_156 ;
}
}
F_29 ( V_8 L_35 ,
F_81 ( V_1 -> V_114 ) ,
V_40 -> V_146 , V_40 -> V_118 -> V_157 , V_156 ) ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_133 ;
V_49 = F_59 ( V_40 , 2 , V_5 , & V_67 , V_123 ) ;
if ( V_49 )
goto V_160;
V_49 = F_82 ( V_123 , V_67 , & V_1 -> V_161 ) ;
if ( V_49 )
goto V_160;
V_1 -> V_40 = V_40 ;
F_83 ( V_40 , V_1 ) ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_162 ;
V_5 [ 2 ] = 0 ;
V_49 = F_59 ( V_40 , 3 , V_5 , & V_67 , V_123 ) ;
if ( ! V_49 && ( V_67 >= 3 ) && ( V_123 [ 2 ] == 0 ) ) {
if ( V_67 < 7 ) {
if ( V_163 )
F_29 ( V_8 L_36 , V_67 ) ;
goto V_164;
}
V_1 -> V_101 = V_123 [ 5 ] ;
V_1 -> V_165 = V_123 [ 6 ] ;
V_1 -> V_166 = ( V_123 [ 4 ] >> 6 ) & 0x3 ;
V_1 -> V_167 = ( V_123 [ 4 ] >> 3 ) & 0x1 ;
switch ( V_1 -> V_166 ) {
case V_168 :
if ( V_1 -> V_101 > 32 )
V_1 -> V_101 = 32 ;
if ( V_1 -> V_165 > 32 )
V_1 -> V_165 = 32 ;
break;
case V_169 :
if ( V_1 -> V_101 > 63 )
V_1 -> V_101 = 63 ;
if ( V_1 -> V_165 > 62 )
V_1 -> V_165 = 62 ;
break;
case V_170 :
if ( V_1 -> V_101 > 63 )
V_1 -> V_101 = 63 ;
break;
default:
goto V_164;
}
} else {
V_164:
F_29 ( V_8 L_37 ,
V_49 , V_67 , V_123 [ 2 ] ) ;
V_1 -> V_101 = 32 ;
V_1 -> V_165 = 32 ;
V_1 -> V_166 = V_168 ;
V_1 -> V_167 = 0 ;
}
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_17 ;
V_5 [ 2 ] = V_13 ;
V_49 = F_59 ( V_40 , 3 , V_5 , & V_67 , V_123 ) ;
if ( V_49 || ( V_67 < 3 ) || ( V_123 [ 2 ] != 0 ) )
F_35 ( V_8 L_38 ,
V_49 , V_67 , V_123 [ 2 ] ) ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_171 ;
V_49 = F_59 ( V_40 , 2 , V_5 , & V_67 , V_123 ) ;
if ( V_49 || ( V_67 < 4 ) || ( V_123 [ 2 ] != 0 ) ) {
F_35 ( V_8 L_39 ,
V_49 , V_67 , V_123 [ 2 ] ) ;
V_49 = 0 ;
goto V_149;
}
V_1 -> V_172 = V_123 [ 3 ] ;
if ( V_123 [ 3 ] & V_173 ) {
V_1 -> V_117 = true ;
goto V_149;
}
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_174 ;
V_5 [ 2 ] = V_1 -> V_172 | V_173 ;
V_49 = F_59 ( V_40 , 3 , V_5 , & V_67 , V_123 ) ;
if ( V_49 || ( V_67 < 2 ) ) {
F_35 ( V_8 L_40 ,
V_49 , V_67 , V_123 [ 2 ] ) ;
V_49 = 0 ;
goto V_149;
}
if ( V_123 [ 2 ] == 0 ) {
V_1 -> V_117 = true ;
V_1 -> V_172 |= V_173 ;
}
if ( V_175 )
goto V_149;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_174 ;
V_5 [ 2 ] = V_1 -> V_172 | V_176 ;
V_49 = F_59 ( V_40 , 3 , V_5 , & V_67 , V_123 ) ;
if ( V_49 || ( V_67 < 2 ) ) {
F_35 ( V_8 L_40 ,
V_49 , V_67 , V_123 [ 2 ] ) ;
V_49 = 0 ;
goto V_149;
}
if ( V_123 [ 2 ] == 0 ) {
V_1 -> V_177 = true ;
V_1 -> V_172 |= V_176 ;
}
V_149:
V_1 -> V_178 = F_84 ( & V_179 ) ;
if ( V_163 ) {
F_29 ( L_41 ,
V_40 -> V_146 ) ;
}
F_85 ( & V_1 -> V_3 ) ;
V_1 -> V_14 = V_18 ;
F_86 ( & V_1 -> V_65 ) ;
V_1 -> V_65 . V_11 = ( unsigned long ) V_1 ;
V_1 -> V_65 . V_180 = F_30 ;
for ( V_75 = 0 ; V_75 < V_181 ; V_75 ++ )
F_87 ( & V_1 -> V_182 [ V_75 ] , 0 ) ;
if ( V_1 -> V_167 )
V_1 -> V_40 -> V_2 |= V_183 ;
V_1 -> V_184 . V_185 = V_186 ;
V_1 -> V_184 . V_187 = F_52 ;
V_1 -> V_184 . F_43 = F_43 ;
V_1 -> V_184 . F_40 = F_40 ;
V_1 -> V_184 . F_45 = F_45 ;
V_1 -> V_184 . F_46 = F_46 ;
V_1 -> V_184 . F_49 = F_49 ;
{
unsigned int V_188 ;
V_188 = ( ( V_1 -> V_40 -> V_118 -> V_119 << 8 ) |
V_1 -> V_40 -> V_146 ) ;
F_23 ( & V_1 -> V_35 ) ;
V_1 -> V_121 = F_88 ( F_20 , V_1 ,
L_42 , V_188 ) ;
if ( F_89 ( V_1 -> V_121 ) ) {
V_49 = F_90 ( V_1 -> V_121 ) ;
F_91 ( & V_1 -> V_40 -> V_115 ,
L_43 ,
V_49 ) ;
goto V_160;
}
}
V_49 = F_92 ( & V_1 -> V_184 ,
V_1 ,
& V_1 -> V_161 ,
& V_1 -> V_40 -> V_115 ,
V_156 ) ;
if ( V_49 ) {
F_8 ( V_8 L_44 , V_49 ) ;
goto V_160;
}
V_49 = F_93 ( V_1 -> V_6 , L_45 ,
& V_189 ,
V_1 ) ;
if ( V_49 ) {
F_8 ( V_8 L_46 , V_49 ) ;
goto V_190;
}
V_49 = F_93 ( V_1 -> V_6 , L_47 ,
& V_191 ,
V_1 ) ;
if ( V_49 ) {
F_8 ( V_8 L_46 , V_49 ) ;
goto V_190;
}
V_160:
if ( V_49 )
F_58 ( V_1 ) ;
F_58 ( V_123 ) ;
return V_49 ;
V_190:
F_54 ( V_1 -> V_6 ) ;
goto V_160;
}
static int F_94 ( struct V_151 * V_192 , void * V_193 )
{
struct V_145 * V_116 = V_193 ;
if ( V_192 -> type != & V_194 )
return 0 ;
F_95 ( F_96 ( V_192 ) , & V_116 -> V_150 ) ;
if ( ! V_116 -> V_147 )
return 1 ;
return 0 ;
}
static int F_97 ( int V_146 , char * V_147 ,
int V_159 , int V_156 ,
enum V_195 V_113 )
{
struct V_145 * V_116 ;
int V_49 = 0 ;
F_98 ( & V_196 ) ;
if ( F_74 ( V_146 , V_147 , false ) ) {
V_49 = - V_197 ;
goto V_198;
}
V_116 = F_80 ( sizeof( * V_116 ) , V_131 ) ;
if ( ! V_116 ) {
V_49 = - V_132 ;
goto V_198;
}
if ( V_147 ) {
V_116 -> V_147 = F_99 ( V_147 , V_131 ) ;
if ( ! V_116 -> V_147 ) {
F_58 ( V_116 ) ;
V_49 = - V_132 ;
goto V_198;
}
}
strncpy ( V_116 -> V_150 . type , V_134 ,
sizeof( V_116 -> V_150 . type ) ) ;
V_116 -> V_150 . V_146 = V_146 ;
V_116 -> V_150 . V_199 = V_116 ;
V_116 -> V_159 = V_159 ;
V_116 -> V_156 = V_156 ;
V_116 -> V_113 = V_113 ;
F_100 ( & V_116 -> V_200 , & V_201 ) ;
if ( V_202 )
F_101 ( V_116 , F_94 ) ;
V_198:
F_102 ( & V_196 ) ;
return V_49 ;
}
static void F_103 ( void )
{
struct V_145 * V_130 , * V_203 ;
F_98 ( & V_196 ) ;
F_104 (info, tmp, &ssif_infos, link) {
F_105 ( & V_130 -> V_200 ) ;
F_58 ( V_130 -> V_147 ) ;
F_58 ( V_130 ) ;
}
F_102 ( & V_196 ) ;
}
static unsigned short * F_106 ( void )
{
struct V_145 * V_130 ;
unsigned int V_204 = 0 , V_75 ;
unsigned short * V_205 ;
F_75 (info, &ssif_infos, link)
V_204 ++ ;
V_205 = F_80 ( sizeof( * V_205 ) * ( V_204 + 1 ) , V_131 ) ;
if ( ! V_205 )
return NULL ;
V_75 = 0 ;
F_75 (info, &ssif_infos, link) {
unsigned short V_146 = V_130 -> V_150 . V_146 ;
int V_206 ;
for ( V_206 = 0 ; V_206 < V_75 ; V_206 ++ ) {
if ( V_205 [ V_206 ] == V_146 )
goto V_207;
}
V_205 [ V_75 ] = V_146 ;
V_207:
V_75 ++ ;
}
V_205 [ V_75 ] = V_208 ;
return V_205 ;
}
static int F_107 ( struct V_209 * V_210 )
{
unsigned short V_211 ;
if ( V_212 >= V_213 )
return - 1 ;
if ( V_210 -> V_214 != 1 ) {
F_35 ( L_48 , V_210 -> V_214 ) ;
return - V_120 ;
}
if ( V_210 -> V_215 != 4 )
return - V_120 ;
if ( V_210 -> V_146 . V_216 != V_217 ) {
F_35 ( V_8 L_49 ,
V_210 -> V_146 . V_216 ) ;
return - V_59 ;
}
V_211 = V_210 -> V_146 . V_218 >> 1 ;
return F_97 ( V_211 , NULL , 0 , 0 , V_219 ) ;
}
static void F_108 ( void )
{
T_5 V_220 ;
struct V_209 * V_210 ;
int V_75 ;
if ( V_221 )
return;
if ( V_222 )
return;
for ( V_75 = 0 ; ; V_75 ++ ) {
V_220 = F_109 ( V_223 , V_75 + 1 ,
(struct V_224 * * ) & V_210 ) ;
if ( V_220 != V_225 )
return;
F_107 ( V_210 ) ;
}
}
static void F_108 ( void ) { }
static int F_110 ( const struct V_226 * V_227 )
{
struct V_228 * V_229 = V_227 -> V_230 ;
T_4 * V_11 = ( T_4 * ) V_229 ;
T_4 V_67 = V_229 -> V_231 ;
unsigned short V_211 ;
int V_156 ;
if ( V_212 >= V_213 )
return - 1 ;
if ( V_67 < 9 )
return - 1 ;
if ( V_11 [ 0x04 ] != 4 )
return - 1 ;
if ( ( V_11 [ 8 ] >> 1 ) == 0 ) {
V_211 = V_11 [ 6 ] >> 1 ;
V_156 = 0 ;
} else {
V_211 = V_11 [ 8 ] >> 1 ;
V_156 = V_11 [ 6 ] ;
}
return F_97 ( V_211 , NULL , 0 , 0 , V_232 ) ;
}
static void F_111 ( void )
{
const struct V_226 * V_115 = NULL ;
while ( ( V_115 = F_112 ( V_233 , NULL , V_115 ) ) )
F_110 ( V_115 ) ;
}
static void F_111 ( void ) { }
static int F_113 ( void )
{
int V_75 ;
int V_49 ;
if ( V_202 )
return 0 ;
F_29 ( L_50 ) ;
for ( V_75 = 0 ; V_75 < V_212 ; V_75 ++ ) {
V_49 = F_97 ( V_146 [ V_75 ] , V_147 [ V_75 ] ,
V_234 [ V_75 ] , V_235 [ V_75 ] ,
V_236 ) ;
if ( V_49 )
F_8 ( V_8
L_51 ,
V_146 [ V_75 ] ) ;
}
if ( V_237 )
V_238 . V_239 . V_240 =
F_114 ( V_241 ) ;
if ( V_242 )
F_111 () ;
if ( V_237 )
F_108 () ;
V_238 . V_205 = F_106 () ;
V_49 = F_115 ( & V_238 ) ;
if ( ! V_49 )
V_202 = true ;
return V_49 ;
}
static void F_116 ( void )
{
if ( ! V_202 )
return;
V_202 = false ;
F_117 ( & V_238 ) ;
F_103 () ;
}
