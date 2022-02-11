int F_1 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 == V_4 )
return 0 ;
else
return 1 ;
}
void F_2 ( void )
{
volatile T_1 V_5 = ( T_1 ) V_6 ;
F_3 ( L_1
L_2 ) ;
V_5 -> V_7 |= 0x10 ;
while( 1 )
;
}
static void F_4 ( char * V_8 )
{
sprintf ( V_8 , L_3 , V_9 == V_10 ? 6 : 4 ) ;
}
static void T_2 F_5 ( void )
{
F_6 ( V_11 , 192 ) ;
}
void T_2 F_7 ( void )
{
volatile T_1 V_5 = ( T_1 ) V_6 ;
if ( ! V_12 ) {
if ( V_9 == V_10 )
V_12 = V_13 ;
else
V_12 = V_14 ;
}
#if 0
bvme6000_set_vectors();
#endif
V_15 = 0xffffffff ;
V_16 = V_17 ;
V_18 = F_5 ;
V_19 = V_20 ;
V_21 = V_22 ;
V_23 = V_24 ;
V_25 = F_2 ;
V_26 = F_4 ;
F_3 ( L_4 ,
* V_27 & V_28 ? L_5 : L_6 ) ;
V_5 -> V_29 = 0x00 ;
V_5 -> V_30 = 0x18 ;
V_5 -> V_31 = 0x00 ;
V_5 -> V_32 = 0x00 ;
V_5 -> V_33 = 0x00 ;
V_5 -> V_34 = 0x80 ;
V_5 -> V_35 = 0xbc | ( * V_27 & V_28 ? 0 : 0x40 ) ;
V_5 -> V_36 = 0xf3 ;
V_5 -> V_37 = 0x01 ;
V_5 -> V_7 = 0x03 ;
V_38 = 0 ;
}
T_3 F_8 ( int V_39 , void * V_40 )
{
unsigned long * V_41 = ( unsigned long * ) V_42 ;
unsigned long * V_43 = ( unsigned long * ) 0xf8000000 ;
while ( * ( volatile unsigned char * ) V_44 & V_45 )
;
* ( V_41 + 4 ) = * ( V_43 + 4 ) ;
* ( V_41 + 9 ) = * ( V_43 + 9 ) ;
* ( V_41 + 47 ) = * ( V_43 + 47 ) ;
* ( V_41 + 0x1f ) = * ( V_43 + 0x1f ) ;
return V_46 ;
}
static T_3 F_9 ( int V_39 , void * V_40 )
{
volatile T_4 V_47 = ( T_4 ) V_48 ;
unsigned char V_49 = V_47 -> V_49 & 0xc0 ;
V_47 -> V_49 = V_49 | 0x20 ;
return F_10 ( V_39 , V_40 ) ;
}
void V_17 ( T_5 V_50 )
{
volatile T_4 V_47 = ( T_4 ) V_48 ;
unsigned char V_49 = V_47 -> V_49 & 0xc0 ;
V_47 -> V_49 = 0 ;
F_10 = V_50 ;
if ( F_11 ( V_51 , F_9 , 0 ,
L_7 , F_9 ) )
F_12 ( L_8 ) ;
V_47 -> V_52 = 0x04 ;
V_47 -> V_53 = 39999 >> 8 ;
V_47 -> V_54 = 39999 & 0xff ;
V_47 -> V_55 &= 0xef ;
V_47 -> V_49 = 0x40 ;
V_47 -> V_56 = 0x80 ;
V_47 -> V_55 = 0 ;
V_47 -> V_52 = 0x0a ;
V_47 -> V_57 &= 0xdf ;
V_47 -> V_49 = 0 ;
V_47 -> V_52 = 0x05 ;
V_47 -> V_49 = V_49 ;
if ( F_11 ( V_58 , F_8 , 0 ,
L_9 , F_8 ) )
F_12 ( L_10 ) ;
}
T_6 V_20 ( void )
{
volatile T_4 V_47 = ( T_4 ) V_48 ;
volatile T_1 V_5 = ( T_1 ) V_6 ;
unsigned char V_49 = V_47 -> V_49 & 0xc0 ;
unsigned char V_59 , V_60 ;
T_6 V_61 = 800000 , V_62 ;
V_47 -> V_49 = 0 ;
do {
V_62 = V_61 ;
V_59 = V_47 -> V_49 & 0x20 ;
V_60 = V_5 -> V_37 & 0x04 ;
V_47 -> V_52 |= 0x40 ;
V_61 = V_47 -> V_53 << 8 ;
V_61 |= V_47 -> V_54 ;
} while ( V_59 != ( V_47 -> V_49 & 0x20 ) ||
V_60 != ( V_5 -> V_37 & 0x04 ) ||
abs ( V_62 - V_61 ) > 80 ||
V_61 > 39960 );
V_61 = 39999 - V_61 ;
if ( ! V_60 )
V_61 += 40000 ;
V_61 /= 8 ;
if ( V_59 )
V_61 += 10000 ;
V_47 -> V_49 = V_49 ;
return V_61 * 1000 ;
}
int V_22 ( int V_63 , struct V_64 * V_65 )
{
volatile T_4 V_47 = ( T_4 ) V_48 ;
unsigned char V_49 = V_47 -> V_49 & 0xc0 ;
V_47 -> V_49 = 0x40 ;
if ( V_63 )
{
V_47 -> V_57 = V_65 -> V_66 % 4 ;
V_47 -> V_67 = 0 ;
V_47 -> V_68 = F_13 ( V_65 -> V_69 ) ;
V_47 -> V_70 = F_13 ( V_65 -> V_71 ) ;
V_47 -> V_72 = F_13 ( V_65 -> V_73 ) ;
V_47 -> V_74 = F_13 ( V_65 -> V_75 ) ;
V_47 -> V_76 = F_13 ( V_65 -> V_77 + 1 ) ;
V_47 -> V_78 = F_13 ( V_65 -> V_66 % 100 ) ;
if ( V_65 -> V_79 >= 0 )
V_47 -> V_80 = F_13 ( V_65 -> V_79 + 1 ) ;
V_47 -> V_57 = V_65 -> V_66 % 4 | 0x08 ;
}
else
{
do {
V_65 -> V_69 = F_14 ( V_47 -> V_68 ) ;
V_65 -> V_71 = F_14 ( V_47 -> V_70 ) ;
V_65 -> V_73 = F_14 ( V_47 -> V_72 ) ;
V_65 -> V_75 = F_14 ( V_47 -> V_74 ) ;
V_65 -> V_77 = F_14 ( V_47 -> V_76 ) - 1 ;
V_65 -> V_66 = F_14 ( V_47 -> V_78 ) ;
if ( V_65 -> V_66 < 70 )
V_65 -> V_66 += 100 ;
V_65 -> V_79 = F_14 ( V_47 -> V_80 ) - 1 ;
} while ( V_65 -> V_69 != F_14 ( V_47 -> V_68 ) );
}
V_47 -> V_49 = V_49 ;
return 0 ;
}
int V_24 ( unsigned long V_81 )
{
int V_82 = 0 ;
short V_83 = V_81 % 60 , V_84 = ( V_81 / 60 ) % 60 ;
unsigned char V_85 , V_86 ;
volatile T_4 V_47 = ( T_4 ) V_48 ;
unsigned char V_49 = V_47 -> V_49 & 0xc0 ;
unsigned long V_87 ;
volatile int V_88 ;
V_47 -> V_49 = 0 ;
V_85 = F_14 ( V_47 -> V_70 ) ;
if ( ( V_85 < V_84
? V_84 - V_85
: V_85 - V_84 ) < 30 )
{
F_15 ( V_87 ) ;
V_86 = V_47 -> V_67 ;
while ( V_86 == V_47 -> V_67 )
;
for ( V_88 = 0 ; V_88 < 1000 ; V_88 ++ )
;
V_47 -> V_70 = F_13 ( V_84 ) ;
V_47 -> V_68 = F_13 ( V_83 ) ;
F_16 ( V_87 ) ;
}
else
V_82 = - 1 ;
V_47 -> V_49 = V_49 ;
return V_82 ;
}
