static T_1 F_1 ( int V_1 , void * V_2 ,
T_2 V_3 , T_3 V_4 )
{
int V_5 , V_6 = V_7 ;
for (; ; ) {
V_5 = F_2 ( V_1 , 0 , ( V_8 ) V_2 ,
V_4 , V_3 ) ;
if ( V_5 >= 0 )
return V_5 ;
if ( V_5 == V_9 )
continue;
if ( V_5 == V_10 && -- V_6 > 0 ) {
F_3 ( V_11 ) ;
continue;
}
F_4 ( L_1 , V_5 ) ;
return - V_12 ;
}
}
static T_1 F_5 ( int V_1 , const void * V_2 ,
T_2 V_3 , T_3 V_4 )
{
int V_5 , V_6 = V_7 ;
for (; ; ) {
V_5 = F_6 ( V_1 , 0 , ( V_8 ) V_2 ,
V_4 , V_3 ) ;
if ( V_5 >= 0 )
return V_5 ;
if ( V_5 == V_9 )
continue;
if ( V_5 == V_10 && -- V_6 > 0 ) {
F_3 ( V_11 ) ;
continue;
}
F_4 ( L_2 , V_5 ) ;
return - V_12 ;
}
}
static int F_7 ( struct V_13 * V_13 , struct V_14 * V_15 )
{
V_15 -> V_16 = & V_17 [ F_8 ( V_13 ) ] ;
return 0 ;
}
static int F_9 ( struct V_13 * V_13 , struct V_14 * V_15 )
{
struct V_18 * V_19 = V_15 -> V_16 ;
char V_20 ;
F_10 ( & V_19 -> V_21 ) ;
if ( V_19 -> V_1 >= 0 )
F_5 ( V_19 -> V_1 , & V_20 , V_22 , 1 ) ;
F_11 ( & V_19 -> V_21 ) ;
V_15 -> V_16 = NULL ;
return 0 ;
}
static T_1 F_12 ( struct V_14 * V_15 , char T_4 * V_2 ,
T_3 V_4 , T_2 * V_23 )
{
int V_5 = 0 ;
void * V_24 ;
struct V_18 * V_19 = V_15 -> V_16 ;
V_24 = F_13 ( V_25 , V_26 ) ;
if ( ! V_24 )
return - V_27 ;
if ( F_14 ( & V_19 -> V_21 ) ) {
V_5 = - V_28 ;
F_15 ( V_24 ) ;
return V_5 ;
}
while ( V_4 ) {
int V_29 ;
int V_30 = F_16 ( V_4 , V_25 ) ;
V_29 = F_1 ( V_19 -> V_1 , V_24 ,
* V_23 , V_30 ) ;
if ( V_29 <= 0 ) {
if ( V_5 == 0 )
V_5 = V_29 ;
break;
}
if ( F_17 ( V_2 , V_24 , V_29 ) != 0 ) {
V_5 = - V_31 ;
break;
}
V_5 += V_29 ;
* V_23 += V_29 ;
V_2 += V_29 ;
V_4 -= V_29 ;
}
F_11 ( & V_19 -> V_21 ) ;
F_15 ( V_24 ) ;
return V_5 ;
}
static T_1 F_18 ( struct V_14 * V_15 , const char T_4 * V_2 ,
T_3 V_4 , T_2 * V_23 )
{
int V_5 = 0 ;
void * V_24 ;
struct V_18 * V_19 = V_15 -> V_16 ;
V_24 = F_13 ( V_25 , V_26 ) ;
if ( ! V_24 )
return - V_27 ;
if ( F_14 ( & V_19 -> V_21 ) ) {
V_5 = - V_28 ;
F_15 ( V_24 ) ;
return V_5 ;
}
while ( V_4 ) {
int V_29 ;
int V_30 = F_16 ( V_4 , V_25 ) ;
if ( F_19 ( V_24 , V_2 , V_30 ) != 0 ) {
V_5 = - V_31 ;
break;
}
V_29 = F_5 ( V_19 -> V_1 , V_24 ,
* V_23 , V_30 ) ;
if ( V_29 <= 0 ) {
if ( V_5 == 0 )
V_5 = V_29 ;
break;
}
V_5 += V_29 ;
* V_23 += V_29 ;
V_2 += V_29 ;
V_4 -= V_29 ;
}
F_11 ( & V_19 -> V_21 ) ;
F_15 ( V_24 ) ;
return V_5 ;
}
T_2 F_20 ( struct V_14 * V_14 , T_2 V_32 , int V_33 )
{
struct V_18 * V_19 = V_14 -> V_16 ;
return F_21 ( V_14 , V_32 , V_33 , V_19 -> V_34 ) ;
}
static T_1 F_22 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_2 )
{
struct V_18 * V_19 = F_23 ( V_36 ) ;
return sprintf ( V_2 , L_3 , V_19 -> V_34 ) ;
}
static T_1 F_24 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_2 )
{
struct V_18 * V_19 = F_23 ( V_36 ) ;
return sprintf ( V_2 , L_3 , V_19 -> V_39 ) ;
}
static T_1 F_25 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_2 )
{
struct V_18 * V_19 = F_23 ( V_36 ) ;
return sprintf ( V_2 , L_3 , V_19 -> V_40 ) ;
}
static char * F_26 ( struct V_35 * V_36 , T_5 * V_41 )
{
if ( V_41 )
* V_41 = 0644 ;
return F_27 ( V_26 , L_4 , F_28 ( V_36 ) ) ;
}
static int F_29 ( struct V_18 * V_19 , int V_42 )
{
V_19 -> V_1 = V_42 ;
F_30 ( & V_19 -> V_21 ) ;
if ( F_1 ( V_42 , & V_19 -> V_34 ,
V_43 , sizeof( V_19 -> V_34 ) ) < 0 )
return - V_12 ;
if ( F_1 ( V_42 , & V_19 -> V_39 ,
V_44 , sizeof( V_19 -> V_39 ) ) < 0 )
return - V_12 ;
if ( F_1 ( V_42 , & V_19 -> V_40 ,
V_45 , sizeof( V_19 -> V_40 ) ) < 0 )
return - V_12 ;
return 0 ;
}
static int F_31 ( void )
{
int V_46 , V_47 ;
T_6 V_36 = F_32 ( V_48 , 0 ) ;
V_17 = F_13 ( 4 * sizeof( struct V_18 ) , V_26 ) ;
for ( V_47 = 0 ; ; V_47 ++ ) {
int V_42 ;
char V_2 [ 20 ] ;
struct V_18 * V_49 =
F_33 ( V_17 , ( V_47 + 1 ) * sizeof( struct V_18 ) ,
V_26 ) ;
if ( ! V_49 ) {
V_46 = - V_27 ;
goto V_50;
}
V_17 = V_49 ;
sprintf ( V_2 , L_5 , V_47 ) ;
V_42 = F_34 ( ( V_8 ) V_2 , 0 ) ;
if ( V_42 < 0 ) {
if ( V_42 != V_51 )
F_35 ( L_6 ,
V_47 , V_42 ) ;
break;
}
V_46 = F_29 ( & V_17 [ V_47 ] , V_42 ) ;
if ( V_46 != 0 )
goto V_50;
}
V_52 = V_47 ;
if ( V_52 == 0 ) {
V_46 = - V_53 ;
goto V_50;
}
if ( V_48 )
V_46 = F_36 ( V_36 , V_52 , L_7 ) ;
else {
V_46 = F_37 ( & V_36 , 0 , V_52 , L_7 ) ;
V_48 = F_38 ( V_36 ) ;
}
if ( V_46 < 0 )
goto V_50;
F_39 ( & V_54 , & V_55 ) ;
V_54 . V_56 = V_57 ;
V_54 . V_58 = & V_55 ;
V_46 = F_40 ( & V_54 , V_36 , V_52 ) ;
if ( V_46 < 0 )
goto V_59;
V_60 = F_41 ( L_7 , - 1 , NULL , 0 ) ;
if ( F_42 ( V_60 ) ) {
V_46 = F_43 ( V_60 ) ;
goto V_61;
}
V_62 = F_44 ( V_57 , L_7 ) ;
if ( F_42 ( V_62 ) ) {
V_46 = F_43 ( V_62 ) ;
goto V_63;
}
V_62 -> V_64 = V_65 ;
V_62 -> V_66 = F_26 ;
for ( V_47 = 0 ; V_47 < V_52 ; V_47 ++ ) {
struct V_35 * V_36 =
F_45 ( V_62 , & V_60 -> V_36 ,
F_32 ( V_48 , V_47 ) , V_17 + V_47 ,
L_8 , V_47 ) ;
V_46 = F_46 ( V_36 ) ;
if ( V_46 < 0 )
goto V_67;
}
return 0 ;
V_67:
for ( V_47 = 0 ; V_47 < V_52 ; V_47 ++ )
F_47 ( V_62 , F_32 ( V_48 , V_47 ) ) ;
F_48 ( V_62 ) ;
V_63:
F_49 ( V_60 ) ;
V_61:
F_50 ( & V_54 ) ;
V_59:
F_51 ( V_36 , V_52 ) ;
V_50:
F_15 ( V_17 ) ;
return V_46 ;
}
static void F_52 ( void )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_52 ; V_47 ++ )
F_47 ( V_62 , F_32 ( V_48 , V_47 ) ) ;
F_48 ( V_62 ) ;
F_50 ( & V_54 ) ;
F_49 ( V_60 ) ;
F_51 ( F_32 ( V_48 , 0 ) , V_52 ) ;
F_15 ( V_17 ) ;
}
