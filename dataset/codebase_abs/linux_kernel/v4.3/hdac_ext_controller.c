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
default:
F_4 ( V_6 -> V_10 , L_7 , V_3 ) ;
break;
}
V_7 ++ ;
if ( V_7 > V_24 ) {
F_5 ( V_6 -> V_10 , L_8 ) ;
break;
}
V_4 = V_3 & V_25 ;
} while ( V_4 );
return 0 ;
}
void F_6 ( struct V_1 * V_2 , bool V_26 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_2 -> V_21 ) {
F_5 ( V_6 -> V_10 , L_9 ) ;
return;
}
if ( V_26 )
F_7 ( V_2 -> V_21 , V_27 , 0 , V_28 ) ;
else
F_7 ( V_2 -> V_21 , V_27 , V_28 , 0 ) ;
}
void F_8 ( struct V_1 * V_2 , bool V_26 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_2 -> V_21 ) {
F_5 ( V_6 -> V_10 , L_10 ) ;
return;
}
if ( V_26 )
F_7 ( V_2 -> V_21 , V_27 , 0 , V_29 ) ;
else
F_7 ( V_2 -> V_21 , V_27 , V_29 , 0 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_30 ;
T_1 V_31 ;
struct V_32 * V_33 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_31 = F_10 ( V_2 -> V_16 + V_34 ) + 1 ;
F_4 ( V_6 -> V_10 , L_11 , V_35 , V_31 ) ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
V_33 = F_11 ( sizeof( * V_33 ) , V_36 ) ;
if ( ! V_33 )
return - V_37 ;
V_33 -> V_38 = V_30 ;
V_33 -> V_6 = V_6 ;
V_33 -> V_39 = V_2 -> V_16 + V_40 +
( V_41 * V_30 ) ;
V_33 -> V_42 = F_10 ( V_33 -> V_39 + V_43 ) ;
V_33 -> V_44 = F_12 ( V_33 -> V_39 + V_45 ) ;
F_13 ( & V_33 -> V_46 , & V_2 -> V_47 ) ;
}
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_32 * V_9 ;
while ( ! F_15 ( & V_2 -> V_47 ) ) {
V_9 = F_16 ( & V_2 -> V_47 , struct V_32 , V_46 ) ;
F_17 ( & V_9 -> V_46 ) ;
F_18 ( V_9 ) ;
}
}
struct V_32 * F_19 ( struct V_1 * V_2 ,
const char * V_48 )
{
int V_49 ;
struct V_32 * V_33 = NULL ;
int V_50 , V_51 ;
if ( sscanf ( V_48 , L_12 , & V_50 , & V_51 ) != 2 )
return NULL ;
if ( V_2 -> V_30 != V_50 )
return NULL ;
F_20 (hlink, &ebus->hlink_list, list) {
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ ) {
if ( V_33 -> V_44 & ( 0x1 << V_51 ) )
return V_33 ;
}
}
return NULL ;
}
static int F_21 ( struct V_32 * V_53 , bool V_26 )
{
int V_54 ;
T_1 V_55 ;
int V_56 = ( 1 << V_57 ) ;
F_22 ( 3 ) ;
V_54 = 50 ;
do {
V_55 = F_10 ( V_53 -> V_39 + V_58 ) ;
if ( V_26 ) {
if ( ( ( V_55 & V_56 ) >> V_57 ) )
return 0 ;
} else {
if ( ! ( ( V_55 & V_56 ) >> V_57 ) )
return 0 ;
}
F_22 ( 3 ) ;
} while ( -- V_54 );
return - V_59 ;
}
int F_23 ( struct V_32 * V_53 )
{
F_7 ( V_53 -> V_39 , V_58 , 0 , V_60 ) ;
return F_21 ( V_53 , true ) ;
}
int F_24 ( struct V_32 * V_53 )
{
F_7 ( V_53 -> V_39 , V_58 , V_60 , 0 ) ;
return F_21 ( V_53 , false ) ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = NULL ;
int V_61 ;
F_20 (hlink, &ebus->hlink_list, list) {
F_7 ( V_33 -> V_39 , V_58 , V_60 , 0 ) ;
V_61 = F_21 ( V_33 , false ) ;
if ( V_61 < 0 )
return V_61 ;
}
return 0 ;
}
