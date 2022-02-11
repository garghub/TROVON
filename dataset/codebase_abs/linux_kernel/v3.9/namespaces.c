static int F_1 ( const struct V_1 * V_1 )
{
return 1 ;
}
static char * F_2 ( struct V_1 * V_1 , char * V_2 , int V_3 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
const struct V_6 * V_7 = F_3 ( V_4 ) -> V_7 ;
return F_4 ( V_1 , V_2 , V_3 , L_1 ,
V_7 -> V_8 , V_4 -> V_9 ) ;
}
static struct V_1 * F_5 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const struct V_6 * V_7 )
{
struct V_1 * V_1 , * V_14 ;
struct V_4 * V_4 ;
struct V_15 * V_16 ;
struct V_17 V_18 = { . V_8 = L_2 , } ;
void * V_19 ;
V_19 = V_7 -> V_20 ( V_13 ) ;
if ( ! V_19 )
return F_6 ( - V_21 ) ;
V_1 = F_7 ( V_11 , & V_18 ) ;
if ( ! V_1 ) {
V_7 -> V_22 ( V_19 ) ;
return F_6 ( - V_23 ) ;
}
V_4 = F_8 ( V_11 , V_7 -> V_24 ( V_19 ) ) ;
if ( ! V_4 ) {
F_9 ( V_1 ) ;
V_7 -> V_22 ( V_19 ) ;
return F_6 ( - V_23 ) ;
}
V_16 = F_3 ( V_4 ) ;
if ( V_4 -> V_25 & V_26 ) {
V_4 -> V_27 = V_4 -> V_28 = V_4 -> V_29 = V_30 ;
V_4 -> V_31 = & V_32 ;
V_4 -> V_33 = V_34 | V_35 ;
V_4 -> V_36 = & V_37 ;
V_16 -> V_7 = V_7 ;
V_16 -> V_19 = V_19 ;
F_10 ( V_4 ) ;
} else {
V_7 -> V_22 ( V_19 ) ;
}
F_11 ( V_1 , & V_38 ) ;
V_14 = F_12 ( V_1 , V_4 ) ;
if ( V_14 ) {
F_9 ( V_1 ) ;
V_1 = V_14 ;
}
return V_1 ;
}
static void * F_13 ( struct V_1 * V_1 , struct V_39 * V_40 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
struct V_10 * V_11 = V_4 -> V_41 ;
struct V_15 * V_16 = F_3 ( V_4 ) ;
struct V_12 * V_13 ;
struct V_42 V_43 ;
void * error = F_6 ( - V_44 ) ;
V_13 = F_14 ( V_4 ) ;
if ( ! V_13 )
goto V_45;
if ( ! F_15 ( V_13 , V_46 ) )
goto V_47;
V_43 . V_1 = F_5 ( V_11 , V_13 , V_16 -> V_7 ) ;
if ( F_16 ( V_43 . V_1 ) ) {
error = F_17 ( V_43 . V_1 ) ;
goto V_47;
}
V_43 . V_48 = F_18 ( V_40 -> V_42 . V_48 ) ;
F_19 ( V_40 , & V_43 ) ;
error = NULL ;
V_47:
F_20 ( V_13 ) ;
V_45:
return error ;
}
static int F_21 ( struct V_1 * V_1 , char T_1 * V_2 , int V_3 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
struct V_15 * V_16 = F_3 ( V_4 ) ;
const struct V_6 * V_7 = V_16 -> V_7 ;
struct V_12 * V_13 ;
void * V_19 ;
char V_8 [ 50 ] ;
int V_49 = - V_44 ;
V_13 = F_14 ( V_4 ) ;
if ( ! V_13 )
goto V_45;
if ( ! F_15 ( V_13 , V_46 ) )
goto V_47;
V_49 = - V_21 ;
V_19 = V_7 -> V_20 ( V_13 ) ;
if ( ! V_19 )
goto V_47;
snprintf ( V_8 , sizeof( V_8 ) , L_3 , V_7 -> V_8 , V_7 -> V_24 ( V_19 ) ) ;
V_49 = strlen ( V_8 ) ;
if ( V_49 > V_3 )
V_49 = V_3 ;
if ( F_22 ( V_2 , V_8 , V_49 ) )
V_49 = - V_50 ;
V_7 -> V_22 ( V_19 ) ;
V_47:
F_20 ( V_13 ) ;
V_45:
return V_49 ;
}
static struct V_1 * F_23 ( struct V_4 * V_51 ,
struct V_1 * V_1 , struct V_12 * V_13 , const void * V_52 )
{
const struct V_6 * V_7 = V_52 ;
struct V_4 * V_4 ;
struct V_15 * V_16 ;
struct V_1 * error = F_6 ( - V_21 ) ;
V_4 = F_24 ( V_51 -> V_41 , V_13 ) ;
if ( ! V_4 )
goto V_45;
V_16 = F_3 ( V_4 ) ;
V_4 -> V_33 = V_53 | V_54 ;
V_4 -> V_31 = & V_55 ;
V_16 -> V_7 = V_7 ;
F_11 ( V_1 , & V_56 ) ;
F_25 ( V_1 , V_4 ) ;
if ( F_26 ( V_1 , 0 ) )
error = NULL ;
V_45:
return error ;
}
static int F_27 ( struct V_57 * V_58 , void * V_59 ,
T_2 V_60 , struct V_12 * V_13 ,
const struct V_6 * V_61 )
{
return F_28 ( V_58 , V_59 , V_60 ,
V_61 -> V_8 , strlen ( V_61 -> V_8 ) ,
F_23 , V_13 , V_61 ) ;
}
static int F_29 ( struct V_57 * V_58 , void * V_59 ,
T_2 V_60 )
{
int V_62 ;
struct V_1 * V_1 = V_58 -> V_63 . V_1 ;
struct V_4 * V_4 = V_1 -> V_5 ;
struct V_12 * V_13 = F_14 ( V_4 ) ;
const struct V_6 * * V_64 , * * V_65 ;
T_3 V_66 ;
int V_67 ;
V_67 = - V_21 ;
if ( ! V_13 )
goto V_68;
V_67 = 0 ;
V_62 = V_58 -> V_69 ;
switch ( V_62 ) {
case 0 :
V_66 = V_4 -> V_9 ;
if ( V_60 ( V_59 , L_4 , 1 , V_62 , V_66 , V_70 ) < 0 )
goto V_45;
V_62 ++ ;
V_58 -> V_69 ++ ;
case 1 :
V_66 = F_30 ( V_1 ) ;
if ( V_60 ( V_59 , L_5 , 2 , V_62 , V_66 , V_70 ) < 0 )
goto V_45;
V_62 ++ ;
V_58 -> V_69 ++ ;
default:
V_62 -= 2 ;
if ( V_62 >= F_31 ( V_71 ) ) {
V_67 = 1 ;
goto V_45;
}
V_64 = V_71 + V_62 ;
V_65 = & V_71 [ F_31 ( V_71 ) - 1 ] ;
while ( V_64 <= V_65 ) {
if ( F_27 ( V_58 , V_59 , V_60 ,
V_13 , * V_64 ) < 0 )
goto V_45;
V_58 -> V_69 ++ ;
V_64 ++ ;
}
}
V_67 = 1 ;
V_45:
F_20 ( V_13 ) ;
V_68:
return V_67 ;
}
static struct V_1 * F_32 ( struct V_4 * V_51 ,
struct V_1 * V_1 , unsigned int V_72 )
{
struct V_1 * error ;
struct V_12 * V_13 = F_14 ( V_51 ) ;
const struct V_6 * * V_64 , * * V_65 ;
unsigned int V_49 = V_1 -> V_73 . V_49 ;
error = F_6 ( - V_21 ) ;
if ( ! V_13 )
goto V_68;
V_65 = & V_71 [ F_31 ( V_71 ) ] ;
for ( V_64 = V_71 ; V_64 < V_65 ; V_64 ++ ) {
if ( strlen ( ( * V_64 ) -> V_8 ) != V_49 )
continue;
if ( ! memcmp ( V_1 -> V_73 . V_8 , ( * V_64 ) -> V_8 , V_49 ) )
break;
}
if ( V_64 == V_65 )
goto V_45;
error = F_23 ( V_51 , V_1 , V_13 , * V_64 ) ;
V_45:
F_20 ( V_13 ) ;
V_68:
return error ;
}
struct V_57 * F_33 ( int V_74 )
{
struct V_57 * V_57 ;
V_57 = F_34 ( V_74 ) ;
if ( ! V_57 )
return F_6 ( - V_75 ) ;
if ( V_57 -> V_76 != & V_37 )
goto V_77;
return V_57 ;
V_77:
F_35 ( V_57 ) ;
return F_6 ( - V_78 ) ;
}
bool F_36 ( struct V_4 * V_4 )
{
return V_4 -> V_36 == & V_37 ;
}
