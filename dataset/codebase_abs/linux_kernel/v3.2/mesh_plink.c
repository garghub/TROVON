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
F_9 ( V_8 , V_22 ) ;
F_9 ( V_8 , V_23 ) ;
F_9 ( V_8 , V_24 ) ;
V_8 -> V_8 . V_25 [ V_18 -> V_26 . V_27 . V_28 -> V_29 ] = V_16 ;
F_10 ( V_8 ) ;
return V_8 ;
}
static bool F_11 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
bool V_30 = false ;
if ( V_8 -> V_9 == V_31 ) {
F_4 ( V_2 ) ;
V_30 = true ;
}
V_8 -> V_9 = V_32 ;
F_12 ( V_8 ) ;
return V_30 ;
}
void F_13 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
bool V_30 ;
F_14 ( & V_8 -> V_33 ) ;
V_30 = F_11 ( V_8 ) ;
V_8 -> V_13 = F_15 ( V_34 ) ;
F_16 ( V_2 , V_35 ,
V_8 -> V_8 . V_36 , V_8 -> V_11 , V_8 -> V_12 ,
V_8 -> V_13 ) ;
F_17 ( & V_8 -> V_33 ) ;
if ( V_30 )
F_18 ( V_2 , V_37 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
enum V_38 V_39 ,
T_1 * V_40 , T_3 V_11 , T_3 V_12 , T_3 V_13 ) {
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_41 * V_42 = F_19 ( V_18 -> V_26 . V_43 + 400 +
V_2 -> V_3 . V_4 . V_44 ) ;
struct V_45 * V_46 ;
bool V_47 = false ;
int V_44 = 4 ;
T_4 V_48 = 0 ;
T_1 * V_49 ;
if ( ! V_42 )
return - 1 ;
F_20 ( V_42 , V_18 -> V_26 . V_43 ) ;
V_46 = (struct V_45 * )
F_21 ( V_42 , 25 + sizeof( V_46 -> V_3 . V_39 . V_3 . V_50 ) ) ;
memset ( V_46 , 0 , 25 + sizeof( V_46 -> V_3 . V_39 . V_3 . V_50 ) ) ;
V_46 -> V_51 = F_15 ( V_52 |
V_53 ) ;
memcpy ( V_46 -> V_40 , V_40 , V_54 ) ;
memcpy ( V_46 -> V_55 , V_2 -> V_56 . V_36 , V_54 ) ;
memcpy ( V_46 -> V_57 , V_2 -> V_56 . V_36 , V_54 ) ;
V_46 -> V_3 . V_39 . V_58 = V_59 ;
V_46 -> V_3 . V_39 . V_3 . V_50 . V_60 = V_39 ;
if ( V_39 != V_35 ) {
V_49 = F_21 ( V_42 , 2 ) ;
memset ( V_49 , 0 , 2 ) ;
if ( V_39 == V_61 ) {
V_49 = F_21 ( V_42 , 2 ) ;
memcpy ( V_49 + 2 , & V_12 , 2 ) ;
}
if ( F_22 ( & V_2 -> V_56 , V_42 ) ||
F_23 ( & V_2 -> V_56 , V_42 ) ||
F_24 ( V_42 , V_2 ) ||
F_25 ( V_42 , V_2 ) ||
F_26 ( V_42 , V_2 ) )
return - 1 ;
} else {
if ( F_25 ( V_42 , V_2 ) )
return - 1 ;
}
switch ( V_39 ) {
case V_62 :
break;
case V_61 :
V_44 += 2 ;
V_47 = true ;
break;
case V_35 :
if ( V_12 ) {
V_44 += 2 ;
V_47 = true ;
}
V_44 += 2 ;
break;
default:
return - V_63 ;
}
if ( F_27 ( F_28 ( V_42 ) < 2 + V_44 ) )
return - V_64 ;
V_49 = F_21 ( V_42 , 2 + V_44 ) ;
* V_49 ++ = V_65 ;
* V_49 ++ = V_44 ;
memcpy ( V_49 , & V_48 , 2 ) ;
V_49 += 2 ;
memcpy ( V_49 , & V_11 , 2 ) ;
V_49 += 2 ;
if ( V_47 ) {
memcpy ( V_49 , & V_12 , 2 ) ;
V_49 += 2 ;
}
if ( V_39 == V_35 ) {
memcpy ( V_49 , & V_13 , 2 ) ;
V_49 += 2 ;
}
if ( F_29 ( V_42 , V_2 ) )
return - 1 ;
F_30 ( V_2 , V_42 ) ;
return 0 ;
}
void F_31 ( T_1 * V_15 , T_2 V_16 ,
struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_7 * V_8 ;
F_32 () ;
V_8 = F_33 ( V_2 , V_15 ) ;
if ( ! V_8 ) {
F_34 () ;
if ( V_2 -> V_3 . V_4 . V_68 & V_69 )
F_35 ( V_2 -> V_70 , V_15 ,
V_67 -> V_71 , V_67 -> V_72 ,
V_21 ) ;
else
V_8 = F_7 ( V_2 , V_15 , V_16 ) ;
if ( ! V_8 )
return;
if ( F_36 ( V_8 ) ) {
F_34 () ;
return;
}
}
V_8 -> V_73 = V_74 ;
V_8 -> V_8 . V_25 [ V_18 -> V_26 . V_27 . V_28 -> V_29 ] = V_16 ;
if ( F_37 ( V_67 ) &&
V_8 -> V_9 == V_10 &&
V_2 -> V_3 . V_4 . V_75 &&
V_2 -> V_3 . V_4 . V_76 . V_77 )
F_38 ( V_8 ) ;
F_34 () ;
}
static void F_39 ( unsigned long V_78 )
{
struct V_7 * V_8 ;
T_3 V_11 , V_12 , V_13 ;
struct V_1 * V_2 ;
V_8 = (struct V_7 * ) V_78 ;
if ( V_8 -> V_2 -> V_18 -> V_79 ) {
V_8 -> V_80 = true ;
return;
}
F_14 ( & V_8 -> V_33 ) ;
if ( V_8 -> V_81 ) {
V_8 -> V_81 = false ;
F_17 ( & V_8 -> V_33 ) ;
return;
}
F_40 ( L_1 ,
V_8 -> V_8 . V_36 , V_8 -> V_9 ) ;
V_13 = 0 ;
V_11 = V_8 -> V_11 ;
V_12 = V_8 -> V_12 ;
V_2 = V_8 -> V_2 ;
switch ( V_8 -> V_9 ) {
case V_82 :
case V_83 :
if ( V_8 -> V_14 < F_41 ( V_2 ) ) {
T_2 rand ;
F_40 ( L_2 ,
V_8 -> V_8 . V_36 , V_8 -> V_14 ,
V_8 -> V_84 ) ;
F_42 ( & rand , sizeof( T_2 ) ) ;
V_8 -> V_84 = V_8 -> V_84 +
rand % V_8 -> V_84 ;
++ V_8 -> V_14 ;
F_43 ( V_8 , V_8 -> V_84 ) ;
F_17 ( & V_8 -> V_33 ) ;
F_16 ( V_2 , V_62 ,
V_8 -> V_8 . V_36 , V_11 , 0 , 0 ) ;
break;
}
V_13 = F_15 ( V_85 ) ;
case V_86 :
if ( ! V_13 )
V_13 = F_15 ( V_87 ) ;
V_8 -> V_9 = V_88 ;
F_43 ( V_8 , F_44 ( V_2 ) ) ;
F_17 ( & V_8 -> V_33 ) ;
F_16 ( V_2 , V_35 ,
V_8 -> V_8 . V_36 , V_11 , V_12 , V_13 ) ;
break;
case V_88 :
F_45 ( & V_8 -> V_89 ) ;
F_6 ( V_8 ) ;
F_17 ( & V_8 -> V_33 ) ;
break;
default:
F_17 ( & V_8 -> V_33 ) ;
break;
}
}
void F_46 ( struct V_7 * V_8 )
{
if ( F_47 ( & V_8 -> V_89 ) )
V_8 -> V_80 = true ;
}
void F_48 ( struct V_7 * V_8 )
{
if ( V_8 -> V_80 ) {
F_49 ( & V_8 -> V_89 ) ;
V_8 -> V_80 = false ;
}
}
static inline void F_50 ( struct V_7 * V_8 , int V_90 )
{
V_8 -> V_89 . V_91 = V_74 + ( V_92 * V_90 / 1000 ) ;
V_8 -> V_89 . V_78 = ( unsigned long ) V_8 ;
V_8 -> V_89 . V_93 = F_39 ;
V_8 -> V_84 = V_90 ;
F_49 ( & V_8 -> V_89 ) ;
}
int F_38 ( struct V_7 * V_8 )
{
T_3 V_11 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_51 ( V_8 , V_22 ) )
return - V_94 ;
F_14 ( & V_8 -> V_33 ) ;
F_42 ( & V_11 , 2 ) ;
V_8 -> V_11 = V_11 ;
if ( V_8 -> V_9 != V_10 ) {
F_17 ( & V_8 -> V_33 ) ;
return - V_95 ;
}
V_8 -> V_9 = V_83 ;
F_50 ( V_8 , F_52 ( V_2 ) ) ;
F_17 ( & V_8 -> V_33 ) ;
F_40 ( L_3 ,
V_8 -> V_8 . V_36 ) ;
return F_16 ( V_2 , V_62 ,
V_8 -> V_8 . V_36 , V_11 , 0 , 0 ) ;
}
void F_53 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
bool V_30 ;
F_14 ( & V_8 -> V_33 ) ;
V_30 = F_11 ( V_8 ) ;
V_8 -> V_9 = V_32 ;
F_17 ( & V_8 -> V_33 ) ;
if ( V_30 )
F_18 ( V_2 , V_37 ) ;
}
void F_54 ( struct V_1 * V_2 , struct V_45 * V_46 ,
T_5 V_96 , struct V_97 * V_98 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_66 V_67 ;
struct V_7 * V_8 ;
enum V_99 V_100 ;
enum V_38 V_101 ;
T_5 V_102 ;
bool V_30 , V_103 = true ;
T_1 V_44 ;
T_1 * V_104 ;
T_3 V_12 , V_11 , V_13 ;
#ifdef F_55
static const char * V_105 [] = {
[ V_10 ] = L_4 ,
[ V_83 ] = L_5 ,
[ V_82 ] = L_6 ,
[ V_86 ] = L_7 ,
[ V_31 ] = L_8 ,
[ V_88 ] = L_9 ,
[ V_32 ] = L_10
} ;
#endif
if ( V_96 < V_106 + 3 )
return;
if ( F_56 ( V_46 -> V_40 ) ) {
F_40 ( L_11 ) ;
return;
}
V_104 = V_46 -> V_3 . V_39 . V_3 . V_50 . V_107 ;
V_102 = ( T_1 * ) V_46 -> V_3 . V_39 . V_3 . V_50 . V_107 - ( T_1 * ) V_46 ;
if ( V_46 -> V_3 . V_39 . V_3 . V_50 . V_60 ==
V_61 ) {
V_104 += 4 ;
V_102 += 4 ;
}
F_57 ( V_104 , V_96 - V_102 , & V_67 ) ;
if ( ! V_67 . V_108 ) {
F_40 ( L_12 ) ;
return;
}
if ( V_67 . V_109 &&
V_2 -> V_3 . V_4 . V_68 == V_110 ) {
F_40 ( L_13 ) ;
return;
}
V_101 = V_46 -> V_3 . V_39 . V_3 . V_50 . V_60 ;
V_44 = V_67 . V_111 ;
if ( ( V_101 == V_62 && V_44 != 4 ) ||
( V_101 == V_61 && V_44 != 6 ) ||
( V_101 == V_35 && V_44 != 6
&& V_44 != 8 ) ) {
F_40 ( L_14 ,
V_101 , V_44 ) ;
return;
}
if ( V_101 != V_35 &&
( ! V_67 . V_112 || ! V_67 . V_113 ) ) {
F_40 ( L_15 ) ;
return;
}
memcpy ( & V_12 , F_58 ( V_67 . V_108 ) , 2 ) ;
if ( V_101 == V_61 ||
( V_101 == V_35 && V_44 == 8 ) )
memcpy ( & V_11 , F_59 ( V_67 . V_108 ) , 2 ) ;
F_32 () ;
V_8 = F_33 ( V_2 , V_46 -> V_55 ) ;
if ( ! V_8 && V_101 != V_62 ) {
F_40 ( L_16 ) ;
F_34 () ;
return;
}
if ( V_8 && ! F_51 ( V_8 , V_22 ) ) {
F_40 ( L_17 ) ;
F_34 () ;
return;
}
if ( V_8 && V_8 -> V_9 == V_32 ) {
F_34 () ;
return;
}
V_100 = V_114 ;
if ( V_101 != V_35 &&
( ! F_60 ( & V_67 , V_2 ) ) ) {
V_103 = false ;
switch ( V_101 ) {
case V_62 :
V_100 = V_115 ;
break;
case V_61 :
V_100 = V_116 ;
break;
default:
break;
}
}
if ( ! V_8 && ! V_103 ) {
F_34 () ;
V_13 = F_15 ( V_117 ) ;
V_11 = 0 ;
F_16 ( V_2 , V_35 ,
V_46 -> V_55 , V_11 , V_12 , V_13 ) ;
return;
} else if ( ! V_8 ) {
T_2 V_16 ;
F_34 () ;
if ( ! F_61 ( V_2 ) ) {
F_40 ( L_18 ) ;
return;
}
V_16 = F_62 ( V_18 , & V_67 , V_98 -> V_29 ) ;
V_8 = F_7 ( V_2 , V_46 -> V_55 , V_16 ) ;
if ( ! V_8 ) {
F_40 ( L_19 ) ;
return;
}
if ( F_36 ( V_8 ) ) {
F_34 () ;
return;
}
V_100 = V_118 ;
F_14 ( & V_8 -> V_33 ) ;
} else if ( V_103 ) {
F_14 ( & V_8 -> V_33 ) ;
switch ( V_101 ) {
case V_62 :
if ( ! F_61 ( V_2 ) ||
( V_8 -> V_12 && V_8 -> V_12 != V_12 ) )
V_100 = V_119 ;
else
V_100 = V_118 ;
break;
case V_61 :
if ( ! F_61 ( V_2 ) ||
( V_8 -> V_11 != V_11 || V_8 -> V_12 != V_12 ) )
V_100 = V_120 ;
else
V_100 = V_121 ;
break;
case V_35 :
if ( V_8 -> V_9 == V_31 )
V_100 = V_122 ;
else if ( V_8 -> V_12 != V_12 )
V_100 = V_123 ;
else if ( V_44 == 7 && V_8 -> V_11 != V_11 )
V_100 = V_123 ;
else
V_100 = V_122 ;
break;
default:
F_40 ( L_20 ) ;
F_17 ( & V_8 -> V_33 ) ;
F_34 () ;
return;
}
} else {
F_14 ( & V_8 -> V_33 ) ;
}
F_40 ( L_21 ,
V_46 -> V_55 , V_105 [ V_8 -> V_9 ] ,
F_63 ( V_8 -> V_11 ) , F_63 ( V_8 -> V_12 ) ,
V_100 ) ;
V_13 = 0 ;
switch ( V_8 -> V_9 ) {
case V_10 :
switch ( V_100 ) {
case V_122 :
F_6 ( V_8 ) ;
F_17 ( & V_8 -> V_33 ) ;
break;
case V_118 :
V_8 -> V_9 = V_82 ;
V_8 -> V_12 = V_12 ;
F_42 ( & V_11 , 2 ) ;
V_8 -> V_11 = V_11 ;
F_50 ( V_8 , F_52 ( V_2 ) ) ;
F_17 ( & V_8 -> V_33 ) ;
F_16 ( V_2 ,
V_62 ,
V_8 -> V_8 . V_36 , V_11 , 0 , 0 ) ;
F_16 ( V_2 ,
V_61 ,
V_8 -> V_8 . V_36 , V_11 , V_12 , 0 ) ;
break;
default:
F_17 ( & V_8 -> V_33 ) ;
break;
}
break;
case V_83 :
switch ( V_100 ) {
case V_115 :
case V_116 :
V_13 = F_15 ( V_117 ) ;
case V_122 :
if ( ! V_13 )
V_13 = F_15 ( V_124 ) ;
V_8 -> V_13 = V_13 ;
V_8 -> V_9 = V_88 ;
if ( ! F_43 ( V_8 ,
F_44 ( V_2 ) ) )
V_8 -> V_81 = true ;
V_11 = V_8 -> V_11 ;
F_17 ( & V_8 -> V_33 ) ;
F_16 ( V_2 ,
V_35 ,
V_8 -> V_8 . V_36 , V_11 , V_12 , V_13 ) ;
break;
case V_118 :
V_8 -> V_9 = V_82 ;
V_8 -> V_12 = V_12 ;
V_11 = V_8 -> V_11 ;
F_17 ( & V_8 -> V_33 ) ;
F_16 ( V_2 ,
V_61 ,
V_8 -> V_8 . V_36 , V_11 , V_12 , 0 ) ;
break;
case V_121 :
V_8 -> V_9 = V_86 ;
if ( ! F_43 ( V_8 ,
F_64 ( V_2 ) ) )
V_8 -> V_81 = true ;
F_17 ( & V_8 -> V_33 ) ;
break;
default:
F_17 ( & V_8 -> V_33 ) ;
break;
}
break;
case V_82 :
switch ( V_100 ) {
case V_115 :
case V_116 :
V_13 = F_15 ( V_117 ) ;
case V_122 :
if ( ! V_13 )
V_13 = F_15 ( V_124 ) ;
V_8 -> V_13 = V_13 ;
V_8 -> V_9 = V_88 ;
if ( ! F_43 ( V_8 ,
F_44 ( V_2 ) ) )
V_8 -> V_81 = true ;
V_11 = V_8 -> V_11 ;
F_17 ( & V_8 -> V_33 ) ;
F_16 ( V_2 , V_35 ,
V_8 -> V_8 . V_36 , V_11 , V_12 , V_13 ) ;
break;
case V_118 :
V_11 = V_8 -> V_11 ;
F_17 ( & V_8 -> V_33 ) ;
F_16 ( V_2 ,
V_61 ,
V_8 -> V_8 . V_36 , V_11 , V_12 , 0 ) ;
break;
case V_121 :
F_45 ( & V_8 -> V_89 ) ;
V_8 -> V_9 = V_31 ;
F_17 ( & V_8 -> V_33 ) ;
F_1 ( V_2 ) ;
F_18 ( V_2 , V_37 ) ;
F_40 ( L_22 ,
V_8 -> V_8 . V_36 ) ;
break;
default:
F_17 ( & V_8 -> V_33 ) ;
break;
}
break;
case V_86 :
switch ( V_100 ) {
case V_115 :
case V_116 :
V_13 = F_15 ( V_117 ) ;
case V_122 :
if ( ! V_13 )
V_13 = F_15 ( V_124 ) ;
V_8 -> V_13 = V_13 ;
V_8 -> V_9 = V_88 ;
if ( ! F_43 ( V_8 ,
F_44 ( V_2 ) ) )
V_8 -> V_81 = true ;
V_11 = V_8 -> V_11 ;
F_17 ( & V_8 -> V_33 ) ;
F_16 ( V_2 ,
V_35 ,
V_8 -> V_8 . V_36 , V_11 , V_12 , V_13 ) ;
break;
case V_118 :
F_45 ( & V_8 -> V_89 ) ;
V_8 -> V_9 = V_31 ;
F_17 ( & V_8 -> V_33 ) ;
F_1 ( V_2 ) ;
F_18 ( V_2 , V_37 ) ;
F_40 ( L_22 ,
V_8 -> V_8 . V_36 ) ;
F_16 ( V_2 ,
V_61 ,
V_8 -> V_8 . V_36 , V_11 , V_12 , 0 ) ;
break;
default:
F_17 ( & V_8 -> V_33 ) ;
break;
}
break;
case V_31 :
switch ( V_100 ) {
case V_122 :
V_13 = F_15 ( V_124 ) ;
V_8 -> V_13 = V_13 ;
V_30 = F_11 ( V_8 ) ;
V_8 -> V_9 = V_88 ;
V_11 = V_8 -> V_11 ;
F_43 ( V_8 , F_44 ( V_2 ) ) ;
F_17 ( & V_8 -> V_33 ) ;
if ( V_30 )
F_18 ( V_2 , V_37 ) ;
F_16 ( V_2 , V_35 ,
V_8 -> V_8 . V_36 , V_11 , V_12 , V_13 ) ;
break;
case V_118 :
V_11 = V_8 -> V_11 ;
F_17 ( & V_8 -> V_33 ) ;
F_16 ( V_2 ,
V_61 ,
V_8 -> V_8 . V_36 , V_11 , V_12 , 0 ) ;
break;
default:
F_17 ( & V_8 -> V_33 ) ;
break;
}
break;
case V_88 :
switch ( V_100 ) {
case V_122 :
if ( F_45 ( & V_8 -> V_89 ) )
V_8 -> V_81 = 1 ;
F_6 ( V_8 ) ;
F_17 ( & V_8 -> V_33 ) ;
break;
case V_118 :
case V_121 :
case V_115 :
case V_116 :
V_11 = V_8 -> V_11 ;
V_13 = V_8 -> V_13 ;
F_17 ( & V_8 -> V_33 ) ;
F_16 ( V_2 , V_35 ,
V_8 -> V_8 . V_36 , V_11 , V_12 , V_13 ) ;
break;
default:
F_17 ( & V_8 -> V_33 ) ;
}
break;
default:
F_17 ( & V_8 -> V_33 ) ;
break;
}
F_34 () ;
}
