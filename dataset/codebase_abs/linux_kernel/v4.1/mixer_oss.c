static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_7 = F_2 ( V_1 , V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_4 = F_3 ( F_4 ( V_1 ) ,
V_8 ) ;
if ( V_4 == NULL )
return - V_9 ;
if ( V_4 -> V_10 == NULL ) {
F_5 ( V_4 ) ;
return - V_9 ;
}
V_7 = F_6 ( V_4 , V_2 ) ;
if ( V_7 < 0 ) {
F_5 ( V_4 ) ;
return V_7 ;
}
V_6 = F_7 ( sizeof( * V_6 ) , V_11 ) ;
if ( V_6 == NULL ) {
F_8 ( V_4 , V_2 ) ;
F_5 ( V_4 ) ;
return - V_12 ;
}
V_6 -> V_4 = V_4 ;
V_6 -> V_13 = V_4 -> V_10 ;
V_2 -> V_14 = V_6 ;
if ( ! F_9 ( V_4 -> V_15 ) ) {
F_10 ( V_6 ) ;
F_8 ( V_4 , V_2 ) ;
F_5 ( V_4 ) ;
return - V_16 ;
}
F_5 ( V_4 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_5 * V_6 ;
if ( V_2 -> V_14 ) {
V_6 = V_2 -> V_14 ;
F_12 ( V_6 -> V_4 -> V_15 ) ;
F_8 ( V_6 -> V_4 , V_2 ) ;
F_10 ( V_6 ) ;
}
return 0 ;
}
static int F_13 ( struct V_5 * V_6 ,
T_1 T_2 * V_17 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_18 * V_13 = V_6 -> V_13 ;
struct T_1 V_19 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
F_14 ( V_19 . V_20 , V_13 && V_13 -> V_20 [ 0 ] ? V_13 -> V_20 : V_4 -> V_21 , sizeof( V_19 . V_20 ) ) ;
F_14 ( V_19 . V_22 , V_13 && V_13 -> V_22 [ 0 ] ? V_13 -> V_22 : V_4 -> V_23 , sizeof( V_19 . V_22 ) ) ;
V_19 . V_24 = V_4 -> V_25 ;
if ( F_15 ( V_17 , & V_19 , sizeof( V_19 ) ) )
return - V_16 ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
T_3 T_2 * V_17 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_18 * V_13 = V_6 -> V_13 ;
T_3 V_19 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
F_14 ( V_19 . V_20 , V_13 && V_13 -> V_20 [ 0 ] ? V_13 -> V_20 : V_4 -> V_21 , sizeof( V_19 . V_20 ) ) ;
F_14 ( V_19 . V_22 , V_13 && V_13 -> V_22 [ 0 ] ? V_13 -> V_22 : V_4 -> V_23 , sizeof( V_19 . V_22 ) ) ;
if ( F_15 ( V_17 , & V_19 , sizeof( V_19 ) ) )
return - V_16 ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 )
{
struct V_18 * V_13 = V_6 -> V_13 ;
int V_26 = 0 ;
if ( V_13 == NULL )
return - V_27 ;
if ( V_13 -> V_28 && V_13 -> V_29 )
V_26 |= V_30 ;
return V_26 ;
}
static int F_18 ( struct V_5 * V_6 )
{
struct V_18 * V_13 = V_6 -> V_13 ;
struct V_31 * V_32 ;
int V_26 = 0 , V_33 ;
if ( V_13 == NULL )
return - V_27 ;
for ( V_33 = 0 ; V_33 < 31 ; V_33 ++ ) {
V_32 = & V_13 -> V_34 [ V_33 ] ;
if ( V_32 -> V_35 || V_32 -> V_29 )
V_26 |= 1 << V_33 ;
}
return V_26 ;
}
static int F_19 ( struct V_5 * V_6 )
{
struct V_18 * V_13 = V_6 -> V_13 ;
struct V_31 * V_32 ;
int V_26 = 0 , V_33 ;
if ( V_13 == NULL )
return - V_27 ;
for ( V_33 = 0 ; V_33 < 31 ; V_33 ++ ) {
V_32 = & V_13 -> V_34 [ V_33 ] ;
if ( V_32 -> V_35 && V_32 -> V_36 )
V_26 |= 1 << V_33 ;
}
return V_26 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_18 * V_13 = V_6 -> V_13 ;
int V_26 = 0 ;
if ( V_13 == NULL )
return - V_27 ;
if ( V_13 -> V_29 && V_13 -> V_28 ) {
V_26 = V_13 -> V_37 ;
} else {
struct V_31 * V_32 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < 31 ; V_33 ++ ) {
V_32 = & V_13 -> V_34 [ V_33 ] ;
if ( V_32 -> V_29 )
V_26 |= 1 << V_33 ;
}
}
return V_26 ;
}
static int F_21 ( struct V_5 * V_6 )
{
struct V_18 * V_13 = V_6 -> V_13 ;
int V_26 = 0 ;
if ( V_13 == NULL )
return - V_27 ;
if ( V_13 -> V_29 && V_13 -> V_28 ) {
int V_7 ;
unsigned int V_38 ;
if ( ( V_7 = V_13 -> V_28 ( V_6 , & V_38 ) ) < 0 )
return V_7 ;
V_26 = 1 << V_38 ;
} else {
struct V_31 * V_32 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < 31 ; V_33 ++ ) {
V_32 = & V_13 -> V_34 [ V_33 ] ;
if ( V_32 -> V_28 ) {
int V_39 = 0 ;
V_32 -> V_28 ( V_6 , V_32 , & V_39 ) ;
if ( V_39 )
V_26 |= 1 << V_33 ;
}
}
}
return V_13 -> V_40 = V_26 ;
}
static int F_22 ( struct V_5 * V_6 , int V_41 )
{
struct V_18 * V_13 = V_6 -> V_13 ;
struct V_31 * V_32 ;
int V_33 , V_39 ;
unsigned int V_38 ;
int V_26 = 0 ;
if ( V_13 == NULL )
return - V_27 ;
if ( V_13 -> V_28 && V_13 -> V_29 ) {
if ( V_41 & ~ V_13 -> V_40 )
V_41 &= ~ V_13 -> V_40 ;
V_13 -> V_29 ( V_6 , F_23 ( ~ V_41 ) ) ;
V_13 -> V_28 ( V_6 , & V_38 ) ;
V_26 = 1 << V_38 ;
}
for ( V_33 = 0 ; V_33 < 31 ; V_33 ++ ) {
V_32 = & V_13 -> V_34 [ V_33 ] ;
if ( V_32 -> V_29 ) {
V_39 = ( V_41 & ( 1 << V_33 ) ) ? 1 : 0 ;
V_32 -> V_29 ( V_6 , V_32 , V_39 ) ;
}
}
if ( ! V_26 ) {
for ( V_33 = 0 ; V_33 < 31 ; V_33 ++ ) {
V_32 = & V_13 -> V_34 [ V_33 ] ;
if ( V_32 -> V_28 ) {
V_39 = 0 ;
V_32 -> V_28 ( V_6 , V_32 , & V_39 ) ;
if ( V_39 )
V_26 |= 1 << V_33 ;
}
}
}
return V_26 ;
}
static int F_24 ( struct V_5 * V_6 , int V_42 )
{
struct V_18 * V_13 = V_6 -> V_13 ;
struct V_31 * V_32 ;
int V_26 = 0 , V_43 , V_44 ;
if ( V_13 == NULL || V_42 > 30 )
return - V_27 ;
V_32 = & V_13 -> V_34 [ V_42 ] ;
V_43 = V_32 -> V_45 [ 0 ] ;
V_44 = V_32 -> V_45 [ 1 ] ;
if ( V_32 -> V_46 )
V_26 = V_32 -> V_46 ( V_6 , V_32 , & V_43 , & V_44 ) ;
if ( ! V_32 -> V_36 )
V_44 = V_43 ;
if ( F_25 ( V_43 < 0 || V_43 > 100 ) )
return - V_27 ;
if ( F_25 ( V_44 < 0 || V_44 > 100 ) )
return - V_27 ;
if ( V_26 >= 0 ) {
V_32 -> V_45 [ 0 ] = V_43 ;
V_32 -> V_45 [ 1 ] = V_44 ;
V_26 = ( V_43 & 0xff ) | ( ( V_44 & 0xff ) << 8 ) ;
}
return V_26 ;
}
static int F_26 ( struct V_5 * V_6 ,
int V_42 , int V_45 )
{
struct V_18 * V_13 = V_6 -> V_13 ;
struct V_31 * V_32 ;
int V_26 = 0 , V_43 = V_45 & 0xff , V_44 = ( V_45 >> 8 ) & 0xff ;
if ( V_13 == NULL || V_42 > 30 )
return - V_27 ;
V_32 = & V_13 -> V_34 [ V_42 ] ;
if ( V_43 > 100 )
V_43 = 100 ;
if ( V_44 > 100 )
V_44 = 100 ;
if ( ! V_32 -> V_36 )
V_44 = V_43 ;
if ( V_32 -> V_35 )
V_26 = V_32 -> V_35 ( V_6 , V_32 , V_43 , V_44 ) ;
if ( V_26 < 0 )
return V_26 ;
V_32 -> V_45 [ 0 ] = V_43 ;
V_32 -> V_45 [ 1 ] = V_44 ;
return ( V_43 & 0xff ) | ( ( V_44 & 0xff ) << 8 ) ;
}
static int F_27 ( struct V_5 * V_6 , unsigned int V_47 , unsigned long V_48 )
{
void T_2 * V_49 = ( void T_2 * ) V_48 ;
int T_2 * V_50 = V_49 ;
int V_51 ;
if ( F_25 ( ! V_6 ) )
return - V_52 ;
if ( ( ( V_47 >> 8 ) & 0xff ) == 'M' ) {
switch ( V_47 ) {
case V_53 :
return F_13 ( V_6 , V_49 ) ;
case V_54 :
return F_16 ( V_6 , V_49 ) ;
case V_55 :
if ( F_28 ( V_51 , V_50 ) )
return - V_16 ;
V_51 = F_22 ( V_6 , V_51 ) ;
if ( V_51 < 0 )
return V_51 ;
return F_29 ( V_51 , V_50 ) ;
case V_56 :
return F_29 ( V_57 , V_50 ) ;
case V_58 :
return F_29 ( 1 , V_50 ) ;
case V_59 :
V_51 = F_18 ( V_6 ) ;
if ( V_51 < 0 )
return V_51 ;
return F_29 ( V_51 , V_50 ) ;
case V_60 :
V_51 = F_19 ( V_6 ) ;
if ( V_51 < 0 )
return V_51 ;
return F_29 ( V_51 , V_50 ) ;
case V_61 :
V_51 = F_20 ( V_6 ) ;
if ( V_51 < 0 )
return V_51 ;
return F_29 ( V_51 , V_50 ) ;
case V_62 :
V_51 = F_17 ( V_6 ) ;
if ( V_51 < 0 )
return V_51 ;
return F_29 ( V_51 , V_50 ) ;
case V_63 :
V_51 = F_21 ( V_6 ) ;
if ( V_51 < 0 )
return V_51 ;
return F_29 ( V_51 , V_50 ) ;
}
}
if ( V_47 & V_64 ) {
if ( F_28 ( V_51 , V_50 ) )
return - V_16 ;
V_51 = F_26 ( V_6 , V_47 & 0xff , V_51 ) ;
if ( V_51 < 0 )
return V_51 ;
return F_29 ( V_51 , V_50 ) ;
} else if ( V_47 & V_65 ) {
V_51 = F_24 ( V_6 , V_47 & 0xff ) ;
if ( V_51 < 0 )
return V_51 ;
return F_29 ( V_51 , V_50 ) ;
}
return - V_52 ;
}
static long F_30 ( struct V_2 * V_2 , unsigned int V_47 , unsigned long V_48 )
{
return F_27 ( V_2 -> V_14 , V_47 , V_48 ) ;
}
int F_31 ( struct V_3 * V_4 , unsigned int V_47 , unsigned long V_48 )
{
struct V_5 V_6 ;
if ( F_25 ( ! V_4 ) )
return - V_52 ;
if ( V_4 -> V_10 == NULL )
return - V_52 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_4 = V_4 ;
V_6 . V_13 = V_4 -> V_10 ;
return F_27 ( & V_6 , V_47 , V_48 ) ;
}
static long F_32 ( long V_66 , long V_67 , long V_68 , long V_69 , long V_70 )
{
long V_71 = V_68 - V_67 , V_72 = V_70 - V_69 ;
if ( V_71 == 0 )
return 0 ;
return ( ( V_72 * ( V_66 - V_67 ) ) + ( V_71 / 2 ) ) / V_71 + V_69 ;
}
static long F_33 ( long V_66 , long V_73 , long V_74 , int * V_75 )
{
if ( V_66 == F_32 ( * V_75 , 0 , 100 , V_73 , V_74 ) )
return * V_75 ;
return F_32 ( V_66 , V_73 , V_74 , 0 , 100 ) ;
}
static long F_34 ( long V_66 , long V_73 , long V_74 )
{
return F_32 ( V_66 , 0 , 100 , V_73 , V_74 ) ;
}
static struct V_76 * F_35 ( struct V_18 * V_13 , const char * V_22 , int V_38 )
{
struct V_3 * V_4 = V_13 -> V_4 ;
struct V_77 V_20 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_78 = V_79 ;
F_14 ( V_20 . V_22 , V_22 , sizeof( V_20 . V_22 ) ) ;
V_20 . V_38 = V_38 ;
return F_36 ( V_4 , & V_20 ) ;
}
static void F_37 ( struct V_5 * V_6 ,
struct V_31 * V_32 ,
unsigned int V_80 ,
int * V_43 , int * V_44 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_76 * V_85 ;
struct V_3 * V_4 = V_6 -> V_4 ;
if ( V_80 == V_86 )
return;
F_38 ( & V_4 -> V_87 ) ;
if ( ( V_85 = F_39 ( V_4 , V_80 ) ) == NULL ) {
F_40 ( & V_4 -> V_87 ) ;
return;
}
V_82 = F_7 ( sizeof( * V_82 ) , V_11 ) ;
V_84 = F_7 ( sizeof( * V_84 ) , V_11 ) ;
if ( V_82 == NULL || V_84 == NULL )
goto V_88;
if ( V_85 -> V_19 ( V_85 , V_82 ) )
goto V_88;
if ( V_85 -> V_89 ( V_85 , V_84 ) )
goto V_88;
if ( V_82 -> type == V_90 &&
V_82 -> V_91 . integer . V_73 == 0 && V_82 -> V_91 . integer . V_74 == 1 )
goto V_88;
* V_43 = F_33 ( V_84 -> V_91 . integer . V_91 [ 0 ] , V_82 -> V_91 . integer . V_73 , V_82 -> V_91 . integer . V_74 , & V_32 -> V_45 [ 0 ] ) ;
if ( V_82 -> V_92 > 1 )
* V_44 = F_33 ( V_84 -> V_91 . integer . V_91 [ 1 ] , V_82 -> V_91 . integer . V_73 , V_82 -> V_91 . integer . V_74 , & V_32 -> V_45 [ 1 ] ) ;
V_88:
F_40 ( & V_4 -> V_87 ) ;
F_10 ( V_84 ) ;
F_10 ( V_82 ) ;
}
static void F_41 ( struct V_5 * V_6 ,
struct V_31 * V_32 ,
unsigned int V_80 ,
int * V_43 , int * V_44 ,
int V_93 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_76 * V_85 ;
struct V_3 * V_4 = V_6 -> V_4 ;
if ( V_80 == V_86 )
return;
F_38 ( & V_4 -> V_87 ) ;
if ( ( V_85 = F_39 ( V_4 , V_80 ) ) == NULL ) {
F_40 ( & V_4 -> V_87 ) ;
return;
}
V_82 = F_7 ( sizeof( * V_82 ) , V_11 ) ;
V_84 = F_7 ( sizeof( * V_84 ) , V_11 ) ;
if ( V_82 == NULL || V_84 == NULL )
goto V_88;
if ( V_85 -> V_19 ( V_85 , V_82 ) )
goto V_88;
if ( V_85 -> V_89 ( V_85 , V_84 ) )
goto V_88;
if ( ! V_84 -> V_91 . integer . V_91 [ 0 ] ) {
* V_43 = 0 ;
if ( V_82 -> V_92 == 1 )
* V_44 = 0 ;
}
if ( V_82 -> V_92 > 1 && ! V_84 -> V_91 . integer . V_91 [ V_93 ? 3 : 1 ] )
* V_44 = 0 ;
V_88:
F_40 ( & V_4 -> V_87 ) ;
F_10 ( V_84 ) ;
F_10 ( V_82 ) ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_31 * V_32 ,
int * V_43 , int * V_44 )
{
struct V_42 * V_42 = V_32 -> V_14 ;
* V_43 = * V_44 = 100 ;
if ( V_42 -> V_94 & V_95 ) {
F_37 ( V_6 , V_32 , V_42 -> V_80 [ V_96 ] , V_43 , V_44 ) ;
} else if ( V_42 -> V_94 & V_97 ) {
F_37 ( V_6 , V_32 , V_42 -> V_80 [ V_98 ] , V_43 , V_44 ) ;
} else if ( V_42 -> V_94 & V_99 ) {
F_37 ( V_6 , V_32 , V_42 -> V_80 [ V_100 ] , V_43 , V_44 ) ;
}
if ( V_42 -> V_94 & V_101 ) {
F_41 ( V_6 , V_32 , V_42 -> V_80 [ V_102 ] , V_43 , V_44 , 0 ) ;
} else if ( V_42 -> V_94 & V_103 ) {
F_41 ( V_6 , V_32 , V_42 -> V_80 [ V_104 ] , V_43 , V_44 , 0 ) ;
} else if ( V_42 -> V_94 & V_105 ) {
F_41 ( V_6 , V_32 , V_42 -> V_80 [ V_106 ] , V_43 , V_44 , 1 ) ;
} else if ( V_42 -> V_94 & V_107 ) {
F_41 ( V_6 , V_32 , V_42 -> V_80 [ V_108 ] , V_43 , V_44 , 1 ) ;
}
return 0 ;
}
static void F_43 ( struct V_5 * V_6 ,
struct V_31 * V_32 ,
unsigned int V_80 ,
int V_43 , int V_44 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_76 * V_85 ;
struct V_3 * V_4 = V_6 -> V_4 ;
int V_109 ;
if ( V_80 == V_86 )
return;
F_38 ( & V_4 -> V_87 ) ;
if ( ( V_85 = F_39 ( V_4 , V_80 ) ) == NULL ) {
F_40 ( & V_4 -> V_87 ) ;
return;
}
V_82 = F_7 ( sizeof( * V_82 ) , V_11 ) ;
V_84 = F_7 ( sizeof( * V_84 ) , V_11 ) ;
if ( V_82 == NULL || V_84 == NULL )
goto V_88;
if ( V_85 -> V_19 ( V_85 , V_82 ) )
goto V_88;
if ( V_82 -> type == V_90 &&
V_82 -> V_91 . integer . V_73 == 0 && V_82 -> V_91 . integer . V_74 == 1 )
goto V_88;
V_84 -> V_91 . integer . V_91 [ 0 ] = F_34 ( V_43 , V_82 -> V_91 . integer . V_73 , V_82 -> V_91 . integer . V_74 ) ;
if ( V_82 -> V_92 > 1 )
V_84 -> V_91 . integer . V_91 [ 1 ] = F_34 ( V_44 , V_82 -> V_91 . integer . V_73 , V_82 -> V_91 . integer . V_74 ) ;
if ( ( V_109 = V_85 -> V_110 ( V_85 , V_84 ) ) < 0 )
goto V_88;
if ( V_109 > 0 )
F_44 ( V_4 , V_111 , & V_85 -> V_20 ) ;
V_88:
F_40 ( & V_4 -> V_87 ) ;
F_10 ( V_84 ) ;
F_10 ( V_82 ) ;
}
static void F_45 ( struct V_5 * V_6 ,
struct V_31 * V_32 ,
unsigned int V_80 ,
int V_43 , int V_44 ,
int V_93 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_76 * V_85 ;
struct V_3 * V_4 = V_6 -> V_4 ;
int V_109 ;
if ( V_80 == V_86 )
return;
F_38 ( & V_4 -> V_87 ) ;
if ( ( V_85 = F_39 ( V_4 , V_80 ) ) == NULL ) {
F_40 ( & V_4 -> V_87 ) ;
return;
}
V_82 = F_7 ( sizeof( * V_82 ) , V_11 ) ;
V_84 = F_7 ( sizeof( * V_84 ) , V_11 ) ;
if ( V_82 == NULL || V_84 == NULL )
goto V_88;
if ( V_85 -> V_19 ( V_85 , V_82 ) )
goto V_88;
if ( V_82 -> V_92 > 1 ) {
V_84 -> V_91 . integer . V_91 [ 0 ] = V_43 > 0 ? 1 : 0 ;
V_84 -> V_91 . integer . V_91 [ V_93 ? 3 : 1 ] = V_44 > 0 ? 1 : 0 ;
if ( V_93 ) {
V_84 -> V_91 . integer . V_91 [ 1 ] =
V_84 -> V_91 . integer . V_91 [ 2 ] = 0 ;
}
} else {
V_84 -> V_91 . integer . V_91 [ 0 ] = ( V_43 > 0 || V_44 > 0 ) ? 1 : 0 ;
}
if ( ( V_109 = V_85 -> V_110 ( V_85 , V_84 ) ) < 0 )
goto V_88;
if ( V_109 > 0 )
F_44 ( V_4 , V_111 , & V_85 -> V_20 ) ;
V_88:
F_40 ( & V_4 -> V_87 ) ;
F_10 ( V_84 ) ;
F_10 ( V_82 ) ;
}
static int F_46 ( struct V_5 * V_6 ,
struct V_31 * V_32 ,
int V_43 , int V_44 )
{
struct V_42 * V_42 = V_32 -> V_14 ;
if ( V_42 -> V_94 & V_95 ) {
F_43 ( V_6 , V_32 , V_42 -> V_80 [ V_96 ] , V_43 , V_44 ) ;
if ( V_42 -> V_94 & V_112 )
F_43 ( V_6 , V_32 , V_42 -> V_80 [ V_113 ] , V_43 , V_44 ) ;
} else if ( V_42 -> V_94 & V_112 ) {
F_43 ( V_6 , V_32 ,
V_42 -> V_80 [ V_113 ] , V_43 , V_44 ) ;
} else if ( V_42 -> V_94 & V_97 ) {
F_43 ( V_6 , V_32 , V_42 -> V_80 [ V_98 ] , V_43 , V_44 ) ;
} else if ( V_42 -> V_94 & V_99 ) {
F_43 ( V_6 , V_32 , V_42 -> V_80 [ V_100 ] , V_43 , V_44 ) ;
}
if ( V_43 || V_44 ) {
if ( V_42 -> V_94 & V_101 )
F_45 ( V_6 , V_32 , V_42 -> V_80 [ V_102 ] , V_43 , V_44 , 0 ) ;
if ( V_42 -> V_94 & V_114 )
F_45 ( V_6 , V_32 , V_42 -> V_80 [ V_115 ] , V_43 , V_44 , 0 ) ;
if ( V_42 -> V_94 & V_103 )
F_45 ( V_6 , V_32 , V_42 -> V_80 [ V_104 ] , V_43 , V_44 , 0 ) ;
if ( V_42 -> V_94 & V_105 )
F_45 ( V_6 , V_32 , V_42 -> V_80 [ V_106 ] , V_43 , V_44 , 1 ) ;
if ( V_42 -> V_94 & V_116 )
F_45 ( V_6 , V_32 , V_42 -> V_80 [ V_117 ] , V_43 , V_44 , 1 ) ;
if ( V_42 -> V_94 & V_107 )
F_45 ( V_6 , V_32 , V_42 -> V_80 [ V_108 ] , V_43 , V_44 , 1 ) ;
} else {
if ( V_42 -> V_94 & V_101 ) {
F_45 ( V_6 , V_32 , V_42 -> V_80 [ V_102 ] , V_43 , V_44 , 0 ) ;
} else if ( V_42 -> V_94 & V_114 ) {
F_45 ( V_6 , V_32 , V_42 -> V_80 [ V_115 ] , V_43 , V_44 , 0 ) ;
} else if ( V_42 -> V_94 & V_103 ) {
F_45 ( V_6 , V_32 , V_42 -> V_80 [ V_104 ] , V_43 , V_44 , 0 ) ;
} else if ( V_42 -> V_94 & V_105 ) {
F_45 ( V_6 , V_32 , V_42 -> V_80 [ V_106 ] , V_43 , V_44 , 1 ) ;
} else if ( V_42 -> V_94 & V_116 ) {
F_45 ( V_6 , V_32 , V_42 -> V_80 [ V_117 ] , V_43 , V_44 , 1 ) ;
} else if ( V_42 -> V_94 & V_107 ) {
F_45 ( V_6 , V_32 , V_42 -> V_80 [ V_108 ] , V_43 , V_44 , 1 ) ;
}
}
return 0 ;
}
static int F_47 ( struct V_5 * V_6 ,
struct V_31 * V_32 ,
int * V_39 )
{
struct V_42 * V_42 = V_32 -> V_14 ;
int V_43 , V_44 ;
V_43 = V_44 = 1 ;
F_41 ( V_6 , V_32 , V_42 -> V_80 [ V_115 ] , & V_43 , & V_44 , 0 ) ;
* V_39 = ( V_43 || V_44 ) ? 1 : 0 ;
return 0 ;
}
static int F_48 ( struct V_5 * V_6 ,
struct V_31 * V_32 ,
int * V_39 )
{
struct V_42 * V_42 = V_32 -> V_14 ;
int V_43 , V_44 ;
V_43 = V_44 = 1 ;
F_41 ( V_6 , V_32 , V_42 -> V_80 [ V_117 ] , & V_43 , & V_44 , 1 ) ;
* V_39 = ( V_43 || V_44 ) ? 1 : 0 ;
return 0 ;
}
static int F_49 ( struct V_5 * V_6 ,
struct V_31 * V_32 ,
int V_39 )
{
struct V_42 * V_42 = V_32 -> V_14 ;
F_45 ( V_6 , V_32 , V_42 -> V_80 [ V_115 ] , V_39 , V_39 , 0 ) ;
return 0 ;
}
static int F_50 ( struct V_5 * V_6 ,
struct V_31 * V_32 ,
int V_39 )
{
struct V_42 * V_42 = V_32 -> V_14 ;
F_45 ( V_6 , V_32 , V_42 -> V_80 [ V_117 ] , V_39 , V_39 , 1 ) ;
return 0 ;
}
static int F_51 ( struct V_5 * V_6 , unsigned int * V_118 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_18 * V_13 = V_6 -> V_13 ;
struct V_76 * V_85 ;
struct V_31 * V_32 ;
struct V_42 * V_42 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
int V_7 , V_119 ;
V_82 = F_7 ( sizeof( * V_82 ) , V_11 ) ;
V_84 = F_7 ( sizeof( * V_84 ) , V_11 ) ;
if ( V_82 == NULL || V_84 == NULL ) {
V_7 = - V_12 ;
goto V_120;
}
F_38 ( & V_4 -> V_87 ) ;
V_85 = F_35 ( V_13 , L_1 , 0 ) ;
if ( ! V_85 ) {
V_7 = - V_121 ;
goto V_122;
}
if ( ( V_7 = V_85 -> V_19 ( V_85 , V_82 ) ) < 0 )
goto V_122;
if ( ( V_7 = V_85 -> V_89 ( V_85 , V_84 ) ) < 0 )
goto V_122;
for ( V_119 = 0 ; V_119 < 32 ; V_119 ++ ) {
if ( ! ( V_13 -> V_37 & ( 1 << V_119 ) ) )
continue;
V_32 = & V_13 -> V_34 [ V_119 ] ;
V_42 = V_32 -> V_14 ;
if ( V_42 -> V_123 != V_124 )
continue;
if ( ! ( V_42 -> V_94 & V_125 ) )
continue;
if ( V_42 -> V_126 == V_84 -> V_91 . V_127 . V_128 [ 0 ] ) {
* V_118 = V_119 ;
break;
}
}
V_7 = 0 ;
V_122:
F_40 ( & V_4 -> V_87 ) ;
V_120:
F_10 ( V_84 ) ;
F_10 ( V_82 ) ;
return V_7 ;
}
static int F_52 ( struct V_5 * V_6 , unsigned int V_118 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_18 * V_13 = V_6 -> V_13 ;
struct V_76 * V_85 ;
struct V_31 * V_32 ;
struct V_42 * V_42 = NULL ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
int V_7 ;
unsigned int V_119 ;
V_82 = F_7 ( sizeof( * V_82 ) , V_11 ) ;
V_84 = F_7 ( sizeof( * V_84 ) , V_11 ) ;
if ( V_82 == NULL || V_84 == NULL ) {
V_7 = - V_12 ;
goto V_120;
}
F_38 ( & V_4 -> V_87 ) ;
V_85 = F_35 ( V_13 , L_1 , 0 ) ;
if ( ! V_85 ) {
V_7 = - V_121 ;
goto V_122;
}
if ( ( V_7 = V_85 -> V_19 ( V_85 , V_82 ) ) < 0 )
goto V_122;
for ( V_119 = 0 ; V_119 < 32 ; V_119 ++ ) {
if ( ! ( V_13 -> V_37 & ( 1 << V_119 ) ) )
continue;
V_32 = & V_13 -> V_34 [ V_119 ] ;
V_42 = V_32 -> V_14 ;
if ( V_42 -> V_123 != V_124 )
continue;
if ( ! ( V_42 -> V_94 & V_125 ) )
continue;
if ( V_119 == V_118 )
break;
V_42 = NULL ;
}
if ( ! V_42 )
goto V_122;
for ( V_119 = 0 ; V_119 < V_82 -> V_92 ; V_119 ++ )
V_84 -> V_91 . V_127 . V_128 [ V_119 ] = V_42 -> V_126 ;
V_7 = V_85 -> V_110 ( V_85 , V_84 ) ;
if ( V_7 > 0 )
F_44 ( V_6 -> V_4 , V_111 , & V_85 -> V_20 ) ;
V_7 = 0 ;
V_122:
F_40 ( & V_4 -> V_87 ) ;
V_120:
F_10 ( V_84 ) ;
F_10 ( V_82 ) ;
return V_7 ;
}
static int F_53 ( struct V_18 * V_13 , struct V_42 * V_42 , const char * V_22 , int V_38 , int V_128 )
{
struct V_81 * V_19 ;
struct V_76 * V_129 ;
struct V_3 * V_4 = V_13 -> V_4 ;
int V_7 ;
F_38 ( & V_4 -> V_87 ) ;
V_129 = F_35 ( V_13 , V_22 , V_38 ) ;
if ( V_129 == NULL ) {
F_40 ( & V_4 -> V_87 ) ;
return 0 ;
}
V_19 = F_54 ( sizeof( * V_19 ) , V_11 ) ;
if ( ! V_19 ) {
F_40 ( & V_4 -> V_87 ) ;
return - V_12 ;
}
if ( ( V_7 = V_129 -> V_19 ( V_129 , V_19 ) ) < 0 ) {
F_40 ( & V_4 -> V_87 ) ;
F_10 ( V_19 ) ;
return V_7 ;
}
V_42 -> V_80 [ V_128 ] = V_129 -> V_20 . V_80 ;
F_40 ( & V_4 -> V_87 ) ;
if ( V_19 -> V_92 > V_42 -> V_130 )
V_42 -> V_130 = V_19 -> V_92 ;
V_42 -> V_94 |= 1 << V_128 ;
F_10 ( V_19 ) ;
return 0 ;
}
static void F_55 ( struct V_31 * V_33 )
{
struct V_42 * V_50 = V_33 -> V_14 ;
if ( V_50 ) {
if ( V_50 -> V_131 && V_50 -> V_132 ) {
F_10 ( V_50 -> V_132 -> V_22 ) ;
F_10 ( V_50 -> V_132 ) ;
}
F_10 ( V_50 ) ;
}
}
static void F_56 ( struct V_31 * V_133 )
{
int V_119 = V_133 -> V_134 ;
if ( V_133 -> V_135 )
V_133 -> V_135 ( V_133 ) ;
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
V_133 -> V_134 = V_119 ;
}
static int F_57 ( struct V_18 * V_13 ,
struct V_136 * V_137 ,
struct V_42 * V_42 )
{
char V_138 [ 64 ] ;
int V_7 ;
V_7 = F_53 ( V_13 , V_42 , V_137 -> V_22 , V_137 -> V_38 ,
V_100 ) ;
if ( V_7 )
return V_7 ;
sprintf ( V_138 , L_2 , V_137 -> V_22 ) ;
V_7 = F_53 ( V_13 , V_42 , V_138 , V_137 -> V_38 ,
V_104 ) ;
if ( V_7 )
return V_7 ;
sprintf ( V_138 , L_3 , V_137 -> V_22 ) ;
V_7 = F_53 ( V_13 , V_42 , V_138 , V_137 -> V_38 ,
V_108 ) ;
if ( V_7 )
return V_7 ;
sprintf ( V_138 , L_4 , V_137 -> V_22 ) ;
V_7 = F_53 ( V_13 , V_42 , V_138 , V_137 -> V_38 ,
V_98 ) ;
if ( V_7 )
return V_7 ;
sprintf ( V_138 , L_5 , V_137 -> V_22 ) ;
V_7 = F_53 ( V_13 , V_42 , V_138 , V_137 -> V_38 ,
V_102 ) ;
if ( V_7 )
return V_7 ;
sprintf ( V_138 , L_6 , V_137 -> V_22 ) ;
V_7 = F_53 ( V_13 , V_42 , V_138 , V_137 -> V_38 ,
V_106 ) ;
if ( V_7 )
return V_7 ;
sprintf ( V_138 , L_7 , V_137 -> V_22 ) ;
V_7 = F_53 ( V_13 , V_42 , V_138 , V_137 -> V_38 ,
V_96 ) ;
if ( V_7 )
return V_7 ;
sprintf ( V_138 , L_8 , V_137 -> V_22 ) ;
V_7 = F_53 ( V_13 , V_42 , V_138 , V_137 -> V_38 ,
V_115 ) ;
if ( V_7 )
return V_7 ;
sprintf ( V_138 , L_9 , V_137 -> V_22 ) ;
V_7 = F_53 ( V_13 , V_42 , V_138 , V_137 -> V_38 ,
V_117 ) ;
if ( V_7 )
return V_7 ;
sprintf ( V_138 , L_10 , V_137 -> V_22 ) ;
V_7 = F_53 ( V_13 , V_42 , V_138 , V_137 -> V_38 ,
V_113 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static int F_58 ( struct V_18 * V_13 , struct V_136 * V_137 , int V_139 , int V_140 )
{
struct V_42 V_42 ;
struct V_42 * V_32 ;
struct V_76 * V_85 ;
struct V_31 * V_133 ;
char V_138 [ 64 ] ;
if ( V_13 -> V_34 [ V_137 -> V_141 ] . V_46 && ! V_140 )
return 0 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
memset ( V_42 . V_80 , 0xff , sizeof( V_42 . V_80 ) ) ;
if ( F_57 ( V_13 , V_137 , & V_42 ) )
return 0 ;
F_38 ( & V_13 -> V_4 -> V_87 ) ;
if ( V_137 -> V_38 == 0 && ( V_85 = F_35 ( V_13 , L_1 , 0 ) ) != NULL ) {
struct V_81 * V_82 ;
V_82 = F_7 ( sizeof( * V_82 ) , V_11 ) ;
if ( ! V_82 ) {
F_40 ( & V_13 -> V_4 -> V_87 ) ;
return - V_12 ;
}
if ( V_85 -> V_19 ( V_85 , V_82 ) ) {
F_40 ( & V_13 -> V_4 -> V_87 ) ;
F_10 ( V_82 ) ;
return 0 ;
}
strcpy ( V_138 , V_137 -> V_22 ) ;
if ( ! strcmp ( V_138 , L_11 ) )
strcpy ( V_138 , L_12 ) ;
if ( ! strcmp ( V_138 , L_13 ) )
strcpy ( V_138 , L_14 ) ;
V_42 . V_126 = 0 ;
if ( ! strcmp ( V_82 -> V_91 . V_127 . V_22 , V_138 ) ) {
V_42 . V_94 |= V_125 ;
} else {
for ( V_42 . V_126 = 1 ; V_42 . V_126 < V_82 -> V_91 . V_127 . V_142 ; V_42 . V_126 ++ ) {
V_82 -> V_91 . V_127 . V_128 = V_42 . V_126 ;
if ( V_85 -> V_19 ( V_85 , V_82 ) ) {
F_40 ( & V_13 -> V_4 -> V_87 ) ;
F_10 ( V_82 ) ;
return 0 ;
}
if ( ! strcmp ( V_82 -> V_91 . V_127 . V_22 , V_138 ) ) {
V_42 . V_94 |= V_125 ;
break;
}
}
}
F_10 ( V_82 ) ;
}
F_40 ( & V_13 -> V_4 -> V_87 ) ;
if ( V_42 . V_94 != 0 ) {
V_32 = F_54 ( sizeof( V_42 ) , V_11 ) ;
if ( ! V_32 )
return - V_12 ;
* V_32 = V_42 ;
V_32 -> V_123 = V_124 ;
V_32 -> V_132 = V_137 ;
V_32 -> V_131 = V_139 ;
V_133 = & V_13 -> V_34 [ V_137 -> V_141 ] ;
F_56 ( V_133 ) ;
V_133 -> V_36 = V_42 . V_130 > 1 ? 1 : 0 ;
V_133 -> V_46 = F_42 ;
V_133 -> V_35 = F_46 ;
if ( V_42 . V_94 & V_114 ) {
V_133 -> V_28 = F_47 ;
V_133 -> V_29 = F_49 ;
} else if ( V_42 . V_94 & V_116 ) {
V_133 -> V_28 = F_48 ;
V_133 -> V_29 = F_50 ;
} else if ( V_42 . V_94 & V_125 ) {
V_13 -> V_37 |= 1 << V_137 -> V_141 ;
}
V_133 -> V_14 = V_32 ;
V_133 -> V_135 = F_55 ;
return 1 ;
}
return 0 ;
}
static void F_59 ( struct V_143 * V_144 ,
struct V_145 * V_146 )
{
struct V_18 * V_13 = V_144 -> V_14 ;
int V_147 ;
F_60 ( & V_13 -> V_148 ) ;
for ( V_147 = 0 ; V_147 < V_149 ; V_147 ++ ) {
struct V_42 * V_50 ;
if ( ! V_150 [ V_147 ] )
continue;
V_50 = (struct V_42 * ) V_13 -> V_34 [ V_147 ] . V_14 ;
F_61 ( V_146 , L_15 , V_150 [ V_147 ] ) ;
if ( V_50 && V_50 -> V_132 )
F_61 ( V_146 , L_16 ,
V_50 -> V_132 -> V_22 ,
V_50 -> V_132 -> V_38 ) ;
else
F_61 ( V_146 , L_17 ) ;
}
F_62 ( & V_13 -> V_148 ) ;
}
static void F_63 ( struct V_143 * V_144 ,
struct V_145 * V_146 )
{
struct V_18 * V_13 = V_144 -> V_14 ;
char line [ 128 ] , V_138 [ 32 ] , V_151 [ 16 ] ;
const char * V_152 ;
int V_153 , V_119 ;
struct V_136 * V_154 ;
struct V_42 * V_42 ;
while ( ! F_64 ( V_146 , line , sizeof( line ) ) ) {
V_152 = F_65 ( V_138 , line , sizeof( V_138 ) ) ;
for ( V_153 = 0 ; V_153 < V_149 ; V_153 ++ )
if ( V_150 [ V_153 ] && strcmp ( V_150 [ V_153 ] , V_138 ) == 0 )
break;
if ( V_153 >= V_149 ) {
F_66 ( L_18 ,
V_138 ) ;
continue;
}
V_152 = F_65 ( V_138 , V_152 , sizeof( V_138 ) ) ;
if ( ! * V_138 ) {
F_60 ( & V_13 -> V_148 ) ;
F_56 ( & V_13 -> V_34 [ V_153 ] ) ;
F_62 ( & V_13 -> V_148 ) ;
continue;
}
F_65 ( V_151 , V_152 , sizeof( V_151 ) ) ;
V_119 = F_67 ( V_151 , NULL , 10 ) ;
if ( V_119 >= 0x4000 ) {
F_66 ( L_19 , V_119 ) ;
continue;
}
F_60 ( & V_13 -> V_148 ) ;
V_42 = (struct V_42 * ) V_13 -> V_34 [ V_153 ] . V_14 ;
if ( V_42 && V_42 -> V_132 &&
V_42 -> V_132 -> V_38 == V_119 && ! strcmp ( V_42 -> V_132 -> V_22 , V_138 ) )
goto V_122;
V_154 = F_54 ( sizeof( * V_154 ) , V_11 ) ;
if ( ! V_154 )
goto V_122;
V_154 -> V_141 = V_153 ;
V_154 -> V_22 = F_68 ( V_138 , V_11 ) ;
if ( ! V_154 -> V_22 ) {
F_10 ( V_154 ) ;
goto V_122;
}
V_154 -> V_38 = V_119 ;
if ( F_58 ( V_13 , V_154 , 1 , 1 ) <= 0 ) {
F_10 ( V_154 -> V_22 ) ;
F_10 ( V_154 ) ;
}
V_122:
F_62 ( & V_13 -> V_148 ) ;
}
}
static void F_69 ( struct V_18 * V_13 )
{
struct V_143 * V_144 ;
V_144 = F_70 ( V_13 -> V_4 , L_20 ,
V_13 -> V_4 -> V_155 ) ;
if ( ! V_144 )
return;
V_144 -> V_156 = V_157 ;
V_144 -> V_158 = V_159 | V_160 | V_161 ;
V_144 -> V_162 . V_163 . V_164 = F_59 ;
V_144 -> V_162 . V_163 . V_165 = F_63 ;
V_144 -> V_14 = V_13 ;
if ( F_71 ( V_144 ) < 0 ) {
F_72 ( V_144 ) ;
V_144 = NULL ;
}
V_13 -> V_166 = V_144 ;
}
static void F_73 ( struct V_18 * V_13 )
{
F_72 ( V_13 -> V_166 ) ;
V_13 -> V_166 = NULL ;
}
static void F_74 ( struct V_18 * V_13 )
{
static struct V_136 V_167 [] = {
{ V_168 , L_11 , 0 } ,
{ V_168 , L_21 , 0 } ,
{ V_169 , L_22 , 0 } ,
{ V_170 , L_23 , 0 } ,
{ V_171 , L_24 , 0 } ,
{ V_171 , L_25 , 0 } ,
{ V_171 , L_26 , 0 } ,
{ V_172 , L_27 , 0 } ,
{ V_173 , L_28 , 0 } ,
{ V_173 , L_29 , 0 } ,
{ V_173 , L_30 , 0 } ,
{ V_174 , L_31 , 0 } ,
{ V_175 , L_32 , 0 } ,
{ V_176 , L_33 , 0 } ,
{ V_177 , L_34 , 0 } ,
{ V_178 , L_27 , 1 } ,
{ V_178 , L_35 , 0 } ,
{ V_178 , L_36 , 0 } ,
{ V_179 , L_37 , 0 } ,
{ V_180 , L_38 , 0 } ,
{ V_181 , L_39 , 0 } ,
{ V_182 , L_40 , 0 } ,
{ V_183 , L_40 , 1 } ,
{ V_184 , L_40 , 2 } ,
{ V_185 , L_41 , 0 } ,
{ V_185 , L_42 , 0 } ,
{ V_185 , L_43 , 0 } ,
{ V_185 , L_44 , 0 } ,
{ V_186 , L_41 , 1 } ,
{ V_187 , L_41 , 2 } ,
{ V_188 , L_45 , 0 } ,
{ V_189 , L_13 , 0 } ,
{ V_189 , L_30 , 0 } ,
{ V_189 , L_46 , 0 } ,
{ V_189 , L_45 , 0 } ,
{ V_190 , L_47 , 0 } ,
{ V_191 , L_48 , 0 } ,
{ V_192 , L_49 , 0 }
} ;
unsigned int V_119 ;
for ( V_119 = 0 ; V_119 < F_75 ( V_167 ) ; V_119 ++ )
F_58 ( V_13 , & V_167 [ V_119 ] , 0 , 0 ) ;
if ( V_13 -> V_37 ) {
V_13 -> V_28 = F_51 ;
V_13 -> V_29 = F_52 ;
}
}
static int F_76 ( void * V_193 )
{
struct V_18 * V_13 = V_193 ;
struct V_3 * V_4 ;
int V_119 ;
if ( ! V_13 )
return 0 ;
V_4 = V_13 -> V_4 ;
if ( F_25 ( V_13 != V_4 -> V_10 ) )
return - V_52 ;
V_4 -> V_10 = NULL ;
for ( V_119 = 0 ; V_119 < V_149 ; V_119 ++ ) {
struct V_31 * V_33 = & V_13 -> V_34 [ V_119 ] ;
if ( V_33 -> V_135 )
V_33 -> V_135 ( V_33 ) ;
}
F_10 ( V_13 ) ;
return 0 ;
}
static int F_77 ( struct V_3 * V_4 , int V_47 )
{
struct V_18 * V_13 ;
if ( V_47 == V_194 ) {
int V_119 , V_7 ;
V_13 = F_78 ( 2 , sizeof( * V_13 ) , V_11 ) ;
if ( V_13 == NULL )
return - V_12 ;
F_79 ( & V_13 -> V_148 ) ;
if ( ( V_7 = F_80 ( V_8 ,
V_4 , 0 ,
& V_195 , V_4 ) ) < 0 ) {
F_81 ( V_4 -> V_196 ,
L_50 ,
V_4 -> V_134 , 0 ) ;
F_10 ( V_13 ) ;
return V_7 ;
}
V_13 -> V_197 = 1 ;
V_13 -> V_4 = V_4 ;
if ( * V_4 -> V_23 )
F_14 ( V_13 -> V_22 , V_4 -> V_23 , sizeof( V_13 -> V_22 ) ) ;
else
snprintf ( V_13 -> V_22 , sizeof( V_13 -> V_22 ) ,
L_51 , V_4 -> V_134 ) ;
#ifdef F_82
F_83 ( F_82 ,
V_4 -> V_134 ,
V_13 -> V_22 ) ;
#endif
for ( V_119 = 0 ; V_119 < V_149 ; V_119 ++ )
V_13 -> V_34 [ V_119 ] . V_134 = V_119 ;
V_4 -> V_10 = V_13 ;
F_74 ( V_13 ) ;
F_69 ( V_13 ) ;
} else {
V_13 = V_4 -> V_10 ;
if ( V_13 == NULL )
return 0 ;
if ( V_13 -> V_197 ) {
#ifdef F_82
F_84 ( F_82 , V_13 -> V_4 -> V_134 ) ;
#endif
F_85 ( V_8 , V_13 -> V_4 , 0 ) ;
V_13 -> V_197 = 0 ;
}
if ( V_47 == V_198 )
return 0 ;
F_73 ( V_13 ) ;
return F_76 ( V_13 ) ;
}
return 0 ;
}
static int T_4 F_86 ( void )
{
int V_119 ;
V_199 = F_77 ;
for ( V_119 = 0 ; V_119 < V_200 ; V_119 ++ ) {
if ( V_201 [ V_119 ] )
F_77 ( V_201 [ V_119 ] , V_194 ) ;
}
return 0 ;
}
static void T_5 F_87 ( void )
{
int V_119 ;
V_199 = NULL ;
for ( V_119 = 0 ; V_119 < V_200 ; V_119 ++ ) {
if ( V_201 [ V_119 ] )
F_77 ( V_201 [ V_119 ] , V_202 ) ;
}
}
