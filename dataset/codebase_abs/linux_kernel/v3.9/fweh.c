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
if ( V_16 -> V_23 && V_7 -> V_24 [ V_2 ] )
V_20 = V_7 -> V_24 [ V_2 ] ( V_16 , V_18 , V_19 ) ;
else
F_9 ( L_3 , V_2 ) ;
} else {
F_9 ( L_4 ) ;
}
return V_20 ;
}
static void F_10 ( struct V_25 * V_22 ,
struct V_17 * V_18 ,
void * V_19 )
{
struct V_26 * V_27 = V_19 ;
struct V_15 * V_16 ;
int V_20 = 0 ;
F_11 ( V_28 , L_5 ,
V_27 -> V_29 , V_27 -> V_30 ,
V_27 -> V_31 , V_27 -> V_10 ) ;
if ( V_27 -> V_30 >= V_32 ) {
F_9 ( L_6 ,
V_27 -> V_30 ) ;
return;
}
V_16 = V_22 -> V_33 [ V_27 -> V_31 ] ;
if ( V_27 -> V_29 == V_34 ) {
F_11 ( V_28 , L_7 , V_18 -> V_35 ,
V_18 -> V_36 ) ;
V_16 = F_12 ( V_22 , V_27 -> V_31 , V_27 -> V_30 ,
V_18 -> V_35 , V_18 -> V_36 ) ;
if ( F_13 ( V_16 ) )
return;
if ( ! V_22 -> V_7 . V_24 [ V_37 ] )
V_20 = F_14 ( V_16 , false ) ;
}
V_20 = F_8 ( V_16 , V_18 -> V_38 , V_18 , V_19 ) ;
if ( V_27 -> V_29 == V_39 )
F_15 ( V_22 , V_27 -> V_31 ) ;
}
static struct V_8 *
F_16 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = NULL ;
T_1 V_10 ;
F_4 ( & V_7 -> V_11 , V_10 ) ;
if ( ! F_17 ( & V_7 -> V_13 ) ) {
V_9 = F_18 ( & V_7 -> V_13 ,
struct V_8 , V_12 ) ;
F_19 ( & V_9 -> V_12 ) ;
}
F_6 ( & V_7 -> V_11 , V_10 ) ;
return V_9 ;
}
static void F_20 ( struct V_40 * V_41 )
{
struct V_25 * V_22 ;
struct V_15 * V_16 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_20 = 0 ;
struct V_42 * V_43 ;
struct V_17 V_18 ;
V_7 = F_21 ( V_41 , struct V_6 , V_14 ) ;
V_22 = F_21 ( V_7 , struct V_25 , V_7 ) ;
while ( ( V_9 = F_16 ( V_7 ) ) ) {
F_11 ( V_28 , L_8 ,
F_1 ( V_9 -> V_2 ) , V_9 -> V_2 ,
V_9 -> V_18 . V_30 , V_9 -> V_18 . V_44 ,
V_9 -> V_18 . V_36 ) ;
V_43 = & V_9 -> V_18 ;
V_18 . V_45 = F_22 ( V_43 -> V_45 ) ;
V_18 . V_10 = F_22 ( V_43 -> V_10 ) ;
V_18 . V_38 = V_9 -> V_2 ;
V_18 . V_46 = F_23 ( V_43 -> V_46 ) ;
V_18 . V_47 = F_23 ( V_43 -> V_47 ) ;
V_18 . V_48 = F_23 ( V_43 -> V_48 ) ;
V_18 . V_49 = F_23 ( V_43 -> V_49 ) ;
memcpy ( V_18 . V_36 , V_43 -> V_36 , V_50 ) ;
memcpy ( V_18 . V_35 , V_43 -> V_35 , sizeof( V_18 . V_35 ) ) ;
V_18 . V_30 = V_43 -> V_30 ;
V_18 . V_44 = V_43 -> V_44 ;
F_11 ( V_28 , L_9 ,
V_18 . V_45 , V_18 . V_10 , V_18 . V_46 , V_18 . V_47 ) ;
F_24 ( F_25 () , V_9 -> V_19 ,
F_26 ( V_51 , V_18 . V_49 , 64 ) ,
L_10 , V_18 . V_49 ) ;
if ( V_9 -> V_2 == V_37 ) {
F_10 ( V_22 , & V_18 , V_9 -> V_19 ) ;
goto V_52;
}
V_16 = V_22 -> V_33 [ V_18 . V_44 ] ;
V_20 = F_8 ( V_16 , V_9 -> V_2 , & V_18 ,
V_9 -> V_19 ) ;
if ( V_20 ) {
F_9 ( L_11 ,
V_9 -> V_2 ) ;
V_20 = 0 ;
}
V_52:
F_27 ( V_9 ) ;
}
}
void F_28 ( struct V_25 * V_22 )
{
struct V_6 * V_7 = & V_22 -> V_7 ;
F_29 ( & V_7 -> V_14 , F_20 ) ;
F_30 ( & V_7 -> V_11 ) ;
F_31 ( & V_7 -> V_13 ) ;
}
void F_32 ( struct V_25 * V_22 )
{
struct V_6 * V_7 = & V_22 -> V_7 ;
struct V_15 * V_16 = V_22 -> V_33 [ 0 ] ;
T_2 V_53 [ V_54 ] ;
if ( V_16 ) {
memset ( V_53 , 0 , V_54 ) ;
( void ) F_33 ( V_16 , L_12 ,
V_53 ,
V_54 ) ;
}
F_34 ( & V_7 -> V_14 ) ;
F_35 ( ! F_17 ( & V_7 -> V_13 ) ) ;
memset ( V_7 -> V_24 , 0 , sizeof( V_7 -> V_24 ) ) ;
}
int F_36 ( struct V_25 * V_22 , enum V_1 V_2 ,
T_3 V_55 )
{
if ( V_22 -> V_7 . V_24 [ V_2 ] ) {
F_9 ( L_13 , V_2 ) ;
return - V_56 ;
}
V_22 -> V_7 . V_24 [ V_2 ] = V_55 ;
F_11 ( V_57 , L_14 ,
F_1 ( V_2 ) ) ;
return 0 ;
}
void F_37 ( struct V_25 * V_22 ,
enum V_1 V_2 )
{
F_11 ( V_57 , L_15 ,
F_1 ( V_2 ) ) ;
V_22 -> V_7 . V_24 [ V_2 ] = NULL ;
}
int F_38 ( struct V_15 * V_16 )
{
int V_3 , V_20 ;
T_2 V_53 [ V_54 ] ;
for ( V_3 = 0 ; V_3 < V_58 ; V_3 ++ ) {
if ( V_16 -> V_22 -> V_7 . V_24 [ V_3 ] ) {
F_11 ( V_28 , L_16 ,
F_1 ( V_3 ) ) ;
F_39 ( V_53 , V_3 ) ;
}
}
F_11 ( V_28 , L_17 ) ;
F_39 ( V_53 , V_37 ) ;
V_20 = F_33 ( V_16 , L_12 ,
V_53 , V_54 ) ;
if ( V_20 )
F_9 ( L_18 , V_20 ) ;
return V_20 ;
}
void F_40 ( struct V_25 * V_22 ,
struct V_59 * V_60 , T_4 * V_30 )
{
enum V_1 V_2 ;
struct V_6 * V_7 = & V_22 -> V_7 ;
struct V_8 * V_9 ;
T_5 V_61 = V_62 ;
void * V_19 ;
V_51 V_49 ;
V_2 = F_41 ( & V_60 -> V_63 . V_64 ) ;
V_49 = F_41 ( & V_60 -> V_63 . V_49 ) ;
* V_30 = V_60 -> V_63 . V_30 ;
V_19 = & V_60 [ 1 ] ;
if ( V_2 >= V_58 )
return;
if ( V_2 != V_37 && ! V_7 -> V_24 [ V_2 ] )
return;
if ( F_42 () )
V_61 = V_65 ;
V_9 = F_43 ( sizeof( * V_9 ) + V_49 , V_61 ) ;
if ( ! V_9 )
return;
V_9 -> V_2 = V_2 ;
V_9 -> V_30 = * V_30 ;
memcpy ( & V_9 -> V_18 , & V_60 -> V_63 , sizeof( V_9 -> V_18 ) ) ;
memcpy ( V_9 -> V_19 , V_19 , V_49 ) ;
memcpy ( V_9 -> V_66 , V_60 -> V_67 . V_68 , V_50 ) ;
F_3 ( V_7 , V_9 ) ;
}
