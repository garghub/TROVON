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
struct V_1 * V_42 ;
void * error = F_6 ( - V_43 ) ;
V_13 = F_14 ( V_4 ) ;
if ( ! V_13 )
goto V_44;
if ( ! F_15 ( V_13 , V_45 ) )
goto V_46;
V_42 = F_5 ( V_11 , V_13 , V_16 -> V_7 ) ;
if ( F_16 ( V_42 ) ) {
error = F_17 ( V_42 ) ;
goto V_46;
}
F_9 ( V_40 -> V_47 . V_1 ) ;
V_40 -> V_47 . V_1 = V_42 ;
error = NULL ;
V_46:
F_18 ( V_13 ) ;
V_44:
return error ;
}
static int F_19 ( struct V_1 * V_1 , char T_1 * V_2 , int V_3 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
struct V_15 * V_16 = F_3 ( V_4 ) ;
const struct V_6 * V_7 = V_16 -> V_7 ;
struct V_12 * V_13 ;
void * V_19 ;
char V_8 [ 50 ] ;
int V_48 = - V_43 ;
V_13 = F_14 ( V_4 ) ;
if ( ! V_13 )
goto V_44;
if ( ! F_15 ( V_13 , V_45 ) )
goto V_46;
V_48 = - V_21 ;
V_19 = V_7 -> V_20 ( V_13 ) ;
if ( ! V_19 )
goto V_46;
snprintf ( V_8 , sizeof( V_8 ) , L_3 , V_7 -> V_8 , V_7 -> V_24 ( V_19 ) ) ;
V_48 = strlen ( V_8 ) ;
if ( V_48 > V_3 )
V_48 = V_3 ;
if ( F_20 ( V_2 , V_8 , V_48 ) )
V_48 = - V_49 ;
V_7 -> V_22 ( V_19 ) ;
V_46:
F_18 ( V_13 ) ;
V_44:
return V_48 ;
}
static struct V_1 * F_21 ( struct V_4 * V_50 ,
struct V_1 * V_1 , struct V_12 * V_13 , const void * V_51 )
{
const struct V_6 * V_7 = V_51 ;
struct V_4 * V_4 ;
struct V_15 * V_16 ;
struct V_1 * error = F_6 ( - V_21 ) ;
V_4 = F_22 ( V_50 -> V_41 , V_13 ) ;
if ( ! V_4 )
goto V_44;
V_16 = F_3 ( V_4 ) ;
V_4 -> V_33 = V_52 | V_53 ;
V_4 -> V_31 = & V_54 ;
V_16 -> V_7 = V_7 ;
F_11 ( V_1 , & V_55 ) ;
F_23 ( V_1 , V_4 ) ;
if ( F_24 ( V_1 , 0 ) )
error = NULL ;
V_44:
return error ;
}
static int F_25 ( struct V_56 * V_57 , void * V_58 ,
T_2 V_59 , struct V_12 * V_13 ,
const struct V_6 * V_60 )
{
return F_26 ( V_57 , V_58 , V_59 ,
V_60 -> V_8 , strlen ( V_60 -> V_8 ) ,
F_21 , V_13 , V_60 ) ;
}
static int F_27 ( struct V_56 * V_57 , void * V_58 ,
T_2 V_59 )
{
int V_61 ;
struct V_1 * V_1 = V_57 -> V_62 . V_1 ;
struct V_4 * V_4 = V_1 -> V_5 ;
struct V_12 * V_13 = F_14 ( V_4 ) ;
const struct V_6 * * V_63 , * * V_64 ;
T_3 V_65 ;
int V_66 ;
V_66 = - V_21 ;
if ( ! V_13 )
goto V_67;
V_66 = 0 ;
V_61 = V_57 -> V_68 ;
switch ( V_61 ) {
case 0 :
V_65 = V_4 -> V_9 ;
if ( V_59 ( V_58 , L_4 , 1 , V_61 , V_65 , V_69 ) < 0 )
goto V_44;
V_61 ++ ;
V_57 -> V_68 ++ ;
case 1 :
V_65 = F_28 ( V_1 ) ;
if ( V_59 ( V_58 , L_5 , 2 , V_61 , V_65 , V_69 ) < 0 )
goto V_44;
V_61 ++ ;
V_57 -> V_68 ++ ;
default:
V_61 -= 2 ;
if ( V_61 >= F_29 ( V_70 ) ) {
V_66 = 1 ;
goto V_44;
}
V_63 = V_70 + V_61 ;
V_64 = & V_70 [ F_29 ( V_70 ) - 1 ] ;
while ( V_63 <= V_64 ) {
if ( F_25 ( V_57 , V_58 , V_59 ,
V_13 , * V_63 ) < 0 )
goto V_44;
V_57 -> V_68 ++ ;
V_63 ++ ;
}
}
V_66 = 1 ;
V_44:
F_18 ( V_13 ) ;
V_67:
return V_66 ;
}
static struct V_1 * F_30 ( struct V_4 * V_50 ,
struct V_1 * V_1 , unsigned int V_71 )
{
struct V_1 * error ;
struct V_12 * V_13 = F_14 ( V_50 ) ;
const struct V_6 * * V_63 , * * V_64 ;
unsigned int V_48 = V_1 -> V_72 . V_48 ;
error = F_6 ( - V_21 ) ;
if ( ! V_13 )
goto V_67;
V_64 = & V_70 [ F_29 ( V_70 ) ] ;
for ( V_63 = V_70 ; V_63 < V_64 ; V_63 ++ ) {
if ( strlen ( ( * V_63 ) -> V_8 ) != V_48 )
continue;
if ( ! memcmp ( V_1 -> V_72 . V_8 , ( * V_63 ) -> V_8 , V_48 ) )
break;
}
if ( V_63 == V_64 )
goto V_44;
error = F_21 ( V_50 , V_1 , V_13 , * V_63 ) ;
V_44:
F_18 ( V_13 ) ;
V_67:
return error ;
}
struct V_56 * F_31 ( int V_73 )
{
struct V_56 * V_56 ;
V_56 = F_32 ( V_73 ) ;
if ( ! V_56 )
return F_6 ( - V_74 ) ;
if ( V_56 -> V_75 != & V_37 )
goto V_76;
return V_56 ;
V_76:
F_33 ( V_56 ) ;
return F_6 ( - V_77 ) ;
}
bool F_34 ( struct V_4 * V_4 )
{
return V_4 -> V_36 == & V_37 ;
}
