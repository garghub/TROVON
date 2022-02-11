static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 )
{
if ( V_4 -> V_5 . V_6 )
V_4 -> V_5 . V_6 ( V_4 -> V_5 . V_7 ) ;
V_4 -> V_8 = V_4 -> V_5 . V_9 ;
}
static void F_4 ( int V_10 , void * V_11 )
{
struct V_1 * V_4 = V_11 ;
V_4 -> V_12 = V_13 ;
F_3 ( V_4 ) ;
}
static void F_5 ( int V_10 , void * V_11 , int error )
{
struct V_1 * V_4 = V_11 ;
V_4 -> V_12 = V_14 ;
F_3 ( V_4 ) ;
}
static void F_6 ( int V_10 , void * V_11 ,
struct V_15 * V_16 )
{
struct V_1 * V_4 = V_11 ;
V_4 -> V_12 = V_13 ;
F_3 ( V_4 ) ;
}
static int F_7 ( struct V_2 * V_3 , enum V_17 V_18 ,
unsigned long V_19 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_20 * V_21 = ( void * ) V_19 ;
int V_22 ;
unsigned int V_23 = 0 ;
switch ( V_18 ) {
case V_24 :
V_4 -> V_12 = V_14 ;
F_8 ( V_4 -> V_1 ) ;
return 0 ;
case V_25 :
if ( V_21 -> V_26 == V_27 ) {
V_4 -> V_28 = V_21 -> V_29 ;
V_4 -> V_30 = V_21 -> V_31 ;
V_4 -> V_32 = V_21 -> V_33 ;
} else {
V_4 -> V_28 = V_21 -> V_34 ;
V_4 -> V_30 = V_21 -> V_35 ;
V_4 -> V_32 = V_21 -> V_36 ;
}
switch ( V_4 -> V_32 ) {
case V_37 :
V_23 = V_38 ;
break;
case V_39 :
V_23 = V_40 ;
break;
default:
case V_41 :
V_23 = V_42 ;
break;
}
V_22 = F_9 ( V_4 -> V_1 ,
V_23 | V_43 ,
V_42 | V_44 ,
V_4 -> V_45 , 1 ) ;
if ( V_22 )
return V_22 ;
F_10 ( V_4 -> V_1 ,
V_4 -> V_30 * V_4 -> V_32 ) ;
return 0 ;
default:
return - V_46 ;
}
return - V_47 ;
}
static enum V_48 F_11 ( struct V_2 * V_3 ,
T_1 V_9 ,
struct V_49 * V_50 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_51 ;
enum V_48 V_22 ;
V_51 = V_3 -> V_9 ;
V_22 = F_12 ( V_9 , V_4 -> V_8 , V_51 ) ;
F_13 ( V_50 , V_4 -> V_8 , V_51 , 0 ) ;
return V_22 ;
}
static T_1 F_14 ( struct V_1 * V_52 )
{
T_1 V_9 = V_52 -> V_3 . V_9 ;
if ( ++ V_9 < 0 )
V_9 = 1 ;
V_52 -> V_3 . V_9 = V_9 ;
V_52 -> V_5 . V_9 = V_9 ;
return V_9 ;
}
static T_1 F_15 ( struct V_53 * V_54 )
{
struct V_1 * V_4 = F_1 ( V_54 -> V_3 ) ;
T_1 V_9 ;
F_16 ( & V_4 -> V_55 ) ;
V_9 = F_14 ( V_4 ) ;
F_17 ( V_4 -> V_1 ) ;
F_18 ( & V_4 -> V_55 ) ;
return V_9 ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_56 * V_11 = V_3 -> V_57 ;
V_4 -> V_45 = V_11 -> V_45 ;
F_20 ( & V_4 -> V_5 , V_3 ) ;
V_4 -> V_5 . V_58 = F_15 ;
V_4 -> V_5 . V_59 = V_60 ;
V_4 -> V_12 = V_13 ;
return 0 ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_8 ( V_4 -> V_1 ) ;
if ( V_4 -> V_61 ) {
F_22 ( V_4 -> V_61 ) ;
V_4 -> V_61 = NULL ;
}
}
static struct V_53 * F_23 (
struct V_2 * V_3 , struct V_15 * V_62 ,
unsigned int V_63 , enum V_64 V_26 ,
unsigned long V_59 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_15 * V_16 ;
int V_65 , V_22 , V_66 = 0 ;
unsigned int V_67 ;
if ( V_4 -> V_12 == V_68 )
return NULL ;
V_4 -> V_12 = V_68 ;
F_24 (sgl, sg, sg_len, i) {
V_66 += V_16 -> V_69 ;
}
if ( V_26 == V_27 )
V_67 = V_70 ;
else
V_67 = V_71 ;
switch ( V_4 -> V_32 ) {
case V_41 :
if ( V_62 -> V_69 & 3 || V_62 -> V_72 & 3 )
return NULL ;
break;
case V_39 :
if ( V_62 -> V_69 & 1 || V_62 -> V_72 & 1 )
return NULL ;
break;
case V_37 :
break;
default:
return NULL ;
}
V_22 = F_25 ( V_4 -> V_1 , V_62 , V_63 ,
V_66 , V_4 -> V_28 , V_67 ) ;
if ( V_22 )
return NULL ;
return & V_4 -> V_5 ;
}
static struct V_53 * F_26 (
struct V_2 * V_3 , T_2 V_73 , T_3 V_74 ,
T_3 V_75 , enum V_64 V_26 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_76 * V_52 = V_4 -> V_52 ;
int V_65 , V_22 ;
unsigned int V_77 = V_74 / V_75 ;
unsigned int V_67 ;
F_27 ( V_52 -> V_78 , L_1 ,
V_79 , V_4 -> V_10 , V_74 , V_75 ) ;
if ( V_4 -> V_12 == V_68 )
return NULL ;
V_4 -> V_12 = V_68 ;
V_22 = F_28 ( V_4 -> V_1 ,
F_6 ) ;
if ( V_22 ) {
F_29 ( V_52 -> V_78 , L_2 ) ;
return NULL ;
}
if ( V_4 -> V_61 )
F_22 ( V_4 -> V_61 ) ;
V_4 -> V_61 = F_30 ( V_77 + 1 ,
sizeof( struct V_15 ) , V_80 ) ;
if ( ! V_4 -> V_61 )
return NULL ;
F_31 ( V_4 -> V_61 , V_77 ) ;
for ( V_65 = 0 ; V_65 < V_77 ; V_65 ++ ) {
V_4 -> V_61 [ V_65 ] . V_81 = 0 ;
V_4 -> V_61 [ V_65 ] . V_82 = 0 ;
V_4 -> V_61 [ V_65 ] . V_72 = V_73 ;
V_4 -> V_61 [ V_65 ] . V_69 = V_75 ;
V_73 += V_75 ;
}
V_4 -> V_61 [ V_77 ] . V_82 = 0 ;
V_4 -> V_61 [ V_77 ] . V_69 = 0 ;
V_4 -> V_61 [ V_77 ] . V_81 =
( ( unsigned long ) V_4 -> V_61 | 0x01 ) & ~ 0x02 ;
if ( V_26 == V_27 )
V_67 = V_70 ;
else
V_67 = V_71 ;
V_22 = F_25 ( V_4 -> V_1 , V_4 -> V_61 , V_77 ,
V_83 , V_4 -> V_28 , V_67 ) ;
if ( V_22 )
return NULL ;
return & V_4 -> V_5 ;
}
static void F_32 ( struct V_2 * V_3 )
{
}
static int T_4 F_33 ( struct V_84 * V_85 )
{
struct V_76 * V_52 ;
int V_22 , V_65 ;
V_52 = F_34 ( sizeof( * V_52 ) , V_80 ) ;
if ( ! V_52 )
return - V_86 ;
F_35 ( & V_52 -> V_87 . V_88 ) ;
F_36 ( V_89 , V_52 -> V_87 . V_90 ) ;
F_36 ( V_91 , V_52 -> V_87 . V_90 ) ;
for ( V_65 = 0 ; V_65 < V_92 ; V_65 ++ ) {
struct V_1 * V_4 = & V_52 -> V_10 [ V_65 ] ;
V_4 -> V_1 = F_37 ( L_3 ,
V_93 ) ;
if ( ( int ) V_4 -> V_10 < 0 ) {
V_22 = - V_94 ;
goto V_95;
}
F_38 ( V_4 -> V_1 ,
F_4 , F_5 , V_4 ) ;
V_4 -> V_52 = V_52 ;
F_39 ( & V_4 -> V_55 ) ;
V_4 -> V_3 . V_96 = & V_52 -> V_87 ;
V_4 -> V_10 = V_65 ;
F_40 ( & V_4 -> V_3 . V_97 , & V_52 -> V_87 . V_88 ) ;
}
V_52 -> V_78 = & V_85 -> V_78 ;
V_52 -> V_87 . V_78 = & V_85 -> V_78 ;
V_52 -> V_87 . V_98 = F_19 ;
V_52 -> V_87 . V_99 = F_21 ;
V_52 -> V_87 . V_100 = F_11 ;
V_52 -> V_87 . V_101 = F_23 ;
V_52 -> V_87 . V_102 = F_26 ;
V_52 -> V_87 . V_103 = F_7 ;
V_52 -> V_87 . V_104 = F_32 ;
F_41 ( V_85 , V_52 ) ;
V_52 -> V_87 . V_78 -> V_105 = & V_52 -> V_105 ;
F_42 ( V_52 -> V_87 . V_78 , 0xffffff ) ;
V_22 = F_43 ( & V_52 -> V_87 ) ;
if ( V_22 ) {
F_29 ( & V_85 -> V_78 , L_4 ) ;
goto V_95;
}
return 0 ;
V_95:
while ( -- V_65 >= 0 ) {
struct V_1 * V_4 = & V_52 -> V_10 [ V_65 ] ;
F_44 ( V_4 -> V_1 ) ;
}
F_22 ( V_52 ) ;
return V_22 ;
}
static int T_5 F_45 ( struct V_84 * V_85 )
{
struct V_76 * V_52 = F_46 ( V_85 ) ;
int V_65 ;
F_47 ( & V_52 -> V_87 ) ;
for ( V_65 = 0 ; V_65 < V_92 ; V_65 ++ ) {
struct V_1 * V_4 = & V_52 -> V_10 [ V_65 ] ;
F_44 ( V_4 -> V_1 ) ;
}
F_22 ( V_52 ) ;
return 0 ;
}
static int T_4 F_48 ( void )
{
return F_49 ( & V_106 , F_33 ) ;
}
