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
F_5 ( V_8 , NULL ) ;
F_6 ( & V_8 -> V_3 , L_1 ) ;
if ( V_4 == NULL )
return 0 ;
if ( V_4 -> V_9 ) {
F_7 ( V_4 -> V_9 ) ;
if ( V_4 -> V_10 ) {
if ( V_4 -> V_11 )
F_8 ( V_4 -> V_10 ) ;
}
F_9 ( V_4 -> V_9 ) ;
}
F_3 ( V_4 , V_12 ) ;
if ( V_4 -> V_13 ) {
F_10 ( V_4 -> V_13 ) ;
F_8 ( V_4 -> V_13 ) ;
}
if ( V_4 -> V_14 . V_15 != NULL )
F_11 ( V_4 -> V_14 . V_15 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_8 )
{
struct V_16 * V_6 ;
struct V_1 * V_4 ;
struct V_17 * V_18 ;
int V_19 = 0 ;
F_6 ( & V_8 -> V_3 , L_2 ) ;
if ( V_8 -> V_3 . V_20 == NULL ) {
F_13 ( & V_8 -> V_3 , L_3 ) ;
V_19 = - V_21 ;
goto V_22;
}
V_6 = V_8 -> V_3 . V_20 ;
V_4 = F_14 ( sizeof( * V_4 ) , V_23 ) ;
if ( V_4 == NULL ) {
F_13 ( & V_8 -> V_3 , L_4 ) ;
V_19 = - V_24 ;
goto V_22;
}
F_5 ( V_8 , V_4 ) ;
V_4 -> V_3 = & V_8 -> V_3 ;
V_4 -> V_6 = V_6 ;
V_18 = F_15 ( V_8 , V_25 , 0 ) ;
if ( V_18 == NULL ) {
F_13 ( & V_8 -> V_3 , L_5 ) ;
V_19 = - V_21 ;
goto V_26;
}
F_6 ( & V_8 -> V_3 , L_6 , V_18 ,
( unsigned long long ) V_18 -> V_27 ) ;
V_4 -> V_14 . V_28 = V_18 -> V_27 ;
V_4 -> V_14 . V_29 = F_16 ( V_18 ) ;
V_4 -> V_14 . V_30 = V_6 -> V_31 != NULL ?
( char * ) V_6 -> V_31 : ( char * ) V_8 -> V_30 ;
V_4 -> V_14 . V_32 = V_6 -> V_32 ;
V_4 -> V_13 = F_17 ( V_18 -> V_27 , V_4 -> V_14 . V_29 , V_8 -> V_30 ) ;
if ( V_4 -> V_13 == NULL ) {
F_13 ( & V_8 -> V_3 , L_7 ) ;
V_19 = - V_33 ;
goto V_26;
}
V_4 -> V_14 . V_15 = F_18 ( V_18 -> V_27 , V_4 -> V_14 . V_29 ) ;
F_6 ( & V_8 -> V_3 , L_8 , V_4 -> V_14 . V_15 , V_4 -> V_14 . V_29 ) ;
if ( V_4 -> V_14 . V_15 == NULL ) {
F_13 ( & V_8 -> V_3 , L_9 ) ;
V_19 = - V_33 ;
goto V_26;
}
F_19 ( & V_4 -> V_14 ) ;
F_6 ( & V_8 -> V_3 , L_10 ) ;
if ( V_6 -> V_34 ) {
const char * * V_34 = V_6 -> V_34 ;
for ( ; ! V_4 -> V_9 && * V_34 ; V_34 ++ )
V_4 -> V_9 = F_20 ( * V_34 , & V_4 -> V_14 ) ;
}
else
V_4 -> V_9 = F_20 ( L_11 , & V_4 -> V_14 ) ;
if ( V_4 -> V_9 == NULL ) {
F_13 ( & V_8 -> V_3 , L_12 ) ;
V_19 = - V_24 ;
goto V_26;
}
V_4 -> V_9 -> V_35 = V_36 ;
V_4 -> V_9 -> V_3 . V_37 = & V_8 -> V_3 ;
F_3 ( V_4 , V_38 ) ;
if ( ! V_6 -> V_39 ) {
if ( V_6 -> V_40 ) {
V_19 = F_21 ( V_4 -> V_9 , V_6 -> V_40 ,
& V_4 -> V_10 , 0 ) ;
V_4 -> V_11 = 1 ;
if ( V_19 > 0 )
V_19 = F_22 ( V_4 -> V_9 ,
V_4 -> V_10 , V_19 ) ;
}
}
else
V_19 = F_22 ( V_4 -> V_9 , V_6 -> V_10 ,
V_6 -> V_39 ) ;
if ( ! V_19 )
F_23 ( & V_8 -> V_3 , L_13 ) ;
V_19 = F_22 ( V_4 -> V_9 , NULL , 0 ) ;
if ( V_19 )
F_13 ( & V_8 -> V_3 , L_14 ) ;
return V_19 ;
V_26:
F_4 ( V_8 ) ;
V_22:
return V_19 ;
}
static int T_1 F_24 ( void )
{
F_25 ( L_15 ) ;
return F_26 ( & V_41 ) ;
}
static void T_2 F_27 ( void )
{
F_28 ( & V_41 ) ;
}
