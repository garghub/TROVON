static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
const struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_3 -> V_7 ;
int V_8 ;
V_8 = F_2 ( V_3 -> V_9 , V_5 -> V_10 ,
V_5 -> V_11 , V_5 -> V_12 ) ;
if ( V_8 )
F_3 ( V_7 , L_1 ) ;
return V_8 ;
}
static int F_4 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
const struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_3 -> V_7 ;
int V_8 ;
V_8 = F_2 ( V_3 -> V_9 , V_5 -> V_10 ,
V_5 -> V_11 , V_5 -> V_13 ) ;
if ( V_8 )
F_3 ( V_7 , L_2 ) ;
return V_8 ;
}
static int F_5 ( struct V_2 * V_3 , T_1 V_14 ,
int V_15 , T_1 * V_16 )
{
const struct V_4 * V_5 = V_3 -> V_5 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_18 ; V_17 ++ ) {
const struct V_19 * V_20 = & V_5 -> V_20 [ V_17 ] ;
if ( V_14 >= V_20 -> V_14 && V_14 + V_15 < V_20 -> V_14 + V_20 -> V_21 ) {
unsigned int V_22 = V_14 - V_20 -> V_14 ;
* V_16 = V_20 -> V_23 + V_22 ;
return 0 ;
}
}
F_6 ( V_3 -> V_7 , L_3 ,
V_14 , V_15 ) ;
return - V_24 ;
}
static void * F_7 ( struct V_1 * V_1 , T_1 V_14 , int V_15 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
void * V_25 = NULL ;
T_1 V_16 ;
int V_17 ;
if ( V_15 <= 0 )
return NULL ;
if ( F_5 ( V_3 , V_14 , V_15 , & V_16 ) )
return NULL ;
for ( V_17 = 0 ; V_17 < V_26 ; V_17 ++ ) {
if ( V_16 >= V_3 -> V_27 [ V_17 ] . V_28 && V_16 + V_15 <
V_3 -> V_27 [ V_17 ] . V_28 + V_3 -> V_27 [ V_17 ] . V_21 ) {
unsigned int V_22 = V_16 - V_3 -> V_27 [ V_17 ] . V_28 ;
V_25 = ( V_29 void * ) ( V_3 -> V_27 [ V_17 ] . V_30 + V_22 ) ;
break;
}
}
F_8 ( & V_1 -> V_7 , L_4 , V_14 , V_15 , V_25 ) ;
return V_25 ;
}
static int F_9 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
const struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = & V_32 -> V_7 ;
struct V_33 * V_34 = V_7 -> V_35 ;
int V_36 , V_37 = 0 , V_38 , V_39 ;
for ( V_36 = 0 ; V_36 < V_5 -> V_18 ; V_36 ++ ) {
const struct V_19 * V_20 = & V_5 -> V_20 [ V_36 ] ;
if ( ! ( V_20 -> V_40 & V_41 ) )
continue;
if ( V_37 >= V_26 )
break;
V_3 -> V_27 [ V_37 ] . V_30 = F_10 ( & V_32 -> V_7 ,
V_20 -> V_23 , V_20 -> V_21 ) ;
if ( ! V_3 -> V_27 [ V_37 ] . V_30 ) {
F_3 ( V_7 , L_5 ) ;
return - V_42 ;
}
V_3 -> V_27 [ V_37 ] . V_28 = V_20 -> V_23 ;
V_3 -> V_27 [ V_37 ] . V_21 = V_20 -> V_21 ;
V_37 ++ ;
}
V_39 = F_11 ( V_34 , L_6 , NULL ) ;
if ( V_39 <= 0 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_39 ; V_36 ++ ) {
struct V_33 * V_43 ;
struct V_44 V_45 ;
V_43 = F_12 ( V_34 , L_6 , V_36 ) ;
V_38 = F_13 ( V_43 , 0 , & V_45 ) ;
if ( V_38 ) {
F_3 ( V_7 , L_7 ) ;
return V_38 ;
}
if ( V_37 >= V_26 )
break;
V_3 -> V_27 [ V_37 ] . V_30 = F_14 ( & V_32 -> V_7 , & V_45 ) ;
if ( F_15 ( V_3 -> V_27 [ V_37 ] . V_30 ) ) {
F_3 ( V_7 , L_5 ) ;
V_38 = F_16 ( V_3 -> V_27 [ V_37 ] . V_30 ) ;
return V_38 ;
}
V_3 -> V_27 [ V_37 ] . V_28 = V_45 . V_46 ;
V_3 -> V_27 [ V_37 ] . V_21 = F_17 ( & V_45 ) ;
V_37 ++ ;
}
return 0 ;
}
static int F_18 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = & V_32 -> V_7 ;
struct V_33 * V_34 = V_7 -> V_35 ;
struct V_2 * V_3 ;
struct V_1 * V_1 ;
struct V_47 V_48 = { . V_49 = L_8 } ;
const struct V_4 * V_5 ;
struct V_9 * V_9 ;
int V_8 ;
V_9 = F_19 ( V_34 , L_9 ) ;
if ( F_15 ( V_9 ) ) {
F_3 ( V_7 , L_10 ) ;
return F_16 ( V_9 ) ;
}
F_20 ( V_7 , V_9 , & V_48 ) ;
V_1 = F_21 ( V_7 , L_8 , & V_50 ,
NULL , sizeof( * V_3 ) ) ;
if ( ! V_1 ) {
V_8 = - V_42 ;
goto V_38;
}
V_5 = F_22 ( V_7 ) ;
if ( ! V_5 )
return - V_51 ;
V_3 = V_1 -> V_3 ;
V_3 -> V_1 = V_1 ;
V_3 -> V_9 = V_9 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_7 = V_7 ;
F_23 ( V_7 , V_1 ) ;
V_8 = F_9 ( V_3 , V_32 ) ;
if ( V_8 ) {
F_3 ( V_7 , L_11 ) ;
goto V_52;
}
V_3 -> V_53 = F_24 ( V_7 , NULL ) ;
if ( F_15 ( V_3 -> V_53 ) ) {
F_3 ( V_7 , L_12 ) ;
F_25 ( V_1 ) ;
return F_16 ( V_3 -> V_53 ) ;
}
V_8 = F_26 ( V_3 -> V_53 ) ;
if ( V_8 ) {
F_3 ( & V_1 -> V_7 , L_13 ) ;
F_25 ( V_1 ) ;
return V_8 ;
}
V_8 = F_27 ( V_1 ) ;
if ( V_8 ) {
F_3 ( V_7 , L_14 ) ;
goto V_54;
}
return V_8 ;
V_54:
F_28 ( V_3 -> V_53 ) ;
V_52:
F_25 ( V_1 ) ;
V_38:
return V_8 ;
}
static int F_29 ( struct V_31 * V_32 )
{
struct V_1 * V_1 = F_30 ( V_32 ) ;
struct V_2 * V_3 = V_1 -> V_3 ;
F_28 ( V_3 -> V_53 ) ;
F_31 ( V_1 ) ;
F_25 ( V_1 ) ;
return 0 ;
}
