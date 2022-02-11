static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
V_5 -> V_7 [ 0 ] = V_8 ;
V_5 -> V_7 [ 1 ] = 1 ;
V_5 -> V_7 [ 2 ] = 0xFF ;
V_5 -> V_7 [ 4 ] = V_3 ;
V_6 = F_3 ( V_2 , V_5 -> V_7 ,
V_5 -> V_9 ) ;
if ( V_6 != V_5 -> V_9 ) {
F_4 ( & V_2 -> V_10 ,
L_1 , V_11 , V_6 ) ;
return V_6 ;
}
V_5 -> V_3 = V_3 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_12 )
{
int V_13 ;
const T_1 V_14 [ 2 ] = { V_15 , V_12 } ;
T_1 * V_16 ;
V_16 = F_6 ( V_14 , sizeof( V_14 ) , V_17 ) ;
if ( ! V_16 )
return - V_18 ;
V_13 = F_7 ( V_2 , V_15 , V_16 ,
sizeof( V_14 ) , V_19 , V_20 ) ;
F_8 ( V_16 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_2 , V_12 ,
V_13 ) ;
return V_13 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_21 , int V_22 )
{
int V_13 ;
V_13 = F_9 ( V_2 , ( void * ) V_21 , V_22 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_3 , V_13 ) ;
return V_13 ;
}
return V_13 ;
}
static int F_10 ( struct V_23 * V_24 , T_2 V_25 ,
void * V_16 , T_3 V_22 )
{
struct V_4 * V_5 = F_11 ( V_24 , struct V_4 , V_24 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_13 ;
int V_26 ;
int V_27 ;
int V_28 ;
int V_29 ;
F_12 ( & V_5 -> V_30 ) ;
if ( F_13 ( V_25 ) != V_5 -> V_3 ) {
V_13 = F_1 ( V_2 , F_13 ( V_25 ) ) ;
if ( V_13 < 0 )
goto exit;
}
for ( V_28 = 5 ; V_28 > 0 ; V_28 -- ) {
V_5 -> V_7 [ 0 ] = V_31 ;
V_5 -> V_7 [ 1 ] = 0 ;
V_5 -> V_7 [ 2 ] = V_25 & 0xFF ;
V_5 -> V_7 [ 3 ] = ( V_25 >> 8 ) & 0xFF ;
V_5 -> V_7 [ 4 ] = V_22 & 0xFF ;
V_5 -> V_7 [ 5 ] = ( V_22 >> 8 ) & 0xFF ;
F_14 ( V_32 , & V_5 -> V_33 ) ;
V_13 = F_3 ( V_2 , V_5 -> V_7 ,
V_5 -> V_9 ) ;
if ( V_13 != V_5 -> V_9 ) {
F_15 ( V_32 , & V_5 -> V_33 ) ;
F_4 ( & V_2 -> V_10 ,
L_4 ,
V_13 ) ;
goto exit;
}
V_26 = 0 ;
V_27 = V_22 ;
while ( V_26 < V_22 ) {
if ( ! F_16 ( V_5 -> V_34 ,
F_17 ( V_35 , & V_5 -> V_33 ) ,
F_18 ( 1000 ) ) ) {
F_19 ( V_2 , L_5 ,
V_11 ) ;
V_13 = - V_36 ;
break;
}
V_29 = V_5 -> V_37 [ 1 ] ;
memcpy ( V_16 + V_26 , & V_5 -> V_37 [ 2 ] ,
V_29 < V_27 ?
V_29 : V_27 ) ;
V_26 += V_29 ;
V_27 -= V_29 ;
F_15 ( V_35 , & V_5 -> V_33 ) ;
}
if ( V_13 >= 0 ) {
V_13 = 0 ;
break;
}
}
exit:
F_15 ( V_32 , & V_5 -> V_33 ) ;
F_20 ( & V_5 -> V_30 ) ;
return V_13 ;
}
static int F_21 ( struct V_23 * V_24 , T_2 V_25 ,
const void * V_16 , T_3 V_22 )
{
struct V_4 * V_5 = F_11 ( V_24 , struct V_4 , V_24 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_13 ;
F_12 ( & V_5 -> V_30 ) ;
if ( F_13 ( V_25 ) != V_5 -> V_3 ) {
V_13 = F_1 ( V_2 , F_13 ( V_25 ) ) ;
if ( V_13 < 0 )
goto exit;
}
V_5 -> V_7 [ 0 ] = V_8 ;
V_5 -> V_7 [ 1 ] = V_22 ;
V_5 -> V_7 [ 2 ] = V_25 & 0xFF ;
V_5 -> V_7 [ 3 ] = ( V_25 >> 8 ) & 0xFF ;
memcpy ( & V_5 -> V_7 [ 4 ] , V_16 , V_22 ) ;
V_13 = F_3 ( V_2 , V_5 -> V_7 ,
V_5 -> V_9 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 ,
L_4 ,
V_13 ) ;
goto exit;
}
V_13 = 0 ;
exit:
F_20 ( & V_5 -> V_30 ) ;
return V_13 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_38 * V_39 = V_5 -> V_24 . V_39 ;
int V_13 ;
V_13 = F_5 ( V_2 , V_40 ) ;
if ( V_13 )
return V_13 ;
if ( F_17 ( V_41 , & V_5 -> V_33 ) )
V_13 = V_39 -> V_42 -> V_43 ( V_39 ) ;
return V_13 ;
}
static void F_23 ( struct V_44 * V_45 )
{
struct V_4 * V_46 = F_11 ( V_45 , struct V_4 ,
V_47 ) ;
F_22 ( V_46 -> V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_1 * V_5 , int V_48 )
{
struct V_4 * V_46 = F_2 ( V_2 ) ;
struct V_38 * V_39 = V_46 -> V_24 . V_39 ;
unsigned long V_33 ;
if ( ! ( F_17 ( V_41 , & V_46 -> V_33 ) ) )
return 0 ;
F_25 ( V_33 ) ;
F_26 ( V_39 , V_5 [ 1 ] , & V_5 [ 2 ] , V_48 - 2 ) ;
F_27 ( V_46 -> V_49 ) ;
F_28 ( V_33 ) ;
return 1 ;
}
static int F_29 ( struct V_1 * V_2 , T_1 * V_5 , int V_48 )
{
struct V_4 * V_46 = F_2 ( V_2 ) ;
if ( ! F_17 ( V_32 , & V_46 -> V_33 ) ) {
F_30 ( V_2 , L_6 ) ;
return 0 ;
}
memcpy ( V_46 -> V_37 , V_5 , V_48 < V_46 -> V_50 ?
V_48 : V_46 -> V_50 ) ;
F_14 ( V_35 , & V_46 -> V_33 ) ;
F_31 ( & V_46 -> V_34 ) ;
return 1 ;
}
static int F_32 ( struct V_1 * V_2 , T_1 * V_5 , int V_48 )
{
int V_51 = V_48 ;
while ( ( V_5 [ V_51 - 1 ] == 0xff ) && V_51 > 0 )
V_51 -- ;
return V_51 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_52 * V_21 , T_1 * V_5 , int V_48 )
{
V_48 = F_32 ( V_2 , V_5 , V_48 ) ;
if ( V_48 < 2 )
return 0 ;
switch ( V_5 [ 0 ] ) {
case V_53 :
return F_29 ( V_2 , V_5 , V_48 ) ;
case V_54 :
return F_24 ( V_2 , V_5 , V_48 ) ;
default:
return 1 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_55 * V_56 ,
struct V_57 * V_58 , T_4 V_59 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ( V_5 -> V_60 & V_61 ) &&
( V_56 -> V_62 == V_63 ||
V_56 -> V_62 == V_64 ) ) {
if ( V_5 -> V_60 & V_65 ) {
if ( ( V_58 -> V_66 & V_67 ) == V_68 )
return 0 ;
if ( ( V_58 -> V_66 == V_69 || V_58 -> V_66 == V_70 )
&& ! V_59 )
return 1 ;
}
F_35 ( & V_5 -> V_47 ) ;
return 1 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , T_5 V_71 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_38 * V_39 = V_5 -> V_24 . V_39 ;
int V_13 ;
if ( ! ( V_5 -> V_60 & V_61 ) )
return 0 ;
V_13 = F_37 ( V_39 , false ) ;
if ( V_13 ) {
F_19 ( V_2 , L_7 , V_13 ) ;
return V_13 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_38 * V_39 = V_5 -> V_24 . V_39 ;
int V_13 ;
if ( ! ( V_5 -> V_60 & V_61 ) )
return 0 ;
V_13 = F_39 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_22 ( V_2 ) ;
if ( V_13 )
goto V_72;
V_13 = F_40 ( V_39 , false ) ;
if ( V_13 ) {
F_19 ( V_2 , L_8 , V_13 ) ;
goto V_72;
}
V_72:
F_41 ( V_2 ) ;
return V_13 ;
}
static int F_42 ( struct V_23 * V_24 , T_2 V_73 )
{
struct V_4 * V_5 = F_11 ( V_24 , struct V_4 , V_24 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
return F_22 ( V_2 ) ;
}
static int F_43 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_76 * V_77 = V_75 -> V_77 ;
int V_13 = 0 ;
if ( ! ( V_5 -> V_60 & V_61 ) )
return 0 ;
V_5 -> V_24 . V_77 = V_77 ;
F_30 ( V_2 , L_9 ) ;
V_13 = F_39 ( V_2 ) ;
if ( V_13 )
return V_13 ;
F_44 ( V_2 ) ;
V_13 = F_5 ( V_2 , V_40 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_10 ) ;
goto exit;
}
V_13 = F_1 ( V_2 , 0 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_11 ) ;
goto exit;
}
V_13 = F_45 ( & V_5 -> V_24 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_12 ) ;
goto exit;
}
F_14 ( V_41 , & V_5 -> V_33 ) ;
exit:
F_46 ( V_2 ) ;
F_41 ( V_2 ) ;
return V_13 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_74 * V_75 , struct V_55 * V_56 ,
struct V_57 * V_58 , unsigned long * * V_78 , int * V_79 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_60 & V_61 ) {
if ( ( V_5 -> V_60 & V_65 ) &&
( ( V_58 -> V_66 & V_67 ) == V_68 ) )
return 0 ;
return - 1 ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , unsigned type ,
unsigned V_80 , struct V_52 * * V_21 )
{
int V_81 ;
* V_21 = V_2 -> V_82 [ type ] . V_83 [ V_80 ] ;
if ( * V_21 ) {
for ( V_81 = 0 ; V_81 < ( * V_21 ) -> V_84 ; V_81 ++ ) {
unsigned V_85 = ( * V_21 ) -> V_56 [ V_81 ] -> V_62 ;
if ( ( V_85 & V_67 ) >= V_86 )
return 1 ;
}
}
return 0 ;
}
static void F_49 ( void * V_5 )
{
struct V_4 * V_46 = V_5 ;
struct V_87 * V_88 = V_46 -> V_88 ;
if ( ! V_88 )
return;
F_50 ( F_51 ( V_88 , 0 ) ) ;
F_52 ( V_88 ) ;
V_46 -> V_88 = NULL ;
V_46 -> V_49 = 0 ;
}
static int F_53 ( struct V_87 * V_89 , unsigned int V_90 ,
T_6 V_91 )
{
F_54 ( V_90 , & V_92 , V_93 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_4 * V_46 = F_2 ( V_2 ) ;
int V_13 ;
V_46 -> V_88 = F_56 ( V_2 -> V_10 . V_94 , 1 ,
& V_95 , V_46 ) ;
if ( ! V_46 -> V_88 )
return - V_18 ;
V_13 = F_57 ( & V_2 -> V_10 , & F_49 , V_46 ) ;
if ( V_13 )
return V_13 ;
V_46 -> V_49 = F_58 ( V_46 -> V_88 , 0 ) ;
if ( V_46 -> V_49 <= 0 ) {
F_59 ( V_2 , L_13 ) ;
return V_46 -> V_49 < 0 ? V_46 -> V_49 : - V_96 ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , const struct V_97 * V_80 )
{
struct V_4 * V_5 = NULL ;
int V_13 ;
T_3 V_98 ;
struct V_52 * V_99 ;
struct V_52 * V_100 ;
struct V_52 * V_101 ;
V_5 = F_61 ( & V_2 -> V_10 , sizeof( struct V_4 ) , V_17 ) ;
if ( ! V_5 )
return - V_18 ;
F_62 ( & V_5 -> V_47 , F_23 ) ;
V_5 -> V_2 = V_2 ;
F_63 ( V_2 , V_5 ) ;
V_2 -> V_102 |= V_103 ;
V_13 = F_64 ( V_2 ) ;
if ( V_13 ) {
F_59 ( V_2 , L_14 ) ;
return V_13 ;
}
if ( V_80 -> V_104 )
V_5 -> V_60 = V_80 -> V_104 ;
if ( ! F_48 ( V_2 , V_19 ,
V_15 , & V_101 ) ) {
F_30 ( V_2 , L_15 ) ;
goto V_105;
}
if ( ! F_48 ( V_2 , V_106 ,
V_54 , & V_99 ) ) {
F_30 ( V_2 , L_16 ) ;
goto V_105;
}
V_5 -> V_50 = F_65 ( V_99 ) ;
if ( ! F_48 ( V_2 , V_107 ,
V_8 , & V_100 ) ) {
F_30 ( V_2 ,
L_17 ) ;
goto V_105;
}
V_5 -> V_9 = F_65 ( V_100 ) ;
V_5 -> V_60 |= V_61 ;
V_98 = V_5 -> V_9 + V_5 -> V_50 ;
V_5 -> V_7 = F_61 ( & V_2 -> V_10 , V_98 , V_17 ) ;
if ( ! V_5 -> V_7 ) {
F_59 ( V_2 , L_18 ) ;
return - V_18 ;
}
V_5 -> V_37 = V_5 -> V_7 + V_5 -> V_9 ;
F_66 ( & V_5 -> V_34 ) ;
F_67 ( & V_5 -> V_30 ) ;
V_13 = F_55 ( V_2 ) ;
if ( V_13 ) {
F_59 ( V_2 , L_19 ) ;
return V_13 ;
}
if ( V_5 -> V_60 & V_65 )
V_108 . V_109 . V_110 = true ;
V_5 -> V_24 . V_10 = V_2 -> V_10 . V_111 ;
V_5 -> V_24 . V_112 = V_108 ;
V_5 -> V_24 . V_112 . V_113 = V_5 -> V_49 ;
V_5 -> V_24 . V_114 = L_20 ;
V_5 -> V_24 . V_115 = & V_116 ;
V_105:
V_13 = F_68 ( V_2 , V_117 ) ;
if ( V_13 ) {
F_59 ( V_2 , L_21 ) ;
return V_13 ;
}
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_4 * V_46 = F_2 ( V_2 ) ;
F_15 ( V_41 , & V_46 -> V_33 ) ;
F_70 ( & V_46 -> V_47 ) ;
F_71 ( & V_46 -> V_24 ) ;
F_72 ( V_2 ) ;
}
