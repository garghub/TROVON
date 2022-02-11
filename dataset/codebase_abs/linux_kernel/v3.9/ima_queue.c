static struct V_1 * F_1 ( T_1 * V_2 )
{
struct V_1 * V_3 , * V_4 = NULL ;
unsigned int V_5 ;
int V_6 ;
V_5 = F_2 ( V_2 ) ;
F_3 () ;
F_4 (qe, &ima_htable.queue[key], hnext) {
V_6 = memcmp ( V_3 -> V_7 -> V_8 , V_2 , V_9 ) ;
if ( V_6 == 0 ) {
V_4 = V_3 ;
break;
}
}
F_5 () ;
return V_4 ;
}
static int F_6 ( struct V_10 * V_7 )
{
struct V_1 * V_3 ;
unsigned int V_5 ;
V_3 = F_7 ( sizeof( * V_3 ) , V_11 ) ;
if ( V_3 == NULL ) {
F_8 ( L_1 ) ;
return - V_12 ;
}
V_3 -> V_7 = V_7 ;
F_9 ( & V_3 -> V_13 ) ;
F_10 ( & V_3 -> V_13 , & V_14 ) ;
F_11 ( & V_15 . V_16 ) ;
V_5 = F_2 ( V_7 -> V_8 ) ;
F_12 ( & V_3 -> V_17 , & V_15 . V_18 [ V_5 ] ) ;
return 0 ;
}
static int F_13 ( const T_1 * V_19 )
{
int V_20 = 0 ;
if ( ! V_21 )
return V_20 ;
V_20 = F_14 ( V_22 , V_23 , V_19 ) ;
if ( V_20 != 0 )
F_8 ( L_2 ,
V_20 ) ;
return V_20 ;
}
int F_15 ( struct V_10 * V_7 , int V_24 ,
const char * V_25 , struct V_26 * V_26 )
{
T_1 V_8 [ V_9 ] ;
const char * V_27 = L_3 ;
char V_28 [ V_29 ] ;
int V_30 = 1 ;
int V_20 = 0 , V_31 = 0 ;
F_16 ( & V_32 ) ;
if ( ! V_24 ) {
memcpy ( V_8 , V_7 -> V_8 , sizeof V_8 ) ;
if ( F_1 ( V_8 ) ) {
V_27 = L_4 ;
V_20 = - V_33 ;
goto V_34;
}
}
V_20 = F_6 ( V_7 ) ;
if ( V_20 < 0 ) {
V_27 = L_5 ;
V_30 = 0 ;
goto V_34;
}
if ( V_24 )
memset ( V_8 , 0xff , sizeof V_8 ) ;
V_31 = F_13 ( V_8 ) ;
if ( V_31 != 0 ) {
snprintf ( V_28 , V_29 , L_6 ,
V_31 ) ;
V_27 = V_28 ;
V_30 = 0 ;
}
V_34:
F_17 ( & V_32 ) ;
F_18 ( V_35 , V_26 ,
V_7 -> V_36 . V_37 ,
V_25 , V_27 , V_20 , V_30 ) ;
return V_20 ;
}
