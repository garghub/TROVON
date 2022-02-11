T_1 int F_1 ( T_2 struct V_1 V_2 )
{
T_3 T_4 * V_3 ;
T_3 V_4 ;
T_5 V_5 ;
T_6 V_6 ;
V_5 = V_2 . V_2 [ 5 ] ;
if ( V_5 != sizeof( T_6 ) )
return - V_7 ;
V_3 = ( T_3 T_4 * ) V_2 . V_2 [ 4 ] ;
if ( F_2 ( & V_4 , V_3 , sizeof( V_4 ) ) )
return - V_8 ;
F_3 ( & V_6 , & V_4 ) ;
F_4 ( & V_6 , ~ V_9 ) ;
V_10 -> V_11 = V_10 -> V_12 ;
F_5 ( & V_6 ) ;
V_10 -> V_13 = V_14 ;
F_6 () ;
F_7 ( V_15 ) ;
return - V_16 ;
}
T_1 void F_8 ( T_2 struct V_1 V_2 )
{
struct V_17 T_4 * V_18 ;
T_7 V_19 ;
T_6 V_20 ;
T_8 V_21 ;
T_9 V_22 ;
int V_23 ;
V_18 = (struct V_17 T_4 * ) V_2 . V_2 [ 29 ] ;
if ( ! F_9 ( V_24 , V_18 , sizeof( * V_18 ) ) )
goto V_25;
if ( F_10 ( & V_20 , & V_18 -> V_26 . V_27 ) )
goto V_25;
F_4 ( & V_20 , ~ V_9 ) ;
F_5 ( & V_20 ) ;
V_23 = F_11 ( & V_2 , & V_18 -> V_26 . V_28 ) ;
if ( V_23 < 0 )
goto V_25;
else if ( V_23 )
F_12 ( V_23 , V_10 ) ;
if ( F_13 ( V_22 , & V_18 -> V_26 . V_29 . V_30 ) )
goto V_25;
V_21 . V_30 = ( void T_4 * ) ( long ) V_22 ;
if ( F_13 ( V_21 . V_31 , & V_18 -> V_26 . V_29 . V_31 ) )
goto V_25;
if ( F_13 ( V_21 . V_32 , & V_18 -> V_26 . V_29 . V_32 ) )
goto V_25;
V_19 = F_14 () ;
F_15 ( V_33 ) ;
F_16 ( ( T_8 T_4 * ) & V_21 , NULL , V_2 . V_2 [ 29 ] ) ;
F_15 ( V_19 ) ;
__asm__ __volatile__(
"move\t$29, %0\n\t"
"j\tsyscall_exit"
:
:"r" (&regs));
V_25:
F_12 ( V_34 , V_10 ) ;
}
static int F_17 ( void * V_35 , struct V_36 * V_37 ,
struct V_1 * V_2 , int V_38 , T_6 * V_20 , T_10 * V_39 )
{
struct V_17 T_4 * V_18 ;
int V_40 = 0 ;
T_9 V_22 ;
V_18 = F_18 ( V_37 , V_2 , sizeof( * V_18 ) ) ;
if ( ! F_9 ( V_41 , V_18 , sizeof ( * V_18 ) ) )
goto V_42;
V_40 |= F_19 ( & V_18 -> V_43 , V_39 ) ;
V_40 |= F_20 ( 0 , & V_18 -> V_26 . V_44 ) ;
V_40 |= F_20 ( 0 , & V_18 -> V_26 . V_45 ) ;
V_22 = ( int ) ( long ) V_10 -> V_46 ;
V_40 |= F_20 ( V_22 ,
& V_18 -> V_26 . V_29 . V_30 ) ;
V_40 |= F_20 ( F_21 ( V_2 -> V_2 [ 29 ] ) ,
& V_18 -> V_26 . V_29 . V_32 ) ;
V_40 |= F_20 ( V_10 -> V_47 ,
& V_18 -> V_26 . V_29 . V_31 ) ;
V_40 |= F_22 ( V_2 , & V_18 -> V_26 . V_28 ) ;
V_40 |= F_23 ( & V_18 -> V_26 . V_27 , V_20 ) ;
if ( V_40 )
goto V_42;
V_2 -> V_2 [ 4 ] = V_38 ;
V_2 -> V_2 [ 5 ] = ( unsigned long ) & V_18 -> V_43 ;
V_2 -> V_2 [ 6 ] = ( unsigned long ) & V_18 -> V_26 ;
V_2 -> V_2 [ 29 ] = ( unsigned long ) V_18 ;
V_2 -> V_2 [ 31 ] = ( unsigned long ) V_35 ;
V_2 -> V_48 = V_2 -> V_2 [ 25 ] = ( unsigned long ) V_37 -> V_49 . V_50 ;
F_24 ( L_1 ,
V_10 -> V_51 , V_10 -> V_52 ,
V_18 , V_2 -> V_48 , V_2 -> V_2 [ 31 ] ) ;
return 0 ;
V_42:
F_25 ( V_38 , V_10 ) ;
return - V_8 ;
}
