static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
if ( V_5 -> V_7 == NULL )
return - V_8 ;
V_6 = F_3 ( V_5 -> V_7 , V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_3 = V_6 << 16 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_5 ( V_5 ) ;
}
static int F_6 ( struct V_10 * V_11 ,
const struct V_12 * V_13 )
{
struct V_4 * V_5 ;
int V_14 ;
V_5 = F_7 ( sizeof( struct V_4 ) , V_15 ) ;
if ( V_5 == NULL ) {
F_8 ( V_16 L_1
L_2 ) ;
return - V_17 ;
}
V_5 -> V_7 = V_11 ;
V_5 -> V_18 . V_19 = V_11 -> V_20 . V_21 ;
V_5 -> V_18 . V_22 = & V_23 ;
F_9 ( V_11 , V_5 ) ;
V_14 = F_10 ( & V_5 -> V_18 ) ;
if ( V_14 ) {
F_5 ( V_5 ) ;
}
return V_14 ;
}
static struct V_10 * F_11 ( struct V_24 * V_25 ,
T_2 V_26 , const char * V_27 )
{
struct V_28 V_29 ;
struct V_10 * V_11 ;
char * V_19 ;
if ( ! strcmp ( V_27 , L_3 ) )
V_19 = L_4 ;
else if ( ! strcmp ( V_27 , L_5 ) )
V_19 = L_6 ;
else if ( ! strcmp ( V_27 , L_7 ) )
V_19 = L_8 ;
else
goto V_30;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 . V_26 = V_26 >> 1 ;
V_29 . V_21 = V_19 ;
F_12 ( V_29 . type , L_9 , V_31 ) ;
V_11 = F_13 ( V_25 , & V_29 ) ;
if ( V_11 == NULL ) {
F_8 ( V_16 L_10 ) ;
goto V_30;
}
F_14 ( & V_11 -> V_32 , & V_33 . V_34 ) ;
return V_11 ;
V_30:
return NULL ;
}
static int F_15 ( struct V_24 * V_25 )
{
struct V_35 * V_36 , * V_20 = NULL ;
struct V_37 * V_38 ;
const char * V_27 ;
V_38 = F_16 ( V_25 ) ;
if ( V_38 == NULL )
return - V_8 ;
V_36 = F_17 ( V_38 ) ;
while ( ( V_20 = F_18 ( V_36 , V_20 ) ) != NULL ) {
T_2 V_26 ;
if ( ! F_19 ( V_20 , V_25 ) )
continue;
if ( ! F_20 ( V_20 , L_11 ) )
continue;
V_26 = F_21 ( V_20 ) ;
V_27 = F_22 ( V_20 , L_12 , NULL ) ;
if ( V_27 == NULL || V_26 == 0 )
continue;
F_8 ( L_13 , V_27 , V_26 ) ;
F_11 ( V_25 , V_26 , V_27 ) ;
}
return 0 ;
}
static int F_23 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_24 ( V_11 ) ;
V_5 -> V_7 = NULL ;
F_25 ( & V_5 -> V_18 ) ;
return 0 ;
}
static int T_3 F_26 ( void )
{
if ( F_27 ( L_14 ) ||
F_27 ( L_15 ) ||
F_27 ( L_16 ) )
return - V_8 ;
return F_28 ( & V_33 ) ;
}
static void T_4 F_29 ( void )
{
F_30 ( & V_33 ) ;
}
