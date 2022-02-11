static void T_1 F_1 ( void )
{
void T_2 * V_1 ;
unsigned long V_2 ;
V_2 = F_2 ( V_3 ) ;
F_3 ( V_2 | 1 | V_4 , V_3 ) ;
V_1 = ( void T_2 * ) F_4 ( V_5 ) ;
F_5 ( V_6 | V_7 ,
V_1 + V_8 ) ;
F_5 ( V_9 , V_1 + V_10 ) ;
F_6 () ;
F_5 ( V_11 , V_1 + V_12 ) ;
F_6 () ;
}
int T_1 F_7 ( void )
{
unsigned short V_13 ;
F_8 ( V_14 ,
V_14 + V_15 ) ;
V_13 = F_9 ( V_16 ) ;
switch ( F_10 ( V_13 ) ) {
case V_17 :
case V_18 :
F_8 ( V_19 ,
V_19 + V_20 ) ;
case V_21 :
break;
default:
return - V_22 ;
}
F_11 ( L_1 \
L_2 , F_12 () ,
( V_13 >> 4 ) & 0xf , ( V_13 >> 8 ) & 0xf , V_13 & 0xf ) ;
F_1 () ;
return 0 ;
}
static void F_13 ( struct V_23 * V_24 , int V_25 ,
unsigned int V_26 )
{
struct V_27 * V_28 = F_14 ( V_24 ) ;
unsigned long V_29 = ( unsigned long ) V_28 -> V_30 ;
V_29 &= 0xffffff00 ;
if ( V_26 & V_31 ) {
V_29 += V_32 ;
} else if ( V_26 & V_33 ) {
V_29 += V_34 ;
} else {
V_29 += V_35 ;
}
V_28 -> V_36 = V_28 -> V_30 = ( void T_2 * ) V_29 ;
if ( V_25 != V_37 ) {
F_15 ( V_25 , V_28 -> V_30 ) ;
F_6 () ;
}
}
static int F_16 ( struct V_23 * V_24 )
{
return F_17 ( V_38 ) & 1 ;
}
static void T_1 F_18 ( void )
{
int V_39 = ( F_17 ( V_38 ) & ( 0x7 << 1 ) ) |
( ( F_9 ( V_40 ) >> 6 ) & 0x1 ) ;
F_19 ( 206 ) ;
switch ( V_39 ) {
case 0 : case 2 : case 8 : case 0xC : case 0xD :
V_41 . V_42 = 1 ;
case 1 : case 3 : case 9 : case 0xE : case 0xF :
F_20 ( & V_43 ) ;
}
}
static void F_21 ( struct V_44 * V_45 , int V_46 , int V_47 )
{
if ( V_46 )
F_22 ( V_48 , 0 , V_49 ) ;
else
F_22 ( V_48 , V_49 , 0 ) ;
}
static int F_23 ( const struct V_50 * V_51 , T_3 V_52 , T_3 V_53 )
{
if ( ( V_52 < 11 ) || ( V_52 > 13 ) || V_53 == 0 )
return - 1 ;
if ( V_52 == 11 )
return ( V_53 == 1 ) ? V_54 : 0xff ;
if ( V_52 == 12 ) {
switch ( V_53 ) {
case 1 : return V_55 ;
case 2 : return V_54 ;
case 3 : return V_56 ;
case 4 : return V_57 ;
}
}
if ( V_52 == 13 ) {
switch ( V_53 ) {
case 1 : return V_57 ;
case 2 : return V_55 ;
case 3 : return V_54 ;
case 4 : return V_56 ;
}
}
return - 1 ;
}
static int F_24 ( const struct V_50 * V_51 , T_3 V_52 , T_3 V_53 )
{
if ( ( V_52 < 12 ) || ( V_52 > 13 ) || V_53 == 0 )
return - 1 ;
if ( V_52 == 12 ) {
switch ( V_53 ) {
case 1 : return V_58 ;
case 2 : return V_59 ;
case 3 : return V_60 ;
case 4 : return V_61 ;
}
}
if ( V_52 == 13 ) {
switch ( V_53 ) {
case 1 : return V_61 ;
case 2 : return V_58 ;
case 3 : return V_59 ;
case 4 : return V_60 ;
}
}
return - 1 ;
}
int T_1 F_25 ( int V_62 )
{
if ( V_62 )
V_63 . V_64 = F_24 ;
return F_20 ( & V_65 ) ;
}
static void T_1 F_26 ( void )
{
F_27 ( 203 , 0 ) ;
F_28 ( V_66 , V_67 ) ;
F_28 ( V_68 , V_67 ) ;
F_28 ( V_69 , V_70 ) ;
F_28 ( V_71 , V_70 ) ;
F_28 ( V_72 , V_70 ) ;
F_28 ( V_73 , V_70 ) ;
F_29 (
V_74 ,
V_74 + 0x000400000 - 1 ,
V_75 ,
V_75 + 0x000400000 - 1 ,
V_76 ,
V_76 + 0x000010000 - 1 ,
V_69 , V_66 ,
0 , 0 , 0 ) ;
F_29 (
V_74 + 0x004000000 ,
V_74 + 0x004400000 - 1 ,
V_75 + 0x004000000 ,
V_75 + 0x004400000 - 1 ,
V_76 + 0x004000000 ,
V_76 + 0x004010000 - 1 ,
V_71 , V_68 ,
0 , 0 , 1 ) ;
F_20 ( & V_77 ) ;
F_27 ( 202 , 0 ) ;
}
static void T_1 F_30 ( void )
{
F_28 ( V_66 , V_70 ) ;
F_28 ( V_68 , V_70 ) ;
F_28 ( V_78 , V_79 ) ;
F_31 ( 201 ) ;
F_31 ( 202 ) ;
F_29 (
V_74 ,
V_74 + 0x000400000 - 1 ,
V_75 ,
V_75 + 0x000400000 - 1 ,
V_76 ,
V_76 + 0x000010000 - 1 ,
V_78 , V_66 , 0 , 0 , 0 ) ;
F_29 (
V_74 + 0x008000000 ,
V_74 + 0x008400000 - 1 ,
V_75 + 0x008000000 ,
V_75 + 0x008400000 - 1 ,
V_76 + 0x008000000 ,
V_76 + 0x008010000 - 1 ,
V_78 , V_68 , 0 , 0 , 1 ) ;
F_18 () ;
}
int T_1 F_32 ( void )
{
int V_80 , V_62 ;
struct V_81 * V_82 ;
V_62 = ( F_10 ( F_9 ( V_16 ) ) != V_21 ) ;
F_33 ( 0 , V_83 ,
F_34 ( V_83 ) ) ;
F_35 ( V_84 ,
F_34 ( V_83 ) ) ;
V_82 = F_36 ( NULL , L_3 ) ;
if ( ! F_37 ( V_82 ) ) {
F_38 ( V_82 , 50000000 ) ;
F_39 ( V_82 ) ;
F_40 ( V_82 ) ;
}
V_82 = F_36 ( NULL , L_4 ) ;
if ( ! F_37 ( V_82 ) ) {
F_38 ( V_82 , V_85 . V_86 ) ;
F_39 ( V_82 ) ;
F_40 ( V_82 ) ;
}
F_5 ( V_6 ,
( void T_2 * ) F_4 ( V_5 ) + V_8 ) ;
F_6 () ;
F_5 ( V_6 ,
( void T_2 * ) F_4 ( V_87 ) + V_8 ) ;
F_6 () ;
F_5 ( V_88 ,
( void T_2 * ) F_4 ( V_89 ) + V_8 ) ;
F_6 () ;
F_5 ( V_88 ,
( void T_2 * ) F_4 ( V_90 ) + V_8 ) ;
F_6 () ;
V_62 ? F_30 () : F_26 () ;
V_80 = F_9 ( V_40 ) &
( V_62 ? V_91 : V_92 ) ;
F_41 ( 128 << 20 , 4 , V_80 ) ;
return F_42 ( V_93 , F_34 ( V_93 ) ) ;
}
