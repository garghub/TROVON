static void F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = & ( * V_4 ) -> V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_11 ;
int V_12 , V_13 ;
T_1 V_14 ;
V_8 -> V_15 = F_2 ( V_2 , L_1 , NULL ) ;
if ( ! F_3 ( V_2 , L_2 , & V_14 ) )
V_8 -> V_16 = V_14 ;
if ( ! F_3 ( V_2 , L_3 , & V_14 ) )
V_8 -> V_17 = V_14 ;
if ( V_8 -> V_16 != V_8 -> V_17 )
V_8 -> V_18 |= V_19 ;
if ( V_8 -> V_16 && V_8 -> V_17 )
V_8 -> V_20 = true ;
if ( ! F_3 ( V_2 , L_4 , & V_14 ) )
V_8 -> V_21 = V_14 ;
if ( ! F_3 ( V_2 , L_5 , & V_14 ) )
V_8 -> V_22 = V_14 ;
if ( ! F_3 ( V_2 , L_6 , & V_14 ) )
V_8 -> V_23 = V_14 ;
if ( ! F_3 ( V_2 , L_7 ,
& V_14 ) )
V_8 -> V_24 = V_14 ;
if ( V_8 -> V_22 != V_8 -> V_23 )
V_8 -> V_18 |= V_25 ;
V_8 -> V_26 = F_4 ( V_2 , L_8 ) ;
V_8 -> V_27 = F_4 ( V_2 , L_9 ) ;
if ( ! V_8 -> V_27 )
V_8 -> V_18 |= V_28 ;
V_8 -> V_29 = F_4 ( V_2 , L_10 ) ;
if ( F_4 ( V_2 , L_11 ) )
V_8 -> V_18 |= V_30 ;
if ( F_4 ( V_2 , L_12 ) )
V_8 -> V_18 |= V_31 ;
V_12 = F_3 ( V_2 , L_13 , & V_14 ) ;
if ( ! V_12 ) {
if ( V_14 )
V_8 -> V_32 = V_14 ;
else
V_8 -> V_33 = true ;
}
V_12 = F_3 ( V_2 , L_14 , & V_14 ) ;
if ( ! V_12 )
V_8 -> V_34 = V_14 ;
V_12 = F_3 ( V_2 , L_15 , & V_14 ) ;
if ( ! V_12 )
V_8 -> V_35 = V_14 ;
if ( V_8 -> V_35 && V_8 -> V_34 ) {
F_5 ( L_16 ,
V_2 -> V_15 ) ;
V_8 -> V_35 = 0 ;
}
V_12 = F_3 ( V_2 , L_17 ,
& V_14 ) ;
if ( ! V_12 )
V_8 -> V_36 = V_14 ;
if ( V_8 -> V_36 && V_8 -> V_34 ) {
F_5 ( L_18 ,
V_2 -> V_15 ) ;
V_8 -> V_36 = 0 ;
}
V_12 = F_3 ( V_2 , L_19 , & V_14 ) ;
if ( ! V_12 )
V_8 -> V_37 = V_14 ;
V_8 -> V_38 = F_4 ( V_2 ,
L_20 ) ;
V_12 = F_3 ( V_2 , L_21 , & V_14 ) ;
if ( ! V_12 ) {
V_8 -> V_39 =
( V_14 ) ? V_40 :
V_41 ;
}
if ( ! F_3 ( V_2 , L_22 , & V_14 ) ) {
if ( V_6 && V_6 -> V_42 ) {
V_12 = V_6 -> V_42 ( V_14 ) ;
if ( V_12 == - V_43 )
F_6 ( L_23 , V_2 -> V_15 , V_14 ) ;
else
V_8 -> V_44 = V_12 ;
} else {
F_5 ( L_24 ,
V_2 -> V_15 , V_14 ) ;
}
}
if ( ! F_3 ( V_2 , L_25 , & V_14 ) )
V_8 -> V_45 = V_14 ;
V_8 -> V_46 = F_4 ( V_2 ,
L_26 ) ;
for ( V_13 = 0 ; V_13 < F_7 ( V_47 ) ; V_13 ++ ) {
switch ( V_13 ) {
case V_48 :
V_10 = & V_8 -> V_49 ;
break;
case V_50 :
V_10 = & V_8 -> V_51 ;
break;
case V_52 :
case V_53 :
case V_54 :
default:
continue;
}
V_11 = F_8 ( V_2 , V_47 [ V_13 ] ) ;
if ( ! V_11 || ! V_10 )
continue;
if ( ! F_3 ( V_11 , L_27 ,
& V_14 ) ) {
if ( V_6 && V_6 -> V_42 ) {
V_12 = V_6 -> V_42 ( V_14 ) ;
if ( V_12 == - V_43 )
F_6 ( L_23 ,
V_2 -> V_15 , V_14 ) ;
else
V_10 -> V_55 = V_12 ;
} else {
F_5 ( L_24 ,
V_2 -> V_15 , V_14 ) ;
}
}
if ( F_4 ( V_11 ,
L_28 ) )
V_10 -> V_56 = true ;
else if ( F_4 ( V_11 ,
L_29 ) )
V_10 -> V_57 = true ;
if ( ! F_3 ( V_11 ,
L_30 , & V_14 ) )
V_10 -> V_58 = V_14 ;
if ( V_13 == V_48 )
V_8 -> V_59 = V_48 ;
F_9 ( V_11 ) ;
V_10 = NULL ;
V_11 = NULL ;
}
}
struct V_3 * F_10 ( struct V_60 * V_61 ,
struct V_1 * V_62 ,
const struct V_5 * V_6 )
{
struct V_3 * V_4 ;
if ( ! V_62 )
return NULL ;
V_4 = F_11 ( V_61 , sizeof( * V_4 ) , V_63 ) ;
if ( ! V_4 )
return NULL ;
F_1 ( V_62 , & V_4 , V_6 ) ;
return V_4 ;
}
static void F_12 ( struct V_60 * V_61 , void * V_64 )
{
struct V_65 * V_66 = V_64 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_66 -> V_67 ; V_13 ++ )
F_9 ( V_66 -> V_68 [ V_13 ] . V_69 ) ;
}
int F_13 ( struct V_60 * V_61 , struct V_1 * V_62 ,
struct F_13 * V_68 ,
unsigned int V_67 )
{
unsigned int V_70 = 0 ;
unsigned int V_13 ;
const char * V_15 ;
struct V_1 * V_71 ;
struct V_65 * V_66 ;
if ( ! V_61 || ! V_62 )
return - V_43 ;
V_66 = F_14 ( F_12 ,
sizeof( struct V_65 ) ,
V_63 ) ;
if ( ! V_66 )
return - V_72 ;
V_66 -> V_68 = V_68 ;
V_66 -> V_67 = V_67 ;
F_15 ( V_61 , V_66 ) ;
for ( V_13 = 0 ; V_13 < V_67 ; V_13 ++ ) {
struct F_13 * V_73 = & V_68 [ V_13 ] ;
V_73 -> V_4 = NULL ;
V_73 -> V_69 = NULL ;
}
F_16 (node, child) {
V_15 = F_2 ( V_71 ,
L_31 , NULL ) ;
if ( ! V_15 )
V_15 = V_71 -> V_15 ;
for ( V_13 = 0 ; V_13 < V_67 ; V_13 ++ ) {
struct F_13 * V_73 = & V_68 [ V_13 ] ;
if ( V_73 -> V_69 )
continue;
if ( strcmp ( V_73 -> V_15 , V_15 ) )
continue;
V_73 -> V_4 =
F_10 ( V_61 , V_71 ,
V_73 -> V_6 ) ;
if ( ! V_73 -> V_4 ) {
F_17 ( V_61 ,
L_32 ,
V_71 -> V_15 ) ;
return - V_43 ;
}
V_73 -> V_69 = F_18 ( V_71 ) ;
V_70 ++ ;
break;
}
}
return V_70 ;
}
struct V_3 * F_19 ( struct V_60 * V_61 ,
const struct V_5 * V_6 ,
struct V_74 * V_75 ,
struct V_1 * * V_62 )
{
struct V_1 * V_76 , * V_71 ;
struct V_3 * V_4 = NULL ;
const char * V_15 ;
if ( ! V_61 -> V_69 || ! V_6 -> V_77 )
return NULL ;
if ( V_6 -> V_78 )
V_76 = F_8 ( V_61 -> V_69 ,
V_6 -> V_78 ) ;
else
V_76 = V_61 -> V_69 ;
if ( ! V_76 ) {
F_20 ( V_61 , L_33 ,
V_6 -> V_78 ) ;
return NULL ;
}
F_21 (search, child) {
V_15 = F_2 ( V_71 , L_31 , NULL ) ;
if ( ! V_15 )
V_15 = V_71 -> V_15 ;
if ( strcmp ( V_6 -> V_77 , V_15 ) )
continue;
V_4 = F_10 ( V_61 , V_71 , V_6 ) ;
if ( ! V_4 ) {
F_17 ( V_61 ,
L_32 ,
V_71 -> V_15 ) ;
break;
}
if ( V_6 -> V_79 ) {
if ( V_6 -> V_79 ( V_71 , V_6 , V_75 ) ) {
F_17 ( V_61 ,
L_34 ,
V_71 -> V_15 ) ;
V_4 = NULL ;
break;
}
}
F_18 ( V_71 ) ;
* V_62 = V_71 ;
break;
}
F_9 ( V_76 ) ;
return V_4 ;
}
