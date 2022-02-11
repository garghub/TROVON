static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_3 = F_3 ( V_4 ) ;
return V_3 -> V_9 ? V_3 -> V_9 ( V_7 , V_5 ) : - V_10 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_3 = F_3 ( V_4 ) ;
return V_3 -> V_12 ? V_3 -> V_12 ( V_7 , V_5 , V_11 ) : - V_10 ;
}
static T_1 F_5 ( struct V_6 * V_7 , char * V_5 )
{
if ( V_7 -> V_13 == 0xff )
return sprintf ( V_5 , L_1 ,
F_6 ( V_7 -> V_14 ) ,
V_7 -> V_14 -> V_13 ) ;
else
return sprintf ( V_5 , L_2 ,
F_6 ( V_7 -> V_14 ) ,
V_7 -> V_14 -> V_13 ,
V_7 -> V_13 ) ;
}
static T_1 F_7 ( enum V_15 V_16 , char * V_5 )
{
const char * V_17 ;
if ( V_16 < F_8 ( V_18 ) )
V_17 = V_18 [ V_16 ] ;
else
V_17 = L_3 ;
return sprintf ( V_5 , L_4 , V_17 ) ;
}
static T_1 F_9 ( struct V_6 * V_7 , char * V_5 )
{
return F_7 ( V_7 -> V_14 -> V_19 , V_5 ) ;
}
static T_1 F_10 ( struct V_6 * V_7 , char * V_5 )
{
return F_7 ( V_7 -> V_14 -> V_20 , V_5 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_12 ( & V_7 -> V_14 -> V_22 , L_5 ,
V_7 -> V_13 , F_13 ( V_7 ) ) ;
F_14 ( & V_23 ) ;
F_15 (dev, &slot->bus->devices, bus_list)
if ( F_16 ( V_22 -> V_24 ) == V_7 -> V_13 )
V_22 -> V_7 = NULL ;
F_17 ( & V_23 ) ;
F_18 ( & V_7 -> V_25 ) ;
F_19 ( V_7 ) ;
}
static char * F_20 ( const char * V_26 )
{
char * V_27 ;
int V_11 , V_28 , V_29 ;
V_27 = F_21 ( V_26 , V_30 ) ;
if ( ! V_27 )
return NULL ;
V_11 = strlen ( V_26 ) + 2 ;
V_28 = 1 ;
V_29 = 1 ;
for (; ; ) {
struct V_1 * V_31 ;
V_31 = F_22 ( V_32 , V_27 ) ;
if ( ! V_31 )
break;
F_23 ( V_31 ) ;
if ( V_29 == V_28 ) {
V_11 ++ ;
V_28 *= 10 ;
F_19 ( V_27 ) ;
V_27 = F_24 ( V_11 , V_30 ) ;
if ( ! V_27 )
break;
}
sprintf ( V_27 , L_6 , V_26 , V_29 ++ ) ;
}
return V_27 ;
}
static int F_25 ( struct V_6 * V_7 , const char * V_26 )
{
int V_33 = 0 ;
char * V_34 ;
if ( strcmp ( F_13 ( V_7 ) , V_26 ) == 0 )
return V_33 ;
V_34 = F_20 ( V_26 ) ;
if ( ! V_34 )
return - V_35 ;
V_33 = F_26 ( & V_7 -> V_2 , V_34 ) ;
F_19 ( V_34 ) ;
return V_33 ;
}
void F_27 ( struct V_21 * V_22 )
{
struct V_6 * V_7 ;
F_28 ( & V_36 ) ;
F_15 (slot, &dev->bus->slots, list)
if ( F_16 ( V_22 -> V_24 ) == V_7 -> V_13 )
V_22 -> V_7 = V_7 ;
F_29 ( & V_36 ) ;
}
static struct V_6 * F_30 ( struct V_37 * V_38 , int V_39 )
{
struct V_6 * V_7 ;
F_15 (slot, &parent->slots, list)
if ( V_7 -> V_13 == V_39 ) {
F_31 ( & V_7 -> V_2 ) ;
return V_7 ;
}
return NULL ;
}
struct V_6 * F_32 ( struct V_37 * V_38 , int V_39 ,
const char * V_26 ,
struct V_40 * V_41 )
{
struct V_21 * V_22 ;
struct V_6 * V_7 ;
int V_42 = 0 ;
char * V_34 = NULL ;
F_28 ( & V_36 ) ;
if ( V_39 == - 1 )
goto V_43;
V_7 = F_30 ( V_38 , V_39 ) ;
if ( V_7 ) {
if ( V_41 ) {
if ( ( V_42 = V_7 -> V_41 ? - V_44 : 0 )
|| ( V_42 = F_25 ( V_7 , V_26 ) ) ) {
F_23 ( & V_7 -> V_2 ) ;
V_7 = NULL ;
goto V_42;
}
}
goto V_45;
}
V_43:
V_7 = F_33 ( sizeof( * V_7 ) , V_30 ) ;
if ( ! V_7 ) {
V_42 = - V_35 ;
goto V_42;
}
V_7 -> V_14 = V_38 ;
V_7 -> V_13 = V_39 ;
V_7 -> V_2 . V_46 = V_32 ;
V_34 = F_20 ( V_26 ) ;
if ( ! V_34 ) {
V_42 = - V_35 ;
goto V_42;
}
V_42 = F_34 ( & V_7 -> V_2 , & V_47 , NULL ,
L_7 , V_34 ) ;
if ( V_42 )
goto V_42;
F_35 ( & V_7 -> V_25 ) ;
F_36 ( & V_7 -> V_25 , & V_38 -> V_48 ) ;
F_14 ( & V_23 ) ;
F_15 (dev, &parent->devices, bus_list)
if ( F_16 ( V_22 -> V_24 ) == V_39 )
V_22 -> V_7 = V_7 ;
F_17 ( & V_23 ) ;
F_12 ( & V_38 -> V_22 , L_8 ,
V_39 , F_13 ( V_7 ) ) ;
V_45:
F_19 ( V_34 ) ;
F_29 ( & V_36 ) ;
return V_7 ;
V_42:
F_19 ( V_7 ) ;
V_7 = F_37 ( V_42 ) ;
goto V_45;
}
void F_38 ( struct V_6 * V_7 )
{
F_12 ( & V_7 -> V_14 -> V_22 , L_9 ,
V_7 -> V_13 , F_39 ( & V_7 -> V_2 . V_49 ) - 1 ) ;
F_28 ( & V_36 ) ;
F_23 ( & V_7 -> V_2 ) ;
F_29 ( & V_36 ) ;
}
void F_40 ( struct V_6 * V_6 )
{
struct V_40 * V_7 = V_6 -> V_41 ;
struct V_1 * V_2 = NULL ;
int V_50 ;
if ( ! V_7 || ! V_7 -> V_51 )
return;
V_2 = F_22 ( V_52 , V_7 -> V_51 -> V_53 ) ;
if ( ! V_2 )
return;
V_50 = F_41 ( & V_6 -> V_2 , V_2 , L_10 ) ;
if ( V_50 )
F_42 ( & V_6 -> V_14 -> V_22 , L_11 ,
V_50 ) ;
F_23 ( V_2 ) ;
}
void F_43 ( struct V_6 * V_6 )
{
F_44 ( & V_6 -> V_2 , L_10 ) ;
}
static int F_45 ( void )
{
struct V_46 * V_54 ;
V_54 = F_46 ( & V_55 ) ;
V_32 = F_47 ( L_12 , NULL ,
& V_54 -> V_2 ) ;
if ( ! V_32 ) {
F_48 ( V_56 L_13 ) ;
return - V_35 ;
}
return 0 ;
}
