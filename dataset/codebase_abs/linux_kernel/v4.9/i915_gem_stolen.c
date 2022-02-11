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
struct V_21 * V_22 = V_2 -> V_23 . V_22 ;
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_24 * V_25 ;
T_2 V_26 ;
V_26 = 0 ;
if ( F_13 ( V_20 ) -> V_27 >= 3 ) {
T_2 V_28 ;
F_14 ( V_22 , V_29 , & V_28 ) ;
V_26 = V_28 & V_30 ;
} else if ( F_15 ( V_20 ) ) {
T_2 V_31 = 0 ;
T_3 V_32 = 0 ;
T_4 V_33 ;
F_16 ( V_22 -> V_34 , F_17 ( 0 , 0 ) ,
V_35 , & V_33 ) ;
if ( V_33 & V_36 ) {
switch ( V_33 & V_37 ) {
case V_38 :
V_31 = F_18 ( 512 ) ;
break;
case V_39 :
V_31 = F_19 ( 1 ) ;
break;
}
}
F_20 ( V_22 -> V_34 , F_17 ( 0 , 0 ) ,
V_40 , & V_32 ) ;
V_26 = ( V_32 << 16 ) + V_31 ;
} else if ( F_21 ( V_20 ) ) {
T_2 V_31 = 0 ;
T_2 V_41 ;
T_4 V_33 ;
F_16 ( V_22 -> V_34 , F_17 ( 0 , 0 ) ,
V_42 , & V_33 ) ;
if ( V_33 & V_36 )
V_31 = F_19 ( 1 ) ;
F_16 ( V_22 -> V_34 , F_17 ( 0 , 1 ) ,
V_43 , & V_33 ) ;
V_41 = V_33 * F_19 ( 32 ) ;
V_26 = V_41 - V_31 - V_17 -> V_44 ;
} else if ( F_22 ( V_20 ) ) {
T_2 V_31 = 0 ;
T_2 V_41 ;
T_4 V_33 ;
F_16 ( V_22 -> V_34 , F_17 ( 0 , 0 ) ,
V_35 , & V_33 ) ;
if ( V_33 & V_36 ) {
switch ( V_33 & V_37 ) {
case V_38 :
V_31 = F_18 ( 512 ) ;
break;
case V_39 :
V_31 = F_19 ( 1 ) ;
break;
}
}
F_16 ( V_22 -> V_34 , F_17 ( 0 , 0 ) ,
V_45 , & V_33 ) ;
V_41 = V_33 * F_19 ( 32 ) ;
V_26 = V_41 - V_31 - V_17 -> V_44 ;
} else if ( F_23 ( V_20 ) ) {
T_2 V_31 = 0 ;
T_2 V_41 ;
T_4 V_33 ;
F_16 ( V_22 -> V_34 , F_17 ( 0 , 0 ) ,
V_46 , & V_33 ) ;
if ( V_33 & V_36 ) {
if ( V_33 & V_47 )
V_31 = F_19 ( 1 ) ;
else
V_31 = F_18 ( 512 ) ;
}
F_16 ( V_22 -> V_34 , F_17 ( 0 , 0 ) ,
V_45 , & V_33 ) ;
V_41 = V_33 * F_19 ( 32 ) ;
V_26 = V_41 - V_31 - V_17 -> V_44 ;
}
if ( V_26 == 0 )
return 0 ;
if ( F_13 ( V_20 ) -> V_27 <= 4 && ! F_24 ( V_20 ) && ! F_25 ( V_20 ) ) {
struct {
T_2 V_7 , V_8 ;
} V_11 [ 2 ] = {
{ . V_7 = V_26 , . V_8 = V_26 + V_17 -> V_44 , } ,
{ . V_7 = V_26 , . V_8 = V_26 + V_17 -> V_44 , } ,
} ;
T_1 V_48 , V_49 ;
V_48 = F_26 ( V_50 ) ;
if ( F_27 ( V_20 ) )
V_48 = ( V_48 & V_51 ) |
( V_48 & V_52 ) << 28 ;
else
V_48 &= V_51 ;
V_49 = V_48 + F_28 ( V_17 ) * 4 ;
if ( V_48 >= V_11 [ 0 ] . V_7 && V_48 < V_11 [ 0 ] . V_8 )
V_11 [ 0 ] . V_8 = V_48 ;
if ( V_49 > V_11 [ 1 ] . V_7 && V_49 <= V_11 [ 1 ] . V_8 )
V_11 [ 1 ] . V_7 = V_49 ;
if ( V_11 [ 0 ] . V_8 - V_11 [ 0 ] . V_7 >
V_11 [ 1 ] . V_8 - V_11 [ 1 ] . V_7 ) {
V_26 = V_11 [ 0 ] . V_7 ;
V_17 -> V_44 = V_11 [ 0 ] . V_8 - V_11 [ 0 ] . V_7 ;
} else {
V_26 = V_11 [ 1 ] . V_7 ;
V_17 -> V_44 = V_11 [ 1 ] . V_8 - V_11 [ 1 ] . V_7 ;
}
if ( V_11 [ 0 ] . V_7 != V_11 [ 1 ] . V_7 ||
V_11 [ 0 ] . V_8 != V_11 [ 1 ] . V_8 ) {
F_29 ( L_1 ,
( unsigned long long ) V_48 ,
( unsigned long long ) V_49 - 1 ) ;
F_29 ( L_2 ,
V_26 , V_26 + ( T_2 ) V_17 -> V_44 - 1 ) ;
}
}
V_25 = F_30 ( V_20 -> V_20 , V_26 , V_17 -> V_44 ,
L_3 ) ;
if ( V_25 == NULL ) {
V_25 = F_30 ( V_20 -> V_20 , V_26 + 1 ,
V_17 -> V_44 - 1 ,
L_3 ) ;
if ( V_25 == NULL && ! F_31 ( V_20 ) ) {
F_32 ( L_4 ,
V_26 , V_26 + ( V_53 ) V_17 -> V_44 ) ;
V_26 = 0 ;
}
}
return V_26 ;
}
void F_33 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_12 ( V_20 ) ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return;
F_34 ( & V_2 -> V_10 . V_11 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
unsigned long * V_26 , unsigned long * V_5 )
{
struct V_16 * V_17 = & V_2 -> V_17 ;
V_53 V_54 = F_26 ( F_36 ( V_2 ) ?
V_55 :
V_56 ) ;
unsigned long V_57 = V_2 -> V_10 . V_58 +
V_17 -> V_44 ;
* V_26 = ( V_54 & V_59 ) << 16 ;
F_37 ( ( V_54 & V_60 ) < * V_26 ) ;
if ( * V_26 == 0 )
* V_5 = 0 ;
else
* V_5 = V_57 - * V_26 ;
}
static void F_38 ( struct V_1 * V_2 ,
unsigned long * V_26 , unsigned long * V_5 )
{
V_53 V_54 = F_26 ( V_61 ) ;
* V_26 = V_54 & V_62 ;
switch ( V_54 & V_63 ) {
case V_64 :
* V_5 = 1024 * 1024 ;
break;
case V_65 :
* V_5 = 512 * 1024 ;
break;
case V_66 :
* V_5 = 256 * 1024 ;
break;
case V_67 :
* V_5 = 128 * 1024 ;
break;
default:
* V_5 = 1024 * 1024 ;
F_39 ( V_54 & V_63 ) ;
}
}
static void F_40 ( struct V_1 * V_2 ,
unsigned long * V_26 , unsigned long * V_5 )
{
V_53 V_54 = F_26 ( V_61 ) ;
* V_26 = V_54 & V_68 ;
switch ( V_54 & V_69 ) {
case V_70 :
* V_5 = 1024 * 1024 ;
break;
case V_71 :
* V_5 = 256 * 1024 ;
break;
default:
* V_5 = 1024 * 1024 ;
F_39 ( V_54 & V_69 ) ;
}
}
static void F_41 ( struct V_1 * V_2 ,
unsigned long * V_26 , unsigned long * V_5 )
{
V_53 V_54 = F_26 ( V_61 ) ;
* V_26 = V_54 & V_62 ;
switch ( V_54 & V_72 ) {
case V_73 :
* V_5 = 1024 * 1024 ;
break;
case V_74 :
* V_5 = 2 * 1024 * 1024 ;
break;
case V_75 :
* V_5 = 4 * 1024 * 1024 ;
break;
case V_76 :
* V_5 = 8 * 1024 * 1024 ;
break;
default:
* V_5 = 8 * 1024 * 1024 ;
F_39 ( V_54 & V_72 ) ;
}
}
static void F_42 ( struct V_1 * V_2 ,
unsigned long * V_26 , unsigned long * V_5 )
{
struct V_16 * V_17 = & V_2 -> V_17 ;
V_53 V_54 = F_26 ( V_61 ) ;
unsigned long V_57 ;
V_57 = V_2 -> V_10 . V_58 + V_17 -> V_44 ;
* V_26 = V_54 & V_62 ;
if ( * V_26 == 0 )
* V_5 = 0 ;
else
* V_5 = V_57 - * V_26 ;
}
int F_43 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_12 ( V_20 ) ;
struct V_16 * V_17 = & V_2 -> V_17 ;
unsigned long V_77 , V_78 = 0 , V_79 ;
unsigned long V_57 ;
F_44 ( & V_2 -> V_10 . V_14 ) ;
#ifdef F_45
if ( V_80 && F_13 ( V_20 ) -> V_27 < 8 ) {
F_46 ( L_5 ) ;
return 0 ;
}
#endif
if ( V_17 -> V_44 == 0 )
return 0 ;
V_2 -> V_10 . V_58 = F_11 ( V_20 ) ;
if ( V_2 -> V_10 . V_58 == 0 )
return 0 ;
V_57 = V_2 -> V_10 . V_58 + V_17 -> V_44 ;
switch ( F_13 ( V_2 ) -> V_27 ) {
case 2 :
case 3 :
break;
case 4 :
if ( F_25 ( V_20 ) )
F_35 ( V_2 , & V_78 ,
& V_79 ) ;
break;
case 5 :
V_79 = 1024 * 1024 ;
V_78 = V_57 - V_79 ;
break;
case 6 :
F_38 ( V_2 , & V_78 ,
& V_79 ) ;
break;
case 7 :
F_40 ( V_2 , & V_78 ,
& V_79 ) ;
break;
default:
if ( F_47 ( V_2 ) ||
F_48 ( V_2 ) || F_49 ( V_20 ) )
F_42 ( V_2 , & V_78 ,
& V_79 ) ;
else
F_41 ( V_2 , & V_78 ,
& V_79 ) ;
break;
}
if ( V_78 == 0 ) {
V_79 = 0 ;
V_78 = V_57 ;
}
if ( V_78 < V_2 -> V_10 . V_58 ||
V_78 + V_79 > V_57 ) {
F_29 ( L_6 ,
V_78 , V_78 + V_79 ,
V_2 -> V_10 . V_58 , V_57 ) ;
return 0 ;
}
V_17 -> V_81 = V_78 ;
V_17 -> V_82 = V_79 ;
V_77 = V_57 - V_78 ;
F_29 ( L_7 ,
V_17 -> V_44 >> 10 ,
( V_17 -> V_44 - V_77 ) >> 10 ) ;
V_17 -> V_18 = V_17 -> V_44 - V_77 ;
F_50 ( & V_2 -> V_10 . V_11 , 0 , V_17 -> V_18 ) ;
return 0 ;
}
static struct V_83 *
F_51 ( struct V_19 * V_20 ,
T_2 V_84 , T_2 V_5 )
{
struct V_1 * V_2 = F_12 ( V_20 ) ;
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_83 * V_85 ;
struct V_86 * V_87 ;
F_52 ( L_8 , V_84 , V_5 ) ;
F_53 ( V_84 > V_17 -> V_44 - V_5 ) ;
V_85 = F_54 ( sizeof( * V_85 ) , V_88 ) ;
if ( V_85 == NULL )
return NULL ;
if ( F_55 ( V_85 , 1 , V_88 ) ) {
F_56 ( V_85 ) ;
return NULL ;
}
V_87 = V_85 -> V_89 ;
V_87 -> V_84 = 0 ;
V_87 -> V_90 = V_5 ;
F_57 ( V_87 ) = ( V_91 ) V_2 -> V_10 . V_58 + V_84 ;
F_58 ( V_87 ) = V_5 ;
return V_85 ;
}
static int F_59 ( struct V_92 * V_93 )
{
F_60 () ;
return - V_94 ;
}
static void F_61 ( struct V_92 * V_93 )
{
F_62 ( V_93 -> V_95 ) ;
F_56 ( V_93 -> V_95 ) ;
}
static void
F_63 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_12 ( V_93 -> V_26 . V_20 ) ;
if ( V_93 -> V_11 ) {
F_9 ( V_2 , V_93 -> V_11 ) ;
F_56 ( V_93 -> V_11 ) ;
V_93 -> V_11 = NULL ;
}
}
static struct V_92 *
F_64 ( struct V_19 * V_20 ,
struct V_3 * V_11 )
{
struct V_92 * V_93 ;
V_93 = F_65 ( V_20 ) ;
if ( V_93 == NULL )
return NULL ;
F_66 ( V_20 , & V_93 -> V_26 , V_11 -> V_5 ) ;
F_67 ( V_93 , & V_96 ) ;
V_93 -> V_95 = F_51 ( V_20 ,
V_11 -> V_7 , V_11 -> V_5 ) ;
if ( V_93 -> V_95 == NULL )
goto V_97;
V_93 -> V_98 . V_87 = V_93 -> V_95 -> V_89 ;
V_93 -> V_98 . V_99 = 0 ;
F_68 ( V_93 ) ;
V_93 -> V_11 = V_11 ;
V_93 -> V_26 . V_100 = V_101 | V_102 ;
V_93 -> V_103 = F_69 ( V_20 ) ? V_104 : V_105 ;
return V_93 ;
V_97:
F_70 ( V_93 ) ;
return NULL ;
}
struct V_92 *
F_71 ( struct V_19 * V_20 , T_2 V_5 )
{
struct V_1 * V_2 = F_12 ( V_20 ) ;
struct V_92 * V_93 ;
struct V_3 * V_11 ;
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return NULL ;
F_29 ( L_9 , V_5 ) ;
if ( V_5 == 0 )
return NULL ;
V_11 = F_72 ( sizeof( * V_11 ) , V_88 ) ;
if ( ! V_11 )
return NULL ;
V_9 = F_8 ( V_2 , V_11 , V_5 , 4096 ) ;
if ( V_9 ) {
F_56 ( V_11 ) ;
return NULL ;
}
V_93 = F_64 ( V_20 , V_11 ) ;
if ( V_93 )
return V_93 ;
F_9 ( V_2 , V_11 ) ;
F_56 ( V_11 ) ;
return NULL ;
}
struct V_92 *
F_73 ( struct V_19 * V_20 ,
T_2 V_106 ,
T_2 V_107 ,
T_2 V_5 )
{
struct V_1 * V_2 = F_12 ( V_20 ) ;
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_92 * V_93 ;
struct V_3 * V_11 ;
struct V_108 * V_109 ;
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return NULL ;
F_74 ( & V_20 -> V_110 ) ;
F_29 ( L_10 ,
V_106 , V_107 , V_5 ) ;
if ( F_37 ( V_5 == 0 ) || F_37 ( V_5 & 4095 ) ||
F_37 ( V_106 & 4095 ) )
return NULL ;
V_11 = F_72 ( sizeof( * V_11 ) , V_88 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_7 = V_106 ;
V_11 -> V_5 = V_5 ;
F_5 ( & V_2 -> V_10 . V_14 ) ;
V_9 = F_75 ( & V_2 -> V_10 . V_11 , V_11 ) ;
F_7 ( & V_2 -> V_10 . V_14 ) ;
if ( V_9 ) {
F_29 ( L_11 ) ;
F_56 ( V_11 ) ;
return NULL ;
}
V_93 = F_64 ( V_20 , V_11 ) ;
if ( V_93 == NULL ) {
F_29 ( L_12 ) ;
F_9 ( V_2 , V_11 ) ;
F_56 ( V_11 ) ;
return NULL ;
}
if ( V_107 == V_111 )
return V_93 ;
V_109 = F_76 ( V_93 , & V_17 -> V_26 , NULL ) ;
if ( F_77 ( V_109 ) ) {
V_9 = F_78 ( V_109 ) ;
goto V_112;
}
V_109 -> V_4 . V_7 = V_107 ;
V_109 -> V_4 . V_5 = V_5 ;
V_9 = F_75 ( & V_17 -> V_26 . V_10 , & V_109 -> V_4 ) ;
if ( V_9 ) {
F_29 ( L_13 ) ;
goto V_112;
}
V_109 -> V_95 = V_93 -> V_95 ;
V_109 -> V_113 |= V_114 ;
F_79 ( V_109 ) ;
F_80 ( & V_109 -> V_115 , & V_17 -> V_26 . V_116 ) ;
V_93 -> V_117 ++ ;
F_81 ( & V_93 -> V_118 , & V_2 -> V_10 . V_119 ) ;
F_68 ( V_93 ) ;
return V_93 ;
V_112:
F_82 ( V_93 ) ;
return NULL ;
}
