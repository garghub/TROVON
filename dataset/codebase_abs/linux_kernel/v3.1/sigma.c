static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = ( void * ) ( V_4 -> V_7 -> V_8 + V_4 -> V_9 ) ;
T_1 V_10 = F_2 ( V_6 ) ;
int V_11 = 0 ;
F_3 ( L_1 , V_12 ,
V_6 -> V_13 , V_6 -> V_14 , V_10 ) ;
switch ( V_6 -> V_13 ) {
case V_15 :
case V_16 :
case V_17 :
if ( V_4 -> V_7 -> V_18 < V_4 -> V_9 + V_10 )
return - V_19 ;
V_11 = F_4 ( V_2 , ( void * ) & V_6 -> V_14 , V_10 ) ;
if ( V_11 < 0 )
return - V_19 ;
break;
case V_20 :
V_11 = 0 ;
F_5 ( V_10 ) ;
V_10 = 0 ;
break;
case V_21 :
return 1 ;
default:
return - V_19 ;
}
V_4 -> V_9 += F_6 ( V_6 , V_10 ) ;
return V_4 -> V_9 == V_4 -> V_7 -> V_18 ;
}
static int
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_3 ( L_2 , V_12 , V_4 ) ;
while ( 1 ) {
int V_11 = F_1 ( V_2 , V_4 ) ;
F_3 ( L_3 , V_12 , V_11 ) ;
if ( V_11 == 1 )
return 0 ;
else if ( V_11 )
return V_11 ;
}
}
int F_8 ( struct V_1 * V_2 , const char * V_22 )
{
int V_11 ;
struct V_23 * V_24 ;
struct V_3 V_4 ;
const struct V_25 * V_7 ;
T_2 V_26 ;
F_3 ( L_4 , V_12 , V_22 ) ;
V_11 = F_9 ( & V_7 , V_22 , & V_2 -> V_27 ) ;
if ( V_11 ) {
F_3 ( L_5 , V_12 , V_11 ) ;
return V_11 ;
}
V_4 . V_7 = V_7 ;
V_11 = - V_19 ;
if ( V_7 -> V_18 < sizeof( * V_24 ) )
goto V_28;
V_24 = ( void * ) V_7 -> V_8 ;
if ( memcmp ( V_24 -> V_29 , V_30 , F_10 ( V_24 -> V_29 ) ) )
goto V_28;
V_26 = F_11 ( 0 , V_7 -> V_8 , V_7 -> V_18 ) ;
F_3 ( L_6 , V_12 , V_26 ) ;
if ( V_26 != V_24 -> V_26 )
goto V_28;
V_4 . V_9 = sizeof( * V_24 ) ;
V_11 = F_7 ( V_2 , & V_4 ) ;
V_28:
F_12 ( V_7 ) ;
F_3 ( L_7 , V_12 , V_22 ) ;
return V_11 ;
}
