static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
int V_12 ;
V_12 = F_3 ( V_2 , F_4 ( V_4 ) ) ;
if ( V_12 < 0 )
return V_12 ;
F_5 ( V_6 -> V_13 -> V_14 ,
L_1
L_2 ,
( unsigned long ) V_8 -> V_15 ,
( unsigned long ) V_8 -> V_16 , V_8 -> V_17 ,
V_8 -> V_18 ) ;
F_5 ( V_6 -> V_13 -> V_14 ,
L_3 ,
F_6 ( V_4 ) , F_7 ( V_4 ) ,
V_2 -> V_19 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_20 = 0 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
V_10 -> V_16 = V_8 -> V_16 ;
V_10 -> V_21 = F_11 ( V_2 ) ;
V_10 -> V_22 = F_12 ( V_2 ) ;
if ( V_10 -> V_21 == V_10 -> V_22 ) {
V_10 -> V_23 = V_10 -> V_22 >> 1 ;
V_10 -> V_24 = 2 ;
} else {
V_10 -> V_23 = V_10 -> V_22 ;
V_10 -> V_24 = V_10 -> V_21 / V_10 -> V_22 ;
}
V_10 -> V_25 = 0 ;
V_10 -> V_20 = 0 ;
return 0 ;
}
static void F_13 ( void * V_26 )
{
struct V_9 * V_10 = V_26 ;
unsigned long V_27 ;
F_14 ( & V_10 -> V_28 , V_27 ) ;
if ( V_10 -> V_25 >= 0 ) {
V_10 -> V_29 -- ;
F_15 ( V_10 -> V_29 < 0 ) ;
F_16 ( & V_10 -> V_30 ) ;
}
F_17 ( & V_10 -> V_28 , V_27 ) ;
}
static struct V_31 *
F_18 ( struct V_9 * V_10 , T_1 V_32 )
{
struct V_33 * V_34 = V_10 -> V_33 ;
struct V_31 * V_35 ;
struct V_36 V_37 ;
F_19 ( & V_37 , 1 ) ;
F_20 ( & V_37 , F_21 ( F_22 ( V_32 ) ) ,
V_10 -> V_23 , V_32 & ( V_38 - 1 ) ) ;
F_23 ( & V_37 ) = V_32 ;
V_35 = V_34 -> V_39 -> V_40 ( V_34 , & V_37 , 1 ,
V_10 -> V_2 -> V_19 == V_41 ?
V_42 : V_43 ,
V_44 | V_45 ) ;
if ( ! V_35 ) {
F_24 ( & V_34 -> V_14 -> V_39 , L_4 ) ;
return NULL ;
}
V_35 -> V_46 = F_13 ;
V_35 -> V_47 = V_10 ;
V_35 -> V_48 ( V_35 ) ;
return V_35 ;
}
static void F_25 ( unsigned long V_49 )
{
struct V_9 * V_10 = (struct V_9 * ) V_49 ;
struct V_33 * V_34 = V_10 -> V_33 ;
struct V_31 * V_35 ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_50 = V_2 -> V_19 == V_41 ?
V_51 : V_52 ;
int V_53 ;
unsigned long V_27 ;
F_14 ( & V_10 -> V_28 , V_27 ) ;
if ( V_10 -> V_25 < 0 ) {
struct V_54 * V_55 = V_56 ;
void T_3 * V_57 = V_55 -> V_57 ;
F_17 ( & V_10 -> V_28 , V_27 ) ;
V_34 -> V_39 -> V_58 ( V_34 , V_59 , 0 ) ;
for ( V_53 = 0 ; V_53 < V_60 ; V_53 ++ ) {
V_35 = F_18 ( V_10 ,
V_10 -> V_16 + V_53 * V_10 -> V_23 ) ;
if ( ! V_35 )
return;
}
V_10 -> V_29 = V_60 ;
V_34 -> V_39 -> V_61 ( V_34 ) ;
F_14 ( & V_10 -> V_28 , V_27 ) ;
F_26 ( V_50 , V_57 + V_62 ) ;
V_10 -> V_25 = V_60 % V_10 -> V_24 ;
F_17 ( & V_10 -> V_28 , V_27 ) ;
return;
}
F_15 ( V_10 -> V_29 >= V_60 ) ;
while ( V_10 -> V_29 < V_60 ) {
V_10 -> V_29 ++ ;
F_17 ( & V_10 -> V_28 , V_27 ) ;
V_35 = F_18 ( V_10 ,
V_10 -> V_16 +
V_10 -> V_25 * V_10 -> V_23 ) ;
if ( ! V_35 )
return;
V_34 -> V_39 -> V_61 ( V_34 ) ;
F_14 ( & V_10 -> V_28 , V_27 ) ;
V_10 -> V_25 ++ ;
V_10 -> V_25 %= V_10 -> V_24 ;
V_10 -> V_20 += V_10 -> V_23 ;
V_10 -> V_20 %= V_10 -> V_21 ;
if ( ( V_10 -> V_25 * V_10 -> V_23 ) %
V_10 -> V_22 == 0 )
F_27 ( V_2 ) ;
}
F_17 ( & V_10 -> V_28 , V_27 ) ;
}
static int F_28 ( struct V_1 * V_2 , int V_63 )
{
struct V_9 * V_10 = V_2 -> V_8 -> V_11 ;
struct V_54 * V_55 = V_56 ;
void T_3 * V_57 = V_55 -> V_57 ;
unsigned long V_27 ;
int V_12 = 0 ;
T_2 V_50 = V_2 -> V_19 == V_41 ?
V_51 : V_52 ;
F_14 ( & V_10 -> V_28 , V_27 ) ;
switch ( V_63 ) {
case V_64 :
V_10 -> V_25 = - 1 ;
F_16 ( & V_10 -> V_30 ) ;
break;
case V_65 :
case V_66 :
case V_67 :
F_26 ( V_50 , V_57 + V_68 ) ;
break;
case V_69 :
case V_70 :
F_26 ( V_50 , V_57 + V_62 ) ;
break;
default:
V_12 = - V_71 ;
}
F_17 ( & V_10 -> V_28 , V_27 ) ;
return V_12 ;
}
static T_4
F_29 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_8 -> V_11 ;
return F_30 ( V_2 -> V_8 , V_10 -> V_20 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_72 * V_14 = & V_72 ;
struct V_9 * V_10 = & V_14 -> V_10 [ V_2 -> V_19 ] ;
int V_12 ;
V_12 = F_32 ( V_2 , & V_73 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_33 ( V_2 -> V_8 ,
V_74 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 -> V_8 -> V_11 = V_10 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_8 -> V_11 ;
struct V_33 * V_34 = V_10 -> V_33 ;
V_10 -> V_25 = - 1 ;
V_34 -> V_39 -> V_58 ( V_34 , V_59 , 0 ) ;
return 0 ;
}
static void F_35 ( struct V_75 * V_76 )
{
F_36 ( V_76 ) ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_77 * V_78 = V_6 -> V_78 -> V_77 ;
struct V_79 * V_80 = V_6 -> V_81 ;
struct V_75 * V_76 = V_6 -> V_76 ;
struct V_82 * V_83 = F_38 ( V_80 -> V_13 -> V_14 ) ;
struct V_72 * V_14 ;
struct V_84 * V_85 ;
int V_53 ;
int V_12 ;
V_14 = F_39 ( V_80 ) ;
V_14 -> V_10 [ 0 ] . V_19 = V_41 ;
V_14 -> V_10 [ 1 ] . V_19 = V_86 ;
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ ) {
V_85 = F_40 ( V_83 , V_87 , V_53 ) ;
if ( ! V_85 ) {
V_12 = - V_88 ;
goto exit;
}
V_14 -> V_10 [ V_53 ] . V_89 = V_85 ;
V_12 = F_41 ( V_14 , & V_14 -> V_10 [ V_53 ] ) ;
if ( V_12 )
goto exit;
}
return F_42 ( V_76 , V_90 ,
V_78 -> V_14 , 64 * 1024 , 4 * 1024 * 1024 ) ;
exit:
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ ) {
if ( V_14 -> V_10 [ V_53 ] . V_33 )
F_43 ( V_14 -> V_10 [ V_53 ] . V_33 ) ;
V_14 -> V_10 [ V_53 ] . V_33 = NULL ;
}
return V_12 ;
}
static bool F_44 ( struct V_33 * V_34 , void * V_91 )
{
struct V_9 * V_10 = V_91 ;
char * V_92 ;
bool V_93 = false ;
V_92 = F_45 ( V_94 , L_5 , V_10 -> V_89 -> V_95 ,
( int ) V_10 -> V_89 -> V_96 ) ;
if ( strcmp ( F_46 ( V_34 -> V_39 -> V_14 ) , V_92 ) == 0 ) {
V_34 -> V_97 = & V_10 -> V_98 ;
V_93 = true ;
}
F_47 ( V_92 ) ;
return V_93 ;
}
static int F_41 ( struct V_72 * V_14 ,
struct V_9 * V_10 )
{
struct V_54 * V_55 = V_56 ;
struct V_99 * V_100 = & V_10 -> V_98 ;
T_5 V_101 ;
F_48 ( & V_10 -> V_28 ) ;
V_100 -> V_102 = sizeof( T_2 ) ;
if ( V_10 -> V_19 == V_41 ) {
V_100 -> V_103 = V_55 -> V_104 + V_105 ;
V_100 -> V_106 = 0 ;
} else {
V_100 -> V_103 = 0 ;
V_100 -> V_106 = V_55 -> V_104 + V_107 ;
}
F_49 ( V_101 ) ;
F_50 ( V_108 , V_101 ) ;
V_10 -> V_33 = F_51 ( V_101 , F_44 , V_10 ) ;
if ( ! V_10 -> V_33 ) {
F_52 ( V_109
L_6 ,
V_10 -> V_19 == V_41 ?
L_7 : L_8 ) ;
return - V_88 ;
}
F_53 ( & V_10 -> V_30 , F_25 ,
( unsigned long ) V_10 ) ;
return 0 ;
}
static int F_54 ( struct V_110 * V_13 )
{
F_55 ( V_13 , & V_72 ) ;
return 0 ;
}
static int F_56 ( struct V_110 * V_13 )
{
struct V_72 * V_14 = F_57 ( V_13 ) ;
struct V_54 * V_55 = V_56 ;
void T_3 * V_57 = V_55 -> V_57 ;
int V_53 ;
F_26 ( V_51 | V_52 , V_57 + V_68 ) ;
F_26 ( F_58 ( V_57 + V_107 ) , V_57 + V_105 ) ;
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ ) {
struct V_9 * V_10 = & V_14 -> V_10 [ V_53 ] ;
struct V_33 * V_34 = V_10 -> V_33 ;
if ( V_34 ) {
V_10 -> V_25 = - 1 ;
V_34 -> V_39 -> V_58 ( V_34 ,
V_59 , 0 ) ;
F_43 ( V_34 ) ;
}
V_14 -> V_10 [ V_53 ] . V_33 = NULL ;
}
return 0 ;
}
static int T_6 F_59 ( struct V_82 * V_83 )
{
return F_60 ( & V_83 -> V_14 , & V_111 ) ;
}
static int T_7 F_61 ( struct V_82 * V_83 )
{
F_62 ( & V_83 -> V_14 ) ;
return 0 ;
}
