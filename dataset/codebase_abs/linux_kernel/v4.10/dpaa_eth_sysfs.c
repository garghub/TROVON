static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_9 )
return sprintf ( V_5 , L_1 ,
( unsigned long long ) V_9 -> V_10 -> V_11 ) ;
else
return sprintf ( V_5 , L_2 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
struct V_12 * V_13 = NULL ;
char * V_14 = NULL ;
struct V_12 * V_15 ;
struct V_12 * V_16 ;
T_2 V_17 = 0 ;
T_2 V_18 = 0 ;
T_1 V_19 = 0 ;
char * V_20 ;
int V_21 = 0 ;
F_5 (fq, tmp, &priv->dpaa_fq_list, list) {
switch ( V_16 -> V_22 ) {
case V_23 :
V_20 = L_3 ;
break;
case V_24 :
V_20 = L_4 ;
break;
case V_25 :
V_20 = L_5 ;
break;
case V_26 :
V_20 = L_6 ;
break;
case V_27 :
V_20 = L_7 ;
break;
case V_28 :
V_20 = L_8 ;
break;
default:
V_20 = L_9 ;
}
if ( V_13 && ( abs ( V_16 -> V_29 - V_13 -> V_29 ) != 1 ||
V_20 != V_14 ) ) {
if ( V_18 == V_17 )
V_19 += sprintf ( V_5 + V_19 ,
L_10 , V_14 , V_13 -> V_29 ) ;
else
V_19 += sprintf ( V_5 + V_19 ,
L_11 , V_14 ,
V_17 , V_18 ) ;
}
if ( V_13 && abs ( V_16 -> V_29 - V_13 -> V_29 ) == 1 &&
V_20 == V_14 ) {
V_18 = V_16 -> V_29 ;
} else {
V_17 = V_16 -> V_29 ;
V_18 = V_16 -> V_29 ;
}
V_13 = V_16 ;
V_14 = V_20 ;
V_21 ++ ;
}
if ( V_13 ) {
if ( V_18 == V_17 )
V_19 += sprintf ( V_5 + V_19 , L_10 , V_14 ,
V_13 -> V_29 ) ;
else
V_19 += sprintf ( V_5 + V_19 , L_11 , V_14 ,
V_17 , V_18 ) ;
}
return V_19 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
T_1 V_19 = 0 ;
int V_21 = 0 ;
for ( V_21 = 0 ; V_21 < V_30 ; V_21 ++ )
V_19 += snprintf ( V_5 + V_19 , V_31 - V_19 , L_12 ,
V_7 -> V_32 [ V_21 ] -> V_33 ) ;
return V_19 ;
}
void F_7 ( struct V_1 * V_2 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < F_8 ( V_34 ) ; V_21 ++ )
if ( F_9 ( V_2 , & V_34 [ V_21 ] ) ) {
F_10 ( V_2 , L_13 ) ;
while ( V_21 > 0 )
F_11 ( V_2 , & V_34 [ -- V_21 ] ) ;
return;
}
}
void F_12 ( struct V_1 * V_2 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < F_8 ( V_34 ) ; V_21 ++ )
F_11 ( V_2 , & V_34 [ V_21 ] ) ;
}
