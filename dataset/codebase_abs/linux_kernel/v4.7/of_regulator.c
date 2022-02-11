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
V_8 -> V_35 = F_4 ( V_2 ,
L_15 ) ;
V_12 = F_3 ( V_2 , L_16 , & V_14 ) ;
if ( ! V_12 ) {
V_8 -> V_36 =
( V_14 ) ? V_37 :
V_38 ;
}
if ( ! F_3 ( V_2 , L_17 , & V_14 ) ) {
if ( V_6 && V_6 -> V_39 ) {
V_12 = V_6 -> V_39 ( V_14 ) ;
if ( V_12 == - V_40 )
F_5 ( L_18 , V_2 -> V_15 , V_14 ) ;
else
V_8 -> V_41 = V_12 ;
} else {
F_6 ( L_19 ,
V_2 -> V_15 , V_14 ) ;
}
}
if ( ! F_3 ( V_2 , L_20 , & V_14 ) )
V_8 -> V_42 = V_14 ;
V_8 -> V_43 = F_4 ( V_2 ,
L_21 ) ;
for ( V_13 = 0 ; V_13 < F_7 ( V_44 ) ; V_13 ++ ) {
switch ( V_13 ) {
case V_45 :
V_10 = & V_8 -> V_46 ;
break;
case V_47 :
V_10 = & V_8 -> V_48 ;
break;
case V_49 :
case V_50 :
case V_51 :
default:
continue;
}
V_11 = F_8 ( V_2 , V_44 [ V_13 ] ) ;
if ( ! V_11 || ! V_10 )
continue;
if ( ! F_3 ( V_11 , L_22 ,
& V_14 ) ) {
if ( V_6 && V_6 -> V_39 ) {
V_12 = V_6 -> V_39 ( V_14 ) ;
if ( V_12 == - V_40 )
F_5 ( L_18 ,
V_2 -> V_15 , V_14 ) ;
else
V_10 -> V_52 = V_12 ;
} else {
F_6 ( L_19 ,
V_2 -> V_15 , V_14 ) ;
}
}
if ( F_4 ( V_11 ,
L_23 ) )
V_10 -> V_53 = true ;
else if ( F_4 ( V_11 ,
L_24 ) )
V_10 -> V_54 = true ;
if ( ! F_3 ( V_11 ,
L_25 , & V_14 ) )
V_10 -> V_55 = V_14 ;
F_9 ( V_11 ) ;
V_10 = NULL ;
V_11 = NULL ;
}
}
struct V_3 * F_10 ( struct V_56 * V_57 ,
struct V_1 * V_58 ,
const struct V_5 * V_6 )
{
struct V_3 * V_4 ;
if ( ! V_58 )
return NULL ;
V_4 = F_11 ( V_57 , sizeof( * V_4 ) , V_59 ) ;
if ( ! V_4 )
return NULL ;
F_1 ( V_58 , & V_4 , V_6 ) ;
return V_4 ;
}
static void F_12 ( struct V_56 * V_57 , void * V_60 )
{
struct V_61 * V_62 = V_60 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_62 -> V_63 ; V_13 ++ )
F_9 ( V_62 -> V_64 [ V_13 ] . V_65 ) ;
}
int F_13 ( struct V_56 * V_57 , struct V_1 * V_58 ,
struct F_13 * V_64 ,
unsigned int V_63 )
{
unsigned int V_66 = 0 ;
unsigned int V_13 ;
const char * V_15 ;
struct V_1 * V_67 ;
struct V_61 * V_62 ;
if ( ! V_57 || ! V_58 )
return - V_40 ;
V_62 = F_14 ( F_12 ,
sizeof( struct V_61 ) ,
V_59 ) ;
if ( ! V_62 )
return - V_68 ;
V_62 -> V_64 = V_64 ;
V_62 -> V_63 = V_63 ;
F_15 ( V_57 , V_62 ) ;
for ( V_13 = 0 ; V_13 < V_63 ; V_13 ++ ) {
struct F_13 * V_69 = & V_64 [ V_13 ] ;
V_69 -> V_4 = NULL ;
V_69 -> V_65 = NULL ;
}
F_16 (node, child) {
V_15 = F_2 ( V_67 ,
L_26 , NULL ) ;
if ( ! V_15 )
V_15 = V_67 -> V_15 ;
for ( V_13 = 0 ; V_13 < V_63 ; V_13 ++ ) {
struct F_13 * V_69 = & V_64 [ V_13 ] ;
if ( V_69 -> V_65 )
continue;
if ( strcmp ( V_69 -> V_15 , V_15 ) )
continue;
V_69 -> V_4 =
F_10 ( V_57 , V_67 ,
V_69 -> V_6 ) ;
if ( ! V_69 -> V_4 ) {
F_17 ( V_57 ,
L_27 ,
V_67 -> V_15 ) ;
return - V_40 ;
}
V_69 -> V_65 = F_18 ( V_67 ) ;
V_66 ++ ;
break;
}
}
return V_66 ;
}
struct V_3 * F_19 ( struct V_56 * V_57 ,
const struct V_5 * V_6 ,
struct V_70 * V_71 ,
struct V_1 * * V_58 )
{
struct V_1 * V_72 , * V_67 ;
struct V_3 * V_4 = NULL ;
const char * V_15 ;
if ( ! V_57 -> V_65 || ! V_6 -> V_73 )
return NULL ;
if ( V_6 -> V_74 )
V_72 = F_8 ( V_57 -> V_65 ,
V_6 -> V_74 ) ;
else
V_72 = V_57 -> V_65 ;
if ( ! V_72 ) {
F_20 ( V_57 , L_28 ,
V_6 -> V_74 ) ;
return NULL ;
}
F_21 (search, child) {
V_15 = F_2 ( V_67 , L_26 , NULL ) ;
if ( ! V_15 )
V_15 = V_67 -> V_15 ;
if ( strcmp ( V_6 -> V_73 , V_15 ) )
continue;
V_4 = F_10 ( V_57 , V_67 , V_6 ) ;
if ( ! V_4 ) {
F_17 ( V_57 ,
L_27 ,
V_67 -> V_15 ) ;
break;
}
if ( V_6 -> V_75 ) {
if ( V_6 -> V_75 ( V_67 , V_6 , V_71 ) ) {
F_17 ( V_57 ,
L_29 ,
V_67 -> V_15 ) ;
V_4 = NULL ;
break;
}
}
F_18 ( V_67 ) ;
* V_58 = V_67 ;
break;
}
F_9 ( V_72 ) ;
return V_4 ;
}
