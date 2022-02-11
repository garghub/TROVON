int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
return V_3 [ V_1 ] + ( F_2 ( V_2 ) && V_1 == 1 ) ;
}
int F_3 ( unsigned int V_4 , unsigned int V_1 , unsigned int V_2 )
{
return V_5 [ F_2 ( V_2 ) ] [ V_1 ] + V_4 - 1 ;
}
void F_4 ( T_1 time , struct V_6 * V_7 )
{
unsigned int V_1 , V_2 ;
unsigned long V_8 ;
int V_9 ;
V_9 = F_5 ( time , 86400 ) ;
V_8 = time - ( unsigned int ) V_9 * 86400 ;
V_7 -> V_10 = ( V_9 + 4 ) % 7 ;
V_2 = 1970 + V_9 / 365 ;
V_9 -= ( V_2 - 1970 ) * 365
+ F_6 ( V_2 - 1 )
- F_6 ( 1970 - 1 ) ;
if ( V_9 < 0 ) {
V_2 -= 1 ;
V_9 += 365 + F_2 ( V_2 ) ;
}
V_7 -> V_11 = V_2 - 1900 ;
V_7 -> V_12 = V_9 + 1 ;
for ( V_1 = 0 ; V_1 < 11 ; V_1 ++ ) {
int V_13 ;
V_13 = V_9 - F_1 ( V_1 , V_2 ) ;
if ( V_13 < 0 )
break;
V_9 = V_13 ;
}
V_7 -> V_14 = V_1 ;
V_7 -> V_15 = V_9 + 1 ;
V_7 -> V_16 = V_8 / 3600 ;
V_8 -= V_7 -> V_16 * 3600 ;
V_7 -> V_17 = V_8 / 60 ;
V_7 -> V_18 = V_8 - V_7 -> V_17 * 60 ;
V_7 -> V_19 = 0 ;
}
int F_7 ( struct V_6 * V_7 )
{
if ( V_7 -> V_11 < 70
|| ( ( unsigned ) V_7 -> V_14 ) >= 12
|| V_7 -> V_15 < 1
|| V_7 -> V_15 > F_1 ( V_7 -> V_14 , V_7 -> V_11 + 1900 )
|| ( ( unsigned ) V_7 -> V_16 ) >= 24
|| ( ( unsigned ) V_7 -> V_17 ) >= 60
|| ( ( unsigned ) V_7 -> V_18 ) >= 60 )
return - V_20 ;
return 0 ;
}
T_1 F_8 ( struct V_6 * V_7 )
{
return mktime64 ( V_7 -> V_11 + 1900 , V_7 -> V_14 + 1 , V_7 -> V_15 ,
V_7 -> V_16 , V_7 -> V_17 , V_7 -> V_18 ) ;
}
T_2 F_9 ( struct V_6 V_7 )
{
return F_10 ( F_8 ( & V_7 ) , 0 ) ;
}
struct V_6 F_11 ( T_2 V_21 )
{
struct V_22 V_23 ;
struct V_6 V_24 ;
V_23 = F_12 ( V_21 ) ;
if ( V_23 . V_25 )
V_23 . V_26 ++ ;
F_4 ( V_23 . V_26 , & V_24 ) ;
return V_24 ;
}
