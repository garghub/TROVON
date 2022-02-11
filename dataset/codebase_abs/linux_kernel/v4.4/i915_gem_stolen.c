int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 ,
unsigned V_6 , T_1 V_7 , T_1 V_8 )
{
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return - V_12 ;
if ( F_3 ( V_2 ) -> V_13 == 8 && V_7 < 4096 )
V_7 = 4096 ;
F_4 ( & V_2 -> V_10 . V_14 ) ;
V_9 = F_5 ( & V_2 -> V_10 . V_11 , V_4 , V_5 ,
V_6 , V_7 , V_8 ,
V_15 ) ;
F_6 ( & V_2 -> V_10 . V_14 ) ;
return V_9 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 ,
unsigned V_6 )
{
return F_1 ( V_2 , V_4 , V_5 ,
V_6 , 0 ,
V_2 -> V_16 . V_17 ) ;
}
void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_4 ( & V_2 -> V_10 . V_14 ) ;
F_9 ( V_4 ) ;
F_6 ( & V_2 -> V_10 . V_14 ) ;
}
static unsigned long F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
struct V_21 * V_22 ;
T_2 V_23 ;
V_23 = 0 ;
if ( F_3 ( V_19 ) -> V_13 >= 3 ) {
F_11 ( V_19 -> V_24 , 0x5c , & V_23 ) ;
V_23 &= ~ ( ( 1 << 20 ) - 1 ) ;
} else if ( F_12 ( V_19 ) ) {
T_3 V_25 = 0 ;
F_13 ( V_19 -> V_24 -> V_26 , F_14 ( 0 , 0 ) ,
V_27 , & V_25 ) ;
V_23 = V_25 << 16 ;
} else if ( F_15 ( V_19 ) ) {
T_2 V_28 = 0 ;
T_2 V_29 ;
T_4 V_30 ;
F_16 ( V_19 -> V_24 -> V_26 , F_14 ( 0 , 0 ) ,
V_31 , & V_30 ) ;
if ( V_30 & V_32 )
V_28 = F_17 ( 1 ) ;
F_16 ( V_19 -> V_24 -> V_26 , F_14 ( 0 , 1 ) ,
V_33 , & V_30 ) ;
V_29 = V_30 * F_17 ( 32 ) ;
V_23 = V_29 - V_28 - V_2 -> V_16 . V_34 ;
} else if ( F_18 ( V_19 ) ) {
T_2 V_28 = 0 ;
T_2 V_29 ;
T_4 V_30 ;
F_16 ( V_19 -> V_24 -> V_26 , F_14 ( 0 , 0 ) ,
V_35 , & V_30 ) ;
if ( V_30 & V_32 ) {
switch ( V_30 & V_36 ) {
case V_37 :
V_28 = F_19 ( 512 ) ;
break;
case V_38 :
V_28 = F_17 ( 1 ) ;
break;
}
}
F_16 ( V_19 -> V_24 -> V_26 , F_14 ( 0 , 0 ) ,
V_39 , & V_30 ) ;
V_29 = V_30 * F_17 ( 32 ) ;
V_23 = V_29 - V_28 - V_2 -> V_16 . V_34 ;
} else if ( F_20 ( V_19 ) ) {
T_2 V_28 = 0 ;
T_2 V_29 ;
T_4 V_30 ;
F_16 ( V_19 -> V_24 -> V_26 , F_14 ( 0 , 0 ) ,
V_40 , & V_30 ) ;
if ( V_30 & V_32 ) {
if ( V_30 & V_41 )
V_28 = F_17 ( 1 ) ;
else
V_28 = F_19 ( 512 ) ;
}
F_16 ( V_19 -> V_24 -> V_26 , F_14 ( 0 , 0 ) ,
V_39 , & V_30 ) ;
V_29 = V_30 * F_17 ( 32 ) ;
V_23 = V_29 - V_28 - V_2 -> V_16 . V_34 ;
}
if ( V_23 == 0 )
return 0 ;
if ( F_3 ( V_19 ) -> V_13 <= 4 && ! F_21 ( V_19 ) && ! F_22 ( V_19 ) ) {
struct {
T_2 V_7 , V_8 ;
} V_11 [ 2 ] = {
{ . V_7 = V_23 , . V_8 = V_23 + V_2 -> V_16 . V_34 , } ,
{ . V_7 = V_23 , . V_8 = V_23 + V_2 -> V_16 . V_34 , } ,
} ;
T_1 V_42 , V_43 ;
V_42 = F_23 ( V_44 ) ;
if ( F_24 ( V_19 ) )
V_42 = ( V_42 & V_45 ) |
( V_42 & V_46 ) << 28 ;
else
V_42 &= V_45 ;
V_43 = V_42 + F_25 ( V_2 -> V_16 ) * 4 ;
if ( V_42 >= V_11 [ 0 ] . V_7 && V_42 < V_11 [ 0 ] . V_8 )
V_11 [ 0 ] . V_8 = V_42 ;
if ( V_43 > V_11 [ 1 ] . V_7 && V_43 <= V_11 [ 1 ] . V_8 )
V_11 [ 1 ] . V_7 = V_43 ;
if ( V_11 [ 0 ] . V_8 - V_11 [ 0 ] . V_7 >
V_11 [ 1 ] . V_8 - V_11 [ 1 ] . V_7 ) {
V_23 = V_11 [ 0 ] . V_7 ;
V_2 -> V_16 . V_34 = V_11 [ 0 ] . V_8 - V_11 [ 0 ] . V_7 ;
} else {
V_23 = V_11 [ 1 ] . V_7 ;
V_2 -> V_16 . V_34 = V_11 [ 1 ] . V_8 - V_11 [ 1 ] . V_7 ;
}
if ( V_11 [ 0 ] . V_7 != V_11 [ 1 ] . V_7 ||
V_11 [ 0 ] . V_8 != V_11 [ 1 ] . V_8 ) {
F_26 ( L_1 ,
( unsigned long long ) V_42 ,
( unsigned long long ) V_43 - 1 ) ;
F_26 ( L_2 ,
V_23 , V_23 + ( T_2 ) V_2 -> V_16 . V_34 - 1 ) ;
}
}
V_22 = F_27 ( V_19 -> V_19 , V_23 , V_2 -> V_16 . V_34 ,
L_3 ) ;
if ( V_22 == NULL ) {
V_22 = F_27 ( V_19 -> V_19 , V_23 + 1 ,
V_2 -> V_16 . V_34 - 1 ,
L_3 ) ;
if ( V_22 == NULL && ! F_28 ( V_19 ) ) {
F_29 ( L_4 ,
V_23 , V_23 + ( V_47 ) V_2 -> V_16 . V_34 ) ;
V_23 = 0 ;
}
}
return V_23 ;
}
void F_30 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return;
F_31 ( & V_2 -> V_10 . V_11 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
unsigned long * V_23 , unsigned long * V_5 )
{
V_47 V_48 = F_23 ( F_33 ( V_2 ) ?
V_49 :
V_50 ) ;
unsigned long V_51 = V_2 -> V_10 . V_52 +
V_2 -> V_16 . V_34 ;
* V_23 = ( V_48 & V_53 ) << 16 ;
F_34 ( ( V_48 & V_54 ) < * V_23 ) ;
if ( * V_23 == 0 )
* V_5 = 0 ;
else
* V_5 = V_51 - * V_23 ;
}
static void F_35 ( struct V_1 * V_2 ,
unsigned long * V_23 , unsigned long * V_5 )
{
V_47 V_48 = F_23 ( V_55 ) ;
* V_23 = V_48 & V_56 ;
switch ( V_48 & V_57 ) {
case V_58 :
* V_5 = 1024 * 1024 ;
break;
case V_59 :
* V_5 = 512 * 1024 ;
break;
case V_60 :
* V_5 = 256 * 1024 ;
break;
case V_61 :
* V_5 = 128 * 1024 ;
break;
default:
* V_5 = 1024 * 1024 ;
F_36 ( V_48 & V_57 ) ;
}
}
static void F_37 ( struct V_1 * V_2 ,
unsigned long * V_23 , unsigned long * V_5 )
{
V_47 V_48 = F_23 ( V_55 ) ;
* V_23 = V_48 & V_62 ;
switch ( V_48 & V_63 ) {
case V_64 :
* V_5 = 1024 * 1024 ;
break;
case V_65 :
* V_5 = 256 * 1024 ;
break;
default:
* V_5 = 1024 * 1024 ;
F_36 ( V_48 & V_63 ) ;
}
}
static void F_38 ( struct V_1 * V_2 ,
unsigned long * V_23 , unsigned long * V_5 )
{
V_47 V_48 = F_23 ( V_55 ) ;
* V_23 = V_48 & V_56 ;
switch ( V_48 & V_66 ) {
case V_67 :
* V_5 = 1024 * 1024 ;
break;
case V_68 :
* V_5 = 2 * 1024 * 1024 ;
break;
case V_69 :
* V_5 = 4 * 1024 * 1024 ;
break;
case V_70 :
* V_5 = 8 * 1024 * 1024 ;
break;
default:
* V_5 = 8 * 1024 * 1024 ;
F_36 ( V_48 & V_66 ) ;
}
}
static void F_39 ( struct V_1 * V_2 ,
unsigned long * V_23 , unsigned long * V_5 )
{
V_47 V_48 = F_23 ( V_55 ) ;
unsigned long V_51 ;
V_51 = V_2 -> V_10 . V_52 + V_2 -> V_16 . V_34 ;
* V_23 = V_48 & V_56 ;
if ( * V_23 == 0 )
* V_5 = 0 ;
else
* V_5 = V_51 - * V_23 ;
}
int F_40 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
unsigned long V_71 , V_72 = 0 , V_73 ;
unsigned long V_51 ;
F_41 ( & V_2 -> V_10 . V_14 ) ;
#ifdef F_42
if ( V_74 && F_3 ( V_19 ) -> V_13 < 8 ) {
F_43 ( L_5 ) ;
return 0 ;
}
#endif
if ( V_2 -> V_16 . V_34 == 0 )
return 0 ;
V_2 -> V_10 . V_52 = F_10 ( V_19 ) ;
if ( V_2 -> V_10 . V_52 == 0 )
return 0 ;
V_51 = V_2 -> V_10 . V_52 + V_2 -> V_16 . V_34 ;
switch ( F_3 ( V_2 ) -> V_13 ) {
case 2 :
case 3 :
break;
case 4 :
if ( F_22 ( V_19 ) )
F_32 ( V_2 , & V_72 ,
& V_73 ) ;
break;
case 5 :
V_73 = 1024 * 1024 ;
V_72 = V_51 - V_73 ;
break;
case 6 :
F_35 ( V_2 , & V_72 ,
& V_73 ) ;
break;
case 7 :
F_37 ( V_2 , & V_72 ,
& V_73 ) ;
break;
default:
if ( F_44 ( V_2 ) || F_45 ( V_2 ) )
F_39 ( V_2 , & V_72 ,
& V_73 ) ;
else
F_38 ( V_2 , & V_72 ,
& V_73 ) ;
break;
}
if ( V_72 == 0 ) {
V_73 = 0 ;
V_72 = V_51 ;
}
if ( V_72 < V_2 -> V_10 . V_52 ||
V_72 + V_73 > V_51 ) {
F_26 ( L_6 ,
V_72 , V_72 + V_73 ,
V_2 -> V_10 . V_52 , V_51 ) ;
return 0 ;
}
V_71 = V_51 - V_72 ;
F_26 ( L_7 ,
V_2 -> V_16 . V_34 >> 10 ,
( V_2 -> V_16 . V_34 - V_71 ) >> 10 ) ;
V_2 -> V_16 . V_17 = V_2 -> V_16 . V_34 -
V_71 ;
F_46 ( & V_2 -> V_10 . V_11 , 0 , V_2 -> V_16 . V_17 ) ;
return 0 ;
}
static struct V_75 *
F_47 ( struct V_18 * V_19 ,
T_2 V_76 , T_2 V_5 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
struct V_75 * V_77 ;
struct V_78 * V_79 ;
F_48 ( L_8 , V_76 , V_5 ) ;
F_49 ( V_76 > V_2 -> V_16 . V_34 - V_5 ) ;
V_77 = F_50 ( sizeof( * V_77 ) , V_80 ) ;
if ( V_77 == NULL )
return NULL ;
if ( F_51 ( V_77 , 1 , V_80 ) ) {
F_52 ( V_77 ) ;
return NULL ;
}
V_79 = V_77 -> V_81 ;
V_79 -> V_76 = 0 ;
V_79 -> V_82 = V_5 ;
F_53 ( V_79 ) = ( V_83 ) V_2 -> V_10 . V_52 + V_76 ;
F_54 ( V_79 ) = V_5 ;
return V_77 ;
}
static int F_55 ( struct V_84 * V_85 )
{
F_56 () ;
return - V_86 ;
}
static void F_57 ( struct V_84 * V_85 )
{
F_58 ( V_85 -> V_87 ) ;
F_52 ( V_85 -> V_87 ) ;
}
static void
F_59 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_23 . V_19 -> V_20 ;
if ( V_85 -> V_11 ) {
F_8 ( V_2 , V_85 -> V_11 ) ;
F_52 ( V_85 -> V_11 ) ;
V_85 -> V_11 = NULL ;
}
}
static struct V_84 *
F_60 ( struct V_18 * V_19 ,
struct V_3 * V_11 )
{
struct V_84 * V_85 ;
V_85 = F_61 ( V_19 ) ;
if ( V_85 == NULL )
return NULL ;
F_62 ( V_19 , & V_85 -> V_23 , V_11 -> V_5 ) ;
F_63 ( V_85 , & V_88 ) ;
V_85 -> V_87 = F_47 ( V_19 ,
V_11 -> V_7 , V_11 -> V_5 ) ;
if ( V_85 -> V_87 == NULL )
goto V_89;
F_64 ( V_85 ) ;
V_85 -> V_11 = V_11 ;
V_85 -> V_23 . V_90 = V_91 | V_92 ;
V_85 -> V_93 = F_65 ( V_19 ) ? V_94 : V_95 ;
return V_85 ;
V_89:
F_66 ( V_85 ) ;
return NULL ;
}
struct V_84 *
F_67 ( struct V_18 * V_19 , T_2 V_5 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
struct V_84 * V_85 ;
struct V_3 * V_11 ;
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return NULL ;
F_26 ( L_9 , V_5 ) ;
if ( V_5 == 0 )
return NULL ;
V_11 = F_68 ( sizeof( * V_11 ) , V_80 ) ;
if ( ! V_11 )
return NULL ;
V_9 = F_7 ( V_2 , V_11 , V_5 , 4096 ) ;
if ( V_9 ) {
F_52 ( V_11 ) ;
return NULL ;
}
V_85 = F_60 ( V_19 , V_11 ) ;
if ( V_85 )
return V_85 ;
F_8 ( V_2 , V_11 ) ;
F_52 ( V_11 ) ;
return NULL ;
}
struct V_84 *
F_69 ( struct V_18 * V_19 ,
T_2 V_96 ,
T_2 V_97 ,
T_2 V_5 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
struct V_98 * V_99 = & V_2 -> V_16 . V_23 ;
struct V_84 * V_85 ;
struct V_3 * V_11 ;
struct V_100 * V_101 ;
int V_9 ;
if ( ! F_2 ( & V_2 -> V_10 . V_11 ) )
return NULL ;
F_26 ( L_10 ,
V_96 , V_97 , V_5 ) ;
if ( F_34 ( V_5 == 0 ) || F_34 ( V_5 & 4095 ) ||
F_34 ( V_96 & 4095 ) )
return NULL ;
V_11 = F_68 ( sizeof( * V_11 ) , V_80 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_7 = V_96 ;
V_11 -> V_5 = V_5 ;
F_4 ( & V_2 -> V_10 . V_14 ) ;
V_9 = F_70 ( & V_2 -> V_10 . V_11 , V_11 ) ;
F_6 ( & V_2 -> V_10 . V_14 ) ;
if ( V_9 ) {
F_26 ( L_11 ) ;
F_52 ( V_11 ) ;
return NULL ;
}
V_85 = F_60 ( V_19 , V_11 ) ;
if ( V_85 == NULL ) {
F_26 ( L_12 ) ;
F_8 ( V_2 , V_11 ) ;
F_52 ( V_11 ) ;
return NULL ;
}
if ( V_97 == V_102 )
return V_85 ;
V_101 = F_71 ( V_85 , V_99 ) ;
if ( F_72 ( V_101 ) ) {
V_9 = F_73 ( V_101 ) ;
goto V_103;
}
V_101 -> V_4 . V_7 = V_97 ;
V_101 -> V_4 . V_5 = V_5 ;
if ( F_2 ( & V_99 -> V_10 ) ) {
V_9 = F_70 ( & V_99 -> V_10 , & V_101 -> V_4 ) ;
if ( V_9 ) {
F_26 ( L_13 ) ;
goto V_103;
}
V_101 -> V_104 |= V_105 ;
F_74 ( V_101 ) ;
F_75 ( & V_101 -> V_106 , & V_99 -> V_107 ) ;
}
F_75 ( & V_85 -> V_108 , & V_2 -> V_10 . V_109 ) ;
F_64 ( V_85 ) ;
return V_85 ;
V_103:
F_76 ( & V_85 -> V_23 ) ;
return NULL ;
}
