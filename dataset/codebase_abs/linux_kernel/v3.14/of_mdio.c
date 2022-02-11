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
static int F_2 ( struct V_12 * V_13 , struct V_14 * V_15 ,
T_1 V_16 )
{
struct V_1 * V_17 ;
bool V_18 ;
int V_19 ;
T_1 V_3 = 0 ;
V_18 = F_3 ( V_15 ,
L_1 ) ;
V_17 = F_4 ( V_13 , V_16 , V_18 ) ;
if ( ! V_17 || F_5 ( V_17 ) )
return 1 ;
V_19 = F_6 ( V_15 , 0 ) ;
if ( V_19 > 0 ) {
V_17 -> V_20 = V_19 ;
if ( V_13 -> V_20 )
V_13 -> V_20 [ V_16 ] = V_19 ;
} else {
if ( V_13 -> V_20 )
V_17 -> V_20 = V_13 -> V_20 [ V_16 ] ;
}
F_7 ( V_15 ) ;
V_17 -> V_21 . V_22 = V_15 ;
V_19 = F_8 ( V_17 ) ;
if ( V_19 ) {
F_9 ( V_17 ) ;
F_10 ( V_15 ) ;
return 1 ;
}
if ( ! F_11 ( V_15 , L_2 , & V_3 ) )
F_1 ( V_17 , V_3 ) ;
F_12 ( & V_13 -> V_21 , L_3 ,
V_15 -> V_23 , V_16 ) ;
return 0 ;
}
int F_13 ( struct V_12 * V_13 , struct V_14 * V_24 )
{
struct V_14 * V_15 ;
const T_2 * V_25 ;
T_1 V_16 ;
bool V_26 = false ;
int V_19 , V_27 , V_28 ;
V_13 -> V_29 = ~ 0 ;
if ( V_13 -> V_20 )
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ )
V_13 -> V_20 [ V_27 ] = V_31 ;
V_13 -> V_21 . V_22 = V_24 ;
V_19 = F_14 ( V_13 ) ;
if ( V_19 )
return V_19 ;
F_15 (np, child) {
V_25 = F_16 ( V_15 , L_4 , & V_28 ) ;
if ( ! V_25 || V_28 < sizeof( * V_25 ) ) {
V_26 = true ;
F_17 ( & V_13 -> V_21 , L_5 ,
V_15 -> V_32 ) ;
continue;
}
V_16 = F_18 ( V_25 ) ;
if ( V_16 >= V_30 ) {
F_17 ( & V_13 -> V_21 , L_6 ,
V_15 -> V_32 , V_16 ) ;
continue;
}
V_19 = F_2 ( V_13 , V_15 , V_16 ) ;
if ( V_19 )
continue;
}
if ( ! V_26 )
return 0 ;
F_15 (np, child) {
V_25 = F_16 ( V_15 , L_4 , & V_28 ) ;
if ( V_25 )
continue;
for ( V_16 = 0 ; V_16 < V_30 ; V_16 ++ ) {
if ( V_13 -> V_33 [ V_16 ] )
continue;
F_19 ( & V_13 -> V_21 , L_7 ,
V_15 -> V_23 , V_16 ) ;
V_19 = F_2 ( V_13 , V_15 , V_16 ) ;
if ( V_19 )
continue;
}
}
return 0 ;
}
static int F_20 ( struct V_34 * V_21 , void * V_35 )
{
return V_21 -> V_22 == V_35 ;
}
struct V_1 * F_21 ( struct V_14 * V_35 )
{
struct V_34 * V_36 ;
if ( ! V_35 )
return NULL ;
V_36 = F_22 ( & V_37 , NULL , V_35 , F_20 ) ;
return V_36 ? F_23 ( V_36 ) : NULL ;
}
struct V_1 * F_24 ( struct V_38 * V_21 ,
struct V_14 * V_35 ,
void (* F_25)( struct V_38 * ) , T_1 V_39 ,
T_3 V_40 )
{
struct V_1 * V_17 = F_21 ( V_35 ) ;
if ( ! V_17 )
return NULL ;
return F_26 ( V_21 , V_17 , F_25 , V_40 ) ? NULL : V_17 ;
}
struct V_1 * F_27 ( struct V_38 * V_21 ,
void (* F_25)( struct V_38 * ) ,
T_3 V_40 )
{
struct V_14 * V_41 ;
char V_42 [ V_43 + 3 ] ;
struct V_1 * V_17 ;
const T_2 * V_44 ;
int V_45 ;
if ( ! V_21 -> V_21 . V_46 )
return NULL ;
V_41 = V_21 -> V_21 . V_46 -> V_22 ;
if ( ! V_41 )
return NULL ;
V_44 = F_16 ( V_41 , L_8 , & V_45 ) ;
if ( ! V_44 || V_45 < sizeof( * V_44 ) )
return NULL ;
sprintf ( V_42 , V_47 , L_9 , F_28 ( V_44 [ 0 ] ) ) ;
V_17 = F_29 ( V_21 , V_42 , F_25 , V_40 ) ;
return F_5 ( V_17 ) ? NULL : V_17 ;
}
struct V_1 * F_30 ( struct V_38 * V_21 ,
struct V_14 * V_35 , T_1 V_39 ,
T_3 V_40 )
{
struct V_1 * V_17 = F_21 ( V_35 ) ;
if ( ! V_17 )
return NULL ;
return F_31 ( V_21 , V_17 , V_39 , V_40 ) ? NULL : V_17 ;
}
