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
V_19 = F_11 ( ( sizeof( struct V_27 ) *
( V_28 + 1 ) ) , V_29 ) ;
if ( ! V_19 )
return - V_30 ;
for ( V_23 = 0 ; V_23 < V_28 ; V_23 ++ ) {
V_25 = * V_22 ++ ;
V_19 [ V_23 ] . V_20 = ( V_4 * V_31 [ V_25 ] ) / 10 ;
V_19 [ V_23 ] . V_32 = V_25 ;
V_24 = V_19 [ V_23 ] . V_20 ;
if ( ( V_31 [ V_25 ] % 10 ) == 5 ) {
#ifdef F_12
if ( V_15 == 1 )
F_9 ( V_23 ) ;
#endif
}
if ( V_24 < V_33 )
V_33 = V_24 ;
if ( V_24 > V_34 )
V_34 = V_24 ;
V_26 = * V_22 ++ ;
V_19 [ V_23 ] . V_32 |= ( V_26 << 8 ) ;
F_13 ( L_9
L_10 , V_25 , V_31 [ V_25 ] / 10 ,
V_31 [ V_25 ] % 10 , V_24 / 1000 , V_26 ,
V_35 [ V_26 ] / 1000 ,
V_35 [ V_26 ] % 1000 ) ;
}
V_19 [ V_28 ] . V_20 = V_36 ;
V_19 [ V_28 ] . V_32 = 0 ;
return 0 ;
}
static void F_14 ( int V_25 )
{
union V_37 V_38 ;
F_15 ( V_39 , V_38 . V_40 ) ;
if ( V_38 . V_41 . V_42 != V_25 ) {
V_38 . V_41 . V_43 = V_44 ;
V_38 . V_41 . V_42 = V_25 ;
V_38 . V_41 . V_45 = 0 ;
V_38 . V_41 . V_46 = 1 ;
F_16 ( V_39 , V_38 . V_40 ) ;
}
}
static void F_17 ( int V_26 )
{
union V_37 V_38 ;
F_15 ( V_39 , V_38 . V_40 ) ;
if ( V_38 . V_41 . V_47 != V_26 ) {
V_38 . V_41 . V_43 = V_44 ;
V_38 . V_41 . V_47 = V_26 ;
V_38 . V_41 . V_46 = 0 ;
V_38 . V_41 . V_45 = 1 ;
F_16 ( V_39 , V_38 . V_40 ) ;
}
}
static void F_18 ( struct V_48 * V_49 , unsigned int V_50 )
{
T_1 V_25 , V_26 ;
struct V_51 V_52 ;
union V_53 V_54 ;
int V_55 ;
V_25 = V_19 [ V_50 ] . V_32 & 0xFF ;
V_26 = ( V_19 [ V_50 ] . V_32 & 0xFF00 ) >> 8 ;
F_15 ( V_56 , V_54 . V_40 ) ;
V_55 = V_54 . V_41 . V_57 ;
V_52 . V_58 = V_4 * V_31 [ V_55 ] / 10 ;
V_52 . V_59 = V_19 [ V_50 ] . V_20 ;
F_19 ( V_49 , & V_52 , V_60 ) ;
if ( V_15 == 1 )
F_20 () ;
if ( V_52 . V_58 > V_52 . V_59 ) {
F_14 ( V_25 ) ;
F_17 ( V_26 ) ;
} else {
F_17 ( V_26 ) ;
F_14 ( V_25 ) ;
}
if ( V_15 == 1 )
F_21 () ;
F_19 ( V_49 , & V_52 , V_61 ) ;
}
static int F_22 ( void )
{
int V_62 ;
int V_63 = 0 ;
union V_64 V_65 ;
if ( V_66 != NULL && V_19 != NULL ) {
V_63 = - V_67 ;
goto V_68;
}
V_66 = F_11 ( sizeof( struct V_69 ) ,
V_29 ) ;
if ( ! V_66 ) {
V_63 = - V_30 ;
goto V_68;
}
if ( ! F_23 ( & V_66 -> V_70 ,
V_29 ) ) {
V_63 = - V_30 ;
goto V_71;
}
if ( F_24 ( V_66 , 0 ) ) {
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
V_28 = V_66 -> V_80 ;
if ( V_28 < 2 ) {
V_63 = - V_77 ;
goto V_78;
}
V_19 = F_11 ( ( sizeof( struct V_27 ) *
( V_28 + 1 ) ) , V_29 ) ;
if ( ! V_19 ) {
V_63 = - V_30 ;
goto V_78;
}
V_65 . V_40 = ( unsigned long ) V_66 -> V_81 [ 0 ] . V_82 ;
for ( V_62 = 0 ; V_62 < V_28 ; V_62 ++ ) {
T_1 V_25 , V_26 ;
struct V_83 * V_84 =
& V_66 -> V_81 [ V_62 ] ;
unsigned int V_24 , V_85 ;
V_65 . V_40 = ( unsigned long ) V_84 -> V_82 ;
F_13 ( L_11 ,
V_62 ,
( V_86 ) V_84 -> V_87 ,
( V_86 ) V_84 -> V_88 ,
( V_86 ) V_84 -> V_89 ,
( V_86 ) V_84 -> V_82 ,
V_65 . V_41 . V_90 ) ;
V_26 = V_65 . V_41 . V_26 ;
V_25 = V_65 . V_41 . V_25 ;
V_19 [ V_62 ] . V_20 = V_4 * V_31 [ V_25 ] / 10 ;
V_19 [ V_62 ] . V_32 = V_25 ;
V_19 [ V_62 ] . V_32 |= ( V_26 << 8 ) ;
V_24 = V_19 [ V_62 ] . V_20 ;
V_85 = V_24 / 1000 ;
if ( V_24 % 1000 > 0 )
V_85 ++ ;
if ( ( V_31 [ V_25 ] % 10 ) == 5 ) {
if ( V_15 == 1 )
F_9 ( V_62 ) ;
}
F_13 ( L_9
L_10 , V_25 , V_31 [ V_25 ] / 10 ,
V_31 [ V_25 ] % 10 , V_85 , V_26 ,
V_35 [ V_26 ] / 1000 ,
V_35 [ V_26 ] % 1000 ) ;
if ( V_84 -> V_87 != V_85 ) {
V_84 -> V_87 = V_85 ;
F_13 ( L_12 ,
V_85 ) ;
}
if ( V_44 < V_65 . V_41 . V_90 )
V_44 = V_65 . V_41 . V_90 ;
if ( V_24 < V_33 )
V_33 = V_24 ;
if ( V_24 > V_34 )
V_34 = V_24 ;
}
V_19 [ V_62 ] . V_20 = V_36 ;
V_19 [ V_62 ] . V_32 = 0 ;
F_25 ( V_91 ) ;
return 0 ;
V_78:
F_26 ( V_66 , 0 ) ;
V_73:
F_27 ( V_66 -> V_70 ) ;
V_71:
F_28 ( V_66 ) ;
V_68:
F_7 (KERN_WARNING PFX L_13
L_14 ) ;
V_66 = NULL ;
return V_63 ;
}
static int F_22 ( void )
{
F_7 (KERN_INFO PFX L_15
L_16 ) ;
return - V_67 ;
}
static void F_29 ( struct V_92 * V_22 , unsigned int V_23 )
{
F_13 ( L_17 , V_23 , V_22 ) ;
F_13 ( L_18 ,
V_22 -> F_8 , V_22 -> V_1 , V_22 -> V_93 , V_22 -> V_94 ) ;
}
static int F_30 ( int V_93 , int V_94 )
{
struct V_95 * V_96 ;
struct V_92 * V_22 ;
unsigned int V_62 , V_23 ;
unsigned char * V_97 ;
unsigned int V_98 ;
unsigned int V_99 ;
V_98 = F_5 ( 0x80000001 ) ;
for ( V_62 = 0xC0000 ; V_62 < 0xffff0 ; V_62 += 16 ) {
V_97 = F_31 ( V_62 ) ;
if ( memcmp ( V_97 , L_19 , 10 ) == 0 ) {
F_13 ( L_20 , V_97 ) ;
V_96 = (struct V_95 * ) V_97 ;
F_13 ( L_21 , V_96 -> V_100 ) ;
if ( V_96 -> V_100 != 0x12 ) {
F_7 (KERN_INFO PFX L_22
L_23 ) ;
return - V_77 ;
}
F_13 ( L_24 , V_96 -> V_101 ) ;
if ( ( V_96 -> V_101 & 1 ) == 0 )
F_13 ( L_25 ) ;
else
F_13 ( L_26 ) ;
V_44 = V_96 -> V_102 ;
if ( V_44 < 100 ) {
F_7 (KERN_INFO PFX L_27
L_28
L_29
L_30 , latency) ;
V_44 = 100 ;
}
F_13 ( L_31 ,
V_96 -> V_102 ) ;
F_13 ( L_32
L_33 ,
V_96 -> V_103 ) ;
V_97 += sizeof( struct V_95 ) ;
V_22 = (struct V_92 * ) V_97 ;
for ( V_23 = 0 ; V_23 < V_96 -> V_103 ; V_23 ++ ) {
V_22 = (struct V_92 * ) V_97 ;
V_28 = V_22 -> V_104 ;
if ( ( V_98 == V_22 -> F_8 ) &&
F_1 ( V_22 -> V_1 ) &&
( V_93 == V_22 -> V_93 ) &&
( V_94 == V_22 -> V_94 ) ) {
F_29 ( V_22 , V_23 ) ;
V_97 = ( char * ) V_22 + sizeof( struct V_92 ) ;
V_99 = F_10 ( V_97 ) ;
return V_99 ;
} else {
unsigned int V_105 ;
V_97 = ( char * ) V_22 + sizeof( struct V_92 ) ;
for ( V_105 = 0 ; V_105 < V_28 ; V_105 ++ )
V_97 += 2 ;
}
}
F_7 (KERN_INFO PFX L_34
L_35 , etuple) ;
F_7 (KERN_INFO PFX L_36
L_37 ) ;
return - V_67 ;
}
V_97 ++ ;
}
return - V_77 ;
}
static int F_32 ( struct V_48 * V_49 ,
unsigned int V_106 ,
unsigned int V_107 )
{
unsigned int V_108 ;
if ( F_33 ( V_49 , V_19 , V_106 ,
V_107 , & V_108 ) )
return - V_67 ;
F_18 ( V_49 , V_108 ) ;
return 0 ;
}
static int F_34 ( struct V_48 * V_49 )
{
return F_35 ( V_49 , V_19 ) ;
}
static int F_36 ( void )
{
unsigned int V_90 ;
unsigned int V_109 ;
V_109 = V_4 / 3333 ;
if ( ( V_109 % 10 ) >= 5 )
V_109 += 5 ;
V_109 /= 10 ;
V_90 = 100 * V_109 * V_44 ;
V_90 = V_90 / 3 ;
if ( V_90 > 0xfffff ) {
F_7 (KERN_WARNING PFX L_38 , sgtc) ;
V_90 = 0xfffff ;
}
return V_90 ;
}
static unsigned int F_37 ( unsigned int V_110 )
{
union V_53 V_54 ;
unsigned int V_55 ;
if ( V_110 )
return 0 ;
F_15 ( V_56 , V_54 . V_40 ) ;
V_55 = V_54 . V_41 . V_57 ;
return V_4 * V_31 [ V_55 ] / 10 ;
}
static int F_38 ( const struct V_111 * V_112 )
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
static int F_39 ( struct V_48 * V_49 )
{
union V_53 V_54 ;
int V_113 ;
if ( V_49 -> V_110 != 0 )
return - V_77 ;
F_15 ( V_56 , V_54 . V_40 ) ;
F_40 () ;
V_4 = ( 10 * V_114 ) / V_31 [ V_54 . V_41 . V_57 ] ;
if ( ! V_4 ) {
F_7 (KERN_WARNING PFX L_43 ) ;
return - V_67 ;
}
F_13 ( L_44 , V_4 / 1000 ) ;
if ( F_41 ( V_115 ) || V_116 ) {
F_7 (KERN_INFO PFX L_45
L_46 ) ;
V_113 = F_22 () ;
} else {
V_113 = F_30 ( V_54 . V_41 . V_117 ,
V_54 . V_41 . V_118 ) ;
if ( V_113 ) {
F_7 (KERN_INFO PFX L_47 ) ;
V_34 = 0 ;
V_33 = - 1 ;
V_44 = 0 ;
V_113 = F_22 () ;
if ( V_113 ) {
F_7 (KERN_INFO PFX
L_48 ) ;
}
} else {
V_44 = F_36 () ;
F_7 (KERN_INFO PFX L_49 , latency) ;
}
}
if ( V_113 )
return V_113 ;
F_7 (KERN_INFO PFX L_50 ,
minimum_speed/1000 , maximum_speed/1000 ) ;
V_49 -> V_119 . V_89 =
F_42 ( 2000000UL , V_4 , V_44 ) ;
V_49 -> V_120 = F_37 ( 0 ) ;
F_43 ( V_19 , V_49 -> V_110 ) ;
return F_44 ( V_49 , V_19 ) ;
}
static int F_45 ( struct V_48 * V_49 )
{
F_46 ( V_49 -> V_110 ) ;
#ifdef F_12
if ( V_66 ) {
F_26 ( V_66 , 0 ) ;
F_27 ( V_66 -> V_70 ) ;
F_28 ( V_66 ) ;
}
#endif
F_28 ( V_19 ) ;
return 0 ;
}
static int T_2 F_47 ( void )
{
if ( F_2 () == 0 )
return - V_77 ;
return F_48 ( & V_121 ) ;
}
static void T_3 F_49 ( void )
{
F_50 ( & V_121 ) ;
}
