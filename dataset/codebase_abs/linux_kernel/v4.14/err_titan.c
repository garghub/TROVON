static int
F_1 ( T_1 V_1 , int V_2 )
{
#ifdef F_2
char * V_3 ;
int V_4 = 0 ;
#endif
int V_5 = V_6 ;
#define F_3 (1UL << 28)
#define F_4 (29)
#define F_5 (0x7)
if ( ! ( V_1 & F_3 ) )
return V_7 ;
#ifdef F_2
if ( ! V_2 )
return V_5 ;
V_4 = F_6 ( V_1 , V_8 ) ;
switch( V_4 ) {
case 0 :
case 1 :
case 2 :
case 3 :
V_3 = L_1 ;
break;
case 4 :
case 5 :
V_3 = L_2 ;
V_4 -= 4 ;
break;
default:
V_3 = L_3 ;
break;
}
F_7 ( L_4 ,
V_9 , V_3 , V_4 ) ;
#endif
return V_5 ;
}
static int
F_8 ( int V_10 , T_1 V_11 , int V_2 )
{
int V_5 = V_6 ;
#ifdef F_2
static const char * const V_12 [] = {
L_5 , L_6 , L_7 , L_8
} ;
static const char * const V_13 [] = {
L_9 , L_10 , L_11 , L_12
} ;
#endif
#define F_9 (1UL << 0)
#define F_10 (1UL << 1)
#define F_11 (1UL << 2)
#define F_12 (1UL << 3)
#define F_13 (1UL << 4)
#define F_14 (TITAN__PCHIP_SERROR__UECC | \
TITAN__PCHIP_SERROR__CRE)
#define F_15 (TITAN__PCHIP_SERROR__LOST_UECC | \
TITAN__PCHIP_SERROR__UECC | \
TITAN__PCHIP_SERROR__CRE | \
TITAN__PCHIP_SERROR__NXIO | \
TITAN__PCHIP_SERROR__LOST_CRE)
#define F_16 (52)
#define F_17 (0x3)
#define F_18 (54)
#define F_19 (0x3)
#define F_20 (56)
#define F_21 (0xff)
#define F_22 (15)
#define F_23 (0xffffffffUL)
if ( ! ( V_11 & F_15 ) )
return V_7 ;
#ifdef F_2
if ( ! V_2 )
return V_5 ;
F_7 ( L_13 ,
V_9 , V_10 , V_11 ) ;
if ( V_11 & F_14 ) {
F_7 ( L_14
L_15
L_16 ,
V_9 ,
( V_11 & F_10 ) ? L_17 : L_18 ,
V_12 [ F_6 ( V_11 , V_14 ) ] ,
V_13 [ F_6 ( V_11 , V_15 ) ] ,
( unsigned ) F_6 ( V_11 , V_16 ) ,
F_6 ( V_11 , V_17 ) ) ;
}
if ( V_11 & F_12 )
F_7 ( L_19 , V_9 ) ;
if ( V_11 & F_9 )
F_7 ( L_20 ,
V_9 ) ;
if ( V_11 & F_13 )
F_7 ( L_21 , V_9 ) ;
#endif
return V_5 ;
}
static int
F_24 ( int V_10 , int V_18 , T_1 perror , int V_2 )
{
int V_19 ;
unsigned long V_20 ;
int V_5 = V_6 ;
#ifdef F_2
static const char * const V_21 [] = {
L_22 , L_23 ,
L_24 , L_25 ,
L_12 , L_12 ,
L_26 , L_27 ,
L_12 , L_12 ,
L_28 , L_29 ,
L_30 , L_31 ,
L_32 , L_33
} ;
#endif
#define F_25 (1UL << 0)
#define F_26 (1UL << 1)
#define F_27 (1UL << 2)
#define F_28 (1UL << 3)
#define F_29 (1UL << 4)
#define F_30 (1UL << 5)
#define F_31 (1UL << 6)
#define F_32 (1UL << 7)
#define F_33 (1UL << 8)
#define F_34 (1UL << 9)
#define F_35 (1UL << 10)
#define F_36 (TITAN__PCHIP_PERROR__LOST | \
TITAN__PCHIP_PERROR__SERR | \
TITAN__PCHIP_PERROR__PERR | \
TITAN__PCHIP_PERROR__DCRTO | \
TITAN__PCHIP_PERROR__SGE | \
TITAN__PCHIP_PERROR__APE | \
TITAN__PCHIP_PERROR__TA | \
TITAN__PCHIP_PERROR__DPE | \
TITAN__PCHIP_PERROR__NDS | \
TITAN__PCHIP_PERROR__IPTPR | \
TITAN__PCHIP_PERROR__IPTPW)
#define F_37 (1UL << 47)
#define F_38 (1UL << 48)
#define F_39 (52)
#define F_40 (0x0f)
#define F_41 (14)
#define F_42 (0x1fffffffful)
if ( ! ( perror & F_36 ) )
return V_7 ;
V_19 = F_6 ( perror , V_22 ) ;
V_20 = F_6 ( perror , V_23 ) << 2 ;
if ( ( ( perror & F_33 ) ||
( ( perror & F_36 ) ==
F_25 ) ) &&
( ( ( ( V_19 & 0xE ) == 2 ) && ( V_20 < 0x1000 ) ) ||
( ( ( V_19 & 0xE ) == 6 ) && ( V_20 >= 0xA0000 ) && ( V_20 < 0x100000 ) ) ) ) {
V_5 = V_24 ;
}
#ifdef F_2
if ( ! V_2 )
return V_5 ;
F_7 ( L_34 ,
V_9 , V_10 ,
V_18 ? 'A' : 'G' , perror ) ;
if ( perror & F_35 )
F_7 ( L_35 , V_9 ) ;
if ( perror & F_34 )
F_7 ( L_36 , V_9 ) ;
if ( perror & F_33 )
F_7 ( L_37 ,
V_9 ) ;
if ( perror & F_32 )
F_7 ( L_38 , V_9 ) ;
if ( perror & F_31 )
F_7 ( L_39 , V_9 ) ;
if ( perror & F_30 )
F_7 ( L_40 , V_9 ) ;
if ( perror & F_29 )
F_7 ( L_41 ,
V_9 ) ;
if ( perror & F_28 )
F_7 ( L_42 ,
V_9 ) ;
if ( perror & F_27 )
F_7 ( L_43 , V_9 ) ;
if ( perror & F_26 )
F_7 ( L_44 , V_9 ) ;
if ( perror & F_25 )
F_7 ( L_45 , V_9 ) ;
F_7 ( L_46
L_47 ,
V_9 ,
V_19 , V_21 [ V_19 ] ,
V_20 ) ;
if ( perror & F_37 )
F_7 ( L_48 , V_9 ) ;
if ( perror & F_38 )
F_7 ( L_49 , V_9 ) ;
#endif
return V_5 ;
}
static int
F_43 ( int V_10 , T_1 V_25 , int V_2 )
{
int V_5 = V_6 ;
#ifdef F_2
int V_19 , V_26 ;
unsigned long V_20 ;
static const char * const V_27 [] = {
L_50 , L_51 ,
L_52 , L_53 ,
L_12 , L_12 ,
L_54 , L_55
} ;
#endif
#define F_44 (1UL << 0)
#define F_45 (1UL << 1)
#define F_46 (1UL << 2)
#define F_47 (1UL << 3)
#define F_48 (1UL << 4)
#define F_49 (1UL << 5)
#define F_50 (1UL << 6)
#define F_51 (TITAN__PCHIP_AGPERROR__LOST | \
TITAN__PCHIP_AGPERROR__LPQFULL | \
TITAN__PCHIP_AGPERROR__HPQFULL | \
TITAN__PCHIP_AGPERROR__RESCMD | \
TITAN__PCHIP_AGPERROR__IPTE | \
TITAN__PCHIP_AGPERROR__PTP | \
TITAN__PCHIP_AGPERROR__NOWINDOW)
#define F_52 (1UL << 48)
#define F_53 (1UL << 49)
#define F_54 (1UL << 59)
#define F_55 (50)
#define F_56 (0x07)
#define F_57 (15)
#define F_58 (0xffffffffUL)
#define F_59 (53)
#define F_60 (0x3f)
if ( ! ( V_25 & F_51 ) )
return V_7 ;
#ifdef F_2
if ( ! V_2 )
return V_5 ;
V_19 = F_6 ( V_25 , V_28 ) ;
V_20 = F_6 ( V_25 , V_29 ) << 3 ;
V_26 = F_6 ( V_25 , V_30 ) ;
F_7 ( L_56 , V_9 ,
V_10 , V_25 ) ;
if ( V_25 & F_50 )
F_7 ( L_57 , V_9 ) ;
if ( V_25 & F_49 )
F_7 ( L_58 , V_9 ) ;
if ( V_25 & F_48 )
F_7 ( L_59 , V_9 ) ;
if ( V_25 & F_47 )
F_7 ( L_60 , V_9 ) ;
if ( V_25 & F_46 )
F_7 ( L_61 ,
V_9 ) ;
if ( V_25 & F_45 )
F_7 ( L_62 ,
V_9 ) ;
if ( V_25 & F_44 )
F_7 ( L_45 , V_9 ) ;
F_7 ( L_63
L_47 ,
V_9 , V_19 , V_27 [ V_19 ] , V_26 ,
( V_25 & F_54 ) ? L_64 : L_65 ,
V_20 ) ;
if ( V_25 & F_52 )
F_7 ( L_48 , V_9 ) ;
if ( V_25 & F_53 )
F_7 ( L_49 , V_9 ) ;
#endif
return V_5 ;
}
static int
F_61 ( int V_10 , T_1 V_11 , T_1 V_31 ,
T_1 V_32 , T_1 V_25 , int V_2 )
{
int V_5 = V_7 ;
V_5 |= F_8 ( V_10 , V_11 , V_2 ) ;
V_5 |= F_24 ( V_10 , 0 , V_31 , V_2 ) ;
V_5 |= F_24 ( V_10 , 1 , V_32 , V_2 ) ;
V_5 |= F_43 ( V_10 , V_25 , V_2 ) ;
return V_5 ;
}
int
F_62 ( struct V_33 * V_34 , int V_2 )
{
struct V_35 * V_36 =
(struct V_35 * )
( ( unsigned long ) V_34 + V_34 -> V_37 ) ;
int V_5 = V_7 ;
V_5 |= F_1 ( V_36 -> V_1 , V_2 ) ;
V_5 |= F_61 ( 0 , V_36 -> V_38 , V_36 -> V_39 ,
V_36 -> V_40 , V_36 -> V_41 ,
V_2 ) ;
V_5 |= F_61 ( 1 , V_36 -> V_42 , V_36 -> V_43 ,
V_36 -> V_44 , V_36 -> V_45 ,
V_2 ) ;
return V_5 ;
}
void
F_63 ( unsigned long V_46 , unsigned long V_47 )
{
struct V_33 * V_34 = (struct V_33 * ) V_47 ;
struct V_35 * V_36 =
(struct V_35 * )
( ( unsigned long ) V_34 + V_34 -> V_37 ) ;
T_1 V_48 ;
#define F_64 0xF800000000000000UL
F_65 () ;
F_66 () ;
if ( ( V_46 != V_49 ) && ( V_46 != V_50 ) ) {
F_67 ( V_46 , V_47 ) ;
return;
}
if ( F_62 ( V_34 , 0 ) !=
V_24 ) {
char * V_51 = V_9 ;
V_9 = V_52 ;
F_7 ( L_66
L_67 ,
V_9 ,
( V_46 == V_50 ) ? L_68 : L_69 ,
( unsigned int ) V_46 , ( int ) F_68 () ) ;
#ifdef F_2
F_62 ( V_34 , V_53 ) ;
if ( V_53 )
F_69 ( F_70 () , NULL ) ;
#endif
V_9 = V_51 ;
V_48 = V_36 -> V_54 & F_64 ;
F_71 ( V_48 ) ;
}
F_72 ( 0x7 ) ;
F_65 () ;
}
static struct V_55 *
F_73 ( struct V_55 * V_56 )
{
if ( V_56 -> V_57 != V_58 ) {
F_7 ( L_70 ,
V_9 ,
V_56 -> V_57 , V_56 -> type ) ;
return NULL ;
}
switch( V_56 -> type ) {
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
F_7 ( L_71 ,
V_9 ,
( int ) V_56 -> V_64 . V_65 . V_66 ) ;
F_74 ( (struct V_33 * )
V_56 -> V_64 . V_65 . V_67 , 1 ) ;
break;
default:
F_7 ( L_72 ,
V_9 , V_56 -> type ) ;
F_75 ( V_56 ) ;
break;
}
return (struct V_55 * ) ( ( unsigned long ) V_56 + V_56 -> V_68 ) ;
}
void T_2
F_76 ( void )
{
T_3 V_69 ;
for ( V_69 = 0 ; V_69 < F_77 ( V_70 ) ; V_69 ++ )
F_78 ( & V_70 [ V_69 ] ) ;
F_79 ( & V_71 ) ;
F_80 () ;
}
static int
F_81 ( struct V_33 * V_34 , int V_2 )
{
int V_5 = V_7 ;
#ifdef F_2
struct V_72 * V_73 =
(struct V_72 * )
( ( unsigned long ) V_34 + V_34 -> V_37 ) ;
if ( ! V_2 )
return V_5 ;
F_7 ( L_73
L_74
L_75
L_76
L_77
L_78
L_79
L_80
L_81
L_82 ,
V_9 ,
V_73 -> V_74 ,
V_73 -> V_54 ,
V_73 -> V_75 ,
V_73 -> V_76 ,
V_73 -> V_77 ,
V_73 -> V_78 ,
V_73 -> V_79 ,
V_73 -> V_80 ,
V_73 -> V_81 ,
V_73 -> V_82 ) ;
#endif
return V_5 ;
}
int
F_74 ( struct V_33 * V_34 , int V_2 )
{
struct V_83 * V_84 =
(struct V_83 * ) V_34 ;
int V_5 = V_7 ;
#define F_82 0x86
#define F_83 0x9E
#define F_84 0x8E
#define F_85 0x90
#define F_86 0x98
#define F_87 0xA0
#define F_88 0xA2
#define F_89 0x202
#define F_90 0x204
#define F_91 0x206
switch( V_84 -> V_85 ) {
case F_82 :
case F_83 :
case F_84 :
case F_85 :
case F_86 :
case F_87 :
case F_88 :
V_5 |= F_92 ( V_34 , V_2 ) ;
break;
case F_90 :
case F_89 :
V_5 |= F_62 ( V_34 , V_2 ) ;
break;
case F_91 :
V_5 |= F_81 ( V_34 , V_2 ) ;
break;
default:
V_5 |= V_6 ;
if ( V_2 ) {
F_7 ( L_83 ,
V_9 ) ;
F_93 ( V_34 ) ;
}
}
return V_5 ;
}
void
F_94 ( unsigned long V_46 , unsigned long V_47 )
{
struct V_33 * V_34 = (struct V_33 * ) V_47 ;
struct V_35 * V_36 =
(struct V_35 * )
( V_47 + V_34 -> V_37 ) ;
T_1 V_48 ;
char * V_51 = V_9 ;
#define F_95 (0xE00UL)
#define F_96 (0xE00UL)
F_65 () ;
F_66 () ;
if ( V_46 != V_86 )
return F_63 ( V_46 , V_47 ) ;
V_9 = V_52 ;
F_7 ( L_84 ,
V_9 ,
( unsigned int ) V_46 , ( int ) F_68 () ) ;
F_81 ( V_34 , 1 ) ;
V_9 = V_51 ;
V_48 = V_36 -> V_54 & F_95 ;
F_71 ( V_48 ) ;
F_72 ( 0x7 ) ;
F_65 () ;
}
