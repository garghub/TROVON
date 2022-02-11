int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
unsigned int V_4 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
unsigned int V_7 = 0 ;
V_4 = F_2 ( V_6 , V_8 ) ;
do {
V_3 = F_3 ( V_9 , V_6 , V_4 ) ;
F_4 ( V_6 -> V_10 , L_1 ,
( ( V_3 & V_11 ) >> V_12 ) ) ;
F_4 ( V_6 -> V_10 , L_2 ,
( V_3 & V_13 ) >> V_14 ) ;
switch ( ( V_3 & V_13 ) >> V_14 ) {
case V_15 :
F_4 ( V_6 -> V_10 , L_3 ) ;
V_2 -> V_16 = V_6 -> V_17 + V_4 ;
break;
case V_18 :
F_4 ( V_6 -> V_10 , L_4 , V_4 ) ;
V_2 -> V_19 = V_6 -> V_17 + V_4 ;
break;
case V_20 :
F_4 ( V_6 -> V_10 , L_5 , V_4 ) ;
V_2 -> V_21 = V_6 -> V_17 + V_4 ;
break;
case V_22 :
F_4 ( V_6 -> V_10 , L_6 ) ;
V_2 -> V_23 = V_6 -> V_17 + V_4 ;
break;
case V_24 :
F_4 ( V_6 -> V_10 , L_7 ) ;
V_2 -> V_25 = V_6 -> V_17 + V_4 ;
break;
default:
F_4 ( V_6 -> V_10 , L_8 , V_3 ) ;
break;
}
V_7 ++ ;
if ( V_7 > V_26 ) {
F_5 ( V_6 -> V_10 , L_9 ) ;
break;
}
V_4 = V_3 & V_27 ;
} while ( V_4 );
return 0 ;
}
void F_6 ( struct V_1 * V_2 , bool V_28 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_2 -> V_21 ) {
F_5 ( V_6 -> V_10 , L_10 ) ;
return;
}
if ( V_28 )
F_7 ( V_2 -> V_21 , V_29 , 0 , V_30 ) ;
else
F_7 ( V_2 -> V_21 , V_29 , V_30 , 0 ) ;
}
void F_8 ( struct V_1 * V_2 , bool V_28 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_2 -> V_21 ) {
F_5 ( V_6 -> V_10 , L_11 ) ;
return;
}
if ( V_28 )
F_7 ( V_2 -> V_21 , V_29 , 0 , V_31 ) ;
else
F_7 ( V_2 -> V_21 , V_29 , V_31 , 0 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_32 ;
T_1 V_33 ;
struct V_34 * V_35 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_33 = F_10 ( V_2 -> V_16 + V_36 ) + 1 ;
F_4 ( V_6 -> V_10 , L_12 , V_37 , V_33 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
V_35 = F_11 ( sizeof( * V_35 ) , V_38 ) ;
if ( ! V_35 )
return - V_39 ;
V_35 -> V_40 = V_32 ;
V_35 -> V_6 = V_6 ;
V_35 -> V_41 = V_2 -> V_16 + V_42 +
( V_43 * V_32 ) ;
V_35 -> V_44 = F_10 ( V_35 -> V_41 + V_45 ) ;
V_35 -> V_46 = F_12 ( V_35 -> V_41 + V_47 ) ;
V_35 -> V_48 = 1 ;
F_13 ( & V_35 -> V_49 , & V_2 -> V_50 ) ;
}
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_34 * V_9 ;
while ( ! F_15 ( & V_2 -> V_50 ) ) {
V_9 = F_16 ( & V_2 -> V_50 , struct V_34 , V_49 ) ;
F_17 ( & V_9 -> V_49 ) ;
F_18 ( V_9 ) ;
}
}
struct V_34 * F_19 ( struct V_1 * V_2 ,
const char * V_51 )
{
int V_52 ;
struct V_34 * V_35 = NULL ;
int V_53 , V_54 ;
if ( sscanf ( V_51 , L_13 , & V_53 , & V_54 ) != 2 )
return NULL ;
if ( V_2 -> V_32 != V_53 )
return NULL ;
F_20 (hlink, &ebus->hlink_list, list) {
for ( V_52 = 0 ; V_52 < V_55 ; V_52 ++ ) {
if ( V_35 -> V_46 & ( 0x1 << V_54 ) )
return V_35 ;
}
}
return NULL ;
}
static int F_21 ( struct V_34 * V_56 , bool V_28 )
{
int V_57 ;
T_1 V_58 ;
int V_59 = ( 1 << V_60 ) ;
F_22 ( 3 ) ;
V_57 = 150 ;
do {
V_58 = F_10 ( V_56 -> V_41 + V_61 ) ;
if ( V_28 ) {
if ( ( ( V_58 & V_59 ) >> V_60 ) )
return 0 ;
} else {
if ( ! ( ( V_58 & V_59 ) >> V_60 ) )
return 0 ;
}
F_22 ( 3 ) ;
} while ( -- V_57 );
return - V_62 ;
}
int F_23 ( struct V_34 * V_56 )
{
F_7 ( V_56 -> V_41 , V_61 , 0 , V_63 ) ;
return F_21 ( V_56 , true ) ;
}
int F_24 ( struct V_34 * V_56 )
{
F_7 ( V_56 -> V_41 , V_61 , V_63 , 0 ) ;
return F_21 ( V_56 , false ) ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = NULL ;
int V_64 ;
F_20 (hlink, &ebus->hlink_list, list) {
F_7 ( V_35 -> V_41 ,
V_61 , 0 , V_63 ) ;
V_64 = F_21 ( V_35 , true ) ;
if ( V_64 < 0 )
return V_64 ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = NULL ;
int V_64 ;
F_20 (hlink, &ebus->hlink_list, list) {
F_7 ( V_35 -> V_41 , V_61 , V_63 , 0 ) ;
V_64 = F_21 ( V_35 , false ) ;
if ( V_64 < 0 )
return V_64 ;
}
return 0 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_34 * V_56 )
{
int V_64 = 0 ;
F_28 ( & V_2 -> V_65 ) ;
if ( ++ V_56 -> V_48 == 1 ) {
if ( ! V_2 -> V_66 ) {
F_29 ( & V_2 -> V_6 ) ;
V_2 -> V_66 = true ;
}
V_64 = F_23 ( V_56 ) ;
}
F_30 ( & V_2 -> V_65 ) ;
return V_64 ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_34 * V_56 )
{
int V_64 = 0 ;
struct V_34 * V_35 ;
bool V_67 = false ;
F_28 ( & V_2 -> V_65 ) ;
if ( -- V_56 -> V_48 == 0 ) {
V_64 = F_24 ( V_56 ) ;
F_20 (hlink, &ebus->hlink_list, list) {
if ( V_35 -> V_48 ) {
V_67 = true ;
break;
}
}
if ( ! V_67 ) {
F_32 ( & V_2 -> V_6 ) ;
V_2 -> V_66 = false ;
}
}
F_30 ( & V_2 -> V_65 ) ;
return V_64 ;
}
