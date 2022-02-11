static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 , T_1 V_5 , T_1 V_6 ,
T_1 * V_7 , T_1 V_8 , bool V_9 )
{
int V_10 ;
int V_11 ;
V_4 -> V_12 [ 0 ] = 0x00 ;
V_4 -> V_12 [ 1 ] = 0x55 ;
V_4 -> V_12 [ 2 ] = 0xaa ;
V_4 -> V_12 [ 3 ] = V_8 ;
V_4 -> V_12 [ 4 ] = V_5 ;
V_4 -> V_12 [ 5 ] = V_6 ;
V_4 -> V_12 [ 6 ] = 0x00 ;
V_4 -> V_12 [ 7 ] = V_7 || V_9 ? 8 : 0 ;
V_10 = F_4 ( V_4 -> V_13 , F_5 ( V_4 -> V_13 , 2 ) ,
V_4 -> V_12 , V_14 , & V_11 , V_15 ) ;
if ( V_10 < 0 || V_11 != V_14 ) {
if ( F_6 ( & V_4 -> V_16 ) )
F_7 ( & V_4 -> V_16 . V_17 ,
L_1 , V_5 ) ;
return V_10 ? V_10 : - V_18 ;
}
if ( ! V_7 && ! V_9 )
return 0 ;
if ( V_7 ) {
memcpy ( V_4 -> V_12 , V_7 , V_8 ) ;
memset ( V_4 -> V_12 + V_8 , 0 , 8 - V_8 ) ;
V_10 = F_4 ( V_4 -> V_13 , F_5 ( V_4 -> V_13 , 2 ) ,
V_4 -> V_12 , V_14 , & V_11 , V_15 ) ;
} else {
memset ( V_4 -> V_12 , 0 , 8 ) ;
V_10 = F_4 ( V_4 -> V_13 , F_8 ( V_4 -> V_13 , 0x81 ) ,
V_4 -> V_12 , V_14 , & V_11 , V_15 ) ;
}
if ( V_10 == 0 && V_11 == V_14 )
return 0 ;
if ( F_6 ( & V_4 -> V_16 ) && V_5 != V_19 )
F_7 ( & V_4 -> V_16 . V_17 , L_2 , V_5 ) ;
return V_10 ? V_10 : - V_18 ;
}
static int F_9 ( struct V_1 * V_4 , bool V_20 )
{
int V_21 = F_3 ( V_4 ,
V_22 , V_20 , NULL , 0 , false ) ;
if ( ! V_21 )
V_4 -> V_23 = V_20 ;
return V_21 ;
}
static int F_10 ( struct V_1 * V_4 , int V_24 )
{
unsigned short V_25 = 0x10 + ( V_24 >> 3 ) / 25 ;
T_1 V_26 [ 3 ] ;
int V_10 ;
V_26 [ 0 ] = ( V_25 >> 8 ) & 0xff ;
V_26 [ 1 ] = V_25 & 0xff ;
V_26 [ 2 ] = 0x01 ;
V_10 = F_3 ( V_4 , V_27 , 0 , V_26 , 3 , false ) ;
if ( V_10 )
return V_10 ;
V_4 -> V_28 = V_24 ;
F_11 ( 40 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_4 , bool V_29 )
{
int V_21 = F_3 ( V_4 ,
V_30 , ! V_29 , NULL , 0 , false ) ;
if ( ! V_21 )
V_4 -> V_29 = V_29 ;
return V_21 ;
}
static int F_13 ( struct V_1 * V_4 , bool * V_31 , T_2 * signal )
{
int V_21 = F_3 ( V_4 ,
V_32 , 0 , NULL , 0 , true ) ;
if ( V_21 )
return V_21 ;
* V_31 = V_4 -> V_12 [ 2 ] >> 7 ;
* signal = ( V_4 -> V_12 [ 3 ] & 0xf0 ) << 8 ;
return 0 ;
}
static void F_14 ( struct V_33 * V_34 )
{
struct V_1 * V_4 = F_1 ( F_15 ( V_34 ) ) ;
F_16 ( & V_4 -> V_35 ) ;
F_17 ( & V_4 -> V_16 ) ;
F_9 ( V_4 , true ) ;
F_18 ( V_34 , NULL ) ;
F_19 ( & V_4 -> V_3 ) ;
F_20 ( & V_4 -> V_35 ) ;
F_21 ( & V_4 -> V_3 ) ;
}
static int F_22 ( struct V_36 * V_36 , void * V_37 ,
struct V_38 * V_39 )
{
struct V_1 * V_4 = F_23 ( V_36 ) ;
F_24 ( V_39 -> V_40 , L_3 , sizeof( V_39 -> V_40 ) ) ;
F_24 ( V_39 -> V_41 , L_4 , sizeof( V_39 -> V_41 ) ) ;
F_25 ( V_4 -> V_13 , V_39 -> V_42 , sizeof( V_39 -> V_42 ) ) ;
V_39 -> V_43 = V_44 | V_45 |
V_46 ;
V_39 -> V_47 = V_39 -> V_43 | V_48 ;
return 0 ;
}
static int F_26 ( struct V_36 * V_36 , void * V_37 ,
struct V_49 * V_39 )
{
struct V_1 * V_4 = F_23 ( V_36 ) ;
bool V_31 = false ;
int V_10 ;
if ( V_39 -> V_50 > 0 )
return - V_51 ;
V_39 -> signal = 0 ;
V_10 = F_13 ( V_4 , & V_31 , & V_39 -> signal ) ;
if ( V_10 )
return V_10 ;
strcpy ( V_39 -> V_52 , L_5 ) ;
V_39 -> type = V_53 ;
V_39 -> V_54 = V_55 * V_56 ;
V_39 -> V_57 = V_58 * V_56 ;
V_39 -> V_59 = V_60 | V_61 |
V_62 ;
V_39 -> V_63 = V_31 ? V_64 : V_65 ;
V_39 -> V_66 = V_4 -> V_29 ?
V_67 : V_68 ;
return 0 ;
}
static int F_27 ( struct V_36 * V_36 , void * V_37 ,
struct V_49 * V_39 )
{
struct V_1 * V_4 = F_23 ( V_36 ) ;
if ( V_39 -> V_50 > 0 )
return - V_51 ;
switch ( V_39 -> V_66 ) {
case V_68 :
return F_12 ( V_4 , V_69 ) ;
default:
return F_12 ( V_4 , V_70 ) ;
}
}
static int F_28 ( struct V_36 * V_36 , void * V_37 ,
struct V_71 * V_72 )
{
struct V_1 * V_4 = F_23 ( V_36 ) ;
if ( V_72 -> V_73 != 0 )
return - V_51 ;
return F_10 ( V_4 , F_29 ( unsigned , V_72 -> V_74 ,
V_55 * V_56 , V_58 * V_56 ) ) ;
}
static int F_30 ( struct V_36 * V_36 , void * V_37 ,
struct V_71 * V_72 )
{
struct V_1 * V_4 = F_23 ( V_36 ) ;
if ( V_72 -> V_73 != 0 || V_72 -> type != V_53 )
return - V_51 ;
V_72 -> type = V_53 ;
V_72 -> V_74 = V_4 -> V_28 ;
return 0 ;
}
static int F_31 ( struct V_36 * V_36 , void * V_37 ,
struct V_75 * V_76 )
{
static T_1 V_26 [ 8 ] = {
0x3d , 0x32 , 0x0f , 0x08 , 0x3d , 0x32 , 0x0f , 0x08
} ;
struct V_1 * V_4 = F_23 ( V_36 ) ;
unsigned long V_77 ;
int V_10 ;
if ( V_76 -> V_73 != 0 || ! V_76 -> V_78 )
return - V_51 ;
V_10 = F_3 ( V_4 ,
V_79 , 0 , V_26 , 8 , false ) ;
if ( V_10 )
return V_10 ;
F_10 ( V_4 , V_4 -> V_28 ) ;
V_10 = F_3 ( V_4 ,
V_76 -> V_80 ? V_81 : V_82 ,
0 , NULL , 0 , false ) ;
if ( V_10 )
return V_10 ;
V_77 = V_83 + F_32 ( 30000 ) ;
for (; ; ) {
if ( F_33 ( V_83 , V_77 ) ) {
V_10 = - V_84 ;
break;
}
if ( F_34 ( F_32 ( 10 ) ) ) {
V_10 = - V_85 ;
break;
}
V_10 = F_3 ( V_4 , V_19 ,
0 , NULL , 0 , true ) ;
if ( V_10 )
continue;
F_3 ( V_4 , V_86 , 0 , NULL , 0 , true ) ;
if ( V_4 -> V_12 [ 1 ] || V_4 -> V_12 [ 2 ] ) {
V_4 -> V_28 = ( V_4 -> V_12 [ 1 ] << 8 ) | V_4 -> V_12 [ 2 ] ;
V_4 -> V_28 = ( V_4 -> V_28 - 0x10 ) * 200 ;
F_3 ( V_4 , V_87 ,
0 , NULL , 0 , false ) ;
F_10 ( V_4 , V_4 -> V_28 ) ;
V_10 = 0 ;
break;
}
}
F_3 ( V_4 , V_87 , 0 , NULL , 0 , false ) ;
F_10 ( V_4 , V_4 -> V_28 ) ;
return V_10 ;
}
static int F_35 ( struct V_88 * V_89 )
{
struct V_1 * V_4 =
F_2 ( V_89 -> V_90 , struct V_1 , V_91 ) ;
switch ( V_89 -> V_92 ) {
case V_93 :
return F_9 ( V_4 , V_89 -> V_94 ) ;
}
return - V_51 ;
}
static int F_36 ( struct V_1 * V_4 )
{
int V_10 ;
V_10 = F_9 ( V_4 , true ) ;
if ( V_10 )
goto V_95;
V_10 = F_12 ( V_4 , true ) ;
if ( V_10 )
goto V_95;
V_10 = F_10 ( V_4 , V_4 -> V_28 ) ;
if ( V_10 )
goto V_95;
return 0 ;
V_95:
F_37 ( & V_4 -> V_16 . V_17 , L_6 ) ;
return V_10 ;
}
static int F_38 ( struct V_33 * V_34 , T_3 V_96 )
{
struct V_1 * V_4 = F_1 ( F_15 ( V_34 ) ) ;
F_16 ( & V_4 -> V_35 ) ;
if ( ! V_4 -> V_23 ) {
F_9 ( V_4 , true ) ;
V_4 -> V_23 = false ;
}
F_20 ( & V_4 -> V_35 ) ;
F_39 ( & V_34 -> V_17 , L_7 ) ;
return 0 ;
}
static int F_40 ( struct V_33 * V_34 )
{
struct V_1 * V_4 = F_1 ( F_15 ( V_34 ) ) ;
F_16 ( & V_4 -> V_35 ) ;
F_12 ( V_4 , V_4 -> V_29 ) ;
F_10 ( V_4 , V_4 -> V_28 ) ;
if ( ! V_4 -> V_23 )
F_9 ( V_4 , false ) ;
F_20 ( & V_4 -> V_35 ) ;
F_39 ( & V_34 -> V_17 , L_8 ) ;
return 0 ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_42 ( & V_4 -> V_91 ) ;
F_43 ( & V_4 -> V_3 ) ;
F_44 ( V_4 -> V_12 ) ;
F_44 ( V_4 ) ;
}
static int F_45 ( struct V_33 * V_34 ,
const struct V_97 * V_92 )
{
struct V_1 * V_4 ;
int V_10 = 0 ;
V_4 = F_46 ( sizeof( struct V_1 ) , V_98 ) ;
if ( ! V_4 ) {
F_47 ( & V_34 -> V_17 , L_9 ) ;
V_10 = - V_99 ;
goto V_100;
}
V_4 -> V_12 = F_48 ( V_14 , V_98 ) ;
if ( ! V_4 -> V_12 ) {
F_47 ( & V_34 -> V_17 , L_10 ) ;
V_10 = - V_99 ;
goto V_101;
}
V_10 = F_49 ( & V_34 -> V_17 , & V_4 -> V_3 ) ;
if ( V_10 < 0 ) {
F_47 ( & V_34 -> V_17 , L_11 ) ;
goto V_102;
}
F_50 ( & V_4 -> V_91 , 1 ) ;
F_51 ( & V_4 -> V_91 , & V_103 ,
V_93 , 0 , 1 , 1 , 1 ) ;
if ( V_4 -> V_91 . error ) {
V_10 = V_4 -> V_91 . error ;
F_47 ( & V_34 -> V_17 , L_12 ) ;
goto V_104;
}
F_52 ( & V_4 -> V_35 ) ;
V_4 -> V_3 . V_105 = & V_4 -> V_91 ;
V_4 -> V_3 . V_106 = F_41 ;
F_24 ( V_4 -> V_16 . V_52 , V_4 -> V_3 . V_52 ,
sizeof( V_4 -> V_16 . V_52 ) ) ;
V_4 -> V_16 . V_3 = & V_4 -> V_3 ;
V_4 -> V_16 . V_107 = & V_108 ;
V_4 -> V_16 . V_109 = & V_110 ;
V_4 -> V_16 . V_106 = V_111 ;
V_4 -> V_16 . V_35 = & V_4 -> V_35 ;
F_53 ( V_112 , & V_4 -> V_16 . V_113 ) ;
V_4 -> V_13 = F_54 ( V_34 ) ;
V_4 -> V_34 = V_34 ;
F_18 ( V_34 , & V_4 -> V_3 ) ;
V_4 -> V_28 = 95.16 * V_56 ;
F_55 ( & V_4 -> V_16 , V_4 ) ;
V_10 = F_36 ( V_4 ) ;
if ( V_10 )
goto V_114;
V_10 = F_56 ( & V_4 -> V_16 , V_115 ,
V_116 ) ;
if ( V_10 < 0 ) {
F_47 ( & V_34 -> V_17 , L_13 ) ;
goto V_114;
}
return 0 ;
V_114:
F_42 ( & V_4 -> V_91 ) ;
V_104:
F_43 ( & V_4 -> V_3 ) ;
V_102:
F_44 ( V_4 -> V_12 ) ;
V_101:
F_44 ( V_4 ) ;
V_100:
return V_10 ;
}
