static inline void F_1 ( unsigned char V_1 , unsigned char V_2 )
{
F_2 ( V_2 , V_3 + V_1 ) ;
}
static inline unsigned char F_3 ( unsigned char V_1 )
{
return F_4 ( V_3 + V_1 ) ;
}
static inline void F_5 ( int V_4 , const struct V_5 * V_6 )
{
T_1 V_7 = F_3 ( V_6 -> V_8 ) ;
if ( ( V_6 -> V_9 && ! V_4 ) || ( ! V_6 -> V_9 && V_4 ) )
F_1 ( V_6 -> V_8 , V_7 | V_6 -> V_10 ) ;
else
F_1 ( V_6 -> V_8 , V_7 & ~ V_6 -> V_10 ) ;
}
static inline int F_6 ( const struct V_5 * V_6 )
{
T_1 V_7 = F_3 ( V_6 -> V_8 ) ;
return ( ( V_6 -> V_9 && ( V_7 & V_6 -> V_10 ) != V_6 -> V_10 )
|| ( ! V_6 -> V_9 && ( V_7 & V_6 -> V_10 ) == V_6 -> V_10 ) ) ;
}
static void F_7 ( void * V_11 , int V_4 )
{
F_5 ( V_4 , & V_12 [ type ] . V_13 ) ;
}
static void F_8 ( void * V_11 , int V_4 )
{
F_5 ( V_4 , & V_12 [ type ] . V_14 ) ;
}
static int F_9 ( void * V_11 )
{
return F_6 ( & V_12 [ type ] . V_15 ) ;
}
static int F_10 ( void * V_11 )
{
return F_6 ( & V_12 [ type ] . V_16 ) ;
}
static int F_11 ( struct V_17 * V_18 )
{
int V_19 ;
F_8 ( NULL , 1 ) ;
F_7 ( NULL , 1 ) ;
if ( V_12 [ type ] . V_20 . V_10 ) {
F_5 ( 1 , & V_12 [ type ] . V_20 ) ;
F_12 ( 100 ) ;
}
V_21 . V_22 . V_23 = & V_18 -> V_22 ;
V_19 = F_13 ( & V_21 ) ;
if ( V_19 ) {
F_14 ( & V_18 -> V_22 , L_1 ) ;
return V_19 ;
}
if ( V_12 [ type ] . V_24 && V_25 ) {
V_26 . V_25 = V_25 ;
V_27 = F_15 ( & V_21 , & V_26 ) ;
if ( V_27 )
F_5 ( 1 , & V_28 ) ;
else
F_16 ( & V_18 -> V_22 , L_2 ) ;
}
return 0 ;
}
static int F_17 ( struct V_17 * V_18 )
{
if ( V_27 ) {
F_5 ( 0 , & V_28 ) ;
F_18 ( V_27 ) ;
V_27 = NULL ;
}
F_19 ( & V_21 ) ;
if ( V_12 [ type ] . V_20 . V_10 )
F_5 ( 0 , & V_12 [ type ] . V_20 ) ;
return 0 ;
}
static int T_2 F_20 ( T_3 V_29 )
{
int V_19 ;
V_18 = F_21 ( V_30 , - 1 ) ;
if ( ! V_18 ) {
V_19 = - V_31 ;
F_22 (KERN_ERR DRVNAME L_3 ) ;
goto exit;
}
V_19 = F_23 ( V_18 ) ;
if ( V_19 ) {
F_22 (KERN_ERR DRVNAME L_4 ,
err) ;
goto V_32;
}
return 0 ;
V_32:
F_24 ( V_18 ) ;
exit:
return V_19 ;
}
static int T_2 F_25 ( void )
{
int V_19 ;
if ( type < 0 ) {
F_22 (KERN_ERR DRVNAME L_5 ) ;
return - V_33 ;
}
if ( type >= F_26 ( V_12 ) ) {
F_22 (KERN_ERR DRVNAME L_6 , type) ;
return - V_33 ;
}
if ( V_3 == 0 ) {
F_27 ( V_30 L_7 , V_34 ) ;
V_3 = V_34 ;
}
if ( ! F_28 ( V_3 , 3 , V_30 ) )
return - V_35 ;
if ( V_25 != 0 )
F_27 ( V_30 L_8 , V_25 ) ;
if ( ! V_12 [ type ] . V_15 . V_10 )
V_36 . V_15 = NULL ;
V_19 = F_20 ( V_3 ) ;
if ( V_19 )
goto V_37;
V_19 = F_29 ( & V_38 ) ;
if ( V_19 )
goto V_39;
return 0 ;
V_39:
F_30 ( V_18 ) ;
V_37:
F_31 ( V_3 , 3 ) ;
return V_19 ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_38 ) ;
F_30 ( V_18 ) ;
F_31 ( V_3 , 3 ) ;
}
