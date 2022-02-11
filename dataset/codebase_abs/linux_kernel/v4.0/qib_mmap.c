void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_7 -> V_8 ) ;
F_4 ( & V_6 -> V_9 ) ;
F_5 ( & V_4 -> V_10 ) ;
F_6 ( & V_6 -> V_9 ) ;
F_7 ( V_4 -> V_11 ) ;
F_8 ( V_4 ) ;
}
static void F_9 ( struct V_12 * V_13 )
{
struct V_3 * V_4 = V_13 -> V_14 ;
F_10 ( & V_4 -> V_2 ) ;
}
static void F_11 ( struct V_12 * V_13 )
{
struct V_3 * V_4 = V_13 -> V_14 ;
F_12 ( & V_4 -> V_2 , F_1 ) ;
}
int F_13 ( struct V_15 * V_7 , struct V_12 * V_13 )
{
struct V_5 * V_6 = F_3 ( V_7 -> V_8 ) ;
unsigned long V_16 = V_13 -> V_17 << V_18 ;
unsigned long V_19 = V_13 -> V_20 - V_13 -> V_21 ;
struct V_3 * V_4 , * V_22 ;
int V_23 = - V_24 ;
F_4 ( & V_6 -> V_9 ) ;
F_14 (ip, pp, &dev->pending_mmaps,
pending_mmaps) {
if ( V_7 != V_4 -> V_7 || ( V_25 ) V_16 != V_4 -> V_16 )
continue;
if ( V_19 > V_4 -> V_19 )
break;
F_15 ( & V_4 -> V_10 ) ;
F_6 ( & V_6 -> V_9 ) ;
V_23 = F_16 ( V_13 , V_4 -> V_11 , 0 ) ;
if ( V_23 )
goto V_26;
V_13 -> V_27 = & V_28 ;
V_13 -> V_14 = V_4 ;
F_9 ( V_13 ) ;
goto V_26;
}
F_6 ( & V_6 -> V_9 ) ;
V_26:
return V_23 ;
}
struct V_3 * F_17 ( struct V_5 * V_6 ,
T_1 V_19 ,
struct V_15 * V_7 ,
void * V_11 ) {
struct V_3 * V_4 ;
V_4 = F_18 ( sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
goto V_30;
V_19 = F_19 ( V_19 ) ;
F_4 ( & V_6 -> V_31 ) ;
if ( V_6 -> V_32 == 0 )
V_6 -> V_32 = V_33 ;
V_4 -> V_16 = V_6 -> V_32 ;
V_6 -> V_32 += V_19 ;
F_6 ( & V_6 -> V_31 ) ;
F_20 ( & V_4 -> V_10 ) ;
V_4 -> V_19 = V_19 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_11 = V_11 ;
F_21 ( & V_4 -> V_2 ) ;
V_30:
return V_4 ;
}
void F_22 ( struct V_5 * V_6 , struct V_3 * V_4 ,
T_1 V_19 , void * V_11 )
{
V_19 = F_19 ( V_19 ) ;
F_4 ( & V_6 -> V_31 ) ;
if ( V_6 -> V_32 == 0 )
V_6 -> V_32 = V_33 ;
V_4 -> V_16 = V_6 -> V_32 ;
V_6 -> V_32 += V_19 ;
F_6 ( & V_6 -> V_31 ) ;
V_4 -> V_19 = V_19 ;
V_4 -> V_11 = V_11 ;
}
