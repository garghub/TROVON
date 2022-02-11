void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
if ( ! V_5 -> V_6 ) {
F_2 ( V_5 -> V_7 , L_1 ) ;
return;
}
if ( V_3 )
F_3 ( V_5 -> V_6 , V_8 , 0 , V_9 ) ;
else
F_3 ( V_5 -> V_6 , V_8 , V_9 , 0 ) ;
}
void F_4 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
if ( ! V_5 -> V_6 ) {
F_2 ( V_5 -> V_7 , L_2 ) ;
return;
}
if ( V_3 )
F_3 ( V_5 -> V_6 , V_8 , 0 , V_10 ) ;
else
F_3 ( V_5 -> V_6 , V_8 , V_10 , 0 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
int V_11 ;
T_1 V_12 ;
struct V_13 * V_14 ;
struct V_4 * V_5 = & V_2 -> V_5 ;
V_12 = F_6 ( V_5 -> V_15 + V_16 ) + 1 ;
F_7 ( V_5 -> V_7 , L_3 , V_17 , V_12 ) ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
V_14 = F_8 ( sizeof( * V_14 ) , V_18 ) ;
if ( ! V_14 )
return - V_19 ;
V_14 -> V_20 = V_11 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_21 = V_5 -> V_15 + V_22 +
( V_23 * V_11 ) ;
V_14 -> V_24 = F_6 ( V_14 -> V_21 + V_25 ) ;
V_14 -> V_26 = F_9 ( V_14 -> V_21 + V_27 ) ;
V_14 -> V_28 = 1 ;
F_10 ( & V_14 -> V_29 , & V_2 -> V_30 ) ;
}
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_13 * V_31 ;
while ( ! F_12 ( & V_2 -> V_30 ) ) {
V_31 = F_13 ( & V_2 -> V_30 , struct V_13 , V_29 ) ;
F_14 ( & V_31 -> V_29 ) ;
F_15 ( V_31 ) ;
}
}
struct V_13 * F_16 ( struct V_1 * V_2 ,
const char * V_32 )
{
int V_33 ;
struct V_13 * V_14 = NULL ;
int V_34 , V_35 ;
if ( sscanf ( V_32 , L_4 , & V_34 , & V_35 ) != 2 )
return NULL ;
if ( V_2 -> V_11 != V_34 )
return NULL ;
F_17 (hlink, &ebus->hlink_list, list) {
for ( V_33 = 0 ; V_33 < V_36 ; V_33 ++ ) {
if ( V_14 -> V_26 & ( 0x1 << V_35 ) )
return V_14 ;
}
}
return NULL ;
}
static int F_18 ( struct V_13 * V_37 , bool V_3 )
{
int V_38 ;
T_1 V_39 ;
int V_40 = ( 1 << V_41 ) ;
F_19 ( 3 ) ;
V_38 = 150 ;
do {
V_39 = F_6 ( V_37 -> V_21 + V_42 ) ;
if ( V_3 ) {
if ( ( ( V_39 & V_40 ) >> V_41 ) )
return 0 ;
} else {
if ( ! ( ( V_39 & V_40 ) >> V_41 ) )
return 0 ;
}
F_19 ( 3 ) ;
} while ( -- V_38 );
return - V_43 ;
}
int F_20 ( struct V_13 * V_37 )
{
F_3 ( V_37 -> V_21 , V_42 , 0 , V_44 ) ;
return F_18 ( V_37 , true ) ;
}
int F_21 ( struct V_13 * V_37 )
{
F_3 ( V_37 -> V_21 , V_42 , V_44 , 0 ) ;
return F_18 ( V_37 , false ) ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = NULL ;
int V_45 ;
F_17 (hlink, &ebus->hlink_list, list) {
F_3 ( V_14 -> V_21 ,
V_42 , 0 , V_44 ) ;
V_45 = F_18 ( V_14 , true ) ;
if ( V_45 < 0 )
return V_45 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = NULL ;
int V_45 ;
F_17 (hlink, &ebus->hlink_list, list) {
F_3 ( V_14 -> V_21 , V_42 , V_44 , 0 ) ;
V_45 = F_18 ( V_14 , false ) ;
if ( V_45 < 0 )
return V_45 ;
}
return 0 ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_13 * V_37 )
{
int V_45 = 0 ;
F_25 ( & V_2 -> V_46 ) ;
if ( ++ V_37 -> V_28 == 1 ) {
if ( ! V_2 -> V_47 ) {
F_26 ( & V_2 -> V_5 ) ;
V_2 -> V_47 = true ;
}
V_45 = F_20 ( V_37 ) ;
}
F_27 ( & V_2 -> V_46 ) ;
return V_45 ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_13 * V_37 )
{
int V_45 = 0 ;
struct V_13 * V_14 ;
bool V_48 = false ;
F_25 ( & V_2 -> V_46 ) ;
if ( -- V_37 -> V_28 == 0 ) {
V_45 = F_21 ( V_37 ) ;
F_17 (hlink, &ebus->hlink_list, list) {
if ( V_14 -> V_28 ) {
V_48 = true ;
break;
}
}
if ( ! V_48 ) {
F_29 ( & V_2 -> V_5 ) ;
V_2 -> V_47 = false ;
}
}
F_27 ( & V_2 -> V_46 ) ;
return V_45 ;
}
