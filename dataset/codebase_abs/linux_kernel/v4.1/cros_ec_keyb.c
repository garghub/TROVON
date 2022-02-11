static bool F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 , V_5 , V_6 , V_7 ;
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 * V_10 = V_2 -> V_10 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_11 ; V_4 ++ ) {
V_6 = V_3 [ V_4 ] & V_10 [ V_4 ] ;
for ( V_5 = V_4 + 1 ; V_5 < V_2 -> V_11 ; V_5 ++ ) {
V_7 = V_3 [ V_5 ] & V_10 [ V_5 ] ;
if ( F_2 ( V_6 & V_7 ) > 1 ) {
F_3 ( V_9 , L_1 ,
V_4 , V_6 , V_5 , V_7 ) ;
return true ;
}
}
}
return false ;
}
static void F_4 ( struct V_1 * V_2 ,
T_1 * V_12 , int V_13 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_16 , V_17 ;
int V_18 ;
int V_19 ;
int V_20 ;
V_20 = V_13 ;
if ( V_2 -> V_21 && F_1 ( V_2 , V_12 ) ) {
F_3 ( V_2 -> V_9 , L_2 ) ;
return;
}
for ( V_16 = 0 ; V_16 < V_2 -> V_11 ; V_16 ++ ) {
for ( V_17 = 0 ; V_17 < V_2 -> V_22 ; V_17 ++ ) {
int V_23 = F_5 ( V_17 , V_16 , V_2 -> V_24 ) ;
const unsigned short * V_25 = V_15 -> V_26 ;
V_18 = V_12 [ V_16 ] & ( 1 << V_17 ) ;
V_19 = V_2 -> V_27 [ V_16 ] & ( 1 << V_17 ) ;
if ( V_18 != V_19 ) {
F_3 ( V_2 -> V_9 ,
L_3 ,
V_17 , V_16 , V_18 ) ;
F_6 ( V_15 , V_25 [ V_23 ] ,
V_18 ) ;
}
}
V_2 -> V_27 [ V_16 ] = V_12 [ V_16 ] ;
}
F_7 ( V_2 -> V_15 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 * V_12 )
{
int V_28 ;
struct V_29 V_30 = {
. V_31 = V_32 ,
. V_33 = V_2 -> V_11 ,
} ;
V_28 = F_9 ( V_2 -> V_34 , & V_30 ) ;
if ( V_28 < 0 )
return V_28 ;
memcpy ( V_12 , V_30 . V_35 , V_2 -> V_11 ) ;
return 0 ;
}
static T_2 F_10 ( int V_36 , void * V_37 )
{
struct V_1 * V_2 = V_37 ;
struct V_38 * V_34 = V_2 -> V_34 ;
int V_28 ;
T_1 V_12 [ V_2 -> V_11 ] ;
if ( F_11 ( V_34 -> V_9 ) )
F_12 ( V_34 -> V_9 , 0 ) ;
V_28 = F_8 ( V_2 , V_12 ) ;
if ( V_28 >= 0 )
F_4 ( V_2 , V_12 , V_28 ) ;
else
F_13 ( V_34 -> V_9 , L_4 , V_28 ) ;
return V_39 ;
}
static int F_14 ( struct V_14 * V_9 )
{
struct V_1 * V_2 = F_15 ( V_9 ) ;
struct V_38 * V_34 = V_2 -> V_34 ;
return F_16 ( V_34 -> V_36 , NULL , F_10 ,
V_40 | V_41 ,
L_5 , V_2 ) ;
}
static void F_17 ( struct V_14 * V_9 )
{
struct V_1 * V_2 = F_15 ( V_9 ) ;
struct V_38 * V_34 = V_2 -> V_34 ;
F_18 ( V_34 -> V_36 , V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_17 , V_16 ;
int V_24 = V_2 -> V_24 ;
unsigned short * V_42 = V_2 -> V_15 -> V_26 ;
unsigned short V_43 ;
F_20 ( V_2 -> V_15 -> V_44 != sizeof( * V_42 ) ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_11 ; V_16 ++ ) {
for ( V_17 = 0 ; V_17 < V_2 -> V_22 ; V_17 ++ ) {
V_43 = V_42 [ F_5 ( V_17 , V_16 , V_24 ) ] ;
if ( V_43 && ( V_43 != V_45 ) )
V_2 -> V_10 [ V_16 ] |= 1 << V_17 ;
}
F_3 ( V_2 -> V_9 , L_6 ,
V_16 , V_2 -> V_10 [ V_16 ] ) ;
}
}
static int F_21 ( struct V_46 * V_47 )
{
struct V_38 * V_34 = F_22 ( V_47 -> V_9 . V_48 ) ;
struct V_8 * V_9 = V_34 -> V_9 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_49 * V_50 ;
int V_51 ;
V_50 = V_47 -> V_9 . V_52 ;
if ( ! V_50 )
return - V_53 ;
V_2 = F_23 ( & V_47 -> V_9 , sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_55 ;
V_51 = F_24 ( & V_47 -> V_9 , & V_2 -> V_22 ,
& V_2 -> V_11 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_10 = F_23 ( & V_47 -> V_9 , V_2 -> V_11 , V_54 ) ;
if ( ! V_2 -> V_10 )
return - V_55 ;
V_2 -> V_27 = F_23 ( & V_47 -> V_9 , V_2 -> V_11 , V_54 ) ;
if ( ! V_2 -> V_27 )
return - V_55 ;
V_15 = F_25 ( & V_47 -> V_9 ) ;
if ( ! V_15 )
return - V_55 ;
if ( ! V_34 -> V_36 ) {
F_13 ( V_9 , L_7 ) ;
return - V_56 ;
}
V_2 -> V_34 = V_34 ;
V_2 -> V_9 = V_9 ;
F_26 ( & V_47 -> V_9 , V_2 ) ;
V_15 -> V_57 = V_34 -> V_58 ;
V_15 -> V_59 = V_34 -> V_60 ;
F_27 ( V_61 , V_15 -> V_62 ) ;
V_15 -> V_63 . V_64 = V_65 ;
V_15 -> V_63 . V_66 = 1 ;
V_15 -> V_63 . V_67 = 0 ;
V_15 -> V_9 . V_48 = & V_47 -> V_9 ;
V_15 -> V_68 = F_14 ;
V_15 -> V_69 = F_17 ;
V_2 -> V_21 = F_28 ( V_50 ,
L_8 ) ;
V_51 = F_29 ( NULL , NULL , V_2 -> V_22 , V_2 -> V_11 ,
NULL , V_15 ) ;
if ( V_51 ) {
F_13 ( V_9 , L_9 ) ;
return V_51 ;
}
V_2 -> V_24 = F_30 ( V_2 -> V_11 ) ;
F_31 ( V_15 , V_70 , V_71 ) ;
F_32 ( V_15 , V_2 ) ;
V_2 -> V_15 = V_15 ;
F_19 ( V_2 ) ;
V_51 = F_33 ( V_2 -> V_15 ) ;
if ( V_51 ) {
F_13 ( V_9 , L_10 ) ;
return V_51 ;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_19 [ V_2 -> V_11 ] ;
T_1 V_18 [ V_2 -> V_11 ] ;
unsigned long V_72 ;
int V_73 , V_28 ;
V_72 = V_74 ;
V_28 = F_8 ( V_2 , V_18 ) ;
for ( V_73 = 1 ; ! V_28 && V_73 < 32 ; V_73 ++ ) {
memcpy ( V_19 , V_18 , sizeof( V_19 ) ) ;
V_28 = F_8 ( V_2 , V_18 ) ;
if ( 0 == memcmp ( V_19 , V_18 , sizeof( V_19 ) ) )
break;
}
V_72 = V_74 - V_72 ;
F_35 ( V_2 -> V_9 , L_11 , V_73 ,
F_36 ( V_72 ) ) ;
}
static int F_37 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_22 ( V_9 ) ;
if ( ! V_2 -> V_34 -> V_75 )
F_34 ( V_2 ) ;
return 0 ;
}
