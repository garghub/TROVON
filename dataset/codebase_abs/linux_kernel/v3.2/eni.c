static void F_1 ( void )
{
}
static void F_2 ( const char * V_1 , unsigned long V_2 , unsigned long V_3 )
{
V_4 [ V_5 ] = V_1 ;
V_6 [ V_5 ] = V_2 ;
V_7 [ V_5 ] = V_3 ;
V_5 = ( V_5 + 1 ) % V_8 ;
}
static void F_1 ( void )
{
int V_9 , V_10 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
V_10 = ( V_5 + V_9 ) % V_8 ;
F_3 ( V_11 ) ;
F_3 ( V_4 [ V_10 ] ? V_4 [ V_10 ] : L_1 , V_6 [ V_10 ] , V_7 [ V_10 ] ) ;
}
}
static void F_4 ( struct V_12 * V_12 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_12 -> V_13 ; V_10 ++ )
F_3 ( V_14 L_2 , V_10 ,
V_12 -> V_15 [ V_10 ] . V_16 ,
1 << V_12 -> V_15 [ V_10 ] . V_17 ) ;
}
static void F_5 ( struct V_18 * V_19 )
{
struct V_12 * V_12 ;
int V_10 ;
V_12 = F_6 ( V_19 ) ;
F_3 ( V_11 L_3 ) ;
F_4 ( V_12 ) ;
F_3 ( V_11 L_4 ) ;
for ( V_10 = 0 ; V_10 < V_20 ; V_10 ++ )
if ( V_12 -> V_21 [ V_10 ] . V_22 )
F_3 ( V_11 L_5 , V_10 ,
V_12 -> V_21 [ V_10 ] . V_22 , V_12 -> V_21 [ V_10 ] . V_23 * 4 ) ;
F_3 ( V_11 L_6 ) ;
for ( V_10 = 0 ; V_10 < 1024 ; V_10 ++ )
if ( V_12 -> V_24 [ V_10 ] && F_7 ( V_12 -> V_24 [ V_10 ] ) -> V_25 )
F_3 ( V_11 L_7 , V_10 ,
F_7 ( V_12 -> V_24 [ V_10 ] ) -> V_26 ,
F_7 ( V_12 -> V_24 [ V_10 ] ) -> V_23 * 4 ) ;
F_3 ( V_11 L_8 ) ;
}
static void F_8 ( struct V_12 * V_12 , void T_1 * V_16 ,
unsigned long V_27 )
{
struct V_28 * V_29 ;
int V_30 , V_17 ;
F_9 ( L_9 , V_16 , V_27 , V_27 ) ;
V_16 += V_12 -> V_31 ;
V_29 = V_12 -> V_15 ;
V_30 = V_12 -> V_13 ;
while ( V_27 ) {
if ( V_30 >= V_12 -> V_32 ) {
F_3 ( V_33 L_10 ,
V_16 , V_27 ) ;
break;
}
for ( V_17 = 0 ; ! ( ( ( unsigned long ) V_16 | V_27 ) & ( 1 << V_17 ) ) ; V_17 ++ ) ;
if ( V_34 > ( 1 << V_17 ) ) {
F_3 ( V_33 L_11 ,
V_17 ) ;
break;
}
V_29 [ V_30 ] . V_16 = ( void T_1 * ) V_16 ;
V_29 [ V_30 ] . V_17 = V_17 ;
V_30 ++ ;
V_16 += 1 << V_17 ;
V_27 -= 1 << V_17 ;
}
V_12 -> V_13 = V_30 ;
}
static void T_1 * F_10 ( struct V_12 * V_12 , unsigned long * V_27 )
{
struct V_28 * V_29 ;
void T_1 * V_16 ;
int V_30 , V_10 , V_17 , V_35 , V_36 ;
V_29 = V_12 -> V_15 ;
V_30 = V_12 -> V_13 ;
if ( * V_27 < V_34 ) * V_27 = V_34 ;
if ( * V_27 > V_37 ) return NULL ;
for ( V_17 = 0 ; ( 1 << V_17 ) < * V_27 ; V_17 ++ ) ;
F_9 ( L_12 , * V_27 , V_17 ) ;
V_35 = 65 ;
V_36 = 0 ;
for ( V_10 = 0 ; V_10 < V_30 ; V_10 ++ )
if ( V_29 [ V_10 ] . V_17 == V_17 ) {
V_35 = V_17 ;
V_36 = V_10 ;
break;
}
else if ( V_35 > V_29 [ V_10 ] . V_17 && V_29 [ V_10 ] . V_17 > V_17 ) {
V_35 = V_29 [ V_10 ] . V_17 ;
V_36 = V_10 ;
}
if ( V_35 == 65 ) return NULL ;
V_16 = V_29 [ V_36 ] . V_16 - V_12 -> V_31 ;
V_29 [ V_36 ] = V_29 [ -- V_30 ] ;
V_12 -> V_13 = V_30 ;
* V_27 = 1 << V_17 ;
F_8 ( V_12 , V_16 + * V_27 , ( 1 << V_35 ) - * V_27 ) ;
F_9 ( L_13 , * V_27 , V_17 , V_16 ) ;
F_11 ( V_16 , 0 , * V_27 ) ;
return V_16 ;
}
static void F_12 ( struct V_12 * V_12 , void T_1 * V_16 ,
unsigned long V_27 )
{
struct V_28 * V_29 ;
int V_30 , V_10 , V_17 ;
V_16 += V_12 -> V_31 ;
V_29 = V_12 -> V_15 ;
V_30 = V_12 -> V_13 ;
for ( V_17 = - 1 ; V_27 ; V_17 ++ ) V_27 >>= 1 ;
F_9 ( L_14 , V_16 , V_27 , V_17 ) ;
for ( V_10 = 0 ; V_10 < V_30 ; V_10 ++ )
if ( ( ( unsigned long ) V_29 [ V_10 ] . V_16 ) == ( ( unsigned long ) V_16 ^ ( 1 << V_17 ) ) &&
V_29 [ V_10 ] . V_17 == V_17 ) {
F_9 ( L_15 , V_10 ,
V_29 [ V_10 ] . V_16 , V_16 , 1 << V_17 , V_29 [ V_10 ] . V_17 , V_17 ) ;
V_29 [ V_10 ] = V_29 [ -- V_30 ] ;
V_16 = ( void T_1 * ) ( ( unsigned long ) V_16 & ~ ( unsigned long ) ( 1 << V_17 ) ) ;
V_17 ++ ;
V_10 = - 1 ;
continue;
}
if ( V_30 >= V_12 -> V_32 ) {
F_3 ( V_38 L_16 , V_16 ,
V_17 ) ;
return;
}
V_29 [ V_30 ] . V_16 = V_16 ;
V_29 [ V_30 ] . V_17 = V_17 ;
V_12 -> V_13 = V_30 + 1 ;
}
static void F_13 ( struct V_39 * V_40 )
{
struct V_18 * V_19 ;
struct V_12 * V_12 ;
struct V_41 * V_41 ;
V_19 = V_40 -> V_19 ;
V_12 = F_6 ( V_19 ) ;
F_14 ( F_15 ( V_42 ) &
~ ( V_43 | V_44 | V_45 ) , V_42 ) ;
V_41 = F_7 ( V_40 ) ;
F_3 (KERN_ALERT DEV_LABEL L_17
L_18 ,dev->number) ;
F_3 ( V_38 L_19 , V_40 -> V_46 ,
V_41 -> V_47 , V_41 -> V_23 ) ;
F_3 ( V_38 L_20
L_21 , V_41 -> V_48 , V_41 -> V_49 ,
( unsigned ) F_16 ( V_41 -> V_26 + V_41 -> V_48 * 4 ) ) ;
F_3 ( V_38 L_22 , V_41 -> V_50 ,
V_41 -> V_51 ) ;
F_2 ( L_23 , 0 , 0 ) ;
F_3 ( V_11 L_24 ) ;
F_1 () ;
F_6 ( V_19 ) -> V_52 = NULL ;
F_6 ( V_19 ) -> V_53 = NULL ;
F_17 ( & F_6 ( V_19 ) -> V_54 ) ;
}
static int F_18 ( struct V_39 * V_40 , struct V_55 * V_56 ,
unsigned long V_57 , unsigned long V_27 , unsigned long V_58 )
{
struct V_12 * V_12 ;
struct V_41 * V_41 ;
T_2 V_59 , V_60 ;
T_2 V_61 [ V_62 * 2 ] ;
T_3 V_63 ;
unsigned long V_64 ;
int V_10 , V_65 ;
V_12 = F_6 ( V_40 -> V_19 ) ;
V_41 = F_7 ( V_40 ) ;
V_63 = 0 ;
if ( V_56 ) {
V_63 = F_19 ( V_12 -> V_66 , V_56 -> V_67 , V_56 -> V_30 ,
V_68 ) ;
F_20 ( V_56 ) = V_63 ;
if ( V_63 & 3 )
F_3 (KERN_CRIT DEV_LABEL L_25
L_26 ,vcc->dev->number,
vcc->vci,(unsigned long) paddr) ;
F_21 ( V_56 ) = V_27 + V_57 ;
F_22 ( V_56 ) -> V_40 = V_40 ;
}
V_65 = 0 ;
if ( ( V_58 && V_57 ) || 1 ) {
V_64 = ( V_41 -> V_48 + V_57 ) & ( V_41 -> V_23 - 1 ) ;
V_61 [ V_65 ++ ] = ( V_64 << V_69 ) | ( V_40 -> V_46
<< V_70 ) | V_71 ;
V_65 ++ ;
}
V_64 = ( V_41 -> V_48 + V_27 + V_57 ) & ( V_41 -> V_23 - 1 ) ;
if ( ! V_58 ) V_27 += V_57 ;
else {
unsigned long V_23 ;
if ( ! V_27 ) {
F_9 ( L_27 ) ;
F_2 ( L_28 ,
V_27 , V_58 ) ;
}
V_23 = V_58 ;
if ( V_63 & 15 ) {
unsigned long V_72 ;
V_72 = 4 - ( ( V_63 & 15 ) >> 2 ) ;
if ( V_72 > V_23 ) V_72 = V_23 ;
V_61 [ V_65 ++ ] = V_73 | ( V_72 << V_69 ) |
( V_40 -> V_46 << V_70 ) ;
V_61 [ V_65 ++ ] = V_63 ;
V_63 += V_72 << 2 ;
V_23 -= V_72 ;
}
#ifdef F_23
if ( V_23 & ~ 15 ) {
V_61 [ V_65 ++ ] = V_74 | ( ( V_23 >> 4 ) <<
V_69 ) | ( V_40 -> V_46 <<
V_70 ) ;
V_61 [ V_65 ++ ] = V_63 ;
V_63 += ( V_23 & ~ 15 ) << 2 ;
V_23 &= 15 ;
}
#endif
#ifdef F_24
if ( V_23 & ~ 7 ) {
V_61 [ V_65 ++ ] = V_75 | ( ( V_23 >> 3 ) <<
V_69 ) | ( V_40 -> V_46 <<
V_70 ) ;
V_61 [ V_65 ++ ] = V_63 ;
V_63 += ( V_23 & ~ 7 ) << 2 ;
V_23 &= 7 ;
}
#endif
#ifdef F_25
if ( V_23 & ~ 3 ) {
V_61 [ V_65 ++ ] = V_76 | ( ( V_23 >> 2 ) <<
V_69 ) | ( V_40 -> V_46 <<
V_70 ) ;
V_61 [ V_65 ++ ] = V_63 ;
V_63 += ( V_23 & ~ 3 ) << 2 ;
V_23 &= 3 ;
}
#endif
#ifdef F_26
if ( V_23 & ~ 1 ) {
V_61 [ V_65 ++ ] = V_77 | ( ( V_23 >> 1 ) <<
V_69 ) | ( V_40 -> V_46 <<
V_70 ) ;
V_61 [ V_65 ++ ] = V_63 ;
V_63 += ( V_23 & ~ 1 ) << 2 ;
V_23 &= 1 ;
}
#endif
if ( V_23 ) {
V_61 [ V_65 ++ ] = V_73 | ( V_23 << V_69 )
| ( V_40 -> V_46 << V_70 ) ;
V_61 [ V_65 ++ ] = V_63 ;
}
}
if ( V_27 != V_58 ) {
V_61 [ V_65 ++ ] = ( V_64 << V_69 ) |
( V_40 -> V_46 << V_70 ) | V_71 ;
V_65 ++ ;
}
if ( ! V_65 || V_65 > 2 * V_62 ) {
F_3 (KERN_CRIT DEV_LABEL L_29 ) ;
goto V_78;
}
V_61 [ V_65 - 2 ] |= V_79 ;
V_65 = V_65 >> 1 ;
V_60 = F_15 ( V_80 ) ;
V_59 = F_15 ( V_81 ) ;
if ( ! F_27 ( V_60 , V_65 + V_65 + 1 , V_59 , V_82 ) ) {
F_3 (KERN_WARNING DEV_LABEL L_30 ,
vcc->dev->number) ;
goto V_78;
}
for ( V_10 = 0 ; V_10 < V_65 ; V_10 ++ ) {
F_28 ( V_61 [ V_10 * 2 ] , V_12 -> V_83 + V_60 * 8 ) ;
F_28 ( V_61 [ V_10 * 2 + 1 ] , V_12 -> V_83 + V_60 * 8 + 4 ) ;
V_60 = ( V_60 + 1 ) & ( V_82 - 1 ) ;
}
if ( V_56 ) {
F_29 ( V_56 ) = V_41 -> V_48 + V_27 + 1 ;
F_30 ( & V_12 -> V_54 , V_56 ) ;
V_41 -> V_50 = V_56 ;
V_84 ++ ;
}
V_41 -> V_48 = V_64 ;
F_14 ( V_60 , V_80 ) ;
return 0 ;
V_78:
if ( V_63 )
F_31 ( V_12 -> V_66 , V_63 , V_56 -> V_30 ,
V_68 ) ;
if ( V_56 ) F_32 ( V_56 ) ;
return - 1 ;
}
static void F_33 ( struct V_39 * V_40 , unsigned long V_27 )
{
struct V_41 * V_41 ;
V_41 = F_7 ( V_40 ) ;
F_2 ( L_31 , V_27 , 0 ) ;
while ( F_18 ( V_40 , NULL , 1 , V_27 , 0 ) ) F_2 ( L_32 , 0 , 0 ) ;
if ( V_41 -> V_47 ) F_29 ( V_41 -> V_50 ) += V_27 + 1 ;
else V_41 -> V_49 = ( V_41 -> V_49 + V_27 + 1 ) & ( V_41 -> V_23 - 1 ) ;
}
static int F_34 ( struct V_39 * V_40 )
{
struct V_41 * V_41 ;
unsigned long V_48 ;
unsigned long V_85 ;
struct V_55 * V_56 ;
F_9 ( L_33 ) ;
V_41 = F_7 ( V_40 ) ;
V_48 = F_16 ( V_41 -> V_26 + V_41 -> V_48 * 4 ) ;
if ( ( V_48 & V_86 ) != ( V_87 << V_88 ) ) {
F_13 ( V_40 ) ;
return 1 ;
}
if ( V_48 & V_89 ) {
F_9 ( V_90 L_34 ,
V_40 -> V_19 -> V_91 ) ;
V_85 = 0 ;
F_35 ( & V_40 -> V_92 -> V_93 ) ;
}
else {
V_85 = V_94 - 1 ;
}
V_56 = V_85 ? F_36 ( V_40 , V_85 , V_95 ) : NULL ;
if ( ! V_56 ) {
F_33 ( V_40 , V_85 >> 2 ) ;
return 0 ;
}
F_37 ( V_56 , V_85 ) ;
V_56 -> V_96 = V_41 -> V_97 ;
F_9 ( L_35 , V_85 ) ;
if ( F_18 ( V_40 , V_56 , 1 , V_85 >> 2 , V_85 >> 2 ) ) return 1 ;
V_41 -> V_47 ++ ;
return 0 ;
}
static int F_38 ( struct V_39 * V_40 )
{
struct V_41 * V_41 ;
unsigned long V_48 ;
unsigned long V_27 , V_58 , V_85 ;
struct V_55 * V_56 ;
F_2 ( L_36 , 0 , 0 ) ;
F_9 ( L_37 ) ;
V_41 = F_7 ( V_40 ) ;
V_48 = F_16 ( V_41 -> V_26 + V_41 -> V_48 * 4 ) ;
if ( ( V_48 & V_86 ) != ( V_87 << V_88 ) ) {
F_13 ( V_40 ) ;
return 1 ;
}
if ( V_48 & ( V_89 | V_98 ) ) {
if ( V_48 & V_89 ) {
F_2 ( L_38 , V_48 , 0 ) ;
F_9 ( V_90 L_34 ,
V_40 -> V_19 -> V_91 ) ;
V_27 = 0 ;
}
else {
static unsigned long V_99 = 0 ;
if ( F_39 ( V_100 , V_99 ) || V_99 == 0 ) {
F_3 (KERN_WARNING DEV_LABEL L_39
L_40 ,
vcc->dev->number) ;
V_99 = ( V_100 + 2 * V_101 ) | 1 ;
}
V_27 = ( V_48 & V_102 ) * ( V_103 >> 2 ) ;
F_2 ( L_41 , V_48 ,
V_27 ) ;
}
V_58 = V_85 = 0 ;
F_35 ( & V_40 -> V_92 -> V_93 ) ;
}
else {
V_27 = ( V_48 & V_102 ) * ( V_103 >> 2 ) ;
F_9 ( L_42 , V_27 ) ;
V_85 = F_16 ( V_41 -> V_26 + ( ( ( V_41 -> V_48 + V_27 - 1 ) &
( V_41 -> V_23 - 1 ) ) ) * 4 ) & 0xffff ;
if ( V_85 && V_85 <= ( V_27 << 2 ) - 8 && V_85 <=
V_104 ) V_58 = ( V_85 + 3 ) >> 2 ;
else {
F_2 ( L_43 , V_48 ,
V_85 ) ;
F_3 (KERN_ERR DEV_LABEL L_44
L_45 ,
vcc->dev->number,vcc->vci,length,size << 2 ,descr) ;
V_85 = V_58 = 0 ;
F_35 ( & V_40 -> V_92 -> V_93 ) ;
}
}
V_56 = V_58 ? F_36 ( V_40 , V_58 << 2 , V_95 ) : NULL ;
if ( ! V_56 ) {
F_33 ( V_40 , V_27 ) ;
return 0 ;
}
F_37 ( V_56 , V_85 ) ;
F_9 ( L_35 , V_85 ) ;
if ( F_18 ( V_40 , V_56 , 1 , V_27 , V_58 ) ) return 1 ;
V_41 -> V_47 ++ ;
return 0 ;
}
static inline int F_40 ( struct V_39 * V_40 )
{
void T_1 * V_105 ;
unsigned long V_106 ;
struct V_41 * V_41 ;
V_41 = F_7 ( V_40 ) ;
V_105 = F_6 ( V_40 -> V_19 ) -> V_46 + V_40 -> V_46 * 16 ;
F_2 ( L_46 , 0 , 0 ) ;
while ( V_41 -> V_48 != ( V_106 = ( F_16 ( V_105 + 4 ) & V_107 ) >>
V_108 ) ) {
F_2 ( L_47 ,
V_41 -> V_48 , V_106 ) ;
F_9 ( L_48 , F_7 ( V_40 ) -> V_48 ,
( ( ( unsigned ) F_16 ( V_105 + 4 ) & V_107 ) >>
V_108 ) ) ;
if ( F_7 ( V_40 ) -> V_25 ( V_40 ) ) return 1 ;
}
F_28 ( F_16 ( V_105 ) & ~ V_109 , V_105 ) ;
F_2 ( L_49 , 0 , 0 ) ;
while ( F_7 ( V_40 ) -> V_48 != ( V_106 = ( F_16 ( V_105 + 4 ) & V_107 )
>> V_108 ) ) {
F_2 ( L_50 ,
V_41 -> V_48 , V_106 ) ;
F_9 ( L_48 , F_7 ( V_40 ) -> V_48 ,
( ( ( unsigned ) F_16 ( V_105 + 4 ) & V_107 ) >>
V_108 ) ) ;
if ( F_7 ( V_40 ) -> V_25 ( V_40 ) ) return 1 ;
}
return 0 ;
}
static void F_41 ( struct V_18 * V_19 )
{
struct V_12 * V_12 ;
struct V_39 * V_110 ;
V_12 = F_6 ( V_19 ) ;
while ( ( V_110 = V_12 -> V_52 ) ) {
F_2 ( L_51 , 0 , 0 ) ;
if ( F_40 ( V_110 ) ) return;
V_12 -> V_52 = F_7 ( V_110 ) -> V_111 ;
F_7 ( V_110 ) -> V_111 = V_112 ;
F_42 () ;
F_7 ( V_110 ) -> V_51 -- ;
}
while ( ( V_110 = V_12 -> V_53 ) ) {
F_2 ( L_52 , 0 , 0 ) ;
if ( F_40 ( V_110 ) ) return;
V_12 -> V_53 = F_7 ( V_110 ) -> V_111 ;
F_7 ( V_110 ) -> V_111 = V_112 ;
F_42 () ;
F_7 ( V_110 ) -> V_51 -- ;
}
}
static void F_43 ( struct V_18 * V_19 )
{
struct V_12 * V_12 ;
struct V_39 * V_40 ;
unsigned long V_46 ;
F_9 ( L_53 ) ;
V_12 = F_6 ( V_19 ) ;
while ( F_15 ( V_113 ) != V_12 -> V_114 ) {
V_46 = F_16 ( V_12 -> V_115 + V_12 -> V_114 * 4 ) ;
V_12 -> V_114 = ( V_12 -> V_114 + 1 ) & ( V_116 - 1 ) ;
V_40 = V_12 -> V_24 [ V_46 & 1023 ] ;
if ( ! V_40 ) {
F_3 (KERN_CRIT DEV_LABEL L_54
L_55 ,dev->number,vci) ;
continue;
}
F_2 ( L_56 , 0 , 0 ) ;
if ( F_7 ( V_40 ) -> V_111 != V_112 ) {
F_2 ( L_57 , 0 , 0 ) ;
F_9 ( L_58 , V_46 ) ;
continue;
}
F_7 ( V_40 ) -> V_97 = F_44 () ;
F_7 ( V_40 ) -> V_111 = NULL ;
if ( V_40 -> V_117 . V_118 . V_119 == V_120 ) {
if ( V_12 -> V_52 )
F_7 ( V_12 -> V_121 ) -> V_111 = V_40 ;
else V_12 -> V_52 = V_40 ;
V_12 -> V_121 = V_40 ;
}
else {
if ( V_12 -> V_53 )
F_7 ( V_12 -> V_122 ) -> V_111 = V_40 ;
else V_12 -> V_53 = V_40 ;
V_12 -> V_122 = V_40 ;
}
V_123 ++ ;
F_7 ( V_40 ) -> V_51 ++ ;
}
}
static void F_45 ( struct V_18 * V_19 )
{
struct V_12 * V_12 ;
struct V_41 * V_41 ;
struct V_39 * V_40 ;
struct V_55 * V_56 ;
void T_1 * V_105 ;
int V_124 ;
V_12 = F_6 ( V_19 ) ;
V_124 = 1 ;
while ( 1 ) {
V_56 = F_46 ( & V_12 -> V_54 ) ;
if ( ! V_56 ) {
if ( V_124 ) {
F_9 ( V_90 L_59
L_60 , V_19 -> V_91 ) ;
F_2 ( L_61 , 0 , 0 ) ;
}
break;
}
F_2 ( L_62 , F_21 ( V_56 ) ,
F_29 ( V_56 ) ) ;
V_125 ++ ;
V_40 = F_22 ( V_56 ) -> V_40 ;
V_41 = F_7 ( V_40 ) ;
V_124 = 0 ;
V_105 = V_12 -> V_46 + V_40 -> V_46 * 16 ;
if ( ! F_47 ( V_41 -> V_49 , F_21 ( V_56 ) ,
( F_16 ( V_105 + 4 ) & V_126 ) >> V_127 ,
V_41 -> V_23 ) ) {
F_2 ( L_63 , 0 , 0 ) ;
F_48 ( & V_12 -> V_54 , V_56 ) ;
break;
}
V_41 -> V_47 -- ;
V_41 -> V_49 = F_29 ( V_56 ) & ( V_41 -> V_23 - 1 ) ;
F_31 ( V_12 -> V_66 , F_20 ( V_56 ) , V_56 -> V_30 ,
V_128 ) ;
if ( ! V_56 -> V_30 ) F_32 ( V_56 ) ;
else {
F_2 ( L_64 , V_56 -> V_30 , 0 ) ;
if ( V_40 -> V_117 . V_129 == V_130 )
* ( unsigned long * ) V_56 -> V_67 =
F_49 ( * ( unsigned long * ) V_56 -> V_67 ) ;
memset ( V_56 -> V_131 , 0 , sizeof( struct V_132 ) ) ;
V_40 -> V_133 ( V_40 , V_56 ) ;
V_134 ++ ;
}
F_35 ( & V_40 -> V_92 -> V_25 ) ;
}
F_50 ( & V_12 -> V_135 ) ;
}
static int F_51 ( struct V_39 * V_40 )
{
struct V_12 * V_12 ;
struct V_41 * V_41 ;
unsigned long V_27 ;
F_9 ( L_65 ) ;
V_12 = F_6 ( V_40 -> V_19 ) ;
V_41 = F_7 ( V_40 ) ;
V_41 -> V_25 = NULL ;
if ( V_40 -> V_117 . V_118 . V_119 == V_136 ) return 0 ;
V_27 = V_40 -> V_117 . V_118 . V_137 * V_12 -> V_138 / 100 ;
if ( V_27 > V_37 && V_40 -> V_117 . V_118 . V_137 <=
V_37 )
V_27 = V_37 ;
V_41 -> V_26 = F_10 ( V_12 , & V_27 ) ;
F_9 ( L_66 , V_41 -> V_26 ) ;
V_41 -> V_23 = V_27 >> 2 ;
if ( ! V_41 -> V_26 ) return - V_139 ;
V_41 -> V_25 = V_40 -> V_117 . V_129 == V_140 ? F_38 : F_34 ;
V_41 -> V_48 = 0 ;
V_41 -> V_49 = 0 ;
V_41 -> V_47 = 0 ;
V_41 -> V_51 = 0 ;
V_41 -> V_111 = V_112 ;
return 0 ;
}
static int F_52 ( struct V_39 * V_40 )
{
void T_1 * V_64 ;
struct V_12 * V_12 ;
struct V_41 * V_41 ;
unsigned long V_27 ;
int V_17 ;
F_9 ( L_67 ) ;
V_12 = F_6 ( V_40 -> V_19 ) ;
V_41 = F_7 ( V_40 ) ;
if ( ! V_41 -> V_25 ) return 0 ;
V_64 = V_12 -> V_46 + V_40 -> V_46 * 16 ;
F_9 ( L_68 , ( unsigned ) ( V_41 -> V_26 - V_12 -> V_141 ) / 4 ) ;
V_27 = V_41 -> V_23 >> 8 ;
for ( V_17 = - 1 ; V_27 ; V_17 ++ ) V_27 >>= 1 ;
F_28 ( 0 , V_64 + 4 ) ;
F_28 ( 0 , V_64 + 8 ) ;
if ( V_12 -> V_24 [ V_40 -> V_46 ] )
F_3 (KERN_CRIT DEV_LABEL L_69
L_70 ,vcc->dev->number,vcc->vci) ;
V_12 -> V_24 [ V_40 -> V_46 ] = V_40 ;
F_28 ( ( ( V_40 -> V_117 . V_129 != V_140 ? V_142 : V_143 ) <<
V_144 ) | V_145 |
( ( ( V_41 -> V_26 - V_12 -> V_141 ) >> ( V_146 + 2 ) ) <<
V_147 ) | ( V_17 << V_148 ) , V_64 ) ;
return 0 ;
}
static void F_53 ( struct V_39 * V_40 )
{
F_54 ( V_149 , V_150 ) ;
void T_1 * V_64 ;
struct V_12 * V_12 ;
struct V_41 * V_41 ;
V_41 = F_7 ( V_40 ) ;
if ( ! V_41 -> V_25 ) return;
V_12 = F_6 ( V_40 -> V_19 ) ;
if ( V_40 -> V_151 != V_152 && V_40 -> V_46 != V_153 ) {
V_64 = V_12 -> V_46 + V_40 -> V_46 * 16 ;
F_28 ( ( F_16 ( V_64 ) & ~ V_154 ) | ( V_155 <<
V_144 ) , V_64 ) ;
F_55 ( 27 ) ;
F_28 ( F_16 ( V_64 ) & ~ V_109 , V_64 ) ;
V_12 -> V_24 [ V_40 -> V_46 ] = NULL ;
F_9 ( L_71 ) ;
F_2 ( L_72 , 0 , 0 ) ;
F_56 ( & V_12 -> V_135 , & V_149 ) ;
F_57 ( V_156 ) ;
F_42 () ;
for (; ; ) {
if ( ! V_41 -> V_51 ) {
F_42 () ;
if ( ! V_41 -> V_47 ) break;
}
F_2 ( L_73 , V_41 -> V_47 ,
V_41 -> V_51 ) ;
F_3 ( V_157 L_74 , V_41 -> V_51 ,
V_41 -> V_47 ) ;
F_58 () ;
F_57 ( V_156 ) ;
}
for (; ; ) {
int V_158 ;
T_2 V_106 ;
F_59 ( & V_12 -> V_159 ) ;
V_106 = F_16 ( V_12 -> V_46 + V_40 -> V_46 * 16 + 4 ) & V_126 ;
V_158 = V_41 -> V_49 == V_106 >> V_127 ;
F_60 ( & V_12 -> V_159 ) ;
if ( V_158 ) break;
F_2 ( L_75 ,
V_41 -> V_49 , V_106 ) ;
F_3 ( V_157 L_76 ,
V_41 -> V_49 , V_106 ) ;
F_58 () ;
F_57 ( V_156 ) ;
}
F_57 ( V_160 ) ;
F_61 ( & V_12 -> V_135 , & V_149 ) ;
}
F_12 ( V_12 , V_41 -> V_26 , V_41 -> V_23 << 2 ) ;
V_41 -> V_25 = NULL ;
}
static int F_62 ( struct V_18 * V_19 )
{
struct V_12 * V_12 ;
V_12 = F_6 ( V_19 ) ;
V_12 -> V_24 = (struct V_39 * * ) F_63 ( V_161 ) ;
if ( ! V_12 -> V_24 ) {
F_3 (KERN_ERR DEV_LABEL L_77 ,
dev->number) ;
F_64 ( ( unsigned long ) V_12 -> V_15 ) ;
return - V_162 ;
}
V_12 -> V_138 = V_163 ;
V_12 -> V_52 = V_12 -> V_121 = NULL ;
V_12 -> V_53 = V_12 -> V_122 = NULL ;
F_65 ( & V_12 -> V_135 ) ;
F_17 ( & V_12 -> V_54 ) ;
V_12 -> V_114 = F_15 ( V_113 ) ;
F_14 ( 0 , V_80 ) ;
return 0 ;
}
static inline void F_66 ( int V_164 , T_2 * V_61 , int * V_65 , T_3 V_63 ,
T_2 V_27 )
{
T_2 V_72 , V_23 ;
F_9 ( L_78 , ( unsigned long ) V_63 , V_27 ) ;
F_2 ( L_79 , ( unsigned long ) V_63 , V_27 ) ;
#if 0
if (paddr & 3)
printk(KERN_ERR "put_dma: unaligned addr (0x%lx)\n",paddr);
if (size & 3)
printk(KERN_ERR "put_dma: unaligned size (0x%lx)\n",size);
#endif
if ( V_63 & 3 ) {
V_72 = 4 - ( V_63 & 3 ) ;
if ( V_72 > V_27 || V_27 < 7 ) V_72 = V_27 ;
F_9 ( L_80 ,
( unsigned long ) V_63 , V_72 , V_27 ) ;
V_61 [ ( * V_65 ) ++ ] = V_165 | ( V_72 << V_69 ) |
( V_164 << V_166 ) ;
V_61 [ ( * V_65 ) ++ ] = V_63 ;
V_63 += V_72 ;
V_27 -= V_72 ;
}
V_23 = V_27 >> 2 ;
V_27 &= 3 ;
if ( V_23 && ( V_63 & 31 ) ) {
V_72 = 8 - ( ( V_63 & 31 ) >> 2 ) ;
if ( V_72 > V_23 ) V_72 = V_23 ;
F_9 ( L_81 ,
( unsigned long ) V_63 , V_72 , V_23 ) ;
V_61 [ ( * V_65 ) ++ ] = V_73 | ( V_72 << V_69 ) |
( V_164 << V_166 ) ;
V_61 [ ( * V_65 ) ++ ] = V_63 ;
V_63 += V_72 << 2 ;
V_23 -= V_72 ;
}
#ifdef F_67
if ( V_23 & ~ 15 ) {
F_9 ( L_82 ,
( unsigned long ) V_63 , V_23 >> 4 , V_23 ) ;
V_61 [ ( * V_65 ) ++ ] = V_74 | ( ( V_23 >> 4 ) << V_69 )
| ( V_164 << V_166 ) ;
V_61 [ ( * V_65 ) ++ ] = V_63 ;
V_63 += ( V_23 & ~ 15 ) << 2 ;
V_23 &= 15 ;
}
#endif
#ifdef F_68
if ( V_23 & ~ 7 ) {
F_9 ( L_83 ,
( unsigned long ) V_63 , V_23 >> 3 , V_23 ) ;
V_61 [ ( * V_65 ) ++ ] = V_75 | ( ( V_23 >> 3 ) << V_69 )
| ( V_164 << V_166 ) ;
V_61 [ ( * V_65 ) ++ ] = V_63 ;
V_63 += ( V_23 & ~ 7 ) << 2 ;
V_23 &= 7 ;
}
#endif
#ifdef F_69
if ( V_23 & ~ 3 ) {
F_9 ( L_84 ,
( unsigned long ) V_63 , V_23 >> 2 , V_23 ) ;
V_61 [ ( * V_65 ) ++ ] = V_76 | ( ( V_23 >> 2 ) << V_69 )
| ( V_164 << V_166 ) ;
V_61 [ ( * V_65 ) ++ ] = V_63 ;
V_63 += ( V_23 & ~ 3 ) << 2 ;
V_23 &= 3 ;
}
#endif
#ifdef F_70
if ( V_23 & ~ 1 ) {
F_9 ( L_85 ,
( unsigned long ) V_63 , V_23 >> 1 , V_23 ) ;
V_61 [ ( * V_65 ) ++ ] = V_77 | ( ( V_23 >> 1 ) << V_69 )
| ( V_164 << V_166 ) ;
V_61 [ ( * V_65 ) ++ ] = V_63 ;
V_63 += ( V_23 & ~ 1 ) << 2 ;
V_23 &= 1 ;
}
#endif
if ( V_23 ) {
F_9 ( L_86 , ( unsigned long ) V_63 ,
V_23 ) ;
V_61 [ ( * V_65 ) ++ ] = V_73 | ( V_23 << V_69 ) |
( V_164 << V_166 ) ;
V_61 [ ( * V_65 ) ++ ] = V_63 ;
V_63 += V_23 << 2 ;
}
if ( V_27 ) {
F_9 ( L_87 , ( unsigned long ) V_63 ,
V_27 ) ;
V_61 [ ( * V_65 ) ++ ] = V_165 | ( V_27 << V_69 ) |
( V_164 << V_166 ) ;
V_61 [ ( * V_65 ) ++ ] = V_63 ;
}
}
static enum V_167 F_71 ( struct V_55 * V_56 )
{
struct V_39 * V_40 ;
struct V_12 * V_12 ;
struct V_41 * V_41 ;
struct V_168 * V_21 ;
T_3 V_63 ;
T_2 V_59 , V_60 ;
T_2 V_27 ;
int V_169 , V_170 , V_10 , V_65 ;
F_9 ( L_88 ) ;
F_72 ( V_56 ) ;
F_2 ( L_89 , ( unsigned long ) V_56 , V_56 -> V_30 ) ;
V_40 = F_22 ( V_56 ) -> V_40 ;
F_72 ( V_40 ) ;
V_12 = F_6 ( V_40 -> V_19 ) ;
F_72 ( V_12 ) ;
V_41 = F_7 ( V_40 ) ;
V_21 = V_41 -> V_21 ;
F_72 ( V_21 ) ;
#if 0
{
unsigned int hack = *((char *) skb->data)-'0';
if (hack < 8) {
skb->data += hack;
skb->len -= hack;
}
}
#endif
#if 0
if ((unsigned long) skb->data & 3)
printk(KERN_ERR DEV_LABEL "(itf %d): VCI %d has mis-aligned "
"TX data\n",vcc->dev->number,vcc->vci);
#endif
V_169 = V_40 -> V_117 . V_129 == V_140 ;
if ( ! V_169 )
V_27 = ( V_103 >> 2 ) + V_171 ;
else {
V_27 = V_56 -> V_30 + 4 * V_172 + V_103 - 1 ;
V_27 = ( ( V_27 - ( V_27 % V_103 ) ) >> 2 ) + V_171 ;
}
if ( ! F_27 ( V_21 -> V_173 , V_27 + V_174 ,
F_15 ( F_73 ( V_21 -> V_36 ) ) , V_21 -> V_23 ) ) {
F_9 ( V_90 L_90 ,
V_40 -> V_19 -> V_91 , V_27 ) ;
return V_175 ;
}
V_60 = F_15 ( V_176 ) ;
V_59 = F_15 ( V_177 ) ;
V_170 = 3 ;
F_9 ( L_91 , F_74 ( V_56 ) -> V_178 ) ;
if ( ! F_74 ( V_56 ) -> V_178 ) V_170 += 5 ;
else V_170 += 5 * ( F_74 ( V_56 ) -> V_178 + 1 ) ;
if ( V_170 > V_179 ) {
F_3 (KERN_CRIT DEV_LABEL L_92
L_93 ,vcc->dev->number,dma_size,TX_DMA_BUF) ;
}
F_9 ( L_94 , V_60 , V_21 -> V_173 ) ;
if ( V_60 != V_59 && ( ( V_59 + V_180 - V_60 ) & ( V_180 - 1 ) ) <
V_170 ) {
F_3 (KERN_WARNING DEV_LABEL L_95 ,
vcc->dev->number) ;
return V_181 ;
}
V_63 = F_19 ( V_12 -> V_66 , V_56 -> V_67 , V_56 -> V_30 ,
V_128 ) ;
F_20 ( V_56 ) = V_63 ;
V_65 = 0 ;
V_12 -> V_61 [ V_65 ++ ] = ( ( ( V_21 -> V_173 + V_171 ) & ( V_21 -> V_23 - 1 ) ) <<
V_69 ) | ( V_21 -> V_36 << V_166 ) |
V_71 ;
V_65 ++ ;
if ( ! F_74 ( V_56 ) -> V_178 )
if ( V_169 ) F_66 ( V_21 -> V_36 , V_12 -> V_61 , & V_65 , V_63 , V_56 -> V_30 ) ;
else F_66 ( V_21 -> V_36 , V_12 -> V_61 , & V_65 , V_63 + 4 , V_56 -> V_30 - 4 ) ;
else {
F_9 ( L_96 ) ;
for ( V_10 = - 1 ; V_10 < F_74 ( V_56 ) -> V_178 ; V_10 ++ )
if ( V_10 == - 1 )
F_66 ( V_21 -> V_36 , V_12 -> V_61 , & V_65 , ( unsigned long )
V_56 -> V_67 ,
F_75 ( V_56 ) ) ;
else
F_66 ( V_21 -> V_36 , V_12 -> V_61 , & V_65 , ( unsigned long )
F_76 ( & F_74 ( V_56 ) -> V_182 [ V_10 ] ) +
F_74 ( V_56 ) -> V_182 [ V_10 ] . V_183 ,
F_77 ( & F_74 ( V_56 ) -> V_182 [ V_10 ] ) ) ;
}
if ( V_56 -> V_30 & 3 )
F_66 ( V_21 -> V_36 , V_12 -> V_61 , & V_65 , V_184 , 4 - ( V_56 -> V_30 & 3 ) ) ;
V_12 -> V_61 [ V_65 ++ ] = ( ( ( V_21 -> V_173 + V_27 ) & ( V_21 -> V_23 - 1 ) ) <<
V_69 ) | ( V_21 -> V_36 << V_166 ) |
V_79 | V_71 ;
V_65 ++ ;
F_9 ( L_97 , V_65 ) ;
F_28 ( ( V_185 << V_186 ) |
( V_169 ? V_187 : 0 ) | ( V_21 -> V_188 << V_189 ) |
( V_21 -> V_190 << V_191 ) |
( V_27 / ( V_103 / 4 ) ) , V_21 -> V_22 + V_21 -> V_173 * 4 ) ;
F_28 ( ( V_40 -> V_46 << V_192 ) |
( V_169 ? 0 : ( V_56 -> V_67 [ 3 ] & 0xf ) ) |
( F_22 ( V_56 ) -> V_193 & V_194 ? V_195 : 0 ) ,
V_21 -> V_22 + ( ( V_21 -> V_173 + 1 ) & ( V_21 -> V_23 - 1 ) ) * 4 ) ;
F_9 ( L_98 , V_27 , V_56 -> V_30 ) ;
if ( V_169 )
F_28 ( V_56 -> V_30 , V_21 -> V_22 +
( ( V_21 -> V_173 + V_27 - V_172 ) & ( V_21 -> V_23 - 1 ) ) * 4 ) ;
V_65 = V_65 >> 1 ;
for ( V_10 = 0 ; V_10 < V_65 ; V_10 ++ ) {
F_28 ( V_12 -> V_61 [ V_10 * 2 ] , V_12 -> V_196 + V_60 * 8 ) ;
F_28 ( V_12 -> V_61 [ V_10 * 2 + 1 ] , V_12 -> V_196 + V_60 * 8 + 4 ) ;
V_60 = ( V_60 + 1 ) & ( V_180 - 1 ) ;
}
F_29 ( V_56 ) = V_21 -> V_173 ;
F_21 ( V_56 ) = V_27 ;
F_7 ( V_40 ) -> V_197 += V_27 ;
V_21 -> V_173 = ( V_21 -> V_173 + V_27 ) & ( V_21 -> V_23 - 1 ) ;
F_9 ( L_99 , V_60 , V_21 -> V_173 ) ;
F_14 ( V_60 , V_176 ) ;
F_30 ( & V_12 -> V_198 , V_56 ) ;
V_199 ++ ;
return V_200 ;
}
static void F_78 ( struct V_18 * V_19 )
{
struct V_168 * V_21 ;
struct V_55 * V_56 ;
enum V_167 V_201 ;
int V_10 ;
F_9 ( L_100 ) ;
for ( V_10 = V_20 - 1 ; V_10 >= 0 ; V_10 -- ) {
V_21 = & F_6 ( V_19 ) -> V_21 [ V_10 ] ;
if ( V_21 -> V_22 )
while ( ( V_56 = F_46 ( & V_21 -> V_202 ) ) ) {
V_201 = F_71 ( V_56 ) ;
if ( V_201 == V_200 ) continue;
F_9 ( L_101 ) ;
F_48 ( & V_21 -> V_202 , V_56 ) ;
V_203 ++ ;
if ( V_201 == V_181 ) return;
break;
}
}
}
static void F_79 ( struct V_18 * V_19 )
{
struct V_12 * V_12 ;
struct V_39 * V_40 ;
struct V_55 * V_56 ;
struct V_168 * V_21 ;
F_72 ( V_19 ) ;
V_12 = F_6 ( V_19 ) ;
F_72 ( V_12 ) ;
while ( ( V_56 = F_46 ( & V_12 -> V_198 ) ) ) {
V_40 = F_22 ( V_56 ) -> V_40 ;
F_72 ( V_40 ) ;
V_21 = F_7 ( V_40 ) -> V_21 ;
F_72 ( F_7 ( V_40 ) -> V_21 ) ;
F_9 ( L_102 , F_29 ( V_56 ) ,
( unsigned ) F_15 ( F_80 ( V_21 -> V_36 ) ) ) ;
if ( F_7 ( V_40 ) -> V_197 < V_21 -> V_23 && F_29 ( V_56 ) ==
F_15 ( F_80 ( V_21 -> V_36 ) ) ) {
F_48 ( & V_12 -> V_198 , V_56 ) ;
break;
}
F_7 ( V_40 ) -> V_197 -= F_21 ( V_56 ) ;
F_31 ( V_12 -> V_66 , F_20 ( V_56 ) , V_56 -> V_30 ,
V_128 ) ;
if ( V_40 -> V_204 ) V_40 -> V_204 ( V_40 , V_56 ) ;
else F_32 ( V_56 ) ;
F_35 ( & V_40 -> V_92 -> V_21 ) ;
F_50 ( & V_12 -> V_205 ) ;
V_206 ++ ;
}
}
static struct V_168 * F_81 ( struct V_12 * V_12 , int V_207 )
{
int V_10 ;
for ( V_10 = ! V_207 ; V_10 < V_20 ; V_10 ++ )
if ( ! V_12 -> V_21 [ V_10 ] . V_22 ) return V_12 -> V_21 + V_10 ;
return NULL ;
}
static int F_82 ( struct V_12 * V_12 , int * V_208 , int V_209 , int * V_210 ,
int * V_201 , int V_211 )
{
static const int V_212 [] = { 4 , 16 , 128 , 2048 } ;
if ( V_211 ) * V_210 = * V_201 = 0 ;
else {
if ( * V_208 > 0 ) {
int div ;
for ( * V_210 = 0 ; * V_210 < 3 ; ( * V_210 ) ++ )
if ( V_213 / V_212 [ * V_210 ] / 64 <= * V_208 ) break;
div = V_212 [ * V_210 ] * * V_208 ;
F_9 ( L_103 , div ) ;
* V_201 = V_213 / div - 1 ;
}
else {
int div ;
if ( ! * V_208 ) * V_208 = V_12 -> V_214 + V_209 ;
for ( * V_210 = 3 ; * V_210 >= 0 ; ( * V_210 ) -- )
if ( V_213 / V_212 [ * V_210 ] / 64 > - * V_208 ) break;
if ( * V_210 < 3 ) ( * V_210 ) ++ ;
div = V_212 [ * V_210 ] * - * V_208 ;
F_9 ( L_104 , div ) ;
* V_201 = F_83 ( V_213 , div ) - 1 ;
}
if ( * V_201 < 0 ) * V_201 = 0 ;
if ( * V_201 > V_215 ) * V_201 = V_215 ;
}
* V_208 = V_213 / V_212 [ * V_210 ] / ( * V_201 + 1 ) ;
F_9 ( L_105 , * V_208 , * V_210 , * V_201 ) ;
return 0 ;
}
static int F_84 ( struct V_39 * V_40 , struct V_216 * V_217 ,
int V_218 , int V_219 )
{
struct V_12 * V_12 = F_6 ( V_40 -> V_19 ) ;
struct V_41 * V_41 = F_7 ( V_40 ) ;
struct V_168 * V_21 ;
unsigned long V_27 ;
void T_1 * V_220 ;
int V_221 , V_207 , V_211 , V_222 ;
int V_210 , V_201 , V_17 ;
int error ;
V_221 = F_85 ( V_217 ) ;
V_207 = V_217 -> V_119 == V_223 ;
V_211 = V_207 && ( ! V_221 || V_221 <= - V_224 ||
V_221 >= V_224 ) ;
if ( ! V_211 ) {
V_27 = V_217 -> V_137 * V_12 -> V_225 / 100 ;
if ( V_27 > V_37 && V_217 -> V_137 <=
V_37 )
V_27 = V_37 ;
}
else {
if ( V_12 -> V_207 ) {
V_41 -> V_21 = V_12 -> V_207 ;
V_217 -> V_208 = V_224 ;
return 0 ;
}
V_27 = V_226 ;
}
V_222 = ! V_41 -> V_21 ;
V_220 = NULL ;
if ( ! V_222 ) V_21 = V_41 -> V_21 ;
else {
V_220 = F_10 ( V_12 , & V_27 ) ;
if ( ! V_220 ) return - V_139 ;
V_21 = F_81 ( V_12 , V_211 ) ;
if ( ! V_21 ) {
F_12 ( V_12 , V_220 , V_27 ) ;
return - V_227 ;
}
F_9 ( L_106 , V_21 -> V_36 ) ;
V_21 -> V_209 = V_21 -> V_228 = 0 ;
V_21 -> V_22 = V_220 ;
V_21 -> V_23 = V_27 >> 2 ;
F_17 ( & V_21 -> V_202 ) ;
for ( V_17 = 0 ; V_27 > ( 1 << ( V_17 + 10 ) ) ; V_17 ++ ) ;
F_14 ( ( V_17 << V_229 ) |
( ( V_21 -> V_22 - V_12 -> V_141 ) >> ( V_146 + 2 ) ) ,
F_86 ( V_21 -> V_36 ) ) ;
V_21 -> V_173 = F_15 ( F_80 ( V_21 -> V_36 ) ) &
V_230 ;
}
error = F_82 ( V_12 , & V_221 , V_21 -> V_209 , & V_210 , & V_201 , V_211 ) ;
if ( ! error && V_217 -> V_231 > V_221 ) error = - V_232 ;
if ( ! error && V_217 -> V_233 && V_217 -> V_233 != V_234 &&
V_217 -> V_233 < V_221 ) error = - V_232 ;
if ( ! error && ! V_207 && V_221 > V_12 -> V_214 + V_21 -> V_209 )
error = - V_232 ;
if ( ! error && V_218 && ! V_219 && V_221 < V_21 -> V_228 )
error = - V_232 ;
if ( ! error && ! V_218 && V_221 > V_21 -> V_209 && ! V_207 )
error = - V_232 ;
if ( error ) {
if ( V_222 ) {
V_21 -> V_22 = NULL ;
F_12 ( V_12 , V_220 , V_27 ) ;
}
return error ;
}
V_217 -> V_208 = V_221 ;
if ( V_218 && ! V_207 ) {
V_12 -> V_214 += V_21 -> V_209 ;
V_21 -> V_209 = V_221 ;
V_12 -> V_214 -= V_221 ;
}
if ( V_219 || ( V_211 && V_222 ) ) {
if ( V_211 && V_222 ) V_12 -> V_207 = V_21 ;
V_21 -> V_188 = V_210 ;
V_21 -> V_190 = V_201 ;
V_21 -> V_228 = V_221 ;
}
if ( V_219 ) V_41 -> V_21 = V_21 ;
F_9 ( L_107 , V_21 -> V_209 , V_21 -> V_228 ) ;
return 0 ;
}
static int F_87 ( struct V_39 * V_40 )
{
F_7 ( V_40 ) -> V_21 = NULL ;
if ( V_40 -> V_117 . V_217 . V_119 == V_136 ) return 0 ;
F_7 ( V_40 ) -> V_197 = 0 ;
return F_84 ( V_40 , & V_40 -> V_117 . V_217 , 1 , 1 ) ;
}
static int F_88 ( struct V_39 * V_40 )
{
return 0 ;
}
static void F_89 ( struct V_39 * V_40 )
{
F_54 ( V_149 , V_150 ) ;
struct V_12 * V_12 ;
struct V_41 * V_41 ;
V_41 = F_7 ( V_40 ) ;
if ( ! V_41 -> V_21 ) return;
V_12 = F_6 ( V_40 -> V_19 ) ;
F_9 ( L_108 ) ;
F_56 ( & V_12 -> V_205 , & V_149 ) ;
F_57 ( V_156 ) ;
for (; ; ) {
int V_197 ;
F_59 ( & V_12 -> V_159 ) ;
V_197 = F_90 ( & V_41 -> V_21 -> V_202 ) || V_41 -> V_197 ;
F_60 ( & V_12 -> V_159 ) ;
if ( ! V_197 ) break;
F_9 ( L_109 , V_41 -> V_197 ) ;
F_58 () ;
F_57 ( V_156 ) ;
}
F_57 ( V_160 ) ;
F_61 ( & V_12 -> V_205 , & V_149 ) ;
if ( V_41 -> V_21 != V_12 -> V_207 ) {
while ( F_15 ( F_73 ( V_41 -> V_21 -> V_36 ) ) !=
F_15 ( F_80 ( V_41 -> V_21 -> V_36 ) ) )
F_58 () ;
F_12 ( V_12 , V_41 -> V_21 -> V_22 , V_41 -> V_21 -> V_23 << 2 ) ;
V_41 -> V_21 -> V_22 = NULL ;
V_12 -> V_214 += V_41 -> V_21 -> V_209 ;
}
V_41 -> V_21 = NULL ;
}
static int F_91 ( struct V_18 * V_19 )
{
struct V_12 * V_12 ;
int V_10 ;
V_12 = F_6 ( V_19 ) ;
V_12 -> V_235 = 0 ;
V_12 -> V_214 = V_224 ;
V_12 -> V_225 = V_236 ;
F_65 ( & V_12 -> V_205 ) ;
V_12 -> V_207 = NULL ;
F_17 ( & V_12 -> V_198 ) ;
F_14 ( 0 , V_176 ) ;
for ( V_10 = 0 ; V_10 < V_20 ; V_10 ++ ) {
V_12 -> V_21 [ V_10 ] . V_22 = NULL ;
V_12 -> V_21 [ V_10 ] . V_36 = V_10 ;
}
return 0 ;
}
static void F_92 ( struct V_18 * V_19 , unsigned long V_237 )
{
F_9 ( L_110 ) ;
if ( V_237 & V_238 )
F_3 (KERN_CRIT DEV_LABEL L_111
L_112 ,dev->number) ;
if ( V_237 & V_239 )
F_3 (KERN_CRIT DEV_LABEL L_113
L_18 ,dev->number) ;
if ( V_237 & V_240 )
F_3 (KERN_CRIT DEV_LABEL L_111
L_114 ,dev->number) ;
F_2 ( L_23 , 0 , 0 ) ;
F_3 ( V_11 L_24 ) ;
F_1 () ;
}
static T_4 F_93 ( int V_241 , void * V_242 )
{
struct V_18 * V_19 ;
struct V_12 * V_12 ;
T_2 V_237 ;
F_9 ( L_115 ) ;
V_19 = V_242 ;
V_12 = F_6 ( V_19 ) ;
V_237 = F_15 ( V_243 ) ;
F_9 ( V_90 L_116 , ( unsigned long ) V_237 ) ;
if ( V_237 & V_244 ) {
F_2 ( L_117 , 0 , 0 ) ;
V_12 -> V_235 += F_15 ( V_245 ) & V_246 ;
}
if ( V_237 & V_247 ) {
F_2 ( L_118 , 0 , 0 ) ;
V_19 -> V_248 -> V_249 ( V_19 ) ;
#if 0
foo();
#endif
}
F_94 ( & V_12 -> V_250 ) ;
V_12 -> V_251 |= V_237 ;
F_95 ( & V_12 -> V_250 ) ;
F_96 ( & V_12 -> V_159 ) ;
return V_252 ;
}
static void F_97 ( unsigned long V_67 )
{
struct V_18 * V_19 = (struct V_18 * ) V_67 ;
struct V_12 * V_12 = F_6 ( V_19 ) ;
unsigned long V_253 ;
T_2 V_251 ;
F_9 ( L_119 , V_19 ) ;
F_98 ( & V_12 -> V_250 , V_253 ) ;
V_251 = F_99 ( & V_12 -> V_251 , 0 ) ;
F_100 ( & V_12 -> V_250 , V_253 ) ;
if ( V_251 & V_254 ) {
F_2 ( L_120 , 0 , 0 ) ;
F_45 ( V_19 ) ;
F_2 ( L_121 , 0 , 0 ) ;
F_41 ( V_19 ) ;
F_2 ( L_122 , 0 , 0 ) ;
}
if ( V_251 & V_255 ) {
F_2 ( L_123 , 0 , 0 ) ;
F_43 ( V_19 ) ;
F_2 ( L_124 , 0 , 0 ) ;
F_41 ( V_19 ) ;
F_2 ( L_122 , 0 , 0 ) ;
}
if ( V_251 & V_256 ) {
F_2 ( L_125 , 0 , 0 ) ;
F_79 ( V_19 ) ;
}
if ( V_251 & V_257 ) {
F_2 ( L_126 , 0 , 0 ) ;
V_258 ++ ;
F_50 ( & V_12 -> V_205 ) ;
}
if ( V_251 & ( V_238 | V_239 | V_240 ) ) {
F_2 ( L_127 , 0 , 0 ) ;
F_92 ( V_19 , V_251 ) ;
}
F_78 ( V_19 ) ;
}
static int T_5 F_101 ( struct V_18 * V_19 )
{
struct V_12 * V_12 ;
unsigned char V_259 ;
int error , V_260 , V_261 ;
int V_262 , V_10 , V_65 ;
V_12 = F_6 ( V_19 ) ;
error = V_261 = 0 ;
V_259 = V_263 | V_264 | V_265 ;
V_266 ;
for ( V_10 = 0 ; V_10 < V_267 && ! error && ! V_261 ; V_10 ++ ) {
V_259 |= V_264 ;
V_266 ;
V_259 |= V_265 ;
V_266 ;
V_259 &= ~ V_264 ;
V_266 ;
V_259 &= ~ V_265 ;
V_266 ;
V_262 = ( ( V_10 + V_268 ) << 1 ) + 1 ;
for ( V_65 = 7 ; V_65 >= 0 ; V_65 -- ) {
V_259 = ( V_262 >> V_65 ) & 1 ? V_259 | V_264 :
V_259 & ~ V_264 ;
V_266 ;
V_259 |= V_265 ;
V_266 ;
V_259 &= ~ V_265 ;
V_266 ;
}
V_259 |= V_264 ;
V_266 ;
V_259 |= V_265 ;
V_266 ;
V_269 ;
V_260 = V_259 & V_264 ;
V_259 &= ~ V_265 ;
V_266 ;
V_259 |= V_264 ;
V_266 ;
if ( V_260 ) error = - V_270 ;
else {
V_19 -> V_271 [ V_10 ] = 0 ;
for ( V_65 = 7 ; V_65 >= 0 ; V_65 -- ) {
V_19 -> V_271 [ V_10 ] <<= 1 ;
V_259 |= V_264 ;
V_266 ;
V_259 |= V_265 ;
V_266 ;
V_269 ;
if ( V_259 & V_264 ) V_19 -> V_271 [ V_10 ] |= 1 ;
V_259 &= ~ V_265 ;
V_266 ;
V_259 |= V_264 ;
V_266 ;
}
V_259 |= V_264 ;
V_266 ;
V_259 |= V_265 ;
V_266 ;
V_269 ;
if ( ! ( V_259 & V_264 ) ) error = - V_270 ;
V_259 &= ~ V_265 ;
V_266 ;
V_259 |= V_264 ;
V_266 ;
}
V_259 &= ~ V_264 ;
V_266 ;
V_259 |= V_265 ;
V_266 ;
V_259 |= V_264 ;
V_266 ;
}
if ( V_261 ) {
F_3 (KERN_ERR DEV_LABEL L_128
L_129 ,dev->number,pci_error) ;
error = - V_270 ;
}
return error ;
}
static int T_5 F_102 ( struct V_18 * V_19 , void T_1 * V_272 )
{
void T_1 * V_273 ;
int V_10 ;
V_273 = V_272 + V_274 - sizeof( struct V_275 ) ;
for ( V_10 = 0 ; V_10 < V_267 ; V_10 ++ ) V_19 -> V_271 [ V_10 ] = F_103 ( V_273 + ( V_10 ^ 3 ) ) ;
return 0 ;
}
static int T_5 F_104 ( struct V_18 * V_19 )
{
struct V_275 T_1 * V_276 ;
struct V_12 * V_12 ;
struct V_66 * V_66 ;
unsigned long V_277 ;
void T_1 * V_272 ;
int error , V_10 , V_50 ;
F_9 ( L_130 ) ;
V_19 -> V_278 . V_279 = 0 ;
V_19 -> V_278 . V_280 = V_281 ;
V_19 -> V_282 = V_224 ;
V_12 = F_6 ( V_19 ) ;
V_66 = V_12 -> V_66 ;
V_277 = F_105 ( V_66 , 0 ) ;
V_12 -> V_241 = V_66 -> V_241 ;
if ( ( error = F_106 ( V_66 , V_283 ,
V_284 |
( V_12 -> V_285 ? V_286 | V_287 : 0 ) ) ) ) {
F_3 (KERN_ERR DEV_LABEL L_131
L_129 ,dev->number,error) ;
return - V_270 ;
}
F_3 (KERN_NOTICE DEV_LABEL L_132 ,
dev->number,pci_dev->revision,real_base,eni_dev->irq) ;
if ( ! ( V_272 = F_107 ( V_277 , V_288 ) ) ) {
F_3 ( L_133 ) ;
F_3 (KERN_ERR DEV_LABEL L_134
L_135 ,dev->number) ;
return error ;
}
V_12 -> V_31 = V_277 - ( unsigned long ) V_272 ;
if ( ! V_12 -> V_285 ) {
V_276 = ( V_272 + V_274 - sizeof( struct V_275 ) ) ;
if ( F_16 ( & V_276 -> V_289 ) != V_290 ) {
F_3 ( L_133 ) ;
F_3 (KERN_ERR DEV_LABEL
L_136 ,
dev->number, ENI155_MAGIC,
(unsigned)readl(&eprom->magic)) ;
error = - V_232 ;
goto V_291;
}
}
V_12 -> V_248 = V_272 + V_292 ;
V_12 -> V_293 = V_272 + V_294 ;
V_12 -> V_141 = V_272 + V_295 ;
V_50 = V_288 - V_295 ;
for ( V_10 = V_50 - V_296 ; V_10 >= 0 ; V_10 -= V_296 ) {
F_28 ( 0x55555555 , V_12 -> V_141 + V_10 ) ;
if ( F_16 ( V_12 -> V_141 + V_10 ) != 0x55555555 ) V_50 = V_10 ;
else {
F_28 ( 0xAAAAAAAA , V_12 -> V_141 + V_10 ) ;
if ( F_16 ( V_12 -> V_141 + V_10 ) != 0xAAAAAAAA ) V_50 = V_10 ;
else F_28 ( V_10 , V_12 -> V_141 + V_10 ) ;
}
}
for ( V_10 = 0 ; V_10 < V_50 ; V_10 += V_296 )
if ( F_16 ( V_12 -> V_141 + V_10 ) != V_10 ) break;
V_12 -> V_220 = V_10 ;
F_11 ( V_12 -> V_141 , 0 , V_12 -> V_220 ) ;
F_3 ( L_137 , V_12 -> V_220 >> 10 ) ;
if ( ! ( F_15 ( V_297 ) & 0x200 ) != ! V_12 -> V_285 ) {
F_3 ( L_138 ) ;
F_3 (KERN_ERR DEV_LABEL L_139 ,
dev->number,(unsigned) eni_in(MID_RES_ID_MCON)) ;
error = - V_232 ;
goto V_291;
}
error = V_12 -> V_285 ? F_101 ( V_19 ) : F_102 ( V_19 , V_272 ) ;
if ( error )
goto V_291;
for ( V_10 = 0 ; V_10 < V_267 ; V_10 ++ )
F_3 ( L_140 , V_10 ? L_141 : L_142 , V_19 -> V_271 [ V_10 ] ) ;
F_3 ( L_138 ) ;
F_3 (KERN_NOTICE DEV_LABEL L_143 ,dev->number,
eni_in(MID_RES_ID_MCON) & 0x200 ? L_144 : L_145 ,
media_name[eni_in(MID_RES_ID_MCON) & DAUGTHER_ID]) ;
error = F_108 ( V_19 ) ;
if ( error )
goto V_291;
V_298:
return error ;
V_291:
F_109 ( V_272 ) ;
goto V_298;
}
static int T_5 F_110 ( struct V_18 * V_19 )
{
struct V_12 * V_12 ;
void T_1 * V_299 ;
unsigned long V_300 ;
int error ;
F_9 ( L_146 ) ;
V_12 = F_6 ( V_19 ) ;
if ( F_111 ( V_12 -> V_241 , & F_93 , V_301 , V_90 , V_19 ) ) {
F_3 (KERN_ERR DEV_LABEL L_147 ,
dev->number,eni_dev->irq) ;
error = - V_302 ;
goto V_298;
}
F_112 ( V_12 -> V_66 ) ;
if ( ( error = F_106 ( V_12 -> V_66 , V_283 ,
V_284 | V_303 |
( V_12 -> V_285 ? V_286 | V_287 : 0 ) ) ) ) {
F_3 (KERN_ERR DEV_LABEL L_148
L_149 ,dev->number,error) ;
goto V_304;
}
if ( ( error = F_113 ( V_12 -> V_66 , V_305 ,
V_306 ) ) ) {
F_3 (KERN_ERR DEV_LABEL L_150
L_129 ,dev->number,error) ;
goto V_304;
}
V_12 -> V_46 = V_12 -> V_141 ;
V_12 -> V_83 = V_12 -> V_141 + V_307 * 16 ;
V_12 -> V_196 = V_12 -> V_83 + V_82 * 8 ;
V_12 -> V_115 = V_12 -> V_196 + V_180 * 8 ;
V_299 = V_12 -> V_115 + V_116 * 4 ;
F_9 ( L_151 ,
V_12 -> V_46 , V_12 -> V_83 , V_12 -> V_196 ,
V_12 -> V_115 , V_299 ) ;
F_114 ( & V_12 -> V_250 ) ;
F_115 ( & V_12 -> V_159 , F_97 , ( unsigned long ) V_19 ) ;
V_12 -> V_251 = 0 ;
V_300 = V_12 -> V_220 - ( V_299 - V_12 -> V_141 ) ;
V_12 -> V_32 = V_300 / V_34 / 2 ;
V_12 -> V_15 = F_116 (
sizeof( struct V_28 ) * ( V_12 -> V_32 + 1 ) , V_161 ) ;
if ( ! V_12 -> V_15 ) {
F_3 (KERN_ERR DEV_LABEL L_77 ,
dev->number) ;
error = - V_162 ;
goto V_304;
}
V_12 -> V_13 = 0 ;
F_8 ( V_12 , V_299 , V_300 ) ;
F_11 ( V_12 -> V_46 , 0 , 16 * V_307 ) ;
F_14 ( 0xffffffff , V_308 ) ;
error = F_91 ( V_19 ) ;
if ( error ) goto V_15;
error = F_62 ( V_19 ) ;
if ( error ) goto V_15;
error = V_19 -> V_248 -> V_16 ( V_19 ) ;
if ( error ) goto V_15;
F_14 ( F_15 ( V_42 ) | ( 1 << V_309 ) |
V_310 | V_43 | V_44 | V_45 ,
V_42 ) ;
( void ) F_15 ( V_243 ) ;
return 0 ;
V_15:
F_117 ( V_12 -> V_15 ) ;
V_304:
V_304 ( V_12 -> V_241 , V_12 ) ;
V_298:
return error ;
}
static void F_118 ( struct V_39 * V_40 )
{
F_9 ( L_152 ) ;
if ( ! F_7 ( V_40 ) ) return;
F_119 ( V_311 , & V_40 -> V_253 ) ;
F_53 ( V_40 ) ;
F_89 ( V_40 ) ;
F_9 ( L_153 ) ;
F_117 ( F_7 ( V_40 ) ) ;
V_40 -> V_312 = NULL ;
F_119 ( V_313 , & V_40 -> V_253 ) ;
}
static int F_120 ( struct V_39 * V_40 )
{
struct V_41 * V_41 ;
int error ;
short V_151 = V_40 -> V_151 ;
int V_46 = V_40 -> V_46 ;
F_9 ( L_154 ) ;
F_2 ( L_155 , 0 , 0 ) ;
if ( ! F_121 ( V_314 , & V_40 -> V_253 ) )
V_40 -> V_312 = NULL ;
if ( V_46 != V_152 && V_151 != V_153 )
F_122 ( V_313 , & V_40 -> V_253 ) ;
if ( V_40 -> V_117 . V_129 != V_130 && V_40 -> V_117 . V_129 != V_140 )
return - V_232 ;
F_9 ( V_90 L_156 , V_40 -> V_19 -> V_91 , V_40 -> V_151 ,
V_40 -> V_46 ) ;
if ( ! F_121 ( V_314 , & V_40 -> V_253 ) ) {
V_41 = F_116 ( sizeof( struct V_41 ) , V_161 ) ;
if ( ! V_41 ) return - V_162 ;
V_40 -> V_312 = V_41 ;
V_41 -> V_21 = NULL ;
if ( ( error = F_51 ( V_40 ) ) ) {
F_118 ( V_40 ) ;
return error ;
}
if ( ( error = F_87 ( V_40 ) ) ) {
F_118 ( V_40 ) ;
return error ;
}
}
if ( V_46 == V_152 || V_151 == V_153 ) return 0 ;
if ( ( error = F_52 ( V_40 ) ) ) {
F_118 ( V_40 ) ;
return error ;
}
if ( ( error = F_88 ( V_40 ) ) ) {
F_118 ( V_40 ) ;
return error ;
}
F_122 ( V_311 , & V_40 -> V_253 ) ;
return 0 ;
}
static int F_123 ( struct V_39 * V_40 , struct V_315 * V_117 , int V_316 )
{
struct V_12 * V_12 = F_6 ( V_40 -> V_19 ) ;
struct V_168 * V_21 = F_7 ( V_40 ) -> V_21 ;
struct V_55 * V_56 ;
int error , V_221 , V_317 , V_318 ;
if ( V_117 -> V_217 . V_119 == V_136 ) return 0 ;
if ( V_21 == V_12 -> V_207 ) return - V_319 ;
V_221 = F_85 ( & V_117 -> V_217 ) ;
if ( V_221 < 0 ) V_221 = - V_221 ;
V_317 = V_318 = 0 ;
if ( ( V_316 & V_320 ) && V_221 && V_221 < V_21 -> V_209 ) V_317 = 1 ;
if ( ( V_316 & V_321 ) && ( ! V_221 || V_221 > V_21 -> V_209 ) ) V_317 = 1 ;
if ( ( V_316 & V_322 ) && V_221 && V_221 < V_21 -> V_228 ) V_318 = 1 ;
if ( ( V_316 & V_323 ) && ( ! V_221 || V_221 > V_21 -> V_228 ) ) V_318 = 1 ;
if ( ! V_317 && ! V_318 ) return 0 ;
error = F_84 ( V_40 , & V_117 -> V_217 , V_317 , V_318 ) ;
if ( error ) return error ;
if ( V_318 && ! ( V_316 & V_324 ) ) return 0 ;
F_59 ( & V_12 -> V_159 ) ;
F_124 (&eni_dev->tx_queue, skb) {
void T_1 * V_325 ;
if ( F_22 ( V_56 ) -> V_40 != V_40 ) continue;
V_325 = V_21 -> V_22 + F_29 ( V_56 ) * 4 ;
F_28 ( ( F_16 ( V_325 ) & ~ ( V_326 | V_327 ) ) |
( V_21 -> V_188 << V_189 ) |
( V_21 -> V_190 << V_191 ) , V_325 ) ;
}
F_60 ( & V_12 -> V_159 ) ;
return 0 ;
}
static int F_125 ( struct V_18 * V_19 , unsigned int V_328 , void T_6 * V_329 )
{
struct V_12 * V_12 = F_6 ( V_19 ) ;
if ( V_328 == V_330 ) {
if ( ! F_126 ( V_331 ) ) return - V_332 ;
F_3 ( V_333 L_157 V_90 L_158
L_159 , V_19 -> V_91 ) ;
F_5 ( V_19 ) ;
return 0 ;
}
if ( V_328 == V_334 ) {
struct V_335 V_336 ;
if ( ! F_126 ( V_331 ) ) return - V_332 ;
if ( F_127 ( & V_336 , V_329 ,
sizeof( struct V_335 ) ) )
return - V_337 ;
if ( ( V_336 . V_21 && V_336 . V_21 <= 100 ) || ( V_336 . V_25 && V_336 . V_25 <= 100 ) ||
V_336 . V_21 > 65536 || V_336 . V_25 > 65536 )
return - V_232 ;
if ( V_336 . V_21 ) V_12 -> V_225 = V_336 . V_21 ;
if ( V_336 . V_25 ) V_12 -> V_138 = V_336 . V_25 ;
return 0 ;
}
if ( V_328 == V_338 ) {
struct V_339 V_340 ;
if ( F_127 ( & V_340 , V_329 , sizeof( struct V_339 ) ) )
return - V_337 ;
if ( ( V_340 . V_279 == 0 || V_340 . V_279 == V_341 ) &&
( V_340 . V_280 == V_281 || V_340 . V_279 == V_341 ) )
return 0 ;
return - V_232 ;
}
if ( ! V_19 -> V_248 -> V_342 ) return - V_343 ;
return V_19 -> V_248 -> V_342 ( V_19 , V_328 , V_329 ) ;
}
static int F_128 ( struct V_39 * V_40 , int V_344 , int V_345 ,
void T_6 * V_346 , int V_347 )
{
return - V_232 ;
}
static int F_129 ( struct V_39 * V_40 , int V_344 , int V_345 ,
void T_6 * V_346 , unsigned int V_347 )
{
return - V_232 ;
}
static int F_130 ( struct V_39 * V_40 , struct V_55 * V_56 )
{
enum V_167 V_201 ;
F_9 ( L_160 ) ;
if ( ! F_7 ( V_40 ) -> V_21 ) {
if ( V_40 -> V_204 ) V_40 -> V_204 ( V_40 , V_56 ) ;
else F_131 ( V_56 ) ;
return - V_232 ;
}
if ( ! V_56 ) {
F_3 ( V_33 L_161 ) ;
if ( V_40 -> V_204 ) V_40 -> V_204 ( V_40 , V_56 ) ;
return - V_232 ;
}
if ( V_40 -> V_117 . V_129 == V_130 ) {
if ( V_56 -> V_30 != V_94 - 1 ) {
if ( V_40 -> V_204 ) V_40 -> V_204 ( V_40 , V_56 ) ;
else F_131 ( V_56 ) ;
return - V_232 ;
}
* ( T_2 * ) V_56 -> V_67 = F_132 ( * ( T_2 * ) V_56 -> V_67 ) ;
}
V_348 ++ ;
F_22 ( V_56 ) -> V_40 = V_40 ;
F_59 ( & F_6 ( V_40 -> V_19 ) -> V_159 ) ;
V_201 = F_71 ( V_56 ) ;
F_60 ( & F_6 ( V_40 -> V_19 ) -> V_159 ) ;
if ( V_201 == V_200 ) return 0 ;
F_30 ( & F_7 ( V_40 ) -> V_21 -> V_202 , V_56 ) ;
V_349 ++ ;
F_96 ( & F_6 ( V_40 -> V_19 ) -> V_159 ) ;
return 0 ;
}
static void F_133 ( struct V_18 * V_19 , unsigned char V_350 ,
unsigned long V_351 )
{
F_28 ( V_350 , F_6 ( V_19 ) -> V_248 + V_351 * 4 ) ;
}
static unsigned char F_134 ( struct V_18 * V_19 , unsigned long V_351 )
{
return F_16 ( F_6 ( V_19 ) -> V_248 + V_351 * 4 ) ;
}
static int F_135 ( struct V_18 * V_19 , T_7 * V_352 , char * V_353 )
{
struct V_354 * V_355 ;
struct V_356 * V_1 ;
static const char * signal [] = { L_162 , L_163 , L_164 } ;
struct V_12 * V_12 = F_6 ( V_19 ) ;
struct V_39 * V_40 ;
int V_357 , V_10 ;
V_357 = * V_352 ;
if ( ! V_357 )
return sprintf ( V_353 , V_90 L_165
L_166 , V_19 -> V_91 , signal [ ( int ) V_19 -> signal ] ,
V_12 -> V_220 >> 10 , V_12 -> V_214 ) ;
if ( ! -- V_357 )
return sprintf ( V_353 , L_167
#if ! F_136 ( F_67 ) && \
! F_136 ( F_68 ) && \
! F_136 ( F_69 ) && \
! F_136 ( F_70 )
L_168
#endif
#ifdef F_67
L_169
#endif
#ifdef F_68
L_170
#endif
#ifdef F_69
L_171
#endif
#ifdef F_70
L_172
#endif
L_173
#if ! F_136 ( F_23 ) && \
! F_136 ( F_24 ) && \
! F_136 ( F_25 ) && \
! F_136 ( F_26 )
L_168
#endif
#ifdef F_23
L_169
#endif
#ifdef F_24
L_170
#endif
#ifdef F_25
L_171
#endif
#ifdef F_26
L_172
#endif
#ifndef F_137
L_174
#endif
L_133 , L_142 ) ;
if ( ! -- V_357 )
return sprintf ( V_353 , L_175 ,
L_142 , V_12 -> V_225 , V_12 -> V_138 ) ;
for ( V_10 = 0 ; V_10 < V_20 ; V_10 ++ ) {
struct V_168 * V_21 = V_12 -> V_21 + V_10 ;
if ( ! V_21 -> V_22 ) continue;
if ( ! -- V_357 ) {
return sprintf ( V_353 , L_176
L_177 , V_10 ,
( unsigned long ) ( V_21 -> V_22 - V_12 -> V_141 ) ,
V_21 -> V_22 - V_12 -> V_141 + V_21 -> V_23 * 4 - 1 , V_21 -> V_23 * 4 ,
V_21 -> V_209 , V_21 -> V_228 ,
V_21 == V_12 -> V_207 ? L_178 : L_142 ) ;
}
if ( -- V_357 ) continue;
return sprintf ( V_353 , L_179 , L_142 ,
F_138 ( & V_21 -> V_202 ) ) ;
}
F_139 ( & V_358 ) ;
for( V_10 = 0 ; V_10 < V_359 ; ++ V_10 ) {
struct V_360 * V_361 = & V_362 [ V_10 ] ;
F_140 (s, node, head) {
struct V_41 * V_41 ;
int V_85 ;
V_40 = F_141 ( V_1 ) ;
if ( V_40 -> V_19 != V_19 )
continue;
V_41 = F_7 ( V_40 ) ;
if ( -- V_357 ) continue;
V_85 = sprintf ( V_353 , L_180 , V_40 -> V_46 ) ;
if ( V_41 -> V_25 ) {
V_85 += sprintf ( V_353 + V_85 , L_181
L_182 ,
( unsigned long ) ( V_41 -> V_26 - V_12 -> V_141 ) ,
V_41 -> V_26 - V_12 -> V_141 + V_41 -> V_23 * 4 - 1 ,
V_41 -> V_23 * 4 ) ;
if ( V_41 -> V_21 ) V_85 += sprintf ( V_353 + V_85 , L_183 ) ;
}
if ( V_41 -> V_21 )
V_85 += sprintf ( V_353 + V_85 , L_184 ,
V_41 -> V_21 -> V_36 , V_41 -> V_197 ) ;
V_353 [ V_85 ] = '\n' ;
F_142 ( & V_358 ) ;
return V_85 + 1 ;
}
}
F_142 ( & V_358 ) ;
for ( V_10 = 0 ; V_10 < V_12 -> V_13 ; V_10 ++ ) {
struct V_28 * V_363 = V_12 -> V_15 + V_10 ;
unsigned long V_364 ;
if ( -- V_357 ) continue;
V_364 = ( unsigned long ) V_12 -> V_141 + V_12 -> V_31 ;
return sprintf ( V_353 , L_185 ,
V_363 -> V_16 - V_364 , V_363 -> V_16 - V_364 + ( 1 << V_363 -> V_17 ) - 1 ,
1 << V_363 -> V_17 ) ;
}
return 0 ;
}
static int T_5 F_143 ( struct V_66 * V_66 ,
const struct V_365 * V_366 )
{
struct V_18 * V_19 ;
struct V_12 * V_12 ;
int error = - V_162 ;
F_9 ( L_186 ) ;
if ( F_144 ( V_66 ) ) {
error = - V_270 ;
goto V_367;
}
V_12 = F_116 ( sizeof( struct V_12 ) , V_161 ) ;
if ( ! V_12 ) goto V_367;
if ( ! V_368 ) {
V_368 = F_145 ( V_66 , V_369 ,
& V_184 ) ;
if ( ! V_368 ) goto V_370;
}
V_19 = F_146 ( V_90 , & V_66 -> V_19 , & V_371 , - 1 , NULL ) ;
if ( ! V_19 ) goto V_372;
F_147 ( V_66 , V_19 ) ;
V_12 -> V_66 = V_66 ;
V_19 -> V_312 = V_12 ;
V_12 -> V_285 = V_366 -> V_373 ;
error = F_104 ( V_19 ) ;
if ( error ) goto V_374;
error = F_110 ( V_19 ) ;
if ( error ) goto V_374;
V_12 -> V_375 = V_376 ;
V_376 = V_19 ;
return 0 ;
V_374:
F_148 ( V_19 ) ;
V_372:
F_149 ( V_12 -> V_66 , V_369 , V_368 , V_184 ) ;
V_368 = NULL ;
V_370:
F_117 ( V_12 ) ;
V_367:
return error ;
}
static void T_8 F_150 ( struct V_66 * V_66 )
{
}
static int T_9 F_151 ( void )
{
struct V_55 * V_56 ;
if ( sizeof( V_56 -> V_131 ) < sizeof( struct V_132 ) ) {
F_3 ( V_377 L_187 ,
sizeof( V_56 -> V_131 ) , sizeof( struct V_132 ) ) ;
return - V_270 ;
}
return F_152 ( & V_378 ) ;
}
