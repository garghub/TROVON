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
unsigned V_40 [] , struct V_41 * V_42 [] )
{
V_40 [ 0 ] = V_34 * 2 ;
* V_39 = 1 ;
return 0 ;
}
static int F_21 ( struct V_43 * V_10 )
{
struct V_1 * V_2 = F_22 ( V_10 -> V_36 ) ;
unsigned V_44 = V_34 * 2 ;
F_2 ( V_2 , 1 , L_4 , V_45 ) ;
if ( V_2 -> V_46 ) {
V_2 -> V_46 = false ;
return - V_47 ;
}
if ( F_23 ( V_10 , 0 ) < V_44 ) {
F_2 ( V_2 , 1 , L_5 ,
V_45 , F_23 ( V_10 , 0 ) , V_44 ) ;
return - V_47 ;
}
F_24 ( V_10 , 0 , V_44 ) ;
return 0 ;
}
static void F_25 ( struct V_43 * V_10 )
{
struct V_48 * V_49 = F_26 ( V_10 ) ;
struct V_1 * V_2 = F_22 ( V_10 -> V_36 ) ;
struct V_3 * V_50 = F_27 ( V_49 , struct V_3 , V_10 ) ;
F_2 ( V_2 , 1 , L_4 , V_45 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_28 ( & V_50 -> V_9 , & V_2 -> V_7 ) ;
F_8 ( & V_2 -> V_6 ) ;
}
static int F_29 ( struct V_36 * V_37 , unsigned V_51 )
{
struct V_1 * V_2 = F_22 ( V_37 ) ;
int V_52 = 0 ;
F_2 ( V_2 , 1 , L_4 , V_45 ) ;
V_2 -> V_12 = 0 ;
if ( V_2 -> V_53 ) {
V_2 -> V_53 = false ;
V_52 = - V_47 ;
} else if ( V_2 -> V_54 == NULL ) {
V_2 -> V_54 = F_30 ( F_12 , V_2 ,
L_6 , V_2 -> V_55 . V_56 ) ;
if ( F_31 ( V_2 -> V_54 ) ) {
F_32 ( & V_2 -> V_55 , L_7 ) ;
V_52 = F_33 ( V_2 -> V_54 ) ;
V_2 -> V_54 = NULL ;
}
}
if ( V_52 ) {
struct V_3 * V_50 , * V_57 ;
F_34 (buf, tmp, &dev->sdr_cap_active, list) {
F_7 ( & V_50 -> V_9 ) ;
F_11 ( & V_50 -> V_10 . V_13 ,
V_58 ) ;
}
}
return V_52 ;
}
static void F_35 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_22 ( V_37 ) ;
if ( V_2 -> V_54 == NULL )
return;
while ( ! F_5 ( & V_2 -> V_7 ) ) {
struct V_3 * V_50 ;
V_50 = F_6 ( V_2 -> V_7 . V_8 ,
struct V_3 , V_9 ) ;
F_7 ( & V_50 -> V_9 ) ;
F_11 ( & V_50 -> V_10 . V_13 , V_17 ) ;
}
F_18 ( & V_2 -> V_31 ) ;
F_36 ( V_2 -> V_54 ) ;
V_2 -> V_54 = NULL ;
F_16 ( & V_2 -> V_31 ) ;
}
int F_37 ( struct V_59 * V_59 , void * V_60 ,
struct V_61 * V_62 )
{
switch ( V_62 -> V_63 ) {
case 0 :
if ( V_62 -> V_64 >= F_38 ( V_65 ) )
return - V_47 ;
* V_62 = V_65 [ V_62 -> V_64 ] ;
return 0 ;
case 1 :
if ( V_62 -> V_64 >= F_38 ( V_66 ) )
return - V_47 ;
* V_62 = V_66 [ V_62 -> V_64 ] ;
return 0 ;
default:
return - V_47 ;
}
}
int F_39 ( struct V_59 * V_59 , void * V_60 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = F_40 ( V_59 ) ;
switch ( V_68 -> V_63 ) {
case 0 :
V_68 -> V_69 = V_2 -> V_32 ;
V_68 -> type = V_70 ;
return 0 ;
case 1 :
V_68 -> V_69 = V_2 -> V_71 ;
V_68 -> type = V_72 ;
return 0 ;
default:
return - V_47 ;
}
}
int F_41 ( struct V_59 * V_59 , void * V_60 ,
const struct V_67 * V_68 )
{
struct V_1 * V_2 = F_40 ( V_59 ) ;
unsigned V_73 = V_68 -> V_69 ;
unsigned V_62 ;
switch ( V_68 -> V_63 ) {
case 0 :
if ( V_68 -> type != V_70 )
return - V_47 ;
if ( V_73 < V_74 )
V_62 = 0 ;
else if ( V_73 < V_75 )
V_62 = 1 ;
else
V_62 = 2 ;
V_73 = F_42 ( unsigned , V_73 ,
V_65 [ V_62 ] . V_76 ,
V_65 [ V_62 ] . V_77 ) ;
if ( F_43 ( & V_2 -> V_78 ) &&
V_73 != V_2 -> V_32 ) {
V_2 -> V_30 = true ;
}
V_2 -> V_32 = V_73 ;
return 0 ;
case 1 :
if ( V_68 -> type != V_72 )
return - V_47 ;
V_2 -> V_71 = F_42 ( unsigned , V_73 ,
V_66 [ 0 ] . V_76 ,
V_66 [ 0 ] . V_77 ) ;
return 0 ;
default:
return - V_47 ;
}
}
int F_44 ( struct V_59 * V_59 , void * V_60 , struct V_79 * V_80 )
{
switch ( V_80 -> V_64 ) {
case 0 :
F_45 ( V_80 -> V_56 , L_8 , sizeof( V_80 -> V_56 ) ) ;
V_80 -> type = V_70 ;
V_80 -> V_81 =
V_82 | V_83 ;
V_80 -> V_76 = V_65 [ 0 ] . V_76 ;
V_80 -> V_77 = V_65 [ 2 ] . V_77 ;
return 0 ;
case 1 :
F_45 ( V_80 -> V_56 , L_9 , sizeof( V_80 -> V_56 ) ) ;
V_80 -> type = V_72 ;
V_80 -> V_81 =
V_82 | V_83 ;
V_80 -> V_76 = V_66 [ 0 ] . V_76 ;
V_80 -> V_77 = V_66 [ 0 ] . V_77 ;
return 0 ;
default:
return - V_47 ;
}
}
int F_46 ( struct V_59 * V_59 , void * V_60 , const struct V_79 * V_80 )
{
if ( V_80 -> V_64 > 1 )
return - V_47 ;
return 0 ;
}
int F_47 ( struct V_59 * V_59 , void * V_60 , struct V_84 * V_85 )
{
if ( V_85 -> V_64 >= F_38 ( V_86 ) )
return - V_47 ;
V_85 -> V_87 = V_86 [ V_85 -> V_64 ] . V_87 ;
return 0 ;
}
int F_48 ( struct V_59 * V_59 , void * V_60 , struct V_88 * V_85 )
{
struct V_1 * V_2 = F_40 ( V_59 ) ;
V_85 -> V_89 . V_90 . V_87 = V_2 -> V_91 ;
V_85 -> V_89 . V_90 . V_92 = V_2 -> V_93 ;
memset ( V_85 -> V_89 . V_90 . V_94 , 0 , sizeof( V_85 -> V_89 . V_90 . V_94 ) ) ;
return 0 ;
}
int F_49 ( struct V_59 * V_59 , void * V_60 , struct V_88 * V_85 )
{
struct V_1 * V_2 = F_40 ( V_59 ) ;
struct V_36 * V_95 = & V_2 -> V_78 ;
int V_96 ;
if ( F_50 ( V_95 ) )
return - V_97 ;
memset ( V_85 -> V_89 . V_90 . V_94 , 0 , sizeof( V_85 -> V_89 . V_90 . V_94 ) ) ;
for ( V_96 = 0 ; V_96 < F_38 ( V_86 ) ; V_96 ++ ) {
if ( V_86 [ V_96 ] . V_87 == V_85 -> V_89 . V_90 . V_87 ) {
V_2 -> V_91 = V_86 [ V_96 ] . V_87 ;
V_2 -> V_93 = V_86 [ V_96 ] . V_92 ;
V_85 -> V_89 . V_90 . V_92 = V_86 [ V_96 ] . V_92 ;
return 0 ;
}
}
V_2 -> V_91 = V_86 [ 0 ] . V_87 ;
V_2 -> V_93 = V_86 [ 0 ] . V_92 ;
V_85 -> V_89 . V_90 . V_87 = V_86 [ 0 ] . V_87 ;
V_85 -> V_89 . V_90 . V_92 = V_86 [ 0 ] . V_92 ;
return 0 ;
}
int F_51 ( struct V_59 * V_59 , void * V_60 , struct V_88 * V_85 )
{
int V_96 ;
memset ( V_85 -> V_89 . V_90 . V_94 , 0 , sizeof( V_85 -> V_89 . V_90 . V_94 ) ) ;
for ( V_96 = 0 ; V_96 < F_38 ( V_86 ) ; V_96 ++ ) {
if ( V_86 [ V_96 ] . V_87 == V_85 -> V_89 . V_90 . V_87 ) {
V_85 -> V_89 . V_90 . V_92 = V_86 [ V_96 ] . V_92 ;
return 0 ;
}
}
V_85 -> V_89 . V_90 . V_87 = V_86 [ 0 ] . V_87 ;
V_85 -> V_89 . V_90 . V_92 = V_86 [ 0 ] . V_92 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 , struct V_3 * V_50 )
{
T_2 * V_49 = F_52 ( & V_50 -> V_10 . V_13 , 0 ) ;
unsigned long V_96 ;
unsigned long V_98 = F_23 ( & V_50 -> V_10 . V_13 , 0 ) ;
T_3 V_99 ;
T_4 V_100 ;
T_4 V_101 ;
T_4 V_102 ;
T_4 V_103 ;
#define F_53 1000
V_100 = F_54 ( V_104 * F_53 ,
V_2 -> V_32 ) ;
for ( V_96 = 0 ; V_96 < V_98 ; V_96 += 2 ) {
V_101 = F_55 ( V_2 -> V_105 ,
V_104 ) >> ( 31 - V_106 ) ;
V_2 -> V_105 += V_100 ;
V_99 = ( T_3 ) V_101 * V_2 -> V_107 ;
V_2 -> V_108 += F_56 ( V_99 , V_109 ) ;
V_2 -> V_105 %= V_104 ;
V_2 -> V_108 %= V_104 ;
if ( V_2 -> V_108 < 0 )
V_2 -> V_108 += V_104 ;
V_102 = F_55 ( V_2 -> V_108 , V_104 ) ;
V_103 = F_57 ( V_2 -> V_108 , V_104 ) ;
V_102 >>= ( 31 - V_106 ) ;
V_103 >>= ( 31 - V_106 ) ;
switch ( V_2 -> V_91 ) {
case V_110 :
V_102 = V_102 * 1275 + V_111 * 1275 ;
V_103 = V_103 * 1275 + V_111 * 1275 ;
* V_49 ++ = F_54 ( V_102 , V_111 * 10 ) ;
* V_49 ++ = F_54 ( V_103 , V_111 * 10 ) ;
break;
case V_112 :
V_102 = V_102 * 1275 - V_111 * 5 ;
V_103 = V_103 * 1275 - V_111 * 5 ;
* V_49 ++ = F_54 ( V_102 , V_111 * 10 ) ;
* V_49 ++ = F_54 ( V_103 , V_111 * 10 ) ;
break;
default:
break;
}
}
}
