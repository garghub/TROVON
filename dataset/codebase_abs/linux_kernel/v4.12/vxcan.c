static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_3 * V_7 ;
struct V_8 * V_9 = (struct V_8 * ) V_2 -> V_10 ;
struct V_11 * V_12 , * V_13 = & V_4 -> V_14 ;
if ( F_3 ( V_4 , V_2 ) )
return V_15 ;
F_4 () ;
V_7 = F_5 ( V_6 -> V_7 ) ;
if ( F_6 ( ! V_7 ) ) {
F_7 ( V_2 ) ;
V_4 -> V_14 . V_16 ++ ;
goto V_17;
}
V_2 = F_8 ( V_2 ) ;
if ( ! V_2 )
goto V_17;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = V_20 ;
V_2 -> V_4 = V_7 ;
V_2 -> V_21 = V_22 ;
if ( F_9 ( V_2 ) == V_23 ) {
V_13 -> V_24 ++ ;
V_13 -> V_25 += V_9 -> V_26 ;
V_12 = & V_7 -> V_14 ;
V_12 -> V_27 ++ ;
V_12 -> V_28 += V_9 -> V_26 ;
}
V_17:
F_10 () ;
return V_15 ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_3 * V_7 = F_12 ( V_6 -> V_7 ) ;
if ( ! V_7 )
return - V_29 ;
if ( V_7 -> V_30 & V_31 ) {
F_13 ( V_4 ) ;
F_13 ( V_7 ) ;
}
return 0 ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_3 * V_7 = F_12 ( V_6 -> V_7 ) ;
F_15 ( V_4 ) ;
if ( V_7 )
F_15 ( V_7 ) ;
return 0 ;
}
static int F_16 ( const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_3 * V_7 ;
int V_32 ;
F_4 () ;
V_7 = F_5 ( V_6 -> V_7 ) ;
V_32 = V_7 ? V_7 -> V_33 : 0 ;
F_10 () ;
return V_32 ;
}
static int F_17 ( struct V_3 * V_4 , int V_34 )
{
if ( V_4 -> V_30 & V_31 )
return - V_35 ;
if ( V_34 != V_36 && V_34 != V_37 )
return - V_38 ;
V_4 -> V_39 = V_34 ;
return 0 ;
}
static void F_18 ( struct V_3 * V_4 )
{
V_4 -> type = V_40 ;
V_4 -> V_39 = V_37 ;
V_4 -> V_41 = 0 ;
V_4 -> V_42 = 0 ;
V_4 -> V_43 = 0 ;
V_4 -> V_30 = ( V_44 | V_45 ) ;
V_4 -> V_46 = & V_47 ;
V_4 -> V_48 = true ;
}
static int F_19 ( struct V_49 * V_49 , struct V_3 * V_4 ,
struct V_50 * V_51 [] , struct V_50 * V_10 [] )
{
struct V_5 * V_6 ;
struct V_3 * V_7 ;
struct V_49 * V_52 ;
struct V_50 * V_53 [ V_54 + 1 ] , * * V_55 = V_51 ;
char V_56 [ V_57 ] ;
unsigned char V_58 ;
struct V_59 * V_60 = NULL ;
int V_61 ;
if ( V_10 && V_10 [ V_62 ] ) {
struct V_50 * V_63 ;
V_63 = V_10 [ V_62 ] ;
V_60 = F_20 ( V_63 ) ;
V_61 = F_21 ( V_53 ,
F_20 ( V_63 ) +
sizeof( struct V_59 ) ,
F_22 ( V_63 ) -
sizeof( struct V_59 ) ,
NULL ) ;
if ( V_61 < 0 )
return V_61 ;
V_55 = V_53 ;
}
if ( V_55 [ V_64 ] ) {
F_23 ( V_56 , V_55 [ V_64 ] , V_57 ) ;
V_58 = V_65 ;
} else {
snprintf ( V_56 , V_57 , V_66 L_1 ) ;
V_58 = V_67 ;
}
V_52 = F_24 ( V_49 , V_55 ) ;
if ( F_25 ( V_52 ) )
return F_26 ( V_52 ) ;
V_7 = F_27 ( V_52 , V_56 , V_58 ,
& V_68 , V_55 ) ;
if ( F_25 ( V_7 ) ) {
F_28 ( V_52 ) ;
return F_26 ( V_7 ) ;
}
if ( V_60 && V_4 -> V_33 )
V_7 -> V_33 = V_60 -> V_69 ;
V_61 = F_29 ( V_7 ) ;
F_28 ( V_52 ) ;
V_52 = NULL ;
if ( V_61 < 0 ) {
F_30 ( V_7 ) ;
return V_61 ;
}
F_15 ( V_7 ) ;
V_61 = F_31 ( V_7 , V_60 ) ;
if ( V_61 < 0 ) {
F_32 ( V_7 ) ;
return V_61 ;
}
if ( V_51 [ V_64 ] )
F_23 ( V_4 -> V_70 , V_51 [ V_64 ] , V_57 ) ;
else
snprintf ( V_4 -> V_70 , V_57 , V_66 L_1 ) ;
V_61 = F_29 ( V_4 ) ;
if ( V_61 < 0 ) {
F_32 ( V_7 ) ;
return V_61 ;
}
F_15 ( V_4 ) ;
V_6 = F_2 ( V_4 ) ;
F_33 ( V_6 -> V_7 , V_7 ) ;
V_6 = F_2 ( V_7 ) ;
F_33 ( V_6 -> V_7 , V_4 ) ;
return 0 ;
}
static void F_34 ( struct V_3 * V_4 , struct V_71 * V_72 )
{
struct V_5 * V_6 ;
struct V_3 * V_7 ;
V_6 = F_2 ( V_4 ) ;
V_7 = F_12 ( V_6 -> V_7 ) ;
F_35 ( V_6 -> V_7 , NULL ) ;
F_36 ( V_4 , V_72 ) ;
if ( V_7 ) {
V_6 = F_2 ( V_7 ) ;
F_35 ( V_6 -> V_7 , NULL ) ;
F_36 ( V_7 , V_72 ) ;
}
}
static struct V_49 * F_37 ( const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_3 * V_7 = F_12 ( V_6 -> V_7 ) ;
return V_7 ? F_38 ( V_7 ) : F_38 ( V_4 ) ;
}
static T_2 int F_39 ( void )
{
F_40 ( L_2 ) ;
return F_41 ( & V_68 ) ;
}
static T_3 void F_42 ( void )
{
F_43 ( & V_68 ) ;
}
