T_1 void F_1 ( T_2 struct V_1 V_2 )
{
struct V_3 T_3 * V_4 ;
T_4 V_5 ;
int V_6 ;
V_4 = (struct V_3 T_3 * ) V_2 . V_2 [ 29 ] ;
if ( ! F_2 ( V_7 , V_4 , sizeof( * V_4 ) ) )
goto V_8;
if ( F_3 ( & V_5 , & V_4 -> V_9 . V_10 ) )
goto V_8;
F_4 ( & V_5 ) ;
V_6 = F_5 ( & V_2 , & V_4 -> V_9 . V_11 ) ;
if ( V_6 < 0 )
goto V_8;
else if ( V_6 )
F_6 ( V_6 , V_12 ) ;
if ( F_7 ( & V_4 -> V_9 . V_13 ) )
goto V_8;
__asm__ __volatile__(
"move\t$29, %0\n\t"
"j\tsyscall_exit"
:
:"r" (&regs));
V_8:
F_6 ( V_14 , V_12 ) ;
}
static int F_8 ( void * V_15 , struct V_16 * V_17 ,
struct V_1 * V_2 , T_4 * V_5 )
{
struct V_3 T_3 * V_4 ;
int V_18 = 0 ;
V_4 = F_9 ( V_17 , V_2 , sizeof( * V_4 ) ) ;
if ( ! F_2 ( V_19 , V_4 , sizeof ( * V_4 ) ) )
return - V_20 ;
V_18 |= F_10 ( & V_4 -> V_21 , & V_17 -> V_22 ) ;
V_18 |= F_11 ( 0 , & V_4 -> V_9 . V_23 ) ;
V_18 |= F_11 ( 0 , & V_4 -> V_9 . V_24 ) ;
V_18 |= F_12 ( & V_4 -> V_9 . V_13 , V_2 -> V_2 [ 29 ] ) ;
V_18 |= F_13 ( V_2 , & V_4 -> V_9 . V_11 ) ;
V_18 |= F_14 ( & V_4 -> V_9 . V_10 , V_5 ) ;
if ( V_18 )
return - V_20 ;
V_2 -> V_2 [ 4 ] = V_17 -> V_6 ;
V_2 -> V_2 [ 5 ] = ( unsigned long ) & V_4 -> V_21 ;
V_2 -> V_2 [ 6 ] = ( unsigned long ) & V_4 -> V_9 ;
V_2 -> V_2 [ 29 ] = ( unsigned long ) V_4 ;
V_2 -> V_2 [ 31 ] = ( unsigned long ) V_15 ;
V_2 -> V_25 = V_2 -> V_2 [ 25 ] = ( unsigned long ) V_17 -> V_26 . V_27 . V_28 ;
F_15 ( L_1 ,
V_12 -> V_29 , V_12 -> V_30 ,
V_4 , V_2 -> V_25 , V_2 -> V_2 [ 31 ] ) ;
return 0 ;
}
