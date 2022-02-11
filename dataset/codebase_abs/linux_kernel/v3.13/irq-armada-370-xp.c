static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
if ( V_3 != V_4 )
F_3 ( V_3 , V_5 +
V_6 ) ;
else
F_3 ( V_3 , V_7 +
V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
if ( V_3 != V_4 )
F_3 ( V_3 , V_5 +
V_9 ) ;
else
F_3 ( V_3 , V_7 +
V_10 ) ;
}
static int F_5 ( void )
{
int V_3 ;
F_6 ( & V_11 ) ;
V_3 = F_7 ( & V_12 , V_13 ) ;
if ( V_3 >= V_13 )
V_3 = - V_14 ;
else
F_8 ( V_3 , V_12 ) ;
F_9 ( & V_11 ) ;
return V_3 ;
}
static void F_10 ( int V_3 )
{
F_6 ( & V_11 ) ;
if ( ! F_11 ( V_3 , V_12 ) )
F_12 ( L_1 , V_3 ) ;
else
F_13 ( V_3 , V_12 ) ;
F_9 ( & V_11 ) ;
}
static int F_14 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 V_22 ;
T_1 V_3 ;
int V_23 ;
V_3 = F_5 () ;
if ( V_3 < 0 )
return V_3 ;
V_23 = F_15 ( V_24 , V_3 ) ;
if ( ! V_23 ) {
F_10 ( V_3 ) ;
return - V_25 ;
}
F_16 ( V_23 , V_20 ) ;
V_22 . V_26 = V_27 ;
V_22 . V_28 = 0 ;
V_22 . V_29 = 0xf00 | ( V_3 + 16 ) ;
F_17 ( V_23 , & V_22 ) ;
return 0 ;
}
static void F_18 ( struct V_15 * V_16 ,
unsigned int V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_20 ( V_30 ) ;
F_10 ( V_2 -> V_3 ) ;
}
static int F_21 ( struct V_31 * V_32 , unsigned int V_23 ,
T_1 V_33 )
{
F_22 ( V_23 , & V_34 ,
V_35 ) ;
F_23 ( V_23 , V_36 ) ;
return 0 ;
}
static int F_24 ( struct V_37 * V_38 ,
T_2 V_39 )
{
struct V_15 * V_15 ;
T_3 V_40 ;
int V_41 ;
V_27 = V_39 +
V_42 ;
V_15 = F_25 ( sizeof( * V_15 ) , V_43 ) ;
if ( ! V_15 )
return - V_44 ;
V_15 -> V_45 = F_14 ;
V_15 -> V_46 = F_18 ;
V_15 -> V_47 = V_38 ;
V_24 =
F_26 ( NULL , V_13 ,
& V_48 ,
NULL ) ;
if ( ! V_24 ) {
F_27 ( V_15 ) ;
return - V_44 ;
}
V_41 = F_28 ( V_15 ) ;
if ( V_41 < 0 ) {
F_29 ( V_24 ) ;
F_27 ( V_15 ) ;
return V_41 ;
}
V_40 = F_30 ( V_7 + V_49 )
| V_50 ;
F_3 ( V_40 , V_7 +
V_49 ) ;
F_3 ( 1 , V_7 + V_10 ) ;
return 0 ;
}
static inline int F_24 ( struct V_37 * V_38 ,
T_2 V_39 )
{
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_51 * V_52 , bool V_53 )
{
unsigned long V_40 ;
unsigned long V_54 = 0 ;
unsigned long V_55 = 0 ;
unsigned long V_56 = 0 ;
T_1 V_3 = F_2 ( V_2 ) ;
int V_57 ;
F_32 (cpu, mask_val) {
V_54 |= 1 << F_33 ( V_57 ) ;
V_56 ++ ;
}
if ( V_56 > 1 )
return - V_25 ;
F_32 (cpu, cpu_online_mask)
V_55 |= 1 << F_33 ( V_57 ) ;
F_34 ( & V_58 ) ;
V_40 = F_30 ( V_5 + F_35 ( V_3 ) ) ;
V_40 = ( V_40 & ( ~ V_55 ) ) | V_54 ;
F_3 ( V_40 , V_5 + F_35 ( V_3 ) ) ;
F_36 ( & V_58 ) ;
return 0 ;
}
static int F_37 ( struct V_31 * V_59 ,
unsigned int V_23 , T_1 V_33 )
{
F_1 ( F_19 ( V_23 ) ) ;
if ( V_33 != V_4 )
F_3 ( V_33 , V_7 +
V_10 ) ;
else
F_3 ( V_33 , V_5 + V_9 ) ;
F_38 ( V_23 , V_60 ) ;
if ( V_33 == V_4 ) {
F_39 ( V_23 ) ;
F_22 ( V_23 , & V_61 ,
V_62 ) ;
} else {
F_22 ( V_23 , & V_61 ,
V_63 ) ;
}
F_23 ( V_23 , V_36 | V_64 ) ;
return 0 ;
}
void F_40 ( const struct V_51 * V_65 , unsigned int V_30 )
{
int V_57 ;
unsigned long V_66 = 0 ;
F_32 (cpu, mask)
V_66 |= 1 << F_33 ( V_57 ) ;
F_41 () ;
F_3 ( ( V_66 << 8 ) | V_30 , V_5 +
V_42 ) ;
}
void F_42 ( void )
{
F_3 ( 0 , V_7 + V_67 ) ;
F_3 ( V_68 , V_7 +
V_49 ) ;
F_3 ( 0 , V_7 + V_10 ) ;
}
static T_4 void T_5
F_43 ( struct V_69 * V_70 )
{
T_3 V_71 , V_72 ;
do {
V_71 = F_44 ( V_7 +
V_73 ) ;
V_72 = V_71 & 0x3FF ;
if ( V_72 > 1022 )
break;
if ( V_72 > 1 ) {
V_72 = F_45 ( V_74 ,
V_72 ) ;
F_46 ( V_72 , V_70 ) ;
continue;
}
#ifdef F_47
if ( V_72 == 1 ) {
T_3 V_75 , V_76 ;
V_75 = F_44 ( V_7 +
V_67 )
& V_50 ;
F_3 ( ~ V_50 , V_7 +
V_67 ) ;
for ( V_76 = V_77 ;
V_76 < V_78 ; V_76 ++ ) {
int V_30 ;
if ( ! ( V_75 & F_48 ( V_76 ) ) )
continue;
V_30 = F_45 ( V_24 ,
V_76 - 16 ) ;
F_46 ( V_30 , V_70 ) ;
}
}
#endif
#ifdef F_49
if ( V_72 == 0 ) {
T_3 V_79 , V_80 ;
V_79 = F_44 ( V_7 +
V_67 )
& V_68 ;
F_3 ( ~ V_68 , V_7 +
V_67 ) ;
for ( V_80 = V_81 ;
V_80 < V_82 ; V_80 ++ ) {
if ( V_79 & ( 0x1 << V_80 ) )
F_50 ( V_80 , V_70 ) ;
}
continue;
}
#endif
} while ( 1 );
}
static int T_6 F_51 ( struct V_37 * V_38 ,
struct V_37 * V_83 )
{
struct V_84 V_85 , V_86 ;
T_3 V_87 ;
F_52 ( F_53 ( V_38 , 0 , & V_85 ) ) ;
F_52 ( F_53 ( V_38 , 1 , & V_86 ) ) ;
F_52 ( ! F_54 ( V_85 . V_88 ,
F_55 ( & V_85 ) ,
V_38 -> V_89 ) ) ;
F_52 ( ! F_54 ( V_86 . V_88 ,
F_55 ( & V_86 ) ,
V_38 -> V_89 ) ) ;
V_5 = F_56 ( V_85 . V_88 ,
F_55 ( & V_85 ) ) ;
F_52 ( ! V_5 ) ;
V_7 = F_56 ( V_86 . V_88 ,
F_55 ( & V_86 ) ) ;
F_52 ( ! V_7 ) ;
V_87 = F_30 ( V_5 + V_90 ) ;
V_74 =
F_26 ( V_38 , ( V_87 >> 2 ) & 0x3ff ,
& V_91 , NULL ) ;
F_52 ( ! V_74 ) ;
F_57 ( V_74 ) ;
#ifdef F_49
F_42 () ;
F_58 ( V_92 ) ;
F_59 ( F_60 () , V_92 ) ;
#endif
F_24 ( V_38 , V_85 . V_88 ) ;
F_61 ( F_43 ) ;
return 0 ;
}
