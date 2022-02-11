static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
if ( V_5 -> V_7 == NULL )
return - V_8 ;
if ( ! V_5 -> V_9 ) {
T_2 V_10 , V_11 = ( T_2 ) F_3 ( V_5 -> V_7 , 1 ) ;
F_4 ( L_1 ,
V_2 -> V_12 , V_11 ) ;
V_10 = V_11 & ~ 0x01 ;
F_5 ( V_5 -> V_7 , 1 , V_10 ) ;
V_5 -> V_9 = 1 ;
F_6 ( 200 ) ;
}
V_6 = ( T_1 ) F_7 ( F_8 ( V_5 -> V_7 , 0 ) ) ;
V_6 <<= 8 ;
* V_3 = V_6 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_10 ( V_5 ) ;
}
static int F_11 ( struct V_13 * V_14 ,
const struct V_15 * V_16 )
{
struct V_4 * V_5 ;
int V_17 ;
V_5 = F_12 ( sizeof( struct V_4 ) , V_18 ) ;
if ( V_5 == NULL )
return - V_8 ;
V_5 -> V_9 = 0 ;
V_5 -> V_19 = V_16 -> V_20 ;
V_5 -> V_7 = V_14 ;
V_5 -> V_21 . V_12 = V_14 -> V_22 . V_23 ;
V_5 -> V_21 . V_24 = & V_25 ;
F_13 ( V_14 , V_5 ) ;
V_17 = F_14 ( & V_5 -> V_21 ) ;
if ( V_17 )
F_10 ( V_5 ) ;
return V_17 ;
}
static struct V_13 * F_15 ( struct V_26 * V_27 ,
T_2 V_28 , int V_19 ,
const char * V_29 )
{
struct V_30 V_31 ;
struct V_13 * V_14 ;
char * V_12 ;
F_4 ( L_2 ,
V_19 ? L_3 : L_4 , V_28 ) ;
if ( ! strcmp ( V_29 , L_5 ) || ! strcmp ( V_29 , L_6 ) )
V_12 = L_7 ;
else if ( ! strcmp ( V_29 , L_8 ) )
V_12 = L_9 ;
else if ( ! strcmp ( V_29 , L_10 ) )
V_12 = L_11 ;
else if ( ! strcmp ( V_29 , L_12 ) )
V_12 = L_13 ;
else
goto V_32;
memset ( & V_31 , 0 , sizeof( struct V_30 ) ) ;
V_31 . V_28 = ( V_28 >> 1 ) & 0x7f ;
V_31 . V_23 = V_12 ;
F_16 ( V_31 . type , V_19 ? L_14 : L_15 , V_33 ) ;
V_14 = F_17 ( V_27 , & V_31 ) ;
if ( V_14 == NULL ) {
F_18 ( V_34 L_16 ,
V_19 ? L_3 : L_4 , V_12 ) ;
goto V_32;
}
F_19 ( & V_14 -> V_35 , & V_36 . V_37 ) ;
return V_14 ;
V_32:
return NULL ;
}
static int F_20 ( struct V_26 * V_27 )
{
struct V_38 * V_39 , * V_22 ;
struct V_40 * V_41 ;
F_4 ( L_17 , V_27 -> V_12 ) ;
V_41 = F_21 ( V_27 ) ;
if ( V_41 == NULL )
return - V_8 ;
V_39 = F_22 ( V_41 ) ;
F_4 ( L_18 ) ;
for ( V_22 = NULL ;
( V_22 = F_23 ( V_39 , V_22 ) ) != NULL ; ) {
const char * V_29 =
F_24 ( V_22 , L_19 , NULL ) ;
T_2 V_28 ;
if ( ! F_25 ( V_22 , V_27 ) )
continue;
V_28 = F_26 ( V_22 ) ;
if ( V_29 == NULL || V_28 == 0 )
continue;
if ( F_27 ( V_22 , L_4 ) )
F_15 ( V_27 , V_28 , 0 , V_29 ) ;
else if ( F_27 ( V_22 , L_3 ) )
F_15 ( V_27 , V_28 , 1 , V_29 ) ;
}
return 0 ;
}
static int F_28 ( struct V_13 * V_14 )
{
struct V_4 * V_5 = F_29 ( V_14 ) ;
F_4 ( L_20 , V_5 -> V_21 . V_12 ) ;
V_5 -> V_7 = NULL ;
F_30 ( & V_5 -> V_21 ) ;
return 0 ;
}
static int T_3 F_31 ( void )
{
if ( F_32 ( L_21 ) ||
F_32 ( L_22 ) ||
F_32 ( L_23 ) )
return - V_8 ;
return F_33 ( & V_36 ) ;
}
static void T_4 F_34 ( void )
{
F_35 ( & V_36 ) ;
}
