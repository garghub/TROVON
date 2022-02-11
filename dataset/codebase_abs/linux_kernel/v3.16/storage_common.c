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
if ( ! ( V_3 -> V_21 & V_25 ) ) {
F_8 ( V_2 , L_4 , V_4 ) ;
goto V_24;
}
if ( ! ( V_3 -> V_21 & V_26 ) )
V_5 = 1 ;
V_10 = F_12 ( V_9 -> V_27 -> V_28 ) ;
if ( V_10 < 0 ) {
F_8 ( V_2 , L_5 , V_4 ) ;
V_7 = ( int ) V_10 ;
goto V_24;
}
if ( V_2 -> V_29 ) {
V_14 = 2048 ;
V_13 = 11 ;
} else if ( V_9 -> V_30 ) {
V_14 = F_13 ( V_9 -> V_30 ) ;
V_13 = F_14 ( V_14 ) ;
} else {
V_14 = 512 ;
V_13 = 9 ;
}
V_11 = V_10 >> V_13 ;
V_12 = 1 ;
if ( V_2 -> V_29 ) {
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
V_7 = - V_31 ;
goto V_24;
}
if ( F_15 ( V_2 ) )
F_1 ( V_2 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_32 = V_10 ;
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
void F_18 ( T_2 * V_33 , int V_34 , T_3 V_35 )
{
if ( V_34 ) {
V_35 >>= 2 ;
V_35 += 2 * 75 ;
V_33 [ 3 ] = V_35 % 75 ;
V_35 /= 75 ;
V_33 [ 2 ] = V_35 % 60 ;
V_35 /= 60 ;
V_33 [ 1 ] = V_35 ;
V_33 [ 0 ] = 0 ;
} else {
F_19 ( V_35 , V_33 ) ;
}
}
T_4 F_20 ( struct V_1 * V_2 , char * V_36 )
{
return sprintf ( V_36 , L_10 , F_15 ( V_2 )
? V_2 -> V_5
: V_2 -> V_15 ) ;
}
T_4 F_21 ( struct V_1 * V_2 , char * V_36 )
{
return sprintf ( V_36 , L_11 , V_2 -> V_37 ) ;
}
T_4 F_22 ( struct V_1 * V_2 , struct V_38 * V_39 ,
char * V_36 )
{
char * V_40 ;
T_4 V_7 ;
F_23 ( V_39 ) ;
if ( F_15 ( V_2 ) ) {
V_40 = F_24 ( & V_2 -> V_3 -> V_41 , V_36 , V_42 - 1 ) ;
if ( F_7 ( V_40 ) )
V_7 = F_6 ( V_40 ) ;
else {
V_7 = strlen ( V_40 ) ;
memmove ( V_36 , V_40 , V_7 ) ;
V_36 [ V_7 ] = '\n' ;
V_36 [ ++ V_7 ] = 0 ;
}
} else {
* V_36 = 0 ;
V_7 = 0 ;
}
F_25 ( V_39 ) ;
return V_7 ;
}
T_4 F_26 ( struct V_1 * V_2 , char * V_36 )
{
return sprintf ( V_36 , L_11 , V_2 -> V_29 ) ;
}
T_4 F_27 ( struct V_1 * V_2 , char * V_36 )
{
return sprintf ( V_36 , L_11 , V_2 -> V_43 ) ;
}
static T_4 F_28 ( struct V_1 * V_2 , bool V_5 )
{
if ( F_15 ( V_2 ) ) {
F_2 ( V_2 , L_12 ) ;
return - V_44 ;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_15 = V_5 ;
F_2 ( V_2 , L_13 , V_2 -> V_5 ) ;
return 0 ;
}
T_4 F_29 ( struct V_1 * V_2 , struct V_38 * V_39 ,
const char * V_36 , T_5 V_45 )
{
T_4 V_7 ;
bool V_5 ;
V_7 = F_30 ( V_36 , & V_5 ) ;
if ( V_7 )
return V_7 ;
F_23 ( V_39 ) ;
V_7 = F_28 ( V_2 , V_5 ) ;
if ( ! V_7 )
V_7 = V_45 ;
F_25 ( V_39 ) ;
return V_7 ;
}
T_4 F_31 ( struct V_1 * V_2 , const char * V_36 , T_5 V_45 )
{
bool V_37 ;
int V_46 ;
V_46 = F_30 ( V_36 , & V_37 ) ;
if ( V_46 )
return V_46 ;
if ( ! V_37 && V_2 -> V_37 )
F_16 ( V_2 ) ;
V_2 -> V_37 = V_37 ;
return V_45 ;
}
T_4 F_32 ( struct V_1 * V_2 , struct V_38 * V_39 ,
const char * V_36 , T_5 V_45 )
{
int V_7 = 0 ;
if ( V_2 -> V_47 && F_15 ( V_2 ) ) {
F_2 ( V_2 , L_14 ) ;
return - V_44 ;
}
if ( V_45 > 0 && V_36 [ V_45 - 1 ] == '\n' )
( ( char * ) V_36 ) [ V_45 - 1 ] = 0 ;
F_33 ( V_39 ) ;
if ( V_45 > 0 && V_36 [ 0 ] ) {
V_7 = F_4 ( V_2 , V_36 ) ;
if ( V_7 == 0 )
V_2 -> V_48 =
V_49 ;
} else if ( F_15 ( V_2 ) ) {
F_1 ( V_2 ) ;
V_2 -> V_48 = V_50 ;
}
F_34 ( V_39 ) ;
return ( V_7 < 0 ? V_7 : V_45 ) ;
}
T_4 F_35 ( struct V_1 * V_2 , struct V_38 * V_39 ,
const char * V_36 , T_5 V_45 )
{
bool V_29 ;
int V_46 ;
V_46 = F_30 ( V_36 , & V_29 ) ;
if ( V_46 )
return V_46 ;
F_23 ( V_39 ) ;
V_46 = V_29 ? F_28 ( V_2 , true ) : 0 ;
if ( ! V_46 ) {
V_2 -> V_29 = V_29 ;
V_46 = V_45 ;
}
F_25 ( V_39 ) ;
return V_46 ;
}
T_4 F_36 ( struct V_1 * V_2 , const char * V_36 ,
T_5 V_45 )
{
bool V_43 ;
int V_46 ;
V_46 = F_30 ( V_36 , & V_43 ) ;
if ( V_46 )
return V_46 ;
V_2 -> V_43 = V_43 ;
return V_45 ;
}
