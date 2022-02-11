static inline T_1 F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 << 16 ) | F_2 ( V_2 -> V_4 ) ;
}
static T_2 F_3 ( struct V_1 * V_2 )
{
T_2 V_5 = 0 ;
switch ( V_2 -> V_6 ) {
case V_7 :
case V_8 :
case V_9 :
V_5 = F_1 ( V_2 ) ;
break;
default:
break;
}
V_5 = F_4 ( V_5 , 2 ) ;
return V_5 + sizeof( struct V_1 ) ;
}
static int
F_5 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
T_2 V_4 = F_1 ( V_2 ) ;
int V_12 ;
F_6 ( L_1 , V_13 ,
V_2 -> V_6 , V_2 -> V_14 , V_4 ) ;
switch ( V_2 -> V_6 ) {
case V_7 :
case V_8 :
case V_9 :
V_12 = V_11 -> V_15 ( V_11 -> V_16 , V_2 , V_4 ) ;
if ( V_12 < 0 )
return - V_17 ;
break;
case V_18 :
F_7 ( V_4 ) ;
V_4 = 0 ;
break;
case V_19 :
return 0 ;
default:
return - V_17 ;
}
return 1 ;
}
static int
F_8 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
T_2 V_20 ;
int V_12 ;
while ( V_11 -> V_21 + sizeof( * V_2 ) <= V_11 -> V_22 -> V_20 ) {
V_2 = (struct V_1 * ) ( V_11 -> V_22 -> V_23 + V_11 -> V_21 ) ;
V_20 = F_3 ( V_2 ) ;
V_11 -> V_21 += V_20 ;
if ( V_11 -> V_21 > V_11 -> V_22 -> V_20 || V_20 == 0 )
break;
V_12 = F_5 ( V_11 , V_2 ) ;
F_6 ( L_2 , V_13 , V_12 ) ;
if ( V_12 <= 0 )
return V_12 ;
}
if ( V_11 -> V_21 != V_11 -> V_22 -> V_20 )
return - V_17 ;
return 0 ;
}
int F_9 ( struct V_24 * V_25 ,
struct V_10 * V_11 , const char * V_26 )
{
int V_12 ;
struct V_27 * V_28 ;
const struct V_29 * V_22 ;
T_1 V_30 ;
F_6 ( L_3 , V_13 , V_26 ) ;
V_12 = F_10 ( & V_22 , V_26 , V_25 ) ;
if ( V_12 ) {
F_6 ( L_4 , V_13 , V_12 ) ;
return V_12 ;
}
V_11 -> V_22 = V_22 ;
V_12 = - V_17 ;
if ( V_22 -> V_20 < sizeof( * V_28 ) || V_22 -> V_20 >= 0x4000000 ) {
F_11 ( V_25 , L_5 ) ;
goto V_31;
}
V_28 = ( void * ) V_22 -> V_23 ;
if ( memcmp ( V_28 -> V_32 , V_33 , F_12 ( V_28 -> V_32 ) ) ) {
F_11 ( V_25 , L_6 ) ;
goto V_31;
}
V_30 = F_13 ( 0 , V_22 -> V_23 + sizeof( * V_28 ) ,
V_22 -> V_20 - sizeof( * V_28 ) ) ;
F_6 ( L_7 , V_13 , V_30 ) ;
if ( V_30 != F_14 ( V_28 -> V_30 ) ) {
F_11 ( V_25 , L_8 ,
F_14 ( V_28 -> V_30 ) , V_30 ) ;
goto V_31;
}
V_11 -> V_21 = sizeof( * V_28 ) ;
V_12 = F_8 ( V_11 ) ;
V_31:
F_15 ( V_22 ) ;
F_6 ( L_9 , V_13 , V_26 ) ;
return V_12 ;
}
