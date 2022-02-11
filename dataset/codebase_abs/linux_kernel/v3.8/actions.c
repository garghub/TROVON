static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ! F_2 ( V_2 ) || F_3 ( V_2 , V_3 ) )
return 0 ;
return F_4 ( V_2 , 0 , 0 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_9 ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
if ( V_2 -> V_10 == V_11 )
V_2 -> V_12 = F_7 ( V_2 -> V_12 , F_8 ( V_2 -> V_13
+ V_14 , V_15 , 0 ) ) ;
V_7 = (struct V_6 * ) ( V_2 -> V_13 + V_14 ) ;
* V_5 = V_7 -> V_16 ;
memmove ( V_2 -> V_13 + V_15 , V_2 -> V_13 , 2 * V_17 ) ;
F_9 ( V_2 , V_15 ) ;
F_10 ( V_2 , V_7 ) ;
V_2 -> V_18 += V_15 ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_19 ;
int V_8 ;
if ( F_13 ( F_14 ( V_2 ) ) ) {
V_2 -> V_20 = 0 ;
} else {
if ( F_6 ( V_2 -> V_21 != F_15 ( V_22 ) ||
V_2 -> V_23 < V_9 ) )
return 0 ;
V_8 = F_5 ( V_2 , & V_19 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_13 ( V_2 -> V_21 != F_15 ( V_22 ) ||
V_2 -> V_23 < V_9 ) )
return 0 ;
V_8 = F_5 ( V_2 , & V_19 ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
F_16 ( V_2 , F_17 ( V_19 ) ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , const struct V_24 * V_25 )
{
if ( F_6 ( F_14 ( V_2 ) ) ) {
T_2 V_26 ;
V_26 = F_19 ( V_2 ) ;
if ( ! F_20 ( V_2 , V_26 ) )
return - V_27 ;
if ( V_2 -> V_10 == V_11 )
V_2 -> V_12 = F_21 ( V_2 -> V_12 , F_8 ( V_2 -> V_13
+ V_14 , V_15 , 0 ) ) ;
}
F_16 ( V_2 , F_17 ( V_25 -> V_20 ) & ~ V_28 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_29 * V_30 )
{
int V_8 ;
V_8 = F_1 ( V_2 , V_14 ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
memcpy ( F_23 ( V_2 ) -> V_31 , V_30 -> V_32 , V_17 ) ;
memcpy ( F_23 ( V_2 ) -> V_33 , V_30 -> V_34 , V_17 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_35 * V_36 ,
T_3 * V_37 , T_3 V_38 )
{
int V_39 = V_2 -> V_23 - F_25 ( V_2 ) ;
if ( V_36 -> V_21 == V_40 ) {
if ( F_13 ( V_39 >= sizeof( struct V_41 ) ) )
F_26 ( & F_27 ( V_2 ) -> V_42 , V_2 ,
* V_37 , V_38 , 1 ) ;
} else if ( V_36 -> V_21 == V_43 ) {
if ( F_13 ( V_39 >= sizeof( struct V_44 ) ) ) {
struct V_44 * V_45 = F_28 ( V_2 ) ;
if ( V_45 -> V_42 || V_2 -> V_10 == V_46 ) {
F_26 ( & V_45 -> V_42 , V_2 ,
* V_37 , V_38 , 1 ) ;
if ( ! V_45 -> V_42 )
V_45 -> V_42 = V_47 ;
}
}
}
F_29 ( & V_36 -> V_42 , * V_37 , V_38 ) ;
V_2 -> V_48 = 0 ;
* V_37 = V_38 ;
}
static void F_30 ( struct V_1 * V_2 , T_4 V_49 ,
T_3 V_37 [ 4 ] , const T_3 V_38 [ 4 ] )
{
int V_39 = V_2 -> V_23 - F_25 ( V_2 ) ;
if ( V_49 == V_40 ) {
if ( F_13 ( V_39 >= sizeof( struct V_41 ) ) )
F_31 ( & F_27 ( V_2 ) -> V_42 , V_2 ,
V_37 , V_38 , 1 ) ;
} else if ( V_49 == V_43 ) {
if ( F_13 ( V_39 >= sizeof( struct V_44 ) ) ) {
struct V_44 * V_45 = F_28 ( V_2 ) ;
if ( V_45 -> V_42 || V_2 -> V_10 == V_46 ) {
F_31 ( & V_45 -> V_42 , V_2 ,
V_37 , V_38 , 1 ) ;
if ( ! V_45 -> V_42 )
V_45 -> V_42 = V_47 ;
}
}
}
}
static void F_32 ( struct V_1 * V_2 , T_4 V_49 ,
T_3 V_37 [ 4 ] , const T_3 V_38 [ 4 ] ,
bool V_50 )
{
if ( V_50 )
F_30 ( V_2 , V_49 , V_37 , V_38 ) ;
V_2 -> V_48 = 0 ;
memcpy ( V_37 , V_38 , sizeof( T_3 [ 4 ] ) ) ;
}
static void F_33 ( struct V_51 * V_36 , T_4 V_52 )
{
V_36 -> V_53 = V_52 >> 4 ;
V_36 -> V_54 [ 0 ] = ( V_36 -> V_54 [ 0 ] & 0x0F ) | ( ( V_52 & 0x0F ) << 4 ) ;
}
static void F_34 ( struct V_51 * V_36 , T_5 V_55 )
{
V_36 -> V_54 [ 0 ] = ( V_36 -> V_54 [ 0 ] & 0xF0 ) | ( V_55 & 0x000F0000 ) >> 16 ;
V_36 -> V_54 [ 1 ] = ( V_55 & 0x0000FF00 ) >> 8 ;
V_36 -> V_54 [ 2 ] = V_55 & 0x000000FF ;
}
static void F_35 ( struct V_1 * V_2 , struct V_35 * V_36 , T_4 V_56 )
{
F_36 ( & V_36 -> V_42 , F_15 ( V_36 -> V_57 << 8 ) , F_15 ( V_56 << 8 ) ) ;
V_36 -> V_57 = V_56 ;
}
static int F_37 ( struct V_1 * V_2 , const struct V_58 * V_59 )
{
struct V_35 * V_36 ;
int V_8 ;
V_8 = F_1 ( V_2 , F_38 ( V_2 ) +
sizeof( struct V_35 ) ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
V_36 = F_39 ( V_2 ) ;
if ( V_59 -> V_60 != V_36 -> V_61 )
F_24 ( V_2 , V_36 , & V_36 -> V_61 , V_59 -> V_60 ) ;
if ( V_59 -> V_62 != V_36 -> V_63 )
F_24 ( V_2 , V_36 , & V_36 -> V_63 , V_59 -> V_62 ) ;
if ( V_59 -> V_64 != V_36 -> V_65 )
F_40 ( V_36 , 0 , V_59 -> V_64 ) ;
if ( V_59 -> V_66 != V_36 -> V_57 )
F_35 ( V_2 , V_36 , V_59 -> V_66 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , const struct V_67 * V_68 )
{
struct V_51 * V_36 ;
int V_8 ;
T_3 * V_61 ;
T_3 * V_63 ;
V_8 = F_1 ( V_2 , F_38 ( V_2 ) +
sizeof( struct V_51 ) ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
V_36 = F_42 ( V_2 ) ;
V_61 = ( T_3 * ) & V_36 -> V_61 ;
V_63 = ( T_3 * ) & V_36 -> V_63 ;
if ( memcmp ( V_68 -> V_69 , V_61 , sizeof( V_68 -> V_69 ) ) )
F_32 ( V_2 , V_68 -> V_70 , V_61 ,
V_68 -> V_69 , true ) ;
if ( memcmp ( V_68 -> V_71 , V_63 , sizeof( V_68 -> V_71 ) ) ) {
unsigned int V_72 = 0 ;
int V_73 = V_74 ;
bool V_75 = true ;
if ( F_43 ( V_36 -> V_76 ) )
V_75 = F_44 ( V_2 , & V_72 ,
V_77 , NULL ,
& V_73 ) != V_77 ;
F_32 ( V_2 , V_68 -> V_70 , V_63 ,
V_68 -> V_71 , V_75 ) ;
}
F_33 ( V_36 , V_68 -> V_78 ) ;
F_34 ( V_36 , F_45 ( V_68 -> V_79 ) ) ;
V_36 -> V_80 = V_68 -> V_81 ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , T_1 * V_82 ,
T_1 V_83 , T_6 * V_42 )
{
F_47 ( V_42 , V_2 , * V_82 , V_83 , 0 ) ;
* V_82 = V_83 ;
V_2 -> V_48 = 0 ;
}
static void F_48 ( struct V_1 * V_2 , T_1 * V_82 , T_1 V_83 )
{
struct V_44 * V_45 = F_28 ( V_2 ) ;
if ( V_45 -> V_42 && V_2 -> V_10 != V_46 ) {
F_46 ( V_2 , V_82 , V_83 , & V_45 -> V_42 ) ;
if ( ! V_45 -> V_42 )
V_45 -> V_42 = V_47 ;
} else {
* V_82 = V_83 ;
V_2 -> V_48 = 0 ;
}
}
static int F_49 ( struct V_1 * V_2 , const struct V_84 * V_85 )
{
struct V_44 * V_45 ;
int V_8 ;
V_8 = F_1 ( V_2 , F_25 ( V_2 ) +
sizeof( struct V_44 ) ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
V_45 = F_28 ( V_2 ) ;
if ( V_85 -> V_86 != V_45 -> V_87 )
F_48 ( V_2 , & V_45 -> V_87 , V_85 -> V_86 ) ;
if ( V_85 -> V_88 != V_45 -> V_89 )
F_48 ( V_2 , & V_45 -> V_89 , V_85 -> V_88 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , const struct V_90 * V_91 )
{
struct V_41 * V_92 ;
int V_8 ;
V_8 = F_1 ( V_2 , F_25 ( V_2 ) +
sizeof( struct V_41 ) ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
V_92 = F_27 ( V_2 ) ;
if ( V_91 -> V_93 != V_92 -> V_87 )
F_46 ( V_2 , & V_92 -> V_87 , V_91 -> V_93 , & V_92 -> V_42 ) ;
if ( V_91 -> V_94 != V_92 -> V_89 )
F_46 ( V_2 , & V_92 -> V_89 , V_91 -> V_94 , & V_92 -> V_42 ) ;
return 0 ;
}
static int F_51 ( struct V_95 * V_96 , struct V_1 * V_2 , int V_97 )
{
struct V_98 * V_98 ;
if ( F_6 ( ! V_2 ) )
return - V_27 ;
V_98 = F_52 ( V_96 , V_97 ) ;
if ( F_6 ( ! V_98 ) ) {
F_53 ( V_2 ) ;
return - V_99 ;
}
F_54 ( V_98 , V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_95 * V_96 , struct V_1 * V_2 ,
const struct V_100 * V_101 )
{
struct V_102 V_103 ;
const struct V_100 * V_104 ;
int V_105 ;
V_103 . V_106 = V_107 ;
V_103 . V_108 = & F_56 ( V_2 ) -> V_109 -> V_108 ;
V_103 . V_110 = NULL ;
V_103 . V_111 = 0 ;
for ( V_104 = F_57 ( V_101 ) , V_105 = F_58 ( V_101 ) ; V_105 > 0 ;
V_104 = F_59 ( V_104 , & V_105 ) ) {
switch ( F_60 ( V_104 ) ) {
case V_112 :
V_103 . V_110 = V_104 ;
break;
case V_113 :
V_103 . V_111 = F_61 ( V_104 ) ;
break;
}
}
return F_62 ( V_96 , V_2 , & V_103 ) ;
}
static int F_63 ( struct V_95 * V_96 , struct V_1 * V_2 ,
const struct V_100 * V_101 )
{
const struct V_100 * V_114 = NULL ;
const struct V_100 * V_104 ;
int V_105 ;
for ( V_104 = F_57 ( V_101 ) , V_105 = F_58 ( V_101 ) ; V_105 > 0 ;
V_104 = F_59 ( V_104 , & V_105 ) ) {
switch ( F_60 ( V_104 ) ) {
case V_115 :
if ( F_64 () >= F_61 ( V_104 ) )
return 0 ;
break;
case V_116 :
V_114 = V_104 ;
break;
}
}
return F_65 ( V_96 , V_2 , F_57 ( V_114 ) ,
F_58 ( V_114 ) , true ) ;
}
static int F_66 ( struct V_1 * V_2 ,
const struct V_100 * V_117 )
{
int V_8 = 0 ;
switch ( F_60 ( V_117 ) ) {
case V_118 :
V_2 -> V_53 = F_61 ( V_117 ) ;
break;
case V_119 :
V_2 -> V_120 = F_61 ( V_117 ) ;
break;
case V_121 :
V_8 = F_22 ( V_2 , F_57 ( V_117 ) ) ;
break;
case V_122 :
V_8 = F_37 ( V_2 , F_57 ( V_117 ) ) ;
break;
case V_123 :
V_8 = F_41 ( V_2 , F_57 ( V_117 ) ) ;
break;
case V_124 :
V_8 = F_50 ( V_2 , F_57 ( V_117 ) ) ;
break;
case V_125 :
V_8 = F_49 ( V_2 , F_57 ( V_117 ) ) ;
break;
}
return V_8 ;
}
static int F_65 ( struct V_95 * V_96 , struct V_1 * V_2 ,
const struct V_100 * V_101 , int V_23 , bool V_126 )
{
int V_127 = - 1 ;
const struct V_100 * V_104 ;
int V_105 ;
for ( V_104 = V_101 , V_105 = V_23 ; V_105 > 0 ;
V_104 = F_59 ( V_104 , & V_105 ) ) {
int V_8 = 0 ;
if ( V_127 != - 1 ) {
F_51 ( V_96 , F_67 ( V_2 , V_4 ) , V_127 ) ;
V_127 = - 1 ;
}
switch ( F_60 ( V_104 ) ) {
case V_128 :
V_127 = F_61 ( V_104 ) ;
break;
case V_129 :
F_55 ( V_96 , V_2 , V_104 ) ;
break;
case V_130 :
V_8 = F_18 ( V_2 , F_57 ( V_104 ) ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
break;
case V_131 :
V_8 = F_12 ( V_2 ) ;
break;
case V_132 :
V_8 = F_66 ( V_2 , F_57 ( V_104 ) ) ;
break;
case V_133 :
V_8 = F_63 ( V_96 , V_2 , V_104 ) ;
break;
}
if ( F_6 ( V_8 ) ) {
F_53 ( V_2 ) ;
return V_8 ;
}
}
if ( V_127 != - 1 ) {
if ( V_126 )
V_2 = F_67 ( V_2 , V_4 ) ;
F_51 ( V_96 , V_2 , V_127 ) ;
} else if ( ! V_126 )
F_68 ( V_2 ) ;
return 0 ;
}
int F_69 ( struct V_95 * V_96 , struct V_1 * V_2 )
{
struct V_134 * V_135 = F_70 ( F_56 ( V_2 ) -> V_109 -> V_136 ) ;
return F_65 ( V_96 , V_2 , V_135 -> V_137 ,
V_135 -> V_138 , false ) ;
}
