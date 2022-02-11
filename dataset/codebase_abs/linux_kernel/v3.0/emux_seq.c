int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
int V_6 ;
struct V_7 V_8 ;
char V_9 [ 64 ] ;
V_2 -> V_10 = F_2 ( V_4 , V_5 ,
L_1 , V_2 -> V_11 ) ;
if ( V_2 -> V_10 < 0 ) {
F_3 ( V_12 L_2 ) ;
return - V_13 ;
}
if ( V_2 -> V_14 < 0 ) {
F_3 ( V_15 L_3 ) ;
V_2 -> V_14 = 1 ;
} else if ( V_2 -> V_14 >= V_16 ) {
F_3 ( V_15 L_4
L_5 , V_16 ) ;
V_2 -> V_14 = V_16 ;
}
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_17 = V_18 ;
V_8 . V_19 = V_20 ;
V_8 . V_21 = V_22 ;
V_8 . V_23 = V_24 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_14 ; V_6 ++ ) {
struct V_25 * V_26 ;
sprintf ( V_9 , L_6 , V_2 -> V_11 , V_6 ) ;
V_26 = F_4 ( V_2 , V_9 , V_27 ,
0 , & V_8 ) ;
if ( V_26 == NULL ) {
F_3 ( V_12 L_7 ) ;
return - V_28 ;
}
V_26 -> V_29 = V_30 ;
F_5 ( V_26 ) ;
V_2 -> V_31 [ V_6 ] = V_26 -> V_32 . V_33 ;
V_2 -> V_34 [ V_6 ] = V_26 ;
}
return 0 ;
}
void
F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 )
F_7 ( V_2 ) ;
F_8 ( & V_2 -> V_36 ) ;
if ( V_2 -> V_10 >= 0 ) {
F_9 ( V_2 -> V_10 ) ;
V_2 -> V_10 = - 1 ;
}
F_10 ( & V_2 -> V_36 ) ;
}
struct V_25 *
F_4 ( struct V_1 * V_2 , char * V_11 ,
int V_37 , int V_38 ,
struct V_7 * V_39 )
{
struct V_25 * V_26 ;
int V_6 , type , V_40 ;
if ( ( V_26 = F_11 ( sizeof( * V_26 ) , V_41 ) ) == NULL ) {
F_3 ( V_12 L_8 ) ;
return NULL ;
}
V_26 -> V_32 . V_42 = F_12 ( V_37 , sizeof( struct V_43 ) , V_41 ) ;
if ( V_26 -> V_32 . V_42 == NULL ) {
F_3 ( V_12 L_8 ) ;
F_13 ( V_26 ) ;
return NULL ;
}
for ( V_6 = 0 ; V_6 < V_37 ; V_6 ++ )
V_26 -> V_32 . V_42 [ V_6 ] . V_44 = V_6 ;
V_26 -> V_32 . V_45 = V_26 ;
V_26 -> V_32 . V_37 = V_37 ;
V_26 -> V_2 = V_2 ;
V_26 -> V_32 . V_10 = V_2 -> V_10 ;
#ifdef F_14
F_15 ( V_26 ) ;
#endif
V_39 -> V_46 = V_47 ;
V_39 -> V_45 = V_26 ;
V_40 = V_48 ;
if ( V_38 ) {
type = V_49 ;
} else {
type = V_50 ;
V_40 |= V_51 ;
}
V_26 -> V_32 . V_33 = F_16 ( V_2 -> V_10 , V_39 ,
V_40 , type , V_37 ,
V_2 -> V_52 , V_11 ) ;
return V_26 ;
}
static void
V_47 ( void * V_45 )
{
struct V_25 * V_26 ;
V_26 = V_45 ;
if ( V_26 ) {
#ifdef F_14
F_17 ( V_26 ) ;
#endif
F_13 ( V_26 -> V_32 . V_42 ) ;
F_13 ( V_26 ) ;
}
}
static void
F_5 ( struct V_25 * V_26 )
{
V_26 -> V_53 = V_54 ;
V_26 -> V_55 = 0 ;
F_18 ( V_26 ) ;
}
void
F_18 ( struct V_25 * V_33 )
{
int V_6 ;
F_19 ( V_33 ) ;
F_20 ( & V_33 -> V_32 ) ;
#ifdef F_14
F_21 ( V_33 ) ;
#endif
V_33 -> V_56 [ V_57 ] = 0 ;
V_33 -> V_56 [ V_58 ] = 0 ;
V_33 -> V_56 [ V_59 ] = 1 ;
for ( V_6 = 0 ; V_6 < V_33 -> V_32 . V_37 ; V_6 ++ ) {
struct V_43 * V_60 = V_33 -> V_32 . V_42 + V_6 ;
V_60 -> V_61 = ( ( V_33 -> V_53 >> V_6 ) & 1 ) ? 1 : 0 ;
}
}
int
V_24 ( struct V_62 * V_63 , int V_64 , void * V_45 ,
int V_65 , int V_66 )
{
struct V_25 * V_33 ;
V_33 = V_45 ;
if ( F_22 ( ! V_33 || ! V_63 ) )
return - V_67 ;
F_23 ( & V_68 , V_63 , & V_33 -> V_32 ) ;
return 0 ;
}
int
F_24 ( struct V_1 * V_2 )
{
V_2 -> V_69 ++ ;
if ( ! F_25 ( V_2 -> V_70 . V_17 ) )
goto V_71;
if ( ! F_25 ( V_2 -> V_4 -> V_72 ) ) {
F_26 ( V_2 -> V_70 . V_17 ) ;
V_71:
V_2 -> V_69 -- ;
return 0 ;
}
return 1 ;
}
void
F_27 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_4 -> V_72 ) ;
V_2 -> V_69 -- ;
if ( V_2 -> V_69 <= 0 )
F_7 ( V_2 ) ;
F_26 ( V_2 -> V_70 . V_17 ) ;
}
static int
V_20 ( void * V_45 , struct V_73 * V_74 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
V_26 = V_45 ;
if ( F_22 ( ! V_26 ) )
return - V_67 ;
V_2 = V_26 -> V_2 ;
if ( F_22 ( ! V_2 ) )
return - V_67 ;
F_8 ( & V_2 -> V_36 ) ;
F_5 ( V_26 ) ;
F_24 ( V_2 ) ;
F_10 ( & V_2 -> V_36 ) ;
return 0 ;
}
static int
V_22 ( void * V_45 , struct V_73 * V_74 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
V_26 = V_45 ;
if ( F_22 ( ! V_26 ) )
return - V_67 ;
V_2 = V_26 -> V_2 ;
if ( F_22 ( ! V_2 ) )
return - V_67 ;
F_8 ( & V_2 -> V_36 ) ;
F_19 ( V_26 ) ;
F_27 ( V_2 ) ;
F_10 ( & V_2 -> V_36 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_6 ;
V_2 -> V_75 = NULL ;
if ( V_2 -> V_76 <= 0 )
return 0 ;
V_2 -> V_75 = F_12 ( V_2 -> V_76 , sizeof( struct V_77 * ) , V_41 ) ;
if ( V_2 -> V_75 == NULL )
return - V_28 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_76 ; V_6 ++ ) {
struct V_77 * V_78 ;
struct V_79 * V_80 ;
if ( F_29 ( V_4 , V_2 -> V_81 + V_6 , & V_78 ) < 0 )
goto V_71;
V_80 = V_78 -> V_45 ;
sprintf ( V_78 -> V_11 , L_9 , V_2 -> V_11 ) ;
V_80 -> V_82 = V_83 ;
V_80 -> V_10 = V_2 -> V_10 ;
V_80 -> V_33 = V_2 -> V_31 [ V_6 ] ;
if ( F_30 ( V_4 , V_78 ) < 0 ) {
F_31 ( V_4 , V_78 ) ;
goto V_71;
}
V_2 -> V_75 [ V_6 ] = V_78 ;
}
return 0 ;
V_71:
F_32 ( V_2 ) ;
return - V_28 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_6 ;
if ( V_2 -> V_75 == NULL )
return 0 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_76 ; V_6 ++ ) {
if ( V_2 -> V_75 [ V_6 ] )
F_31 ( V_2 -> V_4 , V_2 -> V_75 [ V_6 ] ) ;
}
F_13 ( V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
return 0 ;
}
