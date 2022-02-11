static inline int F_1 ( struct V_1 * V_1 )
{
return F_2 ( V_1 -> V_2 + V_3 ) &
V_4 ;
}
static inline int F_3 ( struct V_1 * V_1 , unsigned V_5 )
{
return ( 1U << ( 16 + V_5 ) ) / F_4 ( V_1 -> V_6 ) ;
}
static int F_5 ( struct V_1 * V_1 )
{
int V_5 = F_2 ( V_1 -> V_2 + V_7 ) & 0xF ;
return F_3 ( V_1 , V_5 ) ;
}
static int F_6 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_7 ( V_9 ) ;
F_8 ( V_10 , V_1 -> V_2 +
V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 , unsigned int V_12 )
{
struct V_1 * V_1 = F_7 ( V_9 ) ;
int V_13 , V_14 = V_15 ;
for ( V_13 = 0 ; V_13 <= V_15 ; ++ V_13 )
if ( F_3 ( V_1 , V_13 ) >= V_12 ) {
V_14 = V_13 ;
break;
}
F_8 ( V_14 | V_14 << V_16 ,
V_1 -> V_2 + V_7 ) ;
V_9 -> V_17 = F_3 ( V_1 , V_14 ) ;
return 0 ;
}
static int F_10 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_7 ( V_9 ) ;
F_9 ( V_9 , V_9 -> V_17 ) ;
F_11 ( V_18 , & V_9 -> V_19 ) ;
F_8 ( V_4 ,
V_1 -> V_2 + V_3 ) ;
return 0 ;
}
static int F_12 ( struct V_20 * V_21 ,
unsigned long V_22 , void * V_23 )
{
struct V_1 * V_1 ;
T_1 V_24 ;
V_1 = F_13 ( V_21 , struct V_1 , V_25 ) ;
F_8 ( 0 , V_1 -> V_2 + V_7 ) ;
V_24 = F_2 ( V_1 -> V_2 + V_3 ) ;
if ( V_24 & V_4 )
F_8 ( V_10 ,
V_1 -> V_2 + V_11 ) ;
else
F_8 ( V_4 ,
V_1 -> V_2 + V_3 ) ;
F_14 ( 500 ) ;
return V_26 ;
}
static unsigned int F_15 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_7 ( V_9 ) ;
return F_2 ( V_1 -> V_2 + V_27 ) /
F_4 ( V_1 -> V_6 ) ;
}
static int F_16 ( struct V_28 * V_29 )
{
struct V_1 * V_1 = F_17 ( V_29 ) ;
F_18 ( V_1 -> V_6 ) ;
return 0 ;
}
static int F_19 ( struct V_28 * V_29 )
{
struct V_1 * V_1 = F_17 ( V_29 ) ;
int V_30 = F_20 ( V_1 -> V_6 ) ;
if ( V_30 )
return V_30 ;
F_6 ( & V_1 -> V_9 ) ;
return 0 ;
}
static int F_21 ( struct V_31 * V_32 )
{
struct V_28 * V_29 = & V_32 -> V_29 ;
struct V_8 * V_9 ;
struct V_1 * V_1 ;
struct V_33 * V_34 ;
int V_35 ;
V_1 = F_22 ( V_29 , sizeof( * V_1 ) , V_36 ) ;
if ( ! V_1 )
return - V_37 ;
V_34 = F_23 ( V_32 , V_38 , 0 ) ;
V_1 -> V_2 = F_24 ( V_29 , V_34 ) ;
if ( F_25 ( V_1 -> V_2 ) )
return F_26 ( V_1 -> V_2 ) ;
V_1 -> V_6 = F_27 ( V_29 , NULL ) ;
if ( F_25 ( V_1 -> V_6 ) )
return F_26 ( V_1 -> V_6 ) ;
V_35 = F_20 ( V_1 -> V_6 ) ;
if ( V_35 )
return V_35 ;
V_9 = & V_1 -> V_9 ;
V_9 -> V_39 = & V_40 ;
V_9 -> V_41 = & V_42 ;
V_9 -> V_43 = 1 ;
V_9 -> V_44 =
F_3 ( V_1 , V_15 ) * 1000 ;
V_9 -> V_45 = V_29 ;
F_28 ( V_9 , V_1 ) ;
F_29 ( V_9 , V_46 ) ;
F_30 ( V_9 , 0 , V_29 ) ;
if ( F_1 ( V_1 ) ) {
V_9 -> V_17 = F_5 ( V_1 ) ;
F_11 ( V_18 , & V_9 -> V_19 ) ;
} else {
V_9 -> V_17 = V_47 ;
F_30 ( V_9 , 0 , V_29 ) ;
}
F_31 ( V_32 , V_1 ) ;
V_35 = F_32 ( V_9 ) ;
if ( V_35 )
goto V_48;
V_1 -> V_25 . V_49 = F_12 ;
V_1 -> V_25 . V_50 = 128 ;
V_35 = F_33 ( & V_1 -> V_25 ) ;
if ( V_35 )
F_34 ( L_1 ) ;
return 0 ;
V_48:
F_18 ( V_1 -> V_6 ) ;
return V_35 ;
}
static int F_35 ( struct V_31 * V_32 )
{
struct V_1 * V_1 = F_36 ( V_32 ) ;
F_37 ( & V_1 -> V_25 ) ;
F_38 ( & V_1 -> V_9 ) ;
F_18 ( V_1 -> V_6 ) ;
return 0 ;
}
