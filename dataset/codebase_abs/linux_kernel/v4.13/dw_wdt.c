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
static int F_11 ( struct V_8 * V_9 ,
unsigned long V_20 , void * V_21 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
T_1 V_22 ;
F_7 ( 0 , V_1 -> V_2 + V_7 ) ;
V_22 = F_2 ( V_1 -> V_2 + V_3 ) ;
if ( V_22 & V_4 )
F_7 ( V_10 ,
V_1 -> V_2 + V_11 ) ;
else
F_7 ( V_4 ,
V_1 -> V_2 + V_3 ) ;
F_12 ( 500 ) ;
return 0 ;
}
static unsigned int F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
return F_2 ( V_1 -> V_2 + V_23 ) /
V_1 -> V_6 ;
}
static int F_14 ( struct V_24 * V_25 )
{
struct V_1 * V_1 = F_15 ( V_25 ) ;
F_16 ( V_1 -> V_26 ) ;
return 0 ;
}
static int F_17 ( struct V_24 * V_25 )
{
struct V_1 * V_1 = F_15 ( V_25 ) ;
int V_27 = F_18 ( V_1 -> V_26 ) ;
if ( V_27 )
return V_27 ;
F_5 ( & V_1 -> V_9 ) ;
return 0 ;
}
static int F_19 ( struct V_28 * V_29 )
{
struct V_24 * V_25 = & V_29 -> V_25 ;
struct V_8 * V_9 ;
struct V_1 * V_1 ;
struct V_30 * V_31 ;
int V_32 ;
V_1 = F_20 ( V_25 , sizeof( * V_1 ) , V_33 ) ;
if ( ! V_1 )
return - V_34 ;
V_31 = F_21 ( V_29 , V_35 , 0 ) ;
V_1 -> V_2 = F_22 ( V_25 , V_31 ) ;
if ( F_23 ( V_1 -> V_2 ) )
return F_24 ( V_1 -> V_2 ) ;
V_1 -> V_26 = F_25 ( V_25 , NULL ) ;
if ( F_23 ( V_1 -> V_26 ) )
return F_24 ( V_1 -> V_26 ) ;
V_32 = F_18 ( V_1 -> V_26 ) ;
if ( V_32 )
return V_32 ;
V_1 -> V_6 = F_26 ( V_1 -> V_26 ) ;
if ( V_1 -> V_6 == 0 ) {
V_32 = - V_36 ;
goto V_37;
}
V_1 -> V_38 = F_27 ( & V_29 -> V_25 , NULL ) ;
if ( F_23 ( V_1 -> V_38 ) ) {
V_32 = F_24 ( V_1 -> V_38 ) ;
goto V_37;
}
F_28 ( V_1 -> V_38 ) ;
V_9 = & V_1 -> V_9 ;
V_9 -> V_39 = & V_40 ;
V_9 -> V_41 = & V_42 ;
V_9 -> V_43 = 1 ;
V_9 -> V_44 =
F_3 ( V_1 , V_15 ) * 1000 ;
V_9 -> V_45 = V_25 ;
F_29 ( V_9 , V_1 ) ;
F_30 ( V_9 , V_46 ) ;
F_31 ( V_9 , 0 , V_25 ) ;
if ( F_1 ( V_1 ) ) {
V_9 -> V_17 = F_4 ( V_1 ) ;
F_10 ( V_18 , & V_9 -> V_19 ) ;
} else {
V_9 -> V_17 = V_47 ;
F_31 ( V_9 , 0 , V_25 ) ;
}
F_32 ( V_29 , V_1 ) ;
F_33 ( V_9 , 128 ) ;
V_32 = F_34 ( V_9 ) ;
if ( V_32 )
goto V_37;
return 0 ;
V_37:
F_16 ( V_1 -> V_26 ) ;
return V_32 ;
}
static int F_35 ( struct V_28 * V_29 )
{
struct V_1 * V_1 = F_36 ( V_29 ) ;
F_37 ( & V_1 -> V_9 ) ;
F_38 ( V_1 -> V_38 ) ;
F_16 ( V_1 -> V_26 ) ;
return 0 ;
}
