int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( V_2 -> V_7 [ V_5 ] )
F_2 ( V_2 -> V_7 [ V_5 ] , V_4 ) ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ )
if ( V_2 -> V_9 [ V_5 ] )
F_3 ( V_2 -> V_9 [ V_5 ] , V_4 ) ;
return 0 ;
}
static int F_4 ( struct V_10 * V_11 ,
struct V_10 * V_12 ,
void * V_13 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
struct V_14 * V_15 = V_13 ;
unsigned int V_5 , V_16 = 0 , V_17 = 0 , V_18 = 0 ;
struct V_19 * V_20 = V_15 -> V_21 ;
struct V_22 * V_23 = NULL ;
struct V_22 * V_24 = NULL ;
struct V_25 * V_26 = V_2 -> V_13 . V_27 ;
unsigned int V_28 = V_2 -> V_13 . V_29 ;
V_20 -> V_2 = V_2 ;
for ( V_5 = 0 ; V_5 < V_28 ; V_5 ++ ) {
switch ( V_26 [ V_5 ] . type ) {
case V_30 :
V_2 -> V_7 [ V_17 ++ ] =
F_6 ( V_2 -> V_11 , V_15 , V_26 [ V_5 ] . V_31 ,
V_2 -> V_32 + V_26 [ V_5 ] . V_33 ) ;
break;
case V_34 :
case V_35 :
V_2 -> V_9 [ V_16 ++ ] =
F_7 ( V_2 -> V_11 , V_15 , V_26 [ V_5 ] . V_31 ,
V_2 -> V_32 + V_26 [ V_5 ] . V_33 ) ;
break;
case V_36 :
case V_37 :
break;
default:
F_8 ( L_1 ) ;
return 1 ;
}
}
for ( V_5 = 0 ; V_5 < V_28 ; V_5 ++ ) {
enum V_38 V_39 = V_40 ;
if ( V_18 < V_16 )
V_39 = V_41 ;
switch ( V_26 [ V_5 ] . type ) {
case V_34 :
case V_35 :
case V_30 :
break;
case V_37 :
V_23 = F_9 ( V_15 , V_2 -> V_11 ,
V_26 [ V_5 ] . V_31 ,
V_2 -> V_32 + V_26 [ V_5 ] . V_33 ,
1 ) ;
if ( ! V_23 ) {
F_8 ( L_2 ) ;
break;
}
break;
case V_36 :
V_24 = F_10 ( V_15 , V_2 -> V_11 ,
V_26 [ V_5 ] . V_31 ,
V_2 -> V_32 + V_26 [ V_5 ] . V_33 ,
( 1 << V_16 ) - 1 ,
V_39 ) ;
if ( ! V_24 ) {
F_8 ( L_3 ) ;
break;
}
break;
default:
F_8 ( L_4 ) ;
return 1 ;
}
if ( V_18 < V_16 && V_24 ) {
F_11 ( V_15 , V_2 -> V_9 [ V_18 ] ,
V_24 , V_23 ) ;
V_18 ++ ;
V_23 = NULL ;
V_24 = NULL ;
}
}
F_12 ( V_15 , V_18 ) ;
V_15 -> V_42 = 1 ;
return 0 ;
}
static void F_13 ( struct V_10 * V_11 , struct V_10 * V_12 ,
void * V_13 )
{
}
static int F_14 ( struct V_43 * V_44 )
{
struct V_10 * V_11 = & V_44 -> V_11 ;
struct V_45 * V_46 = V_11 -> V_47 ;
struct V_45 * V_48 ;
struct V_1 * V_2 ;
struct V_49 * V_50 ;
unsigned int V_5 ;
V_2 = F_15 ( V_11 , sizeof( * V_2 ) , V_51 ) ;
if ( ! V_2 ) {
F_8 ( L_5 ) ;
return - V_52 ;
}
V_2 -> V_11 = V_11 ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ )
V_2 -> V_53 [ V_5 ] . V_54 = V_55 ;
F_16 ( ! F_17 ( V_56 , V_46 ) -> V_13 ) ;
memcpy ( & V_2 -> V_13 , F_17 ( V_56 , V_46 ) -> V_13 ,
sizeof( struct V_57 ) ) ;
V_50 = F_18 ( V_44 , V_58 , 0 ) ;
if ( V_50 == NULL ) {
F_8 ( L_6 ) ;
return - V_59 ;
}
V_2 -> V_32 = F_19 ( V_11 , V_50 -> V_60 , F_20 ( V_50 ) ) ;
if ( V_2 -> V_32 == NULL ) {
F_8 ( L_7 ) ;
return - V_59 ;
}
V_2 -> V_61 = F_21 ( V_11 , L_8 ) ;
if ( F_22 ( V_2 -> V_61 ) ) {
F_8 ( L_9 ) ;
return F_23 ( V_2 -> V_61 ) ;
}
V_2 -> V_62 = F_21 ( V_11 , L_10 ) ;
if ( F_22 ( V_2 -> V_62 ) ) {
F_8 ( L_11 ) ;
return F_23 ( V_2 -> V_62 ) ;
}
V_2 -> V_63 = F_21 ( V_11 , L_12 ) ;
if ( F_22 ( V_2 -> V_63 ) ) {
F_8 ( L_13 ) ;
return F_23 ( V_2 -> V_63 ) ;
}
V_2 -> V_64 = F_21 ( V_11 , L_14 ) ;
if ( F_22 ( V_2 -> V_64 ) ) {
F_8 ( L_15 ) ;
return F_23 ( V_2 -> V_64 ) ;
}
V_2 -> V_65 = F_24 ( V_11 , L_16 ) ;
if ( ! F_22 ( V_2 -> V_65 ) )
F_25 ( V_2 -> V_65 ) ;
V_2 -> V_66 = F_24 ( V_11 , L_17 ) ;
if ( ! F_22 ( V_2 -> V_66 ) )
F_25 ( V_2 -> V_66 ) ;
V_48 = F_26 ( V_44 -> V_11 . V_47 , L_18 , 0 ) ;
if ( V_48 )
V_2 -> V_67 [ V_68 ] = F_27 ( V_48 ) ;
F_28 ( V_48 ) ;
V_48 = F_26 ( V_44 -> V_11 . V_47 , L_18 , 1 ) ;
if ( V_48 )
V_2 -> V_67 [ V_69 ] = F_27 ( V_48 ) ;
F_28 ( V_48 ) ;
F_29 ( V_44 , V_2 ) ;
return F_30 ( & V_44 -> V_11 , & V_70 ) ;
}
static int F_31 ( struct V_43 * V_44 )
{
F_32 ( & V_44 -> V_11 , & V_70 ) ;
return 0 ;
}
