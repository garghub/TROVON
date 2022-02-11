static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 , F_2 ( V_2 ) -> V_6 ) ;
}
static T_2 F_3 ( struct V_7 * V_8 ,
struct V_9 * V_4 , int V_10 )
{
struct V_1 * V_2 = F_4 ( V_8 , struct V_1 , V_8 ) ;
if ( F_2 ( V_2 ) -> V_6 == NULL )
return 0 ;
return V_4 -> V_11 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( F_2 ( V_2 ) ) ;
}
struct V_1 *
F_7 ( struct V_1 * V_2 , const char * V_6 ,
void * V_12 ,
const struct V_13 * * V_14 )
{
struct V_15 * V_16 ;
int V_17 , V_18 ;
V_18 = F_8 ( & V_19 , 0 , 0 , V_20 ) ;
if ( V_18 < 0 )
return F_9 ( V_18 ) ;
V_16 = F_10 ( sizeof( * V_16 ) , V_20 ) ;
if ( V_16 == NULL ) {
V_17 = - V_21 ;
goto V_22;
}
V_16 -> V_6 = V_6 ;
V_16 -> V_2 . V_23 = & V_24 ;
V_16 -> V_2 . V_25 = V_2 ;
V_16 -> V_2 . V_14 = V_14 ;
V_16 -> V_2 . V_26 = V_2 ? V_2 -> V_26 : NULL ;
F_11 ( & V_16 -> V_2 , V_12 ) ;
F_12 ( & V_16 -> V_2 , V_27 , V_18 ) ;
V_17 = F_13 ( & V_16 -> V_2 ) ;
if ( V_17 )
goto free;
return & V_16 -> V_2 ;
free:
F_6 ( V_16 ) ;
V_22:
F_14 ( & V_19 , V_18 ) ;
return F_9 ( V_17 ) ;
}
struct V_1 * F_15 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , NULL , NULL , NULL ) ;
}
void F_16 ( struct V_1 * V_2 )
{
int V_18 ;
if ( F_17 ( sscanf ( F_18 ( V_2 ) , V_27 , & V_18 ) == 1 ) ) {
F_19 ( V_2 ) ;
F_14 ( & V_19 , V_18 ) ;
} else
F_20 ( V_2 -> V_25 ,
L_2 ) ;
}
static void F_21 ( struct V_1 * V_2 , void * V_28 )
{
struct V_1 * V_16 = * (struct V_1 * * ) V_28 ;
F_16 ( V_16 ) ;
}
struct V_1 *
F_22 ( struct V_1 * V_2 , const char * V_6 ,
void * V_12 ,
const struct V_13 * * V_14 )
{
struct V_1 * * V_29 , * V_16 ;
if ( ! V_2 )
return F_9 ( - V_30 ) ;
V_29 = F_23 ( F_21 , sizeof( * V_29 ) , V_20 ) ;
if ( ! V_29 )
return F_9 ( - V_21 ) ;
V_16 = F_7 ( V_2 , V_6 , V_12 , V_14 ) ;
if ( F_24 ( V_16 ) )
goto error;
* V_29 = V_16 ;
F_25 ( V_2 , V_29 ) ;
return V_16 ;
error:
F_26 ( V_29 ) ;
return V_16 ;
}
static int F_27 ( struct V_1 * V_2 , void * V_28 , void * V_31 )
{
struct V_1 * * V_16 = V_28 ;
return * V_16 == V_31 ;
}
void F_28 ( struct V_1 * V_2 )
{
F_29 ( F_30 ( V_2 , F_21 , F_27 , V_2 ) ) ;
}
static void T_3 F_31 ( void )
{
#if V_32 V_33 && V_32 V_34
struct V_35 * V_36 ;
T_4 V_37 ;
T_5 V_38 ;
V_36 = F_32 ( V_39 , 0x436c , NULL ) ;
if ( V_36 ) {
if ( V_36 -> V_40 == 0x1462 &&
V_36 -> V_41 == 0x0031 ) {
F_33 ( V_36 , 0x48 , & V_38 ) ;
F_34 ( V_36 , 0x64 , & V_37 ) ;
if ( V_37 == 0 && ! ( V_38 & F_35 ( 2 ) ) ) {
F_36 ( & V_36 -> V_2 ,
L_3 ) ;
F_37 ( V_36 , 0x64 , 0x295 ) ;
F_38 ( V_36 , 0x48 ,
V_38 | F_35 ( 2 ) ) ;
}
}
F_39 ( V_36 ) ;
}
#endif
}
static int T_3 F_40 ( void )
{
int V_17 ;
F_31 () ;
V_17 = F_41 ( & V_24 ) ;
if ( V_17 ) {
F_42 ( L_4 ) ;
return V_17 ;
}
return 0 ;
}
static void T_6 F_43 ( void )
{
F_44 ( & V_24 ) ;
}
