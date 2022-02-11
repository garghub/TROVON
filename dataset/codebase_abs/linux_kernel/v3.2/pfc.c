static int F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
if ( V_1 < V_3 -> V_4 )
return 0 ;
if ( V_1 > V_3 -> V_5 )
return 0 ;
return 1 ;
}
static unsigned long F_2 ( unsigned long V_6 ,
unsigned long V_7 )
{
switch ( V_7 ) {
case 8 :
return F_3 ( V_6 ) ;
case 16 :
return F_4 ( V_6 ) ;
case 32 :
return F_5 ( V_6 ) ;
}
F_6 () ;
return 0 ;
}
static void F_7 ( unsigned long V_6 ,
unsigned long V_7 ,
unsigned long V_8 )
{
switch ( V_7 ) {
case 8 :
F_8 ( V_8 , V_6 ) ;
return;
case 16 :
F_9 ( V_8 , V_6 ) ;
return;
case 32 :
F_10 ( V_8 , V_6 ) ;
return;
}
F_6 () ;
}
static void F_11 ( struct V_9 * V_10 ,
unsigned long V_11 , unsigned long V_12 )
{
unsigned long V_13 ;
V_13 = V_10 -> V_7 - ( V_11 + 1 ) ;
F_12 ( L_1
L_2 ,
V_10 -> V_6 , ! ! V_12 , V_13 , V_10 -> V_7 ) ;
if ( V_12 )
F_13 ( V_13 , & V_10 -> V_14 ) ;
else
F_14 ( V_13 , & V_10 -> V_14 ) ;
F_7 ( V_10 -> V_6 , V_10 -> V_7 , V_10 -> V_14 ) ;
}
static int F_15 ( unsigned long V_6 , unsigned long V_7 ,
unsigned long V_15 , unsigned long V_11 )
{
unsigned long V_8 , V_16 , V_13 ;
V_8 = 0 ;
V_16 = ( 1 << V_15 ) - 1 ;
V_13 = V_7 - ( ( V_11 + 1 ) * V_15 ) ;
F_12 ( L_3
L_4 ,
V_6 , V_13 , V_7 , V_15 ) ;
V_8 = F_2 ( V_6 , V_7 ) ;
return ( V_8 >> V_13 ) & V_16 ;
}
static void F_16 ( unsigned long V_6 , unsigned long V_7 ,
unsigned long V_15 , unsigned long V_11 ,
unsigned long V_12 )
{
unsigned long V_16 , V_13 ;
V_16 = ( 1 << V_15 ) - 1 ;
V_13 = V_7 - ( ( V_11 + 1 ) * V_15 ) ;
F_12 ( L_5
L_4 ,
V_6 , V_12 , V_13 , V_7 , V_15 ) ;
V_16 = ~ ( V_16 << V_13 ) ;
V_12 = V_12 << V_13 ;
switch ( V_7 ) {
case 8 :
F_8 ( ( F_3 ( V_6 ) & V_16 ) | V_12 , V_6 ) ;
break;
case 16 :
F_9 ( ( F_4 ( V_6 ) & V_16 ) | V_12 , V_6 ) ;
break;
case 32 :
F_10 ( ( F_5 ( V_6 ) & V_16 ) | V_12 , V_6 ) ;
break;
}
}
static int F_17 ( struct V_17 * V_18 , unsigned V_19 )
{
struct V_20 * V_21 = & V_18 -> V_22 [ V_19 ] ;
struct V_9 * V_23 ;
int V_24 , V_25 ;
if ( ! F_1 ( V_21 -> V_1 , & V_18 -> V_8 ) )
return - 1 ;
V_24 = 0 ;
while ( 1 ) {
V_23 = V_18 -> V_26 + V_24 ;
if ( ! V_23 -> V_7 )
break;
for ( V_25 = 0 ; V_25 < V_23 -> V_7 ; V_25 ++ ) {
if ( V_23 -> V_27 [ V_25 ] == V_21 -> V_1 ) {
V_21 -> V_28 &= ~ V_29 ;
V_21 -> V_28 |= ( V_24 << V_30 ) ;
V_21 -> V_28 &= ~ V_31 ;
V_21 -> V_28 |= ( V_25 << V_32 ) ;
return 0 ;
}
}
V_24 ++ ;
}
F_6 () ;
return - 1 ;
}
static void F_18 ( struct V_17 * V_18 )
{
struct V_9 * V_33 ;
int V_24 ;
for ( V_24 = V_18 -> V_34 ; V_24 <= V_18 -> V_35 ; V_24 ++ )
F_17 ( V_18 , V_24 ) ;
V_24 = 0 ;
while ( 1 ) {
V_33 = V_18 -> V_26 + V_24 ;
if ( ! V_33 -> V_7 )
break;
V_33 -> V_14 = F_2 ( V_33 -> V_6 , V_33 -> V_7 ) ;
V_24 ++ ;
}
}
static int F_19 ( struct V_17 * V_18 , unsigned V_19 ,
struct V_9 * * V_33 , int * V_36 )
{
struct V_20 * V_21 = & V_18 -> V_22 [ V_19 ] ;
int V_24 , V_25 ;
if ( ! F_1 ( V_21 -> V_1 , & V_18 -> V_8 ) )
return - 1 ;
V_24 = ( V_21 -> V_28 & V_29 ) >> V_30 ;
V_25 = ( V_21 -> V_28 & V_31 ) >> V_32 ;
* V_33 = V_18 -> V_26 + V_24 ;
* V_36 = V_25 ;
return 0 ;
}
static int F_20 ( struct V_17 * V_18 , T_1 V_1 ,
struct V_37 * * V_38 , int * V_39 ,
unsigned long * * V_40 )
{
struct V_37 * V_41 ;
unsigned long V_42 , V_43 ;
int V_24 , V_25 ;
V_24 = 0 ;
while ( 1 ) {
V_41 = V_18 -> V_44 + V_24 ;
V_42 = V_41 -> V_7 ;
V_43 = V_41 -> V_15 ;
if ( ! V_42 )
break;
for ( V_25 = 0 ; V_25 < ( V_42 / V_43 ) * ( 1 << V_43 ) ; V_25 ++ ) {
if ( V_41 -> V_27 [ V_25 ] == V_1 ) {
* V_38 = V_41 ;
* V_39 = V_25 ;
* V_40 = & V_41 -> V_45 [ V_25 / ( 1 << V_43 ) ] ;
return 0 ;
}
}
V_24 ++ ;
}
return - 1 ;
}
static int F_21 ( struct V_17 * V_18 , unsigned V_19 ,
int V_13 , T_1 * V_46 )
{
T_1 V_1 = V_18 -> V_22 [ V_19 ] . V_1 ;
T_1 * V_8 = V_18 -> V_47 ;
int V_24 ;
if ( ! F_1 ( V_1 , & V_18 -> V_8 ) ) {
if ( ! F_1 ( V_1 , & V_18 -> V_48 ) ) {
F_22 ( L_6 , V_19 ) ;
return - 1 ;
}
}
if ( V_13 ) {
* V_46 = V_8 [ V_13 + 1 ] ;
return V_13 + 1 ;
}
for ( V_24 = 0 ; V_24 < V_18 -> V_49 ; V_24 ++ ) {
if ( V_8 [ V_24 ] == V_1 ) {
* V_46 = V_8 [ V_24 + 1 ] ;
return V_24 + 1 ;
}
}
F_22 ( L_7 , V_19 ) ;
return - 1 ;
}
static void F_23 ( struct V_17 * V_18 ,
struct V_37 * V_38 ,
int V_50 )
{
unsigned long V_51 , V_13 , V_12 ;
V_51 = 1 << V_38 -> V_15 ;
V_13 = V_50 / V_51 ;
V_12 = V_50 % V_51 ;
F_16 ( V_38 -> V_6 , V_38 -> V_7 , V_38 -> V_15 , V_13 , V_12 ) ;
}
static int F_24 ( struct V_17 * V_18 ,
struct V_37 * V_38 ,
int V_50 )
{
unsigned long V_51 , V_13 , V_12 ;
V_51 = 1 << V_38 -> V_15 ;
V_13 = V_50 / V_51 ;
V_12 = V_50 % V_51 ;
if ( F_15 ( V_38 -> V_6 , V_38 -> V_7 ,
V_38 -> V_15 , V_13 ) == V_12 )
return 0 ;
return - 1 ;
}
static int F_25 ( struct V_17 * V_18 , unsigned V_19 ,
int V_52 , int V_53 )
{
struct V_37 * V_54 = NULL ;
T_1 V_1 ;
struct V_2 * V_55 ;
int V_56 , V_13 , V_50 ;
unsigned long * V_40 ;
switch ( V_52 ) {
case V_57 :
V_55 = NULL ;
break;
case V_58 :
V_55 = & V_18 -> V_59 ;
break;
case V_60 :
V_55 = & V_18 -> V_61 ;
break;
case V_62 :
V_55 = & V_18 -> V_63 ;
break;
case V_64 :
V_55 = & V_18 -> V_65 ;
break;
default:
goto V_66;
}
V_13 = 0 ;
V_1 = 0 ;
V_50 = 0 ;
while ( 1 ) {
V_13 = F_21 ( V_18 , V_19 , V_13 , & V_1 ) ;
if ( V_13 <= 0 )
goto V_66;
if ( ! V_1 )
break;
V_56 = F_1 ( V_1 , & V_18 -> V_67 ) ;
if ( ! V_56 ) {
if ( V_55 ) {
V_56 = F_1 ( V_1 , V_55 ) ;
if ( V_56 && V_1 == V_55 -> V_68 )
continue;
} else {
V_56 = 1 ;
}
}
if ( ! V_56 )
continue;
if ( F_20 ( V_18 , V_1 , & V_54 , & V_50 , & V_40 ) != 0 )
goto V_66;
switch ( V_53 ) {
case V_69 :
if ( ! * V_40 || ! F_24 ( V_18 , V_54 , V_50 ) )
continue;
break;
case V_70 :
F_23 ( V_18 , V_54 , V_50 ) ;
* V_40 = * V_40 + 1 ;
break;
case V_71 :
* V_40 = * V_40 - 1 ;
break;
}
}
return 0 ;
V_66:
return - 1 ;
}
static struct V_17 * F_26 ( struct V_72 * V_73 )
{
return F_27 ( V_73 , struct V_17 , V_73 ) ;
}
static int F_28 ( struct V_72 * V_73 , unsigned V_74 )
{
struct V_17 * V_18 = F_26 ( V_73 ) ;
struct V_9 * V_75 ;
unsigned long V_28 ;
int V_76 , V_77 , V_52 ;
V_77 = - V_78 ;
if ( ! V_18 )
goto V_79;
F_29 ( & V_80 , V_28 ) ;
if ( ( V_18 -> V_22 [ V_74 ] . V_28 & V_81 ) != V_82 )
goto V_83;
if ( F_19 ( V_18 , V_74 , & V_75 , & V_76 ) != 0 )
V_52 = V_57 ;
else
V_52 = V_84 ;
if ( V_52 == V_57 ) {
if ( F_25 ( V_18 , V_74 ,
V_52 ,
V_69 ) != 0 )
goto V_83;
if ( F_25 ( V_18 , V_74 ,
V_52 ,
V_70 ) != 0 )
F_6 () ;
}
V_18 -> V_22 [ V_74 ] . V_28 &= ~ V_81 ;
V_18 -> V_22 [ V_74 ] . V_28 |= V_52 ;
V_77 = 0 ;
V_83:
F_30 ( & V_80 , V_28 ) ;
V_79:
return V_77 ;
}
static void F_31 ( struct V_72 * V_73 , unsigned V_74 )
{
struct V_17 * V_18 = F_26 ( V_73 ) ;
unsigned long V_28 ;
int V_52 ;
if ( ! V_18 )
return;
F_29 ( & V_80 , V_28 ) ;
V_52 = V_18 -> V_22 [ V_74 ] . V_28 & V_81 ;
F_25 ( V_18 , V_74 , V_52 , V_71 ) ;
V_18 -> V_22 [ V_74 ] . V_28 &= ~ V_81 ;
V_18 -> V_22 [ V_74 ] . V_28 |= V_82 ;
F_30 ( & V_80 , V_28 ) ;
}
static int F_32 ( struct V_17 * V_18 ,
unsigned V_19 , int V_85 )
{
int V_52 ;
int V_77 = - V_78 ;
if ( ! V_18 )
goto V_79;
V_52 = V_18 -> V_22 [ V_19 ] . V_28 & V_81 ;
switch ( V_52 ) {
case V_84 :
break;
case V_58 :
case V_60 :
case V_62 :
case V_64 :
F_25 ( V_18 , V_19 , V_52 , V_71 ) ;
break;
default:
goto V_79;
}
if ( F_25 ( V_18 , V_19 ,
V_85 ,
V_69 ) != 0 )
goto V_79;
if ( F_25 ( V_18 , V_19 ,
V_85 ,
V_70 ) != 0 )
F_6 () ;
V_18 -> V_22 [ V_19 ] . V_28 &= ~ V_81 ;
V_18 -> V_22 [ V_19 ] . V_28 |= V_85 ;
V_77 = 0 ;
V_79:
return V_77 ;
}
static int F_33 ( struct V_72 * V_73 , unsigned V_74 )
{
struct V_17 * V_18 = F_26 ( V_73 ) ;
unsigned long V_28 ;
int V_77 ;
F_29 ( & V_80 , V_28 ) ;
V_77 = F_32 ( V_18 , V_74 , V_60 ) ;
F_30 ( & V_80 , V_28 ) ;
return V_77 ;
}
static void F_34 ( struct V_17 * V_18 ,
unsigned V_19 , int V_12 )
{
struct V_9 * V_10 = NULL ;
int V_86 = 0 ;
if ( ! V_18 || F_19 ( V_18 , V_19 , & V_10 , & V_86 ) != 0 )
F_6 () ;
else
F_11 ( V_10 , V_86 , V_12 ) ;
}
static int F_35 ( struct V_72 * V_73 , unsigned V_74 ,
int V_12 )
{
struct V_17 * V_18 = F_26 ( V_73 ) ;
unsigned long V_28 ;
int V_77 ;
F_34 ( V_18 , V_74 , V_12 ) ;
F_29 ( & V_80 , V_28 ) ;
V_77 = F_32 ( V_18 , V_74 , V_58 ) ;
F_30 ( & V_80 , V_28 ) ;
return V_77 ;
}
static int F_36 ( struct V_17 * V_18 , unsigned V_19 )
{
struct V_9 * V_10 = NULL ;
int V_86 = 0 ;
if ( ! V_18 || F_19 ( V_18 , V_19 , & V_10 , & V_86 ) != 0 )
return - V_78 ;
return F_15 ( V_10 -> V_6 , V_10 -> V_7 , 1 , V_86 ) ;
}
static int F_37 ( struct V_72 * V_73 , unsigned V_74 )
{
return F_36 ( F_26 ( V_73 ) , V_74 ) ;
}
static void F_38 ( struct V_72 * V_73 , unsigned V_74 , int V_12 )
{
F_34 ( F_26 ( V_73 ) , V_74 , V_12 ) ;
}
static int F_39 ( struct V_72 * V_73 , unsigned V_74 )
{
struct V_17 * V_18 = F_26 ( V_73 ) ;
T_1 V_1 ;
T_1 * V_27 ;
int V_76 , V_24 , V_13 ;
V_13 = 0 ;
V_1 = 0 ;
while ( 1 ) {
V_13 = F_21 ( V_18 , V_74 , V_13 , & V_1 ) ;
if ( V_13 <= 0 || ! V_1 )
break;
for ( V_76 = 0 ; V_76 < V_18 -> V_87 ; V_76 ++ ) {
V_27 = V_18 -> V_88 [ V_76 ] . V_27 ;
for ( V_24 = 0 ; V_27 [ V_24 ] ; V_24 ++ ) {
if ( V_27 [ V_24 ] == V_1 )
return V_18 -> V_88 [ V_76 ] . V_89 ;
}
}
}
return - V_90 ;
}
int F_40 ( struct V_17 * V_91 )
{
struct V_72 * V_73 = & V_91 -> V_73 ;
F_41 ( L_8 ,
V_91 -> V_92 , V_91 -> V_34 , V_91 -> V_35 ) ;
F_18 ( V_91 ) ;
V_73 -> V_93 = F_28 ;
V_73 -> free = F_31 ;
V_73 -> V_94 = F_33 ;
V_73 -> V_95 = F_37 ;
V_73 -> V_96 = F_35 ;
V_73 -> V_97 = F_38 ;
V_73 -> V_98 = F_39 ;
F_42 ( V_91 -> V_34 != 0 ) ;
V_73 -> V_99 = V_91 -> V_92 ;
V_73 -> V_100 = V_101 ;
V_73 -> V_102 = V_91 -> V_34 ;
V_73 -> V_103 = ( V_91 -> V_35 - V_91 -> V_34 ) + 1 ;
return F_43 ( V_73 ) ;
}
int F_44 ( struct V_17 * V_91 )
{
F_41 ( L_9 , V_91 -> V_92 ) ;
return F_45 ( & V_91 -> V_73 ) ;
}
