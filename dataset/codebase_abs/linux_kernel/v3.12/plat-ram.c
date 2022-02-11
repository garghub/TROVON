static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) F_2 ( V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_4 , int V_5 )
{
if ( V_4 -> V_6 == NULL )
return;
if ( V_4 -> V_6 -> V_7 != NULL )
( V_4 -> V_6 -> V_7 ) ( V_4 -> V_3 , V_5 ) ;
}
static int F_4 ( struct V_2 * V_8 )
{
struct V_1 * V_4 = F_1 ( V_8 ) ;
F_5 ( & V_8 -> V_3 , L_1 ) ;
if ( V_4 == NULL )
return 0 ;
if ( V_4 -> V_9 ) {
F_6 ( V_4 -> V_9 ) ;
F_7 ( V_4 -> V_9 ) ;
}
F_3 ( V_4 , V_10 ) ;
if ( V_4 -> V_11 ) {
F_8 ( V_4 -> V_11 ) ;
F_9 ( V_4 -> V_11 ) ;
}
if ( V_4 -> V_12 . V_13 != NULL )
F_10 ( V_4 -> V_12 . V_13 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_8 )
{
struct V_14 * V_6 ;
struct V_1 * V_4 ;
struct V_15 * V_16 ;
int V_17 = 0 ;
F_5 ( & V_8 -> V_3 , L_2 ) ;
if ( F_12 ( & V_8 -> V_3 ) == NULL ) {
F_13 ( & V_8 -> V_3 , L_3 ) ;
V_17 = - V_18 ;
goto V_19;
}
V_6 = F_12 ( & V_8 -> V_3 ) ;
V_4 = F_14 ( sizeof( * V_4 ) , V_20 ) ;
if ( V_4 == NULL ) {
F_13 ( & V_8 -> V_3 , L_4 ) ;
V_17 = - V_21 ;
goto V_19;
}
F_15 ( V_8 , V_4 ) ;
V_4 -> V_3 = & V_8 -> V_3 ;
V_4 -> V_6 = V_6 ;
V_16 = F_16 ( V_8 , V_22 , 0 ) ;
if ( V_16 == NULL ) {
F_13 ( & V_8 -> V_3 , L_5 ) ;
V_17 = - V_18 ;
goto V_23;
}
F_5 ( & V_8 -> V_3 , L_6 , V_16 ,
( unsigned long long ) V_16 -> V_24 ) ;
V_4 -> V_12 . V_25 = V_16 -> V_24 ;
V_4 -> V_12 . V_26 = F_17 ( V_16 ) ;
V_4 -> V_12 . V_27 = V_6 -> V_28 != NULL ?
( char * ) V_6 -> V_28 : ( char * ) V_8 -> V_27 ;
V_4 -> V_12 . V_29 = V_6 -> V_29 ;
V_4 -> V_11 = F_18 ( V_16 -> V_24 , V_4 -> V_12 . V_26 , V_8 -> V_27 ) ;
if ( V_4 -> V_11 == NULL ) {
F_13 ( & V_8 -> V_3 , L_7 ) ;
V_17 = - V_30 ;
goto V_23;
}
V_4 -> V_12 . V_13 = F_19 ( V_16 -> V_24 , V_4 -> V_12 . V_26 ) ;
F_5 ( & V_8 -> V_3 , L_8 , V_4 -> V_12 . V_13 , V_4 -> V_12 . V_26 ) ;
if ( V_4 -> V_12 . V_13 == NULL ) {
F_13 ( & V_8 -> V_3 , L_9 ) ;
V_17 = - V_30 ;
goto V_23;
}
F_20 ( & V_4 -> V_12 ) ;
F_5 ( & V_8 -> V_3 , L_10 ) ;
if ( V_6 -> V_31 ) {
const char * const * V_31 = V_6 -> V_31 ;
for ( ; ! V_4 -> V_9 && * V_31 ; V_31 ++ )
V_4 -> V_9 = F_21 ( * V_31 , & V_4 -> V_12 ) ;
}
else
V_4 -> V_9 = F_21 ( L_11 , & V_4 -> V_12 ) ;
if ( V_4 -> V_9 == NULL ) {
F_13 ( & V_8 -> V_3 , L_12 ) ;
V_17 = - V_21 ;
goto V_23;
}
V_4 -> V_9 -> V_32 = V_33 ;
V_4 -> V_9 -> V_3 . V_34 = & V_8 -> V_3 ;
F_3 ( V_4 , V_35 ) ;
V_17 = F_22 ( V_4 -> V_9 , V_6 -> V_36 , NULL ,
V_6 -> V_37 ,
V_6 -> V_38 ) ;
if ( ! V_17 )
F_23 ( & V_8 -> V_3 , L_13 ) ;
if ( V_6 -> V_38 ) {
V_17 = F_24 ( V_4 -> V_9 , NULL , 0 ) ;
if ( V_17 ) {
F_13 ( & V_8 -> V_3 ,
L_14 ) ;
}
}
return V_17 ;
V_23:
F_4 ( V_8 ) ;
V_19:
return V_17 ;
}
static int T_1 F_25 ( void )
{
F_26 ( L_15 ) ;
return F_27 ( & V_39 ) ;
}
static void T_2 F_28 ( void )
{
F_29 ( & V_39 ) ;
}
