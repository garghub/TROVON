void T_1 F_1 ( void )
{
int V_1 ;
F_2 ( V_2 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_3 ) ; V_1 ++ ) {
struct V_4 * V_5 = & V_3 [ V_1 ] ;
T_2 V_6 = F_4 ( V_5 -> V_7 , strlen ( V_5 -> V_7 ) ) ;
F_5 ( V_2 , & V_5 -> V_8 , V_6 ) ;
}
}
static const struct V_9 * F_6 ( const T_2 V_10 )
{
struct V_9 * V_6 ;
V_6 = & V_2 [ F_7 ( V_10 , V_11 ) ] ;
if ( F_8 ( V_6 ) )
return NULL ;
return V_6 ;
}
static const struct V_4 *
F_9 ( const char * V_12 ,
const struct V_9 * V_13 )
{
struct V_4 * V_6 ;
if ( ! V_13 ) {
T_2 V_10 = F_4 ( V_12 , strlen ( V_12 ) ) ;
V_13 = F_6 ( V_10 ) ;
if ( ! V_13 )
return NULL ;
}
F_10 (h, handlers, node)
if ( ! strcmp ( V_6 -> V_7 , V_12 ) )
return V_6 ;
return NULL ;
}
static int F_11 ( struct V_14 * V_15 ,
struct V_16 * V_16 ,
const char * V_12 ,
const char * V_17 ,
T_3 V_18 ,
int V_19 )
{
const struct V_4 * V_20 ;
int V_21 ;
if ( strlen ( V_12 ) <= V_22 )
return - V_23 ;
V_20 = F_9 ( V_12 , NULL ) ;
if ( ! V_20 )
return - V_23 ;
if ( V_18 == 0 ) {
V_21 = F_12 ( V_15 , V_16 , V_20 -> V_7 ,
NULL , 0 , V_19 ) ;
if ( V_21 )
return V_21 ;
V_21 = V_20 -> V_24 ( V_16 , NULL , 0 ) ;
ASSERT ( V_21 == 0 ) ;
return V_21 ;
}
V_21 = V_20 -> V_25 ( V_17 , V_18 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_15 , V_16 , V_20 -> V_7 ,
V_17 , V_18 , V_19 ) ;
if ( V_21 )
return V_21 ;
V_21 = V_20 -> V_24 ( V_16 , V_17 , V_18 ) ;
if ( V_21 ) {
F_12 ( V_15 , V_16 , V_20 -> V_7 ,
NULL , 0 , V_19 ) ;
return V_21 ;
}
F_13 ( V_26 , & F_14 ( V_16 ) -> V_27 ) ;
return 0 ;
}
int F_15 ( struct V_16 * V_16 ,
const char * V_12 ,
const char * V_17 ,
T_3 V_18 ,
int V_19 )
{
return F_11 ( NULL , V_16 , V_12 , V_17 , V_18 , V_19 ) ;
}
static int F_16 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
T_2 V_32 ,
void (* F_17)( void * ,
const struct V_4 * ,
const char * ,
T_3 ) ,
void * V_33 )
{
int V_21 ;
char * V_34 = NULL ;
char * V_35 = NULL ;
int V_36 = 0 ;
int V_37 = 0 ;
while ( 1 ) {
struct V_38 V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
T_4 V_44 , V_45 , V_46 ;
int V_47 ;
const struct V_9 * V_13 ;
V_47 = V_31 -> V_48 [ 0 ] ;
V_43 = V_31 -> V_49 [ 0 ] ;
if ( V_47 >= F_18 ( V_43 ) ) {
V_21 = F_19 ( V_29 , V_31 ) ;
if ( V_21 < 0 )
goto V_50;
else if ( V_21 > 0 )
break;
continue;
}
F_20 ( V_43 , & V_39 , V_47 ) ;
if ( V_39 . V_32 != V_32 )
break;
if ( V_39 . type != V_51 )
break;
V_13 = F_6 ( V_39 . V_52 ) ;
if ( ! V_13 )
goto V_53;
V_41 = F_21 ( V_43 , V_47 , struct V_40 ) ;
V_45 = 0 ;
V_44 = F_22 ( V_43 , V_47 ) ;
while ( V_45 < V_44 ) {
T_4 V_54 = F_23 ( V_43 , V_41 ) ;
T_4 V_55 = F_24 ( V_43 , V_41 ) ;
unsigned long V_56 , V_57 ;
const struct V_4 * V_20 ;
V_46 = sizeof( * V_41 ) + V_54 + V_55 ;
V_56 = ( unsigned long ) ( V_41 + 1 ) ;
V_57 = V_56 + V_54 ;
if ( V_54 <= V_22 ||
F_25 ( V_43 , V_58 ,
V_56 ,
V_22 ) )
goto V_59;
if ( V_54 >= V_36 ) {
F_26 ( V_34 ) ;
V_36 = V_54 + 1 ;
V_34 = F_27 ( V_36 , V_60 ) ;
if ( ! V_34 ) {
V_21 = - V_61 ;
goto V_50;
}
}
F_28 ( V_43 , V_34 , V_56 , V_54 ) ;
V_34 [ V_54 ] = '\0' ;
V_20 = F_9 ( V_34 , V_13 ) ;
if ( ! V_20 )
goto V_59;
if ( V_55 > V_37 ) {
F_26 ( V_35 ) ;
V_37 = V_55 ;
V_35 = F_27 ( V_55 , V_60 ) ;
if ( ! V_35 ) {
V_21 = - V_61 ;
goto V_50;
}
}
F_28 ( V_43 , V_35 , V_57 , V_55 ) ;
F_17 ( V_33 , V_20 , V_35 , V_55 ) ;
V_59:
V_45 += V_46 ;
V_41 = (struct V_40 * ) ( ( char * ) V_41 + V_46 ) ;
}
V_53:
V_31 -> V_48 [ 0 ] ++ ;
}
V_21 = 0 ;
V_50:
F_29 ( V_31 ) ;
F_26 ( V_34 ) ;
F_26 ( V_35 ) ;
return V_21 ;
}
static void F_30 ( void * V_33 ,
const struct V_4 * V_20 ,
const char * V_17 ,
T_3 V_62 )
{
struct V_16 * V_16 = V_33 ;
struct V_28 * V_29 = F_14 ( V_16 ) -> V_29 ;
int V_21 ;
V_21 = V_20 -> V_24 ( V_16 , V_17 , V_62 ) ;
if ( F_31 ( V_21 ) )
F_32 ( V_29 -> V_63 ,
L_1 ,
V_20 -> V_7 , F_33 ( V_16 ) ,
V_29 -> V_64 . V_32 , V_21 ) ;
else
F_13 ( V_26 , & F_14 ( V_16 ) -> V_27 ) ;
}
int F_34 ( struct V_16 * V_16 , struct V_30 * V_31 )
{
struct V_28 * V_29 = F_14 ( V_16 ) -> V_29 ;
T_2 V_65 = F_33 ( V_16 ) ;
int V_21 ;
V_21 = F_16 ( V_29 , V_31 , V_65 , F_30 , V_16 ) ;
return V_21 ;
}
static int F_35 ( struct V_14 * V_15 ,
struct V_16 * V_16 ,
struct V_16 * V_66 )
{
struct V_28 * V_29 = F_14 ( V_16 ) -> V_29 ;
int V_21 ;
int V_1 ;
if ( ! F_36 ( V_26 ,
& F_14 ( V_66 ) -> V_27 ) )
return 0 ;
for ( V_1 = 0 ; V_1 < F_3 ( V_3 ) ; V_1 ++ ) {
const struct V_4 * V_6 = & V_3 [ V_1 ] ;
const char * V_17 ;
T_2 V_67 ;
if ( ! V_6 -> V_68 )
continue;
V_17 = V_6 -> V_69 ( V_66 ) ;
if ( ! V_17 )
continue;
V_67 = F_37 ( V_29 , 1 ) ;
V_21 = F_38 ( V_29 , V_15 -> V_70 ,
V_67 , V_71 ) ;
if ( V_21 )
goto V_50;
V_21 = F_11 ( V_15 , V_16 , V_6 -> V_7 ,
V_17 , strlen ( V_17 ) , 0 ) ;
F_39 ( V_29 , V_15 -> V_70 , V_67 ) ;
if ( V_21 )
goto V_50;
}
V_21 = 0 ;
V_50:
return V_21 ;
}
int F_40 ( struct V_14 * V_15 ,
struct V_16 * V_16 ,
struct V_16 * V_72 )
{
if ( ! V_72 )
return 0 ;
return F_35 ( V_15 , V_16 , V_72 ) ;
}
int F_41 ( struct V_14 * V_15 ,
struct V_28 * V_29 ,
struct V_28 * V_73 )
{
struct V_74 * V_75 = V_29 -> V_63 -> V_75 ;
struct V_38 V_39 ;
struct V_16 * V_76 , * V_77 ;
int V_21 ;
V_39 . V_32 = V_78 ;
V_39 . type = V_79 ;
V_39 . V_52 = 0 ;
V_76 = F_42 ( V_75 , & V_39 , V_73 , NULL ) ;
if ( F_43 ( V_76 ) )
return F_44 ( V_76 ) ;
V_77 = F_42 ( V_75 , & V_39 , V_29 , NULL ) ;
if ( F_43 ( V_77 ) ) {
F_45 ( V_76 ) ;
return F_44 ( V_77 ) ;
}
V_21 = F_35 ( V_15 , V_77 , V_76 ) ;
F_45 ( V_77 ) ;
F_45 ( V_76 ) ;
return V_21 ;
}
static int F_46 ( const char * V_17 , T_3 V_62 )
{
if ( ! strncmp ( L_2 , V_17 , V_62 ) )
return 0 ;
else if ( ! strncmp ( L_3 , V_17 , V_62 ) )
return 0 ;
return - V_23 ;
}
static int F_47 ( struct V_16 * V_16 ,
const char * V_17 ,
T_3 V_62 )
{
int type ;
if ( V_62 == 0 ) {
F_14 ( V_16 ) -> V_19 |= V_80 ;
F_14 ( V_16 ) -> V_19 &= ~ V_81 ;
F_14 ( V_16 ) -> V_82 = V_83 ;
return 0 ;
}
if ( ! strncmp ( L_2 , V_17 , V_62 ) )
type = V_84 ;
else if ( ! strncmp ( L_3 , V_17 , V_62 ) )
type = V_85 ;
else
return - V_23 ;
F_14 ( V_16 ) -> V_19 &= ~ V_80 ;
F_14 ( V_16 ) -> V_19 |= V_81 ;
F_14 ( V_16 ) -> V_82 = type ;
return 0 ;
}
static const char * F_48 ( struct V_16 * V_16 )
{
switch ( F_14 ( V_16 ) -> V_82 ) {
case V_85 :
return L_3 ;
case V_84 :
return L_2 ;
}
return NULL ;
}
