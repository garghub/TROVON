static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = V_6 -> V_9 ;
int V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_12 ; V_10 ++ ) {
V_11 = V_8 -> V_13 [ V_10 ] ;
if ( V_11 >= V_3 && V_11 <= V_4 )
return F_3 ( V_6 -> V_14 , V_10 ) ;
}
return - V_15 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = V_6 -> V_9 ;
unsigned int V_16 ;
int V_17 ;
V_17 = F_5 ( V_6 -> V_14 , & V_16 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_16 >= V_8 -> V_12 )
V_16 = V_8 -> V_12 - 1 ;
return V_8 -> V_13 [ V_16 ] ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned V_19 ;
switch ( V_18 ) {
case V_20 :
V_19 = V_21 ;
break;
case V_22 :
V_19 = V_23 ;
break;
case V_24 :
V_19 = V_25 ;
break;
default:
return - V_15 ;
}
return F_3 ( V_6 -> V_18 , V_19 ) ;
}
static unsigned F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_26 * V_27 ;
unsigned int V_19 , V_18 = 0 ;
int V_17 ;
V_17 = F_5 ( V_6 -> V_18 , & V_19 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_19 ) {
default:
case V_28 :
V_18 = V_20 | V_24 ;
break;
case V_25 :
return V_24 ;
case V_21 :
return V_20 ;
case V_23 :
return V_22 ;
}
V_17 = F_5 ( V_6 -> V_29 , & V_19 ) ;
if ( V_17 < 0 )
return 0 ;
if ( V_19 )
V_27 = V_6 -> V_30 ;
else
V_27 = V_6 -> V_31 ;
V_17 = F_5 ( V_27 , & V_19 ) ;
if ( V_17 < 0 )
return 0 ;
if ( V_19 )
V_18 &= V_24 ;
else
V_18 &= V_22 | V_20 ;
return V_18 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned V_19 ;
switch ( V_18 ) {
case V_22 :
V_19 = 0 ;
break;
case V_24 :
V_19 = 1 ;
break;
default:
return - V_15 ;
}
return F_3 ( V_6 -> V_31 , V_19 ) ;
}
static unsigned F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_26 * V_27 ;
int V_17 , V_19 ;
V_17 = F_5 ( V_6 -> V_29 , & V_19 ) ;
if ( V_17 < 0 )
return 0 ;
if ( V_19 )
V_27 = V_6 -> V_30 ;
else
V_27 = V_6 -> V_31 ;
V_17 = F_5 ( V_27 , & V_19 ) ;
if ( V_17 < 0 )
return 0 ;
if ( V_19 )
return V_24 ;
else
return V_22 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_17 = F_11 ( V_2 ) ;
if ( V_17 == 0 ) {
V_17 = V_32 ;
} else if ( V_17 > 0 ) {
V_17 = F_7 ( V_2 ) ;
if ( V_17 > 0 )
V_17 = F_12 ( V_17 ) ;
else if ( V_17 == 0 )
V_17 = - V_33 ;
}
return V_17 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_17 = F_11 ( V_2 ) ;
if ( V_17 == 0 ) {
V_17 = V_32 ;
} else if ( V_17 > 0 ) {
V_17 = F_9 ( V_2 ) ;
if ( V_17 > 0 )
V_17 = F_12 ( V_17 ) ;
else if ( V_17 == 0 )
V_17 = - V_33 ;
}
return V_17 ;
}
static int F_14 ( struct V_1 * V_2 , int V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = V_6 -> V_9 ;
int V_17 , V_16 ;
V_16 = F_15 ( V_2 , V_34 , V_34 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 <<= F_16 ( V_2 -> V_35 -> V_36 ) - 1 ;
V_17 = F_17 ( V_6 -> V_37 -> V_38 , V_8 -> V_39 ,
V_2 -> V_35 -> V_36 , V_16 ) ;
return V_17 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_3 ( V_6 -> V_29 , 1 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_3 ( V_6 -> V_29 , 0 ) ;
}
static int F_20 ( struct V_1 * V_2 , unsigned V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_19 ;
switch ( V_18 ) {
case V_20 :
V_19 = V_21 ;
break;
case V_22 :
V_19 = V_23 ;
break;
case V_24 :
V_19 = V_25 ;
break;
default:
return - V_15 ;
}
return F_3 ( V_6 -> V_18 , V_19 ) ;
}
static int F_21 ( struct V_1 * V_2 , unsigned V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned V_19 ;
switch ( V_18 ) {
case V_22 :
V_19 = 0 ;
break;
case V_24 :
V_19 = 1 ;
break;
default:
return - V_15 ;
}
return F_3 ( V_6 -> V_30 , V_19 ) ;
}
static T_1 F_22 ( int V_40 , void * V_41 )
{
struct V_42 * V_43 = V_41 ;
struct V_44 * V_37 = V_43 -> V_45 [ 0 ] . V_37 ;
struct V_5 * V_6 ;
int V_46 , V_47 , V_17 ;
V_17 = F_23 ( V_37 -> V_38 , V_48 , & V_46 ) ;
if ( V_17 < 0 )
return V_49 ;
for ( V_47 = V_43 -> V_50 - 1 ; V_47 >= 0 ; V_47 -- ) {
V_6 = & V_43 -> V_45 [ V_47 ] ;
if ( V_6 -> V_9 -> V_51 . V_52 != V_48 )
continue;
if ( F_24 ( V_6 -> V_9 -> V_51 . V_53 ) & V_46 )
F_25 ( V_6 -> V_2 ,
V_54 , NULL ) ;
}
return V_55 ;
}
static const struct V_56 * F_26 (
const struct V_57 * V_58 , int V_59 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_58 -> V_50 ; V_47 ++ ) {
if ( V_59 == V_58 -> V_60 [ V_47 ] . V_59 )
return V_58 -> V_60 [ V_47 ] . V_61 ;
}
return NULL ;
}
static struct V_57 * F_27 (
struct V_62 * V_63 ,
struct V_64 * * V_65 )
{
struct V_57 * V_66 ;
struct V_67 * V_68 ;
struct V_69 * V_70 ;
int V_47 , V_10 , V_71 ;
V_70 = F_28 ( V_63 -> V_72 . V_73 -> V_74 , L_1 ) ;
if ( ! V_70 ) {
F_29 ( & V_63 -> V_72 , L_2 ) ;
return F_30 ( - V_75 ) ;
}
V_71 = V_64 ( & V_63 -> V_72 , V_70 , V_76 ,
F_31 ( V_76 ) ) ;
F_32 ( V_70 ) ;
if ( V_71 < 0 ) {
F_29 ( & V_63 -> V_72 , L_3 ) ;
return F_30 ( - V_15 ) ;
}
V_66 = F_33 ( & V_63 -> V_72 , sizeof( * V_66 ) , V_77 ) ;
if ( ! V_66 )
return F_30 ( - V_78 ) ;
V_66 -> V_60 = F_33 ( & V_63 -> V_72 ,
V_71 * sizeof( * V_66 -> V_60 ) ,
V_77 ) ;
if ( ! V_66 -> V_60 )
return F_30 ( - V_78 ) ;
V_66 -> V_50 = V_71 ;
V_10 = 0 ;
for ( V_47 = 0 ; V_47 < F_31 ( V_76 ) ; V_47 ++ ) {
if ( ! V_76 [ V_47 ] . V_79 )
continue;
V_68 = & V_66 -> V_60 [ V_10 ] ;
V_68 -> V_59 = V_47 ;
V_68 -> V_61 = V_76 [ V_47 ] . V_79 ;
V_10 ++ ;
} ;
* V_65 = V_76 ;
return V_66 ;
}
static struct V_57 * F_27 (
struct V_62 * V_63 ,
struct V_64 * * V_65 )
{
* V_65 = NULL ;
return F_30 ( - V_75 ) ;
}
static int F_34 ( struct V_62 * V_63 )
{
struct V_44 * V_44 = F_35 ( V_63 -> V_72 . V_73 ) ;
struct V_80 * V_80 = F_36 ( V_44 -> V_72 ) ;
struct V_64 * V_65 = NULL ;
struct V_57 * V_58 ;
const struct V_81 * V_82 ;
struct V_42 * V_43 ;
struct V_5 * V_6 ;
struct V_83 V_84 ;
bool V_85 , V_86 ;
int V_59 , V_40 , V_10 , V_50 , V_17 , V_19 ;
T_2 V_87 ;
V_58 = V_80 ? V_80 -> V_88 : NULL ;
if ( ! V_58 )
V_58 = F_27 ( V_63 ,
& V_65 ) ;
if ( F_37 ( V_58 ) || V_58 -> V_50 == 0 ) {
F_29 ( & V_63 -> V_72 ,
L_4 ) ;
return F_38 ( V_58 ) ;
}
for ( V_82 = V_89 ; V_82 -> V_90 ; V_82 ++ ) {
if ( V_82 -> V_91 == V_44 -> V_82 )
break;
}
if ( ! V_82 -> V_90 ) {
F_29 ( & V_63 -> V_72 , L_5 ,
V_44 -> V_82 ) ;
return - V_75 ;
}
V_17 = F_23 ( V_44 -> V_38 , V_92 , & V_19 ) ;
if ( V_17 < 0 ) {
F_29 ( & V_63 -> V_72 ,
L_6 ) ;
return V_17 ;
}
V_85 = V_19 & V_93 ;
V_86 = V_19 & V_94 ;
V_50 = V_82 -> V_50 ;
if ( V_85 )
V_50 -= 2 ;
else
V_50 -- ;
if ( V_86 )
V_50 -= 2 ;
else
V_50 -- ;
V_87 = sizeof( struct V_42 ) +
V_50 * sizeof( struct V_5 ) ;
V_43 = F_33 ( & V_63 -> V_72 , V_87 , V_77 ) ;
if ( ! V_43 )
return - V_78 ;
V_43 -> V_50 = V_50 ;
F_39 ( V_63 , V_43 ) ;
V_10 = 0 ;
V_59 = 0 ;
while ( V_10 < V_43 -> V_50 ) {
switch ( V_59 ) {
case V_95 :
case V_96 :
if ( V_85 ) {
V_59 ++ ;
continue;
}
break;
case V_97 :
case V_98 :
if ( V_86 ) {
V_59 ++ ;
continue;
}
break;
case V_99 :
if ( ! V_85 ) {
V_59 ++ ;
continue;
}
break;
case V_100 :
if ( ! V_86 ) {
V_59 ++ ;
continue;
}
break;
}
V_6 = & V_43 -> V_45 [ V_10 ] ;
V_6 -> V_37 = V_44 ;
V_6 -> V_9 = & V_82 -> V_90 [ V_59 ] ;
V_6 -> V_35 = V_6 -> V_9 -> V_35 ;
V_6 -> V_35 . type = V_101 ;
V_6 -> V_35 . V_102 = V_103 ;
if ( V_6 -> V_9 -> V_18 . V_52 )
V_6 -> V_18 = F_40 ( & V_63 -> V_72 ,
V_44 -> V_38 , V_6 -> V_9 -> V_18 ) ;
if ( V_6 -> V_9 -> V_29 . V_52 )
V_6 -> V_29 = F_40 ( & V_63 -> V_72 ,
V_44 -> V_38 , V_6 -> V_9 -> V_29 ) ;
if ( V_6 -> V_9 -> V_31 . V_52 )
V_6 -> V_31 = F_40 ( & V_63 -> V_72 ,
V_44 -> V_38 , V_6 -> V_9 -> V_31 ) ;
if ( V_6 -> V_9 -> V_30 . V_52 )
V_6 -> V_30 = F_40 ( & V_63 -> V_72 ,
V_44 -> V_38 , V_6 -> V_9 -> V_30 ) ;
if ( V_6 -> V_9 -> V_14 . V_52 )
V_6 -> V_14 = F_40 ( & V_63 -> V_72 ,
V_44 -> V_38 , V_6 -> V_9 -> V_14 ) ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_72 = & V_63 -> V_72 ;
V_84 . V_79 = F_26 ( V_58 , V_59 ) ;
V_84 . V_104 = V_6 ;
if ( V_65 )
V_84 . V_74 = V_65 [ V_59 ] . V_74 ;
V_84 . V_38 = V_44 -> V_38 ;
V_6 -> V_2 = F_41 ( & V_63 -> V_72 , & V_6 -> V_35 ,
& V_84 ) ;
if ( F_37 ( V_6 -> V_2 ) ) {
F_29 ( & V_63 -> V_72 ,
L_7 ,
V_6 -> V_35 . V_105 ) ;
return F_38 ( V_6 -> V_2 ) ;
}
V_59 ++ ;
V_10 ++ ;
}
V_40 = F_42 ( V_63 , L_8 ) ;
if ( V_40 < 0 ) {
F_29 ( & V_63 -> V_72 , L_9 ) ;
return V_40 ;
}
V_17 = F_43 ( & V_63 -> V_72 , V_40 ,
NULL , F_22 ,
V_106 | V_107 ,
L_8 , V_43 ) ;
if ( V_17 ) {
F_29 ( & V_63 -> V_72 , L_10 ) ;
return V_17 ;
}
return 0 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_108 ) ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_108 ) ;
}
