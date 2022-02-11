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
case V_18 :
V_2 -> V_19 [ V_8 ++ ] =
F_3 ( V_2 -> V_12 , V_4 [ V_6 ] . V_13 ,
V_2 -> V_14 + V_4 [ V_6 ] . V_15 ) ;
break;
default:
F_4 ( L_1 ) ;
return 1 ;
}
}
V_2 -> V_20 = V_7 ;
V_2 -> V_21 = V_8 ;
return 0 ;
}
static int F_5 ( struct V_22 * V_12 , struct V_22 * V_23 ,
void * V_24 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_25 * V_26 = V_24 ;
unsigned int V_6 , V_27 = 0 , V_28 = 0 ;
struct V_29 * V_30 = V_26 -> V_31 ;
struct V_32 * V_33 = NULL ;
struct V_32 * V_34 = NULL ;
V_30 -> V_2 = V_2 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_21 ; V_6 ++ ) {
if ( V_2 -> V_19 [ V_6 ] ) {
enum V_35 V_4 = V_2 -> V_19 [ V_6 ] -> V_4 ;
enum V_36 type = V_4 & V_37 ;
enum V_38 V_39 = V_40 ;
if ( V_27 < V_2 -> V_20 )
V_39 = V_41 ;
switch ( type ) {
case V_42 :
V_33 = F_7 ( V_26 ,
V_2 -> V_19 [ V_6 ] ,
1 , V_43 ) ;
break;
case V_44 :
case V_45 :
V_34 = F_7 ( V_26 ,
V_2 -> V_19 [ V_6 ] ,
( 1 << V_2 -> V_20 ) - 1 ,
V_39 ) ;
V_28 ++ ;
break;
case V_46 :
case V_47 :
break;
}
if ( V_27 < V_2 -> V_20 && V_34 ) {
F_8 ( V_26 , V_2 -> V_11 [ V_27 ] ,
V_34 , V_33 ) ;
V_27 ++ ;
V_33 = NULL ;
V_34 = NULL ;
}
}
}
F_9 ( V_26 , V_27 ) ;
V_26 -> V_48 = 1 ;
F_10 ( L_2 ,
V_27 , V_28 ) ;
F_10 ( L_3 ) ;
return 0 ;
}
static void F_11 ( struct V_22 * V_12 , struct V_22 * V_23 ,
void * V_24 )
{
}
static int F_12 ( struct V_49 * V_50 )
{
struct V_22 * V_12 = & V_50 -> V_12 ;
struct V_51 * V_52 = V_12 -> V_53 ;
struct V_51 * V_54 ;
struct V_1 * V_2 ;
struct V_55 * V_56 ;
int V_57 ;
V_2 = F_13 ( V_12 , sizeof( * V_2 ) , V_58 ) ;
if ( ! V_2 ) {
F_4 ( L_4 ) ;
return - V_59 ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_60 . V_61 = V_62 ;
F_14 ( ! F_15 ( V_63 , V_52 ) -> V_24 ) ;
memcpy ( & V_2 -> V_24 , F_15 ( V_63 , V_52 ) -> V_24 ,
sizeof( struct V_64 ) ) ;
V_56 = F_16 ( V_50 , V_65 , 0 ) ;
if ( V_56 == NULL ) {
F_4 ( L_5 ) ;
return - V_66 ;
}
V_2 -> V_14 = F_17 ( V_12 , V_56 -> V_67 , F_18 ( V_56 ) ) ;
if ( V_2 -> V_14 == NULL ) {
F_4 ( L_6 ) ;
return - V_66 ;
}
V_2 -> V_68 = F_19 ( V_12 , L_7 ) ;
if ( F_20 ( V_2 -> V_68 ) ) {
F_4 ( L_8 ) ;
return F_21 ( V_2 -> V_68 ) ;
}
V_2 -> V_69 = F_19 ( V_12 , L_9 ) ;
if ( F_20 ( V_2 -> V_69 ) ) {
F_4 ( L_10 ) ;
return F_21 ( V_2 -> V_69 ) ;
}
V_2 -> V_70 = F_19 ( V_12 , L_11 ) ;
if ( F_20 ( V_2 -> V_70 ) ) {
F_4 ( L_12 ) ;
return F_21 ( V_2 -> V_70 ) ;
}
V_2 -> V_71 = F_19 ( V_12 , L_13 ) ;
if ( F_20 ( V_2 -> V_71 ) ) {
F_4 ( L_14 ) ;
return F_21 ( V_2 -> V_71 ) ;
}
V_2 -> V_72 = F_22 ( V_12 , L_15 ) ;
if ( ! F_20 ( V_2 -> V_72 ) )
F_23 ( V_2 -> V_72 ) ;
V_2 -> V_73 = F_22 ( V_12 , L_16 ) ;
if ( ! F_20 ( V_2 -> V_73 ) )
F_23 ( V_2 -> V_73 ) ;
V_54 = F_24 ( V_50 -> V_12 . V_53 , L_17 , 0 ) ;
if ( V_54 )
V_2 -> V_74 = F_25 ( V_54 ) ;
V_54 = F_24 ( V_50 -> V_12 . V_53 , L_17 , 1 ) ;
if ( V_54 )
V_2 -> V_75 = F_25 ( V_54 ) ;
V_57 = F_1 ( V_2 , V_2 -> V_24 . V_76 ,
V_2 -> V_24 . V_77 ) ;
if ( V_57 )
return V_57 ;
F_26 ( V_50 , V_2 ) ;
return F_27 ( & V_50 -> V_12 , & V_78 ) ;
}
static int F_28 ( struct V_49 * V_50 )
{
F_29 ( & V_50 -> V_12 , & V_78 ) ;
return 0 ;
}
