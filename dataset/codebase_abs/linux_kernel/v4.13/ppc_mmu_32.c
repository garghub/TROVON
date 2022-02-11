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
unsigned int V_19 , T_3 V_20 )
{
unsigned int V_10 ;
int V_21 ;
struct V_22 * V_23 = V_24 [ V_17 ] ;
unsigned long V_25 = F_6 ( V_20 ) ;
if ( ( V_25 & V_26 ) ||
( F_7 ( V_27 ) == 0 ) )
V_25 &= ~ V_28 ;
V_10 = ( V_19 >> 17 ) - 1 ;
if ( F_8 ( F_9 ( V_29 ) ) != 1 ) {
V_21 = V_25 & ( V_30 | V_26
| V_28 | V_31 ) ;
V_21 |= ( V_25 & V_32 ) ? V_33 : V_34 ;
V_23 [ 1 ] . V_35 = V_18 | ( V_10 << 2 ) | 2 ;
V_23 [ 1 ] . V_36 = F_10 ( V_6 ) | V_21 ;
if ( V_25 & V_37 )
V_23 [ 1 ] . V_35 |= 1 ;
if ( V_25 & V_31 ) {
V_23 [ 0 ] . V_35 = V_23 [ 0 ] . V_36 = 0 ;
} else {
V_23 [ 0 ] = V_23 [ 1 ] ;
}
} else {
if ( V_10 > V_38 )
V_10 = V_38 ;
V_21 = V_25 & ( V_30 | V_26
| V_28 ) ;
V_21 |= ( V_25 & V_32 ) ?
( ( V_25 & V_37 ) ? V_39 : V_40 ) : V_41 ;
V_23 -> V_35 = V_18 | V_21 | 4 ;
V_23 -> V_36 = V_6 | V_10 | 0x40 ;
}
V_3 [ V_17 ] . V_4 = V_18 ;
V_3 [ V_17 ] . V_5 = V_18 + ( ( V_10 + 1 ) << 17 ) - 1 ;
V_3 [ V_17 ] . V_6 = V_6 ;
}
void F_11 ( struct V_42 * V_43 , unsigned long V_44 ,
unsigned long V_45 , unsigned long V_46 )
{
T_4 * V_47 ;
if ( V_48 == 0 )
return;
V_47 = F_12 ( F_13 ( F_14 ( V_43 , V_44 ) , V_44 ) , V_44 ) ;
if ( ! F_15 ( * V_47 ) )
F_16 ( V_43 -> V_49 . V_50 , V_44 , F_17 ( * V_47 ) ) ;
}
void T_2 F_18 ( void )
{
unsigned int V_51 , V_52 , V_53 ;
unsigned int V_54 , V_55 ;
extern unsigned int V_56 [] ;
extern unsigned int V_57 [] , V_58 [] ;
extern unsigned int V_59 [] ;
extern unsigned int V_60 [] , V_61 [] ;
if ( ! F_19 ( V_62 ) ) {
V_59 [ 0 ] = 0x4e800020 ;
F_20 ( ( unsigned long ) & V_59 [ 0 ] ,
( unsigned long ) & V_59 [ 1 ] ) ;
return;
}
if ( V_63 . V_64 ) V_63 . V_64 ( L_2 , 0x105 ) ;
#define F_21 6
#define F_22 ((n_hpteg - 1) >> 10)
#define F_23 1024
V_54 = V_65 / ( V_66 * 8 ) ;
if ( V_54 < F_23 )
V_54 = F_23 ;
V_55 = F_24 ( V_54 ) ;
if ( V_54 & ( V_54 - 1 ) ) {
++ V_55 ;
V_54 = 1 << V_55 ;
}
V_67 = V_54 << F_21 ;
if ( V_63 . V_64 ) V_63 . V_64 ( L_3 , 0x322 ) ;
V_48 = F_25 ( F_26 ( V_67 , V_67 ) ) ;
memset ( V_48 , 0 , V_67 ) ;
V_68 = F_27 ( V_48 ) | F_22 ;
V_69 = (struct V_70 * ) ( ( unsigned long ) V_48 + V_67 ) ;
F_4 ( L_4 ,
( unsigned long long ) ( V_65 >> 20 ) , V_67 >> 10 , V_48 ) ;
if ( V_63 . V_64 ) V_63 . V_64 ( L_5 , 0x345 ) ;
V_71 = V_54 - 1 ;
V_51 = V_71 >> ( 16 - F_21 ) ;
V_53 = V_52 = 32 - F_21 - V_55 ;
if ( V_55 > 16 )
V_53 = 16 - F_21 ;
V_56 [ 0 ] = ( V_56 [ 0 ] & ~ 0xffff )
| ( ( unsigned int ) ( V_48 ) >> 16 ) ;
V_56 [ 1 ] = ( V_56 [ 1 ] & ~ 0x7c0 ) | ( V_52 << 6 ) ;
V_56 [ 2 ] = ( V_56 [ 2 ] & ~ 0x7c0 ) | ( V_53 << 6 ) ;
V_57 [ 0 ] = ( V_57 [ 0 ] & ~ 0xffff ) | V_51 ;
V_58 [ 0 ] = ( V_58 [ 0 ] & ~ 0xffff ) | V_51 ;
F_20 ( ( unsigned long ) & V_56 [ 0 ] ,
( unsigned long ) & V_58 [ 1 ] ) ;
V_60 [ 0 ] = ( V_60 [ 0 ] & ~ 0xffff )
| ( ( unsigned int ) ( V_48 ) >> 16 ) ;
V_60 [ 1 ] = ( V_60 [ 1 ] & ~ 0x7c0 ) | ( V_52 << 6 ) ;
V_60 [ 2 ] = ( V_60 [ 2 ] & ~ 0x7c0 ) | ( V_53 << 6 ) ;
V_61 [ 0 ] = ( V_61 [ 0 ] & ~ 0xffff ) | V_51 ;
F_20 ( ( unsigned long ) & V_60 [ 0 ] ,
( unsigned long ) & V_61 [ 1 ] ) ;
if ( V_63 . V_64 ) V_63 . V_64 ( L_6 , 0x205 ) ;
}
void F_28 ( T_1 V_72 ,
T_1 V_73 )
{
F_29 ( V_72 != 0 ) ;
if ( F_8 ( F_9 ( V_29 ) ) == 1 )
F_30 ( F_31 ( V_74 , V_73 , 0x01000000 ) ) ;
else
F_30 ( F_31 ( V_74 , V_73 , 0x10000000 ) ) ;
}
