static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 (priv != NULL, return -1;) ;
F_2 (priv->magic == IRTTY_MAGIC, return -1;) ;
return F_3 ( V_4 -> V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_6 * V_5 ;
F_2 (priv != NULL, return;) ;
F_2 (priv->magic == IRTTY_MAGIC, return;) ;
V_5 = V_4 -> V_5 ;
if ( V_5 -> V_7 -> V_8 ) {
V_5 -> V_7 -> V_8 ( V_5 , F_5 ( 100 ) ) ;
}
else {
F_6 ( V_9 ) ;
}
}
static int F_7 ( struct V_1 * V_2 , unsigned V_10 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_6 * V_5 ;
struct V_11 V_12 ;
int V_13 ;
F_2 (priv != NULL, return -1;) ;
F_2 (priv->magic == IRTTY_MAGIC, return -1;) ;
V_5 = V_4 -> V_5 ;
F_8 ( & V_5 -> V_14 ) ;
V_12 = V_5 -> V_15 ;
V_13 = V_5 -> V_15 . V_16 ;
F_9 ( V_5 , V_10 , V_10 ) ;
if ( V_5 -> V_7 -> V_17 )
V_5 -> V_7 -> V_17 ( V_5 , & V_12 ) ;
V_4 -> V_18 . V_10 = V_10 ;
F_10 ( & V_5 -> V_14 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_19 , int V_20 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_21 = 0 ;
int V_22 = 0 ;
F_2 (priv != NULL, return -1;) ;
F_2 (priv->magic == IRTTY_MAGIC, return -1;) ;
if ( V_20 )
V_21 |= V_23 ;
else
V_22 |= V_23 ;
if ( V_19 )
V_21 |= V_24 ;
else
V_22 |= V_24 ;
F_2 (priv->tty->ops->tiocmset != NULL, return -1;) ;
V_4 -> V_5 -> V_7 -> V_25 ( V_4 -> V_5 , V_21 , V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , const unsigned char * V_26 , T_1 V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_6 * V_5 ;
int V_28 ;
F_2 (priv != NULL, return -1;) ;
F_2 (priv->magic == IRTTY_MAGIC, return -1;) ;
V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_7 -> V_29 )
return 0 ;
F_13 ( V_30 , & V_5 -> V_31 ) ;
V_28 = F_14 ( V_5 ) ;
if ( V_28 > V_27 )
V_28 = V_27 ;
return V_5 -> V_7 -> V_29 ( V_5 , V_26 , V_28 ) ;
}
static void F_15 ( struct V_6 * V_5 , const unsigned char * V_32 ,
char * V_33 , int V_34 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = V_5 -> V_35 ;
int V_36 ;
F_2 (priv != NULL, return;) ;
F_2 (priv->magic == IRTTY_MAGIC, return;) ;
if ( F_16 ( V_34 == 0 ) )
return;
V_2 = V_4 -> V_2 ;
if ( ! V_2 ) {
F_17 ( L_1 , V_37 ) ;
return;
}
for ( V_36 = 0 ; V_36 < V_34 ; V_36 ++ ) {
if ( V_33 && * V_33 ++ ) {
F_18 ( 0 , L_2 ) ;
F_19 ( V_2 , NULL , 0 ) ;
return;
}
}
F_19 ( V_2 , V_32 , V_34 ) ;
}
static void F_20 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_35 ;
F_2 (priv != NULL, return;) ;
F_2 (priv->magic == IRTTY_MAGIC, return;) ;
F_21 ( V_30 , & V_5 -> V_31 ) ;
if ( V_4 -> V_2 )
F_22 ( V_4 -> V_2 ) ;
}
static inline void F_23 ( struct V_6 * V_5 , int V_38 )
{
struct V_11 V_12 ;
int V_13 ;
F_8 ( & V_5 -> V_14 ) ;
V_12 = V_5 -> V_15 ;
V_13 = V_5 -> V_15 . V_16 ;
if ( V_38 )
V_13 &= ~ V_39 ;
else
V_13 |= V_39 ;
V_5 -> V_15 . V_16 = V_13 ;
if ( V_5 -> V_7 -> V_17 )
V_5 -> V_7 -> V_17 ( V_5 , & V_12 ) ;
F_10 ( & V_5 -> V_14 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_6 * V_5 ;
F_25 ( & V_40 ) ;
V_4 = V_2 -> V_4 ;
if ( F_16 ( ! V_4 || V_4 -> V_41 != V_42 ) ) {
F_26 ( & V_40 ) ;
return - V_43 ;
}
V_5 = V_4 -> V_5 ;
if ( V_5 -> V_7 -> V_44 )
V_5 -> V_7 -> V_44 ( V_5 ) ;
F_23 ( V_5 , FALSE ) ;
F_26 ( & V_40 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_6 * V_5 ;
F_25 ( & V_40 ) ;
V_4 = V_2 -> V_4 ;
if ( F_16 ( ! V_4 || V_4 -> V_41 != V_42 ) ) {
F_26 ( & V_40 ) ;
return - V_43 ;
}
V_5 = V_4 -> V_5 ;
F_23 ( V_5 , TRUE ) ;
if ( V_5 -> V_7 -> V_38 )
V_5 -> V_7 -> V_38 ( V_5 ) ;
F_26 ( & V_40 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_5 , struct V_45 * V_45 , unsigned int V_46 , unsigned long V_47 )
{
struct V_48 { char V_49 [ 6 ] ; } V_50 ;
struct V_1 * V_2 ;
struct V_3 * V_4 = V_5 -> V_35 ;
int V_51 = 0 ;
F_2 (priv != NULL, return -ENODEV;) ;
F_2 (priv->magic == IRTTY_MAGIC, return -EBADR;) ;
F_18 ( 3 , L_3 , V_37 , V_46 ) ;
V_2 = V_4 -> V_2 ;
F_2 (dev != NULL, return -1;) ;
switch ( V_46 ) {
case V_52 :
V_51 = F_29 ( V_2 , ( V_53 ) V_47 ) ;
break;
case V_54 :
F_2 (dev->netdev != NULL, return -1;) ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
strncpy ( V_50 . V_49 , V_2 -> V_55 -> V_49 , sizeof( V_50 . V_49 ) - 1 ) ;
if ( F_30 ( ( void V_56 * ) V_47 , & V_50 , sizeof( V_50 ) ) )
V_51 = - V_57 ;
break;
default:
V_51 = F_31 ( V_5 , V_45 , V_46 , V_47 ) ;
break;
}
return V_51 ;
}
static int F_32 ( struct V_6 * V_5 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_58 = 0 ;
if ( V_5 -> V_35 != NULL ) {
V_4 = V_5 -> V_35 ;
if ( V_4 && V_4 -> V_41 == V_42 ) {
V_58 = - V_59 ;
goto V_60;
}
V_5 -> V_35 = NULL ;
}
F_23 ( V_5 , TRUE ) ;
if ( V_5 -> V_7 -> V_38 )
V_5 -> V_7 -> V_38 ( V_5 ) ;
F_33 ( V_5 ) ;
V_61 . V_62 = V_62 ;
V_2 = F_34 ( & V_61 , V_5 -> V_49 ) ;
if ( ! V_2 ) {
V_58 = - V_63 ;
goto V_60;
}
V_4 = F_35 ( sizeof( * V_4 ) , V_64 ) ;
if ( ! V_4 ) {
V_58 = - V_65 ;
goto V_66;
}
V_4 -> V_41 = V_42 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_2 = V_2 ;
F_25 ( & V_40 ) ;
V_2 -> V_4 = V_4 ;
V_5 -> V_35 = V_4 ;
V_5 -> V_67 = 65536 ;
F_26 ( & V_40 ) ;
F_18 ( 0 , L_4 , V_37 , V_5 -> V_49 ) ;
return 0 ;
V_66:
F_36 ( V_2 ) ;
V_60:
return V_58 ;
}
static void F_37 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_35 ;
F_2 (priv != NULL, return;) ;
F_2 (priv->magic == IRTTY_MAGIC, return;) ;
V_5 -> V_35 = NULL ;
F_36 ( V_4 -> V_2 ) ;
F_23 ( V_5 , TRUE ) ;
F_21 ( V_30 , & V_5 -> V_31 ) ;
if ( V_5 -> V_7 -> V_38 )
V_5 -> V_7 -> V_38 ( V_5 ) ;
F_38 ( V_4 ) ;
F_18 ( 0 , L_5 , V_37 , V_5 -> V_49 ) ;
}
static int T_2 F_39 ( void )
{
int V_51 ;
if ( ( V_51 = F_40 ( V_68 , & V_69 ) ) != 0 )
F_41 ( L_6 ,
V_51 ) ;
return V_51 ;
}
static void T_3 F_42 ( void )
{
int V_51 ;
if ( ( V_51 = F_43 ( V_68 ) ) ) {
F_41 ( L_7 ,
V_37 , V_51 ) ;
}
}
