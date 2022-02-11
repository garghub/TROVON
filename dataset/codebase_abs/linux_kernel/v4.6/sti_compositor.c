static int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_4 ;
unsigned int V_9 , V_10 = 0 , V_11 = 0 , V_12 = 0 ;
struct V_13 * V_14 = V_8 -> V_15 ;
struct V_16 * V_17 = NULL ;
struct V_16 * V_18 = NULL ;
struct V_19 * V_20 = V_6 -> V_4 . V_21 ;
unsigned int V_22 = V_6 -> V_4 . V_23 ;
V_14 -> V_6 = V_6 ;
for ( V_9 = 0 ; V_9 < V_22 ; V_9 ++ ) {
switch ( V_20 [ V_9 ] . type ) {
case V_24 :
V_6 -> V_25 [ V_11 ++ ] =
F_3 ( V_6 -> V_2 , V_8 , V_20 [ V_9 ] . V_26 ,
V_6 -> V_27 + V_20 [ V_9 ] . V_28 ) ;
break;
case V_29 :
case V_30 :
V_6 -> V_31 [ V_10 ++ ] =
F_4 ( V_6 -> V_2 , V_8 , V_20 [ V_9 ] . V_26 ,
V_6 -> V_27 + V_20 [ V_9 ] . V_28 ) ;
break;
case V_32 :
case V_33 :
break;
default:
F_5 ( L_1 ) ;
return 1 ;
}
}
for ( V_9 = 0 ; V_9 < V_22 ; V_9 ++ ) {
enum V_34 V_35 = V_36 ;
if ( V_12 < V_10 )
V_35 = V_37 ;
switch ( V_20 [ V_9 ] . type ) {
case V_29 :
case V_30 :
case V_24 :
break;
case V_33 :
V_17 = F_6 ( V_8 , V_6 -> V_2 ,
V_20 [ V_9 ] . V_26 ,
V_6 -> V_27 + V_20 [ V_9 ] . V_28 ,
1 ) ;
if ( ! V_17 ) {
F_5 ( L_2 ) ;
break;
}
break;
case V_32 :
V_18 = F_7 ( V_8 , V_6 -> V_2 ,
V_20 [ V_9 ] . V_26 ,
V_6 -> V_27 + V_20 [ V_9 ] . V_28 ,
( 1 << V_10 ) - 1 ,
V_35 ) ;
if ( ! V_18 ) {
F_5 ( L_3 ) ;
break;
}
break;
default:
F_5 ( L_4 ) ;
return 1 ;
}
if ( V_12 < V_10 && V_18 ) {
F_8 ( V_8 , V_6 -> V_31 [ V_12 ] ,
V_18 , V_17 ) ;
V_12 ++ ;
V_17 = NULL ;
V_18 = NULL ;
}
}
F_9 ( V_8 , V_12 ) ;
V_8 -> V_38 = 1 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , struct V_1 * V_3 ,
void * V_4 )
{
}
static int F_11 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = & V_40 -> V_2 ;
struct V_41 * V_42 = V_2 -> V_43 ;
struct V_41 * V_44 ;
struct V_5 * V_6 ;
struct V_45 * V_46 ;
V_6 = F_12 ( V_2 , sizeof( * V_6 ) , V_47 ) ;
if ( ! V_6 ) {
F_5 ( L_5 ) ;
return - V_48 ;
}
V_6 -> V_2 = V_2 ;
V_6 -> V_49 . V_50 = V_51 ;
F_13 ( ! F_14 ( V_52 , V_42 ) -> V_4 ) ;
memcpy ( & V_6 -> V_4 , F_14 ( V_52 , V_42 ) -> V_4 ,
sizeof( struct V_53 ) ) ;
V_46 = F_15 ( V_40 , V_54 , 0 ) ;
if ( V_46 == NULL ) {
F_5 ( L_6 ) ;
return - V_55 ;
}
V_6 -> V_27 = F_16 ( V_2 , V_46 -> V_56 , F_17 ( V_46 ) ) ;
if ( V_6 -> V_27 == NULL ) {
F_5 ( L_7 ) ;
return - V_55 ;
}
V_6 -> V_57 = F_18 ( V_2 , L_8 ) ;
if ( F_19 ( V_6 -> V_57 ) ) {
F_5 ( L_9 ) ;
return F_20 ( V_6 -> V_57 ) ;
}
V_6 -> V_58 = F_18 ( V_2 , L_10 ) ;
if ( F_19 ( V_6 -> V_58 ) ) {
F_5 ( L_11 ) ;
return F_20 ( V_6 -> V_58 ) ;
}
V_6 -> V_59 = F_18 ( V_2 , L_12 ) ;
if ( F_19 ( V_6 -> V_59 ) ) {
F_5 ( L_13 ) ;
return F_20 ( V_6 -> V_59 ) ;
}
V_6 -> V_60 = F_18 ( V_2 , L_14 ) ;
if ( F_19 ( V_6 -> V_60 ) ) {
F_5 ( L_15 ) ;
return F_20 ( V_6 -> V_60 ) ;
}
V_6 -> V_61 = F_21 ( V_2 , L_16 ) ;
if ( ! F_19 ( V_6 -> V_61 ) )
F_22 ( V_6 -> V_61 ) ;
V_6 -> V_62 = F_21 ( V_2 , L_17 ) ;
if ( ! F_19 ( V_6 -> V_62 ) )
F_22 ( V_6 -> V_62 ) ;
V_44 = F_23 ( V_40 -> V_2 . V_43 , L_18 , 0 ) ;
if ( V_44 )
V_6 -> V_63 = F_24 ( V_44 ) ;
V_44 = F_23 ( V_40 -> V_2 . V_43 , L_18 , 1 ) ;
if ( V_44 )
V_6 -> V_64 = F_24 ( V_44 ) ;
F_25 ( V_40 , V_6 ) ;
return F_26 ( & V_40 -> V_2 , & V_65 ) ;
}
static int F_27 ( struct V_39 * V_40 )
{
F_28 ( & V_40 -> V_2 , & V_65 ) ;
return 0 ;
}
