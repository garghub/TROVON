static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 = V_6 -> V_9 ? V_6 -> V_9 -> V_8 : 0 ;
F_2 ( F_3 ( V_4 ) , V_2 , F_4 ( V_4 ) , & V_6 -> V_10 . V_11 , V_8 ) ;
return V_12 ;
}
static unsigned int
F_5 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 = V_6 -> V_9 ? V_6 -> V_9 -> V_8 : 0 ;
F_6 ( F_3 ( V_4 ) , V_2 , F_4 ( V_4 ) , & V_6 -> V_10 . V_13 , V_8 ) ;
return V_12 ;
}
static int F_7 ( struct V_14 * V_15 , unsigned long V_16 ,
void * V_17 )
{
struct V_18 * V_19 = F_8 ( V_17 ) ;
struct V_20 * V_9 ;
V_9 = F_9 ( V_15 , struct V_20 , V_21 ) ;
switch ( V_16 ) {
case V_22 :
if ( ! strcmp ( V_19 -> V_23 , V_9 -> V_24 -> V_8 ) )
V_9 -> V_8 = V_19 -> V_25 ;
break;
case V_26 :
if ( V_19 -> V_25 == V_9 -> V_8 )
V_9 -> V_8 = - 1 ;
break;
case V_27 :
if ( ! strcmp ( V_19 -> V_23 , V_9 -> V_24 -> V_8 ) )
V_9 -> V_8 = V_19 -> V_25 ;
else if ( V_19 -> V_25 == V_9 -> V_8 )
V_9 -> V_8 = - 1 ;
break;
}
return V_28 ;
}
static int F_10 ( const struct V_29 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_20 * V_9 ;
if ( memcmp ( & V_6 -> V_10 , & V_30 ,
sizeof( V_30 ) ) == 0 )
return - V_31 ;
if ( V_6 -> V_8 [ 0 ] ) {
int V_32 ;
if ( V_6 -> V_8 [ sizeof( V_6 -> V_8 ) - 1 ] != '\0' )
return - V_31 ;
V_9 = F_11 ( sizeof( * V_9 ) , V_33 ) ;
if ( V_9 == NULL )
return - V_34 ;
V_9 -> V_24 = V_6 ;
V_9 -> V_8 = - 1 ;
V_9 -> V_21 . V_35 = F_7 ;
V_6 -> V_9 = V_9 ;
V_32 = F_12 ( & V_9 -> V_21 ) ;
if ( V_32 ) {
F_13 ( V_9 ) ;
return V_32 ;
}
} else
V_6 -> V_9 = NULL ;
F_14 ( & V_36 ) ;
return 0 ;
}
static void F_15 ( const struct V_37 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_9 ) {
F_16 ( & V_6 -> V_9 -> V_21 ) ;
F_13 ( V_6 -> V_9 ) ;
}
F_17 ( & V_36 ) ;
}
static int T_1 F_18 ( void )
{
return F_19 ( V_38 , F_20 ( V_38 ) ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( V_38 , F_20 ( V_38 ) ) ;
}
