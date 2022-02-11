static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
return snprintf ( V_5 , V_9 , L_1 , V_7 -> V_10 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
struct V_12 * V_13 = V_7 -> V_14 ;
int V_10 ;
if ( sscanf ( V_5 , L_1 , & V_10 ) != 1 || V_10 < 0 || V_10 > 1 )
return - V_15 ;
if ( V_10 && ! V_13 -> V_10 )
return - V_15 ;
V_7 -> V_10 = V_10 ;
F_4 ( V_16 , L_2 ,
F_5 ( V_7 -> V_17 -> V_18 ) ,
F_6 ( V_7 -> V_17 -> V_18 ) ,
V_10 ) ;
if ( ! V_10 )
F_7 ( V_7 -> V_17 ) ;
return V_11 ;
}
void F_8 ( struct V_6 * V_7 , int V_10 )
{
V_7 -> V_10 = V_10 ;
if ( ! V_10 )
F_7 ( V_7 -> V_17 ) ;
}
struct V_6 * F_9 ( T_2 V_19 )
{
struct V_6 * V_7 ;
V_7 = F_10 ( sizeof( struct V_6 ) , V_20 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_21 . V_22 = F_11 ( V_19 , V_20 ) ;
if ( ! V_7 -> V_21 . V_22 )
goto V_23;
V_7 -> V_21 . V_24 = V_19 ;
F_12 ( & V_7 -> V_25 ) ;
F_13 ( & V_7 -> V_26 ) ;
return V_7 ;
V_23:
F_14 ( V_7 ) ;
return NULL ;
}
void F_15 ( struct V_6 * V_7 )
{
F_14 ( V_7 -> V_21 . V_22 ) ;
F_14 ( V_7 ) ;
}
static void F_16 ( struct V_27 * V_27 )
{
struct V_6 * V_7 =
F_17 ( V_27 , struct V_6 , V_26 ) ;
F_15 ( V_7 ) ;
}
void F_18 ( struct V_6 * V_7 )
{
F_19 ( & V_7 -> V_26 ) ;
}
int F_20 ( struct V_6 * V_7 )
{
return F_21 ( & V_7 -> V_26 , F_16 ) ;
}
int F_22 ( struct V_6 * V_7 )
{
struct V_12 * V_13 ;
int V_28 ;
F_23 ( & V_29 ) ;
V_13 = V_7 -> V_17 -> V_30 -> V_8 ;
F_24 ( V_13 ) ;
V_7 -> V_14 = V_13 ;
V_7 -> V_10 = 1 ;
F_4 ( V_16 , L_3 ,
F_5 ( V_7 -> V_17 -> V_18 ) , F_6 ( V_7 -> V_17 -> V_18 ) ) ;
F_25 ( & V_7 -> V_25 , & V_13 -> V_31 ) ;
V_32 ++ ;
F_26 ( & V_29 ) ;
V_28 = F_27 ( & V_7 -> V_17 -> V_33 . V_1 . V_34 ,
& V_35 ) ;
if ( V_28 )
goto V_36;
F_28 ( & V_7 -> V_17 -> V_33 . V_1 ) ;
if ( V_7 -> V_37 -> V_38 ) {
V_28 = F_29 () ;
if ( V_28 )
goto V_39;
}
return 0 ;
V_39:
F_30 ( & V_7 -> V_17 -> V_33 . V_1 . V_34 ,
& V_35 ) ;
F_31 ( & V_7 -> V_17 -> V_33 . V_1 ) ;
V_36:
F_23 ( & V_29 ) ;
F_32 ( & V_7 -> V_25 ) ;
F_26 ( & V_29 ) ;
F_33 ( V_13 ) ;
return V_28 ;
}
void F_34 ( struct V_6 * V_7 )
{
struct V_12 * V_13 ;
F_4 ( V_16 , L_4 ,
F_5 ( V_7 -> V_17 -> V_18 ) , F_6 ( V_7 -> V_17 -> V_18 ) ) ;
V_13 = V_7 -> V_14 ;
F_23 ( & V_29 ) ;
F_32 ( & V_7 -> V_25 ) ;
V_32 -- ;
F_26 ( & V_29 ) ;
F_33 ( V_13 ) ;
if ( V_7 -> V_37 -> V_38 )
F_35 () ;
F_30 ( & V_7 -> V_17 -> V_33 . V_1 . V_34 ,
& V_35 ) ;
F_31 ( & V_7 -> V_17 -> V_33 . V_1 ) ;
F_20 ( V_7 ) ;
}
