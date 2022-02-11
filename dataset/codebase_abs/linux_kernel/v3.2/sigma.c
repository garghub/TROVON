static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
switch ( V_2 -> V_4 ) {
case V_5 :
case V_6 :
case V_7 :
V_3 = F_2 ( V_2 ) ;
break;
default:
break;
}
V_3 = F_3 ( V_3 , 2 ) ;
return V_3 + sizeof( struct V_1 ) ;
}
static int
F_4 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
T_1 V_10 = F_2 ( V_2 ) ;
int V_11 ;
F_5 ( L_1 , V_12 ,
V_2 -> V_4 , V_2 -> V_13 , V_10 ) ;
switch ( V_2 -> V_4 ) {
case V_5 :
case V_6 :
case V_7 :
V_11 = F_6 ( V_9 , ( void * ) & V_2 -> V_13 , V_10 ) ;
if ( V_11 < 0 )
return - V_14 ;
break;
case V_15 :
F_7 ( V_10 ) ;
V_10 = 0 ;
break;
case V_16 :
return 0 ;
default:
return - V_14 ;
}
return 1 ;
}
static int
F_8 ( struct V_8 * V_9 , struct V_17 * V_18 )
{
struct V_1 * V_2 ;
T_1 V_19 ;
int V_11 ;
while ( V_18 -> V_20 + sizeof( * V_2 ) <= V_18 -> V_21 -> V_19 ) {
V_2 = (struct V_1 * ) ( V_18 -> V_21 -> V_22 + V_18 -> V_20 ) ;
V_19 = F_1 ( V_2 ) ;
V_18 -> V_20 += V_19 ;
if ( V_18 -> V_20 > V_18 -> V_21 -> V_19 || V_19 == 0 )
break;
V_11 = F_4 ( V_9 , V_2 ) ;
F_5 ( L_2 , V_12 , V_11 ) ;
if ( V_11 <= 0 )
return V_11 ;
}
if ( V_18 -> V_20 != V_18 -> V_21 -> V_19 )
return - V_14 ;
return 0 ;
}
int F_9 ( struct V_8 * V_9 , const char * V_23 )
{
int V_11 ;
struct V_24 * V_25 ;
struct V_17 V_18 ;
const struct V_26 * V_21 ;
T_2 V_27 ;
F_5 ( L_3 , V_12 , V_23 ) ;
V_11 = F_10 ( & V_21 , V_23 , & V_9 -> V_28 ) ;
if ( V_11 ) {
F_5 ( L_4 , V_12 , V_11 ) ;
return V_11 ;
}
V_18 . V_21 = V_21 ;
V_11 = - V_14 ;
if ( V_21 -> V_19 < sizeof( * V_25 ) || V_21 -> V_19 >= 0x4000000 )
goto V_29;
V_25 = ( void * ) V_21 -> V_22 ;
if ( memcmp ( V_25 -> V_30 , V_31 , F_11 ( V_25 -> V_30 ) ) )
goto V_29;
V_27 = F_12 ( 0 , V_21 -> V_22 + sizeof( * V_25 ) ,
V_21 -> V_19 - sizeof( * V_25 ) ) ;
F_5 ( L_5 , V_12 , V_27 ) ;
if ( V_27 != F_13 ( V_25 -> V_27 ) )
goto V_29;
V_18 . V_20 = sizeof( * V_25 ) ;
V_11 = F_8 ( V_9 , & V_18 ) ;
V_29:
F_14 ( V_21 ) ;
F_5 ( L_6 , V_12 , V_23 ) ;
return V_11 ;
}
