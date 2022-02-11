static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
int F_3 ( struct V_1 * V_3 , const T_1 * V_5 , unsigned int V_6 )
{
T_1 * V_7 = NULL ;
int V_8 ;
if ( ! V_5 && V_6 ) {
V_7 = F_4 ( V_6 , V_9 ) ;
if ( ! V_7 )
return - V_10 ;
F_5 ( V_7 , V_6 ) ;
V_5 = V_7 ;
}
V_8 = F_6 ( V_3 ) -> V_5 ( V_3 , V_5 , V_6 ) ;
F_7 ( V_7 ) ;
return V_8 ;
}
static int F_8 ( struct V_2 * V_3 )
{
return 0 ;
}
static unsigned int F_9 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_2 ( V_12 , struct V_13 , V_4 ) ;
return V_14 -> F_9 ;
}
static int F_10 ( struct V_15 * V_16 , struct V_11 * V_12 )
{
struct V_17 V_18 ;
strncpy ( V_18 . type , L_1 , sizeof( V_18 . type ) ) ;
V_18 . F_9 = F_9 ( V_12 ) ;
if ( F_11 ( V_16 , V_19 ,
sizeof( struct V_17 ) , & V_18 ) )
goto V_20;
return 0 ;
V_20:
return - V_21 ;
}
static int F_10 ( struct V_15 * V_16 , struct V_11 * V_12 )
{
return - V_22 ;
}
static void F_12 ( struct V_23 * V_24 , struct V_11 * V_12 )
{
F_13 ( V_24 , L_2 ) ;
F_13 ( V_24 , L_3 , F_9 ( V_12 ) ) ;
}
struct V_1 * F_14 ( const char * V_25 , T_2 type , T_2 V_26 )
{
return F_15 ( V_25 , & V_27 , type , V_26 ) ;
}
int F_16 ( void )
{
struct V_1 * V_28 ;
int V_8 ;
F_17 ( & V_29 ) ;
if ( ! V_30 ) {
V_28 = F_14 ( L_4 , 0 , 0 ) ;
V_8 = F_18 ( V_28 ) ;
if ( F_19 ( V_28 ) )
goto V_31;
V_8 = F_3 ( V_28 , NULL , F_20 ( V_28 ) ) ;
if ( V_8 ) {
F_21 ( V_28 ) ;
goto V_31;
}
V_30 = V_28 ;
}
V_32 ++ ;
V_8 = 0 ;
V_31:
F_22 ( & V_29 ) ;
return V_8 ;
}
void F_23 ( void )
{
F_17 ( & V_29 ) ;
V_32 -- ;
F_22 ( & V_29 ) ;
}
int F_24 ( void )
{
int V_8 = - V_33 ;
F_17 ( & V_29 ) ;
if ( V_32 )
goto V_34;
F_21 ( V_30 ) ;
V_30 = NULL ;
V_8 = 0 ;
V_34:
F_22 ( & V_29 ) ;
return V_8 ;
}
int F_25 ( struct V_13 * V_12 )
{
struct V_11 * V_4 = & V_12 -> V_4 ;
if ( V_12 -> F_9 > V_35 / 8 )
return - V_36 ;
V_4 -> V_37 = & V_27 ;
V_4 -> V_38 &= ~ V_39 ;
V_4 -> V_38 |= V_40 ;
return F_26 ( V_4 ) ;
}
void F_27 ( struct V_13 * V_12 )
{
F_28 ( & V_12 -> V_4 ) ;
}
int F_29 ( struct V_13 * V_41 , int V_42 )
{
int V_43 , V_44 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
V_44 = F_25 ( V_41 + V_43 ) ;
if ( V_44 )
goto V_8;
}
return 0 ;
V_8:
for ( -- V_43 ; V_43 >= 0 ; -- V_43 )
F_27 ( V_41 + V_43 ) ;
return V_44 ;
}
void F_30 ( struct V_13 * V_41 , int V_42 )
{
int V_43 ;
for ( V_43 = V_42 - 1 ; V_43 >= 0 ; -- V_43 )
F_27 ( V_41 + V_43 ) ;
}
