T_1 F_1 ( unsigned long V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < 4 ; ++ V_2 )
if ( V_1 >= V_3 [ V_2 ] . V_4 && V_1 < V_3 [ V_2 ] . V_5 )
return V_3 [ V_2 ] . V_6 + ( V_1 - V_3 [ V_2 ] . V_4 ) ;
return 0 ;
}
unsigned long F_2 ( T_1 V_7 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < 4 ; ++ V_2 )
if ( V_7 >= V_3 [ V_2 ] . V_6
&& V_7 < ( V_3 [ V_2 ] . V_5 - V_3 [ V_2 ] . V_4 )
+ V_3 [ V_2 ] . V_6 )
return V_3 [ V_2 ] . V_4 + ( V_7 - V_3 [ V_2 ] . V_6 ) ;
return 0 ;
}
unsigned long T_2 F_3 ( unsigned long V_8 )
{
unsigned long V_9 , V_10 , V_11 ;
unsigned long V_12 = ( 256 << 20 ) ;
if ( V_13 ) {
F_4 ( V_14 L_1 ) ;
return 0 ;
}
V_9 = V_8 ;
for ( V_10 = 128 << 10 ; V_10 < V_12 ; V_10 <<= 1 ) {
if ( V_10 * 2 > V_9 )
break;
}
F_5 ( 2 , V_15 , 0 , V_10 , V_16 ) ;
V_11 = ( unsigned long ) V_3 [ 2 ] . V_5 - V_15 + 1 ;
if ( ( V_11 < V_9 ) && ! V_3 [ 3 ] . V_5 ) {
V_9 -= V_11 ;
for ( V_10 = 128 << 10 ; V_10 < V_12 ; V_10 <<= 1 )
if ( V_10 * 2 > V_9 )
break;
F_5 ( 3 , V_15 + V_11 , V_11 , V_10 , V_16 ) ;
V_11 = ( unsigned long ) V_3 [ 3 ] . V_5 - V_15 + 1 ;
}
return V_11 ;
}
void T_2 F_5 ( int V_17 , unsigned long V_18 , T_1 V_6 ,
unsigned int V_19 , int V_20 )
{
unsigned int V_10 ;
int V_21 ;
struct V_22 * V_23 = V_24 [ V_17 ] ;
if ( ( V_20 & V_25 ) ||
( F_6 ( V_26 ) == 0 ) )
V_20 &= ~ V_27 ;
V_10 = ( V_19 >> 17 ) - 1 ;
if ( F_7 ( F_8 ( V_28 ) ) != 1 ) {
V_21 = V_20 & ( V_29 | V_25
| V_27 | V_30 ) ;
V_21 |= ( V_20 & V_31 ) ? V_32 : V_33 ;
V_23 [ 1 ] . V_34 = V_18 | ( V_10 << 2 ) | 2 ;
V_23 [ 1 ] . V_35 = F_9 ( V_6 ) | V_21 ;
if ( V_20 & V_36 )
V_23 [ 1 ] . V_34 |= 1 ;
if ( V_20 & V_30 ) {
V_23 [ 0 ] . V_34 = V_23 [ 0 ] . V_35 = 0 ;
} else {
V_23 [ 0 ] = V_23 [ 1 ] ;
}
} else {
if ( V_10 > V_37 )
V_10 = V_37 ;
V_21 = V_20 & ( V_29 | V_25
| V_27 ) ;
V_21 |= ( V_20 & V_31 ) ?
( ( V_20 & V_36 ) ? V_38 : V_39 ) : V_40 ;
V_23 -> V_34 = V_18 | V_21 | 4 ;
V_23 -> V_35 = V_6 | V_10 | 0x40 ;
}
V_3 [ V_17 ] . V_4 = V_18 ;
V_3 [ V_17 ] . V_5 = V_18 + ( ( V_10 + 1 ) << 17 ) - 1 ;
V_3 [ V_17 ] . V_6 = V_6 ;
}
void F_10 ( struct V_41 * V_42 , unsigned long V_43 ,
unsigned long V_44 , unsigned long V_45 )
{
T_3 * V_46 ;
if ( V_47 == 0 )
return;
V_46 = F_11 ( F_12 ( F_13 ( V_42 , V_43 ) , V_43 ) , V_43 ) ;
if ( ! F_14 ( * V_46 ) )
F_15 ( V_42 -> V_48 . V_49 , V_43 , F_16 ( * V_46 ) ) ;
}
void T_2 F_17 ( void )
{
unsigned int V_50 , V_51 , V_52 ;
unsigned int V_53 , V_54 ;
extern unsigned int V_55 [] ;
extern unsigned int V_56 [] , V_57 [] ;
extern unsigned int V_58 [] ;
extern unsigned int V_59 [] , V_60 [] ;
if ( ! F_18 ( V_61 ) ) {
V_58 [ 0 ] = 0x4e800020 ;
F_19 ( ( unsigned long ) & V_58 [ 0 ] ,
( unsigned long ) & V_58 [ 1 ] ) ;
return;
}
if ( V_62 . V_63 ) V_62 . V_63 ( L_2 , 0x105 ) ;
#define F_20 6
#define F_21 ((n_hpteg - 1) >> 10)
#define F_22 1024
V_53 = V_64 / ( V_65 * 8 ) ;
if ( V_53 < F_22 )
V_53 = F_22 ;
V_54 = F_23 ( V_53 ) ;
if ( V_53 & ( V_53 - 1 ) ) {
++ V_54 ;
V_53 = 1 << V_54 ;
}
V_66 = V_53 << F_20 ;
if ( V_62 . V_63 ) V_62 . V_63 ( L_3 , 0x322 ) ;
V_47 = F_24 ( F_25 ( V_66 , V_66 ) ) ;
F_26 ( V_47 , V_66 ) ;
V_67 = F_27 ( V_47 ) | F_21 ;
V_68 = (struct V_69 * ) ( ( unsigned long ) V_47 + V_66 ) ;
F_4 ( L_4 ,
( unsigned long long ) ( V_64 >> 20 ) , V_66 >> 10 , V_47 ) ;
if ( V_62 . V_63 ) V_62 . V_63 ( L_5 , 0x345 ) ;
V_70 = V_53 - 1 ;
V_50 = V_70 >> ( 16 - F_20 ) ;
V_52 = V_51 = 32 - F_20 - V_54 ;
if ( V_54 > 16 )
V_52 = 16 - F_20 ;
V_55 [ 0 ] = ( V_55 [ 0 ] & ~ 0xffff )
| ( ( unsigned int ) ( V_47 ) >> 16 ) ;
V_55 [ 1 ] = ( V_55 [ 1 ] & ~ 0x7c0 ) | ( V_51 << 6 ) ;
V_55 [ 2 ] = ( V_55 [ 2 ] & ~ 0x7c0 ) | ( V_52 << 6 ) ;
V_56 [ 0 ] = ( V_56 [ 0 ] & ~ 0xffff ) | V_50 ;
V_57 [ 0 ] = ( V_57 [ 0 ] & ~ 0xffff ) | V_50 ;
F_19 ( ( unsigned long ) & V_55 [ 0 ] ,
( unsigned long ) & V_57 [ 1 ] ) ;
V_59 [ 0 ] = ( V_59 [ 0 ] & ~ 0xffff )
| ( ( unsigned int ) ( V_47 ) >> 16 ) ;
V_59 [ 1 ] = ( V_59 [ 1 ] & ~ 0x7c0 ) | ( V_51 << 6 ) ;
V_59 [ 2 ] = ( V_59 [ 2 ] & ~ 0x7c0 ) | ( V_52 << 6 ) ;
V_60 [ 0 ] = ( V_60 [ 0 ] & ~ 0xffff ) | V_50 ;
F_19 ( ( unsigned long ) & V_59 [ 0 ] ,
( unsigned long ) & V_60 [ 1 ] ) ;
if ( V_62 . V_63 ) V_62 . V_63 ( L_6 , 0x205 ) ;
}
void F_28 ( T_1 V_71 ,
T_1 V_72 )
{
F_29 ( V_71 != 0 ) ;
if ( F_7 ( F_8 ( V_28 ) ) == 1 )
F_30 ( F_31 ( V_73 , V_72 , 0x01000000 ) ) ;
else
F_30 ( F_31 ( V_73 , V_72 , 0x10000000 ) ) ;
}
