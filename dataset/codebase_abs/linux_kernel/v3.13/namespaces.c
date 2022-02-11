static char * F_1 ( struct V_1 * V_1 , char * V_2 , int V_3 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
const struct V_6 * V_7 = F_2 ( V_4 ) -> V_8 . V_7 ;
return F_3 ( V_1 , V_2 , V_3 , L_1 ,
V_7 -> V_9 , V_4 -> V_10 ) ;
}
static struct V_1 * F_4 ( struct V_11 * V_12 ,
struct V_13 * V_14 , const struct V_6 * V_7 )
{
struct V_1 * V_1 , * V_15 ;
struct V_4 * V_4 ;
struct V_16 * V_17 ;
struct V_18 V_19 = { . V_9 = L_2 , } ;
void * V_8 ;
V_8 = V_7 -> V_20 ( V_14 ) ;
if ( ! V_8 )
return F_5 ( - V_21 ) ;
V_1 = F_6 ( V_12 , & V_19 ) ;
if ( ! V_1 ) {
V_7 -> V_22 ( V_8 ) ;
return F_5 ( - V_23 ) ;
}
V_4 = F_7 ( V_12 , V_7 -> V_24 ( V_8 ) ) ;
if ( ! V_4 ) {
F_8 ( V_1 ) ;
V_7 -> V_22 ( V_8 ) ;
return F_5 ( - V_23 ) ;
}
V_17 = F_2 ( V_4 ) ;
if ( V_4 -> V_25 & V_26 ) {
V_4 -> V_27 = V_4 -> V_28 = V_4 -> V_29 = V_30 ;
V_4 -> V_31 = & V_32 ;
V_4 -> V_33 = V_34 | V_35 ;
V_4 -> V_36 = & V_37 ;
V_17 -> V_8 . V_7 = V_7 ;
V_17 -> V_8 . V_8 = V_8 ;
F_9 ( V_4 ) ;
} else {
V_7 -> V_22 ( V_8 ) ;
}
F_10 ( V_1 , & V_38 ) ;
V_15 = F_11 ( V_1 , V_4 ) ;
if ( V_15 ) {
F_8 ( V_1 ) ;
V_1 = V_15 ;
}
return V_1 ;
}
static void * F_12 ( struct V_1 * V_1 , struct V_39 * V_40 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
struct V_11 * V_12 = V_4 -> V_41 ;
struct V_16 * V_17 = F_2 ( V_4 ) ;
struct V_13 * V_14 ;
struct V_42 V_43 ;
void * error = F_5 ( - V_44 ) ;
V_14 = F_13 ( V_4 ) ;
if ( ! V_14 )
goto V_45;
if ( ! F_14 ( V_14 , V_46 ) )
goto V_47;
V_43 . V_1 = F_4 ( V_12 , V_14 , V_17 -> V_8 . V_7 ) ;
if ( F_15 ( V_43 . V_1 ) ) {
error = F_16 ( V_43 . V_1 ) ;
goto V_47;
}
V_43 . V_48 = F_17 ( V_40 -> V_42 . V_48 ) ;
F_18 ( V_40 , & V_43 ) ;
error = NULL ;
V_47:
F_19 ( V_14 ) ;
V_45:
return error ;
}
static int F_20 ( struct V_1 * V_1 , char T_1 * V_2 , int V_3 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
struct V_16 * V_17 = F_2 ( V_4 ) ;
const struct V_6 * V_7 = V_17 -> V_8 . V_7 ;
struct V_13 * V_14 ;
void * V_8 ;
char V_9 [ 50 ] ;
int V_49 = - V_44 ;
V_14 = F_13 ( V_4 ) ;
if ( ! V_14 )
goto V_45;
if ( ! F_14 ( V_14 , V_46 ) )
goto V_47;
V_49 = - V_21 ;
V_8 = V_7 -> V_20 ( V_14 ) ;
if ( ! V_8 )
goto V_47;
snprintf ( V_9 , sizeof( V_9 ) , L_3 , V_7 -> V_9 , V_7 -> V_24 ( V_8 ) ) ;
V_49 = strlen ( V_9 ) ;
if ( V_49 > V_3 )
V_49 = V_3 ;
if ( F_21 ( V_2 , V_9 , V_49 ) )
V_49 = - V_50 ;
V_7 -> V_22 ( V_8 ) ;
V_47:
F_19 ( V_14 ) ;
V_45:
return V_49 ;
}
static int F_22 ( struct V_4 * V_51 ,
struct V_1 * V_1 , struct V_13 * V_14 , const void * V_52 )
{
const struct V_6 * V_7 = V_52 ;
struct V_4 * V_4 ;
struct V_16 * V_17 ;
V_4 = F_23 ( V_51 -> V_41 , V_14 ) ;
if ( ! V_4 )
goto V_45;
V_17 = F_2 ( V_4 ) ;
V_4 -> V_33 = V_53 | V_54 ;
V_4 -> V_31 = & V_55 ;
V_17 -> V_8 . V_7 = V_7 ;
F_10 ( V_1 , & V_56 ) ;
F_24 ( V_1 , V_4 ) ;
if ( F_25 ( V_1 , 0 ) )
return 0 ;
V_45:
return - V_21 ;
}
static int F_26 ( struct V_57 * V_57 , struct V_58 * V_59 )
{
struct V_13 * V_14 = F_13 ( F_27 ( V_57 ) ) ;
const struct V_6 * * V_60 , * * V_61 ;
if ( ! V_14 )
return - V_21 ;
if ( ! F_28 ( V_57 , V_59 ) )
goto V_45;
if ( V_59 -> V_62 >= 2 + F_29 ( V_63 ) )
goto V_45;
V_60 = V_63 + ( V_59 -> V_62 - 2 ) ;
V_61 = & V_63 [ F_29 ( V_63 ) - 1 ] ;
while ( V_60 <= V_61 ) {
const struct V_6 * V_64 = * V_60 ;
if ( ! F_30 ( V_57 , V_59 , V_64 -> V_9 , strlen ( V_64 -> V_9 ) ,
F_22 , V_14 , V_64 ) )
break;
V_59 -> V_62 ++ ;
V_60 ++ ;
}
V_45:
F_19 ( V_14 ) ;
return 0 ;
}
static struct V_1 * F_31 ( struct V_4 * V_51 ,
struct V_1 * V_1 , unsigned int V_65 )
{
int error ;
struct V_13 * V_14 = F_13 ( V_51 ) ;
const struct V_6 * * V_60 , * * V_61 ;
unsigned int V_49 = V_1 -> V_66 . V_49 ;
error = - V_21 ;
if ( ! V_14 )
goto V_67;
V_61 = & V_63 [ F_29 ( V_63 ) ] ;
for ( V_60 = V_63 ; V_60 < V_61 ; V_60 ++ ) {
if ( strlen ( ( * V_60 ) -> V_9 ) != V_49 )
continue;
if ( ! memcmp ( V_1 -> V_66 . V_9 , ( * V_60 ) -> V_9 , V_49 ) )
break;
}
if ( V_60 == V_61 )
goto V_45;
error = F_22 ( V_51 , V_1 , V_14 , * V_60 ) ;
V_45:
F_19 ( V_14 ) ;
V_67:
return F_5 ( error ) ;
}
struct V_57 * F_32 ( int V_68 )
{
struct V_57 * V_57 ;
V_57 = F_33 ( V_68 ) ;
if ( ! V_57 )
return F_5 ( - V_69 ) ;
if ( V_57 -> V_70 != & V_37 )
goto V_71;
return V_57 ;
V_71:
F_34 ( V_57 ) ;
return F_5 ( - V_72 ) ;
}
struct V_73 * F_35 ( struct V_4 * V_4 )
{
return & F_2 ( V_4 ) -> V_8 ;
}
bool F_36 ( struct V_4 * V_4 )
{
return V_4 -> V_36 == & V_37 ;
}
