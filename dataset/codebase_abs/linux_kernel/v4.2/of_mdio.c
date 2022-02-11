static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 ;
const char * V_6 ;
unsigned int V_7 , V_8 ;
F_2 (device, L_1 , prop, cp) {
if ( sscanf ( V_6 , L_2 , & V_7 , & V_8 ) == 2 ) {
* V_3 = ( ( V_7 & 0xFFFF ) << 16 ) | ( V_8 & 0xFFFF ) ;
return 0 ;
}
}
return - V_9 ;
}
static int F_3 ( struct V_10 * V_11 , struct V_1 * V_12 ,
T_1 V_13 )
{
struct V_14 * V_15 ;
bool V_16 ;
int V_17 ;
T_1 V_3 ;
V_16 = F_4 ( V_12 ,
L_3 ) ;
if ( ! V_16 && ! F_1 ( V_12 , & V_3 ) )
V_15 = F_5 ( V_11 , V_13 , V_3 , 0 , NULL ) ;
else
V_15 = F_6 ( V_11 , V_13 , V_16 ) ;
if ( ! V_15 || F_7 ( V_15 ) )
return 1 ;
V_17 = F_8 ( V_12 , 0 ) ;
if ( V_17 > 0 ) {
V_15 -> V_18 = V_17 ;
if ( V_11 -> V_18 )
V_11 -> V_18 [ V_13 ] = V_17 ;
} else {
if ( V_11 -> V_18 )
V_15 -> V_18 = V_11 -> V_18 [ V_13 ] ;
}
if ( F_9 ( V_12 , L_4 ) )
V_11 -> V_19 |= 1 << V_13 ;
F_10 ( V_12 ) ;
V_15 -> V_20 . V_21 = V_12 ;
V_17 = F_11 ( V_15 ) ;
if ( V_17 ) {
F_12 ( V_15 ) ;
F_13 ( V_12 ) ;
return 1 ;
}
F_14 ( & V_11 -> V_20 , L_5 ,
V_12 -> V_22 , V_13 ) ;
return 0 ;
}
int F_15 ( struct V_2 * V_20 , const struct V_1 * V_23 )
{
T_1 V_13 ;
int V_24 ;
V_24 = F_16 ( V_23 , L_6 , & V_13 ) ;
if ( V_24 < 0 ) {
F_17 ( V_20 , L_7 , V_23 -> V_25 ) ;
return V_24 ;
}
if ( V_13 >= V_26 ) {
F_17 ( V_20 , L_8 ,
V_23 -> V_25 , V_13 ) ;
return - V_9 ;
}
return V_13 ;
}
int F_18 ( struct V_10 * V_11 , struct V_1 * V_23 )
{
struct V_1 * V_12 ;
const T_2 * V_27 ;
bool V_28 = false ;
int V_13 , V_17 , V_29 ;
V_11 -> V_30 = ~ 0 ;
if ( V_11 -> V_18 )
for ( V_29 = 0 ; V_29 < V_26 ; V_29 ++ )
V_11 -> V_18 [ V_29 ] = V_31 ;
V_11 -> V_20 . V_21 = V_23 ;
V_17 = F_19 ( V_11 ) ;
if ( V_17 )
return V_17 ;
F_20 (np, child) {
V_13 = F_15 ( & V_11 -> V_20 , V_12 ) ;
if ( V_13 < 0 ) {
V_28 = true ;
continue;
}
V_17 = F_3 ( V_11 , V_12 , V_13 ) ;
if ( V_17 )
continue;
}
if ( ! V_28 )
return 0 ;
F_20 (np, child) {
V_27 = F_21 ( V_12 , L_6 , NULL ) ;
if ( V_27 )
continue;
for ( V_13 = 0 ; V_13 < V_26 ; V_13 ++ ) {
if ( V_11 -> V_32 [ V_13 ] )
continue;
F_22 ( & V_11 -> V_20 , L_9 ,
V_12 -> V_22 , V_13 ) ;
V_17 = F_3 ( V_11 , V_12 , V_13 ) ;
if ( V_17 )
continue;
}
}
return 0 ;
}
static int F_23 ( struct V_2 * V_20 , void * V_33 )
{
return V_20 -> V_21 == V_33 ;
}
struct V_14 * F_24 ( struct V_1 * V_33 )
{
struct V_2 * V_34 ;
if ( ! V_33 )
return NULL ;
V_34 = F_25 ( & V_35 , NULL , V_33 , F_23 ) ;
return V_34 ? F_26 ( V_34 ) : NULL ;
}
struct V_14 * F_27 ( struct V_36 * V_20 ,
struct V_1 * V_33 ,
void (* F_28)( struct V_36 * ) , T_1 V_37 ,
T_3 V_38 )
{
struct V_14 * V_15 = F_24 ( V_33 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_39 = V_37 ;
return F_29 ( V_20 , V_15 , F_28 , V_38 ) ? NULL : V_15 ;
}
struct V_14 * F_30 ( struct V_36 * V_20 ,
struct V_1 * V_33 , T_1 V_37 ,
T_3 V_38 )
{
struct V_14 * V_15 = F_24 ( V_33 ) ;
if ( ! V_15 )
return NULL ;
return F_31 ( V_20 , V_15 , V_37 , V_38 ) ? NULL : V_15 ;
}
bool F_32 ( struct V_1 * V_23 )
{
struct V_1 * V_40 ;
int V_41 ;
V_40 = F_33 ( V_23 , L_10 ) ;
if ( V_40 ) {
F_13 ( V_40 ) ;
return true ;
}
if ( F_21 ( V_23 , L_10 , & V_41 ) &&
V_41 == ( 5 * sizeof( T_2 ) ) )
return true ;
return false ;
}
int F_34 ( struct V_1 * V_23 )
{
struct V_42 V_43 = {} ;
struct V_1 * V_44 ;
const T_2 * V_45 ;
int V_41 ;
struct V_14 * V_15 ;
V_44 = F_33 ( V_23 , L_10 ) ;
if ( V_44 ) {
V_43 . V_46 = 1 ;
V_43 . V_47 = F_9 ( V_44 ,
L_11 ) ;
if ( F_16 ( V_44 , L_12 , & V_43 . V_48 ) )
return - V_9 ;
V_43 . V_49 = F_9 ( V_44 , L_13 ) ;
V_43 . V_50 = F_9 ( V_44 ,
L_14 ) ;
F_13 ( V_44 ) ;
V_15 = F_35 ( V_31 , & V_43 , V_23 ) ;
return F_7 ( V_15 ) ? F_36 ( V_15 ) : 0 ;
}
V_45 = F_21 ( V_23 , L_10 , & V_41 ) ;
if ( V_45 && V_41 == ( 5 * sizeof( T_2 ) ) ) {
V_43 . V_46 = 1 ;
V_43 . V_47 = F_37 ( V_45 [ 1 ] ) ;
V_43 . V_48 = F_37 ( V_45 [ 2 ] ) ;
V_43 . V_49 = F_37 ( V_45 [ 3 ] ) ;
V_43 . V_50 = F_37 ( V_45 [ 4 ] ) ;
V_15 = F_35 ( V_31 , & V_43 , V_23 ) ;
return F_7 ( V_15 ) ? F_36 ( V_15 ) : 0 ;
}
return - V_51 ;
}
