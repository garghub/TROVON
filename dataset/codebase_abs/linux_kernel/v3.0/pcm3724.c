static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( int V_2 , int V_3 , int V_4 , unsigned long V_5 )
{
unsigned long V_6 = V_5 ;
unsigned char V_7 ;
if ( V_2 ) {
F_6 ( V_4 , V_6 + V_3 ) ;
return 0 ;
} else {
V_7 = F_7 ( V_6 + V_3 ) ;
return V_7 ;
}
}
static int F_8 ( int V_8 , int V_9 , struct V_10 * V_11 )
{
if ( V_11 -> V_12 & 0x0000ff ) {
if ( V_9 == 0 )
V_8 |= V_13 ;
else
V_8 |= V_14 ;
}
if ( V_11 -> V_12 & 0x00ff00 ) {
if ( V_9 == 0 )
V_8 |= V_15 ;
else
V_8 |= V_16 ;
}
if ( V_11 -> V_12 & 0xff0000 ) {
if ( V_9 == 0 )
V_8 |= V_17 ;
else
V_8 |= V_18 ;
}
return V_8 ;
}
static void F_9 ( struct V_19 * V_20 ,
struct V_10 * V_11 , int V_21 )
{
int V_8 ;
int V_22 ;
unsigned long V_23 ;
V_8 = V_24 ;
V_22 = 0 ;
if ( ! ( V_11 -> V_12 & 0x0000ff ) )
V_8 |= V_25 ;
if ( ! ( V_11 -> V_12 & 0x00ff00 ) )
V_8 |= V_26 ;
if ( ! ( V_11 -> V_12 & 0xff0000 ) )
V_8 |= V_27 ;
V_22 = F_8 ( 0 , 0 , V_20 -> V_28 ) ;
V_22 = F_8 ( V_22 , 1 , ( V_20 -> V_28 ) + 1 ) ;
if ( V_11 == V_20 -> V_28 )
V_23 = V_20 -> V_6 + V_29 ;
else
V_23 = V_20 -> V_6 + V_30 + V_29 ;
F_6 ( V_22 , V_20 -> V_6 + 8 ) ;
F_6 ( V_8 , V_23 ) ;
}
static void F_10 ( struct V_19 * V_20 , struct V_10 * V_11 ,
int V_21 )
{
unsigned int V_31 ;
int V_32 ;
struct V_33 * V_34 ;
V_32 = 0 ;
V_34 = V_20 -> V_35 ;
V_31 = 1 << F_11 ( V_21 ) ;
if ( V_11 == V_20 -> V_28 )
V_34 -> V_36 |= V_31 ;
else
V_34 -> V_37 |= V_31 ;
if ( V_34 -> V_36 & 0xff0000 )
V_32 |= V_38 ;
if ( V_34 -> V_36 & 0xff00 )
V_32 |= V_39 ;
if ( V_34 -> V_36 & 0xff )
V_32 |= V_40 ;
if ( V_34 -> V_37 & 0xff0000 )
V_32 |= V_41 ;
if ( V_34 -> V_37 & 0xff00 )
V_32 |= V_42 ;
if ( V_34 -> V_37 & 0xff )
V_32 |= V_43 ;
F_6 ( V_32 , V_20 -> V_6 + 9 ) ;
}
static int F_12 ( struct V_19 * V_20 ,
struct V_10 * V_11 ,
struct V_44 * V_45 , unsigned int * V_4 )
{
unsigned int V_31 ;
unsigned int V_46 ;
V_31 = 1 << F_11 ( V_45 -> V_21 ) ;
if ( V_31 & 0x0000ff )
V_46 = 0x0000ff ;
else if ( V_31 & 0x00ff00 )
V_46 = 0x00ff00 ;
else if ( V_31 & 0x0f0000 )
V_46 = 0x0f0000 ;
else
V_46 = 0xf00000 ;
switch ( V_4 [ 0 ] ) {
case V_47 :
V_11 -> V_12 &= ~ V_46 ;
break;
case V_48 :
V_11 -> V_12 |= V_46 ;
break;
case V_49 :
V_4 [ 1 ] = ( V_11 -> V_12 & V_46 ) ? V_50 : V_51 ;
return V_45 -> V_52 ;
break;
default:
return - V_53 ;
}
F_9 ( V_20 , V_11 , V_45 -> V_21 ) ;
F_10 ( V_20 , V_11 , V_45 -> V_21 ) ;
return 1 ;
}
static int F_13 ( struct V_19 * V_20 ,
struct V_54 * V_55 )
{
unsigned long V_6 ;
unsigned int V_56 ;
int V_57 , V_58 , V_59 ;
V_6 = V_55 -> V_60 [ 0 ] ;
V_56 = V_61 -> V_62 ;
V_57 = F_14 ( V_20 , sizeof( struct V_33 ) ) ;
if ( V_57 < 0 )
return - V_63 ;
( (struct V_33 * ) ( V_20 -> V_35 ) ) -> V_36 = 0 ;
( (struct V_33 * ) ( V_20 -> V_35 ) ) -> V_37 = 0 ;
F_15 ( V_64 L_1 , V_20 -> V_65 ,
V_61 -> V_66 , V_6 ) ;
if ( ! V_6 || ! F_16 ( V_6 , V_56 , L_2 ) ) {
F_15 ( L_3 ) ;
return - V_67 ;
}
V_20 -> V_6 = V_6 ;
V_20 -> V_68 = V_61 -> V_66 ;
F_15 ( V_64 L_4 ) ;
V_59 = V_61 -> V_69 ;
V_57 = F_17 ( V_20 , V_59 ) ;
if ( V_57 < 0 )
return V_57 ;
for ( V_58 = 0 ; V_58 < V_20 -> V_59 ; V_58 ++ ) {
F_18 ( V_20 , V_20 -> V_28 + V_58 , F_5 ,
( unsigned long ) ( V_20 -> V_6 + V_30 * V_58 ) ) ;
( ( V_20 -> V_28 ) + V_58 ) -> V_70 = F_12 ;
}
return 0 ;
}
static int F_19 ( struct V_19 * V_20 )
{
int V_58 ;
if ( V_20 -> V_28 ) {
for ( V_58 = 0 ; V_58 < V_20 -> V_59 ; V_58 ++ )
F_20 ( V_20 , V_20 -> V_28 + V_58 ) ;
}
if ( V_20 -> V_6 )
F_21 ( V_20 -> V_6 , V_61 -> V_62 ) ;
return 0 ;
}
