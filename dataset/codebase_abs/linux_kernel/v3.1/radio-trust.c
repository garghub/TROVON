static void F_1 ( struct V_1 * V_2 , int V_3 , ... )
{
unsigned char V_4 , V_5 ;
T_1 args ;
va_start ( args , V_3 ) ;
V_6 ;
V_7 ;
V_8 ;
V_9 ;
V_10 ;
V_8 ;
for(; V_3 ; V_3 -- ) {
V_4 = va_arg ( args , unsigned ) ;
for( V_5 = 0x80 ; V_5 ; V_5 >>= 1 ) {
if( V_4 & V_5 )
V_6 ;
else
V_9 ;
V_7 ;
V_8 ;
V_10 ;
V_8 ;
}
V_6 ;
V_7 ;
V_8 ;
V_10 ;
V_8 ;
}
V_9 ;
V_8 ;
V_7 ;
V_8 ;
V_6 ;
V_8 ;
va_end ( args ) ;
}
static void F_2 ( struct V_1 * V_2 , T_2 V_11 )
{
F_3 ( & V_2 -> V_12 ) ;
V_2 -> V_13 = V_11 / 2048 ;
F_1 ( V_2 , 2 , V_14 , V_2 -> V_13 ^ 0x1f ) ;
F_4 ( & V_2 -> V_12 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_2 V_15 )
{
F_3 ( & V_2 -> V_12 ) ;
V_2 -> V_16 = V_15 / 4370 ;
F_1 ( V_2 , 2 , V_14 , 0x60 | V_17 [ V_2 -> V_16 ] ) ;
F_4 ( & V_2 -> V_12 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_2 V_18 )
{
F_3 ( & V_2 -> V_12 ) ;
V_2 -> V_19 = V_18 / 4370 ;
F_1 ( V_2 , 2 , V_14 , 0x70 | V_17 [ V_2 -> V_19 ] ) ;
F_4 ( & V_2 -> V_12 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_20 )
{
F_3 ( & V_2 -> V_12 ) ;
V_2 -> V_21 = ! ! V_20 ;
V_2 -> V_22 = ( V_2 -> V_22 & 0xfb ) | ( ! V_2 -> V_21 << 2 ) ;
F_8 ( V_2 -> V_22 , V_2 -> V_23 ) ;
F_4 ( & V_2 -> V_12 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_24 )
{
F_3 ( & V_2 -> V_12 ) ;
V_2 -> V_25 = ! ! V_24 ;
V_2 -> V_22 = ( V_2 -> V_22 & 0xf7 ) | ( V_2 -> V_25 << 3 ) ;
F_8 ( V_2 -> V_22 , V_2 -> V_23 ) ;
F_4 ( & V_2 -> V_12 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_26 , V_27 ;
F_3 ( & V_2 -> V_12 ) ;
for ( V_26 = 0 , V_27 = 0 ; V_26 < 100 ; V_26 ++ )
V_27 |= F_11 ( V_2 -> V_23 ) ;
F_4 ( & V_2 -> V_12 ) ;
return ( V_27 & 1 ) ? 0 : 0xffff ;
}
static int F_12 ( struct V_1 * V_2 )
{
return V_2 -> V_21 ;
}
static void F_13 ( struct V_1 * V_2 , unsigned long V_28 )
{
F_3 ( & V_2 -> V_12 ) ;
V_2 -> V_29 = V_28 ;
V_28 /= 160 ;
V_28 += 1070 ;
F_1 ( V_2 , 5 , V_30 , ( V_28 << 1 ) | 1 , V_28 >> 7 , 0x60 | ( ( V_28 >> 15 ) & 1 ) , 0 ) ;
F_4 ( & V_2 -> V_12 ) ;
}
static int F_14 ( struct V_31 * V_31 , void * V_32 ,
struct V_33 * V_27 )
{
F_15 ( V_27 -> V_34 , L_1 , sizeof( V_27 -> V_34 ) ) ;
F_15 ( V_27 -> V_35 , L_2 , sizeof( V_27 -> V_35 ) ) ;
F_15 ( V_27 -> V_36 , L_3 , sizeof( V_27 -> V_36 ) ) ;
V_27 -> V_37 = V_38 | V_39 ;
return 0 ;
}
static int F_16 ( struct V_31 * V_31 , void * V_32 ,
struct V_40 * V_27 )
{
struct V_1 * V_2 = F_17 ( V_31 ) ;
if ( V_27 -> V_41 > 0 )
return - V_42 ;
F_15 ( V_27 -> V_43 , L_4 , sizeof( V_27 -> V_43 ) ) ;
V_27 -> type = V_44 ;
V_27 -> V_45 = 87.5 * 16000 ;
V_27 -> V_46 = 108 * 16000 ;
V_27 -> V_47 = V_48 | V_49 ;
V_27 -> V_50 = V_51 ;
if ( F_12 ( V_2 ) )
V_27 -> V_52 = V_53 ;
else
V_27 -> V_52 = V_54 ;
V_27 -> signal = F_10 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_31 * V_31 , void * V_32 ,
struct V_40 * V_27 )
{
struct V_1 * V_2 = F_17 ( V_31 ) ;
if ( V_27 -> V_41 )
return - V_42 ;
F_7 ( V_2 , V_27 -> V_52 == V_53 ) ;
return 0 ;
}
static int F_19 ( struct V_31 * V_31 , void * V_32 ,
struct V_55 * V_28 )
{
struct V_1 * V_2 = F_17 ( V_31 ) ;
if ( V_28 -> V_56 != 0 || V_28 -> type != V_44 )
return - V_42 ;
F_13 ( V_2 , V_28 -> V_57 ) ;
return 0 ;
}
static int F_20 ( struct V_31 * V_31 , void * V_32 ,
struct V_55 * V_28 )
{
struct V_1 * V_2 = F_17 ( V_31 ) ;
if ( V_28 -> V_56 != 0 )
return - V_42 ;
V_28 -> type = V_44 ;
V_28 -> V_57 = V_2 -> V_29 ;
return 0 ;
}
static int F_21 ( struct V_31 * V_31 , void * V_32 ,
struct V_58 * V_59 )
{
switch ( V_59 -> V_60 ) {
case V_61 :
return F_22 ( V_59 , 0 , 1 , 1 , 1 ) ;
case V_62 :
return F_22 ( V_59 , 0 , 65535 , 2048 , 65535 ) ;
case V_63 :
case V_64 :
return F_22 ( V_59 , 0 , 65535 , 4370 , 32768 ) ;
}
return - V_42 ;
}
static int F_23 ( struct V_31 * V_31 , void * V_32 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_17 ( V_31 ) ;
switch ( V_66 -> V_60 ) {
case V_61 :
V_66 -> V_67 = V_2 -> V_25 ;
return 0 ;
case V_62 :
V_66 -> V_67 = V_2 -> V_13 * 2048 ;
return 0 ;
case V_63 :
V_66 -> V_67 = V_2 -> V_16 * 4370 ;
return 0 ;
case V_64 :
V_66 -> V_67 = V_2 -> V_19 * 4370 ;
return 0 ;
}
return - V_42 ;
}
static int F_24 ( struct V_31 * V_31 , void * V_32 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_17 ( V_31 ) ;
switch ( V_66 -> V_60 ) {
case V_61 :
F_9 ( V_2 , V_66 -> V_67 ) ;
return 0 ;
case V_62 :
F_2 ( V_2 , V_66 -> V_67 ) ;
return 0 ;
case V_63 :
F_5 ( V_2 , V_66 -> V_67 ) ;
return 0 ;
case V_64 :
F_6 ( V_2 , V_66 -> V_67 ) ;
return 0 ;
}
return - V_42 ;
}
static int F_25 ( struct V_31 * V_68 , void * V_32 , unsigned int * V_26 )
{
* V_26 = 0 ;
return 0 ;
}
static int F_26 ( struct V_31 * V_68 , void * V_32 , unsigned int V_26 )
{
return V_26 ? - V_42 : 0 ;
}
static int F_27 ( struct V_31 * V_31 , void * V_32 ,
struct V_69 * V_70 )
{
V_70 -> V_41 = 0 ;
F_15 ( V_70 -> V_43 , L_5 , sizeof( V_70 -> V_43 ) ) ;
V_70 -> V_50 = V_71 ;
return 0 ;
}
static int F_28 ( struct V_31 * V_31 , void * V_32 ,
struct V_69 * V_70 )
{
return V_70 -> V_41 ? - V_42 : 0 ;
}
static int T_3 F_29 ( void )
{
struct V_1 * V_2 = & V_72 ;
struct V_73 * V_74 = & V_2 -> V_74 ;
int V_75 ;
F_15 ( V_74 -> V_43 , L_6 , sizeof( V_74 -> V_43 ) ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_22 = 0xf ;
F_30 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_23 == - 1 ) {
F_31 ( V_74 , L_7 ) ;
return - V_42 ;
}
if ( ! F_32 ( V_2 -> V_23 , 2 , L_2 ) ) {
F_31 ( V_74 , L_8 , V_2 -> V_23 ) ;
return - V_76 ;
}
V_75 = F_33 ( NULL , V_74 ) ;
if ( V_75 < 0 ) {
F_34 ( V_2 -> V_23 , 2 ) ;
F_31 ( V_74 , L_9 ) ;
return V_75 ;
}
F_15 ( V_2 -> V_77 . V_43 , V_74 -> V_43 , sizeof( V_2 -> V_77 . V_43 ) ) ;
V_2 -> V_77 . V_74 = V_74 ;
V_2 -> V_77 . V_78 = & V_79 ;
V_2 -> V_77 . V_80 = & V_81 ;
V_2 -> V_77 . V_82 = V_83 ;
F_35 ( & V_2 -> V_77 , V_2 ) ;
F_1 ( V_2 , 2 , V_14 , 0x80 ) ;
F_1 ( V_2 , 2 , V_14 , 0xa0 ) ;
F_1 ( V_2 , 2 , V_14 , 0xc0 ) ;
F_1 ( V_2 , 2 , V_14 , 0xe0 ) ;
F_1 ( V_2 , 2 , V_14 , 0x40 ) ;
F_2 ( V_2 , 0xffff ) ;
F_5 ( V_2 , 0x8000 ) ;
F_6 ( V_2 , 0x8000 ) ;
F_7 ( V_2 , 1 ) ;
F_9 ( V_2 , 1 ) ;
if ( F_36 ( & V_2 -> V_77 , V_84 , V_85 ) < 0 ) {
F_37 ( V_74 ) ;
F_34 ( V_2 -> V_23 , 2 ) ;
return - V_42 ;
}
F_38 ( V_74 , L_10 ) ;
return 0 ;
}
static void T_4 F_39 ( void )
{
struct V_1 * V_2 = & V_72 ;
F_40 ( & V_2 -> V_77 ) ;
F_37 ( & V_2 -> V_74 ) ;
F_34 ( V_2 -> V_23 , 2 ) ;
}
