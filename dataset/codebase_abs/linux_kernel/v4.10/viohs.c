int F_1 ( struct V_1 * V_2 , void * V_3 , int V_4 )
{
int V_5 , V_6 = 1000 ;
V_5 = - V_7 ;
while ( V_6 -- > 0 ) {
V_5 = F_2 ( V_2 -> V_8 , V_3 , V_4 ) ;
if ( ! V_5 || ( V_5 != - V_9 ) )
break;
F_3 ( 1 ) ;
}
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 , int V_4 )
{
V_11 -> V_12 = F_5 ( V_2 ) ;
return F_1 ( V_2 , V_11 , V_4 ) ;
}
static void F_6 ( struct V_10 * V_11 , T_1 type , T_1 V_13 , T_2 V_14 )
{
V_11 -> type = type ;
V_11 -> V_13 = V_13 ;
V_11 -> V_14 = V_14 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_15 , T_2 V_16 )
{
struct V_17 V_18 ;
V_2 -> V_19 = ( V_20 ) F_8 () ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_6 ( & V_18 . V_11 , V_21 , V_22 , V_23 ) ;
V_18 . V_15 = V_15 ;
V_18 . V_16 = V_16 ;
V_18 . V_24 = V_2 -> V_24 ;
F_9 ( V_25 , L_1 ,
V_15 , V_16 , V_2 -> V_24 ) ;
return F_4 ( V_2 , & V_18 . V_11 , sizeof( V_18 ) ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_5 ;
F_9 ( V_25 , L_2 ) ;
V_2 -> V_26 = V_27 ;
V_5 = F_7 ( V_2 ,
V_2 -> V_28 [ 0 ] . V_15 ,
V_2 -> V_28 [ 0 ] . V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
T_3 V_31 ;
F_12 ( ! ( V_2 -> V_32 & V_33 ) ) ;
V_30 = & V_2 -> V_34 [ V_35 ] ;
V_31 = V_30 -> V_31 ;
F_12 ( ! V_2 -> V_36 ) ;
F_13 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_31 = V_31 ;
}
void F_14 ( struct V_1 * V_2 , int V_37 )
{
if ( V_37 == V_38 ) {
V_2 -> V_26 = V_27 ;
switch ( V_2 -> V_24 ) {
case V_39 :
case V_40 :
V_2 -> V_32 = ( V_41 |
V_42 ) ;
break;
case V_43 :
V_2 -> V_32 = V_41 ;
break;
case V_44 :
V_2 -> V_32 = V_42 ;
break;
}
F_10 ( V_2 ) ;
} else if ( V_37 == V_45 ) {
V_2 -> V_26 = V_27 ;
if ( V_2 -> V_32 & V_33 )
F_11 ( V_2 ) ;
V_2 -> V_32 = 0x00 ;
memset ( & V_2 -> V_46 , 0 , sizeof( V_2 -> V_46 ) ) ;
F_15 ( V_2 -> V_8 ) ;
}
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
F_9 ( V_25 , L_3 ) ;
V_2 -> V_32 &= ~ ( V_47 |
V_33 ) ;
V_30 = & V_2 -> V_34 [ V_35 ] ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
F_13 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
V_2 -> V_48 = 0 ;
V_2 -> V_26 = V_27 ;
return - V_49 ;
}
static int F_17 ( struct V_1 * V_2 , void * V_50 )
{
struct V_10 * V_18 = V_50 ;
F_9 ( V_25 , L_4 ,
V_18 -> type , V_18 -> V_13 , V_18 -> V_14 , V_18 -> V_12 ) ;
F_18 ( V_51 L_5 ,
V_2 -> V_52 -> V_53 ) ;
F_15 ( V_2 -> V_8 ) ;
return - V_49 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = & V_2 -> V_34 [ V_54 ] ;
union {
struct V_55 V_18 ;
char V_56 [ sizeof( struct V_55 ) +
( sizeof( struct V_57 ) *
V_30 -> V_58 ) ] ;
} V_59 ;
int V_60 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
F_6 ( & V_59 . V_18 . V_11 , V_21 , V_22 , V_61 ) ;
V_59 . V_18 . V_62 = 0 ;
V_59 . V_18 . V_63 = V_30 -> V_64 ;
V_59 . V_18 . V_65 = V_30 -> V_66 ;
V_59 . V_18 . V_67 = V_68 ;
V_59 . V_18 . V_69 = V_30 -> V_58 ;
F_9 ( V_25 , L_6
L_7 ,
V_59 . V_18 . V_63 , V_59 . V_18 . V_65 , V_59 . V_18 . V_67 ,
V_59 . V_18 . V_69 ) ;
for ( V_60 = 0 ; V_60 < V_30 -> V_58 ; V_60 ++ ) {
V_59 . V_18 . V_70 [ V_60 ] = V_30 -> V_70 [ V_60 ] ;
F_9 ( V_25 , L_8 ,
V_60 ,
( unsigned long long ) V_59 . V_18 . V_70 [ V_60 ] . V_71 ,
( unsigned long long ) V_59 . V_18 . V_70 [ V_60 ] . V_72 ) ;
}
return F_4 ( V_2 , & V_59 . V_18 . V_11 , sizeof( V_59 ) ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_73 V_18 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_6 ( & V_18 . V_11 , V_21 , V_22 , V_74 ) ;
F_9 ( V_25 , L_9 ) ;
return F_4 ( V_2 , & V_18 . V_11 , sizeof( V_18 ) ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
return V_2 -> V_75 -> F_21 ( V_2 ) ;
}
static struct V_76 * F_22 ( struct V_1 * V_2 ,
T_2 V_15 )
{
struct V_76 * V_77 = NULL ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_78 ; V_60 ++ ) {
struct V_76 * V_79 = & V_2 -> V_28 [ V_60 ] ;
if ( V_79 -> V_15 <= V_15 ) {
V_77 = V_79 ;
break;
}
}
return V_77 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_76 * V_80 ;
int V_5 ;
F_9 ( V_25 , L_10 ,
V_18 -> V_15 , V_18 -> V_16 , V_18 -> V_24 ) ;
if ( V_2 -> V_26 != V_27 ) {
memset ( & V_2 -> V_46 , 0 , sizeof( V_2 -> V_46 ) ) ;
V_2 -> V_26 = V_27 ;
}
V_80 = F_22 ( V_2 , V_18 -> V_15 ) ;
V_2 -> V_81 = V_18 -> V_11 . V_12 ;
if ( ! V_80 ) {
V_18 -> V_11 . V_13 = V_82 ;
V_18 -> V_15 = 0 ;
V_18 -> V_16 = 0 ;
F_9 ( V_25 , L_11 ) ;
V_5 = F_4 ( V_2 , & V_18 -> V_11 , sizeof( * V_18 ) ) ;
} else if ( V_80 -> V_15 != V_18 -> V_15 ) {
V_18 -> V_11 . V_13 = V_82 ;
V_18 -> V_15 = V_80 -> V_15 ;
V_18 -> V_16 = V_80 -> V_16 ;
F_9 ( V_25 , L_12 ,
V_18 -> V_15 , V_18 -> V_16 ) ;
V_5 = F_4 ( V_2 , & V_18 -> V_11 , sizeof( * V_18 ) ) ;
} else {
struct V_76 V_46 = {
. V_15 = V_18 -> V_15 ,
. V_16 = V_18 -> V_16 ,
} ;
if ( V_46 . V_16 > V_80 -> V_16 )
V_46 . V_16 = V_80 -> V_16 ;
V_18 -> V_16 = V_46 . V_16 ;
V_18 -> V_11 . V_13 = V_83 ;
F_9 ( V_25 , L_13 ,
V_18 -> V_15 , V_18 -> V_16 ) ;
V_5 = F_4 ( V_2 , & V_18 -> V_11 , sizeof( * V_18 ) ) ;
if ( V_5 > 0 ) {
V_2 -> V_46 = V_46 ;
V_2 -> V_26 = V_84 ;
}
}
if ( V_5 < 0 )
return F_16 ( V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
F_9 ( V_25 , L_14 ,
V_18 -> V_15 , V_18 -> V_16 , V_18 -> V_24 ) ;
if ( V_2 -> V_26 & V_84 ) {
if ( V_2 -> V_46 . V_15 != V_18 -> V_15 ||
V_2 -> V_46 . V_16 != V_18 -> V_16 ) {
V_18 -> V_11 . V_13 = V_82 ;
( void ) F_4 ( V_2 , & V_18 -> V_11 , sizeof( * V_18 ) ) ;
return F_16 ( V_2 ) ;
}
} else {
V_2 -> V_46 . V_15 = V_18 -> V_15 ;
V_2 -> V_46 . V_16 = V_18 -> V_16 ;
V_2 -> V_26 = V_84 ;
}
switch ( V_2 -> V_24 ) {
case V_39 :
case V_43 :
if ( F_21 ( V_2 ) < 0 )
return F_16 ( V_2 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_76 * V_85 ;
F_9 ( V_25 , L_15 ,
V_18 -> V_15 , V_18 -> V_16 , V_18 -> V_24 ) ;
if ( V_18 -> V_15 == 0 && V_18 -> V_16 == 0 )
return F_16 ( V_2 ) ;
V_85 = F_22 ( V_2 , V_18 -> V_15 ) ;
if ( ! V_85 )
return F_16 ( V_2 ) ;
if ( F_7 ( V_2 , V_85 -> V_15 , V_85 -> V_16 ) < 0 )
return F_16 ( V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
switch ( V_18 -> V_11 . V_13 ) {
case V_22 :
return F_23 ( V_2 , V_18 ) ;
case V_83 :
return F_24 ( V_2 , V_18 ) ;
case V_82 :
return F_25 ( V_2 , V_18 ) ;
default:
return F_16 ( V_2 ) ;
}
}
static int F_27 ( struct V_1 * V_2 , void * V_18 )
{
int V_5 ;
if ( ! ( V_2 -> V_26 & V_84 ) )
return F_16 ( V_2 ) ;
V_5 = V_2 -> V_75 -> V_86 ( V_2 , V_18 ) ;
if ( V_5 < 0 ) {
return F_16 ( V_2 ) ;
} else {
V_2 -> V_26 |= V_87 ;
if ( ( V_2 -> V_32 & V_41 ) &&
! ( V_2 -> V_26 & V_88 ) ) {
if ( F_19 ( V_2 ) < 0 )
return F_16 ( V_2 ) ;
V_2 -> V_26 |= V_88 ;
}
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_89 , V_90 ;
V_89 = ( V_2 -> V_32 & V_42 ) ;
V_90 = ( V_2 -> V_32 & V_41 ) ;
if ( V_89 &&
! ( V_2 -> V_32 & V_33 ) )
return 0 ;
if ( V_90 &&
! ( V_2 -> V_32 & V_47 ) )
return 0 ;
return 1 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_55 * V_18 )
{
struct V_29 * V_30 ;
int V_60 , V_4 ;
F_9 ( V_25 , L_16
L_17 ,
( unsigned long long ) V_18 -> V_62 ,
V_18 -> V_63 , V_18 -> V_65 , V_18 -> V_67 ,
V_18 -> V_69 ) ;
if ( ! ( V_2 -> V_32 & V_42 ) )
goto V_91;
if ( V_2 -> V_32 & V_33 )
goto V_91;
if ( F_30 ( V_2 , 1 , 6 ) ) {
if ( ! ( V_18 -> V_67 & V_68 ) )
goto V_91;
V_18 -> V_67 = V_68 ;
}
F_12 ( V_2 -> V_36 ) ;
V_2 -> V_36 = F_31 ( V_18 -> V_65 , V_92 ) ;
if ( ! V_2 -> V_36 )
goto V_91;
V_2 -> V_48 = V_18 -> V_65 ;
V_30 = & V_2 -> V_34 [ V_35 ] ;
V_30 -> V_64 = V_18 -> V_63 ;
V_30 -> V_66 = V_18 -> V_65 ;
V_30 -> V_58 = V_18 -> V_69 ;
for ( V_60 = 0 ; V_60 < V_30 -> V_58 ; V_60 ++ ) {
V_30 -> V_70 [ V_60 ] = V_18 -> V_70 [ V_60 ] ;
F_9 ( V_25 , L_8 ,
V_60 ,
( unsigned long long )
V_18 -> V_70 [ V_60 ] . V_71 ,
( unsigned long long )
V_18 -> V_70 [ V_60 ] . V_72 ) ;
}
V_18 -> V_11 . V_13 = V_83 ;
V_18 -> V_62 = ++ V_30 -> V_31 ;
F_9 ( V_25 , L_18
L_17 ,
( unsigned long long ) V_18 -> V_62 ,
V_18 -> V_63 , V_18 -> V_65 , V_18 -> V_67 ,
V_18 -> V_69 ) ;
V_4 = ( sizeof( * V_18 ) +
( V_30 -> V_58 * sizeof( struct V_57 ) ) ) ;
if ( F_4 ( V_2 , & V_18 -> V_11 , V_4 ) < 0 )
goto V_91;
V_2 -> V_32 |= V_33 ;
return 0 ;
V_91:
V_18 -> V_11 . V_13 = V_82 ;
F_9 ( V_25 , L_19 ) ;
( void ) F_4 ( V_2 , & V_18 -> V_11 , sizeof( * V_18 ) ) ;
return F_16 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_55 * V_18 )
{
struct V_29 * V_30 ;
F_9 ( V_25 , L_20
L_17 ,
( unsigned long long ) V_18 -> V_62 ,
V_18 -> V_63 , V_18 -> V_65 , V_18 -> V_67 ,
V_18 -> V_69 ) ;
V_30 = & V_2 -> V_34 [ V_54 ] ;
if ( ! ( V_2 -> V_32 & V_41 ) )
return F_16 ( V_2 ) ;
V_30 -> V_31 = V_18 -> V_62 ;
V_2 -> V_32 |= V_47 ;
if ( F_28 ( V_2 ) ) {
if ( F_20 ( V_2 ) < 0 )
return F_16 ( V_2 ) ;
V_2 -> V_26 = V_93 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_55 * V_18 )
{
F_9 ( V_25 , L_21
L_17 ,
( unsigned long long ) V_18 -> V_62 ,
V_18 -> V_63 , V_18 -> V_65 , V_18 -> V_67 ,
V_18 -> V_69 ) ;
return F_16 ( V_2 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_55 * V_18 )
{
if ( ! ( V_2 -> V_26 & V_84 ) )
return F_16 ( V_2 ) ;
switch ( V_18 -> V_11 . V_13 ) {
case V_22 :
return F_29 ( V_2 , V_18 ) ;
case V_83 :
return F_32 ( V_2 , V_18 ) ;
case V_82 :
return F_33 ( V_2 , V_18 ) ;
default:
return F_16 ( V_2 ) ;
}
}
static int F_35 ( struct V_1 * V_2 ,
struct V_94 * V_18 )
{
struct V_29 * V_30 = & V_2 -> V_34 [ V_35 ] ;
F_9 ( V_25 , L_22 ) ;
if ( V_18 -> V_62 != V_30 -> V_31 )
return 0 ;
V_2 -> V_32 &= ~ V_33 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
F_13 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
V_2 -> V_48 = 0 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_73 * V_18 )
{
F_9 ( V_25 , L_23 ) ;
V_18 -> V_11 . V_13 = V_83 ;
F_9 ( V_25 , L_24 ) ;
if ( F_4 ( V_2 , & V_18 -> V_11 , sizeof( * V_18 ) ) < 0 )
return F_16 ( V_2 ) ;
V_2 -> V_26 |= V_95 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_73 * V_18 )
{
F_9 ( V_25 , L_25 ) ;
if ( ! ( V_2 -> V_26 & V_93 ) )
return F_16 ( V_2 ) ;
V_2 -> V_26 |= V_96 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_73 * V_18 )
{
F_9 ( V_25 , L_26 ) ;
return F_16 ( V_2 ) ;
}
static int F_39 ( struct V_1 * V_2 , struct V_73 * V_18 )
{
if ( ! F_28 ( V_2 ) )
F_16 ( V_2 ) ;
switch ( V_18 -> V_11 . V_13 ) {
case V_22 :
return F_36 ( V_2 , V_18 ) ;
case V_83 :
return F_37 ( V_2 , V_18 ) ;
case V_82 :
return F_38 ( V_2 , V_18 ) ;
default:
return F_16 ( V_2 ) ;
}
}
int F_40 ( struct V_1 * V_2 , void * V_18 )
{
struct V_10 * V_11 = V_18 ;
T_1 V_97 = V_2 -> V_26 ;
int V_5 ;
switch ( V_11 -> V_14 ) {
case V_23 :
V_5 = F_26 ( V_2 , V_18 ) ;
break;
case V_98 :
V_5 = F_27 ( V_2 , V_18 ) ;
break;
case V_61 :
V_5 = F_34 ( V_2 , V_18 ) ;
break;
case V_99 :
V_5 = F_35 ( V_2 , V_18 ) ;
break;
case V_74 :
V_5 = F_39 ( V_2 , V_18 ) ;
break;
default:
V_5 = F_17 ( V_2 , V_18 ) ;
break;
}
if ( ! V_5 &&
V_2 -> V_26 != V_97 &&
( V_2 -> V_26 & V_100 ) )
V_2 -> V_75 -> V_101 ( V_2 ) ;
return V_5 ;
}
void F_41 ( struct V_1 * V_2 )
{
}
int F_42 ( struct V_1 * V_2 , struct V_10 * V_102 )
{
V_20 V_12 ;
if ( V_102 -> type == V_21 &&
V_102 -> V_13 == V_22 &&
V_102 -> V_14 == V_23 )
return 0 ;
switch ( V_2 -> V_24 ) {
case V_39 :
case V_40 :
case V_44 :
default:
V_12 = V_2 -> V_81 ;
break;
case V_43 :
V_12 = V_2 -> V_19 ;
break;
}
if ( V_12 == V_102 -> V_12 )
return 0 ;
F_9 ( V_103 , L_27 ,
V_102 -> V_12 , V_2 -> V_81 , V_2 -> V_19 ) ;
return - V_7 ;
}
V_20 F_5 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_24 ) {
case V_39 :
case V_40 :
case V_43 :
default:
return V_2 -> V_19 ;
case V_44 :
return V_2 -> V_81 ;
}
}
int F_43 ( struct V_1 * V_2 ,
struct V_104 * V_105 ,
void * V_106 )
{
struct V_104 V_107 = * V_105 ;
struct V_108 * V_8 ;
V_107 . V_109 = V_2 -> V_52 -> V_109 ;
V_107 . V_110 = V_2 -> V_52 -> V_110 ;
V_8 = F_44 ( V_2 -> V_52 -> V_53 , & V_107 , V_106 , V_2 -> V_111 ) ;
if ( F_45 ( V_8 ) )
return F_46 ( V_8 ) ;
V_2 -> V_8 = V_8 ;
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
F_48 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
F_13 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
V_2 -> V_48 = 0 ;
}
void F_49 ( struct V_1 * V_2 )
{
unsigned long V_112 ;
int V_5 , V_113 ;
F_50 ( & V_2 -> V_114 , V_112 ) ;
V_113 = F_51 ( V_2 -> V_8 ) ;
V_5 = 0 ;
if ( V_113 == V_115 ) {
V_5 = F_52 ( V_2 -> V_8 ) ;
if ( V_5 )
F_18 ( V_116 L_28
L_29 ,
V_2 -> V_111 , V_2 -> V_52 -> V_53 , V_5 ) ;
}
if ( ! V_5 ) {
V_5 = F_53 ( V_2 -> V_8 ) ;
if ( V_5 )
F_18 ( V_116 L_30
L_29 ,
V_2 -> V_111 , V_2 -> V_52 -> V_53 , V_5 ) ;
}
if ( V_5 ) {
unsigned long V_117 = V_118 + V_119 ;
V_117 = F_54 ( V_117 ) ;
F_55 ( & V_2 -> V_120 , V_117 ) ;
}
F_56 ( & V_2 -> V_114 , V_112 ) ;
}
static void F_57 ( unsigned long V_121 )
{
struct V_1 * V_2 = (struct V_1 * ) V_121 ;
F_49 ( V_2 ) ;
}
int F_58 ( struct V_1 * V_2 , struct V_122 * V_52 ,
T_1 V_24 , struct V_76 * V_28 ,
int V_123 , struct V_124 * V_75 ,
char * V_111 )
{
switch ( V_24 ) {
case V_39 :
case V_40 :
case V_43 :
case V_44 :
break;
default:
return - V_7 ;
}
if ( ! V_75 -> F_21 ||
! V_75 -> V_86 ||
! V_75 -> V_101 )
return - V_7 ;
if ( ! V_28 || V_123 < 0 )
return - V_7 ;
if ( ! V_111 )
return - V_7 ;
F_59 ( & V_2 -> V_114 ) ;
V_2 -> V_111 = V_111 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_52 = V_52 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_78 = V_123 ;
V_2 -> V_75 = V_75 ;
F_60 ( & V_2 -> V_120 , F_57 , ( unsigned long ) V_2 ) ;
return 0 ;
}
