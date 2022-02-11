static void F_1 ( struct V_1 * V_2 )
{
char * * V_3 , * * V_4 ;
int V_5 = V_2 -> V_5 ;
int V_6 = V_2 -> V_6 ;
unsigned long V_7 ;
unsigned long * V_8 ;
V_8 = ( unsigned long * ) ( ( V_2 -> V_7 + 3 ) & ~ 3 ) ;
V_4 = ( char * * ) V_8 ;
V_8 += V_6 + 1 ;
V_3 = ( char * * ) V_8 ;
V_8 += V_5 + 1 ;
F_2 ( ( unsigned long ) V_4 , ++ V_8 ) ;
F_2 ( ( unsigned long ) V_3 , ++ V_8 ) ;
F_2 ( V_5 , ++ V_8 ) ;
V_2 -> V_7 = ( unsigned long ) V_8 ;
V_7 = V_9 -> V_10 -> V_11 ;
while ( V_5 -- > 0 ) {
F_2 ( ( char * ) V_7 , V_3 ++ ) ;
V_7 += F_3 ( ( char * ) V_7 ) ;
}
F_2 ( NULL , V_3 ) ;
V_9 -> V_10 -> V_12 = V_9 -> V_10 -> V_13 = V_7 ;
while ( V_6 -- > 0 ) {
F_2 ( ( char * ) V_7 , V_4 ++ ) ;
V_7 += F_3 ( ( char * ) V_7 ) ;
}
F_2 ( NULL , V_4 ) ;
V_9 -> V_10 -> V_14 = V_7 ;
}
static int F_4 ( struct V_15 * V_16 )
{
int * V_17 = ( int * ) V_16 ;
int V_18 , V_19 ;
if ( V_16 -> V_20 != V_21 &&
V_16 -> V_20 != V_22 &&
V_16 -> V_20 != V_23 )
return - V_24 ;
if ( V_16 -> V_25 != V_26 &&
V_16 -> V_25 != V_27 &&
V_16 -> V_25 != V_28 )
return - V_24 ;
if ( V_16 -> V_29 != V_30 &&
V_16 -> V_29 != V_31 )
return - V_24 ;
V_19 = 0 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ )
V_19 ^= V_17 [ V_18 ] ;
if ( V_19 != 0 )
return - V_24 ;
return 0 ;
}
static int F_5 ( struct V_32 * V_32 ,
const struct V_33 * V_34 )
{
unsigned long V_35 , V_36 , V_37 , V_38 ;
unsigned long V_39 , V_40 ;
int V_41 ;
int V_42 = V_43 | V_44 ;
int V_45 = V_46 | V_47 | V_48 | V_49 ;
T_1 V_50 = F_6 () ;
F_7 ( F_8 () ) ;
V_35 = F_9 ( V_34 -> V_51 ) ;
V_36 = F_10 ( V_34 -> V_52 ) ;
V_9 -> V_10 -> V_53 = V_35 ;
V_9 -> V_10 -> V_54 = V_35 + V_36 ;
V_41 = F_11 ( V_32 , V_35 , V_36 , V_42 ,
V_45 , F_9 ( V_34 -> V_55 ) ) ;
if ( V_41 < 0 && V_41 > - 1024 )
goto V_56;
V_37 = F_9 ( V_34 -> V_57 ) ;
V_38 = F_10 ( V_34 -> V_58 ) ;
V_9 -> V_10 -> V_59 = V_37 ;
V_9 -> V_10 -> V_60 = V_39 = V_37 + V_38 ;
V_41 = F_11 ( V_32 , V_37 , V_38 ,
V_42 | V_61 , V_45 ,
F_9 ( V_34 -> V_62 ) ) ;
if ( V_41 < 0 && V_41 > - 1024 )
goto V_56;
V_40 = V_39 + F_10 ( V_34 -> V_63 ) ;
V_9 -> V_10 -> V_64 = V_9 -> V_10 -> V_65 = V_40 ;
V_41 = F_11 ( NULL , V_39 , V_40 - V_39 ,
V_42 | V_61 , V_46 | V_47 , 0 ) ;
if ( V_41 > 0 || V_41 < - 1024 )
V_41 = 0 ;
V_56:
F_7 ( V_50 ) ;
return V_41 ;
}
static int
F_12 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
int V_41 ;
unsigned int V_68 ;
unsigned long V_69 ;
struct V_15 * V_16 ;
struct V_33 * V_34 ;
V_16 = (struct V_15 * ) V_2 -> V_17 ;
V_41 = F_4 ( V_16 ) ;
if ( V_41 != 0 )
goto V_56;
V_41 = - V_70 ;
V_68 = V_16 -> V_71 ;
if ( V_68 > V_72 )
goto V_56;
V_34 = F_13 ( V_68 , V_73 ) ;
if ( ! V_34 )
goto V_56;
V_41 = F_14 ( V_2 -> V_32 , V_16 -> V_74 ,
( char * ) V_34 , V_68 ) ;
if ( V_41 != V_68 ) {
if ( V_41 >= 0 )
V_41 = - V_75 ;
goto V_76;
}
V_41 = F_15 ( V_2 ) ;
if ( V_41 )
goto V_76;
V_9 -> V_77 = V_78 ;
F_16 ( V_2 ) ;
V_9 -> V_79 . V_80 = 0xc0000000 ;
V_9 -> V_79 . V_81 = 0x80000000 ;
V_41 = F_5 ( V_2 -> V_32 , V_34 ) ;
if ( V_41 < 0 )
goto V_76;
V_69 = V_34 -> V_82 ;
F_17 ( V_34 ) ;
F_18 ( & V_83 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 , V_84 , V_85 ) ;
F_1 ( V_2 ) ;
V_9 -> V_10 -> V_86 = V_2 -> V_7 ;
#if 0
printk("(start_brk) %08lx\n" , (unsigned long) current->mm->start_brk);
printk("(end_code) %08lx\n" , (unsigned long) current->mm->end_code);
printk("(start_code) %08lx\n" , (unsigned long) current->mm->start_code);
printk("(end_data) %08lx\n" , (unsigned long) current->mm->end_data);
printk("(start_stack) %08lx\n" , (unsigned long) current->mm->start_stack);
printk("(brk) %08lx\n" , (unsigned long) current->mm->brk);
#endif
F_21 ( V_9 , V_9 -> V_10 ) ;
F_22 ( V_67 , V_69 , V_2 -> V_7 ) ;
return 0 ;
V_76:
F_17 ( V_34 ) ;
V_56:
return V_41 ;
}
static int F_23 ( struct V_32 * V_87 )
{
return - V_24 ;
}
static int T_2 F_24 ( void )
{
F_25 ( & V_83 ) ;
return 0 ;
}
static void T_3 F_26 ( void )
{
F_27 ( & V_83 ) ;
}
