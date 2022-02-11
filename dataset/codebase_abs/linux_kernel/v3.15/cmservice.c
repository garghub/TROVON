bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
F_3 ( L_1 , V_3 ) ;
switch ( V_3 ) {
case V_5 :
V_2 -> type = & V_6 ;
return true ;
case V_7 :
V_2 -> type = & V_8 ;
return true ;
case V_9 :
V_2 -> type = & V_10 ;
return true ;
case V_11 :
V_2 -> type = & V_12 ;
return true ;
case V_13 :
V_2 -> type = & V_14 ;
return true ;
default:
return false ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
F_3 ( L_2 ) ;
if ( V_2 -> V_15 == 6 ) {
ASSERT ( V_2 -> V_16 && V_2 -> V_17 && V_2 -> V_18 ) ;
F_5 ( V_2 -> V_16 , V_2 -> V_17 , V_2 -> V_18 ) ;
}
F_6 ( V_2 -> V_16 ) ;
V_2 -> V_16 = NULL ;
F_7 ( V_2 -> V_19 ) ;
V_2 -> V_19 = NULL ;
}
static void F_8 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_9 ( V_21 , struct V_1 , V_21 ) ;
F_3 ( L_2 ) ;
F_10 ( V_2 ) ;
F_5 ( V_2 -> V_16 , V_2 -> V_17 , V_2 -> V_18 ) ;
F_11 ( L_2 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_22 * V_23 ,
bool V_24 )
{
struct V_25 * V_26 ;
struct V_27 * V_16 ;
struct V_28 V_29 ;
T_2 * V_30 ;
T_1 V_31 ;
int V_32 , V_33 ;
F_3 ( L_3 , V_2 -> V_15 , V_23 -> V_34 , V_24 ) ;
switch ( V_2 -> V_15 ) {
case 0 :
V_2 -> V_35 = 0 ;
V_2 -> V_15 ++ ;
case 1 :
F_13 ( L_4 ) ;
V_32 = F_14 ( V_2 , V_23 , V_24 , & V_2 -> V_31 , 4 ) ;
switch ( V_32 ) {
case 0 : break;
case - V_36 : return 0 ;
default: return V_32 ;
}
V_2 -> V_17 = F_2 ( V_2 -> V_31 ) ;
F_13 ( L_5 , V_2 -> V_17 ) ;
if ( V_2 -> V_17 > V_37 )
return - V_38 ;
V_2 -> V_19 = F_15 ( V_2 -> V_17 * 3 * 4 , V_39 ) ;
if ( ! V_2 -> V_19 )
return - V_40 ;
V_2 -> V_35 = 0 ;
V_2 -> V_15 ++ ;
case 2 :
F_13 ( L_6 ) ;
V_32 = F_14 ( V_2 , V_23 , V_24 , V_2 -> V_19 ,
V_2 -> V_17 * 3 * 4 ) ;
switch ( V_32 ) {
case 0 : break;
case - V_36 : return 0 ;
default: return V_32 ;
}
F_13 ( L_7 ) ;
V_2 -> V_18 = F_16 ( V_2 -> V_17 ,
sizeof( struct V_25 ) ,
V_39 ) ;
if ( ! V_2 -> V_18 )
return - V_40 ;
V_26 = V_2 -> V_18 ;
V_30 = V_2 -> V_19 ;
for ( V_33 = V_2 -> V_17 ; V_33 > 0 ; V_33 -- , V_26 ++ ) {
V_26 -> V_41 . V_42 = F_2 ( * V_30 ++ ) ;
V_26 -> V_41 . V_43 = F_2 ( * V_30 ++ ) ;
V_26 -> V_41 . V_44 = F_2 ( * V_30 ++ ) ;
V_26 -> type = V_45 ;
}
V_2 -> V_35 = 0 ;
V_2 -> V_15 ++ ;
case 3 :
F_13 ( L_8 ) ;
V_32 = F_14 ( V_2 , V_23 , V_24 , & V_2 -> V_31 , 4 ) ;
switch ( V_32 ) {
case 0 : break;
case - V_36 : return 0 ;
default: return V_32 ;
}
V_31 = F_2 ( V_2 -> V_31 ) ;
F_13 ( L_9 , V_31 ) ;
if ( V_31 != V_2 -> V_17 && V_31 != 0 )
return - V_38 ;
V_2 -> V_35 = 0 ;
V_2 -> V_15 ++ ;
if ( V_31 == 0 )
goto V_46;
case 4 :
F_13 ( L_10 ) ;
V_32 = F_14 ( V_2 , V_23 , V_24 , V_2 -> V_18 ,
V_2 -> V_17 * 3 * 4 ) ;
switch ( V_32 ) {
case 0 : break;
case - V_36 : return 0 ;
default: return V_32 ;
}
F_13 ( L_11 ) ;
V_26 = V_2 -> V_18 ;
V_30 = V_2 -> V_19 ;
for ( V_33 = V_2 -> V_17 ; V_33 > 0 ; V_33 -- , V_26 ++ ) {
V_26 -> V_47 = F_2 ( * V_30 ++ ) ;
V_26 -> V_48 = F_2 ( * V_30 ++ ) ;
V_26 -> type = F_2 ( * V_30 ++ ) ;
}
V_46:
V_2 -> V_35 = 0 ;
V_2 -> V_15 ++ ;
case 5 :
F_13 ( L_12 ) ;
if ( V_23 -> V_34 != 0 )
return - V_38 ;
V_2 -> V_15 ++ ;
case 6 :
break;
}
if ( ! V_24 )
return 0 ;
V_2 -> V_49 = V_50 ;
memcpy ( & V_29 , & F_17 ( V_23 ) -> V_51 , 4 ) ;
V_16 = F_18 ( & V_29 ) ;
if ( ! V_16 )
return - V_52 ;
V_2 -> V_16 = V_16 ;
F_19 ( & V_2 -> V_21 , F_8 ) ;
F_20 ( V_53 , & V_2 -> V_21 ) ;
return 0 ;
}
static void F_21 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_9 ( V_21 , struct V_1 , V_21 ) ;
F_3 ( L_13 , V_2 -> V_16 ) ;
F_22 ( V_2 -> V_16 ) ;
F_10 ( V_2 ) ;
F_11 ( L_2 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
bool V_24 )
{
struct V_27 * V_16 ;
struct V_28 V_29 ;
F_3 ( L_14 , V_23 -> V_34 , V_24 ) ;
if ( V_23 -> V_34 > 0 )
return - V_38 ;
if ( ! V_24 )
return 0 ;
V_2 -> V_49 = V_50 ;
memcpy ( & V_29 , & F_17 ( V_23 ) -> V_51 , 4 ) ;
V_16 = F_18 ( & V_29 ) ;
if ( ! V_16 )
return - V_52 ;
V_2 -> V_16 = V_16 ;
F_19 ( & V_2 -> V_21 , F_21 ) ;
F_20 ( V_53 , & V_2 -> V_21 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
bool V_24 )
{
struct V_27 * V_16 ;
struct V_28 V_29 ;
F_3 ( L_14 , V_23 -> V_34 , V_24 ) ;
if ( ! V_24 )
return 0 ;
V_2 -> V_49 = V_50 ;
memcpy ( & V_29 , & F_17 ( V_23 ) -> V_51 , 4 ) ;
V_16 = F_18 ( & V_29 ) ;
if ( ! V_16 )
return - V_52 ;
V_2 -> V_16 = V_16 ;
F_19 ( & V_2 -> V_21 , F_21 ) ;
F_20 ( V_53 , & V_2 -> V_21 ) ;
return 0 ;
}
static void F_25 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_9 ( V_21 , struct V_1 , V_21 ) ;
F_3 ( L_2 ) ;
F_10 ( V_2 ) ;
F_11 ( L_2 ) ;
}
static int F_26 ( struct V_1 * V_2 , struct V_22 * V_23 ,
bool V_24 )
{
F_3 ( L_14 , V_23 -> V_34 , V_24 ) ;
if ( V_23 -> V_34 > 0 )
return - V_38 ;
if ( ! V_24 )
return 0 ;
V_2 -> V_49 = V_50 ;
F_19 ( & V_2 -> V_21 , F_25 ) ;
F_20 ( V_53 , & V_2 -> V_21 ) ;
return 0 ;
}
static void F_27 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_9 ( V_21 , struct V_1 , V_21 ) ;
struct V_54 * V_55 = V_2 -> V_18 ;
struct {
T_2 V_56 ;
} V_57 ;
F_3 ( L_2 ) ;
if ( memcmp ( V_55 , & V_54 , sizeof( V_54 ) ) == 0 )
V_57 . V_56 = F_28 ( 0 ) ;
else
V_57 . V_56 = F_28 ( 1 ) ;
F_29 ( V_2 , & V_57 , sizeof( V_57 ) ) ;
F_11 ( L_2 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_22 * V_23 ,
bool V_24 )
{
struct V_54 * V_55 ;
unsigned V_33 ;
T_2 * V_58 ;
int V_32 ;
F_3 ( L_3 , V_2 -> V_15 , V_23 -> V_34 , V_24 ) ;
if ( V_23 -> V_34 > 0 )
return - V_38 ;
if ( ! V_24 )
return 0 ;
switch ( V_2 -> V_15 ) {
case 0 :
V_2 -> V_35 = 0 ;
V_2 -> V_19 = F_15 ( 11 * sizeof( T_2 ) , V_39 ) ;
if ( ! V_2 -> V_19 )
return - V_40 ;
V_2 -> V_15 ++ ;
case 1 :
F_13 ( L_15 ) ;
V_32 = F_14 ( V_2 , V_23 , V_24 , V_2 -> V_19 ,
11 * sizeof( T_2 ) ) ;
switch ( V_32 ) {
case 0 : break;
case - V_36 : return 0 ;
default: return V_32 ;
}
F_13 ( L_16 ) ;
V_2 -> V_18 = F_15 ( sizeof( struct V_54 ) , V_39 ) ;
if ( ! V_2 -> V_18 )
return - V_40 ;
V_58 = V_2 -> V_19 ;
V_55 = V_2 -> V_18 ;
V_55 -> V_59 = F_2 ( V_58 [ 0 ] ) ;
V_55 -> V_60 = F_2 ( V_58 [ 1 ] ) ;
V_55 -> V_61 = F_2 ( V_58 [ 2 ] ) ;
V_55 -> V_62 = F_2 ( V_58 [ 3 ] ) ;
V_55 -> V_63 = F_2 ( V_58 [ 4 ] ) ;
for ( V_33 = 0 ; V_33 < 6 ; V_33 ++ )
V_55 -> V_64 [ V_33 ] = F_2 ( V_58 [ V_33 + 5 ] ) ;
V_2 -> V_35 = 0 ;
V_2 -> V_15 ++ ;
case 2 :
F_13 ( L_12 ) ;
if ( V_23 -> V_34 != 0 )
return - V_38 ;
break;
}
if ( ! V_24 )
return 0 ;
V_2 -> V_49 = V_50 ;
F_19 ( & V_2 -> V_21 , F_27 ) ;
F_20 ( V_53 , & V_2 -> V_21 ) ;
return 0 ;
}
static void F_31 ( struct V_20 * V_21 )
{
struct V_65 * V_66 ;
struct V_1 * V_2 = F_9 ( V_21 , struct V_1 , V_21 ) ;
int V_33 , V_67 ;
struct {
struct {
T_2 V_67 ;
T_2 V_68 [ 11 ] ;
T_2 V_69 [ 32 ] ;
T_2 V_70 [ 32 ] ;
T_2 V_71 [ 32 ] ;
} V_72 ;
struct {
T_2 V_73 ;
T_2 V_74 [ 1 ] ;
} V_75 ;
} V_57 ;
F_3 ( L_2 ) ;
V_67 = 0 ;
V_66 = F_16 ( 32 , sizeof( * V_66 ) , V_39 ) ;
if ( V_66 ) {
V_67 = F_32 ( V_66 , 32 , false ) ;
if ( V_67 < 0 ) {
F_7 ( V_66 ) ;
V_66 = NULL ;
V_67 = 0 ;
}
}
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_72 . V_67 = F_28 ( V_67 ) ;
V_57 . V_72 . V_68 [ 0 ] = F_28 ( V_54 . V_59 ) ;
V_57 . V_72 . V_68 [ 1 ] = F_28 ( V_54 . V_60 ) ;
V_57 . V_72 . V_68 [ 2 ] = F_28 ( V_54 . V_61 ) ;
V_57 . V_72 . V_68 [ 3 ] = F_28 ( ( V_76 ) V_54 . V_62 ) ;
V_57 . V_72 . V_68 [ 4 ] = F_28 ( ( V_76 ) V_54 . V_63 ) ;
for ( V_33 = 0 ; V_33 < 6 ; V_33 ++ )
V_57 . V_72 . V_68 [ V_33 + 5 ] = F_28 ( ( V_76 ) V_54 . V_64 [ V_33 ] ) ;
if ( V_66 ) {
for ( V_33 = 0 ; V_33 < V_67 ; V_33 ++ ) {
V_57 . V_72 . V_69 [ V_33 ] = V_66 [ V_33 ] . V_77 . V_78 ;
V_57 . V_72 . V_70 [ V_33 ] = V_66 [ V_33 ] . V_70 . V_78 ;
V_57 . V_72 . V_71 [ V_33 ] = F_28 ( V_66 [ V_33 ] . V_71 ) ;
}
F_7 ( V_66 ) ;
}
V_57 . V_75 . V_73 = F_28 ( 1 ) ;
V_57 . V_75 . V_74 [ 0 ] = F_28 ( V_79 ) ;
F_29 ( V_2 , & V_57 , sizeof( V_57 ) ) ;
F_11 ( L_2 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_22 * V_23 , bool V_24 )
{
F_3 ( L_14 , V_23 -> V_34 , V_24 ) ;
if ( V_23 -> V_34 > 0 )
return - V_38 ;
if ( ! V_24 )
return 0 ;
V_2 -> V_49 = V_50 ;
F_19 ( & V_2 -> V_21 , F_31 ) ;
F_20 ( V_53 , & V_2 -> V_21 ) ;
return 0 ;
}
