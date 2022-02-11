static inline
void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 . V_4 . V_5 . V_6 ) ;
F_3 ( V_2 ) ;
}
static inline
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_3 . V_4 . V_5 . V_6 ) ;
F_3 ( V_2 ) ;
}
static inline void F_6 ( struct V_7 * V_8 )
{
V_8 -> V_9 = V_10 ;
V_8 -> V_11 = V_8 -> V_12 = V_8 -> V_13 = 0 ;
V_8 -> V_14 = 0 ;
}
static struct V_7 * F_7 ( struct V_1 * V_2 ,
T_1 * V_15 , T_2 V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 ;
struct V_7 * V_8 ;
V_22 = V_20 -> V_23 . V_24 -> V_25 [ V_20 -> V_26 -> V_27 ] ;
if ( V_20 -> V_28 >= V_29 )
return NULL ;
V_8 = F_8 ( V_2 , V_15 , V_30 ) ;
if ( ! V_8 )
return NULL ;
F_9 ( V_8 , V_31 ) ;
F_9 ( V_8 , V_32 ) ;
F_9 ( V_8 , V_33 ) ;
F_10 ( V_8 , V_34 ) ;
V_8 -> V_8 . V_35 [ V_20 -> V_23 . V_36 . V_37 -> V_27 ] = V_16 ;
if ( V_18 -> V_38 )
F_11 ( V_2 , V_22 ,
V_18 -> V_38 ,
& V_8 -> V_8 . V_39 ) ;
F_12 ( V_8 ) ;
return V_8 ;
}
static bool F_13 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
bool V_40 = false ;
if ( V_8 -> V_9 == V_41 ) {
F_4 ( V_2 ) ;
V_40 = true ;
}
V_8 -> V_9 = V_42 ;
F_14 ( V_8 ) ;
return V_40 ;
}
void F_15 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
bool V_40 ;
F_16 ( & V_8 -> V_43 ) ;
V_40 = F_13 ( V_8 ) ;
V_8 -> V_13 = F_17 ( V_44 ) ;
F_18 ( V_2 , V_45 ,
V_8 -> V_8 . V_46 , V_8 -> V_11 , V_8 -> V_12 ,
V_8 -> V_13 ) ;
F_19 ( & V_8 -> V_43 ) ;
if ( V_40 )
F_20 ( V_2 , V_47 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
enum V_48 V_49 ,
T_1 * V_50 , T_3 V_11 , T_3 V_12 , T_3 V_13 ) {
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
bool V_55 = false ;
T_4 V_56 = 0 ;
T_1 * V_57 , V_58 = 4 ;
int V_59 = F_21 ( struct V_53 , V_3 . V_49 . V_3 . V_60 ) +
sizeof( V_54 -> V_3 . V_49 . V_3 . V_60 ) ;
V_52 = F_22 ( V_20 -> V_61 +
V_59 +
2 +
2 +
2 + 8 +
2 + ( V_62 - 8 ) +
2 + V_2 -> V_3 . V_4 . V_63 +
2 + sizeof( struct V_64 ) +
2 + sizeof( struct V_65 ) +
2 + sizeof( struct V_66 ) +
2 + 8 +
V_2 -> V_3 . V_4 . V_58 ) ;
if ( ! V_52 )
return - 1 ;
F_23 ( V_52 , V_20 -> V_61 ) ;
V_54 = (struct V_53 * ) F_24 ( V_52 , V_59 ) ;
memset ( V_54 , 0 , V_59 ) ;
V_54 -> V_67 = F_17 ( V_68 |
V_69 ) ;
memcpy ( V_54 -> V_50 , V_50 , V_70 ) ;
memcpy ( V_54 -> V_71 , V_2 -> V_72 . V_46 , V_70 ) ;
memcpy ( V_54 -> V_73 , V_2 -> V_72 . V_46 , V_70 ) ;
V_54 -> V_3 . V_49 . V_74 = V_75 ;
V_54 -> V_3 . V_49 . V_3 . V_60 . V_76 = V_49 ;
if ( V_49 != V_45 ) {
V_57 = F_24 ( V_52 , 2 ) ;
memset ( V_57 , 0 , 2 ) ;
if ( V_49 == V_77 ) {
V_57 = F_24 ( V_52 , 2 ) ;
memcpy ( V_57 + 2 , & V_12 , 2 ) ;
}
if ( F_25 ( & V_2 -> V_72 , V_52 ) ||
F_26 ( & V_2 -> V_72 , V_52 ) ||
F_27 ( V_52 , V_2 ) ||
F_28 ( V_52 , V_2 ) ||
F_29 ( V_52 , V_2 ) )
return - 1 ;
} else {
if ( F_28 ( V_52 , V_2 ) )
return - 1 ;
}
switch ( V_49 ) {
case V_78 :
break;
case V_77 :
V_58 += 2 ;
V_55 = true ;
break;
case V_45 :
if ( V_12 ) {
V_58 += 2 ;
V_55 = true ;
}
V_58 += 2 ;
break;
default:
return - V_79 ;
}
if ( F_30 ( F_31 ( V_52 ) < 2 + V_58 ) )
return - V_80 ;
V_57 = F_24 ( V_52 , 2 + V_58 ) ;
* V_57 ++ = V_81 ;
* V_57 ++ = V_58 ;
memcpy ( V_57 , & V_56 , 2 ) ;
V_57 += 2 ;
memcpy ( V_57 , & V_11 , 2 ) ;
V_57 += 2 ;
if ( V_55 ) {
memcpy ( V_57 , & V_12 , 2 ) ;
V_57 += 2 ;
}
if ( V_49 == V_45 ) {
memcpy ( V_57 , & V_13 , 2 ) ;
V_57 += 2 ;
}
if ( V_49 != V_45 ) {
if ( F_32 ( V_52 , V_2 ) ||
F_33 ( V_52 , V_2 ) )
return - 1 ;
}
if ( F_34 ( V_52 , V_2 ) )
return - 1 ;
F_35 ( V_2 , V_52 ) ;
return 0 ;
}
void F_36 ( T_1 * V_15 , T_2 V_16 ,
struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_7 * V_8 ;
F_37 () ;
V_8 = F_38 ( V_2 , V_15 ) ;
if ( ! V_8 ) {
F_39 () ;
if ( V_2 -> V_3 . V_4 . V_82 & V_83 )
F_40 ( V_2 -> V_84 , V_15 ,
V_18 -> V_85 , V_18 -> V_86 ,
V_30 ) ;
else
V_8 = F_7 ( V_2 , V_15 , V_16 , V_18 ) ;
if ( ! V_8 )
return;
if ( F_41 ( V_8 ) ) {
F_39 () ;
return;
}
}
V_8 -> V_87 = V_88 ;
V_8 -> V_8 . V_35 [ V_20 -> V_23 . V_36 . V_37 -> V_27 ] = V_16 ;
if ( F_42 ( V_18 ) &&
V_8 -> V_9 == V_10 &&
V_2 -> V_3 . V_4 . V_89 &&
V_2 -> V_3 . V_4 . V_90 . V_91 &&
F_43 ( V_8 , V_2 ) )
F_44 ( V_8 ) ;
F_39 () ;
}
static void F_45 ( unsigned long V_92 )
{
struct V_7 * V_8 ;
T_3 V_11 , V_12 , V_13 ;
struct V_1 * V_2 ;
V_8 = (struct V_7 * ) V_92 ;
if ( V_8 -> V_2 -> V_20 -> V_93 ) {
V_8 -> V_94 = true ;
return;
}
F_16 ( & V_8 -> V_43 ) ;
if ( V_8 -> V_95 ) {
V_8 -> V_95 = false ;
F_19 ( & V_8 -> V_43 ) ;
return;
}
F_46 ( L_1 ,
V_8 -> V_8 . V_46 , V_8 -> V_9 ) ;
V_13 = 0 ;
V_11 = V_8 -> V_11 ;
V_12 = V_8 -> V_12 ;
V_2 = V_8 -> V_2 ;
switch ( V_8 -> V_9 ) {
case V_96 :
case V_97 :
if ( V_8 -> V_14 < F_47 ( V_2 ) ) {
T_2 rand ;
F_46 ( L_2 ,
V_8 -> V_8 . V_46 , V_8 -> V_14 ,
V_8 -> V_98 ) ;
F_48 ( & rand , sizeof( T_2 ) ) ;
V_8 -> V_98 = V_8 -> V_98 +
rand % V_8 -> V_98 ;
++ V_8 -> V_14 ;
F_49 ( V_8 , V_8 -> V_98 ) ;
F_19 ( & V_8 -> V_43 ) ;
F_18 ( V_2 , V_78 ,
V_8 -> V_8 . V_46 , V_11 , 0 , 0 ) ;
break;
}
V_13 = F_17 ( V_99 ) ;
case V_100 :
if ( ! V_13 )
V_13 = F_17 ( V_101 ) ;
V_8 -> V_9 = V_102 ;
F_49 ( V_8 , F_50 ( V_2 ) ) ;
F_19 ( & V_8 -> V_43 ) ;
F_18 ( V_2 , V_45 ,
V_8 -> V_8 . V_46 , V_11 , V_12 , V_13 ) ;
break;
case V_102 :
F_51 ( & V_8 -> V_103 ) ;
F_6 ( V_8 ) ;
F_19 ( & V_8 -> V_43 ) ;
break;
default:
F_19 ( & V_8 -> V_43 ) ;
break;
}
}
void F_52 ( struct V_7 * V_8 )
{
if ( F_53 ( & V_8 -> V_103 ) )
V_8 -> V_94 = true ;
}
void F_54 ( struct V_7 * V_8 )
{
if ( V_8 -> V_94 ) {
F_55 ( & V_8 -> V_103 ) ;
V_8 -> V_94 = false ;
}
}
static inline void F_56 ( struct V_7 * V_8 , int V_104 )
{
V_8 -> V_103 . V_105 = V_88 + ( V_106 * V_104 / 1000 ) ;
V_8 -> V_103 . V_92 = ( unsigned long ) V_8 ;
V_8 -> V_103 . V_107 = F_45 ;
V_8 -> V_98 = V_104 ;
F_55 ( & V_8 -> V_103 ) ;
}
int F_44 ( struct V_7 * V_8 )
{
T_3 V_11 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_57 ( V_8 , V_108 ) )
return - V_109 ;
F_16 ( & V_8 -> V_43 ) ;
F_48 ( & V_11 , 2 ) ;
V_8 -> V_11 = V_11 ;
if ( V_8 -> V_9 != V_10 ) {
F_19 ( & V_8 -> V_43 ) ;
return - V_110 ;
}
V_8 -> V_9 = V_97 ;
F_56 ( V_8 , F_58 ( V_2 ) ) ;
F_19 ( & V_8 -> V_43 ) ;
F_46 ( L_3 ,
V_8 -> V_8 . V_46 ) ;
return F_18 ( V_2 , V_78 ,
V_8 -> V_8 . V_46 , V_11 , 0 , 0 ) ;
}
void F_59 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
bool V_40 ;
F_16 ( & V_8 -> V_43 ) ;
V_40 = F_13 ( V_8 ) ;
V_8 -> V_9 = V_42 ;
F_19 ( & V_8 -> V_43 ) ;
if ( V_40 )
F_20 ( V_2 , V_47 ) ;
}
void F_60 ( struct V_1 * V_2 , struct V_53 * V_54 ,
T_5 V_111 , struct V_112 * V_113 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_17 V_18 ;
struct V_7 * V_8 ;
enum V_114 V_115 ;
enum V_48 V_116 ;
T_5 V_117 ;
bool V_40 , V_118 = true ;
T_1 V_58 ;
T_1 * V_119 ;
T_3 V_12 , V_11 , V_13 ;
#ifdef F_61
static const char * V_120 [] = {
[ V_10 ] = L_4 ,
[ V_97 ] = L_5 ,
[ V_96 ] = L_6 ,
[ V_100 ] = L_7 ,
[ V_41 ] = L_8 ,
[ V_102 ] = L_9 ,
[ V_42 ] = L_10
} ;
#endif
if ( V_111 < V_121 + 3 )
return;
if ( F_62 ( V_54 -> V_50 ) ) {
F_46 ( L_11 ) ;
return;
}
V_119 = V_54 -> V_3 . V_49 . V_3 . V_60 . V_122 ;
V_117 = ( T_1 * ) V_54 -> V_3 . V_49 . V_3 . V_60 . V_122 - ( T_1 * ) V_54 ;
if ( V_54 -> V_3 . V_49 . V_3 . V_60 . V_76 ==
V_77 ) {
V_119 += 4 ;
V_117 += 4 ;
}
F_63 ( V_119 , V_111 - V_117 , & V_18 ) ;
if ( ! V_18 . V_123 ) {
F_46 ( L_12 ) ;
return;
}
if ( V_18 . V_124 &&
V_2 -> V_3 . V_4 . V_82 == V_125 ) {
F_46 ( L_13 ) ;
return;
}
V_116 = V_54 -> V_3 . V_49 . V_3 . V_60 . V_76 ;
V_58 = V_18 . V_126 ;
if ( ( V_116 == V_78 && V_58 != 4 ) ||
( V_116 == V_77 && V_58 != 6 ) ||
( V_116 == V_45 && V_58 != 6
&& V_58 != 8 ) ) {
F_46 ( L_14 ,
V_116 , V_58 ) ;
return;
}
if ( V_116 != V_45 &&
( ! V_18 . V_127 || ! V_18 . V_128 ) ) {
F_46 ( L_15 ) ;
return;
}
memcpy ( & V_12 , F_64 ( V_18 . V_123 ) , 2 ) ;
if ( V_116 == V_77 ||
( V_116 == V_45 && V_58 == 8 ) )
memcpy ( & V_11 , F_65 ( V_18 . V_123 ) , 2 ) ;
F_37 () ;
V_8 = F_38 ( V_2 , V_54 -> V_71 ) ;
if ( ! V_8 && V_116 != V_78 ) {
F_46 ( L_16 ) ;
F_39 () ;
return;
}
if ( V_116 == V_78 &&
! F_43 ( V_8 , V_2 ) ) {
F_46 ( L_17 ,
V_54 -> V_71 ) ;
F_39 () ;
return;
}
if ( V_8 && ! F_57 ( V_8 , V_108 ) ) {
F_46 ( L_18 ) ;
F_39 () ;
return;
}
if ( V_8 && V_8 -> V_9 == V_42 ) {
F_39 () ;
return;
}
V_115 = V_129 ;
if ( V_116 != V_45 &&
( ! F_66 ( & V_18 , V_2 ) ) ) {
V_118 = false ;
switch ( V_116 ) {
case V_78 :
V_115 = V_130 ;
break;
case V_77 :
V_115 = V_131 ;
break;
default:
break;
}
}
if ( ! V_8 && ! V_118 ) {
F_39 () ;
V_13 = F_17 ( V_132 ) ;
V_11 = 0 ;
F_18 ( V_2 , V_45 ,
V_54 -> V_71 , V_11 , V_12 , V_13 ) ;
return;
} else if ( ! V_8 ) {
T_2 V_16 ;
F_39 () ;
if ( ! F_67 ( V_2 ) ) {
F_46 ( L_19 ) ;
return;
}
V_16 = F_68 ( V_20 , & V_18 , V_113 -> V_27 ) ;
V_8 = F_7 ( V_2 , V_54 -> V_71 , V_16 , & V_18 ) ;
if ( ! V_8 ) {
F_46 ( L_20 ) ;
return;
}
if ( F_41 ( V_8 ) ) {
F_39 () ;
return;
}
V_115 = V_133 ;
F_16 ( & V_8 -> V_43 ) ;
} else if ( V_118 ) {
F_16 ( & V_8 -> V_43 ) ;
switch ( V_116 ) {
case V_78 :
if ( ! F_67 ( V_2 ) ||
( V_8 -> V_12 && V_8 -> V_12 != V_12 ) )
V_115 = V_134 ;
else
V_115 = V_133 ;
break;
case V_77 :
if ( ! F_67 ( V_2 ) ||
( V_8 -> V_11 != V_11 || V_8 -> V_12 != V_12 ) )
V_115 = V_135 ;
else
V_115 = V_136 ;
break;
case V_45 :
if ( V_8 -> V_9 == V_41 )
V_115 = V_137 ;
else if ( V_8 -> V_12 != V_12 )
V_115 = V_138 ;
else if ( V_58 == 7 && V_8 -> V_11 != V_11 )
V_115 = V_138 ;
else
V_115 = V_137 ;
break;
default:
F_46 ( L_21 ) ;
F_19 ( & V_8 -> V_43 ) ;
F_39 () ;
return;
}
} else {
F_16 ( & V_8 -> V_43 ) ;
}
F_46 ( L_22 ,
V_54 -> V_71 , V_120 [ V_8 -> V_9 ] ,
F_69 ( V_8 -> V_11 ) , F_69 ( V_8 -> V_12 ) ,
V_115 ) ;
V_13 = 0 ;
switch ( V_8 -> V_9 ) {
case V_10 :
switch ( V_115 ) {
case V_137 :
F_6 ( V_8 ) ;
F_19 ( & V_8 -> V_43 ) ;
break;
case V_133 :
V_8 -> V_9 = V_96 ;
V_8 -> V_12 = V_12 ;
F_48 ( & V_11 , 2 ) ;
V_8 -> V_11 = V_11 ;
F_56 ( V_8 , F_58 ( V_2 ) ) ;
F_19 ( & V_8 -> V_43 ) ;
F_18 ( V_2 ,
V_78 ,
V_8 -> V_8 . V_46 , V_11 , 0 , 0 ) ;
F_18 ( V_2 ,
V_77 ,
V_8 -> V_8 . V_46 , V_11 , V_12 , 0 ) ;
break;
default:
F_19 ( & V_8 -> V_43 ) ;
break;
}
break;
case V_97 :
switch ( V_115 ) {
case V_130 :
case V_131 :
V_13 = F_17 ( V_132 ) ;
case V_137 :
if ( ! V_13 )
V_13 = F_17 ( V_139 ) ;
V_8 -> V_13 = V_13 ;
V_8 -> V_9 = V_102 ;
if ( ! F_49 ( V_8 ,
F_50 ( V_2 ) ) )
V_8 -> V_95 = true ;
V_11 = V_8 -> V_11 ;
F_19 ( & V_8 -> V_43 ) ;
F_18 ( V_2 ,
V_45 ,
V_8 -> V_8 . V_46 , V_11 , V_12 , V_13 ) ;
break;
case V_133 :
V_8 -> V_9 = V_96 ;
V_8 -> V_12 = V_12 ;
V_11 = V_8 -> V_11 ;
F_19 ( & V_8 -> V_43 ) ;
F_18 ( V_2 ,
V_77 ,
V_8 -> V_8 . V_46 , V_11 , V_12 , 0 ) ;
break;
case V_136 :
V_8 -> V_9 = V_100 ;
if ( ! F_49 ( V_8 ,
F_70 ( V_2 ) ) )
V_8 -> V_95 = true ;
F_19 ( & V_8 -> V_43 ) ;
break;
default:
F_19 ( & V_8 -> V_43 ) ;
break;
}
break;
case V_96 :
switch ( V_115 ) {
case V_130 :
case V_131 :
V_13 = F_17 ( V_132 ) ;
case V_137 :
if ( ! V_13 )
V_13 = F_17 ( V_139 ) ;
V_8 -> V_13 = V_13 ;
V_8 -> V_9 = V_102 ;
if ( ! F_49 ( V_8 ,
F_50 ( V_2 ) ) )
V_8 -> V_95 = true ;
V_11 = V_8 -> V_11 ;
F_19 ( & V_8 -> V_43 ) ;
F_18 ( V_2 , V_45 ,
V_8 -> V_8 . V_46 , V_11 , V_12 , V_13 ) ;
break;
case V_133 :
V_11 = V_8 -> V_11 ;
F_19 ( & V_8 -> V_43 ) ;
F_18 ( V_2 ,
V_77 ,
V_8 -> V_8 . V_46 , V_11 , V_12 , 0 ) ;
break;
case V_136 :
F_51 ( & V_8 -> V_103 ) ;
V_8 -> V_9 = V_41 ;
F_19 ( & V_8 -> V_43 ) ;
F_1 ( V_2 ) ;
F_20 ( V_2 , V_47 ) ;
F_46 ( L_23 ,
V_8 -> V_8 . V_46 ) ;
break;
default:
F_19 ( & V_8 -> V_43 ) ;
break;
}
break;
case V_100 :
switch ( V_115 ) {
case V_130 :
case V_131 :
V_13 = F_17 ( V_132 ) ;
case V_137 :
if ( ! V_13 )
V_13 = F_17 ( V_139 ) ;
V_8 -> V_13 = V_13 ;
V_8 -> V_9 = V_102 ;
if ( ! F_49 ( V_8 ,
F_50 ( V_2 ) ) )
V_8 -> V_95 = true ;
V_11 = V_8 -> V_11 ;
F_19 ( & V_8 -> V_43 ) ;
F_18 ( V_2 ,
V_45 ,
V_8 -> V_8 . V_46 , V_11 , V_12 , V_13 ) ;
break;
case V_133 :
F_51 ( & V_8 -> V_103 ) ;
V_8 -> V_9 = V_41 ;
F_19 ( & V_8 -> V_43 ) ;
F_1 ( V_2 ) ;
F_20 ( V_2 , V_47 ) ;
F_46 ( L_23 ,
V_8 -> V_8 . V_46 ) ;
F_18 ( V_2 ,
V_77 ,
V_8 -> V_8 . V_46 , V_11 , V_12 , 0 ) ;
break;
default:
F_19 ( & V_8 -> V_43 ) ;
break;
}
break;
case V_41 :
switch ( V_115 ) {
case V_137 :
V_13 = F_17 ( V_139 ) ;
V_8 -> V_13 = V_13 ;
V_40 = F_13 ( V_8 ) ;
V_8 -> V_9 = V_102 ;
V_11 = V_8 -> V_11 ;
F_49 ( V_8 , F_50 ( V_2 ) ) ;
F_19 ( & V_8 -> V_43 ) ;
if ( V_40 )
F_20 ( V_2 , V_47 ) ;
F_18 ( V_2 , V_45 ,
V_8 -> V_8 . V_46 , V_11 , V_12 , V_13 ) ;
break;
case V_133 :
V_11 = V_8 -> V_11 ;
F_19 ( & V_8 -> V_43 ) ;
F_18 ( V_2 ,
V_77 ,
V_8 -> V_8 . V_46 , V_11 , V_12 , 0 ) ;
break;
default:
F_19 ( & V_8 -> V_43 ) ;
break;
}
break;
case V_102 :
switch ( V_115 ) {
case V_137 :
if ( F_51 ( & V_8 -> V_103 ) )
V_8 -> V_95 = 1 ;
F_6 ( V_8 ) ;
F_19 ( & V_8 -> V_43 ) ;
break;
case V_133 :
case V_136 :
case V_130 :
case V_131 :
V_11 = V_8 -> V_11 ;
V_13 = V_8 -> V_13 ;
F_19 ( & V_8 -> V_43 ) ;
F_18 ( V_2 , V_45 ,
V_8 -> V_8 . V_46 , V_11 , V_12 , V_13 ) ;
break;
default:
F_19 ( & V_8 -> V_43 ) ;
}
break;
default:
F_19 ( & V_8 -> V_43 ) ;
break;
}
F_39 () ;
}
