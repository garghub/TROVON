static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ )
if ( V_2 -> V_5 [ V_3 ] . V_6 )
F_2 ( V_2 -> V_5 [ V_3 ] . V_6 ) ;
F_3 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_3 ;
if ( ! V_2 -> V_4 )
return 0 ;
V_2 -> V_5 = F_5 ( V_2 -> V_4 * sizeof( * V_2 -> V_5 ) ,
V_9 ) ;
if ( ! V_2 -> V_5 )
goto V_10;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_8 = V_2 -> V_7 + V_3 ;
F_6 ( F_7 ( V_8 ) != V_11 ) ;
V_2 -> V_5 [ V_3 ] . V_12 = V_8 -> V_13 ;
V_2 -> V_5 [ V_3 ] . V_14 = F_8 ( V_8 ) ;
V_2 -> V_5 [ V_3 ] . V_6 = F_9 ( V_8 -> V_13 ,
F_8 ( V_8 ) ) ;
if ( ! V_2 -> V_5 [ V_3 ] . V_6 )
goto V_15;
}
return 0 ;
V_15:
F_1 ( V_2 ) ;
V_10:
return - 1 ;
}
static void T_1 * F_10 ( struct V_1 * V_2 ,
unsigned long V_16 )
{
struct V_17 * V_5 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_5 = V_2 -> V_5 + V_3 ;
if ( V_16 < V_5 -> V_12 )
continue;
if ( V_16 >= ( V_5 -> V_12 + V_5 -> V_14 ) )
continue;
return V_5 -> V_6 + ( V_16 - V_5 -> V_12 ) ;
}
return ( void T_1 * ) V_16 ;
}
static int F_11 ( T_2 V_18 , struct V_19 * V_20 )
{
if ( V_18 < V_20 -> V_21 )
return 0 ;
if ( V_18 > V_20 -> V_22 )
return 0 ;
return 1 ;
}
static unsigned long F_12 ( void T_1 * V_23 ,
unsigned long V_24 )
{
switch ( V_24 ) {
case 8 :
return F_13 ( V_23 ) ;
case 16 :
return F_14 ( V_23 ) ;
case 32 :
return F_15 ( V_23 ) ;
}
F_16 () ;
return 0 ;
}
static void F_17 ( void T_1 * V_23 ,
unsigned long V_24 ,
unsigned long V_25 )
{
switch ( V_24 ) {
case 8 :
F_18 ( V_25 , V_23 ) ;
return;
case 16 :
F_19 ( V_25 , V_23 ) ;
return;
case 32 :
F_20 ( V_25 , V_23 ) ;
return;
}
F_16 () ;
}
static int F_21 ( struct V_26 * V_27 ,
unsigned long V_28 )
{
unsigned long V_29 ;
V_29 = V_27 -> V_24 - ( V_28 + 1 ) ;
F_22 ( L_1
L_2 , V_27 -> V_30 , V_29 , V_27 -> V_24 ) ;
return ( F_12 ( V_27 -> V_23 , V_27 -> V_24 ) >> V_29 ) & 1 ;
}
static void F_23 ( struct V_26 * V_27 ,
unsigned long V_28 , unsigned long V_31 )
{
unsigned long V_29 ;
V_29 = V_27 -> V_24 - ( V_28 + 1 ) ;
F_22 ( L_3
L_2 ,
V_27 -> V_30 , ! ! V_31 , V_29 , V_27 -> V_24 ) ;
if ( V_31 )
F_24 ( V_29 , & V_27 -> V_32 ) ;
else
F_25 ( V_29 , & V_27 -> V_32 ) ;
F_17 ( V_27 -> V_23 , V_27 -> V_24 , V_27 -> V_32 ) ;
}
static void F_26 ( struct V_1 * V_33 ,
struct V_34 * V_35 ,
unsigned long V_28 ,
void T_1 * * V_36 ,
unsigned long * V_37 ,
unsigned long * V_38 )
{
int V_3 ;
* V_36 = F_10 ( V_33 , V_35 -> V_30 ) ;
if ( V_35 -> V_39 ) {
* V_37 = ( 1 << V_35 -> V_39 ) - 1 ;
* V_38 = V_35 -> V_24 - ( ( V_28 + 1 ) * V_35 -> V_39 ) ;
} else {
* V_37 = ( 1 << V_35 -> V_40 [ V_28 ] ) - 1 ;
* V_38 = V_35 -> V_24 ;
for ( V_3 = 0 ; V_3 <= V_28 ; V_3 ++ )
* V_38 -= V_35 -> V_40 [ V_3 ] ;
}
}
static int F_27 ( struct V_1 * V_33 ,
struct V_34 * V_35 ,
unsigned long V_41 )
{
void T_1 * V_23 ;
unsigned long V_42 , V_29 ;
F_26 ( V_33 , V_35 , V_41 , & V_23 , & V_42 , & V_29 ) ;
F_22 ( L_4
L_5 ,
V_35 -> V_30 , V_41 , V_35 -> V_24 , V_35 -> V_39 ) ;
return ( F_12 ( V_23 , V_35 -> V_24 ) >> V_29 ) & V_42 ;
}
static void F_28 ( struct V_1 * V_33 ,
struct V_34 * V_35 ,
unsigned long V_41 , unsigned long V_31 )
{
void T_1 * V_23 ;
unsigned long V_42 , V_29 , V_25 ;
F_26 ( V_33 , V_35 , V_41 , & V_23 , & V_42 , & V_29 ) ;
F_22 ( L_6
L_5 ,
V_35 -> V_30 , V_31 , V_41 , V_35 -> V_24 , V_35 -> V_39 ) ;
V_42 = ~ ( V_42 << V_29 ) ;
V_31 = V_31 << V_29 ;
V_25 = F_12 ( V_23 , V_35 -> V_24 ) ;
V_25 &= V_42 ;
V_25 |= V_31 ;
if ( V_33 -> V_43 )
F_17 ( F_10 ( V_33 , V_33 -> V_43 ) ,
32 , ~ V_25 ) ;
F_17 ( V_23 , V_35 -> V_24 , V_25 ) ;
}
static int F_29 ( struct V_1 * V_33 , unsigned V_44 )
{
struct V_45 * V_46 = & V_33 -> V_47 [ V_44 ] ;
struct V_26 * V_48 ;
int V_3 , V_49 ;
if ( ! F_11 ( V_46 -> V_18 , & V_33 -> V_25 ) )
return - 1 ;
V_3 = 0 ;
while ( 1 ) {
V_48 = V_33 -> V_50 + V_3 ;
if ( ! V_48 -> V_24 )
break;
V_48 -> V_23 = F_10 ( V_33 , V_48 -> V_30 ) ;
for ( V_49 = 0 ; V_49 < V_48 -> V_24 ; V_49 ++ ) {
if ( V_48 -> V_51 [ V_49 ] == V_46 -> V_18 ) {
V_46 -> V_52 &= ~ V_53 ;
V_46 -> V_52 |= ( V_3 << V_54 ) ;
V_46 -> V_52 &= ~ V_55 ;
V_46 -> V_52 |= ( V_49 << V_56 ) ;
return 0 ;
}
}
V_3 ++ ;
}
F_16 () ;
return - 1 ;
}
static void F_30 ( struct V_1 * V_33 )
{
struct V_26 * V_57 ;
int V_3 ;
for ( V_3 = V_33 -> V_58 ; V_3 <= V_33 -> V_59 ; V_3 ++ )
F_29 ( V_33 , V_3 ) ;
V_3 = 0 ;
while ( 1 ) {
V_57 = V_33 -> V_50 + V_3 ;
if ( ! V_57 -> V_24 )
break;
V_57 -> V_32 = F_12 ( V_57 -> V_23 ,
V_57 -> V_24 ) ;
V_3 ++ ;
}
}
static int F_31 ( struct V_1 * V_33 , unsigned V_44 ,
struct V_26 * * V_57 , int * V_60 )
{
struct V_45 * V_46 = & V_33 -> V_47 [ V_44 ] ;
int V_3 , V_49 ;
if ( ! F_11 ( V_46 -> V_18 , & V_33 -> V_25 ) )
return - 1 ;
V_3 = ( V_46 -> V_52 & V_53 ) >> V_54 ;
V_49 = ( V_46 -> V_52 & V_55 ) >> V_56 ;
* V_57 = V_33 -> V_50 + V_3 ;
* V_60 = V_49 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_33 , T_2 V_18 ,
struct V_34 * * V_35 ,
int * V_61 , int * V_62 ,
unsigned long * * V_63 )
{
struct V_34 * V_64 ;
unsigned long V_65 , V_66 , V_67 , V_68 ;
int V_3 , V_69 , V_49 , V_29 , V_70 ;
V_3 = 0 ;
while ( 1 ) {
V_64 = V_33 -> V_71 + V_3 ;
V_65 = V_64 -> V_24 ;
V_66 = V_64 -> V_39 ;
if ( ! V_65 )
break;
V_29 = 0 ;
V_69 = 0 ;
for ( V_70 = 0 ; V_70 < V_65 ; V_70 += V_67 ) {
if ( V_66 )
V_67 = V_66 ;
else
V_67 = V_64 -> V_40 [ V_69 ] ;
V_68 = 1 << V_67 ;
for ( V_49 = 0 ; V_49 < V_68 ; V_49 ++ ) {
if ( V_64 -> V_51 [ V_29 + V_49 ] == V_18 ) {
* V_35 = V_64 ;
* V_61 = V_69 ;
* V_62 = V_49 ;
* V_63 = & V_64 -> V_72 [ V_69 ] ;
return 0 ;
}
}
V_29 += V_68 ;
V_69 ++ ;
}
V_3 ++ ;
}
return - 1 ;
}
static int F_33 ( struct V_1 * V_33 , unsigned V_44 ,
int V_29 , T_2 * V_73 )
{
T_2 V_18 = V_33 -> V_47 [ V_44 ] . V_18 ;
T_2 * V_25 = V_33 -> V_74 ;
int V_3 ;
if ( ! F_11 ( V_18 , & V_33 -> V_25 ) ) {
if ( ! F_11 ( V_18 , & V_33 -> V_75 ) ) {
F_34 ( L_7 , V_44 ) ;
return - 1 ;
}
}
if ( V_29 ) {
* V_73 = V_25 [ V_29 + 1 ] ;
return V_29 + 1 ;
}
for ( V_3 = 0 ; V_3 < V_33 -> V_76 ; V_3 ++ ) {
if ( V_25 [ V_3 ] == V_18 ) {
* V_73 = V_25 [ V_3 + 1 ] ;
return V_3 + 1 ;
}
}
F_34 ( L_8 , V_44 ) ;
return - 1 ;
}
static int F_35 ( struct V_1 * V_33 , unsigned V_44 ,
int V_77 , int V_78 )
{
struct V_34 * V_79 = NULL ;
T_2 V_18 ;
struct V_19 * V_80 ;
int V_81 , V_29 , V_41 , V_31 ;
unsigned long * V_63 ;
switch ( V_77 ) {
case V_82 :
V_80 = NULL ;
break;
case V_83 :
V_80 = & V_33 -> V_84 ;
break;
case V_85 :
V_80 = & V_33 -> V_86 ;
break;
case V_87 :
V_80 = & V_33 -> V_88 ;
break;
case V_89 :
V_80 = & V_33 -> V_90 ;
break;
default:
goto V_91;
}
V_29 = 0 ;
V_18 = 0 ;
V_41 = 0 ;
V_31 = 0 ;
while ( 1 ) {
V_29 = F_33 ( V_33 , V_44 , V_29 , & V_18 ) ;
if ( V_29 <= 0 )
goto V_91;
if ( ! V_18 )
break;
V_81 = F_11 ( V_18 , & V_33 -> V_92 ) ;
if ( ! V_81 ) {
if ( V_80 ) {
V_81 = F_11 ( V_18 , V_80 ) ;
if ( V_81 && V_18 == V_80 -> V_93 )
continue;
} else {
V_81 = 1 ;
}
}
if ( ! V_81 )
continue;
if ( F_32 ( V_33 , V_18 , & V_79 ,
& V_41 , & V_31 , & V_63 ) != 0 )
goto V_91;
switch ( V_78 ) {
case V_94 :
if ( ! * V_63 ||
( F_27 ( V_33 , V_79 , V_41 ) != V_31 ) )
continue;
break;
case V_95 :
F_28 ( V_33 , V_79 , V_41 , V_31 ) ;
* V_63 = * V_63 + 1 ;
break;
case V_96 :
* V_63 = * V_63 - 1 ;
break;
}
}
return 0 ;
V_91:
return - 1 ;
}
static struct V_1 * F_36 ( struct V_97 * V_98 )
{
return F_37 ( V_98 , struct V_1 , V_98 ) ;
}
static int F_38 ( struct V_97 * V_98 , unsigned V_99 )
{
struct V_1 * V_33 = F_36 ( V_98 ) ;
struct V_26 * V_100 ;
unsigned long V_52 ;
int V_101 , V_102 , V_77 ;
V_102 = - V_103 ;
if ( ! V_33 )
goto V_104;
F_39 ( & V_105 , V_52 ) ;
if ( ( V_33 -> V_47 [ V_99 ] . V_52 & V_106 ) != V_107 )
goto V_108;
if ( F_31 ( V_33 , V_99 , & V_100 , & V_101 ) != 0 )
V_77 = V_82 ;
else
V_77 = V_109 ;
if ( V_77 == V_82 ) {
if ( F_35 ( V_33 , V_99 ,
V_77 ,
V_94 ) != 0 )
goto V_108;
if ( F_35 ( V_33 , V_99 ,
V_77 ,
V_95 ) != 0 )
F_16 () ;
}
V_33 -> V_47 [ V_99 ] . V_52 &= ~ V_106 ;
V_33 -> V_47 [ V_99 ] . V_52 |= V_77 ;
V_102 = 0 ;
V_108:
F_40 ( & V_105 , V_52 ) ;
V_104:
return V_102 ;
}
static void F_41 ( struct V_97 * V_98 , unsigned V_99 )
{
struct V_1 * V_33 = F_36 ( V_98 ) ;
unsigned long V_52 ;
int V_77 ;
if ( ! V_33 )
return;
F_39 ( & V_105 , V_52 ) ;
V_77 = V_33 -> V_47 [ V_99 ] . V_52 & V_106 ;
F_35 ( V_33 , V_99 , V_77 , V_96 ) ;
V_33 -> V_47 [ V_99 ] . V_52 &= ~ V_106 ;
V_33 -> V_47 [ V_99 ] . V_52 |= V_107 ;
F_40 ( & V_105 , V_52 ) ;
}
static int F_42 ( struct V_1 * V_33 ,
unsigned V_44 , int V_110 )
{
int V_77 ;
int V_102 = - V_103 ;
if ( ! V_33 )
goto V_104;
V_77 = V_33 -> V_47 [ V_44 ] . V_52 & V_106 ;
switch ( V_77 ) {
case V_109 :
break;
case V_83 :
case V_85 :
case V_87 :
case V_89 :
F_35 ( V_33 , V_44 , V_77 , V_96 ) ;
break;
default:
goto V_104;
}
if ( F_35 ( V_33 , V_44 ,
V_110 ,
V_94 ) != 0 )
goto V_104;
if ( F_35 ( V_33 , V_44 ,
V_110 ,
V_95 ) != 0 )
F_16 () ;
V_33 -> V_47 [ V_44 ] . V_52 &= ~ V_106 ;
V_33 -> V_47 [ V_44 ] . V_52 |= V_110 ;
V_102 = 0 ;
V_104:
return V_102 ;
}
static int F_43 ( struct V_97 * V_98 , unsigned V_99 )
{
struct V_1 * V_33 = F_36 ( V_98 ) ;
unsigned long V_52 ;
int V_102 ;
F_39 ( & V_105 , V_52 ) ;
V_102 = F_42 ( V_33 , V_99 , V_85 ) ;
F_40 ( & V_105 , V_52 ) ;
return V_102 ;
}
static void F_44 ( struct V_1 * V_33 ,
unsigned V_44 , int V_31 )
{
struct V_26 * V_27 = NULL ;
int V_111 = 0 ;
if ( ! V_33 || F_31 ( V_33 , V_44 , & V_27 , & V_111 ) != 0 )
F_16 () ;
else
F_23 ( V_27 , V_111 , V_31 ) ;
}
static int F_45 ( struct V_97 * V_98 , unsigned V_99 ,
int V_31 )
{
struct V_1 * V_33 = F_36 ( V_98 ) ;
unsigned long V_52 ;
int V_102 ;
F_44 ( V_33 , V_99 , V_31 ) ;
F_39 ( & V_105 , V_52 ) ;
V_102 = F_42 ( V_33 , V_99 , V_83 ) ;
F_40 ( & V_105 , V_52 ) ;
return V_102 ;
}
static int F_46 ( struct V_1 * V_33 , unsigned V_44 )
{
struct V_26 * V_27 = NULL ;
int V_111 = 0 ;
if ( ! V_33 || F_31 ( V_33 , V_44 , & V_27 , & V_111 ) != 0 )
return - V_103 ;
return F_21 ( V_27 , V_111 ) ;
}
static int F_47 ( struct V_97 * V_98 , unsigned V_99 )
{
return F_46 ( F_36 ( V_98 ) , V_99 ) ;
}
static void F_48 ( struct V_97 * V_98 , unsigned V_99 , int V_31 )
{
F_44 ( F_36 ( V_98 ) , V_99 , V_31 ) ;
}
static int F_49 ( struct V_97 * V_98 , unsigned V_99 )
{
struct V_1 * V_33 = F_36 ( V_98 ) ;
T_2 V_18 ;
T_2 * V_51 ;
int V_101 , V_3 , V_29 ;
V_29 = 0 ;
V_18 = 0 ;
while ( 1 ) {
V_29 = F_33 ( V_33 , V_99 , V_29 , & V_18 ) ;
if ( V_29 <= 0 || ! V_18 )
break;
for ( V_101 = 0 ; V_101 < V_33 -> V_112 ; V_101 ++ ) {
V_51 = V_33 -> V_113 [ V_101 ] . V_51 ;
for ( V_3 = 0 ; V_51 [ V_3 ] ; V_3 ++ ) {
if ( V_51 [ V_3 ] == V_18 )
return V_33 -> V_113 [ V_101 ] . V_114 ;
}
}
}
return - V_115 ;
}
int F_50 ( struct V_1 * V_2 )
{
struct V_97 * V_98 = & V_2 -> V_98 ;
int V_102 ;
F_51 ( L_9 ,
V_2 -> V_116 , V_2 -> V_58 , V_2 -> V_59 ) ;
V_102 = F_4 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
F_30 ( V_2 ) ;
V_98 -> V_117 = F_38 ;
V_98 -> free = F_41 ;
V_98 -> V_118 = F_43 ;
V_98 -> V_119 = F_47 ;
V_98 -> V_120 = F_45 ;
V_98 -> V_121 = F_48 ;
V_98 -> V_122 = F_49 ;
F_6 ( V_2 -> V_58 != 0 ) ;
V_98 -> V_123 = V_2 -> V_116 ;
V_98 -> V_124 = V_125 ;
V_98 -> V_126 = V_2 -> V_58 ;
V_98 -> V_127 = ( V_2 -> V_59 - V_2 -> V_58 ) + 1 ;
V_102 = F_52 ( V_98 ) ;
if ( V_102 < 0 )
F_1 ( V_2 ) ;
return V_102 ;
}
int F_53 ( struct V_1 * V_2 )
{
F_51 ( L_10 , V_2 -> V_116 ) ;
F_1 ( V_2 ) ;
return F_54 ( & V_2 -> V_98 ) ;
}
