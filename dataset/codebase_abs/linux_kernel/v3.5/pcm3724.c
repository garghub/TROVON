static int F_1 ( int V_1 , int V_2 , int V_3 , unsigned long V_4 )
{
unsigned long V_5 = V_4 ;
unsigned char V_6 ;
if ( V_1 ) {
F_2 ( V_3 , V_5 + V_2 ) ;
return 0 ;
} else {
V_6 = F_3 ( V_5 + V_2 ) ;
return V_6 ;
}
}
static int F_4 ( int V_7 , int V_8 , struct V_9 * V_10 )
{
if ( V_10 -> V_11 & 0x0000ff ) {
if ( V_8 == 0 )
V_7 |= V_12 ;
else
V_7 |= V_13 ;
}
if ( V_10 -> V_11 & 0x00ff00 ) {
if ( V_8 == 0 )
V_7 |= V_14 ;
else
V_7 |= V_15 ;
}
if ( V_10 -> V_11 & 0xff0000 ) {
if ( V_8 == 0 )
V_7 |= V_16 ;
else
V_7 |= V_17 ;
}
return V_7 ;
}
static void F_5 ( struct V_18 * V_19 ,
struct V_9 * V_10 , int V_20 )
{
int V_7 ;
int V_21 ;
unsigned long V_22 ;
V_7 = V_23 ;
V_21 = 0 ;
if ( ! ( V_10 -> V_11 & 0x0000ff ) )
V_7 |= V_24 ;
if ( ! ( V_10 -> V_11 & 0x00ff00 ) )
V_7 |= V_25 ;
if ( ! ( V_10 -> V_11 & 0xff0000 ) )
V_7 |= V_26 ;
V_21 = F_4 ( 0 , 0 , V_19 -> V_27 ) ;
V_21 = F_4 ( V_21 , 1 , ( V_19 -> V_27 ) + 1 ) ;
if ( V_10 == V_19 -> V_27 )
V_22 = V_19 -> V_5 + V_28 ;
else
V_22 = V_19 -> V_5 + V_29 + V_28 ;
F_2 ( V_21 , V_19 -> V_5 + 8 ) ;
F_2 ( V_7 , V_22 ) ;
}
static void F_6 ( struct V_18 * V_19 , struct V_9 * V_10 ,
int V_20 )
{
unsigned int V_30 ;
int V_31 ;
struct V_32 * V_33 ;
V_31 = 0 ;
V_33 = V_19 -> V_34 ;
V_30 = 1 << F_7 ( V_20 ) ;
if ( V_10 == V_19 -> V_27 )
V_33 -> V_35 |= V_30 ;
else
V_33 -> V_36 |= V_30 ;
if ( V_33 -> V_35 & 0xff0000 )
V_31 |= V_37 ;
if ( V_33 -> V_35 & 0xff00 )
V_31 |= V_38 ;
if ( V_33 -> V_35 & 0xff )
V_31 |= V_39 ;
if ( V_33 -> V_36 & 0xff0000 )
V_31 |= V_40 ;
if ( V_33 -> V_36 & 0xff00 )
V_31 |= V_41 ;
if ( V_33 -> V_36 & 0xff )
V_31 |= V_42 ;
F_2 ( V_31 , V_19 -> V_5 + 9 ) ;
}
static int F_8 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
struct V_43 * V_44 , unsigned int * V_3 )
{
unsigned int V_30 ;
unsigned int V_45 ;
V_30 = 1 << F_7 ( V_44 -> V_20 ) ;
if ( V_30 & 0x0000ff )
V_45 = 0x0000ff ;
else if ( V_30 & 0x00ff00 )
V_45 = 0x00ff00 ;
else if ( V_30 & 0x0f0000 )
V_45 = 0x0f0000 ;
else
V_45 = 0xf00000 ;
switch ( V_3 [ 0 ] ) {
case V_46 :
V_10 -> V_11 &= ~ V_45 ;
break;
case V_47 :
V_10 -> V_11 |= V_45 ;
break;
case V_48 :
V_3 [ 1 ] = ( V_10 -> V_11 & V_45 ) ? V_49 : V_50 ;
return V_44 -> V_51 ;
break;
default:
return - V_52 ;
}
F_5 ( V_19 , V_10 , V_44 -> V_20 ) ;
F_6 ( V_19 , V_10 , V_44 -> V_20 ) ;
return 1 ;
}
static int F_9 ( struct V_18 * V_19 ,
struct V_53 * V_54 )
{
unsigned long V_5 ;
unsigned int V_55 ;
int V_56 , V_57 , V_58 ;
V_5 = V_54 -> V_59 [ 0 ] ;
V_55 = V_60 -> V_61 ;
V_56 = F_10 ( V_19 , sizeof( struct V_32 ) ) ;
if ( V_56 < 0 )
return - V_62 ;
( (struct V_32 * ) ( V_19 -> V_34 ) ) -> V_35 = 0 ;
( (struct V_32 * ) ( V_19 -> V_34 ) ) -> V_36 = 0 ;
F_11 ( V_63 L_1 , V_19 -> V_64 ,
V_60 -> V_65 , V_5 ) ;
if ( ! V_5 || ! F_12 ( V_5 , V_55 , L_2 ) ) {
F_11 ( L_3 ) ;
return - V_66 ;
}
V_19 -> V_5 = V_5 ;
V_19 -> V_67 = V_60 -> V_65 ;
F_11 ( V_63 L_4 ) ;
V_58 = V_60 -> V_68 ;
V_56 = F_13 ( V_19 , V_58 ) ;
if ( V_56 < 0 )
return V_56 ;
for ( V_57 = 0 ; V_57 < V_19 -> V_58 ; V_57 ++ ) {
F_14 ( V_19 , V_19 -> V_27 + V_57 , F_1 ,
( unsigned long ) ( V_19 -> V_5 + V_29 * V_57 ) ) ;
( ( V_19 -> V_27 ) + V_57 ) -> V_69 = F_8 ;
}
return 0 ;
}
static void F_15 ( struct V_18 * V_19 )
{
int V_57 ;
if ( V_19 -> V_27 ) {
for ( V_57 = 0 ; V_57 < V_19 -> V_58 ; V_57 ++ )
F_16 ( V_19 , V_19 -> V_27 + V_57 ) ;
}
if ( V_19 -> V_5 )
F_17 ( V_19 -> V_5 , V_60 -> V_61 ) ;
}
