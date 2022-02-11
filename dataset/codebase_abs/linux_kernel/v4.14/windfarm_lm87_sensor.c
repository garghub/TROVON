static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 = 0 ;
T_1 V_6 ;
for (; ; ) {
V_6 = ( T_1 ) V_3 ;
V_4 = F_2 ( V_2 , & V_6 , 1 ) ;
if ( V_4 <= 0 )
goto error;
V_4 = F_3 ( V_2 , & V_6 , 1 ) ;
if ( V_4 <= 0 )
goto error;
return ( int ) V_6 ;
error:
F_4 ( L_1 ) ;
if ( ++ V_5 > 10 ) {
F_5 ( V_7 L_2 ) ;
return - V_8 ;
}
F_6 ( 10 ) ;
}
}
static int F_7 ( struct V_9 * V_10 , T_2 * V_11 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
T_2 V_15 ;
if ( V_13 -> V_16 == NULL )
return - V_17 ;
#define F_8 0x27
V_15 = F_1 ( V_13 -> V_16 , F_8 ) ;
if ( V_15 < 0 )
return V_15 ;
* V_11 = V_15 << 16 ;
return 0 ;
}
static void F_9 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = F_10 ( V_10 ) ;
F_11 ( V_13 ) ;
}
static int F_12 ( struct V_1 * V_18 ,
const struct V_19 * V_20 )
{
struct V_12 * V_13 ;
const char * V_21 = NULL , * V_22 ;
struct V_23 * V_24 = NULL ;
int V_4 ;
while ( ( V_24 = F_13 ( V_18 -> V_25 . V_26 , V_24 ) ) != NULL ) {
if ( strcmp ( V_24 -> V_21 , L_3 ) )
continue;
V_22 = F_14 ( V_24 , L_4 , NULL ) ;
if ( ! V_22 )
continue;
if ( strstr ( V_22 , L_5 ) )
V_21 = L_6 ;
else if ( strstr ( V_22 , L_7 ) )
V_21 = L_8 ;
if ( V_21 ) {
F_15 ( V_24 ) ;
break;
}
}
if ( ! V_21 ) {
F_16 ( L_9 ,
V_18 -> V_25 . V_26 ) ;
return - V_17 ;
}
V_13 = F_17 ( sizeof( struct V_12 ) , V_27 ) ;
if ( V_13 == NULL )
return - V_17 ;
V_13 -> V_16 = V_18 ;
V_13 -> V_28 . V_21 = V_21 ;
V_13 -> V_28 . V_29 = & V_30 ;
V_13 -> V_28 . V_14 = V_13 ;
F_18 ( V_18 , V_13 ) ;
V_4 = F_19 ( & V_13 -> V_28 ) ;
if ( V_4 )
F_11 ( V_13 ) ;
return V_4 ;
}
static int F_20 ( struct V_1 * V_18 )
{
struct V_12 * V_13 = F_21 ( V_18 ) ;
F_4 ( L_10 , V_13 -> V_28 . V_21 ) ;
V_13 -> V_16 = NULL ;
F_22 ( & V_13 -> V_28 ) ;
return 0 ;
}
static int T_3 F_23 ( void )
{
if ( ! F_24 ( L_11 ) )
return - V_17 ;
return F_25 ( & V_31 ) ;
}
static void T_4 F_26 ( void )
{
F_27 ( & V_31 ) ;
}
