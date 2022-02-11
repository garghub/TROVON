static inline unsigned F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned V_5 )
{
return ( V_4 - V_2 -> V_4 ) * V_6 + V_5 ;
}
static inline unsigned F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned V_5 ,
unsigned V_7 , T_1 V_8 )
{
if ( V_8 ) {
V_5 ++ ;
if ( ( ( V_5 & V_8 ) >> 1 ) >= V_7 )
V_5 = ( V_5 | V_8 ) + 2 ;
} else {
V_5 = F_3 ( V_4 -> V_9 , V_6 , V_5 ) ;
}
return V_5 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_10 )
{
unsigned long V_9 = F_5 ( V_10 ) ;
F_6 ( & V_2 -> V_11 ) ;
if ( V_4 -> V_9 )
F_7 ( V_9 ) ;
else
V_4 -> V_9 = ( void * ) V_9 ;
F_8 ( & V_2 -> V_11 ) ;
}
int F_9 ( struct V_12 * V_13 , struct V_1 * V_2 ,
enum V_14 type , T_3 V_15 , T_2 V_10 )
{
T_4 V_16 , V_17 , V_18 , V_19 ;
struct V_3 * V_4 ;
T_4 V_20 ;
struct V_21 * V_22 = F_10 ( V_13 , struct V_21 , V_13 ) ;
struct V_23 * V_24 = F_10 ( V_22 , struct V_23 ,
V_22 ) ;
T_1 V_8 = V_24 -> V_25 ;
if ( type == V_26 || type == V_27 ) {
unsigned V_7 ;
V_20 = type == V_27 ;
V_7 = 1 << ( V_20 + 2 * ( V_15 - 1 ) ) ;
F_6 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_28 & V_7 )
V_20 = - V_29 ;
else
V_2 -> V_28 |= V_7 ;
F_8 ( & V_2 -> V_11 ) ;
goto V_30;
}
V_19 = V_2 -> V_31 + 2 ;
if ( V_19 >= V_32 )
V_19 = 2 ;
if ( V_8 && ( ( V_19 & V_8 ) >> 1 ) >= V_24 -> V_33 )
V_19 = ( V_19 | V_8 ) + 2 ;
V_17 = V_19 & V_34 ;
V_4 = & V_2 -> V_4 [ V_19 / V_6 ] ;
V_18 = V_2 -> V_35 - ! V_17 ;
for ( V_16 = 0 ; ; ) {
if ( F_11 ( ! V_4 -> V_9 ) ) {
F_4 ( V_2 , V_4 , V_10 ) ;
if ( F_11 ( ! V_4 -> V_9 ) )
break;
}
do {
if ( ! F_12 ( V_17 , V_4 -> V_9 ) ) {
V_2 -> V_31 = V_19 ;
V_20 = V_19 ;
goto V_30;
}
V_17 = F_2 ( V_2 , V_4 , V_17 ,
V_24 -> V_33 , V_8 ) ;
V_19 = F_1 ( V_2 , V_4 , V_17 ) ;
} while ( V_17 < V_6 && V_19 < V_32 );
if ( ++ V_16 > V_18 ) {
if ( V_2 -> V_35 == V_36 )
break;
V_4 = & V_2 -> V_4 [ V_2 -> V_35 ++ ] ;
V_17 = 0 ;
} else if ( V_4 < & V_2 -> V_4 [ V_2 -> V_35 ] ) {
++ V_4 ;
V_17 = 0 ;
} else {
V_4 = & V_2 -> V_4 [ 0 ] ;
V_17 = 2 ;
}
V_19 = F_1 ( V_2 , V_4 , V_17 ) ;
}
V_20 = - V_37 ;
V_30:
return V_20 ;
}
unsigned F_13 ( struct V_12 * V_13 )
{
struct V_21 * V_22 = F_10 ( V_13 , struct V_21 , V_13 ) ;
struct V_23 * V_24 = F_10 ( V_22 , struct V_23 ,
V_22 ) ;
unsigned V_7 , V_38 = 0 ;
for ( V_7 = 0 ; V_7 < V_24 -> V_39 ; V_7 ++ ) {
struct V_40 * V_41 = & V_24 -> V_42 [ V_7 ] . V_43 ;
F_14 () ;
if ( F_15 ( V_41 -> V_44 . V_45 [ 0 ] ) )
V_38 ++ ;
if ( F_15 ( V_41 -> V_44 . V_45 [ 1 ] ) )
V_38 ++ ;
F_16 () ;
}
return V_38 ;
}
void F_17 ( struct V_46 * V_45 )
{
struct V_47 * V_48 = V_45 -> V_48 ;
F_18 ( & V_48 -> V_49 , 0 ) ;
}
void F_19 ( struct V_46 * V_45 )
{
struct V_47 * V_48 = V_45 -> V_48 ;
struct V_21 * V_50 = F_20 ( V_45 -> V_51 . V_52 ) ;
F_6 ( & V_50 -> V_13 . V_53 ) ;
if ( ! F_21 ( & V_48 -> V_54 ) && ! ( V_45 -> V_55 & V_56 ) ) {
V_45 -> V_55 &= ~ V_57 ;
F_22 ( & V_48 -> V_54 ) ;
}
F_8 ( & V_50 -> V_13 . V_53 ) ;
if ( ! ( V_45 -> V_55 & V_56 ) ) {
V_45 -> V_58 = 0 ;
if ( V_45 -> V_59 ) {
F_23 ( V_45 -> V_59 ) ;
V_45 -> V_59 = NULL ;
}
if ( V_48 -> V_60 ) {
F_24 ( V_48 -> V_60 ) ;
V_48 -> V_60 = NULL ;
}
}
}
static int F_25 ( T_4 V_61 )
{
int V_62 ;
switch ( V_61 ) {
case 4096 :
V_62 = V_63 ;
break;
case 2048 :
V_62 = V_64 ;
break;
case 1024 :
V_62 = V_65 ;
break;
case 512 :
V_62 = V_66 ;
break;
case 256 :
V_62 = V_67 ;
break;
default:
V_62 = V_64 ;
}
return V_62 ;
}
int F_26 ( struct V_12 * V_13 , struct V_46 * V_45 ,
struct V_68 * V_69 )
{
int V_61 , V_70 , V_71 = V_45 -> V_72 - 1 ;
struct V_21 * V_22 = F_10 ( V_13 , struct V_21 , V_13 ) ;
struct V_23 * V_24 = F_10 ( V_22 , struct V_23 ,
V_22 ) ;
V_61 = F_27 ( V_69 -> V_73 ) ;
if ( V_61 == - 1 )
return - V_29 ;
if ( V_61 > V_24 -> V_42 [ V_71 ] . V_74 )
V_70 = F_25 ( V_24 -> V_42 [ V_71 ] . V_74 ) ;
else
V_70 = V_69 -> V_73 ;
return V_70 ;
}
int F_28 ( T_4 V_61 )
{
return F_25 ( V_61 ) ;
}
T_4 F_29 ( struct V_12 * V_13 , struct V_46 * V_45 , T_4 V_70 )
{
return F_27 ( V_70 ) ;
}
void * F_30 ( struct V_12 * V_13 , struct V_46 * V_45 , T_2 V_10 )
{
struct V_47 * V_48 ;
V_48 = F_31 ( sizeof( * V_48 ) , V_10 ) ;
if ( ! V_48 )
return F_32 ( - V_37 ) ;
V_48 -> V_75 = V_45 ;
V_48 -> V_76 = F_31 ( sizeof( * V_48 -> V_76 ) , V_10 ) ;
if ( ! V_48 -> V_76 ) {
F_33 ( V_48 ) ;
return F_32 ( - V_37 ) ;
}
F_34 ( & V_48 -> V_77 ) ;
F_35 ( & V_48 -> V_78 , V_79 ) ;
F_36 ( & V_48 -> V_54 ) ;
return V_48 ;
}
void F_37 ( struct V_12 * V_13 , struct V_46 * V_45 )
{
struct V_47 * V_48 = V_45 -> V_48 ;
F_33 ( V_48 -> V_76 ) ;
F_33 ( V_48 ) ;
}
void F_38 ( struct V_46 * V_45 )
{
struct V_47 * V_48 = V_45 -> V_48 ;
F_39 ( & V_48 -> V_78 ) ;
}
void F_40 ( struct V_46 * V_45 )
{
struct V_47 * V_48 = V_45 -> V_48 ;
F_41 ( V_48 -> V_77 , ! F_42 ( & V_48 -> V_49 ) ) ;
if ( V_48 -> V_60 ) {
F_24 ( V_48 -> V_60 ) ;
V_48 -> V_60 = NULL ;
}
}
void F_43 ( struct V_46 * V_45 )
{
struct V_47 * V_48 = V_45 -> V_48 ;
struct V_21 * V_50 = F_20 ( V_45 -> V_51 . V_52 ) ;
F_6 ( & V_50 -> V_13 . V_53 ) ;
if ( ! F_21 ( & V_48 -> V_54 ) )
F_22 ( & V_48 -> V_54 ) ;
F_8 ( & V_50 -> V_13 . V_53 ) ;
}
int F_44 ( struct V_46 * V_45 ,
struct V_80 * V_81 )
{
struct V_82 * V_83 ;
int V_20 = 0 ;
switch ( V_45 -> V_51 . V_84 ) {
case V_85 :
case V_86 :
if ( V_81 -> V_87 > 0x80000000U )
return - V_29 ;
break;
case V_26 :
case V_27 :
case V_88 :
V_83 = F_45 ( V_81 -> V_89 . V_83 ) ;
if ( V_81 -> V_87 > ( 1 << V_83 -> V_90 ) )
return - V_29 ;
V_20 = 1 ;
break;
default:
break;
}
return V_20 ;
}
struct V_91 * F_46 ( struct V_21 * V_50 )
{
struct V_91 * V_92 ;
V_92 = F_31 ( sizeof( * V_92 ) , V_93 ) ;
if ( ! V_92 )
return NULL ;
V_92 -> V_50 = V_50 ;
return V_92 ;
}
int F_47 ( struct V_91 * V_92 )
{
struct V_21 * V_50 = V_92 -> V_50 ;
int V_7 = V_92 -> V_7 ;
int V_20 = 1 ;
struct V_46 * V_94 = V_92 -> V_45 ;
struct V_46 * V_45 ;
for (; V_7 < V_50 -> V_13 . V_95 -> V_96 ; V_7 ++ ) {
if ( V_94 )
V_45 = F_15 ( V_94 -> V_97 ) ;
else
V_45 = F_15 ( V_50 -> V_13 . V_95 -> V_98 [ V_7 ] ) ;
V_94 = V_45 ;
if ( V_45 ) {
V_92 -> V_45 = V_45 ;
V_92 -> V_7 = V_7 ;
return 0 ;
}
}
return V_20 ;
}
void F_48 ( struct V_99 * V_100 , struct V_91 * V_92 )
{
struct V_80 * V_81 ;
struct V_46 * V_45 = V_92 -> V_45 ;
struct V_47 * V_48 = V_45 -> V_48 ;
V_81 = F_49 ( V_45 , V_45 -> V_101 ) ;
F_50 ( V_100 ,
L_1 ,
V_92 -> V_7 ,
V_45 -> V_51 . V_102 ,
V_103 [ V_45 -> V_51 . V_84 ] ,
V_45 -> V_104 ,
V_81 -> V_105 . V_106 ,
V_45 -> V_58 ,
V_45 -> V_55 ,
F_42 ( & V_48 -> V_49 ) ,
! F_21 ( & V_48 -> V_54 ) ,
V_45 -> V_107 ,
V_81 -> V_108 ,
V_45 -> V_109 ,
V_45 -> V_110 ,
V_45 -> V_111 , V_45 -> V_112 ,
V_45 -> V_113 , V_45 -> V_114 ,
V_45 -> V_101 , V_45 -> V_115 , V_45 -> V_116 ,
V_45 -> V_117 , V_45 -> V_118 , V_45 -> V_119 ,
V_45 -> V_120 ,
F_51 ( & V_45 -> V_121 ) ) ;
}
