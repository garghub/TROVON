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
static T_2 F_9 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_18 . V_17 ;
struct V_19 * V_20 = & V_2 -> V_20 ;
struct V_21 * V_22 ;
T_2 V_23 ;
V_23 = 0 ;
if ( F_10 ( V_2 ) >= 3 ) {
T_3 V_24 ;
F_11 ( V_17 , V_25 , & V_24 ) ;
V_23 = V_24 & V_26 ;
} else if ( F_12 ( V_2 ) ) {
T_3 V_27 = 0 ;
T_4 V_28 = 0 ;
T_5 V_29 ;
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
T_3 V_27 = 0 ;
T_3 V_37 ;
T_5 V_29 ;
F_13 ( V_17 -> V_30 , F_14 ( 0 , 0 ) ,
V_38 , & V_29 ) ;
if ( V_29 & V_32 )
V_27 = F_16 ( 1 ) ;
F_13 ( V_17 -> V_30 , F_14 ( 0 , 1 ) ,
V_39 , & V_29 ) ;
V_37 = V_29 * F_16 ( 32 ) ;
V_23 = V_37 - V_27 - V_20 -> V_40 ;
} else if ( F_19 ( V_2 ) ) {
T_3 V_27 = 0 ;
T_3 V_37 ;
T_5 V_29 ;
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
T_3 V_27 = 0 ;
T_3 V_37 ;
T_5 V_29 ;
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
if ( V_23 == 0 || F_21 ( V_23 , V_20 -> V_40 ) )
return 0 ;
if ( F_10 ( V_2 ) <= 4 &&
! F_22 ( V_2 ) && ! F_23 ( V_2 ) && ! F_24 ( V_2 ) ) {
struct {
T_2 V_7 , V_8 ;
} V_11 [ 2 ] = {
{ . V_7 = V_23 , . V_8 = V_23 + V_20 -> V_40 , } ,
{ . V_7 = V_23 , . V_8 = V_23 + V_20 -> V_40 , } ,
} ;
T_1 V_44 , V_45 ;
V_44 = F_25 ( V_46 ) ;
if ( F_26 ( V_2 ) )
V_44 = ( V_44 & V_47 ) |
( V_44 & V_48 ) << 28 ;
else
V_44 &= V_47 ;
V_45 = V_44 + F_27 ( V_20 ) * 4 ;
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
T_2 V_8 = V_23 + V_20 -> V_40 - 1 ;
F_28 ( L_1 ,
( unsigned long long ) V_44 ,
( unsigned long long ) V_45 - 1 ) ;
F_28 ( L_2 ,
& V_23 , & V_8 ) ;
}
}
V_22 = F_29 ( V_2 -> V_18 . V_49 , V_23 , V_20 -> V_40 ,
L_3 ) ;
if ( V_22 == NULL ) {
V_22 = F_29 ( V_2 -> V_18 . V_49 , V_23 + 1 ,
V_20 -> V_40 - 1 ,
L_3 ) ;
if ( V_22 == NULL && ! F_30 ( V_2 ) ) {
T_2 V_8 = V_23 + V_20 -> V_40 ;
F_31 ( L_4 ,
& V_23 , & V_8 ) ;
V_23 = 0 ;
}
}
return V_23 ;
}
void F_32 ( struct V_50 * V_49 )
{
struct V_1 * V_2 = F_33 ( V_49 ) ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return;
F_34 ( & V_2 -> V_10 . V_11 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
T_2 * V_23 , T_3 * V_5 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
T_6 V_51 = F_25 ( F_36 ( V_2 ) ?
V_52 :
V_53 ) ;
T_2 V_54 = V_2 -> V_10 . V_55 + V_20 -> V_40 ;
* V_23 = ( V_51 & V_56 ) << 16 ;
F_37 ( ( V_51 & V_57 ) < * V_23 ) ;
if ( * V_23 == 0 )
* V_5 = 0 ;
else
* V_5 = V_54 - * V_23 ;
}
static void F_38 ( struct V_1 * V_2 ,
T_2 * V_23 , T_3 * V_5 )
{
T_6 V_51 = F_25 ( V_58 ) ;
* V_23 = V_51 & V_59 ;
switch ( V_51 & V_60 ) {
case V_61 :
* V_5 = 1024 * 1024 ;
break;
case V_62 :
* V_5 = 512 * 1024 ;
break;
case V_63 :
* V_5 = 256 * 1024 ;
break;
case V_64 :
* V_5 = 128 * 1024 ;
break;
default:
* V_5 = 1024 * 1024 ;
F_39 ( V_51 & V_60 ) ;
}
}
static void F_40 ( struct V_1 * V_2 ,
T_2 * V_23 , T_3 * V_5 )
{
T_6 V_51 = F_25 ( V_58 ) ;
* V_23 = V_51 & V_65 ;
switch ( V_51 & V_66 ) {
case V_67 :
* V_5 = 1024 * 1024 ;
break;
case V_68 :
* V_5 = 256 * 1024 ;
break;
default:
* V_5 = 1024 * 1024 ;
F_39 ( V_51 & V_66 ) ;
}
}
static void F_41 ( struct V_1 * V_2 ,
T_2 * V_23 , T_3 * V_5 )
{
T_6 V_51 = F_25 ( V_58 ) ;
* V_23 = V_51 & V_59 ;
switch ( V_51 & V_69 ) {
case V_70 :
* V_5 = 1024 * 1024 ;
break;
case V_71 :
* V_5 = 2 * 1024 * 1024 ;
break;
case V_72 :
* V_5 = 4 * 1024 * 1024 ;
break;
case V_73 :
* V_5 = 8 * 1024 * 1024 ;
break;
default:
* V_5 = 8 * 1024 * 1024 ;
F_39 ( V_51 & V_69 ) ;
}
}
static void F_42 ( struct V_1 * V_2 ,
T_2 * V_23 , T_3 * V_5 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
T_6 V_51 = F_25 ( V_58 ) ;
T_2 V_54 ;
V_54 = V_2 -> V_10 . V_55 + V_20 -> V_40 ;
* V_23 = V_51 & V_59 ;
if ( * V_23 == 0 )
* V_5 = 0 ;
else
* V_5 = V_54 - * V_23 ;
}
int F_43 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
T_2 V_74 , V_54 ;
T_3 V_75 , V_76 ;
T_3 V_77 ;
F_44 ( & V_2 -> V_10 . V_13 ) ;
if ( F_45 ( V_2 ) ) {
F_46 ( L_5 ) ;
return 0 ;
}
#ifdef F_47
if ( V_78 && F_10 ( V_2 ) < 8 ) {
F_46 ( L_6 ) ;
return 0 ;
}
#endif
if ( V_20 -> V_40 == 0 )
return 0 ;
V_2 -> V_10 . V_55 = F_9 ( V_2 ) ;
if ( V_2 -> V_10 . V_55 == 0 )
return 0 ;
V_54 = V_2 -> V_10 . V_55 + V_20 -> V_40 ;
V_74 = 0 ;
V_76 = 0 ;
switch ( F_48 ( V_2 ) -> V_79 ) {
case 2 :
case 3 :
break;
case 4 :
if ( F_24 ( V_2 ) )
F_35 ( V_2 ,
& V_74 , & V_76 ) ;
break;
case 5 :
V_76 = 1024 * 1024 ;
V_74 = V_54 - V_76 ;
break;
case 6 :
F_38 ( V_2 ,
& V_74 , & V_76 ) ;
break;
case 7 :
F_40 ( V_2 ,
& V_74 , & V_76 ) ;
break;
default:
if ( F_49 ( V_2 ) )
F_41 ( V_2 ,
& V_74 , & V_76 ) ;
else
F_42 ( V_2 ,
& V_74 , & V_76 ) ;
break;
}
if ( V_74 == 0 ) {
V_76 = 0 ;
V_74 = V_54 ;
}
if ( V_74 < V_2 -> V_10 . V_55 ||
V_74 + V_76 > V_54 ) {
T_2 V_80 = V_74 + V_76 ;
F_28 ( L_7 ,
& V_74 , & V_80 ,
& V_2 -> V_10 . V_55 , & V_54 ) ;
return 0 ;
}
V_20 -> V_81 = V_74 ;
V_20 -> V_82 = V_76 ;
V_75 = V_54 - V_74 ;
F_28 ( L_8 ,
V_20 -> V_40 >> 10 ,
( V_20 -> V_40 - V_75 ) >> 10 ) ;
V_77 = 0 ;
if ( F_10 ( V_2 ) >= 8 )
V_77 = 4096 ;
V_20 -> V_83 =
V_20 -> V_40 - V_75 - V_77 ;
F_50 ( & V_2 -> V_10 . V_11 , V_77 ,
V_20 -> V_83 ) ;
return 0 ;
}
static struct V_84 *
F_51 ( struct V_50 * V_49 ,
T_3 V_85 , T_3 V_5 )
{
struct V_1 * V_2 = F_33 ( V_49 ) ;
struct V_84 * V_86 ;
struct V_87 * V_88 ;
F_52 ( F_53 ( V_85 , V_5 , V_2 -> V_20 . V_40 ) ) ;
V_86 = F_54 ( sizeof( * V_86 ) , V_89 ) ;
if ( V_86 == NULL )
return F_55 ( - V_90 ) ;
if ( F_56 ( V_86 , 1 , V_89 ) ) {
F_57 ( V_86 ) ;
return F_55 ( - V_90 ) ;
}
V_88 = V_86 -> V_91 ;
V_88 -> V_85 = 0 ;
V_88 -> V_92 = V_5 ;
F_58 ( V_88 ) = ( T_2 ) V_2 -> V_10 . V_55 + V_85 ;
F_59 ( V_88 ) = V_5 ;
return V_86 ;
}
static struct V_84 *
F_60 ( struct V_93 * V_94 )
{
return F_51 ( V_94 -> V_23 . V_49 ,
V_94 -> V_11 -> V_7 ,
V_94 -> V_11 -> V_5 ) ;
}
static void F_61 ( struct V_93 * V_94 ,
struct V_84 * V_95 )
{
F_62 ( V_95 ) ;
F_57 ( V_95 ) ;
}
static void
F_63 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_33 ( V_94 -> V_23 . V_49 ) ;
struct V_3 * V_11 = F_64 ( & V_94 -> V_11 ) ;
F_52 ( ! V_11 ) ;
F_65 ( V_94 ) ;
F_7 ( V_2 , V_11 ) ;
F_57 ( V_11 ) ;
}
static struct V_93 *
F_66 ( struct V_1 * V_2 ,
struct V_3 * V_11 )
{
struct V_93 * V_94 ;
V_94 = F_67 ( V_2 ) ;
if ( V_94 == NULL )
return NULL ;
F_68 ( & V_2 -> V_18 , & V_94 -> V_23 , V_11 -> V_5 ) ;
F_69 ( V_94 , & V_96 ) ;
V_94 -> V_11 = V_11 ;
V_94 -> V_23 . V_97 = V_98 | V_99 ;
V_94 -> V_100 = F_70 ( V_2 ) ? V_101 : V_102 ;
if ( F_71 ( V_94 ) )
goto V_103;
return V_94 ;
V_103:
F_72 ( V_94 ) ;
return NULL ;
}
struct V_93 *
F_73 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_93 * V_94 ;
struct V_3 * V_11 ;
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return NULL ;
if ( V_5 == 0 )
return NULL ;
V_11 = F_74 ( sizeof( * V_11 ) , V_89 ) ;
if ( ! V_11 )
return NULL ;
V_9 = F_6 ( V_2 , V_11 , V_5 , 4096 ) ;
if ( V_9 ) {
F_57 ( V_11 ) ;
return NULL ;
}
V_94 = F_66 ( V_2 , V_11 ) ;
if ( V_94 )
return V_94 ;
F_7 ( V_2 , V_11 ) ;
F_57 ( V_11 ) ;
return NULL ;
}
struct V_93 *
F_75 ( struct V_1 * V_2 ,
T_3 V_104 ,
T_3 V_105 ,
T_3 V_5 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
struct V_93 * V_94 ;
struct V_3 * V_11 ;
struct V_106 * V_107 ;
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return NULL ;
F_76 ( & V_2 -> V_18 . V_108 ) ;
F_28 ( L_9 ,
V_104 , V_105 , V_5 ) ;
if ( F_37 ( V_5 == 0 ) ||
F_37 ( ! F_77 ( V_5 , V_109 ) ) ||
F_37 ( ! F_77 ( V_104 , V_110 ) ) )
return NULL ;
V_11 = F_74 ( sizeof( * V_11 ) , V_89 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_7 = V_104 ;
V_11 -> V_5 = V_5 ;
F_3 ( & V_2 -> V_10 . V_13 ) ;
V_9 = F_78 ( & V_2 -> V_10 . V_11 , V_11 ) ;
F_5 ( & V_2 -> V_10 . V_13 ) ;
if ( V_9 ) {
F_28 ( L_10 ) ;
F_57 ( V_11 ) ;
return NULL ;
}
V_94 = F_66 ( V_2 , V_11 ) ;
if ( V_94 == NULL ) {
F_28 ( L_11 ) ;
F_7 ( V_2 , V_11 ) ;
F_57 ( V_11 ) ;
return NULL ;
}
if ( V_105 == V_111 )
return V_94 ;
V_9 = F_71 ( V_94 ) ;
if ( V_9 )
goto V_112;
V_107 = F_79 ( V_94 , & V_20 -> V_23 , NULL ) ;
if ( F_80 ( V_107 ) ) {
V_9 = F_81 ( V_107 ) ;
goto V_113;
}
V_9 = F_82 ( & V_20 -> V_23 , & V_107 -> V_4 ,
V_5 , V_105 , V_94 -> V_100 ,
0 ) ;
if ( V_9 ) {
F_28 ( L_12 ) ;
goto V_113;
}
F_52 ( ! F_83 ( & V_107 -> V_4 ) ) ;
V_107 -> V_95 = V_94 -> V_10 . V_95 ;
V_107 -> V_114 |= V_115 ;
F_84 ( V_107 ) ;
F_85 ( & V_107 -> V_116 , & V_20 -> V_23 . V_117 ) ;
F_85 ( & V_94 -> V_118 , & V_2 -> V_10 . V_119 ) ;
V_94 -> V_120 ++ ;
return V_94 ;
V_113:
F_86 ( V_94 ) ;
V_112:
F_87 ( V_94 ) ;
return NULL ;
}
