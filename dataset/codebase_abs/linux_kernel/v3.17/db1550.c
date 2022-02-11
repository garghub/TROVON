static void T_1 F_1 ( void )
{
void T_2 * V_1 ;
unsigned long V_2 ;
V_2 = F_2 ( V_3 ) ;
F_3 ( V_2 | 0x000001e0 , V_3 ) ;
V_2 = F_2 ( V_4 ) ;
F_3 ( V_2 | 1 | V_5 , V_4 ) ;
V_1 = ( void T_2 * ) F_4 ( V_6 ) ;
F_5 ( V_7 | V_8 ,
V_1 + V_9 ) ;
F_5 ( V_10 , V_1 + V_11 ) ;
F_6 () ;
F_5 ( V_12 , V_1 + V_13 ) ;
F_6 () ;
}
int T_1 F_7 ( void )
{
unsigned short V_14 ;
F_8 ( V_15 ,
V_15 + V_16 ) ;
V_14 = F_9 ( V_17 ) ;
switch ( F_10 ( V_14 ) ) {
case V_18 :
case V_19 :
F_8 ( V_20 ,
V_20 + V_21 ) ;
case V_22 :
break;
default:
return - V_23 ;
}
F_11 ( L_1 \
L_2 , F_12 () ,
( V_14 >> 4 ) & 0xf , ( V_14 >> 8 ) & 0xf , V_14 & 0xf ) ;
F_1 () ;
return 0 ;
}
static void F_13 ( struct V_24 * V_25 , int V_26 ,
unsigned int V_27 )
{
struct V_28 * V_29 = V_25 -> V_30 ;
unsigned long V_31 = ( unsigned long ) V_29 -> V_32 ;
V_31 &= 0xffffff00 ;
if ( V_27 & V_33 ) {
V_31 += V_34 ;
} else if ( V_27 & V_35 ) {
V_31 += V_36 ;
} else {
V_31 += V_37 ;
}
V_29 -> V_38 = V_29 -> V_32 = ( void T_2 * ) V_31 ;
if ( V_26 != V_39 ) {
F_14 ( V_26 , V_29 -> V_32 ) ;
F_6 () ;
}
}
static int F_15 ( struct V_24 * V_25 )
{
return F_16 ( V_40 ) & 1 ;
}
static void T_1 F_17 ( void )
{
int V_41 = ( F_16 ( V_40 ) & ( 0x7 << 1 ) ) |
( ( F_9 ( V_42 ) >> 6 ) & 0x1 ) ;
F_18 ( 206 ) ;
switch ( V_41 ) {
case 0 : case 2 : case 8 : case 0xC : case 0xD :
V_43 . V_44 = 1 ;
case 1 : case 3 : case 9 : case 0xE : case 0xF :
F_19 ( & V_45 ) ;
}
}
static void F_20 ( struct V_46 * V_47 , int V_48 , int V_49 )
{
if ( V_48 )
F_21 ( V_50 , 0 , V_51 ) ;
else
F_21 ( V_50 , V_51 , 0 ) ;
}
static int F_22 ( const struct V_52 * V_53 , T_3 V_54 , T_3 V_55 )
{
if ( ( V_54 < 11 ) || ( V_54 > 13 ) || V_55 == 0 )
return - 1 ;
if ( V_54 == 11 )
return ( V_55 == 1 ) ? V_56 : 0xff ;
if ( V_54 == 12 ) {
switch ( V_55 ) {
case 1 : return V_57 ;
case 2 : return V_56 ;
case 3 : return V_58 ;
case 4 : return V_59 ;
}
}
if ( V_54 == 13 ) {
switch ( V_55 ) {
case 1 : return V_59 ;
case 2 : return V_57 ;
case 3 : return V_56 ;
case 4 : return V_58 ;
}
}
return - 1 ;
}
static int F_23 ( const struct V_52 * V_53 , T_3 V_54 , T_3 V_55 )
{
if ( ( V_54 < 12 ) || ( V_54 > 13 ) || V_55 == 0 )
return - 1 ;
if ( V_54 == 12 ) {
switch ( V_55 ) {
case 1 : return V_60 ;
case 2 : return V_61 ;
case 3 : return V_62 ;
case 4 : return V_63 ;
}
}
if ( V_54 == 13 ) {
switch ( V_55 ) {
case 1 : return V_63 ;
case 2 : return V_60 ;
case 3 : return V_61 ;
case 4 : return V_62 ;
}
}
return - 1 ;
}
int T_1 F_24 ( int V_64 )
{
if ( V_64 )
V_65 . V_66 = F_23 ;
return F_19 ( & V_67 ) ;
}
static void T_1 F_25 ( void )
{
F_26 ( 203 , 0 ) ;
F_27 ( V_68 , V_69 ) ;
F_27 ( V_70 , V_69 ) ;
F_27 ( V_71 , V_72 ) ;
F_27 ( V_73 , V_72 ) ;
F_27 ( V_74 , V_72 ) ;
F_27 ( V_75 , V_72 ) ;
F_28 (
V_76 ,
V_76 + 0x000400000 - 1 ,
V_77 ,
V_77 + 0x000400000 - 1 ,
V_78 ,
V_78 + 0x000010000 - 1 ,
V_71 , V_68 ,
0 , 0 , 0 ) ;
F_28 (
V_76 + 0x004000000 ,
V_76 + 0x004400000 - 1 ,
V_77 + 0x004000000 ,
V_77 + 0x004400000 - 1 ,
V_78 + 0x004000000 ,
V_78 + 0x004010000 - 1 ,
V_73 , V_70 ,
0 , 0 , 1 ) ;
F_19 ( & V_79 ) ;
F_26 ( 202 , 0 ) ;
}
static void T_1 F_29 ( void )
{
F_27 ( V_68 , V_72 ) ;
F_27 ( V_70 , V_72 ) ;
F_27 ( V_80 , V_81 ) ;
F_30 ( 201 ) ;
F_30 ( 202 ) ;
F_28 (
V_76 ,
V_76 + 0x000400000 - 1 ,
V_77 ,
V_77 + 0x000400000 - 1 ,
V_78 ,
V_78 + 0x000010000 - 1 ,
V_80 , V_68 , 0 , 0 , 0 ) ;
F_28 (
V_76 + 0x008000000 ,
V_76 + 0x008400000 - 1 ,
V_77 + 0x008000000 ,
V_77 + 0x008400000 - 1 ,
V_78 + 0x008000000 ,
V_78 + 0x008010000 - 1 ,
V_80 , V_70 , 0 , 0 , 1 ) ;
F_17 () ;
}
int T_1 F_31 ( void )
{
int V_82 , V_64 ;
struct V_83 * V_84 ;
V_64 = ( F_10 ( F_9 ( V_17 ) ) != V_22 ) ;
F_32 ( 0 , V_85 ,
F_33 ( V_85 ) ) ;
F_34 ( V_86 ,
F_33 ( V_85 ) ) ;
V_84 = F_35 ( NULL , L_3 ) ;
if ( ! F_36 ( V_84 ) ) {
F_37 ( V_84 ) ;
F_38 ( V_84 ) ;
}
V_84 = F_35 ( NULL , L_4 ) ;
if ( ! F_36 ( V_84 ) ) {
F_37 ( V_84 ) ;
F_38 ( V_84 ) ;
}
F_5 ( V_7 ,
( void T_2 * ) F_4 ( V_6 ) + V_9 ) ;
F_6 () ;
F_5 ( V_7 ,
( void T_2 * ) F_4 ( V_87 ) + V_9 ) ;
F_6 () ;
F_5 ( V_88 ,
( void T_2 * ) F_4 ( V_89 ) + V_9 ) ;
F_6 () ;
F_5 ( V_88 ,
( void T_2 * ) F_4 ( V_90 ) + V_9 ) ;
F_6 () ;
V_64 ? F_29 () : F_25 () ;
V_82 = F_9 ( V_42 ) &
( V_64 ? V_91 : V_92 ) ;
F_39 ( 128 << 20 , 4 , V_82 ) ;
return F_40 ( V_93 , F_33 ( V_93 ) ) ;
}
