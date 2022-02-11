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
if ( V_10 -> V_22 != V_10 -> V_23 )
V_10 -> V_18 |= V_24 ;
V_10 -> V_25 = F_5 ( V_2 , L_7 ) ;
V_10 -> V_26 = F_5 ( V_2 , L_8 ) ;
if ( ! V_10 -> V_26 )
V_10 -> V_18 |= V_27 ;
if ( F_5 ( V_2 , L_9 ) )
V_10 -> V_18 |= V_28 ;
V_14 = F_4 ( V_2 , L_10 , & V_16 ) ;
if ( ! V_14 ) {
if ( V_16 )
V_10 -> V_29 = V_16 ;
else
V_10 -> V_30 = true ;
}
V_14 = F_4 ( V_2 , L_11 , & V_16 ) ;
if ( ! V_14 )
V_10 -> V_31 = V_16 ;
if ( ! F_4 ( V_2 , L_12 , & V_16 ) ) {
if ( V_6 && V_6 -> V_32 ) {
V_14 = V_6 -> V_32 ( V_16 ) ;
if ( V_14 == - V_33 )
F_6 ( L_13 , V_2 -> V_17 , V_16 ) ;
else
V_10 -> V_34 = V_14 ;
} else {
F_7 ( L_14 ,
V_2 -> V_17 , V_16 ) ;
}
}
for ( V_15 = 0 ; V_15 < F_8 ( V_35 ) ; V_15 ++ ) {
switch ( V_15 ) {
case V_36 :
V_12 = & V_10 -> V_37 ;
break;
case V_38 :
V_12 = & V_10 -> V_39 ;
break;
case V_40 :
case V_41 :
case V_42 :
default:
continue;
} ;
V_13 = F_9 ( V_2 , V_35 [ V_15 ] ) ;
if ( ! V_13 || ! V_12 )
continue;
if ( ! F_4 ( V_13 , L_15 ,
& V_16 ) ) {
if ( V_6 && V_6 -> V_32 ) {
V_14 = V_6 -> V_32 ( V_16 ) ;
if ( V_14 == - V_33 )
F_6 ( L_13 ,
V_2 -> V_17 , V_16 ) ;
else
V_12 -> V_43 = V_14 ;
} else {
F_7 ( L_14 ,
V_2 -> V_17 , V_16 ) ;
}
}
if ( F_5 ( V_13 ,
L_16 ) )
V_12 -> V_44 = true ;
else if ( F_5 ( V_13 ,
L_17 ) )
V_12 -> V_45 = true ;
if ( ! F_4 ( V_13 ,
L_18 , & V_16 ) )
V_12 -> V_46 = V_16 ;
F_10 ( V_13 ) ;
V_12 = NULL ;
V_13 = NULL ;
}
}
struct V_3 * F_11 ( struct V_47 * V_48 ,
struct V_1 * V_49 ,
const struct V_5 * V_6 )
{
struct V_3 * V_4 ;
if ( ! V_49 )
return NULL ;
V_4 = F_12 ( V_48 , sizeof( * V_4 ) , V_50 ) ;
if ( ! V_4 )
return NULL ;
F_1 ( V_49 , & V_4 , V_6 ) ;
return V_4 ;
}
static void F_13 ( struct V_47 * V_48 , void * V_51 )
{
struct V_52 * V_53 = V_51 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_53 -> V_54 ; V_15 ++ )
F_10 ( V_53 -> V_55 [ V_15 ] . V_56 ) ;
}
int F_14 ( struct V_47 * V_48 , struct V_1 * V_49 ,
struct F_14 * V_55 ,
unsigned int V_54 )
{
unsigned int V_57 = 0 ;
unsigned int V_15 ;
const char * V_17 ;
struct V_1 * V_58 ;
struct V_52 * V_53 ;
if ( ! V_48 || ! V_49 )
return - V_33 ;
V_53 = F_15 ( F_13 ,
sizeof( struct V_52 ) ,
V_50 ) ;
if ( ! V_53 )
return - V_59 ;
V_53 -> V_55 = V_55 ;
V_53 -> V_54 = V_54 ;
F_16 ( V_48 , V_53 ) ;
for ( V_15 = 0 ; V_15 < V_54 ; V_15 ++ ) {
struct F_14 * V_60 = & V_55 [ V_15 ] ;
V_60 -> V_4 = NULL ;
V_60 -> V_56 = NULL ;
}
F_17 (node, child) {
V_17 = F_2 ( V_58 ,
L_19 , NULL ) ;
if ( ! V_17 )
V_17 = V_58 -> V_17 ;
for ( V_15 = 0 ; V_15 < V_54 ; V_15 ++ ) {
struct F_14 * V_60 = & V_55 [ V_15 ] ;
if ( V_60 -> V_56 )
continue;
if ( strcmp ( V_60 -> V_17 , V_17 ) )
continue;
V_60 -> V_4 =
F_11 ( V_48 , V_58 ,
V_60 -> V_6 ) ;
if ( ! V_60 -> V_4 ) {
F_18 ( V_48 ,
L_20 ,
V_58 -> V_17 ) ;
return - V_33 ;
}
V_60 -> V_56 = F_19 ( V_58 ) ;
V_57 ++ ;
break;
}
}
return V_57 ;
}
struct V_3 * F_20 ( struct V_47 * V_48 ,
const struct V_5 * V_6 ,
struct V_1 * * V_49 )
{
struct V_1 * V_61 , * V_58 ;
struct V_3 * V_4 = NULL ;
const char * V_17 ;
if ( ! V_48 -> V_56 || ! V_6 -> V_62 )
return NULL ;
if ( V_6 -> V_63 )
V_61 = F_9 ( V_48 -> V_56 ,
V_6 -> V_63 ) ;
else
V_61 = V_48 -> V_56 ;
if ( ! V_61 ) {
F_21 ( V_48 , L_21 ,
V_6 -> V_63 ) ;
return NULL ;
}
F_17 (search, child) {
V_17 = F_2 ( V_58 , L_19 , NULL ) ;
if ( ! V_17 )
V_17 = V_58 -> V_17 ;
if ( strcmp ( V_6 -> V_62 , V_17 ) )
continue;
V_4 = F_11 ( V_48 , V_58 , V_6 ) ;
if ( ! V_4 ) {
F_18 ( V_48 ,
L_20 ,
V_58 -> V_17 ) ;
break;
}
F_19 ( V_58 ) ;
* V_49 = V_58 ;
break;
}
F_10 ( V_61 ) ;
return V_4 ;
}
