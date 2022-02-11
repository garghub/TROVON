void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
F_2 ( V_3 ) ;
for ( V_2 = & V_4 [ 0 ] ; V_2 -> V_5 ; V_2 ++ ) {
T_2 V_6 = F_3 ( V_2 -> V_5 , strlen ( V_2 -> V_5 ) ) ;
F_4 ( V_3 , & V_2 -> V_7 , V_6 ) ;
}
}
static const struct V_8 * F_5 ( const T_2 V_9 )
{
struct V_8 * V_6 ;
V_6 = & V_3 [ F_6 ( V_9 , V_10 ) ] ;
if ( F_7 ( V_6 ) )
return NULL ;
return V_6 ;
}
static const struct V_1 *
F_8 ( const char * V_11 ,
const struct V_8 * V_12 )
{
struct V_1 * V_6 ;
if ( ! V_12 ) {
T_2 V_9 = F_3 ( V_11 , strlen ( V_11 ) ) ;
V_12 = F_5 ( V_9 ) ;
if ( ! V_12 )
return NULL ;
}
F_9 (h, handlers, node)
if ( ! strcmp ( V_6 -> V_5 , V_11 ) )
return V_6 ;
return NULL ;
}
static int F_10 ( struct V_13 * V_14 ,
struct V_15 * V_15 ,
const char * V_11 ,
const char * V_16 ,
T_3 V_17 ,
int V_18 )
{
const struct V_1 * V_19 ;
int V_20 ;
if ( strlen ( V_11 ) <= V_21 )
return - V_22 ;
V_19 = F_8 ( V_11 , NULL ) ;
if ( ! V_19 )
return - V_22 ;
if ( V_17 == 0 ) {
V_20 = F_11 ( V_14 , V_15 , V_19 -> V_5 ,
NULL , 0 , V_18 ) ;
if ( V_20 )
return V_20 ;
V_20 = V_19 -> V_23 ( V_15 , NULL , 0 ) ;
ASSERT ( V_20 == 0 ) ;
return V_20 ;
}
V_20 = V_19 -> V_24 ( V_16 , V_17 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_11 ( V_14 , V_15 , V_19 -> V_5 ,
V_16 , V_17 , V_18 ) ;
if ( V_20 )
return V_20 ;
V_20 = V_19 -> V_23 ( V_15 , V_16 , V_17 ) ;
if ( V_20 ) {
F_11 ( V_14 , V_15 , V_19 -> V_5 ,
NULL , 0 , V_18 ) ;
return V_20 ;
}
F_12 ( V_25 , & F_13 ( V_15 ) -> V_26 ) ;
return 0 ;
}
int F_14 ( struct V_15 * V_15 ,
const char * V_11 ,
const char * V_16 ,
T_3 V_17 ,
int V_18 )
{
return F_10 ( NULL , V_15 , V_11 , V_16 , V_17 , V_18 ) ;
}
static int F_15 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
T_2 V_31 ,
void (* F_16)( void * ,
const struct V_1 * ,
const char * ,
T_3 ) ,
void * V_32 )
{
int V_20 ;
char * V_33 = NULL ;
char * V_34 = NULL ;
int V_35 = 0 ;
int V_36 = 0 ;
while ( 1 ) {
struct V_37 V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
T_4 V_43 , V_44 , V_45 ;
int V_46 ;
const struct V_8 * V_12 ;
V_46 = V_30 -> V_47 [ 0 ] ;
V_42 = V_30 -> V_48 [ 0 ] ;
if ( V_46 >= F_17 ( V_42 ) ) {
V_20 = F_18 ( V_28 , V_30 ) ;
if ( V_20 < 0 )
goto V_49;
else if ( V_20 > 0 )
break;
continue;
}
F_19 ( V_42 , & V_38 , V_46 ) ;
if ( V_38 . V_31 != V_31 )
break;
if ( V_38 . type != V_50 )
break;
V_12 = F_5 ( V_38 . V_51 ) ;
if ( ! V_12 )
goto V_52;
V_40 = F_20 ( V_42 , V_46 , struct V_39 ) ;
V_44 = 0 ;
V_43 = F_21 ( V_42 , V_46 ) ;
while ( V_44 < V_43 ) {
T_4 V_53 = F_22 ( V_42 , V_40 ) ;
T_4 V_54 = F_23 ( V_42 , V_40 ) ;
unsigned long V_55 , V_56 ;
const struct V_1 * V_19 ;
V_45 = sizeof( * V_40 ) + V_53 + V_54 ;
V_55 = ( unsigned long ) ( V_40 + 1 ) ;
V_56 = V_55 + V_53 ;
if ( V_53 <= V_21 ||
F_24 ( V_42 , V_57 ,
V_55 ,
V_21 ) )
goto V_58;
if ( V_53 >= V_35 ) {
F_25 ( V_33 ) ;
V_35 = V_53 + 1 ;
V_33 = F_26 ( V_35 , V_59 ) ;
if ( ! V_33 ) {
V_20 = - V_60 ;
goto V_49;
}
}
F_27 ( V_42 , V_33 , V_55 , V_53 ) ;
V_33 [ V_53 ] = '\0' ;
V_19 = F_8 ( V_33 , V_12 ) ;
if ( ! V_19 )
goto V_58;
if ( V_54 > V_36 ) {
F_25 ( V_34 ) ;
V_36 = V_54 ;
V_34 = F_26 ( V_54 , V_59 ) ;
if ( ! V_34 ) {
V_20 = - V_60 ;
goto V_49;
}
}
F_27 ( V_42 , V_34 , V_56 , V_54 ) ;
F_16 ( V_32 , V_19 , V_34 , V_54 ) ;
V_58:
V_44 += V_45 ;
V_40 = (struct V_39 * ) ( ( char * ) V_40 + V_45 ) ;
}
V_52:
V_30 -> V_47 [ 0 ] ++ ;
}
V_20 = 0 ;
V_49:
F_28 ( V_30 ) ;
F_25 ( V_33 ) ;
F_25 ( V_34 ) ;
return V_20 ;
}
static void F_29 ( void * V_32 ,
const struct V_1 * V_19 ,
const char * V_16 ,
T_3 V_61 )
{
struct V_15 * V_15 = V_32 ;
struct V_27 * V_28 = F_13 ( V_15 ) -> V_28 ;
int V_20 ;
V_20 = V_19 -> V_23 ( V_15 , V_16 , V_61 ) ;
if ( F_30 ( V_20 ) )
F_31 ( V_28 -> V_62 ,
L_1 ,
V_19 -> V_5 , F_32 ( V_15 ) ,
V_28 -> V_63 . V_31 , V_20 ) ;
else
F_12 ( V_25 , & F_13 ( V_15 ) -> V_26 ) ;
}
int F_33 ( struct V_15 * V_15 , struct V_29 * V_30 )
{
struct V_27 * V_28 = F_13 ( V_15 ) -> V_28 ;
T_2 V_64 = F_32 ( V_15 ) ;
int V_20 ;
V_20 = F_15 ( V_28 , V_30 , V_64 , F_29 , V_15 ) ;
return V_20 ;
}
static int F_34 ( struct V_13 * V_14 ,
struct V_15 * V_15 ,
struct V_15 * V_65 )
{
const struct V_1 * V_6 ;
struct V_27 * V_28 = F_13 ( V_15 ) -> V_28 ;
int V_20 ;
if ( ! F_35 ( V_25 ,
& F_13 ( V_65 ) -> V_26 ) )
return 0 ;
for ( V_6 = & V_4 [ 0 ] ; V_6 -> V_5 ; V_6 ++ ) {
const char * V_16 ;
T_2 V_66 ;
if ( ! V_6 -> V_67 )
continue;
V_16 = V_6 -> V_68 ( V_65 ) ;
if ( ! V_16 )
continue;
V_66 = F_36 ( V_28 , 1 ) ;
V_20 = F_37 ( V_28 , V_14 -> V_69 ,
V_66 , V_70 ) ;
if ( V_20 )
goto V_49;
V_20 = F_10 ( V_14 , V_15 , V_6 -> V_5 ,
V_16 , strlen ( V_16 ) , 0 ) ;
F_38 ( V_28 , V_14 -> V_69 , V_66 ) ;
if ( V_20 )
goto V_49;
}
V_20 = 0 ;
V_49:
return V_20 ;
}
int F_39 ( struct V_13 * V_14 ,
struct V_15 * V_15 ,
struct V_15 * V_71 )
{
if ( ! V_71 )
return 0 ;
return F_34 ( V_14 , V_15 , V_71 ) ;
}
int F_40 ( struct V_13 * V_14 ,
struct V_27 * V_28 ,
struct V_27 * V_72 )
{
struct V_37 V_38 ;
struct V_15 * V_73 , * V_74 ;
int V_20 ;
V_38 . V_31 = V_75 ;
V_38 . type = V_76 ;
V_38 . V_51 = 0 ;
V_73 = F_41 ( V_72 -> V_62 -> V_77 , & V_38 ,
V_72 , NULL ) ;
if ( F_42 ( V_73 ) )
return F_43 ( V_73 ) ;
V_74 = F_41 ( V_28 -> V_62 -> V_77 , & V_38 , V_28 , NULL ) ;
if ( F_42 ( V_74 ) ) {
F_44 ( V_73 ) ;
return F_43 ( V_74 ) ;
}
V_20 = F_34 ( V_14 , V_74 , V_73 ) ;
F_44 ( V_74 ) ;
F_44 ( V_73 ) ;
return V_20 ;
}
static int F_45 ( const char * V_16 , T_3 V_61 )
{
if ( ! strncmp ( L_2 , V_16 , V_61 ) )
return 0 ;
else if ( ! strncmp ( L_3 , V_16 , V_61 ) )
return 0 ;
return - V_22 ;
}
static int F_46 ( struct V_15 * V_15 ,
const char * V_16 ,
T_3 V_61 )
{
int type ;
if ( V_61 == 0 ) {
F_13 ( V_15 ) -> V_18 |= V_78 ;
F_13 ( V_15 ) -> V_18 &= ~ V_79 ;
F_13 ( V_15 ) -> V_80 = V_81 ;
return 0 ;
}
if ( ! strncmp ( L_2 , V_16 , V_61 ) )
type = V_82 ;
else if ( ! strncmp ( L_3 , V_16 , V_61 ) )
type = V_83 ;
else
return - V_22 ;
F_13 ( V_15 ) -> V_18 &= ~ V_78 ;
F_13 ( V_15 ) -> V_18 |= V_79 ;
F_13 ( V_15 ) -> V_80 = type ;
return 0 ;
}
static const char * F_47 ( struct V_15 * V_15 )
{
switch ( F_13 ( V_15 ) -> V_80 ) {
case V_83 :
return L_3 ;
case V_82 :
return L_2 ;
}
return NULL ;
}
