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
int V_18 ;
V_18 = V_13 ;
if ( V_2 -> V_19 && F_3 ( V_2 , V_12 ) ) {
F_2 ( V_2 -> V_10 , L_2 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_9 ; V_7 ++ ) {
for ( V_4 = 0 ; V_4 < V_2 -> V_11 ; V_4 ++ ) {
int V_20 = F_5 ( V_4 , V_7 , V_2 -> V_21 ) ;
const unsigned short * V_22 = V_15 -> V_23 ;
V_16 = V_12 [ V_7 ] & ( 1 << V_4 ) ;
V_17 = V_2 -> V_24 [ V_7 ] & ( 1 << V_4 ) ;
if ( V_16 != V_17 ) {
F_2 ( V_2 -> V_10 ,
L_3 ,
V_4 , V_7 , V_16 ) ;
F_6 ( V_15 , V_22 [ V_20 ] ,
V_16 ) ;
}
}
V_2 -> V_24 [ V_7 ] = V_12 [ V_7 ] ;
}
F_7 ( V_2 -> V_15 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 * V_12 )
{
struct V_25 V_26 = {
. V_27 = 0 ,
. V_28 = V_29 ,
. V_30 = NULL ,
. V_31 = 0 ,
. V_32 = V_12 ,
. V_33 = V_2 -> V_9 ,
} ;
return V_2 -> V_34 -> V_35 ( V_2 -> V_34 , & V_26 ) ;
}
static T_2 F_9 ( int V_36 , void * V_37 )
{
struct V_1 * V_2 = V_37 ;
struct V_38 * V_34 = V_2 -> V_34 ;
int V_39 ;
T_1 V_12 [ V_2 -> V_9 ] ;
if ( F_10 ( V_34 -> V_10 ) )
F_11 ( V_34 -> V_10 , 0 ) ;
V_39 = F_8 ( V_2 , V_12 ) ;
if ( V_39 >= 0 )
F_4 ( V_2 , V_12 , V_39 ) ;
else
F_12 ( V_34 -> V_10 , L_4 , V_39 ) ;
return V_40 ;
}
static int F_13 ( struct V_14 * V_10 )
{
struct V_1 * V_2 = F_14 ( V_10 ) ;
struct V_38 * V_34 = V_2 -> V_34 ;
return F_15 ( V_34 -> V_36 , NULL , F_9 ,
V_41 | V_42 ,
L_5 , V_2 ) ;
}
static void F_16 ( struct V_14 * V_10 )
{
struct V_1 * V_2 = F_14 ( V_10 ) ;
struct V_38 * V_34 = V_2 -> V_34 ;
F_17 ( V_34 -> V_36 , V_2 ) ;
}
static int F_18 ( struct V_43 * V_44 )
{
struct V_38 * V_34 = F_19 ( V_44 -> V_10 . V_45 ) ;
struct V_46 * V_10 = V_34 -> V_10 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_47 * V_48 ;
int V_49 ;
V_48 = V_44 -> V_10 . V_50 ;
if ( ! V_48 )
return - V_51 ;
V_2 = F_20 ( & V_44 -> V_10 , sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
V_49 = F_21 ( & V_44 -> V_10 , & V_2 -> V_11 ,
& V_2 -> V_9 ) ;
if ( V_49 )
return V_49 ;
V_2 -> V_24 = F_20 ( & V_44 -> V_10 , V_2 -> V_9 , V_52 ) ;
if ( ! V_2 -> V_24 )
return - V_53 ;
V_15 = F_22 ( & V_44 -> V_10 ) ;
if ( ! V_15 )
return - V_53 ;
if ( ! V_34 -> V_36 ) {
F_12 ( V_10 , L_6 ) ;
return - V_54 ;
}
V_2 -> V_34 = V_34 ;
V_2 -> V_10 = V_10 ;
F_23 ( & V_44 -> V_10 , V_2 ) ;
V_15 -> V_55 = V_34 -> V_56 ;
V_15 -> V_57 = V_34 -> V_58 ;
F_24 ( V_59 , V_15 -> V_60 ) ;
V_15 -> V_61 . V_62 = V_63 ;
V_15 -> V_61 . V_27 = 1 ;
V_15 -> V_61 . V_64 = 0 ;
V_15 -> V_10 . V_45 = & V_44 -> V_10 ;
V_15 -> V_65 = F_13 ;
V_15 -> V_66 = F_16 ;
V_2 -> V_19 = F_25 ( V_48 ,
L_7 ) ;
V_49 = F_26 ( NULL , NULL , V_2 -> V_11 , V_2 -> V_9 ,
NULL , V_15 ) ;
if ( V_49 ) {
F_12 ( V_10 , L_8 ) ;
return V_49 ;
}
V_2 -> V_21 = F_27 ( V_2 -> V_9 ) ;
F_28 ( V_15 , V_67 , V_68 ) ;
F_29 ( V_15 , V_2 ) ;
V_2 -> V_15 = V_15 ;
V_49 = F_30 ( V_2 -> V_15 ) ;
if ( V_49 ) {
F_12 ( V_10 , L_9 ) ;
return V_49 ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_1 V_17 [ V_2 -> V_9 ] ;
T_1 V_16 [ V_2 -> V_9 ] ;
unsigned long V_69 ;
int V_70 , V_39 ;
V_69 = V_71 ;
V_39 = F_8 ( V_2 , V_16 ) ;
for ( V_70 = 1 ; ! V_39 && V_70 < 32 ; V_70 ++ ) {
memcpy ( V_17 , V_16 , sizeof( V_17 ) ) ;
V_39 = F_8 ( V_2 , V_16 ) ;
if ( 0 == memcmp ( V_17 , V_16 , sizeof( V_17 ) ) )
break;
}
V_69 = V_71 - V_69 ;
F_32 ( V_2 -> V_10 , L_10 , V_70 ,
F_33 ( V_69 ) ) ;
}
static int F_34 ( struct V_46 * V_10 )
{
struct V_1 * V_2 = F_19 ( V_10 ) ;
if ( V_2 -> V_34 -> V_72 )
F_31 ( V_2 ) ;
return 0 ;
}
