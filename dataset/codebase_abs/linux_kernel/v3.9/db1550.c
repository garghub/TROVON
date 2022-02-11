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
if ( ( F_9 ( V_13 ) == V_17 ) ||
( F_9 ( V_13 ) == V_18 ) )
F_7 ( V_19 ,
V_19 + V_20 ) ;
F_10 ( L_1 \
L_2 , F_11 () ,
( V_13 >> 4 ) & 0xf , ( V_13 >> 8 ) & 0xf , V_13 & 0xf ) ;
F_1 () ;
return 0 ;
}
static void F_12 ( struct V_21 * V_22 , int V_23 ,
unsigned int V_24 )
{
struct V_25 * V_26 = V_22 -> V_27 ;
unsigned long V_28 = ( unsigned long ) V_26 -> V_29 ;
V_28 &= 0xffffff00 ;
if ( V_24 & V_30 ) {
V_28 += V_31 ;
} else if ( V_24 & V_32 ) {
V_28 += V_33 ;
} else {
V_28 += V_34 ;
}
V_26 -> V_35 = V_26 -> V_29 = ( void T_2 * ) V_28 ;
if ( V_23 != V_36 ) {
F_13 ( V_23 , V_26 -> V_29 ) ;
F_4 () ;
}
}
static int F_14 ( struct V_21 * V_22 )
{
return F_3 ( ( void T_2 * ) V_37 ) & 1 ;
}
static void T_1 F_15 ( void )
{
int V_38 = ( F_16 ( V_37 ) & ( 0x7 << 1 ) ) |
( ( F_8 ( V_39 ) >> 6 ) & 0x1 ) ;
F_17 ( 206 ) ;
switch ( V_38 ) {
case 0 : case 2 : case 8 : case 0xC : case 0xD :
V_40 . V_41 = 1 ;
case 1 : case 3 : case 9 : case 0xE : case 0xF :
F_18 ( & V_42 ) ;
}
}
static void F_19 ( struct V_43 * V_44 , int V_45 , int V_46 )
{
if ( V_45 )
F_20 ( V_47 , 0 , V_48 ) ;
else
F_20 ( V_47 , V_48 , 0 ) ;
}
static int F_21 ( const struct V_49 * V_50 , T_3 V_51 , T_3 V_52 )
{
if ( ( V_51 < 11 ) || ( V_51 > 13 ) || V_52 == 0 )
return - 1 ;
if ( V_51 == 11 )
return ( V_52 == 1 ) ? V_53 : 0xff ;
if ( V_51 == 12 ) {
switch ( V_52 ) {
case 1 : return V_54 ;
case 2 : return V_53 ;
case 3 : return V_55 ;
case 4 : return V_56 ;
}
}
if ( V_51 == 13 ) {
switch ( V_52 ) {
case 1 : return V_56 ;
case 2 : return V_54 ;
case 3 : return V_53 ;
case 4 : return V_55 ;
}
}
return - 1 ;
}
static int F_22 ( const struct V_49 * V_50 , T_3 V_51 , T_3 V_52 )
{
if ( ( V_51 < 12 ) || ( V_51 > 13 ) || V_52 == 0 )
return - 1 ;
if ( V_51 == 12 ) {
switch ( V_52 ) {
case 1 : return V_57 ;
case 2 : return V_58 ;
case 3 : return V_59 ;
case 4 : return V_60 ;
}
}
if ( V_51 == 13 ) {
switch ( V_52 ) {
case 1 : return V_60 ;
case 2 : return V_57 ;
case 3 : return V_58 ;
case 4 : return V_59 ;
}
}
return - 1 ;
}
int T_1 F_23 ( int V_61 )
{
if ( V_61 )
V_62 . V_63 = F_22 ;
return F_18 ( & V_64 ) ;
}
static void T_1 F_24 ( void )
{
F_25 ( 203 , 0 ) ;
F_26 ( V_65 , V_66 ) ;
F_26 ( V_67 , V_66 ) ;
F_26 ( V_68 , V_69 ) ;
F_26 ( V_70 , V_69 ) ;
F_26 ( V_71 , V_69 ) ;
F_26 ( V_72 , V_69 ) ;
F_27 (
V_73 ,
V_73 + 0x000400000 - 1 ,
V_74 ,
V_74 + 0x000400000 - 1 ,
V_75 ,
V_75 + 0x000010000 - 1 ,
V_68 , V_65 ,
0 , 0 , 0 ) ;
F_27 (
V_73 + 0x004000000 ,
V_73 + 0x004400000 - 1 ,
V_74 + 0x004000000 ,
V_74 + 0x004400000 - 1 ,
V_75 + 0x004000000 ,
V_75 + 0x004010000 - 1 ,
V_70 , V_67 ,
0 , 0 , 1 ) ;
F_18 ( & V_76 ) ;
F_25 ( 202 , 0 ) ;
}
static void T_1 F_28 ( void )
{
F_26 ( V_65 , V_69 ) ;
F_26 ( V_67 , V_69 ) ;
F_26 ( V_77 , V_78 ) ;
F_29 ( 201 ) ;
F_29 ( 202 ) ;
F_27 (
V_73 ,
V_73 + 0x000400000 - 1 ,
V_74 ,
V_74 + 0x000400000 - 1 ,
V_75 ,
V_75 + 0x000010000 - 1 ,
V_77 , V_65 , 0 , 0 , 0 ) ;
F_27 (
V_73 + 0x008000000 ,
V_73 + 0x008400000 - 1 ,
V_74 + 0x008000000 ,
V_74 + 0x008400000 - 1 ,
V_75 + 0x008000000 ,
V_75 + 0x008010000 - 1 ,
V_77 , V_67 , 0 , 0 , 1 ) ;
F_15 () ;
}
int T_1 F_30 ( void )
{
int V_79 , V_61 ;
V_61 = ( F_9 ( F_8 ( V_16 ) ) != V_80 ) ;
F_31 ( 0 , V_81 ,
F_32 ( V_81 ) ) ;
F_33 ( V_82 ,
F_32 ( V_81 ) ) ;
F_2 ( V_6 ,
( void T_2 * ) F_5 ( V_5 ) + V_8 ) ;
F_4 () ;
F_2 ( V_6 ,
( void T_2 * ) F_5 ( V_83 ) + V_8 ) ;
F_4 () ;
F_2 ( V_84 ,
( void T_2 * ) F_5 ( V_85 ) + V_8 ) ;
F_4 () ;
F_2 ( V_84 ,
( void T_2 * ) F_5 ( V_86 ) + V_8 ) ;
F_4 () ;
V_61 ? F_28 () : F_24 () ;
V_79 = F_8 ( V_39 ) &
( V_61 ? V_87 : V_88 ) ;
F_34 ( 128 << 20 , 4 , V_79 ) ;
return F_35 ( V_89 , F_32 ( V_89 ) ) ;
}
