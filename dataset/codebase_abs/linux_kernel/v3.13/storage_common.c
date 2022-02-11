void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
F_2 ( V_2 , L_1 ) ;
F_3 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
}
int F_4 ( struct V_1 * V_2 , const char * V_4 )
{
int V_5 ;
struct V_6 * V_3 = NULL ;
int V_7 = - V_8 ;
struct V_9 * V_9 = NULL ;
T_1 V_10 ;
T_1 V_11 ;
T_1 V_12 ;
unsigned int V_13 ;
unsigned int V_14 ;
V_5 = V_2 -> V_15 ;
if ( ! V_5 ) {
V_3 = F_5 ( V_4 , V_16 | V_17 , 0 ) ;
if ( F_6 ( V_3 ) == - V_18 || F_6 ( V_3 ) == - V_19 )
V_5 = 1 ;
}
if ( V_5 )
V_3 = F_5 ( V_4 , V_20 | V_17 , 0 ) ;
if ( F_7 ( V_3 ) ) {
F_8 ( V_2 , L_2 , V_4 ) ;
return F_6 ( V_3 ) ;
}
if ( ! ( V_3 -> V_21 & V_22 ) )
V_5 = 1 ;
V_9 = F_9 ( V_3 ) ;
if ( ( ! F_10 ( V_9 -> V_23 ) && ! F_11 ( V_9 -> V_23 ) ) ) {
F_8 ( V_2 , L_3 , V_4 ) ;
goto V_24;
}
if ( ! ( V_3 -> V_25 -> V_26 || V_3 -> V_25 -> V_27 ) ) {
F_8 ( V_2 , L_4 , V_4 ) ;
goto V_24;
}
if ( ! ( V_3 -> V_25 -> V_28 || V_3 -> V_25 -> V_29 ) )
V_5 = 1 ;
V_10 = F_12 ( V_9 -> V_30 -> V_31 ) ;
if ( V_10 < 0 ) {
F_8 ( V_2 , L_5 , V_4 ) ;
V_7 = ( int ) V_10 ;
goto V_24;
}
if ( V_2 -> V_32 ) {
V_14 = 2048 ;
V_13 = 11 ;
} else if ( V_9 -> V_33 ) {
V_14 = F_13 ( V_9 -> V_33 ) ;
V_13 = F_14 ( V_14 ) ;
} else {
V_14 = 512 ;
V_13 = 9 ;
}
V_11 = V_10 >> V_13 ;
V_12 = 1 ;
if ( V_2 -> V_32 ) {
V_12 = 300 ;
if ( V_11 >= 256 * 60 * 75 ) {
V_11 = 256 * 60 * 75 - 1 ;
F_8 ( V_2 , L_6 , V_4 ) ;
F_8 ( V_2 , L_7 ,
( int ) V_11 ) ;
}
}
if ( V_11 < V_12 ) {
F_8 ( V_2 , L_8 , V_4 ) ;
V_7 = - V_34 ;
goto V_24;
}
if ( F_15 ( V_2 ) )
F_1 ( V_2 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_35 = V_10 ;
V_2 -> V_11 = V_11 ;
F_2 ( V_2 , L_9 , V_4 ) ;
return 0 ;
V_24:
F_3 ( V_3 ) ;
return V_7 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_3 = V_2 -> V_3 ;
if ( V_2 -> V_5 || ! V_3 )
return 0 ;
return F_17 ( V_3 , 1 ) ;
}
void F_18 ( T_2 * V_36 , int V_37 , T_3 V_38 )
{
if ( V_37 ) {
V_38 >>= 2 ;
V_38 += 2 * 75 ;
V_36 [ 3 ] = V_38 % 75 ;
V_38 /= 75 ;
V_36 [ 2 ] = V_38 % 60 ;
V_38 /= 60 ;
V_36 [ 1 ] = V_38 ;
V_36 [ 0 ] = 0 ;
} else {
F_19 ( V_38 , V_36 ) ;
}
}
T_4 F_20 ( struct V_1 * V_2 , char * V_39 )
{
return sprintf ( V_39 , L_10 , F_15 ( V_2 )
? V_2 -> V_5
: V_2 -> V_15 ) ;
}
T_4 F_21 ( struct V_1 * V_2 , char * V_39 )
{
return sprintf ( V_39 , L_11 , V_2 -> V_40 ) ;
}
T_4 F_22 ( struct V_1 * V_2 , struct V_41 * V_42 ,
char * V_39 )
{
char * V_43 ;
T_4 V_7 ;
F_23 ( V_42 ) ;
if ( F_15 ( V_2 ) ) {
V_43 = F_24 ( & V_2 -> V_3 -> V_44 , V_39 , V_45 - 1 ) ;
if ( F_7 ( V_43 ) )
V_7 = F_6 ( V_43 ) ;
else {
V_7 = strlen ( V_43 ) ;
memmove ( V_39 , V_43 , V_7 ) ;
V_39 [ V_7 ] = '\n' ;
V_39 [ ++ V_7 ] = 0 ;
}
} else {
* V_39 = 0 ;
V_7 = 0 ;
}
F_25 ( V_42 ) ;
return V_7 ;
}
T_4 F_26 ( struct V_1 * V_2 , char * V_39 )
{
return sprintf ( V_39 , L_11 , V_2 -> V_32 ) ;
}
T_4 F_27 ( struct V_1 * V_2 , char * V_39 )
{
return sprintf ( V_39 , L_11 , V_2 -> V_46 ) ;
}
static T_4 F_28 ( struct V_1 * V_2 , bool V_5 )
{
if ( F_15 ( V_2 ) ) {
F_2 ( V_2 , L_12 ) ;
return - V_47 ;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_15 = V_5 ;
F_2 ( V_2 , L_13 , V_2 -> V_5 ) ;
return 0 ;
}
T_4 F_29 ( struct V_1 * V_2 , struct V_41 * V_42 ,
const char * V_39 , T_5 V_48 )
{
T_4 V_7 ;
bool V_5 ;
V_7 = F_30 ( V_39 , & V_5 ) ;
if ( V_7 )
return V_7 ;
F_23 ( V_42 ) ;
V_7 = F_28 ( V_2 , V_5 ) ;
if ( ! V_7 )
V_7 = V_48 ;
F_25 ( V_42 ) ;
return V_7 ;
}
T_4 F_31 ( struct V_1 * V_2 , const char * V_39 , T_5 V_48 )
{
bool V_40 ;
int V_49 ;
V_49 = F_30 ( V_39 , & V_40 ) ;
if ( V_49 )
return V_49 ;
if ( ! V_40 && V_2 -> V_40 )
F_16 ( V_2 ) ;
V_2 -> V_40 = V_40 ;
return V_48 ;
}
T_4 F_32 ( struct V_1 * V_2 , struct V_41 * V_42 ,
const char * V_39 , T_5 V_48 )
{
int V_7 = 0 ;
if ( V_2 -> V_50 && F_15 ( V_2 ) ) {
F_2 ( V_2 , L_14 ) ;
return - V_47 ;
}
if ( V_48 > 0 && V_39 [ V_48 - 1 ] == '\n' )
( ( char * ) V_39 ) [ V_48 - 1 ] = 0 ;
F_33 ( V_42 ) ;
if ( V_48 > 0 && V_39 [ 0 ] ) {
V_7 = F_4 ( V_2 , V_39 ) ;
if ( V_7 == 0 )
V_2 -> V_51 =
V_52 ;
} else if ( F_15 ( V_2 ) ) {
F_1 ( V_2 ) ;
V_2 -> V_51 = V_53 ;
}
F_34 ( V_42 ) ;
return ( V_7 < 0 ? V_7 : V_48 ) ;
}
T_4 F_35 ( struct V_1 * V_2 , struct V_41 * V_42 ,
const char * V_39 , T_5 V_48 )
{
bool V_32 ;
int V_49 ;
V_49 = F_30 ( V_39 , & V_32 ) ;
if ( V_49 )
return V_49 ;
F_23 ( V_42 ) ;
V_49 = V_32 ? F_28 ( V_2 , true ) : 0 ;
if ( ! V_49 ) {
V_2 -> V_32 = V_32 ;
V_49 = V_48 ;
}
F_25 ( V_42 ) ;
return V_49 ;
}
T_4 F_36 ( struct V_1 * V_2 , const char * V_39 ,
T_5 V_48 )
{
bool V_46 ;
int V_49 ;
V_49 = F_30 ( V_39 , & V_46 ) ;
if ( V_49 )
return V_49 ;
V_2 -> V_46 = V_46 ;
return V_48 ;
}
