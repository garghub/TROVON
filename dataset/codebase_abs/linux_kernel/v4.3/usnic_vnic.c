static enum V_1 F_1 ( enum V_2 V_3 )
{
#define F_2 ( T_1 , V_1 , T_2 , T_3 ) \
vnic_res_type,
#define F_3 ( T_1 , V_1 , T_2 ) \
vnic_res_type,
static enum V_1 V_4 [] = {
V_5 } ;
#undef F_3
#undef F_2
if ( V_3 >= V_6 )
return V_7 ;
return V_4 [ V_3 ] ;
}
const char * F_4 ( enum V_2 V_3 )
{
#define F_2 ( T_1 , V_1 , T_2 , T_3 ) \
desc,
#define F_3 ( T_1 , V_1 , T_2 ) \
desc,
static const char * const V_8 [] = {
V_5 } ;
#undef F_3
#undef F_2
if ( V_3 >= V_6 )
return L_1 ;
return V_8 [ V_3 ] ;
}
const char * F_5 ( struct V_9 * V_10 )
{
return F_6 ( F_7 ( V_10 ) ) ;
}
int F_8 ( struct V_9 * V_10 , char * V_11 ,
int V_12 ,
void * V_13 ,
int (* F_9)( void * , char * , int ) ,
int (* F_10)( char * , int ) ,
int (* F_11)( void * , char * , int ) )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
int V_20 , V_21 , V_22 ;
V_22 = 0 ;
V_19 = F_12 ( V_10 , 0 ) ;
V_22 += F_13 ( V_11 + V_22 , V_12 - V_22 ,
L_2 ,
F_14 ( V_10 ) ,
& V_19 -> V_23 ,
V_19 -> V_24 , V_19 -> V_25 ) ;
if ( F_9 )
V_22 += F_9 ( V_13 , V_11 + V_22 , V_12 - V_22 ) ;
V_22 += F_13 ( V_11 + V_22 , V_12 - V_22 , L_3 ) ;
V_22 += F_13 ( V_11 + V_22 , V_12 - V_22 ,
L_4 ) ;
if ( F_10 )
V_22 += F_10 ( V_11 + V_22 , V_12 - V_22 ) ;
V_22 += F_13 ( V_11 + V_22 , V_12 - V_22 , L_3 ) ;
F_15 ( & V_10 -> V_26 ) ;
for ( V_20 = 0 ; V_20 < F_16 ( V_10 -> V_27 ) ; V_20 ++ ) {
V_15 = & V_10 -> V_27 [ V_20 ] ;
for ( V_21 = 0 ; V_21 < V_15 -> V_28 ; V_21 ++ ) {
V_17 = V_15 -> V_17 [ V_21 ] ;
V_22 += F_13 ( V_11 + V_22 , V_12 - V_22 ,
L_5 ,
F_4 ( V_17 -> type ) ,
V_17 -> V_29 , V_17 -> V_30 , ! ! V_17 -> V_31 ) ;
if ( F_11 ) {
V_22 += F_11 ( V_17 -> V_31 , V_11 + V_22 ,
V_12 - V_22 ) ;
}
V_22 += F_13 ( V_11 + V_22 , V_12 - V_22 ,
L_3 ) ;
}
}
F_17 ( & V_10 -> V_26 ) ;
return V_22 ;
}
void F_18 ( struct V_32 * V_33 ,
enum V_2 V_34 ,
T_4 V_28 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_6 ; V_20 ++ ) {
if ( V_33 -> V_35 [ V_20 ] . type == V_34 ) {
V_33 -> V_35 [ V_20 ] . V_28 = V_28 ;
return;
}
}
F_19 ( 1 ) ;
}
int F_20 ( const struct V_32 * V_36 ,
struct V_32 * V_37 )
{
int V_38 , V_20 , V_21 ;
for ( V_20 = 0 ; V_20 < V_6 ; V_20 ++ ) {
V_38 = 0 ;
for ( V_21 = 0 ; V_21 < V_6 ; V_21 ++ ) {
if ( V_37 -> V_35 [ V_20 ] . type !=
V_36 -> V_35 [ V_20 ] . type )
continue;
V_38 = 1 ;
if ( V_36 -> V_35 [ V_20 ] . V_28 >
V_37 -> V_35 [ V_20 ] . V_28 )
return - V_39 ;
break;
}
if ( ! V_38 )
return - V_39 ;
}
return 0 ;
}
int F_21 ( char * V_11 , int V_12 ,
struct V_32 * V_37 )
{
enum V_2 V_3 ;
int V_40 ;
int V_20 ;
int V_22 = 0 ;
for ( V_20 = 0 ; V_20 < V_6 ; V_20 ++ ) {
V_3 = V_37 -> V_35 [ V_20 ] . type ;
V_40 = V_37 -> V_35 [ V_20 ] . V_28 ;
V_22 += F_13 ( V_11 + V_22 , V_12 - V_22 ,
L_6 ,
F_4 ( V_3 ) ,
V_40 ) ;
}
return V_22 ;
}
int F_22 ( struct V_9 * V_10 ,
struct V_32 * V_37 )
{
int V_20 ;
enum V_2 V_3 ;
int V_40 ;
for ( V_20 = 0 ; V_20 < V_6 ; V_20 ++ ) {
V_3 = V_37 -> V_35 [ V_20 ] . type ;
V_40 = V_37 -> V_35 [ V_20 ] . V_28 ;
if ( V_3 == V_41 )
break;
if ( V_40 > F_23 ( V_10 , V_3 ) )
return - V_42 ;
}
return 0 ;
}
int F_24 ( struct V_9 * V_10 ,
enum V_2 type )
{
return V_10 -> V_27 [ type ] . V_28 ;
}
int F_23 ( struct V_9 * V_10 ,
enum V_2 type )
{
return V_10 -> V_27 [ type ] . V_43 ;
}
struct V_14 *
F_25 ( struct V_9 * V_10 , enum V_2 type ,
int V_28 , void * V_31 )
{
struct V_14 * V_44 , * V_45 ;
struct V_16 * V_17 ;
int V_20 ;
if ( F_23 ( V_10 , type ) < V_28 || V_28 < 1 || ! V_31 )
return F_26 ( - V_39 ) ;
V_45 = F_27 ( sizeof( * V_45 ) , V_46 ) ;
if ( ! V_45 ) {
F_28 ( L_7 ,
F_5 ( V_10 ) ) ;
return F_26 ( - V_47 ) ;
}
V_45 -> V_17 = F_27 ( sizeof( * ( V_45 -> V_17 ) ) * V_28 , V_46 ) ;
if ( ! V_45 -> V_17 ) {
F_28 ( L_8 ,
F_5 ( V_10 ) ) ;
F_29 ( V_45 ) ;
return F_26 ( - V_47 ) ;
}
F_15 ( & V_10 -> V_26 ) ;
V_44 = & V_10 -> V_27 [ type ] ;
for ( V_20 = 0 ; V_20 < V_44 -> V_28 && V_45 -> V_28 < V_28 ; V_20 ++ ) {
V_17 = V_44 -> V_17 [ V_20 ] ;
if ( ! V_17 -> V_31 ) {
V_44 -> V_43 -- ;
V_17 -> V_31 = V_31 ;
V_45 -> V_17 [ V_45 -> V_28 ++ ] = V_17 ;
}
}
F_17 ( & V_10 -> V_26 ) ;
V_45 -> type = type ;
V_45 -> V_10 = V_10 ;
F_19 ( V_45 -> V_28 != V_28 ) ;
return V_45 ;
}
void F_30 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
int V_20 ;
struct V_9 * V_10 = V_15 -> V_10 ;
F_15 ( & V_10 -> V_26 ) ;
while ( ( V_20 = -- V_15 -> V_28 ) >= 0 ) {
V_17 = V_15 -> V_17 [ V_20 ] ;
V_15 -> V_17 [ V_20 ] = NULL ;
V_17 -> V_31 = NULL ;
V_10 -> V_27 [ V_17 -> type ] . V_43 ++ ;
}
F_17 ( & V_10 -> V_26 ) ;
F_29 ( V_15 -> V_17 ) ;
F_29 ( V_15 ) ;
}
T_4 F_14 ( struct V_9 * V_10 )
{
return F_7 ( V_10 ) -> V_48 - 1 ;
}
static int F_31 ( struct V_9 * V_10 ,
enum V_2 type ,
struct V_14 * V_15 )
{
int V_28 , V_49 , V_20 ;
struct V_16 * V_17 ;
V_28 = F_32 ( V_10 -> V_50 , F_1 ( type ) ) ;
if ( V_28 < 1 )
return - V_39 ;
V_15 -> V_28 = V_15 -> V_43 = V_28 ;
V_15 -> V_17 = F_27 ( sizeof( * ( V_15 -> V_17 ) ) * V_28 , V_51 ) ;
if ( ! V_15 -> V_17 )
return - V_47 ;
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ ) {
V_17 = F_27 ( sizeof( * V_17 ) , V_51 ) ;
if ( ! V_17 ) {
V_49 = - V_47 ;
goto V_52;
}
V_17 -> type = type ;
V_17 -> V_29 = V_20 ;
V_17 -> V_10 = V_10 ;
V_17 -> V_30 = F_33 ( V_10 -> V_50 ,
F_1 ( type ) , V_20 ) ;
V_15 -> V_17 [ V_20 ] = V_17 ;
}
V_15 -> V_10 = V_10 ;
return 0 ;
V_52:
for ( V_20 -- ; V_20 >= 0 ; V_20 -- )
F_29 ( V_15 -> V_17 [ V_20 ] ) ;
F_29 ( V_15 -> V_17 ) ;
return V_49 ;
}
static void F_34 ( struct V_14 * V_15 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_15 -> V_28 ; V_20 ++ )
F_29 ( V_15 -> V_17 [ V_20 ] ) ;
F_29 ( V_15 -> V_17 ) ;
}
static int F_35 ( struct V_53 * V_54 ,
struct V_9 * V_10 )
{
enum V_2 V_3 ;
int V_20 ;
int V_49 = 0 ;
for ( V_20 = 0 ; V_20 < F_16 ( V_10 -> V_55 ) ; V_20 ++ ) {
if ( ! ( F_36 ( V_54 , V_20 ) & V_56 ) )
continue;
V_10 -> V_55 [ V_20 ] . V_25 = F_37 ( V_54 , V_20 ) ;
V_10 -> V_55 [ V_20 ] . V_24 = F_38 ( V_54 , V_20 , V_10 -> V_55 [ V_20 ] . V_25 ) ;
if ( ! V_10 -> V_55 [ V_20 ] . V_24 ) {
F_28 ( L_9 ,
V_20 ) ;
V_49 = - V_57 ;
goto V_58;
}
V_10 -> V_55 [ V_20 ] . V_23 = F_39 ( V_54 , V_20 ) ;
}
V_10 -> V_50 = F_40 ( NULL , V_54 , V_54 , V_10 -> V_55 ,
F_16 ( V_10 -> V_55 ) ) ;
if ( ! V_10 -> V_50 ) {
F_28 ( L_10 ,
F_6 ( V_54 ) ) ;
V_49 = - V_39 ;
goto V_58;
}
for ( V_3 = V_41 + 1 ;
V_3 < V_6 ; V_3 ++ ) {
V_49 = F_31 ( V_10 , V_3 ,
& V_10 -> V_27 [ V_3 ] ) ;
if ( V_49 ) {
F_28 ( L_11 ,
F_4 ( V_3 ) ,
V_49 ) ;
goto V_59;
}
}
return 0 ;
V_59:
for ( V_3 -- ; V_3 > V_41 ; V_3 -- )
F_34 ( & V_10 -> V_27 [ V_3 ] ) ;
F_41 ( V_10 -> V_50 ) ;
V_58:
for ( V_20 = 0 ; V_20 < F_16 ( V_10 -> V_55 ) ; V_20 ++ ) {
if ( ! ( F_36 ( V_54 , V_20 ) & V_56 ) )
continue;
if ( ! V_10 -> V_55 [ V_20 ] . V_24 )
break;
F_42 ( V_10 -> V_55 [ V_20 ] . V_24 ) ;
}
return V_49 ;
}
struct V_53 * F_7 ( struct V_9 * V_10 )
{
return F_43 ( V_10 -> V_50 ) ;
}
struct V_18 * F_12 ( struct V_9 * V_10 ,
int V_60 )
{
return ( V_60 < F_16 ( V_10 -> V_55 ) ) ? & V_10 -> V_55 [ V_60 ] : NULL ;
}
static void F_44 ( struct V_9 * V_10 )
{
int V_20 ;
struct V_53 * V_54 ;
enum V_2 V_3 ;
V_54 = F_7 ( V_10 ) ;
for ( V_3 = V_41 + 1 ;
V_3 < V_6 ; V_3 ++ )
F_34 ( & V_10 -> V_27 [ V_3 ] ) ;
F_41 ( V_10 -> V_50 ) ;
for ( V_20 = 0 ; V_20 < F_16 ( V_10 -> V_55 ) ; V_20 ++ ) {
if ( ! ( F_36 ( V_54 , V_20 ) & V_56 ) )
continue;
F_42 ( V_10 -> V_55 [ V_20 ] . V_24 ) ;
}
}
struct V_9 * F_45 ( struct V_53 * V_54 )
{
struct V_9 * V_10 ;
int V_49 = 0 ;
if ( ! F_46 ( V_54 ) ) {
F_28 ( L_12 , F_6 ( V_54 ) ) ;
return F_26 ( - V_39 ) ;
}
V_10 = F_27 ( sizeof( * V_10 ) , V_51 ) ;
if ( ! V_10 ) {
F_28 ( L_13 ,
F_6 ( V_54 ) ) ;
return F_26 ( - V_47 ) ;
}
F_47 ( & V_10 -> V_26 ) ;
V_49 = F_35 ( V_54 , V_10 ) ;
if ( V_49 ) {
F_28 ( L_14 ,
F_6 ( V_54 ) , V_49 ) ;
goto V_61;
}
F_48 ( L_15 , F_5 ( V_10 ) ) ;
return V_10 ;
V_61:
F_29 ( V_10 ) ;
return F_26 ( V_49 ) ;
}
void F_49 ( struct V_9 * V_10 )
{
F_44 ( V_10 ) ;
F_29 ( V_10 ) ;
}
