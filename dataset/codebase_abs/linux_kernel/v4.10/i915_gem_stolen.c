int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 ,
unsigned V_6 , T_1 V_7 , T_1 V_8 )
{
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return - V_12 ;
if ( V_7 < 4096 && F_3 ( V_2 ) >= 8 )
V_7 = 4096 ;
F_4 ( & V_2 -> V_10 . V_13 ) ;
V_9 = F_5 ( & V_2 -> V_10 . V_11 , V_4 , V_5 ,
V_6 , V_7 , V_8 ,
V_14 ) ;
F_6 ( & V_2 -> V_10 . V_13 ) ;
return V_9 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 ,
unsigned V_6 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
return F_1 ( V_2 , V_4 , V_5 ,
V_6 , 0 ,
V_16 -> V_17 ) ;
}
void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_4 ( & V_2 -> V_10 . V_13 ) ;
F_9 ( V_4 ) ;
F_6 ( & V_2 -> V_10 . V_13 ) ;
}
static unsigned long F_10 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 . V_19 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_21 * V_22 ;
T_2 V_23 ;
V_23 = 0 ;
if ( F_3 ( V_2 ) >= 3 ) {
T_2 V_24 ;
F_11 ( V_19 , V_25 , & V_24 ) ;
V_23 = V_24 & V_26 ;
} else if ( F_12 ( V_2 ) ) {
T_2 V_27 = 0 ;
T_3 V_28 = 0 ;
T_4 V_29 ;
F_13 ( V_19 -> V_30 , F_14 ( 0 , 0 ) ,
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
F_17 ( V_19 -> V_30 , F_14 ( 0 , 0 ) ,
V_36 , & V_28 ) ;
V_23 = ( V_28 << 16 ) + V_27 ;
} else if ( F_18 ( V_2 ) ) {
T_2 V_27 = 0 ;
T_2 V_37 ;
T_4 V_29 ;
F_13 ( V_19 -> V_30 , F_14 ( 0 , 0 ) ,
V_38 , & V_29 ) ;
if ( V_29 & V_32 )
V_27 = F_16 ( 1 ) ;
F_13 ( V_19 -> V_30 , F_14 ( 0 , 1 ) ,
V_39 , & V_29 ) ;
V_37 = V_29 * F_16 ( 32 ) ;
V_23 = V_37 - V_27 - V_16 -> V_40 ;
} else if ( F_19 ( V_2 ) ) {
T_2 V_27 = 0 ;
T_2 V_37 ;
T_4 V_29 ;
F_13 ( V_19 -> V_30 , F_14 ( 0 , 0 ) ,
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
F_13 ( V_19 -> V_30 , F_14 ( 0 , 0 ) ,
V_41 , & V_29 ) ;
V_37 = V_29 * F_16 ( 32 ) ;
V_23 = V_37 - V_27 - V_16 -> V_40 ;
} else if ( F_20 ( V_2 ) ) {
T_2 V_27 = 0 ;
T_2 V_37 ;
T_4 V_29 ;
F_13 ( V_19 -> V_30 , F_14 ( 0 , 0 ) ,
V_42 , & V_29 ) ;
if ( V_29 & V_32 ) {
if ( V_29 & V_43 )
V_27 = F_16 ( 1 ) ;
else
V_27 = F_15 ( 512 ) ;
}
F_13 ( V_19 -> V_30 , F_14 ( 0 , 0 ) ,
V_41 , & V_29 ) ;
V_37 = V_29 * F_16 ( 32 ) ;
V_23 = V_37 - V_27 - V_16 -> V_40 ;
}
if ( V_23 == 0 )
return 0 ;
if ( F_3 ( V_2 ) <= 4 && ! F_21 ( V_2 ) &&
! F_22 ( V_2 ) ) {
struct {
T_2 V_7 , V_8 ;
} V_11 [ 2 ] = {
{ . V_7 = V_23 , . V_8 = V_23 + V_16 -> V_40 , } ,
{ . V_7 = V_23 , . V_8 = V_23 + V_16 -> V_40 , } ,
} ;
T_1 V_44 , V_45 ;
V_44 = F_23 ( V_46 ) ;
if ( F_24 ( V_2 ) )
V_44 = ( V_44 & V_47 ) |
( V_44 & V_48 ) << 28 ;
else
V_44 &= V_47 ;
V_45 = V_44 + F_25 ( V_16 ) * 4 ;
if ( V_44 >= V_11 [ 0 ] . V_7 && V_44 < V_11 [ 0 ] . V_8 )
V_11 [ 0 ] . V_8 = V_44 ;
if ( V_45 > V_11 [ 1 ] . V_7 && V_45 <= V_11 [ 1 ] . V_8 )
V_11 [ 1 ] . V_7 = V_45 ;
if ( V_11 [ 0 ] . V_8 - V_11 [ 0 ] . V_7 >
V_11 [ 1 ] . V_8 - V_11 [ 1 ] . V_7 ) {
V_23 = V_11 [ 0 ] . V_7 ;
V_16 -> V_40 = V_11 [ 0 ] . V_8 - V_11 [ 0 ] . V_7 ;
} else {
V_23 = V_11 [ 1 ] . V_7 ;
V_16 -> V_40 = V_11 [ 1 ] . V_8 - V_11 [ 1 ] . V_7 ;
}
if ( V_11 [ 0 ] . V_7 != V_11 [ 1 ] . V_7 ||
V_11 [ 0 ] . V_8 != V_11 [ 1 ] . V_8 ) {
F_26 ( L_1 ,
( unsigned long long ) V_44 ,
( unsigned long long ) V_45 - 1 ) ;
F_26 ( L_2 ,
V_23 , V_23 + ( T_2 ) V_16 -> V_40 - 1 ) ;
}
}
V_22 = F_27 ( V_2 -> V_20 . V_49 , V_23 , V_16 -> V_40 ,
L_3 ) ;
if ( V_22 == NULL ) {
V_22 = F_27 ( V_2 -> V_20 . V_49 , V_23 + 1 ,
V_16 -> V_40 - 1 ,
L_3 ) ;
if ( V_22 == NULL && ! F_28 ( V_2 ) ) {
F_29 ( L_4 ,
V_23 , V_23 + ( V_50 ) V_16 -> V_40 ) ;
V_23 = 0 ;
}
}
return V_23 ;
}
void F_30 ( struct V_51 * V_49 )
{
struct V_1 * V_2 = F_31 ( V_49 ) ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return;
F_32 ( & V_2 -> V_10 . V_11 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
unsigned long * V_23 , unsigned long * V_5 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
V_50 V_52 = F_23 ( F_34 ( V_2 ) ?
V_53 :
V_54 ) ;
unsigned long V_55 = V_2 -> V_10 . V_56 +
V_16 -> V_40 ;
* V_23 = ( V_52 & V_57 ) << 16 ;
F_35 ( ( V_52 & V_58 ) < * V_23 ) ;
if ( * V_23 == 0 )
* V_5 = 0 ;
else
* V_5 = V_55 - * V_23 ;
}
static void F_36 ( struct V_1 * V_2 ,
unsigned long * V_23 , unsigned long * V_5 )
{
V_50 V_52 = F_23 ( V_59 ) ;
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
F_37 ( V_52 & V_61 ) ;
}
}
static void F_38 ( struct V_1 * V_2 ,
unsigned long * V_23 , unsigned long * V_5 )
{
V_50 V_52 = F_23 ( V_59 ) ;
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
F_37 ( V_52 & V_67 ) ;
}
}
static void F_39 ( struct V_1 * V_2 ,
unsigned long * V_23 , unsigned long * V_5 )
{
V_50 V_52 = F_23 ( V_59 ) ;
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
F_37 ( V_52 & V_70 ) ;
}
}
static void F_40 ( struct V_1 * V_2 ,
unsigned long * V_23 , unsigned long * V_5 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
V_50 V_52 = F_23 ( V_59 ) ;
unsigned long V_55 ;
V_55 = V_2 -> V_10 . V_56 + V_16 -> V_40 ;
* V_23 = V_52 & V_60 ;
if ( * V_23 == 0 )
* V_5 = 0 ;
else
* V_5 = V_55 - * V_23 ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
unsigned long V_75 , V_76 = 0 , V_77 ;
unsigned long V_55 ;
F_42 ( & V_2 -> V_10 . V_13 ) ;
#ifdef F_43
if ( V_78 && F_3 ( V_2 ) < 8 ) {
F_44 ( L_5 ) ;
return 0 ;
}
#endif
if ( V_16 -> V_40 == 0 )
return 0 ;
V_2 -> V_10 . V_56 = F_10 ( V_2 ) ;
if ( V_2 -> V_10 . V_56 == 0 )
return 0 ;
V_55 = V_2 -> V_10 . V_56 + V_16 -> V_40 ;
switch ( F_45 ( V_2 ) -> V_79 ) {
case 2 :
case 3 :
break;
case 4 :
if ( F_22 ( V_2 ) )
F_33 ( V_2 , & V_76 ,
& V_77 ) ;
break;
case 5 :
V_77 = 1024 * 1024 ;
V_76 = V_55 - V_77 ;
break;
case 6 :
F_36 ( V_2 , & V_76 ,
& V_77 ) ;
break;
case 7 :
F_38 ( V_2 , & V_76 ,
& V_77 ) ;
break;
default:
if ( F_46 ( V_2 ) ||
F_47 ( V_2 ) || F_48 ( V_2 ) )
F_40 ( V_2 , & V_76 ,
& V_77 ) ;
else
F_39 ( V_2 , & V_76 ,
& V_77 ) ;
break;
}
if ( V_76 == 0 ) {
V_77 = 0 ;
V_76 = V_55 ;
}
if ( V_76 < V_2 -> V_10 . V_56 ||
V_76 + V_77 > V_55 ) {
F_26 ( L_6 ,
V_76 , V_76 + V_77 ,
V_2 -> V_10 . V_56 , V_55 ) ;
return 0 ;
}
V_16 -> V_80 = V_76 ;
V_16 -> V_81 = V_77 ;
V_75 = V_55 - V_76 ;
F_26 ( L_7 ,
V_16 -> V_40 >> 10 ,
( V_16 -> V_40 - V_75 ) >> 10 ) ;
V_16 -> V_17 = V_16 -> V_40 - V_75 ;
F_49 ( & V_2 -> V_10 . V_11 , 0 , V_16 -> V_17 ) ;
return 0 ;
}
static struct V_82 *
F_50 ( struct V_51 * V_49 ,
T_2 V_83 , T_2 V_5 )
{
struct V_1 * V_2 = F_31 ( V_49 ) ;
struct V_82 * V_84 ;
struct V_85 * V_86 ;
F_51 ( V_83 > V_2 -> V_16 . V_40 - V_5 ) ;
V_84 = F_52 ( sizeof( * V_84 ) , V_87 ) ;
if ( V_84 == NULL )
return F_53 ( - V_88 ) ;
if ( F_54 ( V_84 , 1 , V_87 ) ) {
F_55 ( V_84 ) ;
return F_53 ( - V_88 ) ;
}
V_86 = V_84 -> V_89 ;
V_86 -> V_83 = 0 ;
V_86 -> V_90 = V_5 ;
F_56 ( V_86 ) = ( V_91 ) V_2 -> V_10 . V_56 + V_83 ;
F_57 ( V_86 ) = V_5 ;
return V_84 ;
}
static struct V_82 *
F_58 ( struct V_92 * V_93 )
{
return F_50 ( V_93 -> V_23 . V_49 ,
V_93 -> V_11 -> V_7 ,
V_93 -> V_11 -> V_5 ) ;
}
static void F_59 ( struct V_92 * V_93 ,
struct V_82 * V_94 )
{
F_60 ( V_94 ) ;
F_55 ( V_94 ) ;
}
static void
F_61 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_31 ( V_93 -> V_23 . V_49 ) ;
struct V_3 * V_11 = F_62 ( & V_93 -> V_11 ) ;
F_51 ( ! V_11 ) ;
F_63 ( V_93 ) ;
F_8 ( V_2 , V_11 ) ;
F_55 ( V_11 ) ;
}
static struct V_92 *
F_64 ( struct V_51 * V_49 ,
struct V_3 * V_11 )
{
struct V_92 * V_93 ;
V_93 = F_65 ( V_49 ) ;
if ( V_93 == NULL )
return NULL ;
F_66 ( V_49 , & V_93 -> V_23 , V_11 -> V_5 ) ;
F_67 ( V_93 , & V_95 ) ;
V_93 -> V_11 = V_11 ;
V_93 -> V_23 . V_96 = V_97 | V_98 ;
V_93 -> V_99 = F_68 ( F_31 ( V_49 ) ) ?
V_100 : V_101 ;
if ( F_69 ( V_93 ) )
goto V_102;
return V_93 ;
V_102:
F_70 ( V_93 ) ;
return NULL ;
}
struct V_92 *
F_71 ( struct V_51 * V_49 , T_2 V_5 )
{
struct V_1 * V_2 = F_31 ( V_49 ) ;
struct V_92 * V_93 ;
struct V_3 * V_11 ;
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return NULL ;
if ( V_5 == 0 )
return NULL ;
V_11 = F_72 ( sizeof( * V_11 ) , V_87 ) ;
if ( ! V_11 )
return NULL ;
V_9 = F_7 ( V_2 , V_11 , V_5 , 4096 ) ;
if ( V_9 ) {
F_55 ( V_11 ) ;
return NULL ;
}
V_93 = F_64 ( V_49 , V_11 ) ;
if ( V_93 )
return V_93 ;
F_8 ( V_2 , V_11 ) ;
F_55 ( V_11 ) ;
return NULL ;
}
struct V_92 *
F_73 ( struct V_51 * V_49 ,
T_2 V_103 ,
T_2 V_104 ,
T_2 V_5 )
{
struct V_1 * V_2 = F_31 ( V_49 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_92 * V_93 ;
struct V_3 * V_11 ;
struct V_105 * V_106 ;
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return NULL ;
F_74 ( & V_49 -> V_107 ) ;
F_26 ( L_8 ,
V_103 , V_104 , V_5 ) ;
if ( F_35 ( V_5 == 0 ) || F_35 ( V_5 & 4095 ) ||
F_35 ( V_103 & 4095 ) )
return NULL ;
V_11 = F_72 ( sizeof( * V_11 ) , V_87 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_7 = V_103 ;
V_11 -> V_5 = V_5 ;
F_4 ( & V_2 -> V_10 . V_13 ) ;
V_9 = F_75 ( & V_2 -> V_10 . V_11 , V_11 ) ;
F_6 ( & V_2 -> V_10 . V_13 ) ;
if ( V_9 ) {
F_26 ( L_9 ) ;
F_55 ( V_11 ) ;
return NULL ;
}
V_93 = F_64 ( V_49 , V_11 ) ;
if ( V_93 == NULL ) {
F_26 ( L_10 ) ;
F_8 ( V_2 , V_11 ) ;
F_55 ( V_11 ) ;
return NULL ;
}
if ( V_104 == V_108 )
return V_93 ;
V_9 = F_69 ( V_93 ) ;
if ( V_9 )
goto V_109;
V_106 = F_76 ( V_93 , & V_16 -> V_23 , NULL ) ;
if ( F_77 ( V_106 ) ) {
V_9 = F_78 ( V_106 ) ;
goto V_110;
}
V_106 -> V_4 . V_7 = V_104 ;
V_106 -> V_4 . V_5 = V_5 ;
V_9 = F_75 ( & V_16 -> V_23 . V_10 , & V_106 -> V_4 ) ;
if ( V_9 ) {
F_26 ( L_11 ) ;
goto V_110;
}
V_106 -> V_94 = V_93 -> V_10 . V_94 ;
V_106 -> V_111 |= V_112 ;
F_79 ( V_106 ) ;
F_80 ( & V_106 -> V_113 , & V_16 -> V_23 . V_114 ) ;
F_80 ( & V_93 -> V_115 , & V_2 -> V_10 . V_116 ) ;
V_93 -> V_117 ++ ;
return V_93 ;
V_110:
F_81 ( V_93 ) ;
V_109:
F_82 ( V_93 ) ;
return NULL ;
}
