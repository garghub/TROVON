int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_6 * V_7 ;
unsigned V_8 , V_9 ;
bool V_10 ;
if ( V_2 -> V_11 == - 1 ) {
return 0 ;
}
V_7 = & V_2 -> V_12 [ V_2 -> V_11 ] ;
V_2 -> V_13 = V_7 -> V_14 / 4 ;
V_2 -> V_15 = F_2 ( V_2 -> V_13 , sizeof( void * ) , V_16 ) ;
if ( V_2 -> V_15 == NULL ) {
return - V_17 ;
}
V_2 -> V_18 = F_2 ( V_2 -> V_13 , sizeof( struct V_19 ) , V_16 ) ;
if ( V_2 -> V_18 == NULL ) {
return - V_17 ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_13 ; V_8 ++ ) {
struct V_20 * V_21 ;
V_10 = false ;
V_21 = (struct V_20 * ) & V_7 -> V_22 [ V_8 * 4 ] ;
for ( V_9 = 0 ; V_9 < V_2 -> V_13 ; V_9 ++ ) {
if ( V_21 -> V_23 == V_2 -> V_18 [ V_9 ] . V_23 ) {
V_2 -> V_15 [ V_8 ] = & V_2 -> V_18 [ V_9 ] ;
V_10 = true ;
break;
}
}
if ( ! V_10 ) {
V_2 -> V_18 [ V_8 ] . V_24 = F_3 ( V_4 ,
V_2 -> V_25 ,
V_21 -> V_23 ) ;
if ( V_2 -> V_18 [ V_8 ] . V_24 == NULL ) {
F_4 ( L_1 ,
V_21 -> V_23 ) ;
return - V_26 ;
}
V_2 -> V_15 [ V_8 ] = & V_2 -> V_18 [ V_8 ] ;
V_2 -> V_18 [ V_8 ] . V_27 = F_5 ( V_2 -> V_18 [ V_8 ] . V_24 ) ;
V_2 -> V_18 [ V_8 ] . V_28 . V_29 = V_2 -> V_18 [ V_8 ] . V_27 ;
V_2 -> V_18 [ V_8 ] . V_28 . V_30 = V_21 -> V_31 ;
V_2 -> V_18 [ V_8 ] . V_28 . V_32 = V_21 -> V_33 ;
V_2 -> V_18 [ V_8 ] . V_28 . V_34 . V_29 = & V_2 -> V_18 [ V_8 ] . V_27 -> V_35 ;
V_2 -> V_18 [ V_8 ] . V_23 = V_21 -> V_23 ;
V_2 -> V_18 [ V_8 ] . V_36 = V_21 -> V_36 ;
F_6 ( & V_2 -> V_18 [ V_8 ] . V_28 ,
& V_2 -> V_37 ) ;
}
}
return F_7 ( & V_2 -> V_37 ) ;
}
int F_8 ( struct V_1 * V_2 , void * V_38 )
{
struct V_39 * V_40 = V_38 ;
T_1 * V_41 ;
unsigned V_42 , V_8 , V_36 = 0 ;
if ( ! V_40 -> V_43 ) {
return 0 ;
}
F_9 ( & V_2 -> V_37 ) ;
V_2 -> V_44 = 0 ;
V_2 -> V_45 = - 1 ;
V_2 -> V_11 = - 1 ;
V_2 -> V_46 = F_2 ( V_40 -> V_43 , sizeof( T_1 ) , V_16 ) ;
if ( V_2 -> V_46 == NULL ) {
return - V_17 ;
}
V_41 = ( T_1 * ) ( unsigned long ) ( V_40 -> V_12 ) ;
if ( F_10 ( V_2 -> V_46 , V_41 ,
sizeof( T_1 ) * V_40 -> V_43 ) ) {
return - V_47 ;
}
V_2 -> V_48 = V_40 -> V_43 ;
V_2 -> V_12 = F_2 ( V_2 -> V_48 , sizeof( struct V_6 ) , V_16 ) ;
if ( V_2 -> V_12 == NULL ) {
return - V_17 ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_48 ; V_8 ++ ) {
struct V_49 T_2 * * V_50 = NULL ;
struct V_49 V_51 ;
T_3 T_2 * V_52 ;
V_50 = ( void T_2 * ) ( unsigned long ) V_2 -> V_46 [ V_8 ] ;
if ( F_10 ( & V_51 , V_50 ,
sizeof( struct V_49 ) ) ) {
return - V_47 ;
}
V_2 -> V_12 [ V_8 ] . V_14 = V_51 . V_14 ;
V_2 -> V_12 [ V_8 ] . V_22 = NULL ;
V_2 -> V_12 [ V_8 ] . V_53 = V_51 . V_53 ;
if ( V_2 -> V_12 [ V_8 ] . V_53 == V_54 ) {
V_2 -> V_11 = V_8 ;
}
if ( V_2 -> V_12 [ V_8 ] . V_53 == V_55 ) {
V_2 -> V_45 = V_8 ;
if ( V_2 -> V_12 [ V_8 ] . V_14 == 0 )
return - V_56 ;
}
if ( V_2 -> V_12 [ V_8 ] . V_53 == V_57 &&
! V_2 -> V_12 [ V_8 ] . V_14 ) {
return - V_56 ;
}
V_2 -> V_12 [ V_8 ] . V_14 = V_51 . V_14 ;
V_2 -> V_12 [ V_8 ] . V_58 = ( void T_2 * ) ( unsigned long ) V_51 . V_59 ;
V_52 = ( T_3 * ) ( unsigned long ) V_51 . V_59 ;
if ( V_2 -> V_12 [ V_8 ] . V_53 != V_55 ) {
V_42 = V_2 -> V_12 [ V_8 ] . V_14 * sizeof( T_3 ) ;
V_2 -> V_12 [ V_8 ] . V_22 = F_11 ( V_42 , V_16 ) ;
if ( V_2 -> V_12 [ V_8 ] . V_22 == NULL ) {
return - V_17 ;
}
if ( F_10 ( V_2 -> V_12 [ V_8 ] . V_22 ,
V_2 -> V_12 [ V_8 ] . V_58 , V_42 ) ) {
return - V_47 ;
}
if ( V_2 -> V_12 [ V_8 ] . V_53 == V_57 ) {
V_36 = V_2 -> V_12 [ V_8 ] . V_22 [ 0 ] ;
}
} else {
V_2 -> V_12 [ V_8 ] . V_60 [ 0 ] = F_11 ( V_61 , V_16 ) ;
V_2 -> V_12 [ V_8 ] . V_60 [ 1 ] = F_11 ( V_61 , V_16 ) ;
if ( V_2 -> V_12 [ V_8 ] . V_60 [ 0 ] == NULL || V_2 -> V_12 [ V_8 ] . V_60 [ 1 ] == NULL ) {
F_12 ( V_2 -> V_12 [ V_8 ] . V_60 [ 0 ] ) ;
F_12 ( V_2 -> V_12 [ V_8 ] . V_60 [ 1 ] ) ;
return - V_17 ;
}
V_2 -> V_12 [ V_8 ] . V_62 [ 0 ] = - 1 ;
V_2 -> V_12 [ V_8 ] . V_62 [ 1 ] = - 1 ;
V_2 -> V_12 [ V_8 ] . V_63 = - 1 ;
V_2 -> V_12 [ V_8 ] . V_64 = ( ( V_2 -> V_12 [ V_8 ] . V_14 * 4 ) - 1 ) / V_61 ;
}
}
if ( V_2 -> V_12 [ V_2 -> V_45 ] . V_14 > ( 16 * 1024 ) ) {
F_4 ( L_2 ,
V_2 -> V_12 [ V_2 -> V_45 ] . V_14 ) ;
return - V_56 ;
}
V_2 -> V_65 = ( V_36 & V_66 ) != 0 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_67 , int error )
{
unsigned V_8 ;
if ( ! error && V_67 -> V_68 )
F_14 ( & V_67 -> V_37 ,
V_67 -> V_68 -> V_69 ) ;
else
F_15 ( & V_67 -> V_37 ) ;
if ( V_67 -> V_18 != NULL ) {
for ( V_8 = 0 ; V_8 < V_67 -> V_13 ; V_8 ++ ) {
if ( V_67 -> V_18 [ V_8 ] . V_24 )
F_16 ( V_67 -> V_18 [ V_8 ] . V_24 ) ;
}
}
F_12 ( V_67 -> V_70 ) ;
F_12 ( V_67 -> V_18 ) ;
F_12 ( V_67 -> V_15 ) ;
for ( V_8 = 0 ; V_8 < V_67 -> V_48 ; V_8 ++ ) {
F_12 ( V_67 -> V_12 [ V_8 ] . V_22 ) ;
F_12 ( V_67 -> V_12 [ V_8 ] . V_60 [ 0 ] ) ;
F_12 ( V_67 -> V_12 [ V_8 ] . V_60 [ 1 ] ) ;
}
F_12 ( V_67 -> V_12 ) ;
F_12 ( V_67 -> V_46 ) ;
F_17 ( V_67 -> V_5 , & V_67 -> V_68 ) ;
}
int F_18 ( struct V_3 * V_71 , void * V_38 , struct V_72 * V_25 )
{
struct V_73 * V_5 = V_71 -> V_74 ;
struct V_1 V_67 ;
struct V_6 * V_75 ;
int V_21 ;
F_19 ( & V_5 -> V_76 ) ;
memset ( & V_67 , 0 , sizeof( struct V_1 ) ) ;
V_67 . V_25 = V_25 ;
V_67 . V_5 = V_5 ;
V_67 . V_71 = V_5 -> V_71 ;
V_67 . V_77 = V_5 -> V_77 ;
V_21 = F_8 ( & V_67 , V_38 ) ;
if ( V_21 ) {
F_4 ( L_3 ) ;
F_13 ( & V_67 , V_21 ) ;
F_20 ( & V_5 -> V_76 ) ;
return V_21 ;
}
V_21 = F_21 ( V_5 , & V_67 . V_68 ) ;
if ( V_21 ) {
F_4 ( L_4 ) ;
F_13 ( & V_67 , V_21 ) ;
F_20 ( & V_5 -> V_76 ) ;
return V_21 ;
}
V_21 = F_1 ( & V_67 ) ;
if ( V_21 ) {
if ( V_21 != - V_78 )
F_4 ( L_5 , V_21 ) ;
F_13 ( & V_67 , V_21 ) ;
F_20 ( & V_5 -> V_76 ) ;
return V_21 ;
}
V_75 = & V_67 . V_12 [ V_67 . V_45 ] ;
V_67 . V_68 -> V_14 = V_75 -> V_14 ;
V_21 = F_22 ( & V_67 ) ;
if ( V_21 || V_67 . V_79 ) {
F_4 ( L_6 ) ;
F_13 ( & V_67 , V_21 ) ;
F_20 ( & V_5 -> V_76 ) ;
return V_21 ;
}
V_21 = F_23 ( & V_67 ) ;
if ( V_21 ) {
F_4 ( L_6 ) ;
F_13 ( & V_67 , V_21 ) ;
F_20 ( & V_5 -> V_76 ) ;
return V_21 ;
}
V_21 = F_24 ( V_5 , V_67 . V_68 ) ;
if ( V_21 ) {
F_4 ( L_7 ) ;
}
F_13 ( & V_67 , V_21 ) ;
F_20 ( & V_5 -> V_76 ) ;
return V_21 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_6 * V_80 = & V_2 -> V_12 [ V_2 -> V_45 ] ;
int V_8 ;
int V_42 = V_61 ;
for ( V_8 = V_80 -> V_63 + 1 ; V_8 <= V_80 -> V_64 ; V_8 ++ ) {
if ( V_8 == V_80 -> V_64 ) {
V_42 = ( V_80 -> V_14 * 4 ) % V_61 ;
if ( V_42 == 0 )
V_42 = V_61 ;
}
if ( F_10 ( V_2 -> V_68 -> V_81 + ( V_8 * ( V_61 / 4 ) ) ,
V_80 -> V_58 + ( V_8 * V_61 ) ,
V_42 ) )
return - V_47 ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_2 , int V_82 )
{
int V_83 ;
struct V_6 * V_80 = & V_2 -> V_12 [ V_2 -> V_45 ] ;
int V_8 ;
int V_42 = V_61 ;
for ( V_8 = V_80 -> V_63 + 1 ; V_8 < V_82 ; V_8 ++ ) {
if ( F_10 ( V_2 -> V_68 -> V_81 + ( V_8 * ( V_61 / 4 ) ) ,
V_80 -> V_58 + ( V_8 * V_61 ) ,
V_61 ) ) {
V_2 -> V_79 = - V_47 ;
return 0 ;
}
}
V_83 = V_80 -> V_62 [ 0 ] < V_80 -> V_62 [ 1 ] ? 0 : 1 ;
if ( V_82 == V_80 -> V_64 ) {
V_42 = ( V_80 -> V_14 * 4 ) % V_61 ;
if ( V_42 == 0 )
V_42 = V_61 ;
}
if ( F_10 ( V_80 -> V_60 [ V_83 ] ,
V_80 -> V_58 + ( V_82 * V_61 ) ,
V_42 ) ) {
V_2 -> V_79 = - V_47 ;
return 0 ;
}
memcpy ( ( void * ) ( V_2 -> V_68 -> V_81 + ( V_82 * ( V_61 / 4 ) ) ) , V_80 -> V_60 [ V_83 ] , V_42 ) ;
V_80 -> V_63 = V_82 ;
V_80 -> V_62 [ V_83 ] = V_82 ;
return V_83 ;
}
