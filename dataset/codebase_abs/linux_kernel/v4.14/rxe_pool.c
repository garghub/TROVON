static inline const char * F_1 ( struct V_1 * V_2 )
{
return V_3 [ V_2 -> type ] . V_4 ;
}
static inline struct V_5 * F_2 ( struct V_1 * V_2 )
{
return V_3 [ V_2 -> type ] . V_6 ;
}
int F_3 ( void )
{
int V_7 ;
int V_8 ;
T_1 V_9 ;
struct V_3 * type ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
type = & V_3 [ V_8 ] ;
V_9 = F_4 ( type -> V_9 , V_11 ) ;
type -> V_6 = F_5 ( type -> V_4 , V_9 ,
V_11 ,
V_12 , NULL ) ;
if ( ! type -> V_6 ) {
F_6 ( L_1 ,
type -> V_4 ) ;
V_7 = - V_13 ;
goto V_14;
}
}
return 0 ;
V_14:
while ( -- V_8 >= 0 ) {
F_7 ( type -> V_6 ) ;
type -> V_6 = NULL ;
}
return V_7 ;
}
void F_8 ( void )
{
int V_8 ;
struct V_3 * type ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
type = & V_3 [ V_8 ] ;
F_7 ( type -> V_6 ) ;
type -> V_6 = NULL ;
}
}
static int F_9 ( struct V_1 * V_2 , T_2 V_15 , T_2 V_16 )
{
int V_7 = 0 ;
T_1 V_9 ;
if ( ( V_15 - V_16 + 1 ) < V_2 -> V_17 ) {
F_10 ( L_2 ) ;
V_7 = - V_18 ;
goto V_19;
}
V_2 -> V_20 = V_15 ;
V_2 -> V_21 = V_16 ;
V_9 = F_11 ( V_15 - V_16 + 1 ) * sizeof( long ) ;
V_2 -> V_22 = F_12 ( V_9 , V_23 ) ;
if ( ! V_2 -> V_22 ) {
V_7 = - V_13 ;
goto V_19;
}
V_2 -> V_24 = V_9 ;
F_13 ( V_2 -> V_22 , V_15 - V_16 + 1 ) ;
V_19:
return V_7 ;
}
int F_14 (
struct V_25 * V_26 ,
struct V_1 * V_2 ,
enum V_27 type ,
unsigned int V_17 )
{
int V_7 = 0 ;
T_1 V_9 = V_3 [ type ] . V_9 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_26 = V_26 ;
V_2 -> type = type ;
V_2 -> V_17 = V_17 ;
V_2 -> V_28 = F_4 ( V_9 , V_11 ) ;
V_2 -> V_29 = V_3 [ type ] . V_29 ;
V_2 -> V_30 = V_31 ;
V_2 -> V_32 = V_3 [ type ] . V_32 ;
F_15 ( & V_2 -> V_33 , 0 ) ;
F_16 ( & V_2 -> V_34 ) ;
F_17 ( & V_2 -> V_35 ) ;
if ( V_3 [ type ] . V_29 & V_36 ) {
V_7 = F_9 ( V_2 ,
V_3 [ type ] . V_20 ,
V_3 [ type ] . V_21 ) ;
if ( V_7 )
goto V_19;
}
if ( V_3 [ type ] . V_29 & V_37 ) {
V_2 -> V_38 = V_3 [ type ] . V_38 ;
V_2 -> V_39 = V_3 [ type ] . V_39 ;
}
V_2 -> V_40 = V_41 ;
V_19:
return V_7 ;
}
static void F_18 ( struct V_42 * V_42 )
{
struct V_1 * V_2 = F_19 ( V_42 , struct V_1 , V_34 ) ;
V_2 -> V_40 = V_43 ;
F_20 ( V_2 -> V_22 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_34 , F_18 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
F_24 ( & V_2 -> V_35 , V_29 ) ;
V_2 -> V_40 = V_43 ;
if ( F_25 ( & V_2 -> V_33 ) > 0 )
F_10 ( L_3 ,
F_1 ( V_2 ) ) ;
F_26 ( & V_2 -> V_35 , V_29 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static T_2 F_27 ( struct V_1 * V_2 )
{
T_2 V_44 ;
T_2 V_45 = V_2 -> V_20 - V_2 -> V_21 + 1 ;
V_44 = F_28 ( V_2 -> V_22 , V_45 , V_2 -> V_46 ) ;
if ( V_44 >= V_45 )
V_44 = F_29 ( V_2 -> V_22 , V_45 ) ;
F_30 ( V_44 >= V_45 ) ;
F_31 ( V_44 , V_2 -> V_22 ) ;
V_2 -> V_46 = V_44 ;
return V_44 + V_2 -> V_21 ;
}
static void F_32 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
struct V_49 * * V_50 = & V_2 -> V_30 . V_49 ;
struct V_49 * V_51 = NULL ;
struct V_47 * V_52 ;
while ( * V_50 ) {
V_51 = * V_50 ;
V_52 = F_33 ( V_51 , struct V_47 , V_53 ) ;
if ( V_52 -> V_44 == V_48 -> V_44 ) {
F_10 ( L_4 ) ;
goto V_19;
}
if ( V_52 -> V_44 > V_48 -> V_44 )
V_50 = & ( * V_50 ) -> V_54 ;
else
V_50 = & ( * V_50 ) -> V_55 ;
}
F_34 ( & V_48 -> V_53 , V_51 , V_50 ) ;
F_35 ( & V_48 -> V_53 , & V_2 -> V_30 ) ;
V_19:
return;
}
static void F_36 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
struct V_49 * * V_50 = & V_2 -> V_30 . V_49 ;
struct V_49 * V_51 = NULL ;
struct V_47 * V_52 ;
int V_56 ;
while ( * V_50 ) {
V_51 = * V_50 ;
V_52 = F_33 ( V_51 , struct V_47 , V_53 ) ;
V_56 = memcmp ( ( V_57 * ) V_52 + V_2 -> V_38 ,
( V_57 * ) V_48 + V_2 -> V_38 , V_2 -> V_39 ) ;
if ( V_56 == 0 ) {
F_10 ( L_5 ) ;
goto V_19;
}
if ( V_56 > 0 )
V_50 = & ( * V_50 ) -> V_54 ;
else
V_50 = & ( * V_50 ) -> V_55 ;
}
F_34 ( & V_48 -> V_53 , V_51 , V_50 ) ;
F_35 ( & V_48 -> V_53 , & V_2 -> V_30 ) ;
V_19:
return;
}
void F_37 ( void * V_58 , void * V_59 )
{
struct V_47 * V_52 = V_58 ;
struct V_1 * V_2 = V_52 -> V_2 ;
unsigned long V_29 ;
F_24 ( & V_2 -> V_35 , V_29 ) ;
memcpy ( ( V_57 * ) V_52 + V_2 -> V_38 , V_59 , V_2 -> V_39 ) ;
F_36 ( V_2 , V_52 ) ;
F_26 ( & V_2 -> V_35 , V_29 ) ;
}
void F_38 ( void * V_58 )
{
struct V_47 * V_52 = V_58 ;
struct V_1 * V_2 = V_52 -> V_2 ;
unsigned long V_29 ;
F_24 ( & V_2 -> V_35 , V_29 ) ;
F_39 ( & V_52 -> V_53 , & V_2 -> V_30 ) ;
F_26 ( & V_2 -> V_35 , V_29 ) ;
}
void F_40 ( void * V_58 )
{
struct V_47 * V_52 = V_58 ;
struct V_1 * V_2 = V_52 -> V_2 ;
unsigned long V_29 ;
F_24 ( & V_2 -> V_35 , V_29 ) ;
V_52 -> V_44 = F_27 ( V_2 ) ;
F_32 ( V_2 , V_52 ) ;
F_26 ( & V_2 -> V_35 , V_29 ) ;
}
void F_41 ( void * V_58 )
{
struct V_47 * V_52 = V_58 ;
struct V_1 * V_2 = V_52 -> V_2 ;
unsigned long V_29 ;
F_24 ( & V_2 -> V_35 , V_29 ) ;
F_42 ( V_52 -> V_44 - V_2 -> V_21 , V_2 -> V_22 ) ;
F_39 ( & V_52 -> V_53 , & V_2 -> V_30 ) ;
F_26 ( & V_2 -> V_35 , V_29 ) ;
}
void * F_43 ( struct V_1 * V_2 )
{
struct V_47 * V_52 ;
unsigned long V_29 ;
F_44 ( ! ( V_2 -> V_29 & V_60 ) ) ;
F_24 ( & V_2 -> V_35 , V_29 ) ;
if ( V_2 -> V_40 != V_41 ) {
F_26 ( & V_2 -> V_35 , V_29 ) ;
return NULL ;
}
F_45 ( & V_2 -> V_34 ) ;
F_26 ( & V_2 -> V_35 , V_29 ) ;
F_45 ( & V_2 -> V_26 -> V_34 ) ;
if ( F_46 ( & V_2 -> V_33 ) > V_2 -> V_17 ) {
F_47 ( & V_2 -> V_33 ) ;
F_48 ( V_2 -> V_26 ) ;
F_21 ( V_2 ) ;
return NULL ;
}
V_52 = F_49 ( F_2 ( V_2 ) ,
( V_2 -> V_29 & V_60 ) ?
V_61 : V_23 ) ;
V_52 -> V_2 = V_2 ;
F_16 ( & V_52 -> V_34 ) ;
return V_52 ;
}
void F_50 ( struct V_42 * V_42 )
{
struct V_47 * V_52 =
F_19 ( V_42 , struct V_47 , V_34 ) ;
struct V_1 * V_2 = V_52 -> V_2 ;
if ( V_2 -> V_32 )
V_2 -> V_32 ( V_52 ) ;
F_51 ( F_2 ( V_2 ) , V_52 ) ;
F_47 ( & V_2 -> V_33 ) ;
F_48 ( V_2 -> V_26 ) ;
F_21 ( V_2 ) ;
}
void * F_52 ( struct V_1 * V_2 , T_2 V_44 )
{
struct V_49 * V_53 = NULL ;
struct V_47 * V_52 = NULL ;
unsigned long V_29 ;
F_24 ( & V_2 -> V_35 , V_29 ) ;
if ( V_2 -> V_40 != V_41 )
goto V_19;
V_53 = V_2 -> V_30 . V_49 ;
while ( V_53 ) {
V_52 = F_33 ( V_53 , struct V_47 , V_53 ) ;
if ( V_52 -> V_44 > V_44 )
V_53 = V_53 -> V_54 ;
else if ( V_52 -> V_44 < V_44 )
V_53 = V_53 -> V_55 ;
else
break;
}
if ( V_53 )
F_45 ( & V_52 -> V_34 ) ;
V_19:
F_26 ( & V_2 -> V_35 , V_29 ) ;
return V_53 ? V_52 : NULL ;
}
void * F_53 ( struct V_1 * V_2 , void * V_59 )
{
struct V_49 * V_53 = NULL ;
struct V_47 * V_52 = NULL ;
int V_56 ;
unsigned long V_29 ;
F_24 ( & V_2 -> V_35 , V_29 ) ;
if ( V_2 -> V_40 != V_41 )
goto V_19;
V_53 = V_2 -> V_30 . V_49 ;
while ( V_53 ) {
V_52 = F_33 ( V_53 , struct V_47 , V_53 ) ;
V_56 = memcmp ( ( V_57 * ) V_52 + V_2 -> V_38 ,
V_59 , V_2 -> V_39 ) ;
if ( V_56 > 0 )
V_53 = V_53 -> V_54 ;
else if ( V_56 < 0 )
V_53 = V_53 -> V_55 ;
else
break;
}
if ( V_53 )
F_45 ( & V_52 -> V_34 ) ;
V_19:
F_26 ( & V_2 -> V_35 , V_29 ) ;
return V_53 ? V_52 : NULL ;
}
