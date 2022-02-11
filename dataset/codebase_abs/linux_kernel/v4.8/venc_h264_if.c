static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static unsigned int F_3 ( struct V_1 * V_2 ,
unsigned int V_5 )
{
switch ( V_5 ) {
case V_6 :
return 66 ;
case V_7 :
return 77 ;
case V_8 :
return 100 ;
case V_9 :
F_4 ( V_2 , L_1 ) ;
return 0 ;
case V_10 :
F_4 ( V_2 , L_2 ) ;
return 0 ;
default:
F_5 ( V_2 , L_3 , V_5 ) ;
return 100 ;
}
}
static unsigned int F_6 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
switch ( V_11 ) {
case V_12 :
F_4 ( V_2 , L_4 ) ;
return 0 ;
case V_13 :
return 10 ;
case V_14 :
return 11 ;
case V_15 :
return 12 ;
case V_16 :
return 13 ;
case V_17 :
return 20 ;
case V_18 :
return 21 ;
case V_19 :
return 22 ;
case V_20 :
return 30 ;
case V_21 :
return 31 ;
case V_22 :
return 32 ;
case V_23 :
return 40 ;
case V_24 :
return 41 ;
case V_25 :
return 42 ;
default:
F_5 ( V_2 , L_5 , V_11 ) ;
return 31 ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
int V_26 ;
F_8 ( V_2 ) ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
if ( V_26 != V_28 )
F_9 ( V_2 -> V_29 , & V_2 -> V_30 [ V_26 ] ) ;
}
F_9 ( V_2 -> V_29 , & V_2 -> V_31 ) ;
F_10 ( V_2 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_26 ;
int V_32 = 0 ;
struct V_33 * V_34 = V_2 -> V_35 -> V_30 ;
F_8 ( V_2 ) ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
V_2 -> V_30 [ V_26 ] . V_36 = V_34 [ V_26 ] . V_36 ;
if ( V_26 == V_28 ) {
V_2 -> V_30 [ V_26 ] . V_37 = F_12 (
V_2 -> V_38 . V_39 , V_34 [ V_26 ] . V_40 ) ;
V_2 -> V_30 [ V_26 ] . V_41 = 0 ;
} else {
V_32 = F_13 ( V_2 -> V_29 ,
& V_2 -> V_30 [ V_26 ] ) ;
if ( V_32 ) {
F_4 ( V_2 ,
L_6 , V_26 ) ;
goto V_42;
}
if ( V_26 == V_43 ) {
void * V_44 ;
V_44 = F_12 ( V_2 -> V_38 . V_39 ,
V_34 [ V_26 ] . V_40 ) ;
memcpy ( V_2 -> V_30 [ V_26 ] . V_37 , V_44 ,
V_34 [ V_26 ] . V_36 ) ;
}
}
V_34 [ V_26 ] . V_45 = V_2 -> V_30 [ V_26 ] . V_41 ;
F_5 ( V_2 ,
L_7 ,
V_26 , V_2 -> V_30 [ V_26 ] . V_37 ,
& V_2 -> V_30 [ V_26 ] . V_41 ,
V_2 -> V_30 [ V_26 ] . V_36 ) ;
}
V_2 -> V_31 . V_36 = 128 ;
V_32 = F_13 ( V_2 -> V_29 , & V_2 -> V_31 ) ;
if ( V_32 ) {
F_4 ( V_2 , L_8 ) ;
goto V_42;
}
F_10 ( V_2 ) ;
return V_32 ;
V_42:
F_7 ( V_2 ) ;
return V_32 ;
}
static unsigned int F_14 ( struct V_1 * V_2 )
{
unsigned int V_46 = 0 ;
struct V_47 * V_29 = (struct V_47 * ) V_2 -> V_29 ;
if ( ! F_15 ( V_29 , V_48 ,
V_49 ) ) {
V_46 = V_29 -> V_46 ;
F_5 ( V_2 , L_9 , V_46 ) ;
}
return V_46 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
unsigned int * V_52 )
{
int V_32 = 0 ;
unsigned int V_46 ;
F_8 ( V_2 ) ;
V_32 = F_17 ( & V_2 -> V_38 , V_53 , NULL ,
V_51 , V_52 ) ;
if ( V_32 )
return V_32 ;
V_46 = F_14 ( V_2 ) ;
if ( V_46 != V_54 ) {
F_4 ( V_2 , L_10 ,
V_54 ) ;
return - V_55 ;
}
* V_52 = F_1 ( V_2 , V_56 ) ;
F_5 ( V_2 , L_11 , * V_52 ) ;
return V_32 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
unsigned int * V_52 )
{
int V_32 = 0 ;
unsigned int V_46 ;
F_8 ( V_2 ) ;
V_32 = F_17 ( & V_2 -> V_38 , V_57 , NULL ,
V_51 , V_52 ) ;
if ( V_32 )
return V_32 ;
V_46 = F_14 ( V_2 ) ;
if ( V_46 != V_58 ) {
F_4 ( V_2 , L_10 ,
V_58 ) ;
return - V_55 ;
}
* V_52 = F_1 ( V_2 , V_56 ) ;
F_5 ( V_2 , L_11 , * V_52 ) ;
return V_32 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
unsigned int * V_52 )
{
int V_32 = 0 ;
unsigned int V_59 ;
unsigned int V_60 ;
V_32 = F_16 ( V_2 , V_51 , & V_59 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_18 ( V_2 , & V_2 -> V_31 , & V_60 ) ;
if ( V_32 )
return V_32 ;
memcpy ( V_51 -> V_37 + V_59 , V_2 -> V_31 . V_37 , V_60 ) ;
* V_52 = V_59 + V_60 ;
return V_32 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
struct V_50 * V_51 ,
unsigned int * V_52 )
{
int V_32 = 0 ;
unsigned int V_46 ;
F_8 ( V_2 ) ;
V_32 = F_17 ( & V_2 -> V_38 , V_63 , V_62 ,
V_51 , V_52 ) ;
if ( V_32 )
return V_32 ;
if ( V_2 -> V_38 . V_64 == V_65 ) {
* V_52 = V_2 -> V_38 . V_52 ;
memcpy ( V_51 -> V_37 ,
V_2 -> V_30 [ V_28 ] . V_37 ,
* V_52 ) ;
++ V_2 -> V_66 ;
return V_32 ;
}
V_46 = F_14 ( V_2 ) ;
if ( V_46 != V_67 ) {
F_4 ( V_2 , L_12 , V_46 ) ;
return - V_68 ;
}
* V_52 = F_1 ( V_2 , V_56 ) ;
++ V_2 -> V_66 ;
F_5 ( V_2 , L_13 ,
V_2 -> V_66 , * V_52 , V_2 -> V_38 . V_69 ) ;
return V_32 ;
}
static void F_21 ( struct V_1 * V_2 , void * V_70 ,
int V_36 )
{
unsigned char * V_71 = V_70 ;
if ( V_36 < V_72 ) {
F_4 ( V_2 , L_14 , V_36 ) ;
return;
}
memcpy ( V_71 , V_73 , F_22 ( V_73 ) ) ;
V_36 -= V_72 ;
V_71 += V_72 ;
memset ( V_71 , 0xff , V_36 ) ;
}
static int F_23 ( struct V_47 * V_29 , unsigned long * V_74 )
{
int V_32 = 0 ;
struct V_1 * V_2 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_75 ) ;
if ( ! V_2 )
return - V_76 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_38 . V_29 = V_29 ;
V_2 -> V_38 . V_39 = V_29 -> V_39 -> V_77 ;
V_2 -> V_38 . V_78 = V_79 ;
V_2 -> V_4 = F_25 ( V_2 -> V_29 , V_80 ) ;
F_8 ( V_2 ) ;
V_32 = F_26 ( & V_2 -> V_38 ) ;
V_2 -> V_35 = (struct V_81 * ) V_2 -> V_38 . V_35 ;
F_10 ( V_2 ) ;
if ( V_32 )
F_27 ( V_2 ) ;
else
( * V_74 ) = ( unsigned long ) V_2 ;
return V_32 ;
}
static int F_28 ( unsigned long V_74 ,
enum V_82 V_83 ,
struct V_61 * V_62 ,
struct V_50 * V_51 ,
struct V_84 * V_85 )
{
int V_32 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
struct V_47 * V_29 = V_2 -> V_29 ;
F_5 ( V_2 , L_15 , V_83 ) ;
F_29 ( V_29 -> V_39 -> V_86 ) ;
switch ( V_83 ) {
case V_87 : {
unsigned int V_88 ;
V_32 = F_19 ( V_2 , V_51 , & V_88 ) ;
if ( V_32 )
goto V_89;
V_85 -> V_52 = V_88 ;
V_85 -> V_69 = false ;
break;
}
case V_90 : {
int V_91 ;
int V_92 ;
int V_93 = 0 ;
const int V_94 = 128 ;
struct V_50 V_95 ;
unsigned int V_88 ;
unsigned int V_96 ;
if ( ! V_2 -> V_97 ) {
V_32 = F_20 ( V_2 , V_62 , V_51 ,
& V_85 -> V_52 ) ;
if ( V_32 )
goto V_89;
V_85 -> V_69 = V_2 -> V_38 . V_69 ;
break;
}
F_5 ( V_2 , L_16 ) ;
V_32 = F_19 ( V_2 , V_51 , & V_88 ) ;
if ( V_32 )
goto V_89;
V_91 = V_88 ;
V_92 = ( V_91 & ( V_94 - 1 ) ) ;
if ( V_92 ) {
V_93 = V_94 - V_92 ;
if ( V_92 + V_72 > V_94 )
V_93 += V_94 ;
F_21 ( V_2 , V_51 -> V_37 + V_91 ,
V_93 ) ;
}
V_95 . V_37 = V_51 -> V_37 + V_91 + V_93 ;
V_95 . V_41 = V_51 -> V_41 + V_91 + V_93 ;
V_95 . V_36 = V_51 -> V_36 - ( V_91 + V_93 ) ;
V_32 = F_20 ( V_2 , V_62 , & V_95 ,
& V_96 ) ;
if ( V_32 )
goto V_89;
V_85 -> V_52 = V_91 + V_93 + V_96 ;
F_5 ( V_2 , L_17 ,
V_91 , V_93 , V_96 ,
V_85 -> V_52 ) ;
V_2 -> V_97 = 0 ;
V_85 -> V_69 = V_2 -> V_38 . V_69 ;
break;
}
default:
F_4 ( V_2 , L_18 , V_83 ) ;
V_32 = - V_55 ;
break;
}
V_89:
F_30 ( V_29 -> V_39 -> V_86 ) ;
F_5 ( V_2 , L_19 , V_83 ) ;
return V_32 ;
}
static int F_31 ( unsigned long V_74 ,
enum V_98 type ,
struct V_99 * V_100 )
{
int V_32 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
F_5 ( V_2 , L_20 , type ) ;
switch ( type ) {
case V_101 :
V_2 -> V_35 -> V_102 . V_103 = V_100 -> V_104 ;
V_2 -> V_35 -> V_102 . V_105 = V_100 -> V_105 ;
V_2 -> V_35 -> V_102 . V_106 = V_100 -> V_107 ;
V_2 -> V_35 -> V_102 . V_108 = V_100 -> V_109 ;
V_2 -> V_35 -> V_102 . V_110 = V_100 -> V_111 ;
V_2 -> V_35 -> V_102 . V_112 = V_100 -> V_113 ;
V_2 -> V_35 -> V_102 . V_114 = V_100 -> V_114 ;
V_2 -> V_35 -> V_102 . V_115 = V_100 -> V_116 ;
V_2 -> V_35 -> V_102 . V_117 = V_100 -> V_117 ;
V_2 -> V_35 -> V_102 . V_5 =
F_3 ( V_2 , V_100 -> V_118 ) ;
V_2 -> V_35 -> V_102 . V_11 =
F_6 ( V_2 , V_100 -> V_119 ) ;
V_2 -> V_35 -> V_102 . V_120 = 0 ;
V_32 = F_32 ( & V_2 -> V_38 , type , V_100 ) ;
if ( V_32 )
break;
if ( V_2 -> V_121 ) {
F_7 ( V_2 ) ;
V_2 -> V_121 = false ;
}
V_32 = F_11 ( V_2 ) ;
if ( V_32 )
break;
V_2 -> V_121 = true ;
break;
case V_122 :
V_2 -> V_97 = 1 ;
F_5 ( V_2 , L_21 ) ;
break;
default:
V_32 = F_32 ( & V_2 -> V_38 , type , V_100 ) ;
break;
}
F_10 ( V_2 ) ;
return V_32 ;
}
static int F_33 ( unsigned long V_74 )
{
int V_32 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
F_8 ( V_2 ) ;
V_32 = F_34 ( & V_2 -> V_38 ) ;
if ( V_2 -> V_121 )
F_7 ( V_2 ) ;
F_10 ( V_2 ) ;
F_27 ( V_2 ) ;
return V_32 ;
}
struct V_123 * F_35 ( void )
{
return & V_124 ;
}
