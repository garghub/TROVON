static inline unsigned int F_1 ( T_1 V_1 , T_2 V_2 , T_3 div )
{
return ( ( V_1 == 0x00 ) ? 0 : ( ( V_2 * 30 ) / ( V_1 * div ) ) ) ;
}
static int F_2 ( struct V_3 * V_4 , enum V_5 V_6 )
{
return F_3 ( V_4 , V_6 ) ;
}
static int F_4 ( struct V_3 * V_4 , enum V_5 V_6 ,
T_3 V_7 )
{
return F_5 ( V_4 , V_6 , V_7 ) ;
}
static struct V_8 * F_6 ( struct V_9 * V_10 )
{
struct V_8 * V_11 = F_7 ( V_10 ) ;
struct V_3 * V_4 = V_11 -> V_4 ;
F_8 ( & V_11 -> V_12 ) ;
if ( F_9 ( V_13 , V_11 -> V_14 + V_15 )
|| ! V_11 -> V_16 ) {
F_10 ( & V_4 -> V_10 , L_1 ) ;
V_11 -> V_17 = F_2 ( V_4 , V_18 ) ;
V_11 -> V_19 = F_2 ( V_4 , V_20 ) ;
V_11 -> V_21 = F_2 ( V_4 , V_22 ) ;
V_11 -> V_14 = V_13 ;
V_11 -> V_16 = 1 ;
}
F_11 ( & V_11 -> V_12 ) ;
return V_11 ;
}
static T_4 F_12 ( struct V_9 * V_10 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_8 * V_11 = F_6 ( V_10 ) ;
unsigned int V_26 = 0 ;
F_8 ( & V_11 -> V_12 ) ;
if ( ! ( V_11 -> V_21 & V_27 ) )
V_26 = F_1 ( V_11 -> V_19 , V_11 -> V_2 , V_11 -> V_28 ) ;
F_11 ( & V_11 -> V_12 ) ;
return sprintf ( V_25 , L_2 , V_26 ) ;
}
static T_4 F_13 ( struct V_9 * V_10 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_8 * V_11 = F_6 ( V_10 ) ;
int V_29 = ( V_11 -> V_21 & V_30 ) ? 1 : 0 ;
return sprintf ( V_25 , L_2 , V_29 ) ;
}
static T_4 F_14 ( struct V_9 * V_10 , struct V_23 * V_24 ,
char * V_25 )
{
struct V_8 * V_11 = F_6 ( V_10 ) ;
return sprintf ( V_25 , L_2 , F_15 ( V_11 -> V_17 ) ) ;
}
static T_4 F_16 ( struct V_9 * V_10 , struct V_23 * V_24 ,
const char * V_25 , T_5 V_31 )
{
struct V_8 * V_11 = F_6 ( V_10 ) ;
struct V_3 * V_4 = V_11 -> V_4 ;
unsigned long V_1 ;
if ( F_17 ( V_25 , 10 , & V_1 ) )
return - V_32 ;
F_8 ( & V_11 -> V_12 ) ;
V_11 -> V_17 = F_18 ( F_19 ( V_1 , 0 , 255 ) ) ;
F_4 ( V_4 , V_18 , V_11 -> V_17 ) ;
F_11 ( & V_11 -> V_12 ) ;
return V_31 ;
}
static int F_20 ( struct V_3 * V_4 ,
const struct V_33 * V_34 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_8 * V_11 ;
struct V_9 * V_35 ;
if ( ! F_21 ( V_4 -> V_36 , V_37 ) )
return - V_38 ;
V_11 = F_22 ( V_10 , sizeof( struct V_8 ) , V_39 ) ;
if ( ! V_11 )
return - V_40 ;
V_11 -> V_4 = V_4 ;
F_23 ( & V_11 -> V_12 ) ;
V_11 -> V_28 = V_41 ;
V_11 -> V_2 = V_42 ;
V_35 = F_24 ( V_10 , V_4 -> V_43 ,
V_11 ,
V_44 ) ;
return F_25 ( V_35 ) ;
}
