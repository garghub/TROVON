static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 ;
const char * V_5 , * V_6 ;
struct V_7 * V_8 = V_2 -> V_9 . V_10 ;
struct V_11 * V_11 ;
T_1 V_12 ;
int V_13 ;
V_11 = F_2 ( V_8 ) ;
if ( F_3 ( V_11 ) ) {
F_4 ( & V_2 -> V_9 , L_1 ) ;
return F_5 ( V_11 ) ;
}
V_13 = F_6 ( V_11 , V_14 , & V_12 ) ;
if ( V_13 ) {
F_4 ( & V_2 -> V_9 , L_2 ) ;
return V_13 ;
}
V_3 = V_12 & V_15 ;
switch ( V_3 ) {
case 0x0 :
case 0x1 :
V_4 = 2000 ;
break;
case 0x6 :
case 0x7 :
V_4 = 1800 ;
break;
case 0x4 :
case 0xB :
case 0xD :
V_4 = 1600 ;
break;
case 0x1a :
V_4 = 1400 ;
break;
case 0x14 :
case 0x17 :
V_4 = 1300 ;
break;
case 0x19 :
V_4 = 1200 ;
break;
case 0x13 :
case 0x1d :
V_4 = 1000 ;
break;
case 0x1c :
V_4 = 800 ;
break;
case 0x1b :
V_4 = 600 ;
break;
default:
F_4 ( & V_2 -> V_9 , L_3 ) ;
return - V_16 ;
}
V_4 *= 1000 * 1000 ;
F_7 ( V_8 , L_4 ,
0 , & V_5 ) ;
V_17 [ 0 ] = F_8 ( & V_2 -> V_9 , V_5 , NULL ,
0 , V_4 ) ;
if ( F_3 ( V_17 [ 0 ] ) ) {
V_13 = F_5 ( V_17 [ 0 ] ) ;
goto V_18;
}
F_7 ( V_8 , L_4 ,
1 , & V_5 ) ;
V_17 [ 1 ] = F_8 ( & V_2 -> V_9 , V_5 , NULL , 0 ,
V_4 ) ;
if ( F_3 ( V_17 [ 1 ] ) ) {
V_13 = F_5 ( V_17 [ 1 ] ) ;
goto V_19;
}
F_7 ( V_8 , L_4 ,
2 , & V_6 ) ;
V_17 [ 2 ] = F_8 ( & V_2 -> V_9 , V_6 , NULL ,
0 , 1200 * 1000 * 1000 ) ;
if ( F_3 ( V_17 [ 2 ] ) ) {
V_13 = F_5 ( V_17 [ 2 ] ) ;
goto V_20;
}
F_7 ( V_8 , L_4 ,
3 , & V_5 ) ;
V_17 [ 3 ] = F_9 ( NULL , V_5 , V_6 ,
0 , 1 , 6 ) ;
if ( F_3 ( V_17 [ 3 ] ) ) {
V_13 = F_5 ( V_17 [ 3 ] ) ;
goto V_21;
}
if ( F_7 ( V_8 , L_4 ,
4 , & V_5 ) ) {
V_22 . V_23 -- ;
F_10 ( & V_2 -> V_9 ,
L_5 ) ;
} else {
V_17 [ 4 ] = F_9 ( NULL , V_5 ,
V_6 ,
0 , 1 , 3 ) ;
if ( F_3 ( V_17 [ 4 ] ) ) {
V_13 = F_5 ( V_17 [ 4 ] ) ;
goto V_24;
}
}
F_11 ( V_8 , V_25 , & V_22 ) ;
V_13 = F_11 ( V_8 , V_25 , & V_22 ) ;
if ( V_13 )
goto V_26;
return 0 ;
V_26:
F_12 ( V_17 [ 4 ] ) ;
V_24:
F_12 ( V_17 [ 3 ] ) ;
V_21:
F_13 ( V_17 [ 2 ] ) ;
V_20:
F_13 ( V_17 [ 1 ] ) ;
V_19:
F_13 ( V_17 [ 0 ] ) ;
V_18:
return V_13 ;
}
