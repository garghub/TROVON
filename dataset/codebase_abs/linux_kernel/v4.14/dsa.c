static struct V_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return V_2 ;
}
int F_2 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 ;
int V_14 , V_15 ;
if ( F_3 ( V_8 ) ) {
V_14 = F_4 ( V_8 ) ;
if ( V_14 ) {
F_5 ( V_11 -> V_4 , L_1 ) ;
return V_14 ;
}
V_13 = F_6 ( V_8 ) ;
V_15 = F_7 ( V_8 ) ;
if ( V_15 < 0 )
V_15 = V_16 ;
V_13 -> V_17 = V_15 ;
F_8 ( V_13 ) ;
F_9 ( V_13 ) ;
if ( V_11 -> V_18 -> V_19 )
V_11 -> V_18 -> V_19 ( V_11 , V_6 -> V_20 , V_13 ) ;
F_10 ( & V_13 -> V_21 . V_4 ) ;
}
return 0 ;
}
const struct V_22 * F_11 ( int V_23 )
{
const struct V_22 * V_18 ;
if ( V_23 >= V_24 )
return F_12 ( - V_25 ) ;
V_18 = V_22 [ V_23 ] ;
if ( ! V_18 )
return F_12 ( - V_26 ) ;
return V_18 ;
}
int F_13 ( struct V_5 * V_27 )
{
struct V_10 * V_11 = V_27 -> V_11 ;
struct V_3 * V_28 ;
struct V_29 * V_30 ;
V_28 = V_27 -> V_31 ;
V_30 = F_14 ( V_11 -> V_4 , sizeof( * V_30 ) , V_32 ) ;
if ( ! V_30 )
return - V_33 ;
memcpy ( & V_27 -> V_29 , V_28 -> V_29 ,
sizeof( struct V_29 ) ) ;
V_27 -> V_34 = V_28 -> V_29 ;
memcpy ( V_30 , & V_27 -> V_29 ,
sizeof( struct V_29 ) ) ;
F_15 ( V_30 ) ;
V_28 -> V_29 = V_30 ;
return 0 ;
}
void F_16 ( struct V_5 * V_27 )
{
V_27 -> V_31 -> V_29 = V_27 -> V_34 ;
}
void F_17 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
if ( F_3 ( V_8 ) )
F_18 ( V_8 ) ;
}
static int F_19 ( struct V_35 * V_4 , void * V_36 )
{
if ( V_4 -> V_36 != NULL && ! strcmp ( V_4 -> V_36 -> V_37 , V_36 ) )
return 1 ;
return 0 ;
}
static struct V_35 * F_20 ( struct V_35 * V_38 , char * V_36 )
{
if ( F_19 ( V_38 , V_36 ) ) {
F_21 ( V_38 ) ;
return V_38 ;
}
return F_22 ( V_38 , V_36 , F_19 ) ;
}
struct V_3 * F_23 ( struct V_35 * V_4 )
{
struct V_35 * V_39 ;
V_39 = F_20 ( V_4 , L_2 ) ;
if ( V_39 != NULL ) {
struct V_3 * V_40 ;
V_40 = F_24 ( V_39 ) ;
F_25 ( V_40 ) ;
F_10 ( V_39 ) ;
return V_40 ;
}
return NULL ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_41 * V_42 , struct V_3 * V_43 )
{
struct V_44 * V_45 = V_4 -> V_46 ;
struct V_1 * V_47 = NULL ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
if ( F_27 ( V_45 == NULL ) ) {
F_28 ( V_2 ) ;
return 0 ;
}
V_2 = F_29 ( V_2 , V_52 ) ;
if ( ! V_2 )
return 0 ;
V_47 = V_45 -> V_53 ( V_2 , V_4 , V_42 ) ;
if ( ! V_47 ) {
F_28 ( V_2 ) ;
return 0 ;
}
V_2 = V_47 ;
V_51 = F_30 ( V_2 -> V_4 ) ;
F_31 ( V_2 , V_54 ) ;
V_2 -> V_55 = V_56 ;
V_2 -> V_57 = F_32 ( V_2 , V_2 -> V_4 ) ;
V_49 = F_33 ( V_51 -> V_58 ) ;
F_34 ( & V_49 -> V_59 ) ;
V_49 -> V_60 ++ ;
V_49 -> V_61 += V_2 -> V_62 ;
F_35 ( & V_49 -> V_59 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
static bool F_37 ( struct V_10 * V_11 , int V_51 )
{
return V_11 -> V_63 & ( 1 << V_51 ) && V_11 -> V_64 [ V_51 ] . V_31 ;
}
int F_38 ( struct V_10 * V_11 )
{
int V_65 , V_14 = 0 ;
for ( V_65 = 0 ; V_65 < V_11 -> V_66 ; V_65 ++ ) {
if ( ! F_37 ( V_11 , V_65 ) )
continue;
V_14 = F_39 ( V_11 -> V_64 [ V_65 ] . V_31 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_11 -> V_18 -> V_67 )
V_14 = V_11 -> V_18 -> V_67 ( V_11 ) ;
return V_14 ;
}
int F_40 ( struct V_10 * V_11 )
{
int V_65 , V_14 = 0 ;
if ( V_11 -> V_18 -> V_68 )
V_14 = V_11 -> V_18 -> V_68 ( V_11 ) ;
if ( V_14 )
return V_14 ;
for ( V_65 = 0 ; V_65 < V_11 -> V_66 ; V_65 ++ ) {
if ( ! F_37 ( V_11 , V_65 ) )
continue;
V_14 = F_41 ( V_11 -> V_64 [ V_65 ] . V_31 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
bool F_42 ( struct V_69 * V_70 )
{
return F_43 ( V_71 , V_70 ) ;
}
static int T_1 F_44 ( void )
{
int V_72 ;
V_71 = F_45 ( L_3 ,
V_73 ) ;
if ( ! V_71 )
return - V_33 ;
V_72 = F_46 () ;
if ( V_72 )
return V_72 ;
V_72 = F_47 () ;
if ( V_72 )
return V_72 ;
F_48 ( & V_74 ) ;
return 0 ;
}
static void T_2 F_49 ( void )
{
F_50 () ;
F_51 ( & V_74 ) ;
F_52 () ;
F_53 ( V_71 ) ;
}
