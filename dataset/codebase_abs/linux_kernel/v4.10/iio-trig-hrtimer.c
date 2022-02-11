static
T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return snprintf ( V_5 , V_10 , L_1 , V_9 -> V_11 ) ;
}
static
T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned long V_13 ;
int V_14 ;
V_14 = F_5 ( V_5 , 10 , & V_13 ) ;
if ( V_14 )
return V_14 ;
if ( ! V_13 || V_13 > V_15 )
return - V_16 ;
V_9 -> V_11 = V_13 ;
V_9 -> V_17 = V_15 / V_13 ;
return V_12 ;
}
static enum V_18 F_6 ( struct V_19 * V_20 )
{
struct V_8 * V_9 ;
V_9 = F_7 ( V_20 , struct V_8 , V_20 ) ;
F_8 ( V_20 , V_9 -> V_17 ) ;
F_9 ( V_9 -> V_21 . V_22 ) ;
return V_23 ;
}
static int F_10 ( struct V_6 * V_7 , bool V_24 )
{
struct V_8 * V_25 ;
V_25 = F_3 ( V_7 ) ;
if ( V_24 )
F_11 ( & V_25 -> V_20 , V_25 -> V_17 ,
V_26 ) ;
else
F_12 ( & V_25 -> V_20 ) ;
return 0 ;
}
static struct V_27 * F_13 ( const char * V_28 )
{
struct V_8 * V_25 ;
int V_14 ;
V_25 = F_14 ( sizeof( * V_25 ) , V_29 ) ;
if ( ! V_25 )
return F_15 ( - V_30 ) ;
V_25 -> V_21 . V_22 = F_16 ( L_2 , V_28 ) ;
if ( ! V_25 -> V_21 . V_22 ) {
V_14 = - V_30 ;
goto V_31;
}
F_17 ( V_25 -> V_21 . V_22 , V_25 ) ;
V_25 -> V_21 . V_22 -> V_32 = & V_33 ;
V_25 -> V_21 . V_22 -> V_2 . V_34 = V_35 ;
F_18 ( & V_25 -> V_20 , V_36 , V_26 ) ;
V_25 -> V_20 . V_37 = F_6 ;
V_25 -> V_11 = V_38 ;
V_25 -> V_17 = V_15 / V_25 -> V_11 ;
V_14 = F_19 ( V_25 -> V_21 . V_22 ) ;
if ( V_14 )
goto V_39;
F_20 ( & V_25 -> V_21 , V_28 , & V_40 ) ;
return & V_25 -> V_21 ;
V_39:
F_21 ( V_25 -> V_21 . V_22 ) ;
V_31:
F_22 ( V_25 ) ;
return F_15 ( V_14 ) ;
}
static int F_23 ( struct V_27 * V_21 )
{
struct V_8 * V_25 ;
V_25 = F_3 ( V_21 -> V_22 ) ;
F_24 ( V_21 -> V_22 ) ;
F_12 ( & V_25 -> V_20 ) ;
F_21 ( V_21 -> V_22 ) ;
F_22 ( V_25 ) ;
return 0 ;
}
