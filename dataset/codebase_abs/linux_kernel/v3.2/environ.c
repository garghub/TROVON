static bool F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_5 * V_6 =
F_2 ( V_4 , F_3 ( * V_6 ) , V_7 ) ;
return F_4 ( V_2 -> V_8 . V_9 . V_10 , V_6 -> V_11 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , L_1 ,
V_2 -> V_8 . V_9 . V_10 -> V_10 ) ;
}
int F_7 ( struct V_1 * V_2 , const char * V_11 )
{
struct V_12 V_9 ;
int error ;
if ( ! V_11 || ! * V_11 )
return 0 ;
V_9 . V_10 = V_11 ;
F_8 ( & V_9 ) ;
V_2 -> V_13 = V_14 ;
V_2 -> V_8 . V_9 . V_10 = & V_9 ;
do {
F_9 ( V_2 , F_1 ) ;
error = F_5 ( V_2 ) ;
} while ( error == V_15 );
return error ;
}
static bool F_10 ( const struct V_3 * V_16 ,
const struct V_3 * V_17 )
{
const struct V_5 * V_18 = F_2 ( V_16 , F_3 ( * V_18 ) , V_7 ) ;
const struct V_5 * V_19 = F_2 ( V_17 , F_3 ( * V_19 ) , V_7 ) ;
return V_18 -> V_11 == V_19 -> V_11 ;
}
static int F_11 ( struct V_20 * V_8 )
{
struct V_5 V_21 = { . V_7 . type = V_14 } ;
int error = - V_22 ;
const char * V_23 = F_12 ( V_8 ) ;
if ( ! F_13 ( V_23 ) || strchr ( V_23 , '=' ) )
return - V_24 ;
V_21 . V_11 = F_14 ( V_23 ) ;
if ( ! V_21 . V_11 )
return error ;
error = F_15 ( & V_21 . V_7 , sizeof( V_21 ) , V_8 ,
F_10 , NULL ) ;
F_16 ( V_21 . V_11 ) ;
return error ;
}
int F_17 ( struct V_20 * V_8 )
{
if ( F_18 ( & V_8 -> V_23 , L_2 ) )
return F_11 ( V_8 ) ;
return - V_24 ;
}
