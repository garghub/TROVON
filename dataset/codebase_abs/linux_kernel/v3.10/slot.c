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
F_14 (dev, &slot->bus->devices, bus_list)
if ( F_15 ( V_22 -> V_23 ) == V_7 -> V_13 )
V_22 -> V_7 = NULL ;
F_16 ( & V_7 -> V_24 ) ;
F_17 ( V_7 ) ;
}
static char * F_18 ( const char * V_25 )
{
char * V_26 ;
int V_11 , V_27 , V_28 ;
V_26 = F_19 ( V_25 , V_29 ) ;
if ( ! V_26 )
return NULL ;
V_11 = strlen ( V_25 ) + 2 ;
V_27 = 1 ;
V_28 = 1 ;
for (; ; ) {
struct V_1 * V_30 ;
V_30 = F_20 ( V_31 , V_26 ) ;
if ( ! V_30 )
break;
F_21 ( V_30 ) ;
if ( V_28 == V_27 ) {
V_11 ++ ;
V_27 *= 10 ;
F_17 ( V_26 ) ;
V_26 = F_22 ( V_11 , V_29 ) ;
if ( ! V_26 )
break;
}
sprintf ( V_26 , L_6 , V_25 , V_28 ++ ) ;
}
return V_26 ;
}
static int F_23 ( struct V_6 * V_7 , const char * V_25 )
{
int V_32 = 0 ;
char * V_33 ;
if ( strcmp ( F_13 ( V_7 ) , V_25 ) == 0 )
return V_32 ;
V_33 = F_18 ( V_25 ) ;
if ( ! V_33 )
return - V_34 ;
V_32 = F_24 ( & V_7 -> V_2 , V_33 ) ;
F_17 ( V_33 ) ;
return V_32 ;
}
static struct V_6 * F_25 ( struct V_35 * V_36 , int V_37 )
{
struct V_6 * V_7 ;
F_14 (slot, &parent->slots, list)
if ( V_7 -> V_13 == V_37 ) {
F_26 ( & V_7 -> V_2 ) ;
return V_7 ;
}
return NULL ;
}
struct V_6 * F_27 ( struct V_35 * V_36 , int V_37 ,
const char * V_25 ,
struct V_38 * V_39 )
{
struct V_21 * V_22 ;
struct V_6 * V_7 ;
int V_40 = 0 ;
char * V_33 = NULL ;
F_28 ( & V_41 ) ;
if ( V_37 == - 1 )
goto V_42;
V_7 = F_25 ( V_36 , V_37 ) ;
if ( V_7 ) {
if ( V_39 ) {
if ( ( V_40 = V_7 -> V_39 ? - V_43 : 0 )
|| ( V_40 = F_23 ( V_7 , V_25 ) ) ) {
F_21 ( & V_7 -> V_2 ) ;
V_7 = NULL ;
goto V_40;
}
}
goto V_44;
}
V_42:
V_7 = F_29 ( sizeof( * V_7 ) , V_29 ) ;
if ( ! V_7 ) {
V_40 = - V_34 ;
goto V_40;
}
V_7 -> V_14 = V_36 ;
V_7 -> V_13 = V_37 ;
V_7 -> V_2 . V_45 = V_31 ;
V_33 = F_18 ( V_25 ) ;
if ( ! V_33 ) {
V_40 = - V_34 ;
goto V_40;
}
V_40 = F_30 ( & V_7 -> V_2 , & V_46 , NULL ,
L_7 , V_33 ) ;
if ( V_40 )
goto V_40;
F_31 ( & V_7 -> V_24 ) ;
F_32 ( & V_7 -> V_24 , & V_36 -> V_47 ) ;
F_14 (dev, &parent->devices, bus_list)
if ( F_15 ( V_22 -> V_23 ) == V_37 )
V_22 -> V_7 = V_7 ;
F_12 ( & V_36 -> V_22 , L_8 ,
V_37 , F_13 ( V_7 ) ) ;
V_44:
F_17 ( V_33 ) ;
F_33 ( & V_41 ) ;
return V_7 ;
V_40:
F_17 ( V_7 ) ;
V_7 = F_34 ( V_40 ) ;
goto V_44;
}
void F_35 ( struct V_6 * V_7 , int V_37 )
{
struct V_6 * V_48 ;
F_28 ( & V_41 ) ;
F_14 (tmp, &slot->bus->slots, list) {
F_36 ( V_48 -> V_13 == V_37 ) ;
goto V_44;
}
V_7 -> V_13 = V_37 ;
V_44:
F_33 ( & V_41 ) ;
}
void F_37 ( struct V_6 * V_7 )
{
F_12 ( & V_7 -> V_14 -> V_22 , L_9 ,
V_7 -> V_13 , F_38 ( & V_7 -> V_2 . V_49 . V_50 ) - 1 ) ;
F_28 ( & V_41 ) ;
F_21 ( & V_7 -> V_2 ) ;
F_33 ( & V_41 ) ;
}
void F_39 ( struct V_6 * V_6 )
{
struct V_38 * V_7 = V_6 -> V_39 ;
struct V_1 * V_2 = NULL ;
int V_51 ;
if ( ! V_7 || ! V_7 -> V_52 )
return;
V_2 = F_20 ( V_53 , V_7 -> V_52 -> V_54 ) ;
if ( ! V_2 )
return;
V_51 = F_40 ( & V_6 -> V_2 , V_2 , L_10 ) ;
if ( V_51 )
F_41 ( & V_6 -> V_14 -> V_22 , L_11 ,
V_51 ) ;
F_21 ( V_2 ) ;
}
void F_42 ( struct V_6 * V_6 )
{
F_43 ( & V_6 -> V_2 , L_10 ) ;
}
static int F_44 ( void )
{
struct V_45 * V_55 ;
V_55 = F_45 ( & V_56 ) ;
V_31 = F_46 ( L_12 , NULL ,
& V_55 -> V_2 ) ;
if ( ! V_31 ) {
F_47 ( V_57 L_13 ) ;
return - V_34 ;
}
return 0 ;
}
