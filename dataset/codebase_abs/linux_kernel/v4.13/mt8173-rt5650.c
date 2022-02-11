static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
int V_9 , V_10 ;
switch ( V_11 . V_12 ) {
case V_13 :
V_8 = V_14 ;
break;
case V_15 :
V_8 = F_2 ( V_4 ) * 256 ;
break;
default:
V_8 = V_14 ;
break;
}
for ( V_9 = 0 ; V_9 < V_6 -> V_16 ; V_9 ++ ) {
struct V_17 * V_18 = V_6 -> V_19 [ V_9 ] ;
V_10 = F_3 ( V_18 , 0 , 0 , V_8 ,
F_2 ( V_4 ) * 512 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_4 ( V_18 , 1 ,
F_2 ( V_4 ) * 512 ,
V_20 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_5 ( struct V_5 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
struct V_24 * V_25 = V_21 -> V_19 [ 0 ] -> V_25 ;
const char * V_26 = V_21 -> V_19 [ 1 ] -> V_27 ;
int V_10 ;
F_6 ( V_25 ,
V_28 ,
V_29 ) ;
if ( ! strcmp ( V_26 , L_1 ) ) {
F_6 ( V_25 ,
V_30 ,
V_29 ) ;
} else if ( ! strcmp ( V_26 , L_2 ) ) {
F_6 ( V_25 ,
V_30 ,
V_31 ) ;
} else {
F_7 ( V_23 -> V_32 ,
L_3 ) ;
F_6 ( V_25 ,
V_30 ,
V_29 ) ;
}
V_10 = F_8 ( V_23 , L_4 ,
V_33 | V_34 |
V_35 | V_36 |
V_37 | V_38 ,
& V_39 , NULL , 0 ) ;
if ( V_10 ) {
F_9 ( V_23 -> V_32 , L_5 , V_10 ) ;
return V_10 ;
}
return F_10 ( V_25 ,
& V_39 ,
& V_39 ,
& V_39 ) ;
}
static int F_11 ( struct V_40 * V_41 )
{
struct V_22 * V_23 = & V_42 ;
struct V_43 * V_44 ;
struct V_43 * V_45 ;
const char * V_26 ;
int V_9 , V_10 ;
V_44 = F_12 ( V_41 -> V_32 . V_46 ,
L_6 , 0 ) ;
if ( ! V_44 ) {
F_9 ( & V_41 -> V_32 , L_7 ) ;
return - V_47 ;
}
for ( V_9 = 0 ; V_9 < V_23 -> V_48 ; V_9 ++ ) {
if ( V_49 [ V_9 ] . V_50 )
continue;
V_49 [ V_9 ] . V_51 = V_44 ;
}
V_52 [ 0 ] . V_46 =
F_12 ( V_41 -> V_32 . V_46 , L_8 , 0 ) ;
if ( ! V_52 [ 0 ] . V_46 ) {
F_9 ( & V_41 -> V_32 ,
L_9 ) ;
return - V_47 ;
}
V_52 [ 1 ] . V_46 = V_52 [ 0 ] . V_46 ;
if ( F_13 ( V_44 , L_10 ) ) {
V_45 = F_14 ( V_41 -> V_32 . V_46 , L_10 ) ;
if ( ! V_45 ) {
F_9 ( & V_41 -> V_32 ,
L_11 ,
V_53 ) ;
return - V_47 ;
}
V_10 = F_15 ( V_45 , & V_26 ) ;
if ( V_10 < 0 ) {
F_9 ( & V_41 -> V_32 ,
L_12 ,
V_53 , V_10 ) ;
return V_10 ;
}
V_52 [ 1 ] . V_54 = V_26 ;
}
if ( F_16 ( & V_41 -> V_32 , L_13 ) ) {
V_10 = F_17 ( & V_41 -> V_32 ,
L_13 ,
& V_11 . V_12 ) ;
if ( V_10 ) {
F_9 ( & V_41 -> V_32 ,
L_14 ,
V_53 , V_10 ) ;
}
}
V_49 [ V_55 ] . V_56 =
F_12 ( V_41 -> V_32 . V_46 , L_8 , 1 ) ;
if ( ! V_49 [ V_55 ] . V_56 ) {
F_9 ( & V_41 -> V_32 ,
L_9 ) ;
return - V_47 ;
}
V_23 -> V_32 = & V_41 -> V_32 ;
F_18 ( V_41 , V_23 ) ;
V_10 = F_19 ( & V_41 -> V_32 , V_23 ) ;
if ( V_10 )
F_9 ( & V_41 -> V_32 , L_14 ,
V_53 , V_10 ) ;
return V_10 ;
}
