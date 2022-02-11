static int F_1 ( struct V_1 * V_2 )
{
static const int V_3 [] = {
[ V_4 ] = V_5 ,
[ V_6 ] = V_5 ,
[ V_7 ] = V_8 ,
[ V_9 ] = V_5 ,
[ V_10 ] = V_5 ,
[ V_11 ] = V_8 ,
[ V_12 ] = V_8 ,
[ V_13 ] = V_5 ,
[ V_14 ] = V_5 ,
[ V_15 ] = V_16 ,
[ V_17 ] = V_18 ,
[ V_19 ] = V_20 ,
[ V_21 ] = V_5 ,
[ V_22 ] = V_5 ,
[ V_23 ] = V_16 ,
[ V_24 ] = V_18 ,
[ V_25 ] = V_20 ,
} ;
return V_3 [ V_2 -> V_26 ] ;
}
static int F_2 ( struct V_1 * V_2 )
{
static const int V_27 [] = {
[ V_13 ] = V_5 ,
[ V_22 ] = V_5 ,
[ V_23 ] = V_16 ,
[ V_24 ] = V_18 ,
[ V_25 ] = V_20 ,
} ;
return V_27 [ V_2 -> V_26 ] ;
}
int F_3 ( struct V_1 * V_2 )
{
static const int V_28 [] = {
[ V_4 ] = 0 ,
[ V_6 ] = 0 ,
[ V_7 ] = 1 ,
[ V_9 ] = 1 ,
[ V_10 ] = 0 ,
[ V_11 ] = 1 ,
[ V_12 ] = 1 ,
[ V_13 ] = 1 ,
[ V_14 ] = 1 ,
[ V_15 ] = 0 ,
[ V_17 ] = 0 ,
[ V_19 ] = 0 ,
[ V_21 ] = 1 ,
[ V_22 ] = 1 ,
[ V_23 ] = 1 ,
[ V_24 ] = 1 ,
[ V_25 ] = 1 ,
} ;
return V_28 [ V_2 -> V_26 ] ;
}
int F_4 ( struct V_1 * V_2 )
{
static const int V_29 [] = {
[ V_13 ] = 0 ,
[ V_22 ] = 1 ,
[ V_23 ] = 0 ,
[ V_24 ] = 0 ,
[ V_25 ] = 0 ,
} ;
return V_29 [ V_2 -> V_26 ] ;
}
static struct V_30 * F_5 ( void )
{
struct V_30 * V_31 ;
V_31 = F_6 ( sizeof( struct V_30 ) +
V_32 * sizeof( struct V_33 ) ,
V_34 ) ;
if ( V_31 ) {
V_31 -> V_35 . V_36 = V_37 ;
}
return V_31 ;
}
static void F_7 ( struct V_30 * V_31 ,
struct V_38 * V_39 )
{
int V_40 , V_41 , V_42 = 0 , V_43 = 0 ;
struct V_33 * V_44 ;
T_1 V_45 ;
F_8 ( V_46 , V_47 ) ;
F_8 ( V_48 , V_49 ) ;
V_44 = V_31 -> V_50 ;
F_9 ( V_46 , V_39 -> V_51 , V_47 ) ;
for ( V_40 = 0 ; V_40 < V_32 ; V_40 ++ ) {
F_9 ( V_48 , V_46 , V_49 ) ;
if ( F_10 ( V_48 , V_49 ) > 0 ) {
bool V_52 = false ;
V_45 = ( T_1 ) * V_48 ;
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ ) {
if ( V_45 == V_44 [ V_41 ] . V_53 ) {
V_44 [ V_41 ] . V_54 |= 1 << V_40 ;
V_52 = true ;
break;
}
}
if ( ! V_52 ) {
V_42 ++ ;
V_44 [ V_43 ] . V_54 = 1 << V_40 ;
V_44 [ V_43 ] . V_53 = V_45 ;
V_43 ++ ;
}
}
F_11 ( V_46 , V_46 , V_49 , V_47 ) ;
}
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
V_31 -> V_50 [ V_41 ] . V_54 = F_12 ( V_44 [ V_41 ] . V_54 ) ;
V_31 -> V_50 [ V_41 ] . V_53 = F_12 ( V_44 [ V_41 ] . V_53 ) ;
}
V_31 -> V_35 . V_55 = sizeof( struct V_30 ) - sizeof( struct V_56 )
+ V_42 * sizeof( struct V_33 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
struct V_57 * V_58 ;
int V_59 ;
if ( V_2 -> V_26 == V_60 ) {
F_14 ( V_2 -> V_31 ) ;
V_2 -> V_31 = NULL ;
return 0 ;
}
V_59 = V_2 -> V_39 . V_59 ? 1 : 0 ;
if ( V_2 -> V_31 == NULL ) {
V_2 -> V_31 = F_5 () ;
if ( V_2 -> V_31 == NULL )
return - V_61 ;
}
V_31 = V_2 -> V_31 ;
F_15 ( V_31 , V_59 ) ;
F_16 ( V_31 , V_2 -> V_62 ) ;
F_17 ( V_31 , F_18 ( V_2 ) ) ;
F_19 ( V_31 , F_3 ( V_2 ) ) ;
F_20 ( V_31 , F_1 ( V_2 ) ) ;
F_21 ( V_31 , V_2 -> V_63 ) ;
F_22 ( V_31 , V_2 -> type ) ;
if ( F_18 ( V_2 ) ) {
switch ( V_2 -> V_64 . type ) {
case V_65 :
V_31 -> V_66 = V_2 -> V_64 . V_67 -> V_66 ;
break;
case V_68 :
V_31 -> V_66 = V_2 -> V_64 . V_69 ;
break;
}
} else
V_31 -> V_66 = V_2 -> V_70 -> V_66 ;
F_7 ( V_31 , & V_2 -> V_39 ) ;
if ( F_23 ( V_2 ) ) {
V_58 = & V_2 -> V_58 ;
if ( V_58 -> V_71 == NULL ) {
V_58 -> V_71 = F_5 () ;
if ( V_58 -> V_71 == NULL )
return - V_61 ;
}
V_31 = V_58 -> V_71 ;
memcpy ( V_31 , V_2 -> V_31 , sizeof( struct V_30 ) ) ;
F_15 ( V_31 , 1 ) ;
F_19 ( V_31 , F_4 ( V_2 ) ) ;
F_20 ( V_31 , F_2 ( V_2 ) ) ;
F_7 ( V_31 , & V_58 -> V_72 ) ;
}
V_2 -> V_73 = true ;
return 0 ;
}
static
void F_24 ( struct V_38 * V_51 , T_2 V_74 , T_3 V_53 )
{
int V_39 ;
T_3 V_75 ;
for ( V_39 = 0 ; V_39 < V_49 ; V_39 ++ ) {
V_75 = 1 << V_39 ;
if ( V_53 & V_75 )
F_25 ( V_74 * V_32 + V_39 , V_51 -> V_51 ) ;
}
}
void F_26 ( struct V_38 * V_51 , const struct V_30 * V_31 )
{
int V_76 = ( V_31 -> V_35 . V_55 - 4 ) / 4 ;
const struct V_33 * V_77 ;
int V_78 ;
T_3 V_54 , V_53 ;
T_2 V_74 ;
T_3 V_79 ;
F_27 ( V_51 -> V_51 , V_47 ) ;
for ( V_78 = 0 ; V_78 < V_76 ; V_78 ++ ) {
V_77 = & V_31 -> V_50 [ V_78 ] ;
V_54 = F_28 ( V_77 -> V_54 ) ;
V_53 = F_28 ( V_77 -> V_53 ) ;
for ( V_74 = 0 ; V_74 < V_32 ; V_74 ++ ) {
V_79 = 1 << V_74 ;
if ( V_54 & V_79 )
F_24 ( V_51 , V_74 , V_53 ) ;
}
}
}
