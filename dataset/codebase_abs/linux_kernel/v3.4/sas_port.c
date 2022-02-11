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
int V_12 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_13 * V_14 =
F_3 ( V_6 -> V_15 . V_16 -> V_17 ) ;
unsigned long V_18 ;
if ( V_2 ) {
if ( ! F_1 ( V_2 , V_4 ) )
F_4 ( V_4 , 0 ) ;
else {
F_5 ( L_1 ,
V_19 , V_4 -> V_20 , V_4 -> V_2 -> V_20 ,
V_4 -> V_2 -> V_21 ) ;
return;
}
}
F_6 ( & V_6 -> V_22 , V_18 ) ;
for ( V_12 = 0 ; V_12 < V_6 -> V_21 ; V_12 ++ ) {
V_2 = V_6 -> V_23 [ V_12 ] ;
F_7 ( & V_2 -> V_24 ) ;
if ( * ( V_25 * ) V_2 -> V_11 &&
F_1 ( V_2 , V_4 ) && V_2 -> V_21 > 0 ) {
F_5 ( L_2 , V_4 -> V_20 ,
V_2 -> V_20 ) ;
break;
}
F_8 ( & V_2 -> V_24 ) ;
}
if ( V_12 == V_6 -> V_21 ) {
for ( V_12 = 0 ; V_12 < V_6 -> V_21 ; V_12 ++ ) {
V_2 = V_6 -> V_23 [ V_12 ] ;
F_7 ( & V_2 -> V_24 ) ;
if ( * ( V_25 * ) V_2 -> V_11 == 0
&& V_2 -> V_21 == 0 ) {
memcpy ( V_2 -> V_11 , V_4 -> V_11 ,
V_9 ) ;
break;
}
F_8 ( & V_2 -> V_24 ) ;
}
}
if ( V_12 >= V_6 -> V_21 ) {
F_9 ( V_26 L_3 ,
V_19 ) ;
F_10 ( & V_6 -> V_22 , V_18 ) ;
return;
}
F_11 ( & V_4 -> V_27 , & V_2 -> V_28 ) ;
F_12 ( V_4 , V_2 -> V_29 ) ;
V_4 -> V_2 = V_2 ;
V_2 -> V_21 ++ ;
V_2 -> V_30 |= ( 1U << V_4 -> V_20 ) ;
if ( * ( V_25 * ) V_2 -> V_8 == 0 ) {
V_2 -> V_31 = V_4 -> V_31 ;
memcpy ( V_2 -> V_8 , V_4 -> V_8 ,
V_9 ) ;
V_2 -> V_32 = V_4 -> V_32 ;
V_2 -> V_33 = V_4 -> V_33 ;
V_2 -> V_34 = V_4 -> V_34 ;
V_2 -> V_35 = V_4 -> V_35 ;
} else
V_2 -> V_35 = F_13 ( V_2 -> V_35 , V_4 -> V_35 ) ;
F_8 ( & V_2 -> V_24 ) ;
F_10 ( & V_6 -> V_22 , V_18 ) ;
if ( ! V_2 -> V_2 ) {
V_2 -> V_2 = F_14 ( V_4 -> V_4 -> V_36 . V_37 , V_2 -> V_20 ) ;
F_15 ( ! V_2 -> V_2 ) ;
F_16 ( V_2 -> V_2 ) ;
}
F_17 ( V_2 -> V_2 , V_4 -> V_4 ) ;
F_5 ( L_4 ,
F_18 ( & V_4 -> V_4 -> V_36 ) , F_18 ( & V_2 -> V_2 -> V_36 ) ,
V_2 -> V_30 ,
F_19 ( V_2 -> V_8 ) ) ;
if ( V_2 -> V_29 )
V_2 -> V_29 -> V_38 = V_2 -> V_21 ;
if ( V_14 -> V_39 -> V_40 )
V_14 -> V_39 -> V_40 ( V_4 ) ;
F_20 ( V_4 -> V_2 , V_41 ) ;
}
void F_4 ( struct V_3 * V_4 , int V_42 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_13 * V_14 =
F_3 ( V_6 -> V_15 . V_16 -> V_17 ) ;
struct V_43 * V_36 ;
unsigned long V_18 ;
if ( ! V_2 )
return;
V_36 = V_2 -> V_29 ;
if ( V_36 )
V_36 -> V_38 -- ;
if ( V_2 -> V_21 == 1 ) {
F_21 ( V_2 , V_42 ) ;
F_22 ( V_2 -> V_2 ) ;
V_2 -> V_2 = NULL ;
} else {
F_23 ( V_2 -> V_2 , V_4 -> V_4 ) ;
F_24 ( V_36 , V_2 -> V_2 ) ;
}
if ( V_14 -> V_39 -> V_44 )
V_14 -> V_39 -> V_44 ( V_4 ) ;
F_6 ( & V_6 -> V_22 , V_18 ) ;
F_7 ( & V_2 -> V_24 ) ;
F_25 ( & V_4 -> V_27 ) ;
F_12 ( V_4 , NULL ) ;
V_4 -> V_2 = NULL ;
V_2 -> V_21 -- ;
V_2 -> V_30 &= ~ ( 1U << V_4 -> V_20 ) ;
if ( V_2 -> V_21 == 0 ) {
F_26 ( & V_2 -> V_28 ) ;
memset ( V_2 -> V_11 , 0 , V_9 ) ;
memset ( V_2 -> V_8 , 0 , V_9 ) ;
V_2 -> V_31 = 0 ;
V_2 -> V_32 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_30 = 0 ;
}
F_8 ( & V_2 -> V_24 ) ;
F_10 ( & V_6 -> V_22 , V_18 ) ;
return;
}
void F_27 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_28 ( V_46 ) ;
struct V_3 * V_4 = V_48 -> V_4 ;
F_29 ( V_49 , & V_4 -> V_50 ) ;
F_2 ( V_4 ) ;
}
void F_30 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_28 ( V_46 ) ;
struct V_3 * V_4 = V_48 -> V_4 ;
unsigned long V_18 ;
T_1 V_51 ;
F_29 ( V_52 , & V_4 -> V_50 ) ;
F_6 ( & V_4 -> V_53 , V_18 ) ;
V_51 = V_4 -> V_54 ;
F_10 ( & V_4 -> V_53 , V_18 ) ;
F_5 ( L_5 , V_51 ) ;
F_20 ( V_4 -> V_2 , V_55 ) ;
}
void F_31 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_28 ( V_46 ) ;
struct V_3 * V_4 = V_48 -> V_4 ;
F_29 ( V_56 , & V_4 -> V_50 ) ;
F_4 ( V_4 , 1 ) ;
}
void F_32 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_28 ( V_46 ) ;
struct V_3 * V_4 = V_48 -> V_4 ;
F_29 ( V_57 , & V_4 -> V_50 ) ;
F_4 ( V_4 , 1 ) ;
}
void F_33 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_28 ( V_46 ) ;
struct V_3 * V_4 = V_48 -> V_4 ;
F_29 ( V_58 , & V_4 -> V_50 ) ;
F_4 ( V_4 , 1 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_5 * V_6 , int V_12 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_20 = V_12 ;
F_26 ( & V_2 -> V_59 ) ;
F_26 ( & V_2 -> V_60 ) ;
F_26 ( & V_2 -> V_61 ) ;
F_35 ( & V_2 -> V_24 ) ;
F_26 ( & V_2 -> V_28 ) ;
V_2 -> V_7 = V_6 ;
F_35 ( & V_2 -> V_62 ) ;
}
int F_36 ( struct V_5 * V_6 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_21 ; V_12 ++ ) {
struct V_1 * V_2 = V_6 -> V_23 [ V_12 ] ;
F_34 ( V_2 , V_6 , V_12 ) ;
F_37 ( & V_2 -> V_63 , V_2 ) ;
}
return 0 ;
}
void F_38 ( struct V_5 * V_6 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_21 ; V_12 ++ )
if ( V_6 -> V_64 [ V_12 ] -> V_2 )
F_4 ( V_6 -> V_64 [ V_12 ] , 0 ) ;
}
