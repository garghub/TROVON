static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
if ( V_3 >= V_6 ) {
F_2 ( V_2 -> V_7 , L_1 , V_3 ) ;
return - V_8 ;
}
if ( ! V_2 -> V_9 [ V_3 ] . V_10 ) {
* V_4 = V_2 -> V_9 [ V_3 ] . V_11 ;
goto V_12;
}
V_5 = F_3 ( V_2 -> V_13 , & V_3 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != 1 )
return - V_14 ;
V_5 = F_4 ( V_2 -> V_13 , V_4 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != 1 )
return - V_14 ;
V_12:
F_5 ( V_2 -> V_7 , L_2 , V_3 , * V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_15 [ 2 ] ;
int V_5 ;
if ( V_3 >= V_6 ) {
F_2 ( V_2 -> V_7 , L_1 , V_3 ) ;
return - V_8 ;
}
if ( ! V_2 -> V_9 [ V_3 ] . V_16 ) {
F_2 ( V_2 -> V_7 , L_3 ,
V_3 ) ;
return - V_8 ;
}
V_15 [ 0 ] = V_3 ;
V_15 [ 1 ] = V_4 ;
V_5 = F_3 ( V_2 -> V_13 , V_15 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != 2 )
return - V_14 ;
V_2 -> V_9 [ V_3 ] . V_11 = V_4 ;
F_5 ( V_2 -> V_7 , L_4 , V_3 , V_4 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
F_8 ( & V_2 -> V_17 ) ;
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
F_9 ( & V_2 -> V_17 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
F_8 ( & V_2 -> V_17 ) ;
V_5 = F_6 ( V_2 , V_3 , V_4 ) ;
F_9 ( & V_2 -> V_17 ) ;
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_18 ,
T_1 V_4 )
{
int V_19 ;
T_1 V_20 , V_21 ;
int V_5 ;
F_8 ( & V_2 -> V_17 ) ;
V_5 = F_1 ( V_2 , V_3 , & V_20 ) ;
if ( V_5 )
goto V_22;
V_21 = ( V_20 & ~ V_18 ) | ( V_4 & V_18 ) ;
V_19 = V_20 != V_21 ;
if ( V_19 )
V_5 = F_6 ( V_2 , V_3 , V_21 ) ;
V_22:
F_9 ( & V_2 -> V_17 ) ;
return V_5 ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 >= 0 )
F_13 ( V_2 -> V_23 , 1 ) ;
V_2 -> V_24 = 1 ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 >= 0 )
F_13 ( V_2 -> V_23 , 0 ) ;
V_2 -> V_24 = 0 ;
}
static T_2 F_15 ( struct V_1 * V_2 , char * V_25 )
{
T_1 V_3 , V_4 ;
T_2 V_26 = 0 ;
int V_5 ;
V_26 += sprintf ( V_25 , L_5 ) ;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
V_26 += sprintf ( V_25 + V_26 , L_6 , V_3 ) ;
if ( V_26 >= V_27 - 1 )
break;
V_5 = V_2 -> V_28 ( V_2 , V_3 , & V_4 ) ;
if ( V_5 == 0 )
V_26 += snprintf ( V_25 + V_26 , V_27 - V_26 ,
L_7 , V_4 ) ;
else
V_26 += snprintf ( V_25 + V_26 , V_27 - V_26 ,
L_8 , V_5 ) ;
if ( V_26 >= V_27 - 1 )
break;
V_26 += snprintf ( V_25 + V_26 , V_27 - V_26 , L_9 ) ;
if ( V_26 >= V_27 - 1 )
break;
}
if ( V_26 >= V_27 )
V_26 = V_27 - 1 ;
return V_26 ;
}
static T_2 F_16 ( struct V_29 * V_29 , char T_3 * V_30 ,
T_4 V_26 , T_5 * V_31 )
{
struct V_1 * V_2 = V_29 -> V_32 ;
char * V_25 ;
T_2 V_5 ;
V_25 = F_17 ( V_27 , V_33 ) ;
if ( ! V_25 )
return - V_34 ;
V_5 = F_15 ( V_2 , V_25 ) ;
if ( V_5 >= 0 )
V_5 = F_18 ( V_30 , V_26 , V_31 , V_25 , V_5 ) ;
F_19 ( V_25 ) ;
return V_5 ;
}
static T_2 F_20 ( struct V_29 * V_29 ,
const char T_3 * V_30 , T_4 V_26 ,
T_5 * V_31 )
{
struct V_1 * V_2 = V_29 -> V_32 ;
char V_25 [ 32 ] ;
T_2 V_35 ;
char * V_36 = V_25 ;
unsigned long V_3 , V_4 ;
int V_5 ;
V_35 = F_21 ( V_26 , ( sizeof( V_25 ) - 1 ) ) ;
if ( F_22 ( V_25 , V_30 , V_35 ) ) {
F_2 ( V_2 -> V_7 , L_10 ) ;
return - V_37 ;
}
V_25 [ V_35 ] = 0 ;
while ( * V_36 == ' ' )
V_36 ++ ;
V_3 = F_23 ( V_36 , & V_36 , 16 ) ;
if ( V_3 >= V_6 ) {
F_2 ( V_2 -> V_7 , L_11 , V_3 ) ;
return - V_8 ;
}
while ( * V_36 == ' ' )
V_36 ++ ;
if ( F_24 ( V_36 , 16 , & V_4 ) )
return - V_8 ;
V_5 = V_2 -> V_38 ( V_2 , ( T_1 ) V_3 , ( T_1 ) V_4 ) ;
if ( V_5 )
return V_5 ;
return V_35 ;
}
static void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_39 = F_26 ( L_12 , NULL ) ;
if ( ! V_2 -> V_39 ) {
F_27 ( V_2 -> V_7 ,
L_13 ) ;
return;
}
V_2 -> V_40 = F_28 ( L_14 , 0644 ,
V_2 -> V_39 ,
V_2 , & V_41 ) ;
if ( ! V_2 -> V_40 )
F_27 ( V_2 -> V_7 ,
L_15 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 -> V_39 ) ;
}
static inline void F_25 ( struct V_1 * V_2 )
{
}
static inline void F_29 ( struct V_1 * V_2 )
{
}
static int F_31 ( struct V_42 * V_13 ,
const struct V_43 * V_44 )
{
struct V_45 * V_46 = V_13 -> V_7 . V_47 ;
struct V_1 * V_2 ;
int V_48 , V_49 ;
int V_5 = 0 ;
V_2 = F_32 ( sizeof( struct V_1 ) , V_33 ) ;
if ( ! V_2 ) {
F_2 ( & V_13 -> V_7 ,
L_16 ) ;
V_5 = - V_34 ;
goto V_12;
}
V_2 -> V_7 = & V_13 -> V_7 ;
F_33 ( V_2 -> V_7 , V_2 ) ;
V_2 -> V_13 = V_13 ;
F_34 ( V_13 , V_2 ) ;
V_2 -> V_9 = V_50 ;
if ( V_46 -> V_23 < 0 )
V_2 -> V_23 = - 1 ;
else
V_2 -> V_23 = V_46 -> V_23 ;
V_2 -> V_51 = V_46 -> V_51 ;
V_2 -> V_52 = V_46 -> V_52 ;
V_2 -> V_28 = F_7 ;
V_2 -> V_38 = F_10 ;
V_2 -> V_53 = F_11 ;
F_35 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_51 )
V_2 -> V_51 ( V_2 ) ;
if ( V_2 -> V_23 >= 0 ) {
V_5 = F_36 ( V_2 -> V_23 , V_54 ,
L_17 ) ;
if ( V_5 < 0 ) {
F_2 ( & V_13 -> V_7 ,
L_18 , V_2 -> V_23 ) ;
goto V_55;
}
}
F_12 ( V_2 ) ;
for ( V_48 = 0 ; V_48 < V_46 -> V_56 ; V_48 ++ ) {
for ( V_49 = 0 ; V_49 < F_37 ( V_57 ) ; V_49 ++ ) {
if ( ( V_46 -> V_58 [ V_48 ] . V_44 == V_57 [ V_49 ] . V_44 ) &&
! strcmp ( V_46 -> V_58 [ V_48 ] . V_59 ,
V_57 [ V_49 ] . V_59 ) ) {
V_57 [ V_49 ] . V_47 =
V_46 -> V_58 [ V_48 ] . V_47 ;
break;
}
}
}
V_5 = F_38 ( V_2 -> V_7 , 0 , V_57 ,
F_37 ( V_57 ) , NULL , 0 ) ;
if ( V_5 != 0 ) {
F_2 ( V_2 -> V_7 , L_19 , V_5 ) ;
goto V_60;
}
F_25 ( V_2 ) ;
return 0 ;
V_60:
F_14 ( V_2 ) ;
if ( V_2 -> V_23 >= 0 )
F_39 ( V_2 -> V_23 ) ;
V_55:
F_19 ( V_2 ) ;
V_12:
return V_5 ;
}
static int F_40 ( struct V_42 * V_13 )
{
struct V_1 * V_2 = F_41 ( V_13 ) ;
F_29 ( V_2 ) ;
F_42 ( V_2 -> V_7 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_23 >= 0 )
F_39 ( V_2 -> V_23 ) ;
if ( V_2 -> V_52 )
V_2 -> V_52 ( V_2 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_61 * V_7 )
{
struct V_42 * V_13 = F_44 ( V_7 ) ;
struct V_1 * V_2 = F_41 ( V_13 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_61 * V_7 )
{
struct V_42 * V_13 = F_44 ( V_7 ) ;
struct V_1 * V_2 = F_41 ( V_13 ) ;
struct V_62 * V_63 = NULL ;
int V_48 ;
F_12 ( V_2 ) ;
for ( V_48 = 0 ; V_48 < V_6 ; V_48 ++ ) {
V_63 = & V_2 -> V_9 [ V_48 ] ;
if ( V_63 -> V_16 )
V_2 -> V_38 ( V_2 , V_48 , V_63 -> V_11 ) ;
}
return 0 ;
}
static int T_6 F_46 ( void )
{
return F_47 ( & V_64 ) ;
}
static void T_7 F_48 ( void )
{
F_49 ( & V_64 ) ;
}
