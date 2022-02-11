static void T_1 F_1 ( void )
{
void T_2 * V_1 ;
V_1 = ( void T_2 * ) V_2 ;
F_2 ( F_3 ( V_1 ) | 0x000001e0 , V_1 ) ;
V_1 = ( void T_2 * ) V_3 ;
F_2 ( F_3 ( V_1 ) | 1 | V_4 , V_1 ) ;
F_4 () ;
V_1 = ( void T_2 * ) F_5 ( V_5 ) ;
F_2 ( V_6 | V_7 ,
V_1 + V_8 ) ;
F_2 ( V_9 , V_1 + V_10 ) ;
F_4 () ;
F_2 ( V_11 , V_1 + V_12 ) ;
F_4 () ;
}
int T_1 F_6 ( void )
{
unsigned short V_13 ;
F_7 ( V_14 ,
V_14 + V_15 ) ;
V_13 = F_8 ( V_16 ) ;
switch ( F_9 ( V_13 ) ) {
case V_17 :
case V_18 :
F_7 ( V_19 ,
V_19 + V_20 ) ;
case V_21 :
break;
default:
return - V_22 ;
}
F_10 ( L_1 \
L_2 , F_11 () ,
( V_13 >> 4 ) & 0xf , ( V_13 >> 8 ) & 0xf , V_13 & 0xf ) ;
F_1 () ;
return 0 ;
}
static void F_12 ( struct V_23 * V_24 , int V_25 ,
unsigned int V_26 )
{
struct V_27 * V_28 = V_24 -> V_29 ;
unsigned long V_30 = ( unsigned long ) V_28 -> V_31 ;
V_30 &= 0xffffff00 ;
if ( V_26 & V_32 ) {
V_30 += V_33 ;
} else if ( V_26 & V_34 ) {
V_30 += V_35 ;
} else {
V_30 += V_36 ;
}
V_28 -> V_37 = V_28 -> V_31 = ( void T_2 * ) V_30 ;
if ( V_25 != V_38 ) {
F_13 ( V_25 , V_28 -> V_31 ) ;
F_4 () ;
}
}
static int F_14 ( struct V_23 * V_24 )
{
return F_3 ( ( void T_2 * ) V_39 ) & 1 ;
}
static void T_1 F_15 ( void )
{
int V_40 = ( F_16 ( V_39 ) & ( 0x7 << 1 ) ) |
( ( F_8 ( V_41 ) >> 6 ) & 0x1 ) ;
F_17 ( 206 ) ;
switch ( V_40 ) {
case 0 : case 2 : case 8 : case 0xC : case 0xD :
V_42 . V_43 = 1 ;
case 1 : case 3 : case 9 : case 0xE : case 0xF :
F_18 ( & V_44 ) ;
}
}
static void F_19 ( struct V_45 * V_46 , int V_47 , int V_48 )
{
if ( V_47 )
F_20 ( V_49 , 0 , V_50 ) ;
else
F_20 ( V_49 , V_50 , 0 ) ;
}
static int F_21 ( const struct V_51 * V_52 , T_3 V_53 , T_3 V_54 )
{
if ( ( V_53 < 11 ) || ( V_53 > 13 ) || V_54 == 0 )
return - 1 ;
if ( V_53 == 11 )
return ( V_54 == 1 ) ? V_55 : 0xff ;
if ( V_53 == 12 ) {
switch ( V_54 ) {
case 1 : return V_56 ;
case 2 : return V_55 ;
case 3 : return V_57 ;
case 4 : return V_58 ;
}
}
if ( V_53 == 13 ) {
switch ( V_54 ) {
case 1 : return V_58 ;
case 2 : return V_56 ;
case 3 : return V_55 ;
case 4 : return V_57 ;
}
}
return - 1 ;
}
static int F_22 ( const struct V_51 * V_52 , T_3 V_53 , T_3 V_54 )
{
if ( ( V_53 < 12 ) || ( V_53 > 13 ) || V_54 == 0 )
return - 1 ;
if ( V_53 == 12 ) {
switch ( V_54 ) {
case 1 : return V_59 ;
case 2 : return V_60 ;
case 3 : return V_61 ;
case 4 : return V_62 ;
}
}
if ( V_53 == 13 ) {
switch ( V_54 ) {
case 1 : return V_62 ;
case 2 : return V_59 ;
case 3 : return V_60 ;
case 4 : return V_61 ;
}
}
return - 1 ;
}
int T_1 F_23 ( int V_63 )
{
if ( V_63 )
V_64 . V_65 = F_22 ;
return F_18 ( & V_66 ) ;
}
static void T_1 F_24 ( void )
{
F_25 ( 203 , 0 ) ;
F_26 ( V_67 , V_68 ) ;
F_26 ( V_69 , V_68 ) ;
F_26 ( V_70 , V_71 ) ;
F_26 ( V_72 , V_71 ) ;
F_26 ( V_73 , V_71 ) ;
F_26 ( V_74 , V_71 ) ;
F_27 (
V_75 ,
V_75 + 0x000400000 - 1 ,
V_76 ,
V_76 + 0x000400000 - 1 ,
V_77 ,
V_77 + 0x000010000 - 1 ,
V_70 , V_67 ,
0 , 0 , 0 ) ;
F_27 (
V_75 + 0x004000000 ,
V_75 + 0x004400000 - 1 ,
V_76 + 0x004000000 ,
V_76 + 0x004400000 - 1 ,
V_77 + 0x004000000 ,
V_77 + 0x004010000 - 1 ,
V_72 , V_69 ,
0 , 0 , 1 ) ;
F_18 ( & V_78 ) ;
F_25 ( 202 , 0 ) ;
}
static void T_1 F_28 ( void )
{
F_26 ( V_67 , V_71 ) ;
F_26 ( V_69 , V_71 ) ;
F_26 ( V_79 , V_80 ) ;
F_29 ( 201 ) ;
F_29 ( 202 ) ;
F_27 (
V_75 ,
V_75 + 0x000400000 - 1 ,
V_76 ,
V_76 + 0x000400000 - 1 ,
V_77 ,
V_77 + 0x000010000 - 1 ,
V_79 , V_67 , 0 , 0 , 0 ) ;
F_27 (
V_75 + 0x008000000 ,
V_75 + 0x008400000 - 1 ,
V_76 + 0x008000000 ,
V_76 + 0x008400000 - 1 ,
V_77 + 0x008000000 ,
V_77 + 0x008010000 - 1 ,
V_79 , V_69 , 0 , 0 , 1 ) ;
F_15 () ;
}
int T_1 F_30 ( void )
{
int V_81 , V_63 ;
V_63 = ( F_9 ( F_8 ( V_16 ) ) != V_21 ) ;
F_31 ( 0 , V_82 ,
F_32 ( V_82 ) ) ;
F_33 ( V_83 ,
F_32 ( V_82 ) ) ;
F_2 ( V_6 ,
( void T_2 * ) F_5 ( V_5 ) + V_8 ) ;
F_4 () ;
F_2 ( V_6 ,
( void T_2 * ) F_5 ( V_84 ) + V_8 ) ;
F_4 () ;
F_2 ( V_85 ,
( void T_2 * ) F_5 ( V_86 ) + V_8 ) ;
F_4 () ;
F_2 ( V_85 ,
( void T_2 * ) F_5 ( V_87 ) + V_8 ) ;
F_4 () ;
V_63 ? F_28 () : F_24 () ;
V_81 = F_8 ( V_41 ) &
( V_63 ? V_88 : V_89 ) ;
F_34 ( 128 << 20 , 4 , V_81 ) ;
return F_35 ( V_90 , F_32 ( V_90 ) ) ;
}
