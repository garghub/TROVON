static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_6 = F_3 ( V_2 ) ;
int V_7 = F_4 ( V_4 ) -> V_8 ;
int V_9 ;
V_9 = F_5 ( V_6 , V_7 , 0 , 0 ) * V_10 ;
V_9 = F_6 ( V_9 , 1000 ) ;
return sprintf ( V_5 , L_2 , V_9 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_7 = F_4 ( V_4 ) -> V_8 ;
return sprintf ( V_5 , L_3 , V_11 [ V_7 ] ) ;
}
static int F_8 ( struct V_12 * V_13 )
{
struct V_6 * V_6 = F_9 ( V_13 ) ;
int V_14 ;
V_14 = F_10 ( & V_13 -> V_2 . V_15 , & V_16 ) ;
if ( V_14 )
goto V_17;
V_6 -> V_18 . V_19 = F_11 ( & V_13 -> V_2 ) ;
if ( F_12 ( V_6 -> V_18 . V_19 ) ) {
V_14 = F_13 ( V_6 -> V_18 . V_19 ) ;
goto V_20;
}
return 0 ;
V_20:
F_14 ( & V_13 -> V_2 . V_15 , & V_16 ) ;
V_17:
return V_14 ;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_6 * V_6 = F_9 ( V_13 ) ;
F_16 ( V_6 -> V_18 . V_19 ) ;
F_14 ( & V_13 -> V_2 . V_15 , & V_16 ) ;
return 0 ;
}
