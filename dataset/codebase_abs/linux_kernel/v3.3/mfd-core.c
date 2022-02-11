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
int V_16 )
{
struct V_14 * V_17 ;
struct V_1 * V_2 ;
int V_18 = - V_10 ;
int V_19 ;
V_2 = F_13 ( V_4 -> V_20 , V_13 + V_4 -> V_13 ) ;
if ( ! V_2 )
goto V_21;
V_17 = F_14 ( sizeof( * V_17 ) * V_4 -> V_22 , V_9 ) ;
if ( ! V_17 )
goto V_23;
V_2 -> V_24 . V_12 = V_12 ;
if ( V_4 -> V_25 ) {
V_18 = F_15 ( V_2 ,
V_4 -> V_26 , V_4 -> V_25 ) ;
if ( V_18 )
goto V_27;
}
V_18 = F_10 ( V_2 , V_4 ) ;
if ( V_18 )
goto V_27;
for ( V_19 = 0 ; V_19 < V_4 -> V_22 ; V_19 ++ ) {
V_17 [ V_19 ] . V_20 = V_4 -> V_28 [ V_19 ] . V_20 ;
V_17 [ V_19 ] . V_29 = V_4 -> V_28 [ V_19 ] . V_29 ;
if ( ( V_4 -> V_28 [ V_19 ] . V_29 & V_30 ) && V_15 ) {
V_17 [ V_19 ] . V_12 = V_15 ;
V_17 [ V_19 ] . V_31 = V_15 -> V_31 +
V_4 -> V_28 [ V_19 ] . V_31 ;
V_17 [ V_19 ] . V_32 = V_15 -> V_31 +
V_4 -> V_28 [ V_19 ] . V_32 ;
} else if ( V_4 -> V_28 [ V_19 ] . V_29 & V_33 ) {
V_17 [ V_19 ] . V_31 = V_16 +
V_4 -> V_28 [ V_19 ] . V_31 ;
V_17 [ V_19 ] . V_32 = V_16 +
V_4 -> V_28 [ V_19 ] . V_32 ;
} else {
V_17 [ V_19 ] . V_12 = V_4 -> V_28 [ V_19 ] . V_12 ;
V_17 [ V_19 ] . V_31 = V_4 -> V_28 [ V_19 ] . V_31 ;
V_17 [ V_19 ] . V_32 = V_4 -> V_28 [ V_19 ] . V_32 ;
}
if ( ! V_4 -> V_34 ) {
V_18 = F_16 ( & V_17 [ V_19 ] ) ;
if ( V_18 )
goto V_27;
}
}
V_18 = F_17 ( V_2 , V_17 , V_4 -> V_22 ) ;
if ( V_18 )
goto V_27;
V_18 = F_18 ( V_2 ) ;
if ( V_18 )
goto V_27;
if ( V_4 -> V_35 )
V_35 ( & V_2 -> V_24 ) ;
F_19 ( V_17 ) ;
return 0 ;
V_27:
F_19 ( V_17 ) ;
V_23:
F_20 ( V_2 ) ;
V_21:
return V_18 ;
}
int F_21 ( struct V_11 * V_12 , int V_13 ,
struct V_3 * V_36 , int V_37 ,
struct V_14 * V_15 ,
int V_16 )
{
int V_38 ;
int V_18 = 0 ;
T_1 * V_39 ;
V_39 = F_22 ( sizeof( * V_39 ) , V_37 , V_9 ) ;
if ( ! V_39 )
return - V_10 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
F_23 ( & V_39 [ V_38 ] , 0 ) ;
V_36 [ V_38 ] . V_6 = & V_39 [ V_38 ] ;
V_18 = F_12 ( V_12 , V_13 , V_36 + V_38 , V_15 , V_16 ) ;
if ( V_18 )
break;
}
if ( V_18 )
F_24 ( V_12 ) ;
return V_18 ;
}
static int F_25 ( struct V_11 * V_24 , void * V_40 )
{
struct V_1 * V_2 = F_26 ( V_24 ) ;
const struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 * * V_6 = V_40 ;
if ( ! * V_6 || ( V_4 -> V_6 < * V_6 ) )
* V_6 = V_4 -> V_6 ;
F_27 ( V_2 ) ;
return 0 ;
}
void F_24 ( struct V_11 * V_12 )
{
T_1 * V_39 = NULL ;
F_28 ( V_12 , & V_39 , F_25 ) ;
F_19 ( V_39 ) ;
}
int F_29 ( const char * V_4 , const char * * V_41 , T_2 V_42 )
{
struct V_3 V_43 ;
struct V_11 * V_24 ;
struct V_1 * V_2 ;
int V_38 ;
V_24 = F_30 ( & V_44 , NULL , V_4 ) ;
if ( ! V_24 ) {
F_31 ( V_45 L_1 , V_4 ) ;
return - V_46 ;
}
V_2 = F_26 ( V_24 ) ;
memcpy ( & V_43 , F_2 ( V_2 ) , sizeof( V_43 ) ) ;
F_8 ( ! V_43 . V_7 ) ;
for ( V_38 = 0 ; V_38 < V_42 ; V_38 ++ ) {
V_43 . V_20 = V_41 [ V_38 ] ;
if ( F_12 ( V_2 -> V_24 . V_12 , - 1 , & V_43 , NULL , 0 ) )
F_32 ( V_24 , L_2 ,
V_41 [ V_38 ] ) ;
}
return 0 ;
}
