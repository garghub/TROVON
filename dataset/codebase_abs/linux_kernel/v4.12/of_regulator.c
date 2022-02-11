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
V_8 -> V_36 = F_4 ( V_2 ,
L_16 ) ;
V_12 = F_3 ( V_2 , L_17 , & V_14 ) ;
if ( ! V_12 ) {
V_8 -> V_37 =
( V_14 ) ? V_38 :
V_39 ;
}
if ( ! F_3 ( V_2 , L_18 , & V_14 ) ) {
if ( V_6 && V_6 -> V_40 ) {
V_12 = V_6 -> V_40 ( V_14 ) ;
if ( V_12 == - V_41 )
F_5 ( L_19 , V_2 -> V_15 , V_14 ) ;
else
V_8 -> V_42 = V_12 ;
} else {
F_6 ( L_20 ,
V_2 -> V_15 , V_14 ) ;
}
}
if ( ! F_3 ( V_2 , L_21 , & V_14 ) )
V_8 -> V_43 = V_14 ;
V_8 -> V_44 = F_4 ( V_2 ,
L_22 ) ;
for ( V_13 = 0 ; V_13 < F_7 ( V_45 ) ; V_13 ++ ) {
switch ( V_13 ) {
case V_46 :
V_10 = & V_8 -> V_47 ;
break;
case V_48 :
V_10 = & V_8 -> V_49 ;
break;
case V_50 :
case V_51 :
case V_52 :
default:
continue;
}
V_11 = F_8 ( V_2 , V_45 [ V_13 ] ) ;
if ( ! V_11 || ! V_10 )
continue;
if ( ! F_3 ( V_11 , L_23 ,
& V_14 ) ) {
if ( V_6 && V_6 -> V_40 ) {
V_12 = V_6 -> V_40 ( V_14 ) ;
if ( V_12 == - V_41 )
F_5 ( L_19 ,
V_2 -> V_15 , V_14 ) ;
else
V_10 -> V_53 = V_12 ;
} else {
F_6 ( L_20 ,
V_2 -> V_15 , V_14 ) ;
}
}
if ( F_4 ( V_11 ,
L_24 ) )
V_10 -> V_54 = true ;
else if ( F_4 ( V_11 ,
L_25 ) )
V_10 -> V_55 = true ;
if ( ! F_3 ( V_11 ,
L_26 , & V_14 ) )
V_10 -> V_56 = V_14 ;
if ( V_13 == V_46 )
V_8 -> V_57 = V_46 ;
F_9 ( V_11 ) ;
V_10 = NULL ;
V_11 = NULL ;
}
}
struct V_3 * F_10 ( struct V_58 * V_59 ,
struct V_1 * V_60 ,
const struct V_5 * V_6 )
{
struct V_3 * V_4 ;
if ( ! V_60 )
return NULL ;
V_4 = F_11 ( V_59 , sizeof( * V_4 ) , V_61 ) ;
if ( ! V_4 )
return NULL ;
F_1 ( V_60 , & V_4 , V_6 ) ;
return V_4 ;
}
static void F_12 ( struct V_58 * V_59 , void * V_62 )
{
struct V_63 * V_64 = V_62 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_64 -> V_65 ; V_13 ++ )
F_9 ( V_64 -> V_66 [ V_13 ] . V_67 ) ;
}
int F_13 ( struct V_58 * V_59 , struct V_1 * V_60 ,
struct F_13 * V_66 ,
unsigned int V_65 )
{
unsigned int V_68 = 0 ;
unsigned int V_13 ;
const char * V_15 ;
struct V_1 * V_69 ;
struct V_63 * V_64 ;
if ( ! V_59 || ! V_60 )
return - V_41 ;
V_64 = F_14 ( F_12 ,
sizeof( struct V_63 ) ,
V_61 ) ;
if ( ! V_64 )
return - V_70 ;
V_64 -> V_66 = V_66 ;
V_64 -> V_65 = V_65 ;
F_15 ( V_59 , V_64 ) ;
for ( V_13 = 0 ; V_13 < V_65 ; V_13 ++ ) {
struct F_13 * V_71 = & V_66 [ V_13 ] ;
V_71 -> V_4 = NULL ;
V_71 -> V_67 = NULL ;
}
F_16 (node, child) {
V_15 = F_2 ( V_69 ,
L_27 , NULL ) ;
if ( ! V_15 )
V_15 = V_69 -> V_15 ;
for ( V_13 = 0 ; V_13 < V_65 ; V_13 ++ ) {
struct F_13 * V_71 = & V_66 [ V_13 ] ;
if ( V_71 -> V_67 )
continue;
if ( strcmp ( V_71 -> V_15 , V_15 ) )
continue;
V_71 -> V_4 =
F_10 ( V_59 , V_69 ,
V_71 -> V_6 ) ;
if ( ! V_71 -> V_4 ) {
F_17 ( V_59 ,
L_28 ,
V_69 -> V_15 ) ;
return - V_41 ;
}
V_71 -> V_67 = F_18 ( V_69 ) ;
V_68 ++ ;
break;
}
}
return V_68 ;
}
struct V_3 * F_19 ( struct V_58 * V_59 ,
const struct V_5 * V_6 ,
struct V_72 * V_73 ,
struct V_1 * * V_60 )
{
struct V_1 * V_74 , * V_69 ;
struct V_3 * V_4 = NULL ;
const char * V_15 ;
if ( ! V_59 -> V_67 || ! V_6 -> V_75 )
return NULL ;
if ( V_6 -> V_76 )
V_74 = F_8 ( V_59 -> V_67 ,
V_6 -> V_76 ) ;
else
V_74 = V_59 -> V_67 ;
if ( ! V_74 ) {
F_20 ( V_59 , L_29 ,
V_6 -> V_76 ) ;
return NULL ;
}
F_21 (search, child) {
V_15 = F_2 ( V_69 , L_27 , NULL ) ;
if ( ! V_15 )
V_15 = V_69 -> V_15 ;
if ( strcmp ( V_6 -> V_75 , V_15 ) )
continue;
V_4 = F_10 ( V_59 , V_69 , V_6 ) ;
if ( ! V_4 ) {
F_17 ( V_59 ,
L_28 ,
V_69 -> V_15 ) ;
break;
}
if ( V_6 -> V_77 ) {
if ( V_6 -> V_77 ( V_69 , V_6 , V_73 ) ) {
F_17 ( V_59 ,
L_30 ,
V_69 -> V_15 ) ;
V_4 = NULL ;
break;
}
}
F_18 ( V_69 ) ;
* V_60 = V_69 ;
break;
}
F_9 ( V_74 ) ;
return V_4 ;
}
