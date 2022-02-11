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
if ( ( V_6 -> V_12 != V_13 ) || ( V_6 -> V_14 != 6 ) ) {
#ifdef F_4
F_5 (KERN_INFO PFX L_1
L_2 ) ;
#endif
return 0 ;
}
V_7 = F_6 ( 0x80000000 ) ;
if ( V_7 < 0x80000007 ) {
#ifdef F_4
F_5 (KERN_INFO PFX L_3 ) ;
#endif
return 0 ;
}
if ( ( V_6 -> V_15 == 6 ) && ( V_6 -> V_16 == 0 ) ) {
F_5 (KERN_INFO PFX L_4
L_5 ) ;
V_17 = 1 ;
}
F_7 ( 0x80000007 , & V_8 , & V_9 , & V_10 , & V_11 ) ;
if ( ! ( V_11 & ( 1 << 1 | 1 << 2 ) ) )
return 0 ;
F_5 (KERN_INFO PFX L_6 ) ;
if ( V_11 & 1 << 1 ) {
F_5 ( L_7 ) ;
V_18 = 1 ;
}
if ( ( V_11 & ( 1 << 1 | 1 << 2 ) ) == 0x6 )
F_5 ( L_8 ) ;
if ( V_11 & 1 << 2 ) {
F_5 ( L_9 ) ;
V_19 = 1 ;
}
F_5 ( L_10 ) ;
return 1 ;
}
static void F_8 ( unsigned int V_20 )
{
V_21 [ V_20 ] . V_22 = V_23 ;
}
static int F_9 ( unsigned char * V_24 )
{
unsigned int V_25 ;
unsigned int V_26 ;
T_1 V_27 , V_28 ;
V_21 = F_10 ( ( sizeof( struct V_29 ) *
( V_30 + 1 ) ) , V_31 ) ;
if ( ! V_21 )
return - V_32 ;
for ( V_25 = 0 ; V_25 < V_30 ; V_25 ++ ) {
V_27 = * V_24 ++ ;
V_21 [ V_25 ] . V_22 = ( V_4 * V_33 [ V_27 ] ) / 10 ;
V_21 [ V_25 ] . V_34 = V_27 ;
V_26 = V_21 [ V_25 ] . V_22 ;
if ( ( V_33 [ V_27 ] % 10 ) == 5 ) {
#ifdef F_11
if ( V_17 == 1 )
F_8 ( V_25 ) ;
#endif
}
if ( V_26 < V_35 )
V_35 = V_26 ;
if ( V_26 > V_36 )
V_36 = V_26 ;
V_28 = * V_24 ++ ;
V_21 [ V_25 ] . V_34 |= ( V_28 << 8 ) ;
F_12 ( L_11
L_12 , V_27 , V_33 [ V_27 ] / 10 ,
V_33 [ V_27 ] % 10 , V_26 / 1000 , V_28 ,
V_37 [ V_28 ] / 1000 ,
V_37 [ V_28 ] % 1000 ) ;
}
V_21 [ V_30 ] . V_22 = V_38 ;
V_21 [ V_30 ] . V_34 = 0 ;
return 0 ;
}
static void F_13 ( int V_27 )
{
union V_39 V_40 ;
F_14 ( V_41 , V_40 . V_42 ) ;
if ( V_40 . V_43 . V_44 != V_27 ) {
V_40 . V_43 . V_45 = V_46 ;
V_40 . V_43 . V_44 = V_27 ;
V_40 . V_43 . V_47 = 0 ;
V_40 . V_43 . V_48 = 1 ;
F_15 ( V_41 , V_40 . V_42 ) ;
}
}
static void F_16 ( int V_28 )
{
union V_39 V_40 ;
F_14 ( V_41 , V_40 . V_42 ) ;
if ( V_40 . V_43 . V_49 != V_28 ) {
V_40 . V_43 . V_45 = V_46 ;
V_40 . V_43 . V_49 = V_28 ;
V_40 . V_43 . V_48 = 0 ;
V_40 . V_43 . V_47 = 1 ;
F_15 ( V_41 , V_40 . V_42 ) ;
}
}
static void F_17 ( unsigned int V_34 )
{
T_1 V_27 , V_28 ;
struct V_50 V_51 ;
union V_52 V_53 ;
int V_54 ;
V_27 = V_21 [ V_34 ] . V_34 & 0xFF ;
V_28 = ( V_21 [ V_34 ] . V_34 & 0xFF00 ) >> 8 ;
V_51 . V_55 = 0 ;
F_14 ( V_56 , V_53 . V_42 ) ;
V_54 = V_53 . V_43 . V_57 ;
V_51 . V_58 = V_4 * V_33 [ V_54 ] / 10 ;
V_51 . V_59 = V_21 [ V_34 ] . V_22 ;
F_18 ( & V_51 , V_60 ) ;
if ( V_17 == 1 )
F_19 () ;
if ( V_51 . V_58 > V_51 . V_59 ) {
F_13 ( V_27 ) ;
F_16 ( V_28 ) ;
} else {
F_16 ( V_28 ) ;
F_13 ( V_27 ) ;
}
if ( V_17 == 1 )
F_20 () ;
F_18 ( & V_51 , V_61 ) ;
}
static int F_21 ( void )
{
int V_62 ;
int V_63 = 0 ;
union V_64 V_65 ;
if ( V_66 != NULL && V_21 != NULL ) {
V_63 = - V_67 ;
goto V_68;
}
V_66 = F_10 ( sizeof( struct V_69 ) ,
V_31 ) ;
if ( ! V_66 ) {
V_63 = - V_32 ;
goto V_68;
}
if ( ! F_22 ( & V_66 -> V_70 ,
V_31 ) ) {
V_63 = - V_32 ;
goto V_71;
}
if ( F_23 ( V_66 , 0 ) ) {
V_63 = - V_72 ;
goto V_73;
}
if ( V_66 -> V_74 . V_75 !=
V_76 ) {
V_63 = - V_77 ;
goto V_78;
}
if ( V_66 -> V_79 . V_75 !=
V_76 ) {
V_63 = - V_77 ;
goto V_78;
}
V_30 = V_66 -> V_80 ;
if ( V_30 < 2 ) {
V_63 = - V_77 ;
goto V_78;
}
V_21 = F_10 ( ( sizeof( struct V_29 ) *
( V_30 + 1 ) ) , V_31 ) ;
if ( ! V_21 ) {
V_63 = - V_32 ;
goto V_78;
}
V_65 . V_42 = ( unsigned long ) V_66 -> V_81 [ 0 ] . V_82 ;
for ( V_62 = 0 ; V_62 < V_30 ; V_62 ++ ) {
T_1 V_27 , V_28 ;
struct V_83 * V_84 =
& V_66 -> V_81 [ V_62 ] ;
unsigned int V_26 , V_85 ;
V_65 . V_42 = ( unsigned long ) V_84 -> V_82 ;
F_12 ( L_13 ,
V_62 ,
( V_86 ) V_84 -> V_87 ,
( V_86 ) V_84 -> V_88 ,
( V_86 ) V_84 -> V_89 ,
( V_86 ) V_84 -> V_82 ,
V_65 . V_43 . V_90 ) ;
V_28 = V_65 . V_43 . V_28 ;
V_27 = V_65 . V_43 . V_27 ;
V_21 [ V_62 ] . V_22 = V_4 * V_33 [ V_27 ] / 10 ;
V_21 [ V_62 ] . V_34 = V_27 ;
V_21 [ V_62 ] . V_34 |= ( V_28 << 8 ) ;
V_26 = V_21 [ V_62 ] . V_22 ;
V_85 = V_26 / 1000 ;
if ( V_26 % 1000 > 0 )
V_85 ++ ;
if ( ( V_33 [ V_27 ] % 10 ) == 5 ) {
if ( V_17 == 1 )
F_8 ( V_62 ) ;
}
F_12 ( L_11
L_12 , V_27 , V_33 [ V_27 ] / 10 ,
V_33 [ V_27 ] % 10 , V_85 , V_28 ,
V_37 [ V_28 ] / 1000 ,
V_37 [ V_28 ] % 1000 ) ;
if ( V_84 -> V_87 != V_85 ) {
V_84 -> V_87 = V_85 ;
F_12 ( L_14 ,
V_85 ) ;
}
if ( V_46 < V_65 . V_43 . V_90 )
V_46 = V_65 . V_43 . V_90 ;
if ( V_26 < V_35 )
V_35 = V_26 ;
if ( V_26 > V_36 )
V_36 = V_26 ;
}
V_21 [ V_62 ] . V_22 = V_38 ;
V_21 [ V_62 ] . V_34 = 0 ;
F_24 ( V_91 ) ;
return 0 ;
V_78:
F_25 ( V_66 , 0 ) ;
V_73:
F_26 ( V_66 -> V_70 ) ;
V_71:
F_27 ( V_66 ) ;
V_68:
F_5 (KERN_WARNING PFX L_15
L_16 ) ;
V_66 = NULL ;
return V_63 ;
}
static int F_21 ( void )
{
F_5 (KERN_INFO PFX L_17
L_18 ) ;
return - V_67 ;
}
static void F_28 ( struct V_92 * V_24 , unsigned int V_25 )
{
F_12 ( L_19 , V_25 , V_24 ) ;
F_12 ( L_20 ,
V_24 -> F_7 , V_24 -> V_1 , V_24 -> V_93 , V_24 -> V_94 ) ;
}
static int F_29 ( int V_93 , int V_94 )
{
struct V_95 * V_96 ;
struct V_92 * V_24 ;
unsigned int V_62 , V_25 ;
unsigned char * V_97 ;
unsigned int V_98 ;
unsigned int V_99 ;
V_98 = F_6 ( 0x80000001 ) ;
for ( V_62 = 0xC0000 ; V_62 < 0xffff0 ; V_62 += 16 ) {
V_97 = F_30 ( V_62 ) ;
if ( memcmp ( V_97 , L_21 , 10 ) == 0 ) {
F_12 ( L_22 , V_97 ) ;
V_96 = (struct V_95 * ) V_97 ;
F_12 ( L_23 , V_96 -> V_100 ) ;
if ( V_96 -> V_100 != 0x12 ) {
F_5 (KERN_INFO PFX L_24
L_25 ) ;
return - V_77 ;
}
F_12 ( L_26 , V_96 -> V_101 ) ;
if ( ( V_96 -> V_101 & 1 ) == 0 )
F_12 ( L_27 ) ;
else
F_12 ( L_28 ) ;
V_46 = V_96 -> V_102 ;
if ( V_46 < 100 ) {
F_5 (KERN_INFO PFX L_29
L_30
L_31
L_32 , latency) ;
V_46 = 100 ;
}
F_12 ( L_33 ,
V_96 -> V_102 ) ;
F_12 ( L_34
L_35 ,
V_96 -> V_103 ) ;
V_97 += sizeof( struct V_95 ) ;
V_24 = (struct V_92 * ) V_97 ;
for ( V_25 = 0 ; V_25 < V_96 -> V_103 ; V_25 ++ ) {
V_24 = (struct V_92 * ) V_97 ;
V_30 = V_24 -> V_104 ;
if ( ( V_98 == V_24 -> F_7 ) &&
F_1 ( V_24 -> V_1 ) &&
( V_93 == V_24 -> V_93 ) &&
( V_94 == V_24 -> V_94 ) ) {
F_28 ( V_24 , V_25 ) ;
V_97 = ( char * ) V_24 + sizeof( struct V_92 ) ;
V_99 = F_9 ( V_97 ) ;
return V_99 ;
} else {
unsigned int V_105 ;
V_97 = ( char * ) V_24 + sizeof( struct V_92 ) ;
for ( V_105 = 0 ; V_105 < V_30 ; V_105 ++ )
V_97 += 2 ;
}
}
F_5 (KERN_INFO PFX L_36
L_37 , etuple) ;
F_5 (KERN_INFO PFX L_38
L_39 ) ;
return - V_67 ;
}
V_97 ++ ;
}
return - V_77 ;
}
static int F_31 ( struct V_106 * V_107 ,
unsigned int V_108 ,
unsigned int V_109 )
{
unsigned int V_110 ;
if ( F_32 ( V_107 , V_21 , V_108 ,
V_109 , & V_110 ) )
return - V_67 ;
F_17 ( V_110 ) ;
return 0 ;
}
static int F_33 ( struct V_106 * V_107 )
{
return F_34 ( V_107 , V_21 ) ;
}
static int T_2 F_35 ( void )
{
unsigned int V_90 ;
unsigned int V_111 ;
V_111 = V_4 / 3333 ;
if ( ( V_111 % 10 ) >= 5 )
V_111 += 5 ;
V_111 /= 10 ;
V_90 = 100 * V_111 * V_46 ;
V_90 = V_90 / 3 ;
if ( V_90 > 0xfffff ) {
F_5 (KERN_WARNING PFX L_40 , sgtc) ;
V_90 = 0xfffff ;
}
return V_90 ;
}
static unsigned int F_36 ( unsigned int V_55 )
{
union V_52 V_53 ;
unsigned int V_54 ;
if ( V_55 )
return 0 ;
F_14 ( V_56 , V_53 . V_42 ) ;
V_54 = V_53 . V_43 . V_57 ;
return V_4 * V_33 [ V_54 ] / 10 ;
}
static int T_2 F_37 ( const struct V_112 * V_113 )
{
F_5 (KERN_WARNING PFX
L_41 ,
d->ident) ;
F_5 (KERN_WARNING PFX
L_42
L_43 ) ;
F_5 (KERN_WARNING PFX
L_44 ) ;
return 0 ;
}
static int T_2 F_38 ( struct V_106 * V_107 )
{
union V_52 V_53 ;
int V_114 ;
if ( V_107 -> V_55 != 0 )
return - V_77 ;
F_14 ( V_56 , V_53 . V_42 ) ;
F_39 () ;
V_4 = ( 10 * V_115 ) / V_33 [ V_53 . V_43 . V_57 ] ;
if ( ! V_4 ) {
F_5 (KERN_WARNING PFX L_45 ) ;
return - V_67 ;
}
F_12 ( L_46 , V_4 / 1000 ) ;
if ( F_40 ( V_116 ) || V_117 ) {
F_5 (KERN_INFO PFX L_47
L_48 ) ;
V_114 = F_21 () ;
} else {
V_114 = F_29 ( V_53 . V_43 . V_118 ,
V_53 . V_43 . V_119 ) ;
if ( V_114 ) {
F_5 (KERN_INFO PFX L_49 ) ;
V_36 = 0 ;
V_35 = - 1 ;
V_46 = 0 ;
V_114 = F_21 () ;
if ( V_114 ) {
F_5 (KERN_INFO PFX
L_50 ) ;
}
} else {
V_46 = F_35 () ;
F_5 (KERN_INFO PFX L_51 , latency) ;
}
}
if ( V_114 )
return V_114 ;
F_5 (KERN_INFO PFX L_52 ,
minimum_speed/1000 , maximum_speed/1000 ) ;
V_107 -> V_120 . V_89 =
F_41 ( 2000000UL , V_4 , V_46 ) ;
V_107 -> V_121 = F_36 ( 0 ) ;
F_42 ( V_21 , V_107 -> V_55 ) ;
return F_43 ( V_107 , V_21 ) ;
}
static int F_44 ( struct V_106 * V_107 )
{
F_45 ( V_107 -> V_55 ) ;
#ifdef F_11
if ( V_66 ) {
F_25 ( V_66 , 0 ) ;
F_26 ( V_66 -> V_70 ) ;
F_27 ( V_66 ) ;
}
#endif
F_27 ( V_21 ) ;
return 0 ;
}
static int T_3 F_46 ( void )
{
if ( F_2 () == 0 )
return - V_77 ;
return F_47 ( & V_122 ) ;
}
static void T_4 F_48 ( void )
{
F_49 ( & V_122 ) ;
}
