static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 ;
}
static inline
struct V_1 * F_3 ( struct V_2 * * V_3 )
{
return F_4 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_5 ( struct V_1 * V_5 )
{
if ( V_5 == NULL )
return;
if ( V_5 -> V_3 != NULL )
F_2 ( V_5 -> V_3 ) -> V_4 = NULL ;
F_6 ( V_5 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
if ( V_7 == NULL )
return;
F_5 ( V_7 -> V_8 ) ;
V_7 -> V_8 = NULL ;
V_7 -> V_9 = NULL ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
struct V_1 * * V_5 )
{
* V_5 = F_9 ( sizeof( struct V_1 ) , V_10 ) ;
if ( * V_5 == NULL )
return - V_11 ;
( * V_5 ) -> V_3 = V_3 ;
( * V_5 ) -> V_7 = V_7 ;
V_7 -> V_8 = * V_5 ;
V_7 -> V_9 = F_7 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_5 )
{
struct V_12 * V_13 = F_2 ( V_5 -> V_3 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_11 ( V_7 -> V_14 , L_1 , sizeof( V_7 -> V_14 ) ) ;
snprintf ( V_7 -> V_15 , sizeof( V_7 -> V_15 ) , L_2 ,
V_13 -> V_16 ) ;
snprintf ( V_7 -> V_17 , sizeof( V_7 -> V_17 ) ,
L_3 ,
V_13 -> V_16 , V_13 -> V_18 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_12 * V_13 = F_2 ( V_3 ) ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_5 ;
int V_19 , V_20 ;
V_20 = V_21 [ V_13 -> V_16 ] == - 1 ? V_22 : V_21 [ V_13 -> V_16 ] ;
V_19 = F_13 ( & V_13 -> V_23 -> V_24 ,
V_20 ,
V_25 ,
V_26 , 0 , & V_7 ) ;
if ( V_19 ) {
F_14 ( L_4 ,
V_27 , V_19 ) ;
goto V_28;
}
V_19 = F_8 ( V_3 , V_7 , & V_5 ) ;
if ( V_19 ) {
F_14 ( L_5 ,
V_27 , V_19 ) ;
goto V_29;
}
F_10 ( V_5 ) ;
#if 0
ret = snd_ivtv_mixer_create(itvsc);
if (ret) {
IVTV_ALSA_WARN("%s: snd_ivtv_mixer_create() failed with err %d:"
" proceeding anyway\n", __func__, ret);
}
#endif
V_19 = F_15 ( V_5 ) ;
if ( V_19 ) {
F_14 ( L_6 ,
V_27 , V_19 ) ;
goto V_29;
}
V_13 -> V_4 = V_5 ;
V_19 = F_16 ( V_7 ) ;
if ( V_19 ) {
V_13 -> V_4 = NULL ;
F_14 ( L_7 ,
V_27 , V_19 ) ;
goto V_29;
}
F_17 ( L_8 ,
V_27 , V_13 -> V_16 , V_7 -> V_30 ) ;
return 0 ;
V_29:
if ( V_7 != NULL )
F_18 ( V_7 ) ;
F_6 ( V_5 ) ;
V_28:
return V_19 ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = & V_13 -> V_3 ;
struct V_31 * V_32 ;
if ( V_3 == NULL ) {
F_20 ( L_9 ,
V_27 ) ;
return 0 ;
}
V_13 = F_2 ( V_3 ) ;
if ( V_13 == NULL ) {
F_20 ( L_10 ) ;
return 0 ;
}
V_32 = & V_13 -> V_33 [ V_34 ] ;
if ( V_32 -> V_35 . V_3 == NULL ) {
F_21 ( L_11
L_12 , V_27 ) ;
return 0 ;
}
if ( V_13 -> V_4 != NULL ) {
F_14 ( L_13 ,
V_27 ) ;
return 0 ;
}
if ( F_12 ( V_3 ) ) {
F_14 ( L_14 ,
V_27 ) ;
} else {
F_21 ( L_15
L_16 , V_27 ) ;
}
return 0 ;
}
static int T_1 F_22 ( void )
{
F_23 ( L_17 ) ;
V_36 = & F_19 ;
return 0 ;
}
static void T_2 F_24 ( struct V_1 * V_5 )
{
struct V_12 * V_13 = F_2 ( V_5 -> V_3 ) ;
F_18 ( V_5 -> V_7 ) ;
V_13 -> V_4 = NULL ;
}
static int T_2 F_25 ( struct V_37 * V_24 , void * V_38 )
{
struct V_2 * V_3 = F_26 ( V_24 ) ;
struct V_1 * V_5 ;
if ( V_3 == NULL ) {
F_20 ( L_9 ,
V_27 ) ;
return 0 ;
}
V_5 = F_1 ( V_3 ) ;
if ( V_5 == NULL ) {
F_27 ( L_18 ,
V_27 ) ;
return 0 ;
}
F_24 ( V_5 ) ;
return 0 ;
}
static void T_2 F_28 ( void )
{
struct V_39 * V_40 ;
int V_19 ;
F_23 ( L_19 ) ;
V_40 = F_29 ( L_20 , & V_41 ) ;
V_19 = F_30 ( V_40 , NULL , NULL , F_25 ) ;
( void ) V_19 ;
V_36 = NULL ;
F_23 ( L_21 ) ;
}
