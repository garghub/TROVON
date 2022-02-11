static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
bool V_8 = V_6 -> V_9 & V_10 ;
int V_11 , V_12 ;
switch ( V_6 -> V_13 ) {
case V_14 :
if ( ( F_2 () & 0x7FFFFFFF ) < V_6 -> V_15 . V_16 . V_17 )
V_8 = ! V_8 ;
break;
case V_18 :
do {
V_12 = F_3 ( & V_6 -> V_19 -> V_20 ) ;
V_11 = ( V_12 == V_6 -> V_15 . V_21 . V_22 ) ? 0 : V_12 + 1 ;
} while ( F_4 ( & V_6 -> V_19 -> V_20 , V_12 , V_11 ) != V_12 );
if ( V_11 == 0 )
V_8 = ! V_8 ;
break;
}
return V_8 ;
}
static int F_5 ( const struct V_23 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_13 > V_24 ||
V_6 -> V_9 & ~ V_25 )
return - V_26 ;
V_6 -> V_19 = F_6 ( sizeof( * V_6 -> V_19 ) , V_27 ) ;
if ( V_6 -> V_19 == NULL )
return - V_28 ;
F_7 ( & V_6 -> V_19 -> V_20 , V_6 -> V_15 . V_21 . V_20 ) ;
return 0 ;
}
static void F_8 ( const struct V_29 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
F_9 ( V_6 -> V_19 ) ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_30 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_30 ) ;
}
