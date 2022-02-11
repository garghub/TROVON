int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 , V_6 ;
for ( V_6 = 0 ; V_2 -> V_7 [ V_6 ] ; V_6 ++ ) {
V_5 = F_2 ( V_2 -> V_7 [ V_6 ] , V_4 ) ;
if ( V_5 )
return V_5 ;
}
for ( V_6 = 0 ; V_2 -> V_8 [ V_6 ] ; V_6 ++ ) {
V_5 = F_3 ( V_2 -> V_8 [ V_6 ] , V_4 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static int F_4 ( struct V_9 * V_10 ,
struct V_9 * V_11 ,
void * V_12 )
{
struct V_1 * V_2 = F_5 ( V_10 ) ;
struct V_13 * V_14 = V_12 ;
unsigned int V_6 , V_15 = 0 , V_16 = 0 , V_17 = 0 ;
struct V_18 * V_19 = V_14 -> V_20 ;
struct V_21 * V_22 = NULL ;
struct V_21 * V_23 = NULL ;
struct V_24 * V_25 = V_2 -> V_12 . V_26 ;
unsigned int V_27 = V_2 -> V_12 . V_28 ;
V_19 -> V_2 = V_2 ;
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ ) {
switch ( V_25 [ V_6 ] . type ) {
case V_29 :
V_2 -> V_7 [ V_16 ++ ] =
F_6 ( V_2 -> V_10 , V_14 , V_25 [ V_6 ] . V_30 ,
V_2 -> V_31 + V_25 [ V_6 ] . V_32 ) ;
break;
case V_33 :
case V_34 :
V_2 -> V_8 [ V_15 ++ ] =
F_7 ( V_2 -> V_10 , V_14 , V_25 [ V_6 ] . V_30 ,
V_2 -> V_31 + V_25 [ V_6 ] . V_32 ) ;
break;
case V_35 :
case V_36 :
break;
default:
F_8 ( L_1 ) ;
return 1 ;
}
}
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ ) {
enum V_37 V_38 = V_39 ;
if ( V_17 < V_15 )
V_38 = V_40 ;
switch ( V_25 [ V_6 ] . type ) {
case V_33 :
case V_34 :
case V_29 :
break;
case V_36 :
V_22 = F_9 ( V_14 , V_2 -> V_10 ,
V_25 [ V_6 ] . V_30 ,
V_2 -> V_31 + V_25 [ V_6 ] . V_32 ,
1 ) ;
if ( ! V_22 ) {
F_8 ( L_2 ) ;
break;
}
break;
case V_35 :
V_23 = F_10 ( V_14 , V_2 -> V_10 ,
V_25 [ V_6 ] . V_30 ,
V_2 -> V_31 + V_25 [ V_6 ] . V_32 ,
( 1 << V_15 ) - 1 ,
V_38 ) ;
if ( ! V_23 ) {
F_8 ( L_3 ) ;
break;
}
break;
default:
F_8 ( L_4 ) ;
return 1 ;
}
if ( V_17 < V_15 && V_23 ) {
F_11 ( V_14 , V_2 -> V_8 [ V_17 ] ,
V_23 , V_22 ) ;
V_17 ++ ;
V_22 = NULL ;
V_23 = NULL ;
}
}
F_12 ( V_14 , V_17 ) ;
V_14 -> V_41 = 1 ;
return 0 ;
}
static void F_13 ( struct V_9 * V_10 , struct V_9 * V_11 ,
void * V_12 )
{
}
static int F_14 ( struct V_42 * V_43 )
{
struct V_9 * V_10 = & V_43 -> V_10 ;
struct V_44 * V_45 = V_10 -> V_46 ;
struct V_44 * V_47 ;
struct V_1 * V_2 ;
struct V_48 * V_49 ;
V_2 = F_15 ( V_10 , sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 ) {
F_8 ( L_5 ) ;
return - V_51 ;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_52 . V_53 = V_54 ;
F_16 ( ! F_17 ( V_55 , V_45 ) -> V_12 ) ;
memcpy ( & V_2 -> V_12 , F_17 ( V_55 , V_45 ) -> V_12 ,
sizeof( struct V_56 ) ) ;
V_49 = F_18 ( V_43 , V_57 , 0 ) ;
if ( V_49 == NULL ) {
F_8 ( L_6 ) ;
return - V_58 ;
}
V_2 -> V_31 = F_19 ( V_10 , V_49 -> V_59 , F_20 ( V_49 ) ) ;
if ( V_2 -> V_31 == NULL ) {
F_8 ( L_7 ) ;
return - V_58 ;
}
V_2 -> V_60 = F_21 ( V_10 , L_8 ) ;
if ( F_22 ( V_2 -> V_60 ) ) {
F_8 ( L_9 ) ;
return F_23 ( V_2 -> V_60 ) ;
}
V_2 -> V_61 = F_21 ( V_10 , L_10 ) ;
if ( F_22 ( V_2 -> V_61 ) ) {
F_8 ( L_11 ) ;
return F_23 ( V_2 -> V_61 ) ;
}
V_2 -> V_62 = F_21 ( V_10 , L_12 ) ;
if ( F_22 ( V_2 -> V_62 ) ) {
F_8 ( L_13 ) ;
return F_23 ( V_2 -> V_62 ) ;
}
V_2 -> V_63 = F_21 ( V_10 , L_14 ) ;
if ( F_22 ( V_2 -> V_63 ) ) {
F_8 ( L_15 ) ;
return F_23 ( V_2 -> V_63 ) ;
}
V_2 -> V_64 = F_24 ( V_10 , L_16 ) ;
if ( ! F_22 ( V_2 -> V_64 ) )
F_25 ( V_2 -> V_64 ) ;
V_2 -> V_65 = F_24 ( V_10 , L_17 ) ;
if ( ! F_22 ( V_2 -> V_65 ) )
F_25 ( V_2 -> V_65 ) ;
V_47 = F_26 ( V_43 -> V_10 . V_46 , L_18 , 0 ) ;
if ( V_47 )
V_2 -> V_66 = F_27 ( V_47 ) ;
F_28 ( V_47 ) ;
V_47 = F_26 ( V_43 -> V_10 . V_46 , L_18 , 1 ) ;
if ( V_47 )
V_2 -> V_67 = F_27 ( V_47 ) ;
F_28 ( V_47 ) ;
F_29 ( V_43 , V_2 ) ;
return F_30 ( & V_43 -> V_10 , & V_68 ) ;
}
static int F_31 ( struct V_42 * V_43 )
{
F_32 ( & V_43 -> V_10 , & V_68 ) ;
return 0 ;
}
