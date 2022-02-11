static bool F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , int V_4 )
{
int V_5 = 0 ;
int V_6 = 0 ;
int V_7 , V_8 ;
V_8 = 1 << V_4 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_9 ; V_7 ++ ) {
if ( V_3 [ V_7 ] & V_8 ) {
V_5 ++ ;
V_6 |= V_3 [ V_7 ] & ~ V_8 ;
if ( V_5 > 1 && V_6 ) {
F_2 ( V_2 -> V_10 ,
L_1 ,
V_4 , V_7 , V_5 ,
V_6 ) ;
return true ;
}
}
}
return false ;
}
static bool F_3 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_11 ; V_4 ++ )
if ( F_1 ( V_2 , V_3 , V_4 ) )
return true ;
return false ;
}
static void F_4 ( struct V_1 * V_2 ,
T_1 * V_12 , int V_13 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_7 , V_4 ;
int V_16 ;
int V_17 ;
V_17 = V_13 ;
if ( V_2 -> V_18 && F_3 ( V_2 , V_12 ) ) {
F_2 ( V_2 -> V_10 , L_2 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_9 ; V_7 ++ ) {
for ( V_4 = 0 ; V_4 < V_2 -> V_11 ; V_4 ++ ) {
int V_19 = F_5 ( V_4 , V_7 , V_2 -> V_20 ) ;
const unsigned short * V_21 = V_15 -> V_22 ;
int V_23 ;
V_23 = V_21 [ V_19 ] ;
V_16 = V_12 [ V_7 ] & ( 1 << V_4 ) ;
if ( ! ! V_16 != F_6 ( V_23 , V_15 -> V_24 ) ) {
F_2 ( V_2 -> V_10 ,
L_3 ,
V_4 , V_7 , V_16 ) ;
F_7 ( V_15 , V_23 , V_16 ) ;
}
}
}
F_8 ( V_2 -> V_15 ) ;
}
static int F_9 ( struct V_14 * V_10 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
return F_11 ( & V_2 -> V_25 -> V_26 ,
& V_2 -> V_27 ) ;
}
static void F_12 ( struct V_14 * V_10 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
F_13 ( & V_2 -> V_25 -> V_26 ,
& V_2 -> V_27 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_12 )
{
return V_2 -> V_25 -> V_28 ( V_2 -> V_25 , V_29 ,
V_12 , V_2 -> V_9 ) ;
}
static int F_15 ( struct V_30 * V_31 ,
unsigned long V_32 , void * V_33 )
{
int V_34 ;
struct V_1 * V_2 = F_16 ( V_31 , struct V_1 ,
V_27 ) ;
T_1 V_12 [ V_2 -> V_9 ] ;
V_34 = F_14 ( V_2 , V_12 ) ;
if ( V_34 >= 0 )
F_4 ( V_2 , V_12 , V_34 ) ;
return V_35 ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_36 [ V_2 -> V_9 ] ;
T_1 V_16 [ V_2 -> V_9 ] ;
unsigned long V_37 ;
int V_38 , V_34 ;
V_37 = V_39 ;
V_34 = F_14 ( V_2 , V_16 ) ;
for ( V_38 = 1 ; ! V_34 && V_38 < 32 ; V_38 ++ ) {
memcpy ( V_36 , V_16 , sizeof( V_36 ) ) ;
V_34 = F_14 ( V_2 , V_16 ) ;
if ( 0 == memcmp ( V_36 , V_16 , sizeof( V_36 ) ) )
break;
}
V_37 = V_39 - V_37 ;
F_18 ( V_2 -> V_10 , L_4 , V_38 ,
F_19 ( V_37 ) ) ;
}
static int F_20 ( struct V_40 * V_41 )
{
struct V_42 * V_25 = F_21 ( V_41 -> V_10 . V_43 ) ;
struct V_44 * V_10 = V_25 -> V_10 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_45 * V_46 ;
int V_47 ;
V_46 = V_41 -> V_10 . V_48 ;
if ( ! V_46 )
return - V_49 ;
V_2 = F_22 ( & V_41 -> V_10 , sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 )
return - V_51 ;
V_47 = F_23 ( & V_41 -> V_10 , & V_2 -> V_11 ,
& V_2 -> V_9 ) ;
if ( V_47 )
return V_47 ;
V_15 = F_24 ( & V_41 -> V_10 ) ;
if ( ! V_15 )
return - V_51 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_27 . V_52 = F_15 ;
V_2 -> V_10 = V_10 ;
F_25 ( & V_41 -> V_10 , V_2 ) ;
V_15 -> V_53 = V_25 -> V_54 ;
V_15 -> V_55 = V_25 -> V_56 ;
F_26 ( V_57 , V_15 -> V_58 ) ;
V_15 -> V_59 . V_60 = V_61 ;
V_15 -> V_59 . V_62 = 1 ;
V_15 -> V_59 . V_63 = 0 ;
V_15 -> V_10 . V_43 = & V_41 -> V_10 ;
V_15 -> V_64 = F_9 ;
V_15 -> V_65 = F_12 ;
V_2 -> V_18 = F_27 ( V_46 ,
L_5 ) ;
V_47 = F_28 ( NULL , NULL , V_2 -> V_11 , V_2 -> V_9 ,
NULL , V_15 ) ;
if ( V_47 ) {
F_29 ( V_10 , L_6 ) ;
return V_47 ;
}
V_2 -> V_20 = F_30 ( V_2 -> V_9 ) ;
F_31 ( V_15 , V_66 , V_67 ) ;
F_32 ( V_15 , V_2 ) ;
V_2 -> V_15 = V_15 ;
V_47 = F_33 ( V_2 -> V_15 ) ;
if ( V_47 ) {
F_29 ( V_10 , L_7 ) ;
return V_47 ;
}
return 0 ;
}
static int F_34 ( struct V_44 * V_10 )
{
struct V_1 * V_2 = F_21 ( V_10 ) ;
if ( V_2 -> V_25 -> V_68 )
F_17 ( V_2 ) ;
return 0 ;
}
