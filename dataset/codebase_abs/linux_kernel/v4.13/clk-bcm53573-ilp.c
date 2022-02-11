static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_4 -> V_5 , V_6 , 0x10199 ) ;
F_3 ( V_4 -> V_5 , 0x674 , 0x10000 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_4 -> V_5 , V_6 , 0 ) ;
F_3 ( V_4 -> V_5 , 0x674 , 0 ) ;
}
static unsigned long F_5 ( struct V_1 * V_2 ,
unsigned long V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_8 , V_9 ;
int V_10 = 0 , V_11 = 0 , V_12 = 0 ;
int V_13 ;
F_3 ( V_5 , V_14 , V_15 ) ;
F_6 ( V_5 , V_14 , & V_8 ) ;
V_8 &= V_16 ;
while ( V_11 < 20 ) {
F_6 ( V_5 , V_14 , & V_9 ) ;
V_9 &= V_16 ;
if ( V_9 != V_8 ) {
V_10 += V_9 ;
V_11 ++ ;
V_12 = 0 ;
V_8 = V_9 ;
} else if ( ++ V_12 > 5000 ) {
V_10 += V_9 ;
V_11 ++ ;
break;
}
F_7 () ;
}
F_3 ( V_5 , V_14 , 0x0 ) ;
V_13 = V_10 / V_11 ;
return V_7 * 4 / V_13 ;
}
static void F_8 ( struct V_17 * V_18 )
{
struct V_3 * V_4 ;
struct V_19 V_20 = { } ;
const char * V_21 ;
int V_22 ;
V_4 = F_9 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return;
V_21 = F_10 ( V_18 , 0 ) ;
if ( ! V_21 ) {
V_22 = - V_24 ;
goto V_25;
}
V_4 -> V_5 = F_11 ( F_12 ( V_18 ) ) ;
if ( F_13 ( V_4 -> V_5 ) ) {
V_22 = F_14 ( V_4 -> V_5 ) ;
goto V_25;
}
V_20 . V_26 = V_18 -> V_26 ;
V_20 . V_27 = & V_28 ;
V_20 . V_29 = & V_21 ;
V_20 . V_30 = 1 ;
V_4 -> V_2 . V_20 = & V_20 ;
V_22 = F_15 ( NULL , & V_4 -> V_2 ) ;
if ( V_22 )
goto V_25;
V_22 = F_16 ( V_18 , V_31 , & V_4 -> V_2 ) ;
if ( V_22 )
goto V_32;
return;
V_32:
F_17 ( & V_4 -> V_2 ) ;
V_25:
F_18 ( V_4 ) ;
F_19 ( L_1 , V_22 ) ;
}
