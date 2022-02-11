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
return F_4 ( & V_6 ) ;
}
T_1 void F_5 ( T_2 struct V_1 V_2 )
{
struct V_9 T_4 * V_10 ;
T_7 V_11 ;
T_6 V_12 ;
T_8 V_13 ;
T_9 V_14 ;
int V_15 ;
V_10 = (struct V_9 T_4 * ) V_2 . V_2 [ 29 ] ;
if ( ! F_6 ( V_16 , V_10 , sizeof( * V_10 ) ) )
goto V_17;
if ( F_7 ( & V_12 , & V_10 -> V_18 . V_19 ) )
goto V_17;
F_8 ( & V_12 ) ;
V_15 = F_9 ( & V_2 , & V_10 -> V_18 . V_20 ) ;
if ( V_15 < 0 )
goto V_17;
else if ( V_15 )
F_10 ( V_15 , V_21 ) ;
if ( F_11 ( V_14 , & V_10 -> V_18 . V_22 . V_23 ) )
goto V_17;
V_13 . V_23 = ( void T_4 * ) ( long ) V_14 ;
if ( F_11 ( V_13 . V_24 , & V_10 -> V_18 . V_22 . V_24 ) )
goto V_17;
if ( F_11 ( V_13 . V_25 , & V_10 -> V_18 . V_22 . V_25 ) )
goto V_17;
V_11 = F_12 () ;
F_13 ( V_26 ) ;
F_14 ( ( T_8 T_4 * ) & V_13 , NULL , V_2 . V_2 [ 29 ] ) ;
F_13 ( V_11 ) ;
__asm__ __volatile__(
"move\t$29, %0\n\t"
"j\tsyscall_exit"
:
:"r" (&regs));
V_17:
F_10 ( V_27 , V_21 ) ;
}
static int F_15 ( void * V_28 , struct V_29 * V_30 ,
struct V_1 * V_2 , int V_31 , T_6 * V_12 , T_10 * V_32 )
{
struct V_9 T_4 * V_10 ;
int V_33 = 0 ;
T_9 V_14 ;
V_10 = F_16 ( V_30 , V_2 , sizeof( * V_10 ) ) ;
if ( ! F_6 ( V_34 , V_10 , sizeof ( * V_10 ) ) )
goto V_35;
V_33 |= F_17 ( & V_10 -> V_36 , V_32 ) ;
V_33 |= F_18 ( 0 , & V_10 -> V_18 . V_37 ) ;
V_33 |= F_18 ( 0 , & V_10 -> V_18 . V_38 ) ;
V_14 = ( int ) ( long ) V_21 -> V_39 ;
V_33 |= F_18 ( V_14 ,
& V_10 -> V_18 . V_22 . V_23 ) ;
V_33 |= F_18 ( F_19 ( V_2 -> V_2 [ 29 ] ) ,
& V_10 -> V_18 . V_22 . V_25 ) ;
V_33 |= F_18 ( V_21 -> V_40 ,
& V_10 -> V_18 . V_22 . V_24 ) ;
V_33 |= F_20 ( V_2 , & V_10 -> V_18 . V_20 ) ;
V_33 |= F_21 ( & V_10 -> V_18 . V_19 , V_12 ) ;
if ( V_33 )
goto V_35;
V_2 -> V_2 [ 4 ] = V_31 ;
V_2 -> V_2 [ 5 ] = ( unsigned long ) & V_10 -> V_36 ;
V_2 -> V_2 [ 6 ] = ( unsigned long ) & V_10 -> V_18 ;
V_2 -> V_2 [ 29 ] = ( unsigned long ) V_10 ;
V_2 -> V_2 [ 31 ] = ( unsigned long ) V_28 ;
V_2 -> V_41 = V_2 -> V_2 [ 25 ] = ( unsigned long ) V_30 -> V_42 . V_43 ;
F_22 ( L_1 ,
V_21 -> V_44 , V_21 -> V_45 ,
V_10 , V_2 -> V_41 , V_2 -> V_2 [ 31 ] ) ;
return 0 ;
V_35:
F_23 ( V_31 , V_21 ) ;
return - V_8 ;
}
