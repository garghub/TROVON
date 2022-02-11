static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_7 ;
T_1 V_8 = V_9 ;
F_2 ( V_2 , V_10 L_1 ) ;
F_2 ( V_2 , L_2 , V_8 ) ;
for ( V_7 = 0 ; V_7 < V_11 [ V_8 ] . V_12 ; V_7 ++ ) {
T_1 V_13 ;
for ( V_13 = V_11 [ V_8 ] . V_14 [ V_7 ] . V_15 ;
V_13 <= V_11 [ V_8 ] . V_14 [ V_7 ] . V_16 ;
V_13 ++ ) {
T_2 V_17 ;
int V_18 ;
V_18 = F_3 ( V_5 ,
( T_2 ) V_8 , ( T_2 ) V_13 , & V_17 ) ;
if ( V_18 < 0 ) {
F_4 ( V_5 , L_3 , V_18 ) ;
return V_18 ;
}
V_18 = F_2 ( V_2 , L_4 , V_8 ,
V_13 , V_17 ) ;
if ( V_18 < 0 ) {
F_4 ( V_5 , L_5 ) ;
return 0 ;
}
}
}
return 0 ;
}
static int F_5 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
return F_6 ( V_20 , F_1 , V_19 -> V_21 ) ;
}
static int F_7 ( struct V_1 * V_2 , void * V_3 )
{
return F_2 ( V_2 , L_6 , V_9 ) ;
}
static int F_8 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
return F_6 ( V_20 , F_7 , V_19 -> V_21 ) ;
}
static T_3 F_9 ( struct V_20 * V_20 ,
const char T_4 * V_22 ,
T_5 V_23 , T_6 * V_24 )
{
struct V_4 * V_5 = ( (struct V_1 * ) ( V_20 -> V_25 ) ) -> V_6 ;
unsigned long V_26 ;
int V_18 ;
V_18 = F_10 ( V_22 , V_23 , 0 , & V_26 ) ;
if ( V_18 )
return V_18 ;
if ( V_26 >= V_27 ) {
F_4 ( V_5 , L_7 ) ;
return - V_28 ;
}
V_9 = V_26 ;
return V_23 ;
}
static int F_11 ( struct V_1 * V_2 , void * V_3 )
{
return F_2 ( V_2 , L_8 , V_29 ) ;
}
static int F_12 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
return F_6 ( V_20 , F_11 , V_19 -> V_21 ) ;
}
static T_3 F_13 ( struct V_20 * V_20 ,
const char T_4 * V_22 ,
T_5 V_23 , T_6 * V_24 )
{
struct V_4 * V_5 = ( (struct V_1 * ) ( V_20 -> V_25 ) ) -> V_6 ;
unsigned long V_30 ;
int V_18 ;
V_18 = F_10 ( V_22 , V_23 , 0 , & V_30 ) ;
if ( V_18 )
return V_18 ;
if ( V_30 > 0xff ) {
F_4 ( V_5 , L_9 ) ;
return - V_28 ;
}
V_29 = V_30 ;
return V_23 ;
}
static int F_14 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_31 ;
T_2 V_32 ;
V_31 = F_3 ( V_5 ,
( T_2 ) V_9 , ( T_2 ) V_29 , & V_32 ) ;
if ( V_31 < 0 ) {
F_4 ( V_5 , L_10 ,
V_31 , __LINE__ ) ;
return - V_28 ;
}
F_2 ( V_2 , L_8 , V_32 ) ;
return 0 ;
}
static int F_15 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
return F_6 ( V_20 , F_14 , V_19 -> V_21 ) ;
}
static T_3 F_16 ( struct V_20 * V_20 ,
const char T_4 * V_22 ,
T_5 V_23 , T_6 * V_24 )
{
struct V_4 * V_5 = ( (struct V_1 * ) ( V_20 -> V_25 ) ) -> V_6 ;
unsigned long V_33 ;
int V_18 ;
V_18 = F_10 ( V_22 , V_23 , 0 , & V_33 ) ;
if ( V_18 )
return V_18 ;
if ( V_33 > 0xff ) {
F_4 ( V_5 , L_9 ) ;
return - V_28 ;
}
V_18 = F_17 ( V_5 ,
( T_2 ) V_9 , V_29 , ( T_2 ) V_33 ) ;
if ( V_18 < 0 ) {
F_18 ( V_34 L_11 , V_18 , __LINE__ ) ;
return - V_28 ;
}
return V_23 ;
}
static int T_7 F_19 ( struct V_35 * V_36 )
{
V_9 = V_37 ;
V_29 = V_38 & 0x00FF ;
V_39 = F_20 ( V_10 , NULL ) ;
if ( ! V_39 )
goto V_40;
V_41 = F_21 ( L_12 ,
V_42 , V_39 , & V_36 -> V_5 , & V_43 ) ;
if ( ! V_41 )
goto V_44;
V_45 = F_21 ( L_13 ,
( V_42 | V_46 ) , V_39 , & V_36 -> V_5 , & V_47 ) ;
if ( ! V_45 )
goto V_48;
V_49 = F_21 ( L_14 ,
( V_42 | V_46 ) , V_39 , & V_36 -> V_5 ,
& V_50 ) ;
if ( ! V_49 )
goto V_51;
V_52 = F_21 ( L_15 ,
( V_42 | V_46 ) , V_39 , & V_36 -> V_5 , & V_53 ) ;
if ( ! V_52 )
goto V_54;
return 0 ;
V_54:
F_22 ( V_49 ) ;
V_51:
F_22 ( V_45 ) ;
V_48:
F_22 ( V_41 ) ;
V_44:
F_22 ( V_39 ) ;
V_40:
F_4 ( & V_36 -> V_5 , L_16 ) ;
return - V_55 ;
}
static int T_8 F_23 ( struct V_35 * V_36 )
{
F_22 ( V_52 ) ;
F_22 ( V_49 ) ;
F_22 ( V_45 ) ;
F_22 ( V_41 ) ;
F_22 ( V_39 ) ;
return 0 ;
}
static int T_9 F_24 ( void )
{
return F_25 ( & V_56 ) ;
}
static void T_10 F_26 ( void )
{
F_27 ( & V_56 ) ;
}
