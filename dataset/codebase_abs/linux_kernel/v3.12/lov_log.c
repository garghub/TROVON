static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_9 * V_10 , int V_11 )
{
struct V_12 * V_13 = V_4 -> V_14 ;
struct V_15 * V_16 = & V_13 -> V_17 . V_16 ;
int V_18 , V_19 = 0 , V_20 = 0 ;
F_2 ( V_10 && V_11 >= V_8 -> V_21 ,
L_1 ,
V_10 , V_11 , V_8 -> V_21 ) ;
for ( V_18 = 0 ; V_18 < V_8 -> V_21 ; V_18 ++ ) {
struct V_22 * V_23 = V_8 -> V_24 [ V_18 ] ;
struct V_12 * V_25 =
V_16 -> V_26 [ V_23 -> V_27 ] -> V_28 -> V_29 ;
struct V_3 * V_30 = F_3 ( V_25 , V_4 -> V_31 ) ;
switch ( V_6 -> V_32 ) {
case V_33 : {
struct V_34 * V_35 = (struct V_34 * ) V_6 ;
V_35 -> V_36 = F_4 ( & V_23 -> V_37 ) ;
V_35 -> V_38 = ( V_39 ) F_5 ( & V_23 -> V_37 ) ;
break;
}
case V_40 : {
struct V_41 * V_42 = (struct V_41 * ) V_6 ;
V_42 -> V_43 = V_23 -> V_37 ;
break;
}
default:
break;
}
if ( F_6 ( V_44 ) ) {
F_7 ( V_30 ) ;
V_30 = NULL ;
}
V_19 = F_8 ( V_2 , V_30 , V_6 , NULL , V_10 + V_20 ,
V_11 - V_20 ) ;
F_7 ( V_30 ) ;
if ( V_19 < 0 ) {
F_9 ( L_2 ,
V_19 , V_20 ) ;
memset ( V_10 + V_20 , 0 ,
sizeof( struct V_9 ) ) ;
V_19 = 1 ;
}
V_20 += V_19 ;
}
return V_20 ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_45 * V_46 ,
struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_12 * V_13 = V_4 -> V_14 ;
struct V_15 * V_16 = & V_13 -> V_17 . V_16 ;
int V_18 , V_19 = 0 , V_51 = 0 ;
F_11 ( V_13 ) ;
for ( V_18 = 0 ; V_18 < V_16 -> V_52 . V_53 ; V_18 ++ ) {
struct V_12 * V_25 ;
struct V_3 * V_30 ;
if ( ! V_16 -> V_26 [ V_18 ] || ! V_16 -> V_26 [ V_18 ] -> V_54 )
continue;
if ( V_50 && ! F_12 ( V_50 , & V_16 -> V_26 [ V_18 ] -> V_55 ) )
continue;
F_13 ( V_56 , L_3 , V_18 , V_16 -> V_52 . V_53 ) ;
V_25 = V_16 -> V_26 [ V_18 ] -> V_28 -> V_29 ;
V_30 = F_3 ( V_25 , V_4 -> V_31 ) ;
V_19 = F_14 ( V_30 , V_46 , V_48 , V_50 ) ;
F_7 ( V_30 ) ;
if ( V_19 ) {
F_9 ( L_4 , V_18 , V_19 ) ;
if ( ! V_51 )
V_51 = V_19 ;
}
}
F_15 ( V_13 ) ;
return V_51 ;
}
static int F_16 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_7 * V_8 ,
int V_57 , struct V_9 * V_20 ,
int V_58 )
{
struct V_15 * V_16 ;
struct V_12 * V_13 = V_4 -> V_14 ;
int V_19 = 0 , V_18 ;
F_17 ( V_8 != NULL ) ;
F_17 ( V_57 == V_8 -> V_21 ) ;
V_16 = & V_13 -> V_17 . V_16 ;
F_11 ( V_13 ) ;
for ( V_18 = 0 ; V_18 < V_57 ; V_18 ++ , V_20 ++ ) {
struct V_22 * V_23 = V_8 -> V_24 [ V_18 ] ;
struct V_12 * V_25 =
V_16 -> V_26 [ V_23 -> V_27 ] -> V_28 -> V_29 ;
struct V_3 * V_30 =
F_3 ( V_25 , V_4 -> V_31 ) ;
int V_51 ;
V_51 = F_18 ( V_2 , V_30 , NULL , 1 , V_20 , V_58 ) ;
F_7 ( V_30 ) ;
if ( V_51 && V_16 -> V_26 [ V_23 -> V_27 ] -> V_54 ) {
F_9 ( L_5 V_59 L_6 V_59
L_7 ,
V_13 -> V_60 , F_19 ( & V_8 -> V_61 ) ,
F_19 ( & V_23 -> V_37 ) , V_23 -> V_27 , V_51 ) ;
if ( ! V_19 )
V_19 = V_51 ;
}
}
F_15 ( V_13 ) ;
return V_19 ;
}
int F_20 ( struct V_12 * V_13 , struct V_62 * V_63 ,
struct V_12 * V_64 , int * V_65 )
{
struct V_15 * V_16 = & V_13 -> V_17 . V_16 ;
struct V_12 * V_25 ;
int V_18 , V_19 = 0 ;
F_17 ( V_63 == & V_13 -> V_66 ) ;
V_19 = F_21 ( NULL , V_13 , V_63 , V_67 , V_64 ,
& V_68 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_21 ( NULL , V_13 , V_63 , V_69 , V_64 ,
& V_70 ) ;
if ( V_19 )
GOTO ( V_71 , V_19 ) ;
F_11 ( V_13 ) ;
for ( V_18 = 0 ; V_18 < V_16 -> V_52 . V_53 ; V_18 ++ ) {
if ( ! V_16 -> V_26 [ V_18 ] )
continue;
if ( V_65 && V_18 != * V_65 )
continue;
V_25 = V_16 -> V_26 [ V_18 ] -> V_72 ;
V_19 = F_22 ( V_25 , & V_25 -> V_66 , V_64 , & V_18 ) ;
if ( V_19 )
F_9 ( L_8
L_9 , V_18 , V_25 -> V_60 ,
V_64 -> V_60 , V_19 ) ;
V_19 = 0 ;
}
F_15 ( V_13 ) ;
GOTO ( V_71 , V_19 ) ;
V_71:
if ( V_19 ) {
struct V_3 * V_4 =
F_3 ( V_13 , V_69 ) ;
if ( V_4 )
F_23 ( NULL , V_4 ) ;
V_4 = F_3 ( V_13 , V_67 ) ;
if ( V_4 )
F_23 ( NULL , V_4 ) ;
}
return V_19 ;
}
int F_24 ( struct V_12 * V_13 , int V_57 )
{
struct V_3 * V_4 ;
V_4 = F_3 ( V_13 , V_67 ) ;
if ( V_4 )
F_23 ( NULL , V_4 ) ;
V_4 = F_3 ( V_13 , V_69 ) ;
if ( V_4 )
F_23 ( NULL , V_4 ) ;
return 0 ;
}
