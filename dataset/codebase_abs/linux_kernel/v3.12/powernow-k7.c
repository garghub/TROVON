static int F_1 ( unsigned int V_1 )
{
int V_2 ;
unsigned int V_3 = V_4 / 1000 ;
V_2 = ( V_1 > V_3 ) ? V_1 - V_3 : V_3 - V_1 ;
return V_2 < 5 ;
}
static int F_2 ( void )
{
struct V_5 * V_6 = & F_3 ( 0 ) ;
unsigned int V_7 , V_8 , V_9 , V_10 , V_11 ;
if ( ! F_4 ( V_12 ) )
return 0 ;
V_7 = F_5 ( 0x80000000 ) ;
if ( V_7 < 0x80000007 ) {
#ifdef F_6
F_7 (KERN_INFO PFX L_1 ) ;
#endif
return 0 ;
}
if ( ( V_6 -> V_13 == 6 ) && ( V_6 -> V_14 == 0 ) ) {
F_7 (KERN_INFO PFX L_2
L_3 ) ;
V_15 = 1 ;
}
F_8 ( 0x80000007 , & V_8 , & V_9 , & V_10 , & V_11 ) ;
if ( ! ( V_11 & ( 1 << 1 | 1 << 2 ) ) )
return 0 ;
F_7 (KERN_INFO PFX L_4 ) ;
if ( V_11 & 1 << 1 ) {
F_7 ( L_5 ) ;
V_16 = 1 ;
}
if ( ( V_11 & ( 1 << 1 | 1 << 2 ) ) == 0x6 )
F_7 ( L_6 ) ;
if ( V_11 & 1 << 2 ) {
F_7 ( L_7 ) ;
V_17 = 1 ;
}
F_7 ( L_8 ) ;
return 1 ;
}
static void F_9 ( unsigned int V_18 )
{
V_19 [ V_18 ] . V_20 = V_21 ;
}
static int F_10 ( unsigned char * V_22 )
{
unsigned int V_23 ;
unsigned int V_24 ;
T_1 V_25 , V_26 ;
V_19 = F_11 ( ( sizeof( * V_19 ) *
( V_27 + 1 ) ) , V_28 ) ;
if ( ! V_19 )
return - V_29 ;
for ( V_23 = 0 ; V_23 < V_27 ; V_23 ++ ) {
V_25 = * V_22 ++ ;
V_19 [ V_23 ] . V_20 = ( V_4 * V_30 [ V_25 ] ) / 10 ;
V_19 [ V_23 ] . V_31 = V_25 ;
V_24 = V_19 [ V_23 ] . V_20 ;
if ( ( V_30 [ V_25 ] % 10 ) == 5 ) {
#ifdef F_12
if ( V_15 == 1 )
F_9 ( V_23 ) ;
#endif
}
if ( V_24 < V_32 )
V_32 = V_24 ;
if ( V_24 > V_33 )
V_33 = V_24 ;
V_26 = * V_22 ++ ;
V_19 [ V_23 ] . V_31 |= ( V_26 << 8 ) ;
F_13 ( L_9
L_10 , V_25 , V_30 [ V_25 ] / 10 ,
V_30 [ V_25 ] % 10 , V_24 / 1000 , V_26 ,
V_34 [ V_26 ] / 1000 ,
V_34 [ V_26 ] % 1000 ) ;
}
V_19 [ V_27 ] . V_20 = V_35 ;
V_19 [ V_27 ] . V_31 = 0 ;
return 0 ;
}
static void F_14 ( int V_25 )
{
union V_36 V_37 ;
F_15 ( V_38 , V_37 . V_39 ) ;
if ( V_37 . V_40 . V_41 != V_25 ) {
V_37 . V_40 . V_42 = V_43 ;
V_37 . V_40 . V_41 = V_25 ;
V_37 . V_40 . V_44 = 0 ;
V_37 . V_40 . V_45 = 1 ;
F_16 ( V_38 , V_37 . V_39 ) ;
}
}
static void F_17 ( int V_26 )
{
union V_36 V_37 ;
F_15 ( V_38 , V_37 . V_39 ) ;
if ( V_37 . V_40 . V_46 != V_26 ) {
V_37 . V_40 . V_42 = V_43 ;
V_37 . V_40 . V_46 = V_26 ;
V_37 . V_40 . V_45 = 0 ;
V_37 . V_40 . V_44 = 1 ;
F_16 ( V_38 , V_37 . V_39 ) ;
}
}
static void F_18 ( struct V_47 * V_48 , unsigned int V_49 )
{
T_1 V_25 , V_26 ;
struct V_50 V_51 ;
union V_52 V_53 ;
int V_54 ;
V_25 = V_19 [ V_49 ] . V_31 & 0xFF ;
V_26 = ( V_19 [ V_49 ] . V_31 & 0xFF00 ) >> 8 ;
F_15 ( V_55 , V_53 . V_39 ) ;
V_54 = V_53 . V_40 . V_56 ;
V_51 . V_57 = V_4 * V_30 [ V_54 ] / 10 ;
V_51 . V_58 = V_19 [ V_49 ] . V_20 ;
F_19 ( V_48 , & V_51 , V_59 ) ;
if ( V_15 == 1 )
F_20 () ;
if ( V_51 . V_57 > V_51 . V_58 ) {
F_14 ( V_25 ) ;
F_17 ( V_26 ) ;
} else {
F_17 ( V_26 ) ;
F_14 ( V_25 ) ;
}
if ( V_15 == 1 )
F_21 () ;
F_19 ( V_48 , & V_51 , V_60 ) ;
}
static int F_22 ( void )
{
int V_61 ;
int V_62 = 0 ;
union V_63 V_64 ;
if ( V_65 != NULL && V_19 != NULL ) {
V_62 = - V_66 ;
goto V_67;
}
V_65 = F_11 ( sizeof( * V_65 ) , V_28 ) ;
if ( ! V_65 ) {
V_62 = - V_29 ;
goto V_67;
}
if ( ! F_23 ( & V_65 -> V_68 ,
V_28 ) ) {
V_62 = - V_29 ;
goto V_69;
}
if ( F_24 ( V_65 , 0 ) ) {
V_62 = - V_70 ;
goto V_71;
}
if ( V_65 -> V_72 . V_73 !=
V_74 ) {
V_62 = - V_75 ;
goto V_76;
}
if ( V_65 -> V_77 . V_73 !=
V_74 ) {
V_62 = - V_75 ;
goto V_76;
}
V_27 = V_65 -> V_78 ;
if ( V_27 < 2 ) {
V_62 = - V_75 ;
goto V_76;
}
V_19 = F_11 ( ( sizeof( * V_19 ) *
( V_27 + 1 ) ) , V_28 ) ;
if ( ! V_19 ) {
V_62 = - V_29 ;
goto V_76;
}
V_64 . V_39 = ( unsigned long ) V_65 -> V_79 [ 0 ] . V_80 ;
for ( V_61 = 0 ; V_61 < V_27 ; V_61 ++ ) {
T_1 V_25 , V_26 ;
struct V_81 * V_82 =
& V_65 -> V_79 [ V_61 ] ;
unsigned int V_24 , V_83 ;
V_64 . V_39 = ( unsigned long ) V_82 -> V_80 ;
F_13 ( L_11 ,
V_61 ,
( V_84 ) V_82 -> V_85 ,
( V_84 ) V_82 -> V_86 ,
( V_84 ) V_82 -> V_87 ,
( V_84 ) V_82 -> V_80 ,
V_64 . V_40 . V_88 ) ;
V_26 = V_64 . V_40 . V_26 ;
V_25 = V_64 . V_40 . V_25 ;
V_19 [ V_61 ] . V_20 = V_4 * V_30 [ V_25 ] / 10 ;
V_19 [ V_61 ] . V_31 = V_25 ;
V_19 [ V_61 ] . V_31 |= ( V_26 << 8 ) ;
V_24 = V_19 [ V_61 ] . V_20 ;
V_83 = V_24 / 1000 ;
if ( V_24 % 1000 > 0 )
V_83 ++ ;
if ( ( V_30 [ V_25 ] % 10 ) == 5 ) {
if ( V_15 == 1 )
F_9 ( V_61 ) ;
}
F_13 ( L_9
L_10 , V_25 , V_30 [ V_25 ] / 10 ,
V_30 [ V_25 ] % 10 , V_83 , V_26 ,
V_34 [ V_26 ] / 1000 ,
V_34 [ V_26 ] % 1000 ) ;
if ( V_82 -> V_85 != V_83 ) {
V_82 -> V_85 = V_83 ;
F_13 ( L_12 ,
V_83 ) ;
}
if ( V_43 < V_64 . V_40 . V_88 )
V_43 = V_64 . V_40 . V_88 ;
if ( V_24 < V_32 )
V_32 = V_24 ;
if ( V_24 > V_33 )
V_33 = V_24 ;
}
V_19 [ V_61 ] . V_20 = V_35 ;
V_19 [ V_61 ] . V_31 = 0 ;
F_25 ( V_89 ) ;
return 0 ;
V_76:
F_26 ( V_65 , 0 ) ;
V_71:
F_27 ( V_65 -> V_68 ) ;
V_69:
F_28 ( V_65 ) ;
V_67:
F_7 (KERN_WARNING PFX L_13
L_14 ) ;
V_65 = NULL ;
return V_62 ;
}
static int F_22 ( void )
{
F_7 (KERN_INFO PFX L_15
L_16 ) ;
return - V_66 ;
}
static void F_29 ( struct V_90 * V_22 , unsigned int V_23 )
{
F_13 ( L_17 , V_23 , V_22 ) ;
F_13 ( L_18 ,
V_22 -> F_8 , V_22 -> V_1 , V_22 -> V_91 , V_22 -> V_92 ) ;
}
static int F_30 ( int V_91 , int V_92 )
{
struct V_93 * V_94 ;
struct V_90 * V_22 ;
unsigned int V_61 , V_23 ;
unsigned char * V_95 ;
unsigned int V_96 ;
unsigned int V_97 ;
V_96 = F_5 ( 0x80000001 ) ;
for ( V_61 = 0xC0000 ; V_61 < 0xffff0 ; V_61 += 16 ) {
V_95 = F_31 ( V_61 ) ;
if ( memcmp ( V_95 , L_19 , 10 ) == 0 ) {
F_13 ( L_20 , V_95 ) ;
V_94 = (struct V_93 * ) V_95 ;
F_13 ( L_21 , V_94 -> V_98 ) ;
if ( V_94 -> V_98 != 0x12 ) {
F_7 (KERN_INFO PFX L_22
L_23 ) ;
return - V_75 ;
}
F_13 ( L_24 , V_94 -> V_99 ) ;
if ( ( V_94 -> V_99 & 1 ) == 0 )
F_13 ( L_25 ) ;
else
F_13 ( L_26 ) ;
V_43 = V_94 -> V_100 ;
if ( V_43 < 100 ) {
F_7 (KERN_INFO PFX L_27
L_28
L_29
L_30 , latency) ;
V_43 = 100 ;
}
F_13 ( L_31 ,
V_94 -> V_100 ) ;
F_13 ( L_32
L_33 ,
V_94 -> V_101 ) ;
V_95 += sizeof( * V_94 ) ;
V_22 = (struct V_90 * ) V_95 ;
for ( V_23 = 0 ; V_23 < V_94 -> V_101 ; V_23 ++ ) {
V_22 = (struct V_90 * ) V_95 ;
V_27 = V_22 -> V_102 ;
if ( ( V_96 == V_22 -> F_8 ) &&
F_1 ( V_22 -> V_1 ) &&
( V_91 == V_22 -> V_91 ) &&
( V_92 == V_22 -> V_92 ) ) {
F_29 ( V_22 , V_23 ) ;
V_95 = ( char * ) V_22 + sizeof( * V_22 ) ;
V_97 = F_10 ( V_95 ) ;
return V_97 ;
} else {
unsigned int V_103 ;
V_95 = ( char * ) V_22 + sizeof( * V_22 ) ;
for ( V_103 = 0 ; V_103 < V_27 ; V_103 ++ )
V_95 += 2 ;
}
}
F_7 (KERN_INFO PFX L_34
L_35 , etuple) ;
F_7 (KERN_INFO PFX L_36
L_37 ) ;
return - V_66 ;
}
V_95 ++ ;
}
return - V_75 ;
}
static int F_32 ( struct V_47 * V_48 ,
unsigned int V_104 ,
unsigned int V_105 )
{
unsigned int V_106 ;
if ( F_33 ( V_48 , V_19 , V_104 ,
V_105 , & V_106 ) )
return - V_66 ;
F_18 ( V_48 , V_106 ) ;
return 0 ;
}
static int F_34 ( struct V_47 * V_48 )
{
return F_35 ( V_48 , V_19 ) ;
}
static int F_36 ( void )
{
unsigned int V_88 ;
unsigned int V_107 ;
V_107 = V_4 / 3333 ;
if ( ( V_107 % 10 ) >= 5 )
V_107 += 5 ;
V_107 /= 10 ;
V_88 = 100 * V_107 * V_43 ;
V_88 = V_88 / 3 ;
if ( V_88 > 0xfffff ) {
F_7 (KERN_WARNING PFX L_38 , sgtc) ;
V_88 = 0xfffff ;
}
return V_88 ;
}
static unsigned int F_37 ( unsigned int V_108 )
{
union V_52 V_53 ;
unsigned int V_54 ;
if ( V_108 )
return 0 ;
F_15 ( V_55 , V_53 . V_39 ) ;
V_54 = V_53 . V_40 . V_56 ;
return V_4 * V_30 [ V_54 ] / 10 ;
}
static int F_38 ( const struct V_109 * V_110 )
{
F_7 (KERN_WARNING PFX
L_39 ,
d->ident) ;
F_7 (KERN_WARNING PFX
L_40
L_41 ) ;
F_7 (KERN_WARNING PFX
L_42 ) ;
return 0 ;
}
static int F_39 ( struct V_47 * V_48 )
{
union V_52 V_53 ;
int V_111 ;
if ( V_48 -> V_108 != 0 )
return - V_75 ;
F_15 ( V_55 , V_53 . V_39 ) ;
F_40 () ;
V_4 = ( 10 * V_112 ) / V_30 [ V_53 . V_40 . V_56 ] ;
if ( ! V_4 ) {
F_7 (KERN_WARNING PFX L_43 ) ;
return - V_66 ;
}
F_13 ( L_44 , V_4 / 1000 ) ;
if ( F_41 ( V_113 ) || V_114 ) {
F_7 (KERN_INFO PFX L_45
L_46 ) ;
V_111 = F_22 () ;
} else {
V_111 = F_30 ( V_53 . V_40 . V_115 ,
V_53 . V_40 . V_116 ) ;
if ( V_111 ) {
F_7 (KERN_INFO PFX L_47 ) ;
V_33 = 0 ;
V_32 = - 1 ;
V_43 = 0 ;
V_111 = F_22 () ;
if ( V_111 ) {
F_7 (KERN_INFO PFX
L_48 ) ;
}
} else {
V_43 = F_36 () ;
F_7 (KERN_INFO PFX L_49 , latency) ;
}
}
if ( V_111 )
return V_111 ;
F_7 (KERN_INFO PFX L_50 ,
minimum_speed/1000 , maximum_speed/1000 ) ;
V_48 -> V_117 . V_87 =
F_42 ( 2000000UL , V_4 , V_43 ) ;
V_48 -> V_118 = F_37 ( 0 ) ;
F_43 ( V_19 , V_48 -> V_108 ) ;
return F_44 ( V_48 , V_19 ) ;
}
static int F_45 ( struct V_47 * V_48 )
{
F_46 ( V_48 -> V_108 ) ;
#ifdef F_12
if ( V_65 ) {
F_26 ( V_65 , 0 ) ;
F_27 ( V_65 -> V_68 ) ;
F_28 ( V_65 ) ;
}
#endif
F_28 ( V_19 ) ;
return 0 ;
}
static int T_2 F_47 ( void )
{
if ( F_2 () == 0 )
return - V_75 ;
return F_48 ( & V_119 ) ;
}
static void T_3 F_49 ( void )
{
F_50 ( & V_119 ) ;
}
