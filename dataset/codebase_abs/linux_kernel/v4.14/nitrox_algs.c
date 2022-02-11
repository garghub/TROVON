static enum V_1 F_1 ( const char * V_2 )
{
const struct V_3 * V_4 = V_5 ;
while ( V_4 -> V_2 ) {
if ( ! strcmp ( V_4 -> V_2 , V_2 ) )
break;
V_4 ++ ;
}
return V_4 -> V_6 ;
}
static int F_2 ( int V_7 )
{
int V_8 ;
switch ( V_7 ) {
case V_9 :
V_8 = 1 ;
break;
case V_10 :
V_8 = 2 ;
break;
case V_11 :
V_8 = 3 ;
break;
default:
V_8 = - V_12 ;
break;
}
return V_8 ;
}
static int F_3 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
void * V_17 ;
V_16 -> V_18 = F_5 () ;
if ( ! V_16 -> V_18 )
return - V_19 ;
V_17 = F_6 ( V_16 -> V_18 ) ;
if ( ! V_17 ) {
F_7 ( V_16 -> V_18 ) ;
return - V_20 ;
}
V_16 -> V_21 . V_22 = ( V_23 ) V_17 ;
F_8 ( V_14 , F_9 ( V_14 ) +
sizeof( struct V_24 ) ) ;
return 0 ;
}
static void F_10 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
if ( V_16 -> V_21 . V_22 ) {
struct V_25 * V_17 = V_16 -> V_21 . V_17 ;
memset ( & V_17 -> V_26 , 0 , sizeof( struct V_27 ) ) ;
memset ( & V_17 -> V_28 , 0 , sizeof( struct V_29 ) ) ;
F_11 ( ( void * ) V_17 ) ;
}
F_7 ( V_16 -> V_18 ) ;
V_16 -> V_21 . V_22 = 0 ;
V_16 -> V_18 = NULL ;
}
static inline int F_12 ( struct V_13 * V_4 ,
int V_8 , const T_1 * V_30 ,
unsigned int V_7 )
{
struct V_31 * V_14 = F_13 ( V_4 ) ;
struct V_15 * V_16 = F_14 ( V_14 ) ;
struct V_25 * V_17 ;
enum V_1 V_32 ;
const char * V_2 ;
V_2 = F_15 ( V_14 ) ;
V_32 = F_1 ( V_2 ) ;
if ( F_16 ( V_32 == V_33 ) ) {
F_17 ( L_1 , V_2 ) ;
return - V_12 ;
}
V_17 = V_16 -> V_21 . V_17 ;
V_17 -> V_34 = 0 ;
V_17 -> V_35 . V_32 = V_32 ;
V_17 -> V_35 . V_8 = V_8 ;
V_17 -> V_35 . V_36 = V_37 ;
V_17 -> V_34 = F_18 ( * ( V_38 * ) & V_17 -> V_35 ) ;
memcpy ( V_17 -> V_26 . V_21 . V_30 , V_30 , V_7 ) ;
return 0 ;
}
static int F_19 ( struct V_13 * V_4 , const T_1 * V_30 ,
unsigned int V_7 )
{
int V_8 ;
V_8 = F_2 ( V_7 ) ;
if ( V_8 < 0 ) {
F_20 ( V_4 , V_39 ) ;
return - V_12 ;
}
return F_12 ( V_4 , V_8 , V_30 , V_7 ) ;
}
static void F_21 ( struct V_40 * V_41 ,
int V_42 )
{
if ( V_42 ) {
F_22 ( L_2 , V_42 ) ;
V_42 = - V_12 ;
}
F_23 ( V_41 , V_42 ) ;
}
static int F_24 ( struct V_40 * V_41 , bool V_43 )
{
struct V_13 * V_4 = F_25 ( V_41 ) ;
struct V_15 * V_16 = F_4 ( V_4 ) ;
struct V_24 * V_44 = F_26 ( V_41 ) ;
int V_45 = F_27 ( V_4 ) ;
struct V_46 * V_47 ;
V_47 = & V_44 -> V_47 ;
V_47 -> V_34 = V_41 -> V_48 . V_34 ;
V_47 -> V_49 = ( V_41 -> V_48 . V_34 & V_50 ) ?
V_51 : V_52 ;
V_47 -> V_53 . V_6 = 0 ;
V_47 -> V_54 = V_55 ;
V_47 -> V_53 . V_56 . V_57 = ( V_43 ? V_58 : V_59 ) ;
V_47 -> V_60 . V_61 = F_28 ( V_41 -> V_62 ) ;
V_47 -> V_60 . V_63 = 0 ;
V_47 -> V_60 . V_64 = F_28 ( V_45 ) ;
V_47 -> V_60 . V_65 = 0 ;
V_47 -> V_22 = V_16 -> V_21 . V_22 ;
V_47 -> V_53 . V_56 . V_66 = sizeof( struct V_25 ) ;
memcpy ( V_47 -> V_67 , V_41 -> V_67 , V_45 ) ;
V_47 -> V_45 = V_45 ;
V_47 -> V_68 = V_41 -> V_68 ;
V_47 -> V_69 = V_41 -> V_69 ;
V_44 -> V_16 = V_16 ;
V_44 -> V_41 = V_41 ;
return F_29 ( V_16 -> V_18 , V_47 ,
F_21 , V_41 ) ;
}
static int F_30 ( struct V_40 * V_41 )
{
return F_24 ( V_41 , true ) ;
}
static int F_31 ( struct V_40 * V_41 )
{
return F_24 ( V_41 , false ) ;
}
static int F_32 ( struct V_13 * V_4 ,
const T_1 * V_30 , unsigned int V_7 )
{
if ( V_7 != V_70 ) {
F_20 ( V_4 , V_39 ) ;
return - V_12 ;
}
return F_12 ( V_4 , 0 , V_30 , V_7 ) ;
}
static int F_33 ( struct V_40 * V_41 )
{
return F_24 ( V_41 , true ) ;
}
static int F_34 ( struct V_40 * V_41 )
{
return F_24 ( V_41 , false ) ;
}
static int F_35 ( struct V_13 * V_4 ,
const T_1 * V_30 , unsigned int V_7 )
{
struct V_31 * V_14 = F_13 ( V_4 ) ;
struct V_15 * V_16 = F_14 ( V_14 ) ;
struct V_25 * V_17 ;
int V_8 , V_71 ;
V_71 = F_36 ( V_14 , V_30 , V_7 ) ;
if ( V_71 )
return V_71 ;
V_7 /= 2 ;
V_8 = F_2 ( V_7 ) ;
if ( V_8 < 0 ) {
F_20 ( V_4 , V_39 ) ;
return - V_12 ;
}
V_17 = V_16 -> V_21 . V_17 ;
memcpy ( V_17 -> V_28 . V_21 . V_72 , ( V_30 + V_7 ) , V_7 ) ;
return F_12 ( V_4 , V_8 , V_30 , V_7 ) ;
}
static int F_37 ( struct V_13 * V_4 ,
const T_1 * V_30 , unsigned int V_7 )
{
struct V_31 * V_14 = F_13 ( V_4 ) ;
struct V_15 * V_16 = F_14 ( V_14 ) ;
struct V_25 * V_17 ;
int V_8 ;
if ( V_7 < V_73 )
return - V_12 ;
V_17 = V_16 -> V_21 . V_17 ;
memcpy ( V_17 -> V_26 . V_67 , V_30 + ( V_7 - V_73 ) ,
V_73 ) ;
V_7 -= V_73 ;
V_8 = F_2 ( V_7 ) ;
if ( V_8 < 0 ) {
F_20 ( V_4 , V_39 ) ;
return - V_12 ;
}
return F_12 ( V_4 , V_8 , V_30 , V_7 ) ;
}
int F_38 ( void )
{
return F_39 ( V_74 ,
F_40 ( V_74 ) ) ;
}
void F_41 ( void )
{
F_42 ( V_74 ,
F_40 ( V_74 ) ) ;
}
