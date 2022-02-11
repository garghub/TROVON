static struct V_1 * F_1 ( T_1 * V_2 )
{
struct V_1 * V_3 , * V_4 = NULL ;
unsigned int V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_5 = F_2 ( V_2 ) ;
F_3 () ;
F_4 (qe, pos, &ima_htable.queue[key], hnext) {
V_8 = memcmp ( V_3 -> V_9 -> V_10 , V_2 , V_11 ) ;
if ( V_8 == 0 ) {
V_4 = V_3 ;
break;
}
}
F_5 () ;
return V_4 ;
}
static int F_6 ( struct V_12 * V_9 )
{
struct V_1 * V_3 ;
unsigned int V_5 ;
V_3 = F_7 ( sizeof( * V_3 ) , V_13 ) ;
if ( V_3 == NULL ) {
F_8 ( L_1 ) ;
return - V_14 ;
}
V_3 -> V_9 = V_9 ;
F_9 ( & V_3 -> V_15 ) ;
F_10 ( & V_3 -> V_15 , & V_16 ) ;
F_11 ( & V_17 . V_18 ) ;
V_5 = F_2 ( V_9 -> V_10 ) ;
F_12 ( & V_3 -> V_19 , & V_17 . V_20 [ V_5 ] ) ;
return 0 ;
}
static int F_13 ( const T_1 * V_21 )
{
int V_22 = 0 ;
if ( ! V_23 )
return V_22 ;
V_22 = F_14 ( V_24 , V_25 , V_21 ) ;
if ( V_22 != 0 )
F_8 ( L_2 ) ;
return V_22 ;
}
int F_15 ( struct V_12 * V_9 , int V_26 ,
const char * V_27 , struct V_28 * V_28 )
{
T_1 V_10 [ V_11 ] ;
const char * V_29 = L_3 ;
int V_30 = 1 ;
int V_22 = 0 ;
F_16 ( & V_31 ) ;
if ( ! V_26 ) {
memcpy ( V_10 , V_9 -> V_10 , sizeof V_10 ) ;
if ( F_1 ( V_10 ) ) {
V_29 = L_4 ;
goto V_32;
}
}
V_22 = F_6 ( V_9 ) ;
if ( V_22 < 0 ) {
V_29 = L_5 ;
V_30 = 0 ;
goto V_32;
}
if ( V_26 )
memset ( V_10 , 0xff , sizeof V_10 ) ;
V_22 = F_13 ( V_10 ) ;
if ( V_22 != 0 ) {
V_29 = L_6 ;
V_30 = 0 ;
}
V_32:
F_17 ( & V_31 ) ;
F_18 ( V_33 , V_28 ,
V_9 -> V_34 . V_35 ,
V_27 , V_29 , V_22 , V_30 ) ;
return V_22 ;
}
