void F_1 ( T_1 * V_1 , int V_2 )
{
F_2 ( V_1 , V_3 , V_4 , ( V_2 ? V_4 : V_5 ) ) ;
}
static int F_3 ( T_1 * V_1 )
{
return 1 ;
}
static void F_4 ( T_1 * V_1 , unsigned char * V_6 , int V_7 , int V_8 , int V_9 )
{
unsigned char V_10 ;
int V_11 ;
V_10 = ( 1 << ( * V_1 -> V_12 ) [ V_7 ] [ V_8 ] . V_13 ) - 1 ;
V_9 = ( int ) ( ( V_9 * V_10 ) + 50 ) / 100 ;
V_11 = ( * V_1 -> V_12 ) [ V_7 ] [ V_8 ] . V_14 - ( * V_1 -> V_12 ) [ V_7 ] [ V_15 ] . V_13 + 1 ;
* V_6 &= ~ ( V_10 << V_11 ) ;
* V_6 |= ( V_9 & V_10 ) << V_11 ;
}
static int F_5 ( T_1 * V_1 , int V_7 )
{
if ( ! ( ( 1 << V_7 ) & V_1 -> V_16 ) )
return - V_17 ;
return V_1 -> V_18 [ V_7 ] ;
}
void F_6 ( T_1 * V_1 )
{
int V_19 ;
F_7 ( V_1 , 0x00 , 0x18 ) ;
F_7 ( V_1 , 0x10 , 0x38 ) ;
V_1 -> V_16 = 0 ;
for ( V_19 = 0 ; V_19 < sizeof( V_20 ) ; V_19 ++ )
if ( V_20 [ V_19 ] != 0 )
V_1 -> V_16 |= ( 1 << V_19 ) ;
V_1 -> V_21 = V_1 -> V_16 &
~ ( V_22 | V_23 | V_24 | V_25 ) ;
F_8 ( V_1 ) ;
}
int F_9 ( T_1 * V_1 , int V_7 , int V_26 , int V_27 )
{
int V_28 ;
unsigned char V_29 ;
if ( ( V_7 < 0 ) || ( V_7 >= V_1 -> V_30 ) )
return - V_17 ;
V_28 = ( * V_1 -> V_12 ) [ V_7 ] [ V_15 ] . V_31 ;
if ( V_28 == 0 )
return - V_17 ;
V_29 = F_10 ( V_1 , V_28 ) ;
F_4 ( V_1 , & V_29 , V_7 , V_15 , V_26 ) ;
if ( ( * V_1 -> V_12 ) [ V_7 ] [ V_32 ] . V_31 != V_28 )
{
F_7 ( V_1 , V_28 , V_29 ) ;
V_28 = ( * V_1 -> V_12 ) [ V_7 ] [ V_32 ] . V_31 ;
if ( V_28 == 0 )
return V_26 | ( V_26 << 8 ) ;
V_29 = F_10 ( V_1 , V_28 ) ;
}
F_4 ( V_1 , & V_29 , V_7 , V_32 , V_27 ) ;
F_7 ( V_1 , V_28 , V_29 ) ;
return V_26 | ( V_27 << 8 ) ;
}
static int F_11 ( T_1 * V_1 , int V_7 , int V_26 , int V_27 )
{
int V_33 , V_29 ;
switch ( V_7 )
{
case V_34 :
F_7 ( V_1 , 0x0b , 96 - ( 96 * V_26 / 100 ) ) ;
F_7 ( V_1 , 0x0c , 96 - ( 96 * V_27 / 100 ) ) ;
break;
case V_35 :
case V_36 :
V_1 -> V_18 [ V_7 ] = V_26 | ( V_27 << 8 ) ;
V_29 = ( ( V_1 -> V_18 [ V_36 ] & 0xff ) * 16 / ( unsigned ) 100 ) << 4 ;
V_29 |= ( ( V_1 -> V_18 [ V_35 ] & 0xff ) * 16 / ( unsigned ) 100 ) & 0x0f ;
F_7 ( V_1 , 0x0d , V_29 ) ;
V_29 = ( ( ( V_1 -> V_18 [ V_36 ] >> 8 ) & 0xff ) * 16 / ( unsigned ) 100 ) << 4 ;
V_29 |= ( ( ( V_1 -> V_18 [ V_35 ] >> 8 ) & 0xff ) * 16 / ( unsigned ) 100 ) & 0x0f ;
F_7 ( V_1 , 0x0e , V_29 ) ;
break;
default:
if ( V_7 < 0 || V_7 >= F_12 ( V_20 ) )
return - V_17 ;
V_33 = V_20 [ V_7 ] ;
if ( V_33 == 0 )
return - V_17 ;
F_7 ( V_1 , V_33 , ( 24 - ( 24 * V_26 / 100 ) ) | 0x20 ) ;
F_7 ( V_1 , V_33 + 1 , ( 24 - ( 24 * V_27 / 100 ) ) | 0x40 ) ;
}
V_1 -> V_18 [ V_7 ] = V_26 | ( V_27 << 8 ) ;
return V_26 | ( V_27 << 8 ) ;
}
static int F_13 ( T_1 * V_1 , int V_7 , int V_37 )
{
int V_26 = V_37 & 0x000000ff ;
int V_27 = ( V_37 & 0x0000ff00 ) >> 8 ;
int V_38 ;
if ( V_26 > 100 )
V_26 = 100 ;
if ( V_27 > 100 )
V_27 = 100 ;
if ( ( V_7 < 0 ) || ( V_7 > 31 ) )
return - V_17 ;
if ( ! ( V_1 -> V_16 & ( 1 << V_7 ) ) )
return - V_17 ;
switch ( V_1 -> V_39 ) {
case V_40 :
V_38 = F_11 ( V_1 , V_7 , V_26 , V_27 ) ;
break;
case V_41 :
V_38 = F_14 ( V_1 , V_7 , V_26 , V_27 ) ;
break;
default:
V_38 = F_9 ( V_1 , V_7 , V_26 , V_27 ) ;
}
if ( V_38 >= 0 ) V_1 -> V_18 [ V_7 ] = V_38 ;
return V_38 ;
}
static void F_15 ( T_1 * V_1 , int V_42 )
{
F_7 ( V_1 , V_43 , ( F_10 ( V_1 , V_43 ) & ~ 7 ) | ( V_42 & 0x7 ) ) ;
}
static int F_16 ( T_1 * V_1 , int V_10 )
{
int V_44 , V_19 ;
unsigned char V_45 , V_46 ;
V_44 = V_10 & V_1 -> V_21 ;
switch ( V_1 -> V_39 )
{
case V_47 :
case V_41 :
case V_48 :
case V_40 :
if ( V_1 -> V_39 == V_41 && F_17 ( V_1 , & V_44 ) ) {
break;
}
if ( V_44 != V_49 &&
V_44 != V_50 &&
V_44 != V_51 )
{
V_44 &= ~ V_1 -> V_52 ;
}
if ( V_44 != V_49 &&
V_44 != V_50 &&
V_44 != V_51 )
{
V_44 = V_49 ;
}
if ( V_44 ^ V_1 -> V_52 )
{
switch ( V_44 )
{
case V_49 :
F_15 ( V_1 , V_53 ) ;
break;
case V_50 :
F_15 ( V_1 , V_54 ) ;
break;
case V_51 :
F_15 ( V_1 , V_55 ) ;
break;
default:
F_15 ( V_1 , V_53 ) ;
}
}
break;
case V_56 :
if ( ! V_44 )
V_44 = V_49 ;
if ( V_1 -> V_57 == V_58 )
{
switch ( V_44 )
{
case V_50 :
F_7 ( V_1 , V_59 , V_60 ) ;
break;
case V_51 :
F_7 ( V_1 , V_59 , V_61 ) ;
break;
case V_62 :
F_7 ( V_1 , V_59 , V_63 ) ;
break;
default:
F_7 ( V_1 , V_59 , V_64 ) ;
break;
}
}
else
{
V_45 = V_46 = 0 ;
for ( V_19 = 0 ; V_19 < V_65 ; V_19 ++ )
{
if ( ( 1 << V_19 ) & V_44 )
{
V_45 |= V_66 [ V_19 ] ;
V_46 |= V_67 [ V_19 ] ;
}
F_7 ( V_1 , V_68 , V_45 ) ;
F_7 ( V_1 , V_69 , V_46 ) ;
}
}
break;
}
V_1 -> V_52 = V_44 ;
return V_1 -> V_52 ;
}
static int F_18 ( T_1 * V_1 , int V_10 )
{
int V_44 , V_19 ;
unsigned char V_70 ;
V_44 = V_10 & V_1 -> V_71 ;
switch ( V_1 -> V_39 )
{
case V_56 :
if ( V_1 -> V_57 == V_58 )
break;
else
{
V_70 = 0 ;
for ( V_19 = 0 ; V_19 < V_65 ; V_19 ++ )
{
if ( ( 1 << V_19 ) & V_44 )
{
V_70 |= ( V_66 [ V_19 ] | V_67 [ V_19 ] ) ;
}
F_7 ( V_1 , V_72 , V_70 ) ;
}
}
break;
default:
break;
}
V_1 -> V_73 = V_44 ;
return V_1 -> V_73 ;
}
static int F_19 ( int V_7 , unsigned int V_74 , void T_2 * V_75 )
{
T_1 * V_1 = V_76 [ V_7 ] -> V_1 ;
int V_29 , V_77 ;
int T_2 * V_78 = V_75 ;
if ( V_1 -> V_39 == V_56 ) {
if ( V_74 == V_79 )
{
if ( F_20 ( V_29 , V_78 ) )
return - V_80 ;
F_7 ( V_1 , 0x43 , ( ~ V_29 ) & 0x01 ) ;
return 0 ;
}
if ( V_74 == V_81 )
{
if ( V_1 -> V_82 < 15 )
return - V_17 ;
if ( F_20 ( V_29 , V_78 ) )
return - V_80 ;
if ( V_29 == 0 || V_29 == 1 )
F_2 ( V_1 , V_83 , 0x01 , V_29 ) ;
else if ( V_29 == 2 )
{
V_77 = F_10 ( V_1 , V_83 ) & 0x01 ;
return F_21 ( V_77 , V_78 ) ;
}
else
return - V_17 ;
return 0 ;
}
}
if ( ( ( V_74 >> 8 ) & 0xff ) == 'M' )
{
if ( F_22 ( V_74 ) & V_84 )
{
if ( F_20 ( V_29 , V_78 ) )
return - V_80 ;
switch ( V_74 & 0xff )
{
case V_85 :
V_77 = F_16 ( V_1 , V_29 ) ;
break;
case V_86 :
V_77 = F_18 ( V_1 , V_29 ) ;
break;
default:
V_77 = F_13 ( V_1 , V_74 & 0xff , V_29 ) ;
}
}
else switch ( V_74 & 0xff )
{
case V_85 :
V_77 = V_1 -> V_52 ;
break;
case V_86 :
V_77 = V_1 -> V_73 ;
break;
case V_87 :
V_77 = V_1 -> V_16 ;
break;
case V_88 :
V_77 = V_1 -> V_16 ;
if ( V_1 -> V_39 == V_41 )
V_77 &= ~ ( V_89 | V_90 ) ;
else if ( V_1 -> V_39 != V_48 && V_1 -> V_39 != V_40 )
V_77 &= ~ ( V_49 | V_89 | V_90 ) ;
break;
case V_91 :
V_77 = V_1 -> V_21 ;
break;
case V_92 :
V_77 = V_1 -> V_71 ;
break;
case V_93 :
V_77 = V_1 -> V_94 ;
break;
default:
V_77 = F_5 ( V_1 , V_74 & 0xff ) ;
break;
}
return F_21 ( V_77 , V_78 ) ;
} else
return - V_17 ;
}
static void F_8 ( T_1 * V_1 )
{
char V_95 [ 32 ] ;
int V_19 ;
sprintf ( V_95 , L_1 , V_1 -> V_96 ) ;
if ( V_1 -> V_97 . V_98 )
V_1 -> V_18 = F_23 ( V_95 , V_99 , 1 ) ;
else
V_1 -> V_18 = F_23 ( V_95 , V_100 , 1 ) ;
for ( V_19 = 0 ; V_19 < V_65 ; V_19 ++ )
F_13 ( V_1 , V_19 , V_1 -> V_18 [ V_19 ] ) ;
if ( V_1 -> V_39 != V_41 || ! F_24 ( V_1 ) ) {
F_16 ( V_1 , V_49 ) ;
}
}
int F_25 ( T_1 * V_1 , struct V_101 * V_102 )
{
int V_103 = 0 ;
int V_104 ;
V_1 -> V_96 = V_96 ++ ;
V_1 -> V_18 = NULL ;
F_7 ( V_1 , 0x00 , 0 ) ;
if ( ! ( V_103 = F_3 ( V_1 ) ) )
return 0 ;
switch ( V_1 -> V_39 )
{
case V_105 :
case V_106 :
case V_47 :
case V_107 :
case V_48 :
V_1 -> V_94 = V_108 ;
V_1 -> V_16 = V_109 ;
V_1 -> V_21 = V_110 ;
V_1 -> V_12 = & V_111 ;
V_1 -> V_30 = F_12 ( V_111 ) ;
break;
case V_41 :
F_26 ( V_1 ) ;
break;
case V_40 :
V_1 -> V_94 = V_108 ;
V_1 -> V_16 = 0 ;
V_1 -> V_21 = 0 ;
V_1 -> V_12 = & V_111 ;
V_1 -> V_30 = F_12 ( V_111 ) ;
F_6 ( V_1 ) ;
break;
case V_56 :
V_1 -> V_94 = 0 ;
V_1 -> V_21 = V_112 ;
V_1 -> V_71 = V_113 ;
if ( V_1 -> V_57 != V_58 )
{
V_1 -> V_16 = V_114 ;
V_1 -> V_12 = & V_115 ;
V_1 -> V_30 = F_12 ( V_115 ) ;
}
else
{
V_1 -> V_16 = V_116 ;
V_1 -> V_12 = & V_117 ;
V_1 -> V_30 = F_12 ( V_117 ) ;
}
break;
default:
F_27 ( V_118 L_2 , V_1 -> V_39 ) ;
return 0 ;
}
V_104 = F_28 () ;
if ( V_104 == - 1 )
return 0 ;
V_76 [ V_104 ] = F_29 ( sizeof( struct V_119 ) , V_120 ) ;
if ( V_76 [ V_104 ] == NULL )
{
F_27 ( V_121 L_3 ) ;
F_30 ( V_104 ) ;
return 0 ;
}
if ( V_1 -> V_57 != V_58 )
memcpy ( ( char * ) V_76 [ V_104 ] , ( char * ) & V_122 , sizeof ( struct V_119 ) ) ;
else
memcpy ( ( char * ) V_76 [ V_104 ] , ( char * ) & V_123 , sizeof ( struct V_119 ) ) ;
V_76 [ V_104 ] -> V_1 = V_1 ;
if ( V_102 )
V_76 [ V_104 ] -> V_102 = V_102 ;
V_1 -> V_124 = V_104 ;
F_8 ( V_1 ) ;
return 1 ;
}
void F_31 ( T_1 * V_1 )
{
if ( V_1 -> V_124 == - 1 )
return;
F_32 ( V_76 [ V_1 -> V_124 ] ) ;
F_30 ( V_1 -> V_124 ) ;
V_96 -- ;
}
