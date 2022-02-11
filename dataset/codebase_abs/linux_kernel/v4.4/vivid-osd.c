void F_1 ( struct V_1 * V_2 )
{
void * V_3 = V_2 -> V_4 ;
const T_1 * V_5 = V_6 ;
unsigned V_7 , V_8 ;
if ( V_2 -> V_9 . V_10 . V_11 == 6 )
V_5 = V_12 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_13 ; V_8 ++ ) {
T_1 * V_14 = V_3 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ )
V_14 [ V_7 ] = V_5 [ ( V_8 / 16 + V_7 / 16 ) % 16 ] ;
V_3 += V_2 -> V_16 ;
}
}
static int F_2 ( struct V_17 * V_18 , unsigned V_19 , unsigned long V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_21 ;
switch ( V_19 ) {
case V_22 : {
struct V_23 V_24 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_25 = V_26 | V_27 |
V_28 ;
V_24 . V_29 = 0 ;
V_24 . V_30 = 0 ;
V_24 . V_31 = 0 ;
if ( F_3 ( ( void V_32 * ) V_20 , & V_24 , sizeof( V_24 ) ) )
return - V_33 ;
return 0 ;
}
default:
F_4 ( V_2 , 1 , L_1 , V_19 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
F_4 ( V_2 , 1 , L_2 ) ;
if ( V_36 -> V_37 != 16 ) {
F_4 ( V_2 , 1 , L_3 ) ;
return - V_34 ;
}
V_2 -> V_16 = V_36 -> V_38 * V_2 -> V_39 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
F_4 ( V_2 , 1 , L_4 ) ;
memset ( V_41 , 0 , sizeof( struct V_40 ) ) ;
F_7 ( V_41 -> V_42 , L_5 , sizeof( V_41 -> V_42 ) ) ;
V_41 -> V_43 = V_2 -> V_44 ;
V_41 -> V_45 = V_2 -> V_46 ;
V_41 -> type = V_47 ;
V_41 -> V_48 = V_49 ;
V_41 -> V_50 = 1 ;
V_41 -> V_51 = 1 ;
V_41 -> V_52 = 0 ;
V_41 -> V_53 = V_2 -> V_16 ;
V_41 -> V_54 = V_55 ;
return 0 ;
}
static int F_8 ( struct V_35 * V_36 , struct V_1 * V_2 )
{
F_4 ( V_2 , 1 , L_6 ) ;
V_36 -> V_37 = 16 ;
if ( V_36 -> V_10 . V_11 == 5 ) {
V_36 -> V_56 . V_57 = 10 ;
V_36 -> V_56 . V_11 = 5 ;
V_36 -> V_10 . V_57 = 5 ;
V_36 -> V_10 . V_11 = 5 ;
V_36 -> V_58 . V_57 = 0 ;
V_36 -> V_58 . V_11 = 5 ;
V_36 -> V_59 . V_57 = 15 ;
V_36 -> V_59 . V_11 = 1 ;
} else {
V_36 -> V_56 . V_57 = 11 ;
V_36 -> V_56 . V_11 = 5 ;
V_36 -> V_10 . V_57 = 5 ;
V_36 -> V_10 . V_11 = 6 ;
V_36 -> V_58 . V_57 = 0 ;
V_36 -> V_58 . V_11 = 5 ;
V_36 -> V_59 . V_57 = 0 ;
V_36 -> V_59 . V_11 = 0 ;
}
V_36 -> V_60 = V_36 -> V_61 = 0 ;
V_36 -> V_62 = V_36 -> V_63 = 0 ;
V_36 -> V_64 = 0 ;
V_36 -> V_65 &= ~ V_66 ;
V_36 -> V_65 = V_67 ;
V_36 -> V_68 = 24 ;
V_36 -> V_69 = 2 ;
V_36 -> V_70 = 84316 ;
V_36 -> V_71 = 776 ;
V_36 -> V_72 = 591 ;
return 0 ;
}
static int F_9 ( struct V_35 * V_36 , struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_21 ;
F_4 ( V_2 , 1 , L_6 ) ;
return F_8 ( V_36 , V_2 ) ;
}
static int F_10 ( struct V_35 * V_36 , struct V_17 * V_18 )
{
return 0 ;
}
static int F_11 ( struct V_17 * V_18 )
{
int V_73 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_21 ;
F_4 ( V_2 , 1 , L_7 ) ;
V_73 = F_5 ( V_2 , & V_18 -> V_36 ) ;
F_6 ( V_2 , & V_18 -> V_41 ) ;
return V_73 ;
}
static int F_12 ( unsigned V_74 , unsigned V_56 , unsigned V_10 ,
unsigned V_58 , unsigned V_59 ,
struct V_17 * V_18 )
{
T_2 V_75 , * V_76 ;
if ( V_74 >= V_18 -> V_77 . V_78 )
return - V_34 ;
V_75 = ( ( V_59 & 0xFF00 ) << 16 ) | ( ( V_56 & 0xFF00 ) << 8 ) |
( V_10 & 0xFF00 ) | ( ( V_58 & 0xFF00 ) >> 8 ) ;
if ( V_74 >= 16 )
return - V_34 ;
V_76 = V_18 -> V_79 ;
if ( V_18 -> V_36 . V_37 == 16 ) {
switch ( V_18 -> V_36 . V_10 . V_11 ) {
case 6 :
V_75 = ( V_56 & 0xf800 ) |
( ( V_10 & 0xfc00 ) >> 5 ) |
( ( V_58 & 0xf800 ) >> 11 ) ;
break;
case 5 :
V_75 = ( ( V_56 & 0xf800 ) >> 1 ) |
( ( V_10 & 0xf800 ) >> 6 ) |
( ( V_58 & 0xf800 ) >> 11 ) |
( V_59 ? 0x8000 : 0 ) ;
break;
}
}
V_76 [ V_74 ] = V_75 ;
return 0 ;
}
static int F_13 ( int V_80 , struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_21 ;
F_4 ( V_2 , 1 , L_8 , V_80 ) ;
switch ( V_80 ) {
case V_81 :
break;
case V_82 :
case V_83 :
case V_84 :
case V_85 :
break;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_86 V_87 ;
V_2 -> V_37 = 16 ;
V_2 -> V_39 = V_2 -> V_37 / 8 ;
V_87 . V_88 = V_89 ;
V_87 . V_90 = 0 ;
V_2 -> V_16 = V_87 . V_88 * V_2 -> V_39 ;
V_87 . V_91 = V_92 ;
V_87 . V_93 = 0 ;
V_2 -> V_15 = V_87 . V_88 ;
V_2 -> V_13 = V_87 . V_91 ;
V_2 -> V_9 . V_38 = V_2 -> V_15 ;
V_2 -> V_9 . V_94 = V_2 -> V_13 ;
V_2 -> V_9 . V_95 = V_2 -> V_15 ;
V_2 -> V_9 . V_96 = V_2 -> V_13 ;
V_2 -> V_9 . V_37 = V_2 -> V_37 ;
V_2 -> V_9 . V_65 = V_67 ;
V_2 -> V_9 . V_62 = V_87 . V_90 + 1 ;
V_2 -> V_9 . V_63 = V_87 . V_93 + 1 ;
V_2 -> V_9 . V_97 = V_55 ;
V_2 -> V_9 . V_64 = 0 ;
V_2 -> V_9 . V_10 . V_11 = 5 ;
F_8 ( & V_2 -> V_9 , V_2 ) ;
F_6 ( V_2 , & V_2 -> V_98 ) ;
V_2 -> V_17 . V_99 = - 1 ;
V_2 -> V_17 . V_25 = V_100 ;
V_2 -> V_17 . V_101 = & V_102 ;
V_2 -> V_17 . V_21 = V_2 ;
V_2 -> V_17 . V_36 = V_2 -> V_9 ;
V_2 -> V_17 . V_41 = V_2 -> V_98 ;
V_2 -> V_17 . V_103 = ( V_104 V_105 * ) V_2 -> V_4 ;
V_2 -> V_17 . V_101 = & V_102 ;
V_2 -> V_17 . V_106 . V_107 = 8000 ;
V_2 -> V_17 . V_106 . V_108 = 70000 ;
V_2 -> V_17 . V_106 . V_109 = 10 ;
V_2 -> V_17 . V_106 . V_110 = 100 ;
if ( F_15 ( & V_2 -> V_17 . V_77 , 256 , 1 ) ) {
F_16 ( L_9 ) ;
return - V_111 ;
}
V_2 -> V_17 . V_79 = F_17 ( 16 , sizeof( T_2 ) , V_112 ) ;
return V_2 -> V_17 . V_79 ? 0 : - V_111 ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 == NULL )
return;
if ( V_2 -> V_17 . V_77 . V_78 )
F_19 ( & V_2 -> V_17 . V_77 ) ;
F_20 ( V_2 -> V_17 . V_79 ) ;
F_20 ( ( void * ) V_2 -> V_4 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_113 ;
V_2 -> V_46 = V_92 * V_89 * 2 ;
V_2 -> V_4 = F_22 ( V_2 -> V_46 , V_112 | V_114 ) ;
if ( V_2 -> V_4 == NULL )
return - V_111 ;
V_2 -> V_44 = F_23 ( V_2 -> V_4 ) ;
F_24 ( L_10 ,
V_2 -> V_44 , V_2 -> V_4 ,
V_2 -> V_46 / 1024 ) ;
V_113 = F_14 ( V_2 ) ;
if ( V_113 ) {
F_18 ( V_2 ) ;
return V_113 ;
}
F_1 ( V_2 ) ;
if ( F_25 ( & V_2 -> V_17 ) < 0 ) {
F_18 ( V_2 ) ;
return - V_34 ;
}
F_11 ( & V_2 -> V_17 ) ;
return 0 ;
}
