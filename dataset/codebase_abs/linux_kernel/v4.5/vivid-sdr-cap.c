static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
F_2 ( V_2 , 1 , L_1 ) ;
if ( V_2 -> V_5 &&
F_3 ( 100 ) < V_2 -> V_5 )
return;
F_4 ( & V_2 -> V_6 ) ;
if ( ! F_5 ( & V_2 -> V_7 ) ) {
V_4 = F_6 ( V_2 -> V_7 . V_8 ,
struct V_3 , V_9 ) ;
F_7 ( & V_4 -> V_9 ) ;
}
F_8 ( & V_2 -> V_6 ) ;
if ( V_4 ) {
V_4 -> V_10 . V_11 = V_2 -> V_12 ;
F_9 ( V_2 , V_4 ) ;
V_4 -> V_10 . V_13 . V_14 =
F_10 () + V_2 -> V_15 ;
F_11 ( & V_4 -> V_10 . V_13 , V_2 -> V_16 ?
V_17 : V_18 ) ;
V_2 -> V_16 = false ;
}
}
static int F_12 ( void * V_19 )
{
struct V_1 * V_2 = V_19 ;
T_1 V_20 ;
T_1 V_21 ;
T_1 V_22 ;
unsigned long V_23 ;
unsigned long V_24 ;
unsigned V_25 ;
F_2 ( V_2 , 1 , L_2 ) ;
F_13 () ;
V_2 -> V_26 = 0 ;
if ( V_2 -> V_27 )
V_2 -> V_26 = 0xffffff80U ;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 = false ;
for (; ; ) {
F_14 () ;
if ( F_15 () )
break;
F_16 ( & V_2 -> V_31 ) ;
V_24 = V_29 ;
if ( V_2 -> V_30 ) {
V_2 -> V_28 = V_24 ;
V_2 -> V_26 = V_2 -> V_12 + 1 ;
V_2 -> V_12 = 0 ;
V_2 -> V_30 = false ;
}
V_23 = V_24 - V_2 -> V_28 ;
V_21 =
( T_1 ) V_23 * V_2 -> V_32 +
( V_33 * V_34 ) / 2 ;
F_17 ( V_21 , V_33 * V_34 ) ;
if ( V_23 > V_35 ) {
V_2 -> V_28 = V_24 ;
V_2 -> V_26 = V_21 ;
V_21 = 0 ;
}
V_2 -> V_12 =
V_21 + V_2 -> V_26 ;
F_1 ( V_2 ) ;
F_18 ( & V_2 -> V_31 ) ;
V_20 = V_21 * V_34 ;
V_23 = V_29 - V_2 -> V_28 ;
V_20 += V_34 ;
V_22 = V_20 * V_33 +
V_2 -> V_32 / 2 ;
F_17 ( V_22 , V_2 -> V_32 ) ;
if ( V_22 < V_23 )
V_22 = V_23 ;
V_25 = V_22 - V_23 ;
F_19 ( V_25 ? V_25 : 1 ) ;
}
F_2 ( V_2 , 1 , L_3 ) ;
return 0 ;
}
static int F_20 ( struct V_36 * V_37 ,
unsigned * V_38 , unsigned * V_39 ,
unsigned V_40 [] , void * V_41 [] )
{
V_40 [ 0 ] = V_34 * 2 ;
* V_39 = 1 ;
return 0 ;
}
static int F_21 ( struct V_42 * V_10 )
{
struct V_1 * V_2 = F_22 ( V_10 -> V_36 ) ;
unsigned V_43 = V_34 * 2 ;
F_2 ( V_2 , 1 , L_4 , V_44 ) ;
if ( V_2 -> V_45 ) {
V_2 -> V_45 = false ;
return - V_46 ;
}
if ( F_23 ( V_10 , 0 ) < V_43 ) {
F_2 ( V_2 , 1 , L_5 ,
V_44 , F_23 ( V_10 , 0 ) , V_43 ) ;
return - V_46 ;
}
F_24 ( V_10 , 0 , V_43 ) ;
return 0 ;
}
static void F_25 ( struct V_42 * V_10 )
{
struct V_47 * V_48 = F_26 ( V_10 ) ;
struct V_1 * V_2 = F_22 ( V_10 -> V_36 ) ;
struct V_3 * V_49 = F_27 ( V_48 , struct V_3 , V_10 ) ;
F_2 ( V_2 , 1 , L_4 , V_44 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_28 ( & V_49 -> V_9 , & V_2 -> V_7 ) ;
F_8 ( & V_2 -> V_6 ) ;
}
static int F_29 ( struct V_36 * V_37 , unsigned V_50 )
{
struct V_1 * V_2 = F_22 ( V_37 ) ;
int V_51 = 0 ;
F_2 ( V_2 , 1 , L_4 , V_44 ) ;
V_2 -> V_12 = 0 ;
if ( V_2 -> V_52 ) {
V_2 -> V_52 = false ;
V_51 = - V_46 ;
} else if ( V_2 -> V_53 == NULL ) {
V_2 -> V_53 = F_30 ( F_12 , V_2 ,
L_6 , V_2 -> V_54 . V_55 ) ;
if ( F_31 ( V_2 -> V_53 ) ) {
F_32 ( & V_2 -> V_54 , L_7 ) ;
V_51 = F_33 ( V_2 -> V_53 ) ;
V_2 -> V_53 = NULL ;
}
}
if ( V_51 ) {
struct V_3 * V_49 , * V_56 ;
F_34 (buf, tmp, &dev->sdr_cap_active, list) {
F_7 ( & V_49 -> V_9 ) ;
F_11 ( & V_49 -> V_10 . V_13 ,
V_57 ) ;
}
}
return V_51 ;
}
static void F_35 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_22 ( V_37 ) ;
if ( V_2 -> V_53 == NULL )
return;
while ( ! F_5 ( & V_2 -> V_7 ) ) {
struct V_3 * V_49 ;
V_49 = F_6 ( V_2 -> V_7 . V_8 ,
struct V_3 , V_9 ) ;
F_7 ( & V_49 -> V_9 ) ;
F_11 ( & V_49 -> V_10 . V_13 , V_17 ) ;
}
F_18 ( & V_2 -> V_31 ) ;
F_36 ( V_2 -> V_53 ) ;
V_2 -> V_53 = NULL ;
F_16 ( & V_2 -> V_31 ) ;
}
int F_37 ( struct V_58 * V_58 , void * V_59 ,
struct V_60 * V_61 )
{
switch ( V_61 -> V_62 ) {
case 0 :
if ( V_61 -> V_63 >= F_38 ( V_64 ) )
return - V_46 ;
* V_61 = V_64 [ V_61 -> V_63 ] ;
return 0 ;
case 1 :
if ( V_61 -> V_63 >= F_38 ( V_65 ) )
return - V_46 ;
* V_61 = V_65 [ V_61 -> V_63 ] ;
return 0 ;
default:
return - V_46 ;
}
}
int F_39 ( struct V_58 * V_58 , void * V_59 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_40 ( V_58 ) ;
switch ( V_67 -> V_62 ) {
case 0 :
V_67 -> V_68 = V_2 -> V_32 ;
V_67 -> type = V_69 ;
return 0 ;
case 1 :
V_67 -> V_68 = V_2 -> V_70 ;
V_67 -> type = V_71 ;
return 0 ;
default:
return - V_46 ;
}
}
int F_41 ( struct V_58 * V_58 , void * V_59 ,
const struct V_66 * V_67 )
{
struct V_1 * V_2 = F_40 ( V_58 ) ;
unsigned V_72 = V_67 -> V_68 ;
unsigned V_61 ;
switch ( V_67 -> V_62 ) {
case 0 :
if ( V_67 -> type != V_69 )
return - V_46 ;
if ( V_72 < V_73 )
V_61 = 0 ;
else if ( V_72 < V_74 )
V_61 = 1 ;
else
V_61 = 2 ;
V_72 = F_42 ( unsigned , V_72 ,
V_64 [ V_61 ] . V_75 ,
V_64 [ V_61 ] . V_76 ) ;
if ( F_43 ( & V_2 -> V_77 ) &&
V_72 != V_2 -> V_32 ) {
V_2 -> V_30 = true ;
}
V_2 -> V_32 = V_72 ;
return 0 ;
case 1 :
if ( V_67 -> type != V_71 )
return - V_46 ;
V_2 -> V_70 = F_42 ( unsigned , V_72 ,
V_65 [ 0 ] . V_75 ,
V_65 [ 0 ] . V_76 ) ;
return 0 ;
default:
return - V_46 ;
}
}
int F_44 ( struct V_58 * V_58 , void * V_59 , struct V_78 * V_79 )
{
switch ( V_79 -> V_63 ) {
case 0 :
F_45 ( V_79 -> V_55 , L_8 , sizeof( V_79 -> V_55 ) ) ;
V_79 -> type = V_69 ;
V_79 -> V_80 =
V_81 | V_82 ;
V_79 -> V_75 = V_64 [ 0 ] . V_75 ;
V_79 -> V_76 = V_64 [ 2 ] . V_76 ;
return 0 ;
case 1 :
F_45 ( V_79 -> V_55 , L_9 , sizeof( V_79 -> V_55 ) ) ;
V_79 -> type = V_71 ;
V_79 -> V_80 =
V_81 | V_82 ;
V_79 -> V_75 = V_65 [ 0 ] . V_75 ;
V_79 -> V_76 = V_65 [ 0 ] . V_76 ;
return 0 ;
default:
return - V_46 ;
}
}
int F_46 ( struct V_58 * V_58 , void * V_59 , const struct V_78 * V_79 )
{
if ( V_79 -> V_63 > 1 )
return - V_46 ;
return 0 ;
}
int F_47 ( struct V_58 * V_58 , void * V_59 , struct V_83 * V_84 )
{
if ( V_84 -> V_63 >= F_38 ( V_85 ) )
return - V_46 ;
V_84 -> V_86 = V_85 [ V_84 -> V_63 ] . V_86 ;
return 0 ;
}
int F_48 ( struct V_58 * V_58 , void * V_59 , struct V_87 * V_84 )
{
struct V_1 * V_2 = F_40 ( V_58 ) ;
V_84 -> V_88 . V_89 . V_86 = V_2 -> V_90 ;
V_84 -> V_88 . V_89 . V_91 = V_2 -> V_92 ;
memset ( V_84 -> V_88 . V_89 . V_93 , 0 , sizeof( V_84 -> V_88 . V_89 . V_93 ) ) ;
return 0 ;
}
int F_49 ( struct V_58 * V_58 , void * V_59 , struct V_87 * V_84 )
{
struct V_1 * V_2 = F_40 ( V_58 ) ;
struct V_36 * V_94 = & V_2 -> V_77 ;
int V_95 ;
if ( F_50 ( V_94 ) )
return - V_96 ;
memset ( V_84 -> V_88 . V_89 . V_93 , 0 , sizeof( V_84 -> V_88 . V_89 . V_93 ) ) ;
for ( V_95 = 0 ; V_95 < F_38 ( V_85 ) ; V_95 ++ ) {
if ( V_85 [ V_95 ] . V_86 == V_84 -> V_88 . V_89 . V_86 ) {
V_2 -> V_90 = V_85 [ V_95 ] . V_86 ;
V_2 -> V_92 = V_85 [ V_95 ] . V_91 ;
V_84 -> V_88 . V_89 . V_91 = V_85 [ V_95 ] . V_91 ;
return 0 ;
}
}
V_2 -> V_90 = V_85 [ 0 ] . V_86 ;
V_2 -> V_92 = V_85 [ 0 ] . V_91 ;
V_84 -> V_88 . V_89 . V_86 = V_85 [ 0 ] . V_86 ;
V_84 -> V_88 . V_89 . V_91 = V_85 [ 0 ] . V_91 ;
return 0 ;
}
int F_51 ( struct V_58 * V_58 , void * V_59 , struct V_87 * V_84 )
{
int V_95 ;
memset ( V_84 -> V_88 . V_89 . V_93 , 0 , sizeof( V_84 -> V_88 . V_89 . V_93 ) ) ;
for ( V_95 = 0 ; V_95 < F_38 ( V_85 ) ; V_95 ++ ) {
if ( V_85 [ V_95 ] . V_86 == V_84 -> V_88 . V_89 . V_86 ) {
V_84 -> V_88 . V_89 . V_91 = V_85 [ V_95 ] . V_91 ;
return 0 ;
}
}
V_84 -> V_88 . V_89 . V_86 = V_85 [ 0 ] . V_86 ;
V_84 -> V_88 . V_89 . V_91 = V_85 [ 0 ] . V_91 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 , struct V_3 * V_49 )
{
T_2 * V_48 = F_52 ( & V_49 -> V_10 . V_13 , 0 ) ;
unsigned long V_95 ;
unsigned long V_97 = F_23 ( & V_49 -> V_10 . V_13 , 0 ) ;
T_3 V_98 ;
T_4 V_99 ;
T_4 V_100 ;
T_4 V_101 ;
T_4 V_102 ;
#define F_53 1000
V_99 = F_54 ( V_103 * F_53 ,
V_2 -> V_32 ) ;
for ( V_95 = 0 ; V_95 < V_97 ; V_95 += 2 ) {
V_100 = F_55 ( V_2 -> V_104 ,
V_103 ) >> ( 31 - V_105 ) ;
V_2 -> V_104 += V_99 ;
V_98 = ( T_3 ) V_100 * V_2 -> V_106 ;
V_2 -> V_107 += F_56 ( V_98 , V_108 ) ;
V_2 -> V_104 %= V_103 ;
V_2 -> V_107 %= V_103 ;
if ( V_2 -> V_107 < 0 )
V_2 -> V_107 += V_103 ;
V_101 = F_55 ( V_2 -> V_107 , V_103 ) ;
V_102 = F_57 ( V_2 -> V_107 , V_103 ) ;
V_101 >>= ( 31 - V_105 ) ;
V_102 >>= ( 31 - V_105 ) ;
switch ( V_2 -> V_90 ) {
case V_109 :
V_101 = V_101 * 1275 + V_110 * 1275 ;
V_102 = V_102 * 1275 + V_110 * 1275 ;
* V_48 ++ = F_54 ( V_101 , V_110 * 10 ) ;
* V_48 ++ = F_54 ( V_102 , V_110 * 10 ) ;
break;
case V_111 :
V_101 = V_101 * 1275 - V_110 * 5 ;
V_102 = V_102 * 1275 - V_110 * 5 ;
* V_48 ++ = F_54 ( V_101 , V_110 * 10 ) ;
* V_48 ++ = F_54 ( V_102 , V_110 * 10 ) ;
break;
default:
break;
}
}
}
