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
struct V_37 * V_38 = V_4 -> V_33 . V_39 ;
int V_40 , V_41 , V_42 ;
struct V_22 * V_17 ;
int V_6 ;
if ( ! F_8 ( V_2 , V_43 ) )
return - V_7 ;
V_17 = F_9 ( & V_4 -> V_33 , sizeof( struct V_22 ) , V_44 ) ;
if ( ! V_17 )
return - V_45 ;
F_10 ( V_4 , V_17 ) ;
if ( F_11 ( V_46 ) && V_38 ) {
enum V_47 V_14 ;
int V_48 ;
V_48 = F_12 ( V_38 , L_1 , 0 , & V_14 ) ;
if ( F_13 ( V_48 ) ) {
V_6 = F_14 ( & V_4 -> V_33 , V_48 ,
V_14 & V_49 ?
V_50 : V_51 ,
L_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
}
if ( F_15 ( V_4 , 0 ) < 0 ) {
F_16 ( & V_4 -> V_33 , L_3 ) ;
return - V_7 ;
}
V_17 -> type = V_32 -> V_52 ;
V_17 -> V_30 = 0 ;
for ( V_40 = 0 ; V_40 < V_25 [ V_17 -> type ] . V_53 ; V_40 ++ ) {
V_41 = 0 ;
V_42 = 0 ;
if ( V_36 ) {
if ( V_40 < V_36 -> V_54 ) {
V_41 = V_36 -> V_55 [ V_40 ] . V_56 ;
V_42 = V_36 -> V_55 [ V_40 ] . V_42 ;
} else
break;
}
V_17 -> V_57 [ V_40 ] =
F_17 ( V_2 , & V_4 -> V_33 , V_4 ,
V_41 , V_40 , V_42 , F_2 ,
( V_36 && V_36 -> V_55 [ V_40 ] . V_58 )
? F_4 : NULL ) ;
if ( V_17 -> V_57 [ V_40 ] == NULL ) {
V_6 = - V_7 ;
F_18 ( & V_4 -> V_33 ,
L_4
L_5 , V_40 , V_41 ) ;
goto V_59;
}
}
F_19 ( & V_4 -> V_33 ,
L_6 ,
V_40 , V_25 [ V_17 -> type ] . V_27 == V_28
? L_7 : L_8 , V_4 -> V_60 ) ;
return 0 ;
V_59:
for ( V_40 -- ; V_40 >= 0 ; V_40 -- )
F_20 ( V_17 -> V_57 [ V_40 ] ) ;
return V_6 ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_22 * V_17 = F_3 ( V_4 ) ;
const struct V_23 * V_24 = & V_25 [ V_17 -> type ] ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_24 -> V_53 ; ++ V_61 )
if ( V_17 -> V_57 [ V_61 ] ) {
F_20 ( V_17 -> V_57 [ V_61 ] ) ;
V_17 -> V_57 [ V_61 ] = NULL ;
}
return 0 ;
}
