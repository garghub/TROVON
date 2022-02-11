static void F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
const struct V_5 * V_6 )
{
const T_1 * V_7 , * V_8 ;
struct V_9 * V_10 = & ( * V_4 ) -> V_10 ;
struct V_11 * V_12 ;
struct V_1 * V_13 ;
int V_14 , V_15 ;
T_2 V_16 ;
V_10 -> V_17 = F_2 ( V_2 , L_1 , NULL ) ;
V_7 = F_2 ( V_2 , L_2 , NULL ) ;
if ( V_7 )
V_10 -> V_7 = F_3 ( * V_7 ) ;
V_8 = F_2 ( V_2 , L_3 , NULL ) ;
if ( V_8 )
V_10 -> V_8 = F_3 ( * V_8 ) ;
if ( V_10 -> V_7 != V_10 -> V_8 )
V_10 -> V_18 |= V_19 ;
if ( V_7 && V_8 && V_10 -> V_7 == V_10 -> V_8 )
V_10 -> V_20 = true ;
if ( ! F_4 ( V_2 , L_4 , & V_16 ) )
V_10 -> V_21 = V_16 ;
if ( ! F_4 ( V_2 , L_5 , & V_16 ) )
V_10 -> V_22 = V_16 ;
if ( ! F_4 ( V_2 , L_6 , & V_16 ) )
V_10 -> V_23 = V_16 ;
if ( ! F_4 ( V_2 , L_7 ,
& V_16 ) )
V_10 -> V_24 = V_16 ;
if ( V_10 -> V_22 != V_10 -> V_23 )
V_10 -> V_18 |= V_25 ;
V_10 -> V_26 = F_5 ( V_2 , L_8 ) ;
V_10 -> V_27 = F_5 ( V_2 , L_9 ) ;
if ( ! V_10 -> V_27 )
V_10 -> V_18 |= V_28 ;
V_10 -> V_29 = F_5 ( V_2 , L_10 ) ;
if ( F_5 ( V_2 , L_11 ) )
V_10 -> V_18 |= V_30 ;
if ( F_5 ( V_2 , L_12 ) )
V_10 -> V_18 |= V_31 ;
V_14 = F_4 ( V_2 , L_13 , & V_16 ) ;
if ( ! V_14 ) {
if ( V_16 )
V_10 -> V_32 = V_16 ;
else
V_10 -> V_33 = true ;
}
V_14 = F_4 ( V_2 , L_14 , & V_16 ) ;
if ( ! V_14 )
V_10 -> V_34 = V_16 ;
V_10 -> V_35 = F_5 ( V_2 ,
L_15 ) ;
if ( ! F_4 ( V_2 , L_16 , & V_16 ) ) {
if ( V_6 && V_6 -> V_36 ) {
V_14 = V_6 -> V_36 ( V_16 ) ;
if ( V_14 == - V_37 )
F_6 ( L_17 , V_2 -> V_17 , V_16 ) ;
else
V_10 -> V_38 = V_14 ;
} else {
F_7 ( L_18 ,
V_2 -> V_17 , V_16 ) ;
}
}
if ( ! F_4 ( V_2 , L_19 , & V_16 ) )
V_10 -> V_39 = V_16 ;
V_10 -> V_40 = F_5 ( V_2 ,
L_20 ) ;
for ( V_15 = 0 ; V_15 < F_8 ( V_41 ) ; V_15 ++ ) {
switch ( V_15 ) {
case V_42 :
V_12 = & V_10 -> V_43 ;
break;
case V_44 :
V_12 = & V_10 -> V_45 ;
break;
case V_46 :
case V_47 :
case V_48 :
default:
continue;
}
V_13 = F_9 ( V_2 , V_41 [ V_15 ] ) ;
if ( ! V_13 || ! V_12 )
continue;
if ( ! F_4 ( V_13 , L_21 ,
& V_16 ) ) {
if ( V_6 && V_6 -> V_36 ) {
V_14 = V_6 -> V_36 ( V_16 ) ;
if ( V_14 == - V_37 )
F_6 ( L_17 ,
V_2 -> V_17 , V_16 ) ;
else
V_12 -> V_49 = V_14 ;
} else {
F_7 ( L_18 ,
V_2 -> V_17 , V_16 ) ;
}
}
if ( F_5 ( V_13 ,
L_22 ) )
V_12 -> V_50 = true ;
else if ( F_5 ( V_13 ,
L_23 ) )
V_12 -> V_51 = true ;
if ( ! F_4 ( V_13 ,
L_24 , & V_16 ) )
V_12 -> V_52 = V_16 ;
F_10 ( V_13 ) ;
V_12 = NULL ;
V_13 = NULL ;
}
}
struct V_3 * F_11 ( struct V_53 * V_54 ,
struct V_1 * V_55 ,
const struct V_5 * V_6 )
{
struct V_3 * V_4 ;
if ( ! V_55 )
return NULL ;
V_4 = F_12 ( V_54 , sizeof( * V_4 ) , V_56 ) ;
if ( ! V_4 )
return NULL ;
F_1 ( V_55 , & V_4 , V_6 ) ;
return V_4 ;
}
static void F_13 ( struct V_53 * V_54 , void * V_57 )
{
struct V_58 * V_59 = V_57 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_59 -> V_60 ; V_15 ++ )
F_10 ( V_59 -> V_61 [ V_15 ] . V_62 ) ;
}
int F_14 ( struct V_53 * V_54 , struct V_1 * V_55 ,
struct F_14 * V_61 ,
unsigned int V_60 )
{
unsigned int V_63 = 0 ;
unsigned int V_15 ;
const char * V_17 ;
struct V_1 * V_64 ;
struct V_58 * V_59 ;
if ( ! V_54 || ! V_55 )
return - V_37 ;
V_59 = F_15 ( F_13 ,
sizeof( struct V_58 ) ,
V_56 ) ;
if ( ! V_59 )
return - V_65 ;
V_59 -> V_61 = V_61 ;
V_59 -> V_60 = V_60 ;
F_16 ( V_54 , V_59 ) ;
for ( V_15 = 0 ; V_15 < V_60 ; V_15 ++ ) {
struct F_14 * V_66 = & V_61 [ V_15 ] ;
V_66 -> V_4 = NULL ;
V_66 -> V_62 = NULL ;
}
F_17 (node, child) {
V_17 = F_2 ( V_64 ,
L_25 , NULL ) ;
if ( ! V_17 )
V_17 = V_64 -> V_17 ;
for ( V_15 = 0 ; V_15 < V_60 ; V_15 ++ ) {
struct F_14 * V_66 = & V_61 [ V_15 ] ;
if ( V_66 -> V_62 )
continue;
if ( strcmp ( V_66 -> V_17 , V_17 ) )
continue;
V_66 -> V_4 =
F_11 ( V_54 , V_64 ,
V_66 -> V_6 ) ;
if ( ! V_66 -> V_4 ) {
F_18 ( V_54 ,
L_26 ,
V_64 -> V_17 ) ;
return - V_37 ;
}
V_66 -> V_62 = F_19 ( V_64 ) ;
V_63 ++ ;
break;
}
}
return V_63 ;
}
struct V_3 * F_20 ( struct V_53 * V_54 ,
const struct V_5 * V_6 ,
struct V_67 * V_68 ,
struct V_1 * * V_55 )
{
struct V_1 * V_69 , * V_64 ;
struct V_3 * V_4 = NULL ;
const char * V_17 ;
if ( ! V_54 -> V_62 || ! V_6 -> V_70 )
return NULL ;
if ( V_6 -> V_71 )
V_69 = F_9 ( V_54 -> V_62 ,
V_6 -> V_71 ) ;
else
V_69 = V_54 -> V_62 ;
if ( ! V_69 ) {
F_21 ( V_54 , L_27 ,
V_6 -> V_71 ) ;
return NULL ;
}
F_22 (search, child) {
V_17 = F_2 ( V_64 , L_25 , NULL ) ;
if ( ! V_17 )
V_17 = V_64 -> V_17 ;
if ( strcmp ( V_6 -> V_70 , V_17 ) )
continue;
V_4 = F_11 ( V_54 , V_64 , V_6 ) ;
if ( ! V_4 ) {
F_18 ( V_54 ,
L_26 ,
V_64 -> V_17 ) ;
break;
}
if ( V_6 -> V_72 ) {
if ( V_6 -> V_72 ( V_64 , V_6 , V_68 ) ) {
F_18 ( V_54 ,
L_28 ,
V_64 -> V_17 ) ;
V_4 = NULL ;
break;
}
}
F_19 ( V_64 ) ;
* V_55 = V_64 ;
break;
}
F_10 ( V_69 ) ;
return V_4 ;
}
