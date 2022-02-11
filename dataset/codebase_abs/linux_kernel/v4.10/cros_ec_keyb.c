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
static int F_8 ( struct V_14 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
return F_10 ( & V_2 -> V_28 -> V_29 ,
& V_2 -> V_30 ) ;
}
static void F_11 ( struct V_14 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
F_12 ( & V_2 -> V_28 -> V_29 ,
& V_2 -> V_30 ) ;
}
static int F_13 ( struct V_31 * V_32 ,
unsigned long V_33 , void * V_34 )
{
struct V_1 * V_2 = F_14 ( V_32 , struct V_1 ,
V_30 ) ;
if ( V_2 -> V_28 -> V_35 . V_36 != V_37 )
return V_38 ;
if ( V_33 )
return V_39 ;
if ( V_2 -> V_28 -> V_40 != V_2 -> V_11 ) {
F_15 ( V_2 -> V_9 ,
L_4 ) ;
return V_39 ;
}
F_4 ( V_2 , V_2 -> V_28 -> V_35 . V_41 . V_42 ,
V_2 -> V_28 -> V_40 ) ;
return V_39 ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_17 , V_16 ;
int V_24 = V_2 -> V_24 ;
unsigned short * V_43 = V_2 -> V_15 -> V_26 ;
unsigned short V_44 ;
F_17 ( V_2 -> V_15 -> V_45 != sizeof( * V_43 ) ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_11 ; V_16 ++ ) {
for ( V_17 = 0 ; V_17 < V_2 -> V_22 ; V_17 ++ ) {
V_44 = V_43 [ F_5 ( V_17 , V_16 , V_24 ) ] ;
if ( V_44 && ( V_44 != V_46 ) )
V_2 -> V_10 [ V_16 ] |= 1 << V_17 ;
}
F_3 ( V_2 -> V_9 , L_5 ,
V_16 , V_2 -> V_10 [ V_16 ] ) ;
}
}
static int F_18 ( struct V_47 * V_48 )
{
struct V_49 * V_28 = F_19 ( V_48 -> V_9 . V_50 ) ;
struct V_8 * V_9 = & V_48 -> V_9 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_51 * V_52 ;
int V_53 ;
V_52 = V_48 -> V_9 . V_54 ;
if ( ! V_52 )
return - V_55 ;
V_2 = F_20 ( V_9 , sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 )
return - V_57 ;
V_53 = F_21 ( V_9 , & V_2 -> V_22 , & V_2 -> V_11 ) ;
if ( V_53 )
return V_53 ;
V_2 -> V_10 = F_20 ( V_9 , V_2 -> V_11 , V_56 ) ;
if ( ! V_2 -> V_10 )
return - V_57 ;
V_2 -> V_27 = F_20 ( V_9 , V_2 -> V_11 , V_56 ) ;
if ( ! V_2 -> V_27 )
return - V_57 ;
V_15 = F_22 ( V_9 ) ;
if ( ! V_15 )
return - V_57 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_30 . V_58 = F_13 ;
V_2 -> V_9 = V_9 ;
F_23 ( V_9 , V_2 ) ;
V_15 -> V_59 = V_60 ;
V_15 -> V_61 = V_28 -> V_62 ;
F_24 ( V_63 , V_15 -> V_64 ) ;
V_15 -> V_65 . V_66 = V_67 ;
V_15 -> V_65 . V_68 = 1 ;
V_15 -> V_65 . V_69 = 0 ;
V_15 -> V_9 . V_50 = V_9 ;
V_15 -> V_70 = F_8 ;
V_15 -> V_71 = F_11 ;
V_2 -> V_21 = F_25 ( V_52 ,
L_6 ) ;
V_53 = F_26 ( NULL , NULL , V_2 -> V_22 , V_2 -> V_11 ,
NULL , V_15 ) ;
if ( V_53 ) {
F_15 ( V_9 , L_7 ) ;
return V_53 ;
}
V_2 -> V_24 = F_27 ( V_2 -> V_11 ) ;
F_28 ( V_15 , V_72 , V_73 ) ;
F_29 ( V_15 , V_2 ) ;
V_2 -> V_15 = V_15 ;
F_16 ( V_2 ) ;
V_53 = F_30 ( V_2 -> V_15 ) ;
if ( V_53 ) {
F_15 ( V_9 , L_8 ) ;
return V_53 ;
}
return 0 ;
}
