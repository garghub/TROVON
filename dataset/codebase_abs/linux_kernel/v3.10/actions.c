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
+ ( 2 * V_14 ) , V_15 , 0 ) ) ;
V_7 = (struct V_6 * ) ( V_2 -> V_13 + V_16 ) ;
* V_5 = V_7 -> V_17 ;
memmove ( V_2 -> V_13 + V_15 , V_2 -> V_13 , 2 * V_14 ) ;
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
F_16 ( V_2 , F_15 ( V_22 ) , F_17 ( V_19 ) ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , const struct V_24 * V_25 )
{
if ( F_6 ( F_14 ( V_2 ) ) ) {
T_2 V_26 ;
V_26 = F_19 ( V_2 ) ;
if ( ! F_20 ( V_2 , V_2 -> V_27 , V_26 ) )
return - V_28 ;
if ( V_2 -> V_10 == V_11 )
V_2 -> V_12 = F_21 ( V_2 -> V_12 , F_8 ( V_2 -> V_13
+ ( 2 * V_14 ) , V_15 , 0 ) ) ;
}
F_16 ( V_2 , V_25 -> V_29 , F_17 ( V_25 -> V_20 ) & ~ V_30 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_31 * V_32 )
{
int V_8 ;
V_8 = F_1 ( V_2 , V_16 ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
memcpy ( F_23 ( V_2 ) -> V_33 , V_32 -> V_34 , V_14 ) ;
memcpy ( F_23 ( V_2 ) -> V_35 , V_32 -> V_36 , V_14 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_37 * V_38 ,
T_3 * V_39 , T_3 V_40 )
{
int V_41 = V_2 -> V_23 - F_25 ( V_2 ) ;
if ( V_38 -> V_21 == V_42 ) {
if ( F_13 ( V_41 >= sizeof( struct V_43 ) ) )
F_26 ( & F_27 ( V_2 ) -> V_44 , V_2 ,
* V_39 , V_40 , 1 ) ;
} else if ( V_38 -> V_21 == V_45 ) {
if ( F_13 ( V_41 >= sizeof( struct V_46 ) ) ) {
struct V_46 * V_47 = F_28 ( V_2 ) ;
if ( V_47 -> V_44 || V_2 -> V_10 == V_48 ) {
F_26 ( & V_47 -> V_44 , V_2 ,
* V_39 , V_40 , 1 ) ;
if ( ! V_47 -> V_44 )
V_47 -> V_44 = V_49 ;
}
}
}
F_29 ( & V_38 -> V_44 , * V_39 , V_40 ) ;
V_2 -> V_50 = 0 ;
* V_39 = V_40 ;
}
static void F_30 ( struct V_1 * V_2 , T_4 V_51 ,
T_3 V_39 [ 4 ] , const T_3 V_40 [ 4 ] )
{
int V_41 = V_2 -> V_23 - F_25 ( V_2 ) ;
if ( V_51 == V_42 ) {
if ( F_13 ( V_41 >= sizeof( struct V_43 ) ) )
F_31 ( & F_27 ( V_2 ) -> V_44 , V_2 ,
V_39 , V_40 , 1 ) ;
} else if ( V_51 == V_45 ) {
if ( F_13 ( V_41 >= sizeof( struct V_46 ) ) ) {
struct V_46 * V_47 = F_28 ( V_2 ) ;
if ( V_47 -> V_44 || V_2 -> V_10 == V_48 ) {
F_31 ( & V_47 -> V_44 , V_2 ,
V_39 , V_40 , 1 ) ;
if ( ! V_47 -> V_44 )
V_47 -> V_44 = V_49 ;
}
}
}
}
static void F_32 ( struct V_1 * V_2 , T_4 V_51 ,
T_3 V_39 [ 4 ] , const T_3 V_40 [ 4 ] ,
bool V_52 )
{
if ( V_52 )
F_30 ( V_2 , V_51 , V_39 , V_40 ) ;
V_2 -> V_50 = 0 ;
memcpy ( V_39 , V_40 , sizeof( T_3 [ 4 ] ) ) ;
}
static void F_33 ( struct V_53 * V_38 , T_4 V_54 )
{
V_38 -> V_55 = V_54 >> 4 ;
V_38 -> V_56 [ 0 ] = ( V_38 -> V_56 [ 0 ] & 0x0F ) | ( ( V_54 & 0x0F ) << 4 ) ;
}
static void F_34 ( struct V_53 * V_38 , T_5 V_57 )
{
V_38 -> V_56 [ 0 ] = ( V_38 -> V_56 [ 0 ] & 0xF0 ) | ( V_57 & 0x000F0000 ) >> 16 ;
V_38 -> V_56 [ 1 ] = ( V_57 & 0x0000FF00 ) >> 8 ;
V_38 -> V_56 [ 2 ] = V_57 & 0x000000FF ;
}
static void F_35 ( struct V_1 * V_2 , struct V_37 * V_38 , T_4 V_58 )
{
F_36 ( & V_38 -> V_44 , F_15 ( V_38 -> V_59 << 8 ) , F_15 ( V_58 << 8 ) ) ;
V_38 -> V_59 = V_58 ;
}
static int F_37 ( struct V_1 * V_2 , const struct V_60 * V_61 )
{
struct V_37 * V_38 ;
int V_8 ;
V_8 = F_1 ( V_2 , F_38 ( V_2 ) +
sizeof( struct V_37 ) ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
V_38 = F_39 ( V_2 ) ;
if ( V_61 -> V_62 != V_38 -> V_63 )
F_24 ( V_2 , V_38 , & V_38 -> V_63 , V_61 -> V_62 ) ;
if ( V_61 -> V_64 != V_38 -> V_65 )
F_24 ( V_2 , V_38 , & V_38 -> V_65 , V_61 -> V_64 ) ;
if ( V_61 -> V_66 != V_38 -> V_67 )
F_40 ( V_38 , 0 , V_61 -> V_66 ) ;
if ( V_61 -> V_68 != V_38 -> V_59 )
F_35 ( V_2 , V_38 , V_61 -> V_68 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , const struct V_69 * V_70 )
{
struct V_53 * V_38 ;
int V_8 ;
T_3 * V_63 ;
T_3 * V_65 ;
V_8 = F_1 ( V_2 , F_38 ( V_2 ) +
sizeof( struct V_53 ) ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
V_38 = F_42 ( V_2 ) ;
V_63 = ( T_3 * ) & V_38 -> V_63 ;
V_65 = ( T_3 * ) & V_38 -> V_65 ;
if ( memcmp ( V_70 -> V_71 , V_63 , sizeof( V_70 -> V_71 ) ) )
F_32 ( V_2 , V_70 -> V_72 , V_63 ,
V_70 -> V_71 , true ) ;
if ( memcmp ( V_70 -> V_73 , V_65 , sizeof( V_70 -> V_73 ) ) ) {
unsigned int V_74 = 0 ;
int V_75 = V_76 ;
bool V_77 = true ;
if ( F_43 ( V_38 -> V_78 ) )
V_77 = F_44 ( V_2 , & V_74 ,
V_79 , NULL ,
& V_75 ) != V_79 ;
F_32 ( V_2 , V_70 -> V_72 , V_65 ,
V_70 -> V_73 , V_77 ) ;
}
F_33 ( V_38 , V_70 -> V_80 ) ;
F_34 ( V_38 , F_45 ( V_70 -> V_81 ) ) ;
V_38 -> V_82 = V_70 -> V_83 ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , T_1 * V_84 ,
T_1 V_85 , T_6 * V_44 )
{
F_47 ( V_44 , V_2 , * V_84 , V_85 , 0 ) ;
* V_84 = V_85 ;
V_2 -> V_50 = 0 ;
}
static void F_48 ( struct V_1 * V_2 , T_1 * V_84 , T_1 V_85 )
{
struct V_46 * V_47 = F_28 ( V_2 ) ;
if ( V_47 -> V_44 && V_2 -> V_10 != V_48 ) {
F_46 ( V_2 , V_84 , V_85 , & V_47 -> V_44 ) ;
if ( ! V_47 -> V_44 )
V_47 -> V_44 = V_49 ;
} else {
* V_84 = V_85 ;
V_2 -> V_50 = 0 ;
}
}
static int F_49 ( struct V_1 * V_2 , const struct V_86 * V_87 )
{
struct V_46 * V_47 ;
int V_8 ;
V_8 = F_1 ( V_2 , F_25 ( V_2 ) +
sizeof( struct V_46 ) ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
V_47 = F_28 ( V_2 ) ;
if ( V_87 -> V_88 != V_47 -> V_89 )
F_48 ( V_2 , & V_47 -> V_89 , V_87 -> V_88 ) ;
if ( V_87 -> V_90 != V_47 -> V_91 )
F_48 ( V_2 , & V_47 -> V_91 , V_87 -> V_90 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , const struct V_92 * V_93 )
{
struct V_43 * V_94 ;
int V_8 ;
V_8 = F_1 ( V_2 , F_25 ( V_2 ) +
sizeof( struct V_43 ) ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
V_94 = F_27 ( V_2 ) ;
if ( V_93 -> V_95 != V_94 -> V_89 )
F_46 ( V_2 , & V_94 -> V_89 , V_93 -> V_95 , & V_94 -> V_44 ) ;
if ( V_93 -> V_96 != V_94 -> V_91 )
F_46 ( V_2 , & V_94 -> V_91 , V_93 -> V_96 , & V_94 -> V_44 ) ;
return 0 ;
}
static int F_51 ( struct V_97 * V_98 , struct V_1 * V_2 , int V_99 )
{
struct V_100 * V_100 ;
if ( F_6 ( ! V_2 ) )
return - V_28 ;
V_100 = F_52 ( V_98 , V_99 ) ;
if ( F_6 ( ! V_100 ) ) {
F_53 ( V_2 ) ;
return - V_101 ;
}
F_54 ( V_100 , V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_97 * V_98 , struct V_1 * V_2 ,
const struct V_102 * V_103 )
{
struct V_104 V_105 ;
const struct V_102 * V_106 ;
int V_107 ;
V_105 . V_108 = V_109 ;
V_105 . V_110 = & F_56 ( V_2 ) -> V_111 -> V_110 ;
V_105 . V_112 = NULL ;
V_105 . V_113 = 0 ;
for ( V_106 = F_57 ( V_103 ) , V_107 = F_58 ( V_103 ) ; V_107 > 0 ;
V_106 = F_59 ( V_106 , & V_107 ) ) {
switch ( F_60 ( V_106 ) ) {
case V_114 :
V_105 . V_112 = V_106 ;
break;
case V_115 :
V_105 . V_113 = F_61 ( V_106 ) ;
break;
}
}
return F_62 ( V_98 , V_2 , & V_105 ) ;
}
static int F_63 ( struct V_97 * V_98 , struct V_1 * V_2 ,
const struct V_102 * V_103 )
{
const struct V_102 * V_116 = NULL ;
const struct V_102 * V_106 ;
int V_107 ;
for ( V_106 = F_57 ( V_103 ) , V_107 = F_58 ( V_103 ) ; V_107 > 0 ;
V_106 = F_59 ( V_106 , & V_107 ) ) {
switch ( F_60 ( V_106 ) ) {
case V_117 :
if ( F_64 () >= F_61 ( V_106 ) )
return 0 ;
break;
case V_118 :
V_116 = V_106 ;
break;
}
}
return F_65 ( V_98 , V_2 , F_57 ( V_116 ) ,
F_58 ( V_116 ) , true ) ;
}
static int F_66 ( struct V_1 * V_2 ,
const struct V_102 * V_119 )
{
int V_8 = 0 ;
switch ( F_60 ( V_119 ) ) {
case V_120 :
V_2 -> V_55 = F_61 ( V_119 ) ;
break;
case V_121 :
V_2 -> V_122 = F_61 ( V_119 ) ;
break;
case V_123 :
V_8 = F_22 ( V_2 , F_57 ( V_119 ) ) ;
break;
case V_124 :
V_8 = F_37 ( V_2 , F_57 ( V_119 ) ) ;
break;
case V_125 :
V_8 = F_41 ( V_2 , F_57 ( V_119 ) ) ;
break;
case V_126 :
V_8 = F_50 ( V_2 , F_57 ( V_119 ) ) ;
break;
case V_127 :
V_8 = F_49 ( V_2 , F_57 ( V_119 ) ) ;
break;
}
return V_8 ;
}
static int F_65 ( struct V_97 * V_98 , struct V_1 * V_2 ,
const struct V_102 * V_103 , int V_23 , bool V_128 )
{
int V_129 = - 1 ;
const struct V_102 * V_106 ;
int V_107 ;
for ( V_106 = V_103 , V_107 = V_23 ; V_107 > 0 ;
V_106 = F_59 ( V_106 , & V_107 ) ) {
int V_8 = 0 ;
if ( V_129 != - 1 ) {
F_51 ( V_98 , F_67 ( V_2 , V_4 ) , V_129 ) ;
V_129 = - 1 ;
}
switch ( F_60 ( V_106 ) ) {
case V_130 :
V_129 = F_61 ( V_106 ) ;
break;
case V_131 :
F_55 ( V_98 , V_2 , V_106 ) ;
break;
case V_132 :
V_8 = F_18 ( V_2 , F_57 ( V_106 ) ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
break;
case V_133 :
V_8 = F_12 ( V_2 ) ;
break;
case V_134 :
V_8 = F_66 ( V_2 , F_57 ( V_106 ) ) ;
break;
case V_135 :
V_8 = F_63 ( V_98 , V_2 , V_106 ) ;
break;
}
if ( F_6 ( V_8 ) ) {
F_53 ( V_2 ) ;
return V_8 ;
}
}
if ( V_129 != - 1 ) {
if ( V_128 )
V_2 = F_67 ( V_2 , V_4 ) ;
F_51 ( V_98 , V_2 , V_129 ) ;
} else if ( ! V_128 )
F_68 ( V_2 ) ;
return 0 ;
}
int F_69 ( struct V_97 * V_98 , struct V_1 * V_2 )
{
struct V_136 * V_137 = F_70 ( F_56 ( V_2 ) -> V_111 -> V_138 ) ;
return F_65 ( V_98 , V_2 , V_137 -> V_139 ,
V_137 -> V_140 , false ) ;
}
