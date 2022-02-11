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
F_10 ( & V_4 -> V_10 . V_13 ) ;
V_4 -> V_10 . V_13 . V_14 += V_2 -> V_15 ;
F_11 ( & V_4 -> V_10 . V_16 , V_2 -> V_17 ?
V_18 : V_19 ) ;
V_2 -> V_17 = false ;
}
}
static int F_12 ( void * V_20 )
{
struct V_1 * V_2 = V_20 ;
T_1 V_21 ;
T_1 V_22 ;
T_1 V_23 ;
unsigned long V_24 ;
unsigned long V_25 ;
unsigned V_26 ;
F_2 ( V_2 , 1 , L_2 ) ;
F_13 () ;
V_2 -> V_27 = 0 ;
if ( V_2 -> V_28 )
V_2 -> V_27 = 0xffffff80U ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = false ;
for (; ; ) {
F_14 () ;
if ( F_15 () )
break;
F_16 ( & V_2 -> V_32 ) ;
V_25 = V_30 ;
if ( V_2 -> V_31 ) {
V_2 -> V_29 = V_25 ;
V_2 -> V_27 = V_2 -> V_12 + 1 ;
V_2 -> V_12 = 0 ;
V_2 -> V_31 = false ;
}
V_24 = V_25 - V_2 -> V_29 ;
V_22 =
( T_1 ) V_24 * V_2 -> V_33 +
( V_34 * V_35 ) / 2 ;
F_17 ( V_22 , V_34 * V_35 ) ;
if ( V_24 > V_36 ) {
V_2 -> V_29 = V_25 ;
V_2 -> V_27 = V_22 ;
V_22 = 0 ;
}
V_2 -> V_12 =
V_22 + V_2 -> V_27 ;
F_1 ( V_2 ) ;
F_18 ( & V_2 -> V_32 ) ;
V_21 = V_22 * V_35 ;
V_24 = V_30 - V_2 -> V_29 ;
V_21 += V_35 ;
V_23 = V_21 * V_34 +
V_2 -> V_33 / 2 ;
F_17 ( V_23 , V_2 -> V_33 ) ;
if ( V_23 < V_24 )
V_23 = V_24 ;
V_26 = V_23 - V_24 ;
F_19 ( V_26 ? V_26 : 1 ) ;
}
F_2 ( V_2 , 1 , L_3 ) ;
return 0 ;
}
static int F_20 ( struct V_37 * V_38 , const void * V_39 ,
unsigned * V_40 , unsigned * V_41 ,
unsigned V_42 [] , void * V_43 [] )
{
V_42 [ 0 ] = V_35 * 2 ;
* V_41 = 1 ;
return 0 ;
}
static int F_21 ( struct V_44 * V_10 )
{
struct V_1 * V_2 = F_22 ( V_10 -> V_37 ) ;
unsigned V_45 = V_35 * 2 ;
F_2 ( V_2 , 1 , L_4 , V_46 ) ;
if ( V_2 -> V_47 ) {
V_2 -> V_47 = false ;
return - V_48 ;
}
if ( F_23 ( V_10 , 0 ) < V_45 ) {
F_2 ( V_2 , 1 , L_5 ,
V_46 , F_23 ( V_10 , 0 ) , V_45 ) ;
return - V_48 ;
}
F_24 ( V_10 , 0 , V_45 ) ;
return 0 ;
}
static void F_25 ( struct V_44 * V_10 )
{
struct V_49 * V_50 = F_26 ( V_10 ) ;
struct V_1 * V_2 = F_22 ( V_10 -> V_37 ) ;
struct V_3 * V_51 = F_27 ( V_50 , struct V_3 , V_10 ) ;
F_2 ( V_2 , 1 , L_4 , V_46 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_28 ( & V_51 -> V_9 , & V_2 -> V_7 ) ;
F_8 ( & V_2 -> V_6 ) ;
}
static int F_29 ( struct V_37 * V_38 , unsigned V_52 )
{
struct V_1 * V_2 = F_22 ( V_38 ) ;
int V_53 = 0 ;
F_2 ( V_2 , 1 , L_4 , V_46 ) ;
V_2 -> V_12 = 0 ;
if ( V_2 -> V_54 ) {
V_2 -> V_54 = false ;
V_53 = - V_48 ;
} else if ( V_2 -> V_55 == NULL ) {
V_2 -> V_55 = F_30 ( F_12 , V_2 ,
L_6 , V_2 -> V_56 . V_57 ) ;
if ( F_31 ( V_2 -> V_55 ) ) {
F_32 ( & V_2 -> V_56 , L_7 ) ;
V_53 = F_33 ( V_2 -> V_55 ) ;
V_2 -> V_55 = NULL ;
}
}
if ( V_53 ) {
struct V_3 * V_51 , * V_58 ;
F_34 (buf, tmp, &dev->sdr_cap_active, list) {
F_7 ( & V_51 -> V_9 ) ;
F_11 ( & V_51 -> V_10 . V_16 ,
V_59 ) ;
}
}
return V_53 ;
}
static void F_35 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_22 ( V_38 ) ;
if ( V_2 -> V_55 == NULL )
return;
while ( ! F_5 ( & V_2 -> V_7 ) ) {
struct V_3 * V_51 ;
V_51 = F_6 ( V_2 -> V_7 . V_8 ,
struct V_3 , V_9 ) ;
F_7 ( & V_51 -> V_9 ) ;
F_11 ( & V_51 -> V_10 . V_16 , V_18 ) ;
}
F_18 ( & V_2 -> V_32 ) ;
F_36 ( V_2 -> V_55 ) ;
V_2 -> V_55 = NULL ;
F_16 ( & V_2 -> V_32 ) ;
}
int F_37 ( struct V_60 * V_60 , void * V_61 ,
struct V_62 * V_63 )
{
switch ( V_63 -> V_64 ) {
case 0 :
if ( V_63 -> V_65 >= F_38 ( V_66 ) )
return - V_48 ;
* V_63 = V_66 [ V_63 -> V_65 ] ;
return 0 ;
case 1 :
if ( V_63 -> V_65 >= F_38 ( V_67 ) )
return - V_48 ;
* V_63 = V_67 [ V_63 -> V_65 ] ;
return 0 ;
default:
return - V_48 ;
}
}
int F_39 ( struct V_60 * V_60 , void * V_61 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = F_40 ( V_60 ) ;
switch ( V_69 -> V_64 ) {
case 0 :
V_69 -> V_70 = V_2 -> V_33 ;
V_69 -> type = V_71 ;
return 0 ;
case 1 :
V_69 -> V_70 = V_2 -> V_72 ;
V_69 -> type = V_73 ;
return 0 ;
default:
return - V_48 ;
}
}
int F_41 ( struct V_60 * V_60 , void * V_61 ,
const struct V_68 * V_69 )
{
struct V_1 * V_2 = F_40 ( V_60 ) ;
unsigned V_74 = V_69 -> V_70 ;
unsigned V_63 ;
switch ( V_69 -> V_64 ) {
case 0 :
if ( V_69 -> type != V_71 )
return - V_48 ;
if ( V_74 < V_75 )
V_63 = 0 ;
else if ( V_74 < V_76 )
V_63 = 1 ;
else
V_63 = 2 ;
V_74 = F_42 ( unsigned , V_74 ,
V_66 [ V_63 ] . V_77 ,
V_66 [ V_63 ] . V_78 ) ;
if ( F_43 ( & V_2 -> V_79 ) &&
V_74 != V_2 -> V_33 ) {
V_2 -> V_31 = true ;
}
V_2 -> V_33 = V_74 ;
return 0 ;
case 1 :
if ( V_69 -> type != V_73 )
return - V_48 ;
V_2 -> V_72 = F_42 ( unsigned , V_74 ,
V_67 [ 0 ] . V_77 ,
V_67 [ 0 ] . V_78 ) ;
return 0 ;
default:
return - V_48 ;
}
}
int F_44 ( struct V_60 * V_60 , void * V_61 , struct V_80 * V_81 )
{
switch ( V_81 -> V_65 ) {
case 0 :
F_45 ( V_81 -> V_57 , L_8 , sizeof( V_81 -> V_57 ) ) ;
V_81 -> type = V_71 ;
V_81 -> V_82 =
V_83 | V_84 ;
V_81 -> V_77 = V_66 [ 0 ] . V_77 ;
V_81 -> V_78 = V_66 [ 2 ] . V_78 ;
return 0 ;
case 1 :
F_45 ( V_81 -> V_57 , L_9 , sizeof( V_81 -> V_57 ) ) ;
V_81 -> type = V_73 ;
V_81 -> V_82 =
V_83 | V_84 ;
V_81 -> V_77 = V_67 [ 0 ] . V_77 ;
V_81 -> V_78 = V_67 [ 0 ] . V_78 ;
return 0 ;
default:
return - V_48 ;
}
}
int F_46 ( struct V_60 * V_60 , void * V_61 , const struct V_80 * V_81 )
{
if ( V_81 -> V_65 > 1 )
return - V_48 ;
return 0 ;
}
int F_47 ( struct V_60 * V_60 , void * V_61 , struct V_85 * V_86 )
{
if ( V_86 -> V_65 >= F_38 ( V_87 ) )
return - V_48 ;
V_86 -> V_88 = V_87 [ V_86 -> V_65 ] . V_88 ;
return 0 ;
}
int F_48 ( struct V_60 * V_60 , void * V_61 , struct V_89 * V_86 )
{
struct V_1 * V_2 = F_40 ( V_60 ) ;
V_86 -> V_90 . V_91 . V_88 = V_2 -> V_92 ;
V_86 -> V_90 . V_91 . V_93 = V_2 -> V_94 ;
memset ( V_86 -> V_90 . V_91 . V_95 , 0 , sizeof( V_86 -> V_90 . V_91 . V_95 ) ) ;
return 0 ;
}
int F_49 ( struct V_60 * V_60 , void * V_61 , struct V_89 * V_86 )
{
struct V_1 * V_2 = F_40 ( V_60 ) ;
struct V_37 * V_96 = & V_2 -> V_79 ;
int V_97 ;
if ( F_50 ( V_96 ) )
return - V_98 ;
memset ( V_86 -> V_90 . V_91 . V_95 , 0 , sizeof( V_86 -> V_90 . V_91 . V_95 ) ) ;
for ( V_97 = 0 ; V_97 < F_38 ( V_87 ) ; V_97 ++ ) {
if ( V_87 [ V_97 ] . V_88 == V_86 -> V_90 . V_91 . V_88 ) {
V_2 -> V_92 = V_87 [ V_97 ] . V_88 ;
V_2 -> V_94 = V_87 [ V_97 ] . V_93 ;
V_86 -> V_90 . V_91 . V_93 = V_87 [ V_97 ] . V_93 ;
return 0 ;
}
}
V_2 -> V_92 = V_87 [ 0 ] . V_88 ;
V_2 -> V_94 = V_87 [ 0 ] . V_93 ;
V_86 -> V_90 . V_91 . V_88 = V_87 [ 0 ] . V_88 ;
V_86 -> V_90 . V_91 . V_93 = V_87 [ 0 ] . V_93 ;
return 0 ;
}
int F_51 ( struct V_60 * V_60 , void * V_61 , struct V_89 * V_86 )
{
int V_97 ;
memset ( V_86 -> V_90 . V_91 . V_95 , 0 , sizeof( V_86 -> V_90 . V_91 . V_95 ) ) ;
for ( V_97 = 0 ; V_97 < F_38 ( V_87 ) ; V_97 ++ ) {
if ( V_87 [ V_97 ] . V_88 == V_86 -> V_90 . V_91 . V_88 ) {
V_86 -> V_90 . V_91 . V_93 = V_87 [ V_97 ] . V_93 ;
return 0 ;
}
}
V_86 -> V_90 . V_91 . V_88 = V_87 [ 0 ] . V_88 ;
V_86 -> V_90 . V_91 . V_93 = V_87 [ 0 ] . V_93 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 , struct V_3 * V_51 )
{
T_2 * V_50 = F_52 ( & V_51 -> V_10 . V_16 , 0 ) ;
unsigned long V_97 ;
unsigned long V_99 = F_23 ( & V_51 -> V_10 . V_16 , 0 ) ;
T_3 V_100 ;
T_4 V_101 ;
T_4 V_102 ;
T_4 V_103 ;
T_4 V_104 ;
#define F_53 1000
V_101 = F_54 ( V_105 * F_53 ,
V_2 -> V_33 ) ;
for ( V_97 = 0 ; V_97 < V_99 ; V_97 += 2 ) {
V_102 = F_55 ( V_2 -> V_106 ,
V_105 ) >> ( 31 - V_107 ) ;
V_2 -> V_106 += V_101 ;
V_100 = ( T_3 ) V_102 * V_2 -> V_108 ;
V_2 -> V_109 += F_56 ( V_100 , V_110 ) ;
V_2 -> V_106 %= V_105 ;
V_2 -> V_109 %= V_105 ;
if ( V_2 -> V_109 < 0 )
V_2 -> V_109 += V_105 ;
V_103 = F_55 ( V_2 -> V_109 , V_105 ) ;
V_104 = F_57 ( V_2 -> V_109 , V_105 ) ;
V_103 >>= ( 31 - V_107 ) ;
V_104 >>= ( 31 - V_107 ) ;
switch ( V_2 -> V_92 ) {
case V_111 :
V_103 = V_103 * 1275 + V_112 * 1275 ;
V_104 = V_104 * 1275 + V_112 * 1275 ;
* V_50 ++ = F_54 ( V_103 , V_112 * 10 ) ;
* V_50 ++ = F_54 ( V_104 , V_112 * 10 ) ;
break;
case V_113 :
V_103 = V_103 * 1275 - V_112 * 5 ;
V_104 = V_104 * 1275 - V_112 * 5 ;
* V_50 ++ = F_54 ( V_103 , V_112 * 10 ) ;
* V_50 ++ = F_54 ( V_104 , V_112 * 10 ) ;
break;
default:
break;
}
}
}
