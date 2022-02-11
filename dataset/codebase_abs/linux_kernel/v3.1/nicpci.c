void * F_1 ( struct V_1 * V_2 , void * V_3 , void * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_7 ) ;
if ( V_6 == NULL ) {
F_3 ( ( L_1 ) ) ;
return NULL ;
}
V_6 -> V_2 = V_2 ;
V_6 -> V_8 = V_3 ;
if ( V_2 -> V_9 == V_10 ) {
T_1 V_11 ;
V_6 -> V_4 . V_12 = V_4 ;
V_11 = F_4 ( V_6 -> V_8 , V_13 ,
NULL , NULL ) ;
V_6 -> V_14 = V_11 + V_15 ;
} else
V_6 -> V_4 . V_16 = V_4 ;
return V_6 ;
}
void F_5 ( void * V_17 )
{
F_6 ( V_17 ) ;
}
T_1
F_4 ( void * V_8 , T_1 V_18 ,
unsigned char * V_19 , T_2 * V_20 )
{
T_1 V_21 ;
T_1 V_11 = 0 ;
T_2 V_22 ;
T_1 V_23 ;
F_7 ( V_8 , V_24 , & V_23 ) ;
if ( ( V_23 & 0x7f ) != V_25 )
goto V_26;
F_7 ( V_8 , V_27 , & V_23 ) ;
if ( ! ( V_23 & V_28 ) )
goto V_26;
F_7 ( V_8 , V_29 , & V_11 ) ;
if ( V_11 == 0x00 )
goto V_26;
F_7 ( V_8 , V_11 , & V_21 ) ;
while ( V_21 != V_18 ) {
F_7 ( V_8 , V_11 + 1 , & V_11 ) ;
if ( V_11 == 0x00 )
break;
F_7 ( V_8 , V_11 , & V_21 ) ;
}
if ( V_21 != V_18 )
goto V_26;
if ( V_19 != NULL && V_20 != NULL ) {
T_1 V_30 ;
V_22 = * V_20 ;
if ( ! V_22 )
goto V_26;
* V_20 = 0 ;
V_30 = V_11 + 2 ;
if ( ( V_22 + V_30 ) > V_31 )
V_22 = V_31 - V_30 ;
* V_20 = V_22 ;
while ( V_22 -- ) {
F_7 ( V_8 , V_30 , V_19 ) ;
V_30 ++ ;
V_19 ++ ;
}
}
V_26:
return V_11 ;
}
static T_3
F_8 ( struct V_32 * V_12 , T_3 V_33 , T_3 V_34 )
{
T_3 V_35 = 0xFFFFFFFF ;
switch ( V_33 ) {
case V_36 :
F_9 ( & V_12 -> V_37 , V_34 ) ;
( void ) F_10 ( ( & V_12 -> V_37 ) ) ;
V_35 = F_10 ( & V_12 -> V_38 ) ;
break;
case V_39 :
F_9 ( & V_12 -> V_40 , V_34 ) ;
( void ) F_10 ( & V_12 -> V_40 ) ;
V_35 = F_10 ( & V_12 -> V_41 ) ;
break;
}
return V_35 ;
}
static T_3
F_11 ( struct V_32 * V_12 , T_3 V_33 , T_3 V_34 , T_3 V_42 )
{
switch ( V_33 ) {
case V_36 :
F_9 ( ( & V_12 -> V_37 ) , V_34 ) ;
F_9 ( ( & V_12 -> V_38 ) , V_42 ) ;
break;
case V_39 :
F_9 ( ( & V_12 -> V_40 ) , V_34 ) ;
F_9 ( ( & V_12 -> V_41 ) , V_42 ) ;
break;
default:
break;
}
return 0 ;
}
static bool F_12 ( struct V_5 * V_6 , T_3 V_43 )
{
struct V_32 * V_12 = V_6 -> V_4 . V_12 ;
T_3 V_44 , V_45 = 0 ;
T_3 V_46 = 200 ;
V_44 = ( V_47 | V_48 | V_49 |
( V_50 << V_51 ) |
( V_52 << V_53 ) |
( V_43 << 4 ) ) ;
F_9 ( & V_12 -> V_44 , V_44 ) ;
F_13 () ;
while ( V_45 < V_46 ) {
if ( F_10 ( & V_12 -> V_54 ) & V_55 )
break;
F_14 ( 1000 ) ;
V_45 ++ ;
}
if ( V_45 >= V_46 ) {
F_3 ( ( L_2 ) ) ;
return false ;
}
return true ;
}
static int
F_15 ( struct V_5 * V_6 , T_3 V_56 , T_3 V_57 , bool V_58 ,
T_3 * V_42 )
{
struct V_32 * V_12 = V_6 -> V_4 . V_12 ;
T_3 V_44 ;
T_3 V_45 = 0 ;
T_3 V_46 = 10 ;
F_9 ( & V_12 -> V_54 , V_59 | V_60 ) ;
if ( V_6 -> V_2 -> V_61 >= 10 ) {
if ( ! F_12 ( V_6 , V_56 ) )
return 1 ;
V_44 = ( ( V_50 << V_51 ) |
( V_57 << V_53 ) ) ;
V_46 *= 20 ;
} else {
V_44 = ( ( V_56 << V_62 ) |
( V_57 << V_63 ) ) ;
}
if ( ! V_58 )
V_44 |= ( V_47 | V_64 | V_49 ) ;
else
V_44 |= ( V_47 | V_48 | V_49 |
* V_42 ) ;
F_9 ( & V_12 -> V_44 , V_44 ) ;
F_13 () ;
while ( V_45 < V_46 ) {
if ( F_10 ( & V_12 -> V_54 ) & V_55 ) {
if ( ! V_58 ) {
F_13 () ;
* V_42 = ( F_10 ( & V_12 -> V_44 ) &
V_65 ) ;
}
F_9 ( & V_12 -> V_54 , 0 ) ;
return 0 ;
}
F_14 ( 1000 ) ;
V_45 ++ ;
}
F_3 ( ( L_3 , V_58 ) ) ;
F_9 ( & V_12 -> V_54 , 0 ) ;
return 1 ;
}
static int
F_16 ( struct V_5 * V_6 , T_3 V_56 , T_3 V_57 ,
T_3 * V_66 )
{
return F_15 ( V_6 , V_56 , V_57 , false , V_66 ) ;
}
static int
F_17 ( struct V_5 * V_6 , T_3 V_56 , T_3 V_57 , T_3 V_42 )
{
return F_15 ( V_6 , V_56 , V_57 , true , & V_42 ) ;
}
static T_1 F_18 ( void * V_17 , T_2 V_67 , T_2 V_42 )
{
struct V_5 * V_6 = V_17 ;
T_2 V_68 ;
T_1 V_34 ;
V_34 = V_6 -> V_14 ;
if ( ! V_34 )
return 0 ;
F_19 ( V_6 -> V_8 , V_34 , & V_68 ) ;
if ( V_67 ) {
if ( V_42 )
V_68 |= V_69 ;
else
V_68 &= ~ V_69 ;
F_20 ( V_6 -> V_8 , V_34 , V_68 ) ;
F_19 ( V_6 -> V_8 , V_34 , & V_68 ) ;
}
if ( V_68 & V_69 )
return 1 ;
else
return 0 ;
}
static void F_21 ( struct V_5 * V_6 , bool V_70 )
{
T_2 V_71 ;
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_32 * V_12 = V_6 -> V_4 . V_12 ;
if ( ! F_22 ( V_2 ) || V_2 -> V_61 < 7 )
return;
V_71 = F_8 ( V_12 , V_39 , V_72 ) ;
if ( V_70 )
V_71 |= V_73 ;
else
V_71 &= ~ V_73 ;
F_11 ( V_12 , V_39 , V_72 , V_71 ) ;
V_71 = F_8 ( V_12 , V_39 , V_72 ) ;
}
static void F_23 ( struct V_5 * V_6 , T_3 V_74 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
switch ( V_74 ) {
case V_75 :
if ( F_24 ( V_2 ) )
F_18 ( ( void * ) V_6 , 1 , 0 ) ;
break;
case V_76 :
if ( V_2 -> V_61 == 6 ) {
F_25 ( V_2 , V_77 ,
F_26 ( V_78 , V_79 ) ,
~ 0 , 0 ) ;
F_25 ( V_2 , V_77 ,
F_26 ( V_78 , V_80 ) ,
~ 0x40 , 0 ) ;
} else if ( V_6 -> V_81 ) {
F_18 ( ( void * ) V_6 , 1 , 1 ) ;
}
break;
case V_82 :
if ( V_2 -> V_61 == 6 ) {
F_25 ( V_2 , V_77 ,
F_26 ( V_78 , V_79 ) ,
~ 0 , 0 ) ;
F_25 ( V_2 , V_77 ,
F_26 ( V_78 , V_80 ) ,
~ 0x40 , 0x40 ) ;
} else if ( F_24 ( V_2 ) ) {
F_18 ( ( void * ) V_6 , 1 , 0 ) ;
}
break;
}
}
static void F_27 ( struct V_5 * V_6 )
{
T_2 V_71 ;
if ( V_6 -> V_83 != 0 )
return;
V_71 = F_8 ( V_6 -> V_4 . V_12 , V_39 , V_84 ) ;
if ( ( V_71 & V_85 ) == 0 )
V_6 -> V_83 = V_86 ;
else
V_6 -> V_83 = ( V_86 |
V_87 ) ;
}
static void F_28 ( struct V_5 * V_6 )
{
struct V_32 * V_12 = V_6 -> V_4 . V_12 ;
struct V_1 * V_2 = V_6 -> V_2 ;
T_4 V_88 , * V_89 ;
T_2 V_71 ;
if ( ! F_24 ( V_2 ) )
return;
V_89 = & V_12 -> V_90 [ V_91 ] ;
V_88 = F_10 ( V_89 ) ;
V_88 &= ~ V_92 ;
if ( V_6 -> V_93 == V_94 )
V_88 |= V_92 ;
else if ( V_6 -> V_93 == V_95 )
V_88 |= V_96 ;
else if ( V_6 -> V_93 == V_97 )
V_88 |= V_98 ;
F_9 ( V_89 , V_88 ) ;
F_19 ( V_6 -> V_8 , V_6 -> V_14 , & V_71 ) ;
V_71 &= ~ V_94 ;
V_71 |= V_6 -> V_93 ;
F_20 ( V_6 -> V_8 , V_6 -> V_14 , V_71 ) ;
V_89 = & V_12 -> V_90 [ V_99 ] ;
V_88 = F_10 ( V_89 ) ;
if ( V_6 -> V_93 != V_100 ) {
V_88 |= V_101 ;
V_6 -> V_81 = true ;
} else
V_88 &= ~ V_101 ;
F_9 ( V_89 , V_88 ) ;
}
static void F_29 ( struct V_5 * V_6 )
{
T_2 V_71 = 0 ;
if ( V_6 -> V_83 != 0 )
F_17 ( V_6 , V_102 , V_103 ,
V_6 -> V_83 ) ;
F_16 ( V_6 , V_104 , V_105 , & V_71 ) ;
if ( V_71 & V_106 ) {
V_71 &= ~ V_106 ;
F_17 ( V_6 , V_104 , V_105 , V_71 ) ;
}
}
static void F_30 ( struct V_5 * V_6 )
{
struct V_32 * V_12 = V_6 -> V_4 . V_12 ;
T_4 V_88 , * V_89 ;
V_89 = & V_12 -> V_90 [ V_107 ] ;
V_88 = F_10 ( V_89 ) ;
if ( ( V_88 & V_108 ) == 0 ) {
V_88 |= V_108 ;
F_9 ( V_89 , V_88 ) ;
}
}
static void F_31 ( struct V_5 * V_6 )
{
struct V_32 * V_12 = V_6 -> V_4 . V_12 ;
T_4 * V_89 ;
F_25 ( V_6 -> V_2 , V_77 , F_26 ( V_78 , V_109 ) ,
V_110 , V_110 ) ;
V_89 = & V_12 -> V_90 [ V_111 ] ;
F_9 ( V_89 , 0 ) ;
}
static void F_32 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_32 * V_12 = V_6 -> V_4 . V_12 ;
T_2 V_71 ;
if ( V_2 -> V_61 == 0 || V_2 -> V_61 == 1 ) {
V_71 = F_8 ( V_12 , V_39 ,
V_112 ) ;
V_71 |= 0x8 ;
F_11 ( V_12 , V_39 ,
V_112 , V_71 ) ;
}
if ( V_2 -> V_61 == 1 ) {
V_71 = F_8 ( V_12 , V_39 , V_113 ) ;
V_71 |= 0x40 ;
F_11 ( V_12 , V_39 , V_113 , V_71 ) ;
}
if ( V_2 -> V_61 == 0 ) {
F_17 ( V_6 , V_102 , V_114 , 0x8128 ) ;
F_17 ( V_6 , V_102 , V_115 , 0x0100 ) ;
F_17 ( V_6 , V_102 , V_116 , 0x1466 ) ;
} else if ( F_24 ( V_2 ) ) {
V_71 = F_8 ( V_12 , V_39 ,
V_72 ) ;
V_71 &= ~ V_117 ;
V_71 |= V_118 << V_119 ;
F_11 ( V_12 , V_39 ,
V_72 , V_71 ) ;
F_29 ( V_6 ) ;
F_28 ( V_6 ) ;
} else if ( V_6 -> V_2 -> V_61 == 7 )
F_31 ( V_6 ) ;
if ( V_6 -> V_2 -> V_61 >= 6 )
F_30 ( V_6 ) ;
}
void F_33 ( void * V_17 , char * V_120 , int V_74 )
{
struct V_5 * V_6 = V_17 ;
struct V_1 * V_2 = V_6 -> V_2 ;
if ( F_24 ( V_2 ) ) {
if ( ( T_2 ) F_34 ( V_120 , L_4 ) & V_121 )
V_6 -> V_93 = V_100 ;
else
V_6 -> V_93 = V_94 ;
}
F_27 ( V_6 ) ;
F_29 ( V_6 ) ;
F_28 ( V_6 ) ;
F_23 ( V_6 , V_74 ) ;
}
void F_35 ( void * V_17 )
{
struct V_5 * V_6 = V_17 ;
if ( ! V_6 || ! F_22 ( V_6 -> V_2 ) )
return;
F_32 ( V_6 ) ;
}
void F_36 ( void * V_17 , int V_74 )
{
struct V_5 * V_6 = V_17 ;
if ( ! V_6 || ! F_22 ( V_6 -> V_2 ) )
return;
F_21 ( V_6 , true ) ;
F_23 ( V_6 , V_74 ) ;
}
void F_37 ( void * V_17 )
{
struct V_5 * V_6 = V_17 ;
T_2 V_71 ;
if ( ! V_6 || ! F_24 ( V_6 -> V_2 ) )
return;
F_19 ( V_6 -> V_8 , V_6 -> V_14 , & V_71 ) ;
V_71 &= ~ V_122 ;
F_20 ( V_6 -> V_8 , V_6 -> V_14 , V_71 ) ;
V_6 -> V_81 = false ;
}
void F_38 ( void * V_17 , int V_74 )
{
struct V_5 * V_6 = V_17 ;
if ( ! V_6 || ! F_22 ( V_6 -> V_2 ) )
return;
F_23 ( V_6 , V_74 ) ;
F_21 ( V_6 , false ) ;
}
void F_39 ( void * V_17 , void * V_4 )
{
struct V_5 * V_6 = V_17 ;
struct V_123 * V_124 = F_40 ( V_6 -> V_2 ) ;
struct V_125 * V_16 = V_4 ;
struct V_32 * V_12 = V_4 ;
T_4 V_88 , * V_89 = NULL ;
T_3 V_126 ;
if ( V_124 -> V_127 . V_9 == V_10 )
V_89 = & V_12 -> V_90 [ V_128 ] ;
else if ( V_124 -> V_127 . V_9 == V_129 )
V_89 = & V_16 -> V_90 [ V_128 ] ;
V_126 = F_41 ( & V_124 -> V_127 ) ;
V_88 = F_10 ( V_89 ) ;
if ( ( ( V_88 & V_130 ) >> V_131 ) != ( T_4 ) V_126 ) {
V_88 = ( T_4 ) ( V_126 << V_131 ) |
( V_88 & ~ V_130 ) ;
F_9 ( V_89 , V_88 ) ;
}
}
void F_42 ( void * V_17 , void * V_4 )
{
struct V_5 * V_6 = V_17 ;
struct V_125 * V_16 = V_4 ;
T_2 V_71 ;
F_43 ( & V_16 -> V_132 , V_133 | V_134 ) ;
if ( F_40 ( V_6 -> V_2 ) -> V_127 . V_61 >= 11 ) {
F_43 ( & V_16 -> V_132 , V_135 ) ;
V_71 = F_10 ( & V_16 -> V_136 ) ;
F_9 ( & V_16 -> V_136 , V_71 | V_137 ) ;
V_71 = F_10 ( & V_16 -> V_136 ) ;
}
}
