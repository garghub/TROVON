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
F_1 ( V_2 , 65536 - F_5 ( V_2 , V_8 -> V_9 ) , V_5 ) ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
F_7 ( V_8 -> V_10 ) ;
F_1 ( V_2 , 0 , V_11 ) ;
F_1 ( V_2 , V_2 -> V_12 , V_13 ) ;
F_3 ( V_8 ) ;
while ( F_8 ( V_2 -> V_6 + V_13 ) & V_14 )
F_9 () ;
F_1 ( V_2 , V_2 -> V_12 | V_15 , V_13 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
F_1 ( V_2 , V_2 -> V_12 , V_13 ) ;
F_11 ( V_8 -> V_10 ) ;
return 0 ;
}
static unsigned int F_12 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_2 V_3 = F_13 ( V_2 -> V_6 + V_5 ) ;
return F_14 ( V_2 , 65536 - V_3 ) ;
}
static int F_15 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
struct V_20 * V_20 ;
unsigned long V_21 ;
int V_22 , V_23 ;
V_2 = F_16 ( & V_17 -> V_24 , sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 )
return - V_26 ;
V_19 = F_17 ( V_17 , V_27 , 0 ) ;
V_2 -> V_6 = F_18 ( & V_17 -> V_24 , V_19 ) ;
if ( F_19 ( V_2 -> V_6 ) )
return F_20 ( V_2 -> V_6 ) ;
V_20 = F_21 ( & V_17 -> V_24 , NULL ) ;
if ( F_19 ( V_20 ) )
return F_20 ( V_20 ) ;
F_22 ( & V_17 -> V_24 ) ;
F_7 ( & V_17 -> V_24 ) ;
V_2 -> V_28 = F_23 ( V_20 ) ;
F_11 ( & V_17 -> V_24 ) ;
if ( ! V_2 -> V_28 ) {
V_22 = - V_29 ;
goto V_30;
}
for ( V_23 = F_24 ( V_31 ) - 1 ; V_23 >= 0 ; V_23 -- ) {
V_21 = V_2 -> V_28 / V_31 [ V_23 ] ;
if ( V_21 && V_21 < 65536 ) {
V_2 -> V_12 = V_23 ;
break;
}
}
if ( V_23 < 0 ) {
F_25 ( & V_17 -> V_24 , L_1 ) ;
V_22 = - V_32 ;
goto V_30;
}
V_2 -> V_8 . V_33 = & V_34 ,
V_2 -> V_8 . V_35 = & V_36 ,
V_2 -> V_8 . V_10 = & V_17 -> V_24 ;
V_2 -> V_8 . V_37 = 1 ;
V_2 -> V_8 . V_38 = F_14 ( V_2 , 65536 ) ;
V_2 -> V_8 . V_9 = F_26 ( V_2 -> V_8 . V_38 , V_39 ) ;
F_27 ( V_17 , V_2 ) ;
F_28 ( & V_2 -> V_8 , V_2 ) ;
F_29 ( & V_2 -> V_8 , V_40 ) ;
V_22 = F_30 ( & V_2 -> V_8 , 0 , & V_17 -> V_24 ) ;
if ( V_22 )
F_31 ( & V_17 -> V_24 , L_2 ) ;
V_22 = F_32 ( & V_2 -> V_8 ) ;
if ( V_22 < 0 )
goto V_30;
return 0 ;
V_30:
F_33 ( & V_17 -> V_24 ) ;
return V_22 ;
}
static int F_34 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_35 ( V_17 ) ;
F_36 ( & V_2 -> V_8 ) ;
F_33 ( & V_17 -> V_24 ) ;
return 0 ;
}
