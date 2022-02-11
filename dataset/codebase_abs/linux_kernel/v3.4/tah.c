int T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_5 ) ;
F_3 ( & V_5 -> V_6 ) ;
++ V_5 -> V_7 ;
F_4 ( & V_5 -> V_6 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_5 ) ;
F_3 ( & V_5 -> V_6 ) ;
-- V_5 -> V_7 ;
F_4 ( & V_5 -> V_6 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_5 ) ;
struct V_8 T_2 * V_9 = V_5 -> V_10 ;
int V_11 ;
F_7 ( & V_9 -> V_12 , V_13 ) ;
V_11 = 100 ;
while ( ( F_8 ( & V_9 -> V_12 ) & V_13 ) && V_11 )
-- V_11 ;
if ( F_9 ( ! V_11 ) )
F_10 ( V_14 L_1 ,
V_2 -> V_5 . V_15 -> V_16 ) ;
F_7 ( & V_9 -> V_12 ,
V_17 | V_18 | V_19 | V_20 |
V_21 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
return sizeof( struct V_22 ) +
sizeof( struct V_8 ) ;
}
void * F_12 ( struct V_1 * V_2 , void * V_23 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_5 ) ;
struct V_22 * V_24 = V_23 ;
struct V_8 * V_25 = (struct V_8 * ) ( V_24 + 1 ) ;
V_24 -> V_26 = 0 ;
V_24 -> V_27 = 0 ;
F_13 ( V_25 , V_5 -> V_10 , sizeof( struct V_8 ) ) ;
return V_25 + 1 ;
}
static int T_1 F_14 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_5 . V_15 ;
struct V_4 * V_5 ;
struct V_30 V_25 ;
int V_31 ;
V_31 = - V_32 ;
V_5 = F_15 ( sizeof( struct V_4 ) , V_33 ) ;
if ( V_5 == NULL )
goto V_34;
F_16 ( & V_5 -> V_6 ) ;
V_5 -> V_2 = V_2 ;
V_31 = - V_35 ;
if ( F_17 ( V_29 , 0 , & V_25 ) ) {
F_10 ( V_14 L_2 ,
V_29 -> V_16 ) ;
goto V_36;
}
V_31 = - V_32 ;
V_5 -> V_10 = (struct V_8 T_2 * ) F_18 ( V_25 . V_37 ,
sizeof( struct V_8 ) ) ;
if ( V_5 -> V_10 == NULL ) {
F_10 ( V_14 L_3 ,
V_29 -> V_16 ) ;
goto V_36;
}
F_19 ( & V_2 -> V_5 , V_5 ) ;
F_6 ( V_2 ) ;
F_10 ( V_38
L_4 , V_2 -> V_5 . V_15 -> V_16 ) ;
F_20 () ;
return 0 ;
V_36:
F_21 ( V_5 ) ;
V_34:
return V_31 ;
}
static int T_3 F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_5 ) ;
F_19 ( & V_2 -> V_5 , NULL ) ;
F_23 ( V_5 -> V_7 != 0 ) ;
F_24 ( V_5 -> V_10 ) ;
F_21 ( V_5 ) ;
return 0 ;
}
int T_4 F_25 ( void )
{
return F_26 ( & V_39 ) ;
}
void F_27 ( void )
{
F_28 ( & V_39 ) ;
}
