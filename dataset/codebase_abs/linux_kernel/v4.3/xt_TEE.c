static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
F_2 ( V_2 , V_4 -> V_8 , & V_6 -> V_9 . V_10 , V_6 -> V_11 -> V_12 ) ;
return V_13 ;
}
static unsigned int
F_3 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
F_4 ( V_2 , V_4 -> V_8 , & V_6 -> V_9 . V_14 , V_6 -> V_11 -> V_12 ) ;
return V_13 ;
}
static int F_5 ( struct V_15 * V_16 , unsigned long V_17 ,
void * V_18 )
{
struct V_19 * V_20 = F_6 ( V_18 ) ;
struct V_21 * V_11 ;
V_11 = F_7 ( V_16 , struct V_21 , V_22 ) ;
switch ( V_17 ) {
case V_23 :
if ( ! strcmp ( V_20 -> V_24 , V_11 -> V_25 -> V_12 ) )
V_11 -> V_12 = V_20 -> V_26 ;
break;
case V_27 :
if ( V_20 -> V_26 == V_11 -> V_12 )
V_11 -> V_12 = - 1 ;
break;
case V_28 :
if ( ! strcmp ( V_20 -> V_24 , V_11 -> V_25 -> V_12 ) )
V_11 -> V_12 = V_20 -> V_26 ;
else if ( V_20 -> V_26 == V_11 -> V_12 )
V_11 -> V_12 = - 1 ;
break;
}
return V_29 ;
}
static int F_8 ( const struct V_30 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_21 * V_11 ;
if ( memcmp ( & V_6 -> V_9 , & V_31 ,
sizeof( V_31 ) ) == 0 )
return - V_32 ;
if ( V_6 -> V_12 [ 0 ] ) {
if ( V_6 -> V_12 [ sizeof( V_6 -> V_12 ) - 1 ] != '\0' )
return - V_32 ;
V_11 = F_9 ( sizeof( * V_11 ) , V_33 ) ;
if ( V_11 == NULL )
return - V_34 ;
V_11 -> V_25 = V_6 ;
V_11 -> V_12 = - 1 ;
V_11 -> V_22 . V_35 = F_5 ;
V_6 -> V_11 = V_11 ;
F_10 ( & V_11 -> V_22 ) ;
} else
V_6 -> V_11 = NULL ;
F_11 ( & V_36 ) ;
return 0 ;
}
static void F_12 ( const struct V_37 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_11 ) {
F_13 ( & V_6 -> V_11 -> V_22 ) ;
F_14 ( V_6 -> V_11 ) ;
}
F_15 ( & V_36 ) ;
}
static int T_1 F_16 ( void )
{
return F_17 ( V_38 , F_18 ( V_38 ) ) ;
}
static void T_2 F_19 ( void )
{
F_20 ( V_38 , F_18 ( V_38 ) ) ;
}
