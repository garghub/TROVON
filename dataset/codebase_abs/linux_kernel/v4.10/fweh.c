const char * F_1 ( enum V_1 V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_2 == V_2 )
return V_4 [ V_3 ] . V_5 ;
}
return L_1 ;
}
const char * F_1 ( enum V_1 V_2 )
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
bool V_27 ;
int V_20 = 0 ;
F_11 ( V_28 , L_5 ,
V_26 -> V_29 , V_26 -> V_30 , V_26 -> V_31 ,
V_26 -> V_10 , V_26 -> V_32 ) ;
V_27 = ( ( V_26 -> V_10 & V_33 ) &&
( V_26 -> V_32 == V_34 ||
( ( V_26 -> V_32 == V_35 ) &&
( V_22 -> V_7 . V_36 ) ) ) ) ;
if ( ! V_27 && ( V_26 -> V_10 & V_33 ) ) {
F_11 ( V_28 , L_6 ) ;
return;
}
if ( V_26 -> V_30 >= V_37 ) {
F_9 ( L_7 , V_26 -> V_30 ) ;
return;
}
V_16 = V_22 -> V_38 [ V_26 -> V_31 ] ;
if ( V_26 -> V_29 == V_39 ) {
F_11 ( V_28 , L_8 , V_18 -> V_40 ,
V_18 -> V_41 ) ;
V_16 = F_12 ( V_22 , V_26 -> V_31 , V_26 -> V_30 ,
V_27 , V_18 -> V_40 , V_18 -> V_41 ) ;
if ( F_13 ( V_16 ) )
return;
if ( ! V_27 )
F_14 ( V_16 ) ;
if ( ! V_22 -> V_7 . V_23 [ V_42 ] )
if ( F_15 ( V_16 , false ) < 0 )
return;
}
if ( V_16 && V_26 -> V_29 == V_43 )
F_16 ( V_16 ) ;
V_20 = F_8 ( V_16 , V_18 -> V_44 , V_18 , V_19 ) ;
if ( V_16 && V_26 -> V_29 == V_45 ) {
bool V_46 = F_17 ( V_22 -> V_47 ) ;
if ( ! V_46 )
F_18 ( V_16 , false ) ;
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
static void F_23 ( struct V_48 * V_49 )
{
struct V_24 * V_22 ;
struct V_15 * V_16 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_20 = 0 ;
struct V_50 * V_51 ;
struct V_17 V_18 ;
V_7 = F_24 ( V_49 , struct V_6 , V_14 ) ;
V_22 = F_24 ( V_7 , struct V_24 , V_7 ) ;
while ( ( V_9 = F_19 ( V_7 ) ) ) {
F_11 ( V_28 , L_9 ,
F_1 ( V_9 -> V_2 ) , V_9 -> V_2 ,
V_9 -> V_18 . V_30 , V_9 -> V_18 . V_31 ,
V_9 -> V_18 . V_41 ) ;
V_51 = & V_9 -> V_18 ;
V_18 . V_52 = F_25 ( V_51 -> V_52 ) ;
V_18 . V_10 = F_25 ( V_51 -> V_10 ) ;
V_18 . V_44 = V_9 -> V_2 ;
V_18 . V_53 = F_26 ( V_51 -> V_53 ) ;
V_18 . V_54 = F_26 ( V_51 -> V_54 ) ;
V_18 . V_55 = F_26 ( V_51 -> V_55 ) ;
V_18 . V_56 = F_26 ( V_51 -> V_56 ) ;
memcpy ( V_18 . V_41 , V_51 -> V_41 , V_57 ) ;
memcpy ( V_18 . V_40 , V_51 -> V_40 , sizeof( V_18 . V_40 ) ) ;
V_18 . V_30 = V_51 -> V_30 ;
V_18 . V_31 = V_51 -> V_31 ;
F_11 ( V_28 , L_10 ,
V_18 . V_52 , V_18 . V_10 , V_18 . V_53 , V_18 . V_54 ) ;
F_27 ( F_28 () , V_9 -> V_19 ,
F_29 ( V_58 , V_18 . V_56 , 64 ) ,
L_11 , V_18 . V_56 ) ;
if ( V_18 . V_56 > V_9 -> V_56 ) {
F_9 ( L_12 ,
V_9 -> V_56 , V_18 . V_56 ) ;
goto V_59;
}
if ( V_9 -> V_2 == V_42 ) {
F_10 ( V_22 , & V_18 , V_9 -> V_19 ) ;
goto V_59;
}
if ( V_9 -> V_2 == V_60 )
V_16 = V_22 -> V_38 [ 0 ] ;
else
V_16 = V_22 -> V_38 [ V_18 . V_31 ] ;
V_20 = F_8 ( V_16 , V_9 -> V_2 , & V_18 ,
V_9 -> V_19 ) ;
if ( V_20 ) {
F_9 ( L_13 ,
V_9 -> V_2 ) ;
V_20 = 0 ;
}
V_59:
F_30 ( V_9 ) ;
}
}
void F_31 ( struct V_15 * V_16 , bool V_61 )
{
V_16 -> V_22 -> V_7 . V_36 = V_61 ;
}
void F_32 ( struct V_24 * V_22 )
{
struct V_6 * V_7 = & V_22 -> V_7 ;
F_33 ( & V_7 -> V_14 , F_23 ) ;
F_34 ( & V_7 -> V_11 ) ;
F_35 ( & V_7 -> V_13 ) ;
}
void F_36 ( struct V_24 * V_22 )
{
struct V_6 * V_7 = & V_22 -> V_7 ;
struct V_15 * V_16 = F_37 ( V_22 , 0 ) ;
T_2 V_62 [ V_63 ] ;
if ( V_16 ) {
memset ( V_62 , 0 , V_63 ) ;
( void ) F_38 ( V_16 , L_14 ,
V_62 ,
V_63 ) ;
}
F_39 ( & V_7 -> V_14 ) ;
F_40 ( ! F_20 ( & V_7 -> V_13 ) ) ;
memset ( V_7 -> V_23 , 0 , sizeof( V_7 -> V_23 ) ) ;
}
int F_41 ( struct V_24 * V_22 , enum V_1 V_2 ,
T_3 V_64 )
{
if ( V_22 -> V_7 . V_23 [ V_2 ] ) {
F_9 ( L_15 , V_2 ) ;
return - V_65 ;
}
V_22 -> V_7 . V_23 [ V_2 ] = V_64 ;
F_11 ( V_66 , L_16 ,
F_1 ( V_2 ) ) ;
return 0 ;
}
void F_42 ( struct V_24 * V_22 ,
enum V_1 V_2 )
{
F_11 ( V_66 , L_17 ,
F_1 ( V_2 ) ) ;
V_22 -> V_7 . V_23 [ V_2 ] = NULL ;
}
int F_43 ( struct V_15 * V_16 )
{
int V_3 , V_20 ;
T_2 V_62 [ V_63 ] ;
memset ( V_62 , 0 , sizeof( V_62 ) ) ;
for ( V_3 = 0 ; V_3 < V_67 ; V_3 ++ ) {
if ( V_16 -> V_22 -> V_7 . V_23 [ V_3 ] ) {
F_11 ( V_28 , L_18 ,
F_1 ( V_3 ) ) ;
F_44 ( V_62 , V_3 ) ;
}
}
F_11 ( V_28 , L_19 ) ;
F_44 ( V_62 , V_42 ) ;
V_20 = F_38 ( V_16 , L_14 ,
V_62 , V_63 ) ;
if ( V_20 )
F_9 ( L_20 , V_20 ) ;
return V_20 ;
}
void F_45 ( struct V_24 * V_22 ,
struct V_68 * V_69 ,
V_58 V_70 )
{
enum V_1 V_2 ;
struct V_6 * V_7 = & V_22 -> V_7 ;
struct V_8 * V_9 ;
T_4 V_71 = V_72 ;
void * V_19 ;
V_58 V_56 ;
V_2 = F_46 ( & V_69 -> V_73 . V_74 ) ;
V_56 = F_46 ( & V_69 -> V_73 . V_56 ) ;
V_19 = & V_69 [ 1 ] ;
if ( V_2 >= V_67 )
return;
if ( V_2 != V_42 && ! V_7 -> V_23 [ V_2 ] )
return;
if ( V_56 > V_75 )
return;
if ( F_47 () )
V_71 = V_76 ;
V_9 = F_48 ( sizeof( * V_9 ) + V_56 , V_71 ) ;
if ( ! V_9 )
return;
V_9 -> V_2 = V_2 ;
V_9 -> V_30 = V_69 -> V_73 . V_30 ;
memcpy ( & V_9 -> V_18 , & V_69 -> V_73 , sizeof( V_9 -> V_18 ) ) ;
memcpy ( V_9 -> V_19 , V_19 , V_56 ) ;
V_9 -> V_56 = V_56 ;
memcpy ( V_9 -> V_77 , V_69 -> V_78 . V_79 , V_57 ) ;
F_3 ( V_7 , V_9 ) ;
}
