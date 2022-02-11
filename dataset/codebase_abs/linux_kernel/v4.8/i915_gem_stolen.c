int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 ,
unsigned V_6 , T_1 V_7 , T_1 V_8 )
{
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return - V_12 ;
if ( V_7 < 4096 && ( F_3 ( V_2 ) ||
F_4 ( V_2 , 0 , V_13 ) ) )
V_7 = 4096 ;
F_5 ( & V_2 -> V_10 . V_14 ) ;
V_9 = F_6 ( & V_2 -> V_10 . V_11 , V_4 , V_5 ,
V_6 , V_7 , V_8 ,
V_15 ) ;
F_7 ( & V_2 -> V_10 . V_14 ) ;
return V_9 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 ,
unsigned V_6 )
{
struct V_16 * V_17 = & V_2 -> V_17 ;
return F_1 ( V_2 , V_4 , V_5 ,
V_6 , 0 ,
V_17 -> V_18 ) ;
}
void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_5 ( & V_2 -> V_10 . V_14 ) ;
F_10 ( V_4 ) ;
F_7 ( & V_2 -> V_10 . V_14 ) ;
}
static unsigned long F_11 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_12 ( V_20 ) ;
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_21 * V_22 ;
T_2 V_23 ;
V_23 = 0 ;
if ( F_13 ( V_20 ) -> V_24 >= 3 ) {
T_2 V_25 ;
F_14 ( V_20 -> V_26 , V_27 , & V_25 ) ;
V_23 = V_25 & V_28 ;
} else if ( F_15 ( V_20 ) ) {
T_3 V_29 = 0 ;
F_16 ( V_20 -> V_26 -> V_30 , F_17 ( 0 , 0 ) ,
V_31 , & V_29 ) ;
V_23 = V_29 << 16 ;
} else if ( F_18 ( V_20 ) ) {
T_2 V_32 = 0 ;
T_2 V_33 ;
T_4 V_34 ;
F_19 ( V_20 -> V_26 -> V_30 , F_17 ( 0 , 0 ) ,
V_35 , & V_34 ) ;
if ( V_34 & V_36 )
V_32 = F_20 ( 1 ) ;
F_19 ( V_20 -> V_26 -> V_30 , F_17 ( 0 , 1 ) ,
V_37 , & V_34 ) ;
V_33 = V_34 * F_20 ( 32 ) ;
V_23 = V_33 - V_32 - V_17 -> V_38 ;
} else if ( F_21 ( V_20 ) ) {
T_2 V_32 = 0 ;
T_2 V_33 ;
T_4 V_34 ;
F_19 ( V_20 -> V_26 -> V_30 , F_17 ( 0 , 0 ) ,
V_39 , & V_34 ) ;
if ( V_34 & V_36 ) {
switch ( V_34 & V_40 ) {
case V_41 :
V_32 = F_22 ( 512 ) ;
break;
case V_42 :
V_32 = F_20 ( 1 ) ;
break;
}
}
F_19 ( V_20 -> V_26 -> V_30 , F_17 ( 0 , 0 ) ,
V_43 , & V_34 ) ;
V_33 = V_34 * F_20 ( 32 ) ;
V_23 = V_33 - V_32 - V_17 -> V_38 ;
} else if ( F_23 ( V_20 ) ) {
T_2 V_32 = 0 ;
T_2 V_33 ;
T_4 V_34 ;
F_19 ( V_20 -> V_26 -> V_30 , F_17 ( 0 , 0 ) ,
V_44 , & V_34 ) ;
if ( V_34 & V_36 ) {
if ( V_34 & V_45 )
V_32 = F_20 ( 1 ) ;
else
V_32 = F_22 ( 512 ) ;
}
F_19 ( V_20 -> V_26 -> V_30 , F_17 ( 0 , 0 ) ,
V_43 , & V_34 ) ;
V_33 = V_34 * F_20 ( 32 ) ;
V_23 = V_33 - V_32 - V_17 -> V_38 ;
}
if ( V_23 == 0 )
return 0 ;
if ( F_13 ( V_20 ) -> V_24 <= 4 && ! F_24 ( V_20 ) && ! F_25 ( V_20 ) ) {
struct {
T_2 V_7 , V_8 ;
} V_11 [ 2 ] = {
{ . V_7 = V_23 , . V_8 = V_23 + V_17 -> V_38 , } ,
{ . V_7 = V_23 , . V_8 = V_23 + V_17 -> V_38 , } ,
} ;
T_1 V_46 , V_47 ;
V_46 = F_26 ( V_48 ) ;
if ( F_27 ( V_20 ) )
V_46 = ( V_46 & V_49 ) |
( V_46 & V_50 ) << 28 ;
else
V_46 &= V_49 ;
V_47 = V_46 + F_28 ( V_17 ) * 4 ;
if ( V_46 >= V_11 [ 0 ] . V_7 && V_46 < V_11 [ 0 ] . V_8 )
V_11 [ 0 ] . V_8 = V_46 ;
if ( V_47 > V_11 [ 1 ] . V_7 && V_47 <= V_11 [ 1 ] . V_8 )
V_11 [ 1 ] . V_7 = V_47 ;
if ( V_11 [ 0 ] . V_8 - V_11 [ 0 ] . V_7 >
V_11 [ 1 ] . V_8 - V_11 [ 1 ] . V_7 ) {
V_23 = V_11 [ 0 ] . V_7 ;
V_17 -> V_38 = V_11 [ 0 ] . V_8 - V_11 [ 0 ] . V_7 ;
} else {
V_23 = V_11 [ 1 ] . V_7 ;
V_17 -> V_38 = V_11 [ 1 ] . V_8 - V_11 [ 1 ] . V_7 ;
}
if ( V_11 [ 0 ] . V_7 != V_11 [ 1 ] . V_7 ||
V_11 [ 0 ] . V_8 != V_11 [ 1 ] . V_8 ) {
F_29 ( L_1 ,
( unsigned long long ) V_46 ,
( unsigned long long ) V_47 - 1 ) ;
F_29 ( L_2 ,
V_23 , V_23 + ( T_2 ) V_17 -> V_38 - 1 ) ;
}
}
V_22 = F_30 ( V_20 -> V_20 , V_23 , V_17 -> V_38 ,
L_3 ) ;
if ( V_22 == NULL ) {
V_22 = F_30 ( V_20 -> V_20 , V_23 + 1 ,
V_17 -> V_38 - 1 ,
L_3 ) ;
if ( V_22 == NULL && ! F_31 ( V_20 ) ) {
F_32 ( L_4 ,
V_23 , V_23 + ( V_51 ) V_17 -> V_38 ) ;
V_23 = 0 ;
}
}
return V_23 ;
}
void F_33 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_12 ( V_20 ) ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return;
F_34 ( & V_2 -> V_10 . V_11 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
unsigned long * V_23 , unsigned long * V_5 )
{
struct V_16 * V_17 = & V_2 -> V_17 ;
V_51 V_52 = F_26 ( F_36 ( V_2 ) ?
V_53 :
V_54 ) ;
unsigned long V_55 = V_2 -> V_10 . V_56 +
V_17 -> V_38 ;
* V_23 = ( V_52 & V_57 ) << 16 ;
F_37 ( ( V_52 & V_58 ) < * V_23 ) ;
if ( * V_23 == 0 )
* V_5 = 0 ;
else
* V_5 = V_55 - * V_23 ;
}
static void F_38 ( struct V_1 * V_2 ,
unsigned long * V_23 , unsigned long * V_5 )
{
V_51 V_52 = F_26 ( V_59 ) ;
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
F_39 ( V_52 & V_61 ) ;
}
}
static void F_40 ( struct V_1 * V_2 ,
unsigned long * V_23 , unsigned long * V_5 )
{
V_51 V_52 = F_26 ( V_59 ) ;
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
F_39 ( V_52 & V_67 ) ;
}
}
static void F_41 ( struct V_1 * V_2 ,
unsigned long * V_23 , unsigned long * V_5 )
{
V_51 V_52 = F_26 ( V_59 ) ;
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
F_39 ( V_52 & V_70 ) ;
}
}
static void F_42 ( struct V_1 * V_2 ,
unsigned long * V_23 , unsigned long * V_5 )
{
struct V_16 * V_17 = & V_2 -> V_17 ;
V_51 V_52 = F_26 ( V_59 ) ;
unsigned long V_55 ;
V_55 = V_2 -> V_10 . V_56 + V_17 -> V_38 ;
* V_23 = V_52 & V_60 ;
if ( * V_23 == 0 )
* V_5 = 0 ;
else
* V_5 = V_55 - * V_23 ;
}
int F_43 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_12 ( V_20 ) ;
struct V_16 * V_17 = & V_2 -> V_17 ;
unsigned long V_75 , V_76 = 0 , V_77 ;
unsigned long V_55 ;
F_44 ( & V_2 -> V_10 . V_14 ) ;
#ifdef F_45
if ( V_78 && F_13 ( V_20 ) -> V_24 < 8 ) {
F_46 ( L_5 ) ;
return 0 ;
}
#endif
if ( V_17 -> V_38 == 0 )
return 0 ;
V_2 -> V_10 . V_56 = F_11 ( V_20 ) ;
if ( V_2 -> V_10 . V_56 == 0 )
return 0 ;
V_55 = V_2 -> V_10 . V_56 + V_17 -> V_38 ;
switch ( F_13 ( V_2 ) -> V_24 ) {
case 2 :
case 3 :
break;
case 4 :
if ( F_25 ( V_20 ) )
F_35 ( V_2 , & V_76 ,
& V_77 ) ;
break;
case 5 :
V_77 = 1024 * 1024 ;
V_76 = V_55 - V_77 ;
break;
case 6 :
F_38 ( V_2 , & V_76 ,
& V_77 ) ;
break;
case 7 :
F_40 ( V_2 , & V_76 ,
& V_77 ) ;
break;
default:
if ( F_47 ( V_2 ) ||
F_48 ( V_2 ) || F_49 ( V_20 ) )
F_42 ( V_2 , & V_76 ,
& V_77 ) ;
else
F_41 ( V_2 , & V_76 ,
& V_77 ) ;
break;
}
if ( V_76 == 0 ) {
V_77 = 0 ;
V_76 = V_55 ;
}
if ( V_76 < V_2 -> V_10 . V_56 ||
V_76 + V_77 > V_55 ) {
F_29 ( L_6 ,
V_76 , V_76 + V_77 ,
V_2 -> V_10 . V_56 , V_55 ) ;
return 0 ;
}
V_17 -> V_79 = V_76 ;
V_17 -> V_80 = V_77 ;
V_75 = V_55 - V_76 ;
F_29 ( L_7 ,
V_17 -> V_38 >> 10 ,
( V_17 -> V_38 - V_75 ) >> 10 ) ;
V_17 -> V_18 = V_17 -> V_38 - V_75 ;
F_50 ( & V_2 -> V_10 . V_11 , 0 , V_17 -> V_18 ) ;
return 0 ;
}
static struct V_81 *
F_51 ( struct V_19 * V_20 ,
T_2 V_82 , T_2 V_5 )
{
struct V_1 * V_2 = F_12 ( V_20 ) ;
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_81 * V_83 ;
struct V_84 * V_85 ;
F_52 ( L_8 , V_82 , V_5 ) ;
F_53 ( V_82 > V_17 -> V_38 - V_5 ) ;
V_83 = F_54 ( sizeof( * V_83 ) , V_86 ) ;
if ( V_83 == NULL )
return NULL ;
if ( F_55 ( V_83 , 1 , V_86 ) ) {
F_56 ( V_83 ) ;
return NULL ;
}
V_85 = V_83 -> V_87 ;
V_85 -> V_82 = 0 ;
V_85 -> V_88 = V_5 ;
F_57 ( V_85 ) = ( V_89 ) V_2 -> V_10 . V_56 + V_82 ;
F_58 ( V_85 ) = V_5 ;
return V_83 ;
}
static int F_59 ( struct V_90 * V_91 )
{
F_60 () ;
return - V_92 ;
}
static void F_61 ( struct V_90 * V_91 )
{
F_62 ( V_91 -> V_93 ) ;
F_56 ( V_91 -> V_93 ) ;
}
static void
F_63 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_12 ( V_91 -> V_23 . V_20 ) ;
if ( V_91 -> V_11 ) {
F_9 ( V_2 , V_91 -> V_11 ) ;
F_56 ( V_91 -> V_11 ) ;
V_91 -> V_11 = NULL ;
}
}
static struct V_90 *
F_64 ( struct V_19 * V_20 ,
struct V_3 * V_11 )
{
struct V_90 * V_91 ;
V_91 = F_65 ( V_20 ) ;
if ( V_91 == NULL )
return NULL ;
F_66 ( V_20 , & V_91 -> V_23 , V_11 -> V_5 ) ;
F_67 ( V_91 , & V_94 ) ;
V_91 -> V_93 = F_51 ( V_20 ,
V_11 -> V_7 , V_11 -> V_5 ) ;
if ( V_91 -> V_93 == NULL )
goto V_95;
V_91 -> V_96 . V_85 = V_91 -> V_93 -> V_87 ;
V_91 -> V_96 . V_97 = 0 ;
F_68 ( V_91 ) ;
V_91 -> V_11 = V_11 ;
V_91 -> V_23 . V_98 = V_99 | V_100 ;
V_91 -> V_101 = F_69 ( V_20 ) ? V_102 : V_103 ;
return V_91 ;
V_95:
F_70 ( V_91 ) ;
return NULL ;
}
struct V_90 *
F_71 ( struct V_19 * V_20 , T_2 V_5 )
{
struct V_1 * V_2 = F_12 ( V_20 ) ;
struct V_90 * V_91 ;
struct V_3 * V_11 ;
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return NULL ;
F_29 ( L_9 , V_5 ) ;
if ( V_5 == 0 )
return NULL ;
V_11 = F_72 ( sizeof( * V_11 ) , V_86 ) ;
if ( ! V_11 )
return NULL ;
V_9 = F_8 ( V_2 , V_11 , V_5 , 4096 ) ;
if ( V_9 ) {
F_56 ( V_11 ) ;
return NULL ;
}
V_91 = F_64 ( V_20 , V_11 ) ;
if ( V_91 )
return V_91 ;
F_9 ( V_2 , V_11 ) ;
F_56 ( V_11 ) ;
return NULL ;
}
struct V_90 *
F_73 ( struct V_19 * V_20 ,
T_2 V_104 ,
T_2 V_105 ,
T_2 V_5 )
{
struct V_1 * V_2 = F_12 ( V_20 ) ;
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_90 * V_91 ;
struct V_3 * V_11 ;
struct V_106 * V_107 ;
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return NULL ;
F_74 ( & V_20 -> V_108 ) ;
F_29 ( L_10 ,
V_104 , V_105 , V_5 ) ;
if ( F_37 ( V_5 == 0 ) || F_37 ( V_5 & 4095 ) ||
F_37 ( V_104 & 4095 ) )
return NULL ;
V_11 = F_72 ( sizeof( * V_11 ) , V_86 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_7 = V_104 ;
V_11 -> V_5 = V_5 ;
F_5 ( & V_2 -> V_10 . V_14 ) ;
V_9 = F_75 ( & V_2 -> V_10 . V_11 , V_11 ) ;
F_7 ( & V_2 -> V_10 . V_14 ) ;
if ( V_9 ) {
F_29 ( L_11 ) ;
F_56 ( V_11 ) ;
return NULL ;
}
V_91 = F_64 ( V_20 , V_11 ) ;
if ( V_91 == NULL ) {
F_29 ( L_12 ) ;
F_9 ( V_2 , V_11 ) ;
F_56 ( V_11 ) ;
return NULL ;
}
if ( V_105 == V_109 )
return V_91 ;
V_107 = F_76 ( V_91 , & V_17 -> V_23 ) ;
if ( F_77 ( V_107 ) ) {
V_9 = F_78 ( V_107 ) ;
goto V_110;
}
V_107 -> V_4 . V_7 = V_105 ;
V_107 -> V_4 . V_5 = V_5 ;
if ( F_2 ( & V_17 -> V_23 . V_10 ) ) {
V_9 = F_75 ( & V_17 -> V_23 . V_10 , & V_107 -> V_4 ) ;
if ( V_9 ) {
F_29 ( L_13 ) ;
goto V_110;
}
V_107 -> V_111 |= V_112 ;
F_79 ( V_107 ) ;
F_80 ( & V_107 -> V_113 , & V_17 -> V_23 . V_114 ) ;
}
F_80 ( & V_91 -> V_115 , & V_2 -> V_10 . V_116 ) ;
F_68 ( V_91 ) ;
return V_91 ;
V_110:
F_81 ( & V_91 -> V_23 ) ;
return NULL ;
}
