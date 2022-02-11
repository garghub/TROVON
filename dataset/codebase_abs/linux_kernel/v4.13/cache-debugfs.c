static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
unsigned int V_4 = ( unsigned int ) V_2 -> V_5 ;
struct V_6 * V_7 ;
unsigned int V_8 , V_9 ;
unsigned long V_10 ;
unsigned long V_11 = 0 ;
F_2 () ;
V_10 = F_3 ( V_12 ) ;
if ( ( V_10 & V_13 ) == 0 ) {
F_4 () ;
F_5 ( V_2 , L_1 ) ;
return 0 ;
}
if ( V_4 == V_14 ) {
V_11 = V_15 ;
V_7 = & V_16 . V_17 ;
} else {
V_11 = V_18 ;
V_7 = & V_16 . V_19 ;
}
V_8 = V_7 -> V_20 ;
if ( ( V_10 & V_21 ) && V_4 == V_14 )
V_8 >>= 1 ;
V_8 <<= V_7 -> V_22 ;
for ( V_9 = 0 ; V_9 < V_7 -> V_23 ; V_9 ++ ) {
unsigned long V_24 ;
unsigned int line ;
F_5 ( V_2 , L_2 ) ;
F_5 ( V_2 , L_3 , V_9 ) ;
F_5 ( V_2 , L_2 ) ;
for ( V_24 = V_11 , line = 0 ;
V_24 < V_11 + V_8 ;
V_24 += V_7 -> V_25 , line ++ ) {
unsigned long V_26 = F_3 ( V_24 ) ;
if ( ( V_26 & 1 ) == 0 )
continue;
F_5 ( V_2 , L_4 ,
line , V_26 & 2 ? 'U' : ' ' ,
V_26 & 0x1ffffc00 ) ;
}
V_11 += V_7 -> V_27 ;
}
F_4 () ;
return 0 ;
}
static int F_6 ( struct V_28 * V_28 , struct V_2 * V_2 )
{
return F_7 ( V_2 , F_1 , V_28 -> V_29 ) ;
}
static int T_1 F_8 ( void )
{
struct V_30 * V_31 , * V_32 ;
V_31 = F_9 ( L_5 , V_33 , V_34 ,
( unsigned int * ) V_14 ,
& V_35 ) ;
if ( ! V_31 )
return - V_36 ;
V_32 = F_9 ( L_6 , V_33 , V_34 ,
( unsigned int * ) V_37 ,
& V_35 ) ;
if ( ! V_32 ) {
F_10 ( V_31 ) ;
return - V_36 ;
}
return 0 ;
}
