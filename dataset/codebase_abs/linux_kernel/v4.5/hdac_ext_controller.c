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
F_13 ( & V_35 -> V_48 , & V_2 -> V_49 ) ;
}
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_34 * V_9 ;
while ( ! F_15 ( & V_2 -> V_49 ) ) {
V_9 = F_16 ( & V_2 -> V_49 , struct V_34 , V_48 ) ;
F_17 ( & V_9 -> V_48 ) ;
F_18 ( V_9 ) ;
}
}
struct V_34 * F_19 ( struct V_1 * V_2 ,
const char * V_50 )
{
int V_51 ;
struct V_34 * V_35 = NULL ;
int V_52 , V_53 ;
if ( sscanf ( V_50 , L_13 , & V_52 , & V_53 ) != 2 )
return NULL ;
if ( V_2 -> V_32 != V_52 )
return NULL ;
F_20 (hlink, &ebus->hlink_list, list) {
for ( V_51 = 0 ; V_51 < V_54 ; V_51 ++ ) {
if ( V_35 -> V_46 & ( 0x1 << V_53 ) )
return V_35 ;
}
}
return NULL ;
}
static int F_21 ( struct V_34 * V_55 , bool V_28 )
{
int V_56 ;
T_1 V_57 ;
int V_58 = ( 1 << V_59 ) ;
F_22 ( 3 ) ;
V_56 = 150 ;
do {
V_57 = F_10 ( V_55 -> V_41 + V_60 ) ;
if ( V_28 ) {
if ( ( ( V_57 & V_58 ) >> V_59 ) )
return 0 ;
} else {
if ( ! ( ( V_57 & V_58 ) >> V_59 ) )
return 0 ;
}
F_22 ( 3 ) ;
} while ( -- V_56 );
return - V_61 ;
}
int F_23 ( struct V_34 * V_55 )
{
F_7 ( V_55 -> V_41 , V_60 , 0 , V_62 ) ;
return F_21 ( V_55 , true ) ;
}
int F_24 ( struct V_34 * V_55 )
{
F_7 ( V_55 -> V_41 , V_60 , V_62 , 0 ) ;
return F_21 ( V_55 , false ) ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = NULL ;
int V_63 ;
F_20 (hlink, &ebus->hlink_list, list) {
F_7 ( V_35 -> V_41 ,
V_60 , 0 , V_62 ) ;
V_63 = F_21 ( V_35 , true ) ;
if ( V_63 < 0 )
return V_63 ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = NULL ;
int V_63 ;
F_20 (hlink, &ebus->hlink_list, list) {
F_7 ( V_35 -> V_41 , V_60 , V_62 , 0 ) ;
V_63 = F_21 ( V_35 , false ) ;
if ( V_63 < 0 )
return V_63 ;
}
return 0 ;
}
