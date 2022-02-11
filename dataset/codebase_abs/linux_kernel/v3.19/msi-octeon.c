int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
T_1 V_7 ;
int V_8 ;
int V_9 ;
int V_10 = 0 ;
int V_11 ;
T_2 V_12 ;
int V_13 ;
F_2 ( V_2 , V_2 -> V_14 + V_15 , & V_7 ) ;
V_8 = ( V_7 & V_16 ) >> 4 ;
if ( V_8 == 0 ) {
V_9 = ( V_7 & V_17 ) >> 1 ;
} else {
V_9 = V_8 ;
}
if ( V_9 > 5 )
V_9 = 0 ;
V_18:
V_11 = 1 << V_9 ;
V_12 = ( 1 << V_11 ) - 1 ;
F_3 ( & V_19 ) ;
for ( V_13 = 0 ; V_13 < V_20 / 64 ; V_13 ++ ) {
for ( V_10 = 0 ; V_10 < 64 ; V_10 += V_11 ) {
if ( ( V_21 [ V_13 ] & ( V_12 << V_10 ) ) == 0 ) {
V_21 [ V_13 ] |= V_12 << V_10 ;
V_22 [ V_13 ] |= ( V_12 >> 1 ) << V_10 ;
goto V_23;
}
}
}
V_23:
F_4 ( & V_19 ) ;
if ( V_10 >= 64 ) {
if ( V_9 ) {
F_5 ( L_1 ,
1 << V_9 ) ;
V_9 = 0 ;
goto V_18;
} else
F_6 ( L_2 ) ;
}
V_10 += V_13 * 64 ;
V_10 += V_24 ;
switch ( V_25 ) {
case V_26 :
V_6 . V_27 =
( ( 128ul << 20 ) + V_28 ) & 0xffffffff ;
V_6 . V_29 = ( ( 128ul << 20 ) + V_28 ) >> 32 ;
break;
case V_30 :
V_6 . V_27 = ( 0 + V_28 ) & 0xffffffff ;
V_6 . V_29 = ( 0 + V_28 ) >> 32 ;
break;
case V_31 :
V_6 . V_27 = ( 0 + V_32 ) & 0xffffffff ;
V_6 . V_29 = ( 0 + V_32 ) >> 32 ;
break;
case V_33 :
V_6 . V_27 = ( 0 + V_34 ) & 0xffffffff ;
V_6 . V_29 = ( 0 + V_34 ) >> 32 ;
break;
default:
F_6 ( L_3 ) ;
}
V_6 . V_35 = V_10 - V_24 ;
V_7 &= ~ V_16 ;
V_7 |= V_9 << 4 ;
F_7 ( V_2 , V_2 -> V_14 + V_15 , V_7 ) ;
F_8 ( V_10 , V_4 ) ;
F_9 ( V_10 , & V_6 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , int V_36 , int type )
{
struct V_3 * V_37 ;
int V_38 ;
if ( type == V_39 )
return - V_40 ;
if ( type == V_41 && V_36 > 1 )
return 1 ;
F_11 (entry, &dev->msi_list, list) {
V_38 = F_1 ( V_2 , V_37 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 > 0 )
return - V_42 ;
}
return 0 ;
}
void F_12 ( unsigned int V_10 )
{
int V_43 ;
T_2 V_44 ;
int V_13 = 0 ;
int V_45 ;
if ( ( V_10 < V_24 )
|| ( V_10 > V_20 + V_24 ) )
F_6 ( L_4
L_5 , V_10 ) ;
V_10 -= V_24 ;
V_13 = V_10 / 64 ;
V_45 = V_10 % 64 ;
V_43 = 0 ;
while ( ( V_45 + V_43 < 64 ) &&
( V_22 [ V_13 ]
& ( 1ull << ( V_45 + V_43 ) ) ) )
V_43 ++ ;
V_43 ++ ;
V_44 = ( 1 << V_43 ) - 1 ;
V_44 <<= V_45 ;
if ( ( V_21 [ V_13 ] & V_44 ) != V_44 )
F_6 ( L_6
L_7 , V_10 ) ;
F_3 ( & V_19 ) ;
V_21 [ V_13 ] &= ~ V_44 ;
V_22 [ V_13 ] &= ~ V_44 ;
F_4 ( & V_19 ) ;
}
static void F_13 ( struct V_46 * V_35 )
{
T_2 V_47 ;
unsigned long V_48 ;
int V_49 = V_35 -> V_10 - V_24 ;
int V_50 = V_49 >> 6 ;
int V_51 = V_49 & 0x3f ;
F_14 ( & V_52 , V_48 ) ;
V_47 = F_15 ( V_53 [ V_50 ] ) ;
V_47 |= 1ull << V_51 ;
F_16 ( V_53 [ V_50 ] , V_47 ) ;
F_15 ( V_53 [ V_50 ] ) ;
F_17 ( & V_52 , V_48 ) ;
}
static void F_18 ( struct V_46 * V_35 )
{
T_2 V_47 ;
unsigned long V_48 ;
int V_49 = V_35 -> V_10 - V_24 ;
int V_50 = V_49 >> 6 ;
int V_51 = V_49 & 0x3f ;
F_14 ( & V_52 , V_48 ) ;
V_47 = F_15 ( V_53 [ V_50 ] ) ;
V_47 &= ~ ( 1ull << V_51 ) ;
F_16 ( V_53 [ V_50 ] , V_47 ) ;
F_15 ( V_53 [ V_50 ] ) ;
F_17 ( & V_52 , V_48 ) ;
}
static void F_19 ( struct V_46 * V_35 )
{
}
static void F_20 ( struct V_46 * V_35 )
{
}
static T_3 F_21 ( int V_13 , T_2 V_54 )
{
int V_10 ;
int V_55 ;
V_55 = F_22 ( V_54 ) ;
if ( V_55 ) {
V_55 -- ;
F_16 ( V_56 [ V_13 ] , 1ull << V_55 ) ;
V_10 = V_55 + V_24 + 64 * V_13 ;
F_23 ( V_10 ) ;
return V_57 ;
}
return V_58 ;
}
int T_4 F_24 ( void )
{
int V_10 ;
struct V_59 * V_60 ;
if ( V_25 == V_31 ) {
V_56 [ 0 ] = V_61 ;
V_56 [ 1 ] = V_62 ;
V_56 [ 2 ] = V_63 ;
V_56 [ 3 ] = V_64 ;
V_53 [ 0 ] = V_65 ;
V_53 [ 1 ] = V_66 ;
V_53 [ 2 ] = V_67 ;
V_53 [ 3 ] = V_68 ;
V_60 = & V_69 ;
} else {
V_56 [ 0 ] = V_70 ;
#define F_25 0x8700000000000000ULL;
V_56 [ 1 ] = F_25 ;
V_56 [ 2 ] = F_25 ;
V_56 [ 3 ] = F_25 ;
V_53 [ 0 ] = F_25 ;
V_53 [ 1 ] = F_25 ;
V_53 [ 2 ] = F_25 ;
V_53 [ 3 ] = F_25 ;
V_60 = & V_71 ;
}
for ( V_10 = V_24 ; V_10 <= V_72 ; V_10 ++ )
F_26 ( V_10 , V_60 , V_73 ) ;
if ( F_27 ( V_74 ) ) {
if ( F_28 ( V_75 , V_76 ,
0 , L_8 , V_76 ) )
F_6 ( L_9 ) ;
if ( F_28 ( V_77 , V_78 ,
0 , L_10 , V_78 ) )
F_6 ( L_11 ) ;
if ( F_28 ( V_79 , V_80 ,
0 , L_12 , V_80 ) )
F_6 ( L_13 ) ;
if ( F_28 ( V_81 , V_82 ,
0 , L_14 , V_82 ) )
F_6 ( L_15 ) ;
V_20 = 256 ;
} else if ( F_29 () ) {
if ( F_28 ( V_75 , V_76 ,
0 , L_16 , V_76 ) )
F_6 ( L_9 ) ;
if ( F_28 ( V_77 , V_76 ,
0 , L_17 , V_76 ) )
F_6 ( L_11 ) ;
if ( F_28 ( V_79 , V_76 ,
0 , L_18 , V_76 ) )
F_6 ( L_13 ) ;
if ( F_28 ( V_81 , V_76 ,
0 , L_19 , V_76 ) )
F_6 ( L_15 ) ;
V_20 = 64 ;
}
return 0 ;
}
