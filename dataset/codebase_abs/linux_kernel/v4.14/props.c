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
struct V_34 * V_35 = V_29 -> V_35 ;
int V_21 ;
char * V_36 = NULL ;
char * V_37 = NULL ;
int V_38 = 0 ;
int V_39 = 0 ;
while ( 1 ) {
struct V_40 V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
T_4 V_46 , V_47 , V_48 ;
int V_49 ;
const struct V_9 * V_13 ;
V_49 = V_31 -> V_50 [ 0 ] ;
V_45 = V_31 -> V_51 [ 0 ] ;
if ( V_49 >= F_18 ( V_45 ) ) {
V_21 = F_19 ( V_29 , V_31 ) ;
if ( V_21 < 0 )
goto V_52;
else if ( V_21 > 0 )
break;
continue;
}
F_20 ( V_45 , & V_41 , V_49 ) ;
if ( V_41 . V_32 != V_32 )
break;
if ( V_41 . type != V_53 )
break;
V_13 = F_6 ( V_41 . V_54 ) ;
if ( ! V_13 )
goto V_55;
V_43 = F_21 ( V_45 , V_49 , struct V_42 ) ;
V_47 = 0 ;
V_46 = F_22 ( V_45 , V_49 ) ;
while ( V_47 < V_46 ) {
T_4 V_56 = F_23 ( V_45 , V_43 ) ;
T_4 V_57 = F_24 ( V_45 , V_43 ) ;
unsigned long V_58 , V_59 ;
const struct V_4 * V_20 ;
V_48 = sizeof( * V_43 ) + V_56 + V_57 ;
V_58 = ( unsigned long ) ( V_43 + 1 ) ;
V_59 = V_58 + V_56 ;
if ( F_25 ( V_35 , V_45 ,
V_31 -> V_50 [ 0 ] , V_43 ) ) {
V_21 = - V_60 ;
goto V_52;
}
if ( V_56 <= V_22 ||
F_26 ( V_45 , V_61 ,
V_58 ,
V_22 ) )
goto V_62;
if ( V_56 >= V_38 ) {
F_27 ( V_36 ) ;
V_38 = V_56 + 1 ;
V_36 = F_28 ( V_38 , V_63 ) ;
if ( ! V_36 ) {
V_21 = - V_64 ;
goto V_52;
}
}
F_29 ( V_45 , V_36 , V_58 , V_56 ) ;
V_36 [ V_56 ] = '\0' ;
V_20 = F_9 ( V_36 , V_13 ) ;
if ( ! V_20 )
goto V_62;
if ( V_57 > V_39 ) {
F_27 ( V_37 ) ;
V_39 = V_57 ;
V_37 = F_28 ( V_57 , V_63 ) ;
if ( ! V_37 ) {
V_21 = - V_64 ;
goto V_52;
}
}
F_29 ( V_45 , V_37 , V_59 , V_57 ) ;
F_17 ( V_33 , V_20 , V_37 , V_57 ) ;
V_62:
V_47 += V_48 ;
V_43 = (struct V_42 * ) ( ( char * ) V_43 + V_48 ) ;
}
V_55:
V_31 -> V_50 [ 0 ] ++ ;
}
V_21 = 0 ;
V_52:
F_30 ( V_31 ) ;
F_27 ( V_36 ) ;
F_27 ( V_37 ) ;
return V_21 ;
}
static void F_31 ( void * V_33 ,
const struct V_4 * V_20 ,
const char * V_17 ,
T_3 V_65 )
{
struct V_16 * V_16 = V_33 ;
struct V_28 * V_29 = F_14 ( V_16 ) -> V_29 ;
int V_21 ;
V_21 = V_20 -> V_24 ( V_16 , V_17 , V_65 ) ;
if ( F_32 ( V_21 ) )
F_33 ( V_29 -> V_35 ,
L_1 ,
V_20 -> V_7 , F_34 ( F_14 ( V_16 ) ) ,
V_29 -> V_66 . V_32 , V_21 ) ;
else
F_13 ( V_26 , & F_14 ( V_16 ) -> V_27 ) ;
}
int F_35 ( struct V_16 * V_16 , struct V_30 * V_31 )
{
struct V_28 * V_29 = F_14 ( V_16 ) -> V_29 ;
T_2 V_67 = F_34 ( F_14 ( V_16 ) ) ;
int V_21 ;
V_21 = F_16 ( V_29 , V_31 , V_67 , F_31 , V_16 ) ;
return V_21 ;
}
static int F_36 ( struct V_14 * V_15 ,
struct V_16 * V_16 ,
struct V_16 * V_68 )
{
struct V_28 * V_29 = F_14 ( V_16 ) -> V_29 ;
struct V_34 * V_35 = V_29 -> V_35 ;
int V_21 ;
int V_1 ;
if ( ! F_37 ( V_26 ,
& F_14 ( V_68 ) -> V_27 ) )
return 0 ;
for ( V_1 = 0 ; V_1 < F_3 ( V_3 ) ; V_1 ++ ) {
const struct V_4 * V_6 = & V_3 [ V_1 ] ;
const char * V_17 ;
T_2 V_69 ;
if ( ! V_6 -> V_70 )
continue;
V_17 = V_6 -> V_71 ( V_68 ) ;
if ( ! V_17 )
continue;
V_69 = F_38 ( V_35 , 1 ) ;
V_21 = F_39 ( V_29 , V_15 -> V_72 ,
V_69 , V_73 ) ;
if ( V_21 )
goto V_52;
V_21 = F_11 ( V_15 , V_16 , V_6 -> V_7 ,
V_17 , strlen ( V_17 ) , 0 ) ;
F_40 ( V_35 , V_15 -> V_72 , V_69 ) ;
if ( V_21 )
goto V_52;
}
V_21 = 0 ;
V_52:
return V_21 ;
}
int F_41 ( struct V_14 * V_15 ,
struct V_16 * V_16 ,
struct V_16 * V_74 )
{
if ( ! V_74 )
return 0 ;
return F_36 ( V_15 , V_16 , V_74 ) ;
}
int F_42 ( struct V_14 * V_15 ,
struct V_28 * V_29 ,
struct V_28 * V_75 )
{
struct V_76 * V_77 = V_29 -> V_35 -> V_77 ;
struct V_40 V_41 ;
struct V_16 * V_78 , * V_79 ;
int V_21 ;
V_41 . V_32 = V_80 ;
V_41 . type = V_81 ;
V_41 . V_54 = 0 ;
V_78 = F_43 ( V_77 , & V_41 , V_75 , NULL ) ;
if ( F_44 ( V_78 ) )
return F_45 ( V_78 ) ;
V_79 = F_43 ( V_77 , & V_41 , V_29 , NULL ) ;
if ( F_44 ( V_79 ) ) {
F_46 ( V_78 ) ;
return F_45 ( V_79 ) ;
}
V_21 = F_36 ( V_15 , V_79 , V_78 ) ;
F_46 ( V_79 ) ;
F_46 ( V_78 ) ;
return V_21 ;
}
static int F_47 ( const char * V_17 , T_3 V_65 )
{
if ( ! strncmp ( L_2 , V_17 , V_65 ) )
return 0 ;
else if ( ! strncmp ( L_3 , V_17 , V_65 ) )
return 0 ;
else if ( ! strncmp ( L_4 , V_17 , V_65 ) )
return 0 ;
return - V_23 ;
}
static int F_48 ( struct V_16 * V_16 ,
const char * V_17 ,
T_3 V_65 )
{
int type ;
if ( V_65 == 0 ) {
F_14 ( V_16 ) -> V_19 |= V_82 ;
F_14 ( V_16 ) -> V_19 &= ~ V_83 ;
F_14 ( V_16 ) -> V_84 = V_85 ;
return 0 ;
}
if ( ! strncmp ( L_2 , V_17 , 3 ) )
type = V_86 ;
else if ( ! strncmp ( L_3 , V_17 , 4 ) )
type = V_87 ;
else if ( ! strncmp ( L_4 , V_17 , V_65 ) )
type = V_88 ;
else
return - V_23 ;
F_14 ( V_16 ) -> V_19 &= ~ V_82 ;
F_14 ( V_16 ) -> V_19 |= V_83 ;
F_14 ( V_16 ) -> V_84 = type ;
return 0 ;
}
static const char * F_49 ( struct V_16 * V_16 )
{
switch ( F_14 ( V_16 ) -> V_84 ) {
case V_87 :
return L_3 ;
case V_86 :
return L_2 ;
case V_88 :
return L_4 ;
}
return NULL ;
}
