static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int * V_9 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_4 ( V_4 ) ;
unsigned int V_12 = V_11 -> V_13 ;
unsigned int V_14 [ 4 ] ;
int V_15 ;
V_15 = F_5 ( V_7 -> V_16 ,
V_17 ,
V_12 , 0 , 0 , V_14 ) ;
if ( V_15 )
return V_15 ;
V_12 &= 0x7 ;
* V_9 = ( V_14 [ V_12 % 4 ] >> ( V_12 > 3 ? 14 : 2 ) ) & 0x3ff ;
return 0 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
unsigned V_9 ;
struct V_18 * V_19 = F_7 ( V_2 ) ;
T_2 V_20 = F_8 ( V_19 ) -> V_20 ;
int V_15 = F_3 ( V_2 , V_4 , & V_9 ) ;
if ( V_15 )
return V_15 ;
if ( V_20 & V_21 )
V_9 = F_9 ( V_9 * 9 , 2 ) ;
else
V_9 = F_9 ( V_9 * 9 , 4 ) + 2400 ;
return sprintf ( V_5 , L_2 , V_9 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
unsigned V_9 ;
int V_15 = F_3 ( V_2 , V_4 , & V_9 ) ;
if ( V_15 )
return V_15 ;
V_9 = F_9 ( V_9 * 9 , 4 ) ;
return sprintf ( V_5 , L_2 , V_9 ) ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_6 * V_7 = F_12 ( V_19 ) ;
unsigned V_22 = F_13 ( V_7 -> V_16 ) ;
return V_22 & V_23 ;
}
static int T_3 F_14 ( struct V_18 * V_19 )
{
struct V_6 * V_7 ;
int V_15 ;
const struct V_24 * V_25 = F_8 ( V_19 ) ;
char * V_26 ;
V_7 = F_15 ( & V_19 -> V_2 , sizeof( * V_7 ) , V_27 ) ;
if ( ! V_7 )
return - V_28 ;
V_7 -> V_16 = F_2 ( V_19 -> V_2 . V_29 ) ;
snprintf ( V_7 -> V_8 , F_16 ( V_7 -> V_8 ) , L_3 , V_25 -> V_8 ) ;
V_26 = strchr ( V_7 -> V_8 , '-' ) ;
if ( V_26 )
* V_26 = '\0' ;
F_17 ( V_19 , V_7 ) ;
V_15 = F_18 ( & V_19 -> V_2 . V_30 , & V_31 ) ;
if ( V_15 )
return V_15 ;
if ( V_25 -> V_20 & V_32 ) {
V_15 = F_18 ( & V_19 -> V_2 . V_30 ,
& V_33 ) ;
if ( V_15 )
goto V_34;
}
if ( ! F_11 ( V_19 ) ) {
V_15 = F_18 ( & V_19 -> V_2 . V_30 , & V_35 ) ;
if ( V_15 )
goto V_36;
}
V_7 -> V_37 = F_19 ( & V_19 -> V_2 ) ;
if ( F_20 ( V_7 -> V_37 ) ) {
V_15 = F_21 ( V_7 -> V_37 ) ;
F_22 ( & V_19 -> V_2 ,
L_4 , V_15 ) ;
goto V_38;
}
return 0 ;
V_38:
if ( ! F_11 ( V_19 ) )
F_23 ( & V_19 -> V_2 . V_30 , & V_35 ) ;
V_36:
if ( V_25 -> V_20 & V_32 )
F_23 ( & V_19 -> V_2 . V_30 , & V_33 ) ;
V_34:
F_23 ( & V_19 -> V_2 . V_30 , & V_31 ) ;
return V_15 ;
}
static int F_24 ( struct V_18 * V_19 )
{
struct V_6 * V_7 = F_12 ( V_19 ) ;
T_2 V_20 = F_8 ( V_19 ) -> V_20 ;
F_25 ( V_7 -> V_37 ) ;
if ( ! F_11 ( V_19 ) )
F_23 ( & V_19 -> V_2 . V_30 , & V_35 ) ;
if ( V_20 & V_32 )
F_23 ( & V_19 -> V_2 . V_30 , & V_33 ) ;
F_23 ( & V_19 -> V_2 . V_30 , & V_31 ) ;
return 0 ;
}
