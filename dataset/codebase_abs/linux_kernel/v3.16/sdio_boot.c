static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 + V_5 ;
T_1 V_6 ;
int V_7 ;
while ( F_2 ( V_4 , V_3 ) ) {
V_6 = F_3 ( V_2 , 0x13 , & V_7 ) ;
if ( V_6 & 0x01 )
return 1 ;
F_4 () ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , const char * V_8 )
{
int V_7 = 0 , V_9 , V_10 ;
T_1 * V_11 = V_12 ;
T_2 V_13 = 0 ;
int V_14 ;
const struct V_15 * V_16 ;
V_7 = F_6 ( & V_16 , V_8 , & V_2 -> V_17 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_2 -> V_17 ,
L_1 ,
V_8 , V_7 ) ;
return V_7 ;
}
V_11 = F_8 ( V_18 + V_19 , V_20 ) ;
if ( V_11 == NULL )
return - V_21 ;
V_14 = V_16 -> V_22 ;
if ( V_14 <= 0 ) {
V_7 = - 1 ;
goto V_23;
}
V_10 = 0 ;
while ( V_14 > 0 ) {
if ( V_14 > V_18 ) {
V_9 = V_18 ;
V_11 [ 3 ] = 0 ;
} else {
V_9 = V_14 ;
V_11 [ 3 ] = 2 ;
}
V_11 [ 0 ] = V_9 & 0xff ;
V_11 [ 1 ] = ( V_9 >> 8 ) & 0xff ;
V_11 [ 2 ] = ( V_9 >> 16 ) & 0xff ;
memcpy ( V_11 + V_19 , V_16 -> V_24 + V_13 , V_9 ) ;
V_7 = F_9 ( V_2 , 0 , V_11 , V_9 + V_19 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_2 -> V_17 ,
L_2 ,
V_10 , V_7 ) ;
goto V_23;
}
if ( V_11 [ 3 ] == 2 )
break;
if ( ! F_1 ( V_2 ) ) {
V_7 = - V_25 ;
F_7 ( & V_2 -> V_17 , L_3 ) ;
goto V_23;
}
V_7 = F_10 ( V_2 , V_11 , 0 , V_26 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_2 -> V_17 ,
L_4 ,
V_10 , V_7 ) ;
goto V_23;
}
F_11 ( V_2 , 0x01 , 0x13 , & V_7 ) ;
F_11 ( V_2 , 0x00 , 0x10 , & V_7 ) ;
V_14 -= V_18 ;
V_13 += V_18 ;
V_10 ++ ;
}
V_23:
F_12 ( V_11 ) ;
return V_7 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_7 ;
const char * V_27 = V_28 V_29 ;
const char * V_30 = V_28 V_31 ;
V_12 = F_8 ( V_32 , V_20 ) ;
if ( V_12 == NULL )
return - V_21 ;
V_7 = F_5 ( V_2 , V_27 ) ;
if ( V_7 )
goto V_33;
F_14 ( & V_2 -> V_17 , L_5 ) ;
V_7 = F_5 ( V_2 , V_30 ) ;
if ( V_7 )
goto V_33;
F_14 ( & V_2 -> V_17 , L_6 ) ;
V_33:
F_12 ( V_12 ) ;
return V_7 ;
}
