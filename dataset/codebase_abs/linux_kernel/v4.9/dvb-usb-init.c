static int F_1 ( struct V_1 * V_2 , short * V_3 )
{
struct V_4 * V_5 ;
int V_6 , V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_9 . V_10 ; V_7 ++ ) {
V_5 = & V_2 -> V_11 [ V_7 ] ;
V_5 -> V_12 = V_2 ;
V_5 -> V_13 = V_7 ;
memcpy ( & V_5 -> V_9 , & V_2 -> V_9 . V_11 [ V_7 ] , sizeof( struct V_14 ) ) ;
for ( V_8 = 0 ; V_8 < V_5 -> V_9 . V_15 ; V_8 ++ ) {
struct V_16 * V_9 = & V_5 -> V_9 . V_17 [ V_8 ] ;
if ( V_2 -> V_18 -> V_19 == V_20 && ! ( V_9 -> V_21 & V_22 ) ) {
F_2 ( L_1 ) ;
return - V_23 ;
}
if ( ( V_2 -> V_18 -> V_19 == V_20 && V_9 -> V_21 & V_22 ) ||
( V_9 -> V_21 & V_24 ) ) {
F_3 ( L_2 , V_9 -> V_25 ) ;
V_5 -> V_26 [ V_8 ] . V_27 = 1 ;
V_5 -> V_26 [ V_8 ] . V_28 = V_9 -> V_25 ;
} else {
F_3 ( L_3 ) ;
V_5 -> V_26 [ V_8 ] . V_27 = 0 ;
V_5 -> V_26 [ V_8 ] . V_28 = 255 ;
}
if ( ! V_5 -> V_26 [ V_8 ] . V_27 &&
V_29 &&
V_9 -> V_21 & V_22 ) {
F_3 ( L_4 ) ;
V_5 -> V_26 [ V_8 ] . V_27 = 1 ;
V_5 -> V_26 [ V_8 ] . V_28 = V_9 -> V_25 ;
}
if ( V_9 -> V_30 > 0 ) {
V_5 -> V_26 [ V_8 ] . V_31 = F_4 ( V_9 -> V_30 , V_32 ) ;
if ( V_5 -> V_26 [ V_8 ] . V_31 == NULL ) {
F_2 ( L_5 , V_7 , V_8 ) ;
return - V_33 ;
}
}
}
if ( V_5 -> V_9 . V_30 > 0 ) {
V_5 -> V_31 = F_4 ( V_5 -> V_9 . V_30 , V_32 ) ;
if ( V_5 -> V_31 == NULL ) {
F_2 ( L_6 , V_7 ) ;
return - V_33 ;
}
}
if ( ( V_6 = F_5 ( V_5 ) ) ||
( V_6 = F_6 ( V_5 , V_3 ) ) ||
( V_6 = F_7 ( V_5 ) ) ) {
return V_6 ;
}
if ( V_5 -> V_26 [ 1 ] . V_17 )
V_5 -> V_34 . V_35 = 1 ;
V_2 -> V_36 ++ ;
V_2 -> V_37 |= V_38 ;
}
if ( V_2 -> V_9 . V_39 != 0 ) {
F_8 ( V_2 -> V_18 , F_9 ( V_2 -> V_18 , V_2 -> V_9 . V_39 ) ) ;
F_8 ( V_2 -> V_18 , F_10 ( V_2 -> V_18 , V_2 -> V_9 . V_39 ) ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_36 ; V_7 ++ ) {
F_12 ( & V_2 -> V_11 [ V_7 ] ) ;
F_13 ( & V_2 -> V_11 [ V_7 ] ) ;
F_14 ( & V_2 -> V_11 [ V_7 ] ) ;
F_15 ( V_2 -> V_11 [ V_7 ] . V_31 ) ;
}
V_2 -> V_36 = 0 ;
V_2 -> V_37 &= ~ V_38 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_17 ( L_7 , V_2 -> V_37 ) ;
F_18 ( V_2 ) ;
F_11 ( V_2 ) ;
F_19 ( V_2 ) ;
F_17 ( L_8 , V_2 -> V_37 ) ;
V_2 -> V_37 = V_40 ;
F_15 ( V_2 -> V_31 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , short * V_41 )
{
int V_6 = 0 ;
F_21 ( & V_2 -> V_42 ) ;
F_21 ( & V_2 -> V_43 ) ;
F_21 ( & V_2 -> V_44 ) ;
V_2 -> V_37 = V_40 ;
if ( V_2 -> V_9 . V_30 > 0 ) {
V_2 -> V_31 = F_4 ( V_2 -> V_9 . V_30 , V_32 ) ;
if ( V_2 -> V_31 == NULL ) {
F_2 ( L_9 ) ;
return - V_33 ;
}
}
F_22 ( V_2 , 1 ) ;
if ( ( V_6 = F_23 ( V_2 ) ) ||
( V_6 = F_1 ( V_2 , V_41 ) ) ) {
F_16 ( V_2 ) ;
return V_6 ;
}
if ( ( V_6 = F_24 ( V_2 ) ) )
F_2 ( L_10 ) ;
F_22 ( V_2 , 0 ) ;
return 0 ;
}
static struct V_45 * F_25 ( struct V_46 * V_18 , struct V_47 * V_9 , int * V_48 )
{
int V_49 , V_50 ;
struct V_45 * V_51 = NULL ;
* V_48 = - 1 ;
for ( V_49 = 0 ; V_49 < V_9 -> V_52 ; V_49 ++ ) {
for ( V_50 = 0 ; V_50 < V_53 && V_9 -> V_54 [ V_49 ] . V_55 [ V_50 ] != NULL ; V_50 ++ ) {
F_17 ( L_11 , V_9 -> V_54 [ V_49 ] . V_55 [ V_50 ] -> V_56 , V_9 -> V_54 [ V_49 ] . V_55 [ V_50 ] -> V_57 ) ;
if ( V_9 -> V_54 [ V_49 ] . V_55 [ V_50 ] -> V_56 == F_26 ( V_18 -> V_58 . V_56 ) &&
V_9 -> V_54 [ V_49 ] . V_55 [ V_50 ] -> V_57 == F_26 ( V_18 -> V_58 . V_57 ) ) {
* V_48 = 1 ;
V_51 = & V_9 -> V_54 [ V_49 ] ;
break;
}
}
if ( V_51 != NULL )
break;
for ( V_50 = 0 ; V_50 < V_53 && V_9 -> V_54 [ V_49 ] . V_59 [ V_50 ] != NULL ; V_50 ++ ) {
F_17 ( L_12 , V_9 -> V_54 [ V_49 ] . V_59 [ V_50 ] -> V_56 , V_9 -> V_54 [ V_49 ] . V_59 [ V_50 ] -> V_57 ) ;
if ( V_9 -> V_54 [ V_49 ] . V_59 [ V_50 ] -> V_56 == F_26 ( V_18 -> V_58 . V_56 ) &&
V_9 -> V_54 [ V_49 ] . V_59 [ V_50 ] -> V_57 == F_26 ( V_18 -> V_58 . V_57 ) ) {
* V_48 = 0 ;
V_51 = & V_9 -> V_54 [ V_49 ] ;
break;
}
}
}
if ( V_51 != NULL && V_9 -> V_60 != NULL )
V_9 -> V_60 ( V_18 , V_9 , & V_51 , V_48 ) ;
return V_51 ;
}
int F_22 ( struct V_1 * V_2 , int V_61 )
{
if ( V_61 )
V_2 -> V_62 ++ ;
else
V_2 -> V_62 -- ;
if ( V_2 -> V_62 == 0 || ( V_61 && V_2 -> V_62 == 1 ) ) {
F_17 ( L_13 , V_61 ) ;
if ( V_2 -> V_9 . V_63 )
return V_2 -> V_9 . V_63 ( V_2 , V_61 ) ;
}
return 0 ;
}
int F_27 ( struct V_64 * V_65 ,
struct V_47 * V_9 ,
struct V_66 * V_67 , struct V_1 * * V_68 ,
short * V_41 )
{
struct V_46 * V_18 = F_28 ( V_65 ) ;
struct V_1 * V_2 = NULL ;
struct V_45 * V_51 = NULL ;
int V_6 = - V_33 , V_48 = 0 ;
if ( V_68 != NULL )
* V_68 = NULL ;
if ( ( V_51 = F_25 ( V_18 , V_9 , & V_48 ) ) == NULL ) {
F_29 ( L_14 ) ;
return - V_23 ;
}
if ( V_48 ) {
F_3 ( L_15 , V_51 -> V_69 ) ;
V_6 = F_30 ( V_18 , V_9 ) ;
if ( ! V_9 -> V_70 || V_6 != 0 )
return V_6 ;
}
F_3 ( L_16 , V_51 -> V_69 ) ;
V_2 = F_4 ( sizeof( struct V_1 ) , V_32 ) ;
if ( V_2 == NULL ) {
F_2 ( L_17 ) ;
return - V_33 ;
}
V_2 -> V_18 = V_18 ;
memcpy ( & V_2 -> V_9 , V_9 , sizeof( struct V_47 ) ) ;
V_2 -> V_51 = V_51 ;
V_2 -> V_67 = V_67 ;
F_31 ( V_65 , V_2 ) ;
if ( V_68 != NULL )
* V_68 = V_2 ;
V_6 = F_20 ( V_2 , V_41 ) ;
if ( V_6 == 0 )
F_3 ( L_18 , V_51 -> V_69 ) ;
else
F_3 ( L_19 , V_51 -> V_69 , V_6 ) ;
return V_6 ;
}
void F_32 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_33 ( V_65 ) ;
const char * V_69 = L_20 ;
F_31 ( V_65 , NULL ) ;
if ( V_2 != NULL && V_2 -> V_51 != NULL ) {
V_69 = V_2 -> V_51 -> V_69 ;
F_16 ( V_2 ) ;
}
F_3 ( L_21 , V_69 ) ;
}
