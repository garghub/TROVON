static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = F_3 ( V_2 , V_7 [ V_3 ] ) ;
V_5 -> V_8 = V_3 ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , int V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_9 == 0 )
V_6 = F_3 ( V_2 , V_10 ) ;
else {
V_6 = F_3 ( V_2 , V_11 ) ;
F_1 ( V_2 , V_5 -> V_8 ) ;
}
V_5 -> V_12 = V_9 ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_13 )
{
int V_6 ;
V_6 = F_6 ( V_2 , V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! ( V_6 & 0x80 ) )
return - V_14 ;
return V_6 & 0x7f ;
}
static int F_7 ( T_1 V_15 , T_1 V_16 )
{
unsigned int V_17 ;
T_2 V_18 = V_19 [ V_15 ] ;
T_2 V_20 = V_19 [ V_16 ] ;
T_1 V_21 = 128 ;
if ( V_20 <= V_18 )
if ( V_18 ) {
V_21 = V_20 * 128 / V_18 ;
V_17 = ( ( V_18 - V_20 ) * V_22 [ V_21 ] ) / 256 ;
} else
V_17 = 0 ;
else
return - V_14 ;
return V_17 > V_23 ? V_23 : V_17 ;
}
static T_3 F_8 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_4 * V_5 = F_2 ( F_9 ( V_25 ) ) ;
return sprintf ( V_28 , L_1 , V_5 -> V_12 ) ;
}
static T_3 F_10 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_28 , T_4 V_29 )
{
struct V_1 * V_2 = F_9 ( V_25 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_30 = F_11 ( V_28 , NULL , 10 ) ;
int V_6 ;
if ( V_30 < 0 || V_30 > 1 )
return - V_31 ;
F_12 ( & V_5 -> V_32 ) ;
V_6 = F_4 ( V_2 , V_30 ) ;
F_13 ( & V_5 -> V_32 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_29 ;
}
static T_3 F_14 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_4 * V_5 = F_2 ( F_9 ( V_25 ) ) ;
return sprintf ( V_28 , L_1 , V_5 -> V_8 ) ;
}
static T_3 F_15 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_28 , T_4 V_29 )
{
struct V_1 * V_2 = F_9 ( V_25 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_30 = F_11 ( V_28 , NULL , 10 ) ;
int V_6 ;
if ( V_30 < 0 || V_30 > 1 )
return - V_31 ;
if ( V_5 -> V_12 == 0 )
return - V_33 ;
F_12 ( & V_5 -> V_32 ) ;
V_6 = F_1 ( V_2 , V_30 ) ;
F_13 ( & V_5 -> V_32 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_29 ;
}
static T_3 F_16 ( struct V_1 * V_2 , char * V_28 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_15 , V_16 ;
int V_6 ;
V_6 = F_5 ( V_2 , V_34 ) ;
if ( V_6 < 0 )
return V_6 ;
V_15 = V_6 ;
V_6 = F_5 ( V_2 , V_35 ) ;
if ( V_6 < 0 )
return V_6 ;
V_16 = V_6 ;
V_6 = F_7 ( V_15 , V_16 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_5 -> V_8 == 1 )
V_6 *= 5 ;
return sprintf ( V_28 , L_2 , V_6 ) ;
}
static T_3 F_17 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_1 * V_2 = F_9 ( V_25 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( ! V_5 -> V_12 )
return - V_33 ;
F_12 ( & V_5 -> V_32 ) ;
V_6 = F_16 ( V_2 , V_28 ) ;
F_13 ( & V_5 -> V_32 ) ;
return V_6 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_36 ;
V_36 = F_6 ( V_2 , V_11 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_36 != V_11 )
return - V_37 ;
V_5 -> V_12 = 1 ;
V_36 = F_3 ( V_2 ,
V_7 [ V_5 -> V_8 ] ) ;
if ( V_36 < 0 )
return V_36 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_38 * V_39 )
{
struct V_40 * V_41 = F_20 ( V_2 -> V_25 . V_42 ) ;
struct V_4 * V_5 ;
int * V_43 , V_36 = 0 ;
if ( ! F_21 ( V_41 , V_44
| V_45 ) ) {
V_36 = - V_46 ;
goto exit;
}
V_5 = F_22 ( sizeof( struct V_4 ) , V_47 ) ;
if ( ! V_5 ) {
V_36 = - V_48 ;
goto exit;
}
V_5 -> V_2 = V_2 ;
F_23 ( V_2 , V_5 ) ;
V_43 = V_2 -> V_25 . V_49 ;
if ( V_43 ) {
if ( * V_43 < 0 || * V_43 > 1 ) {
F_24 ( & V_2 -> V_25 , L_3 ,
* V_43 ) ;
V_36 = - V_31 ;
goto V_50;
}
V_5 -> V_8 = * V_43 ;
} else
V_5 -> V_8 = 0 ;
F_25 ( & V_2 -> V_25 , L_4 ,
V_5 -> V_8 ? L_5 : L_6 ) ;
F_26 ( & V_5 -> V_32 ) ;
V_36 = F_18 ( V_2 ) ;
if ( V_36 )
goto V_50;
V_36 = F_27 ( & V_2 -> V_25 . V_51 , & V_52 ) ;
if ( V_36 )
goto V_50;
F_25 ( & V_2 -> V_25 , L_7 , V_53 ) ;
return 0 ;
V_50:
F_28 ( V_5 ) ;
exit:
return V_36 ;
}
static int F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_25 . V_51 , & V_52 ) ;
F_4 ( V_2 , 0 ) ;
F_28 ( F_2 ( V_2 ) ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , T_5 V_54 )
{
return F_4 ( V_2 , 0 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , 1 ) ;
}
