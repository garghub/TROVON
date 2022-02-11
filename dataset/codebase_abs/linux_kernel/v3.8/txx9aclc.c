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
V_35 = F_24 ( V_34 , & V_37 , 1 ,
V_10 -> V_2 -> V_19 == V_39 ?
V_40 : V_41 ,
V_42 | V_43 ) ;
if ( ! V_35 ) {
F_25 ( & V_34 -> V_14 -> V_44 , L_4 ) ;
return NULL ;
}
V_35 -> V_45 = F_13 ;
V_35 -> V_46 = V_10 ;
V_35 -> V_47 ( V_35 ) ;
return V_35 ;
}
static void F_26 ( unsigned long V_48 )
{
struct V_9 * V_10 = (struct V_9 * ) V_48 ;
struct V_33 * V_34 = V_10 -> V_33 ;
struct V_31 * V_35 ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_49 = V_2 -> V_19 == V_39 ?
V_50 : V_51 ;
int V_52 ;
unsigned long V_27 ;
F_14 ( & V_10 -> V_28 , V_27 ) ;
if ( V_10 -> V_25 < 0 ) {
struct V_53 * V_54 = V_55 ;
void T_3 * V_56 = V_54 -> V_56 ;
F_17 ( & V_10 -> V_28 , V_27 ) ;
V_34 -> V_44 -> V_57 ( V_34 , V_58 , 0 ) ;
for ( V_52 = 0 ; V_52 < V_59 ; V_52 ++ ) {
V_35 = F_18 ( V_10 ,
V_10 -> V_16 + V_52 * V_10 -> V_23 ) ;
if ( ! V_35 )
return;
}
V_10 -> V_29 = V_59 ;
V_34 -> V_44 -> V_60 ( V_34 ) ;
F_14 ( & V_10 -> V_28 , V_27 ) ;
F_27 ( V_49 , V_56 + V_61 ) ;
V_10 -> V_25 = V_59 % V_10 -> V_24 ;
F_17 ( & V_10 -> V_28 , V_27 ) ;
return;
}
F_15 ( V_10 -> V_29 >= V_59 ) ;
while ( V_10 -> V_29 < V_59 ) {
V_10 -> V_29 ++ ;
F_17 ( & V_10 -> V_28 , V_27 ) ;
V_35 = F_18 ( V_10 ,
V_10 -> V_16 +
V_10 -> V_25 * V_10 -> V_23 ) ;
if ( ! V_35 )
return;
V_34 -> V_44 -> V_60 ( V_34 ) ;
F_14 ( & V_10 -> V_28 , V_27 ) ;
V_10 -> V_25 ++ ;
V_10 -> V_25 %= V_10 -> V_24 ;
V_10 -> V_20 += V_10 -> V_23 ;
V_10 -> V_20 %= V_10 -> V_21 ;
if ( ( V_10 -> V_25 * V_10 -> V_23 ) %
V_10 -> V_22 == 0 )
F_28 ( V_2 ) ;
}
F_17 ( & V_10 -> V_28 , V_27 ) ;
}
static int F_29 ( struct V_1 * V_2 , int V_62 )
{
struct V_9 * V_10 = V_2 -> V_8 -> V_11 ;
struct V_53 * V_54 = V_55 ;
void T_3 * V_56 = V_54 -> V_56 ;
unsigned long V_27 ;
int V_12 = 0 ;
T_2 V_49 = V_2 -> V_19 == V_39 ?
V_50 : V_51 ;
F_14 ( & V_10 -> V_28 , V_27 ) ;
switch ( V_62 ) {
case V_63 :
V_10 -> V_25 = - 1 ;
F_16 ( & V_10 -> V_30 ) ;
break;
case V_64 :
case V_65 :
case V_66 :
F_27 ( V_49 , V_56 + V_67 ) ;
break;
case V_68 :
case V_69 :
F_27 ( V_49 , V_56 + V_61 ) ;
break;
default:
V_12 = - V_70 ;
}
F_17 ( & V_10 -> V_28 , V_27 ) ;
return V_12 ;
}
static T_4
F_30 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_8 -> V_11 ;
return F_31 ( V_2 -> V_8 , V_10 -> V_20 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_71 * V_14 = & V_71 ;
struct V_9 * V_10 = & V_14 -> V_10 [ V_2 -> V_19 ] ;
int V_12 ;
V_12 = F_33 ( V_2 , & V_72 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_34 ( V_2 -> V_8 ,
V_73 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 -> V_8 -> V_11 = V_10 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_8 -> V_11 ;
struct V_33 * V_34 = V_10 -> V_33 ;
V_10 -> V_25 = - 1 ;
V_34 -> V_44 -> V_57 ( V_34 , V_58 , 0 ) ;
return 0 ;
}
static void F_36 ( struct V_74 * V_75 )
{
F_37 ( V_75 ) ;
}
static int F_38 ( struct V_5 * V_6 )
{
struct V_76 * V_77 = V_6 -> V_77 -> V_76 ;
struct V_78 * V_79 = V_6 -> V_80 ;
struct V_74 * V_75 = V_6 -> V_75 ;
struct V_81 * V_82 = F_39 ( V_79 -> V_13 -> V_14 ) ;
struct V_71 * V_14 ;
struct V_83 * V_84 ;
int V_52 ;
int V_12 ;
V_14 = F_40 ( V_79 ) ;
V_14 -> V_10 [ 0 ] . V_19 = V_39 ;
V_14 -> V_10 [ 1 ] . V_19 = V_85 ;
for ( V_52 = 0 ; V_52 < 2 ; V_52 ++ ) {
V_84 = F_41 ( V_82 , V_86 , V_52 ) ;
if ( ! V_84 ) {
V_12 = - V_87 ;
goto exit;
}
V_14 -> V_10 [ V_52 ] . V_88 = V_84 ;
V_12 = F_42 ( V_14 , & V_14 -> V_10 [ V_52 ] ) ;
if ( V_12 )
goto exit;
}
return F_43 ( V_75 , V_89 ,
V_77 -> V_14 , 64 * 1024 , 4 * 1024 * 1024 ) ;
exit:
for ( V_52 = 0 ; V_52 < 2 ; V_52 ++ ) {
if ( V_14 -> V_10 [ V_52 ] . V_33 )
F_44 ( V_14 -> V_10 [ V_52 ] . V_33 ) ;
V_14 -> V_10 [ V_52 ] . V_33 = NULL ;
}
return V_12 ;
}
static bool F_45 ( struct V_33 * V_34 , void * V_90 )
{
struct V_9 * V_10 = V_90 ;
char * V_91 ;
bool V_92 = false ;
V_91 = F_46 ( V_93 , L_5 , V_10 -> V_88 -> V_94 ,
( int ) V_10 -> V_88 -> V_95 ) ;
if ( strcmp ( F_47 ( V_34 -> V_44 -> V_14 ) , V_91 ) == 0 ) {
V_34 -> V_96 = & V_10 -> V_97 ;
V_92 = true ;
}
F_48 ( V_91 ) ;
return V_92 ;
}
static int F_42 ( struct V_71 * V_14 ,
struct V_9 * V_10 )
{
struct V_53 * V_54 = V_55 ;
struct V_98 * V_99 = & V_10 -> V_97 ;
T_5 V_100 ;
F_49 ( & V_10 -> V_28 ) ;
V_99 -> V_101 = sizeof( T_2 ) ;
if ( V_10 -> V_19 == V_39 ) {
V_99 -> V_102 = V_54 -> V_103 + V_104 ;
V_99 -> V_105 = 0 ;
} else {
V_99 -> V_102 = 0 ;
V_99 -> V_105 = V_54 -> V_103 + V_106 ;
}
F_50 ( V_100 ) ;
F_51 ( V_107 , V_100 ) ;
V_10 -> V_33 = F_52 ( V_100 , F_45 , V_10 ) ;
if ( ! V_10 -> V_33 ) {
F_53 ( V_108
L_6 ,
V_10 -> V_19 == V_39 ?
L_7 : L_8 ) ;
return - V_87 ;
}
F_54 ( & V_10 -> V_30 , F_26 ,
( unsigned long ) V_10 ) ;
return 0 ;
}
static int F_55 ( struct V_109 * V_13 )
{
F_56 ( V_13 , & V_71 ) ;
return 0 ;
}
static int F_57 ( struct V_109 * V_13 )
{
struct V_71 * V_14 = F_58 ( V_13 ) ;
struct V_53 * V_54 = V_55 ;
void T_3 * V_56 = V_54 -> V_56 ;
int V_52 ;
F_27 ( V_50 | V_51 , V_56 + V_67 ) ;
F_27 ( F_59 ( V_56 + V_106 ) , V_56 + V_104 ) ;
for ( V_52 = 0 ; V_52 < 2 ; V_52 ++ ) {
struct V_9 * V_10 = & V_14 -> V_10 [ V_52 ] ;
struct V_33 * V_34 = V_10 -> V_33 ;
if ( V_34 ) {
V_10 -> V_25 = - 1 ;
V_34 -> V_44 -> V_57 ( V_34 ,
V_58 , 0 ) ;
F_44 ( V_34 ) ;
}
V_14 -> V_10 [ V_52 ] . V_33 = NULL ;
}
return 0 ;
}
static int F_60 ( struct V_81 * V_82 )
{
return F_61 ( & V_82 -> V_14 , & V_110 ) ;
}
static int F_62 ( struct V_81 * V_82 )
{
F_63 ( & V_82 -> V_14 ) ;
return 0 ;
}
