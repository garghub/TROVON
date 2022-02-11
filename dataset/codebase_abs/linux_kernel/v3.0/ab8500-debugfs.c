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
char V_26 [ 32 ] ;
int V_27 ;
unsigned long V_28 ;
int V_18 ;
V_27 = F_10 ( V_23 , ( sizeof( V_26 ) - 1 ) ) ;
if ( F_11 ( V_26 , V_22 , V_27 ) )
return - V_29 ;
V_26 [ V_27 ] = 0 ;
V_18 = F_12 ( V_26 , 0 , & V_28 ) ;
if ( V_18 )
return - V_30 ;
if ( V_28 >= V_31 ) {
F_4 ( V_5 , L_7 ) ;
return - V_30 ;
}
V_9 = V_28 ;
return V_27 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_3 )
{
return F_2 ( V_2 , L_8 , V_32 ) ;
}
static int F_14 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
return F_6 ( V_20 , F_13 , V_19 -> V_21 ) ;
}
static T_3 F_15 ( struct V_20 * V_20 ,
const char T_4 * V_22 ,
T_5 V_23 , T_6 * V_24 )
{
struct V_4 * V_5 = ( (struct V_1 * ) ( V_20 -> V_25 ) ) -> V_6 ;
char V_26 [ 32 ] ;
int V_27 ;
unsigned long V_33 ;
int V_18 ;
V_27 = F_10 ( V_23 , ( sizeof( V_26 ) - 1 ) ) ;
if ( F_11 ( V_26 , V_22 , V_27 ) )
return - V_29 ;
V_26 [ V_27 ] = 0 ;
V_18 = F_12 ( V_26 , 0 , & V_33 ) ;
if ( V_18 )
return - V_30 ;
if ( V_33 > 0xff ) {
F_4 ( V_5 , L_9 ) ;
return - V_30 ;
}
V_32 = V_33 ;
return V_27 ;
}
static int F_16 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_34 ;
T_2 V_35 ;
V_34 = F_3 ( V_5 ,
( T_2 ) V_9 , ( T_2 ) V_32 , & V_35 ) ;
if ( V_34 < 0 ) {
F_4 ( V_5 , L_10 ,
V_34 , __LINE__ ) ;
return - V_30 ;
}
F_2 ( V_2 , L_8 , V_35 ) ;
return 0 ;
}
static int F_17 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
return F_6 ( V_20 , F_16 , V_19 -> V_21 ) ;
}
static T_3 F_18 ( struct V_20 * V_20 ,
const char T_4 * V_22 ,
T_5 V_23 , T_6 * V_24 )
{
struct V_4 * V_5 = ( (struct V_1 * ) ( V_20 -> V_25 ) ) -> V_6 ;
char V_26 [ 32 ] ;
int V_27 ;
unsigned long V_36 ;
int V_18 ;
V_27 = F_10 ( V_23 , ( sizeof( V_26 ) - 1 ) ) ;
if ( F_11 ( V_26 , V_22 , V_27 ) )
return - V_29 ;
V_26 [ V_27 ] = 0 ;
V_18 = F_12 ( V_26 , 0 , & V_36 ) ;
if ( V_18 )
return - V_30 ;
if ( V_36 > 0xff ) {
F_4 ( V_5 , L_9 ) ;
return - V_30 ;
}
V_18 = F_19 ( V_5 ,
( T_2 ) V_9 , V_32 , ( T_2 ) V_36 ) ;
if ( V_18 < 0 ) {
F_20 ( V_37 L_11 , V_18 , __LINE__ ) ;
return - V_30 ;
}
return V_27 ;
}
static int T_7 F_21 ( struct V_38 * V_39 )
{
V_9 = V_40 ;
V_32 = V_41 & 0x00FF ;
V_42 = F_22 ( V_10 , NULL ) ;
if ( ! V_42 )
goto V_43;
V_44 = F_23 ( L_12 ,
V_45 , V_42 , & V_39 -> V_5 , & V_46 ) ;
if ( ! V_44 )
goto V_47;
V_48 = F_23 ( L_13 ,
( V_45 | V_49 ) , V_42 , & V_39 -> V_5 , & V_50 ) ;
if ( ! V_48 )
goto V_51;
V_52 = F_23 ( L_14 ,
( V_45 | V_49 ) , V_42 , & V_39 -> V_5 ,
& V_53 ) ;
if ( ! V_52 )
goto V_54;
V_55 = F_23 ( L_15 ,
( V_45 | V_49 ) , V_42 , & V_39 -> V_5 , & V_56 ) ;
if ( ! V_55 )
goto V_57;
return 0 ;
V_57:
F_24 ( V_52 ) ;
V_54:
F_24 ( V_48 ) ;
V_51:
F_24 ( V_44 ) ;
V_47:
F_24 ( V_42 ) ;
V_43:
F_4 ( & V_39 -> V_5 , L_16 ) ;
return - V_58 ;
}
static int T_8 F_25 ( struct V_38 * V_39 )
{
F_24 ( V_55 ) ;
F_24 ( V_52 ) ;
F_24 ( V_48 ) ;
F_24 ( V_44 ) ;
F_24 ( V_42 ) ;
return 0 ;
}
static int T_9 F_26 ( void )
{
return F_27 ( & V_59 ) ;
}
static void T_10 F_28 ( void )
{
F_29 ( & V_59 ) ;
}
