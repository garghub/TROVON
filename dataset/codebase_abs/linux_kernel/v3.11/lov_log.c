static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_9 * V_10 , int V_11 )
{
struct V_12 * V_13 = V_4 -> V_14 ;
struct V_15 * V_16 = & V_13 -> V_17 . V_16 ;
int V_18 , V_19 = 0 , V_20 = 0 ;
V_21 ;
F_2 ( V_10 && V_11 >= V_8 -> V_22 ,
L_1 ,
V_10 , V_11 , V_8 -> V_22 ) ;
for ( V_18 = 0 ; V_18 < V_8 -> V_22 ; V_18 ++ ) {
struct V_23 * V_24 = V_8 -> V_25 [ V_18 ] ;
struct V_12 * V_26 =
V_16 -> V_27 [ V_24 -> V_28 ] -> V_29 -> V_30 ;
struct V_3 * V_31 = F_3 ( V_26 , V_4 -> V_32 ) ;
switch ( V_6 -> V_33 ) {
case V_34 : {
struct V_35 * V_36 = (struct V_35 * ) V_6 ;
V_36 -> V_37 = F_4 ( & V_24 -> V_38 ) ;
V_36 -> V_39 = ( V_40 ) F_5 ( & V_24 -> V_38 ) ;
break;
}
case V_41 : {
struct V_42 * V_43 = (struct V_42 * ) V_6 ;
V_43 -> V_44 = V_24 -> V_38 ;
break;
}
default:
break;
}
if ( F_6 ( V_45 ) ) {
F_7 ( V_31 ) ;
V_31 = NULL ;
}
V_19 = F_8 ( V_2 , V_31 , V_6 , NULL , V_10 + V_20 ,
V_11 - V_20 ) ;
F_7 ( V_31 ) ;
if ( V_19 < 0 ) {
F_9 ( L_2 ,
V_19 , V_20 ) ;
memset ( V_10 + V_20 , 0 ,
sizeof( struct V_9 ) ) ;
V_19 = 1 ;
}
V_20 += V_19 ;
}
RETURN ( V_20 ) ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_46 * V_47 ,
struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_12 * V_13 = V_4 -> V_14 ;
struct V_15 * V_16 = & V_13 -> V_17 . V_16 ;
int V_18 , V_19 = 0 , V_52 = 0 ;
V_21 ;
F_11 ( V_13 ) ;
for ( V_18 = 0 ; V_18 < V_16 -> V_53 . V_54 ; V_18 ++ ) {
struct V_12 * V_26 ;
struct V_3 * V_31 ;
if ( ! V_16 -> V_27 [ V_18 ] || ! V_16 -> V_27 [ V_18 ] -> V_55 )
continue;
if ( V_51 && ! F_12 ( V_51 , & V_16 -> V_27 [ V_18 ] -> V_56 ) )
continue;
F_13 ( V_57 , L_3 , V_18 , V_16 -> V_53 . V_54 ) ;
V_26 = V_16 -> V_27 [ V_18 ] -> V_29 -> V_30 ;
V_31 = F_3 ( V_26 , V_4 -> V_32 ) ;
V_19 = F_14 ( V_31 , V_47 , V_49 , V_51 ) ;
F_7 ( V_31 ) ;
if ( V_19 ) {
F_9 ( L_4 , V_18 , V_19 ) ;
if ( ! V_52 )
V_52 = V_19 ;
}
}
F_15 ( V_13 ) ;
RETURN ( V_52 ) ;
}
static int F_16 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_7 * V_8 ,
int V_58 , struct V_9 * V_20 ,
int V_59 )
{
struct V_15 * V_16 ;
struct V_12 * V_13 = V_4 -> V_14 ;
int V_19 = 0 , V_18 ;
V_21 ;
F_17 ( V_8 != NULL ) ;
F_17 ( V_58 == V_8 -> V_22 ) ;
V_16 = & V_13 -> V_17 . V_16 ;
F_11 ( V_13 ) ;
for ( V_18 = 0 ; V_18 < V_58 ; V_18 ++ , V_20 ++ ) {
struct V_23 * V_24 = V_8 -> V_25 [ V_18 ] ;
struct V_12 * V_26 =
V_16 -> V_27 [ V_24 -> V_28 ] -> V_29 -> V_30 ;
struct V_3 * V_31 =
F_3 ( V_26 , V_4 -> V_32 ) ;
int V_52 ;
V_52 = F_18 ( V_2 , V_31 , NULL , 1 , V_20 , V_59 ) ;
F_7 ( V_31 ) ;
if ( V_52 && V_16 -> V_27 [ V_24 -> V_28 ] -> V_55 ) {
F_9 ( L_5 V_60 L_6 V_60
L_7 ,
V_13 -> V_61 , F_19 ( & V_8 -> V_62 ) ,
F_19 ( & V_24 -> V_38 ) , V_24 -> V_28 , V_52 ) ;
if ( ! V_19 )
V_19 = V_52 ;
}
}
F_15 ( V_13 ) ;
RETURN ( V_19 ) ;
}
int F_20 ( struct V_12 * V_13 , struct V_63 * V_64 ,
struct V_12 * V_65 , int * V_66 )
{
struct V_15 * V_16 = & V_13 -> V_17 . V_16 ;
struct V_12 * V_26 ;
int V_18 , V_19 = 0 ;
V_21 ;
F_17 ( V_64 == & V_13 -> V_67 ) ;
V_19 = F_21 ( NULL , V_13 , V_64 , V_68 , V_65 ,
& V_69 ) ;
if ( V_19 )
RETURN ( V_19 ) ;
V_19 = F_21 ( NULL , V_13 , V_64 , V_70 , V_65 ,
& V_71 ) ;
if ( V_19 )
GOTO ( V_72 , V_19 ) ;
F_11 ( V_13 ) ;
for ( V_18 = 0 ; V_18 < V_16 -> V_53 . V_54 ; V_18 ++ ) {
if ( ! V_16 -> V_27 [ V_18 ] )
continue;
if ( V_66 && V_18 != * V_66 )
continue;
V_26 = V_16 -> V_27 [ V_18 ] -> V_73 ;
V_19 = F_22 ( V_26 , & V_26 -> V_67 , V_65 , & V_18 ) ;
if ( V_19 )
F_9 ( L_8
L_9 , V_18 , V_26 -> V_61 ,
V_65 -> V_61 , V_19 ) ;
V_19 = 0 ;
}
F_15 ( V_13 ) ;
GOTO ( V_72 , V_19 ) ;
V_72:
if ( V_19 ) {
struct V_3 * V_4 =
F_3 ( V_13 , V_70 ) ;
if ( V_4 )
F_23 ( NULL , V_4 ) ;
V_4 = F_3 ( V_13 , V_68 ) ;
if ( V_4 )
F_23 ( NULL , V_4 ) ;
}
return V_19 ;
}
int F_24 ( struct V_12 * V_13 , int V_58 )
{
struct V_3 * V_4 ;
V_21 ;
V_4 = F_3 ( V_13 , V_68 ) ;
if ( V_4 )
F_23 ( NULL , V_4 ) ;
V_4 = F_3 ( V_13 , V_70 ) ;
if ( V_4 )
F_23 ( NULL , V_4 ) ;
RETURN ( 0 ) ;
}
