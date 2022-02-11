static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 = V_6 -> V_9 ? V_6 -> V_9 -> V_8 : 0 ;
F_2 ( V_4 -> V_10 , V_2 , V_4 -> V_11 , & V_6 -> V_12 . V_13 , V_8 ) ;
return V_14 ;
}
static unsigned int
F_3 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 = V_6 -> V_9 ? V_6 -> V_9 -> V_8 : 0 ;
F_4 ( V_4 -> V_10 , V_2 , V_4 -> V_11 , & V_6 -> V_12 . V_15 , V_8 ) ;
return V_14 ;
}
static int F_5 ( struct V_16 * V_17 , unsigned long V_18 ,
void * V_19 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
struct V_22 * V_9 ;
V_9 = F_7 ( V_17 , struct V_22 , V_23 ) ;
switch ( V_18 ) {
case V_24 :
if ( ! strcmp ( V_21 -> V_25 , V_9 -> V_26 -> V_8 ) )
V_9 -> V_8 = V_21 -> V_27 ;
break;
case V_28 :
if ( V_21 -> V_27 == V_9 -> V_8 )
V_9 -> V_8 = - 1 ;
break;
case V_29 :
if ( ! strcmp ( V_21 -> V_25 , V_9 -> V_26 -> V_8 ) )
V_9 -> V_8 = V_21 -> V_27 ;
else if ( V_21 -> V_27 == V_9 -> V_8 )
V_9 -> V_8 = - 1 ;
break;
}
return V_30 ;
}
static int F_8 ( const struct V_31 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_22 * V_9 ;
if ( memcmp ( & V_6 -> V_12 , & V_32 ,
sizeof( V_32 ) ) == 0 )
return - V_33 ;
if ( V_6 -> V_8 [ 0 ] ) {
if ( V_6 -> V_8 [ sizeof( V_6 -> V_8 ) - 1 ] != '\0' )
return - V_33 ;
V_9 = F_9 ( sizeof( * V_9 ) , V_34 ) ;
if ( V_9 == NULL )
return - V_35 ;
V_9 -> V_26 = V_6 ;
V_9 -> V_8 = - 1 ;
V_9 -> V_23 . V_36 = F_5 ;
V_6 -> V_9 = V_9 ;
F_10 ( & V_9 -> V_23 ) ;
} else
V_6 -> V_9 = NULL ;
F_11 ( & V_37 ) ;
return 0 ;
}
static void F_12 ( const struct V_38 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_9 ) {
F_13 ( & V_6 -> V_9 -> V_23 ) ;
F_14 ( V_6 -> V_9 ) ;
}
F_15 ( & V_37 ) ;
}
static int T_1 F_16 ( void )
{
return F_17 ( V_39 , F_18 ( V_39 ) ) ;
}
static void T_2 F_19 ( void )
{
F_20 ( V_39 , F_18 ( V_39 ) ) ;
}
