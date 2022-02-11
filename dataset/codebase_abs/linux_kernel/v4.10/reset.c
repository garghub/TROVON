int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 ;
T_2 * V_4 = NULL ;
int V_5 ;
T_3 V_6 ;
T_3 V_7 ;
T_3 V_8 ;
unsigned long V_9 ;
T_2 V_10 ;
int V_11 ;
int V_12 = 0 ;
#define F_2 0xf0000
#define F_3 0x400
#define F_4 0x3fc
#define F_5 0x10
#define F_6 swab32(1)
#define F_7 (10 * HZ)
#define F_8 (2 * HZ)
V_4 = F_9 ( 256 , V_13 ) ;
if ( ! V_4 ) {
V_12 = - V_14 ;
F_10 ( V_2 , L_1 ) ;
goto V_15;
}
V_5 = F_11 ( V_2 -> V_16 -> V_17 ) ;
for ( V_11 = 0 ; V_11 < 64 ; ++ V_11 ) {
if ( V_11 == 22 || V_11 == 23 )
continue;
if ( F_12 ( V_2 -> V_16 -> V_17 , V_11 * 4 ,
V_4 + V_11 ) ) {
V_12 = - V_18 ;
F_10 ( V_2 , L_2 ) ;
goto V_15;
}
}
V_3 = F_13 ( F_14 ( V_2 -> V_16 -> V_17 , 0 ) +
F_2 ,
F_3 ) ;
if ( ! V_3 ) {
V_12 = - V_14 ;
F_10 ( V_2 , L_3 ) ;
goto V_15;
}
V_9 = V_19 + F_7 ;
do {
V_10 = F_15 ( V_3 + F_4 ) ;
if ( ! V_10 )
break;
F_16 ( 1 ) ;
} while ( F_17 ( V_19 , V_9 ) );
if ( V_10 ) {
F_10 ( V_2 , L_4 ) ;
V_12 = - V_20 ;
F_18 ( V_3 ) ;
goto V_15;
}
F_19 ( F_6 , V_3 + F_5 ) ;
F_18 ( V_3 ) ;
F_16 ( 1000 ) ;
V_9 = V_19 + F_8 ;
do {
if ( ! F_20 ( V_2 -> V_16 -> V_17 , V_21 ,
& V_8 ) && V_8 != 0xffff )
break;
F_16 ( 1 ) ;
} while ( F_17 ( V_19 , V_9 ) );
if ( V_8 == 0xffff ) {
V_12 = - V_18 ;
F_10 ( V_2 , L_5 ) ;
goto V_15;
}
if ( V_5 ) {
V_6 = V_4 [ ( V_5 + V_22 ) / 4 ] ;
if ( F_21 ( V_2 -> V_16 -> V_17 ,
V_22 ,
V_6 ) ) {
V_12 = - V_18 ;
F_10 ( V_2 , L_6 ) ;
goto V_15;
}
V_7 = V_4 [ ( V_5 + V_23 ) / 4 ] ;
if ( F_21 ( V_2 -> V_16 -> V_17 ,
V_23 ,
V_7 ) ) {
V_12 = - V_18 ;
F_10 ( V_2 , L_7 ) ;
goto V_15;
}
}
for ( V_11 = 0 ; V_11 < 16 ; ++ V_11 ) {
if ( V_11 * 4 == V_24 )
continue;
if ( F_22 ( V_2 -> V_16 -> V_17 , V_11 * 4 ,
V_4 [ V_11 ] ) ) {
V_12 = - V_18 ;
F_10 ( V_2 , L_8 ,
V_11 ) ;
goto V_15;
}
}
if ( F_22 ( V_2 -> V_16 -> V_17 , V_24 ,
V_4 [ V_24 / 4 ] ) ) {
V_12 = - V_18 ;
F_10 ( V_2 , L_9 ) ;
goto V_15;
}
V_15:
F_23 ( V_4 ) ;
return V_12 ;
}
