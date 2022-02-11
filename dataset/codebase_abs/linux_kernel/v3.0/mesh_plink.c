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
T_1 * V_15 , T_2 V_16 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 ;
if ( V_18 -> V_19 >= V_20 )
return NULL ;
V_8 = F_8 ( V_2 , V_15 , V_21 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_22 = V_23 | V_24 ;
V_8 -> V_8 . V_25 [ V_18 -> V_26 . V_27 . V_28 -> V_29 ] = V_16 ;
F_9 ( V_8 ) ;
return V_8 ;
}
static bool F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
bool V_30 = false ;
if ( V_8 -> V_9 == V_31 ) {
F_4 ( V_2 ) ;
V_30 = true ;
}
V_8 -> V_9 = V_32 ;
F_11 ( V_8 ) ;
return V_30 ;
}
void F_12 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
bool V_30 ;
F_13 ( & V_8 -> V_33 ) ;
V_30 = F_10 ( V_8 ) ;
F_14 ( & V_8 -> V_33 ) ;
if ( V_30 )
F_15 ( V_2 , V_34 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
enum V_35 V_36 , T_1 * V_37 , T_3 V_11 , T_3 V_12 ,
T_3 V_13 ) {
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_38 * V_39 = F_17 ( V_18 -> V_26 . V_40 + 400 +
V_2 -> V_3 . V_4 . V_41 ) ;
struct V_42 * V_43 ;
bool V_44 = false ;
static const T_1 V_45 [] = { 0x00 , 0x0F , 0xAC , 0x2A } ;
T_1 * V_46 ;
int V_41 ;
if ( ! V_39 )
return - 1 ;
F_18 ( V_39 , V_18 -> V_26 . V_40 ) ;
V_43 = (struct V_42 * )
F_19 ( V_39 , 25 + sizeof( V_43 -> V_3 . V_36 . V_3 . V_47 ) ) ;
memset ( V_43 , 0 , 25 + sizeof( V_43 -> V_3 . V_36 . V_3 . V_47 ) ) ;
V_43 -> V_48 = F_20 ( V_49 |
V_50 ) ;
memcpy ( V_43 -> V_37 , V_37 , V_51 ) ;
memcpy ( V_43 -> V_52 , V_2 -> V_53 . V_54 , V_51 ) ;
memcpy ( V_43 -> V_55 , V_2 -> V_53 . V_54 , V_51 ) ;
V_43 -> V_3 . V_36 . V_56 = V_57 ;
V_43 -> V_3 . V_36 . V_3 . V_47 . V_58 = V_36 ;
if ( V_36 == V_59 )
V_43 -> V_3 . V_36 . V_3 . V_47 . V_60 = V_13 ;
else {
V_43 -> V_3 . V_36 . V_3 . V_47 . V_60 = F_20 ( 0x0 ) ;
if ( V_36 == V_61 ) {
V_46 = F_19 ( V_39 , 4 ) ;
memset ( V_46 , 0 , 2 ) ;
memcpy ( V_46 + 2 , & V_12 , 2 ) ;
}
F_21 ( V_39 , V_2 ) ;
}
switch ( V_36 ) {
case V_62 :
V_41 = 6 ;
break;
case V_61 :
V_41 = 8 ;
V_44 = true ;
break;
case V_59 :
default:
if ( ! V_12 )
V_41 = 8 ;
else {
V_41 = 10 ;
V_44 = true ;
}
break;
}
V_46 = F_19 ( V_39 , 2 + V_41 ) ;
* V_46 ++ = V_63 ;
* V_46 ++ = V_41 ;
memcpy ( V_46 , V_45 , sizeof( V_45 ) ) ;
V_46 += 4 ;
memcpy ( V_46 , & V_11 , 2 ) ;
if ( V_44 ) {
V_46 += 2 ;
memcpy ( V_46 , & V_12 , 2 ) ;
}
if ( V_36 == V_59 ) {
V_46 += 2 ;
memcpy ( V_46 , & V_13 , 2 ) ;
}
F_22 ( V_2 , V_39 ) ;
return 0 ;
}
void F_23 ( T_1 * V_15 , T_2 V_16 ,
struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 ;
F_24 () ;
V_8 = F_25 ( V_2 , V_15 ) ;
if ( ! V_8 ) {
F_26 () ;
if ( V_2 -> V_3 . V_4 . V_66 & V_67 )
F_27 ( V_2 -> V_68 , V_15 ,
V_65 -> V_69 , V_65 -> V_70 ,
V_21 ) ;
else
V_8 = F_7 ( V_2 , V_15 , V_16 ) ;
if ( ! V_8 )
return;
if ( F_28 ( V_8 ) ) {
F_26 () ;
return;
}
}
V_8 -> V_71 = V_72 ;
V_8 -> V_8 . V_25 [ V_18 -> V_26 . V_27 . V_28 -> V_29 ] = V_16 ;
if ( F_29 ( V_65 ) &&
V_8 -> V_9 == V_10 &&
V_2 -> V_3 . V_4 . V_73 &&
V_2 -> V_3 . V_4 . V_74 . V_75 )
F_30 ( V_8 ) ;
F_26 () ;
}
static void F_31 ( unsigned long V_76 )
{
struct V_7 * V_8 ;
T_3 V_11 , V_12 , V_13 ;
struct V_1 * V_2 ;
V_8 = (struct V_7 * ) V_76 ;
if ( V_8 -> V_2 -> V_18 -> V_77 ) {
V_8 -> V_78 = true ;
return;
}
F_13 ( & V_8 -> V_33 ) ;
if ( V_8 -> V_79 ) {
V_8 -> V_79 = false ;
F_14 ( & V_8 -> V_33 ) ;
return;
}
F_32 ( L_1 ,
V_8 -> V_8 . V_54 , V_8 -> V_9 ) ;
V_13 = 0 ;
V_11 = V_8 -> V_11 ;
V_12 = V_8 -> V_12 ;
V_2 = V_8 -> V_2 ;
switch ( V_8 -> V_9 ) {
case V_80 :
case V_81 :
if ( V_8 -> V_14 < F_33 ( V_2 ) ) {
T_2 rand ;
F_32 ( L_2 ,
V_8 -> V_8 . V_54 , V_8 -> V_14 ,
V_8 -> V_82 ) ;
F_34 ( & rand , sizeof( T_2 ) ) ;
V_8 -> V_82 = V_8 -> V_82 +
rand % V_8 -> V_82 ;
++ V_8 -> V_14 ;
F_35 ( V_8 , V_8 -> V_82 ) ;
F_14 ( & V_8 -> V_33 ) ;
F_16 ( V_2 , V_62 , V_8 -> V_8 . V_54 , V_11 ,
0 , 0 ) ;
break;
}
V_13 = F_20 ( V_83 ) ;
case V_84 :
if ( ! V_13 )
V_13 = F_20 ( V_85 ) ;
V_8 -> V_9 = V_86 ;
F_35 ( V_8 , F_36 ( V_2 ) ) ;
F_14 ( & V_8 -> V_33 ) ;
F_16 ( V_2 , V_59 , V_8 -> V_8 . V_54 , V_11 , V_12 ,
V_13 ) ;
break;
case V_86 :
F_37 ( & V_8 -> V_87 ) ;
F_6 ( V_8 ) ;
F_14 ( & V_8 -> V_33 ) ;
break;
default:
F_14 ( & V_8 -> V_33 ) ;
break;
}
}
void F_38 ( struct V_7 * V_8 )
{
if ( F_39 ( & V_8 -> V_87 ) )
V_8 -> V_78 = true ;
}
void F_40 ( struct V_7 * V_8 )
{
if ( V_8 -> V_78 ) {
F_41 ( & V_8 -> V_87 ) ;
V_8 -> V_78 = false ;
}
}
static inline void F_42 ( struct V_7 * V_8 , int V_88 )
{
V_8 -> V_87 . V_89 = V_72 + ( V_90 * V_88 / 1000 ) ;
V_8 -> V_87 . V_76 = ( unsigned long ) V_8 ;
V_8 -> V_87 . V_91 = F_31 ;
V_8 -> V_82 = V_88 ;
F_41 ( & V_8 -> V_87 ) ;
}
int F_30 ( struct V_7 * V_8 )
{
T_3 V_11 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_43 ( V_8 , V_24 ) )
return - V_92 ;
F_13 ( & V_8 -> V_33 ) ;
F_34 ( & V_11 , 2 ) ;
V_8 -> V_11 = V_11 ;
if ( V_8 -> V_9 != V_10 ) {
F_14 ( & V_8 -> V_33 ) ;
return - V_93 ;
}
V_8 -> V_9 = V_81 ;
F_42 ( V_8 , F_44 ( V_2 ) ) ;
F_14 ( & V_8 -> V_33 ) ;
F_32 ( L_3 ,
V_8 -> V_8 . V_54 ) ;
return F_16 ( V_2 , V_62 ,
V_8 -> V_8 . V_54 , V_11 , 0 , 0 ) ;
}
void F_45 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
bool V_30 ;
F_13 ( & V_8 -> V_33 ) ;
V_30 = F_10 ( V_8 ) ;
V_8 -> V_9 = V_32 ;
F_14 ( & V_8 -> V_33 ) ;
if ( V_30 )
F_15 ( V_2 , V_34 ) ;
}
void F_46 ( struct V_1 * V_2 , struct V_42 * V_43 ,
T_4 V_94 , struct V_95 * V_96 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_64 V_65 ;
struct V_7 * V_8 ;
enum V_97 V_98 ;
enum V_35 V_99 ;
T_4 V_100 ;
bool V_30 , V_101 = true ;
T_1 V_41 ;
T_1 * V_102 ;
T_3 V_12 , V_11 , V_13 ;
#ifdef F_47
static const char * V_103 [] = {
[ V_10 ] = L_4 ,
[ V_81 ] = L_5 ,
[ V_80 ] = L_6 ,
[ V_84 ] = L_7 ,
[ V_31 ] = L_8 ,
[ V_86 ] = L_9 ,
[ V_32 ] = L_10
} ;
#endif
if ( V_94 < V_104 + 3 )
return;
if ( F_48 ( V_43 -> V_37 ) ) {
F_32 ( L_11 ) ;
return;
}
V_102 = V_43 -> V_3 . V_36 . V_3 . V_47 . V_105 ;
V_100 = ( T_1 * ) V_43 -> V_3 . V_36 . V_3 . V_47 . V_105 - ( T_1 * ) V_43 ;
if ( V_43 -> V_3 . V_36 . V_3 . V_47 . V_58 == V_61 ) {
V_102 += 4 ;
V_100 += 4 ;
}
F_49 ( V_102 , V_94 - V_100 , & V_65 ) ;
if ( ! V_65 . V_106 ) {
F_32 ( L_12 ) ;
return;
}
if ( V_65 . V_107 &&
V_2 -> V_3 . V_4 . V_66 == V_108 ) {
F_32 ( L_13 ) ;
return;
}
V_99 = V_43 -> V_3 . V_36 . V_3 . V_47 . V_58 ;
V_41 = V_65 . V_109 ;
if ( ( V_99 == V_62 && V_41 != 6 ) ||
( V_99 == V_61 && V_41 != 8 ) ||
( V_99 == V_59 && V_41 != 8 && V_41 != 10 ) ) {
F_32 ( L_14 ,
V_99 , V_41 ) ;
return;
}
if ( V_99 != V_59 && ( ! V_65 . V_110 || ! V_65 . V_111 ) ) {
F_32 ( L_15 ) ;
return;
}
memcpy ( & V_12 , F_50 ( V_65 . V_106 ) , 2 ) ;
if ( V_99 == V_61 || ( V_99 == V_59 && V_41 == 10 ) )
memcpy ( & V_11 , F_51 ( V_65 . V_106 ) , 2 ) ;
F_24 () ;
V_8 = F_25 ( V_2 , V_43 -> V_52 ) ;
if ( ! V_8 && V_99 != V_62 ) {
F_32 ( L_16 ) ;
F_26 () ;
return;
}
if ( V_8 && ! F_43 ( V_8 , V_24 ) ) {
F_32 ( L_17 ) ;
F_26 () ;
return;
}
if ( V_8 && V_8 -> V_9 == V_32 ) {
F_26 () ;
return;
}
V_98 = V_112 ;
if ( V_99 != V_59 && ( ! F_52 ( & V_65 , V_2 ) ) ) {
V_101 = false ;
switch ( V_99 ) {
case V_62 :
V_98 = V_113 ;
break;
case V_61 :
V_98 = V_114 ;
break;
case V_59 :
break;
}
}
if ( ! V_8 && ! V_101 ) {
F_26 () ;
V_13 = F_20 ( V_115 ) ;
V_11 = 0 ;
F_16 ( V_2 , V_59 , V_43 -> V_52 , V_11 ,
V_12 , V_13 ) ;
return;
} else if ( ! V_8 ) {
T_2 V_16 ;
F_26 () ;
if ( ! F_53 ( V_2 ) ) {
F_32 ( L_18 ) ;
return;
}
V_16 = F_54 ( V_18 , & V_65 , V_96 -> V_29 ) ;
V_8 = F_7 ( V_2 , V_43 -> V_52 , V_16 ) ;
if ( ! V_8 ) {
F_32 ( L_19 ) ;
return;
}
if ( F_28 ( V_8 ) ) {
F_26 () ;
return;
}
V_98 = V_116 ;
F_13 ( & V_8 -> V_33 ) ;
} else if ( V_101 ) {
F_13 ( & V_8 -> V_33 ) ;
switch ( V_99 ) {
case V_62 :
if ( ! F_53 ( V_2 ) ||
( V_8 -> V_12 && V_8 -> V_12 != V_12 ) )
V_98 = V_117 ;
else
V_98 = V_116 ;
break;
case V_61 :
if ( ! F_53 ( V_2 ) ||
( V_8 -> V_11 != V_11 || V_8 -> V_12 != V_12 ) )
V_98 = V_118 ;
else
V_98 = V_119 ;
break;
case V_59 :
if ( V_8 -> V_9 == V_31 )
V_98 = V_120 ;
else if ( V_8 -> V_12 != V_12 )
V_98 = V_121 ;
else if ( V_41 == 7 && V_8 -> V_11 != V_11 )
V_98 = V_121 ;
else
V_98 = V_120 ;
break;
default:
F_32 ( L_20 ) ;
F_14 ( & V_8 -> V_33 ) ;
F_26 () ;
return;
}
} else {
F_13 ( & V_8 -> V_33 ) ;
}
F_32 ( L_21 ,
V_43 -> V_52 , V_103 [ V_8 -> V_9 ] ,
F_55 ( V_8 -> V_11 ) , F_55 ( V_8 -> V_12 ) ,
V_98 ) ;
V_13 = 0 ;
switch ( V_8 -> V_9 ) {
case V_10 :
switch ( V_98 ) {
case V_120 :
F_6 ( V_8 ) ;
F_14 ( & V_8 -> V_33 ) ;
break;
case V_116 :
V_8 -> V_9 = V_80 ;
V_8 -> V_12 = V_12 ;
F_34 ( & V_11 , 2 ) ;
V_8 -> V_11 = V_11 ;
F_42 ( V_8 , F_44 ( V_2 ) ) ;
F_14 ( & V_8 -> V_33 ) ;
F_16 ( V_2 , V_62 , V_8 -> V_8 . V_54 , V_11 ,
0 , 0 ) ;
F_16 ( V_2 , V_61 , V_8 -> V_8 . V_54 ,
V_11 , V_12 , 0 ) ;
break;
default:
F_14 ( & V_8 -> V_33 ) ;
break;
}
break;
case V_81 :
switch ( V_98 ) {
case V_113 :
case V_114 :
V_13 = F_20 ( V_115 ) ;
case V_120 :
if ( ! V_13 )
V_13 = F_20 ( V_122 ) ;
V_8 -> V_13 = V_13 ;
V_8 -> V_9 = V_86 ;
if ( ! F_35 ( V_8 ,
F_36 ( V_2 ) ) )
V_8 -> V_79 = true ;
V_11 = V_8 -> V_11 ;
F_14 ( & V_8 -> V_33 ) ;
F_16 ( V_2 , V_59 , V_8 -> V_8 . V_54 , V_11 ,
V_12 , V_13 ) ;
break;
case V_116 :
V_8 -> V_9 = V_80 ;
V_8 -> V_12 = V_12 ;
V_11 = V_8 -> V_11 ;
F_14 ( & V_8 -> V_33 ) ;
F_16 ( V_2 , V_61 , V_8 -> V_8 . V_54 , V_11 ,
V_12 , 0 ) ;
break;
case V_119 :
V_8 -> V_9 = V_84 ;
if ( ! F_35 ( V_8 ,
F_56 ( V_2 ) ) )
V_8 -> V_79 = true ;
F_14 ( & V_8 -> V_33 ) ;
break;
default:
F_14 ( & V_8 -> V_33 ) ;
break;
}
break;
case V_80 :
switch ( V_98 ) {
case V_113 :
case V_114 :
V_13 = F_20 ( V_115 ) ;
case V_120 :
if ( ! V_13 )
V_13 = F_20 ( V_122 ) ;
V_8 -> V_13 = V_13 ;
V_8 -> V_9 = V_86 ;
if ( ! F_35 ( V_8 ,
F_36 ( V_2 ) ) )
V_8 -> V_79 = true ;
V_11 = V_8 -> V_11 ;
F_14 ( & V_8 -> V_33 ) ;
F_16 ( V_2 , V_59 , V_8 -> V_8 . V_54 , V_11 ,
V_12 , V_13 ) ;
break;
case V_116 :
V_11 = V_8 -> V_11 ;
F_14 ( & V_8 -> V_33 ) ;
F_16 ( V_2 , V_61 , V_8 -> V_8 . V_54 , V_11 ,
V_12 , 0 ) ;
break;
case V_119 :
F_37 ( & V_8 -> V_87 ) ;
V_8 -> V_9 = V_31 ;
F_14 ( & V_8 -> V_33 ) ;
F_1 ( V_2 ) ;
F_15 ( V_2 , V_34 ) ;
F_32 ( L_22 ,
V_8 -> V_8 . V_54 ) ;
break;
default:
F_14 ( & V_8 -> V_33 ) ;
break;
}
break;
case V_84 :
switch ( V_98 ) {
case V_113 :
case V_114 :
V_13 = F_20 ( V_115 ) ;
case V_120 :
if ( ! V_13 )
V_13 = F_20 ( V_122 ) ;
V_8 -> V_13 = V_13 ;
V_8 -> V_9 = V_86 ;
if ( ! F_35 ( V_8 ,
F_36 ( V_2 ) ) )
V_8 -> V_79 = true ;
V_11 = V_8 -> V_11 ;
F_14 ( & V_8 -> V_33 ) ;
F_16 ( V_2 , V_59 , V_8 -> V_8 . V_54 , V_11 ,
V_12 , V_13 ) ;
break;
case V_116 :
F_37 ( & V_8 -> V_87 ) ;
V_8 -> V_9 = V_31 ;
F_14 ( & V_8 -> V_33 ) ;
F_1 ( V_2 ) ;
F_15 ( V_2 , V_34 ) ;
F_32 ( L_22 ,
V_8 -> V_8 . V_54 ) ;
F_16 ( V_2 , V_61 , V_8 -> V_8 . V_54 , V_11 ,
V_12 , 0 ) ;
break;
default:
F_14 ( & V_8 -> V_33 ) ;
break;
}
break;
case V_31 :
switch ( V_98 ) {
case V_120 :
V_13 = F_20 ( V_122 ) ;
V_8 -> V_13 = V_13 ;
V_30 = F_10 ( V_8 ) ;
V_8 -> V_9 = V_86 ;
V_11 = V_8 -> V_11 ;
F_35 ( V_8 , F_36 ( V_2 ) ) ;
F_14 ( & V_8 -> V_33 ) ;
if ( V_30 )
F_15 ( V_2 , V_34 ) ;
F_16 ( V_2 , V_59 , V_8 -> V_8 . V_54 , V_11 ,
V_12 , V_13 ) ;
break;
case V_116 :
V_11 = V_8 -> V_11 ;
F_14 ( & V_8 -> V_33 ) ;
F_16 ( V_2 , V_61 , V_8 -> V_8 . V_54 , V_11 ,
V_12 , 0 ) ;
break;
default:
F_14 ( & V_8 -> V_33 ) ;
break;
}
break;
case V_86 :
switch ( V_98 ) {
case V_120 :
if ( F_37 ( & V_8 -> V_87 ) )
V_8 -> V_79 = 1 ;
F_6 ( V_8 ) ;
F_14 ( & V_8 -> V_33 ) ;
break;
case V_116 :
case V_119 :
case V_113 :
case V_114 :
V_11 = V_8 -> V_11 ;
V_13 = V_8 -> V_13 ;
F_14 ( & V_8 -> V_33 ) ;
F_16 ( V_2 , V_59 , V_8 -> V_8 . V_54 ,
V_11 , V_12 , V_13 ) ;
break;
default:
F_14 ( & V_8 -> V_33 ) ;
}
break;
default:
F_14 ( & V_8 -> V_33 ) ;
break;
}
F_26 () ;
}
