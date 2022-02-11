static struct V_1 * F_1 ( T_1 * V_2 ,
int V_3 )
{
struct V_1 * V_4 , * V_5 = NULL ;
unsigned int V_6 ;
int V_7 ;
V_6 = F_2 ( V_2 ) ;
F_3 () ;
F_4 (qe, &ima_htable.queue[key], hnext) {
V_7 = memcmp ( V_4 -> V_8 -> V_9 , V_2 , V_10 ) ;
if ( ( V_7 == 0 ) && ( V_4 -> V_8 -> V_3 == V_3 ) ) {
V_5 = V_4 ;
break;
}
}
F_5 () ;
return V_5 ;
}
static int F_6 ( struct V_11 * V_8 )
{
struct V_1 * V_4 ;
unsigned int V_6 ;
V_4 = F_7 ( sizeof( * V_4 ) , V_12 ) ;
if ( V_4 == NULL ) {
F_8 ( L_1 ) ;
return - V_13 ;
}
V_4 -> V_8 = V_8 ;
F_9 ( & V_4 -> V_14 ) ;
F_10 ( & V_4 -> V_14 , & V_15 ) ;
F_11 ( & V_16 . V_17 ) ;
V_6 = F_2 ( V_8 -> V_9 ) ;
F_12 ( & V_4 -> V_18 , & V_16 . V_19 [ V_6 ] ) ;
return 0 ;
}
static int F_13 ( const T_1 * V_20 , int V_3 )
{
int V_21 = 0 ;
if ( ! V_22 )
return V_21 ;
V_21 = F_14 ( V_23 , V_3 , V_20 ) ;
if ( V_21 != 0 )
F_8 ( L_2 , V_21 ) ;
return V_21 ;
}
int F_15 ( struct V_11 * V_8 , int V_24 ,
const char * V_25 , struct V_26 * V_26 ,
const unsigned char * V_27 )
{
T_1 V_9 [ V_10 ] ;
const char * V_28 = L_3 ;
char V_29 [ V_30 ] ;
int V_31 = 1 ;
int V_21 = 0 , V_32 = 0 ;
F_16 ( & V_33 ) ;
if ( ! V_24 ) {
memcpy ( V_9 , V_8 -> V_9 , sizeof( V_9 ) ) ;
if ( F_1 ( V_9 , V_8 -> V_3 ) ) {
V_28 = L_4 ;
V_21 = - V_34 ;
goto V_35;
}
}
V_21 = F_6 ( V_8 ) ;
if ( V_21 < 0 ) {
V_28 = L_5 ;
V_31 = 0 ;
goto V_35;
}
if ( V_24 )
memset ( V_9 , 0xff , sizeof( V_9 ) ) ;
V_32 = F_13 ( V_9 , V_8 -> V_3 ) ;
if ( V_32 != 0 ) {
snprintf ( V_29 , V_30 , L_6 ,
V_32 ) ;
V_28 = V_29 ;
V_31 = 0 ;
}
V_35:
F_17 ( & V_33 ) ;
F_18 ( V_36 , V_26 , V_27 ,
V_25 , V_28 , V_21 , V_31 ) ;
return V_21 ;
}
