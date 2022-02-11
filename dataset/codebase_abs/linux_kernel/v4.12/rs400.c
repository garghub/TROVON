void F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . V_4 / ( 1024 * 1024 ) ) {
case 32 :
case 64 :
case 128 :
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
default:
F_2 ( L_1 ,
( unsigned ) ( V_2 -> V_3 . V_4 >> 20 ) ) ;
F_2 ( L_2 ) ;
F_2 ( L_3 ) ;
V_2 -> V_3 . V_4 = 32 * 1024 * 1024 ;
return;
}
}
void F_3 ( struct V_1 * V_2 )
{
T_1 V_5 ;
unsigned int V_6 = V_2 -> V_7 ;
F_4 ( V_8 , V_9 ) ;
do {
V_5 = F_5 ( V_8 ) ;
if ( ( V_5 & V_9 ) == 0 )
break;
F_6 ( 1 ) ;
V_6 -- ;
} while ( V_6 > 0 );
F_4 ( V_8 , 0 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_11 . V_12 ) {
F_8 ( 1 , L_4 ) ;
return 0 ;
}
switch( V_2 -> V_3 . V_4 / ( 1024 * 1024 ) ) {
case 32 :
case 64 :
case 128 :
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
default:
return - V_13 ;
}
V_10 = F_9 ( V_2 ) ;
if ( V_10 )
return V_10 ;
if ( F_10 ( V_2 ) )
F_2 ( L_5 ) ;
V_2 -> V_11 . V_14 = V_2 -> V_11 . V_15 * 4 ;
return F_11 ( V_2 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
T_1 V_16 ;
T_1 V_5 ;
V_5 = F_5 ( V_17 ) ;
V_5 |= V_18 ;
F_4 ( V_17 , V_5 ) ;
switch( V_2 -> V_3 . V_4 / ( 1024 * 1024 ) ) {
case 32 :
V_16 = V_19 ;
break;
case 64 :
V_16 = V_20 ;
break;
case 128 :
V_16 = V_21 ;
break;
case 256 :
V_16 = V_22 ;
break;
case 512 :
V_16 = V_23 ;
break;
case 1024 :
V_16 = V_24 ;
break;
case 2048 :
V_16 = V_25 ;
break;
default:
return - V_13 ;
}
if ( V_2 -> V_26 == V_27 || ( V_2 -> V_26 == V_28 ) ) {
F_4 ( V_29 , 0xFFFFFFFF ) ;
F_4 ( V_30 , 0 ) ;
} else {
F_13 ( V_31 , 0xFFFFFFFF ) ;
F_13 ( V_32 , 0 ) ;
}
V_5 = F_14 ( V_33 , V_2 -> V_3 . V_34 >> 16 ) ;
V_5 |= F_14 ( V_35 , V_2 -> V_3 . V_36 >> 16 ) ;
if ( ( V_2 -> V_26 == V_27 ) || ( V_2 -> V_26 == V_28 ) ) {
F_4 ( V_37 , V_5 ) ;
V_5 = F_15 ( V_38 ) & ~ V_39 ;
F_13 ( V_38 , V_5 ) ;
} else {
F_13 ( V_40 , V_5 ) ;
V_5 = F_15 ( V_38 ) & ~ V_41 ;
F_13 ( V_38 , V_5 ) ;
}
V_5 = ( V_42 ) V_2 -> V_11 . V_43 & 0xfffff000 ;
V_5 |= ( F_16 ( V_2 -> V_11 . V_43 ) & 0xff ) << 4 ;
F_4 ( V_44 , V_5 ) ;
F_4 ( V_45 ,
( V_46 |
V_47 | V_48 ) ) ;
F_4 ( V_49 ,
( 1 << V_50 ) | V_51 ) ;
if ( ( V_2 -> V_26 == V_27 ) || ( V_2 -> V_26 == V_28 ) ) {
V_5 = F_5 ( V_52 ) ;
V_5 |= V_53 | V_54 ;
F_4 ( V_52 , V_5 ) ;
} else {
V_5 = F_5 ( V_52 ) ;
V_5 |= V_53 ;
F_4 ( V_52 , V_5 ) ;
}
F_4 ( V_55 , ( V_56 | V_16 ) ) ;
F_3 ( V_2 ) ;
F_17 ( L_6 ,
( unsigned ) ( V_2 -> V_3 . V_4 >> 20 ) ,
( unsigned long long ) V_2 -> V_11 . V_43 ) ;
V_2 -> V_11 . V_57 = true ;
return 0 ;
}
void F_18 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_5 ( V_17 ) ;
V_5 |= V_18 ;
F_4 ( V_17 , V_5 ) ;
F_4 ( V_55 , 0 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
F_18 ( V_2 ) ;
F_21 ( V_2 ) ;
}
T_2 F_22 ( T_2 V_58 , T_1 V_59 )
{
T_1 V_60 ;
V_60 = ( F_23 ( V_58 ) & V_61 ) |
( ( F_16 ( V_58 ) & 0xff ) << 4 ) ;
if ( V_59 & V_62 )
V_60 |= V_63 ;
if ( V_59 & V_64 )
V_60 |= V_65 ;
if ( ! ( V_59 & V_66 ) )
V_60 |= V_67 ;
return V_60 ;
}
void F_24 ( struct V_1 * V_2 , unsigned V_68 ,
T_2 V_60 )
{
V_42 * V_69 = V_2 -> V_11 . V_12 ;
V_69 [ V_68 ] = F_25 ( F_23 ( V_60 ) ) ;
}
int F_26 ( struct V_1 * V_2 )
{
unsigned V_68 ;
T_1 V_5 ;
for ( V_68 = 0 ; V_68 < V_2 -> V_7 ; V_68 ++ ) {
V_5 = F_15 ( V_70 ) ;
if ( V_5 & V_71 ) {
return 0 ;
}
F_6 ( 1 ) ;
}
return - 1 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
if ( F_26 ( V_2 ) ) {
F_29 ( L_7 ,
F_15 ( V_70 ) ) ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
T_3 V_72 ;
F_1 ( V_2 ) ;
V_2 -> V_3 . V_73 = F_31 ( V_2 ) ;
V_2 -> V_3 . V_74 = true ;
V_2 -> V_3 . V_75 = 128 ;
F_32 ( V_2 ) ;
V_72 = ( F_15 ( V_76 ) & 0xffff ) << 16 ;
F_33 ( V_2 , & V_2 -> V_3 , V_72 ) ;
V_2 -> V_3 . V_77 = V_2 -> V_3 . V_4 - 1 ;
F_34 ( V_2 , & V_2 -> V_3 ) ;
F_35 ( V_2 ) ;
}
T_1 F_36 ( struct V_1 * V_2 , T_1 V_78 )
{
unsigned long V_59 ;
T_1 V_10 ;
F_37 ( & V_2 -> V_79 , V_59 ) ;
F_13 ( V_80 , V_78 & 0xff ) ;
V_10 = F_15 ( V_81 ) ;
F_13 ( V_80 , 0xff ) ;
F_38 ( & V_2 -> V_79 , V_59 ) ;
return V_10 ;
}
void F_39 ( struct V_1 * V_2 , T_1 V_78 , T_1 V_82 )
{
unsigned long V_59 ;
F_37 ( & V_2 -> V_79 , V_59 ) ;
F_13 ( V_80 , ( ( V_78 ) & 0xff ) | V_83 ) ;
F_13 ( V_81 , ( V_82 ) ) ;
F_13 ( V_80 , 0xff ) ;
F_38 ( & V_2 -> V_79 , V_59 ) ;
}
static int F_40 ( struct V_84 * V_85 , void * V_86 )
{
struct V_87 * V_88 = (struct V_87 * ) V_85 -> V_89 ;
struct V_90 * V_91 = V_88 -> V_92 -> V_91 ;
struct V_1 * V_2 = V_91 -> V_93 ;
T_1 V_5 ;
V_5 = F_15 ( V_94 ) ;
F_41 ( V_85 , L_8 , V_5 ) ;
V_5 = F_15 ( V_38 ) ;
F_41 ( V_85 , L_9 , V_5 ) ;
V_5 = F_5 ( V_17 ) ;
F_41 ( V_85 , L_10 , V_5 ) ;
if ( V_2 -> V_26 == V_27 || ( V_2 -> V_26 == V_28 ) ) {
V_5 = F_5 ( V_29 ) ;
F_41 ( V_85 , L_11 , V_5 ) ;
V_5 = F_5 ( V_30 ) ;
F_41 ( V_85 , L_12 , V_5 ) ;
V_5 = F_5 ( V_37 ) ;
F_41 ( V_85 , L_13 , V_5 ) ;
V_5 = F_5 ( V_95 ) ;
F_41 ( V_85 , L_14 , V_5 ) ;
V_5 = F_15 ( V_96 ) ;
F_41 ( V_85 , L_15 , V_5 ) ;
} else {
V_5 = F_15 ( V_31 ) ;
F_41 ( V_85 , L_16 , V_5 ) ;
V_5 = F_15 ( V_32 ) ;
F_41 ( V_85 , L_17 , V_5 ) ;
V_5 = F_15 ( V_40 ) ;
F_41 ( V_85 , L_18 , V_5 ) ;
}
V_5 = F_5 ( V_44 ) ;
F_41 ( V_85 , L_19 , V_5 ) ;
V_5 = F_5 ( V_45 ) ;
F_41 ( V_85 , L_20 , V_5 ) ;
V_5 = F_5 ( V_49 ) ;
F_41 ( V_85 , L_21 , V_5 ) ;
V_5 = F_5 ( V_52 ) ;
F_41 ( V_85 , L_22 , V_5 ) ;
V_5 = F_5 ( 0x5F ) ;
F_41 ( V_85 , L_23 , V_5 ) ;
V_5 = F_5 ( V_55 ) ;
F_41 ( V_85 , L_24 , V_5 ) ;
V_5 = F_5 ( V_8 ) ;
F_41 ( V_85 , L_25 , V_5 ) ;
V_5 = F_5 ( 0x3B ) ;
F_41 ( V_85 , L_26 , V_5 ) ;
V_5 = F_5 ( 0x3C ) ;
F_41 ( V_85 , L_27 , V_5 ) ;
V_5 = F_5 ( 0x30 ) ;
F_41 ( V_85 , L_28 , V_5 ) ;
V_5 = F_5 ( 0x31 ) ;
F_41 ( V_85 , L_29 , V_5 ) ;
V_5 = F_5 ( 0x32 ) ;
F_41 ( V_85 , L_30 , V_5 ) ;
V_5 = F_5 ( 0x33 ) ;
F_41 ( V_85 , L_31 , V_5 ) ;
V_5 = F_5 ( 0x34 ) ;
F_41 ( V_85 , L_32 , V_5 ) ;
V_5 = F_5 ( 0x35 ) ;
F_41 ( V_85 , L_33 , V_5 ) ;
V_5 = F_5 ( 0x36 ) ;
F_41 ( V_85 , L_34 , V_5 ) ;
V_5 = F_5 ( 0x37 ) ;
F_41 ( V_85 , L_35 , V_5 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
#if F_42 ( V_97 )
return F_43 ( V_2 , V_98 , 1 ) ;
#else
return 0 ;
#endif
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_99 V_100 ;
F_45 ( V_2 , & V_100 ) ;
if ( F_26 ( V_2 ) )
F_46 ( V_2 -> V_91 , L_36 ) ;
F_13 ( V_101 ,
F_47 ( V_2 -> V_3 . V_102 >> 16 ) |
F_48 ( V_2 -> V_3 . V_103 >> 16 ) ) ;
F_49 ( V_2 , & V_100 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_10 ;
F_51 ( V_2 ) ;
F_44 ( V_2 ) ;
F_52 ( V_2 ) ;
F_27 ( V_2 ) ;
F_53 ( V_2 ) ;
V_10 = F_12 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_54 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_55 ( V_2 , V_104 ) ;
if ( V_10 ) {
F_56 ( V_2 -> V_91 , L_37 , V_10 ) ;
return V_10 ;
}
if ( ! V_2 -> V_105 . V_106 ) {
V_10 = F_57 ( V_2 ) ;
if ( V_10 )
return V_10 ;
}
F_58 ( V_2 ) ;
V_2 -> V_107 . V_108 . V_109 = F_15 ( V_94 ) ;
V_10 = F_59 ( V_2 , 1024 * 1024 ) ;
if ( V_10 ) {
F_56 ( V_2 -> V_91 , L_38 , V_10 ) ;
return V_10 ;
}
V_10 = F_60 ( V_2 ) ;
if ( V_10 ) {
F_56 ( V_2 -> V_91 , L_39 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
int F_61 ( struct V_1 * V_2 )
{
int V_10 ;
F_18 ( V_2 ) ;
F_52 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( F_62 ( V_2 ) ) {
F_46 ( V_2 -> V_91 , L_40 ,
F_15 ( V_110 ) ,
F_15 ( V_111 ) ) ;
}
F_63 ( V_2 -> V_112 ) ;
F_52 ( V_2 ) ;
F_64 ( V_2 ) ;
V_2 -> V_113 = true ;
V_10 = F_50 ( V_2 ) ;
if ( V_10 ) {
V_2 -> V_113 = false ;
}
return V_10 ;
}
int F_65 ( struct V_1 * V_2 )
{
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
void F_70 ( struct V_1 * V_2 )
{
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
F_19 ( V_2 ) ;
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
F_80 ( V_2 -> V_114 ) ;
V_2 -> V_114 = NULL ;
}
int F_81 ( struct V_1 * V_2 )
{
int V_10 ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
F_64 ( V_2 ) ;
F_84 ( V_2 ) ;
if ( ! F_85 ( V_2 ) ) {
if ( F_86 ( V_2 ) )
return - V_13 ;
}
if ( V_2 -> V_115 ) {
F_56 ( V_2 -> V_91 , L_41 ) ;
return - V_13 ;
} else {
V_10 = F_87 ( V_2 ) ;
if ( V_10 )
return V_10 ;
}
if ( F_62 ( V_2 ) ) {
F_46 ( V_2 -> V_91 ,
L_40 ,
F_15 ( V_110 ) ,
F_15 ( V_111 ) ) ;
}
if ( F_88 ( V_2 ) == false )
return - V_13 ;
F_89 ( V_2 -> V_112 ) ;
F_30 ( V_2 ) ;
V_10 = F_90 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_91 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_7 ( V_2 ) ;
if ( V_10 )
return V_10 ;
F_92 ( V_2 ) ;
F_93 ( V_2 ) ;
V_2 -> V_113 = true ;
V_10 = F_50 ( V_2 ) ;
if ( V_10 ) {
F_56 ( V_2 -> V_91 , L_42 ) ;
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
F_19 ( V_2 ) ;
F_76 ( V_2 ) ;
V_2 -> V_113 = false ;
}
return 0 ;
}
