static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
return snprintf ( V_5 , V_9 , L_1 , V_7 -> V_10 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
return snprintf ( V_5 , V_9 , L_2 , V_7 -> V_11 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
struct V_13 * V_14 ;
int V_11 , V_15 ;
if ( sscanf ( V_5 , L_2 , & V_11 ) != 1 || V_11 < 0 || V_11 > 1 )
return - V_16 ;
V_7 -> V_11 = V_11 ;
V_15 = V_7 -> V_17 -> V_15 ;
F_5 ( V_18 , L_3 , V_15 , V_11 ) ;
F_6 ( & V_19 ) ;
F_7 (zq, &zc->zqueues, list)
F_8 ( V_14 , V_11 ) ;
F_9 ( & V_19 ) ;
return V_12 ;
}
struct V_6 * F_10 ( void )
{
struct V_6 * V_7 ;
V_7 = F_11 ( sizeof( struct V_6 ) , V_20 ) ;
if ( ! V_7 )
return NULL ;
F_12 ( & V_7 -> V_21 ) ;
F_12 ( & V_7 -> V_22 ) ;
F_13 ( & V_7 -> V_23 ) ;
return V_7 ;
}
void F_14 ( struct V_6 * V_7 )
{
F_15 ( V_7 ) ;
}
static void F_16 ( struct V_24 * V_24 )
{
struct V_6 * V_25 =
F_17 ( V_24 , struct V_6 , V_23 ) ;
F_14 ( V_25 ) ;
}
void F_18 ( struct V_6 * V_7 )
{
F_19 ( & V_7 -> V_23 ) ;
}
int F_20 ( struct V_6 * V_7 )
{
return F_21 ( & V_7 -> V_23 , F_16 ) ;
}
int F_22 ( struct V_6 * V_7 )
{
int V_26 ;
V_26 = F_23 ( & V_7 -> V_17 -> V_27 . V_1 . V_28 ,
& V_29 ) ;
if ( V_26 )
return V_26 ;
F_6 ( & V_19 ) ;
F_24 ( & V_7 -> V_21 , & V_30 ) ;
F_9 ( & V_19 ) ;
V_7 -> V_11 = 1 ;
F_5 ( V_18 , L_4 , V_7 -> V_17 -> V_15 ) ;
return V_26 ;
}
void F_25 ( struct V_6 * V_7 )
{
F_5 ( V_18 , L_5 , V_7 -> V_17 -> V_15 ) ;
F_6 ( & V_19 ) ;
F_26 ( & V_7 -> V_21 ) ;
F_9 ( & V_19 ) ;
F_27 ( & V_7 -> V_17 -> V_27 . V_1 . V_28 ,
& V_29 ) ;
}
