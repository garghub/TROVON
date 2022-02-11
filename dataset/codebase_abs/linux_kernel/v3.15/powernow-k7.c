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
static int F_18 ( struct V_47 * V_48 , unsigned int V_49 )
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
if ( V_15 == 1 )
F_19 () ;
if ( V_51 . V_57 > V_51 . V_58 ) {
F_14 ( V_25 ) ;
F_17 ( V_26 ) ;
} else {
F_17 ( V_26 ) ;
F_14 ( V_25 ) ;
}
if ( V_15 == 1 )
F_20 () ;
return 0 ;
}
static int F_21 ( void )
{
int V_59 ;
int V_60 = 0 ;
union V_61 V_62 ;
if ( V_63 != NULL && V_19 != NULL ) {
V_60 = - V_64 ;
goto V_65;
}
V_63 = F_11 ( sizeof( * V_63 ) , V_28 ) ;
if ( ! V_63 ) {
V_60 = - V_29 ;
goto V_65;
}
if ( ! F_22 ( & V_63 -> V_66 ,
V_28 ) ) {
V_60 = - V_29 ;
goto V_67;
}
if ( F_23 ( V_63 , 0 ) ) {
V_60 = - V_68 ;
goto V_69;
}
if ( V_63 -> V_70 . V_71 !=
V_72 ) {
V_60 = - V_73 ;
goto V_74;
}
if ( V_63 -> V_75 . V_71 !=
V_72 ) {
V_60 = - V_73 ;
goto V_74;
}
V_27 = V_63 -> V_76 ;
if ( V_27 < 2 ) {
V_60 = - V_73 ;
goto V_74;
}
V_19 = F_11 ( ( sizeof( * V_19 ) *
( V_27 + 1 ) ) , V_28 ) ;
if ( ! V_19 ) {
V_60 = - V_29 ;
goto V_74;
}
V_62 . V_39 = ( unsigned long ) V_63 -> V_77 [ 0 ] . V_78 ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
T_1 V_25 , V_26 ;
struct V_79 * V_80 =
& V_63 -> V_77 [ V_59 ] ;
unsigned int V_24 , V_81 ;
V_62 . V_39 = ( unsigned long ) V_80 -> V_78 ;
F_13 ( L_11 ,
V_59 ,
( V_82 ) V_80 -> V_83 ,
( V_82 ) V_80 -> V_84 ,
( V_82 ) V_80 -> V_85 ,
( V_82 ) V_80 -> V_78 ,
V_62 . V_40 . V_86 ) ;
V_26 = V_62 . V_40 . V_26 ;
V_25 = V_62 . V_40 . V_25 ;
V_19 [ V_59 ] . V_20 = V_4 * V_30 [ V_25 ] / 10 ;
V_19 [ V_59 ] . V_31 = V_25 ;
V_19 [ V_59 ] . V_31 |= ( V_26 << 8 ) ;
V_24 = V_19 [ V_59 ] . V_20 ;
V_81 = V_24 / 1000 ;
if ( V_24 % 1000 > 0 )
V_81 ++ ;
if ( ( V_30 [ V_25 ] % 10 ) == 5 ) {
if ( V_15 == 1 )
F_9 ( V_59 ) ;
}
F_13 ( L_9
L_10 , V_25 , V_30 [ V_25 ] / 10 ,
V_30 [ V_25 ] % 10 , V_81 , V_26 ,
V_34 [ V_26 ] / 1000 ,
V_34 [ V_26 ] % 1000 ) ;
if ( V_80 -> V_83 != V_81 ) {
V_80 -> V_83 = V_81 ;
F_13 ( L_12 ,
V_81 ) ;
}
if ( V_43 < V_62 . V_40 . V_86 )
V_43 = V_62 . V_40 . V_86 ;
if ( V_24 < V_32 )
V_32 = V_24 ;
if ( V_24 > V_33 )
V_33 = V_24 ;
}
V_19 [ V_59 ] . V_20 = V_35 ;
V_19 [ V_59 ] . V_31 = 0 ;
F_24 ( V_87 ) ;
return 0 ;
V_74:
F_25 ( V_63 , 0 ) ;
V_69:
F_26 ( V_63 -> V_66 ) ;
V_67:
F_27 ( V_63 ) ;
V_65:
F_7 (KERN_WARNING PFX L_13
L_14 ) ;
V_63 = NULL ;
return V_60 ;
}
static int F_21 ( void )
{
F_7 (KERN_INFO PFX L_15
L_16 ) ;
return - V_64 ;
}
static void F_28 ( struct V_88 * V_22 , unsigned int V_23 )
{
F_13 ( L_17 , V_23 , V_22 ) ;
F_13 ( L_18 ,
V_22 -> F_8 , V_22 -> V_1 , V_22 -> V_89 , V_22 -> V_90 ) ;
}
static int F_29 ( int V_89 , int V_90 )
{
struct V_91 * V_92 ;
struct V_88 * V_22 ;
unsigned int V_59 , V_23 ;
unsigned char * V_93 ;
unsigned int V_94 ;
unsigned int V_95 ;
V_94 = F_5 ( 0x80000001 ) ;
for ( V_59 = 0xC0000 ; V_59 < 0xffff0 ; V_59 += 16 ) {
V_93 = F_30 ( V_59 ) ;
if ( memcmp ( V_93 , L_19 , 10 ) == 0 ) {
F_13 ( L_20 , V_93 ) ;
V_92 = (struct V_91 * ) V_93 ;
F_13 ( L_21 , V_92 -> V_96 ) ;
if ( V_92 -> V_96 != 0x12 ) {
F_7 (KERN_INFO PFX L_22
L_23 ) ;
return - V_73 ;
}
F_13 ( L_24 , V_92 -> V_97 ) ;
if ( ( V_92 -> V_97 & 1 ) == 0 )
F_13 ( L_25 ) ;
else
F_13 ( L_26 ) ;
V_43 = V_92 -> V_98 ;
if ( V_43 < 100 ) {
F_7 (KERN_INFO PFX L_27
L_28
L_29
L_30 , latency) ;
V_43 = 100 ;
}
F_13 ( L_31 ,
V_92 -> V_98 ) ;
F_13 ( L_32
L_33 ,
V_92 -> V_99 ) ;
V_93 += sizeof( * V_92 ) ;
V_22 = (struct V_88 * ) V_93 ;
for ( V_23 = 0 ; V_23 < V_92 -> V_99 ; V_23 ++ ) {
V_22 = (struct V_88 * ) V_93 ;
V_27 = V_22 -> V_100 ;
if ( ( V_94 == V_22 -> F_8 ) &&
F_1 ( V_22 -> V_1 ) &&
( V_89 == V_22 -> V_89 ) &&
( V_90 == V_22 -> V_90 ) ) {
F_28 ( V_22 , V_23 ) ;
V_93 = ( char * ) V_22 + sizeof( * V_22 ) ;
V_95 = F_10 ( V_93 ) ;
return V_95 ;
} else {
unsigned int V_101 ;
V_93 = ( char * ) V_22 + sizeof( * V_22 ) ;
for ( V_101 = 0 ; V_101 < V_27 ; V_101 ++ )
V_93 += 2 ;
}
}
F_7 (KERN_INFO PFX L_34
L_35 , etuple) ;
F_7 (KERN_INFO PFX L_36
L_37 ) ;
return - V_64 ;
}
V_93 ++ ;
}
return - V_73 ;
}
static int F_31 ( void )
{
unsigned int V_86 ;
unsigned int V_102 ;
V_102 = V_4 / 3333 ;
if ( ( V_102 % 10 ) >= 5 )
V_102 += 5 ;
V_102 /= 10 ;
V_86 = 100 * V_102 * V_43 ;
V_86 = V_86 / 3 ;
if ( V_86 > 0xfffff ) {
F_7 (KERN_WARNING PFX L_38 , sgtc) ;
V_86 = 0xfffff ;
}
return V_86 ;
}
static unsigned int F_32 ( unsigned int V_103 )
{
union V_52 V_53 ;
unsigned int V_54 ;
if ( V_103 )
return 0 ;
F_15 ( V_55 , V_53 . V_39 ) ;
V_54 = V_53 . V_40 . V_56 ;
return V_4 * V_30 [ V_54 ] / 10 ;
}
static int F_33 ( const struct V_104 * V_105 )
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
static int F_34 ( struct V_47 * V_48 )
{
union V_52 V_53 ;
int V_106 ;
if ( V_48 -> V_103 != 0 )
return - V_73 ;
F_15 ( V_55 , V_53 . V_39 ) ;
F_35 () ;
V_4 = ( 10 * V_107 ) / V_30 [ V_53 . V_40 . V_56 ] ;
if ( ! V_4 ) {
F_7 (KERN_WARNING PFX L_43 ) ;
return - V_64 ;
}
F_13 ( L_44 , V_4 / 1000 ) ;
if ( F_36 ( V_108 ) || V_109 ) {
F_7 (KERN_INFO PFX L_45
L_46 ) ;
V_106 = F_21 () ;
} else {
V_106 = F_29 ( V_53 . V_40 . V_110 ,
V_53 . V_40 . V_111 ) ;
if ( V_106 ) {
F_7 (KERN_INFO PFX L_47 ) ;
V_33 = 0 ;
V_32 = - 1 ;
V_43 = 0 ;
V_106 = F_21 () ;
if ( V_106 ) {
F_7 (KERN_INFO PFX
L_48 ) ;
}
} else {
V_43 = F_31 () ;
F_7 (KERN_INFO PFX L_49 , latency) ;
}
}
if ( V_106 )
return V_106 ;
F_7 (KERN_INFO PFX L_50 ,
minimum_speed/1000 , maximum_speed/1000 ) ;
V_48 -> V_112 . V_85 =
F_37 ( 2000000UL , V_4 , V_43 ) ;
return F_38 ( V_48 , V_19 ) ;
}
static int F_39 ( struct V_47 * V_48 )
{
#ifdef F_12
if ( V_63 ) {
F_25 ( V_63 , 0 ) ;
F_26 ( V_63 -> V_66 ) ;
F_27 ( V_63 ) ;
}
#endif
F_27 ( V_19 ) ;
return 0 ;
}
static int T_2 F_40 ( void )
{
if ( F_2 () == 0 )
return - V_73 ;
return F_41 ( & V_113 ) ;
}
static void T_3 F_42 ( void )
{
F_43 ( & V_113 ) ;
}
