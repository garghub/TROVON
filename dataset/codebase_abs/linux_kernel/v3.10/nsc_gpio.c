void F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_4 = V_2 -> V_5 ( V_3 , ~ 0 , 0 ) ;
F_2 ( V_2 -> V_6 , L_1 ,
V_3 , V_4 ,
( V_4 & 1 ) ? L_2 : L_3 ,
( V_4 & 2 ) ? L_4 : L_5 ,
( V_4 & 4 ) ? L_6 : L_7 ,
( V_4 & 8 ) ? L_8 : L_9 ,
( V_4 & 16 ) ? L_10 : L_11 ,
( V_4 & 32 ) ? L_12 : L_13 ,
( V_4 & 64 ) ? L_14 : L_9 ,
V_2 -> V_7 ( V_3 ) , V_2 -> V_8 ( V_3 ) ) ;
}
T_2 F_3 ( struct V_9 * V_9 , const char T_3 * V_10 ,
T_4 V_11 , T_5 * V_12 )
{
unsigned V_13 = F_4 ( F_5 ( V_9 ) ) ;
struct V_1 * V_2 = V_9 -> V_14 ;
struct V_15 * V_6 = V_2 -> V_6 ;
T_4 V_16 ;
int V_17 = 0 ;
for ( V_16 = 0 ; V_16 < V_11 ; ++ V_16 ) {
char V_18 ;
if ( F_6 ( V_18 , V_10 + V_16 ) )
return - V_19 ;
switch ( V_18 ) {
case '0' :
V_2 -> V_20 ( V_13 , 0 ) ;
break;
case '1' :
V_2 -> V_20 ( V_13 , 1 ) ;
break;
case 'O' :
F_7 ( V_6 , L_15 , V_13 ) ;
V_2 -> V_5 ( V_13 , ~ 1 , 1 ) ;
break;
case 'o' :
F_7 ( V_6 , L_16 , V_13 ) ;
V_2 -> V_5 ( V_13 , ~ 1 , 0 ) ;
break;
case 'T' :
F_7 ( V_6 , L_17 , V_13 ) ;
V_2 -> V_5 ( V_13 , ~ 2 , 2 ) ;
break;
case 't' :
F_7 ( V_6 , L_18 , V_13 ) ;
V_2 -> V_5 ( V_13 , ~ 2 , 0 ) ;
break;
case 'P' :
F_7 ( V_6 , L_19 , V_13 ) ;
V_2 -> V_5 ( V_13 , ~ 4 , 4 ) ;
break;
case 'p' :
F_7 ( V_6 , L_20 , V_13 ) ;
V_2 -> V_5 ( V_13 , ~ 4 , 0 ) ;
break;
case 'v' :
V_2 -> V_21 ( V_2 , V_13 ) ;
break;
case '\n' :
break;
default:
F_8 ( V_6 , L_21 ,
V_13 , ( int ) V_18 ) ;
V_17 ++ ;
}
}
if ( V_17 )
return - V_22 ;
return V_11 ;
}
T_2 F_9 ( struct V_9 * V_9 , char T_3 * V_23 ,
T_4 V_11 , T_5 * V_12 )
{
unsigned V_13 = F_4 ( F_5 ( V_9 ) ) ;
int V_24 ;
struct V_1 * V_2 = V_9 -> V_14 ;
V_24 = V_2 -> V_7 ( V_13 ) ;
if ( F_10 ( V_24 ? '1' : '0' , V_23 ) )
return - V_19 ;
return 1 ;
}
static int T_6 F_11 ( void )
{
F_12 (KERN_DEBUG NAME L_22 ) ;
return 0 ;
}
static void T_7 F_13 ( void )
{
F_12 (KERN_DEBUG NAME L_23 ) ;
}
