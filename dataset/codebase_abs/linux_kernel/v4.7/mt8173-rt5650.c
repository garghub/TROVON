static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 , V_9 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_10 ; V_8 ++ ) {
struct V_11 * V_12 = V_6 -> V_13 [ V_8 ] ;
V_9 = F_2 ( V_12 , 0 , 0 , V_14 ,
F_3 ( V_4 ) * 512 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_4 ( V_12 , 1 ,
F_3 ( V_4 ) * 512 ,
V_15 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_5 ( struct V_5 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_19 * V_20 = V_16 -> V_13 [ 0 ] -> V_20 ;
const char * V_21 = V_16 -> V_13 [ 1 ] -> V_22 ;
int V_9 ;
F_6 ( V_20 ,
V_23 ,
V_24 ) ;
if ( ! strcmp ( V_21 , L_1 ) ) {
F_6 ( V_20 ,
V_25 ,
V_24 ) ;
} else if ( ! strcmp ( V_21 , L_2 ) ) {
F_6 ( V_20 ,
V_25 ,
V_26 ) ;
} else {
F_7 ( V_18 -> V_27 ,
L_3 ) ;
F_6 ( V_20 ,
V_25 ,
V_24 ) ;
}
V_9 = F_8 ( V_18 , L_4 ,
V_28 | V_29 |
V_30 | V_31 |
V_32 | V_33 ,
& V_34 , NULL , 0 ) ;
if ( V_9 ) {
F_9 ( V_18 -> V_27 , L_5 , V_9 ) ;
return V_9 ;
}
return F_10 ( V_20 ,
& V_34 ,
& V_34 ,
& V_34 ) ;
}
static int F_11 ( struct V_35 * V_36 )
{
struct V_17 * V_18 = & V_37 ;
struct V_38 * V_39 ;
struct V_38 * V_40 ;
const char * V_21 ;
int V_8 , V_9 ;
V_39 = F_12 ( V_36 -> V_27 . V_41 ,
L_6 , 0 ) ;
if ( ! V_39 ) {
F_9 ( & V_36 -> V_27 , L_7 ) ;
return - V_42 ;
}
for ( V_8 = 0 ; V_8 < V_18 -> V_43 ; V_8 ++ ) {
if ( V_44 [ V_8 ] . V_45 )
continue;
V_44 [ V_8 ] . V_46 = V_39 ;
}
V_47 [ 0 ] . V_41 =
F_12 ( V_36 -> V_27 . V_41 , L_8 , 0 ) ;
if ( ! V_47 [ 0 ] . V_41 ) {
F_9 ( & V_36 -> V_27 ,
L_9 ) ;
return - V_42 ;
}
V_47 [ 1 ] . V_41 = V_47 [ 0 ] . V_41 ;
if ( F_13 ( V_39 , L_10 ) ) {
V_40 = F_14 ( V_36 -> V_27 . V_41 , L_10 ) ;
if ( ! V_40 ) {
F_9 ( & V_36 -> V_27 ,
L_11 ,
V_48 ) ;
return - V_42 ;
}
V_9 = F_15 ( V_40 , & V_21 ) ;
if ( V_9 < 0 ) {
F_9 ( & V_36 -> V_27 ,
L_12 ,
V_48 , V_9 ) ;
return V_9 ;
}
V_47 [ 1 ] . V_49 = V_21 ;
}
V_18 -> V_27 = & V_36 -> V_27 ;
F_16 ( V_36 , V_18 ) ;
V_9 = F_17 ( & V_36 -> V_27 , V_18 ) ;
if ( V_9 )
F_9 ( & V_36 -> V_27 , L_13 ,
V_48 , V_9 ) ;
return V_9 ;
}
