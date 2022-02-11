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
if ( V_2 -> V_11 . V_12 . V_13 . V_14 ) {
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
return - V_15 ;
}
V_10 = F_9 ( V_2 ) ;
if ( V_10 )
return V_10 ;
if ( F_10 ( V_2 ) )
F_2 ( L_5 ) ;
V_2 -> V_11 . V_16 = V_2 -> V_11 . V_17 * 4 ;
return F_11 ( V_2 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
T_1 V_18 ;
T_1 V_5 ;
F_13 ( V_2 ) ;
V_5 = F_5 ( V_19 ) ;
V_5 |= V_20 ;
F_4 ( V_19 , V_5 ) ;
switch( V_2 -> V_3 . V_4 / ( 1024 * 1024 ) ) {
case 32 :
V_18 = V_21 ;
break;
case 64 :
V_18 = V_22 ;
break;
case 128 :
V_18 = V_23 ;
break;
case 256 :
V_18 = V_24 ;
break;
case 512 :
V_18 = V_25 ;
break;
case 1024 :
V_18 = V_26 ;
break;
case 2048 :
V_18 = V_27 ;
break;
default:
return - V_15 ;
}
if ( V_2 -> V_28 == V_29 || ( V_2 -> V_28 == V_30 ) ) {
F_4 ( V_31 , 0xFFFFFFFF ) ;
F_4 ( V_32 , 0 ) ;
} else {
F_14 ( V_33 , 0xFFFFFFFF ) ;
F_14 ( V_34 , 0 ) ;
}
V_5 = F_15 ( V_35 , V_2 -> V_3 . V_36 >> 16 ) ;
V_5 |= F_15 ( V_37 , V_2 -> V_3 . V_38 >> 16 ) ;
if ( ( V_2 -> V_28 == V_29 ) || ( V_2 -> V_28 == V_30 ) ) {
F_4 ( V_39 , V_5 ) ;
V_5 = F_16 ( V_40 ) & ~ V_41 ;
F_14 ( V_40 , V_5 ) ;
} else {
F_14 ( V_42 , V_5 ) ;
V_5 = F_16 ( V_40 ) & ~ V_43 ;
F_14 ( V_40 , V_5 ) ;
}
V_5 = ( V_44 ) V_2 -> V_11 . V_45 & 0xfffff000 ;
V_5 |= ( F_17 ( V_2 -> V_11 . V_45 ) & 0xff ) << 4 ;
F_4 ( V_46 , V_5 ) ;
F_4 ( V_47 ,
( V_48 |
V_49 | V_50 ) ) ;
F_4 ( V_51 ,
( 1 << V_52 ) | V_53 ) ;
if ( ( V_2 -> V_28 == V_29 ) || ( V_2 -> V_28 == V_30 ) ) {
F_4 ( V_54 ,
( V_55 | V_56 ) ) ;
} else {
F_4 ( V_54 , V_55 ) ;
}
F_4 ( V_57 , ( V_58 | V_18 ) ) ;
F_3 ( V_2 ) ;
V_2 -> V_11 . V_59 = true ;
return 0 ;
}
void F_18 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_5 ( V_19 ) ;
V_5 |= V_20 ;
F_4 ( V_19 , V_5 ) ;
F_4 ( V_57 , 0 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
F_18 ( V_2 ) ;
F_21 ( V_2 ) ;
}
int F_22 ( struct V_1 * V_2 , int V_60 , T_2 V_61 )
{
T_1 V_62 ;
if ( V_60 < 0 || V_60 > V_2 -> V_11 . V_17 ) {
return - V_15 ;
}
V_62 = ( F_23 ( V_61 ) & V_63 ) |
( ( F_17 ( V_61 ) & 0xff ) << 4 ) |
V_64 | V_65 ;
V_62 = F_24 ( V_62 ) ;
V_2 -> V_11 . V_12 . V_13 . V_14 [ V_60 ] = V_62 ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
unsigned V_60 ;
T_1 V_5 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_7 ; V_60 ++ ) {
V_5 = F_16 ( V_66 ) ;
if ( V_5 & V_67 ) {
return 0 ;
}
F_6 ( 1 ) ;
}
return - 1 ;
}
void F_26 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
if ( F_25 ( V_2 ) ) {
F_28 ( V_68 L_6
L_7 , F_16 ( V_66 ) ) ;
}
}
void F_29 ( struct V_1 * V_2 )
{
T_3 V_69 ;
F_1 ( V_2 ) ;
V_2 -> V_3 . V_70 = F_30 ( V_2 ) ;
V_2 -> V_3 . V_71 = true ;
V_2 -> V_3 . V_72 = 128 ;
F_31 ( V_2 ) ;
V_69 = ( F_16 ( V_73 ) & 0xffff ) << 16 ;
F_32 ( V_2 , & V_2 -> V_3 , V_69 ) ;
V_2 -> V_3 . V_74 = V_2 -> V_3 . V_4 - 1 ;
F_33 ( V_2 , & V_2 -> V_3 ) ;
F_34 ( V_2 ) ;
}
T_1 F_35 ( struct V_1 * V_2 , T_1 V_75 )
{
T_1 V_10 ;
F_14 ( V_76 , V_75 & 0xff ) ;
V_10 = F_16 ( V_77 ) ;
F_14 ( V_76 , 0xff ) ;
return V_10 ;
}
void F_36 ( struct V_1 * V_2 , T_1 V_75 , T_1 V_78 )
{
F_14 ( V_76 , ( ( V_75 ) & 0xff ) | V_79 ) ;
F_14 ( V_77 , ( V_78 ) ) ;
F_14 ( V_76 , 0xff ) ;
}
static int F_37 ( struct V_80 * V_81 , void * V_82 )
{
struct V_83 * V_84 = (struct V_83 * ) V_81 -> V_85 ;
struct V_86 * V_87 = V_84 -> V_88 -> V_87 ;
struct V_1 * V_2 = V_87 -> V_89 ;
T_1 V_5 ;
V_5 = F_16 ( V_90 ) ;
F_38 ( V_81 , L_8 , V_5 ) ;
V_5 = F_16 ( V_40 ) ;
F_38 ( V_81 , L_9 , V_5 ) ;
V_5 = F_5 ( V_19 ) ;
F_38 ( V_81 , L_10 , V_5 ) ;
if ( V_2 -> V_28 == V_29 || ( V_2 -> V_28 == V_30 ) ) {
V_5 = F_5 ( V_31 ) ;
F_38 ( V_81 , L_11 , V_5 ) ;
V_5 = F_5 ( V_32 ) ;
F_38 ( V_81 , L_12 , V_5 ) ;
V_5 = F_5 ( V_39 ) ;
F_38 ( V_81 , L_13 , V_5 ) ;
V_5 = F_5 ( V_91 ) ;
F_38 ( V_81 , L_14 , V_5 ) ;
V_5 = F_16 ( V_92 ) ;
F_38 ( V_81 , L_15 , V_5 ) ;
} else {
V_5 = F_16 ( V_33 ) ;
F_38 ( V_81 , L_16 , V_5 ) ;
V_5 = F_16 ( V_34 ) ;
F_38 ( V_81 , L_17 , V_5 ) ;
V_5 = F_16 ( V_42 ) ;
F_38 ( V_81 , L_18 , V_5 ) ;
}
V_5 = F_5 ( V_46 ) ;
F_38 ( V_81 , L_19 , V_5 ) ;
V_5 = F_5 ( V_47 ) ;
F_38 ( V_81 , L_20 , V_5 ) ;
V_5 = F_5 ( V_51 ) ;
F_38 ( V_81 , L_21 , V_5 ) ;
V_5 = F_5 ( V_54 ) ;
F_38 ( V_81 , L_22 , V_5 ) ;
V_5 = F_5 ( 0x5F ) ;
F_38 ( V_81 , L_23 , V_5 ) ;
V_5 = F_5 ( V_57 ) ;
F_38 ( V_81 , L_24 , V_5 ) ;
V_5 = F_5 ( V_8 ) ;
F_38 ( V_81 , L_25 , V_5 ) ;
V_5 = F_5 ( 0x3B ) ;
F_38 ( V_81 , L_26 , V_5 ) ;
V_5 = F_5 ( 0x3C ) ;
F_38 ( V_81 , L_27 , V_5 ) ;
V_5 = F_5 ( 0x30 ) ;
F_38 ( V_81 , L_28 , V_5 ) ;
V_5 = F_5 ( 0x31 ) ;
F_38 ( V_81 , L_29 , V_5 ) ;
V_5 = F_5 ( 0x32 ) ;
F_38 ( V_81 , L_30 , V_5 ) ;
V_5 = F_5 ( 0x33 ) ;
F_38 ( V_81 , L_31 , V_5 ) ;
V_5 = F_5 ( 0x34 ) ;
F_38 ( V_81 , L_32 , V_5 ) ;
V_5 = F_5 ( 0x35 ) ;
F_38 ( V_81 , L_33 , V_5 ) ;
V_5 = F_5 ( 0x36 ) ;
F_38 ( V_81 , L_34 , V_5 ) ;
V_5 = F_5 ( 0x37 ) ;
F_38 ( V_81 , L_35 , V_5 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
#if F_39 ( V_93 )
return F_40 ( V_2 , V_94 , 1 ) ;
#else
return 0 ;
#endif
}
void F_41 ( struct V_1 * V_2 )
{
struct V_95 V_96 ;
F_42 ( V_2 , & V_96 ) ;
if ( F_25 ( V_2 ) )
F_43 ( V_2 -> V_87 , L_36 ) ;
F_14 ( V_97 ,
F_44 ( V_2 -> V_3 . V_98 >> 16 ) |
F_45 ( V_2 -> V_3 . V_99 >> 16 ) ) ;
F_46 ( V_2 , & V_96 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_10 ;
F_48 ( V_2 ) ;
F_41 ( V_2 ) ;
F_49 ( V_2 ) ;
F_26 ( V_2 ) ;
F_50 ( V_2 ) ;
V_10 = F_12 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_51 ( V_2 ) ;
if ( V_10 )
return V_10 ;
F_52 ( V_2 ) ;
V_2 -> V_100 . V_101 . V_102 = F_16 ( V_90 ) ;
V_10 = F_53 ( V_2 , 1024 * 1024 ) ;
if ( V_10 ) {
F_54 ( V_2 -> V_87 , L_37 , V_10 ) ;
return V_10 ;
}
V_10 = F_55 ( V_2 ) ;
if ( V_10 ) {
F_54 ( V_2 -> V_87 , L_38 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
int F_56 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
F_49 ( V_2 ) ;
F_41 ( V_2 ) ;
if ( F_57 ( V_2 ) ) {
F_43 ( V_2 -> V_87 , L_39 ,
F_16 ( V_103 ) ,
F_16 ( V_104 ) ) ;
}
F_58 ( V_2 -> V_105 ) ;
F_49 ( V_2 ) ;
F_59 ( V_2 ) ;
return F_47 ( V_2 ) ;
}
int F_60 ( struct V_1 * V_2 )
{
F_61 ( V_2 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
void F_64 ( struct V_1 * V_2 )
{
F_65 ( V_2 ) ;
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
F_19 ( V_2 ) ;
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
F_73 ( V_2 -> V_106 ) ;
V_2 -> V_106 = NULL ;
}
int F_74 ( struct V_1 * V_2 )
{
int V_10 ;
F_75 ( V_2 ) ;
F_76 ( V_2 ) ;
F_59 ( V_2 ) ;
F_77 ( V_2 ) ;
if ( ! F_78 ( V_2 ) ) {
if ( F_79 ( V_2 ) )
return - V_15 ;
}
if ( V_2 -> V_107 ) {
F_54 ( V_2 -> V_87 , L_40 ) ;
return - V_15 ;
} else {
V_10 = F_80 ( V_2 ) ;
if ( V_10 )
return V_10 ;
}
if ( F_57 ( V_2 ) ) {
F_43 ( V_2 -> V_87 ,
L_39 ,
F_16 ( V_103 ) ,
F_16 ( V_104 ) ) ;
}
if ( F_81 ( V_2 ) == false )
return - V_15 ;
F_82 ( V_2 -> V_105 ) ;
F_29 ( V_2 ) ;
V_10 = F_83 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_84 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_85 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_7 ( V_2 ) ;
if ( V_10 )
return V_10 ;
F_86 ( V_2 ) ;
V_2 -> V_108 = true ;
V_10 = F_47 ( V_2 ) ;
if ( V_10 ) {
F_54 ( V_2 -> V_87 , L_41 ) ;
F_65 ( V_2 ) ;
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
F_19 ( V_2 ) ;
F_69 ( V_2 ) ;
V_2 -> V_108 = false ;
}
return 0 ;
}
