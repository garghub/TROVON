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
V_4 -> V_2 = V_2 ;
V_2 -> V_21 ++ ;
V_2 -> V_29 |= ( 1U << V_4 -> V_20 ) ;
if ( ! V_2 -> V_4 )
V_2 -> V_4 = V_4 -> V_4 ;
if ( * ( V_25 * ) V_2 -> V_8 == 0 ) {
V_2 -> V_30 = V_4 -> V_30 ;
memcpy ( V_2 -> V_8 , V_4 -> V_8 ,
V_9 ) ;
V_2 -> V_31 = V_4 -> V_31 ;
V_2 -> V_32 = V_4 -> V_32 ;
V_2 -> V_33 = V_4 -> V_33 ;
V_2 -> V_34 = V_4 -> V_34 ;
} else
V_2 -> V_34 = F_12 ( V_2 -> V_34 , V_4 -> V_34 ) ;
F_8 ( & V_2 -> V_24 ) ;
F_10 ( & V_6 -> V_22 , V_18 ) ;
if ( ! V_2 -> V_2 ) {
V_2 -> V_2 = F_13 ( V_4 -> V_4 -> V_35 . V_36 , V_2 -> V_20 ) ;
F_14 ( ! V_2 -> V_2 ) ;
F_15 ( V_2 -> V_2 ) ;
}
F_16 ( V_2 -> V_2 , V_4 -> V_4 ) ;
F_5 ( L_4 ,
F_17 ( & V_4 -> V_4 -> V_35 ) , F_17 ( & V_2 -> V_2 -> V_35 ) ,
V_2 -> V_29 ,
F_18 ( V_2 -> V_8 ) ) ;
if ( V_2 -> V_37 )
V_2 -> V_37 -> V_38 = V_2 -> V_21 ;
if ( V_14 -> V_39 -> V_40 )
V_14 -> V_39 -> V_40 ( V_4 ) ;
F_19 ( V_4 -> V_2 , V_41 ) ;
}
void F_4 ( struct V_3 * V_4 , int V_42 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_13 * V_14 =
F_3 ( V_6 -> V_15 . V_16 -> V_17 ) ;
struct V_43 * V_35 ;
unsigned long V_18 ;
if ( ! V_2 )
return;
V_35 = V_2 -> V_37 ;
if ( V_35 )
V_35 -> V_38 -- ;
if ( V_2 -> V_21 == 1 ) {
if ( V_35 && V_42 )
V_35 -> V_42 = 1 ;
F_20 ( V_2 ) ;
F_21 ( V_2 -> V_2 ) ;
V_2 -> V_2 = NULL ;
} else
F_22 ( V_2 -> V_2 , V_4 -> V_4 ) ;
if ( V_14 -> V_39 -> V_44 )
V_14 -> V_39 -> V_44 ( V_4 ) ;
F_6 ( & V_6 -> V_22 , V_18 ) ;
F_7 ( & V_2 -> V_24 ) ;
F_23 ( & V_4 -> V_27 ) ;
V_4 -> V_2 = NULL ;
V_2 -> V_21 -- ;
V_2 -> V_29 &= ~ ( 1U << V_4 -> V_20 ) ;
if ( V_2 -> V_21 == 0 ) {
F_24 ( & V_2 -> V_28 ) ;
memset ( V_2 -> V_11 , 0 , V_9 ) ;
memset ( V_2 -> V_8 , 0 , V_9 ) ;
V_2 -> V_30 = 0 ;
V_2 -> V_31 = 0 ;
V_2 -> V_32 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_29 = 0 ;
}
F_8 ( & V_2 -> V_24 ) ;
F_10 ( & V_6 -> V_22 , V_18 ) ;
return;
}
void F_25 ( struct V_45 * V_46 )
{
struct V_47 * V_48 =
F_26 ( V_46 , struct V_47 , V_46 ) ;
struct V_3 * V_4 = V_48 -> V_4 ;
F_27 ( V_49 , & V_4 -> V_7 -> V_50 ,
& V_4 -> V_51 ) ;
F_2 ( V_4 ) ;
}
void F_28 ( struct V_45 * V_46 )
{
struct V_47 * V_48 =
F_26 ( V_46 , struct V_47 , V_46 ) ;
struct V_3 * V_4 = V_48 -> V_4 ;
unsigned long V_18 ;
T_1 V_52 ;
F_27 ( V_53 , & V_4 -> V_7 -> V_50 ,
& V_4 -> V_51 ) ;
F_6 ( & V_4 -> V_54 , V_18 ) ;
V_52 = V_4 -> V_55 ;
F_10 ( & V_4 -> V_54 , V_18 ) ;
F_5 ( L_5 , V_52 ) ;
F_19 ( V_4 -> V_2 , V_56 ) ;
}
void F_29 ( struct V_45 * V_46 )
{
struct V_47 * V_48 =
F_26 ( V_46 , struct V_47 , V_46 ) ;
struct V_3 * V_4 = V_48 -> V_4 ;
F_27 ( V_57 , & V_4 -> V_7 -> V_50 ,
& V_4 -> V_51 ) ;
F_4 ( V_4 , 1 ) ;
}
void F_30 ( struct V_45 * V_46 )
{
struct V_47 * V_48 =
F_26 ( V_46 , struct V_47 , V_46 ) ;
struct V_3 * V_4 = V_48 -> V_4 ;
F_27 ( V_58 , & V_4 -> V_7 -> V_50 ,
& V_4 -> V_51 ) ;
F_4 ( V_4 , 1 ) ;
}
void F_31 ( struct V_45 * V_46 )
{
struct V_47 * V_48 =
F_26 ( V_46 , struct V_47 , V_46 ) ;
struct V_3 * V_4 = V_48 -> V_4 ;
F_27 ( V_59 , & V_4 -> V_7 -> V_50 ,
& V_4 -> V_51 ) ;
F_4 ( V_4 , 1 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_5 * V_6 , int V_12 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_20 = V_12 ;
F_24 ( & V_2 -> V_60 ) ;
F_33 ( & V_2 -> V_24 ) ;
F_24 ( & V_2 -> V_28 ) ;
V_2 -> V_7 = V_6 ;
F_33 ( & V_2 -> V_61 ) ;
}
int F_34 ( struct V_5 * V_6 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_21 ; V_12 ++ ) {
struct V_1 * V_2 = V_6 -> V_23 [ V_12 ] ;
F_32 ( V_2 , V_6 , V_12 ) ;
F_35 ( & V_2 -> V_62 , V_2 ) ;
}
return 0 ;
}
void F_36 ( struct V_5 * V_6 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_21 ; V_12 ++ )
if ( V_6 -> V_63 [ V_12 ] -> V_2 )
F_4 ( V_6 -> V_63 [ V_12 ] , 0 ) ;
}
