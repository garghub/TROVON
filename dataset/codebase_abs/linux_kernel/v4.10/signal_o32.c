static int F_1 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
int V_5 = 0 ;
int V_6 ;
V_5 |= F_2 ( V_2 -> V_7 , & V_4 -> V_8 ) ;
V_5 |= F_2 ( 0 , & V_4 -> V_9 [ 0 ] ) ;
for ( V_6 = 1 ; V_6 < 32 ; V_6 ++ )
V_5 |= F_2 ( V_2 -> V_2 [ V_6 ] , & V_4 -> V_9 [ V_6 ] ) ;
V_5 |= F_2 ( V_2 -> V_10 , & V_4 -> V_11 ) ;
V_5 |= F_2 ( V_2 -> V_12 , & V_4 -> V_13 ) ;
if ( V_14 ) {
V_5 |= F_2 ( F_3 ( V_15 ) , & V_4 -> V_16 ) ;
V_5 |= F_2 ( F_4 () , & V_4 -> V_17 ) ;
V_5 |= F_2 ( F_5 () , & V_4 -> V_18 ) ;
V_5 |= F_2 ( F_6 () , & V_4 -> V_19 ) ;
V_5 |= F_2 ( F_7 () , & V_4 -> V_20 ) ;
V_5 |= F_2 ( F_8 () , & V_4 -> V_21 ) ;
V_5 |= F_2 ( F_9 () , & V_4 -> V_22 ) ;
}
V_5 |= F_10 ( V_4 ) ;
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
int V_5 = 0 ;
T_2 V_23 ;
int V_6 ;
V_24 -> V_25 . V_26 = V_27 ;
V_5 |= F_12 ( V_2 -> V_7 , & V_4 -> V_8 ) ;
V_5 |= F_12 ( V_2 -> V_10 , & V_4 -> V_11 ) ;
V_5 |= F_12 ( V_2 -> V_12 , & V_4 -> V_13 ) ;
if ( V_14 ) {
V_5 |= F_12 ( V_23 , & V_4 -> V_17 ) ; F_13 ( V_23 ) ;
V_5 |= F_12 ( V_23 , & V_4 -> V_18 ) ; F_14 ( V_23 ) ;
V_5 |= F_12 ( V_23 , & V_4 -> V_19 ) ; F_15 ( V_23 ) ;
V_5 |= F_12 ( V_23 , & V_4 -> V_20 ) ; F_16 ( V_23 ) ;
V_5 |= F_12 ( V_23 , & V_4 -> V_21 ) ; F_17 ( V_23 ) ;
V_5 |= F_12 ( V_23 , & V_4 -> V_22 ) ; F_18 ( V_23 ) ;
V_5 |= F_12 ( V_23 , & V_4 -> V_16 ) ; F_19 ( V_23 , V_15 ) ;
}
for ( V_6 = 1 ; V_6 < 32 ; V_6 ++ )
V_5 |= F_12 ( V_2 -> V_2 [ V_6 ] , & V_4 -> V_9 [ V_6 ] ) ;
return V_5 ? : F_20 ( V_4 ) ;
}
static int F_21 ( void * V_28 , struct V_29 * V_30 ,
struct V_1 * V_2 , T_3 * V_31 )
{
struct V_32 T_1 * V_33 ;
int V_5 = 0 ;
V_33 = F_22 ( V_30 , V_2 , sizeof( * V_33 ) ) ;
if ( ! F_23 ( V_34 , V_33 , sizeof ( * V_33 ) ) )
return - V_35 ;
V_5 |= F_1 ( V_2 , & V_33 -> V_36 ) ;
V_5 |= F_24 ( & V_33 -> V_37 , V_31 ) ;
if ( V_5 )
return - V_35 ;
V_2 -> V_2 [ 4 ] = V_30 -> V_38 ;
V_2 -> V_2 [ 5 ] = 0 ;
V_2 -> V_2 [ 6 ] = ( unsigned long ) & V_33 -> V_36 ;
V_2 -> V_2 [ 29 ] = ( unsigned long ) V_33 ;
V_2 -> V_2 [ 31 ] = ( unsigned long ) V_28 ;
V_2 -> V_7 = V_2 -> V_2 [ 25 ] = ( unsigned long ) V_30 -> V_39 . V_40 . V_41 ;
F_25 ( L_1 ,
V_24 -> V_42 , V_24 -> V_43 ,
V_33 , V_2 -> V_7 , V_2 -> V_2 [ 31 ] ) ;
return 0 ;
}
T_4 void F_26 ( T_5 struct V_1 V_2 )
{
struct V_44 T_1 * V_33 ;
T_3 V_31 ;
int V_38 ;
V_33 = (struct V_44 T_1 * ) V_2 . V_2 [ 29 ] ;
if ( ! F_23 ( V_45 , V_33 , sizeof( * V_33 ) ) )
goto V_46;
if ( F_27 ( & V_31 , & V_33 -> V_47 . V_48 ) )
goto V_46;
F_28 ( & V_31 ) ;
V_38 = F_11 ( & V_2 , & V_33 -> V_47 . V_49 ) ;
if ( V_38 < 0 )
goto V_46;
else if ( V_38 )
F_29 ( V_38 , V_24 ) ;
if ( F_30 ( & V_33 -> V_47 . V_50 ) )
goto V_46;
__asm__ __volatile__(
"move\t$29, %0\n\t"
"j\tsyscall_exit"
:
:"r" (&regs));
V_46:
F_29 ( V_51 , V_24 ) ;
}
static int F_31 ( void * V_28 , struct V_29 * V_30 ,
struct V_1 * V_2 , T_3 * V_31 )
{
struct V_44 T_1 * V_33 ;
int V_5 = 0 ;
V_33 = F_22 ( V_30 , V_2 , sizeof( * V_33 ) ) ;
if ( ! F_23 ( V_34 , V_33 , sizeof ( * V_33 ) ) )
return - V_35 ;
V_5 |= F_32 ( & V_33 -> V_52 , & V_30 -> V_53 ) ;
V_5 |= F_2 ( 0 , & V_33 -> V_47 . V_54 ) ;
V_5 |= F_2 ( 0 , & V_33 -> V_47 . V_55 ) ;
V_5 |= F_33 ( & V_33 -> V_47 . V_50 , V_2 -> V_2 [ 29 ] ) ;
V_5 |= F_1 ( V_2 , & V_33 -> V_47 . V_49 ) ;
V_5 |= F_24 ( & V_33 -> V_47 . V_48 , V_31 ) ;
if ( V_5 )
return - V_35 ;
V_2 -> V_2 [ 4 ] = V_30 -> V_38 ;
V_2 -> V_2 [ 5 ] = ( unsigned long ) & V_33 -> V_52 ;
V_2 -> V_2 [ 6 ] = ( unsigned long ) & V_33 -> V_47 ;
V_2 -> V_2 [ 29 ] = ( unsigned long ) V_33 ;
V_2 -> V_2 [ 31 ] = ( unsigned long ) V_28 ;
V_2 -> V_7 = V_2 -> V_2 [ 25 ] = ( unsigned long ) V_30 -> V_39 . V_40 . V_41 ;
F_25 ( L_1 ,
V_24 -> V_42 , V_24 -> V_43 ,
V_33 , V_2 -> V_7 , V_2 -> V_2 [ 31 ] ) ;
return 0 ;
}
T_4 void F_34 ( T_5 struct V_1 V_2 )
{
struct V_32 T_1 * V_33 ;
T_3 V_56 ;
int V_38 ;
V_33 = (struct V_32 T_1 * ) V_2 . V_2 [ 29 ] ;
if ( ! F_23 ( V_45 , V_33 , sizeof( * V_33 ) ) )
goto V_46;
if ( F_27 ( & V_56 , & V_33 -> V_37 ) )
goto V_46;
F_28 ( & V_56 ) ;
V_38 = F_11 ( & V_2 , & V_33 -> V_36 ) ;
if ( V_38 < 0 )
goto V_46;
else if ( V_38 )
F_29 ( V_38 , V_24 ) ;
__asm__ __volatile__(
"move\t$29, %0\n\t"
"j\tsyscall_exit"
:
:"r" (&regs));
V_46:
F_29 ( V_51 , V_24 ) ;
}
