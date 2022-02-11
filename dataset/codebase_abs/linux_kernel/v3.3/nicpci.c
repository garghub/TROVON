static void F_1 ( void )
{
F_2 ( 10 ) ;
}
struct V_1 * F_3 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 ;
V_6 = F_4 ( sizeof( struct V_1 ) , V_7 ) ;
if ( V_6 == NULL )
return NULL ;
V_6 -> V_3 = V_3 ;
V_6 -> V_8 = V_5 -> V_9 -> V_10 ;
V_6 -> V_5 = V_5 ;
if ( V_5 -> V_11 . V_11 == V_12 ) {
T_1 V_13 ;
V_13 = F_5 ( V_6 -> V_8 , V_14 ,
NULL , NULL ) ;
V_6 -> V_15 = V_13 + V_16 ;
}
return V_6 ;
}
void F_6 ( struct V_1 * V_17 )
{
F_7 ( V_17 ) ;
}
T_1
F_5 ( struct V_18 * V_8 , T_1 V_19 ,
unsigned char * V_20 , T_2 * V_21 )
{
T_1 V_22 ;
T_1 V_13 = 0 ;
T_2 V_23 ;
T_1 V_24 ;
F_8 ( V_8 , V_25 , & V_24 ) ;
if ( ( V_24 & 0x7f ) != V_26 )
goto V_27;
F_8 ( V_8 , V_28 , & V_24 ) ;
if ( ! ( V_24 & V_29 ) )
goto V_27;
F_8 ( V_8 , V_30 , & V_13 ) ;
if ( V_13 == 0x00 )
goto V_27;
F_8 ( V_8 , V_13 , & V_22 ) ;
while ( V_22 != V_19 ) {
F_8 ( V_8 , V_13 + 1 , & V_13 ) ;
if ( V_13 == 0x00 )
break;
F_8 ( V_8 , V_13 , & V_22 ) ;
}
if ( V_22 != V_19 )
goto V_27;
if ( V_20 != NULL && V_21 != NULL ) {
T_1 V_31 ;
V_23 = * V_21 ;
if ( ! V_23 )
goto V_27;
* V_21 = 0 ;
V_31 = V_13 + 2 ;
if ( ( V_23 + V_31 ) > V_32 )
V_23 = V_32 - V_31 ;
* V_21 = V_23 ;
while ( V_23 -- ) {
F_8 ( V_8 , V_31 , V_20 ) ;
V_31 ++ ;
V_20 ++ ;
}
}
V_27:
return V_13 ;
}
static T_3
F_9 ( struct V_4 * V_5 , T_3 V_33 , T_3 V_34 )
{
T_3 V_35 = 0xFFFFFFFF ;
switch ( V_33 ) {
case V_36 :
F_10 ( V_5 , F_11 ( V_37 ) , V_34 ) ;
( void ) F_12 ( V_5 , F_11 ( V_37 ) ) ;
V_35 = F_12 ( V_5 , F_11 ( V_38 ) ) ;
break;
case V_39 :
F_10 ( V_5 , F_11 ( V_40 ) , V_34 ) ;
( void ) F_12 ( V_5 , F_11 ( V_40 ) ) ;
V_35 = F_12 ( V_5 , F_11 ( V_41 ) ) ;
break;
}
return V_35 ;
}
static T_3 F_13 ( struct V_4 * V_5 , T_3 V_33 ,
T_3 V_34 , T_3 V_42 )
{
switch ( V_33 ) {
case V_36 :
F_10 ( V_5 , F_11 ( V_37 ) , V_34 ) ;
F_10 ( V_5 , F_11 ( V_38 ) , V_42 ) ;
break;
case V_39 :
F_10 ( V_5 , F_11 ( V_40 ) , V_34 ) ;
F_10 ( V_5 , F_11 ( V_41 ) , V_42 ) ;
break;
default:
break;
}
return 0 ;
}
static bool F_14 ( struct V_1 * V_6 , T_3 V_43 )
{
T_3 V_44 , V_45 = 0 ;
T_3 V_46 = 200 ;
V_44 = ( V_47 | V_48 | V_49 |
( V_50 << V_51 ) |
( V_52 << V_53 ) |
( V_43 << 4 ) ) ;
F_10 ( V_6 -> V_5 , F_11 ( V_44 ) , V_44 ) ;
F_1 () ;
while ( V_45 < V_46 ) {
if ( F_12 ( V_6 -> V_5 , F_11 ( V_54 ) ) &
V_55 )
break;
F_2 ( 1000 ) ;
V_45 ++ ;
}
if ( V_45 >= V_46 )
return false ;
return true ;
}
static int
F_15 ( struct V_1 * V_6 , T_3 V_56 , T_3 V_57 , bool V_58 ,
T_3 * V_42 )
{
T_3 V_44 ;
T_3 V_45 = 0 ;
T_3 V_46 = 10 ;
F_10 ( V_6 -> V_5 , F_11 ( V_54 ) ,
V_59 | V_60 ) ;
if ( F_16 ( V_6 -> V_3 ) >= 10 ) {
if ( ! F_14 ( V_6 , V_56 ) )
return 1 ;
V_44 = ( ( V_50 << V_51 ) |
( V_57 << V_53 ) ) ;
V_46 *= 20 ;
} else {
V_44 = ( ( V_56 << V_61 ) |
( V_57 << V_62 ) ) ;
}
if ( ! V_58 )
V_44 |= ( V_47 | V_63 | V_49 ) ;
else
V_44 |= ( V_47 | V_48 | V_49 |
* V_42 ) ;
F_10 ( V_6 -> V_5 , F_11 ( V_44 ) , V_44 ) ;
F_1 () ;
while ( V_45 < V_46 ) {
if ( F_12 ( V_6 -> V_5 , F_11 ( V_54 ) ) &
V_55 ) {
if ( ! V_58 ) {
F_1 () ;
* V_42 = ( F_12 ( V_6 -> V_5 ,
F_11 ( V_44 ) ) &
V_64 ) ;
}
F_10 ( V_6 -> V_5 , F_11 ( V_54 ) , 0 ) ;
return 0 ;
}
F_2 ( 1000 ) ;
V_45 ++ ;
}
F_10 ( V_6 -> V_5 , F_11 ( V_54 ) , 0 ) ;
return 1 ;
}
static int
F_17 ( struct V_1 * V_6 , T_3 V_56 , T_3 V_57 ,
T_3 * V_65 )
{
return F_15 ( V_6 , V_56 , V_57 , false , V_65 ) ;
}
static int
F_18 ( struct V_1 * V_6 , T_3 V_56 , T_3 V_57 , T_3 V_42 )
{
return F_15 ( V_6 , V_56 , V_57 , true , & V_42 ) ;
}
static T_1 F_19 ( struct V_1 * V_6 , T_2 V_66 , T_2 V_42 )
{
T_2 V_67 ;
T_1 V_34 ;
V_34 = V_6 -> V_15 ;
if ( ! V_34 )
return 0 ;
F_20 ( V_6 -> V_8 , V_34 , & V_67 ) ;
if ( V_66 ) {
if ( V_42 )
V_67 |= V_68 ;
else
V_67 &= ~ V_68 ;
F_21 ( V_6 -> V_8 , V_34 , V_67 ) ;
F_20 ( V_6 -> V_8 , V_34 , & V_67 ) ;
}
if ( V_67 & V_68 )
return 1 ;
else
return 0 ;
}
static void F_22 ( struct V_1 * V_6 , bool V_69 )
{
T_2 V_70 ;
struct V_2 * V_3 = V_6 -> V_3 ;
if ( F_23 ( V_3 ) != V_12 ||
F_16 ( V_3 ) < 7 )
return;
V_70 = F_9 ( V_6 -> V_5 , V_39 , V_71 ) ;
if ( V_69 )
V_70 |= V_72 ;
else
V_70 &= ~ V_72 ;
F_13 ( V_6 -> V_5 , V_39 , V_71 , V_70 ) ;
V_70 = F_9 ( V_6 -> V_5 , V_39 , V_71 ) ;
}
static void F_24 ( struct V_1 * V_6 , T_3 V_73 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
switch ( V_73 ) {
case V_74 :
if ( F_25 ( V_3 ) )
F_19 ( V_6 , 1 , 0 ) ;
break;
case V_75 :
if ( F_16 ( V_3 ) == 6 ) {
F_26 ( V_3 ,
F_27 ( struct V_76 , V_77 ) ,
~ 0 , 0 ) ;
F_26 ( V_3 ,
F_27 ( struct V_76 , V_78 ) ,
~ 0x40 , 0 ) ;
} else if ( V_6 -> V_79 ) {
F_19 ( V_6 , 1 , 1 ) ;
}
break;
case V_80 :
if ( F_16 ( V_3 ) == 6 ) {
F_26 ( V_3 ,
F_27 ( struct V_76 , V_77 ) ,
~ 0 , 0 ) ;
F_26 ( V_3 ,
F_27 ( struct V_76 , V_78 ) ,
~ 0x40 , 0x40 ) ;
} else if ( F_25 ( V_3 ) ) {
F_19 ( V_6 , 1 , 0 ) ;
}
break;
}
}
static void F_28 ( struct V_1 * V_6 )
{
T_2 V_70 ;
if ( V_6 -> V_81 != 0 )
return;
V_70 = F_9 ( V_6 -> V_5 , V_39 , V_82 ) ;
if ( ( V_70 & V_83 ) == 0 )
V_6 -> V_81 = V_84 ;
else
V_6 -> V_81 = ( V_84 |
V_85 ) ;
}
static void F_29 ( struct V_1 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
T_4 V_86 ;
T_2 V_70 ;
if ( ! F_25 ( V_3 ) )
return;
V_86 = F_30 ( V_6 -> V_5 , F_11 ( V_87 [ V_88 ] ) ) ;
V_86 &= ~ V_89 ;
if ( V_6 -> V_90 == V_91 )
V_86 |= V_89 ;
else if ( V_6 -> V_90 == V_92 )
V_86 |= V_93 ;
else if ( V_6 -> V_90 == V_94 )
V_86 |= V_95 ;
F_31 ( V_6 -> V_5 , F_11 ( V_87 [ V_88 ] ) , V_86 ) ;
F_20 ( V_6 -> V_8 , V_6 -> V_15 , & V_70 ) ;
V_70 &= ~ V_91 ;
V_70 |= V_6 -> V_90 ;
F_21 ( V_6 -> V_8 , V_6 -> V_15 , V_70 ) ;
V_86 = F_30 ( V_6 -> V_5 ,
F_11 ( V_87 [ V_96 ] ) ) ;
if ( V_6 -> V_90 != V_97 ) {
V_86 |= V_98 ;
V_6 -> V_79 = true ;
} else
V_86 &= ~ V_98 ;
F_31 ( V_6 -> V_5 , F_11 ( V_87 [ V_96 ] ) ,
V_86 ) ;
}
static void F_32 ( struct V_1 * V_6 )
{
T_2 V_70 = 0 ;
if ( V_6 -> V_81 != 0 )
F_18 ( V_6 , V_99 , V_100 ,
V_6 -> V_81 ) ;
F_17 ( V_6 , V_101 , V_102 , & V_70 ) ;
if ( V_70 & V_103 ) {
V_70 &= ~ V_103 ;
F_18 ( V_6 , V_101 , V_102 , V_70 ) ;
}
}
static void F_33 ( struct V_1 * V_6 )
{
T_4 V_86 ;
V_86 = F_30 ( V_6 -> V_5 ,
F_11 ( V_87 [ V_104 ] ) ) ;
if ( ( V_86 & V_105 ) == 0 ) {
V_86 |= V_105 ;
F_31 ( V_6 -> V_5 ,
F_11 ( V_87 [ V_104 ] ) , V_86 ) ;
}
}
static void F_34 ( struct V_1 * V_6 )
{
F_26 ( V_6 -> V_3 , F_27 ( struct V_76 , V_106 ) ,
V_107 , V_107 ) ;
F_31 ( V_6 -> V_5 , F_11 ( V_87 [ V_108 ] ) , 0 ) ;
}
static void F_35 ( struct V_1 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
T_2 V_70 ;
if ( F_16 ( V_3 ) == 0 || F_16 ( V_3 ) == 1 ) {
V_70 = F_9 ( V_6 -> V_5 , V_39 ,
V_109 ) ;
V_70 |= 0x8 ;
F_13 ( V_6 -> V_5 , V_39 ,
V_109 , V_70 ) ;
}
if ( F_16 ( V_3 ) == 1 ) {
V_70 = F_9 ( V_6 -> V_5 , V_39 , V_110 ) ;
V_70 |= 0x40 ;
F_13 ( V_6 -> V_5 , V_39 , V_110 , V_70 ) ;
}
if ( F_16 ( V_3 ) == 0 ) {
F_18 ( V_6 , V_99 , V_111 , 0x8128 ) ;
F_18 ( V_6 , V_99 , V_112 , 0x0100 ) ;
F_18 ( V_6 , V_99 , V_113 , 0x1466 ) ;
} else if ( F_25 ( V_3 ) ) {
V_70 = F_9 ( V_6 -> V_5 , V_39 ,
V_71 ) ;
V_70 &= ~ V_114 ;
V_70 |= V_115 << V_116 ;
F_13 ( V_6 -> V_5 , V_39 ,
V_71 , V_70 ) ;
F_32 ( V_6 ) ;
F_29 ( V_6 ) ;
} else if ( F_16 ( V_6 -> V_3 ) == 7 )
F_34 ( V_6 ) ;
if ( F_16 ( V_6 -> V_3 ) >= 6 )
F_33 ( V_6 ) ;
}
void F_36 ( struct V_1 * V_6 , int V_73 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
T_2 V_117 = ( T_2 ) F_37 ( V_3 , V_118 ) ;
if ( F_25 ( V_3 ) ) {
if ( V_117 & V_119 )
V_6 -> V_90 = V_97 ;
else
V_6 -> V_90 = V_91 ;
}
F_28 ( V_6 ) ;
F_32 ( V_6 ) ;
F_29 ( V_6 ) ;
F_24 ( V_6 , V_73 ) ;
}
void F_38 ( struct V_1 * V_6 )
{
if ( ! V_6 || F_23 ( V_6 -> V_3 ) != V_12 )
return;
F_35 ( V_6 ) ;
}
void F_39 ( struct V_1 * V_6 , int V_73 )
{
if ( ! V_6 || F_23 ( V_6 -> V_3 ) != V_12 )
return;
F_22 ( V_6 , true ) ;
F_24 ( V_6 , V_73 ) ;
}
void F_40 ( struct V_1 * V_6 )
{
T_2 V_70 ;
if ( ! V_6 || ! F_25 ( V_6 -> V_3 ) )
return;
F_20 ( V_6 -> V_8 , V_6 -> V_15 , & V_70 ) ;
V_70 &= ~ V_120 ;
F_21 ( V_6 -> V_8 , V_6 -> V_15 , V_70 ) ;
V_6 -> V_79 = false ;
}
void F_41 ( struct V_1 * V_6 , int V_73 )
{
if ( ! V_6 || F_23 ( V_6 -> V_3 ) != V_12 )
return;
F_24 ( V_6 , V_73 ) ;
F_22 ( V_6 , false ) ;
}
void F_42 ( struct V_1 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_5 ;
T_4 V_86 ;
T_3 V_121 ;
switch ( V_6 -> V_5 -> V_11 . V_11 ) {
case V_122 :
V_121 = F_43 ( V_87 [ V_123 ] ) ;
break;
case V_124 :
V_121 = F_11 ( V_87 [ V_123 ] ) ;
break;
default:
return;
}
V_86 = F_30 ( V_6 -> V_5 , V_121 ) ;
if ( ( ( V_86 & V_125 ) >> V_126 ) !=
( T_4 ) V_5 -> V_127 ) {
V_86 = ( ( T_4 ) V_5 -> V_127 << V_126 ) |
( V_86 & ~ V_125 ) ;
F_31 ( V_6 -> V_5 , V_121 , V_86 ) ;
}
}
void
F_44 ( struct V_1 * V_6 )
{
F_45 ( V_6 -> V_5 , F_43 ( V_128 ) ,
V_129 | V_130 ) ;
if ( V_6 -> V_5 -> V_11 . V_131 >= 11 ) {
F_45 ( V_6 -> V_5 , F_43 ( V_128 ) ,
V_132 ) ;
F_45 ( V_6 -> V_5 , F_43 ( V_133 ) , V_134 ) ;
( void ) F_12 ( V_6 -> V_5 , F_43 ( V_133 ) ) ;
}
}
