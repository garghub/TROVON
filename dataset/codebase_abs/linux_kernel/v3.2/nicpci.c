static void F_1 ( void )
{
F_2 ( 10 ) ;
}
struct V_1 * F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
void T_1 * V_6 )
{
struct V_1 * V_7 ;
V_7 = F_4 ( sizeof( struct V_1 ) , V_8 ) ;
if ( V_7 == NULL )
return NULL ;
V_7 -> V_3 = V_3 ;
V_7 -> V_9 = V_5 ;
if ( V_3 -> V_10 == V_11 ) {
T_2 V_12 ;
V_7 -> V_6 . V_13 = V_6 ;
V_12 = F_5 ( V_7 -> V_9 , V_14 ,
NULL , NULL ) ;
V_7 -> V_15 = V_12 + V_16 ;
} else
V_7 -> V_6 . V_17 = V_6 ;
return V_7 ;
}
void F_6 ( struct V_1 * V_18 )
{
F_7 ( V_18 ) ;
}
T_2
F_5 ( struct V_4 * V_9 , T_2 V_19 ,
unsigned char * V_20 , T_3 * V_21 )
{
T_2 V_22 ;
T_2 V_12 = 0 ;
T_3 V_23 ;
T_2 V_24 ;
F_8 ( V_9 , V_25 , & V_24 ) ;
if ( ( V_24 & 0x7f ) != V_26 )
goto V_27;
F_8 ( V_9 , V_28 , & V_24 ) ;
if ( ! ( V_24 & V_29 ) )
goto V_27;
F_8 ( V_9 , V_30 , & V_12 ) ;
if ( V_12 == 0x00 )
goto V_27;
F_8 ( V_9 , V_12 , & V_22 ) ;
while ( V_22 != V_19 ) {
F_8 ( V_9 , V_12 + 1 , & V_12 ) ;
if ( V_12 == 0x00 )
break;
F_8 ( V_9 , V_12 , & V_22 ) ;
}
if ( V_22 != V_19 )
goto V_27;
if ( V_20 != NULL && V_21 != NULL ) {
T_2 V_31 ;
V_23 = * V_21 ;
if ( ! V_23 )
goto V_27;
* V_21 = 0 ;
V_31 = V_12 + 2 ;
if ( ( V_23 + V_31 ) > V_32 )
V_23 = V_32 - V_31 ;
* V_21 = V_23 ;
while ( V_23 -- ) {
F_8 ( V_9 , V_31 , V_20 ) ;
V_31 ++ ;
V_20 ++ ;
}
}
V_27:
return V_12 ;
}
static T_4
F_9 ( struct V_33 T_1 * V_13 , T_4 V_34 , T_4 V_35 )
{
T_4 V_36 = 0xFFFFFFFF ;
switch ( V_34 ) {
case V_37 :
F_10 ( & V_13 -> V_38 , V_35 ) ;
( void ) F_11 ( ( & V_13 -> V_38 ) ) ;
V_36 = F_11 ( & V_13 -> V_39 ) ;
break;
case V_40 :
F_10 ( & V_13 -> V_41 , V_35 ) ;
( void ) F_11 ( & V_13 -> V_41 ) ;
V_36 = F_11 ( & V_13 -> V_42 ) ;
break;
}
return V_36 ;
}
static T_4 F_12 ( struct V_33 T_1 * V_13 , T_4 V_34 ,
T_4 V_35 , T_4 V_43 )
{
switch ( V_34 ) {
case V_37 :
F_10 ( ( & V_13 -> V_38 ) , V_35 ) ;
F_10 ( ( & V_13 -> V_39 ) , V_43 ) ;
break;
case V_40 :
F_10 ( ( & V_13 -> V_41 ) , V_35 ) ;
F_10 ( ( & V_13 -> V_42 ) , V_43 ) ;
break;
default:
break;
}
return 0 ;
}
static bool F_13 ( struct V_1 * V_7 , T_4 V_44 )
{
struct V_33 T_1 * V_13 = V_7 -> V_6 . V_13 ;
T_4 V_45 , V_46 = 0 ;
T_4 V_47 = 200 ;
V_45 = ( V_48 | V_49 | V_50 |
( V_51 << V_52 ) |
( V_53 << V_54 ) |
( V_44 << 4 ) ) ;
F_10 ( & V_13 -> V_45 , V_45 ) ;
F_1 () ;
while ( V_46 < V_47 ) {
if ( F_11 ( & V_13 -> V_55 ) & V_56 )
break;
F_2 ( 1000 ) ;
V_46 ++ ;
}
if ( V_46 >= V_47 )
return false ;
return true ;
}
static int
F_14 ( struct V_1 * V_7 , T_4 V_57 , T_4 V_58 , bool V_59 ,
T_4 * V_43 )
{
struct V_33 T_1 * V_13 = V_7 -> V_6 . V_13 ;
T_4 V_45 ;
T_4 V_46 = 0 ;
T_4 V_47 = 10 ;
F_10 ( & V_13 -> V_55 , V_60 | V_61 ) ;
if ( V_7 -> V_3 -> V_62 >= 10 ) {
if ( ! F_13 ( V_7 , V_57 ) )
return 1 ;
V_45 = ( ( V_51 << V_52 ) |
( V_58 << V_54 ) ) ;
V_47 *= 20 ;
} else {
V_45 = ( ( V_57 << V_63 ) |
( V_58 << V_64 ) ) ;
}
if ( ! V_59 )
V_45 |= ( V_48 | V_65 | V_50 ) ;
else
V_45 |= ( V_48 | V_49 | V_50 |
* V_43 ) ;
F_10 ( & V_13 -> V_45 , V_45 ) ;
F_1 () ;
while ( V_46 < V_47 ) {
if ( F_11 ( & V_13 -> V_55 ) & V_56 ) {
if ( ! V_59 ) {
F_1 () ;
* V_43 = ( F_11 ( & V_13 -> V_45 ) &
V_66 ) ;
}
F_10 ( & V_13 -> V_55 , 0 ) ;
return 0 ;
}
F_2 ( 1000 ) ;
V_46 ++ ;
}
F_10 ( & V_13 -> V_55 , 0 ) ;
return 1 ;
}
static int
F_15 ( struct V_1 * V_7 , T_4 V_57 , T_4 V_58 ,
T_4 * V_67 )
{
return F_14 ( V_7 , V_57 , V_58 , false , V_67 ) ;
}
static int
F_16 ( struct V_1 * V_7 , T_4 V_57 , T_4 V_58 , T_4 V_43 )
{
return F_14 ( V_7 , V_57 , V_58 , true , & V_43 ) ;
}
static T_2 F_17 ( struct V_1 * V_7 , T_3 V_68 , T_3 V_43 )
{
T_3 V_69 ;
T_2 V_35 ;
V_35 = V_7 -> V_15 ;
if ( ! V_35 )
return 0 ;
F_18 ( V_7 -> V_9 , V_35 , & V_69 ) ;
if ( V_68 ) {
if ( V_43 )
V_69 |= V_70 ;
else
V_69 &= ~ V_70 ;
F_19 ( V_7 -> V_9 , V_35 , V_69 ) ;
F_18 ( V_7 -> V_9 , V_35 , & V_69 ) ;
}
if ( V_69 & V_70 )
return 1 ;
else
return 0 ;
}
static void F_20 ( struct V_1 * V_7 , bool V_71 )
{
T_3 V_72 ;
struct V_2 * V_3 = V_7 -> V_3 ;
struct V_33 T_1 * V_13 = V_7 -> V_6 . V_13 ;
if ( V_3 -> V_10 != V_11 || V_3 -> V_62 < 7 )
return;
V_72 = F_9 ( V_13 , V_40 , V_73 ) ;
if ( V_71 )
V_72 |= V_74 ;
else
V_72 &= ~ V_74 ;
F_12 ( V_13 , V_40 , V_73 , V_72 ) ;
V_72 = F_9 ( V_13 , V_40 , V_73 ) ;
}
static void F_21 ( struct V_1 * V_7 , T_4 V_75 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
switch ( V_75 ) {
case V_76 :
if ( F_22 ( V_3 ) )
F_17 ( V_7 , 1 , 0 ) ;
break;
case V_77 :
if ( V_3 -> V_62 == 6 ) {
F_23 ( V_3 , V_78 ,
F_24 ( struct V_79 , V_80 ) ,
~ 0 , 0 ) ;
F_23 ( V_3 , V_78 ,
F_24 ( struct V_79 , V_81 ) ,
~ 0x40 , 0 ) ;
} else if ( V_7 -> V_82 ) {
F_17 ( V_7 , 1 , 1 ) ;
}
break;
case V_83 :
if ( V_3 -> V_62 == 6 ) {
F_23 ( V_3 , V_78 ,
F_24 ( struct V_79 , V_80 ) ,
~ 0 , 0 ) ;
F_23 ( V_3 , V_78 ,
F_24 ( struct V_79 , V_81 ) ,
~ 0x40 , 0x40 ) ;
} else if ( F_22 ( V_3 ) ) {
F_17 ( V_7 , 1 , 0 ) ;
}
break;
}
}
static void F_25 ( struct V_1 * V_7 )
{
T_3 V_72 ;
if ( V_7 -> V_84 != 0 )
return;
V_72 = F_9 ( V_7 -> V_6 . V_13 , V_40 , V_85 ) ;
if ( ( V_72 & V_86 ) == 0 )
V_7 -> V_84 = V_87 ;
else
V_7 -> V_84 = ( V_87 |
V_88 ) ;
}
static void F_26 ( struct V_1 * V_7 )
{
struct V_33 T_1 * V_13 = V_7 -> V_6 . V_13 ;
struct V_2 * V_3 = V_7 -> V_3 ;
T_5 V_89 ;
T_5 T_1 * V_90 ;
T_3 V_72 ;
if ( ! F_22 ( V_3 ) )
return;
V_90 = & V_13 -> V_91 [ V_92 ] ;
V_89 = F_11 ( V_90 ) ;
V_89 &= ~ V_93 ;
if ( V_7 -> V_94 == V_95 )
V_89 |= V_93 ;
else if ( V_7 -> V_94 == V_96 )
V_89 |= V_97 ;
else if ( V_7 -> V_94 == V_98 )
V_89 |= V_99 ;
F_10 ( V_90 , V_89 ) ;
F_18 ( V_7 -> V_9 , V_7 -> V_15 , & V_72 ) ;
V_72 &= ~ V_95 ;
V_72 |= V_7 -> V_94 ;
F_19 ( V_7 -> V_9 , V_7 -> V_15 , V_72 ) ;
V_90 = & V_13 -> V_91 [ V_100 ] ;
V_89 = F_11 ( V_90 ) ;
if ( V_7 -> V_94 != V_101 ) {
V_89 |= V_102 ;
V_7 -> V_82 = true ;
} else
V_89 &= ~ V_102 ;
F_10 ( V_90 , V_89 ) ;
}
static void F_27 ( struct V_1 * V_7 )
{
T_3 V_72 = 0 ;
if ( V_7 -> V_84 != 0 )
F_16 ( V_7 , V_103 , V_104 ,
V_7 -> V_84 ) ;
F_15 ( V_7 , V_105 , V_106 , & V_72 ) ;
if ( V_72 & V_107 ) {
V_72 &= ~ V_107 ;
F_16 ( V_7 , V_105 , V_106 , V_72 ) ;
}
}
static void F_28 ( struct V_1 * V_7 )
{
struct V_33 T_1 * V_13 = V_7 -> V_6 . V_13 ;
T_5 V_89 ;
T_5 T_1 * V_90 ;
V_90 = & V_13 -> V_91 [ V_108 ] ;
V_89 = F_11 ( V_90 ) ;
if ( ( V_89 & V_109 ) == 0 ) {
V_89 |= V_109 ;
F_10 ( V_90 , V_89 ) ;
}
}
static void F_29 ( struct V_1 * V_7 )
{
struct V_33 T_1 * V_13 = V_7 -> V_6 . V_13 ;
T_5 T_1 * V_90 ;
F_23 ( V_7 -> V_3 , V_78 , F_24 ( struct V_79 , V_110 ) ,
V_111 , V_111 ) ;
V_90 = & V_13 -> V_91 [ V_112 ] ;
F_10 ( V_90 , 0 ) ;
}
static void F_30 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
struct V_33 T_1 * V_13 = V_7 -> V_6 . V_13 ;
T_3 V_72 ;
if ( V_3 -> V_62 == 0 || V_3 -> V_62 == 1 ) {
V_72 = F_9 ( V_13 , V_40 ,
V_113 ) ;
V_72 |= 0x8 ;
F_12 ( V_13 , V_40 ,
V_113 , V_72 ) ;
}
if ( V_3 -> V_62 == 1 ) {
V_72 = F_9 ( V_13 , V_40 , V_114 ) ;
V_72 |= 0x40 ;
F_12 ( V_13 , V_40 , V_114 , V_72 ) ;
}
if ( V_3 -> V_62 == 0 ) {
F_16 ( V_7 , V_103 , V_115 , 0x8128 ) ;
F_16 ( V_7 , V_103 , V_116 , 0x0100 ) ;
F_16 ( V_7 , V_103 , V_117 , 0x1466 ) ;
} else if ( F_22 ( V_3 ) ) {
V_72 = F_9 ( V_13 , V_40 ,
V_73 ) ;
V_72 &= ~ V_118 ;
V_72 |= V_119 << V_120 ;
F_12 ( V_13 , V_40 ,
V_73 , V_72 ) ;
F_27 ( V_7 ) ;
F_26 ( V_7 ) ;
} else if ( V_7 -> V_3 -> V_62 == 7 )
F_29 ( V_7 ) ;
if ( V_7 -> V_3 -> V_62 >= 6 )
F_28 ( V_7 ) ;
}
void F_31 ( struct V_1 * V_7 , int V_75 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
T_3 V_121 = ( T_3 ) F_32 ( V_3 , V_122 ) ;
if ( F_22 ( V_3 ) ) {
if ( V_121 & V_123 )
V_7 -> V_94 = V_101 ;
else
V_7 -> V_94 = V_95 ;
}
F_25 ( V_7 ) ;
F_27 ( V_7 ) ;
F_26 ( V_7 ) ;
F_21 ( V_7 , V_75 ) ;
}
void F_33 ( struct V_1 * V_7 )
{
if ( ! V_7 || V_7 -> V_3 -> V_10 != V_11 )
return;
F_30 ( V_7 ) ;
}
void F_34 ( struct V_1 * V_7 , int V_75 )
{
if ( ! V_7 || V_7 -> V_3 -> V_10 != V_11 )
return;
F_20 ( V_7 , true ) ;
F_21 ( V_7 , V_75 ) ;
}
void F_35 ( struct V_1 * V_7 )
{
T_3 V_72 ;
if ( ! V_7 || ! F_22 ( V_7 -> V_3 ) )
return;
F_18 ( V_7 -> V_9 , V_7 -> V_15 , & V_72 ) ;
V_72 &= ~ V_124 ;
F_19 ( V_7 -> V_9 , V_7 -> V_15 , V_72 ) ;
V_7 -> V_82 = false ;
}
void F_36 ( struct V_1 * V_7 , int V_75 )
{
if ( ! V_7 || V_7 -> V_3 -> V_10 != V_11 )
return;
F_21 ( V_7 , V_75 ) ;
F_20 ( V_7 , false ) ;
}
static void F_37 ( struct V_1 * V_7 , T_5 T_1 * V_90 )
{
struct V_125 * V_126 = (struct V_125 * ) ( V_7 -> V_3 ) ;
T_5 V_89 ;
T_4 V_127 ;
V_127 = F_38 ( & V_126 -> V_128 ) ;
V_89 = F_11 ( V_90 ) ;
if ( ( ( V_89 & V_129 ) >> V_130 ) != ( T_5 ) V_127 ) {
V_89 = ( T_5 ) ( V_127 << V_130 ) |
( V_89 & ~ V_129 ) ;
F_10 ( V_90 , V_89 ) ;
}
}
void
F_39 ( struct V_1 * V_7 , struct V_131 T_1 * V_17 )
{
F_37 ( V_7 , & V_17 -> V_91 [ V_132 ] ) ;
}
void F_40 ( struct V_1 * V_7 ,
struct V_33 T_1 * V_13 )
{
F_37 ( V_7 , & V_13 -> V_91 [ V_132 ] ) ;
}
void
F_41 ( struct V_1 * V_7 , struct V_131 T_1 * V_17 )
{
T_3 V_72 ;
F_42 ( & V_17 -> V_133 , V_134 | V_135 ) ;
if ( ( (struct V_125 * ) ( V_7 -> V_3 ) ) -> V_128 . V_62 >= 11 ) {
F_42 ( & V_17 -> V_133 , V_136 ) ;
V_72 = F_11 ( & V_17 -> V_137 ) ;
F_10 ( & V_17 -> V_137 , V_72 | V_138 ) ;
V_72 = F_11 ( & V_17 -> V_137 ) ;
}
}
