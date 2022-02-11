static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_9 )
return sprintf ( V_5 , L_2 ) ;
return sprintf ( V_5 , L_3 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
bool V_9 ;
int V_11 ;
if ( F_5 ( V_5 , L_2 ) || F_5 ( V_5 , L_4 ) )
V_9 = true ;
else if ( F_5 ( V_5 , L_3 ) || F_5 ( V_5 , L_5 ) )
V_9 = false ;
else {
F_6 ( V_2 , L_6 ) ;
return V_10 ;
}
F_7 ( & V_7 -> V_12 ) ;
if ( V_9 != V_7 -> V_9 ) {
if ( V_9 )
V_11 = F_8 ( V_7 -> V_13 ,
V_7 -> V_14 ) ;
else
V_11 = F_9 ( V_7 -> V_13 ,
V_7 -> V_14 ) ;
if ( V_11 == 0 )
V_7 -> V_9 = V_9 ;
else
F_6 ( V_2 , L_7 , V_11 ) ;
}
F_10 ( & V_7 -> V_12 ) ;
return V_10 ;
}
static int F_11 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_6 * V_19 ;
int V_11 ;
V_18 = F_12 ( & V_16 -> V_2 ) ;
if ( ! V_18 )
return - V_20 ;
V_19 = F_13 ( & V_16 -> V_2 ,
sizeof( struct V_6 ) ,
V_21 ) ;
if ( V_19 == NULL )
return - V_22 ;
V_19 -> V_8 = V_18 -> V_8 ;
V_19 -> V_13 = V_18 -> V_13 ;
V_19 -> V_14 = V_18 -> V_14 ;
F_14 ( & V_19 -> V_12 ) ;
V_11 = F_15 ( & V_16 -> V_2 , V_19 -> V_13 ,
V_19 -> V_14 ) ;
if ( V_11 ) {
F_6 ( & V_16 -> V_2 , L_8 , V_11 ) ;
return V_11 ;
}
V_11 = F_16 ( & V_16 -> V_2 . V_23 , & V_24 ) ;
if ( V_11 != 0 )
return V_11 ;
if ( V_18 -> V_25 ) {
V_11 = F_8 ( V_19 -> V_13 ,
V_19 -> V_14 ) ;
if ( V_11 ) {
F_6 ( & V_16 -> V_2 ,
L_9 , V_11 ) ;
goto V_26;
}
}
V_19 -> V_9 = V_18 -> V_25 ;
F_17 ( V_16 , V_19 ) ;
return 0 ;
V_26:
F_18 ( & V_16 -> V_2 . V_23 , & V_24 ) ;
return V_11 ;
}
static int F_19 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = F_20 ( V_16 ) ;
F_18 ( & V_16 -> V_2 . V_23 , & V_24 ) ;
if ( V_7 -> V_9 )
F_9 ( V_7 -> V_13 , V_7 -> V_14 ) ;
return 0 ;
}
