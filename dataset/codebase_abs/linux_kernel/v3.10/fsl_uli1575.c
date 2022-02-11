static inline bool F_1 ( void )
{
return ( F_2 ( V_1 ) ||
F_2 ( V_2 ) ||
F_2 ( V_3 ) ||
F_2 ( V_4 ) ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
unsigned char V_7 ;
if ( ! F_1 () )
return;
F_4 ( V_6 , V_8 , V_9 |
V_10 | V_11 ) ;
F_5 ( V_6 , 0x7c , & V_7 ) ;
F_6 ( V_6 , 0x7c , 0x80 ) ;
F_6 ( V_6 , V_12 , 0x01 ) ;
V_6 -> V_13 |= 0x1 ;
F_6 ( V_6 , 0x7c , V_7 ) ;
}
static void F_7 ( struct V_5 * V_6 )
{
int V_14 ;
if ( ! F_1 () )
return;
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
T_1 V_15 = V_16 [ V_14 * 2 ] | ( V_16 [ V_14 * 2 + 1 ] << 4 ) ;
F_6 ( V_6 , 0x48 + V_14 , V_15 ) ;
}
F_6 ( V_6 , 0x86 , V_17 ) ;
F_6 ( V_6 , 0x87 , V_18 ) ;
F_6 ( V_6 , 0x88 , V_19 ) ;
F_6 ( V_6 , 0x89 , V_20 ) ;
F_6 ( V_6 , 0x8a , V_20 ) ;
F_6 ( V_6 , 0x8b , V_20 ) ;
F_6 ( V_6 , 0x8c , V_20 ) ;
F_6 ( V_6 , 0x8d , V_21 ) ;
F_6 ( V_6 , 0x8e , V_22 ) ;
F_6 ( V_6 , 0x8f , V_22 ) ;
F_6 ( V_6 , 0x74 , V_23 ) ;
F_6 ( V_6 , 0x44 , 0x30 | V_24 ) ;
F_6 ( V_6 , 0x75 , V_25 ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
if ( ! F_1 () )
return;
F_9 ( 0xfa , 0x4d0 ) ;
F_9 ( 0x1e , 0x4d1 ) ;
F_10 ( V_26 , V_27 ) ;
F_10 ( V_28 , V_27 ) ;
F_10 ( 0 , V_29 ) ;
F_11 ( 0x7c , 0x72 ) ;
F_11 ( V_30 , 0x73 ) ;
F_11 ( 0x7d , 0x72 ) ;
F_11 ( V_30 , 0x73 ) ;
}
static void F_12 ( struct V_5 * V_6 )
{
unsigned char V_31 ;
unsigned int V_32 ;
if ( ! F_1 () )
return;
F_5 ( V_6 , 0x83 , & V_31 ) ;
F_6 ( V_6 , 0x83 , V_31 | 0x80 ) ;
F_13 ( V_6 , V_33 , & V_32 ) ;
V_32 = ( V_32 & 0xff ) | ( V_34 << 8 ) ;
F_14 ( V_6 , V_33 , V_32 ) ;
F_6 ( V_6 , 0x83 , V_31 ) ;
F_5 ( V_6 , 0x84 , & V_31 ) ;
F_6 ( V_6 , 0x84 , V_31 & ~ 0x01 ) ;
}
static void F_15 ( struct V_5 * V_6 )
{
unsigned short V_7 ;
if ( ! F_1 () )
return;
F_4 ( V_6 , V_8 , V_35 |
V_11 | V_9 ) ;
F_16 ( V_6 , 0x4a , & V_7 ) ;
F_4 ( V_6 , 0x4a , V_7 | 0x1000 ) ;
}
static void F_17 ( struct V_5 * V_6 )
{
int V_14 ;
T_1 * V_36 ;
struct V_37 * V_38 = V_6 -> V_38 ;
struct V_39 * V_40 ;
T_2 V_41 = 0 ;
for ( V_14 = V_42 ; V_14 < V_42 + 3 ; V_14 ++ ) {
unsigned long V_43 = F_18 ( V_6 , V_14 ) ;
if ( ( V_43 & ( V_44 | V_45 ) ) == V_44 )
V_41 = F_19 ( V_6 , V_14 ) ;
}
F_20 (bus, res, i) {
if ( V_40 && V_40 -> V_43 & V_44 ) {
if ( V_40 -> V_41 == V_41 )
V_36 = F_21 ( V_40 -> V_46 , 0x4 ) ;
else
V_36 = F_21 ( V_40 -> V_41 - 3 , 0x4 ) ;
if ( V_36 ) {
F_22 ( V_36 ) ;
F_23 ( V_36 ) ;
}
break;
}
}
}
static void F_24 ( struct V_5 * V_6 )
{
T_3 V_47 ;
if ( ! F_2 ( V_48 ) )
return;
F_13 ( V_6 , 0x48 , & V_47 ) ;
F_14 ( V_6 , 0x48 , ( V_47 | 1 << 26 ) ) ;
F_13 ( V_6 , 0x90 , & V_47 ) ;
F_14 ( V_6 , 0x90 , ( V_47 | 1 << 22 ) ) ;
}
static void F_25 ( struct V_5 * V_6 )
{
unsigned char V_31 ;
if ( ! F_2 ( V_48 ) )
return;
F_5 ( V_6 , 0x83 , & V_31 ) ;
V_31 |= 0x80 ;
F_6 ( V_6 , 0x83 , V_31 ) ;
F_6 ( V_6 , V_12 , 0x01 ) ;
F_6 ( V_6 , V_49 , 0x06 ) ;
F_5 ( V_6 , 0x83 , & V_31 ) ;
V_31 &= 0x7f ;
F_6 ( V_6 , 0x83 , V_31 ) ;
}
static void F_26 ( struct V_5 * V_6 )
{
unsigned char V_31 ;
if ( ! F_2 ( V_48 ) )
return;
F_5 ( V_6 , 0x4b , & V_31 ) ;
V_31 |= 0x10 ;
F_6 ( V_6 , 0x4b , V_31 ) ;
}
static void F_27 ( struct V_5 * V_6 )
{
struct V_50 * V_51 = F_28 ( V_6 -> V_38 ) ;
struct V_52 * V_53 = V_51 ? V_51 -> V_54 : NULL ;
struct V_55 V_56 ;
int V_57 , V_58 = 2 ;
T_3 V_59 [ 3 ] ;
if ( ! F_2 ( V_48 ) )
return;
if ( ! V_53 )
return;
V_59 [ 0 ] = ( V_51 -> V_60 << 16 ) | ( F_29 ( 31 , 0 ) << 8 ) ;
V_59 [ 1 ] = V_59 [ 2 ] = 0 ;
F_30 ( V_53 , & V_58 , 1 , V_59 , & V_56 ) ;
V_57 = F_31 ( V_56 . V_61 , V_56 . V_62 ,
V_56 . V_63 ) ;
V_6 -> V_64 = V_57 ;
}
int F_32 ( struct V_50 * V_51 ,
T_4 V_38 , T_4 V_65 )
{
if ( V_38 == ( V_51 -> V_60 + 2 ) ) {
if ( ( F_33 ( V_65 ) == 29 ) && ( F_34 ( V_65 ) == 1 ) )
return V_66 ;
if ( ( F_33 ( V_65 ) == 29 ) && ( F_34 ( V_65 ) == 2 ) )
return V_66 ;
}
return V_67 ;
}
