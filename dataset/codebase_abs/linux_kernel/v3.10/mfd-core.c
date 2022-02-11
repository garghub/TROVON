int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
if ( F_3 ( V_4 -> V_6 ) == 1 )
V_5 = V_4 -> V_7 ( V_2 ) ;
if ( V_5 )
F_4 ( V_4 -> V_6 ) ;
return V_5 ;
}
int F_5 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
if ( F_6 ( V_4 -> V_6 ) == 0 )
V_5 = V_4 -> V_8 ( V_2 ) ;
if ( V_5 )
F_7 ( V_4 -> V_6 ) ;
F_8 ( F_9 ( V_4 -> V_6 ) < 0 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( ! V_4 )
return 0 ;
V_2 -> V_3 = F_11 ( V_4 , sizeof( * V_4 ) , V_9 ) ;
if ( ! V_2 -> V_3 )
return - V_10 ;
return 0 ;
}
static int F_12 ( struct V_11 * V_12 , int V_13 ,
const struct V_3 * V_4 ,
struct V_14 * V_15 ,
int V_16 , struct V_17 * V_18 )
{
struct V_14 * V_19 ;
struct V_1 * V_2 ;
struct V_20 * V_21 = NULL ;
int V_22 = - V_10 ;
int V_23 ;
V_2 = F_13 ( V_4 -> V_24 , V_13 + V_4 -> V_13 ) ;
if ( ! V_2 )
goto V_25;
V_19 = F_14 ( sizeof( * V_19 ) * V_4 -> V_26 , V_9 ) ;
if ( ! V_19 )
goto V_27;
V_2 -> V_28 . V_12 = V_12 ;
V_2 -> V_28 . type = & V_29 ;
if ( V_12 -> V_30 && V_4 -> V_31 ) {
F_15 (parent->of_node, np) {
if ( F_16 ( V_21 , V_4 -> V_31 ) ) {
V_2 -> V_28 . V_30 = V_21 ;
break;
}
}
}
if ( V_4 -> V_32 ) {
V_22 = F_17 ( V_2 ,
V_4 -> V_33 , V_4 -> V_32 ) ;
if ( V_22 )
goto V_34;
}
V_22 = F_10 ( V_2 , V_4 ) ;
if ( V_22 )
goto V_34;
for ( V_23 = 0 ; V_23 < V_4 -> V_26 ; V_23 ++ ) {
V_19 [ V_23 ] . V_24 = V_4 -> V_35 [ V_23 ] . V_24 ;
V_19 [ V_23 ] . V_36 = V_4 -> V_35 [ V_23 ] . V_36 ;
if ( ( V_4 -> V_35 [ V_23 ] . V_36 & V_37 ) && V_15 ) {
V_19 [ V_23 ] . V_12 = V_15 ;
V_19 [ V_23 ] . V_38 = V_15 -> V_38 +
V_4 -> V_35 [ V_23 ] . V_38 ;
V_19 [ V_23 ] . V_39 = V_15 -> V_38 +
V_4 -> V_35 [ V_23 ] . V_39 ;
} else if ( V_4 -> V_35 [ V_23 ] . V_36 & V_40 ) {
if ( V_18 ) {
F_8 ( V_4 -> V_35 [ V_23 ] . V_38 !=
V_4 -> V_35 [ V_23 ] . V_39 ) ;
V_19 [ V_23 ] . V_38 = V_19 [ V_23 ] . V_39 = F_18 (
V_18 , V_4 -> V_35 [ V_23 ] . V_38 ) ;
} else {
V_19 [ V_23 ] . V_38 = V_16 +
V_4 -> V_35 [ V_23 ] . V_38 ;
V_19 [ V_23 ] . V_39 = V_16 +
V_4 -> V_35 [ V_23 ] . V_39 ;
}
} else {
V_19 [ V_23 ] . V_12 = V_4 -> V_35 [ V_23 ] . V_12 ;
V_19 [ V_23 ] . V_38 = V_4 -> V_35 [ V_23 ] . V_38 ;
V_19 [ V_23 ] . V_39 = V_4 -> V_35 [ V_23 ] . V_39 ;
}
if ( ! V_4 -> V_41 ) {
V_22 = F_19 ( & V_19 [ V_23 ] ) ;
if ( V_22 )
goto V_34;
}
}
V_22 = F_20 ( V_2 , V_19 , V_4 -> V_26 ) ;
if ( V_22 )
goto V_34;
V_22 = F_21 ( V_2 ) ;
if ( V_22 )
goto V_34;
if ( V_4 -> V_42 )
V_42 ( & V_2 -> V_28 ) ;
F_22 ( V_19 ) ;
return 0 ;
V_34:
F_22 ( V_19 ) ;
V_27:
F_23 ( V_2 ) ;
V_25:
return V_22 ;
}
int F_24 ( struct V_11 * V_12 , int V_13 ,
struct V_3 * V_43 , int V_44 ,
struct V_14 * V_15 ,
int V_16 , struct V_17 * V_18 )
{
int V_45 ;
int V_22 = 0 ;
T_1 * V_46 ;
V_46 = F_25 ( V_44 , sizeof( * V_46 ) , V_9 ) ;
if ( ! V_46 )
return - V_10 ;
for ( V_45 = 0 ; V_45 < V_44 ; V_45 ++ ) {
F_26 ( & V_46 [ V_45 ] , 0 ) ;
V_43 [ V_45 ] . V_6 = & V_46 [ V_45 ] ;
V_22 = F_12 ( V_12 , V_13 , V_43 + V_45 , V_15 ,
V_16 , V_18 ) ;
if ( V_22 )
break;
}
if ( V_22 )
F_27 ( V_12 ) ;
return V_22 ;
}
static int F_28 ( struct V_11 * V_28 , void * V_47 )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
T_1 * * V_6 = V_47 ;
if ( V_28 -> type != & V_29 )
return 0 ;
V_2 = F_29 ( V_28 ) ;
V_4 = F_2 ( V_2 ) ;
if ( ! * V_6 || ( V_4 -> V_6 < * V_6 ) )
* V_6 = V_4 -> V_6 ;
F_30 ( V_2 ) ;
return 0 ;
}
void F_27 ( struct V_11 * V_12 )
{
T_1 * V_46 = NULL ;
F_31 ( V_12 , & V_46 , F_28 ) ;
F_22 ( V_46 ) ;
}
int F_32 ( const char * V_4 , const char * * V_48 , T_2 V_49 )
{
struct V_3 V_50 ;
struct V_11 * V_28 ;
struct V_1 * V_2 ;
int V_45 ;
V_28 = F_33 ( & V_51 , NULL , V_4 ) ;
if ( ! V_28 ) {
F_34 ( V_52 L_1 , V_4 ) ;
return - V_53 ;
}
V_2 = F_29 ( V_28 ) ;
memcpy ( & V_50 , F_2 ( V_2 ) , sizeof( V_50 ) ) ;
F_8 ( ! V_50 . V_7 ) ;
for ( V_45 = 0 ; V_45 < V_49 ; V_45 ++ ) {
V_50 . V_24 = V_48 [ V_45 ] ;
if ( F_12 ( V_2 -> V_28 . V_12 , - 1 , & V_50 , NULL , 0 ,
NULL ) )
F_35 ( V_28 , L_2 ,
V_48 [ V_45 ] ) ;
}
return 0 ;
}
