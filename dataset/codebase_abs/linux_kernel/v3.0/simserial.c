static void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
F_3 ( L_1 ,
V_2 -> V_3 , V_2 -> V_4 , V_2 -> V_5 ) ;
#endif
}
static void F_4 ( struct V_1 * V_2 )
{
#ifdef F_2
F_3 ( L_2 ,
V_2 -> V_3 , V_2 -> V_4 , V_2 -> V_5 ) ;
#endif
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned char V_6 ;
static unsigned char V_7 = 0 ;
while ( ( V_6 = F_6 ( 0 , 0 , 0 , 0 , V_8 ) ) ) {
if ( V_6 == 27 && V_7 == 0 ) {
V_7 = 1 ;
continue;
} else {
if ( V_7 == 1 && V_6 == 'O' ) {
V_7 = 2 ;
continue;
} else if ( V_7 == 2 ) {
if ( V_6 == 'P' )
F_7 () ;
#ifdef F_8
if ( V_6 == 'S' ) {
do
V_6 = F_6 ( 0 , 0 , 0 , 0 ,
V_8 ) ;
while ( ! V_6 );
F_9 ( V_6 ) ;
}
#endif
V_7 = 0 ;
continue;
}
}
V_7 = 0 ;
if ( F_10 ( V_2 , V_6 , V_9 ) == 0 )
break;
}
F_11 ( V_2 ) ;
}
static T_1 F_12 ( int V_10 , void * V_11 )
{
struct V_12 * V_13 ;
V_13 = V_14 [ V_10 ] ;
if ( ! V_13 || ! V_13 -> V_2 ) {
F_3 ( V_15 L_3 , V_13 ) ;
return V_16 ;
}
F_5 ( V_13 -> V_2 ) ;
return V_17 ;
}
static void F_13 ( struct V_18 * V_19 )
{
F_3 ( V_20 L_4 ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned char V_6 )
{
struct V_12 * V_13 = (struct V_12 * ) V_2 -> V_21 ;
unsigned long V_22 ;
if ( ! V_2 || ! V_13 -> V_23 . V_24 )
return 0 ;
F_15 ( V_22 ) ;
if ( F_16 ( V_13 -> V_23 . V_25 , V_13 -> V_23 . V_26 , V_27 ) == 0 ) {
F_17 ( V_22 ) ;
return 0 ;
}
V_13 -> V_23 . V_24 [ V_13 -> V_23 . V_25 ] = V_6 ;
V_13 -> V_23 . V_25 = ( V_13 -> V_23 . V_25 + 1 ) & ( V_27 - 1 ) ;
F_17 ( V_22 ) ;
return 1 ;
}
static void F_18 ( struct V_12 * V_13 , int * V_28 )
{
int V_29 ;
unsigned long V_22 ;
F_15 ( V_22 ) ;
if ( V_13 -> V_30 ) {
char V_31 = V_13 -> V_30 ;
V_32 -> V_33 ( V_32 , & V_31 , 1 ) ;
V_13 -> V_34 -> V_35 . V_36 ++ ;
V_13 -> V_30 = 0 ;
goto V_37;
}
if ( V_13 -> V_23 . V_25 == V_13 -> V_23 . V_26 || V_13 -> V_2 -> V_3 || V_13 -> V_2 -> V_4 ) {
#ifdef F_2
F_3 ( L_5 ,
V_13 -> V_23 . V_25 , V_13 -> V_23 . V_26 , V_13 -> V_2 -> V_3 ) ;
#endif
goto V_37;
}
V_29 = F_19 ( F_20 ( V_13 -> V_23 . V_25 , V_13 -> V_23 . V_26 , V_27 ) ,
V_27 - V_13 -> V_23 . V_26 ) ;
V_32 -> V_33 ( V_32 , V_13 -> V_23 . V_24 + V_13 -> V_23 . V_26 , V_29 ) ;
V_13 -> V_23 . V_26 = ( V_13 -> V_23 . V_26 + V_29 ) & ( V_27 - 1 ) ;
V_29 = F_20 ( V_13 -> V_23 . V_25 , V_13 -> V_23 . V_26 , V_27 ) ;
if ( V_29 ) {
V_32 -> V_33 ( V_32 , V_13 -> V_23 . V_24 , V_29 ) ;
V_13 -> V_23 . V_26 += V_29 ;
}
V_37:
F_17 ( V_22 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = (struct V_12 * ) V_2 -> V_21 ;
if ( V_13 -> V_23 . V_25 == V_13 -> V_23 . V_26 || V_2 -> V_3 || V_2 -> V_4 ||
! V_13 -> V_23 . V_24 )
return;
F_18 ( V_13 , NULL ) ;
}
static int F_22 ( struct V_1 * V_2 ,
const unsigned char * V_24 , int V_29 )
{
int V_31 , V_38 = 0 ;
struct V_12 * V_13 = (struct V_12 * ) V_2 -> V_21 ;
unsigned long V_22 ;
if ( ! V_2 || ! V_13 -> V_23 . V_24 || ! V_39 ) return 0 ;
F_15 ( V_22 ) ;
while ( 1 ) {
V_31 = F_23 ( V_13 -> V_23 . V_25 , V_13 -> V_23 . V_26 , V_27 ) ;
if ( V_29 < V_31 )
V_31 = V_29 ;
if ( V_31 <= 0 ) {
break;
}
memcpy ( V_13 -> V_23 . V_24 + V_13 -> V_23 . V_25 , V_24 , V_31 ) ;
V_13 -> V_23 . V_25 = ( ( V_13 -> V_23 . V_25 + V_31 ) &
( V_27 - 1 ) ) ;
V_24 += V_31 ;
V_29 -= V_31 ;
V_38 += V_31 ;
}
F_17 ( V_22 ) ;
if ( F_20 ( V_13 -> V_23 . V_25 , V_13 -> V_23 . V_26 , V_27 )
&& ! V_2 -> V_3 && ! V_2 -> V_4 ) {
F_18 ( V_13 , NULL ) ;
}
return V_38 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = (struct V_12 * ) V_2 -> V_21 ;
return F_16 ( V_13 -> V_23 . V_25 , V_13 -> V_23 . V_26 , V_27 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = (struct V_12 * ) V_2 -> V_21 ;
return F_20 ( V_13 -> V_23 . V_25 , V_13 -> V_23 . V_26 , V_27 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = (struct V_12 * ) V_2 -> V_21 ;
unsigned long V_22 ;
F_15 ( V_22 ) ;
V_13 -> V_23 . V_25 = V_13 -> V_23 . V_26 = 0 ;
F_17 ( V_22 ) ;
F_27 ( V_2 ) ;
}
static void F_28 ( struct V_1 * V_2 , char V_6 )
{
struct V_12 * V_13 = (struct V_12 * ) V_2 -> V_21 ;
V_13 -> V_30 = V_6 ;
if ( V_6 ) {
F_18 ( V_13 , NULL ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
if ( F_30 ( V_2 ) ) F_28 ( V_2 , F_31 ( V_2 ) ) ;
F_3 ( V_15 L_6 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = (struct V_12 * ) V_2 -> V_21 ;
if ( F_30 ( V_2 ) ) {
if ( V_13 -> V_30 )
V_13 -> V_30 = 0 ;
else
F_28 ( V_2 , F_33 ( V_2 ) ) ;
}
F_3 ( V_15 L_7 ) ;
}
static int F_34 ( struct V_1 * V_2 , unsigned int V_40 , unsigned long V_41 )
{
if ( ( V_40 != V_42 ) && ( V_40 != V_43 ) &&
( V_40 != V_44 ) && ( V_40 != V_45 ) &&
( V_40 != V_46 ) ) {
if ( V_2 -> V_22 & ( 1 << V_47 ) )
return - V_48 ;
}
switch ( V_40 ) {
case V_42 :
F_3 ( V_15 L_8 ) ;
return 0 ;
case V_43 :
F_3 ( V_15 L_9 ) ;
return 0 ;
case V_44 :
F_3 ( V_15 L_10 ) ;
return - V_49 ;
case V_50 :
F_3 ( V_15 L_11 ) ;
return - V_49 ;
case V_45 :
F_3 ( V_15 L_12 ) ;
#if 0
if (copy_to_user((struct async_struct *) arg,
info, sizeof(struct async_struct)))
return -EFAULT;
#endif
return 0 ;
case V_46 :
F_3 ( V_15 L_13 ) ;
return 0 ;
case V_51 :
case V_52 :
F_3 ( V_15 L_14 ) ;
return 0 ;
default:
return - V_53 ;
}
return 0 ;
}
static void F_35 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
if ( ( V_55 -> V_56 & V_57 ) &&
! ( V_2 -> V_58 -> V_56 & V_57 ) ) {
V_2 -> V_4 = 0 ;
F_4 ( V_2 ) ;
}
}
static void F_36 ( struct V_12 * V_13 )
{
unsigned long V_22 ;
struct V_59 * V_34 ;
int V_60 ;
if ( ! ( V_13 -> V_22 & V_61 ) ) return;
V_34 = V_13 -> V_34 ;
#ifdef F_2
F_3 ( L_15 , V_13 -> line ,
V_34 -> V_10 ) ;
#endif
F_15 ( V_22 ) ;
{
if ( V_13 -> V_62 )
V_13 -> V_62 -> V_63 = V_13 -> V_63 ;
if ( V_13 -> V_63 )
V_13 -> V_63 -> V_62 = V_13 -> V_62 ;
else
V_14 [ V_34 -> V_10 ] = V_13 -> V_62 ;
if ( V_34 -> V_10 && ( ! V_14 [ V_34 -> V_10 ] ||
! V_14 [ V_34 -> V_10 ] -> V_62 ) ) {
if ( V_14 [ V_34 -> V_10 ] ) {
F_37 ( V_34 -> V_10 , NULL ) ;
V_60 = F_38 ( V_34 -> V_10 , F_12 ,
F_39 ( V_13 ) , L_16 , NULL ) ;
if ( V_60 )
F_3 ( V_20 L_17
L_18 , V_60 ) ;
} else
F_37 ( V_34 -> V_10 , NULL ) ;
}
if ( V_13 -> V_23 . V_24 ) {
F_40 ( ( unsigned long ) V_13 -> V_23 . V_24 ) ;
V_13 -> V_23 . V_24 = NULL ;
}
if ( V_13 -> V_2 ) F_41 ( V_47 , & V_13 -> V_2 -> V_22 ) ;
V_13 -> V_22 &= ~ V_61 ;
}
F_17 ( V_22 ) ;
}
static void F_42 ( struct V_1 * V_2 , struct V_64 * V_65 )
{
struct V_12 * V_13 = (struct V_12 * ) V_2 -> V_21 ;
struct V_59 * V_34 ;
unsigned long V_22 ;
if ( ! V_13 ) return;
V_34 = V_13 -> V_34 ;
F_15 ( V_22 ) ;
if ( F_43 ( V_65 ) ) {
#ifdef F_2
F_3 ( L_19 ) ;
#endif
F_17 ( V_22 ) ;
return;
}
#ifdef F_2
F_3 ( L_20 , V_13 -> line , V_34 -> V_29 ) ;
#endif
if ( ( V_2 -> V_29 == 1 ) && ( V_34 -> V_29 != 1 ) ) {
F_3 ( V_20 L_21
L_22 , V_34 -> V_29 ) ;
V_34 -> V_29 = 1 ;
}
if ( -- V_34 -> V_29 < 0 ) {
F_3 ( V_20 L_23 ,
V_13 -> line , V_34 -> V_29 ) ;
V_34 -> V_29 = 0 ;
}
if ( V_34 -> V_29 ) {
F_17 ( V_22 ) ;
return;
}
V_13 -> V_22 |= V_66 ;
F_17 ( V_22 ) ;
F_36 ( V_13 ) ;
F_26 ( V_2 ) ;
F_44 ( V_2 ) ;
V_13 -> V_67 = 0 ;
V_13 -> V_2 = NULL ;
if ( V_13 -> V_68 ) {
if ( V_13 -> V_69 )
F_45 ( V_13 -> V_69 ) ;
F_46 ( & V_13 -> V_70 ) ;
}
V_13 -> V_22 &= ~ ( V_71 | V_66 ) ;
F_46 ( & V_13 -> V_72 ) ;
}
static void F_47 ( struct V_1 * V_2 , int V_73 )
{
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = (struct V_12 * ) V_2 -> V_21 ;
struct V_59 * V_34 = V_13 -> V_34 ;
#ifdef F_2
F_3 ( L_24 ) ;
#endif
V_34 = V_13 -> V_34 ;
F_26 ( V_2 ) ;
if ( V_13 -> V_22 & V_66 )
return;
F_36 ( V_13 ) ;
V_13 -> V_67 = 0 ;
V_34 -> V_29 = 0 ;
V_13 -> V_22 &= ~ V_71 ;
V_13 -> V_2 = NULL ;
F_46 ( & V_13 -> V_70 ) ;
}
static int F_49 ( int line , struct V_12 * * V_74 )
{
struct V_12 * V_13 ;
struct V_59 * V_75 ;
V_75 = V_76 + line ;
V_75 -> V_29 ++ ;
if ( V_75 -> V_13 ) {
* V_74 = V_75 -> V_13 ;
return 0 ;
}
V_13 = F_50 ( sizeof( struct V_12 ) , V_77 ) ;
if ( ! V_13 ) {
V_75 -> V_29 -- ;
return - V_78 ;
}
F_51 ( & V_13 -> V_70 ) ;
F_51 ( & V_13 -> V_72 ) ;
F_51 ( & V_13 -> V_79 ) ;
V_13 -> V_80 = V_81 ;
V_13 -> V_82 = V_75 -> V_82 ;
V_13 -> V_22 = V_75 -> V_22 ;
V_13 -> V_83 = V_75 -> V_83 ;
V_13 -> line = line ;
F_52 ( & V_13 -> V_84 , F_13 ) ;
V_13 -> V_34 = V_75 ;
if ( V_75 -> V_13 ) {
F_53 ( V_13 ) ;
* V_74 = V_75 -> V_13 ;
return 0 ;
}
* V_74 = V_75 -> V_13 = V_13 ;
return 0 ;
}
static int
F_54 ( struct V_12 * V_13 )
{
unsigned long V_22 ;
int V_60 = 0 ;
T_2 V_85 ;
struct V_59 * V_34 = V_13 -> V_34 ;
unsigned long V_86 ;
V_86 = F_55 ( V_77 ) ;
if ( ! V_86 )
return - V_78 ;
F_15 ( V_22 ) ;
if ( V_13 -> V_22 & V_61 ) {
F_40 ( V_86 ) ;
goto V_87;
}
if ( ! V_34 -> V_82 || ! V_34 -> type ) {
if ( V_13 -> V_2 ) F_41 ( V_47 , & V_13 -> V_2 -> V_22 ) ;
F_40 ( V_86 ) ;
goto V_87;
}
if ( V_13 -> V_23 . V_24 )
F_40 ( V_86 ) ;
else
V_13 -> V_23 . V_24 = ( unsigned char * ) V_86 ;
#ifdef F_2
F_3 ( L_25 , V_13 -> line , V_34 -> V_10 ) ;
#endif
if ( V_34 -> V_10 && ( ! V_14 [ V_34 -> V_10 ] ||
! V_14 [ V_34 -> V_10 ] -> V_62 ) ) {
if ( V_14 [ V_34 -> V_10 ] ) {
V_60 = - V_88 ;
goto V_87;
} else
V_85 = F_12 ;
V_60 = F_38 ( V_34 -> V_10 , V_85 , F_39 ( V_13 ) , L_26 , NULL ) ;
if ( V_60 ) {
if ( F_56 ( V_89 ) ) {
if ( V_13 -> V_2 )
F_41 ( V_47 ,
& V_13 -> V_2 -> V_22 ) ;
V_60 = 0 ;
}
goto V_87;
}
}
V_13 -> V_63 = NULL ;
V_13 -> V_62 = V_14 [ V_34 -> V_10 ] ;
if ( V_13 -> V_62 )
V_13 -> V_62 -> V_63 = V_13 ;
V_14 [ V_34 -> V_10 ] = V_13 ;
if ( V_13 -> V_2 ) F_57 ( V_47 , & V_13 -> V_2 -> V_22 ) ;
V_13 -> V_23 . V_25 = V_13 -> V_23 . V_26 = 0 ;
#if 0
timer_table[RS_TIMER].expires = jiffies + 2*HZ/100;
timer_active |= 1 << RS_TIMER;
#endif
if ( V_13 -> V_2 ) {
if ( ( V_13 -> V_22 & V_90 ) == V_91 )
V_13 -> V_2 -> V_92 = 57600 ;
if ( ( V_13 -> V_22 & V_90 ) == V_93 )
V_13 -> V_2 -> V_92 = 115200 ;
if ( ( V_13 -> V_22 & V_90 ) == V_94 )
V_13 -> V_2 -> V_92 = 230400 ;
if ( ( V_13 -> V_22 & V_90 ) == V_95 )
V_13 -> V_2 -> V_92 = 460800 ;
}
V_13 -> V_22 |= V_61 ;
F_17 ( V_22 ) ;
return 0 ;
V_87:
F_17 ( V_22 ) ;
return V_60 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_64 * V_65 )
{
struct V_12 * V_13 ;
int V_60 , line ;
unsigned long V_86 ;
line = V_2 -> V_96 ;
if ( ( line < 0 ) || ( line >= V_97 ) )
return - V_98 ;
V_60 = F_49 ( line , & V_13 ) ;
if ( V_60 )
return V_60 ;
V_2 -> V_21 = V_13 ;
V_13 -> V_2 = V_2 ;
#ifdef F_2
F_3 ( L_27 , V_2 -> V_99 , V_13 -> V_34 -> V_29 ) ;
#endif
V_13 -> V_2 -> V_100 = ( V_13 -> V_22 & V_101 ) ? 1 : 0 ;
if ( ! V_39 ) {
V_86 = F_55 ( V_77 ) ;
if ( ! V_86 )
return - V_78 ;
if ( V_39 )
F_40 ( V_86 ) ;
else
V_39 = ( unsigned char * ) V_86 ;
}
if ( F_43 ( V_65 ) ||
( V_13 -> V_22 & V_66 ) ) {
if ( V_13 -> V_22 & V_66 )
F_59 ( & V_13 -> V_72 ) ;
#ifdef F_60
return ( ( V_13 -> V_22 & V_102 ) ?
- V_103 : - V_104 ) ;
#else
return - V_103 ;
#endif
}
V_60 = F_54 ( V_13 ) ;
if ( V_60 ) {
return V_60 ;
}
V_32 = V_105 ;
while ( V_32 ) {
if ( ( V_32 -> V_22 & V_106 ) && V_32 -> V_33 ) break;
V_32 = V_32 -> V_107 ;
}
#ifdef F_2
F_3 ( L_28 , V_13 -> line ) ;
#endif
return 0 ;
}
static inline void F_61 ( struct V_108 * V_109 , struct V_59 * V_34 )
{
F_62 ( V_109 , L_29 ,
V_34 -> line , V_110 [ V_34 -> type ] . V_99 ,
V_34 -> V_82 , V_34 -> V_10 ) ;
}
static int F_63 ( struct V_108 * V_109 , void * V_111 )
{
int V_112 ;
F_62 ( V_109 , L_30 , V_113 ) ;
for ( V_112 = 0 ; V_112 < V_97 ; V_112 ++ )
F_61 ( V_109 , & V_76 [ V_112 ] ) ;
return 0 ;
}
static int F_64 ( struct V_114 * V_114 , struct V_64 * V_64 )
{
return F_65 ( V_64 , F_63 , NULL ) ;
}
static inline void F_66 ( void )
{
F_3 ( V_15 L_31 , V_115 , V_113 ) ;
F_3 ( V_15 L_32 ) ;
}
static int T_3
F_67 ( void )
{
int V_112 , V_116 ;
struct V_59 * V_34 ;
if ( ! F_68 ( L_33 ) )
return - V_98 ;
V_117 = F_69 ( 1 ) ;
if ( ! V_117 )
return - V_78 ;
F_66 () ;
V_117 -> V_118 = V_119 ;
V_117 -> V_120 = L_26 ;
V_117 -> V_99 = L_34 ;
V_117 -> V_121 = V_122 ;
V_117 -> V_123 = 64 ;
V_117 -> type = V_124 ;
V_117 -> V_125 = V_126 ;
V_117 -> V_127 = V_128 ;
V_117 -> V_127 . V_56 =
V_129 | V_130 | V_131 | V_132 | V_133 ;
V_117 -> V_22 = V_134 ;
F_70 ( V_117 , & V_135 ) ;
for ( V_112 = 0 , V_34 = V_76 ; V_112 < V_97 ; V_112 ++ , V_34 ++ ) {
if ( V_34 -> type == V_136 ) continue;
if ( ! V_34 -> V_10 ) {
if ( ( V_116 = F_71 ( V_137 ) ) < 0 )
F_72 ( L_35 ,
V_138 ) ;
V_34 -> V_10 = V_116 ;
F_73 ( V_139 , V_34 -> V_10 ) ;
}
F_3 ( V_15 L_36 ,
V_34 -> line ,
V_34 -> V_82 , V_34 -> V_10 ,
V_110 [ V_34 -> type ] . V_99 ) ;
}
if ( F_74 ( V_117 ) )
F_72 ( L_37 ) ;
return 0 ;
}
