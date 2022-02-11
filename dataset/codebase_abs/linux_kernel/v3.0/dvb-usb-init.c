static int F_1 ( struct V_1 * V_2 , short * V_3 )
{
struct V_4 * V_5 ;
int V_6 , V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 . V_9 ; V_7 ++ ) {
V_5 = & V_2 -> V_10 [ V_7 ] ;
V_5 -> V_11 = V_2 ;
V_5 -> V_12 = V_7 ;
memcpy ( & V_5 -> V_8 , & V_2 -> V_8 . V_10 [ V_7 ] , sizeof( struct V_13 ) ) ;
if ( V_2 -> V_14 -> V_15 == V_16 && ! ( V_5 -> V_8 . V_17 & V_18 ) ) {
F_2 ( L_1 ) ;
return - V_19 ;
}
if ( ( V_2 -> V_14 -> V_15 == V_16 && V_5 -> V_8 . V_17 & V_18 ) ||
( V_5 -> V_8 . V_17 & V_20 ) ) {
F_3 ( L_2 , V_5 -> V_8 . V_21 ) ;
V_5 -> V_22 = 1 ;
V_5 -> V_23 = V_5 -> V_8 . V_21 ;
} else {
F_3 ( L_3 ) ;
V_5 -> V_22 = 0 ;
V_5 -> V_23 = 255 ;
}
if ( ! V_5 -> V_22 &&
V_24 &&
V_5 -> V_8 . V_17 & V_18 ) {
F_3 ( L_4 ) ;
V_5 -> V_22 = 1 ;
V_5 -> V_23 = V_5 -> V_8 . V_21 ;
}
if ( V_5 -> V_8 . V_25 > 0 ) {
V_5 -> V_26 = F_4 ( V_5 -> V_8 . V_25 , V_27 ) ;
if ( V_5 -> V_26 == NULL ) {
F_2 ( L_5 , V_7 ) ;
return - V_28 ;
}
}
if ( ( V_6 = F_5 ( V_5 ) ) ||
( V_6 = F_6 ( V_5 , V_3 ) ) ||
( V_6 = F_7 ( V_5 ) ) ) {
return V_6 ;
}
V_2 -> V_29 ++ ;
V_2 -> V_30 |= V_31 ;
}
if ( V_2 -> V_8 . V_32 != 0 ) {
F_8 ( V_2 -> V_14 , F_9 ( V_2 -> V_14 , V_2 -> V_8 . V_32 ) ) ;
F_8 ( V_2 -> V_14 , F_10 ( V_2 -> V_14 , V_2 -> V_8 . V_32 ) ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_29 ; V_7 ++ ) {
F_12 ( & V_2 -> V_10 [ V_7 ] ) ;
F_13 ( & V_2 -> V_10 [ V_7 ] ) ;
F_14 ( & V_2 -> V_10 [ V_7 ] ) ;
F_15 ( V_2 -> V_10 [ V_7 ] . V_26 ) ;
}
V_2 -> V_29 = 0 ;
V_2 -> V_30 &= ~ V_31 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_17 ( L_6 , V_2 -> V_30 ) ;
F_18 ( V_2 ) ;
F_11 ( V_2 ) ;
F_19 ( V_2 ) ;
F_17 ( L_7 , V_2 -> V_30 ) ;
V_2 -> V_30 = V_33 ;
F_15 ( V_2 -> V_26 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , short * V_34 )
{
int V_6 = 0 ;
F_21 ( & V_2 -> V_35 ) ;
F_21 ( & V_2 -> V_36 ) ;
V_2 -> V_30 = V_33 ;
if ( V_2 -> V_8 . V_25 > 0 ) {
V_2 -> V_26 = F_4 ( V_2 -> V_8 . V_25 , V_27 ) ;
if ( V_2 -> V_26 == NULL ) {
F_2 ( L_8 ) ;
return - V_28 ;
}
}
F_22 ( V_2 , 1 ) ;
if ( ( V_6 = F_23 ( V_2 ) ) ||
( V_6 = F_1 ( V_2 , V_34 ) ) ) {
F_16 ( V_2 ) ;
return V_6 ;
}
if ( ( V_6 = F_24 ( V_2 ) ) )
F_2 ( L_9 ) ;
F_22 ( V_2 , 0 ) ;
return 0 ;
}
static struct V_37 * F_25 ( struct V_38 * V_14 , struct V_39 * V_8 , int * V_40 )
{
int V_41 , V_42 ;
struct V_37 * V_43 = NULL ;
* V_40 = - 1 ;
for ( V_41 = 0 ; V_41 < V_8 -> V_44 ; V_41 ++ ) {
for ( V_42 = 0 ; V_42 < V_45 && V_8 -> V_46 [ V_41 ] . V_47 [ V_42 ] != NULL ; V_42 ++ ) {
F_17 ( L_10 , V_8 -> V_46 [ V_41 ] . V_47 [ V_42 ] -> V_48 , V_8 -> V_46 [ V_41 ] . V_47 [ V_42 ] -> V_49 ) ;
if ( V_8 -> V_46 [ V_41 ] . V_47 [ V_42 ] -> V_48 == F_26 ( V_14 -> V_50 . V_48 ) &&
V_8 -> V_46 [ V_41 ] . V_47 [ V_42 ] -> V_49 == F_26 ( V_14 -> V_50 . V_49 ) ) {
* V_40 = 1 ;
V_43 = & V_8 -> V_46 [ V_41 ] ;
break;
}
}
if ( V_43 != NULL )
break;
for ( V_42 = 0 ; V_42 < V_45 && V_8 -> V_46 [ V_41 ] . V_51 [ V_42 ] != NULL ; V_42 ++ ) {
F_17 ( L_11 , V_8 -> V_46 [ V_41 ] . V_51 [ V_42 ] -> V_48 , V_8 -> V_46 [ V_41 ] . V_51 [ V_42 ] -> V_49 ) ;
if ( V_8 -> V_46 [ V_41 ] . V_51 [ V_42 ] -> V_48 == F_26 ( V_14 -> V_50 . V_48 ) &&
V_8 -> V_46 [ V_41 ] . V_51 [ V_42 ] -> V_49 == F_26 ( V_14 -> V_50 . V_49 ) ) {
* V_40 = 0 ;
V_43 = & V_8 -> V_46 [ V_41 ] ;
break;
}
}
}
if ( V_43 != NULL && V_8 -> V_52 != NULL )
V_8 -> V_52 ( V_14 , V_8 , & V_43 , V_40 ) ;
return V_43 ;
}
int F_22 ( struct V_1 * V_2 , int V_53 )
{
if ( V_53 )
V_2 -> V_54 ++ ;
else
V_2 -> V_54 -- ;
if ( V_2 -> V_54 == 0 || ( V_53 && V_2 -> V_54 == 1 ) ) {
F_17 ( L_12 , V_53 ) ;
if ( V_2 -> V_8 . V_55 )
return V_2 -> V_8 . V_55 ( V_2 , V_53 ) ;
}
return 0 ;
}
int F_27 ( struct V_56 * V_57 ,
struct V_39 * V_8 ,
struct V_58 * V_59 , struct V_1 * * V_60 ,
short * V_34 )
{
struct V_38 * V_14 = F_28 ( V_57 ) ;
struct V_1 * V_2 = NULL ;
struct V_37 * V_43 = NULL ;
int V_6 = - V_28 , V_40 = 0 ;
if ( V_60 != NULL )
* V_60 = NULL ;
if ( ( V_43 = F_25 ( V_14 , V_8 , & V_40 ) ) == NULL ) {
F_29 ( L_13 ) ;
return - V_19 ;
}
if ( V_40 ) {
F_3 ( L_14 , V_43 -> V_61 ) ;
V_6 = F_30 ( V_14 , V_8 ) ;
if ( ! V_8 -> V_62 || V_6 != 0 )
return V_6 ;
}
F_3 ( L_15 , V_43 -> V_61 ) ;
V_2 = F_4 ( sizeof( struct V_1 ) , V_27 ) ;
if ( V_2 == NULL ) {
F_2 ( L_16 ) ;
return - V_28 ;
}
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_8 , V_8 , sizeof( struct V_39 ) ) ;
V_2 -> V_43 = V_43 ;
V_2 -> V_59 = V_59 ;
F_31 ( V_57 , V_2 ) ;
if ( V_60 != NULL )
* V_60 = V_2 ;
V_6 = F_20 ( V_2 , V_34 ) ;
if ( V_6 == 0 )
F_3 ( L_17 , V_43 -> V_61 ) ;
else
F_3 ( L_18 , V_43 -> V_61 , V_6 ) ;
return V_6 ;
}
void F_32 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_33 ( V_57 ) ;
const char * V_61 = L_19 ;
F_31 ( V_57 , NULL ) ;
if ( V_2 != NULL && V_2 -> V_43 != NULL ) {
V_61 = V_2 -> V_43 -> V_61 ;
F_16 ( V_2 ) ;
}
F_3 ( L_20 , V_61 ) ;
}
