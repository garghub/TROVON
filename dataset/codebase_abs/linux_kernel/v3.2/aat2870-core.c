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
static int F_16 ( struct V_29 * V_29 , struct V_30 * V_30 )
{
V_30 -> V_31 = V_29 -> V_32 ;
return 0 ;
}
static T_2 F_17 ( struct V_30 * V_30 , char T_3 * V_33 ,
T_4 V_26 , T_5 * V_34 )
{
struct V_1 * V_2 = V_30 -> V_31 ;
char * V_25 ;
T_2 V_5 ;
V_25 = F_18 ( V_27 , V_35 ) ;
if ( ! V_25 )
return - V_36 ;
V_5 = F_15 ( V_2 , V_25 ) ;
if ( V_5 >= 0 )
V_5 = F_19 ( V_33 , V_26 , V_34 , V_25 , V_5 ) ;
F_20 ( V_25 ) ;
return V_5 ;
}
static T_2 F_21 ( struct V_30 * V_30 ,
const char T_3 * V_33 , T_4 V_26 ,
T_5 * V_34 )
{
struct V_1 * V_2 = V_30 -> V_31 ;
char V_25 [ 32 ] ;
T_2 V_37 ;
char * V_38 = V_25 ;
unsigned long V_3 , V_4 ;
int V_5 ;
V_37 = F_22 ( V_26 , ( sizeof( V_25 ) - 1 ) ) ;
if ( F_23 ( V_25 , V_33 , V_37 ) ) {
F_2 ( V_2 -> V_7 , L_10 ) ;
return - V_39 ;
}
V_25 [ V_37 ] = 0 ;
while ( * V_38 == ' ' )
V_38 ++ ;
V_3 = F_24 ( V_38 , & V_38 , 16 ) ;
if ( V_3 >= V_6 ) {
F_2 ( V_2 -> V_7 , L_11 , V_3 ) ;
return - V_8 ;
}
while ( * V_38 == ' ' )
V_38 ++ ;
if ( F_25 ( V_38 , 16 , & V_4 ) )
return - V_8 ;
V_5 = V_2 -> V_40 ( V_2 , ( T_1 ) V_3 , ( T_1 ) V_4 ) ;
if ( V_5 )
return V_5 ;
return V_37 ;
}
static void F_26 ( struct V_1 * V_2 )
{
V_2 -> V_41 = F_27 ( L_12 , NULL ) ;
if ( ! V_2 -> V_41 ) {
F_28 ( V_2 -> V_7 ,
L_13 ) ;
return;
}
V_2 -> V_42 = F_29 ( L_14 , 0644 ,
V_2 -> V_41 ,
V_2 , & V_43 ) ;
if ( ! V_2 -> V_42 )
F_28 ( V_2 -> V_7 ,
L_15 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_31 ( V_2 -> V_41 ) ;
}
static inline void F_26 ( struct V_1 * V_2 )
{
}
static inline void F_30 ( struct V_1 * V_2 )
{
}
static int F_32 ( struct V_44 * V_13 ,
const struct V_45 * V_46 )
{
struct V_47 * V_48 = V_13 -> V_7 . V_49 ;
struct V_1 * V_2 ;
int V_50 , V_51 ;
int V_5 = 0 ;
V_2 = F_33 ( sizeof( struct V_1 ) , V_35 ) ;
if ( ! V_2 ) {
F_2 ( & V_13 -> V_7 ,
L_16 ) ;
V_5 = - V_36 ;
goto V_12;
}
V_2 -> V_7 = & V_13 -> V_7 ;
F_34 ( V_2 -> V_7 , V_2 ) ;
V_2 -> V_13 = V_13 ;
F_35 ( V_13 , V_2 ) ;
V_2 -> V_9 = V_52 ;
if ( V_48 -> V_23 < 0 )
V_2 -> V_23 = - 1 ;
else
V_2 -> V_23 = V_48 -> V_23 ;
V_2 -> V_53 = V_48 -> V_53 ;
V_2 -> V_54 = V_48 -> V_54 ;
V_2 -> V_28 = F_7 ;
V_2 -> V_40 = F_10 ;
V_2 -> V_55 = F_11 ;
F_36 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_53 )
V_2 -> V_53 ( V_2 ) ;
if ( V_2 -> V_23 >= 0 ) {
V_5 = F_37 ( V_2 -> V_23 , L_17 ) ;
if ( V_5 < 0 ) {
F_2 ( & V_13 -> V_7 ,
L_18 , V_2 -> V_23 ) ;
goto V_56;
}
F_38 ( V_2 -> V_23 , 1 ) ;
}
F_12 ( V_2 ) ;
for ( V_50 = 0 ; V_50 < V_48 -> V_57 ; V_50 ++ ) {
for ( V_51 = 0 ; V_51 < F_39 ( V_58 ) ; V_51 ++ ) {
if ( ( V_48 -> V_59 [ V_50 ] . V_46 == V_58 [ V_51 ] . V_46 ) &&
! strcmp ( V_48 -> V_59 [ V_50 ] . V_60 ,
V_58 [ V_51 ] . V_60 ) ) {
V_58 [ V_51 ] . V_49 =
V_48 -> V_59 [ V_50 ] . V_49 ;
break;
}
}
}
V_5 = F_40 ( V_2 -> V_7 , 0 , V_58 ,
F_39 ( V_58 ) , NULL , 0 ) ;
if ( V_5 != 0 ) {
F_2 ( V_2 -> V_7 , L_19 , V_5 ) ;
goto V_61;
}
F_26 ( V_2 ) ;
return 0 ;
V_61:
F_14 ( V_2 ) ;
if ( V_2 -> V_23 >= 0 )
F_41 ( V_2 -> V_23 ) ;
V_56:
F_20 ( V_2 ) ;
V_12:
return V_5 ;
}
static int F_42 ( struct V_44 * V_13 )
{
struct V_1 * V_2 = F_43 ( V_13 ) ;
F_30 ( V_2 ) ;
F_44 ( V_2 -> V_7 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_23 >= 0 )
F_41 ( V_2 -> V_23 ) ;
if ( V_2 -> V_54 )
V_2 -> V_54 ( V_2 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_44 * V_13 , T_6 V_62 )
{
struct V_1 * V_2 = F_43 ( V_13 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_44 * V_13 )
{
struct V_1 * V_2 = F_43 ( V_13 ) ;
struct V_63 * V_64 = NULL ;
int V_50 ;
F_12 ( V_2 ) ;
for ( V_50 = 0 ; V_50 < V_6 ; V_50 ++ ) {
V_64 = & V_2 -> V_9 [ V_50 ] ;
if ( V_64 -> V_16 )
V_2 -> V_40 ( V_2 , V_50 , V_64 -> V_11 ) ;
}
return 0 ;
}
static int T_7 F_47 ( void )
{
return F_48 ( & V_65 ) ;
}
static void T_8 F_49 ( void )
{
F_50 ( & V_65 ) ;
}
