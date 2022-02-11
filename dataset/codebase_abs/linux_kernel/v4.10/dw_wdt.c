static inline int F_1 ( struct V_1 * V_1 )
{
return F_2 ( V_1 -> V_2 + V_3 ) &
V_4 ;
}
static inline int F_3 ( struct V_1 * V_1 , unsigned V_5 )
{
return ( 1U << ( 16 + V_5 ) ) / V_1 -> V_6 ;
}
static int F_4 ( struct V_1 * V_1 )
{
int V_5 = F_2 ( V_1 -> V_2 + V_7 ) & 0xF ;
return F_3 ( V_1 , V_5 ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
F_7 ( V_10 , V_1 -> V_2 +
V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_8 * V_9 , unsigned int V_12 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
int V_13 , V_14 = V_15 ;
for ( V_13 = 0 ; V_13 <= V_15 ; ++ V_13 )
if ( F_3 ( V_1 , V_13 ) >= V_12 ) {
V_14 = V_13 ;
break;
}
F_7 ( V_14 | V_14 << V_16 ,
V_1 -> V_2 + V_7 ) ;
V_9 -> V_17 = F_3 ( V_1 , V_14 ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
F_8 ( V_9 , V_9 -> V_17 ) ;
F_10 ( V_18 , & V_9 -> V_19 ) ;
F_7 ( V_4 ,
V_1 -> V_2 + V_3 ) ;
return 0 ;
}
static int F_11 ( struct V_20 * V_21 ,
unsigned long V_22 , void * V_23 )
{
struct V_1 * V_1 ;
T_1 V_24 ;
V_1 = F_12 ( V_21 , struct V_1 , V_25 ) ;
F_7 ( 0 , V_1 -> V_2 + V_7 ) ;
V_24 = F_2 ( V_1 -> V_2 + V_3 ) ;
if ( V_24 & V_4 )
F_7 ( V_10 ,
V_1 -> V_2 + V_11 ) ;
else
F_7 ( V_4 ,
V_1 -> V_2 + V_3 ) ;
F_13 ( 500 ) ;
return V_26 ;
}
static unsigned int F_14 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
return F_2 ( V_1 -> V_2 + V_27 ) /
V_1 -> V_6 ;
}
static int F_15 ( struct V_28 * V_29 )
{
struct V_1 * V_1 = F_16 ( V_29 ) ;
F_17 ( V_1 -> V_30 ) ;
return 0 ;
}
static int F_18 ( struct V_28 * V_29 )
{
struct V_1 * V_1 = F_16 ( V_29 ) ;
int V_31 = F_19 ( V_1 -> V_30 ) ;
if ( V_31 )
return V_31 ;
F_5 ( & V_1 -> V_9 ) ;
return 0 ;
}
static int F_20 ( struct V_32 * V_33 )
{
struct V_28 * V_29 = & V_33 -> V_29 ;
struct V_8 * V_9 ;
struct V_1 * V_1 ;
struct V_34 * V_35 ;
int V_36 ;
V_1 = F_21 ( V_29 , sizeof( * V_1 ) , V_37 ) ;
if ( ! V_1 )
return - V_38 ;
V_35 = F_22 ( V_33 , V_39 , 0 ) ;
V_1 -> V_2 = F_23 ( V_29 , V_35 ) ;
if ( F_24 ( V_1 -> V_2 ) )
return F_25 ( V_1 -> V_2 ) ;
V_1 -> V_30 = F_26 ( V_29 , NULL ) ;
if ( F_24 ( V_1 -> V_30 ) )
return F_25 ( V_1 -> V_30 ) ;
V_36 = F_19 ( V_1 -> V_30 ) ;
if ( V_36 )
return V_36 ;
V_1 -> V_6 = F_27 ( V_1 -> V_30 ) ;
if ( V_1 -> V_6 == 0 ) {
V_36 = - V_40 ;
goto V_41;
}
V_9 = & V_1 -> V_9 ;
V_9 -> V_42 = & V_43 ;
V_9 -> V_44 = & V_45 ;
V_9 -> V_46 = 1 ;
V_9 -> V_47 =
F_3 ( V_1 , V_15 ) * 1000 ;
V_9 -> V_48 = V_29 ;
F_28 ( V_9 , V_1 ) ;
F_29 ( V_9 , V_49 ) ;
F_30 ( V_9 , 0 , V_29 ) ;
if ( F_1 ( V_1 ) ) {
V_9 -> V_17 = F_4 ( V_1 ) ;
F_10 ( V_18 , & V_9 -> V_19 ) ;
} else {
V_9 -> V_17 = V_50 ;
F_30 ( V_9 , 0 , V_29 ) ;
}
F_31 ( V_33 , V_1 ) ;
V_36 = F_32 ( V_9 ) ;
if ( V_36 )
goto V_41;
V_1 -> V_25 . V_51 = F_11 ;
V_1 -> V_25 . V_52 = 128 ;
V_36 = F_33 ( & V_1 -> V_25 ) ;
if ( V_36 )
F_34 ( L_1 ) ;
return 0 ;
V_41:
F_17 ( V_1 -> V_30 ) ;
return V_36 ;
}
static int F_35 ( struct V_32 * V_33 )
{
struct V_1 * V_1 = F_36 ( V_33 ) ;
F_37 ( & V_1 -> V_25 ) ;
F_38 ( & V_1 -> V_9 ) ;
F_17 ( V_1 -> V_30 ) ;
return 0 ;
}
