static unsigned int F_1 ( struct V_1 * V_2 )
{
return 150000000 ;
}
static void F_2 ( struct V_1 * V_2 , unsigned int clock )
{
struct V_3 * V_4 = F_3 ( V_2 -> V_5 ) ;
int div = 1 ;
T_1 V_6 ;
unsigned long V_7 ;
if ( clock == V_2 -> clock )
return;
F_4 ( V_2 , 0 , V_8 ) ;
if ( clock == 0 )
goto V_9;
while ( V_2 -> V_10 / div > clock ) {
if ( div < 4 )
div += 1 ;
else if ( div < 256 )
div *= 2 ;
else
break;
}
F_5 ( V_4 , L_1 ,
clock , V_2 -> V_10 / div ) ;
if ( div != 3 )
div >>= 1 ;
V_6 = div << V_11 ;
V_6 |= V_12 ;
F_4 ( V_2 , V_6 , V_8 ) ;
V_7 = 20 ;
while ( ! ( ( V_6 = F_6 ( V_2 , V_8 ) )
& V_13 ) ) {
if ( V_7 == 0 ) {
F_7 ( V_4 , L_2 ) ;
break;
}
V_7 -- ;
F_8 ( 1 ) ;
}
V_6 |= V_14 ;
F_4 ( V_2 , V_6 , V_8 ) ;
V_9:
V_2 -> clock = clock ;
}
static int F_9 ( struct V_15 * V_16 )
{
return F_10 ( V_16 , & V_17 , 0 ) ;
}
static int F_11 ( struct V_15 * V_16 )
{
return F_12 ( V_16 ) ;
}
