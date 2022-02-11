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
int V_6 ;
if ( F_16 ( V_11 ) ) {
V_1 = V_11 -> V_22 -> V_23 ;
V_4 |= V_52 ;
}
V_27:
V_6 = F_3 ( V_1 , V_11 -> V_7 , V_53 , V_4 ) ;
if ( F_26 ( * V_53 ) ) {
F_14 ( F_29 ( V_11 ) != V_56 || V_6 != 2 ) ;
if ( ! V_55 ) {
V_55 = F_30 () ;
goto V_27;
}
if ( ( F_30 () - V_55 ) < V_57 )
goto V_27;
}
return V_6 ;
}
static inline int F_31 ( struct V_10 * V_11 )
{
unsigned long V_1 = * ( ( V_49 * ) & V_11 -> V_22 -> V_1 ) ;
unsigned int V_4 = V_58 ;
int V_6 ;
F_11 ( V_35 , V_11 -> V_22 , L_13 , V_11 -> V_20 ) ;
F_9 ( V_11 , V_59 ) ;
if ( F_16 ( V_11 ) ) {
V_1 = V_11 -> V_22 -> V_23 ;
V_4 |= V_52 ;
}
V_6 = F_2 ( V_1 , V_11 -> V_7 , V_4 ) ;
if ( F_26 ( V_6 ) )
F_5 ( L_14 , F_6 ( V_11 ) , V_6 ) ;
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
if ( ! V_11 -> V_60 . T_4 . V_61 )
return;
V_11 -> V_60 . T_4 . V_61 = 0 ;
F_9 ( V_11 , V_62 ) ;
if ( F_16 ( V_11 ) ) {
F_19 ( V_11 , V_11 -> V_60 . T_4 . V_63 , V_45 ,
V_11 -> V_60 . T_4 . V_64 ) ;
V_11 -> V_60 . T_4 . V_64 = 0 ;
} else
F_21 ( V_11 , V_11 -> V_60 . T_4 . V_63 , V_45 ) ;
}
static inline void F_38 ( struct V_10 * V_11 , int V_16 )
{
int V_65 = 0 ;
V_11 -> V_66 . V_67 += V_16 ;
if ( V_16 == V_40 ) {
V_11 -> V_66 . V_68 [ 7 ] ++ ;
return;
}
while ( V_16 >>= 1 )
V_65 ++ ;
V_11 -> V_66 . V_68 [ V_65 ] ++ ;
}
static void F_39 ( struct V_10 * V_11 , int V_16 )
{
unsigned char V_14 = ( V_11 -> V_25 ) ? V_45 :
V_46 ;
V_11 -> V_69 |= V_70 ;
if ( ( ! V_11 -> V_25 &&
( V_11 -> V_71 [ V_11 -> V_72 ] -> V_73 [ 15 ] . V_74 ) == 0x10 ) ) {
F_9 ( V_11 , V_75 ) ;
F_11 ( V_35 , V_11 -> V_22 , L_15 ,
V_11 -> V_72 ) ;
return;
}
F_5 ( L_16 , F_6 ( V_11 ) ) ;
F_5 ( ( V_11 -> V_25 ) ? L_17 : L_18 , V_11 -> V_20 ) ;
F_5 ( L_19 , V_11 -> V_72 , V_16 ) ;
F_5 ( L_20 ,
V_11 -> V_71 [ V_11 -> V_72 ] -> V_73 [ 14 ] . V_74 ,
V_11 -> V_71 [ V_11 -> V_72 ] -> V_73 [ 15 ] . V_74 ) ;
F_19 ( V_11 , V_11 -> V_72 , V_14 , V_16 ) ;
}
static inline void F_40 ( struct V_10 * V_11 , int V_16 )
{
int V_76 ;
F_11 ( V_35 , V_11 -> V_22 , L_21 , V_16 ) ;
if ( F_16 ( V_11 ) ) {
if ( ! V_11 -> V_60 . T_4 . V_61 ) {
V_11 -> V_60 . T_4 . V_61 = 1 ;
V_11 -> V_60 . T_4 . V_64 = V_16 ;
V_11 -> V_60 . T_4 . V_63 = V_11 -> V_72 ;
return;
}
F_19 ( V_11 , V_11 -> V_60 . T_4 . V_63 , V_45 ,
V_11 -> V_60 . T_4 . V_64 ) ;
V_11 -> V_60 . T_4 . V_64 = V_16 ;
V_11 -> V_60 . T_4 . V_63 = V_11 -> V_72 ;
return;
}
V_76 = F_41 ( V_11 -> V_72 , V_16 - 1 ) ;
if ( V_11 -> V_60 . T_4 . V_61 ) {
F_21 ( V_11 , V_76 , V_77 ) ;
F_21 ( V_11 , V_11 -> V_60 . T_4 . V_63 , V_45 ) ;
} else {
V_11 -> V_60 . T_4 . V_61 = 1 ;
F_21 ( V_11 , V_76 , V_77 ) ;
}
V_11 -> V_60 . T_4 . V_63 = V_76 ;
V_16 -- ;
if ( ! V_16 )
return;
F_19 ( V_11 , V_11 -> V_72 , V_45 , V_16 ) ;
}
static int F_42 ( struct V_10 * V_11 )
{
int V_16 , V_78 ;
unsigned char V_14 = 0 ;
V_16 = F_43 ( F_44 ( & V_11 -> V_79 ) , V_40 ) ;
V_78 = F_41 ( V_11 -> V_72 , V_16 ) ;
if ( V_11 -> V_72 == V_78 )
goto T_3;
V_16 = F_15 ( V_11 , V_11 -> V_72 , & V_14 , V_16 , 1 ) ;
if ( ! V_16 )
goto T_3;
switch ( V_14 ) {
case V_80 :
F_40 ( V_11 , V_16 ) ;
V_11 -> V_72 = F_41 ( V_11 -> V_72 , V_16 ) ;
if ( F_45 ( V_16 , & V_11 -> V_79 ) == 0 )
F_9 ( V_11 , V_81 ) ;
if ( V_11 -> V_22 -> V_82 )
F_38 ( V_11 , V_16 ) ;
break;
case V_83 :
F_39 ( V_11 , V_16 ) ;
V_11 -> V_72 = F_41 ( V_11 -> V_72 , V_16 ) ;
F_45 ( V_16 , & V_11 -> V_79 ) ;
if ( V_11 -> V_22 -> V_82 )
F_46 ( V_11 , V_16 ) ;
break;
case V_84 :
case V_45 :
case V_77 :
if ( V_11 -> V_22 -> V_82 )
V_11 -> V_66 . V_85 ++ ;
F_11 ( V_35 , V_11 -> V_22 , L_22 ) ;
break;
default:
F_47 () ;
}
T_3:
return V_11 -> V_72 ;
}
static int F_48 ( struct V_10 * V_11 )
{
int V_37 ;
V_37 = F_42 ( V_11 ) ;
if ( ( V_37 != V_11 -> V_86 ) || V_11 -> V_69 ) {
V_11 -> V_86 = V_37 ;
if ( ! F_49 ( V_11 -> V_22 ) && V_87 )
V_11 -> V_60 . T_4 . V_88 = F_30 () ;
return 1 ;
} else
return 0 ;
}
static inline int F_50 ( struct V_10 * V_11 )
{
unsigned char V_14 = 0 ;
if ( ! F_44 ( & V_11 -> V_79 ) )
return 1 ;
if ( F_36 ( V_11 ) )
F_27 ( V_11 ) ;
F_18 ( V_11 , V_11 -> V_72 , & V_14 , 0 ) ;
if ( V_14 == V_80 || V_14 == V_83 )
return 0 ;
if ( F_49 ( V_11 -> V_22 ) )
return 1 ;
if ( V_89 )
return 1 ;
if ( F_30 () > V_11 -> V_60 . T_4 . V_88 + V_90 ) {
F_11 ( V_35 , V_11 -> V_22 , L_23 ,
V_11 -> V_72 ) ;
return 1 ;
} else
return 0 ;
}
static void F_51 ( struct V_10 * V_11 )
{
int V_15 = V_11 -> V_91 ;
int V_92 = V_11 -> V_72 ;
int V_16 ;
if ( F_26 ( V_11 -> V_22 -> V_14 != V_93 ) )
return;
V_16 = F_52 ( V_92 , V_15 ) ;
if ( V_11 -> V_25 ) {
F_9 ( V_11 , V_94 ) ;
F_11 ( V_35 , V_11 -> V_22 , L_24 , V_15 , V_16 ) ;
} else {
F_9 ( V_11 , V_95 ) ;
F_11 ( V_35 , V_11 -> V_22 , L_25 ,
V_15 , V_16 ) ;
}
V_11 -> V_30 ( V_11 -> V_22 -> V_31 , V_11 -> V_69 , V_11 -> V_20 , V_15 , V_16 ,
V_11 -> V_22 -> V_33 ) ;
V_11 -> V_91 = V_92 ;
V_11 -> V_69 = 0 ;
}
static void F_53 ( struct V_10 * V_11 )
{
F_9 ( V_11 , V_96 ) ;
if ( ! F_48 ( V_11 ) )
return;
F_51 ( V_11 ) ;
if ( ! F_50 ( V_11 ) ) {
F_9 ( V_11 , V_97 ) ;
if ( F_54 ( V_11 -> V_22 -> V_14 != V_98 ) ) {
F_55 ( & V_11 -> V_99 ) ;
return;
}
}
F_37 ( V_11 ) ;
if ( ! F_50 ( V_11 ) ) {
F_9 ( V_11 , V_100 ) ;
if ( F_54 ( V_11 -> V_22 -> V_14 != V_98 ) )
F_55 ( & V_11 -> V_99 ) ;
}
}
void F_56 ( unsigned long V_101 )
{
struct V_10 * V_11 = (struct V_10 * ) V_101 ;
F_53 ( V_11 ) ;
}
static int F_57 ( struct V_10 * V_11 )
{
int V_16 , V_78 ;
unsigned char V_14 = 0 ;
if ( F_36 ( V_11 ) )
if ( ( ( F_29 ( V_11 ) != V_56 ) &&
! F_33 ( V_11 ) ) ||
( F_29 ( V_11 ) == V_56 &&
F_58 ( V_11 ) ) )
F_27 ( V_11 ) ;
V_16 = F_43 ( F_44 ( & V_11 -> V_79 ) , V_40 ) ;
V_78 = F_41 ( V_11 -> V_72 , V_16 ) ;
if ( V_11 -> V_72 == V_78 )
return V_11 -> V_72 ;
V_16 = F_15 ( V_11 , V_11 -> V_72 , & V_14 , V_16 , 0 ) ;
if ( ! V_16 )
return V_11 -> V_72 ;
switch ( V_14 ) {
case V_102 :
F_11 ( V_35 , V_11 -> V_22 , L_26 , V_11 -> V_20 , V_16 ) ;
F_45 ( V_16 , & V_11 -> V_79 ) ;
V_11 -> V_72 = F_41 ( V_11 -> V_72 , V_16 ) ;
if ( V_11 -> V_22 -> V_82 )
F_38 ( V_11 , V_16 ) ;
break;
case V_103 :
F_39 ( V_11 , V_16 ) ;
V_11 -> V_72 = F_41 ( V_11 -> V_72 , V_16 ) ;
F_45 ( V_16 , & V_11 -> V_79 ) ;
if ( V_11 -> V_22 -> V_82 )
F_46 ( V_11 , V_16 ) ;
break;
case V_104 :
if ( V_11 -> V_22 -> V_82 )
V_11 -> V_66 . V_85 ++ ;
F_11 ( V_35 , V_11 -> V_22 , L_27 , V_11 -> V_20 ) ;
break;
case V_46 :
case V_105 :
break;
default:
F_47 () ;
}
return V_11 -> V_72 ;
}
static inline int F_59 ( struct V_10 * V_11 )
{
return F_44 ( & V_11 -> V_79 ) == 0 ;
}
static inline int F_60 ( struct V_10 * V_11 )
{
int V_37 ;
V_37 = F_57 ( V_11 ) ;
if ( ( V_37 != V_11 -> V_86 ) || V_11 -> V_69 ) {
V_11 -> V_86 = V_37 ;
F_11 ( V_35 , V_11 -> V_22 , L_28 , V_11 -> V_20 ) ;
return 1 ;
} else
return 0 ;
}
static int F_61 ( struct V_10 * V_11 )
{
unsigned int V_53 ;
int V_6 ;
if ( ! F_62 ( V_11 ) )
return 0 ;
F_11 ( V_35 , V_11 -> V_22 , L_29 , V_11 -> V_20 ) ;
F_9 ( V_11 , V_106 ) ;
V_6 = F_28 ( V_11 , & V_53 ) ;
switch ( V_6 ) {
case 0 :
break;
case 2 :
if ( V_53 ) {
F_5 ( L_30 , F_6 ( V_11 ) , V_11 -> V_20 ) ;
V_6 |= V_107 ;
} else
F_11 ( V_35 , V_11 -> V_22 , L_31 , V_11 -> V_20 ) ;
break;
case 1 :
case 3 :
F_5 ( L_32 , F_6 ( V_11 ) , V_6 ) ;
break;
}
return V_6 ;
}
static void F_63 ( struct V_10 * V_11 )
{
F_9 ( V_11 , V_108 ) ;
F_8 ( F_44 ( & V_11 -> V_79 ) < 0 ) ;
if ( F_60 ( V_11 ) )
F_51 ( V_11 ) ;
if ( F_29 ( V_11 ) == V_109 )
if ( ! F_33 ( V_11 ) && ! F_59 ( V_11 ) )
goto V_110;
if ( F_29 ( V_11 ) == V_56 && ! F_58 ( V_11 ) )
return;
if ( ( F_29 ( V_11 ) == V_56 ) &&
( F_44 ( & V_11 -> V_79 ) ) > V_111 )
goto V_110;
if ( V_11 -> V_60 . T_3 . V_112 )
return;
if ( F_59 ( V_11 ) )
F_64 ( & V_11 -> V_60 . T_3 . V_113 ) ;
else
if ( ! F_65 ( & V_11 -> V_60 . T_3 . V_113 ) )
F_66 ( & V_11 -> V_60 . T_3 . V_113 , V_114 + 10 * V_115 ) ;
return;
V_110:
if ( F_26 ( V_11 -> V_22 -> V_14 == V_98 ) )
return;
F_55 ( & V_11 -> V_99 ) ;
}
void F_67 ( unsigned long V_101 )
{
struct V_10 * V_11 = (struct V_10 * ) V_101 ;
F_63 ( V_11 ) ;
}
void F_68 ( unsigned long V_101 )
{
struct V_10 * V_11 = (struct V_10 * ) V_101 ;
if ( F_26 ( V_11 -> V_22 -> V_14 == V_98 ) )
return;
F_55 ( & V_11 -> V_99 ) ;
}
static inline void F_69 ( struct V_10 * V_11 )
{
struct V_10 * T_3 ;
int V_39 ;
if ( ! F_33 ( V_11 ) )
return;
F_24 (q->irq_ptr, out, i)
if ( ! F_59 ( T_3 ) )
F_55 ( & T_3 -> V_99 ) ;
}
static void F_70 ( struct V_10 * V_11 )
{
F_9 ( V_11 , V_96 ) ;
if ( F_36 ( V_11 ) && F_71 ( V_11 ) )
F_32 ( V_11 ) ;
F_69 ( V_11 ) ;
if ( ! F_48 ( V_11 ) )
return;
F_51 ( V_11 ) ;
if ( ! F_50 ( V_11 ) ) {
F_9 ( V_11 , V_97 ) ;
if ( F_54 ( V_11 -> V_22 -> V_14 != V_98 ) ) {
F_55 ( & V_11 -> V_99 ) ;
return;
}
}
F_37 ( V_11 ) ;
if ( ! F_50 ( V_11 ) ) {
F_9 ( V_11 , V_100 ) ;
if ( F_54 ( V_11 -> V_22 -> V_14 != V_98 ) )
F_55 ( & V_11 -> V_99 ) ;
}
}
void F_72 ( unsigned long V_101 )
{
struct V_10 * V_11 = (struct V_10 * ) V_101 ;
F_70 ( V_11 ) ;
}
static inline void F_73 ( struct V_44 * V_22 ,
enum V_116 V_14 )
{
F_11 ( V_35 , V_22 , L_33 , V_14 ) ;
V_22 -> V_14 = V_14 ;
F_74 () ;
}
static void F_75 ( struct V_44 * V_22 , struct V_117 * V_117 )
{
if ( V_117 -> V_118 . V_119 . V_120 . V_121 ) {
F_5 ( L_34 , V_22 -> V_1 . V_122 ) ;
F_76 ( V_117 , 64 ) ;
F_76 ( V_117 -> V_123 , 64 ) ;
}
}
static void F_77 ( struct V_44 * V_22 )
{
int V_39 ;
struct V_10 * V_11 ;
if ( F_26 ( V_22 -> V_14 == V_98 ) )
return;
F_23 (irq_ptr, q, i) {
if ( V_11 -> V_60 . T_4 . V_124 ) {
if ( F_78 ( V_125 ,
& V_11 -> V_60 . T_4 . V_126 ) ) {
F_9 ( V_11 , V_127 ) ;
continue;
}
V_11 -> V_60 . T_4 . V_124 ( V_11 -> V_22 -> V_31 , V_11 -> V_20 ,
V_11 -> V_22 -> V_33 ) ;
} else
F_55 ( & V_11 -> V_99 ) ;
}
if ( ! F_33 ( V_11 ) )
return;
F_24 (irq_ptr, q, i) {
if ( F_59 ( V_11 ) )
continue;
if ( F_36 ( V_11 ) && F_79 ( V_11 ) )
F_27 ( V_11 ) ;
F_55 ( & V_11 -> V_99 ) ;
}
}
static void F_80 ( struct V_128 * V_31 ,
unsigned long V_129 , int V_130 , int V_131 )
{
struct V_44 * V_22 = V_31 -> V_132 -> V_133 ;
struct V_10 * V_11 ;
F_5 ( L_35 , V_22 -> V_1 . V_122 ) ;
F_5 ( L_36 , V_129 ) ;
F_5 ( L_37 , V_131 , V_130 ) ;
if ( V_22 -> V_26 ) {
V_11 = V_22 -> V_134 [ 0 ] ;
} else if ( V_22 -> V_135 ) {
V_11 = V_22 -> V_136 [ 0 ] ;
} else {
F_81 () ;
goto V_137;
}
V_11 -> V_30 ( V_11 -> V_22 -> V_31 , V_32 ,
0 , - 1 , - 1 , V_22 -> V_33 ) ;
V_137:
F_73 ( V_22 , V_98 ) ;
}
static void F_82 ( struct V_128 * V_31 , int V_130 ,
int V_131 )
{
struct V_44 * V_22 = V_31 -> V_132 -> V_133 ;
F_11 ( V_35 , V_22 , L_38 ) ;
if ( V_130 )
goto error;
if ( V_131 & ~ ( V_138 | V_139 ) )
goto error;
if ( ! ( V_131 & V_138 ) )
goto error;
F_73 ( V_22 , V_140 ) ;
return;
error:
F_5 ( L_39 , V_22 -> V_1 . V_122 ) ;
F_5 ( L_37 , V_131 , V_130 ) ;
F_73 ( V_22 , V_141 ) ;
}
void F_83 ( struct V_128 * V_31 , unsigned long V_129 ,
struct V_117 * V_117 )
{
struct V_44 * V_22 = V_31 -> V_132 -> V_133 ;
int V_130 , V_131 ;
if ( ! V_129 || ! V_22 ) {
F_5 ( L_40 , V_31 -> V_132 -> V_1 . V_122 ) ;
return;
}
F_84 ( F_85 () ) . V_142 [ V_143 ] ++ ;
if ( V_22 -> V_82 )
V_22 -> V_144 . V_145 ++ ;
if ( F_86 ( V_117 ) ) {
switch ( F_87 ( V_117 ) ) {
case - V_13 :
F_5 ( L_41 , V_22 -> V_1 . V_122 ) ;
F_73 ( V_22 , V_141 ) ;
F_88 ( & V_31 -> V_132 -> V_146 ) ;
return;
default:
F_14 ( 1 ) ;
return;
}
}
F_75 ( V_22 , V_117 ) ;
V_130 = V_117 -> V_147 . V_148 . V_130 ;
V_131 = V_117 -> V_147 . V_148 . V_131 ;
switch ( V_22 -> V_14 ) {
case V_149 :
F_82 ( V_31 , V_130 , V_131 ) ;
break;
case V_150 :
F_73 ( V_22 , V_149 ) ;
break;
case V_140 :
case V_93 :
if ( V_130 & V_151 ) {
F_77 ( V_22 ) ;
return;
}
if ( V_130 || V_131 )
F_80 ( V_31 , V_129 , V_130 ,
V_131 ) ;
break;
case V_98 :
break;
default:
F_14 ( 1 ) ;
}
F_88 ( & V_31 -> V_132 -> V_146 ) ;
}
int F_89 ( struct V_128 * V_31 ,
struct V_152 * V_101 )
{
if ( ! V_31 || ! V_31 -> V_132 )
return - V_153 ;
F_90 ( L_42 , V_31 -> V_132 -> V_1 . V_122 ) ;
return F_91 ( NULL , & V_31 -> V_132 -> V_1 , V_101 ) ;
}
static void F_92 ( struct V_128 * V_31 )
{
struct V_44 * V_22 = V_31 -> V_132 -> V_133 ;
struct V_10 * V_11 ;
int V_39 ;
F_23 (irq_ptr, q, i)
F_93 ( & V_11 -> V_99 ) ;
F_24 (irq_ptr, q, i) {
F_64 ( & V_11 -> V_60 . T_3 . V_113 ) ;
F_93 ( & V_11 -> V_99 ) ;
}
}
int F_94 ( struct V_128 * V_31 , int V_154 )
{
struct V_44 * V_22 = V_31 -> V_132 -> V_133 ;
int V_21 ;
unsigned long V_155 ;
if ( ! V_22 )
return - V_156 ;
F_8 ( F_95 () ) ;
F_90 ( L_43 , V_31 -> V_132 -> V_1 . V_122 ) ;
F_96 ( & V_22 -> V_157 ) ;
if ( V_22 -> V_14 == V_149 ) {
F_97 ( & V_22 -> V_157 ) ;
return 0 ;
}
F_73 ( V_22 , V_98 ) ;
F_98 ( V_22 ) ;
F_92 ( V_31 ) ;
F_99 ( V_22 , V_31 ) ;
F_100 ( F_101 ( V_31 ) , V_155 ) ;
if ( V_154 & V_158 )
V_21 = F_102 ( V_31 , V_159 ) ;
else
V_21 = F_103 ( V_31 , V_159 ) ;
if ( V_21 ) {
F_5 ( L_44 , V_22 -> V_1 . V_122 ) ;
F_5 ( L_45 , V_21 ) ;
goto V_160;
}
F_73 ( V_22 , V_150 ) ;
F_104 ( F_101 ( V_31 ) , V_155 ) ;
F_105 ( V_31 -> V_132 -> V_146 ,
V_22 -> V_14 == V_149 ||
V_22 -> V_14 == V_141 ,
10 * V_115 ) ;
F_100 ( F_101 ( V_31 ) , V_155 ) ;
V_160:
F_106 ( V_22 ) ;
if ( ( void * ) V_31 -> V_30 == ( void * ) F_83 )
V_31 -> V_30 = V_22 -> V_161 ;
F_104 ( F_101 ( V_31 ) , V_155 ) ;
F_73 ( V_22 , V_149 ) ;
F_97 ( & V_22 -> V_157 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
int F_107 ( struct V_128 * V_31 )
{
struct V_44 * V_22 = V_31 -> V_132 -> V_133 ;
if ( ! V_22 )
return - V_156 ;
F_90 ( L_46 , V_31 -> V_132 -> V_1 . V_122 ) ;
F_96 ( & V_22 -> V_157 ) ;
if ( V_22 -> V_162 != NULL ) {
F_108 ( V_22 -> V_162 ) ;
V_22 -> V_162 = NULL ;
}
V_31 -> V_132 -> V_133 = NULL ;
F_97 ( & V_22 -> V_157 ) ;
F_109 ( V_22 ) ;
return 0 ;
}
int F_110 ( struct V_163 * V_164 )
{
struct V_44 * V_22 ;
F_90 ( L_47 , V_164 -> V_31 -> V_132 -> V_1 . V_122 ) ;
if ( ( V_164 -> V_165 && ! V_164 -> V_166 ) ||
( V_164 -> V_167 && ! V_164 -> V_168 ) )
return - V_153 ;
if ( ( V_164 -> V_165 > V_169 ) ||
( V_164 -> V_167 > V_169 ) )
return - V_153 ;
if ( ( ! V_164 -> V_170 ) ||
( ! V_164 -> V_171 ) )
return - V_153 ;
V_22 = ( void * ) F_111 ( V_172 | V_173 ) ;
if ( ! V_22 )
goto V_174;
F_112 ( & V_22 -> V_157 ) ;
F_113 ( V_164 , V_22 ) ;
V_22 -> V_175 = F_111 ( V_172 ) ;
if ( ! V_22 -> V_175 )
goto V_176;
V_22 -> V_177 = (struct V_177 * ) F_111 ( V_172 | V_173 ) ;
if ( ! V_22 -> V_177 )
goto V_176;
F_14 ( ( unsigned long ) V_22 -> V_177 & 0xfff ) ;
if ( F_114 ( V_22 , V_164 -> V_165 ,
V_164 -> V_167 ) )
goto V_176;
V_164 -> V_31 -> V_132 -> V_133 = V_22 ;
F_73 ( V_22 , V_149 ) ;
return 0 ;
V_176:
F_109 ( V_22 ) ;
V_174:
return - V_178 ;
}
int F_115 ( struct V_163 * V_164 )
{
struct V_44 * V_22 ;
struct V_128 * V_31 = V_164 -> V_31 ;
unsigned long V_179 ;
int V_21 ;
F_90 ( L_48 , V_31 -> V_132 -> V_1 . V_122 ) ;
V_22 = V_31 -> V_132 -> V_133 ;
if ( ! V_22 )
return - V_156 ;
if ( V_31 -> V_132 -> V_14 != V_180 )
return - V_153 ;
F_96 ( & V_22 -> V_157 ) ;
F_116 ( V_164 ) ;
V_21 = F_117 ( V_22 ) ;
if ( V_21 ) {
F_97 ( & V_22 -> V_157 ) ;
F_94 ( V_31 , V_158 ) ;
return V_21 ;
}
V_22 -> V_181 . V_182 = V_22 -> V_183 . V_148 ;
V_22 -> V_181 . V_155 = V_184 ;
V_22 -> V_181 . V_16 = V_22 -> V_183 . V_16 ;
V_22 -> V_181 . V_185 = ( V_49 ) ( ( V_186 ) V_22 -> V_177 ) ;
F_100 ( F_101 ( V_31 ) , V_179 ) ;
F_118 ( V_31 , 0 ) ;
V_21 = F_119 ( V_31 , & V_22 -> V_181 , V_187 , 0 , 0 ) ;
if ( V_21 ) {
F_5 ( L_49 , V_22 -> V_1 . V_122 ) ;
F_5 ( L_50 , V_21 ) ;
}
F_104 ( F_101 ( V_31 ) , V_179 ) ;
if ( V_21 ) {
F_97 ( & V_22 -> V_157 ) ;
F_94 ( V_31 , V_158 ) ;
return V_21 ;
}
F_105 ( V_31 -> V_132 -> V_146 ,
V_22 -> V_14 == V_140 ||
V_22 -> V_14 == V_141 , V_115 ) ;
if ( V_22 -> V_14 != V_140 ) {
F_97 ( & V_22 -> V_157 ) ;
F_94 ( V_31 , V_158 ) ;
return - V_13 ;
}
F_120 ( V_22 ) ;
F_90 ( L_51 , V_22 -> V_188 . V_189 ) ;
F_22 ( V_22 ) ;
F_97 ( & V_22 -> V_157 ) ;
F_121 ( V_22 , V_31 ) ;
F_122 ( V_22 , V_31 ) ;
return 0 ;
}
int F_123 ( struct V_128 * V_31 )
{
struct V_44 * V_22 ;
int V_21 ;
unsigned long V_179 ;
F_90 ( L_52 , V_31 -> V_132 -> V_1 . V_122 ) ;
V_22 = V_31 -> V_132 -> V_133 ;
if ( ! V_22 )
return - V_156 ;
if ( V_31 -> V_132 -> V_14 != V_180 )
return - V_153 ;
F_96 ( & V_22 -> V_157 ) ;
if ( V_22 -> V_14 == V_149 ) {
V_21 = - V_190 ;
goto T_3;
}
V_22 -> V_181 . V_182 = V_22 -> V_191 . V_148 ;
V_22 -> V_181 . V_155 = V_184 ;
V_22 -> V_181 . V_16 = V_22 -> V_191 . V_16 ;
V_22 -> V_181 . V_185 = 0 ;
F_100 ( F_101 ( V_31 ) , V_179 ) ;
F_124 ( V_31 , V_192 ) ;
V_21 = F_119 ( V_31 , & V_22 -> V_181 , V_193 ,
0 , V_194 ) ;
if ( V_21 ) {
F_5 ( L_53 , V_22 -> V_1 . V_122 ) ;
F_5 ( L_50 , V_21 ) ;
}
F_104 ( F_101 ( V_31 ) , V_179 ) ;
if ( V_21 )
goto T_3;
if ( F_49 ( V_22 ) )
F_125 ( V_22 ) ;
F_126 ( 5 ) ;
switch ( V_22 -> V_14 ) {
case V_98 :
case V_141 :
V_21 = - V_13 ;
break;
default:
F_73 ( V_22 , V_93 ) ;
V_21 = 0 ;
}
T_3:
F_97 ( & V_22 -> V_157 ) ;
return V_21 ;
}
static inline int F_127 ( int V_37 , int V_15 , int V_16 )
{
int V_92 = F_41 ( V_15 , V_16 ) ;
if ( V_92 > V_15 ) {
if ( V_37 >= V_15 && V_37 < V_92 )
return 1 ;
else
return 0 ;
}
if ( ( V_37 >= V_15 && V_37 <= V_41 ) ||
( V_37 < V_92 ) )
return 1 ;
else
return 0 ;
}
static int F_128 ( struct V_10 * V_11 , unsigned int V_195 ,
int V_37 , int V_16 )
{
int V_196 , V_197 ;
F_9 ( V_11 , V_198 ) ;
if ( ! V_11 -> V_60 . T_4 . V_61 )
goto V_199;
if ( V_16 == V_41 ) {
V_11 -> V_60 . T_4 . V_61 = 0 ;
V_11 -> V_60 . T_4 . V_64 = 0 ;
goto V_199;
} else if ( F_127 ( V_11 -> V_60 . T_4 . V_63 , V_37 , V_16 ) ) {
if ( F_16 ( V_11 ) ) {
V_197 = F_41 ( V_37 , V_16 ) ;
V_197 = F_52 ( V_197 , V_11 -> V_60 . T_4 . V_63 ) ;
V_11 -> V_60 . T_4 . V_64 -= V_197 ;
if ( V_11 -> V_60 . T_4 . V_64 <= 0 ) {
V_11 -> V_60 . T_4 . V_61 = 0 ;
V_11 -> V_60 . T_4 . V_64 = 0 ;
goto V_199;
}
V_11 -> V_60 . T_4 . V_63 = F_41 ( V_11 -> V_60 . T_4 . V_63 , V_197 ) ;
}
else
V_11 -> V_60 . T_4 . V_61 = 0 ;
}
V_199:
V_16 = F_19 ( V_11 , V_37 , V_84 , V_16 ) ;
V_196 = F_129 ( V_16 , & V_11 -> V_79 ) - V_16 ;
F_8 ( V_196 + V_16 > V_41 ) ;
if ( V_196 )
return 0 ;
if ( F_130 ( V_11 ) )
return F_31 ( V_11 ) ;
return 0 ;
}
static int F_131 ( struct V_10 * V_11 , unsigned int V_195 ,
int V_37 , int V_16 )
{
unsigned char V_14 = 0 ;
int V_196 , V_21 = 0 ;
F_9 ( V_11 , V_200 ) ;
V_16 = F_19 ( V_11 , V_37 , V_104 , V_16 ) ;
V_196 = F_129 ( V_16 , & V_11 -> V_79 ) ;
F_8 ( V_196 > V_41 ) ;
if ( V_196 == V_41 )
F_9 ( V_11 , V_201 ) ;
if ( V_195 & V_202 ) {
V_11 -> V_60 . T_3 . V_112 = 1 ;
F_9 ( V_11 , V_203 ) ;
} else
V_11 -> V_60 . T_3 . V_112 = 0 ;
if ( F_29 ( V_11 ) == V_56 ) {
F_132 ( V_16 > 1 && ! F_58 ( V_11 ) ) ;
V_21 = F_61 ( V_11 ) ;
} else if ( F_36 ( V_11 ) ) {
V_21 = F_27 ( V_11 ) ;
} else {
F_18 ( V_11 , F_133 ( V_37 ) , & V_14 , 0 ) ;
if ( V_14 != V_104 )
V_21 = F_61 ( V_11 ) ;
else
F_9 ( V_11 , V_204 ) ;
}
if ( V_196 >= V_11 -> V_60 . T_3 . V_205 || V_21 )
F_55 ( & V_11 -> V_99 ) ;
else
if ( ! F_65 ( & V_11 -> V_60 . T_3 . V_113 ) )
F_66 ( & V_11 -> V_60 . T_3 . V_113 , V_114 + V_115 ) ;
return V_21 ;
}
int F_134 ( struct V_128 * V_31 , unsigned int V_195 ,
int V_206 , unsigned int V_37 , unsigned int V_16 )
{
struct V_44 * V_22 ;
if ( V_37 >= V_41 || V_16 > V_41 )
return - V_153 ;
V_22 = V_31 -> V_132 -> V_133 ;
if ( ! V_22 )
return - V_156 ;
F_11 ( V_35 , V_22 ,
L_54 , V_195 , V_37 , V_16 ) ;
if ( V_22 -> V_14 != V_93 )
return - V_190 ;
if ( ! V_16 )
return 0 ;
if ( V_195 & V_207 )
return F_128 ( V_22 -> V_134 [ V_206 ] ,
V_195 , V_37 , V_16 ) ;
else if ( V_195 & V_208 )
return F_131 ( V_22 -> V_136 [ V_206 ] ,
V_195 , V_37 , V_16 ) ;
return - V_153 ;
}
int F_135 ( struct V_128 * V_31 , int V_20 )
{
struct V_10 * V_11 ;
struct V_44 * V_22 = V_31 -> V_132 -> V_133 ;
if ( ! V_22 )
return - V_156 ;
V_11 = V_22 -> V_134 [ V_20 ] ;
F_14 ( F_136 ( V_11 ) ) ;
if ( ! F_137 ( V_11 -> V_22 -> V_209 ) )
F_20 ( V_11 -> V_22 -> V_209 , 0 ) ;
F_37 ( V_11 ) ;
F_138 ( V_125 , & V_11 -> V_60 . T_4 . V_126 ) ;
if ( ! F_137 ( V_11 -> V_22 -> V_209 ) && * V_11 -> V_22 -> V_209 )
goto V_210;
if ( ! F_50 ( V_11 ) )
goto V_210;
return 0 ;
V_210:
if ( F_78 ( V_125 ,
& V_11 -> V_60 . T_4 . V_126 ) )
return 0 ;
else
return 1 ;
}
int F_139 ( struct V_128 * V_31 , int V_20 , int * V_37 ,
int * error )
{
struct V_10 * V_11 ;
int V_15 , V_92 ;
struct V_44 * V_22 = V_31 -> V_132 -> V_133 ;
if ( ! V_22 )
return - V_156 ;
V_11 = V_22 -> V_134 [ V_20 ] ;
F_14 ( F_136 ( V_11 ) ) ;
if ( F_36 ( V_11 ) )
F_32 ( V_11 ) ;
F_69 ( V_11 ) ;
if ( ! F_48 ( V_11 ) )
return 0 ;
if ( F_26 ( V_11 -> V_22 -> V_14 != V_93 ) )
return - V_13 ;
V_15 = V_11 -> V_91 ;
V_92 = V_11 -> V_72 ;
* V_37 = V_15 ;
* error = V_11 -> V_69 ;
V_11 -> V_91 = V_92 ;
V_11 -> V_69 = 0 ;
return F_52 ( V_92 , V_15 ) ;
}
int F_140 ( struct V_128 * V_31 , int V_20 )
{
struct V_10 * V_11 ;
struct V_44 * V_22 = V_31 -> V_132 -> V_133 ;
if ( ! V_22 )
return - V_156 ;
V_11 = V_22 -> V_134 [ V_20 ] ;
if ( F_78 ( V_125 ,
& V_11 -> V_60 . T_4 . V_126 ) )
return 0 ;
else
return 1 ;
}
static int T_7 F_141 ( void )
{
int V_21 ;
V_21 = F_142 () ;
if ( V_21 )
return V_21 ;
V_21 = F_143 () ;
if ( V_21 )
goto V_211;
V_21 = F_144 () ;
if ( V_21 )
goto V_212;
V_21 = F_145 () ;
if ( V_21 )
goto V_213;
return 0 ;
V_213:
F_146 () ;
V_212:
F_147 () ;
V_211:
F_148 () ;
return V_21 ;
}
static void T_8 F_149 ( void )
{
F_150 () ;
F_146 () ;
F_147 () ;
F_148 () ;
}
