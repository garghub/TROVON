int F_1 ( struct V_1 * V_2 ,
int V_3 , struct V_4 * V_4 )
{
const char * V_5 = L_1 ;
const char * V_6 = L_2 ;
int V_7 ;
memset ( V_2 -> V_8 , 0 , sizeof( V_2 -> V_8 ) ) ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = sizeof( V_2 -> V_12 ) ;
if ( ! V_3 ) {
V_7 = F_2 ( V_2 -> V_11 ,
& V_2 -> V_12 ,
V_2 -> V_8 ) ;
if ( V_7 < 0 ) {
F_3 ( V_13 , V_4 ,
V_2 -> V_9 , V_5 ,
V_6 , V_7 , 0 ) ;
return V_7 ;
}
}
V_7 = F_4 ( V_2 , V_3 , V_5 , V_4 ) ;
return V_7 ;
}
void F_5 ( struct V_4 * V_4 , const unsigned char * V_14 ,
const char * V_5 , const char * V_15 )
{
struct V_1 * V_2 ;
int V_3 = 1 ;
int V_7 ;
F_6 ( & V_16 . V_17 ) ;
V_2 = F_7 ( sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 ) {
V_7 = - V_19 ;
goto V_20;
}
memset ( & V_2 -> V_12 , 0 , sizeof( V_2 -> V_12 ) ) ;
strncpy ( V_2 -> V_12 . V_21 , V_14 , V_22 ) ;
V_7 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_7 < 0 )
F_8 ( V_2 ) ;
V_20:
F_3 ( V_13 , V_4 , V_14 ,
V_5 , V_15 , V_7 , 0 ) ;
}
int F_9 ( struct V_4 * V_4 , int V_23 , int V_24 )
{
int V_25 ;
V_25 = F_10 ( V_4 , V_24 , V_23 ) ;
return V_25 ? 0 : - V_26 ;
}
int F_11 ( struct V_27 * V_28 , struct V_29 * V_29 )
{
int V_7 = - V_30 ;
if ( ! ( V_28 -> V_31 & V_32 ) ) {
T_1 V_33 = V_29 -> V_34 -> V_35 -> V_33 ;
memset ( V_28 -> V_8 , 0 , V_36 ) ;
V_7 = F_12 ( V_29 , V_28 -> V_8 ) ;
if ( ! V_7 )
V_28 -> V_37 = V_33 ;
}
return V_7 ;
}
void F_13 ( struct V_27 * V_28 , struct V_29 * V_29 ,
const unsigned char * V_14 )
{
const char * V_5 = L_1 ;
const char * V_6 = L_3 ;
int V_7 = - V_19 ;
struct V_4 * V_4 = V_29 -> V_34 -> V_35 ;
struct V_1 * V_2 ;
int V_3 = 0 ;
V_2 = F_7 ( sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 ) {
F_3 ( V_13 , V_4 , V_14 ,
V_5 , V_6 , V_7 , 0 ) ;
return;
}
memset ( & V_2 -> V_12 , 0 , sizeof( V_2 -> V_12 ) ) ;
memcpy ( V_2 -> V_12 . V_8 , V_28 -> V_8 , V_36 ) ;
strncpy ( V_2 -> V_12 . V_21 , V_14 , V_22 ) ;
V_7 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_7 )
V_28 -> V_31 |= V_32 ;
else
F_8 ( V_2 ) ;
}
