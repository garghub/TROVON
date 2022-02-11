static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 &= V_5 ;
switch ( V_3 ) {
default:
return;
case V_6 :
V_2 -> V_4 |= V_7 ;
case V_8 :
V_2 -> V_4 |= V_9 ;
case V_10 :
V_2 -> V_4 |= V_11 ;
}
}
static int F_2 ( struct V_12 * V_13 , T_1 * V_14 )
{
struct V_15 * V_16 ;
const char * V_17 ;
unsigned int V_18 , V_19 ;
F_3 (device, L_1 , prop, cp) {
if ( sscanf ( V_17 , L_2 , & V_18 , & V_19 ) == 2 ) {
* V_14 = ( ( V_18 & 0xFFFF ) << 16 ) | ( V_19 & 0xFFFF ) ;
return 0 ;
}
}
return - V_20 ;
}
static int F_4 ( struct V_21 * V_22 , struct V_12 * V_23 ,
T_1 V_24 )
{
struct V_1 * V_25 ;
bool V_26 ;
int V_27 ;
T_1 V_3 = 0 ;
T_1 V_14 ;
V_26 = F_5 ( V_23 ,
L_3 ) ;
if ( ! V_26 && ! F_2 ( V_23 , & V_14 ) )
V_25 = F_6 ( V_22 , V_24 , V_14 , 0 , NULL ) ;
else
V_25 = F_7 ( V_22 , V_24 , V_26 ) ;
if ( ! V_25 || F_8 ( V_25 ) )
return 1 ;
V_27 = F_9 ( V_23 , 0 ) ;
if ( V_27 > 0 ) {
V_25 -> V_28 = V_27 ;
if ( V_22 -> V_28 )
V_22 -> V_28 [ V_24 ] = V_27 ;
} else {
if ( V_22 -> V_28 )
V_25 -> V_28 = V_22 -> V_28 [ V_24 ] ;
}
F_10 ( V_23 ) ;
V_25 -> V_29 . V_30 = V_23 ;
V_27 = F_11 ( V_25 ) ;
if ( V_27 ) {
F_12 ( V_25 ) ;
F_13 ( V_23 ) ;
return 1 ;
}
if ( ! F_14 ( V_23 , L_4 , & V_3 ) )
F_1 ( V_25 , V_3 ) ;
F_15 ( & V_22 -> V_29 , L_5 ,
V_23 -> V_31 , V_24 ) ;
return 0 ;
}
int F_16 ( struct V_21 * V_22 , struct V_12 * V_32 )
{
struct V_12 * V_23 ;
const T_2 * V_33 ;
T_1 V_24 ;
bool V_34 = false ;
int V_27 , V_35 , V_36 ;
V_22 -> V_37 = ~ 0 ;
if ( V_22 -> V_28 )
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ )
V_22 -> V_28 [ V_35 ] = V_39 ;
V_22 -> V_29 . V_30 = V_32 ;
V_27 = F_17 ( V_22 ) ;
if ( V_27 )
return V_27 ;
F_18 (np, child) {
V_33 = F_19 ( V_23 , L_6 , & V_36 ) ;
if ( ! V_33 || V_36 < sizeof( * V_33 ) ) {
V_34 = true ;
F_20 ( & V_22 -> V_29 , L_7 ,
V_23 -> V_40 ) ;
continue;
}
V_24 = F_21 ( V_33 ) ;
if ( V_24 >= V_38 ) {
F_20 ( & V_22 -> V_29 , L_8 ,
V_23 -> V_40 , V_24 ) ;
continue;
}
V_27 = F_4 ( V_22 , V_23 , V_24 ) ;
if ( V_27 )
continue;
}
if ( ! V_34 )
return 0 ;
F_18 (np, child) {
V_33 = F_19 ( V_23 , L_6 , & V_36 ) ;
if ( V_33 )
continue;
for ( V_24 = 0 ; V_24 < V_38 ; V_24 ++ ) {
if ( V_22 -> V_41 [ V_24 ] )
continue;
F_22 ( & V_22 -> V_29 , L_9 ,
V_23 -> V_31 , V_24 ) ;
V_27 = F_4 ( V_22 , V_23 , V_24 ) ;
if ( V_27 )
continue;
}
}
return 0 ;
}
static int F_23 ( struct V_13 * V_29 , void * V_42 )
{
return V_29 -> V_30 == V_42 ;
}
struct V_1 * F_24 ( struct V_12 * V_42 )
{
struct V_13 * V_43 ;
if ( ! V_42 )
return NULL ;
V_43 = F_25 ( & V_44 , NULL , V_42 , F_23 ) ;
return V_43 ? F_26 ( V_43 ) : NULL ;
}
struct V_1 * F_27 ( struct V_45 * V_29 ,
struct V_12 * V_42 ,
void (* F_28)( struct V_45 * ) , T_1 V_46 ,
T_3 V_47 )
{
struct V_1 * V_25 = F_24 ( V_42 ) ;
if ( ! V_25 )
return NULL ;
return F_29 ( V_29 , V_25 , F_28 , V_47 ) ? NULL : V_25 ;
}
struct V_1 * F_30 ( struct V_45 * V_29 ,
void (* F_28)( struct V_45 * ) ,
T_3 V_47 )
{
struct V_12 * V_48 ;
char V_49 [ V_50 + 3 ] ;
struct V_1 * V_25 ;
const T_2 * V_14 ;
int V_51 ;
if ( ! V_29 -> V_29 . V_52 )
return NULL ;
V_48 = V_29 -> V_29 . V_52 -> V_30 ;
if ( ! V_48 )
return NULL ;
V_14 = F_19 ( V_48 , L_10 , & V_51 ) ;
if ( ! V_14 || V_51 < sizeof( * V_14 ) )
return NULL ;
sprintf ( V_49 , V_53 , L_11 , F_31 ( V_14 [ 0 ] ) ) ;
V_25 = F_32 ( V_29 , V_49 , F_28 , V_47 ) ;
return F_8 ( V_25 ) ? NULL : V_25 ;
}
struct V_1 * F_33 ( struct V_45 * V_29 ,
struct V_12 * V_42 , T_1 V_46 ,
T_3 V_47 )
{
struct V_1 * V_25 = F_24 ( V_42 ) ;
if ( ! V_25 )
return NULL ;
return F_34 ( V_29 , V_25 , V_46 , V_47 ) ? NULL : V_25 ;
}
