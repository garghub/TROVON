static void F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned int V_4 )
{
if ( V_4 == V_5 )
V_3 |= 0x5a5a0000 ;
else
V_3 |= 0xa5a5a500 ;
F_2 ( V_3 , V_2 -> V_6 + V_4 ) ;
}
static int F_3 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
F_1 ( V_2 , 65536 - V_8 -> V_9 * V_2 -> V_10 , V_5 ) ;
return 0 ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
F_6 ( V_2 -> V_11 ) ;
F_1 ( V_2 , V_2 -> V_12 , V_13 ) ;
F_3 ( V_8 ) ;
while ( F_7 ( V_2 -> V_6 + V_13 ) & V_14 )
F_8 () ;
F_1 ( V_2 , V_2 -> V_12 | V_15 , V_13 ) ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
F_1 ( V_2 , V_2 -> V_12 , V_13 ) ;
F_10 ( V_2 -> V_11 ) ;
return 0 ;
}
static unsigned int F_11 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_2 V_3 = F_12 ( V_2 -> V_6 + V_5 ) ;
return F_13 ( 65536 - V_3 , V_2 -> V_10 ) ;
}
static int F_14 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
unsigned long V_20 ;
unsigned int V_10 ;
int V_21 , V_22 ;
V_2 = F_15 ( & V_17 -> V_23 , sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
return - V_25 ;
V_19 = F_16 ( V_17 , V_26 , 0 ) ;
V_2 -> V_6 = F_17 ( & V_17 -> V_23 , V_19 ) ;
if ( F_18 ( V_2 -> V_6 ) )
return F_19 ( V_2 -> V_6 ) ;
V_2 -> V_11 = F_20 ( & V_17 -> V_23 , NULL ) ;
if ( F_18 ( V_2 -> V_11 ) )
return F_19 ( V_2 -> V_11 ) ;
V_20 = F_21 ( V_2 -> V_11 ) ;
if ( ! V_20 )
return - V_27 ;
for ( V_22 = F_22 ( V_28 ) - 1 ; V_22 >= 0 ; V_22 -- ) {
V_10 = F_23 ( V_20 , V_28 [ V_22 ] ) ;
if ( V_10 ) {
V_2 -> V_10 = V_10 ;
V_2 -> V_12 = V_22 ;
break;
}
}
if ( ! V_10 ) {
F_24 ( & V_17 -> V_23 , L_1 ) ;
return - V_29 ;
}
F_25 ( & V_17 -> V_23 ) ;
F_26 ( & V_17 -> V_23 ) ;
V_2 -> V_8 . V_30 = & V_31 ,
V_2 -> V_8 . V_32 = & V_33 ,
V_2 -> V_8 . V_34 = & V_17 -> V_23 ;
V_2 -> V_8 . V_35 = 1 ;
V_2 -> V_8 . V_36 = 65536 / V_10 ;
V_2 -> V_8 . V_9 = F_27 ( V_2 -> V_8 . V_36 , V_37 ) ;
F_28 ( V_17 , V_2 ) ;
F_29 ( & V_2 -> V_8 , V_2 ) ;
F_30 ( & V_2 -> V_8 , V_38 ) ;
V_21 = F_31 ( & V_2 -> V_8 , 0 , & V_17 -> V_23 ) ;
if ( V_21 )
F_32 ( & V_17 -> V_23 , L_2 ) ;
V_21 = F_33 ( & V_2 -> V_8 ) ;
if ( V_21 < 0 ) {
F_34 ( & V_17 -> V_23 ) ;
F_35 ( & V_17 -> V_23 ) ;
return V_21 ;
}
return 0 ;
}
static int F_36 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_37 ( V_17 ) ;
F_38 ( & V_2 -> V_8 ) ;
F_34 ( & V_17 -> V_23 ) ;
F_35 ( & V_17 -> V_23 ) ;
return 0 ;
}
