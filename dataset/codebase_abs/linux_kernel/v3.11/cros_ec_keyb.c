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
static int F_17 ( struct V_36 * V_37 )
{
struct V_38 * V_25 = F_18 ( V_37 -> V_10 . V_39 ) ;
struct V_40 * V_10 = V_25 -> V_10 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_41 * V_42 ;
int V_43 ;
V_42 = V_37 -> V_10 . V_44 ;
if ( ! V_42 )
return - V_45 ;
V_2 = F_19 ( & V_37 -> V_10 , sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
V_43 = F_20 ( & V_37 -> V_10 , & V_2 -> V_11 ,
& V_2 -> V_9 ) ;
if ( V_43 )
return V_43 ;
V_15 = F_21 ( & V_37 -> V_10 ) ;
if ( ! V_15 )
return - V_47 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_27 . V_48 = F_15 ;
V_2 -> V_10 = V_10 ;
F_22 ( & V_37 -> V_10 , V_2 ) ;
V_15 -> V_49 = V_25 -> V_50 ;
V_15 -> V_51 = V_25 -> V_52 ;
F_23 ( V_53 , V_15 -> V_54 ) ;
V_15 -> V_55 . V_56 = V_57 ;
V_15 -> V_55 . V_58 = 1 ;
V_15 -> V_55 . V_59 = 0 ;
V_15 -> V_10 . V_39 = & V_37 -> V_10 ;
V_15 -> V_60 = F_9 ;
V_15 -> V_61 = F_12 ;
V_2 -> V_18 = F_24 ( V_42 ,
L_4 ) ;
V_43 = F_25 ( NULL , NULL , V_2 -> V_11 , V_2 -> V_9 ,
NULL , V_15 ) ;
if ( V_43 ) {
F_26 ( V_10 , L_5 ) ;
return V_43 ;
}
V_2 -> V_20 = F_27 ( V_2 -> V_9 ) ;
F_28 ( V_15 , V_62 , V_63 ) ;
F_29 ( V_15 , V_2 ) ;
V_2 -> V_15 = V_15 ;
V_43 = F_30 ( V_2 -> V_15 ) ;
if ( V_43 ) {
F_26 ( V_10 , L_6 ) ;
return V_43 ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_1 V_64 [ V_2 -> V_9 ] ;
T_1 V_16 [ V_2 -> V_9 ] ;
unsigned long V_65 ;
int V_66 , V_34 ;
V_65 = V_67 ;
V_34 = F_14 ( V_2 , V_16 ) ;
for ( V_66 = 1 ; ! V_34 && V_66 < 32 ; V_66 ++ ) {
memcpy ( V_64 , V_16 , sizeof( V_64 ) ) ;
V_34 = F_14 ( V_2 , V_16 ) ;
if ( 0 == memcmp ( V_64 , V_16 , sizeof( V_64 ) ) )
break;
}
V_65 = V_67 - V_65 ;
F_32 ( V_2 -> V_10 , L_7 , V_66 ,
F_33 ( V_65 ) ) ;
}
static int F_34 ( struct V_40 * V_10 )
{
struct V_1 * V_2 = F_18 ( V_10 ) ;
if ( V_2 -> V_25 -> V_68 )
F_31 ( V_2 ) ;
return 0 ;
}
