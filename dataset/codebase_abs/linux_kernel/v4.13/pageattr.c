static inline unsigned long F_1 ( unsigned long V_1 , unsigned char V_2 )
{
asm volatile(".insn rrf,0xb22b0000,%[skey],%[addr],9,0"
: [addr] "+a" (addr) : [skey] "d" (skey));
return V_1 ;
}
void F_2 ( unsigned long V_3 , unsigned long V_4 )
{
unsigned long V_5 , V_6 ;
if ( ! V_7 )
return;
while ( V_3 < V_4 ) {
if ( V_8 ) {
V_6 = 1UL << 20 ;
V_5 = ( V_3 + V_6 ) & ~ ( V_6 - 1 ) ;
if ( V_5 <= V_4 ) {
do {
V_3 = F_1 ( V_3 , V_7 ) ;
} while ( V_3 < V_5 );
continue;
}
}
F_3 ( V_3 , V_7 , 0 ) ;
V_3 += V_9 ;
}
}
void F_4 ( struct V_10 * V_11 )
{
F_5 ( V_11 , L_1 ,
F_6 ( & V_12 [ V_13 ] ) << 2 ) ;
F_5 ( V_11 , L_2 ,
F_6 ( & V_12 [ V_14 ] ) << 10 ) ;
F_5 ( V_11 , L_3 ,
F_6 ( & V_12 [ V_15 ] ) << 21 ) ;
}
static void F_7 ( unsigned long * V_16 , unsigned long V_17 , unsigned long V_1 ,
unsigned long V_18 )
{
unsigned long V_19 , V_20 ;
V_20 = 0 ;
if ( V_21 ) {
switch ( V_18 ) {
case V_22 :
V_20 = ~ ( V_23 * sizeof( V_24 ) - 1 ) ;
break;
case V_25 :
V_20 = ~ ( V_26 * sizeof( V_27 ) - 1 ) ;
break;
case V_28 :
V_20 = ~ ( V_29 * sizeof( V_30 ) - 1 ) ;
break;
}
V_19 = ( unsigned long ) V_16 & V_20 ;
F_8 ( * V_16 , V_17 , V_19 , V_18 , V_1 , V_31 . V_32 ) ;
} else if ( V_33 ) {
F_9 ( V_16 , * V_16 , V_17 ) ;
} else {
F_10 ( ( unsigned int * ) V_16 + 1 , * V_16 , V_17 ) ;
}
}
static int F_11 ( V_27 * V_34 , unsigned long V_1 , unsigned long V_4 ,
unsigned long V_35 )
{
V_30 * V_36 , V_17 ;
V_36 = F_12 ( V_34 , V_1 ) ;
do {
V_17 = * V_36 ;
if ( F_13 ( V_17 ) )
return - V_37 ;
if ( V_35 & V_38 )
V_17 = F_14 ( V_17 ) ;
else if ( V_35 & V_39 )
V_17 = F_15 ( F_16 ( V_17 ) ) ;
if ( V_35 & V_40 )
F_17 ( V_17 ) |= V_41 ;
else if ( V_35 & V_42 )
F_17 ( V_17 ) &= ~ V_41 ;
F_7 ( ( unsigned long * ) V_36 , F_17 ( V_17 ) , V_1 , V_28 ) ;
V_36 ++ ;
V_1 += V_9 ;
F_18 () ;
} while ( V_1 < V_4 );
return 0 ;
}
static int F_19 ( V_27 * V_34 , unsigned long V_1 )
{
unsigned long V_43 , V_44 ;
V_30 * V_45 , * V_36 ;
V_27 V_17 ;
int V_46 , V_47 , V_48 ;
V_45 = F_20 () ;
if ( ! V_45 )
return - V_49 ;
V_43 = F_21 ( * V_34 ) << V_50 ;
V_47 = ! ! ( F_22 ( * V_34 ) & V_51 ) ;
V_48 = ! ! ( F_22 ( * V_34 ) & V_52 ) ;
V_44 = F_23 ( V_47 ? V_53 : V_54 ) ;
if ( ! V_48 )
V_44 &= ~ V_41 ;
V_36 = V_45 ;
for ( V_46 = 0 ; V_46 < V_29 ; V_46 ++ ) {
F_17 ( * V_36 ) = V_43 | V_44 ;
V_43 += V_9 ;
V_36 ++ ;
}
F_22 ( V_17 ) = F_24 ( V_45 ) | V_55 ;
F_7 ( ( unsigned long * ) V_34 , F_22 ( V_17 ) , V_1 , V_25 ) ;
F_25 ( V_13 , V_29 ) ;
F_25 ( V_14 , - 1 ) ;
return 0 ;
}
static void F_26 ( V_27 * V_34 , unsigned long V_1 ,
unsigned long V_35 )
{
V_27 V_17 = * V_34 ;
if ( V_35 & V_38 )
V_17 = F_27 ( V_17 ) ;
else if ( V_35 & V_39 )
V_17 = F_28 ( F_29 ( V_17 ) ) ;
if ( V_35 & V_40 )
F_22 ( V_17 ) |= V_52 ;
else if ( V_35 & V_42 )
F_22 ( V_17 ) &= ~ V_52 ;
F_7 ( ( unsigned long * ) V_34 , F_22 ( V_17 ) , V_1 , V_25 ) ;
}
static int F_30 ( V_24 * V_56 , unsigned long V_1 , unsigned long V_4 ,
unsigned long V_35 )
{
unsigned long V_57 ;
V_27 * V_34 ;
int V_58 = 0 ;
V_34 = F_31 ( V_56 , V_1 ) ;
do {
if ( F_32 ( * V_34 ) )
return - V_37 ;
V_57 = F_33 ( V_1 , V_4 ) ;
if ( F_34 ( * V_34 ) ) {
if ( V_1 & ~ V_59 || V_1 + V_60 > V_57 ) {
V_58 = F_19 ( V_34 , V_1 ) ;
if ( V_58 )
return V_58 ;
continue;
}
F_26 ( V_34 , V_1 , V_35 ) ;
} else {
V_58 = F_11 ( V_34 , V_1 , V_57 , V_35 ) ;
if ( V_58 )
return V_58 ;
}
V_34 ++ ;
V_1 = V_57 ;
F_18 () ;
} while ( V_1 < V_4 );
return V_58 ;
}
static int F_35 ( V_24 * V_56 , unsigned long V_1 )
{
unsigned long V_61 , V_44 ;
V_27 * V_62 , * V_34 ;
V_24 V_17 ;
int V_46 , V_47 , V_48 ;
V_62 = F_36 () ;
if ( ! V_62 )
return - V_49 ;
V_61 = F_37 ( * V_56 ) << V_50 ;
V_47 = ! ! ( F_38 ( * V_56 ) & V_63 ) ;
V_48 = ! ! ( F_38 ( * V_56 ) & V_64 ) ;
V_44 = F_23 ( V_47 ? V_65 : V_66 ) ;
if ( ! V_48 )
V_44 &= ~ V_52 ;
V_34 = V_62 ;
for ( V_46 = 0 ; V_46 < V_26 ; V_46 ++ ) {
F_22 ( * V_34 ) = V_61 | V_44 ;
V_61 += V_60 ;
V_34 ++ ;
}
F_38 ( V_17 ) = F_24 ( V_62 ) | V_67 ;
F_7 ( ( unsigned long * ) V_56 , F_38 ( V_17 ) , V_1 , V_22 ) ;
F_25 ( V_14 , V_26 ) ;
F_25 ( V_15 , - 1 ) ;
return 0 ;
}
static void F_39 ( V_24 * V_56 , unsigned long V_1 ,
unsigned long V_35 )
{
V_24 V_17 = * V_56 ;
if ( V_35 & V_38 )
V_17 = F_40 ( V_17 ) ;
else if ( V_35 & V_39 )
V_17 = F_41 ( F_42 ( V_17 ) ) ;
if ( V_35 & V_40 )
F_38 ( V_17 ) |= V_64 ;
else if ( V_35 & V_42 )
F_38 ( V_17 ) &= ~ V_64 ;
F_7 ( ( unsigned long * ) V_56 , F_38 ( V_17 ) , V_1 , V_22 ) ;
}
static int F_43 ( T_1 * V_68 , unsigned long V_1 , unsigned long V_4 ,
unsigned long V_35 )
{
unsigned long V_57 ;
V_24 * V_56 ;
int V_58 = 0 ;
V_56 = F_44 ( V_68 , V_1 ) ;
do {
if ( F_45 ( * V_56 ) )
return - V_37 ;
V_57 = F_46 ( V_1 , V_4 ) ;
if ( F_47 ( * V_56 ) ) {
if ( V_1 & ~ V_69 || V_1 + V_70 > V_57 ) {
V_58 = F_35 ( V_56 , V_1 ) ;
if ( V_58 )
break;
continue;
}
F_39 ( V_56 , V_1 , V_35 ) ;
} else {
V_58 = F_30 ( V_56 , V_1 , V_57 , V_35 ) ;
}
V_56 ++ ;
V_1 = V_57 ;
F_18 () ;
} while ( V_1 < V_4 && ! V_58 );
return V_58 ;
}
static int F_48 ( T_2 * V_71 , unsigned long V_1 , unsigned long V_4 ,
unsigned long V_35 )
{
unsigned long V_57 ;
T_1 * V_72 ;
int V_58 = 0 ;
V_72 = F_49 ( V_71 , V_1 ) ;
do {
if ( F_50 ( * V_72 ) )
return - V_37 ;
V_57 = F_51 ( V_1 , V_4 ) ;
V_58 = F_43 ( V_72 , V_1 , V_57 , V_35 ) ;
V_72 ++ ;
V_1 = V_57 ;
F_18 () ;
} while ( V_1 < V_4 && ! V_58 );
return V_58 ;
}
static int F_52 ( unsigned long V_1 , unsigned long V_4 ,
unsigned long V_35 )
{
unsigned long V_57 ;
int V_58 = - V_37 ;
T_2 * V_73 ;
if ( V_1 == V_4 )
return 0 ;
if ( V_4 >= V_74 )
return - V_37 ;
F_53 ( & V_75 ) ;
V_73 = F_54 ( V_1 ) ;
do {
if ( F_55 ( * V_73 ) )
break;
V_57 = F_56 ( V_1 , V_4 ) ;
V_58 = F_48 ( V_73 , V_1 , V_57 , V_35 ) ;
if ( V_58 )
break;
F_18 () ;
} while ( V_73 ++ , V_1 = V_57 , V_1 < V_4 && ! V_58 );
F_57 ( & V_75 ) ;
return V_58 ;
}
int F_58 ( unsigned long V_1 , int V_76 , unsigned long V_35 )
{
if ( ! V_77 )
V_35 &= ~ ( V_40 | V_42 ) ;
if ( ! V_35 )
return 0 ;
V_1 &= V_78 ;
return F_52 ( V_1 , V_1 + V_76 * V_9 , V_35 ) ;
}
static void F_59 ( V_30 * V_79 , unsigned long V_80 , int V_81 )
{
int V_46 ;
if ( F_60 ( 13 ) ) {
F_61 ( V_80 , V_81 - 1 , V_79 , V_82 ) ;
return;
}
for ( V_46 = 0 ; V_46 < V_81 ; V_46 ++ ) {
F_62 ( V_80 , V_79 , V_82 ) ;
V_80 += V_9 ;
V_79 ++ ;
}
}
void F_63 ( struct V_83 * V_83 , int V_76 , int V_84 )
{
unsigned long V_80 ;
int V_81 , V_46 , V_85 ;
T_2 * V_71 ;
T_1 * V_68 ;
V_24 * V_86 ;
V_27 * V_87 ;
V_30 * V_79 ;
for ( V_46 = 0 ; V_46 < V_76 ; ) {
V_80 = F_64 ( V_83 + V_46 ) ;
V_71 = F_54 ( V_80 ) ;
V_68 = F_49 ( V_71 , V_80 ) ;
V_86 = F_44 ( V_68 , V_80 ) ;
V_87 = F_31 ( V_86 , V_80 ) ;
V_79 = F_65 ( V_87 , V_80 ) ;
V_81 = ( unsigned long ) V_79 >> F_66 ( sizeof( long ) ) ;
V_81 = V_29 - ( V_81 & ( V_29 - 1 ) ) ;
V_81 = F_67 ( V_76 - V_46 , V_81 ) ;
if ( V_84 ) {
for ( V_85 = 0 ; V_85 < V_81 ; V_85 ++ ) {
F_17 ( * V_79 ) &= ~ V_88 ;
V_80 += V_9 ;
V_79 ++ ;
}
} else {
F_59 ( V_79 , V_80 , V_81 ) ;
}
V_46 += V_81 ;
}
}
bool F_68 ( struct V_83 * V_83 )
{
unsigned long V_1 ;
int V_89 ;
V_1 = F_64 ( V_83 ) ;
asm volatile(
" lra %1,0(%1)\n"
" ipm %0\n"
" srl %0,28"
: "=d" (cc), "+a" (addr) : : "cc");
return V_89 == 0 ;
}
