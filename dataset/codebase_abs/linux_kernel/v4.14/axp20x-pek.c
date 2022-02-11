static T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * time ,
unsigned int V_4 , char * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
int V_8 , V_9 ;
V_8 = F_3 ( V_6 -> V_10 -> V_11 , V_12 , & V_7 ) ;
if ( V_8 != 0 )
return V_8 ;
V_7 &= V_4 ;
V_7 >>= F_4 ( V_4 ) - 1 ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ )
if ( V_7 == time [ V_9 ] . V_13 )
V_7 = time [ V_9 ] . time ;
return sprintf ( V_5 , L_1 , V_7 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
char * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
return F_1 ( V_2 , V_6 -> V_16 -> V_17 ,
V_6 -> V_16 -> V_18 , V_5 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
char * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
return F_1 ( V_2 , V_6 -> V_16 -> V_19 ,
V_6 -> V_16 -> V_20 , V_5 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
const struct V_3 * time ,
unsigned int V_4 , const char * V_5 ,
T_2 V_21 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
char V_22 [ 20 ] ;
T_2 V_23 ;
int V_8 , V_9 ;
unsigned int V_7 , V_13 = 0 ;
unsigned int V_24 = V_25 ;
V_22 [ sizeof( V_22 ) - 1 ] = '\0' ;
strncpy ( V_22 , V_5 , sizeof( V_22 ) - 1 ) ;
V_23 = strlen ( V_22 ) ;
if ( V_23 && V_22 [ V_23 - 1 ] == '\n' )
V_22 [ V_23 - 1 ] = '\0' ;
V_8 = F_8 ( V_22 , 10 , & V_7 ) ;
if ( V_8 )
return V_8 ;
for ( V_9 = 3 ; V_9 >= 0 ; V_9 -- ) {
unsigned int V_26 ;
V_26 = abs ( time [ V_9 ] . time - V_7 ) ;
if ( V_26 < V_24 ) {
V_24 = V_26 ;
V_13 = time [ V_9 ] . V_13 ;
}
if ( ! V_26 )
break;
}
V_13 <<= F_4 ( V_4 ) - 1 ;
V_8 = F_9 ( V_6 -> V_10 -> V_11 , V_12 ,
V_4 , V_13 ) ;
if ( V_8 != 0 )
return - V_27 ;
return V_21 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
const char * V_5 , T_2 V_21 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
return F_7 ( V_2 , V_6 -> V_16 -> V_17 ,
V_6 -> V_16 -> V_18 , V_5 , V_21 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
const char * V_5 , T_2 V_21 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
return F_7 ( V_2 , V_6 -> V_16 -> V_19 ,
V_6 -> V_16 -> V_20 , V_5 , V_21 ) ;
}
static T_3 F_12 ( int V_28 , void * V_29 )
{
struct V_30 * V_31 = V_29 ;
struct V_6 * V_6 = F_13 ( V_31 ) ;
if ( V_28 == V_6 -> V_32 )
F_14 ( V_31 , V_33 , true ) ;
else if ( V_28 == V_6 -> V_34 )
F_14 ( V_31 , V_33 , false ) ;
F_15 ( V_31 ) ;
return V_35 ;
}
static int F_16 ( struct V_6 * V_6 ,
struct V_36 * V_37 )
{
struct V_38 * V_10 = V_6 -> V_10 ;
struct V_30 * V_31 ;
int error ;
V_6 -> V_34 = F_17 ( V_37 , L_2 ) ;
if ( V_6 -> V_34 < 0 ) {
F_18 ( & V_37 -> V_2 , L_3 ,
V_6 -> V_34 ) ;
return V_6 -> V_34 ;
}
V_6 -> V_34 = F_19 ( V_10 -> V_39 ,
V_6 -> V_34 ) ;
V_6 -> V_32 = F_17 ( V_37 , L_4 ) ;
if ( V_6 -> V_32 < 0 ) {
F_18 ( & V_37 -> V_2 , L_5 ,
V_6 -> V_32 ) ;
return V_6 -> V_32 ;
}
V_6 -> V_32 = F_19 ( V_10 -> V_39 ,
V_6 -> V_32 ) ;
V_6 -> V_40 = F_20 ( & V_37 -> V_2 ) ;
if ( ! V_6 -> V_40 )
return - V_41 ;
V_31 = V_6 -> V_40 ;
V_31 -> V_42 = L_6 ;
V_31 -> V_43 = L_7 ;
V_31 -> V_2 . V_44 = & V_37 -> V_2 ;
F_21 ( V_31 , V_45 , V_33 ) ;
F_22 ( V_31 , V_6 ) ;
error = F_23 ( & V_37 -> V_2 , V_6 -> V_34 ,
F_12 , 0 ,
L_8 , V_31 ) ;
if ( error < 0 ) {
F_18 ( & V_37 -> V_2 , L_9 ,
V_6 -> V_34 , error ) ;
return error ;
}
error = F_23 ( & V_37 -> V_2 , V_6 -> V_32 ,
F_12 , 0 ,
L_10 , V_31 ) ;
if ( error < 0 ) {
F_18 ( & V_37 -> V_2 , L_11 ,
V_6 -> V_32 , error ) ;
return error ;
}
error = F_24 ( V_31 ) ;
if ( error ) {
F_18 ( & V_37 -> V_2 , L_12 ,
error ) ;
return error ;
}
if ( V_6 -> V_10 -> V_46 == V_47 )
F_25 ( V_6 -> V_34 ) ;
return 0 ;
}
static bool F_26 ( struct V_6 * V_6 ,
struct V_36 * V_37 )
{
unsigned long long V_48 = 0 ;
T_4 V_49 ;
if ( F_27 ( V_50 ) &&
V_6 -> V_10 -> V_46 == V_47 ) {
V_49 = F_28 ( F_29 ( V_37 -> V_2 . V_44 ) ,
L_13 , NULL , & V_48 ) ;
if ( F_30 ( V_49 ) )
F_18 ( & V_37 -> V_2 , L_14 ) ;
if ( V_48 == 3 && ( F_31 ( L_15 , NULL , - 1 ) ||
F_31 ( L_16 , NULL , - 1 ) ) )
return false ;
}
return true ;
}
static bool F_26 ( struct V_6 * V_6 ,
struct V_36 * V_37 )
{
return true ;
}
static int F_32 ( struct V_36 * V_37 )
{
struct V_6 * V_6 ;
const struct V_51 * V_52 = F_33 ( V_37 ) ;
int error ;
if ( ! V_52 ) {
F_18 ( & V_37 -> V_2 , L_17 ) ;
return - V_27 ;
}
V_6 = F_34 ( & V_37 -> V_2 , sizeof( struct V_6 ) ,
V_53 ) ;
if ( ! V_6 )
return - V_41 ;
V_6 -> V_10 = F_2 ( V_37 -> V_2 . V_44 ) ;
if ( F_26 ( V_6 , V_37 ) ) {
error = F_16 ( V_6 , V_37 ) ;
if ( error )
return error ;
}
V_6 -> V_16 = (struct V_54 * ) V_52 -> V_55 ;
error = F_35 ( & V_37 -> V_2 , & V_56 ) ;
if ( error ) {
F_18 ( & V_37 -> V_2 , L_18 ,
error ) ;
return error ;
}
F_36 ( V_37 , V_6 ) ;
return 0 ;
}
static int T_5 F_37 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_10 -> V_46 != V_47 )
return 0 ;
F_38 ( V_6 -> V_10 -> V_11 ,
V_57 + V_58 / 8 ,
F_39 ( V_58 % 8 ) ) ;
return 0 ;
}
