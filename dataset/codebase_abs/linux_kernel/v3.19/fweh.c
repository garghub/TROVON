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
if ( ! ( V_26 -> V_29 == 0 && V_26 -> V_30 == 1 ) &&
( V_26 -> V_10 & V_32 ) ) {
F_11 ( V_27 , L_6 ) ;
return;
}
if ( V_26 -> V_29 >= V_33 ) {
F_9 ( L_7 ,
V_26 -> V_29 ) ;
return;
}
V_16 = V_22 -> V_34 [ V_26 -> V_30 ] ;
if ( V_26 -> V_28 == V_35 ) {
F_11 ( V_27 , L_8 , V_18 -> V_36 ,
V_18 -> V_37 ) ;
V_16 = F_12 ( V_22 , V_26 -> V_30 , V_26 -> V_29 ,
V_18 -> V_36 , V_18 -> V_37 ) ;
if ( F_13 ( V_16 ) )
return;
F_14 ( V_16 ) ;
if ( ! V_22 -> V_7 . V_23 [ V_38 ] )
if ( F_15 ( V_16 , false ) < 0 )
return;
}
if ( V_16 && V_26 -> V_28 == V_39 )
F_16 ( V_16 ) ;
V_20 = F_8 ( V_16 , V_18 -> V_40 , V_18 , V_19 ) ;
if ( V_16 && V_26 -> V_28 == V_41 )
F_17 ( V_22 , V_26 -> V_30 ) ;
}
static struct V_8 *
F_18 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = NULL ;
T_1 V_10 ;
F_4 ( & V_7 -> V_11 , V_10 ) ;
if ( ! F_19 ( & V_7 -> V_13 ) ) {
V_9 = F_20 ( & V_7 -> V_13 ,
struct V_8 , V_12 ) ;
F_21 ( & V_9 -> V_12 ) ;
}
F_6 ( & V_7 -> V_11 , V_10 ) ;
return V_9 ;
}
static void F_22 ( struct V_42 * V_43 )
{
struct V_24 * V_22 ;
struct V_15 * V_16 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_20 = 0 ;
struct V_44 * V_45 ;
struct V_17 V_18 ;
V_7 = F_23 ( V_43 , struct V_6 , V_14 ) ;
V_22 = F_23 ( V_7 , struct V_24 , V_7 ) ;
while ( ( V_9 = F_18 ( V_7 ) ) ) {
F_11 ( V_27 , L_9 ,
F_1 ( V_9 -> V_2 ) , V_9 -> V_2 ,
V_9 -> V_18 . V_29 , V_9 -> V_18 . V_46 ,
V_9 -> V_18 . V_37 ) ;
V_45 = & V_9 -> V_18 ;
V_18 . V_47 = F_24 ( V_45 -> V_47 ) ;
V_18 . V_10 = F_24 ( V_45 -> V_10 ) ;
V_18 . V_40 = V_9 -> V_2 ;
V_18 . V_48 = F_25 ( V_45 -> V_48 ) ;
V_18 . V_49 = F_25 ( V_45 -> V_49 ) ;
V_18 . V_50 = F_25 ( V_45 -> V_50 ) ;
V_18 . V_51 = F_25 ( V_45 -> V_51 ) ;
memcpy ( V_18 . V_37 , V_45 -> V_37 , V_52 ) ;
memcpy ( V_18 . V_36 , V_45 -> V_36 , sizeof( V_18 . V_36 ) ) ;
V_18 . V_29 = V_45 -> V_29 ;
V_18 . V_46 = V_45 -> V_46 ;
F_11 ( V_27 , L_10 ,
V_18 . V_47 , V_18 . V_10 , V_18 . V_48 , V_18 . V_49 ) ;
F_26 ( F_27 () , V_9 -> V_19 ,
F_28 ( V_53 , V_18 . V_51 , 64 ) ,
L_11 , V_18 . V_51 ) ;
if ( V_9 -> V_2 == V_38 ) {
F_10 ( V_22 , & V_18 , V_9 -> V_19 ) ;
goto V_54;
}
if ( ( V_9 -> V_2 == V_55 ) &&
( V_18 . V_46 == 1 ) )
V_16 = V_22 -> V_34 [ 0 ] ;
else
V_16 = V_22 -> V_34 [ V_18 . V_46 ] ;
V_20 = F_8 ( V_16 , V_9 -> V_2 , & V_18 ,
V_9 -> V_19 ) ;
if ( V_20 ) {
F_9 ( L_12 ,
V_9 -> V_2 ) ;
V_20 = 0 ;
}
V_54:
F_29 ( V_9 ) ;
}
}
void F_30 ( struct V_24 * V_22 )
{
struct V_6 * V_7 = & V_22 -> V_7 ;
F_31 ( & V_7 -> V_14 , F_22 ) ;
F_32 ( & V_7 -> V_11 ) ;
F_33 ( & V_7 -> V_13 ) ;
}
void F_34 ( struct V_24 * V_22 )
{
struct V_6 * V_7 = & V_22 -> V_7 ;
struct V_15 * V_16 = V_22 -> V_34 [ 0 ] ;
T_2 V_56 [ V_57 ] ;
if ( V_16 ) {
memset ( V_56 , 0 , V_57 ) ;
( void ) F_35 ( V_16 , L_13 ,
V_56 ,
V_57 ) ;
}
F_36 ( & V_7 -> V_14 ) ;
F_37 ( ! F_19 ( & V_7 -> V_13 ) ) ;
memset ( V_7 -> V_23 , 0 , sizeof( V_7 -> V_23 ) ) ;
}
int F_38 ( struct V_24 * V_22 , enum V_1 V_2 ,
T_3 V_58 )
{
if ( V_22 -> V_7 . V_23 [ V_2 ] ) {
F_9 ( L_14 , V_2 ) ;
return - V_59 ;
}
V_22 -> V_7 . V_23 [ V_2 ] = V_58 ;
F_11 ( V_60 , L_15 ,
F_1 ( V_2 ) ) ;
return 0 ;
}
void F_39 ( struct V_24 * V_22 ,
enum V_1 V_2 )
{
F_11 ( V_60 , L_16 ,
F_1 ( V_2 ) ) ;
V_22 -> V_7 . V_23 [ V_2 ] = NULL ;
}
int F_40 ( struct V_15 * V_16 )
{
int V_3 , V_20 ;
T_2 V_56 [ V_57 ] ;
for ( V_3 = 0 ; V_3 < V_61 ; V_3 ++ ) {
if ( V_16 -> V_22 -> V_7 . V_23 [ V_3 ] ) {
F_11 ( V_27 , L_17 ,
F_1 ( V_3 ) ) ;
F_41 ( V_56 , V_3 ) ;
}
}
F_11 ( V_27 , L_18 ) ;
F_41 ( V_56 , V_38 ) ;
V_20 = F_35 ( V_16 , L_13 ,
V_56 , V_57 ) ;
if ( V_20 )
F_9 ( L_19 , V_20 ) ;
return V_20 ;
}
void F_42 ( struct V_24 * V_22 ,
struct V_62 * V_63 )
{
enum V_1 V_2 ;
struct V_6 * V_7 = & V_22 -> V_7 ;
struct V_8 * V_9 ;
T_4 V_64 = V_65 ;
void * V_19 ;
V_53 V_51 ;
V_2 = F_43 ( & V_63 -> V_66 . V_67 ) ;
V_51 = F_43 ( & V_63 -> V_66 . V_51 ) ;
V_19 = & V_63 [ 1 ] ;
if ( V_2 >= V_61 )
return;
if ( V_2 != V_38 && ! V_7 -> V_23 [ V_2 ] )
return;
if ( F_44 () )
V_64 = V_68 ;
V_9 = F_45 ( sizeof( * V_9 ) + V_51 , V_64 ) ;
if ( ! V_9 )
return;
V_9 -> V_2 = V_2 ;
V_9 -> V_29 = V_63 -> V_66 . V_29 ;
memcpy ( & V_9 -> V_18 , & V_63 -> V_66 , sizeof( V_9 -> V_18 ) ) ;
memcpy ( V_9 -> V_19 , V_19 , V_51 ) ;
memcpy ( V_9 -> V_69 , V_63 -> V_70 . V_71 , V_52 ) ;
F_3 ( V_7 , V_9 ) ;
}
