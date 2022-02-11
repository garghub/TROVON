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
const struct V_3 * V_4 ,
T_1 * V_6 )
{
if ( ! V_4 )
return 0 ;
V_2 -> V_3 = F_11 ( V_4 , sizeof( * V_4 ) , V_9 ) ;
if ( ! V_2 -> V_3 )
return - V_10 ;
V_2 -> V_3 -> V_6 = V_6 ;
return 0 ;
}
static int F_12 ( struct V_11 * V_12 , int V_13 ,
const struct V_3 * V_4 , T_1 * V_6 ,
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
V_2 -> V_28 . V_30 = V_12 -> V_30 ;
V_2 -> V_28 . V_31 = V_12 -> V_31 ;
V_22 = F_15 (
& V_2 -> V_28 , V_4 -> V_32 ,
V_12 , V_4 -> V_32 ,
V_4 -> V_33 ) ;
if ( V_22 < 0 )
goto V_34;
if ( V_12 -> V_35 && V_4 -> V_36 ) {
F_16 (parent->of_node, np) {
if ( F_17 ( V_21 , V_4 -> V_36 ) ) {
V_2 -> V_28 . V_35 = V_21 ;
break;
}
}
}
if ( V_4 -> V_37 ) {
V_22 = F_18 ( V_2 ,
V_4 -> V_38 , V_4 -> V_37 ) ;
if ( V_22 )
goto V_39;
}
V_22 = F_10 ( V_2 , V_4 , V_6 ) ;
if ( V_22 )
goto V_39;
for ( V_23 = 0 ; V_23 < V_4 -> V_26 ; V_23 ++ ) {
V_19 [ V_23 ] . V_24 = V_4 -> V_40 [ V_23 ] . V_24 ;
V_19 [ V_23 ] . V_41 = V_4 -> V_40 [ V_23 ] . V_41 ;
if ( ( V_4 -> V_40 [ V_23 ] . V_41 & V_42 ) && V_15 ) {
V_19 [ V_23 ] . V_12 = V_15 ;
V_19 [ V_23 ] . V_43 = V_15 -> V_43 +
V_4 -> V_40 [ V_23 ] . V_43 ;
V_19 [ V_23 ] . V_44 = V_15 -> V_43 +
V_4 -> V_40 [ V_23 ] . V_44 ;
} else if ( V_4 -> V_40 [ V_23 ] . V_41 & V_45 ) {
if ( V_18 ) {
F_8 ( V_4 -> V_40 [ V_23 ] . V_43 !=
V_4 -> V_40 [ V_23 ] . V_44 ) ;
V_19 [ V_23 ] . V_43 = V_19 [ V_23 ] . V_44 = F_19 (
V_18 , V_4 -> V_40 [ V_23 ] . V_43 ) ;
} else {
V_19 [ V_23 ] . V_43 = V_16 +
V_4 -> V_40 [ V_23 ] . V_43 ;
V_19 [ V_23 ] . V_44 = V_16 +
V_4 -> V_40 [ V_23 ] . V_44 ;
}
} else {
V_19 [ V_23 ] . V_12 = V_4 -> V_40 [ V_23 ] . V_12 ;
V_19 [ V_23 ] . V_43 = V_4 -> V_40 [ V_23 ] . V_43 ;
V_19 [ V_23 ] . V_44 = V_4 -> V_40 [ V_23 ] . V_44 ;
}
if ( ! V_4 -> V_46 ) {
V_22 = F_20 ( & V_19 [ V_23 ] ) ;
if ( V_22 )
goto V_39;
}
}
V_22 = F_21 ( V_2 , V_19 , V_4 -> V_26 ) ;
if ( V_22 )
goto V_39;
V_22 = F_22 ( V_2 ) ;
if ( V_22 )
goto V_39;
if ( V_4 -> V_47 )
V_47 ( & V_2 -> V_28 ) ;
F_23 ( V_19 ) ;
return 0 ;
V_39:
F_24 ( & V_2 -> V_28 ,
V_4 -> V_32 ,
V_4 -> V_33 ) ;
V_34:
F_23 ( V_19 ) ;
V_27:
F_25 ( V_2 ) ;
V_25:
return V_22 ;
}
int F_26 ( struct V_11 * V_12 , int V_13 ,
const struct V_3 * V_48 , int V_49 ,
struct V_14 * V_15 ,
int V_16 , struct V_17 * V_18 )
{
int V_50 ;
int V_22 ;
T_1 * V_51 ;
V_51 = F_27 ( V_49 , sizeof( * V_51 ) , V_9 ) ;
if ( ! V_51 )
return - V_10 ;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ ) {
F_28 ( & V_51 [ V_50 ] , 0 ) ;
V_22 = F_12 ( V_12 , V_13 , V_48 + V_50 , V_51 + V_50 , V_15 ,
V_16 , V_18 ) ;
if ( V_22 )
goto V_52;
}
return 0 ;
V_52:
if ( V_50 )
F_29 ( V_12 ) ;
else
F_23 ( V_51 ) ;
return V_22 ;
}
static int F_30 ( struct V_11 * V_28 , void * V_53 )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
T_1 * * V_6 = V_53 ;
if ( V_28 -> type != & V_29 )
return 0 ;
V_2 = F_31 ( V_28 ) ;
V_4 = F_2 ( V_2 ) ;
F_24 ( V_28 , V_4 -> V_32 ,
V_4 -> V_33 ) ;
if ( ! * V_6 || ( V_4 -> V_6 < * V_6 ) )
* V_6 = V_4 -> V_6 ;
F_32 ( V_2 ) ;
return 0 ;
}
void F_29 ( struct V_11 * V_12 )
{
T_1 * V_51 = NULL ;
F_33 ( V_12 , & V_51 , F_30 ) ;
F_23 ( V_51 ) ;
}
int F_34 ( const char * V_4 , const char * * V_54 , T_2 V_55 )
{
struct V_3 V_56 ;
struct V_11 * V_28 ;
struct V_1 * V_2 ;
int V_50 ;
V_28 = F_35 ( & V_57 , NULL , V_4 ) ;
if ( ! V_28 ) {
F_36 ( V_58 L_1 , V_4 ) ;
return - V_59 ;
}
V_2 = F_31 ( V_28 ) ;
memcpy ( & V_56 , F_2 ( V_2 ) , sizeof( V_56 ) ) ;
F_8 ( ! V_56 . V_7 ) ;
for ( V_50 = 0 ; V_50 < V_55 ; V_50 ++ ) {
V_56 . V_24 = V_54 [ V_50 ] ;
if ( F_12 ( V_2 -> V_28 . V_12 , - 1 , & V_56 ,
V_56 . V_6 , NULL , 0 , NULL ) )
F_37 ( V_28 , L_2 ,
V_54 [ V_50 ] ) ;
}
return 0 ;
}
