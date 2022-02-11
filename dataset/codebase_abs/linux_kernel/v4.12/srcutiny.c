static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 [ 0 ] = 0 ;
V_2 -> V_3 [ 1 ] = 0 ;
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = 0 ;
F_3 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = false ;
V_2 -> V_8 = false ;
V_2 -> V_9 = 0 ;
F_4 ( & V_2 -> V_10 , V_11 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , const char * V_12 ,
struct V_13 * V_14 )
{
F_6 ( ( void * ) V_2 , sizeof( * V_2 ) ) ;
F_7 ( & V_2 -> V_15 , V_12 , V_14 , 0 ) ;
return F_1 ( V_2 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_3 [ 0 ] || V_2 -> V_3 [ 1 ] ) ;
F_11 ( & V_2 -> V_10 ) ;
F_10 ( F_12 ( V_2 -> V_5 ) ) ;
F_10 ( V_2 -> V_7 ) ;
F_10 ( V_2 -> V_8 ) ;
F_10 ( ! F_13 ( & V_2 -> V_6 ) ) ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_16 ;
V_16 = F_15 ( V_2 -> V_9 ) ;
F_16 ( V_2 -> V_3 [ V_16 ] , V_2 -> V_3 [ V_16 ] + 1 ) ;
return V_16 ;
}
void F_17 ( struct V_1 * V_2 , int V_16 )
{
int V_17 = V_2 -> V_3 [ V_16 ] - 1 ;
F_16 ( V_2 -> V_3 [ V_16 ] , V_17 ) ;
if ( ! V_17 && F_15 ( V_2 -> V_8 ) )
F_18 ( & V_2 -> V_4 ) ;
}
void V_11 ( struct V_18 * V_19 )
{
int V_16 ;
struct V_20 V_21 ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
V_2 = F_19 ( V_19 , struct V_1 , V_10 ) ;
if ( V_2 -> V_7 || F_13 ( & V_2 -> V_6 ) )
return;
F_16 ( V_2 -> V_7 , true ) ;
F_20 ( & V_2 -> V_6 ,
F_21 ( & V_2 -> V_5 ) ) ;
F_22 ( & V_2 -> V_5 ) ;
V_16 = V_2 -> V_9 ;
F_16 ( V_2 -> V_9 , ! V_2 -> V_9 ) ;
F_16 ( V_2 -> V_8 , true ) ;
F_23 ( V_2 -> V_4 , ! F_15 ( V_2 -> V_3 [ V_16 ] ) ) ;
F_16 ( V_2 -> V_8 , false ) ;
F_24 ( & V_2 -> V_5 ) ;
F_25 ( & V_2 -> V_6 ,
F_26 ( & V_2 -> V_5 ) ) ;
if ( F_27 ( & V_2 -> V_6 ) ) {
F_28 ( & V_21 ) ;
F_29 () ;
F_30 ( & V_2 -> V_6 , & V_21 ) ;
F_31 () ;
V_23 = F_32 ( & V_21 ) ;
for (; V_23 != NULL ; V_23 = F_32 ( & V_21 ) ) {
F_33 () ;
V_23 -> V_24 ( V_23 ) ;
F_34 () ;
}
F_29 () ;
F_35 ( & V_2 -> V_6 , & V_21 ) ;
F_31 () ;
}
F_16 ( V_2 -> V_7 , false ) ;
if ( ! F_13 ( & V_2 -> V_6 ) )
F_36 ( & V_2 -> V_10 ) ;
}
void F_37 ( struct V_1 * V_2 , struct V_22 * V_25 ,
T_1 V_24 )
{
unsigned long V_26 ;
V_25 -> V_24 = V_24 ;
F_38 ( V_26 ) ;
F_39 ( & V_2 -> V_6 , V_25 , false ) ;
F_40 ( V_26 ) ;
if ( ! F_15 ( V_2 -> V_7 ) )
F_36 ( & V_2 -> V_10 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_27 V_28 ;
F_42 ( & V_28 . V_25 ) ;
F_43 ( & V_28 . V_29 ) ;
F_37 ( V_2 , & V_28 . V_25 , V_30 ) ;
F_44 ( & V_28 . V_29 ) ;
F_45 ( & V_28 . V_25 ) ;
}
