int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 ,
unsigned V_6 , T_1 V_7 , T_1 V_8 )
{
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return - V_12 ;
F_3 ( & V_2 -> V_10 . V_13 ) ;
V_9 = F_4 ( & V_2 -> V_10 . V_11 , V_4 ,
V_5 , V_6 , 0 ,
V_7 , V_8 , V_14 ) ;
F_5 ( & V_2 -> V_10 . V_13 ) ;
return V_9 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 ,
unsigned V_6 )
{
return F_1 ( V_2 , V_4 , V_5 ,
V_6 , 0 , V_15 ) ;
}
void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_3 ( & V_2 -> V_10 . V_13 ) ;
F_8 ( V_4 ) ;
F_5 ( & V_2 -> V_10 . V_13 ) ;
}
static unsigned long F_9 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_18 . V_17 ;
struct V_19 * V_20 = & V_2 -> V_20 ;
struct V_21 * V_22 ;
T_2 V_23 ;
V_23 = 0 ;
if ( F_10 ( V_2 ) >= 3 ) {
T_2 V_24 ;
F_11 ( V_17 , V_25 , & V_24 ) ;
V_23 = V_24 & V_26 ;
} else if ( F_12 ( V_2 ) ) {
T_2 V_27 = 0 ;
T_3 V_28 = 0 ;
T_4 V_29 ;
F_13 ( V_17 -> V_30 , F_14 ( 0 , 0 ) ,
V_31 , & V_29 ) ;
if ( V_29 & V_32 ) {
switch ( V_29 & V_33 ) {
case V_34 :
V_27 = F_15 ( 512 ) ;
break;
case V_35 :
V_27 = F_16 ( 1 ) ;
break;
}
}
F_17 ( V_17 -> V_30 , F_14 ( 0 , 0 ) ,
V_36 , & V_28 ) ;
V_23 = ( V_28 << 16 ) + V_27 ;
} else if ( F_18 ( V_2 ) ) {
T_2 V_27 = 0 ;
T_2 V_37 ;
T_4 V_29 ;
F_13 ( V_17 -> V_30 , F_14 ( 0 , 0 ) ,
V_38 , & V_29 ) ;
if ( V_29 & V_32 )
V_27 = F_16 ( 1 ) ;
F_13 ( V_17 -> V_30 , F_14 ( 0 , 1 ) ,
V_39 , & V_29 ) ;
V_37 = V_29 * F_16 ( 32 ) ;
V_23 = V_37 - V_27 - V_20 -> V_40 ;
} else if ( F_19 ( V_2 ) ) {
T_2 V_27 = 0 ;
T_2 V_37 ;
T_4 V_29 ;
F_13 ( V_17 -> V_30 , F_14 ( 0 , 0 ) ,
V_31 , & V_29 ) ;
if ( V_29 & V_32 ) {
switch ( V_29 & V_33 ) {
case V_34 :
V_27 = F_15 ( 512 ) ;
break;
case V_35 :
V_27 = F_16 ( 1 ) ;
break;
}
}
F_13 ( V_17 -> V_30 , F_14 ( 0 , 0 ) ,
V_41 , & V_29 ) ;
V_37 = V_29 * F_16 ( 32 ) ;
V_23 = V_37 - V_27 - V_20 -> V_40 ;
} else if ( F_20 ( V_2 ) ) {
T_2 V_27 = 0 ;
T_2 V_37 ;
T_4 V_29 ;
F_13 ( V_17 -> V_30 , F_14 ( 0 , 0 ) ,
V_42 , & V_29 ) ;
if ( V_29 & V_32 ) {
if ( V_29 & V_43 )
V_27 = F_16 ( 1 ) ;
else
V_27 = F_15 ( 512 ) ;
}
F_13 ( V_17 -> V_30 , F_14 ( 0 , 0 ) ,
V_41 , & V_29 ) ;
V_37 = V_29 * F_16 ( 32 ) ;
V_23 = V_37 - V_27 - V_20 -> V_40 ;
}
if ( V_23 == 0 )
return 0 ;
if ( F_10 ( V_2 ) <= 4 &&
! F_21 ( V_2 ) && ! F_22 ( V_2 ) && ! F_23 ( V_2 ) ) {
struct {
T_2 V_7 , V_8 ;
} V_11 [ 2 ] = {
{ . V_7 = V_23 , . V_8 = V_23 + V_20 -> V_40 , } ,
{ . V_7 = V_23 , . V_8 = V_23 + V_20 -> V_40 , } ,
} ;
T_1 V_44 , V_45 ;
V_44 = F_24 ( V_46 ) ;
if ( F_25 ( V_2 ) )
V_44 = ( V_44 & V_47 ) |
( V_44 & V_48 ) << 28 ;
else
V_44 &= V_47 ;
V_45 = V_44 + F_26 ( V_20 ) * 4 ;
if ( V_44 >= V_11 [ 0 ] . V_7 && V_44 < V_11 [ 0 ] . V_8 )
V_11 [ 0 ] . V_8 = V_44 ;
if ( V_45 > V_11 [ 1 ] . V_7 && V_45 <= V_11 [ 1 ] . V_8 )
V_11 [ 1 ] . V_7 = V_45 ;
if ( V_11 [ 0 ] . V_8 - V_11 [ 0 ] . V_7 >
V_11 [ 1 ] . V_8 - V_11 [ 1 ] . V_7 ) {
V_23 = V_11 [ 0 ] . V_7 ;
V_20 -> V_40 = V_11 [ 0 ] . V_8 - V_11 [ 0 ] . V_7 ;
} else {
V_23 = V_11 [ 1 ] . V_7 ;
V_20 -> V_40 = V_11 [ 1 ] . V_8 - V_11 [ 1 ] . V_7 ;
}
if ( V_11 [ 0 ] . V_7 != V_11 [ 1 ] . V_7 ||
V_11 [ 0 ] . V_8 != V_11 [ 1 ] . V_8 ) {
F_27 ( L_1 ,
( unsigned long long ) V_44 ,
( unsigned long long ) V_45 - 1 ) ;
F_27 ( L_2 ,
V_23 , V_23 + ( T_2 ) V_20 -> V_40 - 1 ) ;
}
}
V_22 = F_28 ( V_2 -> V_18 . V_49 , V_23 , V_20 -> V_40 ,
L_3 ) ;
if ( V_22 == NULL ) {
V_22 = F_28 ( V_2 -> V_18 . V_49 , V_23 + 1 ,
V_20 -> V_40 - 1 ,
L_3 ) ;
if ( V_22 == NULL && ! F_29 ( V_2 ) ) {
F_30 ( L_4 ,
V_23 , V_23 + ( V_50 ) V_20 -> V_40 ) ;
V_23 = 0 ;
}
}
return V_23 ;
}
void F_31 ( struct V_51 * V_49 )
{
struct V_1 * V_2 = F_32 ( V_49 ) ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return;
F_33 ( & V_2 -> V_10 . V_11 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
T_5 * V_23 , T_2 * V_5 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
V_50 V_52 = F_24 ( F_35 ( V_2 ) ?
V_53 :
V_54 ) ;
T_5 V_55 = V_2 -> V_10 . V_56 + V_20 -> V_40 ;
* V_23 = ( V_52 & V_57 ) << 16 ;
F_36 ( ( V_52 & V_58 ) < * V_23 ) ;
if ( * V_23 == 0 )
* V_5 = 0 ;
else
* V_5 = V_55 - * V_23 ;
}
static void F_37 ( struct V_1 * V_2 ,
T_5 * V_23 , T_2 * V_5 )
{
V_50 V_52 = F_24 ( V_59 ) ;
* V_23 = V_52 & V_60 ;
switch ( V_52 & V_61 ) {
case V_62 :
* V_5 = 1024 * 1024 ;
break;
case V_63 :
* V_5 = 512 * 1024 ;
break;
case V_64 :
* V_5 = 256 * 1024 ;
break;
case V_65 :
* V_5 = 128 * 1024 ;
break;
default:
* V_5 = 1024 * 1024 ;
F_38 ( V_52 & V_61 ) ;
}
}
static void F_39 ( struct V_1 * V_2 ,
T_5 * V_23 , T_2 * V_5 )
{
V_50 V_52 = F_24 ( V_59 ) ;
* V_23 = V_52 & V_66 ;
switch ( V_52 & V_67 ) {
case V_68 :
* V_5 = 1024 * 1024 ;
break;
case V_69 :
* V_5 = 256 * 1024 ;
break;
default:
* V_5 = 1024 * 1024 ;
F_38 ( V_52 & V_67 ) ;
}
}
static void F_40 ( struct V_1 * V_2 ,
T_5 * V_23 , T_2 * V_5 )
{
V_50 V_52 = F_24 ( V_59 ) ;
* V_23 = V_52 & V_60 ;
switch ( V_52 & V_70 ) {
case V_71 :
* V_5 = 1024 * 1024 ;
break;
case V_72 :
* V_5 = 2 * 1024 * 1024 ;
break;
case V_73 :
* V_5 = 4 * 1024 * 1024 ;
break;
case V_74 :
* V_5 = 8 * 1024 * 1024 ;
break;
default:
* V_5 = 8 * 1024 * 1024 ;
F_38 ( V_52 & V_70 ) ;
}
}
static void F_41 ( struct V_1 * V_2 ,
T_5 * V_23 , T_2 * V_5 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
V_50 V_52 = F_24 ( V_59 ) ;
T_5 V_55 ;
V_55 = V_2 -> V_10 . V_56 + V_20 -> V_40 ;
* V_23 = V_52 & V_60 ;
if ( * V_23 == 0 )
* V_5 = 0 ;
else
* V_5 = V_55 - * V_23 ;
}
int F_42 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
T_5 V_75 , V_55 ;
T_2 V_76 , V_77 ;
T_2 V_78 ;
F_43 ( & V_2 -> V_10 . V_13 ) ;
if ( F_44 ( V_2 ) ) {
F_45 ( L_5 ) ;
return 0 ;
}
#ifdef F_46
if ( V_79 && F_10 ( V_2 ) < 8 ) {
F_45 ( L_6 ) ;
return 0 ;
}
#endif
if ( V_20 -> V_40 == 0 )
return 0 ;
V_2 -> V_10 . V_56 = F_9 ( V_2 ) ;
if ( V_2 -> V_10 . V_56 == 0 )
return 0 ;
V_55 = V_2 -> V_10 . V_56 + V_20 -> V_40 ;
V_75 = 0 ;
V_77 = 0 ;
switch ( F_47 ( V_2 ) -> V_80 ) {
case 2 :
case 3 :
break;
case 4 :
if ( F_23 ( V_2 ) )
F_34 ( V_2 ,
& V_75 , & V_77 ) ;
break;
case 5 :
V_77 = 1024 * 1024 ;
V_75 = V_55 - V_77 ;
break;
case 6 :
F_37 ( V_2 ,
& V_75 , & V_77 ) ;
break;
case 7 :
F_39 ( V_2 ,
& V_75 , & V_77 ) ;
break;
default:
if ( F_48 ( V_2 ) )
F_40 ( V_2 ,
& V_75 , & V_77 ) ;
else
F_41 ( V_2 ,
& V_75 , & V_77 ) ;
break;
}
if ( V_75 == 0 ) {
V_77 = 0 ;
V_75 = V_55 ;
}
if ( V_75 < V_2 -> V_10 . V_56 ||
V_75 + V_77 > V_55 ) {
T_5 V_81 = V_75 + V_77 ;
F_27 ( L_7 ,
& V_75 , & V_81 ,
& V_2 -> V_10 . V_56 , & V_55 ) ;
return 0 ;
}
V_20 -> V_82 = V_75 ;
V_20 -> V_83 = V_77 ;
V_76 = V_55 - V_75 ;
F_27 ( L_8 ,
V_20 -> V_40 >> 10 ,
( V_20 -> V_40 - V_76 ) >> 10 ) ;
V_78 = 0 ;
if ( F_10 ( V_2 ) >= 8 )
V_78 = 4096 ;
V_20 -> V_84 =
V_20 -> V_40 - V_76 - V_78 ;
F_49 ( & V_2 -> V_10 . V_11 , V_78 ,
V_20 -> V_84 ) ;
return 0 ;
}
static struct V_85 *
F_50 ( struct V_51 * V_49 ,
T_2 V_86 , T_2 V_5 )
{
struct V_1 * V_2 = F_32 ( V_49 ) ;
struct V_85 * V_87 ;
struct V_88 * V_89 ;
F_51 ( F_52 ( V_86 , V_5 , V_2 -> V_20 . V_40 ) ) ;
V_87 = F_53 ( sizeof( * V_87 ) , V_90 ) ;
if ( V_87 == NULL )
return F_54 ( - V_91 ) ;
if ( F_55 ( V_87 , 1 , V_90 ) ) {
F_56 ( V_87 ) ;
return F_54 ( - V_91 ) ;
}
V_89 = V_87 -> V_92 ;
V_89 -> V_86 = 0 ;
V_89 -> V_93 = V_5 ;
F_57 ( V_89 ) = ( V_94 ) V_2 -> V_10 . V_56 + V_86 ;
F_58 ( V_89 ) = V_5 ;
return V_87 ;
}
static struct V_85 *
F_59 ( struct V_95 * V_96 )
{
return F_50 ( V_96 -> V_23 . V_49 ,
V_96 -> V_11 -> V_7 ,
V_96 -> V_11 -> V_5 ) ;
}
static void F_60 ( struct V_95 * V_96 ,
struct V_85 * V_97 )
{
F_61 ( V_97 ) ;
F_56 ( V_97 ) ;
}
static void
F_62 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_32 ( V_96 -> V_23 . V_49 ) ;
struct V_3 * V_11 = F_63 ( & V_96 -> V_11 ) ;
F_51 ( ! V_11 ) ;
F_64 ( V_96 ) ;
F_7 ( V_2 , V_11 ) ;
F_56 ( V_11 ) ;
}
static struct V_95 *
F_65 ( struct V_1 * V_2 ,
struct V_3 * V_11 )
{
struct V_95 * V_96 ;
V_96 = F_66 ( V_2 ) ;
if ( V_96 == NULL )
return NULL ;
F_67 ( & V_2 -> V_18 , & V_96 -> V_23 , V_11 -> V_5 ) ;
F_68 ( V_96 , & V_98 ) ;
V_96 -> V_11 = V_11 ;
V_96 -> V_23 . V_99 = V_100 | V_101 ;
V_96 -> V_102 = F_69 ( V_2 ) ? V_103 : V_104 ;
if ( F_70 ( V_96 ) )
goto V_105;
return V_96 ;
V_105:
F_71 ( V_96 ) ;
return NULL ;
}
struct V_95 *
F_72 ( struct V_1 * V_2 , T_2 V_5 )
{
struct V_95 * V_96 ;
struct V_3 * V_11 ;
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return NULL ;
if ( V_5 == 0 )
return NULL ;
V_11 = F_73 ( sizeof( * V_11 ) , V_90 ) ;
if ( ! V_11 )
return NULL ;
V_9 = F_6 ( V_2 , V_11 , V_5 , 4096 ) ;
if ( V_9 ) {
F_56 ( V_11 ) ;
return NULL ;
}
V_96 = F_65 ( V_2 , V_11 ) ;
if ( V_96 )
return V_96 ;
F_7 ( V_2 , V_11 ) ;
F_56 ( V_11 ) ;
return NULL ;
}
struct V_95 *
F_74 ( struct V_1 * V_2 ,
T_2 V_106 ,
T_2 V_107 ,
T_2 V_5 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
struct V_95 * V_96 ;
struct V_3 * V_11 ;
struct V_108 * V_109 ;
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return NULL ;
F_75 ( & V_2 -> V_18 . V_110 ) ;
F_27 ( L_9 ,
V_106 , V_107 , V_5 ) ;
if ( F_36 ( V_5 == 0 ) ||
F_36 ( ! F_76 ( V_5 , V_111 ) ) ||
F_36 ( ! F_76 ( V_106 , V_112 ) ) )
return NULL ;
V_11 = F_73 ( sizeof( * V_11 ) , V_90 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_7 = V_106 ;
V_11 -> V_5 = V_5 ;
F_3 ( & V_2 -> V_10 . V_13 ) ;
V_9 = F_77 ( & V_2 -> V_10 . V_11 , V_11 ) ;
F_5 ( & V_2 -> V_10 . V_13 ) ;
if ( V_9 ) {
F_27 ( L_10 ) ;
F_56 ( V_11 ) ;
return NULL ;
}
V_96 = F_65 ( V_2 , V_11 ) ;
if ( V_96 == NULL ) {
F_27 ( L_11 ) ;
F_7 ( V_2 , V_11 ) ;
F_56 ( V_11 ) ;
return NULL ;
}
if ( V_107 == V_113 )
return V_96 ;
V_9 = F_70 ( V_96 ) ;
if ( V_9 )
goto V_114;
V_109 = F_78 ( V_96 , & V_20 -> V_23 , NULL ) ;
if ( F_79 ( V_109 ) ) {
V_9 = F_80 ( V_109 ) ;
goto V_115;
}
V_9 = F_81 ( & V_20 -> V_23 , & V_109 -> V_4 ,
V_5 , V_107 , V_96 -> V_102 ,
0 ) ;
if ( V_9 ) {
F_27 ( L_12 ) ;
goto V_115;
}
F_51 ( ! F_82 ( & V_109 -> V_4 ) ) ;
V_109 -> V_97 = V_96 -> V_10 . V_97 ;
V_109 -> V_116 |= V_117 ;
F_83 ( V_109 ) ;
F_84 ( & V_109 -> V_118 , & V_20 -> V_23 . V_119 ) ;
F_84 ( & V_96 -> V_120 , & V_2 -> V_10 . V_121 ) ;
V_96 -> V_122 ++ ;
return V_96 ;
V_115:
F_85 ( V_96 ) ;
V_114:
F_86 ( V_96 ) ;
return NULL ;
}
