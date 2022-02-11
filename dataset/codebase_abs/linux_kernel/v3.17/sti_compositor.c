static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 )
{
unsigned int V_6 , V_7 = 0 , V_8 = 0 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
switch ( V_4 [ V_6 ] . type ) {
case V_9 :
case V_10 :
V_2 -> V_11 [ V_7 ++ ] =
F_2 ( V_2 -> V_12 , V_4 [ V_6 ] . V_13 ,
V_2 -> V_14 + V_4 [ V_6 ] . V_15 ) ;
break;
case V_16 :
case V_17 :
V_2 -> V_18 [ V_8 ++ ] =
F_3 ( V_2 -> V_12 , V_4 [ V_6 ] . V_13 ,
V_2 -> V_14 + V_4 [ V_6 ] . V_15 ) ;
break;
default:
F_4 ( L_1 ) ;
return 1 ;
}
}
V_2 -> V_19 = V_7 ;
V_2 -> V_20 = V_8 ;
return 0 ;
}
static int F_5 ( struct V_21 * V_12 , struct V_21 * V_22 ,
void * V_23 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_24 * V_25 = V_23 ;
unsigned int V_6 , V_26 = 0 , V_27 = 0 ;
struct V_28 * V_29 = V_25 -> V_30 ;
struct V_31 * V_32 = NULL ;
struct V_31 * V_33 = NULL ;
V_29 -> V_2 = V_2 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_20 ; V_6 ++ ) {
if ( V_2 -> V_18 [ V_6 ] ) {
enum V_34 V_4 = V_2 -> V_18 [ V_6 ] -> V_4 ;
enum V_35 type = V_4 & V_36 ;
enum V_37 V_38 = V_39 ;
if ( V_2 -> V_11 [ V_26 ] )
V_38 = V_40 ;
switch ( type ) {
case V_41 :
V_32 = F_7 ( V_25 ,
V_2 -> V_18 [ V_6 ] ,
( 1 << V_26 ) - 1 ,
V_42 ) ;
break;
case V_43 :
case V_44 :
V_33 = F_7 ( V_25 ,
V_2 -> V_18 [ V_6 ] ,
( 1 << V_26 ) - 1 , V_38 ) ;
V_27 ++ ;
break;
case V_45 :
break;
}
if ( V_2 -> V_11 [ V_26 ] ) {
F_8 ( V_25 , V_2 -> V_11 [ V_26 ] ,
V_33 , V_32 ) ;
V_26 ++ ;
V_32 = NULL ;
}
}
}
F_9 ( V_25 , V_26 ) ;
V_25 -> V_46 = 1 ;
F_10 ( L_2 ,
V_26 , V_27 ) ;
F_10 ( L_3 ) ;
return 0 ;
}
static void F_11 ( struct V_21 * V_12 , struct V_21 * V_22 ,
void * V_23 )
{
}
static int F_12 ( struct V_47 * V_48 )
{
struct V_21 * V_12 = & V_48 -> V_12 ;
struct V_49 * V_50 = V_12 -> V_51 ;
struct V_49 * V_52 ;
struct V_1 * V_2 ;
struct V_53 * V_54 ;
int V_55 ;
V_2 = F_13 ( V_12 , sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 ) {
F_4 ( L_4 ) ;
return - V_57 ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_58 . V_59 = V_60 ;
F_14 ( ! F_15 ( V_61 , V_50 ) -> V_23 ) ;
memcpy ( & V_2 -> V_23 , F_15 ( V_61 , V_50 ) -> V_23 ,
sizeof( struct V_62 ) ) ;
V_54 = F_16 ( V_48 , V_63 , 0 ) ;
if ( V_54 == NULL ) {
F_4 ( L_5 ) ;
return - V_64 ;
}
V_2 -> V_14 = F_17 ( V_12 , V_54 -> V_65 , F_18 ( V_54 ) ) ;
if ( V_2 -> V_14 == NULL ) {
F_4 ( L_6 ) ;
return - V_64 ;
}
V_2 -> V_66 = F_19 ( V_12 , L_7 ) ;
if ( F_20 ( V_2 -> V_66 ) ) {
F_4 ( L_8 ) ;
return F_21 ( V_2 -> V_66 ) ;
}
V_2 -> V_67 = F_19 ( V_12 , L_9 ) ;
if ( F_20 ( V_2 -> V_67 ) ) {
F_4 ( L_10 ) ;
return F_21 ( V_2 -> V_67 ) ;
}
V_2 -> V_68 = F_19 ( V_12 , L_11 ) ;
if ( F_20 ( V_2 -> V_68 ) ) {
F_4 ( L_12 ) ;
return F_21 ( V_2 -> V_68 ) ;
}
V_2 -> V_69 = F_19 ( V_12 , L_13 ) ;
if ( F_20 ( V_2 -> V_69 ) ) {
F_4 ( L_14 ) ;
return F_21 ( V_2 -> V_69 ) ;
}
V_2 -> V_70 = F_22 ( V_12 , L_15 ) ;
if ( ! F_20 ( V_2 -> V_70 ) )
F_23 ( V_2 -> V_70 ) ;
V_2 -> V_71 = F_22 ( V_12 , L_16 ) ;
if ( ! F_20 ( V_2 -> V_71 ) )
F_23 ( V_2 -> V_71 ) ;
V_52 = F_24 ( V_48 -> V_12 . V_51 , L_17 , 0 ) ;
if ( V_52 )
V_2 -> V_72 = F_25 ( V_52 ) ;
V_52 = F_24 ( V_48 -> V_12 . V_51 , L_17 , 1 ) ;
if ( V_52 )
V_2 -> V_73 = F_25 ( V_52 ) ;
V_55 = F_1 ( V_2 , V_2 -> V_23 . V_74 ,
V_2 -> V_23 . V_75 ) ;
if ( V_55 )
return V_55 ;
F_26 ( V_48 , V_2 ) ;
return F_27 ( & V_48 -> V_12 , & V_76 ) ;
}
static int F_28 ( struct V_47 * V_48 )
{
F_29 ( & V_48 -> V_12 , & V_76 ) ;
return 0 ;
}
