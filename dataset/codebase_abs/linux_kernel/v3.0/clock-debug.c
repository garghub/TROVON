static int F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * clock = V_1 ;
int V_4 ;
if ( clock -> V_5 & V_6 )
F_2 ( clock , V_2 ) ;
if ( clock -> V_5 & V_7 )
V_4 = F_3 ( clock , V_2 ) ;
else
V_4 = F_4 ( clock , V_2 ) ;
if ( V_4 != 0 )
F_5 ( V_8 L_1 ,
( clock -> V_5 & V_7 ) ? L_2 : L_3 , V_4 ) ;
return V_4 ;
}
static int F_6 ( void * V_1 , T_1 * V_2 )
{
struct V_3 * clock = V_1 ;
* V_2 = F_7 ( clock ) ;
return 0 ;
}
static int F_8 ( void * V_1 , T_1 V_2 )
{
struct V_3 * clock = V_1 ;
int V_9 = 0 ;
if ( V_2 )
V_9 = clock -> V_10 -> V_11 ( clock -> V_12 ) ;
else
clock -> V_10 -> V_13 ( clock -> V_12 ) ;
return V_9 ;
}
static int F_9 ( void * V_1 , T_1 * V_2 )
{
struct V_3 * clock = V_1 ;
* V_2 = clock -> V_10 -> V_14 ( clock -> V_12 ) ;
return 0 ;
}
static int F_10 ( void * V_1 , T_1 * V_2 )
{
struct V_3 * clock = V_1 ;
* V_2 = clock -> V_10 -> V_15 ( clock -> V_12 ) ;
return 0 ;
}
int T_2 F_11 ( void )
{
V_16 = F_12 ( L_4 , NULL ) ;
if ( ! V_16 )
return - V_17 ;
return 0 ;
}
int T_2 F_13 ( struct V_3 * clock )
{
char V_18 [ 50 ] , * V_19 ;
struct V_20 * V_21 ;
if ( ! V_16 )
return - V_17 ;
strncpy ( V_18 , clock -> V_22 , F_14 ( V_18 ) - 1 ) ;
for ( V_19 = V_18 ; * V_19 ; V_19 ++ )
* V_19 = tolower ( * V_19 ) ;
V_21 = F_12 ( V_18 , V_16 ) ;
if ( ! V_21 )
return - V_17 ;
if ( ! F_15 ( L_5 , V_23 | V_24 , V_21 ,
clock , & V_25 ) )
goto error;
if ( ! F_15 ( L_6 , V_23 | V_24 , V_21 ,
clock , & V_26 ) )
goto error;
if ( ! F_15 ( L_7 , V_23 , V_21 , clock ,
& V_27 ) )
goto error;
return 0 ;
error:
F_16 ( V_21 ) ;
return - V_17 ;
}
