static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( memcmp ( V_2 -> V_8 , V_4 -> V_8 ,
V_9 ) != 0 || ( V_6 -> V_10 &&
memcmp ( V_2 -> V_11 , V_4 -> V_11 , V_9 ) != 0 ) )
return false ;
return true ;
}
static void F_2 ( struct V_3 * V_4 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_14 * V_15 = F_3 ( V_6 -> V_16 . V_17 -> V_18 ) ;
if ( V_15 -> V_19 -> V_20 )
V_15 -> V_19 -> V_20 ( V_4 ) ;
if ( V_2 -> V_21 )
V_2 -> V_21 = 0 ;
else {
return;
}
F_4 (dev, &port->dev_list, dev_list_node) {
int V_22 , V_23 ;
V_23 = F_5 ( V_13 ) ;
if ( V_23 ) {
F_6 ( V_2 , V_13 ) ;
continue;
}
if ( V_13 -> V_24 == V_25 || V_13 -> V_24 == V_26 ) {
V_13 -> V_27 . V_28 = - 1 ;
for ( V_22 = 0 ; V_22 < V_13 -> V_27 . V_29 ; V_22 ++ ) {
struct V_30 * V_4 = & V_13 -> V_27 . V_30 [ V_22 ] ;
V_4 -> V_31 = - 1 ;
}
}
}
F_7 ( V_2 , V_32 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
int V_22 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_14 * V_15 =
F_3 ( V_6 -> V_16 . V_17 -> V_18 ) ;
unsigned long V_33 ;
if ( V_2 ) {
if ( ! F_1 ( V_2 , V_4 ) )
F_9 ( V_4 , 0 ) ;
else if ( V_4 -> V_21 ) {
V_4 -> V_21 = 0 ;
F_2 ( V_4 ) ;
F_10 ( & V_6 -> V_34 ) ;
return;
} else {
F_11 ( L_1 ,
V_35 , V_4 -> V_36 , V_4 -> V_2 -> V_36 ,
V_4 -> V_2 -> V_29 ) ;
return;
}
}
F_12 ( & V_6 -> V_37 , V_33 ) ;
for ( V_22 = 0 ; V_22 < V_6 -> V_29 ; V_22 ++ ) {
V_2 = V_6 -> V_38 [ V_22 ] ;
F_13 ( & V_2 -> V_39 ) ;
if ( * ( V_40 * ) V_2 -> V_11 &&
F_1 ( V_2 , V_4 ) && V_2 -> V_29 > 0 ) {
F_11 ( L_2 , V_4 -> V_36 ,
V_2 -> V_36 ) ;
break;
}
F_14 ( & V_2 -> V_39 ) ;
}
if ( V_22 == V_6 -> V_29 ) {
for ( V_22 = 0 ; V_22 < V_6 -> V_29 ; V_22 ++ ) {
V_2 = V_6 -> V_38 [ V_22 ] ;
F_13 ( & V_2 -> V_39 ) ;
if ( * ( V_40 * ) V_2 -> V_11 == 0
&& V_2 -> V_29 == 0 ) {
memcpy ( V_2 -> V_11 , V_4 -> V_11 ,
V_9 ) ;
break;
}
F_14 ( & V_2 -> V_39 ) ;
}
}
if ( V_22 >= V_6 -> V_29 ) {
F_15 ( V_41 L_3 ,
V_35 ) ;
F_16 ( & V_6 -> V_37 , V_33 ) ;
return;
}
F_17 ( & V_4 -> V_42 , & V_2 -> V_43 ) ;
F_18 ( V_4 , V_2 -> V_44 ) ;
V_4 -> V_2 = V_2 ;
V_2 -> V_29 ++ ;
V_2 -> V_45 |= ( 1U << V_4 -> V_36 ) ;
if ( * ( V_40 * ) V_2 -> V_8 == 0 ) {
V_2 -> V_46 = V_4 -> V_46 ;
memcpy ( V_2 -> V_8 , V_4 -> V_8 ,
V_9 ) ;
V_2 -> V_47 = V_4 -> V_47 ;
V_2 -> V_48 = V_4 -> V_48 ;
V_2 -> V_49 = V_4 -> V_49 ;
V_2 -> V_50 = V_4 -> V_50 ;
} else
V_2 -> V_50 = F_19 ( V_2 -> V_50 , V_4 -> V_50 ) ;
F_14 ( & V_2 -> V_39 ) ;
F_16 ( & V_6 -> V_37 , V_33 ) ;
if ( ! V_2 -> V_2 ) {
V_2 -> V_2 = F_20 ( V_4 -> V_4 -> V_13 . V_51 , V_2 -> V_36 ) ;
F_21 ( ! V_2 -> V_2 ) ;
F_22 ( V_2 -> V_2 ) ;
}
F_23 ( V_2 -> V_2 , V_4 -> V_4 ) ;
F_11 ( L_4 ,
F_24 ( & V_4 -> V_4 -> V_13 ) , F_24 ( & V_2 -> V_2 -> V_13 ) ,
V_2 -> V_45 ,
F_25 ( V_2 -> V_8 ) ) ;
if ( V_2 -> V_44 )
V_2 -> V_44 -> V_52 = V_2 -> V_29 ;
if ( V_15 -> V_19 -> V_20 )
V_15 -> V_19 -> V_20 ( V_4 ) ;
F_7 ( V_4 -> V_2 , V_53 ) ;
}
void F_9 ( struct V_3 * V_4 , int V_54 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_14 * V_15 =
F_3 ( V_6 -> V_16 . V_17 -> V_18 ) ;
struct V_12 * V_13 ;
unsigned long V_33 ;
if ( ! V_2 )
return;
V_13 = V_2 -> V_44 ;
if ( V_13 )
V_13 -> V_52 -- ;
if ( V_2 -> V_29 == 1 ) {
F_26 ( V_2 , V_54 ) ;
F_27 ( V_2 -> V_2 ) ;
V_2 -> V_2 = NULL ;
} else {
F_28 ( V_2 -> V_2 , V_4 -> V_4 ) ;
F_29 ( V_13 , V_2 -> V_2 ) ;
}
if ( V_15 -> V_19 -> V_55 )
V_15 -> V_19 -> V_55 ( V_4 ) ;
F_12 ( & V_6 -> V_37 , V_33 ) ;
F_13 ( & V_2 -> V_39 ) ;
F_30 ( & V_4 -> V_42 ) ;
F_18 ( V_4 , NULL ) ;
V_4 -> V_2 = NULL ;
V_2 -> V_29 -- ;
V_2 -> V_45 &= ~ ( 1U << V_4 -> V_36 ) ;
if ( V_2 -> V_29 == 0 ) {
F_31 ( & V_2 -> V_43 ) ;
memset ( V_2 -> V_11 , 0 , V_9 ) ;
memset ( V_2 -> V_8 , 0 , V_9 ) ;
V_2 -> V_46 = 0 ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_49 = 0 ;
V_2 -> V_45 = 0 ;
}
F_14 ( & V_2 -> V_39 ) ;
F_16 ( & V_6 -> V_37 , V_33 ) ;
return;
}
void F_32 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_33 ( V_57 ) ;
struct V_3 * V_4 = V_59 -> V_4 ;
F_34 ( V_60 , & V_4 -> V_61 ) ;
F_8 ( V_4 ) ;
}
void F_35 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_33 ( V_57 ) ;
struct V_3 * V_4 = V_59 -> V_4 ;
unsigned long V_33 ;
T_1 V_62 ;
F_34 ( V_63 , & V_4 -> V_61 ) ;
F_12 ( & V_4 -> V_64 , V_33 ) ;
V_62 = V_4 -> V_65 ;
F_16 ( & V_4 -> V_64 , V_33 ) ;
F_11 ( L_5 , V_62 ) ;
F_7 ( V_4 -> V_2 , V_66 ) ;
}
void F_36 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_33 ( V_57 ) ;
struct V_3 * V_4 = V_59 -> V_4 ;
F_34 ( V_67 , & V_4 -> V_61 ) ;
F_9 ( V_4 , 1 ) ;
}
void F_37 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_33 ( V_57 ) ;
struct V_3 * V_4 = V_59 -> V_4 ;
F_34 ( V_68 , & V_4 -> V_61 ) ;
F_9 ( V_4 , 1 ) ;
}
void F_38 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_33 ( V_57 ) ;
struct V_3 * V_4 = V_59 -> V_4 ;
F_34 ( V_69 , & V_4 -> V_61 ) ;
F_9 ( V_4 , 1 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_5 * V_6 , int V_22 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_36 = V_22 ;
F_31 ( & V_2 -> V_70 ) ;
F_31 ( & V_2 -> V_71 ) ;
F_31 ( & V_2 -> V_72 ) ;
F_40 ( & V_2 -> V_39 ) ;
F_31 ( & V_2 -> V_43 ) ;
V_2 -> V_7 = V_6 ;
F_40 ( & V_2 -> V_73 ) ;
}
int F_41 ( struct V_5 * V_6 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_6 -> V_29 ; V_22 ++ ) {
struct V_1 * V_2 = V_6 -> V_38 [ V_22 ] ;
F_39 ( V_2 , V_6 , V_22 ) ;
F_42 ( & V_2 -> V_74 , V_2 ) ;
}
return 0 ;
}
void F_43 ( struct V_5 * V_6 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_6 -> V_29 ; V_22 ++ )
if ( V_6 -> V_75 [ V_22 ] -> V_2 )
F_9 ( V_6 -> V_75 [ V_22 ] , 0 ) ;
}
