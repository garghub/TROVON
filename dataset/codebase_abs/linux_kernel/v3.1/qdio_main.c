static inline int F_1 ( unsigned long V_1 ,
unsigned int V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
register unsigned long T_1 V_5 ( L_1 ) = V_4 ;
register unsigned long T_2 V_5 ( L_2 ) = V_1 ;
register unsigned long T_3 V_5 ( L_3 ) = V_2 ;
register unsigned long T_4 V_5 ( L_4 ) = V_3 ;
int V_6 ;
asm volatile(
" siga 0\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (cc)
: "d" (__fc), "d" (__schid), "d" (out), "d" (in) : "cc");
return V_6 ;
}
static inline int F_2 ( unsigned long V_1 , unsigned int V_7 ,
unsigned int V_4 )
{
register unsigned long T_1 V_5 ( L_1 ) = V_4 ;
register unsigned long T_2 V_5 ( L_2 ) = V_1 ;
register unsigned long T_5 V_5 ( L_3 ) = V_7 ;
int V_6 ;
asm volatile(
" siga 0\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (cc)
: "d" (__fc), "d" (__schid), "d" (__mask) : "cc", "memory");
return V_6 ;
}
static inline int F_3 ( unsigned long V_1 , unsigned long V_7 ,
unsigned int * V_8 , unsigned int V_4 )
{
register unsigned long T_1 V_5 ( L_1 ) = V_4 ;
register unsigned long T_2 V_5 ( L_2 ) = V_1 ;
register unsigned long T_5 V_5 ( L_3 ) = V_7 ;
int V_6 = V_9 ;
asm volatile(
" siga 0\n"
"0: ipm %0\n"
" srl %0,28\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+d" (cc), "+d" (__fc), "+d" (__schid), "+d" (__mask)
: : "cc", "memory");
* V_8 = ( ( unsigned int ) T_1 ) >> 31 ;
return V_6 ;
}
static inline int F_4 ( struct V_10 * V_11 , unsigned int V_12 )
{
if ( V_12 == 0 || V_12 == 32 )
return 0 ;
if ( V_12 == 96 || V_12 == 97 )
return 1 ;
F_5 ( L_5 , F_6 ( V_11 ) , V_12 ) ;
return - V_13 ;
}
static int F_7 ( struct V_10 * V_11 , unsigned char * V_14 ,
int V_15 , int V_16 , int V_17 )
{
unsigned int V_12 = 0 ;
int V_18 = V_16 , V_19 = V_15 ;
int V_20 = V_11 -> V_20 ;
int V_21 ;
F_8 ( ! V_11 -> V_22 -> V_23 ) ;
F_9 ( V_11 , V_24 ) ;
if ( ! V_11 -> V_25 )
V_20 += V_11 -> V_22 -> V_26 ;
V_27:
V_12 = F_10 ( V_11 -> V_22 -> V_23 , V_14 , V_20 , & V_19 , & V_18 ,
V_17 ) ;
V_21 = F_4 ( V_11 , V_12 ) ;
if ( ( V_12 == 96 ) && ( V_16 != V_18 ) ) {
F_9 ( V_11 , V_28 ) ;
return ( V_16 - V_18 ) ;
}
if ( V_21 == 1 ) {
F_11 ( V_29 , V_11 -> V_22 , L_6 , V_12 ) ;
goto V_27;
}
if ( V_21 < 0 ) {
F_5 ( L_7 , F_6 ( V_11 ) ) ;
F_5 ( L_8 , V_16 , V_18 , V_20 ) ;
V_11 -> V_30 ( V_11 -> V_22 -> V_31 ,
V_32 ,
0 , - 1 , - 1 , V_11 -> V_22 -> V_33 ) ;
return 0 ;
}
return V_16 - V_18 ;
}
static int F_12 ( struct V_10 * V_11 , unsigned char V_14 , int V_15 ,
int V_16 )
{
unsigned int V_12 = 0 ;
int V_18 = V_16 , V_19 = V_15 ;
int V_20 = V_11 -> V_20 ;
int V_21 ;
if ( ! V_16 )
return 0 ;
F_8 ( ! V_11 -> V_22 -> V_23 ) ;
F_9 ( V_11 , V_34 ) ;
if ( ! V_11 -> V_25 )
V_20 += V_11 -> V_22 -> V_26 ;
V_27:
V_12 = F_13 ( V_11 -> V_22 -> V_23 , V_14 , V_20 , & V_19 , & V_18 ) ;
V_21 = F_4 ( V_11 , V_12 ) ;
if ( V_21 == 1 ) {
F_11 ( V_35 , V_11 -> V_22 , L_9 , V_12 ) ;
F_9 ( V_11 , V_36 ) ;
goto V_27;
}
if ( V_21 < 0 ) {
F_5 ( L_10 , F_6 ( V_11 ) ) ;
F_5 ( L_8 , V_16 , V_18 , V_20 ) ;
V_11 -> V_30 ( V_11 -> V_22 -> V_31 ,
V_32 ,
0 , - 1 , - 1 , V_11 -> V_22 -> V_33 ) ;
return 0 ;
}
F_14 ( V_18 ) ;
return V_16 - V_18 ;
}
static inline int F_15 ( struct V_10 * V_11 , unsigned int V_37 ,
unsigned char * V_14 , unsigned int V_16 ,
int V_17 )
{
unsigned char V_38 = 0 ;
int V_39 ;
F_8 ( V_37 > V_40 ) ;
F_8 ( V_16 > V_41 ) ;
if ( F_16 ( V_11 ) )
return F_7 ( V_11 , V_14 , V_37 , V_16 , V_17 ) ;
for ( V_39 = 0 ; V_39 < V_16 ; V_39 ++ ) {
if ( ! V_38 )
V_38 = V_11 -> V_42 . V_43 [ V_37 ] ;
else if ( V_11 -> V_42 . V_43 [ V_37 ] != V_38 )
break;
V_37 = F_17 ( V_37 ) ;
}
* V_14 = V_38 ;
return V_39 ;
}
static inline int F_18 ( struct V_10 * V_11 , unsigned int V_37 ,
unsigned char * V_14 , int V_17 )
{
return F_15 ( V_11 , V_37 , V_14 , 1 , V_17 ) ;
}
static inline int F_19 ( struct V_10 * V_11 , int V_37 ,
unsigned char V_14 , int V_16 )
{
int V_39 ;
F_8 ( V_37 > V_40 ) ;
F_8 ( V_16 > V_41 ) ;
if ( F_16 ( V_11 ) )
return F_12 ( V_11 , V_14 , V_37 , V_16 ) ;
for ( V_39 = 0 ; V_39 < V_16 ; V_39 ++ ) {
F_20 ( & V_11 -> V_42 . V_43 [ V_37 ] , V_14 ) ;
V_37 = F_17 ( V_37 ) ;
}
return V_16 ;
}
static inline int F_21 ( struct V_10 * V_11 , int V_37 ,
unsigned char V_14 )
{
return F_19 ( V_11 , V_37 , V_14 , 1 ) ;
}
void F_22 ( struct V_44 * V_22 )
{
struct V_10 * V_11 ;
int V_39 ;
F_23 (irq_ptr, q, i)
F_19 ( V_11 , 0 , V_45 ,
V_41 ) ;
F_24 (irq_ptr, q, i)
F_19 ( V_11 , 0 , V_46 ,
V_41 ) ;
}
static inline int F_25 ( struct V_10 * V_11 , unsigned int V_47 ,
unsigned int V_48 )
{
unsigned long V_1 = * ( ( V_49 * ) & V_11 -> V_22 -> V_1 ) ;
unsigned int V_4 = V_50 ;
int V_6 ;
F_11 ( V_35 , V_11 -> V_22 , L_11 , V_11 -> V_20 ) ;
F_9 ( V_11 , V_51 ) ;
if ( F_16 ( V_11 ) ) {
V_1 = V_11 -> V_22 -> V_23 ;
V_4 |= V_52 ;
}
V_6 = F_1 ( V_1 , V_47 , V_48 , V_4 ) ;
if ( F_26 ( V_6 ) )
F_5 ( L_12 , F_6 ( V_11 ) , V_6 ) ;
return V_6 ;
}
static inline int F_27 ( struct V_10 * V_11 )
{
if ( V_11 -> V_25 )
return F_25 ( V_11 , 0 , V_11 -> V_7 ) ;
else
return F_25 ( V_11 , V_11 -> V_7 , 0 ) ;
}
static int F_28 ( struct V_10 * V_11 , unsigned int * V_53 )
{
unsigned long V_1 = * ( ( V_49 * ) & V_11 -> V_22 -> V_1 ) ;
unsigned int V_4 = V_54 ;
T_6 V_55 = 0 ;
int V_56 = 0 , V_6 ;
if ( F_16 ( V_11 ) ) {
V_1 = V_11 -> V_22 -> V_23 ;
V_4 |= V_52 ;
}
V_27:
V_6 = F_3 ( V_1 , V_11 -> V_7 , V_53 , V_4 ) ;
if ( F_26 ( * V_53 ) ) {
F_14 ( F_29 ( V_11 ) != V_57 || V_6 != 2 ) ;
V_56 ++ ;
if ( ! V_55 ) {
V_55 = F_30 () ;
goto V_27;
}
if ( ( F_30 () - V_55 ) < V_58 )
goto V_27;
}
if ( V_56 ) {
F_11 ( V_29 , V_11 -> V_22 ,
L_13 , F_6 ( V_11 ) , V_11 -> V_20 ) ;
F_11 ( V_29 , V_11 -> V_22 , L_14 , V_56 ) ;
}
return V_6 ;
}
static inline int F_31 ( struct V_10 * V_11 )
{
unsigned long V_1 = * ( ( V_49 * ) & V_11 -> V_22 -> V_1 ) ;
unsigned int V_4 = V_59 ;
int V_6 ;
F_11 ( V_35 , V_11 -> V_22 , L_15 , V_11 -> V_20 ) ;
F_9 ( V_11 , V_60 ) ;
if ( F_16 ( V_11 ) ) {
V_1 = V_11 -> V_22 -> V_23 ;
V_4 |= V_52 ;
}
V_6 = F_2 ( V_1 , V_11 -> V_7 , V_4 ) ;
if ( F_26 ( V_6 ) )
F_5 ( L_16 , F_6 ( V_11 ) , V_6 ) ;
return V_6 ;
}
static inline void F_32 ( struct V_10 * V_11 )
{
if ( F_33 ( V_11 ) )
F_34 ( V_11 ) ;
else
F_27 ( V_11 ) ;
}
int F_35 ( struct V_10 * V_11 , unsigned int V_37 ,
unsigned char * V_14 )
{
if ( F_36 ( V_11 ) )
F_27 ( V_11 ) ;
return F_15 ( V_11 , V_37 , V_14 , 1 , 0 ) ;
}
static inline void F_37 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_61 . T_4 . V_62 )
return;
V_11 -> V_61 . T_4 . V_62 = 0 ;
F_9 ( V_11 , V_63 ) ;
if ( F_16 ( V_11 ) ) {
F_19 ( V_11 , V_11 -> V_61 . T_4 . V_64 , V_45 ,
V_11 -> V_61 . T_4 . V_65 ) ;
V_11 -> V_61 . T_4 . V_65 = 0 ;
} else
F_21 ( V_11 , V_11 -> V_61 . T_4 . V_64 , V_45 ) ;
}
static inline void F_38 ( struct V_10 * V_11 , int V_16 )
{
int V_66 = 0 ;
V_11 -> V_67 . V_68 += V_16 ;
if ( V_16 == V_40 ) {
V_11 -> V_67 . V_69 [ 7 ] ++ ;
return;
}
while ( V_16 >>= 1 )
V_66 ++ ;
V_11 -> V_67 . V_69 [ V_66 ] ++ ;
}
static void F_39 ( struct V_10 * V_11 , int V_16 )
{
unsigned char V_14 = ( V_11 -> V_25 ) ? V_45 :
V_46 ;
V_11 -> V_70 |= V_71 ;
if ( ( ! V_11 -> V_25 &&
( V_11 -> V_72 [ V_11 -> V_73 ] -> V_74 [ 15 ] . V_75 ) == 0x10 ) ) {
F_9 ( V_11 , V_76 ) ;
F_11 ( V_35 , V_11 -> V_22 , L_17 ,
V_11 -> V_73 ) ;
return;
}
F_5 ( L_18 , F_6 ( V_11 ) ) ;
F_5 ( ( V_11 -> V_25 ) ? L_19 : L_20 , V_11 -> V_20 ) ;
F_5 ( L_21 , V_11 -> V_73 , V_16 ) ;
F_5 ( L_22 ,
V_11 -> V_72 [ V_11 -> V_73 ] -> V_74 [ 14 ] . V_75 ,
V_11 -> V_72 [ V_11 -> V_73 ] -> V_74 [ 15 ] . V_75 ) ;
F_19 ( V_11 , V_11 -> V_73 , V_14 , V_16 ) ;
}
static inline void F_40 ( struct V_10 * V_11 , int V_16 )
{
int V_77 ;
F_11 ( V_35 , V_11 -> V_22 , L_23 , V_16 ) ;
if ( F_16 ( V_11 ) ) {
if ( ! V_11 -> V_61 . T_4 . V_62 ) {
V_11 -> V_61 . T_4 . V_62 = 1 ;
V_11 -> V_61 . T_4 . V_65 = V_16 ;
V_11 -> V_61 . T_4 . V_64 = V_11 -> V_73 ;
return;
}
F_19 ( V_11 , V_11 -> V_61 . T_4 . V_64 , V_45 ,
V_11 -> V_61 . T_4 . V_65 ) ;
V_11 -> V_61 . T_4 . V_65 = V_16 ;
V_11 -> V_61 . T_4 . V_64 = V_11 -> V_73 ;
return;
}
V_77 = F_41 ( V_11 -> V_73 , V_16 - 1 ) ;
if ( V_11 -> V_61 . T_4 . V_62 ) {
F_21 ( V_11 , V_77 , V_78 ) ;
F_21 ( V_11 , V_11 -> V_61 . T_4 . V_64 , V_45 ) ;
} else {
V_11 -> V_61 . T_4 . V_62 = 1 ;
F_21 ( V_11 , V_77 , V_78 ) ;
}
V_11 -> V_61 . T_4 . V_64 = V_77 ;
V_16 -- ;
if ( ! V_16 )
return;
F_19 ( V_11 , V_11 -> V_73 , V_45 , V_16 ) ;
}
static int F_42 ( struct V_10 * V_11 )
{
int V_16 , V_79 ;
unsigned char V_14 = 0 ;
V_16 = F_43 ( F_44 ( & V_11 -> V_80 ) , V_40 ) ;
V_79 = F_41 ( V_11 -> V_73 , V_16 ) ;
if ( V_11 -> V_73 == V_79 )
goto T_3;
V_16 = F_15 ( V_11 , V_11 -> V_73 , & V_14 , V_16 , 1 ) ;
if ( ! V_16 )
goto T_3;
switch ( V_14 ) {
case V_81 :
F_40 ( V_11 , V_16 ) ;
V_11 -> V_73 = F_41 ( V_11 -> V_73 , V_16 ) ;
if ( F_45 ( V_16 , & V_11 -> V_80 ) == 0 )
F_9 ( V_11 , V_82 ) ;
if ( V_11 -> V_22 -> V_83 )
F_38 ( V_11 , V_16 ) ;
break;
case V_84 :
F_39 ( V_11 , V_16 ) ;
V_11 -> V_73 = F_41 ( V_11 -> V_73 , V_16 ) ;
F_45 ( V_16 , & V_11 -> V_80 ) ;
if ( V_11 -> V_22 -> V_83 )
F_46 ( V_11 , V_16 ) ;
break;
case V_85 :
case V_45 :
case V_78 :
if ( V_11 -> V_22 -> V_83 )
V_11 -> V_67 . V_86 ++ ;
F_11 ( V_35 , V_11 -> V_22 , L_24 ) ;
break;
default:
F_47 () ;
}
T_3:
return V_11 -> V_73 ;
}
static int F_48 ( struct V_10 * V_11 )
{
int V_37 ;
V_37 = F_42 ( V_11 ) ;
if ( ( V_37 != V_11 -> V_87 ) || V_11 -> V_70 ) {
V_11 -> V_87 = V_37 ;
if ( ! F_49 ( V_11 -> V_22 ) && V_88 )
V_11 -> V_61 . T_4 . V_89 = F_30 () ;
return 1 ;
} else
return 0 ;
}
static inline int F_50 ( struct V_10 * V_11 )
{
unsigned char V_14 = 0 ;
if ( ! F_44 ( & V_11 -> V_80 ) )
return 1 ;
if ( F_36 ( V_11 ) )
F_27 ( V_11 ) ;
F_18 ( V_11 , V_11 -> V_73 , & V_14 , 0 ) ;
if ( V_14 == V_81 || V_14 == V_84 )
return 0 ;
if ( F_49 ( V_11 -> V_22 ) )
return 1 ;
if ( V_90 )
return 1 ;
if ( F_30 () > V_11 -> V_61 . T_4 . V_89 + V_91 ) {
F_11 ( V_35 , V_11 -> V_22 , L_25 ,
V_11 -> V_73 ) ;
return 1 ;
} else
return 0 ;
}
static void F_51 ( struct V_10 * V_11 )
{
int V_15 = V_11 -> V_92 ;
int V_93 = V_11 -> V_73 ;
int V_16 ;
if ( F_26 ( V_11 -> V_22 -> V_14 != V_94 ) )
return;
V_16 = F_52 ( V_93 , V_15 ) ;
if ( V_11 -> V_25 ) {
F_9 ( V_11 , V_95 ) ;
F_11 ( V_35 , V_11 -> V_22 , L_26 , V_15 , V_16 ) ;
} else {
F_9 ( V_11 , V_96 ) ;
F_11 ( V_35 , V_11 -> V_22 , L_27 ,
V_15 , V_16 ) ;
}
V_11 -> V_30 ( V_11 -> V_22 -> V_31 , V_11 -> V_70 , V_11 -> V_20 , V_15 , V_16 ,
V_11 -> V_22 -> V_33 ) ;
V_11 -> V_92 = V_93 ;
V_11 -> V_70 = 0 ;
}
static void F_53 ( struct V_10 * V_11 )
{
F_9 ( V_11 , V_97 ) ;
if ( ! F_48 ( V_11 ) )
return;
F_51 ( V_11 ) ;
if ( ! F_50 ( V_11 ) ) {
F_9 ( V_11 , V_98 ) ;
if ( F_54 ( V_11 -> V_22 -> V_14 != V_99 ) ) {
F_55 ( & V_11 -> V_100 ) ;
return;
}
}
F_37 ( V_11 ) ;
if ( ! F_50 ( V_11 ) ) {
F_9 ( V_11 , V_101 ) ;
if ( F_54 ( V_11 -> V_22 -> V_14 != V_99 ) )
F_55 ( & V_11 -> V_100 ) ;
}
}
void F_56 ( unsigned long V_102 )
{
struct V_10 * V_11 = (struct V_10 * ) V_102 ;
F_53 ( V_11 ) ;
}
static int F_57 ( struct V_10 * V_11 )
{
int V_16 , V_79 ;
unsigned char V_14 = 0 ;
if ( F_36 ( V_11 ) )
if ( ( ( F_29 ( V_11 ) != V_57 ) &&
! F_33 ( V_11 ) ) ||
( F_29 ( V_11 ) == V_57 &&
F_58 ( V_11 ) ) )
F_27 ( V_11 ) ;
V_16 = F_43 ( F_44 ( & V_11 -> V_80 ) , V_40 ) ;
V_79 = F_41 ( V_11 -> V_73 , V_16 ) ;
if ( V_11 -> V_73 == V_79 )
return V_11 -> V_73 ;
V_16 = F_15 ( V_11 , V_11 -> V_73 , & V_14 , V_16 , 0 ) ;
if ( ! V_16 )
return V_11 -> V_73 ;
switch ( V_14 ) {
case V_103 :
F_11 ( V_35 , V_11 -> V_22 , L_28 , V_11 -> V_20 , V_16 ) ;
F_45 ( V_16 , & V_11 -> V_80 ) ;
V_11 -> V_73 = F_41 ( V_11 -> V_73 , V_16 ) ;
if ( V_11 -> V_22 -> V_83 )
F_38 ( V_11 , V_16 ) ;
break;
case V_104 :
F_39 ( V_11 , V_16 ) ;
V_11 -> V_73 = F_41 ( V_11 -> V_73 , V_16 ) ;
F_45 ( V_16 , & V_11 -> V_80 ) ;
if ( V_11 -> V_22 -> V_83 )
F_46 ( V_11 , V_16 ) ;
break;
case V_105 :
if ( V_11 -> V_22 -> V_83 )
V_11 -> V_67 . V_86 ++ ;
F_11 ( V_35 , V_11 -> V_22 , L_29 , V_11 -> V_20 ) ;
break;
case V_46 :
case V_106 :
break;
default:
F_47 () ;
}
return V_11 -> V_73 ;
}
static inline int F_59 ( struct V_10 * V_11 )
{
return F_44 ( & V_11 -> V_80 ) == 0 ;
}
static inline int F_60 ( struct V_10 * V_11 )
{
int V_37 ;
V_37 = F_57 ( V_11 ) ;
if ( ( V_37 != V_11 -> V_87 ) || V_11 -> V_70 ) {
V_11 -> V_87 = V_37 ;
F_11 ( V_35 , V_11 -> V_22 , L_30 , V_11 -> V_20 ) ;
return 1 ;
} else
return 0 ;
}
static int F_61 ( struct V_10 * V_11 )
{
int V_56 = 0 , V_6 ;
unsigned int V_53 ;
if ( ! F_62 ( V_11 ) )
return 0 ;
F_11 ( V_35 , V_11 -> V_22 , L_31 , V_11 -> V_20 ) ;
V_107:
F_9 ( V_11 , V_108 ) ;
V_6 = F_28 ( V_11 , & V_53 ) ;
switch ( V_6 ) {
case 0 :
break;
case 2 :
if ( V_53 ) {
while ( ++ V_56 < V_109 ) {
F_63 ( V_110 ) ;
goto V_107;
}
F_5 ( L_32 , F_6 ( V_11 ) , V_11 -> V_20 ) ;
V_6 |= V_111 ;
} else
F_11 ( V_35 , V_11 -> V_22 , L_33 , V_11 -> V_20 ) ;
break;
case 1 :
case 3 :
F_5 ( L_34 , F_6 ( V_11 ) , V_6 ) ;
break;
}
if ( V_56 ) {
F_5 ( L_35 , F_6 ( V_11 ) , V_11 -> V_20 ) ;
F_5 ( L_14 , V_56 ) ;
}
return V_6 ;
}
static void F_64 ( struct V_10 * V_11 )
{
F_9 ( V_11 , V_112 ) ;
F_8 ( F_44 ( & V_11 -> V_80 ) < 0 ) ;
if ( F_60 ( V_11 ) )
F_51 ( V_11 ) ;
if ( F_29 ( V_11 ) == V_113 )
if ( ! F_33 ( V_11 ) && ! F_59 ( V_11 ) )
goto V_114;
if ( F_29 ( V_11 ) == V_57 && ! F_58 ( V_11 ) )
return;
if ( ( F_29 ( V_11 ) == V_57 ) &&
( F_44 ( & V_11 -> V_80 ) ) > V_115 )
goto V_114;
if ( V_11 -> V_61 . T_3 . V_116 )
return;
if ( F_59 ( V_11 ) )
F_65 ( & V_11 -> V_61 . T_3 . V_117 ) ;
else
if ( ! F_66 ( & V_11 -> V_61 . T_3 . V_117 ) )
F_67 ( & V_11 -> V_61 . T_3 . V_117 , V_118 + 10 * V_119 ) ;
return;
V_114:
if ( F_26 ( V_11 -> V_22 -> V_14 == V_99 ) )
return;
F_55 ( & V_11 -> V_100 ) ;
}
void F_68 ( unsigned long V_102 )
{
struct V_10 * V_11 = (struct V_10 * ) V_102 ;
F_64 ( V_11 ) ;
}
void F_69 ( unsigned long V_102 )
{
struct V_10 * V_11 = (struct V_10 * ) V_102 ;
if ( F_26 ( V_11 -> V_22 -> V_14 == V_99 ) )
return;
F_55 ( & V_11 -> V_100 ) ;
}
static inline void F_70 ( struct V_10 * V_11 )
{
struct V_10 * T_3 ;
int V_39 ;
if ( ! F_33 ( V_11 ) )
return;
F_24 (q->irq_ptr, out, i)
if ( ! F_59 ( T_3 ) )
F_55 ( & T_3 -> V_100 ) ;
}
static void F_71 ( struct V_10 * V_11 )
{
F_9 ( V_11 , V_97 ) ;
if ( F_36 ( V_11 ) && F_72 ( V_11 ) )
F_32 ( V_11 ) ;
F_70 ( V_11 ) ;
if ( ! F_48 ( V_11 ) )
return;
F_51 ( V_11 ) ;
if ( ! F_50 ( V_11 ) ) {
F_9 ( V_11 , V_98 ) ;
if ( F_54 ( V_11 -> V_22 -> V_14 != V_99 ) ) {
F_55 ( & V_11 -> V_100 ) ;
return;
}
}
F_37 ( V_11 ) ;
if ( ! F_50 ( V_11 ) ) {
F_9 ( V_11 , V_101 ) ;
if ( F_54 ( V_11 -> V_22 -> V_14 != V_99 ) )
F_55 ( & V_11 -> V_100 ) ;
}
}
void F_73 ( unsigned long V_102 )
{
struct V_10 * V_11 = (struct V_10 * ) V_102 ;
F_71 ( V_11 ) ;
}
static inline void F_74 ( struct V_44 * V_22 ,
enum V_120 V_14 )
{
F_11 ( V_35 , V_22 , L_36 , V_14 ) ;
V_22 -> V_14 = V_14 ;
F_75 () ;
}
static void F_76 ( struct V_44 * V_22 , struct V_121 * V_121 )
{
if ( V_121 -> V_122 . V_123 . V_124 . V_125 ) {
F_5 ( L_37 , V_22 -> V_1 . V_126 ) ;
F_77 ( V_121 , 64 ) ;
F_77 ( V_121 -> V_127 , 64 ) ;
}
}
static void F_78 ( struct V_44 * V_22 )
{
int V_39 ;
struct V_10 * V_11 ;
if ( F_26 ( V_22 -> V_14 == V_99 ) )
return;
F_23 (irq_ptr, q, i) {
if ( V_11 -> V_61 . T_4 . V_128 ) {
if ( F_79 ( V_129 ,
& V_11 -> V_61 . T_4 . V_130 ) ) {
F_9 ( V_11 , V_131 ) ;
continue;
}
V_11 -> V_61 . T_4 . V_128 ( V_11 -> V_22 -> V_31 , V_11 -> V_20 ,
V_11 -> V_22 -> V_33 ) ;
} else
F_55 ( & V_11 -> V_100 ) ;
}
if ( ! F_33 ( V_11 ) )
return;
F_24 (irq_ptr, q, i) {
if ( F_59 ( V_11 ) )
continue;
if ( F_36 ( V_11 ) && F_80 ( V_11 ) )
F_27 ( V_11 ) ;
F_55 ( & V_11 -> V_100 ) ;
}
}
static void F_81 ( struct V_132 * V_31 ,
unsigned long V_133 , int V_134 , int V_135 )
{
struct V_44 * V_22 = V_31 -> V_136 -> V_137 ;
struct V_10 * V_11 ;
F_5 ( L_38 , V_22 -> V_1 . V_126 ) ;
F_5 ( L_39 , V_133 ) ;
F_5 ( L_40 , V_135 , V_134 ) ;
if ( V_22 -> V_26 ) {
V_11 = V_22 -> V_138 [ 0 ] ;
} else if ( V_22 -> V_139 ) {
V_11 = V_22 -> V_140 [ 0 ] ;
} else {
F_82 () ;
goto V_141;
}
V_11 -> V_30 ( V_11 -> V_22 -> V_31 , V_32 ,
0 , - 1 , - 1 , V_22 -> V_33 ) ;
V_141:
F_74 ( V_22 , V_99 ) ;
}
static void F_83 ( struct V_132 * V_31 , int V_134 ,
int V_135 )
{
struct V_44 * V_22 = V_31 -> V_136 -> V_137 ;
F_11 ( V_35 , V_22 , L_41 ) ;
if ( V_134 )
goto error;
if ( V_135 & ~ ( V_142 | V_143 ) )
goto error;
if ( ! ( V_135 & V_142 ) )
goto error;
F_74 ( V_22 , V_144 ) ;
return;
error:
F_5 ( L_42 , V_22 -> V_1 . V_126 ) ;
F_5 ( L_40 , V_135 , V_134 ) ;
F_74 ( V_22 , V_145 ) ;
}
void F_84 ( struct V_132 * V_31 , unsigned long V_133 ,
struct V_121 * V_121 )
{
struct V_44 * V_22 = V_31 -> V_136 -> V_137 ;
int V_134 , V_135 ;
if ( ! V_133 || ! V_22 ) {
F_5 ( L_43 , V_31 -> V_136 -> V_1 . V_126 ) ;
return;
}
F_85 ( F_86 () ) . V_146 [ V_147 ] ++ ;
if ( V_22 -> V_83 )
V_22 -> V_148 . V_149 ++ ;
if ( F_87 ( V_121 ) ) {
switch ( F_88 ( V_121 ) ) {
case - V_13 :
F_5 ( L_44 , V_22 -> V_1 . V_126 ) ;
F_74 ( V_22 , V_145 ) ;
F_89 ( & V_31 -> V_136 -> V_150 ) ;
return;
default:
F_14 ( 1 ) ;
return;
}
}
F_76 ( V_22 , V_121 ) ;
V_134 = V_121 -> V_151 . V_152 . V_134 ;
V_135 = V_121 -> V_151 . V_152 . V_135 ;
switch ( V_22 -> V_14 ) {
case V_153 :
F_83 ( V_31 , V_134 , V_135 ) ;
break;
case V_154 :
F_74 ( V_22 , V_153 ) ;
break;
case V_144 :
case V_94 :
if ( V_134 & V_155 ) {
F_78 ( V_22 ) ;
return;
}
if ( V_134 || V_135 )
F_81 ( V_31 , V_133 , V_134 ,
V_135 ) ;
break;
case V_99 :
break;
default:
F_14 ( 1 ) ;
}
F_89 ( & V_31 -> V_136 -> V_150 ) ;
}
int F_90 ( struct V_132 * V_31 ,
struct V_156 * V_102 )
{
if ( ! V_31 || ! V_31 -> V_136 )
return - V_157 ;
F_91 ( L_45 , V_31 -> V_136 -> V_1 . V_126 ) ;
return F_92 ( NULL , & V_31 -> V_136 -> V_1 , V_102 ) ;
}
static void F_93 ( struct V_132 * V_31 )
{
struct V_44 * V_22 = V_31 -> V_136 -> V_137 ;
struct V_10 * V_11 ;
int V_39 ;
F_23 (irq_ptr, q, i)
F_94 ( & V_11 -> V_100 ) ;
F_24 (irq_ptr, q, i) {
F_65 ( & V_11 -> V_61 . T_3 . V_117 ) ;
F_94 ( & V_11 -> V_100 ) ;
}
}
int F_95 ( struct V_132 * V_31 , int V_158 )
{
struct V_44 * V_22 = V_31 -> V_136 -> V_137 ;
int V_21 ;
unsigned long V_159 ;
if ( ! V_22 )
return - V_160 ;
F_8 ( F_96 () ) ;
F_91 ( L_46 , V_31 -> V_136 -> V_1 . V_126 ) ;
F_97 ( & V_22 -> V_161 ) ;
if ( V_22 -> V_14 == V_153 ) {
F_98 ( & V_22 -> V_161 ) ;
return 0 ;
}
F_74 ( V_22 , V_99 ) ;
F_99 ( V_22 ) ;
F_93 ( V_31 ) ;
F_100 ( V_22 , V_31 ) ;
F_101 ( F_102 ( V_31 ) , V_159 ) ;
if ( V_158 & V_162 )
V_21 = F_103 ( V_31 , V_163 ) ;
else
V_21 = F_104 ( V_31 , V_163 ) ;
if ( V_21 ) {
F_5 ( L_47 , V_22 -> V_1 . V_126 ) ;
F_5 ( L_48 , V_21 ) ;
goto V_164;
}
F_74 ( V_22 , V_154 ) ;
F_105 ( F_102 ( V_31 ) , V_159 ) ;
F_106 ( V_31 -> V_136 -> V_150 ,
V_22 -> V_14 == V_153 ||
V_22 -> V_14 == V_145 ,
10 * V_119 ) ;
F_101 ( F_102 ( V_31 ) , V_159 ) ;
V_164:
F_107 ( V_22 ) ;
if ( ( void * ) V_31 -> V_30 == ( void * ) F_84 )
V_31 -> V_30 = V_22 -> V_165 ;
F_105 ( F_102 ( V_31 ) , V_159 ) ;
F_74 ( V_22 , V_153 ) ;
F_98 ( & V_22 -> V_161 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
int F_108 ( struct V_132 * V_31 )
{
struct V_44 * V_22 = V_31 -> V_136 -> V_137 ;
if ( ! V_22 )
return - V_160 ;
F_91 ( L_49 , V_31 -> V_136 -> V_1 . V_126 ) ;
F_97 ( & V_22 -> V_161 ) ;
if ( V_22 -> V_166 != NULL ) {
F_109 ( V_22 -> V_166 ) ;
V_22 -> V_166 = NULL ;
}
V_31 -> V_136 -> V_137 = NULL ;
F_98 ( & V_22 -> V_161 ) ;
F_110 ( V_22 ) ;
return 0 ;
}
int F_111 ( struct V_167 * V_168 )
{
struct V_44 * V_22 ;
F_91 ( L_50 , V_168 -> V_31 -> V_136 -> V_1 . V_126 ) ;
if ( ( V_168 -> V_169 && ! V_168 -> V_170 ) ||
( V_168 -> V_171 && ! V_168 -> V_172 ) )
return - V_157 ;
if ( ( V_168 -> V_169 > V_173 ) ||
( V_168 -> V_171 > V_173 ) )
return - V_157 ;
if ( ( ! V_168 -> V_174 ) ||
( ! V_168 -> V_175 ) )
return - V_157 ;
V_22 = ( void * ) F_112 ( V_176 | V_177 ) ;
if ( ! V_22 )
goto V_178;
F_113 ( & V_22 -> V_161 ) ;
F_114 ( V_168 , V_22 ) ;
V_22 -> V_179 = F_112 ( V_176 ) ;
if ( ! V_22 -> V_179 )
goto V_180;
V_22 -> V_181 = (struct V_181 * ) F_112 ( V_176 | V_177 ) ;
if ( ! V_22 -> V_181 )
goto V_180;
F_14 ( ( unsigned long ) V_22 -> V_181 & 0xfff ) ;
if ( F_115 ( V_22 , V_168 -> V_169 ,
V_168 -> V_171 ) )
goto V_180;
V_168 -> V_31 -> V_136 -> V_137 = V_22 ;
F_74 ( V_22 , V_153 ) ;
return 0 ;
V_180:
F_110 ( V_22 ) ;
V_178:
return - V_182 ;
}
int F_116 ( struct V_167 * V_168 )
{
struct V_44 * V_22 ;
struct V_132 * V_31 = V_168 -> V_31 ;
unsigned long V_183 ;
int V_21 ;
F_91 ( L_51 , V_31 -> V_136 -> V_1 . V_126 ) ;
V_22 = V_31 -> V_136 -> V_137 ;
if ( ! V_22 )
return - V_160 ;
if ( V_31 -> V_136 -> V_14 != V_184 )
return - V_157 ;
F_97 ( & V_22 -> V_161 ) ;
F_117 ( V_168 ) ;
V_21 = F_118 ( V_22 ) ;
if ( V_21 ) {
F_98 ( & V_22 -> V_161 ) ;
F_95 ( V_31 , V_162 ) ;
return V_21 ;
}
V_22 -> V_185 . V_186 = V_22 -> V_187 . V_152 ;
V_22 -> V_185 . V_159 = V_188 ;
V_22 -> V_185 . V_16 = V_22 -> V_187 . V_16 ;
V_22 -> V_185 . V_189 = ( V_49 ) ( ( V_190 ) V_22 -> V_181 ) ;
F_101 ( F_102 ( V_31 ) , V_183 ) ;
F_119 ( V_31 , 0 ) ;
V_21 = F_120 ( V_31 , & V_22 -> V_185 , V_191 , 0 , 0 ) ;
if ( V_21 ) {
F_5 ( L_52 , V_22 -> V_1 . V_126 ) ;
F_5 ( L_53 , V_21 ) ;
}
F_105 ( F_102 ( V_31 ) , V_183 ) ;
if ( V_21 ) {
F_98 ( & V_22 -> V_161 ) ;
F_95 ( V_31 , V_162 ) ;
return V_21 ;
}
F_106 ( V_31 -> V_136 -> V_150 ,
V_22 -> V_14 == V_144 ||
V_22 -> V_14 == V_145 , V_119 ) ;
if ( V_22 -> V_14 != V_144 ) {
F_98 ( & V_22 -> V_161 ) ;
F_95 ( V_31 , V_162 ) ;
return - V_13 ;
}
F_121 ( V_22 ) ;
F_91 ( L_54 , V_22 -> V_192 . V_193 ) ;
F_22 ( V_22 ) ;
F_98 ( & V_22 -> V_161 ) ;
F_122 ( V_22 , V_31 ) ;
F_123 ( V_22 , V_31 ) ;
return 0 ;
}
int F_124 ( struct V_132 * V_31 )
{
struct V_44 * V_22 ;
int V_21 ;
unsigned long V_183 ;
F_91 ( L_55 , V_31 -> V_136 -> V_1 . V_126 ) ;
V_22 = V_31 -> V_136 -> V_137 ;
if ( ! V_22 )
return - V_160 ;
if ( V_31 -> V_136 -> V_14 != V_184 )
return - V_157 ;
F_97 ( & V_22 -> V_161 ) ;
if ( V_22 -> V_14 == V_153 ) {
V_21 = - V_194 ;
goto T_3;
}
V_22 -> V_185 . V_186 = V_22 -> V_195 . V_152 ;
V_22 -> V_185 . V_159 = V_188 ;
V_22 -> V_185 . V_16 = V_22 -> V_195 . V_16 ;
V_22 -> V_185 . V_189 = 0 ;
F_101 ( F_102 ( V_31 ) , V_183 ) ;
F_125 ( V_31 , V_196 ) ;
V_21 = F_120 ( V_31 , & V_22 -> V_185 , V_197 ,
0 , V_198 ) ;
if ( V_21 ) {
F_5 ( L_56 , V_22 -> V_1 . V_126 ) ;
F_5 ( L_53 , V_21 ) ;
}
F_105 ( F_102 ( V_31 ) , V_183 ) ;
if ( V_21 )
goto T_3;
if ( F_49 ( V_22 ) )
F_126 ( V_22 ) ;
F_127 ( 5 ) ;
switch ( V_22 -> V_14 ) {
case V_99 :
case V_145 :
V_21 = - V_13 ;
break;
default:
F_74 ( V_22 , V_94 ) ;
V_21 = 0 ;
}
T_3:
F_98 ( & V_22 -> V_161 ) ;
return V_21 ;
}
static inline int F_128 ( int V_37 , int V_15 , int V_16 )
{
int V_93 = F_41 ( V_15 , V_16 ) ;
if ( V_93 > V_15 ) {
if ( V_37 >= V_15 && V_37 < V_93 )
return 1 ;
else
return 0 ;
}
if ( ( V_37 >= V_15 && V_37 <= V_41 ) ||
( V_37 < V_93 ) )
return 1 ;
else
return 0 ;
}
static int F_129 ( struct V_10 * V_11 , unsigned int V_199 ,
int V_37 , int V_16 )
{
int V_200 , V_201 ;
F_9 ( V_11 , V_202 ) ;
if ( ! V_11 -> V_61 . T_4 . V_62 )
goto V_203;
if ( V_16 == V_41 ) {
V_11 -> V_61 . T_4 . V_62 = 0 ;
V_11 -> V_61 . T_4 . V_65 = 0 ;
goto V_203;
} else if ( F_128 ( V_11 -> V_61 . T_4 . V_64 , V_37 , V_16 ) ) {
if ( F_16 ( V_11 ) ) {
V_201 = F_41 ( V_37 , V_16 ) ;
V_201 = F_52 ( V_201 , V_11 -> V_61 . T_4 . V_64 ) ;
V_11 -> V_61 . T_4 . V_65 -= V_201 ;
if ( V_11 -> V_61 . T_4 . V_65 <= 0 ) {
V_11 -> V_61 . T_4 . V_62 = 0 ;
V_11 -> V_61 . T_4 . V_65 = 0 ;
goto V_203;
}
V_11 -> V_61 . T_4 . V_64 = F_41 ( V_11 -> V_61 . T_4 . V_64 , V_201 ) ;
}
else
V_11 -> V_61 . T_4 . V_62 = 0 ;
}
V_203:
V_16 = F_19 ( V_11 , V_37 , V_85 , V_16 ) ;
V_200 = F_130 ( V_16 , & V_11 -> V_80 ) - V_16 ;
F_8 ( V_200 + V_16 > V_41 ) ;
if ( V_200 )
return 0 ;
if ( F_131 ( V_11 ) )
return F_31 ( V_11 ) ;
return 0 ;
}
static int F_132 ( struct V_10 * V_11 , unsigned int V_199 ,
int V_37 , int V_16 )
{
unsigned char V_14 = 0 ;
int V_200 , V_21 = 0 ;
F_9 ( V_11 , V_204 ) ;
V_16 = F_19 ( V_11 , V_37 , V_105 , V_16 ) ;
V_200 = F_130 ( V_16 , & V_11 -> V_80 ) ;
F_8 ( V_200 > V_41 ) ;
if ( V_200 == V_41 )
F_9 ( V_11 , V_205 ) ;
if ( V_199 & V_206 ) {
V_11 -> V_61 . T_3 . V_116 = 1 ;
F_9 ( V_11 , V_207 ) ;
} else
V_11 -> V_61 . T_3 . V_116 = 0 ;
if ( F_29 ( V_11 ) == V_57 ) {
F_133 ( V_16 > 1 && ! F_58 ( V_11 ) ) ;
V_21 = F_61 ( V_11 ) ;
} else if ( F_36 ( V_11 ) ) {
V_21 = F_27 ( V_11 ) ;
} else {
F_18 ( V_11 , F_134 ( V_37 ) , & V_14 , 0 ) ;
if ( V_14 != V_105 )
V_21 = F_61 ( V_11 ) ;
else
F_9 ( V_11 , V_208 ) ;
}
if ( V_200 >= V_11 -> V_61 . T_3 . V_209 || V_21 )
F_55 ( & V_11 -> V_100 ) ;
else
if ( ! F_66 ( & V_11 -> V_61 . T_3 . V_117 ) )
F_67 ( & V_11 -> V_61 . T_3 . V_117 , V_118 + V_119 ) ;
return V_21 ;
}
int F_135 ( struct V_132 * V_31 , unsigned int V_199 ,
int V_210 , unsigned int V_37 , unsigned int V_16 )
{
struct V_44 * V_22 ;
if ( V_37 >= V_41 || V_16 > V_41 )
return - V_157 ;
V_22 = V_31 -> V_136 -> V_137 ;
if ( ! V_22 )
return - V_160 ;
F_11 ( V_35 , V_22 ,
L_57 , V_199 , V_37 , V_16 ) ;
if ( V_22 -> V_14 != V_94 )
return - V_194 ;
if ( ! V_16 )
return 0 ;
if ( V_199 & V_211 )
return F_129 ( V_22 -> V_138 [ V_210 ] ,
V_199 , V_37 , V_16 ) ;
else if ( V_199 & V_212 )
return F_132 ( V_22 -> V_140 [ V_210 ] ,
V_199 , V_37 , V_16 ) ;
return - V_157 ;
}
int F_136 ( struct V_132 * V_31 , int V_20 )
{
struct V_10 * V_11 ;
struct V_44 * V_22 = V_31 -> V_136 -> V_137 ;
if ( ! V_22 )
return - V_160 ;
V_11 = V_22 -> V_138 [ V_20 ] ;
F_14 ( F_137 ( V_11 ) ) ;
if ( ! F_138 ( V_11 -> V_22 -> V_213 ) )
F_20 ( V_11 -> V_22 -> V_213 , 0 ) ;
F_37 ( V_11 ) ;
F_139 ( V_129 , & V_11 -> V_61 . T_4 . V_130 ) ;
if ( ! F_138 ( V_11 -> V_22 -> V_213 ) && * V_11 -> V_22 -> V_213 )
goto V_214;
if ( ! F_50 ( V_11 ) )
goto V_214;
return 0 ;
V_214:
if ( F_79 ( V_129 ,
& V_11 -> V_61 . T_4 . V_130 ) )
return 0 ;
else
return 1 ;
}
int F_140 ( struct V_132 * V_31 , int V_20 , int * V_37 ,
int * error )
{
struct V_10 * V_11 ;
int V_15 , V_93 ;
struct V_44 * V_22 = V_31 -> V_136 -> V_137 ;
if ( ! V_22 )
return - V_160 ;
V_11 = V_22 -> V_138 [ V_20 ] ;
F_14 ( F_137 ( V_11 ) ) ;
if ( F_36 ( V_11 ) )
F_32 ( V_11 ) ;
F_70 ( V_11 ) ;
if ( ! F_48 ( V_11 ) )
return 0 ;
if ( F_26 ( V_11 -> V_22 -> V_14 != V_94 ) )
return - V_13 ;
V_15 = V_11 -> V_92 ;
V_93 = V_11 -> V_73 ;
* V_37 = V_15 ;
* error = V_11 -> V_70 ;
V_11 -> V_92 = V_93 ;
V_11 -> V_70 = 0 ;
return F_52 ( V_93 , V_15 ) ;
}
int F_141 ( struct V_132 * V_31 , int V_20 )
{
struct V_10 * V_11 ;
struct V_44 * V_22 = V_31 -> V_136 -> V_137 ;
if ( ! V_22 )
return - V_160 ;
V_11 = V_22 -> V_138 [ V_20 ] ;
if ( F_79 ( V_129 ,
& V_11 -> V_61 . T_4 . V_130 ) )
return 0 ;
else
return 1 ;
}
static int T_7 F_142 ( void )
{
int V_21 ;
V_21 = F_143 () ;
if ( V_21 )
return V_21 ;
V_21 = F_144 () ;
if ( V_21 )
goto V_215;
V_21 = F_145 () ;
if ( V_21 )
goto V_216;
V_21 = F_146 () ;
if ( V_21 )
goto V_217;
return 0 ;
V_217:
F_147 () ;
V_216:
F_148 () ;
V_215:
F_149 () ;
return V_21 ;
}
static void T_8 F_150 ( void )
{
F_151 () ;
F_147 () ;
F_148 () ;
F_149 () ;
}
