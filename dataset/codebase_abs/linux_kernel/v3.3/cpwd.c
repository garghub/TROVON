static void F_1 ( T_1 V_1 , void T_2 * V_2 )
{
F_2 ( F_3 ( V_1 ) , V_2 ) ;
}
static T_1 F_4 ( void T_2 * V_2 )
{
T_1 V_1 = F_5 ( V_2 ) ;
return F_6 ( V_1 ) ;
}
static void F_7 ( T_3 V_1 , void T_2 * V_2 )
{
F_8 ( V_1 , V_2 ) ;
}
static T_3 F_9 ( void T_2 * V_2 )
{
return F_10 ( V_2 ) ;
}
static void F_11 ( struct V_3 * V_4 , int V_5 , int V_6 )
{
unsigned char V_7 = F_9 ( V_4 -> V_8 + V_9 ) ;
unsigned char V_10 =
( V_5 == - 1 ) ?
( V_11 | V_12 | V_13 ) :
( V_4 -> V_14 [ V_5 ] . V_15 ) ;
if ( V_6 == V_16 )
V_7 &= ~ V_10 ;
else
V_7 |= V_10 ;
F_7 ( V_7 , V_4 -> V_8 + V_9 ) ;
}
static void F_12 ( struct V_3 * V_4 , int V_5 )
{
F_11 ( V_4 , V_5 , V_16 ) ;
F_1 ( V_17 , V_4 -> V_14 [ V_5 ] . V_8 + V_18 ) ;
}
static void F_13 ( unsigned long V_19 )
{
struct V_3 * V_4 = (struct V_3 * ) V_19 ;
int V_20 , V_21 = 0 ;
if ( F_14 ( & V_22 ) )
F_15 ( & V_22 ) ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
if ( V_4 -> V_14 [ V_20 ] . V_24 & V_25 ) {
++ V_21 ;
F_12 ( V_4 , V_20 ) ;
}
}
if ( V_21 ) {
V_22 . V_26 = V_27 ;
F_16 ( & V_22 ) ;
}
}
static void F_17 ( struct V_3 * V_4 , int V_5 )
{
if ( F_9 ( V_4 -> V_14 [ V_5 ] . V_8 + V_28 ) & V_29 )
F_4 ( V_4 -> V_14 [ V_5 ] . V_8 + V_30 ) ;
}
static void F_18 ( struct V_3 * V_4 , int V_5 )
{
if ( F_9 ( V_4 -> V_14 [ V_5 ] . V_8 + V_28 ) & V_29 ) {
F_11 ( V_4 , V_5 , V_31 ) ;
if ( V_4 -> V_32 ) {
V_4 -> V_14 [ V_5 ] . V_24 |= V_25 ;
F_13 ( ( unsigned long ) V_4 ) ;
}
}
}
static void F_19 ( struct V_3 * V_4 , int V_5 )
{
if ( V_4 -> V_32 )
V_4 -> V_14 [ V_5 ] . V_24 &= ~ V_25 ;
V_4 -> V_14 [ V_5 ] . V_24 &= ~ V_33 ;
F_1 ( V_4 -> V_14 [ V_5 ] . V_34 , V_4 -> V_14 [ V_5 ] . V_8 + V_18 ) ;
F_11 ( V_4 , V_5 , V_16 ) ;
}
static int F_20 ( struct V_3 * V_4 , int V_5 )
{
unsigned char V_35 = F_9 ( V_4 -> V_14 [ V_5 ] . V_8 + V_28 ) ;
unsigned char V_36 = F_9 ( V_4 -> V_14 [ V_5 ] . V_8 + V_9 ) ;
unsigned char V_37 = V_38 ;
if ( ! V_35 )
return V_37 ;
else if ( V_39 & V_35 ) {
V_37 = V_40 ;
} else if ( V_29 & V_35 ) {
if ( V_36 & V_4 -> V_14 [ V_5 ] . V_15 ) {
V_37 = V_41 ;
} else {
if ( V_4 -> V_32 &&
( V_4 -> V_14 [ V_5 ] . V_24 & V_25 ) ) {
if ( V_4 -> V_14 [ V_5 ] . V_24 & V_33 ) {
V_37 = V_40 ;
} else {
V_37 = V_41 ;
}
} else {
V_37 = V_42 ;
}
}
}
if ( V_4 -> V_14 [ V_5 ] . V_24 & V_33 )
V_37 |= V_43 ;
return V_37 ;
}
static T_4 F_21 ( int V_44 , void * V_45 )
{
struct V_3 * V_4 = V_45 ;
F_22 ( & V_4 -> V_46 ) ;
F_18 ( V_4 , V_47 ) ;
V_4 -> V_14 [ V_47 ] . V_24 |= V_33 ;
F_23 ( & V_4 -> V_46 ) ;
return V_48 ;
}
static int F_24 ( struct V_49 * V_49 , struct V_50 * V_51 )
{
struct V_3 * V_4 = V_52 ;
F_25 ( & V_53 ) ;
switch ( F_26 ( V_49 ) ) {
case V_54 :
case V_55 :
case V_56 :
break;
default:
F_27 ( & V_53 ) ;
return - V_57 ;
}
if ( ! V_4 -> V_58 ) {
if ( F_28 ( V_4 -> V_44 , & F_21 ,
V_59 , V_60 , V_4 ) ) {
F_29 (KERN_ERR PFX L_1 ,
p->irq) ;
F_27 ( & V_53 ) ;
return - V_61 ;
}
V_4 -> V_58 = true ;
}
F_27 ( & V_53 ) ;
return F_30 ( V_49 , V_51 ) ;
}
static int F_31 ( struct V_49 * V_49 , struct V_50 * V_50 )
{
return 0 ;
}
static long F_32 ( struct V_50 * V_50 , unsigned int V_62 , unsigned long V_63 )
{
static const struct V_64 V_65 = {
. V_66 = V_67 ,
. V_68 = 1 ,
. V_69 = V_60 ,
} ;
void T_5 * V_70 = ( void T_5 * ) V_63 ;
struct V_49 * V_49 = V_50 -> V_71 . V_72 -> V_73 ;
int V_5 = F_26 ( V_49 ) - V_54 ;
struct V_3 * V_4 = V_52 ;
int V_74 = 0 ;
switch ( V_62 ) {
case V_75 :
if ( F_33 ( V_70 , & V_65 , sizeof( struct V_64 ) ) )
return - V_76 ;
break;
case V_77 :
case V_78 :
if ( F_34 ( 0 , ( int T_5 * ) V_70 ) )
return - V_76 ;
break;
case V_79 :
F_17 ( V_4 , V_5 ) ;
break;
case V_80 :
if ( F_35 ( & V_74 , V_70 , sizeof( unsigned int ) ) )
return - V_76 ;
if ( V_74 & V_81 ) {
if ( V_4 -> V_82 )
return - V_83 ;
F_18 ( V_4 , V_5 ) ;
} else if ( V_74 & V_84 ) {
F_19 ( V_4 , V_5 ) ;
} else {
return - V_83 ;
}
break;
case V_85 :
V_74 = F_20 ( V_4 , V_5 ) ;
if ( F_33 ( V_70 , & V_74 , sizeof( unsigned int ) ) )
return - V_76 ;
break;
case V_86 :
F_19 ( V_4 , V_5 ) ;
break;
case V_87 :
if ( V_4 -> V_82 )
return - V_83 ;
F_18 ( V_4 , V_5 ) ;
break;
default:
return - V_83 ;
}
return 0 ;
}
static long F_36 ( struct V_50 * V_50 , unsigned int V_62 ,
unsigned long V_63 )
{
int V_88 = - V_89 ;
switch ( V_62 ) {
case V_86 :
case V_87 :
case V_85 :
F_25 ( & V_53 ) ;
V_88 = F_32 ( V_50 , V_62 , V_63 ) ;
F_27 ( & V_53 ) ;
break;
default:
break;
}
return V_88 ;
}
static T_6 F_37 ( struct V_50 * V_50 , const char T_5 * V_90 ,
T_7 V_91 , T_8 * V_92 )
{
struct V_49 * V_49 = V_50 -> V_71 . V_72 -> V_73 ;
struct V_3 * V_4 = V_52 ;
int V_5 = F_26 ( V_49 ) ;
if ( V_91 ) {
F_17 ( V_4 , V_5 ) ;
return 1 ;
}
return 0 ;
}
static T_6 F_38 ( struct V_50 * V_50 , char T_5 * V_93 ,
T_7 V_91 , T_8 * V_92 )
{
return - V_83 ;
}
static int T_9 F_39 ( struct V_94 * V_95 )
{
struct V_96 * V_66 ;
const char * V_97 ;
const void * V_98 ;
int V_99 , V_100 = - V_83 ;
struct V_3 * V_4 ;
if ( V_52 )
return - V_83 ;
V_4 = F_40 ( sizeof( * V_4 ) , V_101 ) ;
V_100 = - V_102 ;
if ( ! V_4 ) {
F_29 (KERN_ERR PFX L_2 ) ;
goto V_103;
}
V_4 -> V_44 = V_95 -> V_104 . V_105 [ 0 ] ;
F_41 ( & V_4 -> V_46 ) ;
V_4 -> V_8 = F_42 ( & V_95 -> V_106 [ 0 ] , 0 ,
4 * V_107 , V_60 ) ;
if ( ! V_4 -> V_8 ) {
F_29 (KERN_ERR PFX L_3 ) ;
goto V_108;
}
V_66 = F_43 ( L_4 ) ;
V_100 = - V_57 ;
if ( ! V_66 ) {
F_29 (KERN_ERR PFX L_5 ) ;
goto V_109;
}
V_98 = F_44 ( V_66 , L_6 , NULL ) ;
V_4 -> V_82 = ( V_98 ? true : false ) ;
V_98 = F_44 ( V_66 , L_7 , NULL ) ;
V_4 -> V_110 = ( V_98 ? true : false ) ;
V_97 = F_44 ( V_66 , L_8 , NULL ) ;
if ( V_97 )
V_4 -> V_34 = F_45 ( V_97 , NULL , 10 ) ;
V_97 = F_44 ( V_95 -> V_111 . V_112 , L_9 , NULL ) ;
V_4 -> V_32 = ( V_97 && ! strcmp ( V_97 , V_113 ) ) ;
if ( ! V_4 -> V_82 )
F_11 ( V_4 , - 1 , V_31 ) ;
for ( V_99 = 0 ; V_99 < V_23 ; V_99 ++ ) {
static const char * V_114 [] = { L_10 , L_11 , L_12 } ;
static int * V_115 [] = { & V_116 ,
& V_117 ,
& V_118 } ;
struct V_119 * V_120 = & V_4 -> V_14 [ V_99 ] . V_121 ;
V_120 -> V_122 = V_54 + V_99 ;
V_120 -> V_123 = V_114 [ V_99 ] ;
V_120 -> V_124 = & V_125 ;
V_4 -> V_14 [ V_99 ] . V_8 = V_4 -> V_8 + ( V_99 * V_107 ) ;
V_4 -> V_14 [ V_99 ] . V_15 = ( V_11 << V_99 ) ;
V_4 -> V_14 [ V_99 ] . V_24 &= ~ V_25 ;
V_4 -> V_14 [ V_99 ] . V_24 |= V_126 ;
V_4 -> V_14 [ V_99 ] . V_34 = V_4 -> V_34 ;
if ( * V_115 [ V_99 ] )
V_4 -> V_14 [ V_99 ] . V_34 = * V_115 [ V_99 ] ;
V_100 = F_46 ( & V_4 -> V_14 [ V_99 ] . V_121 ) ;
if ( V_100 ) {
F_29 ( V_127 L_13
L_14 , V_99 ) ;
goto V_128;
}
}
if ( V_4 -> V_32 ) {
F_47 ( & V_22 ) ;
V_22 . V_129 = F_13 ;
V_22 . V_19 = ( unsigned long ) V_4 ;
V_22 . V_26 = V_27 ;
F_29 (KERN_INFO PFX L_15
L_16 WD_BADMODEL L_17 ) ;
}
F_48 ( & V_95 -> V_111 , V_4 ) ;
V_52 = V_4 ;
V_100 = 0 ;
V_103:
return V_100 ;
V_128:
for ( V_99 -- ; V_99 >= 0 ; V_99 -- )
F_49 ( & V_4 -> V_14 [ V_99 ] . V_121 ) ;
V_109:
F_50 ( & V_95 -> V_106 [ 0 ] , V_4 -> V_8 , 4 * V_107 ) ;
V_108:
F_51 ( V_4 ) ;
goto V_103;
}
static int T_10 F_52 ( struct V_94 * V_95 )
{
struct V_3 * V_4 = F_53 ( & V_95 -> V_111 ) ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_23 ; V_99 ++ ) {
F_49 ( & V_4 -> V_14 [ V_99 ] . V_121 ) ;
if ( ! V_4 -> V_82 ) {
F_18 ( V_4 , V_99 ) ;
if ( V_4 -> V_14 [ V_99 ] . V_24 & V_25 )
F_12 ( V_4 , V_99 ) ;
}
}
if ( V_4 -> V_32 )
F_54 ( & V_22 ) ;
if ( V_4 -> V_58 )
F_55 ( V_4 -> V_44 , V_4 ) ;
F_50 ( & V_95 -> V_106 [ 0 ] , V_4 -> V_8 , 4 * V_107 ) ;
F_51 ( V_4 ) ;
V_52 = NULL ;
return 0 ;
}
