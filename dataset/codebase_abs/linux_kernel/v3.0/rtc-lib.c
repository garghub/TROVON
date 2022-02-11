int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
return V_3 [ V_1 ] + ( F_2 ( V_2 ) && V_1 == 1 ) ;
}
int F_3 ( unsigned int V_4 , unsigned int V_1 , unsigned int V_2 )
{
return V_5 [ F_2 ( V_2 ) ] [ V_1 ] + V_4 - 1 ;
}
void F_4 ( unsigned long time , struct V_6 * V_7 )
{
unsigned int V_1 , V_2 ;
int V_8 ;
V_8 = time / 86400 ;
time -= ( unsigned int ) V_8 * 86400 ;
V_7 -> V_9 = ( V_8 + 4 ) % 7 ;
V_2 = 1970 + V_8 / 365 ;
V_8 -= ( V_2 - 1970 ) * 365
+ F_5 ( V_2 - 1 )
- F_5 ( 1970 - 1 ) ;
if ( V_8 < 0 ) {
V_2 -= 1 ;
V_8 += 365 + F_2 ( V_2 ) ;
}
V_7 -> V_10 = V_2 - 1900 ;
V_7 -> V_11 = V_8 + 1 ;
for ( V_1 = 0 ; V_1 < 11 ; V_1 ++ ) {
int V_12 ;
V_12 = V_8 - F_1 ( V_1 , V_2 ) ;
if ( V_12 < 0 )
break;
V_8 = V_12 ;
}
V_7 -> V_13 = V_1 ;
V_7 -> V_14 = V_8 + 1 ;
V_7 -> V_15 = time / 3600 ;
time -= V_7 -> V_15 * 3600 ;
V_7 -> V_16 = time / 60 ;
V_7 -> V_17 = time - V_7 -> V_16 * 60 ;
}
int F_6 ( struct V_6 * V_7 )
{
if ( V_7 -> V_10 < 70
|| ( ( unsigned ) V_7 -> V_13 ) >= 12
|| V_7 -> V_14 < 1
|| V_7 -> V_14 > F_1 ( V_7 -> V_13 , V_7 -> V_10 + 1900 )
|| ( ( unsigned ) V_7 -> V_15 ) >= 24
|| ( ( unsigned ) V_7 -> V_16 ) >= 60
|| ( ( unsigned ) V_7 -> V_17 ) >= 60 )
return - V_18 ;
return 0 ;
}
int F_7 ( struct V_6 * V_7 , unsigned long * time )
{
* time = mktime ( V_7 -> V_10 + 1900 , V_7 -> V_13 + 1 , V_7 -> V_14 ,
V_7 -> V_15 , V_7 -> V_16 , V_7 -> V_17 ) ;
return 0 ;
}
T_1 F_8 ( struct V_6 V_7 )
{
T_2 time ;
F_7 ( & V_7 , & time ) ;
return F_9 ( time , 0 ) ;
}
struct V_6 F_10 ( T_1 V_19 )
{
struct V_20 V_21 ;
struct V_6 V_22 ;
V_21 = F_11 ( V_19 ) ;
if ( V_21 . V_23 )
V_21 . V_24 ++ ;
F_4 ( V_21 . V_24 , & V_22 ) ;
return V_22 ;
}
