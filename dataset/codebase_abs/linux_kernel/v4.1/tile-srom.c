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
* V_41 = V_42 | V_43 ;
return F_27 ( V_26 , L_4 , F_28 ( V_36 ) ) ;
}
static int F_29 ( struct V_18 * V_19 , int V_44 )
{
struct V_35 * V_36 ;
int V_45 = V_19 -> V_1 ;
F_30 ( & V_19 -> V_21 ) ;
if ( F_1 ( V_45 , & V_19 -> V_34 ,
V_46 , sizeof( V_19 -> V_34 ) ) < 0 )
return - V_12 ;
if ( F_1 ( V_45 , & V_19 -> V_39 ,
V_47 , sizeof( V_19 -> V_39 ) ) < 0 )
return - V_12 ;
if ( F_1 ( V_45 , & V_19 -> V_40 ,
V_48 , sizeof( V_19 -> V_40 ) ) < 0 )
return - V_12 ;
V_36 = F_31 ( V_49 , & V_50 -> V_36 ,
F_32 ( V_51 , V_44 ) , V_19 , L_5 , V_44 ) ;
return F_33 ( V_36 ) ;
}
static int F_34 ( void )
{
int V_52 , V_53 ;
T_6 V_36 = F_32 ( V_51 , 0 ) ;
V_17 = F_35 ( 4 * sizeof( struct V_18 ) , V_26 ) ;
for ( V_53 = 0 ; ; V_53 ++ ) {
int V_45 ;
char V_2 [ 20 ] ;
struct V_18 * V_54 =
F_36 ( V_17 , ( V_53 + 1 ) * sizeof( struct V_18 ) ,
V_26 | V_55 ) ;
if ( ! V_54 ) {
V_52 = - V_27 ;
goto V_56;
}
V_17 = V_54 ;
sprintf ( V_2 , L_6 , V_53 ) ;
V_45 = F_37 ( ( V_8 ) V_2 , 0 ) ;
if ( V_45 < 0 ) {
if ( V_45 != V_57 )
F_38 ( L_7 ,
V_53 , V_45 ) ;
break;
}
V_17 [ V_53 ] . V_1 = V_45 ;
}
V_58 = V_53 ;
if ( V_58 == 0 ) {
V_52 = - V_59 ;
goto V_56;
}
if ( V_51 )
V_52 = F_39 ( V_36 , V_58 , L_8 ) ;
else {
V_52 = F_40 ( & V_36 , 0 , V_58 , L_8 ) ;
V_51 = F_41 ( V_36 ) ;
}
if ( V_52 < 0 )
goto V_56;
F_42 ( & V_60 , & V_61 ) ;
V_60 . V_62 = V_63 ;
V_60 . V_64 = & V_61 ;
V_52 = F_43 ( & V_60 , V_36 , V_58 ) ;
if ( V_52 < 0 )
goto V_65;
V_50 = F_44 ( L_8 , - 1 , NULL , 0 ) ;
if ( F_45 ( V_50 ) ) {
V_52 = F_46 ( V_50 ) ;
goto V_66;
}
V_49 = F_47 ( V_63 , L_8 ) ;
if ( F_45 ( V_49 ) ) {
V_52 = F_46 ( V_49 ) ;
goto V_67;
}
V_49 -> V_68 = V_69 ;
V_49 -> V_70 = F_26 ;
for ( V_53 = 0 ; V_53 < V_58 ; V_53 ++ ) {
V_52 = F_29 ( V_17 + V_53 , V_53 ) ;
if ( V_52 < 0 )
goto V_71;
}
return 0 ;
V_71:
for ( V_53 = 0 ; V_53 < V_58 ; V_53 ++ )
F_48 ( V_49 , F_32 ( V_51 , V_53 ) ) ;
F_49 ( V_49 ) ;
V_67:
F_50 ( V_50 ) ;
V_66:
F_51 ( & V_60 ) ;
V_65:
F_52 ( V_36 , V_58 ) ;
V_56:
F_15 ( V_17 ) ;
return V_52 ;
}
static void F_53 ( void )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_58 ; V_53 ++ )
F_48 ( V_49 , F_32 ( V_51 , V_53 ) ) ;
F_49 ( V_49 ) ;
F_51 ( & V_60 ) ;
F_50 ( V_50 ) ;
F_52 ( F_32 ( V_51 , 0 ) , V_58 ) ;
F_15 ( V_17 ) ;
}
