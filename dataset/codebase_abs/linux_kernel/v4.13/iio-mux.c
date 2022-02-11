static int F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = & V_1 -> V_4 [ V_2 ] ;
struct V_5 const * V_6 = & V_1 -> V_6 [ V_2 ] ;
int V_7 ;
int V_8 ;
V_7 = F_2 ( V_1 -> V_9 , V_6 -> V_10 ) ;
if ( V_7 < 0 ) {
V_1 -> V_11 = - 1 ;
return V_7 ;
}
if ( V_1 -> V_11 == V_6 -> V_10 )
return 0 ;
if ( V_6 -> V_12 ) {
for ( V_8 = 0 ; V_6 -> V_12 [ V_8 ] . V_13 ; ++ V_8 ) {
const char * V_14 = V_6 -> V_12 [ V_8 ] . V_13 ;
struct V_15 * V_16 ;
V_16 = & V_4 -> V_17 [ V_8 ] ;
if ( V_16 -> V_18 < 0 )
continue;
V_7 = F_3 ( V_1 -> V_19 , V_14 ,
V_16 -> V_20 ,
V_16 -> V_18 ) ;
if ( V_7 < 0 ) {
F_4 ( V_1 -> V_9 ) ;
V_1 -> V_11 = - 1 ;
return V_7 ;
}
}
}
V_1 -> V_11 = V_6 -> V_10 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_1 )
{
F_4 ( V_1 -> V_9 ) ;
}
static int F_6 ( struct V_21 * V_22 ,
struct V_5 const * V_6 ,
int * V_23 , int * V_24 , long V_25 )
{
struct V_1 * V_1 = F_7 ( V_22 ) ;
int V_2 = V_6 - V_1 -> V_6 ;
int V_7 ;
V_7 = F_1 ( V_1 , V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( V_25 ) {
case V_26 :
V_7 = F_8 ( V_1 -> V_19 , V_23 ) ;
break;
case V_27 :
V_7 = F_9 ( V_1 -> V_19 , V_23 , V_24 ) ;
break;
default:
V_7 = - V_28 ;
}
F_5 ( V_1 ) ;
return V_7 ;
}
static int F_10 ( struct V_21 * V_22 ,
struct V_5 const * V_6 ,
const int * * V_29 , int * type , int * V_30 ,
long V_25 )
{
struct V_1 * V_1 = F_7 ( V_22 ) ;
int V_2 = V_6 - V_1 -> V_6 ;
int V_7 ;
V_7 = F_1 ( V_1 , V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( V_25 ) {
case V_26 :
* type = V_31 ;
V_7 = F_11 ( V_1 -> V_19 , V_29 , V_30 ) ;
break;
default:
V_7 = - V_28 ;
}
F_5 ( V_1 ) ;
return V_7 ;
}
static int F_12 ( struct V_21 * V_22 ,
struct V_5 const * V_6 ,
int V_23 , int V_24 , long V_25 )
{
struct V_1 * V_1 = F_7 ( V_22 ) ;
int V_2 = V_6 - V_1 -> V_6 ;
int V_7 ;
V_7 = F_1 ( V_1 , V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( V_25 ) {
case V_26 :
V_7 = F_13 ( V_1 -> V_19 , V_23 ) ;
break;
default:
V_7 = - V_28 ;
}
F_5 ( V_1 ) ;
return V_7 ;
}
static T_1 F_14 ( struct V_21 * V_22 , T_2 V_32 ,
struct V_5 const * V_6 , char * V_33 )
{
struct V_1 * V_1 = F_7 ( V_22 ) ;
int V_2 = V_6 - V_1 -> V_6 ;
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_15 ( V_1 -> V_19 ,
V_1 -> V_12 [ V_32 ] . V_13 ,
V_33 ) ;
F_5 ( V_1 ) ;
return V_7 ;
}
static T_1 F_16 ( struct V_21 * V_22 , T_2 V_32 ,
struct V_5 const * V_6 ,
const char * V_33 , T_3 V_34 )
{
struct V_35 * V_36 = V_22 -> V_36 . V_19 ;
struct V_1 * V_1 = F_7 ( V_22 ) ;
int V_2 = V_6 - V_1 -> V_6 ;
char * V_37 ;
T_1 V_7 ;
if ( V_34 >= V_38 )
return - V_28 ;
V_7 = F_1 ( V_1 , V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_37 = F_17 ( V_36 , V_33 , V_34 + 1 , V_39 ) ;
if ( ! V_37 ) {
F_5 ( V_1 ) ;
return - V_40 ;
}
V_37 [ V_34 ] = 0 ;
V_7 = F_3 ( V_1 -> V_19 ,
V_1 -> V_12 [ V_32 ] . V_13 ,
V_33 , V_34 ) ;
if ( V_7 < 0 ) {
F_5 ( V_1 ) ;
F_18 ( V_36 , V_37 ) ;
return V_7 ;
}
F_18 ( V_36 , V_1 -> V_4 [ V_2 ] . V_17 [ V_32 ] . V_20 ) ;
V_1 -> V_4 [ V_2 ] . V_17 [ V_32 ] . V_20 = V_37 ;
V_1 -> V_4 [ V_2 ] . V_17 [ V_32 ] . V_18 = V_34 ;
F_5 ( V_1 ) ;
return V_7 ;
}
static int F_19 ( struct V_35 * V_36 , struct V_1 * V_1 ,
T_4 V_41 , const char * V_42 , int V_2 )
{
struct V_3 * V_4 = & V_1 -> V_4 [ V_2 ] ;
struct V_5 * V_6 = & V_1 -> V_6 [ V_2 ] ;
struct V_5 const * V_43 = V_1 -> V_19 -> V_10 ;
char * V_44 = NULL ;
int V_45 ;
int V_8 ;
int V_7 ;
V_6 -> V_46 = 1 ;
V_6 -> V_47 = V_43 -> V_47 ;
V_6 -> V_48 = V_42 ;
V_6 -> V_12 = V_1 -> V_12 ;
V_7 = F_20 ( V_1 -> V_19 , & V_6 -> type ) ;
if ( V_7 < 0 ) {
F_21 ( V_36 , L_1 ) ;
return V_7 ;
}
if ( F_22 ( V_43 , V_26 ) )
V_6 -> V_49 |= F_23 ( V_26 ) ;
if ( F_22 ( V_43 , V_27 ) )
V_6 -> V_49 |= F_23 ( V_27 ) ;
if ( F_24 ( V_43 , V_26 ) )
V_6 -> V_50 |= F_23 ( V_26 ) ;
if ( V_41 >= F_25 ( V_1 -> V_9 ) ) {
F_21 ( V_36 , L_2 ) ;
return - V_28 ;
}
V_6 -> V_10 = V_41 ;
V_45 = F_26 ( V_1 -> V_19 ) ;
if ( V_45 ) {
V_44 = F_27 ( V_36 , V_38 , V_39 ) ;
if ( ! V_44 )
return - V_40 ;
}
V_4 -> V_17 = F_27 ( V_36 ,
sizeof( * V_4 -> V_17 ) *
V_45 , V_39 ) ;
for ( V_8 = 0 ; V_8 < V_45 ; ++ V_8 ) {
V_4 -> V_17 [ V_8 ] . V_18 = - 1 ;
if ( ! V_43 -> V_12 [ V_8 ] . V_51 )
continue;
if ( ! V_43 -> V_12 [ V_8 ] . V_52 )
continue;
V_7 = F_15 ( V_1 -> V_19 ,
V_1 -> V_12 [ V_8 ] . V_13 ,
V_44 ) ;
if ( V_7 < 0 ) {
F_21 ( V_36 , L_3 ,
V_43 -> V_12 [ V_8 ] . V_13 ) ;
return V_7 ;
}
if ( V_7 >= V_38 ) {
F_21 ( V_36 , L_4 ,
V_43 -> V_12 [ V_8 ] . V_13 ) ;
return - V_28 ;
}
V_4 -> V_17 [ V_8 ] . V_20 = F_17 ( V_36 , V_44 , V_7 + 1 ,
V_39 ) ;
V_4 -> V_17 [ V_8 ] . V_20 [ V_7 ] = 0 ;
V_4 -> V_17 [ V_8 ] . V_18 = V_7 ;
}
if ( V_44 )
F_18 ( V_36 , V_44 ) ;
return 0 ;
}
static int F_28 ( struct V_53 * V_54 )
{
struct V_35 * V_36 = & V_54 -> V_36 ;
struct V_55 * V_56 = V_54 -> V_36 . V_57 ;
struct V_21 * V_22 ;
struct V_58 * V_19 ;
struct V_1 * V_1 ;
struct V_59 * V_60 ;
const char * V_42 ;
T_4 V_41 ;
int V_61 ;
int V_62 ;
int V_63 ;
int V_8 ;
int V_7 ;
if ( ! V_56 )
return - V_64 ;
V_19 = F_29 ( V_36 , L_5 ) ;
if ( F_30 ( V_19 ) ) {
if ( F_31 ( V_19 ) != - V_65 )
F_21 ( V_36 , L_6 ) ;
return F_31 ( V_19 ) ;
}
V_61 = F_26 ( V_19 ) ;
if ( V_61 ) {
V_61 += 1 ;
V_61 *= sizeof( * V_1 -> V_12 ) ;
}
V_62 = 0 ;
F_32 (np, L_7 , prop, label) {
if ( * V_42 )
V_62 ++ ;
}
if ( V_62 <= 0 ) {
F_21 ( V_36 , L_8 ) ;
return - V_28 ;
}
V_63 = sizeof( * V_1 ) ;
V_63 += sizeof( * V_1 -> V_4 ) * V_62 ;
V_63 += sizeof( * V_1 -> V_6 ) * V_62 ;
V_63 += V_61 ;
V_22 = F_33 ( V_36 , V_63 ) ;
if ( ! V_22 )
return - V_40 ;
V_1 = F_7 ( V_22 ) ;
V_1 -> V_4 = (struct V_3 * ) ( V_1 + 1 ) ;
V_1 -> V_6 = (struct V_5 * ) ( V_1 -> V_4 + V_62 ) ;
F_34 ( V_54 , V_22 ) ;
V_1 -> V_19 = V_19 ;
V_1 -> V_11 = - 1 ;
V_22 -> V_13 = F_35 ( V_36 ) ;
V_22 -> V_36 . V_19 = V_36 ;
V_22 -> V_66 = & V_67 ;
V_22 -> V_68 = V_69 ;
V_22 -> V_70 = V_1 -> V_6 ;
V_22 -> V_71 = V_62 ;
if ( V_61 ) {
V_1 -> V_12 = F_17 ( V_36 ,
V_19 -> V_10 -> V_12 ,
V_61 , V_39 ) ;
if ( ! V_1 -> V_12 )
return - V_40 ;
for ( V_8 = 0 ; V_1 -> V_12 [ V_8 ] . V_13 ; ++ V_8 ) {
if ( V_19 -> V_10 -> V_12 [ V_8 ] . V_52 )
V_1 -> V_12 [ V_8 ] . V_52 = F_14 ;
if ( V_19 -> V_10 -> V_12 [ V_8 ] . V_51 )
V_1 -> V_12 [ V_8 ] . V_51 = F_16 ;
V_1 -> V_12 [ V_8 ] . V_32 = V_8 ;
}
}
V_1 -> V_9 = F_36 ( V_36 , NULL ) ;
if ( F_30 ( V_1 -> V_9 ) ) {
if ( F_31 ( V_1 -> V_9 ) != - V_65 )
F_21 ( V_36 , L_9 ) ;
return F_31 ( V_1 -> V_9 ) ;
}
V_8 = 0 ;
F_37 (np, L_7 , prop, label, state) {
if ( ! * V_42 )
continue;
V_7 = F_19 ( V_36 , V_1 , V_41 , V_42 , V_8 ++ ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_38 ( V_36 , V_22 ) ;
if ( V_7 ) {
F_21 ( V_36 , L_10 ) ;
return V_7 ;
}
return 0 ;
}
