static char * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
const T_1 * V_6 ;
T_2 V_7 ;
V_6 = F_2 ( V_4 , L_1 , NULL ) ;
V_7 = F_3 ( V_4 , V_6 ) ;
return F_4 ( V_2 , V_8 , L_2 ,
( unsigned long long ) V_7 , V_5 ) ;
}
static int F_5 ( struct V_9 * V_10 ,
struct V_3 * V_11 )
{
unsigned int V_12 , V_13 ;
const char * V_5 , * V_14 ;
struct V_1 * V_2 = & V_10 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_15 ;
struct V_16 * V_16 ;
T_3 V_6 ;
int V_17 ;
V_16 = F_6 ( V_11 ) ;
if ( F_7 ( V_16 ) ) {
F_8 ( V_2 , L_3 ) ;
return F_9 ( V_16 ) ;
}
V_17 = F_10 ( V_16 , V_18 , & V_6 ) ;
if ( V_17 ) {
F_8 ( V_2 , L_4 ) ;
return V_17 ;
}
V_12 = V_6 & V_19 ;
switch ( V_12 ) {
case 0x0 :
case 0x1 :
V_13 = 2000 ;
break;
case 0x6 :
case 0x7 :
V_13 = 1800 ;
break;
case 0x4 :
case 0xB :
case 0xD :
V_13 = 1600 ;
break;
case 0x1a :
V_13 = 1400 ;
break;
case 0x14 :
case 0x17 :
V_13 = 1300 ;
break;
case 0x19 :
V_13 = 1200 ;
break;
case 0x13 :
case 0x1d :
V_13 = 1000 ;
break;
case 0x1c :
V_13 = 800 ;
break;
case 0x1b :
V_13 = 600 ;
break;
default:
F_8 ( V_2 , L_5 ) ;
return - V_20 ;
}
V_13 *= 1000 * 1000 ;
V_5 = F_1 ( V_2 , V_11 , L_6 ) ;
V_21 [ 0 ] = F_11 ( V_2 , V_5 , NULL ,
0 , V_13 ) ;
if ( F_7 ( V_21 [ 0 ] ) ) {
V_17 = F_9 ( V_21 [ 0 ] ) ;
goto V_22;
}
V_5 = F_1 ( V_2 , V_11 , L_7 ) ;
V_21 [ 1 ] = F_11 ( V_2 , V_5 , NULL , 0 ,
V_13 ) ;
if ( F_7 ( V_21 [ 1 ] ) ) {
V_17 = F_9 ( V_21 [ 1 ] ) ;
goto V_23;
}
V_14 = F_1 ( V_2 , V_11 , L_8 ) ;
V_21 [ 2 ] = F_11 ( V_2 , V_14 , NULL ,
0 , 1200 * 1000 * 1000 ) ;
if ( F_7 ( V_21 [ 2 ] ) ) {
V_17 = F_9 ( V_21 [ 2 ] ) ;
goto V_24;
}
V_5 = F_1 ( V_2 , V_11 , L_9 ) ;
V_21 [ 3 ] = F_12 ( NULL , V_5 , V_14 ,
0 , 1 , 6 ) ;
if ( F_7 ( V_21 [ 3 ] ) ) {
V_17 = F_9 ( V_21 [ 3 ] ) ;
goto V_25;
}
V_5 = F_1 ( V_2 , V_11 , L_10 ) ;
V_21 [ 4 ] = F_12 ( NULL , V_5 ,
V_14 ,
0 , 1 , 3 ) ;
if ( F_7 ( V_21 [ 4 ] ) ) {
V_17 = F_9 ( V_21 [ 4 ] ) ;
goto V_26;
}
F_13 ( V_4 , V_27 , & V_28 ) ;
V_17 = F_13 ( V_4 , V_27 , & V_28 ) ;
if ( V_17 )
goto V_29;
return 0 ;
V_29:
F_14 ( V_21 [ 4 ] ) ;
V_26:
F_14 ( V_21 [ 3 ] ) ;
V_25:
F_15 ( V_21 [ 2 ] ) ;
V_24:
F_15 ( V_21 [ 1 ] ) ;
V_23:
F_15 ( V_21 [ 0 ] ) ;
V_22:
return V_17 ;
}
static int F_16 ( struct V_9 * V_10 )
{
F_17 ( & V_10 -> V_2 , V_30 L_11 ) ;
F_17 ( & V_10 -> V_2 , V_30 L_12 ) ;
F_17 ( & V_10 -> V_2 , V_30
L_13 ) ;
return F_5 ( V_10 , V_10 -> V_2 . V_15 ) ;
}
static int F_18 ( struct V_9 * V_10 )
{
return F_5 ( V_10 , V_10 -> V_2 . V_15 -> V_31 ) ;
}
