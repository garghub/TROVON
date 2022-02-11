static inline char * F_1 ( struct V_1 * V_2 )
{
return V_3 [ V_2 -> type ] . V_4 ;
}
static inline struct V_5 * F_2 ( struct V_1 * V_2 )
{
return V_3 [ V_2 -> type ] . V_6 ;
}
static inline enum V_7 F_3 ( void * V_8 )
{
struct V_9 * V_10 = V_8 ;
return V_10 -> V_2 -> type ;
}
int F_4 ( void )
{
int V_11 ;
int V_12 ;
T_1 V_13 ;
struct V_3 * type ;
for ( V_12 = 0 ; V_12 < V_14 ; V_12 ++ ) {
type = & V_3 [ V_12 ] ;
V_13 = F_5 ( type -> V_13 , V_15 ) ;
type -> V_6 = F_6 ( type -> V_4 , V_13 ,
V_15 ,
V_16 , NULL ) ;
if ( ! type -> V_6 ) {
F_7 ( L_1 ,
type -> V_4 ) ;
V_11 = - V_17 ;
goto V_18;
}
}
return 0 ;
V_18:
while ( -- V_12 >= 0 ) {
F_8 ( type -> V_6 ) ;
type -> V_6 = NULL ;
}
return V_11 ;
}
void F_9 ( void )
{
int V_12 ;
struct V_3 * type ;
for ( V_12 = 0 ; V_12 < V_14 ; V_12 ++ ) {
type = & V_3 [ V_12 ] ;
F_8 ( type -> V_6 ) ;
type -> V_6 = NULL ;
}
}
static int F_10 ( struct V_1 * V_2 , T_2 V_19 , T_2 V_20 )
{
int V_11 = 0 ;
T_1 V_13 ;
if ( ( V_19 - V_20 + 1 ) < V_2 -> V_21 ) {
F_11 ( L_2 ) ;
V_11 = - V_22 ;
goto V_23;
}
V_2 -> V_24 = V_19 ;
V_2 -> V_25 = V_20 ;
V_13 = F_12 ( V_19 - V_20 + 1 ) * sizeof( long ) ;
V_2 -> V_26 = F_13 ( V_13 , V_27 ) ;
if ( ! V_2 -> V_26 ) {
F_11 ( L_3 ) ;
V_11 = - V_17 ;
goto V_23;
}
V_2 -> V_28 = V_13 ;
F_14 ( V_2 -> V_26 , V_19 - V_20 + 1 ) ;
V_23:
return V_11 ;
}
int F_15 (
struct V_29 * V_30 ,
struct V_1 * V_2 ,
enum V_7 type ,
unsigned V_21 )
{
int V_11 = 0 ;
T_1 V_13 = V_3 [ type ] . V_13 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_30 = V_30 ;
V_2 -> type = type ;
V_2 -> V_21 = V_21 ;
V_2 -> V_31 = F_5 ( V_13 , V_15 ) ;
V_2 -> V_32 = V_3 [ type ] . V_32 ;
V_2 -> V_33 = V_34 ;
V_2 -> V_35 = V_3 [ type ] . V_35 ;
F_16 ( & V_2 -> V_36 , 0 ) ;
F_17 ( & V_2 -> V_37 ) ;
F_18 ( & V_2 -> V_38 ) ;
if ( V_3 [ type ] . V_32 & V_39 ) {
V_11 = F_10 ( V_2 ,
V_3 [ type ] . V_24 ,
V_3 [ type ] . V_25 ) ;
if ( V_11 )
goto V_23;
}
if ( V_3 [ type ] . V_32 & V_40 ) {
V_2 -> V_41 = V_3 [ type ] . V_41 ;
V_2 -> V_42 = V_3 [ type ] . V_42 ;
}
V_2 -> V_43 = V_44 ;
V_23:
return V_11 ;
}
static void F_19 ( struct V_45 * V_45 )
{
struct V_1 * V_2 = F_20 ( V_45 , struct V_1 , V_37 ) ;
V_2 -> V_43 = V_46 ;
F_21 ( V_2 -> V_26 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_37 , F_19 ) ;
}
int F_24 ( struct V_1 * V_2 )
{
unsigned long V_32 ;
F_25 ( & V_2 -> V_38 , V_32 ) ;
V_2 -> V_43 = V_46 ;
if ( F_26 ( & V_2 -> V_36 ) > 0 )
F_11 ( L_4 ,
F_1 ( V_2 ) ) ;
F_27 ( & V_2 -> V_38 , V_32 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static T_2 F_28 ( struct V_1 * V_2 )
{
T_2 V_47 ;
T_2 V_48 = V_2 -> V_24 - V_2 -> V_25 + 1 ;
V_47 = F_29 ( V_2 -> V_26 , V_48 , V_2 -> V_49 ) ;
if ( V_47 >= V_48 )
V_47 = F_30 ( V_2 -> V_26 , V_48 ) ;
F_31 ( V_47 , V_2 -> V_26 ) ;
V_2 -> V_49 = V_47 ;
return V_47 + V_2 -> V_25 ;
}
static void F_32 ( struct V_1 * V_2 , struct V_9 * V_50 )
{
struct V_51 * * V_52 = & V_2 -> V_33 . V_51 ;
struct V_51 * V_53 = NULL ;
struct V_9 * V_10 ;
while ( * V_52 ) {
V_53 = * V_52 ;
V_10 = F_33 ( V_53 , struct V_9 , V_54 ) ;
if ( V_10 -> V_47 == V_50 -> V_47 ) {
F_11 ( L_5 ) ;
goto V_23;
}
if ( V_10 -> V_47 > V_50 -> V_47 )
V_52 = & ( * V_52 ) -> V_55 ;
else
V_52 = & ( * V_52 ) -> V_56 ;
}
F_34 ( & V_50 -> V_54 , V_53 , V_52 ) ;
F_35 ( & V_50 -> V_54 , & V_2 -> V_33 ) ;
V_23:
return;
}
static void F_36 ( struct V_1 * V_2 , struct V_9 * V_50 )
{
struct V_51 * * V_52 = & V_2 -> V_33 . V_51 ;
struct V_51 * V_53 = NULL ;
struct V_9 * V_10 ;
int V_57 ;
while ( * V_52 ) {
V_53 = * V_52 ;
V_10 = F_33 ( V_53 , struct V_9 , V_54 ) ;
V_57 = memcmp ( ( V_58 * ) V_10 + V_2 -> V_41 ,
( V_58 * ) V_50 + V_2 -> V_41 , V_2 -> V_42 ) ;
if ( V_57 == 0 ) {
F_11 ( L_6 ) ;
goto V_23;
}
if ( V_57 > 0 )
V_52 = & ( * V_52 ) -> V_55 ;
else
V_52 = & ( * V_52 ) -> V_56 ;
}
F_34 ( & V_50 -> V_54 , V_53 , V_52 ) ;
F_35 ( & V_50 -> V_54 , & V_2 -> V_33 ) ;
V_23:
return;
}
void F_37 ( void * V_8 , void * V_59 )
{
struct V_9 * V_10 = V_8 ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_32 ;
F_25 ( & V_2 -> V_38 , V_32 ) ;
memcpy ( ( V_58 * ) V_10 + V_2 -> V_41 , V_59 , V_2 -> V_42 ) ;
F_36 ( V_2 , V_10 ) ;
F_27 ( & V_2 -> V_38 , V_32 ) ;
}
void F_38 ( void * V_8 )
{
struct V_9 * V_10 = V_8 ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_32 ;
F_25 ( & V_2 -> V_38 , V_32 ) ;
F_39 ( & V_10 -> V_54 , & V_2 -> V_33 ) ;
F_27 ( & V_2 -> V_38 , V_32 ) ;
}
void F_40 ( void * V_8 )
{
struct V_9 * V_10 = V_8 ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_32 ;
F_25 ( & V_2 -> V_38 , V_32 ) ;
V_10 -> V_47 = F_28 ( V_2 ) ;
F_32 ( V_2 , V_10 ) ;
F_27 ( & V_2 -> V_38 , V_32 ) ;
}
void F_41 ( void * V_8 )
{
struct V_9 * V_10 = V_8 ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_32 ;
F_25 ( & V_2 -> V_38 , V_32 ) ;
F_42 ( V_10 -> V_47 - V_2 -> V_25 , V_2 -> V_26 ) ;
F_39 ( & V_10 -> V_54 , & V_2 -> V_33 ) ;
F_27 ( & V_2 -> V_38 , V_32 ) ;
}
void * F_43 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
unsigned long V_32 ;
F_44 ( ! ( V_2 -> V_32 & V_60 ) ) ;
F_25 ( & V_2 -> V_38 , V_32 ) ;
if ( V_2 -> V_43 != V_44 ) {
F_27 ( & V_2 -> V_38 , V_32 ) ;
return NULL ;
}
F_45 ( & V_2 -> V_37 ) ;
F_27 ( & V_2 -> V_38 , V_32 ) ;
F_45 ( & V_2 -> V_30 -> V_37 ) ;
if ( F_46 ( & V_2 -> V_36 ) > V_2 -> V_21 ) {
F_47 ( & V_2 -> V_36 ) ;
F_48 ( V_2 -> V_30 ) ;
F_22 ( V_2 ) ;
return NULL ;
}
V_10 = F_49 ( F_2 ( V_2 ) ,
( V_2 -> V_32 & V_60 ) ?
V_61 : V_27 ) ;
V_10 -> V_2 = V_2 ;
F_17 ( & V_10 -> V_37 ) ;
return V_10 ;
}
void F_50 ( struct V_45 * V_45 )
{
struct V_9 * V_10 =
F_20 ( V_45 , struct V_9 , V_37 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_2 -> V_35 )
V_2 -> V_35 ( V_10 ) ;
F_51 ( F_2 ( V_2 ) , V_10 ) ;
F_47 ( & V_2 -> V_36 ) ;
F_48 ( V_2 -> V_30 ) ;
F_22 ( V_2 ) ;
}
void * F_52 ( struct V_1 * V_2 , T_2 V_47 )
{
struct V_51 * V_54 = NULL ;
struct V_9 * V_10 = NULL ;
unsigned long V_32 ;
F_25 ( & V_2 -> V_38 , V_32 ) ;
if ( V_2 -> V_43 != V_44 )
goto V_23;
V_54 = V_2 -> V_33 . V_51 ;
while ( V_54 ) {
V_10 = F_33 ( V_54 , struct V_9 , V_54 ) ;
if ( V_10 -> V_47 > V_47 )
V_54 = V_54 -> V_55 ;
else if ( V_10 -> V_47 < V_47 )
V_54 = V_54 -> V_56 ;
else
break;
}
if ( V_54 )
F_45 ( & V_10 -> V_37 ) ;
V_23:
F_27 ( & V_2 -> V_38 , V_32 ) ;
return V_54 ? ( void * ) V_10 : NULL ;
}
void * F_53 ( struct V_1 * V_2 , void * V_59 )
{
struct V_51 * V_54 = NULL ;
struct V_9 * V_10 = NULL ;
int V_57 ;
unsigned long V_32 ;
F_25 ( & V_2 -> V_38 , V_32 ) ;
if ( V_2 -> V_43 != V_44 )
goto V_23;
V_54 = V_2 -> V_33 . V_51 ;
while ( V_54 ) {
V_10 = F_33 ( V_54 , struct V_9 , V_54 ) ;
V_57 = memcmp ( ( V_58 * ) V_10 + V_2 -> V_41 ,
V_59 , V_2 -> V_42 ) ;
if ( V_57 > 0 )
V_54 = V_54 -> V_55 ;
else if ( V_57 < 0 )
V_54 = V_54 -> V_56 ;
else
break;
}
if ( V_54 )
F_45 ( & V_10 -> V_37 ) ;
V_23:
F_27 ( & V_2 -> V_38 , V_32 ) ;
return V_54 ? ( ( void * ) V_10 ) : NULL ;
}
