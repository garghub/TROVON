static void F_1 ( struct V_1 * V_1 )
{
#ifdef F_2
if ( V_1 -> V_2 ) {
int V_3 ;
struct V_4 * V_5 = V_1 -> V_6 ;
for ( V_3 = 0 ; V_3 < 10 && V_5 -> V_7 . V_1 [ V_3 ] != V_1 ; V_3 ++ ) ;
F_3 ( L_1 , V_3 , V_1 -> V_2 ) ;
}
#endif
}
static void F_4 ( struct V_1 * V_1 )
{
int V_8 = 0 ;
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_9 ;
V_5 -> V_11 ++ ;
if ( V_1 -> V_2 ) {
F_3 ( L_2 , V_1 -> V_2 ) ;
return;
}
if ( V_10 ) {
int V_12 = - 1 ;
if ( - 2 == V_10 -> V_13 ) {
V_12 = 0 ;
memcpy ( V_5 -> V_14 , V_5 -> V_15 , sizeof( V_5 -> V_14 ) ) ;
V_10 -> V_13 = - 1 ;
} else {
int V_3 ;
for ( V_3 = 0 ; V_3 < 21 ; V_3 ++ ) {
if ( V_5 -> V_14 [ V_3 ] != ( ( char * ) V_5 -> V_15 ) [ V_3 ] ) {
if ( V_12 < 0 )
V_12 = V_3 ;
V_5 -> V_14 [ V_3 ] = ( ( char * ) V_5 -> V_15 ) [ V_3 ] ;
}
}
}
if ( 0 <= V_12 ) {
int V_16 = V_10 -> V_13 + 1 ;
if ( V_16 >= V_17 || V_16 < 0 )
V_16 = 0 ;
memcpy ( V_10 -> V_18 + V_16 , V_5 -> V_15 , sizeof( V_10 -> V_18 [ 0 ] ) ) ;
V_10 -> V_19 [ V_16 ] = V_12 ;
V_10 -> V_13 = V_16 ;
F_5 ( & V_5 -> V_20 ) ;
}
}
if ( V_5 -> V_21 ) {
if ( 0 == V_5 -> V_21 -> V_22 )
do {
V_8 = F_6 ( V_5 -> V_21 -> V_1 [ V_5 -> V_21 -> V_22 ++ ] , V_23 ) ;
} while ( ! V_8 && V_5 -> V_21 -> V_22 < V_5 -> V_21 -> V_24 );
} else
if ( V_10 && V_10 -> V_25 >= 0 && V_10 -> V_25 < V_26 ) {
if ( V_10 -> V_25 != V_10 -> V_27 ) {
int V_28 , V_29 = V_10 -> V_27 + 1 ;
if ( V_29 >= V_26 )
V_29 = 0 ;
for ( V_28 = 0 ; V_28 < V_30 && ! V_8 ; ++ V_28 )
if ( 0 == V_5 -> V_7 . V_1 [ V_28 ] -> V_2 ) {
struct V_31 * V_32 = V_10 -> V_32 + V_29 ;
F_7 ( V_5 -> V_7 . V_1 [ V_28 ] , V_5 -> V_33 ,
F_8 ( V_5 -> V_33 , 0x04 ) , & V_32 -> V_34 . V_35 ,
V_32 -> type == V_36 ? sizeof( struct V_37 ) : 5 ,
F_1 , V_5 ) ;
V_8 = F_6 ( V_5 -> V_7 . V_1 [ V_28 ] , V_23 ) ;
V_10 -> V_27 = V_29 ;
break;
}
}
}
if ( V_8 )
F_9 ( V_38 L_3 , V_8 ) ;
V_1 -> V_33 = V_5 -> V_33 ;
F_6 ( V_1 , V_23 ) ;
}
int F_10 ( struct V_4 * V_5 )
{
int V_8 = 0 ,
V_3 ;
if ( NULL == ( V_5 -> V_7 . V_39 = F_11 ( V_40 * V_30 , V_41 ) ) ) {
V_8 = - V_42 ;
} else
for ( V_3 = 0 ; V_3 < V_30 ; ++ V_3 ) {
if ( NULL == ( V_5 -> V_7 . V_1 [ V_3 ] = F_12 ( 0 , V_41 ) ) ) {
V_8 = - V_42 ;
break;
}
F_7 ( V_5 -> V_7 . V_1 [ V_3 ] , V_5 -> V_33 ,
F_8 ( V_5 -> V_33 , 0x04 ) ,
V_5 -> V_7 . V_39 + V_40 * V_3 , 0 ,
F_1 , V_5
) ;
}
return V_8 ;
}
int F_13 ( struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_43 = F_12 ( 0 , V_41 ) ) )
return - V_42 ;
if ( ! ( V_5 -> V_15 = F_11 ( 21 , V_41 ) ) ) {
F_14 ( V_5 -> V_43 ) ;
return - V_42 ;
}
F_15 ( & V_5 -> V_44 ) ;
F_16 ( V_5 -> V_43 , V_5 -> V_33 , F_17 ( V_5 -> V_33 , 0x4 ) ,
V_5 -> V_15 , 21 ,
F_4 , V_5 ,
10 ) ;
return F_6 ( V_5 -> V_43 , V_41 ) ;
}
static void F_18 ( struct V_45 * V_46 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_30 ; ++ V_3 ) {
F_19 ( V_46 -> V_1 [ V_3 ] ) ;
F_14 ( V_46 -> V_1 [ V_3 ] ) ;
V_46 -> V_1 [ V_3 ] = NULL ;
}
F_20 ( V_46 -> V_39 ) ;
}
static int F_21 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_51 * * V_52 )
{
int V_33 ;
struct V_51 * V_53 ;
int V_8 ;
for ( V_33 = 0 ; V_33 < V_54 ; ++ V_33 )
if ( V_55 [ V_33 ] && ! V_56 [ V_33 ] )
break;
if ( V_33 >= V_54 )
return - V_57 ;
V_8 = F_22 ( & V_50 -> V_33 , V_58 [ V_33 ] , V_59 [ V_33 ] , V_60 ,
sizeof( struct V_4 ) , & V_53 ) ;
if ( V_8 < 0 )
return V_8 ;
V_56 [ V_5 ( V_53 ) -> V_61 = V_33 ] = 1 ;
V_53 -> V_62 = V_63 ;
V_5 ( V_53 ) -> V_33 = V_48 ;
F_15 ( & V_5 ( V_53 ) -> V_64 ) ;
F_23 ( & V_5 ( V_53 ) -> V_65 ) ;
F_24 ( & V_5 ( V_53 ) -> V_66 ) ;
strcpy ( V_53 -> V_67 , L_4 V_68 L_5 ) ;
sprintf ( V_53 -> V_69 , L_6 V_68 L_5 ) ;
sprintf ( V_53 -> V_70 , L_7 ,
V_53 -> V_69 ,
F_25 ( V_48 -> V_71 . V_72 ) ,
F_25 ( V_48 -> V_71 . V_73 ) ,
0 ,
V_5 ( V_53 ) -> V_33 -> V_74 -> V_75 , V_5 ( V_53 ) -> V_33 -> V_76
) ;
* V_52 = V_53 ;
return 0 ;
}
static int F_26 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const struct V_77 * V_78 ,
struct V_51 * * V_52 )
{
int V_8 ;
struct V_51 * V_53 ;
* V_52 = NULL ;
if ( F_25 ( V_48 -> V_71 . V_72 ) != 0x1604 ||
( F_25 ( V_48 -> V_71 . V_73 ) != V_79 &&
F_25 ( V_48 -> V_71 . V_73 ) != V_80 &&
F_25 ( V_48 -> V_71 . V_73 ) != V_81 ) )
return - V_82 ;
V_8 = F_21 ( V_48 , V_50 , & V_53 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( V_8 = F_27 ( V_53 , V_48 ) ) < 0 ||
( V_8 = F_28 ( V_53 ) ) < 0 ) {
F_29 ( V_53 ) ;
return V_8 ;
}
* V_52 = V_53 ;
return 0 ;
}
static int F_30 ( struct V_49 * V_50 , const struct V_77 * V_59 )
{
struct V_51 * V_53 ;
int V_8 ;
V_8 = F_26 ( F_31 ( V_50 ) , V_50 , V_59 , & V_53 ) ;
if ( V_8 < 0 )
return V_8 ;
F_32 ( & V_50 -> V_33 , V_53 ) ;
return 0 ;
}
static void F_33 ( struct V_49 * V_50 )
{
F_34 ( F_31 ( V_50 ) ,
F_35 ( V_50 ) ) ;
}
static void V_63 ( struct V_51 * V_53 )
{
F_20 ( V_5 ( V_53 ) -> V_15 ) ;
F_14 ( V_5 ( V_53 ) -> V_43 ) ;
if ( V_5 ( V_53 ) -> V_9 )
F_36 ( V_5 ( V_53 ) -> V_9 , sizeof( * V_5 ( V_53 ) -> V_9 ) ) ;
if ( V_5 ( V_53 ) -> V_61 >= 0 && V_5 ( V_53 ) -> V_61 < V_54 )
V_56 [ V_5 ( V_53 ) -> V_61 ] = 0 ;
}
static void F_34 ( struct V_47 * V_48 , void * V_83 )
{
if ( V_83 ) {
struct V_51 * V_53 = V_83 ;
struct V_4 * V_5 = V_5 ( V_53 ) ;
struct V_84 * V_85 ;
V_5 -> V_86 = V_87 ;
F_18 ( & V_5 -> V_7 ) ;
F_19 ( V_5 -> V_43 ) ;
F_37 ( V_53 ) ;
F_38 (p, &usX2Y->midi_list) {
F_39 ( V_85 ) ;
}
if ( V_5 -> V_9 )
F_5 ( & V_5 -> V_20 ) ;
F_29 ( V_53 ) ;
}
}
