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
F_14 ( V_25 , V_28 -> V_31 ) ;
F_6 () ;
}
}
static int F_15 ( struct V_23 * V_24 )
{
return F_16 ( V_39 ) & 1 ;
}
static void T_1 F_17 ( void )
{
int V_40 = ( F_16 ( V_39 ) & ( 0x7 << 1 ) ) |
( ( F_9 ( V_41 ) >> 6 ) & 0x1 ) ;
F_18 ( 206 ) ;
switch ( V_40 ) {
case 0 : case 2 : case 8 : case 0xC : case 0xD :
V_42 . V_43 = 1 ;
case 1 : case 3 : case 9 : case 0xE : case 0xF :
F_19 ( & V_44 ) ;
}
}
static void F_20 ( struct V_45 * V_46 , int V_47 , int V_48 )
{
if ( V_47 )
F_21 ( V_49 , 0 , V_50 ) ;
else
F_21 ( V_49 , V_50 , 0 ) ;
}
static int F_22 ( const struct V_51 * V_52 , T_3 V_53 , T_3 V_54 )
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
static int F_23 ( const struct V_51 * V_52 , T_3 V_53 , T_3 V_54 )
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
int T_1 F_24 ( int V_63 )
{
if ( V_63 )
V_64 . V_65 = F_23 ;
return F_19 ( & V_66 ) ;
}
static void T_1 F_25 ( void )
{
F_26 ( 203 , 0 ) ;
F_27 ( V_67 , V_68 ) ;
F_27 ( V_69 , V_68 ) ;
F_27 ( V_70 , V_71 ) ;
F_27 ( V_72 , V_71 ) ;
F_27 ( V_73 , V_71 ) ;
F_27 ( V_74 , V_71 ) ;
F_28 (
V_75 ,
V_75 + 0x000400000 - 1 ,
V_76 ,
V_76 + 0x000400000 - 1 ,
V_77 ,
V_77 + 0x000010000 - 1 ,
V_70 , V_67 ,
0 , 0 , 0 ) ;
F_28 (
V_75 + 0x004000000 ,
V_75 + 0x004400000 - 1 ,
V_76 + 0x004000000 ,
V_76 + 0x004400000 - 1 ,
V_77 + 0x004000000 ,
V_77 + 0x004010000 - 1 ,
V_72 , V_69 ,
0 , 0 , 1 ) ;
F_19 ( & V_78 ) ;
F_26 ( 202 , 0 ) ;
}
static void T_1 F_29 ( void )
{
F_27 ( V_67 , V_71 ) ;
F_27 ( V_69 , V_71 ) ;
F_27 ( V_79 , V_80 ) ;
F_30 ( 201 ) ;
F_30 ( 202 ) ;
F_28 (
V_75 ,
V_75 + 0x000400000 - 1 ,
V_76 ,
V_76 + 0x000400000 - 1 ,
V_77 ,
V_77 + 0x000010000 - 1 ,
V_79 , V_67 , 0 , 0 , 0 ) ;
F_28 (
V_75 + 0x008000000 ,
V_75 + 0x008400000 - 1 ,
V_76 + 0x008000000 ,
V_76 + 0x008400000 - 1 ,
V_77 + 0x008000000 ,
V_77 + 0x008010000 - 1 ,
V_79 , V_69 , 0 , 0 , 1 ) ;
F_17 () ;
}
int T_1 F_31 ( void )
{
int V_81 , V_63 ;
struct V_82 * V_83 ;
V_63 = ( F_10 ( F_9 ( V_16 ) ) != V_21 ) ;
F_32 ( 0 , V_84 ,
F_33 ( V_84 ) ) ;
F_34 ( V_85 ,
F_33 ( V_84 ) ) ;
V_83 = F_35 ( NULL , L_3 ) ;
if ( ! F_36 ( V_83 ) ) {
F_37 ( V_83 , 50000000 ) ;
F_38 ( V_83 ) ;
F_39 ( V_83 ) ;
}
V_83 = F_35 ( NULL , L_4 ) ;
if ( ! F_36 ( V_83 ) ) {
F_37 ( V_83 , V_86 . V_87 ) ;
F_38 ( V_83 ) ;
F_39 ( V_83 ) ;
}
F_5 ( V_6 ,
( void T_2 * ) F_4 ( V_5 ) + V_8 ) ;
F_6 () ;
F_5 ( V_6 ,
( void T_2 * ) F_4 ( V_88 ) + V_8 ) ;
F_6 () ;
F_5 ( V_89 ,
( void T_2 * ) F_4 ( V_90 ) + V_8 ) ;
F_6 () ;
F_5 ( V_89 ,
( void T_2 * ) F_4 ( V_91 ) + V_8 ) ;
F_6 () ;
V_63 ? F_29 () : F_25 () ;
V_81 = F_9 ( V_41 ) &
( V_63 ? V_92 : V_93 ) ;
F_40 ( 128 << 20 , 4 , V_81 ) ;
return F_41 ( V_94 , F_33 ( V_94 ) ) ;
}
