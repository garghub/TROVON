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
T_2 F_20 ( struct V_14 * V_15 , T_2 V_32 , int V_33 )
{
struct V_18 * V_19 = V_15 -> V_16 ;
if ( F_14 ( & V_19 -> V_21 ) )
return - V_28 ;
switch ( V_33 ) {
case V_34 :
V_32 += V_19 -> V_35 ;
break;
case V_36 :
V_32 += V_15 -> V_23 ;
break;
}
if ( V_32 < 0 || V_32 > V_19 -> V_35 ) {
V_32 = - V_37 ;
} else {
V_15 -> V_23 = V_32 ;
V_15 -> V_38 = 0 ;
}
F_11 ( & V_19 -> V_21 ) ;
return V_32 ;
}
static T_1 F_21 ( struct V_39 * V_40 ,
struct V_41 * V_42 , char * V_2 )
{
struct V_18 * V_19 = F_22 ( V_40 ) ;
return sprintf ( V_2 , L_3 , V_19 -> V_35 ) ;
}
static T_1 F_23 ( struct V_39 * V_40 ,
struct V_41 * V_42 , char * V_2 )
{
struct V_18 * V_19 = F_22 ( V_40 ) ;
return sprintf ( V_2 , L_3 , V_19 -> V_43 ) ;
}
static T_1 F_24 ( struct V_39 * V_40 ,
struct V_41 * V_42 , char * V_2 )
{
struct V_18 * V_19 = F_22 ( V_40 ) ;
return sprintf ( V_2 , L_3 , V_19 -> V_44 ) ;
}
static char * F_25 ( struct V_39 * V_40 , T_5 * V_45 )
{
* V_45 = V_46 | V_47 ;
return F_26 ( V_26 , L_4 , F_27 ( V_40 ) ) ;
}
static int F_28 ( struct V_18 * V_19 , int V_48 )
{
struct V_39 * V_40 ;
int V_49 = V_19 -> V_1 ;
F_29 ( & V_19 -> V_21 ) ;
if ( F_1 ( V_49 , & V_19 -> V_35 ,
V_50 , sizeof( V_19 -> V_35 ) ) < 0 )
return - V_12 ;
if ( F_1 ( V_49 , & V_19 -> V_43 ,
V_51 , sizeof( V_19 -> V_43 ) ) < 0 )
return - V_12 ;
if ( F_1 ( V_49 , & V_19 -> V_44 ,
V_52 , sizeof( V_19 -> V_44 ) ) < 0 )
return - V_12 ;
V_40 = F_30 ( V_53 , & V_54 ,
F_31 ( V_55 , V_48 ) , V_19 , L_5 , V_48 ) ;
return F_32 ( V_40 ) ? F_33 ( V_40 ) : 0 ;
}
static int F_34 ( void )
{
int V_56 , V_57 ;
T_6 V_40 = F_31 ( V_55 , 0 ) ;
V_17 = F_35 ( 4 * sizeof( struct V_18 ) , V_26 ) ;
for ( V_57 = 0 ; ; V_57 ++ ) {
int V_49 ;
char V_2 [ 20 ] ;
struct V_18 * V_58 =
F_36 ( V_17 , ( V_57 + 1 ) * sizeof( struct V_18 ) ,
V_26 | V_59 ) ;
if ( ! V_58 ) {
V_56 = - V_27 ;
goto V_60;
}
V_17 = V_58 ;
sprintf ( V_2 , L_6 , V_57 ) ;
V_49 = F_37 ( ( V_8 ) V_2 , 0 ) ;
if ( V_49 < 0 ) {
if ( V_49 != V_61 )
F_38 ( L_7 ,
V_57 , V_49 ) ;
break;
}
V_17 [ V_57 ] . V_1 = V_49 ;
}
V_62 = V_57 ;
if ( V_62 == 0 ) {
V_56 = - V_63 ;
goto V_60;
}
if ( V_55 )
V_56 = F_39 ( V_40 , V_62 , L_8 ) ;
else {
V_56 = F_40 ( & V_40 , 0 , V_62 , L_8 ) ;
V_55 = F_41 ( V_40 ) ;
}
if ( V_56 < 0 )
goto V_60;
F_42 ( & V_64 , & V_65 ) ;
V_64 . V_66 = V_67 ;
V_64 . V_68 = & V_65 ;
V_56 = F_43 ( & V_64 , V_40 , V_62 ) ;
if ( V_56 < 0 )
goto V_69;
V_53 = F_44 ( V_67 , L_8 ) ;
if ( F_32 ( V_53 ) ) {
V_56 = F_33 ( V_53 ) ;
goto V_70;
}
V_53 -> V_71 = V_72 ;
V_53 -> V_73 = F_25 ;
for ( V_57 = 0 ; V_57 < V_62 ; V_57 ++ ) {
V_56 = F_28 ( V_17 + V_57 , V_57 ) ;
if ( V_56 < 0 )
goto V_74;
}
return 0 ;
V_74:
for ( V_57 = 0 ; V_57 < V_62 ; V_57 ++ )
F_45 ( V_53 , F_31 ( V_55 , V_57 ) ) ;
F_46 ( V_53 ) ;
V_70:
F_47 ( & V_64 ) ;
V_69:
F_48 ( V_40 , V_62 ) ;
V_60:
F_15 ( V_17 ) ;
return V_56 ;
}
static void F_49 ( void )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_62 ; V_57 ++ )
F_45 ( V_53 , F_31 ( V_55 , V_57 ) ) ;
F_46 ( V_53 ) ;
F_47 ( & V_64 ) ;
F_48 ( F_31 ( V_55 , 0 ) , V_62 ) ;
F_15 ( V_17 ) ;
}
