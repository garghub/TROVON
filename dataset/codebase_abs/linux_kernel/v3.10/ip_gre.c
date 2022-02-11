static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
switch ( V_2 -> V_4 ) {
case V_5 :
V_3 = F_2 ( V_2 -> V_3 ) ;
if ( ! V_3 )
break;
case V_6 :
V_2 -> V_3 = 0 ;
V_3 = F_3 ( V_2 ) ;
V_2 -> V_4 = V_5 ;
break;
}
return V_3 ;
}
static int F_4 ( T_2 V_7 )
{
int V_8 = 4 ;
if ( V_7 & V_9 )
V_8 += 4 ;
if ( V_7 & V_10 )
V_8 += 4 ;
if ( V_7 & V_11 )
V_8 += 4 ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_12 * V_13 ,
bool * V_14 , int * V_15 )
{
unsigned int V_16 = F_6 ( V_2 ) ;
const struct V_17 * V_18 ;
T_3 * V_19 ;
if ( F_7 ( ! F_8 ( V_2 , sizeof( struct V_17 ) ) ) )
return - V_20 ;
V_18 = (struct V_17 * ) ( F_9 ( V_2 ) + V_16 ) ;
if ( F_7 ( V_18 -> V_21 & ( V_22 | V_23 ) ) )
return - V_20 ;
V_13 -> V_21 = F_10 ( V_18 -> V_21 ) ;
* V_15 = F_4 ( V_13 -> V_21 ) ;
if ( ! F_8 ( V_2 , * V_15 ) )
return - V_20 ;
V_18 = (struct V_17 * ) ( F_9 ( V_2 ) + V_16 ) ;
V_13 -> V_24 = V_18 -> V_25 ;
V_19 = ( T_3 * ) ( V_18 + 1 ) ;
if ( V_18 -> V_21 & V_26 ) {
if ( F_1 ( V_2 ) ) {
* V_14 = true ;
return - V_20 ;
}
V_19 ++ ;
}
if ( V_18 -> V_21 & V_27 ) {
V_13 -> V_28 = * V_19 ;
V_19 ++ ;
} else
V_13 -> V_28 = 0 ;
if ( F_7 ( V_18 -> V_21 & V_29 ) ) {
V_13 -> V_30 = * V_19 ;
V_19 ++ ;
} else
V_13 -> V_30 = 0 ;
if ( V_18 -> V_21 == 0 && V_13 -> V_24 == F_11 ( V_31 ) ) {
V_13 -> V_24 = F_11 ( V_32 ) ;
if ( ( * ( V_33 * ) V_19 & 0xF0 ) != 0x40 ) {
* V_15 += 4 ;
if ( ! F_8 ( V_2 , * V_15 ) )
return - V_20 ;
}
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , T_4 V_34 )
{
struct V_35 * V_35 = F_13 ( V_2 -> V_36 ) ;
struct V_37 * V_38 ;
const struct V_39 * V_40 ;
const int type = F_14 ( V_2 ) -> type ;
const int V_41 = F_14 ( V_2 ) -> V_41 ;
struct V_42 * V_43 ;
struct V_12 V_13 ;
int V_15 ;
bool V_14 = false ;
if ( F_5 ( V_2 , & V_13 , & V_14 , & V_15 ) ) {
if ( ! V_14 )
return;
}
switch ( type ) {
default:
case V_44 :
return;
case V_45 :
switch ( V_41 ) {
case V_46 :
case V_47 :
return;
default:
break;
}
break;
case V_48 :
if ( V_41 != V_49 )
return;
break;
case V_50 :
break;
}
if ( V_13 . V_24 == F_11 ( V_51 ) )
V_38 = F_15 ( V_35 , V_52 ) ;
else
V_38 = F_15 ( V_35 , V_53 ) ;
V_40 = ( const struct V_39 * ) V_2 -> V_54 ;
V_43 = F_16 ( V_38 , V_2 -> V_36 -> V_55 , V_13 . V_21 ,
V_40 -> V_56 , V_40 -> V_57 , V_13 . V_28 ) ;
if ( V_43 == NULL )
return;
if ( type == V_45 && V_41 == V_58 ) {
F_17 ( V_2 , F_13 ( V_2 -> V_36 ) , V_34 ,
V_43 -> V_59 . V_60 , 0 , V_61 , 0 ) ;
return;
}
if ( type == V_50 ) {
F_18 ( V_2 , F_13 ( V_2 -> V_36 ) , V_43 -> V_59 . V_60 , 0 ,
V_61 , 0 ) ;
return;
}
if ( V_43 -> V_59 . V_40 . V_56 == 0 ||
F_19 ( V_43 -> V_59 . V_40 . V_56 ) )
return;
if ( V_43 -> V_59 . V_40 . V_62 == 0 && type == V_48 )
return;
if ( F_20 ( V_63 , V_43 -> V_64 + V_65 ) )
V_43 -> V_66 ++ ;
else
V_43 -> V_66 = 1 ;
V_43 -> V_64 = V_63 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_35 * V_35 = F_13 ( V_2 -> V_36 ) ;
struct V_37 * V_38 ;
const struct V_39 * V_40 ;
struct V_42 * V_67 ;
struct V_12 V_13 ;
int V_15 ;
bool V_14 = false ;
if ( F_5 ( V_2 , & V_13 , & V_14 , & V_15 ) < 0 )
goto V_68;
if ( V_13 . V_24 == F_11 ( V_51 ) )
V_38 = F_15 ( V_35 , V_52 ) ;
else
V_38 = F_15 ( V_35 , V_53 ) ;
V_40 = F_22 ( V_2 ) ;
V_67 = F_16 ( V_38 , V_2 -> V_36 -> V_55 , V_13 . V_21 ,
V_40 -> V_57 , V_40 -> V_56 , V_13 . V_28 ) ;
if ( V_67 ) {
F_23 ( V_67 , V_2 , & V_13 , V_69 ) ;
return 0 ;
}
F_24 ( V_2 , V_45 , V_47 , 0 ) ;
V_68:
F_25 ( V_2 ) ;
return 0 ;
}
static struct V_1 * F_26 ( struct V_42 * V_67 , struct V_1 * V_2 )
{
int V_70 ;
if ( F_27 ( V_2 ) ) {
V_70 = F_28 ( V_2 , V_71 ) ;
if ( F_7 ( V_70 ) )
goto error;
F_29 ( V_2 ) -> V_72 |= V_73 ;
return V_2 ;
} else if ( V_2 -> V_4 == V_74 &&
V_67 -> V_59 . V_7 & V_9 ) {
V_70 = F_30 ( V_2 ) ;
if ( F_7 ( V_70 ) )
goto error;
} else if ( V_2 -> V_4 != V_74 )
V_2 -> V_4 = V_6 ;
return V_2 ;
error:
F_25 ( V_2 ) ;
return F_31 ( V_70 ) ;
}
static struct V_1 * F_32 ( struct V_1 * V_2 ,
const struct V_12 * V_13 ,
int V_15 )
{
struct V_17 * V_18 ;
F_33 ( V_2 , V_15 ) ;
V_18 = (struct V_17 * ) V_2 -> V_54 ;
V_18 -> V_21 = F_34 ( V_13 -> V_21 ) ;
V_18 -> V_25 = V_13 -> V_24 ;
if ( V_13 -> V_21 & ( V_10 | V_9 | V_11 ) ) {
T_3 * V_75 = ( T_3 * ) ( ( ( V_33 * ) V_18 ) + V_15 - 4 ) ;
if ( V_13 -> V_21 & V_11 ) {
* V_75 = V_13 -> V_30 ;
V_75 -- ;
}
if ( V_13 -> V_21 & V_10 ) {
* V_75 = V_13 -> V_28 ;
V_75 -- ;
}
if ( V_13 -> V_21 & V_9 &&
! ( F_29 ( V_2 ) -> V_72 & V_73 ) ) {
* ( T_1 * ) V_75 = 0 ;
* ( T_1 * ) V_75 = F_2 ( F_35 ( V_2 , 0 ,
V_2 -> V_76 , 0 ) ) ;
}
}
return V_2 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_77 * V_36 ,
const struct V_39 * V_78 ,
T_2 V_24 )
{
struct V_42 * V_67 = F_37 ( V_36 ) ;
struct V_12 V_13 ;
if ( F_38 ( ! V_2 -> V_79 ) ) {
F_39 ( V_2 ) ;
V_2 -> V_79 = 1 ;
}
V_13 . V_21 = V_67 -> V_59 . V_7 ;
V_13 . V_24 = V_24 ;
V_13 . V_28 = V_67 -> V_59 . V_80 ;
if ( V_67 -> V_59 . V_7 & V_11 )
V_67 -> V_81 ++ ;
V_13 . V_30 = F_40 ( V_67 -> V_81 ) ;
V_2 = F_32 ( V_2 , & V_13 , V_67 -> V_82 ) ;
if ( F_7 ( ! V_2 ) ) {
V_36 -> V_83 . V_84 ++ ;
return;
}
F_41 ( V_2 , V_36 , V_78 ) ;
}
static T_5 F_42 ( struct V_1 * V_2 ,
struct V_77 * V_36 )
{
struct V_42 * V_67 = F_37 ( V_36 ) ;
const struct V_39 * V_78 ;
V_2 = F_26 ( V_67 , V_2 ) ;
if ( F_43 ( V_2 ) )
goto V_85;
if ( V_36 -> V_86 ) {
if ( F_44 ( V_2 , V_36 -> V_87 -
( V_67 -> V_82 + sizeof( struct V_39 ) ) ) )
goto V_88;
V_78 = ( const struct V_39 * ) V_2 -> V_54 ;
F_45 ( V_2 , V_67 -> V_82 + sizeof( struct V_39 ) ) ;
} else {
if ( F_44 ( V_2 , V_36 -> V_87 ) )
goto V_88;
V_78 = & V_67 -> V_59 . V_40 ;
}
F_36 ( V_2 , V_36 , V_78 , V_2 -> V_25 ) ;
return V_89 ;
V_88:
F_46 ( V_2 ) ;
V_85:
V_36 -> V_83 . V_84 ++ ;
return V_89 ;
}
static T_5 F_47 ( struct V_1 * V_2 ,
struct V_77 * V_36 )
{
struct V_42 * V_67 = F_37 ( V_36 ) ;
V_2 = F_26 ( V_67 , V_2 ) ;
if ( F_43 ( V_2 ) )
goto V_85;
if ( F_44 ( V_2 , V_36 -> V_87 ) )
goto V_88;
F_36 ( V_2 , V_36 , & V_67 -> V_59 . V_40 , F_11 ( V_51 ) ) ;
return V_89 ;
V_88:
F_46 ( V_2 ) ;
V_85:
V_36 -> V_83 . V_84 ++ ;
return V_89 ;
}
static int F_48 ( struct V_77 * V_36 ,
struct V_90 * V_91 , int V_92 )
{
int V_70 = 0 ;
struct V_93 V_94 ;
if ( F_49 ( & V_94 , V_91 -> V_95 . V_96 , sizeof( V_94 ) ) )
return - V_97 ;
if ( V_94 . V_40 . V_98 != 4 || V_94 . V_40 . V_25 != V_61 ||
V_94 . V_40 . V_99 != 5 || ( V_94 . V_40 . V_100 & F_11 ( ~ V_101 ) ) ||
( ( V_94 . V_102 | V_94 . V_7 ) & ( V_22 | V_23 ) ) ) {
return - V_20 ;
}
V_94 . V_102 = F_10 ( V_94 . V_102 ) ;
V_94 . V_7 = F_10 ( V_94 . V_7 ) ;
V_70 = F_50 ( V_36 , & V_94 , V_92 ) ;
if ( V_70 )
return V_70 ;
V_94 . V_102 = F_34 ( V_94 . V_102 ) ;
V_94 . V_7 = F_34 ( V_94 . V_7 ) ;
if ( F_51 ( V_91 -> V_95 . V_96 , & V_94 , sizeof( V_94 ) ) )
return - V_97 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_77 * V_36 ,
unsigned short type ,
const void * V_56 , const void * V_57 , unsigned int V_76 )
{
struct V_42 * V_43 = F_37 ( V_36 ) ;
struct V_39 * V_40 ;
struct V_17 * V_18 ;
V_40 = (struct V_39 * ) F_33 ( V_2 , V_43 -> V_82 + sizeof( * V_40 ) ) ;
V_18 = (struct V_17 * ) ( V_40 + 1 ) ;
V_18 -> V_21 = F_34 ( V_43 -> V_59 . V_7 ) ;
V_18 -> V_25 = F_11 ( type ) ;
memcpy ( V_40 , & V_43 -> V_59 . V_40 , sizeof( struct V_39 ) ) ;
if ( V_57 )
memcpy ( & V_40 -> V_57 , V_57 , 4 ) ;
if ( V_56 )
memcpy ( & V_40 -> V_56 , V_56 , 4 ) ;
if ( V_40 -> V_56 )
return V_43 -> V_82 ;
return - ( V_43 -> V_82 + sizeof( * V_40 ) ) ;
}
static int F_53 ( const struct V_1 * V_2 , unsigned char * V_103 )
{
const struct V_39 * V_40 = ( const struct V_39 * ) F_54 ( V_2 ) ;
memcpy ( V_103 , & V_40 -> V_57 , 4 ) ;
return 4 ;
}
static int F_55 ( struct V_77 * V_36 )
{
struct V_42 * V_43 = F_37 ( V_36 ) ;
if ( F_19 ( V_43 -> V_59 . V_40 . V_56 ) ) {
struct V_104 V_105 ;
struct V_106 * V_107 ;
V_107 = F_56 ( F_13 ( V_36 ) , & V_105 ,
V_43 -> V_59 . V_40 . V_56 ,
V_43 -> V_59 . V_40 . V_57 ,
V_43 -> V_59 . V_80 ,
F_57 ( V_43 -> V_59 . V_40 . V_108 ) ,
V_43 -> V_59 . V_60 ) ;
if ( F_43 ( V_107 ) )
return - V_109 ;
V_36 = V_107 -> V_110 . V_36 ;
F_58 ( V_107 ) ;
if ( F_59 ( V_36 ) == NULL )
return - V_109 ;
V_43 -> V_111 = V_36 -> V_55 ;
F_60 ( F_59 ( V_36 ) , V_43 -> V_59 . V_40 . V_56 ) ;
}
return 0 ;
}
static int F_61 ( struct V_77 * V_36 )
{
struct V_42 * V_43 = F_37 ( V_36 ) ;
if ( F_19 ( V_43 -> V_59 . V_40 . V_56 ) && V_43 -> V_111 ) {
struct V_112 * V_113 ;
V_113 = F_62 ( F_13 ( V_36 ) , V_43 -> V_111 ) ;
if ( V_113 )
F_63 ( V_113 , V_43 -> V_59 . V_40 . V_56 ) ;
}
return 0 ;
}
static void F_64 ( struct V_77 * V_36 )
{
V_36 -> V_114 = & V_115 ;
F_65 ( V_36 , V_53 ) ;
}
static void F_66 ( struct V_77 * V_36 )
{
struct V_42 * V_67 ;
V_67 = F_37 ( V_36 ) ;
V_67 -> V_82 = F_4 ( V_67 -> V_59 . V_7 ) ;
V_67 -> V_59 . V_40 . V_25 = V_61 ;
V_36 -> V_87 = V_116 + sizeof( struct V_39 ) + 4 ;
V_36 -> V_117 = V_118 - sizeof( struct V_39 ) - 4 ;
V_36 -> V_119 |= V_120 | V_121 ;
V_36 -> V_122 |= V_121 ;
if ( ! ( V_67 -> V_59 . V_7 & V_11 ) ) {
V_36 -> V_119 |= V_123 ;
V_36 -> V_122 |= V_123 ;
V_36 -> V_119 |= V_124 ;
}
}
static int F_67 ( struct V_77 * V_36 )
{
struct V_42 * V_67 = F_37 ( V_36 ) ;
struct V_39 * V_40 = & V_67 -> V_59 . V_40 ;
F_66 ( V_36 ) ;
memcpy ( V_36 -> V_125 , & V_40 -> V_57 , 4 ) ;
memcpy ( V_36 -> V_126 , & V_40 -> V_56 , 4 ) ;
V_36 -> type = V_127 ;
V_36 -> V_21 = V_128 ;
V_36 -> V_129 &= ~ V_130 ;
V_36 -> V_131 = 4 ;
if ( V_40 -> V_56 ) {
#ifdef F_68
if ( F_19 ( V_40 -> V_56 ) ) {
if ( ! V_40 -> V_57 )
return - V_20 ;
V_36 -> V_21 = V_132 ;
V_36 -> V_86 = & V_133 ;
}
#endif
} else
V_36 -> V_86 = & V_133 ;
return F_69 ( V_36 ) ;
}
static int T_6 F_70 ( struct V_35 * V_35 )
{
return F_71 ( V_35 , V_53 , & V_134 , NULL ) ;
}
static void T_7 F_72 ( struct V_35 * V_35 )
{
struct V_37 * V_38 = F_15 ( V_35 , V_53 ) ;
F_73 ( V_38 ) ;
}
static int F_74 ( struct V_135 * V_136 [] , struct V_135 * V_54 [] )
{
T_2 V_21 ;
if ( ! V_54 )
return 0 ;
V_21 = 0 ;
if ( V_54 [ V_137 ] )
V_21 |= F_75 ( V_54 [ V_137 ] ) ;
if ( V_54 [ V_138 ] )
V_21 |= F_75 ( V_54 [ V_138 ] ) ;
if ( V_21 & ( V_22 | V_23 ) )
return - V_20 ;
return 0 ;
}
static int F_76 ( struct V_135 * V_136 [] , struct V_135 * V_54 [] )
{
T_3 V_56 ;
if ( V_136 [ V_139 ] ) {
if ( F_77 ( V_136 [ V_139 ] ) != V_140 )
return - V_20 ;
if ( ! F_78 ( F_79 ( V_136 [ V_139 ] ) ) )
return - V_109 ;
}
if ( ! V_54 )
goto V_85;
if ( V_54 [ V_141 ] ) {
memcpy ( & V_56 , F_79 ( V_54 [ V_141 ] ) , 4 ) ;
if ( ! V_56 )
return - V_20 ;
}
V_85:
return F_74 ( V_136 , V_54 ) ;
}
static void F_80 ( struct V_135 * V_54 [] , struct V_135 * V_136 [] ,
struct V_93 * V_59 )
{
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_59 -> V_40 . V_25 = V_61 ;
if ( ! V_54 )
return;
if ( V_54 [ V_142 ] )
V_59 -> V_60 = F_81 ( V_54 [ V_142 ] ) ;
if ( V_54 [ V_137 ] )
V_59 -> V_102 = F_10 ( F_75 ( V_54 [ V_137 ] ) ) ;
if ( V_54 [ V_138 ] )
V_59 -> V_7 = F_10 ( F_75 ( V_54 [ V_138 ] ) ) ;
if ( V_54 [ V_143 ] )
V_59 -> V_144 = F_82 ( V_54 [ V_143 ] ) ;
if ( V_54 [ V_145 ] )
V_59 -> V_80 = F_82 ( V_54 [ V_145 ] ) ;
if ( V_54 [ V_146 ] )
V_59 -> V_40 . V_57 = F_82 ( V_54 [ V_146 ] ) ;
if ( V_54 [ V_141 ] )
V_59 -> V_40 . V_56 = F_82 ( V_54 [ V_141 ] ) ;
if ( V_54 [ V_147 ] )
V_59 -> V_40 . V_62 = F_83 ( V_54 [ V_147 ] ) ;
if ( V_54 [ V_148 ] )
V_59 -> V_40 . V_108 = F_83 ( V_54 [ V_148 ] ) ;
if ( ! V_54 [ V_149 ] || F_83 ( V_54 [ V_149 ] ) )
V_59 -> V_40 . V_100 = F_11 ( V_101 ) ;
}
static int F_84 ( struct V_77 * V_36 )
{
F_66 ( V_36 ) ;
return F_69 ( V_36 ) ;
}
static void F_85 ( struct V_77 * V_36 )
{
F_86 ( V_36 ) ;
V_36 -> V_114 = & V_150 ;
F_65 ( V_36 , V_52 ) ;
}
static int F_87 ( struct V_35 * V_151 , struct V_77 * V_36 ,
struct V_135 * V_136 [] , struct V_135 * V_54 [] )
{
struct V_93 V_94 ;
F_80 ( V_54 , V_136 , & V_94 ) ;
return F_88 ( V_36 , V_136 , & V_94 ) ;
}
static int F_89 ( struct V_77 * V_36 , struct V_135 * V_136 [] ,
struct V_135 * V_54 [] )
{
struct V_93 V_94 ;
F_80 ( V_54 , V_136 , & V_94 ) ;
return F_90 ( V_36 , V_136 , & V_94 ) ;
}
static T_8 F_91 ( const struct V_77 * V_36 )
{
return
F_92 ( 4 ) +
F_92 ( 2 ) +
F_92 ( 2 ) +
F_92 ( 4 ) +
F_92 ( 4 ) +
F_92 ( 4 ) +
F_92 ( 4 ) +
F_92 ( 1 ) +
F_92 ( 1 ) +
F_92 ( 1 ) +
0 ;
}
static int F_93 ( struct V_1 * V_2 , const struct V_77 * V_36 )
{
struct V_42 * V_43 = F_37 ( V_36 ) ;
struct V_93 * V_94 = & V_43 -> V_59 ;
if ( F_94 ( V_2 , V_142 , V_94 -> V_60 ) ||
F_95 ( V_2 , V_137 , F_34 ( V_94 -> V_102 ) ) ||
F_95 ( V_2 , V_138 , F_34 ( V_94 -> V_7 ) ) ||
F_96 ( V_2 , V_143 , V_94 -> V_144 ) ||
F_96 ( V_2 , V_145 , V_94 -> V_80 ) ||
F_96 ( V_2 , V_146 , V_94 -> V_40 . V_57 ) ||
F_96 ( V_2 , V_141 , V_94 -> V_40 . V_56 ) ||
F_97 ( V_2 , V_147 , V_94 -> V_40 . V_62 ) ||
F_97 ( V_2 , V_148 , V_94 -> V_40 . V_108 ) ||
F_97 ( V_2 , V_149 ,
! ! ( V_94 -> V_40 . V_100 & F_11 ( V_101 ) ) ) )
goto V_152;
return 0 ;
V_152:
return - V_153 ;
}
static int T_6 F_98 ( struct V_35 * V_35 )
{
return F_71 ( V_35 , V_52 , & V_154 , NULL ) ;
}
static void T_7 F_99 ( struct V_35 * V_35 )
{
struct V_37 * V_38 = F_15 ( V_35 , V_52 ) ;
F_73 ( V_38 ) ;
}
static int T_9 F_100 ( void )
{
int V_70 ;
F_101 ( L_1 ) ;
V_70 = F_102 ( & V_155 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_102 ( & V_156 ) ;
if ( V_70 < 0 )
goto V_157;
V_70 = F_103 ( & V_158 , V_159 ) ;
if ( V_70 < 0 ) {
F_101 ( L_2 , V_160 ) ;
goto V_161;
}
V_70 = F_104 ( & V_134 ) ;
if ( V_70 < 0 )
goto V_162;
V_70 = F_104 ( & V_154 ) ;
if ( V_70 < 0 )
goto V_163;
return 0 ;
V_163:
F_105 ( & V_134 ) ;
V_162:
F_106 ( & V_158 , V_159 ) ;
V_161:
F_107 ( & V_156 ) ;
V_157:
F_107 ( & V_155 ) ;
return V_70 ;
}
static void T_10 F_108 ( void )
{
F_105 ( & V_154 ) ;
F_105 ( & V_134 ) ;
if ( F_106 ( & V_158 , V_159 ) < 0 )
F_101 ( L_3 , V_160 ) ;
F_107 ( & V_156 ) ;
F_107 ( & V_155 ) ;
}
