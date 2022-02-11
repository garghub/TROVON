static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 , V_8 , V_9 , V_10 = 0 ;
const struct V_11 * V_11 ;
unsigned char * V_12 = F_3 ( 50 , V_13 ) ;
unsigned char V_14 [ 4 ] ;
const T_1 * V_15 ;
if ( ! V_12 )
return - V_16 ;
if ( F_4 ( & V_11 , L_1 , & V_6 -> V_6 ) != 0 ) {
F_5 ( V_17 L_2 ) ;
V_10 = - V_18 ;
goto V_19;
}
V_15 = V_11 -> V_14 ;
if ( F_6
( V_6 , F_7 ( V_6 , 0 ) , 0xa0 , 0x40 , 0xe600 , 0 , L_3 , 1 ,
300 ) != 1 ) {
F_5 ( V_17
L_4 ) ;
V_10 = - V_18 ;
goto V_19;
}
while ( V_15 + 4 <= V_11 -> V_14 + V_11 -> V_20 ) {
memcpy ( V_14 , V_15 , 4 ) ;
V_8 = ( V_14 [ 0 ] << 8 | V_14 [ 1 ] ) ;
V_9 = ( V_14 [ 2 ] << 8 | V_14 [ 3 ] ) ;
V_15 += 4 ;
if ( V_8 == 0x8001 )
break;
else if ( V_8 == 0 )
continue;
for (; V_8 > 0 ; V_9 += 50 ) {
V_7 = F_8 ( V_8 , 50 ) ;
V_8 -= V_7 ;
if ( V_15 + V_7 > V_11 -> V_14 + V_11 -> V_20 ) {
F_5 ( V_17
L_5 ) ;
V_10 = - V_18 ;
goto V_19;
}
memcpy ( V_12 , V_15 , V_7 ) ;
V_15 += V_7 ;
if ( F_6
( V_6 , F_7 ( V_6 , 0 ) , 0xa0 , 0x40 , V_9 , 0 ,
V_12 , V_7 , 300 ) != V_7 ) {
F_5 ( V_17
L_6 ) ;
V_10 = - V_18 ;
goto V_19;
}
}
}
if ( F_6
( V_6 , F_7 ( V_6 , 0 ) , 0xa0 , 0x40 , 0xe600 , 0 , L_7 , 1 ,
300 ) != 1 ) {
F_5 ( V_17 L_8 ) ;
V_10 = - V_18 ;
}
V_19:
F_9 ( V_12 ) ;
F_10 ( V_11 ) ;
return V_10 ;
}
static void F_11 ( struct V_1 * V_2 )
{
}
static int T_2 F_12 ( void )
{
return F_13 ( & V_21 ) ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_21 ) ;
}
