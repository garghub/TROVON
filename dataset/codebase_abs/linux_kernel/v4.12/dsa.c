static struct V_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return V_2 ;
}
int F_2 ( struct V_5 * V_6 , struct V_7 * V_4 ,
struct V_8 * V_9 , int V_10 )
{
struct V_11 * V_12 = V_9 -> V_13 ;
struct V_14 * V_15 ;
int V_16 , V_17 ;
if ( F_3 ( V_12 ) ) {
V_16 = F_4 ( V_12 ) ;
if ( V_16 ) {
F_5 ( V_4 , L_1 ) ;
return V_16 ;
}
V_15 = F_6 ( V_12 ) ;
V_17 = F_7 ( V_12 ) ;
if ( V_17 < 0 )
V_17 = V_18 ;
V_15 -> V_19 = V_17 ;
F_8 ( V_15 ) ;
F_9 ( V_15 ) ;
if ( V_6 -> V_20 -> V_21 )
V_6 -> V_20 -> V_21 ( V_6 , V_10 , V_15 ) ;
F_10 ( & V_15 -> V_22 . V_4 ) ;
}
return 0 ;
}
const struct V_23 * F_11 ( int V_24 )
{
const struct V_23 * V_20 ;
if ( V_24 >= V_25 )
return F_12 ( - V_26 ) ;
V_20 = V_23 [ V_24 ] ;
if ( ! V_20 )
return F_12 ( - V_27 ) ;
return V_20 ;
}
int F_13 ( struct V_5 * V_6 )
{
struct V_3 * V_28 ;
struct V_29 * V_30 ;
V_28 = V_6 -> V_31 -> V_32 ;
if ( V_6 -> V_32 )
V_28 = V_6 -> V_32 ;
V_30 = F_14 ( V_6 -> V_4 , sizeof( * V_30 ) , V_33 ) ;
if ( ! V_30 )
return - V_34 ;
memcpy ( & V_6 -> V_31 -> V_35 , V_28 -> V_29 ,
sizeof( struct V_29 ) ) ;
V_6 -> V_31 -> V_36 = V_28 -> V_29 ;
memcpy ( V_30 , & V_6 -> V_31 -> V_35 ,
sizeof( struct V_29 ) ) ;
F_15 ( V_30 ) ;
V_28 -> V_29 = V_30 ;
return 0 ;
}
void F_16 ( struct V_5 * V_6 )
{
struct V_3 * V_28 ;
V_28 = V_6 -> V_31 -> V_32 ;
if ( V_6 -> V_32 )
V_28 = V_6 -> V_32 ;
V_28 -> V_29 = V_6 -> V_31 -> V_36 ;
}
void F_17 ( struct V_8 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_3 ( V_12 ) )
F_18 ( V_12 ) ;
}
static int F_19 ( struct V_7 * V_4 , void * V_37 )
{
if ( V_4 -> V_37 != NULL && ! strcmp ( V_4 -> V_37 -> V_38 , V_37 ) )
return 1 ;
return 0 ;
}
static struct V_7 * F_20 ( struct V_7 * V_39 , char * V_37 )
{
if ( F_19 ( V_39 , V_37 ) ) {
F_21 ( V_39 ) ;
return V_39 ;
}
return F_22 ( V_39 , V_37 , F_19 ) ;
}
struct V_3 * F_23 ( struct V_7 * V_4 )
{
struct V_7 * V_40 ;
V_40 = F_20 ( V_4 , L_2 ) ;
if ( V_40 != NULL ) {
struct V_3 * V_41 ;
V_41 = F_24 ( V_40 ) ;
F_25 ( V_41 ) ;
F_10 ( V_40 ) ;
return V_41 ;
}
return NULL ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_42 * V_43 , struct V_3 * V_44 )
{
struct V_45 * V_31 = V_4 -> V_46 ;
struct V_1 * V_47 = NULL ;
if ( F_27 ( V_31 == NULL ) ) {
F_28 ( V_2 ) ;
return 0 ;
}
V_2 = F_29 ( V_2 , V_48 ) ;
if ( ! V_2 )
return 0 ;
V_47 = V_31 -> V_49 ( V_2 , V_4 , V_43 , V_44 ) ;
if ( ! V_47 ) {
F_28 ( V_2 ) ;
return 0 ;
}
V_2 = V_47 ;
F_30 ( V_2 , V_50 ) ;
V_2 -> V_51 = V_52 ;
V_2 -> V_53 = F_31 ( V_2 , V_2 -> V_4 ) ;
V_2 -> V_4 -> V_54 . V_55 ++ ;
V_2 -> V_4 -> V_54 . V_56 += V_2 -> V_57 ;
F_32 ( V_2 ) ;
return 0 ;
}
int F_33 ( struct V_5 * V_6 )
{
int V_58 , V_16 = 0 ;
for ( V_58 = 0 ; V_58 < V_6 -> V_59 ; V_58 ++ ) {
if ( ! F_34 ( V_6 , V_58 ) )
continue;
V_16 = F_35 ( V_6 -> V_60 [ V_58 ] . V_61 ) ;
if ( V_16 )
return V_16 ;
}
if ( V_6 -> V_20 -> V_62 )
V_16 = V_6 -> V_20 -> V_62 ( V_6 ) ;
return V_16 ;
}
int F_36 ( struct V_5 * V_6 )
{
int V_58 , V_16 = 0 ;
if ( V_6 -> V_20 -> V_63 )
V_16 = V_6 -> V_20 -> V_63 ( V_6 ) ;
if ( V_16 )
return V_16 ;
for ( V_58 = 0 ; V_58 < V_6 -> V_59 ; V_58 ++ ) {
if ( ! F_34 ( V_6 , V_58 ) )
continue;
V_16 = F_37 ( V_6 -> V_60 [ V_58 ] . V_61 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
static int T_1 F_38 ( void )
{
int V_64 ;
V_64 = F_39 () ;
if ( V_64 )
return V_64 ;
V_64 = F_40 () ;
if ( V_64 )
return V_64 ;
F_41 ( & V_65 ) ;
return 0 ;
}
static void T_2 F_42 ( void )
{
F_43 () ;
F_44 ( & V_65 ) ;
F_45 () ;
}
