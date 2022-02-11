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
int V_12 = 0 ;
V_12 += sizeof( V_13 ) ;
V_12 += sizeof( V_8 -> V_9 ) ;
V_12 += sizeof( int ) ;
V_12 += strlen ( V_8 -> V_14 -> V_15 ) + 1 ;
V_12 += sizeof( V_8 -> V_16 ) ;
V_12 += V_8 -> V_16 ;
return V_12 ;
}
static int F_7 ( struct V_11 * V_8 ,
bool V_17 )
{
struct V_1 * V_4 ;
unsigned int V_6 ;
V_4 = F_8 ( sizeof( * V_4 ) , V_18 ) ;
if ( V_4 == NULL ) {
F_9 ( L_1 ) ;
return - V_19 ;
}
V_4 -> V_8 = V_8 ;
F_10 ( & V_4 -> V_20 ) ;
F_11 ( & V_4 -> V_20 , & V_21 ) ;
F_12 ( & V_22 . V_23 ) ;
if ( V_17 ) {
V_6 = F_2 ( V_8 -> V_9 ) ;
F_13 ( & V_4 -> V_24 , & V_22 . V_25 [ V_6 ] ) ;
}
if ( V_26 != V_27 ) {
int V_12 ;
V_12 = F_6 ( V_8 ) ;
V_26 = ( V_26 < V_27 - V_12 ) ?
V_26 + V_12 : V_27 ;
}
return 0 ;
}
unsigned long F_14 ( void )
{
if ( V_26 >= ( V_27 - sizeof( struct V_28 ) ) )
return V_27 ;
else
return V_26 + sizeof( struct V_28 ) ;
}
static int F_15 ( const T_1 * V_29 , int V_3 )
{
int V_30 = 0 ;
if ( ! V_31 )
return V_30 ;
V_30 = F_16 ( V_32 , V_3 , V_29 ) ;
if ( V_30 != 0 )
F_9 ( L_2 , V_30 ) ;
return V_30 ;
}
int F_17 ( struct V_11 * V_8 , int V_33 ,
const char * V_34 , struct V_35 * V_35 ,
const unsigned char * V_36 )
{
T_1 V_9 [ V_10 ] ;
const char * V_37 = L_3 ;
char V_38 [ V_39 ] ;
int V_40 = 1 ;
int V_30 = 0 , V_41 = 0 ;
F_18 ( & V_42 ) ;
if ( ! V_33 ) {
memcpy ( V_9 , V_8 -> V_9 , sizeof( V_9 ) ) ;
if ( F_1 ( V_9 , V_8 -> V_3 ) ) {
V_37 = L_4 ;
V_30 = - V_43 ;
goto V_44;
}
}
V_30 = F_7 ( V_8 , 1 ) ;
if ( V_30 < 0 ) {
V_37 = L_5 ;
V_40 = 0 ;
goto V_44;
}
if ( V_33 )
memset ( V_9 , 0xff , sizeof( V_9 ) ) ;
V_41 = F_15 ( V_9 , V_8 -> V_3 ) ;
if ( V_41 != 0 ) {
snprintf ( V_38 , V_39 , L_6 ,
V_41 ) ;
V_37 = V_38 ;
V_40 = 0 ;
}
V_44:
F_19 ( & V_42 ) ;
F_20 ( V_45 , V_35 , V_36 ,
V_34 , V_37 , V_30 , V_40 ) ;
return V_30 ;
}
int F_21 ( struct V_11 * V_8 )
{
int V_30 = 0 ;
F_18 ( & V_42 ) ;
V_30 = F_7 ( V_8 , 0 ) ;
F_19 ( & V_42 ) ;
return V_30 ;
}
