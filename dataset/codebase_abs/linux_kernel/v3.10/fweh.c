static const char * F_1 ( enum V_1 V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_2 == V_2 )
return V_4 [ V_3 ] . V_5 ;
}
return L_1 ;
}
static const char * F_1 ( enum V_1 V_2 )
{
return L_2 ;
}
static void F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
T_1 V_10 ;
F_4 ( & V_7 -> V_11 , V_10 ) ;
F_5 ( & V_9 -> V_12 , & V_7 -> V_13 ) ;
F_6 ( & V_7 -> V_11 , V_10 ) ;
F_7 ( & V_7 -> V_14 ) ;
}
static int F_8 ( struct V_15 * V_16 ,
enum V_1 V_2 ,
struct V_17 * V_18 ,
void * V_19 )
{
struct V_6 * V_7 ;
int V_20 = - V_21 ;
if ( V_16 ) {
V_7 = & V_16 -> V_22 -> V_7 ;
if ( V_7 -> V_23 [ V_2 ] )
V_20 = V_7 -> V_23 [ V_2 ] ( V_16 , V_18 , V_19 ) ;
else
F_9 ( L_3 , V_2 ) ;
} else {
F_9 ( L_4 ) ;
}
return V_20 ;
}
static void F_10 ( struct V_24 * V_22 ,
struct V_17 * V_18 ,
void * V_19 )
{
struct V_25 * V_26 = V_19 ;
struct V_15 * V_16 ;
int V_20 = 0 ;
F_11 ( V_27 , L_5 ,
V_26 -> V_28 , V_26 -> V_29 , V_26 -> V_30 ,
V_26 -> V_10 , V_26 -> V_31 ) ;
if ( V_26 -> V_29 >= V_32 ) {
F_9 ( L_6 ,
V_26 -> V_29 ) ;
return;
}
V_16 = V_22 -> V_33 [ V_26 -> V_30 ] ;
if ( V_26 -> V_28 == V_34 ) {
F_11 ( V_27 , L_7 , V_18 -> V_35 ,
V_18 -> V_36 ) ;
V_16 = F_12 ( V_22 , V_26 -> V_30 , V_26 -> V_29 ,
V_18 -> V_35 , V_18 -> V_36 ) ;
if ( F_13 ( V_16 ) )
return;
F_14 ( V_16 ) ;
if ( ! V_22 -> V_7 . V_23 [ V_37 ] )
if ( F_15 ( V_16 , false ) < 0 )
return;
}
if ( V_26 -> V_28 == V_38 )
F_16 ( V_16 ) ;
V_20 = F_8 ( V_16 , V_18 -> V_39 , V_18 , V_19 ) ;
if ( V_26 -> V_28 == V_40 ) {
F_17 ( V_16 ) ;
F_18 ( V_22 , V_26 -> V_30 ) ;
}
}
static struct V_8 *
F_19 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = NULL ;
T_1 V_10 ;
F_4 ( & V_7 -> V_11 , V_10 ) ;
if ( ! F_20 ( & V_7 -> V_13 ) ) {
V_9 = F_21 ( & V_7 -> V_13 ,
struct V_8 , V_12 ) ;
F_22 ( & V_9 -> V_12 ) ;
}
F_6 ( & V_7 -> V_11 , V_10 ) ;
return V_9 ;
}
static void F_23 ( struct V_41 * V_42 )
{
struct V_24 * V_22 ;
struct V_15 * V_16 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_20 = 0 ;
struct V_43 * V_44 ;
struct V_17 V_18 ;
V_7 = F_24 ( V_42 , struct V_6 , V_14 ) ;
V_22 = F_24 ( V_7 , struct V_24 , V_7 ) ;
while ( ( V_9 = F_19 ( V_7 ) ) ) {
F_11 ( V_27 , L_8 ,
F_1 ( V_9 -> V_2 ) , V_9 -> V_2 ,
V_9 -> V_18 . V_29 , V_9 -> V_18 . V_45 ,
V_9 -> V_18 . V_36 ) ;
V_44 = & V_9 -> V_18 ;
V_18 . V_46 = F_25 ( V_44 -> V_46 ) ;
V_18 . V_10 = F_25 ( V_44 -> V_10 ) ;
V_18 . V_39 = V_9 -> V_2 ;
V_18 . V_47 = F_26 ( V_44 -> V_47 ) ;
V_18 . V_48 = F_26 ( V_44 -> V_48 ) ;
V_18 . V_49 = F_26 ( V_44 -> V_49 ) ;
V_18 . V_50 = F_26 ( V_44 -> V_50 ) ;
memcpy ( V_18 . V_36 , V_44 -> V_36 , V_51 ) ;
memcpy ( V_18 . V_35 , V_44 -> V_35 , sizeof( V_18 . V_35 ) ) ;
V_18 . V_29 = V_44 -> V_29 ;
V_18 . V_45 = V_44 -> V_45 ;
F_11 ( V_27 , L_9 ,
V_18 . V_46 , V_18 . V_10 , V_18 . V_47 , V_18 . V_48 ) ;
F_27 ( F_28 () , V_9 -> V_19 ,
F_29 ( V_52 , V_18 . V_50 , 64 ) ,
L_10 , V_18 . V_50 ) ;
if ( V_9 -> V_2 == V_37 ) {
F_10 ( V_22 , & V_18 , V_9 -> V_19 ) ;
goto V_53;
}
V_16 = V_22 -> V_33 [ V_18 . V_45 ] ;
V_20 = F_8 ( V_16 , V_9 -> V_2 , & V_18 ,
V_9 -> V_19 ) ;
if ( V_20 ) {
F_9 ( L_11 ,
V_9 -> V_2 ) ;
V_20 = 0 ;
}
V_53:
F_30 ( V_9 ) ;
}
}
void F_31 ( struct V_24 * V_22 )
{
struct V_6 * V_7 = & V_22 -> V_7 ;
F_32 ( & V_7 -> V_14 , F_23 ) ;
F_33 ( & V_7 -> V_11 ) ;
F_34 ( & V_7 -> V_13 ) ;
}
void F_35 ( struct V_24 * V_22 )
{
struct V_6 * V_7 = & V_22 -> V_7 ;
struct V_15 * V_16 = V_22 -> V_33 [ 0 ] ;
T_2 V_54 [ V_55 ] ;
if ( V_16 ) {
memset ( V_54 , 0 , V_55 ) ;
( void ) F_36 ( V_16 , L_12 ,
V_54 ,
V_55 ) ;
}
F_37 ( & V_7 -> V_14 ) ;
F_38 ( ! F_20 ( & V_7 -> V_13 ) ) ;
memset ( V_7 -> V_23 , 0 , sizeof( V_7 -> V_23 ) ) ;
}
int F_39 ( struct V_24 * V_22 , enum V_1 V_2 ,
T_3 V_56 )
{
if ( V_22 -> V_7 . V_23 [ V_2 ] ) {
F_9 ( L_13 , V_2 ) ;
return - V_57 ;
}
V_22 -> V_7 . V_23 [ V_2 ] = V_56 ;
F_11 ( V_58 , L_14 ,
F_1 ( V_2 ) ) ;
return 0 ;
}
void F_40 ( struct V_24 * V_22 ,
enum V_1 V_2 )
{
F_11 ( V_58 , L_15 ,
F_1 ( V_2 ) ) ;
V_22 -> V_7 . V_23 [ V_2 ] = NULL ;
}
int F_41 ( struct V_15 * V_16 )
{
int V_3 , V_20 ;
T_2 V_54 [ V_55 ] ;
for ( V_3 = 0 ; V_3 < V_59 ; V_3 ++ ) {
if ( V_16 -> V_22 -> V_7 . V_23 [ V_3 ] ) {
F_11 ( V_27 , L_16 ,
F_1 ( V_3 ) ) ;
F_42 ( V_54 , V_3 ) ;
}
}
F_11 ( V_27 , L_17 ) ;
F_42 ( V_54 , V_37 ) ;
V_20 = F_36 ( V_16 , L_12 ,
V_54 , V_55 ) ;
if ( V_20 )
F_9 ( L_18 , V_20 ) ;
return V_20 ;
}
void F_43 ( struct V_24 * V_22 ,
struct V_60 * V_61 )
{
enum V_1 V_2 ;
struct V_6 * V_7 = & V_22 -> V_7 ;
struct V_8 * V_9 ;
T_4 V_62 = V_63 ;
void * V_19 ;
V_52 V_50 ;
V_2 = F_44 ( & V_61 -> V_64 . V_65 ) ;
V_50 = F_44 ( & V_61 -> V_64 . V_50 ) ;
V_19 = & V_61 [ 1 ] ;
if ( V_2 >= V_59 )
return;
if ( V_2 != V_37 && ! V_7 -> V_23 [ V_2 ] )
return;
if ( F_45 () )
V_62 = V_66 ;
V_9 = F_46 ( sizeof( * V_9 ) + V_50 , V_62 ) ;
if ( ! V_9 )
return;
V_9 -> V_2 = V_2 ;
V_9 -> V_29 = V_61 -> V_64 . V_29 ;
memcpy ( & V_9 -> V_18 , & V_61 -> V_64 , sizeof( V_9 -> V_18 ) ) ;
memcpy ( V_9 -> V_19 , V_19 , V_50 ) ;
memcpy ( V_9 -> V_67 , V_61 -> V_68 . V_69 , V_51 ) ;
F_3 ( V_7 , V_9 ) ;
}
