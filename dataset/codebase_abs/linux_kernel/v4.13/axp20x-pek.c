static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_4 , V_3 ) -> V_5 ;
}
static T_1 F_3 ( struct V_6 * V_7 ,
struct V_2 * V_3 , char * V_8 )
{
struct V_9 * V_9 = F_4 ( V_7 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
unsigned int V_11 ;
int V_12 , V_13 ;
V_12 = F_5 ( V_9 -> V_14 -> V_15 , V_16 , & V_11 ) ;
if ( V_12 != 0 )
return V_12 ;
V_11 &= V_10 -> V_17 ;
V_11 >>= F_6 ( V_10 -> V_17 ) - 1 ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ )
if ( V_11 == V_10 -> V_18 [ V_13 ] . V_19 )
V_11 = V_10 -> V_18 [ V_13 ] . time ;
return sprintf ( V_8 , L_1 , V_11 ) ;
}
static T_1 F_7 ( struct V_6 * V_7 ,
struct V_2 * V_3 ,
const char * V_8 , T_2 V_20 )
{
struct V_9 * V_9 = F_4 ( V_7 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
char V_21 [ 20 ] ;
T_2 V_22 ;
int V_12 , V_13 ;
unsigned int V_11 , V_19 = 0 ;
unsigned int V_23 = V_24 ;
V_21 [ sizeof( V_21 ) - 1 ] = '\0' ;
strncpy ( V_21 , V_8 , sizeof( V_21 ) - 1 ) ;
V_22 = strlen ( V_21 ) ;
if ( V_22 && V_21 [ V_22 - 1 ] == '\n' )
V_21 [ V_22 - 1 ] = '\0' ;
V_12 = F_8 ( V_21 , 10 , & V_11 ) ;
if ( V_12 )
return V_12 ;
for ( V_13 = 3 ; V_13 >= 0 ; V_13 -- ) {
unsigned int V_25 ;
V_25 = abs ( V_10 -> V_18 [ V_13 ] . time - V_11 ) ;
if ( V_25 < V_23 ) {
V_23 = V_25 ;
V_19 = V_10 -> V_18 [ V_13 ] . V_19 ;
}
if ( ! V_25 )
break;
}
V_19 <<= F_6 ( V_10 -> V_17 ) - 1 ;
V_12 = F_9 ( V_9 -> V_14 -> V_15 ,
V_16 ,
V_10 -> V_17 , V_19 ) ;
if ( V_12 != 0 )
return - V_26 ;
return V_20 ;
}
static T_3 F_10 ( int V_27 , void * V_28 )
{
struct V_29 * V_30 = V_28 ;
struct V_9 * V_9 = F_11 ( V_30 ) ;
if ( V_27 == V_9 -> V_31 )
F_12 ( V_30 , V_32 , true ) ;
else if ( V_27 == V_9 -> V_33 )
F_12 ( V_30 , V_32 , false ) ;
F_13 ( V_30 ) ;
return V_34 ;
}
static void F_14 ( void * V_35 )
{
struct V_6 * V_7 = V_35 ;
F_15 ( & V_7 -> V_36 , & V_37 ) ;
}
static int F_16 ( struct V_9 * V_9 ,
struct V_38 * V_39 )
{
struct V_40 * V_14 = V_9 -> V_14 ;
struct V_29 * V_30 ;
int error ;
V_9 -> V_33 = F_17 ( V_39 , L_2 ) ;
if ( V_9 -> V_33 < 0 ) {
F_18 ( & V_39 -> V_7 , L_3 ,
V_9 -> V_33 ) ;
return V_9 -> V_33 ;
}
V_9 -> V_33 = F_19 ( V_14 -> V_41 ,
V_9 -> V_33 ) ;
V_9 -> V_31 = F_17 ( V_39 , L_4 ) ;
if ( V_9 -> V_31 < 0 ) {
F_18 ( & V_39 -> V_7 , L_5 ,
V_9 -> V_31 ) ;
return V_9 -> V_31 ;
}
V_9 -> V_31 = F_19 ( V_14 -> V_41 ,
V_9 -> V_31 ) ;
V_9 -> V_42 = F_20 ( & V_39 -> V_7 ) ;
if ( ! V_9 -> V_42 )
return - V_43 ;
V_30 = V_9 -> V_42 ;
V_30 -> V_44 = L_6 ;
V_30 -> V_45 = L_7 ;
V_30 -> V_7 . V_46 = & V_39 -> V_7 ;
F_21 ( V_30 , V_47 , V_32 ) ;
F_22 ( V_30 , V_9 ) ;
error = F_23 ( & V_39 -> V_7 , V_9 -> V_33 ,
F_10 , 0 ,
L_8 , V_30 ) ;
if ( error < 0 ) {
F_18 ( & V_39 -> V_7 , L_9 ,
V_9 -> V_33 , error ) ;
return error ;
}
error = F_23 ( & V_39 -> V_7 , V_9 -> V_31 ,
F_10 , 0 ,
L_10 , V_30 ) ;
if ( error < 0 ) {
F_18 ( & V_39 -> V_7 , L_11 ,
V_9 -> V_31 , error ) ;
return error ;
}
error = F_24 ( V_30 ) ;
if ( error ) {
F_18 ( & V_39 -> V_7 , L_12 ,
error ) ;
return error ;
}
if ( V_9 -> V_14 -> V_48 == V_49 )
F_25 ( V_9 -> V_33 ) ;
return 0 ;
}
static bool F_26 ( struct V_9 * V_9 ,
struct V_38 * V_39 )
{
unsigned long long V_50 = 0 ;
T_4 V_51 ;
if ( F_27 ( V_52 ) &&
V_9 -> V_14 -> V_48 == V_49 ) {
V_51 = F_28 ( F_29 ( V_39 -> V_7 . V_46 ) ,
L_13 , NULL , & V_50 ) ;
if ( F_30 ( V_51 ) )
F_18 ( & V_39 -> V_7 , L_14 ) ;
if ( V_50 == 3 && ( F_31 ( L_15 , NULL , - 1 ) ||
F_31 ( L_16 , NULL , - 1 ) ) )
return false ;
}
return true ;
}
static bool F_26 ( struct V_9 * V_9 ,
struct V_38 * V_39 )
{
return true ;
}
static int F_32 ( struct V_38 * V_39 )
{
struct V_9 * V_9 ;
int error ;
V_9 = F_33 ( & V_39 -> V_7 , sizeof( struct V_9 ) ,
V_53 ) ;
if ( ! V_9 )
return - V_43 ;
V_9 -> V_14 = F_4 ( V_39 -> V_7 . V_46 ) ;
if ( F_26 ( V_9 , V_39 ) ) {
error = F_16 ( V_9 , V_39 ) ;
if ( error )
return error ;
}
error = F_34 ( & V_39 -> V_7 . V_36 , & V_37 ) ;
if ( error ) {
F_18 ( & V_39 -> V_7 , L_17 ,
error ) ;
return error ;
}
error = F_35 ( & V_39 -> V_7 ,
F_14 , & V_39 -> V_7 ) ;
if ( error ) {
F_14 ( & V_39 -> V_7 ) ;
F_18 ( & V_39 -> V_7 , L_18 ,
error ) ;
return error ;
}
F_36 ( V_39 , V_9 ) ;
return 0 ;
}
static int T_5 F_37 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_4 ( V_7 ) ;
if ( V_9 -> V_14 -> V_48 != V_49 )
return 0 ;
F_38 ( V_9 -> V_14 -> V_15 ,
V_54 + V_55 / 8 ,
F_39 ( V_55 % 8 ) ) ;
return 0 ;
}
