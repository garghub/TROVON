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
F_2 ( V_2 , V_4 -> V_14 . V_15 + V_16 ,
& V_7 ) ;
V_8 = ( V_7 & V_17 ) >> 4 ;
if ( V_8 == 0 ) {
V_9 = ( V_7 & V_18 ) >> 1 ;
} else {
V_9 = V_8 ;
}
if ( V_9 > 5 )
V_9 = 0 ;
V_19:
V_11 = 1 << V_9 ;
V_12 = ( 1 << V_11 ) - 1 ;
F_3 ( & V_20 ) ;
for ( V_13 = 0 ; V_13 < V_21 / 64 ; V_13 ++ ) {
for ( V_10 = 0 ; V_10 < 64 ; V_10 += V_11 ) {
if ( ( V_22 [ V_13 ] & ( V_12 << V_10 ) ) == 0 ) {
V_22 [ V_13 ] |= V_12 << V_10 ;
V_23 [ V_13 ] |= ( V_12 >> 1 ) << V_10 ;
goto V_24;
}
}
}
V_24:
F_4 ( & V_20 ) ;
if ( V_10 >= 64 ) {
if ( V_9 ) {
F_5 ( L_1 ,
1 << V_9 ) ;
V_9 = 0 ;
goto V_19;
} else
F_6 ( L_2 ) ;
}
V_10 += V_13 * 64 ;
V_10 += V_25 ;
switch ( V_26 ) {
case V_27 :
V_6 . V_28 =
( ( 128ul << 20 ) + V_29 ) & 0xffffffff ;
V_6 . V_30 = ( ( 128ul << 20 ) + V_29 ) >> 32 ;
break;
case V_31 :
V_6 . V_28 = ( 0 + V_29 ) & 0xffffffff ;
V_6 . V_30 = ( 0 + V_29 ) >> 32 ;
break;
case V_32 :
V_6 . V_28 = ( 0 + V_33 ) & 0xffffffff ;
V_6 . V_30 = ( 0 + V_33 ) >> 32 ;
break;
default:
F_6 ( L_3 ) ;
}
V_6 . V_34 = V_10 - V_25 ;
V_7 &= ~ V_17 ;
V_7 |= V_9 << 4 ;
F_7 ( V_2 , V_4 -> V_14 . V_15 + V_16 ,
V_7 ) ;
F_8 ( V_10 , V_4 ) ;
F_9 ( V_10 , & V_6 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , int V_35 , int type )
{
struct V_3 * V_36 ;
int V_37 ;
if ( type == V_38 )
return - V_39 ;
if ( type == V_40 && V_35 > 1 )
return 1 ;
F_11 (entry, &dev->msi_list, list) {
V_37 = F_1 ( V_2 , V_36 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_37 > 0 )
return - V_41 ;
}
return 0 ;
}
void F_12 ( unsigned int V_10 )
{
int V_42 ;
T_2 V_43 ;
int V_13 = 0 ;
int V_44 ;
if ( ( V_10 < V_25 )
|| ( V_10 > V_21 + V_25 ) )
F_6 ( L_4
L_5 , V_10 ) ;
V_10 -= V_25 ;
V_13 = V_10 / 64 ;
V_44 = V_10 % 64 ;
V_42 = 0 ;
while ( ( V_44 + V_42 < 64 ) &&
( V_23 [ V_13 ]
& ( 1ull << ( V_44 + V_42 ) ) ) )
V_42 ++ ;
V_42 ++ ;
V_43 = ( 1 << V_42 ) - 1 ;
V_43 <<= V_44 ;
if ( ( V_22 [ V_13 ] & V_43 ) != V_43 )
F_6 ( L_6
L_7 , V_10 ) ;
F_3 ( & V_20 ) ;
V_22 [ V_13 ] &= ~ V_43 ;
V_23 [ V_13 ] &= ~ V_43 ;
F_4 ( & V_20 ) ;
}
static void F_13 ( struct V_45 * V_34 )
{
T_2 V_46 ;
unsigned long V_47 ;
int V_48 = V_34 -> V_10 - V_25 ;
int V_49 = V_48 >> 6 ;
int V_50 = V_48 & 0x3f ;
F_14 ( & V_51 , V_47 ) ;
V_46 = F_15 ( V_52 [ V_49 ] ) ;
V_46 |= 1ull << V_50 ;
F_16 ( V_52 [ V_49 ] , V_46 ) ;
F_15 ( V_52 [ V_49 ] ) ;
F_17 ( & V_51 , V_47 ) ;
}
static void F_18 ( struct V_45 * V_34 )
{
T_2 V_46 ;
unsigned long V_47 ;
int V_48 = V_34 -> V_10 - V_25 ;
int V_49 = V_48 >> 6 ;
int V_50 = V_48 & 0x3f ;
F_14 ( & V_51 , V_47 ) ;
V_46 = F_15 ( V_52 [ V_49 ] ) ;
V_46 &= ~ ( 1ull << V_50 ) ;
F_16 ( V_52 [ V_49 ] , V_46 ) ;
F_15 ( V_52 [ V_49 ] ) ;
F_17 ( & V_51 , V_47 ) ;
}
static void F_19 ( struct V_45 * V_34 )
{
}
static void F_20 ( struct V_45 * V_34 )
{
}
static T_3 F_21 ( int V_13 , T_2 V_53 )
{
int V_10 ;
int V_54 ;
V_54 = F_22 ( V_53 ) ;
if ( V_54 ) {
V_54 -- ;
F_16 ( V_55 [ V_13 ] , 1ull << V_54 ) ;
V_10 = V_54 + V_25 + 64 * V_13 ;
F_23 ( V_10 ) ;
return V_56 ;
}
return V_57 ;
}
int T_4 F_24 ( void )
{
int V_10 ;
struct V_58 * V_59 ;
if ( V_26 == V_32 ) {
V_55 [ 0 ] = V_60 ;
V_55 [ 1 ] = V_61 ;
V_55 [ 2 ] = V_62 ;
V_55 [ 3 ] = V_63 ;
V_52 [ 0 ] = V_64 ;
V_52 [ 1 ] = V_65 ;
V_52 [ 2 ] = V_66 ;
V_52 [ 3 ] = V_67 ;
V_59 = & V_68 ;
} else {
V_55 [ 0 ] = V_69 ;
#define F_25 0x8700000000000000ULL;
V_55 [ 1 ] = F_25 ;
V_55 [ 2 ] = F_25 ;
V_55 [ 3 ] = F_25 ;
V_52 [ 0 ] = F_25 ;
V_52 [ 1 ] = F_25 ;
V_52 [ 2 ] = F_25 ;
V_52 [ 3 ] = F_25 ;
V_59 = & V_70 ;
}
for ( V_10 = V_25 ; V_10 <= V_71 ; V_10 ++ )
F_26 ( V_10 , V_59 , V_72 ) ;
if ( F_27 ( V_73 ) ) {
if ( F_28 ( V_74 , V_75 ,
0 , L_8 , V_75 ) )
F_6 ( L_9 ) ;
if ( F_28 ( V_76 , V_77 ,
0 , L_10 , V_77 ) )
F_6 ( L_11 ) ;
if ( F_28 ( V_78 , V_79 ,
0 , L_12 , V_79 ) )
F_6 ( L_13 ) ;
if ( F_28 ( V_80 , V_81 ,
0 , L_14 , V_81 ) )
F_6 ( L_15 ) ;
V_21 = 256 ;
} else if ( F_29 () ) {
if ( F_28 ( V_74 , V_75 ,
0 , L_16 , V_75 ) )
F_6 ( L_9 ) ;
if ( F_28 ( V_76 , V_75 ,
0 , L_17 , V_75 ) )
F_6 ( L_11 ) ;
if ( F_28 ( V_78 , V_75 ,
0 , L_18 , V_75 ) )
F_6 ( L_13 ) ;
if ( F_28 ( V_80 , V_75 ,
0 , L_19 , V_75 ) )
F_6 ( L_15 ) ;
V_21 = 64 ;
}
return 0 ;
}
