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
( long ) V_108 . V_109 , ( long ) V_108 . V_110 ) ;
}
}
static int F_43 ( void * V_105 , struct V_111 * V_11 )
{
struct V_1 * V_1 = V_105 ;
V_11 -> V_112 = V_1 -> V_113 ;
V_11 -> V_114 = & V_1 -> V_40 -> V_114 ;
V_11 -> V_115 = V_1 -> V_115 ;
F_44 ( V_11 -> V_114 ) ;
return 0 ;
}
static void F_45 ( void * V_105 )
{
struct V_1 * V_1 = (struct V_1 * ) V_105 ;
unsigned long V_24 , * V_2 ;
if ( ! V_1 -> V_116 )
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
if ( ! F_47 ( V_1 -> V_40 -> V_117 -> V_118 ) )
return - V_119 ;
F_48 ( V_1 -> V_40 ) ;
return 0 ;
}
static void F_49 ( void * V_105 )
{
struct V_1 * V_1 = V_105 ;
F_50 ( V_1 -> V_40 ) ;
F_51 ( V_1 -> V_40 -> V_117 ) ;
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
if ( V_1 -> V_120 ) {
F_27 ( & V_1 -> V_35 ) ;
F_57 ( V_1 -> V_120 ) ;
}
F_58 ( V_1 ) ;
return 0 ;
}
static int F_59 ( struct V_62 * V_40 , int V_67 , unsigned char * V_5 ,
int * V_121 , unsigned char * V_122 )
{
int V_123 ;
int V_124 ;
V_123 = V_102 ;
V_125:
V_124 = F_24 ( V_40 , V_100 , V_67 , V_5 ) ;
if ( V_124 ) {
V_123 -- ;
if ( V_123 > 0 )
goto V_125;
return - V_119 ;
}
V_124 = - V_119 ;
V_123 = V_95 ;
while ( V_123 > 0 ) {
V_124 = F_25 ( V_40 , V_54 ,
V_122 ) ;
if ( V_124 > 0 )
break;
F_60 ( V_126 ) ;
V_123 -- ;
if ( V_123 <= 0 )
break;
}
if ( V_124 > 0 ) {
if ( V_124 < 3 ||
( V_122 [ 0 ] != ( V_5 [ 0 ] | ( 1 << 2 ) ) ) ||
( V_122 [ 1 ] != V_5 [ 1 ] ) )
V_124 = - V_127 ;
else {
* V_121 = V_124 ;
V_124 = 0 ;
}
}
return V_124 ;
}
static int F_61 ( struct V_62 * V_40 , struct V_128 * V_129 )
{
unsigned char * V_122 ;
unsigned char V_5 [ 3 ] ;
int V_49 ;
int V_67 ;
V_122 = F_62 ( V_80 , V_130 ) ;
if ( ! V_122 )
return - V_131 ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_132 ;
V_49 = F_59 ( V_40 , 2 , V_5 , & V_67 , V_122 ) ;
if ( V_49 )
V_49 = - V_119 ;
else
F_63 ( V_129 -> type , V_133 , V_134 ) ;
F_58 ( V_122 ) ;
return V_49 ;
}
static int F_64 ( struct V_135 * V_136 , void * V_137 )
{
F_65 ( V_136 , L_21 ) ;
return 0 ;
}
static int F_66 ( struct V_138 * V_138 , struct V_139 * V_139 )
{
return F_67 ( V_139 , F_64 , V_138 -> V_140 ) ;
}
static int F_68 ( struct V_135 * V_136 , void * V_137 )
{
struct V_1 * V_1 = V_136 -> V_141 ;
F_69 ( V_136 , L_22 ,
F_70 ( V_1 , V_94 ) ) ;
F_69 ( V_136 , L_23 ,
F_70 ( V_1 , V_92 ) ) ;
F_69 ( V_136 , L_24 ,
F_70 ( V_1 , V_88 ) ) ;
F_69 ( V_136 , L_25 ,
F_70 ( V_1 , V_89 ) ) ;
F_69 ( V_136 , L_26 ,
F_70 ( V_1 , V_82 ) ) ;
F_69 ( V_136 , L_27 ,
F_70 ( V_1 , V_76 ) ) ;
F_69 ( V_136 , L_28 ,
F_70 ( V_1 , V_69 ) ) ;
F_69 ( V_136 , L_29 ,
F_70 ( V_1 , V_73 ) ) ;
F_69 ( V_136 , L_30 ,
F_70 ( V_1 , V_84 ) ) ;
F_69 ( V_136 , L_31 ,
F_70 ( V_1 , V_9 ) ) ;
F_69 ( V_136 , L_32 ,
F_70 ( V_1 , V_86 ) ) ;
F_69 ( V_136 , L_33 ,
F_70 ( V_1 , V_31 ) ) ;
F_69 ( V_136 , L_34 ,
F_70 ( V_1 , V_64 ) ) ;
return 0 ;
}
static int F_71 ( struct V_138 * V_138 , struct V_139 * V_139 )
{
return F_67 ( V_139 , F_68 , F_72 ( V_138 ) ) ;
}
static int F_73 ( char * V_142 , char * V_143 )
{
while ( * V_142 && * V_143 ) {
while ( isspace ( * V_142 ) )
V_142 ++ ;
while ( isspace ( * V_143 ) )
V_143 ++ ;
if ( * V_142 > * V_143 )
return 1 ;
if ( * V_142 < * V_143 )
return - 1 ;
V_142 ++ ;
V_143 ++ ;
}
return 0 ;
}
static struct V_144 * F_74 ( unsigned short V_145 ,
char * V_146 ,
bool V_147 )
{
struct V_144 * V_129 , * V_148 = NULL ;
V_103:
F_75 (info, &ssif_infos, link) {
if ( V_129 -> V_149 . V_145 == V_145 ) {
if ( V_129 -> V_146 || V_146 ) {
if ( ! V_129 -> V_146 != ! V_146 ) {
continue;
}
if ( V_146 &&
F_73 ( V_129 -> V_146 ,
V_146 ) )
continue;
}
V_148 = V_129 ;
break;
}
}
if ( ! V_148 && V_147 ) {
V_146 = NULL ;
V_147 = false ;
goto V_103;
}
return V_148 ;
}
static bool F_76 ( struct V_1 * V_1 , struct V_150 * V_114 )
{
#ifdef F_77
T_3 T_3 ;
T_3 = F_78 ( V_114 ) ;
if ( T_3 ) {
V_1 -> V_113 = V_151 ;
V_1 -> V_115 . V_152 . T_3 = T_3 ;
return true ;
}
#endif
return false ;
}
static int F_79 ( struct V_62 * V_40 , const struct V_153 * V_154 )
{
unsigned char V_5 [ 3 ] ;
unsigned char * V_122 ;
struct V_1 * V_1 ;
int V_49 = 0 ;
int V_67 ;
int V_75 ;
T_4 V_155 = 0 ;
struct V_144 * V_115 = NULL ;
V_122 = F_62 ( V_80 , V_130 ) ;
if ( ! V_122 )
return - V_131 ;
V_1 = F_80 ( sizeof( * V_1 ) , V_130 ) ;
if ( ! V_1 ) {
F_58 ( V_122 ) ;
return - V_131 ;
}
if ( ! F_76 ( V_1 , & V_40 -> V_114 ) ) {
V_115 = F_74 ( V_40 -> V_145 , V_40 -> V_117 -> V_156 ,
true ) ;
if ( ! V_115 ) {
V_1 -> V_113 = V_157 ;
} else {
V_1 -> V_113 = V_115 -> V_112 ;
V_1 -> V_57 = V_115 -> V_158 ;
V_1 -> V_115 = V_115 -> V_115 ;
V_155 = V_115 -> V_155 ;
}
}
F_29 ( V_8 L_35 ,
F_81 ( V_1 -> V_113 ) ,
V_40 -> V_145 , V_40 -> V_117 -> V_156 , V_155 ) ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_132 ;
V_49 = F_59 ( V_40 , 2 , V_5 , & V_67 , V_122 ) ;
if ( V_49 )
goto V_159;
V_49 = F_82 ( V_122 , V_67 , & V_1 -> V_160 ) ;
if ( V_49 )
goto V_159;
V_1 -> V_40 = V_40 ;
F_83 ( V_40 , V_1 ) ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_161 ;
V_5 [ 2 ] = 0 ;
V_49 = F_59 ( V_40 , 3 , V_5 , & V_67 , V_122 ) ;
if ( ! V_49 && ( V_67 >= 3 ) && ( V_122 [ 2 ] == 0 ) ) {
if ( V_67 < 7 ) {
if ( V_162 )
F_29 ( V_8 L_36 , V_67 ) ;
goto V_163;
}
V_1 -> V_101 = V_122 [ 5 ] ;
V_1 -> V_164 = V_122 [ 6 ] ;
V_1 -> V_165 = ( V_122 [ 4 ] >> 6 ) & 0x3 ;
V_1 -> V_166 = ( V_122 [ 4 ] >> 3 ) & 0x1 ;
switch ( V_1 -> V_165 ) {
case V_167 :
if ( V_1 -> V_101 > 32 )
V_1 -> V_101 = 32 ;
if ( V_1 -> V_164 > 32 )
V_1 -> V_164 = 32 ;
break;
case V_168 :
if ( V_1 -> V_101 > 63 )
V_1 -> V_101 = 63 ;
if ( V_1 -> V_164 > 62 )
V_1 -> V_164 = 62 ;
break;
case V_169 :
if ( V_1 -> V_101 > 63 )
V_1 -> V_101 = 63 ;
break;
default:
goto V_163;
}
} else {
V_163:
F_29 ( V_8 L_37 ,
V_49 , V_67 , V_122 [ 2 ] ) ;
V_1 -> V_101 = 32 ;
V_1 -> V_164 = 32 ;
V_1 -> V_165 = V_167 ;
V_1 -> V_166 = 0 ;
}
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_17 ;
V_5 [ 2 ] = V_13 ;
V_49 = F_59 ( V_40 , 3 , V_5 , & V_67 , V_122 ) ;
if ( V_49 || ( V_67 < 3 ) || ( V_122 [ 2 ] != 0 ) )
F_35 ( V_8 L_38 ,
V_49 , V_67 , V_122 [ 2 ] ) ;
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_170 ;
V_49 = F_59 ( V_40 , 2 , V_5 , & V_67 , V_122 ) ;
if ( V_49 || ( V_67 < 4 ) || ( V_122 [ 2 ] != 0 ) ) {
F_35 ( V_8 L_39 ,
V_49 , V_67 , V_122 [ 2 ] ) ;
V_49 = 0 ;
goto V_148;
}
V_1 -> V_171 = V_122 [ 3 ] ;
if ( V_122 [ 3 ] & V_172 ) {
V_1 -> V_116 = true ;
goto V_148;
}
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_173 ;
V_5 [ 2 ] = V_1 -> V_171 | V_172 ;
V_49 = F_59 ( V_40 , 3 , V_5 , & V_67 , V_122 ) ;
if ( V_49 || ( V_67 < 2 ) ) {
F_35 ( V_8 L_40 ,
V_49 , V_67 , V_122 [ 2 ] ) ;
V_49 = 0 ;
goto V_148;
}
if ( V_122 [ 2 ] == 0 ) {
V_1 -> V_116 = true ;
V_1 -> V_171 |= V_172 ;
}
V_5 [ 0 ] = V_16 << 2 ;
V_5 [ 1 ] = V_173 ;
V_5 [ 2 ] = V_1 -> V_171 | V_174 ;
V_49 = F_59 ( V_40 , 3 , V_5 , & V_67 , V_122 ) ;
if ( V_49 || ( V_67 < 2 ) ) {
F_35 ( V_8 L_40 ,
V_49 , V_67 , V_122 [ 2 ] ) ;
V_49 = 0 ;
goto V_148;
}
if ( V_122 [ 2 ] == 0 ) {
V_1 -> V_175 = true ;
V_1 -> V_171 |= V_174 ;
}
V_148:
V_1 -> V_176 = F_84 ( & V_177 ) ;
if ( V_162 ) {
F_29 ( L_41 ,
V_40 -> V_145 ) ;
}
F_85 ( & V_1 -> V_3 ) ;
V_1 -> V_14 = V_18 ;
F_86 ( & V_1 -> V_65 ) ;
V_1 -> V_65 . V_11 = ( unsigned long ) V_1 ;
V_1 -> V_65 . V_178 = F_30 ;
for ( V_75 = 0 ; V_75 < V_179 ; V_75 ++ )
F_87 ( & V_1 -> V_180 [ V_75 ] , 0 ) ;
if ( V_1 -> V_166 )
V_1 -> V_40 -> V_2 |= V_181 ;
V_1 -> V_182 . V_183 = V_184 ;
V_1 -> V_182 . V_185 = F_52 ;
V_1 -> V_182 . F_43 = F_43 ;
V_1 -> V_182 . F_40 = F_40 ;
V_1 -> V_182 . F_45 = F_45 ;
V_1 -> V_182 . F_46 = F_46 ;
V_1 -> V_182 . F_49 = F_49 ;
{
unsigned int V_186 ;
V_186 = ( ( V_1 -> V_40 -> V_117 -> V_118 << 8 ) |
V_1 -> V_40 -> V_145 ) ;
F_23 ( & V_1 -> V_35 ) ;
V_1 -> V_120 = F_88 ( F_20 , V_1 ,
L_42 , V_186 ) ;
if ( F_89 ( V_1 -> V_120 ) ) {
V_49 = F_90 ( V_1 -> V_120 ) ;
F_91 ( & V_1 -> V_40 -> V_114 ,
L_43 ,
V_49 ) ;
goto V_159;
}
}
V_49 = F_92 ( & V_1 -> V_182 ,
V_1 ,
& V_1 -> V_160 ,
& V_1 -> V_40 -> V_114 ,
V_155 ) ;
if ( V_49 ) {
F_8 ( V_8 L_44 , V_49 ) ;
goto V_159;
}
V_49 = F_93 ( V_1 -> V_6 , L_45 ,
& V_187 ,
V_1 ) ;
if ( V_49 ) {
F_8 ( V_8 L_46 , V_49 ) ;
goto V_188;
}
V_49 = F_93 ( V_1 -> V_6 , L_47 ,
& V_189 ,
V_1 ) ;
if ( V_49 ) {
F_8 ( V_8 L_46 , V_49 ) ;
goto V_188;
}
V_159:
if ( V_49 )
F_58 ( V_1 ) ;
F_58 ( V_122 ) ;
return V_49 ;
V_188:
F_54 ( V_1 -> V_6 ) ;
goto V_159;
}
static int F_94 ( struct V_150 * V_190 , void * V_191 )
{
struct V_144 * V_115 = V_191 ;
if ( V_190 -> type != & V_192 )
return 0 ;
F_95 ( F_96 ( V_190 ) , & V_115 -> V_149 ) ;
if ( ! V_115 -> V_146 )
return 1 ;
return 0 ;
}
static int F_97 ( int V_145 , char * V_146 ,
int V_158 , int V_155 ,
enum V_193 V_112 )
{
struct V_144 * V_115 ;
int V_49 = 0 ;
F_98 ( & V_194 ) ;
if ( F_74 ( V_145 , V_146 , false ) ) {
V_49 = - V_195 ;
goto V_196;
}
V_115 = F_80 ( sizeof( * V_115 ) , V_130 ) ;
if ( ! V_115 ) {
V_49 = - V_131 ;
goto V_196;
}
if ( V_146 ) {
V_115 -> V_146 = F_99 ( V_146 , V_130 ) ;
if ( ! V_115 -> V_146 ) {
F_58 ( V_115 ) ;
V_49 = - V_131 ;
goto V_196;
}
}
strncpy ( V_115 -> V_149 . type , V_133 ,
sizeof( V_115 -> V_149 . type ) ) ;
V_115 -> V_149 . V_145 = V_145 ;
V_115 -> V_149 . V_197 = V_115 ;
V_115 -> V_158 = V_158 ;
V_115 -> V_155 = V_155 ;
V_115 -> V_112 = V_112 ;
F_100 ( & V_115 -> V_198 , & V_199 ) ;
if ( V_200 )
F_101 ( V_115 , F_94 ) ;
V_196:
F_102 ( & V_194 ) ;
return V_49 ;
}
static void F_103 ( void )
{
struct V_144 * V_129 , * V_201 ;
F_98 ( & V_194 ) ;
F_104 (info, tmp, &ssif_infos, link) {
F_105 ( & V_129 -> V_198 ) ;
F_58 ( V_129 -> V_146 ) ;
F_58 ( V_129 ) ;
}
F_102 ( & V_194 ) ;
}
static unsigned short * F_106 ( void )
{
struct V_144 * V_129 ;
unsigned int V_202 = 0 , V_75 ;
unsigned short * V_203 ;
F_75 (info, &ssif_infos, link)
V_202 ++ ;
V_203 = F_80 ( sizeof( * V_203 ) * ( V_202 + 1 ) , V_130 ) ;
if ( ! V_203 )
return NULL ;
V_75 = 0 ;
F_75 (info, &ssif_infos, link) {
unsigned short V_145 = V_129 -> V_149 . V_145 ;
int V_204 ;
for ( V_204 = 0 ; V_204 < V_75 ; V_204 ++ ) {
if ( V_203 [ V_204 ] == V_145 )
goto V_205;
}
V_203 [ V_75 ] = V_145 ;
V_205:
V_75 ++ ;
}
V_203 [ V_75 ] = V_206 ;
return V_203 ;
}
static int F_107 ( struct V_207 * V_208 )
{
unsigned short V_209 ;
if ( V_210 >= V_211 )
return - 1 ;
if ( V_208 -> V_212 != 1 ) {
F_35 ( L_48 , V_208 -> V_212 ) ;
return - V_119 ;
}
if ( V_208 -> V_213 != 4 )
return - V_119 ;
if ( V_208 -> V_145 . V_214 != V_215 ) {
F_35 ( V_8 L_49 ,
V_208 -> V_145 . V_214 ) ;
return - V_59 ;
}
V_209 = V_208 -> V_145 . V_216 >> 1 ;
return F_97 ( V_209 , NULL , 0 , 0 , V_217 ) ;
}
static void F_108 ( void )
{
T_5 V_218 ;
struct V_207 * V_208 ;
int V_75 ;
if ( V_219 )
return;
if ( V_220 )
return;
for ( V_75 = 0 ; ; V_75 ++ ) {
V_218 = F_109 ( V_221 , V_75 + 1 ,
(struct V_222 * * ) & V_208 ) ;
if ( V_218 != V_223 )
return;
F_107 ( V_208 ) ;
}
}
static void F_108 ( void ) { }
static int F_110 ( const struct V_224 * V_225 )
{
struct V_226 * V_227 = V_225 -> V_228 ;
T_4 * V_11 = ( T_4 * ) V_227 ;
T_4 V_67 = V_227 -> V_229 ;
unsigned short V_209 ;
int V_155 ;
if ( V_210 >= V_211 )
return - 1 ;
if ( V_67 < 9 )
return - 1 ;
if ( V_11 [ 0x04 ] != 4 )
return - 1 ;
if ( ( V_11 [ 8 ] >> 1 ) == 0 ) {
V_209 = V_11 [ 6 ] >> 1 ;
V_155 = 0 ;
} else {
V_209 = V_11 [ 8 ] >> 1 ;
V_155 = V_11 [ 6 ] ;
}
return F_97 ( V_209 , NULL , 0 , 0 , V_230 ) ;
}
static void F_111 ( void )
{
const struct V_224 * V_114 = NULL ;
while ( ( V_114 = F_112 ( V_231 , NULL , V_114 ) ) )
F_110 ( V_114 ) ;
}
static void F_111 ( void ) { }
static int F_113 ( void )
{
int V_75 ;
int V_49 ;
if ( V_200 )
return 0 ;
F_29 ( L_50 ) ;
for ( V_75 = 0 ; V_75 < V_210 ; V_75 ++ ) {
V_49 = F_97 ( V_145 [ V_75 ] , V_146 [ V_75 ] ,
V_232 [ V_75 ] , V_233 [ V_75 ] ,
V_234 ) ;
if ( V_49 )
F_8 ( V_8
L_51 ,
V_145 [ V_75 ] ) ;
}
if ( V_235 )
V_236 . V_237 . V_238 =
F_114 ( V_239 ) ;
if ( V_240 )
F_111 () ;
if ( V_235 )
F_108 () ;
V_236 . V_203 = F_106 () ;
V_49 = F_115 ( & V_236 ) ;
if ( ! V_49 )
V_200 = true ;
return V_49 ;
}
static void F_116 ( void )
{
if ( ! V_200 )
return;
V_200 = false ;
F_117 ( & V_236 ) ;
F_103 () ;
}
