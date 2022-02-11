static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
unsigned int V_4 = ( unsigned int ) V_2 -> V_5 ;
unsigned long V_6 , V_7 , V_8 , V_9 ;
unsigned long V_10 ;
unsigned long V_11 ;
unsigned int V_12 , V_13 ;
unsigned int V_14 ;
V_11 = F_2 ( V_15 ) ;
if ( ( V_11 & 0x1 ) == 0 ) {
F_3 ( V_2 , L_1 ) ;
return 0 ;
}
if ( V_4 == V_16 ) {
V_6 = V_17 ;
V_7 = V_18 ;
V_8 = V_19 ;
V_9 = V_20 ;
V_12 = 4 ;
} else {
V_6 = V_21 ;
V_7 = V_22 ;
V_8 = V_23 ;
V_9 = V_24 ;
V_12 = 64 ;
}
F_4 ( V_10 ) ;
F_5 () ;
V_14 = ( V_11 & V_25 ) >> V_26 ;
if ( V_14 == 0 )
V_14 = V_27 + 1 ;
if ( V_4 == V_16 ) {
V_6 = V_17 ;
V_7 = V_18 ;
V_8 = V_19 ;
V_9 = V_20 ;
V_12 = 4 ;
} else {
V_6 = V_21 ;
V_7 = V_22 ;
V_8 = V_23 ;
V_9 = V_24 ;
V_12 = 64 ;
}
F_3 ( V_2 , L_2 ) ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
unsigned long V_28 , V_29 , V_30 , V_31 ;
unsigned long V_32 ;
unsigned long V_33 ;
const char * V_34 = L_3 ;
int V_35 ;
V_33 = F_2 ( V_6 | ( V_13 << V_36 ) ) ;
F_6 () ;
V_28 = V_33 & 0xfffffc00 ;
V_32 = V_33 & 0x100 ;
V_33 = F_2 ( V_7 | ( V_13 << V_36 ) ) ;
F_6 () ;
V_30 = V_33 & V_37 ;
V_33 = F_2 ( V_8 | ( V_13 << V_36 ) ) ;
F_6 () ;
V_29 = ( V_33 & 0x0ffffc00 ) << 4 ;
V_33 = F_2 ( V_9 | ( V_13 << V_36 ) ) ;
F_6 () ;
V_31 = ( V_33 & 0xf0 ) >> 4 ;
for ( V_35 = 0 ; V_35 < F_7 ( V_38 ) ; V_35 ++ ) {
if ( V_38 [ V_35 ] . V_39 == V_31 )
break;
}
if ( V_35 != F_7 ( V_38 ) )
V_34 = V_38 [ V_35 ] . V_31 ;
F_3 ( V_2 , L_4 ,
V_13 , V_28 , V_29 , V_30 ,
V_34 , V_32 ? L_5 : L_6 ,
( V_14 <= V_13 ) ? L_7 : L_6 ) ;
}
F_8 () ;
F_9 ( V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_40 * V_40 , struct V_2 * V_2 )
{
return F_11 ( V_2 , F_1 , V_40 -> V_41 ) ;
}
static int T_1 F_12 ( void )
{
struct V_42 * V_43 , * V_44 ;
V_43 = F_13 ( L_8 , V_45 , V_46 ,
( unsigned int * ) V_16 ,
& V_47 ) ;
if ( F_14 ( ! V_43 ) )
return - V_48 ;
V_44 = F_13 ( L_9 , V_45 , V_46 ,
( unsigned int * ) V_49 ,
& V_47 ) ;
if ( F_14 ( ! V_44 ) ) {
F_15 ( V_43 ) ;
return - V_48 ;
}
return 0 ;
}
