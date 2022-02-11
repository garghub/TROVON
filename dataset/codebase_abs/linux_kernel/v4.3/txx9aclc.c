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
if ( ! F_15 ( V_10 -> V_29 < 0 ) )
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
F_26 ( V_35 ) ;
return V_35 ;
}
static void F_27 ( unsigned long V_47 )
{
struct V_9 * V_10 = (struct V_9 * ) V_47 ;
struct V_33 * V_34 = V_10 -> V_33 ;
struct V_31 * V_35 ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_48 = V_2 -> V_19 == V_39 ?
V_49 : V_50 ;
int V_51 ;
unsigned long V_27 ;
F_14 ( & V_10 -> V_28 , V_27 ) ;
if ( V_10 -> V_25 < 0 ) {
struct V_52 * V_53 = V_54 ;
void T_3 * V_55 = V_53 -> V_55 ;
F_17 ( & V_10 -> V_28 , V_27 ) ;
F_28 ( V_34 ) ;
for ( V_51 = 0 ; V_51 < V_56 ; V_51 ++ ) {
V_35 = F_18 ( V_10 ,
V_10 -> V_16 + V_51 * V_10 -> V_23 ) ;
if ( ! V_35 )
return;
}
V_10 -> V_29 = V_56 ;
F_29 ( V_34 ) ;
F_14 ( & V_10 -> V_28 , V_27 ) ;
F_30 ( V_48 , V_55 + V_57 ) ;
V_10 -> V_25 = V_56 % V_10 -> V_24 ;
F_17 ( & V_10 -> V_28 , V_27 ) ;
return;
}
if ( F_15 ( V_10 -> V_29 >= V_56 ) ) {
F_17 ( & V_10 -> V_28 , V_27 ) ;
return;
}
while ( V_10 -> V_29 < V_56 ) {
V_10 -> V_29 ++ ;
F_17 ( & V_10 -> V_28 , V_27 ) ;
V_35 = F_18 ( V_10 ,
V_10 -> V_16 +
V_10 -> V_25 * V_10 -> V_23 ) ;
if ( ! V_35 )
return;
F_29 ( V_34 ) ;
F_14 ( & V_10 -> V_28 , V_27 ) ;
V_10 -> V_25 ++ ;
V_10 -> V_25 %= V_10 -> V_24 ;
V_10 -> V_20 += V_10 -> V_23 ;
V_10 -> V_20 %= V_10 -> V_21 ;
if ( ( V_10 -> V_25 * V_10 -> V_23 ) %
V_10 -> V_22 == 0 )
F_31 ( V_2 ) ;
}
F_17 ( & V_10 -> V_28 , V_27 ) ;
}
static int F_32 ( struct V_1 * V_2 , int V_58 )
{
struct V_9 * V_10 = V_2 -> V_8 -> V_11 ;
struct V_52 * V_53 = V_54 ;
void T_3 * V_55 = V_53 -> V_55 ;
unsigned long V_27 ;
int V_12 = 0 ;
T_2 V_48 = V_2 -> V_19 == V_39 ?
V_49 : V_50 ;
F_14 ( & V_10 -> V_28 , V_27 ) ;
switch ( V_58 ) {
case V_59 :
V_10 -> V_25 = - 1 ;
F_16 ( & V_10 -> V_30 ) ;
break;
case V_60 :
case V_61 :
case V_62 :
F_30 ( V_48 , V_55 + V_63 ) ;
break;
case V_64 :
case V_65 :
F_30 ( V_48 , V_55 + V_57 ) ;
break;
default:
V_12 = - V_66 ;
}
F_17 ( & V_10 -> V_28 , V_27 ) ;
return V_12 ;
}
static T_4
F_33 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_8 -> V_11 ;
return F_34 ( V_2 -> V_8 , V_10 -> V_20 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_67 * V_14 = & V_67 ;
struct V_9 * V_10 = & V_14 -> V_10 [ V_2 -> V_19 ] ;
int V_12 ;
V_12 = F_36 ( V_2 , & V_68 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_37 ( V_2 -> V_8 ,
V_69 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 -> V_8 -> V_11 = V_10 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_8 -> V_11 ;
struct V_33 * V_34 = V_10 -> V_33 ;
V_10 -> V_25 = - 1 ;
F_28 ( V_34 ) ;
return 0 ;
}
static int F_39 ( struct V_5 * V_6 )
{
struct V_70 * V_71 = V_6 -> V_71 -> V_70 ;
struct V_72 * V_73 = V_6 -> V_74 ;
struct V_75 * V_76 = V_6 -> V_76 ;
struct V_77 * V_78 = F_40 ( V_6 -> V_13 -> V_14 ) ;
struct V_67 * V_14 ;
struct V_79 * V_80 ;
int V_51 ;
int V_12 ;
V_14 = F_41 ( V_73 ) ;
V_14 -> V_10 [ 0 ] . V_19 = V_39 ;
V_14 -> V_10 [ 1 ] . V_19 = V_81 ;
for ( V_51 = 0 ; V_51 < 2 ; V_51 ++ ) {
V_80 = F_42 ( V_78 , V_82 , V_51 ) ;
if ( ! V_80 ) {
V_12 = - V_83 ;
goto exit;
}
V_14 -> V_10 [ V_51 ] . V_84 = V_80 ;
V_12 = F_43 ( V_14 , & V_14 -> V_10 [ V_51 ] ) ;
if ( V_12 )
goto exit;
}
return F_44 ( V_76 , V_85 ,
V_71 -> V_14 , 64 * 1024 , 4 * 1024 * 1024 ) ;
exit:
for ( V_51 = 0 ; V_51 < 2 ; V_51 ++ ) {
if ( V_14 -> V_10 [ V_51 ] . V_33 )
F_45 ( V_14 -> V_10 [ V_51 ] . V_33 ) ;
V_14 -> V_10 [ V_51 ] . V_33 = NULL ;
}
return V_12 ;
}
static bool F_46 ( struct V_33 * V_34 , void * V_86 )
{
struct V_9 * V_10 = V_86 ;
char * V_87 ;
bool V_88 = false ;
V_87 = F_47 ( V_89 , L_5 , V_10 -> V_84 -> V_90 ,
( int ) V_10 -> V_84 -> V_91 ) ;
if ( strcmp ( F_48 ( V_34 -> V_44 -> V_14 ) , V_87 ) == 0 ) {
V_34 -> V_92 = & V_10 -> V_93 ;
V_88 = true ;
}
F_49 ( V_87 ) ;
return V_88 ;
}
static int F_43 ( struct V_67 * V_14 ,
struct V_9 * V_10 )
{
struct V_52 * V_53 = V_54 ;
struct V_94 * V_95 = & V_10 -> V_93 ;
T_5 V_96 ;
F_50 ( & V_10 -> V_28 ) ;
V_95 -> V_97 = sizeof( T_2 ) ;
if ( V_10 -> V_19 == V_39 ) {
V_95 -> V_98 = V_53 -> V_99 + V_100 ;
V_95 -> V_101 = 0 ;
} else {
V_95 -> V_98 = 0 ;
V_95 -> V_101 = V_53 -> V_99 + V_102 ;
}
F_51 ( V_96 ) ;
F_52 ( V_103 , V_96 ) ;
V_10 -> V_33 = F_53 ( V_96 , F_46 , V_10 ) ;
if ( ! V_10 -> V_33 ) {
F_54 ( V_104
L_6 ,
V_10 -> V_19 == V_39 ?
L_7 : L_8 ) ;
return - V_83 ;
}
F_55 ( & V_10 -> V_30 , F_27 ,
( unsigned long ) V_10 ) ;
return 0 ;
}
static int F_56 ( struct V_105 * V_13 )
{
F_57 ( V_13 , & V_67 ) ;
return 0 ;
}
static int F_58 ( struct V_105 * V_13 )
{
struct V_67 * V_14 = F_59 ( V_13 ) ;
struct V_52 * V_53 = V_54 ;
void T_3 * V_55 = V_53 -> V_55 ;
int V_51 ;
F_30 ( V_49 | V_50 , V_55 + V_63 ) ;
F_30 ( F_60 ( V_55 + V_102 ) , V_55 + V_100 ) ;
for ( V_51 = 0 ; V_51 < 2 ; V_51 ++ ) {
struct V_9 * V_10 = & V_14 -> V_10 [ V_51 ] ;
struct V_33 * V_34 = V_10 -> V_33 ;
if ( V_34 ) {
V_10 -> V_25 = - 1 ;
F_28 ( V_34 ) ;
F_45 ( V_34 ) ;
}
V_14 -> V_10 [ V_51 ] . V_33 = NULL ;
}
return 0 ;
}
static int F_61 ( struct V_77 * V_78 )
{
return F_62 ( & V_78 -> V_14 ,
& V_106 ) ;
}
