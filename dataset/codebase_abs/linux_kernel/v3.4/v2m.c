static void T_1 F_1 ( void T_2 * V_1 )
{
T_3 V_2 ;
if ( F_2 ( ! V_1 ) )
return;
V_2 = F_3 ( V_1 + V_3 ) ;
V_2 |= V_4 ;
V_2 |= V_5 ;
F_4 ( V_2 , V_1 + V_3 ) ;
}
static void T_1 F_5 ( void T_2 * V_1 , unsigned int V_6 )
{
if ( F_2 ( ! V_1 || V_6 == V_7 ) )
return;
F_4 ( 0 , V_1 + V_8 + V_9 ) ;
F_4 ( 0 , V_1 + V_10 + V_9 ) ;
F_6 ( V_1 + V_10 , L_1 ) ;
F_7 ( V_1 + V_8 , V_6 , L_2 ) ;
}
static void T_1 F_8 ( void )
{
F_1 ( F_9 ( V_11 , V_12 ) ) ;
F_5 ( F_9 ( V_13 , V_12 ) , V_14 ) ;
}
int F_10 ( T_3 V_15 , T_3 V_16 )
{
T_3 V_17 ;
F_11 ( L_3 , V_18 , V_16 , V_15 ) ;
V_15 |= V_19 | V_20 ;
F_12 ( & V_21 ) ;
V_17 = F_3 ( V_22 + V_23 ) ;
F_4 ( V_17 & ~ V_24 , V_22 + V_23 ) ;
F_4 ( V_16 , V_22 + V_25 ) ;
F_4 ( V_15 , V_22 + V_26 ) ;
do {
V_17 = F_3 ( V_22 + V_23 ) ;
} while ( V_17 == 0 );
F_13 ( & V_21 ) ;
return ! ! ( V_17 & V_27 ) ;
}
int F_14 ( T_3 V_15 , T_3 * V_16 )
{
T_3 V_17 ;
V_15 |= V_19 ;
F_12 ( & V_21 ) ;
F_4 ( 0 , V_22 + V_23 ) ;
F_4 ( V_15 , V_22 + V_26 ) ;
F_15 () ;
do {
F_16 () ;
V_17 = F_3 ( V_22 + V_23 ) ;
} while ( V_17 == 0 );
* V_16 = F_3 ( V_22 + V_25 ) ;
F_13 ( & V_21 ) ;
return ! ! ( V_17 & V_27 ) ;
}
void T_1 F_17 ( T_3 V_16 )
{
F_4 ( ~ 0 , V_22 + V_28 ) ;
F_4 ( V_16 , V_22 + V_29 ) ;
}
static void F_18 ( struct V_30 * V_31 , int V_32 )
{
F_4 ( V_32 != 0 , V_22 + V_33 ) ;
}
static unsigned int F_19 ( struct V_34 * V_35 )
{
return F_3 ( V_22 + V_36 ) & ( 1 << 0 ) ;
}
static long F_20 ( struct V_37 * V_37 , unsigned long V_38 )
{
return V_38 ;
}
static int F_21 ( struct V_37 * V_37 , unsigned long V_38 )
{
return F_10 ( V_39 | V_40 | 1 , V_38 ) ;
}
static void T_1 F_22 ( void )
{
V_41 -> V_42 () ;
F_23 ( V_43 , F_24 ( V_43 ) ) ;
F_25 ( V_22 + V_44 , 24000000 ) ;
}
static void F_26 ( void )
{
if ( F_10 ( V_45 | V_40 , 0 ) )
F_11 ( V_46 L_4 ) ;
}
static void F_27 ( char V_47 , const char * V_48 )
{
if ( F_10 ( V_49 | V_40 , 0 ) )
F_11 ( V_46 L_5 ) ;
}
static void T_1 F_28 ( void )
{
int V_50 ;
T_3 V_51 ;
V_41 = NULL ;
V_51 = F_3 ( V_22 + V_52 )
& V_53 ;
for ( V_50 = 0 ; V_50 < F_24 ( V_54 ) && ! V_41 ; ++ V_50 )
if ( V_54 [ V_50 ] -> V_55 == V_51 )
V_41 = V_54 [ V_50 ] ;
if ( ! V_41 )
F_29 ( L_6
L_7 ,
V_51 ) ;
}
static void T_1 F_30 ( void )
{
F_31 ( V_56 , F_24 ( V_56 ) ) ;
V_22 = F_9 ( V_57 , V_12 ) ;
F_28 () ;
V_41 -> V_58 () ;
}
static void T_1 F_32 ( void )
{
V_41 -> V_59 () ;
}
static void T_1 F_33 ( void )
{
int V_50 ;
F_34 ( & V_60 ) ;
F_34 ( & V_61 ) ;
F_34 ( & V_62 ) ;
F_34 ( & V_63 ) ;
F_34 ( & V_64 ) ;
F_34 ( & V_65 ) ;
for ( V_50 = 0 ; V_50 < F_24 ( V_66 ) ; V_50 ++ )
F_35 ( V_66 [ V_50 ] , & V_67 ) ;
V_68 = F_26 ;
V_41 -> V_69 () ;
}
static int T_1 F_36 ( unsigned long V_70 , const char * V_71 ,
int V_72 , void * V_16 )
{
const char * * V_73 = V_16 ;
if ( strcmp ( V_71 , L_8 ) != 0 )
return 0 ;
* V_73 = F_37 ( V_70 , L_9 , NULL ) ;
return 1 ;
}
void T_1 F_38 ( void )
{
const char * V_73 = NULL ;
F_39 ( F_36 , & V_73 ) ;
if ( V_73 && strcmp ( V_73 , L_10 ) == 0 )
F_31 ( & V_74 , 1 ) ;
else
F_31 ( V_56 , F_24 ( V_56 ) ) ;
#if F_40 ( V_75 )
F_41 () ;
#endif
}
void T_1 F_42 ( void )
{
struct V_76 * V_70 ;
T_3 V_77 ;
V_70 = F_43 ( NULL , NULL , L_11 ) ;
V_22 = F_44 ( V_70 , 0 ) ;
if ( F_2 ( ! V_22 ) )
return;
if ( F_45 ( V_78 , L_12 , & V_77 ) == 0 ) {
T_3 V_79 = F_3 ( V_22 + V_80 ) ;
T_3 V_55 = F_3 ( V_22 + ( V_79 & V_81 ?
V_82 : V_52 ) ) ;
T_3 V_83 = V_55 & V_84 ;
if ( F_2 ( V_77 != V_83 ) )
F_46 ( L_13
L_14 , V_77 , V_83 ) ;
}
F_23 ( V_85 , F_24 ( V_85 ) ) ;
F_25 ( V_22 + V_44 , 24000000 ) ;
}
static void T_1 F_47 ( void )
{
F_48 ( V_86 ) ;
}
static void T_1 F_49 ( void )
{
struct V_76 * V_70 ;
const char * V_87 ;
int V_88 ;
V_70 = F_43 ( NULL , NULL , L_15 ) ;
F_1 ( F_44 ( V_70 , 0 ) ) ;
V_88 = F_50 ( V_89 , L_16 , & V_87 ) ;
if ( F_2 ( V_88 ) )
return;
V_70 = F_51 ( V_87 ) ;
F_5 ( F_44 ( V_70 , 0 ) , F_52 ( V_70 , 0 ) ) ;
}
static void T_1 F_53 ( void )
{
F_54 ( 0x00400000 , 0xfe0fffff ) ;
F_55 ( NULL , V_90 ,
V_91 , NULL ) ;
V_68 = F_26 ;
}
