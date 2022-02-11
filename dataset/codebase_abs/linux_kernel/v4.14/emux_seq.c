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
if ( ! V_26 ) {
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
if ( V_2 -> V_10 >= 0 ) {
F_8 ( V_2 -> V_10 ) ;
V_2 -> V_10 = - 1 ;
}
}
struct V_25 *
F_4 ( struct V_1 * V_2 , char * V_11 ,
int V_36 , int V_37 ,
struct V_7 * V_38 )
{
struct V_25 * V_26 ;
int V_6 , type , V_39 ;
V_26 = F_9 ( sizeof( * V_26 ) , V_40 ) ;
if ( ! V_26 )
return NULL ;
V_26 -> V_32 . V_41 = F_10 ( V_36 , sizeof( * V_26 -> V_32 . V_41 ) ,
V_40 ) ;
if ( ! V_26 -> V_32 . V_41 ) {
F_11 ( V_26 ) ;
return NULL ;
}
for ( V_6 = 0 ; V_6 < V_36 ; V_6 ++ )
V_26 -> V_32 . V_41 [ V_6 ] . V_42 = V_6 ;
V_26 -> V_32 . V_43 = V_26 ;
V_26 -> V_32 . V_36 = V_36 ;
V_26 -> V_2 = V_2 ;
V_26 -> V_32 . V_10 = V_2 -> V_10 ;
#ifdef F_12
F_13 ( V_26 ) ;
#endif
V_38 -> V_44 = V_45 ;
V_38 -> V_43 = V_26 ;
V_39 = V_46 ;
if ( V_37 ) {
type = V_47 ;
} else {
type = V_48 ;
V_39 |= V_49 ;
}
V_26 -> V_32 . V_33 = F_14 ( V_2 -> V_10 , V_38 ,
V_39 , type , V_36 ,
V_2 -> V_50 , V_11 ) ;
return V_26 ;
}
static void
V_45 ( void * V_43 )
{
struct V_25 * V_26 ;
V_26 = V_43 ;
if ( V_26 ) {
#ifdef F_12
F_15 ( V_26 ) ;
#endif
F_11 ( V_26 -> V_32 . V_41 ) ;
F_11 ( V_26 ) ;
}
}
static void
F_5 ( struct V_25 * V_26 )
{
V_26 -> V_51 = V_52 ;
V_26 -> V_53 = 0 ;
F_16 ( V_26 ) ;
}
void
F_16 ( struct V_25 * V_33 )
{
int V_6 ;
F_17 ( V_33 ) ;
F_18 ( & V_33 -> V_32 ) ;
#ifdef F_12
F_19 ( V_33 ) ;
#endif
V_33 -> V_54 [ V_55 ] = 0 ;
V_33 -> V_54 [ V_56 ] = 0 ;
V_33 -> V_54 [ V_57 ] = 1 ;
for ( V_6 = 0 ; V_6 < V_33 -> V_32 . V_36 ; V_6 ++ ) {
struct V_58 * V_59 = V_33 -> V_32 . V_41 + V_6 ;
V_59 -> V_60 = ( ( V_33 -> V_51 >> V_6 ) & 1 ) ? 1 : 0 ;
}
}
int
V_24 ( struct V_61 * V_62 , int V_63 , void * V_43 ,
int V_64 , int V_65 )
{
struct V_25 * V_33 ;
V_33 = V_43 ;
if ( F_20 ( ! V_33 || ! V_62 ) )
return - V_66 ;
F_21 ( & V_67 , V_62 , & V_33 -> V_32 ) ;
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 )
{
V_2 -> V_68 ++ ;
if ( ! F_23 ( V_2 -> V_69 . V_17 ) )
goto V_70;
if ( ! F_23 ( V_2 -> V_4 -> V_71 ) ) {
F_24 ( V_2 -> V_69 . V_17 ) ;
V_70:
V_2 -> V_68 -- ;
return 0 ;
}
return 1 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_72 ;
F_26 ( & V_2 -> V_73 ) ;
V_72 = F_22 ( V_2 ) ;
F_27 ( & V_2 -> V_73 ) ;
return V_72 ;
}
static void
F_28 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_4 -> V_71 ) ;
V_2 -> V_68 -- ;
if ( V_2 -> V_68 <= 0 )
F_7 ( V_2 ) ;
F_24 ( V_2 -> V_69 . V_17 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_73 ) ;
F_28 ( V_2 ) ;
F_27 ( & V_2 -> V_73 ) ;
}
static int
V_20 ( void * V_43 , struct V_74 * V_75 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
V_26 = V_43 ;
if ( F_20 ( ! V_26 ) )
return - V_66 ;
V_2 = V_26 -> V_2 ;
if ( F_20 ( ! V_2 ) )
return - V_66 ;
F_26 ( & V_2 -> V_73 ) ;
F_5 ( V_26 ) ;
F_22 ( V_2 ) ;
F_27 ( & V_2 -> V_73 ) ;
return 0 ;
}
static int
V_22 ( void * V_43 , struct V_74 * V_75 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
V_26 = V_43 ;
if ( F_20 ( ! V_26 ) )
return - V_66 ;
V_2 = V_26 -> V_2 ;
if ( F_20 ( ! V_2 ) )
return - V_66 ;
F_26 ( & V_2 -> V_73 ) ;
F_17 ( V_26 ) ;
F_28 ( V_2 ) ;
F_27 ( & V_2 -> V_73 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_6 ;
V_2 -> V_76 = NULL ;
if ( V_2 -> V_77 <= 0 )
return 0 ;
V_2 -> V_76 = F_10 ( V_2 -> V_77 , sizeof( * V_2 -> V_76 ) , V_40 ) ;
if ( ! V_2 -> V_76 )
return - V_28 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_77 ; V_6 ++ ) {
struct V_78 * V_79 ;
struct V_80 * V_81 ;
if ( F_31 ( V_4 , V_2 -> V_82 + V_6 , & V_79 ) < 0 )
goto V_70;
V_81 = V_79 -> V_43 ;
sprintf ( V_79 -> V_11 , L_8 , V_2 -> V_11 ) ;
V_81 -> V_83 = V_84 ;
V_81 -> V_10 = V_2 -> V_10 ;
V_81 -> V_33 = V_2 -> V_31 [ V_6 ] ;
if ( F_32 ( V_4 , V_79 ) < 0 ) {
F_33 ( V_4 , V_79 ) ;
goto V_70;
}
V_2 -> V_76 [ V_6 ] = V_79 ;
}
return 0 ;
V_70:
F_34 ( V_2 ) ;
return - V_28 ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! V_2 -> V_76 )
return 0 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_77 ; V_6 ++ ) {
if ( V_2 -> V_76 [ V_6 ] )
F_33 ( V_2 -> V_4 , V_2 -> V_76 [ V_6 ] ) ;
}
F_11 ( V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
return 0 ;
}
