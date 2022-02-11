static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
int V_6 = - V_7 ;
if ( V_2 -> V_8 -> V_9 ) {
struct V_10 V_11 ;
char V_12 [ 1 ] ;
V_11 . V_13 = V_4 -> V_13 ;
V_11 . V_14 = 0 ;
V_11 . V_15 = 1 ;
V_12 [ 0 ] = V_5 ;
V_11 . V_12 = V_12 ;
V_6 = V_2 -> V_8 -> V_9 ( V_2 , & V_11 , 1 ) ;
} else {
union V_16 V_17 ;
V_6 = V_2 -> V_8 -> V_18 ( V_2 , V_4 -> V_13 ,
V_4 -> V_14 ,
V_19 ,
V_5 , V_20 , & V_17 ) ;
}
return V_6 ;
}
static int F_2 ( struct V_1 * V_2 ,
void * V_4 , T_2 V_21 )
{
struct V_22 * V_17 = F_3 ( V_4 ) ;
const struct V_23 * V_24 = & V_25 [ V_17 -> type ] ;
T_1 V_26 ;
int V_6 = 0 ;
if ( V_24 -> V_27 == V_28 )
V_26 = V_21 | V_24 -> V_29 ;
else
V_26 = 1 << V_21 ;
if ( V_17 -> V_30 != V_26 ) {
V_6 = F_1 ( V_2 , V_4 , V_26 ) ;
V_17 -> V_30 = V_26 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 ,
void * V_4 , T_2 V_21 )
{
struct V_22 * V_17 = F_3 ( V_4 ) ;
V_17 -> V_30 = 0 ;
return F_1 ( V_2 , V_4 , V_17 -> V_30 ) ;
}
static int F_5 ( struct V_3 * V_4 ,
const struct V_31 * V_32 )
{
struct V_1 * V_2 = F_6 ( V_4 -> V_33 . V_34 ) ;
struct V_35 * V_36 = F_7 ( & V_4 -> V_33 ) ;
struct V_37 * V_38 = V_4 -> V_33 . V_38 ;
bool V_39 ;
struct V_40 * V_41 ;
int V_42 , V_43 , V_44 ;
struct V_22 * V_17 ;
int V_6 ;
if ( ! F_8 ( V_2 , V_45 ) )
return - V_7 ;
V_17 = F_9 ( & V_4 -> V_33 , sizeof( struct V_22 ) , V_46 ) ;
if ( ! V_17 )
return - V_47 ;
F_10 ( V_4 , V_17 ) ;
V_41 = F_11 ( & V_4 -> V_33 , L_1 , V_48 ) ;
if ( F_12 ( V_41 ) )
return F_13 ( V_41 ) ;
if ( F_14 ( V_4 , 0 ) < 0 ) {
F_15 ( & V_4 -> V_33 , L_2 ) ;
return - V_7 ;
}
V_17 -> type = V_32 -> V_49 ;
V_17 -> V_30 = 0 ;
V_39 = V_38 &&
F_16 ( V_38 , L_3 ) ;
for ( V_42 = 0 ; V_42 < V_25 [ V_17 -> type ] . V_50 ; V_42 ++ ) {
bool V_51 = false ;
V_43 = 0 ;
V_44 = 0 ;
if ( V_36 ) {
if ( V_42 < V_36 -> V_52 ) {
V_43 = V_36 -> V_53 [ V_42 ] . V_54 ;
V_44 = V_36 -> V_53 [ V_42 ] . V_44 ;
} else
break;
V_51 = V_36 -> V_53 [ V_42 ] . V_55 ;
}
V_17 -> V_56 [ V_42 ] =
F_17 ( V_2 , & V_4 -> V_33 , V_4 ,
V_43 , V_42 , V_44 , F_2 ,
( V_51 || V_39 )
? F_4 : NULL ) ;
if ( V_17 -> V_56 [ V_42 ] == NULL ) {
V_6 = - V_7 ;
F_18 ( & V_4 -> V_33 ,
L_4
L_5 , V_42 , V_43 ) ;
goto V_57;
}
}
F_19 ( & V_4 -> V_33 ,
L_6 ,
V_42 , V_25 [ V_17 -> type ] . V_27 == V_28
? L_7 : L_8 , V_4 -> V_58 ) ;
return 0 ;
V_57:
for ( V_42 -- ; V_42 >= 0 ; V_42 -- )
F_20 ( V_17 -> V_56 [ V_42 ] ) ;
return V_6 ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_22 * V_17 = F_3 ( V_4 ) ;
const struct V_23 * V_24 = & V_25 [ V_17 -> type ] ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_24 -> V_50 ; ++ V_59 )
if ( V_17 -> V_56 [ V_59 ] ) {
F_20 ( V_17 -> V_56 [ V_59 ] ) ;
V_17 -> V_56 [ V_59 ] = NULL ;
}
return 0 ;
}
static int F_22 ( struct V_60 * V_33 )
{
struct V_3 * V_4 = F_23 ( V_33 ) ;
struct V_22 * V_17 = F_3 ( V_4 ) ;
V_17 -> V_30 = 0 ;
return F_14 ( V_4 , 0 ) ;
}
