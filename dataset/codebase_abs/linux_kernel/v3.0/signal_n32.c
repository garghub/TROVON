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
F_5 ( & V_10 -> V_11 -> V_12 ) ;
V_10 -> V_13 = V_10 -> V_14 ;
V_10 -> V_14 = V_6 ;
F_6 () ;
F_7 ( & V_10 -> V_11 -> V_12 ) ;
V_10 -> V_15 = V_16 ;
F_8 () ;
F_9 ( V_17 ) ;
return - V_18 ;
}
T_1 void F_10 ( T_2 struct V_1 V_2 )
{
struct V_19 T_4 * V_20 ;
T_7 V_21 ;
T_6 V_22 ;
T_8 V_23 ;
T_9 V_24 ;
int V_25 ;
V_20 = (struct V_19 T_4 * ) V_2 . V_2 [ 29 ] ;
if ( ! F_11 ( V_26 , V_20 , sizeof( * V_20 ) ) )
goto V_27;
if ( F_12 ( & V_22 , & V_20 -> V_28 . V_29 ) )
goto V_27;
F_4 ( & V_22 , ~ V_9 ) ;
F_5 ( & V_10 -> V_11 -> V_12 ) ;
V_10 -> V_14 = V_22 ;
F_6 () ;
F_7 ( & V_10 -> V_11 -> V_12 ) ;
V_25 = F_13 ( & V_2 , & V_20 -> V_28 . V_30 ) ;
if ( V_25 < 0 )
goto V_27;
else if ( V_25 )
F_14 ( V_25 , V_10 ) ;
if ( F_15 ( V_24 , & V_20 -> V_28 . V_31 . V_32 ) )
goto V_27;
V_23 . V_32 = ( void T_4 * ) ( long ) V_24 ;
if ( F_15 ( V_23 . V_33 , & V_20 -> V_28 . V_31 . V_33 ) )
goto V_27;
if ( F_15 ( V_23 . V_34 , & V_20 -> V_28 . V_31 . V_34 ) )
goto V_27;
V_21 = F_16 () ;
F_17 ( V_35 ) ;
F_18 ( ( T_8 T_4 * ) & V_23 , NULL , V_2 . V_2 [ 29 ] ) ;
F_17 ( V_21 ) ;
__asm__ __volatile__(
"move\t$29, %0\n\t"
"j\tsyscall_exit"
:
:"r" (&regs));
V_27:
F_14 ( V_36 , V_10 ) ;
}
static int F_19 ( void * V_37 , struct V_38 * V_39 ,
struct V_1 * V_2 , int V_40 , T_6 * V_22 , T_10 * V_41 )
{
struct V_19 T_4 * V_20 ;
int V_42 = 0 ;
T_9 V_24 ;
V_20 = F_20 ( V_39 , V_2 , sizeof( * V_20 ) ) ;
if ( ! F_11 ( V_43 , V_20 , sizeof ( * V_20 ) ) )
goto V_44;
V_42 |= F_21 ( & V_20 -> V_45 , V_41 ) ;
V_42 |= F_22 ( 0 , & V_20 -> V_28 . V_46 ) ;
V_42 |= F_22 ( 0 , & V_20 -> V_28 . V_47 ) ;
V_24 = ( int ) ( long ) V_10 -> V_48 ;
V_42 |= F_22 ( V_24 ,
& V_20 -> V_28 . V_31 . V_32 ) ;
V_42 |= F_22 ( F_23 ( V_2 -> V_2 [ 29 ] ) ,
& V_20 -> V_28 . V_31 . V_34 ) ;
V_42 |= F_22 ( V_10 -> V_49 ,
& V_20 -> V_28 . V_31 . V_33 ) ;
V_42 |= F_24 ( V_2 , & V_20 -> V_28 . V_30 ) ;
V_42 |= F_25 ( & V_20 -> V_28 . V_29 , V_22 ) ;
if ( V_42 )
goto V_44;
V_2 -> V_2 [ 4 ] = V_40 ;
V_2 -> V_2 [ 5 ] = ( unsigned long ) & V_20 -> V_45 ;
V_2 -> V_2 [ 6 ] = ( unsigned long ) & V_20 -> V_28 ;
V_2 -> V_2 [ 29 ] = ( unsigned long ) V_20 ;
V_2 -> V_2 [ 31 ] = ( unsigned long ) V_37 ;
V_2 -> V_50 = V_2 -> V_2 [ 25 ] = ( unsigned long ) V_39 -> V_51 . V_52 ;
F_26 ( L_1 ,
V_10 -> V_53 , V_10 -> V_54 ,
V_20 , V_2 -> V_50 , V_2 -> V_2 [ 31 ] ) ;
return 0 ;
V_44:
F_27 ( V_40 , V_10 ) ;
return - V_8 ;
}
